#include <stdio.h>
#define Square(X) X*X

int main(){
	char x;

/*1-a*/	printf("\nSquare=%d\n",Square(10+2));

/*1-b*/	x='H';
		switch(x){
			case ('H') : printf("HELLO\n");
			case ('W') : printf("WELCOME\n");	
			case ('B') : printf("BYE\n");
			break;
		};
		
/*1-c*/ char *s[]={"sifirinci","white","pink","ucuncu"};
		char **ptr[]={s+3,s+2,s+1,s}, ***p;
		p=ptr;
		++p;
		printf("%s\n",**p+1);	
  	return 0;
	
}


