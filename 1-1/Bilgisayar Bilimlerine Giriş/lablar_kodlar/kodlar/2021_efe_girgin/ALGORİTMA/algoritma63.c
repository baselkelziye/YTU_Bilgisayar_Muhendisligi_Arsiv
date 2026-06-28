#include <stdio.h>
int main(){
	int N,i,j;
	printf("matrislerin boyutunu giriniz\n");
	scanf("%d",&N);
	int A[N][N];
	int B[N][N];
	int C[N][N];
	printf("birinci matrisi giriniz\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&A[i][j]);
		}
	}
	printf("ikinci matrisi giriniz\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&B[i][j]);
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(A[i][j]>B[i][j]){
				C[i][j]=A[i][j];
			}
			else{
				C[i][j]=B[i][j];
			}    			
		}
		
	}
	printf("\nA matrisimiz\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	printf("\nB matrisimiz\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",B[i][j]);
		}
		printf("\n");
	}
	printf("\nC matrisimiz\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
	return 0;
}








//denendi ve compile edildi
//iki tane NxN lik matris veriliyor.bu matrisleri karsilastirarak ayni satir ve sutundaki elemanlardan buyuk olanýný ayný saytir ve numaradaki c matrisine yazdýran agoritma ve programi
//sayfa 52
//2.soru
//kod calýsýyor
