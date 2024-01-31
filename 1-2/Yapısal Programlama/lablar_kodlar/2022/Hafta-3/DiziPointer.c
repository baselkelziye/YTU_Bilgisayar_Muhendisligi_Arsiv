#include <stdio.h>
void print(int d[], int n);
void print2(int *px, int n);
void print3(int *px, int n);
void print4(int *px, int n);
int main(){
	int d[5]={1,2};
	int x=9; int *px=&x;
	printf("%d\n",*&*&x);
	printf("%p - %p\n",&x,&*px);
//printf("%d",**&&x);
	printf("\n%p %p %p\n",d,&d,&d[0]);
	//int *px;
	px=d;
	print(d,5);
	printf("===============\n");
	print2(px,5);
	printf("===============\n");
	print3(&d[0],5);
	printf("===============\n");
	print4(&d,5);
	setarray(d,5);
	print3(&d[0],5);
	f(d[4]);
}
void f(int a){ // call by value
	a++;
}
void setarray(int *d, int n){  // call by pointer / reference
	int i;
	for(i=0;i<n;i++){
		*(d+i) = i;
	}
}
void print(int d[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d - %p \n",i[d],&d[i]);
	}
}

void print2(int *px, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d - %p \n",*px,px);
		px++;
	}
	printf("%d - %p \n",*px,px);
}

void print3(int *px, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d - %p \n",*(px+i),px+i);
		
	}
}

void print4(int *px, int n){
	int i;
	for(i=0;i<n;i++,px++){
		printf("%d - %p \n",*px,px);
		
	}
}
