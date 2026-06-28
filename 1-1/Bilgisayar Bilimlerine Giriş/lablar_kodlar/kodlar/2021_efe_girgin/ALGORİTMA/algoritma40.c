#include <stdio.h>
int main(){
	int i,sonuc,j,k,N,M,K;
	printf("1.matrisin satir sayisini ve sutun sayisini giriniz\n");
	scanf("%d %d",&N,&M);
	printf("2.matrisin satir ve sutun sayisini giriniz\n");
	scanf("%d %d",&M,&K);
	
	int A[N][M];
	int B[M][K];
	int C[N][K];
	printf("1.matrisi giriniz\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			scanf("%d",&A[i][j]);
		}
	}
	printf("2.matrisi giriniz\n");
	for(i=0;i<M;i++){
		for(j=0;j<K;j++){
			scanf("%d",&B[i][j]);
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<K;j++){
			sonuc=0;
			for(k=0;k<M;k++){
				sonuc=sonuc+A[i][k]*B[k][j];
				
			}
			C[i][j]=sonuc;
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<K;j++){
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
	
}


//deneme ve compile yapildi
//iki matrisin carpimi algoritmasi ve programi
//sayfa 35
//1.soru
//kod calýsýyor
