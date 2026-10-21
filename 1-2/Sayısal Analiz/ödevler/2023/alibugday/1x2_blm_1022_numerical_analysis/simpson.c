#include<stdio.h>
#include<math.h>

float fonk(float x);

int main(){
	float h,N,ust,alt;
	float toplam0=0,toplam1=0,toplam,yukseklik,yukseklik1;
	
	
	
	
	printf("ilk nokta giriniz : ");
	scanf("%f",&alt);
	printf("üst nokta giriniz : ");
	scanf("%f",&ust);
	printf("aralýk sayýsý n giriniz : ");
	scanf("%f",&N);
	
	 
	h=(ust-alt)/N;
	
	
	
	yukseklik=fonk(alt+0*h);
	yukseklik1=fonk(alt+N*h);
	
	int i;
	
	for(i=1; i<N; i++){
	
		if(i%2 == 1)
			toplam1 = toplam1 + fonk(alt+i*h);
		else
			toplam0 = toplam0 + fonk(alt+i*h);
	}
	printf("toplam1 : %.4f\n",toplam1);
	printf("toplam0 : %.4f\n",toplam0);
	printf("yukseklik : %.4f\n",yukseklik);
	printf("toplam0 : %.4f\n",yukseklik1);
	toplam =(h/3)*(yukseklik + yukseklik1 + 2*toplam0 + 4*toplam1);
	
	printf("cevap : %.4f",toplam);
	
	
	return 1;
	
	
	
}

//integral alýnmamýþ hali
float fonk(float x){
	return x*x*x;
	
}
