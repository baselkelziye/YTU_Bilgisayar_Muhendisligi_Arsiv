#include <stdio.h>
int main(){
	int N,i,BYK;
	printf("dizinin boyutunu giriniz \n");
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	BYK=A[0];
	for(i=1;i<N;i++){
		if(A[i]>BYK){
			BYK=A[i];
		}
		
	}
	printf("%d",BYK);
	return 0;
}
//deneme ve compile yapildi
//bir dizinin en buyuk elemanini bulan algoritma ve programi
//sayfa 11
//kod çalýþýyor
