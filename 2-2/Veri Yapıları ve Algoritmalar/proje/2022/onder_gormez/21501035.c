
/* ************** Stack.h ***************/
/* #pragma once */

#include <stdbool.h>

#define MAX_ELEMENT_COUNT 1000

typedef struct Stack {
    int item[MAX_ELEMENT_COUNT];
    int top;
} Stack_t;

bool isStackEmpty(Stack_t* stack);

bool isStackFull(Stack_t* stack);

/* Returns true: success */
/* Returns false: failure */
bool pushToStack(Stack_t* stack, int value);

/* Returns true: success */
/* Returns false: failure */
bool popFromStack(Stack_t* stack, int* pValue);

/* Returns true: success */
/* Returns false: failure */
bool peekValueFromStack(Stack_t* stack, int* pValue);

void printValuesInStack(Stack_t* stack);

/* ************** Stack.c ***************/
/* #include "Stack.h" */

#include <stdio.h>

bool isStackEmpty(Stack_t* stack)
{
    if (stack == NULL) {
        printf("In function isStackEmpty(): Stack pointer null!");
        return false;
    }

    return stack->top == 0;
}

bool isStackFull(Stack_t* stack)
{
    if (stack == NULL) {
        printf("In function isStackFull(): Stack pointer null!");
        return false;
    }

    return stack->top == MAX_ELEMENT_COUNT;
}

bool pushToStack(Stack_t* stack, int value)
{
    if (stack == NULL) {
        printf("In function pushToStack(): Unable to push data to stack. Stack pointer null!");
        return false;
    }

    if (isStackFull(stack)) {
        printf("In function pushToStack(): Unable to push data to stack. Stack full!");
        return false;
    }

    stack->item[stack->top++] = value;

    return true;
}

bool popFromStack(Stack_t* stack, int* pValue)
{
    if (stack == NULL) {
        printf("In function popFromStack(): Unable to pop data from the stack. Stack pointer null!");
        return false;
    }

    if (pValue == NULL) {
        printf("In function popFromStack(): Unable to pop data from the stack. Value pointer null!");
        return false;
    }

    if (isStackEmpty(stack)) {
        printf("In function popFromStack(): Unable to pop data from the stack. Stack empty!");
        return false;
    }

    *pValue = stack->item[--stack->top];

    return true;
}

bool peekValueFromStack(Stack_t* stack, int* pValue)
{
    if (stack == NULL) {
        printf("In function peekValueFromStack(): Unable to peek data from the stack. Stack pointer null!");
        return false;
    }

    if (pValue == NULL) {
        printf("In function peekValueFromStack(): Unable to peek data from the stack. Value pointer null!");
        return false;
    }

    if (isStackEmpty(stack)) {
        printf("In function peekValueFromStack(): Unable to peek data from the stack. Stack empty!");
        return false;
    }

    *pValue = stack->item[stack->top - 1];

    return true;
}

void printValuesInStack(Stack_t* stack)
{
    int index = 0;

    if (stack == NULL) {
        printf("In function printValuesInStack(): Unable to print values in the stack. Stack pointer null!");
        return;
    }

    if (isStackEmpty(stack)) {
        printf("In function printValuesInStack(): Unable to print values in the stack.  Stack empty!");
        return;
    }

    printf("Values in stack: \n");
    for (index = 0; index < stack->top; ++index)
        printf("%d. index: %d\n", index, stack->item[index]);
}

/* ************** main.c ***************/
/* #include "Stack.h" */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define CORNER_CHARACTER '+'
#define PATH '1'
#define WALL '0'
#define WALL_CHARACTER_1 '-'
#define WALL_CHARACTER_2 '|'
#define START_CHARACTER 'b'
#define FINISH_CHARACTER 'c'
#define SPACE_CHARACTER ' '
#define APPLE_CHARACTER 'o'
#define SNAKE_CHARACTER '*'

/* Küçük */
/* #define FILE_NAME "maze5.txt" */

/* Büyük */
#define FILE_NAME "maze4.txt"
/* #define FILE_NAME "maze2.txt" */

/* Çıkmaz */
/* #define FILE_NAME "maze6.txt" */

#define PENALTY_POINTS 5
#define REWARD_POINTS 10
#define MICRO_SECONDS 25000

/* Node Index + North Index + South Index + West Index + East Index + Is Visited */
#define ADJACENCY_MATRIX_COLUMN_COUNT 6
#define NODE_INDEX 0
#define NORTH_INDEX 1
#define SOUTH_INDEX 2
#define WEST_INDEX 3
#define EAST_INDEX 4
#define IS_VISITED_INDEX 5
#define VISITED 1
#define NOT_VISITED 0

void addApples(char* matrixForPrint, int numberOfApples);
void printMaze(char* matrixForPrint);
void printMatrix(int* matrix, int rowCount, int columnCount);
void transformToMatrix(char* matrixForPrint, char* matrixForDFS);
int getSpaceCount(char* matrixForDFS);
void createAdjacencyMatrix(char* matrixForDFS, int* adjacencyMatrix);
void traverseMaze(Stack_t* stack, char* matrixForPrint, char* matrixForDFS, int* adjacencyMatrix, int adjacencyMatrixNodeCount, int currrentNodeIndex);
bool isApplePresentCurrentNode(char* matrixForPrint, int currentNode);

/* Dead End Detection Part */
int getNorth(int rowIndex, int colIndex);
int getSouth(int rowIndex, int colIndex);
int getWest(int rowIndex, int colIndex);
int getEast(int rowIndex, int colIndex);
bool isDeadEnd(char* matrixForDFS, int currentSpace);

static int rowCount = 0;
static int lengthOfRow = 0;
static int dfsStartIndex = 0;
static int dfsFinishIndex = 0;

static int totalPoints = 0;
static int totalAppleCount = 0;
static int eatenAppleCount = 0;
static int deadEndCount = 0;
static int totalRoomCount = 0;
static int visitedRoomCount = 0;

int main(void)
{
    int row = 0;
    int column = 0;
    char character = 0;
    int idx = 0;
    FILE* inputFile = NULL;
    char* matrixForPrint = NULL;
    char* matrixForDFS = NULL;
    int* adjacencyMatrix = NULL;

    Stack_t stack = { 0 };

    inputFile = fopen(FILE_NAME, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open file. File not found!\n");
        exit(-1);
    }

    while ((character = getc(inputFile)) != EOF) {
        /* NOTE: The number of columns is determined according to the first row only. */
        if (row == 0 && character != '\r' && character != '\n')
            column++;

        if (character == '\n') {
            row++;
            continue;
        }
    }

    rowCount = row;
    printf("Row count: %d\n", row);
    lengthOfRow = column;
    printf("Column count: %d\n", column);

    matrixForPrint = (char*)malloc(sizeof(char) * row * column);
    matrixForDFS = (char*)malloc(sizeof(char) * row * column);

    if (matrixForPrint == NULL || matrixForDFS == NULL) {
        printf("Allocation failure!\n");
        exit(EXIT_FAILURE);
    }

    row = 0;
    column = 0;
    character = 0;
    fclose(inputFile);
    inputFile = fopen(FILE_NAME, "r");
    while ((character = getc(inputFile)) != EOF) {
        matrixForPrint[row * lengthOfRow + column] = character;

        if (character == START_CHARACTER) {
            dfsStartIndex = row * lengthOfRow + column;
            printf("DFS Start Index: %d\n", dfsStartIndex);
        } else if (character == FINISH_CHARACTER) {
            dfsFinishIndex = row * lengthOfRow + column;
            printf("DFS Finish Index: %d\n", dfsFinishIndex);
        }

        column++;
        if (character == '\n') {
            column = 0;
            row++;
            continue;
        }
    }

    for (idx = 0; idx < rowCount * lengthOfRow; idx++) {
        if (idx != 0 && idx % (lengthOfRow) == 0)
            printf("\n");
        printf("%c", matrixForPrint[idx]);
    }
    printf("\n");

    transformToMatrix(matrixForPrint, matrixForDFS);
    printf("\n");
    printf("Matrix For DFS:\n");
    printf("\n");
    printMaze(matrixForDFS);

    totalRoomCount = getSpaceCount(matrixForDFS);
    printf("Node count: %d\n", totalRoomCount);
    totalAppleCount = totalRoomCount / 10;

    addApples(matrixForPrint, totalAppleCount);
    printf("\n%d apples added\n", totalAppleCount);
    printMaze(matrixForPrint);

    adjacencyMatrix = (int*)malloc(sizeof(int) * totalRoomCount * ADJACENCY_MATRIX_COLUMN_COUNT);
    if (adjacencyMatrix == NULL) {
        printf("Allocation failure!\n");
        exit(EXIT_FAILURE);
    }

    createAdjacencyMatrix(matrixForDFS, adjacencyMatrix);
    printMatrix(adjacencyMatrix, totalRoomCount, ADJACENCY_MATRIX_COLUMN_COUNT);

    traverseMaze(&stack, matrixForPrint, matrixForDFS, adjacencyMatrix, totalRoomCount, dfsStartIndex);

    /* Free the allocated sources */
    free(matrixForPrint);
    free(matrixForDFS);
    free(adjacencyMatrix);

    return 0;
}

void transformToMatrix(char* matrixForPrint, char* matrixForDFS)
{
    int rowIndex = 0;
    int colIndex = 0;
    int idx = 0;
    for (rowIndex = 0; rowIndex < rowCount; rowIndex++) {
        for (colIndex = 0; colIndex < lengthOfRow; colIndex++) {
            idx = rowIndex * lengthOfRow + colIndex;
            if (matrixForPrint[idx] == SPACE_CHARACTER || matrixForPrint[idx] == APPLE_CHARACTER || matrixForPrint[idx] == START_CHARACTER || matrixForPrint[idx] == FINISH_CHARACTER)
                matrixForDFS[idx] = PATH;
            else
                matrixForDFS[idx] = WALL;
        }
    }
}

int convertDFSMatrixIndexToAdjacencyMatrixIndex(int dfsIndex, int* adjacencyMatrix, int adjacencyMatrixNodeCount)
{
    int idx = 0;

    for (idx = 0; idx < adjacencyMatrixNodeCount; ++idx) {
        if (adjacencyMatrix[(idx * ADJACENCY_MATRIX_COLUMN_COUNT) + NODE_INDEX] == dfsIndex)
            return (idx * ADJACENCY_MATRIX_COLUMN_COUNT) + NODE_INDEX;
    }

    /* printf("Error: Invalid Index!\n"); */

    return 0;
}

/* The function used to navigate through the labyrinth. */
void traverseMaze(Stack_t* stack, char* matrixForPrint, char* matrixForDFS, int* adjacencyMatrix, int adjacencyMatrixNodeCount, int currrentNodeIndex)
{
    int incomingNode = 0;
    int incomingAdjacencyMatrixIndex = 0;

    int adjacencyMatrixIndex = convertDFSMatrixIndexToAdjacencyMatrixIndex(currrentNodeIndex, adjacencyMatrix, adjacencyMatrixNodeCount);
    pushToStack(stack, currrentNodeIndex);

    usleep(MICRO_SECONDS);

    if (isApplePresentCurrentNode(matrixForPrint, currrentNodeIndex)) {
        totalPoints += REWARD_POINTS;
        eatenAppleCount++;
    }

    /* If it comes back to the starting point, there is no exit from the starting point in this maze. */
    if (matrixForPrint[currrentNodeIndex] == START_CHARACTER && adjacencyMatrix[adjacencyMatrixIndex + IS_VISITED_INDEX] == VISITED) {
        printMaze(matrixForPrint);
        printf("Got stuck in maze. There is no exit :(\n");
        exit(EXIT_FAILURE);
    }

    if (adjacencyMatrix[adjacencyMatrixIndex + IS_VISITED_INDEX] == NOT_VISITED)
        visitedRoomCount++;

    adjacencyMatrix[adjacencyMatrixIndex + IS_VISITED_INDEX] = VISITED;
    /* This is the exit case */
    if (matrixForPrint[currrentNodeIndex] == FINISH_CHARACTER) {
        printf("Congratulations. Exited from maze :)\n");
        exit(EXIT_SUCCESS);
    }

    if (matrixForPrint[currrentNodeIndex] != START_CHARACTER)
        matrixForPrint[currrentNodeIndex] = SNAKE_CHARACTER;

    /* This is the normal case */
    printMaze(matrixForPrint);

    incomingNode = adjacencyMatrix[adjacencyMatrixIndex + WEST_INDEX];
    incomingAdjacencyMatrixIndex = convertDFSMatrixIndexToAdjacencyMatrixIndex(incomingNode, adjacencyMatrix, adjacencyMatrixNodeCount);
    if (matrixForDFS[incomingNode] == PATH && adjacencyMatrix[incomingAdjacencyMatrixIndex + IS_VISITED_INDEX] == NOT_VISITED)
        traverseMaze(stack, matrixForPrint, matrixForDFS, adjacencyMatrix, adjacencyMatrixNodeCount, incomingNode);

    incomingNode = adjacencyMatrix[adjacencyMatrixIndex + EAST_INDEX];
    incomingAdjacencyMatrixIndex = convertDFSMatrixIndexToAdjacencyMatrixIndex(incomingNode, adjacencyMatrix, adjacencyMatrixNodeCount);
    if (matrixForDFS[incomingNode] == PATH && adjacencyMatrix[incomingAdjacencyMatrixIndex + IS_VISITED_INDEX] == NOT_VISITED)
        traverseMaze(stack, matrixForPrint, matrixForDFS, adjacencyMatrix, adjacencyMatrixNodeCount, incomingNode);

    incomingNode = adjacencyMatrix[adjacencyMatrixIndex + NORTH_INDEX];
    incomingAdjacencyMatrixIndex = convertDFSMatrixIndexToAdjacencyMatrixIndex(incomingNode, adjacencyMatrix, adjacencyMatrixNodeCount);
    if (matrixForDFS[incomingNode] == PATH && adjacencyMatrix[incomingAdjacencyMatrixIndex + IS_VISITED_INDEX] == NOT_VISITED)
        traverseMaze(stack, matrixForPrint, matrixForDFS, adjacencyMatrix, adjacencyMatrixNodeCount, incomingNode);

    incomingNode = adjacencyMatrix[adjacencyMatrixIndex + SOUTH_INDEX];
    incomingAdjacencyMatrixIndex = convertDFSMatrixIndexToAdjacencyMatrixIndex(incomingNode, adjacencyMatrix, adjacencyMatrixNodeCount);
    if (matrixForDFS[incomingNode] == PATH && adjacencyMatrix[incomingAdjacencyMatrixIndex + IS_VISITED_INDEX] == NOT_VISITED)
        traverseMaze(stack, matrixForPrint, matrixForDFS, adjacencyMatrix, adjacencyMatrixNodeCount, incomingNode);

    /* Dead end case */
    if (isDeadEnd(matrixForDFS, currrentNodeIndex)) {
        printMaze(matrixForPrint);

        deadEndCount++;
        totalPoints -= PENALTY_POINTS;
        printf("Warning: Dead End!\n");
        printf("Total points: %d\n", totalPoints);
        printf("Dead End Count: %d\n", deadEndCount);
        sleep(2);
    }

    matrixForPrint[currrentNodeIndex] = SPACE_CHARACTER;
    /* Rollback all operations */
    popFromStack(stack, &incomingNode);
    popFromStack(stack, &incomingNode);
    traverseMaze(stack, matrixForPrint, matrixForDFS, adjacencyMatrix, adjacencyMatrixNodeCount, incomingNode);
}

void addApples(char* matrixForPrint, int numberOfApples)
{
    int totalApples = 0;
    int rowIndex = 0;
    int colIndex = 0;

    srand((unsigned)time(NULL));

    while (totalApples < numberOfApples) {
        rowIndex = (int)(rand() % (rowCount + 1));
        colIndex = (int)(rand() % (lengthOfRow + 1));
        if (matrixForPrint[rowIndex * lengthOfRow + colIndex] == SPACE_CHARACTER) {
            matrixForPrint[rowIndex * lengthOfRow + colIndex] = APPLE_CHARACTER;
            totalApples++;
        }
    }
}

void printMaze(char* matrixForPrint)
{
    int rowIndex, colIndex;
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    for (rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        for (colIndex = 0; colIndex < lengthOfRow; ++colIndex) {
            printf("%c", matrixForPrint[rowIndex * lengthOfRow + colIndex]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Total points: %d\n", totalPoints);
    printf("Eaten Apple Counts: %d/%d\n", eatenAppleCount, totalAppleCount);
    printf("Visited Room Counts: %d/%d\n", visitedRoomCount, totalRoomCount);
    printf("Dead End Count: %d\n", deadEndCount);
}

void printMatrix(int* matrix, int rowCount, int columnCount)
{
    int rowIndex = 0;
    int colIndex = 0;
    int idx = 0;

    for (rowIndex = 0; rowIndex < rowCount; rowIndex++) {
        for (colIndex = 0; colIndex < columnCount; colIndex++) {

            if (idx != 0 && ((idx + 1) % columnCount) == 0)
                printf("\n");

            idx = rowIndex * columnCount + colIndex;
            printf("%5d ", matrix[idx]);
        }
    }

    printf("\n");
}

int getSpaceCount(char* matrixForDFS)
{
    int rowIndex = 0;
    int colIndex = 0;
    int idx = 0;
    int totalRoomCount = 0;

    for (rowIndex = 0; rowIndex < rowCount; rowIndex++) {
        for (colIndex = 0; colIndex < lengthOfRow; colIndex++) {
            idx = rowIndex * lengthOfRow + colIndex;
            if (matrixForDFS[idx] == '1')
                ++totalRoomCount;
        }
    }

    return totalRoomCount;
}

void getRowAndColumnIndex(const int nodeIndex, int* rowIndex, int* columnIndex)
{
    *rowIndex = nodeIndex / lengthOfRow;
    *columnIndex = nodeIndex % lengthOfRow;
}

bool isApplePresentCurrentNode(char* matrixForPrint, int currentNode)
{
    int rowIndex = 0;
    int columnIndex = 0;
    getRowAndColumnIndex(currentNode, &rowIndex, &columnIndex);

    if (matrixForPrint[currentNode] != APPLE_CHARACTER)
        return false;

    printf("Apple eaten at node: %d, rowIndex: %d, columnIndex %d\n", currentNode, rowIndex, columnIndex);
    printf("+%d point!\n", REWARD_POINTS);

    return true;
}

int getNorth(int rowIndex, int colIndex)
{
    if ((rowIndex < 0 || rowIndex > rowCount) || (colIndex < 0 || colIndex > lengthOfRow)) {
        return -1;
    }

    if (rowIndex - 1 < 0) {
        return -1;
    } else {
        return (rowIndex - 1) * lengthOfRow + colIndex;
    }
}

int getSouth(int rowIndex, int colIndex)
{
    if ((rowIndex < 0 || rowIndex > rowCount) || (colIndex < 0 || colIndex > lengthOfRow)) {
        return -1;
    }

    if (rowIndex + 1 > rowCount) {
        return -1;
    } else {
        return (rowIndex + 1) * lengthOfRow + colIndex;
    }
}

int getWest(int rowIndex, int colIndex)
{
    if ((rowIndex < 0 || rowIndex > rowCount) || (colIndex < 0 || colIndex > lengthOfRow)) {
        return -1;
    }

    if (colIndex - 1 < 0) {
        return -1;
    } else {
        return rowIndex * lengthOfRow + colIndex - 1;
    }
}

int getEast(int rowIndex, int colIndex)
{
    if ((rowIndex < 0 || rowIndex > rowCount) || (colIndex < 0 || colIndex > lengthOfRow)) {
        return -1;
    }

    if (colIndex + 1 > lengthOfRow) {
        return -1;
    } else {
        return rowIndex * lengthOfRow + colIndex + 1;
    }
}

bool isDeadEnd(char* matrixForDFS, int currentSpace)
{
    int node = 0;
    int wallCount = 0;
    int rowIndex = 0;
    int columnIndex = 0;

    getRowAndColumnIndex(currentSpace, &rowIndex, &columnIndex);

    node = getNorth(rowIndex, columnIndex);
    if (matrixForDFS[node] == WALL)
        wallCount++;

    node = getSouth(rowIndex, columnIndex);
    if (matrixForDFS[node] == WALL)
        wallCount++;

    node = getWest(rowIndex, columnIndex);
    if (matrixForDFS[node] == WALL)
        wallCount++;

    node = getEast(rowIndex, columnIndex);
    if (matrixForDFS[node] == WALL)
        wallCount++;

    if (wallCount >= 3) {
        printf("Dead end detected at node: %d, rowIndex: %d, columnIndex %d\n", currentSpace, rowIndex, columnIndex);
        printf("%d point!\n", PENALTY_POINTS);
        return true;
    }

    return false;
}

void createAdjacencyMatrix(char* matrixForDFS, int* adjacencyMatrix)
{
    int rowIndex = 0;
    int colIndex = 0;
    int adjIndex = 0;
    int idx = 0;

    printf("Node Index + North Index + South Index + West Index + East Index + Is Visited\n");

    for (rowIndex = 0; rowIndex < rowCount; rowIndex++) {
        for (colIndex = 0; colIndex < lengthOfRow; colIndex++) {
            idx = rowIndex * lengthOfRow + colIndex;

            if (matrixForDFS[idx] == PATH) {

                adjacencyMatrix[adjIndex++] = idx;
                printf("Node: %3d, ", idx);

                adjacencyMatrix[adjIndex] = getNorth(rowIndex, colIndex);
                printf("  North: %5d, ", adjacencyMatrix[adjIndex++]);

                adjacencyMatrix[adjIndex] = getSouth(rowIndex, colIndex);
                printf("South: %5d, ", adjacencyMatrix[adjIndex++]);

                adjacencyMatrix[adjIndex] = getWest(rowIndex, colIndex);
                printf("West: %5d, ", adjacencyMatrix[adjIndex++]);

                adjacencyMatrix[adjIndex] = getEast(rowIndex, colIndex);
                printf("East: %5d", adjacencyMatrix[adjIndex++]);

                adjacencyMatrix[adjIndex++] = NOT_VISITED;
                printf("     false\n");
            }
        }
    }
}
