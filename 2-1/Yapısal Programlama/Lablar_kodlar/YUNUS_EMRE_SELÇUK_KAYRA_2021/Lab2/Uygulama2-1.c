#include<stdio.h>
#include<stdlib.h>

int main(){
	enum Palet{
	Siyah=0, 
	Gri=128, 
	Beyaz=255
	};
	
	int N, M, i, j;
	int **resim, **histogram, tmp;
	int arr_[N][M];

	
	printf("Lutfen resim boyutlarini satir ve sutun olarak siraiyla giriniz: \n");
	scanf("%d %d", &N, &M);
	
	resim = (int**)malloc(N*sizeof(int*));
	if(resim == NULL){
		printf("Bellekte yer ayrilamadi!!");
		return -1;
	}
	
	for(i = 0; i < N; i++)
	{
		resim[i] = (int*)malloc(M*sizeof(int));
		if(resim[i] == NULL){
			printf("Bellekte yer ayrilamadi!!");
			return -1;
		}
	}
	
	for(i = 0; i < N; i++)
	{
		printf("%d. satir elemanlarini giriniz: \n", i);
		for(j = 0; j < M; j++)
		{
			scanf("%d", &resim[i][j]);
		}
	}
	
	
	printf("Resim Matrisi: \n");
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			printf("%3d   ", resim[i][j]);
		}
		printf("\n");
	}
	
	histogram = (int**)calloc(3, sizeof(int*));
	if(histogram == NULL){
		printf("Bellekte yer ayrilamadi!!");
		return -1;
	}
	
	for(i = 0; i <= 2; i++)
	{
		histogram[i] = (int*)calloc(2, sizeof(int));
	}
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < M; j++)
		{
			tmp = resim[i][j];
			histogram[(tmp/127)][0] = tmp; // Pikselin deðerini atadýk.
			histogram[(tmp/127)][1]++; // Frekansýný 1 arttýrdýk.
		}
	}
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("%4d   ", histogram[i][j]);
		}
		printf("\n");
	}

	
	for(i = 0; i < N; i++)
		free(resim[i]);
	free(resim);
	
	
	for(i = 0; i < 3; i++)
		free(histogram[i]);
	free(histogram);	
	
	return 0;
}
