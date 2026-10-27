# Over-the-shoulder agent

Status: **idea** (brainstorm 2026-10-27)

An AI agent that uses the Kaypro the way a person behind the chair would: it reads the
screen, types on the keyboard, swaps disks, resets the machine and dials out on the modem.
It's single-user, single-task, so it works as an over-the-shoulder assistant rather than a
native process.

## Principles (Jaapie's requirements)
- The agent's native environment is locked down to a few tools.
- **It can't create files natively.** Anything it writes, it writes *on the Kaypro*, to
  floppies.
- **No internet from the native environment.** Its only network access is the Kaypro's
  modem, dial-up.
- Hard reset and power control so it can recover the machine and avoid burn-in.

## Two tiers: agent senses vs. harness instrumentation
The conceit only holds if the agent's senses are what a person would have: screen,
keyboard, disk box, power switch. The harness can see more (VRAM or char-ROM capture) and
use it to score OCR, detect screen changes and debug the rig, **as long as it's never an
agent tool**.

## Subsystems

### Keyboard mux
- A microcontroller (Pico) in series between the keyboard and the Kaypro, with a third,
  **galvanically isolated** serial port to the agent host (ADuM-type isolator or an isolated USB-UART).
- The keyboard ([details](../hardware/keyboard.md)) is **300 baud 8N1, 5 V TTL** on a
  4-wire cable: +5 V, K2H (keyboard→host, open-collector, 3.3 kΩ pull-up), GND, H2K
  (host→keyboard, beeper). It sends **ASCII** for main keys and fixed codes for keypad and
  cursor keys (0xB1–0xF4). No make/break or modifier bytes, so muxing is just
  **interleaving bytes**: no key state, no stuck modifiers, no rollover. The agent emits
  the raw keypad/cursor codes, not ASCII escapes.
- Insert the mux in the J2 cable. Two UARTs at 300 baud (keyboard side, host side). Pass
  H2K (bell) through. 300 baud is ~30 chars/s, so the line is never the bottleneck.
- The K2H pull-up is on the host side, so the mux's host-facing TX should be open-collector too.
- **The human always wins:** any physical keystroke pauses the agent's queue for N seconds.
  Add an "agent typing" LED and a physical agent-enable switch that cuts injection in firmware.
- **Pacing is the microcontroller's job.** The agent calls `type(string)` and firmware
  sends it at human speed, since CP/M console input is polled and WordStar/MBASIC drop typeahead.

### Screen
- **Agent's eyes: a webcam** on the CRT.
  - Rectify (homography from the screen corners), sample the 80×25 grid (the CRTC displays 25 rows; what the 25th holds is unconfirmed), template-match
    against glyphs from the dumped char ROM.
  - Lock exposure to a multiple of the frame period (at ~49.3 Hz, about 20.3 ms) to avoid
    roll banding. Lock focus, gain and white balance.
  - Long-persistence phosphor ghosts on scroll, so use a settle detector (frame diff below
    a threshold for ~200 ms) before decoding.
  - Attributes (inverse, half-intensity, underline, blink) need extra templates; blink needs two samples.
- **Ground truth: digital capture** ([video](../hardware/video.md)), harness-side only.
- Tools: `screen()` returns the text grid plus cursor (cheap, ~2k chars).
  `screen_image()` is on demand. `wait_for_change(timeout)` avoids polling turns.

### Disks (Gotek)
The Gotek's I2C header is for its OLED, not control. Options:
- **Fake USB stick:** a Pi Zero 2 (or similar) as a USB mass-storage gadget plugged into
  the Gotek. The harness owns the backing image, swaps disk sets, and re-plugs the gadget
  so FlashFloppy rescans. It also gives the **harness** read-back of saved disks via
  cpmtools. The agent doesn't get that; it has to show its work on screen or send it over the modem.
- **Button emulation:** optocouplers across prev/next, FlashFloppy in indexed mode
  (`DSKA0000.IMG`…). Dumb but reliable.
- Tools: `disks.list()`, `disks.insert(name)`, `disks.blank(label)`, `disks.eject()`.
  Blank disks are formatted template images the harness copies.

### Reset and power
- **Reset:** an optocoupler transistor across the reset switch. No relay needed, and it keeps isolation.
- **Power:** a properly rated SSR/relay on mains. Policy lives in **firmware, not the agent**:
  minimum off time (~10 s), maximum cycles per hour, refuse power-off during a disk write
  (Gotek activity LED or drive select as a busy signal).
- Burn-in: an idle timeout makes the agent save state, then power-off. Turning brightness down is free.

### Modem
The internal modem is a **TMS99532** Bell 103 chip on SIO2 ch B (port 0x0D), with a
**TMS99531** tone/pulse dialer on the PIO ([machine § modem](../hardware/machine.md#internal-modem)).
Bell 103 FSK: originate 1070/1270 Hz, answer 2025/2225 Hz. DTR selects answer/originate,
so the Kaypro can also **answer** calls, and ring detect is on CTS. The dialer does both
DTMF and pulse, so the far end can decode either. That survives G.711 VoIP fine, unlike V.32+. Options, best first:
1. **ATA (FXS) → own Asterisk → softmodem.** Third-party `app_softmodem` (Bell 103/V.21/V.23/V.22bis)
   answers and bridges to TCP. The ATA supplies dial tone, loop current and DTMF.
   No Digium cards, no Twilio. Force G.711 and turn off VAD, comfort noise and echo cancellation.
2. **ATA → Asterisk → minimodem** process. More DIY.
3. **Twilio → a real dial-up provider.** Questionable: who answers at 300 baud? Most ISPs
   want V.34+/V.90, which VoIP mangles. A few hobbyist BBSes still have phone lines.
4. **Home-built line interface → sound card.** See [phone line interface](phone-line-interface.md).
   This is the parts-on-hand option.

Whatever answers the call is **the egress firewall**: the TCP end it connects to *is*
the agent's internet (curated BBS list, text-mode web proxy, own services). The native host
reaches only the model API.

## Agent tool surface
`screen`, `screen_image`, `wait_for_change`, `type`, `key` (ctrl/esc/arrows), `disks.*`,
`reset`, `power`, `status`. No filesystem, shell or fetch. Run it in a container/VM whose
only egress is the API endpoint, with the isolated serial port and camera passed through.

Side effect: no scratch notes except context. For long sessions it has to keep a
`NOTES.TXT` on a Kaypro disk and re-read it.

## Build order
1. **Emulator first.** Build the whole tool API and agent loop against an emulator (MAME
   is scriptable via Lua: key injection, frame grabs), with a folder of disk images
   standing in for the Gotek. See the agent's real failure modes before soldering.
2. Keyboard mux plus isolated port (replaces emulator key injection).
3. Camera OCR (replaces the emulator framebuffer), validated against known screen contents.
4. Reset/power optos and relay.
5. Gotek control.
6. Modem path ([phone line interface](phone-line-interface.md) or ATA → Asterisk).

Steps 2–5 could share hardware with the [Pico board](pico-board.md).

## Open questions
- What is it actually *for*? Writing programs (MBASIC, Turbo Pascal), BBS-ing, or a character that lives in the machine?
- Keyboard baud rate (read the archive's keyboard USB project notes; otherwise scope it).
