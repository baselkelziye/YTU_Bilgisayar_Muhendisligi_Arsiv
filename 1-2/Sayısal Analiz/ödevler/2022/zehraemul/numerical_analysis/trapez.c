#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	
	
	int secim,u,count,i,j,r,c2,n,k,fak,f,iterasyon,flag,y;
	float a1,b1,c,x0,x1,h,turev,epsilon,alan=0,xn,xT,katsayilar[20],hata,birim[20][20],a,b,matris[20][20],s,x[20],determinant,t,ax[20],ay[20],l,fark[20][20],carpim,w,ent[20],x4,sonuc[20];
	float toplam1=0,toplam2=0,toplam3=0,toplam=0,toplam4=0,tmp;


		printf("***TRAPEZ YONTEMI***\n");
		printf("Integralin alt limitini girin: \n");
		scanf("%f",&x0);
		printf("Integralin ust limitini girin:  \n");
		scanf("%f",&xn);
		printf("Alani bolmek istediginiz yamuk sayisini girin: \n");
		scanf("%d",&n);
		
		h=fabs((xn-x0))/n;
		
		printf("gireceginiz fonksiyondaki en yuksek us degerini girin:\n ");
		scanf("%d",&u);	
			for(i=u;i>=0;i--){
		printf("x uzeri %d degerine sahip elemanin katsayi degerini girin: \n", i);
		scanf("%f",&katsayilar[i]);
		toplam1=toplam1+pow(x0,i)*katsayilar[i];//f(xo)
		toplam2=toplam2+pow(xn,i)*katsayilar[i];//f(xn)
		
	}
		
		
		for(k=1;k<=(n-1);k++){
			
			xT=x0+h*k;
			for(i=u;i>=0;i--){
	
		toplam3=toplam3+pow(xT,i)*katsayilar[i];//f(xT)	
	}	
			
		}
		
		alan=fabs(h*((toplam1+toplam2)/2.0+toplam3));
		
		printf("Integral (Alan) degerinin yaklasik sonucu : %f\n",alan);	
		return 0;
	}
