#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int** makeMat(int N);
int** expandMat(int N, int **mat);
void enumerateMat(int N,int **mat);
void sumMat(int cols,int rows,int **mat);
void printMat(int cols,int rows,int **mat);
void freeMat(int cols,int rows,int **mat);
int main() {
	int N , **mat ,i,j;
	
	srand(time(NULL));
	printf("N: ");
	scanf("%d",&N);
	int cols = N;
	int rows = N;
	cols++;
	rows++;
	mat = makeMat(N);
	mat = expandMat(N,mat);
	
	enumerateMat(N,mat);
	
//	printMat(cols,rows,mat);
	printf("\n\n");
	printf("\n\n");
	sumMat(cols,rows,mat);
	printMat(cols,rows,mat);
	freeMat(cols,rows,mat);
	
	return 0;
}
int** makeMat(int N){
	int **mat,i,j;
	
	mat = (int**)malloc(N*sizeof(int*));
	for(i=0;i<N;i++){
		*(mat+i) = (int*)malloc(N*sizeof(int));
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			*( *(mat+i) +j ) = j;//(rand()%100) +1;
		}
	}
	
	
	return mat;
}
int** expandMat(int N, int **mat){
	int i,j;
	int cols = N;
	int rows = N;
	cols++;
	
	for(i=0;i<(rows);i++){
		mat[i] = realloc(mat[i],(cols)*sizeof(int));
		if (mat[i] == NULL) {
            exit(1);
        }
	}
	rows++;
	mat = realloc(mat,sizeof(int*)*rows);
	mat[rows-1] = malloc(sizeof(int) * cols); 
	
	return mat;
}
void enumerateMat(int N,int **mat){
	int i,j;
	int cols = N;
	int rows = N;
	cols++;
	rows++;
	for(i=0;i<(rows);i++){
		for(j=0;j<(cols);j++){
			if((i == rows-1) || (j == cols-1)){
				*( *(mat+i) +j ) = 0;
			}
			else{
				*( *(mat+i) +j ) = (rand()%100) +1;
			}
		}
	}
	printf("Enumarate\n\n");
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("%3d  ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
void sumMat(int cols,int rows,int **mat){
	int i,j;
	int sum=0;
	int rowSum=0;
	int colSum=0;
	for(i=0;i<(rows-1);i++){
		for(j=0;j<(cols-1);j++){
			sum = sum+ mat[i][j];
		}
		mat[i][cols-1] = sum;
		rowSum = rowSum + sum;
		sum = 0;
	}
	for(i=0;i<(cols-1);i++){
		for(j=0;j<(rows-1);j++){
			sum = sum+ mat[j][i];
		}
		mat[rows-1][i] = sum;
		colSum = colSum + sum;
		sum = 0;
	}
	mat[rows-1][cols-1] = rowSum + colSum;
}
void printMat(int cols,int rows,int **mat){
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("%3d  ",mat[i][j]);
		}
		printf("\n");
	}
}
void freeMat(int cols,int rows,int **mat){
	int i;
	for(i=0;i<rows;i++){
		free(mat[i]);
	}
	free(mat);
}



