#include <stdio.h>
#include <stdlib.h>

void getElements(int**, int, int);
int** multiply(int**,int,int,int**,int,int);
void printMatrix(int**,int,int);
void deallocateMatrix(int**,int);
int** allocateMatrix(int, int);
int main(){
	
	srand(time(NULL));
	int m, n, x, y;
	int **m1, **m2, **m3;
	m=3;
	n=4;
	x=4;
	y=2;
	
	m1=allocateMatrix(m,n);
	m2=allocateMatrix(x,y);
	getElements(m1,m,n);
	getElements(m2,x,y);
	m3=multiply(m1,m,n,m2,x,y);
	if(m1==NULL ||m2==NULL){
		printf("yer yok");
		return -1;
	}	
	if(m3==NULL){
		printf("Yer ayrýialamadý veya matris çarpýlamadý");
		return -2;
	}else{
		printMatrix(m1,m,n);
		printMatrix(m2,x,y);
		printMatrix(m3,m,y);
		deallocateMatrix(m1,m);
		deallocateMatrix(m2,x);
		deallocateMatrix(m3,m);	
	}
	
	return 0;
	
}

int** allocateMatrix(int m, int n){
	int** matrix;
	int i;
	matrix=(int**) calloc(m,sizeof(int*));
	if(matrix==NULL){
		return NULL;
	}
	for(i=0;i<m;i++){
		matrix[i]=(int*) calloc(n,sizeof(int));
		if(matrix[i]==NULL)
			return NULL;
	}
	return matrix;
}

void getElements(int** matris, int m, int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		//	printf("M[%d][%d]=",i,j);
			//scanf("%d",&matris[i][j]);
			matris[i][j]=rand()%5;
		}
	}
}

void printMatrix(int** matris, int m, int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("M[%d][%d]=%d ,",i,j,matris[i][j]);	
		}
		printf("\n");
	}
	printf("=====================================\n");
}

void deallocateMatrix(int** matris, int m){
	int i;
	for(i=0;i<m;i++){
		free(matris[i]);
	}
	free(matris);
}

int** multiply(int** m1,int A ,int B,int** m2,int C,int D){ // A x B X B x C
	int i, j,k;
	int** m3;
	if(B!=C){
		printf("Matrisler çarpilamaz");
		return NULL;
	}
	m3=allocateMatrix(A,D);
	if(m3!=NULL){
		for(i=0;i<A;i++){
			for(j=0;j<D;j++){
				for(k=0;k<B;k++){
					m3[i][j]+=m1[j][k]*m2[k][j];
				}
			}
		}
	}
	return m3;
}
