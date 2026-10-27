# Kaypro Collection — Deep File Investigation

Detailed examination of programs, ROMs, source code, older archives, and text files. Companion to `master_contents.md`.

---

## ROM & Firmware Binaries

### `software/rom/rom.txt` [K]
A complete Kaypro ROM image in binary form. Despite the `.txt` extension, this is a binary file — the extension is either a misnomer or a platform artefact from a system that used `.txt` for all files. Contains Z80 machine code plus identifying strings extracted via `strings`:
- `"KAYPRO"` — system identification
- `"Please place your diskette into Drive A"` — boot prompt
- `"I cannot read your diskette"` — drive error message

This is a bootable ROM image containing the system's cold-start routine, drive diagnostics, and user-facing prompts.

### `81-146a.bin` [R]
2048 bytes (2 KB). The filename follows Kaypro's mainboard component numbering scheme (`81-xxx` series). Likely a small ROM or EPROM dump — possibly a character ROM, keyboard controller firmware, or a sub-component ROM rather than the main system ROM. The size (2KB = 2048 bytes) is consistent with a 2716 EPROM.

### `virtual-kaypro/81-478c.rom` [K]
8 KB ROM image used by the Virtual Kaypro emulator. The `81-478c` designation places it in the Kaypro mainboard part number series. 8 KB matches a 2764 EPROM — the size used for the main Kaypro system ROM in later models.

### `turbo.bin` [R]
8 KB TurboROM binary image. This is the actual compiled ROM image corresponding to the TurboROM 3.4 source and documentation also present in the collection. The Amiga `.info` sidecar (`turbo.bin.info`) confirms this arrived via an Amiga at some point.

---

## Source Code

### `software/source/bios.mac` [K]
**Reference BIOS for early Kaypro hardware. 1,758 lines of Z80 assembly (MAC80 assembler format). Dated July 15, 1982.**

A complete CP/M BIOS implementation documenting the hardware architecture of the early Kaypro:
- CPU: 8080-compatible (not Z80 extended instructions)
- RAM: 64 KB
- Console: CRT/keyboard controller via serial-like interface, no dedicated baud rate generator
- Serial port: Intel 8251A USART with 8253 baud rate generator
- Floppy: Two 5.25" mini-floppy drives (512-byte sectors, double-density) and two 8" drives (128-byte sectors, standard single-density)
- Implements the full CP/M BIOS jump table: `BOOT`, `WBOOT`, `CONST`, `CONIN`, `CONOUT`, `LIST`, `PUNCH`, `READER`, `HOME`, `SELDSK`, `SETTRK`, `SETSEC`, `SETDMA`, `READ`, `WRITE`, `LISTST`, `SECTRAN`

Historically interesting because it shows the Kaypro's 8" drive heritage (the Kaypro II was marketed as a portable, but the BIOS still accommodated standard 8" drives used in earlier S-100 systems).

### `software/source/crdmp.z80` [K]
**"Dump V2.05" — enhanced memory/file dump utility. Z80 assembly. Dated 28-Nov-79.**

Displays memory or file contents as paired hex and ASCII columns. An improvement over Digital Research's standard `DUMP.COM`, offering wider output and cleaner formatting. The 1979 date places this among the earliest CP/M utilities in the collection — predating the Kaypro itself by several years, reflecting the broader CP/M ecosystem the Kaypro was built to run.

### `software/source/k10rom7a/` [K]
**Kaypro 10 ROM version 7A — full Z80 assembly source. Copyright 1983 Non-Linear Systems (NLS, the company behind Kaypro).**

Six assembly source modules plus an Intel HEX output file:

| File | Size | Contents |
|------|------|----------|
| `ROM7A.MAC` | — | Cold start / reset routines; master ROM jump table |
| `DEVIO.MAC` | 8.8 KB | Device I/O handlers (serial, parallel) |
| `FLPYIO.MAC` | 17 KB | Floppy disk I/O — 5.25" mini-floppy operations |
| `HDIO7A.MAC` | 16 KB | Hard disk I/O — supports the Kaypro 10's Winchester drive |
| `VIDEO.MAC` | 16 KB | Video display control |
| `MOVE77.MAC` | 12 KB | Memory move operations |
| `RAM.MAC` | 5.3 KB | RAM configuration |
| `ROM7A.HEX` | 9.8 KB | Intel HEX output (the assembled ROM image) |

The jump table in `ROM7A.MAC` is the authoritative interface between the ROM and CP/M BIOS — every disk, video, keyboard, and serial operation routes through it. The modification note ("8-Jun-83 by M. Sherman for proper floppy response on power-up") documents a real production bug fix. This is as close to the primary source as it gets for understanding the Kaypro 10's firmware.

### `kaypro4/source/kaypro_292_rom.s` [R]
**Kaypro 292 ROM source. Z80 assembly. 24 KB.**

Source code for the ROM used in the Kaypro 292 variant. The "292" designation refers to a specific Kaypro 4/10 board revision. Together with `k10rom7a/`, this gives two ROM versions for comparison — useful for understanding what changed between hardware revisions.

### `PCGET.ASM` / `PCPUT.ASM` [R]
**XMODEM file transfer utilities for CP/M ↔ PC. Z80 assembly.**

Implements Ward Christensen's XMODEM protocol for transferring files between a CP/M machine and a PC over a serial connection:
- `PCGET.ASM` — receive a file from PC to CP/M (Kaypro receives)
- `PCPUT.ASM` — send a file from CP/M to PC (Kaypro sends)

Written by Mike Douglas. The file metadata indicates a 2015 creation/revision date, making these among the most recently authored files in the collection — demonstrating that people were still actively writing CP/M tools within the last decade. The code supports two serial hardware variants: North Star Horizon (8251 USART) and Vector Graphics Bitstreamer II.

### `software/pro884mx/MCONFIG.PAS` [K]
**Configuration utility for the Micro Cornucopia PRO-884 MAX ROM. Turbo Pascal source.**

Manages default settings stored in the first sector of the boot disk (bytes 8–15 of sector 0, after the CP/M system image pointer). Configurable items include:
- VT52 capability flag
- Screen dump key assignment
- Printer toggle key
- Timestamp key
- Disk drive stepping rates per drive (3, 6, 10, or 15 ms)

The comment in the source notes it is "too large for memory compilation" under Turbo Pascal — must be compiled to disk. Gives a direct window into how third-party ROM enhancements stored their persistent configuration on CP/M systems, which had no NVRAM or battery-backed CMOS.

### `software/pro884mx/FASTTEST.PAS` [K]
**Video performance test for the PRO-884 MAX ROM's FAST display mode. Turbo Pascal source.**

Fills the screen and repeatedly performs insert/delete line operations to test for display artefacts in the accelerated video mode. Intended to verify that the ROM's FAST mode was stable before depending on it.

### `software/pro884mx/AUTOLOAD.Z80` [K]
Z80 assembly bootloader for the ProMulti 884 ROM. Handles the initial system load sequence for the 88xx-series Kaypro with the MAX ROM installed.

### TurboROM support: `TURBO-BS.ASM` / `TURBO-BS.REL` [K]
Z80 assembly source (`TURBO-BS.ASM`, 23 KB) with pre-assembled relocatable object code (`TURBO-BS.REL`, 3 KB). The `.REL` format is CP/M's relocatable binary format — position-independent code that can be linked at any memory address.

---

## CP/M Executables

### ProMulti 884 MAX ROM utilities (`software/pro884mx/`) [K]

| File | Size | Purpose |
|------|------|---------|
| `CONFIG.COM` | 35 KB | Main configuration utility for MAX ROM settings |
| `MCONFIG.COM` | 21 KB | Compiled version of MCONFIG.PAS |
| `FASTTEST.COM` | 9 KB | Video fast-mode test (compiled FASTTEST.PAS) |
| `8DISKTST.COM` | 2.7 KB | 8-inch disk drive diagnostic |
| `NEWCOPY.COM` | 6.3 KB | Enhanced disk copy |
| `RAMCON.COM` | 3 KB | RAM controller configuration |
| `CRC.COM` | 2.8 KB | CRC checksum verification |
| `SYSGEN.COM` | 1 KB | System generation |
| `AUTOLOAD.COM` | 512 bytes | Auto-loader (minimal) |
| `EX.COM`, `D.COM` | 3 KB / 2 KB | Directory utilities |

### TurboROM support utilities (`software/trmsuppt/`, `trom-doc/`) [K]

| File | Size | Purpose |
|------|------|---------|
| `TURBOCFG.COM` | 23 KB | TurboROM configuration — the main setup tool |
| `TURBOCPY.COM` | 19 KB | Fast disk copy using TurboROM's accelerated I/O |
| `TURBOGEN.COM` | 1.2 KB | TurboROM system generation |
| `TURBOMAP.COM` | 8.9 KB | Memory map / configuration viewer |
| `MAKTURBO.COM` | 12 KB | Build a TurboROM-bootable disk |
| `MOVTURBO.COM` | 11 KB | Move TurboROM in memory |
| `MOVCPM.COM` | 9.5 KB | Standard CP/M MOVCPM |
| `FORMAT.COM` | 3.3 KB | Disk formatter |
| `ADVFMT.COM` | 33 KB | Advanced format utility |
| `DP205.COM` | 4.5 KB | Disk parameter utility (5.25" drives) |
| `PIP.COM` | 7.3 KB | Peripheral Interchange Program (standard CP/M file copy) |
| `PEEK.COM` | 5.5 KB | Memory inspection |
| `BADLIM.COM` | 5.3 KB | Bad sector management |
| `FORGET.COM` | 128 bytes | Minimal reset utility — note the 128-byte size, one CP/M sector |
| `SF.COM`, `SW.COM`, `GRID.COM` | small | Screen/switch/display utilities |
| `WSCONFIG.COM` | — | WordStar configuration for TurboROM |
| `TURBORST.COM` | — | TurboROM reset |

### `mload.com` [R]
CP/M machine language loader utility. Used for loading `.COM`-format binary programs into memory at a specified address — a common need when working with memory-resident tools or patching code in place.

### `software/virtual-kaypro/strtrk.com` [K]
26 KB CP/M utility. Name suggests "start track" or "strip track" functionality — possibly related to managing the system tracks on a floppy disk (the tracks reserved for the CP/M boot loader and BIOS).

---

## Archaic Archive Formats

### `software/84KP256A.ARK` [K]
**ARC archive (dynamic LZW compression). CP/M/DOS era archive format predating ZIP.**

Contains at minimum `84KP256A.DOC` — documentation for an expansion or upgrade referenced by the filename (likely a 256 KB RAM expansion for a Kaypro 84-series board). ARC was the dominant compression format on BBS systems in the mid-1980s before PKZIP.

### `AUTOBOOT.WZ` [K]
**Crunched CP/M file. Original filename inside: `AUTOBOOT.WS`.**

The `.WZ` extension indicates Squeeze or Crunch compression, a CP/M-native single-file compression format used on BBS systems before multi-file archives were common. The original `.WS` extension strongly suggests a **WordStar document** — so this is a compressed WordStar-format autoboot configuration or documentation file.

### `KRAMDISK.TZT` [R]
**Crunched file. Original filename inside: `KRAMDISK.TXT`.**

The `.TZT` extension is a variant crunched format. Original content is a plain text file about the Kaypro RAM disk utility — documentation or instructions for `KRAMDISK`, a RAM disk driver for CP/M.

### CP/M Library files (`.LBR`)

The `.LBR` (Library) format is a CP/M-specific flat container — it concatenates multiple files with a directory header, similar to a Unix `.tar` with no compression (compression was applied separately as `.LBZ` or similar). Contents:

| File | Contents |
|------|----------|
| `KPVID.LBR` [R] | Kaypro video driver library |
| `VT100KAY.LBR` [R] | VT100 terminal emulation for Kaypro |
| `XLATE5.LBR` [R] | Character set translation utility, version 5 |
| `AUTKEY40.LBR` [K] (in TurboROM dirs) | Automatic keyboard macro utility, version 4.0 |
| `QWIKKEY2.LBR` [K] | Quick keyboard macros, version 2 |
| `VDE22.LBR` [K] | VDE text editor integration, version 2.2 |
| `TROMHINT.LBR` [K] | TurboROM hints and tips documentation |

---

## Text & Document Files

### `KAYMAINT.TXT` [K]
**Kaypro maintenance and troubleshooting guide. By Barry A. Cole of WLAKUG (probably West Los Angeles Kaypro User Group). Copyright 1987.**

Written for owners doing their own maintenance, not technicians. Organised around the troubleshooting principle of "confirm, simplify, isolate, repeat." Key topics:
- External failure causes: bad mains power, incorrect switch settings, cable faults
- Internal causes: mechanical wear, head contamination, connector oxidation
- Disk drive head cleaning schedules and alignment testing
- The single most common fix: opening the system and reseating connectors and boards
- When to escalate to a professional

The 1987 date puts this three or four years into Kaypro ownership — the point where drives were wearing out and people were starting to need this kind of guide.

### `KP-VERSN.TXT` [K]
**Version matrix for all Kaypro models: CP/M version × mainboard part number × ROM part number.**

Documents the following models: K1, K2X/MTC, K2X, K2/84, KII/83, NEW 2, K4X, K4/84, K4/84+88, K4/83+88, K10/MTC, K10. Shows the extensive variation across production runs — CP/M versions range from 2.2D to 2.2U1, mainboards carry `81-xxx` part numbers, ROM versions similarly. An essential reference for identifying an unknown unit or determining what software is compatible.

### `KP-CBOOT.txt` / `KP-CBOOT.DOC` [K][R]
**"Cold Boot Initialization — K10 CP/M 2.2F". By J. Steele, 7-6-84.**

Describes how to manually modify BIOS configuration values using a disk sector editor (EDFILE), bypassing the `CONFIG` utility. Specific memory locations documented:
- `EA33h` — I/O byte: `81h` = parallel printer, `01h` = serial printer
- `EA47h` — modem baud rate (default `05h` = 300 baud)
- `EA48h` — printer baud rate (default `05h` = 300 baud)
- Cursor key and keypad translation table locations

The technique involves editing specific bytes in sector 0 of a CP/M disk directly. These values only take effect at cold boot — a reset alone is not sufficient. The 1984 date and the level of detail strongly suggest this was written by someone in a user group and distributed via BBS or disk. Present in four format variants (`.DOC`, `.txt`, `.md`, `.odt`) suggesting it has been actively maintained and reformatted over several decades.

### `kaypro.doc` [K][R]
**ADM-3A terminal emulation specification for the Kaypro. Binary WordStar format.**

Despite the `.doc` extension this is a WordStar (or compatible) word processor document, not a modern Word file. Readable text extracted covers:
- The Kaypro's terminal emulation (ADM-3A / Lear-Seigler): cursor movement codes, ESC sequences for cursor positioning, line insert/delete
- Character set switching between ASCII and Greek
- **RS-232 port I/O map**: data port (4), status port (6), keyboard data (5), keyboard status (7), parallel data (8), parallel status (9), system status (1Dh)

The Greek character set capability is rarely documented — the Kaypro shipped with a ROM font containing Greek characters accessible via escape sequences.

### `77053-strange-disk-problem-kaypro-selfbuilt-bios-for-harddisk` [R]
An archived forum thread (no file extension). The title describes the content precisely: a discussion of an unusual disk problem on a Kaypro with a custom-built BIOS for hard disk access. Useful primary source material for anyone attempting similar modifications.

### `hardware_README` [R]
**Documentation for `z80-mon`, a Z80 CPU emulator/monitor with hardware simulation. Dated 2005-06-02.**

Not Kaypro-specific — documents simulated hardware peripherals for a Z80 software monitor:
- Hardware clock (ports `0x1c`–`0x1f`)
- LCD display (ports `0x0a`–`0x0b`)
- Z80-CTC (Counter/Timer Circuit) with daisy-chain interrupt handling
- Bank-switched memory layout (using a TI-86 pocket calculator as the example platform — 16 ROM banks, 8 RAM banks)

Context: the `z80-mon` monitor runs on a PC but simulates Z80 hardware, used for CP/M development and testing without physical hardware.

### `todo` [K]
**Personal project notes for modernising the Kaypro 4.** Proposed upgrades:
- **PSU**: Replace with ATX power supply
- **Modem**: Replace internal modem with ESP8266 Wi-Fi module
- **Storage**: Replace floppy controller with Compact Flash — either Arduino emulating an FDD, or a ROM mod to access CF directly
- **RAM disk**: Add RAM disk capability
- **Keyboard**: Replace the 8048 keyboard controller with an Arduino; adapt to PS/2, USB, or Bluetooth

---

## Disk Images

### TeleDisk format (`.td0`)
Produced by the TeleDisk program (Sydex, early 1990s). Stores full track-level data including sector headers and interleave — can represent copy-protected and non-standard formats that sector-copy tools miss. Requires TeleDisk or a compatible tool (e.g., HxCFloppyEmulator, `td02mfm`) to extract.

| File | Size | Contents |
|------|------|---------|
| `k4f-292.td0` [K] | 264 KB | Kaypro 4 system disk (292 ROM variant) |
| `k4-games.td0` [R] | 144 KB | Kaypro 4 games collection |
| `kp-trom.td0` [R] | 135 KB | TurboROM support disk (uncompressed TeleDisk) |
| `kp22gdsd.td0` [R] | 198 KB | CP/M 2.2 GDS system disk |
| `kpmex114.td0` [R] | 72 KB | Mex v1.14 communications software disk |

### ImageDisk format (`.imd`)
Dave Dunfield's open format (2005). Stores sector data plus metadata (density, timing). Widely used for software preservation; readable by cpmtools with the right disk definition.

| File | Size | Contents |
|------|------|---------|
| `KayPlus-Boot.imd` [K] | 363 KB | KayPlus ROM bootable disk |
| 15 × `.imd` in `kaypro10.zip` [K] | — | Full Kaypro 10 software suite |
| Various in `virtual-kaypro/disk/` [K] | — | Pre-built system and application disks |

### Raw sector images (`.img`)
| File | Size | Contents |
|------|------|---------|
| `22src1.img`, `22src2.img` [K] | 251 KB each | CP/M 2.2 source code disks |
| `kayplusboot.img` [K] | 400 KB | KayPlus boot disk (same content as `.imd` above) |

---

## Z80 Development Tools

### `z80/z80-asm-2.4.1/` [R]
Full source distribution of a Z80 cross-assembler. C source files (`asm.c` 35 KB, `compile.c` 17 KB, `decode.c` 10 KB, `execute.c`) with Makefile build system and pre-built object files. Produces Z80 machine code from standard Z80 assembly source. The companion `z80-asm-current.tar.gz` may be a newer snapshot of the same project.

### `z80/dazzlestar/` [R]
**DazzleStar TNG — interactive Z80 disassembler. Java. Git repository.**

A professional-grade reverse engineering tool for CP/M binaries. Key capabilities:
- Accepts `.COM`, `.HEX`, `.PRL`, `.SPR`, `.REL` input formats
- Configurable ORG (origin address) for bare binary files
- Code path tracing — follows branches and calls to distinguish code from data regions, iteratively expanding the code map
- Symbol table generation from `.REL` relocation information
- Output in either MAC80 (CP/M standard assembler) or Zilog mnemonics
- Handles dead code and unreachable data regions separately

The combination of DazzleStar and z80-asm means the collection contains a complete round-trip toolchain: disassemble a `.COM` file → edit the resulting assembly → reassemble back to a `.COM`.

---

## Virtual Kaypro Emulator

### `VirtualKaypro.jar` [K][R]
**Java application, 937 KB compiled. Full Kaypro II / 4 / 10 emulator.**

Architecture (from the source archives):
- Z80 CPU emulator (separate `z80cpu.tgz`, 92 KB source)
- CP/M BIOS emulation
- CRT video emulation (6545 CRTC)
- Floppy disk I/O (`.logdisk` and `.imd` format)
- Winchester hard disk I/O (11 MB image files)
- CP/NET networking support (two variants: CP/NET 1.2 and CP/NET 3)
- Diablo 630 daisy-wheel printer emulation
- Keyboard mapping (configurable via `kbd-map.tgz`)

Model configuration files cover eight Kaypro variants including CP/NET-networked versions. The emulator is the primary tool for running the 50+ disk images in the collection.

---

## ROM Binary String Analysis

Extracted strings from the boot ROM binaries in `software/roms/boot/`:

| File | Identity | Key strings / features |
|------|----------|----------------------|
| `81-478c.rom` | **Official Kaypro ROM v2.03** | `Kaypro CP/M Version 2.2`, `Kaypro Corporation`, `Version 2.03`, `No operating system present on this disk`. Full keyboard scan table embedded. |
| `turbo.bin` | **TurboROM v3.4 — Plu\*Perfect Systems, © 1985** | `ADVENT PRODUCTS`, `'84 TURBO ROM v3.4`, `© 1985, Plu*Perfect Systems`, `Boot Error`. |
| `884max.rom` | **Micro Cornucopia PRO-884 ROM, © 1984** | `B0 PRO 84-52 ROM`, `MICRO CORNUCOPIA`. Built-in mini CLI: `DIR`, `LIST`, `TYPE`, `USER`, `DFU`, `GO`, `ERA`, `SAVE`, `REN`, `GET`, `JUMP`, `SUB`. |
| `kplus83.rom` | **KayPLUS-83 v0.1c — MICROCode Consulting, © 1986** | Monitor: `Boot`, `Dump`, `Go`, `Modify`, `Port`, `Terminal`, `eXtended memory test`. Self-test strings: `ROM Error`, `RAM Error`. |
| `kplus84.rom` | **KayPLUS v1.2a — MICROCode Consulting, © 1986/87/88** | Same monitor as kplus83, updated. `TERMINAL MODE: Press <CTRL>+<^> to exit`. |
| `pro884mx.rom` | **Super MAX ROM v2.7** | `B0 Super MAX 2.7`, `No system`. Same CLI as 884max.rom — later version of same family. |
| `rom.txt` | **Unknown ROM, truncated** | 5,587 bytes (8,192 expected). Same boot strings as `81-478c.rom` family but different dump source. Truncated at 0x1A (CP/M EOF marker during a text-mode transfer). Unique — no match elsewhere in archive. |

### `81-146a.bin` — Character ROM

2,048 bytes = 256 characters × 8 rows. Lower half (0x00–0x7F, first 1,024 bytes) is unprogrammed 0xFF — those glyphs come from a companion ROM not in the archive. Only chars 0x80–0xFF are programmed here. Glyphs are **active-low** (0 = pixel on).

Confirmed as the **Kaypro extended/Greek character set ROM**:
- `0x9B`=`{`, `0x9C`=`|`, `0x9D`=`}`, `0x9F`=solid block
- Several lowercase Greek letter forms (α, β, ε, etc.), mathematical symbols
- Matches the Greek charset documented in `kaypro.doc` (switchable via ESC sequences)

This is the upper half of a two-ROM character generator (2732, 4K×8). The Theory of Operation confirms the companion ROM (lower 128 ASCII chars) is a separate chip on the mainboard.

### `.sr` Signal Recordings

`z80_kc85_kc85-20mhz.sr` and `z80_kc85_kc85-cpuclk.sr` are ZIP files despite the `.sr` extension. Internal structure identifies them as **PulseView/sigrok** logic analyzer sessions — captures of Z80 bus signals from a **KC85** (East German Z80 computer, not a Kaypro). Likely reference material for Z80 bus timing analysis that got mixed in with the archive.

### LBR Archive Contents

| File | Contents |
|------|----------|
| `KPVID.LBR` | BASIC programs for video effects: inverse, underline, dim. Files are Squeezed (`.BZS`) inside. |
| `VT100KAY.LBR` | VT100 emulator for Kaypro. `.BUG` report, `.DOC`, speed variants `VT1200.COM` / `VT2400.COM`. |
| `XLATE5.LBR` | Character translation utility v5 — `.ASM` source, `.COM`, docs. |
| `AUTKEY40.LBR` | `AUTOKEYS.COM` v4.0 — keyboard macro utility. |
| `QWIKKEY2.LBR` | `QwikKey v2.0` (1984) — keyboard macros. 31 definitions per file, save/load to disk. |
| `VDE22.LBR` | `VDE 2.20` text editor by E. Meyer. Kaypro-specific overlay `VDE22KP` included. |
| `TROMHINT.LBR` | TurboROM tips/hints. References `DDT VERS 2.2` (CP/M debugger). |

### `84KP256A.ARK`

ARC archive (magic bytes `0x1A 0x08`). Contains `84KP256A.DOC` — documentation for a **256 KB RAM expansion board** for the Kaypro 84-series.

### `strtrk.com`

26,576 bytes. Guard string: `This program is for a CP/M system.` Name likely "strip tracks" — disk track manipulation for Kaypro floppies. Both copies in the archive are identical (confirmed duplicate).

### `mload.com`

**MLOAD v2.5, NightOwl Software (1983–1985).** Loads Intel HEX or binary files into memory. Standard CP/M development tool.

### `kpmex114.img`

**Empty — 0 bytes.** Floppy image is missing; only the filename survives.

---

## New PDFs (root of `kaypro_related/`, outside subfolder) — added 2026-03

| File | Size | Identity |
|------|------|----------|
| `kaypro150dpigrayscale.pdf` | 34 MB, 221 pp | *Chilton's Guide to Kaypro Repair and Maintenance* by Gene B. Williams. 150 DPI grayscale scan from San Jose State University library copy. Covers all models including Kaypro 16. Troubleshooting, board/drive/keyboard/monitor repair, add-ons. **Unique.** |
| `KayproOperation.pdf` | 4 MB, 13 pp | *Kaypro 84 Theory of Operation* © 1984 Micro Cornucopia, Eric Roby. ImageMagick scan (2011). **Duplicate content** of `1984_Kaypro_II-4_84_Theory-of-Operation.pdf` — older non-OCR scan. |
| `1984_Kaypro_II-4_84_Theory-of-Operation.pdf` | 7.3 MB, 13 pp | Same Theory of Operation, FineReader OCR'd (2022). Has searchable text layer. **Preferred version.** |
| `1984_Kaypro_II-4_84_Theory-of-Operation_Schematic.pdf` | 1.2 MB, 1 p | *Kaypro 84 Schematic* © 1984 Micro Cornucopia. Full fold-out mainboard schematic (2560×1722 pt). **Distinct from `KayproSchematic.pdf`** (official Kaypro Corp). Covers CPU, video, I/O with all ICs labelled. **Unique.** |

---

## Notable Observations

**Provenance markers in the source files:**
- `bios.mac` is dated July 1982 — within months of the Kaypro II's launch (spring 1982). It may be the original or near-original BIOS that shipped with early units.
- `crdmp.z80` is dated November 1979 — three years before Kaypro existed. It is a generic CP/M utility from the pre-Kaypro CP/M ecosystem, showing that the Kaypro was designed to run the broad existing library of CP/M software.
- `k10rom7a/ROM7A.MAC` carries a documented bug-fix commit ("8-Jun-83, M. Sherman") — a rare instance of version control history surviving in a plain comment.
- The `.WZ` extension on `AUTOBOOT.WZ` (original: `AUTOBOOT.WS`) indicates a WordStar document that was Squeezed and uploaded to a BBS, then downloaded and never decompressed before being archived again. The content has never been seen since it was compressed, possibly in the mid-1980s.

**Format survival:**
The oldest files (1979–1984) have survived in better condition than might be expected. The binary format files (`.COM`, ROM images) are immune to text encoding issues. The assembly source files use 7-bit ASCII throughout — standard CP/M convention — which survives most encoding transformations intact. The greatest risk to text files is CR/LF mangling, which affects readability but not content recovery.

**Completeness of the ROM source:**
Having both `k10rom7a/` (Kaypro 10 ROM v7A source) and `kaypro_292_rom.s` (292 variant source) alongside the `81-478c.rom` binary used by the emulator means it is theoretically possible to assemble, diff, and patch ROM images — a level of access well beyond what most vintage computer collections provide.
