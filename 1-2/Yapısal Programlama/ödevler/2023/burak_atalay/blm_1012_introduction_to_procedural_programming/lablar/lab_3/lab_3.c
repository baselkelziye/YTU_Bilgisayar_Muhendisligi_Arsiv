#include<stdio.h>
#include<stdlib.h>
#define max 15

void getMatrix(int** matrix, int n);
void printMatrix(int** matrix, int n);
void totalRoute(int** matrix, int routeMatrix[max][2], int n, int i, int j, int* p, int index);
void printRoute(int routeMatrix[max][2], int n);

int main(){
	int i, j, n, **matrix, routeMatrix[max][2] = {{0}}, *p, count=0;
	p = &count;
	printf("n: ");
	scanf("%d", &n);
	matrix = (int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++) matrix[i] = (int*)malloc(n*sizeof(int));
	
	getMatrix(matrix, n);
	printf("\n\n");
	printMatrix(matrix, n);
	totalRoute(matrix, routeMatrix, n, 0, 0, p, 0);
	printf("\nThe number of routes: %d\n\n", *p);
	return 0;
}

void totalRoute(int** matrix, int routeMatrix[max][2], int n, int i, int j, int* p, int index){
	if(i < 0 || i >= n || j < 0 || j >= n) return;
	if(matrix[i][j] == 0) return;
	if((i == n-1) && (j == n-1)){
		(*p)++;
		printRoute(routeMatrix, n);
		return;
	}
	routeMatrix[index][0] = i; 
	routeMatrix[index][1] = j;
	index++; 
	totalRoute(matrix, routeMatrix, n, i+1, j, p, index);
	totalRoute(matrix, routeMatrix, n, i, j+1, p, index);
}

void printRoute(int routeMatrix[max][2], int n){
    int i;
    
    for (i = 0; i < 2 * n - 2; i++){
        printf("(%d, %d) ", routeMatrix[i][0], routeMatrix[i][1]);
    }
    printf("(%d, %d) ", n - 1, n - 1);
    printf("\n");
}

void getMatrix(int** matrix, int n){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d. row %d. column: ", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}
	}
	matrix[n-1][n-1]=1;
}

void printMatrix(int** matrix, int n){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
