#include <stdio.h>
#define m 4
#define n 4

int main() {
    srand(time(NULL));
     int i,j,tmp;
    
    int matrix[m][n], matrixT[m][n];

    // Fill random values in the matrix
    for (  i = 0; i < m; i++ ) {
        for (  j = 0; j < n; j++ ) {
            matrix[i][j] = rand() % 20+1;
             
        }
          
    }

    // Print the matrix
    for ( i = 0; i < m; i++ ) {
        for (  j = 0; j < n; j++ ) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n 1. YOL SONUC\n");
    // 1. yol
    for(i=0;i<n;i++)  
	{
		for(j=0;j<m;j++)  
		{ 
			matrixT[j][n-1-i]=matrix[i][j];
			
			}
	}
	 for ( i = 0; i < n; i++ ) {
        for (  j = 0; j < m; j++ ) {
            printf("%3d ", matrixT[i][j]);
        }
        printf("\n");
    }
	
    //2 . YOl
    // Transpose the matrix
    for ( i = 0; i < m; i++ ) {
        for (  j = i + 1; j < n; j++ ) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    // Swap the columns
    for ( i = 0; i < m; i++ ) {
        for (  j = 0; j < n/2; j++ ) {
             tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n-1-j];
            matrix[i][n-1-j] = tmp;
        }
    }
   printf("\n 2. YOL SONUC\n");
    // Print the rotated matrix
     for ( i = 0; i < n; i++ ) {
        for (  j = 0; j < m; j++ ) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}
