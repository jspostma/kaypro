# Keyboard

Detachable keyboard with its own MCU, on a 4-wire modular cable to J2 on the mainboard.
Jaapie's goal for the keyboard ROM work: reverse-engineer the controller (300 baud serial,
drives a buzzer for the bell).

## Electrical (third-party RE, [protocol.md](keyboard/protocol.md))

| Jack wire | Signal |
|---|---|
| 1 yellow | +5 V (~150 mA) |
| 2 green | **K2H**: keyboard → host serial |
| 3 red | GND |
| 4 black | **H2K**: host → keyboard (beeper control) |

- **5 V TTL, 300 baud, 8N1.**
- K2H is open-collector with a 3.3 kΩ pull-up. H2K goes into a 7406 input with a 3.3 kΩ pull-up.
- On the mainboard: SIO1 (U11) channel B at **port 0x05** (data) / **0x07** (control),
  clocked at 4800 Hz = 300 baud × 16 from U29. J2 passes through 74LS14 Schmitt
  inverters (U2). See the [I/O map](io-map.md).

## What it sends
- **ASCII for everything on the main keys.** CTRL+key gives 0x00–0x1F; SHIFT/CTRL/CAPS
  send nothing by themselves. Caps lock and its LED are handled inside the keyboard.
- **No make/break, no modifier state.** One byte per keypress.
- Keypad and cursor keys send codes the ROM translates (table at 0x183 in 81-292-A):

| Code | Key | Code | Key |
|---|---|---|---|
| 0xB1 | keypad 0 | 0xD0–0xD2 | keypad 4–6 |
| 0xB2 | keypad . | 0xD3 | keypad , |
| 0xC0–0xC2 | keypad 1–3 | 0xE1–0xE3 | keypad 7–9 |
| 0xC3 | keypad ENTER | 0xE4 | keypad − |
| 0xF1–0xF4 | cursor up/down/left/right | | |

Implications for the [agent keyboard mux](../projects/agent.md#keyboard-mux): byte
interleaving at 300 baud (~30 chars/s max) is enough. Inject the raw codes above for
keypad and cursor keys. Pass host→keyboard bytes through so the bell still works.

## Controller
- K10 keyboard: **Mitsubishi M5L8049** (8049 clone), 2 KB mask ROM, 128 B RAM, 6 MHz.
  KII keyboard: **8048**, 1 KB ROM. Both ROMs are dumped (binaries outside git).
- Serial TX is **bit-banged** from the timer ISR.
- 15 rows × 8 columns = 120 positions. The row index goes out DB0–DB3 to a decoder
  (enable P26 low); columns are read on P10–P17, active low.
- Buzzer: P27 square wave from the timer ISR, P25 envelope. The bell sequence ends in a
  full firmware restart.

Analysis files (machine-generated, unverified):
[ROM explained](keyboard/8049-rom-explained.md), [pinout / replacement notes](keyboard/8049-pinout.md),
disassemblies [K10](keyboard/kaypro10-8049.lst) and [KII](keyboard/kaypro2-8048.lst),
disassembler [dis8049.py](keyboard/dis8049.py).

## Third-party USB conversion
A 2018 plan by someone else: ATmega32u4 (LUFA), 300-baud USART in, synthesize HID
keydown/up plus modifiers. [Notes](keyboard/usb-conversion-notes.md).
Jaapie's old `todo` had a similar idea: an Arduino in place of the 8048 with PS/2/USB/Bluetooth output.

## Open
- Beeper protocol: which host bytes produce which tones. The third-party RE says
  different bytes give different lengths.
- The analysis conflicts on how host bytes reach the 8049 (T1 vs the bus). Check the keyboard board.
