#include <stdio.h>
#define ARR_SIZE 8

//BUBBLE SORT WITHOUT FUNCTIONS AND DYNAMIC MEMORY
int main(int argc, char *argv[])
{
    int i, j, tmp;
    int arr[ARR_SIZE];
    for( i=0; i<ARR_SIZE; i++ ) {
        printf("Enter integer #%d: ", i+1);
        scanf("%d",&arr[i]);
    }
    printf("\nThe unsorted array is: ");
    for( i=0; i<ARR_SIZE; i++ )
        printf("%5d", arr[i]);
    for( i=0; i<ARR_SIZE-1; i++ ) {
        for( j=i+1; j<ARR_SIZE; j++ ) {
            if( arr[i] > arr[j] ) {
                tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
                //Verbose code to show the bubbling
                printf("\nThe array has become : ");
                for( tmp=0; tmp<ARR_SIZE; tmp++ )
                    printf("%5d", arr[tmp]);
            }
        }
    }
    printf("\nThe sorted array is  : ");
    for( i=0; i<ARR_SIZE; i++ )
        printf("%5d", arr[i]);
    printf("\n"); system("pause"); return 0;
}
