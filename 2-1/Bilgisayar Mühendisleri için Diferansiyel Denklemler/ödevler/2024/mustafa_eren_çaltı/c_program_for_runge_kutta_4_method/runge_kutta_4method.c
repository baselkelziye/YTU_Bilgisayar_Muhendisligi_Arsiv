 #include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.00002
#define PI 3.14159265

typedef struct{
	float katsayi;
	float derece;
}xliterim;

typedef struct{
	float katsayi;
	float derece;
	char tur;
	xliterim xli;
}terim;

terim *fonksiyonuAl(int *n){ // Kullanicidan terim sayisina gore dinamik bellek yonetimiyle alan acarak diferansiyel ifadeyi alan fonksiyon.
	terim *terimler;
	int i;	
	printf("\n------  Fonksiyon ay'= by + g(x) seklinde olacaktir.  {g(x) x'e bagli fonksiyonlardir.'}  ------\n\n");
	printf("Toplam terim sayisini giriniz: ");
	scanf("%d",n);
	terimler = (terim *)malloc((*n)*sizeof(terim));
	printf("(y')'li terimin katsayisini giriniz(a) :  ");
	scanf("%f",&(terimler[0].katsayi));
	printf("(y)'li terimin katsayisini giriniz(b) :  ");
	scanf("%f",&(terimler[1].katsayi));
	for(i=2; i<*n; i++){
		printf("\n%d. terimin turunu giriniz: (x=2, (g)sin(cx)=3, (f)(e^(dx)=4)? ",i+1);
		scanf(" %c",&(terimler[i].tur));
		printf("\n %c girdiginiz tur degeri. \n\n",terimler[i].tur);
		if(terimler[i].tur == '4'){
		printf("(f)e^(dx)'li terimde tum ifadenin katsayisini(f) girin: ");
		scanf("%f",&(terimler[i].katsayi));
		printf("(f)e^(dx)'li terimde x'li ifadenin katsayisini(d) girin: ");
		scanf("%f",&(terimler[i].xli.katsayi));
		}
		else if(terimler[i].tur == '3'){
		printf("(g)sin(cx)'li terimde tum ifadenin katsayisini(g) girin: ");
		scanf("%f",&(terimler[i].katsayi));
		printf("(g)sin(cx)'li terimde x'li ifadenin katsayisini(c) girin: ");
		scanf("%f",&(terimler[i].xli.katsayi));
		}
		else{
			printf("x'li teriminizin derecesini girin: ");
			scanf("%f",&(terimler[i].derece));
			printf("x'li teriminizin katsayisini girin: ");
			scanf("%f",&(terimler[i].katsayi));
		}	
	}
	return terimler;
}

void degerleriAl(float *xi, float *iterationNumber, float *yi, float *x, float*h, float *ilkDeger){
	int i;
	printf("Bildigimiz y(x) ifadesinin x'ini giriniz: ");
	scanf("%f",xi);
	printf("Bildigimiz y(x) ifadesinin degerini (y(x) = a) giriniz: ");
	scanf("%f",ilkDeger);
	printf("Hangi noktadaki degeri istiyorsunuz? (x)  ");
	scanf("%f",x);
	printf("Adim buyuklugunu giriniz : (h)   ");
	scanf("%f",h);
	*iterationNumber = (fabs((*x)-(float)(*xi)))/ *h;
	
	printf("\niteration number: %f\n",*iterationNumber); // Epsilon degeri float degerler arasi cikarma isleminde olusabilecek hatalardan dolayi eklenmistir.
	
}

float kiHesaplama(float xi, float yi , terim *terimler ,int n){ // verilen parametrelere gore k1 k2 k3 k4 degerlerini hesaplayan fonksiyon.
	int i=0;
	float toplam = 0;
	float hesaplama=0;
	toplam += terimler[1].katsayi * yi;
	
	for(i=2; i<n; i++){
		hesaplama = 0;
		// Terimin ne turde bir ifade olduguna gore (sinus, polinum, ustel) hesaplamalar.
		if(terimler[i].tur == '2')    
		hesaplama += pow(xi,terimler[i].derece) * terimler[i].katsayi;	
		
		else if(terimler[i].tur == '3')
		hesaplama += sin( ((float)(terimler[i].xli.katsayi * xi)) * PI / 180) * terimler[i].katsayi;
		
		else
		hesaplama += exp((float)terimler[i].xli.katsayi * xi) * terimler[i].katsayi;
		
		toplam += hesaplama;
	}
	toplam = toplam /  terimler[0].katsayi;
	return toplam;	
}

void hesaplama(float *xi, float *iterationNumber, float *yi, float *x, float h,terim *terimler, int n, float *ilkDeger){
	int i,j;
	float toplam = *ilkDeger;
	*yi = *ilkDeger;
	float k1,k2,k3,k4;
	if(((*x)-(float)(*xi)) < 0)
	h = -h;
	for(i=0; i<(int)*iterationNumber; i++){
		k1 = kiHesaplama (*xi,*yi,terimler,n); // k degerlerini hesaplamak icin yapilan islemler.
		k2 = kiHesaplama(*xi+ h/2,*yi+(k1* h / 2),terimler,n);
		k3 = kiHesaplama(*xi+ h/2,(*yi)+(k2* h / 2),terimler,n);
		k4 = kiHesaplama(*xi+ h,(*yi)+( k3 * h), terimler, n);
		toplam += (k1 + 2 * k2 + 2 * k3 + k4) * h / 6 ; 
		*xi += h;
		*yi = toplam;
		 printf("Iterasyon %d:  x = %f y = %f \n",i+1,*xi,*yi); // Her adimda kullaniciya iterasyon saiysi, x degeri ve y degerleri
	}
		
	printf("\nElde edilen sonuc : %f",toplam);
}

int main(){
	float iterationNumber;
	float x,h,yi,ilkDeger,xi;
	int i,n;
	terim *terimler;
	terimler = fonksiyonuAl(&n);
	degerleriAl(&xi,&iterationNumber,&yi,&x,&h,&ilkDeger);
	hesaplama(&xi,&iterationNumber,&yi,&x,h,terimler,n,&ilkDeger);
	
	free(terimler);
	
	return 0;
}
