#include <stdio.h>
int ahmet(int a){
	int i=1;
	if(i<a){
	return a*ahmet(a-1);
	}
	return 1;
}
int main(void){
	int b=7;
	b=ahmet(b);
	printf("%d",b);
	return 0;
}
