#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int** createMatrix(int N, int M);
void freeMatrix(int** matrix, int N);
void printMatrix(int** matrix, int N, int M);
int** fillMatrixWithRandomNumbers(int** matrix, int* lengthOfEachQueue, int N, int M);
void build_max_heap(int* arr, int n);
void max_heapify(int* arr, int n, int i);
void swap(int *a, int *b);
int allIsFinished(int** matrix, int N);

int main(){
	
	int N, M, i, max, resultOrder=0;
	int* lengthOfEachQueue;
	int* result;
	
	N = 4;
	M = 5;
	
	
	int** matrix = createMatrix(N, M);
	
	result = (int*)malloc(N*sizeof(int));
	
	lengthOfEachQueue = (int*)malloc(N*sizeof(int));
	lengthOfEachQueue[0] = 2;
	lengthOfEachQueue[1] = 3;
	lengthOfEachQueue[2] = 4;
	lengthOfEachQueue[3] = 4;
	
	matrix[0][0] = 20;
	matrix[0][1] = 19;
	matrix[0][2] = -1;
	matrix[0][3] = -1;
	matrix[0][4] = -1;
	
	matrix[1][0] = 17;
	matrix[1][1] = 5;
	matrix[1][2] = 18;
	matrix[1][3] = -1;
	matrix[1][4] = -1;
	
	matrix[2][0] = 1;
	matrix[2][1] = 9;
	matrix[2][2] = 8;
	matrix[2][3] = 3;
	matrix[2][4] = -1;
	
	matrix[3][0] = 12;
	matrix[3][1] = 14;
	matrix[3][2] = 13;
	matrix[3][3] = 15;
	matrix[3][4] = -1;
	printf("Matrix filled with random numbers:\n");
	printMatrix(matrix, N, M);
	printf("\n");
	for(i=0; i < N; i++){
		build_max_heap(matrix[i], lengthOfEachQueue[i]);
	}
	printf("Matrix constructed as heap tree:\n");
	printMatrix(matrix, N, M);
	printf("\n");
	
	while(!allIsFinished(matrix, N)){
		max = 0;
		for(i=0; i < N; i++){
			if(matrix[i][0] > matrix[max][0])
				max = i;
		}
		matrix[max][0] = -1;
		max_heapify(matrix[max], lengthOfEachQueue[max], 0);
		if(matrix[max][0] == -1){
			result[resultOrder] = max + 1;
			resultOrder++;
		}
		lengthOfEachQueue[i] -= 1;
		printMatrix(matrix, N, M);
		printf("\n");
	}
	printf("Finished order: ");
	for(i = 0; i<N; i++){
		printf("%d ", result[i]);
	}
	freeMatrix(matrix, N);
	
	return 0;
}

int** createMatrix(int N, int M){
	int i, j;
	int** matrix = (int**)malloc(sizeof(int*)*N);
	for(i = 0; i < N; i++){
		matrix[i] = (int*)malloc(sizeof(int)*M);
		for (j = 0; j < M; j++) {
            matrix[i][j] = -1;
        }
	}
	return matrix;
}

void freeMatrix(int** matrix, int N){
	int i;
	for(i=0;i<N;i++){
		free(matrix[i]);
	}
	free(matrix);
}

void printMatrix(int** matrix, int N, int M){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%4d",matrix[i][j]);
		}
		printf("\n");
	}
}

int** fillMatrixWithRandomNumbers(int** matrix, int* lengthOfEachQueue, int N, int M){
	srand(time(NULL));
	int *uniqueNumbers;
	int i, j, K, temp, numPlaced = 0;
	
	K = N * M;
	uniqueNumbers = (int*)malloc(K * sizeof(int));
	for (i = 0; i < K; i++) {
        uniqueNumbers[i] = i;
    }
    
	for(i=K-1;i>=0;i--){
		j = rand() % (i + 1);
		temp = uniqueNumbers[i];
        uniqueNumbers[i] = uniqueNumbers[j];
        uniqueNumbers[j] = temp;
	}
	
	
    for (i = 0; i < N; i++) {
        for (j = 0; j < lengthOfEachQueue[i]; j++) {
            matrix[i][j] = uniqueNumbers[numPlaced++];
        }
    }
	
	free(uniqueNumbers);
	return matrix;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void max_heapify(int* arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, n, largest);
    }
}

void build_max_heap(int arr[], int n) {
	int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}

int allIsFinished(int** matrix, int N){
	int allIsFinished = 1;
	int i;
	for(i=0; i < N; i++){
		if(matrix[i][0] != -1){
			allIsFinished = 0;
			return allIsFinished;
		}
	}
	return allIsFinished;
}



