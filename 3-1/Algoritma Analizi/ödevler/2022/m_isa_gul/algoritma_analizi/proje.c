#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Asagidaki fonksiyon ile mevcut satir, ustundeki diger satirlar ile karsilastirilir.
// Eger ayni deger bulunuyorsa 0, bulunmuyorsa 1 degeri dondurulur.
int checkUp(int n, int row, int **board)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[row][j] == board[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

// Asagidaki fonksiyon ile saga kaydirma islemi yapilmaktadir.
void shift(int n, int row, int **board, int mod)
{
    int i, j;
    int tmp = board[row][n - 1];
    for (i = n - 1; i > 0; i--)
    {
        board[row][i] = board[row][i - 1];
    }
    board[row][0] = tmp;
    if (mod == 2)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int backtrack(int n, int row, int **board, int shiftCount[], int mod)
{
    // Kontrol edilecek satir kalmayinca fonksiyondan cikilir
    if (row == n)
        return 1;

    // Ilk satirin ustunde satir olmadigi icin karsilastirma yapilmayacaktir.
    // Sadece saga kaydirma islemi yapilmaktadir.
    if (row == 0)
    {
        if (shiftCount[0] != n - 1)
        {
            shift(n, row, board, mod);
            shiftCount[0]++;
            backtrack(n, row + 1, board, shiftCount, mod);
        }
        return 0;
    }

    if (shiftCount[row] < n)
    {
        if (checkUp(n, row, board))
        {
            // checkUp fonksiyonu sonucu 1 degeri dondurulmusse bir sonraki satira gecilir.
            backtrack(n, row + 1, board, shiftCount, mod);
        }
        else
        {
            // checkUp fonksiyonu sonucu 0 degeri dondurulmusse kaydirma islemi yapilir.
            shiftCount[row] += 1;
            shift(n, row, board, mod);
            backtrack(n, row, board, shiftCount, mod);
        }
    }
    else
    {
        // Islemde olan satir n kere kaydirma islemine ugramissa bir adim geri gidilir.
        // Tekrar bu satira gelindiginde en fazla n kere kaydirma islemi yapilabilmesi icin
        // shifCount degeri 0 lanir
        shiftCount[row] = 0;

        // Ilk satir icin fonksiyon girisinde kontrol yapildigi icin burada tekrar kontrol edilmemeli.
        if (row - 1 != 0)
            shiftCount[row - 1]++;
        shift(n, row - 1, board, mod);
        backtrack(n, row - 1, board, shiftCount, mod);
    }
}

int main()
{
    int i, j;
    int res;
    int n;
    char color[10];
    printf("n: ");
    scanf("%d", &n);

    int mod;
    printf("1-Normal\n2-Detail\nMod: ");
    scanf("%d", &mod);
    int **board = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(n * sizeof(int));
    }
    printf("\nAsagidaki renklerden tam ismini ya da bas harflerini giriniz...\n");
    printf("\n1-Kirmizi\n2-Sari\n3-Yesil\n4-Mavi\n5-Beyaz\n6-Gri\n7-Turuncu\n8-Pembe\n");

    int readMode;
    printf("\n1-board.txt dosyasindan oku\n2-tek tek gir\nBoard okuma modunu seciniz: ");
    scanf("%d", &readMode);

    if (readMode == 1)
    {
        FILE *filePtr = fopen("board3.txt", "r");
        char buff[255];

        for (i = 0; i < n; i++)
        {
            fgets(buff, sizeof(buff), filePtr);
            for (j = 0; j < n; j++)
            {
                char *token;
                if (j == 0)
                    token = strtok(buff, " ");
                else if (j == n - 1)
                    token = strtok(NULL, " \n");
                else
                    token = strtok(NULL, " ");
                if (strcmp(token, "Kirmizi") == 0 || strcmp(token, "K") == 0)
                    board[i][j] = 1;
                else if (strcmp(token, "Sari") == 0 || strcmp(token, "S") == 0)
                    board[i][j] = 2;
                else if (strcmp(token, "Yesil") == 0 || strcmp(token, "Y") == 0)
                    board[i][j] = 3;
                else if (strcmp(token, "Mavi") == 0 || strcmp(token, "M") == 0)
                    board[i][j] = 4;
                else if (strcmp(token, "Beyaz") == 0 || strcmp(token, "B") == 0)
                    board[i][j] = 5;
                else if (strcmp(token, "Gri") == 0 || strcmp(token, "G") == 0)
                    board[i][j] = 6;
                else if (strcmp(token, "Turuncu") == 0 || strcmp(token, "T") == 0)
                    board[i][j] = 7;
                else if (strcmp(token, "Pembe") == 0 || strcmp(token, "P") == 0)
                    board[i][j] = 8;
            }
        }
        fclose(filePtr);
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("board[%d][%d]: ", i, j);
                scanf("%s", color);
                if (strcmp(color, "Kirmizi") == 0 || strcmp(color, "K") == 0)
                    board[i][j] = 1;
                else if (strcmp(color, "Sari") == 0 || strcmp(color, "S") == 0)
                    board[i][j] = 2;
                else if (strcmp(color, "Yesil") == 0 || strcmp(color, "Y") == 0)
                    board[i][j] = 3;
                else if (strcmp(color, "Mavi") == 0 || strcmp(color, "M") == 0)
                    board[i][j] = 4;
                else if (strcmp(color, "Beyaz") == 0 || strcmp(color, "B") == 0)
                    board[i][j] = 5;
                else if (strcmp(color, "Gri") == 0 || strcmp(color, "G") == 0)
                    board[i][j] = 6;
                else if (strcmp(color, "Turuncu") == 0 || strcmp(color, "T") == 0)
                    board[i][j] = 7;
                else if (strcmp(color, "Pembe") == 0 || strcmp(color, "P") == 0)
                    board[i][j] = 8;
            }
        }
    }
    printf("\nFirst version:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Her satirin kac kere shift edildigi shiftCount dizisinde tutulmaktadir.
    int shiftCount[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    res = backtrack(n, 1, board, shiftCount, mod);

    if (res == 0)
    {
        printf("\nThere is not any possible board!");
    }
    else
    {
        printf("Last version:\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        printf("\nColor version:\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                    printf("Kirmizi ");
                else if (board[i][j] == 2)
                    printf("Sari ");
                else if (board[i][j] == 3)
                    printf("Yesil ");
                else if (board[i][j] == 4)
                    printf("Mavi ");
                else if (board[i][j] == 5)
                    printf("Beyaz ");
                else if (board[i][j] == 6)
                    printf("Gri ");
                else if (board[i][j] == 7)
                    printf("Turuncu ");
                else if (board[i][j] == 8)
                    printf("Pembe ");
            }
            printf("\n");
        }
    }

    for (i = 0; i < n; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}
