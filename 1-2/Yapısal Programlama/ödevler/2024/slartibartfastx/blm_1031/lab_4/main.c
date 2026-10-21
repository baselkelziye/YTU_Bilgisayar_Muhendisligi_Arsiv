#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Musteri {
    int siparisKodu;
    int musteriID;
    char musteriAdi[20];
    char urunTipi[20];
    char siparisGunu[20];
    struct Musteri* next;
};

struct Musteri* ekle(struct Musteri* liste, int siparisKodu, int musteriID, const char* musteriAdi, const char* urunTipi, const char* siparisGunu) {
    struct Musteri* yeniMusteri = (struct Musteri*)malloc(sizeof(struct Musteri));
    yeniMusteri->siparisKodu = siparisKodu;
    yeniMusteri->musteriID = musteriID;
    strcpy(yeniMusteri->musteriAdi, musteriAdi);
    strcpy(yeniMusteri->urunTipi, urunTipi);
    strcpy(yeniMusteri->siparisGunu, siparisGunu);
    yeniMusteri->next = NULL;

    if (liste == NULL || siparisKodu < liste->siparisKodu) {
        yeniMusteri->next = liste;
        return yeniMusteri;
    }

    struct Musteri* temp = liste;
    while (temp->next != NULL && temp->next->siparisKodu < siparisKodu) {
        temp = temp->next;
    }

    yeniMusteri->next = temp->next;
    temp->next = yeniMusteri;

    return liste;
}

struct Musteri* dosyadanOku(const char* dosyaAdi) {
    FILE* dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        perror("Dosya acilamadi.");
        exit(EXIT_FAILURE);
    }

    
    fseek(dosya, 0, SEEK_END);
    long fileSize = ftell(dosya);
    rewind(dosya);

    
    char* buffer = (char*)malloc(fileSize);
    if (buffer == NULL) {
        perror("Hafiza ayrilamadi.");
        exit(EXIT_FAILURE);
    }

    size_t bytesRead = fread(buffer, 1, fileSize, dosya);
    fclose(dosya);

    if (bytesRead != fileSize) {
        perror("Dosya okunurken hata olustu.");
        exit(EXIT_FAILURE);
    }

    struct Musteri* liste = NULL;
    char* token = strtok(buffer, " \n");

    while (token != NULL) {
        int siparisKodu = atoi(token);
        token = strtok(NULL, " \n");
        int musteriID = atoi(token);
        token = strtok(NULL, " \n");
        char musteriAdi[20];
        strcpy(musteriAdi, token);
        token = strtok(NULL, " \n");
        char urunTipi[20];
        strcpy(urunTipi, token);
        token = strtok(NULL, " \n");
        char siparisGunu[20];
        strcpy(siparisGunu, token);
        token = strtok(NULL, " \n");

        liste = ekle(liste, siparisKodu, musteriID, musteriAdi, urunTipi, siparisGunu);
    }

    free(buffer);
    return liste;
}

void listeyiGoster(struct Musteri* liste) {
    printf("Siparis Kodu\tMusteri ID\tMusteri Adi\tUrun Tipi\tSiparis Gunu\n");
    while (liste != NULL) {
        printf("%d\t\t%d\t\t%s\t\t%s\t\t%s\n", liste->siparisKodu, liste->musteriID, liste->musteriAdi, liste->urunTipi, liste->siparisGunu);
        liste = liste->next;
    }
}


void dosyaOlustur(struct Musteri* liste) {
    while (liste != NULL) {
        char dosyaAdi[50];
        sprintf(dosyaAdi, "%s.txt",liste->musteriAdi);

        FILE* dosya = fopen(dosyaAdi, "w");
        fprintf(dosya, "Merhaba %s, %s gunu tarafinizdan siparis numarasi %d olan musteri id %d olan %s alisverisi gerceklestirilmistir.Iyi gunler.\n",
                liste->musteriAdi, liste->siparisGunu,liste->siparisKodu, liste->musteriID, liste->urunTipi);
        fclose(dosya);

        liste = liste->next;
    }
}

void raporOlustur(struct Musteri* liste) {
    int i;
    FILE* raporDosyasi = fopen("rapor.txt", "w");
    char urunTipleri[10][10];
    int urunTipiSayilari[10] = {0};
    int urunTipiIndex = 0;

    while (liste != NULL) {
        int found = 0;

        for (i = 0; i < urunTipiIndex && !found; ++i) {
            found = (strcmp(urunTipleri[i], liste->urunTipi) == 0);
        }

        if (!found) {
            strcpy(urunTipleri[urunTipiIndex], liste->urunTipi);
            urunTipiSayilari[urunTipiIndex] = 1;  
            urunTipiIndex++;
        } else {
            urunTipiSayilari[i - 1]++;  
        }

        liste = liste->next;
    }

    for (i = 0; i < urunTipiIndex; ++i) {
        fprintf(raporDosyasi, "%s siparis sayisi %d\n", urunTipleri[i], urunTipiSayilari[i]);
    }

    fclose(raporDosyasi);
}

int main() {
    struct Musteri* liste = dosyadanOku("input.txt");
    listeyiGoster(liste);
    dosyaOlustur(liste);
    raporOlustur(liste);

    return 0;
}
