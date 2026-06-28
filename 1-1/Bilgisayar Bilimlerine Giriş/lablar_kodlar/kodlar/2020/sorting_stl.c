/******************************************************************************

author:Zatona;
date:10/12/2020;
finish_time:10:00;
subject:sorting the serie of numbers from small to large;

*******************************************************************************/
#include <stdio.h>
#define SIZE 100

int main()
{
    int n,i,tmp,swapped=1;
    int A[SIZE];
    
    printf("enter the number of elements:");
    scanf("%d",&n);
    
    for (i=0;i<n;i++){
    printf("enter %d. element:",i+1);
    scanf("%d",&A[i]);
    }
    
    while(swapped==1){
        swapped=0;
        for (i=0;i<n-1;i++){
            if(A[i]>A[i+1]){
                tmp     =A[i];
                A[i]    =A[i+1];
                A[i+1]  =tmp;
                swapped =1;
            }
        }
    }
    
    for (i=0;i<n;i++){
    printf("%d\t",A[i]);
    
    }
    
    return 0;
}
