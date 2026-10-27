# Archive index

The archive itself is **not in git**: manuals, schematics, datasheets, ROM dumps, disk
images, emulators, site mirrors. It lives in two trees on Jaapie's machine:

| Code | Tree | Size |
|---|---|---|
| **[K]** | `kaypro/` (originally under `/mnt/backup/intel/…/Kaypro Info`) | ~444 MB |
| **[R]** | `kaypro_related/` (`/mnt/backup/kaypro_related/`) | ~3.1 GB |

In the old `kaypro_stuff` checkout these were symlinked in as `kaypro/` and `kaypro_related/`.

## Files here
| File | What |
|---|---|
| [master_contents.md](master_contents.md) | **Start here.** Unified index of both trees, 14 sections, [K]/[R] location codes, duplicates |
| [deep_investigation.md](deep_investigation.md) | Per-file detail: ROMs, source, executables, disk images, formats, Z80 tools, emulators, binary string analysis |
| [proposed_structure.md](proposed_structure.md) | Proposed reorganisation of the trees. **Not executed.** |
| [archive_hashes.sha256](archive_hashes.sha256) | SHA-256 manifest, 3,365 files. Verify from the archive root with `sha256sum -c` |
| [kaypro_summary.md](kaypro_summary.md), [kaypro_related_summary.md](kaypro_related_summary.md) | Historical snapshots, superseded by `master_contents.md` |
| [summary-prompt.md](summary-prompt.md) | The original prompt used to generate the summaries |

## Deduplication (analysed March 2026)
| | |
|---|---|
| Total files | 3,365 |
| Unique | 2,660 |
| Size now | ~1.6 GB |
| After dedup | ~1.0 GB |
| Reclaimable | ~546 MB (34%) |

Biggest offenders: Virtual Kaypro disk images in four places, `KayproSchematic.pdf` ×7,
`KayproOperation.pdf` ×7, `KayproAddendum.pdf` ×5. Not done yet.

## Version control strategy
- **Notes, docs, code** → this repo; text diffs are meaningful.
- **Archive binaries** → never in git. Back up with rsync; check integrity with the manifest.
- Reorganisation and dedup are independent of tooling: a directory restructure plus a dedup pass.

## Archive items worth knowing about
- `kaypro.doc` (WordStar): period ADM-3A/port document; source of the disputed SIO port evidence.
- `KP-CBOOT.*`: K10 CP/M 2.2F cold-boot config bytes (`EA47h` modem baud, default 300).
- `KP-VERSN.TXT`: model × CP/M version × mainboard × ROM matrix.
- `kaypro_keyboard.txt` and the keyboard USB conversion project in `web/`: keyboard protocol.
- `software/source/k10rom7a/`: full K10 ROM v7A source (1983).
- Site mirrors: kayprojournal.com (clean HTML), retrocmp.de Kaypro reference.
- Chilton's *Guide to Kaypro Repair and Maintenance* (`kaypro150dpigrayscale.pdf`).
