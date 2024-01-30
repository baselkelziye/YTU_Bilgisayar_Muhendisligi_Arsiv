// usage of pointers
#include <stdio.h>
int main()
{
	char *p_ch;
	char ch1='A',ch2;
	
	printf("adress of p_ch p %p\n",&p_ch);
	printf("adress of p_ch d %d\n",&p_ch);
	printf("value stored in ch1 %c\n",ch1);
	printf("adress of ch1 %p\n",&ch1);
	p_ch=&ch1;
	printf("value of p_ch %p\n",p_ch);
	printf("dereferenced vallue of p_ch %c\n",*p_ch);
	
	return 0;
}
