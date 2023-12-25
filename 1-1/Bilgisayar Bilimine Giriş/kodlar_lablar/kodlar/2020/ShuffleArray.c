// C Program to shuffle a given array 
  
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
	int i,j,k;
	int num1,num2;
    // Use a different seed value so that we don't get same 
    // result each time we run this program 
    srand ( time(NULL) ); 
  
    for ( i = 0; i < n; i++) 
    { 
        // Pick two random indices from 0 to n-1 
        j = rand() % n; 
        k = rand() % n; 
        // Swap arr[j] with arr[k] 
       swap(&arr[j], &arr[k]); 
    } 
} 
  
// Driver program to test above function. 
int main() 
{ 
	int arr[20], n,i;
	printf("dizinin eleman sayisi:\n");
	scanf("%d",&n);
	printf("dizinin elemanlarini veriniz:\n");

	for (i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printArray(arr, n); 
    randomize (arr, n); 
    printArray(arr, n); 
  
    return 0; 
} 
