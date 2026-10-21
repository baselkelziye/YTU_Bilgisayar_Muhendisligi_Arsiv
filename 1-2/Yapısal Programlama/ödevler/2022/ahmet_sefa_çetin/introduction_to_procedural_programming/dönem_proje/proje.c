#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 60

void readFromFile(int matrix[][MAX], char *fileName);
void drawBoard(int matrix[][MAX], int N);

void zeroMatrix(int matrix[][MAX], int N);
void randomMatrix(int matrix[][MAX], int N, int startingLocations[][4]);
void startingLocationsFunction(int matrix[][MAX], int N, int startingLocations[][4]);
void showUserScores(int scores[][MAX], int gameCounter[], int avarageScores[], int M);
void manualFunction(int matrix[][MAX], int N, int steps[][4], int stepCounter);
void undoFunction(int matrix[][MAX], int N, int steps[][4], int stepCounter);
int successCheckFunction(int matrix[][MAX], int N, int startingLocations[][4]);
void manualMode(int matrix[][MAX], int N, int currentPlayer, int *numberOfUndos);
void matrixCopy(int matrix1[][MAX], int matrix2[][MAX], int N);
void automaticMode(int board[][MAX], int startingLocations[][4], int N, int currentLabel, int row, int column, int *counter, int *isAutoCompleted, int resultMatrix[][MAX]);

int main() {
    int board[MAX][MAX], choice, startingLocations[MAX][4], N, M, scores[MAX][MAX], gameCounter[MAX] = {0}, currentPlayer, numberOfUndos;
    int randomOrFileScore, manualOrAutoScore, successCheck, avarageScores[MAX] = {0}, currentLabel, counter, isAutoCompleted, resultMatrix[MAX][MAX];
    char fileName[20];

    printf("number of players: ");
    scanf("%d", &M);

    do {
        srand(time(NULL));

        printf("\nGenerate a Random Matrix: 1\n");
        printf("Generate a Matrix from File: 2\n");
        printf("Show Users Scores: 3\n");
        printf("Exit: 4\n");
        printf("choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            showUserScores(scores, gameCounter, avarageScores, M);
        }

        if (choice == 1 || choice == 2) {
            printf("dimension of board: ");
            scanf("%d", &N);

            zeroMatrix(board, N);
            zeroMatrix(resultMatrix, N);

            if (choice == 1) {
                randomMatrix(board, N, startingLocations);
                randomOrFileScore = N * 4;
            }

            else if (choice == 2) {
                printf("Enter the file name: ");
                scanf("%s", fileName);
                readFromFile(board, fileName);
                startingLocationsFunction(board, N, startingLocations);
                randomOrFileScore = N * 2;
            }

            printf("enter current player number (1 to %d): ", M);
            scanf("%d", &currentPlayer);

            drawBoard(board, N);

            printf("\nPlay in manual mode: 1\n");
            printf("Play in automatic mode: 2\n");
            printf("Return to main menu: 3\n");
            printf("choice: ");
            scanf("%d", &choice);

            numberOfUndos = 0;

            if (choice == 1) {
                manualMode(board, N, currentPlayer, &numberOfUndos);
                drawBoard(board, N);
                manualOrAutoScore = N * 4;
            }

            else if (choice == 2) {
                currentLabel = 1;
                isAutoCompleted = 0;
                counter = 0;
                automaticMode(board, startingLocations, N, currentLabel, startingLocations[0][0], startingLocations[0][1], &counter, &isAutoCompleted, resultMatrix);
                matrixCopy(resultMatrix, board, N);
                drawBoard(board, N);
                manualOrAutoScore = N * 2;
                numberOfUndos = 1;
            }

            successCheck = 0;
            if (choice == 1 || choice == 2) {
                successCheck = successCheckFunction(board, N, startingLocations);

                if (successCheck) {
                    printf("\nCongratulations! The game was successfully completed.\n");
                    scores[currentPlayer][gameCounter[currentPlayer]] = randomOrFileScore + manualOrAutoScore - 2 * numberOfUndos;
                } else {
                    if (choice == 1) printf("\nThe game was not successfully completed.\n");
                    if (choice == 2) printf("\nThere are no available solutions.\n");
                    scores[currentPlayer][gameCounter[currentPlayer]] = 0;
                }

                gameCounter[currentPlayer]++;
            }
        }

    } while (choice != 4);

    return 0;
}

void readFromFile(int matrix[][MAX], char *fileName) {
    int i, j, temp;
    FILE *data = fopen(fileName, "r");
    if (!data) {
        printf("Dosya Acilamadi!");
        return;
    }
    while (!feof(data)) {
        fscanf(data, "%d %d %d\n", &i, &j, &temp);
        matrix[i][j] = temp;
    }
    fclose(data);
}

void drawBoard(int matrix[][MAX], int N) {
    int i, j, k;
    printf("\n   ");
    for (k = 0; k < N; k++)
        printf("  %d    ", k);
    for (i = 0; i < N; i++) {
        printf("\n   ");
        for (k = 0; k < N; k++)
            printf("-------");
        printf("\n%d |", i);

        for (j = 0; j < N; j++) {
            if (matrix[i][j] != 0)
                printf("  %d   |", matrix[i][j]);
            else
                printf("      |", matrix[i][j]);
        }
    }
    printf("\n   ");
    for (k = 0; k < N; k++)
        printf("-------");
}

void zeroMatrix(int matrix[][MAX], int N) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matrix[i][j] = 0;
        }
    }
}

void randomMatrix(int matrix[][MAX], int N, int startingLocations[][4]) {
    int i, j, x, y;

    for (i = 0; i < N; i++) {
        j = 0;
        while (j < 2) {
            x = rand() % N;
            y = rand() % N;
            if (matrix[x][y] == 0) {
                matrix[x][y] = i + 1;
                startingLocations[i][2 * j] = x;
                startingLocations[i][2 * j + 1] = y;
                j++;
            }
        }
    }
}

void startingLocationsFunction(int matrix[][MAX], int N, int startingLocations[][4]) {
    int i, j, used[MAX] = {0};

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (matrix[i][j] != 0) {
                if (used[matrix[i][j]] != 0) {
                    startingLocations[matrix[i][j] - 1][0] = i;
                    startingLocations[matrix[i][j] - 1][1] = j;
                } else {
                    startingLocations[matrix[i][j] - 1][2] = i;
                    startingLocations[matrix[i][j] - 1][3] = j;
                }
                used[matrix[i][j]]++;
            }
        }
    }
}

void showUserScores(int scores[][MAX], int gameCounter[], int avarageScores[], int M) {
    int i, j;

    for (i = 1; i <= M; i++) {
        if (scores[i][0]) {
            avarageScores[i] = 0;
            for (j = 0; j < gameCounter[i]; j++) {
                avarageScores[i] += scores[i][j];
            }
            avarageScores[i] /= gameCounter[i];
        }
        printf("Score of player %d: %d\n", i, avarageScores[i]);
    }
}

void manualFunction(int matrix[][MAX], int N, int steps[][4], int stepCounter) {
    int i, j, sourceX, sourceY, destinationX, destinationY, t;

    printf("enter indexes of source point: ");
    scanf("%d %d", &sourceX, &sourceY);

    printf("enter indexes of destination point: ");
    scanf("%d %d", &destinationX, &destinationY);

    if (sourceY == destinationY) {
        t = 1;
        if (destinationX < sourceX) t = -1;

        i = sourceX + t;
        while (t * i <= t * destinationX && matrix[i][sourceY] == 0 && i < N && i >= 0) {
            matrix[i][sourceY] = matrix[sourceX][sourceY];
            i += t;
        }

        steps[stepCounter][0] = i - t;
        steps[stepCounter][1] = sourceY;
        steps[stepCounter][2] = sourceX;
        steps[stepCounter][3] = sourceY;
    } else if (sourceX == destinationX) {
        t = 1;
        if (destinationY < sourceY) t = -1;

        i = sourceY + t;
        while (t * i <= t * destinationY && matrix[sourceX][i] == 0 && i < N && i >= 0) {
            matrix[sourceX][i] = matrix[sourceX][sourceY];
            i += t;
        }

        steps[stepCounter][0] = sourceX;
        steps[stepCounter][1] = i - t;
        steps[stepCounter][2] = sourceX;
        steps[stepCounter][3] = sourceY;
    }
}

void undoFunction(int matrix[][MAX], int N, int steps[][4], int stepCounter) {
    int i, j, sourceX, sourceY, destinationX, destinationY, t;

    sourceX = steps[stepCounter][0];
    sourceY = steps[stepCounter][1];
    destinationX = steps[stepCounter][2];
    destinationY = steps[stepCounter][3];

    if (sourceY == destinationY) {
        t = 1;
        if (destinationX < sourceX) t = -1;

        i = sourceX;
        while (t * i < t * destinationX && i < N && i >= 0) {
            matrix[i][sourceY] = 0;
            i += t;
        }
    } else if (sourceX == destinationX) {
        t = 1;
        if (destinationY < sourceY) t = -1;

        i = sourceY;
        while (t * i < t * destinationY && i < N && i >= 0) {
            matrix[sourceX][i] = 0;
            i += t;
        }
    }
}

int successCheckFunction(int matrix[][MAX], int N, int startingLocations[][4]) {
    int i, j, k, counter, control, zeroMatrix[MAX][MAX] = {{0}};

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (matrix[i][j] == zeroMatrix[i][j])
                return 0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            control = 0;
            k = 0;
            while (k < N && !control) {
                if ((i == startingLocations[k][0] && j == startingLocations[k][1]) || (i == startingLocations[k][2] && j == startingLocations[k][3])) control = 1;
                k++;
            }

            counter = 0;
            if (control) {
                if (matrix[i + 1][j] == matrix[i][j]) counter++;
                if (matrix[i][j + 1] == matrix[i][j]) counter++;
                if (matrix[i - 1][j] == matrix[i][j]) counter++;
                if (matrix[i][j - 1] == matrix[i][j]) counter++;

                if (counter < 1) return 0;
            } else {
                if (matrix[i + 1][j] == matrix[i][j]) counter++;
                if (matrix[i][j + 1] == matrix[i][j]) counter++;
                if (matrix[i - 1][j] == matrix[i][j]) counter++;
                if (matrix[i][j - 1] == matrix[i][j]) counter++;

                if (counter < 2) return 0;
            }
        }
    }

    return 1;
}

void manualMode(int matrix[][MAX], int N, int currentPlayer, int *numberOfUndos) {
    int steps[MAX][4], stepCounter, choice;

    choice = 1;
    stepCounter = 0;
    while (choice != 3) {
        if (choice == 1) {
            manualFunction(matrix, N, steps, stepCounter);
            stepCounter++;
        }

        else if (choice == 2) {
            if (stepCounter != 0) stepCounter--;
            undoFunction(matrix, N, steps, stepCounter);
            (*numberOfUndos)++;
        }

        drawBoard(matrix, N);

        printf("\n");
        printf("continue: 1\n");
        printf("undo: 2\n");
        printf("end the game: 3\n");
        printf("choice: ");
        scanf("%d", &choice);
    }
}

void matrixCopy(int matrix1[][MAX], int matrix2[][MAX], int N) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matrix2[i][j] = matrix1[i][j];
        }
    }
}

void automaticMode(int board[][MAX], int startingLocations[][4], int N, int currentLabel, int row, int column, int *counter, int *isAutoCompleted, int resultMatrix[][MAX]) {
    int i, j, direction, dx[] = {+1, 0, -1, 0}, dy[] = {0, +1, 0, -1};
    int matrix[MAX][MAX];

    if (*isAutoCompleted == 0) {
        // If you'd like to see results sooner, you can remove this block as it takes time to draw boards.
        drawBoard(board, N);
        printf("\n");
        //***********************************************************************************************
    } else return;

    matrixCopy(board, matrix, N);

    if (row < 0 || row >= N) return;
    if (column < 0 || column >= N) return;

    if (row == startingLocations[currentLabel - 1][2] && column == startingLocations[currentLabel - 1][3]) {
        if (currentLabel < N) {
            currentLabel++;
            *counter = 0;
            automaticMode(matrix, startingLocations, N, currentLabel, startingLocations[currentLabel - 1][0], startingLocations[currentLabel - 1][1], counter, isAutoCompleted, resultMatrix);
        } else if (currentLabel == N && successCheckFunction(matrix, N, startingLocations)) {
            matrixCopy(matrix, resultMatrix, N);
            *isAutoCompleted = 1;
            return;
        }
    }

    if (*counter != 0 && matrix[row][column]) return;

    (*counter)++;
    matrix[row][column] = currentLabel;

    for (direction = 0; direction < 4; ++direction)
        automaticMode(matrix, startingLocations, N, currentLabel, row + dx[direction], column + dy[direction], counter, isAutoCompleted, resultMatrix);
}
