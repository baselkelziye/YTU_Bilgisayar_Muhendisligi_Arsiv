#include <stdio.h>


int main() {
	int N;printf("Dizi boyutu : ");scanf("%d",&N);
	
	int A[N],B[N];
	
	for(int i = 0;i < N;i++){
		printf("%d. elemani giriniz : ",i+1);scanf("%d",&A[i]);
	}
			
	for(int i = 0; i < N; i++){
		int count = 0;
		for(int j = 0; j < N; j++){
			if(A[i] > A[j]){         //<(küçüktür) olsaydý büyükten küçüðe sýralamýþ olurduk...
				count = count + 1;
			}
		}
		B[count] = A[i];//en küçük eleman, hiçbir elemandan büyük olmadýðý için direkt 0. indise atanýyor...
	}
	
	for(int i = 0; i < N; i++){
		printf("%d |",A[i]);
	}
	printf("\n");
	for(int i = 0; i < N; i++){
		printf("%d |",B[i]);
	}
	
	
	
	return 0;
}
