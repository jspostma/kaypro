/*
 * kaypro.h — Hardware register definitions for the Kaypro 4 (Z80/CP/M)
 *
 * Covers all I/O ports, control latch bits, FDC commands and status flags,
 * SIO register indices, CRTC register indices, PIT channels, and scratch RAM
 * layout for the 81-292-A ROM.
 *
 * Usage with z88dk:
 *   #include <arch/z80.h>   // for inp() / outp()
 *   #include "kaypro.h"
 *
 * Naming follows AVR conventions where practical:
 *   - Port address constants:  ALL_CAPS
 *   - Bit mask constants:      PREFIX_NAME  (e.g. FDC_BUSY, CTL_MOTOR)
 *   - Register index constants (chips with addr/data pairs): PREFIX_REG_NAME
 */

#ifndef KAYPRO_H
#define KAYPRO_H

#include <stdint.h>

/* ── Utility ──────────────────────────────────────────────────────────────── */

#ifndef _BV
#define _BV(n)          (1 << (n))
#endif

/* Set / clear individual bits in an I/O port (read-modify-write) */
#define port_set(port, mask)    outp((port), inp((port)) |  (mask))
#define port_clr(port, mask)    outp((port), inp((port)) & ~(mask))
#define port_tgl(port, mask)    outp((port), inp((port)) ^  (mask))


/* ══════════════════════════════════════════════════════════════════════════
 * Z80 SIO — Serial I/O (two channels: A = keyboard/console, B = modem)
 * ══════════════════════════════════════════════════════════════════════════ */

#define SIO_A_DATA      0x00    /* channel A data  (read: kbd in, write: console out) */
#define SIO_B_DATA      0x02    /* channel B data  (read/write: modem) */
#define SIO_A_CTRL      0x01    /* channel A control (WR0–WR7 / RR0–RR2) */
#define SIO_B_CTRL      0x03    /* channel B control */

/* SIO Write Register select — first byte written to ctrl port selects WRn */
#define SIO_WR0         0x00    /* command / register pointer */
#define SIO_WR1         0x01    /* interrupt enables */
#define SIO_WR2         0x02    /* interrupt vector (channel B only) */
#define SIO_WR3         0x03    /* receive parameters & enable */
#define SIO_WR4         0x04    /* clocks & sync modes */
#define SIO_WR5         0x05    /* transmit parameters & enable */
#define SIO_WR6         0x06    /* sync character (SYNC mode only) */
#define SIO_WR7         0x07    /* sync character (SYNC mode only) */

/* SIO Read Register select (RR0 is read directly; RR1/RR2 need pointer) */
#define SIO_RR0         0x00    /* transmit/receive buffer status, line status */
#define SIO_RR1         0x01    /* special receive condition bits */
#define SIO_RR2         0x02    /* interrupt vector (modified by status, ch B) */

/* SIO RR0 status bits */
#define SIO_RX_RDY      _BV(0) /* receive character available */
#define SIO_TX_EMPTY    _BV(2) /* transmit buffer empty */
#define SIO_DCD         _BV(3) /* /DCD input */
#define SIO_SYNC        _BV(4) /* /SYNC or HUNT status */
#define SIO_CTS         _BV(5) /* /CTS input */
#define SIO_TX_UND      _BV(6) /* transmit underrun (SDLC mode) */
#define SIO_BRK         _BV(7) /* break/abort received */

/* SIO WR3 (receive) bits */
#define SIO_RX_5BIT     0x00
#define SIO_RX_7BIT     0x40
#define SIO_RX_6BIT     0x80
#define SIO_RX_8BIT     0xC0
#define SIO_RX_EN       _BV(0)

/* SIO WR5 (transmit) bits */
#define SIO_TX_5BIT     0x00
#define SIO_TX_7BIT     0x20
#define SIO_TX_6BIT     0x40
#define SIO_TX_8BIT     0x60
#define SIO_TX_EN       _BV(3)
#define SIO_RTS         _BV(1)
#define SIO_DTR         _BV(7)


/* ══════════════════════════════════════════════════════════════════════════
 * 8253 PIT — Programmable Interval Timer (baud rate generation)
 * ══════════════════════════════════════════════════════════════════════════ */

#define PIT_0           0x04    /* counter 0 */
#define PIT_1           0x05    /* counter 1 */
#define PIT_2           0x06    /* counter 2 */
#define PIT_CTRL        0x07    /* mode/control word */

/* PIT control word fields */
#define PIT_BCD         _BV(0) /* BCD mode (0 = binary) */
#define PIT_MODE0       0x00   /* interrupt on terminal count */
#define PIT_MODE2       0x04   /* rate generator */
#define PIT_MODE3       0x06   /* square wave generator (typical for baud) */
#define PIT_LSB         0x10   /* load LSB only */
#define PIT_MSB         0x20   /* load MSB only */
#define PIT_LSBMSB      0x30   /* load LSB then MSB */
#define PIT_CH0         0x00   /* select counter 0 */
#define PIT_CH1         0x40   /* select counter 1 */
#define PIT_CH2         0x80   /* select counter 2 */


/* ══════════════════════════════════════════════════════════════════════════
 * WD179x FDC — Floppy Disk Controller
 * ══════════════════════════════════════════════════════════════════════════ */

#define FDC_CMD         0x10    /* write: command register */
#define FDC_STATUS      0x10    /* read:  status register  */
#define FDC_TRACK       0x11    /* track register */
#define FDC_SECTOR      0x12    /* sector register */
#define FDC_DATA        0x13    /* data register */

/* FDC Commands (write to FDC_CMD) */
#define FDC_RESTORE     0x00    /* seek track 0 */
#define FDC_SEEK        0x10    /* seek to track in data register */
#define FDC_STEP        0x20    /* step in direction of last seek */
#define FDC_STEP_IN     0x40    /* step toward track 0+1 */
#define FDC_STEP_OUT    0x60    /* step toward track 0 */
#define FDC_READ_SEC    0x80    /* read sector */
#define FDC_WRITE_SEC   0xA0    /* write sector */
#define FDC_READ_ADDR   0xC0    /* read address (ID field) */
#define FDC_READ_TRACK  0xE0    /* read entire track */
#define FDC_WRITE_TRACK 0xF0    /* write entire track (format) */
#define FDC_FORCE_INT   0xD0    /* force interrupt / terminate */

/* FDC command modifier flags (OR into command byte) */
#define FDC_FLAG_UPDATE _BV(4)  /* type I: update track register */
#define FDC_FLAG_LOAD   _BV(3)  /* type I: load head on step */
#define FDC_FLAG_VERIFY _BV(2)  /* type I: verify on destination track */
#define FDC_FLAG_15MS   _BV(2)  /* type I: 15ms head settle delay (with VERIFY) */
#define FDC_FLAG_SIDE   _BV(3)  /* type II/III: side select compare enable */
#define FDC_FLAG_DELAY  _BV(2)  /* type II/III: 15ms head settle delay */
#define FDC_FLAG_MULTI  _BV(4)  /* type II: multiple sector read/write */
#define FDC_FLAG_DDEN   _BV(0)  /* double density (MFM) — 0 = FM (SD), 1 = MFM (DD) */

/* FDC Status register bits (type I commands) */
#define FDC_ST_BUSY     _BV(0)  /* command in progress */
#define FDC_ST_INDEX    _BV(1)  /* index pulse (type I) / DRQ (type II/III) */
#define FDC_ST_TRACK0   _BV(2)  /* head at track 0 (type I) / LOST DATA (type II/III) */
#define FDC_ST_CRC_ERR  _BV(3)  /* CRC error */
#define FDC_ST_SEEK_ERR _BV(4)  /* seek error / record not found */
#define FDC_ST_HEAD_LD  _BV(5)  /* head loaded (type I) / record type (type II/III) */
#define FDC_ST_WPROT    _BV(6)  /* write protected */
#define FDC_ST_NOT_RDY  _BV(7)  /* drive not ready */

/* FDC Status register bits (type II/III commands — different meanings) */
#define FDC_ST_DRQ      _BV(1)  /* data request */
#define FDC_ST_LOST     _BV(2)  /* lost data (CPU too slow) */
#define FDC_ST_RNF      _BV(4)  /* record not found */
#define FDC_ST_RECTYPE  _BV(5)  /* record type (0=normal, 1=deleted) */


/* ══════════════════════════════════════════════════════════════════════════
 * Control Latch (port 0x14) — drive select, motor, side, density, ROM bank
 * ══════════════════════════════════════════════════════════════════════════ */

#define CTL_LATCH       0x14

/* Drive select (bits 0–1) */
#define CTL_DRIVE_A     0x00
#define CTL_DRIVE_B     0x01
#define CTL_DRIVE_C     0x02
#define CTL_DRIVE_D     0x03
#define CTL_DRIVE_MASK  0x03

/* Other latch bits */
#define CTL_SIDE1       _BV(2)  /* 0 = side 0, 1 = side 1 */
#define CTL_MOTOR       _BV(3)  /* 1 = motor on */
#define CTL_DDEN        _BV(4)  /* 1 = double density (MFM) */
#define CTL_ROM_BANK    _BV(6)  /* 0 = ROM at 0x0000, 1 = RAM at 0x0000 */

/* Helpers */
#define ctl_read()              inp(CTL_LATCH)
#define ctl_write(v)            outp(CTL_LATCH, (v))
#define ctl_set(bits)           port_set(CTL_LATCH, (bits))
#define ctl_clr(bits)           port_clr(CTL_LATCH, (bits))
#define ctl_drive(d)            outp(CTL_LATCH, (inp(CTL_LATCH) & ~CTL_DRIVE_MASK) | ((d) & CTL_DRIVE_MASK))


/* ══════════════════════════════════════════════════════════════════════════
 * 6545 CRTC — CRT Controller (video)
 * ══════════════════════════════════════════════════════════════════════════ */

#define CRTC_ADDR       0x1C    /* write: select internal register */
#define CRTC_DATA       0x1D    /* read/write: access selected register */
#define CRTC_STROBE     0x1F    /* read: light pen strobe (also used as status) */

/* CRTC internal register indices (write index to CRTC_ADDR, then data to CRTC_DATA) */
#define CRTC_R0_HTOTAL  0       /* horizontal total characters - 1 */
#define CRTC_R1_HDISP   1       /* horizontal displayed characters */
#define CRTC_R2_HSYNC   2       /* horizontal sync position */
#define CRTC_R3_SYNC_W  3       /* sync widths (bits 7-4: vsync, bits 3-0: hsync) */
#define CRTC_R4_VTOTAL  4       /* vertical total rows - 1 */
#define CRTC_R5_VADJ    5       /* vertical total adjust (scan lines) */
#define CRTC_R6_VDISP   6       /* vertical displayed rows */
#define CRTC_R7_VSYNC   7       /* vertical sync position */
#define CRTC_R8_MODE    8       /* interlace and skew */
#define CRTC_R9_SCANMAX 9       /* maximum scan line address */
#define CRTC_R10_CSTART 10      /* cursor start (bits 6-5: blink, bits 4-0: scan line) */
#define CRTC_R11_CEND   11      /* cursor end scan line */
#define CRTC_R12_START_H 12     /* display start address high byte */
#define CRTC_R13_START_L 13     /* display start address low byte */
#define CRTC_R14_CUR_H  14      /* cursor address high byte */
#define CRTC_R15_CUR_L  15      /* cursor address low byte */
#define CRTC_R16_LP_H   16      /* light pen address high byte (read only) */
#define CRTC_R17_LP_L   17      /* light pen address low byte (read only) */

/* CRTC cursor blink mode (bits 6-5 of R10) */
#define CRTC_CUR_NOBLINK    0x00
#define CRTC_CUR_NOBLINK2   0x20
#define CRTC_CUR_BLINK_16   0x40    /* blink at 1/16 field rate */
#define CRTC_CUR_BLINK_32   0x60    /* blink at 1/32 field rate */

/* CRTC access helpers */
#define crtc_write(reg, val)    do { outp(CRTC_ADDR, (reg)); outp(CRTC_DATA, (val)); } while(0)
#define crtc_read(reg)          (outp(CRTC_ADDR, (reg)), inp(CRTC_DATA))

/* Set display start address (16-bit video RAM address, for hardware scrolling) */
#define crtc_set_start(addr) \
    do { \
        crtc_write(CRTC_R12_START_H, (uint8_t)(((addr) >> 8) & 0x3F)); \
        crtc_write(CRTC_R13_START_L, (uint8_t)((addr) & 0xFF)); \
    } while(0)

/* Set cursor address */
#define crtc_set_cursor(addr) \
    do { \
        crtc_write(CRTC_R14_CUR_H, (uint8_t)(((addr) >> 8) & 0x3F)); \
        crtc_write(CRTC_R15_CUR_L, (uint8_t)((addr) & 0xFF)); \
    } while(0)


/* ══════════════════════════════════════════════════════════════════════════
 * Parallel Printer Port
 * ══════════════════════════════════════════════════════════════════════════ */

#define PRINTER_DATA    0x18    /* write: printer data byte */


/* ══════════════════════════════════════════════════════════════════════════
 * Scratch RAM layout — 81-292-A ROM
 * These would be mapped to C globals via #pragma output CRT_ORG_BSS = 0xFB00
 * or accessed via explicit pointer casts for direct compatibility with ROM code.
 * ══════════════════════════════════════════════════════════════════════════ */

/* Disk state (0xFB00–) */
#define SCRATCH_SECTOR      ((volatile uint8_t  *)0xFB00)  /* current sector */
#define SCRATCH_DMA_ADDR    ((volatile uint16_t *)0xFB01)  /* DMA address */
#define SCRATCH_TRACK       ((volatile uint8_t  *)0xFB03)  /* current track */
#define SCRATCH_DMA_PTR     ((volatile uint16_t *)0xFB14)  /* DMA buffer pointer */
#define SCRATCH_SEC_BUF     ((volatile uint8_t  *)0xFB16)  /* 128-byte sector buffer */

/* Video / system state (0xFD00–) */
#define SCRATCH_DRIVE       ((volatile uint8_t  *)0xFD16)  /* current drive */
#define SCRATCH_BAUD_CFG    ((volatile uint8_t  *)0xFD17)  /* baud rate / SIO config (9 bytes) */
#define SCRATCH_ESC_STATE   ((volatile uint8_t  *)0xFD74)  /* ESC sequence parser state */
#define SCRATCH_CUR_ROW     ((volatile uint8_t  *)0xFD75)  /* cursor row */
#define SCRATCH_CUR_COL     ((volatile uint8_t  *)0xFD76)  /* cursor column */
#define SCRATCH_VID_ATTR    ((volatile uint8_t  *)0xFD77)  /* video attribute flags */
#define SCRATCH_VID_CUR_PTR ((volatile uint16_t *)0xFD78)  /* video RAM cursor pointer */
#define SCRATCH_VID_BASE    ((volatile uint16_t *)0xFD7A)  /* video RAM base address */


/* ══════════════════════════════════════════════════════════════════════════
 * Video RAM
 * ══════════════════════════════════════════════════════════════════════════ */

#define VRAM_BASE       0xF000  /* start of 4KB video RAM */
#define VRAM_COLS       80
#define VRAM_ROWS       24
#define VRAM_SIZE       (VRAM_COLS * VRAM_ROWS)     /* 1920 bytes */

#define vram_ptr(row, col)  ((volatile uint8_t *)(VRAM_BASE + (row) * VRAM_COLS + (col)))


#endif /* KAYPRO_H */
