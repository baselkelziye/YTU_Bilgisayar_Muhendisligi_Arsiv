#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// BLM1031 2023-2024

typedef struct {
    char piece;
    int row;
    int col;
} Position;

void initializeBoard(int, char**);
void printBoard(int, char**, int*, int*);
void freeBoard(int, char**);
void playTurn(char**, int, int*, int*, int);
void endGameScore(int*, int*);
void saveGameToFile(int, char**, int*, int*);
void loadGameFromFile(int*, char***, int**, int**);
int isGameOver(int, char**);

int main() {
    int boardSize, i, turn;
    char **gameBoard;
    int *player1;
    int *player2;
    char newOrSaved;

    printf("SKIPPITY\nNew game: n    Saved game: s\n");
    scanf(" %c", &newOrSaved);

    if (newOrSaved == 's' || newOrSaved == 'S') {
        loadGameFromFile(&boardSize, &gameBoard, &player1, &player2);
    } else {
        printf("Enter board size (must be <=20 and even): ");
        scanf(" %d", &boardSize);
        while (boardSize <= 2 || boardSize > 20 || boardSize % 2 != 0) {
            printf("Invalid board size!\nEnter again (<=20 and even): ");
            scanf(" %d", &boardSize);
        }

        gameBoard = (char**)malloc(boardSize * sizeof(char*));
        for (i = 0; i < boardSize; i++) {
            gameBoard[i] = (char*)malloc(boardSize * sizeof(char));
        }

        player1 = (int*)calloc(5, sizeof(int));
        player2 = (int*)calloc(5, sizeof(int));

        initializeBoard(boardSize, gameBoard);
    }

    printBoard(boardSize, gameBoard, player1, player2);
    playTurn(gameBoard, 1, player1, player2, boardSize);

    freeBoard(boardSize, gameBoard);
    free(player1);
    free(player2);

    return 0;
}

void playTurn(char** gameBoard, int turn, int *player1, int *player2, int boardSize) {
    Position sourcePos;
    Position targetPos;
    char capturedPiece;
    char deletedPiece;
    char undoCommand = 'a';
    char redoCommand = 'a';
    int undoDirection;
    int isFinished = 0;

    while (isFinished == 0) {

        if (isGameOver(boardSize, gameBoard) == 1) {
            printf("No possible moves left.\nGAME OVER\n");
            endGameScore(player1, player2);
            isFinished = 1;
        }

        printf("\nPlayer %d's turn!", turn);

        if (undoCommand != 'd' && undoCommand != 'D' && 
            redoCommand != 'd' && redoCommand != 'D') {

            printf("\nEnter row and column of the piece to move: ");
            scanf(" %d %d", &sourcePos.row, &sourcePos.col);

            while (sourcePos.row < 0 || sourcePos.col < 0 ||
                   sourcePos.row >= boardSize || sourcePos.col >= boardSize) {
                printf("\nInvalid position!");
                printf("\nEnter row and column of the piece to move: ");
                scanf(" %d %d", &sourcePos.row, &sourcePos.col);
            }
            while (gameBoard[sourcePos.row][sourcePos.col] == '_') {
                printf("\nInvalid position. No piece here.");
                printf("\nEnter row and column of the piece to move: ");
                scanf(" %d %d", &sourcePos.row, &sourcePos.col);
            }

            sourcePos.piece = gameBoard[sourcePos.row][sourcePos.col];
        } 
        else {
            sourcePos.row = targetPos.row;
            sourcePos.col = targetPos.col;
        }

        undoCommand = 'a';
        redoCommand = 'a';
        undoDirection = 0;

        printf("\nEnter new row and column: ");
        scanf(" %d %d", &targetPos.row, &targetPos.col);

        while (targetPos.row < 0 || targetPos.col < 0 ||
               targetPos.row >= boardSize || targetPos.col >= boardSize) {
            printf("\nInvalid position!");
            printf("\nEnter new row and column: ");
            scanf(" %d %d", &targetPos.row, &targetPos.col);
        }

        while (gameBoard[targetPos.row][targetPos.col] != '_') {
            printf("\nInvalid position. Another piece is here.");
            printf("\nEnter new row and column: ");
            scanf(" %d %d", &targetPos.row, &targetPos.col);
        }

        while ( (targetPos.row == sourcePos.row+2 && targetPos.col == sourcePos.col+2) ||
                (targetPos.row == sourcePos.row+2 && targetPos.col == sourcePos.col-2) ||
                (targetPos.row == sourcePos.row-2 && targetPos.col == sourcePos.col+2) ||
                (targetPos.row == sourcePos.row-2 && targetPos.col == sourcePos.col-2) ) {

            printf("\nInvalid move. Diagonal jumping is not allowed.");
            printf("\nEnter new row and column: ");
            scanf(" %d %d", &targetPos.row, &targetPos.col);
        }

        // movement logic
        if (sourcePos.row == targetPos.row) {
            if (sourcePos.col == targetPos.col + 2) {
                capturedPiece = gameBoard[targetPos.row][targetPos.col + 1];
                gameBoard[targetPos.row][targetPos.col + 1] = '_';
                gameBoard[targetPos.row][targetPos.col] = sourcePos.piece;
                gameBoard[sourcePos.row][sourcePos.col] = '_';
                undoDirection = 1;
            }
            else if (sourcePos.col == targetPos.col - 2) {
                capturedPiece = gameBoard[targetPos.row][targetPos.col - 1];
                gameBoard[targetPos.row][targetPos.col - 1] = '_';
                gameBoard[targetPos.row][targetPos.col] = sourcePos.piece;
                gameBoard[sourcePos.row][sourcePos.col] = '_';
                undoDirection = 2;
            }
        }

        else if (sourcePos.col == targetPos.col) {
            if (sourcePos.row == targetPos.row + 2) {
                capturedPiece = gameBoard[targetPos.row + 1][targetPos.col];
                gameBoard[targetPos.row + 1][targetPos.col] = '_';
                gameBoard[targetPos.row][targetPos.col] = sourcePos.piece;
                gameBoard[sourcePos.row][sourcePos.col] = '_';
                undoDirection = 3;
            }
            else if (sourcePos.row == targetPos.row - 2) {
                capturedPiece = gameBoard[targetPos.row - 1][targetPos.col];
                gameBoard[targetPos.row - 1][targetPos.col] = '_';
                gameBoard[targetPos.row][targetPos.col] = sourcePos.piece;
                gameBoard[sourcePos.row][sourcePos.col] = '_';
                undoDirection = 4;
            }
        }

        deletedPiece = capturedPiece;
        capturedPiece -= 'A';

        if (turn == 1)
            player1[capturedPiece]++;
        else
            player2[capturedPiece]++;

        printBoard(boardSize, gameBoard, player1, player2);

        if (isGameOver(boardSize, gameBoard) == 1) {
            printf("No possible moves left.\nGAME OVER\n");
            endGameScore(player1, player2);
            isFinished = 1;
        }

        printf("\nundo: u  other player: p  continue: d  save & exit: c\t");
        scanf(" %c", &undoCommand);

        // Undo
        if (undoCommand == 'u' || undoCommand == 'U') {

            // reverse movement
            if (undoDirection == 1) {
                gameBoard[sourcePos.row][sourcePos.col] = gameBoard[sourcePos.row][targetPos.col];
                gameBoard[sourcePos.row][targetPos.col] = '_';
                gameBoard[sourcePos.row][targetPos.col + 1] = deletedPiece;
            }
            else if (undoDirection == 2) {
                gameBoard[sourcePos.row][sourcePos.col] = gameBoard[sourcePos.row][targetPos.col];
                gameBoard[sourcePos.row][targetPos.col] = '_';
                gameBoard[sourcePos.row][targetPos.col - 1] = deletedPiece;
            }
            else if (undoDirection == 3) {
                gameBoard[sourcePos.row][sourcePos.col] = gameBoard[targetPos.row][sourcePos.col];
                gameBoard[targetPos.row][sourcePos.col] = '_';
                gameBoard[targetPos.row + 1][targetPos.col] = deletedPiece;
            }
            else if (undoDirection == 4) {
                gameBoard[sourcePos.row][sourcePos.col] = gameBoard[targetPos.row][sourcePos.col];
                gameBoard[targetPos.row][sourcePos.col] = '_';
                gameBoard[targetPos.row - 1][targetPos.col] = deletedPiece;
            }

            if (turn == 1)
                player1[capturedPiece]--;
            else
                player2[capturedPiece]--;

            printBoard(boardSize, gameBoard, player1, player2);

            printf("\nredo: r  other player: p  continue: d  save & exit: c\t");
            scanf(" %c", &redoCommand);

            // redo
            if (redoCommand == 'r' || redoCommand == 'R') {

                if (sourcePos.row == targetPos.row) {
                    if (sourcePos.col == targetPos.col + 2) {
                        gameBoard[targetPos.row][targetPos.col + 1] = '_';
                        gameBoard[targetPos.row][targetPos.col] = gameBoard[sourcePos.row][sourcePos.col];
                        gameBoard[sourcePos.row][sourcePos.col] = '_';
                    }
                    else if (sourcePos.col == targetPos.col - 2) {
                        gameBoard[targetPos.row][targetPos.col - 1] = '_';
                        gameBoard[targetPos.row][targetPos.col] = gameBoard[sourcePos.row][sourcePos.col];
                        gameBoard[sourcePos.row][sourcePos.col] = '_';
                    }
                }
                else if (sourcePos.col == targetPos.col) {
                    if (sourcePos.row == targetPos.row + 2) {
                        gameBoard[targetPos.row + 1][targetPos.col] = '_';
                        gameBoard[targetPos.row][targetPos.col] = gameBoard[sourcePos.row][sourcePos.col];
                        gameBoard[sourcePos.row][sourcePos.col] = '_';
                    }
                    else if (sourcePos.row == targetPos.row - 2) {
                        gameBoard[targetPos.row - 1][targetPos.col] = '_';
                        gameBoard[targetPos.row][targetPos.col] = gameBoard[sourcePos.row][sourcePos.col];
                        gameBoard[sourcePos.row][sourcePos.col] = '_';
                    }
                }

                if (turn == 1)
                    player1[capturedPiece]++;
                else
                    player2[capturedPiece]++;

                printBoard(boardSize, gameBoard, player1, player2);
                printf("\nother player: p  continue: d  save & exit: c\t");
                scanf(" %c", &redoCommand);
            }

            else if (undoCommand == 'c' || undoCommand == 'C') {
                saveGameToFile(boardSize, gameBoard, player1, player2);
                printf("Game saved!\n");
                isFinished = 1;
            }
            else if (undoCommand == 'p' || undoCommand == 'P') {
                turn = (turn == 1 ? 2 : 1);
            }
        }

        // save & exit immediately
        else if (undoCommand == 'c' || undoCommand == 'C') {
            saveGameToFile(boardSize, gameBoard, player1, player2);
            printf("Game saved!\n");
            isFinished = 1;
        }

        // switch player
        else if (undoCommand == 'p' || undoCommand == 'P') {
            turn = (turn == 1 ? 2 : 1);
        }
    }
}

int isGameOver(int boardSize, char **gameBoard) {
    int i, j;

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardSize; j++) {
            if (gameBoard[i][j] != '_') {

                if (i - 2 >= 0 && gameBoard[i - 2][j] == '_' && gameBoard[i - 1][j] != '_')
                    return 0;
                if (i + 2 < boardSize && gameBoard[i + 2][j] == '_' && gameBoard[i + 1][j] != '_')
                    return 0;
                if (j - 2 >= 0 && gameBoard[i][j - 2] == '_' && gameBoard[i][j - 1] != '_')
                    return 0;
                if (j + 2 < boardSize && gameBoard[i][j + 2] == '_' && gameBoard[i][j + 1] != '_')
                    return 0;
            }
        }
    }
    return 1;
}

void saveGameToFile(int boardSize, char** gameBoard, int* player1, int* player2) {
    FILE *file = fopen("skippityGame.txt", "w");
    int i, j;

    fprintf(file, "%d\n", boardSize);

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardSize; j++) {
            fprintf(file, "%c ", gameBoard[i][j]);
        }
        fprintf(file, "\n");
    }

    for (i = 0; i < 5; i++)
        fprintf(file, "%d ", player1[i]);
    fprintf(file, "\n");

    for (i = 0; i < 5; i++)
        fprintf(file, "%d ", player2[i]);
    fprintf(file, "\n");

    fclose(file);
}

void loadGameFromFile(int *boardSize, char ***gameBoard, int **player1, int **player2) {
    FILE *file = fopen("skippityGame.txt", "r");
    int i, j;

    fscanf(file, "%d\n", boardSize);

    *gameBoard = (char**)malloc(*boardSize * sizeof(char*));
    for (i = 0; i < *boardSize; i++) {
        (*gameBoard)[i] = (char*)malloc(*boardSize * sizeof(char));
    }

    *player1 = (int*)calloc(5, sizeof(int));
    *player2 = (int*)calloc(5, sizeof(int));

    for (i = 0; i < *boardSize; i++) {
        for (j = 0; j < *boardSize; j++) {
            fscanf(file, " %c", &((*gameBoard)[i][j]));
        }
    }

    for (i = 0; i < 5; i++)
        fscanf(file, "%d", &((*player1)[i]));

    for (i = 0; i < 5; i++)
        fscanf(file, "%d", &((*player2)[i]));

    fclose(file);
}

void endGameScore(int *player1, int *player2) {
    int score1 = player1[0];
    int score2 = player2[0];
    int i;

    for (i = 0; i < 5; i++) {
        if (player1[i] < score1)
            score1 = player1[i];
        if (player2[i] < score2)
            score2 = player2[i];
    }

    printf("\nPlayer1 score: %d", score1);
    printf("\nPlayer2 score: %d", score2);
}

void initializeBoard(int size, char** gameBoard) {
    int i, j, random;
    srand(time(NULL));

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            random = rand() % 5;
            gameBoard[i][j] = 'A' + random;
        }
    }

    gameBoard[size/2 - 1][size/2] = '_';
    gameBoard[size/2 - 1][size/2 - 1] = '_';
    gameBoard[size/2][size/2] = '_';
    gameBoard[size/2][size/2 - 1] = '_';
}

void printBoard(int size, char** gameBoard, int *player1, int *player2) {
    int i, j;
    printf("\n   ");
    for (i = 0; i < size; i++) {
        printf(" %d ", i);
    }
    printf("\n");

    for (i = 0; i < size; i++) {
        printf(" %d ", i);
        for (j = 0; j < size; j++) {
            printf(" %c ", gameBoard[i][j]);
        }
        printf("\n");
    }

    printf("\nPlayer1\nA B C D E\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", player1[i]);
    }

    printf("\nPlayer2\nA B C D E\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", player2[i]);
    }
}

void freeBoard(int size, char** gameBoard) {
    int i;
    for (i = 0; i < size; i++) {
        free(gameBoard[i]);
    }
    free(gameBoard);
}

