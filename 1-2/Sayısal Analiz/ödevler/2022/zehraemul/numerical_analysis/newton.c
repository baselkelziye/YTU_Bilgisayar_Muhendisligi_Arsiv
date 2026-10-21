
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
	
	
int main(){
	
	
	int secim,u,count,i,j,r,c2,n,k,fak,f,iterasyon,flag,y;
	float a1,b1,c,x0,x1,h,turev,epsilon,alan=0,xn,xT,katsayilar[20],hata,birim[20][20],a,b,matris[20][20],s,x[20],determinant,t,ax[20],ay[20],l,fark[20][20],carpim,w,ent[20],x4,sonuc[20];
	float toplam1=0,toplam2=0,toplam3=0,toplam=0,toplam4=0,tmp;

	
	
		
	printf("***NEWTON-RAPHSON YONTEMI***\n");
		
	printf("hata payini girin: ");
	scanf("%f",&epsilon);
	printf("alt ve ust sinir degerlerini girin: \n");
	scanf("%f %f",&a1,&b1);
	printf("Baslangic degeri aralik icinde olan x0'i girin: \n");
	scanf("%f",&x0);
	printf("gireceginiz fonksiyondaki en yuksek us degerini girin:\n ");
	scanf("%d",&u);	
	for(i=u;i>=0;i--){
		printf("x uzeri %d degerine sahip elemanin katsayi degerini girin: \n", i);
		scanf("%f",&katsayilar[i]);
		//turevsiz hali:
		toplam1=toplam1+pow(x0,i)*katsayilar[i];
		//turevli hali:
	}
			for(i=u;i>0;i--){
			
				toplam2=toplam2+(pow(x0,(i-1))*katsayilar[i]*(i));
				
		}
	
	x1=x0-(toplam1/toplam2);
	
	hata=fabs(x1-x0);
	count=1;
	while(hata>epsilon){
		
		toplam1=0;
		toplam2=0;
		for(i=u;i>=0;i--){
		toplam1=toplam1+pow(x0,i)*katsayilar[i];
	}
	
			for(i=u;i>0;i--){
				toplam2=toplam2+(pow(x0,(i-1))*katsayilar[i]*(i));
				
		}
	
	
	x1=x0-(toplam1/toplam2);
	hata=fabs(x1-x0);
	
	printf("\n  %d. iterasyon : x%d=%f    x%d=%f    hata=%f   kok degeri= %f \n  ",count,count-1,x0,count,x1,hata,x1);
	count++;
	x0=x1;
		
	
}

	printf("Yaklasik kok degeri=%f",x1);

return 0;
	}
	
