#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 500000

void quickSort(int * arr, int left, int right, int * counter);
int partition(int * arr, int left, int right, int * counter);
void generateRandomNumbersForArr(int * arr, int size);
void printArray(int * arr, int size);
void swap(int * a, int * b);

int main() {
  //for the random function to work correctly
  srand(time(NULL));
  //variable declarations
  clock_t start, stop;
  double duration;
  int arr[SIZE];
  int * counter;
  int count = 0, n , i ,stars;
  counter = & count; //i used the counter as a pointer to access this variable from other functions

  printf("Enter the size of the input array:");
  scanf("%d", & n);

  //assigning random numbers to an array so that the user doesn't have to enter
  generateRandomNumbersForArr(arr, n);
  printArray(arr,n);

  start = clock(); // cpu beginning time     clock()-->This function returns the number of clock ticks elapsed since the start of the program.

  //calling quicksort with the left value=0 and right value=size-1 
  quickSort(arr, 0, n - 1, counter);

  stop = clock(); // cpu time after the sort algorithm executes

  duration = (double)(stop - start); //elapsed time
  
  stars = duration;

  printf("\nArray after sorted:\n");
  printArray(arr,n);

  printf("\nCPU time for algorithm to run was %.3lf .", duration);

  //writes n and the total number of function calls made
  printf("\nTotal %d function(quicksort+partition) calls.\n", count);
  
  printf("Visual representation of complexity(one star for each CPU time): ");
  // a notation with stars to better visually see the complexity
  for (i = 0; i < stars; i++) {
  	printf("*");
  }

  return 0;
}

void quickSort(int * arr, int left, int right, int * counter) {
  (* counter) ++;

  if (left < right) {

    int pivot = partition(arr, left, right, counter); //returns the correct position of the pivot we selected

    quickSort(arr, left, pivot - 1, counter); //sorts the part before the pivot

    quickSort(arr, pivot + 1, right, counter); //sorts the part after the pivot
  }

}

int partition(int * arr, int left, int right, int * counter) {
  (* counter) ++;

  int j; // right pointer
  int pivot = arr[right]; //i chose the pivot as the last element of the array

  int i = (left - 1); // left pointer

  // traverse each value between left and right and compare with pivot
  for (j = left; j < right; j++) {

    if (arr[j] <= pivot) {

      // if element smaller than pivot is found , swap it with the bigger element pointed by i
      i++;

      // swap element at i with element at j
      swap( & arr[i], & arr[j]);
    }
  }

  swap( & arr[i + 1], & arr[right]); //finally puts the pivot in its proper position

  return i + 1; //index of the pivot
}

void generateRandomNumbersForArr(int * arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    arr[i] = rand() % (size); // generates random numbers up to size
  }

}

//simple swap function using pointers
void swap(int * a, int * b) {
  int tmp = * a;
  * a = * b;
  * b = tmp;
}

void printArray(int * arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}
