#include <stdio.h>

#define N 10

// Renk kodları
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

void print_array_with_highlight(int *arr, int len, int highlighted_index)
{
    printf("[");
    for (int i = 0; i < len; i++)
    {
        if (i == highlighted_index)
            printf(RED "%d" RESET, arr[i]); // Eklenen eleman kırmızı
        else
            printf("%d", arr[i]);

        if (i < len - 1)
            printf(", ");
    }
    printf("]\n");
}

int main()
{
    int data[N] = {2, 5, 3, 10, 9, 1, 1, 5, 4, 15};

    int i = 1;
    int j = 0;
    int tmp = 0;

    printf(YELLOW "Başlangıç dizisi: " RESET);
    print_array_with_highlight(data, N, -1);
    printf("\n");

    for (i = 0; i < N; i++)
    {
        tmp = data[i];
        j = i - 1;

        printf(CYAN "\nAdım %d: tmp = %d\n" RESET, i + 1, tmp);

        while (j >= 0 && data[j] > tmp)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = tmp;

        printf(GREEN "Dizi güncellendi: " RESET);
        print_array_with_highlight(data, N, j + 1);
    }

    printf("\n" YELLOW "Sıralanmış dizi: " RESET);
    print_array_with_highlight(data, N, -1);

    return 0;
}
