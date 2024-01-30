#include <stdio.h>
#include <stdlib.h>
typedef struct{
 char isim[35]; 
 short yas;
 float puan; 
}OGR; // ogr tipi oluþturulur. bu tipden yeni degiskenler uretilebilir

void FindMax (OGR *,int);
void NotGuncelle (OGR *);
OGR NotGuncellev2 (OGR);
OGR* NotGuncellev3 (OGR);
OGR* YerAc (int);

int main()
{
	OGR ogrenciler[3], ogrenci1, ogrenci2, *ogrenci3,*ogrPtr;
	int i,n=3;
	for (i=0;i<n;i++)
		scanf("%s %d %f",ogrenciler[i].isim,&ogrenciler[i].yas,&ogrenciler[i].puan);
	FindMax (ogrenciler,n);
	scanf("%s %d %f",ogrenci2.isim,&ogrenci2.yas,&ogrenci2.puan);
	NotGuncelle (&ogrenci2);
	printf("ogrenci2 nin puani v1:%f\n",ogrenci2.puan);
    ogrenci1=NotGuncellev2 (ogrenci2);
	printf("ogrenci2 nin puani v2:%f\n",ogrenci1.puan); 
	ogrenci3=NotGuncellev3 (ogrenci1);
	printf("ogrenci2 nin puani v3:%f\n",ogrenci3->puan); 
	ogrPtr=YerAc(3);
	ogrPtr[0].puan=80;
	printf("yeni ogrencinin puani:%f\n",ogrPtr[0].puan); 
	return 0;
}

void FindMax (OGR *ogrenciDizi,int n) //void findmax (OGR ogrenciDizi[],int n)
{
	int i,max=0;
	for (i=0;i<n;i++)
	{
		if (ogrenciDizi[i].puan>max)
			max=ogrenciDizi[i].puan;
	}
	printf("%d\n",max);
}

void NotGuncelle (OGR *ogrenci)  //    void NotGuncelle (OGR ogrenci) olsaydý yaptýðýmýz degisiklik main functionýA yansýmazdý. structure in compiler tarafinda olusturulnus kopyasýna yansýrdý
{
	if (ogrenci->yas < 18)
		ogrenci->puan++;
}

OGR NotGuncellev2 (OGR ogrenci)  
{
	if (ogrenci.yas < 18)
		ogrenci.puan++;
	return ogrenci;
}

OGR* YerAc (int n)
{
	return (OGR*) calloc (n, sizeof(OGR));
}

OGR* NotGuncellev3 (OGR ogrenci)  
{
	if (ogrenci.yas < 18)
		ogrenci.puan++;
	return &ogrenci;
}
