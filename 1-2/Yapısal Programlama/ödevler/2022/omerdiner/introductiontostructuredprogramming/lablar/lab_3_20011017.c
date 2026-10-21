#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 3

void generateRandomMatris(int A[][SIZE]);
void printMatris(int A[][SIZE]);
int calculateDeterminant(int A[][SIZE],int i,int j);
void minor(int M[SIZE][SIZE],int A[SIZE][SIZE],int i,int j);

int main(){
	srand(time(NULL));
	
	int A[SIZE][SIZE],M[SIZE][SIZE];
	generateRandomMatris(A);
	
	printMatris(A);
		
	minor(M,A,0,0);
	
	printf("\n");
	
    printMatris(M);
	
	
	return 0;
}

void minor(int M[SIZE][SIZE],int A[SIZE][SIZE],int i,int j){

	M[i][j]=calculateDeterminant(A,i,j);
		
	if(i==SIZE-1&&j==SIZE-1){
		return ;
	}else if(j<SIZE-1){
		minor(M,A,i,j+1);
	}else if(j==SIZE-1){
		j=0;
		minor(M,A,i+1,j);
	}
	
}
void generateRandomMatris(int A[SIZE][SIZE]){
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			A[i][j]=rand()%10;
		}
	}
}
void printMatris(int A[SIZE][SIZE]){
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			printf("%3d ",A[i][j]);
		}
		printf("\n");
	}
}

int calculateDeterminant(int A[][SIZE],int i,int j){
	
	int result;
	int tmp[SIZE-1][SIZE-1];
	int m=0,k=0,x,y;
	
	for(x=0;x<SIZE;x++){
		for(y=0;y<SIZE;y++){
			if(i!=x&&j!=y){
				tmp[m][k]=A[x][y];
				k++;
			}
			if(k==SIZE-1){
				k=0;
				m++;
			}
		
		}
	}
	
	result=tmp[0][0]*tmp[1][1]-tmp[0][1]*tmp[1][0];
	return result;
}

