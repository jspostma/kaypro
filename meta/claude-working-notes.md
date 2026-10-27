> **Historical (imported from `kaypro_stuff`, 2026-10-27).** Paths and the Gitea remote below describe the old local repo, not this one. The merged result is [`/CLAUDE.md`](../CLAUDE.md).

# Working with Claude on this Project — Reference Notes

This file is for your reference only. It documents the behavioral preferences and
working patterns established over multiple sessions, explains where each type of
context lives, and notes what should go in a CLAUDE.md vs what belongs in memory.

---

## How context layers work

| Layer | File(s) | Who writes it | When it loads | Best for |
|---|---|---|---|---|
| **CLAUDE.md** | `CLAUDE.md` in repo root | You | Every session, automatically | Hard rules, project orientation, navigation pointers — stable, human-authored |
| **Memory files** | `~/.claude/projects/.../memory/` | Claude (auto) | Every session, automatically | Accumulated context, discovered facts, working style — evolves over time |
| **Conversation** | Session history (`--resume`) | Both | Only when resumed | Full detail of a specific working session — lossy when compressed |
| **Repo docs** | `master_contents.md`, etc. | Both | On demand (Claude reads them) | Source of truth for project content — not instructions |

**The separation principle:** CLAUDE.md tells Claude *how to navigate and what rules apply*.
Memory files tell Claude *what has been learned*. Repo docs contain the actual content.
Don't put archive inventory in CLAUDE.md; don't put behavioral rules in `master_contents.md`.

---

## What goes in CLAUDE.md (and what doesn't)

**Include:**
- Project orientation — what this is, who it's for
- Navigation pointers — which files to read first and why
- Repository structure — what's in git, what's symlinked, what's excluded
- Hard constraints — things Claude must never do (add binaries to git, touch printer/, etc.)
- Environment facts — tool locations, mount flags, remote URL
- Subproject list — brief description + pointer to the notes file

**Don't include:**
- Behavioral style preferences — terseness, commit frequency, pace (→ memory)
- Accumulated technical facts — U29 ASIC details, DPB values, port addresses (→ memory + repo docs)
- Working session state — current task, in-progress work (→ conversation / tasks)
- Archive inventory details — what files exist where (→ master_contents.md)

---

## Behavioral preferences established in this project

These live in memory files and don't need to go in CLAUDE.md, but are documented
here so you can verify Claude is following them and update them if your preferences change.

**Pace:** One step at a time. Check in before large changes. Don't batch up sweeping
reorganisations without confirmation.
*Memory file: `feedback_working_style.md`*

**Commits:** Commit and push after any meaningful batch of changes. Repo is treated
as a backup.
*Memory file: `feedback_working_style.md`*

**Memory:** Save memories proactively — discovered facts, decisions made, project
milestones. Stay factual; don't speculate. Update existing memories rather than
duplicating.
*Memory file: `feedback_memory_approach.md`*

**Responses:** Terse is fine. No preamble, no trailing summaries. Lead with the result.
*Memory file: `feedback_working_style.md`*

**C/embedded framing:** Frame hardware concepts in AVR analogues where helpful
(user knows AVR register patterns well).
*Memory file: `user_profile.md`*

**Archive files:** Never add to git. Never delete without explicit instruction.
*Memory file: `feedback_working_style.md`*

**Printer folder:** Separate project, separate repo. Ignore in this context.
*Memory file: `feedback_working_style.md`*

---

## Memory files — current index

Located at `~/.claude/projects/-home-jaapie-projects-kayprostuff/memory/`:

| File | Contents |
|---|---|
| `MEMORY.md` | Index — loaded first, points to all others |
| `user_profile.md` | Who you are, background, working style |
| `project_kaypro.md` | Current project state, active subprojects, archive status |
| `technical_kaypro_hw.md` | Key hardware facts (U29 ASIC, port map, DPB, scratch RAM, etc.) |
| `feedback_memory_approach.md` | How aggressively to save memories and why |
| `feedback_working_style.md` | Pace, commits, response style, constraints |
| `project_rag_future.md` | Future RAG/knowledge index plan + Marker install notes |
| `project_tech_manual.md` | Tech manual subproject status |

---

## Comparing the two CLAUDE.md styles

**Direct (`claude-sample-direct.md`)** — second-person instructions ("You are...", "Read...",
"Do not..."). More reliable for enforcing constraints — Claude treats imperative phrasing
as rules. Can feel prescriptive. Better when you have specific behaviors to mandate.

**Brief (`claude-sample-brief.md`)** — descriptive project brief. More readable for
humans reviewing the file. Relies on Claude inferring appropriate behavior from context.
Better when the goal is orientation rather than rule enforcement.

In practice: use the direct style for constraints that matter (don't touch printer/,
don't add binaries to git) and the brief style for orientation. Mixing both in a single
file is common and works well — hard rules at the bottom as a "Constraints" section,
descriptive context above.

---

## What a final CLAUDE.md for this project might look like

A merged approach:
1. Short project brief (2–3 sentences) — what this is
2. Navigation table — key files and when to read them
3. Repo structure diagram — what's in git vs not
4. Subproject list — one line each with file pointer
5. Environment table — tools, remotes, mount notes
6. Constraints section — direct imperative style for the non-negotiables

Keep it under ~100 lines. CLAUDE.md loads on every session; a very long file wastes
context window on content that rarely changes.
