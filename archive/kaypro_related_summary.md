# Kaypro Related Archive — Contents Summary

> **Superseded by [`master_contents.md`](master_contents.md)**, which covers both `kaypro/` and `kaypro_related/` in a unified, more detailed index. This file is kept as a historical snapshot of the `kaypro_related/` folder structure.



This folder is a less-organized companion to `kaypro/`, containing roughly 1.7 GB across ~6,700 files. Much of the material overlaps with `kaypro/`; cross-folder duplicates are noted throughout and collected at the end.

---

## Root Level

### Firmware / ROM Binaries
- `turbo.bin` (8 KB) + `turbo.bin.info` — TurboROM binary image; `.info` is an Amiga OS icon metadata sidecar file
- `81-146a.bin` — Firmware binary (origin unclear)

### CP/M Operating System Archives
- `cpm80.tar.gz` + `cpm80(1).tar.gz` — CP/M 80 distribution; the two `.tar.gz` files are exact duplicates
- `cpm80.zip` — Same CP/M 80 distribution in ZIP format
- `cpm22-b.zip` — CP/M 2.2 BIOS components *(also in `kaypro/cpm/`)*
- `cpm22pat.zip` — CP/M 2.2 patches *(also in `kaypro/cpm/`)*
- `cpm22red.zip` — CP/M 2.2 reduced/minimal version
- `cpm2.zip` — CP/M 2 base system
- `cpmtex.zip` — CP/M TeX package
- `STDCPM22.ZIP` + `STDCPM22.info` — Standard CP/M 2.2 distribution *(also in `kaypro/software/`)*
- `DRIPAK.ZIP` + `DRIPAK.info` — Digital Research operating system package (8.4 MB)

### Kaypro Software & Tools
- `trmsuppt.zip` — TurboROM terminal support *(also in `kaypro/software/brokezips/`)*
- `trom-doc.zip` / `TROM-DOC.ZIP` — TROM documentation (two copies of the same content) *(also in `kaypro/software/brokezips/`)*
- `TurboRom_Kaypro_4.zip` + `TurboRom_Kaypro_4(1).zip` — TurboROM for Kaypro 4; the two zips are exact duplicates *(also in `kaypro/software/brokezips/`)*
- `turborom.zip` + `turborom.zip.info` — Another TurboROM archive (possibly different version)
- `urmtkit1.zip`, `urmtkit2.zip`, `urmtkit3.zip` — Upgrade/ROM toolkit parts 1–3 *(also in `kaypro/software/`)*
- `kayplus.zip` — KayPlus ROM enhancement package
- `kp4diag.zip` — Kaypro 4 diagnostics *(also in `kaypro/software/`)*
- `kpdiag1.zip` — Kaypro diagnostics v1 with source *(also in `kaypro/software/`)*
- `kp-bios.zip` — BIOS source code
- `kcom-bcn.zip` — Communication software
- `kermit.zip` + `kermit(1).zip` — Kermit-80; the two files are exact duplicates *(also in `kaypro/cpm/`)*
- `kermit68.zip` — Kermit for 68000-based systems
- `kp-mite.zip` — Mite editor/tools
- `kpgames.zip` — Kaypro games collection
- `learn.zip` — CP/M learning materials *(also in `kaypro/cpm/`)*
- `mac-b.zip` — Mac utilities for CP/M
- `web-lan.zip` + `web-lan(1).zip` — Networking utilities; the two files are exact duplicates
- `wgrep.zip` — Grep utility for CP/M
- `KAYPROII.ZIP` + `KAYPROII.info` — Kaypro II software *(also in `kaypro/software/`)*
- `KAYPRO2X.ZIP` + `KAYPRO2X.info` — Kaypro 2X software *(also in `kaypro/software/`)*
- `kaypro4.zip` — Kaypro 4 archive (884 KB)
- `Kaypro.zip` — Large Kaypro archive (27 MB): ROMs, BIOS, disk images
- `kaypro-repair.zip` — Repair documentation PDF (32 MB, 150 DPI grayscale scan)
- `bootimd.zip` — Boot disk images (IMD format)
- `COMPUPRO.ZIP` + `COMPUPRO.info` — Compupro computer archive (6.3 MB)
- `doc-master.zip` — Documentation master archive (55 files, includes SDCC docs)

### Disk Images (root level)
- `k4-games.td0` — Kaypro 4 games disk (Teledisk format)
- `kp22gdsd.td0` + `kp22gdsd(1).td0` — CP/M 2.2 GDS disk image; the two files are exact duplicates
- `kpmex114.td0` — Mex communications software disk image
- `kp-trom.td0` — TROM floppy image
- `Kaypro-4-DS-HFE.zip` — Kaypro 4 double-sided HFE floppy image (for HxC emulator)
- `zork1.zip` — Zork I adventure game disk image

### Disk Emulator Tools
- `HxCFloppyEmulator_soft.zip` (13 MB) — HxC Floppy Emulator software *(extracted copy in `HxCFloppyEmulator_soft/`)*
- `flashfloppy-3.39.zip` — FlashFloppy firmware source *(extracted copy in `flashfloppy-3.39/`)*
- `FreHD_2.14.zip` — FreHD hard disk emulator for TRS-80/Z80 systems
- `FF_Images.zip` — FlashFloppy disk images
- `imd118.zip` — ImageDisk v1.18 disk imaging tools
- `format.jar` — Java disk formatting utility
- `cpt.zip` — CP/T tools archive

### Z80 Tools
- `Z80-081707.zip` — Z80 tools/documentation
- `z80prog.zip` — Z80 programming tools
- `z80-asm.5` — Z80 assembler man page *(also in `kaypro/software/source/`)*
- `z80_kc85_kc85-20mhz.sr`, `z80_kc85_kc85-cpuclk.sr` — KC85 Z80 signal recording files
- `zrt80.tar` — ZRT80 Z80 system archive (2 MB)

### CP/M Tools Source
- `cpmtools-2.23.tar.gz` — CPM tools source archive *(extracted copy in `cpmtools-2.23/`)*

### CP/M Utilities (raw binaries)
- `KPVID.LBR` — Video utility library
- `VT100KAY.LBR` — VT100 emulator for Kaypro
- `XLATE5.LBR` — Character translation utility
- `KRAMDISK.TZT` — RAM disk utility

### PC-to-CP/M Transfer Utilities
- `PCGET.ASM`, `PCPUT.ASM` — Assembly source for PC-to-CP/M serial file transfer
- `mload.com` — Module loader

### PDFs — Kaypro Documentation (root level, outside `kaypro_related/` subfolder)
- `KayproOperation.pdf` — Kaypro 84 Theory of Operation, © 1984 Micro Cornucopia, by Eric Roby (13 pp, ImageMagick scan 2011) *(also in `kaypro/theory/` and `kaypro/virtual-kaypro/`)*
- `1984_Kaypro_II-4_84_Theory-of-Operation.pdf` — Same document, better scan: FineReader OCR'd 2022, searchable text layer; 7.3 MB
- `1984_Kaypro_II-4_84_Theory-of-Operation_Schematic.pdf` — **Micro Cornucopia Kaypro 84 Schematic** (1 page fold-out, 2560×1722 pt high-res); companion to the Theory of Operation. Distinct from `KayproSchematic.pdf` (which is the official Kaypro Corp schematic)
- `kaypro150dpigrayscale.pdf` — *Chilton's Guide to Kaypro Repair and Maintenance* by Gene B. Williams (221 pp, 34 MB); covers troubleshooting, repairing boards/drives/keyboards/monitors, add-ons. Includes Kaypro 16. Scanned from San Jose State University library copy. Not a duplicate of anything in the archive.
- `KayproAddendum.pdf` — Kaypro addendum *(also in `kaypro/virtual-kaypro/`)*
- `KayproSchematic.pdf` — Official Kaypro Corp circuit schematic *(also in `kaypro/schematics/` and `kaypro/virtual-kaypro/`)*
- `Kaypro_Disk_Drive_Diagnostic_Users_Guide_1983.pdf` *(also in `kaypro/manuals/`)*
- `Kaypro_Software_Bulletin_Jul83.pdf` *(also in `kaypro/manuals/`)*
- `Kaypro_Hardware_Upgrades_text.pdf` *(also in `kaypro/manuals/`)*
- `kaypro-repair.zip` — Repair manual (see archives above)
- `kaypro.doc` — Kaypro notes *(also in `kaypro/theory/`)*
- `kuser.pdf` — Kaypro user guide
- `kayprospec.pdf` — Kaypro specifications
- `kproto.pdf` — Prototype documentation
- `Kaypro-ROM-Versions.pdf` — ROM version reference
- `kayplus.pdf` — KayPlus ROM manual

### PDFs — CP/M Documentation
- `CPM_2.2_Alteration_Guide_1979.pdf` — CP/M 2.2 system alteration guide *(cf. `kaypro/cpm/CPM_2_0_System_Alteration_Guide.pdf`)*
- `CPM_2_0_Interface_Guide.pdf` — CP/M 2.0 interface guide
- `cpm22-m.pdf` — CP/M 2.2 manual *(also in `kaypro/cpm/`)*
- `dri-cpnet.pdf` — DRI CP/Net manual
- `portingcpm.html` — CP/M porting guide *(cf. `kaypro/web/porting-cpm-to-a-new-computer.html`)*

### PDFs — Z80 / Processor
- `um0080.pdf`, `um0081.pdf` — Zilog Z80 CPU documentation (two volumes)
- `z80-interrupts.pdf` — Z80 interrupt system reference
- `Chapter 3 Z80.pdf` — Z80 CPU chapter excerpt
- `Microsoft M80 Assembler.pdf` — M80 macro assembler manual

### PDFs — Hardware / ICs
- `39402-0_706-712_Hard_Disk_Reference_Manual_1984.pdf` — Hard disk reference manual
- `61-031050-0030_WD1002-05_HDO_OEM_Manual_Jul83.pdf` — WD1002-05 OEM manual *(cf. `kaypro/datasheets/WD1002-05-Winchester_HD-controller-manual_Jul83.pdf`)*
- `79000004WD1002SHDOEMManualAug1984.3449749783.pdf` — WD1002 manual, August 1984 variant (third copy of essentially the same document)
- `CRTC_COMPENDIUM_v1.6_2023-07[ENG].pdf` — Modern CRT controller compendium
- `21C_TOCR29.pdf` — CRTC chip reference
- `sn74hc595.pdf` — 74HC595 shift register datasheet
- `sn74ls14.pdf` — 74LS14 Schmitt trigger datasheet
- `74HC_HCT245.pdf`, `74HC_HCT125.pdf` — Logic IC datasheets
- `SC16IS740_750_760.pdf` — NXP serial UART IC datasheet
- `m48t08.pdf` — Timekeeper NRAM IC datasheet
- `27C64.pdf`, `2764_EPROM.pdf` — 2764 EPROM datasheets (two copies of essentially the same data)
- `LM7812-461970.pdf` — 7812 voltage regulator datasheet
- `Micro-C-ROMs.pdf` — ROM IC reference
- `Introduction to NAND Flash.pdf` — NAND flash memory overview
- `5666.5668.pdf` — IC datasheets
- `floppy.pdf` — Floppy drive documentation *(also in `kaypro/theory/`)*
- `adm3-mm.pdf` (15 MB) — ADM-3A terminal technical manual
- `DTR-DSR-RTS-CTS_Difference.pdf` — RS-232 signal reference
- `4a-esp8266_at_instruction_set_en_v1.5.4_0.pdf` — ESP8266 Wi-Fi module AT command set

### PDFs — Other Software / Languages
- `Turbo_Pascal_Version_3.0_Reference_Manual_1986.pdf` — Turbo Pascal 3.0 reference (11 MB)
- `sdccman.pdf` — SDCC small device C compiler manual
- `plipg.zip` — Programming language documentation
- `pl1lrm.zip` — PL/I language reference manual
- `mac.pdf` — Microsoft MAC assembler reference
- `PDF32000_2008.pdf` (22 MB) — PDF 1.7 specification
- `Micro_Cornucopia_24_Jun85.pdf` (10 MB) — Micro Cornucopia magazine issue #24, June 1985 *(single issue; full archive is in `bitsavers_microCornua30Jun86_11542571/`)*

### HTML Files
- `cpmfsinfo.html` (6.6 MB), `cpmfs.html` (5.4 MB), `cpmf.html` — CP/M filesystem documentation (three related/overlapping pages from the same source)
- `Jz0qcG2G.html` — Retro computing documentation
- `portingcpm.html` — CP/M porting guide

### KP-CBOOT Documentation (same content, four formats)
- `KP-CBOOT.DOC` — Original *(also in `kaypro/theory/`)*
- `KP-CBOOT.txt` — Plain text conversion
- `KP-CBOOT.md` — Markdown conversion
- `KP-CBOOT.odt` — OpenDocument conversion

### Miscellaneous Root Files
- `77053-strange-disk-problem-kaypro-selfbuilt-bios-for-harddisk` — Archived forum thread about a custom BIOS/hard disk problem
- `hardware_README` — Hardware documentation notes
- `README` — Z80-asm readme
- `Ramdisk-System-Master-CPM_archive.torrent` — Torrent metadata for a CP/M RAM disk system master archive
- `V56pR.jpg` — CRTC chip diagram image
- `Selectric Advocate.ttf`, `Selectric Scribe.ttf`, `Selectric Orator.ttf` — IBM Selectric-style display fonts
- `presentation.PDF` — Presentation materials (contents unclear)

---

## `kaypro4/` — Main Content Subdirectory

The bulk of the collection (1.2 GB). Contains a mixture of PDFs, web archives, disk images, emulator files, and forum content.

### `kaypro4/tech manual/` (477 MB, 43 files)
OCR'd and analyzed Kaypro 4 technical manual. The large size suggests high-resolution scans plus derived text/analysis files. This is the most storage-intensive item in the entire archive.

### `kaypro4/virtual-kaypro/` (160 MB, 34 files)
Virtual Kaypro emulator materials, including the Java emulator and disk images. Content appears to overlap substantially with `kaypro/virtual-kaypro/`; may be an earlier or source version.

### `kaypro4/workdir/` (471 MB)
Archived web content, primarily mirrors of `sebhc.durgadas.com` (a Kaypro/S-100 hardware community site). Contains a `sebhc.durgadas.com/` directory and a `sebhc.durgadas.com_old/` directory — the latter appears to be a prior snapshot of the same site (duplicate mirror).

### `kaypro4/Disk-Utilities/` (6.2 MB)
Open-source disk image manipulation toolkit written in C. Source code for reading, writing, and converting disk image formats.

### `kaypro4/floppy images/` (14 MB, 184 files)
Collection of floppy disk images in various formats (IMD, TD0, IMG, etc.) for Kaypro and CP/M systems.

### `kaypro4/forum/` (4 MB, 67 files)
Archived forum discussions about Kaypro hardware and software (HTML pages).

### `kaypro4/pdf/` (128 MB)
Miscellaneous PDF collection — likely unsorted overflow from other categories.

### `kaypro4/theory/` (9.3 MB)
Theory and reference materials for Kaypro hardware operation *(cf. `kaypro/theory/`; likely overlapping content)*.

### `kaypro4/Z80 Support_files/` (4.1 MB)
Supporting files for Z80 documentation (likely images/assets for an archived web page).

### `kaypro4/www.vcfed.org/` (3.8 MB)
Archived pages from the Vintage Computer Federation forums — discussions relevant to Kaypro/CP/M.

### `kaypro4/source/` (24 KB)
Small collection of source code files.

### `kaypro4/floppy/`
Empty directory.

---

## `z80/` — Z80 Processor Resources (170 MB, 147 files)

- **`dazzlestar/`** — Z80 disassembler project (Git repository with full source)
- **`z80-asm-2.4.1/`** — Complete z80-asm assembler source distribution
- **`z80-asm-current.tar.gz`** — Latest z80-asm source (likely same as or newer than `z80-asm-2.4.1/`)
- **`asm80.zip`**, **`z80prog.zip`**, **`myz80.zip`** — Z80 tool archives
- PDFs: "How to Program the Z80", Zilog Z80 manuals, and other Z80 processor documentation

---

## `bitsavers_microCornua30Jun86_11542571/` — Micro Cornucopia Magazine Archive (12 MB)

Internet Archive download of the Micro Cornucopia magazine collection through June 1986, with SQLite database and XML metadata. The root-level `Micro_Cornucopia_24_Jun85.pdf` is a single issue from this same publication.

---

## `cpmtools-2.23/` — CPM Tools Source (extracted)

Full source distribution of cpmtools 2.23, a Unix toolkit for reading/writing CP/M disk images. The corresponding `cpmtools-2.23.tar.gz` in the root is the same content as a compressed archive.

---

## `flashfloppy-3.39/` — FlashFloppy Firmware Source (extracted)

Source code for the FlashFloppy open-source floppy emulator firmware. The corresponding `flashfloppy-3.39.zip` in the root is the same content compressed.

---

## `HxCFloppyEmulator_soft/` — HxC Floppy Emulator Software (extracted)

HxC Floppy Emulator PC software distribution. The corresponding `HxCFloppyEmulator_soft.zip` in the root is the same content compressed.

---

## `keyboard/` — Keyboard Photographs (74 MB, 19 JPGs)

High-resolution photographs of Kaypro keyboard hardware, dated 2022-02-01 (`IMG_20220201_*.jpg`). 16 full-size images (3–6 MB each) and 3 smaller detail shots. These are distinct from the keyboard photos in `kaypro/images/` (which are dated January 2019).

---

## Duplicates and Redundancies

### Within `kaypro_related` (internal duplicates)

| Item | Copies |
|------|--------|
| `cpm80.tar.gz` / `cpm80(1).tar.gz` | Exact duplicate pair |
| `cpm80.tar.gz` vs `cpm80.zip` | Same content, different formats |
| `TurboRom_Kaypro_4.zip` / `TurboRom_Kaypro_4(1).zip` | Exact duplicate pair |
| `kermit.zip` / `kermit(1).zip` | Exact duplicate pair |
| `web-lan.zip` / `web-lan(1).zip` | Exact duplicate pair |
| `kp22gdsd.td0` / `kp22gdsd(1).td0` | Exact duplicate pair |
| `trom-doc.zip` / `TROM-DOC.ZIP` | Same content, different filename case |
| `KP-CBOOT.DOC` / `.txt` / `.md` / `.odt` | Same document in four formats |
| `27C64.pdf` / `2764_EPROM.pdf` | Same datasheet, two copies |
| `cpmtools-2.23.tar.gz` (root) + `cpmtools-2.23/` (directory) | Archive + extracted copy |
| `flashfloppy-3.39.zip` (root) + `flashfloppy-3.39/` (directory) | Archive + extracted copy |
| `HxCFloppyEmulator_soft.zip` (root) + `HxCFloppyEmulator_soft/` (directory) | Archive + extracted copy |
| `sebhc.durgadas.com/` + `sebhc.durgadas.com_old/` (in `kaypro4/workdir/`) | Two snapshots of the same website |
| WD1002 manual (3 copies) | `61-031050-0030_WD1002-05_HDO_OEM_Manual_Jul83.pdf`, `79000004WD1002SHDOEMManualAug1984.3449749783.pdf`, and `kaypro4/pdf/` likely contains another |
| `Micro_Cornucopia_24_Jun85.pdf` (root) + `bitsavers_microCornua30Jun86_11542571/` | Single issue vs. full archive |
| `.info` files | Amiga OS icon metadata sidecars for: `turbo.bin`, `turborom.zip`, `KAYPROII.ZIP`, `KAYPRO2X.ZIP`, `STDCPM22.ZIP`, `TROM-DOC.ZIP`, `COMPUPRO.ZIP`, `DRIPAK.ZIP`. These files were likely downloaded from BBS systems or newsgroups in the 1980s–90s by an Amiga user — a common archiving practice of the era. |

### Duplicates vs `kaypro/`

| Item | Location in `kaypro_related` | Location in `kaypro/` |
|------|------------------------------|----------------------|
| `cpm22-b.zip` | root | `cpm/` |
| `cpm22pat.zip` | root | `cpm/` |
| `kermit.zip` | root | `cpm/` |
| `learn.zip` | root | `cpm/` |
| `cpm22-m.pdf` | root | `cpm/` |
| `STDCPM22.ZIP` | root | `software/` |
| `KAYPROII.ZIP` | root | `software/` |
| `KAYPRO2X.ZIP` | root | `software/` |
| `urmtkit1-3.zip` | root | `software/` |
| `kp4diag.zip` | root | `software/` |
| `kpdiag1.zip` | root | `software/` |
| `trmsuppt.zip` | root | `software/brokezips/` |
| `trom-doc.zip` / `TROM-DOC.ZIP` | root | `software/brokezips/` |
| `TurboRom_Kaypro_4.zip` | root | `software/brokezips/` |
| `KayproOperation.pdf` | root | `theory/`, `virtual-kaypro/` |
| `KayproAddendum.pdf` | root | `virtual-kaypro/` |
| `KayproSchematic.pdf` | root | `schematics/`, `virtual-kaypro/` |
| `Kaypro_Disk_Drive_Diagnostic_Users_Guide_1983.pdf` | root | `manuals/` |
| `Kaypro_Software_Bulletin_Jul83.pdf` | root | `manuals/` |
| `Kaypro_Hardware_Upgrades_text.pdf` | root | `manuals/` |
| `floppy.pdf` | root | `theory/` |
| `kaypro.doc` | root | `theory/` |
| `KP-CBOOT.DOC` | root | `theory/` |
| `z80-asm.5` | root | `software/source/` |
| Virtual Kaypro emulator | `kaypro4/virtual-kaypro/` | `virtual-kaypro/` |
| Theory/operation docs | `kaypro4/theory/` | `theory/` |
