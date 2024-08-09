#include<stdio.h>

int main(){
	float x=1.05;
	float y = 1;
	float h = 0.05;
	
	int iter = (int)((x-y)/h+0.5);
	printf("%d",iter);
	printf("\n%f",1.0/6.0);
	
	return 0;
}
