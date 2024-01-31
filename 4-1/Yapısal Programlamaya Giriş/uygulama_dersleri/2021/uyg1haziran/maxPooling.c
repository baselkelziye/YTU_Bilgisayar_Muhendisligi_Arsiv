#include<stdio.h>
#include<time.h> 

#define N 8
#define M 8

void printMatrix(int mtrx[N][M], int rows, int cols){
	int i, j, k;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("%0.2d ", mtrx[i][j]); 
		}			
		printf("\n");
	}
}
	
void maxpooling(int mtrx[N][M], int row, int column, int pool[N][M])
{	
	int max,i,j;
	for(i=0;i<N;i=i+2){
		for(j=0;j<M;j=j+2){		
			max = mtrx[i][j];
			 if(mtrx[i+1][j]>max){
				max = mtrx[i+1][j];
			} if(mtrx[i][j+1]>max){
				max = mtrx[i][j+1];
			} if(mtrx[i+1][j+1]>max){
				max = mtrx[i+1][j+1];
			}
			pool[i/2][j/2] = max;
		}			
	}
}

void main()
{
    int i, j, k;
    int mtrx[N][M];
    int pool[N][M];
    srand(time(0)); 
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
				mtrx[i][j] = (rand() % 50); 
		}			
	}
	printMatrix(mtrx,N,M);
	printf("\n");
	maxpooling(mtrx, N, M, pool);
	printMatrix(pool,N/2,M/2);
}

