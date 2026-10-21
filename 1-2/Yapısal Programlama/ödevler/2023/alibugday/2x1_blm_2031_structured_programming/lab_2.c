#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int Fonk_satir_topla(int **dz,int n,int num);

int Fonk_sutun_topla(int **dz,int n,int num);

int main() {
	int i,j,N,satir=0,sutun=0;
	
	printf("n sayýsýný giriniz");
    scanf("%d",&N);
    
    int **matris;
    
    matris=(int**)malloc(N*sizeof(int*));
	if(matris == NULL)  {
		printf("Bellek ayrýlamadý...\n");
		return -1;
	}
	
	for(i=0;i<N;i++){
		matris[i]=(int*)malloc(N*sizeof(int));
		if(matris[i] == NULL)  {
		printf("Bellek ayrýlamadý...\n");
		return -1;
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matris[i][j]=rand()%101+1;//1-100 arasýnda	
		}
	}
	
	printf("\nmatris :\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%3d  ",matris[i][j]);
		printf("\n");
	}
	
	
	matris=(int**)realloc(matris,(N+1)*sizeof(int*));
	for(i=0;i<N;i++){
		matris[i]=(int*)realloc(matris[i],(N+1)*sizeof(int));
		if(matris[i] == NULL)  {
		printf("Bellek ayrýlamadý...\n");
		return -1;
		}
	}
	matris[N]=(int*)malloc((N+1)*sizeof(int));
	
	
	
	
	
	for(i=0;i<N;i++)
	{
		satir=Fonk_satir_topla(matris,N,i);
		matris[i][N]=satir;
	}
	
	for(i=0;i<N;i++)
	{
		sutun=Fonk_sutun_topla(matris,N,i);
		matris[N][i]=sutun;
	}
	
	satir=Fonk_satir_topla(matris,N,N);
	sutun=Fonk_sutun_topla(matris,N,N);
	
	matris[N][N]=satir+sutun;
	
	printf("\nmatris :\n");
	for(i=0;i<N+1;i++)
	{
		for(j=0;j<N+1;j++)
			printf("%3d  ",matris[i][j]);
		printf("\n");
	}
	
	
	
	for(i=0;i<N;i++)
		free(matris[i]);
	free(matris);
	
	
	return 0;
}



int Fonk_satir_topla(int **dz,int n,int num){
	int toplam=0,i;
	
	for (i=0;i<n;i++){
		toplam+=dz[num][i];	
		
	}
	
	return toplam;
}

int Fonk_sutun_topla(int **dz,int n,int num){
	int toplam=0,i;
	
	for (i=0;i<n;i++){
		toplam+=dz[i][num];	
	}
	
	return toplam;
}




