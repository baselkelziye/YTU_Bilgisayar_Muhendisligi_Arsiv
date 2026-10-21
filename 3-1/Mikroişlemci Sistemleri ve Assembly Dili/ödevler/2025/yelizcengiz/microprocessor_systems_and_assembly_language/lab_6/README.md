# 8086 USART Communication System

This project implements a transmitter–receiver communication system using the 8251 USART interfaced with an 8086 microprocessor.

## Description
The system is designed using the 8251 Universal Synchronous/Asynchronous Receiver Transmitter (USART) and supports serial data communication between two virtual terminals. Address decoding is performed using external logic components, and all interfacing is handled through the system bus. The application includes data filtering, buffering, and simple encryption before transmission.

## Hardware Components
- 8086 Microprocessor
- 8251 USART
- 74273 Octal D-Type Flip-Flops (3 units)
- 74154 Demultiplexer
- Virtual Terminals (2 units)
- Additional logic gates for address decoding (AND, OR, NOT, etc.)

## Address Decoding
- Isolated I/O addressing using the M/IO signal
- The 8251 USART is mapped starting at address **0158H**, occupying consecutive I/O addresses
- All address decoding connections are implemented via the system bus

## Communication Workflow
1. **Input**  
   Characters are entered through the first virtual terminal.
2. **Receive Loop**  
   The system continuously receives data until the user enters the character `'0'`.
3. **Filtering**  
   Only uppercase letters (A–Z) are accepted as valid input. Digits, symbols, and lowercase letters are ignored.
4. **Buffer Management**  
   Valid characters are stored in a buffer. When `'0'` is received, the most recent three characters are selected for processing.
5. **Encryption**  
   Each valid character is encrypted by adding 3 to its ASCII value (e.g., `'A'` → `'D'`).
6. **Transmission**  
   Encrypted characters are transmitted to the second virtual terminal in the order they were entered.

## Purpose
This project demonstrates serial communication, address decoding, peripheral interfacing with the 8251 USART, and low-level data processing using Assembly language in microprocessor-based systems.
