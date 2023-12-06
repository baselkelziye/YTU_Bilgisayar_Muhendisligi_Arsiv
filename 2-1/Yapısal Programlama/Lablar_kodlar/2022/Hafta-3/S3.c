#include<stdio.h>
void swap4(int **a, int **b);
void swap3(int *a, int *b);
void swap2(int *a, int *b);
void swap2(int *a, int *b);
void swap(int , int );
int main(){
	int x=4, y=6;
	int *pX=&x;
	int *pY=&y;
	swap(x,y);
	printf("%d--%d\n",x,y); // 4-6
	swap2(&x,&y);
	printf("%d--%d\n",x,y); //6-4
	swap3(pX,pY);
	printf("%d--%d\n",*pX,*pY); //6-4
	swap4(&pX,&pY);
	printf("%d--%d\n",*pX,*pY); //4-6
}
void swap4(int **a, int **b){
	int *t;
	
	t=*a;
	printf("\n%d--%d--%d\n",*t, **a,**b);
	*a=*b;
	*b=t;
	
}
void swap3(int *a, int *b){
	int *t;
	t=a;
	a=b;
	b=t;
}
void swap2(int *a, int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

void swap(int a, int b){//call by value-deep copy
	int t=a;
	a=b;
	b=t;
}


