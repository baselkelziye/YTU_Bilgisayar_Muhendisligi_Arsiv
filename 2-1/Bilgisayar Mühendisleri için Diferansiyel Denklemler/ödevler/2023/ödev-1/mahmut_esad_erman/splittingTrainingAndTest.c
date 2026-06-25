#include <stdio.h>

void splittingIntoTrainingAndTest(FILE* topic, FILE* training, FILE* test);


int main() {
    FILE *topic;
    FILE *training;
    FILE *test;

    // Splitting group1 samples
    topic = fopen("dataset/news/business.txt", "r");
    training = fopen("dataset/businessTraining.txt", "w");
    test = fopen("dataset/businessTest.txt", "w");

    splittingIntoTrainingAndTest(topic, training, test);

    fclose(topic);
    fclose(training);
    fclose(test);

    // Splitting group2 samples
    topic = fopen("dataset/news/sport.txt", "r");
    training = fopen("dataset/sportTraining.txt", "w");
    test = fopen("dataset/sportTest.txt", "w");

    splittingIntoTrainingAndTest(topic, training, test);

    fclose(topic);
    fclose(training);
    fclose(test);

    printf("Your data is splitted into two parts.");

    return 0;
}

void splittingIntoTrainingAndTest(FILE* topic, FILE* training, FILE* test){
    int i;
    int c;

    for (i = 0; i < 80; i++){
        while ((c = getc(topic)) != '\n'){
            fputc(c, training);
        }
        fputc(c, training);
    }

    for (i = 0; i < 20; i++){
        while ((c = getc(topic)) != '\n'){
            fputc(c, test);
        }
        fputc(c, test);
    }
}

