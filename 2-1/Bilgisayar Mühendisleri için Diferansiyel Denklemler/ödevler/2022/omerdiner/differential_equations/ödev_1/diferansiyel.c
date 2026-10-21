#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUMLE_UZUNLUK 300
#define MAX_CUMLE_SAYISI 200

int dosyadanCumleleriOku(char *dosyaAdi, char *cumleler[], int maxCumleSayisi);
char **uniqueKelimeleriBul(char *cumleler1[], int cumleSayisi1, char *cumleler2[], int cumleSayisi2, int *uniqueKelimeSayisi);
int **oneHotVectorOlustur(char *cumleler1[], char *cumleler2[], int cumleSayisi1, int cumleSayisi2, char **uniqueKelimeler, int uniqueKelimeSayisi);

int main()
{
    char class1[] = "positive.txt";
    char class2[] = "negative.txt";
    char *cumleler_1[MAX_CUMLE_SAYISI];
    char *cumleler_2[MAX_CUMLE_SAYISI];
    int cumleSayisi_1 = 0, cumleSayisi_2 = 0;
    int i = 0;
    int j = 0;
    int uniqueKelimeSayisi = 0;

    cumleSayisi_1 = dosyadanCumleleriOku(class1, cumleler_1, MAX_CUMLE_SAYISI);
    cumleSayisi_2 = dosyadanCumleleriOku(class2, cumleler_2, MAX_CUMLE_SAYISI);

    char **uniqueKelimeler = uniqueKelimeleriBul(cumleler_1, cumleSayisi_1, cumleler_2, cumleSayisi_2, &uniqueKelimeSayisi);

    /*printf("Unique kelimeler:\n");
    for (i = 0; i < uniqueKelimeSayisi; i++)
    {
        printf("%s\n", uniqueKelimeler[i]);
    }*/
    /* printf("unique kelime sayisi: %d", uniqueKelimeSayisi);
     for (i = 0; i < cumleSayisi_1; i++)
     {
         printf("%s\n", cumleler_1[i]);

     }*/

    //

    int **oneHotVektorler = oneHotVectorOlustur(cumleler_1, cumleler_2, cumleSayisi_1, cumleSayisi_2, uniqueKelimeler, uniqueKelimeSayisi);

    printf("One hot vektorler:\n");
    for (i = 0; i < cumleSayisi_1 + cumleSayisi_2; i++)
    {
        printf("%d. cumle icin one hot vektoru:\n ", i + 1);

        for (j = 0; j < uniqueKelimeSayisi; j++)
        {

            printf("%d ", oneHotVektorler[i][j]);
        }
        printf("\n\n");
    }

    // Bellekte ayrýlana yerleri temizleyen kdolar
    for (i = 0; i < cumleSayisi_1; i++)
    {
        free(cumleler_1[i]);
    }
    for (i = 0; i < cumleSayisi_2; i++)
    {
        free(cumleler_2[i]);
    }

    for (i = 0; i < uniqueKelimeSayisi; i++)
    {
        free(uniqueKelimeler[i]);
    }
    free(uniqueKelimeler);

    for (i = 0; i < cumleSayisi_1 + cumleSayisi_2; i++)
    {
        free(oneHotVektorler[i]);
    }

    free(oneHotVektorler);

    return 0;
}

int dosyadanCumleleriOku(char *dosyaAdi, char *cumleler[], int maxCumleSayisi)
{
    FILE *dosya;
    char cumle[MAX_CUMLE_UZUNLUK];
    int cumleSayisi = 0;

    dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL)
    {
        perror("hata,dosya acilamadi");
        exit(EXIT_FAILURE);
    }

    // Dosyadan cumleleri satir satir okur ve diziye atar
    while (fgets(cumle, MAX_CUMLE_UZUNLUK, dosya) != NULL && cumleSayisi < maxCumleSayisi)
    {

        cumle[strcspn(cumle, "\n")] = '\0';
        cumleler[cumleSayisi] = strdup(cumle);
        cumleSayisi++;
    }

    fclose(dosya);

    return cumleSayisi;
}
char **uniqueKelimeleriBul(char *cumleler1[], int cumleSayisi1, char *cumleler2[], int cumleSayisi2, int *uniqueKelimeSayisi)
{
    char **uniqueKelimeler = NULL;
    int toplamUniqueKelimeSayisi = 0;
    int i, j;

    for (i = 0; i < cumleSayisi1; i++)
    {
        char *cumleKopya1 = strdup(cumleler1[i]);
        char *kelime = strtok(cumleKopya1, " ");
        while (kelime != NULL)
        {

            // kelimenin sonunda noktalama varsa kaldýrýr
            char *sonKarakter = strchr(kelime, '\0') - 1;
            if (ispunct(*sonKarakter))
            {
                *sonKarakter = '\0';
            }

            // kelime unique dizinde var mý kontrol eder
            int unique = 1;
            for (j = 0; j < toplamUniqueKelimeSayisi; j++)
            {
                if (strcmp(kelime, uniqueKelimeler[j]) == 0)
                {
                    unique = 0;
                    break;
                }
            }

            // eger kelime unique diziside yoksa yani unique=1 kaldýysa, diziye ekler
            if (unique)
            {
                toplamUniqueKelimeSayisi++;
                uniqueKelimeler = realloc(uniqueKelimeler, toplamUniqueKelimeSayisi * sizeof(char *));
                uniqueKelimeler[toplamUniqueKelimeSayisi - 1] = strdup(kelime);
            }

            // obur kelimeyi al
            kelime = strtok(NULL, " ");
        }
    }

    // ayný islemlerin 2. dosya icin yapýlmasý
    for (i = 0; i < cumleSayisi2; i++)
    {
        char *cumleKopya2 = strdup(cumleler2[i]);
        char *kelime = strtok(cumleKopya2, " ");
        while (kelime != NULL)
        {

            char *sonKarakter = strchr(kelime, '\0') - 1;
            if (ispunct(*sonKarakter))
            {
                *sonKarakter = '\0';
            }

            int unique = 1;
            for (j = 0; j < toplamUniqueKelimeSayisi; j++)
            {
                if (strcmp(kelime, uniqueKelimeler[j]) == 0)
                {
                    unique = 0;
                    break;
                }
            }

            if (unique)
            {
                toplamUniqueKelimeSayisi++;
                uniqueKelimeler = realloc(uniqueKelimeler, toplamUniqueKelimeSayisi * sizeof(char *));
                uniqueKelimeler[toplamUniqueKelimeSayisi - 1] = strdup(kelime);
            }

            kelime = strtok(NULL, " ");
        }
    }

    // yollanan pointera unique kelime sayýsýný yazýyor
    *uniqueKelimeSayisi = toplamUniqueKelimeSayisi;

    return uniqueKelimeler;
}

// iki dosya icin one hot vektor olusturur
int **oneHotVectorOlustur(char *cumleler1[], char *cumleler2[], int cumleSayisi1, int cumleSayisi2, char **uniqueKelimeler, int uniqueKelimeSayisi)
{
    int **oneHotVektorler = NULL;
    int i, j;

    // Her cümle için  one hot vektör
    for (i = 0; i < cumleSayisi1; i++)
    {
        // dinamik bellek alaný ayýr ve sýfýr doldurur
        oneHotVektorler = realloc(oneHotVektorler, (i + 1) * sizeof(int *));
        oneHotVektorler[i] = calloc(uniqueKelimeSayisi, sizeof(int));

        // kelimelere ayýran ksýým
        char *cumleKopya = strdup(cumleler1[i]);
        char *kelime = strtok(cumleKopya, " ");
        while (kelime != NULL)
        {
            // printf("%d %s ", i, kelime);

            char *sonKarakter = strchr(kelime, '\0') - 1;
            if (ispunct(*sonKarakter))
            {
                *sonKarakter = '\0';
            }

            // Kelimeninin unique listesindeki gectigi indexi bul
            int kelimeIndeksi = -1;
            for (j = 0; j < uniqueKelimeSayisi; j++)
            {
                if (strcmp(kelime, uniqueKelimeler[j]) == 0)
                {
                    // printf("%d :%s %s\n", i, kelime, uniqueKelimeler[j]);
                    kelimeIndeksi = j;
                    break;
                }
            }

            //  kelimeyi one hot vektorunde isaretle
            if (kelimeIndeksi != -1)
            {
                oneHotVektorler[i][kelimeIndeksi] = 1;
            }

            // obur kelimeye gec
            kelime = strtok(NULL, " ");
        }
    }

    // 2. dosya icin ayný islemler ,
    // x degiskeni kullandim cunku ayni one hot vektor dizisine eklemek icin
    // i degiskeninin devamýna eklemek gerekiyor
    int x = 0;

    for (x = 0; x < cumleSayisi2; x++)
    {
        oneHotVektorler = realloc(oneHotVektorler, (x + i + 1) * sizeof(int *));
        oneHotVektorler[x + i] = calloc(uniqueKelimeSayisi, sizeof(int));

        char *cumleKopya = strdup(cumleler2[x]);
        char *kelime = strtok(cumleKopya, " ");
        while (kelime != NULL)
        {

            char *sonKarakter = strchr(kelime, '\0') - 1;
            if (ispunct(*sonKarakter))
            {
                *sonKarakter = '\0';
            }

            int kelimeIndeksi = -1;
            for (j = 0; j < uniqueKelimeSayisi; j++)
            {
                if (strcmp(kelime, uniqueKelimeler[j]) == 0)
                {
                    kelimeIndeksi = j;
                    break;
                }
            }

            if (kelimeIndeksi != -1)
            {
                oneHotVektorler[x + i][kelimeIndeksi] = 1;
            }

            kelime = strtok(NULL, " ");
        }
    }

    return oneHotVektorler;
}

