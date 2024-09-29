#include <stdio.h>
int main(){
	int N,M,i,j,k;
	printf("lutfen N sayisi giriniz\n");
	scanf("%d",&N);
	
	printf("lutfen M sayisi giriniz\n");
	scanf("%d",&M);
	
	int A[M];
	int B[N];
	int C[N+M];
	
	for(j=0;j<M;j++){
		scanf("%d",&A[j]);
	}
	for(i=0;i<N;i++){
		scanf("%d",&B[i]);
	}
	i=1;
	j=1;
	for(k=0;k<M+N;k++){
		if(A[i]<B[j]){
			C[k]=A[i];
			i=i+1;
		}
		else{
			C[k]=B[j];
			j=j+3;
		}
		k++;
	}
	return 0;
}
//sayfa 1
