#include <stdio.h>
int main(){
	int inttype;
	float floattype;
	double doubletype;
	char chartype;
	
	printf("%zu byte\n",sizeof(inttype));
	printf("%zu byte\n",sizeof(floattype));
	printf("%zu byte\n",sizeof(doubletype));
	printf("%zu byte\n",sizeof(chartype));
	
	return 0;
}
