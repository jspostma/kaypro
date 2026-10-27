> Imported 2026-10-27 from Jaapie's `kaypro_keyboard` folder. **Machine-generated analysis of the K10 keyboard ROM; unverified.** Some claims (e.g. host commands read via `INS A,BUS`) conflict with [8049-pinout.md](8049-pinout.md), which says host RX is on T1. Treat as a starting point. Disassemblies: [K10 8049](kaypro10-8049.lst), [KII 8048](kaypro2-8048.lst); tool: [dis8049.py](dis8049.py).

# Kaypro-10 Keyboard Controller ROM — Explained

This document explains what the firmware in `KAYPRO-10_M5L8049.BIN` does, aimed at someone
comfortable with Python but new to bare-metal microcontroller programming.

---

## The chip: Mitsubishi M5L8049

The M5L8049 is an 8-bit microcontroller from the early 1980s, second-sourced from Intel's 8049.
Think of it as a very primitive single-board computer baked into one chip:

- **CPU**: 8-bit, runs one instruction at a time
- **ROM**: 2 048 bytes (2 KB) of read-only program storage — the file you have
- **RAM**: 256 bytes of working memory, addressed 0x00–0xFF
- **No operating system, no filesystem, no heap** — just raw execution

### The "registers" (variables)

Instead of local variables, the CPU has a handful of named 8-bit registers:

| Name | Python equivalent |
|------|------------------|
| `A` (accumulator) | The one register almost every instruction touches; like a temp variable |
| `R0–R7` | Eight general-purpose registers; like `r = [0]*8` |
| `T` (timer) | A hardware counter that ticks on its own |
| `F0`, `F1` | Single-bit flags; like `bool` variables |
| `C` (carry) | A leftover bit from arithmetic/shift operations |

There are actually **two sets** of R0–R7 (called *register banks* 0 and 1). You switch between
them with `SEL RB0` / `SEL RB1`. The interrupt service routine uses bank 1 so it doesn't
clobber bank 0, which the main program uses — the hardware equivalent of saving registers before
calling a function.

### The I/O pins

| Pin group | Direction | Purpose in this keyboard |
|-----------|-----------|--------------------------|
| `P1` | Input | Reads the keyboard matrix rows |
| `P2` | Bidirectional | Bit 5 = buzzer, bit 7 = serial data line; other bits = column drive |
| `BUS` | Output | 8-bit data bus — used here as the 300 baud serial line to the Kaypro computer |
| `T0`, `T1` | Input | Extra test pins used to detect serial line state from the host |

---

## The memory map

The 2 048 bytes break down roughly like this:

```
0x000–0x006   Interrupt vectors + table-lookup helper (6 bytes of code)
0x007–0x0BF   Timer interrupt service routine (serial output + buzzer)
0x0CA–0x0DF   String sender subroutine
0x0E0–0x0EA   ASCII data: "0000 ., <p0"  (a test/startup string)
0x100–0x118   Hardware initialisation
0x119–0x1FF   Main keyboard scan loop + key processing
0x200–0x2FF   Host-command receiver and scan-code dispatcher
0x300–0x3C1   Scan code / character lookup tables
0x3C8         One-shot timer delay helper
0x3D0–0x3E6   Host-data monitor (watches for incoming bytes)
0x400–0x4E6   Scan matching, debounce logic, serial queue management
0x500–0x554   Diagnostic/bell sequence + cross-page table dispatch
0x555–0x7FF   Unused (all 0x00 = NOP)
```

Addresses above 0x554 are filled with `0x00` bytes. The chip reads `NOP` from those. This is
typical of mask ROMs — the manufacturer only programs what they need, and the rest stays erased.

---

## Interrupt vectors: the three entry points

When the CPU resets (power on), it starts executing from **address 0x000**.
But there are two other "magic" addresses the hardware jumps to automatically:

| Address | Trigger |
|---------|---------|
| `0x000` | Reset / power-on |
| `0x003` | External interrupt (`INT` pin) |
| `0x007` | Timer overflow interrupt |

In Python terms this is roughly:

```python
def on_reset():        # 0x000
    ...

def on_external_int(): # 0x003
    ...

def on_timer():        # 0x007
    ...
```

The firmware is clever about these fixed positions. Because reset goes to `0x000` and the INT
vector is at `0x003`, only 3 bytes fit between them. The programmer put exactly two instructions
there:

```asm
0000  MOV A,#FFh    ; load accumulator with 0xFF (all bits 1)
0002  OUTL P1,A     ; drive P1 high — keyboard matrix idle state
0003  JMP L_100     ; << this IS the INT handler — jumps to main init
```

At power-on, execution falls straight through to `0x003` (the INT vector location) and
immediately jumps to the real startup code at `0x100`. The same two bytes serve double duty:
reset init _and_ INT handler.

### The tiny helper at 0x005

```asm
0005  MOVP A,@A    ; read ROM byte at (current 256-byte page + A)
0006  RET
```

`MOVP A,@A` is a special instruction that looks up a byte in the ROM using `A` as an index into
the current 256-byte "page". This 2-instruction subroutine is a standard MCS-48 idiom for
accessing a lookup table — like Python's `table[index]` but restricted to the current
256-byte window of ROM.

---

## The timer ISR: 300 baud serial output (0x007–0x0BF)

This is the most important and most complex part of the firmware. Understanding it explains
almost everything the keyboard does.

### What is "bit-banging"?

Modern microcontrollers have dedicated UART hardware that handles serial communication
automatically. The 8049 does not. Instead, the firmware manually wiggles a single output pin
high and low at exactly the right moments. This is called *bit-banging*.

At 300 baud, each bit lasts about 3.3 milliseconds. The timer is configured to fire an interrupt
regularly. Each time it fires, the ISR checks what bit should be on the wire right now and drives
the pin accordingly.

### Timer ISR structure

```asm
0007  SEL RB1        ; switch to register bank 1
0008  MOV R7,A       ; save accumulator there (like: rb1_r7 = A)
0009  MOV A,#FEh     ;
000B  MOV T,A        ; reload timer (sets how soon the next interrupt fires)
000C  JF1 L_012      ; if F1 flag set: buzzer HIGH
000E  ANL P2,#7Fh    ; else: P2 bit 7 = 0 (serial/buzzer LOW)
0010  JMP L_014
0012  ORL P2,#80h    ; P2 bit 7 = 1 (serial/buzzer HIGH)    L_012:
```

**F1 is the buzzer flag.** When the main code wants to sound the bell, it sets F1. Every timer
tick, the ISR toggles P2 bit 7 based on F1, creating a square wave that drives the buzzer.
This is how an 8049 makes a beep with no audio hardware: software-controlled pin toggling.

### The serial output state machine (R6)

After handling the buzzer pin, the ISR runs a state machine held in register `R6`. `R6` tracks
where in the current byte's transmission the chip is:

```
Bit:  7  6  5  4  3  2  1  0
      └──┴──┘  └──┴──┘  └──┴─┘
      stop/    data         start/
      idle     bits         phase
      flags                 flag
```

In Python, you could picture it as:

```python
# Each timer tick:
if r6 & 0x01 == 0:          # no active transmission
    if T1_pin_is_low():      # host sending a start bit?
        r6 |= 0x01           # enter transmission state
        r5 = 12              # set sub-bit counter
elif r6 & 0x02 == 0:        # waiting for bit sample point
    r5 -= 1
    if r5 == 0:
        sample_bit()
        r5 = 21              # 21 ticks per data bit
# ...etc...
```

`R4` is the outer countdown (major bit-time counter) and `R5` is the inner countdown (fine
timing within a bit period). Together they divide the timer's tick rate down to exactly one
action per bit-time. The DJNZ ("Decrement and Jump if Not Zero") instruction is the 8049's
loop primitive.

The main loop at `0x0063`:

```asm
0063  DJNZ R4,L_092   ; count down R4; if not zero, skip to bookkeeping
; if R4 reached zero, fall through to bit state machine:
0065  MOV A,R6
0066  JB7 L_07D       ; test various state bits...
...
0090  MOV R4,#15h     ; L_090: reload R4 = 21 for next bit period
0092  MOV A,R1        ; L_092: bookkeeping (decrement various timers)
```

This is a common pattern in 1980s microcontroller code: use one fast interrupt and software
counters to create multiple different time intervals at once.

### Bookkeeping at the end of the ISR (0x092–0x0BF)

After the serial state machine, the ISR decrements several software timers stored in RAM:

- `R1`: auto-repeat counter
- `R2`: another countdown
- `RAM[0x2F]`: repeat-delay counter
- `RAM[0x3A]`, `RAM[0x3B]`: buzzer duration counters

The P2 pin value is also updated at the end (buzzer frequency tuning), then `A` is restored from
`RB1.R7` and the ISR returns with `RETR` (return from interrupt, re-enabling interrupts).

---

## Hardware initialisation (0x100–0x118)

After the reset → jump-to-0x100 sequence, the first thing the firmware does is set up hardware:

```asm
0100  MOV A,#BFh   ; 1011 1111 — sets most P2 pins high, bit 6 low
0102  OUTL P2,A    ; P2 = 0xBF
0103  MOV A,#00h
0105  OUTL BUS,A   ; clear the data bus output
0106  MOV A,#FEh
0108  MOV T,A      ; preload timer with 0xFE (= -2, overflows quickly)
0109  STRT T       ; start the timer in free-running mode
010A  SEL RB1
010B  MOV R6,#00h  ; clear the serial state register (in bank 1)
010D  SEL RB0
010E  EN TCNTI     ; enable timer counter interrupt
010F  CLR F1       ; clear buzzer flag
0110  CPL F1       ; ...then complement it → F1 = 1 (buzzer on for startup?)
```

In Python terms:

```python
P2 = 0xBF                 # configure output pins
BUS = 0x00                # serial output idle
timer.preload = 0xFE
timer.start()             # starts ticking
serial_state = 0          # nothing transmitting yet
interrupts.timer.enable()
buzzer_active = True       # bell on for a moment at startup
```

After this, a few RAM locations are zeroed (`RAM[0x39]`, `RAM[0x3B]`) and the keyboard scan
loop begins.

---

## The main keyboard scan loop (0x119–0x1E2)

This runs continuously, scanning P1 for pressed keys.

```asm
L_119:
  CLR A            ; A = 0
  MOV R2,A         ; R2 = row counter (0..N)

L_11B:
  CALL L_3D0       ; check for incoming data from host
  CALL L_4A8       ; send any queued serial bytes
  IN A,P1          ; read the keyboard matrix
  MOV R3,A         ; R3 = raw pin state
  MOV R1,A         ; R1 = copy
  CPL A            ; invert (keys are active-low: 0 = pressed)
  JZ L_1CF         ; if all zero after invert → all keys released
```

`P1` reads the keyboard matrix one row at a time. Keys are "active low" — pressing a key shorts
a pin to ground, reading `0`. After `CPL A` (bitwise NOT), a pressed key shows as `1`.

### Counting pressed keys in a row

```asm
  MOV R4,#08h    ; 8 bits to check
  MOV R5,#00h    ; pressed key counter

L_12F:
  MOV A,R3       ; reload row data
  RRC A          ; rotate right: LSB → carry
  MOV R3,A
  JNC L_138      ; carry=0 → bit was 0 → key is pressed → count it
  DJNZ R4,L_12F  ; count down 8 bits
  JMP L_13B

L_138:
  INC R5         ; R5 = number of pressed keys found
  JMP L_134      ; continue loop
```

This loops through all 8 bits of the row, counting pressed keys. In Python:

```python
pressed_count = 0
for bit in range(8):
    if (row_data >> bit) & 1 == 0:   # active low: 0 = pressed
        pressed_count += 1
```

### Handling exactly one key

```asm
L_13B:
  MOV A,R5
  DEC A
  JNZ L_157      ; not exactly one key? → handle rollover/no-key case
```

If exactly one key is pressed, the code proceeds to decode which key it is and build the
character to send. If no keys or multiple keys are pressed simultaneously, it jumps to a
different handler (`L_157`) that deals with key-up events and multi-key filtering.

### Decoding the character

Once a single key is identified, the code calls into the scan code lookup tables at `0x2D9`:

```asm
02D9  MOV R0,#34h   ; RAM[0x34] holds the key's matrix position
02DB  MOV A,@R0     ; A = position
02DC  MOVP3 A,@A    ; look up from ROM page 3 (0x300): A = base character
02DD  MOV R3,A      ; R3 = base char (e.g. 'a' = 0x61)
02DE  MOV A,@R0     ; position again
02DF  ADD A,#64h    ; offset into shifted table (position + 100)
02E1  MOVP3 A,@A    ; A = shifted character (e.g. 'A' = 0x41)
02E2  RET
```

`MOVP3 A,@A` reads a byte from page 3 of the ROM (address 0x300 + A). Two lookups happen:
one for the base character and one at `position + 100` for the shifted character. The
caller decides which to use based on Shift/Ctrl/Caps Lock state.

In Python this is simply:

```python
base_char  = rom[0x300 + position]
shift_char = rom[0x300 + position + 0x64]
```

---

## Cross-page table dispatch (0x528–0x554)

The 8049 has a quirk: `MOVP A,@A` can only read from the *current* 256-byte page of ROM.
If your data is on a different page you have to jump to a tiny helper stub on that page first,
then call `MOVP` from there.

The firmware solves this with a dispatch table at `0x52E`:

```asm
052D  JMPP @A        ; indirect jump: PC[7:0] = A → jumps within page 5

; Jump table (each pair: MOV A,R4 + JMP to the right page's MOVP stub):
0536  MOV A,R4 ; JMP L_005   ; → page 0 MOVP stub
0539  MOV A,R4 ; JMP L_1E8   ; → page 1 MOVP stub
053C  MOV A,R4 ; JMP L_2E3   ; → page 2 MOVP stub
053F  MOV A,R4 ; JMP L_3CE   ; → page 3 MOVP stub
0542  MOV A,R4 ; JMP L_47C   ; → page 4 MOVP stub
0545  MOV A,R4 ; JMP L_500   ; → page 5 MOVP stub
0548  MOV A,R4 ; JMP L_600   ; → page 6 MOVP stub
054B  MOV A,R4 ; JMP L_700   ; → page 7 MOVP stub
```

Each of those "MOVP stubs" is just:

```asm
  MOVP A,@A
  RET
```

And `R4` holds the table offset to look up. In Python:

```python
def read_rom_table(page, offset):
    return rom[page * 256 + offset]   # every page has its own lookup helper
```

This is a workaround for the CPU's 256-byte page restriction — clever but verbose.

---

## The scan code tables (0x300–0x3BF)

The ROM data starting at `0x300` is the keyboard character table. The disassembler shows many
of these bytes as instructions, but they are actually *data*. The firmware reads them with
`MOVP3 A,@A`, not as code.

Here is a slice decoded as data (bytes, not instructions):

```
0x358: 38 39 30 37 30 31 32 33 34 35 36
         '8' '9' '0' '7' '0' '1' '2' '3' '4' '5' '6'
```

That sequence of digit characters confirms that this region is the ASCII scan code table for
the top row of the keyboard.

Values above `0x7F` in the table represent special keys:
- `0xF8`, `0xF0`, etc. — function keys, cursor keys
- `0xA0`–`0xAF` — modifier key indicators
- `0x1B` = ESC, `0x0D` = Return, `0x08` = Backspace, etc.

---

## The host-command handler (0x200–0x2C6)

The Kaypro computer can also *send* data to the keyboard (to control the bell, set LEDs, etc.).
The firmware polls for incoming bytes at `0x200`:

```asm
0200  INS A,BUS       ; read byte from data bus
0201  CPL A           ; invert
0202  ANL A,#10h      ; mask bit 4
0204  MOV R0,A        ; R0 = relevant bits
0205  IN A,P2         ; read P2 pins
0206  CPL A
0207  ANL A,#05h      ; mask bits 0 and 2
0209  ORL A,R0        ; combine
020A  MOV R7,A        ; R7 = combined command byte
```

After decoding the command byte it calls `CALL L_400`, which searches a small command table
(`R1` points into it, `R3` = length, `R6` = stride). If the byte matches a known command,
the appropriate handler fires. Known handled commands include:

- Bell / buzzer activation (queues a tone sequence)
- Keyboard reset
- Diagnostic mode (the sequence at `0x502` which produces a test pattern and then jumps back
  to `0x000`)

---

## The bell sequence (0x502–0x526)

When the host sends a bell character, the firmware eventually reaches `0x502`. This:

1. Calls `L_54E` to initialise counters (`R3=8, R0=0, R1=0xFF`)
2. Runs two loops that accumulate a pattern via the cross-page dispatch
3. Calls `L_2C7` to queue the result as a serial byte
4. Repeats with an XOR variant
5. Executes a long software delay (nested `DJNZ R0,L_522; DJNZ R1,L_522` — counts down
   256 × 256 = 65 536 iterations)
6. Jumps to `L_000` — a **full restart** of the firmware

The restart at the end means the bell also doubles as a reset path. After the tone completes,
the keyboard reinitialises cleanly.

---

## Timer delay helper (0x3C8)

```asm
03C8  MOV A,T         ; read current timer value
03C9  ADD A,#01h      ; add 1
03CB  JNZ L_3C8       ; if not zero (i.e. no overflow yet): loop
03CD  RET             ; overflow happened → return
```

This is a busy-wait: it spins until the timer counter overflows from `0xFF` to `0x00`. The
`ADD A,#01h; JNZ` trick detects the overflow because adding 1 to 0xFF produces 0x100, which
truncates to `0x00`, setting the zero flag.

In Python:

```python
def wait_one_timer_tick():
    while (timer.value + 1) & 0xFF != 0:
        pass
```

This helper is called from several places when the firmware needs a precise short delay
independent of the main interrupt timing.

---

## The "0000" string at 0x0E0

The bytes at `0x0E0–0x0EA` decode as ASCII: `"0000 \xF0, <p0"`. The subroutine at `0x0CA`
sends bytes from this address via the serial line:

```asm
00CA  MOV R0,#34h    ; load counter from RAM[0x34]
00CC  MOV A,@R0
00CD  MOV R3,A
00CE  MOV R0,#E0h    ; R0 points to the string at 0x0E0
00D0  INC R3
00D1  MOV A,R0       ; L_0D1: A = current address
00D2  MOVP A,@A      ; read byte from ROM at that address
00D3  MOV R6,#08h    ; 8 bits to send
00D5  DJNZ R3,L_0D8  ; L_0D5: count down characters
00D7  RET
00D8  DJNZ R6,L_0DD  ; L_0D8: inner loop: send one bit
00DA  INC R0          ; advance to next byte
00DB  JMP L_0D1
00DD  RR A            ; L_0DD: shift out next bit
00DE  JMP L_0D5
```

This sends the startup string bit by bit over the serial line. The `0xF0` byte in the string
is likely a special marker understood by the Kaypro computer's terminal software, not a
printable character.

---

## Putting it all together

Here is the overall flow in pseudocode:

```python
# On power-on reset:
P1 = 0xFF                    # keyboard matrix idle
P2 = 0xBF                    # output pins to idle state
BUS = 0x00
timer.start(preload=0xFE)    # start timer
timer_interrupt.enable()

# Timer fires ~constantly:
def timer_isr():
    reload_timer()
    toggle_buzzer_pin_if_f1_set()   # bell sound
    step_serial_state_machine()     # one step of bit-banging
    decrement_software_timers()     # auto-repeat, etc.

# Main loop:
while True:
    check_for_host_commands()       # incoming data from Kaypro computer
    send_queued_serial_bytes()      # flush any pending output
    row_data = read_P1()            # scan keyboard matrix
    if no_keys_pressed(row_data):
        advance_row()
        continue
    pressed = count_pressed_keys(row_data)
    if pressed == 1:
        char = look_up_scan_code(key_position, shift_state)
        queue_for_serial_output(char)
    else:
        handle_multi_key_or_release()
```

The timer interrupt and the main loop run in parallel (the interrupt can fire at any point
during the main loop). The serial queue in RAM decouples them: the main loop writes characters
to queue, the timer ISR drains them one bit at a time.

---

## What we don't know yet

- The exact mapping of P1 bits to physical keys (would need a keyboard schematic or probing)
- Which specific values in the scan code table at 0x300 correspond to which keys
- The exact baud rate timing (depends on the crystal frequency, which isn't in the ROM)
- The meaning of the `0xF0` byte in the startup string (could be a host-specific command byte)
- Whether the tables at 0x600 and 0x700 are actually populated (both currently read `A3 83` =
  `MOVP A,@A; RET`, which would return the opcode bytes themselves as data — possibly
  intentional placeholder stubs for an expanded feature that was never implemented)