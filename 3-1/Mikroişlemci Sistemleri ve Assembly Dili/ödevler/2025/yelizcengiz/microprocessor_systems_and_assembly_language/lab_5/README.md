# Keypad Controlled 7-Segment Display

This experiment implements a keypad-controlled 7-segment display system using the 8086 microprocessor.

## Description
An input unit consisting of 8 push buttons is interfaced with an 8086 microprocessor using a 74HC373 latch and an 8255 Programmable Peripheral Interface (PPI). Each button corresponds to a unique digit (0–7) or a user-defined symbol, which is displayed on a common-anode 7-segment display.

Button inputs are read from Port B of the 8255, and the corresponding 7-segment codes are sent to the display via Port A.

## Hardware Components
- 8086 Microprocessor
- 74HC373 Latch
- 8255 Programmable Peripheral Interface (PPI)
- Common-Anode 7-Segment Display
- 8 Push Buttons
- Current-limiting resistors for the 7-segment display
- Pull-up or pull-down resistors for button inputs
- Clock source, reset circuit, and power connections

## Implementation Details
- Button states are read from Port B
- 7-segment display data is written to Port A
- Each button triggers a distinct digit or symbol on the display
- Circuit design and simulation are performed using Proteus

## Purpose
This project demonstrates microprocessor-based I/O interfacing, peripheral control using the 8255 PPI, and hardware–software integration in embedded systems.