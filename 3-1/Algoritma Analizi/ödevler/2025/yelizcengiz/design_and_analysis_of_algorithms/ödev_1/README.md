# Hybrid Hashing Algorithm Analysis

This project implements and evaluates a **hybrid hashing algorithm** that combines **linear probing (open addressing)** and **separate chaining** to handle collisions efficiently in large-scale hash tables.

## Overview
The system simulates a large user database inspired by social media workloads, where a small subset of users generates a disproportionate number of accesses.
To reduce clustering in linear probing and memory overhead in separate chaining, a hybrid collision resolution strategy is applied.

The project is implemented in **C** and focuses on empirical performance analysis.

## Hashing Strategy
- Collisions are first resolved using **linear probing**
- If insertion fails after **k probing attempts**, the key is stored using
  **separate chaining** at the original hash index
- This approach balances speed, memory usage, and clustering behavior

## Hash Function and Table Size
- Hash function:

    **h(t) = t mod m**

- Table size `m` is automatically selected as the **nearest prime number to X / 10**
- User IDs are generated in the range **[1, X]**, where **X ≥ 1,000,000**

## Purpose
This project demonstrates hybrid hashing techniques and performance evaluation methods for large-scale data structures, developed as part of an **Algorithm Analysis** course.