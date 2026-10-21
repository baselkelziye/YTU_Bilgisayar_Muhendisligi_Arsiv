# 🎮 Triversi Game in C

A console-based **Triversi** (3-player Reversi/Othello variant) game implemented in **C language**.  
Three players (Red, Yellow, and Blue) compete on a square board, flipping each other’s pieces to dominate the board.

---

## 🧠 Game Description

- **Player 1:** Red (`K` *Kırmızı*)
- **Player 2:** Yellow (`S` *Sarı*)
- **Player 3:** Blue (`M` *Mavi*)

The players take turns placing their colored pieces on the board.  
Whenever a player encloses opponent pieces between two of their own, the enclosed pieces flip to their color — just like in **Reversi**, but with **three colors**!

---

## ⚙️ Features

✅ 3-player mode (Red, Yellow, Blue)  
✅ Dynamic board size (from 3×3 up to 23×23)  
✅ Valid move checking  
✅ Automatic color flipping in 8 directions  
✅ Final score and winner detection  

---

## 🖥️ How to Compile and Run

You can compile the program using **GCC** or any C compiler.

```bash
gcc triversi.c -o triversi
./triversi

