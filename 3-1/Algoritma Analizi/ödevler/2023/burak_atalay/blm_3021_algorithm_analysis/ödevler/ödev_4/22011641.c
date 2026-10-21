#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define PRINT 1 //you can make it 0 to not print solutions

typedef struct helper{ //helper arrays for isCorrectSolution functions
	int* rows; //to check if a row is used	
	int* cols; //to check if a column is used
	int* mainDiagonal; //to check if a main diagonal is used
	int* secondaryDiagonal; //to check if a secondary diagonal is used
}HELPER;

typedef struct info{ //to store informations about called functions' performance
	long long calls; //how many times the function call itself
	long long moves; //how many moves function will make
	int solutions; //how many solutions function will find
}INFO;

int isCorrectSolutionBruteForce(int** board, int n, HELPER* helper);
int isCorrectSolutionOptimized1(int** board, int n, HELPER* helper);
int isCorrectSolutionOptimized2(int** board, int n, HELPER* helper);
void bruteForce(int** board, int n, int index, int q, HELPER* helper, INFO* info);
void optimized1(int** board, int n, int q, HELPER* helper, INFO* info);
void optimized2(int** board, int n, int* cols, int q, HELPER* helper, INFO* info);
void backtracking(int** board, int n, int* cols, int* mainDiagonal, int* secondaryDiagonal, int q, INFO* info);
void drawBoard(int** board, int n);
int** createBoard(int n);
HELPER* createHelperArrays(int n);
void resetHelperArrays(HELPER* helper, int n);
void freeBoard(int** board, int n);
void freeHelperArrays(HELPER* helper);
void bruteForceMode(int n);
void optimized1Mode(int n);
void optimized2Mode(int n);
void backtrackingMode(int n);
void allModes(int n);
void menu();
void clearConsole();

int main(){
	
	menu();
	
	return 0;
}

/*
@brief asks the user which mode to run after taking the input n and runs the selected mode. 

@param 

@return 
*/
void menu(){
	int answer, n; 
	
	do{
		clearConsole(); //clearing console after one iteration
		printf("n: ");
		scanf("%d", &n);
		printf("\n--------------------------------------------------\n");
		printf("enter 1 for brute force mode\nenter 2 for optimized 1 mode\nenter 3 for optimized 2 mode\n");
		printf("enter 4 for backtracking mode\nenter 5 for all modes\nmode: ");
		scanf("%d", &answer);
		printf("--------------------------------------------------\n");
		
		if(answer == 1) bruteForceMode(n);
		else if(answer == 2) optimized1Mode(n);
		else if(answer == 3) optimized2Mode(n);
		else if(answer == 4) backtrackingMode(n);
		else if(answer == 5) allModes(n);
		else{
			printf("\n--------------------------------------------------\n");
			printf("Invalid choice...");
			printf("\n--------------------------------------------------\n");
		}
		
		printf("\n--------------------------------------------------\n");
		printf("enter 1 if you want to continue\nenter 0 if you want to exit\nanswer: ");
		scanf("%d", &answer);
	} while(answer);
}

/*
@brief tries to place and not to place the qth queen in the current cell and makes a call for both possibilities. 

@param board: nxn board.
@param n: the size of the board.
@param index: the cell on the board that the function will try to place a queen (it can take values between 0 and n^2 - 1).
@param q: current queen the function will try to place.
@param helper: stores helper arrays that will be used in isCorrectSolutionBruteForce
@param info: struct that has three variables about function performance

@return 
*/

void bruteForce(int** board, int n, int index, int q, HELPER* helper, INFO* info){
	info->calls++;
	if(q == n){ //since q is given 0 at the initial call, if it is n in this call, then we placed the nth queen in the prior call
		info->moves++;
		if(isCorrectSolutionBruteForce(board, n, helper)){
			if(PRINT){ //if macro is 1 then it prints the solution
				printf("\nSolution %d...\n", info->solutions + 1);
				drawBoard(board, n);	
			}
			info->solutions++;
		}
		return;
	}
	
	if(index >= n * n) return; //if index is n^2 then it is out of bounds since we have n^2 cells
	int row = index / n, col = index % n; 
	
	board[row][col] = 1; //placing the qth queen in this cell
	bruteForce(board, n, index + 1, q + 1, helper, info); //making call to place (q+1)th queen in the next cell
	
	board[row][col] = 0; //not placing the qth queen in this cell
	bruteForce(board, n, index + 1, q, helper, info); //making call to place qth queen in the next cell
}

/*
@brief reserves qth row to qth queen. tries to place qth queen in each column in the qth row. 

@param board: nxn board.
@param n: the size of the board.
@param q: current queen the function will try to place.
@param helper: stores helper arrays that will be used in isCorrectSolutionOptimized1
@param info: struct that has three variables about function performance

@return 
*/

void optimized1(int** board, int n, int q, HELPER* helper, INFO* info){
	info->calls++;
	if(q == n){
		info->moves++;
		if(isCorrectSolutionOptimized1(board, n, helper)){
			if(PRINT){
				printf("\nSolution %d...\n", info->solutions + 1);
				drawBoard(board, n);	
			}
			info->solutions++;
		}
		return;
	}
	
	int i;
	for(i=0;i<n;i++){ //iterates over each column in the qth row
		board[q][i] = 1; //place qth queen in ith column of qth row
		optimized1(board, n, q + 1, helper, info); //making a call to place (q+1)th queen
		board[q][i] = 0; //unmarking this cell since we tried each possibility after placing qth queen in this cell	
	}
}

/*
@brief reserves qth row to qth queen. tries to place qth queen in each column in the qth row if that column is not used by prior queens. 

@param board: nxn board.
@param n: the size of the board.
@param cols: array to check whether a specific column is used or not.
@param q: current queen the function will try to place.
@param helper: stores helper arrays that will be used in isCorrectSolutionOptimized2
@param info: struct that has three variables about function performance

@return 
*/

void optimized2(int** board, int n, int* cols, int q, HELPER* helper, INFO* info){
	info->calls++;
	if(q == n){
		info->moves++;
		if(isCorrectSolutionOptimized2(board, n, helper)){
			if(PRINT){
				printf("\nSolution %d...\n", info->solutions + 1);
				drawBoard(board, n);	
			}
			info->solutions++;
		}
		return;
	}
	
	int i;
	for(i=0;i<n;i++){ //iterates over each column in the qth row
		if(!cols[i]){ //if ith column is not used
			board[q][i] = 1; //placing the queen in qth row and ith column
			cols[i] = 1; //marking the ith column 
			optimized2(board, n, cols, q + 1, helper, info); //making a call to place (q+1)th queen 
			board[q][i] = 0; //unmarking this cell since we tried each possibility after placing qth queen in this cell	
			cols[i] = 0; //unmarking the ith column 
		}	
	}
}

/*
@brief reserves qth row to qth queen. tries to place qth queen in each column in the qth row if that column is not used by prior queens
and also that cell is not part of a used main diagonal or secondary diagonal. 

@param board: nxn board.
@param n: the size of the board.
@param cols: array to check whether a specific column is used or not.
@param mainDiagonal: array to check whether a specific main diagonal is used or not.
@param secondaryDiagonal: array to check whether a specific secondary diagonal is used or not.
@param q: current queen the function will try to place.
@param info: struct that has three variables about function performance

@return 
*/

void backtracking(int** board, int n, int* cols, int* mainDiagonal, int* secondaryDiagonal, int q, INFO* info){
	info->calls++;
	if(q == n){ //no need to check if it is true solution since function only puts queens into valid places
		info->moves++;
		if(PRINT){
			printf("\nSolution %d...\n", info->solutions + 1);
			drawBoard(board, n);	
		}
		info->solutions++;
		return;
	}
	
	int i;
	for(i=0;i<n;i++){ //iterating over each column
		if(!cols[i] && !mainDiagonal[q - i + n - 1] && !secondaryDiagonal[q + i]){ //if ith column and both diagonals are not used  
			board[q][i] = 1; //placing the queen in qth row and ith column
			cols[i] = 1; //marking the ith column 
			mainDiagonal[q - i + n - 1] = 1; //marking the main diagonal
			secondaryDiagonal[q + i] = 1; //marking the secondary diagonal
			backtracking(board, n, cols, mainDiagonal, secondaryDiagonal, q + 1, info); //making a call to place (q+1)th queen
			board[q][i] = 0; //unmarking this cell since we tried each possibility after placing qth queen in this cell		 
			cols[i] = 0; //unmarking the ith column 
			mainDiagonal[q - i + n - 1] = 0; //unmarking the main diagonal
			secondaryDiagonal[q + i] = 0; //unmarking the secondary diagonal
		}
	}
}

/*
@brief checks whether the given board is valid or not by iterating the board once. it is for brute force solutions.

@param board: nxn board.
@param n: the size of the board.

@return 1 if it is a correct solution 0 if not
*/

int isCorrectSolutionBruteForce(int** board, int n, HELPER* helper){
	int countQueens = 0, i, j;
	resetHelperArrays(helper, n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(board[i][j]){ //if this cell has a queen
				if(helper->rows[i] || helper->cols[j] || helper->mainDiagonal[i - j + n - 1] || helper->secondaryDiagonal[i + j]){ //if any one of these is used then board is not valid
					return 0;
				}
				helper->rows[i] = 1; //marking the row
				helper->cols[j] = 1; //marking the column
				helper->mainDiagonal[i - j + n - 1] = 1; //marking the main diagonal (there is 2n-1 main diagonals in a board and cells 
				// in a main diagonal has same value for row - column and this value ranges between -(n-1) and n-1. thats why
				// we are adding n-1 to i-j)
				helper->secondaryDiagonal[i + j] = 1; //marking the secondary diagonal (there is also 2n-1 secondary diagonals in a board and cells
				//in a secondary diagonal has same value for row + column and this value ranges between 0 and 2n-1)
				countQueens++; //incrementing the seen queens
			}
		}
	}

	return (countQueens == n) ? 1 : 0;
}

/*
@brief checks whether the given board is valid or not by iterating the board once. doesnt check rows since optimized 1 only place one queen per row.

@param board: nxn board.
@param n: the size of the board.

@return 1 if it is a correct solution 0 if not
*/

int isCorrectSolutionOptimized1(int** board, int n, HELPER* helper){	
	int countQueens = 0, i, j;
	resetHelperArrays(helper, n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(board[i][j]){
				if(helper->cols[j] || helper->mainDiagonal[i - j + n - 1] || helper->secondaryDiagonal[i + j]){ 
					return 0;
				}
				helper->cols[j] = 1;
				helper->mainDiagonal[i - j + n - 1] = 1;
				helper->secondaryDiagonal[i + j] = 1;
				countQueens++; 
			}
		}
	}

	return (countQueens == n) ? 1 : 0;
}

/*
@brief checks whether the given board is valid or not by iterating the board once. doesnt check rows and columns since optimized 2
only place one queen per row and one queen per column.

@param board: nxn board.
@param n: the size of the board.

@return 1 if it is a correct solution 0 if not
*/

int isCorrectSolutionOptimized2(int** board, int n, HELPER* helper){	
	int countQueens = 0, i, j;
	resetHelperArrays(helper, n);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(board[i][j]){ //if this cell has a queen
				if(helper->mainDiagonal[i - j + n - 1] || helper->secondaryDiagonal[i + j]){
					return 0;
				}
				helper->mainDiagonal[i - j + n - 1] = 1;
				helper->secondaryDiagonal[i + j] = 1;
				countQueens++;
			}
		}
	}

	return (countQueens == n) ? 1 : 0;
}

/*
@brief calls bruteForce function for the given n and calculates the time spent and related information.

@param n: the size of the board.

@return
*/

void bruteForceMode(int n){
	int** board = createBoard(n);
	HELPER* helper = createHelperArrays(n);
	INFO info = {0, 0, 0};
	clock_t start, end;
	double timeSpent;
	
	printf("\n--------------------------------------------------\n");
	printf("Brute Force...");
	printf("\n--------------------------------------------------\n");
	start = clock();
	
	bruteForce(board, n, 0, 0, helper, &info);
	
	end = clock();
	timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
	
	printf("\n--------------------------------------------------\n");
	printf("Brute Force...\n");
	printf("the number of recursion calls: %lld\nthe number of moves: %lld\nthe number of solutions: %d\n", info.calls, info.moves, info.solutions);
	printf("Time spent: %.6f seconds", timeSpent);
	printf("\n--------------------------------------------------\n");
	
	freeBoard(board, n);
	freeHelperArrays(helper);
}

/*
@brief calls optimized1 function for the given n and calculates the time spent and related information.

@param n: the size of the board.

@return
*/

void optimized1Mode(int n){
	int** board = createBoard(n);
	HELPER* helper = createHelperArrays(n);
	INFO info = {0, 0, 0};
	clock_t start, end; 
	double timeSpent;
	
	printf("\n--------------------------------------------------\n");
	printf("Optimized 1...");
	printf("\n--------------------------------------------------\n");
	start = clock();
	
	optimized1(board, n, 0, helper, &info);
	
	end = clock();
	timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
	
	printf("\n--------------------------------------------------\n");
	printf("Optimized 1...\n");
	printf("the number of recursion calls: %lld\nthe number of moves: %lld\nthe number of solutions: %d\n", info.calls, info.moves, info.solutions);
	printf("Time spent: %.6f seconds", timeSpent);
	printf("\n--------------------------------------------------\n");
	
	freeBoard(board, n);
	freeHelperArrays(helper);
}

/*
@brief calls optimized2 function for the given n and calculates the time spent and related information.

@param n: the size of the board.

@return
*/

void optimized2Mode(int n){
	int** board = createBoard(n);
	HELPER* helper = createHelperArrays(n);
	int* cols = (int*) calloc(n, sizeof(int));
	INFO info = {0, 0, 0};
	clock_t start, end; 
	double timeSpent;
	
	printf("\n--------------------------------------------------\n");
	printf("Optimized 2...");
	printf("\n--------------------------------------------------\n");
	start = clock();
	
	optimized2(board, n, cols, 0, helper, &info);
	
	end = clock();
	timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
	
	printf("\n--------------------------------------------------\n");
	printf("Optimized 2...\n");
	printf("the number of recursion calls: %lld\nthe number of moves: %lld\nthe number of solutions: %d\n", info.calls, info.moves, info.solutions);
	printf("Time spent: %.6f seconds", timeSpent);
	printf("\n--------------------------------------------------\n");
	
	free(board);
	free(cols);
	freeHelperArrays(helper);
}

/*
@brief calls backtracking function for the given n and calculates the time spent and related information.

@param n: the size of the board.

@return
*/

void backtrackingMode(int n){
	int** board = createBoard(n);
	int* cols = (int*) calloc(n, sizeof(int));
	int* mainDiagonal = (int*) calloc(2 * n - 1, sizeof(int));
	int* secondaryDiagonal = (int*) calloc(2 * n - 1, sizeof(int));
	INFO info = {0, 0, 0};
	clock_t start, end; 
	double timeSpent;
	
	printf("\n--------------------------------------------------\n");
	printf("Backtracking...");
	printf("\n--------------------------------------------------\n");
	start = clock();
	
	backtracking(board, n, cols, mainDiagonal, secondaryDiagonal, 0, &info);
	
	end = clock();
	timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
	
	printf("\n--------------------------------------------------\n");
	printf("Backtracking...\n");
	printf("the number of recursion calls: %lld\nthe number of moves: %lld\nthe number of solutions: %d\n", info.calls, info.moves, info.solutions);
	printf("Time spent: %.6f seconds", timeSpent);
	printf("\n--------------------------------------------------\n");
	
	freeBoard(board, n);
	free(cols);
	free(mainDiagonal);
	free(secondaryDiagonal);
}

/*
@brief calls all modes for the given n 

@param n: the size of the board.

@return
*/

void allModes(int n){
	bruteForceMode(n);
	optimized1Mode(n);
	optimized2Mode(n);
	backtrackingMode(n);
}

/*
@brief creates the board filled with zeros and returns it.

@param n: the size of the board.

@return created board which is a 2D array
*/

int** createBoard(int n){
	int i;
	int** board = (int**) malloc(n * sizeof(int*));
	for(i=0;i<n;i++) board[i] = (int*) calloc(n, sizeof(int));
	return board;
}

/*
@brief creates helper struct to use it in isCorrectSolution functions.

@param n: the size of the board.

@return address of the created helper struct
*/

HELPER* createHelperArrays(int n){
	HELPER* helper = (HELPER*) malloc(sizeof(HELPER));
	helper->rows = (int*) calloc(n, sizeof(int));	
	helper->cols = (int*) calloc(n, sizeof(int)); 
	helper->mainDiagonal = (int*) calloc(2 * n - 1, sizeof(int)); 
	helper->secondaryDiagonal = (int*) calloc(2 * n - 1, sizeof(int)); 
	return helper;
}

void resetHelperArrays(HELPER* helper, int n){
	int i;
	
	for(i=0;i<n;i++){
		helper->rows[i] = 0;
		helper->cols[i] = 0;
	}
	
	for(i=0;i<2*n-1;i++){
		helper->mainDiagonal[i] = 0;
		helper->secondaryDiagonal[i] = 0;
	}
}

/*
@brief frees the given board.

@param board: the board.

@return
*/

void freeBoard(int** board, int n){
	int i;
	for(i=0;i<n;i++) free(board[i]);
	free(board);
}

/*
@brief frees the given helper struct.

@param helper: pointer to the helper struct.

@return
*/

void freeHelperArrays(HELPER* helper){
	free(helper->rows);
	free(helper->cols);
	free(helper->mainDiagonal);
	free(helper->secondaryDiagonal);
	free(helper);
}

/*
@brief draws the board in a good format.

@param board: nxn board.
@param n: the size of the board.

@return
*/

void drawBoard(int** board, int n){
    int i, j;
    
    printf("\n   ");
    for(i=0;i<n;i++){
    	printf("  %.2d  ", i);	
	}
	
    for(i=0;i<n;i++){
        printf("\n   ");
        
        for(j=0;j<n;j++){
        	printf("------");	
		}
		
        printf("\n%.2d |", i);

        for(j=0;j<n;j++){
            if(board[i][j]) printf("  Q  |");
            else printf("     |");
        }
    }
    
    printf("\n   ");
    
    for(i=0;i<n;i++){
    	printf("------");	
	}
	
    printf("\n\n");
}

/*
@brief clears console.

@param 

@return
*/

void clearConsole(){
		// Windows
		#ifdef _WIN32
        	system("cls");
	    // Unix/Linux/macOS
	    #else
	        system("clear");
	    #endif
}
