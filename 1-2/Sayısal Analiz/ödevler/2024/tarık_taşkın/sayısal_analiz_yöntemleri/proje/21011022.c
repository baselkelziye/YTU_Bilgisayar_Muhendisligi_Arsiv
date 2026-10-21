#include <stdio.h>
#include <stdlib.h> //system("cls")
#include <math.h> //fabs()
#define MAX 15

void polinomAl(double polinom[2][MAX],int* p);
void polinomYazdir(double polinom[2][MAX],int terimSayisi);
double usAlma(double x, int kuvvet);
double fonksiyonDegeri(double x, double polinom[2][MAX],int terimSayisi);
void turev(double polinom[2][MAX],int terimSayisi,double turevFonksiyonu[2][MAX],int* turevTerimSayisi);
void matrisAl(double matris[MAX][MAX],int boyut);
void matrisYazdir(double matris[MAX][MAX],int boyut);
void altMatrisOlustur(double matris[MAX][MAX], double altMatris[MAX][MAX], int N, int sutunNo);
double determinantAl(double matris[MAX][MAX], int N);
void birimMatrisOlustur(double matris[MAX][MAX],int boyut);
void tersMatrisOlustur(double matris[MAX][MAX],double birimMatris[MAX][MAX],int boyut);
double simpsonYontemi(double polinom[MAX][MAX],int terimSayisi, double baslangic, double bitis, int n);
void denklemYazdir(double matris[MAX][MAX],int boyut);
void denklemAl(double matris[MAX][MAX], int boyut);
void denklemCoz(double matris[MAX][MAX],int boyut);
void satirDegistir(double matris[MAX][MAX], int satir1, int satir2, int boyut);
void konsolTemizle();

int main(){
    double polinom[2][MAX];
    double turevFonksiyonu[2][MAX];
    double matris[MAX][MAX];
    double tersMatris[MAX][MAX];
    double deger[MAX][MAX];
    int secim,terimSayisi;
    int turevTerimSayisi;
    double baslangic,bitis,ortaNokta;
    double gercekDeger;
    double epsilon;
    int durmaKosulu;
    int iterasyonSayisi;
    int boyut;
    double determinant;
    double x,h;
    double n;
    double sonuc,entSonuc;
    double ileriFark, geriFark, merkeziFark;
    int i,k,t;
    int maks;
    double j;
    
    do{
        printf("\n0  : Cikis\n1  : Bisection Yontemi\n2  : Regula-Falsi Yontemi\n3  : Newton-Raphson Yontemi\n");
        printf("4  : NxN'lik Matrisin Tersi\n5  : Gauss Eleminasyon Yontemi\n6  : Gauss-Seidal Yontemi\n7  : Sayisal Turev\n");
        printf("8  : Simpson Yontemi (1/3 ve 1/8)\n9  : Trapez Yontemi\n10 : Gregory Newton Enterpolasyonu\n");
        printf("Seciminiz : ");
        scanf("%d",&secim);

        switch(secim){
            case 0:
                break;
            case 1: //Bisection Yontemi
                printf("\n  ---  Bisection Yontemi  ---  ");
                polinomAl(polinom,&terimSayisi);
                polinomYazdir(polinom,terimSayisi);
                
                printf("\nBaslangic Degeri : ");
                scanf("%lf",&baslangic);
                printf("Bitis Degeri     : ");
                scanf("%lf",&bitis);
                printf("Hata Miktari     : ");
                scanf("%lf",&epsilon);
                printf("Durma Kosulu     :\n1- (b-a) / 2^n < Epsilon\n2- |p-xn| < Epsilon\nSeciminiz        : ");
                scanf("%d",&durmaKosulu);
                if(durmaKosulu == 2){
                    printf("Gercek Deger     : ");
                    scanf("%lf",&gercekDeger);
                }
                printf("Maksimum Iterasyon Sayisi: ");
                scanf("%d",&iterasyonSayisi);
                
                if(durmaKosulu == 1){
                    i=0;
                    while(i<iterasyonSayisi){
                        ortaNokta = (baslangic + bitis) / 2;

                        printf("\t%d. Iterasyon\t\n",i+1);
                        printf("Baslangic    : %lf\n",baslangic);
                        printf("Bitis        : %lf\n",bitis);
                        printf("Orta         : %lf\n",ortaNokta);
                        printf("f(Baslangic) : %lf\n",fonksiyonDegeri(baslangic,polinom,terimSayisi));
                        printf("f(Bitis)     : %lf\n",fonksiyonDegeri(bitis,polinom,terimSayisi));
                        printf("f(Orta)      : %lf\n",fonksiyonDegeri(ortaNokta,polinom,terimSayisi));

                        if(fonksiyonDegeri(ortaNokta,polinom,terimSayisi) * fonksiyonDegeri(bitis,polinom,terimSayisi) < 0){
                            baslangic = ortaNokta;
                        }
                        else{
                            bitis = ortaNokta;
                        }

                        if((bitis - baslangic)/usAlma(2,i+1) < epsilon){
                            i = iterasyonSayisi;
                        }
                        else{
                            i++;
                        }
                    } 
                }
                else{
                    i=0;
                    while(i<iterasyonSayisi){
                        ortaNokta = (baslangic + bitis) / 2;

                        printf("\t%d. Iterasyon\t\n",i+1);
                        printf("Baslangic    : %lf\n",baslangic);
                        printf("Bitis        : %lf\n",bitis);
                        printf("Orta         : %lf\n",ortaNokta);
                        printf("f(Baslangic) : %lf\n",fonksiyonDegeri(baslangic,polinom,terimSayisi));
                        printf("f(Bitis)     : %lf\n",fonksiyonDegeri(bitis,polinom,terimSayisi));
                        printf("f(Orta)      : %lf\n",fonksiyonDegeri(ortaNokta,polinom,terimSayisi));

                        if(fonksiyonDegeri(ortaNokta,polinom,terimSayisi) * fonksiyonDegeri(bitis,polinom,terimSayisi) < 0){
                            baslangic = ortaNokta;
                        }
                        else{
                            bitis = ortaNokta;
                        }

                        if(fabs(gercekDeger - ortaNokta) < epsilon){
                            i = iterasyonSayisi;
                        }
                        else{
                            i++;
                        }
                    }
                }
                printf("Sonuc        : %lf\n",ortaNokta);
                konsolTemizle();
                break;
            case 2: //Regula-Falsi Yontemi
                printf("\n  ---  Regula-Falsi Yontemi  ---  ");
                polinomAl(polinom,&terimSayisi);
                polinomYazdir(polinom,terimSayisi);
                
                printf("\nBaslangic Degeri : ");
                scanf("%lf",&baslangic);
                printf("Bitis Degeri     : ");
                scanf("%lf",&bitis);
                printf("Hata Miktari     : ");
                scanf("%lf",&epsilon);
                printf("Durma Kosulu     :\n1- (b-a) / 2^n < Epsilon\n2- |p-xn| < Epsilon\nSeciminiz        : ");
                scanf("%d",&durmaKosulu);
                if(durmaKosulu == 2){
                    printf("Gercek Deger     : ");
                    scanf("%lf",&gercekDeger);
                }
                printf("Maksimum Iterasyon Sayisi: ");
                scanf("%d",&iterasyonSayisi);
                
                if(durmaKosulu == 1){
                    i=0;
                    while(i<iterasyonSayisi){
                        ortaNokta = (bitis * fonksiyonDegeri(baslangic,polinom,terimSayisi) - baslangic * fonksiyonDegeri(bitis,polinom,terimSayisi)) / (fonksiyonDegeri(baslangic,polinom,terimSayisi) - fonksiyonDegeri(bitis,polinom,terimSayisi));

                        printf("\t%d. Iterasyon\t\n",i+1);
                        printf("Baslangic    : %lf\n",baslangic);
                        printf("Bitis        : %lf\n",bitis);
                        printf("Orta         : %lf\n",ortaNokta);
                        printf("f(Baslangic) : %lf\n",fonksiyonDegeri(baslangic,polinom,terimSayisi));
                        printf("f(Bitis)     : %lf\n",fonksiyonDegeri(bitis,polinom,terimSayisi));
                        printf("f(Orta)      : %lf\n",fonksiyonDegeri(ortaNokta,polinom,terimSayisi));

                        if(fonksiyonDegeri(ortaNokta,polinom,terimSayisi) * fonksiyonDegeri(bitis,polinom,terimSayisi) < 0){
                            baslangic = ortaNokta;
                        }
                        else{
                            bitis = ortaNokta;
                        }

                        if((bitis - baslangic)/usAlma(2,i+2) < epsilon){
                            i = iterasyonSayisi;
                        }
                        else{
                            i++;
                        }
                    } 
                }
                else{
                    i=0;
                    while(i<iterasyonSayisi){
                        ortaNokta = (bitis * fonksiyonDegeri(baslangic,polinom,terimSayisi) - baslangic * fonksiyonDegeri(bitis,polinom,terimSayisi)) / (fonksiyonDegeri(baslangic,polinom,terimSayisi) - fonksiyonDegeri(bitis,polinom,terimSayisi));

                        printf("\t%d. Iterasyon\t\n",i+1);
                        printf("Baslangic    : %lf\n",baslangic);
                        printf("Bitis        : %lf\n",bitis);
                        printf("Orta         : %lf\n",ortaNokta);
                        printf("f(Baslangic) : %lf\n",fonksiyonDegeri(baslangic,polinom,terimSayisi));
                        printf("f(Bitis)     : %lf\n",fonksiyonDegeri(bitis,polinom,terimSayisi));
                        printf("f(Orta)      : %lf\n",fonksiyonDegeri(ortaNokta,polinom,terimSayisi));

                        if(fonksiyonDegeri(ortaNokta,polinom,terimSayisi) * fonksiyonDegeri(bitis,polinom,terimSayisi) < 0){
                            baslangic = ortaNokta;
                        }
                        else{
                            bitis = ortaNokta;
                        }

                        if(fabs(gercekDeger - ortaNokta) < epsilon){
                            i = iterasyonSayisi;
                        }
                        else{
                            i++;
                        }
                    }
                }
                printf("Sonuc        : %lf\n",ortaNokta);
                konsolTemizle();
                break;
            case 3: //Newton-Raphson Yontemi
                printf("\n  ---  Newton-Raphson Yontemi  ---  ");
                polinomAl(polinom,&terimSayisi);
                polinomYazdir(polinom,terimSayisi);
                turev(polinom,terimSayisi,turevFonksiyonu,&turevTerimSayisi);

                printf("\nBaslangic Degeri : ");
                scanf("%lf",&baslangic);
                printf("Hata Miktari     : ");
                scanf("%lf",&epsilon);
                printf("Durma Kosulu     :\n1- |p-xn| < Epsilon\n2- |x(n+1)-x(n)| < Epsilon\nSeciminiz        : ");
                scanf("%d",&durmaKosulu);
                if(durmaKosulu == 1){
                    printf("Gercek Deger     : ");
                    scanf("%lf",&gercekDeger);
                }
                printf("Maksimum Iterasyon Sayisi: ");
                scanf("%d",&iterasyonSayisi);
                
                if(durmaKosulu == 1){
                    i=0;
                    while(i<iterasyonSayisi){
                        ortaNokta = baslangic - (fonksiyonDegeri(baslangic,polinom,terimSayisi)/fonksiyonDegeri(baslangic,turevFonksiyonu,turevTerimSayisi));
                        printf("\t%d. Iterasyon\t\n",i+1);
                        printf("x(n)     : %lf\n",baslangic);
                        printf("x(n+1)   : %lf\n",ortaNokta);
                        printf("f(x(n))  : %lf\n",fonksiyonDegeri(baslangic,polinom,terimSayisi));
                        printf("f'(x(n)) : %lf\n",fonksiyonDegeri(baslangic,turevFonksiyonu,turevTerimSayisi));
                        
                        if(fabs(gercekDeger - ortaNokta) < epsilon){
                            i = iterasyonSayisi;
                        }
                        else{
                            baslangic = ortaNokta;
                            i++;
                        }
                    } 
                }
                else{
                    i=0;
                    while(i<iterasyonSayisi){
                        ortaNokta = baslangic - (fonksiyonDegeri(baslangic,polinom,terimSayisi)/fonksiyonDegeri(baslangic,turevFonksiyonu,turevTerimSayisi));
                        printf("\t%d. Iterasyon\t\n",i+1);
                        printf("x(n)     : %lf\n",baslangic);
                        printf("x(n+1)   : %lf\n",ortaNokta);
                        printf("f(x(n))  : %lf\n",fonksiyonDegeri(baslangic,polinom,terimSayisi));
                        printf("f'(x(n)) : %lf\n",fonksiyonDegeri(baslangic,turevFonksiyonu,turevTerimSayisi));
                        
                        if(fabs(ortaNokta - baslangic) < epsilon){
                            i = iterasyonSayisi;
                        }
                        else{
                            baslangic = ortaNokta;
                            i++;
                        }
                    }
                }
                printf("Sonuc    : %lf\n",ortaNokta);
                konsolTemizle();
                break;
            case 4: //NxN'lik Matrisin Tersi
                printf("\n  ---  NxN'lik Matrisin Tersi  ---  \n");
                printf("Matrisin boyutunu giriniz : ");
                scanf("%d",&boyut);
                matrisAl(matris,boyut);
                printf("\tGirilen Matris\n");
                matrisYazdir(matris,boyut);

                determinant = determinantAl(matris,boyut);
                if(determinant == 0){
                    printf("Matrisin determinanti 0 oldugu icin matrisin tersi yoktur.\n");
                }
                else{
                    birimMatrisOlustur(tersMatris,boyut);
                    tersMatrisOlustur(matris,tersMatris,boyut);
                    printf("\tTers Matris\n");
                    matrisYazdir(tersMatris,boyut);
                }
                konsolTemizle();
                break;
            case 5: //Gauss Eleminasyon Yontemi
                printf("\n  ---  Gauss Eleminasyon Yontemi  ---  \n");
                printf("Degisken (denklem) sayisini giriniz : ");
                scanf("%d",&boyut);
                denklemAl(matris,boyut);
                printf("\n\t\tDenklem Sistemi\n");
                denklemYazdir(matris,boyut);
                printf("\n");

                determinant = determinantAl(matris,boyut);
                if(determinant != 0){
                    denklemCoz(matris,boyut);
                    for(i=0;i<boyut;i++){
                        printf("x%d : %lf\n",i+1,matris[boyut][i]);
                    }
                }
                else{
                    printf("Denklem sisteminin cozumu yok ya da sonsuz cozumu var.\n");
                }
                konsolTemizle();
                break;
            case 6: //Gauss-Seidal Yontemi
                printf("\n  ---  Gauss-Seidal Yontemi  ---  \n");
                printf("Degisken (denklem) sayisini giriniz : ");
                scanf("%d",&boyut);
                denklemAl(matris,boyut);
                printf("\n\t\tDenklem Sistemi\n");
                denklemYazdir(matris,boyut);
                printf("Hata Miktari     : ");
                scanf("%lf",&epsilon);
                printf("Baslangic degerlerini giriniz.\n");
                for(i=0;i<boyut;i++){
                    printf("x%d : ",i+1);
                    scanf("%lf",&matris[boyut+1][i]);                      
                }

                for(i=0;i<boyut-1;i++){
                    maks = i;
                    for(k=i+1;k<boyut;k++){
                        if(fabs(matris[k][i]) > fabs(matris[maks][i])){
                            maks = k;
                        }
                    }
                    if(maks != i){
                        satirDegistir(matris,i,maks,boyut);
                    }
                }
                
                printf("\t1. Iterasyon\t\n");
                for(k=0;k<boyut;k++){
                    printf("  x%d : %lf\n",k+1,matris[boyut+1][k]);
                    printf("/%cx%d : -\n",92,k+1);
                }
                i=2;
                while(i != 1){
                    for(k=0;k<boyut;k++){
                        matris[boyut][k] = matris[boyut+1][k];       // boyut. satir eski deger
                        matris[boyut+1][k] = matris[k][boyut];       // boyut+1. satir yeni deger
                        for(t=0;t<boyut;t++){
                            if(t != k){
                                matris[boyut+1][k] = matris[boyut+1][k] - matris[k][t]*matris[boyut+1][t];
                            }
                        }
                        matris[boyut+1][k] = matris[boyut+1][k] / matris[k][k];
                    }
                    
                    t=0;
                    printf("\t%d. Iterasyon\t\n",i);
                    for(k=0;k<boyut;k++){
                        printf("  x%d : %lf\n",k+1,matris[boyut+1][k]);
                        printf("/%cx%d : %lf\n",92,k+1,fabs(matris[boyut][k] - matris[boyut+1][k]));

                        if(fabs(matris[boyut][k] - matris[boyut+1][k]) < epsilon){
                            t++;
                        }
                    }

                    if(t == boyut){
                        i = 1;
                    }
                    else{
                        i++;
                    }
                }

                printf("\n\tSonuc\t\n");
                for(i=0;i<boyut;i++){
                    printf("  x%d : %lf\n",i+1,matris[boyut+1][i]);
                }
                konsolTemizle();
                break;
            case 7: //Sayisal Turev
                printf("\n  ---  Sayisal Turev  ---  ");
                polinomAl(polinom,&terimSayisi);
                polinomYazdir(polinom,terimSayisi);
                turev(polinom,terimSayisi,turevFonksiyonu,&turevTerimSayisi);
                printf("\nx Noktasi : ");
                scanf("%lf",&x);
                printf("h Araligi : ");
                scanf("%lf",&h);

                ileriFark = (fonksiyonDegeri(x+h,polinom,terimSayisi) - fonksiyonDegeri(x,polinom,terimSayisi)) / h;
                geriFark = (fonksiyonDegeri(x,polinom,terimSayisi) - fonksiyonDegeri(x-h,polinom,terimSayisi)) / h;
                merkeziFark = (fonksiyonDegeri(x+h,polinom,terimSayisi) - fonksiyonDegeri(x-h,polinom,terimSayisi)) / (2*h);
                printf("\nGeri Farklar    : %lf\n",geriFark);
                printf("Ileri Farklar   : %lf\n",ileriFark);
                printf("Merkezi Farklar : %lf\n",merkeziFark);
                printf("Analitik Cozum  : %lf\n",fonksiyonDegeri(x,turevFonksiyonu,turevTerimSayisi));
                konsolTemizle();
                break;
            case 8: //Simpson Yontemi (1/3 ve 1/8)
                printf("\n  ---  Simpson Yontemi (1/3 ve 1/8)  ---  ");
                polinomAl(polinom,&terimSayisi);
                polinomYazdir(polinom,terimSayisi);

                printf("\nIntegral Alt Siniri    : ");
                scanf("%lf",&baslangic);    // Tekrar degisken kullanmamak icin altSinir = baslangic
                printf("Integral Ust Siniri    : ");
                scanf("%lf",&bitis);        // Tekrar degisken kullanmamak icin ustSinir = bitis
                printf("Aralik Sayisi (n:cift) : ");
                scanf("%lf",&n);

                h = (bitis - baslangic) / n;
                sonuc = fonksiyonDegeri(baslangic,polinom,terimSayisi) + fonksiyonDegeri(bitis,polinom,terimSayisi);
                for(j=baslangic+h;j<bitis;j=j+(2*h)){
                    sonuc = sonuc + 4*fonksiyonDegeri(j,polinom,terimSayisi);
                }
                for(j=baslangic+(2*h);j<bitis;j=j+(2*h)){
                    sonuc = sonuc + 2*fonksiyonDegeri(j,polinom,terimSayisi);
                }
                
                sonuc = (sonuc * h)/3;
                printf("\nh Degeri               : %lf\n",h);
                printf("Simpson 1/3 Sonucu     : %lf\n",sonuc);
                printf("Simpson 3/8 Sonucu     : %lf\n",simpsonYontemi(polinom,terimSayisi,baslangic,bitis,n));
                konsolTemizle();
                break;
            case 9: //Trapez Yontemi
                printf("\n  ---  Sayisal Turev  ---  ");
                polinomAl(polinom,&terimSayisi);
                polinomYazdir(polinom,terimSayisi);

                printf("\nIntegral Alt Siniri : ");
                scanf("%lf",&baslangic);    // Tekrar degisken kullanmamak icin altSinir = baslangic
                printf("Integral Ust Siniri : ");
                scanf("%lf",&bitis);        // Tekrar degisken kullanmamak icin ustSinir = bitis
                printf("Aralik Sayisi  (n)  : ");
                scanf("%lf",&n);

                h = (bitis - baslangic) / n;
                sonuc = (fonksiyonDegeri(baslangic,polinom,terimSayisi) + fonksiyonDegeri(bitis,polinom,terimSayisi)) / 2;
                for(j=baslangic+h;j<bitis;j=j+h){
                    sonuc = sonuc + fonksiyonDegeri(j,polinom,terimSayisi);
                }
                sonuc = sonuc * h;
                printf("Toplam Alan         : %lf\n",sonuc);
                konsolTemizle();
                break;
            case 10: //Gregory Newton Enterpolasyonu
                printf("\n  ---  Gregory Newton Enterpolasyonu  ---  \n");
                printf("Hesaplanacak Deger : ");
                scanf("%lf",&x);
                printf("Baslangic Degeri   : ");
                scanf("%lf",&baslangic);
                printf("Artis Miktari (h)  : ");
                scanf("%lf",&h);
                printf("Terim Sayisi       : ");
                scanf("%d",&terimSayisi);
                printf("\n");

                for(i=0;i<terimSayisi;i++){
                    printf("f(%lf) : ",baslangic);
                    scanf("%lf",&deger[i][0]);     // 0. sutun fonksiyon degerlerini icerir.
                    baslangic = baslangic + h;
                }
                baslangic = baslangic - (terimSayisi)*h;

                for(i=1;i<terimSayisi;i++){        // 1. sutundan itibaren sutunlar ardasik iki terim arasindaki farki belirtir
                    for(k=terimSayisi-1;k>=i;k--){             
                        deger[k][i] = deger[k][i-1] - deger[k-1][i-1];
                    }
                }

                printf("\n\tSonlu Farklar Tablosu\t\n");
                matrisYazdir(deger,terimSayisi);

                sonuc = deger[0][0];
                for(i=1;i<terimSayisi;i++){
                    entSonuc = 1;
                    geriFark = 0;
                    for(k=1;k<i+1;k++){
                        entSonuc = entSonuc * (x-baslangic)/(h*k);
                        baslangic = baslangic + h; 
                    }
                    baslangic = baslangic - (i*h);
                    sonuc = sonuc + (entSonuc*deger[i][i]);
                }
                printf("\nf(%lf) : %lf\n",x,sonuc);
                konsolTemizle();
                break;
            default:
                printf("0 ile 10 arasi secim yapmaniz gerekiyor. Lutfen tekrar deneyin.\n");
        }
    }while(secim != 0);

    return 0;
}

void polinomAl(double polinom[2][MAX],int* p){
    int i,terimSayisi;
    printf("\nFonksiyonun terim sayisi : ");
    scanf("%d",&terimSayisi);
    *p = terimSayisi;
    for(i=0;i<terimSayisi;i++){
        printf("%d. terimin katsayisi     : ",i+1);
        scanf("%lf",&polinom[0][i]);
        printf("%d. terimin kuvveti       : ",i+1);
        scanf("%lf",&polinom[1][i]);
    }
}

void polinomYazdir(double polinom[2][MAX],int terimSayisi){
    int i;

    printf("Fonksiyon : ");
    for(i=0;i<terimSayisi-1;i++){
        if(polinom[1][i]==0){
            printf("%lf + ",polinom[0][i]);
        }
        else{
            printf("%lf * x^%lf + ",polinom[0][i],polinom[1][i]);
        }
    }
    if(polinom[1][i]==0){
            printf("%lf ",polinom[0][i]);
        }
        else{
            printf("%lf * x^%lf",polinom[0][i],polinom[1][i]);
        }
    printf("\n");
}

double usAlma(double x, int kuvvet){
    int i;
    double sonuc=1;

    if(kuvvet>0){
        for(i=0;i<kuvvet;i++){
        sonuc = sonuc * x;
        }
    }
    else{
        for(i=kuvvet;i<0;i++){
        sonuc = sonuc / x;
        }
    }

    return sonuc;
}

double fonksiyonDegeri(double x, double polinom[2][MAX],int terimSayisi){
    int i;
    double sonuc=0;

    for(i=0;i<terimSayisi;i++){
        sonuc = sonuc + (polinom[0][i] * usAlma(x,polinom[1][i]));
    }

    return sonuc;
}

void turev(double polinom[2][MAX],int terimSayisi,double turevFonksiyonu[2][MAX],int* turevTerimSayisi){
    int i,j=0;
    
    for(i=0;i<terimSayisi;i++){
        if(polinom[1][i] != 0){
            turevFonksiyonu[0][j] = polinom[0][i] * polinom[1][i];
            turevFonksiyonu[1][j] = polinom[1][i] - 1;
            j++;
        }
    }
    *turevTerimSayisi = j;
}

void matrisAl(double matris[MAX][MAX],int boyut){
    int i,j;

    for(i=0;i<boyut;i++){
        for(j=0;j<boyut;j++){
            printf("[%d][%d]. eleman: ",i+1,j+1);
            scanf("%lf",&matris[i][j]);
        }
    }
}

void matrisYazdir(double matris[MAX][MAX],int boyut){
    int i,j;

    for(i=0;i<boyut;i++){
        for(j=0;j<boyut;j++){
            printf("[%lf] ",matris[i][j]);
        }
        printf("\n");
    }
}

void altMatrisOlustur(double matris[MAX][MAX], double altMatris[MAX][MAX], int boyut, int sutunNo){
    int i,j;
    int sutun=0;

    for(i=0;i<boyut;i++){
        if(i != sutunNo){
            for(j=1;j<boyut;j++){
                altMatris[j-1][sutun] = matris[j][i];
            }
            sutun++;
        }
    }
}

double determinantAl(double matris[MAX][MAX], int boyut){
    int i;
    double determinant=0;
    double altMatris[MAX][MAX];

    if(boyut == 1){
        return matris[0][0];
    }
    else if(boyut == 2){
        return ((matris[0][0] * matris[1][1]) - (matris[0][1] * matris[1][0]));
    }
    else{
        for(i=0;i<boyut;i++){
            altMatrisOlustur(matris,altMatris,boyut,i);
            determinant = determinant + usAlma(-1,i)*matris[0][i]*(determinantAl(altMatris,boyut-1));
        }
        
    }

    return determinant;
}

void birimMatrisOlustur(double matris[MAX][MAX],int boyut){
    int i,j;

    for(i=0;i<boyut;i++){
        for(j=0;j<boyut;j++){
            matris[i][j] = 0;
        }
        
    }
    for(i=0;i<boyut;i++){
        matris[i][i] = 1;
    }
}

void tersMatrisOlustur(double matris[MAX][MAX],double birimMatris[MAX][MAX],int boyut){
    int i,j,k;
    double kosegen;

    for(i=0;i<boyut;i++){
        kosegen = matris[i][i];
        for(j=0;j<boyut;j++){
            matris[i][j] = matris[i][j] / kosegen;
            birimMatris[i][j] = birimMatris[i][j] / kosegen;
        }
        for(j=0;j<boyut;j++){
            if(i != j){
                kosegen = matris[j][i];
                for(k=0;k<boyut;k++){
                    matris[j][k] = matris[j][k] - (kosegen*matris[i][k]);
                    birimMatris[j][k] = birimMatris[j][k] - (kosegen*birimMatris[i][k]);
                }
            }
        }
        
    }
}

double simpsonYontemi(double polinom[MAX][MAX],int terimSayisi, double baslangic, double bitis, int n){
    double sonuc = 0;
    double h = (bitis - baslangic) / (3*n);
    double i;
    

    for(i=baslangic;i<bitis;i=i+(3*h)){
        sonuc = sonuc + (fonksiyonDegeri(i,polinom,terimSayisi) + (3*fonksiyonDegeri(i+h,polinom,terimSayisi))+ (3*fonksiyonDegeri(i+(2*h),polinom,terimSayisi)) + (1*fonksiyonDegeri(i+(3*h),polinom,terimSayisi)));
    }

    sonuc = (((bitis - baslangic) / n) * sonuc)/ 8;
    return sonuc;
}

void denklemAl(double matris[MAX][MAX], int boyut){
    int i,j;

    printf("Degiskenlerin katsayilarini giriniz.\n");
    for(i=0;i<boyut;i++){
        printf("\t%d. Denklem\t\n",i+1);
        for(j=0;j<boyut;j++){
            printf("x%d : ",j+1);
            scanf("%lf",&matris[i][j]);
        }
        printf("   = ");  // x1 + ... + xn
        scanf("%lf",&matris[i][j]);
    }
}

void denklemYazdir(double matris[MAX][MAX],int boyut){
    int i,j;

    for(i=0;i<boyut;i++){
        for(j=0;j<boyut-1;j++){
            printf("%lf * x%d + ",matris[i][j],j+1);
        }
        printf("%lf * x%d = %lf\n",matris[i][j],j+1,matris[i][j+1]);
    }
}

void denklemCoz(double matris[MAX][MAX],int boyut){
    /*
        N denklem icin N+1. sutun denklemlerdeki sonucları belirtir. 
        (x+y = 7, x-y = 1 denklemleri icin 7 ve 1 degerleri)
        N+1. satir ise ust ucgen matris olusturulduktan sonra her bir degiskenin degerini belirtir. 
        (ustteki denkleme gore 4 ve 3)
    */

    double kosegen;
    int i,j,k;

    for(i=0;i<boyut;i++){
        kosegen = matris[i][i];
        for(j=0;j<boyut+1;j++){
            matris[i][j] = matris[i][j] / kosegen;
        }
        for(j=i+1;j<boyut;j++){
            kosegen = matris[j][i];
            for(k=0;k<boyut+1;k++){
                matris[j][k] = matris[j][k] / kosegen;
                matris[j][k] = matris[j][k] - matris[i][k];
                matris[j][k] = matris[j][k] * kosegen;
            }
        }
    }

    for(i=boyut-1;i>-1;i--){
        matris[boyut][i] = matris[i][boyut];
        for(j=i;j<boyut-1;j++){
            matris[boyut][i] = matris[boyut][i] - matris[i][j+1]*matris[boyut][j+1];
        }
    }   
}

void satirDegistir(double matris[MAX][MAX], int satir1, int satir2, int boyut){
    int i;
    double gecici;

    for(i=0;i<boyut+1;i++){
        gecici = matris[satir1][i];
        matris[satir1][i] = matris[satir2][i];
        matris[satir2][i] = gecici;
    }
}

void konsolTemizle(){
    int secim;
    printf("\n ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----  \n");
    printf("Konsolu temizlemek istiyorsaniz 1'i istemiyorsaniz 0'i tuslayin : ");
    scanf("%d",&secim);

    if(secim == 1){
        system("cls");
    }
}
