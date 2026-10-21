#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printBoard(int **board, int N);
void bruteForce(int **board, int N, int row, int col, int queensPlaced, long long *counter);
void optimized1(int **board, int N, int row, int col, int queensPlaced, long long *counter, int *rowOccupied);
void optimized2(int **board, int N, int row, int col, int queensPlaced, long long *counter, int *rowOccupied, int *colOccupied);
void backtracking(int **board, int N, int col, long long *counter);
int isBoardValid(int **board, int N);
int isSafe(int **board, int N, int row, int col);

int main() {
    int N, i, choice;
    long long counter;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the matrix: ");
    scanf("%d", &N);

    int **board = (int **)malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        board[i] = (int *)calloc(N, sizeof(int));
    }
    int *rowOccupied = (int *)calloc(N, sizeof(int));
    int *colOccupied = (int *)calloc(N, sizeof(int));

    printf("Choose a mode:\n");
    printf("1: Brute force\n");
    printf("2: Optimized 1\n");
    printf("3: Optimized 2\n");
    printf("4: Backtracking\n");
    printf("5: Run all\n");
    printf("Choice:");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            counter = 0;
            start = clock();
            bruteForce(board, N, 0, 0, 0, &counter);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("BruteForce: %lld possibilities, %.6f sec\n", counter, cpu_time_used);
            break;
        case 2:
            counter = 0;
            start = clock();
            optimized1(board, N, 0, 0, 0, &counter, rowOccupied);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Optimized1: %lld possibilities, %.6f sec\n", counter, cpu_time_used);
            break;
        case 3:
            counter = 0;
            start = clock();
            optimized2(board, N, 0, 0, 0, &counter, rowOccupied, colOccupied);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Optimized2: %lld possibilities, %.6f sec\n", counter, cpu_time_used);
            break;
        case 4:
            counter = 0;
            start = clock();
            backtracking(board, N, 0, &counter);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Backtracking: %lld tries, %.6f sec\n", counter, cpu_time_used);
            break;
        case 5:
            counter = 0;
            start = clock();
            bruteForce(board, N, 0, 0, 0, &counter);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("BruteForce: %lld possibilities, %.6f sec\n", counter, cpu_time_used);

            counter = 0;
            start = clock();
            optimized1(board, N, 0, 0, 0, &counter, rowOccupied);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Optimized1: %lld possibilities, %.6f sec\n", counter, cpu_time_used);

            counter = 0;
            start = clock();
            optimized2(board, N, 0, 0, 0, &counter, rowOccupied, colOccupied);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Optimized2: %lld possibilities, %.6f sec\n", counter, cpu_time_used);

            counter = 0;
            start = clock();
            backtracking(board, N, 0, &counter);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Backtracking: %lld tries, %.6f sec\n", counter, cpu_time_used);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    for (i = 0; i < N; i++) {
        free(board[i]);
    }
    free(board);
    free(rowOccupied);
    free(colOccupied);

    return 0;
}

/*
@brief Prints the chessboard with the current positions of queens.
 
@param board The NxN board represented as a 2D array.
@param N The size of the board (NxN).

@return
*/
void printBoard(int **board, int N) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
@brief Solves the n-Queens problem using brute force.

@param board The NxN board represented as a 2D array.
@param N The size of the board (NxN).
@param row Current row being processed.
@param col Current column being processed.
@param queensPlaced Number of queens placed so far.
@param counter Pointer to a variable to count the number of possibilities.

@return
*/
void bruteForce(int **board, int N, int row, int col, int queensPlaced, long long *counter) {
    if (queensPlaced == N) {
        if (isBoardValid(board, N)) {
            printBoard(board, N);
        }
        (*counter)++;
        return;
    }

    if (row == N) {
        return;
    }

    if (col == N) {
        bruteForce(board, N, row + 1, 0, queensPlaced, counter);
        return;
    }

    // Place queen
    board[row][col] = 1;
    bruteForce(board, N, row, col + 1, queensPlaced + 1, counter);

    // Don't place queen
    board[row][col] = 0;
    bruteForce(board, N, row, col + 1, queensPlaced, counter);
}

/*
@brief Solves the n-Queens problem with optimization that prevents queens from being in the same row.

@param board The NxN board represented as a 2D array.
@param N The size of the board (NxN).
@param row Current row being processed.
@param col Current column being processed.
@param queensPlaced Number of queens placed so far.
@param counter Pointer to a variable to count the number of possibilities.
@param rowOccupied Array to track which rows are occupied.

@return
*/
void optimized1(int **board, int N, int row, int col, int queensPlaced, long long *counter, int *rowOccupied) {
    if (queensPlaced == N) {
        if (isBoardValid(board, N)) {
            printBoard(board, N);
        }
        (*counter)++;
        return;
    }

    if (row == N) {
        return;
    }

    if (col == N) {
        optimized1(board, N, row + 1, 0, queensPlaced, counter, rowOccupied);
        return;
    }

    // Place queen only if no other queen in the same row
    if (!rowOccupied[row]) {
        board[row][col] = 1;
        rowOccupied[row] = 1;
        optimized1(board, N, row + 1, 0, queensPlaced + 1, counter, rowOccupied);
        board[row][col] = 0;
        rowOccupied[row] = 0;
    }

    // Don't place queen
    optimized1(board, N, row, col + 1, queensPlaced, counter, rowOccupied);
}

/*
@brief Solves the n-Queens problem with optimization that prevents queens from being in the same row and column.

@param board The NxN board represented as a 2D array.
@param N The size of the board (NxN).
@param row Current row being processed.
@param col Current column being processed.
@param queensPlaced Number of queens placed so far.
@param counter Pointer to a variable to count the number of possibilities.
@param rowOccupied Array to track which rows are occupied.
@param colOccupied Array to track which columns are occupied.

@return
*/
void optimized2(int **board, int N, int row, int col, int queensPlaced, long long *counter, int *rowOccupied, int *colOccupied) {
    if (queensPlaced == N) {
        if (isBoardValid(board, N)) {
            printBoard(board, N);
        }
        (*counter)++;
        return;
    }

    if (row == N) {
        return;
    }

    if (col == N) {
        optimized2(board, N, row + 1, 0, queensPlaced, counter, rowOccupied, colOccupied);
        return;
    }

    // Place queen only if no other queen in the same row and column
    if (!rowOccupied[row] && !colOccupied[col]) {
        board[row][col] = 1;
        rowOccupied[row] = 1;
        colOccupied[col] = 1;
        optimized2(board, N, row + 1, 0, queensPlaced + 1, counter, rowOccupied, colOccupied);
        board[row][col] = 0;
        rowOccupied[row] = 0;
        colOccupied[col] = 0;
    }

    // Don't place queen
    optimized2(board, N, row, col + 1, queensPlaced, counter, rowOccupied, colOccupied);
}

/*
@brief Solves the n-Queens problem using the backtracking approach.

@param board The NxN board represented as a 2D array.
@param N The size of the board (NxN).
@param col Current column being processed.
@param counter Pointer to a variable to count the number of possibilities.

@return
*/
void backtracking(int **board, int N, int col, long long *counter) {
    (*counter)++;
    if (col >= N) {
        printBoard(board, N);
        return;
    }

    int i;
    for (i = 0; i < N; i++) {
        if (isSafe(board, N, i, col)) {
            board[i][col] = 1;
            backtracking(board, N, col + 1, counter);
            board[i][col] = 0; // Backtrack
        }
    }
}

/*
@brief Checks if the current board configuration is valid.

@param board The NxN board represented as a 2D array.
@param N The size of the board (NxN).
@return Returns 1 if the board is valid, 0 otherwise.

@return Returns 1 if the board is valid, 0 otherwise.
*/
int isBoardValid(int **board, int N) {
    int i, j, k;
    int rowCount, colCount;

    // Check rows and columns
    for (i = 0; i < N; i++) {
        rowCount = 0;
        colCount = 0;
        for (j = 0; j < N; j++) {
            if (board[i][j] == 1) rowCount++;
            if (board[j][i] == 1) colCount++;
        }
        if (rowCount > 1 || colCount > 1) return 0;
    }

    // Check diagonals
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                // Check all four diagonals
                for (k = 1; k < N; k++) {
                    // Check upper left diagonal
                    if (i - k >= 0 && j - k >= 0 && board[i - k][j - k] == 1) return 0;
                    
                    // Check upper right diagonal
                    if (i - k >= 0 && j + k < N && board[i - k][j + k] == 1) return 0;

                    // Check lower left diagonal
                    if (i + k < N && j - k >= 0 && board[i + k][j - k] == 1) return 0;

                    // Check lower right diagonal
                    if (i + k < N && j + k < N && board[i + k][j + k] == 1) return 0;

                }
            }
        }
    }

    return 1;
}

/*
@brief Checks if placing a queen at the given position is safe.

@param board The NxN board represented as a 2D array.
@param N The size of the board (NxN).
@param row Row index of the position to check.
@param col Column index of the position to check.

@return Returns 1 if it is safe to place a queen, 0 otherwise.
*/
int isSafe(int **board, int N, int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}