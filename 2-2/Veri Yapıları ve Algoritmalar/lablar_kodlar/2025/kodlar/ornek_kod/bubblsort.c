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

int main()
{
    int data[N] = {2, 5, 3, 10, 9, 1, 1, 5, 4, 15};

    int flag = 0;
    int i = 0;
    int tmp = 0;
    int swapped = 1;
    while (swapped != 0)
    {
        swapped = 0;
        for (i = 1; i < N; i++)
        {
            if (data[i - 1] > data[i])
            {
                print_array(data, N);
                tmp = data[i];
                data[i] = data[i - 1];
                data[i - 1] = tmp;
                swapped = 1;
                print_array(data, N);
            }
        }
    }

    print_array(data, N);
    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}