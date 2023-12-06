#include <stdio.h>
#include <stdlib.h>
int** allocateMatrix(int row, int *column);
void fillMatrix(int **matrix, int row, int *columnArray);
void printMatrix(int **matrix, int row, int *columnArray);
void allocateMatrixv2(int ***matrix,int row, int *column);
int main(){
	srand(time(NULL));
	int row;
	int *columnArray;
	int **matrix;
	printf("%p\n",matrix);
	int i;
	printf("Enter row"); scanf("%d",&row);
	columnArray = (int*) malloc(row*sizeof(int));
	for(i=0;i<row;i++){
		columnArray[i]= 1+rand()%10;
	}
    allocateMatrixv2(&matrix,row, columnArray);
	printf("%p\n",matrix); 
	//matrix = allocateMatrix(row,columnArray );
	fillMatrix(matrix,row, columnArray);
	printMatrix(matrix,row, columnArray);
	free(columnArray);
	for(i=0;i<row;i++)
	   free(matrix[i]);
	free(matrix);
	
	return 0;
}
void allocateMatrixv2(int ***matrix,int row, int *column){
	printf("%p\n",*matrix);
	int i;
	*matrix  = (int**) malloc(row*sizeof(int*));
	printf("1");
	for(i=0;i<row;i++){
		*(*matrix+i)= (int*) malloc(column[i]*sizeof(int));
		//printf("2"); 
		//if(*matrix[i]==NULL) //return NULL;
	}
	printf("%p\n",*matrix);
	//return matrix;
}


int** allocateMatrix(int row, int *column){
	int **matrix;
	int i;
	matrix  = (int**) malloc(row*sizeof(int*));
	for(i=0;i<row;i++){
		matrix[i] = (int*) malloc(column[i]*sizeof(int));
		if(matrix[i]==NULL) return NULL;
	}
	
	return matrix;
}

void fillMatrix(int **matrix, int row, int *columnArray){
	int i, j;
	for(i=0;i<row;i++){
		for(j=0;j<columnArray[i];j++){
			matrix[i][j] = rand()%10;
		}
	}
}

void printMatrix(int **matrix, int row, int *columnArray){
	int i, j;
	for(i=0;i<row;i++){
		for(j=0;j<columnArray[i];j++){
			printf("%3d",matrix[i][j]);
		}
		printf("\n");
	}
}
