#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Max-Heapify: dizi[], düğüm i, toplam eleman sayısı N
void max_heapify(int dizi[], int i, int N)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest;

    if (left <= N && dizi[left] > dizi[i])
        largest = left;
    else
        largest = i;

    if (right <= N && dizi[right] > dizi[largest])
        largest = right;

    if (largest != i)
    {
        swap(&dizi[i], &dizi[largest]);
        max_heapify(dizi, largest, N); // Rekürsif olarak devam et
    }
}

// Max-Heap oluşturma
void build_maxheap(int dizi[], int N)
{
    for (int i = N / 2; i >= 1; i--)
    {
        max_heapify(dizi, i, N);
    }
}

// Diziyi ekrana yazdır
void printArray(int dizi[], int N)
{
    for (int i = 1; i <= N; i++)
    {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

int main()
{
    // 0. index kullanılmaz, heap 1-index ile başlar
    int dizi[] = {0, 6, 14, 5, 8, 2, 9, 1}; // Başında 0 eklenmiş
    int N = 7;

    printf("İlk dizi: ");
    printArray(dizi, N);

    build_maxheap(dizi, N);

    printf("Max-Heap dizisi: ");
    printArray(dizi, N);

    return 0;
}
