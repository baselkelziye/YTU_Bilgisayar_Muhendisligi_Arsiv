#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** getWords(char**, int);
void printAndClearWords(char**, int);

int main(){
	char** dizi;
	int n;
	printf("how many words: ");
	scanf("%d", &n);
	dizi = getWords(dizi, n);
	printAndClearWords(dizi, n);
	return 0;
}

char** getWords(char** dizi, int n){
	int i, j, len, max = 0;
	char* temp = (char*) malloc(51*sizeof(char));
	dizi = (char**) malloc(n * sizeof(char*));
	
	for(i=0;i<n;i++){
		printf("%d. word: ", i+1);
		scanf("%s", temp);
		len = strlen(temp);
		if(len > max) max = len;
		dizi[i] = (char*) malloc((len+1)*sizeof(char));
		for(j=0;j<len;j++) dizi[i][j] = temp[j];
		dizi[i][j] = '\0';
	}
	for(i=0;i<n;i++){
		len = strlen(dizi[i]);
		temp = realloc(dizi[i], max+1);
		if(temp != NULL){
			for(j=len;j<max;j++) dizi[i][j] = '*';
			dizi[i][j] = '\0';
		}
	}
	
	return dizi;
}

void printAndClearWords(char** dizi, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%s\n", dizi[i]);
	}
	for(i=0;i<n;i++){
		free(dizi[i]);
	}
	free(dizi);
}
