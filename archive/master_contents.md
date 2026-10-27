# Kaypro Collection — Master Contents

Compiled from `kaypro/` and `kaypro_related/`. Location codes: **[K]** = `kaypro/`, **[R]** = `kaypro_related/`.

---

## Provenance & Caveats

Most material in this collection was found online, but the older files — especially CP/M software — have likely passed through many hands and platforms over several decades. A plausible chain for a file from the early 1980s might look like:

> Kaypro user uploads to BBS (1984) → downloaded to Amiga or DOS PC → copied to floppy → read years later on a mid-90s Mac → posted to a newsgroup or FTP site → downloaded on Windows 95 → eventually uploaded to the web

Each transfer introduced opportunities for encoding/decoding errors, format conversions, or data loss. The following should be kept in mind when working with these files:

### Encoding artifacts
- BBS file transfers commonly used XMODEM, YMODEM, or ZMODEM protocols, which could introduce errors or padding, especially if sessions were interrupted and resumed.
- Text files distributed via newsgroups were often UUencoded or Base64-encoded; repeated encode/decode cycles could corrupt binary content or introduce line-ending inconsistencies.
- Some files may still be in an encoded wrapper (UUencoded, BinHex, etc.) that was never decoded.
- CP/M text files use CR+LF or CR-only line endings; these may have been mangled by platform-specific newline conversions at various points.

### Archaic and obscure archive formats
Several formats in this collection predate ZIP and may require uncommon tools to open:
| Extension | Format | Era / Origin |
|-----------|--------|--------------|
| `.ARK` | ARC archive (SEA/PKWARE precursor) | Mid-1980s, common on CP/M and early DOS BBS systems |
| `.LBR` | CP/M library format | CP/M era; a flat container format, not compressed |
| `.WZ` | Squeeze/Crunch compressed file | CP/M era |
| `.TZT` | Possibly a text-squeezed archive | CP/M era |
| `.td0` | Teledisk floppy image | Early 1990s; proprietary format, tool required |
| `.imd` | ImageDisk floppy image | Dave Dunfield's format, widely used for preservation |
| `.HFE` | HxC floppy emulator format | Modern preservation format |
| `.logdisk` | Virtual Kaypro emulator format | Specific to VirtualKaypro.jar |
| `.tgz` / `.tar.gz` | Unix compressed tar | Common but may have been created on systems with different tar variants |

### Platform-specific artifacts
- **Amiga `.info` files**: Several archives have Amiga OS icon sidecar files, confirming at least one leg of the journey went through an Amiga. The associated `.info`-bearing files likely originated as BBS downloads in the late 1980s or early 1990s.
- **All-caps filenames**: CP/M and early BBS conventions used uppercase-only 8.3 filenames. Files with all-caps names were probably never renamed after leaving a CP/M or DOS system.
- **Mixed line endings**: Files that have passed through CP/M, Unix, Mac OS 9, and Windows systems may have inconsistent or garbled line endings.
- Some binaries may be Z80 `.COM` files that will only run under CP/M or an emulator — they are not x86 executables.

### Data integrity
Given the number of platform transitions, some files in this collection may be silently corrupt — particularly older binary archives and disk images. Checksums or test-extracting archives before relying on their contents is advisable.

---

## 1. Kaypro Hardware Documentation

### Technical Manuals (official Kaypro series)
- **Kaypro Technical Manual 1484-C** (Aug 1984) **[K]** `manuals/`
- **Kaypro Technical Manual 1484-D** (Dec 1984) **[K]** `manuals/`
- **Kaypro Technical Manual 1484-E** (Jun 1985, Ch. 1–15) **[K]** `manuals/`
- **Kaypro Technical Manual 1484-F** (Sep 1985, Ch. 19–29) **[K]** `manuals/`
- **Kaypro 4 Technical Manual** (OCR'd, high-res scans, 477 MB) **[R]** `kaypro4/tech manual/`

### User & Reference Manuals
- **Kaypro II Dealer Reference Manual** (1982) **[K]** `manuals/`
- **Kaypro general documentation** (comprehensive) **[K]** `manuals/kaypro_general.pdf`
- **Kaypro Omni-4 User Manual** **[K]** `manuals/`
- **Kaypro user guide** (`kuser.pdf`) **[R]**
- **Kaypro specifications** (`kayprospec.pdf`) **[R]**
- **Kaypro addendum** (`KayproAddendum.pdf`) **[K]** `virtual-kaypro/` **[R]**
- **Kaypro prototype documentation** (`kproto.pdf`) **[R]**
- **Kaypro ROM version reference** (`Kaypro-ROM-Versions.pdf`) **[R]**
- **Kaypro Software Bulletin** (Jul 1983) **[K]** `manuals/` **[R]**
- **Kaypro Hardware Upgrades guide** **[K]** `manuals/` **[R]**
- **Kaypro Disk Drive Diagnostic Users Guide** (1983) **[K]** `manuals/` **[R]**
- **`5620701505058721359.pdf`** — additional technical documentation, origin unclear **[K]** `manuals/`

### Schematics
- **Kaypro II schematics** **[K]** `schematics/`
- **Kaypro circuit schematics** (`KayproSchematic.pdf`) **[K]** `schematics/`, `virtual-kaypro/` **[R]**

### Operations & Theory
- **Kaypro operations manual** (`KayproOperation.pdf` / `kaypro_operation.txt` / `KayproOperation-ocr.pdf`) **[K]** `theory/`, `virtual-kaypro/` **[R]**
- **Kaypro cold-boot documentation** (`KP-CBOOT.DOC`) **[K]** `theory/` **[R]** (also as `.txt`, `.md`, `.odt`)
- **Kaypro serial port specifications** (`kaypro-serial-info.doc`) **[K]** `theory/`
- **Kaypro operational notes** (`kaypro.doc`) **[K]** `theory/` **[R]**
- **Kaypro trademark/certification documentation** (`kaypro_tm.pdf`) **[K]** `theory/`
- **Kaypro keyboard specifications** (cable pinouts, 76-key, 4-wire serial) **[K]** `kaypro_keyboard.txt`
- **Kaypro CP/M version matrix** (model vs. mainboard vs. ROM) **[K]** `KP-VERSN.TXT`
- **Kaypro maintenance guide** (reliability, common failures, repair) **[K]** `KAYMAINT.TXT`
- **Kaypro repair manual** (scanned PDF, 32 MB) **[R]** `kaypro-repair.zip`
- ***Chilton's Guide to Kaypro Repair and Maintenance*** by Gene B. Williams (221 pp, 34 MB) **[R]** `kaypro150dpigrayscale.pdf` — troubleshooting, board/drive/keyboard/monitor repair, add-ons, includes Kaypro 16; scanned from San Jose State University library copy
- **Kaypro 84 Theory of Operation** © 1984 Micro Cornucopia, by Eric Roby (13 pp) — plain-English hardware walkthrough of CPU, video, I/O sections with block diagrams **[R]** `KayproOperation.pdf` (2011); `1984_Kaypro_II-4_84_Theory-of-Operation.pdf` (FineReader OCR 2022, searchable — preferred)
- **Micro Cornucopia Kaypro 84 Schematic** (1-page fold-out, 2560×1722 pt) **[R]** `1984_Kaypro_II-4_84_Theory-of-Operation_Schematic.pdf` — companion to Theory of Operation; distinct from the official Kaypro Corp `KayproSchematic.pdf`
- **KayPlus ROM manual** (`kayplus.pdf`) **[R]**
- **Hardware notes** (`hardware_README`) **[R]**

---

## 2. CP/M Operating System

### Documentation
- **CP/M 2.0 System Alteration Guide** (Digital Research official) **[K]** `cpm/` (PDF + OCR variant) **[R]** (`CPM_2.2_Alteration_Guide_1979.pdf`)
- **CP/M 2.0 Interface Guide** **[R]**
- **CP/M 2.2 manual** (`cpm22-m.pdf`) **[K]** `cpm/` **[R]**
- **CP/M operating manual** **[K]** `cpm/`
- **CP/M bootstrap procedures** (`cpm_bootstrap.pdf` + RTF) **[K]** `cpm/`
- **SC-CPM documentation** **[K]** `cpm/`
- **CP/M reference materials** (`CPMRef.zip`) **[K]** `cpm/`, `software/`
- **CP/M filesystem documentation** (`cpmfsinfo.html`, `cpmfs.html`, `cpmf.html`) **[R]**
- **Kermit for CP/M documentation** (`cpkerm.pdf`) **[K]** `cpm/`
- **DRI CP/Net manual** (`dri-cpnet.pdf`) **[R]**
- **CP/M porting guide** **[K]** `web/porting-cpm-to-a-new-computer.html` **[R]** `portingcpm.html`

### Source Code
- **CP/M 2.0 source** (`cpm20src.zip`) — ASM, DDT, ED, PIP, STAT, XSUB, boot, CCP, BDOS in assembly and PL/M **[K]** `cpm/`
- **CP/M 2.0 assembler source** (`cpm2-asm.zip`) — likely extracted from above **[K]** `cpm/`
- **CP/M 2.0 PL/M source** (`cpm2-plm.zip`) — likely extracted from above **[K]** `cpm/`
- **CP/M 80 distribution** (`cpm80.tar.gz` / `cpm80.zip`) **[R]**

### Binary Distributions
- **CP/M 2.2 binary distribution** (`cpm22-b.zip`) **[K]** `cpm/` **[R]**
- **CP/M 2.2 reduced/minimal** (`cpm22red.zip`) **[R]**
- **CP/M 2 base system** (`cpm2.zip`) **[R]**
- **CP/M 3 binary distributions** (`cpm3bin.zip` + Unix variant) **[K]** `cpm/`
- **Standard CP/M 2.2 distribution** (`STDCPM22.ZIP`) — ASM, BIOS variants, DDT, ED, PIP, STAT, etc. **[K]** `software/` **[R]**
- **Digital Research package** (`DRIPAK.ZIP`) — full DRI OS package **[R]**

### Patches
- **CP/M 2.2 patches** (`cpm22pat.zip`) **[K]** `cpm/` **[R]**

### Open-Source Clone
- **cpmish** — CP/M 2.2 clone using ZSDOS, ZCPR1, open-source BIOSes; build system (Lua/Makefile); architecture BIOSes for Kaypro II, Amstrad NC200, Brother typewriters **[K]** `cpm/cpmish/`

### Miscellaneous
- **CP/M TeX package** (`cpmtex.zip`) **[R]**
- **CP/M learning materials** (`learn.zip`) **[K]** `cpm/` **[R]**
- **Kermit-80 communications software** (`kermit.zip`) **[K]** `cpm/` **[R]**
- **Kermit for 68000 systems** (`kermit68.zip`) **[R]**

---

## 3. Component Datasheets

### CPU
- **Z80 CPU** (`MK3880.pdf`) **[K]** `datasheets/`
- **Zilog Z80 CPU documentation** (two volumes: `um0080.pdf`, `um0081.pdf`) **[R]**
- **Z80 interrupt system** (`z80-interrupts.pdf`) **[R]**
- **Z80 CPU chapter excerpt** (`Chapter 3 Z80.pdf`) **[R]**

### Floppy & Disk Controllers
- **WD179x floppy disk controller** (`FD179X-02_Data_Sheet_May1980.pdf`) **[K]** `datasheets/`
- **TEAC FD235HF floppy drive** **[K]** `datasheets/`
- **WD1002-05 Winchester HD controller manual** (Jul 1983) **[K]** `datasheets/` **[R]** (`61-031050-0030_...`)
- **WD1002 HD controller manual** (Aug 1984 variant) **[R]**
- **WD1943 hard disk controller** **[K]** `datasheets/`
- **Hard disk reference manual** (`39402-0_706-712_Hard_Disk_Reference_Manual_1984.pdf`) **[R]**

### CRT Controller
- **MOS/Motorola 6545 / MC6845 CRTC** — multiple formats: `c6545.zip`, `MC6845.zip`, `r6545.zip`, `mos_6545-1_crtc.pdf`, `sy6545.pdf` + variants **[K]** `datasheets/CRT Controller/`
- **6545 CRT controller technical info** (translated) **[K]** `theory/6545-english.txt`
- **CRTC compendium v1.6** (2023, modern reference) **[R]**
- **21C_TOCR29 CRTC chip reference** **[R]**
- **CRTC chip diagram** (`V56pR.jpg`) **[R]**

### Memory
- **6116 SRAM** **[K]** `datasheets/memory/`
- **2764 EPROM** (`27C64.pdf` / `2764_EPROM.pdf`) **[R]**
- **Timekeeper NRAM** (`m48t08.pdf`) **[R]**
- **Introduction to NAND Flash** **[R]**

### Other ICs
- **Mitsubishi M5L8049 microcontroller** **[K]** `datasheets/`
- **MM58167 real-time clock** **[K]** `datasheets/`
- **MC75451, SN7406, TMS99532A** — logic/digital ICs **[K]** `datasheets/`
- **74HC595 shift register** (`sn74hc595.pdf`) **[R]**
- **74LS14 Schmitt trigger** (`sn74ls14.pdf`) **[R]**
- **74HC/HCT245, 74HC/HCT125** — logic ICs **[R]**
- **SC16IS740/750/760 serial UART** **[R]**
- **LM7812 voltage regulator** **[R]**
- **5666/5668 IC datasheets** **[R]**
- **Micro-C-ROMs ROM IC reference** **[R]**

### Serial / Connectivity
- **RS-232 signal reference** (`DTR-DSR-RTS-CTS_Difference.pdf`) **[R]**
- **ESP8266 AT command set** **[R]**

---

## 4. Kaypro Software

### ROM Enhancements
- **TurboROM 3.4** — ROM enhancement for Kaypro 84-series; utilities, config tools, `TROM.DOC` manual **[K]** `software/trmsuppt/`, `software/trom-doc/`, `software/TurboRom_Kaypro_4/` **[R]** `trmsuppt.zip`, `trom-doc.zip`/`TROM-DOC.ZIP`, `TurboRom_Kaypro_4.zip`, `turborom.zip`, `turbo.bin`
- **ProMulti 884 ROM** — ROM enhancement for Kaypro 88xx; Z80 bootloader, Pascal config utilities **[K]** `software/pro884mx/`
- **KayPlus** — ROM enhancement package (`kayplus.zip`, `KayPlus-Boot.imd`) **[K]** `software/disk-images/` **[R]**
- **Upgrade/ROM toolkit** (`urmtkit1-3.zip`) **[K]** `software/` **[R]**
- **Kaypro 10 ROM source** (`k10rom7a/`) **[K]** `software/source/`

### ROM Dumps
- **Boot ROMs and character ROMs** **[K]** `software/rom/boot/`, `software/rom/character/`
- **ROM documentation** (`rom.txt`) **[K]** `software/rom/`
- **TurboROM binary** (`turbo.bin`) **[R]**
- **81-146a firmware binary** **[R]**

### Disk Images — Kaypro System Disks
- **Kaypro 4 Teledisk image** (`k4f-292.td0`) **[K]** `software/disk-images/`
- **Kaypro 4 HFE image** (`Kaypro-4-DS-HFE.zip`) **[R]**
- **CP/M 2.2 source disk images** (`22src1.img`, `22src2.img`) **[K]** `software/disk-images/`
- **KayPlus boot disk** (`KayPlus-Boot.imd` / `kayplusboot.img`) **[K]** `software/disk-images/`
- **k4-games.td0** — Kaypro 4 games disk **[R]**
- **kp22gdsd.td0** — CP/M 2.2 GDS disk **[R]**
- **kpmex114.td0** — Mex communications software disk **[R]**
- **kp-trom.td0** — TROM floppy **[R]**
- **Boot disk images** (`bootimd.zip`) **[R]**
- **Kaypro 4 floppy image collection** (184 files, various formats) **[R]** `kaypro4/floppy images/`

### Disk Images — Virtual Kaypro (emulator-ready)
50+ pre-built `.logdisk` and `.imd` images:
- CP/M 2.2 and CP/M 3 bootable system disks
- CP/NET distributions and utilities
- Application disks: WordStar 3.3, Perfect Writer, Perfect Calc, dBASE II, Microplan, Datastar/Infostar/Reportstar/Calcstar, MS BASIC, C-BASIC, S-BASIC, Kermit-80, Magic Wand, Automite/Mite
- Kaypro 10 Winchester autoload disks (8 disks, full software suite)
- Winchester hard disk images (11 MB): blank templates, CP/M 2.2, CP/M 3, CP/NET 3 installs
- Blank floppy templates
- `disk/index.txt` — catalog with descriptions

**[K]** `virtual-kaypro/disk/` **[R]** `kaypro4/virtual-kaypro/`

### Software Collections by Model
- **Kaypro 1** (`kaypro1.zip`) **[K]** `software/`
- **Kaypro II** (`kayproii.zip` / `KAYPROII.ZIP`) **[K]** `software/` **[R]**
- **Kaypro 2X** (`KAYPRO2X.ZIP`) **[K]** `software/` **[R]**
- **Kaypro 4** (`kaypro4.zip`) **[R]**
- **Kaypro 10** (`kaypro10.zip`, 15 `.imd` disk images) **[K]** `software/`, `virtual-kaypro/`
- **Kaypro 1983 era** (`kaypro83.zip`) **[K]** `software/`
- **Kaypro miscellaneous utilities** (`KAYMISC.ZIP`) — MBASIC, MODEM712, PIP, format tools **[K]** `software/`
- **Kaypro main archive** (`Kaypro.zip`, 27 MB) — ROMs, BIOS, disk images **[R]**
- **Compupro archive** (`COMPUPRO.ZIP`) **[R]**

### Utilities & Tools
- **Kermit-80** **[K]** `cpm/`, `virtual-kaypro/` **[R]**
- **Mite terminal** (`kp-mite.zip`) **[R]**
- **PC-to-CP/M serial transfer** (`PCGET.ASM`, `PCPUT.ASM`) **[R]**
- **Module loader** (`mload.com`) **[R]**
- **VT100 emulator** (`VT100KAY.LBR`) **[R]**
- **Video utility** (`KPVID.LBR`) **[R]**
- **Character translation** (`XLATE5.LBR`) **[R]**
- **RAM disk utility** (`KRAMDISK.TZT`) **[R]**
- **RAM disk system master** (torrent metadata) **[R]**
- **Networking utilities** (`web-lan.zip`) **[R]**
- **Grep for CP/M** (`wgrep.zip`) **[R]**
- **MAC utilities** (`mac-b.zip`) **[R]**
- **Communication software** (`kcom-bcn.zip`) **[R]**
- **CP/M BIOS source** (`kp-bios.zip`) **[R]**
- **BIOS assembly source** (`bios.mac`) **[K]** `software/source/`
- **Z80 assembly source** (`crdmp.z80`) **[K]** `software/source/`
- **Autoboot configuration** (`AUTOBOOT.WZ`) **[K]**

### Diagnostics
- **Kaypro 4 diagnostics** (`kp4diag.zip`) **[K]** `software/` **[R]**
- **Kaypro diagnostics v1** (`kpdiag1.zip`, `DIAG1.MAC` source + binaries) **[K]** `software/` **[R]**
- **ROM extraction utility** (`kpgetrom.zip`) **[K]** `software/`
- **84KP256A archive** (older format) **[K]** `software/`

### Games
- **Kaypro games collection** (`kpgames.zip`) **[R]**
- **Zork I** (`zork1.zip`) **[R]**
- **Games disk image** (`k4-games.td0`) **[R]**

### CP/NET
- **CP/NET distributions** (`cpnet12kp.tgz`, `cpnet12.tgz`, `cpnet3kp.tgz`, `cpnet-dist.logdisk`, etc.) **[K]** `virtual-kaypro/`
- **Kaypro 10 reload kit** (`k10u-rld-h.tgz`) **[K]** `virtual-kaypro/`

---

## 5. Z80 Development Tools

### Assemblers
- **z80-asm 2.4.1** — full source distribution **[R]** `z80/z80-asm-2.4.1/`
- **z80-asm current** (`z80-asm-current.tar.gz`) — likely same as or newer than above **[R]** `z80/`
- **z80-asm man page** (`z80-asm.5`) **[K]** `software/source/` **[R]**
- **asm80** (`asm80.zip`) **[R]** `z80/`
- **Microsoft M80 Assembler manual** **[R]**
- **Microsoft MAC assembler reference** (`mac.pdf`) **[R]**
- **Z80 programming tools** (`z80prog.zip`) **[R]**

### Disassemblers / Debuggers
- **Dazzlestar** — Z80 disassembler (Git repo with full source) **[R]** `z80/dazzlestar/`
- **myz80** (`myz80.zip`) — Z80 tools **[R]** `z80/`

### Reference
- **Z80-081707** (`Z80-081707.zip`) — Z80 tools/documentation **[R]**
- **ZRT80 system archive** (`zrt80.tar`) **[R]**
- **KC85 Z80 signal recordings** (`z80_kc85_*.sr`) **[R]**
- **Z80 documentation** (`z80/` PDFs: "How to Program the Z80", Zilog manuals) **[R]** `z80/`

---

## 6. Floppy & Disk Emulators

### HxC Floppy Emulator
- Software distribution (`HxCFloppyEmulator_soft.zip` + extracted `HxCFloppyEmulator_soft/`) **[R]**

### FlashFloppy
- Firmware source (`flashfloppy-3.39.zip` + extracted `flashfloppy-3.39/`) **[R]**
- Disk images (`FF_Images.zip`) **[R]**

### Gotek
- Kaypro 10 Gotek configuration (`Gotek_-_Kaypro_10_4461262.zip`) **[K]** `software/`

### FreHD
- Hard disk emulator for TRS-80/Z80 systems (`FreHD_2.14.zip`) **[R]**

### Virtual Kaypro (Java emulator)
- `VirtualKaypro.jar` — Java emulator supporting Kaypro II, 4, 10, variants
- Model configs for: kaypro II, IV, 84, 2X, 10, 10e, 10eu, CP/NET variants
- 50+ disk images (see §4 above)
- Build system, LICENSE
- `vkaypro.tgz` — full distribution archive
- `z80cpu.tgz` — Z80 CPU emulation module
- `diablo630.tgz` — Diablo 630 printer emulation
- `kbd-map.tgz` — keyboard mapping

**[K]** `virtual-kaypro/` **[R]** `kaypro4/virtual-kaypro/`

### Disk Image Format Tools
- **ImageDisk v1.18** (`imd118.zip`) **[R]**
- **Java disk formatting utility** (`format.jar`) **[R]**
- **CP/T tools** (`cpt.zip`) **[R]**

---

## 7. CP/M Disk Tools

### cpmtools
- Source distribution v2.23 (`cpmtools-2.23.tar.gz` + extracted `cpmtools-2.23/`) — Unix toolkit for reading/writing CP/M disk images **[R]**

### Disk-Utilities
- Open-source disk image toolkit (C source) for reading, writing, converting formats **[R]** `kaypro4/Disk-Utilities/`

---

## 8. Floppy Disk Theory & Reference
- **Floppy disk technology theory** (`floppy.pdf`) **[K]** `theory/` **[R]**
- **AN917: Reading and Writing in Floppy Disk Systems** **[K]** `theory/`

---

## 9. Web & Community Archives

### Restoration & Technical Blogs
- **Tech Flashback: Reviving the Kaypro 4** (Gough's Tech Zone) — restoration blog post with 40+ photos **[K]** `web/`
- **Dave's Old Computers: Kaypro** — photo gallery of Kaypro II and 4 hardware **[K]** `web/`
- **The Kaypro II Extreme** — article on Kaypro II configurations **[K]** `web/`
- **Deep Dive #9: Kaypro Edition** — technical discussion **[K]** `web/`
- **Exploring Kaypro video performance** **[K]** `web/`
- **Kaypro graphics capabilities** **[K]** `web/`
- **Teaching the Kaypro to draw** — graphics programming tutorial **[K]** `web/`

### Forums & Discussions
- **Kaypro and CP/M newsgroup discussion** **[K]** `web/`
- **Forum thread: strange disk problem / custom BIOS for hard disk** **[R]**
- **Forum archive** (67 HTML pages, Kaypro hardware/software) **[R]** `kaypro4/forum/`
- **Vintage Computer Federation (VCF) forum archive** (Kaypro/CP/M threads) **[R]** `kaypro4/www.vcfed.org/`

### Site Mirrors
- **sebhc.durgadas.com** — Kaypro/S-100 hardware community site (two snapshots: current + `_old/`) **[R]** `kaypro4/workdir/`
- **kayprojournal.com** — MediaWiki community knowledge base (76 content pages + image file pages). Topics: model identification, serial numbers, production numbers, hardware variants, RAM disks, hard drives, peripherals, software bundles, company history (interviews with Allan Kay, Marshall Mosley), Kaypro decline, warehouse/sales/distribution, keyboard models, ROMs, manuals index. **[R]** `mirrors/kayprojournal.com/` — raw mirror at `kayprojournal.com/index.php/`; clean readable HTML at `clean/` (open `clean/index.html`)
- **retrocmp.de/kaypro** — Comprehensive German retrocomputing reference, Kaypro section (25 numbered parts + index). Topics: CP/M version matrix, hardware overview, 4K→8K EPROM mod, hard disk formatting, user guide, terminal emulation, KayPLUS ROM, TurboROM, Multicopy, Kay family history, newspaper articles, design history, Micro Cornucopia index, Kaypro II repair, collections, FAQ, Virtual Kaypro, floppy formatting, ROM/EPROM guide, Kaycomp, MFM emulator, Road Runner. Last updated 2024/2025. **[R]** `mirrors/retrocmp.de/retrocmp.de/kaypro/` (open `index.htm`; pages are `kay-p0_info.htm` through `kay-p25_kaycomp.htm`)

### Other Web Content
- **Retro computing documentation** (`Jz0qcG2G.html`) **[R]**
- **Z80 Support documentation with assets** **[R]** `kaypro4/Z80 Support_files/`

---

## 10. Publications

### Micro Cornucopia Magazine
- **Issue #24** (Jun 1985, PDF, 10 MB) **[R]**
- **Full archive through Jun 1986** (12 MB, SQLite + XML metadata, Internet Archive download) **[R]** `bitsavers_microCornua30Jun86_11542571/`
- **Issue #30** (Jun 1986) **[R]** (likely within above archive)

### Electronics Digest
- **Autumn 1983** issue **[K]** `datasheets/`

---

## 11. Photographs

### Personal Hardware Photos
- **January 2019** (7 JPGs): general hardware **[K]** `images/my-pics/`
- **February 2022** (19 JPGs, 74 MB, high-res): keyboard hardware detail **[R]** `keyboard/`

### System Documentation Photos
- **BIOS POST screens** (5 JPGs) **[K]** `images/kaypro_images/bios post/`
- **Internal components** (7 JPGs) **[K]** `images/kaypro_images/inside/`
- **Keyboard** (2 JPGs) **[K]** `images/kaypro_images/keyboard/`
- **Kaypro running Linux/Knoppix** (15 JPGs + 4 bootup sequence) **[K]** `images/kaypro_images/`

### Web-Sourced Photos
- **Kaypro 4 restoration** (40+ high-res JPGs) **[K]** `web/Tech Flashback..._files/`
- **Kaypro II and 4 hardware gallery** (30+ JPGs) **[K]** `web/DAVES OLD COMPUTERS..._files/`
- **Kaypro II Extreme** (7 JPGs) **[K]** `web/The Kaypro II Extreme_files/`

---

## 12. Keyboard USB Conversion Project

A project to reverse-engineer the Kaypro keyboard's serial protocol and adapt it to USB.
- `README.md`, `kaypro_technical.md`, `usb_conversion_notes.md` — project documentation
- `kaypro_interface_schematic.jpg`, `KayproKeyboard.JPG` — hardware reference images
- `images/` — supporting images

**[K]** `web/` (keyboard conversion subfolder)

Personal notes on further hardware projects (PSU upgrade, modem replacement, FDD controller mods, RAM disk, USB keyboard): **[K]** `todo`

---

## 13. Other / Peripheral

### Terminal Documentation
- **ADM-3A terminal technical manual** (15 MB) **[R]**

### Programming Languages & Compilers
- **Turbo Pascal 3.0 Reference Manual** (1986, 11 MB) **[R]**
- **SDCC small device C compiler manual** (`sdccman.pdf`) **[R]**
- **PL/I language reference manual** (`pl1lrm.zip`) **[R]**
- **Programming language documentation** (`plipg.zip`) **[R]**
- **Documentation master archive** (`doc-master.zip`, 55 files incl. SDCC docs) **[R]**

### Fonts
- **Selectric Advocate, Scribe, Orator** — three IBM Selectric-style TrueType fonts **[R]**

### Miscellaneous
- **PDF 1.7 specification** (`PDF32000_2008.pdf`, 22 MB) **[R]**
- **Presentation materials** (`presentation.PDF`) **[R]**
- **Amiga OS `.info` sidecar files** — icon metadata accompanying several archives (`turbo.bin`, `turborom.zip`, `KAYPROII.ZIP`, `KAYPRO2X.ZIP`, `STDCPM22.ZIP`, `TROM-DOC.ZIP`, `COMPUPRO.ZIP`, `DRIPAK.ZIP`). Consistent with the material having been originally downloaded and archived from BBS systems or newsgroups in the 1980s–90s by an Amiga user — a common practice at the time. **[R]**

---

## 14. Duplicate Summary

### Exact duplicates (same file, multiple copies)
| Item | Copies |
|------|--------|
| TurboROM 3.4 distribution | 5+ copies across both folders |
| `cpm22pat.zip` | 3 copies |
| `KAYPROII.ZIP` / `kayproii.zip` | 3 copies |
| `cpm80.tar.gz` / `cpm80(1).tar.gz` | 2 copies |
| `cpm80.tar.gz` vs `cpm80.zip` | Same content, 2 formats |
| `TurboRom_Kaypro_4.zip` / `(1).zip` | 2 copies |
| `kermit.zip` / `(1).zip` | 2 copies |
| `web-lan.zip` / `(1).zip` | 2 copies |
| `kp22gdsd.td0` / `(1).td0` | 2 copies |
| `trom-doc.zip` / `TROM-DOC.ZIP` | 2 copies (case variant) |
| Virtual Kaypro emulator | `kaypro/virtual-kaypro/` and `kaypro_related/kaypro4/virtual-kaypro/` |
| sebhc.durgadas.com mirror | 2 snapshots in `kaypro4/workdir/` |
| Kaypro operations documentation | `.txt` + OCR PDF + PDF — 3 formats |
| KP-CBOOT documentation | `.DOC` + `.txt` + `.md` + `.odt` — 4 formats |
| 2764 EPROM datasheet | `27C64.pdf` and `2764_EPROM.pdf` |

### Archive + extracted directory pairs (in `kaypro_related/`)
| Archive | Extracted directory |
|---------|-------------------|
| `cpmtools-2.23.tar.gz` | `cpmtools-2.23/` |
| `flashfloppy-3.39.zip` | `flashfloppy-3.39/` |
| `HxCFloppyEmulator_soft.zip` | `HxCFloppyEmulator_soft/` |
| `k4f-292.zip` | `k4f-292.td0` |
| `22srcimg.zip` | `22src1.img`, `22src2.img` |
| Broken zips in `kaypro/software/brokezips/` | Extracted folders in `kaypro/software/` |

### Files in both `kaypro/` and `kaypro_related/`
`cpm22-b.zip`, `cpm22pat.zip`, `cpm22-m.pdf`, `kermit.zip`, `learn.zip`, `STDCPM22.ZIP`, `KAYPROII.ZIP`, `KAYPRO2X.ZIP`, `urmtkit1-3.zip`, `kp4diag.zip`, `kpdiag1.zip`, `trmsuppt.zip`, `trom-doc.zip`, `TurboRom_Kaypro_4.zip`, `KayproOperation.pdf`, `KayproAddendum.pdf`, `KayproSchematic.pdf`, `Kaypro_Disk_Drive_Diagnostic_Users_Guide_1983.pdf`, `Kaypro_Software_Bulletin_Jul83.pdf`, `Kaypro_Hardware_Upgrades_text.pdf`, `floppy.pdf`, `kaypro.doc`, `KP-CBOOT.DOC`, `z80-asm.5`, virtual-kaypro emulator, theory docs

### WD1002 hard disk controller manual (3 variants)
`kaypro/datasheets/WD1002-05-Winchester_HD-controller-manual_Jul83.pdf`, `kaypro_related/61-031050-0030_WD1002-05_HDO_OEM_Manual_Jul83.pdf`, `kaypro_related/79000004WD1002SHDOEMManualAug1984.3449749783.pdf`