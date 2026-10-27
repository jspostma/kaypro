# C Development for Z80 / CP/M / Kaypro

## Primary Toolchain: z88dk

**GitHub:** https://github.com/z88dk/z88dk

The Z88 Development Kit — a full C and assembly toolchain for Z80-based systems. Has first-class CP/M and Kaypro support. This is the toolchain confirmed working for Kaypro 4 development (hello world compiled, disk image created, ran on hardware).

### Key components
- `zcc` — the C compiler frontend (drives the whole build)
- `z80asm` — assembler (also invoked by zcc)
- `appmake` — post-processes output into target-specific binary formats (COM files, disk images, etc.)
- `z88dk-lib` — standard library with CP/M and target-specific implementations

### Kaypro target
```sh
zcc +cpm -subtype=kaypro -o hello.com hello.c
```
The `+cpm` target covers generic CP/M 2.2; `-subtype=kaypro` adds Kaypro-specific library support (screen, keyboard). For a standalone ROM or BIOS (not a CP/M .COM file) use `+z80` with a custom memory map.

### Inline assembly
```c
#include <arch/z80.h>

void wait_for_fdc(void) {
    __asm
        halt          ; pause until /INT asserted by FDC
        ini           ; read byte from FDC data port to (HL), decrement BC
    __endasm;
}
```
z88dk uses `__asm` / `__endasm` blocks. Register values can be passed in/out via `__asm` with named registers but the calling convention must be respected.

### Hardware I/O
```c
#include <arch/z80.h>

uint8_t status = inp(0x10);   // IN A,(0x10) — read FDC status
outp(0x10, 0xD0);             // OUT (0x10),A — send Force Interrupt command
```

### Mixing C and assembly modules
```sh
zcc +cpm -subtype=kaypro -o bios.com bios.c fdc_loop.asm
```
Assembly modules that need to live at fixed addresses (e.g. the relocated disk read loop at 0xFDE5) can be linked with explicit ORG directives.

### Useful pragmas for BIOS work
```c
#pragma output REGISTER_SP = 0xFFFF   // set initial stack pointer
#pragma output CRT_ORG_CODE = 0xFA00  // place code at BIOS entry point
#pragma output CRT_ORG_BSS  = 0xFB00  // scratch RAM starts here
```

---

## Alternative: SDCC (Small Device C Compiler)

**Docs in archive:** `kaypro_related/sdccman.pdf`, `kaypro_related/doc-master.zip`

SDCC supports Z80 but has weaker CP/M/Kaypro integration than z88dk. The archive SDCC docs were collected for reference. z88dk is the better choice for this project.

---

## Z80 C Calling Convention (z88dk)

z88dk uses a register-based calling convention for Z80:
- First integer arg: passed in `HL` (or `BC` for second arg)
- Return value: in `HL` (16-bit) or `A` (8-bit)
- Caller saves registers; callee can trash `AF`, `BC`, `DE`, `HL`
- Alternate registers (`AF'`, `BC'`, `DE'`, `HL'`) are **not preserved** — inline asm that uses them must save/restore

CP/M BIOS entry convention (what the BDOS expects when calling BIOS functions):
- Single-byte arg: in `C`
- 16-bit arg: in `BC`
- Return HL = pointer (e.g. DPH address from SELDSK), or A = error code

---

## BIOS Rewrite Notes

### What can be pure C
- `SELDSK` / `SETTRK` / `SETSEC` / `SETDMA` — just store args to globals
- `SECTRAN` — table lookup
- `HOME` — call `SELDSK(0)` then issue FDC RESTORE command
- `READ` / `WRITE` control flow, retry logic, track seeking
- `vidout` escape sequence state machine — switch/case is cleaner than the Z80 dispatch chain
- `kbdstat` / `kbdin` / `kbdout` — simple `inp()`/`outp()` wrappers
- Disk Parameter Block and DPH structs — map directly to z88dk structs
- `devinit` SIO init — loop over init byte table with `outp()`

### Needs inline asm
- **FDC byte-transfer inner loop** (`HALT` + `INI`/`OUTI`) — timing critical, no C equivalent for the HALT-on-INT trick
- **Cold-start entry** (`DI`, `LD SP,0xFFFF` before C runtime init)
- Any use of Z80 shadow/alternate registers

### Keep as linked asm module
- The **relocated sector read/write routine** (originally at 0xFDE5 in the 292 ROM) — position-sensitive, should be a separate `.asm` file with explicit ORG

### Disk Parameter Block struct (z88dk C)
```c
typedef struct {
    uint16_t spt;   // sectors per track
    uint8_t  bsh;   // block shift
    uint8_t  blm;   // block mask
    uint8_t  exm;   // extent mask
    uint16_t dsm;   // disk size - 1
    uint16_t drm;   // directory entries - 1
    uint8_t  al0;   // allocation bitmap byte 0
    uint8_t  al1;   // allocation bitmap byte 1
    uint16_t cks;   // checksum size
    uint16_t off;   // track offset
} dpb_t;

// Drive A (single-sided, from 81-292 ROM)
const dpb_t dpb_a = { 18, 3, 7, 0, 82, 31, 0x80, 0x00, 8, 3 };
```

---

## Reference: Kaypro 4 I/O Ports (for outp/inp calls)

| Port | Function |
|------|----------|
| 0x00 | SIO channel A data (keyboard in) |
| 0x01 | SIO channel B data (serial/modem) |
| 0x02 | SIO channel A control |
| 0x03 | SIO channel B control |
| 0x04–0x07 | 8253 PIT (baud rate generator) |
| 0x10 | FDC command/status |
| 0x11 | FDC track register |
| 0x12 | FDC sector register |
| 0x13 | FDC data register |
| 0x14 | Control latch (drive select, motor, side, density, ROM bank) |
| 0x18 | Parallel printer data |
| 0x1C | 6545 CRTC address register |
| 0x1D | 6545 CRTC data register |
| 0x1F | 6545 CRTC strobe/lightpen |

## Reference: Key Scratch RAM Addresses (292 ROM layout)

These would become global variable locations in the C BIOS (set via `#pragma output CRT_ORG_BSS` or explicit placement):

| Address | Variable |
|---------|----------|
| 0xFB00 | Current sector |
| 0xFB01–02 | DMA address |
| 0xFB03 | Current track |
| 0xFB14–15 | DMA buffer pointer |
| 0xFB16+ | 128-byte sector buffer |
| 0xFD16 | Current drive |
| 0xFD17–1F | Baud rate / SIO config bytes |
| 0xFD74 | ESC sequence parser state |
| 0xFD75 | Cursor row |
| 0xFD76 | Cursor column |
| 0xFD77 | Video attribute flags |
| 0xFD78–79 | Video RAM cursor pointer |
| 0xFD7A–7B | Video RAM base address |
