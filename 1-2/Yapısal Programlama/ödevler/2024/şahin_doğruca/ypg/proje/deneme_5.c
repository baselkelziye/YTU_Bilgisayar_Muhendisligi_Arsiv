#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "players.dat"
#define MAX_NAME_LENGTH 50
#define MAX_SCORES 10

// Struct to represent player information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int scores[MAX_SCORES];
    int scoreCount;
} Player;

// Function prototypes
void printPlayers();
void addScore(const char *name, int score);

int main() {
    char playerName[MAX_NAME_LENGTH];
    int newScore;

    // Print existing players and scores
    printf("Existing Players and Scores:\n");
    printPlayers();

    // Get user input
    printf("\nEnter player name: ");
    scanf("%s", playerName);

    printf("Enter score to add: ");
    scanf("%d", &newScore);

    // Add the score to the file
    addScore(playerName, newScore);

    // Print the updated players and scores
    printf("\nUpdated Players and Scores:\n");
    printPlayers();

    return 0;
}

// Function to print all players and scores from the binary file
void printPlayers() {
    FILE *file = fopen(FILENAME, "rb");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Player player;

    // Print all players and scores
    while (fread(&player, sizeof(Player), 1, file) == 1) {
        printf("%s (%d scores):", player.name, player.scoreCount);
        for (int i = 0; i < player.scoreCount; i++) {
            printf(" %d", player.scores[i]);
        }
        printf("\n");
    }

    fclose(file);
}

// Function to add a score for a given player in the binary file
void addScore(const char *name, int score) {
    FILE *file = fopen(FILENAME, "rb+");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Player player;
    int found = 0;

    // Search for the player in the file
    while (fread(&player, sizeof(Player), 1, file) == 1) {
        if (strcmp(player.name, name) == 0) {
            // Player found, update the scores
            if (player.scoreCount < MAX_SCORES) {
                player.scores[player.scoreCount++] = score;
                fseek(file, -sizeof(Player), SEEK_CUR);
                fwrite(&player, sizeof(Player), 1, file);
            } else {
                printf("Player's score array is full. Cannot add a new score.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        // Player not found, append a new entry
        fseek(file, 0, SEEK_END);
        strcpy(player.name, name);
        player.scores[0] = score;
        player.scoreCount = 1;
        fwrite(&player, sizeof(Player), 1, file);
    }

    fclose(file);
}
