#include <stdio.h>
#include <stdlib.h>
typedef struct complex{
	double real;
	double imag;
} COMPLEX; 
COMPLEX* allocateList(int N);
void writeComplexNumber(COMPLEX c);
void setValues(COMPLEX *c);
void writeList(COMPLEX *c, int N);
int main(){
	COMPLEX c={1.0,-2.0};
	COMPLEX *c1;
	COMPLEX *c2; 
	c1 = &c; 
	printf("%p--%p--%p\n",&c,&c.real,&c.imag);
	writeComplexNumber(c);
	
	setValues(c1); // setValues(&c); 
	writeComplexNumber(*c1);
	
	c2 = allocateList(10);
	writeList(c2,10);
}

COMPLEX* allocateList(int N){
	return (COMPLEX *) malloc(N*sizeof(COMPLEX));
}

void writeList(COMPLEX *c, int N){
	int i;
	for(i=0;i<N;i++){
		writeComplexNumber(c[i]);
	}
}

void writeComplexNumber(COMPLEX c){ // call by value
	//printf("%p--%p--%p\n",&c,&c.real,&c.imag);
	if(c.imag<0) 
		printf("%lf - %lfi",c.real,abs(c.imag));
	else if(c.imag==0)
		printf("%lf",c.real);
	else
		printf("%lf + %lfi",c.real,c.imag);
	
	printf("\n");
}

void setValues(COMPLEX *c){ // call by ref via pointer i.e. fake call by ref
	(*c).real = 4;
	c->imag = 6;
}
