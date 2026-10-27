# Tech manual master

Status: **active, stalled**. Detail: [notes.md](tech-manual/notes.md). Marker output for 1484-C: [`tech-manual/marker-output/`](tech-manual/marker-output/).

Goal: one clean, bookmarked, OCR'd master of the Kaypro Technical Manual from revisions
1484-C (Aug 84), D (Dec 84), E (Jun 85) and F (Sep 85), plus a diffable text form to find
undocumented changes between revisions. 11 distinct source PDFs (hash-deduped 2026-04-01).

## Decisions
- Re-OCR with **Marker** (structural Markdown). The existing text layers are uniformly bad.

## Status
- 2021: assembled 1484-F PDF, `toc.json`, hand-compiled TOC CSV, transcribed index.
  Stalled parsing the index from bad OCR; `toc4.py` left with a syntax error.
- 1484-C (154 pp) converted with Marker: good enough for diff and search.

## Next
1. Marker on the rest: 1484-C 203 pp (has a Kaypro 16 section 19), D, E (132 vs 126 pp copies), F.
2. Fix `toc4.py`; inject `toc.json` as bookmarks into the 1484-F PDF.
3. Chapter-by-chapter cross-revision diff.
4. Check the 279 pp 1484-F is really complete.
5. Clean up 2021 residue (~450 MB of PNG renders, test PDFs, venv).
