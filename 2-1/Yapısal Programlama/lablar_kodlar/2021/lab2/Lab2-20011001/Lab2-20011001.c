#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int **matris, N;
	int i, j;
	
	srand(time(NULL));
	
	printf("Kare matrisin boyutunu giriniz: ");
	scanf("%d",&N);
	
	matris = (int**)malloc(N*sizeof(int*));
	if(matris == NULL){
		printf("Yer musait degil\n");
		return -1;
	}
	for(i=0;i<N;i++){
		matris[i] = (int*)malloc(N*sizeof(int));
		if(matris[i] == NULL){
			printf("Yer musait degil\n");
			return -1;
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matris[i][j] = rand() % 100 +1;
		}
	}
	
	matris = (int**)realloc(matris, (N+1) * sizeof(int*));
	if(matris == NULL){
		printf("Yer musait degil\n");
		return -1;
	}
	for(i=0;i<(N+1);i++){
		matris[i] = (int*)realloc(matris[i], (N+1)*sizeof(int));
		if(matris[i] == NULL){
			printf("Yer musait degil\n");
			return -1;
		}
	}
	
	matris[N][N] = 0;
	for(i=0;i<N;i++){
		matris[i][N] = 0;
		matris[N][i] = 0;
		for(j=0;j<N;j++){
			matris[i][N]+=matris[i][j];
			matris[N][i]+=matris[j][i];
		}
		matris[N][N] += matris[i][N] + matris[N][i];
	}
	
	for(i=0;i<(N+1);i++){
		printf("\n");
		for(j=0;j<(N+1);j++){
			printf("%8d",matris[i][j]);
		}
	}
	
	for(i=0;i<(N+1);i++)
		free(matris[i]);
	free(matris);
	
	return 0;
}
