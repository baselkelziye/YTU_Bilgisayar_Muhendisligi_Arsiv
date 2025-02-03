#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int getWord(char tmpWord[],int i);
void printWords(char **words,int wordsAmount,int maxLen);
void freeMemory(char **words,int wordsAmount);

int main(){
	int i, j;
	int len, maxLen=0;
	int wordsAmount;
	char **words;
	char tmpWord[50];
	
	printf("Kelime sayisini giriniz: ");
	scanf("%d",&wordsAmount);
	
	words=(char**) calloc (wordsAmount,sizeof(char*));
	
	i=0;
	while(i<wordsAmount){
		len=getWord(tmpWord,i);
		words[i]=(char*) calloc (len,sizeof(char));
		
		for(j=0;j<len-1;j++){
			words[i][j]=tmpWord[j];
		}
		words[i][len]='\0';
		
		if(len>maxLen){
			maxLen=len;
		}
		i++;
	}

	printWords(words,wordsAmount,maxLen);
	
	return 0;
}

void printWords(char **words,int wordsAmount,int maxLen){
	int i, j;
	int currLen;
	for(i=0;i<wordsAmount;i++){
		for(j=0;j<maxLen;j++){
			currLen=strlen(words[i]);
			if(currLen>=j)
				printf("%c",words[i][j]);
			else
				printf("*");
		}
		printf("\n");
	}
}

int getWord(char tmpWord[50],int i){
	int len;
	
	printf("%d. kelimeyi giriniz: ",i+1);
	scanf("%s",tmpWord);
	len=strlen(tmpWord);
	
	return len+1;
}

void freeMemory(char **words,int wordsAmount){
	int i;
	for(i=0;i<wordsAmount;i++){
		free(words[i]);
	}
	
	free(words);
}
