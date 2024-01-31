#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int N, i, j,colSum,rowSum;
	
	int **tablo;
	
	srand(time(NULL));
	
	printf("lutfen matris boyutunu giriniz:\n");
	scanf(" %d",&N);
	
	tablo = (int**)malloc(N*sizeof(int*));
	if(tablo == NULL){
		printf("Bellekte yer ayrilamadi!!");
		return -1;
	}
	
	for (i = 0; i< N; i++){
		tablo[i] = (int*)malloc(N*sizeof(int));
		if(tablo[i]==NULL){
			printf("Bellekte yer ayrilamadi");
			return -1;
		}
	}
	
	printf(" satir elemanlari random olarak giriliyor\n");
	
	for(i=0;i<N;i++){
	
		for(j=0;j<N;j++){
			tablo[i][j] = rand() % 99 + 1;
		}
	}
	
	printf("tablo matrisi:\n");
	
	for(i = 0; i<N ; i++){
		
		for(j = 0; j<N; j++){
			
			printf("%3d \t", tablo[i][j]);
		}
		printf("\n");
	}
	
	tablo = (int**)realloc(tablo,(N+1)*sizeof(int*));
	if(tablo == NULL){
		printf("Bellekte yer ayrilamadi!!");
		return -1;
	}
	
	for (i = 0; i< N; i++){
		tablo[i] = (int*)realloc(tablo[i], (N+1)*sizeof(int));
		if(tablo[i]==NULL){
			printf("Bellekte yer ayrilamadi");
			return -1;
		}
	}
	for (i = N; i< N+1; i++){
		tablo[i] = (int*)calloc((N+1),sizeof(int));
		if(tablo[i]==NULL){
			printf("Bellekte yer ayrilamadi");
			return -1;
		}
	}
	

	
	for(i=0; i<N;i++){
		colSum=0;
		rowSum=0;
		for(j=0;j<N;j++){
			rowSum+=tablo[i][j];
			colSum+=tablo[j][i];
		}
		tablo[i][N]=rowSum;
		tablo[N][i]=colSum;
		tablo[N][N]+=(rowSum+colSum);
	}
	
	printf("\n yeni matrisimiz N+1 boyutlu \n");
	for(i = 0; i<N+1 ; i++){
		
		for(j = 0; j<N+1; j++){
			
			printf("%3d \t", tablo[i][j]);
		}
		printf("\n");
	}
	
	
	for(i=0;i<N+1;i++){
		free(tablo[i]);
	}
	
	free(tablo);

}
