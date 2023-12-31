#include <stdio.h>
#include <stdlib.h>
#define SIZE 2048
void func(int * dizi[SIZE],int *a){
	int b;
	int s,d;
	b=*a;
	s=*a;
	if(b>2){
	b=2*(b);
	if((dizi)[0][b]<0){
		b=s;
		b--;
		func(&dizi,&b);
		func(&dizi,&b);
		d=*a;
		b=(b)-(*a);
		b=(b)+1;
		func(dizi,&b);
		b=*a+d;
		s=s*2;
		*dizi[s]=d;
		*a=d;
		
	}	
	else{
		b=*dizi[b];
		*a=b;
	}
	}
	else
	*a=1;
	
	
	
	
	
}
int main(){
	int a=5;
	int *dizi,i;
	dizi=(int *)malloc(2048*sizeof(int));
	for(i=0;i<2048;i++){
		dizi[i]=-1;
	}
	
	func(&dizi,&a);
	
	return 0;
}
