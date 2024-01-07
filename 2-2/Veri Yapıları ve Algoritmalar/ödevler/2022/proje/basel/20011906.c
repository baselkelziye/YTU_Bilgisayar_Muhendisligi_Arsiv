#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void determine_dimension_of_maze(int *, int *);
void read_maze_from_txt_to_matrix(char **, int, int);
void print_matrix(char **, int, int, int); // utility delayed print
int dfs(char **matrix, int[], int, int, int *);
void delay(int);
void elmalari_yerlestir(char **, int, int);
int main()
{
    printf("\n\n*************** NEW RUN TIME***********\n\n");
    srand(time(NULL));
    int row_length = 0, column_length = 0;
    int i;
    int starting_row = 29;
    int starting_column = 1;
    int matris_len[2];
    int toplam = 0;
    determine_dimension_of_maze(&row_length, &column_length);
    printf("Labirentin Boyutlari -> %dx%d", row_length, column_length);
    matris_len[0] = row_length;
    matris_len[1] = column_length;
    //    // printf("\nAfter Function Calling row-> %d column -> %d", row_length, column_length);
    char **matrix = (char **)malloc(sizeof(char *) * (row_length + 1));
    for (i = 0; i < row_length; i++)
    {
        matrix[i] = (char *)malloc(sizeof(char) * (column_length + 1));
    }
    read_maze_from_txt_to_matrix(matrix, row_length, column_length);

    print_matrix(matrix, row_length, column_length, 0);
    elmalari_yerlestir(matrix, row_length, column_length);
    print_matrix(matrix, row_length, column_length, 0);
    dfs(matrix, matris_len, starting_row, starting_column, &toplam);
    // print_matrix(matrix, row_length, column_length);

    // printf("\n\n\nBIRINCI SATIIIIR\n\n");
    // for (i = 0; i < column_length; i++)
    // {
    //     printf("%c", matrix[0][i]);
    // }

    // for (i = 0; i < row_length; i++)
    // {
    //     free(matrix[i]);
    // }
    // free(matrix);

    printf("\n");
    return 0;
}

void determine_dimension_of_maze(int *row_length, int *column_length)
{ // row satir ,column sutun
    const char EOL = '\n';
    char c;
    char buff[255];
    FILE *fp = fopen("maze.txt", "r"); // dilenirse dinamik yapilabilir dosyanin ismi
    if (fp == NULL)
    {
        printf("\nHata:Dosya Acilamadi!");
        exit(101);
    }

    *column_length = 0;
    while ((c = fgetc(fp)) != EOL)
    {
        *column_length = *column_length + 1;
    }
    //    printf("\nColumn length -> %d", *column_length);
    //     *row_length = *row_length + 1;
    //  }
    *row_length = 0;
    do
    {
        *row_length = *row_length + 1;
    } while (fgets(buff, 255, fp) != NULL);

    fclose(fp);
}

void read_maze_from_txt_to_matrix(char **matris, int row_length, int column_length)
{
    FILE *fp = fopen("maze.txt", "r");
    int i, j;
    char c;
    for (i = 0; i < row_length; i++)
    {
        for (j = 0; j < column_length + 1; j++)
        {
            c = fgetc(fp);
            matris[i][j] = c;
        }
    }

    fclose(fp);
}

void print_matrix(char **matris, int row_Length, int column_length, int toplam)
{

    int i, j;
    delay(1);

    printf("\n");

    for (i = 0; i < row_Length; i++)
    {
        for (j = 0; j < column_length + 1; j++)
        {
            printf("%c", matris[i][j]);
        }
        // printf("\n");
    }
    printf("\nToplam -> %d", toplam);
}

int dfs(char **matrix, int mtr_ln[], int start_row, int start_col, int *toplam)
{
    int cikmazSayisi = 0;

    print_matrix(matrix, mtr_ln[0], mtr_ln[1], *toplam);
    // Base case
    int bulundu = -1;

    if (matrix[start_row][start_col] == 'c')
    {
        printf("\n Cikis-> (%d,%d)", start_row, start_col);
        bulundu = 1;
        return bulundu;
    }

    //  if(bulundu != 1)

    if (start_row + 1 != mtr_ln[0] && bulundu != 1)
    {
        if (matrix[start_row + 1][start_col] == ' ' || matrix[start_row + 1][start_col] == 'c' || matrix[start_row + 1][start_col] == 'O')
        {
            cikmazSayisi = 1;
            if (matrix[start_row][start_col] != 'b')
                matrix[start_row][start_col] = '*';

            if (matrix[start_row + 1][start_col] == 'O')
                *toplam = *toplam + 10;

            bulundu = dfs(matrix, mtr_ln, start_row + 1, start_col, toplam);

            if (bulundu == -1)
            {
                matrix[start_row][start_col] = ' ';
                print_matrix(matrix, mtr_ln[0], mtr_ln[1], *toplam);
            }
        }
    }
    if (start_col + 1 != mtr_ln[1] && bulundu != 1)
    {
        if (matrix[start_row][start_col + 1] == ' ' || matrix[start_row][start_col + 1] == 'c' || matrix[start_row][start_col + 1] == 'O')
        {
            cikmazSayisi = 1;

            if (matrix[start_row][start_col + 1] == 'O')
                *toplam = *toplam + 10;

            if (matrix[start_row][start_col] != 'b')
                matrix[start_row][start_col] = '*';

            bulundu = dfs(matrix, mtr_ln, start_row, start_col + 1, toplam);
            if (bulundu == -1)
            {
                matrix[start_row][start_col] = ' ';
                print_matrix(matrix, mtr_ln[0], mtr_ln[1], *toplam);
            }
        }
    }

    if (start_row - 1 != mtr_ln[0] && bulundu != 1)
    {
        if (matrix[start_row - 1][start_col] == ' ' || matrix[start_row - 1][start_col] == 'c' || matrix[start_row - 1][start_col] == 'O')
        {
            cikmazSayisi = 1;

            if (matrix[start_row - 1][start_col] == 'O')
                *toplam = *toplam + 10;

            if (matrix[start_row][start_col] != 'b')
                matrix[start_row][start_col] = '*';

            bulundu = dfs(matrix, mtr_ln, start_row - 1, start_col, toplam);
            if (bulundu == -1)
            {
                matrix[start_row][start_col] = ' ';
                print_matrix(matrix, mtr_ln[0], mtr_ln[1], *toplam);
            }
        }
    }

    if (start_col - 1 != mtr_ln[1] && bulundu != 1)
    {
        if (matrix[start_row][start_col - 1] == ' ' || matrix[start_row][start_col - 1] == 'c' || matrix[start_row][start_col - 1] == 'O')
        {

            cikmazSayisi = 1;
            if (matrix[start_row][start_col - 1] == 'O')
                *toplam = *toplam + 10;

            if (matrix[start_row][start_col] != 'b')
                matrix[start_row][start_col] = '*';

            bulundu = dfs(matrix, mtr_ln, start_row, start_col - 1, toplam);

            if (bulundu == -1)
            {
                matrix[start_row][start_col] = ' ';
                print_matrix(matrix, mtr_ln[0], mtr_ln[1], *toplam);
            }
        }
    }

    if (cikmazSayisi == 0 && bulundu != 1)
    {
        *toplam = *toplam - 5;
    }

    //    if (bulundu == 1)
    //        matrix[start_row][start_col] = ' ';
    // eğer yoksa - 1 çeviricek
    // system("clear");
    return bulundu;
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 100000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void elmalari_yerlestir(char **matrix, int row, int column)
{
    int target_elma_sayisi = 20;
    int tmp_row, tmp_col;
    // if (row > column)
    // {
    //     target_elma_sayisi = row / 2;
    //     target_elma_sayisi = target_elma_sayisi / 2;
    // }
    // else
    // {
    //     target_elma_sayisi = row / 2;
    //     target_elma_sayisi = target_elma_sayisi / 2;
    // }

    printf("\n Target Elma -> %d", target_elma_sayisi);
    int current_elma = 0;

    while (current_elma != target_elma_sayisi)
    {
        tmp_row = rand() % row;
        tmp_col = rand() % column;
        if (matrix[tmp_row][tmp_col] == ' ')
        {
            matrix[tmp_row][tmp_col] = 'O';
            current_elma++;
        }
    }
}