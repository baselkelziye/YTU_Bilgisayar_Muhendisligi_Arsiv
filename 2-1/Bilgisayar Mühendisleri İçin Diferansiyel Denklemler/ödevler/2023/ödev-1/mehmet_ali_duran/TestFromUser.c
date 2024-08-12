#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAX_WORD 9000
#define WORD_LENGTH 30
#define LINE_LENGTH 1000
#define LEARNING_RATE 0.08
#define EPOCHS 100

void deleteChar(char *str, int index);
void toLowerCase(char *str);
void deleteApostrophe(char text[]);
void freeMemoryChar(char **matrix, int row);
void freeMemoryInt(int **matrix, int row);
void deletePuncAndNumbers(int len, char *line);
void trim(char *str);
void splitWords(char **dictionary, int *hotVector, int *wordsCounter, char *line,char *splittedWord);
int searchWord(char *word, char *dictionary[], int len);
char** allocateMemoryChar(int row, int column);
double tanh(double x);
double dotProduct(double* a, int* b, int size);
int getTrueOutput(int label) {
    return label;
}
int guessNewsCategory(double *weights, int wordsCounter, int *hotVector);

int main() {

    int i, j, flag, len, wordsCounter=0, valueCount = 0, guess;
    int *hotVector;
    double *weights;
    double currentValue;
    char line[LINE_LENGTH];
    char *splittedWord;
    char **dictionary;
    char currentWord[WORD_LENGTH];
    FILE *testFile, *dictionaryFile, *hotVectorFile, *weightsFile;

    //ekonomi 1, spor -1;


    dictionary = allocateMemoryChar(MAX_WORD, WORD_LENGTH);    
    dictionaryFile = fopen("kelimeler.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Dosya açma hatası!\n");
        return 1;
    }
    
    while (EOF != fscanf(dictionaryFile, "%[^\n]\n", currentWord)) {
        dictionary[wordsCounter++]=strdup(currentWord); 
    }

    fclose(dictionaryFile);

    weights = (double*)calloc(wordsCounter,sizeof(double));
    
    weightsFile=fopen("weights0.txt","r");
    while (fscanf(weightsFile, "%lf", &currentValue) == 1 && valueCount < wordsCounter) {
        weights[valueCount++] = currentValue;
    }
    fclose(weightsFile);

    hotVector=(int*) calloc(wordsCounter,sizeof(int));
    
    for(i=0;i<wordsCounter;i++)
        hotVector[i]=0;

    
    testFile = fopen("C:\\Users\\mehme\\dif\\test.txt", "r");
    if (testFile == NULL) {

        perror("dosya acilamadi");
        return 1;
    }

    while(fgets(line, sizeof(line), testFile) != NULL) {
        
        flag=0;
        
        if (strspn(line, " \t\n") == strlen(line))
            flag=1;
            
        if(flag!=1){
            trim(line);
            toLowerCase(line);
            deleteApostrophe(line);
            len = strlen(line);
            deletePuncAndNumbers(len, line);
            splitWords(dictionary, hotVector, &wordsCounter, line, splittedWord);
        }
    }

    guess = guessNewsCategory(weights, wordsCounter, hotVector);
    // if(guess==1) printf("Girdiginiz metnin kategorisi ekonomi");
    // else if(guess==-1)printf("Girdiginiz metnin kategorisi spor");
    guess == 1 ? printf("Girdiginiz metnin kategorisi ekonomi") : printf("Girdiginiz metnin kategorisi spor");
	freeMemoryChar(dictionary,MAX_WORD);
    free(weights);
    free(hotVector);
	
    return 0;
}

void freeMemoryChar(char **matrix, int row){
	int i;
	for(i=0;i<row;i++){
    	free(matrix[i]);
	}
	free(matrix);
}


void deleteChar(char *str, int index) {
    int len = strlen(str);

    if (index < 0 || index >= len) {
        printf("Hata: Gecersiz indeks\n");
        return;
    }

    //memmove(str + index, str + index + 1, len - index);
	*(str+index)=' ';
    //str[len - 1] = '\0';
}

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}


void deleteApostrophe(char text[]) {
    char *baslangic = strstr(text, "'");
    char *bitis;

    while (baslangic != NULL) {
        bitis = baslangic + 1;

        while (*bitis != ' ' && *bitis != '\0') {
            bitis++;
        }

        memmove(baslangic, bitis, strlen(bitis) + 1);

        if (isspace(text[baslangic - text - 1])) {
            memmove(baslangic - 1, baslangic, strlen(baslangic) + 1);
        }

        baslangic = strstr(baslangic + 1, "'");
    }
}

void deletePuncAndNumbers(int len, char *line){
    int flag, i;
    for (i = 0; i < len; i++){
        flag=0;

        if(isdigit(line[i]))
            flag++;
        else if (ispunct(line[i]))
            flag++;
        if(flag==1){
            deleteChar(line, i);
        }
    }
}

void trim(char *str) {
    int start = 0, end = strlen(str) - 1;

    while (isspace(str[start]) || str[start] == '\n') {
        start++;
    }

    while (end > start && (isspace(str[end]) || str[end] == '\n')) {
        end--;
    }

    if (start > 0 || end < strlen(str) - 1) {
        memmove(str, str + start, end - start + 1);
        str[end - start + 1] = '\0';
    }
}

void splitWords(char **dictionary, int *hotVector, int *wordsCounter, char *line,char *splittedWord){
    int index;
    
    splittedWord = strtok(line, " ");
    while(splittedWord != NULL){
        
        index=searchWord(splittedWord, dictionary, *wordsCounter);
        
        if(index!=-1){
            (*(hotVector+index))=1;
        }
        
        splittedWord = strtok(NULL, " ");
    }
}

char** allocateMemoryChar(int row, int column){
    int i;
    char **matrix;
    matrix=(char**) calloc(row,sizeof(char*));
    if (matrix == NULL) {
        printf("Bellek tahsis hatasi!\n");
        return 0;
    }
    
    for(i=0;i<row;i++){
    	matrix[i]=(char*) calloc(column,sizeof(char));
        if (matrix[i] == NULL)
            printf("Bellek tahsis hatasi!\n");
            
	}

    return matrix;
}


int searchWord(char *word, char *dictionary[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        if (strcmp(dictionary[i],word) == 0) {
            return i; // Word found
        }
    }
    return -1; // Word not found
}

double tanh(double x) {
    return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}


double dotProduct(double* a, int* b, int size) {
    double result = 0;
    for (int i = 0; i < size; i++) {
        result += a[i] * b[i];
    }
    return result;
}


int guessNewsCategory(double *weights, int wordsCounter, int *hotVector) {
    double output;
    

    output = tanh(dotProduct(weights, hotVector, wordsCounter)); 

    if(output>=0)
        output=1;
    else
        output=-1;
               
    return output;
}
