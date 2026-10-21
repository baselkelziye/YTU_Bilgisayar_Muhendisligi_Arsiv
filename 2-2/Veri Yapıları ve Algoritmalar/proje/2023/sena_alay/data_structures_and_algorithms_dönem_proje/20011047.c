//
//  main.c
//  trieproject
//
//  Created by Sena Alay on 26.05.2023.
//

/*
veri yapıları dönem projesi Sena Alay 20011047 -bu program bir Trie ve n-ary tree veri yapılarını kullanarak sözlük uygulaması sağlar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 sadece ingilizce harfleri kullanarak ödevi yapabildim.türkçe karakterlerle çalışmıyor.
 
 sözlüğe büyük harf lüçük harf ayrımı yapmadan her türlü kelime eklenebiliyor. program çalışırken hepsini lowercase yapıyor
 tolower() fonks ile.
 
 son durumda keypaddeki sayı - harf karşılıkları
 2 abc
 3 def
 4 ghi
 5 jkl
 6 mno
 7 pqrs
 8 tuv
 9 wxyz
 
 */

// Trie ağacı düğümü tanımı
typedef struct TrieNode {
    struct TrieNode *children[10]; //Çocuk düğümler
    char isEndOfWord; //Bir kelimenin sonunu belirtir
    char words[10][50]; //Düğümdeki kelimeler
    char wordNumbers[10][50]; //Kelimenin sayısal karşılıkları
    int wordCount; //Düğümdeki kelime sayısı
} TrieNode;


// Yeni bir düğüm oluşturma işlemi
TrieNode *createNewNodeForTrie() {
    int i;
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    if(newNode == NULL) {
        printf("Hafiza alani yetersiz. Program sonlandiriliyor...");
        exit(1); //exit silmen gerekebilir ödev koşuluna dikkat et
    }
    
    newNode->isEndOfWord = '0';
    newNode->wordCount = 0;

    for (i = 0; i < 10; i++)
        newNode->children[i] = NULL;

    return newNode;
}

// Harften rakama dönüştürme işlemi
int charToDigitKeypad(char c) {
    c = tolower(c); //büyük harf küçük harf fark etmeksizin sözlüğe ne girildiyse hepsi küçük harfe çevrilip öyle işlem yapılıyor.
    switch(c) {
        case 'a': case 'b': case 'c':
            return 2;
        case 'd': case 'e': case 'f':
            return 3;
        case 'g': case 'h': case 'i':
            return 4;
        case 'j': case 'k': case 'l':
            return 5;
        case 'm': case 'n': case 'o':
            return 6;
        case 'p': case 'q': case 'r': case 's':
            return 7;
        case 't': case 'u': case 'v':
            return 8;
        case 'w': case 'x': case 'y': case 'z':
            return 9;
        default:
            return -1;
    }
}


// Kelime ekleme işlemi
void insertToTrie(TrieNode *root, const char *key, const char *number) {
    int level;
    int length = strlen(key);
    int index;
    TrieNode *currentNode = root;
    

    for (level = 0; level < length; level++) {
        index = charToDigitKeypad(key[level]);
        if (!currentNode->children[index])
            currentNode->children[index] = createNewNodeForTrie();

        currentNode = currentNode->children[index];
    }

    currentNode->isEndOfWord = '1';
    strcpy(currentNode->words[currentNode->wordCount], key);
    strcpy(currentNode->wordNumbers[currentNode->wordCount++], number);
}


// Fonksiyon: Trie ağacında bir kelimeyi armak için
void searchInTrie(TrieNode *root, const int key) {
    int i,level;
    int length = snprintf( NULL, 0, "%d", key );
    char strKey[length + 1];
    sprintf(strKey, "%d", key);

    int index;
    TrieNode *searchNode = root;

    for (level = 0; level < length; level++) {
        index = strKey[level] - '0';
        if (!searchNode->children[index]) {
            printf("Sozlukte bu sayinin karsiligi bir kelime yoktur.\n");
            return;
        }

        searchNode = searchNode->children[index];
    }

    if (searchNode != NULL && searchNode->isEndOfWord == '1') {
        for (i = 0; i < searchNode->wordCount; i++) {
            printf("%s\n", searchNode->words[i]);
        }
    } else {
        printf("Sozlukte bu sayinin karsiligi bir kelime yoktur.\n");
    }
}


// Dosyadan programa kelime okuyup ekleme
void insertWordsFromFile(TrieNode *root, const char* fileName) {
    int i;
    char word[100];
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", fileName);
        return;
    }
    while (fgets(word, sizeof(word), file) != NULL) {
        // Remove newline character if present
        int len = strlen(word);
        if(word[len - 1] == '\n') word[len - 1] = '\0';
        
        //bu kısım commente alınmazsa sözlükte kaç kez o kelimenin geçtiğinin çıktısını ekrana verir.
        //örneğin 9642 sözlükte arandığında dört kez yoga çıktısını verir.
        // commente aldım ki yoga,YOGA,yoGa,yoGA,YOGa ŞEKLİNDE sözlükte geçen tüm kombinasyonları versin.
        // Convert to lowercase
        //for(i = 0; word[i]; i++){
        //  word[i] = tolower(word[i]);
        //}
        
        char number[50];
        for(i = 0; word[i]; i++){
            number[i] = '0' + charToDigitKeypad(word[i]);
        }
        number[i] = '\0';

        insertToTrie(root, word, number);
    }
    fclose(file);
}

// Girişin sayılardan oluşup olmadığını kontrol etmek için fonks
int isAllNumeric (const char * s)
{
    if (s == NULL || *s == '\0' || isspace(*s)) //s boşsa yani nullsa, snin işlk karakteri nullsa yani dizi boşsa, ya da ilk karakter boşluksa 0 döndürür
      return 0;
    char * p;
    strtod (s, &p); //double pointing hassas noktayı bulmak için strtod çağrısı
    return *p == '\0'; //p nullsa 1 döner
}

// Tüm kelimeleri Trie ağacından yazdırmak için ek olarak eklediğim fonksiyon
void displayAllWordsInTrie(TrieNode *root) {
    int i;
    if (root == NULL)
        return;

    if (root->isEndOfWord == '1') {
        for (i = 0; i < root->wordCount; i++) {
            printf("%s -> %s\n", root->words[i], root->wordNumbers[i]);
        }
    }

    for (i = 0; i < 10; i++) {
        displayAllWordsInTrie(root->children[i]);
    }
}

int main() {

    TrieNode *root = createNewNodeForTrie();
    insertWordsFromFile(root, "DICTIONARY.TXT");

    // Kullanıcının girisini almak için bir dizi.
    char input[10];
    printf("Sozluk uygulamasina hosgeldiniz. sayisal karsiliğini bildiginiz kelimeyi giriniz.\n");
    printf("> Cikis icin ‘q’ yazmaniz yeterli.\n");

    int running = 1;
    while(running) {
        printf("> ");
        fgets(input, 10, stdin); // stdin'den kullanıcı girişini okumak için
        // Yeni satır karakterini siliyorum çünkü fgets ile okurken yeni satır karakteri ni de dahil ediyor.
        //amaç kullanıcının girdisini bozmamak
        input[strcspn(input, "\n")] = 0;

        if(strcmp(input, "q") == 0) {
            // Kullanıcı "q" girerse programı sonlandır.
            printf("Eger cikis yapmadan once sozluk icindeki tum kelimeler ve sayisal karsiliklari gormek isterseniz 'y' ye basin:\n");
            printf("baska herhangi bir tusa basarsaniz direkt cikis yapilacaktir.\n");
            fgets(input, 10, stdin); //klavyeden 10 karakter al. yukarda tanımlana char input dizisine koy.
            input[strcspn(input, "\n")] = 0; //input dizisindeki ilk yeni satır karakterini al onu \0 ile NULL ile değiş
            
            if(strcmp(input, "y") == 0) {
                printf("Tum kelimeler ve sayisal karsiliklari:\n");
                displayAllWordsInTrie(root);
            }
            running = 0;
        }
        else if(isAllNumeric(input)) {
            int number = atoi(input); // String'i integer'a çevirmece
            // Girilen sayıyı ara
            searchInTrie(root, number);
        } else {
            printf("Lutfen gecerli bir sayi giriniz.\n");
        }
    }
    printf("Cikis yapiliyor...\n");
    return 0;
}
