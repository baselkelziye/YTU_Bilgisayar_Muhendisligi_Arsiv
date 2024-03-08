#include<stdio.h>

int main(){
	
	char c, *p, str[]="ZONGULDAK";
	
	for(c='A';c<='Z';c++){	
	p=str;
	while(*p!='\0'){
		
		if(*p==c){
			printf("%c",*p);
			p++;
		}
	}	
		
		
	}
	
	
}
