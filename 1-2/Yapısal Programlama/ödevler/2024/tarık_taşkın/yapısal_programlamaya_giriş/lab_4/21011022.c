#include <stdio.h>
#define MAX 50

void veriGir(int matris[MAX][MAX],char is[MAX], int N);
void yazdir(int matris[MAX][MAX], char is[MAX], int N, int head);

/*
    char -> int , int -> char donusumleri normalde calisirken dongu icinde hatali calistigi icin 
    matrisin 0. sutununda karakterleri tutamadim
    onun yerine is adli char dizisi kullandim
*/

int main(){
    int matris[MAX][MAX];
    char is[MAX];
    int N;
    int i;
    int head;

    printf("Is sayisini giriniz: ");
    scanf("%d",&N);
    veriGir(matris,is,N);
    for(i=0;i<N;i++){
        printf("%c\n",is[i]);
    }

    do{
        printf("Head (0,N-1): ");
        scanf("%d",&head);
    }while(head<0 && head>N-1);

    printf("Linkleri giriniz.\n");
    for(i=0;i<N;i++){
        printf("%c isinin linki: ",is[i]);
        scanf("%d",&matris[i][2]);
    }

    yazdir(matris,is,N,head);


    return 0;
}

void veriGir(int matris[MAX][MAX],char is[MAX], int N){
    int i;


    printf("Isleri giriniz.\n");
    for(i=0;i<N;i++){
        printf("%d. is: ",i+1);
        scanf("%s",&is[i]);
    }

    printf("Islerin suresini giriniz.\n");
    for(i=0;i<N;i++){
        printf("%c isinin suresi: ",is[i]);
        scanf("%d",&matris[i][1]);
        if(matris[i][1]<1){
            i--;
        }
    }
}

void yazdir(int matris[MAX][MAX], char is[MAX], int N, int head){
    int i,j;

    while(head!=-1){
        for(j=0;j<matris[head][1];j++){
            printf("%c ",is[head]);
        }
        head = matris[head][2];
    }
}