#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrix(int **matrix, int N, int M, int *capaticies, int *usedNumbers);
void printMatrix(int **matrix, int N, int M);
void swap(int *a, int *b);
void maxHeapify(int *array, int n, int i);
void buildMaxHeap(int *array, int n);
void heapifyMatrix(int **matrix, int N, int *capacities);
int extractMaxFromMatrix(int **matrix, int N, int M, int *capacities, int *emptyQueues, int *k);
 
int main() {
	int i, j, k; // indexes
	int N, M; // number of rows and columns
	int **matrix; // matrix
	int *capacities; // array that has length of heaps
	int randomNumber; // random integer
	int *usedNumbers; // label array that shows a number is used or not used in matrix
	int *emptyQueues; // array that has the index of queues emptied in order
	int maxElement; // max element that is extracted from matrix
	
	printf("N: ");
	scanf("%d", &N);
	
	printf("M: ");
	scanf("%d", &M);
	
	capacities = (int*)malloc(N * sizeof(int));
	usedNumbers = (int*)calloc(((N * M) + 5), sizeof(int));
	emptyQueues = (int*)malloc(N * sizeof(int));
	
	matrix = (int**)malloc(N * sizeof(int*));
	for (i = 0; i < N; i++) { 
		matrix[i] = (int*)malloc(M * sizeof(int));
	}
	
	for (i = 0; i < N; i++) { // user inputs the length of heaps
		do {
			printf("size of %dth priority queue: ", i);
			scanf("%d", &capacities[i]);
		} while (capacities[i] > M);	
	}
	
	fillMatrix(matrix, N, M, capacities, usedNumbers);
	
	printf("\nThe random matrix: \n");
	printMatrix(matrix, N, M);
	printf("--------------------------------------------------------------\n");
	
	heapifyMatrix(matrix, N, capacities);
	
	printf("\nThe matrix that has heaps: \n");
	printMatrix(matrix, N, M);
	printf("--------------------------------------------------------------\n");
	
	k = 0;
	while (k < N) { // until all heaps are empty, it extract the max element from the matrix
		maxElement = extractMaxFromMatrix(matrix, N, M, capacities, emptyQueues, &k);
		printf("\n");
		printMatrix(matrix, N, M);
		printf("Extracted element: %d\n", maxElement);
		printf("--------------------------------------------------------------\n");
	}
	
	printf("\nQueues emptied in order: ");
	for (i = 0; i < N; i++) { // prints the queues emptied in order
		printf("%d ", emptyQueues[i]);
	}
	
	return 0;
}

/*
@brief a function that fills a matrix with random numbers uniquely

@param matrix the matrix that has heaps in each row
@param N number of rows of matrix
@param M number of columns of matrix
@param capacities array that has length of heaps
@param usedNumbers label array that shows a number is used or not used in matrix. If a number is used, label is 1, else it is 0

@return
*/
void fillMatrix(int **matrix, int N, int M, int *capacities, int *usedNumbers) {
	int i, j, randomNumber;
	
	srand(time(NULL));
	
	for (i = 0; i < N; i++) { // for each row and column it fills the matrix with unique numbers 
		j = 0;
        while (j < capacities[i]) {
            randomNumber = rand() % ((N * M) + 2);
            if (usedNumbers[randomNumber] == 0) { // if random number is not used it makes matrix[i][j] the number
                matrix[i][j] = randomNumber;
                usedNumbers[randomNumber] = 1;
                j++;
            }
        }
		for (j = capacities[i]; j < M; j++) { // it makes empty areas -1
            matrix[i][j] = -1;
        }
	}
	
	free(usedNumbers);
}

/*
@brief a function that prints the matrix

@param matrix the matrix that has heaps in each row
@param N number of rows of matrix
@param M number of columns of matrix

@return
*/
void printMatrix(int **matrix, int N, int M) {
	int i, j;
	
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

/*
@brief a function that swaps values of two integer

@param a an integer pointer
@param b an integer pointer

@return
*/
void swap(int *a, int *b) {
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

/*
@brief a function that heapifies down an element of max heap

@param array an integer array which is a heap
@param n length of array
@param i index that we want to heapify

@return
*/
void maxHeapify(int *array, int n, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	int largest = i;
	
	if (left < n && array[left] > array[largest]) {
		largest = left;
	}
	
	if (right < n && array[right] > array[largest]) {
		largest = right;
	}
	
	if (i != largest) {
		swap(&array[i], &array[largest]);
		return maxHeapify(array, n, largest);
	}
}

/*
@brief a function that builds max heap from a complete binary tree by apllying maxHeapify to all elements

@param array an integer array which is a heap
@param n length of array

@return
*/
void buildMaxHeap(int *array, int n) {
	int i;
	
	for (i = n/2; i >=0; i--) {
		maxHeapify(array, n, i);
	}
}

/*
@brief a function that applyies maxHeapify to all rows of the matrix

@param matrix the matrix that has heaps in each row
@param N number of rows of matrix
@param capacities array that has length of heaps

@return
*/
void heapifyMatrix(int **matrix, int N, int *capacities) {
	int i;
	
	for (i = 0; i < N; i++) { // applys buildMaxHeap function for each heap in the matrix
		buildMaxHeap(matrix[i], capacities[i]);
	}
}

/*
@brief a function that prints the matrix

@param matrix the matrix that has heaps in each row
@param N number of rows of matrix
@param M number of columns of matrix
@param capacities array that has length of heaps
@param emptyQueues array that has the index of queues emptied in order
@param k length of emptyQueues array

@return
*/
int extractMaxFromMatrix(int **matrix, int N, int M, int *capacities, int *emptyQueues, int *k) {
	int i, max = 0, maxElement;
	
	for (i = 0; i < N; i++) { // finds the index of heap which has the biggest element in its top
		if (matrix[i][0] >= matrix[max][0]) {
			max = i;
		}
	}
	
	maxElement = matrix[max][0];
	
	swap(&matrix[max][0], &matrix[max][capacities[max] - 1]);
	matrix[max][capacities[max] - 1] = -1;
	capacities[max]--;
	
	if (capacities[max] == 0) { // if the heap is empty, it adds the index of heap to empty queues array
		emptyQueues[*k] = max + 1;
		(*k)++;
	}
	else { // if the heap is not empty, it applys the max heapify process to that heap
		maxHeapify(matrix[max], capacities[max], 0);
	}
	
	return maxElement;
}



