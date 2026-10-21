#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void printArray(int *arr, int N, int k);
void merge(int *arr, int left,int *m, int right, int counter, int k, int N);
int* mergeTwoArrays(int *arr1, int *arr2, int N, int M);
void selectionSort(int *arr, int n);
void mergeSort(int *arr, int left, int right, int counter, int k, int N);
int isSorted(int *arr, int N);
void swap(int *a, int *b);
int* copyArray(int* source, int n);
void shuffle(int *arr, int n);

int main(int argc, char *argv[]) {
    
    int i, j, N; // index, to be initiated element amount
    int A[6]= {100, 1000, 10000, 100000, 1000000, 10000000}; // arraylength values that be analyzed
    int k = 10; // k-th way merge
    srand(time(NULL)); // provides randomizing each time
    int *dest; // destination of copied array
    int *arr = NULL; 

    for(i = 0; i < 6; i++)
    {
        N = A[i];
        arr = (int*)malloc(N * sizeof(int));
        for(j=0; j<N; j++)
        {
            arr[j] = j+1; // creating an array sorted 1 to N
        }
        int tmp;
        shuffle(arr, N);// shuffling array
        printf("N: %d----\n", N);
        for(j = 2 ; j <= k; j++) // k-th way merge sort
        {
            dest= copyArray(arr, N); // copying array to avoid sorting a sorted array
            // printArray(dest, N, k);
            clock_t t; 
            t = clock();  
            mergeSort(dest, 0, N-1, 0, j, N);
            t = clock() - t; 
            double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 

            // printArray(arr, N, i);
            printf("k=%d took %.3f seconds to execute--", j, time_taken);
            if(isSorted(dest, N) == 1) printf("Succesfully sorted.\n"); // determining sorted or not
            else printf("Not sorted."); 
            free(dest);
        }
        free(arr);
    }

    return 0;
}
/*
@brief a function that shuffles the given array

@param arr the array to be shuffled
@param n array length

@return
*/
void shuffle(int *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Random index from 0 to i
        swap(&arr[i], &arr[j]);
    }
}
/*
@brief a function that swaps the given variables

@param *a, *b the variables to be swapped

@return
*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
@brief a function that controls the given array is sorted.

@param arr the array to be controlled
@param N array length

@return
*/
int isSorted(int *arr, int N)
{
    int i;
    for(i=1; i<N+1; i++)
    {
        if(arr[i-1] != i) return 0;
    }
    return 1;
}
/*
@brief a function that copies the given array into destination array

@param source the array to be copied
@param n array length

@return destination the array which been copied
*/
int* copyArray(int* source, int n) {
    int* destination = (int*)malloc(n * sizeof(int)); // Allocating a new array
    if (destination == NULL) {
        printf("Memory allocation failed!\n");
        return NULL; 
    }
    for (int i = 0; i < n; i++) {
        destination[i] = source[i]; // assign every element one by one
    }

    return destination; // returning copied array
}
/*
@brief a function that merges the sorted diversed subarrays

@param arr the array that will hold the merged result of the sorted subarrays.
@param left left index of arr
@param *m partition points
@param right right index of arr
@param counter the counter that determines the time of sorting of subarrays which has (k-1 elements)
@param k k-th way
@param N array length

@return
*/
void merge(int *arr, int left,int *m, int right, int counter, int k, int N)
{
    int i, j; // iterator for for loop
    int **subArray = (int**)malloc(sizeof(int*) * k); // allocating for k different subarrays
    int *n = (int*)malloc(sizeof(int) * k); // allocating for k different subarray's length
    n[0] = m[0] - left + 1; // subarray[0]'s array length. the difference is about index starting.
    for(i=1 ; i <= k-2; i++)
    {
        n[i] = m[i] - m[i-1]; // subarray[i]'s array length.
    }
    n[k-1] = right - m[k-2]; // subarray[k-1]'s array length
    
    for(i=0 ; i<k ; i ++)
    {
        subArray[i] = (int*)malloc(n[i]* sizeof(int)); // allocating for each subarray
    }
    for(i = 0; i < n[0]; i++)
    {
        subArray[0][i] = arr[left + i]; // initiating 0th subarray
    }
    for(i = 1; i < k ; i++)
    {
        int a = i-1;
        for (j = 0; j < n[i]; j++)
        {
            subArray[i][j] = arr[m[a] + 1 + j]; // initiating i'th subarray
        }  
    }
    int lastStep = log(N)/log(k); // initiating last step to sort that subarray.len < (k-1) arrays
    if(counter == lastStep) // means there is no more subarrays to divide then sort them.
    {
        for(i = 0; i < k ; i++)
        {
            selectionSort(subArray[i], n[i]);
            // mergeSort(subArray[i],0, n[i]-1, counter, 2, N); // 2nd way Merge Sort for small subarrays, doesnt work efficiently now.
        }
    }
    int *tmpArr = mergeTwoArrays(subArray[0], subArray[1], n[0], n[1]); // insertion two sorted arrays into one sorted array
    int tmpSize = n[0] + n[1]; // defining tmpArr's length
    for(i=2 ; i<k ; i++)
    {
        tmpArr = mergeTwoArrays(tmpArr, subArray[i], tmpSize, n[i]); // insertion two sorted arrays into one sorted array
        tmpSize += n[i]; // increase the tmparr's length by given subarray's length
    }
    // a sorted array(tmpArr) for stated part of arr is created 
    for(i=0 ; i<tmpSize ; i++)
    {
        arr[left + i] = tmpArr[i]; // transfer the sorted values from tmpArr to arr for stated part
    }
}
/*
@brief a function that merges sorted arrays into sorted array

@param arr1 sorted array
@param arr2 sorted array
@param N array length of arr1
@param M array length of arr2

@return the merged sorted array
*/
int* mergeTwoArrays(int *arr1, int *arr2, int N, int M)
{
    int i,j,k;
    int *arr = (int*)malloc((M+N) * sizeof(int));
    
    i = 0;
    j = 0;
    k = 0;
    while (i < N && j < M) { // while the array sizes are not exceeded, copy the values one by one into new array one by one 
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of arr1[],
    // if there are any
    while (i < N) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    // Copy the remaining elements of arr2[],
    // if there are any
    while (j < M) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
    return arr;

}
/*
@brief A function that first recursively divides an array into subarrays, 
each containing at most k - 1 elements.
Then, it merges them in sorted order until the stack is empty.

@param arr an array to be divided into subarrays
@param left left index of subarray
@param right right index of subarray
@param counter to be passed it into merge() function
@param k to be passed it into merge() function
@param N to be passed it into merge() function

@return
*/
void mergeSort(int *arr, int left, int right, int counter, int k, int N)
{
    int i;
    if (right > left){ // determining for a subarray has at most (k-1) or not 
        
        int *m = (int*)malloc((k-1) * sizeof(int)); // partition point number of given array
        for(i=0 ; i < k-1 ; i++)
        {   // calculating partition points and preventing float to int convertings
            m[i] = ((right - left) * (i+1));
            m[i] = m[i]/k;
            m[i] = left + m[i]; // partition position of m[i] to be used in mergeSort
        }
        mergeSort(arr, left, m[0], counter+1, k, N); 
        for(i=0; i<k-2; i++)
        {
            //mergeSort(arr, left, right , counter, k , N); m[i]+1 = left m[i+1] = right
            mergeSort(arr, m[i] + 1, m[i+1], counter+1, k, N);
        }
        mergeSort(arr, m[k-2] + 1, right, counter+1, k, N);
        merge(arr, left, m, right, counter+1, k, N); // merging k different subarray

        
    }  
}

/*
@brief a function that sorts the given array

@param arr array that contains the values to be sorted
@param n array length

@return
*/
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
      
        // Assume the current position holds
        // the minimum element
        int min_idx = i;
        
        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
              
                // Update min_idx if a smaller element is found
                min_idx = j;
            }
        }
        // Move minimum element to its
        // correct position
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
/*
@brief a function that prints the array

@param arr the array that to be printed 
@param N array length
@param k states the which way of merging (k-th way merge)

@return
*/
void printArray(int *arr, int N, int k)
{
    int i;
    printf("\nfor k= %d -> ",k );
    for(i=0; i<N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

