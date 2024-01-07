#include <stdio.h>
#include <stdlib.h>

int check(int row, int **board, int N)
{
    int i, j;

    for (i = row - 1; i >= 0; i--)
    {
        for (j = 0; j < N; j++)
        {

            if (board[i][j] == board[row][j])
                return 0;
        }
    }
    return 1;
}

void printColor(int colorCode)
{
    switch (colorCode)
    {
    case 1:
        printf("YELLOW\t");
        break;
    case 2:
        printf("BLUE\t");
        break;
    case 3:
        printf("ORANGE\t");
        break;
    case 4:
        printf("GREEN\t");
        break;
    case 5:
        printf("RED\t");
        break;
    case 6:
        printf("PINK\t");
        break;
    case 7:
        printf("BLACK\t");
        break;
    case 8:
        printf("WHITE\t");
        break;

    default:
        printf("ERROR! Unrecognizable Color");
        break;
    }
}

void printColorList(int N)
{
    int i;
    printf("\n \t\t\t\t\t\tColor List.");
    for (i = 1; i <= N; i++)
    {
        printf("\n \t\t\t\t\t\t%d.", i);
        printColor(i);
    }
}
void printSolution(int **board, int N)
{
    printf("\n\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printColor(board[i][j]);
        printf("\n");
    }
    printf("\n");
}

void rotate_right(int row, int **board, int N)
{
    int temp = board[row][N - 1];
    for (int i = N - 1; i > 0; i--)
    {
        board[row][i] = board[row][i - 1];
    }
    board[row][0] = temp;
}

int adjust_matrix(int row, int **board, int *shift_dizisi, int N, int mode_selection)
{

    if (row < N && row >= 0) // base case. (satir sayisini asarsak)
    {
        // printf("\n Row -> %d", row);
        if (check(row, board, N) == 1)
        {
            shift_dizisi[row + 1] = 0; // baska yerde gelmissek onceden sifirla
            adjust_matrix(row + 1, board, shift_dizisi, N, mode_selection);
        }
        else
        {
            rotate_right(row, board, N);
            shift_dizisi[row]++;
            if (mode_selection == 2)
            {
                printf("\n%d. Satiri Otele", row + 1);
                printSolution(board, N);
            }

            if (shift_dizisi[row] < N)
            {
                adjust_matrix(row, board, shift_dizisi, N, mode_selection);
            }
            else if (shift_dizisi[row - 1] < N)
            {
                rotate_right(row - 1, board, N);
                shift_dizisi[row - 1]++;
                if (mode_selection == 2)
                {
                    printf("\n%d. Satiri Otele", row + 1);

                    printSolution(board, N);
                }
                adjust_matrix(row - 1, board, shift_dizisi, N, mode_selection);
            }
        }
    }

    if (check(N - 1, board, N) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{

    int i, j;
    int N;
    int mode_selection;
    printf("Please Enter The Number Of Colors You Would like to choose\n");
    scanf(" %d", &N);

    int **board = (int **)malloc(sizeof(int *) * N);

    for (i = 0; i < N; i++)
    {
        board[i] = (int *)malloc(sizeof(int) * N);
    }

    board[0][0] = 1;
    board[0][1] = 2;
    board[0][2] = 3;
    board[0][3] = 4;

    board[1][0] = 2;
    board[1][1] = 3;
    board[1][2] = 4;
    board[1][3] = 1;

    board[2][0] = 4;
    board[2][1] = 3;
    board[2][2] = 2;
    board[2][3] = 1;

    board[3][0] = 3;
    board[3][1] = 2;
    board[3][2] = 1;
    board[3][3] = 4;

    // askjndkjansdkjnaskjndsa

    // board[0][0] = 5;
    // board[0][1] = 2;
    // board[0][2] = 4;

    // board[1][0] = 4;
    // board[1][1] = 2;
    // board[1][2] = 5;

    // board[2][0] = 5;
    // board[2][1] = 4;
    // board[2][2] = 2;
    // for (i = 0; i < N; i++)
    // {
    //     for (j = 0; j < N; j++)
    //     {

    //         printf("\nPlease Choose (%d,%d)'s Color \n", i + 1, j + 1);
    //         printColorList(N);
    //         printf("\n");
    //         scanf(" %d", &board[i][j]);
    //     }
    // }

    printf("Please Enter Mode\n1-Normal Mode\n2-Detailed Mode\n");
    scanf(" %d", &mode_selection);

    printf("Giris Matrisi");
    printSolution(board, N);

    int *shift_dizisi = (int *)calloc(N, sizeof(int));

    if (adjust_matrix(0, board, shift_dizisi, N, mode_selection))
    {
        printf("\nCozum Matrisi");
        printSolution(board, N);
        int i;
        for (i = 0; i < N; i++)
        {
            printf("\n%d. Satir %d Kez Otelendi!", i + 1, shift_dizisi[i]);
        }
    }
    else
    {
        printf("Cozum Yoktur!\n");
    }
    printf("\n");
    for (i = 0; i < N; i++)
    {
        free(board[i]);
    }
    free(board);
    return 0;
}
