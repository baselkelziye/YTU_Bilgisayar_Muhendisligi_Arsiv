// Kullanıcıdan alınan bir karakter dizisinin ilk harfini sabit tutarak,
// sonraki her bir karakteri kendisinden bir önceki karakterin değeri
// ve kendisinin alfabedeki sıra değeri (a=1,b=2,...,z=26) toplamı kadar ileri
// kaydıran bir C programı tasarlayınız. İşlem sonucunda 'z' karakteri
// aşılıyorsa alfabenin başına dönülmelidir.

#include <stdio.h>

int main()
{
	int i = 1;
	char str[1024];
	printf("Karakter dizisini giriniz: ");
	scanf("%s", str);
	
	if(str[0] != '\0') // Eğer boş ise hiçbir işlem yapılmamalı
	{
		while(str[i] != '\0')
		{
			str[i] = (str[i-1] - 'a' + (str[i] - 'a' + 1)) % 26 + 'a';
			i++;
		}
	}
	
	printf("Oluşan yeni karakter dizisi: %s\n", str);
	return 0;	
}
