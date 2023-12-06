#include <stdio.h>
#include <math.h>
int main(void) {
	int i, a[10],n;
	float e,l,k,kucuk=0.0,buyuk=0.0;
	printf("Lutfen en buyuk ussu giriniz");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
    	printf("Lutfen ussu %d olan degiskenin katsayisini giriniz",i);
    	scanf("%d",&a[i]);
	}
	printf("Kac noktasindaki turev");
	scanf("%f",&k);
	l=k+0.0001;
	for(i=0;i<=n;i++){
    	kucuk+=pow(k,i)*a[i];
    	buyuk+=pow(l,i)*a[i];
	}
	e=(kucuk-buyuk)/(k-l);
	printf("%f",e);
	return 0;
}
