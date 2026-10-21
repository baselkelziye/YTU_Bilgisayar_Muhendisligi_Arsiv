#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ogr
{
	int id;
	char isim[10];
	char ders[10];
	int puan;
} OGR;
void dosyaOku(OGR **ptr);
void ogrenciyiDosyayaYaz(OGR o);
void raporYazdir(OGR *ptr, int N);

int main()
{
	int i;
	FILE *fp;
	OGR o1[4] = {{1, "ali", "mat1", 100}, {1, "veli", "mat1", 30}, {1, "ayse", "mat1", 80}, {1, "fatma", "mat1", 70}};
	int N = 4;
	OGR *ptr = (OGR *)malloc(N * sizeof(OGR));
	fp = fopen("input.txt", "w+");
	fwrite(&N, sizeof(int), 1, fp);
	fwrite(o1, sizeof(OGR) * N, 1, fp);
	fclose(fp);
	dosyaOku(&ptr);

	for (i = 0; i < N; i++)
	{
		ogrenciyiDosyayaYaz(ptr[i]);
	}
	raporYazdir(ptr, N);
	return 0;
}
void ogrenciyiDosyayaYaz(OGR o)
{
	FILE *fp;
	char dosyaAdi[15];
	strcpy(dosyaAdi, o.isim);
	strcat(dosyaAdi, ".txt");
	fp = fopen(dosyaAdi, "w+");
	fprintf(fp, "Merhaba %d numarali %s, %s dersinden aldiðiniz puan: %d\n", o.id, o.isim, o.ders, o.puan);
	fclose(fp);
}

void dosyaOku(OGR **ptr)
{
	FILE *fp;
	int N;
	fp = fopen("input.txt", "r");
	fread(&N, sizeof(int), 1, fp);
	*ptr = (OGR *)malloc(N * sizeof(OGR));
	fread(*ptr, sizeof(OGR) * N, 1, fp);
	fclose(fp);
}
void raporYazdir(OGR *ptr, int N)
{
	FILE *fp;
	int i, toplam = 0, gecen = 0;
	double ortalama;
	fp = fopen("rapor.txt", "w+");
	for (i = 0; i < N; i++)
	{
		toplam += ptr[i].puan;
		if (ptr[i].puan >= 40)
			gecen++;
	}
	ortalama = toplam / N;
	fprintf(fp, "mat1 dersinin ortalamasi: %.2lf basarili ogrenci sayisi: %d\n", ortalama, gecen);
	fclose(fp);
}

