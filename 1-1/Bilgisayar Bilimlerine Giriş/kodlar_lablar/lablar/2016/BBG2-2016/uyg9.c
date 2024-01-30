#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void RastGele(int*, int*, int);

int main(){
	srand(time(NULL));
	int i, n = 5;
	int dizi[] = {10, 20, 30, 40, 50};
	int rast[10];
	
	RastGele(dizi, rast, n);
	printf("\nDizi: ");
	for(i = 0; i < n; i++)
		printf("%d ", dizi[i]);
	printf("\nRast: ");
	for(i = 0; i < n; i++)
		printf("%d ", rast[i]);
	
	return 0;
}

void RastGele(int* ar1, int* ar2, int y){
	int i;
	for (i = 0; i < y; i++)
		ar2[i] = rand() % ar1[i] + 1;	
}













