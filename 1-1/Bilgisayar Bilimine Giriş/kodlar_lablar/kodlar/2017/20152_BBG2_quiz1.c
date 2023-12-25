#include <stdio.h> //printf ve scanf için
#include <stdbool.h> // bool deðiþken tanýmlayabilmek için
#include <stdlib.h> // system("PAUSE") ve system("CLS") kodlarýný kullanabilmek için

//20152 BBG2 (MFA) 1. Quiz Sorusu Cevabý
//Soru: Tanim ve deger kumesi kullanicidan alinacak sekilde f(x) = 2x + 1 fonksiyonun verilen kumeler icin birebir ve orten olup olmadýgini bulunuz.

//c fonksiyonlarinin uygulamasi yapilmadigi icin binary search fonksiyon olarak yazilmamistir.
bool binarySearch(int *dizi, int son, int ara);

int main(){
	int t, d, tanim[50], deger[50], i, j, sonuc[50], tmp, ara, a, b;
	int ilk, son, orta; //binary search icin kullanilacak degerler
	bool bul, birebir;
	
	printf("Soru: Tanim ve deger kumesi kullanicidan alinacak sekilde f(x) = ax + b fonksiyonun verilen kumeler icin birebir ve orten olup olmadigini bulunuz.\n");
	printf("Kume teorisi geregi ayni elemanin bir kumede birden fazla bulunmasina izin verilmemistir !\n\n");
	printf("Tanim dizisinin boyutunu giriniz: ");
	scanf("%d", &t);
	
	printf("\nDeger dizisinin boyutunu giriniz: ");
	scanf("%d", &d);
	
	if(d == t){
		
		printf("\nTanim kumesini giriyorsunuz ...\n");
		for(i = 0; i < t; i++){
			do{
	      		printf("tanim[%d]:  ", i);
	      		scanf("%d", &tanim[i]);
	      	}while(binarySearch(tanim, i-1,tanim[i]));
		}
		
		printf("\nDeger kumesini giriyorsunuz ...\n");
		for(j = 0; j < d; j++){
			do{
	      		printf("deger[%d]:  ", j);
	      		scanf("%d", &deger[j]);
	      	}while(binarySearch(deger, j-1,deger[j]));
		}
		
		printf("\na: ");
		scanf("%d", &a);
		printf("b: ");
		scanf("%d", &b);
		
		//deger kumesi kucukten buyuge siralaniyor. Binary search icin.
		for(i = 1; i < d; i++){
			tmp = deger[i];
			j = i - 1;
			while(j >= 0 && deger[j] > tmp){
				deger[j+1] = deger[j];
				j = j - 1;
			}
			deger[j+1] = tmp;
		}
		
		i = 0;
		birebir = true;
		while(i < t && birebir){
			ara = a * (tanim[i]) + b; //tanim kumesinin ilgili elemanini fonksiyondan geciriyoruz. 
			ilk = 0;
			son = d - 1;
			orta = (ilk + son)/2;
			bul = false;
			//tanim kumesinin ilgili elemaninin fonksiyon sonucu binary search ile deger kumesinde araniyor.
			while((ilk <= son) && !bul){
		   		if(deger[orta] == ara){
		   			bul = true;
		   		}else{
			      	if (deger[orta] < ara )
			         	ilk = orta + 1;    
			      	else 
			         	son = orta - 1;
			 		orta = (ilk + son)/2;
		   		}
		   	}
		   	if(!bul)	   		
		   		birebir = false;
		   	i++;
		}
		
		if(birebir)
			printf("\nGirilen degerler icin fonksiyon, birebir ve orten bir fonksiyondur. \n");
		else
			printf("\nGirilen degerler icin fonksiyon, birebir ve orten degildir! \n");	
	}else{
		printf("\nTanim kumesinin boyutu, deger kumesinin boyutundan farkli oldugu icin, fonksiyon birebir ve orten degidir !\n");
	}
	
	system("PAUSE");
	return 0;
}

//Bir kumede ayný elemanin birden fazla defa olamayacagi kontrol edildi.
bool binarySearch(int *dizi, int son, int ara){
	int ilk = 0;
	int orta = (ilk+son)/2;
	bool bul = false;
	 
	while((ilk <= son) && !bul){
		if(dizi[orta] == ara){
			bul = true;
		}else{
	  		if (dizi[orta] < ara )
	       		ilk = orta + 1;    
		    else 
		       	son = orta - 1;
		 	orta = (ilk + son)/2;
	   	}
	}
	return bul;
}
