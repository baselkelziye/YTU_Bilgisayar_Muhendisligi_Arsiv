// Verilen bir string'in icerisindeki harflerin histogramini bulma
#include <stdio.h>
int main()
{
	static int frekans[26];
	int i=0, indis;
	char text[100];
	gets(text);
	
	while (text[i])
	{
		if ((text[i]<='z') && (text[i]>='a'))
		{
			indis=text[i]-'a';
			frekans[indis]++;
		}
		i++;
	}
	
	for (i=0;i<26;i++)
		printf("%c %d\n",'a'+i, frekans[i]);
		
	return 0;	
}
