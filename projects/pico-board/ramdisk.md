# Kaypro RAM Disk — Research Notes

> **See also:** [`pico-board/design-notes.md`](design-notes.md) — the RAM disk is implemented as Subsystem 2 of the combined RP2040 daughter board project. Hardware design decisions (addressing strategy, SRAM sizing, BIOS driver) are tracked there.

## Hardware Approaches

### CPU Socket Daughter Board (observed in the wild)
The most common physical form for Kaypro RAM disk attachments: a daughter board that plugs into the Z80 CPU socket, with the Z80 itself re-seated into a socket on top of the daughter board. This gives the board clean access to every Z80 bus signal (A0–A15, D0–D7, /MREQ, /IORQ, /RD, /WR, /M1, /WAIT, /BUSACK, etc.) without cutting traces or tapping the expansion connector.

The daughter board watches bus transactions and, for a configured address range, takes over: it de-asserts the system memory select, drives the data bus from its own SRAM, and can assert /WAIT if it needs time. The Z80 is unaware anything has changed — it just sees memory at those addresses.

Advantages:
- No trace cuts, no soldering to the motherboard
- Access to all signals in one place
- Works on any Z80 machine regardless of expansion connector availability
- The Z80 socket on the Kaypro 4 mainboard makes this straightforward

### Expansion Connector Board
The alternative: a board plugged into the Kaypro's proprietary expansion edge connector on the motherboard. Pinout is in `KayproSchematic.pdf`. Less universal than the CPU socket approach.

---

## Commercial Products Documented in the Archive

### Advent RAM Disk (Advent Products, Inc.)
- Sizes: 256 KB, 512 KB, 1 MB
- Up to 2 units simultaneously
- TurboROM 3.4 has built-in auto-detection: scans at boot and assigns the next available CP/M drive letter after floppy/hard drives
- No extra software needed if running TurboROM

### Micro Sphere RAM Disk
- Documented in `kaypro/software/pro884mx/MRDISK.DOC`
- Works with the MAX ROM (pro884mx.rom)
- Setup: run `RAMCON.COM` to install updated BIOS and configure drive letter and size, then reset
- `RF.COM` formats and sysgens the RAM disk
- Supports hotkey swap between RAM disk and drive A:
- Has a built-in printer spooler that uses the RAM disk as a buffer
- Can be used without the new BIOS via `ESC K` to wake it (appears as drive E: only in that mode)
- Commands: `ESC H` = pause printer buffer, `ESC K` = halt and clear printer buffer

### KRAMDISK
- Documented in `kaypro_related/KRAMDISK.TZT` (compressed, not yet read)
- Name and 22 KB of documentation suggest a software or hybrid RAM disk
- Likely carves space from upper memory rather than requiring external hardware
- **To do: decompress KRAMDISK.TZT to read full docs**

---

## Software/BIOS Requirements

All approaches require the BIOS to register the RAM disk as a CP/M logical drive. CP/M communicates with all drives through the BIOS jump table (HOME, SELDSK, SETTRK, SETSEC, SETDMA, READ, WRITE). A RAM disk just needs those routines to read/write SRAM instead of a disk controller.

### With a ROM replacement
- **TurboROM**: auto-detects Advent RAM disk, assigns drive letter automatically, configured via `TURBOCFG.COM`
- **MAX ROM (pro884mx)**: supports Micro Sphere RAM disk via `RAMCON.COM`
- **KayPlus**: likely has similar support (check `kayplus.pdf`)

### Without a ROM replacement (stock Kaypro ROM)
Need to patch the BIOS manually. References in the archive:
- `kaypro/software/source/bios.mac` — 1982 reference BIOS with full CP/M jump table in Z80 assembly; the template for understanding how drives are registered
- `kaypro/software/source/k10rom7a/` — Kaypro 10 ROM v7A full source; shows how floppy and hard disk drives are handled, RAM disk support would follow the same pattern
- `kaypro_related/kaypro4/source/kaypro_292_rom.s` — 292 variant ROM source for comparison

---

## Memory Map Considerations

The Z80 has a 64 KB address space. The Kaypro uses all 64 KB as RAM (with ROM mapped in only during boot, then switched out). A CPU socket daughter board can extend this by:
- **Bank switching**: the daughter board controls an additional address line (or a latch driven by an I/O write) to select between multiple 64 KB banks
- **Address decode with /WAIT**: the board watches for accesses to a specific address range and responds with its own SRAM, transparently to the CPU

From TurboROM docs: the memory layout from the top of the 64 KB space downwards is:
- `0xFFFF` downward: BIOS scratch area (size varies with number of drives)
- Below scratch: free memory (used for drivers etc.)
- Below free: BIOS
- Below BIOS: BDOS
- `0x0100` upward: TPA (Transient Program Area — where CP/M programs run)
- `0x0000`–`0x00FF`: CP/M system parameters

A 56 KB CP/M system is small enough to boot with any combination of floppy, hard, and RAM disks. Maximising the TPA requires running `TURBOGEN`/`MOVCPM` to set the system size appropriately.

---

## Files in the Archive Relevant to RAM Disk

| File | Location | Notes |
|------|----------|-------|
| `MRDISK.DOC` | `kaypro/software/pro884mx/` | Micro Sphere RAM disk setup guide |
| `RAMCON.COM` | `kaypro/software/pro884mx/` | Micro Sphere BIOS installer/configurator |
| `RF.COM` | `kaypro/software/pro884mx/` | Formats and sysgens the Micro Sphere RAM disk |
| `KRAMDISK.TZT` | `kaypro_related/` | Compressed RAM disk documentation (needs decoding) |
| `Turbo_Rom.txt` | `kaypro/software/TurboRom_Kaypro_4/TurboRom_3_4/TROM-DOC/` | Section 5.5 covers Advent RAM disk support |
| `TROM.DOC` | `kaypro/software/trom-doc/` | WordStar format; RAM disk section present |
| `bios.mac` | `kaypro/software/source/` | 1982 reference BIOS source — starting point for RAM disk BIOS driver |
| `k10rom7a/` | `kaypro/software/source/` | Full ROM source; RAM.MAC covers scratch RAM layout |
| `KayproSchematic.pdf` | `kaypro/schematics/` | Expansion connector pinout |

---

## Next Steps for a DIY Build

1. Read `KRAMDISK.TZT` (decompress the Crunch file)
2. Read `kayplus.pdf` for KayPlus RAM disk support details
3. Study expansion connector pinout in `KayproSchematic.pdf`
4. Study `bios.mac` SELDSK/READ/WRITE routines for the BIOS driver template
5. Decide on form factor: CPU socket daughter board vs expansion connector board
6. Decide on volatility: plain SRAM (lost on power-off) vs battery-backed SRAM (persistent)
