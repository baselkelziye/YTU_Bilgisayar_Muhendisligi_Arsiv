#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct Ogrenci
{
    char ogrID[9];
    char ad[30];
    char soyad[30];
    int puan;
    struct Ogrenci *next;
    struct Ogrenci *prev;
} OGRENCI;

typedef struct Yazar
{
    int yazarID;
    char yazarAd[30];
    char yazarSoyad[30];
    struct Yazar *next;
} YAZAR;
typedef struct KitapOrnek
{
    char EtiketNo[20];
    char Durum[8];
    struct KitapOrnek *next;
} KITORN;

typedef struct Kitap
{
    char kitapAdi[30];
    char ISBN[15];
    int adet;
    struct Kitap *next;
    struct KitapOrnek *head;
} KITAP;

typedef struct KitapYazar
{
    char ISBN[15];
    int YazarID;
    struct KitapYazar *next;
} KYAZAR;

typedef struct Tarih
{
    int gun : 5;
    int ay : 4;
    int yil : 12;
} TARIH;

typedef struct KitapOdunc
{
    char EtiketNo[20];
    char ogrID[9];
    int islemTipi : 1;
    struct Tarih islemTarihi;
    struct KitapOdunc *next;

} KODUNC;
void split_ogrenci(OGRENCI *holder, char *buff);
void split_yazar(YAZAR *holder, char *buff);
void split_kitap(KITAP *holder, char *buff);
void split_k_odunc(KODUNC *holder, char *buff);
void split_k_yazar(KYAZAR *holder, char *buff);
void ogrencileri_listele(OGRENCI *head);
void raftakileri_listele(KODUNC *kodunc);
void cezalilari_listele(KODUNC *kodunc, OGRENCI *ogrenci);
void verilmeyenleri_listele(KODUNC *kodunc);
void ogrenci_goruntule(OGRENCI *ogrenci, KODUNC *kodunc, KITAP *kitap);
void ogrenci_ekle(OGRENCI **head);
void ogrencileri_oku(char *file_name, OGRENCI **ogrenci);
void kitaplari_oku(char *file_name, KITAP **kitap);
void yazarlari_oku(char *file_name, YAZAR **yazar);
void kyazarlari_oku(char *file_name, KYAZAR **kyazar);
void koduncleri_oku(char *file_name, KODUNC **kodunc);
void ogrenci_guncelle(OGRENCI *head);
void ogrenci_sil(OGRENCI **head);
void yazarlari_yaz(YAZAR *head, char *file_name);
void ogrencileri_yaz(OGRENCI *head, char *file_name);
void kitaplari_yaz(KITAP *head, char *file_name);
void kitap_ekle(KITAP **head);
void kitaplilari_listele(KODUNC *kodunc, OGRENCI *ogrenci);
void kitap_sil(KITAP **head);
void kitap_guncelle(KITAP *head);
void yazar_ekle(YAZAR **head);
void yazar_sil(YAZAR **head);
void yazar_guncelle(YAZAR *head);
void yazar_goruntule(YAZAR *yazar, KYAZAR *kityaz, KITAP *kitap);
void ornek_olustur(KITAP *kitap);
void yazarlari_listele(YAZAR *head);
void islemleri_listele(KODUNC *head);
void odunc_al();
void teslim_et();
// void kitap_yazarlari_listele(KYAZAR *head);
void kitabin_yazarini_guncelle(KITAP *kitap, KYAZAR *kyazar);
void kitap_goruntule(KITAP *kitap, KYAZAR *kyazar, YAZAR *yazar);
void kitaplari_listele_wornek(KITAP *head);
void kitap_yazar_eslestir(KITAP *kitap, KYAZAR *kyazar, YAZAR *yazar);
int main()
{
    OGRENCI **ogrHead = (OGRENCI **)malloc(sizeof(OGRENCI *));
    YAZAR **yzrHead = (YAZAR **)malloc(sizeof(YAZAR *));
    KITAP **ktphead = (KITAP **)malloc(sizeof(KITAP *));
    KODUNC **kdncHead = (KODUNC **)malloc(sizeof(KODUNC *));
    KYAZAR **kyzrHead = (KYAZAR **)malloc(sizeof(KYAZAR *));
    ogrencileri_oku("Ogrenciler.csv", ogrHead);
    yazarlari_oku("Yazarlar.csv", yzrHead);
    kitaplari_oku("Kitaplar.csv", ktphead);
    ornek_olustur(*ktphead);
    koduncleri_oku("KitapOdunc.csv", kdncHead);
    kyazarlari_oku("KitapYazar.csv", kyzrHead);
    // kitap_yazarlari_listele(*kyzrHead);
    // islemleri_listele(*kdncHead);
    int cho1, cho2, cho3, program = 1;
    while (program)
    {
        printf("\n1-OGRENCI ISLEMLERI\n2-KITAP ISLEMLERI\n3-YAZAR ISLEMLERI\n4-CIKIS\n => ");
        scanf("%d", &cho1);
        switch (cho1)
        {
        case 1:
            // ogrencileri_listele(*ogrHead);
            printf("\n1-Ogrenci Ekle, Sil, Guncelle\n2-Ogrenci Bilgisi Goruntuleme\n3-Kitap Teslim Etmemis Ogrencileri Listele\n4-Cezali Ogrencileri Listele\n5-Tum Ogrencileri Listele\n6-Kitap Odunc Al\\Teslim Et\n => ");
            scanf("%d", &cho2);
            switch (cho2)
            {
            case 1:
                printf("\n1-Ekle\n2-Sil\n3-Guncelle\n => ");
                scanf("%d", &cho3);
                switch (cho3)
                {
                case 1:
                    ogrenci_ekle(ogrHead);
                    break;
                case 2:
                    ogrenci_sil(ogrHead);
                    ogrencileri_yaz(*ogrHead, "Ogrenciler.csv");
                    break;
                case 3:
                    ogrenci_guncelle(*ogrHead);
                    ogrencileri_yaz(*ogrHead, "Ogrenciler.csv");
                    break;
                default:
                    printf("Hatali giris");
                    break;
                }
                break;
            case 2:
                ogrenci_goruntule(*ogrHead, *kdncHead, *ktphead);
                break;
            case 3:
                kitaplilari_listele(*kdncHead, *ogrHead);
                break;
            case 4:
                cezalilari_listele(*kdncHead, *ogrHead);
                break;
            case 5:
                ogrencileri_listele(*ogrHead);
                break;
            case 6:
                odunc_al();
                break;
            case 7:
                teslim_et();
                break;
            }
            break;
        case 2:
            // kitaplari_listele_wornek(*ktphead);
            printf("1-Kitap Ekle, Sil, Guncelle\n2-Kitap Bilgisi Goruntuleme\n3-Raftaki Kitaplari Listele\n4-Zamaninda Teslim Edilmeyen Kitaplari Listele\n5-Kitap-Yazar Eslestir\n6-Kitabin Yazarini Guncelle\n => ");
            scanf("%d", &cho2);
            switch (cho2)
            {
            case 1:
                printf("1-Kitap Ekle\n2-Kitap Sil\n3-Kitap Guncelle\n => ");
                scanf("%d", &cho3);
                switch (cho3)
                {
                case 1:
                    kitap_ekle(ktphead);
                    ornek_olustur(*ktphead);
                    break;
                case 2:
                    kitap_sil(ktphead);
                    kitaplari_yaz(*ktphead, "Kitaplar.csv");
                    break;
                case 3:
                    kitap_guncelle(*ktphead);
                    kitaplari_yaz(*ktphead, "Kitaplar.csv");
                    break;
                default:
                    printf("Hatali giris");
                    break;
                }
                break;
            case 2:
                kitap_goruntule(*ktphead, *kyzrHead, *yzrHead);
                break;
            case 3:
                raftakileri_listele(*kdncHead);
                break;
            case 4:
                verilmeyenleri_listele(*kdncHead);
                break;
            case 5:
                kitap_yazar_eslestir(*ktphead, *kyzrHead, *yzrHead);
                break;
            case 6:
                kitabin_yazarini_guncelle(*ktphead, *kyzrHead);
                break;
            }
            break;
        case 3:
            // yazarlari_listele(*yzrHead);
            printf("1-Yazar Ekle, Sil, Guncelle\n2-Yazar Bilgisi Goruntuleme\n => ");
            scanf("%d", &cho2);
            switch (cho2)
            {
            case 1:
                printf("1-Yazar Ekle\n2-Yazar Sil\n3-Yazar Guncelle\n => ");
                scanf("%d", &cho3);
                switch (cho3)
                {
                case 1:
                    yazar_ekle(yzrHead);
                    yazarlari_listele(*yzrHead);
                    break;
                case 2:
                    yazar_sil(yzrHead);
                    yazarlari_yaz(*yzrHead, "Yazarlar.csv");
                    yazarlari_listele(*yzrHead);
                    break;
                case 3:
                    yazar_guncelle(*yzrHead);
                    yazarlari_yaz(*yzrHead, "Yazarlar.csv");
                    yazarlari_listele(*yzrHead);
                    break;
                default:
                    printf("Hatali giris");
                    break;
                }
                break;
            case 2:
                yazar_goruntule(*yzrHead, *kyzrHead, *ktphead);
                break;
            default:
                printf("Hatali giris");
                break;
            }
            break;
        case 4:
            program = 0;
            break;
        default:
            break;
        }
    }

    return 0;
}
void yazarlari_listele(YAZAR *head)
{
    while (head != NULL)
    {
        printf("Yazar ID:%8d,Yazar Ad:%30s,Yazar Soyad:%30s\n", head->yazarID, head->yazarAd, head->yazarSoyad);
        head = head->next;
    }
}
void ogrencileri_listele(OGRENCI *head)
{
    while (head != NULL)
    {
        printf("Ogrenci ID:%8s, Ad:%30s, Soyad:%30s, Puan:%3d\n", head->ogrID, head->ad, head->soyad, head->puan);
        head = head->next;
    }
}

void ogrencileri_oku(char *file_name, OGRENCI **ogrenci)
{
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("%s bulunamadi!", file_name);
        exit(-1);
    }
    char data[100];
    OGRENCI *head = (OGRENCI *)malloc(sizeof(OGRENCI));
    if (head == NULL)
    {
        exit(-1);
    }
    *ogrenci = head;
    OGRENCI *curr_data;
    OGRENCI *prev_data = head;
    if (fgets(data, 100, fp) != NULL)
    {
        split_ogrenci(head, data);
    }
    prev_data = head;
    head->prev = NULL;
    while (fgets(data, 100, fp) != NULL)
    {
        curr_data = (OGRENCI *)malloc(sizeof(OGRENCI));
        curr_data->prev = prev_data;
        prev_data->next = curr_data;
        split_ogrenci(curr_data, data);
        prev_data = curr_data;
        curr_data->next = NULL;
    }
    fclose(fp);
}

void yazarlari_oku(char *file_name, YAZAR **yazar)
{
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("%s bulunamadi!", file_name);
        exit(-1);
    }
    char data[100];
    YAZAR *head = (YAZAR *)malloc(sizeof(YAZAR));
    if (head == NULL)
    {
        exit(-1);
    }
    *yazar = head;
    YAZAR *curr_data;
    YAZAR *prev_data = head;
    if (fgets(data, 100, fp) != NULL)
    {
        split_yazar(head, data);
    }
    prev_data = head;
    while (fgets(data, 100, fp) != NULL)
    {
        curr_data = (YAZAR *)malloc(sizeof(YAZAR));
        prev_data->next = curr_data;
        split_yazar(curr_data, data);
        prev_data = curr_data;
        curr_data->next = NULL;
    }
    fclose(fp);
}

void kitaplari_oku(char *file_name, KITAP **kitap)
{
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("%s bulunamadi!", file_name);
        exit(-1);
    }
    char data[100];
    KITAP *head = (KITAP *)malloc(sizeof(KITAP));
    if (head == NULL)
    {
        exit(-1);
    }
    *kitap = head;
    KITAP *curr_data;
    int i;
    KITAP *prev_data = head;
    if (fgets(data, 100, fp) != NULL)
    {
        split_kitap(head, data);
    }
    prev_data = head;
    while (fgets(data, 100, fp) != NULL)
    {
        curr_data = (KITAP *)malloc(sizeof(KITAP));
        prev_data->next = curr_data;
        split_kitap(curr_data, data);
        prev_data = curr_data;
        curr_data->next = NULL;
    }
    fclose(fp);
}

void ornek_olustur(KITAP *kitap)
{
    int i;
    KITORN *tmp, *iter;
    KITAP *a = kitap;
    while (a != NULL)
    {
        tmp = (KITORN *)malloc(sizeof(KITORN) * 1);
        strcpy(tmp->EtiketNo, a->ISBN);
        strcpy(tmp->Durum, "rafta");
        tmp->next = NULL;
        a->head = tmp;
        iter = tmp;

        for (i = 0; i < a->adet - 1; i++)
        {

            tmp = (KITORN *)malloc(sizeof(KITORN) * 1);
            strcpy(tmp->EtiketNo, a->ISBN);
            strcpy(tmp->Durum, "rafta");
            tmp->next = NULL;
            iter->next = tmp;
            iter = iter->next;
        }
        a = a->next;
    }
}

void split_ogrenci(OGRENCI *ogr, char buff[100])
{
    char *tmp;
    tmp = strtok(buff, ",");
    strcpy(ogr->ogrID, tmp);
    ogr->ogrID[9] = '\0';

    tmp = strtok(NULL, ",");
    strcpy(ogr->ad, tmp);
    tmp = strtok(NULL, ",");
    strcpy(ogr->soyad, tmp);

    tmp = strtok(NULL, "\n");
    ogr->puan = atof(tmp);
}

void split_yazar(YAZAR *holder, char buff[100])
{
    char *tmp;
    tmp = strtok(buff, ",");
    holder->yazarID = atoi(tmp);

    tmp = strtok(NULL, ",");
    strcpy(holder->yazarAd, tmp);

    tmp = strtok(NULL, "\n");
    strcpy(holder->yazarSoyad, tmp);
}

void split_kitap(KITAP *holder, char buff[100])
{
    char *tmp;
    tmp = strtok(buff, ",");
    strcpy(holder->kitapAdi, tmp);

    tmp = strtok(NULL, ",");
    strcpy(holder->ISBN, tmp);

    tmp = strtok(NULL, "\n");
    holder->adet = atoi(tmp);
}

void koduncleri_oku(char *file_name, KODUNC **kodunc)
{
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("%s bulunamadi!", file_name);
        exit(-1);
    }
    char data[100];
    KODUNC *head = (KODUNC *)malloc(sizeof(KODUNC));
    if (head == NULL)
    {
        exit(-1);
    }
    *kodunc = head;
    KODUNC *curr_data;
    KODUNC *prev_data = head;
    if (fgets(data, 100, fp) != NULL)
    {
        split_k_odunc(head, data);
    }
    prev_data = head;
    while (fgets(data, 100, fp) != NULL)
    {
        curr_data = (KODUNC *)malloc(sizeof(KODUNC));
        prev_data->next = curr_data;
        split_k_odunc(curr_data, data);
        prev_data = curr_data;
        curr_data->next = NULL;
    }
    fclose(fp);
}

void kyazarlari_oku(char *file_name, KYAZAR **kyazar)
{
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("%s bulunamadi!", file_name);
        exit(-1);
    }
    char data[100];
    KYAZAR *head = (KYAZAR *)malloc(sizeof(KYAZAR));
    if (head == NULL)
    {
        exit(-1);
    }
    *kyazar = head;
    KYAZAR *curr_data;
    KYAZAR *prev_data = head;
    if (fgets(data, 100, fp) != NULL)
    {
        split_k_yazar(head, data);
    }
    prev_data = head;
    while (fgets(data, 100, fp) != NULL)
    {
        curr_data = (KYAZAR *)malloc(sizeof(KYAZAR));
        prev_data->next = curr_data;
        split_k_yazar(curr_data, data);
        prev_data = curr_data;
        curr_data->next = NULL;
    }
    fclose(fp);
}
void split_k_odunc(KODUNC *holder, char *buff)
{
    char *tmp;
    int date;
    tmp = strtok(buff, ",");
    strcpy(holder->EtiketNo, tmp);

    tmp = strtok(NULL, ",");
    strcpy(holder->ogrID, tmp);

    tmp = strtok(NULL, ",");
    holder->islemTipi = atoi(tmp);

    tmp = strtok(NULL, ",");

    tmp = strtok(tmp, ".");
    date = atoi(tmp);
    holder->islemTarihi.gun = date;

    tmp = strtok(NULL, ".");
    date = atoi(tmp);
    holder->islemTarihi.ay = date;

    tmp = strtok(tmp, ".");
    date = atoi(tmp);
    holder->islemTarihi.yil = date;
}

void split_k_yazar(KYAZAR *holder, char *buff)
{
    char *tmp;
    tmp = strtok(buff, ",");
    strcpy(holder->ISBN, tmp);

    tmp = strtok(NULL, ",");
    holder->YazarID = atoi(tmp);
}

void yazarlari_yaz(YAZAR *head, char *file_name)
{
    FILE *fp = fopen(file_name, "w");
    if (head == NULL)
    {
        printf("Yazilacak eleman yok!");
        fclose(fp);
    }
    while (head->next != NULL)
    {
        fprintf(fp, "%d,%s,%s\n", head->yazarID, head->yazarAd, head->yazarSoyad);
        head = head->next;
    }
    fprintf(fp, "%d,%s,%s", head->yazarID, head->yazarAd, head->yazarSoyad);

    fclose(fp);
    return;
}

void kitaplari_yaz(KITAP *head, char *file_name)
{
    FILE *fp = fopen(file_name, "w");
    if (head == NULL)
    {
        printf("Yazilacak eleman yok!");
        fclose(fp);
    }
    while (head != NULL)
    {
        fprintf(fp, "%S,%s,%d", head->kitapAdi, head->ISBN, head->adet);
        head = head->next;
    }

    fclose(fp);
    return;
}

void ogrencileri_yaz(OGRENCI *head, char *file_name)
{
    FILE *fp = fopen(file_name, "w");
    if (head == NULL)
    {
        printf("Yazilacak eleman yok!");
        fclose(fp);
    }

    while (head != NULL)
    {
        fprintf(fp, "%s,%s,%s,%d", head->ogrID, head->ad, head->soyad, head->puan);
        head = head->next;
    }

    fclose(fp);
    return;
}

void ogrenci_sil(OGRENCI **head)
{
    char *ad, *soyad;
    OGRENCI *tmp, *prev;
    int flag = 0;
    ad = (char *)malloc(sizeof(char) * 30);
    soyad = (char *)malloc(sizeof(char) * 30);
    printf("Silmek istediginiz ogrencinin adini ve soyadini giriniz.");
    scanf("%s %s", ad, soyad);
    tmp = *head;
    if (tmp == NULL)
    {
        printf("Silinecek ogrenci yok!");
        return;
    }
    prev = NULL;
    while (tmp != NULL && !flag)
    {
        if ((strcmp(tmp->ad, ad) == 0) && (strcmp(tmp->soyad, soyad) == 0))
        {
            flag = 1;
        }
        prev = tmp;
        tmp = tmp->next;
    }

    if (flag == 0) // eleman yok
    {
        printf("Öğrenci bulunamadi");
        return;
    }
    else // eleman bulundu
    {
        if (prev == *head) // ilk eleman silinecekse
        {
            (*head) = tmp;
            free(prev);
            tmp->prev = NULL;
        }
        else if (prev->next == NULL) // eleman sonda bulundu
        {
            prev->prev->next = NULL;
            free(prev);
        }
        else // ortada
        {
            prev->prev->next = tmp;
            tmp->prev = prev->prev;
            free(prev);
        }
        printf("Eleman silindi");
    }
}

void ogrenci_ekle(OGRENCI **head)
{
    int ogrID;
    FILE *fp;
    OGRENCI *tmp, *iter;
    fp = fopen("Ogrenciler.csv", "a");
    if (fp == NULL)
    {
        printf("Simdilik hicbir ogrenci yok...");
        fclose(fp);
        fp = fopen("Ogrenciler.csv", "w");
        if (fp == NULL)
        {
            exit(-1);
        }
    }
    iter = (*head);
    tmp = (OGRENCI *)malloc(sizeof(OGRENCI) * 1);
    printf("Eklemek istediginiz ogrencinin adini, soyadini ve IDsini giriniz.");
    scanf("%s %s %s", &tmp->ad, &tmp->soyad, &tmp->ogrID);
    tmp->puan = 100;
    tmp->next = NULL;
    if (*head == NULL)
    {
        tmp->prev = NULL;
        *head = tmp;
        fprintf(fp, "%s,%s,%s,%d", tmp->ogrID, tmp->ad, tmp->soyad, tmp->puan);
        printf("Ilk ogrenci basariyla eklendi.");
    }
    else
    {
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        iter->next = tmp;
        tmp->prev = iter;
        fprintf(fp, "\n%s,%s,%s,%d", tmp->ogrID, tmp->ad, tmp->soyad, tmp->puan);
        printf("Ogrenci basariyla eklendi.");
    }
    fclose(fp);
}

void ogrenci_guncelle(OGRENCI *head)
{
    OGRENCI *tmp = head;
    OGRENCI *prev = NULL;
    char *ad, *soyad;
    ad = (char *)malloc(sizeof(char) * 30);
    soyad = (char *)malloc(sizeof(char) * 30);
    int flag = 0;
    printf("Guncellemek istediginiz ogrencinin adini ve soyadini giriniz.");
    scanf("%s %s", ad, soyad);
    while (tmp != NULL && !flag)
    {
        if ((strcmp(tmp->ad, ad) == 0) && (strcmp(tmp->soyad, soyad) == 0))
        {
            flag = 1;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    if (flag == 0)
    {
        printf("Ogrenci bulunamadi!");
    }
    else // bulundu
    {
        printf("Ogrencinin adini, soyadini ve puanini giriniz.");
        scanf("%s %s %d", &prev->ad, &prev->soyad, &prev->puan);
        printf("Ogrenci basariyla guncellendi.");
    }
}

void ogrenci_goruntule(OGRENCI *ogrenci, KODUNC *kodunc, KITAP *kitap)
{
    char *ad, *soyad;
    printf("Goruntulemek istediginiz ogrencinin adini ve soyadini giriniz. ");
    ad = (char *)malloc(sizeof(char) * 30);
    soyad = (char *)malloc(sizeof(char) * 30);
    scanf("%s %s", ad, soyad);
    int kdncFlg = 0;
    int ogrFlg = 0;

    KODUNC *currkdnc = kodunc;

    while ((ogrenci != NULL) && !ogrFlg)
    {
        if ((strcmp(ogrenci->ad, ad) == 0) && (strcmp(ogrenci->soyad, soyad) == 0))
        {
            ogrFlg = 1;
            currkdnc = kodunc;
            while (currkdnc != NULL && !kdncFlg)
            {
                if (strcmp(currkdnc->ogrID, ogrenci->ogrID) == 0)
                {
                    kdncFlg = 1;
                    printf("Ogrencinin Adi Soyadi: %s %s, Ogrenci ID: %s, Puani :%d,  Son Aldigi Kitap ISBN : %s ", ogrenci->ad, ogrenci->soyad, ogrenci->ogrID, ogrenci->puan, currkdnc->EtiketNo);
                }
                currkdnc = currkdnc->next;
            }
        }
        ogrenci = ogrenci->next;
    }
}

void kitap_ekle(KITAP **head)
{
    FILE *fp;
    KITAP *tmp, *iter;
    fp = fopen("Kitaplar.csv", "a");
    if (fp == NULL)
    {
        exit(-1);
    }
    iter = (*head);
    tmp = (KITAP *)malloc(sizeof(KITAP) * 1);
    printf("Eklemek istediginiz kitabin adini, ISBN kodunu ve adetini giriniz.");
    scanf("%s %s %d", &tmp->kitapAdi, &tmp->ISBN, &tmp->adet);
    tmp->next = NULL;
    if (*head == NULL)
    {
        *head = tmp;
        fprintf(fp, "%s,%s,%d", tmp->kitapAdi, tmp->ISBN, tmp->adet);
        printf("Ilk kitap basariyla eklendi.");
    }
    else
    {
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        iter->next = tmp;
        fprintf(fp, "\n%s,%s,%d", tmp->kitapAdi, tmp->ISBN, tmp->adet);
        printf("Kitap basariyla eklendi.");
    }
    fclose(fp);
}
void kitap_sil(KITAP **head)
{

    char *ad;
    KITAP *tmp, *prev;
    int flag = 0;
    ad = (char *)malloc(sizeof(char) * 30);
    printf("Silmek istediginiz kitabin adini giriniz.");
    scanf("%s", ad);
    tmp = *head;
    if (tmp == NULL)
    {
        printf("Silinecek ogrenci yok!");
        return;
    }
    prev = NULL;
    if (strcmp(tmp->kitapAdi, ad) == 0) // ilkinde bulunduysa
    {
        flag = 1;
    }
    while (tmp->next != NULL && !flag)
    {
        // printf("%s\n", tmp->next->kitapAdi);
        if (strcmp(tmp->next->kitapAdi, ad) == 0)
        {
            flag = 1;
        }
        prev = tmp;
        tmp = tmp->next;
    }

    if (flag == 0) // eleman yok
    {
        printf("Kitap bulunamadi");
        return;
    }
    else // eleman bulundu
    {
        if (tmp == *head) // ilk eleman silinecekse

        {
            (*head) = tmp->next;
            free(tmp);
        }
        else if (tmp->next == NULL) // eleman sonda bulundu
        {
            prev->next = NULL;
            free(tmp);
        }
        else // ortada
        {
            prev->next = tmp->next;
            free(tmp);
        }
    }
}
void kitap_guncelle(KITAP *head)
{
    KITAP *tmp = head;
    KITAP *prev = NULL;
    char *ad;
    ad = (char *)malloc(sizeof(char) * 30);
    int flag = 0;
    printf("Guncellemek istediginiz kitabin adini giriniz.");
    scanf("%s", ad);
    while (tmp != NULL && !flag)
    {
        if (strcmp(tmp->kitapAdi, ad) == 0)
        {
            flag = 1;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    if (flag == 0)
    {
        printf("Kitap bulunamadi!");
    }
    else // bulundu
    {
        printf("Kitabin yeni adini, ISBN kodunu ve adetini giriniz.");
        scanf("%s %s %d", &prev->kitapAdi, &prev->ISBN, &prev->adet);
        printf("Kitap basariyla guncellendi.");
    }
}
void kitap_goruntule(KITAP *kitap, KYAZAR *kyazar, YAZAR *yazar)
{
    char *ad;
    ad = (char *)malloc(sizeof(char) * 30);
    int kyazarFlg = 0;
    int kitapFlg = 0;

    printf("Goruntulemek istediginiz kitabin adini giriniz.");
    getchar();
    gets(ad);
    puts(ad);

    KYAZAR *currKtpYzr = kyazar;

    while ((kitap != NULL) && !kitapFlg)
    {
        if (strcmp(kitap->kitapAdi, ad) == 0)
        {
            kitapFlg = 1;
            currKtpYzr = kyazar;
            while (currKtpYzr != NULL && !kyazarFlg)
            {
                if (strcmp(currKtpYzr->ISBN, kitap->ISBN) == 0)
                {
                    kyazarFlg = 1;
                    printf("Kitabin Adi: %s, ISBN: %s, Adet: %d, Yazar Adi Soyadi: %s %s ", kitap->kitapAdi, kitap->ISBN, kitap->adet, yazar->yazarAd, yazar->yazarSoyad);
                }
                currKtpYzr = currKtpYzr->next;
            }
        }
        kitap = kitap->next;
    }
}
void kitaplari_listele_wornek(KITAP *head)
{
    KITORN *tmp;
    while (head != NULL)
    {
        printf("Kitap Adi:%30s, ISBN:%20s, Adet:%3d\n", head->kitapAdi, head->ISBN, head->adet);
        tmp = head->head;
        //        while (tmp != NULL)
        //        {
        //            printf("%s\t", tmp->EtiketNo);
        //            tmp = tmp->next;
        //        }

        head = head->next;
    }
}

void kitap_yazar_eslestir(KITAP *kitap, KYAZAR *kyazar, YAZAR *yazar)
{
    FILE *fp;
    fp = fopen("KitapYazar.csv", "a");
    if (fp == NULL)
    {
        printf("hata");
        exit(-1);
    }
    char *kitapAdi = (char *)malloc(sizeof(char) * 30);
    char *yazarAdi = (char *)malloc(sizeof(char) * 30);
    char *yazarSoyadi = (char *)malloc(sizeof(char) * 30);
    int yazarFlg = 0;
    int kitapFlg = 0;
    printf("Eslestirmek istediginiz kitabin adini giriniz. ");
    scanf("%s", kitapAdi);
    printf("Eslestirmek istediginiz yazarin adini ve soyadini giriniz. ");
    scanf("%s %s", yazarAdi, yazarSoyadi);

    KITAP *currKtp = kitap;
    KYAZAR *currKtpYzr = kyazar;

    while ((yazar != NULL) && !yazarFlg)
    {
        if (strcmp(yazar->yazarAd, yazarAdi) == 0 && strcmp(yazar->yazarSoyad, yazarSoyadi) == 0)
        {
            yazarFlg = 1;
            currKtp = kitap;
            while (currKtp != NULL && !kitapFlg)
            {
                if (strcmp(currKtp->kitapAdi, kitapAdi) == 0)
                {
                    KYAZAR *prev = NULL;
                    kitapFlg = 1;
                    while (currKtpYzr != NULL)
                    {
                        prev = currKtpYzr;
                        currKtpYzr = currKtpYzr->next;
                    }
                    if (prev == NULL)
                    {
                        prev = (KYAZAR *)malloc(sizeof(KYAZAR));
                        strcpy(prev->ISBN, currKtp->ISBN);
                        prev->YazarID = yazar->yazarID;
                        prev->next = NULL;
                        fprintf(fp, "%s,%d", prev->ISBN, prev->YazarID);
                    }
                    else
                    {
                        prev->next = (KYAZAR *)malloc(sizeof(KYAZAR));
                        strcpy(prev->next->ISBN, currKtp->ISBN);
                        prev->next->YazarID = yazar->yazarID;
                        prev->next->next = NULL;
                        fprintf(fp, "\n%s,%d", prev->next->ISBN, prev->next->YazarID);
                    }
                }
                currKtp = currKtp->next;
            }
        }
        yazar = yazar->next;
    }
    if (yazarFlg == 0 || kitapFlg == 0)
    {
        printf("Girdiginiz isme sahip kitap ya da yazar bulunmamaktadir.");
    }

    fclose(fp);
}

void kitabin_yazarini_guncelle(KITAP *kitap, KYAZAR *kyazar)
{
    char *ad = (char *)malloc(sizeof(char) * 30);
    printf("Guncellemek istediginiz kitabin adini giriniz. ");
    scanf("%s", ad);
    KYAZAR *currkyzr;
    int ktpflg = 0;
    while (kitap != NULL && !ktpflg)
    {
        if ((strcmp(kitap->kitapAdi, ad) == 0))
        {
            ktpflg = 1;
            currkyzr = kyazar;
            while (currkyzr != NULL)
            {

                if ((strcmp(kitap->ISBN, kyazar->ISBN) == 0))
                {
                }

                currkyzr = currkyzr->next;
            }
        }
        kitap = kitap->next;
    }
}

void yazar_ekle(YAZAR **head)
{
    FILE *fp;
    YAZAR *tmp, *iter;
    fp = fopen("Yazarlar.csv", "a");
    if (fp == NULL)
    {
        exit(-1);
    }
    iter = (*head);
    tmp = (YAZAR *)malloc(sizeof(YAZAR) * 1);
    printf("Eklemek istediginiz yazarin adini ve soyadini giriniz.");
    scanf("%s %s", &tmp->yazarAd, &tmp->yazarSoyad);
    tmp->next = NULL;
    if (*head == NULL)
    {
        tmp->yazarID = 1;
        *head = tmp;
        fprintf(fp, "%d,%s,%s", tmp->yazarID, tmp->yazarAd, tmp->yazarSoyad);
        printf("Ilk yazar basariyla eklendi.");
    }
    else
    {
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        tmp->yazarID = iter->yazarID + 1;
        iter->next = tmp;
        fprintf(fp, "\n%d,%s,%s", tmp->yazarID, tmp->yazarAd, tmp->yazarSoyad);
        printf("Yazar basariyla eklendi.");
    }
    fclose(fp);
}
void yazar_sil(YAZAR **head)
{
    char *ad, *soyad;
    YAZAR *tmp, *prev;
    int flag = 0;
    ad = (char *)malloc(sizeof(char) * 30);
    soyad = (char *)malloc(sizeof(char) * 30);
    printf("Silmek istediginiz yazarin adini ve soyadini giriniz.");
    scanf("%s %s", ad, soyad);
    tmp = *head;
    if (tmp == NULL)
    {
        printf("Silinecek ogrenci yok!");
        return;
    }
    prev = NULL;
    if ((strcmp(tmp->next->yazarAd, ad) == 0) && (strcmp(tmp->next->yazarSoyad, soyad) == 0)) // ilkinde bulunduysa
    {
        flag = 1;
    }
    while (tmp->next != NULL && !flag)
    {
        printf("%s\n", tmp->next->yazarAd);
        if ((strcmp(tmp->next->yazarAd, ad) == 0) && (strcmp(tmp->next->yazarSoyad, soyad) == 0))
        {
            flag = 1;
        }
        prev = tmp;
        tmp = tmp->next;
    }

    if (flag == 0) // eleman yok
    {
        printf("Yazar bulunamadi");
        return;
    }
    else // eleman bulundu
    {
        if (tmp == *head) // ilk eleman silinecekse

        {
            (*head) = tmp->next;
            free(tmp);
            printf("ilk eleman silindi");
        }
        else if (tmp->next == NULL) // eleman sonda bulundu
        {
            prev->next = NULL;
            free(tmp);
            printf("Son eleman silindi");
        }
        else // ortada
        {
            prev->next = tmp->next;
            free(tmp);
            printf("ortadan eleman silindi");
        }
    }
}
void yazar_guncelle(YAZAR *head)
{
    YAZAR *tmp = head;
    YAZAR *prev = NULL;
    char *ad, *soyad;
    ad = (char *)malloc(sizeof(char) * 30);
    soyad = (char *)malloc(sizeof(char) * 30);
    int flag = 0;
    printf("Guncellemek istediginiz yazarin adini ve soyadini giriniz.");
    scanf("%s %s", ad, soyad);
    while (tmp != NULL && !flag)
    {
        if ((strcmp(tmp->yazarAd, ad) == 0) && (strcmp(tmp->yazarSoyad, soyad) == 0))
        {
            flag = 1;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    if (flag == 0)
    {
        printf("Yazar bulunamadi!");
    }
    else // bulundu
    {
        printf("Yazar yeni IDsini, adini ve soyadini giriniz.");
        scanf("%d %s %s", &prev->yazarID, &prev->yazarAd, &prev->yazarSoyad);
        printf("Yazar basariyla guncellendi.");
    }
}
void yazar_goruntule(YAZAR *yazar, KYAZAR *kyazar, KITAP *kitap)
{
    char *ad = (char *)malloc(sizeof(char) * 30);
    int yazarFlg = 0;
    int kitapFlg = 0;
    printf("Kitaplarini goruntulemek istediğiniz yazarin adini giriniz: ");
    scanf("%s", ad);

    KITAP *currKtp = kitap;

    while ((yazar != NULL) && !yazarFlg)
    {
        if (strcmp(yazar->yazarAd, ad) == 0)
        {
            yazarFlg = 1;
            printf("Yazar ID:%3d,Yazar Adi:%10s, Yazar Soyadi:%10s\nKitaplari:\n", yazar->yazarID, yazar->yazarAd, yazar->yazarSoyad);
            while (kyazar != NULL)
            {
                if (yazar->yazarID == kyazar->YazarID)
                {
                    currKtp = kitap;
                    kitapFlg = 0;
                    while ((currKtp != NULL) && !kitapFlg)
                    {
                        if (strcmp(currKtp->ISBN, kyazar->ISBN) == 0)
                        {
                            kitapFlg = 1;
                            printf("-%s\t", currKtp->kitapAdi);
                        }
                        currKtp = currKtp->next;
                    }
                }
                kyazar = kyazar->next;
            }
        }
        yazar = yazar->next;
    }
    if (yazarFlg == 0)
    {
        printf("Girdiginiz isme sahip yazar bulunmamaktadir.");
    }
}

void kitaplilari_listele(KODUNC *kodunc, OGRENCI *ogrenci)
{
    KODUNC *curr = kodunc;
    KODUNC *prev = NULL;

    while (curr != NULL)
    {
        if (curr->islemTipi == 1)
        {
            while (ogrenci != NULL)
            {
                if (curr->ogrID == ogrenci->ogrID)
                {
                    printf("%s ID sine sahip %s %s adli ogrencide kitap bulunmaktadir.", ogrenci->ogrID, ogrenci->ad, ogrenci->soyad);
                }
            }
        }
        prev = curr;
        curr = curr->next;
    }
}
void cezalilari_listele(KODUNC *kodunc, OGRENCI *ogrenci)
{
}
void islemleri_listele(KODUNC *head)
{
    while (head != NULL)
    {
        printf("Ogrenci ID:%10s, ISBN:%30s, Islem Tipi:%3d\n", head->ogrID, head->EtiketNo, head->islemTipi);
        head = head->next;
    }
}
// void kitap_yazarlari_listele(KYAZAR *head)
//{
//     while (head != NULL)
//     {
//         printf("ISBN:%30s, Yazar ID:%3d\n", head->ISBN, head->YazarID);
//         head = head->next;
//     }
// }
void odunc_al() {}
void teslim_et() {}
void raftakileri_listele(KODUNC *kodunc)
{
    printf("RAFTAKILER:\n");

    while (kodunc != NULL)
    {
        if (kodunc->islemTipi == 1)
        {
            printf("\n%s", kodunc->EtiketNo);
        }
        kodunc = kodunc->next;
    }
}
void verilmeyenleri_listele(KODUNC *kodunc)
{
    printf("TESLIM EDILMEYENLER:\n");

    while (kodunc != NULL)
    {
        if (kodunc->islemTipi == 0)
        {
            printf("\n%s", kodunc->EtiketNo);
        }
        kodunc = kodunc->next;
    }
}