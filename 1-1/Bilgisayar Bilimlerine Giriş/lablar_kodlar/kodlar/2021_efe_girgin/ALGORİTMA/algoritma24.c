#include <stdio.h>
int main(){
	int N,i;
	printf("lutfen dizilerin boyutunu giriniz\n");
	scanf("%d",&N);
	

	int C[i];
	int A[N];
	int B[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		scanf("%d",&B[i]);
	}
	
	
	for(i=0;i<N;i++){
		C[i]=A[i]*B[i];
	}
	for(i=0;i<N;i++){
		printf("%d",C[i]);
	}
	return 0;
}
//deneme ve compile yapildi
//0 ve 1lerden olusan 2 diziden bir c dizisinin olusmasi,ikisi de 1 ise 1,biri sýfýr digeri 1 ise 0 olacak sekildedir.bu islemi yapan algoritma ve programi.
//sayfa 19
//kod calýsýyor
