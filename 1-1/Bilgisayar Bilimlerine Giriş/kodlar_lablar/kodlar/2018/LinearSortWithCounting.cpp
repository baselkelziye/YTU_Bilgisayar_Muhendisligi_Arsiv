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
			if(A[i] > A[j]){         //<(k���kt�r) olsayd� b�y�kten k����e s�ralam�� olurduk...
				count = count + 1;
			}
		}
		B[count] = A[i];//en k���k eleman, hi�bir elemandan b�y�k olmad��� i�in direkt 0. indise atan�yor...
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
