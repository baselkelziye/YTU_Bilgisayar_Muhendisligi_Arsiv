#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef TEXTCLASSIFICATION_MAKEHOTVECTOR_H
#define TEXTCLASSIFICATION_MAKEHOTVECTOR_H

#endif //TEXTCLASSIFICATION_MAKEHOTVECTOR_H

#define NUMBEROFWORDS 7000

/*----------------------------Dictionary Structure-------------------------------------*/
// Struct to hold each key-value pair
struct KeyValuePair {
    char key[50];
    int value;
};

// Dictionary structure
struct Dictionary {
    struct KeyValuePair items[NUMBEROFWORDS]; // Defined as an array with a capacity of 100, can be adjusted as needed
    int length; // Keeps track of the number of items in the dictionary
}typedef dict;

// makes letters short
void toLowerStr(char *p){
    for ( ; *p; ++p) *p = tolower(*p);
}

void addToDictionary(dict* dictionary, const char* key) {
    if (dictionary->length < NUMBEROFWORDS) { // If there is space in the dictionary
        strcpy(dictionary->items[dictionary->length].key, key);
        dictionary->items[dictionary->length].value = dictionary->length;
        dictionary->length++;
    } else {
        printf("Dictionary is full, cannot add new item.\n");
    }
}

// Function to get the value for a given key in the dictionary, if key is not found returns -1
int getValue(dict* dictionary, const char* key) {
    for (int i = 0; i < dictionary->length; i++) {
        if (strcmp(dictionary->items[i].key, key) == 0) {
            return dictionary->items[i].value;
        }
    }
    return -1; // Return -1 if the key is not found (default value)
}
/*---------------------------------------------------------------------------------*/

// Calculates number of lines in a txt file
int calculateLineNumber(char* path){
    FILE* file;
    file = fopen(path, "r");
    int c;
    int i = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            i++;
        }
    }
    fclose(file);
    return i;
}

// Makes dictionary from a file
void makeDictionary(FILE* file, dict* dictionary){
    char word[50];
    rewind(file);
    while (fscanf(file, "%s", word) == 1){
        toLowerStr(word);
        if(getValue(dictionary, word) == -1){
            addToDictionary(dictionary, word);
            if(dictionary->length == NUMBEROFWORDS){
                printf("you have reached word limit!!");
                return;
            }
        }
    }
}

// Saves dictionary to a txt file
void saveDictionary(FILE* file, dict* dictionary){
    int i;
    for (i = 0; i < dictionary->length; i++){
        if(strcmp(dictionary->items[i].key, "\0")  != 0){
            fprintf(file, "%s\n", dictionary->items[i].key);
        } else{
            printf("%d)\n", i);
        }
    }
}

// Loads dictionary from a txt file
void loadDictionary(char dictionaryFile[200], dict* dictionary){
    dictionary->length = 0;
    FILE* file;
    file = fopen(dictionaryFile, "r");
    while (fscanf(file, "%s", dictionary->items[dictionary->length].key) == 1){
        dictionary->items[dictionary->length].value = dictionary->length;
        dictionary->length++;
    }
    fclose(file);
}

// Makes hot vector from a file
void makeHotVector(FILE* file, dict generalDict, bool* hotVector){
    char words[1000][50];
    int i, j, n, c;

    n = 0;
    j = 0;
    while ((c = getc(file)) != '\n'){
        if(c == ' ' && j != 0){
            words[n][j] = '\0';
            toLowerStr(words[n]);

            // Check if the same word is written
            i = 0;
            while(i<n-1 && strcmp(words[i], words[n]) != 0){
                i++;
            }
            if(i<n && strcmp(words[i], words[n]) == 0)
                n--;
            n++;
            j = 0;
        } else if (c != ' '){
            words[n][j] = c;
            j++;
        }
    }

    // Set all values 0
    for (i = 0; i < generalDict.length; i++){
        hotVector[i] = 0;
    }
    // Set the positions of the words in the vector to 1
    for (i = 0; i < n; i++){
        hotVector[getValue(&generalDict, words[i])] = 1;
    }

}

