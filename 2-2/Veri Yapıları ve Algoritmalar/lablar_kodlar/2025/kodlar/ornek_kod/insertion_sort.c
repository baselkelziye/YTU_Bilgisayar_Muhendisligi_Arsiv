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

    int i = 1;
    int j = 0;
    int tmp = 0;

    for (i = 0; i < N; i++)
    {
        tmp = data[i];
        j = i - 1;

        while (data[j] > tmp && j >= 0)
        {

            data[j + 1] = data[j];
            j--;
            
        }
        data[j + 1] = tmp;
    }
    print_array(data, N);

    return 0;
}