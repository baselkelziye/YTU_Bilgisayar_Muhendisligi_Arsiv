# Single-Cycle RISC-V Processor Implementation and ISA Extensions

## Overview

This project implements a complete single-cycle RISC-V processor in Verilog and progressively extends the instruction set architecture (ISA) with additional instructions.

The processor was developed according to the RISC-V architecture and verified using custom testbenches and waveform simulations.

---

## Supported Instructions

### Base Instruction Set

- lw
- sw
- add
- sub
- slt
- or
- and
- beq
- addi
- slti
- ori
- andi
- jal

### ISA Extensions

#### Extension 1

Added support for:

- srai (Shift Right Arithmetic Immediate)

Required modifications:

- Control Unit
- ALU Control Logic
- Immediate Handling Logic

#### Extension 2

Added support for:

- lh (Load Halfword)

Required modifications:

- Data Memory Interface
- Sign Extension Logic
- Control Signals

---

## Processor Architecture

Main modules include:

### Program Counter

- Instruction sequencing
- Branch handling
- Jump execution

### Instruction Memory

- Stores machine instructions

### Register File

- 32 general-purpose registers
- Dual-read, single-write architecture

### ALU

Performs:

- Arithmetic operations
- Logical operations
- Branch comparisons

### Control Unit

Generates:

- ALU control signals
- Memory control signals
- Write-back signals

### Data Memory

Supports:

- Word access
- Halfword access

---

## Verification

A dedicated testbench was created to verify:

- Arithmetic instructions
- Memory instructions
- Branch instructions
- Jump instructions
- Newly added ISA extensions

Simulation outputs were analyzed using GTKWave.

---

## Technologies

- Verilog HDL
- RISC-V ISA
- Icarus Verilog
- GTKWave

---

## Learning Outcomes

- CPU design fundamentals
- Single-cycle datapath architecture
- Instruction decoding
- Control unit design
- ISA extension methodology
- Hardware verification
