#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int dizi[50][50];
    int N,rastgeleDeger,i,j,k,toplamBetul,toplamAyse,temp;
    char stop;
    srand(time(0));

    do{
        printf("Dizinin boyutunu giriniz: ");
        scanf("%d",&N);

        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                rastgeleDeger = rand()%(N*N+1);
                dizi[i][j] = rastgeleDeger;
                printf("%d ",dizi[i][j]);
            }
            printf("\n");
        }

        toplamAyse = 0;
        toplamBetul = 0;

        for(k=0;k<6;k++){
            for(i=0;i<N/2;i++){
                for(j=i;j<N-i-1;j++){
                    temp = dizi[i][j];
                    dizi[i][j] = dizi[N-1-j][i];
                    dizi[N-1-j][i] = dizi[N-1-i][N-1-j];
                    dizi[N-1-i][N-1-j] = dizi[j][N-1-i];
                    dizi[j][N-1-i] = temp;
                }
            }

            printf("90 derece dondurulmus hali:\n");
            for(i=0;i<N;i++){
                for(j=0;j<N;j++){
                    printf("%d ",dizi[i][j]);
                }
                printf("\n");
            }

            if(k%2==0){
                for(i=0;i<N;i++){
                    toplamBetul = toplamBetul + dizi[N-1][i];
                }
            }
            else{
                for(i=0;i<N;i++){
                    toplamAyse = toplamAyse + dizi[N-1][i];
                }
            }
            printf("Betul: %d , Ayse: %d \n",toplamBetul,toplamAyse);
        }
        
        if(toplamAyse>toplamBetul){
            printf("Ayse kazandi.\n");
        }
        else{
            printf("Betul kazandi.\n");
        }

        printf("Devam etmek icin 'E' ya da 'e' tusuna basiniz: ");
        scanf(" %c",&stop);
    }
    while(stop == 'E' || stop == 'e');

    return 0;
}