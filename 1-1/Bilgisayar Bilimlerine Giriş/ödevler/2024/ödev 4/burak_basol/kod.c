#include <stdio.h>
#include <stdlib.h>

//#define TEST

int main() {
    int i, j;
    #ifdef TEST
    int n = 10, m = 10;
    int array[12][12] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 1, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 2, 1, 2, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 2, 1, 0, 2, 2, 2, 2, 0},
        {0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 2, 2, 2, 0, 4, 0, 0, 0, 0, 0},
        {0, 4, 4, 4, 4, 4, 4, 0, 3, 3, 3, 0},
        {0, 3, 0, 0, 3, 3, 3, 0, 3, 0, 0, 0},
        {0, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    #endif
    #ifdef TEST1
    int n = 9, m = 9;
    int array[11][11] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
        {0, 1, 1, 2, 0, 0, 2, 2, 2, 0, 0},
        {0, 0, 2, 0, 2, 2, 2, 0, 0, 2, 0},
        {0, 2, 4, 4, 4, 0, 0, 0, 3, 3, 0},
        {0, 0, 4, 0, 0, 0, 3, 3, 3, 0, 0},
        {0, 4, 0, 0, 0, 0, 3, 0, 0, 0, 0},
        {0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0},
        {0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    #endif
    #ifdef TEST2
    int n = 13, m = 13;
    int array[15][15] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 2, 1, 1, 2, 1, 0, 0, 1, 1, 1, 0}, //18
        {0, 0, 1, 1, 2, 0, 0, 2, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 2, 2, 0, 0, 0, 0, 2, 1, 1, 1, 0, 2, 0}, //15
        {0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 3, 0, 3, 4, 3, 4, 3, 0, 3, 0, 3, 4, 0}, //16
        {0, 0, 0, 0, 4, 3, 4, 0, 4, 3, 0, 3, 4, 3, 0},
        {0, 0, 4, 4, 4, 0, 0, 0, 5, 4, 4, 4, 4, 6, 0}, //13
        {0, 4, 4, 5, 5, 5, 5, 5, 6, 5, 5, 6, 6, 0, 0},
        {0, 0, 5, 0, 0, 6, 6, 6, 0, 6, 6, 0, 0, 0, 0},
        {0, 5, 5, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    #endif

    #ifdef MAIN
    int n, m;
    printf("Enter the n value (rows):");
    scanf("%d", &n);
    printf("Enter the m value (columns):");
    scanf("%d", &m);
    int array[n + 2][m + 2];

    for (i = 0; i < (n + 2); i++){
        for (j = 0; j < (m + 2); j++) {
            array[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++) {
            printf("%d.row %d.columns value:", i + 1, j + 1);
            scanf("%d", &array[i + 1][j + 1]);
        }
    }
    #endif

    printf("The matrix you provided:\n");
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < m + 2; j++) {
            printf(" %d ", array[i][j]);
        }
        printf("\n");
    }

    int row = 1, column = 1;
    for (row = 1;row < n + 2; row++) {
        int road_value = array[row][1];
        int temp = row;
        if (road_value != 0) {
            int count = 1;
            int flag = 0;
            column = 1;
            while (column < m + 1){
                if (array[row - 1][column] == road_value) {array[row][column] = 0; count++; row--;}
                else if (array[row][column - 1] == road_value) {array[row][column] = 0; count++; column--;}
                else if (array[row][column + 1] == road_value) {array[row][column] = 0; count++; column++;}
                else if (array[row + 1][column] == road_value) {array[row][column] = 0; count++; row++;}
                else if (array[row - 1][column - 1] == road_value) {array[row][column] = 0; count++; row--; column--;}
                else if (array[row - 1][column + 1] == road_value) {array[row][column] = 0; count++; row--; column++;}
                else if (array[row + 1][column - 1] == road_value) {array[row][column] = 0; count++; row++; column--;}
                else if (array[row + 1][column + 1] == road_value) {array[row][column] = 0; count++; row++; column++;}
                else {if (column != m) {flag = 1;} column = m + 2;}
            }
            if (flag == 0) {
                printf("Road %d --> Length %d\n", road_value, count);
            }
            flag = 0;
        }
        row = temp;
    }
    return 0;
}