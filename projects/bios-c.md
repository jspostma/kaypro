# C BIOS

Status: **active**. Files: [`kaypro.h`](bios-c/kaypro.h), [`kaypro-h-reference.md`](bios-c/kaypro-h-reference.md), [`z80-c-toolchains.md`](bios-c/z80-c-toolchains.md).

> **Warning:** the SIO/baud-generator port assignments in `kaypro.h` contradict the ROM's own code and a period document. See [machine § I/O map](../hardware/machine.md#io-map-disputed). Audit before touching hardware directly. The `VRAM_BASE 0xF000` memory-mapped model and `VRAM_ROWS 24` should be checked too: on the '84 board VRAM most likely sits behind the 6545 (transparent addressing via R18/R19 and the port 0x1F strobe) rather than in Z80 memory, and the ROM programs the CRTC for 25 displayed rows.

Rewrite the Kaypro BIOS in C with **z88dk**:
- `zcc +cpm -subtype=kaypro` for .COM programs.
- `+z80` with a custom memory map for ROM/BIOS.

Contents: `kaypro.h` (ports, bit masks, FDC/SIO/PIT/CRTC registers, control
latch, scratch RAM; AVR-style `_BV()`/`port_set()` helpers), `kaypro-h-reference.md`,
`z80-c-toolchains.md`.

## Decisions
- Toolchain: z88dk, confirmed working on hardware.
- **C:** SELDSK/SETTRK/SETSEC/SETDMA, SECTRAN, read/write control flow, the video escape
  state machine, keyboard and SIO init.
- **Inline asm:** the FDC `HALT`+`INI`/`OUTI` loop, cold-start entry, shadow registers.
- **Linked asm module with explicit ORG:** the relocated sector routine (0xFDE5 in the 292 ROM).

Needed by the [Pico board](pico-board.md) RAM disk driver.
