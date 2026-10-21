

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//faktoriyel hesaplama fonksiyonu: 
	
int faktoriyel(int f){
	int i,fak=1;
	if(f==0){
		return 1;
	}else if(f==1){
		return 1;
	}else {
		for(i=1;i<=f;i++){
			fak=fak*i;
		}
		return fak;
	}
}	
	
	
int main(){
	
	
	int secim,u,count,i,j,r,c2,n,k,fak,f,iterasyon,flag,y;
	float a1,b1,c,x0,x1,h,turev,epsilon,alan=0,xn,xT,katsayilar[20],hata,birim[20][20],a,b,matris[20][20],s,x[20],determinant,t,ax[20],ay[20],l,fark[20][20],carpim,w,ent[20],x4,sonuc[20];
	float toplam1=0,toplam2=0,toplam3=0,toplam=0,toplam4=0,tmp;



		printf("***GREGORY NEWTON ENTERPOLASYONU***\n");
		
		printf("n degerini girin: \n");
		scanf("%d",&n);
		
		printf(" Degerleri (x,y) biciminde giriniz:\n");
   for (i=0;i<n;i++){
      scanf("%f %f",&ax[i],&ay[i]);
   }
   printf("y degerini bulmak istediginiz x degerini girin: \n");
   scanf("%f",&x4);
   h=ax[1]-ax[0];
		
	
	int count1=0;
	for(i=0;i<n-1;i++){
		fark[count1][i]=ay[i+1]-ay[i];
		
	}
	count1=count1+1;
	for(j=n;j>0;j--){
		for(i=0;i<j-2;i++){
			fark[count1][i]=fark[count1-1][i+1]-fark[count1-1][i];
		}
		count1++;
	}
	
		
	w=(x4-ax[0])/h;
	for(i=0;i<n;i++){
		c=0;
		carpim=1.0;
		while(c<=i){
			carpim=carpim*(w-c);
			c++;
		}	
		ent[i]=((carpim*fark[i][0])/faktoriyel(i+1));	
	}
	for(i=0;i<n;i++){
		toplam=toplam+ent[i];	
	}
		toplam=toplam+ay[0];

   printf("x %f iken karsilik gelen f(x) degeri = %f",x4,toplam);
	return 0;
	
	}
