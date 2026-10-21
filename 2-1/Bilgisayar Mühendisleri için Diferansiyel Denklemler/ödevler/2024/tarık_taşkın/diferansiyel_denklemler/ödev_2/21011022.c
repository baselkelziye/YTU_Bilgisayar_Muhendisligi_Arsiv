#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Terimler struct yapisinda tutulup, daha sonra butun terimler struct pointer'da dinamik bir sekilde saklanmistir.
struct Terim{
	int tip;	 //x icin 0, y icin 1, sabit icin 2
	double katsayi;
	int us;
};

void denklemAl(struct Terim* denklem, int n);
void denklemYazdir(struct Terim* denklem, int n);
double degerBul(struct Terim* denklem, int n, double x, double y);
void RK4(struct Terim* denklem, int n, double h, double x0, double y0, double xi, double gercekDeger);
void terimSayisiAl(int *n);
void parametreAl(double *x0, double *y0, double *xi, double *h, double *gercekDeger);
void parametreYazdir(double x0, double y0, double xi, double h);

int main(){
	int n;
	double h;
	double x0;
	double y0;
	double xi;
	double gercekDeger;
	struct Terim* denklem;

	terimSayisiAl(&n);	
	denklem = (struct Terim*) malloc(n*sizeof(struct Terim));
	
	denklemAl(denklem,n);
	parametreAl(&x0,&y0,&xi,&h,&gercekDeger);
	denklemYazdir(denklem,n);
	parametreYazdir(x0,y0,xi,h);
	RK4(denklem,n,h,x0,y0,xi,gercekDeger);
	
	free(denklem);
	
	return 0;
}

//Kullanicidan terim sayisini alir.
void terimSayisiAl(int *n){
	printf("y' = ...\n");
	do{
		printf("Denklemdeki terim sayisini giriniz: ");
		scanf("%d",n);
	}while(n<=0);
}

//Kullanicidan gerekli parametreleri alir.
void parametreAl(double *x0, double *y0, double *xi, double *h, double *gercekDeger){
	printf("\nGerekli parametreleri giriniz.\n");
	printf("   x0: ");			//Sonucu bilinen x degeri
	scanf("%lf",x0);
	printf("y(x0): ");			//x'in sonucu
	scanf("%lf",y0);
	printf("   xi: ");			//Sonucu istenen x degeri
	scanf("%lf",xi);
	printf("    h: ");			//Artis miktari
	scanf("%lf",h);
	printf("Gercek deger: ");	//y(x)'in gercek degeri
	scanf("%lf",gercekDeger);
}

//Alinan parametreleri yazdirir.
void parametreYazdir(double x0, double y0, double xi, double h){
	printf("y(%lf) = %lf, h = %lf, y(%lf) = ?\n\n",x0,y0,h,xi);
}

//Kullanýcýdan y' = ... seklinde denklemi alir.
void denklemAl(struct Terim* denklem, int n){
	int i;
	int tip;
	
	for(i=0;i<n;i++){
		do{
			printf("\n%d. terimin tipi (x:0, y:1, sabit:2): ",i+1);
			scanf(" %d",&tip);
		}while(tip!=0 && tip!=1 && tip!=2);
		denklem[i].tip = tip;
		switch(denklem[i].tip){
			case 0: 	//x'li terimin katsayisi ve ussu alinir.
				printf("%d. terimin katsayisi: ",i+1);
				scanf("%lf",&denklem[i].katsayi);
				printf("%d. terimin ussu     : ",i+1);
				scanf("%d",&denklem[i].us);
				break;
			case 1: 	//Denklem lineer oldugundan y'li terimin sadece katsayisi alinir. 
				printf("%d. terimin katsayisi: ",i+1);
				scanf("%lf",&denklem[i].katsayi);
				break;
			case 2: 	//Sabit terimi alinir.
				printf("%d. terimin katsayisi: ",i+1);
				scanf("%lf",&denklem[i].katsayi);
				break;
		}
	}
}

//Kullanicidan alinan denklemi yazdirir.
void denklemYazdir(struct Terim* denklem, int n){
	int i;
	
	printf("\ny' = ");
	for(i=0;i<n;i++){ 	//Katsayinin veya ussun 1 olmasi durumunda daha temiz bir gorunum icin katsayi ve ussu yazdirmaz.
		switch(denklem[i].tip){
			case 0:
				if(denklem[i].us == 1){
					if(denklem[i].katsayi == 1){
						printf("x ");
					}else{
						printf("%.2lf * x ",denklem[i].katsayi);
					}					
				}else{
					if(denklem[i].katsayi == 1){
						printf("x^%d ",denklem[i].us);
					}else{
						printf("%.2lf * x^%d ",denklem[i].katsayi,denklem[i].us);
					}
				}	
				break;
			case 1:
				if(denklem[i].katsayi == 1){
					printf("y ");
				}else{
					printf("%.2lf * y ",denklem[i].katsayi);
				}			
				break;
			case 2:
				printf("%.2lf ",denklem[i].katsayi);
				break;
		}
		if(i != n-1){
			printf("+ ");
		}
	}
	printf("\n");
}

//RK4 yontemi uygulanirken f(x,y) degerini hesaplar.
double degerBul(struct Terim* denklem, int n, double x, double y){
	double sonuc = 0;
	int i;
	
	for(i=0;i<n;i++){
		switch(denklem[i].tip){
			case 0:
				sonuc += pow(x,denklem[i].us) * denklem[i].katsayi;
				break;
			case 1:
				sonuc += y * denklem[i].katsayi;
				break;
			case 2:
				sonuc += denklem[i].katsayi;
				break;
		}
	}	
	
	return sonuc;
}

//Runge-Kutta 4 yontemini uygular.
void RK4(struct Terim* denklem, int n, double h, double x0, double y0, double xi, double gercekDeger){
	double x = x0;
	double y = y0;
	double k1, k2, k3, k4;
	double hata;
	int i = 1;
	
	printf("\t     Runge-Kutta 4 Yontemi\n");
	while(x+0.000001<xi){ 	//Cok kucuk x degerlerinde bir iterasyon fazladan calistigi icin x'e, 0.000001 eklenmistir.
		printf("%3d. Iterasyon: ",i++);
		k1 = degerBul(denklem, n, x, y);
		k2 = degerBul(denklem, n, x+(h/2), y+(0.5*k1*h));
		k3 = degerBul(denklem, n, x+(h/2), y+(0.5*k2*h));
		k4 = degerBul(denklem, n, x+h, y+(k3*h));
		y += ((k1+2*k2+2*k3+k4)*h/6); 	//y(i+1) = y(i) + (h/6)(k1 + 2*k2 + 2*k3 + k4)
		x += h;
		printf("x: %lf, y(x): %lf\n",x,y); 	//Her iterasyondaki x ve y(x) degerleri ekrana yazdirilir.
	}
	hata = fabs(gercekDeger - y);
	printf("\n RK4 cozumu: %lf\n",y);
	printf("       Hata: |%lf - %lf| = %lf\n",gercekDeger, y, hata); 	//Hata: |Gercek Deger - Sonuc|
	printf("Mutlak Hata: |%lf / %lf| = %lf\n",hata, gercekDeger, fabs(hata/gercekDeger)); // Mutlak Hata: |(Gercek Deger - Sonuc) / Gercek Deger| = |Hata / Gercek Deger|
}
