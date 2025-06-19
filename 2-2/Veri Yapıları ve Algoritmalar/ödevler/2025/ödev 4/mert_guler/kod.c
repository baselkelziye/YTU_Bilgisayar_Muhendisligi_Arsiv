#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define ORANGE "\033[38;5;208m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

/*
@brief compares two numbers based on ordering type and returns the comparison result.

@param First first number in comparison. This is the number that comes before in the array.
@param Second second number in comparison. This number comes after the First parameter
@param orderType determines the type of ording, if 0 Ascending, if 1 Descending.

@return return the comparison results of First and Second depending on orderType
*/

/*
@brief A struct for storing a matrix and its size
*/
typedef struct MatrixData {
    int size;
    int** matrix;
} MatrixData;

/*
@brief Creates a NxN square matrix with dynamic memory allocation

@param size  Size of the square matrix

@return return The created matrix
*/
int** createSquareMatrix(int size){
    int i;
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
    }
    return matrix;
}

/*
@brief Frees memory of a matrix

@param matrix The matrix to be memory freed
@param size The size of the matrix
*/
void freeMatrix(int** matrix, int size){
    int i;
    for (i = 0; i < size; i++) {
        free(matrix[i]);
    }
    
    free(matrix);
}

/*
@brief Fills a array with ones

@param array The matrix to be filled with 1s
@param size The size of the array
*/
void fillArray(int* array, int size){
    int i;
    for (i = 0; i < size; i++) {
        array[i] = 1;
    }
}

/*
@brief Prints a square matrix to console

@param matrix The matrix to be printed
@param size The size of the matrix
*/
void printSquareMatrix(int** matrix, int size){
    int i, j;
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/*
@brief Prints a array with format like: [ a b c ]

@param array The array to be printed
@param size The size of the array
*/
void printArray(int* array, int size){
    int i;
    printf("[ ");
    for (i = 0; i < size; i++) {
        if (array[i] == 1) {
            printf(GREEN "%d " RESET, array[i]);
        } else {
            printf("%d ", array[i]);
        }
    }
    printf("]\n\n");
}

/*
@brief Checks if a vertex is a neighbor to another. Takes a array that represents neighbours.

@param neighbours The neighbour array to be checked
@param vertexIndex The vertex to be checked for neighbourness
 
@return Returns the data in the neighbours array at vertex's index (1 or 0, 1 means neighbour 0 is not)
*/
int isNeighbour(int* neighbours, int vertexIndex){
    return neighbours[vertexIndex];
}

/*
@brief Prints the result for finding the prize vertex. Also checks for vertexes that has equal neighbours

@param resultArray The result array that contains -1 or 1, -1 means not prize and 1 means prize
@param size The size of the array (vertex count)
@param questionCount The question count that asked to vertexes
*/
void printResult(int* resultArray, int size, int questionCount){
    int i;
    int findCount = 0; /* The count of the prize vertexes. Necessary for checking multiple results */
    
    for (i = 0; i < size; i++) {
        if (resultArray[i] == 1) {
            printf("Prize Vertex is founded as: " GREEN "%d" RESET " in " GREEN "%d" RESET "  questions\n", i, questionCount);
            findCount++;
        }
    }
    
    if (findCount > 1) {
        printf("%d " RED "equal vertexes" RESET " with same neighbours are found!!!", findCount);
    }
}

/*
@brief Makes current vertexs neighbours -1. This happens if vertex is not a neighbour to prize vertex. Neighbours cant be prize vertex.

@param neighboursArray The array that contains current vertexs neighbours with 1 or 0s
@param size The size of the array (vertex count)
@param result The result array for updating potential of prize vertexs.
@param resultSize The size of the elements in the result array. Must be checked because we control loop with this variable.
*/
void makeAdjInactive(int* neighboursArray, int size, int* resultArray, int* resultSize){
    int i;
    for (i = 0; i < size; i++) {
        /* If current vertex is still has potential to be prize */
        /* And it is neighbour to the vertex*/
        if (resultArray[i] != -1 && isNeighbour(neighboursArray, i)){
            resultArray[i] = -1;
            /* Result size is now smaller. Neccessary for stoping the loop early */
            *resultSize = *resultSize - 1;
        }
    }
}

/*
@brief Makes current vertexs non neighbours -1. This happens if vertex is a neighbour to prize vertex. Then non neighbours cant be prize vertex.

@param neighboursArray The array that contains current vertexs neighbours with 1 or 0s
@param size The size of the array (vertex count)
@param result The result array for updating potential of prize vertexs.
@param resultSize The size of the elements in the result array. Must be checked because we control loop with this variable.
*/
void makeNonAdjInactive(int* neighboursArray, int size, int* resultArray, int* resultSize){
    int i;
    for (i = 0; i < size; i++) {
        /* If current vertex is still has potential to be prize */
        /* And it is not neighbour to the vertex*/
        if (resultArray[i] != -1 && !isNeighbour(neighboursArray, i)){
            resultArray[i] = -1;
            /* Result size is now smaller. Neccessary for stoping the loop early */
            *resultSize = *resultSize - 1;
        }
    }
}

/*
@brief Makes current vertexs non neighbours -1. This happens if vertex is a neighbour to prize vertex. Then non neighbours cant be prize vertex.

@param matrix The matrix that contains the adjacency matrix of the graph
@param size The size of the matrix
@param prizeVertex The prize vertex to be searched in the graph
*/
void findPrizeVertex(int** matrix, int size, int prizeVertex){
    int resultSize = size; /* Size of the resultArray, if size < 1 then we found the deterministic prize. For exiting loop early. */
    int currentIndex = 0; /* The current vertexs index (that being questioned) */
    int* resultArray = (int*)malloc(sizeof(int)); /* The array that contains potential prize vertexes. 1 for has potential and -1 for dont have */
    
    /* Fill array with 1s (This means vertex still has potential, and will convert to -1 if cant be prize) */
    fillArray(resultArray, size);
    
    printf("Result Array: ");
    printArray(resultArray, size);
    
    /* Continue while resultArray is bigger than 1 element. This means we didnt found the actual (certain) prize vertex yet */
    /* Continue while currentIndex is smaller than size. This means we will stop if we questioned all of the vertexes*/
    while (resultSize > 1 && currentIndex < size){
        printf("Asking to " GREEN "Vertex %d\n" RESET, currentIndex);
        
        /* If it is neighbour then make itself -1 and non neighbours of the vertex -1. This means vertex doesnt have any potential to be prize */
        if (isNeighbour(matrix[currentIndex], prizeVertex)) {
            printf(GREEN "Vertex %d is neighbour with %d! Make vertex and non neighbours -1\n" RESET, currentIndex, prizeVertex);
            makeNonAdjInactive(matrix[currentIndex], size, resultArray, &resultSize);
        }
        
        /* If it is not neighbour then make its neighbours -1. This means vertex has potential to be prize */
        else {
            printf(RED "Vertex %d is not neighbour with %d! Make vertex's neighbours -1\n" RESET, currentIndex, prizeVertex);
            makeAdjInactive(matrix[currentIndex], size, resultArray, &resultSize);
        }
        
        printf("Result Array: ");
        printArray(resultArray, size);
        
        currentIndex++;
    }
    
    printResult(resultArray, size, currentIndex);
    free(resultArray);
}

/*
@brief Reads prize vertexs index from console

@param size The size of the matrix for checking for non existens vertexes
 
@return The prize vertex index
*/
int getPrizeVertex(int size){
    int validInput = 0;
    int prizeVertex = 0;
    
    while (validInput == 0) {
        printf("Enter Prize Vertex: ");
        scanf("%d", &prizeVertex);
        
        if (prizeVertex > size - 1) {
            printf("\nYou entered a non existent vertex!\n");
        } else {
            validInput = 1;
        }
    }
    
    return prizeVertex;
}

/*
@brief Reads data from a file, calculates matrix size, allocates dynamic memory, prints matrix and returns matrix data as a struct

@return Returns MatrixData struct that contains matrix and its size
*/
MatrixData* readData(void){
    char fileName[100];
    FILE *file = NULL;
    int validFile = 0;
    int** matrix;
    char line[100];
    char* lineContext;
    int i, j;
    int matrixSize = 0;
    MatrixData* matrixData;
    
    printf("\nEnter the name of the file you want to load (with .txt)\nEnter Q to Quit: ");
    
    while (validFile == 0) {
        fgets(fileName, sizeof(fileName), stdin);
        fileName[strcspn(fileName, "\n")] = 0;
        
        if (strcmp(fileName,"q") == 0 || strcmp(fileName,"Q") == 0){
            printf("\nExiting...\n");
            exit(1);
        }

        file = fopen(fileName, "r");
        
        if (file != NULL) {
            validFile = 1;
        } else {
            printf("\nFile could not be opened or found. Please try again: ");
        }
    }
    
    /* Write data, assuming data is perfectly fits the specified template */
    
    /* Read first line of the matrix to calculate the size */
    fgets(line, sizeof(line), file);
    lineContext = strtok(line, " \t\n");
    while (lineContext != NULL) {
        matrixSize++;
        lineContext = strtok(NULL, " \t\n");
    }
    
    printf("\nMatrix size: %d x %d\n", matrixSize, matrixSize);
    /* Create matrix dynamicly */
    matrix = createSquareMatrix(matrixSize);
    
    /* Restart and read file from beginning */
    file = fopen(fileName, "r");
    
    /* Scan matrix from file*/
    for (i = 0; i < matrixSize; i++) {
        for (j = 0; j < matrixSize; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    
    printSquareMatrix(matrix, matrixSize);
    fclose(file);
    printf("\n" GREEN "Successfully Loaded File!\n\n" RESET);

    matrixData = (MatrixData*)malloc(sizeof(matrixData));
    matrixData->size = matrixSize;
    matrixData->matrix = matrix;
    
    free(lineContext); /* Free string that was necessary for calculating matrix size */
    return matrixData;
}

int main(int argc, const char * argv[]) {
    int prizeVertex;
    MatrixData* matrixData;
    
    printf("\nAlgoritma Ozeti: Ilk olarak bir sonuc dizisi acilir ve 1 ile doldurulur. \n"
           "Sonuc dizisinin eleman sayisi bir sayac ile tutulur\n"
           "0 vertex'inden baslanilarak komsuluk sorgulanir.\n"
           "Eger komsu ise vertex'in komsu olmadiklari ve kendisi sonuc dizisinde -1 degerine esitlenir\n"
           "Eger komsu degil ise vertex'in komsulari -1'lenir.\n"
           "Bu sekilde worst case O(N) olsa da ortalamada hizli bir sekilde sonuc bulunur\n");
    
    matrixData = readData();
    prizeVertex = getPrizeVertex(matrixData->size);
    findPrizeVertex(matrixData->matrix, matrixData->size, prizeVertex);
    freeMatrix(matrixData->matrix, matrixData->size);
    free(matrixData);

    return 0;
}
