#include <stdio.h>
// polinom = a1*x^(n) + a2*x^(n-1) ....+ an*x^0
typedef struct polinom{
	double katsayi;
	int derece;
}POLINOM;

int main(){
	POLINOM p1;
	POLINOM *p2;
	POLINOM **p3;
	
	POLINOM p4[10];
	POLINOM *p5[10];
	
	POLINOM p6[4][8];
	
	p1.derece = 4;
	p1.katsayi= 6;
	printf("Derece= %d , Katsayi = %d\n",p1.derece,p1.katsayi);
	printf("Struct Adress =%p, Derece= %p , Katsayi = %p\n",&p1,&p1.derece,&p1.katsayi);
	
	printf("Derece giriniz"); scanf("%d",&p1.derece);
	printf("Katsayi giriniz"); scanf("%lf",&p1.katsayi);
	printf("Derece= %d , Katsayi = %2.2lf\n",p1.derece,p1.katsayi);
	
	int a=5;
	int *pA=&a;
	
	
	//scanf("%d",a);
	
	p2=&p1;
	p3=&p2;
	(*p2).derece=66;
	p2->katsayi=100;
	printf("Struct Adress =%p, Derece= %p , Katsayi = %p\n",p2,&p2->derece,&p2->katsayi);
	printf("Struct Adress =%p, Derece= %p , Katsayi = %p\n",p2,&(*p2).derece,&(*p2).katsayi);
	
	printf("Derece= %d , Katsayi = %2.2lf\n",p2->derece,(*p2).katsayi);
	
	printf("Derece giriniz"); scanf("%d",&p2->derece);
	printf("Katsayi giriniz"); scanf("%lf",&p2->katsayi);
	printf("Derece= %d , Katsayi = %2.2lf\n",p2->derece,(*p2).katsayi);
	

	
	return 0;

	 
}

