# Pico debug / daughter board

Status: **design only**, nothing built.

Two framings of the same project have come up. They overlap heavily and should probably
be reconciled into one design.

## Framing A: interposer set (from the Kaypro Claude project)
A single Pico connected by ribbon cables to four interposer points:
1. **Z80 CPU interposer:** IDC/DIP plug with 74HC**T**245/244 transceivers (HCT, see
   [machine](../hardware/machine.md#electrical-rules-for-anything-attached)), full CPU pin
   access including bus-mastering signals. Adopted because the 50-pin HDD header lacks
   BUSREQ/BUSACK.
2. **BIOS EEPROM interposer:** SRAM shadowing and selectable boot ROM images.
3. **VRAM interposers:** replace both 6116s (char and attribute) with **Cypress CY7C136**
   dual-port SRAM (52-pin PLCC; sockets on hand). The Pico gets direct VRAM access via
   port B without CRTC involvement. The 136's semaphore/BUSY/INT (mailbox) pins can serve
   as Z80↔Pico signaling. On the CY7C136 (master), BUSY is open-drain and needs a pull-up.
4. **Char ROM shadow:** custom glyphs. The char ROM sits next to the VRAMs. This is also
   the socket [Kaypro10Video](../hardware/video.md#digital-capture-kaypro10video) taps,
   so screen capture can live on this board.

Horizon: a dedicated Pico carrier PCB to replace the ribbon-cable spread.

## Framing B: CPU-socket daughter board ([design-notes.md](pico-board/design-notes.md))
One board in the Z80 socket (Z80 re-seated on top), RP2040 on the full bus, three subsystems:
1. **Boot manager:** bank-switched ROM images in larger flash (27C512 = 8 slots,
   SST39SF040 = 64). Slot 0 is a custom menu ROM. The Pico switches bank and pulses /RESET.
   /WAIT hides flash timing. Candidates (all in the archive): stock 81-478c, KayPLUS 84/83,
   PRO-884 MAX, Super MAX 2.7, TurboROM 3.4.
2. **RAM disk:** battery-backed 512 KB SRAM (e.g. AS6C4008) as CP/M drive(s), with a
   BIOS driver ([C BIOS](bios-c.md)). Prior art: Advent, Micro Sphere, KRAMDISK ([ramdisk.md](pico-board/ramdisk.md)). An `84KP256A.DOC` (256 KB RAM expansion for '84 boards) is in the archive.
3. **System monitor:** /M1 snooping for trace and breakpoints, /BUSRQ to inspect and modify
   memory, USB CDC console.

Decision recorded there: CPU-socket form factor rather than the expansion edge connector
(all signals in one place, no trace cuts). Full design: [design-notes.md](pico-board/design-notes.md) (bus signals, GPIO allocation, subsystem designs). RAM disk background: [ramdisk.md](pico-board/ramdisk.md).

## Useful facts
- U29 refreshes DRAM itself (Z80 /RFSH unused), so **long /BUSRQ holds are safe**.
- /WAIT and /BUSRQ act upstream of U29's bank decode.
- A Pico running PIO logic-analyzer firmware is plenty for 4 MHz bus capture. Use it to
  verify timing on the real box.

## Other uses of the same hardware
- [Agent](agent.md): keyboard mux, reset/power optos, Gotek buttons, screen-capture oracle.
- [NPU coprocessor](npu-coprocessor.md): the CPU interposer turns into an expansion port.

## Open questions
- Reconcile A and B: one board or two?
- ~~Is /WAIT already used?~~ **Yes**: video (VIDWAIT) and RTC drive it through a 7406
  open-collector with a 750 Ω pull-up. The board must drive /WAIT open-collector too.
- The J9 header lacks /INT, /BUSRQ, /MREQ and A8–A15, which confirms the CPU-socket form factor.
- Pico (26 GPIO) vs Pico 2 (30 GPIO). The Pico's 26 GPIO run out fast with four interposers.
- RAM disk addressing: I/O-mapped, bank-switched window, or DMA via /BUSRQ?
- Which ROM video/keyboard routines a menu ROM can safely call from cold start.
