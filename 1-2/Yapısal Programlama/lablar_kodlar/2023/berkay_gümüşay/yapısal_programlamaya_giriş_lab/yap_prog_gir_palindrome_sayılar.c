#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i,j,k,control,t=0,temp;
	
	
	for(i=100;i<1000;i++){
		j=0;
		j = j + ((i%10)*100) + ((i/10)%10)*10 + (i/100);
		if(i%10 == 0){
			printf("%3d0%2d",i,j);
		}
		else{
			printf("%3d%3d",i,j);
		}
		printf("\n");
		
	}
	
	
	
	
	
	return 0;
}
