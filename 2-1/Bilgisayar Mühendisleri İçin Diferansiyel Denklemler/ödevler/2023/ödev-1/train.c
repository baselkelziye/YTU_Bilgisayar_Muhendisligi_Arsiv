#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<time.h>


#define MAX_WORD 9000
#define WORD_LENGTH 25
#define LINE_LENGTH 1000
#define LEARNING_RATE 0.05
#define EPOCHS 35
#define BETA1 0.9
#define BETA2 0.999
#define EPSILON 1e-8

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
void gradientDescent(double *weights, int wordsCounter, int **hotVectors);
void update_weights_sgd(double *weights, int **hotVectors, int wordsCounter);
//void adam_optimizer(int **hotVectors, double *weights, int wordsCounter, int a);
void adam_optimizer(int **hotVectors, double *weights, int wordsCounter);

int main() {

    int i, j, k;
    int flag, len, wordsCounter=0;
    char line[LINE_LENGTH];
    char *splittedWord;
    char fileName[100];
    char newsCategory[2][15]={"ekonomi","spor"};
    //ekonomi 1, spor -1;
    int **hotVectors;
    char **dictionary;
    //mode1= addDict, mode2 = searchDict
    FILE *file, *dictionaryFile, *hotVectorsFile, *fw;
    double *weights;

    

    dictionary = allocateMemoryChar(MAX_WORD, WORD_LENGTH);

    for(i=0;i<2;i++){
        for(j=1;j<=80;j++){
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
                    splitWords(dictionary, hotVectors, &wordsCounter, line, splittedWord, 1,0);
                }
            }
        }
    }
    
    weights = (double*)calloc(wordsCounter,sizeof(double));
    for(i=0;i<wordsCounter;i++){
        weights[i] = 0.05;
    }

    hotVectors=allocateMemoryInteger(160, wordsCounter+1);
    
    for(i=0;i<160;i++){
        for(j=0;j<wordsCounter+1;j++){
            hotVectors[i][j]=0;
        }
    }

    for(i=0;i<2;i++){
        for(j=1;j<=80;j++){
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
    
    hotVectorsFile = fopen("C:\\Users\\mehme\\dif\\hotVectors.txt", "w");
    
    if (hotVectorsFile == NULL) {
        fprintf(stderr, "file acilamadi.\n");
        return 0;
    }
    
    for (i = 0; i < 160; i++) {
        for(j=0;j<wordsCounter;j++){
            fprintf(hotVectorsFile, "%d ", hotVectors[i][j]);
            //printf("%c",hotVectors[i]);
        }
        fprintf(hotVectorsFile,"\n\n\n\n\n\n\n\n\n\n\n");
    }
    fclose(hotVectorsFile);
    
    //gradientDescent(weights, wordsCounter, hotVectors);
    update_weights_sgd(weights, hotVectors, wordsCounter);
    //adam_optimizer(hotVectors, weights, wordsCounter);
    
    fw = fopen("C:\\Users\\mehme\\dif\\weights3New.txt", "w");
    for (j = 0; j < wordsCounter; j++) {
        fprintf(fw, "%f\n",weights[j]);
    }
    fclose(fw);

    saveWordsToFile(dictionaryFile, &wordsCounter, dictionary);
	
	freeMemoryChar(dictionary,MAX_WORD);
    freeMemoryInt(hotVectors,160);
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
            
            if(index!=-1){
                if(textNumber<=99){
                    *(*(hotVectors+textNumber))=1;
                    *(*(hotVectors+textNumber)+index+1)=1;
                }
                else{
                    *(*(hotVectors+textNumber-20))=-1;
                    *(*(hotVectors+textNumber-20)+index+1)=1;
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
    int i;
    for (i = 0; i < size; i++) {
        result += a[i] * b[i];
    }
    return result;
}

void gradientDescent(double *weights, int wordsCounter, int **hotVectors) {
    int oneHotVector[wordsCounter];
    int label, trueOutput;
    int i, j, epoch;
    double output, error;
    float minSquareErrorSum;
    FILE *fp, *fileLoss;
    fp=fopen("C:\\Users\\mehme\\dif\\labels.txt","w");

    for(i=0;i<160;i++){
        label=hotVectors[i][0];
        fprintf(fp ,"labels:%d\n",label);
    }
    fclose(fp);
    
    for (epoch = 1; epoch <= EPOCHS; epoch++) {
        minSquareErrorSum=0;
        for (i = 0; i < 160; i++) {            
            
            for(j=0;j<wordsCounter;j++){
                oneHotVector[j]=hotVectors[i][j+1];
            }
    
            output = tanh((dotProduct(weights, oneHotVector, wordsCounter))*3.14/180);
            trueOutput = getTrueOutput(label);
            error = trueOutput - output;           
             //(y - yhat)^2  -> -2*(y-yhat)*(-yhat)'
             //tanh(w*x)               x*(1-tanh(w*x)^2)

            for (j = 0; j < wordsCounter; j++) {
                weights[j] -= LEARNING_RATE * error * -2 * oneHotVector[j]*(1-(output*output));
            }

            
            minSquareErrorSum+=error*error;
        }
        printf("Epoch:%d  Loss:%f\n",epoch,minSquareErrorSum/160);
        fileLoss = fopen("C:\\Users\\mehme\\dif\\loss.txt","w");
        
    }
}


void update_weights_sgd(double *weights, int **hotVectors, int wordsCounter) {
    int i, j, label, rand, epoch, index;
    srand(time(NULL));
    int oneHotVector[wordsCounter];
    float prediction, gradient;
    float error, minSquareError;;    
    FILE *fp;
    
    for(epoch=1;epoch<EPOCHS;epoch++){
        index = (rand%160)+1;

        label=hotVectors[index][0];
        for(i=0;i<wordsCounter;i++){
            oneHotVector[i]=hotVectors[index][i+1];
        }

        prediction = tanh(dotProduct(weights,oneHotVector,wordsCounter)*3.14/180);
        

        for (j = 0; j < wordsCounter; j++) {
            weights[j] -= LEARNING_RATE  * -2 * error * oneHotVector[j]*(1-powf(prediction,2));
        }
        
        error=(float)label-prediction;
        minSquareError=0.5*error*error;

        printf("EPOCH: %d  LOSS:%lf\n",epoch, minSquareError);
    }

    
    fp=fopen("C:\\Users\\mehme\\dif\\weights3New.txt","w");
    if(fp!=NULL){
        for(i=0;i<wordsCounter;i++){
           fprintf(fp, "%lf\n", weights[i]);
        }
        fclose(fp);

    }else{
        printf("acilamadi");
    }
    fclose(fp);

    //gradient = (prediction - labels[i]) * (1.0 - pow(tanh(prediction), 2));

    // Ağırlıkları güncelle
    
    
}

void adam_optimizer(int **hotVectors, double *weights, int wordsCounter) {
    double *m = (double *)malloc(wordsCounter * sizeof(double));
    double *v = (double *)malloc(wordsCounter * sizeof(double));
    double beta1_t = 1.0;
    double beta2_t = 1.0;
    double m_hat, v_hat;
    int epoch, i;
    FILE *fp;
    fp=fopen("C:\\Users\\mehme\\dif\\weightsADAM-0.txt","w");
    printf("yazdi0");
    // Gradient Descent
    for (epoch = 0; epoch < EPOCHS; epoch++) {
        for (i = 0; i < wordsCounter; i++) {
            m[i] = BETA1 * m[i] + (1 - BETA1) * hotVectors[epoch][i];
            v[i] = BETA2 * v[i] + (1 - BETA2) * hotVectors[epoch][i] * hotVectors[epoch][i];
        }

        beta1_t *= BETA1;
        beta2_t *= BETA2;

        for (i = 0; i < wordsCounter; i++) {
            m_hat = m[i] / (1 - beta1_t);
            v_hat = v[i] / (1 - beta2_t);
            weights[i] -= LEARNING_RATE * m_hat / (sqrt(v_hat) + EPSILON);
        }
    }
    if(fp!=NULL){
        for(i=0;i<wordsCounter;i++){
           fprintf(fp, "%lf\n", weights[i]);
           printf("yazdi0");
        }
        fclose(fp);

    }else{
        printf("acilamadi");
    }
    fclose(fp);
    
    printf("bitti");
    free(m);
    free(v);
}