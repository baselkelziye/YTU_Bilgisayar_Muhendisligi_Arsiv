#include <stdio.h>
#define ARR_SIZE 8

//BUBBLE SORT WITH FUNCTIONS BUT WITHOUT DYNAMIC MEMORY
//FUNCTIONS USE GLOBAL VARIABLES (NOT PREFERRED)

int arr[ARR_SIZE];
//WHAT IF i,j,tmp were defined as global?

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

int main(int argc, char *argv[])
{
    int i, j, tmp;
    int count = 0;
    enterArray();
    printf("\nThe unsorted array is: ");
    printArray();
    for( i=0; i<ARR_SIZE-1; i++ ) {
        for( j=i+1; j<ARR_SIZE; j++ ) {
            count++;
            if( arr[i] > arr[j] ) {
                tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
                //Verbose code to show the bubbling
                printf("\nThe array has become : "); printArray();
            }
        }
    }
    printf("\nThe sorted array is  : "); printArray();
    printf("\n%d ops",count); system("pause"); return 0;
}

