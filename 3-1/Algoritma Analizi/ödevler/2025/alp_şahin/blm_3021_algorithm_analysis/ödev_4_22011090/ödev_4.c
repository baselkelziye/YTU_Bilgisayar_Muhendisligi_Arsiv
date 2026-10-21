#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Function prototypes
void printMatrix(char **matrix, int size);
char **createMatrix(int size);
void generatePermutationsWithoutRowColConflicts(int *positions, int depth, int size, int *solutions, long long int *iterations);
void displaySolution(int *positions, int size);
int isValidCombination(int *positions, int size);
void generatePermutations(int *positions, int depth, int size, int *solutions, long long int *iterations);
void generateCombinations(int *positions, int start, int depth, int size, int *solutions, long long int *iterations);
int isSafe(char **board, int row, int col, int size);
void solveNQueensBacktrack(char **board, int size, int *solutions, long long int *iterations);
float runPermutationsMode(int size);
float runCombinationsMode(int size);
float runRowColumnPermutationsMode(int size);
float runBacktrackingMode(char **table, int size);



int main(int argc, char *argv[]) {
    int size;
    int choice;
    float timeUsed[4];
    
    printf("Enter the size of the board (N): ");
    scanf("%d", &size);
    
    if (size < 1) {
        printf("Invalid board size. Size must be at least 1.\n");
        return 1;
    }

    char **table = createMatrix(size);

    printf("Choose the method to solve N-Queens:\n");
    printf("1. Brute Force\n");
    printf("2. OPTIMIZED_1\n");
    printf("3. OPTIMIZED_2\n");
    printf("4. Backtracking\n");
    printf("5. Run All Methods\n");
    printf("Enter your choice (1, 2, 3, 4 or 5): ");
    scanf("%d", &choice);

    
    switch(choice) {
        case 1:
            runCombinationsMode(size);
            break;
        case 2:
            runPermutationsMode(size);
            break;
        case 3:
            runRowColumnPermutationsMode(size);
            break;
        case 4:
            runBacktrackingMode(table, size);
            break;
        case 5:
            printf("\n=== Running All Methods ===\n");
        
            timeUsed[0]=runCombinationsMode(size);
            timeUsed[1]=runPermutationsMode(size);
            timeUsed[2]=runRowColumnPermutationsMode(size);
            timeUsed[3]=runBacktrackingMode(table, size);
                
            printf("\n=== All Methods Completed ===\n");
            printf("Brute Force lasts: %f\n",timeUsed[0]);
            printf("Optimized_1 lasts: %f\n",timeUsed[1]);
            printf("Optimized_2 lasts: %f\n",timeUsed[2]);
            printf("Backtracking lasts: %f\n",timeUsed[3]);
            break;
        default:
            printf("Invalid choice! Using default Permutations method...\n");
            
        }
    
    
    // Free allocated memory
    for(int i = 0; i < size; i++) {
        free(table[i]);
    }
    free(table);
    
    return 0;
}

/*
@brief Checks if a given combination of queen positions is valid.

@param positions An array representing the positions of queens.
@param size      The size of the chessboard.

@return 1 if the combination is valid, otherwise 0.
*/
int isValidCombination(int *positions, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            int x1 = positions[i] % size;
            int y1 = positions[i] / size;
            int x2 = positions[j] % size;
            int y2 = positions[j] / size;
            // column check  row check        diagonal check
            if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
                return 0;
            }
        }
    }
    displaySolution(positions, size);
    return 1;
}

/*
@brief Generates all permutations of queen positions by placing one queen in each row.

@param positions  An array to store the queen positions.
@param depth      The current recursion depth (indicating which row is being processed).
@param size       The size of the chessboard.
@param solutions  Pointer to store the count of valid solutions found.
@param iterations Pointer to store the number of iterations performed.


@return void
*/
void generatePermutations(int *positions, int depth, int size, int *solutions, long long int *iterations) {
    int col;
    if (depth == size) { // checking the queen amount
        (*iterations)++;
        if (isValidCombination(positions, size)) {
            (*solutions)++;
        }
        return;
    }
    for (col = 0; col < size; col++) {
        positions[depth] = depth * size + col; //
        generatePermutations(positions, depth + 1, size, solutions, iterations);
    }
}

/*
@brief Generates combinations of positions for queen placements.

@param positions  An array to store the queen positions.
@param start      The starting index for combination generation.
@param depth      The current depth of recursion.
@param size       The size of the chessboard.
@param solutions  Pointer to store the count of valid solutions found.
@param iterations Pointer to store the number of iterations performed.
@param table      The chessboard (unused in this particular logic but kept for consistency).

@return void
*/
void generateCombinations(int *positions, int start, int depth, int size, int *solutions, long long int *iterations) {
    if (depth == size) {
        (*iterations)++;
        if (isValidCombination(positions, size)) {
            (*solutions)++;
        }
        return;
    }
    int i;
    for (i = start; i < size * size; i++) {
        positions[depth] = i;
        generateCombinations(positions, i + 1, depth + 1, size, solutions, iterations);
    }
}

/*
@brief Checks if placing a queen at a given row and column is safe.

@param board The chessboard as a 2D array.
@param row   The row index to place the queen.
@param col   The column index to place the queen.
@param size  The size of the chessboard.

@return 1 if the position is safe, otherwise 0.
*/
int isSafe(char **board, int row, int col, int size) {
    int i, j;
    
    // Check row on left side
    for (j = 0; j < col; j++)
        if (board[row][j] == 1)
            return 0;
    
    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return 0;
    
    // Check lower diagonal on left side
    for (i = row, j = col; i < size && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return 0;
    
    return 1;
}

/*
@brief A utility function that attempts to place queens using backtracking from left to right.
       This function works by trying to place a queen in each row of the current column,
       and recursively solving for the remaining columns.

@param table      The chessboard as a 2D array where 1 represents a queen and 0 represents empty
@param col        The current column being processed (starts from 0)
@param size       The size of the chessboard (N×N)
@param iterations Pointer to store the number of iterations performed
@param solutions  Pointer to store the count of valid solutions found

@return 1 if a solution is found along this path, otherwise 0
*/
int solveNQueensBacktrackUtil(char **table, int col, int size, long long int *iterations, int *solutions) {
    // Count each attempt to place queens in a new configuration
    (*iterations)++;
    
    // Base case: If we've successfully placed queens in all columns (0 to size-1)
    if (col == size) {
        // We found a valid solution, print it
        printf("\nSolution Matrix:\n");
        printMatrix(table, size);
        (*solutions)++;  // Increment the solutions counter
        return 1;  // Return success
    }
    
    // Variable to track if we found any solution through this path
    int res = 0;
    int i;
    // Try placing a queen in each row of the current column
    for (i = 0; i < size; i++) {
        // Check if it's safe to place a queen at position [i][col]
        // This checks row, upper diagonal and lower diagonal conflicts
        if (isSafe(table, i, col, size)) {
            // Place the queen at position [i][col]
            table[i][col] = 1;
            
            // Recursively try to place queens in the remaining columns (col+1 to size-1)
            // The OR operation (||) ensures res becomes 1 if any path leads to a solution, ensure continue to find solutions
            res = solveNQueensBacktrackUtil(table, col + 1, size, iterations, solutions) || res;
            
            // Backtrack: Remove the queen from [i][col] to try other possibilities
            table[i][col] = 0;
        }
    }
    
    // Return whether we found any solution through this path
    return res;
}

/*
@brief Solves the N-Queens problem using backtracking and prints each valid solution.

@param board      The chessboard as a 2D array.
@param size       The size of the chessboard.
@param solutions  Pointer to store the count of valid solutions found.
@param iterations Pointer to store the number of iterations performed.

@return void
*/
void solveNQueensBacktrack(char **table, int size, int *solutions, long long int *iterations) {
    *solutions = 0;
    *iterations = 0;
    
    solveNQueensBacktrackUtil(table, 0, size, iterations, solutions);
    
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            table[i][j] = 0;
}

/*
@brief Runs the Permutations method to solve the N-Queens problem.

@param table The chessboard as a 2D array.
@param size  The size of the chessboard.

@return void
*/
float runPermutationsMode(int size) {
    int solutions = 0;
    long long int iterations = 0;
    int *positions = malloc(size * sizeof(int));
    clock_t start, end;
    double timeUsed;

    printf("\nUsing Permutations method...\n");
    start = clock();
    generatePermutations(positions, 0, size, &solutions, &iterations);
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Number of valid solutions: %d\n", solutions);
    printf("Number of iterations: %lld\n", iterations);
    printf("Execution time: %f seconds\n", timeUsed);
    
    free(positions);
    return timeUsed;
}

/*
@brief Runs the Combinations method to solve the N-Queens problem.

@param table The chessboard as a 2D array.
@param size  The size of the chessboard.

@return void
*/
float runCombinationsMode(int size) {
    int solutions = 0; //solutions is the number of valid solutions
    long long int iterations = 0; //number of iterations
    int *positions = malloc(size * sizeof(int)); //array to store the positions of the queens
    clock_t start, end; //start and end time
    double timeUsed; //time used

    printf("\nUsing Combinations method...\n");
    start = clock();
    generateCombinations(positions, 0, 0, size, &solutions, &iterations); //generating combinations
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC; //calculating the time used

    printf("Number of valid solutions: %d\n", solutions);   //printing the number of valid solutions
    printf("Number of iterations: %lld\n", iterations); //printing the number of iterations
    printf("Execution time: %f seconds\n", timeUsed); //printing the time used
    
    free(positions); //freeing the memory allocated for the positions array

    return timeUsed;
}

/*
@brief Runs the Row-Column Permutations method to solve the N-Queens problem.

@param table The chessboard as a 2D array.
@param size  The size of the chessboard.

@return void
*/
float runRowColumnPermutationsMode(int size) {
    int solutions = 0; //solutions is the number of valid solutions
    long long int iterations = 0; //number of iterations
    int *positions = malloc(size * sizeof(int)); //array to store the positions of the queens
    clock_t start, end; //start and end time
    double timeUsed; //time used

    printf("\nUsing Row-Column Permutations method...\n");
    start = clock();
    generatePermutationsWithoutRowColConflicts(positions, 0, size, &solutions, &iterations); //generating permutations without row-column conflicts
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC; //calculating the time used

    printf("Number of valid solutions: %d\n", solutions); //printing the number of valid solutions
    printf("Number of iterations: %lld\n", iterations); //printing the number of iterations
    printf("Execution time: %f seconds\n", timeUsed); //printing the time used
    
    free(positions);
    return timeUsed;
}

/*
@brief Runs the Backtracking method to solve the N-Queens problem.

@param table The chessboard as a 2D array.
@param size  The size of the chessboard.

@return void
*/
float runBacktrackingMode(char **table, int size) {
    int solutions = 0; //solutions is the number of valid solutions
    long long int iterations = 0; //number of iterations
    clock_t start, end; //start and end time
    double timeUsed; //time used

    printf("\nUsing Backtracking method...\n");
    start = clock();
    solveNQueensBacktrack(table, size, &solutions, &iterations); //solving the N-Queens problem using backtracking
    end = clock();
    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC; //calculating the time used

    printf("Number of valid solutions: %d\n", solutions);
    printf("Number of iterations: %lld\n", iterations);
    printf("Execution time: %f seconds\n", timeUsed);

    return timeUsed;
}

/*
@brief Creates a dynamically allocated 2D matrix (size x size) initialized to 0.

@param size The size of the matrix.

@return A pointer to the allocated 2D matrix.
*/
char **createMatrix(int size)
{
    char **table = NULL; //table is the 2D matrix
    int i;
    table = (char**)malloc((size) * sizeof(char*)); //allocating memory for the matrix  
    for(i = 0; i < size; i++)
    {
        table[i] = (char*)calloc((size), sizeof(char));
    }
    return table;
}

/*
@brief Prints a 2D matrix of given size.

@param matrix The matrix to print.
@param size   The size of the matrix.

@return void
*/
void printMatrix(char **matrix, int size)
{
    int i, j;
    for(i = 0; i < size; i++) //looping through the rows
    {
        for(j=0; j < size; j++) //looping through the columns
        {
            printf("%d ", matrix[i][j]); //printing the matrix
        }
        printf("\n"); //printing a new line
    }
    printf("\n");
}

/*
@brief Displays a solution by placing queens on the board and printing it.

@param positions The array of queen positions.
@param size      The size of the chessboard.

@return void
*/
void displaySolution(int *positions, int size) {
    char **solutionBoard = createMatrix(size);
    int i;
    for (i = 0; i < size; i++) {
        int row = positions[i] / size;
        int col = positions[i] % size;
        solutionBoard[row][col] = 1;
    }
    
    printf("\nSolution Matrix:\n");
    printMatrix(solutionBoard, size);
    
    for (i = 0; i < size; i++) {
        free(solutionBoard[i]);
    }
    free(solutionBoard);
}

/*
@brief Displays a solution for row-column permutations (positions[i] = column of queen in row i).

@param positions The array where positions[i] is the column for the queen in row i.
@param size      The size of the chessboard.

@return void
*/
void displaySolutionFromRowCol(int *positions, int size) {
    char **solutionBoard = createMatrix(size);
    int i;
    for (i = 0; i < size; i++) {
        solutionBoard[i][positions[i]] = 1;
    }
    
    printf("\nSolution Matrix:\n");
    printMatrix(solutionBoard, size);
    
    for (i = 0; i < size; i++) {
        free(solutionBoard[i]);
    }
    free(solutionBoard);
}

/*
@brief Generates permutations of queen placements without using the same row or column more than once.

@param positions  The array to store the column index for the queen in each row.
@param depth      The current row (depth of recursion).
@param size       The size of the chessboard.
@param solutions  Pointer to the count of valid solutions found.
@param iterations Pointer to the number of iterations performed.


@return void
*/
void generatePermutationsWithoutRowColConflicts(int *positions, int depth, int size, int *solutions, long long int *iterations) {
    if (depth == size) {
        (*iterations)++;
        int *linearPositions = malloc(size * sizeof(int));
        int i;
        for (i = 0; i < size; i++) {
            linearPositions[i] = i * size + positions[i];
        }
        
        if (isValidCombination(linearPositions, size)) {
            (*solutions)++;
        }
        free(linearPositions);
        return;
    }
    
    int col;
    for (col = 0; col < size; col++) {
        int valid = 1;
        int j = 0;
        while (j < depth && valid) {
            if (positions[j] == col) {
                valid = 0;
            }
            j++;
        }
        
        if (valid) {
            positions[depth] = col;
            generatePermutationsWithoutRowColConflicts(positions, depth + 1, size, solutions, iterations);
        }
    }
}
