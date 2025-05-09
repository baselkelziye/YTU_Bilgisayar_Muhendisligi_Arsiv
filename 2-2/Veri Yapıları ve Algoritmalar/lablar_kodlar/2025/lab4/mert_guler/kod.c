#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Cousin{
    int data;
    struct Cousin* next;
} Cousin;

typedef struct Info {
    int max;
    int level;
    int index;
} Info;

void findInfo(int *arr, int N, Info* info){
    int max = -1;
    int i;
    int index = 0;
    
    for (i = 1; i <= N; i = 2 * i + 1) {
        if (arr[i - 1] > max){
            max = arr[i - 1];
            index = i;
        }
    }
    
    info->max = max;
    info->level = (int) log2((double) index) + 1;
    info->index = index;
}

Cousin* findCousins(int* arr, int index){
    int i;
    int first = 1;
    Cousin* cousin = (Cousin*)calloc(1, sizeof(Cousin));
    Cousin* iterator = cousin;
    
    for (i = index / 2 + 1; i < index; i++) {
        
        if (arr[i] != -1){
            
           if (first == 1){
              iterator->data = arr[i];
              first = 0;
            } else {
            iterator->next = (Cousin*)calloc(1, sizeof(Cousin));
            iterator->next->data = arr[i];
            iterator = iterator->next;
            }
            
        }
        
    }
    
    return cousin;
}

int main(int argc, const char * argv[]) {
    int N;
    int i;
    int *arr;
    Cousin* cousins;
    Cousin* temp;
    
    Info* info = (Info*)calloc(1, sizeof(Info));
    
    printf("N girin: ");
    scanf("%d", &N);
    
    arr = (int*)calloc(N, sizeof(int));
    for (i = 0; i < N; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    findInfo(arr, N, info);
    printf("\nMax value: %d", info->max);
    printf("\nLevel: %d\n", info->level);
    
    cousins = findCousins(arr, info->index);
    
    printf("Cousins: ");
    while (cousins != NULL) {
        printf("%d ", cousins->data);
        temp = cousins;
        cousins = cousins->next;
        free(temp);
    }
    
    free(info);
    return 0;
}
