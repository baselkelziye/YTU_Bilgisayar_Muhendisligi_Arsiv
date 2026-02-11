#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Donem Projesi
 * Panel de Pon
 *
 * Enes Genc
 * 25011079
 */

#ifdef _WIN32
#define BORDER_H "-"
#define BORDER_V "|"
#define BORDER_TL "/"
#define BORDER_TR "\\"
#define BORDER_BL "\\"
#define BORDER_BR "/"
#else
#define BORDER_H "─"
#define BORDER_V "│"
#define BORDER_TL "╭"
#define BORDER_TR "╮"
#define BORDER_BL "╰"
#define BORDER_BR "╯"
#endif

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define HIGHLIGHT "\033[1;37m\033[4;37m"
#define RESET "\033[0m"

#define CHAR1 '*'
#define CHAR2 '/'
#define CHAR3 '+'
#define CHAR4 '%'
#define CHAR5 'O'

#define BLOCK1 YELLOW "*" RESET
#define BLOCK2 BLUE   "/" RESET
#define BLOCK3 PURPLE "+" RESET
#define BLOCK4 RED    "%" RESET
#define BLOCK5 GREEN  "O" RESET

/*
 * Kontrol modunda ekrani tamamen temizlemek yerine sadece biraz bosluk birakiliyor.
 */
void clear(int fullClear) {
    if (!fullClear) {
        int i;
        for (i = 0; i < 5; i++) {
            printf("\n");
        }
        return;
    }

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void drawBoard(int board[20][20], int boardX, int boardY, int highlight, int highlightX, int highlightY) {
    int x, y;

    for (y = -2; y <= boardY; y++) {
        int coordinateLine = y == -2;
        int firstLine = y == -1;
        int lastLine = y == boardY;

        for (x = -1; x <= boardX; x++) {
            int firstChar = x == -1;
            int lastChar = x == boardX;

            int ch = board[y][x];
            char* block;

            if (ch == CHAR1) block = BLOCK1;
            else if (ch == CHAR2) block = BLOCK2;
            else if (ch == CHAR3) block = BLOCK3;
            else if (ch == CHAR4) block = BLOCK4;
            else if (ch == CHAR5) block = BLOCK5;
            else block = " ";

            if (!ch) ch = ' ';

            if (coordinateLine && x == -1) {
                x = 0;
                printf("      %d", x + 1);
            }
            else if (coordinateLine) { if (x < boardX) printf(" %d", (x + 1) % 10); }
            else if (firstLine && firstChar) printf("    %s", BORDER_TL);
            else if (firstLine && lastChar) printf("%s%s", BORDER_H, BORDER_TR);
            else if (lastLine && firstChar) printf("    %s", BORDER_BL);
            else if (lastLine && lastChar) printf("%s%s", BORDER_H, BORDER_BR);
            else if (firstLine || lastLine) printf("%s%s", BORDER_H, BORDER_H);
            else if (firstChar) printf(" %2d %s", y + 1, BORDER_V);
            else if (lastChar) printf(" %s", BORDER_V);
            else if (x == highlightX && y == highlightY && highlight) printf(" %s%c%s", HIGHLIGHT, ch, RESET);
            else printf(" %s", block);
        }

        printf("\n");
    }
}

void wait(int seconds) {
    long end = time(NULL) + seconds;
    while (time(NULL) < end) {
    }
}

int calculateDigits(int num) {
    int i;
    int digits = 1;

    for (i = num; i > 10; i /= 10) {
        digits++;
    }

    return digits;
}

void drawWhitespace(int n) {
    int i;
    for (i = 0; i < n; i++) printf(" ");
}

void drawStats(int swp, int exp) {
    int i;
    int flLength = 26 + calculateDigits(swp);
    int llLength = 29 + calculateDigits(exp);
    int maxLength = flLength > llLength ? flLength : llLength;

    printf(" %s", BORDER_TL);
    for (i = 0; i < maxLength; i++) printf("%s", BORDER_H);
    printf("%s\n", BORDER_TR);

    printf(" %s Toplam Yer Degisikligi:", BORDER_V);
    drawWhitespace(maxLength - flLength + 1);
    printf("%d %s\n", swp, BORDER_V);

    printf(" %s Toplam Patlatilan Element:", BORDER_V);
    drawWhitespace(maxLength - llLength + 1);
    printf("%d %s\n", exp, BORDER_V);

    printf(" %s", BORDER_BL);
    for (i = 0; i < maxLength; i++) printf("%s", BORDER_H);
    printf("%s\n", BORDER_BR);
}

int mainMenu(int invalidInput) {
    printf(" ____                         ___           __              ____                   \n");
    printf("/\\  _`\\                      /\\_ \\         /\\ \\            /\\  _`\\                 \n");
    printf("\\ \\ \\L\\ \\ __      ___      __\\//\\ \\        \\_\\ \\     __    \\ \\ \\L\\ \\___     ___    \n");
    printf(" \\ \\ ,__/'__`\\  /' _ `\\  /'__`\\\\ \\ \\       /'_` \\  /'__`\\   \\ \\ ,__/ __`\\ /' _ `\\  \n");
    printf(
        "  \\ \\ \\/\\ \\L\\.\\_/\\ \\/\\ \\/\\  __/ \\_\\ \\_    /\\ \\L\\ \\/\\  __/    \\ \\ \\/\\ \\L\\ \\/\\ \\/\\ \\ \n");
    printf(
        "   \\ \\_\\ \\__/.\\_\\ \\_\\ \\_\\ \\____\\/\\____\\   \\ \\___,_\\ \\____\\    \\ \\_\\ \\____/\\ \\_\\ \\_\\\n");
    printf("    \\/_/\\/__/\\/_/\\/_/\\/_/\\/____/\\/____/    \\/__,_ /\\/____/     \\/_/\\/___/  \\/_/\\/_/\n");
    printf("\n\n");
    printf("Enes Genc - 25011079\n");
    printf("Donem Projesi\n\n");

    if (invalidInput) {
        printf("%sHatali giris yaptiniz. Lutfen tekrar giris yapin.%s\n\n", RED, RESET);
    }
    else {
        printf("\n\n"); // Hatali giriste kaymayi onleme amacli hata mesajinin oldugu yeri bos birakiyor.
    }

    printf("Mod Seciniz:\n");
    printf("1) Oyun Modu\n");
    printf("2) Kontrol Modu\n");
    printf(">  ");

    int input;
    scanf("%d", &input);

    if (input == 1) {
        return 1;
    }
    if (input == 2) {
        return 0;
    }

    clear(1);
    return mainMenu(1);
}

void setBoardSize(int* x, int* y, int gamemode, int invalidInput) {
    if (invalidInput == 1) {
        printf("%sHatali giris yaptiniz. Lutfen tekrar giris yapin.%s\n\n", RED, RESET);
    }
    else if (invalidInput == 2) {
        printf("%sBelirlediginiz boyutta oynanabilir alan olusmuyor. Lutfen daha buyuk oyun alani belirleyin.%s\n", RED,
               RESET);
    }
    else {
        printf("\n\n");
    }

    printf("Oyun alani belirleyin:\n");
    printf("> Yukseklik (Max 20):");
    scanf("%d", y);

    if (*y <= 0 || *y > 20) {
        clear(gamemode);
        return setBoardSize(x, y, gamemode, 1);
    }

    if (*y % 2 && gamemode) {
        printf("Yukseklik olarak tek sayi girdiniz. Oyun alaninin ilk %d satiri dolu baslayacak.\n", *y / 2);
    }

    printf("> Genislik (Max 20):");
    scanf("%d", x);

    if (*x <= 0 || *x > 20) {
        clear(gamemode);
        return setBoardSize(x, y, gamemode, 1);
    }

    if (*x <= 2 || *y <= 1) {
        clear(gamemode);
        return setBoardSize(x, y, gamemode, 2);
    }
}

void randomFillBoard(int board[20][20], int x, int y, int chars[5]) {
    int i, j;

    for (i = y / 2 + y % 2; i < y; i++) {
        for (j = 0; j < x; j++) {
            board[i][j] = chars[rand() % 5];
        }
    }
}

void controlModeFillBoard(int board[20][20], int boardX, int boardY) {
    int i, j;
    int invalid = 0;

    for (i = 0; i < boardY; i++) {
        for (j = 0; j < boardX; j++) {
            clear(0);
            drawBoard(board, boardX, boardY, 1, j, i);
            printf("\n");
            if (invalid) {
                printf("%sHatalı giriş yaptınız.%s\n", RED, RESET);
                invalid = 0;
            } else {
                printf("\n");
            }
            printf("Gosterilen kare icin element (veya elementin numarasini) girin:\n");
            printf("1) *  2) /  3) +  4) %%  5) O  0) Bos Birak\n");
            printf(">  ");

            char input;
            scanf(" %c", &input);

            if (input == '0') board[i][j] = 0;
            else if (input == CHAR1 || input == '1') board[i][j] = CHAR1;
            else if (input == CHAR2 || input == '2') board[i][j] = CHAR2;
            else if (input == CHAR3 || input == '3') board[i][j] = CHAR3;
            else if (input == CHAR4 || input == '4') board[i][j] = CHAR4;
            else if (input == CHAR5 || input == '5') board[i][j] = CHAR5;
            else {
                j--;
                invalid = 1;
            }
        }
    }

    clear(0);
    drawBoard(board, boardX, boardY, 0, 0, 0);
    wait(2);
}

int gameCanContinue(int board[20][20], int x) {
    int i;
    int st = 1;

    for (i = 0; i < x; i++) {
        if (board[0][i] != 0) st = 0;
    }

    return st;
}

int explode(int board[20][20], int boardX, int boardY, int x, int y) {
    int i, j;
    int xs, xe, ys, ye;

    int ch = board[y][x];

    for (i = x; i >= 0 && board[y][i] == ch; i--) {
    }
    xs = i + 1;
    for (i = x; i < boardX && board[y][i] == ch; i++) {
    }
    xe = i - 1;
    for (i = y; i >= 0 && board[i][x] == ch; i--) {
    }
    ys = i + 1;
    for (i = y; i < boardY && board[i][x] == ch; i++) {
    }
    ye = i - 1;

    int xle = xe - xs + 1;
    int yle = ye - ys + 1;
    int sideways = 0;

    if (xle < 3 && yle < 3) {
        return 0;
    }

    if (xle >= 3 && xle >= yle) {
        sideways = 1;
    }

    if (sideways) {
        for (i = xs; i <= xe; i++) {
            for (j = y - 1; j >= 0; j--) {
                board[j + 1][i] = board[j][i];
            }
            board[0][i] = 0;
        }

        return xle;
    }

    for (i = ye; i >= 0; i--) {
        if (i - yle >= 0) {
            board[i][x] = board[i - yle][x];
        }
        else {
            board[i][x] = 0;
        }
    }

    return yle;
}

void addRandomLine(int board[20][20], int boardX, int boardY, int chars[5]) {
    int i, j;

    for (i = 0; i < boardX; i++) {
        for (j = 1; j < boardY; j++) {
            board[j - 1][i] = board[j][i];
        }
        board[boardY - 1][i] = chars[rand() % 5];
    }
}

int main() {
    int board[20][20] = {0};
    int boardX, boardY;
    int gamemode; // Kontrol = 0; Oyun = 1

    int chars[5] = {CHAR1, CHAR2, CHAR3, CHAR4, CHAR5};
    int swapCount = 0;
    int explosionCount = 0;

    int choice = 0;
    int step = 0;

    char* message;
    int messageInt;
    int showInfo = 0;
    int showError = 0;
    int showInt = 0;

    int chx1, chy1, chx2, scanres;

    srand(time(NULL));

    clear(1);
    gamemode = mainMenu(0);
    clear(gamemode);
    setBoardSize(&boardX, &boardY, gamemode, 0);

    if (gamemode) {
        randomFillBoard(board, boardX, boardY, chars);
    }
    else {
        controlModeFillBoard(board, boardX, boardY);
    }

    while (gameCanContinue(board, boardX) && choice != 9) {
        clear(gamemode);
        if (choice == 2 && step == 2) {
            drawBoard(board, boardX, boardY, 1, chx1, chy1);
        }
        else {
            drawBoard(board, boardX, boardY, 0, 0, 0);
        }
        printf("\n");
        drawStats(swapCount, explosionCount);
        printf("\n");

        if (showInfo) {
            if (showInt) printf("%s%d %s%s\n\n", BLUE, messageInt, message, RESET);
            else printf("%s%s%s\n\n", BLUE, message, RESET);
        }
        else if (showError) {
            printf("%s%s%s\n\n", RED, message, RESET);
        }
        else {
            printf("\n\n");
        }

        if (step == 0) {
            printf("Islem secin:\n");
            printf("1) Patlatma\n");
            printf("2) Yer Degistirme\n");
            printf("9) Oyunu Bitir\n");
            printf(">  ");
            scanf("%d", &choice);
            printf("\n");

            step = 1;
            showInfo = 0;
            showError = 0;
            showInt = 0;
        }
        else if (choice == 1) {
            printf("Patlatilacak elementin koordinatini giriniz (Format: y,x Ornek: 6,7): \n");
            printf("> ");
            scanres = scanf("%d,%d", &chy1, &chx1);

            // koordinatlar 1den basliyor, arrayler 0dan basliyor
            chx1--;
            chy1--;

            if (chx1 < 0 || chx1 >= boardX || chy1 < 0 || chy1 >= boardY || scanres != 2) {
                message = "Hatali giris yaptiniz.";
                showInfo = 0;
                showInt = 0;
                showError = 1;
            }
            else if (board[chy1][chx1] == 0) {
                message = "Verilen koordinatta element yok. Patlatma yapilmadi.";
                showInfo = 1;
                showInt = 0;
                showError = 0;
                step = 0;
            }
            else {
                int result = explode(board, boardX, boardY, chx1, chy1);
                explosionCount += result;

                if (result) {
                    messageInt = result;
                    message = "element patlatildi.";

                    showInfo = 1;
                    showInt = 1;
                    showError = 0;

                    step = 0;
                }
                else {
                    message = "Patlatma icin yeterli element yok.";
                    showInfo = 0;
                    showInt = 0;
                    showError = 1;

                    step = 0;
                }
            }
        }
        else if (choice == 2 && step == 1) {
            printf("Yer degistirme icin ilk elementin koordinatini giriniz (Format: y,x Ornek: 6,7): \n");
            printf(">  ");
            scanres = scanf("%d,%d", &chy1, &chx1);
            chx1--;
            chy1--;

            if (chx1 < 0 || chx1 >= boardX || chy1 < 0 || chy1 >= boardY || scanres != 2) {
                message = "Hatali giris yaptiniz.";
                showInfo = 0;
                showInt = 0;
                showError = 1;
            }
            else {
                showInfo = 0;
                showInt = 0;
                showError = 0;
                step = 2;
            }
        }
        else if (choice == 2 && step == 2) {
            printf("Yer degistirme icin ikinci elementin koordinatini giriniz (Format: y,x Ornek: 6,7): \n");
            printf(">  %d,", chy1 + 1);
            scanres = scanf("%d", &chx2);
            chx2--;

            if (chx2 < 0 || chx2 >= boardX || scanres != 1) {
                message = "Hatali giris yaptiniz.";
                showInfo = 0;
                showInt = 0;
                showError = 1;
            }
            else if (!board[chy1][chx1] || !board[chy1][chx2]) {
                message = "Sadece farkli renkte iki element yer degistirebilir. Element bos alana gecirilemez.";
                showInfo = 0;
                showInt = 0;
                showError = 1;
                step = 0;
            }
            else if (board[chy1][chx1] == board[chy1][chx2]) {
                message = "Ayni renkte iki element yer degistiremez.";
                showInfo = 0;
                showInt = 0;
                showError = 1;
                step = 0;
            }
            else if (chx1 + 1 != chx2 && chx1 - 1 != chx2) {
                message = "Sadece yan yana olan elementler yer degistirebilir.";
                showInfo = 0;
                showInt = 0;
                showError = 1;
                step = 0;
            }
            else {
                int temp = board[chy1][chx1];
                board[chy1][chx1] = board[chy1][chx2];
                board[chy1][chx2] = temp;

                swapCount++;

                message = "Yer degisimi yapildi.";
                showInfo = 1;
                showInt = 0;
                showError = 0;
                step = 3;
            }
        }
        else if (choice == 2 && step == 3) {
            wait(2);
            addRandomLine(board, boardX, boardY, chars);
            step = 0;
        }
        else {
            message = "Hatali giris yaptiniz.";
            showInfo = 0;
            showInt = 0;
            showError = 1;

            step = 0;
        }
    }

    clear(gamemode);
    drawBoard(board, boardX, boardY, 0, 0, 0);
    printf("\n");
    drawStats(swapCount, explosionCount);
    printf("\n\n");
    printf("%sOyun bitti.%s", GREEN, RESET);
    printf("\n\n");

    return 0;
}
