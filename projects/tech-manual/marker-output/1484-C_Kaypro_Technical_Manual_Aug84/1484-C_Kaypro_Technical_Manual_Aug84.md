KAYPRO TOCHNlCAL MANuAL

AUGUST 1984

#### CONTENTS

| SECTION    |                                                          | PAGE     |
|------------|----------------------------------------------------------|----------|
| 1.0        | Introduction                                             |          |
| 1.1<br>1.2 | Purpose of Technical Manual<br>Scope of Technical Manual | 11<br>12 |
| 1.2        | scope of recrifical randar                               | 12       |
| 2.0        | FCC Information                                          | 2-1      |
| 3.Ø        | Model Specifications                                     |          |
| 3.1        | KAYPRO 2                                                 | 31       |
| 3.2        | KAYPRO 2/84 and 2X                                       | 32       |
| 3.3        | KAYPRO 4                                                 | 33       |
| 3.4        | KAYPRO 4/84                                              | 34       |
| 3.5        | KAYPRO 4X                                                | 35       |
| 3.6        | KAYPRO 1Ø                                                | 36       |
| 3.7        | KAYPRO ROBIE                                             | 37       |
| 4.0        | RCM Revisions CP/M Compatibility                         | 41       |
| 5.0        | Chassis                                                  |          |
| 5.1        | Removal/Replacement of Hood (Exc. ROBIE)                 | 5-1      |
| 5.2        | Touch-up Information                                     | 52       |
| 6.Ø        | Mainboards—Troubleshooting Tips                          | 61       |
| 6.1        | KAYPRO 2 (81-110-n)                                      | 62       |
| 6.2        | KAYPRO 2/4 (81-240-n)                                    | 68       |
| 6.3        | KAYPRO 10 (81-180-n)                                     | 616      |
| 6.4        | KAYPRO 2/84 and 2X (81-294-n)                            | 626      |
| 6.5        | KAYPRO 4/84 (81-184)                                     | 635      |
| 6.6        | KAYPRO ROBIE (81-296-n)                                  | 644      |
| 6.7        | Removal/Installation Instructions                        | 653      |
| 7.Ø        | CRT Assemblies                                           |          |
| 7.1        | Descriptions and Adjustments                             | 71       |
| 7.2        | Video Alignment                                          | 73       |
| 7.3        | Video Signals on KAYPRO Mainboard                        | 7-4      |
| 7.4        | ALIGN.MAC Diagnostic Listing                             | 75       |
| 7.5        | Removal/Installation Instructions                        | 78       |

## CONTENTS (Continued)

| SECTION       |                                         | PAGE |
|---------------|-----------------------------------------|------|
| 8.0           | Power Supplies                          |      |
| 8.1           | Introduction                            | 81   |
| 8.2           | Description and 220V Configuration      | 82   |
| 8.3           | Removal/Installation Instructions       | 85   |
| 9.0           | Diskette Drives                         |      |
| 9.1           | Introduction/Disk Drive Cleaning        | 91   |
| 9.2           | Which Brand of Drive Is It?             | 92   |
| 9.3           | Jumpering Diagrams                      | 95   |
| 9.4           | High-Density (Drivetec) Drives          | 99   |
| 9.5           | Removal/Installation Instructions       | 910  |
| 10.0          | Hard Disk Drives (KAYPRO 10)            |      |
| 10.1          | Introduction                            | 101  |
| 10.2          | Description                             | 1Ø2  |
| 10.3          | Hard Drive Configuration                | 103  |
| 10.4          | Hard Drive or Floppy Drive Removal/     |      |
|               | Installation Instructions (KAYPRO 10)   | 104  |
| 11.0          | Hard Drive Controller Board (KAYPRO 10) |      |
| 11.1          | Description                             | 11-1 |
| 11.2          | Removal/Installation Instructions       | 112  |
| 12.0          | Interface Board (KAYPRO 10)             |      |
| 12.1          | Description                             | 121  |
| 12.2          | Removal/Installation Instructions       | 12-2 |
| 13 <b>.</b> Ø | Keyboards                               | 13—1 |
| 14.0          | ROBIE Removal/Installation Instructions |      |
| 14.1          | Chassis Covers                          | 141  |
| 14.2          | Diskette Drives                         | 142  |

## CONTENTS (Continued)

| SECTION |                                      | PAGE             |
|---------|--------------------------------------|------------------|
| 15.Ø    | Troubleshooting                      |                  |
| 15.1    | Introduction                         | 151              |
| 15.2    | KAYPRO 2 and 4 Symptom—Fix Guides    | 152              |
| 15.3    | KAYPRO 10 Symptom—Fix Guide          | 158              |
| 15.4    | ROBIE Symptom—Fix Guide              | 1515             |
| 15.5    | KAYPRO 2/84 and 2X Symptom—Fix Guide | 1521             |
| 15.6    | KAYPRO 4/84 and 4X Symptom—Fix Guide | 1522             |
| 16.Ø    | System I/O                           |                  |
| 16.1    | Video Command Protocol               | 161              |
| 16.2    | Keyboard Codes and Functions         | 162              |
| 16.3    | Connector Pin-Outs                   | 163              |
| 16.4    | Port Addresses                       | 1610             |
| 17.Ø    | Reference Section                    |                  |
| 17.1    | ASCII Chart                          | 171              |
| 17.2    | Memory Maps                          | 172              |
| 17.3    | Vendor Addresses                     | 17 <del></del> 6 |
| 18.0    | Suggested References                 | 18-1             |

INDEX

#### 1.0 INTRODUCTION

#### 1.1 PURPOSE OF TECHNICAL MANUAL

This publication is intended to be a technical reference guide to be used by trained repair technicians. It will attempt to cover all dealer-serviceable sections of Kaypro computers. This manual replaces previous manuals on the subject.

The procedures and information contained in this manual assume technical expertise on the part of the reader. To avoid personal injury, do not perform any servicing unless you are a qualified service technician.

It is our desire to provide dealers with the information and support needed to expedite repairs and provide the users with the service they deserve. We encourage your comments and suggestions regarding this manual.

#### 1.2 SCOPE OF TECHNICAL MANUAL

The information and procedures occurred by this manual assume some technical knowledge on the part of the reader.

The policy of Kaypro Corporation is to repair computers to the modular level only. Even Kaypro's repair technicians do not repair switching power supplies, CRT assemblies, or disk drives. Repairs to modular components not manufactured by Kaypro Corporation (power supplies, CRT assemblies, disk drives) are NOT covered by this manual.

However, we do not discourage dealers and technicians who have the knowledge and the tools to repair to the component level from doing so, on out-of-warranty Kaypro computers.

The adjustment and removal/replacement information in this manual is organized by module type, with the exception of removal/replacement information for the KAYPRO ROBIE, which is placed in a separate section due to the differences in chassis design and hardware module placement in that machine.

#### 2.Ø FCC INFORMATION

As Kaypro keeps in step with computer technology, the models have changes which affect FCC ratings. The proper rating is affixed to the back of each computer. Contact the Kaypro Engineering Department if you need further information.

#### 3.0 MODEL SPECIFICATIONS

#### 3.1 KAYPRO 2 SPECIFICATIONS

CPU Z-80 2.5 MHz

RAM 64K bytes

MAINBOARD 81-110-n or 81-240-n series.

DISK STORAGE Two 5-1/4 inch, double-density, single-

sided, floppy disk drives, providing 191K bytes of storage per diskette.

KEYBOARD Detachable, 72 key typewriter style

keyboard with 18 programmable keys.

VIDEO SCREEN Non-glare, 9-inch, green phosphor

screen with a 25 row x 80 column

display.

I/O CONNECTIONS One "Centronics"-type parallel

port, one RS-232C serial port.

## 3.2 KAYPRO 2/84 and 2X SPECIFICATIONS

CPU

Z80-A 4.0 MHz

RAM

64K bytes

MAINBOARD

81-294-n series.

DISK STORAGE (Kaypro 2/84) Two 5-1/4 inch double-density, single-sided, floppy disk drives, providing 191K bytes of storage per diskette.

DISK STORAGE (Kaypro 2X)

Two 5-1/4 inch double-density, double-sided, floppy disk drives, providing 390K bytes of storage per diskette.

KEYBOARD

Detachable, 72 key typewriter style keyboard with 18 programmable keys.

VIDEO SCREEN

Non-glare, 9-inch, green phosphor screen with a 25 row x 80 column

display.

I/O CONNECTIONS

One "Centronics"-type parallel port,

two RS-232C serial ports.

#### 3.3 KAYPRO 4 SPECIFICATIONS

CPU Z-80 2.5 MHz

RAM 64K bytes

MAINBOARD 81-240-n series.

DISK STORAGE Two 5-1/4 inch double-density, double-

sided, floppy disk drives, providing 390K bytes of storage per diskette.

KEYBOARD Detachable, 72 key typewriter style

keyboard with 18 programmable keys.

VIDEO SCREEN Non-glare, 9-inch, green phosphor

screen with a 25 row x 80 column

display.

I/O CONNECTIONS One "Centronics"-type parallel port,

one RS-232C serial port.

#### 3.4 KAYPRO 4/84 SPECIFICATIONS

CPU Z-8ØA 4.Ø MHz

RAM 64K bytes

MAINBOARD 81-184-n series.

DISK STORAGE Two double-density, double-sided,

floppy disk drives, providing 390K

bytes of storage per diskette.

KEYBOARD Detachable, 72 key typewriter style

keyboard with 18 programmable keys.

VIDEO SCREEN Non-glare, 9-inch green phosphor

screen with a 25 row x 80 column

display.

I/O CONNECTIONS One "Centronics"-type parallel port,

two RS-232C serial ports, one RJ11C

modular telephone jack.

MODEM Built-in, 3000-baud modem, with Bell

System 103 compatibility. Uses Texas

Instruments TMS99531/TMS99532.

REAL-TIME CLOCK Built-in real-time clock. Uses National

MM58167.

#### 3.5 KAYPRO 4X SPECIFICATIONS

CPU Z-8ØA 4.Ø MHz

RAM 64K bytes

MAINBOARD 81-296-n series.

DISK STORAGE Two 5-1/4 inch, high-density, double-

sided, floppy disk drives providing 2.6M bytes of storage per diskette.

KEYBOARD Detachable, 72 key typewriter style

keyboard with 18 programmable keys.

VIDEO SCREEN Non-glare, 9-inch, green phosphor

screen with a 25 row x 80 column

display.

I/O CONNECTIONS One "Centronics"-type parallel

port, two RS-232C serial ports, one

RJ11C modular telephone jack.

MODEM Built-in, 300-baud modem, with Bell

System 103 compatibility. Uses Texas

Instruments TMS99531/TMS99532.

REAL-TIME CLOCK Built-in real-time clock. Uses National

MM58167.

#### 3.6 KAYPRO 10 SPECIFICATIONS

CPU

Z8ØA, 4.0 MHz

RAM

64K bytes

MAINBOARD

81-180-n series.

DISK STORAGE

One 5-1/4 inch double-density, doublesided, floppy disk drive providing 390K bytes of storage per diskette. One hard disk drive providing 10M

bytes of storage.

KEYBOARD

Detachable, 72 key typewriter style keyboard with 18 programmable keys.

VIDEO SCREEN

Non-glare, 9-inch, green phosphor screen

with a 25 row x 80 column display.

I/O CONNECTIONS

One "Centronics"-type parallel port,

two RS-232C serial ports.

#### 3.7 KAYPRO ROBIE SPECIFICATIONS

CPU Z8ØA, 4.0 MHz

RAM 64K bytes

MAINBOARD 81-296-n series.

DISK STORAGE Two 5-1/4 inch, high-density, double-

sided, floppy disk drives providing 2.6M bytes of storage per diskette.

KEYBOARD Detachable, 72 key typewriter style

keyboard with 18 programmable keys.

VIDEO SCREEN Non-glare, 9-inch, green phosphor screen

with a 25 row x 80 column display.

I/O CONNECTIONS One "Centronics"type parallel port,

two RS232C serial ports, one RJ11C

modular telephone jack.

MODEM Built-in, 300-baud modem, with Bell

System 103 compatibility. Uses Texas

Instruments TMS99531/TMS99532.

REAL-TIME CLOCK Built-in real-time clock. Uses National

MM58167.

|           | CP/M VERSICB | I <aypro pari'="" t<br="">(:fDr CP/M disk)</aypro> | ReM VERSIQT          |
|-----------|--------------|----------------------------------------------------|----------------------|
| 2/83      | 2.2F         | 0777                                               | 81-149-C or 81-232-A |
| 4/83      | 2.2F         | 1475                                               | 81-232-A             |
| 4/83 + 88 | 2.2F         | 1475                                               | 81-232-A             |
| 2/84      | 2.2G         | 2619                                               | 81-292-A             |
| 4/84      | 2.2G         | 2622                                               | 81-292-A             |
| 4/84 + 88 | 2.2G         | 2622                                               | 81-292-A             |
| 2 X       | 2.2G         | 2470                                               | 81-292-A             |
| 4X        | 2.2G         | 2340                                               | 81-326-E             |
| RCBIE     | 2.2G         | 2340                                               | 81-326-E             |

## **5.8 cassIS**

## **5.1 amssm IUD lBD1AL (FJCa:P1' I<AYPRO Ra3IE)**

- 1. Turn off the machine.
- 2. Disconnect AC power by unplugging the power oord :from wall outlet.
- 3. Remove the ten screws :from the chassis hood: there are two on top and :fOur on each side.
- 4. RsIove the hood :fran the chassis.

- 1. IDwer the hood onto the unit.
- 2. Align the two holes on top of the hood with those on top of the chassis.
- 3. Insert the two flat-head screws into the holes on the top of the chassis and start them, but do IDt tighten them yet.
- 4. Insert the eight round-head screws, :fOur on each side, and start them.
- 5. Tighten each screw securely.

#### 5.2 TOUCH-UP INFORMATION

Kaypro Corporation has small amounts of touch-up paint for Kaypro hoods and chassis available to the dealers. Contact the Hardware Technical Support personnel to obtain this paint.

Occasionally a customer's computer will have scratches on the hood or chassis. A <u>small</u> amount of rubbing compound, when carefully applied, will often smooth out very small scratches on a hood or chassis. Should painting be necessary, there are two sizes of sable paintbrushes to have on hand: size 00 and size 000. These brushes are available at any art supply store.

#### 6.0 MAINBOARDS

The following sections contain schematics, chip layout diagrams, and IC lists (by U-number) for Kaypro mainboards. This is not intended to be a theory of operation, but rather an aid to locating possible problems on a mainboard.

Consult an appropriate databook (TTL, Zilog, etc.) if you need to find out the internal workings of a particular IC.

#### MAINBOARD TROUBLESHOOTING TIPS:

A blank EPROM can be used to help troubleshoot Kaypro mainboards of series 81-110, 81-240, and 81-180. The appropriate model of EPROM (2732, 2716, etc) allows a quick check of the board. It will usually force the data and address lines to toggle at approximately the same amplitude, allowing the technician to use a scope to spot affected lines.

If the video display does not show a screen filled with alternating "9"'s and apostrophes, you have a problem in the video RAM or associated circuitry.

You can check the main RAM and associated circuitry quickly with a scope by looking at pin 14 on each of the RAM chips. There should be a pattern of signals like this:

For the 81-240 board:

| U2Ø (D7) | low    |
|----------|--------|
| U21 (D6) | low    |
| U22 (D5) | toggle |
| U23 (D4) | toggle |
| U24 (D3) | toggle |
| U25 (D2) | low    |
| U26 (D1) | low    |
| U27 (DØ) | toggle |

The U-numbers of the main RAM chips will vary depending on which mainboard you have, but the pattern will be the same.

### IC LIST, KAYPRO 2 (81-110-n)

Reference Designation

### Description

| Ul                 | 74LS161 | 4-bit counter                   |
|--------------------|---------|---------------------------------|
| U2,U67*            | 74HCUØ4 | Hex inverter, CMOS              |
| U3                 | 74LS29Ø | decade counter                  |
| U4                 | 74LS10  | Tri NAND gates                  |
| U6, U11            | 74LS393 | Dual binary counter             |
| U9, U8Ø            | 74LSØ8  | Quad AND gates                  |
| UlØ, U61           | 73LS32  | Quad OR Gates                   |
| U12, U14, U32      | 74LS74  | Dual "D" flip-flop              |
| U15, U39           | 74LSØØ  | Quad NAND Gates                 |
| Ul6 through Ul9    | 74LS157 | Quad 2/1 MUX                    |
| U20 through U27    | MCM6665 | (or equivalent) 64K x 1 RAM     |
| U28 through U31    | 2114    | 1K x 4 RAM                      |
| U33, U34           | 74157   | Quad 2/1 MUX                    |
| U35, U38           | 8216    | Quad Bi-directional MUX         |
| U36                | 74LS2Ø  | Dual NAND gates                 |
| U37, U56, U85      | 74LSØ2  | Quad NOR gates                  |
| U41                | 74S151  | 8/1 MUX                         |
| U <b>42</b>        | 74LS174 | Hex "D" flip-flop               |
| U43                | 81-146  | Character generator EPROM       |
| U44, U45, U64, U65 | 74LS243 | Quad bus trans                  |
| U47                | 81-149  | Boot EPROM                      |
| U48, U73           | 74LSØ4  | Hex inverter                    |
| U49, U52, U62      | 74LS241 | Octal buffer                    |
| U54, U72           | Z8Ø PIO | ,                               |
| U57, U58, U6Ø      | 74LS138 | 3/8 MUX                         |
| U59                | 74LS373 | Octal "D" latch                 |
| U63                | Z8Ø CPU |                                 |
| U66                | 74164   | 8-bit shift register            |
| U68                | 1488    | Quad line driver (OUT)          |
| U69                | 1489    | Quad SCHMITT line receiver (IN) |
| U <b>7Ø</b>        | Z8Ø SIO |                                 |
| U <b>7</b> 1       | 74SØ4   | Hex inverter                    |
| U <b>7</b> 8       | 8116    | Dual programmable baud rate     |
|                    |         | generator                       |
| U81                | 74Ø6    | Hex inverter, open collector    |
| U82                | FD1793  | Floppy disk controller          |
| U84                | 74LS195 | 4-bit shift register            |
| U86                | 74LS293 | 4-bit binary counter            |
| U87                | 74LS39Ø | Dual decade counter             |
| U88                | FDC9216 | Data separator                  |

\*NOTE: THERE ARE SOME VERSIONS OF THE 81-110 BOARD ON WHICH U2 AND U67 ARE NOT CMOS IC.S BUT ARE NORMAL TTL ICS. READ THE NUMBER ON THE IC TO BE SURE.

### SCOPE SIGNALS TO AID IN TROUBLESHOOTING (81-110-n)

The examples of correct signals shown below do not represent all of the signals on a Kaypro mainboard, since most signals will be simple high-low toggles. A group of video signals (CCØ through CC3) are included as illustrations of the timing relationships between the various video signals. Note that only one of the I/O signals on U57 will be low at any given time.

State of the machine: The door of drive A is open; the machine is waiting to boot.

The signal measurements were made using a Tektronix oscilloscope, model 2213. It has a bandwidth of DC-60 MHz, sensitivity of 2mV/cm, a sweep delay of 0.1 microseconds to 1 second, and a graticule display measuring 8 x 10 cm.

Signal M1 from pin 27 of the CPU (U63) was triggered on. This signal is shown in the top half of each display and was channel 1. Ground for the signals shown on channel 2 was established at first graticule line above the bottom of the display.

Each square of the representation is the equivalent of one square cm on the graticule. The scope was set for 2V/div, for all figures, and was set for .5 micro-secs/div. for all figures EXCEPT figure 6, which was taken using 1 micro-secs/div.

Figure 1: Pin 6 of U63, 2.5MHz clock signal.

Figure 2: Pin 24 of U82, lMHz clock signal.

Figure 3: Pin 3 of U6, CCØ.

Figure 4: Pin 4 of U6, CCl.

Figure 5: Pin 5 of U6, CC2.

Figure 6: Pin 6 of U6, CC3.

### SIGNAL LOCATIONS ON MAINBOARD 81-110-n

| The state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the state of the s | IC          |         |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------|---------|
| SIGNAL                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         | LCCATION    | PIN NO. |
| CPU SIGNALS                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |             |         |
| 2.5 MHz                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        | U 63        | 6       |
| MREQB                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          | U 62        | 16      |
| RDB                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | U 62        | 5       |
| WRB                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | U 62        | 14      |
| MEMORY SIGNALS                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |             |         |
| RAS                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | U 39        | 11      |
| CAS                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | บ <b>66</b> | . 5     |
| MUXC                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           | U 66        | 4       |
| VIDEO CLOCK SIGNALS                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |             |         |
| CLCCK, YI                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      | U 2         | 8       |
| CCØ                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | U 6         | . 3     |
| CC1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | U 6         | 4       |
| CC2                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | U 6         | 5       |
| CC3                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | บ 6         | 6       |
|                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |             |         |

**KAYPRO 2 and 4 BLOCK DIAGRAM** 

## IC LIST, KAYPRO 2/4 (81-246-n)

| Reference   |
|-------------|
| Designation |

## Description

| U1                 | 74LS161         | 4-bit counter                   |
|--------------------|-----------------|---------------------------------|
| U2, U67            | 74HCUØ4         | Hex inverter, CMOS              |
| บ3                 | 74LS29Ø         | Decade counter                  |
| U4                 | 74LS1Ø          | Tri NAND gates                  |
| U6,U11             | 74LS393         | Dual binary counter             |
| U9, U8Ø            | 74LSØ8          | Quad AND gates                  |
| U1Ø, U61           | 73LS32          | Quad OR Gates                   |
| U12, U14, U32      | 74LS74          | Dual "D" flip-flop              |
| U15, U39           | 74LSØØ          | Quad NAND Gates                 |
| Ul6 through Ul9    | 74LS157         | Quad 2/1 MUX                    |
| U2Ø through U27    | MCM6665         | (or equivalent) 64K x l RAM     |
| U28 through U31    | 2114            | 1K x 4 RAM                      |
| U33, U34           | 74157           | Quad 2/1 MUX                    |
| U35, U38           | 8216            | Quad Bi-directional MUX         |
| U36                | 74LS2Ø          | Dual NAND gates                 |
| U37, U56, U85      | 74LSØ2          | Quad NOR gates                  |
| U41                | 7 <b>4S</b> 151 | 8/1 MUX                         |
| U42                | 74LS174         | Hex "D" flip-flop               |
| U43                | 81-146-n        | Character generator EPROM       |
| U44, U45, U64, U65 | 74LS243         | Quad bus trans                  |
| U47                | 81-232-n        | Boot EPROM                      |
| U48, U73           | 74LSØ4          | Hex inverter                    |
| U49, U52, U62      | 74LS241         | Octal buffer                    |
| U54 <b>,</b> U72   | Z8Ø PIO         | _                               |
| U57, U58, U6Ø      | 74LS138         | 3/8 MUX                         |
| U59                | 74LS373         | Octal "D" latch                 |
| U63                | Z8Ø CPU         |                                 |
| U66                | 74164           | 8-bit shift register            |
| U68                | MC1488          | Quad line driver (OUT)          |
| U69                | MC1489          | Quad SCHMITT line receiver (IN) |
| U7Ø                | z8Ø SIO         |                                 |
| U71                | 74SØ4           | Hex inverter                    |
| U78                | 8116            | Dual programmable baud rate     |
|                    |                 | generator                       |
| U81                | 7406            | Hex inverter, open collector    |
| U82                | 1793            | Floppy disk controller          |
| U84                | 74LS195         | 4-bit shift register            |
| U86                | 74LS293         | 4-bit binary counter            |
| U87                | 74LS39Ø         | Dual decade counter             |
| U88                | FDC9216         | Data separator                  |

#### SCOPE SIGNALS FOR TROUBLESHOOTING 81-240-n

The examples of correct signals shown below do not represent all of the signals on a Kaypro mainboard, since most signals will be simple high-low toggles. A group of video signals (CCØ through CC3) are included as illustrations of the timing relationships between the various video signals. Note that only one of the I/O signals on U57 will be low at any given time.

State of the machine: with a blank, 2732, EPROM inserted in place of normal EPROM at location U 47. The door of drive A is open; the machine is waiting to boot.

The signal measurements were made using a Tektronix oscilloscope, model 2213. It has a bandwidth of DC-60 MHz, sensitivity of 2mV/cm, a sweep delay of 0.1 microseconds to 1 second, and a graticule display measuring 8 x 10 cm.

Signal M1 from pin 27 of the CPU (U63) was triggered on. This signal is shown in the top half of each display and was channel 1. Ground for the signals shown on channel 2 was established at first graticule line above the bottom of the display.

Each square of the representation is the equivalent of one square cm on the graticule. The scope was set for 2V/div, for all figures, and was set for .5 micro-secs/div, for all figures EXCEPT figure 6, which was taken using 1 micro-secs/div.

Figure 1: Pin 6 of U63, 2.5MHz clock signal.

Figure 2: Pin 24 of U82, 1MHz clock signal.

Figure 3: Pin 3 of U6, CCØ.

Figure 4: Pin 4 of U6, CCl.

Figure 5: Pin 5 of U6, CC2.

Figure 6: Pin 6 of U6, CC3.

## SIGNAL LOCATIONS, 81-246-n

|                                                                | IC                                   |                         |
|----------------------------------------------------------------|--------------------------------------|-------------------------|
| SIGNAL                                                         | LOCATION                             | PIN NO.                 |
| CPU SIGNALS                                                    |                                      |                         |
| CPU clock<br>1 MHz<br>2 MHz<br>MREQB<br>RDB<br>M1R (reference) | U 67<br>U 87<br>U 87<br>U 62<br>U 62 | 6<br>13<br>3<br>16<br>5 |
| MEMORY SIGNALS                                                 |                                      |                         |
| RAS<br>CAS<br>MUXC                                             | U 39<br>U 66<br>U 66                 | 11<br>5<br>4            |
| VIDEO CLOCK SIGNALS                                            |                                      |                         |
| CLCCK, YI<br>CCØ<br>CCI<br>CC2<br>CC3                          | U 2<br>U 6<br>U 6<br>U 6<br>U 6      | 8<br>3<br>4<br>5<br>6   |

## IC LIST, 81-180-n

| Reference<br>Designation               |                 | Description                                     |
|----------------------------------------|-----------------|-------------------------------------------------|
| Ul                                     | 7 <b>4</b> S74  | Dual "D" flip-flop                              |
| U2                                     | 74SØ8           | Hex Schmitt Quad AND gate                       |
| U3                                     | 74SØ4           | Hex inverter                                    |
| U4, U1Ø                                | 1489            | Quad SCHMITT line receiver                      |
| U5, U38, U41                           | 74LS244         | Octal buffer                                    |
| U6, U21, U24, U33, U49                 | 74LS74          | Dual "D" flip-flop                              |
| U2Ø, U3Ø                               | 74LSØ8          | Quad AND gate                                   |
| U8, U37, U5Ø                           | 74LSØØ          | Quad NAND gate                                  |
| U9, U59                                | 74LS393         | Dual binary counter                             |
| U11, U18, U31, U45,                    | 74LS373         | Octal "D' latch                                 |
| U46, U6Ø                               | 74.0100         | 2/2                                             |
| U12, U19<br>U13                        | 74LS138<br>74Ø6 | 3/8 MUX                                         |
| U14                                    | 7486<br>74886   | Hex inverter, open collector                    |
| U15, U61                               | 74S2Ø           | Hex Schmitt Quad XOR gate<br>Dual NAND gate     |
| U16                                    | 8116            | Dual programmable baud rate                     |
| 010                                    | 0110            | generator                                       |
| U17                                    | 1488            | Quad transmitter                                |
| U22                                    | 74LS165         | 8-bit shift register                            |
| U23, U27                               | Z8ØA SIO        |                                                 |
| U25, U72                               | 74LS10          | Tri NAND gate                                   |
| U26                                    | 81-187          | Character generator EPROM (2732)                |
| U28                                    | Z8ØA CPU        |                                                 |
| U29                                    | 74LS195         | 4-bit shift register                            |
| U32, U43                               | 74LSØ2          | Quad NOR gate                                   |
| U34                                    | 74LS14          | Hex Schmitt inverter                            |
| U35, U44                               | 6116            | RAM, 2K x 8-bit (200ns)                         |
| U36                                    | 6545A-1         | Video controller                                |
| U39, U54                               | 74LS245         | Bi-directional 8-bit buffer                     |
| U42                                    | 81-3Ø2-C        | Boot EPROM (2732)                               |
| U4Ø                                    | 74LS32          | Quad OR gate                                    |
| U47, U48                               | 74LS157         | Quad 2/1 MUX                                    |
| U51, U52, U57, U58, U62, U63, U68, U69 | 4565N-15        | Dynamic RAM 64K x 1 (150/ns)<br>(Mostek number) |
| U53                                    | 74LS163         | Synchronous 4-bit binary counter                |
| U55                                    | 14-2-392        | 14-Pin pull-up resistor                         |
| U56, U65                               | 74LSØ4          | Hex inverter                                    |
| U64, U67                               | 74HCUØ4         | Hex inverter, CMOS                              |
| U66                                    | 74LS93          | Asynchronous 4-bit binary counter               |
| U73<br>U74                             | WD9216<br>1793  | Data separator                                  |
| 0/4                                    | 1/33            | Floppy disk controller                          |

#### SCOPE SIGNALS FOR TROUBLESHOOTING 81-180-n

The examples of correct signals shown here do not represent all of the signals on the 81-180-n mainboard, since most of the signals will be high-low toggles. A group of signals taken from a video clock divider (U66) are shown to illustrate the timing relationships between the various video signals.

The signal measurements were made using a Tektronix ocilloscope, model 2213. It has a bandwidth of DC-60 MHz, sensitivity of 2mV/cm, a sweep delay of 0.1 microseconds to 1 second, and a graticule display measuring 8 x 10 cm.

Each square of the representation is the equivalent of one square cm. on the graticule. The scope was set for 2V/div. and .2micro-secs/div. for all figures except figure 2, which was set at .5micro-secs/div.

Signal M1 from pin 27 of the CPU (U28) was triggered on. This signal is shown in the top half of each display and was channel 1. Ground for signals shown on channel 2 was established at the first graticule line above the bottom of the display.

State of the machine: The machine has just booted-up on the hard drive.

Figure 1: Pin 6 of U28, 4MHz clock signal:

Figure 2: Pin 24 of U74, 1MHz clock signal.

Figure 3: Pin 12 of U66, video, clock divider.

Figure 4: Pin 9 of U66, video, clock divider.

Figure 5: Pin 8 of U66, video, clock divider.

Figure 6: Pin 11 of U66, video, clock divider.

**KAYPRO 10 BLOCK DIAGRAM** 

## IC LIST, 81-294-n

### Reference Designation

## Description

| Ul, U54     |                | 74Ø6              | Hex inverter, open collector |
|-------------|----------------|-------------------|------------------------------|
| U2, U25,    | U <b>7</b> 1   | 74LS14            | Hex Schmitt inverter         |
| U3, U5      |                | 1489              | Quad Scmitt line driver      |
| U4          |                | 1488              | Quad line driver             |
| U6, U13,    | U14,U55, U58   | 74LS373           | Octal "D" latch              |
| U8          |                | 74LS374           | Octal "D" flip-flop          |
| U9          |                | 81-235-n          | Character PROM (2732)        |
| ALL         |                | 81-189            | Custom gate array            |
| U11, U17    |                | Z8Ø SIO           | <u> </u>                     |
| U15, U23    |                | 6116              | Video RAM                    |
| U16         |                | 6545EA            | CRT controller               |
| U2Ø, U31    |                | 74LS245           | Octal bus transceiver        |
| U22         |                | 3.9K              | Pull-up Resistor             |
| U24         |                | WD1943/           | Dual programmable baud rate  |
|             |                | 8116              | generator                    |
| U26, U27    |                | 74LS138           | 3/8 MUX                      |
| U28, U51    |                | 74LS244           | Octal buffer/line driver     |
|             |                |                   | (3-state outputs)            |
| 127         |                | 81-194            | Custom gate array            |
|             | U38, U39, U41, | 2164              | 64K x 1 RAM                  |
| U42, U47,   | U48            |                   |                              |
| U34         |                | 81-292            | Boot PROM (2764)             |
| • •         | U59, U72       | 74LSØ2            | Quad NOR gate                |
| U4Ø         |                | 74LSØØ            | Quad NAND gate               |
| U43         |                | Z8ØA CPU          |                              |
| U44         |                | 1793              | Floppy disk controller       |
| U46         |                | 74LSØ4            | Hex inverter                 |
| U52         |                | 74LS32            | Quad OR gate                 |
| U <b>6Ø</b> |                | 74LS195           | 4-bit shift register         |
| U61         |                | 74LSØ8            | Quad AND gate                |
| U65         |                | 74LS1Ø            | Tri NAND gate                |
| U66, U75    |                | 74LS74            | Dual "D" flip-flop           |
| U67<br>U73  |                | FDC9216<br>74HCØØ | Data separator               |
| 0/3         |                | / HICKU           | Quad NAND gate               |

\*\*\*\*\*\*\*

Scope signals for this mainboard will be available soon; the section will be sent to the dealers for insertion into the new Technical Reference Manual as soon as it is available.

\*\*\*\*\*\*

## IC LIST, 81-184-n

| Reference   |
|-------------|
| Designation |

## Description

| Ul, U54                  | 7406      | Hex inverter, open collector            |
|--------------------------|-----------|-----------------------------------------|
| U2, U25, U71             | 74LS14    | Hex Schmitt inverter                    |
| U3, U5                   | 1489      | Ouad Schmitt line driver                |
| U4                       | 1488      | Quad line driver                        |
| U6, U13, U14, U55, U58   | 74LS373   | Octal "D" latch                         |
| U7                       | 74LS38    | Positive-NAND buffer                    |
| U8                       | 74LS374   | Octal "D" flip-flop                     |
| U9                       | 81-235    | Character PROM (2732)                   |
| U1Ø                      | 81-189    | Custom gate array                       |
| Ull, Ul7                 | Z8ØA SIO  | _                                       |
| U12                      | LM324     | Op-Amp                                  |
| U15, U23                 | 6116      | Video RAM                               |
| U16                      | 6545A     | Video controller                        |
| U18                      | TMS 99532 | Modem                                   |
| U19                      | TMS 99531 | Dialer                                  |
| U2Ø, U31                 | 74LS245   | Octal bus transceiver (3-state outputs) |
| U21                      | 4N35      | Photo isolator                          |
| U22                      | 3.9K      | Pullup resistor, 14-pin DIP             |
| U24                      | WD1943/   | Dual programmable baud rate             |
|                          | 8116      | generator                               |
| U26, U27                 | 74LS138   | 3/8 MUX                                 |
| U28, U51                 | 74LS244   | Octal buffer/line driver                |
| U29                      | 81-194    | Custom gate array                       |
| U32, U33, U38, U39, U41, | 2164      | 64K x 1 RAM                             |
| U42, U47, U48            |           |                                         |
| U34                      | 81-292    | Boot PROM (2764)                        |
| U35                      | Z8ØA PIO  |                                         |
| U36                      | MM581678  | Clock                                   |
| U37, U45, U59, U72       | 74LSØ2    | Quad NOR gate                           |
| U4Ø                      | 74LS00    | Quad NAND gate                          |
| U43                      | zsøa cpu  |                                         |
| U44                      | 1793      | Floppy disk controller                  |
| U46                      | 74LSØ4    | Hex inverter                            |
| U52                      | 74LS32    | Quad OR gate                            |
| U53, U7Ø, U74, U75       |           | Spares                                  |
| U6Ø                      | 74LS195   | 4-bit shift register                    |
| U61                      | 74LSØ8    | Quad AND gate                           |
| U65                      | 74LS10    | Tri NAND gate                           |
| U66, U75                 | 74LS74    | Dual "D" flip-flop                      |
| U67                      | FDC9216   | Data separator                          |
| U73                      | 74HCØØ    | Quad NAND gate                          |

\*\*\*\*\*\*

Scope signals for this mainboard will be available soon; the section will be sent to the dealers for insertion into the new Technical Reference Manual as soon as it is available.

\*\*\*\*\*\*

# KAYPRO.

## IC LIST, 81-296-n

## Reference Designation

## Description

| U1, U5<br>U2, U2<br>U3, U5<br>U4 | 25, U71         |       |        | 74Ø6<br>74LS14<br>1489<br>1488 | Hex inverter, open collector<br>Hex Schmitt inverter<br>Quad Schmitt line driver<br>Quad line driver |
|----------------------------------|-----------------|-------|--------|--------------------------------|------------------------------------------------------------------------------------------------------|
| U6, Ul                           | 3, U14,         | U55,  | U58    | 74LS373                        | Octal "D" latch                                                                                      |
| U7                               |                 |       |        | 74LS38                         | Positive-NAND buffer                                                                                 |
| U8                               |                 |       |        | 74LS374                        | Octal "D" flip-flop                                                                                  |
| U9                               |                 |       |        | 81-235                         | Character PROM (2732)                                                                                |
| UlØ<br>Ull, U                    | 11.7            |       |        | 81-189<br>Z8ØA SIO             | Custom gate array                                                                                    |
| U12, U                           | 17              |       |        | LM324                          | Ор-Аптр                                                                                              |
| U15, U                           | 23              |       |        | 6116                           | Video RAM                                                                                            |
| U16                              |                 |       |        | 6545EA                         | Video controller                                                                                     |
| U18                              |                 |       |        | TMS 99532                      | Modem                                                                                                |
| U19                              |                 |       |        | TMS 99531                      | Dialer                                                                                               |
| U2Ø, U                           | 31              |       |        | 74LS245                        | Octal bus transceiver                                                                                |
| U21                              |                 |       |        | 4N35                           | Photo Isolator                                                                                       |
| U22                              |                 |       |        | 3.9K                           | Pullup resistor, 14-pin DIP                                                                          |
| U24                              |                 |       |        | WD1943/                        | Dual programmable baud rate                                                                          |
| 1106 11                          | 27              |       |        | 8116                           | generator                                                                                            |
| U26, U2                          |                 |       |        | 74LS138<br>74LS244             | 3/8 MUX Octal buffer/line driver                                                                     |
| U29, U.                          | <b>J</b> 1      |       |        | 81 <b>-</b> 194                | Custom gate array                                                                                    |
|                                  | 33, U38,        | 1139. | 1141 . | 2164                           | 64K x 1 RAM                                                                                          |
|                                  | 47, U48         | 007,  | 0.11,  | 2101                           |                                                                                                      |
| U34                              |                 |       |        | 81-326                         | Boot PROM (2764)                                                                                     |
| U35                              |                 |       |        | Z8ØA PIO                       | · · · · · ·                                                                                          |
| U36                              |                 |       |        | MM581678                       | Clock                                                                                                |
| -                                | 45, U59,        | U72   |        | 74LSØ2                         | Quad NOR gate                                                                                        |
| U4Ø                              |                 |       |        | 74LSØØ                         | Quad NAND gate                                                                                       |
| U43                              |                 |       |        | Z8ØA CPU                       | Elemen diele eesteelles                                                                              |
| U44<br>U46                       |                 |       |        | 1793<br>74LSØ4                 | Floppy disk controller Hex inverter                                                                  |
| U52                              |                 |       |        | 74LS32                         | Quad OR gate                                                                                         |
|                                  | 74 <b>,</b> U75 |       |        | 7-11052                        | Spares                                                                                               |
| U6Ø                              | <b>,</b> 0,0    |       |        | 74LS195                        | 4-bit shift register                                                                                 |
| U61                              |                 |       |        | 74LSØ8                         | Quad AND gate                                                                                        |
| U65                              |                 |       |        | 74LS10                         | Tri NAND gate                                                                                        |
| U66, U7                          | 75              |       |        | 74LS74                         | Dual "D" flip-flop                                                                                   |
| U67                              |                 |       |        | FDC9216                        | Data separator                                                                                       |
| U73                              |                 |       |        | 74HCØØ                         | Quad NAND gate                                                                                       |

### SCOPE SIGNALS, 81-296-n

#### \*\*\*\*\*\*

Scope signals for this mainboard will be available soon; the section will be sent to the dealers for insertion into the new Technical Reference Manual as soon as it is available.

\*\*\*\*\*\*

#### 6.7 MAINBOARD REMOVAL

- 1. Turn off the machine and disconnect the AC power (5.1).
- 2. Remove the chassis hood (5.1).
- Remove the two screws from the front of the mainboard that attach the mainboard and the two plastic standoffs.
- 4. Remove the screws from the rear, top of the chassis that secure the mainboard. The KAYPRO 2/83 and 4/83 each have four Phillips-head screws and two hex-head screws. The KAYPRO 10, 2/84 and 4/84 each have three Phillips-head screws and four hex-head screws.
- 5. Remove the power, reset, and video plugs. On the KAYPRO 2/83 and 4/83 these are J1, J5, and J7. On the KAYPRO 10, 2/84 and 4/84 these are J1, J7, and J10.
- 6. Remove the ribbon cable(s). On the KAYPRO 2/83 and 4/83 this is J6. On the KAYPRO 10 they are J8 and J9. On the KAYPRO 2/84 and 4/84 this is J8.
- 7. Remove the mainboard.

#### MAINBOARD INSTALLATION

- Set the mainboard on the plastic standoffs, insert the screws, but do not tighten them yet.
- Align the ports and the keyboard jack with the openings on the rear, top of the chassis.
- Insert the screws through rear of chassis into mounting holes. Do not tighten yet.
- 4. The KAYPRO 2/83 and 4/83 each have four Phillips-head and two hex-head screws. The KAYPRO 10, 2/84 and 4/84 each have three Phillips-head and four hex-head screws.
- 5. Tighten the screws on the rear of the chassis and the screws that go into the plastic standoffs.
- 6. Replace the power, reset, and video plugs.
- Replace the ribbon cable(s).

#### 7.0 CRT ASSEMBLIES

#### 7.1 HARDWARE DESCRIPTIONS AND ADJUSTMENTS

Figure 7.1
Dotronix video board

Figure 7.2 Elston video board

#### VIDEO ADJUSTMENTS

At the current time Kaypro is using CRT assemblies produced by Dotronix, Elston, and Toshiba. The adjustment pots are positioned in different locations on the boards and can be located by using figures 7-1, 7-2, and 7-3. These pots are factory aligned and normally need no adjustment. The purpose of these adjustments is to obtain the correct size, centering, and brightness of the display.

Use only non-metallic tools when making these adjustments.

Before any adjustments are made on the video board, the ALIGN diagnostic should be invoked. This will fill the screen with H's and aid in adjustment.

#### HORIZONIAL CENTERING

Check to see that the pattern is centered on the screen. Adjust the horizontal hold pot until the display is correctly centered. On the Elston video board, adjust the video centering pot.

#### VERTICAL SIZE AND LINEARITY

The following two procedures are to be performed alternately until correct display is obtained.

Adjust the vertical size pot to obtain pattern height of approximately 4-7/8 inches.

Adjust vertical linearity pot until all characters are the same vertical size, top to bottom.

#### HORIZONTAL WIDTH

Adjust the horizontal width pot to obtain a display width of approximately 7 inches.

Figure 7.3 Toshiba video board

Figure 7.4
Yoke alignment

# HORIZONTAL HOLD (KAYPRO 2/83 and 4/83 with Dotronix only)

These procedures should be performed to adjust horizontal hold.

Attach one end of a test jumper to TP2 (test point 2). Attach the other end of the jumper to the heat sink at O3.

Adjust R43 (horizontal hold pot) until the display either stops scrolling or almost stops. (sometimes they don't stop scrolling complétely)

Disconnect the test jumper.

Adjust the horizontal deflection rings as needed.

#### FOCUS

Adjust the focus pot until the edges and center of the display image are in focus.

#### BRIGHINESS

To prolong the life of the CRT, the maximum brightness obtainable should not be excessive. If the brightness is excessive, adjust the brightness pot. If the raster lines are visible, the brightness pot should be adjusted until they disappear.

#### ALIGNING CRT YOKE

\*\*\* CAUTION \*\*\*
HIGH VOLTAGE IS PRESENT AT THIS POINT

Loosen the screw on the locking clamp (figure 7-4).

Grasp the white collar on the rear of the coil.

Turn the collar in the direction required to square the display.

Turn the collar slightly past the alignment point, as it will turn back slightly when released.

Tighten the locking screw.

#### VIDEO ADJUSTMENTS FOR MICREX CRT

The same procedures should be used to adjust the Micrex CRT assembly as those used for the other brands of CRTs.

Figure 7.5 Micrex video board

#### 7.2 PERFECT VIDEO ALIGNMENT EXAMPLE

Below is an example of perfect video alignment with a capital E positioned along the borders. You can copy this diagram onto a piece of clear, stiff plastic to use as a template over the screen.

#### 7.3 VIDEO SIGNALS, ON KAYPRO MAINBOARD

Below is a list of the video signals on connector J1 of the mainboard and the voltages on the video board. Repeated removal and installation of the video board connector will loosen the connection and produce poor contact. Malfunctions due to a loose connector can be very difficult to trace.

Video comes from the main board as separate signals, not as a composite like a TV signal.

A simple check for 12V on the video board is to turn the BRIGHINESS pot up, then turn the rear panel brightness control down. If 12V is present on the board, you should be able to see the raster lines on the screen.

#### Video signals on main board at J1

```
Pin 1 - Horizontal Sync.
```

Pin 2 - Key

Pin 3 - Video

Pin 4 - Vertical Sync.

#### Voltages on Video Board

```
Pin 1 \longrightarrow Øv
```

Pin 6  $\rightarrow$  Øv

Pin 7 --> 12v

Pin 8  $\rightarrow$  Øv

Pin 9 -> 4v approx. (this voltage controls brightness)

Pin 10 --> 0v

#### 7.4 LISTING OF ALIGN.MAC

If you have the assembly language utilities M-80 and L-80, this diagnostic can be typed into the KAYPRO, then turned into a COM file by running M-80, then L-80.

\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*

```
; kaypro alignment test routine
; first a program to move this routine above 80000h
; so we can turn on the other page of memory
; and address the video page directly
start:
        lđ
                hl, first+l
        ld
                de.dest
                bc, last-firstl
        ld
        ldir
        jр
                dest
dest
        equ
                Ø8ØØØh
first: defb
        .phase dest
; beginning of the program
; first turn off the drives and turn on the vid page
firstl:
        in
                a,(Ølch)
        set
                7,a
                         ;turn on the vid page
                         ;turn off drives
        set
                6,a
                         ;turn off drive a light
        res
                Ø,a
                l,a
                         ;turn off drive b light
        res
                (Ølch),a
        out
;
        ld
                hl,3000h
                                 ; beginning of the vid page
        ld
                (h1), 'H'
        1d
                de,3000h+1
        1d
                bc, 3*1024
                                          ;how many
        ldir
        now vid page filled with H
;
        ld
                hl,msgl
        ld
                de,03580h
                                 ;line 12
        ld
                bc,80
        ldir
;
        1d
                hl,msg2
        1d
                de,03600h
                                 ;line 13
        1d
                bc,80
        ldir
```

## 7.4 ALIGN.MAC LISTING (CONTINUED)

```
;
loop:
         call
                 delay
         call
                 aon
         call
                 delay
         call
                 aoff
         call
                 delay
         call
                 bon
         call
                 delay
        call
                 boff
                 loop
         jр
;
;
aon:
        in
                 a,(Ølch)
        set
                 Ø,a
        out
                 (Ølch),a
        ret
aoff:
        in
                 a, (Ølch)
        res
                 Ø,a
        out
                 (Ølch),a
        ret
bon:
        in
                 a,(Ølch)
        set
                 l,a
                 (Ølch),a
        out
        ret
boff:
        in
                 a,(Ølch)
        res
                 1,a
                 (Ølch),a
        out
        ret
delay:
        ld
                 bc,2
delay0:
        ld
                 hl,Ø
delayl:
        dec
                hl
        1d
                 a,h
        or
                 1
        jр
                 nz,delayl
        dec
                bc
        ld
                 a,b
        or
                 C
        jр
                 nz,delayØ
        ret
;
```

#### 7.4 ALIGN.MAC LISTING (CONTINUED)

```
12345678901234567890123456789012
       de fb
               · ------------------------------------
msql:
                   KAY', 'P' OR Ø8ØH, 'R' OR Ø8ØH, 'O II
       defb
       defb
               '
       defb
               · ------------------------------------
msg2:
               'crt ad','j' or 080h,'u' or 080h,'stment '
       defb
       defb
last:
       defb
               Ø,Ø,Ø
               start
       end
;
```

#### 7.5 CRT ASSEMBLY REMOVAL, (EXCEPT ROBIE)

- 1. Turn off the machine and disconnect the AC power (5.1).
- 2. Remove the chassis hood (5.1).
- 3. Remove the mainboard (6.7).
- 4. Remove the four screws that connect the video PCB and the bottom of the chassis. This should be done from the outside, bottom of the chassis, not from inside the machine.
- 5. Remove the video connector from the back of the video PCB.
- Remove the four screws that connect the CRT to the front of the machine chassis.
- 7. Remove the CRT assembly from the chassis.
- 8. Remove the four plastic standoffs from the CRT PCB. These can be used on the new CRT PCB.

#### CRT ASSEMBLY INSTALLATION

- \*\*\* Note: Before starting with CRT installation, check to see if the small plastic standoffs are attached to the bottom of the CRT PCB. If they are not attached, use the ones from the old board.
  - 1. Lower the CRT assembly into the chassis.
  - Position the CRT so that the top mounting holes are aligned with the two metal standoffs on the chassis.
  - Insert screws through the top two mounting holes on the CRT and into the standoffs, but do not tighten.
  - 4. Insert screws through the bottom two mounting holes on the CRT and into the standoffs. Tighten these two screws and the top two screws.
  - 5. Hold the CRT PCB in place and tilt the machine up so that it is sitting on the cord wraps.
  - Align the plastic standoffs on the PCB with the holes in the bottom of the chassis.
  - 7. Insert the four screws and tighten securely.
  - 8. Replace the video connector on the back of the video PCB.

#### 8.0 POWER SUPPLIES

#### 8.1 INTRODUCTION

Kaypro is using three different brands of power supplies at the present time. These are Astec, Boschert, and Cal D.C. These three power supplies are interchangeable with any of the Kaypro computers, if the power supply being changed is a new one from the factory.

#### \*\*\* EXCEPTION \*\*\*

If a power supply is removed from a 2/83 or a 4/83, and it's going to be used in another computer, it MUST be used in a 2/83 or 4/83. The power supplies used in 2/83 and 4/83 computers are not interchangeable with other Kaypro computers.

#### \*\*\*\*\*\*

There are no authorized dealer repairs that can be made on any of the power supplies. The CNLY authorized dealer service to power supplies is 220V configuration. Each brand of power supply can be configured for 220V operation.

#### 8.2 DESCRIPTION AND 220V CONFIGURATION INSTRUCTIONS

Two fuses are associated with each of the power supplies. One fuse (2 amp) is mounted on the rear of the chassis and accessible from outside the computer. The other fuse (2.5 amp) is mounted directly on the power supply board.

Disconnect AC power from the computer whenever replacing fuses. Be especially careful when replacing the fuse on the power supply board. Use of a fuse replacement tool is recommended due to the difficulty of reaching this component.

#### 220V CONFIGURATION

#### Astec Power Supply

Identified by a beige board with a white label on the right of the component side. The label will have the name ASTEC, followed by a model number, and the output voltages.

Locate the white shorting block labelled TB2. If the board is configured for 110V, a pin will be visible on the right of the shorting block.

Remove the shorting block and shift it to the right so that it covers the pin. A different pin should now be exposed on the left of the shorting block. The power supply is now configured for 220V use.

#### 220V CONFIGURATION

#### Boschert Power Supply

Identified by the word "Boschert" on the component side of the board at lower right and above the fuse and capacitor C2.

Locate a six-inch wire that is soldered to point JPl. If the board is configured for 110V, the other end of the wire is attached to point El (labelled 110V).

Unplug the wire from point El and plug it into point E2 (labelled 220V). Point E2 is to the left of point El. The power supply is now configured for 220V use.

#### 220V CONFIGURATION

#### Cal D.C. Power Supply

Identified by a bright blue circuit board. A white sticker with "California DC", model, and serial number is located on solder side of board.

There are two ceramic power resistors in the upper right-hand corner of the board. These resistors get quite hot during operation. Wiring should be tied down AWAY FROM THESE COMPONENTS.

Locate a jumper block labelled 115VAC and 230VAC. With the jumper in the 115VAC position the board is configured for 110V.

Remove the jumper from the socket labelled 115VAC and replace it in the socket labelled 230VAC. The power supply is now configured for 220V use.

#### 8.3 POWER SUPPLY REMOVAL

- 1. Turn off the machine and disconnect the AC power (5.1).
- 2. Remove the chassis hood (5.1).
- 3. Remove the mainboard (6.7).
- 4. Remove the four screws that connect the power supply and the back of the chassis. These are easier to remove from outside the back of the chassis than from inside the machine.
- 5. Remove the power plug from the power supply.
- 6. Remove the tie wraps from the plastic standoffs.
- 7. Remove the power supply.

#### POWER SUPPLY INSTALLATION

- 1. Position the power supply inside the chassis so that the four plastic standoffs are aligned with the four mounting holes in the chassis. Be certain that the power connector is on the side nearest the drives.
  - 2. Place the tie wraps on the plastic standoffs.
  - Insert four screws through the rear of the chassis and into the plastic standoffs of the power supply.
  - 4. Tighten the screws securely.
  - 5. Replace the power connector.
  - 6. Replace the mainboard (6.7).
  - 7. Replace the chassis hood (5.1).

#### 9.0 DISKETTE DRIVES

#### 9.1 INTRODUCTION

All diskette drive types (except the high-density drives in the ROBIE and 4X) are functionally interchangeable between manufacturers.

Because of the number of manufacturers from which Kaypro gets its diskette drives, no attempt is made in this manual to show alignment procedures for each of the drives. If you have access to a drive manual for a particular model, and have the Dysan Alignment Diskette (Dysan's part number: 224/2A) the knowledge, and an oscilloscope, go ahead and align away. Kaypro Corporation's policy is to do no repairs on these components.

However, since the company recognizes the fact that many customers want a KAYPRO computer in which both drives have the same outward appearance, we provide a guide for determining models of diskette drives from the placement of the LED and the drive door closure.

This section also contains diagrams and instructions on jumpering the various models of diskette drives to be used as either A or B (or, in the case of the KAYPRO 10, C) drive.

#### DISK DRIVE CLEANING

Generally speaking the majority of people clean disk drives too often. Unless the environment is especially dusty or dirty, under commercial use there is no reason to clean the drives more than twice a year.

Use care in selecting a cleaning kit. Many of the drive head cleaning kits on the market are very abrasive. Cleaning is done by the liquid solution, not by mechanical scrubbing.

\*\*\*NOTE\*\*\* The manufacturer (Drivetec) of the high-density drives in the ROBIE, and 4X recommends only four brands of head-cleaning kits for their drives. The letter from Drivetec states:

"THE FOLLOWING CLEANING DISKS HAVE BEEN EVALUATED AND ARE RECOMMENDED FOR USAGE ON THE DRIVETEC DISK DRIVE WHEN HEAD CLEANING IS DEEMED NECESSARY:

- 1) SCOTCH #744Ø
- HEAD COMPUTER PRODUCTS 5 1/4 CLEANING DISK
- 3) PERFECT DATA 5 1/4 CLEANING DISK
- 4) FLOPPICLENE 5 1/4 CLEANING DISK"

Refer to the symptom-fix guide for troubleshooting hints relative to the floppy drives, the Winchester hard disk, and the Drivetec (high-density) drives.

#### 9.2 WHICH BRAND OF DRIVE IS IT?

The following figures represent the face plates of the different brands of half-height floppy drives that are used in Kaypro computers. The drive door closure and the LED position can be used to reference the drive.

Fig. 9.1, TANDON Half-Height

Fig. 9.2, EPSON

Fig. 9.3, SHUGART

Fig. 9.4, TOKYO ELECTRIC

Fig. 9.5, TOSHIBA

Fig. 9.6, HI-TECH

Fig. 9.7, DRIVETEC

Fig. 9.8, TANDON Full-Height

#### 9.3 JUMPERING DIAGRAMS

Figure 9.8 Tandon diskette drive

Figure 9.9 Epson diskette drive

#### TANDON

Used only on KAYPRO 10, Pins 2 and 15 on U19 are jumpered and a 470—ohm terminating resistor pack is inserted in RPll.

#### EPSON

Next to the connector for the data cable is a black plug with ten pins. These pins are jumpered to change the configuration of the drive. They are MX,  $\emptyset$ , 1, 2, 3.

KAYPRO 10: The two pins in the "0" position should be jumpered and a 470-ohm terminating resistor inserted in RAL.

A DRIVE: Jumper the two pins in the "0" position. No terminating resistor is needed.

B DRIVE: Jumper the two pins in the "l" position. Insert a 470-ohm terminating resistor into RAL.

Figure 9.10 Shugart diskette drive

Figure 9.11 Tokyo Electric diskette drive

#### SHIGART

Next to the connector for the data cable is a blue plug with eleven pins. These pins are 1, 2, 3, 4, MX.

KAYPRO 10: Jumper the two pins in the "1" position. In the "MX" position, there are three pins. Jumper the one in the center and the one on the left of it. Insert a 470-ohm terminating resistor into RP1.

A DRIVE: Jumper the two pins in the "l" position. In the "MX" position, jumper the pin in the center and the pin on the left of it. No terminating resistor is necessary.

B DRIVE: Jumper the two pins in the "2" position. In the "MX" position, jumper the pin in the center and the pin on the left of it. Insert a 470-ohm terminating resistor into RPL.

#### TOKYO ELECTRIC

Next to the connector for the data cable is a blue plug with ten pins. These pins are DSØ, DS1, DS2, DS3, MX.

KAYPRO 10: Jumper the two pins in the "DS0" position. Insert a 470-ohm terminating resistor into RAll.

A DRIVE: Jumper the two pins in the "DSØ" position. No terminating resistor is necessary.

B DRIVE: Jumper the two pins in the "DS1" position. Insert a 470-ohm terminating resistor into RAll.

Figure 9.12 Toshiba diskette drive

#### TOSHTRA

Next to the connector for the data cable is a black plug with sixteen pins. These are 1, 2, 3, 4, LI, LD, HD, HM. Next to the black plug, is a 470-ohm terminating resistor with the letters "DM" to the left of it. Locate this resistor. On the other side of the resistor is another black plug. This plug has the letters "RM" to the left of it and the letters "PJ5" to the right of it. It has sixteen pins. For the terminating resistor to function, all pins must be jumpered EXCEPT the two next to the letters "RM". When the resistor is not needed, none of the pins should be jumpered.

KAYPRO l0: Jumper the two pins in the "l" position, the two pins in the "LD" position, and the two pins in the "HM" position. The terminating resistor is needed.

A DRIVE: Jumper the two pins in the "l" position, the two pins in the "LD" position, and the two pins in the "HM" position. The terminating resistor is not needed.

B DRIVE: Jumper the two pins in the "2" position, the two pins in the "LD" position, and the two pins in the "HM" position. The terminating resistor is needed.

Figure 9.13 Hi-Tech diskette drive

#### HI-TECH

Next to the connector for the data cable is a black plug with eight pins. These pins are DSØ, DS1, DS2, DS3.

KAYPRO 10: Jumper the two pins in the "DSO" position. Insert a 470-ohm SIP terminating resistor into RPL.

A-DRIVE: Jumper the two pins in the "DSØ" position. No terminating resistor is necessary.

B-DRIVE: Jumper the two pins in the "DS1" position. Insert a 470-ohm terminating resistor into RP1.

Figure 9.14
Tandon full-height diskette drive

#### Option shunt lE

#### TANDON

Used only in KAYPRO 2 AND KAYPRO 4.

A DRIVE: Pins 1-14 and 2-13 should be jumpered in option shunt block 1E.

B DRIVE: Pins 1-14 and 3-12 should be jumpered in option shunt block lE. Insert a 470-ohm terminating resistor into socket 2F.

#### 9.4 HIGH-DENSITY (DRIVETEC) DRIVES

The high-density diskette drives are currently being offered in the KAYPRO ROBIE, and KAYPRO 4X. These are 5-1/4 inch, double-sided drives with 192 tracks per inch. Each drive has 160 cylinders with a total of 320 tracks and a formatted storage capacity of 2.6 megabytes.

#### HIGH-DENSITY DISKETTES

The diskettes used with the high-density drives MUST be pre-formatted 17 sector, 192 TPI diskettes.

#### DRIVE CONFIGURATION

Next to the connector for the data cable is a drive select switch— DS1 through DS4.

A DRIVE: DSl should be in the "on" position. All other switches should be in the "off" position.

DRIVE: DS2 should be in the "on" position. All other switches should be in the "off" position.

#### 10.0 HARD DISK DRIVES (KAYPRO 10)

#### 10.1 INTRODUCTION

Kaypro Corporation uses hard disk drives from a number on different manufacturers. As with the diskette drives, all models of hard disk drives are functionally interchangeable.

No adjustments are meant to be made by dealers (or are made by Kaypro technicians, for that matter) on these hard drives. And, since recovering information from a hard disk which has "crashed" requires a clean room, no directions for performing such an operation are included in this manual. Be aware that true head crashes are very rare occurrences, however——most hard disk problems can be corrected without the need to replace the drive itself. (See the symptom-fix guide.) We cannot stress strongly enough that dealers instruct their customers to ALWAYS back up their data while working on a hard disk. In many cases NOTHING can be done about the loss of data in a hard-drive failure.

#### 10.2 DESCRIPTION

The hard disk drives used in the KAYPRO 10 are industry standard, 5-1/4 inch half-height drives offering Winchester technology. This technology includes sealed media and drive heads, with an air filtration system that prevents contamination. Since the drives are sealed, there are no dealer serviceable components on the drive. The only authorized dealer service to the hard disk drives is drive configuration.

#### 10.3 HARD DRIVE CONFIGURATION MICROSCIENCE

Figure 10.1 Microscience 9 Position Switch

Figure 10.2 Microscience 10 Position Switch

Figure 10.3 Seagate Hard Drive

Option shunt block

There are two types of drive selection switch banks available on Microscience drives. One type has nine (9) switches and one type has ten (10) switches. These switches are located on the drive PCB next to the power pluq.

9 POSITION SWITCH: Pins 1, 2, and 4 should be in the "up" position .

10 POSITION SWITCH: Pins 1, 3, 4, and 10 should be in the up position.

Refer to Figures 10.1 and 10.2 for Microscience drive configuration.

#### SEAGATE

Next to the connector for the data cable, is a 16 pin option shunt block. Pins 7 and 10 should be jumpered.

Refer to figure 10.3 for Seagate drive configuration.

#### 10.4 HARD DRIVE OR FLOPPY DRIVE REMOVAL FOR KAYPRO 10

For all hard drives and all diskette drives used in KAYPRO 10 computers.

Note: If the KAYPRO 10 has an Epson or Tokyo Electric diskette drive, it will be necessary to tilt the drive unit at an angle while removing or installing the drive. Refer to section 9.2 to determine the brand of drive.

Note: As you remove the cables on the KAYPRO 10, it's a good idea to label them. This will insure that they get replaced correctly. Also, the end of the data cable that has a different color wire (usually red) goes to pin #1 on the connector.

- 1. Turn off the machine and disconnect the AC power (5.1).
- 2. Remove the chassis hood (5.1).
- 3. Remove the two diagonal braces from the right side of the chassis.
- 4. Tilt the machine up so that the front of the machine is sitting on the work surface and parallel to the floor.
- 5. Remove the six screws from the bottom of the chassis that are under the drives. Set the machine back down.
- 6. Remove the ribbon cables from the mainboard.
- 7. Slide entire drive shield unit slightly to the rear, to make room for the face of the floppy to clear the opening.
- 8. Lift entire drive shield unit slightly and slide out the side of the chassis.

#### REMOVING THE DRIVES FROM THE DRIVE SHIELD

- 1. Remove the ribbon cables, power plug and the ground wire from the back of the drive (hard drive or floppy). Label these.
- Remove the two screws that attach the bottom of the drive to the drive shield (hard drive or floppy).
- Remove the two screws that attach the top of the drive to the drive shield.
- 4. Slide drive out through the front of the drive shield.

- 1. Configure the new drive. Refer to page 10-3 for the hard drive, pages 9-5 to 9-7 for the floppy drive.
- 2. Slide the drive into the shield so that the mounting holes in the drive are aligned with tb::>se in the shield.
- 3. Insert two screws through the top of the shield am. into the mounting holes of the drive.
- 4. Tighten these securely.
- 5. Insert two screws through the bottom of the shield and into the mounting holes of the drive.
- 6. Tighten these securely.
- 7. Replace the ribbon cable ( s), power plug and ground wire.
- 8. Slide the entire drive shield unit into the chassis.
- 9. Align the mounting holes in the drive shield with those in the chassis.
- 10. Insert the six screws through the mountin3 holes am. tighten securely.
- 11. Replace the two diagonal braces.
- 12. Replace the ribbon cab1e(s) on the main1x>ard.
- 13. Replace the chassis hood..

#### 11.0 HARD DRIVE CONTROLLER BOARD

## 11.1 DESCRIPTION

The hard disk controller board used in the KAYPRO 10 is a Western Digital board, and is not dealer-serviceable.

## **11.2** RFl!I:NAL/INSTAUATICN **1NS'l'm£l'I0lIS**

- L Turn off the ma.chine and disconnect AC power (5.1).
- 2. Remove *chassis* hood (5.1).
- 3. Remove the two diag:>nal braces from the right *side* of the machine.
- 4. Remove the p::>wer plug and the three *ribbcn* cables from the hard disk controller 1:x:>ard. Label these to insure correct replacement.
- 5. Remove the three screws that attach the hard disk controller board and. the *dri* ve shield.
- 6. Remove the board.

- *1. Position* the hard disk controller board so that the mounting holes in the board are aligned with the holes in the *drive* shield.
- 2. Insert the three screws and tighten securely.
- 3. Replace the power plug and the three *ribbon* cables.
- 4. Replace the two diagonal braces.
- 5. Replace the *chassis* hood (5.1).

### 12.0 INTERFACE BOARD, KAYPRO 10

#### 12.1 DESCRIPTION

The interface board that is used on the KAYPRO 10 is the interface between the mainboard and the hard drive controller board. This board is not dealer serviceable.

#### 12.2 INTERFACE BOARD REMOVAL

- 1. Turn off the machine and disconnect the AC power (5.1).
- 2. Remove the chassis hood (5.1).
- 3. Remove the mainboard (6.7).
- 4. Remove the two ribbon cables from the interface board.
- 5. Remove the four screws that attach the interface board and the drive shield.
- 6. Remove the interface board.

#### INTERFACE BOARD INSTALLATION

- Position the interface board so that the mounting holes on the board are aligned with the holes on the drive shield.
- 2. Insert four screws and tighten securely.
- 3. Replace the two ribbon cables.
- 4. Replace the mainboard (6.7).
- 5. Replace the chassis hood (5.1).

#### 13.0 KEYBOARDS

The 76-key alphanumeric, detachable keyboard is connected to the computer by a four-wire cable and is powered by +5 VDC through the cable. The CAPS LOCK indicator light allows a quick check on whether the keyboard is receiving power.

The impedance of the connecting cable can be a critical factor in proper operation of the computer. Replacement of the standard cable with a phone cord can create malfunctions in signal transmission to the computer. This is because the wire in phone cords is too small; therefore, the impedance over the total length of the cord can be too high for reliable operation.

Wire in the standard keyboard cable is 28-gage copper, and the cable length is six feet. Should you desire a longer keyboard cable, restrict the length to not more than twelve feet, and use wire no smaller than 28 gauge.

#### Keyboard Cable Pinouts

```
Pin 4 (Black) - Serial Data out (to keyboard), TTL level.
Pin 3 (Red) - Ground
```

Pin 2 (Green) - Serial data in (from keyboard), TTL level.

Pin 1 (Yellow) - +5 VDC

#### 14.0 KAYPRO ROBIE REMOVAL/INSTALLATION INSTRUCTIONS

#### 14.1 CHASSIS COVER REMOVAL

- 1. Turn off the machine and disconnect the AC power(5.1).
- Remove the four screws securing the top chassis cover (two on each side of the machine).
- Remove the eight screws securing the bottom chassis cover (four on each side of the machine).
- 4. Remove the two sections of the chassis cover from the machine.

#### CHASSIS COVER REPLACEMENT

- Place the lower chassis cover on the machine and align the eight mounting holes with the mounting holes in the sides of the machine.
- Insert the eight screws into the mounting holes and tighten securely.
- 3. Place the top chassis cover on the machine and align the four mounting holes with the mounting holes in the sides of the machine.
- Insert the four screws into the mounting holes and tighten securely.

#### 14.2 DISKETTE DRIVE REMOVAL

- 1. Remove the top chassis cover (5.1).
- 2. Remove the drive support unit from the chassis. There are three screws in the front and three screws in the rear.
- 3. Remove the ribbon cable and the power plugs from the drives.
- 4. Lift the drive support unit (drives still attached) off the chassis.
- 5. To remove either drive from the drive support unit, turn the unit over and remove the four screws that attach the specific drive to the support unit.

#### DISKETTE DRIVE REPLACEMENT

- Align the drive mounting holes with the mounting holes in the drive support unit.
- Insert four screws into the drive support unit and into the drive. Tighten these screws securely.
- Set the drive support unit on the chassis and align the mounting holes in the support unit with those in the chassis.
- 4. Insert three screws into the front mounting holes and three screws into the rear mounting holes. Tighten these securely.
- 5. Replace the ribbon cable and the power plugs on the drives.

#### 15.0 TROUBLESHOOTING

#### 15.1 INTRODUCTION

The symptom—fix guide's information is based on our experience repairing Kaypro computers. The guide is a summary of the records that Kaypro Repair maintains on each computer received.

\*\*\*\*\*\*\*

Fixes for each problem noted are presented in **descending** order of occurrence.

\*\*\*\*\*\*\*

### 15.2 KAYPRO 2 AND 4 SYMPTOM—FIX GUIDE

| CONDITION                          | POSSIBLE CAUSE                         | RECOMMENDED ACTION                                                                                                          |
|------------------------------------|----------------------------------------|-----------------------------------------------------------------------------------------------------------------------------|
| No power, no<br>lights, no video   | Power cord not<br>plugged in           | Check all cord connections                                                                                                  |
|                                    | Fuse is blown                          | Replace fuse                                                                                                                |
|                                    | Mainboard not getting power            | Check harness connections; check<br>for proper voltages; replace<br>either harness or power supply                          |
|                                    | Defective mainboard                    | Replace mainboard                                                                                                           |
|                                    | Defective fuse holder                  | Replace fuse holder                                                                                                         |
|                                    | Power switch shorted internally        | Replace power switch                                                                                                        |
|                                    | Power supply jumpered for wrong supply | Correct jumpering on power supply                                                                                           |
|                                    | Defective power supply                 | Replace power supply                                                                                                        |
|                                    | Defective harness                      | Replace harness                                                                                                             |
| Fuse blows when power is turned on | Defective power supply                 | Disconnect all modules from power supply; replace power supply if fuse still blows                                          |
|                                    | One module has a short                 | Disconnect all modules, replace<br>fuse, and re-connect modules, one<br>at a time, until fuse blows.<br>Replace that module |
|                                    | Defective harness                      | Replace harness                                                                                                             |
| High-pitched<br>squeal or "chirp"  | One module is shorted                  | Unplug modules, one at a time, from the harness. Replace the module whose unplugging causes the noise to stop               |

## KAYPRO 2 AND 4 SYMPTOM-FIX GUIDE (CONT'D)

| CONDITION                                       | POSSIBLE CAUSE                   | RECOMMENDED ACTION                                                                                                       |
|-------------------------------------------------|----------------------------------|--------------------------------------------------------------------------------------------------------------------------|
| Power LED flickers                              | Shorted module                   | Disconnect modules from power, one at a time, until LED stays on; replace module whose unplugging caused LED to stay on. |
|                                                 | Defective power supply           | Replace power supply                                                                                                     |
|                                                 | Defective harness                | Replace harness                                                                                                          |
| No video display,<br>or poor quality<br>display | Brightness not<br>adjusted       | Turn up brightness knob on rear of<br>chassis; adjust brightness pot on<br>CRT board, if necessary                       |
|                                                 | CRT not connected                | Check all connections to CRT; be<br>sure plug on rear of CRT tube is<br>square                                           |
|                                                 | Defective CRT                    | Replace CRT assembly                                                                                                     |
|                                                 | Defective mainboard              | Replace mainboard                                                                                                        |
|                                                 | Defective power supply           | Replace power supply                                                                                                     |
|                                                 | Defective harness                | Replace harness                                                                                                          |
| Video is on, but screen is filled               | Defective mainboard              | Replace mainboard                                                                                                        |
| with "garbage"<br>characters                    | Reset harness shorted to chassis | Check lugs of reset button for grounding to inside of chassis                                                            |
|                                                 | Defective reset harness          | Replace reset harness                                                                                                    |

## KAYPRO 2 AND 4 SYMPTOM-FIX GUIDE (CONT'D)

| CONDITION                                    | POSSIBLE CAUSE                                        | RECOMMENDED ACTION                                                                                                                                 |
|----------------------------------------------|-------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------|
| "Raster" (hori-<br>zontal lines) on<br>video | Brightness not adjusted<br>properly                   | Turn up brightness knob on back of<br>chassis; adjust brightness pot on<br>CRT board if necessary                                                  |
|                                              | Loose connection from<br>mainboard or power<br>supply | Check black plug from power supply<br>to CRT board, 4-pin jumper from<br>main board to CRT board; check that<br>plug on rear of CRT tube is square |
| Strange video image                          | Short in brightness-<br>adjusting knob                | Check for shorts between wires in<br>rear of brightness-adjusting knob                                                                             |
|                                              | Defective mainboard                                   | Replace mainboard                                                                                                                                  |
| Missing characters<br>on video display       | Defective mainboard                                   | Replace mainboard                                                                                                                                  |
| on video display                             | Defective CRT                                         | Replace CRT assembly                                                                                                                               |
| Will not boot                                | Defective diskette                                    | Change diskettes                                                                                                                                   |
|                                              | Diskette has no system image                          | Change diskettes; use a diskette with a known good system image                                                                                    |
|                                              | Wrong CP/M for model of machine                       | Check that you're not trying to boot a KP 2 with a KP 4 CP/M (KP 4 WILL boot a KP 2 CP/M)                                                          |
|                                              | Defective drive B                                     | Unplug data cable from drive B, and reset machine; if it boots, replace drive B                                                                    |
|                                              | Defective mainboard                                   | Replace mainboard                                                                                                                                  |
|                                              | Defective drive A                                     | Replace drive A                                                                                                                                    |
|                                              | Defective data cable                                  | Replace data cable                                                                                                                                 |

## KAYPRO 2 AND 4 SYMPTOM—FIX GUIDE (CONT'D)

| CONDITION                                      | POSSIBLE CAUSE                                                                                  | RECOMMENDED ACTION                                                                        |
|------------------------------------------------|-------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------|
| Both drive LEDs<br>are on, won't<br>boot       | Problem on power-up Diskette has no CP/M Defective mainboard Select jumpers on drives incorrect | Reset machine  Try known good sysgenned diskette  Replace mainboard  Check select jumpers |
| Drive A LED only<br>on during reset            | Drive select jumpering incorrect                                                                | Check jumpering on drive A                                                                |
| No LED on drive A at any time                  | Data cable poorly connected                                                                     | Check all connections on data cable                                                       |
|                                                | Defective data cable                                                                            | Replace data cable                                                                        |
|                                                | Defective drive A                                                                               | Replace drive A                                                                           |
|                                                | Defective mainboard                                                                             | Replace mainboard                                                                         |
| Computer boots CP/M, but no A> prompt appears  | Defective diskette Defective mainboard                                                          | Try known good, sysgenned diskette<br>Replace mainboard                                   |
| Rattling sound<br>from drive when<br>accessing | Defective drive                                                                                 | Replace the diskette drive Replace mainboard                                              |

## KAYPRO 2 AND 4 SYMPTOM-FIX GUIDE (CONTINUED)

| CONDITION                                                | POSSIBLE CAUSE                             | RECOMMENDED ACTION                                                                                                                   |
|----------------------------------------------------------|--------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------|
|                                                          |                                            |                                                                                                                                      |
| Drive will not<br>step through all<br>tracks on diskette | Drive connectors loose                     | Check all connectors on rear of<br>drive, esp. P12 (Tandon drives)                                                                   |
| cracio di dibiecce                                       | Defective mainboard                        | Replace mainboard                                                                                                                    |
|                                                          | Defective drive                            | Replace diskette drive                                                                                                               |
|                                                          | Defective data cable                       | Replace data cable                                                                                                                   |
|                                                          |                                            |                                                                                                                                      |
| Errors on either<br>drive during COPY                    | Defective diskette                         | Change the diskette (if problem is<br>on drive B, insert another blank<br>diskette; if on drive A, try to<br>copy from a new master) |
|                                                          | Defective disk drive                       | Replace diskette drive                                                                                                               |
|                                                          | Defective mainboard                        | Replace mainboard                                                                                                                    |
|                                                          |                                            |                                                                                                                                      |
| No output to parallel printer                            | No power to printer                        | Check that printer is plugged in, and selected                                                                                       |
|                                                          | Poor cable connection                      | Check all cable connections from computer to printer                                                                                 |
|                                                          | Printer is assigned as serial by STAT      | Use STAT to assign printer device as parallel, type:<br>STAT LST:=LPT:                                                               |
| •                                                        | Defective mainboard                        | Replace mainboard                                                                                                                    |
|                                                          |                                            |                                                                                                                                      |
| No output to serial printer                              | No power to printer                        | Check that printer is plugged in and selected                                                                                        |
|                                                          | Poor cable connection                      | Check all cable connections from computer to printer; also check serial port connector pins for contamination                        |
|                                                          | Printer is assigned<br>as parallel by STAT | Use STAT to assign printer device to serial; type: STAT LST:=TTY:                                                                    |

### KAYPRO 2 AND 4 SYMPTOM-FIX GUIDE (CONTINUED)

| CONDITION                                                 | POSSIBLE CAUSE                                                  | RECOMMENDED ACTION                                                              |
|-----------------------------------------------------------|-----------------------------------------------------------------|---------------------------------------------------------------------------------|
| No output to<br>serial printer<br>(cont'd)                | Baud rate of printer<br>does not match baud<br>rate of computer | Use CONFIG to set baud rate for serial port                                     |
|                                                           | Defective power supply                                          | Check voltages (esp12 V) at power supply output; replace power supply           |
|                                                           | Defective harness                                               | Check voltages (esp12V) at main board power connector; replace harness          |
|                                                           | Defective mainboard                                             | Replace mainboard                                                               |
|                                                           |                                                                 |                                                                                 |
| No characters on<br>video when keys<br>struck on keyboard | Defective keyboard<br>coil cord                                 | Replace coil cord                                                               |
| SCIUCK Off Reyboard                                       | Defective keyboard                                              | Replace keyboard                                                                |
|                                                           | Keyboard connector on<br>mainboard defective                    | Check for shorted contacts on<br>keyboard plug; esp. soldering to<br>main board |
|                                                           | Defective mainboard                                             | Replace mainboard                                                               |
|                                                           |                                                                 |                                                                                 |
| Wrong characters<br>or too many char-                     | Defective keyboard                                              | Replace keyboard                                                                |
| acters appear when<br>a key is struck                     | Defective mainboard                                             | Replace mainboard (if "^@^@^@" appears, replace 8116 IC on mainboard)           |
|                                                           |                                                                 |                                                                                 |

#### 15.3 KAYPRO 10 SYMPTOM-FIX GUIDE

## IMPORTANT NOTE

Do not proceed with troubleshooting a Kaypro 10 until you verify that the computer has eprom number 81-302-x (installed at the factory), or has been upgraded in the field with kit number 31-303 (consisting of eprom number 81-302-x, a modified interface board, and a utilities reload diskette.)

| CONDITION                        | POSSIBLE CAUSE                                 | RECOMMENDED ACTION                                                                                                           |
|----------------------------------|------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------|
| No power, no<br>lights, no video | Power cord not plugged in                      | Check all cord connections                                                                                                   |
|                                  | Fuse is blown                                  | Replace fuse                                                                                                                 |
|                                  | Mainboard not getting<br>power                 | Check harness connections, then<br>check for proper voltages from<br>power supply; replace either<br>harness or power supply |
|                                  | Defective mainboard                            | Replace mainboard                                                                                                            |
|                                  | Defective fuse holder                          | Replace fuse holder                                                                                                          |
|                                  | Power switch shorted internally                | Replace power switch                                                                                                         |
|                                  | Power supply jumpered for wrong supply voltage | Correct jumpering on power supply                                                                                            |
|                                  | Defective power supply                         | Check for proper voltage output<br>at power supply harness connector;<br>replace power supply                                |
|                                  | Defective harness                              | Replace harness                                                                                                              |
|                                  |                                                |                                                                                                                              |
| Fuse blows when power turned on  | Defective power supply                         | Replace power supply                                                                                                         |
| power carried off                | One module has a short                         | Disconnect all modules, replace<br>fuse, and re-connect one by one<br>until fuse blows again; replace it                     |
|                                  | Defective harness                              | Replace harness                                                                                                              |
|                                  |                                                |                                                                                                                              |

| CONDITION                                          | POSSIBLE CAUSE                                                                 | RECOMMENDED ACTION                                                                                                                                                                                   |
|----------------------------------------------------|--------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| High-pitched<br>squeal or "chirp"<br>upon power-on | One module is shorted                                                          | Unplug modules, one at a time, from the harness. Replace the module whose unplugging causes the noise to stop.                                                                                       |
| Power LED flickers                                 | Shorted module                                                                 | Disconnect modules from power one<br>at a time until LED stays on;<br>replace module whose unplugging<br>causes LED to stay on                                                                       |
|                                                    | Defective power supply                                                         | Replace power supply                                                                                                                                                                                 |
|                                                    | Defective harness                                                              | Replace harness                                                                                                                                                                                      |
| No video display,<br>or poor quality<br>display    | Brightness not adjusted  CRT not connected  Defective CRT  Defective mainboard | Turn up brightness knob on rear of chassis; turn up brightness pot on CRT board, if necessary  Check all connections to CRT; ensure CRT tube plug is square  Replace CRT assembly  Replace mainboard |
|                                                    | Defective power supply Defective harness                                       | Replace power supply Replace harness                                                                                                                                                                 |
| Extra pixels on video                              | Defective mainboard Defective CRT                                              | Replace mainboard Replace CRT assembly                                                                                                                                                               |
| Inverse video only                                 | Defective mainboard Defective CRT                                              | Replace mainboard Replace CRT assembly                                                                                                                                                               |

| CONDITION                                          | POSSIBLE CAUSES                    | RECOMMENDED ACTION                                                                                      |
|----------------------------------------------------|------------------------------------|---------------------------------------------------------------------------------------------------------|
| No graphics on video                               | Damaged system image               | Rum PUTSYS and PUTOVL                                                                                   |
|                                                    | Defective mainboard                | Replace mainboard                                                                                       |
|                                                    | Defective CRT                      | Replace CRT assembly                                                                                    |
| No video; drives running                           | Poor cable connection              | Check all cable connections, (esp. to/from video harness plug)                                          |
|                                                    | Defective mainboard                | Replace mainboard                                                                                       |
|                                                    | Defective CRT                      | Replace CRT assembly                                                                                    |
|                                                    | Elston CRT: fuse<br>blown          | Check continuity of pico-fuse on<br>Elston video board (just above<br>power connector) If open, replace |
| Hard drive boots,<br>but no cursor on              | Defective system image             | Run PUTSYS and PUTOVL from the<br>diskette drive, push RESET                                            |
| video                                              | Defective mainboard                | Replace mainboard                                                                                       |
| Diskette drive<br>boots, but no<br>cursor on video | Defective system image on diskette | Run GENFLPY on the diskette; push<br>RESET                                                              |
|                                                    | Defective mainboard                | Replace mainboard                                                                                       |
|                                                    | Defective drive                    | Replace diskette drive                                                                                  |
|                                                    |                                    |                                                                                                         |
| Diskette drive<br>won't boot; or<br>BDOS error on  | Diskette not centered              | Remove diskette, center diskette in its jacket; try again                                               |
| diskette drive                                     | No system image on<br>diskette     | Run GENFLPY on the diskette;<br>push RESET                                                              |
|                                                    | Defective diskette                 | Try a known good diskette with a known good system image                                                |

| CONDITION                                              | POSSIBLE CAUSE                                   | RECOMMENDED ACTION                                                                    |
|--------------------------------------------------------|--------------------------------------------------|---------------------------------------------------------------------------------------|
| Diskette drive<br>won't boot; or<br>BDOS errors        | Poor cable connection                            | Check all cable connections; esp.<br>those to/from drives and the<br>controller board |
|                                                        | No system image                                  | Run GENFLPY                                                                           |
|                                                        | Incorrect cable orientation                      | Verify that all cables are oriented properly                                          |
|                                                        | Defective mainboard                              | Replace mainboard                                                                     |
|                                                        | Defective drive                                  | Replace diskette drive                                                                |
| Diskette drive                                         | Diskette off center                              | Ensure that diskette is centered within its jacket                                    |
| disk                                                   | Defective diskette<br>drive                      | Replace diskette drive                                                                |
|                                                        | Defective mainboard                              | Replace mainboard                                                                     |
|                                                        |                                                  |                                                                                       |
| Diskette drive has<br>BDOS errors or                   | Defective drive heads                            | Replace diskette drive                                                                |
| won't work if warm                                     | Defective mainboard                              | Replace mainboard                                                                     |
| Diskette drive<br>makes a rattling<br>noise, and won't | Defective diskette<br>drive                      | Replace diskette drive                                                                |
| boot                                                   | Defective mainboard                              | Replace mainboard                                                                     |
| High-pitched whine<br>when diskette<br>drive runs      | Defective diskette<br>drive ("singing<br>heads") | Replace diskette drive                                                                |

| CONDITION                                                                          | POSSIBLE CAUSE                        | RECOMMENDED ACTION                                                                                                                                       |
|------------------------------------------------------------------------------------|---------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|
| Hard drive will<br>not boot; or boots<br>with "System Status<br>02" ("Read Fault") | Machine not upgraded                  | Verify installation of eprom<br>number 81-302-x (at the factory),<br>or kit 81-303; install if needed                                                    |
| message                                                                            | Poor cable connection                 | Check all cable connections                                                                                                                              |
|                                                                                    | Incorrect cable orientation           | Verify that all cables are oriented properly                                                                                                             |
|                                                                                    | System image degraded                 | Boot on a disk in the diskette drive; then log onto hard drive. Run FINDBAD (or CHECK on cylinder Ø and 1) if no errors are found, run PUTSYS and PUTOVL |
|                                                                                    | Defective controller<br>board         | Replace controller board                                                                                                                                 |
|                                                                                    | Degraded format on hard disk          | Boot on a disk in the diskette<br>drive; run FORMAT on entire hard<br>drive; then run PUTSYS and PUTOVL                                                  |
|                                                                                    | Defective mainboard                   | Replace mainboard                                                                                                                                        |
|                                                                                    | Defective hard drive                  | Replace hard drive                                                                                                                                       |
|                                                                                    | Defective power supply                | Replace power supply                                                                                                                                     |
|                                                                                    |                                       | or brake assembly failure, ALWAYS appears to be within the hard drive                                                                                    |
| No output to<br>parallel printer                                                   | No power to printer                   | Check that printer is plugged in, and selected                                                                                                           |
|                                                                                    | Poor cable connection                 | Check all cable connections from computer to printer                                                                                                     |
|                                                                                    | Printer is assigned as serial by STAT | Use STAT to assign printer device as parallel; type: STAT LST:=LPT:                                                                                      |
|                                                                                    | Defective mainboard                   | Replace mainboard                                                                                                                                        |
|                                                                                    |                                       |                                                                                                                                                          |

| CONDITION                      | POSSIBLE CAUSE                                                  | RECOMMENDED ACTION                                                                                            |
|--------------------------------|-----------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------|
| No output to<br>serial printer | No power to printer                                             | Check that printer is plugged in and selected                                                                 |
|                                | Poor cable connection                                           | Check all cable connections from computer to printer; also check serial port connector pins for contamination |
|                                | Printer is assigned as parallel by STAT                         | Use STAT to assign printer device to serial; type: STAT LST:=TTY:                                             |
|                                | Baud rate of printer<br>does not match baud<br>rate of computer | Use CONFIG to set baud rate for serial port                                                                   |
|                                | Defective power supply                                          | Check voltages (esp12 V) at supply output; replace supply                                                     |
|                                | Defective harness                                               | Check voltages (esp12V) at main board power connector; replace harness                                        |
|                                | Defective mainboard                                             | Replace mainboard                                                                                             |

### 15.4 KAYPRO ROBIE SYMPTOM-FIX GUIDE

| CONDITION                                | POSSIBLE CAUSE               | RECOMMENDED ACTION                                                                                                          |
|------------------------------------------|------------------------------|-----------------------------------------------------------------------------------------------------------------------------|
| No power, no<br>lights, no video         | Power cord not<br>plugged in | Check all cord connections                                                                                                  |
|                                          | Fuse is blown                | Replace fuse                                                                                                                |
|                                          | Mainboard not getting power  | Check harness connections; check<br>for proper voltages; replace<br>either harness or power supply                          |
|                                          | Defective mainboard          | Replace mainboard                                                                                                           |
|                                          | Defective power supply       | Replace power supply                                                                                                        |
|                                          | Defective harness            | Replace harness                                                                                                             |
| Fuse blows when<br>power is turned<br>on | Defective power supply       | Disconnect all modules from power supply; replace power supply if fuse still blows                                          |
|                                          | One module has a short       | Disconnect all modules, replace<br>fuse, and re-connect modules, one<br>at a time, until fuse blows.<br>Replace that module |
|                                          | Defective harness            | Replace harness                                                                                                             |
| High-pitched<br>squeal or "chirp"        | One module is<br>shorted     | Unplug modules, one at a time, from the harness. Replace the module whose unplugging causes the noise to stop               |
| No video display                         | Brightness not<br>adjusted   | Turn up brightness knob on rear of<br>chassis; turn up brightness pot on<br>CRT board, if necessary                         |
|                                          | CRT not connected            | Check all connections to CRT; be<br>sure plug on rear of CRT tube is<br>square                                              |

## KAYPRO ROBIE SYMPTOM-FIX GUIDE (CON'T.)

| CONDITION                                    | POSSIBLE CAUSE                                        | RECOMMENDED ACTION                                                                                                                                |  |
|----------------------------------------------|-------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------|--|
| No video display                             | Defective CRT                                         | Replace CRT assembly                                                                                                                              |  |
|                                              | Defective mainboard                                   | Replace mainboard                                                                                                                                 |  |
|                                              | Defective power supply                                | Replace power supply                                                                                                                              |  |
|                                              | Defective harness                                     | Replace harness                                                                                                                                   |  |
| Video is on, but<br>screen is filled         | Defective mainboard                                   | Replace mainboard                                                                                                                                 |  |
| with "garbage"<br>characters                 | Reset harness shorted to chassis                      | Check lugs of reset button for grounding to inside of chassis                                                                                     |  |
|                                              | Defective reset harness                               | Replace reset harness                                                                                                                             |  |
| "Raster" (hori-<br>zontal lines) on<br>video | Brightness not adjusted properly                      | Turn up brightness knob on back of<br>chassis; adjust brightness pot on<br>CRT board if necessary                                                 |  |
|                                              | Loose connection from<br>mainboard or power<br>supply | Check black plug from power supply<br>to CRT board, 4-pin jumper from<br>mainboard to CRT board; check that<br>plug on rear of CRT tube is square |  |
| Strange video<br>image                       | Defective mainboard                                   | Replace mainboard                                                                                                                                 |  |
| Missing characters<br>on video display       | Defective mainboard                                   | Replace mainboard                                                                                                                                 |  |
| Will not boot                                | Defective diskette                                    | Change diskettes                                                                                                                                  |  |
|                                              | Diskette has no system image                          | Change diskettes; use a diskette with a known good system image                                                                                   |  |
|                                              | Wrong diskette for model of machine                   | ROBIE will only boot on 17 sector,<br>192 TPI diskettes                                                                                           |  |
|                                              | Defective drive B                                     | Unplug data cable from drive B, and reset machine; if it boots, replace B drive                                                                   |  |

## KAYPRO ROBIE SYMPTOM-FIX GUIDE (CON'T.)

| CONDITION                           | POSSIBLE CAUSE                     | RECOMMENDED ACTION                  |
|-------------------------------------|------------------------------------|-------------------------------------|
| Will not boot                       | Defective mainboard                | Replace mainboard                   |
|                                     | Defective drive A                  | Replace drive A                     |
|                                     | Defective data cable               | Replace data cable                  |
| Both drive LEDs are on, won't       | Problem on power-up                | Reset machine                       |
| boot                                | Diskette has no CP/M               | Try known good sysgenned diskette   |
|                                     | Defective mainboard                | Replace mainboard                   |
|                                     | Select jumpers on drives incorrect | Check select jumpers                |
| Drive A LED only<br>on during reset | Drive select jumpering incorrect   | Check jumpering on drive A          |
| No LED on drive A at any time       | Data cable poorly connected        | Check all connections on data cable |
|                                     | Defective data cable               | Replace data cable                  |
|                                     | Defective drive A                  | Replace drive A                     |
|                                     | Defective mainboard                | Replace mainboard                   |
| Computer boots                      | Defective diskette                 | Try known good, sysgenned diskette  |
| CP/M, but no<br>master menu         | Defective drive A                  | Replace drive A                     |
| appears                             | Defective mainboard                | Replace mainboard                   |
| Rattling sound<br>from drive when   | Defective drive                    | Replace the diskette drive          |
| accessing                           | Defective mainboard                | Replace mainboard                   |

## KAYPRO ROBIE SYMPTOM-FIX GUIDE (CONT'D.)

| CONDITION                                                | POSSIBLE CAUSE                        | RECOMMENDED ACTION                                                                                                                   |  |
|----------------------------------------------------------|---------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------|--|
| Drive will not<br>step through all<br>tracks on diskette | Drive connectors loose                | Check all connectors on rear of drive                                                                                                |  |
| CIACAS ON CISAECCE                                       | Defective mainboard                   | Replace mainboard                                                                                                                    |  |
|                                                          | Defective drive                       | Replace diskette drive                                                                                                               |  |
|                                                          | Defective data cable                  | Replace data cable                                                                                                                   |  |
| Errors on either<br>drive during COPY                    | Defective diskette                    | Change the diskette (if problem is<br>on drive B, insert another blank<br>diskette; if on drive A, try to<br>copy from a new master) |  |
|                                                          | Defective disk drive                  | Replace diskette drive                                                                                                               |  |
|                                                          | Defective mainboard                   | Replace mainboard                                                                                                                    |  |
| No output to parallel printer                            | No power to printer                   | Check that printer is plugged in, and selected                                                                                       |  |
|                                                          | Poor cable connection                 | Check all cable connections from computer to printer                                                                                 |  |
|                                                          | Printer is assigned as serial by STAT | Use STAT to assign printer device as parallel, type:<br>STAT LST:=LPT:                                                               |  |
|                                                          | Defective mainboard                   | Replace mainboard                                                                                                                    |  |
| No output to serial printer                              | No power to printer                   | Check that printer is plugged in and selected                                                                                        |  |
|                                                          | Poor cable connection                 | Check all cable connections from computer to printer; also check serial port connector pins for contamination                        |  |

## KAYPRO ROBIE SYMPTOM-FIX GUIDE (CONT'D.)

| CONDITION                                                 | POSSIBLE CAUSE                                                  | RECOMMENDED ACTION                                                        |
|-----------------------------------------------------------|-----------------------------------------------------------------|---------------------------------------------------------------------------|
| No output to<br>serial printer<br>(cont'd)                | Printer is assigned as parallel by STAT                         | Use STAT to assign printer device to serial; type: STAT LST:=TTY:         |
|                                                           | Baud rate of printer<br>does not match baud<br>rate of computer | Use CONFIG to set baud rate for serial port                               |
|                                                           | Defective power supply                                          | Check voltages (esp12 V) at power supply output; replace power supply     |
|                                                           | Defective harness                                               | Check voltages (esp12V) at main board power connector; replace harness    |
|                                                           | Defective mainboard                                             | Replace mainboard                                                         |
| No characters on<br>video when keys<br>struck on keyboard | Defective keyboard<br>coil cord                                 | Replace coil cord                                                         |
| struck on keyboard                                        | Defective keyboard                                              | Replace keyboard                                                          |
|                                                           | Keyboard connector on<br>mainboard defective                    | Check for shorted contacts on keyboard plug; esp. soldering to main board |
|                                                           | Defective mainboard                                             | Replace mainboard                                                         |
| Wrong characters                                          | Defective keyboard                                              | Replace keyboard                                                          |

### 15.5 KAYPRO 2/84 AND KAYPRO 2X SYMPTOM—FIX GUIDE

See KAYPRO 2 AND 4 SYMPTOM—FIX GUIDE for the 2/84. The problems and solutions will not be different.

For troubleshooting information on the KAYPRO 2X, see the KAYPRO 2 AND 4 SYMPTOM—FIX GUIDE for all problems.

## 15.6 KAYPRO 4X SYMPTOM-FIX GUIDE

For help in troubleshooting the KAYPRO 4X, see the KAYPRO ROBIE SYMPTOM—FIX GUIDE.

#### 16.0 KAYPRO SYSTEM I/O

#### 16.1 VIDEO COMMAND PROTOCOL

The Kaypro video section was originally designed to imitate most of the control sequences of a Lear-Siegler ADM-3A terminal. For most commercial software, this meant that you could "install" or customize the display characteristics by choosing ADM-3A from the menu.

The above is no longer true for the current Kaypro line. The change to graphics and the differences in cursor control keys caused the change.

For custom software or those instances where there is no choice of "ADM-3A" on the menu, the complete command protocol for the KAYPRO 2, 4, or 10 is:

#### Control Characters

|                               | VERSION 2.2F AND LOWER |     | VERSION 2.2G |            |
|-------------------------------|------------------------|-----|--------------|------------|
| Action                        | Dec                    | Hex | Dec          | Hex        |
|                               |                        |     |              |            |
| Ring Bell                     | Ø7                     | Ø7  |              |            |
| Cursor left (non-destructive) | Ø8                     | Ø8  | 19           | 13         |
| Cursor Right                  | 12                     | ØC  | Ø4           | Ø4         |
| Cursor Down                   | 1Ø                     | ØA  | 24           | 18         |
| Cursor Up                     | 11                     | ØB  | Ø5           | Ø5         |
| Erase to end of screen        | 23                     | 17  |              |            |
| Erase to end of line          | 24                     | 18  | Remainin     | g codes    |
| Clear screen, home cursor     | 26                     | 1A  |              | same as in |
| Hame cursor                   | 3Ø                     | 1E  | 2.2G (and    | d lower).  |

#### ESCape Sequences

| Insert | line | ESCape,R  |
|--------|------|-----------|
| Delete | line | ESCape, E |

Cursor address ESCape,=,row+32,col+32

\* Additionally, the following codes apply to: KAYPRO 2/84, 2X, 4/84, 4X, 10, and ROBIE (KAYPRO computers with graphics capability):

| Reverse video start          | ESCape, B, Ø              |
|------------------------------|---------------------------|
| Reverse video stop           | ESCape, C, Ø              |
| Half intensity start         | ESCape, B, 1              |
| Half intensity stop          | ESCape, C, 1              |
| Blinking start               | ESCape, B, 2              |
| Blinking stop                | ESCape, C, 2              |
| Underline start              | ESCape, B, 3              |
| Underline stop               | ESCape, C, 3              |
| Cursor on                    | ESCape, B, 4              |
| Cursor off                   | ESCape, C, 4              |
| Video mode on                | ESCape, B, 5              |
| Video mode off               | ESCape, C, 5              |
| Remember current cursor      |                           |
| position                     | ESCape, B, 6              |
| Return to last remembered    |                           |
| cursor position              | ESCape, C, 6              |
| Status line preservation on  | ESCape, B, 7              |
| Status line preservation off | ESCape, C, 7              |
| Set pixel                    | ESCape, *, Vl, Hl         |
| Clear pixel                  | ESCape, ,Vl,Hl            |
| Set line                     | ESCape, L, Vl, Hl, V2, H2 |
| Delete line                  | ESCape, D, Vl, Hl, V2, H2 |

#### 16.2 KEYBOARD CODES AND FUNCTIONS

Control key functions in CP/M:

DEL Delete and echo the last character typed at the console (same as rubout).

CTRL-C CP/M system reboot (warm start).

CTRL-E Physical, not logical, end of line. Carriage is returned, but line is not sent until RETURN key is pressed.

CTRL-G Bell; sounds an audible bell (from keyboard).

CTRL-H Backspace; move cursor left one character position.

CTRL-I Horizontal tab, moves cursor to the next defined tab stop. (CP/M assumes tab stops at every 8th position.

CTRL-J Line feed: move cursor down one line.

CTRL-M Carriage return; return cursor to left margin.

CTRL-R Retype current command line. Types a "clean line" following character deletion with rubouts.

CTRL-U Delete the entire line typed at the console.

CTRL-X Same as CTRL-U.

SEE ALSO: ASCII character chart, Section 17.1.

#### 16.3 CONNECTOR PIN-OUTS

This section contains drawings of the pin assignments on various output ports on Kaypro computers, intended as an aid in building printer cables and in troubleshooting problems with peripherals.

### CONNECTOR PIN-OUTS, KAYPRO 2/83 AND KAYPRO 4/83

#### PARALLEL PRINTER PORT: J2

|       | STROBE  | 1  | 19 |        |
|-------|---------|----|----|--------|
| (LSB) | DATA Ø  | 2  | 2Ø |        |
|       | DATA 1  | 3  | 21 |        |
|       | DATA 2  | 4  | 22 |        |
|       | DATA 3  | 5  | 23 |        |
|       | DATA 4  | 6  | 24 |        |
|       | DATA 5  | 7  | 25 | GROUND |
|       | DATA 6  | 8  | 26 |        |
| (MSB) | DATA 7  | 9  | 27 |        |
|       | N/C     | 1Ø | 28 |        |
| BUS   | SY (IN) | 11 | 29 |        |
|       |         | 12 | 3Ø |        |
|       | N/C     | 13 | 31 | N/C    |
|       | N/C     | 14 | 32 | N/C    |
|       |         | 15 | 33 | GROUND |
| apor  | B.TO    | 16 | 34 |        |
| GROU  | חאר     | 17 | 35 | N/C    |
|       | N/C     | 18 | 36 |        |

Top of connector Bottom of connector

Note that the BUSY line is read by the KAYPRO as active when it's disconnected (no cable). The computer will hang if you attempt to print to an unconnected parallel printer.

## **IQ\YPR) 2/83 AND lO\YPK).4/83** REmQMID~ **(J3)**

TxD 4 2 RxD GND 3 1 +5V

## **IQMJR) 2/83 AND I<AYPRO 4/83 SERIAL rom' (RS232C - J4)**

GROUND 1 14 TxD 2 15 . RxD 3 16 4 17 crs S 18 6 19 GROUND 7 20 8 21 9 22 10 23 N/C N/C 11 24 12 25 13

Bottan of connector

Top of connector

### KAYPRO 10 MODEM PORT (J3)

| GROUND | 1  |    |     |
|--------|----|----|-----|
| TxD    | 2  | 14 |     |
| IND    | 2  | 15 |     |
| RxD    | 3  | 16 |     |
| RTS    | 4  |    |     |
| CTS    | 5  | 17 |     |
|        |    | 18 |     |
| +5V    | 6  | 19 |     |
| GROUND | 7  |    |     |
| DCD    | 8  | 2Ø | DTR |
|        |    | 21 |     |
|        | 9  | 22 |     |
|        | 1Ø |    |     |
|        | 11 | 23 |     |
|        | 10 | 24 |     |
|        | 12 | 25 |     |
|        | 13 |    |     |

Bottom of connector

Top of connector

#### KAYPRO 10 KEYBOARD CONNECTOR (J5)

The pin-out for this connector is the same as J3 on the KAYPRO 2/83 and KAYPRO 4/83. See page 16-6.

#### KAYPRO 10 PARALLEL PRINTER CONNECTOR (J6)

The pin-out for this connector is the same as J2 on the KAYPRO 2/83 and KAYPRO 4/83. See page 16-5.

## KAYPRO 10 SERIAL PRINTER PORT (RS232C - J4)

```
GROUND
          1
              14
 RxD
              15
 TxD
          3
              16
              17
          5
             18
          6
              19
GROUND
             2Ø
                  CTS
          8
             21
         9
             22
         1Ø
                  N/C
              23
         11
              24
        12
              25
        13
              Bottom of connector
```

Top of connector

The pin-out for this connector is the same as J3 on the KAYPRO 2/83 and KAYFro 4/83. See page 16--6.

## I<AYPBO 2/84. 2X, 4/84. 4X AND lQ3IB SERIAL :flAm aJAR!1EL (J4)

The pin-out for this connector is the same as J4 00 the KAYFro 2/83 and KAYPRO 4/83. See page 16-6. .

## I<AYPBO 2/84. 2X. 4/84. 4X AND ROOIB SERIAL PRllllm ~l'CR (J3)

| GroUND | 1    |      |      |
|--------|------|------|------|
|        |      | 14   |      |
| RxD    | 2    | 15   |      |
| TxD    | 3    |      |      |
|        | 4    | 16   |      |
|        |      | 17   |      |
| N/C    | 5    | 18   |      |
|        | 6    |      |      |
| GROUND | 7    | 19   |      |
|        |      | 2121 | Cl'S |
|        | 8    | 21   |      |
|        | 9    |      |      |
|        | 1121 | 22   |      |
|        |      | 23   | N/C  |
| N/C    | 11   | 24   |      |
|        | 12   |      |      |
|        |      | 25   |      |
|        | 13   |      |      |

### KAYPRO 2/84, 2X, 4/84, 4X AND ROBIE PARALLEL PRINTER CONNECTOR (J5)

## KAYPRO 4/84, 4X AND ROBIE MODEM CONNECTOR (J6)

Note that this is NOT connected on the 2/84 and 2X.

N/C 1 2 N/C
TIP (Green) 3 4 RING (Red)
N/C 5 6 N/C

#### 16.4 I/O PORT ADDRESSES

The port addresses below apply to KAYPRO 2/83 and 4/83 computers.

| Port # | Use and/or Assignment                                                                                                                                         |
|--------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 00     | Baud Rate (write only) - Writing a number between $\emptyset$ and F hex (see baud rate table) to this port sets the RS-232C baud rate.                        |
| Ø4     | RS-232C Serial Data (R/W) - Data register of the Z-80 SIO. Refer to Zilog/Mostek Microcomputer Data books for further information.                            |
| Ø5     | Keyboard Data ( $R/W$ ) - Eight-bit data from detachable keyboard.                                                                                            |
| Ø6     | RS-232C Status (R/W) - Control/status port for the Z-80 SIO. Refer to Zilog/Mostek Microcomputer Data books for further information.                          |
| Ø8     | Printer Port (write only) - Eight-bit data to parallel printer connector.                                                                                     |
| 1C     | System Port $(R/W)$ - This port is used for system control. The various bits are used for memory bank selection, disk drive control, and printer handshaking. |

The serial output is an 8-bit word with one start, one stop, and no parity.

#### Examples:

- \* Received character available is obtained by testing bit Ø of the status port. Character is available if this bit is high (a 1 rather than Ø).
- \* Transmit Buffer Empty is obtained by testing bit 2 of the status port. Buffer is empty when bit 2 is high (1).

Manuals on the Z-80 CPU, Z-80 PIO, Z-80 SIO are available from the ZILCG sales office nearest to you. Western Digital can sell you a copy of the manual for the Floppy Disk Controller. Refer to Reference Section for vendors' mailing addresses and phone numbers.

When ordering manuals for any of the chips mentioned above, remove the hood from the computer and write down the full model number that is on the top surface of the chip. This is the best way to be certain of getting the proper manual from either of the manufacturers listed above.

The following p::>rt address information applies to KAYPRO l~, KAYPRO 2/84, KAYPRO 2X, KAYPro 4/84, KAYPRO 4X, am KAYPRO ROBIE.

## I/O **roRl' AaWESSES**

| Use                 | Port#<br>(hex) | Device                                    | Function                                                |
|---------------------|----------------|-------------------------------------------|---------------------------------------------------------|
| Keyboard:           | ~5             | ZSIO 1<br>Olan. B                         | Eight-bit<br>Keyboard data(R/W).<br>data fran keyboard. |
|                     | ~7             | ZSIO 1<br>Chan. B                         | Keyboard control/status I/O.                            |
| Vide:>:             | lC             | 6545/6845 FA                              | CRl' controller status/control<br>I/O.                  |
|                     | lD             | 6545/6845 FA                              | CRl' controller data I/O.                               |
|                     | 18 -<br>lB     | Parallel Printer: (output only)<br>74 373 | Parallel printer port<br>(write only).                  |
|                     |                |                                           |                                                         |
|                     |                |                                           |                                                         |
| Serial Printer I/O: | ~8 -<br>~B     | WD 1943<br>CCM 8116                       | Baud rate for serial printer<br>p::>rt.                 |
|                     | OC             | ZSIO 2<br>Chan. A                         | Serial printer data I/O<br>(RS-232C) •                  |
|                     |                | ZSIO 2<br>Chan. A                         | Serial printer control/ status<br>I/O.                  |
|                     |                |                                           |                                                         |
| Serial D3.ta I/O:   | 00 -<br>~3     | WD 1943<br>CCM 8116                       | Baud rate for serial data p::>rt<br>(write only).       |
|                     | 04             | ZSIO 1<br>Chan. A                         | Serial data port (RS-232C).<br>D3.ta I/O.               |

|            | Port#        |                                       |                                                       |
|------------|--------------|---------------------------------------|-------------------------------------------------------|
| <u>Use</u> | (hex)        | Device                                | Function                                              |
| Real-time  | clock:<br>20 | (NS-MM58167A)<br>PIO Chan. A<br>data. | Real-time clock register select and interrupt status. |
|            |              |                                       | Bit functions:                                        |
|            |              |                                       | <pre>Ø lsb register select (output). 1</pre>          |
|            | 22           | PIO Chan. A                           | Real-time clock PIO control port.                     |
|            | 24           | MM 58167A                             | Real-time clock data I/O.                             |

| <u>Use</u> | (hex)   | Device | <u>Function</u>                                                                                                                                                                                                                                                                                                   |
|------------|---------|--------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| System:    | 14 - 17 | 74 373 | System output port. Bit functions.                                                                                                                                                                                                                                                                                |
|            |         |        | <pre>Ø Ø=Select floppy A (C on KlØ). 1 Ø=Select floppy B (Hard disk on KlØ). 2 Ø=Select side 2. 3 PSTROB 4 Ø=Floppy motor on (48 tpi drives). 1=Select high speed (High density drive). * see note 5 Ø=Select double-density. 6 Ø=Select normal character set. 7 Ø=Select RCM (RAM 8000-FFFF).</pre>              |
|            |         | 74 244 | System input port.  Bit functions.  Ø Ø=floppy A selected (C on KlØ).  1 Ø=floppy B selected    (Hard disk on KlØ).  2 Ø=Side 2 selected.  3 PSTROB.  4 Ø=motor is on (48 tpi floppy).  5 Ø=Double-density is selected.  6 Ø=Parallel printer is busy.  7 Ø=64K RAM is selected.  1=RCM (RAM 8ØØØ-FFFF) selected. |

<sup>\*</sup> Note on high-density drives:

Port#

A l in bit position 4 will select high speed on the high-density diskette drive. To reset the drive to low speed it is necessary to change this bit to a  $\emptyset$  AND open the drive door, then close it.

| <u>Use</u> | Port#<br>(hex) | Device            | <u>Function</u>                                                                                                                                                                                                                                                                     |
|------------|----------------|-------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Internal   | Modem:<br>ØD   | ZSIO 2<br>Chan. B | Internal modem data I/O port.                                                                                                                                                                                                                                                       |
|            | ØF             | ZSIO 2<br>Chan. B | Internal modem status/control I/O port.                                                                                                                                                                                                                                             |
|            | 21             | PIO Chan. B       | Internal modem control lines.                                                                                                                                                                                                                                                       |
|            |                |                   | Bit functions.  Ø lsb digit to dial (output).  1 " 2 " 3 msb digit to dial (output). 4 Ø=touch tone. l=pulse dialate on modem chip. 5 Ø=not loop back (test mode). 6 Ø=off hook (on line). 7 l=digit present to dialer chip, not BSTROBE input present next digit from dialer chip. |
|            | 23             | PIO Chan. B       | Modem PIO control port.                                                                                                                                                                                                                                                             |

The internal modem on the KAYPRO uses Texas Instruments TMS99531 dialer and TMS99532 modem chips. Both of these chips are accessed through the Z80 PIO and Z80 SIO chips. Specification sheets on these chips are available from Texas Instruments and ZILOG respectively.

| Disk Co | ntroller 1 | Ports: |                                                  |
|---------|------------|--------|--------------------------------------------------|
|         | 1Ø         | 1793   | Floppy disk controller status/command I/O port.  |
|         | 11         | 1793   | Floppy disk controller track register I/O port.  |
|         | 12         | 1793   | Floppy disk controller sector register I/O port. |
|         | 13         | 1793   | Floppy disk controller data register I/O port.   |

| Use | 1:Ort#<br>(hex) | Device  | Functioo                                                     |
|-----|-----------------|---------|--------------------------------------------------------------|
|     | 00              | WD 1002 | Hard disk CXXltroller card<br>data I/O port.                 |
|     | 81              |         | Error Register (input.).<br>(output).<br>Write Preoc::mp.    |
|     | 82              |         | Sector COlttlt register I/O.                                 |
|     | 83              |         | Sector m:mber register I/O.                                  |
|     | 84              |         | Cylinder lOA' register I/O.                                  |
|     | 85              |         | Cylinder high register I/O.                                  |
|     | 86              |         | Size/drive/head register I/O.                                |
|     | 87              |         | Status register 1br inp.lt.<br>C:mnand register :fur output. |

### 17.0 REFERENCE SECTION

## 17.1 ASCII CHART

| Dec | Hex | Char      | Dec | Hex | Char  | Dec | Hex        | Char | Dec | Hex | Char |
|-----|-----|-----------|-----|-----|-------|-----|------------|------|-----|-----|------|
|     |     |           |     |     |       |     |            |      |     |     |      |
| Ø   | ØØ  | NUL or ^@ | 32  | 2Ø  | Space | 64  | 40         | @    | 96  | 6Ø  | •    |
| 1   | Ø1  | SOH or ^A | 33  | 21  | 1     | 65  | 41         | Α    | 97  | 61  | a.   |
| 2   | Ø2  | STX or ^B | 34  | 22  | **    | 66  | 42         | В    | 98  | 62  | b    |
| 3   | Ø3  | ETX or ^C | 35  | 23  | #     | 67  | 43         | С    | 99  | 63  | C    |
| 4   | Ø4  | EOT or ^D | 36  | 24  | \$    | 68  | 44         | D    | 100 | 64  | đ    |
| 5   | Ø5  | ENQ or ^E | 37  | 25  | 8     | 69  | 45         | E    | 1Ø1 | 65  | е    |
| 6   | Ø6  | ACK or ^F | 38  | 26  | &     | 7Ø  | 46         | F    | 1Ø2 | 66  | f    |
| 7   | Ø7  | BEL or ^G | 39  | 27  | •     | 71  | 47         | G    | 1Ø3 | 67  | g    |
| 8   | Ø8  | BS or TH  | 40  | 28  | (     | 72  | 48         | H    | 1Ø4 | 68  | h    |
| 9   | Ø9  | HT or Î   | 41  | 29  | )     | 73  | 49         | I    | 1Ø5 | 69  | i    |
| 1Ø  | ØA  | LF or J   | 42  | 2A  | *     | 74  | 4A         | J    | 1Ø6 | 6A  | j    |
| 11  | ØB  | VT or K   | 43  | 2B  | +     | 75  | 4B         | K    | 1Ø7 | 6B  | k    |
| 12  | ØC  | FF or ^L  | 44  | 2C  | ,     | 76  | 4C         | L    | 1Ø8 | 6C  | 1    |
| 13  | ØD  | CR or ^M  | 45  | 2D  | -     | 77  | 4D         | M    | 1Ø9 | 6D  | m    |
| 14  | ØE  | so or n   | 46  | 2E  | •     | 78  | 4E         | N    | 11Ø | 6E  | n    |
| 15  | ØF  | SI or ^O  | 47  | 2F  | /     | 79  | <b>4</b> F | 0    | 111 | 6F  | 0    |
| 16  | 1Ø  | DLE or ^P | 48  | 3Ø  | Ø     | 8Ø  | 5Ø         | P    | 112 | 7Ø  | р    |
| 17  | 11  | DCl or ^Q | 49  | 31  | 1     | 81  | 51         | Q    | 113 | 71  | q    |
| 18  | 12  | DC2 or ^R | 5Ø  | 32  | 2     | 82  | 52         | R    | 114 | 72  | r    |
| 19  | 13  | DC3 or ^S | 51  | 33  | 3     | 83  | 53         | S    | 115 | 73  | s    |
| 2Ø  | 14  | DC4 or ^T | 52  | 34  | 4     | 84  | 54         | T    | 116 | 74  | t    |
| 21  | 15  | NAK or ^U | 53  | 35  | 5     | 85  | 55         | U    | 117 | 75  | u    |
| 22  | 16  | SYN or ^V | 54  | 36  | 6     | 86  | 56         | V    | 118 | 76  | v    |
| 23  | 17  | ETB or W  | 55  | 37  | 7     | 87  | 57         | W    | 119 | 77  | W    |
| 24  | 18  | CAN or ^X | 56  | 38  | 8     | 88  | 58         | Х    | 12Ø | 78  | х    |
| 25  | 19  | EM or Y   | 57  | 39  | 9     | 89  | 59         | Y    | 121 | 79  | У    |
| 26  | 1A  | SUB or ^Z | 58  | ЗА  | :     | 9Ø  | 9A         | - Z  | 122 | 7A  | z    |
| 27  | 1B  | ESC or ^[ | 59  | 3B  | ;     | 91  | 5B         | Ε    | 123 | 7B  | - {  |
| 28  | 1C  | FS or ^\  | 60  | 3C  | <     | 92  | 5C         | 7    | 124 | 7C  | Į    |
| 29  | 1D  | GS or ^]  | 61  | 3D  | _ =   | 93  | 5D         | יַ   | 125 | 7D  | }    |
| ЗØ  | 1E  | RS or ^^  | 62  | 3E  | >     | 94  | 5E         | ^    | 126 | 7E  | ~    |
| 31  | 1F  | US or     | 63  | 3F  | ?     | 95  | 5F         | _    | 127 | 7F  | DEL  |

#### 17.3 MEMORY MAPS

## **MEMORY MAP OF KAYPRO 2 AND KAYPRO 4**

| CBIOS                        | FA00H |
|------------------------------|-------|
| BDOS                         | EC00H |
| ССР                          | E400H |
|                              |       |
| TRANSIENT<br>PROGRAM<br>AREA |       |
|                              |       |
|                              | 100Н  |
| CP/M BUFFERS                 | 00Н   |

## MEMORY MAP OF KAYPRO 10

| CBIOS                        | EAOOH |
|------------------------------|-------|
| BOOS                         | OCOOH |
| CCP                          | 0400H |
| TRANSIENT<br>PROGRAM<br>AREA | IOOH  |
| CP/M BUFFERS                 | OOH   |

## MEMORY MAP OF KAYPRO *2/84* AND *4/84*

| CBIOS                        | F600H |
|------------------------------|-------|
| BOOS                         | E800H |
| CCP                          | EOOOH |
| TRANSIENT<br>PROGRAM<br>AREA | IOOH  |
| CP/M BUFFERS                 | OOH   |

## MEMORY MAP OF KAYPRO ROBIE

| CBIOS                        | F200H |
|------------------------------|-------|
| BOOS                         | E400H |
| CCP                          | OCOOH |
| TRANSIENT<br>PROGRAM<br>AREA | IOOH  |
| CP/M BUFFERS                 | OOH   |

#### 17.4 VENDOR ADDRESSES

Kaypro Corporation does not provide repair or reference manuals for other companies' products which are used in Kaypro computers. The list below does not presume to be complete, but is included for dealer convenience in ordering manuals directly from the manufacturer.

#### Drives

Drivetec 2140 Bering Drive San Jose, Ca. 95131 (408) 946-2222

Epson 17752 Skypark #255 Irvine, Ca 92714 (714) 250-0111

HI-TEC 10150 Sorrento Valley Rd. San Diego, Ca. 92121 (619) 452-5500

Microscience 575 E. Middlefield Road Mountain View, Ca. 94043 (415) 961-2212

Seagate 920 Disc Drive Scotts Valley, Ca. 95066 (408) 438-6550

Shugart 475 Cakmead Parkway Sunnyvale, Ca. 94086 (408) 733-0100

Tandon 20320 Prairie St. Chatsworth, Ca. 91311 (213) 993-6644

TEC 1000 E. Walnut St. Pasadena, Ca. 91106 (213) 681-5631

Toshiba 9030 Carroll Canyon #7 San Diego, Ca. 92121 (619) 578-9171

#### Integrated Circuits

Mostek 18004 Skypark Circle Suite 140 Irvine, Ca. 92714 (714) 250-0455

National Semiconductor 2900 Semiconductor Drive Santa Clara, Ca. 95051 (408) 737-5000

Texas Instruments 1762Ø Fitch Irvine, Ca. 92714 (714) 545-521Ø

Western Digital 3128 Red Hill Ave. Costa Mesa, Ca. 92626

Zilog 18023 Skypark Circle Suite J Irvine, Ca. 92714 (714) 549-2891

#### CRT Assemblies

## Power Supplies

Astec

Audiotronics

7420 Belair Ave.

N. Hollywood, Ca. 91605

(213) 765-2645

Dotronix

160 lst Street S. E. New Brighton, MN. 55112

(612) 633-1742

Elston

35 Lehigh Street Geneva, N.Y. 14456

(315) 781-1350

Toshiba

9030 Carroll Canyon #7

Boschert

384 Santa Trinita Ave.

Santa Clara, Ca. 95050

Sunnyvale, Ca. 94086

(408) 732-2240

1101 Space Park

(408) 727-3350

Cal D.C.

2150 Anehor Court

Newbury Park, Ca. 91320

(8Ø5) 499-3621

San Diego, Ca. 92121

(619) 578-9171

Disk Controller Board

Western Digital 2445 MCCabe Way

Irvine, Ca. 92714

(714) 863-0102

Keyboards

Keytronics

7032 Owensmouth

Canoga Park, Ca. 91303

(714) 832-1685

KBD

2160150 A65-02706 .001

630184-02 -201 PC3D

Maxi-Switch

9697 E. River Road

Minneapolis, MN. 55433

(612) 755-7660

KYBD 2160150

PCBD

630184-02

SMK

4617 Ruffner Street #206

San Diego, Ca. 92111

(619) 560-8330

3-19011-024

TW-1794V-0

#### 18.0 SUGGESTED REFERENCES

**KAYPRO II Theory of Operation**, by Dana Cotant-Micro Cornucopia, P.O. Box 223 - Bend, OR. 97709

Modern Dictionary of Electronics, by Rudolf F. Graf, Radio Shack Catalog Number 62-2310

Some **colored markers or pencils** with which to mark the chip layout diagrams in this manual according to function (video, disk control, etc.) will be useful. Such "maps" can be time-saving devices. (Because of printing costs and problems, Kaypro is unable to supply colored "maps" in the Technical Manual.)

The CP/M Manual included with each KAYPRO. You can devise excellent and effective tests for the machines through imaginative use of CP/M programs like PIP, SUBMIT, XSUB. To this end, books about CP/M (with an emphasis on programming; not for the beginner) can be helpful.

A good book containing information on the **Z8Ø microcomputer** and its family (SIO, PIO). Timing diagrams (or scope signals) in these books can help troubleshoot mainboards.

Any component repair manuals you feel necessary. See Section 17.4 for vendor addresses.

#### INDEX

220V configuration, 8-2 align.mac, 7--5 aligning CRT yoke, 7-2 ASCII chart, 17--1 brightness, 7-2 chassis hood, 5---1 CRT adjustments, 7-1 CRT assembly removal, 7-8 CRT descriptions, 7--1 disk drive cleaning, 9--1 diskette drive configuration, 9-5 diskette drive identification, 9---2 diskette drives, 9--1 Drivetec, 9--9 focus, 7---2 fuse, 8-2 hard disk drive, 10--1 hard drive configuration, 10-3 hard drive controller board, 11--1 hard drive removal, 10--4 high-density (Drivetec) drives, 9-9 horizontal centering, 7-1 horizontal hold, 7-2 horizontal width, 7-1 I/O port addresses, 16--10 interface board KAYPRO 10, 12-1 internal modem, 16--14 KAYPRO 10 block diagram, 6-18 KAYPRO 10 specifications, 3-1 KAYPRO 2 and 4 block diagram, 6-6 KAYPRO 2 specifications, 3--1 KAYPRO 2/84 and 2X specifications, 3-2 KAYPRO 4 specifications, 3--3 KAYPRO 4/84 specifications, 3--4 KAYPRO 4X specifications, 3--5 KAYPRO ROBIE specifications, 3-7 keyboard, 13--1 keyboard codes and functions, 16--3 keyboard connector, 16-6 mainboard removal, 6--51 mainboards, 6--1 memory maps, 17--3 modem port KAYPRO 10, 16-7 parallel printer port, 16--5 power supplies, 8-1 power supply removal, 8--5 real-time clock, 16-12 ROBIE removal/installation, 14--1 serial port KAYPRO 2 and 4, 16—6 serial printer port KAYPRO 10, 16--7.1

touch-up information, 5—2 troubleshooting, 15—1 vendor addresses, 17—6 vertical size and linearity, 7—1 video alignment, 7—3 video command protocol, 16—1

## PUBLICATICN C<M1ENT SHEEl'

|      | Please use this oomment sheet to assist with identificaticn of errors or<br>needed improvements in this manual. |  |
|------|-----------------------------------------------------------------------------------------------------------------|--|
|      | Date                                                                                                            |  |
|      |                                                                                                                 |  |
|      | ~<br>Job Title                                                                                                  |  |
|      | Address                                                                                                         |  |
| Page | Cannent                                                                                                         |  |
|      |                                                                                                                 |  |
|      |                                                                                                                 |  |
|      |                                                                                                                 |  |
|      |                                                                                                                 |  |
|      |                                                                                                                 |  |
|      |                                                                                                                 |  |

Please mail this :fbnn to the :fbllc::Ming address.

Publications Department Kaypro Corporation P.O. Box N Del Mar, Ca. 92014