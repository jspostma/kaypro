# NPU coprocessor

Status: **idea** (2026-10-26). Jaapie: "I just like the idea of a Z80 machine with an AI coprocessor."

A TTL/breadboard-style binarized neural network unit (XNOR / popcount / threshold), driven
by the Kaypro.

## Interface: Am9511 pattern
The AMD Am9511 APU (1977) is the template: an I/O-mapped coprocessor for 8080/Z80.
- **Ports:** command (LOAD_WEIGHTS, LOAD_INPUT, RUN, STEP, READ_OUTPUT), status
  (BUSY, DONE, layer counter), data. Three or four port addresses.
- **Bulk transfer:** OTIR/INIR (~21 T-states/byte), or map the weight SRAM into a memory window and use LDIR.
- **Completion:** IM2 interrupt, or poll BUSY. A halt-on-layer mode lets you step it from CP/M.
- **Hook-up:** the [CPU interposer](pico-board.md) exposes the full bus (address decode,
  IORQ, INT). Simplest loader: the parallel printer port (latched 8-bit plus strobe) for
  weights, serial for reading back.

## Hardware on hand
~10× 2K dual-port SRAM (CY7C136-family; delay line, weights, ping-pong activations,
output), 8-bit parallel ADCs, GALs. A 35-input digit classifier is ~720 weights, one EEPROM.

## Training on a 4 MHz Z80
- Digits/XOR: feasible. Software floats (Turbo Pascal 6-byte reals, MBASIC) run at a few
  thousand FLOPS, so backprop takes hours to overnight. 16-bit fixed point, or the integer
  perceptron rule, takes minutes.
- Audio nets: not on the Kaypro. Do human-in-the-loop evolutionary search instead (mutate,
  listen, keep or revert, save presets to floppy). The audio effect is a **separate project**.

## Demo
Draw a glyph in a character cell with the cursor keys; the coprocessor classifies it.
The display's native cell format is the network's input format, which ties into the
char-ROM shadow work.
