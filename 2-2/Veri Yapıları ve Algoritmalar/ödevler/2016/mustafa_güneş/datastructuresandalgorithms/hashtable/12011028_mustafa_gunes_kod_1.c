#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M1 541 // stopwords icin M degeri
#define M2 809 // diger kelimeler icin m degeri

typedef struct{ //stopWords icin hashtable
	int key;
	char value[15];
}HASHTABLE;

typedef struct{ //dokumandaki kelimeler icin hashtable
	int key;
	int textCount; //kac farkli textte geciyor
	char textName[15][20]; //icinde gectigi textlerin adlari
	char value[15]; //kelimenin kendisi
	char where[10]; //var olan dokumanlardaki degeri 1 olacak
}HASHTABLE2;

//fonskiyon prototipleri
char ** readStopWords(char **stopWords, int *stopWordsCount);
void toLowerCase(char word[15]);
int keyForHash(char str[15]);
int hash(int key, int i, int M);
int hash1(int key, int M);
int hash2(int key, int M);
void writeFileStopWordsHash(HASHTABLE *stopWordsHash, int n);
void readStopWordsHashTable(HASHTABLE *stopWordsHash, int n);
int isStopWord(char word[20], HASHTABLE *stopWordsHash, int * searchCount, int M);
void readDocumentList(char documentList[15][15], int *n);
void inputWord(HASHTABLE *stopWordsHash, HASHTABLE2 *wordHash);

int main(){
	char **stopWords; //stop wordleri tutacak matris
	char documentList[15][15];
	int stopWordsCount; //stop word sayisi
	int i, j, k=0; //genel amacli dongu indisleri
	int key; //tabloya yerlestirirken kullanilacak key degiskeni
	int address; //tabloya yerlestirirken kullanilacak adres degiskeni
	int fileCount;
	int searchCount; //kac adimda bulundu
	HASHTABLE *stopWordsHash; //stop wordleri tutacak hash table
	HASHTABLE2 *wordHash;
	
	//stop word listesindeki kelimeleri oku
	stopWords = readStopWords(stopWords, &stopWordsCount);
	
	stopWordsHash = (HASHTABLE *) malloc (M1 * sizeof(HASHTABLE));
	wordHash = (HASHTABLE2 *) malloc (M2 * sizeof(HASHTABLE2));
	
	for(i=0; i<M1; i++){
		stopWordsHash[i].key = -1;
		strcpy(stopWordsHash[i].value, "bos");
	}
	
	for(i=0; i<M2; i++){
		wordHash[i].key = -1;
		wordHash[i].textCount = 0;
		strcpy(wordHash[i].value, "bos");
	}
	
	//stop words icin hash table olustur
	//ARTIK GEREK KALMADI DOSYADAN OKUNACAK
	/*for(i=0; i<stopWordsCount; i++){
		key = keyForHash(stopWords[i]);
		address = hash(key, 0, M1); //hash2 fonksiyonunun degeri ilk denemede sayilmaz
		
		//adres bos kelimeyi yerlestir
		if(stopWordsHash[address].key == -1){
			strcpy(stopWordsHash[address].value, stopWords[i]);
			stopWordsHash[address].key = key;
		}
		else{//cakisma var yeni yer ara
			j = 1;
			k = 0;
			//printf("\ncakisma durumu\n");
			k++;
			do{//bos yer gorene kadar don
				address = hash(key, j, M1);
				j++;
				//printf("\n%d",stopWordsHash[address].key);
				k++;
			}while(stopWordsHash[address].key != -1 && k<541);
			
			if(k==541)
				printf("\n%s kelimesi yerlestirilemedi", stopWords[i]);
			else{
				strcpy(stopWordsHash[address].value, stopWords[i]);
				stopWordsHash[address].key = key;
			}
		}
	}*/
	
	//stop words hash i dosyaya yaz
	//writeFileStopWordsHash(stopWordsHash, M1);
	
	//dosyaya yazili stop words hash table i oku
	readStopWordsHashTable(stopWordsHash, M1);
	
	//okunacak dosya listesini okur	
	readDocumentList(documentList, &fileCount);
	
	for(i=0; i<fileCount; i++){
		FILE *fp = fopen(documentList[i], "r");
		char word[20];
		
		while(fscanf(fp, "%s", word) != EOF){
			toLowerCase(word);
			if(isStopWord(word, stopWordsHash, &searchCount, M2) == 0){
				key = keyForHash(word);
				address = hash(key,0,M2);
				
				if(wordHash[address].key == -1){
					strcpy(wordHash[address].value, word);
					wordHash[address].key = key;
					wordHash[address].where[i] = 1;
					strcpy(wordHash[address].textName[wordHash[address].textCount], documentList[i]);
					wordHash[address].textCount++;
				}
				else if(strcmp(word, wordHash[address].value) == 0){ //ayni kelime daha once eklenmis
					wordHash[address].where[i] = 1;
					if(strcmp(documentList[i],wordHash[address].textName[wordHash[address].textCount-1]) != 0){
						strcpy(wordHash[address].textName[wordHash[address].textCount], documentList[i]);
						wordHash[address].textCount++;
					}
				}
				else{//cakisma var yeni yer ara
					j = 1;
					k = 0;
					//printf("\ncakisma durumu\n");
					k++;
					do{//bos yer gorene kadar veya ayni kelimeyi bulana kadar don
						address = hash(key, j, M2);
						j++;
						//printf("\n%d",stopWordsHash[address].key);
						k++;
					}while((wordHash[address].key != -1 && strcmp(word, wordHash[address].value) != 0) && k<809);
			
					//sil
					
					//sil
					if(k==541)
						printf("\n%s kelimesi yerlestirilemedi", word);
					else if(wordHash[address].key == -1){
						strcpy(wordHash[address].value, word);
						wordHash[address].key = key;
						wordHash[address].where[i] = 1;
						strcpy(wordHash[address].textName[wordHash[address].textCount], documentList[i]);
						wordHash[address].textCount++;
					}
					//kelime tabloda var ve ayni textte değil
					else if(strcmp(word, wordHash[address].value) == 0 && wordHash[address].where[i] ==0){
						//printf("ayni kelime var %s %s \n", word, documentList[i] );
						wordHash[address].where[i] = 1;
						strcpy(wordHash[address].textName[wordHash[address].textCount], documentList[i]);
						wordHash[address].textCount++;
					}
				}
			}
		}
	}//for sonu
	
	inputWord(stopWordsHash, wordHash);
	
	return 0;
}//main sonu

//kullanicinin girdigi kelimelerin dokumanlarda aranmasi
void inputWord(HASHTABLE *stopWordsHash, HASHTABLE2 *wordHash){
	char inputWord[20];
	int key, address;
	int i;
	int searchCount; //kac defa arandigini tutan degisken
	
	do{
		printf("\n\nkelime giriniz:\n");
		scanf("%s",inputWord);
		
		toLowerCase(inputWord);
		
		//once stop word mu diye bak
		if(isStopWord(inputWord, stopWordsHash, &searchCount, M1) == 1){
			printf("\n kelime stop word, arama sayisi:%d", searchCount);
		}
		else{
			key = keyForHash(inputWord);
			i=0;
			address = hash(key,i,M2);
	
			if(strcmp(wordHash[address].value, inputWord) == 0){
				printf("ilk aramada bulundu");
				for(i=0; i<wordHash[address].textCount; i++)
					printf("\n%s",wordHash[address].textName[i]);
			}
			else{
				do{
					i++;
					address = hash(key,i,M2);
					searchCount = i;
				}while(i<M2 && strcmp(wordHash[address].value, inputWord) != 0);

				if(i == M2)
					printf("\nkelime bulunamadi arama sayisi %d", searchCount); 
				else{
					printf("%d aramada bulundu", i+1);
					for(i=0; i<wordHash[address].textCount; i++)
						printf("\n%s",wordHash[address].textName[i]);
				} 
			}
		}
		
	}while(strcmp(inputWord, "") != 0);
}


void readDocumentList(char documentList[15][15], int *n){
	FILE *fp;
	int i = 0;
	
	fp = fopen("documentList.txt", "r");
	
	if(fp ==NULL)
		exit(1);
		
	while(fscanf(fp, "%s", documentList[i]) != EOF){
		i++;
	}
	
	*n = i;
}

//paramtre olarak aldigi kelimenin stop word listesinde olup olmadigina bakar
int isStopWord(char word[20], HASHTABLE *stopWordsHash, int *searchCount, int M){
	int key, address = -1;
	int i = -1;
	*searchCount = 0;
	key = keyForHash(word);
	
	do{
		i++;
		address = hash(key,i, M);
	}while(i<M && strcmp(stopWordsHash[address].value,word) != 0);
	
	*searchCount = i;
	
	if(i == M){
		printf("stop words degil %d arama yapildi", *searchCount);
		return 0; //kelime stopwords degil
	}
		
	else
		return 1; //kelime stop words
}

//daha onceden olusturulup dosyaya yazilan stopWordsHashTable i okur
void readStopWordsHashTable(HASHTABLE *stopWordsHash, int n){
	FILE *fp;
	int i;
	
	fp= fopen("stopWordsHashTable.txt", "r");
	
	if(fp == NULL){
		printf("dosya acilamadi");
		exit(1);
	}
	
	for(i=0; i<n; i++){
		fscanf(fp, "%d %s", &stopWordsHash[i].key, stopWordsHash[i].value);
	}
	
	fclose(fp);
}

//olusturulan stopWordsHash i dosyaya yazar
void writeFileStopWordsHash(HASHTABLE *stopWordsHash, int n){
	int i;
	FILE *fp;
	fp = fopen("stopWordsHashTable.txt", "w");
	
	if(fp == NULL){
		printf("dosya acilamadi");
		exit(1);
	}
	
	for(i=0; i<n; i++){
		fprintf(fp,"%d %s\n",stopWordsHash[i].key, stopWordsHash[i].value);
	}
	
	fclose(fp);
}

//aldigi kelime icin key degeri uretip dondurur
int keyForHash(char str[15]){
	int key = 0;
	long i;
	
	for(i=0; i<strlen(str); i++)
		key += (str[i] - 'a') * 26 * i;
		
	return key;
}

int hash(int key, int i, int M){
	int address;
	
	address = (hash1(key, M) + i * hash2(key, M)) % M;
	
	return address;
}

//double hashing icin hash1 fonksiyonu
int hash1(int key, int M){
	return key % M;
}

//double hashing icin step size i belirler
int hash2(int key, int M){
	key = 1 + (key % (M-1));
	
	return key;
}

//kelimenin buyun harflerini kucuge ceviren fonksiyon
void toLowerCase(char word[15]){
	long i = 0; //strlen long int donduruyor
	
	for(i=0; i<strlen(word); i++){
		if(word[i] >= 'A' && word[i] <= 'Z') //eger harf buyuk ise
			word[i] = word[i] + 'a' -'A'; //kucuge cevir
	}
}

char ** readStopWords(char **stopWords, int *stopWordsCount){
	int i = 0; //dongu indisi
	char temptWord[15];
	FILE *fp;
	
	fp = fopen("stopWords.txt", "r");
	
	if(fp == NULL){
		printf("\nstopWords.txt dosyasi acilamadi");
		exit(1);
	}
	
	stopWords = (char **) malloc (1*sizeof(char));  
	stopWords[i] = (char *) malloc(15 * sizeof(char));
	
	while(fscanf(fp,"%s",temptWord) != EOF){
		strcpy(stopWords[i], temptWord); //eger dosya sonu gelmediyse okunan kelimeyi diziye at
		i++;
		
		stopWords = (char **) realloc (stopWords,(i+1)*sizeof(*stopWords)); 
		stopWords[i] = (char *) malloc (15 * sizeof(char));
		
		if(stopWords == NULL){
			printf("\nyer ayrilamadi");
			exit(1);
		}
	}
	
	fclose(fp);
	*stopWordsCount = i;
	return stopWords;
}
