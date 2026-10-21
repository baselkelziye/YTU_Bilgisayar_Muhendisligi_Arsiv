#include <stdio.h>
#include <math.h>
#define N 10

/*
 UYARI!
 Gireceginiz 'x' degerleri arasindaki farklar esit olmalidir, yani bu sayi degerleri ardisik olmalidir.
 Algoritma, ardisik olmayan sayilar icin dogru calismayabilir.
*/

// 'x' ve 'y' degerlerini kullanicidan alan fonksiyon
void readValues(float values[N][N], int size)
{
	int i, j;
	
	for(i=0; i<size; i++){
		printf("x[%d]: ", i);
		scanf("%f", &values[i][0]);
		printf("y[%d]: ", i);
		scanf("%f", &values[i][1]);
		printf("\n");
	}
}

// Faktoriyel hesaplayan fonksiyon
int factorial(float number)
{
	int i, result = 1;
	
	if(number == 0 || number == 1){
		return 1;
	}
	else{
		
		for(i=2; i<=number; i++){
			result *= i;
		}
	}
	
	return result;
}

// Gregory-Newton Enterpolasyonunda kullanilan fonksiyon
float function(float values[N][N], float h, float x, int column)
{
	int a, b;
	float func = 0, x_value = 1;
	
	func += values[0][1];
	
	a = 1, b = 2;
	
	while(b < column){
		
		x_value *= x - values[a-1][0];
		
		func += x_value * values[a][b] / factorial(a) / pow(h, a);
		
		a++; 
		b++;
	}
	
	return func;
}

// Gregory-Newton Enterpolasyonu'nun adimlarini iceren fonksiyon
void gregoryNewton(float values[N][N], int size)
{
	int i, j, k, counter = 0, flag = 0;
	float h, x, functionValue;
	
	h = values[1][0] - values[0][0];
	
	j = 2;
	
	while(flag == 0){
		
		for(i=j-1; i<size; i++){
			values[i][j] = values[i][j-1] - values[i-1][j-1];
			
			if((i != size-1 || j != size) && (i >= j) && (values[i][j] - values[i-1][j] == 0)){
				counter++;
			}
			else if(i == size-1 && j == size){
				flag = 1;
			}
		}
		
		if(counter == size - j && flag == 0){
			flag = 1;
		}
		
		j++;
	}
	
	printf("\nDifference Table\n\n");
	
	for(i=1; i<j; i++){
		
		if(i == 1){
			printf("\t x");
			printf("\t\t y");
		}
		else{
			printf("\t\t D^%d", i-1);
		}
	}
	
	for(i=0; i<size; i++){
		printf("\n\n%d --->", i);
		
		for(k=0; k<j; k++){
			
			if(k >= 2 && i < k - 1){
				values[i][k] = 0;
				printf("\t |\t");
			}
			else{
				if(values[i][k] >= 0){
					printf("\t %f", values[i][k]);
				}
				else{
					printf("\t%f", values[i][k]);
				}
			}
		}
	}
	
	printf("\n\nEnter the 'x' value you want to calculate: ");
	scanf("%f", &x);
	
	functionValue = function(values, h, x, j);
	
	printf("\nCalculated function value: %f\n", functionValue);
}

int main()
{
	int size;
	float values[N][N];
	
	printf("---> GREGORY-NEWTON INTERPOLATION\n");
	
	printf("\nEnter the amount of 'x' and 'y' values: ");
	scanf("%d", &size);
	
	printf("\nEnter the 'x' and 'y' values respectively...\n");
	readValues(values, size);
	
	gregoryNewton(values, size);
	
	getch();
	
	return 0;
}

