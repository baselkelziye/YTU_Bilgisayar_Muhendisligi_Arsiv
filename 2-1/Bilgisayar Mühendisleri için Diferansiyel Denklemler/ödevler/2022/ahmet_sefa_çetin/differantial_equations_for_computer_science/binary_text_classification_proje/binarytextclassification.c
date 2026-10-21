#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void convertFromFile(char *fileName, char matrix[100][3][20]);

int main() {
    srand(time(NULL));

    int i, j, k;

    char goodComments[100][3][20];
    char badComments[100][3][20];
    convertFromFile("goodComments.txt", goodComments);
    convertFromFile("badComments.txt", badComments);

    char ***allComments;

    allComments = (char ***)malloc(200 * sizeof(char **));
    for (i = 0; i < 200; i++) {
        allComments[i] = (char **)malloc(3 * sizeof(char *));
        for (j = 0; j < 3; j++) {
            allComments[i][j] = (char *)malloc(3 * sizeof(char));
        }
    }

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 3; j++) {
            allComments[i][j] = goodComments[i][j];
            allComments[i + 100][j] = badComments[i][j];
        }
    }

    char **dictionary, **newDictionary;

    dictionary = (char **)malloc(600 * sizeof(char *));
    newDictionary = (char **)malloc(600 * sizeof(char *));
    for (i = 0; i < 600; i++) {
        dictionary[i] = (char *)malloc(20 * sizeof(char));
        newDictionary[i] = (char *)malloc(20 * sizeof(char));
    }

    k = 0;
    for (i = 0; i < 200; i++) {
        for (j = 0; j < 3; j++) {
            strcpy(dictionary[k], allComments[i][j]);
            k++;
        }
    }

    int wordCounter = 0;
    for (i = 0; i < 600; i++) {
        j = 0;
        while (j < wordCounter && strcmp(newDictionary[j], dictionary[i]) != 0) j++;
        if (j == wordCounter) {
            strcpy(newDictionary[wordCounter], dictionary[i]);
            wordCounter++;
        }
    }

    for (i = 0; i < 600; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    newDictionary = (char **)realloc(newDictionary, wordCounter * sizeof(char *));
    dictionary = newDictionary;

    // Dictionary yazdirma
    // for (i = 0; i < wordCounter; i++) {
    //     printf("%s\n", dictionary[i]);
    // }

    int **hotVectors;

    hotVectors = (int **)calloc(wordCounter, sizeof(int *));
    for (i = 0; i < wordCounter; i++) {
        hotVectors[i] = (int *)calloc(200, sizeof(int));
    }

    for (i = 0; i < wordCounter; i++) {
        for (j = 0; j < 200; j++) {
            for (k = 0; k < 3; k++) {
                if (strcmp(dictionary[i], allComments[j][k]) == 0) {
                    hotVectors[i][j] = 1;
                }
            }
        }
    }

    int **partitionMatrix, partitionOutputs[200], **testVectors, **trainingVectors;
    int trainingOutputs[160] = {0}, testOutputs[40] = {0};

    for (i = 0; i < 100; i++) {
        partitionOutputs[i] = 1;
    }
    for (i = 100; i < 200; i++) {
        partitionOutputs[i] = -1;
    }

    partitionMatrix = (int **)calloc(wordCounter, sizeof(int *));
    for (i = 0; i < wordCounter; i++) {
        partitionMatrix[i] = (int *)calloc(200, sizeof(int));
    }
    for (i = 0; i < wordCounter; i++) {
        for (j = 0; j < 200; j++) {
            partitionMatrix[i][j] = hotVectors[i][j];
        }
    }

    trainingVectors = (int **)malloc(wordCounter * sizeof(int *));
    for (i = 0; i < wordCounter; i++) {
        trainingVectors[i] = (int *)malloc(160 * sizeof(int));
    }
    testVectors = (int **)malloc(wordCounter * sizeof(int *));
    for (i = 0; i < wordCounter; i++) {
        testVectors[i] = (int *)malloc(40 * sizeof(int));
    }

    // test vektörlerinin bulunduğu 40 sütunlu matrise partitionMatrix ten rastgele seçilen vektörleri koydum
    // aynı zamanda outputları da aktarıyorum
    int testMatrixIndexes[40];  // all comments dizisindeki hangi indexteki cümleler seçildi o indexleri kaydedelim
    int randomNumber;
    i = 0;
    while (i < 40) {
        randomNumber = rand() % 200;
        if (partitionMatrix[0][randomNumber] != 2) {
            // indexleri tutmak için
            testMatrixIndexes[i] = randomNumber;
            // *********************
            for (j = 0; j < wordCounter; j++) {
                testVectors[j][i] = partitionMatrix[j][randomNumber];
            }
            testOutputs[i] = partitionOutputs[randomNumber];
            partitionMatrix[0][randomNumber] = 2;
            i++;
        }
    }
    // **************************************************************************************************

    // partitionMatrixte testVectors e atılan vektörlerin haricindekileri eğitim kümesine atıyorum
    // aynı zamanda outputları da aktarıyorum
    j = 0;
    for (i = 0; i < 200; i++) {
        if (partitionMatrix[0][i] != 2) {
            for (k = 0; k < wordCounter; k++) {
                trainingVectors[k][j] = partitionMatrix[k][i];
            }
            trainingOutputs[j] = partitionOutputs[i];
            j++;
        }
    }
    // **************************************************************************************************

    // dosyaya test kümesini yazdırma -1 ve 1 labelları ile
    /*
    FILE *dosya;

    dosya = fopen("dosya.txt", "w");

    for (i = 0; i < 40; i++) {
        if (testOutputs[i] == 1) {
            fprintf(dosya, "%s\n", "1");
        } else {
            fprintf(dosya, "%s\n", "-1");
        }
        for (j = 0; j < 3; j++) {
            fprintf(dosya, "%s\n", allComments[testMatrixIndexes[i]][j]);
        }
    }
    */
    // **************************************************************************************************

    // değişken tanımlamalarının yapıldığı kod bloğu
    double eps, eps2, eps3, total, errors[160], errors2[160], errors3[160], loss;

    double tolerans = 0.001;

    double gdTestResults[40], sgdTestResults[40], adamTestResults[40];

    int f, f2, f3, trueResults, random;

    double alpha, beta1, beta2, m, v, m1, v1, t, total2;

    double *w;
    w = (double *)calloc(wordCounter, sizeof(double));
    double *w2;
    w2 = (double *)calloc(wordCounter, sizeof(double));
    double *w3;
    w3 = (double *)calloc(wordCounter, sizeof(double));

    clock_t gdStartTime;
    clock_t gdFinishTime;
    double gdElapsedTime;
    clock_t sgdStartTime;
    clock_t sgdFinishTime;
    double sgdElapsedTime;
    clock_t adamStartTime;
    clock_t adamFinishTime;
    double adamElapsedTime;

    FILE *gdDatasFile;
    FILE *sgdDatasFile;
    FILE *adamDatasFile;

    gdDatasFile = fopen("gdDatasFile.txt", "w");
    sgdDatasFile = fopen("sgdDatasFile.txt", "w");
    adamDatasFile = fopen("adamDatasFile.txt", "w");

    // **************************************************************************************************
    //printf("size of dictionary: %d\n\n", wordCounter);

    int y;
    for (y = 0; y < 5; y++) {
        printf("%d. deneme: \n", y + 1);

        for (i = 0; i < wordCounter; i++) {
            w[i] = rand();
            w[i] = ((double)w[i] / RAND_MAX) * 2 - 1;
            w2[i] = w[i];
            w3[i] = w[i];
        }

        // Gradient descent yaptığımız kod bloğu

        eps = 15;
        f = 0;

        gdStartTime = clock();
        do {
            for (k = 0; k < wordCounter; k++) {
                total2 = 0;
                for (i = 0; i < 160; i++) {
                    total = 0;
                    for (j = 0; j < wordCounter; j++) {
                        total += w[j] * trainingVectors[j][i];
                    }
                    total2 += (trainingOutputs[i] - tanh(total)) * trainingVectors[k][i] * pow(1 / cosh(total), 2);
                }
                total2 = (total2 * -2) / 160;
                w[k] -= eps * total2;
            }
            i = 0;
            loss = 0;
            while (i < 160) {
                total = 0;
                for (j = 0; j < wordCounter; j++) {
                    total += w[j] * trainingVectors[j][i];
                }
                loss += pow(trainingOutputs[i] - tanh(total), 2);
                i++;
            }
            loss /= 160;

            // printf("%lf\n", loss);

            gdFinishTime = clock();

            gdElapsedTime = (double)(gdFinishTime - gdStartTime) / CLOCKS_PER_SEC;

            fprintf(gdDatasFile, "%d %f %f\n", f, loss, gdElapsedTime);

            f++;
        } while (loss > tolerans && f < 10000);

        // for (i = 0; i < wordCounter; i++) {
        //    printf("%lf\n", w[i]);
        //}

        // **************************************************************************************************

        // gradient descent sonuçlarını test ettiğim kod bloğu

        printf("\n\nGD Test results: \n");

        trueResults = 0;
        for (i = 0; i < 40; i++) {
            total = 0;
            for (j = 0; j < wordCounter; j++) {
                total += w[j] * testVectors[j][i];
            }

            gdTestResults[i] = tanh(total);

            if (testOutputs[i] == 1 && gdTestResults[i] > 0.5) {
                trueResults++;
            } else if (testOutputs[i] == -1 && gdTestResults[i] < 0.5) {
                trueResults++;
            }

            // printf("%lf\n", gdTestResults[i]);
        }

        printf("\nloss: %lf\n", loss);
        printf("iteration number: %d\n", f);
        printf("true results: %d\n", trueResults);
        printf("elapsed time: %lf", gdElapsedTime);

        // **************************************************************************************************

        printf("\n");

        // Stochastic Gradient descent yaptığımız kod bloğu

        eps2 = 0.9;
        f2 = 0;

        sgdStartTime = clock();
        do {
            total2 = 0;
            random = rand() % 160;
            for (i = 0; i < wordCounter; i++) {
                total = 0;
                for (j = 0; j < wordCounter; j++) {
                    total += w2[j] * trainingVectors[j][random];
                }
                total2 = (trainingOutputs[random] - tanh(total)) * trainingVectors[i][random] * pow(1 / cosh(total), 2);
                total2 = (total2 * -2) / 160;
                w2[i] -= eps * total2;
            }

            i = 0;
            loss = 0;
            while (i < 160) {
                total = 0;
                for (j = 0; j < wordCounter; j++) {
                    total += w2[j] * trainingVectors[j][i];
                }

                loss += pow(tanh(total) - trainingOutputs[i], 2);
                i++;
            }
            loss /= 160;

            // printf("%lf\n", loss);

            sgdFinishTime = clock();

            sgdElapsedTime = (double)(sgdFinishTime - sgdStartTime) / CLOCKS_PER_SEC;

            fprintf(sgdDatasFile, "%d %f %f\n", f2, loss, sgdElapsedTime);

            f2++;
        } while (loss > tolerans && f2 < 1000000);

        // for (i = 0; i < wordCounter; i++) {
        //     printf("%lf\n", w2[i]);
        // }

        // **************************************************************************************************

        // Stochastic gradient descent sonuçlarını test ettiğim kod bloğu

        printf("\n\nSGD Test results: \n");

        trueResults = 0;
        for (i = 0; i < 40; i++) {
            total = 0;
            for (j = 0; j < wordCounter; j++) {
                total += w2[j] * testVectors[j][i];
            }

            sgdTestResults[i] = tanh(total);

            if (testOutputs[i] == 1 && sgdTestResults[i] > 0.5) {
                trueResults++;
            } else if (testOutputs[i] == -1 && sgdTestResults[i] < -0.5) {
                trueResults++;
            }

            // printf("%lf\n", sgdTestResults[i]);
        }

        printf("\nloss: %lf\n", loss);
        printf("iteration number: %d\n", f2);
        printf("true results: %d\n", trueResults);
        printf("elapsed time: %lf", sgdElapsedTime);

        // **************************************************************************************************

        printf("\n");

        // Adam yaptigimiz kod blogu

        eps3 = 0.001, alpha = 0.000001, beta1 = 0.9, beta2 = 0.999, m = 0, v = 0, t = 0;
        f3 = 0;

        adamStartTime = clock();
        do {
            random = rand() % 160;
            total2 = 0;
            for (i = 0; i < wordCounter; i++) {
                total = 0;
                for (j = 0; j < wordCounter; j++) {
                    total += w3[j] * trainingVectors[j][random];
                }
                t = t + 1;
                total2 = (trainingOutputs[random] - tanh(total)) * trainingVectors[i][random] * pow(1 / cosh(total), 2);
                total2 = (total2 * -2) / 160;
                m = beta1 * m + (1 - beta1) * total2;
                v = beta2 * v + (1 - beta2) * pow(total2, 2);
                m1 = m / (1 - pow(beta1, t));
                v1 = v / (1 - pow(beta2, t));
                w3[i] -= eps3 * (m1 / (sqrt(v1) + alpha));
            }

            i = 0;
            loss = 0;
            while (i < 160) {
                total = 0;
                for (j = 0; j < wordCounter; j++) {
                    total += w3[j] * trainingVectors[j][i];
                }

                loss += pow(tanh(total) - trainingOutputs[i], 2);
                i++;
            }
            loss /= 160;

            // printf("%lf\n", loss);

            adamFinishTime = clock();

            adamElapsedTime = (double)(adamFinishTime - adamStartTime) / CLOCKS_PER_SEC;

            fprintf(adamDatasFile, "%d %f %f\n", f3, loss, adamElapsedTime);

            f3++;
        } while (loss > tolerans && f3 < 100000);

        // for (i = 0; i < wordCounter; i++) {
        //     printf("%lf\n", w3[i]);
        // }

        // **************************************************************************************************

        // ADAM sonuçlarını test ettiğim kod bloğu

        printf("\n\nADAM Test results: \n");

        trueResults = 0;
        for (i = 0; i < 40; i++) {
            total = 0;
            for (j = 0; j < wordCounter; j++) {
                total += w3[j] * testVectors[j][i];
            }

            adamTestResults[i] = tanh(total);

            if (testOutputs[i] == 1 && adamTestResults[i] > 0.8) {
                trueResults++;
            } else if (testOutputs[i] == -1 && adamTestResults[i] < -0.8) {
                trueResults++;
            }

            // printf("%lf\n", adamTestResults[i]);
        }

        printf("\nloss: %lf\n", loss);
        printf("iteration number: %d\n", f3);
        printf("true results: %d\n", trueResults);
        printf("elapsed time: %lf", adamElapsedTime);
        // **************************************************************************************************

        printf("\n***********************************************\n\n");
    }

    return 0;
}

void convertFromFile(char *fileName, char matrix[100][3][20]) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        exit(1);
    }

    char line[3 * 20];
    int lineCount = 0;

    while (fgets(line, sizeof(line), file) != NULL && lineCount < 100) {
        line[strcspn(line, "\n")] = '\0';

        char *word = strtok(line, " ");
        int wordCount = 0;

        while (word != NULL && wordCount < 3) {
            strncpy(matrix[lineCount][wordCount], word, 20);
            matrix[lineCount][wordCount][19] = '\0';
            word = strtok(NULL, " ");
            wordCount++;
        }

        lineCount++;
    }

    fclose(file);
}
