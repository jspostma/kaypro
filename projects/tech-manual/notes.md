# Tech Manual Master Copy — Project Notes

Goal: produce a single clean, bookmarked, OCR'd PDF covering all Kaypro models from the four revision PDFs (1484-C through 1484-F), and extract a diffable text form to identify undocumented changes between revisions.

---

## Source PDFs — complete unique-file inventory

Hash deduplication performed 2026-04-01. 11 distinct files across `kaypro/manuals/`, `kaypro_related/kaypro4/pdf/kaypro/`, and `kaypro_related/mirrors/retrocmp.de/`. retrocmp.de and kayprojournal.com mirrors contain no tech manual sources not already in the local archive.

| Hash (8) | Rev | Date | Pages | Size | Location | Notes |
|---|---|---|---|---|---|---|
| `f480d887` | 1484-C | Aug 1984 | 154 | 8 MB | `kaypro/manuals/C/1484-C_Kaypro_Technical_Manual_Aug84.pdf` | Main copy; identical in kaypro4/pdf/ and retrocmp.de mirror. Sections 1–18. Marker output done. |
| `69029b4f` | 1484-C | Aug 1984 | **203** | 6.3 MB | `kaypro/manuals/C/1484-C_KayproTechnicalManual_Aug84(1).pdf` | **Mixed binding: sections 1–18 (identical to 154pp) + section 19 (Kaypro 16) on pp.154–202.** Likely a service-dept copy with the new section inserted before 1484-D was issued. Section 19 covers Kaypro 16 chassis/boards/drives/I/O/memory map/switch settings. Also = mystery file `kaypro/manuals/5620701505058721359.pdf` (same hash). Adobe Acrobat 8.31 Paper Capture, Sep 2013. |
| `79af7337` | 1484-D | Dec 1984 | 157 | 5.1 MB | `kaypro/manuals/D/1484-D_KayproTechnicalManual_Dec84.pdf` | Scan only; identical in kaypro4/pdf/ and retrocmp.de mirror. |
| `3b43319b` | 1484-D | Dec 1984 | 157 | 4.3 MB | `kaypro/manuals/D/1484-D_KayproTechnicalManual_Dec84_text.pdf` | Text-layer variant of above. |
| `eea318c2` | 1484-E | Jun 1985 | 132 | 11 MB | `kaypro_related/kaypro4/pdf/kaypro/1484-E_KayproTechnicalManual_Ch1-15_Jun85.pdf` | Ch1–15 scan. |
| `22775d32` | 1484-E | Jun 1985 | 132 | 17 MB | `kaypro_related/mirrors/retrocmp.de/.../1985_1484-E_KayproTechnicalManual.pdf` | Same 132pp, different (higher-res?) scan. |
| `823a5df0` | 1484-E | Jun 1985 | 132 | 4.2 MB | `kaypro/manuals/E/1484-E_KayproTechnicalManual_Ch1-15_Jun85_text.pdf` | Text-layer variant. |
| `8fd5a1c8` | 1484-E | Jun 1985 | **126** | 9.7 MB | `kaypro/manuals/F/1484-E_KayproTechnicalManual_June85.pdf` | **6 pages fewer than 132pp copies.** Canon iR5570/iR6570 scan, 2006. Likely missing pages from physical copy. |
| `2e1c60cd` | 1484-F | Sep 1985 | 279 | 19 MB | `kaypro/manuals/F/1484-F_Kaypro_Technical_Manual_Sep85.pdf` | Full (sections 1–29); duplicate copy in manuals/F/ and kaypro4/pdf/. |
| `167805b5` | 1484-F | Sep 1985 | 279 | 28 MB | `kaypro_related/mirrors/retrocmp.de/.../1985_1484-F_KayproTechnicalManual.pdf` | Same 279pp, different (higher-res?) scan. |
| `f14cf7ff` | 1484-F | Sep 1985 | 122 | 15 MB | `kaypro/manuals/F/1484-F_KayproTechnicalManual_Ch19-29_Sep85.pdf` | Ch19–29 only (partial). |

**Coverage summary:**
- 1484-C 154pp: sections 1–18 confirmed from Marker output
- 1484-C 203pp: unknown — Marker conversion pending
- 1484-D: sections unknown (Marker not yet run)
- 1484-E: sections 1–15 (confirmed by filename); 132pp vs 126pp content unknown
- 1484-F 279pp: sections 1–29 — most complete single document; `toc.json` produced from this

**Sections 19–29** (present only in 1484-F) cover models added after Aug 1984 — likely Kaypro 16 and DOS-era machines.

Existing "text layer" OCR quality is uniformly bad across all revisions — produced by an older engine. Samples:
- "PURJ?ajE CF T!XB1ICAL MN!U\\L" → "PURPOSE OF TECHNICAL MANUAL"
- "KAn'RO 4/84 SPB!IFICATIO!1S" → "KAYPRO 4/84 SPECIFICATIONS"
- 1484-F_full-ocr.pdf is worse — character-spaced output suggesting wrong-DPI scan input

The manual covers all Kaypro models (CP/M and DOS-era), so newer revisions may contain updated info on equipment relevant to the Kaypro 4 even where sections appear redundant. Undocumented edits between revisions are possible and worth diffing.

---

## Work completed (2021)

Located in `kaypro_related/kaypro4/tech manual/`:

- **`sections/1484-F_full.pdf`** (19 MB) — base assembled PDF
- **`1484-F_full-ocr.pdf`** (28 MB) — OCR pass applied (poor quality)
- **`toc.json`** — fully structured TOC (29 sections, subsections, page numbers) — real work, keep
- **`kaypro-1484-F_contents.csv` / `.ods`** — source TOC data, manually compiled — keep
- **`kaypro-1484F-index.txt`** — back-of-book index, transcribed — keep
- **`kaypro-1484F-toctxt`** — raw TOC text — keep
- **`kaypro4_memory_map.pdf`**, **`kaypro4_portmaps.pdf`**, **`kp4_schematic.pdf`** — extracted sections of interest — keep
- **`toc4.py`** — most recent script for injecting TOC as PDF bookmarks (has syntax error — stray `)` on `item = (path,description,page))` line)
- **`sections.py`** — Section class and outline builder using pikepdf
- **`toc.py`**, **`toc2.py`**, **`toc3.py`** — earlier iterations, superseded
- **`gr.py`** — unrelated networkx tutorial snippet

Residue (safe to clean up when ready):
- `html/1/` — 342 PNG page renders (~450 MB, bulk of the 477 MB total)
- `newtest*.pdf`, `test*.pdf`, `nt3.pdf`, `test5.pdf.bak` — intermediate outputs
- `pm.pdf`, `pm-ocr.pdf`, `pm.ps`, `pm%d.ps`, `pm.txt`, `portmaps08-12.pdf` — port map iteration artifacts
- `urwid/` — Python TUI library dumped as local dep
- `venv/` — Python virtualenv
- `__pycache__/` — bytecode cache
- `tmp/` — temp files

---

## Why it stalled

The index extraction from the back-of-book index (`kaypro-1484F-index.txt`) became too complex to parse from the bad OCR. The TOC injection script (`toc4.py`) was left with a syntax error. The project was set aside before the bookmark injection was completed or any cross-revision diffing was done.

---

## Planned next steps

### 1. Re-OCR all four revisions
Use **Marker** (marker-pdf, Python library) for full structural conversion to Markdown — understands headers, tables, multi-column layouts.

**Status: 1484-C complete.** Output at `projects/tech-manual/marker-output/1484-C_Kaypro_Technical_Manual_Aug84/`. 2,479 lines of Markdown. Quality assessment:
- Body text, spec tables, IC lists: good — usable for diff and search
- Spec table values (model numbers, ROM versions, part numbers): accurate
- Degraded scan pages: section headers sometimes garble badly, body less affected
- Systematic OCR font substitutions: `Ø`→`0`, occasional `:f`→`f` (`:fran`→"from")
- Overall: vastly better than old OCR; good enough for cross-revision diff

Run command (working):
```
PYTORCH_CUDA_ALLOC_CONF=expandable_segments:True \
~/.venv-marker/bin/marker_single "$INPUT" \
  --output_dir "$OUTDIR" \
  --disable_image_extraction \
  --highres_image_dpi 150 \
  --layout_batch_size 2
```
Runtime: ~8.5 minutes on RTX 2080 Super (8 GB VRAM).

**Marker install notes:**
- venv at `~/.venv-marker` (Python 3.11 — 3.14 breaks Pillow 10.x build)
- Model cache: `~/.cache/datalab/` — Marker ignores `HF_HOME`, uses its own datalab cache dir. Models are ~1.35 GB (surya) + additional layout/table models.
- `/mnt/llm` is noexec — venv must live elsewhere; model storage location cannot be redirected
- Pillow pinned to `>=12.0.0` to bypass marker's `<11.0.0` constraint (10.x won't build on current gcc)
- `transformers` pinned to `<5.0.0`, `regex` to `<2025.0.0` to satisfy marker's version requirements
- OOM risk: Marker uses ~6.7 GB VRAM. Default 192 DPI + batch sizes cause OOM on 8 GB card. Use flags above.

Alternatively: Google Vision API for highest character accuracy on worst pages, then reconstruct structure separately.

### 2. Fix and complete TOC bookmark injection
Fix syntax error in `toc4.py` (line with `item = (path,description,page))`), run against `sections/1484-F_full.pdf` to inject the structured `toc.json` as proper PDF bookmarks.

### 3. Cross-revision diff
Once all four revisions have clean Markdown output, chapter-by-chapter text diff to identify additions, deletions, and undocumented changes. 1484-C page 15 already shows the CP/M version matrix stops at 2/84 — D/E/F extend this and likely add Robie, 4/84, 2X, and later model specs.

### 4. Merge E + F into complete 1484-F master
1484-E covers chapters 1–15, 1484-F covers chapters 19–29 (also has a 279-page version covering all). Verify the 279-page F is genuinely complete before treating it as the master.

---

## Tools available

| Tool | Status | Notes |
|---|---|---|
| `pikepdf` | installed (project venv) | PDF manipulation, bookmark injection |
| `ocrmypdf` | installed (system) | Adds OCR text layer to existing PDF |
| `tesseract` | 5.5.2 (system) | Character recognition engine |
| `marker-pdf` | installed (`~/.venv-marker`) | Structural Markdown conversion, best option |
| `pdftotext` | installed (system) | Basic text extraction |
| Google Vision API | available | Best raw OCR accuracy, no structure output |
