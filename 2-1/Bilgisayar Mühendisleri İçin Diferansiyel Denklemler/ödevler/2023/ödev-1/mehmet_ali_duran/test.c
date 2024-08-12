#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAX_WORD 9000
#define WORD_LENGTH 30
#define LINE_LENGTH 1000
#define LEARNING_RATE 0.08
#define EPOCHS 10

void deleteChar(char *str, int index);
void toLowerCase(char *str);
void addDictionary(char **words,char *currentWord,int *wordsCounter);
void deleteApostrophe(char text[]);
void freeMemoryChar(char **matrix, int row);
void freeMemoryInt(int **matrix, int row);
void deletePuncAndNumbers(int len, char *line);
void trim(char *str);
void saveWordsToFile(FILE* dictionaryFile, int *wordsCounter, char **dictionary);
void splitWords(char **dictionary, int **hotVectors, int *wordsCounter, char *line,char *splittedWord, int mode, int textNumber);
int searchWord(char *word, char *dictionary[], int len);
char** allocateMemoryChar(int row, int column);
int** allocateMemoryInteger(int row, int column);
double tanh(double x);
double dotProduct(double* a, int* b, int size);
int getTrueOutput(int label) {
    return label;
}
float findSuccessRate(double *weights, int wordsCounter, int **hotVectors);

int main() {

    int i, j, k;
    int flag, len, wordsCounter=0, valueCount = 0, lineCount=0;;
    char line[LINE_LENGTH];
    char *splittedWord;
    char fileName[100];
    char **newsCategory;
    //ekonomi 1, spor -1;
    int **hotVectors;
    char **dictionary;
    //mode1= addDict, mode2 = searchDict
    FILE *file, *dictionaryFile, *hotVectorsFile, *fw, *fpDict, *fpWeights;
    double *weights;
    double currentValue;
    char currentWord[WORD_LENGTH];
    
    newsCategory=allocateMemoryChar(2,WORD_LENGTH);
    dictionary = allocateMemoryChar(MAX_WORD, WORD_LENGTH);

    *newsCategory="ekonomi";
    *(newsCategory+1)="spor";
    // Dosyayı aç
    fpDict = fopen("kelimeler.txt", "r");
    if (fpDict == NULL) {
        printf("Dosya açma hatası!\n");
        return 1;
    }
    
    while (EOF != fscanf(fpDict, "%[^\n]\n", currentWord)) {

        dictionary[wordsCounter++]=strdup(currentWord); 
    }


    fclose(fpDict);

    weights = (double*)calloc(wordsCounter,sizeof(double));
    
    fpWeights=fopen("weights0.txt","r");
    while (fscanf(fpWeights, "%lf", &currentValue) == 1 && valueCount < wordsCounter) {
        weights[valueCount] = currentValue;
        valueCount++;
    }

    hotVectors=allocateMemoryInteger(40, wordsCounter+1);
    
    for(i=0;i<40;i++){
        for(j=0;j<wordsCounter+1;j++){
            hotVectors[i][j]=0;
        }
    }

    for(i=0;i<2;i++){
        for(j=81;j<=100;j++){
            
            snprintf(fileName, sizeof(fileName), "C:\\Users\\mehme\\dif\\%s\\%d.txt",newsCategory[i] ,j);
            file = fopen(fileName, "r");
            if (file == NULL) {

                perror("dosya acilamadi");
                return 1;
            }

            while(fgets(line, sizeof(line), file) != NULL) {
                
                flag=0;
                
                if (strspn(line, " \t\n") == strlen(line))
                    flag=1;
                    
                if(flag!=1){
                    trim(line);
                    toLowerCase(line);
                    deleteApostrophe(line);
                    len = strlen(line);
                    deletePuncAndNumbers(len, line);
                    //mode1= addDict, mode2 = searchDict
                    splitWords(dictionary, hotVectors, &wordsCounter, line, splittedWord, 2, i*100+j-1);
                    
                }
            }
        }
    }

    
    hotVectorsFile = fopen("C:\\Users\\mehme\\dif\\hotVectorsTest.txt", "w");
    
    if (hotVectorsFile == NULL) {
        fprintf(stderr, "file acilamadi.\n");
        return 0;
    }
    
    for (i = 0; i < 40; i++) {
        for(j=0;j<wordsCounter;j++){
            fprintf(hotVectorsFile, "%d ", hotVectors[i][j]);
            //printf("%d",hotVectors[i][j]);
        }
        fprintf(hotVectorsFile,"\n\n\n\n\n\n\n\n\n\n\n");
    }
    fclose(hotVectorsFile);
    printf("findSucces:%.2lf\n",findSuccessRate(weights, wordsCounter, hotVectors));
    fclose(fpWeights);
	freeMemoryChar(dictionary,MAX_WORD);
    freeMemoryInt(hotVectors,40);
    free(weights);
	
    return 0;
}

void freeMemoryChar(char **matrix, int row){
	int i;
	for(i=0;i<row;i++){
    	free(matrix[i]);
	}
	free(matrix);
}

void freeMemoryInt(int **matrix, int row){
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

void addDictionary(char **dictionary,char *currentWord,int *wordsCounter){
	int i, control=0;
	for (i = 0; i < *wordsCounter; i++) {
		if (strcmp(dictionary[i], currentWord) == 0) {
            control = 1;
            i=*wordsCounter;
        }
    }
    if(strlen(currentWord)<3)
    	control=1;
    
	if(control==0){
		dictionary[*wordsCounter]=strdup(currentWord);
		*wordsCounter=*wordsCounter+1;		
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

void saveWordsToFile(FILE* dictionaryFile, int *wordsCounter, char **dictionary){
    int i;
    dictionaryFile = fopen("C:\\Users\\mehme\\dif\\kelimeler.txt", "w");

    if (dictionaryFile == NULL) {
        fprintf(stderr, "file acilamadi.\n");
        return;
    }

    for (i = 0; i < *wordsCounter; i++) {
        fprintf(dictionaryFile,"%s\n", dictionary[i]);
    }

    fclose(dictionaryFile);

    printf("Kelimeler dosyaya kaydedildi.\n");
}

void splitWords(char **dictionary, int **hotVectors, int *wordsCounter, char *line,char *splittedWord, int mode, int textNumber){
    int index;
    
    splittedWord = strtok(line, " ");
    while(splittedWord != NULL){
        if(mode==1)
            addDictionary(dictionary,splittedWord,wordsCounter);
        else if(mode==2){
            index=searchWord(splittedWord, dictionary, *wordsCounter);
            
            if(index!=-1){
                if(textNumber<=99){
                    *(*(hotVectors+textNumber-80))=1;
                    *(*(hotVectors+textNumber-80)+index+1)=1;
                }
                else{
                    *(*(hotVectors+textNumber-160))=-1;
                    *(*(hotVectors+textNumber-160)+index+1)=1;
                }
            }
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

int** allocateMemoryInteger(int row, int column){
    int i;
    int **matrix;
    matrix=(int**) calloc(row,sizeof(int*));
    if (matrix == NULL) {
        printf("Bellek tahsis hatasi!\n");
        return 0;
    }
    
    for(i=0;i<row;i++){
    	matrix[i]=(int*) calloc(column,sizeof(int));
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


float findSuccessRate(double *weights, int wordsCounter, int **hotVectors) {
    int oneHotVector[wordsCounter];
    int label;
    int i, j, trueOutput, matchCounter=0;
    double output;
    
    for (i = 0; i < 40; i++) {
        label=hotVectors[i][0];
        for(j=0;j<wordsCounter;j++){
            oneHotVector[j]=hotVectors[i][j+1];
        }

        output = tanh(dotProduct(weights, oneHotVector, wordsCounter)*3.14/180); 
        trueOutput = getTrueOutput(label);

        if(output>=0)
            output=1;
        else
            output=-1;
        
        if(trueOutput==(int)output)
            matchCounter+=1;
    }
    printf("%d",matchCounter);

    return (float)((float)matchCounter/40)*100;
}
