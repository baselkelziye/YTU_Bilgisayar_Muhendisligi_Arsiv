# RISC-V Assembly Programming and Cycle Analysis for Bit Counting

## Overview

This project implements a RISC-V assembly program that analyzes a 20-element array of 32-bit integers and counts the number of set bits located only at even bit positions.

The generated assembly code was translated into machine code and executed on a custom single-cycle RISC-V processor developed in previous projects.

---

## Problem Description

Given a 32-bit value:

Count only the bits located at:

0, 2, 4, 6, ..., 30

and store the resulting count into a corresponding output array.

Example:

Input:

0xFFFFFFFF

Output:

16

since all sixteen even-position bits are set.

---

## Algorithm

For each array element:

1. Load value from memory
2. Initialize counter
3. Create a mask for even positions
4. Check all 16 even-position bits
5. Increment counter when bit equals 1
6. Store result in COUNT array
7. Continue with next element

---

## Processor Integration

The program was executed on a single-cycle RISC-V processor.

Components involved:

- Instruction Memory
- Data Memory
- Register File
- ALU
- Control Unit

---

## Performance Analysis

Cycle counts were calculated for:

- Every individual array element
- Entire array execution

Special analysis was performed for:

- 0xFFFFFFFF
- 0x80000000
- 0xC7B52169

These values were used to validate:

- Correct functionality
- Execution timing
- Processor behavior

---

## Verification

Verification methods:

### Assembly Verification

- Instruction-by-instruction debugging
- Expected output comparison

### Waveform Verification

Using GTKWave:

- Register values
- Memory contents
- COUNT array outputs
- Cycle measurements

### Machine Code Validation

Assembly instructions were translated into machine code and successfully executed on the processor.

---

## Technologies

- RISC-V Assembly
- Verilog HDL
- Single-Cycle Processor Design
- GTKWave
- Icarus Verilog

---

## Learning Outcomes

- RISC-V assembly programming
- Machine code generation
- Processor execution analysis
- Cycle counting
- Performance evaluation
- Hardware-software interaction
