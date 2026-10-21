#include <stdio.h>
#include <math.h>

float simpone(float [10], int, float, float);
float simptwo(float [10], int, float, float);
float caller(float [10], int, float, float, int, float);

float simpone(float a[10], int n, float x1, float x2){
	int i;
	float sum1=0,sum2=0,sum3=0,res;
	for(i=n;i>=0;i--){
		sum1 += a[i]*pow(x1,i);
		sum2 += a[i]*pow(x2,i);
		sum3 += a[i]*pow((x1+x2)/2,i);	
	}
	res = (x2-x1)*((sum1+4*sum3+sum2)/6);
	return res;
}

float simptwo(float a[10], int n, float x1, float x2){
	int i;
	float sum1=0,sum2=0,sum3=0,sum4=0,res;
	for(i=n;i>=0;i--){
		sum1 += a[i]*pow(x1,i);
		sum2 += a[i]*pow(x2,i);
		sum3 += a[i]*pow(x1+(x2-x1)/3,i);
		sum4 += a[i]*pow(x1+2*(x2-x1)/3,i);	
	}
	res = (x2-x1)*((sum1+3*sum3+3*sum4+sum2)/8);
	return res;
}

float caller(float a[10], int n, float x1, float x2, int c, float ara){
	float x0,sum=0,art;
	int araci=0;
	art = fabs((x2-x1)/ara);
	x0=x1;
	if(c==2){//simptwo
		while(araci<ara){
			sum += simptwo(a,n,x0,x0+art);
			x0 += art;
			araci++;
		}
		return sum;
	}else{//simpone
		while(araci<ara){
			sum += simpone(a,n,x0,x0+art);
			x0 += art;
			araci++;
		}
		return sum;
	}
}

int main(){
	int i,power;
	float katsayi[10],alt,ust,ara,x,sum=0,res=0,res1=0,choice;
	printf(" Simpson Metodu\n\n");
	printf("\tP(x) polinomunda X'in en buyuk kuvveti = ");
	scanf("%d",&power);
	for(i=power;i>=0;i--){
		printf("\n\t\tX^%d'in katsayisi = ",i);
		scanf("%f",&katsayi[i]);
	}	
	printf("\n Integralin alt limiti = ");scanf("%f",&alt);
	printf("\n Integralin ust limiti = ");scanf("%f",&ust);
	printf("\n Aralik sayisi = ");scanf("%f",&ara);choice=1;
	res = fabs(caller(katsayi,power,alt,ust,choice,ara));choice=2;
	res1 = fabs(caller(katsayi,power,alt,ust,choice,ara));
	printf("\n Simpson 1/3 metoduyla bulunan alan = %f",res);
	printf("\n Simpson 3/8 metoduyla bulunan alan = %f",res1);
	return 1;
}
