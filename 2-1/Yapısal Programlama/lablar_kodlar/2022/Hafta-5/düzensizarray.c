#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int N;
	int i,j;
	int *dizi;
	int **matris;
	scanf("%d",&N);
	
	dizi=malloc(N*sizeof(int));
	for(i=0;i<N;i++){
		dizi[i]=rand()%N+1;
	}
	
	matris = (int**) calloc(N,sizeof(int*));
	for(i=0;i<N;i++){
		matris[i]= (int*) calloc(dizi[i],sizeof(int));
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<dizi[i];j++){
			matris[i][j]=rand()%5;
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<dizi[i];j++){
			printf("%3d",matris[i][j]);
		}
		printf("\n");
	}
	
}
