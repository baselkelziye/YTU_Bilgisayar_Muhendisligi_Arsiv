#include <stdio.h>
#include <math.h>

int main(){	
	int i,secim,power;
	float katsayi[20],h,x0,sum1=0,sum2=0,turev;
	printf(" Sayisal Turev\n");	
	printf("\n\tF(x) fonksiyonunda X'in en buyuk kuvveti = ");scanf("%d",&power);
	for(i=power;i>=0;i--){
		printf("\n\t\tX^%d'in katsayisi = ",i);
		scanf("%f",&katsayi[i]);
	}
	//printf("\n\n Geri farkli turev icin 1, Merkezi farkli turev icin 2, Ileri farkli turev icin 3 giriniz = ");scanf("%d",&secim);
	printf("\n Turev hesabinde kullanilacak X0 noktasi = ");scanf("%f",&x0);	
	printf("\n Turev alirken kullanilacak iki deger arasi fark degerini giriniz = ");scanf("%f",&h);
	//if(secim==1){
		for(i=power;i>=0;i--){
			sum1=sum1+pow(x0+h,i)*katsayi[i];
			sum2=sum2+pow(x0,i)*katsayi[i];
		}
		turev = (sum1-sum2)/h;
		printf("\n Ileri farkli turevin sonucu = %f",turev);sum1=0;sum2=0;
	//}else if(secim==2){
		for(i=power;i>=0;i--){
			sum1=sum1+pow(x0+h,i)*katsayi[i];
			sum2=sum2+pow(x0-h,i)*katsayi[i];
		}
		turev = (sum1-sum2)/(2*h);
		printf("\n Merkezi farkli turevin sonucu = %f",turev);sum1=0;sum2=0;
	//}else{
		for(i=power;i>=0;i--){
			sum1=sum1+pow(x0,i)*katsayi[i];
			sum2=sum2+pow(x0-h,i)*katsayi[i];
		}
		turev = (sum1-sum2)/h;
		printf("\n Geri farkli turevin sonucu = %f",turev);sum1=0;sum2=0;
	//}
	
	return 0;
}
	
