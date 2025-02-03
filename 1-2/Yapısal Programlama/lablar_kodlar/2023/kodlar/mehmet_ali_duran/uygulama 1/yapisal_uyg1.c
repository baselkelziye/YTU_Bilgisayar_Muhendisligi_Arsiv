#include <stdio.h>

// Fonksiyon: Diziyi sýrala (Bubble Sort algoritmasý)
void bubbleSort(int arr[], int n) {
    int temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fonksiyon: Dizideki bir elemanýn kaç kez bulunduðunu say
int countElement(int arr[], int n, int target) {
    int count = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

void findElementIndices(int arr[], int n, int target, int indices[]) {
    int count = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            indices[count] = i;
            count++;
        }
    }
}

int main() {
    int n;
    printf("Dizinin boyutunu girin: ");
    scanf("%d", &n);

    int arr[n];
    printf("Dizi elemanlarini girin:\n");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    int target;
    int indices[n];
    int count;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Diziyi Sirala\n");
        printf("2. Girilen elemanýn kaç kez gectigini bul\n");
        printf("3. Elemanin Indekslerini Bul\n");
        printf("4. Cikis\n");
        printf("Seciminizi girin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(arr, n);
                printf("Siralanan Dizi: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 2:
                printf("Aranan elemani girin: ");
                scanf("%d", &target);
                count = countElement(arr, n, target);
                printf("%d, dizide %d kez bulunuyor.\n", target, count);
                break;
            case 3:
                printf("Aranan elemani girin: ");
                scanf("%d", &target);
                count = countElement(arr, n, target);
                if (count > 0) {
                    findElementIndices(arr, n, target, indices);
                    printf("%d, dizideki indeksler: ", target);
                    for (i = 0; i < count; i++) {
                        printf("%d ", indices[i]);
                    }
                    printf("\n");
                } else {
                    printf("%d, dizide bulunmuyor.\n");
                }
                break;
            case 4:
                printf("Programdan cikiliyor.\n");
                return 0;
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
                break;
        }
    }

    return 0;
}
