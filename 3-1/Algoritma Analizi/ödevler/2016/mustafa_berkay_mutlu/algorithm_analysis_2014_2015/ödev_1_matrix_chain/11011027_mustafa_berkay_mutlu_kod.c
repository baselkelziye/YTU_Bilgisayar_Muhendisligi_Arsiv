#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


void MatrixChain(int *, int**, int**);
void PrintMatrixes(int **, int **);
char* Mult(int **, int, int);

int SIZE;

int main()
{
    int i, j; // Dongu degiskenleri
    int *arr; // Matrislerin boyutlarinin tutuldugu dizi. Boyutlar ornegin 10x30 ve 30x200 luk matrisler icin 10, 30 ,200 seklinde tutulur.
    int **m, **s; // Pseudo kodda belirtilen m ve s matrisleri.

    printf("Matris sayisini giriniz: ");
    scanf("%d", &SIZE);
    // Kullanici matris sayisini girecek, ancak biz arr dizisinde matrislerin olculerini
    // tutacagimiz icin, burada SIZE'i artiriyoruz.
    SIZE++;

    // Dinamik diziler olusturuluyor.
    arr = (int *) malloc( sizeof(int) * SIZE );
    m = (int **) malloc ( sizeof(int *) * SIZE);
    s = (int **) malloc ( sizeof(int *) * SIZE);

    for(i=0;i<SIZE;i++){
        m[i] = (int *) malloc( sizeof(int) * SIZE );
        s[i] = (int *) malloc( sizeof(int) * SIZE );
    }

    // Diziler ilklendiriliyor.
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }

    printf("Lutfen matrislerin buyukluklerini (p degerlerini) girin. Matrisler ornek olarak 10x20 ve 20x30 ise sirayla 10, 20, 30 girin.\n");
    for(i=0;i<SIZE;i++){
        printf("%d. p degeri: ", i + 1);
        scanf("%d", &arr[i]);
    }

    MatrixChain(arr, m, s);
    PrintMatrixes(m, s);

    printf("En az carpim sonucu: "); puts(Mult(s, 1, SIZE-1));
    printf("En az m[%d][%d] = %d kadar carpma islemi yapilarak matrisler carpilabilir. \n\n", 1, SIZE-1, m[1][SIZE-1]);

    printf("Cikmak icin bir tusa basiniz.\n");
    getchar();

    free(arr);
    free(m);
    free(s);
    return 0;
}


void MatrixChain(int *p, int **m, int **s)
{
    int i, j, k, L, cost;

    // Kosegen sifirlaniyor.
    for (i = 1; i < SIZE; i++){
        m[i][i] = 0;
    }

    for (L=2; L<SIZE; L++)
    {
        for (i=1; i<SIZE-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                cost = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (cost < m[i][j]){
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
}

char* Mult(int **s, int i, int j){
    if(i < j){
        char *retVal = (char*) malloc(10);
        char *a = Mult(s, i, s[i][j]);
        char *b = Mult(s, s[i][j] + 1, j);
        sprintf(retVal, "(%s*%s)\0", a, b);
        return retVal;
    }
    else {
        char *retVal = (char *) malloc(3);
        sprintf(retVal, "A%d\0", i);
        return retVal;
    }
}


void PrintMatrixes(int **m, int **s){
    int i, j;

    printf("\n----------------------------------------------------\n");
    printf("The 'm' matrix:\n");
    for(j=SIZE-1;j>=1;j--){
        for(i=1;i<SIZE;i++){
            printf("m[%d][%d] = %5d   ", i, j, m[i][j]);
        }
        printf("\n");
    }
    printf("\n\nThe 's' matrix:\n");

    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            printf("s[%d][%d] = %d   ", i, j, s[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------------------------\n\n");
}
