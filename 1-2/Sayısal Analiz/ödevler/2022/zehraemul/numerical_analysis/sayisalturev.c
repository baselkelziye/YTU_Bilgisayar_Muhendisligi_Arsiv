#include<stdio.h>
#include<math.h>
#include<stdlib.h>



	
	
int main(){
	
	
	int secim,u,count,i,j,r,c2,n,k,fak,f,iterasyon,flag,y;
	float a1,b1,c,x0,x1,h,turev,epsilon,alan=0,xn,xT,katsayilar[20],hata,birim[20][20],a,b,matris[20][20],s,x[20],determinant,t,ax[20],ay[20],l,fark[20][20],carpim,w,ent[20],x4,sonuc[20];
	float toplam1=0,toplam2=0,toplam3=0,toplam=0,toplam4=0,tmp;

	
		printf("***SAYISAL TUREV***\n");
		
		printf("1-->Ileri farklar ile sayisal turev\n2-->Geri farklar ile sayisal turev\n3-->Merkezi farklar ile sayisal turev\n");
		printf("Uygulamak istediginiz yontemi girin:\n");
		scanf("%d",&secim);
		if(secim==1){
		printf("***ILERI FARKLAR ILE SAYISAL TUREV***\n");
		printf("Turevini hesaplamak istediginiz x noktasini girin: \n");
		scanf("%f",&x0);
		printf("h degerini girin(iki nokta arasi fark degeri): \n");
		scanf("%f",&h);
		printf("gireceginiz fonksiyondaki en yuksek us degerini girin:\n ");
		scanf("%d",&u);	
		x1=x0+h;
			for(i=u;i>=0;i--){
		printf("x uzeri %d degerine sahip elemanin katsayi degerini girin: \n", i);
		scanf("%f",&katsayilar[i]);
		toplam1=toplam1+pow(x0,i)*katsayilar[i];
		toplam2=toplam2+pow(x1,i)*katsayilar[i];
		
	}
	turev=(toplam2-toplam1)/h;
	printf("%f. noktasindaki turev degeri: %f",x0,turev);
	
}
		else if(secim==2){
		printf("***GERI FARKLAR ILE SAYISAL TUREV***\n");
			
		printf("Turevini hesaplamak istediginiz x noktasini girin: \n");
		scanf("%f",&x0);
		printf("h degerini girin(iki nokta arasi fark degeri): \n");
		scanf("%f",&h);
		printf("gireceginiz fonksiyondaki en yuksek us degerini girin:\n ");
		scanf("%d",&u);	
		x1=x0-h;
			for(i=u;i>=0;i--){
		printf("x uzeri %d degerine sahip elemanin katsayi degerini girin: \n", i);
		scanf("%f",&katsayilar[i]);
		toplam1=toplam1+pow(x0,i)*katsayilar[i];
		toplam2=toplam2+pow(x1,i)*katsayilar[i];
		
	}
	turev=(toplam1-toplam2)/h;
	printf("%f. noktasindaki turev degeri: %f",x0,turev);
			
		}
		else if(secim==3){
		printf("***MERKEZI FARKLAR ILE SAYISAL TUREV***\n");
		
		printf("Turevini hesaplamak istediginiz x noktasini girin: \n");
		scanf("%f",&x0);
		printf("h degerini girin(iki nokta arasi fark degeri): \n");
		scanf("%f",&h);
		printf("gireceginiz fonksiyondaki en yuksek us degerini girin:\n ");
		scanf("%d",&u);
		x0=x0+h;	
		x1=x0-(2.0*h);
			for(i=u;i>=0;i--){
		printf("x uzeri %d degerine sahip elemanin katsayi degerini girin: \n", i);
		scanf("%f",&katsayilar[i]);
		toplam1=toplam1+pow(x0,i)*katsayilar[i];
		toplam2=toplam2+pow(x1,i)*katsayilar[i];
		
	}
	turev=((toplam1-toplam2)/(2.0*h));
	x0=x0-h;
	printf("%f. noktasindaki turev degeri: %f",x0,turev);
		}
		return 0;
	}
