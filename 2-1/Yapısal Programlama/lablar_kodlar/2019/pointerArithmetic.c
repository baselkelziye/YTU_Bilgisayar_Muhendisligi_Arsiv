#include <stdio.h>
int main()
{
	char dizi[5]={'a','b','c','d','e'};
	char *p1_ch, **p2_ch;
	int i;
	p1_ch=dizi;
	*(p1_ch+3)='*';
	p2_ch=&(p1_ch);
	**p2_ch='z';
	for (i=0;i<5;i++)
		printf("%c", dizi[i]);
	return 0;
}
