/******************************************************************************

author:Zatona;
creat:20/12/2020 02:46;
finish_date:20/12/2020;
finish_time:03:26;
edited at: 20/12/2020 20:05 ;
subject:Matrix multiplication;

*******************************************************************************/
#include <stdio.h>
#define SIZE 100

int main(){
    int l, m, n, i, j, k, A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    
    printf("enter number of rows for first matrix:");
    scanf("%d", &l);
    printf("enter number of colomun for first matrix\n");
    printf("NOT:this will be the same number of rows for second matrix:");
    scanf("%d", &m);
    printf("enter number of colomun for second matrix:");
    scanf("%d", &n);
    
    for(i=0;i<l;i++){
        for(j=0;j<m;j++){
            printf("enter element A[%d][%d]:", i+1,j+1);
            //printf("enter element of %d. row and %d. colomun for first matrix:", i+1,j+1);
            scanf("%d", &A[i][j]);
        }    
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("enter element B[%d][%d]:", i+1,j+1);
            //printf("enter element of %d. row and %d. colomun for second matrix:", i+1,j+1);
            scanf("%d", &B[i][j]);
        }    
    }
    
    for(i=0;i<l;i++){
        for(j=0;j<n;j++){
            int sum=0;
            for(k=0;k<m;k++){
                sum += A[i][k]*B[k][j];
            }
            C[i][j]= sum;
        }
    }
    
    printf("result is:\n\t\t");
    for(i=0;i<l;i++){
        for(j=0;j<n;j++){
            printf("%d\t", C[i][j]);
        }
        printf("\n\n\t\t");
    }    

    return 0;
}

