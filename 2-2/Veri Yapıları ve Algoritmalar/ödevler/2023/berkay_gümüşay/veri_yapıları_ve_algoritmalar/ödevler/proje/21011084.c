#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct TrieNode{
	struct TrieNode *children[10];
	int isEndOfWord;
	char* word;	
}trieNode;

int charToInt(char c);
trieNode *getNode();
void insertNode(trieNode* root,char* key);
int search(trieNode* root,char* key);
void searchNumber(trieNode* root,int number);

int main(int argc, char *argv[]) {

	trieNode *root = getNode();
	int i,N,run = 1,wordNum;
	char dosyaAdi[30];
	char **stringArray;
	char *line;
	FILE *file;
	printf("Kelime Sayisini Giriniz: ");
	scanf("%d",&N);
	line = (char *)malloc(sizeof(char) *100);
    stringArray = (char**)calloc(sizeof(char**),N);
	file = fopen("words.txt","r");
	fgets(line,256,file);
	stringArray[0] = strtok(line,",");
	for(i=1;i<N;i++){
		stringArray[i] = strtok(NULL,",");
	}
	system("cls");
	for (i = 0; i < N; i++){
        insertNode(root, stringArray[i]);  
	}	
	while(run == 1){
		printf("Cikis icin 0 yaziniz\n\n");
		printf("Aramak istediginiz kelimenin sayi degerini giriniz :");
		scanf("%d",&wordNum);
		if(wordNum == 0){
			printf("\n\nCikis Yapildi\n");
			return 0;
		}
		printf("\n");
		searchNumber(root,wordNum);
		printf("\n\nTekrar Etmek Icin Enter'a Basiniz...");
		getch();
		system("cls");
	}
	return 0;
}


int search(trieNode* root,char* key){
	int level;
    int length = strlen(key);
    int index;
    trieNode *pNode = root;
    for (level=0;level<length;level++)
    {
        index = charToInt(key[level]);
        if (pNode->children[index] == NULL)
            return 0;
        pNode = pNode->children[index];
    }
    return (pNode->isEndOfWord);
}

void searchNumber(trieNode* root,int number){
	int numOfDigits = floor(log10(abs(number))) + 1;
	int i;
	int tmp;
	trieNode *pNode = root;
	int *indexArr = (int*)malloc(sizeof(int)*numOfDigits);
	for(i=0;i<numOfDigits;i++){
		indexArr[i] = number%10; 
		number = number/10;
	}
	for(i=0;i<(numOfDigits/2);i++){
		tmp = indexArr[i];
		indexArr[i] = indexArr[numOfDigits-1-i];
		indexArr[numOfDigits-1-i] = tmp;
	}
	for(i=0;i<numOfDigits;i++){
		if(pNode->children[indexArr[i]] == NULL){
			printf("!! Word Not Found !!\n");
			return;
		}
		pNode = pNode->children[indexArr[i]];
	}
	printf("Word Found : %s  ",pNode->word);
	if(pNode->children[0] != NULL){
		printf("\nWord Found : %s  ",pNode->children[0]->word);
	}
}

trieNode *getNode(){
	trieNode *pNode = NULL;
	int i;
	pNode = (trieNode*)malloc(sizeof(trieNode));	
	if(pNode != NULL){
		pNode->isEndOfWord = 0;
		for(i=0;i<10;i++){
			pNode->children[i] = NULL;
		}
	}
	return pNode;
}
void insertNode(trieNode* root,char* key){
	int level,length=strlen(key),index;
	trieNode *pNode = root;
	for(level=0;level<length;level++){
		index = charToInt(key[level]);
		if(pNode->children[index] == NULL){
			pNode->children[index] = getNode();
		}
		pNode = pNode->children[index];
	}
	if(pNode->isEndOfWord == 1){
		pNode->children[0] = getNode();
		pNode = pNode->children[0];
	}
	
	pNode->word = (char*)malloc(sizeof(char)*length);
	strcpy(pNode->word,key);
	pNode->isEndOfWord = 1;
}
int charToInt(char c){
	if(c == '#'){
		return 0;
	}
	else if((c == 'ç') || (c == 'ð') || (c == 'ü') || (c == 'þ')){
		return 1;
	}
	else if((c == 'a') || (c == 'b') || (c == 'c')){
		return 2;
	}
	else if((c == 'd') || (c == 'e') || (c == 'f')){
		return 3;
	}
	else if((c == 'g') || (c == 'h') || (c == 'i')){
		return 4;
	}
	else if((c == 'j') || (c == 'k') || (c == 'l')){
		return 5;
	}
	else if((c == 'm') || (c == 'n') || (c == 'o')){
		return 6;
	}
	else if((c == 'p') || (c == 'q') || (c == 'r') || (c == 's')){
		return 7;
	}
	else if((c == 't') || (c == 'u') || (c == 'v')){
		return 8;
	}
	else if((c == 'w') || (c == 'x') || (c == 'y') || (c == 'z')){
		return 9;
	}
}
