# Kaypro ROM Overview

## Known ROM Versions

The Kaypro ROM is part-numbered in the `81-xxx` series (Kaypro/NLS part numbering scheme). From `KP-VERSN.TXT`, the known ROM versions by model:

| ROM Part | CP/M | Models |
|----------|------|--------|
| `81-18` | 2.2D | K10/83 (earliest Kaypro 10) |
| `81-149-C` | 2.2F | KII/83 (obsolete mainboard 81-110) |
| `81-232` | 2.2F | KII/83 (81-184 board), K4/83 (81-184 board) |
| `81-232-A` | 2.2F | K4/83 (81-240 board); `SWP` variant for K4/83+88 |
| `81-242` | 2.2F | KII/83 (81-184 board, alternate) |
| `81-292-A` | 2.2G/H | K2X, K2/84, K4/84; `SWP` variant for +88 models |
| `81-302` | 2.2F | K10 |
| `81-302-C` | 2.2G/H | K10 (revised) |
| `81-326-E` | 2.2H | K4X |
| `81-478-A` | 2.2U1 | K1, K2X/MTC, NEW 2, K10/MTC (latest/unified ROM) |

Notes:
- The `SWP` suffix denotes a board configuration variant, possibly for units with the 88xx co-processor option
- CP/M versions progress D → F → G → H → U1, corresponding roughly to 1983 → 1984 → 1985
- `81-478-A` is the final unified ROM, used across the late-production "84-series" boards
- The K4X's `81-326-E` is unique to that model
- The K10/83 is the earliest entry, with the oldest CP/M (2.2D) and a bare `81-18` part number with no letter suffix

---

## ROM-Related Files in the Archive

### Reference Documents

| File | Location | Notes |
|------|----------|-------|
| `KP-VERSN.TXT` | `kaypro/` | Version matrix — model × mainboard × ROM |
| `Kaypro-ROM-Versions.pdf` | `kaypro_related/` | PDF ROM version reference (may contain more detail than KP-VERSN.TXT) |
| `KP-CBOOT.DOC` / `.txt` / `.md` / `.odt` | `kaypro/theory/`, `kaypro_related/` | Documents specific memory locations in the K10 CP/M 2.2F ROM: `EA33h` (I/O byte), `EA47h`/`EA48h` (baud rates), cursor key table |

---

### ROM Source Code

| File | Location | Notes |
|------|----------|-------|
| `software/source/bios.mac` | `kaypro/` | **Early Kaypro BIOS, July 1982.** 1,758 lines, MAC80 assembler. Full CP/M BIOS jump table. Supports 5.25" and 8" drives, 8251A USART, 8253 baud rate generator. Likely KII/83 era firmware |
| `software/source/k10rom7a/` | `kaypro/` | **Kaypro 10 ROM v7A full source, 1983, NLS copyright.** Six `.MAC` modules: `ROM7A.MAC` (cold start / jump table), `DEVIO.MAC` (serial/parallel I/O), `FLPYIO.MAC` (floppy, 17 KB), `HDIO7A.MAC` (Winchester hard disk, 16 KB), `VIDEO.MAC` (display, 16 KB), `MOVE77.MAC`, `RAM.MAC`. Plus `ROM7A.HEX` (assembled Intel HEX output). Contains documented in-source bug fix: "8-Jun-83, M. Sherman — proper floppy response on power-up" |
| `kaypro4/source/kaypro_292_rom.s` | `kaypro_related/` | **Kaypro 292 ROM source, 24 KB Z80 assembly.** Board revision of the Kaypro 4/10 — a second version for comparison against v7A |
| `software/pro884mx/AUTOLOAD.Z80` | `kaypro/` | Z80 bootloader for the ProMulti 884 MAX ROM (third-party ROM enhancement for 88xx-series) |

---

### ROM Binary Images

| File | Location | Size | Notes |
|------|----------|------|-------|
| `software/rom.txt` | `kaypro/` | — | Binary ROM image with `.txt` extension (misnomer). Contains strings: `"KAYPRO"`, `"Please place your diskette into Drive A"`, `"I cannot read your diskette"` |
| `virtual-kaypro/81-478c.rom` | `kaypro/` | 8 KB | Main system ROM used by VirtualKaypro emulator. `81-478c` part number — note lowercase `c` suffix, not in `KP-VERSN.TXT` (may be a sub-variant). 8 KB = 2764 EPROM size |
| `81-146a.bin` | `kaypro_related/` | 2 KB | Likely a character ROM or keyboard controller firmware (2716 EPROM size). `81-146a` part number — not in the version matrix, so not the main system ROM |
| `turbo.bin` | `kaypro_related/` | 8 KB | **TurboROM 3.4 binary** — the assembled image corresponding to the TurboROM source and docs in the archive. Arrived via an Amiga (has `.info` sidecar) |

---

### ROM Enhancement Software

| Item | Location | Notes |
|------|----------|-------|
| **TurboROM 3.4** | `kaypro/software/trmsuppt/`, `trom-doc/`, `TurboRom_Kaypro_4/`; `kaypro_related/` (multiple copies) | ROM enhancement for Kaypro 84-series. Source (`TURBO-BS.ASM`), pre-assembled relocatable object (`TURBO-BS.REL`), binary (`turbo.bin`), 187 KB manual (`TROM.DOC`), and utility suite (`TURBOCFG.COM`, `TURBOCPY.COM`, etc.) |
| **ProMulti 884 MAX ROM** | `kaypro/software/pro884mx/` | ROM enhancement for Kaypro 88xx. Z80 bootloader source (`AUTOLOAD.Z80`), Turbo Pascal config utilities (`MCONFIG.PAS`, `FASTTEST.PAS`) with compiled `.COM` files |
| **KayPlus** | `kaypro_related/` (`kayplus.zip`, `kayplus.pdf`) | ROM enhancement for Kaypro II/4. PDF manual and archive present |

---

### ROM Extraction & Manipulation Tools

| File | Location | Notes |
|------|----------|-------|
| `kpgetrom.zip` | `kaypro/software/` | Utility for dumping the ROM from a live Kaypro |
| `urmtkit1-3.zip` | `kaypro/software/`, `kaypro_related/` | Upgrade/ROM toolkit in three parts |

---

## Open Questions

- The version matrix lists `81-478-A` as the final production ROM, but the VirtualKaypro emulator uses `81-478c` — a suffix that doesn't appear in `KP-VERSN.TXT`. `Kaypro-ROM-Versions.pdf` in `kaypro_related/` may resolve this.
- `81-146a.bin` (2 KB) has no match in the version matrix. It is likely a secondary ROM (character generator or keyboard controller) rather than the main system ROM.
- `software/rom.txt` is a binary ROM image but its exact model/version is not documented anywhere in the archive.