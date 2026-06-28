#include <stdio.h>
int main(){
	int N,i;
	printf("dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	int A[N];
		
	
	 A[0]=3;
	 A[1]=4;
	
	for(i=2;i<N;i++){
		A[i]=A[i-1]+A[i-2]+1;
	}
	for(i=0;i<N;i++){
		printf("%d\t",A[i]);
	}
	return 0;
}
//verilen bir dizinin her bir elemani kendinden 
//önce gelen elemanlarin toplaminin bir fazlasina eþittir.
//1. ve 2.elemani verilen bir dizinin ilk 20 elemaninin
// degerlerini bulup diziye yerlestiren algoritma ve programi
//sayfa 42
//1.soru
//kod calisiyor
