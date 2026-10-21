#include<stdio.h>

int main(){
	int N=3, i, j, ders, devam=1;
	int A[N][2], matris[N][N];
	
	printf("Ders sayisini giriniz: ");
	scanf("%d", &N);
	
	for(i=0; i<N; i++){
		printf("\n%d. ders baslangic saati: ", i);
		scanf("%d", &A[i][0]);
		printf("\n%d. ders suresi: ", i);
		scanf("%d", &A[i][1]);
	}
	
	
	printf("\nDers tablosu: \n\n");
	for(i=0; i<N; i++){
		printf("%d  ", i);
		for(j=0; j<2; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			matris[i][j] = 0;
		}
	}
	
	for(i=0; i<N; i++){
		for(j=i+1; j<N; j++){
			if(A[i][0]+A[i][1] > A[j][0] && A[j][0]+A[j][1] > A[i][0]){
				matris[i][j] = 1;
				matris[j][i] = 1;
			}
		}
	}
	
	printf("\nKomsuluk Matrisi:\n\n");
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf("%d ", matris[i][j]);
		}
		printf("\n");
	}
	
	while(devam){
		printf("\nBir ders numarasi giriniz: ");
		scanf("%d", &ders);
		for(i=0; i<N; i++){
			if(matris[ders][i] == 1){
				printf("\ncakisan ders-> %d   baslangic: %d   sure: %d", i, A[i][0], A[i][1]);
			}
		}
		printf("\n\ndevam? (1/0): ");
		scanf("%d", &devam);
	}
	
	
	return 0;
}
