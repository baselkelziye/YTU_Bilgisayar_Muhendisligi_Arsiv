#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct data{
    char *name;
    int firstIndex;
    char *type;

}typedef DATA;

int isVariable(char *text);
int varCounter(char **tokens);
char* readFile(char *fileName);
char **tokenizer(char *text);
void printTokens(char **tokens);
int findMinPrimeAboveDouble(int number);
int isPrime(int num);
unsigned long long int hornerHash(char *varName);
int hash(char *varName, int i, int m);
int hash2(unsigned long long int key, int m);
int hash1(unsigned long long int key, int m);
void printHashTable(DATA *hashTable, int hashTableSize);
void insert(char *varName, char *varType, int m, DATA *hashTable);
void lookUp(char *varName, char *varType, int m, DATA *hashTable);
void processTokens(char **tokens, int hashTableSize, DATA *hashTable);
int declaredVariableCounter(DATA *hashTable, int hashTableSize);
int initHashTable(DATA **hashTable, char **tokens);


int main(int argc, char *argv[]) {
    
    char *text = readFile("para.txt");
    int i, mode = 1, flag = 1;
    int declaredVariableCount;
    char **tokens = tokenizer(text); // token matrix to be processed   
    DATA *hashTable;
    int hashTableSize = initHashTable(&hashTable, tokens); //initializing hashTable via pointer and returning size 
    
    while(flag)
    {
        printf("\nNORMAL Mode: 0\nDEBUG Mode: 1\n");
        scanf("%d", &mode);
        if(mode == 1)
        {
            printf("----DEBUG Mode is selected----\n");
            processTokens(tokens, hashTableSize, hashTable);
            declaredVariableCount = declaredVariableCounter(hashTable, hashTableSize);
            printf("\n\n\nDeclared Variable Amount: %d -- Hash Table Size: %d", declaredVariableCount, hashTableSize);
            printHashTable(hashTable, hashTableSize);
            flag = 0;
        }
        else if(mode == 0)
        {
            printf("----NORMAL Mode is selected----\n");
            processTokens(tokens, hashTableSize, hashTable);
            flag = 0;
        }
        else
        {
            ("Wrong input\n");
        }
    }
    
    return 0;
}

/*
@brief Counts the number of declared variables in the hash table.

@param hashTable     The hash table containing variable data.
@param hashTableSize The size of the hash table.

@return The number of declared variables.
*/
int declaredVariableCounter(DATA *hashTable, int hashTableSize)
{
    int i, counter = 0;
    for( i=0; i<hashTableSize; i++)
    {
        if(hashTable[i].name != NULL) // iterate thorugh hashTable, if the element is not null then increase counter
        {
            counter++;
        }
    }
    return counter;
}

/*
@brief Initializes the hash table based on the number of tokens.

@param hashTable Pointer to the hash table.
@param tokens    The array of tokens to process.

@return The size of the initialized hash table.
*/
int initHashTable(DATA **hashTable, char **tokens){
    int i;
    int varCount=varCounter(tokens); //varCount for calculate hashTableSize
    int hashTableSize = findMinPrimeAboveDouble(varCount); // calculating hashTableSize
    
    *hashTable = (DATA*)malloc(sizeof(DATA) * hashTableSize); // allocating hashTable

    if (*hashTable == NULL) {
        perror("Error allocating memory for hash table");
        exit(-1);
    }
    for (i = 0; i < hashTableSize; i++) { // initializing
        (*hashTable)[i].name = NULL;
        (*hashTable)[i].firstIndex = -1;
        (*hashTable)[i].type = NULL;
    }
    return hashTableSize;
}

/*
@brief Classificate the tokens and performs lookups or insertions based on type declarations.

@param tokens        The array of tokens to process.
@param hashTableSize The size of the hash table.
@param hashTable     The hash table to store the variables.

@return
*/
void processTokens(char **tokens, int hashTableSize, DATA *hashTable){
    int i = 0;
    while(tokens[i] != NULL)
    {   // compare the token with its type(int, char, float)
        if(!strcmp(tokens[i], "int")) 
        {
            i++; // iterate through next token
            while(strchr(tokens[i], ';') == NULL) //call lookUp with insertion mode until the token containing ';', insert it if its not declared before.
            {
                if(isVariable(tokens[i])) lookUp(tokens[i], "int", hashTableSize, hashTable);
                
                i++; // iterate through next token
            }
            if(isVariable(tokens[i]))// checks the edge case like int a, b=7;
            {
                tokens[i] = strtok(tokens[i],";"); // removes the ';' from token
                lookUp(tokens[i], "int", hashTableSize, hashTable); // call lookUp with insertion mode, inserting it if its not declared before
            }
                 
        }
        else if(!strcmp(tokens[i], "char"))
        {
            i++; // iterate through next token
            while(strchr(tokens[i], ';') == NULL) //call lookUp with insertion mode until the token containing ';', insert it if its not declared before.
            {     
                if(isVariable(tokens[i])) lookUp(tokens[i], "char", hashTableSize, hashTable);
                i++; // iterate through next token
            }
            if(isVariable(tokens[i]))// checks the edge case like int _a, _b=7;
            {
                tokens[i] = strtok(tokens[i],";"); // removes the ';' from token
                lookUp(tokens[i], "char", hashTableSize, hashTable); // call lookUp with insertion mode, inserting it if its not declared before
            } 
        }
        else if(!strcmp(tokens[i], "float"))
        {
            i++; // iterate through next token
            while(strchr(tokens[i], ';') == NULL) //call lookUp with insertion mode until the token containing ';', insert it if its not declared before.
            {
                if(isVariable(tokens[i])) lookUp(tokens[i], "int", hashTableSize, hashTable);  // call lookUp with insertion mode, inserting it if its not declared before
                i++;  // iterate through next token
            }
            if(isVariable(tokens[i]))// checks the edge case like int a, b=7;
            {
                tokens[i] = strtok(tokens[i],";"); // removes the ';' from token
                lookUp(tokens[i], "float", hashTableSize, hashTable); // call lookUp with insertion mode, inserting it if its not declared before
            }
        }
        else if(isVariable(tokens[i])) // check the token's type with calling lookUp func with checking mode
        {
            tokens[i] = strtok(tokens[i],";"); // removes the ';' from token
            lookUp(tokens[i], NULL, hashTableSize, hashTable); // check the validity of "_aa = 5;" for example
        }
        i++; // iterate through next token
    }
}

/*
@brief Checks if the given text is a variable (starts with an underscore).

@param text The string to check.

@return 1 if the text is a variable, 0 otherwise.
*/
int isVariable(char *text)
{
    if(text[0] == '_')  return 1; // check the text, starts with an underscore or not
    return 0; 
}

/*
@brief Prints the contents of the hash table.

@param hashTable     The hash table containing variable data.
@param hashTableSize The size of the hash table.

@return
*/
void printHashTable(DATA *hashTable, int hashTableSize) {
    // output:
    // Index i: Type: hashTable[i].type Name: hashTable[i].name FirstIndex: hashTable[i].firstIndex 
    // firstIndex = first hash index to see open-addresing be used or not, to store the variable.
    int i;
    printf("\nHash Table Contents:\n");
    printf("----------------------------\n");
    for (i = 0; i < hashTableSize; i++) {
        if (hashTable[i].name != NULL) {
            printf("Index %d:", i);
            printf("\tType: %s", hashTable[i].type);
            printf("\tName: %s", hashTable[i].name);
            printf("\tFirstIndex: %d\n", hashTable[i].firstIndex);
        } else {
            printf("Index %d:\tEmpty\n", i); // if the index is null for hashTable print Empty.
        }
    }
    printf("----------------------------\n");
}

/*
@brief Inserts a variable into the hash table.

@param varName   The name of the variable.
@param varType   The type of the variable.
@param m         The size of the hash table.
@param hashTable The hash table to insert the variable into.

@return
*/
void insert(char *varName, char *varType, int m, DATA *hashTable)
{
    int i=0;
    int index = hash(varName, i, m);  // hash index calculation via HornerMethod and double hashing
    int firstHashedIndex = index; // will be assigned into var.FirstIndex
    int varNameLen;
    int varTypeLen;

    // checking through hash function in hashTable until find NULL or the variable
    while(hashTable[index].name != NULL && strcmp(hashTable[index].name, varName) != 0)
    {
        i++; // to be used in open addresing in double hash function
        index = hash(varName, i, m);
    }

    if(hashTable[index].name == NULL) //if empty index is found then insert variable
    {
        varNameLen = strlen(varName);
        varTypeLen = strlen(varType);
        hashTable[index].name = malloc(varNameLen); // allocating memory for pointer
        hashTable[index].type = malloc(varTypeLen); // allocating memory for pointer

        // assignment
        hashTable[index].firstIndex = firstHashedIndex;
        strcpy(hashTable[index].name, varName);
        strcpy(hashTable[index].type, varType);        
        return;
    }

    printf("\n%s already declared.\n",varName);    
}

/*
@brief Looks up a variable in the hash table and inserts it if in declaration mode.

@param varName   The name of the variable.
@param varType   The type of the variable.
@param m         The size of the hash table.
@param hashTable The hash table to search in.

@return 0 if the lookup or insertion is successful.
*/
void    lookUp(char *varName, char *varType, int m, DATA *hashTable) 
{
    int index; // hash index to be calculated
    int i= 0;
    if(varType == NULL) // checking mode if varType == NULL
    {
        index = hash(varName, i, m); // hash index calculation via HornerMethod and double hashing
        // checking through hash function in hashTable until find NULL or the variable 
        while(hashTable[index].name != NULL && strcmp(hashTable[index].name, varName) != 0)
        {
            i++;
            index = hash(varName, i, m);
        }
        if(hashTable[index].name == NULL) // if the variable is not declared print an error message
        {
            // if index is not null and varName is not equal to hashTable[index].name iterate via doubleHashing 
            printf("\n%s was not declared before. Not usable.", varName);
            return;
        }
    }
    else // declaration mode if varType != NULL
    {
        index = hash(varName, i, m); //hash index calculation via HornerMethod and double hashing
        // checking through hash function in hashTable until find NULL or the variable 
        while(hashTable[index].name != NULL && strcmp(hashTable[index].name, varName) != 0)
        {
            // if index is not null and varName is not equal to hashTable[index].name iterate via doubleHashing 
            i++;
            index = hash(varName, i, m); 
        }
        if(hashTable[index].name == NULL)// if empty index is found then insert variable
        {            
            insert(varName, varType, m, hashTable);            
            return;
        }
        else // if same varName is already declared in hashed index print an error. 
        {
            printf("\n%s already declared. The declared variable cannot be declared once more.", varName);
        }
    }
}

/*
@brief Computes the hash value of a variable name using Horner's method.

@param varName The name of the variable.

@return The computed hash value as an unsigned long long int.
*/
unsigned long long int hornerHash(char *varName) {
    unsigned long long int key = 0;

    int length = strlen(varName); // length of varName
    int i;
    int k = pow(31, length -1);
    for (i = 0; i < length; i++) { // key = str[0] * 31^(n-1) + str[1] * 31^(n-2) + .... + str[n-1] * 31 ^ (0)
        key += (k * varName[i]);
        k /= 31;
    }

    return key;
}

/*
@brief Computes the primary hash function for a given key.

@param varName The name of the variable.
@param i       The probing index.
@param m       The size of the hash table.

@return The computed hash index.
*/
int hash(char *varName, int i, int m)
{
    unsigned long long int key = hornerHash(varName);
    return (hash1(key, m) + i * hash2(key, m-3)) % m;
}
/*
@brief Computes the secondary hash function for double hashing.

@param key The hash key.
@param m   The size of the hash table.

@return The computed secondary hash value.
*/
int hash2(unsigned long long int key, int m)
{
    return 1 + (key % m);
}
/*
@brief Computes the primary hash function value.

@param key The hash key.
@param m   The size of the hash table.

@return The computed primary hash value.
*/
int hash1(unsigned long long int key, int m)
{
    return key % m;
}


/*
@brief Finds the smallest prime number greater than or equal to double the given number.

@param number The base number to find the prime for.

@return The smallest prime number greater than or equal to double the input number.
*/
int findMinPrimeAboveDouble(int number) {
    int target = 2 * number;
    while (!isPrime(target)) { // increase until found prime number
        target++;
    }
    return target;
}

/*
@brief Checks if a given number is prime.

@param num The number to check.

@return 1 if the number is prime, 0 otherwise.
*/
int isPrime(int num) {
    if (num <= 1) return 0; 
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;

    // Check factors up to sqrt(num)
    int i;
    for (i = 3; i <= sqrt(num); i += 2) { // prime checking until sqrt(num), decreases complexity O(N) to O(N^1/2)
        if (num % i == 0) { 
            return 0;
        }
    }
    return 1;
}

/*
@brief Counts the number of variables in the tokens array.

@param tokens The array of tokens.

@return The number of variables found.
*/
int varCounter(char **tokens){
    int i=0;
    int varCount = 0;
    while(tokens[i] != NULL)
    {
        // if see an int, char or float variable count until encountered a ";" included variable or "}"
        if( !strcmp("int",tokens[i]) || !strcmp("char",tokens[i]) || !strcmp("float",tokens[i])) 
        {
            i++;
            varCount++;
            while(strchr(tokens[i], ';') == NULL && strchr(tokens[i], '}') == NULL)
            {
                varCount++;
                i++;
            }            
        }
        i++;
        
    }

    return varCount;
}

/*
@brief Prints the tokens in the given array.

@param tokens The array of tokens to print.
*/
void printTokens(char **tokens)
{
    int i=0;
    while(tokens[i] != NULL) // print each token
    {
        printf("%s\n", tokens[i]);
        i++;
    }
}

/*
@brief Tokenizes the given text into an array of strings.

@param text The text to tokenize.

@return A dynamically allocated array of tokens.
*/
char **tokenizer(char *text) {
    
    int capacity = 8;
    char **tokens = malloc(capacity * sizeof(char *));// Allocated memory for an array of strings (initially with 8 rows)
    if (tokens == NULL) {
        perror("Error allocating memory");
        return NULL;
    }

    int tokenCount = 0;
    
    char *token = strtok(text, ",\n\t"); // Get the first token
    while (token != NULL) {
        // Reallocate more memory if the token count exceeds capacity
        if (tokenCount >= capacity) {
            capacity *= 2;
            char **temp = realloc(tokens, capacity * sizeof(char *));
            if (temp == NULL) {
                perror("Error reallocating memory");
                free(tokens);
                return NULL;
            }
            tokens = temp;
        }

        // Allocate memory for the token string
        tokens[tokenCount] = malloc((strlen(token) + 1) * sizeof(char));
        if (tokens[tokenCount] == NULL) {
            perror("Error allocating memory for token");
            for (int i = 0; i < tokenCount; i++) {
                free(tokens[i]);
            }
            free(tokens);
            return NULL;
        }

        // Copy the token into the allocated space
        strcpy(tokens[tokenCount], token);
        tokenCount++;

        // Get the next token
        token = strtok(NULL," ,\n\t");
    }

    // Null-terminate the array of tokens
    tokens[tokenCount] = NULL;

    return tokens;
}

/*
@brief a function that reads the given text

@param exampleText the text to be read

@return the array that being read
*/
char* readFile(char* fileName)
{
    FILE *file;
    file = fopen(fileName, "r");
    char *buffer;
    unsigned int fileSize;


    if (file == NULL)
    {
        printf("Could not open file!");
        exit(-1);
    }

    fseek(file, 0, SEEK_END); // sending cursor to end of file
    fileSize = ftell(file); // assigned how many byte file has (1 byte = 1 char)
    rewind(file); // returned back to start

    buffer = (char* )malloc((fileSize + 1)); // +1 for appending NULL(\0) variable at the end
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        exit(-1);
    }
    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0'; // appended NULL variable

    fclose(file);

    return buffer;
}
