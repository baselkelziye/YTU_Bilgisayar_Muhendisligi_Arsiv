#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printBoard(int **board, int n);
int isSafeBacktracking(int **board, int n, int row, int col);
int isValidPosition(int **board, int n);
void get2DCoordinates(int index, int *row, int *col, int n);
int solveNQueensBacktrackingUtil(int **board, int n, int col, int *total_solutions);
void solveNQueensBacktracking(int n, int *total_solutions, double *execution_time);
int next_permutation(int *array, int n);
void solveNQueensOptimized1(int n, int *total_solutions, double *execution_time);
void solveNQueensOptimized2(int n, int *total_solutions, double *execution_time);
void solveNQueensBruteForce(int n, int *total_solutions, double *execution_time);
void runAllMethods(int n);

/*
@brief print the board to the console
@param board 2D array representing the game board
@param n size of the board
*/
void printBoard(int **board, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                printf("Q ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
/*
@brief check if it is safe to place a queen at board[row][col]
@param board 2D array representing the game board
@param n size of the board
@param row row index
@param col column index
@return 1 if it is safe, 0 if not safe
*/
int isSafeBacktracking(int **board, int n, int row, int col)
{
    int i, j;

    // Checking if there is a queen in the same row
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return 0;
    }

    // Checking if there is a queen in the upper diagonal on the left side
    i = row;
    j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j])
            return 0;
        i--;
        j--;
    }

    // Checking if there is a queen in the lower diagonal on the left side
    i = row;
    j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j])
            return 0;
        i++;
        j--;
    }

    // If no conflicts, it's safe to place the queen
    return 1;
}

/*
@brief check if the board is valid
@param board 2D array representing the game board
@param n size of the board
@return 1 if the board is valid, 0 if not valid
*/
int isValidPosition(int **board, int n)
{
    int i, j, k, l;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {

            if (board[i][j] == 1)
            {

                // Checking if there is a queen in the same row
                k = 0;
                while (k < n)
                {
                    if (k != j && board[i][k] == 1)
                        return 0;
                    k++;
                }
                // Checking if there is a queen in the same column
                k = 0;
                while (k < n)
                {
                    if (k != i && board[k][j] == 1)
                        return 0;
                    k++;
                }
                // Checking if there is a queen in the same diagonal
                k = 0;
                while (k < n)
                {
                    l = 0;
                    while (l < n)
                    {
                        if (k != i && l != j && board[k][l] == 1)
                        {
                            if (k - l == i - j || k + l == i + j)
                                return 0;
                        }
                        l++;
                    }
                    k++;
                }
            }
        }
    }
    return 1;
}

/*
/*
@brief converts a 1D index to 2D coordinates on the board
@param index 1D index
@param row pointer to store the row index
@param col pointer to store the column index
@param n size of the board
*/
void get2DCoordinates(int index, int *row, int *col, int n)
{
    *row = index / n;
    *col = index % n;
}

/*
@brief solve the N-Queens problem using backtracking algorithm
@param board 2D array representing the game board
@param n size of the board
@param col column index
@param total_solutions pointer to store the total number of solutions
*/
int solveNQueensBacktrackingUtil(int **board, int n, int col, int *total_solutions)
{
    int i;

    // If all queens are placed print the board
    if (col >= n)
    {
        (*total_solutions)++;
        printf("Cozum %d:\n", *total_solutions);
        printBoard(board, n);
        return 0;
    }

    // Trying to place a queen in each row of the current column
    for (i = 0; i < n; i++)
    {
        if (isSafeBacktracking(board, n, i, col))
        {
            board[i][col] = 1;
            // Recursively place the rest of the queens in the next column
            solveNQueensBacktrackingUtil(board, n, col + 1, total_solutions);
            // If placing the queen in board[i][col] doesn't lead to a solution, remove the queen
            board[i][col] = 0;
        }
    }

    return 0;
}

/*
@brief solve the N-Queens problem using backtracking algorithm and print the total number of solutions and execution time
@param n size of the board
@param total_solutions pointer to store the total number of solutions
@param execution_time pointer to store the execution time
*/
void solveNQueensBacktracking(int n, int *total_solutions, double *execution_time)
{
    clock_t start = clock();
    int **board = (int **)malloc(n * sizeof(int *));
    int i;
    *total_solutions = 0;

    for (i = 0; i < n; i++)
    {
        board[i] = (int *)calloc(n, sizeof(int));
    }
    // Starting from the first column find all solutions
    solveNQueensBacktrackingUtil(board, n, 0, total_solutions);

    clock_t end = clock();
    *execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    for (i = 0; i < n; i++)
    {
        free(board[i]);
    }
    free(board);

    printf("BACKTRACKING\n");
    printf("Toplam cozum: %d\n", *total_solutions);
    printf("Calisma suresi: %f saniye\n\n", *execution_time);
}

/*
@brief find the next permutation of the array
@param array array to find the next permutation
@param n size of the array
@return 1 if there is a next permutation, 0 if there is no next permutation
*/
int next_permutation(int *array, int n)
{
    int i = n - 2;
    int k, l;

    while (i >= 0 && array[i] >= array[i + 1])
    {
        i--;
    }

    if (i < 0)
        return 0;

    int j = n - 1;
    while (array[j] <= array[i])
    {
        j--;
    }

    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;

    k = i + 1;
    l = n - 1;
    while (k < l)
    {
        int temp = array[k];
        array[k] = array[l];
        array[l] = temp;
        k++;
        l--;
    }

    return 1;
}

/*
@brief a mode where queens are placed knowing that they cannot be in the same row
@param n size of the board
@param total_solutions pointer to store the total number of solutions
@param execution_time pointer to store the execution time
*/
void solveNQueensOptimized1(int n, int *total_solutions, double *execution_time)
{
    clock_t start = clock();
    int *columns = (int *)malloc(n * sizeof(int));
    int i, j;
    *total_solutions = 0;
    int finished = 0;

    // columns array stores the column index of the queens. columns[i] = j means there is a queen in the i. row and j. column
    for (i = 0; i < n; i++)
    {
        columns[i] = 0;
    }

    // trying all possible column combinations
    while (!finished)
    {
        int is_valid = 1;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                // checking if there are queens in the same column or diagonal
                if (columns[i] == columns[j] || abs(columns[i] - columns[j]) == abs(i - j))
                {
                    is_valid = 0;
                    break;
                }
            }
            if (!is_valid)
                break;
        }

        if (is_valid)
        {
            (*total_solutions)++;
            printf("Cozum %d:\n", *total_solutions);

            int **board = (int **)malloc(n * sizeof(int *));
            for (i = 0; i < n; i++)
            {
                board[i] = (int *)calloc(n, sizeof(int));
                board[i][columns[i]] = 1;
            }
            printBoard(board, n);

            for (i = 0; i < n; i++)
            {
                free(board[i]);
            }
            free(board);
        }

        // generating the next column combination
        int row = n - 1;
        while (row >= 0 && columns[row] == n - 1)
        {
            columns[row] = 0;
            row--;
        }

        if (row < 0)
        {
            finished = 1;
        }
        else
        {
            columns[row]++;
        }
    }

    clock_t end = clock();
    *execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("OPTIMIZED 1\n");
    printf("Toplam cozum: %d\n", *total_solutions);
    printf("Calisma suresi: %f saniye\n\n", *execution_time);

    free(columns);
}

/*
@brief: a mode where queens are placed knowing that they cannot be in the same row or diagonal
@param n size of the board
@param total_solutions pointer to store the total number of solutions
@param execution_time pointer to store the execution time
*/
void solveNQueensOptimized2(int n, int *total_solutions, double *execution_time)
{
    clock_t start = clock();

    int *columns = (int *)malloc(n * sizeof(int));
    int i, j;
    *total_solutions = 0;

    for (i = 0; i < n; i++)
    {
        columns[i] = i;
    }

    do
    {
        int is_valid = 1;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                // checking if there are queens in the same diagonal only
                // because we know that they cannot be in the same row or column
                if (abs(columns[i] - columns[j]) == abs(i - j))
                {
                    is_valid = 0;
                    break;
                }
            }
            if (!is_valid)
                break;
        }

        if (is_valid)
        {
            (*total_solutions)++;
            printf("Cozum %d:\n", *total_solutions);

            int **board = (int **)malloc(n * sizeof(int *));
            for (i = 0; i < n; i++)
            {
                board[i] = (int *)calloc(n, sizeof(int));
                board[i][columns[i]] = 1;
            }
            printBoard(board, n);

            for (i = 0; i < n; i++)
            {
                free(board[i]);
            }
            free(board);
        }
    } while (next_permutation(columns, n));

    clock_t end = clock();
    *execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("OPTIMIZED 2\n");
    printf("Toplam cozum: %d\n", *total_solutions);
    printf("Calisma suresi: %f saniye\n\n", *execution_time);

    free(columns);
}

/*
@brief generate all board configurations and check if they are valid
@param n size of the board
@param total_solutions pointer to store the total number of solutions
@param execution_time pointer to store the execution time
*/
void solveNQueensBruteForce(int n, int *total_solutions, double *execution_time)
{
    clock_t start = clock();

    int **board = (int **)malloc(n * sizeof(int *));
    int i, j;

    for (i = 0; i < n; i++)
    {
        board[i] = (int *)calloc(n, sizeof(int));
    }

    int *queens = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        queens[i] = i;
    }

    *total_solutions = 0;
    int finished = 0;
    int total_cells = n * n;

    while (!finished)
    {

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                board[i][j] = 0;
            }
        }

        for (i = 0; i < n; i++)
        {
            int row, col;
            get2DCoordinates(queens[i], &row, &col, n);
            board[row][col] = 1;
        }
        // first we place the queens on the board and then check if it is valid
        if (isValidPosition(board, n))
        {
            (*total_solutions)++;
            printf("Cozum %d:\n", *total_solutions);
            printBoard(board, n);
        }

        // generating the next queen positions
        i = n - 1;
        while (i >= 0 && queens[i] == total_cells - n + i)
        {
            i--;
        }

        if (i < 0)
        {
            finished = 1;
        }
        else
        {
            queens[i]++;
            for (j = i + 1; j < n; j++)
            {
                queens[j] = queens[j - 1] + 1;
            }
        }
    }

    clock_t end = clock();
    *execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    for (i = 0; i < n; i++)
    {
        free(board[i]);
    }

    printf("BRUTE FORCE\n");
    printf("Toplam cozum: %d\n", *total_solutions);
    printf("Calisma suresi: %f saniye\n\n", *execution_time);

    free(board);
    free(queens);
}

/*
@brief run all methods and print the results
@param n size of the board
*/
void runAllMethods(int n)
{

    int total_solutions_optimized1;
    double execution_time_optimized1;

    int total_solutions_optimized2;
    double execution_time_optimized2;

    int total_solutions_brute_force;
    double execution_time_brute_force;

    int total_solutions_backtracking;
    double execution_time_backtracking;

    solveNQueensOptimized1(n, &total_solutions_optimized1, &execution_time_optimized1);

    solveNQueensOptimized2(n, &total_solutions_optimized2, &execution_time_optimized2);

    solveNQueensBruteForce(n, &total_solutions_brute_force, &execution_time_brute_force);

    solveNQueensBacktracking(n, &total_solutions_backtracking, &execution_time_backtracking);

    printf("Brute Force:\n");
    printf("Toplam cozum: %d\n", total_solutions_brute_force);
    printf("Calisma suresi: %f saniye\n\n", execution_time_brute_force);
    printf("--------------------\n");

    printf("Optimized 1:\n");
    printf("Toplam cozum: %d\n", total_solutions_optimized1);
    printf("Calisma süresi: %f saniye\n\n", execution_time_optimized1);
    printf("--------------------\n");

    printf("Optimized 2:\n");
    printf("Toplam cozum: %d\n", total_solutions_optimized2);
    printf("Calisma suresi: %f saniye\n\n", execution_time_optimized2);
    printf("--------------------\n");

    printf("Backtracking:\n");
    printf("Toplam cozum: %d\n", total_solutions_backtracking);
    printf("Calisma suresi: %f saniye\n\n", execution_time_backtracking);
    printf("--------------------\n");
}
/*
@brief main function
*/
int main()
{
    int n;
    int total_solutions;
    double execution_time;
    int exit = 0;
    printf("N-Queens problemi icin tahta boyutunu giriniz: ");
    scanf("%d", &n);

    while (exit != 1)
    {
        printf("1-Brute Force\n2-Backtracking\n3-Optimized 1\n4-Optimized 2\n5-Tum yontemler\n0-Cikis\n");
        int choice;
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            solveNQueensBruteForce(n, &total_solutions, &execution_time);
            break;

        case 2:
            solveNQueensBacktracking(n, &total_solutions, &execution_time);
            break;

        case 3:
            solveNQueensOptimized1(n, &total_solutions, &execution_time);
            break;

        case 4:
            solveNQueensOptimized2(n, &total_solutions, &execution_time);
            break;

        case 5:
            runAllMethods(n);
            break;

        case 0:
            printf("Cikis yapildi.\n");
            exit = 1;
            break;

        default:
            printf("Gecersiz secim.\n");
            break;
        }
    }

    return 0;
}

