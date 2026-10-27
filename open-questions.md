# Open questions and things to measure

Ordered roughly by how much they unblock. Strike through or move the answer into the
relevant page when resolved.

## Measure on the machine (scope, about an hour total)
1. **Keyboard protocol:** baud rate, framing, ASCII vs scancodes, what the host sends back.
   Unblocks the [agent keyboard mux](projects/agent.md#keyboard-mux).
2. **CCLK frequency and DE width:** resolves the 56-vs-80 column contradiction in
   [video](hardware/video.md#measured-timing-kaypro-10-sy6545-from-kaypro10video).
3. **Confirm HSYNC/VSYNC** match the K10 numbers (~21 kHz / ~49 Hz).

## Look up in the schematic / on the board
4. **Char ROM part and U-number** on the 4/84 (2732 vs 2716); clearance for a piggyback stack.
5. **50-pin header:** which I/O ports, which address lines, /M1, IEI/IEO, /WAIT, buffer parts.
6. **CPU socket:** is /WAIT already used (FDC, CRT)?
7. **Internal modem present?** Bell 103 only? Can it blind-dial? Tone or pulse?

## Design decisions
8. [Pico board](projects/pico-board.md): reconcile the interposer-set framing with the CPU-socket daughter-board framing.
9. [Agent](projects/agent.md): what is it *for*? (programming, BBS, a resident character)
10. Agent modem path: home-built [line interface](projects/phone-line-interface.md) vs ATA → Asterisk.

## Conflicts between sources
- A past discussion called the 4/84 "no expansion bus"; the 50-pin HDD header carries most
  of the bus plus interrupt (minus BUSREQ/BUSACK). Probably both true depending on what
  "expansion bus" means. Settle and fix the wording in [machine](hardware/machine.md).

## Meta
- **Relationship to `kaypro_stuff`.** That repo already holds the research notes and
  archive indexes. Decide whether this repo is (a) the design/decision wiki that links
  into `kaypro_stuff`, or (b) a replacement that absorbs its notes. Either works; having
  two partially overlapping homes is the failure mode.
- Edge connector part number for the video board (asked once, unresolved).
