# Kaypro wiki

Notes on Jaapie's Kaypro 4 ('84 series, ROM 81-292-A) and the projects built around it.
Plain Markdown with relative links, so it reads the same on GitHub and in Obsidian.

**This repo is canonical** for Kaypro notes. The old local `kaypro_stuff` repo was
imported here on 2026-10-27 and is retired. The archive binaries stay out of git.

**Status convention:** every project page has a `Status:` line. Unless it says
otherwise, everything is *idea* or *design only*.

## Where things live

| What | Where |
|---|---|
| Wiki pages, notes, code (`kaypro.h`), ROM explainer | this repo |
| Archive (manuals, schematics, ROM dumps, disk images, mirrors) | on disk, not in git: see [archive/](archive/README.md) |
| Vault notes (`kaypro-4`, `kaypro-research`, …) | `jspostma/vault`; should point here |

## Pages

### Hardware
- [The machine](hardware/machine.md): chips, ASICs, **disputed I/O map**, keyboard, modem, headers, electrical rules
- [Video](hardware/video.md): CRTC programming, timing derivation, why CVBS won't work, digital capture
- [ROM reference](hardware/rom-reference.md): 81-xxx version matrix, every ROM file in the archive
- [ROM explainer](hardware/rom-explainer/index.html): annotated walkthrough of 81-292-A (HTML; open in a browser)

### Projects
- [Over-the-shoulder agent](projects/agent.md): an AI agent operating the Kaypro via keyboard, screen, disks and modem
- [Phone line interface](projects/phone-line-interface.md): sound card ↔ Kaypro modem board
- [Pico board](projects/pico-board.md): interposers / CPU-socket daughter board (boot manager, RAM disk, monitor) — [design notes](projects/pico-board/design-notes.md), [RAM disk](projects/pico-board/ramdisk.md)
- [NPU coprocessor](projects/npu-coprocessor.md): a Z80 machine with a binarized-NN coprocessor
- [C BIOS](projects/bios-c.md): BIOS rewrite in C with z88dk — [`kaypro.h`](projects/bios-c/kaypro.h), [reference](projects/bios-c/kaypro-h-reference.md), [toolchains](projects/bios-c/z80-c-toolchains.md)
- [Tech manual master](projects/tech-manual.md): one clean master of the 1484-C/D/E/F manuals — [notes](projects/tech-manual/notes.md)

### Tools
- [Emulation and simulation](tools/emulation.md): Virtual Kaypro, MAME, mixed-level sim, hardware-in-the-loop

### Cross-cutting
- [Open questions](open-questions.md): one list, ordered by what blocks the most
- [Archive index](archive/README.md): [master contents](archive/master_contents.md), [deep investigation](archive/deep_investigation.md), dedup, hashes
- [References](references.md): external projects, docs, parts
- [meta/](meta/): old CLAUDE.md drafts and working notes (historical)

Out of scope: the Smith-Corona printer ROM project (`printer/`) is its own repo.
