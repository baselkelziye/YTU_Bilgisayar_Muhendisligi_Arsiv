#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void solve(int** board, int n, int placed, int row, int col, int mode, int* results, int writeOutput);
void updateAreas(int** board, int n, int row, int col, int delta, int mode);
int** boardInit(int n);
void printBoard(int** board, int n);
int checkQueensSafe(int n, int** board);
void freeBoard(int** board, int n);

int main() {
    int n; // Size of the board
	int mode; // Mode choosen by user
	int results=0; // Result counter
    clock_t start,end;
    struct timespec start_ms, end_ms;
	double duration;
	double duration_ms;
	 
    printf("Please enter the n value: ");
    scanf("%d", &n);
    
    while (n <= 3) {
        printf("Please enter a positive number grater than 3.\n");
        scanf("%d", &n);
    }

    int** board = boardInit(n);
	printf("\nPlease select a mode:\n");
    printf("1: Detailed mode (shows the solution results)\n");
    printf("2: All approaches (shows only the time taken for each solution, no results are shown)\n");
    printf("\nEnter your choice: ");
    
    scanf("%d", &mode);
    while (mode < 0 || mode > 2) {
        printf("Invalid mode. Please choose again (1 or 2): ");
        scanf("%d", &mode);
    }
    system("cls");
    
    if(mode == 2){     
	    // If mode is 'All approaches', perform all optimizations and measure time for each, and print necessary informations
		// Brute force solution
		
		printf("Starting Brute Force, timer started. This might take some time..\n");
    	start = clock();
    	clock_gettime(CLOCK_MONOTONIC, &start_ms);
    	solve(board, n, 0, 0, 0, 0, &results,0);
    	clock_gettime(CLOCK_MONOTONIC, &end_ms);
    	end = clock();
    	duration = ( double ) ( end - start ) / CLOCKS_PER_SEC;
    	duration_ms = (end_ms.tv_sec - start_ms.tv_sec) * 1000.0 + (end_ms.tv_nsec - start_ms.tv_nsec) / 1000000.0;
    	printf("Brute Force took: %.4f seconds (%lf miliseconds). Found %d solutions.\n\n", duration,duration_ms,results);
    	results = 0;
    	
    	
    	// Optimized1 solution
    	
    	
    	printf("Starting Optimize1, timer started.\n");
    	start = clock();
    	clock_gettime(CLOCK_MONOTONIC, &start_ms);
    	solve(board, n, 0, 0, 0, 1, &results,0);
    	clock_gettime(CLOCK_MONOTONIC, &end_ms);
    	end = clock();
    	duration_ms = (end_ms.tv_sec - start_ms.tv_sec) * 1000.0 + (end_ms.tv_nsec - start_ms.tv_nsec) / 1000000.0;
    	duration = ( double ) ( end - start ) / CLOCKS_PER_SEC;
    	printf("Optimized1 took: %lf seconds (%lf miliseconds). Found %d solutions.\n\n", duration, duration_ms,results);
		results = 0;
		
		
		// Optimized2 solution
		
    	printf("Starting Optimize2, timer started.\n");
    	start = clock();
    	clock_gettime(CLOCK_MONOTONIC, &start_ms);
    	solve(board, n, 0, 0, 0, 2, &results,0);
    	end = clock();
    	clock_gettime(CLOCK_MONOTONIC, &end_ms);
    	duration = ( double ) ( end - start ) / CLOCKS_PER_SEC;
    	duration_ms = (end_ms.tv_sec - start_ms.tv_sec) * 1000.0 + (end_ms.tv_nsec - start_ms.tv_nsec) / 1000000.0;
    	printf("Optimized2 took: %.4f seconds (%lf miliseconds). Found %d solutions.\n\n", duration,duration_ms,results);
		results = 0;
		
		// Backtracking solution

    	printf("Starting Backtracking, timer started.\n");
    	start = clock();
    	clock_gettime(CLOCK_MONOTONIC, &start_ms);
    	solve(board, n, 0, 0, 0, 3, &results,0);
 		clock_gettime(CLOCK_MONOTONIC, &end_ms);
 		end = clock();
 		duration = ( double ) ( end - start ) / CLOCKS_PER_SEC;
    	duration_ms = (end_ms.tv_sec - start_ms.tv_sec) * 1000.0 + (end_ms.tv_nsec - start_ms.tv_nsec) / 1000000.0;
      	printf("Backtracking took: %.4f seconds (%lf miliseconds). Found %d solutions.\n\n", duration,duration_ms,results);

	}else{
		// If mode is not 'All approaches', select specific approach
		printf("Please select an approach: \n0: Brute Force \n1: Optimized1\n2: Optimized2\n3: Backtracking\nEnter your choice: ");
    	scanf("%d", &mode);
    	while (mode < 0 || mode > 3) {
	        printf("Invalid mode. Please choose again (0 - 3): ");
	        scanf("%d", &mode);
    	}
    	
    	// Solve the problem using the chosen mode, with print output enabled
    	system("cls");
		printf("Timer started, processing...\n");
	    start = clock();
	    clock_gettime(CLOCK_MONOTONIC, &start_ms);
	    solve(board, n, 0, 0, 0, mode, &results,1);
	    clock_gettime(CLOCK_MONOTONIC, &end_ms);
		end = clock();
		printf("\n-------------------------------------------\n\n");
		printf("\nAll solutions have been calculated, timer stopped.\n\n");
		duration = ( double ) ( end - start ) / CLOCKS_PER_SEC;
		duration_ms = (end_ms.tv_sec - start_ms.tv_sec) * 1000.0 + (end_ms.tv_nsec - start_ms.tv_nsec) / 1000000.0;
		printf("Process completed in %.4f seconds (%lf miliseconds) with print statements. Found %d solutions.\n(Note: Print statements may significantly affect the execution time with higher n values.) \n(Use the 'All approaches' mode to measure time without the impact of prints.)\n", duration,duration_ms, results);
	}

    freeBoard(board,n);
   

    return 0;
}


/**
 * @brief Recursively solves the n-queens problem, counts and prints the valid solutions.
 * 
 * This function attempts to place all n queens on an n*n chessboard such that no two queens threaten each other. 
 * It recursively explores all possible configurations and increments the result counter for each valid solution.
 * Depending on the user input, it prints the solutions to the console.
 * 
 * @param board A 2D array representing the chessboard. Each cell indicates queen placement or influence.
 *              -1: Queen placed, 0: Safe cell, >0: Under threat by other queens.
 * @param n The size of the chessboard (n x n).
 * @param placed The number of queens currently placed on the board.
 * @param row The current row to start placing queens.
 * @param col The current column to start placing queens in the specified row.
 * @param mode Determines the influence updating strategy:
 *             - 0: No threats are marked, try every cell with brute force.
 *             - 1, 2, 3: Updates specific areas depending on the user's choice (row, column, and diagonals).
 * @param results A pointer to an integer that keeps track of the total number of valid solutions found.
 * @param writeOutput A flag to indicate whether to print the valid solutions to the console.
 *                    - 1: Print the solutions.
 *                    - 0: Do not print.
 * @return void
 */



void solve(int** board, int n, int placed, int row, int col, int mode, int* results, int writeOutput) {
	int i,j;
	
	 // Base case: All queens are placed
    if (placed == n) {
        // Note: In backtracking, the queens are placed one at a time, with each placement being validated to ensure it's safe.
        // Therefore, if we reach this point where all queens are placed, it means their placements are already valid. Otherwise we can not place n queens without violating the rules.
        if ( mode == 3 || checkQueensSafe(n, board)) {  
        	// All queens are safely placed
        	
        	(*results)++;
    		if(writeOutput){
    			printf("\n------------------------------------------\n");
        		printBoard(board, n);	
			}
    		
        }
        return;
    }
    
	// Try placing queens starting from the specified row and column
    for ( i = row; i < n; i++) {
        for ( j = (i == row ? col : 0); j < n; j++) {
            if (board[i][j] == 0) { // Check if the cell is free to place a queen
                board[i][j] = -1; // Place queen
                
                // Update threated areas if mode is not brute force
                if(mode != 0)
                	updateAreas(board, n, i, j, 1, mode);
                	
                solve(board, n, placed + 1, i, j + 1, mode, results, writeOutput);
                // Place the next queen
                
                board[i][j] = 0; // Remove queen
                
                // Revert threats if mode is not brute force
                if(mode != 0)
                	updateAreas(board, n, i, j, -1, mode);

            }
        }
    }
}




/**
 * @brief Updates the areas threatened by a queen on the chessboard.
 * 
 * This function adjusts the influence values on the board for a queen's position. 
 * It marks or removes threats in the row, column, and diagonals depending on the specified mode.
 * 
 * - A positive delta adds threat (e.g., placing a queen).
 * - A negative delta removes threat (e.g., removing a queen).
 *
 * @param board A matrix representing the chessboard.
 * @param n The size of the chessboard (n x n).
 * @param row The row index of the queen's position.
 * @param col The column index of the queen's position.
 * @param delta The value to modify the influence areas (+1 to mark threat, -1 to remove threat).
 * @param mode Determines which areas to update based on the program mode given by user: 
 *             - 1: Update row only.
 *             - 2: Update row and column.
 *             - 3: Update row, column, and diagonals.
 */
 

void updateAreas(int** board, int n, int row, int col, int delta, int mode) {
	int i;
    for ( i = 0; i < n; i++) {
        if (mode >= 1 && i != col) {
            board[row][i] += delta; // Update row
        }
        if (mode >= 2 && i != row) {
            board[i][col] += delta; // Update column
        }
    }

    if (mode >= 3) {
        for ( i = 1; row - i >= 0 && col - i >= 0; i++) {
            board[row - i][col - i] += delta; // Top-left diagonal
        }
        for ( i = 1; row - i >= 0 && col + i < n; i++) {
            board[row - i][col + i] += delta; // Top-right diagonal
        }
        for ( i = 1; row + i < n && col - i >= 0; i++) {
            board[row + i][col - i] += delta; // Bottom-left diagonal
        }
        for ( i = 1; row + i < n && col + i < n; i++) {
            board[row + i][col + i] += delta; // Bottom-right diagonal
        }
    }
}





/**
 * @brief Checks if the current configuration of queens on the board is safe.
 * 
 * This function scans the entire chessboard to be sure that no two queens threaten each other.
 * It performs checks along the same column, row, and diagonals for each queen's position.
 * 
 * @param n The size of the chessboard (n x n).
 * @param board A matrix representing the chessboard, where -1 indicates a queen's position and 0 indicates an empty cell. And positive numbers are threaten cells.
 * @return 1 if the board configuration is safe (no two queens threaten each other), 0 otherwise.
 */


int checkQueensSafe(int n, int** board) {
	int i,j,k;
   
    // Scan through the entire board
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
        	
            if (board[i][j] == -1) {  // A queen is found at board[i][j]
            
            
                 // Check the same column
                for (k = 0; k < n; k++) {
                    if (k != i && board[k][j] == -1) {
                        return 0; // Another queen in the same column.
                    }
                }
                
                
                // Check the same row
                for (k = 0; k < n; k++) {
                    if (k != j && board[i][k] == -1) {
                        return 0; 
						 // Another queen in the same row.
                    }
                }
                
                

                 // Check the top-left diagonal
                for (k = 1; i - k >= 0 && j - k >= 0; k++) {
                    if (board[i - k][j - k] == -1) {
                        return 0; 
						// Another queen is found on the top-left diagonal.
                    }
                }
                
                

                // Check the top-right diagonal
                for (k = 1; i - k >= 0 && j + k < n; k++) {
                    if (board[i - k][j + k] == -1) {
                        return 0;
                    }  // Another queen is found on the top-right diagonal.
                }
                
                

                // Check the bottom-left diagonal
                for (k = 1; i + k < n && j - k >= 0; k++) {
                    if (board[i + k][j - k] == -1) {
                        return 0;
                        // Another queen is found on the bottom-left diagonal.
                    } 
                }
                
                

                // Check the bottom-right diagonal
                for (k = 1; i + k < n && j + k < n; k++) {
                    if (board[i + k][j + k] == -1) {
                        return 0;
                        // Another queen is found on the bottom-right diagonal.
                    }
                }  
            }
        }
    }

    return 1; // All queens are safely placed.
}


/**
 * @brief Initializes an n*n chessboard, allocates memory for it and sets all cells to 0 initially.
 * @param n Size of the chessboard (number of rows and columns).
 * @return Pointer to the initialized chessboard.
 */
 
int** boardInit(int n) {
	int i;
    int** board = (int**) calloc(n, sizeof(int*));
    for ( i = 0; i < n; i++) {
        board[i] = (int*) calloc(n, sizeof(int));
    }
    return board;
}


/**
 * @brief Prints the current state of the chessboard.
 * @param board Pointer to the chessboard.
 * @param n Size of the chessboard (number of rows and columns).
 */

void printBoard(int** board, int n) {
	int i,j;
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            if (board[i][j] == -1) {
                printf(" Q "); // A cell with a queen
            } else {
                printf(" * "); // A cell without a queen
            }
        }
        printf("\n");
    }
}

/**
 * @brief Frees the memory allocated for the chessboard.
 * @param board Pointer to the chessboard.
 * @param n Size of the chessboard (number of rows and columns).
 */

void freeBoard(int** board, int n){
	int i;
	 for ( i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
}

