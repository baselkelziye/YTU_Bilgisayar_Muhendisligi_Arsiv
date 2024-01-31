#include <stdio.h>
typedef struct den{
	int no;
	char isim[10];
	struct den * adres;
}dene;
dene * q ;
dene * header=NULL;
dene * eleman_olustur(){
	dene * a; int i;
	a=(dene*)malloc(sizeof(dene));
	printf("isim"); scanf("%s",a->isim);
	printf("no"); scanf("%d",&i);a->no=i;
	a->adres=NULL;
	return a;
}
void eleman_ekle(dene * a){
	if(header==NULL){
		header=a;
	}
	else{
		for(q=header;q->adres!=NULL;q=q->adres);
	}
	q->adres=a;
	
}
int main(){
	dene *p;
	int i,j;
	eleman_ekle(eleman_olustur());
	for(q=header;q->adres!=NULL;q=q->adres)
	printf("%d %s",q->no,q->isim);
	return 0;
}
