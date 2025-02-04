#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_VARIABLES 100
#define MAX_SIZE 1000

struct variable{
	char type[10];
	char name[30];
};

struct table{
	struct variable Table[MAX_VARIABLES]; 
	int size;
};

int findTableSize(int n);
int power(int m, int n);
int horner(char* name);
int h(int key, int m, int i);
int h1(int key, int m);
int h2(int key, int m);
void trimString(char *str);
int countCharOccurrences(char* str, char ch);
void insert(char* name, char* type, struct table* myTable, int mode, int* varNum);
int findVariableNumber(char* token, char* reservedWords[]);
void printTable(struct table myTable);
int checkInvalidDeclaration(char *str, char *type);


int main(){
	
	int tableSize=0, varNum, i, n=0, j, sayac, index=0, temp, mode;
    char matrix[MAX_SIZE]; 
	//= "int main() {int _aa, _bb, _cc; char _dd;float _zdg;char _x;char _aa;float _aa; _aa = 5; _xx = 9; _bb = _aa + _dd;}";
    char* reservedWords[3] = {"int", "char", "float"};
    char ch;
    char yedekToken[500];
    char buffer[20];
    char var[20];
    char filename[100];
    FILE* file;
    
    struct table myTable;
    
    printf("Enter the file name (e.g., input.txt): ");
    scanf("%s", filename);
    //strcpy(filename, "test6.c");
    printf("Select mode:\n");
    printf("1. NORMAL\n");
    printf("2. DEBUG\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &mode);
    //mode=2;

    if (mode != 1 && mode != 2) {
        printf("Error: Invalid choice. Please select 1 for NORMAL or 2 for DEBUG.\n");
        return 1;
    }
    
    file = fopen(filename, "r");
    
    if (!file) {
        printf("Error: File '%s' not found.\n", filename);
        return 1;
    }
    
    while ((ch = fgetc(file)) != EOF) {
        matrix[index++] = ch;
        
        if (index >= MAX_SIZE) {
            printf("Error: File size exceeds the maximum limit.\n");
            fclose(file);
            return 1;
        }
    }

    matrix[index] = '\0';

    fclose(file);
    
    
    char* token = strtok(matrix, "{");
    token = strtok(NULL, "{");
    
    strcpy(yedekToken, token);
    
    varNum = findVariableNumber(yedekToken, reservedWords);
    
    tableSize = findTableSize(varNum);
    printf("\n\nTable Size: %d\n\n", tableSize);
    myTable.size = tableSize;
    
    for(i=0; i<myTable.size; i++){
    	strcpy(myTable.Table[i].type,"");
    	strcpy(myTable.Table[i].name,"");
	}
        
    token = strtok(token, ";");

    while (token != NULL) {
        if(token != NULL){
        	trimString(token);        	 
        	for(i=0; i<3; i++){

        		if (strstr(token, reservedWords[i]) != NULL && !checkInvalidDeclaration(token, reservedWords[i])) {
        			strcpy(yedekToken, token);
        			j=0;
        			ch=yedekToken[j];
        			while(ch!='\0'){
        				if(ch=='_'){
        					sayac=0;
        					temp = j;
        					while(ch!=',' && ch!='\0'){
        						buffer[sayac] = ch;
        						sayac++;
        						temp++;
        						ch = yedekToken[temp];
							}
							buffer[sayac] = '\0';
							strcpy(var, buffer);
							insert(var, reservedWords[i], &myTable, mode, &varNum);
						}
						j++;
						ch = yedekToken[j];
					}
			    }
			}
		}
		token = strtok(NULL, ";");
    }
    
    //printf("\nToken2-----------------------\n\n\n\n");
    
    file = fopen(filename, "r");
    index=0;
    if (!file) {
        printf("Error: File '%s' not found.\n", filename);
        return 1;
    }
    
    while ((ch = fgetc(file)) != EOF) {
        matrix[index++] = ch;
        
        if (index >= MAX_SIZE) {
            printf("Error: File size exceeds the maximum limit.\n");
            fclose(file);
            return 1;
        }
    }

    matrix[index] = '\0';

    fclose(file);
    
    token = strtok(matrix, "{");
    token = strtok(NULL, "{");
    
    token = strtok(token, ";");

    while (token != NULL) {
        if(token != NULL){
        	trimString(token);
			strcpy(yedekToken, token);        	 
        	j=0;
			ch=yedekToken[j];
			while(ch!='\0'){
				if(ch=='_'){
					sayac=0;
					temp = j;
					while(ch!=',' && ch!='\0' && ch!=' '){
						buffer[sayac] = ch;
						sayac++;
						temp++;
						ch = yedekToken[temp];
					}
					buffer[sayac] = '\0';
					strcpy(var, buffer);
					if(lookup(var, myTable)==0){
						printf("\n%s is not declared, you can not use it!!!\n", var);
					}
					
				}
			j++;
			ch = yedekToken[j];
			}
			
		}
		token = strtok(NULL, ";");
    }
    
    if(mode==2){
    	printf("\n\nDeclared Variable Number: %d,  Table Size: %d\n", varNum, myTable.size);
    	printTable(myTable);
	}
    
	return 0;
}


/**
 * @brief Verilen stringde, int, char veya float rezerve kelimelerinin hatali tanimlama icin kontrolu.
 * @param str Kontrol edilecek string.
 * @param type Su an islenmekte olan degisken tipi ("int", "char", "float").
 * @return -1 (hatali tanimlama varsa), 0 (herhangi bir sorun yoksa).
 */
int checkInvalidDeclaration(char *str, char *type) {
    // Rezerve kelimeler
    char *reservedWords[3] = {"int", "char", "float"};
    int i = 0;
    char *found;
    char prev, next;

    while (i < 3) {
        found = strstr(str, reservedWords[i]);  // Rezerve kelimeyi bul
        if (found != NULL) {
            // Eger kelimenin basinda olup olmadigini kontrol edelim
            if (found != str) {
                // Kelimenin onceki ve sonraki karakterlerini al
                if (found > str) {
                    prev = *(found - 1);
                } else {
                    prev = ' ';
                }
                next = *(found + strlen(reservedWords[i]));

                // Kelimenin tam bir tip olup olmadigini kontrol et
                if (isspace(prev) || prev == '_' || prev == ',' || prev == '(') {
                    if (isspace(next) || next == ';' || next == ',' || next == ')' || next == '\0') {
                        // Eger tipler uyusuyorsa ve hatali tanimlama varsa kontrol et
                        if (strcmp(reservedWords[i], type) == 0) {
                            if (prev == '_') {
                                return -1;  // Hatali tanimlama
                            }
                        }
                    }
                }
            }
        }
        i++;
    }
    return 0;  // Herhangi bir sorun bulunmadi
}

/**
 * @brief Tabloyu yazdirir.
 * @param myTable Tablo yapisi.
 */
void printTable(struct table myTable){
	int i;
	printf("\n------------------Table-------------------\n\n           Var Type  |  Var Name\n\n");
	for(i=0; i<myTable.size; i++){
		printf("%2d---->%10s%10s\n", i, myTable.Table[i].type, myTable.Table[i].name);
	}
}

/**
 * @brief Verilen stringdeki bosluklari kirpar.
 * @param str Kirpilacak string.
 */
void trimString(char *str) {

  while (isspace((unsigned char)str[0]))

    memmove(str, str + 1, strlen(str));   

  while (isspace((unsigned char)str[strlen(str) - 1]))

    str[strlen(str) - 1] = '\0';

}

/**
 * @brief Degisken ismini ve tipini tabloya ekler.
 * @param name Degisken adi.
 * @param type Degisken tipi.
 * @param myTable Tablo yapisi.
 * @param mode Calisma modu (NORMAL veya DEBUG).
 */
void insert(char* name, char* type, struct table* myTable, int mode, int* varNum) {
    int sayi = horner(name);
    int index;
    int i = 0;                

    if (lookup(name, *myTable) == 1) {
        printf("Cannot insert. The variable '%s' is already declared.\n", name);
        (*varNum)--;
        return;
    }
	index = h(sayi, myTable->size, i);
	if(mode==2){
		printf("For %s calculated first index is: %d ", name, index);
	}
	
    while (i < myTable->size) {
        index = h(sayi, myTable->size, i);
        if (strcmp(myTable->Table[index].name, "") == 0) {
            strcpy(myTable->Table[index].name, name);
            strcpy(myTable->Table[index].type, type);
            if(mode==2){
				printf("Variable '%s' of type '%s' and added to index: %d\n", name, type, index);
			}
            //printf("Variable '%s' of type '%s' added at index: %d\n", name, type, index);
            return;
        }
        i++; 
    }

    printf("Cannot insert. The table is full.\n");
}

/**
 * @brief Verilen degiskenin tabloda olup olmadigini kontrol eder.
 * @param name Aranacak degisken adi.
 * @param myTable Tablo yapisi.
 * @return 1 (bulundu), 0 (bulunamadi), -1 (hata).
 */
int lookup(char* name, struct table myTable) {
    int sayi = horner(name);   
    int index;
    int i = 0;                

    while (i < myTable.size) { 
        index = h(sayi, myTable.size, i); 

        if (strcmp(myTable.Table[index].name, name) == 0) {
            //printf("it found at index: %d\n", index);
            return 1;
        }

        if (strcmp(myTable.Table[index].name, "") == 0) {
            //printf("index is empty, you can put the var to that index %d\n", index);
            return 0;
        }

        i++;
    }

    return -1;
}

/**
 * @brief Verilen karakterin stringde kac kez gectigini bulur.
 * @param str Arama yapilacak string.
 * @param ch Aranacak karakter.
 * @return Karakterin tekrar sayisi.
 */
int countCharOccurrences(char* str, char ch) {
    int i, count=0;
    // Stringi gezerek, her karakteri kontrol ediyoruz
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;  // Karakteri bulduðumuzda sayacý artýrýyoruz
        }
    }
    return count;
    
}

/**
 * @brief Verilen degisken sayisina gore tablo boyutunu hesaplar.
 * @param n Degisken sayisi.
 * @return Hesaplanan tablo boyutu.
 */
int findTableSize(int n){
	int i, flag, isPrime=0;
	n*=2;
	while(!isPrime){
		n++;
		i=2;
		flag = 1;
		while((i<(n/2)) && flag){
			if(n%i==0){
				flag=0;
			}
			i++;
		}
		if(flag==1){
			isPrime=1;
		}
		
	}
	return n;
}

/**
 * @brief Degisken sayisini belirler.
 * @param token Kod parcasi.
 * @param reservedWords Rezerve kelimeler listesi.
 * @return Degisken sayisi.
 */
int findVariableNumber(char* token, char* reservedWords[]){
	int i, varNumber=0;
	char yedekToken[50];
	token = strtok(token, ";");
    
    while (token != NULL) {
        if(token != NULL){
        	trimString(token);
        	 
        	for(i=0; i<3; i++){
        		if (strstr(token, reservedWords[i]) != NULL && !checkInvalidDeclaration(token, reservedWords[i])) {
        			strcpy(yedekToken, token);
			        varNumber+=countCharOccurrences(token, ',');
			        varNumber++;
			    }
			}
		}
		token = strtok(NULL, ";");
    }
    return varNumber;
}

/**
 * @brief Bir sayinin kuvvetini hesaplar.
 * @param m Taban degeri.
 * @param n Us degeri.
 * @return Kuvvet sonucu.
 */
int power(int m, int n){
	int i, result=1;
	for(i=0; i<n;i++)
		result*=m;
	return result;
}

/**
 * @brief Verilen degisken adina gore Horner metodu kullanarak hash degeri hesaplar.
 * @param name Degisken adi.
 * @return Hash degeri.
 */
int horner(char* name){
	int len = strlen(name), prime = 13, i;
	int result=0;
	for(i=1;i<len;i++){
		result+=power(prime, len-i-1)*(tolower(name[i])-'a'+1);
	}
	
	return result;
}

/**
 * @brief Hash fonksiyonunun ilk kisimlarini hesaplar.
 * @param key Hash anahtari.
 * @param m Tablo boyutu.
 * @return Hash degerinin ilk kismi.
 */
int h1(int key, int m){
	return key%m;
}

/**
 * @brief Hash fonksiyonunun ikinci kisimlarini hesaplar.
 * @param key Hash anahtari.
 * @param m Tablo boyutu.
 * @return Hash degerinin ikinci kismi.
 */
int h2(int key, int m){
	return 1 + (key%(m-3));
}

/**
 * @brief Hash fonksiyonunu hesaplar.
 * @param key Hash anahtari.
 * @param m Tablo boyutu.
 * @param i Tekrar sayisi (ikili hashing icin).
 * @return Hesaplanan hash degeri.
 */
int h(int key, int m, int i){
	return (h1(key, m) + i*h2(key, m)) % m;
}




