#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <time.h>
#define MAX_SENTENCES 201
#define MAX_WORDS 15
#define MAX_CHARS 100

void testing(double*, double**, int, int, int*, int);
void regressionWithGD(double*, int*, int, int, double**, double, double, int);
void regressionWithSGD(double*, int*, int, int, double**, double, double, int);
void regressionWithADAM(double*, int*, int, int, double**, double, double, int);
void gradientDescent(double*, double*, double, int);
void gradientDescentForADAM(double*, double*, double*, double*, double, double, double, int, int);
void derivative(double*, double*, int, int*, double**, int, double);
double lossFunction(double*, int, int*, double**, int);
double getYi(int*, int);
double dotProduct(double*, double*, int);
void seperateIntoTrainingSet(int**, int);
void shuffle(int*, int);
void createHotVectors(char***, double***, int, int*, char**, int);
int createDict(char***, int, int*, char***);
void tokenizeSentence(char*, char***, int, int*);
int readFromFile(char***, int*, int*);

int main() {
    int i, j, trainingSize, maxIter;
    char ***matrix;
    int sentenceCount = 0, dictSize;
    int wordCounts[MAX_SENTENCES] = {0};
    char **dict;
    int *set;
    double **hotVectors, **W;
    double eps, tolerans;

    srand(time(0));
	
	// Allocate memory for the 3D matrix that stores sentences
    matrix = (char***)malloc(MAX_SENTENCES * sizeof(char**));
    for (i = 0; i < MAX_SENTENCES; i++) {
        matrix[i] = (char**)malloc(MAX_WORDS * sizeof(char*));
        for (j = 0; j < MAX_WORDS; j++) {
            matrix[i][j] = (char*)malloc(MAX_CHARS * sizeof(char));
        }
    }
    
    if(readFromFile(matrix, &sentenceCount, wordCounts)) return 1;
	
	trainingSize = (sentenceCount * 4) / 5;
	
	dictSize = createDict(matrix, sentenceCount, wordCounts, &dict);
	
	createHotVectors(matrix, &hotVectors, sentenceCount, wordCounts, dict, dictSize);
	
	W = (double**) malloc(15 * sizeof(double*));
	for(i=0;i<5;i++){
		W[i] = (double*) malloc(dictSize * sizeof(double));
		W[i+5] = (double*) malloc(dictSize * sizeof(double));
		W[i+10] = (double*) malloc(dictSize * sizeof(double));
		for(j=0;j<dictSize;j++){
			W[i][j] = ((double) rand()) / (double) RAND_MAX - 0.4;
			W[i+5][j] = W[i][j];
			W[i+10][j] = W[i][j];
		}
	}
	
	seperateIntoTrainingSet(&set, sentenceCount);
	
	printf("\neps: ");
	scanf("%lf", &eps);
	printf("\ntolerans: ");
	scanf("%lf", &tolerans);
	printf("\nmaximum iteration: ");
	scanf(" %d", &maxIter);
	
	for(i=0;i<5;i++){
		printf("\n\nGD - %d...\n", i+1);
		regressionWithGD(W[i], set, dictSize, trainingSize, hotVectors, eps, tolerans, maxIter);
		testing(W[i], hotVectors, sentenceCount, trainingSize, set, dictSize);
		printf("\n\nSGD - %d...\n", i+1);
		regressionWithSGD(W[i+5], set, dictSize, trainingSize, hotVectors, eps, tolerans, maxIter);
		testing(W[i+5], hotVectors, sentenceCount, trainingSize, set, dictSize);
		printf("\n\nADAM - %d...\n", i+1);
		regressionWithADAM(W[i+10], set, dictSize, trainingSize, hotVectors, eps, tolerans, maxIter);
		testing(W[i+10], hotVectors, sentenceCount, trainingSize, set, dictSize);
	}
	
    return 0;
}

void testing(double* W, double** hotVectors, int sentenceCount, int trainingSize, int* set, int dictSize){
	int i, count = 0;
	double testResult = 0;
	for(i=trainingSize;i<sentenceCount;i++){
		testResult = tanh(dotProduct(W, hotVectors[set[i]], dictSize));
		//printf("\ntest %d: %lf", set[i], testResult);
		if(getYi(set, i) == 1 && testResult > 0.4) count++;
		if(getYi(set, i) == -1 && testResult < -0.4) count++;
	}
	printf("\nthe number of correct outputs out of %d: %d", sentenceCount - trainingSize, count);
	printf("\n%d percent success...",  (count * 100) / (sentenceCount - trainingSize));
	printf("\n\n********************************\n");
}

void regressionWithGD(double* W, int* set, int dictSize, int trainingSize, double** hotVectors, double eps, double tolerans, int maxIter){
	double lossOld = 0, lossNew = 0;
	int i=0;
	double* dW = (double*) malloc(dictSize * sizeof(double));
	
	clock_t starttime, endtime;
	FILE *file = fopen("file1.txt", "a");
	if(file == 0) return;
	starttime = clock();
	do{
		//printf("%d. iterasyon\n", i+1);
		lossOld = lossNew;
		lossNew = lossFunction(W, trainingSize, set, hotVectors, dictSize);
		derivative(dW,W, trainingSize,set,hotVectors,dictSize,eps);
		gradientDescent(dW, W, eps, dictSize);
		fprintf(file, "%lf\n", lossNew);
		i++;
	} while(i < maxIter && fabs(lossOld - lossNew) > tolerans);
	
	fprintf(file, "%s\n", "stop");
	endtime = clock();
	fprintf(file, "%lf\n", (double) (endtime - starttime) / CLOCKS_PER_SEC);
	fclose(file);
	printf("\nit took %d iterations\n", i);
}

void regressionWithSGD(double* W, int* set, int dictSize, int trainingSize, double** hotVectors, double eps, double tolerans, int maxIter){
	double lossOld = 0, lossNew = 0;
	int i=0, stochasticSize = trainingSize / 5;
	double* dW = (double*) malloc(dictSize * sizeof(double));
	
	clock_t starttime, endtime;
	FILE *file = fopen("file2.txt", "a");
	if(file == 0) return;
	starttime = clock();
	
	do{
		//printf("%d. iterasyon - ", i+1);
		shuffle(set, trainingSize);
		lossOld = lossNew;
		lossNew = lossFunction(W, trainingSize, set, hotVectors, dictSize);
		derivative(dW, W,stochasticSize,set,hotVectors, dictSize,eps);
		gradientDescent(dW, W, eps, dictSize);
		fprintf(file, "%lf\n", lossNew);
		i++;
	} while(i < maxIter && fabs(lossOld - lossNew) > tolerans);
	
	fprintf(file, "%s\n", "stop");
	endtime = clock();
	fprintf(file, "%lf\n", (double) (endtime - starttime) / CLOCKS_PER_SEC);
	fclose(file);
	printf("\nit took %d iterations\n", i);
}

void gradientDescent(double* dW, double* W, double eps, int dictSize){
	int i;
	for(i=0;i<dictSize;i++) W[i] = W[i] - eps * dW[i];
}

void regressionWithADAM(double* W, int* set, int dictSize, int trainingSize, double** hotVectors, double eps, double tolerans, int maxIter){
	double lossOld = 0, lossNew = 0, b1 = 0.9, b2 = 0.999;
	int i=1, stochasticSize = trainingSize / 5;
	
	double* dW = (double*) calloc(dictSize, sizeof(double));
	double *G = (double*) calloc(dictSize, sizeof(double));
	double *V = (double*) calloc(dictSize, sizeof(double));
	
	clock_t starttime, endtime;
	FILE *file = fopen("file3.txt", "a");
	if(file == 0) return;
	starttime = clock();
	
	do{
		//printf("%d. iterasyon - ", i+1);
		shuffle(set, trainingSize);
		lossOld = lossNew;
		lossNew = lossFunction(W, trainingSize, set, hotVectors, dictSize);
		derivative(dW, W,stochasticSize,set,hotVectors, dictSize,eps);
		gradientDescentForADAM(dW, G, V, W, b1, b2, eps, dictSize, i);
		fprintf(file, "%lf\n", lossNew);
		i++;
	} while(i < maxIter && fabs(lossOld - lossNew) > tolerans);
	
	fprintf(file, "%s\n", "stop");
	endtime = clock();
	fprintf(file, "%lf\n", (double) (endtime - starttime) / CLOCKS_PER_SEC);
	fclose(file);
	printf("\nit took %d iterations\n", i);
}

void gradientDescentForADAM(double* dW, double* G, double* V, double* W, double b1, double b2, double eps, int dictSize, int t){
	int i;
	double g, v;
	for(i=0;i<dictSize;i++){
		V[i] = b1 * V[i] + (1 - b1) * dW[i];
		G[i] = b2 * G[i] + (1 - b2) * dW[i] * dW[i];
		v = V[i] / (1 - pow(b1, t));
		g = G[i] / (1 - pow(b2, t));
		W[i] = W[i] - (eps / (sqrt(g) + 0.000001)) * v;
	}
}

void derivative(double* dW, double* W, int trainingSize, int* set, double** hotVectors, int dictSize, double eps){
    int i,j;
    double temp, dotResult;	
	
    for(i=0;i<trainingSize;i++){
    	dotResult = dotProduct(W, hotVectors[set[i]], dictSize);
        for(j=0;j<dictSize;j++){
            temp = 1.0/cosh(dotResult);
			temp *= temp;
            temp *= getYi(set,i) - tanh(dotResult);
            temp *= hotVectors[set[i]][j];
            dW[j] += temp;
        }
    }
    
    for(i=0;i<dictSize;i++){
    	dW[i] *= (-2.0 / trainingSize);
	}
}

double lossFunction(double* W, int trainingSize, int* set, double** hotVectors, int dictSize){
	int i;
	double result=0.0, temp;
	
	for(i=0;i<trainingSize;i++){
		temp = getYi(set, i) - tanh(dotProduct(W, hotVectors[set[i]], dictSize));
		result += temp * temp;
	}
	//printf("loss f: %lf\n", result / trainingSize);
	
	return result / trainingSize;
}

double getYi(int* set, int i){
	if(set[i] < 100) return 1;
	else return -1;
}

double dotProduct(double* v1, double* v2, int size){
	double result = 0.0;
	int i;
	for(i=0;i<size;i++){
		result += v1[i] * v2[i];
	}
	return result;
}

void seperateIntoTrainingSet(int** set, int sentenceCount){
	int i;
	*set = (int*) malloc(sentenceCount * sizeof(int));
	for(i=0;i<sentenceCount;i++) (*set)[i] = i;
	shuffle(*set, sentenceCount);
}

void shuffle(int *array, int size) {
	int temp, i, j;
    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void createHotVectors(char*** matrix, double*** hotVectors, int sentenceCount, int* wordCounts, char** dict, int dictSize){
	int i, j, k;
	
	*hotVectors = (double**) calloc(sentenceCount, sizeof(double*));
	for(i=0;i<sentenceCount;i++) (*hotVectors)[i] = (double*) calloc(dictSize, sizeof(double));
	
	for(k=0;k<dictSize;k++){
		for(i=0;i<sentenceCount;i++){
    		for(j=0;j<wordCounts[i];j++){
	    		if(!strcmp(matrix[i][j], dict[k])){
	    			(*hotVectors)[i][k] = 1;
				}
			}
		}
	}
}

int createDict(char*** matrix, int sentenceCount, int* wordCounts, char*** dict){
	int i, j, k, count = 0;
	char** temp;
	
	for(i=0;i<sentenceCount;i++) count += wordCounts[i];
	temp = (char**) malloc(count * sizeof(char*));
	
	k=0;
    for(i=0;i<sentenceCount;i++){
    	for(j=0;j<wordCounts[i];j++){
    		temp[k] = (char*) malloc((strlen(matrix[i][j]) + 1) * sizeof(char));
    		strcpy(temp[k++], matrix[i][j]);
		}
	}
	
	*dict = (char**) malloc(sizeof(char*));
	
	count=0;
	for(i=0;i<k;i++){
		j=0;
		while(j<count && strcmp(temp[i], (*dict)[j]) != 0){
			j++;
		}
		if(j == count){
			*dict = realloc(*dict, (count+1) * sizeof(char*));
			
			(*dict)[count] = (char*) malloc((strlen(temp[i]) + 1) * sizeof(char));
			strcpy((*dict)[count], temp[i]);
			count++;
		}
	}
	return count;
}

void tokenizeSentence(char* sentence, char*** matrix, int sentenceIndex, int* wordCounts) {
    char* token = strtok(sentence, " ");
    int wordIndex = 0;

    while (token != NULL) {
        strcpy(matrix[sentenceIndex][wordIndex], token);
        wordIndex++;
        token = strtok(NULL, " ");

        // Break if maximum words reached
        if (wordIndex >= MAX_WORDS) {
            printf("Maximum number of words reached for sentence %d. Exiting.\n", sentenceIndex + 1);
            break;
        }
    }
    *wordCounts = wordIndex;
}

int readFromFile(char*** matrix, int* sentenceCount, int* wordCounts){
	FILE *file;
    char fileName[100];
    
	printf("Enter the file name: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read sentences from the file
    while (fgets(matrix[*sentenceCount][0], MAX_CHARS, file) != NULL) {
        matrix[*sentenceCount][0][strcspn(matrix[*sentenceCount][0], "\n")] = '\0';

        tokenizeSentence(matrix[*sentenceCount][0], matrix, *sentenceCount, &wordCounts[*sentenceCount]);

        (*sentenceCount)++;

        if (*sentenceCount >= MAX_SENTENCES) {
            printf("Maximum number of sentences reached. Exiting.\n");
            break;
        }
    }
	
    fclose(file);
    return 0;
}
