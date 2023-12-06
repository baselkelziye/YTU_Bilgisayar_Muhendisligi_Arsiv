#include <stdio.h>
void f(int x, int *y);
void f1(int x,const int *y);
int main(){
	int x=5;
	int y=6;
	printf("%d %d\n",x,y);
	f(x,&y);
	x=y=7;
	printf("%d %d\n",x,y);
	f2(x,&y);
	printf("%d %d\n",x,y);
	
}

void f(int x, int *y){
	x=0;
	*y=0;
}

void f1(int x,const int *y){
	x=0;
	//*y=0; invalid
	y=&x; // valid
	
}

void f2(int x, int *const y){
	x=0;
	*y=0; 
	//y=&x;  invalid	
}

void f3(int x,const int *const y){
	x=0;
	//*y=0;  invalid
	//y=&x;  invalid	
}
