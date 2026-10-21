#include <stdio.h>
#include <math.h>

double trapez(double [], int, double, double);

double trapez(double a[], int n, double x1, double x0){//a katsayýlar n max üst
	int i;
	double sumx1=0,sumx0=0,res;
	for(i=n;i>=0;i--){
		sumx1 += a[i]*pow(x1,i);
		sumx0 += a[i]*pow(x0,i);
	}res = (x1-x0)*(sumx1+sumx0)/2;
	return res;
}

int main(){
	int i,power;
	double katsayi[20],alt,ust,art,ara,x,sum=0;
	printf(" Trapez Metodu\n\n");
	printf("\tP(x) polinomunda X'in en buyuk kuvveti = ");
	scanf("%d",&power);
	for(i=power;i>=0;i--){
		printf("\n\t\tX^%d'in katsayisi = ",i);
		scanf("%lf",&katsayi[i]);
	}	
	printf("\n Integralin alt limiti = ");scanf("%lf",&alt);
	printf("\n Integralin ust limiti = ");scanf("%lf",&ust);
	printf("\n Aralik sayisi = ");scanf("%lf",&ara);
	if(ara>0.0){
		art = (ust-alt)/ara;x=alt;		
		for(i=0;i<ara;i++){
			sum += trapez(katsayi,power,x+art,x);x += art;			
		}printf("\n\n\tPolinomun %.0lf aralik sayisina gore alani = %lf",ara,sum);
	}else{
		printf("Hatali aralik sayisi girdiniz!");		
	}
	
}
