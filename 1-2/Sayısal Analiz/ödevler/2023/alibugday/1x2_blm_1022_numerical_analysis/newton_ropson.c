#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


float fonk(int a, int b,int c,int d,float x){
	return a*x*x*x+b*x*x+c*x+d;
}

float turev(int a, int b,int c,int d,float x){
	float x1=x+0.001;
	return (((a*x1*x1*x1+b*x1*x1+c*x1+d)-(a*x*x*x+b*x*x+c*x+d))/(x1-x));
}


int main() {
	int a,b,c,d,i=1;
	float x0,x1,epsilon;
	
	printf("a*x^3+b*x^2+c*x+d fonksiyon degerlerini giriniz:\n");
	
    printf("X kup katsayisi a giriniz:");
    scanf("%d",&a);
    printf("X kare katsayisi b giriniz:");
    scanf("%d",&b);
    printf("X katsayisi c giriniz:");
    scanf("%d",&c);
    printf("d sayisini giriniz:");
    scanf("%d",&d);
	
	printf("x1:");
	scanf("%f",&x1);
	
	printf("epsilon:");
	scanf("%f",&epsilon);
	
	do{
		x0=x1;
		x1=x0-(fonk(a,b,c,d,x0)/turev(a,b,c,d,x0));
		printf("%dinci iterasyon:%f\n",i++,x1);
		
	}while((x1-x0)>epsilon);
	printf("sonuc:%f",x1);
	return 0;
}
