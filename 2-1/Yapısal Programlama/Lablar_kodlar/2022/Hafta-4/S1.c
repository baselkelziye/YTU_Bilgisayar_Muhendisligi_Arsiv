#include <stdio.h>
#include <stdlib.h>

int* g();
int* h();
int main(){
	int a;
	int *p;
	a = f(); // legal	
	p = g(); // legal
	
	p = h(); // legal
	
  //	f() = 5;  // 3 = 5 ,illegal 
     
    p = h();
	*p = 5;
	
	//*h() = 5; 
    
    
    
     printf("%d ",*p);
	return 0;
}

int f(){
	int x=6;
	return x; //deep copy
}

int* g(){
	int *p;
	int x=7;
	int dizi[5];
	return &dizi[4];
}

int* h(){
	int *dizi=(int*) malloc(5*sizeof(int));
	
	return &dizi[4];
}
