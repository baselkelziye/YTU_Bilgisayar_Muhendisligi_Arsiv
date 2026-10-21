#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define R 31

typedef struct node{
	char* name;
	char type[6];
}NODE;

typedef struct map{
	int m; //table size
	int n; //the number of pairs currently in the map
	NODE *hashMap; 
}MAP;

int findN(char** lines, int totalLines);
int isPrime(int num);
int findNextPrime(int num);
MAP* createHashMap(int m);
void freeMap(MAP* map);
void insert(MAP* map, char* name, char* type);
int lookup(MAP* map, char* name);
int hashFunction(char* name, int m);
char* readTheCodeFromFile();
char** tokenizeTheCodeIntoLines(char* codeFileAsTxt, int* totalLines);
void compileTheCode(char** lines, int totalLines);
void compileLine(char* line, int lineNo, MAP* map);
int isDelimiter(char* DELIMITERS, char c);
char customStrtok(char* tokenBuffer, char** p, char* DELIMITERS);
void skipWhiteSpaces(char** p);
int isDeclarationKeyword(char *token);
int isAnotherKeyword(char *token);
int isNum(char* token);
int isValidVariable(char *token);
void printMap(MAP* map);

int main(){
	int totalLines = 0, i;
	char* codeFileAsTxt = readTheCodeFromFile();
	char** lines = tokenizeTheCodeIntoLines(codeFileAsTxt, &totalLines);
	
	compileTheCode(lines, totalLines);
	
	for(i=0;i<totalLines;i++){ //freeing the array of strings that stores each line
		free(lines[i]);	
	}
	free(lines);
	
	return 0;
}

/*
@brief it creates the map and asks the user the mode and call compileLine for each line. at the end, prints the map if selected mode is debug. 

@param lines: array of strings, each one is a line that ends with ";".
@param totalLines: the number of lines in the code.

@return
*/

void compileTheCode(char** lines, int totalLines){
	int m = findNextPrime(2 * findN(lines, totalLines)); //after counting the number of variables that may be declared with findN, we find m
	MAP* map = createHashMap(m);
	int mode, i;
	do{
		printf("enter 1 to run in debug mode...\nenter 0 to run in normal mode...\nmode: ");
		scanf("%d", &mode);	
	} while(mode != 0 && mode != 1);
	
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	
    for(i=0;i<totalLines;i++){ //calling compileLine for each line
        compileLine(lines[i], i + 1, map);
    }
    
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");

    if(mode) printMap(map); //printing the map and infos if selected mode is debug

	freeMap(map);
}

/*
@brief it checks if c is a delimiter in the DELIMITERS string by using strchr. 

@param DELIMITERS: a string that stores the wanted delimiters.
@param c: a char that may be a delimiter.

@return 1 if c is delimiter, 0 if not
*/

int isDelimiter(char* DELIMITERS, char c){
    return strchr(DELIMITERS, c) != NULL;
}

/*
@brief it iterates over the line via p until it sees a delimiter and copies the chars to tokenBuffer while iterating. 

@param tokenBuffer: a string that will store the current token.
@param p: pointer to the pointer of the current char of the line.
@param DELIMITERS: a string that stores the wanted delimiters.

@return the delimiter
*/

char customStrtok(char* tokenBuffer, char** p, char* DELIMITERS){
	int tokenLen = 0;
    while (**p && !isDelimiter(DELIMITERS, **p)){
        tokenBuffer[tokenLen++] = **p;
        (*p)++;
    }
    
	tokenBuffer[tokenLen] = '\0';
	char delimiter = **p;
	if(**p) (*p)++;	
	return delimiter;
}

/*
@brief it iterates over the line via p until it sees a char which is not '\n', '\t' or ' ' to eliminate spaces. 

@param p: pointer to the pointer of the current char of the line.

@return 
*/

void skipWhiteSpaces(char** p){
	while(**p && isspace(**p)){
        (*p)++;
    }
}

/*
@brief compiles the input line according to rules and gives erros if needed. 

@param line: a line. (I seperated the code into lines by ';').
@param lineNo: the number of the line.
@param map: pointer to the map.

@return 
*/

void compileLine(char* line, int lineNo, MAP* map){
	if(line == NULL) return; 
	int ctrl = 1, canBeDeclared = 1; //ctrl will be used if there is a big error and stop compiling this line, canBeDeclared will be used to 
	//check if there is an assign in declaration line (=)
	char type[6], DELIMITERS[20] = " \t\n,=()<>+-*/%", delimiter; //DELIMITERS will be used to tokenize the line
	char* tokenBuffer = (char*) malloc(256 * sizeof(char)); //it will be used to store the current token while tokenizing
	char *p = line, *token; //p will be used to iterate over the line
	
	skipWhiteSpaces(&p);
	delimiter = customStrtok(tokenBuffer, &p, DELIMITERS); //getting the first token of the line and the delimiter
	token = tokenBuffer;
	
    if(isDeclarationKeyword(token)){ //if the first token is a declaration keyword then we enter this block
    	strcpy(type, token); //copying the first token to type
    	while(ctrl && *p){ //iterate until the line ends
    		skipWhiteSpaces(&p); //skipping the white spaces until the next token or delimiter
    		delimiter = customStrtok(tokenBuffer, &p, DELIMITERS); //getting the delimiter and the token
    		token = tokenBuffer;
			if(isValidVariable(token)){ //if variable name is valid, then we can try to declare
				if(canBeDeclared){ //if token comes after ',' then we can check the map to declare it
					if(!lookup(map, token)){ //if it is not declared before we can declare it
	    				printf("Line %d -> variable %s can be declared...\n", lineNo, token); //I was not sure to print that it can be declared...
	    				insert(map, token, type);
					}
					else{ //if it is declared before we can give an error
						printf("Line %d -> ERROR: variable %s was declared before!\n", lineNo, token);
					}
				}
				else{ //if token doesnt come after ',' then it means it comes after '=' or other arithmetic operators so we should
				//look at if it is declared before
					if(!lookup(map, token)){ //if it is not declared before than we should give an error
	    				printf("Line %d -> ERROR: variable %s was used but was not declared!\n", lineNo, token);
					}
				}
			}
			else if(isDeclarationKeyword(token)){ //if we see a declaration keyword again at the same line then we should stop compiling 
			//this line. GCC does like this too (ex -> char a, b, int b;) 
				printf("Line %d -> ERROR: expected identifier like ';' or '(' before declaration keyword %s!\n", lineNo, token);
				ctrl = 0;
			}
			else if(!isNum(token) && !isAnotherKeyword(token)){ //if token is not a number or another keyword like for, if, while, then this is an 
			//invalid variable name
				printf("Line %d -> ERROR: variable name %s is invalid!\n", lineNo, token);
			}
			if(delimiter == ','){ //if delimiter we get from customStrtok is ',' then we can try to declare the next token 
        		canBeDeclared = 1;
			}
        	else if(delimiter == '='){ //if delimiter we get from customStrtok is '=' then we shouldnt declare the variables until we see ','
        		canBeDeclared = 0;
			}
		}
	}
	else{ //if the first token is not a declaration keyword then we enter this block, this is not a declaration line
		while((token[0] != '\0' || *p != '\0') && ctrl){ //iterates until both the line is ended and token gets null char
			if(isValidVariable(token)){ //if it valid variable name then we can check if it is declared before
    			if(!lookup(map, token)){ //if it is not declare before we should give error
    				printf("Line %d -> ERROR: variable %s was used but was not declared!\n", lineNo, token);
				}
			}
			else if(isDeclarationKeyword(token)){ //if we see a declaration keyword then we should stop compiling this line
				printf("Line %d -> ERROR: expectecd identifier like ';' or '(' before %s!\n", lineNo, token);
				ctrl = 0;
			}
			else if(!isNum(token) && !isAnotherKeyword(token)){ //if token is not a number or another keyword like for, if, while, then this is an 
			//invalid variable name
				printf("Line %d -> ERROR: unknown variable type '%s'\n", lineNo, token);
			}
			
			skipWhiteSpaces(&p);
			customStrtok(tokenBuffer, &p, DELIMITERS); //getting the token (delimiter is not important for a this line since it is not
			// a declaration line)
			token = tokenBuffer;
		}
	}
	
	free(tokenBuffer);
}

/*
@brief checks if the token is valid. 

@param token: a string we get between two delimiters.

@return 1 if it is valid, 0 if not
*/

int isValidVariable(char *token){
	if(token[0] != '_') return 0;
	int i, n = strlen(token);
	for(i=1;i<n;i++){
		if(!isalnum(token[i]) && token[i] != '_') return 0;
	}
	return 1;
}

/*
@brief checks if the token is number. 

@param token: a string we get between two delimiters.

@return 1 if it is number, 0 if not
*/

int isNum(char* token){
	int i, n = strlen(token);
	for(i=0;i<n;i++){
		if(!isdigit(token[i])) return 0;
	}
	return 1;
}

/*
@brief checks if the token is another keyword. 

@param token: a string we get between two delimiters.

@return 1 if it is keyword, 0 if not
*/

int isAnotherKeyword(char *token){
	return strcmp(token, "for") == 0 || strcmp(token, "do") == 0 || strcmp(token, "while") == 0 || strcmp(token, "if") == 0;
}

/*
@brief checks if the token is a declaration keyword. 

@param token: a string we get between two delimiters.

@return 1 if it is keyword, 0 if not
*/

int isDeclarationKeyword(char *token){
    return strcmp(token, "int") == 0 || strcmp(token, "char") == 0 || strcmp(token, "float") == 0;
}

/*
@brief reads the file to a string and returns it. 

@return the file as a string
*/

char* readTheCodeFromFile(){
	char filename[20];
	printf("file name: ");
	scanf("%s", filename);
	
	FILE *file = fopen(filename, "r");
	
    if (file == NULL) {
        printf("Error opening file");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    
    char *codeFileAsTxt = (char*) malloc((fileSize + 1) * sizeof(char));
    if (codeFileAsTxt == NULL) {
        printf("Memory allocation failed");
        fclose(file);
        exit(1);
    }
    
    size_t bytesRead = fread(codeFileAsTxt, 1, fileSize, file);
    fclose(file);
    codeFileAsTxt[bytesRead] = '\0';
    
    return codeFileAsTxt;
}

/*
@brief it seperates the input string into lines by tokenizing. 

@param codeFileAsTxt: all the input file as string.
@param totalLines: pointer to the int that will store the number of lines in the codeFileAsTxt (we calculate it here while seperating).

@return array of strings that stores each line
*/

char** tokenizeTheCodeIntoLines(char* codeFileAsTxt, int* totalLines){
	char* copyCode = (char*) malloc((strlen(codeFileAsTxt) + 1) * sizeof(char));
	strcpy(copyCode, codeFileAsTxt);
	char* token = strtok(copyCode, ";{}");
	while (token != NULL){
        (*totalLines)++;
        token = strtok(NULL, ";{}");
    }
    
    free(copyCode);
    
    (*totalLines)--;
    char** lines = (char**) malloc(*totalLines * sizeof(char*)); //skip the main
    
    token = strtok(codeFileAsTxt, ";{}");
    int i = 0;
    while (i < *totalLines && (token = strtok(NULL, ";{}")) != NULL){
		lines[i] = (char*) malloc((strlen(token) + 1) * sizeof(char));
		strcpy(lines[i], token);
		i++;	
    }
    
    return lines;
}

/*
@brief it counts the number of variables that may be declared. 

@param lines: array of strings that stores each line.
@param totalLines: the number of lines.

@return the number of variables
*/

int findN(char** lines, int totalLines){
	int ctrl, canBeDeclared, count = 0, i;
	char DELIMITERS[20] = " \t\n,=()<>+-*/%", delimiter;
	char* tokenBuffer = (char*) malloc(256 * sizeof(char));
	char *p, *token;
	for(i=0;i<totalLines;i++){
		p = lines[i];	
		ctrl = 1, canBeDeclared = 1;
		skipWhiteSpaces(&p);
		delimiter = customStrtok(tokenBuffer, &p, DELIMITERS);
		token = tokenBuffer;
	    if(isDeclarationKeyword(token)){
	    	while(ctrl && *p){
	    		skipWhiteSpaces(&p);
	    		delimiter = customStrtok(tokenBuffer, &p, DELIMITERS);
	    		token = tokenBuffer;
				if(isValidVariable(token) && canBeDeclared){
					count++;
				}
				else if(isDeclarationKeyword(token)){
					ctrl = 0;
				}
				if(delimiter == ','){
	        		canBeDeclared = 1;
				}
	        	else if(delimiter == '='){
	        		canBeDeclared = 0;
				}
			}
		}
	}

	free(tokenBuffer);
	
	return count;
}

/*
@brief finds the prime that is bigger than num. 

@param num: integer

@return found prime
*/

int findNextPrime(int num){
	int p = num + 1;
	
	while(!isPrime(p)){
		p++;
	};
	
	return p;
}

/*
@brief checks if num is prime. 

@param num: integer

@return 1 if it is prime, 0 if not
*/

int isPrime(int num){
	int temp = sqrt(num), i;
	
	for(i=2;i<=temp;i++){
		if(num % i == 0) return 0;
	}
	
    return 1;
}

/*
@brief creates the map. 

@param m: size of the table

@return created map
*/

MAP* createHashMap(int m){
	MAP* map = (MAP*) calloc(1, sizeof(MAP));
	map->m = m;
	map->n = 0;
	map->hashMap = (NODE*) calloc(m, sizeof(NODE));
	return map;
}

/*
@brief it uses horner method and calculates the hash. 

@param name: key of which this will calculate hash
@param m: size of the table

@return hash value
*/

int hashFunction(char* name, int m){
	int i, L = strlen(name);
	int hash = 0;
	
	//taking mod in each iter doesnt change the resulted hash value, we could take it at the end but we need to use long long to store hash
	//and also multiyplying big numbers slows the process.
	for(i=0;i<L;i++){
		hash = (hash * R + name[i]) % m;
	}
	
	return hash;
}

/*
@brief it searches at the map with double hashing looking for name. 

@param map: pointer to the map
@param name: key of which we will look if it is in the map

@return 1 if it is found, 0 if not
*/

int lookup(MAP* map, char* name){
	int h1 = hashFunction(name, map->m);
	int h2 = 1 + hashFunction(name, map->m - 3);
	int i = 0, slot = h1;
	
	while(i < map->m && map->hashMap[slot].name != NULL){ //if there is an empty slot while doing probing, then key cannot be in the map
		if(!strcmp(map->hashMap[slot].name, name)) return 1;
		i++;
		slot = (h1 + i * h2) % map->m; //doing probing
	};
	
	return 0;
}

/*
@brief it inserts to the map with double hashing. 

@param map: pointer to the map
@param name: key we will insert to the map
@param type: value

@return
*/

void insert(MAP* map, char* name, char* type){
	int h1 = hashFunction(name, map->m);
	int h2 = 1 + hashFunction(name, map->m - 3);
	int i = 0, slot = h1;
	
	//it is assumed that lookup function is called before insert function so this loop doesnt check whether there is a variable added before
	while(i < map->m && map->hashMap[slot].name != NULL){
		i++;
		slot = (h1 + i * h2) % map->m;
	};
	
	map->hashMap[slot].name = (char*) malloc((strlen(name) + 1) * sizeof(char));
	strcpy(map->hashMap[slot].name, name);
	strcpy(map->hashMap[slot].type, type);
	map->n++;
}

/*
@brief frees the map. 

@param map: pointer to the map

@return
*/

void freeMap(MAP* map){
	int i;
	
	for(i=0;i<map->m;i++){
		free(map->hashMap[i].name);
	}
	
	free(map->hashMap);
	free(map);
}

/*
@brief prints the map. 

@param map: pointer to the map

@return
*/

void printMap(MAP* map){
	int i, h1, h2, probes;
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("n (declared variables): %d - m (table size): %d - load factor: %.2lf", map->n, map->m, (double)map->n / map->m);
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<map->m;i++){
		if(map->hashMap[i].name == NULL){
			printf("%d -> Empty\n", i);
		}
		else{
			h1 = hashFunction(map->hashMap[i].name, map->m);
			h2 = 1 + hashFunction(map->hashMap[i].name, map->m - 3);
			probes = (i < h1) ? map->m - h1 + i : i - h1;
			probes = (probes / h2) + 1;
			printf("%d -> (%s, %s) - first address (h1): %d - probe step size (h2): %d - actual address: %d - the number of probes: %d\n", 
			i, map->hashMap[i].name, map->hashMap[i].type, h1, h2, i, probes);	
		}
	}
	printf("\n------------------------------------------------------------------------------------------------------------------------\n\n");
}
