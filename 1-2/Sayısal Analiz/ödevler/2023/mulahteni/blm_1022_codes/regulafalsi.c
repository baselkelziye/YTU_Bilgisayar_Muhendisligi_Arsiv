#include <stdio.h>
#include <math.h>

int main(){
	int i,j,power,count=1;
	float x,x0,x1,hata,mis,sum1=0,sum2=0,sum3=0,katsayi[20];
	printf(" Regula Falsi Metodu\n\n");
	printf("\tF(x) fonksiyonunda X'in en buyuk kuvveti = ");
	scanf("%d",&power);
	for(i=power;i>=0;i--){
		printf("\n\t\tX^%d'in katsayisi = ",i);
		scanf("%f",&katsayi[i]);
	}
	printf("\n\tFonksiyonun kok araligi [x0, x1]\n");
	printf("\n\t\t\tx0 = ");scanf("%f",&x0);
	printf("\n\t\t\tx1 = ");scanf("%f",&x1);
	printf("\n\tHata payi = ");scanf("%f",&mis);
	for(i=power;i>=0;i--){		
		sum1=sum1+pow(x0,i)*katsayi[i];
		sum2=sum2+pow(x1,i)*katsayi[i];		
	}
	if(sum1*sum2<0){
		hata = fabs((x1-x0)/pow(2,count));
		while(hata>mis){
			printf("\n\t%d. Iterasyon\n\t\tx0 = %f\tx1 = %f\t",count,x0,x1);
			x = (x0*sum2-x1*sum1)/(sum2-sum1);
			printf("yeni kok = %f",x);
			sum1=0;
			sum2=0;
			sum3=0;
			for(i=power;i>=0;i--){
				sum3=sum3+pow(x,i)*katsayi[i];
				sum1=sum1+pow(x0,i)*katsayi[i];
				sum2=sum2+pow(x1,i)*katsayi[i];				
			}
			if(sum3*sum1<0){
				x1=x;
			}else if(sum3*sum2<0){
				x0=x;
			}
			count++;
			hata = fabs((x1-x0)/pow(2,count));
			printf("\thata = %f\n",hata);			
		}
		printf("\n\tSon kok = %f",x);
	}else if(sum1==0){
		printf("\n Verilen aralik koktur = %f",x0);
	}else if(sum2==0){
		printf("\n Verilen aralik koktur = %f",x1);
	}else{
		printf("\n Aralikta kok yok");
	}
	return 0;
}

