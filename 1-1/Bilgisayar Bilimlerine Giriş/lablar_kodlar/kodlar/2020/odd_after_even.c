/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define SIZE 100

int main()
{
    int i, j, TMP;
    int n, A[SIZE];
    printf("elemen saysisni giriniz: ");
    scanf("%d", &n);
    
    for( i = 0 ; i < n ; i++ ){
        printf("dizinin %d.elmeni giriniz:", i+1);
        scanf("%d", &A[i]);
    }
    
    
    i=0;
    j=n-1;

    while(i < j){
        if( A[i] % 2 == 0){
            i++;
        }else{
            TMP     = A[i];
            A[i]    = A[j];
            A[j]    = TMP;
            j       = j-1;
        }
    }
    for( i = 0 ; i < n ; i++ ){
        //printf("A[%d]= %d\n", i+1, A[i]);
        printf("%d\n", A[i]);
    }

    return 0;
}
