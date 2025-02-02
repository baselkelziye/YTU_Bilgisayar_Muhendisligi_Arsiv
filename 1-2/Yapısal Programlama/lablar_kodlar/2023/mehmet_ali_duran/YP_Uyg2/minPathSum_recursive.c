#include <stdio.h>
#include <stdlib.h>

void diziDoldur(int *matrix, int rows, int cols){
	int i;
	for(i=0; i < rows * cols; i++){
	
		printf("matrix[%d]:", i);
		scanf("%d", &matrix[i]);
		}
}

void diziYazdir(int *matrix, int rows, int cols){
	int i, j;
	printf("matrisin elemanlari: \n");
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			printf("%d", matrix[i * cols + j]);
		}
		printf("\n");
	}
}

int findMinPathSum(int *matrix, int currentRow, int currentCol, int hedefRow, int hedefCol, int rows, int cols){
	
	int costSag, costAsagi, minCostPath, currentCellCost;
	
	if (currentRow >= rows || currentCol >= cols){
		return INT_MAX;
	}
	
	if (currentRow == hedefRow && currentCol == hedefCol){
		return matrix[currentRow * cols + currentCol];
	}
	
	costSag = findMinPathSum(matrix, currentRow, currentCol + 1, hedefRow, hedefCol, rows, cols);
	costAsagi = findMinPathSum(matrix, currentRow + 1, currentCol, hedefRow, hedefCol, rows, cols);
	
	if (costSag < costAsagi){
		minCostPath = costSag;
	} else {
		minCostPath = costAsagi;
	}
	
	currentCellCost = matrix[currentRow * cols + currentCol];
	return currentCellCost + minCostPath;
	
}

int main(){
	int *matrix;
	int rows, cols;
	
	printf("matrixin satir sayisini girin: ");
	scanf("%d", &rows);
	printf("matrixin sütun sayisini girin: ");
	scanf("%d", &cols);
	
	matrix = (int *)malloc(rows * cols * sizeof(int));
	
	diziDoldur(matrix, rows, cols);
	diziYazdir(matrix, rows, cols);
	
	int minPathSum = findMinPathSum(matrix, 0, 0, rows - 1, cols - 1, rows, cols);
	printf("MinpathSum = %d\n", minPathSum);
	
	free(matrix);
	
	return 0;

}
