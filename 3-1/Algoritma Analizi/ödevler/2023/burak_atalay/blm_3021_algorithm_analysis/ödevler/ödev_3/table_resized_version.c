#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define R 31
#define M 7 //initial m

typedef struct node{
	char* name;
	char type[6];
}NODE;

typedef struct map{
	int m; //table size
	int n; //the number of pairs currently in the map
	NODE *hashMap; 
}MAP;

int isPrime(int num);
int findNextPrime(int num);
MAP* createHashMap(int m);
MAP* resizeMap(MAP* map);
void freeMap(MAP* map);
void insert(MAP** map, char* name, char* type);
int lookup(MAP* map, char* name);
int hashFunction(char* name, int m);
char* readTheCodeFromFile();
char** tokenizeTheCodeIntoLines(char* codeFileAsTxt, int* totalLines);
void compileTheCode(char** lines, int totalLines);
void compileLine(char* line, MAP** map);
int isDelimiter(char* DELIMITERS, char c);
char customStrtok(char* tokenBuffer, char** p, char* DELIMITERS);
void skipWhiteSpaces(char** p);
int isDeclarationKeyword(char *token);
int isAnotherKeyword(char *token);
int isNum(char* token);
int isValidVariable(char *token);
void printMap(MAP* map);
char* trimLeadingSpaces(char* str);
char* trimTrailingSpaces(char* str);

int main(){
	int totalLines = 0;
	char* codeFileAsTxt = readTheCodeFromFile();
	printf("%s\n", codeFileAsTxt);
	char** lines = tokenizeTheCodeIntoLines(codeFileAsTxt, &totalLines);
	printf("%d\n", totalLines);
	int i;
	for(i=0;i<totalLines;i++){
		printf("%d: %s\n", i + 1, lines[i]);
	}
	
	compileTheCode(lines, totalLines);
	
	for(i=0;i<totalLines;i++){
		free(lines[i]);	
	}
	free(lines);
	
	return 0;
}

void compileTheCode(char** lines, int totalLines){
	MAP* map = createHashMap(M);
	int mode, i;
	do{
		printf("enter 1 to run in debug mode enter 0 to run in normal mode: ");
		scanf("%d", &mode);	
	} while(mode != 0 && mode != 1);
	
	
    for(i=0;i<totalLines;i++){
        compileLine(lines[i], &map);
    }
    
    if(mode) printMap(map);

	freeMap(map);
}

int isDelimiter(char* DELIMITERS, char c){
    return (c == '\0' || strchr(DELIMITERS, c) != NULL);
}

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

void skipWhiteSpaces(char** p){
	while(**p && isspace(**p)){
        (*p)++;
    }
}

void compileLine(char* line, MAP** map){
	if(line == NULL) return;
	int ctrl = 1, canBeDeclared = 1, tokenLen;
	char type[6], DELIMITERS[20] = " \t\n,=()<>+*/%", delimiter;
	char* tokenBuffer = (char*) malloc(256 * sizeof(char));;
	
	char *p = line, *token;
	
	skipWhiteSpaces(&p);
	delimiter = customStrtok(tokenBuffer, &p, DELIMITERS);
	token = tokenBuffer;
    if(isDeclarationKeyword(token)){
    	strcpy(type, token);
    	while(ctrl && *p){
    		skipWhiteSpaces(&p);
    		delimiter = customStrtok(tokenBuffer, &p, DELIMITERS);
    		token = tokenBuffer;
    		//printf("%s\n", token);
			if(isValidVariable(token)){
				if(canBeDeclared){
					if(!lookup(*map, token)){
	    				printf("variable %s can be declared...\n", token);
	    				insert(map, token, type);
					}
					else{
						printf("ERROR: variable %s was declared before!\n", token);
					}
				}
				else{
					if(!lookup(*map, token)){
	    				printf("Error: variable %s was used but was not declared!\n", token);
					}else printf("else %s\n", token);
				}
			}
			else if(isDeclarationKeyword(token)){
				printf("ERROR: expected identifier like ';' or '(' before declaration keyword %s!\n", token);
				ctrl = 0;
			}
			else if(!isNum(token) && !isAnotherKeyword(token)){
				printf("ERROR: variable name %s is invalid!\n", token);
			}
			if(delimiter == ','){
        		canBeDeclared = 1;
			}
        	else if(delimiter == '='){
        		canBeDeclared = 0;
			}
		}
	}
	else{
		while(token[0] != '\0' && ctrl){
			//printf("2: %s\n", token);
			if(isValidVariable(token)){
    			if(!lookup(*map, token)){
    				printf("Error: variable %s was used but was not declared!\n", token);
				}
			}
			else if(isDeclarationKeyword(token)){
				printf("ERROR: expected identifier like ';' or '(' before %s!\n", token);
				ctrl = 0;
			}
			else if(!isNum(token) && !isAnotherKeyword(token)){
				printf("ERROR: unknown variable type '%s'\n", token);
			}
			skipWhiteSpaces(&p);
			customStrtok(tokenBuffer, &p, DELIMITERS);
			token = tokenBuffer;
		}
	}
	
	free(tokenBuffer);
}

char* trimLeadingSpaces(char* str){
    while (isspace(*str)) str++;
    return str;
}

char* trimTrailingSpaces(char* str){
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)){
        *end = '\0';
        end--;
    }
    return str;
}

int isValidVariable(char *token){
	if(token[0] != '_') return 0;
	int i, n = strlen(token);
	for(i=1;i<n;i++){
		if(!isalnum(token[i]) && token[i] != '_') return 0;
	}
	return 1;
}

int isNum(char* token){
	int i, n = strlen(token);
	for(i=0;i<n;i++){
		if(!isdigit(token[i])) return 0;
	}
	return 1;
}

int isAnotherKeyword(char *token){
	return strcmp(token, "for") == 0 || strcmp(token, "do") == 0 || strcmp(token, "while") == 0 || strcmp(token, "if") == 0;
}

int isDeclarationKeyword(char *token){
    return strcmp(token, "int") == 0 || strcmp(token, "char") == 0 || strcmp(token, "float") == 0;
}

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

char** tokenizeTheCodeIntoLines(char* codeFileAsTxt, int* totalLines){
	char* copyCode = (char*) malloc((strlen(codeFileAsTxt) + 1) * sizeof(char));
	strcpy(copyCode, codeFileAsTxt);
	char* token = strtok(copyCode, ";{}");
	while (token != NULL){
		token = trimLeadingSpaces(token);
		token = trimTrailingSpaces(token);
        if(strlen(token) > 0) (*totalLines)++;
        token = strtok(NULL, ";{}");
    }
    
    free(copyCode);
    
    (*totalLines)--;
    char** lines = (char**) malloc(*totalLines * sizeof(char*)); //skip the main
    
    token = strtok(codeFileAsTxt, ";{}");
    int i = 0;
    while (i < *totalLines && (token = strtok(NULL, ";{}")) != NULL){
    	token = trimLeadingSpaces(token);
    	token = trimTrailingSpaces(token);
    	if(strlen(token) > 0) {
    		lines[i] = (char*) malloc((strlen(token) + 1) * sizeof(char));
    		strcpy(lines[i], token);
			i++;	
		}
    }
    
    return lines;
}

int findNextPrime(int num){
	int p = num + 1;
	
	while(!isPrime(p)){
		p++;
	};
	
	return p;
}

int isPrime(int num){
	int temp = sqrt(num), i;
	
	for(i=2;i<=temp;i++){
		if(num % i == 0) return 0;
	}
	
    return 1;
}

MAP* createHashMap(int m){
	MAP* map = (MAP*) calloc(1, sizeof(MAP));
	map->m = m;
	map->n = 0;
	map->hashMap = (NODE*) calloc(m, sizeof(NODE));
	return map;
}

int hashFunction(char* name, int m){
	int i, L = strlen(name);
	int hash = 0;
	
	for(i=0;i<L;i++){
		hash = ((hash * R) % m + name[i]) % m;
	}
	
	return hash;
}

int lookup(MAP* map, char* name){
	int h1 = hashFunction(name, map->m);
	int h2 = hashFunction(name, map->m - 3);
	int i = 0, slot = h1;
	
	while(i < map->m && map->hashMap[slot].name != NULL){ //if there is an empty slot while doing probing, then key cannot be in the map
		if(!strcmp(map->hashMap[slot].name, name)) return 1;
		i++;
		slot = (h1 + i * h2) % map->m;
	};
	
	return 0;
}

void insert(MAP** map, char* name, char* type){
	int h1 = hashFunction(name, (*map)->m);
	int h2 = hashFunction(name, (*map)->m - 3);
	int i = 0, slot = h1;
	
	//it is assumed that lookup function is called before insert function so this loop doesnt check whether there is a variable added before
	while(i < (*map)->m && (*map)->hashMap[slot].name != NULL){
		i++;
		slot = (h1 + i * h2) % (*map)->m;
	};
	
	(*map)->hashMap[slot].name = (char*) malloc((strlen(name) + 1) * sizeof(char));
	strcpy((*map)->hashMap[slot].name, name);
	strcpy((*map)->hashMap[slot].type, type);
	(*map)->n++;
	double load_factor = (double)(*map)->n / (*map)->m;
	if(load_factor >= 0.6) *map = resizeMap(*map);
	//printf("name: %s, probs: %d, m: %d, n: %d, hash: %d, load_factor: %lf\n", name, i, (*map)->m, (*map)->n, h1, load_factor);
}

MAP* resizeMap(MAP* map){ //resizing the map if load factor becomes exceeds 0.7 since complexity for each operation would be high wihcih is 1 /(1-load_factor)
	//printf("resizing... m: %d\n", map->m);
	int i, newSize = findNextPrime(map->m * 2); //doubled the size and also selected the smallest prime bigger than that number
	MAP* newMap = createHashMap(newSize);
	
	for(i=0;i<map->m;i++){
		if(map->hashMap[i].name != NULL){ //if slot is not empty or deleted
			insert(&newMap, map->hashMap[i].name, map->hashMap[i].type);	
		}
	}
	freeMap(map);
	return newMap;
}

void freeMap(MAP* map){
	int i;
	
	for(i=0;i<map->m;i++){
		free(map->hashMap[i].name);
	}
	
	free(map->hashMap);
	free(map);
}

void printMap(MAP* map){
	int i, h1, h2, probes;
	printf("\nn: %d, m: %d, load_factor: %lf\n", map->n, map->m, (double)map->n / map->m);
	for(i=0;i<map->m;i++){
		if(map->hashMap[i].name == NULL){
			printf("%d -> Empty\n", i);
		}
		else{
			h1 = hashFunction(map->hashMap[i].name, map->m);
			h2 = hashFunction(map->hashMap[i].name, map->m - 3);
			probes = (i < h1) ? map->m - h1 + i : i - h1;
			probes = (probes / h2) + 1; 
			printf("%d -> (%s, %s) - first address: %d, probe step size (h2): %d, actual address: %d, the number of probes: %d\n", 
			i, map->hashMap[i].name, map->hashMap[i].type, h1, h2, i, probes);	
		}
	}
	printf("\n------------------------------------------------------------\n\n");
}
