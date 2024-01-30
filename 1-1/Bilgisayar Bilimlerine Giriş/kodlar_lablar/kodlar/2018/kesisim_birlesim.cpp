#include <stdio.h>
#include <stdlib.h>

int main(){
	int N,M,i,j,k,l,z;
	printf("dizi boyutu N : ");scanf("%d",&N);
	printf("dizi boyutu M : ");scanf("%d",&M);
	int A[N],B[M],D[N+M],C[N+M];
	for(int i = 1; i <= N; i++){
		printf("%d. eleman ",i);
		scanf("%d",&A[i]);
	}
	for(int i = 1; i <= M; i++){
		printf("%d. eleman ",i);
		scanf("%d",&B[i]);
	}
	i = 1, j = 1, l = 1, k = 1;
	for(int i = 1; i < N+M; i++)
		D[i] = -99;
	
	for(z = 1; z <= N+M; z++){
		if(A[i] < B[j] || A[i] == B[j]){
			D[l] = A[i];
			i++;
		}
		else{
			D[l] = B[j];
			j++;
		}
		if(D[l-1] == D[l]){
			C[k] = D[l];
			k++;
		}
		else
			l++;
	}
	for(int i = 1; i <= k; i++){//SINIR DEGERLERINDE VAR BI SEYLER KONTROL ET
		printf("%d ",C[i]);
	}
	printf(" <--C dizisi\n");
	for(int i = 1; i <= l-1; i++){
		printf("%d ",D[i]);
	}
	printf(" <--D dizisi\n");
	
	
	
	
	
	return 0;
}
