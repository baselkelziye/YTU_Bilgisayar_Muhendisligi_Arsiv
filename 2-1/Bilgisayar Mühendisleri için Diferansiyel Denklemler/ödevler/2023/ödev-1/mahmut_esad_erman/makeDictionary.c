#include "functionsForDictionaryAndHotVectors.h"

#define NUMBEROFWORDS 7000

int main() {
    dict generalDictionary;

    generalDictionary.length = 0;

    FILE* businessTraining;
    FILE* sportTraining;
    FILE* dictionaryOutput;

    businessTraining = fopen("dataset/businessTraining.txt", "r");
    sportTraining = fopen("dataset/sportTraining.txt", "r");
    dictionaryOutput = fopen("dataset/dictionary.txt", "w");

    // make general dictionary
    makeDictionary(businessTraining, &generalDictionary);
    makeDictionary(sportTraining, &generalDictionary);

    // save dictionary
    saveDictionary(dictionaryOutput, &generalDictionary);

    // Freeing memory
    fclose(businessTraining);
    fclose(sportTraining);
    fclose(dictionaryOutput);

    printf("Dictionary is saved ");

    return 0;
}
