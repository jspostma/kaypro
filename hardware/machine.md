# The machine

Kaypro 4, '84 series ("4/84"). Z80 at 4 MHz, CP/M 2.2.
The Kaypro 10 uses the same mainboard ("universal" '84 board), so K10 documentation and
measurements apply unless noted.

## Core

| Item | Detail | Source |
|---|---|---|
| CPU | Z80, 4 MHz (T-state = 250 ns) | |
| ROM | 81-292-A (the K2X / K2/84 / K4/84 ROM; CP/M 2.2G/H) | vault `kaypro-4` |
| U29 (81-194) | Custom ASIC: clock division, DRAM address mux, ROM/RAM bank select. **Refreshes DRAM itself; Z80 /RFSH is unused**, so long /BUSRQ holds are safe. | `kaypro_stuff` notes |
| U10 | Custom ASIC: video timing | `kaypro_stuff` notes |
| CRTC | 6545 variant (SY6545 confirmed on a K10) | Kaypro10Video |
| Char ROM | 2732 EPROM (U26 on the K10) | Kaypro10Video |
| VRAM | Two 6116 (2K×8): character and attribute | interposer design |
| Interrupts | IM2, with SIO/PIO vectors (Z80 peripheral daisy chain) | |

I/O map, DPB and scratch RAM layout live in `kaypro_stuff`:
`projects/bios-c-rewrite/kaypro.h` and its reference doc. Not duplicated here.

C code built with z88dk has run on this machine (hello world → disk image → hardware).

## Buses and headers

### 50-pin hard disk header ("SASI-like")
- Carries most of the main bus plus interrupt. Anything here is an I/O-mapped peripheral.
- **No BUSREQ/BUSACK.** That's why bus-mastering work needs the CPU-socket interposer.
- To pin down from the schematic: which I/O ports are routed there, which address lines
  (probably A0–A7 only), whether /M1 and the IEI/IEO daisy chain are present (needed to
  supply an IM2 vector), whether /WAIT is present, and which buffers sit between Z80 and
  header (and whether the data buffer direction follows /RD).
- I/O timing is relaxed: the Z80 adds an automatic wait state to every I/O cycle, leaving
  a few hundred ns from /IORQ+/RD to data sampling at the falling edge of T3.

> Conflict to resolve: one past discussion described the 4/84 as having "no expansion
> bus". The 50-pin header effectively is one for I/O devices. See [open questions](../open-questions.md).

### Keyboard
- Detachable keyboard on a modular coiled cable. Believed to be a self-contained MCU
  sending **ASCII bytes over async serial** (≈300 baud?), not make/break scancodes.
  The host also sends to the keyboard (bell/click). **Unverified; scope it.**

### Power harness
- Mainboard power connector: **AMP 87025-7** (MATE-N-LOK, 7-position).
- Mating plug housing: **AMP 1-480702-0**. Pins: **AMP 350078-4** (18–22 AWG) or
  **350689-4** (14–18 AWG). Standard MATE-N-LOK crimp tool.

### Other
- Parallel printer port: 8-bit latched output with strobe. Usable for streaming data out
  (see [NPU coprocessor](../projects/npu-coprocessor.md)).
- Serial port (SIO).
- Internal modem? Assumed in the [agent](../projects/agent.md) design. **Confirm whether this unit has one.**

## Electrical rules for anything attached

- **NMOS Z80 outputs only guarantee ≈2.4 V high.** 74HC inputs want ≈3.15 V at 4.5 V
  supply. Transceivers on the CPU side of any interposer must be **74HCT** (or LS/ACT),
  not HC. Logic sims won't catch this; check against datasheets.
- 5 V → 3.3 V (Pico side): 74LVCH245 with 100 Ω series resistors works (Kaypro10Video).
- Bring-up of anything touching the bus: current-limited bench supply, series Schottky
  or polyfuse on the input, ZIF sockets for irreplaceable parts.

## Unresolved

- Edge connector part number for the video board (asked once, never found).
