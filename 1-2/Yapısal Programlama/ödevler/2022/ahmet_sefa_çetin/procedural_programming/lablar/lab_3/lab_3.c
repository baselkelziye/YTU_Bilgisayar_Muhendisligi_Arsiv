#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int urunKodu;
    char urunAdi[20];
    double birimSatisFiyati;
    double kiloSatisFiyati;
} URUN;

void listele(URUN urunler[]);
double alisverisTutari(URUN urunler[], int urunKodu, int alisTipi, int miktar);
double indirimliTutar(double toplamTutar);

int main() {
    int i, urunKodu, alisTipi, miktar;
    double toplamTutar = 0;
    char devam;

    URUN urunler[6];

    urunler[0].urunKodu = 1;
    strcpy(urunler[0].urunAdi, "domates");
    urunler[0].birimSatisFiyati = 8.25;
    urunler[0].kiloSatisFiyati = 23.75;

    urunler[1].urunKodu = 2;
    strcpy(urunler[1].urunAdi, "biber");
    urunler[1].birimSatisFiyati = 6.25;
    urunler[1].kiloSatisFiyati = 29.50;

    urunler[2].urunKodu = 3;
    strcpy(urunler[2].urunAdi, "süt");
    urunler[2].birimSatisFiyati = 15.85;
    urunler[2].kiloSatisFiyati = 27.15;

    urunler[3].urunKodu = 4;
    strcpy(urunler[3].urunAdi, "peynir");
    urunler[3].birimSatisFiyati = 23;
    urunler[3].kiloSatisFiyati = 95.5;

    urunler[4].urunKodu = 5;
    strcpy(urunler[4].urunAdi, "muz");
    urunler[4].birimSatisFiyati = 13.45;
    urunler[4].kiloSatisFiyati = 45.50;

    urunler[5].urunKodu = 6;
    strcpy(urunler[5].urunAdi, "armut");
    urunler[5].birimSatisFiyati = 5.50;
    urunler[5].kiloSatisFiyati = 20.15;

    do {
        printf("\n");
        listele(urunler);

        do {
            printf("Urun kodu giriniz: ");
            scanf("%d", &urunKodu);
        } while (urunKodu > 6 || urunKodu < 1);

        do {
            printf("Alis tipi (1: birim, 2: kilo): ");
            scanf("%d", &alisTipi);
        } while (alisTipi != 1 && alisTipi != 2);

        printf("miktar giriniz: ");
        scanf("%d", &miktar);

        toplamTutar += alisverisTutari(urunler, urunKodu, alisTipi, miktar);
        printf("Toplam tutar: %f", toplamTutar);

        printf("\ndevam etmek istiyor musunuz(E/H): ");
        scanf(" %c", &devam);
    } while (devam == 'e' || devam == 'E');

    printf("\ntoplam tutar: %f", toplamTutar);
    printf("\nindirimli tutar: %f", indirimliTutar(toplamTutar));

    printf("\nprogramdan çikiş yapiliyor");

    return 0;
}

void listele(URUN urunler[]) {
    int i;

    printf("Kod\tUrun Adi\tBirim Fiyat\tKilo Fiyat\n");

    for (i = 0; i < 6; i++) {
        printf("%d\t%s\t\t%f\t%f\n", urunler[i].urunKodu, urunler[i].urunAdi, urunler[i].birimSatisFiyati, urunler[i].kiloSatisFiyati);
    }
    printf("\n");
}

double alisverisTutari(URUN urunler[], int urunKodu, int alisTipi, int miktar) {
    int i;

    if (alisTipi == 1) {
        return urunler[urunKodu - 1].birimSatisFiyati * miktar;
    }
    return urunler[urunKodu - 1].kiloSatisFiyati * miktar;
}

double indirimliTutar(double toplamTutar) {
    if (toplamTutar >= 50 && toplamTutar < 100) {
        return toplamTutar * 0.95;
    } else if (toplamTutar > 100) {
        return toplamTutar * 0.9;
    } else
        return toplamTutar;
}