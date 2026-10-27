# Kaypro wiki

Notes on Jaapie's Kaypro 4 ('84 series, ROM 81-292-A) and the projects built around it.
Plain Markdown with relative links, so it reads the same on GitHub and in Obsidian.

**Status convention:** every project page has a `Status:` line. Unless it says otherwise,
everything here is *idea* or *design only*. Nothing is built unless a page says so.

## Where things live (read this first)

This repo is not the only Kaypro source. Before adding anything, check whether it
belongs in one of these instead:

| What | Where | Holds |
|---|---|---|
| **This repo** (`jspostma/kaypro`) | GitHub | Wiki pages: hardware facts, project designs, decisions, open questions |
| **`kaypro_stuff`** | `https://git.timegoat.org/jaapie/kaypro_stuff.git` (branch `master`), checkout `~/projects/kayprostuff` | Research notes, tooling, archive indexes (`README.md` → `master_contents.md` → `deep_investigation.md`), `kaypro.h`, ROM explainer, ROM reference, tech-manual work |
| **Archive** (not in git) | `/mnt/backup/intel/…/Kaypro Info` (~444 MB), `/mnt/backup/kaypro_related/` (~3.1 GB) | Manuals, schematics, datasheets, ROM dumps, disk images, emulators, site mirrors |
| **Vault notes** | `jspostma/vault`: `kaypro-4`, `kaypro-research`, `kaypro-pico-board`, `kaypro-bios-c`, `kaypro-tech-manual` | Short summaries pointing at `kaypro_stuff` |

> Open decision: is this repo the wiki *for* `kaypro_stuff` (design and decision pages
> only, linking out for detail), or does it replace `kaypro_stuff`'s notes? See
> [open questions](open-questions.md#meta).

## Pages

### Hardware
- [The machine](hardware/machine.md): chips, ASICs, buses, connectors, level-shifting rules
- [Video](hardware/video.md): measured timing, why CVBS won't work, digital capture (Kaypro10Video)

### Projects
- [Over-the-shoulder agent](projects/agent.md): an AI agent operating the Kaypro through keyboard, screen, disks and modem
- [Phone line interface](projects/phone-line-interface.md): sound card ↔ Kaypro modem board (part of the agent)
- [Pico debug / daughter board](projects/pico-board.md): CPU, ROM, VRAM and char-ROM interposers; boot manager, RAM disk, monitor
- [NPU coprocessor](projects/npu-coprocessor.md): a Z80 machine with a binarized-NN coprocessor, Am9511-style
- [C BIOS](projects/bios-c.md): BIOS rewrite in C with z88dk
- [Tech manual master](projects/tech-manual.md): one clean master of the 1484-C/D/E/F technical manuals

### Tools
- [Emulation and simulation](tools/emulation.md): Virtual Kaypro, MAME, mixed-level sim, hardware-in-the-loop

### Cross-cutting
- [Open questions / things to measure](open-questions.md): one list, ordered by what blocks the most
- [References](references.md): external projects, docs, parts
