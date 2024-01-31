#include <stdio.h>
#include <math.h>
#include <conio.h>
int main(void){
	int n,i,k=0;
	double a[100];
	printf("lutfen eleman sayisini giriniz");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Lutfen %d. sayiyi giriniz",i);
		scanf("%lf",&a[i]);
	}
	i=1;
	a[0]=a[1]-1;
	while(a[i]+1==a[i+1] && i+1!=n){
		k=(i+1)/2+(n/2);
		if(a[1]+k-1==a[k]){
		
		i=(i+n)/2;
	}
	else{
		n=(i+1)/2+(n+1)/2;
	}
}
k=a[i]+1;
if(i+1==n){
	if(a[i]+1==a[i+1]){
		printf("Akisi bozan sayi yok");
	}
	else{
		printf("%d",k);
	}
}
else{
	printf("%d",k);
}
	return 0;
}
