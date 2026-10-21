#include <stdio.h>

// Utility function to print the current triplet
void printTriplet(int triplet[]) {
    printf("%d %d %d\n", triplet[0], triplet[1], triplet[2]);
}

// Recursive function to form and print triplets
void findTriplets(int arr[], int n, int start, int triplet[], int count) {
    if (count == 3) {  // Base case: triplet is ready to be printed
        printTriplet(triplet);
        return;
    }
    
    for (int i = start; i < n; i++) {
        triplet[count] = arr[i]; // Include the current element in the triplet
        findTriplets(arr, n, i + 1, triplet, count + 1); // Recur for the next element
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Your input array
    int triplet[3]; // Array to store the triplets
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the input array
    
    findTriplets(arr, n, 0, triplet, 0); // Function call to start the process
    
    return 0;
}
