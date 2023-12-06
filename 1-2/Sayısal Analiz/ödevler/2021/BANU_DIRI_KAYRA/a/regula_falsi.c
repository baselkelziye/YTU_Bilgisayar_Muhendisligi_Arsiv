#include <stdio.h>
#include <math.h>
int main(void) {
		int i,n,a[20],p=1;
	double g,k,e,m=0.0,l=0.0,u,j=0.0; 
		printf("Lutfen en buyuk ussu giriniz");
	scanf("%d",&n);
	if(n<1){
		printf("Bu bir fonksiyon degildir");
	}
	else{
	for(i=0;i<=n;i++){
	
    	printf("Lutfen ussu %d olan degiskenin katsayisini giriniz",i);
    	scanf("%d",&a[i]);
	}
	printf("Lutfen ilk degeri giriniz");
	scanf("%lf",&k);
	printf("Lutfen son degeri giriniz");
	scanf("%lf",&u);
	printf("lutfen epsilone degerini giriniz");
	scanf("%lf",&e);
	for(i=0;i<=n;i++){
    	m+=pow(k,i)*a[i];
    }
    for(i=0;i<=n;i++){
    	l+=pow(u,i)*a[i];
    }
    if(l==0 && m==0){
    	
    	printf("sonuc = %lf ve %lf",u,k);
	}
	else{
    if(m*l<=0){
    g=(u*m-l*k)/(m-l);
    while((k-u)/pow(2,p)>e || (u-k)/pow(2,p)>e){
    	for(i=0;i<=n;i++){
    	j+=pow(g,i)*a[i];
    }
    	if(j*l<0){
    		m=j;
    		k=g;
		}
		else{
			l=j;
    		u=g;
		}
	g=(u*m-l*k)/(m-l);	
	p++;
	j=0;
	printf("%d. tekrarda kok = %f\n",p,g);
    }
    printf("yaklsakik deger = %lf",g);
	
}
else{
	printf("bu aralikta kok yoktur");
}
}}
return 0;
}
