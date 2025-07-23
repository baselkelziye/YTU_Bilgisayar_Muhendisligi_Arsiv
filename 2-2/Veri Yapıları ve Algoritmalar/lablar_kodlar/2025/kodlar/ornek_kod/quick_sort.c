#include <stdio.h>
#define N 8

void print_array(int *arr, int len)
{
    printf("[");
    for (int i = 0; i < len; i++)
    {
        printf("%d", arr[i]);
        if (i < len - 1)
            printf(", "); // Son elemana kadar virgül koy
    }
    printf("]\n");
}

int main()
{

    int data[N] = {10, 2, 21, 79, 5, 7, 13, 11};

    int pivot = data[N - 1];


    return 0;
}

void quick_sort(){

}

void partition(){
    
}