#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float fonk(int a, int b,int c,int d,float x){
	return a*x*x*x+b*x*x+c*x+d;
}


int main() {
	int a,b,c,d,i=0;
	float x,epsilon,ilk,son,yaklasim0,yaklasim1;
	
	printf("a*x^3+b*x^2+c*x+d fonksiyon degerlerini giriniz:\n");
	
    printf("X kup katsayisi a giriniz:");
    scanf("%d",&a);
    printf("X kare katsayisi b giriniz:");
    scanf("%d",&b);
    printf("X katsayisi c giriniz:");
    scanf("%d",&c);
    printf("d sayisini giriniz:");
    scanf("%d",&d);
	
	printf("ilk:");
	scanf("%f",&ilk);
	
	printf("son:");
	scanf("%f",&son);
	
	printf("epsilon:");
	scanf("%f",&epsilon);
	
	do{
		yaklasim0=(ilk*fonk(a,b,c,d,son) - son*fonk(a,b,c,d,ilk))/ (fonk(a,b,c,d,son) - fonk(a,b,c,d,ilk));
		if(fonk(a,b,c,d,yaklasim0)==0){
			break;
		}else if(fonk(a,b,c,d,yaklasim0)*fonk(a,b,c,d,ilk)<0){
			son=yaklasim0;
		}else{
			ilk=yaklasim0;
		}
		yaklasim1=(ilk*fonk(a,b,c,d,son) - son*fonk(a,b,c,d,ilk))/ (fonk(a,b,c,d,son) - fonk(a,b,c,d,ilk));
		printf("%d inci iteration:%f\n",i++,yaklasim0);
	}while(fabs(yaklasim1-yaklasim0)>epsilon);
	printf("sonuc:%f",yaklasim1);
	
	return 0;
}
