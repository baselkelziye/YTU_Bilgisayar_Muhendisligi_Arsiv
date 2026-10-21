#include <stdio.h>
#include <conio.h> // For getch
#include <unistd.h> // For sleep
#include <string.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX

#define MAX_STEPS 1000

typedef struct {
    char name[50];
    char surname[50];
    char nickname[50];
    char password[50];
} Player;

int is_valid_move(int newRow, int newCol,int rows,int cols,char **maze);
int recursive_pathfinder(int newRow, int newCol, int steps, char **maze, int rows, int cols, int *path, int *bestPath, int *min_steps);
void writeScoreboard(Player *loggedInPlayer, int points);
void displayScoreboard();
void savePlayerDataBinary(const Player *p);
int isNicknameUniqueBinary(const char *nickname);
void registerPlayer();
int loginPlayer(Player *loggedInPlayer);
char** loadMapFromTxt(const char *filename, int *rows, int *cols);
void displayMaze(char **maze, int rows, int cols);
void freeMaze(char **maze, int rows);
void movePlayer(char **maze, int *playerRow, int *playerCol, int rows, int cols, char *collectedItems);
int calculatePoints(const char *collectedItems);
int playGame(char **maze, int rows, int cols);
void startNewGame(Player *loggedInPlayer);
void autoPlayGame(char **maze, int rows, int cols, int *bestPath, int steps);

int main() {
    int choice;
    int loggedIn = 0; 
    int flag =1;
    Player currentPlayer; 

    while (flag == 1) {
        if (!loggedIn) {
            printf("Welcome to the Game!\n");
            printf("1. Register\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                registerPlayer();  
            } else if (choice == 2) {
                loggedIn = loginPlayer(&currentPlayer);  
            } else if (choice == 3) {
                printf("Exiting the game. Goodbye!\n");
                flag = 0;
            } else {
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
            }
        } else {
            printf("Play Menu:\n");
            printf("1. Start New Game\n");
            printf("2. View High Scores\n");
            printf("3. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1) {
                startNewGame(&currentPlayer);
            } else if (choice == 2) {
                displayScoreboard();
                printf("High Scores:\n");
            } else if (choice == 3) {
                loggedIn = 0; 
                printf("Logged out successfully.\n");
            } else {
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
            }
        }
    }

    return 0;
}


void writeScoreboard(Player *loggedInPlayer, int points) {
    const int maxSize = 5;
    char nicknames[maxSize][50];
    int scores[maxSize];
    int j, k;
    char tempNickname[50];

    // Open the file in read mode to read existing scores
    FILE *file = fopen("scoreboard.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    // Read existing scores from the file
    int i = 0;
   while (fscanf(file, "Nickname: %49[^,], Score: %d\n", nicknames[i], &scores[i]) == 2) {
    i++;
}

    fclose(file);

    // Add the new score
    strcpy(nicknames[i], loggedInPlayer->nickname);
    scores[i] = points;

    // Sort the scores in descending order
    for (j = 0; j < 5; j++) {
        for (k = j + 1; k < 6; k++) {
            if (scores[j] < scores[k]) {
                // Swap scores
                int tempScore = scores[j];
                scores[j] = scores[k];
                scores[k] = tempScore;

                // Swap nicknames
                 char *tempNickname = malloc(sizeof(strlen(nicknames[j]) + 1));
                strcpy(tempNickname, nicknames[j]);
                strcpy(nicknames[j], nicknames[k]);
                strcpy(nicknames[k], tempNickname);
            }
        }
    }

    // Open the file in write mode to update the scoreboard
    file = fopen("scoreboard.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    // Write the top 5 scores to the file
    for (j = 0; j < maxSize; j++) {
        fprintf(file, "Nickname: %s, Score: %d\n", nicknames[j], scores[j]);
    }

    fclose(file);
}
void displayScoreboard() {
    FILE *file = fopen("scoreboard.txt", "r"); // Open the file in read mode
    if (file == NULL) {
        printf("Error opening file or no scoreboard entries yet.\n");
        return;
    }

    printf("Scoreboard:\n");

    // Read and display each line in the file
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}
void savePlayerDataBinary(const Player *p) {
    FILE *file = fopen("players.dat", "ab"); // Open the file in binary append mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fwrite(p, sizeof(Player), 1, file);

    fclose(file);
}

int isNicknameUniqueBinary(const char *nickname) {
    FILE *file = fopen("players.dat", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return -1; // Return -1 to indicate file error
    }

    Player p;

    while (fread(&p, sizeof(Player), 1, file) == 1) {
        if (strcmp(p.nickname, nickname) == 0) {
            fclose(file);
            return 0; // Nickname is not unique
        }
    }

    fclose(file);
    return 1; // Nickname is unique
}

void registerPlayer() {
    Player newPlayer;

    printf("Enter name: ");
    scanf("%s", newPlayer.name);

    printf("Enter surname: ");
    scanf("%s", newPlayer.surname);

    do {
        printf("Enter nickname: ");
        scanf("%s", newPlayer.nickname);

        if (!isNicknameUniqueBinary(newPlayer.nickname)) {
            printf("This nickname is already taken. Please choose another one.\n");
        }
    } while (!isNicknameUniqueBinary(newPlayer.nickname));

    printf("Enter password: ");
    scanf("%s", newPlayer.password);

    // Save the newPlayer to a binary file
    savePlayerDataBinary(&newPlayer);
}

int loginPlayer(Player *loggedInPlayer) {
    char enteredNickname[50];
    char enteredPassword[50];
    int loginSuccess = 0;  // Flag to indicate success

    printf("Enter nickname: ");
    scanf("%s", enteredNickname);

    printf("Enter password: ");
    scanf("%s", enteredPassword);

    FILE *file = fopen("players.dat", "rb");  // Open the file in binary read mode
    if (file == NULL) {
        printf("Error opening file or no registered users yet.\n");
        return 0;  // Return 0 to indicate failure
    }

    Player p;
    while (fread(&p, sizeof(Player), 1, file) == 1) {
        if (strcmp(p.nickname, enteredNickname) == 0 && strcmp(p.password, enteredPassword) == 0) {
            *loggedInPlayer = p;  // Copy the logged-in player's information
            printf("Login successful! Welcome %s %s.\n", p.name, p.surname);
            loginSuccess = 1;  // Set flag to 1 if login is successful
        }
    }

    fclose(file);

    if (!loginSuccess) {
        printf("Login failed. Incorrect nickname or password.\n");
    }

    return loginSuccess;  // Return the login success status
}

char** loadMapFromTxt(const char *filename, int *rows, int *cols) {
    int i, j;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Determine the number of rows and columns in the maze
    *rows = 0;
    *cols = 0;
    int maxCols = 0;  // To track the maximum number of columns in any row
    char c;

    while (fscanf(file, "%c", &c) == 1) {
        if (c == '\n') {
            (*rows)++;
            *cols = maxCols > *cols ? maxCols : *cols;  // Set the number of columns based on the maximum in any row
            maxCols = 0;      // Reset for the next row
        } else if (c != ' ') {
            maxCols++;
        }
    }

    // Reset the file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the maze dynamically
    char **maze = (char **)malloc((*rows) * sizeof(char *));
    for (i = 0; i < *rows; i++) {
        maze[i] = (char *)malloc((*cols) * sizeof(char));
    }

    // Read the maze from the file
    for (i = 0; i < *rows; i++) {
        for (j = 0; j < *cols; j++) {
            fscanf(file, " %c", &maze[i][j]);
        }
    }

    fclose(file);

    return maze;
}

void displayMaze(char **maze, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void freeMaze(char **maze, int rows) {
    int i;
    for (i = 0; i < rows; i++) {
        free(maze[i]);
    }
    free(maze);
}

void movePlayer(char **maze, int *playerRow, int *playerCol, int rows, int cols, char *collectedItems) {
    int i;
    int success,firstMove = 0;  // Initialize success to 0
    char move;

    for (i = 20; i > 0; i--) {  // Change loop condition to i > 0
        printf("Iteration: %d\n", 20 - i);  // Display the remaining iterations

        move = getch();

        if (move == 27) {
            printf("Game over. You exited the game.\n");
            i = 0;
        } else {
            move = getch();
            int newRow = *playerRow;
            int newCol = *playerCol;

 if (move == 72 && newRow > 0) { // Up
    printf("Up arrow key pressed\n");
    newRow--;
} else if (move == 80 && newRow < rows - 1) { // Down
    printf("Down arrow key pressed\n");
    newRow++;
} else if (move == 77 && newCol < cols - 1) { // Right
    printf("Right arrow key pressed\n");
    newCol++;
} else if (move == 75 && newCol > 0) { // Left
    printf("Left arrow key pressed\n");
    newCol--;
} else {
    printf("You can't move outside the matrix!\n");
}
            sleep(1);
            system("cls");

            // Check if it's the first move

            if (maze[newRow][newCol] != '1') {
            	   if (firstMove == 0) {
                maze[*playerRow][*playerCol] = 'G';
                firstMove=1;
            } else {
                maze[*playerRow][*playerCol] = '0';
            }
                *playerRow = newRow;
                *playerCol = newCol;

                char currentCell = maze[*playerRow][*playerCol];
                if (currentCell == 'E') {
                    printf("Collected e+ 'E'\n");
                    strcat(collectedItems, "E ");
                } else if (currentCell == 'e') {
                    printf("Collected e- 'e'\n");
                    strcat(collectedItems, "e ");
                } else if (currentCell == 'P') {
                    printf("Collected P+ 'P'\n");
                    strcat(collectedItems, "P ");
                } else if (currentCell == 'p') {
                    printf("Collected p- 'p'\n");
                    strcat(collectedItems, "p ");
                } else if (currentCell == 'K') {
                    printf("Karedelige ulastin oyun bitiyor!\n");
                    i = 0;  
                } else if (currentCell == 'C') {
                    printf("Tebrikler cikisa ulastin oyun bitiyor!\n");
                    i = 0; 
                    success = 1;
                }

                maze[*playerRow][*playerCol] = 'X';
            } else if (maze[newRow][newCol] == '1') {
                printf("Duvara carptin!\n");
                maze[*playerRow][*playerCol] = 'X';
                
            }
            printf("Toplanan atom alti parcaciklar: %s\n", collectedItems);
            displayMaze(maze, rows, cols);
        }
    }

    if (success == 1) {
        // Success logic goes here
    } else {
        strcpy(collectedItems, "0");
        printf("Out of moves!\n");
    }
}


int calculatePoints(const char *collectedItems) {
	int antimatterCount;
	int itemCounts[4];
	const char *ptr;
    itemCounts[0] = 0; // 'e'
    itemCounts[1] = 0; // 'E'
    itemCounts[2] = 0; // 'p'
    itemCounts[3] = 0; // 'P'

    for (ptr = collectedItems; *ptr; ptr++) {
        if (*ptr == 'e') {
            itemCounts[0]++;
        } else if (*ptr == 'E') {
            itemCounts[1]++;
        } else if (*ptr == 'p') {
            itemCounts[2]++;
        } else if (*ptr == 'P') {
            itemCounts[3]++;
        }
    }
    
    if (itemCounts[0] >= itemCounts[1]) {
        itemCounts[0] = itemCounts[0] - itemCounts[1];
        itemCounts[1] = 0;
    } else {
        itemCounts[1] = itemCounts[1] - itemCounts[0];
        itemCounts[0] = 0;
    }

    if (itemCounts[2] >= itemCounts[3]) {
        itemCounts[2] = itemCounts[2] - itemCounts[3];
        itemCounts[3] = 0;
    } else {
        itemCounts[3] = itemCounts[3] - itemCounts[2];
        itemCounts[2] = 0;
    }
    
   if (itemCounts[0] == 0 && itemCounts[3] == 0) {
    if (itemCounts[1] < itemCounts[2]) {
        antimatterCount = itemCounts[1];
        itemCounts[1] = 0;
        itemCounts[2] -= antimatterCount;
    } else {
        antimatterCount = itemCounts[2];
        itemCounts[2] = 0;
        itemCounts[1] -= antimatterCount;
    }
}
    int points = antimatterCount * 100;
    points -= (itemCounts[0] + itemCounts[1]+itemCounts[2]+itemCounts[3]) * 10;

    printf("Number of antimatter: %d\n", antimatterCount);
    printf("Total Points: %d\n", points);
    return points;
}
    

int playGame(char **maze, int rows, int cols) {
    int playerRow = -1, playerCol = -1;
    int path[MAX_STEPS], bestPath[MAX_STEPS];
    int min_steps = INT_MAX;
    int point;
    int i, j;
    char collectedItems[100] = "";  
    int result;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (maze[i][j] == 'X') {
                playerRow = i;
                playerCol = j;
                printf("Player is on %d %d.\n", playerRow, playerCol);
            }
        }
    }
    
     displayMaze(maze, rows, cols);
     
     int choice = 0;
    while(choice==0){
    	printf("Choose mode (1 for manual, 2 for automatic): ");
    int modeChoice;
    scanf("%d", &modeChoice);
    	if (modeChoice == 1) {
        movePlayer(maze, &playerRow, &playerCol, rows, cols, collectedItems);
        choice = 1;
    } else if (modeChoice == 2) {
    	result =  recursive_pathfinder(playerRow, playerCol, 0, maze, rows, cols, path, bestPath, &min_steps);
    	if (min_steps < INT_MAX) {
    		autoPlayGame(maze, rows, cols, bestPath, min_steps);
    } else {
        printf("No path found!\n");
    }
        choice = 1;
    } else {
        printf("Invalid mode choice. Try again...\n");
    }

	}
    int itemCounts[4]; 
    point=calculatePoints(collectedItems);
    return point;
}

void startNewGame(Player *loggedInPlayer) {
    int mapChoice;
    int choice;
    char txtFilename[100];
    int point;
    int flag=1;


    while (flag==1) {
    printf("Choose an option:\n");
    printf("1. Play with an already loaded map\n");
    printf("2. Load map from a text file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
        if(choice == 1){
        	 printf("Choose which map you want to play (1-5):\n");
            scanf("%d", &mapChoice);
            if (mapChoice >= 1 && mapChoice <= 5) {
                // playLoadedMap(mapChoice);
                printf("Playing loaded map %d...\n", mapChoice);
                 flag = 0;
            } else {
                printf("Invalid map choice. Please enter a number between 1 and 5 or load map from txt.\n");
            }
            
		}
        else if(choice == 2){
        	printf("Enter the name of the text file containing the map (including .txt extension):\n");
            scanf("%99s", txtFilename);
            printf("Loading map from %s...\n", txtFilename);
            char **maze;
            int rows, cols;

            maze = loadMapFromTxt(txtFilename, &rows, &cols);
            point = playGame(maze, rows, cols);
            writeScoreboard(loggedInPlayer,point);
            freeMaze(maze, rows); 
            flag = 0;
		}
            
        else{
        printf("Invalid choice. Please enter 1 or 2.\n");
		}
    }
}

int is_valid_move(int newRow, int newCol, int rows, int cols, char **maze) {
    return newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && 
           maze[newRow][newCol] != '1'&& maze[newRow][newCol] != 'K';;
}

int recursive_pathfinder(int newRow, int newCol, int steps, char **maze, int rows, int cols, int *path, int *bestPath, int *min_steps) {
	int i;
    if (!is_valid_move(newRow, newCol, rows, cols, maze)) {
        return INT_MAX;
    }

    path[steps] = newRow * cols + newCol;

    char current_cell = maze[newRow][newCol];
    if (current_cell == 'C') {
        if (steps < *min_steps) {
            *min_steps = steps;
            for ( i = 0; i <= steps; i++) {
                bestPath[i] = path[i];
            }
        }
        return steps;
    }

    maze[newRow][newCol] = '1';

    int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (i = 0; i < 4; ++i) {
        int next_newRow = newRow + moves[i][0];
        int next_newCol = newCol + moves[i][1];
        recursive_pathfinder(next_newRow, next_newCol, steps + 1, maze, rows, cols, path, bestPath, min_steps);
    }

    maze[newRow][newCol] = current_cell;
    return *min_steps;
}

void autoPlayGame(char **maze, int rows, int cols, int *bestPath, int steps) {
    int i;
    char collectedItems[100] = ""; // to keep track of collected items

    for (i = 0; i <= steps; ++i) {
        int playerRow = bestPath[i] / cols;
        int playerCol = bestPath[i] % cols;

        // Simulate player movement
        char currentCell = maze[playerRow][playerCol];
         system("cls");
        // Collect items or perform actions based on what's in the current cell
        if (currentCell == 'E') {
                    printf("Collected e+ 'E'\n");
                    strcat(collectedItems, "E ");
                } else if (currentCell == 'e') {
                    printf("Collected e- 'e'\n");
                    strcat(collectedItems, "e ");
                } else if (currentCell == 'P') {
                    printf("Collected P+ 'P'\n");
                    strcat(collectedItems, "P ");
                } else if (currentCell == 'p') {
                    printf("Collected p- 'p'\n");
                    strcat(collectedItems, "p ");
                } else if (currentCell == 'K') {
                    printf("Karedelige ulastin oyun bitiyor!\n");
                } else if (currentCell == 'C') {
                    printf("Tebrikler cikisa ulastin oyun bitiyor!\n");
                }

        maze[playerRow][playerCol] = 'X';  // Mark the new player position
         printf("Toplanan atom alti parcaciklar: %s\n", collectedItems);
        displayMaze(maze, rows, cols);  // Display the updated maze
        sleep(1);  // Wait a bit before the next move for visibility
    }

    int points = calculatePoints(collectedItems);  // Calculate points based on collected items
    printf("Game over! Points collected: %d\n", points);
}
