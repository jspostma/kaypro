# Video

## Signal chain

```
6116 char VRAM ─┐
                ├─► char ROM (2732) ─► shift register ─► attribute logic ─► CRT
6116 attr VRAM ─┘        ▲                                    ▲
                     RA (scanline)                     attributes, CURSOR
6545 CRTC ── MA, RA, HSYNC, VSYNC, DE, CURSOR, CCLK
```

Attributes (inverse, half-intensity, underline, blink) and the cursor are applied
**after** the char ROM.

## Measured timing (Kaypro 10, SY6545; from Kaypro10Video)

| Signal | Value | Notes |
|---|---|---|
| CCLK | ~1.286 MHz | character clock |
| HSYNC | ~21 kHz | high = 3 µs blanking, low = 43 µs active |
| VSYNC | ~49 Hz | active low |
| DE | | active high during active video |
| Lines | 400 active | 25 rows × 16 scanlines |

**Doesn't add up:** 1.286 MHz × 43 µs ≈ 55 characters, but 80 columns needs 80.
Either CCLK is closer to 1.86 MHz or that firmware captures a truncated window
(it uses 56 bytes per line). **Scope CCLK and DE width on this machine.**

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
1. **No attributes, no cursor.** Add taps for attribute VRAM data out (8 lines) and CRTC
   CURSOR (1 line). Without them, inverse-video menus (WordStar) and the cursor are invisible.
2. **The 56-byte window** (see above).
3. **The AND filter** kills blink and adds a frame of latency. Make it optional.
4. **Check 4/84 parts and clearance:** char ROM type (2732 vs 2716), U-numbers, piggyback stack height.

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
