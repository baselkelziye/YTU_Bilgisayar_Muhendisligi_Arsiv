#include<stdio.h>
#define MAX 10
void yaz(int array[MAX]);
void yaz2(int *pA);
int main(){
	int array[MAX]={1,2,3};
	int j=0;
	yaz(array);
	int *x=array;
	x=&array;
	x=&array[0];
	yaz2(array);
	yaz2(&array);
	yaz2(&array[0]);
	f(array);
	yaz2(array);
	f2(array);
	yaz2(array);
	f3(array);
	yaz2(array);
	printf("\n%d %d %d",array[j], *(array+j), j[array]);
		printf("\n%d %d %d",&array[j], (array+j), &j[array]);
}
void yaz(int array[MAX]){
	int i;
	for(i=0;i<MAX;++i){
		printf("%d -",array[i]);
	}
	printf("\n");
}

void yaz2(int *pA){
	int i;
	for(i=0;i<MAX;++i){
		printf("%d -",*(pA+i));
	}
	printf("\n");
}

void f(int array[MAX]){
	int i;
	for(i=0;i<MAX;++i){
		array[i]+=1;
	}
}
void f2(int *array){
	int i;
	for(i=0;i<MAX;++i){
		*(array+i)+=1;
	}
}

void f3(int *array){
	int i;
	for(i=0;i<MAX;++i){
		array[i]+=1;
	}
}
