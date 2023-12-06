#include <stdio.h>
/*typedef struct {
	char name[10];
	char surname[10];
	int id;
}sinif;
sinif * scan(sinif *a ){
	int i;
	a=(sinif*)malloc(sizeof(sinif));
	printf("Lutfen isim gir");
	scanf("%s",a->name);
	printf("Lutfen soyisim gir");
	scanf("%s",a->surname);
	printf("Lutfen id gir");
	scanf("%d",&i);
	a->id=i;
	return a;
}*/
int sum(int k,int m){
	return k+m;
}
int mul(int a,int b){
	return a*b;
}
int devide(int a,int b){
	return a/b;
}
void dene(){
	printf("Hello");
}
void deger(int a){
	printf("Lutfen deger giriniz");
	scanf("%d",&a);
	printf("\n%d",a);
}
int main(){
	//sinif *b;
	int (*a[5])();
	int k=1,m=3;
	void (*c[10])();
	//b=scan(b);
//	printf("%s",b->name);
	a[0]=sum;
	a[1]=mul;
	a[2]=devide;
	c[0]=dene;
	c[1]=deger;
	c[0]();
	c[1](k);
	k=a[0](k,m);
	printf("%d",k);
	m=a[1](k,m);
	printf("%d",m);
	k=a[2](m,k);
	printf("%d",k);
	return 0;
}
