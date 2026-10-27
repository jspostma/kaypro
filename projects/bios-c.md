# C BIOS

Status: **active** (per vault). Detail lives in `kaypro_stuff` under `projects/bios-c-rewrite/`.

Rewrite the Kaypro BIOS in C with **z88dk**:
- `zcc +cpm -subtype=kaypro` for .COM programs.
- `+z80` with a custom memory map for ROM/BIOS.

Files in `kaypro_stuff`: `kaypro.h` (ports, bit masks, FDC/SIO/PIT/CRTC registers, control
latch, scratch RAM; AVR-style `_BV()`/`port_set()` helpers), `kaypro-h-reference.md`,
`z80-c-toolchains.md`.

## Decisions
- Toolchain: z88dk, confirmed working on hardware.
- **C:** SELDSK/SETTRK/SETSEC/SETDMA, SECTRAN, read/write control flow, the video escape
  state machine, keyboard and SIO init.
- **Inline asm:** the FDC `HALT`+`INI`/`OUTI` loop, cold-start entry, shadow registers.
- **Linked asm module with explicit ORG:** the relocated sector routine (0xFDE5 in the 292 ROM).

Needed by the [Pico board](pico-board.md) RAM disk driver.
