# Video

## Signal chain (from the [schematic](schematic.md), sheet 2B)

```
6545 U16 ── MA0–10 ──► U23 6116 char VRAM ─► U8 74LS374 ─► U9 2732 char ROM (A4–A10)
         │                                            RA0–3 ─► U9 A0–A3
         │                                    A12CH (sys port) ─► U9 A11 (char set)
         └─ MA0–10 ──► U15 6116 attr VRAM ─► U20 74LS245 ─► U10 D0A–D3A (4 attr bits)
U9 O0–O7 (glyph row) ─► U10 Q0D–Q7D ─► shift + attributes + CURSOR ─► VIDOUT, VIDHLF
U10 81-189: 18.000 MHz crystal → dot clock, CCLK to the 6545
CPU D0–7 ─► U14/U13 74LS373 latches ─► VRAM data side (no CPU address path to VRAM)
```

- **The VRAMs are addressed only by the 6545's MA lines.** The CPU has no address path to
  them. It reaches video RAM through the 6545 (update/transparent addressing) and the
  U13/U14 data latches, under U10's control, with /WAIT (VIDWAIT) while it waits.
  So `VRAM_BASE 0xF000` in `kaypro.h` (the memory-mapped '83 model) is wrong for this board.
- **Attributes are 4 bits** (D0A–D3A into U10): reverse, half intensity, underline, blink
  presumably; confirm the bit order from the ROM.
- The char ROM's top address line comes from **A12CH**, a system-port bit, which selects
  the alternate (Greek/graphics) character set half. Inferred from the net name.
- Glyph rows go *into* U10, which does the shifting and attribute logic. U60 (74LS195) is
  elsewhere.
- Monitor: J1-3 VIDEO is 3-level (VIDOUT + VIDHLF summed through 150/300 Ω);
  HSYNC J1-1 and VSYNC J1-4 are separate. All are 7406 open-collector.

## Measured timing (Kaypro 10, SY6545; from Kaypro10Video)

| Signal | Value | Notes |
|---|---|---|
| CCLK | ~1.286 MHz | character clock |
| HSYNC | ~21 kHz | high = 3 µs blanking, low = 43 µs active |
| VSYNC | ~49 Hz | active low |
| DE | | active high during active video |
| Lines | 400 active | 25 rows × 16 scanlines (confirmed by the ROM's CRTC table below) |

**Their CCLK figure doesn't add up:** 1.286 MHz × 43 µs ≈ 55 characters, but 80
columns needs 80. That firmware also captures only 56 bytes per line.

## What the 292 ROM programs into the 6545

From the CRTC init table at 0x76D in 81-292-A (via the [ROM explainer](rom-explainer/index.html)):

| Reg | Value | Meaning |
|---|---|---|
| R0 | 0x6A | 107 character clocks per line |
| R1 | 0x50 | 80 displayed |
| R2 | 0x56 | HSYNC at char 86 |
| R3 | 0x99 | sync widths |
| R4 | 0x19 | 26 character rows total |
| R5 | 0x0A | +10 scanlines adjust |
| R6 | 0x19 | **25 rows displayed** |
| R7 | 0x19 | VSYNC at row 25 |
| R9 | 0x0F | **16 scanlines per row** |

So lines per frame = 26 × 16 + 10 = **426**, of which 400 are visible.

Check against the measurements: 21 kHz / 426 = **49.3 Hz**, which matches the measured
~49 Hz. The table is right and the HSYNC measurement is right.

Then **CCLK = 107 × 21 kHz ≈ 2.25 MHz**, not 1.286 MHz. Active video is 80 / 2.25 MHz ≈
35.6 µs of a 47.6 µs line. At 8 px/char that implies an 18 MHz dot clock, and the
schematic confirms it: **Y1 on U10 is 18.000 MHz**. So the Kaypro10Video window constants (56 bytes, 43 µs)
are probably wrong for this board, or that firmware samples on a divided clock. The
25th row's use is unconfirmed (`kaypro.h` assumes 24 for CP/M). **Confirm on the scope: CCLK ≈ 2.25 MHz, DE high ≈ 35.6 µs.**

The ROM explainer's "K10" CRTC values (R9 = 0x07, 8 scanlines; R0 = 0x78; R4 = 0x1F)
give ~15.7 kHz NTSC-like timing. They come from the 1983 K10 ROM v7A source, i.e. the
pre-universal-board K10, and don't apply to this machine.

## Composite (CVBS) output: don't

21 kHz / 49 Hz is far from NTSC (15.734 kHz / 59.94 Hz). Cheap decoders (MS2109 dongles,
TVP5150-class) tolerate only a few percent, so a composite feed won't lock.

Kept for reference in case it's ever needed for an NTSC-timed source: summing logic-level
sync and video into 75 Ω, solved for sync 0 V, black 0.3 V, white 1.0 V at 5 V logic,
gives **Rs ≈ 1 kΩ (from CSYNC_n), Rv ≈ 430 Ω (from VIDEO)**. Source impedance is ≈300 Ω
(fine for short cables; add an emitter follower or a THS7316 plus 75 Ω for proper
matching). Composite sync from active-low H and V: `CSYNC_n = H_n AND V_n`.

## Digital capture: Kaypro10Video

<https://github.com/jasperhax0r/Kaypro10Video> (MIT). Passive, no board mods.

- **Taps:** a piggyback shim on the 6545 (HSYNC, CCLK, VSYNC, DE) and a piggyback socket
  on the char ROM (D0–D7). Dual SN74LVCH245 (5 V→3.3 V) with 100 Ω series resistors.
  Shim traces under 40 mm.
- **Pico:** PIO samples char ROM data on CCLK edges, HSYNC-locked, with DMA armed per line.
  Double-buffered 400 × 56 byte frames. Temporal filter ANDs each frame with the previous
  one. USB serial debug.
- **Output:** UART at 3 Mbaud to a Pi Zero 2W running Circle bare-metal, giving HDMI at
  about 12 fps with color modes, scanlines and a rotary encoder.

Because it samples the glyph row byte **before** the shift register, latched on the
character clock, it needs **no dot clock and has no pixel-phase problem**. The pixels are
exact by construction.

### Gaps for using it as a screen reader
1. **No attributes, no cursor.** Add taps for the 4 attribute lines (U15/U20 D0A–D3A,
   or U10 pins 1, 37–39) and CRTC CURSOR (U16 pin 19 → U10 pin 36). Without them, inverse-video menus (WordStar) and the cursor are invisible.
2. **The 56-byte window.** This machine needs 80 bytes per line at a ~2.25 MHz CCLK (see above).
3. **The AND filter** kills blink and adds a frame of latency. Make it optional.
4. **4/84 parts:** char ROM is **U9, 81-235 (2732)**, CRTC is U16. Check piggyback stack height.
5. **Simpler alternative tap point:** VIDOUT/VIDHLF at J1 plus HSYNC/VSYNC, sampled at
   18 MHz (a PIO can do it), gives the composed image including attributes and cursor, but
   needs dot-phase alignment, which the char-ROM tap avoids.

### Planned adaptation
- Drop the Pi Zero/HDMI half. Have the Pico send frames over USB (CDC with RLE, or UVC so
  it shows up as `/dev/videoN`, the same as a webcam).
- **Text decode is a dictionary lookup:** each cell's 16 row-bytes match exactly against a
  dump of the same char ROM. That gives a perfect text grid.
- It occupies the **same socket as the planned char ROM shadow** ([Pico board](../projects/pico-board.md)).
  Merge the capture into that board rather than stacking two.
- The VRAM dual-port interposer would be a better oracle (codes *and* attributes, no
  reconstruction). Kaypro10Video is the buildable-now option.

## Related projects (other machines, same technique)
- EBD_IPKVM: Pico framebuffer capture for the Lisa through the SE/30, with ADB on the same Pico (a KVM). RLE takes a ~21 KB frame to ~1 KB.
- guruthree/mac-se-video-converter: Mac SE video to VGA or mono composite.
- holmatic/video_if_ql_vga: Sinclair QL; samples 32 MS/s against a 10 MHz pixel clock (oversampling without a dot clock).

Links in [references](../references.md).
