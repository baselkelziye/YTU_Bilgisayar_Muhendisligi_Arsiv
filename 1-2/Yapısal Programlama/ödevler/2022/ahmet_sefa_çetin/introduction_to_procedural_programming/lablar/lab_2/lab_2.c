#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	int matris[100][100], i, j, n, skorA, skorB, temp, a;
	char devam;
	
	srand(time(NULL));
	
	do {
		
		skorA = 0;
		skorB = 0;
		
		printf("kare matrisin satir/sutun sayisini giriniz: ");
		scanf("%d", &n);
	
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				matris[i][j] = rand() % (n*n) + 1;
			}
		}
	
		printf("matris: \n");
		
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				printf("%d\t", matris[i][j]);
			}
			printf("\n");
		}
		
		for (a = 0; a < 6; a++) {
			
			printf("\n%d. adim: \n", a + 1);
			
			for (i = 0; i < n; i++) {
		        for (j = i; j < n; j++) {
		            temp = matris[i][j];
		            matris[i][j] = matris[j][i];
		            matris[j][i] = temp;
		        }
	    	}
			
			for (i = 0; i < n; i++) {
		        for (j = 0; j < n / 2; j++) {
		            temp = matris[i][j];
		            matris[i][j] = matris[i][n - j - 1];
		            matris[i][n - j - 1] = temp;
		        }
	    	}
			
			for (i = 0; i < n; i++) {
				if (a%2 == 0) {
					skorB += matris[n - 1][i];
				}
				else {
					skorA += matris[n - 1][i];
				}    
	    	}
	    	
	    	for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					printf("%d\t", matris[i][j]);
				}
				printf("\n");
			}
	    	
	    	printf("\nBetul: %d   Ayse: %d\n", skorB, skorA);
	    	
		}
		
		printf("\n");
		
		if (skorA > skorB) {
			printf("Ayse kazandi.");
		}
		else if (skorA < skorB) {
			printf("Betul kazandi.");
		}
		else {
			printf("Beraberlik.");
		}
		
		printf("\n");		
		
		printf("\ndevam etmek icin 'E' veya 'e' giriniz. Bitirmek icin baska bir sey giriniz: ");
		scanf(" %c", &devam);
		
	} while(devam == 'e' || devam == 'E');
	
	
	return 0;
}
