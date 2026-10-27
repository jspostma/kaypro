> Imported 2026-10-27 from `kaypro_keyboard`. Machine-generated from firmware analysis; verify against the board before building a replacement.

# M5L8049 Pinout — Kaypro-10 Keyboard Controller

Derived from firmware analysis of `KAYPRO-10_M5L8049.BIN`.  
**Replacement approach:** daughterboard in the DIP-40 socket. Serial to the Kaypro computer
is handled entirely on the daughterboard — only the key matrix and buzzer pins on the socket
matter.

> Pin positions follow the standard Intel 8049 DIP-40 layout; the M5L8049 is a pin-for-pin
> second source. Verify uncertain positions (pins 29, 38–39) against the Mitsubishi datasheet
> if needed, though none of those are in the active set below.

---

## DIP-40 Pinout Diagram

Pins marked **[CONNECT]** need traces on the daughterboard.  
Pins marked **[TIE]** need to be pulled to a fixed level.  
Everything else can be left unconnected.

```
                  ┌────┬──────────────┬────┐
          T0  NC ─┤  1 │              │ 40 ├─ VCC (+5V)       [POWER]
        XTL1  NC ─┤  2 │              │ 39 ├─ NC / PROG
        XTL2  NC ─┤  3 │              │ 38 ├─ T1         NC
       RESET  NC ─┤  4 │              │ 37 ├─ P10   COL0 [CONNECT]
        /INT  NC ─┤  5 │  M5L8049    │ 36 ├─ P11   COL1 [CONNECT]
    EA → VCC  ────┤  6 │  (DIP-40)   │ 35 ├─ P12   COL2 [CONNECT]
         /RD  NC ─┤  7 │              │ 34 ├─ P13   COL3 [CONNECT]
       /PSEN  NC ─┤  8 │              │ 33 ├─ P14   COL4 [CONNECT]
         /WR  NC ─┤  9 │              │ 32 ├─ P15   COL5 [CONNECT]
         ALE  NC ─┤ 10 │              │ 31 ├─ P16   COL6 [CONNECT]
    DB0  ROW0 ────┤ 11 │              │ 30 ├─ P17   COL7 [CONNECT]
    DB1  ROW1 ────┤ 12 │              │ 29 ├─ NC / PROG
    DB2  ROW2 ────┤ 13 │              │ 28 ├─ P27  BUZZER [CONNECT]
    DB3  ROW3 ────┤ 14 │              │ 27 ├─ P26  MUX/EN [CONNECT]
         DB4  NC ─┤ 15 │              │ 26 ├─ P25  BUZ-MOD [CONNECT]
         DB5  NC ─┤ 16 │              │ 25 ├─ P24        NC
         DB6  NC ─┤ 17 │              │ 24 ├─ P23        NC
         DB7  NC ─┤ 18 │              │ 23 ├─ P22        NC
 VDD → VCC   ─────┤ 19 │              │ 22 ├─ P21        NC
         GND ─────┤ 20 │              │ 21 ├─ P20        NC
                  └────┴──────────────┴────┘
```

---

## Pins to Connect on the Daughterboard

### Key matrix — row select (MCU outputs)

| DIP pin | Signal | Function |
|---------|--------|----------|
| 11 | DB0 | Row address bit 0 → mux/decoder input A0 |
| 12 | DB1 | Row address bit 1 → mux/decoder input A1 |
| 13 | DB2 | Row address bit 2 → mux/decoder input A2 |
| 14 | DB3 | Row address bit 3 → mux/decoder input A3 |

The firmware cycles R2 from 0 to 14, writing it onto DB3:0 before each P1 read. Your MCU
outputs the current row index (0–14) on these four pins before sampling the columns.
15 rows × 8 columns = 120 key positions.

### Key matrix — column enable (MCU output)

| DIP pin | Signal | Function |
|---------|--------|----------|
| 27 | P26 | Mux / decoder enable. Firmware drives this LOW at init and never changes it. Drive LOW permanently, or use it as an active-low scan-enable if your timing needs it |

### Key matrix — column sense (MCU inputs)

| DIP pin | Signal | Function |
|---------|--------|----------|
| 37 | P10 | Column 0 — active low (0 = key pressed) |
| 36 | P11 | Column 1 |
| 35 | P12 | Column 2 |
| 34 | P13 | Column 3 |
| 33 | P14 | Column 4 |
| 32 | P15 | Column 5 |
| 31 | P16 | Column 6 |
| 30 | P17 | Column 7 |

Enable pull-ups on your MCU's input pins; the original chip used its quasi-bidirectional
ports in high-impedance mode with internal weak pull-ups.

### Buzzer (MCU outputs)

| DIP pin | Signal | Function |
|---------|--------|----------|
| 28 | P27 | Main buzzer drive. Original firmware toggles this as a square wave via the timer ISR (bell = continuous toggle, idle = HIGH). On the original board this pin also fed the serial line to the Kaypro — see note below |
| 26 | P25 | Buzzer modulation / envelope. Toggled at a lower rate to shape the bell tone. Can be ignored if you drive the buzzer directly from your own code on P27 |

**P27 / serial note:** On the original PCB, P27 likely has two destinations — the buzzer
transducer and the Kaypro serial connector. Your daughterboard drives P27 (pin 28) for the
transducer. Your serial TX to the Kaypro comes from a separate MCU GPIO routed directly to
the serial connector, not through the DIP socket. Trace the P27 net on the board to confirm
both destinations before finalising your connector routing.

---

## Pins to Tie Off

| DIP pin | Signal | Tie to | Reason |
|---------|--------|--------|--------|
| 6 | EA | VCC | Selects internal ROM — irrelevant for replacement, but prevents floating |
| 19 | VDD | VCC | Programming voltage; only matters for 8748 EPROM. Tie to VCC |

---

## Everything Else — Leave Unconnected

| Pins | Signals | Why unused |
|------|---------|------------|
| 1 | T0 | Appears only in data table regions, not in active code |
| 2, 3 | XTL1, XTL2 | Your MCU has its own clock |
| 4 | RESET | Your MCU has its own reset |
| 5 | /INT | Host wake signal — serial is now on the daughterboard |
| 7–10 | /RD, /PSEN, /WR, ALE | External memory bus — not used |
| 15–18 | DB4–DB7 | DB4 was a host handshake bit; DB5–7 always driven LOW. All obsolete |
| 21–25 | P20–P24 | Host serial/handshake inputs — obsolete |
| 29, 38, 39 | NC/PROG | No-connect on mask ROM variant |
| 38 | T1 | Was serial RX from host — now handled on daughterboard |

---

## Summary: Active GPIO Count

| Function | MCU pins needed |
|----------|----------------|
| Row select (DB0–DB3) | 4 outputs |
| Column sense (P10–P17) | 8 inputs (with pull-ups) |
| Mux enable (P26) | 1 output, drive LOW |
| Buzzer (P27) | 1 output |
| Buzzer modulation (P25) | 1 output *(optional)* |
| Serial TX to Kaypro | 1 output *(not a DIP socket pin — goes direct to connector)* |
| **Total socket pins** | **14** (or 13 without P25) |

---

## Key Matrix Topology

```
  MCU                  original board ICs
  ────                 ──────────────────
  DB0–DB3 (4 bits) ──► hex inverter ──► mux ──► ROW 0
                                              ──► ROW 1
                                               ...
                                              ──► ROW 14   (15 rows total)
  P26 (LOW) ──────────────────────────► mux /EN

                                        key switches
                                             │
  P10–P17 (8 inputs) ◄─────── COL0–COL7 ◄──┘

  Active low throughout: 0 = pressed, 1 = released.
```