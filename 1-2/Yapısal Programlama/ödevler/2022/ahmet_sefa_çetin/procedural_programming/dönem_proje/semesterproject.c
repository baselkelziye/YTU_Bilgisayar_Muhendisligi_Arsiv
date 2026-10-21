#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX 100

typedef struct player {
    int id;
    char name[20];
    char surname[20];
    char username[20];
    char password[20];
} PLAYER;

void readBoardFromFile(int **matrix);
void drawBoard(int **matrix, int N, int M);
void zeroMatrix(int **matrix, int N, int M);
int **getBoard(int **board, int *N, int *M);
int signin(PLAYER *players, int playerCounter, char passwords[][20]);
int signup(PLAYER *players, int *playerCounter, char passwords[][20]);
void readPlayersFromFile(PLAYER *players, int *playerCounter, char passwords[][20]);
void savePlayersToFile(PLAYER *players);
void findStartingLocation(int **board, int N, int M, int *userLocationX, int *userLocationY);
void manualMod(int **board, int N, int M, int currentPlayerId, double maxFiveScores[], int maxFiveIds[]);
double calculateScore(int particlesCounter[], double gameTime);
void updateMaxScores(int currentPlayerId, double score, double maxFiveScores[], int maxFiveIds[]);
void listMaxScores(double maxFiveScores[], int maxFiveIds[], PLAYER *players);
void readMaxFiveScoresFromFile(int maxFiveIds[], double maxFiveScores[]);
void saveMaxFiveScoresToFile(int maxFiveIds[], double maxFiveScores[]);
void automaticMode(int **board, int N, int M, int currentPlayerId, double maxFiveScores[], int maxFiveIds[]);
void freeBoard(int **board, int N);

int main() {
    int i, **board, N, M, choice, playerCounter = 0, currentPlayerId, maxFiveIds[5]= {0};
    double maxFiveScores[5] = {0};
    PLAYER *players;
    players = (PLAYER*)malloc(MAX * sizeof(PLAYER));
    for (i = 0; i < MAX; i++) {
        players[i].id = -1;
    }
    char passwords[MAX][20];
	readPlayersFromFile(players, &playerCounter, passwords);
	printf("users: %d\n", playerCounter);
	readMaxFiveScoresFromFile(maxFiveIds, maxFiveScores);
	
	srand(time(NULL));
	
	do {
		listMaxScores(maxFiveScores, maxFiveIds, players);

	    printf("\nSign in: 1\n");
	    printf("Sign up: 2\n");
	    printf("Exit: 3\n");
	    printf("Choice: ");
	    scanf("%d", &choice);

		if (choice == 1)
	        currentPlayerId = signin(players, playerCounter, passwords);
		else if (choice == 2)
		    currentPlayerId = signup(players, &playerCounter, passwords);

	    while (choice == 1 || choice == 2) {
		    printf("Play in manual mode: 1\n");
		    printf("Play in automatic mode: 2\n");
		    printf("Sign out: 0\n");
		    printf("choice: ");
			scanf("%d", &choice);
		    if (choice == 1 || choice == 2) {
				board = getBoard(board, &N, &M);
			    drawBoard(board, N, M);
			    
			    if (choice == 1) 
			    	manualMod(board, N, M, currentPlayerId, maxFiveScores, maxFiveIds);
				
				else if (choice == 2)
					automaticMode(board, N, M, currentPlayerId, maxFiveScores, maxFiveIds);
			}
	    	freeBoard(board, N);
		}
		
		
	} while (choice != 3);
	
	printf("You exitted the game.");
    
	free(players);

    return 0;
}

// reading matrix values from a txt file and saving them to matrix
void readBoardFromFile(int **matrix) {
    int i, j, temp;
	char fileName[20];
    FILE *data;
    do {
    	printf("Enter the file name: ");
    	scanf("%s", fileName);
    	
    	data = fopen(fileName, "r");
		if (!data) {
			printf("File could not be opened!, ");
		}
	} while (!data);
    
    while (!feof(data)) {
        fscanf(data, "%d %d %d\n", &i, &j, &temp);
        matrix[i][j] = temp;
    }
    fclose(data);
}

// drawing the game board
void drawBoard(int **matrix, int N, int M) {
    int i, j, k;
    printf("\n   ");
    for (k = 0; k < M; k++)
        printf("  %d    ", k);
    for (i = 0; i < N; i++) {
        printf("\n   ");
        for (k = 0; k < M; k++)
            printf("-------");
        printf("\n%d |", i);

        for (j = 0; j < M; j++) {
            if (matrix[i][j] == 0)
                printf("      |");
            else if (matrix[i][j] == 1)
                printf("  1   |");
            else if (matrix[i][j] == 2)
                printf("  P   |");
            else if (matrix[i][j] == 3)
                printf("  e   |");
            else if (matrix[i][j] == 4)
                printf("  p   |");
            else if (matrix[i][j] == 5)
                printf("  E   |");
            else if (matrix[i][j] == 6)
                printf("  K   |");
            else if (matrix[i][j] == 7)
                printf("  G   |");
            else if (matrix[i][j] == 8)
                printf("  C   |");
            else if (matrix[i][j] == 9)
                printf("  X   |");
        }
    }
    printf("\n   ");
    for (k = 0; k < M; k++)
        printf("-------");
}

// initialize all elements of matrix to zero
void zeroMatrix(int **matrix, int N, int M) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            matrix[i][j] = 0;
        }
    }
}

// getting row, column numbers and file name that allows us to fill matrix from user
int **getBoard(int **board, int *N, int *M) {
    int i;

    printf("number of board rows: ");
    scanf("%d", N);

    printf("number of board columns: ");
    scanf("%d", M);

    board = (int **)malloc(*N * sizeof(int *));
    for (i = 0; i < *N; i++) {
        board[i] = (int *)malloc(*M * sizeof(int));
    }

    zeroMatrix(board, *N, *M);

    readBoardFromFile(board);

    return board;
}

// returns id of player who signed in
int signin(PLAYER *players, int playerCounter, char passwords[][20]) {
    char username[20], password[20];
    int i, isPlayerFound, currentPlayerId;

    printf("username: ");
    scanf("%s", username);

    isPlayerFound = 0;
    i = 0;
    while (i < playerCounter && isPlayerFound == 0) {
        if (strcmp(username, players[i].username) == 0) {
                isPlayerFound = 1;
                currentPlayerId = i;
        }
        i++;
    }

    while (isPlayerFound == 0) {
        printf("invalid username, enter username again: ");
        scanf("%s", username);
        i = 0;
        while (i < playerCounter && isPlayerFound == 0) {
            if (strcmp(username, players[i].username) == 0) {
                isPlayerFound = 1;
                currentPlayerId = i;
            }
            i++;
        }
    }

    printf("password: ");
    scanf("%s", password);

    if (strcmp(password, passwords[currentPlayerId]) == 0) {
        printf("\nWelcome %s.\n\n", username);
        return currentPlayerId;
    }

    while (strcmp(password, passwords[currentPlayerId]) != 0) {
        printf("wrong password, enter password again: ");
        scanf("%s", password);
    }
    printf("\nWelcome %s.\n\n", username);
    return currentPlayerId;
}

// returns id of player who signed up
int signup(PLAYER *players, int *playerCounter, char passwords[][20]) {
    int i, isUniq, currentPlayerId;

    printf("name: ");
    scanf("%s", players[*playerCounter].name);

    printf("surname: ");
    scanf("%s", players[*playerCounter].surname);

    printf("username: ");
    scanf("%s", players[*playerCounter].username);

    isUniq = 1;
    i = 0;
    while (i < *playerCounter && isUniq == 1) {
        if (strcmp(players[*playerCounter].username, players[i].username) == 0)
            isUniq = 0;
        i++;
    }

    while (isUniq == 0) {
        printf("username is taken, enter a different username: ");
        scanf("%s", players[*playerCounter].username);
        i = 0;
        isUniq = 1;
        while (i < *playerCounter && isUniq == 1) {
            if (strcmp(players[*playerCounter].username, players[i].username) == 0)
                isUniq = 0;
            i++;
        }
    }

    printf("password: ");
    scanf("%s", players[*playerCounter].password);

    printf("\nSuccessfully signed up.\n\n");

    strcpy(passwords[*playerCounter], players[*playerCounter].password);

    players[*playerCounter].id = *playerCounter;
    currentPlayerId = *playerCounter;

    (*playerCounter)++;

    savePlayersToFile(players);

    return currentPlayerId;
}

// reads players from players.bin file
void readPlayersFromFile(PLAYER *players, int *playerCounter, char passwords[][20]) {
    FILE *playersFile = fopen("players.bin", "rb");
    if (!playersFile) {
        printf("File could not be opened!");
        return;
    }
    fread(players, sizeof(PLAYER), MAX, playersFile);

    while (players[*playerCounter].id != -1) {
        strcpy(passwords[*playerCounter], players[*playerCounter].password);
        (*playerCounter)++;
    }
    fclose(playersFile);
}

// saves players to players.bin file
void savePlayersToFile(PLAYER *players) {
    FILE *playersFile = fopen("players.bin", "wb");
    if (!playersFile) {
        printf("File could not be opened!");
        return;
    }
    fwrite(players, sizeof(PLAYER), MAX, playersFile);
    fclose(playersFile);
}

// finds the row and column number of starting location G
void findStartingLocation(int **board, int N, int M, int *userLocationX, int *userLocationY) {
	int i, j, isFound = 0;
	
	i = 0;
	while (i < N && isFound == 0) {
		j = 0;
		while (j < M && isFound == 0) {
			if (board[i][j] == 7) {
				*userLocationX = i;
				*userLocationY = j;
				isFound = 1;
			}
			j++;
		}
		i++;
	}
}

//  function that enables playing in manual mod
void manualMod(int **board, int N, int M, int currentPlayerId, double maxFiveScores[], int maxFiveIds[]) {	
	int i, j, userLocationX, userLocationY, particlesCounter[4] = {0}, isBlackHole = 0, isFinish = 0;
	char direction;
	clock_t gameStartTime, gameFinishTime, currentTime;
	double gameTime, score = 0, elapsedTime;
	
	findStartingLocation(board, N, M, &userLocationX, &userLocationY);
	
	printf("\n\n%d %d\n\n", userLocationX, userLocationY);
	
	board[userLocationX][userLocationY] = 9;
	
	system("cls");
	drawBoard(board, N, M);
	
	printf("\nP+: %d\n", particlesCounter[0]);
	printf("e-: %d\n", particlesCounter[1]);
	printf("P-: %d\n", particlesCounter[2]);
	printf("e+: %d\n", particlesCounter[3]);
	
	gameStartTime = clock();
	do {	
		direction = getch();
		
		if (direction != 27) {
			direction = getch();
		
			if (direction == 72 &&userLocationX - 1 >= 0 && board[userLocationX - 1][userLocationY] != 1) {
				board[userLocationX][userLocationY] = 0;
				userLocationX--;
			}
	
			else if (direction == 75 && userLocationY - 1 >= 0 && board[userLocationX][userLocationY - 1] != 1) {
				board[userLocationX][userLocationY] = 0;
				userLocationY--;
			}
				
			else if (direction == 77 && userLocationY + 1 < M && board[userLocationX][userLocationY + 1] != 1) {
				board[userLocationX][userLocationY] = 0;
				userLocationY++;
			}
			
			else if (direction == 80 && userLocationX + 1 < N && board[userLocationX + 1][userLocationY] != 1) {
				board[userLocationX][userLocationY] = 0;
				userLocationX++;
			}
	
			if (board[userLocationX][userLocationY] == 2)
				particlesCounter[0]++;
			
			else if (board[userLocationX][userLocationY] == 3)
				particlesCounter[1]++;
			
			else if (board[userLocationX][userLocationY] == 4)
				particlesCounter[2]++;
			
			else if (board[userLocationX][userLocationY] == 5)
				particlesCounter[3]++;
			
			else if (board[userLocationX][userLocationY] == 6)
				isBlackHole = 1;
			
			else if (board[userLocationX][userLocationY] == 8)
				isFinish = 1;
			
			board[userLocationX][userLocationY] = 9;	
			
			system("cls");
			
			drawBoard(board, N, M);
			
			printf("\nP+: %d\n", particlesCounter[0]);
			printf("e-: %d\n", particlesCounter[1]);
			printf("P-: %d\n", particlesCounter[2]);
			printf("e+: %d\n", particlesCounter[3]);
			
			currentTime	= clock();
			
			elapsedTime	= (double)(currentTime - gameStartTime) / CLOCKS_PER_SEC;
					
		}
		
	} while(direction != 27 && isBlackHole == 0 && isFinish == 0 && elapsedTime < 120.0);
	
	gameFinishTime = clock();
	
	gameTime = (double)(gameFinishTime - gameStartTime) / CLOCKS_PER_SEC;
	
	if (isFinish == 1) {
		printf("Arrived at finish location. The game is over.\n");
		score = calculateScore(particlesCounter, gameTime);
		printf("Score: %2.2lf\n\n", score);
		updateMaxScores(currentPlayerId, score, maxFiveScores, maxFiveIds);
		saveMaxFiveScoresToFile(maxFiveIds, maxFiveScores);
	}
	
	else if (isBlackHole == 1) {
		printf("Encountered with black hole. The game is over.\n");
		printf("Score: %2.2lf\n\n", score);
	}
	
	else if (direction == 27) {
		printf("You entered ESC. Game finished.\n");
		printf("Score: %2.2lf\n\n", score);
	}
	
	else if (elapsedTime >= 120.0) {
		printf("Time is up. The game is over.\n");
		printf("Score: %2.2lf\n\n", score);
	}
	
}

// returns the calculated score
double calculateScore(int particlesCounter[], double gameTime) {
	if (particlesCounter[0] > particlesCounter[2]) {
		particlesCounter[0] -= particlesCounter[2];
		particlesCounter[2] = 0;
	} else {
		particlesCounter[2] -= particlesCounter[0];
		particlesCounter[0] = 0;
	}
	
	if (particlesCounter[1] > particlesCounter[3]) {
		particlesCounter[1] -= particlesCounter[3];
		particlesCounter[3] = 0;
	} else {
		particlesCounter[3] -= particlesCounter[1];
		particlesCounter[1] = 0;
	}
	
	if (particlesCounter[0] != 0 || particlesCounter[1] != 0)
		return 0;
	
	if (particlesCounter[2] > particlesCounter[3]) 
		return (double)particlesCounter[3] * 100.0 / gameTime;
	else
		return (double)particlesCounter[2] * 100.0 / gameTime;
	
}

// inserts a score to list of maxFiveScores 
void updateMaxScores(int currentPlayerId, double score, double maxFiveScores[], int maxFiveIds[]) {
    int i, indexToInsert = 0;

	while (indexToInsert < 5 && score <= maxFiveScores[indexToInsert]) {
	    indexToInsert++;
	}
	
	for (i = 4; i > indexToInsert; i--) {
	    maxFiveIds[i] = maxFiveIds[i - 1];
	    maxFiveScores[i] = maxFiveScores[i - 1];
	}
	
	maxFiveIds[indexToInsert] = currentPlayerId;
	maxFiveScores[indexToInsert] = score;
}

// lists max five scores
void listMaxScores(double maxFiveScores[], int maxFiveIds[], PLAYER *players) {
	int i = 0;
	
	printf("\n******MAX SCORES******\n");
	if (players[0].id == -1) {
		for (i = 0; i < 5; i++) {
			printf("%d. -   %2.2lf\n", i+1, maxFiveScores[i]);
		}
	} else {
		for (i = 0; i < 5; i++) {
			printf("%d. %s   %2.2lf\n", i+1, players[maxFiveIds[i]].username, maxFiveScores[i]);
		}
	}

}

// reads max five scores from txt file
void readMaxFiveScoresFromFile(int maxFiveIds[], double maxFiveScores[]) {
    int i;
	FILE *maxScoresFile = fopen("maxFiveScores.txt", "r");
    
    i = 0;
    while (!feof(maxScoresFile)) {
        fscanf(maxScoresFile, "%d %lf\n", &maxFiveIds[i], &maxFiveScores[i]);
        i++;
    }
    fclose(maxScoresFile);
}

// saves max five scores to txt file
void saveMaxFiveScoresToFile(int maxFiveIds[], double maxFiveScores[]) {
	int i;
	FILE *maxScoresFile = fopen("maxFiveScores.txt", "w");
    
    for (i = 0; i < 5; i++) {
        fprintf(maxScoresFile, "%d %lf\n", maxFiveIds[i], maxFiveScores[i]);
    }
    fclose(maxScoresFile);
}

// automatic mod codes
void automaticMode(int **board, int N, int M, int currentPlayerId, double maxFiveScores[], int maxFiveIds[]) {
	int i, j, userLocationX, userLocationY, particlesCounter[4] = {0}, isBlackHole = 0, isFinish = 0, randomDirection;
	clock_t gameStartTime, gameFinishTime, currentTime;
	double gameTime, score = 0, elapsedTime;
	
	findStartingLocation(board, N, M, &userLocationX, &userLocationY);
	
	printf("\n\n%d %d\n\n", userLocationX, userLocationY);
	
	board[userLocationX][userLocationY] = 9;
	
	system("cls");
	drawBoard(board, N, M);
	
	printf("\nP+: %d\n", particlesCounter[0]);
	printf("e-: %d\n", particlesCounter[1]);
	printf("P-: %d\n", particlesCounter[2]);
	printf("e+: %d\n", particlesCounter[3]);
	
	gameStartTime = clock();
	do {	
		randomDirection = rand() % 4;
		
		if (randomDirection == 0 &&userLocationX - 1 >= 0 && board[userLocationX - 1][userLocationY] != 1) {
			board[userLocationX][userLocationY] = 0;
			userLocationX--;
		}
	
		else if (randomDirection == 1 && userLocationY - 1 >= 0 && board[userLocationX][userLocationY - 1] != 1) {
			board[userLocationX][userLocationY] = 0;
			userLocationY--;
		}
				
		else if (randomDirection == 2 && userLocationY + 1 < M && board[userLocationX][userLocationY + 1] != 1) {
			board[userLocationX][userLocationY] = 0;
			userLocationY++;
		}
			
		else if (randomDirection == 3 && userLocationX + 1 < N && board[userLocationX + 1][userLocationY] != 1) {
			board[userLocationX][userLocationY] = 0;
			userLocationX++;
		}
			
		if (board[userLocationX][userLocationY] == 2)
			particlesCounter[0]++;
			
		else if (board[userLocationX][userLocationY] == 3)
			particlesCounter[1]++;
			
		else if (board[userLocationX][userLocationY] == 4)
			particlesCounter[2]++;

		else if (board[userLocationX][userLocationY] == 5)
			particlesCounter[3]++;
			
		else if (board[userLocationX][userLocationY] == 6)
			isBlackHole = 1;
			
		else if (board[userLocationX][userLocationY] == 8)
			isFinish = 1;
			
		board[userLocationX][userLocationY] = 9;
			
		system("cls");	
			
		drawBoard(board, N, M);
			
		printf("\nP+: %d\n", particlesCounter[0]);
		printf("e-: %d\n", particlesCounter[1]);
		printf("P-: %d\n", particlesCounter[2]);
		printf("e+: %d\n", particlesCounter[3]);
			
		usleep(150000);
		
		currentTime	= clock();
		
		elapsedTime	= (double)(currentTime - gameStartTime) / CLOCKS_PER_SEC;
		
	} while(isBlackHole == 0 && isFinish == 0 && elapsedTime < 15.0);
	
	gameFinishTime = clock();
	
	gameTime = (double)(gameFinishTime - gameStartTime) / CLOCKS_PER_SEC;
	
	if (isFinish == 1) {
		printf("Arrived at finish location. The game is over.\n");
		score = calculateScore(particlesCounter, gameTime);
		printf("Score: %2.2lf\n\n", score);
		updateMaxScores(currentPlayerId, score, maxFiveScores, maxFiveIds);
		saveMaxFiveScoresToFile(maxFiveIds, maxFiveScores);
	}
	
	else if (isBlackHole == 1) {
		printf("Encountered with black hole. The game is over.\n");
		printf("Score: %2.2lf\n\n", score);
	}
	
	else if (elapsedTime >= 15.0) {
		printf("Time is up. The game is over.\n");
		printf("Score: %2.2lf\n\n", score);
	}
	
}

// frees memory of board
void freeBoard(int **board, int N) {
	int i = 0;
	
	for (i = 0; i < N; i++) {
		free(board[i]);
	}
	free(board);
}
