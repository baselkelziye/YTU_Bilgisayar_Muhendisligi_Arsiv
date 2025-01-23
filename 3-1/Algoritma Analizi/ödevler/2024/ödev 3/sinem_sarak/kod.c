#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


// Enum to define variable types
// Each type corresponds to a specific data type: int, float, char, long, and double
typedef enum{
    myint,
    myfloat,
    mychar,
    mylong,
    mydouble
} varType;


// Structure to represent a variable
// Each variable has a name (string) and a type (varType enum)
typedef struct{
    char name[20];
    varType type;
} myvariable;

varType determineType(const char *determineType);
void scanFile(char *filename, myvariable *hashTable, int *variableCount, int M);
void printVariable(myvariable var, int M);
int isPrime(int n);
int determineM(int variableCount);
long long getKey(char* word);
void moveToHash(int M, myvariable* hashTable, char* word, varType type);
int lookUp(int M, myvariable* hashTable, char* word);
void insert(myvariable* hashTable, char* word,int index, char* type);
void printTable(myvariable* hashTable, int M);
void processHashTable(myvariable *hashTable, char *token, char *tempType, int *variableCount, int M);

int main()
{
	int modeVar, i, variableCount = 0;
	char filename[20];
	printf("Hello. Welcome to mini variable checker. Please choose a mode: \n(1 for Normal, 2 for Debug): ");
	scanf("%d", &modeVar);
	printf("Please enter the name of your file: ");
	scanf("%s", filename);
    system("cls");
    
    scanFile(filename, NULL, &variableCount,0); // First scan: scan file to count variables (no hashTable yet)
    
    int M = determineM(variableCount); // Calculate the size of the hash table
    myvariable* hashTable = (myvariable*) calloc (M,sizeof(myvariable)); // Allocate hash table of size M
    
    variableCount = 0;  // Reset variable count for the second scan to get actual number of variables
    scanFile(filename, hashTable, &variableCount,M); // Second scan: scan and store variables in the hashTable
	
	
	 // If the mode is set to Debug, print additional information about the process
	if (modeVar == 2){
		printf("\nNumber of declared variables: %d\n", variableCount);
		printf("The size of the hashTable: %d\n", M);
		printTable(hashTable,M);
	}	
	
	free(hashTable);
    return 0;
}


/**
 * @brief Inserts a new variable into the hash table at the specified index.
 *
 * This function copies the variable name and its type into the hash table at the provided index. 
 *
 * @param hashTable The hash table to insert the variable into.
 *
 * @param word The name of the variable to insert.
 *
 * @param index The index at which to insert the variable.
 *
 * @param type The type of the variable as a string (e.g., "int", "float") which will be converted to vartype enum.
 *
 * @return
 */

void insert(myvariable* hashTable, char* word,int index, char* type){
	strcpy(hashTable[index].name, word);
	hashTable[index].type = determineType(type);
}


/**
 * @brief Looks up a word in the hashTable and checks for duplicates or empty spots.
 *
 * This function searches for the given word in the hashTable and checks for duplicates or empty spots using double hashing
 *
 * @param M The size of the hashTable.
 *
 * @param hashTable The hashTable containing variable information.
 *
 * @param word The word to search for in the hashTable.
 *
 * @return The index of an available space in the hashTable, or -1 if the word is already in the hashTable.
 */

int lookUp(int M, myvariable* hashTable, char* word){
	int i=0, m = M-3;
	long long key =getKey(word); // Get the hash key for the word
	int index = key%M;
	while(strcmp(hashTable[index].name,word) != 0 && strlen(hashTable[index].name) != 0){
		index += (key%m);
		index %= M;
	}
	
	 // If the word is found at the calculated index, it is already declared
	if(strcmp(hashTable[index].name,word) == 0){
		return -1; 
	}
	
	// If the index is empty, return the index as available
	if(strlen(hashTable[index].name) == 0){
		return index; 
	}
	
	
	
}


/**
 * @brief Generates a hash key for a given word using Horner's Method.
 *
 * This function computes a unique hash key for the input word by applying Horner's Method.
 *
 * @param word The word to be hashed.
 *
 * @return The generated hash key as a long long integer.
 */

long long getKey(char* word) {
    int i, R = 31;
    int len = strlen(word);

    long long key = 0;
    for (i = 0; i < len; i++) {
        int currLetter = (int)word[i];
        key += (long long)pow(R, len - i - 1) * currLetter;
    }
    return key;
}


/**
 * @brief Determines an appropriate prime number size for the hash table.
 *
 * This function calculates an initial value for the hash table size (m) by doubling the number of variables.
 * It then iterates until a prime number is found, which will be returned as the hash table size.
 *
 * @param variableCount The number of declared variables.
 * 
 * @return The nearest prime number greater than to variable count*2.
 */


int determineM(int variableCount){
    int m = variableCount * 2;
    
    // Increment m by 1 until a prime is found
    do
    {
        m++;
    } while (isPrime(m) == 0); // Check if m is not prime (isPrime returns 0 if not prime)

    return m;
}



/**
 * @brief Checks if a number is prime.
 *
 * This function determines if the given number n is prime by checking divisibility.
 *
 * @param n The number to be checked for primality.
 *
 * @return 1 if n is prime, 0 otherwise.
 */

int isPrime(int n){
    int i;
    
    // Check if the number is divisible by 2 or 3
    if (n%2==0 || n%3==0){
        return 0;
    }
    
	for (i=5; i*i<=n; i=i+6){
        if (n%i==0 || n%(i+2) == 0){ // Check divisibility by i or i+2 (i.e., 5 or 7, 11 or 13, etc.)
            return 0;
        }
    }
    return 1;
}



/**
 * @brief Prints the hash table.
 *
 * This function iterates through each entry of the hash table and prints its index, name, type,
 * and the original index of the variable which calculated using Horner's Method and double hashing.
 *
 * @param hashTable The hash table to print.
 
 * @param M The size of the hash table.
 *
 * @return
 */
 
void printTable(myvariable* hashTable, int M){
	int i;
	printf("\n*****************************************************************\n");
	printf("\t\t\tHash Table\n*****************************************************************\n\n");
	for(i=0;i<M;i++){
    	printf("hashTable[%d]:\t", i);
    	if(strlen(hashTable[i].name) == 0){  // Checks if the hashTable[i] is empty
    		printf(" is empty.");
		}else{
			printVariable(hashTable[i],M);
		}
		printf("\n----------------------------------------------------------------------\n");

	}
}


/**
 * @brief Prints the details of a single variable stored in the hash table.
 *
 * This function prints the name and type of the variable, followed by its calculated using Horner's Method and double hashin.
 *
 * @param var The variable to print, a `myvariable` structure.
 *
 * @param M The size of the hash table.
 *
 * @return
 */

void printVariable(myvariable var, int M){
        printf("Name: %s \t Type: ", var.name);
        switch (var.type){
        case myint:
            printf("int");
            break;
        case myfloat:
            printf("float");
            break;
        case mychar:
            printf("char");
            break;
        case mylong:
            printf("long");
            break;
        case mydouble:
            printf("double");
            break;
        default: // Normally, this should not be triggered since the type of a variable is a predefined enum.
            printf("An error occured..\n"); 
    }
     printf("\tCalculated key value: %d", getKey(var.name)%M); // Prints the original key value.
}


/**
 * @brief Determines the type of a variable based on its declaration in the .c file.
 *
 * This function checks the string `tempType` and returns the corresponding `varType` enumeration value.
 * It handles types like "int", "float", "char", "long", and "double". If the type name doesn't match any of these,
 * it returns `-1` to indicate that the line which tempType is in, is not a declaration line.
 *
 * @param tempType The type name as a string (e.g., "int", "float").
 *
 * @return The corresponding `varType` value, or `-1` if the line is not a declaration
 */

varType determineType(const char *tempType){
    if (strcmp(tempType, "int") == 0){
        return myint;
    }
    else if (strcmp(tempType, "float") == 0){
        return myfloat;
    }
    else if (strcmp(tempType, "char") == 0){
        return mychar;
    }
    else if (strcmp(tempType, "long") == 0){
        return mylong;
    }
    else if (strcmp(tempType, "double") == 0){
        return mydouble;
    }
    return -1; //reserved keyword or another variable.
}





/**
 *  @brief Scans a given .c file to detect and handle variable declarations and usages.
 *
 * This function reads a .c file line by line, looking for variable declarations and usages. 
 * It identifies variable names starting with '_' and determines whether 
 * they are declared or used without prior declaration. It updates a hash table or simply 
 * counts variables depending on whether a hashTable is provided.
 *
 * @param filename The name of the .c file.
 *
 * @param hashTable The hash table storing variable information.
 *  	If NULL, the function only counts variables for determining the size of the hash table.
 *
 * @param variableCount Pointer to the number of declared variables. 
 * 		
 * @param M The size of the hash table. Ignored if hashTable is NULL.
 * 
 * @return 
 */
 
void scanFile(char *filename, myvariable *hashTable, int *variableCount, int M) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File couldn't open, terminating program..");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        
        if (strchr(line, '_')){  // Check if the line contains an '_'. Skip the line if it doesn't

	        char *token = strtok(line, " ()=\t\n;");
	        char tempType[20] = "";
	        int index;
	
	        if (token){
	        	strcpy(tempType, token); // If a '_' is detected in line, consider the first word in the line as a potential variable type
			} 
	
	        while (token) {
	            if (token[0] == '_') {
	            	// Check if the token starts with a '_' to see if it is a variable
	                if (hashTable) {
	                	// If hashTable is not NULL, process the token for insertion or error detection
	                    processHashTable(hashTable, token, tempType, variableCount, M);
	                } else if (determineType(tempType) != -1) {
	                	// If hashTable is NULL and the type is valid, count number of declarations
	                    (*variableCount)++;
	                }
	            }
	            token = strtok(NULL, " =+\t\n,;");
	        }
   		 }
	}
    fclose(file);
}


/**
 * @brief Processes a variable token to check for declaration or usage errors in the hash table.
 *
 * This function determines whether a given token represents a variable declaration or usage, 
 * then updates the hash table or detects errors such as duplicate declarations or usage without declaration.
 *
 * @param hashTable A pointer to the hash table where variable information is stored.
 *
 * @param token The current variable being processed
 *
 * @param tempType The type associated with the token (e.g., "int", "float")
 
 * @param variableCount Pointer to the number of declared variables.
 
 * @param M The size of the hash table.
 *
 * @return void
 */


void processHashTable(myvariable *hashTable, char *token, char *tempType, int *variableCount, int M) {
    int index = lookUp(M, hashTable, token) ;
    
    if (determineType(tempType) != -1) { 
	// If valid type detected then it must be a declaration, else it is a usage like if(_bb == 0) etc.
        if (index == -1) {
        	// Duplicate declaration detected, warn user
            printf("The variable %s is defined twice\n", token);
        } else {
        	// Insert new variable into hash table
            insert(hashTable, token, index, tempType);
            (*variableCount)++;
        }
        
        
    } else {
    	//usage of a variable detected. check if valid. If is not, warn user
        if ( index!= -1) {
        	// Variable used without declaration
            printf("Usage without definition of: %s\n", token);
        }
    }
}
