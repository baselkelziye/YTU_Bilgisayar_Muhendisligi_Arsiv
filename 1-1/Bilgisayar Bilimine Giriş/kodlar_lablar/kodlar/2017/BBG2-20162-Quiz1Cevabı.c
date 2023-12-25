#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
	
	srand(time(NULL));
	int N, mat[10][10], rast[10][10], i, j, k, r;
	double ort = 0;
	printf("N: ");
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("mat[%d][%d]: ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
	}
	
	printf("\n");
	for(i = 0; i < N; i++){
		printf("\n");
		for(j = 0; j < N - 1; j++)
			printf("%d, ", mat[i][j]);
		printf("%d", mat[i][j]);
	}
	
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			rast[i][j] = rand() % (int) pow(N, 2) + 1;
	
	printf("\n\n");
	for(i = 0; i < N; i++){
		printf("\n");
		for(j = 0; j < N - 1; j++)
			printf("%d, ", rast[i][j]);
		printf("%d", rast[i][j]);
	}
	
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			ort += rast[i][j];
	ort = ort / pow(N, 2);
	
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			if(mat[i][j] < ort)
				mat[i][j] = 0;
	
	printf("\n\n");
	for(i = 0; i < N; i++){
		printf("\n");
		for(j = 0; j < N - 1; j++)
			printf("%d, ", mat[i][j]);
		printf("%d", mat[i][j]);
	}	
	
	r = 0;
	for(i = r; i < N - 1; i++){
		for(j = r; j < N; j++)
			mat[i+1][j] += mat[i][j];
			
		printf("\n\n");
		for(j = r+1; j < N; j++){
			printf("\n");
			for(k = r; k < N - 1; k++)
				printf("%d, ", mat[j][k]);
			printf("%d", mat[j][k]);
		}
		
		for(j = r; j < N; j++)
			mat[j][i+1] += mat[j][i];
		
		printf("\n\n");
		for(j = r+1; j < N; j++){
			printf("\n");
			for(k = r+1; k < N - 1; k++)
				printf("%d, ", mat[j][k]);
			printf("%d", mat[j][k]);
		}
		r++;
	}
			
	return 0;	
}
