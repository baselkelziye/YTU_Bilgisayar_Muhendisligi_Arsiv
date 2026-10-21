#include <stdio.h>
#include <math.h>

int main(){
	int i,power,count=1;
	float x0,x1,x2,hata,mis,sum1=0,sum2=0,katsayi[20];
	printf(" Newton Raphson Metodu\n\n");
	printf("\tF(x) fonksiyonunda X'in en buyuk kuvveti = ");
	scanf("%d",&power);
	for(i=power;i>=0;i--){
		printf("\n\t\tX^%d'in katsayisi = ",i);
		scanf("%f",&katsayi[i]);
	}
	printf("\n\tFonksiyonun kok araligi [x0, x1]\n");
	printf("\n\t\t\tx0 = ");scanf("%f",&x0);
	printf("\n\t\t\tx1 = ");scanf("%f",&x1);
	printf("\n\tAnaliz yapilirken kullanilacak [%f, %f] araliginda kullanilacak ilk deger = ",x0,x1);scanf("%f",&x2);
	printf("\n\tHata payi = ");scanf("%f",&mis);
	for(i=power;i>=0;i--){
		sum1=sum1+pow(x0,i)*katsayi[i];			
		sum2=sum2+pow(x1,i)*katsayi[i];		
	}
	if(sum1*sum2<0){
		sum1=0;sum2=0;
		hata = fabs(x1-x0);
		x0=x2;
		while(hata>mis){
			for(i=power;i>=0;i--){
				sum1=sum1+pow(x0,i)*katsayi[i];				
			}
			for(i=power;i>0;i--){
				sum2=sum2+pow(x0,i-1)*katsayi[i]*i;				
			}
			x1 = x0 - sum1/sum2;
			printf("\n\t\t\t\t%d. Iterasyon \n\n\tKullanilan kok = %f\t Bulunan  kok = %f\n\n",count,x0,x1);
			sum1=0;sum2=0;
			hata = fabs((x1-x0)/pow(2,count));
			count++;
			x0 = x1;
		}
		printf("\n\t\t\t     Son kok = %f",x1);
	}else if(sum1==0){
		printf("\n Verilen aralik koktur = %f",x0);
	}else if(sum2==0){
		printf("\n Verilen aralik koktur = %f",x1);
	}else{
		printf("\n Aralikta kok yok");
	}
	return 0;
}

