#include <stdio.h>
#include <stdlib.h>
int main(){
	int M, N; 
	int **matris;
	int i,j;

	printf("Satir ve sutun sayisi gir");
	scanf("%d %d",&M, &N);
	
    matris = (int**) malloc(sizeof(int*)*M);
    if(matris == NULL ) {
    		printf("Hata"); return -1;
    }
    for(i=0;i<M;i++){
    	matris[i] = (int*) malloc(sizeof(int)*N);
    	if(matris[i] == NULL ) {
    		printf("Hata"); return -1;
		}
	}
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			matris[i][j] = 5; 
			//*(*(matris+i) + j ) = 5; 
		}
	}
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%d ",*(*(matris+i)+j));
			//*(*(matris+i) + j ) = 5; 
		}
		printf("\n");
	}
	
	//memory leak 
	// 1D array : int *dizi = malloc(sizeof(int*)*N); free(dizi);
	
	// 2D array
	 for(i=0;i<M;i++){
	 	free(matris[i]);
	 }
	 
	 free(matris);
	
	return 0;
}	
