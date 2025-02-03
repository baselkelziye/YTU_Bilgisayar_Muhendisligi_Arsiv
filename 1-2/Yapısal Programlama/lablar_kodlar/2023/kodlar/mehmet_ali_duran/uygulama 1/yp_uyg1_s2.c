
#include <stdio.h>

#define ROWS 3
#define COLS 3

void multiplyByTwo(int **, int, int);
//void multiplyByTwo(int **mat, int rows, int cols);
void printMatrix(int **mat, int rows, int cols);

//SORU 2: Bir matisin elemanlarının iki katını alarak aynı matris üzerine yazdırın.
int main() {
    //int data[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};
	int a[] = {1, 2, 3};
	int b[] = {4, 5, 6};
	int c[] = {7, 8, 9};
    int *matrix[] = {a,b,c};
	
    printf("Original Matrix:\n");
    printMatrix(matrix, ROWS, COLS);

    multiplyByTwo(matrix, ROWS, COLS);

    printf("\nMatrix After Multiplication by 2:\n");
    printMatrix(matrix, ROWS, COLS);

    return 0;
}
void multiplyByTwo(int **mat, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            *(*(mat + i) + j) *= 2;
        }
    }
}

void printMatrix(int **mat, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", *(*(mat + i) + j));
        }
        printf("\n");
    }
}




