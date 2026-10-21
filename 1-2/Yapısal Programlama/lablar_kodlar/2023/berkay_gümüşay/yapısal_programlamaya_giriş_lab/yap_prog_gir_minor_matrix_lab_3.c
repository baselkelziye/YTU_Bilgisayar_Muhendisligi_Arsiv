#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 200
void randMatrix(int matrix[SIZE][SIZE]){
	srand(time(0));
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			matrix[i][j] = rand() % 10;
		}
	}	
}
void printMatrix(int matrixRand[SIZE][SIZE]){
	int i,j;
	printf(" Matrix : \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%2d  ",matrixRand[i][j]); 
		}
		printf("\n");
	}
}
int detRes(int matrix[SIZE][SIZE] ,int i ,int j){
	int detresult , k , t , count;
	int det[4];
	for(k=0;k<3;k++){
		for(t=0;t<3;t++){
			if((k != i) && (t != j)){
				det[count] = matrix[k][t];
				count++;
			}
		}
	}
	detresult  = (det[0] * det[3]) - (det[1] * det[2]);
	return detresult;
}
int minorMatrix(int matrix[SIZE][SIZE]){
	int i,j,k,t;
	int detRes;
	int det[4];
	int count=0;
	int minorMatrix[SIZE][SIZE];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			count=0;
			for(k=0;k<3;k++){
				for(t=0;t<3;t++){
					if((k != i) && (t != j)){
						det[count] = matrix[k][t];
						count++;
					}
				}
			}
			minorMatrix[i][j] = (det[0] * det[3]) - (det[1] * det[2]);
			printf("%3d ",minorMatrix[i][j] );
		}
		printf("\n");
	}
}
int recursiveMinor(int matrix[SIZE][SIZE] , int i , int j){
	
	int  res; 
	int counter = 0;
	while (counter != 9){
		if((j<3)){
			res = detRes(matrix,i,j);
			printf("%2d ",res);
			j++;
			counter++;
			return recursiveMinor(matrix, i ,j);
					// BU FONKSÝYONDA RECURSÝVE OLARAK MÝNÖR BULMAYI DENEDÝM FAKAT SONSUZA KADAR ÝLK MÝNÖRÜ YAZDITRIYORDU ONDAN DOLAYI KULLANMADIM
		}
		else{
			printf("\n");
			i++;
			j = 0;
			counter++;
			return recursiveMinor(matrix, i ,j);;
		}
		
		
		
	
	}
	return 0;
	
}
int main(int argc, char *argv[]) {
	int matrix2[SIZE][SIZE] , i , j;
	randMatrix(matrix2);
	printMatrix(matrix2);
	printf("\n\nMinor Matrix: \n\n");
//	minorMatrix(matrix2);
	recursiveMinor(matrix2, 0 , 0);
	return 0;
}
