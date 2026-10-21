#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char type[20];
    char name[50];
    int key;
} NODE;

int fillHashTable(NODE **hashTable, int M, char *fileContent);
void printHashTable(NODE **hashTable, int M);
int calculateKey(char *string, int M);
int doubleHash(int key, int m, int i);
int insert(NODE **hashTable, int M, char *type, char *name);
int lookup(NODE **hashTable, int M, char *name);
int calculateTableSize(int variableCount);
int countVariables(char *fileContent);
char* readFileContent();

int main() {

    int M, i;
    int variableCount;
    char *fileContent;
    int mode;
    int declaredVariableCount;

    fileContent = readFileContent();

    variableCount = countVariables(fileContent);

    M = calculateTableSize(variableCount);

    NODE **hashTable = (NODE**)malloc(M * sizeof(NODE*));
    for (i = 0; i < M; i++) {
        hashTable[i] = NULL;
    }

    printf("\nSelect mode\n");
    printf("Normal mode: 1\n");
    printf("Debug mode: 2\n");
    printf("choice: ");
    scanf("%d", &mode);

    printf("\n");
    
    declaredVariableCount = fillHashTable(hashTable, M, fileContent);

    printf("\n");

    if (mode == 2) {
        printf("Number of variables before declaration control = %d\n", variableCount);
        printf("Number of declared variables = %d\n", declaredVariableCount);
        printf("Table size: %d\n", M);
        printHashTable(hashTable, M);
    } 

    for (i = 0; i < M; i++) {
        if (hashTable[i]) {
            free(hashTable[i]);
        }
    }
    free(hashTable);

    free(fileContent);

    return 0;
}

/*
@brief fills the hash table with variables in c code

@param hashTable array of hash nodes 
@param M hash table size
@param fileContent a char array which is content of file

@return returns the number of declared variables
*/
int fillHashTable(NODE **hashTable, int M, char *fileContent) {
    char *line, *saveLine;
    char *token, *saveToken;
    char currentType[10];
    char *delimiters = " ,\t\n(){}";
    char *variableToken, *saveVariableToken;
    char *saveAssignedToken;
    int declaredVariableCount = 0;

    char *copyFileContent = strdup(fileContent);

    line = strtok_r(copyFileContent, ";{}", &saveLine);
    while (line) { // seperates each line by ';' character and runs for each line
        token = strtok_r(line, delimiters, &saveToken);

        // if the line starts with "int", "char" or "float"
        if (token && (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0)) {
            strcpy(currentType, token);
            token = strtok_r(saveToken, ",", &saveVariableToken);
            while (token) { // for each variable name checks if it is a variable name
                variableToken = strtok_r(token, " =\n", &saveAssignedToken);
                if (variableToken && variableToken[0] == '_') {
                    if (insert(hashTable, M, currentType, variableToken) == 1) { // if it can be inserted, increment the count
                        declaredVariableCount++;
                    }
                }
                variableToken = strtok_r(NULL, " =\n", &saveAssignedToken);
                // checks if the assigned varible was declared before by looking the hash table
                if (variableToken && variableToken[0] == '_' && lookup(hashTable, M, variableToken) == 0) {
                    printf("Error: '%s' is not declared!\n", variableToken);
                }
                token = strtok_r(NULL, ",", &saveVariableToken);
            }
        }

        else {
            while (token) { // looks for each used variable and checks if they are declared by looking the hash table
                if (token && token[0] == '_' && lookup(hashTable, M, token) == 0) {
                    printf("Error: '%s' is not declared!\n", token);
                }
                token = strtok_r(saveToken, delimiters, &saveToken);
            }
        }
        
        line = strtok_r(NULL, ";{}", &saveLine);
    }

    free(copyFileContent);

    return declaredVariableCount;
}

/*
@brief prints the hash table with some information

@param hashTable array of hash nodes 
@param M hash table size

@return 
*/
void printHashTable(NODE **hashTable, int M) {
    int i;

    printf("\nHash Table:\n");
    for (i = 0; i < M; i++) {
        if (hashTable[i] != NULL) {
            printf("%d: %s (%s), first calculated address = %d\n", i, hashTable[i]->name, hashTable[i]->type, hashTable[i]->key % M);
        } else {
            printf("%d: NULL\n", i);
        }
    }
    printf("\n");
}

/*
@brief calculates the key value of a string by using horner's method

@param string a string that we calculate the key value with horner's method
@param M hash table size

@return returns the calculated key
*/
int calculateKey(char *string, int M) {
    int length = strlen(string);
    int i;
    int R = 31;
    int key = 0;

    for (i = 0; i < length; i++) {
        key += string[i] * pow(R, length - i - 1);
    }

    return key;
}

/*
@brief calculates double hash value of a key

@param key key of a string which is calculated by horners method
@param M hash table size
@param i iterator to calculate double hash index

@return returns double hash value for given key, M and i
*/
int doubleHash(int key, int M, int i) {
    int h, h1, h2, m2;

    m2 = M - 3;
    h1 = key % M;
    h2 = 1 + (key % m2);

    h = (h1 + i * h2) % M;

    return h;
}

/*
@brief creates new hash node with given type and name and inserts it to hash table

@param hashTable array of hash nodes 
@param M hash table size
@param type type of variable which is int or char or float
@param name name of variable

@return if name inserted, returns 1. else returns 0
*/
int insert(NODE **hashTable, int M, char *type, char *name) {
    if (lookup(hashTable, M, name)) {
        printf("Error: '%s' is already declared!\n", name);
        return 0;
    }

    int key = calculateKey(name, M);
    int i = 0;
    int index;

    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    strcpy(newNode->type, type);
    strcpy(newNode->name, name);
    newNode->key = key;

    while (i < M) {
        index = doubleHash(key, M, i);
        if (hashTable[index] == NULL) {
            hashTable[index] = newNode;
            printf("'%s' is declared successfully.\n", name);
            return 1;
        }
        i++;
    }
    
    printf("Error: Hash table is full.\n");
    return 0;
}

/*
@brief searchs the name in hash table. if it exist, returns 1. else returns 0

@param hashTable array of hash nodes 
@param M hash table size
@param name name of variable

@return if name exist in hash table, returns 1. else returns 0
*/
int lookup(NODE **hashTable, int M, char *name) {
    int key = calculateKey(name, M);
    int i = 0;
    int index;

    while (i < M) {
        index = doubleHash(key, M, i);
        if (hashTable[index] == NULL) {
            return 0;
        }
        if (strcmp(hashTable[index]->name, name) == 0) {
            return 1;
        }
        i++;
    }
    return 0;
}

/*
@brief calculates the table size M that is smallest prime number bigger than 2 times number of variables

@param variableCount the number of variables in the c code 

@return returns the table size M
*/
int calculateTableSize(int variableCount) {
    int M = 2 * variableCount + 1;
    int isPrime = 0;
    int i;

    while (!isPrime) {
        isPrime = 1;

        for (i = 2; i <= sqrt(M) && isPrime; i++) {
            if (M % i == 0) {
                isPrime = 0;
            }
        }

        if (!isPrime) {
            M++;
        }
    }

    return M;
}

/*
@brief counts the variables in the c code

@param fileContent a char array which is content of file

@return returns the number of variables in c code
*/
int countVariables(char *fileContent) {
    char *line, *saveLine;
    char *token, *saveToken;
    int variableCount = 0;
    char *delimiters = " ,\t\n(){}";
    char *variableToken, *saveVariableToken;
    
    char *copyFileContent = strdup(fileContent);

    line = strtok_r(copyFileContent, ";{}", &saveLine);
    while (line) { // seperates each line by ';' character and runs for each line
        token = strtok_r(line, delimiters, &saveToken);

        // if the line starts with "int", "char" or "float"
        if (token && (strcmp(token, "int") == 0 || strcmp(token, "float") == 0 || strcmp(token, "char") == 0)) {
            token = strtok_r(saveToken, ",", &saveVariableToken);
            while (token) { // for each variable name checks if it is a variable name
                variableToken = strtok(token, " =");
                if (variableToken && variableToken[0] == '_') {
                    variableCount++;
                }
                token = strtok_r(NULL, ",", &saveVariableToken);
            }
        }
        
        line = strtok_r(NULL, ";{}", &saveLine);
    }

    free(copyFileContent);

    return variableCount;
}

/*
@brief reads whole text to a char array

@return returns the content of file as char array
*/
char* readFileContent() {
    FILE* file;
    char fileName[256];
    char* fileContent;

    do {
        printf("\nEnter the filename: ");
        scanf("%s", fileName);

        file = fopen(fileName, "r");
        if (!file) {
            printf("Could not open file. ");
        }
    } while (!file);

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    fileContent = (char*)malloc(fileSize + 1);

    fread(fileContent, 1, fileSize, file);
    fileContent[fileSize] = '\0';

    fclose(file);
    return fileContent;
}