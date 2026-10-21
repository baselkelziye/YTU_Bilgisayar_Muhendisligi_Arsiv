#include <stdio.h>
#define MAX 50

void matrisAl(int matris[MAX][MAX],int *ptr);
void matrisYazdir(int matris[MAX][MAX],int N);
int toplamYol(int matris[MAX][MAX], int i, int j, int N);
void guzergahYazdir(int matris[MAX][MAX],int N,int i,int j,int yol[MAX*MAX][2],int sira);

int main(){
    int matris[MAX][MAX];
    int yol[MAX*MAX][2];
    int N;

    matrisAl(matris,&N);
    matrisYazdir(matris,N);
    printf("Toplam yol sayisi: %d\n",toplamYol(matris,0,0,N));
    guzergahYazdir(matris, N, 0, 0, yol, 0);

    return 0;
}

void matrisAl(int matris[MAX][MAX],int *ptr){
    int i,j,N;
    printf("Matrisin boyutu : ");
    scanf("%d",&N);
    *ptr = N;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("[%d][%d]. terim : ",i+1,j+1);
            scanf("%d",&matris[i][j]);
        }
    }
}

void matrisYazdir(int matris[MAX][MAX],int N){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",matris[i][j]);
        }
        printf("\n");
    }
}

int toplamYol(int matris[MAX][MAX], int i, int j, int N){
    
    if ((i==N-1) && (j==N-1) && (matris[i][j]==1)) {
        return 1;
    }
    if ((i>=N) || (j>=N) || (matris[i][j]==0)) {
        return 0;
    }
    return toplamYol(matris,i+1,j,N) + toplamYol(matris,i,j+1,N);
}

void guzergahYazdir(int matris[MAX][MAX],int N,int i,int j,int yol[MAX*MAX][2],int sira){
    int k;
    if ((i==N-1) && (j==N-1)){
        yol[sira][0] = i;
        yol[sira][1] = j;
        for (k=0;k<=sira;k++) {
            printf("(%d,%d) ",yol[k][0],yol[k][1]);
        }
        printf("\n");
        return;
    }
    if ((i>=N) || (j>=N) || (matris[i][j]==0)) {
        return;
    }
    yol[sira][0] = i;
    yol[sira][1] = j;
    guzergahYazdir(matris,N,i+1,j,yol,sira+1);
    guzergahYazdir(matris,N,i,j+1,yol,sira+1);
}