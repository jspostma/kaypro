# Proposed Folder Structure

Suggested reorganization of the combined `kaypro/` and `kaypro_related/` contents into a unified hierarchy.

---

## Tree

```
kayprostuff/
│
├── docs/
│   ├── hardware/
│   │   ├── manuals/          # Official Kaypro manuals (technical series 1484-C/D/E/F,
│   │   │                     #   dealer ref, user guide, Omni-4, upgrade guide, etc.)
│   │   ├── schematics/       # Circuit diagrams (Kaypro II, general)
│   │   ├── reference/        # Operation theory, maintenance guide, version/ROM matrix,
│   │   │                     #   keyboard pinouts & specs, cold-boot docs, serial info,
│   │   │                     #   KP-CBOOT (all format variants), repair manual scan
│   │   └── peripherals/      # ADM-3A terminal manual; RS-232 signal ref
│   │
│   ├── cpm/                  # All CP/M documentation (alteration guide, interface guide,
│   │                         #   operating manuals, bootstrap, filesystem docs, CP/Net manual)
│   │
│   ├── datasheets/
│   │   ├── z80/              # Z80 CPU volumes, interrupt ref, chapter excerpts
│   │   ├── disk-controllers/ # WD179x FDC, WD1002/1943 HDC, TEAC FD235HF, hard disk ref
│   │   ├── crtc/             # 6545/MC6845 (all format variants), CRTC compendium
│   │   ├── memory/           # 6116 SRAM, 2764 EPROM, NRAM, NAND flash
│   │   └── misc/             # Logic ICs (74xx), UART, RTC, voltage regulator,
│   │                         #   ESP8266, Mitsubishi M5L8049, misc
│   │
│   └── languages/            # Turbo Pascal 3.0, SDCC, PL/I, M80/MAC assembler refs,
│                             #   SDCC doc master archive
│
├── software/
│   ├── cpm-os/               # CP/M distributions (2.2, 3, STDCPM22, DRIPAK, cpm80),
│   │   │                     #   source (cpm20src, cpm2-asm, cpm2-plm), patches,
│   │   │                     #   CP/M TeX, learning materials, Kermit-80
│   │   └── cpmish/           # Open-source CP/M 2.2 clone (keep self-contained)
│   │
│   ├── rom/
│   │   ├── dumps/            # turbo.bin, 81-146a.bin, 81-478c.rom, boot/ + character/ ROMs
│   │   └── source/           # k10rom7a/, bios.mac, crdmp.z80, TurboROM src, ProMulti 884
│   │
│   ├── disk-images/          # All preservation disk images in one place
│   │   ├── kaypro-4/         # k4f-292.td0, Kaypro-4-DS-HFE.zip, k4-games.td0
│   │   ├── system/           # 22src*.img, kp22gdsd.td0, KayPlus-Boot.imd, kpmex114.td0,
│   │   │                     #   kp-trom.td0, bootimd.zip, floppy collection (184 files)
│   │   └── games/            # zork1.zip
│   │
│   ├── by-model/             # Software archives organized by Kaypro model
│   │   ├── kaypro-1/
│   │   ├── kaypro-ii/        # KAYPROII.ZIP, kayproii.zip
│   │   ├── kaypro-2x/        # KAYPRO2X.ZIP
│   │   ├── kaypro-4/         # kaypro4.zip, kaypro83.zip
│   │   └── kaypro-10/        # kaypro10.zip (disk images), Gotek config
│   │
│   ├── utilities/            # Kermit, Mite, VT100KAY, KPVID, XLATE5, KRAMDISK,
│   │                         #   PCGET/PCPUT, mload, web-lan, wgrep, mac-b,
│   │                         #   kcom-bcn, kp-bios, KAYMISC, CPMRef, COMPUPRO
│   │
│   ├── diagnostics/          # kp4diag, kpdiag1, kpgetrom, 84KP256A.ARK
│   │
│   └── games/                # kpgames.zip, zork1.zip (archive copy)
│
├── tools/
│   ├── emulators/            # Virtual Kaypro (jar + configs + disk images),
│   │                         #   future emulators here
│   ├── z80/                  # z80-asm 2.4.1 source, dazzlestar disassembler, asm80,
│   │                         #   z80prog, myz80, ZRT80, KC85 signal recordings
│   ├── disk-tools/           # cpmtools-2.23 (source + extracted), Disk-Utilities (C src),
│   │                         #   ImageDisk imd118, format.jar, cpt, urmtkit 1-3
│   └── floppy-emulators/     # HxC software + extracted, FlashFloppy source + extracted
│                             #   + FF_Images, FreHD 2.14
│
├── community/
│   ├── articles/             # Kaypro restoration blog (Gough's), Dave's Old Computers,
│   │                         #   Kaypro II Extreme, Deep Dive #9, video/graphics articles,
│   │                         #   porting CP/M, graphics tutorial, keyboard USB project docs
│   ├── forums/               # Forum archive (67 HTML), VCF archive, newsgroup discussion,
│   │                         #   strange-disk-problem thread
│   └── mirrors/              # sebhc.durgadas.com (current + old snapshots)
│
├── publications/
│   ├── micro-cornucopia/     # Full archive (bitsavers download) + individual issue PDFs
│   └── electronics-digest/   # Autumn 1983 issue
│
├── photos/
│   ├── hardware/             # BIOS POST screens, internal components, general (2019)
│   └── keyboard/             # High-res keyboard detail shots (2022, 19 JPGs, 74 MB)
│
└── projects/                 # Personal ongoing work — already partially created
    ├── pico-board/           # RP2040 daughter board (boot manager + RAM disk + monitor)
    │                         #   design-notes.md: bus signals, GPIO, subsystem designs,
    │                         #   U29/U10 ASIC notes, DRAM refresh, open questions
    ├── bios-c-rewrite/       # C BIOS rewrite using z88dk
    │                         #   z80-c-toolchains.md: toolchain setup, inline asm,
    │                         #   DPB structs, I/O port ref, scratch RAM ref
    ├── rom-explainer/        # ROM walkthrough — open index.html in browser
    ├── rom-reference.md      # ROM version matrix + all ROM-related archive files
    ├── keyboard-usb/         # USB conversion: README, schematics, notes, images
    └── notes/                # todo, hardware_README, misc notes, Selectric fonts,
                              #   AUTOBOOT.WZ, misc one-offs
```

---

## Key decisions

**Unified hierarchy** — the `kaypro/` vs `kaypro_related/` split was historical accident, not meaningful taxonomy. Everything merges into one tree.

**`docs/` is pure reference material** — nothing executable. Subcategories map to how you'd actually search: *"I need the manual"*, *"I need a datasheet"*, *"I need to understand CP/M"*.

**`software/` separates concern clearly:**
- `cpm-os/` = the operating system itself
- `rom/` = firmware (dumps + source together, since they're tightly related)
- `disk-images/` = preservation images for use with real hardware or imaging tools
- `by-model/` = "what software ran on my specific machine"
- `utilities/`, `diagnostics/`, `games/` = self-explanatory

**`tools/` holds everything you run on a modern PC** to work with Kaypro material:
- `emulators/` = software emulating the Kaypro (Virtual Kaypro now, others in future)
- `z80/` = Z80 dev tools (assemblers, disassemblers)
- `disk-tools/` = disk image manipulation (cpmtools, Disk-Utilities, ImageDisk, etc.)
- `floppy-emulators/` = software for hardware floppy/disk emulator devices (HxC, FlashFloppy, FreHD)

**`community/` preserves web archives without burying them** — restoration guides, forum threads, and site mirrors are findable without digging through article assets.

**Duplicates** — this structure implies keeping one canonical copy per item. The many duplicates identified across both folders (TurboROM ×5+, kermit.zip ×3, etc.) should be consolidated during the actual move.
