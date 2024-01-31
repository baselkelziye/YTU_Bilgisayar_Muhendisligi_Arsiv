//Verilen bir kelime aþaðýdaki kurala gore sifrelenmektedir
//çift numarali indislerde bulunan karakterler key kadar sonra gelen karakter ile
//tek numarali indislerde bulunan karakterler key kadar once gelen karakter ile kodlanacaktir
#include <stdio.h>
int main()
{
	int i=0, n=4, yon=1, key;
	char kelime[10];
	gets(kelime);
	scanf("%d",&key);
	while (kelime[i])
	{
		kelime[i]=kelime[i]+(key*yon);
		yon=-yon;
		i++;
	}
	puts(kelime);
	return 0;	
}
