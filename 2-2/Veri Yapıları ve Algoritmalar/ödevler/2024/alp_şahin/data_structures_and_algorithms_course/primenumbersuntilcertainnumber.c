#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void primeNumbers(int N);

int main(){

    primeNumbers(100);
    return 0;
}

void primeNumbers(int N)
{
    int i=0;
    int *arr;
    int squareRoot;
    int j;
    arr=malloc(N*sizeof(int));
    for(i=1;i<=N;i=i+2)
    {
        arr[i]=0;
    }
    for(i=4;i<=N;i=i+2)
    {
        arr[i]=1;
    }
    squareRoot=sqrt(N);
    for(i=3;i<=squareRoot;i=i+2)
    {
        if(arr[i] == 0)
        {
            for(j=i*i;j<=N;j=j+2*i)
            {
                arr[j]=1;
            }
        }
    }
    arr[1]=1;
    arr[2]=0;
    for(i=0;i<=N;i++)
    {
        if(arr[i]==0)
        {
            printf("%d ",i);
        }
    }
}