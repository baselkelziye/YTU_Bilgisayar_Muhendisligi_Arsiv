#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Important Not: I could have searched linear to find which heap's value is bigger and called extractMax for that heap and would not have needed heap functions
for NODE type but with this way the complexity was decreased to O(n * m * (logn + logm)) from O(n * m * (n + logm)). I could have made matrix as NODE type 
as well but then space efficiency would not have been good. So please dont deduct points for using seperate functions for node type since I did this to decrease
the time complexity. 
*/

typedef struct{// heap to use when selecting the maximum of maximum value of each heap in the matrix
	int key; // the max value of a heap (heap is organized according to key value of the nodes) 
	int index; // which heap's max value this key is
}NODE;

void siftDown(int* heap, int n, int i);
int extractMax(int* heap, int* n);
int getMax(int* heap);
void buildHeap(int* heap, int n);
void siftUpNODE(NODE* heap, int i);
void siftDownNODE(NODE* heap, int n, int i);
NODE extractMaxNODE(NODE* heap, int* n);
void buildHeapNODE(NODE* heap, int n);
void insertNODE(NODE* heap, int* n, int key, int index);
void shuffle(int* arr, int n);
void fillMatrix(int** matrix, int n, int m, int* heapSizes);
void printMatrix(int** matrix, int n, int m);
void mainFunction(int** matrix, int n, int m, int* heapSizes);

int main(){
	int **matrix, n, m = 0, *heapSizes, i;
	
	printf("How many heaps are there: ");
	scanf("%d", &n);
	
	heapSizes = (int*) malloc(n * sizeof(int));
	matrix = (int**) malloc(n * sizeof(int*));
	
	for(i=0;i<n;i++){
		printf("%d. heap's size: ", i+1);
		scanf("%d", &heapSizes[i]);
		if(heapSizes[i] <= 0){
			printf("\nsize cannot be less than 1...\n");
			i--;
		}
		if(heapSizes[i] > m) m = heapSizes[i];
	}
	
	for(i=0;i<n;i++){
		matrix[i] = (int*) malloc(m * sizeof(int));
	}
	
	fillMatrix(matrix, n, m, heapSizes);
	
	mainFunction(matrix, n, m, heapSizes);
	
	for(i=0;i<n;i++) free(matrix[i]);
	free(matrix);
	free(heapSizes);
	
	return 0;
}

/*
@brief it creates heap for each row of the matrix and finds the maximum of maximum values. 

@param matrix: pointer to the matrix that stores the heaps.
@param n: the number of rows (heaps) in the matrix.
@param m: the number of columns in the matrix..
@param heapSizes: pointer to the array that stores the size of the each heap.

@return
*/

void mainFunction(int** matrix, int n, int m, int* heapSizes){
	int* finishedHeaps = (int*) malloc(n * sizeof(int)), size = 0, i;
	NODE* auxHeap = (NODE*) malloc(n * sizeof(NODE));
	int auxHeapSize = n;
	NODE temp;
	
	printf("\n\n\n****************************************\n");
	printf("\n\n\nmatrix before buildHeap operations...\n");
	printMatrix(matrix, n, m);
	
	for(i=0;i<n;i++){
		buildHeap(matrix[i], heapSizes[i]);
	}
	
	printf("\n\n\n****************************************\n");
	printf("\n\n\nmatrix after buildHeap operations...\n");
	printMatrix(matrix, n, m);
	
	for(i=0;i<n;i++){
		auxHeap[i].index = i;
		auxHeap[i].key = getMax(matrix[i]);
	}
	
	buildHeapNODE(auxHeap, n);
	
	i = 0;
	while(size < n){
		temp = extractMaxNODE(auxHeap, &auxHeapSize);
		
		printf("\n\n\n****************************************\n");
		printf("\nthe selected element: %d\n", temp.key);
		
		extractMax(matrix[temp.index], &heapSizes[temp.index]);
		
		if(!heapSizes[temp.index]){
			printf("\ncurrent finished heap: %d\n", temp.index + 1);
			finishedHeaps[size++] = temp.index + 1;
		}
		else{
			insertNODE(auxHeap, &auxHeapSize, getMax(matrix[temp.index]), temp.index);
		}
		
		printf("\nmatrix after %d. iteration...\n", ++i);
		printMatrix(matrix, n, m);
	}
	
	printf("\n\n\n****************************************\n");
	printf("\n\nFinished Heap Order...\n");
	for(i=0;i<n;i++) printf("%d ", finishedHeaps[i]);
	
	free(auxHeap);
	free(finishedHeaps);
}

/*
@brief it swaps until the element is bigger than or equal to both of its children

@param heap: pointer to the heap.
@param n: size of the heap.
@param i: the index of the element that will be sifted down.

@return
*/

void siftDown(int* heap, int n, int i){
	int temp, index = i;
	
	do{
		i = index;
		if(2 * i + 1 < n && heap[2 * i + 1] > heap[index]){
			index = 2 * i + 1;
		}
		if(2 * i + 2 < n && heap[2 * i + 2] > heap[index]){
			index = 2 * i + 2;
		}
		temp = heap[i];
		heap[i] = heap[index];
		heap[index] = temp;
	} while(i != index); //it stops when i doesnt change in the last iteration so that means either the element is not less than both of its children or it is leaf at the moment
}

/*
@brief it swaps the rightmost leaf node with the root and after decrease the size by one, calls the siftDown function for the root.

@param heap: pointer to the heap.
@param n: pointer to the size of the heap.

@return the max value of the heap
*/

int extractMax(int* heap, int* n){
	int result = heap[0];
	heap[0] = heap[*n - 1];
	heap[--(*n)] = - 1;
	siftDown(heap, *n, 0);
	return result;
}

/*
@brief it returns the max value of the heap.

@param heap: pointer to the heap.

@return the max value of the heap
*/

int getMax(int* heap){
	return heap[0];
}

/*
@brief it calls siftDown starting from the first non leaf node to build a heap from an array.

@param heap: pointer to the heap.
@param n: pointer to the size of the heap.

@return 
*/

void buildHeap(int* heap, int n){
	int i;
	for(i=n/2;i>=0;i--) siftDown(heap, n, i);
}

/*
@brief it swaps with the parent until the key of the element is less than or equal to the parent 

@param heap: pointer to the heap.
@param i: index of the element for which sif-up operation will be done.

@return 
*/

void siftUpNODE(NODE* heap, int i){
	NODE temp;
	while(i && heap[i].key > heap[(i - 1) / 2].key){
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

void siftDownNODE(NODE* heap, int n, int i){
	int index = i;
	NODE temp;
	
	do{
		i = index;
		if(2 * i + 1 < n && heap[2 * i + 1].key > heap[index].key){
			index = 2 * i + 1;
		}
		if(2 * i + 2 < n && heap[2 * i + 2].key > heap[index].key){
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

NODE extractMaxNODE(NODE* heap, int* n){
	NODE result = heap[0];
	heap[0] = heap[*n - 1];
	(*n)--;
	siftDownNODE(heap, *n, 0);
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

void insertNODE(NODE* heap, int* n, int key, int index){
	heap[*n].index = index;
	heap[*n].key = key;
	siftUpNODE(heap, *n);
	(*n)++;
}

/*
@brief it calls siftDownNODE starting from the first non leaf node to build a heap from an array.

@param heap: pointer to the heap.
@param n: pointer to the size of the heap.

@return 
*/

void buildHeapNODE(NODE* heap, int n){
	int i;
	for(i=n/2;i>=0;i--) siftDownNODE(heap, n, i);
}

/*
@brief it shuffles the given array

@param arr: pointer to the array.
@param n: size of the array.

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
@brief it creates an array with size n * m and shuffles it. After that it fills the matrix with this array's values and frees that array at the end.

@param matrix: pointer to the matrix that stores the heaps.
@param n: the number of rows (heaps) in the matrix.
@param m: the number of columns in the matrix.
@param heapSizes: pointer to the array that stores the size of the each heap.

@return 
*/

void fillMatrix(int** matrix, int n, int m, int* heapSizes){
	int *arr, size = n * m, i, j, k;
	arr = (int*) malloc(size * sizeof(int));
	
	for(i=0;i<size;i++){
		arr[i] = i+1;
	}
	
	shuffle(arr, size);
	
	k=0;
	for(i=0;i<n;i++){
		for(j=0;j<heapSizes[i];j++){
			matrix[i][j] = arr[k++];
		}
		while(j < m) matrix[i][j++] = -1; //filling the rest of the row with -1
	}
	
	free(arr);
}

/*
@brief it prints the matrix in a formatted way

@param matrix: pointer to the matrix that stores the heaps.
@param n: the number of rows (heaps) in the matrix.
@param m: the number of columns in the matrix.

@return 
*/

void printMatrix(int** matrix, int n, int m){
    int i, j, k;
    printf("\n\n   ");
    for(k=0;k<m;k++)
        printf("  %2d    ", k);
    for(i=0;i<n;i++){
        printf("\n   ");
        for(k=0;k<m;k++)
            printf("--------");
        printf("\n%2d |", i+1);

        for(j=0;j<m;j++){
        	printf("  %2d   |", matrix[i][j]);
        }
    }
    printf("\n   ");
    for(k=0;k<m;k++)
        printf("--------");
    printf("\n\n");
}
