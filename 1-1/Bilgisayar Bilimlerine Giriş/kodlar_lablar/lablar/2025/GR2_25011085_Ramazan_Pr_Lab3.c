#include <stdio.h>
int main () {
int n,m;
int palet[100][100];
int hist[256];
int i,j;
printf("Matrisinizin boyutlarini giriniz ");
scanf("%d %d", &n, &m);
printf("Renk paleti matrisini giriniz (0-255) ");
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        scanf("%d", &palet[i][j] );
    }
}
for(i=0;i<256;i++){
    hist[i]=0;
}
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        if(palet[i][j]<256 && palet[i][j]>=0){
            hist[palet[i][j]]++;
        }
    }
}
for(i=0;i<256;i++){
    if(hist[i]==1){
        printf("%d ", i);
    }
}
}