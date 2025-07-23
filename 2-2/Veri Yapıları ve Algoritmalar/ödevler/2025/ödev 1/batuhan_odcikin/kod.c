#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Değişkenlerin değerlerini yer değiştirir.
 *
 * @param a Birinci işaretçi
 * @param b İkinci işaretçi
 */
void swap(int *, int *);

/**
 * @brief Belirtilen aralıkta diziyi yazdırır.
 *
 * @param arr Yazdırılacak dizi
 * @param start Başlangıç indeksi
 * @param end Bitiş indeksi
 */
void printArray(int *, int, int);
/**
 * @brief Dosyadan anahtar ve kilit dizilerini okur.
 *
 * @param key Okunan anahtar dizisi (çift işaretçi)
 * @param lock Okunan kilit dizisi (çift işaretçi)
 * @param len Dizi uzunluğu (tek işaretçi)
 * @return int 0 başarı, 1 hata
 */
int read_txt(int **key, int **lock, int *len);

/**
 * @brief Pivot kullanarak diziyi bölümlere ayırır.
 *
 * @param arr Sıralanacak dizi
 * @param low Başlangıç indeksi
 * @param high Bitiş indeksi
 * @param pivot Kullanılacak pivot değeri
 * @return int Pivotun son indeksi
 */
int partition(int *, int, int, int);

/**
 * @brief Anahtar ve kilit dizilerini eşleşecek şekilde QuickSort algoritması ile sıralar.
 *
 * @param key Anahtar dizisi
 * @param lock Kilit dizisi
 * @param low Başlangıç indeksi
 * @param high Bitiş indeksi
 * @param step Rekürsif adım sayısı (sadece yazdırmak için)
 */
void quickSort(int *, int *, int, int, int);

/**
 * @brief Ana fonksiyon, dosyadan verileri okur, sıralama işlemini başlatır ve sonucu ekrana yazdırır.
 *
 * @return int Çıkış durumu (0: başarı)
 */
int main()
{
    int *key, *lock;
    int len, i;
    read_txt(&key, &lock, &len);

    printf("len: %d\n", len);

    printf("Key: ");
    for (i = 0; i < len; i++)
        printf("%d ", key[i]);

    printf("\nLock: ");
    for (i = 0; i < len; i++)
        printf("%d ", lock[i]);
    printf("\n ");

    quickSort(key, lock, 0, len - 1, 1);

    printf(" \nQucik Sorted Array: \n");
    printf("Keys:");
    printArray(key, 0, len - 1);
    printf("\nLocks:");
    printArray(lock, 0, len - 1);

    free(key);
    free(lock);
    return 0;
}

int partition(int *arr, int low, int high, int pivot)
{
    int border;
    int i = low;
    int j;
    // int pivot = arr[low];

    for (j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        // printArray(arr, low, high);
        // printf("i: %d, j: %d\n", i, j);
        // printf("\n");
    }

    swap(&arr[i], &arr[low]);
    // printf("\nSorted \n");
    printArray(arr, low, high);
    printf("\n");

    return i;
}

void quickSort(int *key, int *lock, int low, int high, int step)
{
    int pivot_idx;

    // printf("Locks: ");
    // printArray(lock, low, high);

    if (low < high)
    {
        printf("\n%d. Adim", step);
        printf("\nKeys: ");
        printArray(key, low, high);
        printf("\nLocks: ");
        printArray(lock, low, high);

        printf("\nPivot: %d\n", key[low]);
        pivot_idx = partition(key, low, high, key[low]);
        partition(lock, low, high, key[pivot_idx - 1]);

        quickSort(key, lock, low, pivot_idx - 1, step + 1);
        quickSort(key, lock, pivot_idx + 1, high, step + 1);
    }
}

void printArray(int *arr, int start, int end)
{
    int i;
    for (i = start; i <= end; i++)
    {
        printf("%d", arr[i]);
        if (i < end)
            printf("/");
    }
}

void swap(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int read_txt(int **key, int **lock, int *len)
{
    FILE *fp;
    int i = 0;

    fp = fopen("veri.txt", "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    fscanf(fp, "%d", len);

    *key = (int *)calloc(sizeof(int), *len);
    *lock = (int *)calloc(sizeof(int), *len);

    for (i = 0; i < *len; i++)
        fscanf(fp, "%d ", &(*key)[i]);

    for (i = 0; i < *len; i++)
        fscanf(fp, "%d ", &(*lock)[i]);

    fclose(fp);
    return 0;
}
