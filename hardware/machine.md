# The machine

Kaypro 4, '84 series ("4/84"). Z80 at 4 MHz, CP/M 2.2, ROM 81-292-A.
The Kaypro 10 shares the '84 "universal" mainboard (Jaapie), so K10 measurements usually
apply. Exception: the 1983 K10 ROM v7A source predates that board; see [video](video.md).

Deeper references in this repo:
- [ROM reference](rom-reference.md): 81-xxx ROM version matrix and every ROM file in the archive
- [ROM explainer](rom-explainer/index.html): annotated walkthrough of 81-292-A (open in a browser)
- [`kaypro.h`](../projects/bios-c/kaypro.h) + [reference](../projects/bios-c/kaypro-h-reference.md): register definitions. **Port map disputed, see below.**

## Core

| Item | Detail |
|---|---|
| CPU | Z80, 4 MHz (T-state = 250 ns) |
| ROM | 81-292-A (the K2X / K2/84 / K4/84 ROM; CP/M 2.2G/H) |
| U29 (81-194) | Custom ASIC, CPU section: clock division (16 MHz → 4 MHz CPU, 2 MHz, 1 MHz, 4800 Hz baud), DRAM address mux plus RAS/CAS for the 4864s, ROM/RAM bank select (pin 22 ROM enable, pin 21 RAM enable, from BANK + A15). **Refreshes DRAM itself; Z80 /RFSH unused**, so long /BUSRQ holds are safe. |
| U10 | Custom ASIC, video section: dot-clock division, character clock, CRTC clock, attribute generation, CPU↔video transfer sync |
| CRTC | 6545 variant (SY6545 confirmed on a K10). Ports 0x1C (address), 0x1D (data), 0x1F (status / update strobe). |
| Char ROM | 2732 on the K10 (U26). `81-146a.bin` (2 KB, 2716-sized) in the archive is a char-ROM or keyboard-firmware candidate. |
| VRAM | Two 6116 (2K×8): character and attribute |
| FDC | WD179x, ports 0x10–0x13; control latch at 0x14 (drive select, side, motor, density, ROM bank) |
| Interrupts | IM2, SIO/PIO vectors (Z80 peripheral daisy chain) |
| Terminal | ADM-3A-compatible escape codes plus Kaypro extensions (attributes ESC G/H, reverse ESC j/k, graphics ESC p); a Greek character set is reachable by escape |

## I/O map: disputed

Two notes in this repo disagree with each other, and the strongest evidence contradicts both tables.

| Source | SIO A (keyboard) | SIO B (serial/modem) | Baud gen |
|---|---|---|---|
| `kaypro.h` | data 0x00, ctrl 0x01 | data 0x02, ctrl 0x03 | 8253 at 0x04–0x07 |
| ROM explainer's port table | data 0x00, ctrl 0x02 | data 0x01, ctrl 0x03 | 8253 at 0x04–0x07 |
| **ROM explainer's own disassembly** of `kbdstat`/`kbdin` | `IN A,(7)` status, `IN A,(5)` data | | |
| **`kaypro.doc`** (period ADM-3A/ports doc, in archive) | data 5, status 7 | data 4, status 6 | |

The two independent primary sources (the ROM's code and the period document) agree:
**SIO at 0x04–0x07** (B data 4, A data 5, B ctrl 6, A ctrl 7). The baud setting stored by
the BIOS uses codes like `05h` = 300 baud (KP-CBOOT), which matches a COM8116-style
baud-generator code table, not an 8253 divisor. So "8253 PIT at 0x04–0x07" is likely
wrong too. `kaypro.doc` also lists parallel at 8/9 and system status at 0x1D, which may be
the '83 layout (on the '84 board 0x1D is the CRTC).

**Action:** audit every port in `kaypro.h` against the 292 ROM disassembly and the
schematic before running any C BIOS code that touches hardware directly. See
[open questions](../open-questions.md).

## Keyboard
- **8048 MCU** in the keyboard scans the matrix and sends **serial bytes** to SIO
  channel A. 76 keys, 4-wire cable (`kaypro_keyboard.txt` in archive).
- Alphanumerics arrive **as ASCII**; function, cursor and keypad keys arrive as raw codes
  (0xF1…) that the ROM translates via a table at 0x183 (routine `translate` at 0x16E).
- Baud rate is set by the baud generator; exact rate unconfirmed (believed low, ~300).
- The archive has a **keyboard USB conversion project** (`web/` in `kaypro/`:
  `kaypro_technical.md`, `usb_conversion_notes.md`, interface schematic) that documents
  the protocol. Read it before designing the [agent keyboard mux](../projects/agent.md#keyboard-mux).

## Serial and modem
- SIO channel B: rear RS-232 port and the **internal modem**. Jaapie's old `todo` lists
  "replace internal modem with ESP8266", so this unit has one.
- BIOS default for modem baud (`EA47h` in K10 CP/M 2.2F) is `05h` = **300 baud**.
- Parallel printer port: 8-bit latched output with strobe.

## 50-pin hard disk header ("SASI-like")
- Carries most of the main bus plus interrupt. Anything here is an I/O-mapped peripheral.
  The K10 puts its hard disk controller at 0x40–0x5F.
- **No BUSREQ/BUSACK**, which is why bus mastering needs the CPU-socket interposer.
- To pin down from the schematic: routed ports, address lines (probably A0–A7), /M1 and
  IEI/IEO (for an IM2 vector), /WAIT, buffer parts and direction control.
- I/O timing is relaxed: the automatic I/O wait state leaves a few hundred ns from
  /IORQ+/RD to data sampling at T3.

## Power harness
- Mainboard power connector: **AMP 87025-7** (MATE-N-LOK, 7-position).
- Mating plug housing **AMP 1-480702-0**; pins **AMP 350078-4** (18–22 AWG) or
  **350689-4** (14–18 AWG). Standard MATE-N-LOK crimp tool.
- Old `todo` idea: replace the PSU with ATX.

## Electrical rules for anything attached
- **NMOS Z80 outputs only guarantee ≈2.4 V high.** 74HC inputs want ≈3.15 V at 4.5 V.
  Use **74HCT** (or LS/ACT) on the CPU side of any interposer. Logic sims won't catch this.
- 5 V → 3.3 V (Pico side): 74LVCH245 plus 100 Ω series resistors works (Kaypro10Video).
- Bring-up: current-limited bench supply, series Schottky or polyfuse, ZIF sockets for irreplaceable parts.

## Other ideas from the old `todo`
Compact Flash instead of the floppy controller (Arduino FDD emulator, or ROM mod), RAM
disk (now [Pico board](../projects/pico-board.md)), 8048 → Arduino keyboard with PS/2/USB/Bluetooth.

## Unresolved
- Edge connector part number for the video board (asked once, never found).
