#include<stdio.h>
#define mMAX 20


void get_matrix(int N, int matrix[][mMAX]);
void print_matrix(int N, int matrix[][mMAX]);


int main(){
	
	int matrix[mMAX][mMAX];
	int N, i = 0, j = 0;
	printf("Please enter N(it should be greater than 0):  ");
	do{
		scanf("%d",&N);
	}while(N<=0);
	
	
	get_matrix(N, matrix);
	
	print_matrix(N, matrix);
	
	road_finder(N, matrix, i, j);
	
	
	
	return 0;
}

void get_matrix(int N, int matrix[][mMAX]){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("matrix[%d][%d]: ",i,j);
			if((i==N-1) && (j==N-1)){
				printf("this value has to be 1: ");
				do{
					scanf("%d",&matrix[i][j]);
				}while(matrix[i][j] != 1);
				
			}else{
				scanf("%d",&matrix[i][j]);
			}
			
		}
	}
}

void print_matrix(int N, int matrix[][mMAX]){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}	
}


int road_finder(int N, int matrix[][mMAX], int i,int j){
	
	int counter=0;
	
	if((i==N-1) && (j == N-1)){
		printf("(%d,%d)",i,j);
		printf("\n");
		printf("(%d,%d)",0,0);
		return;
	}
	
	
	if (matrix[i][j] != 0) {
    	printf("(%d,%d),",i,j);
	}
		
	if ((j < N - 1) && (matrix[i][j] != 0)) {
    	road_finder(N, matrix, i, j + 1);
	}
	if ((i < N - 1) && (matrix[i][j] != 0)) {
  		road_finder(N, matrix, i + 1, j);
    }
    /*
    if ((j < N - 1) && (matrix[i][j] != 0)) {
    	road_finder(N, matrix, i + 1, j);
	}
	else if ((i < N - 1) && (matrix[i][j] != 0)) {
  		road_finder(N, matrix, i, j + 1);
    }
	
	*/	
}
