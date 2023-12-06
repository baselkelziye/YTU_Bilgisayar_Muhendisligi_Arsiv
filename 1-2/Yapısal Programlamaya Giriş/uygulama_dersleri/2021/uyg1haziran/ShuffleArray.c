#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
// A utility function to swap to integers 
void swap (int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
// A utility function to print an array 
void printArray (int arr[], int n) 
{ 
	int i;
    for ( i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
// A function to generate a random permutation of arr[] 
void randomize ( int arr[], int n ) 
{ 	
	int i;
  
    // Start from the last element and swap one by one. 
    for ( i = n-1; i > 0; i--) 
    { 
        // Pick a random index from 0 to i 
        int j = rand() % (i+1); 
  
        // Swap arr[i] with the element at random index 
        swap(&arr[i], &arr[j]); 
    } 
} 
  
// Driver program to test above function. 
int main() 
{ 
	int arr[20],n,i;
	printf("dizinin eleman sayisi:\n");
	scanf("%d",&n);
	
	srand ( time(NULL) );  // hep ayný dizi üretilmesin
	
	//printf("dizinin elemanlarini veriniz:\n");
	//for (i=0;i<n;i++)
	//	scanf("%d",&arr[i]);
	for (i=0;i<n;i++)
		arr[i]=rand() % 100; 
	printArray(arr, n); 
    randomize (arr, n); 
    printArray(arr, n); 
  
    return 0; 
} 
