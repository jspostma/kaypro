# `kaypro.h` Reference

Hardware register definitions for the Kaypro 4 (Z80/CP/M, ROM 81-292-A).

Include alongside z88dk's `<arch/z80.h>` which provides `inp()` and `outp()`.

---

## Utility macros

### `_BV(n)`
Bit value — produces a byte with bit *n* set. Identical to the AVR macro.
```c
_BV(0) == 0x01
_BV(3) == 0x08
_BV(7) == 0x80
```

### `port_set(port, mask)` / `port_clr(port, mask)` / `port_tgl(port, mask)`
Read-modify-write helpers for any I/O port. Because Z80 I/O ports aren't memory-mapped you can't do `PORT |= mask` directly — you have to read, modify, then write. These hide that pattern.
```c
port_set(CTL_LATCH, CTL_MOTOR);   // turn motor on without disturbing other bits
port_clr(CTL_LATCH, CTL_MOTOR);   // turn motor off
port_tgl(CTL_LATCH, CTL_DDEN);    // flip density bit
```

---

## Z80 SIO — Serial I/O (`0x00`–`0x03`)

The Kaypro uses a Z80 SIO/2 chip. It has two independent serial channels:
- **Channel A** (`SIO_A_*`) — keyboard input and console output
- **Channel B** (`SIO_B_*`) — modem / RS-232 serial port

Each channel has separate data and control ports.

### Port addresses

| Constant | Address | Direction | Function |
|---|---|---|---|
| `SIO_A_DATA` | `0x00` | R/W | Channel A data (keyboard in / console out) |
| `SIO_B_DATA` | `0x02` | R/W | Channel B data (modem) |
| `SIO_A_CTRL` | `0x01` | R/W | Channel A control register access |
| `SIO_B_CTRL` | `0x03` | R/W | Channel B control register access |

### How SIO register access works

The SIO has internal write registers WR0–WR7 and read registers RR0–RR2. You don't address them directly — you write the register number to the control port first, then write (or read) the data.

WR0 is always selected after reset, and any write to the control port that doesn't look like a register pointer is treated as a WR0 command. To access WR2:
```c
outp(SIO_A_CTRL, 0x02);          // select WR2
outp(SIO_A_CTRL, value);         // write to WR2
```

For RR0 (the most commonly read register) you can read directly without a pointer:
```c
uint8_t status = inp(SIO_A_CTRL);   // reads RR0
```

### Write register indices (`SIO_WR0`–`SIO_WR7`)

| Constant | Value | Purpose |
|---|---|---|
| `SIO_WR0` | `0x00` | Command register / register pointer |
| `SIO_WR1` | `0x01` | Interrupt enables |
| `SIO_WR2` | `0x02` | Interrupt vector (channel B only; channel A writes it but B uses it) |
| `SIO_WR3` | `0x03` | Receive parameters and enable |
| `SIO_WR4` | `0x04` | Clock mode and sync mode selection |
| `SIO_WR5` | `0x05` | Transmit parameters and enable |
| `SIO_WR6` | `0x06` | Sync character (SYNC modes only; unused in async) |
| `SIO_WR7` | `0x07` | Sync character (SYNC modes only; unused in async) |

### Read register indices (`SIO_RR0`–`SIO_RR2`)

| Constant | Value | Purpose |
|---|---|---|
| `SIO_RR0` | `0x00` | Buffer status and line status (default after reset) |
| `SIO_RR1` | `0x01` | Special receive conditions (framing, parity, overrun errors) |
| `SIO_RR2` | `0x02` | Interrupt vector, optionally modified with status bits (channel B) |

### RR0 status bits

These are what you test after `inp(SIO_A_CTRL)` to check if data is waiting or if you can send.

| Constant | Bit | Meaning |
|---|---|---|
| `SIO_RX_RDY` | 0 | A received byte is waiting in the data register |
| `SIO_TX_EMPTY` | 2 | Transmit buffer is empty — safe to write next byte |
| `SIO_DCD` | 3 | /DCD input state (data carrier detect, active low) |
| `SIO_SYNC` | 4 | /SYNC input or HUNT status |
| `SIO_CTS` | 5 | /CTS input state (clear to send, active low) |
| `SIO_TX_UND` | 6 | Transmit underrun (SDLC mode only) |
| `SIO_BRK` | 7 | Break or abort condition received |

Typical use:
```c
// Wait for a byte from keyboard
while (!(inp(SIO_A_CTRL) & SIO_RX_RDY)) {}
uint8_t ch = inp(SIO_A_DATA);

// Send a byte to console
while (!(inp(SIO_A_CTRL) & SIO_TX_EMPTY)) {}
outp(SIO_A_DATA, ch);
```

### WR3 receive bits (`SIO_RX_*`)

WR3 controls receive word length and receiver enable.

| Constant | Value | Meaning |
|---|---|---|
| `SIO_RX_5BIT` | `0x00` | 5-bit receive words |
| `SIO_RX_7BIT` | `0x40` | 7-bit receive words |
| `SIO_RX_6BIT` | `0x80` | 6-bit receive words |
| `SIO_RX_8BIT` | `0xC0` | 8-bit receive words (normal async use) |
| `SIO_RX_EN`   | bit 0 | Receiver enable |

### WR5 transmit bits (`SIO_TX_*`, `SIO_RTS`, `SIO_DTR`)

WR5 controls transmit word length, transmitter enable, and modem control outputs.

| Constant | Bit/value | Meaning |
|---|---|---|
| `SIO_TX_5BIT` | `0x00` | 5-bit transmit words |
| `SIO_TX_7BIT` | `0x20` | 7-bit transmit words |
| `SIO_TX_6BIT` | `0x40` | 6-bit transmit words |
| `SIO_TX_8BIT` | `0x60` | 8-bit transmit words (normal async use) |
| `SIO_TX_EN`   | bit 3 | Transmitter enable |
| `SIO_RTS`     | bit 1 | Assert /RTS output |
| `SIO_DTR`     | bit 7 | Assert /DTR output |

---

## 8253 PIT — Programmable Interval Timer (`0x04`–`0x07`)

The PIT generates the baud rate clock that drives the SIO. Three independent 16-bit down-counters. Counter 0 is typically used for baud rate; the others may be unused or used for other timing.

### Port addresses

| Constant | Address | Function |
|---|---|---|
| `PIT_0` | `0x04` | Counter 0 data port |
| `PIT_1` | `0x05` | Counter 1 data port |
| `PIT_2` | `0x06` | Counter 2 data port |
| `PIT_CTRL` | `0x07` | Mode/control word (write only) |

### How PIT access works

Write the control word to `PIT_CTRL` first to select a counter, set its mode, and specify how you'll load the count value. Then write the count to the counter's data port.

```c
// Set counter 0 to mode 3 (square wave), load LSB then MSB
outp(PIT_CTRL, PIT_CH0 | PIT_LSBMSB | PIT_MODE3);
outp(PIT_0, count & 0xFF);         // LSB
outp(PIT_0, (count >> 8) & 0xFF);  // MSB
```

### Control word fields

**Channel select** (bits 7–6):

| Constant | Value | Selects |
|---|---|---|
| `PIT_CH0` | `0x00` | Counter 0 |
| `PIT_CH1` | `0x40` | Counter 1 |
| `PIT_CH2` | `0x80` | Counter 2 |

**Load mode** (bits 5–4):

| Constant | Value | Meaning |
|---|---|---|
| `PIT_LSB` | `0x10` | Load LSB only |
| `PIT_MSB` | `0x20` | Load MSB only |
| `PIT_LSBMSB` | `0x30` | Load LSB first, then MSB (most common) |

**Operating mode** (bits 3–1):

| Constant | Value | Meaning |
|---|---|---|
| `PIT_MODE0` | `0x00` | Interrupt on terminal count |
| `PIT_MODE2` | `0x04` | Rate generator (pulse every N clocks) |
| `PIT_MODE3` | `0x06` | Square wave — used for baud rate generation |

**Count format** (bit 0):

| Constant | Value | Meaning |
|---|---|---|
| *(none)* | `0x00` | Binary count (default) |
| `PIT_BCD` | `0x01` | BCD count (rarely needed) |

---

## WD179x FDC — Floppy Disk Controller (`0x10`–`0x13`)

The WD1793 (or compatible) manages all floppy disk I/O. It handles seek, step, read, and write operations and signals the CPU via /INTRQ (interrupt request) and /DRQ (data request).

On the Kaypro the /INTRQ line drives the Z80 /INT pin. The ROM BIOS uses `HALT` to suspend the CPU until /INT fires, then uses `INI`/`OUTI` instructions to move bytes between the FDC data register and memory.

### Port addresses

| Constant | Address | R/W | Function |
|---|---|---|---|
| `FDC_CMD` | `0x10` | W | Command register — write a command byte to start an operation |
| `FDC_STATUS` | `0x10` | R | Status register — read to check completion/errors |
| `FDC_TRACK` | `0x11` | R/W | Track register — current head position |
| `FDC_SECTOR` | `0x12` | R/W | Sector register — target sector for read/write |
| `FDC_DATA` | `0x13` | R/W | Data register — byte-at-a-time during sector transfer |

`FDC_CMD` and `FDC_STATUS` are the same address — write = command, read = status.

### Command constants

Commands are grouped into three types. Type I commands move the head. Type II/III commands transfer data.

**Type I — head positioning:**

| Constant | Value | Action |
|---|---|---|
| `FDC_RESTORE` | `0x00` | Seek to track 0 (home) |
| `FDC_SEEK` | `0x10` | Seek to track number in the data register |
| `FDC_STEP` | `0x20` | Step one track in the last direction |
| `FDC_STEP_IN` | `0x40` | Step one track inward (away from track 0) |
| `FDC_STEP_OUT` | `0x60` | Step one track outward (toward track 0) |

**Type II — sector transfer:**

| Constant | Value | Action |
|---|---|---|
| `FDC_READ_SEC` | `0x80` | Read sector (track/sector registers must be set first) |
| `FDC_WRITE_SEC` | `0xA0` | Write sector |

**Type III — track/address operations:**

| Constant | Value | Action |
|---|---|---|
| `FDC_READ_ADDR` | `0xC0` | Read ID field of next sector (returns 6 bytes) |
| `FDC_READ_TRACK` | `0xE0` | Read entire track raw |
| `FDC_WRITE_TRACK` | `0xF0` | Write entire track (used for formatting) |

**Terminate:**

| Constant | Value | Action |
|---|---|---|
| `FDC_FORCE_INT` | `0xD0` | Abort current command, optionally generate interrupt |

### Command modifier flags

OR these into a command byte to change its behavior.

| Constant | Bit | Applies to | Meaning |
|---|---|---|---|
| `FDC_FLAG_UPDATE` | 4 | Type I | Update track register after step |
| `FDC_FLAG_LOAD` | 3 | Type I | Load head before stepping |
| `FDC_FLAG_VERIFY` | 2 | Type I | Verify head is on correct track after seek |
| `FDC_FLAG_15MS` | 2 | Type I | 15 ms head settle delay (same bit as VERIFY — set both) |
| `FDC_FLAG_SIDE` | 3 | Type II/III | Enable side-select compare |
| `FDC_FLAG_DELAY` | 2 | Type II/III | 15 ms head settle delay before data transfer |
| `FDC_FLAG_MULTI` | 4 | Type II | Continue to next sector after this one (multi-sector) |
| `FDC_FLAG_DDEN` | 0 | Type II/III | 0 = single density (FM), 1 = double density (MFM) |

Kaypro double-density read example:
```c
outp(FDC_TRACK, track);
outp(FDC_SECTOR, sector);
outp(FDC_CMD, FDC_READ_SEC | FDC_FLAG_DDEN | FDC_FLAG_DELAY);
```

### Status register bits

The meaning of some bits changes depending on whether a type I or type II/III command is running.

**Bit 0 — always the same:**

| Constant | Bit | Meaning |
|---|---|---|
| `FDC_ST_BUSY` | 0 | Command in progress. Poll until clear before issuing next command. |

**Type I status bits:**

| Constant | Bit | Meaning |
|---|---|---|
| `FDC_ST_INDEX` | 1 | Index pulse — disk has passed the index hole |
| `FDC_ST_TRACK0` | 2 | Head is at track 0 |
| `FDC_ST_CRC_ERR` | 3 | CRC error in ID field or data |
| `FDC_ST_SEEK_ERR` | 4 | Seek error — track not found |
| `FDC_ST_HEAD_LD` | 5 | Head is loaded (motor engaged) |
| `FDC_ST_WPROT` | 6 | Disk is write-protected |
| `FDC_ST_NOT_RDY` | 7 | Drive not ready (no disk, door open) |

**Type II/III status bits (bits 1–5 differ):**

| Constant | Bit | Meaning |
|---|---|---|
| `FDC_ST_DRQ` | 1 | Data request — byte ready in data register (or needs one for write) |
| `FDC_ST_LOST` | 2 | Lost data — CPU didn't service DRQ in time |
| `FDC_ST_CRC_ERR` | 3 | CRC error in data field |
| `FDC_ST_RNF` | 4 | Record not found — sector ID not found on track |
| `FDC_ST_RECTYPE` | 5 | Record type: 0 = normal data mark, 1 = deleted data mark |
| `FDC_ST_WPROT` | 6 | Write protected (write commands only) |
| `FDC_ST_NOT_RDY` | 7 | Drive not ready |

---

## Control Latch (`0x14`)

A write-only latch that controls drive selection, motor, head side, density, and the ROM/RAM bank switch. There is no hardware read-back — the BIOS maintains a shadow copy in scratch RAM so that read-modify-write is possible. The `ctl_*` macros use `inp()` which reads the latch's last written value via the bus, but this is not guaranteed to work on all hardware revisions — a software shadow byte is safer.

### Bit definitions

| Constant | Bits | Value | Meaning |
|---|---|---|---|
| `CTL_DRIVE_A` | 1:0 | `0x00` | Select drive A |
| `CTL_DRIVE_B` | 1:0 | `0x01` | Select drive B |
| `CTL_DRIVE_C` | 1:0 | `0x02` | Select drive C |
| `CTL_DRIVE_D` | 1:0 | `0x03` | Select drive D |
| `CTL_DRIVE_MASK` | 1:0 | `0x03` | Mask for drive select bits |
| `CTL_SIDE1` | 2 | `0x04` | 0 = side 0, 1 = side 1 |
| `CTL_MOTOR` | 3 | `0x08` | 1 = motor on |
| `CTL_DDEN` | 4 | `0x10` | 1 = double density (MFM); 0 = single density (FM) |
| `CTL_ROM_BANK` | 6 | `0x40` | 0 = ROM mapped at 0x0000; 1 = RAM at 0x0000 (normal CP/M state) |

Bit 5 is unused. Bit 7 is unused.

### Helper macros

| Macro | Action |
|---|---|
| `ctl_read()` | Read current latch value |
| `ctl_write(v)` | Write entire latch value |
| `ctl_set(bits)` | Set bits without disturbing others |
| `ctl_clr(bits)` | Clear bits without disturbing others |
| `ctl_drive(d)` | Switch drive (0–3) without disturbing motor/side/density bits |

```c
ctl_set(CTL_MOTOR);             // motor on
ctl_drive(1);                   // select drive B
ctl_set(CTL_DDEN);              // double density
ctl_clr(CTL_ROM_BANK);          // map ROM to 0x0000 (cold boot setup)
```

---

## 6545 CRTC — CRT Controller (`0x1C`–`0x1F`)

The 6545 (or pin-compatible MC6845) generates all video timing and provides the display start address and cursor address registers. The Kaypro's character ROM and attribute logic sit between the CRTC and the monitor — the CRTC itself deals only with addresses and timing, not pixels or characters.

### Port addresses

| Constant | Address | R/W | Function |
|---|---|---|---|
| `CRTC_ADDR` | `0x1C` | W | Select internal register (0–17) |
| `CRTC_DATA` | `0x1D` | R/W | Read or write the selected register |
| `CRTC_STROBE` | `0x1F` | R | Light pen strobe / status |

### How CRTC access works

Write the register index to `CRTC_ADDR`, then read or write `CRTC_DATA`. The index register holds its value, so a second access to `CRTC_DATA` without re-writing `CRTC_ADDR` touches the same register again.

The `crtc_write()` and `crtc_read()` macros handle the two-step access:
```c
crtc_write(CRTC_R6_VDISP, 24);   // 24 displayed rows
uint8_t rows = crtc_read(CRTC_R6_VDISP);
```

### Internal register reference

| Constant | Index | R/W | Function |
|---|---|---|---|
| `CRTC_R0_HTOTAL` | 0 | W | Horizontal total character clocks per line, minus 1 |
| `CRTC_R1_HDISP` | 1 | W | Horizontal displayed characters per line |
| `CRTC_R2_HSYNC` | 2 | W | Horizontal sync position |
| `CRTC_R3_SYNC_W` | 3 | W | Sync widths: bits 7–4 = vsync width, bits 3–0 = hsync width |
| `CRTC_R4_VTOTAL` | 4 | W | Vertical total character rows, minus 1 |
| `CRTC_R5_VADJ` | 5 | W | Vertical total adjust in scan lines (fine-tunes frame period) |
| `CRTC_R6_VDISP` | 6 | W | Vertical displayed rows |
| `CRTC_R7_VSYNC` | 7 | W | Vertical sync position (row number) |
| `CRTC_R8_MODE` | 8 | W | Interlace mode and display/cursor skew |
| `CRTC_R9_SCANMAX` | 9 | W | Maximum scan line per character row (font height minus 1) |
| `CRTC_R10_CSTART` | 10 | W | Cursor start: bits 6–5 = blink mode, bits 4–0 = start scan line |
| `CRTC_R11_CEND` | 11 | W | Cursor end scan line |
| `CRTC_R12_START_H` | 12 | W | Display start address, high byte (bits 5–0) |
| `CRTC_R13_START_L` | 13 | W | Display start address, low byte |
| `CRTC_R14_CUR_H` | 14 | R/W | Cursor address, high byte |
| `CRTC_R15_CUR_L` | 15 | R/W | Cursor address low byte |
| `CRTC_R16_LP_H` | 16 | R | Light pen address high byte (latched on strobe) |
| `CRTC_R17_LP_L` | 17 | R | Light pen address low byte |

**Display start address** (R12/R13) is the video RAM address of the top-left character on screen. Incrementing it by 80 scrolls the display up one row without moving any data — hardware scrolling. The CRTC treats video RAM as a circular buffer.

**Cursor address** (R14/R15) is the video RAM address of the cursor character cell. The CRTC generates the cursor underline/block at that position automatically.

Both addresses are 14-bit (only bits 5–0 of the high byte are used).

### Cursor blink mode (bits 6–5 of R10)

| Constant | Value | Blink behaviour |
|---|---|---|
| `CRTC_CUR_NOBLINK` | `0x00` | Cursor always visible |
| `CRTC_CUR_NOBLINK2` | `0x20` | Cursor always visible (alternate encoding) |
| `CRTC_CUR_BLINK_16` | `0x40` | Blink at 1/16 of field rate (~3 Hz at 50 Hz) |
| `CRTC_CUR_BLINK_32` | `0x60` | Blink at 1/32 of field rate (~1.5 Hz at 50 Hz) |

### Convenience macros

```c
// Hardware scroll — point display start at row 2 of video RAM
crtc_set_start(VRAM_BASE + 2 * VRAM_COLS);

// Move cursor to row 5, column 10
crtc_set_cursor(VRAM_BASE + 5 * VRAM_COLS + 10);
```

---

## Parallel Printer Port (`0x18`)

| Constant | Address | Function |
|---|---|---|
| `PRINTER_DATA` | `0x18` | Write a byte to the parallel printer data lines |

Status (busy/strobe) is handled by separate circuitry not directly exposed as an I/O port in the standard Kaypro design — the BIOS uses a timeout loop rather than polling a status bit.

---

## Scratch RAM — 81-292-A ROM layout

These constants are `volatile` pointer casts to absolute addresses — the same locations used by the original ROM BIOS. Use them when writing code that needs to interoperate with ROM routines, or as a starting point for a full C BIOS where you'd replace them with proper global variables.

The 292 ROM places disk state at `0xFB00` and video/system state at `0xFD00`.

### Disk state (`0xFB00–`)

| Constant | Address | Type | Contents |
|---|---|---|---|
| `SCRATCH_SECTOR` | `0xFB00` | `uint8_t` | Current sector number |
| `SCRATCH_DMA_ADDR` | `0xFB01` | `uint16_t` | DMA address (where READ/WRITE transfers data in CP/M memory) |
| `SCRATCH_TRACK` | `0xFB03` | `uint8_t` | Current track number |
| `SCRATCH_DMA_PTR` | `0xFB14` | `uint16_t` | DMA buffer pointer (internal use during transfer) |
| `SCRATCH_SEC_BUF` | `0xFB16` | `uint8_t[128]` | 128-byte sector buffer |

### Video / system state (`0xFD00–`)

| Constant | Address | Type | Contents |
|---|---|---|---|
| `SCRATCH_DRIVE` | `0xFD16` | `uint8_t` | Currently selected drive (0 = A, 1 = B, …) |
| `SCRATCH_BAUD_CFG` | `0xFD17` | `uint8_t[9]` | Baud rate and SIO configuration bytes |
| `SCRATCH_ESC_STATE` | `0xFD74` | `uint8_t` | ESC sequence parser state machine state |
| `SCRATCH_CUR_ROW` | `0xFD75` | `uint8_t` | Cursor row (0–23) |
| `SCRATCH_CUR_COL` | `0xFD76` | `uint8_t` | Cursor column (0–79) |
| `SCRATCH_VID_ATTR` | `0xFD77` | `uint8_t` | Current video attribute flags |
| `SCRATCH_VID_CUR_PTR` | `0xFD78` | `uint16_t` | Video RAM address of cursor character cell |
| `SCRATCH_VID_BASE` | `0xFD7A` | `uint16_t` | Video RAM base address (normally `VRAM_BASE` = `0xF000`) |

Usage:
```c
uint8_t row = *SCRATCH_CUR_ROW;
*SCRATCH_CUR_COL = 0;
```

---

## Video RAM

| Constant | Value | Meaning |
|---|---|---|
| `VRAM_BASE` | `0xF000` | Start of 4 KB video RAM |
| `VRAM_COLS` | `80` | Characters per row |
| `VRAM_ROWS` | `24` | Rows on screen |
| `VRAM_SIZE` | `1920` | Total character cells (80 × 24) |

### `vram_ptr(row, col)`
Returns a `volatile uint8_t *` to a character cell.
```c
*vram_ptr(0, 0) = 'H';   // write 'H' to top-left corner
*vram_ptr(23, 79) = ' '; // clear bottom-right corner
```

Video RAM is contiguous — characters run left-to-right, row by row. The CRTC display start address (R12/R13) selects which RAM address maps to the top-left corner, allowing hardware scrolling without copying data.
