#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct MyStruct{
	int id;
	char *name;
	char surname[20];
};

union myUnion{
	int ramGB;
	float price;
	char *name;
};


int main(){
	struct MyStruct s1;
	int i=0;
	s1.id = 10;
	s1.name = "ahmet";
	printf("%d , %c\n",s1.id, *(s1.name+1));
	while(*(s1.name+i)!='\0'){
		printf("%c",*(s1.name+i));
		i++;
	}
	while(*(s1.name)!='\0'){
		printf("%c",*(s1.name++));
	}
	printf("\n");
	strcpy(s1.surname,"duran");
	printf("%s",s1.surname);
	
	union myUnion u1;
	u1.name = "lenovo";
	u1.price = 17000.99;
	u1.ramGB = 8;
	printf("\n %s", u1.name);
	
	
	return 0;
}
