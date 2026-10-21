#include <stdio.h>

#define MAX_SIZE 100

void Karsilastir(int scores[], int N, int *minIndex1, int *minIndex2, int *minIndex3, int *maxIndex1, int *maxIndex2, int *maxIndex3) {
    int i;

    *minIndex1 = 100;
    *minIndex2 = 100;
    *minIndex3 = 100;
    *maxIndex1 = 0;
    *maxIndex2 = 0;
    *maxIndex3 = 0;

    for (i = 0; i < N; i++) {
        if (scores[i] < *minIndex1) {
            *minIndex3 = *minIndex2;
            *minIndex2 = *minIndex1;
            *minIndex1 = scores[i];
        } else if (scores[i] < *minIndex2) {
            *minIndex3 = *minIndex2;
            *minIndex2 = scores[i];
        } else if (scores[i] < *minIndex3) {
            *minIndex3 = scores[i];
        }

        if (scores[i] > *maxIndex1) {
            *maxIndex3 = *maxIndex2;
            *maxIndex2 = *maxIndex1;
            *maxIndex1 = scores[i];
        } else if (scores[i] > *maxIndex2) {
            *maxIndex3 = *maxIndex2;
            *maxIndex2 = scores[i];
        } else if (scores[i] > *maxIndex3) {
            *maxIndex3 = scores[i];
        }
    }
}

int main() {
    int scores[MAX_SIZE];
    int N, i;
     int minIndex1, minIndex2, minIndex3, maxIndex1, maxIndex2, maxIndex3;

    do {
        printf("Dizinin eleman sayisini 6 veya daha buyuk bir sayi olarak giriniz: ");
        scanf("%d", &N);
    } while (N < 6);

    for (i = 0; i < N; i++) {
        printf("Ogrenci notunu giriniz: ");
        scanf("%d", &scores[i]);
    }

    Karsilastir(scores, N, &minIndex1, &minIndex2, &minIndex3, &maxIndex1, &maxIndex2, &maxIndex3);

    // En düsük notlar
    printf("En dusuk notlara sahip ogrenciler:\n");
    printf("Not: %d\n", minIndex1);
    printf("Not: %d\n", minIndex2);
    printf("Not: %d\n", minIndex3);

    int lowestSum = minIndex1 + minIndex2 + minIndex3;

    // En yüksek notlar
    printf("En yuksek notlara sahip ogrenciler:\n");
    printf("Not: %d\n", maxIndex1);
    printf("Not: %d\n", maxIndex2);
    printf("Not: %d\n", maxIndex3);

    int highestSum = maxIndex1 + maxIndex2 + maxIndex3;

    printf("En dusuk notlarin toplami: %d\n", lowestSum);
    printf("En yuksek notlarin toplami: %d\n", highestSum);

    return 0;
}
