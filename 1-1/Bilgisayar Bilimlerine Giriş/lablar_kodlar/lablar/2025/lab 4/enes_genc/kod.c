#include <stdio.h>

/*
 * Matrisin en fazla 32x32 olacağı varsayılmıştır.
 *
 * Enes Genç
 *
 */

int main(void) {
    int mtx[32][32] = {0};
    int i, j, n;

    printf("N giriniz (1-32): ");
    scanf("%d", &n);

    while (n <= 0 || n > 32) {
        printf("N en az 1 en fazla 32 olmalıdır. N giriniz (1-32): ");
        scanf("%d", &n);
    }

    int x = 0;
    int y = 0;
    int goingUp = 1;

    for (i = 1; i <= n * n; i++) {
        mtx[y][x] = i;

        if (
            (x == n - 1 && goingUp) ||
            (y == n - 1 && !goingUp)
        ) {
            if (goingUp) y++;
            else x++;

            goingUp = !goingUp;
        } else if (
            (x == 0 && !goingUp) ||
            (y == 0 && goingUp)
        ) {
            if (goingUp) x++;
            else y++;

            goingUp = !goingUp;
        }
        else {
            if (goingUp) {
                y--;
                x++;
            }
            else {
                y++;
                x--;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d ", mtx[i][j]);
        }
        printf("\n");
    }

    return 0;
}
