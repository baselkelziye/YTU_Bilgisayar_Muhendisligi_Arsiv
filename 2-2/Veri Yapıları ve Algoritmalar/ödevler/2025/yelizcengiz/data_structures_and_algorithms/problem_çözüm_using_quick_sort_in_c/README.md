# Lock & Key Matching (Nuts & Bolts Problem)

This project implements a **Divide and Conquer** algorithm to match $N$ locks with $N$ keys with an average time complexity of **$O(N \log N)$**.

## Problem Statement

We are given $N$ distinct locks and $N$ distinct keys. The goal is to find the correct matching key for every lock.

**Constraints:**
- You **cannot** compare a key with another key.
- You **cannot** compare a lock with another lock.
- You can only compare a **key** against a **lock**.
- The comparison yields one of three results: *Too Small*, *Fits*, or *Too Large*.

## Algorithm Logic

The solution utilizes a **Randomized QuickSort** approach. Since we cannot compare elements within the same array, we use the two arrays (Locks and Keys) to partition each other.

The process is as follows:

1. **Pick a Pivot Key:** Select a random key from the `Keys` array.
2. **Partition Locks:** Use the selected key to partition the `Locks` array into three sets:
   - Locks smaller than the key.
   - The lock that fits the key (The Pivot Lock).
   - Locks larger than the key.
3. **Partition Keys:** Use the found **Pivot Lock** to partition the `Keys` array into three sets:
   - Keys smaller than the lock.
   - The key that fits the lock (The original Pivot Key).
   - Keys larger than the lock.
4. **Recurse:** Recursively apply the same logic to the "Smaller" and "Larger" subarrays for both locks and keys.

## Complexity Analysis

- **Average Time Complexity:** $O(N \log N)$
- **Worst Case Time Complexity:** $O(N^2)$ 
- **Space Complexity:** $O(\log N)$ 
