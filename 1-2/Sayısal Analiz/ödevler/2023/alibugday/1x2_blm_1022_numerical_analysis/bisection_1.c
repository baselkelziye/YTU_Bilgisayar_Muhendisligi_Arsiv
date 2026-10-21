#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double Fonk(double x, int a, int b, int c, int d);

int main() {
	double ilk,son,ortax0,ortax1,epsilon,fark;
	int a,b,c,d;
	printf("a*x^3+b*x^2+c*x+d fonksiyon degerlerini giriniz:\n");
	
	printf("X kup katsayisi a giriniz:");
    scanf("%d",&a);
    printf("X kare katsayisi b giriniz:");
    scanf("%d",&b);
    printf("X katsayisi c giriniz:");
    scanf("%d",&c);
    printf("d sayisini giriniz:");
    scanf("%d",&d);
	
	printf("baslangic degeri:");
	scanf("%lf",&ilk);
	
	printf("son deger:");
	scanf("%lf",&son);
	
	printf("epsilon degeri:");
	scanf("%lf",&epsilon);
	
	do{
		ortax0=(ilk+son)/2;
		if(Fonk(ortax0,a,b,c,d)==0){
			break;
		}else if((Fonk(ortax0,a,b,c,d)*Fonk(ilk,a,b,c,d))<0){
			son=ortax0;
		}else{
			ilk=ortax0;
		}
		ortax1=(ilk+son)/2;
		printf("adim:%lf\n",ortax1);
	}while(fabs(Fonk(ortax1,a,b,c,d))>epsilon);
	
	printf("=========\nsonuc:%lf",ortax1);
	return 0;
}

double Fonk(double x, int a, int b, int c, int d){
	return a*x*x*x+b*x*x+c*x+d;
}
