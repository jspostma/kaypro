# Kaypro Pico Board — Design Notes

A combined hardware project: a single daughter board that plugs into the Kaypro 4's Z80 CPU socket, with the Z80 re-seated on top. An RP2040 (Raspberry Pi Pico) on the board has full access to the Z80 bus and implements three cooperating subsystems:

1. **Boot manager** — bank-switched ROM selection
2. **RAM disk** — battery-backed SRAM presented as a CP/M drive
3. **System monitor** — memory inspection, breakpoints, execution tracing over USB

---

## Physical Form Factor

- 40-pin DIP daughter board, fits the Kaypro 4 Z80 socket
- Z80 in a 40-pin socket on top of the board
- RPi Pico (or bare RP2040) on the board with USB accessible from outside the case
- Additional socket for the flash chip (boot manager)
- SRAM + battery holder (RAM disk)
- A few buttons (ROM selection / monitor trigger)
- Optional: small status LED

The board intercepts every Z80 bus signal. All lines that the board doesn't need to modify are passed straight through to the mainboard socket below.

---

## Z80 Bus Signals Available

From the CPU socket (all signals relative to Z80 pin names):

| Signal | Dir | Use |
|--------|-----|-----|
| A0–A15 | Z80→board | Address bus — monitor for ROM/RAM disk ranges |
| D0–D7 | bidirectional | Data bus — drive for RAM disk reads, inject for monitor |
| /MREQ | Z80→board | Memory request — qualifies address bus |
| /IORQ | Z80→board | I/O request |
| /RD | Z80→board | Read cycle |
| /WR | Z80→board | Write cycle |
| /M1 | Z80→board | Opcode fetch — used for breakpoints and execution tracing |
| /WAIT | board→Z80 | Insert wait states — eliminates flash/SRAM timing constraints |
| /BUSRQ | board→Z80 | Request bus — Pico takes over to inspect/modify memory |
| /BUSACK | Z80→board | Z80 has released bus — Pico can now drive A/D lines |
| /RESET | bidirectional | Pico can assert reset (bank switch, monitor restart) |
| /INT | board→Z80 | Could be used for monitor interrupts |
| CLK | Z80→board | 4 MHz system clock — Pico can monitor for cycle counting |

---

## Subsystem 1: Boot Manager

### Concept
A larger parallel flash chip in a separate socket (on the daughter board or in the original EPROM socket via a ribbon) stores multiple 8 KB ROM images. The Pico controls the upper address lines of the flash, selecting which bank the Z80 sees.

### Flash chip options
- **27C512** (64 KB) — 8 × 8 KB slots, same 28-pin DIP footprint as 2764, drop-in compatible
- **SST39SF040** (512 KB) — 64 × 8 KB slots, 32-pin, needs adapter; in-circuit reprogrammable over SPI

### How it works
1. At power-on, Pico sets bank select lines to the last-used (or default) ROM slot
2. Pico releases /RESET, Z80 boots from selected ROM
3. To show a boot menu: slot 0 contains a custom Z80 menu ROM (see below)
4. Pico monitors the bus for a "slot select" signal from the menu ROM (a write to a specific I/O port or unused memory address)
5. On receiving the signal, Pico changes bank select lines and pulses /RESET

### Wait state handling
When a bank switch is in progress (or for slow flash chips), Pico asserts /WAIT during ROM reads (/MREQ + /RD + address in ROM range) until the flash output is stable. Eliminates all timing constraints — any flash chip works regardless of access time.

### ROM slots (proposed)
| Slot | Image | Notes |
|------|-------|-------|
| 0 | Menu ROM | Custom Z80 firmware — displays selection menu |
| 1 | `81-478c.rom` | Stock Kaypro ROM v2.03 |
| 2 | `kplus84.rom` | KayPLUS v1.2a |
| 3 | `kplus83.rom` | KayPLUS-83 v0.1c |
| 4 | `884max.rom` | Micro Cornucopia PRO-884 |
| 5 | `pro884mx.rom` | Super MAX v2.7 |
| 6 | `turbo.bin` | TurboROM v3.4 |
| 7 | (spare / custom) | |

All images are already present in the archive.

### Menu ROM
A small Z80 program that:
- Displays available ROM names on the Kaypro screen using the existing video routines
- Reads keystrokes via the existing keyboard handler
- On selection, writes the slot number to a specific I/O port that the Pico monitors
- Pico switches bank and pulses /RESET

Could also allow the Pico to be reprogrammed over USB while the Kaypro is running — new ROM images uploaded via serial without opening the machine.

---

## Subsystem 2: RAM Disk

### Concept
Battery-backed SRAM on the daughter board, presented to CP/M as one or more logical disk drives. The Pico watches the address bus and, when the Z80 accesses the RAM disk address range, takes over the data bus (asserting /WAIT first if needed).

### Address space
The Z80 has a 64 KB address space, all of which the Kaypro uses as RAM. The RAM disk cannot live in the normal address space without displacing something. Options:

- **I/O-mapped**: use /IORQ instead of /MREQ. The Kaypro has a sparse I/O map; the RAM disk could appear as a set of I/O ports (address register + data register). The BIOS driver writes an address, then reads/writes data a byte at a time. Slow but simple.
- **Bank-switched window**: the Pico maps a 4–16 KB window of SRAM into the Z80 address space (typically upper RAM), controlled by a latch. The BIOS sets the latch to select which SRAM bank is visible, then accesses the window directly. Fast, but steals address space from CP/M.
- **DMA-style via /BUSRQ**: Pico requests the bus, transfers a full 128-byte CP/M sector directly, releases bus. The Z80 waits (blocked in /WAIT or polling a flag) during the transfer. Clean separation between Z80 and Pico address spaces.

### SRAM sizing
- 512 KB SRAM chip (e.g., AS6C4008) gives 4 × 128 KB CP/M drives or 2 × 256 KB
- Battery backup (CR2032 + diode) keeps contents across power cycles
- At CP/M sector size of 128 bytes, 512 KB = 4,096 sectors — plenty for a working drive

### BIOS driver
The CP/M BIOS needs routines for the RAM disk drive: SELDSK, HOME, SETTRK, SETSEC, SETDMA, READ, WRITE. These translate CP/M disk operations into the appropriate I/O or memory window accesses.

References in archive:
- `bios.mac` — full BIOS source, template for adding a new drive
- `k10rom7a/FLPYIO.MAC` and `HDIO7A.MAC` — examples of how floppy and hard disk drivers are structured
- `MRDISK.DOC` + `RAMCON.COM` — Micro Sphere RAM disk, shows what the BIOS integration looks like from the outside

---

## Subsystem 3: System Monitor

### Concept
The Pico presents a USB serial console (appears as a CDC device on the connected PC). Commands sent over USB let you inspect and manipulate the running Kaypro without interrupting normal operation — or pause it entirely for debugging.

### Passive monitoring (bus snooping)
While the Z80 runs normally, the Pico logs bus activity:
- Every /M1 fetch = opcode fetch at that address → execution trace / disassembly
- /MREQ + /RD / /WR = memory reads and writes → memory access log
- /IORQ = I/O operations → peripheral access log

The Pico's PIO state machines handle this at line speed without involving the ARM cores for each cycle. Data is buffered and streamed to the USB console.

### Active control
- **Breakpoint**: Pico watches for a specific address on /M1. When seen, asserts /WAIT — Z80 freezes. Console shows address, Pico can then inspect memory.
- **Single-step**: release /WAIT for exactly one cycle at a time.
- **Bus takeover**: assert /BUSRQ, wait for /BUSACK, then Pico drives the address and data buses directly. Can read or write any memory location. Release /BUSRQ when done — Z80 resumes as if nothing happened.
- **Register inspection**: Pico injects a small routine into RAM (via bus takeover), sets PC to it via a reset vector patch, routine pushes all registers to a known address, Pico reads that memory. Requires care to restore state afterwards.
- **Reset**: Pico pulses /RESET to restart the machine (also used by boot manager for ROM switching).

### USB console commands (proposed)
```
r              — read all registers (via injected routine)
m <addr> <len> — hex dump memory
w <addr> <hex> — write bytes to memory
b <addr>       — set breakpoint at address
s              — single step (from breakpoint)
c              — continue (release breakpoint)
t              — toggle execution trace
i <port>       — read I/O port
o <port> <val> — write I/O port
reset          — pulse /RESET
rom <slot>     — switch ROM slot and reset
```

### Relationship to ROM source
The ROM source in the archive (`k10rom7a/`, `kaypro_292_rom.s`) documents exact addresses for BIOS routines, jump tables, and memory-mapped variables. This makes breakpoints meaningful — you can break on `CONIN`, `SELDSK`, the cold boot entry point, etc. by name rather than by hunting for addresses.

---

## RP2040 / Pico Suitability

- 26 GPIO pins (Pico) — enough for A0–A15 (16), D0–D7 (8), and control signals with careful multiplexing or using a Pico 2 (30 GPIO)
- PIO state machines: handle time-critical bus watching without ARM core latency
- USB CDC: free serial console without extra hardware
- 2 MB onboard flash: enough to store all ROM images directly on the Pico, with the external flash chip only needed if you want in-circuit reprogramming from the Kaypro side
- 3.3V logic: need level shifting for the Z80's 5V signals (simple 74HCT245 buffers or a dedicated level shifter)

### GPIO allocation (approximate, Pico 2)
| GPIO | Signal |
|------|--------|
| 0–7 | D0–D7 (bidirectional via buffer) |
| 8–15 | A0–A7 (input) |
| 16–23 | A8–A15 (input) |
| 24 | /MREQ (input) |
| 25 | /IORQ (input) |
| 26 | /RD (input) |
| 27 | /WR (input) |
| 28 | /M1 (input) |
| 29 | /WAIT (output, open-drain) |
| + | /BUSRQ, /BUSACK, /RESET via spare pins or small expander |

Level shifting: 74HCT245 octal bus transceiver for data bus (bidirectional, 5V tolerant inputs, 3.3V drive through series resistors or proper shifter). Address and control lines: 74HCT244 buffers (input only, 5V→3.3V).

---

## Related Files in the Archive

| File | Relevance |
|------|-----------|
| `kaypro/software/roms/boot/` | All ROM images ready to flash |
| `kaypro/virtual-kaypro/81-478c.rom` | Stock ROM |
| `kaypro/software/source/bios.mac` | BIOS source — RAM disk driver template |
| `kaypro/software/source/k10rom7a/` | Full ROM source — jump table addresses for breakpoints |
| `kaypro_related/kaypro4/source/kaypro_292_rom.s` | 292 variant ROM source |
| `kaypro/schematics/KayproSchematic.pdf` | Mainboard schematic — CPU socket pinout, address decoding |
| `kaypro/datasheets/MK3880.pdf` | Z80 CPU datasheet — timing diagrams |
| `kaypro_related/KRAMDISK.TZT` | RAM disk documentation (needs decoding) |
| `kaypro/software/pro884mx/MRDISK.DOC` | Micro Sphere RAM disk — BIOS integration reference |
| `kaypro/datasheets/FD179X-02_Data_Sheet_May1980.pdf` | FDC datasheet — useful for understanding how the existing disk driver works |

---

## Hardware Notes — Custom ASICs

The Kaypro 4 mainboard has two custom LSI gate array ASICs (Kaypro 81-xxx part numbers):

- **U29 (81-194)** — CPU section. Does three things: clock division (16 MHz → 4 MHz CPU, 2 MHz, 1 MHz, 4800 Hz baud), DRAM address multiplexing (MUX signal + RAS/CAS generation for the 4864 DRAM chips), and ROM/RAM bank select (pin 22 = ROM enable, pin 21 = RAM enable, controlled by BANK signal + A15).
- **U10** — Video section. Dot clock division, character clock, video controller clock, attribute generation, CPU-video data transfer synchronisation.

### Critical: DRAM refresh is U29's job, not the Z80's

The Z80 generates a /RFSH signal during M1 cycles for DRAM refresh, but **U29 does not use it** — the Theory of Operation explicitly states "RFSH from the Z80-A is not used in RAS generation. Dynamic RAM is refreshed whenever it is not being accessed."

U29 handles refresh autonomously. This means:
- Holding the bus with /BUSRQ for extended periods is safe from a refresh standpoint — U29 keeps refreshing regardless of what the Z80 is doing
- You do not need to worry about DRAM decay during bus takeover operations (monitor, RAM disk DMA transfers)
- However, U29 is also generating the bank select signals — when designing the daughter board, be aware that /WAIT and /BUSRQ assertions happen upstream of U29's bank decode logic

---

## Open Questions

- Exact CPU socket pinout on the Kaypro 4 mainboard — confirm from schematic
- Whether /WAIT is already used by any existing Kaypro hardware (FDC, CRT?) — check schematic before driving it
- Level shifting strategy — 74HCT vs dedicated shifter ICs vs resistor dividers
- Whether a Pico (26 GPIO) is sufficient or Pico 2 (30 GPIO) is needed
- RAM disk addressing strategy — I/O mapped vs bank-switched window vs DMA
- Menu ROM design — what video/keyboard routines are safe to call from a cold-start ROM context
