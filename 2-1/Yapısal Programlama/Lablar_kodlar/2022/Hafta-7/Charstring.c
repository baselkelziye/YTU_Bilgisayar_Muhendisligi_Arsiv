#include <stdio.h>

int main(){
	
	char x[20];
	char *p;
	int a,b,c;
	
	printf("enter string");
	scanf("%s",&x);
	printf("%s has been entered",x);
	fflush(stdin);
	printf("enter string");
	scanf("%[^\n]s",&x);
	printf("%s has been entered",x);
	printf("enter string");
	fflush(stdin);
	gets(x);
	printf("%s has been entered",x);
	
	sscanf("1 2 33","%d %d %d",&a,&b,&c);
	printf("%d %d %d",a,b,c);
	sprintf(x,"\n%d; %d ;abcd; %d; %s",a,c,b,"12324");
	printf("string=%s",x);
	p=strtok(x,";");
	
	while(p!=NULL){
		printf("%s \n",p);
		p=strtok(NULL,";");
	}
	
}
