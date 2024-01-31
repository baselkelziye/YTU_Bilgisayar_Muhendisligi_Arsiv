#include <stdio.h>
#include "menu.h"
int main(void){
	int a[POPULATION],i,j,k,max,min,b[iterasyon];
	printf("Populasyon sayisi = %d\n",POPULATION);
	printf("Iterasyon sayisi = %d\n",iterasyon);
	for(i=0;i<POPULATION;i++){
	a[i]=rand() % 25+1; 	
	}
	for(i=0;i<iterasyon;i++){
	max=a[0];
		for(k=0;k<POPULATION;k++){
	a[k]=rand() % 25+2; 	
	}
	printf("Initial population:\n");
	for(j=0;j<POPULATION;j++){
		printf("%d\t",a[j]);
		if(a[j]<max){
			max=a[j];
		}
	}
	b[i]=max;
	printf("\nBest cost in iteration %d = %d\n",i+1,maliyet(max));
	}
	max=b[0];
	for(i=1;i<iterasyon;i++){
		if(b[i]<max){
			max=b[i];
			min=i;
		}
	}
	printf("\nBest cost in iteration %d : %d value \n",min+1,maliyet(max));
	return 0;
}
