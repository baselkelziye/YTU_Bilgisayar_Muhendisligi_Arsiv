#include <stdio.h>

int main() {
    int n, i, j, x, y, strike = 0, tmpx, tmpy;
    char player[3] = {'K', 'S', 'M'};
    int win[3] = {0};

    printf("\n\n\t\tTRIVERSE\n\nGAME RULES:\n");
    printf("1) ALL COORDINATES MUST BE GIVEN IN (x,y) FORMAT.\n");
    printf("2) MAX GAME TABLE SIZE IS 23.\n");
    printf("3) FIRST PLAYER SHOULD PLACE THEIR LETTER CLOSEST TO THE MIDDLE OF THE GAME TABLE.\n");
	printf("4) ALL OF THE INDEX ARE STARTS FROM 0 TO N-1. PAY ATTENTION THAT YOUR COORDINATES FITS THAT STANDARD.\n\n");

    printf("ENTER NXN GAME TABLE SIZE:\n");
    scanf("%d", &n);
    while (n > 23 || n < 3) {
        printf("\nSIZE MUST BE BETWEEN 3 AND 23.\nENTER AGAIN: ");
        scanf("%d", &n);
    } //controlling game table size

    char game[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            game[i][j] = '_';
        }
    }

    while (strike<n*n) {
        printf("\n\n");
        for (i=0;i<=n;i++) {
            if (i==0) {
                printf("   ");
                for (j=0;j<n;j++) {
                    printf("%2d ", j);
                }
                printf("\n");
            } else {
                printf("%2d ",(i-1));
                for (j=0;j<n;j++) {
                    printf("%2c ",game[i-1][j]);
                }
                printf("\n");
            }
        }

        printf("\nPLAYER %c IS PLAYING.\nENTER COORDINATES (x,y): ", player[strike % 3]);
        scanf("%d,%d", &x, &y);

        while (strike == 0 && 
               ((n % 2 == 1 && !(x == n / 2 && y == n / 2)) || 
                (n % 2 == 0 && !(x >= n / 2 - 1 && x < n / 2 + 1 && 
                                 y >= n / 2 - 1 && y < n / 2 + 1)))) {
            printf("INVALID COORDINATES. ENTER AGAIN: ");
            scanf("%d,%d", &x, &y);
        }

        while (strike != 0 && 
             (x < 0 || x >= n || y < 0 || y >= n || (game[x][y]!='_' || 
             ((!( x!=n-1 && y!=0) || (game[x+1][y-1]=='_')) &&
             (x==n-1 || game[x+1][y]=='_') &&
             (!(x!=n-1 && y!=n-1) || (game[x+1][y+1]=='_')) &&
             (y==0 || (game[x][y-1]=='_')) &&
             (y==n-1 || (game[x][y+1]=='_')) &&
             (!(x!=0 && y!=0) || (game[x-1][y-1]=='_')) &&
             (x==0 || game[x-1][y]=='_') &&
             (!( x!=0  && y!=n-1) || (game[x-1][y+1]=='_')))))){
            printf("INVALID COORDINATES. ENTER AGAIN: ");
            scanf("%d,%d", &x,&y);
        }

        game[x][y] = player[strike % 3];
        strike++;

        tmpy = y + 1;
        while (tmpy < n && game[x][tmpy] != '_') {
            if (game[x][tmpy] == game[x][y]) {
                for (i = y; i <= tmpy; i++) {
                    game[x][i] = game[x][y];
                }
                tmpy = n; 
            }
            tmpy++;
        } //right

        tmpy = y - 1;
        while (tmpy >= 0 && game[x][tmpy] != '_') {
            if (game[x][tmpy] == game[x][y]) {
                for (i = tmpy; i <= y; i++) {
                    game[x][i] = game[x][y];
                }
                tmpy = -1; 
            }
            tmpy--;
        } //left

        tmpx = x - 1;
        while (tmpx >= 0 && game[tmpx][y] != '_') {
            if (game[tmpx][y] == game[x][y]) {
                for (i = tmpx; i <= x; i++) {
                    game[i][y] = game[x][y];
                }
                tmpx = -1; 
            }
            tmpx--;
        } //top

        tmpx = x + 1;
        while (tmpx < n && game[tmpx][y] != '_') {
            if (game[tmpx][y] == game[x][y]) {
                for (i = x; i <= tmpx; i++) {
                    game[i][y] = game[x][y];
                }
                tmpx = n; 
            }
            tmpx++;
        } //bottom

        tmpx = x - 1, tmpy = y - 1;
        while (tmpx >= 0 && tmpy >= 0 && game[tmpx][tmpy] != '_') {
            if (game[tmpx][tmpy] == game[x][y]) {
                for (i = tmpx, j = tmpy; i <= x && j <= y; i++, j++) {
                    game[i][j] = game[x][y];
                }
                tmpx = -1; 
            }
            tmpx--;
            tmpy--;
        } //top left

        tmpx = x - 1, tmpy = y + 1;
        while (tmpx >= 0 && tmpy < n && game[tmpx][tmpy] != '_') {
            if (game[tmpx][tmpy] == game[x][y]) {
                for (i = tmpx, j = tmpy; i <= x && j >= y; i++, j--) {
                    game[i][j] = game[x][y];
                }
                tmpx = -1; 
            }
            tmpx--;
            tmpy++;
        } //bottom left

        tmpx = x + 1, tmpy = y - 1;
        while (tmpx < n && tmpy >= 0 && game[tmpx][tmpy] != '_') {
            if (game[tmpx][tmpy] == game[x][y]) {
                for (i = tmpx, j = tmpy; i >= x && j <= y; i--, j++) {
                    game[i][j] = game[x][y];
                }
                tmpx = n; 
            }
            tmpx++;
            tmpy--;
        } //top right

        tmpx = x + 1, tmpy = y + 1;
        while (tmpx < n && tmpy < n && game[tmpx][tmpy] != '_') {
            if (game[tmpx][tmpy] == game[x][y]) {
                for (i = tmpx, j = tmpy; i >= x && j >= y; i--, j--) {
                    game[i][j] = game[x][y];
                }
                tmpx = n;
            }
            tmpx++;
            tmpy++;
        } //bottom right
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (game[i][j] == player[0]) win[0]++;
            else if (game[i][j] == player[1]) win[1]++;
            else if (game[i][j] == player[2]) win[2]++;
        }
    }

    if (win[0] == win[1] && win[0] == win[2]) {
        printf("\nDRAW: ALL PLAYERS HAVE THE SAME SCORE.\n");
    } else if ((win[0] == win[1] && win[0] > win[2]) || 
               (win[0] == win[2] && win[0] > win[1]) || 
               (win[1] == win[2] && win[1] > win[0])) {
        printf("\nDRAW: TWO PLAYERS HAVE THE SAME HIGHEST SCORE.\n");
    } else if (win[0] > win[1] && win[0] > win[2]) {
        printf("\nPLAYER %c WINS WITH A SCORE OF %d.\n", player[0], win[0]);
    } else if (win[1] > win[0] && win[1] > win[2]) {
        printf("\nPLAYER %c WINS WITH A SCORE OF %d.\n", player[1], win[1]);
    } else {
        printf("\nPLAYER %c WINS WITH A SCORE OF %d.\n", player[2], win[2]);
    }

    return 0;
}