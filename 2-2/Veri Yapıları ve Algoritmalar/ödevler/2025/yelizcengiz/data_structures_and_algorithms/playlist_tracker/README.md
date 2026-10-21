## 📖 Overview

This project is a C-based backend simulation that models the interaction between users and a music library. It is designed to simulate a streaming service environment where users create playlists, listen to songs, and generate data that the system analyzes.

The core focus of this project is **memory optimization** and **dynamic data management**. It utilizes complex pointer arithmetic and custom algorithms to track listening habits and generate real-time "Top 10" charts for both individual users and the global platform.

## 🚀 Key Features

* **Dynamic Data Structures:** Implemented using Doubly Circular Linked Lists for song management and Singly Linked Lists for user management.
* **User Simulation:** Automatically generates $N$ users and assigns them random playlists from a global song pool.
* **Listening Behavior Model:** Simulates users listening to songs, dynamically updating play counts in real-time.
* **Algorithmic Sorting:** Features a custom "bubble-up" sorting algorithm that reorders Linked List nodes instantly as play counts increase, maintaining an always-sorted "Top 10" list without requiring a full re-sort.
* **Memory Management:** Robust system architecture ensuring all dynamically allocated memory (users, songs, names) is properly freed upon termination.