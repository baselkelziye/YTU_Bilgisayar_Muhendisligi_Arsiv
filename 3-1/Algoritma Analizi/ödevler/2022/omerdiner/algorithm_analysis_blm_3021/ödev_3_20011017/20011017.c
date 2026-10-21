#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_FILE_NAME 100
#define MAX_VAR_NAME 100
#define MAX_LINE 2000

typedef struct
{
    char name[MAX_VAR_NAME];
    char type[10];
    int isFull;
} SymbolTableElement;

typedef struct
{
    int tableSize;
    int debugMode;
    SymbolTableElement *table;
} SymbolTable;

SymbolTable *initializeSymbolTable(int tableSize);
int isPrime(int n);
int nextPrime(int n);
int h1(int key, int m);
int h2(int key, int m);
int doubleHash(int key, int i, int m);
int countDeclaredVariables(FILE *file);
int hornerRule(char *name, int m);
int insert(SymbolTable *s, char *name, char *type);
int lookup(SymbolTable *s, char *name);
void errorCheck(char *filename);
void printTable(SymbolTable *s, int varCount);
void freeSymbolTable(SymbolTable *s);

/*
@brief: checks if a number is prime
@param: num: number to be checked
@return: 1 if the number is prime, 0 if not prime
*/
int isPrime(int num)
{
    int i;
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    // Even numbers are not prime
    if (num % 2 == 0)
        return 0;

    int boundary = sqrt(num);
    for (i = 3; i <= boundary; i += 2)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

/*
@brief: finds the next prime number after n
@param: n: number to start from
@return: the first prime number bigger than n
*/
int nextPrime(int n)
{
    while (!isPrime(n))
    {
        n++;
    }
    return n;
}

/*
@brief: calculates the hash value of a string using Horner's rule
@param: name: string to be hashed
@param: n: size of the hash table
@return: string's hash value
*/
int hornerRule(char *name, int n)
{
    int i;
    int key = 0, base = 31;

    // iterating over the string and calculating the hash value
    while (*name != '\0')
    {
        char c = *name;
        key = (key * base + c) % n;
        name++;
    }

    return key;
}

/*
@brief: calculates the first hash function
@param: key: key to be hashed
@param: m: size of the hash table
@return: hash value of the key
*/
int h1(int key, int m)
{
    return key % m;
}

/*
@brief: calculates the second hash function
@param: key: key to be hashed
@param: m: size of the hash table
@return: hash value of the key
*/
int h2(int key, int m)
{
    int m2 = m - 3;
    return 1 + (key % m2);
}

/*
@brief: calculates the double hash value
@param: key: key to be hashed
@param: i: index (iteration number)
@param: m: size of the hash table
@return: double hash value of the key
*/
int doubleHash(int key, int i, int m)
{
    return (h1(key, m) + i * h2(key, m)) % m;
}

/*
@brief: initializes the symbol hash table
@param: tableSize: size of the symbol hash table
@return: a pointer to the  hashtable
*/
SymbolTable *initializeSymbolTable(int tableSize)
{
    int i;

    SymbolTable *symbolTable = malloc(sizeof(SymbolTable));
    symbolTable->table = calloc(tableSize, sizeof(SymbolTableElement));
    symbolTable->tableSize = tableSize;
    symbolTable->debugMode = 0;

    for (i = 0; i < tableSize; i++)
    {
        symbolTable->table[i].isFull = 0;
    }

    return symbolTable;
}

/*
@brief: frees the memory allocated for the symbol hash table
@param: symbolTable: pointer to the symbol hash table
*/
void freeSymbolTable(SymbolTable *symbolTable)
{
    free(symbolTable->table);
    free(symbolTable);
}

/*
@brief: inserts a new element to the symbol hash table
@param: symbolTable: pointer to the symbol hash table
@param: name: name of the variable to be inserted
@param: type: type of the variable to be inserted
@return: index of the inserted element
*/
int insert(SymbolTable *symbolTable, char *name, char *type)
{
    int i = 0;
    int key = hornerRule(name, symbolTable->tableSize);
    int initialPos = h1(key, symbolTable->tableSize);

    if (symbolTable->debugMode == 1)
        printf("\n%s icin baslangic indexi: %d\n", name, initialPos);

    while (i < symbolTable->tableSize)
    {
        int pos = doubleHash(key, i, symbolTable->tableSize);

        if (!symbolTable->table[pos].isFull)
        {
            strcpy(symbolTable->table[pos].name, name);
            strcpy(symbolTable->table[pos].type, type);
            symbolTable->table[pos].isFull = 1;
            if (symbolTable->debugMode == 1)
            {
                printf("%s degiskeni %d. indexe yerlestirildi.\n", name, pos);
            }

            return pos;
        }
        i++;
    }
    return -1;
}

/*
@brief: searches for an element in the symbol hash table
@param: symbolTable: pointer to the symbol hash table
@param: name: name of the variable to be searched
@return: index of the element if found, -1 if not found
*/
int lookup(SymbolTable *s, char *name)
{

    int key = hornerRule(name, s->tableSize);
    int i = 0;

    while (i < s->tableSize)
    {
        int searchIdx = doubleHash(key, i, s->tableSize);
        if (s->table[searchIdx].isFull == 0)
            return -1;
        if (s->table[searchIdx].isFull && strcmp(s->table[searchIdx].name, name) == 0)
            return searchIdx;
        i++;
    }
    return -1;
}

/*
@brief: prints the contents of symbol hash table
@param: s: pointer to the symbol hash table
@param: varCount: number of declared variables
*/
void printTable(SymbolTable *s, int varCount)
{
    int i;

    printf("\n\nDeklare edilen degisken sayisi: %d, Tablo boyutu: %d\n", varCount, s->tableSize);
    printf("\nTablo icerigi:\n");
    printf("Index\tName\tType\n");

    for (i = 0; i < s->tableSize; i++)
    {
        if (s->table[i].isFull == 1)
        {
            printf("%d\t%s\t%s\n", i, s->table[i].name, s->table[i].type);
        }
        else
        {
            printf("%d\t---\t---\n", i);
        }
    }
}

/*
@brief: counts the number of declared variables in a file
@param: file: pointer to the file that will be analyzed
@return: number of declared variables
*/
int countDeclaredVariables(FILE *file)
{
    int i;
    int count = 0;
    int isDeclaration = 0;
    char *dataTypes[] = {"int", "char", "float"};
    char line[MAX_LINE];
    char *token;

    rewind(file);

    // reading the file line by line
    while (fgets(line, MAX_LINE, file))
    {
        isDeclaration = 0;
        for (i = 0; i < 3; i++)
        {
            // checking if the line starts with a data type that we are looking for
            if (strstr(line, dataTypes[i]) == line)
            {
                isDeclaration = 1;
                break;
            }
        }

        if (!isDeclaration)
            continue;

        // if the line starts with a data type, counting the variables separated by commas
        line[strcspn(line, "\n")] = 0;
        char *semi = strchr(line, ';');

        if (semi)
            *semi = 0;

        // skipping the data type and getting the first variable
        token = strtok(line, " ");
        token = strtok(NULL, ",");

        while (token != NULL)
        {
            while (*token == ' ')
                token++;
            // only counting the variables that start with an "_"
            if (token[0] == '_')
            {
                count++;
            }
            token = strtok(NULL, ",");
        }
    }

    // resetting the file pointer
    rewind(file);
    return count;
}

/*
@brief: the runner function that creates the symbol table and checks for errors
@param: filename: name of the file to be analyzed
*/
void errorCheck(char *filename)
{
    int mod = 0;
    FILE *file = fopen(filename, "r");

    if (!file)
    {
        printf("Dosya acarken hata.\n");
        return;
    }

    int varCount = countDeclaredVariables(file);
    // m = first prime number that is greater than 2 * (declared variable count)
    int m = nextPrime(varCount * 2);
    SymbolTable *symbolTable = initializeSymbolTable(m);

    // taking the mode from the user and setting the debug mode accordingly
    printf("--Kontrol modlari--\n");
    printf("0-> Debug Mode\n");
    printf("1-> Normal Mode\n");
    printf("Mod giriniz: ");
    scanf("%d", &mod);

    if (mod == 0)
    {
        symbolTable->debugMode = 1;
    }

    char line[MAX_LINE];
    char *token;

    // reading the file line by line
    while (fgets(line, MAX_LINE, file))
    {
        token = strtok(line, " ,;(){\n");
        while (token)
        { // if the token is one of the data types, we get the type and the variable names
            if (strcmp(token, "int") == 0 || strcmp(token, "char") == 0 || strcmp(token, "float") == 0)
            {
                char type[10];
                strcpy(type, token);
                token = strtok(NULL, " ,;(){\n");
                // if we encounter a variable name, first we check if it is already declared in the symbol table
                // if not, we insert it to the symbol table
                while (token && token[0] == '_')
                {
                    if (lookup(symbolTable, token) != -1)
                    {
                        printf("\n%s degiskeni daha once deklare edilmistir.\n", token);
                    }
                    else
                    {
                        insert(symbolTable, token, type);
                    }

                    token = strtok(NULL, " ,;(){\n");
                }
            }
            // if the line starts with a variable name, we check if it is declared in the symbol table
            else if (token[0] == '_')
            {
                if (lookup(symbolTable, token) == -1)
                    printf("\n%s degiskeni deklare edilmemistir.", token);
            }
            token = strtok(NULL, " ,;(){\n");
        }
    }

    // if the debug mode is on, we print the symbol table
    if (symbolTable->debugMode)
    {
        printTable(symbolTable, varCount);
    }

    freeSymbolTable(symbolTable);
    fclose(file);
}

/*
@brief: main function
*/
int main()
{
    char filename[MAX_FILE_NAME];
    printf("Analiz edilecek dosyanin adini giriniz: ");
    scanf("%s", filename);

    errorCheck(filename);
    return 0;
}
