#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void siftDown(int* heap, int n, int i);
int extractMax(int* heap, int* n);
void buildHeap(int* heap, int n);
int findMax(int** matrix, int n);
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
		if(heapSizes[i] > m) m = heapSizes[i]; //m will be equal to the size of the heap with maximum size 
	}
	
	for(i=0;i<n;i++){
		matrix[i] = (int*) malloc(m * sizeof(int));
	}
	
	fillMatrix(matrix, n, m, heapSizes); //filling matrix with random values
	
	mainFunction(matrix, n, m, heapSizes); //function that will extract the values from heaps
	
	for(i=0;i<n;i++) free(matrix[i]);
	free(matrix);
	free(heapSizes);
	
	return 0;
}

/*
@brief it does extractMax for a heap that has currently the maximum max value until all the heaps becomes empty. 

@param matrix: pointer to the matrix that stores the heaps.
@param n: the number of rows (heaps) in the matrix.
@param m: the number of columns in the matrix..
@param heapSizes: pointer to the array that stores the size of the each heap.

@return
*/

void mainFunction(int** matrix, int n, int m, int* heapSizes){
	int* finishedHeaps = (int*) malloc(n * sizeof(int)), size = 0, i, index;
	
	printf("\n\n\n****************************************\n");
	printf("\n\n\nmatrix before buildHeap operations...\n");
	printMatrix(matrix, n, m);
	
	for(i=0;i<n;i++){
		buildHeap(matrix[i], heapSizes[i]);
	}
	
	printf("\n\n\n****************************************\n");
	printf("\n\n\nmatrix after buildHeap operations...\n");
	printMatrix(matrix, n, m);
	
	i = 0;
	while(size < n){ //it repeats until all the heaps becomes empty
		index = findMax(matrix, n); //index stores the index of the heap that has maximum max value at this iteration
		
		printf("\n\n\n****************************************\n");
		printf("\nthe selected element: %d\n", matrix[index][0]);
		
		extractMax(matrix[index], &heapSizes[index]);
		
		if(!heapSizes[index]){//if heap in that index becomes empty after extractMax then we can add it to finishedHeaps array. 
			printf("\ncurrent finished heap: %d\n", index + 1);
			finishedHeaps[size++] = index + 1; //size is incremented after adding since one heap is done. 
		}
		
		printf("\nmatrix after %d. iteration...\n", ++i);
		printMatrix(matrix, n, m);
	}
	
	printf("\n\n\n****************************************\n");
	printf("\n\nFinished Heap Order...\n");
	for(i=0;i<n;i++) printf("%d ", finishedHeaps[i]); //at the end all the heaps are printed in the order they finished
	
	free(finishedHeaps);
}

/*
@brief it takes all the heaps as a parameter and finds index of the heap that has the maximum max value.

@param matrix: pointer to the matrix that stores the heaps.
@param n: the number of rows (heaps) in the matrix.

@return index of the heap that has the maximum max value
*/

int findMax(int** matrix, int n){
	int i, max = -1, index;
	for(i=0;i<n;i++){
		if(matrix[i][0] > max){
			max = matrix[i][0];
			index = i;
		}
	}
	return index;
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
		arr[i] = i+1; //filling this array with numbers 1 to n * m
	}
	
	shuffle(arr, size); //shuffling this array
	
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
        printf("  %3d    ", k);
    for(i=0;i<n;i++){
        printf("\n   ");
        for(k=0;k<m;k++)
            printf("---------");
        printf("\n%2d |", i+1);

        for(j=0;j<m;j++){
        	printf("  %3d   |", matrix[i][j]);
        }
    }
    printf("\n   ");
    for(k=0;k<m;k++)
        printf("---------");
    printf("\n\n");
}
