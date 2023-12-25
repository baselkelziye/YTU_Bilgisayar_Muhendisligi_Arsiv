// verilen bir paragraftaki harflerin dikey histogramlarinin cikaran program
#include <stdio.h>
int main()
{
	static int counter[26];
	int i,j,indis,sum=0,normalized;
	static char histmat[100][26];
	char text[100];
	printf("paragrafi giriniz\n");
	gets(text);
	i=0;
	while (text[i]!=0)
	{
		if ((text[i]<='z') && (text[i]>='a'))
		{
			indis=text[i]-'a';
			counter[indis]++;
		}
	i++;
	}
	for (i=0;i<26;i++)
	{
		printf("%c:%d\n",'a'+i,counter[i]);
		sum+=counter[i];
	}
	
//Frekanslar 100'lik dilime gecirilir
	for (j=0;j<26;j++)
	{
		normalized=(counter[j]/(float)sum)*100;
		for (i=99;i>=100-normalized;i--)
			histmat[i][j]='|';
		
	}
	
	for (i=0;i<100;i++)
	{
		for (j=0;j<26;j++)
			printf("%c ",histmat[i][j]);
		printf("\n");
	}
	
	
	return 0;
}
