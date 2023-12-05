#include <stdio.h>
#include <stdlib.h>

int main(void){
	int N,i,j;
	int** matris,**matris2;
	printf("Lutfen matris boyutunu giriniz");
	scanf("%d",&N);
	matris = (int**)malloc(N*sizeof(int*));
	if(matris == NULL){
		printf("Bellekte yer ayrilamadi!!");
		return -1;
	}
	for(i = 0; i < N; i++)
	{
		matris[i] = (int*)malloc(N*sizeof(int));
		if(matris[i] == NULL){
			printf("Bellekte yer ayrilamadi!!");
			return -1;
		}
	}
	N++;
	
	
	matris2 = (int**)realloc(matris,N*sizeof(int*));
	if(matris2 == NULL){
		printf("Bellekte yer ayrilamadi!!");
		return -1;
	}
	matris=matris2;
	matris2[N]=(int*)malloc(N*sizeof(int));
	for(i = 0; i < N; i++)
	{
		matris2[i] = (int*)realloc(matris[i],N*sizeof(int));
		if(matris2[i] == NULL){
			printf("Bellekte yer ayrilamadi!!");
			return -1;
		}
		matris[i]=matris2[i];
	}
	for(i=0;i<N-1;i++){
		for(j=0;j<N-1;j++){
			matris[i][j]=rand()%99+1;
		}
	}
	for(i=0;i<N;i++){
		matris[i][N]=0;
		matris[N][i]=0;
	}
		for(i=0;i<N-1;i++){
			for(j=0;j<N-1;j++){
		matris[i][N]+=matris[i][j];
		matris[N][j]+=matris[i][j];
	}}
	for(i=0;i<N-1;i++){
		matris[N][N]+=matris[i][N];
		matris[N][N]+=matris[N][i];
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d\t",matris[i][j]);
		}
		printf("\n");
	}
		for(i = 0; i < N; i++)
		free(matris[i]);
		free(matris);
	return 0;
}
