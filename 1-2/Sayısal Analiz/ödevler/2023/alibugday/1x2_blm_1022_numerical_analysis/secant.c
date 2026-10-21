#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fonk(a,b,c,d,x);

int main() {
	int a,b,c,d;
	float x0, x1, x2, f0, f1, f2, epsilon;
	
	printf("a*x*x*x+b*x*x+c*x+d fonksiyon degerlerini gir\n");
	
	printf("a:");
	scanf("%d",&a);
	
	printf("b:");
	scanf("%d",&b);
	
	printf("c:");
	scanf("%d",&c);
	
	printf("d:");
	scanf("%d",&d);
	
	printf("X0:");
	scanf("%f",&x0);
	
	printf("X1:");
	scanf("%f",&x1);
	
	printf("epsilon:");
	scanf("%f",&epsilon);
	
	do{
		f0 = fonk(a,b,c,d,x0);
		f1 = fonk(a,b,c,d,x1);
		
		if ((f1>0 || f0>0) && (f1<0 || f0<0)){
			printf("hatali deger girdiniz\n");
			exit(0);
		}
		
		x2 = x1 - (x1 - x0) * f1/(f1-f0);
		f2 = fonk(a,b,c,d,x2);	
		
		x0 = x1;
	    f0 = f1;
	  	x1 = x2;
	  	f1 = f2;
	  	
	  	printf("sonuc:%f",x2);
	  	
	}while(fabs(f2)>epsilon);
	
	printf("sonuc:%f",x2);
	return 0;
}


int fonk(a,b,c,d,x){
	return a*x*x*x+b*x*x+c*x+d;
}
