#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Degisken bilgilerinin tutuldugu struct
struct Variable{
	char* type; 
	char* name;
};

int findDeclaredVariables(FILE* file);
int findNextPrime(int num);
struct Variable* createHashTable(int numberOfVariables, int* m);
int hornersMethod(char* str);
int h1(int key, int m);
int h2(int key, int m);
int hash(int key, int i, int m);
int isTypeKeyword(char *str);
void insert(struct Variable* hashTable, char* type, char* name, int m, int debugMode);
int lookup(struct Variable* hashTable, char* name, int m);
void run(FILE* file, int debugMode);
void printHashTable(struct Variable* hashTable, int m);

int main(){
	char fileName[32], choice;
	int debugMode;

	do{
		system("cls");
		printf("Dosya ismini giriniz: ");
		scanf("%s", fileName);
		
		FILE* file = fopen(fileName, "r");
	    if (file == NULL) {
	        printf("Dosya acilamadi!\n");
	    }else{
	    	printf("\n0- Normal Mod\n");
			printf("1- Debug Mod\n");
			printf("Seciminiz: ");
			scanf("%d", &debugMode);
			run(file, debugMode);
		}		
		fclose(file);
		printf("\n\nDevam etmek icin enter tusuna basiniz...");
		choice = getch();
	}while(choice == 13);
	
	printf("\nCikis yapiliyor...");
	return 0;
}

/*
@brief Verilen dosyadaki programda kac tane degisken tanimlandigini bulur.

@param FILE, programin bulundugu dosya.

@return Toplam degisken sayisini dondurur.
*/
int findDeclaredVariables(FILE* file){
    char line[256];
    char delim[] = " ,;(){}=<>+-/*!\n";
    int variableCount = 0;

    while(fgets(line, sizeof(line), file)){
        char *token = strtok(line, delim);
        int isType = isTypeKeyword(token); // Satir basinda int/char/float tanimi yapilip yapilmadigini tutar.

        while(token && isType){ // Ilgili satirin basinda int/char/float bulunuyorsa 
            if(token[0] == '_'){ // ve degisken ismin '_' ile basliyorsa degisken sayisi bir arttirilir.
                variableCount++;
            }
            token = strtok(NULL, delim);
        }
    }

    return variableCount;
}

/*
@brief Verilen sayidan buyuk ilk asal sayiyi dondurur.

@param n, sayi.

@return Verilen sayidan buyuk ilk asal sayiyi dondurur.
*/
int findNextPrime(int num){
	int i, j;
	int nextPrime = 0, limit = num*2; // Asal sayi [num, num*2] araliginda aranir.
	int* prime = (int*) calloc(limit, sizeof(int));	// Ilk degerler 0 ile baslatilir. 0 -> asal, 1 -> asal degil.
	
	prime[0] = 1;
	prime[1] = 1;
	
	for(i=2; i*i<limit; i++){ // Sieve of eratosthenes yontemiyle asal sayilar bulunur.
        if(!prime[i]){
            for(j=i*i; j<limit; j+=i){
                prime[j] = 1;
            }
        }
    }
	
	i = num + 1;
	while(i<limit && !nextPrime){ // Verilen sayidan buyuk ilk asal sayi bulunur.
		if(!prime[i]){
			nextPrime = i;
		}
		i++;
	}
	
	free(prime);
	return nextPrime;
}

/*
@brief Verilen degisken sayisindan buyuk ilk asal sayi boyutunda hash tablosu olusturur.

@param numberOfVariables, degisken sayisi.
@param m, hash tablosunun boyutu.

@return Olusturulan m boyutlu hash tablosunu dondurur.
*/
struct Variable* createHashTable(int numberOfVariables, int* m){
	*m = findNextPrime(numberOfVariables*2);
	struct Variable* hashTable = (struct Variable*) calloc(*m, sizeof(struct Variable)); // type ve name NULL olarak baslatilir.
	
	return hashTable;
}

/*
@brief Verilen string'in sayisal degerini Horner's metoduyla bulur.

@param str, verilen string.

@return Olusturulan sayisal deger dondurulur.
*/
int hornersMethod(char* str){
	int key = 0, len = strlen(str), i;
	int base = 1 << (len-1); // 2^(L-1)
	
	// key = 2^(L-1) * str[0] + 2^(L-2) * str[1] + ... + 2^(0) * str[L-1]
	for(i=0; i<len; i++){
		key += base * str[i];
		base >>= 1;
	}

	return key;
}

/*
@brief Verilen key'in m'e gore modunu alarak hash degerini olusturur.

@param key, verilen sayisal deger.
@param m, hash tablosunun boyutu.

@return Olusturulan hash degeri dondurulur.
*/
int h1(int key, int m){
	return key % m;
}

/*
@brief Verilen key'in m'e gore modunu alarak hash degerini olusturur.

@param key, verilen sayisal deger.
@param m, hash tablosunun boyutu.

@return Olusturulan hash degeri dondurulur.
*/
int h2(int key, int m){
	return 1 + (key % m);
}

/*
@brief Verilen key'in double hash degerini olusturur.

@param key, verilen sayisal deger.
@param i, hash2 fonksiyonu carpani.
@param m, hash tablosunun boyutu.

@return Olusturulan hash degeri dondurulur.
*/
int hash(int key, int i, int m){
	// m degeri 3'ten kucukse hash2 fonksiyonu key mod m seklinde calisir.
	return m > 3 ? ((h1(key, m) + i*h2(key, m-3)) % m) : ((h1(key, m) + i*h2(key, m)) % m);
}

/*
@brief Verilen string'in int/char/float'a esit olup olmadigi kontrol edilir.

@param str, string ifade.

@return String, int/char/float'a esitse 1, diger durumlarda 0 dondurur.
*/
int isTypeKeyword(char *str){
	if(str == NULL)
		return 0;
    return !strcmp(str, "int") || !strcmp(str, "char") || !strcmp(str, "float");
}

/*
@brief Verilen degiskeni hash tablosuna ekler.

@param hashTable, hash tablosu.
@param type, degiskenin tipi.
@param name, degiskenin ismi.
@param m, hash tablosunun boyutu.
@param debugMode, debug-normal mod secimi.

@return
*/
void insert(struct Variable* hashTable, char* type, char* name, int m, int debugMode){
	int i = 0, index;
	int key = hornersMethod(name);
	int firstIndex = hash(key, 0, m);

	do{
        index = hash(key, i, m);
		
        if(hashTable[index].name == NULL){ // Tablodaki deger NULL ise degisken tabloya eklenir.
            hashTable[index].type = strdup(type);
            hashTable[index].name = strdup(name);
            if(debugMode)
            	printf("-> '%s' degiskeni icin %d adresi hesaplandi, %d adresine yerlestirildi!\n", name, firstIndex, index);
            return;
        }

        i++;
    }while(i < m);
	printf("Tablo dolu!\n");
}

/*
@brief Verilen degiskenin hash tablosunda olup olmadigini kontrol eder.

@param hashTable, hash tablosu.
@param name, degiskenin ismi.
@param m, hash tablosunun boyutu.

@return Degisken tabloda varsa 1, yoksa 0 dondurur.
*/
int lookup(struct Variable* hashTable, char* name, int m){
	int i = 0, index;
	int key = hornersMethod(name);
	
	if(!m){ // Hicbir degisken tanimlanmadan degisken kullanilmaya calisildiysa 0 dondurulur.
		return 0;
	}
	
	do{
        index = hash(key, i, m);
		
		if(hashTable[index].name == NULL){ // Tablodaki deger NULL ise degisken tabloda yoktur.
        	return 0;
		}
        else if(!strcmp(hashTable[index].name, name)){ // Tablodaki deger ile verilen isim ayniysa degisken tabloda vardir.
        	return 1;
		}

        i++;
    }while(i < m);

	return 0;
}

/*
@brief Verilen dosyadaki programý calistirir.

@param FILE, programin bulundugu dosya.
@param debugMode, debug-normal mod secimi.

@return
*/
void run(FILE* file, int debugMode){
	int m, numberOfVariables = findDeclaredVariables(file);
	struct Variable* hashTable = createHashTable(numberOfVariables, &m);
	int errorCount = 0;
    char line[256];
    char delim[] = " ,;(){}=<>+-/*!\n";
    
    system("cls");
    if(debugMode){
    	printf(" \t\t\t=== DEBUG MOD ===\n\n");
	}else{
		printf(" \t\t=== NORMAL MOD ===\n\n");
	}
    
	fseek(file, 0, SEEK_SET); // Dosyanin basina donulur.
	
    while(fgets(line, sizeof(line), file)){
        char* token = strtok(line, delim);
        int isType = isTypeKeyword(token); // Satir basinda int/char/float tanimi yapilip yapilmadigini tutar.
		char* type = token; // Degisken tipini tutar.
		
        while(token){        	
            if(token[0] == '_'){
            	if(isType && !lookup(hashTable, token, m)){ // Degisken tanimlaniyorsa ve hash tablosunda yoksa tabloya eklenir.
            		insert(hashTable, type, token, m, debugMode);
				}else if(isType && lookup(hashTable, token, m)){ // Degisken tanimlaniyorsa ve hash tablosunda varsa hata mesaji ekrana yazdirilir.
					printf("HATA: '%s' degiskeni daha once deklere edilmistir!\n", token);
					errorCount++;
				}else if(!lookup(hashTable, token, m)){ // Degisken hash tablosunda yoksa hata mesaji ekrana yazdirilir.
					printf("HATA: '%s' degiskeni deklere edilmemistir!\n", token);
					errorCount++;
				}                            
            }
            token = strtok(NULL, delim);
        }
    }
    
    if(!errorCount){
    	printf("\nProgram hicbir hata ile karsilasilmadan sonlandirilmistir!\n");
	}
    
    if(debugMode){
    	printf("\nDeklere edilmis degisken sayisi: %d\n", numberOfVariables);
    	printf("Sembol tablosunun uzunlugu: %d\n\n", m);
    	printHashTable(hashTable, m);
	}
	
	free(hashTable);
}

/*
@brief Verilen hash tablosunu ekrana yazdirir.

@param hashTable, hash tablosu.
@param m, hash tablosunun boyutu.

@return
*/
void printHashTable(struct Variable* hashTable, int m){
	int i;
	printf("+-------+--------+-------------------+\n");
	printf("| Adres |  Tip   |   Degisken Ismi   |\n");
	printf("+-------+--------+-------------------+\n");
	for(i=0; i<m; i++){
		printf("| %5d | %6s | %-17s |\n", i, hashTable[i].type, hashTable[i].name);
	}
	printf("+-------+--------+-------------------+\n");
}
