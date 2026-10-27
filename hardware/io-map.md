# I/O map (Kaypro 4/84, board 81-184)

**Source:** the Non-Linear Systems schematic set 81-185 for board 81-184 rev B
(`kp4_schematic.pdf`, not in git), sheets 2A processor, 2E serial, 2F modem/RTC.
Read from the 74LS138 decoders U26 and U27 and the SIO/PIO B/A and C/D wiring.
This supersedes the port tables in [`kaypro.h`](../projects/bios-c/kaypro.h) and the
ROM explainer, which are wrong (see [below](#what-was-wrong-before)).

## Decode

- **U26** (74LS138): A = A2, B = A3, C = A4. G2A = A7 (active low), G2B = /IORQ-qualified
  strobe (from U40), G1 = A5 through an inverter (U25). It's active for **A7 = 0, A5 = 0**.
- **U27** (74LS138): same A2–A4. Active for **A7 = 0, A5 = 1**.
- **A6 is not decoded**, so 0x40–0x7F mirror 0x00–0x3F.
- **0x80–0xFF are not decoded on the board.** The J9 header's data buffer (U31, 74LS245)
  turns toward the CPU only on an I/O read with A7 = 1, so this half is J9's space.
- Z80 SIOs and the PIO have **B/A = A0, C/D = A1**, so within each 4-port block:
  +0 = A data, +1 = B data, +2 = A control, +3 = B control.

## Ports

| Port | Select | Device | Function |
|---|---|---|---|
| 0x00–0x03 | BAUDA | U24 WD1943/COM8116 | Rate code for **fA**, which clocks SIO1 ch A (J4 serial). Write low nibble. |
| **0x04** | SIOCE1 | U11 SIO ch A data | **J4 RS-232 serial port** |
| **0x05** | | U11 SIO ch B data | **J2 keyboard** (ch B clocked by U29's 4800 Hz = 300 baud ×16) |
| 0x06 | | U11 SIO ch A control | serial port |
| 0x07 | | U11 SIO ch B control | keyboard (RR0 bit 0 = key waiting) |
| 0x08–0x0B | BAUDB | U24 | Rate code for **fB**, which clocks SIO2 via jumpers E14/E15/E8 |
| 0x0C | SIOCE2 | U17 SIO ch A data | **J3 serial printer** |
| **0x0D** | | U17 SIO ch B data | **Internal modem** (U18 TMS99532) |
| 0x0E | | U17 SIO ch A control | printer |
| 0x0F | | U17 SIO ch B control | modem: DTR = answer/originate, RTS = squelch (SQT), CTS = ring detect, DCD = carrier |
| 0x10–0x13 | FDSK.CS | U44 1793 FDC | command/status, track, sector, data |
| 0x14–0x17 | SYS PRT | system port latch | drive select, side, motor, density, ROM bank, char set (A12CH?), etc. |
| 0x18–0x1B | PDATA | latch | **Parallel printer data** (J5) |
| 0x1C–0x1F | VIDCS | U10 81-189 + U16 6545 | CRTC access; U10 sees A0, A1, RD, WR |
| 0x20 | PIOCS | U35 Z80 PIO port A data | **RTC register address** (PA0–PA4 → MM58167A A0–A4); RTC interrupt lines also land on port A |
| 0x21 | | U35 PIO port B data | **Modem dialer** U19 TMS99531 (digits, tone/pulse, dial strobe) |
| 0x22 / 0x23 | | U35 PIO A / B control | |
| 0x24–0x27 | RTCS | U36 MM58167A RTC | RTC data. Register chosen by PIO port A. Battery-backed (BT1, 3 V); 32.768 kHz crystal. |
| 0x28–0x3F | | U27 outputs N/C | unused |
| 0x40–0x7F | | | mirror of 0x00–0x3F |
| 0x80–0xFF | | J9 header | external devices (e.g. hard disk controller) |

## Baud generator
U24 is a **WD1943/COM8116** with a 5.0688 MHz crystal (Y2). Two independent outputs:
fA (serial port) and fB (SIO2 side). The rate is a 4-bit code, not a divisor: code `05h` =
300 baud, which matches KP-CBOOT's stored defaults. **There is no 8253 on this board.**

## Interrupts
- IM2 daisy chain: SIO U11 → SIO U17 → PIO U35 (IEI/IEO, with a 3.9 kΩ pull-up on the PIO's IEI).
- **/INT is not on J9**; external devices on the header can't interrupt and must be polled.

## /WAIT
Already in use. The modem/RTC sheet drives the Z80 /WAIT through U54 (7406, open
collector) with a 750 Ω pull-up. The logic feeding it appears to combine **VIDWAIT** from
the video section (CPU access to the 6545/VRAM) and the RTC's RDY (through U66). The gate
is cut off at the sheet edge in the scan, so confirm on the board. J9-38 joins the same node. Anything else that drives /WAIT must be
**open-collector**.

## What was wrong before

| Item | Old notes said | Schematic says |
|---|---|---|
| Keyboard data | 0x00 | **0x05** |
| Serial (RS-232) data | 0x01 or 0x02 | **0x04** |
| SIO count | one | **two** (U11, U17) |
| Baud generator | 8253 PIT at 0x04–0x07 | **COM8116 at 0x00 (fA) and 0x08 (fB)** |
| Parallel printer | 0x18 | 0x18 ✓ |
| Modem | "SIO channel B" | SIO2 ch B, **0x0D**; dialer on PIO port B (0x21) |
| RTC, PIO | not mentioned | 0x24, 0x20 |

The period `kaypro.doc` (serial data 4, status 6, keyboard data 5, status 7) was right
about the SIO. Its parallel 8/9 and system status 0x1D entries are probably the '83 layout.
The ROM explainer's K10 hard-disk ports (0x40–0x5F) can't work on this board, since A6
isn't decoded. The K10's decode must differ.

## J9 (50-pin hard disk header) pinout

| Pins | Signal |
|---|---|
| 2, 4, …, 16 | BD0–BD7 (via U31 74LS245, always enabled; direction → CPU on I/O read with A7 = 1) |
| 18, 20, …, 32 | BA7–BA0 (via U28 74LS244, output only) |
| 34 | /IORQ |
| 36 | /M1 |
| 38 | /WAIT (open-collector node, see above) |
| 40 | /RD (gated) |
| 42 | /WR (gated) |
| 43 | /RST |
| 45 | HD CTRL RST (from the system port, via E22) |
| 47, 48 | spare (E20, E21) |
| 49 | B4MHZ clock |
| 50 | key (N/C) |
| odd 1–31 | GND |
| odd 33–41 | tied to the supply symbol on the sheet (+5 V?); check before use |

**Not on J9:** /INT, /BUSRQ, /BUSACK, /MREQ, A8–A15. It's an 8-bit I/O-only port in
0x80–0xFF with /M1 and /WAIT available.
