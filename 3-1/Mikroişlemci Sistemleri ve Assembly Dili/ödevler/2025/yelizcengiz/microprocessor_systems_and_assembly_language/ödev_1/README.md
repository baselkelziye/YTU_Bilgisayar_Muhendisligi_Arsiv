# Matrix Multiplication (C vs Assembly)

This project implements two-dimensional matrix multiplication using both C and Assembly language.

## Description
Given matrices A and B, the program computes the result matrix C using the standard matrix multiplication formula:

C[i, j] = Σ (A[i, k] × B[k, j]), for k = 0 to n − 1

The multiplication is implemented twice: once in C and once in Assembly. The results from both implementations are printed and compared to verify correctness.

## Provided Files
- **HW1.cpp**
  - Defines matrices A and B and their dimensions
  - Declares `matmul_c` and `matmul_asm` function prototypes
  - Prints result matrices and compares C and Assembly outputs

- **matmul.asm**
  - Contains the Assembly implementation
  - Includes a predefined skeleton for the `matmul_asm` subroutine

## Features
- Two-dimensional matrix multiplication
- Dual implementation in C and Assembly
- Output comparison for correctness verification
- Integration of high-level and low-level programming

## Purpose
This project demonstrates understanding of matrix operations, function interfacing between C and Assembly, and low-level optimization techniques in microprocessor-based systems.
