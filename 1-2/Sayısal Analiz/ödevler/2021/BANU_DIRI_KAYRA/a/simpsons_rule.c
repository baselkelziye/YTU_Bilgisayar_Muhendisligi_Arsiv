#include <stdio.h>
#include <math.h>
#define SIZE 1000
int main(void){
	int l,n,i,j,k;
	float a[SIZE],b[SIZE],c[SIZE],m,w,t=0.0,y;
	double q;
		printf("lutfen integrali alinacak fonksiyonun en buyuk ussunu giriniz");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		printf("Lutfen ussu %d olan degiskenin katsayisini giriniz :",i);
		scanf("%f",&a[i]);
	}
	printf("lutfen integralin baslangicini giriniz");
	scanf("%lf",&q);
	printf("lutfen integralin bitisini giriniz");
	scanf("%f",&m);
	printf("lutfen n sayisini giriniz");
	scanf("%d",&l);
	w=(m-q)/l;
	y=q;
	t=w/3;
	q+=t;
	for(i=1;i<=l;i++){
		q-=t;
		for(j=0;j<=3;j++){
			b[j]=0;
			for(k=0;k<=n;k++){
			b[j]+=pow(q,k)*a[k];}
			q+=t;
		}
		c[i]=(m-y)/l*(b[0]+3*b[1]+3*b[2]+b[3])/8;
	}
	t=0;
	for(i=1;i<=l;i++){
		t+=c[i];
	}
	printf("%f",t);
	return 0;
}
