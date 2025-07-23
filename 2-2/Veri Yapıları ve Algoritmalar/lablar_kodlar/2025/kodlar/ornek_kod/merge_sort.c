#include <stdio.h>
#define N 10

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

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int data[N] = {2, 5, 3, 10, 9, 1, 8, 1, 4, 15};

    int flag = 0;
    int i, j, t;
    int idx = 0;
    int min;

    

    print_array(data, N);
    return 0;
}
