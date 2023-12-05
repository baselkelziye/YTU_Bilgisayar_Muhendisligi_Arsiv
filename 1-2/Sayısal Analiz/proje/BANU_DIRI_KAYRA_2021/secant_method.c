#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void) {
	int i, a[10],n,j;
	double e,l,k,s=0.0,y=0.0,g,t;
	printf("Lutfen en buyuk ussu giriniz");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
	
    	printf("Lutfen ussu %d olan degiskenin katsayisini giriniz",i);
    	scanf("%d",&a[i]);
	}
	printf("Lutfen kucuk x degerini giriniz giriniz");
	scanf("%lf",&k);
	l=k+0.5;
	printf("lutfen epsilone degerini giriniz");
	scanf("%lf",&e);
	i=0;
	s=1;
	y=3;
	while((k-l)>e || (l-k)>e){	
		y=0;
		s=0;
			for(j=0;j<=n;j++){
    	y+=pow(k,j)*a[j];
    }
    		for(j=0;j<=n;j++){
    	s+=pow(l,j)*a[j];
    }
    t=s-y;
    	if(t==0){
    		t+=0.001;
		}
		g=k-(l-k)*y/(t);
    	l=k;
    	k=g;
    	i++;
    	printf("%d. adim %f\n",i,g);
}
	printf("Yaklasik deger %f",k);
	return 0;
}
