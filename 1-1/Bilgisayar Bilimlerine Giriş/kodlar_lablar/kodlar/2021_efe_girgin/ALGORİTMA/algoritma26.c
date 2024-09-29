#include <stdio.h>
int main(){
	int N,i;
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	int C[N];
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N-1;i++){
		C[i]=A[i]-A[i+1];
	}
	for(i=0;i<N-1;i++){
		printf("%d\t",C[i]);
	}
	return 0;
}


//denendi ve compile edildi
//bir dizinin elemanlari arasindaki farki baska bir diziye yazdiran algoritma ve programi
//sayfa 20
//1.soru
//kod calýsýyor
