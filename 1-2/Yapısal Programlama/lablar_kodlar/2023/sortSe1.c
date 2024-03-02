#include <stdio.h>
#define ARR_SIZE 8

//SELECTION SORT WITH FUNCTIONS BUT WITHOUT DYNAMIC MEMORY
//FUNCTIONS USE GLOBAL VARIABLES (NOT PREFERRED)

int arr[ARR_SIZE];
int count = 0;

void enterArray( ) {
    int i;
    for( i=0; i<ARR_SIZE; i++ ) {
        printf("Enter integer #%d: ", i+1);
        scanf("%d",&arr[i]);
    }
}
void printArray( ) {
    int i;
    for( i=0; i<ARR_SIZE; i++ )
        printf("%5d", arr[i]);
}
int findMinIndex( int from ) {
    int i, minIndex;
    minIndex = from;
    for( i=from+1; i<ARR_SIZE; i++ ) {
        count++;
        if( arr[i] < arr[minIndex] )
            minIndex = i;
    }
    return minIndex;
}

int main(int argc, char *argv[])
{
    int i, j, tmp;
    enterArray();
    printf("\nThe unsorted array is: ");
    printArray();
    for( i=0; i<ARR_SIZE-1; i++ ) {
        j = findMinIndex(i);
        if( arr[i] > arr[j] ) {
            tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
            //Verbose code to show the bubbling
            printf("\nThe array has become : "); printArray();
        }
    }
    printf("\nThe sorted array is  : "); printArray();
    printf("\n%d ops",count); system("pause"); return 0;
}


