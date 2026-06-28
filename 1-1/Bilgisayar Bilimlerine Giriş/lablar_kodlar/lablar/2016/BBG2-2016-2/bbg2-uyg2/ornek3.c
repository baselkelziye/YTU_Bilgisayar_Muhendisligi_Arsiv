#include <stdio.h>

int main(){
	int i, j, tmp, mat[100][100], n;

	printf("n degerini giriniz: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("mat[%d][%d]: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(i = 0; i < n/2; i++){
		for(j = 0; j < n; j++){
			tmp = mat[j][i];
			mat[j][i] = mat[j][n-i-1];
			mat[j][n-i-1] = tmp;
		}
	}

	printf("\n\nSonuclar...\n");
	for (i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}



	return 0;
}
