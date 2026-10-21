#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    struct denklem {
        double polinomderece;
        double *polinomkatsayilar;
        double turevkatsayi;
        double ykatsayi;
        int iterasyon;
        double *ydegerleri;
        double h;
        double Xson;
    };

    double solveFunction(struct denklem *p, double x0, double y0){
        int i ;
        double tmp = 0.0;
        double polresult = 0.0;
        double lastResult = 0.0;
        tmp = p->polinomderece;
        for(i=0;i<p->polinomderece+1;i++){
            polresult += p->polinomkatsayilar[i] * pow(x0, tmp--);
        }
        lastResult = (polresult + (y0 * p->ykatsayi)) / p->turevkatsayi;
        return (lastResult);        
    }

    void rungekutta4(struct denklem *p, double x0, double y0){
        double k1 = 0.0;
        double k2 = 0.0; 
        double k3 = 0.0;
        double k4 = 0.0;
        int i;
        y0 = p->ydegerleri[0];

        // f(x,y) = f(x,y) + 1/6 ( K1 + 2K2 + 2K3 + K4 )
        for(i=0;i<p->iterasyon;i++){
            k1 =  solveFunction(p, x0, y0);
            k2 =  solveFunction(p, (x0 + (0.5 * p->h)), (y0 + (0.5 * (p->h * k1))));
            k3 =  solveFunction(p, (x0 + (0.5 * p->h)),(y0 + ( 0.5 * (p->h * k2))));
            k4 =  solveFunction(p, (x0 + p->h), (y0 + (p->h * k3)));
        

        // her iterasyonda y degerini guncelle
        p->ydegerleri[i+1] = p->ydegerleri[i] +  (p->h * ( k1 + 2 * k2 + 2 * k3 + k4 ) /  6.0 ) ;

        printf("%d. iterasyon : y(%d) =  y(%d) + 1/6 ( %lf + 2 * %lf + 2 * %lf + %lf ) \n", i+1, i+1 , i , k1, k2, k3, k4);
        printf("y(%d) = %lf \n\n", i+1, p->ydegerleri[i+1]);

        x0 += p->h;
        y0 = p->ydegerleri[i+1];
    }

}



int main (){
    int terimsayisi, iterasyon,polinomderece,i;
    double x, y0, h,x0,turevkatsayi,ykatsayi, gercekDeger,fark;
    struct denklem p;

// *****************************************************************************************************
// kullanicidan gereken tum bilgileri topluyoruz 

printf("----------------------------------------------------------------------------------------------");
    printf("\nRunge Kutta-4 metoduyla denklem koku yaklasim hesaplamasi programina hos geldiniz \n");

    printf("adim buyuklugunu (h) giriniz \n");
    scanf("%lf", &h);

    printf("bulmak istediginiz x degerini giriniz \n");
    scanf(" %lf" , &x);

    printf("x'in baslangic degerini giriniz (X0) \n");
    scanf("%lf", &x0);

    // kac iterasyon yapmamiz gerekecek onu hesapliyoruz
    iterasyon = ( x - x0 )/ h;
    p.iterasyon = iterasyon;
    p.h = h;

    printf("y'nin baslangic degerini giriniz (Y0) \n");
    scanf("%lf", &y0);

    p.ydegerleri = (double *) malloc ((iterasyon +1 ) * sizeof(double));
    if ( p.ydegerleri == NULL){
        printf(" bellek tahsisi basarisiz");
        return(1);
    }
    p.ydegerleri[0] = y0;

    printf("diferansiyel denklemi girmeye baslayalim ay'= p(x) + by \n\n");
    printf("dy/dx 'in katsyisi nedir? (a)\n");
    scanf("%lf", &p.turevkatsayi);
    printf("normal y'nin katsyisi nedir?(b)\n");
    scanf("%lf", &p.ykatsayi);   
    printf("a*x^n + b*x^(n-1) + ...\n");
    printf("en buyuk derceyi giriniz\n");
    scanf("%lf", &p.polinomderece);
    p.polinomkatsayilar = (double *) malloc ((p.polinomderece +1 ) * sizeof(double));
    if ( p.polinomkatsayilar == NULL){
        printf(" bellek tahsisi basarisiz");
        return(1);
    }            
    printf("simdi en buyuk dereceli terimden baslayarak katsayilari giriniz(+7 veya -5 gibi)\n");
    int k;
    for( k=0; k<(p.polinomderece + 1); k++){
        printf(" %d.terim:", k+1);
        scanf("%lf", &p.polinomkatsayilar[k]);
    }
//******************************************************************************************************

//denklemi kullaniciya kontrol ettiriyoruz
    int bool = 1;
    do
    {
        char onay;
        double tmp = 0.0;
        tmp = (p.polinomderece); 
        for(i=0;i<(p.polinomderece+1);i++){
            printf("(%lf) * x ^ %lf  ", p.polinomkatsayilar[i], tmp--);
        }
        printf("\ndenklemi kontrol edebilirsin , dogru mu ? (E yada H) \n");
        scanf(" %c", &onay);

        if(onay == 'E' || onay == 'e') 
        {
            printf("harika ! o zaman denklemi cozelimmm \n\n");
            bool = 0;
        }
        else if (onay == 'H' || onay =='h')
        {
            printf("yeniden girebilirsin \n\n");
            bool = 1;
        }
        else
        {
        printf("yalnis harf\n\n");
        bool = 1;
        }
    } while (bool == 1);

//simdi fonksiyonu cagirip hesaplamalari yapiyoruz
rungekutta4(&p,x0,y0);    

printf("gercek deger nedir ?");
scanf("%lf", &gercekDeger);
fark = p.ydegerleri[p.iterasyon] - gercekDeger; 
printf("numerik cozumle gercek cozum arasindaki mutlak hata : %lf",fark );

free(p.ydegerleri);
free(p.polinomkatsayilar);
return 0;         

}