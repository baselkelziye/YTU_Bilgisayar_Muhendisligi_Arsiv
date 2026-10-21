#include <stdio.h>

int main(){
    int i=0,stop,j,k,uzunluk;
    char temp;
    char kontrol;
    char kelimeler[100][100];

    do{
        stop=0;
        printf("Kelime giriniz: ");
        scanf("%s",kelimeler[i]);

        j=0;
        do{
            j++;
        }
        while(kelimeler[i][j]);
        uzunluk=j;

        k=0;
        do{
            temp = kelimeler[i][0];
            j=0;
            do{
                kelimeler[i][j]=kelimeler[i][j+1];
                j++;
            }
            while(j<uzunluk-1);
            kelimeler[i][uzunluk-1] = temp;
            printf("%s\n",kelimeler[i]);
            k++;
        }
        while(k<uzunluk);

        printf("Devam etmek icin 'E' ya da 'e' tusuna basiniz: ");
        scanf(" %c",&kontrol);
        if(kontrol == 'E' || kontrol == 'e'){
            stop=1;
        }

        i++;       
    }
    while(stop);
    
    return 0;
}