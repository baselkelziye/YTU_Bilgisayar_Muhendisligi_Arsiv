#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>

struct Veri
{
	int i;
	int j;
	int sayi;
};

int seviye;
int kartlar[8][8];
int durum[8][8];//0 -Kapalý, 1- Açýk, 2- Bulundu 
int hafiza;
int hafizaKartSayi;
int boyut;
int bilgisayarPuan;
int oyuncuPuan;
int bilgisayarHamle;
int oyuncuHamle;
int sira;
struct Veri Hafiza[16];

void boyutBelirle()
{
	switch (seviye)
	{
	case 1:
		hafiza = 2;
		boyut = 4;
		break;
	case 2:
		hafiza = 6;
		boyut = 6;
		break;
	case 3:
		hafiza = 16;
		boyut = 8;
		break;
	default:
		printf("Boyle seviye olmaz.");
		break;
	}
	
	int i;
	for (i = 0; i < 16; i++)
	{
		struct Veri veri;
		veri.i = -1;
		veri.j = -1;
		Hafiza[i] = veri;
	}
	hafizaKartSayi = 0;
	bilgisayarPuan = 0;
	bilgisayarHamle = 0;
	oyuncuHamle = 0;
	oyuncuPuan = 0;
	sira = 0;
}

void seviyeSor()
{
	do
	{
		system("cls");
		printf("1. Kolay\n");
		printf("2. Orta\n");
		printf("3. Zor\n");
		printf("0. Cikis\n");

		printf("Lutfen seviyenizi secin:");
		scanf("%d", &seviye);
	} while (seviye > 3 || seviye < 0);

}

void sayilariDoldur() {

	srand(time(NULL));
    
    int i, j;
	int aralik = (boyut * boyut) / 2;
	int sayiMiktar[33] = { 0 };

	for (i = 0; i < boyut; i++)
	{
		for (j = 0; j < boyut; j++)
		{
			do
			{
				int r = (rand() % aralik) + 1;
				if (sayiMiktar[r] < 2)
				{
					kartlar[i][j] = r;
					durum[i][j] = 0;
					sayiMiktar[r]++;
					break;
				}
			} while (1);
		}
	}

}

void kartlariYazdir()
{
	int i, j;
	system("cls");
	for (i = 0; i < boyut; i++)
	{
		for (j = 0; j < boyut; j++)
		{
			if (durum[i][j] == 0)
				printf("[  *  ] ");
			else if (durum[i][j] == 1)
				printf("[%3d  ] ", kartlar[i][j]);
			else
				printf("[  -  ] ");
		}
		printf("\n");
	}
	printf("\n");

	if (sira == 0)
		printf("Oyun sirasi:Oyuncu\n");
	else
		printf("Oyun sirasi:Bilgisayar\n");

	/*printf("Bilgisayar hafizasi: ");

	for (int k = 0; k < hafizaKartSayi; k++)
	{
		printf("%d ", Hafiza[k].sayi);
	}
	printf("\n");*/

}

void hafizadanCikar(struct Veri* veri) {
	
	int i, j;
	for (i = 0; i < hafizaKartSayi; i++)
	{
		if (Hafiza[i].i == veri->i && Hafiza[i].j == veri->j && Hafiza[i].sayi == veri->sayi)
		{
			for (j = i + 1; j < hafizaKartSayi; j++)
			{
				Hafiza[j - 1] = Hafiza[j];
			}
			Hafiza[hafizaKartSayi - 1].sayi = 0;
			Hafiza[hafizaKartSayi - 1].i = -1;
			Hafiza[hafizaKartSayi - 1].j = -1;
			hafizaKartSayi--;
			break;
		}
	}
}

void hafizayaAl(struct Veri* veri) {
	
	int i;
	for (i = 0; i < hafizaKartSayi; i++)
	{
		if (Hafiza[i].i == veri->i && Hafiza[i].j == veri->j)
			return;
	}

	if (hafizaKartSayi < hafiza)
	{
		Hafiza[hafizaKartSayi] = *veri;
		hafizaKartSayi++;
		return;
	}

	for (i = 1; i < hafiza; i++)
	{
		Hafiza[i - 1] = Hafiza[i];
	}
	Hafiza[hafiza - 1] = *veri;
}

void degerlendir()
{
	struct Veri birinciAcikKart;
	birinciAcikKart.sayi = 0;
	
	int i, j;
	for (i = 0; i < boyut; i++)
	{
		for (j = 0; j < boyut; j++)
		{
			if (durum[i][j] == 1)
			{
				if (birinciAcikKart.sayi == 0)
				{
					birinciAcikKart.i = i;
					birinciAcikKart.j = j;
					birinciAcikKart.sayi = kartlar[i][j];
				}
				else
				{

					struct Veri ikinciAcikKart;
					ikinciAcikKart.i = i;
					ikinciAcikKart.j = j;
					ikinciAcikKart.sayi = kartlar[i][j];

					if (birinciAcikKart.sayi == kartlar[i][j])
					{
						durum[i][j] = 2;
						durum[birinciAcikKart.i][birinciAcikKart.j] = 2;
						if (sira == 0)
							oyuncuPuan++;
						else
							bilgisayarPuan++;
						hafizadanCikar(&birinciAcikKart);
						hafizadanCikar(&ikinciAcikKart);
					}
					else
					{
						durum[i][j] = 0;
						durum[birinciAcikKart.i][birinciAcikKart.j] = 0;
						sira = (sira + 1) % 2;//sira deðiþtir
					}
				}

			}
		}
	}
}

void kartiAc(int x, int y)
{
	struct Veri veri;
	veri.i = x;
	veri.j = y;
	veri.sayi = kartlar[x][y];
	durum[x][y] = 1;
	kartlariYazdir();
	Sleep(2000);
	degerlendir();
	if(durum[veri.i][veri.j] != 2)
		hafizayaAl(&veri);
	kartlariYazdir();
}

struct Veri bilgisayarTahmin(int tahminSayisi) {
	//Hafizadfaki deðerlerden ayný deðere sahip iki veri var mý varsa bunlarý söyle
	int i, j;
	for (i = 0; i < hafizaKartSayi; i++)
	{
		struct Veri kart1 = Hafiza[i];
		for (j = i + 1; j < hafizaKartSayi; j++)
		{
			struct Veri kart2 = Hafiza[j];
			if (kart1.sayi == kart2.sayi && (kart1.i != kart2.i || kart1.j != kart2.j))
			{
				if (tahminSayisi == 1 && durum[kart1.i][kart1.j] == 0)
					return kart1;
				else if (tahminSayisi == 2 && durum[kart2.i][kart2.j] == 0)
					return kart2;
			}
		}
	}

	//Hafýzadaki son deðeri söyle ve bir rastgele sayi söyle
	if (tahminSayisi == 1 && hafizaKartSayi > 0 && durum[Hafiza[hafizaKartSayi - 1].i][Hafiza[hafizaKartSayi - 1].j] == 0)
	{
		return Hafiza[hafizaKartSayi - 1];
	}
	else if (tahminSayisi == 2 || hafizaKartSayi == 0)
	{
		srand(time(NULL));
		int x, y;
		do {
			x = rand() % boyut;
			y = rand() % boyut;
		} while (durum[x][y] != 0);
		struct Veri veri;
		veri.i = x;
		veri.j = y;
		return veri;
	}
}

void TahminGir(int tahminSayisi)
{
	int x, y, i, j;
	do
	{
		printf("Tahmin icin %d. kordinati girin (x,y):",tahminSayisi);
		if (sira == 0) {
			scanf("%d,%d", &i, &j);

			x = i - 1;
			y = j - 1;
			printf(" = %d\n", kartlar[x][y]);
			oyuncuHamle++;
		}
		else {
			struct Veri veri = bilgisayarTahmin(tahminSayisi);
			x = veri.i;
			y = veri.j;
			printf("%d,%d = %d\n", x + 1, y + 1, kartlar[x][y]);
			bilgisayarHamle++;
		}
		Sleep(2000);
		if (durum[x][y] != 0)
			printf("Bu kart zaten acilmis\n");
	} while (durum[x][y] != 0);

	kartiAc(x, y);
}


int main()
{
	seviyeSor();
	boyutBelirle();
	sayilariDoldur();
	kartlariYazdir();
	int fark = ((boyut * boyut) / 4) + 1;
	while (abs(bilgisayarPuan - oyuncuPuan) < fark)
	{
		TahminGir(1);
		TahminGir(2);
	}
	if (bilgisayarPuan - oyuncuPuan > 0)
		printf("\nDurum:BILGISAYAR Kazandi Hamle sayisi:%d",bilgisayarHamle);
	else if (bilgisayarPuan - oyuncuPuan < 0)
		printf("\nDurum:OYUNCU Kazandi Hamle sayisi:%d",oyuncuHamle);
	else
		printf("\nDurum:BERABERE");
	return 0;
}
