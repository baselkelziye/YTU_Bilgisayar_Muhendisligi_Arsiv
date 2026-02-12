#include <stdio.h>

int main() {
    int in, max, maxLen;
    int last = -1;
    int len = 1;

    printf("Renkleri girin (0-255), bitirmek icin -1 girin:\n");

    scanf("%d", &in);
    max = in;
    maxLen = 1;

    while (in != -1) {
        if (in == last && in >= 0 && in <= 255) {
            len++;
        } else {
            if (len > maxLen) {
                max = last;
                maxLen = len;
            }

            len = 1;
        }

        last = in;
        scanf("%d", &in);
    }

    if (len > maxLen) {
        max = last;
        maxLen = len;
    }

    if (max != -1) {
        printf("Renk:%d Uzunluk:%d\n", max, maxLen);
    } else {
        printf("Renk girisi yapilmadi.");
    }

    return 0;
}
