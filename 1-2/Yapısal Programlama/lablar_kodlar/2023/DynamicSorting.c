#include <stdio.h>
#include <stdlib.h>
void printList( int *list, int n );

int getPosOfMin( int *list, int n, int fromPos ) {
    int i, minIndex;
    minIndex = fromPos;
    for( i=fromPos+1; i<n; i++ )
        if( *(list+i) < *(list+minIndex) )
            minIndex = i;
    return minIndex;
}

void selectionSort( int *b, int n ) {
    int i, minPos, tmp;
    for( i=0; i<n-1; i++ ) {
        minPos = getPosOfMin( b, n, i );
        if( *(b+i) > *(b+minPos) ) {
            tmp = *(b+i); *(b+i) = *(b+minPos); *(b+minPos) = tmp;
        }
        printList( b, n );
    }

}

void bubbleSort( int *b, int n ) {
    int i, j, tmp;
    for( i=0; i<n-1; i++ ) {
        for( j=i+1; j<n; j++ ) {
            if( b[i] > b[j] ) { //*(b+i) > *(b+j) de olur.
                tmp = b[i]; b[i] = b[j]; b[j] = tmp;
            }
            printList( b, n );
        }
    }
}
void printList( int *list, int n ) {
    int i;
    printf("\n");
    for( i=0; i<n; i++ )
        printf("%5d ",*(list+i));
}
int main(int argc, char *argv[]){
    int i, n;
    int *p;
    printf("Kac tamsayi girmek istiyorsunuz? ");
    scanf("%d",&n);
    p = (int*) malloc( n * sizeof(int) );
    if( p == NULL ) {
        printf("Bellek ayrilamadi"); return -1;
    }
    for( i=0; i<n; i++ ) {
        printf("%d. tamsayi? ",(i+1));
        scanf("%d", p+i);
    }
    printf("\nGirilen dizi ");
    printList(p,n);
    selectionSort(p,n);
    printf("\nSirali dizi ");
    printList(p,n);


    free(p);
    printf("\n");
    system("PAUSE");
    return 0;
}

