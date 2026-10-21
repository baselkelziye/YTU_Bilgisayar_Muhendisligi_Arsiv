# 🎮 YTU-BBG Final Project — Terminal Matrix Match & Pop Game

**Yıldız Technical University — Introduction to Computer Science (BBG) Final Project**  
A terminal-based matrix match-and-pop game written in C.

---

## 📖 About

This project is a console-based puzzle game where the player manipulates a grid filled with symbols. The goal is to **swap elements** within the same row or **detonate** matching sequences of 3 or more adjacent symbols — either horizontally or vertically — to clear the board before elements reach the top row.

The game features two modes: a fully automated **Game Mode** with a randomly generated board, and a **Control Mode** for manually entering a custom board for testing purposes.

---

## 🕹️ Gameplay

### Symbols
The board is filled with 5 different symbols:

| Symbol | Meaning |
|--------|---------|
| `*`    | Star    |
| `/`    | Slash   |
| `+`    | Plus    |
| `%`    | Percent |
| `O`    | Circle  |

### Win / Lose Condition
- The game **ends** when any element reaches the **top row** of the board.
- The player aims to detonate as many elements as possible before that happens.

---

## ⚙️ How to Compile & Run

### Requirements
- A C compiler (GCC recommended)
- A terminal that supports ANSI escape codes (Linux, macOS, or Windows Terminal)

### Compilation
```bash
gcc ics_project.c -o ics_project
```

### Run
```bash
./ics_project
```

---

## 🗂️ Game Modes

### 1. Game Mode
- The board is **randomly generated** using a custom LCG (Linear Congruential Generator) seeded with the current time.
- Only the **bottom half** of the board is filled at the start.
- The terminal screen is cleared between turns for a clean display.

### 2. Control Mode
- The player **manually inputs** the starting board configuration symbol by symbol.
- Useful for testing specific scenarios.

---

## 🎯 Actions

### Move 1 — Relocation (Swap)
- Swap two elements that are **on the same row**.
- After the swap, all rows **shift down by one** and a new random row is generated at the bottom.
- Input format:
  ```
  x1, y1
  x2, y2
  ```

### Move 2 — Detonation (Explode)
- Select a cell to attempt a chain detonation.
- The game checks for **3 or more consecutive identical symbols** in the same row or column starting from that cell.
- If valid, those cells are **cleared (set to null)** and the column/row collapses downward.
- If fewer than 3 matches are found, the move is rejected as invalid.
- Input format:
  ```
  x1, y1
  ```

---

## 📊 Stats Tracked

| Stat | Description |
|------|-------------|
| **Total Displacement** | Number of successful swap moves |
| **Total Elements Exploded** | Total symbols removed via detonation |

---

## 🔧 Technical Details

- **Language:** C (standard C)
- **Board Size:** User-defined at runtime (up to 20×20)
- **RNG:** Custom Linear Congruential Generator (`seed = (1103515245 * seed + 12345) % 2147483648`)
- **Screen Clearing:** ANSI escape code `\033[H\033[J` (Game Mode only)
- **No external libraries** — only `<stdio.h>` and `<time.h>`

---

## 📁 File Structure

```
YTU-bbg_finish_project/
├── ics_project.c   # Full source code (single file)
├── README.md       # This file
└── .gitignore
```

---

## 👤 Author

**Abdullah Yaren**  
Computer Engineering Student — Yıldız Technical University

---

## 📄 License

This project was developed for educational purposes as part of the BBG (Introduction to Computer Science - Bilgisayar Bilimlerine Giris) course at Yıldız Technical University.
