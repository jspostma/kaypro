> Imported 2026-10-27 from Jaapie's `kaypro_schematic` folder: the CLAUDE.md of a planned interactive IC-mapping tool. Status: **idea**; `layout.py` is a 6-line stub. The source PDF and the Inkscape SVGs (raster page 1 + a few rectangles) are not in git.

# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project purpose

This project is a tool for interactively mapping integrated circuits across the Kaypro 4/84 mainboard (assembly 81-184-n). The primary source is `kp4_schematic.pdf`, which contains:

- **Page 1** — physical component layout of the motherboard (silkscreen-style diagram)
- **Page 2** — IC list: reference designation, part number, and description
- **Pages 3+** — functional schematics broken down by board section

The goal is a UI that lets a user click or hover on a component in a rendered page image and see it highlighted, with cross-references between the layout (page 1), the IC list (page 2), and the section schematics (pages 3+).

## Development environment

```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt   # once requirements.txt exists
```

Python 3.14 is the target interpreter (configured in `.idea/`).

## Existing data files

### `ic_list.json`
Array of objects extracted from page 2 of the PDF. Schema:
```json
{ "references": ["U1", "U54"], "part": "7406", "description": "Hex inverter, open collector" }
```
`part` is `null` for spare slots. One entry covers all references sharing a part/description.

### `ic_layout.json`
Object with a `components` array extracted from page 1. Schema:
```json
{ "ref": "U1", "bbox": [x1, y1, x2, y2] }
```
Coordinates are pixel positions in the rendered page 1 image, origin top-left. These bounding boxes were estimated by machine vision and **will need manual correction** — accuracy varies, with the top rows (U1–U11) being most reliable and the dense right-side cluster and lower-center area being least reliable. U12 and U34 were not located. An `"unknown_N"` naming convention is planned for IC footprints whose reference designation is not legible.

## Architecture intent

The planned approach is to automate what machines handle well and expose manual correction UI for what they don't:

- **PDF rendering** — rasterise pages at a fixed DPI (e.g. via `pypdfium2` or `pdf2image`) to get stable pixel coordinates
- **Automated bbox extraction** — template matching or connected-component analysis on the rasterised layout to detect DIP footprints; IC body shapes are regular and mostly vary only in length and rotation
- **Manual correction layer** — a lightweight UI (likely Tkinter or a browser-based canvas) where the user can drag/resize bboxes and assign reference designations to unknown footprints
- **Schematic cross-reference** — for each IC reference, record which schematic page(s) it appears on and the bbox within that page, enabling bidirectional navigation
- **Data model** — a single JSON (or SQLite) store keying on reference designation, linking layout bbox, IC list entry, and schematic page appearances