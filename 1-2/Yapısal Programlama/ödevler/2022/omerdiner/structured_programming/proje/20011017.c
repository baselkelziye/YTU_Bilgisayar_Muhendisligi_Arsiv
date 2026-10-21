#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char ogrID[9];
    char ad[30];
    char soyad[30];
    int puan;
    struct Ogrenci *next;
    struct Ogrenci *prev;
} Ogrenci;
typedef struct
{
    int yazarID;
    char yazarAd[30];
    char yazarSoyad[30];
    struct Yazar *next;
} Yazar;
typedef struct
{
    char EtiketNo[20];
    char Durum[9];
    struct KitapOrnek *next;
} KitapOrnek;
typedef struct
{
    char kitapAdi[30];
    char ISBN[13];
    int adet;
    struct Kitap *next;
    struct KitapOrnek *head;
} Kitap;
typedef struct
{
    char ISBN[13];
    int YazarID;
} KitapYazar;
typedef struct
{
    unsigned int gun : 5;
    unsigned int ay : 4;
    unsigned int yil : 12;
} Tarih;
typedef struct
{
    char EtiketNo[20];
    char ogrID[9];
    unsigned int islemTipi : 1;
    Tarih islemTarihi;
    struct KitapOdunc *next;
} KitapOdunc;
void menuyuYazdir();
Ogrenci *ogrenciIdAra(char *ogrenciId);
Kitap *kitapAdiAra(char *kitapAdi);

void yazarlariOku(Yazar **yazarHead);
void yazarlariCSVyeYazdir(Yazar *yazarHead);
void yazarlariYazdir(Yazar *yazarHead);
void yazarGuncelle(Yazar **yazarHead);
int yazarSil(Yazar **yazarHead);
void yazarEkle(Yazar **yazarHead);
void ogrencileriYazdir(Ogrenci *ogrenciHead);
void ogrencileriOku(Ogrenci **ogrenciHead);
void ogrencileriCSVyeYaz(Ogrenci *ogrenciHead);
void ogrenciSilId(Ogrenci **ogrenciHead);
void ogrenciSilIsim(Ogrenci **ogrenciHead);
void ogrenciGuncelle(Ogrenci **ogrenciHead);
void ogrenciEkle(Ogrenci **ogrenciHead);
void kitaplariOku(Kitap **kitapHead);
void kitaplariYazdir(Kitap *kitapHead);
void kitapEkle(Kitap **kitapHead);
void kitapSil(Kitap **kitapHead);
void kitapGuncelle(Kitap **kitapHead);
void kitaplariCSVyeYazdir(Kitap *kitapHead);
void freeKitaplar(Kitap *kitapHead);
void freeYazarlar(Yazar *yazarHead);
void freeOgrenciler(Ogrenci *ogrenciHead);
void freeKitapOdunc(KitapOdunc *kitapOduncHead);
void freeKitapYazarDinamik(KitapYazar *kitapYazarDinamik);
void kitapOrnekleriOlustur(Kitap **kitapHead);
void kitapOrnekleriniYazdir(Kitap *kitapHead);
void kitapOduncuYazdir(KitapOdunc *head);
void kitapOduncuOku(KitapOdunc **kitapOduncHead);
void kitapOrnegiOdunceGoreGuncelle(Kitap **kitapHead, KitapOdunc **kitapOduncHead);
void kitapAdinaGoreKitapOrnekleriniYazdir(Kitap **kitapHead);
void raftaOlanKitaplariYaz(Kitap **kitapHead);
void kitapOduncuCSVyeYazdir(KitapOdunc *kitapOduncHead);
void kitapYazarlariYazdir(KitapYazar *kitapYazarArray, int kitapYazarSayisi);
KitapYazar *kitapYazarlariOku(int *kitapYazarSayisi);
void kitapYazarlariCSVyeYazdir(KitapYazar *kitapYazarArray, int kitapYazarSayisi);
void yazarSilinceKitapYazariGuncelle(KitapYazar *kitapYazarArray, int kitapYazarSayisi, int yazarId);
void kitapYazarEkle(KitapYazar **kitapYazarArray, int *kitapYazarSayisi, Kitap *kitapHead, Yazar *yazarHead);
void kitapYazarGuncelle(KitapYazar **kitapYazarArray, int kitapYazarSayisi, Kitap *kitapHead, Yazar *yazarHead);
Kitap *kitapAra(Kitap *kitapHead, char *kitapAdi);
Yazar *yazarAra(Yazar *yazarHead, char *yazarAdi, char *yazarSoyadi);
Tarih tarihStringdenTarihStructa(char *tarihString);
void kitapOduncAl(Kitap **kitapHead, KitapOdunc **kitapOduncHead, Ogrenci **ogrenciHead);
void cezaliOgrencileriYazdir(Ogrenci **ogrenciHead);
void zamanindaTeslimEdilmeyenKitaplariYaz(KitapOdunc **kitapOduncHead);
void kitapOduncEkle(KitapOdunc **kitapOduncHead, char *ogrenciId, char *kitapISBN, int tip, Tarih tarih);
int gunFarki(Tarih tarih1, Tarih tarih2);
void kitapTeslimAl(Kitap **kitapHead, KitapOdunc **kitapOduncHead, Ogrenci **ogrenciHead);
Tarih kitapOduncGunGetir(KitapOdunc *kitapOduncHead, char *etiketNo);
int kitapTeslimEdilmisMi(char *ogrID, char *etiketNo, KitapOdunc **kitapOduncHead);
void kitapTeslimEdilmemisleriYazdir(KitapOdunc **kitapOduncHead, Kitap **kitapHead, Ogrenci **ogrenciHead);
Ogrenci *ogrenciBul(Ogrenci **ogrenciHead, char *ogrID);
void ogrenciIcinKitapOduncuYaz(KitapOdunc **head, char *ogrenciId);
void ogrenciBilgisiYazdir(Ogrenci **ogrenciHead, KitapOdunc **kitapOduncHead);
void kitapTemelBilgisiYaz(Kitap *kitap);
Kitap *kitapBul(Kitap **kitapHead, char *ISBN);
void yazarinKitaplariniYazdir(KitapYazar *kitapYazarDinamik, int kitapYazarSayisi, Kitap **kitapHead, int yazarID);
void yazarBilgisiGoruntule(Yazar **yazarHead, KitapYazar *kitapYazarDinamik, Kitap **kitapHead, int kitapYazarSayisi);

void inputuTemizle();

int main()
{
    int kitapYazarSayisi = 0;
    Yazar *yazarHead = NULL;
    Ogrenci *ogrenciHead = NULL;
    Kitap *kitapHead = NULL;
    // KitapYazar *kitapYazarHead = NULL;
    KitapOdunc *kitapOduncHead = NULL;
    KitapYazar *kitapYazarDinamik = kitapYazarlariOku(&kitapYazarSayisi);
    yazarlariOku(&yazarHead);
    ogrencileriOku(&ogrenciHead);
    kitaplariOku(&kitapHead);
    kitapOrnekleriOlustur(&kitapHead);
    kitapOduncuOku(&kitapOduncHead);
    kitapOrnegiOdunceGoreGuncelle(&kitapHead, &kitapOduncHead);
    int silinenId = -1;
    int secim = -1;
    int icsecim = -1;
    int silmeSecim = -1;
    while (secim != 0)
    {

        menuyuYazdir();
        printf("Seciminizi giriniz: ");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:
            printf("1- Ekle\n2- Sil\n3- Guncelle\n0. Ana Menu\n");
            printf("Seciminizi giriniz:");
            scanf("%d", &icsecim);
            inputuTemizle();
            switch (icsecim)
            {
            case 1:
                ogrenciEkle(&ogrenciHead);
                ogrencileriCSVyeYaz(ogrenciHead);
                break;
            case 2:

                silmeSecim = -1;
                printf("1- ID ile sil\n2- Ad ve Soyad ile sil\n");
                printf("Seciminizi giriniz:");
                scanf("%d", &silmeSecim);
                switch (silmeSecim)
                {
                case 1:
                    ogrenciSilId(&ogrenciHead);
                    ogrencileriCSVyeYaz(ogrenciHead);
                    break;
                case 2:
                    ogrenciSilIsim(&ogrenciHead);
                    ogrencileriCSVyeYaz(ogrenciHead);
                    break;
                default:
                    printf("Yanlis secim yaptiniz!");
                    break;
                }
                break;
            case 3:
                ogrenciGuncelle(&ogrenciHead);
                ogrencileriCSVyeYaz(ogrenciHead);
                break;
            case 0:
                printf("Ana Menuye donuluyor...");
                break;

            default:
                break;
            }
            break;
        case 2:
            ogrenciBilgisiYazdir(&ogrenciHead, &kitapOduncHead);
            break;
        case 3:
            kitapTeslimEdilmemisleriYazdir(&kitapOduncHead, &kitapHead, &ogrenciHead);
            break;
        case 4:
            cezaliOgrencileriYazdir(&ogrenciHead);
            break;
        case 5:
            ogrencileriYazdir(ogrenciHead);
            break;
        case 6:
            printf("Odunc almak icin 1, teslim etmek icin 2 :");
            scanf("%d", &icsecim);
            inputuTemizle();
            switch (icsecim)
            {
            case 1:
                // kitapOduncuYazdir(kitapOduncHead);
                // printf("\n");
                kitapOduncAl(&kitapHead, &kitapOduncHead, &ogrenciHead);
                kitapOduncuCSVyeYazdir(kitapOduncHead);
                // printf("\n");
                // kitapOduncuYazdir(kitapOduncHead);
                break;
            case 2:
                // kitapOrnekleriniYazdir(kitapHead);
                kitapTeslimAl(&kitapHead, &kitapOduncHead, &ogrenciHead);
                // printf("\n");
                // kitapOduncuYazdir(kitapOduncHead);
                kitapOduncuCSVyeYazdir(kitapOduncHead);
                ogrencileriCSVyeYaz(ogrenciHead);
                break;
            default:
                printf("Yanlis secim yaptiniz!");
                break;
            }
            break;
        case 7:
            printf("1- Ekle\n2- Sil\n3- Guncelle\n0. Ana Menu\n");
            printf("Seciminizi giriniz:");
            scanf("%d", &icsecim);
            inputuTemizle();
            switch (icsecim)
            {
            case 1:
                kitapEkle(&kitapHead);
                kitaplariCSVyeYazdir(kitapHead);
                kitapOrnekleriOlustur(&kitapHead);
                kitapOrnegiOdunceGoreGuncelle(&kitapHead, &kitapOduncHead);
                break;
            case 2:
                kitapSil(&kitapHead);
                kitaplariCSVyeYazdir(kitapHead);
                kitapOrnekleriOlustur(&kitapHead);
                kitapOrnegiOdunceGoreGuncelle(&kitapHead, &kitapOduncHead);
                break;
            case 3:
                kitapGuncelle(&kitapHead);
                kitaplariCSVyeYazdir(kitapHead);
                kitapOrnekleriOlustur(&kitapHead);
                kitapOrnegiOdunceGoreGuncelle(&kitapHead, &kitapOduncHead);
                break;
            case 0:
                printf("Ana Menuye donuluyor...");
                break;
            default:
                break;
            }

            break;
        case 8:
            inputuTemizle();
            kitapAdinaGoreKitapOrnekleriniYazdir(&kitapHead);
            break;
        case 9:
            raftaOlanKitaplariYaz(&kitapHead);
            break;
        case 10:
            zamanindaTeslimEdilmeyenKitaplariYaz(&kitapOduncHead);
            break;
        case 11:
            inputuTemizle();
            kitapYazarEkle(&kitapYazarDinamik, &kitapYazarSayisi, kitapHead, yazarHead);
            // kitapYazarlariYazdir(kitapYazarDinamik, kitapYazarSayisi);
            kitapYazarlariCSVyeYazdir(kitapYazarDinamik, kitapYazarSayisi);
            break;

            break;
        case 12:
            inputuTemizle();
            kitapYazarGuncelle(&kitapYazarDinamik, kitapYazarSayisi, kitapHead, yazarHead);
            // kitapYazarlariYazdir(kitapYazarDinamik, kitapYazarSayisi);
            kitapYazarlariCSVyeYazdir(kitapYazarDinamik, kitapYazarSayisi);
            break;
        case 13:
            printf("1- Ekle\n2- Sil\n3- Guncelle\n0. Ana Menu\n");
            scanf("%d", &icsecim);
            switch (icsecim)
            {
            case 1:
                yazarEkle(&yazarHead);
                yazarlariCSVyeYazdir(yazarHead);
                break;
            case 2:
                silinenId = yazarSil(&yazarHead);
                yazarSilinceKitapYazariGuncelle(&kitapYazarDinamik, kitapYazarSayisi, silinenId);
                kitapYazarlariCSVyeYazdir(kitapYazarDinamik, kitapYazarSayisi);
                yazarlariCSVyeYazdir(yazarHead);
                break;
            case 3:

                yazarGuncelle(&yazarHead);
                yazarlariCSVyeYazdir(yazarHead);
                break;
            case 0:
                printf("Ana Menuye donuluyor...");
                break;

            default:
                break;
            }
            break;
            break;
        case 14:
            yazarBilgisiGoruntule(&yazarHead, kitapYazarDinamik, &kitapHead, kitapYazarSayisi);
            break;

        case 0:
            printf("Programdan cikiliyor...");
            break;

        default:
            break;
        }
    }

    freeKitaplar(kitapHead);
    freeOgrenciler(ogrenciHead);
    freeYazarlar(yazarHead);
    freeKitapOdunc(kitapOduncHead);
    freeKitapYazarDinamik(kitapYazarDinamik);

    return 0;
}
void freeKitapYazarDinamik(KitapYazar *kitapYazarDinamik)
{

    free(kitapYazarDinamik);
}

void freeKitapOdunc(KitapOdunc *kitapOduncHead)
{
    KitapOdunc *temp = kitapOduncHead;
    while (temp != NULL)
    {
        KitapOdunc *temp2 = temp;
        temp = temp->next;
        free(temp2);
    }
}
void zamanindaTeslimEdilmeyenKitaplariYaz(KitapOdunc **kitapOduncHead)
{

    KitapOdunc *tmp = *kitapOduncHead;
    KitapOdunc *gezici = NULL;
    while (tmp != NULL)
    {

        if (tmp->islemTipi == 1)
        {
            Tarih tarih = tmp->islemTarihi;
            gezici = *kitapOduncHead;
            int gunfarki = gunFarki(tarih, kitapOduncGunGetir(gezici,
                                                              tmp->EtiketNo));

            if (gunfarki > 15)
            {

                printf("%s ISBN'li kitap zamaninda teslim edilmedi!!\n", tmp->EtiketNo);
            }
        }
        tmp = tmp->next;
    }
}

void yazarBilgisiGoruntule(Yazar **yazarHead, KitapYazar *kitapYazarDinamik, Kitap **kitapHead, int kitapYazarSayisi)
{
    char yazarAdi[30];
    char yazarSoyadi[30];
    printf("Yazar Adi:");
    scanf("%s", yazarAdi);
    printf("Yazar Soyadi:");
    scanf("%s", yazarSoyadi);
    Yazar *yazar = yazarAra(*yazarHead, yazarAdi, yazarSoyadi);
    if (yazar == NULL)
    {
        printf("Yazar Bulunamadi!\n");
    }
    else
    {
        printf("Yazar Adi: %s  Soyadi: %s  ID: %d\n", yazar->yazarAd, yazar->yazarSoyad, yazar->yazarID);
        printf("Yazara ait kitaplar:\n");
        yazarinKitaplariniYazdir(kitapYazarDinamik, kitapYazarSayisi, kitapHead, yazar->yazarID);
    }
}
void yazarinKitaplariniYazdir(KitapYazar *kitapYazarDinamik, int kitapYazarSayisi, Kitap **kitapHead, int yazarID)
{

    Kitap *kitap = NULL;

    int i;
    for (i = 0; i < kitapYazarSayisi; i++)
    {

        if (kitapYazarDinamik[i].YazarID == yazarID)
        {

            kitap = kitapBul(kitapHead, kitapYazarDinamik[i].ISBN);
            kitapTemelBilgisiYaz(kitap);
        }
    }
}
Kitap *kitapBul(Kitap **kitapHead, char *ISBN)
{
    Kitap *temp = *kitapHead;
    while (temp != NULL)
    {
        if (strcmp(temp->ISBN, ISBN) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void kitapTemelBilgisiYaz(Kitap *kitap)
{
    printf("Kitap Adi: %s\tKitap ISBN: %s\tKitap Adedi: %d\n", kitap->kitapAdi, kitap->ISBN, kitap->adet);
}

void kitapTeslimEdilmemisleriYazdir(KitapOdunc **kitapOduncHead, Kitap **kitapHead, Ogrenci **ogrenciHead)
{
    printf("TESLIM ETMEYENLER:\n");
    KitapOdunc *temp = *kitapOduncHead;
    while (temp != NULL)
    {
        if (temp->islemTipi == 0)
        {

            if (kitapTeslimEdilmisMi(temp->ogrID, temp->EtiketNo, kitapOduncHead) == 0)
            {

                Ogrenci *ogrenci = ogrenciBul(ogrenciHead, temp->ogrID);

                printf("Ogrenci ID: %s\tOgrenci Adi: %s\tOgrenci Soyadi: %s\n", ogrenci->ogrID, ogrenci->ad, ogrenci->soyad);
            }
        }
        temp = temp->next;
    }
}
Ogrenci *ogrenciBul(Ogrenci **ogrenciHead, char *ogrID)
{
    Ogrenci *temp = *ogrenciHead;
    while (temp != NULL)
    {
        if (strcmp(temp->ogrID, ogrID) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void ogrenciBilgisiYazdir(Ogrenci **ogrenciHead, KitapOdunc **kitapOduncHead)
{
    int secim;
    printf("1-Id ile \n2-Ad ve soyad ile \n");
    printf("Seciminiz: ");
    scanf("%d", &secim);
    inputuTemizle();
    if (secim == 1)
    {
        char ogrID[9];
        printf("Ogrencinin ID'sini giriniz:");
        scanf("%s", ogrID);

        Ogrenci *temp = ogrenciBul(ogrenciHead, ogrID);

        if (temp != NULL)
        {

            printf("%s %s %s %d\n", ogrID, temp->ad, temp->soyad, temp->puan);
            ogrenciIcinKitapOduncuYaz(kitapOduncHead, ogrID);
            return;
        }
        else
        {
            printf("Ogrenci bulunamadi\n");
            return;
        }
    }
    else if (secim == 2)
    {
        char ad[30];
        char soyad[30];
        printf("Ad giriniz:");
        scanf("%s", ad);
        printf("Soyad giriniz:");
        scanf("%s", soyad);
        Ogrenci *temp = *ogrenciHead;
        int bulundu = 0;
        while (temp != NULL)
        {
            if (strcmp(temp->ad, ad) == 0 && strcmp(temp->soyad, soyad) == 0 && bulundu == 0)
            {
                bulundu = 1;
                printf("%s %s %s %d\n", temp->ogrID, temp->ad, temp->soyad, temp->puan);
                ogrenciIcinKitapOduncuYaz(kitapOduncHead, temp->ogrID);
                return;
            }
            temp = temp->next;
        }
        if (bulundu == 0)
        {
            printf("Ogrenci bulunamadi\n");
        }
    }
    else
    {
        printf("Hatali secim");
    }
}
void ogrenciIcinKitapOduncuYaz(KitapOdunc **head, char *ogrenciId)
{

    KitapOdunc *tmp = *head;
    while (tmp != NULL)
    {
        if (strcmp(tmp->ogrID, ogrenciId) == 0)
        {
            printf("Etiket No: %s  ", tmp->EtiketNo);
            printf("Ogrenci ID: %s  ", tmp->ogrID);
            printf("Islem Tipi: %d  ", tmp->islemTipi);
            printf("Islem Tarihi: %d/%d/%d\n", tmp->islemTarihi.gun, tmp->islemTarihi.ay, tmp->islemTarihi.yil);
        }

        tmp = tmp->next;
    }
}
int kitapTeslimEdilmisMi(char *ogrID, char *etiketNo, KitapOdunc **kitapOduncHead)
{
    KitapOdunc *temp = *kitapOduncHead;
    while (temp != NULL)
    {
        if (strcmp(temp->ogrID, ogrID) == 0 && strcmp(temp->EtiketNo, etiketNo) == 0)
        {
            if (temp->islemTipi == 1)
            {
                return 1;
            }
          
        }
        temp = temp->next;
    }
    return 0;
}

void cezaliOgrencileriYazdir(Ogrenci **ogrenciHead)
{
    printf("CEZALI OGRENCILER\n");
    Ogrenci *temp = *ogrenciHead;
    while (temp != NULL)
    {
        if (temp->puan < 100)
        {
            printf("Ogrenci id: %s  Ad-Soyad: %s-%s  Puan: %d\n", temp->ogrID, temp->ad, temp->soyad, temp->puan);
        }
        temp = temp->next;
    }
}

void kitapOduncAl(Kitap **kitapHead, KitapOdunc **kitapOduncHead, Ogrenci **ogrenciHead)
{
    Kitap *kitap = *kitapHead;
    KitapOrnek *kitapOrnek = NULL;
    char ogrenciId[9];
    char kitapAdi[30];
    char oduncISBN[30];
    int i;
    Tarih tarih;

    printf("Ogrenci id giriniz:");
    scanf("%s", ogrenciId);
    inputuTemizle();
    printf("Kitap adi giriniz:");
    gets(kitapAdi);
    Kitap *istenen = NULL;
    int kitapvarmi = 0;

    while (kitap != NULL && kitapvarmi == 0)
    {
        if (strcmp(kitap->kitapAdi, kitapAdi) == 0)
        {
            istenen = kitap;
            kitapvarmi = 1;
        }
        kitap = kitap->next;
    }
    if (kitapvarmi == 0)
    {
        printf("Kitap bulunamadi\n");
        return;
    }
    Ogrenci *isteyen = ogrenciIdAra(ogrenciId);
    if (isteyen == NULL)
    {
        printf("Ogrenci bulunamadi\n");
        return;
    }
    if (isteyen->puan < 0)
    {
        printf("Ogrenci puani negatif , kitap verilemez.\n");
        return;
    }

    int tarihtmp;

    printf("Gun:");
    scanf("%d", &tarihtmp);
    tarih.gun = tarihtmp;

    printf("Ay:");
    scanf("%d", &tarihtmp);
    tarih.ay = tarihtmp;

    printf("Yil:");
    scanf("%d", &tarihtmp);
    tarih.yil = tarihtmp;
    // inputuTemizle();
    kitapOrnek = istenen->head;
    while (kitapOrnek != NULL)
    {
        if (strcmp(kitapOrnek->Durum, "Rafta") == 0)
        {
            strcpy(kitapOrnek->Durum, isteyen->ogrID);
            kitapOduncEkle(kitapOduncHead, kitapOrnek->EtiketNo, isteyen->ogrID, 0, tarih);
            return;
        }
        kitapOrnek = kitapOrnek->next;
    }
    printf("Kitabin rafta olan kopyasi yok.\n");
}

void kitapTeslimAl(Kitap **kitapHead, KitapOdunc **kitapOduncHead, Ogrenci **ogrenciHead)
{
    Kitap *kitap = *kitapHead;
    KitapOrnek *kitapOrnek = NULL;
    char ogrenciId[9];
    char kitapAdi[30];
    char oduncISBN[30];
    int i;
    Tarih tarih;

    printf("Ogrenci id giriniz:");
    scanf("%s", ogrenciId);
    inputuTemizle();
    printf("Kitap adi giriniz:");
    gets(kitapAdi);
    Kitap *istenen = NULL;
    int kitapvarmi = 0;

    while (kitap != NULL && kitapvarmi == 0)
    {
        if (strcmp(kitap->kitapAdi, kitapAdi) == 0)
        {
            istenen = kitap;
            kitapvarmi = 1;
        }
        kitap = kitap->next;
    }
    if (kitapvarmi == 0)
    {
        printf("Kitap bulunamadi\n");
        return;
    }
    Ogrenci *isteyen = ogrenciIdAra(ogrenciId);
    if (isteyen == NULL)
    {
        printf("Ogrenci bulunamadi\n");
        return;
    }

    int tarihtmp;

    printf("Gun:");
    scanf("%d", &tarihtmp);
    tarih.gun = tarihtmp;

    printf("Ay:");
    scanf("%d", &tarihtmp);
    tarih.ay = tarihtmp;

    printf("Yil:");
    scanf("%d", &tarihtmp);
    tarih.yil = tarihtmp;
    // inputuTemizle();
    kitapOrnek = istenen->head;
    while (kitapOrnek != NULL)
    {
       // printf("Kitap adi:%s Kitap isbn %s Kitap ornek durumu:%s ogrenci id %s \n", istenen->kitapAdi, kitapOrnek->EtiketNo, kitapOrnek->Durum, ogrenciId);

        if (strcmp(kitapOrnek->Durum, ogrenciId) == 0)
        {
            strcpy(kitapOrnek->Durum, "Rafta");
            int gunfarki = gunFarki(tarih, kitapOduncGunGetir(*kitapOduncHead,
                                                              kitapOrnek->EtiketNo));
            if (gunfarki > 15)
            {
                isteyen->puan -= 10;
                printf("Teslim tarihi geciktigi icin ogrenciye -10 puan ceza eklendi.\n");
            }

            kitapOduncEkle(kitapOduncHead, kitapOrnek->EtiketNo, isteyen->ogrID, 1, tarih);
            return;
        }
        kitapOrnek = kitapOrnek->next;
    }
    printf("Ogrenci ile kitap eslesmemis.\n");
}

Tarih kitapOduncGunGetir(KitapOdunc *kitapOduncHead, char *etiketNo)
{
    KitapOdunc *kitapOdunc = kitapOduncHead;
    while (kitapOdunc != NULL)
    {
        if (strcmp(kitapOdunc->EtiketNo, etiketNo) == 0&&kitapOdunc->islemTipi==0)
        {
            return kitapOdunc->islemTarihi;
        }
        kitapOdunc = kitapOdunc->next;
    }
    Tarih tarih;
    tarih.gun = 0;
    tarih.ay = 0;
    tarih.yil = 0;
    return tarih;
}
int gunFarki(Tarih tarih1, Tarih tarih2)
{
	if(tarih2.ay==0&&tarih2.gun==0&&tarih2.yil==0)
	return 0;
    int gun_farki = 0;

    if (tarih2.yil != tarih1.yil)
    {
        int yil_farki = tarih1.yil - tarih2.yil;
        gun_farki += yil_farki * 365;
    }

    if (tarih2.ay != tarih1.ay)
    {
        int ay_farki = tarih1.ay - tarih2.ay;
        gun_farki += ay_farki * 30;
    }

    gun_farki += tarih1.gun - tarih2.gun;

    return gun_farki;
}

Ogrenci *ogrenciIdAra(char *ogrenciId)
{
    Ogrenci *ogrenci = NULL;
    ogrencileriOku(&ogrenci);

    while (ogrenci != NULL)
    {
        if (strcmp(ogrenci->ogrID, ogrenciId) == 0)
        {
            return ogrenci;
        }
        ogrenci = ogrenci->next;
    }
    return NULL;
}
Kitap *kitapAdiAra(char *kitapAdi)
{
    Kitap *kitap = NULL;
    kitaplariOku(&kitap);

    while (kitap != NULL)
    {
        if (strcmp(kitap->kitapAdi, kitapAdi) == 0)
        {
            return kitap;
        }
        kitap = kitap->next;
    }
    return NULL;
}

void kitapOduncEkle(KitapOdunc **kitapOduncHead, char *kitapISBN, char *ogrenciId, int tip, Tarih tarih)
{
    KitapOdunc *kitapOdunc = *kitapOduncHead;
    KitapOdunc *yeniKitapOdunc = (KitapOdunc *)malloc(sizeof(KitapOdunc));
    strcpy(yeniKitapOdunc->ogrID, ogrenciId);
    strcpy(yeniKitapOdunc->EtiketNo, kitapISBN);
    yeniKitapOdunc->islemTipi = tip;
    yeniKitapOdunc->islemTarihi = tarih;
    yeniKitapOdunc->next = NULL;
    if (kitapOdunc == NULL)
    {
        *kitapOduncHead = yeniKitapOdunc;
    }
    else
    {
        while (kitapOdunc->next != NULL)
        {
            kitapOdunc = kitapOdunc->next;
        }
        kitapOdunc->next = yeniKitapOdunc;
    }
}

void kitapYazarGuncelle(KitapYazar **kitapYazarArray, int kitapYazarSayisi, Kitap *kitapHead, Yazar *yazarHead)
{
    int i;
    Kitap *kitap = kitapHead;
    Yazar *yazar = yazarHead;
    KitapYazar *kitapYazar = *kitapYazarArray;
    char kitapAdi[50];
    char yazarAdi[50];
    char yazarSoyadi[50];
    printf("Kitap adi giriniz:");
    gets(kitapAdi);
    printf("Yazar adi giriniz:");
    scanf("%s", yazarAdi);
    printf("Yazar soyadi giriniz:");
    scanf("%s", yazarSoyadi);
    inputuTemizle();
    kitap = kitapAra(kitapHead, kitapAdi);
    if (kitap != NULL)
    {
        yazar = yazarAra(yazarHead, yazarAdi, yazarSoyadi);
        if (yazar != NULL)
        {
            for (i = 0; i < kitapYazarSayisi; i++)
            {
                if (strcmp(kitapYazar[i].ISBN, kitap->ISBN) == 0)
                {
                    kitapYazar[i].YazarID = yazar->yazarID;
                    printf("Kitap yazar guncellendi...\n");
                    break;
                }
            }
        }
        else
        {
            printf("Yazar bulunamadi...\n");
        }
    }
    else
    {
        printf("Kitap bulunamadi...\n");
    }
}
Kitap *kitapAra(Kitap *kitapHead, char *kitapAdi)
{
    Kitap *kitap = kitapHead;
    while (kitap != NULL)
    {
        if (strcmp(kitap->kitapAdi, kitapAdi) == 0)
        {
            return kitap;
        }
        kitap = kitap->next;
    }
    return NULL;
}
Yazar *yazarAra(Yazar *yazarHead, char *yazarAdi, char *yazarSoyadi)
{
    Yazar *yazar = yazarHead;
    while (yazar != NULL)
    {
        if (strcmp(yazar->yazarAd, yazarAdi) == 0 && strcmp(yazar->yazarSoyad, yazarSoyadi) == 0)
        {
            return yazar;
        }
        yazar = yazar->next;
    }
    return NULL;
}

void kitapYazarEkle(KitapYazar **kitapYazarArray, int *kitapYazarSayisi, Kitap *kitapHead, Yazar *yazarHead)
{
    Kitap *kitap = kitapHead;
    Yazar *yazar = yazarHead;
    KitapYazar *kitapYazar = *kitapYazarArray;
    char kitapAdi[50];
    char yazarAdi[50];
    char yazarSoyadi[50];
    printf("Kitap adi giriniz:");
    gets(kitapAdi);
    printf("Yazar adi giriniz:");
    scanf("%s", yazarAdi);
    printf("Yazar soyadi giriniz:");
    scanf("%s", yazarSoyadi);
    while (kitap != NULL)
    {
        if (strcmp(kitap->kitapAdi, kitapAdi) == 0)
        {
            while (yazar != NULL)
            {
                if (strcmp(yazar->yazarAd, yazarAdi) == 0 && strcmp(yazar->yazarSoyad, yazarSoyadi) == 0)
                {
                    kitapYazar = realloc(kitapYazar, (*kitapYazarSayisi + 1) * sizeof(KitapYazar));
                    strcpy(kitapYazar[*kitapYazarSayisi].ISBN, kitap->ISBN);
                    kitapYazar[*kitapYazarSayisi].YazarID = yazar->yazarID;
                    (*kitapYazarSayisi)++;
                    *kitapYazarArray = kitapYazar;
                    return;
                }
                yazar = yazar->next;
            }
        }
        kitap = kitap->next;
    }
    printf("Kitap veya yazar bulunamadi!\n");
}

void yazarSilinceKitapYazariGuncelle(KitapYazar *kitapYazarArray, int kitapYazarSayisi, int yazarId)
{
    if (yazarId == -1)
        return;
    int i;
    for (i = 0; i < kitapYazarSayisi; i++)
    {
        if (kitapYazarArray[i].YazarID == yazarId)
        {
            kitapYazarArray[i].YazarID = -1;
        }
    }
}
void kitapYazarlariYazdir(KitapYazar *kitapYazarArray, int kitapYazarSayisi)
{
    int i;
    for (i = 0; i < kitapYazarSayisi; i++)
    {
        printf("%s %d \n", kitapYazarArray[i].ISBN, kitapYazarArray[i].YazarID);
    }
}
void kitapYazarlariCSVyeYazdir(KitapYazar *kitapYazarArray, int kitapYazarSayisi)
{
    FILE *kitapYazarDosya = fopen("KitapYazar.csv", "w");
    int i;
    for (i = 0; i < kitapYazarSayisi; i++)
    {
        fprintf(kitapYazarDosya, "%s, %d\n", kitapYazarArray[i].ISBN, kitapYazarArray[i].YazarID);
    }
    fclose(kitapYazarDosya);
}
KitapYazar *kitapYazarlariOku(int *kitapYazarSayisi)
{
    FILE *kitapYazarDosya = fopen("KitapYazar.csv", "r");
    char line[100];
    int i = 0;
    while (fgets(line, 100, kitapYazarDosya))
    {
        i++;
    }
    *kitapYazarSayisi = i;
    KitapYazar *kitapYazarArray = (KitapYazar *)malloc(sizeof(KitapYazar) * i);
    kitapYazarDosya = fopen("KitapYazar.csv", "r");

    i = 0;
    while (fgets(line, 100, kitapYazarDosya))
    {
        char *token = strtok(line, ",");
        strcpy(kitapYazarArray[i].ISBN, token);
        token = strtok(NULL, "\n");
        kitapYazarArray[i].YazarID = atoi(token);
        i++;
    }
    fclose(kitapYazarDosya);
    return kitapYazarArray;
}

void kitapOduncuYazdir(KitapOdunc *head)
{
    KitapOdunc *tmp = head;
    while (tmp != NULL)
    {
        printf("Etiket No: %s - ", tmp->EtiketNo);
        printf("Ogrenci ID: %s - ", tmp->ogrID);
        printf("Islem Tipi: %d - ", tmp->islemTipi);
        printf("Islem Tarihi: %d/%d/%d\n", tmp->islemTarihi.gun, tmp->islemTarihi.ay, tmp->islemTarihi.yil);
        tmp = tmp->next;
    }
}
void raftaOlanKitaplariYaz(Kitap **kitapHead)
{
    Kitap *kitap = *kitapHead;

    while (kitap != NULL)
    {
        KitapOrnek *kitapOrnek = kitap->head;
        while (kitapOrnek != NULL)
        {
            if (strcmp(kitapOrnek->Durum, "Rafta") == 0)
            {
                printf("Rafta-> ISBN:%s   Kitap Adi: %s\n", kitapOrnek->EtiketNo, kitap->kitapAdi);
            }
            kitapOrnek = kitapOrnek->next;
        }
        kitap = kitap->next;
    }
}

void kitapOrnegiOdunceGoreGuncelle(Kitap **kitapHead, KitapOdunc **kitapOduncHead)
{
    Kitap *kitap = *kitapHead;
    KitapOdunc *kitapOdunc = *kitapOduncHead;
    while (kitapOdunc != NULL)
    {
        kitap = *kitapHead;
        while (kitap != NULL)
        {
            KitapOrnek *kitapOrnek = kitap->head;
            while (kitapOrnek != NULL)
            {
                if (strcmp(kitapOrnek->EtiketNo, kitapOdunc->EtiketNo) == 0)
                {
                    if (kitapOdunc->islemTipi == 0)
                    {
                        strcpy(kitapOrnek->Durum, kitapOdunc->ogrID);
                    }
                }
                kitapOrnek = kitapOrnek->next;
            }
            kitap = kitap->next;
        }
        kitapOdunc = kitapOdunc->next;
    }
}
void kitapOduncuCSVyeYazdir(KitapOdunc *kitapOduncHead)
{
    FILE *fp = fopen("KitapOdunc.csv", "w");
    if (fp == NULL)
    {
        printf("Kitap odunc dosyasi yazmak icin acilamadi");
        exit(1);
    }
    KitapOdunc *tmp = kitapOduncHead;
    while (tmp != NULL)
    {
        fprintf(fp, "%s,%s,%d,%d/%d/%d\n", tmp->EtiketNo, tmp->ogrID, tmp->islemTipi, tmp->islemTarihi.gun, tmp->islemTarihi.ay, tmp->islemTarihi.yil);
        tmp = tmp->next;
    }
    fclose(fp);
}
void kitapOduncuOku(KitapOdunc **kitapOduncHead)
{
    FILE *fp = fopen("KitapOdunc.csv", "r");
    if (fp == NULL)
    {
        printf("Kitap odunc dosyasi okumak icin acilamadi");
        exit(1);
    }
    char buffer[100];
    KitapOdunc *kitapOdunc = NULL;
    while (fgets(buffer, 100, fp) != NULL)
    {
        kitapOdunc = (KitapOdunc *)malloc(sizeof(KitapOdunc));
        kitapOdunc->next = NULL;
        char *token = strtok(buffer, ",");
        strcpy(kitapOdunc->EtiketNo, token);
        token = strtok(NULL, ",");
        strcpy(kitapOdunc->ogrID, token);
        token = strtok(NULL, ",");
        kitapOdunc->islemTipi = atoi(token);
        token = strtok(NULL, "\n");
        kitapOdunc->islemTarihi = tarihStringdenTarihStructa(token);
        if (*kitapOduncHead == NULL)
        {
            *kitapOduncHead = kitapOdunc;
        }
        else
        {
            KitapOdunc *tmp = *kitapOduncHead;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = kitapOdunc;
        }
    }
    fclose(fp);
}

Tarih tarihStringdenTarihStructa(char *tarihString)
{
    Tarih tarih;
    char *gun = strtok(tarihString, "/");
    char *ay = strtok(NULL, "/");
    char *yil = strtok(NULL, "\n");
    tarih.gun = atoi(gun);
    tarih.ay = atoi(ay);
    tarih.yil = atoi(yil);
    return tarih;
}
void kitapAdinaGoreKitapOrnekleriniYazdir(Kitap **kitapHead)
{
    Kitap *tmp = *kitapHead;
    char kitapAdi[100];
    printf("Kitap adi giriniz:");
    gets(kitapAdi);
    while (tmp != NULL)
    {
        if (strcmp(tmp->kitapAdi, kitapAdi) == 0)
        {
            KitapOrnek *tmpOrnek = tmp->head;
            while (tmpOrnek != NULL)
            {
                printf("Kitap adi:%s Etiket No:%s Durum:%s\n", tmp->kitapAdi, tmpOrnek->EtiketNo, tmpOrnek->Durum);
                tmpOrnek = tmpOrnek->next;
            }
            printf("\n");
        }
        tmp = tmp->next;
    }
}
void kitapOrnekleriniYazdir(Kitap *kitapHead)
{
    Kitap *tmp = kitapHead;
    KitapOrnek *tmpOrnek = tmp->head;
    while (tmp != NULL)
    {
        tmpOrnek = tmp->head;
        while (tmpOrnek != NULL)
        {
            printf("Kitap adi:%s Etiket No:%s Durum:%s\n", tmp->kitapAdi, tmpOrnek->EtiketNo, tmpOrnek->Durum);
            tmpOrnek = tmpOrnek->next;
        }
        printf("\n");
        tmp = tmp->next;
    }
}

void kitapOrnekleriOlustur(Kitap **kitapHead)
{
    Kitap *tmp = *kitapHead;
    KitapOrnek *tmpOrnek;
    int i = 1;
    while (tmp != NULL)
    {
        tmp->head = (KitapOrnek *)malloc(sizeof(KitapOrnek));
        tmpOrnek = tmp->head;
        strcpy(tmpOrnek->Durum, "Rafta");
        sprintf(tmpOrnek->EtiketNo, "%s_%d", tmp->ISBN, i);
        for (i = 2; i <= tmp->adet; i++)
        {
            tmpOrnek->next = (KitapOrnek *)malloc(sizeof(KitapOrnek));
            tmpOrnek = tmpOrnek->next;
            strcpy(tmpOrnek->Durum, "Rafta");
            sprintf(tmpOrnek->EtiketNo, "%s_%d", tmp->ISBN, i);
        }
        i = 1;
        tmpOrnek->next = NULL;
        tmp = tmp->next;
    }
}
void inputuTemizle()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
void freeOgrenciler(Ogrenci *head)
{
    Ogrenci *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
void freeYazarlar(Yazar *head)
{
    Yazar *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
void freeKitaplar(Kitap *head)
{
    Kitap *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
void kitapSil(Kitap **kitapHead)
{
    int bulundu = 0;
    Kitap *tmp = *kitapHead;
    Kitap *onceki = NULL;
    char kitapAdi[30];
    printf("Silmek istediginiz kitabin adini giriniz:");
    gets(kitapAdi);

    while (tmp != NULL && bulundu == 0)
    {
        if (strcmp(tmp->kitapAdi, kitapAdi) == 0)
        {
            bulundu = 1;
            if (tmp == *kitapHead)
            {
                *kitapHead = tmp->next;
                free(tmp);
            }
            else
            {
                onceki->next = tmp->next;
                free(tmp);
            }
        }
        onceki = tmp;
        tmp = tmp->next;
    }
    if (bulundu == 0)
    {
        printf("Kitap bulunamadi!\n");
    }
    else
    {
        printf("Kitap silindi!\n");
    }
}
void kitapEkle(Kitap **kitapHead)
{
    Kitap *kitap = (Kitap *)malloc(sizeof(Kitap));
    Kitap *tmp = *kitapHead;
    Kitap *onceki = NULL;
    printf("Kitap adi:");
    gets(kitap->kitapAdi);
    printf("ISBN:");
    gets(kitap->ISBN);
    printf("Adet:");
    scanf("%d", &kitap->adet);
    inputuTemizle();
    while (tmp != NULL && strcmp(tmp->kitapAdi, kitap->kitapAdi) < 0)
    {
        onceki = tmp;
        tmp = tmp->next;
    }
    if (tmp == *kitapHead)
    {
        kitap->next = *kitapHead;
        *kitapHead = kitap;
    }
    else
    {
        onceki->next = kitap;
        kitap->next = tmp;
    }
}
void kitapGuncelle(Kitap **kitapHead)
{
    int bulundu = 0;
    Kitap *tmp = *kitapHead;
    char ISBN[30];
    printf("Guncellemek istediginiz kitabin ISBN numarasini giriniz:");
    gets(ISBN);

    while (tmp != NULL && bulundu == 0)
    {
        if (strcmp(tmp->ISBN, ISBN) == 0)
        {
            bulundu = 1;
            printf("Kitap adi:");
            gets(tmp->kitapAdi);
            printf("Adet:");
            scanf("%d", &tmp->adet);
            inputuTemizle();
        }
        tmp = tmp->next;
    }
    if (bulundu == 0)
    {
        printf("Kitap bulunamadi!\n");
    }
    else
    {
        printf("Kitap guncellendi!\n");
    }
}
void kitaplariCSVyeYazdir(Kitap *kitapHead)
{
    FILE *fp = fopen("Kitaplar.csv", "w");
    if (fp == NULL)
    {
        printf("Kitap dosyasi yazmak icin acilamadi");
        exit(1);
    }
    Kitap *temp = kitapHead;
    while (temp != NULL)
    {
        fprintf(fp, "%s,%s,%d\n", temp->kitapAdi, temp->ISBN, temp->adet);
        temp = temp->next;
    }
    fclose(fp);
}
void kitaplariYazdir(Kitap *kitapHead)
{
    Kitap *temp = kitapHead;
    while (temp != NULL)
    {
        printf("%s %s %d\n", temp->kitapAdi, temp->ISBN, temp->adet);
        temp = temp->next;
    }
}
void kitaplariOku(Kitap **kitapHead)
{
    FILE *fp = fopen("Kitaplar.csv", "r");
    if (fp == NULL)
    {
        printf("Kitap dosyasi okumak icin acilamadi");
        exit(1);
    }
    char buffer[100];
    Kitap *kitap = NULL;
    while (fgets(buffer, 100, fp) != NULL)
    {
        kitap = (Kitap *)malloc(sizeof(Kitap));
        kitap->next = NULL;
        char *token = strtok(buffer, ",");
        strcpy(kitap->kitapAdi, token);
        token = strtok(NULL, ",");
        strcpy(kitap->ISBN, token);
        token = strtok(NULL, "\n");
        kitap->adet = atoi(token);
        if (*kitapHead == NULL)
        {
            *kitapHead = kitap;
        }
        else
        {
            Kitap *temp = *kitapHead;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = kitap;
        }
    }
    fclose(fp);
}
void ogrencileriYazdir(Ogrenci *ogrenciHead)
{
    Ogrenci *ogrenci = ogrenciHead;
    while (ogrenci != NULL)
    {
        printf("%s %s %s %d\n", ogrenci->ogrID, ogrenci->ad, ogrenci->soyad, ogrenci->puan);
        ogrenci = ogrenci->next;
    }
}

void ogrencileriOku(Ogrenci **ogrenciHead)
{
    FILE *fp = fopen("Ogrenciler.csv", "r");
    if (fp == NULL)
    {
        printf("Ogrenci dosyasi okumak icin acilamadi");
        exit(1);
    }
    char buffer[100];
    Ogrenci *ogrenci = NULL;
    while (fgets(buffer, 100, fp) != NULL)
    {
        ogrenci = (Ogrenci *)malloc(sizeof(Ogrenci));
        ogrenci->next = NULL;
        char *token = strtok(buffer, ",");
        strcpy(ogrenci->ogrID, token);
        token = strtok(NULL, ",");
        strcpy(ogrenci->ad, token);
        token = strtok(NULL, ",");
        strcpy(ogrenci->soyad, token);
        token = strtok(NULL, "\n");
        ogrenci->puan = atoi(token);
        if (*ogrenciHead == NULL)
        {
            *ogrenciHead = ogrenci;
        }
        else
        {
            Ogrenci *temp = *ogrenciHead;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ogrenci;
        }
    }
    fclose(fp);
}
void ogrenciEkle(Ogrenci **ogrenciHead)
{
    Ogrenci *ogrenci = (Ogrenci *)malloc(sizeof(Ogrenci));
    ogrenci->next = NULL;
    printf("Ogrenci ID giriniz:");
    scanf("%s", ogrenci->ogrID);
    printf("Ogrenci Ad giriniz:");
    scanf("%s", ogrenci->ad);
    printf("Ogrenci Soyad giriniz:");
    scanf("%s", ogrenci->soyad);
    ogrenci->puan = 100;
    if (*ogrenciHead == NULL)
    {
        *ogrenciHead = ogrenci;
    }
    else
    {
        Ogrenci *temp = *ogrenciHead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ogrenci;
    }
}
void ogrenciSilId(Ogrenci **ogrenciHead)
{
    char ogrID[9];
    printf("Silinecek ogrencinin ID'sini giriniz:");
    scanf("%s", ogrID);
    Ogrenci *temp = *ogrenciHead;
    Ogrenci *prev = NULL;
    int bulundu = 0;
    while (temp != NULL && bulundu == 0)
    {
        if (strcmp(temp->ogrID, ogrID) == 0)
        {
            bulundu = 1;
            if (prev == NULL)
            {
                *ogrenciHead = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
        }
        prev = temp;
        temp = temp->next;
    }
    if (bulundu == 0)
    {
        printf("Ogrenci bulunamadi\n");
    }
    else
    {
        printf("Ogrenci silindi\n");
    }
}

void ogrenciSilIsim(Ogrenci **ogrenciHead)
{
    char ad[30];
    char soyad[30];
    printf("Silinecek ogrencinin adini giriniz:");
    scanf("%s", ad);
    printf("Silinecek ogrencinin soyadini giriniz:");
    scanf("%s", soyad);
    Ogrenci *temp = *ogrenciHead;
    Ogrenci *prev = NULL;
    int bulundu = 0;
    while (temp != NULL)
    {
        if (strcmp(temp->ad, ad) == 0 && strcmp(temp->soyad, soyad) == 0 && bulundu == 0)
        {
            bulundu = 1;
            if (prev == NULL)
            {
                *ogrenciHead = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
        }
        prev = temp;
        temp = temp->next;
    }
    if (bulundu == 0)
    {
        printf("Ogrenci bulunamadi\n");
    }
    else
    {
        printf("Ogrenci silindi\n");
    }
}
void ogrencileriCSVyeYaz(Ogrenci *ogrenciHead)
{
    FILE *fp = fopen("Ogrenciler.csv", "w");
    if (fp == NULL)
    {
        printf("Ogrenci dosyasi yazmak icin acilamadi");
        exit(1);
    }
    Ogrenci *ogrenci = ogrenciHead;
    while (ogrenci != NULL)
    {
        fprintf(fp, "%s,%s,%s,%d\n", ogrenci->ogrID, ogrenci->ad, ogrenci->soyad, ogrenci->puan);
        ogrenci = ogrenci->next;
    }
    fclose(fp);
}
void ogrenciGuncelle(Ogrenci **ogrenciHead)
{
    char ogrID[9];
    printf("Islem yapilacak ogrencinin ID'sini giriniz:");
    scanf("%s", ogrID);
    Ogrenci *temp = *ogrenciHead;
    int bulundu = 0;
    while (temp != NULL && bulundu == 0)
    {
        if (strcmp(temp->ogrID, ogrID) == 0)
        {
            printf("%s idli ogrenci icin:\n", ogrID);
            bulundu = 1;
            printf("Ad:");
            scanf("%s", temp->ad);
            printf("Soyad:");
            scanf("%s", temp->soyad);
            printf("Puan:");
            scanf("%d", &temp->puan);
        }
        temp = temp->next;
    }
    if (bulundu == 0)
    {
        printf("Ogrenci bulunamadi\n");
    }
    else
    {
        printf("Ogrenci guncellendi\n");
    }
}

void yazarlariOku(Yazar **yazarHead)
{
    FILE *fp = fopen("Yazarlar.csv", "r");
    if (fp == NULL)
    {
        printf("Yazar dosyasi okumak icin acilamadi");
        exit(1);
    }
    char buffer[100];
    Yazar *yazar = NULL;
    while (fgets(buffer, 100, fp) != NULL)
    {
        yazar = (Yazar *)malloc(sizeof(Yazar));
        yazar->next = NULL;
        char *token = strtok(buffer, ",");
        yazar->yazarID = atoi(token);
        token = strtok(NULL, ",");
        strcpy(yazar->yazarAd, token);
        token = strtok(NULL, "\n");
        strcpy(yazar->yazarSoyad, token);
        if (*yazarHead == NULL)
        {
            *yazarHead = yazar;
        }
        else
        {
            Yazar *temp = *yazarHead;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = yazar;
        }
    }
    fclose(fp);
}
void yazarlariCSVyeYazdir(Yazar *yazarHead)
{
    FILE *fp = fopen("Yazarlar.csv", "w");
    if (fp == NULL)
    {
        printf("Yazar dosyasi yazmak icin acilamadi");
        exit(1);
    }
    Yazar *yazar = yazarHead;
    while (yazar != NULL)
    {
        fprintf(fp, "%d,%s,%s\n", yazar->yazarID, yazar->yazarAd, yazar->yazarSoyad);
        yazar = yazar->next;
    }
    fclose(fp);
}

void yazarlariYazdir(Yazar *yazarHead)
{
    printf("YAZARLAR\n");
    Yazar *yazar = yazarHead;
    while (yazar != NULL)
    {
        printf("%d %s %s\n", yazar->yazarID, yazar->yazarAd, yazar->yazarSoyad);
        yazar = yazar->next;
    }
}
void yazarEkle(Yazar **yazarHead)
{
    Yazar *yazar = (Yazar *)malloc(sizeof(Yazar));
    yazar->next = NULL;
    Yazar *temp = *yazarHead;
    int max = 0;
    while (temp != NULL)
    {
        if (temp->yazarID > max)
        {
            max = temp->yazarID;
        }
        temp = temp->next;
    }
    yazar->yazarID = max + 1;
    printf("Ad:");
    scanf("%s", yazar->yazarAd);
    printf("Soyad:");
    scanf("%s", yazar->yazarSoyad);
    if (*yazarHead == NULL)
    {
        *yazarHead = yazar;
    }
    else
    {
        Yazar *temp = *yazarHead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = yazar;
    }
    printf("Yazar eklendi\n");
}
int yazarSil(Yazar **yazarHead)
{
    int found = 0;
    char ad[20];
    char soyad[20];
    printf("Ad:");
    scanf("%s", ad);
    printf("Soyad:");
    scanf("%s", soyad);
    Yazar *temp = *yazarHead;
    Yazar *prev = NULL;
    int id = -1;
    while (temp != NULL)
    {
        if (strcmp(temp->yazarAd, ad) == 0 && strcmp(temp->yazarSoyad, soyad) == 0)
        {
            found = 1;
            id = temp->yazarID;
            if (prev == NULL)
            {
                *yazarHead = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (found == 1)
    {
        printf("Yazar silindi\n");
    }
    else
    {
        printf("Yazar bulunamadi\n");
    }
    return id;
}
void yazarGuncelle(Yazar **yazarHead)
{
    char ad[20];
    char soyad[20];
    printf("Ad:");
    scanf("%s", ad);
    printf("Soyad:");
    scanf("%s", soyad);
    Yazar *temp = *yazarHead;
    int found = 0;
    while (temp != NULL && found == 0)
    {
        if (strcmp(temp->yazarAd, ad) == 0 && strcmp(temp->yazarSoyad, soyad) == 0)
        {
            printf("Yeni bilgileri giriniz.\n");
            char tmpAd[20];
            char tmpSoyad[20];
            printf("Ad:");
            scanf("%s", tmpAd);
            printf("Soyad:");
            scanf("%s", tmpSoyad);
            strcpy(temp->yazarAd, tmpAd);
            strcpy(temp->yazarSoyad, tmpSoyad);
            found = 1;
        }
        temp = temp->next;
    }
    if (found == 0)
    {
        printf("Yazar bulunamadi\n");
        return;
    }
    else
    {
        printf("Yazar guncellendi\n");
    }
}
void menuyuYazdir()
{
    printf("OGRENCI ISLEMLERI\n");
    printf("1- Ogrenci Ekle, Sil, Guncelle\n");
    printf("2- Ogrenci Bilgisi Goruntuleme\n");
    printf("3- Kitap Teslim Etmemis Ogrencileri Listele\n");
    printf("4- Cezali Ogrencileri Listele\n");
    printf("5- Tum Ogrencileri Listele\n");
    printf("6- Kitap Odunc Al/Teslim Et\n");
    printf("\n");
    printf("KITAP ISLEMLERI\n");
    printf("7- Kitap Ekle, Sil, Guncelle\n");
    printf("8- Kitap Bilgisi Goruntuleme\n");
    printf("9- Raftaki Kitaplari Listele\n");
    printf("10- Zamaninda Teslim Edilmeyen Kitaplari Listele\n");
    printf("11- Kitap-Yazar Eslestir\n");
    printf("12- Kitabin Yazarini Guncelle\n");
    printf("\n");
    printf("YAZAR ISLEMLERI\n");
    printf("13- Yazar Ekle, Sil, Guncelle\n");
    printf("14- Yazar Bilgisi Goruntuleme\n");
    printf("0- Cikis\n");
}
