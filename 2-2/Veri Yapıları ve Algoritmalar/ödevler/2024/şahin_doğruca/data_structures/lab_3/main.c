#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// matrix unique elemanlardan oluşuyor mu kontrolunu yapar.
int check_for_repeat(int **matrix, int N, int *ql, int num)
{
    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < ql[i]; j++)
            if (matrix[i][j] == num)
                return 1;

    return 0;
}

void getInfos(int *N_ref, int *M_ref, int ***matrix_ref, int **ql_ref)
{
    int i, j, select, num;
    srand(time(NULL));
    printf("please enter row count (N) : ");
    scanf("%d", N_ref);

    printf("please enter column count (M) : ");
    scanf("%d", M_ref);

    // matrix'i ve öncelikli kuyrukların uzunluklarını tutan diziyi oluşturur
    (*matrix_ref) = (int **)malloc(sizeof(int *) * (*N_ref));
    for (i = 0; i < (*N_ref); i++)
        (*matrix_ref)[i] = (int *)malloc(sizeof(int) * (*M_ref));

    (*ql_ref) = (int *)malloc(sizeof(int) * (*N_ref));

    printf("1- enter the values\n2- get random values\nselect option : ");
    scanf("%d", &select);

    while (select != 1 && select != 2)
    {
        printf("select value is invalid. Please enter again (1 or 2) : ");
        scanf("%d", &select);
    }

    // öncelikli kuyrukların uzunluklarını ve elemanlarını alır
    for (i = 0; i < (*N_ref); i++)
    {
        printf("please enter length of queue %d : ", i + 1);
        scanf("%d", &((*ql_ref)[i]));

        // öncelikli kuyruk uzunluğu M'den büyük olamaz
        while ((*ql_ref)[i] > (*M_ref))
        {
            printf("Queue length can't be greater than M. Please enter a valid length : ");
            scanf("%d", &((*ql_ref)[i]));
        }

        if (select == 1)
        {
            for (j = 0; j < (*ql_ref)[i]; j++)
            {
                printf("please enter %d. element of %d. queue : ", j + 1, i + 1);
                scanf("%d", &num);

                // girilen değer 0'dan büyük olmalıdır. Kontrolü bur da yapılıyor.
                while (num < 0)
                {
                    printf("elements must be greater than zero. Please enter a valid value : ");
                    scanf("%d", &num);
                }

                while (check_for_repeat(*matrix_ref, *N_ref, *ql_ref, num))
                {
                    printf("elements must be unique. Please enter a valid value : ");
                    scanf("%d", &num);
                }

                (*matrix_ref)[i][j] = num;
            }
        }
        else if (select == 2)
        {
            for (j = 0; j < (*ql_ref)[i]; j++)
            {
                do
                    num = rand() % 100;
                while (check_for_repeat(*matrix_ref, *N_ref, *ql_ref, num));

                (*matrix_ref)[i][j] = num;
            }
        }

        // eğer öncelikli kuyruk uzunluğu M'den küçükse, kalan elemanları -1 ile doldurur
        for (j = (*ql_ref)[i]; j < (*M_ref); j++)
            (*matrix_ref)[i][j] = -1;
    }
}

// matrix'i yazdırır
void printMatrix(int **matrix, int N, int M)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            // eğer sayı 100'den büyük ise 2 birimlik yere sığmayacağı için kendi uzunluğu kadar yazdırıyoruz.
            if (matrix[i][j] == -1 || matrix[i][j] >= 100)
                printf("%d ", matrix[i][j]);
            else
                printf("%.2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// bellek temizleme işlemleri
void freeMemory(int ***matrix_ref, int **ql_ref, int N, int **cq_ref)
{
    int i;

    for (i = 0; i < N; i++)
        free((*matrix_ref)[i]);
    free(*matrix_ref);

    free(*cq_ref);
    free(*ql_ref);
}

// heapify için kullanılan swap fonksiyonu, iki pointer alır ve değerlerini değiştirir
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heapify fonksiyonu, bir array ve index alır, array'i heap haline getirir
void heapify(int **array_ref, int i, int N)
{
    int largest = i; // En büyük elemanın indis'ini saklayacak değişken

    int left_child = 2 * i + 1;  // Sol çocuk düğümü indis'ini hesapla
    int right_child = 2 * i + 2; // Sağ çocuk düğümün indis'ini hesapla

    if (left_child < N && (*array_ref)[left_child] > (*array_ref)[largest])
        largest = left_child;

    if (right_child < N && (*array_ref)[right_child] > (*array_ref)[largest])
        largest = right_child;

    // En büyük değer kök değilse, yani kök değerden büyük bir çocuk varsa
    if (largest != i)
    {
        swap(&((*array_ref)[i]), &((*array_ref)[largest]));

        // Değişiklik yapıldıktan sonra, etkilenen alt ağaçta heapify işlemi tekrar çağrılır
        heapify(array_ref, largest, N);
    }
}

// build_max_heap fonksiyonu, bir array ve uzunluk alır, array'i heap haline getirir
void build_max_heap(int **array_ref, int N)
{
    int i;

    // N/2'den 0'a kadar olan indisler de heapify işlemi uygular, çünkü N/2'den sonraki indisler yapraklardır.
    for (i = N / 2 - 1; i >= 0; i--)
        heapify(array_ref, i, N);
}

// max_heap_matrix fonksiyonu, bir matrix ve uzunluklar array'i alır, matris'deki her bir satırı heap haline getirir
void max_heap_matrix(int ***matrix_ref, int N, int *ql)
{
    int i;

    for (i = 0; i < N; i++)
        build_max_heap(&((*matrix_ref)[i]), ql[i]);
}

// delete_heap_max fonksiyonu, bir array ve uzunluk alır, array'in en büyük elemanını siler ve heap haline getirir
void delete_heap_max(int **array_ref, int *N_ref)
{
    swap(&(*array_ref)[0], &(*array_ref)[(*N_ref) - 1]);

    // silinen elemanın yerine -1 koyar
    (*array_ref)[(*N_ref) - 1] = -1;

    // array'in uzunluğunu bir azaltır
    (*N_ref) = (*N_ref) - 1;

    // heap haline getirir
    build_max_heap(array_ref, (*N_ref));
}

// selectMax fonksiyonu, bir matrix, uzunluk ve cleared_queues array'i alır, matris'deki en büyük elemanı seçer ve
// cleared_queues array'ine ekler
int selectMax(int **matrix, int N, int **cq_ref, int *cq_idx)
{
    int i, j, max = -1, maxIndex = -1, flag = 1;

    for (i = 0; i < N; i++)
    {
        // eğer satırın ilk elemanı -1 değilse, en büyük elemanı seçer
        if (matrix[i][0] > max)
        {
            max = matrix[i][0];
            maxIndex = i;
        }

        // eğer satırın ilk elemanı -1 ise, cleared_queues array'ine ekler
        if (matrix[i][0] == -1)
        {
            flag = 1;
            // cleared_queues array'inde aynı eleman varsa eklemez
            for (j = 0; j <= (*cq_idx); j++)
                if ((*cq_ref)[j] == i + 1)
                    flag = 0;

            // eğer önce den array'e eklenmemiş ise cleared_queues array'ine ekler
            if (flag == 1)
                (*cq_ref)[(*cq_idx)++] = i + 1;
        }
    }

    return maxIndex;
}

// deleteMax fonksiyonu, bir matrix, uzunluk array'i, N ve M alır,
// teker teker matris'deki en büyük elemanı siler ve silinen her bir elemanın satırını tekrar heap haline getirir
void deleteMax(int ***matrix_ref, int **ql_ref, int N, int M, int **cq_ref, int *cq_idx)
{

    int maxIndex = -1, max, i;
    // cleared_queues array'ini oluşturur
    (*cq_ref) = (int *)malloc(sizeof(int) * N);

    do
    {
        // en büyük elemanı seçer, ve indis'ini alır
        maxIndex = selectMax(*matrix_ref, N, cq_ref, cq_idx);

        // eğer en büyük eleman varsa siler, eğer maxIndex -1 ise tüm elemanlar silinmiş demektir
        if (maxIndex != -1)
        {
            // silinen max elemanı alır
            max = (*matrix_ref)[maxIndex][0];

            // elemanı siler ve heap haline getirir
            delete_heap_max(&((*matrix_ref)[maxIndex]), &(*ql_ref)[maxIndex]);

            // silinen elemandan sonra matrix'i yazdırır
            printf("Matrix after deleted %d : \n", max);
            printMatrix(*matrix_ref, N, M);
        }
    } while (maxIndex != -1 || (*cq_idx) < N);

    // tüm elemanlar silinmiş ise cleared_queues array'ini yazdırır
    printf("Cleared queues nums : \n");
    for (i = 0; i < N; i++)
        printf("%d ", (*cq_ref)[i]);
}

int main()
{

    int N = 0, M = 0, cq_index = 0;
    int **matrix, *queueLengths, *cleared_queues;

    // eğer değerleri terminal'den almak istiyorsan bu fonksiyonu kullan
    getInfos(&N, &M, &matrix, &queueLengths);

    // eğer hazır değerler ile birlikte başlamak istiyorsan bu fonksiyonu kullan
    // testInfos(&N, &M, &matrix, &queueLengths);

    printf("Starter Matrix : \n");
    // değerleri aldıktan sonra oluşan ilk matrisi yazdırır
    printMatrix(matrix, N, M);

    // matris'deki tüm satırlara max_heap_build fonksiyonunu uygular
    max_heap_matrix(&matrix, N, queueLengths);

    // matris'deki tüm satırlar heap olduktan sonraki halini yazdırır
    printf("Max-heaped Matrix : \n");
    printMatrix(matrix, N, M);

    // tek tek en büyük sayıyı siler, ve en büyük değeri silinen satıra heapify işlemini uygular
    deleteMax(&matrix, &queueLengths, N, M, &cleared_queues, &cq_index);

    // bellek temizleme işlemleri
    freeMemory(&matrix, &queueLengths, N, &cleared_queues);
    return 0;
}