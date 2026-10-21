
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main(){
	
	
	int secim,u,count,i,j,r,c2,n,k,fak,f,iterasyon,flag,y;
	float a1,b1,c,x0,x1,h,turev,epsilon,alan=0,xn,xT,katsayilar[20],hata,birim[20][20],a,b,matris[20][20],s,x[20],determinant,t,ax[20],ay[20],l,fark[20][20],carpim,w,ent[20],x4,sonuc[20];
	float toplam1=0,toplam2=0,toplam3=0,toplam=0,toplam4=0,tmp;

	
	printf("***BISECTION YONTEMI***\n");
	
	printf("alt ve ust sinir degerlerini girin: \n");
	scanf("%f %f",&a1,&b1);
	printf("hata payini girin: ");
	scanf("%f",&epsilon);
	
	printf("gireceginiz fonksiyondaki en yuksek us degerini girin:\n ");
	scanf("%d",&u);
	for(i=u;i>=0;i--){
		printf("x uzeri %d degerine sahip elemanin katsayi degerini girin: \n", i);
		
		scanf("%f",&katsayilar[i]);
		toplam1=toplam1+pow(a1,i)*katsayilar[i];
		toplam2=toplam2+pow(b1,i)*katsayilar[i];
	}
	
	if(toplam1*toplam2<0){
		int count=1;
		
	
		printf("bu aralikta en az bir tane kok vardir.\n");
		hata=fabs((b1-a1)/pow(2,count));
		while(hata>epsilon){
		toplam1=0;
		toplam2=0;
		toplam3=0;	
		c=(a1+b1)/2;
		for(i=u;i>=0;i--){
		toplam1=toplam1+pow(a1,i)*katsayilar[i];
		toplam2=toplam2+pow(b1,i)*katsayilar[i];
		toplam3=toplam3+pow(c,i)*katsayilar[i];
		
	}
		hata=fabs((b1-a1)/pow(2,count));
		
		
		printf("\n %d. iterasyon : a1=%f 	 b1=%f 	  hata=%f  kok=%f	\n",count,a1,b1,hata,c);
		if(toplam1*toplam3<0){
			b1=c;
		}
		else if(toplam2*toplam3<0){
			a1=c;
		}
		
		count++;
		
		}
		
		printf("   yaklasik kok degeri = %f \n\n",c);
	}
	
	else{
		
		printf("bu aralikta kok yoktur");
	}
	
	return 0;
		
	}
