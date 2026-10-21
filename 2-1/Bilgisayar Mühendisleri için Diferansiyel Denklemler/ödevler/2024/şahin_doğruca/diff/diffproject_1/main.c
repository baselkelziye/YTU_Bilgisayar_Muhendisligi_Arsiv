#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define TRAINING_SIZE 160

void fillDict(FILE *file, char ***dict_ref, char ****texts_ref, int *textLine_ref, int *dictCap_ref, int *dictLen_ref)
{
    char line[1000];
    char *token = NULL;
    int lineCount = 0;
    int rowCount = 0;

    while (fgets(line, 1000, file) != NULL)
    {
        lineCount = 0;
        line[strcspn(line, "\n")] = 0;
        token = strtok(line, " ");

        while (token != NULL)
        {
            bool alreadyExists = false;
            for (int i = 0; i < *dictLen_ref; i++)
            {
                if (strcmp(token, (*dict_ref)[i]) == 0)
                {
                    alreadyExists = true;
                    break;
                }
            }
            if (!alreadyExists)
            {
                (*dict_ref)[*dictLen_ref] = (char *)malloc(sizeof(char) * (strlen(token) + 1));
                strcpy((*dict_ref)[*dictLen_ref], token);
                (*dictLen_ref)++;
            }

            (*texts_ref)[*textLine_ref][lineCount] = (char *)malloc(sizeof(char) * (strlen(token) + 1));
            strcpy((*texts_ref)[*textLine_ref][lineCount], token);

            if (*dictLen_ref == (*dictCap_ref))
            {
                (*dictCap_ref) *= 2;
                (*dict_ref) = (char **)realloc((*dict_ref), sizeof(char *) * (*dictCap_ref));
            }

            token = strtok(NULL, " ");
            lineCount++;
        }

        (*texts_ref)[*textLine_ref] = (char **)realloc((*texts_ref)[*textLine_ref], sizeof(char *) * lineCount);
        (*textLine_ref)++;

        rowCount++;
    }
}

void createDict(char ***dict_ref, char ****texts_ref, int *dictCap_ref)
{
    (*dict_ref) = (char **)malloc(sizeof(char *) * (*dictCap_ref));
    int dictLen = 0;
    char *token = NULL;
    int textLine = 0;

    FILE *file = fopen("texts.txt", "r");

    fillDict(file, dict_ref, texts_ref, &textLine, dictCap_ref, &dictLen);

    (*dict_ref) = (char **)realloc((*dict_ref), sizeof(char *) * dictLen);
    (*dictCap_ref) = dictLen;

    fclose(file);
}

bool contains(char *word, char **text)
{
    for (int i = 0; i < 1000; i++)
    {
        if (text[i] == NULL)
            break;

        if (strcmp(word, text[i]) == 0)
        {
            return true;
        }
    }

    return false;
}

float compute_cost(bool **hotVectors, float *labels, int dictCap, float *weights)
{
    float cost = 0;
    for (int i = 0; i < TRAINING_SIZE; i++)
    {
        float prediction = 0;
        for (int j = 0; j < dictCap; j++)
        {
            prediction += tanh((float)hotVectors[i][j] * weights[j]);
        }
        cost += pow(prediction - labels[i], 2);
    }
    cost /= (2 * TRAINING_SIZE);
    return cost;
}

void compute_gradient(bool **hotVectors, float *labels, int dictCap, float *weights, float **grad_ref)
{
    for (int i = 0; i < dictCap; i++)
    {
        (*grad_ref)[i] = 0;
        for (int j = 0; j < TRAINING_SIZE; j++)
        {
            (*grad_ref)[i] += (tanh((float)hotVectors[j][i] * weights[i]) - labels[j]) * (float)hotVectors[j][i] * (1 / pow(cosh((float)hotVectors[j][i] * weights[i]), 2));
        }
        (*grad_ref)[i] /= TRAINING_SIZE;
    }
}

void compute_gradient_sgd(bool **hotVectors, float *labels, int dictCap, float *weights, float **grad_ref, int randomCount)
{
    int k = 0, l = 0;
    for (int i = 0; i < dictCap; i++)
    {
        (*grad_ref)[i] = 0;
        int usedIndexes[randomCount];
        int usedIndexCount = 0;
        for (int k = 0; k < randomCount; k++)
        {
            int j = rand() % TRAINING_SIZE;
            for (int l = 0; l < usedIndexCount; l++)
            {
                if (usedIndexes[l] == j)
                {
                    k--;
                    continue;
                }
            }
            usedIndexes[usedIndexCount] = j;
            (*grad_ref)[i] += (tanh((float)hotVectors[j][i] * weights[i]) - labels[j]) * (float)hotVectors[j][i] * (1 / pow(cosh((float)hotVectors[j][i] * weights[i]), 2));
        }
        (*grad_ref)[i] /= randomCount;
    }
}

void gradient_descent(float **c_hist, float ***w_hist, bool **hotVectors, float *labels, int dictCap, float *weights, float alpha, int num_iters)
{
    float *grad = (float *)malloc(sizeof(float) * dictCap);
    for (int i = 0; i < num_iters; i++)
    {
        compute_gradient(hotVectors, labels, dictCap, weights, &grad);
        for (int j = 0; j < dictCap; j++)
        {
            weights[j] -= alpha * grad[j];
        }

        if (i < 100000)
        {
            for (int j = 0; j < dictCap; j++)
                (*w_hist)[i][j] = weights[j];
            (*c_hist)[i] = compute_cost(hotVectors, labels, dictCap, weights);
        }

        if (i % (int)ceil(num_iters / 10) == 0)
            printf("iter: %d, cost: %f\n", i, (*c_hist)[i]);
    }

    free(grad);
}

void gradient_descent_sgd(float **c_hist, float ***w_hist, bool **hotVectors, float *labels, int dictCap, float *weights, float alpha, int num_iters, int randomCount)
{
    float *grad = (float *)malloc(sizeof(float) * dictCap);
    for (int i = 0; i < num_iters; i++)
    {
        compute_gradient_sgd(hotVectors, labels, dictCap, weights, &grad, randomCount);
        for (int j = 0; j < dictCap; j++)
        {
            weights[j] -= alpha * grad[j];
        }

        if (i < 100000)
        {
            for (int j = 0; j < dictCap; j++)
                (*w_hist)[i][j] = weights[j];
            (*c_hist)[i] = compute_cost(hotVectors, labels, dictCap, weights);
        }

        if (i % (int)ceil(num_iters / 10) == 0)
            printf("iter: %d, cost: %f\n", i, (*c_hist)[i]);
    }

    free(grad);
}

void adam(float **c_hist, float ***w_hist, bool **hotVectors, float *labels, int dictCap, float *weights, float alpha, int num_iters, float beta1, float beta2, float epsilon)
{
    float *grad = (float *)malloc(sizeof(float) * dictCap);
    float *m = (float *)malloc(sizeof(float) * dictCap);
    memset(m, 0, sizeof(float) * dictCap);
    float *v = (float *)malloc(sizeof(float) * dictCap);
    memset(v, 0, sizeof(float) * dictCap);

    for (int i = 1; i <= num_iters; i++)
    {
        compute_gradient(hotVectors, labels, dictCap, weights, &grad);

        for (int j = 0; j < dictCap; j++)
        {
            m[j] = beta1 * m[j] + (1 - beta1) * grad[j];
            v[j] = beta2 * v[j] + (1 - beta2) * pow(grad[j], 2);

            float m_hat = m[j] / (1 - pow(beta1, i));
            float v_hat = v[j] / (1 - pow(beta2, i));

            weights[j] -= alpha * m_hat / (sqrt(v_hat) + epsilon);
        }

        if (i < 100000)
        {
            for (int j = 0; j < dictCap; j++)
                (*w_hist)[i - 1][j] = weights[j];
            (*c_hist)[i - 1] = compute_cost(hotVectors, labels, dictCap, weights);
        }

        if (i % (int)ceil(num_iters / 10) == 0)
            printf("iter: %d, cost: %f\n", i, (*c_hist)[i - 1]);
    }

    free(grad);
    free(m);
    free(v);
}

void gd_test(float *weights, bool **hotVectors, float *labels, int dictCap)
{
    int i, count = 0, isTrue;
    for (i = TRAINING_SIZE; i < 200; i++)
    {
        float prediction = 0;
        for (int j = 0; j < dictCap; j++)
            prediction += (float)hotVectors[i][j] * weights[j];

        prediction = tanh(prediction);
        isTrue = fabs(labels[i] - prediction) < 0.5 ? 1 : 0;
        count += isTrue;
        printf("iter: %d, Prediction: %f, Label: %.1f, isTrue: %d\n", i, prediction, labels[i], isTrue);
    }

    printf("True Count : %d\n", count);
}

void get_start_comparison(FILE *file, float *temp_weights, float **weights, int dictCap, float **c_hist, float ***w_hist, bool **hotVectors, float *labels, float alpha, int num_iters, void (*func)(float **c_hist, float ***w_hist, bool **hotVectors, float *labels, int dictCap, float *weights, float alpha, int num_iters))
{
    int i;
    for (i = 0; i < dictCap; i++)
        (*weights)[i] = temp_weights[i];

    clock_t start, end;

    start = clock();
    (*func)(c_hist, w_hist, hotVectors, labels, dictCap, *weights, alpha, num_iters);
    end = clock();

    fprintf(file, "%f,", (double)(end - start) / CLOCKS_PER_SEC);
    for (i = 0; i < num_iters; i++)
    {
        if (i != num_iters - 1)
            fprintf(file, "%f,", (*c_hist)[i]);
        else
            fprintf(file, "%f\n", (*c_hist)[i]);
    }
}

void sgd_start(float **c_hist, float ***w_hist, bool **hotVectors, float *labels, int dictCap, float *weights, float alpha, int num_iters)
{
    gradient_descent_sgd(c_hist, w_hist, hotVectors, labels, dictCap, weights, alpha, num_iters, 1);
}

void adam_start(float **c_hist, float ***w_hist, bool **hotVectors, float *labels, int dictCap, float *weights, float alpha, int num_iters)
{
    float beta1 = 0.9, beta2 = 0.999;
    adam(c_hist, w_hist, hotVectors, labels, dictCap, weights, alpha, num_iters, beta1, beta2, 1e-8);
}

void comparison_for5value(float **weights, int dictCap, float **c_hist, float ***w_hist, bool **hotVectors, float *labels, float alpha, int num_iters)
{
    int p = 0, i;

    FILE *file = fopen("costs.txt", "w");
    float temp_weights[dictCap];

    for (p = 0; p < 5; p++)
    {
        for (i = 0; i < dictCap; i++)
            temp_weights[i] = (float)rand() / RAND_MAX;

        get_start_comparison(file, temp_weights, weights, dictCap, c_hist, w_hist, hotVectors, labels, alpha, num_iters, &gradient_descent);
        get_start_comparison(file, temp_weights, weights, dictCap, c_hist, w_hist, hotVectors, labels, alpha, num_iters, &sgd_start);
        get_start_comparison(file, temp_weights, weights, dictCap, c_hist, w_hist, hotVectors, labels, alpha, num_iters, &adam_start);
    }

    fclose(file);
}

void start_for_get_weights(void (*func)(float **c_hist, float ***w_hist, bool **hotVectors, float *labels, int dictCap, float *weights, float alpha, int num_iters), FILE *file, float **weights, int dictCap, float **c_hist, float ***w_hist, bool **hotVectors, float *labels, float alpha, int num_iters, float *temp_weights)
{
    int i;
    for (i = 0; i < dictCap; i++)
        (*weights)[i] = temp_weights[i];

    (*func)(c_hist, w_hist, hotVectors, labels, dictCap, *weights, alpha, num_iters);

    for (i = 0; i < num_iters; i++)
    {
        for (int j = 0; j < dictCap; j++)
        {
            if (j != dictCap - 1)
                fprintf(file, "%f,", (*w_hist)[i][j]);
            else
                fprintf(file, "%f\n", (*w_hist)[i][j]);
        }
    }
}

void get_weights(float **weights, int dictCap, float **c_hist, float ***w_hist, bool **hotVectors, float *labels, float alpha, int num_iters)
{
    int i, j;
    float temp_weights[dictCap];
    FILE *file = fopen("weights.txt", "w+");

    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < dictCap; i++)
            temp_weights[i] = -5.0 + (float)rand() / ((float)RAND_MAX / 10.0);

        start_for_get_weights(&gradient_descent, file, weights, dictCap, c_hist, w_hist, hotVectors, labels, alpha, num_iters, temp_weights);
        // start_for_get_weights(&sgd_start, file, weights, dictCap, c_hist, w_hist, hotVectors, labels, alpha, num_iters, temp_weights);
        // start_for_get_weights(&adam_start, file, weights, dictCap, c_hist, w_hist, hotVectors, labels, alpha, num_iters, temp_weights);
    }

    fclose(file);
}

int main()
{
    char **dict;
    int dictCap = 100;
    int i = 0, j = 0;

    char ***texts = (char ***)malloc(sizeof(char **) * 200);
    for (i = 0; i < 200; i++)
        texts[i] = (char **)malloc(sizeof(char *) * 100);

    createDict(&dict, &texts, &dictCap);

    bool **hotVectors;
    hotVectors = (bool **)malloc(sizeof(bool *) * 200);
    for (i = 0; i < 200; i++)
    {
        hotVectors[i] = (bool *)malloc(sizeof(bool) * dictCap);
        for (j = 0; j < dictCap; j++)
            hotVectors[i][j] = contains(dict[j], texts[i]);
    }

    float *labels = (float *)malloc(sizeof(float) * 200);
    for (i = 0; i < 200; i++)
    {
        if (i < 80 || (i >= 160 && i < 180))
            labels[i] = 1;
        else
            labels[i] = -1;
    }

    srand(time(NULL));

    float *weights = (float *)malloc(sizeof(float) * dictCap);

    char inp = 'a';

    int epochs;
    float **w_hist;
    float *c_hist;

    while (inp != '0' && inp != 'q')
    {
        printf("1. Gradient Descent\n2. Stochastic Gradient Descent\n3. Adam\n4. Get Weights\n5. Comparison\n0. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &inp);

        clock_t start, end;

        for (i = 0; i < dictCap; i++)
            weights[i] = (float)rand() / RAND_MAX;

        int num_iters = 10000;
        float alpha = 0.01;

        if (inp != '0' && inp != 'q')
        {
            printf("Enter number of iterations: ");
            scanf("%d", &num_iters);

            printf("Enter learning rate: ");
            scanf("%f", &alpha);
        }

        epochs = (num_iters < 100000 ? num_iters : 100000);

        w_hist = (float **)malloc(sizeof(float *) * epochs);
        for (i = 0; i < epochs; i++)
            w_hist[i] = (float *)malloc(sizeof(float) * dictCap);

        c_hist = (float *)malloc(sizeof(float) * epochs);

        switch (inp)
        {
        case '1':
            start = clock();

            gradient_descent(&c_hist, &w_hist, hotVectors, labels, dictCap, weights, alpha, epochs);
            end = clock();
            break;
        case '2':
            printf("Enter number of random samples: ");
            int randomCount = 1;
            scanf("%d", &randomCount);
            start = clock();
            gradient_descent_sgd(&c_hist, &w_hist, hotVectors, labels, dictCap, weights, alpha, epochs, randomCount);
            end = clock();
            break;
        case '3':
        {
            float beta1 = 0.9, beta2 = 0.999;
            printf("Enter beta1: ");
            scanf("%f", &beta1);
            printf("Enter beta2: ");
            scanf("%f", &beta2);
            start = clock();
            adam(&c_hist, &w_hist, hotVectors, labels, dictCap, weights, alpha, epochs, beta1, beta2, 1e-8);
            end = clock();
            break;
        }
        case '4':
            get_weights(&weights, dictCap, &c_hist, &w_hist, hotVectors, labels, alpha, num_iters);
            break;
        case '5':
            comparison_for5value(&weights, dictCap, &c_hist, &w_hist, hotVectors, labels, alpha, num_iters);
            break;
        }

        if (inp != '0' && inp != 'q' && inp != '4' && inp != '5')
        {
            printf("Time taken: %.3f\n", (double)(end - start) / CLOCKS_PER_SEC);
            printf("Final Cost: %f\n", c_hist[epochs - 1]);
            printf("\nFinal Weights: ");
            for (i = 0; i < dictCap; i++)
                printf("%f ", weights[i]);
            printf("\n");

            gd_test(weights, hotVectors, labels, dictCap);
        }
    }

    // Free allocated memory
    for (i = 0; i < dictCap; i++)
        free(dict[i]);
    free(dict);

    for (i = 0; i < 200; i++)
    {
        j = 0;
        while (texts[i] != NULL && texts[i][j] != NULL)
            free(texts[i][j++]);
        free(texts[i]);
    }
    free(texts);

    for (i = 0; i < 200; i++)
        free(hotVectors[i]);
    free(hotVectors);

    free(labels);
    free(weights);

    for (i = 0; i < epochs; i++)
        free(w_hist[i]);
    free(w_hist);
    free(c_hist);

    return 0;
}
