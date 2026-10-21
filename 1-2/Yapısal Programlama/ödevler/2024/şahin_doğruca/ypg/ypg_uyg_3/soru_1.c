#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int eksikSayiMi(int S) {
    if(S < 0) return -1;
    int * divisors = (int*) malloc(sizeof(int) * 0);
    int divisorCount = 0;

    int i = 1;

    while(i < S && (divisorCount == 0 || divisors[divisorCount - 1] != i)) {
        if(S % i == 0) {
            divisors = realloc(divisors, sizeof(int) * (divisorCount + 1));
            divisors[divisorCount] = i;
            printf("%d. indexteki eleman : %d\n", divisorCount, divisors[divisorCount]);
            divisorCount++;
            if(divisors[divisorCount - 1] != (S / i)) {
                divisors = realloc(divisors, sizeof(int) * (divisorCount + 1));
                divisors[divisorCount] = (S / i);
                printf("%d. indexteki eleman : %d\n", divisorCount, divisors[divisorCount]);
                divisorCount++;
            }
        }
        i++;
    }


    int sum = 0;

    for(i = 0; i < divisorCount; i++) {
        sum += (divisors[i]);
    }

    printf("sum : %d\n", sum);

    if(sum < (S * 2)) 
        return S * 2 - sum;
    else 
        return 1;
    

    free(divisors);
}

void dosyayaGrupla(int * nums, int len) {
    int i, res;
    FILE * file;
    for(i = 0; i < len; i++) {
        res = eksikSayiMi(nums[i]);

        if(res == -1) {
            file = fopen("negatif.txt", "a");
            fprintf(file, "%d\n", nums[i]);
        } else if(res == 1) {
            file = fopen("pozitif.txt", "a");
            fprintf(file, "%d\n", nums[i]);
        } else {
            file = fopen("eksik.txt", "a");
            fprintf(file, "%d\n", nums[i]);
        }
    }



    fclose(file);
}

int main() {
    int len;

    printf("kac sayi girmek istersiniz : ");
    scanf("%d", &len);

    int * nums = (int*) malloc(sizeof(int) * len);

    int i;
    for(i = 0; i< len; i++) {
        printf("%d. indexteki eleman : ", i);
        scanf("%d", &nums[i]);
    }

    dosyayaGrupla(nums, len);

    return 0;
}