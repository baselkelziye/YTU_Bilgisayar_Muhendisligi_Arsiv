//
//  main.c
//  locksandkeys
//
//  Created by Sena ALAY on 7.11.2023.
//

/*
@brief This program solves the "Locks and Keys" problem where there is an array of locks and an array of keys.
       Each lock can only be opened by one key and each key can only open one lock. The goal is to match each
       lock to its key. The program uses a variant of the quicksort algorithm to recursively partition and match
       the keys and locks based on a randomly chosen pivot. The user is prompted to input the number of locks
       and keys, followed by the respective values. The program then proceeds to find the matching pairs and
       outputs them to the user. My program uses random pivoting, partitioning, and recursive sorting
       techniques.

       this program include:
       - getting user input for the number of keys and locks and their values
       - matching keys and locks using a quicksort-inspired approach
       - recursively partitioning and sorting subarrays to find the correct matches
       - swapping elements to assist in partitioning
       - dynamically allocating and freeing memory for the keys and locks

       at the end of the program, the user receives a printed list of matched keys and locks.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function prototypes, they are explained in detailed below
void matchKeysAndLocks(int keys[], int locks[], int low, int high);
int makePartition(int arr[], int low, int high, int pivot);
void getInputFromUser(int *N, int **keys, int **locks);
void makeSwap(int *a, int *b); // Swap function

/*
@brief The main function where the program starts execution.
@return returns an integer that indicates the exit status of the program, to say the program ended succesfully or not
*/
int main() {
    int N; //number of elements in keys and locks arrays
    int i; //index
    int *keys, *locks; //pointers for the keys and locks arrays

    getInputFromUser(&N, &keys, &locks);

    // random number generator
    srand(time(NULL));

    matchKeysAndLocks(keys, locks, 0, N - 1);

    printf("Matched keys and locks are:\n");
    for ( i = 0; i < N; i++)
        printf("Key: %d, Lock: %d\n", keys[i], locks[i]);

    // Free dynamically allocated memory
    free(keys);
    free(locks);

    return 0;
}

/*
@brief this function gets input from the user for the number of keys and locks and their respective values, then allocates memory for both of the arrays.
@param N -> is a pointer to the variable that will hold the number of keys and locks
@param keys -> a double pointer to the array of keys for making the allocation
@param locks -> a double pointer to the array of locks for making the allocation
 @return
*/
void getInputFromUser(int *N, int **keys, int **locks) {
    printf("Enter the number of keys and locks (N): ");
    scanf("%d", N);
    int i;
    *keys = (int *)malloc(sizeof(int) * (*N));
    *locks = (int *)malloc(sizeof(int) * (*N));

    printf("Enter the keys and locks (one at a time):\n");
    for (i = 0; i < *N; i++) {
        printf("Enter the key for lock %d: ", i + 1);
        scanf("%d", &(*keys)[i]);
    }

    for (i = 0; i < *N; i++) {
        printf("Enter the lock for key %d: ", i + 1);
        scanf("%d", &(*locks)[i]);
    }
}

/*
@brief in this function i make the match for keys and locks by recursively partitioning and matching all the subarrays.
@param keys[] -> the array of keys to be matched with locks
@param locks[] -> the array of locks to be matched with keys
@param low -> the starting index for the matching
@param high -> the ending index for the matching
 @return
*/
void matchKeysAndLocks(int keys[], int locks[], int low, int high) {
    if (low < high) {
        // Choose a random pivot index
        int randomPivotIndex = rand() % (high - low + 1) + low;
        int pivot = keys[randomPivotIndex]; // Use key as the pivot

        // Partition the locks based on the pivot key
        int pivotIndex = makePartition(locks, low, high, pivot);

        // Partition the keys based on the pivot lock
        makePartition(keys, low, high, locks[pivotIndex]);

        // Recur for [low..pivotIndex-1] and [pivotIndex+1..high] for keys and locks array.
        matchKeysAndLocks(keys, locks, low, pivotIndex - 1);
        matchKeysAndLocks(keys, locks, pivotIndex + 1, high);
    }
}

/*
@brief this function partitions an array around a pivot so that all lesser elements are on the left side of the pivot element, and all greater elements are on the right side of the pivot element.
@param arr[] -> the array to be partitioned
@param low -> the starting index for the partitioning
@param high -> the ending index for the partitioning
@param pivot -> the value of the pivot element
@return the final index position of the pivot element
*/
int makePartition(int arr[], int low, int high, int pivot) {
    // 'i' will be used to keep track of the "boundary" between elements less than the pivot and elements not yet checked
    int i = low;
    int j;

    // Iterate over the array, but not including the last element, which is assumed to be the pivot
    for (j = low; j < high; j++) {
        // If the current element is less than the pivot, swap it with the element at index 'i'
        if (arr[j] < pivot) {
            makeSwap(&arr[i], &arr[j]);
            i++; // increment 'i' to expand the region of elements less than the pivot
        }
        // If an element equal to the pivot is found, swap it to the end of the array to get it out of the way
        else if (arr[j] == pivot) {
            makeSwap(&arr[j], &arr[high]);
            j--; // decrement 'j' because the element at 'arr[high]' hasn't been checked yet
        }
    }
    // Once all elements have been partitioned, swap the pivot (from the end of the array) to its correct position at index 'i'
    makeSwap(&arr[i], &arr[high]);

    // Return the index 'i', which is the final position of the pivot
    return i;
}


/*
@brief this function swaps the values of two integers.
@param a a pointer to the first integer to be swapped
@param b a pointer to the second integer to be swapped
@return
*/
void makeSwap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
