# The machine

Kaypro 4, '84 series ("4/84"): board **81-184 rev B**, Z80A at 4 MHz, CP/M 2.2,
boot ROM 81-292-A. Primary source: the [schematic](schematic.md) (NLS drawing 81-185).
The Kaypro 10 shares the '84 universal board (Jaapie). The 1983 K10 ROM v7A source
predates that board, so its port and CRTC values don't apply here.

Related pages: [I/O map](io-map.md) · [video](video.md) · [keyboard](keyboard.md) ·
[schematic and IC list](schematic.md) · [ROM reference](rom-reference.md) ·
[ROM explainer](rom-explainer/index.html)

## Core

| Item | Detail |
|---|---|
| CPU | Z80A (U43), 4 MHz, T-state = 250 ns |
| Boot ROM | U34, 81-292 in a 2764 (8 KB). Rev B ties 2764 pins 1 and 27 to +5 V. |
| DRAM | 8× 2164 (64K×1) = 64 KB |
| U29 (81-194) | Gate array: clock division (16 MHz → 4 MHz CPU, 2 MHz, 1 MHz, **4800 Hz keyboard baud clock**), DRAM address mux and RAS/CAS, ROM/RAM bank select (pin 22 ROM, pin 21 RAM, from BANK + A15). **Refreshes DRAM itself; Z80 /RFSH unused**, so long /BUSRQ holds are safe. |
| U10 (81-189) | Gate array: video timing from an **18.000 MHz** crystal, character shift, attributes, CPU↔VRAM access sync |
| CRTC | U16 6545A. VRAM is addressed only through it (see [video](video.md)). |
| Serial | Two Z80A SIOs (U11, U17), WD1943/COM8116 baud generator (U24) |
| Parallel | Latched output at 0x18, J5 |
| PIO | U35 Z80A PIO: drives RTC addressing and the modem dialer |
| RTC | U36 MM58167A, battery-backed (3 V BT1), 32.768 kHz crystal |
| Modem | U18 TMS99532 (300 baud) + U19 TMS99531 dialer; see [below](#internal-modem) |
| FDC | U44 1793 with U67 FDC9216 data separator |
| Interrupts | IM2 daisy chain U11 → U17 → U35 |
| Terminal | ADM-3A-compatible escapes plus Kaypro extensions (attributes ESC G/H, reverse ESC j/k, graphics ESC p); an alternate character set (Greek) via escape |

## I/O
Full table: [io-map.md](io-map.md). Summary:

| Port | Device |
|---|---|
| 0x00 | Baud rate fA (serial port) |
| 0x04 / 0x06 | RS-232 data / control (SIO1 A) |
| 0x05 / 0x07 | **Keyboard** data / control (SIO1 B) |
| 0x08 | Baud rate fB (SIO2) |
| 0x0C / 0x0E | Serial printer data / control (SIO2 A) |
| 0x0D / 0x0F | **Modem** data / control (SIO2 B) |
| 0x10–0x13 | FDC |
| 0x14 | System port |
| 0x18 | Parallel printer data |
| 0x1C–0x1F | Video (6545 via U10) |
| 0x20–0x23 | PIO (port A = RTC address, port B = dialer) |
| 0x24 | RTC data |
| 0x80–0xFF | J9 header |

[`kaypro.h`](../projects/bios-c/kaypro.h) has the SIO and baud-generator ports wrong. See
[io-map § what was wrong](io-map.md#what-was-wrong-before).

## Keyboard
8049-based, 300 baud 8N1 TTL, ASCII plus keypad/cursor codes, no make/break.
See [keyboard](keyboard.md).

## Internal modem
- **TMS99532** single-chip **Bell 103** 300-baud FSK modem, 4.032 MHz crystal, on SIO2
  channel B (port 0x0D).
  - SIO **DTR → A/O**: answer/originate select, so it can **answer as well as originate**.
  - SIO **RTS → SQT** (squelch/transmit).
  - SIO **DCD** = carrier detect.
  - SIO **CTS = ring detect**, from the 4N35 optoisolator and LM324 on the line side.
- **TMS99531** dialer on PIO port B (0x21): digit lines, **tone or pulse** (TT/P), dial strobe.
- Line side: transformer, LM324 TX/RX filtering, hook relay, RJ jack J6 (TIP/RING).
- BIOS default modem rate (`EA47h` in K10 CP/M 2.2F) is code `05h` = 300 baud.
- The old `todo` idea "replace internal modem with ESP8266" exists only as a hello-world
  stub (`kaypro_esp/main.py`, not in git).

## J9: 50-pin hard disk header
8-bit I/O expansion in 0x80–0xFF: BD0–7, BA0–7, /IORQ, /M1, /RD, /WR, /RST, /WAIT,
HD CTRL RST, 4 MHz clock. **No /INT, /BUSRQ, /BUSACK, /MREQ or upper address lines.**
Full pinout: [io-map § J9](io-map.md#j9-50-pin-hard-disk-header-pinout).
- I/O timing is relaxed: the automatic I/O wait state leaves a few hundred ns from
  /IORQ+/RD to data sampling at T3.
- /WAIT on J9 joins an open-collector node already used by the video and RTC logic.

## J1: monitor connector
Separate TTL-level signals, each through a 7406 open-collector with a pull-up:
- J1-3 **VIDEO**: a 3-level signal. U10's VIDOUT and VIDHLF (half intensity) are summed
  through 150 Ω / 300 Ω.
- J1-1 **HSYNC**, J1-4 **VSYNC** (300 Ω pull-ups).

## Power harness
- Mainboard power connector: **AMP 87025-7** (MATE-N-LOK, 7-position). Mating plug
  housing **AMP 1-480702-0**; pins **AMP 350078-4** (18–22 AWG) or **350689-4** (14–18 AWG).
- Supplies on the board: +5 V, +12 V, −12 V. −5 V for the modem is made locally (MC79L05).
- Old `todo` idea: replace the PSU with ATX.

## Electrical rules for anything attached
- **NMOS Z80 outputs only guarantee ≈2.4 V high.** 74HC inputs want ≈3.15 V at 4.5 V.
  Use **74HCT** (or LS/ACT) on the CPU side of any interposer.
- Anything driving **/WAIT** must be open-collector.
- 5 V → 3.3 V (Pico side): 74LVCH245 plus 100 Ω series resistors works (Kaypro10Video).
- Bring-up: current-limited bench supply, series Schottky or polyfuse, ZIF sockets for irreplaceable parts.

## Other ideas from the old `todo`
Compact Flash instead of the floppy controller (Arduino FDD emulator, or ROM mod), RAM
disk (now [Pico board](../projects/pico-board.md)), 8048 → Arduino keyboard with PS/2/USB/Bluetooth.

## Unresolved
- Edge connector part number for the video board (asked once, never found; this board has
  video on the mainboard, so it may refer to an '83 machine).
