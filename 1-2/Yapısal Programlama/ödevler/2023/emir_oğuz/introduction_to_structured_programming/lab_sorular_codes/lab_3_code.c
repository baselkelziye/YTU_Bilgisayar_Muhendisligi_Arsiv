#include <stdio.h>
#include <time.h>
#include <math.h>

void randomMatrix(int matrix[3][3])
{
	int i, j;
	
	srand(time(NULL));
	
	for(i=0; i<3; i++){
		
		for(j=0; j<3; j++){
			matrix[i][j] = rand() % 10;
		}
	}
}

void printMatrix(int matrix[3][3])
{
	int i, j;
	
	for(i=0; i<3; i++){
		
		for(j=0; j<3; j++){
			printf("%6d", matrix[i][j]);
		}
		
		printf("\n\n");
	}
}

int detCalculation(int matrix[3][3], int size)
{
	int a, b, i, j, k, determinant = 0, minor[3][3];

	if(size == 1){
		determinant = matrix[0][0];
		
		return determinant;
	}
	else if(size == 2){
		determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
		
		return determinant;
	}
	else{
		for(i=0; i<size; i++){ 
			a = 0;
			b = 0;
			
			for(j=1; j<size; j++){
				
				for(k=0; k<size; k++){
					
					if(k != i){
						minor[a][b] = matrix[j][k];
						b++;
					}
					
					if(b == size - 1){
						b = 0;
						a++;
					}
				}
			}
			
			determinant += matrix[0][i] * pow(-1, i) * detCalculation(minor, size - 1);
		}
	}
	
	return determinant;
}

void minorMatrix(int matrix[3][3], int size)
{
	int a, b, i, j, x, y;
	int minor[3][3], temp[3][3];
	
	for(x=0; x<size; x++){
		
		for(y=0; y<size; y++){
			a = 0;
			b = 0;
			
			for(i=0; i<size; i++){
				
				for(j=0; j<size; j++){
					
					if(i != x && j != y){
						temp[a][b] = matrix[i][j];
						b++;
					}
					
					if(b == size - 1){
						b = 0;
						a++;
					}
				}
			}
			
			minor[x][y] = detCalculation(temp, size - 1);
		}
	}
	
	printMatrix(minor);
}

int main()
{
	int i, resultDet, size = 3, matrix[3][3], minor[3][3];
	
	randomMatrix(matrix);
	
	printf("Rastgele uretilen rakamlar ile olusturulan matris:\n\n");
	printMatrix(matrix);
	
	resultDet = detCalculation(matrix, size);
	printf("\nMatrisin determinanti: %d\n\n", resultDet);
	
	printf("\nMinor matris:\n\n");
	minorMatrix(matrix, size);
	
	getch();
	
	return 0;
}

