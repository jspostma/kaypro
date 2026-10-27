> **Historical (imported from `kaypro_stuff`, 2026-10-27).** Paths and the Gitea remote below describe the old local repo, not this one. The merged result is [`/CLAUDE.md`](../CLAUDE.md).

# Kaypro Research Project — Claude Context (project brief style sample)

## What this project is

A vintage computing research archive and active hardware project workspace centred on
the Kaypro 4, a Z80-based CP/M machine (ROM 81-292-A). The owner uses the archive for
active hardware experimentation and modification — this is not just a collection.

This repository contains notes, documentation, and tooling only. The binary archive
(~3.5 GB of PDFs, disk images, ROM dumps, manuals) lives outside the repo and is
accessed via symlinks (`kaypro/` and `kaypro_related/`). It is not in git and should
not be added.

---

## Finding things

**Start with `README.md`** — it is the navigation index for the repo.

For the archive contents specifically:
- `master_contents.md` — unified index of everything across both archive trees
- `deep_investigation.md` — detailed examination of specific files

The archive has not yet been reorganised. `proposed_structure.md` describes a planned
but unexecuted reorganisation into a cleaner hierarchy.

---

## Repository layout

```
kayprostuff/
├── kaypro/              symlink to archive tree 1 (444 MB) — not in git
├── kaypro_related/      symlink to archive tree 2 (3.1 GB) — not in git
├── printer/             separate project, separate repo — out of scope here
├── master_contents.md
├── deep_investigation.md
├── archive_hashes.sha256   SHA-256 manifest for both archive trees
├── proposed_structure.md
├── pico-board/
│   └── design-notes.md
└── projects/
    ├── bios-c-rewrite/
    │   ├── kaypro.h
    │   ├── kaypro-h-reference.md
    │   └── z80-c-toolchains.md
    ├── rom-reference.md
    └── tech-manual-master/
        └── notes.md
```

---

## Active subprojects

**RP2040 daughter board** (`pico-board/design-notes.md`)
A CPU-socket daughter board combining a boot manager, RAM disk, and system monitor.
Hardware note worth knowing immediately: U29 (part 81-194) is a custom ASIC handling
DRAM refresh autonomously. The Z80 /RFSH signal is not used; /BUSRQ holds are safe.

**C BIOS rewrite** (`projects/bios-c-rewrite/`)
Rewriting the Kaypro ROM BIOS in C using z88dk, confirmed working on hardware.
`kaypro.h` provides AVR-style hardware register definitions for all I/O ports.
`kaypro-h-reference.md` explains every definition in detail.

**ROM explainer** (`rom-explainer/index.html`)
Browser-based annotated walkthrough of the 81-292-A ROM.

**Tech manual master** (`projects/tech-manual-master/notes.md`)
Consolidating four revisions of the Kaypro technical manual (1484-C/D/E/F). All
existing OCR is poor quality. Conversion via Marker (PDF→Markdown) is planned but
blocked on disk space for model storage.

---

## Archive mirrors

Two site mirrors were created in `kaypro_related/mirrors/`:
- `kayprojournal.com/clean/` — 272 MediaWiki pages converted to clean HTML
- `retrocmp.de/retrocmp.de/kaypro/` — 25-part Kaypro reference, updated 2024/2025

---

## Environment

| Thing | Detail |
|---|---|
| Git remote | `https://git.timegoat.org/jaapie/kaypro_stuff.git`, branch `master` |
| C toolchain | z88dk — `zcc +cpm -subtype=kaypro` |
| ML/model storage | `/mnt/llm/` — mounted `noexec`; venvs go elsewhere, use `HF_HOME=/mnt/llm/<tool>` |
| Archive integrity | `sha256sum -c archive_hashes.sha256` (3,365 files) |
| Memory files | `~/.claude/projects/-home-jaapie-projects-kayprostuff/memory/` — auto-loaded |
