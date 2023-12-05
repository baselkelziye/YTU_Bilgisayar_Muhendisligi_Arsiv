#include <stdio.h>
#include <math.h>
#define SIZE 10
int main(void){
	int i,j=0,n;
	float a[SIZE],q,e,s,bir,iki,qiki;
	printf("Lutfen en buyuk ussu giriniz");
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		printf("lutfen ussu %d olan elemanin katsayisini giriniz",i);
		scanf("%f",&a[i]);
	}
	printf("Lutfen baslangic degerini giriniz");
	scanf("%f",&q);
	printf("lutfen artis miktarini giriniz");
	scanf("%f",&s);
	printf("Lutfen epsilone degerini giriniz");
	scanf("%f",&e);
	bir=0;
	for(i=0;i<=n;i++){
		bir+=pow(q,i)*a[i];
	}
	q+=s;
	s*=2;
	while((qiki-q>e || q-qiki>e) && j<100){
		iki=0;
		j=0;
		q-=s;
		s/=2;
	while(bir*iki>=0 && j<100){
		iki=0;
		qiki=q;
		q+=s;
		j++;
	for(i=0;i<=n;i++){
		iki+=pow(q,i)*a[i];
	}
	if(iki==0)
	j=101;
	if(j==100)
	iki=-1*bir;
	}

}
	if(j==100)
	printf("Deger bulunamadi");
	else
	printf("%f",q);
	
	return 0;
}
