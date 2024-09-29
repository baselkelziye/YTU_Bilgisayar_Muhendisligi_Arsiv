#include <stdio.h>
int main(){
	int N,say,k,i;
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	int A[N];
	int C[N/2];
	say=0;
	k=0;

	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<N;i=i+2){
	
		C[k]=(A[i]+A[i+1])/2;
		k=k+1;
	}
	for(i=0;i<N/2;i++){
		printf("c'nin %d.elemani=%d\n",i+1,C[i]);
	}
	return 0;
	
}
//deneme ve compile yapildi
//50 elemanli bir dizinin 1.ve 2. elemanlari toplaminin yarisi baska bir dizinin ilk elemani,3.ve4.elemanlari toplaminin yarýsý2.elemani...seklindedir.
//bu islemi yapan algoritma ve programi.
//sayfa 52
//1.soru
//kod calýsýyor
