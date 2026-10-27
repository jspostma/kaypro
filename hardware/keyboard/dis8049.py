#!/usr/bin/env python3
"""MCS-48 (Intel 8049 / Mitsubishi M5L8049) disassembler.

Instruction set reference: Intel MCS-48 Microcomputer User's Manual.

Address encoding:
  JMP/CALL:          upper 3 bits of opcode = addr[10:8], second byte = addr[7:0]
  Conditional jumps: target = (pc_of_insn & 0xF00) | second_byte
"""

import sys
from pathlib import Path

# Instruction table: opcode -> (mnemonic_template, size)
# Mnemonic templates use '%s' for branch targets (substituted later),
# or '%02Xh' for 8-bit immediates.
INSNS = {
    0x00: ("NOP", 1),
    0x02: ("OUTL BUS,A", 1),
    0x03: ("ADD A,#%02Xh", 2),
    0x05: ("EN I", 1),
    0x07: ("DEC A", 1),
    0x08: ("INS A,BUS", 1),
    0x09: ("IN A,P1", 1),
    0x0A: ("IN A,P2", 1),
    0x0C: ("MOVD A,P4", 1),  0x0D: ("MOVD A,P5", 1),
    0x0E: ("MOVD A,P6", 1),  0x0F: ("MOVD A,P7", 1),
    0x10: ("INC @R0", 1),    0x11: ("INC @R1", 1),
    0x12: ("JB0 %s", 2),
    0x13: ("ADDC A,#%02Xh", 2),
    0x15: ("DIS I", 1),
    0x16: ("JTF %s", 2),
    0x17: ("INC A", 1),
    0x18: ("INC R0", 1),  0x19: ("INC R1", 1),
    0x1A: ("INC R2", 1),  0x1B: ("INC R3", 1),
    0x1C: ("INC R4", 1),  0x1D: ("INC R5", 1),
    0x1E: ("INC R6", 1),  0x1F: ("INC R7", 1),
    0x20: ("XCH A,@R0", 1),  0x21: ("XCH A,@R1", 1),
    0x23: ("MOV A,#%02Xh", 2),
    0x25: ("EN TCNTI", 1),
    0x26: ("JNT0 %s", 2),
    0x27: ("CLR A", 1),
    0x28: ("XCH A,R0", 1),  0x29: ("XCH A,R1", 1),
    0x2A: ("XCH A,R2", 1),  0x2B: ("XCH A,R3", 1),
    0x2C: ("XCH A,R4", 1),  0x2D: ("XCH A,R5", 1),
    0x2E: ("XCH A,R6", 1),  0x2F: ("XCH A,R7", 1),
    0x30: ("XCHD A,@R0", 1),  0x31: ("XCHD A,@R1", 1),
    0x32: ("JB1 %s", 2),
    0x35: ("DIS TCNTI", 1),
    0x36: ("JT0 %s", 2),
    0x37: ("CPL A", 1),
    0x39: ("OUTL P1,A", 1),  0x3A: ("OUTL P2,A", 1),
    0x3C: ("MOVD P4,A", 1),  0x3D: ("MOVD P5,A", 1),
    0x3E: ("MOVD P6,A", 1),  0x3F: ("MOVD P7,A", 1),
    0x40: ("ORL A,@R0", 1),  0x41: ("ORL A,@R1", 1),
    0x42: ("MOV A,T", 1),
    0x43: ("ORL A,#%02Xh", 2),
    0x45: ("STRT CNT", 1),
    0x46: ("JNT1 %s", 2),
    0x47: ("SWAP A", 1),
    0x48: ("ORL A,R0", 1),  0x49: ("ORL A,R1", 1),
    0x4A: ("ORL A,R2", 1),  0x4B: ("ORL A,R3", 1),
    0x4C: ("ORL A,R4", 1),  0x4D: ("ORL A,R5", 1),
    0x4E: ("ORL A,R6", 1),  0x4F: ("ORL A,R7", 1),
    0x50: ("ANL A,@R0", 1),  0x51: ("ANL A,@R1", 1),
    0x52: ("JB2 %s", 2),
    0x53: ("ANL A,#%02Xh", 2),
    0x55: ("STRT T", 1),
    0x56: ("JT1 %s", 2),
    0x57: ("DA A", 1),
    0x58: ("ANL A,R0", 1),  0x59: ("ANL A,R1", 1),
    0x5A: ("ANL A,R2", 1),  0x5B: ("ANL A,R3", 1),
    0x5C: ("ANL A,R4", 1),  0x5D: ("ANL A,R5", 1),
    0x5E: ("ANL A,R6", 1),  0x5F: ("ANL A,R7", 1),
    0x60: ("ADD A,@R0", 1),  0x61: ("ADD A,@R1", 1),
    0x62: ("MOV T,A", 1),
    0x65: ("STOP TCNT", 1),
    0x67: ("RRC A", 1),
    0x68: ("ADD A,R0", 1),  0x69: ("ADD A,R1", 1),
    0x6A: ("ADD A,R2", 1),  0x6B: ("ADD A,R3", 1),
    0x6C: ("ADD A,R4", 1),  0x6D: ("ADD A,R5", 1),
    0x6E: ("ADD A,R6", 1),  0x6F: ("ADD A,R7", 1),
    0x70: ("ADDC A,@R0", 1),  0x71: ("ADDC A,@R1", 1),
    0x72: ("JB3 %s", 2),
    0x75: ("ENT0 CLK", 1),
    0x76: ("JF1 %s", 2),
    0x77: ("RR A", 1),
    0x78: ("ADDC A,R0", 1),  0x79: ("ADDC A,R1", 1),
    0x7A: ("ADDC A,R2", 1),  0x7B: ("ADDC A,R3", 1),
    0x7C: ("ADDC A,R4", 1),  0x7D: ("ADDC A,R5", 1),
    0x7E: ("ADDC A,R6", 1),  0x7F: ("ADDC A,R7", 1),
    0x80: ("MOVX A,@R0", 1),  0x81: ("MOVX A,@R1", 1),
    0x83: ("RET", 1),
    0x85: ("CLR F0", 1),
    0x86: ("JNI %s", 2),
    0x87: ("RLC A", 1),
    0x88: ("ORL BUS,#%02Xh", 2),
    0x89: ("ORL P1,#%02Xh", 2),  0x8A: ("ORL P2,#%02Xh", 2),
    0x8C: ("ORLD P4,A", 1),  0x8D: ("ORLD P5,A", 1),
    0x8E: ("ORLD P6,A", 1),  0x8F: ("ORLD P7,A", 1),
    0x90: ("MOVX @R0,A", 1),  0x91: ("MOVX @R1,A", 1),
    0x92: ("JB4 %s", 2),
    0x93: ("RETR", 1),
    0x95: ("CPL F0", 1),
    0x96: ("JNZ %s", 2),
    0x97: ("CLR C", 1),
    0x98: ("ANL BUS,#%02Xh", 2),
    0x99: ("ANL P1,#%02Xh", 2),  0x9A: ("ANL P2,#%02Xh", 2),
    0x9C: ("ANLD P4,A", 1),  0x9D: ("ANLD P5,A", 1),
    0x9E: ("ANLD P6,A", 1),  0x9F: ("ANLD P7,A", 1),
    0xA0: ("MOV @R0,A", 1),  0xA1: ("MOV @R1,A", 1),
    0xA3: ("MOVP A,@A", 1),
    0xA5: ("CLR F1", 1),
    0xA7: ("CPL C", 1),
    0xA8: ("MOV R0,A", 1),  0xA9: ("MOV R1,A", 1),
    0xAA: ("MOV R2,A", 1),  0xAB: ("MOV R3,A", 1),
    0xAC: ("MOV R4,A", 1),  0xAD: ("MOV R5,A", 1),
    0xAE: ("MOV R6,A", 1),  0xAF: ("MOV R7,A", 1),
    0xB0: ("MOV @R0,#%02Xh", 2),  0xB1: ("MOV @R1,#%02Xh", 2),
    0xB2: ("JB5 %s", 2),
    0xB3: ("JMPP @A", 1),
    0xB5: ("CPL F1", 1),
    0xB6: ("JF0 %s", 2),
    0xB8: ("MOV R0,#%02Xh", 2),  0xB9: ("MOV R1,#%02Xh", 2),
    0xBA: ("MOV R2,#%02Xh", 2),  0xBB: ("MOV R3,#%02Xh", 2),
    0xBC: ("MOV R4,#%02Xh", 2),  0xBD: ("MOV R5,#%02Xh", 2),
    0xBE: ("MOV R6,#%02Xh", 2),  0xBF: ("MOV R7,#%02Xh", 2),
    0xC2: ("JB6 %s", 2),
    0xC5: ("SEL RB0", 1),
    0xC6: ("JZ %s", 2),
    0xC7: ("MOV A,PSW", 1),
    0xC8: ("DEC R0", 1),  0xC9: ("DEC R1", 1),
    0xCA: ("DEC R2", 1),  0xCB: ("DEC R3", 1),
    0xCC: ("DEC R4", 1),  0xCD: ("DEC R5", 1),
    0xCE: ("DEC R6", 1),  0xCF: ("DEC R7", 1),
    0xD0: ("XRL A,@R0", 1),  0xD1: ("XRL A,@R1", 1),
    0xD2: ("JB7 %s", 2),
    0xD3: ("XRL A,#%02Xh", 2),
    0xD5: ("SEL RB1", 1),
    0xD7: ("MOV PSW,A", 1),
    0xD8: ("XRL A,R0", 1),  0xD9: ("XRL A,R1", 1),
    0xDA: ("XRL A,R2", 1),  0xDB: ("XRL A,R3", 1),
    0xDC: ("XRL A,R4", 1),  0xDD: ("XRL A,R5", 1),
    0xDE: ("XRL A,R6", 1),  0xDF: ("XRL A,R7", 1),
    0xE3: ("MOVP3 A,@A", 1),
    0xE5: ("SEL MB0", 1),
    0xE6: ("JNC %s", 2),
    0xE7: ("RL A", 1),
    0xE8: ("DJNZ R0,%s", 2),  0xE9: ("DJNZ R1,%s", 2),
    0xEA: ("DJNZ R2,%s", 2),  0xEB: ("DJNZ R3,%s", 2),
    0xEC: ("DJNZ R4,%s", 2),  0xED: ("DJNZ R5,%s", 2),
    0xEE: ("DJNZ R6,%s", 2),  0xEF: ("DJNZ R7,%s", 2),
    0xF0: ("MOV A,@R0", 1),  0xF1: ("MOV A,@R1", 1),
    0xF2: ("JC %s", 2),
    0xF5: ("SEL MB1", 1),
    0xF6: ("JNZ %s", 2),
    0xF8: ("MOV A,R0", 1),  0xF9: ("MOV A,R1", 1),
    0xFA: ("MOV A,R2", 1),  0xFB: ("MOV A,R3", 1),
    0xFC: ("MOV A,R4", 1),  0xFD: ("MOV A,R5", 1),
    0xFE: ("MOV A,R6", 1),  0xFF: ("MOV A,R7", 1),
}

# Set of opcodes whose upper 3 bits encode the destination page
JMP_BASE  = 0x04
CALL_BASE = 0x14

def is_jmp(op):  return (op & 0x1F) == JMP_BASE
def is_call(op): return (op & 0x1F) == CALL_BASE

def jmp_target(op, imm):
    return ((op & 0xE0) << 3) | imm

def cond_target(pc, imm):
    return (pc & 0xF00) | imm

def is_branch(op, mnemo):
    return mnemo.endswith("%s")


def first_pass(rom):
    """Collect all branch targets for label generation."""
    targets = set()
    targets.add(0)          # entry point always labelled
    pc = 0
    while pc < len(rom):
        op = rom[pc]
        if is_jmp(op) or is_call(op):
            if pc + 1 < len(rom):
                targets.add(jmp_target(op, rom[pc + 1]))
            pc += 2
        elif op in INSNS:
            mnemo, size = INSNS[op]
            if size == 2 and pc + 1 < len(rom) and is_branch(op, mnemo):
                targets.add(cond_target(pc, rom[pc + 1]))
            pc += size
        else:
            pc += 1
    return targets


def addr_ref(addr, labels):
    """Format an address as a label reference or hex literal."""
    if addr in labels:
        return f"L_{addr:03X}"
    return f"{addr:03X}h"


def disassemble(rom):
    labels = first_pass(rom)
    lines = []
    pc = 0
    while pc < len(rom):
        label = f"L_{pc:03X}:" if pc in labels else ""
        op = rom[pc]

        if is_jmp(op) or is_call(op):
            if pc + 1 < len(rom):
                imm = rom[pc + 1]
                tgt = jmp_target(op, imm)
                mne = "JMP" if is_jmp(op) else "CALL"
                lines.append((label, pc, f"{op:02X} {imm:02X}", f"{mne} {addr_ref(tgt, labels)}"))
                pc += 2
            else:
                lines.append((label, pc, f"{op:02X}", f"DB {op:02X}h  ; truncated"))
                pc += 1

        elif op in INSNS:
            mnemo, size = INSNS[op]
            if size == 2:
                if pc + 1 < len(rom):
                    imm = rom[pc + 1]
                    if is_branch(op, mnemo):
                        tgt = cond_target(pc, imm)
                        decoded = mnemo % addr_ref(tgt, labels)
                    else:
                        decoded = mnemo % imm
                    lines.append((label, pc, f"{op:02X} {imm:02X}", decoded))
                    pc += 2
                else:
                    lines.append((label, pc, f"{op:02X}", f"DB {op:02X}h  ; truncated"))
                    pc += 1
            else:
                lines.append((label, pc, f"{op:02X}", mnemo))
                pc += 1
        else:
            lines.append((label, pc, f"{op:02X}", f"DB {op:02X}h"))
            pc += 1

    return lines


def format_output(lines):
    out = []
    for label, pc, hexbytes, mnemo in lines:
        lbl = f"{label:<9}" if label else "         "
        out.append(f"{pc:04X}  {hexbytes:<6}  {lbl}  {mnemo}")
    return "\n".join(out)


def main():
    path = Path(sys.argv[1]) if len(sys.argv) > 1 else Path("KAYPRO-10_M5L8049.BIN")
    rom = path.read_bytes()
    print(f"; MCS-48 disassembly of {path.name} ({len(rom)} bytes)")
    print(f"; Mitsubishi M5L8049 (Intel 8049 compatible), 300 baud serial keyboard controller")
    print(f"; ROM address space: 0000h - {len(rom)-1:04X}h")
    print()
    lines = disassemble(rom)
    print(format_output(lines))


if __name__ == "__main__":
    main()