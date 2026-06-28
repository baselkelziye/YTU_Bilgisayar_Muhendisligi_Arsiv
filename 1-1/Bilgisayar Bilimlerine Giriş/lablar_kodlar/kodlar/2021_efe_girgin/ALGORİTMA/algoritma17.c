#include <stdio.h>
int main(){
	int N,k=0,i;
	printf("dizinin boyutunu giriniz \n");
	scanf("%d",&N);
	int A[N];
	int C[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	
	for(i=0;i<N;i++){
		if(A[i]%20==0){
			
			C[k]=A[i];
			k=k+1;
		}
	}

	for(i=0;i<k;i++){
		printf("hem 4 e hem 5 e bolunen sayilar=%d\n",C[i]);
	}
	return 0;
}
//deneme ve compile yapildi
//bir dizide hem 4 e hem 5 e bolunebilen sayilari bulan algoritma ve programi
//sayfa 14
//kod calýsýyor
