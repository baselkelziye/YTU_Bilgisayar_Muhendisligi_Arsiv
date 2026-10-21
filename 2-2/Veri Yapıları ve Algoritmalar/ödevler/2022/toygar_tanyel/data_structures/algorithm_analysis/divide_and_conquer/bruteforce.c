#include <stdio.h>

int main() {
    int a[] = {8, -30, 36, 2, -6, 52, 8, -1, -11, 10, 4}; //test1 (tek)
    //int a[] = {-8, 500, 1, -200, 100, 200, 0, 300, 600, -150, -40}; //test2 (tek)
    //int a[] = {3, 5, 100, 100, 1, 3, 2, 6}; //test3 (cift)
    //int a[] = {1, 1, -100, 1, -4, -4, -1, 1, 1, 3, 2}; //test4 (tek)
    //int a[] = {3, 5, 1, -10, 1, 3}; //test5 (cift)
    //int a[] = {3, 5, 1, -10, 2, 20}; //test6 (cift)

    int n = sizeof(a) / sizeof(a[0]);
    int i, j, max_sum = 0, sum = 0, hold_the_i, hold_the_j;

    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = i; j < n; j++) {
            sum += a[j];

            if (sum > max_sum) {
                hold_the_i = i;
                max_sum = sum;
                hold_the_j = j;
            }
        }
    }
    printf("\nEn buyuk alt kume toplami %d\nAlt kumede kazilmasi gereken bloklar: %d - %d\n\n", max_sum, hold_the_i, hold_the_j);
}