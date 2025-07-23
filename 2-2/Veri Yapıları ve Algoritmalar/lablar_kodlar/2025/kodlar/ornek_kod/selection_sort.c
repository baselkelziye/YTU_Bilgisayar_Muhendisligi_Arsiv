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

    for (i = 0; i < N; i++)
    {
        print_array(data, N);

        min = data[i];
        idx = i;

        for (j = i + 1; j < N; j++)
        {
            if (data[j] < min)
            {
                min = data[j];
                idx = j;
            }
        }
        swap(&data[i], &data[idx]);
    }

    print_array(data, N);
    return 0;
}
