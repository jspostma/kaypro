# Kaypro Research Archive — Contents Summary

> **Superseded by [`master_contents.md`](master_contents.md)**, which covers both `kaypro/` and `kaypro_related/` in a unified, more detailed index. This file is kept as a historical snapshot of the `kaypro/` folder structure.



---

## Root-Level Files

| File | Description |
|------|-------------|
| `KAYMAINT.TXT` | Maintenance guide covering reliability, common failures, and repair procedures |
| `KP-VERSN.TXT` | Version matrix: CP/M versions vs. Kaypro model, mainboard, and ROM revisions |
| `kaypro_keyboard.txt` | Keyboard technical specs and cable pinouts (76-key, 4-wire serial) |
| `AUTOBOOT.WZ` | Autoboot configuration file |
| `todo` | Personal notes: PSU upgrade, modem replacement, FDD controller mods, RAM disk, USB keyboard conversion ideas |

---

## `cpm/` — CP/M Operating System

**Documentation:**
- `CPM_2_0_System_Alteration_Guide.pdf` (+ OCR variant) — official Digital Research alteration guide for CP/M 2.0
- `cpm22-m.pdf`, `cpm-operating-manual.pdf`, `cpm_bootstrap.pdf` (+ RTF variant), `SC-CPM.pdf` — CP/M 2.x reference and operating manuals
- `cpkerm.pdf` — Kermit communications software documentation for CP/M

**Source Code Archives:**
- `cpm20src.zip` — CP/M 2.0 source (ASM, DDT, ED, PIP, STAT, XSUB, boot, CCP, BDOS modules in assembly and PL/M)
- `cpm2-asm.zip`, `cpm2-plm.zip` — CP/M 2.0 assembler and PL/M source (likely extracted from `cpm20src.zip`)
- `cpm22pat.zip` + `cpm22pat (1).zip` — CP/M 2.2 patches; the two files appear to be duplicates
- `cpm22-b.zip` — CP/M 2.2 binary distribution
- `cpm3bin.zip` + Unix variant — CP/M 3 binary distributions
- `CPMRef.zip` — CP/M reference materials (also present in `software/`)
- `kermit.zip` — Kermit-80 communications software
- `learn.zip` — CP/M learning materials

**`cpmish/` Subfolder:**
Modern open-source CP/M 2.2 clone (no Digital Research code); uses ZSDOS, ZCPR1, open-source BIOSes. Includes build system (Lua/Makefile), architecture-specific BIOSes for Kaypro II, Amstrad NC200, and Brother typewriters, plus standard CP/M utilities.

---

## `datasheets/` — Component Datasheets

| File(s) | Component |
|---------|-----------|
| `MK3880.pdf` | Z80 CPU |
| `FD179X-02_Data_Sheet_May1980.pdf` | Floppy disk controller (WD179x) |
| `WD1002-05-Winchester_HD-controller-manual_Jul83.pdf`, `WD1943.pdf` | Winchester/hard disk controllers |
| `TEAC-FD235HF-A291--booleans.pdf` | TEAC floppy drive |
| `MM58167.pdf` | Real-time clock IC |
| `Mitsubishi_M5L8049-XXXP-6.pdf` | Microcontroller |
| `MC75451.pdf`, `SN7406.pdf`, `TMS99532A.pdf` | Logic/digital ICs |
| `6116.pdf` (in `memory/`) | 6116 SRAM |
| `c6545.zip`, `MC6845.zip`, `r6545.zip`, `mos_6545-1_crtc.pdf`, `sy6545.pdf` + variants (in `CRT Controller/`) | MOS/Motorola 6545 / MC6845 CRT controller — multiple formats covering the same device |
| `Electronics-Digest-1983-Autumn.pdf` | Autumn 1983 electronics industry publication |

---

## `manuals/` — Kaypro Technical & User Manuals

**Kaypro Technical Manual series** (four progressive revisions of the same document):
- `1484-C` (Aug 1984), `1484-D` (Dec 1984), `1484-E` (Jun 1985, Ch. 1–15), `1484-F` (Sep 1985, Ch. 19–29)

**Other manuals:**
- `kaypro_general.pdf` — Comprehensive general Kaypro documentation
- `Kaypro_II_Dealer_Reference_Manual_1982.pdf` — 1982 Kaypro II dealer reference
- `Kaypro_Disk_Drive_Diagnostic_Users_Guide_1983.pdf` — 1983 disk drive diagnostics
- `Kaypro_Hardware_Upgrades_text.pdf` — Hardware upgrade guide
- `Kaypro_Software_Bulletin_Jul83.pdf` — July 1983 software bulletin
- `Omni-4-User-Manual.pdf` — Kaypro Omni-4 user manual
- `5620701505058721359.pdf` — Additional technical documentation (origin unclear)

---

## `schematics/`

- `Kaypro_II_schematics.pdf` — Kaypro II circuit schematics
- `KayproSchematic.pdf` — General Kaypro circuit schematics (also present in `virtual-kaypro/`)

---

## `software/`

**ROM source (`source/`):**
- `crdmp.z80` — Z80 assembly source
- `bios.mac` — BIOS assembly source
- `k10rom7a/` — Kaypro 10 ROM source code
- `z80-asm.5` — Z80 assembler reference

**TurboROM distribution** — ROM enhancement for Kaypro 84-series. Present in three locations that appear to be duplicates/extracts of the same archive:
- `trmsuppt/` — TurboROM 3.4 support files (utilities, config tools, library archives)
- `trom-doc/` — Same distribution with added `TROM.DOC` (187 KB manual) and `K10FMT.COM`
- `TurboRom_Kaypro_4/TurboRom_3_4/` — Another copy

**ProMulti 884 ROM (`pro884mx/`):**
ROM enhancement for Kaypro 88xx systems. Z80 assembler bootloader (`AUTOLOAD.Z80`), Pascal configuration utilities (`MCONFIG.PAS`, `FASTTEST.PAS`), ZCPR/BIOS config files.

**`brokezips/`** — Broken/incomplete archive files that correspond to the extracted folders above:
`k10rom7a.zip`, `pro884mx.zip`, `trmsuppt.zip`, `trom-doc.zip`, `TurboRom_Kaypro_4.zip`

**Disk images (`disk-images/`):**
- `k4f-292.td0` + `k4f-292.zip` — Kaypro 4 Teledisk floppy image (zip is the compressed version)
- `22src1.img`, `22src2.img` + `22srcimg.zip` — CP/M 2.2 source disk images (zip is the compressed version)
- `KayPlus-Boot.imd` + `kayplusboot.img` — KayPlus bootable disk (two formats of the same content)

**ROM dumps (`rom/`):**
- `boot/` and `character/` — ROM image subdirectories
- `rom.txt` — ROM documentation with embedded system message strings

**Software collections (zip archives):**
- `kaypro10.zip` (15 `.imd` disk images), `kaypro83.zip`, `kayproii.zip` / `KAYPROII.ZIP` (two copies), `kaypro1.zip`, `KAYPRO2X.ZIP` — Software archives by Kaypro model
- `KAYMISC.ZIP` — Miscellaneous utilities (MBASIC, MODEM712, PIP, format tools, etc.)
- `STDCPM22.ZIP` — Standard CP/M 2.2 distribution (ASM, BIOS variants, DDT, ED, PIP, STAT, etc.)
- `CPMRef.zip` — CP/M reference (also in `cpm/`)
- `kiibios.zip` — Kaypro II BIOS variant
- `urmtkit1.zip`, `urmtkit2.zip`, `urmtkit3.zip` — Upgrade/ROM toolkit archives
- `Gotek_-_Kaypro_10_4461262.zip` — Gotek USB floppy emulator configuration for Kaypro 10

**Diagnostics:**
- `kp4diag.zip` — Kaypro 4 diagnostics (DIAG executable)
- `kpdiag1.zip` — Kaypro diagnostics v1 (`DIAG1.MAC` source + compiled binaries)
- `kpgetrom.zip` — ROM extraction utility

**Other:**
- `84KP256A.ARK` — Older-format archive file

---

## `theory/` — Technical Theory

- `kaypro_operation.txt` + `KayproOperation-ocr.pdf` — Kaypro operation theory (two formats of the same content)
- `kaypro.doc` — Kaypro operational documentation (binary .doc format)
- `KP-CBOOT.DOC` — Kaypro cold-boot documentation
- `kaypro-serial-info.doc` — Serial port specifications
- `kaypro_tm.pdf` — Kaypro trademark/certification documentation
- `6545-english.txt` — MOS 6545 CRT controller technical info (translated from another language)
- `floppy.pdf` — Floppy disk technology theory
- `AN917_Reading_and_Writing_In_Floppy_Disk_Systems.pdf` — Floppy disk I/O technical document

---

## `virtual-kaypro/` — Java Kaypro Emulator

**Emulator application:**
- `VirtualKaypro.jar` — Java-based emulator supporting Kaypro II, 4, 10, and variants
- Build system (Makefile, scripts), LICENSE

**Configurations (`configs/`):**
Model-specific config files for: kaypro II, IV, 84, 2X, 10, 10e, 10eu, and CP/NET variants.

**Disk images (`disk/`):**
50+ pre-built disk images in `.logdisk` (emulator format) and `.imd` (ImageDisk) formats:
- CP/M 2.2 and CP/M 3 bootable system disks
- Application disks: WordStar 3.3, Perfect Writer, Perfect Calc, dBASE II (lessons + system), Microplan, Datastar/Infostar/Reportstar/Calcstar, MS BASIC, C-BASIC, S-BASIC, Kermit-80, Magic Wand word processor
- CP/NET distributions and utilities
- Kaypro 10 Winchester autoload disks (8 disks covering the full software suite)
- Winchester hard disk images (11 MB each): blank templates, and pre-installed CP/M 2.2, CP/M 3, CP/NET 3
- Blank floppy templates
- `disk/index.txt` — Catalog of all disk images with descriptions
- `kaypro10.zip` — Kaypro 10 software package (also present in `software/`)

**Archives:**
- `cpnet12kp.tgz`, `cpnet12.tgz`, `cpnet3kp.tgz` — CP/NET archives
- `diablo630.tgz` — Diablo 630 printer emulation
- `k10u-rld-h.tgz` — Kaypro 10 reload kit
- `kbd-map.tgz` — Keyboard mapping
- `vkaypro.tgz` — Full Virtual Kaypro distribution
- `z80cpu.tgz` — Z80 CPU emulation module

**Documentation (duplicates from other folders):**
- `KayproAddendum.pdf`, `KayproOperation.pdf`, `KayproSchematic.pdf`

---

## `web/` — Archived Web Content

**Archived articles/blog posts:**
- `Tech Flashback: Reviving the Kaypro 4 | Gough's Tech Zone.html` + `_files/` (100+ images, CSS, JS) — Detailed hardware restoration blog post with 40+ photographs
- `DAVES OLD COMPUTERS- Kaypro.htm` + `_files/` (30+ JPGs, CSS) — Photo gallery of Kaypro II and Kaypro 4 hardware
- `The Kaypro II Extreme.html` + `_files/` (7 JPGs) — Article on Kaypro II configurations
- `dd9-kaypro-edition.html` — Deep Dive #9 technical discussion
- `exploring-kaypro-video-performance.html` — Video performance analysis
- `kaypro-graphics.html` — Graphics capabilities and techniques
- `teaching-the-kaypro-to-draw.html` — Graphics programming tutorial
- `porting-cpm-to-a-new-computer.html` — CP/M porting guide
- `kaypro-and-cpm-discussion.html` — Newsgroup discussion archive

**Kaypro keyboard USB conversion project:**
A small project for converting the Kaypro keyboard to USB by reverse-engineering its serial protocol.
- `README.md`, `kaypro_technical.md`, `usb_conversion_notes.md` — Project documentation
- `kaypro_interface_schematic.jpg`, `KayproKeyboard.JPG` — Hardware reference images
- `images/` — Supporting images

---

## `images/` — Personal Hardware Photographs

- `kaypro_images/` — Photos organized by subject: BIOS POST screens (5), internal components (7), keyboard (2), Knoppix bootup sequence (4), Kaypro running Linux/Knoppix (15)
- `my-pics/` — 7 personal photos dated January 2019 (`IMG_20190121_*.jpg`)

---

## Notable Duplicates / Cross-Folder Redundancy

| Item | Locations |
|------|-----------|
| TurboROM 3.4 distribution | `software/trmsuppt/`, `software/trom-doc/`, `software/TurboRom_Kaypro_4/TurboRom_3_4/`, and the corresponding broken zips in `software/brokezips/` |
| Kaypro schematics | `schematics/KayproSchematic.pdf` and `virtual-kaypro/KayproSchematic.pdf` |
| Kaypro operation documentation | `theory/kaypro_operation.txt` + `theory/KayproOperation-ocr.pdf` (same content, two formats); also `virtual-kaypro/KayproOperation.pdf` |
| `kaypro10.zip` | `software/` and `virtual-kaypro/` |
| `CPMRef.zip` | `cpm/` and `software/` |
| `KAYPROII.ZIP` / `kayproii.zip` | Two copies in `software/` |
| `cpm22pat.zip` / `cpm22pat (1).zip` | Two copies in `cpm/` |
| Kaypro 4 Teledisk image | `software/disk-images/k4f-292.td0` (raw) + `k4f-292.zip` (compressed) |
| CP/M 2.2 source disk images | `software/disk-images/22src1.img` + `22src2.img` (raw) + `22srcimg.zip` (compressed) |
| KayPlus boot disk | `software/disk-images/KayPlus-Boot.imd` and `kayplusboot.img` |
| TurboROM and ROM source archives | Extracted folders in `software/` correspond to broken zips in `software/brokezips/` |