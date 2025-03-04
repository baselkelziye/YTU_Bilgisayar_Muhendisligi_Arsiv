#include <stdio.h>

#define TEST // Hocam bunu kapatmayı unuttuysam kusura bakmayın yorum satırına dönüştürürseniz normal çalışacaktır.

int main() {
    int i, j, k, n, x = 0, y = 0, winner = 0;
    int useless_index = 1, different_kind_of_count = 0;
    int flag = 0, _;
    int control_array[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    int control_control_array[8] = {0};
    int useless_array[3][2] = {{'K', 0}, {'S', 0}, {'M', 0}};

    printf("Enter the board size (3-23):");

    #ifdef TEST
    n = 20;
    #else
    scanf("%d", &n);

    if ( n > 23 || n < 3) {
        printf("N value can not be bigger than 23 or smaller than 3");
        return 0;
    }
    #endif
    
    char board[n][n];

    for ( i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            board[i][j] = '_';
        }
    }
    board[(n / 2) - 1][(n / 2) - 1] = 'K';

    for ( _ = n * n - 1; _ > 0 && flag == 0; _--) {

        do {
            printf("\e[1;1H\e[2J");

            printf("\nBoard:\n\nX  ");

            for ( i = 0; i < n; i++) printf("%d  ", i % 10);
            printf("\n");

            for ( i = 0; i < n; i++){
                printf("%d  ", i % 10);
                for (j = 0; j < n; j++) {
                    printf("%c  ", board[i][j]);
                }
                printf("\n");
            }
            printf("\n\nEnter the coordinates with spaces between for the %c.\nIf you want to exit write -1 -1.\nCoordinates: ", 
            useless_array[useless_index % 3][0]);
            scanf("%d %d", &x, &y);
            
            if ( x == -1 || y == -1) flag = 1;
            
        }while (( board[x][y] != '_' ||
               ((!( x != n - 1 && y != 0)     || (board[x + 1][y - 1] == '_')) &&
                (   x == n - 1                ||  board[x + 1][y]      == '_') &&
                (!( x != n - 1 && y != n - 1) || (board[x + 1][y + 1] == '_')) &&
                (                 y == 0      || (board[x][y - 1]     == '_')) &&
                (                 y == n - 1  || (board[x][y + 1]     == '_')) &&
                (!( x != 0     && y != 0)     || (board[x - 1][y - 1] == '_')) &&
                (   x == 0                    ||  board[x - 1][y]      == '_') &&
                (!( x != 0     && y != n - 1) || (board[x - 1][y + 1] == '_')))) && flag == 0);

        if ( flag == 0) {
            board[x][y] = useless_array[useless_index % 3][0];
            useless_index++;
        }

        for ( i = 1; i < n; i++) {
            for ( j = 0; j < 8; j++) {
                if ( ( ( (x + i * control_array[j][0]) >= 0 && (x + i * control_array[j][0]) < n) && 
                       ( (y + i * control_array[j][0]) >= 0 && (y + i * control_array[j][0]) < n)) && 
                       (control_control_array[j] == 0 && board[x + i * control_array[j][0]][y + i * control_array[j][1]] == board[x][y])) {
                    for (k = 1; k < i; k++) {
                        board[x + k * control_array[j][0]][y + k * control_array[j][1]] = board[x][y];
                    }
                    j = 8;
                    i = n;
                }
                else if ( board[x + i * control_array[j][0]][y + i * control_array[j][1]] == '_') {
                    control_control_array[j] = 1;
                }
            }
        }
        for ( i = 0; i < 8; i++) control_control_array[i] = 0;
    }

    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i][j] == 'K') {
                useless_array[0][1]++;
            }
            else if (board[i][j] == 'S') {
                useless_array[1][1]++;
            }
            else if (board[i][j] == 'M') {
                useless_array[2][1]++;
            }
        }
    }
    printf("K --> %d\n", useless_array[0][1]);
    printf("S --> %d\n", useless_array[1][1]);
    printf("M --> %d\n", useless_array[2][1]);

    if ( useless_array[0][1] >= useless_array[1][1] && useless_array[0][1] >= useless_array[2][1]) {
        winner = 'K';
    }
    else if ( useless_array[1][1] >= useless_array[0][1] && useless_array[1][1] >= useless_array[2][1]) {
        winner = 'S';
    }
    else if ( useless_array[2][1] >= useless_array[1][1] && useless_array[2][1] >= useless_array[0][1]) {
        winner = 'M';
    }

    printf("\n\n----------------\nWinner: %c\n----------------", winner);
    return 0;
}