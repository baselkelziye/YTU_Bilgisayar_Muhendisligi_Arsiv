# ADC–DAC Based Motor Speed Control

This project implements a sensor-based motor speed control system using ADC0804 and DAC0830 devices interfaced with an 8086 microprocessor.

## Description
The system reads analog sensor data from an LDR using the ADC0804, processes the digital output, and generates an analog control signal through the DAC0830 to control motor speed. The motor speed dynamically changes based on the distance of a light source from the LDR.

## Address Mapping
- **DAC0830** is mapped to I/O address **200H**
- **ADC0804** data port is mapped to I/O address **400H**
- **ADC0804 INTR** signal is mapped to I/O address **800H**
  - The INTR signal is passed through a tri-state buffer and connected to the **D7** data line

## ADC Operation
- ADC conversion completion is detected by monitoring the **D7 bit**
- The system continuously polls the D7 bit until it becomes `0`
- The ADC result is read only when D7 = `0`
- No delay-based waiting is used; conversion completion is detected via hardware status polling

## Circuit Implementation
- Motor system and sensor system blocks are completed using proper signal labeling
- Missing connections and labels in other parts of the circuit are identified and completed
- Voltage levels applied to motors can be monitored using voltmeters connected to motor terminals

## System Behavior
- As the light source approaches the LDR, motor speed increases and both motors rotate in the same direction
- When the light source is closest to the LDR, motors run at maximum speed
- As the light source moves away, motor speed decreases
- When the light source is farthest from the LDR, motors stop completely

## Signal Mapping
- ADC0804 output range is properly mapped to the DAC0830 input range
- Motor speed varies proportionally with the light intensity sensed by the LDR

## Purpose
This project demonstrates analog-to-digital and digital-to-analog conversion, hardware polling using status bits, and real-time motor control in microprocessor-based embedded systems.
