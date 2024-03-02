#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
void listOneLineOfText( char *p ) {
    int j;
    for( j=0; j<SIZE; j++ ) {
        printf("%c",*p);
        p++;
    }
    printf("\n");
}
void toUpperCase( char *p ) {
    int j;
    for( j=0; j<SIZE; j++ ) {
        if( *p >= 97 && *p <= 123 )
            *p -= 32;
        p++;
    }
}
void toLowerCase( char *p ) {
    int j;
    for( j=0; j<SIZE; j++ ) {
        if( *p >= 65 && *p <= 91 )
            *p += 32;
        p++;
    }
}
void listAllLines( char *p ) {
    int j;
    for( j=0; j<SIZE*SIZE; j++ ) {
        if( j % SIZE == 0 )
            printf("\n");
        if( ( *p >= 97 && *p <= 123 ) || ( *p >= 65 && *p <= 91 )  ) {
            printf("%c",*p);
        }
        p++;
    }
}


int main(int argc, char *argv[]){
    char metinler[SIZE][SIZE], i;
    char ba='A', ka='a';
    printf("A=%d,a=%d",ba,ka);
    //A=65,a=97,fark=32

    for( i=0; i<SIZE; i++ ) {
        printf("Enter text %d: (max %d letters)", i, SIZE);
        scanf("%s",&metinler[i]);
    }
    /*for( i=0; i<SIZE; i++ ) {
        toLowerCase(metinler[i]);
    }
    for( i=0; i<SIZE; i++ ) {
        listOneLineOfText(metinler[i]);
    } */
    listAllLines(metinler[0]);
    printf("\n");
    system("PAUSE");
    return 0;
}

