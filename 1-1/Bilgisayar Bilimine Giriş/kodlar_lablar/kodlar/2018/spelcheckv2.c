#include <stdio.h>
#include <string.h>
#define MAX_WORDS 50
#define LAST_LANG 2

int main()
{
	char *dict[LAST_LANG] [MAX_WORDS] = { { "abhor", "able", "abort", "about", NULL } ,
											 { "absurde" , "accepter", "accord", "achat" , NULL } };

	char str[10];
	int diff=-1,language,j=0;
	printf("type the word\n");
	scanf("%s",str);

	printf("which language 0 or 1 ?\n");
	scanf("%d",&language);

	while (dict[language][j] && (diff < 0))
	{
		diff = strcmp(dict[language][j],str);   //ilk kelime buyukse 1,eþitlerse 0, ikinci kelime buyukse -1
		j++;
	}

	if (diff==0)
		printf("match");
	else
	{
        j--;
        printf("best match:%s",dict[language][j]);
	}

}

