#include <stdio.h>

/*
 * Girilen input matrixin maksimum 128x128 olacagi varsayilmistir.
 *
 * Enes Genç
 *
 * GR2 - HİT
 */

int main(void) {
    int n,m, i, j;
    int mtx[128][128] = {0};
    int h[256] = {0};

    printf("N: ");
    scanf("%d", &n);

    printf("M: ");
    scanf("%d", &m);

    if (n > 128 || m > 128) {
        printf("Matris satir veya sutun sayisi en fazla 128 olabilir.");
        return 1;
    }

    printf("A:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int input;
            scanf("%d", &input);

            while (input < 0 || input > 255) {
                printf("Gecersiz veri, tekrar girin (0-255):");
                scanf("%d", &input);
            }

            mtx[i][j] = input;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int el = mtx[i][j];

            h[el]++;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int current = mtx[i][j];
            if (h[current] == 1) {
                printf("%d ", current);
            }
        }
    }
    printf("\n");

    return 0;
}
