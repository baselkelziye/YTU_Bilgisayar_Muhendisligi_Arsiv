#include <stdio.h>
#include <stdlib.h>
/* Kullanıcıdan dynamic allocation ile alınan NxN matrisin her bir elemanını pointer mantığı ile gezen ve her bir sayıya bakıp
sınırlarındaki sayıların her birinden büyükse ekrana yazdıran ve Toplam değişkeninde bu matris elementlerini toplayan kod soruldu*/
int main(){
int i,j,N;
int isBigger;
int toplam = 0;
printf("Matrisin boyutunu giriniz: \n");
scanf("%d", &N);
int** mat = (int**)malloc(N*sizeof(int*));
for(i=0;i<N;i++){
    mat[i] = (int*)malloc(N*sizeof(int)); // Veya *(mat+i)
}
printf("Matrisinizi giriniz:\n");
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        scanf("%d", (*(mat+i)+j)); // scanf adres istediği için tek *
    }
}
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        isBigger = 1;
        if( i>0 && *(*(mat+i)+j) <= *(*(mat+i-1)+j)) isBigger=0;
        if( j>0 && *(*(mat+i)+j) <= *(*(mat+i)+j-1)) isBigger=0;
        if( i<N-1 && *(*(mat+i)+j) <= *(*(mat+i+1)+j)) isBigger=0;
        if( j<N-1 && *(*(mat+i)+j) <= *(*(mat+i)+j+1)) isBigger=0;
        if(isBigger == 1){
            printf("Deger:%d , Konum: (%d,%d)\n", *(*(mat+i)+j), i , j);
            toplam += *(*(mat+i)+j);
        }
    }
}
printf("Toplam:%d", toplam);
for(i=0;i<N;i++){
    free(mat[i]);
}
free(mat);
return 0;
}