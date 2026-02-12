#include <stdio.h>

/*
 * En fazla 32 elemanlik giris yapilacagi varsayilmistir.
 * 0 elemanlik dizinin gecersiz oldugu varsayilmistir.
 */
int main() {
    int n;
    int input[32];

    int i = 0;

    int leftRange[32] = {0};
    int rightRange[32] = {0};
    int bombCount = 0;

    int ok = 0;

    while (!ok) {
        ok = 1;
        bombCount = 0;

        printf("-Oyuna elverisli bir dizi icin dizi boyutunu ve elemanlari veriniz\n");
        scanf("%d", &n);

        if (n <= 0) {
            ok = 0;
        }

        int lastBombRightRange = -1;

        for (i = 0; i < n; i++) {
            int in;
            scanf("%d", &in);
            input[i] = in;

            if (in < 0) {
                int bombLeftRange = i + in; // in negatif oldugu icin range indislerini hesaplarken isaretler ters
                int bombRightRange = i - in;

                leftRange[bombCount] = bombLeftRange;
                rightRange[bombCount] = bombRightRange;

                bombCount++;

                if (lastBombRightRange != -1 && bombLeftRange <= lastBombRightRange) {
                    ok = 0;
                }

                lastBombRightRange = bombRightRange;
            }
        }

        if (!ok) {
            printf("-Oyuna elverisli degil\n");
        }
    }

    // onceki hatali inputun daha uzun olma ihtimaline karsi n'den sonrasini sifirlama
    // range arrayleri bomba sayisi kadar okundugu icin gerek yok
    for (; i < 32; i++) {
        input[i] = 0;
    }

    int currentBomb = 0;
    int out[32] = {0};
    int outIndex = 0;

    for (i = 0; i < n; i++) {
        if (i < leftRange[currentBomb] || i > rightRange[currentBomb] || !bombCount) { // hic bomba yoksa input aynen out'a kopyalanir
            out[outIndex] = input[i];
            outIndex++;
        }

        // sonuncuya kadar sadece bir sonrakinin left rangeine gore kontrol ediyoruz.
        // ustteki if'in sag kismi sadece son bombada currentBomb artmadigi icin kontrol edilmis oluyor.
        if (rightRange[currentBomb] <= i && bombCount > currentBomb) {
            currentBomb++;
        }
    }

    printf("-Bombalar patlatildi\n");

    if (outIndex == 0) {
        printf("-Hic eleman kalmadi\n");
    } else {
        for (i = 0; i < outIndex; i++) {
            printf("%d ", out[i]);
        }

        printf("\n");
    }

    return 0;
}
