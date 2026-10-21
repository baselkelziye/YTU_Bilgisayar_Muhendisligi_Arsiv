#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// algorithm that shuffles the created array

void printArray(int n, int arr[]) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

void randomize(int n, int arr[]) {
  int x, temp, i;
  for (i = 0; i < n; i++) {
    x = rand() % n;
    temp = arr[i];
    arr[i] = arr[x];
    arr[x] = temp;
  }
}

int main() {
  int arr[SIZE], n, i;
  printf("SHUFFLING ARRAY ELEMENTS");
  printf("\nNumber of array elements: ");
  scanf("%d", &n);

  // create random array elements
  srand(time(NULL));
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }

  printf("\n");
  printArray(n, arr); // print
  randomize(n, arr);  // shuffle
  printf("\n");
  printArray(n, arr); // print again

  return 0;
}
