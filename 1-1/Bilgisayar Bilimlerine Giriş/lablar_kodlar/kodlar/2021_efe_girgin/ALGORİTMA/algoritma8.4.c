#include <stdio.h>
int main(){
	int a,b,k,t;
	t=0;
	printf("bir sayi giriniz\n");
	scanf("%d",&a);
	
	printf("bir sayi daha giriniz\n");
	scanf("%d",&b);
	while(b>=1){
		k=b %2;
		t=t+(a*k);
		a=a*2;
		b=b/2;
	}
	printf("%d",t);
	return 0;
	
	
}
//iki sayi giriliyor.1.sayi 2 ile carpilirken 2.sayi ikiye bolunuyor.bu islem 2.sayinin bir olmasina kadar devam ediyor.2.sayi tek ise ondaki 1.sayinin degerleri toplaniyor.
//toplamin sonucu bize carpmayi verir.bu islemin algoritma ve programi(2sayi arasinda dogrudan carpma islemi yapmadan carpmanin yolu)
//sayfa 7
//kod calýsýyor
