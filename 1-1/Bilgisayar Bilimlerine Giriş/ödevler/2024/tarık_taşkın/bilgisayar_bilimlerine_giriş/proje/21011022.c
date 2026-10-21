#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int N,M,yemekSayisi,yilanSatir,yilanSutun,gelinenNokta;
    int hamleSayisi=1,uzunluk=1,stop=1,carptiMi=0,yediMi=0;
    int rastgele,rastgeleSatir,rastgeleSutun;
    int i,j,a,b,c,d;
    char hareketYonu,x,y;
    char oyunTahtasi[100][100];
    int yemekNoktalari[2][500];
    int yilanNoktalari[2][501];

    // Girdileri alma 
    printf("--- Yilan Buyutme Oyunu ---\n");
    printf("Satir sayisini giriniz: ");
    scanf("%d",&N);
    printf("Sutun sayisini giriniz: ");
    scanf("%d",&M);
    printf("Yemek sayisini giriniz: ");
        scanf("%d",&yemekSayisi);
    while(yemekSayisi>=(N*M)){
        printf("Yemek sayisini fazla girdiniz.\n");
        printf("Yemek sayisini tekrar giriniz:");
        scanf("%d",&yemekSayisi);
    }
    
    // Diziyi olusturma
    for(i=0;i<N;i++){   
        for(j=0;j<M;j++){
            oyunTahtasi[i][j] = ' ';
        }
    }

    // Yemek yerleri ve baslangic noktasi olusturma
    srand(time(0));
    i=0;
    while(i<=yemekSayisi){
        rastgeleSatir = rand()%N;
        rastgeleSutun = rand()%M;
        j=0;
        while(j<i){
            if((yemekNoktalari[0][j]==rastgeleSatir) && (yemekNoktalari[1][j]==rastgeleSutun)){
                rastgeleSatir = rand()%N;
                rastgeleSutun = rand()%M;
                j=0;
            }
            else{
                j=j+1;
            }
        }
        yemekNoktalari[0][i]=rastgeleSatir;
        yemekNoktalari[1][i]=rastgeleSutun;
        oyunTahtasi[rastgeleSatir][rastgeleSutun] = '0';
        i=i+1;
    }
    // Yemekler bir fazla yazdirilip sondaki yemek yilanin baslangici yapilir
    yilanSatir = rastgeleSatir;
    yilanSutun = rastgeleSutun;
    yilanNoktalari[0][0] = yilanSatir;
    yilanNoktalari[1][0] = yilanSutun;
    oyunTahtasi[yilanSatir][yilanSutun] = '1';

    printf(" ---- --- --- --- --- ---- \n");
    for(i=0;i<N;i++){   
        for(j=0;j<M;j++){
            printf(("| %c"),oyunTahtasi[i][j]);
        }
        printf("|\n");
    }
    while(stop){
        gelinenNokta=0;
        // Hareket yonunu alip gelinen noktanin matris disina cikip cikmadigi kontrol edilir
        printf("Hareket Yonu (U/D/L/R): ");
        scanf(" %c",&hareketYonu);
        if(hareketYonu == 'U' || hareketYonu == 'u'){
            yilanSatir = yilanSatir - 1;
            if(yilanSatir<0){
                stop=0;
                carptiMi=1;
            }
            else if(oyunTahtasi[yilanSatir][yilanSutun] == '0'){
                gelinenNokta = 1;
            }
        }
        else if(hareketYonu == 'D' || hareketYonu == 'd'){
            yilanSatir = yilanSatir + 1;
            if(yilanSatir>(N-1)){
                stop=0;
                carptiMi=1;
            }
            else if(oyunTahtasi[yilanSatir][yilanSutun] == '0'){
                gelinenNokta = 1;
            }
        }
        else if(hareketYonu == 'L' || hareketYonu == 'l'){
            yilanSutun = yilanSutun - 1;
            if(yilanSutun<0){
                stop=0;
                carptiMi=1;
            }
            else if(oyunTahtasi[yilanSatir][yilanSutun] == '0'){
                gelinenNokta = 1;
            }
        }
        else if(hareketYonu == 'R' || hareketYonu == 'r'){
            yilanSutun = yilanSutun + 1;
            if(yilanSutun>(M-1)){
                stop=0;
                carptiMi=1;
            }
            else if(oyunTahtasi[yilanSatir][yilanSutun] == '0'){
                gelinenNokta = 1;
            }
        }
        
        // Kendi ustune basti mi kontrolu
        i=1;
        while(i<uzunluk && stop){
            if(yilanSatir == yilanNoktalari[0][i]){
                if(yilanSutun == yilanNoktalari[1][i]){
                    carptiMi = 1;
                    stop = 0;
                }
            }
            i=i+1;
        }

        // Yilan yemek yediyse uzunlugunun artirilmasi
        c=yilanNoktalari[0][uzunluk-1];
        d=yilanNoktalari[1][uzunluk-1];
        if(yediMi && stop){
            yediMi=0;
            yilanNoktalari[0][uzunluk-1]=c;
            yilanNoktalari[1][uzunluk-1]=d;
            uzunluk = uzunluk + 1;
            yemekSayisi = yemekSayisi - 1;
            if(yemekSayisi == 0){
                stop = 0;
            }
        }
        else{
            oyunTahtasi[c][d]= ' ';
        }

        // Yilanin kendi ustune basmasi ya da duvara carpmasi durumunda * ile gosterilmesi
        // Eger carpmadiysa yilan hareket ettirilir
        if(carptiMi){
            for(i=0;i<uzunluk;i++){
                a = yilanNoktalari[0][i];
                b = yilanNoktalari[1][i];
                oyunTahtasi[a][b] = '*';
            }
        }
        else{
            for(i=uzunluk-1;i>=1;i--){
                yilanNoktalari[0][i]=yilanNoktalari[0][i-1];
                a=yilanNoktalari[0][i];
                yilanNoktalari[1][i]=yilanNoktalari[1][i-1];
                b=yilanNoktalari[1][i];
                oyunTahtasi[a][b]= i + '1';
            }
            yilanNoktalari[0][0]= yilanSatir;
            yilanNoktalari[1][0]= yilanSutun;
            oyunTahtasi[yilanSatir][yilanSutun]= '1';
        }

        // Yemek yeme islemi bir sonraki adimda yapilacagindan cift degisken kullanilarak yemek yeme durumu kontrol edilir
        if(gelinenNokta){
            yediMi=1;
        }

        // Hamle sayisi ve yapilan isleme gore oyun tahtasi yazdirilir
        printf(" ---- --- --- --- --- ---- \n");
        printf("\t%d. HAMLE\t\n",hamleSayisi);
        hamleSayisi = hamleSayisi + 1;
        for(i=0;i<N;i++){   
            for(j=0;j<M;j++){
                if(oyunTahtasi[i][j] > '9'){
                    x = ((oyunTahtasi[i][j] - '0')/10) + '0';
                    y = ((oyunTahtasi[i][j] - '0')%10) + '0';
                    printf("|%c%c",x,y);
                }
                else{
                    printf("| %c",oyunTahtasi[i][j]);
                }
            }
            printf("|\n");
        }
    }

    // Oyunun bitmesi durumunda kullaniciya bilgiler verilir
    printf(" ---- --- --- --- --- ---- \n");
    if(carptiMi){
        printf("Kaybettiniz!\n%d hamlede %d buyukluge ulastiniz. Geriye %d yemek kaldi.",hamleSayisi-1,uzunluk,yemekSayisi);
    }
    else{
        printf("Tebrikler, kazandiniz!\n%d hamlede butun yemekleri yiyip %d buyuklugune ulastiniz!",hamleSayisi-1,uzunluk);
    }

    return 0;
}