# Recursive Binary Search

This program implements a recursive binary search algorithm to find the index of a given key in a sorted array of natural numbers.

## Description
The program first verifies whether the input array is sorted in ascending order. If the array is sorted, a recursive binary search is performed to determine the index of the specified key. All parameters are passed through the stack, and return values are handled via the stack as well.

## Subroutines
- **IS_SORTED**  
  Checks whether the array is sorted in ascending order.  
  Parameters: array base address, number of elements (passed via stack)

- **BINARY_SEARCH**  
  Recursive binary search subroutine.  
  Parameters: array base address, low index, high index, key (passed via stack)

## Features
- Validates array order before searching
- Recursive binary search implementation
- Stack-based parameter passing
- Stack-based return value handling
