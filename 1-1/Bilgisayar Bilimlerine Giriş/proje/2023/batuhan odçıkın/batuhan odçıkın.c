#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_SIZE 100
enum
{
    OK = 0,
    COORDINATE_ERROR,
    GAMEOVER
};

enum
{
    PLAY = 1,
    QUIT
};

int n = 0,
    m = 0;

void reset_board(int board[MAX_SIZE][MAX_SIZE]);

void print_board(int board[MAX_SIZE][MAX_SIZE]);
void reset_tetramino(int tetremino[][3]);

void print_tetremino(int tetremino[][3]);

uint8_t select_tetramino();

void equalize_tetreminos(int const_matris[][3], int matris_to_equaled[][3]);

void rotate_tetremino_left(int tetremino[][3]);
void rotate_tetremino_right(int tetremino[][3]);

uint8_t add_tetramino_to_board(int gameboard[][MAX_SIZE], int tetremino[][3], int coordinate, int height);

int check_for_fulled_columns(int gameboard[][100]);

int main()
{
    int tetremino1[3][3] = {
        {1, 1, 1},
        {0, 0, 0},
        {0, 0, 0}};

    int tetremino2[3][3] = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 0}};

    int tetremino3[3][3] = {
        {0, 1, 0},
        {0, 1, 0},
        {0, 0, 0}};

    int tetremino4[3][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};

    int tetremino5[3][3] = {
        {0, 1, 0},
        {0, 1, 0},
        {0, 1, 1}};

    int tetremino6[3][3] = {
        {0, 1, 0},
        {0, 1, 0},
        {0, 1, 0}};

    int tetremino7[3][3] = {
        {0, 1, 1},
        {1, 1, 0},
        {0, 0, 0}};

    int temp_tetremino[3][3];
    char command;
    // int dummy_tetremino2[3][3];
    int coordinate;
    int tetremino_no;
    int score = 0;
    int temp_score = 0;
    uint8_t menu_state;
    uint8_t code;
    uint8_t state;

    srand(time(NULL));
    printf("##########################\n");
    printf("\n");
    printf("Welcome to Tetris game !!!\n");
    printf("\n");
    printf("##########################\n");
    printf("\n");

    printf("\n1- PLAY\n");
    printf("2- QUIT\n");
    scanf("%d", &menu_state);

    while (menu_state == PLAY)
    {
        state = OK;

        printf("When you wanna quit, press (z) button\n");
        printf("Please enter the dimensions of game board: \n");
        printf("Height:\t");
        scanf("%d", &n);
        printf("Width:\t");
        scanf("%d", &m);

        int gameboard[MAX_SIZE][MAX_SIZE];

        reset_board(gameboard);

        print_board(gameboard);

        printf("Let the game begin!!!!\n");
        while (state != GAMEOVER)
        {
            if (state == OK)
            {
                tetremino_no = select_tetramino();
                reset_tetramino(temp_tetremino);
                switch (tetremino_no)
                {
                case 1:
                    equalize_tetreminos(tetremino1, temp_tetremino);
                    break;
                case 2:
                    equalize_tetreminos(tetremino2, temp_tetremino);
                    break;
                case 3:
                    equalize_tetreminos(tetremino3, temp_tetremino);
                    break;
                case 4:
                    equalize_tetreminos(tetremino4, temp_tetremino);
                    break;
                case 5:
                    equalize_tetreminos(tetremino5, temp_tetremino);
                    break;
                case 6:
                    equalize_tetreminos(tetremino6, temp_tetremino);
                    break;
                case 7:
                    equalize_tetreminos(tetremino7, temp_tetremino);
                    break;
                default:
                    printf("WTF is going on ???");
                    break;
                }

                do
                {
                    print_tetremino(temp_tetremino);
                    printf("Rotate tetremino left/ok/right (q/w/e): ");
                    scanf("%s", &command);
                    switch (command)
                    {
                    case 'q':
                        rotate_tetremino_left(temp_tetremino);
                        print_tetremino(temp_tetremino);
                        break;

                    case 'e':
                        rotate_tetremino_right(temp_tetremino);
                        print_tetremino(temp_tetremino);
                        break;
                    case 'w':
                        print_tetremino(temp_tetremino);
                        print_board(gameboard);
                        break;
                    case 'z':
                        menu_state = QUIT;
                        command = 'w';
                        break;
                    default:
                        printf("Wrong command!!!\n");
                        break;
                    }
                } while (command != 'w');
            }
            if (menu_state == QUIT)
                break;

            printf("\nEnter the coordinate: ");
            scanf("%d", &coordinate);

            if (coordinate == 'z')
                break;

            code = add_tetramino_to_board(gameboard, temp_tetremino, coordinate, n);
            if (code == OK)
            {
                print_board(gameboard);
                state = OK;
                temp_score = check_for_fulled_columns(gameboard);
                score = temp_score + score;
                printf("SCORE: %d\n", score);
            }
            else if (code == COORDINATE_ERROR)
            {
                printf("You can't put tetramino here! Try smaller coordinate.");
                state = COORDINATE_ERROR;
            }
            else if (code == GAMEOVER)
            {
                print_board(gameboard);
                printf("###################################################################\n");
                printf("###################################################################\n");
                printf("                           GAMEOVER                                \n");
                printf("                           GAMEOVER                                \n");
                printf("                           GAMEOVER                                \n");
                printf("###################################################################\n");
                printf("###################################################################\n");

                state = GAMEOVER;
            }
        }
        printf("HIGH SCORE: %d\n", score);
        printf("Wanna play again?");
        printf("\n1- PLAY\n");
        printf("2- QUIT\n");
        scanf("%d", &menu_state);
    }
    return 0;
}

uint8_t select_tetramino()
{

    int number;
    number = rand();
    number = (number % 7) + 1;
    return number;
}
void reset_board(int board[MAX_SIZE][MAX_SIZE])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] = 0;
        }
    }
}

void reset_tetramino(int tetramino[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tetramino[i][j] = 0;
        }
    }
}

void print_board(int board[MAX_SIZE][MAX_SIZE])
{
    for (int j = 0; j < m; j++)
    {
        printf(" ---");
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
                printf("|   ");
            else if (board[i][j] == 'X')
                printf("| X ");
            else
                printf("| 1 ");
        }
        printf("|\n");
        for (int j = 0; j < m; j++)
        {
            printf(" ---");
        }
        printf("\n");
    }
    for (int j = 0; j < m; j++)
    {
        printf("| %d ", j + 1);
    }
    printf("|\n\n");
}

void print_tetremino(int tetremino[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tetremino[i][j] == 0)
                printf(" ");
            else if (tetremino[i][j] == 1)
                printf("X");
            // printf("%d", tetremino[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void equalize_tetreminos(int const_matris[][3], int matris_to_equaled[][3])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matris_to_equaled[i][j] = const_matris[i][j];
        }
    }
}

void rotate_tetremino_left(int tetremino[][3])
{
    int rotated_tetramino[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            rotated_tetramino[2 - j][i] = tetremino[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tetremino[i][j] = rotated_tetramino[i][j];
        }
    }
}

void rotate_tetremino_right(int tetremino[][3])
{

    int rotated_tetramino[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            rotated_tetramino[j][2 - i] = tetremino[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tetremino[i][j] = rotated_tetramino[i][j];
        }
    }
}

uint8_t add_tetramino_to_board(int gameboard[][MAX_SIZE], int tetremino[][3], int coordinate, int height)
{
    int tetremino_col = 0;
    int tetremino_row = 0;
    int gameboard_coordinate;
    int i = 0, j = 2, t = 0;
    int a = 0;
    int tetremino_point_flag = 0;
    int gameboard_coordinate_flag = 0;
    int tetremino_add_flag = 1;
    int tetremino_add_flag_1 = 0;
    uint8_t code;

    while (i < 3 && tetremino_point_flag == 0)
    {
        while (j >= 0 && tetremino_point_flag == 0)
        {
            // printf("%d", tetremino[j][i]);
            if (tetremino[j][i] == 1 && tetremino_point_flag == 0)
            {
                tetremino_col = i;
                tetremino_row = j;
                tetremino_point_flag = 1;
            }
            // printf(" | (%d,%d)\n\n", tetremino_col, tetremino_row);
            j--;
        }
        j = 2;
        i++;
    }
    // printf("(%d,%d) - %d\n", tetremino_col, tetremino_row, tetremino_point_flag);

    int x_ctr = 0;
    int y_ctr = 0;
    int tet_x_len = 0;
    int tet_y_len = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tetremino[i][j] == 1)
            {
                x_ctr++;
            }
            if (tetremino[j][i] == 1)
            {
                y_ctr++;
            }
            // printf("\ntetremino[i][j] = %d, tetremino[j][i] = %d || x_ctr = %d, y_ctr = %d\n", tetremino[i][j], tetremino[j][i], x_ctr, y_ctr);
        }
        if (x_ctr > tet_x_len)
        {
            tet_x_len = x_ctr;
        }
        if (y_ctr > tet_y_len)
        {
            tet_y_len = y_ctr;
        }
        x_ctr = 0;
        y_ctr = 0;
    }
    // printf("\nx_len = %d, y_len = %d\n", tet_x_len, tet_y_len);

    if ((coordinate + tet_x_len - 1) > n)
    {
        return COORDINATE_ERROR;
    }

    int flag1 = 1;
    int flag2 = 1;
    int k, p;
    while (t <= height && flag1 == 1)
    {
        k = 0;
        while (k <= 2 - tetremino_row && flag1 == 1)
        {
            p = 0;
            while (p <= 2 - tetremino_col && flag1 == 1)
            {
                // printf("%d) check tetramino(%d,%d)(%d,%d) = %d ", t, tetremino_row + p, tetremino_col + k, t + p, coordinate - 1 + k, gameboard[t + p][coordinate - 1 + k] + tetremino[tetremino_row + p][tetremino_col + k]);
                if (gameboard[t + p][coordinate - 1 + k] + tetremino[tetremino_row + p][tetremino_col + k] == 2)
                {
                    gameboard_coordinate = t - 1;
                    flag1 = 0;
                    // printf("gameboard_coordinate = %d (normal)\n", gameboard_coordinate);
                }
                p++;
            }
            // printf("\n");
            k++;
        }

        if (t == height && flag1 == 1)
        {
            gameboard_coordinate = t - 1;
            flag1 = 0;
            // printf("gameboard_coordinate = %d (max)\n", gameboard_coordinate);
        }

        t++;
    }

    while (tetremino_add_flag_1 == 0)
    {
        /*for (int k = 0; k < 3; k++)
        {
            if (tetremino[tetremino_row][k] == 1 && gameboard[gameboard_coordinate - 1][coordinate + k] == 1)
            {
                printf("\nCheck: (%d,%d)\n", gameboard_coordinate + 1, coordinate + k);
                printf("Gameboard: %d, Tetremino: %d\n", gameboard[gameboard_coordinate - 1][coordinate + k], tetremino[tetremino_row][k]);
                tetremino_add_flag = 0;
            }
        }*/

        if (tetremino_add_flag == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    gameboard[gameboard_coordinate + i - tetremino_row][coordinate + j - 1 - tetremino_col] = tetremino[i][j] + gameboard[gameboard_coordinate + i - tetremino_row][coordinate + j - 1 - tetremino_col];
                    // printf("\nAdd: (%d,%d)\n", gameboard_coordinate + i - 1, coordinate + j);
                    // printf("gameboard:%d\n", gameboard[gameboard_coordinate + i - 1][coordinate + j - 1]);
                }
            }
            tetremino_add_flag_1 = 1;
            code = OK;
        }
        if (tetremino_add_flag == 0)
        {
            // printf("gameboard_coordinate-- : %d\n", gameboard_coordinate);
            gameboard_coordinate--;
        }

        if (gameboard_coordinate - tet_y_len < 0)
        {
            printf("Gameover\n");
            tetremino_add_flag_1 == 1;
            code = GAMEOVER;
            break;
        }
    }
    return code;
}

int check_for_fulled_columns(int gameboard[][100])
{
    int flag = 0;
    int ctr = 0;
    int arr[n];
    int score;

    for (int i = 0; i < n; i++)
    {
        int row_flag = 1;
        for (int j = 0; j < m; j++)
        {
            if (gameboard[i][j] == 0)
            {
                row_flag = 0;
                break;
            }
        }
        if (row_flag == 1)
        {
            arr[ctr++] = i;
            flag = 1;

            for (int j = 0; j < m; j++)
            {
                gameboard[i][j] = 'X';
            }

            print_board(gameboard);
            sleep(1);
        }
        score = score + (m * 100);
    }

    if (flag == 1)
    {
        for (int k = 0; k < ctr; k++)
        {
            int row_to_remove = arr[k];
            for (int i = row_to_remove; i > 0; i--)
            {
                for (int j = 0; j < m; j++)
                {
                    gameboard[i][j] = gameboard[i - 1][j];
                }
            }

            for (int j = 0; j < m; j++)
            {
                gameboard[0][j] = 0;
            }

            for (int i = k + 1; i < ctr; i++)
            {
                arr[i]++;
            }
        }

        print_board(gameboard);
        return score;
    }

    else if (flag == 0)
    {
        return 0;
    }
}
