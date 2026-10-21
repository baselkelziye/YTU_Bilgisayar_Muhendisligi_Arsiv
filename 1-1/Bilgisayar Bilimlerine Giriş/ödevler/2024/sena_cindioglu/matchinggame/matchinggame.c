#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

void draw(int matrix[MAX_SIZE][MAX_SIZE], int N);
void readFromFile(int matris[][MAX_SIZE], char *fileName);
void fill_array_randomly(int N, int matrix[MAX_SIZE][MAX_SIZE]);
int manuelmode(int matrix[MAX_SIZE][MAX_SIZE], int N);
int isBlank(int matrix[MAX_SIZE][MAX_SIZE], int destx, int desty);
void autoMode(int matrix[MAX_SIZE][MAX_SIZE], int N);
int solveMatrix(int matrix[MAX_SIZE][MAX_SIZE], int N, int row, int col, int positions[][4], int num);
void GetPositions(int matrix[MAX_SIZE][MAX_SIZE], int N);

int main()
{

    clock_t start, end;
    double cpu_time_used_manual;
    int N, gametype = 0, filetype, gamemode;
    char fileName[20], cansolved, playagain;
    int matrix[MAX_SIZE][MAX_SIZE] = {{0}};
    printf("welcome to my matching game !\n");
    do
    {
        printf("please choose \n1. Random matrix\n2. Pre-defined example\n3. players scores\n4. exit\n");
        scanf("%d", &gametype);

        if (gametype == 1)
        {
            printf("Enter the size of the game board : ");
            scanf("%d", &N);
            printf("lets start\n");
            fill_array_randomly(N, matrix);
            draw(matrix, N);
            do
            {
                printf("\n can this game be solved ?( press y or n ) ");
                scanf(" %c", &cansolved);
                if (cansolved == 'y' || cansolved == 'Y')
                {
                    do
                    {
                        printf(" \n you want to play at which mode ?\n 1- manuel mode\n 2- auto mode \n 3-turn to the menu\n");
                        scanf("%d", &gamemode);
                        if (gamemode == 1)
                        {
                            start = clock();
                            manuelmode(matrix, N);
                            end = clock();
                            // Calculate the CPU time used
                            cpu_time_used_manual = ((double)(end - start)) / CLOCKS_PER_SEC;

                            printf("Execution time: %f seconds\n", cpu_time_used_manual);
                        }
                        else if (gamemode == 2)
                        {
                            autoMode(matrix, N);
                        }

                    } while (gamemode != 3);
                }
                else if (cansolved == 'n' || cansolved == 'N')
                {
                    fill_array_randomly(N, matrix);
                    draw(matrix, N);
                }
            } while (cansolved == 'n' || cansolved == 'N');
        }

        else if (gametype == 2)
        {
            printf("Enter the size of the game board : (from 3 to 11)\n ");
            scanf("%d", &N);
            printf(" what is the name of the file you want ? (for ex : 7x7.txt) \n ");
            scanf("%s", &fileName);
            readFromFile(matrix, fileName);
            draw(matrix, N);
            do
            {
                printf(" \n you want to play at which mode ?\n 1- manuel mode\n 2- auto mode \n 3- turn to the menu \n");
                scanf("%d", &gamemode);
                if (gamemode == 1)
                {
                    start = clock();
                    manuelmode(matrix, N);
                    end = clock();
                    // Calculate the CPU time used
                    cpu_time_used_manual = ((double)(end - start)) / CLOCKS_PER_SEC;

                    printf("Execution time: %f seconds\n", cpu_time_used_manual);
                }
                else if (gamemode == 2)
                {
                    autoMode(matrix, N);
                }

            } while (gamemode != 3);
        }

    } while (gametype != 4);

    return 0;
}

void draw(int matrix[MAX_SIZE][MAX_SIZE], int N)
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        printf("\n");
        for (k = 0; k < N; k++)
            printf("-------");
        printf("\n");
        for (j = 0; j < N; j++)
            if (matrix[i][j] != 0)
                printf("  %d   |", matrix[i][j]);
            else
                printf("      |", matrix[i][j]);
    }
    printf("\n");
    for (k = 0; k < N; k++)
        printf("-------");
    printf("\n");
}

void readFromFile(int matrix[][MAX_SIZE], char *fileName)
{
    int i, j, temp;
    FILE *data = fopen(fileName, "r");
    if (!data)
    {
        printf("Dosya Acilamadi!");
        return;
    }
    while (!feof(data))
    {
        fscanf(data, "%d %d %d\n", &i, &j, &temp);
        matrix[i][j] = temp;
    }
    fclose(data);

    // Buraya kadar olan bolumde dosyadan okuma yapiliyor. Kodu degistirmeyiniz.
}

void fill_array_randomly(int N, int matrix[MAX_SIZE][MAX_SIZE])
{
    int numbers[N * 2];
    int i, j, k;

    // Initialize the output array with zeros
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // Populate the numbers array with duplicated numbers
    for (i = 0; i < N; i++)
    {
        numbers[i] = i + 1;
        numbers[i + N] = i + 1;
    }

    // Shuffle the numbers array
    srand(time(NULL));
    for (i = N * 2 - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Assign numbers twice in the output array
    k = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            // Find the next empty position to place the number randomly
            int row, col;
            do
            {
                row = rand() % N;
                col = rand() % N;
            } while (matrix[row][col] != 0);

            matrix[row][col] = numbers[k];
            k++;
            if (k == N * 2)
                return;
        }
    }
}

int isBlank(int matrix[MAX_SIZE][MAX_SIZE], int destx, int desty)
{
    return matrix[destx][desty] == 0;
}

int manuelmode(int matrix[MAX_SIZE][MAX_SIZE], int N)
{
    int sourcex, sourcey, destx, desty, blankcount, undocount;
    char undo;
    blankcount = N * N - 2 * N;
    do
    {
        printf("\n source : (x,y)\n ");
        scanf("%d %d", &sourcex, &sourcey);
        printf(" destination : (x,y)\n");
        scanf("%d %d", &destx, &desty);
        // Check if the chosen destination is within the valid range and a blank space
        if (sourcex < N && sourcey < N && desty >= 0 && destx >= 0 && sourcey >= 0 && sourcex >= 0 && destx < N && desty < N && isBlank(matrix, destx, desty) && ((abs(destx - sourcex) == 1 && sourcey == desty) || (abs(desty - sourcey) == 1 && sourcex == destx)))
        {
            matrix[destx][desty] = matrix[sourcex][sourcey];
            draw(matrix, N);
            printf("\n  Move Successful \n");
            blankcount--;
        }

        else
        {
            printf("the move you want to do is not available, please try again");
        }
        printf("\n do you want to UNDO this move?\n (input 'y' or 'n' )\n ");
        scanf(" %c", &undo);
        if (undo == 'y')
        {
            matrix[destx][desty] = 0;
            draw(matrix, N);
            blankcount++;
            undocount++;
        }
    } while (blankcount > 0);
    return undocount;
}

void GetPositions(int matrix[MAX_SIZE][MAX_SIZE], int N)
{
    int NumberPositions[MAX_SIZE][MAX_SIZE];
    int positions[MAX_SIZE][4];

    for (int n = 1; n <= N; n++)
    {
        int found = 0;
        for (int x = 0; x < N; x++)
        {
            if (found < 2)
            {
                for (int y = 0; y < N; y++)
                {
                    int num = matrix[x][y];
                    if (found < 2 && num == n)
                    {
                        if (found == 0)
                        {
                            found = 1;
                            positions[n - 1][0] = x;
                            positions[n - 1][1] = y;
                        }
                        else if (found == 1)
                        {
                            found = 2;
                            positions[n - 1][2] = x;
                            positions[n - 1][3] = y;
                        }
                    }
                }
            }
        }
    }
}

void autoMode(int matrix[MAX_SIZE][MAX_SIZE], int N)
{
    int positions[N][4];
    GetPositions(matrix, N);

    int result = solveMatrix(matrix, N, positions[0][0], positions[0][1], positions, 1);

    if (result)
    {
        printf("\nMatrix Solved:\n");
        draw(matrix, N);
    }
    else
    {
        printf("\nNo solution found!\n");
    }
}

int solveMatrix(int matrix[MAX_SIZE][MAX_SIZE], int N, int row, int col, int positions[][4], int num)
{
    int x1 = positions[num - 1][0];
    int y1 = positions[num - 1][1];
    int x2 = positions[num - 1][2];
    int y2 = positions[num - 1][3];

    // Check if the current position is out of bounds or already filled
    if (row < 0 || row >= N || col < 0 || col >= N || matrix[row][col] != 0)
    {
        return 0;
    }

    // Check if the current position matches the first or second position of the number
    if ((row == x1 && col == y1) || (row == x2 && col == y2))
    {
        // Move to the next number
        if (num == N)
        {
            // Check if the matrix is full and all numbers are matched
            int blankCount = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        blankCount++;
                    }
                }
            }
            if (blankCount == 0)
            {
                return 1; // Matrix is solved
            }
        }
        else
        {
            // Move to the next number's positions
            int nextRow = positions[num][0];
            int nextCol = positions[num][1];

            return solveMatrix(matrix, N, nextRow, nextCol, positions, num + 1);
        }
    }

    // Try moving right
    if (col + 1 < N && matrix[row][col + 1] == num)
    {
        matrix[row][col + 1] = num;

        if (solveMatrix(matrix, N, row, col + 1, positions, num))
        {
            return 1; // Matrix is solved
        }

        matrix[row][col] = 0;
    }

    // Try moving left
    if (col - 1 >= 0 && matrix[row][col - 1] == num)
    {
        matrix[row][col - 1] = num;

        if (solveMatrix(matrix, N, row, col - 1, positions, num))
        {
            return 1; // Matrix is solved
        }

        matrix[row][col] = 0;
    }

    // Try moving down
    if (row + 1 < N && matrix[row + 1][col] == num)
    {
        matrix[row + 1][col] = num;

        if (solveMatrix(matrix, N, row + 1, col, positions, num))
        {
            return 1; // Matrix is solved
        }

        matrix[row][col] = 0;
    }

    // Try moving up
    if (row - 1 >= 0 && matrix[row - 1][col] == num)
    {
        matrix[row - 1][col] = num;

        if (solveMatrix(matrix, N, row - 1, col, positions, num))
        {
            return 1; // Matrix is solved
        }

        matrix[row][col] = 0;
    }

    return 0; // No solution found
}
