#include <stdio.h>
#include <stdlib.h>
typedef struct term{
	int derece;
	int katsayi;
}TERM;

typedef struct poly{
	TERM *terms;
	int N;
}POLY;

void getTerms(POLY* p);
void writeTerms(POLY p);
void topla(POLY p1, POLY p2, POLY *p3);
int getMax(int x, int y);
int dereceBul(POLY p);
POLY* toplav2(POLY p1, POLY p2);

int main(){
	srand(time(NULL));
	POLY p1, p2, p3, *p4;
	printf("N sayisi") ; scanf("%d",&p1.N);
	p1.terms = (TERM*) malloc(p1.N*sizeof(TERM));
	getTerms(&p1);
	writeTerms(p1);
	
	printf("\nN sayisi") ; scanf("%d",&p2.N);
	p2.terms = (TERM*) malloc(p2.N*sizeof(TERM));
	getTerms(&p2);
	writeTerms(p2);
	
	topla(p1,p2,&p3); 
	printf("\n");
	writeTerms(p3);
	
	p4 = toplav2(p1,p2); 
	
	writeTerms(*p4);
	
	return 0;
}
void topla(POLY p1, POLY p2, POLY *p3){
	int N, M, MAX;
	int i,j=0, counter=0;
	int *dizi;
	N = dereceBul(p1);
	M = dereceBul(p2); 
	MAX = getMax(N,M) +1 ; 
	dizi = (int*) calloc(MAX,sizeof(int));
	for(i=0;i<p1.N;i++){
		dizi[p1.terms[i].derece] += p1.terms[i].katsayi;
	}
	for(i=0;i<p2.N;i++){
		dizi[p2.terms[i].derece] += p2.terms[i].katsayi;
	}
	
	for(i=0;i<MAX;i++) {
		if(dizi[i]!=0) 
			counter++;
	}
	p3->N = counter;
	p3->terms = (TERM*)malloc(counter*sizeof(TERM));
	
	for(i=0;i<MAX;i++) {
		if(dizi[i]!=0) {
			p3->terms[j].derece = i;
			p3->terms[j].katsayi = dizi[i];
			j++;	
		}
	}
}

POLY* toplav2(POLY p1, POLY p2){
	int N, M, MAX;
	POLY *p3;
	int i,j=0, counter=0;
	int *dizi;
	N = dereceBul(p1);
	M = dereceBul(p2); 
	MAX = getMax(N,M) +1 ; 
	dizi = (int*) calloc(MAX,sizeof(int));
	for(i=0;i<p1.N;i++){
		dizi[p1.terms[i].derece] += p1.terms[i].katsayi;
	}
	for(i=0;i<p2.N;i++){
		dizi[p2.terms[i].derece] += p2.terms[i].katsayi;
	}
	
	for(i=0;i<MAX;i++) {
		if(dizi[i]!=0) 
			counter++;
	}
	p3 = (POLY*) malloc(1*sizeof(POLY));
	
	p3->N = counter;
	p3->terms = (TERM*)malloc(counter*sizeof(TERM));
	
	for(i=0;i<MAX;i++) {
		if(dizi[i]!=0) {
			p3->terms[j].derece = i;
			p3->terms[j].katsayi = dizi[i];
			j++;	
		}
	}
	return p3;
}


int getMax(int x, int y){
	return x>=y ? x:y; 
}

int dereceBul(POLY p){
	int i;
	int max=0;
	for(i=0;i<p.N;i++){
		if(p.terms[i].derece>max)
			max = p.terms[i].derece;
	}
	
	return max;
}

void getTerms(POLY* p){
	int i;
	for(i=0;i<p->N;i++){
		
		/*printf("%d. terim icin katsayi",i); 
		scanf("%d",&p->terms[i].katsayi);
		printf("%d. terim icin derece",i); 
		scanf("%d",&p->terms[i].derece);*/
		p->terms[i].katsayi = rand() % 5 + 1 ; 
		(*p).terms[i].derece = rand() % p->N + 1  ; 
		
	}
	
}
void writeTerms(POLY p){
	int i;
	for(i=0;i<p.N-1;i++){
		printf("%d.X^%d + ",p.terms[i].katsayi,p.terms[i].derece);
	}
	printf("%d.X^%d",p.terms[i].katsayi,p.terms[i].derece);
}
