# C BIOS

Status: **active**. Files: [`kaypro.h`](bios-c/kaypro.h), [`kaypro-h-reference.md`](bios-c/kaypro-h-reference.md), [`z80-c-toolchains.md`](bios-c/z80-c-toolchains.md).

> **`kaypro.h` is wrong for this board; don't use its port constants as-is.** The schematic
> ([I/O map](../hardware/io-map.md)) shows:
> - Keyboard is SIO1 ch B at **0x05/0x07**; RS-232 is SIO1 ch A at **0x04/0x06** (the header has 0x00–0x03).
> - There is no 8253: baud rates go to a **COM8116** at **0x00** (fA) and **0x08** (fB) as 4-bit codes.
> - A second SIO exists: printer 0x0C/0x0E, modem 0x0D/0x0F. PIO at 0x20–0x23, RTC at 0x24.
> - VRAM isn't memory-mapped (`VRAM_BASE 0xF000` is the '83 model). The CPU reaches it
>   through the 6545 and U10. The ROM programs 25 displayed rows, not 24.
>
> FDC (0x10–0x13), system port (0x14), parallel (0x18) and CRTC (0x1C–0x1F) match.

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
