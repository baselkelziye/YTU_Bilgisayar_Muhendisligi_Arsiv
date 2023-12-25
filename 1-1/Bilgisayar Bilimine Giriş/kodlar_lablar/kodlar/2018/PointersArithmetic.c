// usage of pointers
#include <stdio.h>
int main()
{
	char dizi[5]={'a','b','c','d','e'},*p1_ch,**p2_ch;
	char ch1,ch2='Y';
	int i;
	p1_ch=dizi;
	*(p1_ch+3)='*';
	
	p2_ch=&(p1_ch);
	
	*(*p2_ch)='z';
	
	for (i=0;i<5;i++)
		printf("%c ",dizi[i]);
		
		
	char *p;
	p=&dizi[3];
	printf("\n%c",*(p+1));

	return 0;
}

