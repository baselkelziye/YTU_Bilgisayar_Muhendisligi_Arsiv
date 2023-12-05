#include <stdio.h>
#include <math.h>
int main(void) {
	int i, a[10],n,j;
	double e,l,k,s=0.0,y=0.0,kucuk=0.0,buyuk=0.0;
	printf("Lutfen en buyuk ussu giriniz");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
	
    	printf("Lutfen ussu %d olan degiskenin katsayisini giriniz",i);
    	scanf("%d",&a[i]);
	}
	printf("Lutfen araligin baslangicini giriniz");
	scanf("%lf",&k);
	printf("Lutfen araligin sonunu giriniz");
	scanf("%lf",&l);
	printf("lutfen epsilone degerini giriniz");
	scanf("%lf",&e);
    for(i=0;i<=n;i++){
    	kucuk+=pow(k,i)*a[i];
    	buyuk+=pow(l,i)*a[i];
	}
	if(kucuk*buyuk>0){
		printf("Bu aralikta kok yoktur");
	}
	else{
	
	
		
		i=1;
		while(l-k>e || k-l>e){
			s=(k+l)/2;
			for(j=0;j<=n;j++){
    	y+=pow(s,j)*a[j];
    }
			if(y*buyuk<=0){
				k=s;
				printf("%d. tekrarda degeri = %lf\n",i,s);
			}
			else{
				l=s;
				printf("%d. tekrarda degeri = %lf\n",i,s);
			}
			i++;
			y=0;
			
		}
		if(abs(k)<abs(l)){
			printf("yaklasik deger %lf",k);
		}
		else{
			printf("yaklasik deger %lf",l);
		}
	}



    return 0;
}
