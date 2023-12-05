#include <stdio.h>
#include <math.h>
#define SIZE 1000
int main(void){
	int l,n,i,j;
	float a[SIZE],b[SIZE],m,w,t=0.0;
	double q;
	printf("lutfen integrali alinacak fonksiyonun en buyuk katsayisini giriniz");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		printf("Lutfen ussu %d olan degiskenin katsayisini giriniz :",i);
		scanf("%f",&a[i]);
	}
	printf("lutfen integralin baslangicini giriniz");
	scanf("%lf",&q);
	printf("lutfen integralin bitisini giriniz");
	scanf("%f",&m);
	printf("lutfen aralik sayisini giriniz");
	scanf("%d",&l);
	w=(m-q)/l;
	for(i=0;i<=l;i++){
		b[i]=0;
	}
	for(i=0;i<=l;i++){
		for(j=0;j<=n;j++){
			b[i]+=pow(q,j)*a[j];
		}
		q+=w;
		
	}
	for(i=1;i<=l-1;i++){
		t+=b[i];
	}
	t=(t+(b[0]+b[l])/2)*w;
	printf("%f",t);
	return 0;
}
