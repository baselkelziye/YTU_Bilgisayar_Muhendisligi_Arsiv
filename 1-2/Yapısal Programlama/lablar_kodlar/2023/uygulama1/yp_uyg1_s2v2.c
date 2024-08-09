//Soru2 - V2
#include <stdio.h>

#define ROWS 2
#define COLS 3

void multiplyByTwo(int *mat, int rows, int cols);
void printMatrix(int *mat, int rows, int cols);

int main() {
    int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};

    printf("Original Matrix:\n");
    printMatrix((int *)matrix, ROWS, COLS);

    multiplyByTwo((int *)matrix, ROWS, COLS);

    printf("\nMatrix After Multiplication by 2:\n");
    printMatrix((int *)matrix, ROWS, COLS);

    return 0;
}
void multiplyByTwo(int *mat, int rows, int cols) {
    int i,j = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            *((mat + i * cols) + j) *= 2;
        }
    }
}

void printMatrix(int *mat, int rows, int cols) {
	int i,j=0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", *((mat + i * cols) + j));
        }
        printf("\n");
    }
}
