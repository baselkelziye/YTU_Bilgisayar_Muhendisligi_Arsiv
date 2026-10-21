# Backtracking Based Server Placement

This project solves a constrained **server placement problem** in a data center using a **backtracking algorithm**. The goal is to assign `N` servers to `M` racks while satisfying power, thermal efficiency, and security constraints.

The solution is implemented in **C** and demonstrates systematic search and constraint checking using backtracking.

---

## Constraints

### 1. Capacity Constraint
Each rack has a maximum power capacity `C`:

    Σ P(servers in rack) ≤ C

---

### 2. Thermal Efficiency Constraint
For each rack, the ratio of total heat generation to total power consumption
must not exceed the cooling efficiency threshold `K`:

    (Σ H(servers in rack)) / (Σ P(servers in rack)) ≤ K
    
---

### 3. Conflict Constraint
Certain server pairs `(Si, Sj)` cannot be placed in the same rack due to
security restrictions.

---

## Solution Approach

A **backtracking-based algorithm** assigns servers to racks while dynamically managing active racks.

- Servers are placed **one by one**.
- For each server, all **active racks** are checked against:
  - Power capacity constraint
  - Conflict constraint
- If the server cannot be placed in any active rack, a **new rack is opened** (if available) and the active rack count is updated.
- Once placed, the algorithm proceeds to the **next server**.

After all servers are placed:
- The **thermal efficiency constraint** is checked for each rack.
- If the constraint is satisfied, a valid solution is found.
- Otherwise, the algorithm **backtracks**, undoing placements step by step and exploring alternative assignments.

---

## Technologies and Concepts

- Language: C  
- Algorithm: Backtracking  
- Concepts:
  - Constraint Satisfaction Problems (CSP)
  - Search Space Pruning
  - Algorithm Analysis

---

## Purpose

This project was developed as part of an **Algorithm Analysis** course to demonstrate backtracking techniques for solving real-world constrained optimization problems.
