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

// Girilen denklem sisteminin bilinmeyen sayisina uygunlugunu kontrol eden fonksiyon
int equationCheck(float matrix[N][N], int size)
{
	int i, j = 0, counter, error = 0, flag = 0;
	
	while(j < size && flag == 0){
		i = 0;
		counter = 0;
		
		while(i < size && flag == 0){
			
			if(matrix[i][j] == 0){
				counter++;
			}
			
			i++;
		}
		
		if(counter == i){
			flag = 1;
			error = 1;
		}
		
		j++;
	}
	
	return error;	
}

// Gauss Yok Etme Yontemi'nin adimlarini iceren fonksiyon
void gaussElimination(float matrix[N][N], int size)
{
	int a, i, j, k, y, n = 0, error, flag, iteration = 0;
	float temp, value, x[N];
	
	for(k=0; k<size-1; k++){
		a = k + 1;
		
		// Guncel sutunun kosegen degeri sifir ise satir degistirme islemleri yapilir.
		if(matrix[k][k] == 0){
			flag = 0;
			
			while(a < size && flag == 0){
				
				if(matrix[a][k] != 0){
					
					for(y=0; y<size+1; y++){
						temp = matrix[k][y];
						matrix[k][y] = matrix[a][y];
						matrix[a][y] = temp;
					}
					
					flag = 1;
					
					iteration++;
					printf("\nITERATION %d\n", iteration);
					printMatrix(matrix, size);
				}
				
				a++;
			}
		}
		
		// Guncel kosegen degerini 1 yapmak icin kosegenin bulundugu tum satir, kosegen degerine bolunur.
		if(matrix[n][n] != 1 && matrix[n][n] != 0){
			value = matrix[n][n];
				
			for(j=k; j<size+1; j++){
				matrix[n][j] = matrix[n][j] / value;
			}
					
			iteration++;
			printf("\nITERATION %d\n", iteration);
			printMatrix(matrix, size);
		}
		
		// Guncel kosegenin alt satirlarindaki elemanlarin degeri 0 yapilir.
		for(i=k+1; i<size; i++){
			value = 0;
			
			if(matrix[i][n] != 0 && matrix[n][n] != 0){
				value = matrix[i][n] / matrix[n][n];
			
				for(j=k; j<size+1; j++){
					matrix[i][j] -= matrix[n][j] * value;
				}
			}
		}
		
		if(value != 0){
			iteration++;
			printf("\nITERATION %d\n", iteration);
			printMatrix(matrix, size);
		}	
		
		n++;
	}
	
	// Kosegenin son elemani ve son denklem sonucu son elemanin degerine bolunur.
	if(matrix[size-1][size-1] != 1 && matrix[size-1][size-1] != 0){
		
		value = matrix[size-1][size-1];
		matrix[size-1][size-1] /= value;
		matrix[size-1][size] /= value;
		
		iteration++;
		printf("\nITERATION %d\n", iteration);
		printMatrix(matrix, size);
	}
	
	// Denklemin tutarliligi kontrol edilir.
	if(matrix[size-1][size-1] == 0 && matrix[size-1][size] != 0){
		printf("\nThe system of linear equations you created is inconsistent and has no solution.\n");
	}
	else if(matrix[size-1][size-1] == 0 && matrix[size-1][size] == 0){
		printf("\nThe system of linear equations you created is consistent and has infinite solutions.\n");
	}
	else if(matrix[size-2][size-2] == 0 && matrix[size-1][size-2] == 0){
		
		if(matrix[size-2][size] / matrix[size-2][size-1] == matrix[size-1][size] / matrix[size-1][size-1]){
			printf("\nThe system of linear equations you created is consistent and has infinite solutions.\n");
		}
		else{
			printf("\nThe system of linear equations you created is inconsistent and has no solution.\n");
		}
	}
	else{
		printf("\nThe system of linear equations you created is consistent and has only one solution.\n");
		
		// Son siradaki bilinmeyenin degeri bulunur.
		x[size-1] = matrix[size-1][size];
		
		// Diger bilinmeyenlerin degeri bulunur.
		for(i=size-2; i>=0; i--){
			j = size - 1;
		
			while(j > i){
				matrix[i][size] -= matrix[i][j] * x[j];
			
				j--;
			}
		
			if(matrix[i][i] != 0){
				x[i] = matrix[i][size] / matrix[i][i];
			}
		}
		
		printf("\nFound values:\n");
		
		for(i=0; i<size; i++){
			printf("x%d = %f\n", i + 1, x[i]);
		}
	}
}

int main()
{
	int i, j, size, error = 0;
	float matrix[N][N];
	
	printf("--> GAUSSIAN ELIMINATION METHOD\n\n");
	
	printf("Enter the variable amount of the linear system of equations: ");
	scanf("%d", &size);
	
	readMatrix(matrix, size);
	
	error = equationCheck(matrix, size);
	
	if(error == 1){
		int choice;
		
		system("cls");
		
		printf("Augmented matrix of the system of linear equations you created:\n");
		printMatrix(matrix, size);
			
		printf("\nThe system of linear equations you created is not compatible with the variable amount!\n");
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
		printf("\nAugmented matrix of the system of linear equations you created:\n");
		printMatrix(matrix, size);
	
		gaussElimination(matrix, size);
	}
	
	getch();
	
	return 0;
}

