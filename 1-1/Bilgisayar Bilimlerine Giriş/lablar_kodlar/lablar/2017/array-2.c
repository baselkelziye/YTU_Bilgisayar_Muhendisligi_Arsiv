#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
	Read a value and write on console display for 1d array
*/
int main(){
	srand(time(NULL));
	int dizi[7]; 
	int i, maxyer;
	for(i=0; i<7; i++)
	{
		dizi[i]=rand()%100;
		printf("%4d",dizi[i]);
	}
	maxyer = 0;
	for(i=1;i<7;i++)
	{
		if(dizi[i]>dizi[maxyer])
			maxyer=i;
	}
	printf("\nBu dizideki en buyuk yer=%d, sayi= %d", maxyer, dizi[maxyer]);
	return 0;
}
