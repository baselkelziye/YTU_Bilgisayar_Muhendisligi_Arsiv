#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "turkish");
	
    int N, M;
    int i, j;
    printf("Ýlk polinomun terim sayýsý?\n");
    scanf("%d", &N);

    int* p1_exponents = (int*)malloc(N * sizeof(int));
    int* p1_coefficients = (int*)malloc(N * sizeof(int));

    for (i = 0; i < N; i++) {
        printf("Üst ve katsayý?\n");
        scanf("%d %d", &p1_exponents[i], &p1_coefficients[i]);
    }
    printf("Ýkinci polinomun terim sayisi?\n");
    scanf("%d", &M);
    int* p2_exponents = (int*)malloc(M * sizeof(int));
    int* p2_coefficients = (int*)malloc(M * sizeof(int));

    for (i = 0; i < M; i++) {
        printf("Üst ve katsayý?\n");
        scanf("%d %d", &p2_exponents[i], &p2_coefficients[i]);
    }

    int result_size = (N * M)+1; 
    int* result_exponents = (int*)malloc(result_size * sizeof(int));
    int* result_coefficients = (int*)calloc(result_size, sizeof(int)); 

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            int exp = p1_exponents[i] + p2_exponents[j];
            result_coefficients[exp] += p1_coefficients[i] * p2_coefficients[j];
        }
    }

    for (i = 0; i < result_size ; i++) {
        if (result_coefficients[i] != 0) {
            printf("+((%d)*p^%d) ", result_coefficients[i], i);
        }
    }

    free(p1_exponents);
    free(p1_coefficients);
    free(p2_exponents);
    free(p2_coefficients);
    free(result_exponents);
    free(result_coefficients);

    return 0;
}
