#include <stdio.h>

int main() {
    int numberOfCompetitor;
    int competitor;
    int stepNumber;
    int dd, sn;              /* o etaba ait dakika, saniye */
    int totalDd, totalSn;    /* yarismacinin 3 etap toplam suresi */
    int points;

    printf("How many competitor will be in the race?\n");
    scanf("%d", &numberOfCompetitor);

    if (numberOfCompetitor > 0) {
        for (competitor = 1; competitor <= numberOfCompetitor; competitor++) {

            totalDd = 0;
            totalSn = 0;

            for (stepNumber = 1; stepNumber <= 3; stepNumber++) {
                printf("Enter number %d competitor's %d.step time (minute,second):\n",
                       competitor, stepNumber);
                scanf("%d,%d", &dd, &sn);

                totalDd += dd;
                totalSn += sn;
            }

            /* saniye tasmasini dakikaya devret */
            if (totalSn >= 60) {
                totalDd += totalSn / 60;
                totalSn  = totalSn % 60;
            }

            /* bonus puan hesaplama (toplam sureye gore, TEK sefer) */
            points = 0;
            if (totalDd < 10) {
                points += 20;
            } else if (totalDd < 15) {
                points += 10;
            }

            /* toplam dakika ciftse ekstra puan */
            if (totalDd % 2 == 0) {
                points += 5;
            }

            printf("---outcomes---\n");
            printf("%d.->competitor total minute:%d,second:%d,point:%d\n",
                   competitor, totalDd, totalSn, points);
        }
    } else {
        printf("Number of competitor should be bigger than 0!\n");
    }

    return 0;
}