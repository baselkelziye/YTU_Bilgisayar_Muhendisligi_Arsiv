#include <stdio.h>

#define MAX 100

int main(void) {
    int N, M;
    int sparseMatrix[MAX][MAX];
    int doluMatrix[MAX][3];
    
    int i, j;
    int elemanSayisi = 0; /* Dolu Matrix'te bulunan eleman (satir) sayisi*/
    int arananSatir, arananSutun, arananEleman = 0;
    
    printf("Satir sayisi, N giriniz: ");
    scanf("%d", &N);
    
    printf("Sutun sayisi, M giriniz: ");
    scanf("%d", &M);
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++){
            printf("matrix[%d][%d]: ", i ,j);
            scanf("%d", &sparseMatrix[i][j]);
        }
    }
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++){
            if (sparseMatrix[i][j] != 0){
                doluMatrix[elemanSayisi][0] = i + 1; /* satir */
                doluMatrix[elemanSayisi][1] = j + 1; /* sutun */
                doluMatrix[elemanSayisi][2] = sparseMatrix[i][j]; /* deger */
                elemanSayisi++;
            }
        }
    }
    
    printf("\nSparse Matrix: \n");
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++){
            printf("%d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\nDolu Matrix: \n");
    
    /* Dolu matrixi yazdir */
    
    for (i = 0; i < elemanSayisi; i++) {
        for (j = 0; j < 3; j++){
            printf("%d ", doluMatrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    printf("Aranan satiri giriniz: ");
    scanf("%d", &arananSatir);
    
    printf("Aranan sutunu giriniz: ");
    scanf("%d", &arananSutun);
    
    for (i = 0; i < elemanSayisi; i++){
        /* [0] = satir, [1] = sutun, [2] = deger */
        if (doluMatrix[i][0] == arananSatir && doluMatrix[i][1] == arananSutun){
        
            arananEleman = doluMatrix[i][2];
        }
    }

    if (arananEleman == 0){
        printf("\nBULUNAMADI");
    } else {
        printf("\nAranan Eleman: %d\n", arananEleman);
    }
    
    return 0;
}
