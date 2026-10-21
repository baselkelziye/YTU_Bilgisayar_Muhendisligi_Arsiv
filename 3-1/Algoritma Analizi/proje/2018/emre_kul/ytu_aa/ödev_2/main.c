#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "limits.h"

#ifndef min
    #define min(a,b) ((a) < (b) ? (a) : (b))
#endif//min tanımlanmamışsa tanımlar
#define STR_SIZE 100//string boyutu
#define DICTIONARY_SIZE 267569//hash boyutu
#define TEST_SIZE 256//test girişleri boyutu
#define MAXIMUM_EDIT_DISTANCE 10//NONE gösterimi için kullanılcak uzaklık.

struct Word{
    char str[STR_SIZE];//kelime
};
typedef struct Word Word;//Kelimeler için kullanılacak yapı.
/*
	Verilen kelimenin hash içinde addresini bulur ve geri döndürür.
	Aynı zamanda gelen kelimenin tüm harflerini küçük hale getirir.
	@char *str = hash içersinde aranancak kelime.
	@return = kelimenin adresini döndürür.
	*/
unsigned long getHashAdress(char *);
/*
	Sözlüğü okur ve hash yaratır.
	@char *filename = okunacak sözlüğün dosya ismi.
	@return = yaratılan hash'i döndürür.
*/
Word* readDictionary(char *);
/*
	Dosyaya kaydedilmiş hash'i okur ve geri döndürür.
	@char *filename = okunacak hash dosyasının ismi.
	@return = hash'i döndürür.
*/
Word *readHashedDictionary(char *);
/*
	Hash'i dosyaya yazar.
	@char *filename = Yazılacak dosyanın ismi.
	@Word *hashedDictionary = Dosyaya yazılacak olan hash.
*/
void writeHashedDictionary(char *,Word *);
/*
	Dosyadan inputları okur.
	@char *filename = İnputların okunacağı dosyanın ismi.
	@int *inputSize = Okunan kelime sayısını döndürme için kullanılacak değişken.
	@return = Okunan kelimeleri döndürür. 
*/
Word* readInputs(char *,int *);

/*
	Kelimenin tüm kelimelere olan uzaklığını ölçer ve en yakınını bulur.
	@char *searchStr = Sözlükte aranacak kelime.
	@Word *dictionary = Hash Sözlüğü
*/
void levensteinEditDistance(char *,Word *);
/*
	Sonuçları dosyaya yazar.
	@char* searchStr = Aranan kelime.
	@char* closestStr = Bulunan en benzer kelime.
	@int distance[STR_SIZE][STR_SIZE] = 2 kelime arasındaki fark matrisi. 
	@int minDistance = 2 kelime arasındaki minumum uzaklık
*/
void writeResult(char*,char*,int [STR_SIZE][STR_SIZE],int);
/*
	Kelimenin hash'in içinde olup olmadığı bilgisini döndürür.
	@char *searchStr = Hash içersinde aranacak kelime. 
	Word *hashedDictionary = Aramanın yapılacağı hash.
	*/
char isInHashTable(char *,Word *);
/*
	3 sayı arasından en küçüğünü döndürür.
	@int x = sayı 1
	@int y = sayı 2
	@int z = sayı 3
	@return = en küçük sayı değeri
*/
int getMin(int ,int ,int );

int main(){
    int inputSize;//giriş olarak verilen kelime sayısı.
    unsigned long i;//genel amaçlı iter
    Word *dictionary,//sözlük 
		 *inputs;//arama yapılacak giriş kelimeleri
    //dictionary = readDictionary("dictionary");
    //writeHashedDictionary("hashedDictionary",dictionary);
    dictionary = readHashedDictionary("hashedDictionary");
    inputs = readInputs("test.txt",&inputSize);
    for(i = 0;i < inputSize;i++){
        levensteinEditDistance(inputs[i].str,dictionary);
    }
    free(dictionary);
    return 0;
}

Word* readDictionary(char *filename){
    unsigned long i,//genel amaçlı iter
			      addr;//adres tutan değişken
    char tmpStr[STR_SIZE];//kelime okuma için kullanılacak değişken
    Word *readedWords = (Word*)malloc(DICTIONARY_SIZE*sizeof(Word));
    FILE *dictionaryFile = fopen(filename,"r");
    i = 0;
    printf("OK");
    while(fscanf(dictionaryFile,"%s%*[^\n]",tmpStr) != EOF){
        addr = getHashAdress(tmpStr)%DICTIONARY_SIZE;
        while(readedWords[addr].str[0] != 0){
            addr = (++addr)%DICTIONARY_SIZE;
        }
        strcpy(readedWords[addr].str,tmpStr);
        i++;
    }
    fclose(dictionaryFile);
    return readedWords;
}

Word *readHashedDictionary(char *filename){
    long i = 0;//genel amaçlı iter
    char tmpStr[STR_SIZE];//okuma için kullanılacak string
    Word *readedWords = (Word*)malloc(DICTIONARY_SIZE*sizeof(Word));
    FILE *hashFile = fopen(filename,"r");
    for(i = 0;i < DICTIONARY_SIZE;i++){
        fscanf(hashFile,"%s\n",tmpStr);
        strcpy(readedWords[i].str,tmpStr);
    }
    fclose(hashFile);
    return readedWords;
}

void writeHashedDictionary(char *filename,Word *words){
    unsigned long i;//genel amaçlı iter
    FILE *writeFile = fopen(filename,"w");
    for(i= 0;i <  DICTIONARY_SIZE;i++){
        fprintf(writeFile,"%s\n",words[i].str);
    }
    fclose(writeFile);
}

Word* readInputs(char *filename,int *inputSize){
    int i = 0;//genel amaçlı iter
    Word *testInputs = (Word*)malloc(TEST_SIZE*sizeof(Word));
    FILE *testFile = fopen(filename,"r");
    while(i < TEST_SIZE && fscanf(testFile,"%s\n",testInputs[i].str) != EOF){
        i++;
    }
    *inputSize = i;
    fclose(testFile);
    return testInputs;
}

unsigned long getHashAdress(char *str){
    int i,//genel amaçlı iter
		length;//string boyutu(her döngüde strlen ile hesaplamamak için)
    unsigned long addr = 0;//hash adres değişkeni
    i = 0;
    length = strlen(str);
    while(i < length && str[i] != 0){
        str[i] = (str[i] <= 'Z' && str[i] >= 'A') ? str[i]-'A'+'a' : str[i];
        addr += str[i]*26*i;
        i++;
    }
    return addr;
}

int getMin(int x,int y,int z){
    return min(min(x,y),z);
}

char isInHashTable(char *str,Word *hashedDictionary){
    char strFinded = 0;//kelimenin bulunup bulunmadığı bilgisini tutan değişken
    unsigned long strAddr,//kelimenin hash adresi
		loopCount = DICTIONARY_SIZE;//kelimeyi aramak için kullanılacak maximum adım sayısı
    strAddr = getHashAdress(str);
    while(loopCount > 0 && !strFinded){
        if(strAddr >= DICTIONARY_SIZE)
            strAddr = 0;
        if(strcmp(str,hashedDictionary[strAddr].str) == 0)
            strFinded = 1;
        strAddr++;
        loopCount--;
    }
    return strFinded;
}

void levensteinEditDistance(char *searchStr,Word *dictionary){
    unsigned long i;//genel amaçlı iter
    int minDistance = INT_MAX,//en yakın kelimenin uzaklığını tutan değişken
        minAddr = INT_MAX,//en yakın kelimenin adresini tutan değişken
        distanceMtr[STR_SIZE][STR_SIZE],//kelimenin aranan kelimeyle olan uzaklık matrisi
        minDistanceMtr[STR_SIZE][STR_SIZE],//en yakın kelimenin aranan kelimeyle olan uzaklık matrisi
        lenStr1,//aranan kelimenin uzunluğu
        lenStr2,//karşılaştırılan kelimenin uzunluğu
        col,//column için kullanılcak genel amaçlı iter
        row;//row için kullanılcak genel amaçlı iter

    if(isInHashTable(searchStr,dictionary)){
        minDistance = 0;
    }
    else{
        lenStr1 = strlen(searchStr);
        for(i = 0;i < DICTIONARY_SIZE;i++){
            if(dictionary[i].str[0] != 0){
                lenStr2 = strlen(dictionary[i].str);        
                for(col = 0;col <= lenStr1;col++){
                    distanceMtr[0][col] = col;
                }

                for(row = 1;row <= lenStr2;row++){
                    distanceMtr[row][0] = row;
                    for(col = 1;col <= lenStr1;col++){   
                        if(searchStr[col-1] != dictionary[i].str[row-1])
                            distanceMtr[row][col] = getMin(distanceMtr[row-1][col-1]+2,distanceMtr[row-1][col]+1,distanceMtr[row][col-1]+1);
                        else
                            distanceMtr[row][col] = distanceMtr[row-1][col-1]; 
                    }
				}

                if(distanceMtr[lenStr2][lenStr1] < minDistance && distanceMtr[lenStr2][lenStr1] < MAXIMUM_EDIT_DISTANCE){
                    minAddr = i;
                    minDistance = distanceMtr[lenStr2][lenStr1];
                    for(row = 0;row <= lenStr2;row++)
                        for(col = 0;col <= lenStr1;col++)
                            minDistanceMtr[row][col] = distanceMtr[row][col];
                }

            }    
		}
    }
    
	writeResult(searchStr,dictionary[minAddr].str,minDistanceMtr,minDistance);     
    
}

void writeResult(char *searchStr,char *closestStr,int distance[STR_SIZE][STR_SIZE],int minDistance){
		int i,//genel amaçlı iter aranan kelime için kullanıldı çoğunlukla
			j,//genel amaçlı iter bulunan kelime için kullanıldı çoğunlukla
			changeIndex = 0;//değişiklikleri tutan dizinin indexi
		char changes[100];//2 kelime arasında yapılan değişikliklerin tutulduğu dizi
        FILE *f = fopen("testout.txt","a+");
		fprintf(f,"%s ",searchStr);
		printf("%s Controlling and results saving to 'testout.txt'\n",searchStr);
		if(minDistance >= MAXIMUM_EDIT_DISTANCE)
        	fprintf(f,"NONE\n");	
		else if(minDistance == 0) 
        	fprintf(f,"OK\n");
		else {
			i = strlen(closestStr);
        	j = strlen(searchStr);
			fprintf(f,"%s ",closestStr);
			while(i > 0 && j > 0){
        		if(distance[i][j-1] < distance[i-1][j-1] && distance[i][j-1] <= distance[i-1][j]){
        			changes[changeIndex] = 'D';
					j--;
				}
				else if(distance[i-1][j] < distance[i-1][j-1] && distance[i-1][j] < distance[i][j-1]){
					changes[changeIndex] = 'I';
					i--;
				}
				else if(distance[i][j] == distance[i-1][j-1]){
                	changes[changeIndex] = 'N';
            		i--;
            		j--;
				}
            	else{
                	changes[changeIndex] = 'C';
        			i--;
        			j--;
				}
				changeIndex++;	
			}
			while(i > 0){
				changes[changeIndex] = 'I';
				changeIndex++;
				i--;
			}
			while(j > 0){
				changes[changeIndex] = 'D';
				changeIndex++;
				j--;
			}
			i = 0;//search str index
			j = 0;//closest str index
			while(changeIndex >= 0){
				changeIndex--;
				if(changes[changeIndex] == 'N'){
					fprintf(f,"%c",searchStr[i]);
					i++;
					j++;
				}
				else if(changes[changeIndex] == 'D'){
					fprintf(f," %c(Delete)",searchStr[i]);
					i++;
				}
				else if(changes[changeIndex] == 'I'){
					fprintf(f," %c(Insert)",closestStr[j]);
					j++;
				}
				else if(changes[changeIndex] == 'C'){
					fprintf(f," %c(Change)",closestStr[j]);
					i++;
					j++;
				}
			}
        	fprintf(f,"\n");
		}
}