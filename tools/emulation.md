# Emulation and simulation

## Emulators
- **Virtual Kaypro** (Doug Miller, Java): <http://sims.durgadas.com/kaypro/kaypro.html>.
  Supports the Model 10/10X, so it already models the **WD1002 HDD controller** as a Java
  device on the 50-pin header bus. That class is the template for any header peripheral
  (port range, IN/OUT handlers, interrupt hookup, per-model registration).
- **MAME:** has Kaypro drivers and Lua scripting (key injection, frame grabs). Proposed
  backend for the [agent](../projects/agent.md) phase 0. Its `mc6845.cpp` covers the
  6845/6545 variants and is the best CRTC reference model.
- **kaytil** (kobolt): Z80 CP/M 2.2 emulator for Kaypro II games; also runs on a Pico.

## Mixed-level simulation for mods
You don't need a gate-level Kaypro. Use tick-level detail only where the mod touches the bus.

1. **Behavioral (Java device in Virtual Kaypro):** "does software work with this mod?"
   20–100 lines, full speed. ROM shadowing is a memory-map hook, dual-port VRAM is an
   external agent poking the VRAM array, bus mastering is "pause CPU, poke memory."
2. **Gate-level per transaction (hneemann's Digital):** "is my decode/glue right?" Digital
   is Java (load `.dig` into the emulator JVM, no IPC), has a 74xx library and test
   vectors (log real bus transactions as test cases), and exports Verilog/VHDL. Model the
   data bus as separate D_in/D_out/D_oe.
   Alternative: a generic "socket port" Java device forwarding IN/OUT over TCP to Python,
   or to cocotb plus Icarus/Verilator.
3. **Datasheet timing math on paper:** "is it fast enough?" Z80 bus-cycle min/max plus
   worst-case 74xx delays against the target's window. About a page per mod.
4. **Logic analyzer on the real box:** confirm. A Pico with PIO LA firmware handles 4 MHz.
5. **Cycle-stepped** (floooh `chips/z80.h`, per-tick 64-bit pin mask): only for mods that
   play with /WAIT, M1, refresh or bus arbitration (i.e. the CPU interposer's bus mastering).

## Hardware-in-the-loop
A Java device in Virtual Kaypro can forward port accesses over USB serial to a **real Pico
running the real firmware**. Emulated CP/M exercises the Pico's port handling with zero
risk to the machine. Latency is fine except for tight polling loops.

Practical order: build the jar from source → add a dummy device at an unused port and
confirm CP/M reaches it → turn that device into the Digital / Pico bridge.

## Falstad
CircuitJS is an analog timestep solver. Keep it for analog-ish bits (CRT drive, reset RC),
not bus logic.
