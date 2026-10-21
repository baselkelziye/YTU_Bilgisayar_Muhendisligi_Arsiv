#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void mergeSort(int* arr, int k, int left, int right);
void merge(int* arr, int k, int left, int right, int partSize);

void insertionSort(int* arr, int left, int right);
void shuffle(int* arr, int n);
void copyArray(int* src, int* dest, int n);
void testTheSortingAlgorithm(int K, int numOfTests);

int main(){
	int K = 10, numOfTests = 10;
	testTheSortingAlgorithm(K, numOfTests);
	return 0;
}

/*
@brief divides array into k parts make a call for each part until the base case where n < k and at the end merge the k parts. 

@param arr: array which will be sorted.
@param k: it determines how many parts the array will be divided.
@param left: start index of the portion of the array.
@param right: end index of the portion of the array
@return
*/

void mergeSortKWay(int* arr, int k, int left, int right){
	int n = right - left + 1;
	if(n == 1) return; //base case when we have one element, it is already sorted
	if(n < k){ //base case when n < k, we can divide further so we need to sort it in naive way
		insertionSort(arr, left, right); //used insertion sort to sort the array in the base case
		return;
	}
	
	//divide
	int partSize = n / k, i, j = 0; //calculating the size of each part except the last part by integer division
	
	for(i=0;i<k-1;i++){
		mergeSortKWay(arr, k, left + j, left + j + partSize - 1); //making call for each part with size n / k except last part
		j += partSize;
	}
	mergeSortKWay(arr, k, left + j, right); //last part may be bigger than n / k so we make the call after for loop 
	
	//merge
	merge(arr, k, left, right, partSize); //merging the k parts 
}

/*
@brief creates an auxilary array with size n and selects the min element out of all the k parts in O(k) complexity in each step and 
saves it in the aux array. at the end copy the elements to the original array. 

@param arr: array some portion of which will be sorted by merging k parts.
@param k: the number of parts which will be merged.
@param left: start index of the portion of the array.
@param right: end index of the portion of the array
@param partSize: the size of each part except the last part (we can find the last part's size by partSize + n % k)

@return
*/		
																									                                 														
void merge(int* arr, int k, int left, int right, int partSize){
	int n = right - left + 1, i, j, min, index;
	int* indices = (int*) calloc(k, sizeof(int)); //stores the current index of each part
	int* ends = (int*) malloc(k * sizeof(int)); //stores the end index of each part
	int* helperArr = (int*) malloc(n * sizeof(int));

	for(i=0;i<k;i++){ //calculating the start indices and end indices of each part
		indices[i] = left + i * partSize;
		ends[i] = indices[i] + partSize - 1;
	}
	
	ends[k-1] += n % k; //adding the mod to the last part's end index to find the real end
	
	i = 0;
	while(i < n){ //iterates until all the n element is correctly placed in the helper array
		min = INT_MAX; //will be the min element out of all the k parts
		for(j=0;j<k;j++){ //iterating all the parts' current indices
			if(indices[j] <= ends[j] && min > arr[indices[j]]){ //if the current part is not finished and its current min elemnet is less than min
				min = arr[indices[j]];
				index = j; //stores which part's element we took
			}
		}
		indices[index]++; //moving forward in the part where we took the element
		helperArr[i++] = min; //adding the element
	}
	
	for(i=0;i<n;i++){ //copying the helper arr to the original array
		arr[left + i] = helperArr[i];
	}
	
	free(ends);
	free(indices);
	free(helperArr);
}

/*
@brief it does the regular insertion sort to sort a portion of the input array 

@param arr: array some portion of which will be sorted.
@param left: start index of the portion of the array.
@param right: end index of the portion of the array

@return
*/	

void insertionSort(int* arr, int left, int right){
	int i, j, n = right - left + 1;
	int temp;
	
	for(i=1;i<n;i++){
		j = left + i - 1;
		temp = arr[i + left];
		while(j >= left && arr[j] > temp){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

/*
@brief simply checks whether the input array is sorted or not by comparing the adjacent elements

@param arr: pointer to the array
@param n: size of the array

@return 1 if array is sorted or 0
*/	

int isSorted(int* arr, int n) {
    int i;
	for(i=0;i<n-1;i++){
        if(arr[i] > arr[i + 1]){
            return 0;
        }
    }
    return 1;
}

/*
@brief simply suffles the input array in linear time

@param arr: pointer to the array
@param n: size of the array

@return
*/

void shuffle(int* arr, int n){
	int i, j, temp;
	srand(time(NULL));
	
    for(i=n-1;i>0;i--){
        j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/*
@brief simply copy the elements of the source array to the destination array

@param src: pointer to the source array
@param dest: pointer to the destination array
@param n: size of the arrays

@return
*/

void copyArray(int* src, int* dest, int n){
	int i;
	
	for(i=0;i<n;i++){
		dest[i] = src[i];
	}
}

/*
@brief tests the algorithm with different n, k and calculate the running time and writes to the file.

@param K: the upper limit of k that will be tested for the algorithm. (default one is 10 when called in main function)
@param numOfTests: the number of tests the algorithm will be tested. so we will create different arrays for each test. default one is 10

@return
*/

void testTheSortingAlgorithm(int K, int numOfTests){
	int k, i, j;
	int** arr = (int**) malloc(numOfTests * sizeof(int*)); //different arrays for each test
	int* copyArr = (int*) malloc(10000000 * sizeof(int)); 
	long N[6] = {100, 1000, 10000, 100000, 1000000, 10000000};
	double timeTaken, totalTimeTaken, meanTime;
	FILE *file = fopen("resultsLinear.txt", "w");
	
    if(file == NULL){
        printf("file couldn't be opened.\n");
		free(arr);
		free(copyArr);
        return;
    }
    
    fprintf(file, "n,k,mean_time_ms\n"); //writing in csv format
    
    for(i=0;i<numOfTests;i++){ //allocating an array for each test
    	arr[i] = (int*) malloc(N[5] * sizeof(int)); //making each one with size the larger n
    	for(j=0;j<N[5];j++){ //filling each with numbers 1 to larger n
			arr[i][j] = j+1;	
		}
		shuffle(arr[i], N[5]); //shuffling to get the randomness
	}

	for(i=0;i<6;i++){
		printf("\nfor n: %d...\n\n", N[i]);
		for(k=2;k<=K;k++){
			printf("\nfor k: %d...\n\n", k);
			totalTimeTaken = 0.0;
			for(j=0;j<numOfTests;j++){
				copyArray(copyArr, arr[j], N[i]); //copying the array for test j to not change the original one
				clock_t start = clock();
				mergeSortKWay(copyArr, k, 0, N[i] - 1);
				clock_t end = clock();
			    timeTaken = ((double)(end - start) * 1000) / CLOCKS_PER_SEC; //calculating the number of ms 
			    totalTimeTaken += timeTaken;
			    printf("Time taken: %f ms - ", timeTaken);
			    if(isSorted(copyArr, N[i])) printf("sorted successfully.\n"); //checking whether it is sorted successfully
			    else printf("couldnt be sorted.\n");
			}
			meanTime = totalTimeTaken / numOfTests; //calculating the mean time taken for the specific n and k
            fprintf(file, "%ld,%d,%f\n", N[i], k, meanTime);
            printf("Mean time taken for n = %ld and k = %d is %f ms\n", N[i], k, meanTime);
			printf("----------------------------------------------");
		}
		printf("----------------------------------------------");
	}
	
		
	fclose(file);
	for(i=0;i<numOfTests;i++) free(arr[i]);
	free(arr);
	free(copyArr);
}
