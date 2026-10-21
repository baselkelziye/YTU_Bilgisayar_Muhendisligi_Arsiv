# 8086 Memory Mapping and Address Decoding

This project designs and implements an address decoding circuit for an 8086-based system to map ROM and RAM blocks to specific physical memory addresses.

## Description
An address decoding system is designed using 74LS138 decoders and logic gates to correctly interface ROM and RAM memories with the 8086 microprocessor. The design supports even–odd memory banks and is simulated in the Proteus environment. The correctness of the hardware is verified using Assembly code that performs FAR subroutine calls from ROM and writes data to RAM.

## Hardware Components
- 8086 Microprocessor
- 74273 Octal D-Type Flip-Flops (3 units)
- 74LS138 Decoder (2 units)
- 27C128 EPROM (16KB × 4)
- 62256 SRAM (32KB × 2)

## Memory Map
- **ROM Block (64KB)**  
  - Physical start address: **20000H**  
  - Implemented using four 16KB EPROMs (27C128)

- **RAM Block (64KB)**  
  - Physical start address: **60000H**  
  - Implemented using two 32KB SRAMs (62256)

## Address Decoding
- Chip Select (CS) signals are generated using 74LS138 decoders and logic gates
- Separate address decoding is implemented for even and odd memory banks
- Isolated memory and I/O mapping principles are applied
- Address, data, and control signals are assumed to be properly latched and separated

## ROM Programming
- Binary files **00.bin**, **01.bin**, **10.bin**, and **11.bin** are loaded into EPROMs:
  - ROM00, ROM01, ROM10, ROM11

## Software Verification
- FAR subroutines are located at:
  - **2000H:0000H**
  - **2800H:0002H**
- An Assembly program continuously calls these FAR subroutines inside an infinite loop
- RAM write operations are used to verify correct memory access

## Purpose
This project demonstrates memory mapping, address decoding, even–odd bank organization, and low-level verification techniques for 8086-based microprocessor systems.