//verilen bir paragrafta her cümlenin ilk harfini büyüten programı c dilinde kodlayınız
#include <stdio.h>
int main()
{
	char paragraf[100];
	int i=0;
	printf("paragrafi giriniz\n");
	gets(paragraf);
	
	if ((paragraf[0]<='z') && (paragraf[0]>='a'))	paragraf[0]=paragraf[0]-('a'-'A');
	
	while(paragraf[i]!='\0')
	{
		if ((paragraf[i]=='.') && (paragraf[i+1]<='z') && (paragraf[i+1]>='a'))
			paragraf[i+1]=paragraf[i+1]-('a'-'A');
		i++;
	}
	printf("%s\n",paragraf);
	
	return 0;
}
