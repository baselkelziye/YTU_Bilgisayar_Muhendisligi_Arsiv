#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//Ben initial degerlere gerek duymadan direkt for dongusu icerisnde baslattým.
int main() {
	int y,z,i,j,min=1000,deger,maliyet,en_kucuk=1001;
	
	ARISAYISI(y);
	ITERATION(z);
	
	for (i=0;i<z;i++){
		min=1000;
		printf("==========================================\n");
		printf("%d iteration:\n",i);
		
		for (j=0;j<y;j++){
			deger =rand()%31+1;//bir ile 30 arasýnda arndom deger urettim
			printf("%d\t",deger);
			maliyet=MALIYET(deger);
			if (min > maliyet){
				min=maliyet;
			}
		}
		printf("\nyukardaki iterasyonun en kucuk maliyeti %d\n",min);
		printf("==========================================");
		
		if (en_kucuk>min){
			en_kucuk=min;
		}
	}
	
	printf("\n\nen kucuk maliyet:%d",en_kucuk);
	
	return 0;
}
