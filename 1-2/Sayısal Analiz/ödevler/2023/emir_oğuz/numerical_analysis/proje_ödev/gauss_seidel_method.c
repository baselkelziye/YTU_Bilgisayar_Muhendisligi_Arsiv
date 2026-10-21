#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

// Denklem sistemini kullanicidan alan fonksiyon
void readMatrix(float matrix[N][N], int size)
{
	int i, j;
	
	printf("\nEnter the coefficients of the variables in the equations and the result of each equation in order...\n");
	
	for(i=0; i<size; i++){
		
		for(j=0; j<size+1; j++){
			
			if(j != size){
				printf("- Element[%d][%d] (Coefficient of x%d) = ", i + 1, j + 1, j + 1);
				scanf("%f", &matrix[i][j]);
			}
			else{
				printf("- Element[%d][%d] (Result %d) = ", i + 1, j + 1, i + 1);
				scanf("%f", &matrix[i][j]);
				printf("\n");
			}
		}
	}
}

// Denklem sistemini genisletilmis katsayi matrisi halinde yazdiran fonksiyon
void printMatrix(float matrix[N][N], int size)
{
	int i, j, value;
	
	for(i=0; i<size; i++){
		
		for(j=0; j<size+1; j++){
			
			if(matrix[i][j] < 0){
				printf("\t%f", matrix[i][j]);
			}
			else{
				printf("\t %f", matrix[i][j]);
			}
			
			if(j == size - 1){
				value = fabs(matrix[i][j] / 10);
				
				if(value < 1){
					printf("     |");
				}
				else if(value >= 1 && value < 10){
					printf("    |");
				}
				else if(value >= 10 && value < 100){
					printf("   |");
				}
				else if(value >= 100 && value < 1000){
					printf("  |");
				}
			}
		}
		
		printf("\n");
	}
}

// Gauss-Seidel Yontemi'nin adimlarini iceren fonksiyon
void gaussSeidel(float matrix[N][N], int size)
{
	int i, j, k, iteration, flag = 0, step = 0;
	float temp, value, x[N], former[N];
	
	// Sutunlardaki elemanlardan mutlak degerce en buyuk olanlar, kosegenlere yerlestirilir.
	// Kosegenlerin alt satirlarinda bulunan elemanlar kontrol ediliyor, ust satira bakilmiyor.
	for(k=0; k<size+1; k++){
		
		for(i=k+1; i<size; i++){
			
			if(fabs(matrix[i][k]) > fabs(matrix[k][k])){
				
				for(j=0; j<size+1; j++){
					temp = matrix[i][j];
					matrix[i][j] = matrix[k][j];
					matrix[k][j] = temp;
				}
				
				flag = 1;
			}
		}
	}
	
	if(flag == 1){
		printf("\nNew matrix formed as a result of row changes:\n");
		printMatrix(matrix, size);
	}
	
	printf("\nEnter the initial values of the variables...\n");
	for(i=0; i<size; i++){
		printf("x%d = ", i+1);
		scanf("%f", &x[i]);
	}
	
	printf("\nEnter the iteration amount to be applied: ");
	scanf("%d", &iteration);
	
	k = 0, flag = 0;
	
	while(k < iteration && flag != size){
		
		for(i=0; i<size; i++){
			value = matrix[i][size];
			
			for(j=0; j<size; j++){
				
				if(j != i){
					value -= matrix[i][j] * x[j];
				}
			}
			
			x[i] = value / matrix[i][i];
		}
		
		if(k>0){
			
			for(i=0; i<size; i++){
				
				if(former[i] == x[i]){
					flag++;
				}
			}
		}
		
		for(i=0; i<size; i++){
			former[i] = x[i];
		}
		
		if(k != iteration - 1 && flag != size){
			printf("\nITERATION %d\n", k + 1);
			
			for(i=0; i<size; i++){
				printf("--> x%d = %f\n", i + 1, x[i]);
			}
		}
		else{
			printf("\nITERATION %d (FOUND VALUES)\n", k + 1);
			
			for(i=0; i<size; i++){
				printf("--> x%d = %f\n", i + 1, x[i]);
			}
		}
		
		if(flag == size){
			printf("\nIteration stopped because values are found!\n");
		}
		
		k++;
	}
}

int main()
{
	int size;
	float matrix[N][N];
	
	printf("--> GAUSS-SEIDEL METHOD\n\n");
	
	printf("Enter the variable amount of the linear system of equations: ");
	scanf("%d", &size);
	
	readMatrix(matrix, size);
	
	printf("\nAugmented matrix of the system of linear equations you created:\n");
	printMatrix(matrix, size);
	
	gaussSeidel(matrix, size);
	
	getch();
	
	return 0;
}

