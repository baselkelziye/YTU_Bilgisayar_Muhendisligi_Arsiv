#include <stdio.h>

void insertionSort(int *arr, int N);
int main()
{

    int arr[10]={1, 7, 8, 4, 3, 2, 9 ,0 ,5 ,6};
    insertionSort(arr,10);
    int i=0;
    for(i;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

void insertionSort(int *arr, int N)
{
    int i,j,tmp;
    int counter =0;
    for(i=1;i<N;i++)
    {
        tmp=arr[i];
        j=i-1;

        while(j>=0 && arr[j] > tmp)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=tmp;
    }
    
}