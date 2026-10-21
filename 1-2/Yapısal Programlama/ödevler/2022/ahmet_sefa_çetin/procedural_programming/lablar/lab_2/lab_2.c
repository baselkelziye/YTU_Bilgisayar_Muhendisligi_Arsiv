#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printArray(char **matrix, int wordCount, int maxCharacter) {
    int i, j;
    for (i = 0; i < wordCount; i++) {
        for (j = 0; j < maxCharacter; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int getElements(char **matrix, int wordCount) {
    int maxCharacter = 0, i;

    for (i = 0; i < wordCount; i++) {
        printf("Enter %d. word: ", i + 1);
        scanf("%s", matrix[i]);
        if (strlen(matrix[i]) > maxCharacter) {
            maxCharacter = strlen(matrix[i]);
        }
    }

    return maxCharacter;
}

int main() {
    int wordCount, i, j, maxCharacter = 0;
    char **matrix, **newMatrix;

    printf("Enter the number of words: ");
    scanf("%d", &wordCount);

    matrix = (char **)malloc(wordCount * sizeof(char *));
    if (matrix == NULL) {
        printf("Memory allocation failed");
        return -1;
    }
    for (i = 0; i < wordCount; i++) {
        matrix[i] = (char *)malloc(50 * sizeof(char));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed");
            return -1;
        }
    }

    maxCharacter = getElements(matrix, wordCount);

    newMatrix = (char **)malloc(wordCount * sizeof(char *));
    if (newMatrix == NULL) {
        printf("Memory allocation failed");
        return -1;
    }

    for (i = 0; i < wordCount; i++) {
        newMatrix[i] = (char *)realloc(matrix[i], maxCharacter * sizeof(char));
        if (newMatrix[i] == NULL) {
            printf("Memory allocation failed");
            return -1;
        }
    }

    for (i = 0; i < wordCount; i++) {
        for (j = strlen(newMatrix[i]); j < maxCharacter; j++) {
            newMatrix[i][j] = '*';
        }
    }

    printArray(newMatrix, wordCount, maxCharacter);

    // Freeing the memory
    for (i = 0; i < wordCount; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(newMatrix);

    return 0;
}

