#include <stdio.h>

int main(){
	//degiskenleri tanýmladýk
	int yas,yil,dogumYili;
	
	
	//kullanýcýdan yillari aldik
	printf("lutfen yili giriniz \n");
	scanf("%d",&yil);
	
	
	//kullanýcýdan dogum yilini aldik
	printf("lutfen dogum yilinizi giriniz \n");
	scanf("%d",&dogumYili);
	
	
	//yas'ý hesapladýk
	 yas=yil-dogumYili;
	
	
	//yas'ý yazdýr
	printf("kullanicinin yasi =%d",yas);
}
//denendi ve compile edildi
//dogum tarihi verilen kiþinin yaþýný bulan algoritma ve programi
//sayfa 1
//kod calýsýyor
