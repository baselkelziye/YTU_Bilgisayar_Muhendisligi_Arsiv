//
//  main.c
//  20011047algohw4
//
//  Created by Sena ALAY on 15.12.2023.
//

// 20011047 Sena Alay
/*
@brief
    This program calculates and prints the Longest Common Subsequences (LCS) between two text strings. 
    It uses Dynamic Programming (DP) to calculate the LCS length and backtracking to find all LCSs. 
    Program takes input text strings from the user, displays DP matrices, and finds all LCSs.
    At the end of the program, it displays the length of LCS and all LCSs found.
    This program includes these functions which are explained in detail in their own sections:
        - A function to print a matrix
        - A recursive function to find and print all LCS
        - A function to calculate LCS length and fill DP and choice matrices
        - A function to get user's choicae for displaying matrices
        - A main function to find and print all LCS 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

//Function prototypes, they are explained in detail in their own sections
void printMatrix(int matrix[MAX][MAX], int len1, int len2);
void findAllLCS(int dp[MAX][MAX], int choiceMatrix[MAX][MAX], char* X, char* Y, int m, int n, char* lcs, int index);
int lcs(char *X, char *Y, int m, int n, int dp[MAX][MAX], int choiceMatrix[MAX][MAX], int showMatrix);
char getChoice(const char *prompt);
void printAllLCS(char *X, char *Y);

/*
    @brief This function prints a matrix.
    @param matrix[MAX][MAX] -> the matrix to be printed
    @param len1 -> the number of rows in the matrix
    @param len2 -> the number of columns in the matrix
    @return
*/
void printMatrix(int matrix[MAX][MAX], int len1, int len2) {
    int i,j;
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/*
    @brief This recursive function finds and prints all Longest Common Subsequences (LCS).
    @param dp[MAX][MAX] -> the DP matrix for LCS calculation
    @param choiceMatrix[MAX][MAX] -> the choice matrix for backtracking LCS
    @param X -> the first input string
    @param Y -> the second input string
    @param m -> the length of the first string
    @param n -> the length of the second string
    @param lcs -> a character array to store the LCS
    @param index -> the current index in the LCS string
    @return
*/
void findAllLCS(int dp[MAX][MAX], int choiceMatrix[MAX][MAX], char* X, char* Y, int m, int n, char* lcs, int index) {
    int i, j;
    if (index == -1) {
        printf("%s\n", lcs); // Print the LCS found
        return;
    }

    // Loop to find all paths for LCS
    for (i = m; i > 0; i--) {
        for (j = n; j > 0; j--) {
            // Check if current cell is part of any LCS
            if (dp[i][j] == index + 1 && X[i - 1] == Y[j - 1]) {
                // Recur for the cell (i-1, j-1) in the matrix
                if (choiceMatrix[i][j] == 1) {
                    lcs[index] = X[i - 1];
                    findAllLCS(dp, choiceMatrix, X, Y, i - 1, j - 1, lcs, index - 1);
                }
            }
        }
    }
}

 /*
    @brief This function calculates the length of Longest Common Subsequence (LCS) and fills DP and choice matrices.
    @param X -> the first input string
    @param Y -> the second input string
    @param m -> the length of the first string
    @param n -> the length of the second string
    @param dp[MAX][MAX] -> the DP matrix for LCS calculation
    @param choiceMatrix[MAX][MAX] -> the choice matrix for backtracking LCS
    @param showMatrix -> a flag to determine if matrices should be displayed
    @return the length of LCS
*/
int lcs(char *X, char *Y, int m, int n, int dp[MAX][MAX], int choiceMatrix[MAX][MAX], int showMatrix) {
    int i,j;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0; // Initializing first row and column to 0
                choiceMatrix[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Characters match
                choiceMatrix[i][j] = 1; // Choice is diagonal
            } else {
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]; // Max of left and top cell
                choiceMatrix[i][j] = dp[i - 1][j] > dp[i][j - 1] ? 2 : 3; // Choice is left or top
            }
        }
        // Option to display matrices after each row
        if (showMatrix) {
            printf("DP Matrix after row %d:\n", i);
            printMatrix(dp, m, n);
            printf("Choice Matrix after row %d:\n", i);
            printMatrix(choiceMatrix, m, n);
        }
    }
    return dp[m][n]; // Length of LCS
}

/*
    @brief This function gets the user's choice for displaying matrices.
    @param prompt -> the prompt message to be displayed to the user
    @return the user's choice (Y or N)
*/
char getChoice(const char *prompt) {
    char input;
    printf("%s", prompt);
    while (scanf(" %c", &input) != 1 || (input != 'Y' && input != 'y' && input != 'N' && input != 'n')) {
        while (getchar() != '\n'); // Flush extra input
        printf("Invalid choice. Please enter Y or N.\n");
        printf("%s", prompt);
    }
    return input;
}

/*
    @brief This function finds and prints all Longest Common Subsequences (LCS) in sorted order.
    @param X -> the first input string
    @param Y -> the second input string
    @return
*/
void printAllLCS(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[MAX][MAX] = {{0}};
    int choiceMatrix[MAX][MAX] = {{0}};

    char showMatrixChoice = getChoice("Do you want to see the matrices row by row after the implementation? (Y/N): ");

    int showMatrix = showMatrixChoice == 'Y' || showMatrixChoice == 'y';

    int lcsLength = lcs(X, Y, m, n, dp, choiceMatrix, showMatrix);

    char showFinalMatrixChoice = getChoice("Would you like to see the matrix created with the dynamic programming approach in detail? (Y/N): ");
    if (showFinalMatrixChoice == 'Y' || showFinalMatrixChoice == 'y') {
        printf("Final DP Matrix:\n");
        printMatrix(dp, m, n);
        printf("Final Choice Matrix:\n");
        printMatrix(choiceMatrix, m, n);
    }
     
    printf("\n************************************************************************\n");

    printf("\nLCS length of the given strings is: %d\n", lcsLength);
    printf("\n****************** All LCS ******************\n");

    char* lcs = (char*)malloc((lcsLength + 1) * sizeof(char));
    lcs[lcsLength] = '\0'; // Null-terminate the string

    printf("\nLCS of %s and %s is/are below here:\n", X, Y);

    findAllLCS(dp, choiceMatrix, X, Y, m, n, lcs, lcsLength - 1);

    free(lcs); // Free allocated memory
}

/*
    @brief The main function where the program starts execution.
    @return returns an integer that indicates the exit status of the program, to say the program ended successfully or not
*/
int main() {
    char X[MAX], Y[MAX];
    char choice;

    do {
        printf("Enter String 1: ");
        scanf("%99s", X);
        printf("Enter String 2: ");
        scanf("%99s", Y);

        printAllLCS(X, Y);

        choice = getChoice("Do you want to enter another pair of strings? (Y/N): ");
    } while (choice == 'Y' || choice == 'y');

    printf("Thank you for using the program! Have a nice day :) \n");
    printf("Exiting...\n");

    return 0;
}

//SENA ALAY 20011047