#include <stdio.h>
int main(){
	int i,N,elde=0,top=0;
	printf("lutfen dizinin boyutunu giriniz \n");
	scanf("%d",&N);
	int A[N];
	int B[N];
	int C[N];
	printf("A dizisini giriniz:\n");
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	printf("B dizisini giriniz:\n");
	for(i=0;i<N;i++){
		scanf("%d",&B[i]);
	}
	for(i=N;i>=1;i--){
		top=A[i]+B[i]+elde;
		elde=top/2;
		C[i+1]=top%2;
	}
	C[0]=elde;
	for(i=0;i<=N+1;i++){
		printf("%d",C[i]);
	}
	return 0;
}








//
//ikilik düzende ayni basamakli iki sayi verildiginde bunlarin toplamini yapan algoritma ve programi
//sayfa 13
