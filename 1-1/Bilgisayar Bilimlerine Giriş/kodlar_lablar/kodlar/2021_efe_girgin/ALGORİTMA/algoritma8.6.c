#include <stdio.h>
int main(){
	int k,l,max,s,us;
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&k);
	
	l=0;
	max=k;
	us=0;
	s=0;
	while(k!=1){
		l=l+1;
		if(k%2!=0){
			k=3*k+1;
			us=0;
			if(k>max){
				max=k;
			}
			s=k;
			
		}
		else{
			us=us+1;
			k=k/2;
		}
	}
	printf("%d kadar islem surmustur,%d maximum degerimizdir,%d maximum degerin 2 nin kacinci kuvvet oldugunu soyler,%d sayisindan sonra hep cift olarak devam etmistir",l,max,us,s);
	return 0;
}
//kod calýsýyor
//bir k sayisi tek ise 3 ile carpýlýp 1 ekleniyor.çift ise 2 ye bolunuyor.islem k sayisi 1 olana kadar tekrar ediliyor.
//bu islemin kac adim surdugunu islem sirasinda k sayisinin aldigi maximum degeri k sayisinin hangi sayidan sonra hep cift olarak 1 e ulastýgýný ve bu sayinin ikinin kacinci kuvveti oldugnu bulan algoritma ve programi
//sayfa 8
