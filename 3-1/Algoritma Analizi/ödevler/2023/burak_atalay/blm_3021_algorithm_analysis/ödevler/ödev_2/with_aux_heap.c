#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//this is better when k is bigger than 7 but worse when k is less than 7. homework is for k is between 2 and 10 so I didnt upload this.

typedef struct{// heap to use when selecting the maximum of maximum value of each heap in the matrix
	int key; // the max value of a heap (heap is organized according to key value of the nodes) 
	int index; // which heap's max value this key is
}NODE;

void mergeSortKWay(int* arr, int k, int left, int right);
void merge(int* arr, int k, int left, int right, int partSize);

void insertionSort(int* arr, int left, int right);
void siftUp(NODE* heap, int i);
void siftDown(NODE* heap, int n, int i);
NODE extractMin(NODE* heap, int* n);
void buildHeap(NODE* heap, int n);
void insert(NODE* heap, int* n, int key, int index);
void shuffle(int* arr, int n);
void copyArray(int* src, int* dest, int n);
void testTheSortingAlgorithm(int K, int numOfTests);

int main(){	
	int K = 100, numOfTests = 10;
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
																											                                 														
void merge(int* arr, int k, int left, int right, int partSize){
	int n = right - left + 1, i, j, key, min, index;
	NODE currMin;
	int* indices = (int*) calloc(k, sizeof(int));
	int* ends = (int*) malloc(k * sizeof(int));
	int* helperArr = (int*) malloc(n * sizeof(int));
	NODE* heap = (NODE*) malloc(k * sizeof(NODE));
	int heapSize = k;
	
	for(i=0;i<k;i++){
		indices[i] = left + i * partSize;
		ends[i] = indices[i] + partSize - 1;
	}
	
	ends[k-1] += n % k;
	
	for(i=0;i<heapSize;i++){
		heap[i].index = i;
		heap[i].key = arr[left + i * partSize];
	}
	
	buildHeap(heap, heapSize);
	
	i = 0;
	while(i < n){
		currMin = extractMin(heap, &heapSize);
		helperArr[i++] = currMin.key;
		
		if(indices[currMin.index] <= ends[currMin.index]){
			insert(heap, &heapSize, arr[indices[currMin.index]], currMin.index);	
			indices[currMin.index]++;
		}
	}
	
	for(i=0;i<n;i++){
		arr[left + i] = helperArr[i];
	}
	
	free(ends);
	free(indices);
	free(helperArr);
	free(heap);
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

void siftUp(NODE* heap, int i){
	NODE temp;
	while(i && heap[i].key < heap[(i - 1) / 2].key){
		temp = heap[i];
		heap[i] = heap[(i - 1) / 2];
		heap[(i - 1) / 2] = temp;
	
		i = (i - 1) / 2;
	}
}

/*
@brief it swaps until key of the element is bigger than or equal to both of its children's key

@param heap: pointer to the heap.
@param n: size of the heap.
@param i: the index of the element that will be sifted down.

@return
*/

void siftDown(NODE* heap, int n, int i){
	int index = i;
	NODE temp;
	
	do{
		i = index;
		if(2 * i + 1 < n && heap[2 * i + 1].key < heap[index].key){
			index = 2 * i + 1;
		}
		if(2 * i + 2 < n && heap[2 * i + 2].key < heap[index].key){
			index = 2 * i + 2;
		}
		temp = heap[i];
		heap[i] = heap[index];
		heap[index] = temp;
	} while(i != index);//it stops when i doesnt change in the last iteration so that means either the element is not less than both of its children or it is leaf at the moment
}

/*
@brief it swaps the rightmost leaf node with the root and after decrease the size by one, calls the siftDownNODE function for the root.

@param heap: pointer to the heap.
@param n: pointer to the size of the heap.

@return the NODE with the max value of the heap
*/

NODE extractMin(NODE* heap, int* n){
	NODE result = heap[0];
	heap[0] = heap[*n - 1];
	(*n)--;
	siftDown(heap, *n, 0);
	return result;
}

/*
@brief it adds a NODE to the rightmost leaf of the heap after that calls the siftUpNODE function for the new added NODE and increases the size by one.

@param heap: pointer to the heap.
@param n: pointer to the size of the heap.
@param key: the value which will be the key of this new node.
@param index: index of the heap in the matrix.

@return
*/

void insert(NODE* heap, int* n, int key, int index){
	heap[*n].index = index;
	heap[*n].key = key;
	siftUp(heap, *n);
	(*n)++;
}

/*
@brief it calls siftDownNODE starting from the first non leaf node to build a heap from an array.

@param heap: pointer to the heap.
@param n: pointer to the size of the heap.

@return 
*/

void buildHeap(NODE* heap, int n){
	int i;
	for(i=n/2;i>=0;i--) siftDown(heap, n, i);
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
	FILE *file = fopen("resultsHeap.txt", "w");
	
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
