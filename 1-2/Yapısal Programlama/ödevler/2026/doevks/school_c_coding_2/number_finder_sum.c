#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    srand(time(NULL));
    int counter = 0, Arr[15], Sum = 0, index, find = 0;
    bool Flag = false;

    do {
        printf("\n--> Which number between 0 to 30 would you like to find?: ");
        fflush(stdout);
        scanf("%d", &find);

        if (find <0 || find > 30)
            printf("\n      [Error code: Please enter a number between the integers 0 and 30.]\n");

        } while (find < 0 || find > 30);

    printf("\n--> The array being created is a 15 index array with the numbers:\n[");
    while (counter<15) {
        Arr[counter] = rand() % 30;
        Sum += Arr[counter];
        printf("'%d',  ", Arr[counter]);

        if (Arr[counter] == find) {
            Flag = true;
            index = counter;
        }
        ++counter;
    }
    printf("]\n\n--> The sum of Arr ends up as: %d", Sum);

    if (Flag == true) printf("\n\n      [The number you're looking for is indexed in [%d] with the value of %d.] \n",index,find);
    else printf("\n\n       [The number %d you're looking for is not in associated array.]\n", find);



    //Notes: stdio.h was designed purely for input/output — printf, scanf etc. That's all it was ever meant to do.
    //bool wasn't even part of C originally! C is a very old language (1972) and back then programmers just used int for true/false (0 = false, anything else = true).
    //bool was only formally added to C in C99 (1999), and they put it in its own separate header stdbool.h rather than cramming it into existing ones.
}
