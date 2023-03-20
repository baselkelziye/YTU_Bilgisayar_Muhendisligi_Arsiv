#include <stdio.h>
#include <stdlib.h>

int MatrisiOlustur(int **, char[20], int **);
void matrisyazdir(int **, int);
int baglantiEkle(int **, int **, int);
void donguTespit(int **, int **, int);
void matrisiKopyala(int **, int **, int V);
void baglantilariYazdir(int **, int V);
void matrisiAyikla(int **, int);
int main()
{

    int V, i, j;
    int **matris, **kopyaMatris;
    int tmp_Max;
    int src, dest, weight, maxEdge;
    char dosyaIsmi[20];
    int X_Baglanti, Y_Baglanti;
    int selection = 0;

    printf("\nLutfen Dugum Sayisini Giriniz\n");
    scanf(" %d", &V);
    V++;

    matris = (int **)calloc(V, sizeof(int *));
    kopyaMatris = (int **)calloc(V, sizeof(int *));

    for (i = 0; i < V; i++)
    {
        matris[i] = (int *)calloc(V, sizeof(int));
        kopyaMatris[i] = (int *)calloc(V, sizeof(int));
    }

    while (selection != -1)
    {
        printf("\n1->MST'i Olusturun\t\t\t Basel Kelziye 20011906");
        printf("\n2->MST'e Yeni Baglanti Ekle");
        printf("\n3->Bagli Dugumleri Yazdirin");
        printf("\n4-Matris Formatli Graph'i Yazdirin\n");
        scanf(" %d", &selection);

        switch (selection)
        {
        case 1:
            printf("\nLutfen Dosya Ismi Giriniz\n");
            scanf(" %s", dosyaIsmi);
            maxEdge = MatrisiOlustur(matris, dosyaIsmi, kopyaMatris);
            break;
        case 2:
            if (baglantiEkle(matris, kopyaMatris, maxEdge))
            {
                donguTespit(matris, kopyaMatris, V);
                tmp_Max = 0;
                for (i = 0; i < V; i++)
                {
                    for (j = 0; j <= i; j++)
                    {
                        if (kopyaMatris[i][j] > tmp_Max)
                        {
                            tmp_Max = kopyaMatris[i][j];
                            X_Baglanti = i;
                            Y_Baglanti = j;
                        }
                    }
                }
                printf("\nCikarilan Kenarin Agirligi -> %d  (%d,%d) Arasi", tmp_Max, X_Baglanti, Y_Baglanti);
                matris[X_Baglanti][Y_Baglanti] = 0;
                matris[Y_Baglanti][X_Baglanti] = 0;
                matrisiKopyala(matris, kopyaMatris, V);
            }
            break;

        case 3:
            baglantilariYazdir(matris, V);
            break;

        case 4:
            matrisyazdir(matris, V);
            break;

        default:
            break;
        }
    }

    for (i = 0; i < V; i++)
    {
        free(matris[i]);
        free(kopyaMatris[i]);
    }

    free(kopyaMatris);
    free(matris);

    printf("\n");
    return 0;
}

void matrisyazdir(int **matris, int V)
{
    int i, j;
    printf("\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

int MatrisiOlustur(int **matris, char dosyaIsmi[20], int **kopyaMatris)
{

    FILE *fp = fopen(dosyaIsmi, "r");
    int src = 0, dest = 0, weight = 0;
    if (fp == NULL)
    {
        printf("\nHata:Dosya Acilamadi!");
        exit(101);
    }

    while (fscanf(fp, "%d %d %d", &weight, &src, &dest) == 3)
    {
        matris[src][dest] = weight;
        matris[dest][src] = weight;

        kopyaMatris[src][dest] = weight;
        kopyaMatris[dest][src] = weight;
    }
    fclose(fp);
    return weight;
}

int baglantiEkle(int **matris, int **kopyaMatris, int maxBaglanti)
{
    int weight, src, dest;
    printf("\nLutfen sirasiyla agirlik baslangic varis degerlerini giriniz\n");
    scanf(" %d %d %d", &weight, &src, &dest);

    if (weight >= maxBaglanti)
    {
        printf("\nEklediginiz Baglanti Mevcut Baglantidan\nBuyuk Esit oldugu icin MST'e Herhangi Bir Degisiklik Yapilmayacaktir!\n");
        return 0;
    }
    else if (src == dest)
    {
        printf("\nGirdiginiz Degerler Self-loop Yaptigi Icin Ekleme Yapilmayacaktir!");
        return 0;
    }
    else
    {
        matris[src][dest] = weight;
        matris[dest][src] = weight;

        kopyaMatris[src][dest] = weight;
        kopyaMatris[dest][src] = weight;
        printf("\nEkleme Basarili Bir sekilde Gerceklesmistir!");
        return 1;
    }
}

void donguTespit(int **matris, int **kopyaMatris, int V)
{

    matrisiAyikla(kopyaMatris, V);
    matrisiAyikla(kopyaMatris, V);
    matrisiAyikla(kopyaMatris, V);
    matrisiAyikla(kopyaMatris, V);
    matrisiAyikla(kopyaMatris, V);
}

void matrisiKopyala(int **matris, int **kopyaMatris, int V)
{
    int i, j;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            kopyaMatris[i][j] = matris[i][j];
        }
    }
}

void baglantilariYazdir(int **matris, int V)
{
    int i, j, totalWeight = 0;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (matris[i][j] != 0)
            {
                printf("\n[%d,%d] -----> %d", i, j, matris[i][j]);
                totalWeight = totalWeight + matris[i][j];
            }
        }
    }
    printf("\nMST'nin Agirligi: %d\n", totalWeight);
}

void matrisiAyikla(int **kopyaMatris, int V)
{
    int count, X_Dugum, Y_Dugum;
    int i, j;

    for (j = 0; j < V; j++)
    {
        for (i = 0; i < V; i++)
        {

            if (kopyaMatris[i][j] != 0)
            {
                count++;
                X_Dugum = i;
                Y_Dugum = j;
            }
        }
        if (count == 1)
        {
            kopyaMatris[X_Dugum][Y_Dugum] = 0;
            kopyaMatris[Y_Dugum][X_Dugum] = 0;
        }
        count = 0;
    }
}