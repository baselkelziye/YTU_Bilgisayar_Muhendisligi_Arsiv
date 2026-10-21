#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

// Matrisin elemanlarini kullanicidan alan fonksiyon
void readMatrix(float matrix[N][N], int size)
{
	int i, j;
	
	printf("\nEnter the elements of the matrix in row order...\n");
	for(i=0; i<size; i++){
		
		for(j=0; j<size; j++){
			printf("Element[%d][%d] = ", i + 1, j + 1);
			scanf("%f", &matrix[i][j]);
		}
		
		printf("\n");
	}
}

// Kullanicinin girdigi elemanlara gore matrisi yazdiran fonksiyon
void printMatrix(float matrix[N][N], int size)
{
	int i, j;
	
	for(i=0; i<size; i++){
		
		for(j=0; j<size; j++){
			
			if(matrix[i][j] < 0){
				printf("\t%f", matrix[i][j]);
			}
			else{
				printf("\t %f", matrix[i][j]);
			}
		}
		
		printf("\n");
	}
}

// Girilen matrisin determinant degerini hesaplayan fonksiyon
float detCalculation(float matrix[N][N], int size)
{
	int a, b, i, j, k;
	float determinant = 0, minor[N][N];
	
	if(size == 1){
		determinant = matrix[0][0]; // Ebatlari 1x1 olan matrisin determinanti
		return determinant;
	}
	else if(size == 2){
		determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]); // Ebatlari 2x2 olan matrisin determinanti
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
	
	/*
	- Bu islem, 0. satir uzerinden yapilir.
	- En distaki 'for' dongusu 0. satirin sutunlarini doner.
	- a ve b degerleri, 0. satirin elemanlarinin minorunu bulmak icin tutulan matrisin satir ve sutunlarinda kullanilir.
	- Determinant degeri, A[m][n] x [-1^(m+n)] x |M(m)(n)| formulu ile hesaplanir.
	*/
	
	return determinant;
}

// Girilen matrisin kofaktor ve ek matrislerini hesaplayip ters matrisini bulan fonksiyon
void inverseMatrix(float matrix[N][N], int size)
{
	int a, b, i, j, x, y;
	float determinant, adjMatrix[N][N], cofactor[N][N], minor[N][N];
	
	for(x=0; x<size; x++){
		
		for(y=0; y<size; y++){
			a = 0;
			b = 0;
			
			for(i=0; i<size; i++){
				
				for(j=0; j<size; j++){
					
					if(i != x && j != y){
						minor[a][b] = matrix[i][j];
						b++;
					}
					
					if(b == size - 1){
						b = 0;
						a++;
					}
				}
			}
			
			cofactor[x][y] = pow(-1, x+y) * detCalculation(minor, size - 1);
		}
	}
	
	printf("\nCofactors of the matrix:\n");
	printMatrix(cofactor, size);
	
	for(i=0; i<size; i++){
		
		for(j=0; j<size; j++){
			adjMatrix[i][j] = cofactor[j][i]; // Ek matrisi bulmak icin kofaktor matrisin devrigi alinir.
		}
	}
	
	printf("\nAdjoint matrix:\n");
	printMatrix(adjMatrix, size);
	
	determinant = detCalculation(matrix, size);
	
	for(i=0; i<size; i++){
		
		for(j=0; j<size; j++){
			adjMatrix[i][j] /= determinant; // Ters matrisi bulmak icin ek matrisin elemanlari determinant degerine bolunur.
		}
	}	
	
	printf("\nInverse matrix:\n");
	printMatrix(adjMatrix, size);	
}

int main()
{
	int size;
	float determinant, matrix[N][N];
	
	printf("--> INVERSE OF NxN MATRIX\n\n");
	
	printf("Enter the dimension of the square matrix to be inverted: ");
	scanf("%d", &size);
	
	readMatrix(matrix, size);
	
	printf("\nThe matrix you created:\n");
	printMatrix(matrix, size);
	
	determinant = detCalculation(matrix, size);
	printf("\nDeterminant: %f\n", determinant);
	
	if(determinant == 0){
		int choice;
		
		printf("\nThe determinant value is zero, the matrix cannot be inverted.\n");
		printf("\n1) TRY AGAIN");
		printf("\n2) EXIT");
		printf("\nYour choice: ");
		scanf("%d", &choice);
		
		if(choice == 1){
			system("cls");
			
			return main();
		}
		else{
			system("cls");
			
			printf("-\n");
			printf("-\n");
			printf("-");
			
			exit(0);
		}
		
	}
	else{
		inverseMatrix(matrix, size);	
	}
	
	getch();
	
	return 0;
}

