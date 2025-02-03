#include <stdio.h>
#include <stdlib.h>

void TransposeMat(int **mat, int **transposeM, int dim1, int dim2){
	int i, j;
	for (i=0; i<dim1; i++)
		for (j=0; j<dim2; j++)
			transposeM[j][i] = mat[i][j];
}

void PrintMat(int **mat, int dim1, int dim2){
	int i,j;
	for (i=0; i<dim1; i++){
	
		for (j=0; j<dim2; j++)
			printf("%d", mat[i][j]);
		printf("\n");
	}
}

int main(){
	int **mat, **transposeM;
	int n, m;
	int i, j, k, l;
	do {
		printf("Give row and column numbers of the matrix:\n");
		scanf("%d %d", &n, &m);
	} while((n>50) || (m>50));

	mat = (int **) calloc(n, sizeof(int*));
	for (i=0; i<n; i++)
		mat[i]=(int*) calloc(m, sizeof(int));
	
	printf("elementleri ver:\n");
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			scanf("%d", &mat[i][j]);
			
	transposeM = (int **) calloc(m, sizeof(int*));
	for (i=0; i<m; i++)
		transposeM[i]=(int*) calloc(n, sizeof(int));
		
	TransposeMat(mat, transposeM, n, m);
	PrintMat(transposeM, m, n);

	for (k = 0; k < n; k++)
	{
    free(mat[k]);
	}
	
	for (l = 0; l < n; l++)
	{
    free(transposeM[l]);
	}
	
	return 0;
}
