#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int zar,F[7] = { 0 };//D�Z�Y� �LK �NCE B� SIFIRLA, �ND�SLERDE B�R SIKINTI �IKMASIN D�YE ***7***
	
	srand( time( NULL));
	
	for( int i = 1; i <= 600; i++ ){
		zar = rand() % 6 + 1;
		F[zar]++;
	}
	
	for( int i = 1; i <= 6; i++){//7 H�CREL� D�Z�N�N 6 H�CRES�N� YAZDIRIYORUM
		printf("%d |",F[i]);
	}
	/*
	for( int i = 1; i <= 6; i++){//Histogram �izmek i�in
		printf("%d ",i);
		for(int j = 1; j <= F[i]; j++){
			printf("*");
		}
		printf("\n");
	}
	*/
	
	
	
	
	
	
	
	return 0;
}
