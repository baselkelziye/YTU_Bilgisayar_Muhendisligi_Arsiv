#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void diziAl(char **dizi, int N);
void diziYazdir(char **dizi, int N);
int maxUzunlukBul(char **dizi, int N);
void yeniDiziOlustur(char **dizi, int N, char ***yeniDizi, int maxUzunluk);

int main(){
    char **dizi;
    char **yeniDizi;
    int N;
    int i;
    int maxUzunluk;

    printf("Kelime sayisini giriniz: ");
    scanf("%d",&N);

    dizi = (char**) malloc(N*sizeof(char*));
    for(i=0;i<N;i++){
        dizi[i] = (char*) malloc(50*sizeof(char));
    }
    diziAl(dizi,N);

    maxUzunluk = maxUzunlukBul(dizi,N);

    yeniDiziOlustur(dizi, N, &yeniDizi, maxUzunluk);
    diziYazdir(yeniDizi,N);

    return 0;
}

void diziAl(char **dizi, int N){
    int i;
    printf("Maksimum 50 karakter giriniz.\n");
    for(i=0;i<N;i++){
        printf("Kelime %d: ",i+1);
        scanf("%s",dizi[i]);
    }
}

void diziYazdir(char **dizi, int N){
    int i;
    printf("\n");
    for(i=0;i<N;i++){
        printf("%s\n",dizi[i]);
    }
}

int maxUzunlukBul(char **dizi, int N){
    int i;
    int maxIndex = 0;

    for(i=1;i<N;i++){
        if(strlen(dizi[i]) > strlen(dizi[maxIndex])){
            maxIndex = i;
        }
    }
    return strlen(dizi[maxIndex]);
}

void yeniDiziOlustur(char **dizi, int N, char ***yeniDizi, int maxUzunluk){
    int i,j;
    *yeniDizi = (char**) malloc(N*sizeof(char*));
    for(i=0;i<N;i++){
        (*yeniDizi)[i] = (char*) malloc((maxUzunluk+1)*sizeof(char));
        strcpy((*yeniDizi)[i], dizi[i]);
        for(j=strlen(dizi[i]);j<maxUzunluk;j++){
            (*yeniDizi)[i][j] = '*';
        }
        (*yeniDizi)[i][j] = '\0';
    }
}
