#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta4_codes
cc -o test hafta4_2_eg_mat_comprs.c 
*/

int** compress_matrix(int ** mat, int n, int m, int *ptr_non0s){
	int i,j,k=0;
	int **rtrn_mat; // we will return this object as an row*3 Matrix 

	// before allocating a location for the matrix to be returned,
	// we need to first check the non-0 elements in the matrix:
	*ptr_non0s=0;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if(mat[i][j]>0)
				(*ptr_non0s)++;

	rtrn_mat=(int**)malloc((*ptr_non0s)*sizeof(int*));

	// we need to first check the non-0 elements in the matrix:
	for(i=0; i<(*ptr_non0s); i++)
		rtrn_mat[i]=(int*)malloc(3*sizeof(int));

	k=0;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if(mat[i][j]>0){
				rtrn_mat[k][0]=i; 
				rtrn_mat[k][1]=j; 
				rtrn_mat[k][2]=mat[i][j]; 
				k++;
			}
	return rtrn_mat;
}

int main() {
	int **mat;
	int n,m, i,j, non0s;
	int ** compressed_mat;

	printf("Please enter number of rows ");scanf("%d", &n);
	printf("Please enter number of columns ");scanf("%d", &m);

	mat = (int **) malloc( n * sizeof(int *) );
	for(i = 0; i < n; i++)  
		mat[i] = (int *)malloc(m * sizeof(int) ); 
	
	for(i = 0; i < n; i++){
		printf("Enter the elements in the %d-th row of your matrix :\n", i+1);
		for(j = 0; j < m; j++)	
			scanf("%d", &mat[i][j]); 
	}		
	printf("This is the sparse matrix that you entered: \n");
	for(i = 0; i < n; i++){
		for(int j = 0; j < m; j++)	
			printf("%d\t", mat[i][j]); 
		printf("\n");
	}
	printf("We will compress this matrix now: \n");

	compressed_mat = compress_matrix(mat, n, m, &non0s);
	
	printf("These are the elements of the compressed matrix: \n");
	printf("row\tcol\tvalue\n");
	for(i = 0; i < non0s; i++){
		for(int j = 0; j < 3; j++)	
			printf("%d\t", compressed_mat[i][j]); 
		printf("\n");
	}
	return 0;
}
