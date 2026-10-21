#include <stdio.h>

int main(void) {
	
	int matris[100][100], filtre[100][100], sonucMatris[100][100], M, N, k, i, j, filtreToplami = 0, carpim, carpimlarinToplami = 0, x, y;
	
	printf("M giriniz: ");
	scanf("%d", &M);
		
	printf("N giriniz: ");
	scanf("%d", &N);
	
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			printf("ilk matrisin %d, %d indisteki elemani giriniz: ", i, j);
			scanf("%d", &matris[i][j]);
		}
	}
	
	printf("k giriniz: ");
	scanf("%d", &k);

	for (i = 0; i < k; i++) {
		for (j = 0; j < k; j++) {
			printf("filtre matrisinin %d, %d indisteki elemani giriniz: ", i, j);
			scanf("%d", &filtre[i][j]);
		}
	}
		
	for (i = 0; i < k; i++) {
		for (j = 0; j < k; j++) {
			filtreToplami += filtre[i][j];
		}
	}	
	
	for (x = 0; x < M - k + 1; x++) {
		for (y = 0; y < N - k + 1; y++) {
			carpimlarinToplami = 0;
			for (i = x; i < k + x; i++) {
				for (j = y; j < k + y; j++) {
					carpim = matris[i][j] * filtre[i - x][j - y];
					carpimlarinToplami += carpim;
				}
			}
			sonucMatris[x][y] = carpimlarinToplami / filtreToplami; 			
		}				
	}
	
	printf("\n");
	
	for (i = 0; i < M - k + 1; i++) {
		for (j = 0; j < N - k + 1; j++) {
			printf("%d\t", sonucMatris[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
