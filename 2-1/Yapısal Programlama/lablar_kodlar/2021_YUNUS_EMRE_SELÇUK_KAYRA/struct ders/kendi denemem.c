#include <stdio.h>
#include <stdlib.h>
typedef struct okul{
	char isim[20];
	int no;
	struct okul * adres;
}sinif;
sinif * head;
void print(sinif *a){
	printf("%s",a->isim);
	printf("\t%d\n",a->no);
}
void println(){
	sinif * p;
	for(p=head;p!=NULL;p=p->adres)
	print(p);	
}
sinif * eleman(){
	int i;
	sinif * a;
	a=(sinif*)malloc(sizeof(sinif));
	printf("isim\n");
	scanf("%s",a->isim);
	printf("no\n");scanf("%d",&i);a->no=i;
	a->adres=NULL;
	return a;
}
void ekle(sinif * e){
	sinif *p;
	if(head==NULL)
	head=e;
	else{
	for (p=head; p->adres != NULL; p=p->adres); 
	p->adres=e;}
}
void sil(sinif *goner){
sinif *p;
if(goner == head)
head=goner->adres;
else{
for(p=head; (p!=NULL) && (p->adres != goner); p=p->adres);
if(p == NULL){
printf("delete_element(): could not find the element \n"); return;
}
p->adres=goner->adres; 
}
free(goner);}
void araya(){
	int n,i;
	sinif *q,*a;
	printf("kacinci elemandan sonra ekleyeceksiniz?\n");
	scanf("%d",&n);
	q=head;
	if(n==0){
	a=(sinif*)malloc(sizeof(sinif));
	printf("Lutfen ismi giriniz\n");
	scanf("%s",a->isim);
	printf("Lutfen no giriniz\n");
	scanf("%d",&i);
	a->no=i;
	head=a;
	a->adres=head;
	}
	else{
	for(i=0;i<n-1;i++){
		q=q->adres;
	}
	a=(sinif*)malloc(sizeof(sinif));
	printf("Lutfen ismi giriniz\n");
	scanf("%s",a->isim);
	printf("Lutfen no giriniz\n");
	scanf("%d",&i);
	a->no=i;
	a->adres=q->adres;
	q->adres=a;
	}
}
int main(){
	sinif p,*q,*f;
	int i;
	for(i=0;i<3;i++)
	ekle(eleman());		
	println();
	araya();
	println();
	araya();
	println();
	araya();
	println();
	
	
	return 0;
}
