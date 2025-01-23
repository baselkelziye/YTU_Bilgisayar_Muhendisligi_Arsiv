#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printArray(int* arr, int N);
int* generateRandomArray(int N);
void kWayMergeSort(int* arr, int left, int right, int k);
void merge(int* arr, int left, int mid, int right);
void swap(int* arr, int a, int b);

int main() {
	int N;
	int  k,i;
    // Getting input N from user.
    printf("Welcome, please enter the number of elements: ");
    scanf("%d", &N);

    struct timespec start, end;
    double workingTime;
    
    int* array =  (int*) calloc(N,sizeof(int));
    int * backupArray =  generateRandomArray(N);//Getting a copy of array to protect the original array before sorting.
    
 	// The array is printed before and after the sorting process to verify the correctness of the sorting. 
	// To optimize performance working with large values of N, print statements are commented out.
    
	//printf("Original array created:\n"); 
    //printArray(backupArray, N);
    
    
    for(k=2;k<=10;k++){
    	memcpy( array,backupArray, sizeof(int) * N);
    	printf("\nOriginal array restored. Starting timer now for k = %d\n", k);
    	//printArray(array, N);
    	clock_gettime(CLOCK_MONOTONIC, &start); //Start clock to measure the time for sort.
    	kWayMergeSort(array, 0, N - 1, k);
		clock_gettime(CLOCK_MONOTONIC, &end); //Stop clock to measure the time for sort.
    	printf("Sorting complated, timer is stopping now.\n");
    	
		workingTime =(end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0; //Calculate elapsed time
		
		printf("Sorting took for k = %d: %f miliseconds.",k, workingTime);
		printf("\n-------------------------------------\n");
	}
   
   	//printf("After sort process: \n");
	//printArray(array, N);

	
	free(array);
	
    return 0;
}



/**
 * @brief Generates an array of unique random integers from 1 to N. To create an unique array, first creates an ordered array of integers from 1 to N. 
 * Then, it performs random swaps on elements within the array to shuffle them, ensuring all elements are unique and fall within the range [1, N].
 * 
 * @param N The number of elements in the array.
 * @return A pointer to the generated array containing N unique random integers.
 */
 
int* generateRandomArray(int N){
    int* array; // Array to sort
    srand(time(NULL));
    int i, temp;

    array = (int*) calloc(N, sizeof(int));

    // This method of generating a unique array was found to be problematic at high values of N, 
    // where finding unused elements becomes difficult due to high density of occupied values.
    // Note for report: Mention this inefficiency.

    /* The following block is an alternative approach, currently commented out.
       It uses an auxiliary array (isExist) to check for uniqueness but may be inefficient for large N.

    short* isExist = (short*) calloc(N, sizeof(short));
    for(i = 0; i < N; i++){
        temp = (rand() % N) + 1;
        if(isExist[temp] == 0){
            array[i] = temp;
            isExist[temp] = 1;
        } else {
            i--;
        }
    }
    free(isExist);
    */

    // Fill the array sequentially with numbers from 1 to N to achieve uniqueness
    for(i = 1; i <= N; i++){
        array[i - 1] = i;
    }

    // Randomly swap elements to shuffle the array to generate a mixed array
    for(i = 0; i < N / 2; i++){
        temp = (rand() % N); // Choose a random index to swap
        swap(array, i, temp); // Swap
    }

    return array; // Return randomized array
}


/**
 * Swaps two elements in an array.
 *
 * 
 * @param arr The array containing the elements to be swapped.
 * @param a The index of the first element.
 * @param b The index of the second element.
 */
void swap(int* arr, int a, int b) {
    int temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


/**
 * Prints all elements of an array.
 * 
 * @param arr The array to be printed.
 * @param N The number of elements in the array.
 */
void printArray(int* arr, int N) {
    int i;
    for (i = 0; i < N; i++) {
    	 printf("%d ", arr[i]);	
		
       
    }
    printf("\n");
}


/**
 * Merges two sorted arrays into a single sorted array.
 * 
 * This function is used in the merge phase of the merge sort algorithm to combine
 * two sorted arrays into a single sorted array.
 * 
 * @param arr The array containing the subarrays to be merged.
 * @param left The starting index of the first sorted part.
 * @param mid The ending index of the first sorted part; `mid + 1` is the start of the second.
 * @param right The ending index of the second sorted part.
 */
void merge(int* arr, int left, int mid, int right) {
    int i, j;

    // Calculate the sizes of the two subarrays to be merged
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Dynamically allocate memory for temporary arrays to hold left and right parts
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Copy data into temporary arrays for the left and right arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Initial indexes for left (i), right (j), and merged array position (k)
    i = 0, j = 0;
    int k = left;

    // Merge the two temporary arrays back into the original array in sorted order
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { // If current element in L is less than or equal to R, add L[i] to arr
            arr[k] = L[i];
            i++;
        } else {            // Otherwise, add R[j] to arr
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements in the left subarray
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements in the right subarray
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}


/**
 * k-way merge sort algorithm for dividing an array into `k` parts and recursively sorting each part.
 * 
 * This function recursively divides the given array segment into `k` parts, sorts each segment using
 * `kWayMergeSort`, and then merges the sorted parts using 'kWayMergeSort' recursively. Until length of the parts
 * equals to 1. Then merges the sorted arrays into one array.
 * 
 * @param arr The array to be sorted.
 * @param left The starting index of the part for be sorted.
 * @param right The ending index of the part for be sorted.
 * @param k number of parts to divide the array for each call.
 */
void kWayMergeSort(int* arr, int left, int right, int k) {
    int i;

    // Base condition: Proceed only if there is more than one do not make another call and return
    if(left >= right){
    	return;
	}
    
        int segmentSize = (right - left + 1) / k;  // Calculate the minimum number of elements for each part
        int extras = (right - left + 1) % k;       // Calculate remaining elements after division,
        int start = left;                          // Set initial start position for dividing 

        int* midPoints = (int*)malloc(k * sizeof(int));  // Array to store endpoints of each divided parts

        // Loop to divide the array into k segments
        for (i = 0; i < k; i++) {
            int end = start + segmentSize - 1;  // Set endpoint for each segment

            // Add remaining elements in the first parts
            if (i < extras) {
                end++; 
            }

            midPoints[i] = end; // Store the endpoint of the current segment

            // Recursively sort each part in themself
            kWayMergeSort(arr, start, end, k);

            start = end + 1; // Move start to the beginning of the next part
        }

        // After sorting, merge each sorted part 
        for (i = 1; i < k; i++) {
            merge(arr, left, midPoints[i - 1], midPoints[i]);
        } 

        free(midPoints); 

}


