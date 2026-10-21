#include<stdio.h>

int main(){
	int i, j, sayac, h=0;
	//int atif[] = {30, 10, 5, 4, 3, 3, 2, 1}, N=8;
	int atif[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, N=10;
	
	for(i=0; i<N; i++){
		printf("%d ", atif[i]);
	}
	
	i=N;
	while(i>0 && sayac<i){
		i--;
		sayac=0;
		j=0;
		while(j<N && atif[j] > i){
			sayac++;
			j++;
		}
	}
	
	printf("\n\nh-index: %d", sayac);
	
	return 0;
}
