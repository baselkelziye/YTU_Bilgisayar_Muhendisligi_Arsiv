#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char uyelikTipi;
    char *isim;
} KULLANICI;

void oku(KULLANICI **k, int n);
void yaz(KULLANICI **k, int n);
void sirala(KULLANICI **db, int n);
void freeKullanicilar(KULLANICI **k, int n);

int main()
{
    int n;
    printf("Eleman sayisi:");
    scanf("%d", &n);
    KULLANICI **kullanicilar = (KULLANICI **)malloc(n * sizeof(KULLANICI *));
    oku(kullanicilar, n);
    printf("Orjinal hali:\n");
    yaz(kullanicilar, n);
    sirala(kullanicilar, n);
    printf("Siralanmis hali:\n");
    yaz(kullanicilar, n);
    freeKullanicilar(kullanicilar, n);
    return 0;
}

void oku(KULLANICI **k, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        k[i] = (KULLANICI *)malloc(sizeof(KULLANICI));
        k[i]->isim = (char *)malloc(20 * sizeof(char));
        printf("id, uyelikTipi, isim:");
        scanf("%d %c %s", &k[i]->id, &k[i]->uyelikTipi, k[i]->isim);
    }
}
void yaz(KULLANICI **k, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d %c %s \n", k[i]->id, k[i]->uyelikTipi, k[i]->isim);
    }
}
void sirala(KULLANICI **db, int n)
{
    int i, j;
    KULLANICI *tmp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (db[j]->uyelikTipi > db[j + 1]->uyelikTipi)
            {
                tmp = db[j];
                db[j] = db[j + 1];
                db[j + 1] = tmp;
            }
            else if (db[j]->uyelikTipi == db[j + 1]->uyelikTipi)
            {
                if (strcmp(db[j]->isim, db[j + 1]->isim) > 0)
                {
                    tmp = db[j];
                    db[j] = db[j + 1];
                    db[j + 1] = tmp;
                }
            }
        }
    }
}
void freeKullanicilar(KULLANICI **k, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        free(k[i]->isim);
        free(k[i]);
    }
    free(k);
}
