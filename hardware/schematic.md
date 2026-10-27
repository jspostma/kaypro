# Schematic

**Non-Linear Systems drawing 81-185**, "Kaypro 4/84", board **81-184 rev B** (sheets dated
1983–84). Source file `kp4_schematic.pdf` (8 pages, scanned with a poor OCR layer) is in
Jaapie's `kaypro_schematic` folder, **not in git**.

| PDF page | Sheet | Content |
|---|---|---|
| 1 | | Board layout (component placement) |
| 2 | | IC list → [kaypro4_ics.csv](schematic/kaypro4_ics.csv), [ic_list.json](schematic/ic_list.json) |
| 3 | 2A | Processor: Z80 U43, boot ROM U34, I/O decode U26/U27, J9 buffers |
| 4 | 2B | Video: 6545 U16, gate array U10 81-189, VRAMs U23/U15, char ROM U9, J1 monitor |
| 5 | 2C | RAM: U29 81-194, 8× 2164 |
| 6 | 2D | Floppy (1793 U44, FDC9216 data separator) and parallel printer J5 |
| 7 | 2E | Serial: SIOs U11/U17, baud gen U24, J2 keyboard, J3 serial printer, J4 RS-232 |
| 8 | 2F | Modem (TMS99532 U18, dialer TMS99531 U19, line interface, ring detect) and RTC (MM58167A U36 via PIO U35) |

Derived pages: [I/O map](io-map.md), [machine](machine.md), [video](video.md).

## IC list (81-184)

| Ref | Part | Function |
|---|---|---|
| U43 | Z80A | CPU |
| U34 | 81-292 (2764) | Boot ROM |
| U29 | 81-194 | Gate array: clocks, DRAM mux/refresh, bank select |
| U10 | 81-189 | Gate array: video timing, shifter, attributes |
| U16 | 6545A (marked "6845EA" on the sheet) | CRTC |
| U9 | 81-235 (2732) | Character ROM |
| U15, U23 | 6116 | Attribute / character VRAM |
| U32, 33, 38, 39, 41, 42, 47, 48 | 2164 | 64K×1 DRAM |
| U11, U17 | Z80A SIO | Serial (keyboard, RS-232, printer, modem) |
| U35 | Z80A PIO | RTC addressing, dialer |
| U24 | WD1943 / COM8116 | Dual baud rate generator |
| U44 | 1793 | Floppy controller |
| U67 | FDC9216 | Data separator |
| U18 | TMS99532 | 300-baud modem |
| U19 | TMS99531 | Dialer |
| U21 | 4N35 | Optoisolator (line / ring detect) |
| U36 | MM58167A | Real-time clock |
| U12 | LM324 | Modem analog (filters, ring detect) |
| U3/U5, U4 | 1489, 1488 | RS-232 receivers / drivers |
| U20, U31 | 74LS245 | Bus transceivers (VRAM attribute, J9 data) |
| U28 | 74LS244 | J9 address buffer |
| U51 | 74LS244 | Buffer (role not traced yet) |
| U26, U27 | 74LS138 | I/O decode |
| U6, U13, U14, U55, U58 | 74LS373 | Latches |
| U8 | 74LS374 | Char-code latch → char ROM |
| U60 | 74LS195 | Shift register |
| U73 | 74HC00 | Clock buffering (added rev B) |
| spares | U53, U70, U74, U75 | |

Full list with packages: [kaypro4_ics.csv](schematic/kaypro4_ics.csv). OCR typos
("Ul3", "U7l") are in the source table.

## IC-mapping tool (idea)
Jaapie's plan: click an IC on the layout page and see it highlighted across the IC list and
section sheets. Bounding boxes from machine vision are in
[ic_layout.json](schematic/ic_layout.json) and need manual correction; U12 and U34
weren't found. Notes: [mapper-notes.md](schematic/mapper-notes.md). Status: **idea**.
