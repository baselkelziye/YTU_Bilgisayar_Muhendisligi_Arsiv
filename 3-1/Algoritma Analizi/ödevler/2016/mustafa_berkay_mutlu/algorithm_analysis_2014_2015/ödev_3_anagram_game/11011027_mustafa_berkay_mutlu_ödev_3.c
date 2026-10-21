 /***************************************************************************
 * main.c                                                                   *
 *                                                                          *
 *                         ANAGRAM WORDS GAME                               *
 *                                                                          *
 *                                                                          *
 * Modified in 24 December 2014                                             *
 * Written by Mustafa Berkay Mutlu, 11011027                                *
 * www.berkaymutlu.com                                                      *
 *                                                                          *
 * Please feel free to copy this source code.                               *
 *                                                                          *
 * DESCRIPTION:                                                             *
 *  This program creates a hash table from given words file and starts a    *
 * word game which the player needs to find meaningful anagram words of a   *
 * given random word.                                                       *
 *                                                                          *
 ***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR -1

// Ayarlar:
#define DEBUG_MODE 1 // 1 olursa ekrana bilgilendirme yazilir, 0 olursa sadece sonuc yazilir.
#define WORDS_FILENAME "words.txt"
#define WORD_LENGTH 5 // Her kelimenin sonunda bir de NULL karakteri ('\0') eklendigi icin, toplam 5 karakter yer ayrildi.
#define HASH_TABLE_LENGTH 8495 // 5096/0.6
#define M 8495 // 5096/0.6
#define M2 8494 // 5096/0.6 - 1
#define ARRAY_USER_WORDS_LENGTH 100 // Kullanicinin basariyla girdigi anagram kelimelerin saklanacagi dizinin boyutunu belirtir.


void CreateHashTable(char[][WORD_LENGTH], char[]); // Hash tablosunu dosyadan okur ve parametre olarak verilen diziye yazar.
int LookHashTable(char[][WORD_LENGTH], char[WORD_LENGTH], int); // Parametre olarak verilen kelime, hash tablosunda var mi kontrol eder. Varsa 1, yoksa 0 dondurur.
void MoveToHashTable(char[][WORD_LENGTH], char[WORD_LENGTH], int, int); // Parametre olarak verilen kelimeyi Hash tablosuna yerleştirir. Rekursif calisir.
void PrintHashTable(char[][WORD_LENGTH]); // Hash tablosunu ekrana yazdirir.
int h(int, int); // HashIndex uretmek icin kullanilan fonksiyondur. h1 ve h2 fonksiyonlarini kullanir.
int h1(int); // 1. Hash fonksiyonu
int h2(int); // 2. Hash fonksiyonu
int Key(char[WORD_LENGTH]); // Horner Kurali kullanilarak key degeri uretir.
int CheckAnagram(char[WORD_LENGTH], char[WORD_LENGTH]); // Parametre olarak verilen kelimeler anagram ise 1, degil ise 0 dondurur. Kelimeler birbirinin aynisiysa 0 dondurur.
void Analyze(char[][WORD_LENGTH]); // Raporda Uygulama bolumunde istenen analizi yapar.

int main()
{
    int i, j; // Dongu degiskenleri.
    char hashTable[HASH_TABLE_LENGTH][WORD_LENGTH] = {0}; // Hash tablosu.
    char userEnteredWords[ARRAY_USER_WORDS_LENGTH][WORD_LENGTH] = {0};
    char randomWord[WORD_LENGTH] = {0}; // Kullaniciya gosterilecek olan rasgele secilmis kelimeyi tutar.
    char userChosenWord[WORD_LENGTH] = {0}; // Kullanicinin girdigi kelimeyi tutar.
    int randomInteger; // Rasgele kelime secmek icin kullanilan rasgele sayinin tutuldugu degisken.
    int point = 0; // Kullanicinin toplam puanini tutar.
    char menuChoice; // Menude secilen numarayi tutar.
    char wordsFileName[100]; // Words dosyasinin ismini tutar.
    int menuChoiceCompleted = 0; // Menude secim basarili bir sekilde yapilirsa 1, yapilmazsa 0 olur.
    int userEnteredWordCount = 0; // Kullanicinin basariyla girdigi anagram kelime sayisini tutar.
    int letterCheck = 0; // Kullanicinin girdigi kelimeyi daha once girilen kelimelerle kontrol etmek icin kullanilir.

    srand(time(NULL));

    do{
        printf("\n\n:::: MENU ::::\n\n");
        printf("[1] Create new hash table (read from words file and save to a new hashtable file). \n");
        printf("[2] Read hash table from a file (read from existing hashtable file). \n");
        menuChoice = getch();

        switch(menuChoice){
            case '1':
                printf("Please enter the words file's name (ex: %s)> ", WORDS_FILENAME);
                scanf("%s", wordsFileName);
                CreateHashTable(hashTable, wordsFileName); // Dosyadan okuma islemi yapilir.
                menuChoiceCompleted = 1;

                break;
            case '2':
                printf("This part is not implemented because I tried 3 days in a row just to figure out what is wrong with fseek, fwrite and fread; and angrily quit.\n");
                menuChoiceCompleted = 0;
                break;
            default:
                printf("You hit the wrong button, try again. \n\n");
                break;
        }
    }while(menuChoiceCompleted == 0);

    if(DEBUG_MODE) Analyze(hashTable);

    do{
        randomInteger = rand() % HASH_TABLE_LENGTH;

        for(i=0;i<WORD_LENGTH;i++){
            randomWord[i] = hashTable[randomInteger][i];
        }
    }while(randomWord[0] == 0);

    // Eger sabit bir kelime ile deneme yapmak isterseniz asagidaki yorumu kaldirin ve kelimenin harflerini randomWord degiskenine girin.
/*
    randomWord[0] = 'G';
    randomWord[1] = 'O';
    randomWord[2] = 'W';
    randomWord[3] = 'L';
    randomWord[4] = '\0';
*/

    printf("\n\nYour word is \"%s\". GO!\n", randomWord);
    printf("If you want to quit, enter letter \"q\" or \"Q\".\n\n");

    do{
        printf("Enter the anagram word of %s> ", randomWord);
        scanf("%4s", userChosenWord);
        printf("You entered \"%s\" ",userChosenWord);

        if((userChosenWord[0] != 'q' && userChosenWord[0] != 'Q') || userChosenWord[1] != 0){
            if(DEBUG_MODE) printf("Key: %d HashIndex (when i=0): %d %s\n", Key(userChosenWord), h(Key(userChosenWord), 0),
                                  CheckAnagram(randomWord, userChosenWord) == 1 ? "Its an anagram word" : "Its not an anagram word");
            if(CheckAnagram(randomWord, userChosenWord) && LookHashTable(hashTable, userChosenWord, 0)){
                for(i=0;i<userEnteredWordCount && letterCheck == 0;i++){
                    letterCheck = 1;
                    for(j=0;j<WORD_LENGTH-1;j++){
                        if(userEnteredWords[i][j] != userChosenWord[j])
                            letterCheck = 0;
                    }
                }
                if(letterCheck == 1){
                    printf("You already entered %s. Try again.\n", userChosenWord);
                    letterCheck = 0;
                }
                else {
                    printf("%s is a meaningful anagram word. You gain 5 points!\n", userChosenWord);
                    point += 5;
                    printf("Your total point is: %d\n\n", point);

                    for(j=0;j<WORD_LENGTH-1;j++){
                        userEnteredWords[userEnteredWordCount][j] = userChosenWord[j];
                    }
                    userEnteredWords[userEnteredWordCount][WORD_LENGTH-1] = '\0';
                    userEnteredWordCount++;
                }

            }
            else {
                printf("%s is NOT a meaningful anagram word. You lost 5 points!\n", userChosenWord);
                point -= 5;
                printf("Your total point is: %d\n\n", point);
            }
        }
    }while((userChosenWord[0] != 'q' && userChosenWord[0] != 'Q') || userChosenWord[1] != 0);

    printf("Your total point is %d\n", point);

    getchar();
    getchar();

    if(DEBUG_MODE) PrintHashTable(hashTable);

    getchar();
    return 0;
}

int CheckAnagram(char word1[WORD_LENGTH], char word2[WORD_LENGTH]){
    int i = 0; // Dongu degiskeni.
    int first[26] = {0}, second[26] = {0}; // Iki kelimenin de harflerinin isaretlendigi diziler.
    int comparison = 1;

    // Kelimeler tamamen ayniysa 0 dondurur:
    for(i=0;i<WORD_LENGTH;i++){
        if(word1[i] != word2[i]){
            comparison = 0;
        }
    }
    if(comparison == 1) return 0; // Kelimeler tamamen aynidir.

    i = 0;
    while (word1[i] != '\0')
    {
        first[word1[i]-'A']++;
        i++;
    }

    i = 0;

    while (word2[i] != '\0')
    {
        second[word2[i]-'A']++;
        i++;
    }

    for (i = 0; i < 26; i++)
    {
        if (first[i] != second[i])
            return 0;
    }

    return 1;
}

int LookHashTable(char hashTable[][WORD_LENGTH], char word[WORD_LENGTH], int i){
    int key = Key(word);
    int hashIndex = h(key, i);
    int comparisonResult = 1; // 1 olmasi kelimelerin esit oldugu, 0 olmasi kelimelerin esit olmadigi anlamina gelir.
    int j;

    if(hashTable[hashIndex][0] != 0){
        for(j=0;j<WORD_LENGTH-1;j++){
            if(word[j] != hashTable[hashIndex][j])
                comparisonResult = 0;
        }

        if(comparisonResult == 1){
            if(DEBUG_MODE) printf("%s kelimesi %d. adreste bulundu. i: %d\n", word, hashIndex, i);
            return 1;
        }
        else { // HashTable'da kelime var, ancak aradigimiz kelime degil. Bir sonraki indekse bakilir:
            if(DEBUG_MODE) printf("%s kelimesi %d. adreste bulunamadi.\n", word, hashIndex);
            return LookHashTable(hashTable, word, i+1);
        }
    }
    else { // HashTable'da baktigimiz yer bos, kelime yok demektir.
        if(DEBUG_MODE) printf("%s kelimesi %d. adreste bulunamadi.\n", word, hashIndex);
        if(DEBUG_MODE) printf("%s kelimesi HashTable'da bulunamadi. i: %d\n", word, i);
        return 0;
    }

}

void CreateHashTable(char hashTable[][WORD_LENGTH], char wordsFileName[]){
    char word[WORD_LENGTH];
    char readStatus; // fscanf ile okuma yapilirken donen degerin saklandigi degisken.
    int key;

    FILE *p_hashFile = fopen(wordsFileName, "r");

    if(!p_hashFile){
        printf("Error occurred while opening \"%s\" file for read. Exiting..\n", wordsFileName);
        exit(ERROR);
    }

    do {
        readStatus = fscanf(p_hashFile, "%s", word);
        if(DEBUG_MODE) printf("Read word: %s\n", word);
        key = Key(word);

        MoveToHashTable(hashTable, word, key, 0);

   } while (readStatus != EOF);

   fclose(p_hashFile);
}

void MoveToHashTable(char hashTable[][WORD_LENGTH], char word[WORD_LENGTH], int key, int i){
    int j;
    int hashIndex = h(key, i);
    if(DEBUG_MODE) printf("key: %d i: %d hashIndex: %d\n", key, i, hashIndex);

    if(hashTable[hashIndex][0] == 0){
        if(DEBUG_MODE) printf("%d adresi bos, kelime yerlestiriliyor: %s\n", hashIndex, word);
        for(j=0;j<WORD_LENGTH-1;j++){
            hashTable[hashIndex][j] = word[j];
        }
        hashTable[hashIndex][WORD_LENGTH-1] = '\0';
    }
    else{
        if(DEBUG_MODE) printf("%d adresi dolu, su kelime var: %s\n", hashIndex, hashTable[hashIndex]);
        if(DEBUG_MODE) printf("Yeni hashIndex uretiliyor\n");
        MoveToHashTable(hashTable, word, key, i + 1);
    }
}

void PrintHashTable(char hashTable[][WORD_LENGTH]){
    int i;

    printf("----- Hash Table -----\n");
    for(i=0;i<HASH_TABLE_LENGTH;i+=5){

        printf("%4d) ", i);
        printf("%5s", hashTable[i]);
        printf("\t%4d) ", i+1);
        printf("%5s", hashTable[i+1]);
        printf("\t%4d) ", i+2);
        printf("%5s", hashTable[i+2]);
        printf("\t%4d) ", i+3);
        printf("%5s", hashTable[i+3]);
        printf("\t%4d) ", i+4);
        printf("%5s", hashTable[i+4]);
        printf("\n");
    }
}

int h(int key, int i){
    return ((h1(key) + i*h2(key)) % M);
}

int h1(int key){
    return (key % M);
}

int h2(int key){
    return (1 + (key % M2));
}


int Key(char word[WORD_LENGTH]){
    int i, key;

    for(i = 0, key = 0;i < WORD_LENGTH-1;i++){
        key = 61*key + (int)word[i];
    }

    return key;
}

void Analyze(char hashTable[][WORD_LENGTH]){
    int i; // Dongu degiskeni.

    char dizi[40][WORD_LENGTH] = {"FACE\0",
    "FACT\0",
    "GOLE\0",
    "GOLF\0",
    "HOLE\0",
    "HOLK\0",
    "BISK\0",
    "BITE\0",
    "DAME\0",
    "DAMN\0",
    "NIMS\0",
    "NINE\0",
    "PAIN\0",
    "PAIR\0",
    "LIVE\0",
    "LOAD\0",
    "YARD\0",
    "YARE\0",
    "ZERO\0",
    "ZEST\0",
    "FACX\0",
    "FACZ\0",
    "GOLT\0",
    "HOLF\0",
    "HOLR\0",
    "BIST\0",
    "BITF\0",
    "DAMF\0",
    "DAMZ\0",
    "NIMT\0",
    "NINF\0",
    "PAIY\0",
    "PAIZ\0",
    "LIVT\0",
    "LOAR\0",
    "YARF\0",
    "YART\0",
    "ZERT\0",
    "ZESZ\0",
    };


    printf("\n\n:::::::: ANALYZE ::::::::\n");
    for(i=0;i<40;i++){
        LookHashTable(hashTable, dizi[i], 0);
        printf("\n");
    }

    printf("\n\n:::::::: ANALYZE END ::::::::\n");

}
