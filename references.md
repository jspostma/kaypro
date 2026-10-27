# References

## Kaypro-specific
- Kaypro10Video (Pico char-ROM/CRTC capture → HDMI): <https://github.com/jasperhax0r/Kaypro10Video>
- Virtual Kaypro emulator (Doug Miller): <http://sims.durgadas.com/kaypro/kaypro.html>
- kaytil (Kaypro II game-focused CP/M emulator, Pico port): <https://github.com/kobolt/kaytil>
- Local archive trees: see [archive index](archive/README.md)

## Video capture on other machines (same PIO technique)
- EBD_IPKVM (Lisa through SE/30, Pico capture plus ADB): <https://github.com/h4rm0n1c/EBD_IPKVM>
- mac-se-video-converter (SE → VGA / mono composite): <https://github.com/guruthree/mac-se-video-converter>
- QLpicoVGA (Sinclair QL → VGA): <https://github.com/holmatic/video_if_ql_vga>
- RGBtoHDMI: <https://github.com/hoglet67/RGBtoHDMI/wiki>
- TinyUSB (UVC device class example, for a Pico that enumerates as a webcam): <https://github.com/hathach/tinyusb>

## Simulation
- Digital (hneemann): <https://github.com/hneemann/Digital>
- floooh chips (`z80.h`, pin-level Z80): <https://github.com/floooh/chips>
- MAME `mc6845.cpp`: 6845/6545 variant reference

## Telephony / modem
- minimodem: software FSK modem (Bell 103 etc.)
- app_softmodem: third-party Asterisk app answering Bell 103/V.21/V.23/V.22bis and bridging to TCP
- FlashFloppy (Gotek firmware): <https://github.com/keirf/flashfloppy>

## Parts
- CY7C136 (master) / CY7C146 (slave): 2K×8 dual-port SRAM, 52-pin PLCC, with INT mailbox
  (7FF left / 7FE right). CY7C132/142 are 48-pin DIP only.
- AMP 87025-7 power connector → mating AMP 1-480702-0 housing, 350078-4 / 350689-4 pins.
- AMD Am9511 APU: interface template for the [NPU coprocessor](projects/npu-coprocessor.md).
