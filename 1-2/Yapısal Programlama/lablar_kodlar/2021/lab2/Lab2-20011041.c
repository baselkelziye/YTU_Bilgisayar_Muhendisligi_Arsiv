/*
 Quick note, n variable always represents original length of matrix which means it excludes 1 in (N + 1)x(N + 1) to make it simpler
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_NUMBER_MAX 100
#define RANDOM_NUMBER_MIN 1

int generateRandomNumber(int min, int max);
int **allocateSquareMatrix(int n);
void fillMatrixWithRandomNumbers(int n, int **matrix);
int **reallocateSquareMatrixBigger(int nOld, int nNew, int **matrix);
void findSumsAndWrite(int n, int **matrix);
void printSqMatrixWithSums(int n, int **matrix);
void freeSquareMatrix(int nNew, int **matrix);

int main(int argc, char *argv[])
{
  int n;
  int **matrix;

  srand(time(NULL));

  printf("Enter N in NxN: ");
  scanf("%d", &n);

  if (n <= 1)
  {
    printf("Please enter an integer more than 1.\n");
    return 1;
  }

  matrix = allocateSquareMatrix(n);
  if (matrix == NULL)
  {
    printf("Memory error\n");
    return 1;
  }

  fillMatrixWithRandomNumbers(n, matrix);

  matrix = reallocateSquareMatrixBigger(n, n + 1, matrix);

  findSumsAndWrite(n, matrix);

  printSqMatrixWithSums(n, matrix);

  freeSquareMatrix(n + 1, matrix);
  return 0;
}

void printSqMatrixWithSums(int n, int **matrix)
{
  int i, j;
  for (i = 0; i < n + 1; i++)
  {
    for (j = 0; j < n + 1; j++)
    {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
}
void findSumsAndWrite(int n, int **matrix)
{
  int i, j;
  int tempRowSum, tempColumnSum;

  matrix[n][n] = 0;

  for (i = 0; i < n; i++)
  {
    tempRowSum = 0;
    tempColumnSum = 0;

    for (j = 0; j < n; j++)
    {
      tempRowSum += matrix[i][j];
      tempColumnSum += matrix[j][i];
    }

    matrix[i][n] = tempRowSum;
    matrix[n][i] = tempColumnSum;

    matrix[n][n] += (tempRowSum + tempColumnSum);
  }
}

/* Includes 1 in N + 1 */
void freeSquareMatrix(int nNew, int **matrix)
{
  int i;
  for (i = 0; i < nNew; i++)
  {
    free(matrix[i]);
  }

  free(matrix);
}

/* ONLY USE THIS FOR BIGGER MATRIXES */
int **reallocateSquareMatrixBigger(int nOld, int nNew, int **matrix)
{
  int i;

  if (nNew <= nOld)
  {
    printf("Invalid use of function\n");
    exit(1);
  }

  matrix = (int **)realloc(matrix, nNew * sizeof(int *));

  // Realloc old rows
  for (i = 0; i < nOld; i++)
  {
    matrix[i] = (int *)realloc(matrix[i], nNew * sizeof(int));
  }

  /* Now allocate new rows that wasnt allocated */
  for (i = nOld; i < nNew; i++)
  {
    matrix[i] = (int *)malloc(nNew * sizeof(int));
  }
  return matrix;
}

void fillMatrixWithRandomNumbers(int n, int **matrix)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      matrix[i][j] = generateRandomNumber(RANDOM_NUMBER_MIN, RANDOM_NUMBER_MAX);
    }
  }
}

int **allocateSquareMatrix(int n)
{
  int i;
  int **matrix = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++)
  {
    matrix[i] = (int *)malloc(n * sizeof(int));
  }
  return matrix;
}

/* Generates random number between min and max */
int generateRandomNumber(int min, int max)
{
  return (rand() % (max - min + 1) + min);
}

/* Prints matrix using 2D pointer and n */
void printMatrix(int n, int **matrix)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
}