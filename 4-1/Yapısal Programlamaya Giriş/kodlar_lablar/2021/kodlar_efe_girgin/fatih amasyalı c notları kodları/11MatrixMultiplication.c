#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void sequentialMult(int(*)[10],int(*)[10],int(*)[10],int,int,int);
int main() 
{
   	int A [10][10] = { {1,4}, {2,5}, {3,6} }; //M*K  3*2
   	int B [10][10] = { {8,7,6}, {5,4,3} };    //K*N  2*3
	int C [10][10];							  //M*N  3*3
   
   int M=3;
   int K=2;
   int N=3;
   
   int i,j;
       	
   sequentialMult(A,B,C,M,N,K);
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
         printf("%d ", C[i][j]);
      }
      printf("\n");
   }
}

void sequentialMult(int A[][10],int B[][10],int C[][10],int M, int N, int K)
{
	int sum=0;
	int i,j,k;
	for (i = 0; i < M; i++) {
      for (j = 0; j < N; j++) {
        for (k = 0; k < K; k++) {
          sum = sum + A[i][k]*B[k][j];
        }
        C[i][j] = sum;
        sum = 0;
      }
    }
}
