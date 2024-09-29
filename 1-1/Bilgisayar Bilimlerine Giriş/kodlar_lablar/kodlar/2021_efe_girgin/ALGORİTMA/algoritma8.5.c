#include <stdio.h>
int main(){
	int sayi,kuvvet,deger,i;
	
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&sayi);
	
	printf("lutfen sayinin kuvvetini giriniz\n");
	scanf("%d",&kuvvet);
	
	deger=1;
	for(i=1;i<=kuvvet;i++){
		deger=deger*sayi;
	}
	printf("%d",deger);
	return 0;
	
	
}
//deneme ve compile yapildi
//herhangi bir sayinin herhangi bir dereceden kuvvetini bulan program ve algoritma
//sayfa 7
//kod calýsýyor
