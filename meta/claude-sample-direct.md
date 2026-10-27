> **Historical (imported from `kaypro_stuff`, 2026-10-27).** Paths and the Gitea remote below describe the old local repo, not this one. The merged result is [`/CLAUDE.md`](../CLAUDE.md).

# CLAUDE.md — Kaypro Research Project (direct style sample)

You are working on a vintage computing research project centred on the Kaypro 4,
a Z80-based CP/M machine (ROM 81-292-A). This repository contains research notes,
project documentation, and tooling. The binary archive files are excluded from git
and accessed via symlinks.

---

## Orientation

Read `README.md` first — it is the navigation index for this repo.
Read `master_contents.md` for a complete inventory of the archive.

Do not assume you know what is in the archive without checking these files.

---

## Repository structure

```
kayprostuff/          ← this repo (notes, projects, tooling only)
├── kaypro/           ← symlink → /mnt/backup/intel/.../Kaypro Info  (444 MB, not in git)
├── kaypro_related/   ← symlink → /mnt/backup/kaypro_related/        (3.1 GB, not in git)
├── printer/          ← separate project, separate git repo — ignore entirely
├── master_contents.md
├── deep_investigation.md
├── archive_hashes.sha256
├── proposed_structure.md
├── pico-board/
└── projects/
    ├── bios-c-rewrite/
    ├── rom-reference.md
    └── tech-manual-master/
```

The binary archive is **not in git** and should never be added to it. Use
`sha256sum -c archive_hashes.sha256` to verify archive integrity.

---

## Key reference files

| File | When to read it |
|---|---|
| `README.md` | Start of every session — navigation index |
| `master_contents.md` | Looking for a specific file or topic in the archive |
| `deep_investigation.md` | Detailed notes on specific files (ROMs, source, executables, formats) |
| `proposed_structure.md` | Archive reorganisation plan (not yet executed) |
| `archive_hashes.sha256` | Integrity verification — 3,365 files across both archive trees |

---

## Active subprojects

### RP2040 daughter board (`pico-board/design-notes.md`)
CPU-socket board for the Kaypro 4. Three subsystems: boot manager, RAM disk, system
monitor. Critical note: U29 (part 81-194) is a custom ASIC that handles DRAM refresh
autonomously — the Z80 /RFSH signal is not used, so /BUSRQ holds are safe.

### C BIOS rewrite (`projects/bios-c-rewrite/`)
Rewriting the Kaypro BIOS in C using z88dk (`zcc +cpm -subtype=kaypro`), confirmed
working on hardware. Key files: `kaypro.h` (hardware register definitions),
`kaypro-h-reference.md` (full explanation), `z80-c-toolchains.md` (toolchain notes).

### ROM explainer (`rom-explainer/index.html`)
Self-contained HTML walkthrough of the 81-292-A ROM. Open in a browser.

### Tech manual master (`projects/tech-manual-master/notes.md`)
Consolidating four revisions of the Kaypro technical manual (1484-C/D/E/F) into a
single clean, bookmarked, diffable form. Blocked on Marker installation (needs
partition space). All existing OCR is poor quality and needs redoing.

---

## Site mirrors (in `kaypro_related/mirrors/`)

- `kayprojournal.com/clean/` — 272 MediaWiki pages as clean HTML (open `index.html`)
- `retrocmp.de/retrocmp.de/kaypro/` — 25-part Kaypro reference (open `index.htm`)

---

## Environment notes

- **Git remote:** `https://git.timegoat.org/jaapie/kaypro_stuff.git` (branch: master)
- **C development:** z88dk with Python 3.11 for any ML/tooling work
- **ML models:** stored at `/mnt/llm/` — mounted `noexec`, so Python venvs must live
  elsewhere (e.g. `~/.venv-marker`). Use `HF_HOME=/mnt/llm/<tool>` for model cache.
- **Memory files:** `~/.claude/projects/-home-jaapie-projects-kayprostuff/memory/`
  These load automatically and contain accumulated project context.

---

## Constraints

- Do not add archive files (PDFs, disk images, ROMs, binaries) to git.
- Do not delete or move archive files without explicit instruction.
- The `printer/` directory is a separate project with its own repo — do not touch it
  in the context of this project.
- The binary archive reorganisation (`proposed_structure.md`) has not been executed
  yet — do not assume the new structure is in place.
