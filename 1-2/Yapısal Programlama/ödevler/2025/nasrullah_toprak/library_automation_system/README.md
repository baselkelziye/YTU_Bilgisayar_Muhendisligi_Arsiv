# 📚 Library Automation System (Kütüphane Otomasyonu)

### 🎓 Course: BLM1031 - Structural Programming (Yapısal Programlama)
### 🧑‍💻 Project Type: Term Project

---

## 📖 Project Overview

This project implements a **Library Automation System** that mimics the logic of relational databases using **C programming**, **CSV-based file storage**, and **linked list data structures**.  
All data (authors, books, students, borrow records, etc.) are stored persistently in CSV files while being dynamically managed in memory through **singly and doubly linked lists**.

---

## ⚙️ Functional Requirements

👩‍🏫 Author Operations

🎓 Student Operations

📚 Book Operations

✍️ Book–Author Relationship

📘 Borrowing and Returning Books

---

## 🧩 Program Menus

### 🧑‍🎓 Student Menu
1. Add / Delete / Update Student  
2. Display Student Info (by ID or Name)  
3. List Students with Unreturned Books  
4. List Penalized Students  
5. List All Students  
6. Borrow / Return Books  

### 📖 Book Menu
7. Add / Delete / Update Books  
8. Display Book Info and Copies  
9. List Books on Shelf  
10. List Overdue Books  
11. Assign Authors to Books  
12. Update Book’s Author  

### ✍️ Author Menu
13. Add / Delete / Update Authors  
14. Display Author Info and Their Books

15. Exit & End

---

## 📁 File Structure

| File Name | Description |
|------------|-------------|
| `main.c` | Entry point and main menu control; Functions for author, student, and book management in addition to book–author relationships |
| `Yazarlar.csv` | Stores all author records |
| `Ogrenciler.csv` | Stores student records |
| `Kitaplar.csv` | Stores main book records |
| `KitapOrnekleri.csv` | Stores each copy of books related to Kitaplar.csv |
| `KitapYazar.csv` | Book–author relationships |
| `OduncIslemleri.csv` | Borrow-return transaction log |

---
