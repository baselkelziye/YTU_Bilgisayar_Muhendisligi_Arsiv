# High-Performance Structural RISC-V ALU and Datapath Design

## Overview

This project focuses on the design and implementation of a 32-bit RISC-V Arithmetic Logic Unit (ALU) using structural Verilog. The objective was to create a high-performance datapath capable of operating at the maximum possible clock frequency while satisfying setup and hold timing constraints.

Unlike behavioral implementations, all arithmetic and logical operations were constructed exclusively from basic logic gates, providing a low-level understanding of digital hardware design and timing optimization.

---

## Features

### Supported ALU Operations

| ALU Control | Operation |
|------------|------------|
| 000 | AND |
| 001 | XOR |
| 010 | ADD |
| 110 | SUB |
| 111 | SLT (Set Less Than) |

### Structural Hardware Design

- Gate-level implementation
- No behavioral arithmetic operators
- Fully structural datapath
- Timing-aware architecture

### Arithmetic Unit

Implemented a high-speed adder architecture to improve performance compared to a conventional Ripple Carry Adder (RCA).

Features:

- Reduced propagation delay
- Improved Fmax
- Faster arithmetic operations

### Signed Comparison Support

The SLT operation correctly handles:

- Signed integers
- Overflow detection
- Two's complement arithmetic

---

## Datapath Design

The datapath integrates:

- Register File
- 32-bit ALU
- Write-back path

Workflow:

1. Read operands from register file
2. Execute ALU operation
3. Write result back to register file

---

## Timing Analysis

### Maximum Frequency Analysis

The critical path was identified and analyzed to determine:

- Propagation delay
- Maximum operating frequency (Fmax)

### Hold-Time Verification

The fastest combinational paths were examined to detect:

- Race conditions
- Hold-time violations

Additional buffering techniques were applied when necessary to satisfy timing constraints.

---

## Verification

Simulation environment:

- Icarus Verilog
- GTKWave

Verification included:

- Functional correctness
- Timing correctness
- Waveform inspection

---

## Technologies

- Verilog HDL
- Structural Digital Design
- Icarus Verilog
- GTKWave

---

## Learning Outcomes

- Structural hardware design
- Timing analysis
- Critical path optimization
- Hold-time verification
- High-speed datapath design
- RISC-V ALU architecture
