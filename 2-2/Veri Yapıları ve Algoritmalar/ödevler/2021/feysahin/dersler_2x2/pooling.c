#include<stdio.h>
#include<stdlib.h>

int **pooling(int m[][8]);

int main(){
	int bigPool[8][8] = {{34, 65, 87, 32, 45, 10, 21, 78}, 
							{73, 84, 78, 37, 49, 38, 98, 49},
							{74, 82, 74, 92, 81, 74, 93, 2},
							{37, 46, 47, 38, 92, 84, 71, 74},
							{74, 84, 73, 84, 72, 83, 74, 73},
							{83, 74, 83, 14, 25, 24, 53, 52},
							{14, 52, 24, 36, 41, 42, 53, 4},
							{72, 83, 72, 62, 60, 37, 27, 7}};
							
	int i, j;
	int **smallPool;
	smallPool = pooling(bigPool);
	
	printf("\n   big pool:\n\n");
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			printf("%d ", bigPool[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n   small pool:\n\n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%d ", smallPool[i][j]);
		}
		printf("\n");
	}
	free(smallPool);
	return 0;
}

int **pooling(int m[][8]){
	int i, j, k, max;
	int **smallPool = (int**)malloc(4*sizeof(int*));
	for(i=0; i<4; i++){
		smallPool[i] = (int*)malloc(4*sizeof(int));
	}
	
	for(i=0; i<8; i=i+2){
		for(j=0; j<8; j=j+2){
			max = m[i][j];
			if(m[i][j+1] > max){
				max = m[i][j+1];
			}
			if(m[i+1][j] > max){
				max = m[i+1][j];
			}
			if(m[i+1][j+1] > max){
				max = m[i+1][j+1];
			}
			smallPool[i/2][j/2] = max;
		}
	}
	return smallPool;
}
