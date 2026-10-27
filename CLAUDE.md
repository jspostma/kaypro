# Kaypro wiki — context for Claude

Jaapie's notes, designs and tooling for his Kaypro 4 ('84 series, Z80 4 MHz, CP/M 2.2,
ROM 81-292-A). It's used for active hardware experiments and mods, not just collecting.
This GitHub repo (`jspostma/kaypro`) is canonical; it absorbed the old local
`kaypro_stuff` repo on 2026-10-27.

## Start here
| Need | Read |
|---|---|
| Overview and page list | `README.md` |
| Hardware facts | `hardware/machine.md`, `hardware/io-map.md` (authoritative ports), `hardware/video.md`, `hardware/keyboard.md` |
| Schematic | `hardware/schematic.md` (sheet index, IC list); PDF itself is not in git |
| What's unresolved | `open-questions.md` |
| What's in the archive | `archive/master_contents.md`, then `archive/deep_investigation.md` |
| ROM details | `hardware/rom-reference.md`, `hardware/rom-explainer/index.html` |

## Layout
```
README.md  CLAUDE.md  open-questions.md  references.md
hardware/   machine, io-map, schematic(+/), video, keyboard(+/), rom-reference, rom-explainer/
projects/   agent, phone-line-interface, pico-board(+/), npu-coprocessor,
            bios-c(+/ kaypro.h etc.), tech-manual(+/ notes, marker-output)
tools/      emulation
archive/    indexes, dedup notes, sha256 manifest (archive files themselves NOT here)
meta/       old CLAUDE.md drafts (historical)
```

## Archive (not in git)
Two trees on Jaapie's machine: [K] `kaypro/` (~444 MB) and [R] `kaypro_related/` (~3.1 GB).
`archive/master_contents.md` uses those codes. Integrity: `sha256sum -c archive/archive_hashes.sha256`.

## Environment
| Thing | Detail |
|---|---|
| C toolchain | z88dk: `zcc +cpm -subtype=kaypro` (.COM); `+z80` + custom map for ROM/BIOS |
| ML/model storage | `/mnt/llm/` is mounted `noexec`; put venvs elsewhere, use `HF_HOME=/mnt/llm/<tool>` |
| Emulator | Virtual Kaypro (Java, sims.durgadas.com); MAME |

## Conventions
- Every project page has a `Status:` line. Default is idea / design only. Never describe
  something as built unless a page or Jaapie says it is.
- Relative Markdown links only (renders on GitHub and in Obsidian).
- Hardware facts carry their source. When sources disagree, record the conflict and the
  evidence in the page and in `open-questions.md`; don't silently pick one.
- Frame hardware concepts with AVR analogues where it helps.
- Terse responses; lead with the result.

## Known hazards
- **`projects/bios-c/kaypro.h` has the wrong port map** (SIO, baud generator, VRAM model).
  Use `hardware/io-map.md`, which is decoded from the schematic, until `kaypro.h` is fixed.
- Anything driving Z80 /WAIT must be open-collector (it's a shared node).
- NMOS Z80 VOH ≈ 2.4 V: CPU-side logic must be 74HCT/LS/ACT, never plain 74HC.

## Constraints
- Do not add archive binaries (PDFs, disk images, ROM dumps) to git.
- Do not delete or move archive files without explicit instruction.
- `printer/` (Smith-Corona ROM) is a separate project and repo. Ignore it here.
- Work one step at a time. Check in before large reorganisations.
- Commit and push after each meaningful batch of changes; the repo is the backup.
