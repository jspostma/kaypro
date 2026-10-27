# Phone line interface (sound card ↔ Kaypro modem)

Status: **idea**. Jaapie has 600 Ω transformers and TL072/TL074s on hand; it's a
single-sided board, etchable in a few hours.

Part of the [agent](agent.md) modem path: the Kaypro dials, and software on a PC plays the
whole phone company.

## What the modem needs from a "line"
- **Loop current**, ~20–30 mA DC when off-hook. Without it most modems won't seize the line.
- **Dial tone**, unless it can blind-dial. Check whether the Kaypro modem can be set to dial without waiting.
- Something that hears its **dialing** (DTMF or pulse).
- **Ringing** (~90 Vrms) only if the Kaypro answers. If it always originates, skip it.

## Line side (talk battery)
- 24 V supply → TIP and RING through **two current limiters**: an LM317 plus ≈62 Ω each
  (≈20 mA), or ≈470 Ω resistors per leg. Current sources look like a high AC impedance
  and don't load the signal.
- **DC block before the transformer** (cheap 600 Ω audio transformers saturate on DC):
  a non-polar film cap, 1–2.2 µF, ≥100 V.
- **Hook detector:** a PC817 plus a reverse diode in series with the loop. Wire its output
  to a USB-serial adapter's CTS/DCD so pyserial can read it with no microcontroller. It
  also counts pulse dialing.
- The modem has its own bridge, so polarity doesn't matter.

## Audio side (transformer + TL072)
- **TX:** sound card out → TL072 buffer → ≈600 Ω series resistor → transformer secondary.
- **RX:** a difference amp taking the secondary voltage minus half the TX drive. That's the
  classic op-amp **hybrid**, which cancels the local transmit signal.
- Hybrid balance can be sloppy: Bell 103 is frequency-split, so the demodulator filters its
  own echo. A v1 could skip the hybrid.
- Levels: line ≈ −10 dBm (≈0.25 Vrms). RX gain +10–12 dB into line-in. TX ≤ ~0.5 Vrms on the line.
- Supply: the TL072 is unhappy at 5 V. Use ±12 V or 12–15 V single-supply with a virtual
  ground. Keep it separate from the 24 V loop supply so the transformer actually isolates.

## Software (Python)
1. Hook off → play dial tone (350 + 440 Hz).
2. Decode DTMF (Goertzel) or count pulses via the opto. Stop the dial tone on the first digit.
3. The dialed number is a routing key → a TCP destination (BBS, gateway, echo test).
4. `minimodem --tx/--rx 300` (Bell 103) in answer mode, piped to the socket.
5. Hook on → close the socket.

## BOM
24 V supply, 2× LM317 (or 2 resistors), film cap, PC817 plus diode, 600 Ω transformer,
TL072, resistors, RJ11 jack, 3.5 mm in/out jacks, USB-serial adapter.

## Compared with the ATA → Asterisk route
An ATA costs ~$20 used and does all of the line side correctly. This board instead keeps
the dial plan in Python rather than Asterisk config, and uses parts on hand.
