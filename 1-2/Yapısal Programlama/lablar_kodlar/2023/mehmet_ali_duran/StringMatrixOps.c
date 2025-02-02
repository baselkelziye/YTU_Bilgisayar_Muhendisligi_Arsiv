#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 64
#define USED_ROWS 3
#define USED_COLS 6

int main(int argc, char *argv[])
{
    int i, j;
    char **text = (char**) calloc( ROWS, sizeof(char*) );
    char *mat[ROWS] = {"012345\n","6789AB\n","CDEFGH\n"};
    char *bp, *mp; /* same as char *bp; char *mp;
     Notice where * is aligned, *mp does not become **mp. */
    if( text == NULL ) {
        printf("Can not allocate memory for the text"); return -1;
    }
    for( i=0; i < ROWS; i++ )
        text[i] = (char*) calloc( COLS, sizeof(char) );

    strcpy(text[0], "012345\n");
    strcpy(text[1], "6789AB\n");
    strcpy(text[2], "CDEFGH\n");
    for(i = 0; i < ROWS; i++)
        printf("%s",text[i]);
    //system("pause");

    bp = text[0]; mp = text[1];  j = 1;
    printf("Output %d:%s", j, mp); j++; //(#1)
    printf("Output %d:%s", j, mp+1); j++; //(#2)
    printf("Output %d:%s", j, mp+2); j++; //(#3)
    printf("Output %d:%s\n", j, text ); j++; //(#4) buggy
    printf("Output %d:%s", j, *text ); j++; //(#5) **text:crash
    printf("Output %d:%c\n", j, text ); j++; //(#6) buggy
    printf("Output %d:%c\n", j, *bp); j++; //(#7) %c & *bp: OK
    printf("Output %d:%c\n", j, bp); j++; //(#8)%c & bp: buggy
    printf("Output %d:%c\n", j, *(bp+2) ); j++; //(#9)
    printf("Output%d:%c\n", j, *text ); j++; //(#10)buggy
    printf("Output%d:%c\n", j, **text ); j++; //(#11)
    printf("Output%d:%c\n", j, *(*(text+1)+2) ); j++; //(#12)
    printf("Output%d:%c\n", j, *((text[1])+3) ); j++; //(#13) +3:OK [3]:error
    printf("Output%d:%c\n", j, *(*(mat+1))+3 ); j++; //(#14) +3:OK [3]:error
    printf("Output%d:%c\n", j, *(*(mat+1)+2) ); j++; //(#15)
    printf("Output%d:%d\n", j, mat[2][4]-mat[1][4] ); j++;//(#16)

    for(i = 0; i < ROWS; i++) {
	   free(text[i]); //free(mat[i]);
    }
    free(text); //free(mat);

    system("pause"); return 0;
}