//LAB 1 SORULARI

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float dortlukSistem[] = {4.0, 3.5, 3.0, 2.5, 0};
	int maxPuan[] = {100, 89, 79, 69, 59};
	int minPuan[] = {90, 80, 70, 60, 0};
	char isim[30];
	char soyad[30];
	
	float *p;
	p = dortlukSistem;
	int *a, *b;
	a = maxPuan;
	b = minPuan;
	
	printf("Ogrencinin adi: ");
	scanf("%s", &isim);
	printf("\nOgrencinin soyadi: ");
	scanf("%s", &soyad);
	
	int vize, final;
	
	printf("\nOgrencinin vize notu: ");
	scanf("%d", &vize);
	printf("\nOgrencinin final notu: ");
	scanf("%d", &final);
	
	float ort;
	ort = (vize * 0.4) + (final * 0.6);
	
	if(ort <= *(a) && ort >= *(b) ) 
	{
		printf("%s %s isimli ogrencinin not ortalamasi %f olarak gerceklesmis ve transkriptine %f olarak islenmistir.", isim, soyad, ort, *(p));
	}
	
	else if (ort <= *(a+1) && ort >= *(b+1))
	{
		printf("%s %s isimli ogrencinin not ortalamasi %f olarak gerceklesmis ve transkriptine %f olarak islenmistir.", isim, soyad, ort, *(p+1));
	}
	
	else if (ort <= *(a+2) && ort >= *(b+2))
	{
		printf("%s %s isimli ogrencinin not ortalamasi %f olarak gerceklesmis ve transkriptine %f olarak islenmistir.", isim, soyad, ort, *(p+2));
	}
	
	else if(ort <= *(a+3) && ort >= *(b+3))
	{
		printf("%s %s isimli ogrencinin not ortalamasi %f olarak gerceklesmis ve transkriptine %f olarak islenmistir.", isim, soyad, ort, *(p+3));
	}
	
	else if (ort <= *(a+4) && ort >= *(b+4))
	{
		printf("%s %s isimli ogrencinin not ortalamasi %f olarak gerçekleşmiş ve transkriptine %f olarak islenmistir.", isim, soyad, ort, *(p+4));
	}
	
	
	return 0;
}
