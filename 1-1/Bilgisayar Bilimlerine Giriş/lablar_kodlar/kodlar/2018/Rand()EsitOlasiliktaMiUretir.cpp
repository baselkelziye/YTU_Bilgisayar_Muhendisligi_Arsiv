#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int zar,F[7] = { 0 };//DÝZÝYÝ ÝLK ÖNCE BÝ SIFIRLA, ÝNDÝSLERDE BÝR SIKINTI ÇIKMASIN DÝYE ***7***
	
	srand( time( NULL));
	
	for( int i = 1; i <= 600; i++ ){
		zar = rand() % 6 + 1;
		F[zar]++;
	}
	
	for( int i = 1; i <= 6; i++){//7 HÜCRELÝ DÝZÝNÝN 6 HÜCRESÝNÝ YAZDIRIYORUM
		printf("%d |",F[i]);
	}
	/*
	for( int i = 1; i <= 6; i++){//Histogram çizmek için
		printf("%d ",i);
		for(int j = 1; j <= F[i]; j++){
			printf("*");
		}
		printf("\n");
	}
	*/
	
	
	
	
	
	
	
	return 0;
}
