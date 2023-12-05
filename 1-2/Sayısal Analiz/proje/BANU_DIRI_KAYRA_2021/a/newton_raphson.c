#include <stdio.h>
#include <math.h>
int main(void) {
	int i,j=812832,n,a[20],p=1;
	double g,k,e,m=0.0,l=0.0; 
		printf("Lutfen en buyuk ussu giriniz");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
	
    	printf("Lutfen ussu %d olan degiskenin katsayisini giriniz",i);
    	scanf("%d",&a[i]);
	}
	printf("Lutfen baslangic degerini giriniz");
	scanf("%lf",&k);
	printf("lutfen epsilone degerini giriniz");
	scanf("%lf",&e);
	i=0;
	m+=pow(k,i)*a[i];
    for(i=1;i<=n;i++){
    	m+=pow(k,i)*a[i];
    	l+=pow(k,i-1)*a[i]*i;
	}
	if(l==0)
	l++;
	g=k-m/l;
	while((k-g)>e || g-k>e){	
	printf("%d. tekrar degeri %f\n",p,g);
	k=g;
	m=0;
	l=0;
	m+=pow(k,0)*a[0];
	 for(i=1;i<=n;i++){
    	m+=pow(k,i)*a[i];
    	l+=pow(k,i-1)*a[i]*i;
    }
    if(l==0)
	l++;
    g=k-m/l;
    p++;
	}
	printf("%d. tekrarda sonuc = %lf",p,g);
	return 0;
}
