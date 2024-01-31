#include <stdio.h>
#include <stdlib.h>
/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta3_codes
cc -o test hafta3_6_alloc.c 
*/

int main() {
	int **mat;
	int n,m, i,j;
	printf("Please enter number of rows ");scanf("%d", &n);
	printf("Please enter number of columns ");scanf("%d", &m);
	mat = (int **) malloc( n * sizeof(int *) );
	if(mat == NULL)  {
		printf("Can not allocate memory for the array...\n");
		return -1;
	}
	for(i = 0; i < n; i++)  
		mat[i] = (int *)malloc(m * sizeof(int) ); // 
	
	for(i = 0; i < n; i++){
		printf("Enter the elements in the %d-th row of your matrix :\n", i+1);
		for(j = 0; j < m; j++)	
			scanf("%d", &mat[i][j]); // scanf("%d", (mat[i] + j)); // scanf("%d", (*(mat+i) + j));
	}		
	
	printf("These are the elements of the matrix: \n");
	for(i = 0; i < n; i++){
		for(int j = 0; j < m; j++)	
			printf("%d\t", mat[i][j]); // printf("%d\t", *(mat[i] + j)); // printf("%d\t", *(*(mat+i) + j));
		printf("\n");
	}
	return 0;
}


/*
int main() {
	int *mat;
	int n,m, i,j;
	printf("Please enter number of rows ");scanf("%d", &n);
	printf("Please enter number of columns ");scanf("%d", &m);
	mat = (int *) malloc( n * m * sizeof(int) );
	if(mat == NULL)  {
		printf("Can not allocate memory for the array...\n");
		return -1;
	}

	for(i = 0; i < n; i++){
		printf("Enter the elements in the %d-th row of your matrix :\n", i+1);
		for(j = 0; j < m; j++)	
			scanf("%d", (mat+i*m + j)); // CANNOT USE ANY OF THOSE: scanf("%d", &mat[i][j]); // scanf("%d", (mat[i] + j)); // scanf("%d", (*(mat+i) + j));
	}		
	
	printf("These are the elements of the matrix: \n");
	for(i = 0; i < n; i++){
		for(int j = 0; j < m; j++)	
			printf("%d\t", *(mat+i*m + j)); // CANNOT USE ANY OF THOSE: printf("%d\t", mat[i][j]); // printf("%d\t", *(mat[i] + j)); // printf("%d\t", *(*(mat+i) + j));
		printf("\n");
	}
	return 0;
}

*/ 