# Open questions and things to measure

Ordered roughly by how much they unblock. When one is resolved, put the answer in the
relevant page and delete it here.

## Fix before trusting the code
1. **Audit the I/O port map in [`kaypro.h`](projects/bios-c/kaypro.h).** Its SIO and baud
   generator assignments contradict the ROM's own `kbdstat`/`kbdin` code and the period
   `kaypro.doc`, which put the SIO at 0x04–0x07. See [machine § I/O map](hardware/machine.md#io-map-disputed).
   Check against the 292 ROM disassembly, the `k10rom7a` source and the schematic.
   Also fix the ROM explainer's port table, which contradicts its own disassembly.
2. **Video RAM model in `kaypro.h`** (`VRAM_BASE 0xF000`, `VRAM_ROWS 24`) vs the '84 board's
   VRAM behind the 6545 and 25 displayed rows.

## Read in the archive (no hardware needed)
3. **Keyboard protocol and baud rate:** the keyboard USB conversion project (`web/`) and
   `kaypro_keyboard.txt`. Unblocks the [agent keyboard mux](projects/agent.md#keyboard-mux).
4. **Baud generator part:** is it a COM8116-type (code `05h` = 300 fits that) or an 8253? Schematic.
5. **What the 25th displayed row holds.**

## Measure on the machine (scope, about an hour)
6. **CCLK ≈ 2.25 MHz and DE ≈ 35.6 µs**, as predicted from the ROM's CRTC table ([video](hardware/video.md#what-the-292-rom-programs-into-the-6545)).
7. HSYNC/VSYNC match ~21 kHz / ~49.3 Hz.
8. Keyboard line: confirm whatever item 3 says.

## Look up on the board / in the schematic
9. Char ROM part and U-number on the 4/84 (2732 vs 2716); clearance for a piggyback stack.
10. 50-pin header: routed ports, address lines, /M1, IEI/IEO, /WAIT, buffers.
11. CPU socket: is /WAIT already used (FDC, CRT)?
12. Internal modem: Bell 103 only? Can it blind-dial? Tone or pulse?

## Design decisions
13. [Pico board](projects/pico-board.md): reconcile the interposer-set framing with the CPU-socket daughter board.
14. [Agent](projects/agent.md): what is it *for*? (programming, BBS, a resident character)
15. Agent modem path: home-built [line interface](projects/phone-line-interface.md) vs ATA → Asterisk.

## Conflicts between sources
- A past discussion called the 4/84 "no expansion bus"; the 50-pin HDD header carries most
  of the bus plus interrupt (minus BUSREQ/BUSACK). Settle the wording in [machine](hardware/machine.md).
- The ROM explainer's "K10" CRTC table (8 scanlines, ~15.7 kHz) vs the 21 kHz / 400 lines
  measured on a universal-board K10. Probably the 1983 pre-universal K10; confirm in `k10rom7a`.

## Archive housekeeping (from `kaypro_stuff`)
- Reorganisation per [proposed_structure.md](archive/proposed_structure.md): proposed, not executed.
- Dedup: ~546 MB reclaimable ([archive index](archive/README.md#deduplication-analysed-march-2026)).

## Meta
- Point the vault note `kaypro-research` at this repo (it lists a Gitea URL that never existed).
- Edge connector part number for the video board (asked once, unresolved).
