#include <stdio.h>
#include <stdlib.h>
#include "lab1Header.h"
#define N 5
#define LIMIT 999999


int main(int argc, char *argv[]) {
	
	int i;
	int arr[N]={33,44,34,44,45};
	int min1=LIMIT,min2=LIMIT,max1=-LIMIT,max2=-LIMIT;

	for(i=0;i<N;i++){
		if(buyukMu(arr[i],max2)==1){
			max2=arr[i];
		}
		if(buyukMu(arr[i],max1)==1){
			max2=max1;
			max1=arr[i];
		}if(buyukMu(arr[i],min2)==-1){
			min2=arr[i];
		}if(buyukMu(arr[i],min1)==-1){
			min2=min1;
			min1=arr[i];
		}
	}
	
	printf("Dizinin orjinal hali: ");
	for(i=0;i<N;i++){
		printf("%d ",arr[i]);
	}
	
	printf("\n");
	
	printf("Kucuk ikili: %d  %d \n",min1,min2);
	printf("Buyuk ikili: %d  %d \n",max1,max2);
	printf("Buyuk ve kucuk ikilinin toplami: %d",(min1+min2+max1+max2));
	
	return 0;
}
