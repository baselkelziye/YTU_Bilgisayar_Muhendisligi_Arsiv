#include <stdio.h>
int main(){
	int N,M,i,j;
	printf("lutfen matrisin satir ve sutun sayilarini giriniz\n");
	scanf("%d %d",&N,&M);
	int A[N][M];
	int trans[M][N];
	
	printf("A matrixini giriniz\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("A[%d][%d]=",i+1,j+1);
			scanf("%d",&A[i][j]);
		}
	}
	printf("girilen A matrixi:\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%d",A[i][j]);
			if(j==M-1){
				printf("\n");
			}
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			trans[j][i]=A[i][j];
		}
	}
	printf("matrisin transpozesi:\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%d",trans[i][j]);
			if(j==N-1){
				printf("\n");
			}
			
		}
	}
	return 0;
}
//Program to Find the Transpose of a Matrix
