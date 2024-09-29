#include <stdio.h>
int main(){
	int i;
	int a,b,y;
	for(i=100;i<999;i++){
		y=i/100;
		a=((i-(y*100))/10);
		b=i% 10;
	
	if(y*y*y+a*a*a+b*b*b==i){
		printf("%d\t",i);
	}
}
	return 0;
}
//kod calýsýyor
