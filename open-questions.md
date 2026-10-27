# Open questions and things to measure

Ordered roughly by how much they unblock. When one is resolved, put the answer in the
relevant page and delete it here.

## Fix
1. **Correct [`kaypro.h`](projects/bios-c/kaypro.h) and its reference** to the schematic
   [I/O map](hardware/io-map.md): SIO ports, COM8116 instead of 8253, second SIO, PIO, RTC,
   and VRAM access via the 6545. Also fix the ROM explainer's port table.

## Read in the ROM / archive (no hardware needed)
2. **System port (0x14) bit map** on the 81-184 board: confirm drive select, side, motor,
   density, ROM bank, A12CH (char set), HD CTRL RST. Sheet 2D plus the 292 ROM.
3. **Attribute bit order** (4 bits into U10): which bit is reverse, half, underline, blink.
   Read `ESC G/H` handling in the ROM.
4. **CPU→VRAM access sequence** through the 6545/U10 (update address R18/R19, strobe at 0x1F?).
   Read the ROM's `vidout`.
5. **What the 25th displayed row holds.**
6. **Keyboard beeper protocol:** which host bytes make which tones.

## Measure on the machine (scope, about an hour)
7. **CCLK ≈ 2.25 MHz and DE ≈ 35.6 µs**, as predicted from the ROM's CRTC table and the
   18 MHz crystal ([video](hardware/video.md#what-the-292-rom-programs-into-the-6545)).
8. HSYNC/VSYNC ≈ 21 kHz / 49.3 Hz.
9. J9 odd pins 33–41: what are they actually tied to?

## Look up on the board
10. Char ROM U9 piggyback clearance (for a Kaypro10Video-style tap or a char-ROM shadow).
11. Modem jumpers E14/E15/E8: what clocks SIO2 ch B (fB or 4800 Hz)?

## Design decisions
12. [Pico board](projects/pico-board.md): reconcile the interposer-set framing with the CPU-socket daughter board.
13. [Agent](projects/agent.md): what is it *for*? (programming, BBS, a resident character)
14. Agent modem path: home-built [line interface](projects/phone-line-interface.md) vs ATA → Asterisk.

## Conflicts between sources
- [Keyboard ROM analysis](hardware/keyboard/8049-rom-explained.md) vs [pinout notes](hardware/keyboard/8049-pinout.md):
  host→keyboard bytes arrive via the bus vs via T1. Check the keyboard PCB.
- K10 hard-disk ports 0x40–0x5F (ROM explainer, from K10 v7A source) can't work on
  81-184, which ignores A6. The K10's decode must differ; confirm in `k10rom7a`.

## Resolved 2026-10-27 (from the schematic)
- I/O port map; SIO count; baud generator part (COM8116, no 8253).
- Internal modem present: TMS99532 Bell 103 plus TMS99531 tone/pulse dialer; answer and originate.
- /WAIT already used (video, RTC), open-collector node.
- 50-pin header (J9) signals: no /INT, /BUSRQ, /MREQ; /M1 and /WAIT present; space 0x80–0xFF.
  This also settles "no expansion bus": J9 is an I/O-only expansion port.
- Char ROM is U9, 81-235 (2732). Dot clock is 18.000 MHz.
- Keyboard: 300 baud 8N1, 4-wire, ASCII plus keypad/cursor codes.

## Archive housekeeping
- Reorganisation per [proposed_structure.md](archive/proposed_structure.md): proposed, not executed.
- Dedup: ~546 MB reclaimable ([archive index](archive/README.md#deduplication-analysed-march-2026)).

## Meta
- Point the vault note `kaypro-research` at this repo (it lists a Gitea URL that never existed).
- Edge connector part number for "the video board": probably an '83-model question, since
  this board has video on the mainboard.
