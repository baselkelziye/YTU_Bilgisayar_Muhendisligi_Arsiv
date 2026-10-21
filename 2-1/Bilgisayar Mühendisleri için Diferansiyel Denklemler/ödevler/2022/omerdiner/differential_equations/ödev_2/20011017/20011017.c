#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// a * y' + b * y = g(x)
typedef struct DENKLEM
{
    int y_katsayisi;
    int y_turev_katsayisi;
    int gx_terim_sayisi;
    float *gx_katsayilar;
    int *gx_usler;
} DENKLEM;

void mutlakHatayiYazdir(float gercekDeger, float yaklasikDeger);
void denklemYazdir(DENKLEM *denklem);
float turev(float x, float y, DENKLEM *denklem);
float rungeKutta(float x0, float y0, float x, float h, DENKLEM *denklem);
float gx_hesapla(DENKLEM *denklem, float t);
int main()
{

    int i;
    float x0, y0, h, x_aranan;

    DENKLEM *denklem = (DENKLEM *)malloc(sizeof(DENKLEM));
    printf("1. dereceden diferansiyel denklem icin Runge-Kutta yontemi\n");
    printf("a * y' + b * y = g(x)\n\n");

    printf("y' in katsayisi : ");
    scanf("%d", &denklem->y_turev_katsayisi);
    printf("y nin katsayisi: ");
    scanf("%d", &denklem->y_katsayisi);
    printf("g(x) terim sayisini giriniz: ");
    scanf("%d", &denklem->gx_terim_sayisi);

    denklem->gx_katsayilar = (float *)malloc(denklem->gx_terim_sayisi * sizeof(float));
    denklem->gx_usler = (int *)malloc(denklem->gx_terim_sayisi * sizeof(int));

    for (i = 0; i < denklem->gx_terim_sayisi; i++)
    {
        printf("g(x)'nin %d. teriminin katsayisini giriniz: ", i + 1);
        scanf("%f", &denklem->gx_katsayilar[i]);
        printf("g(x)'nin %d. teriminin ussunu giriniz: ", i + 1);
        scanf("%d", &denklem->gx_usler[i]);
    }

    printf("Alinan denklem: ");
    denklemYazdir(denklem);

    printf("Denklemin cozumu icin ilk degerleri giriniz:\n");
    printf("x0: ");
    scanf("%f", &x0);
    printf("y0: ");
    scanf("%f", &y0);

    printf("Adim uzunlugunu giriniz: ");
    scanf("%f", &h);

    printf("Denklemin hangi noktasindaki degeri bulmak istiyorsunuz: ");
    scanf("%f", &x_aranan);

    // RAPORDA MUTLAK HATAYI GÖSTERMEK ÝÇÝN FONKSÝYONUN ARANAN NOKTADA GERÇEK DEÐERÝNÝN BÝLÝNMESÝ GEREKÝYOR
    // BU KISMIN DÝÐER KISIMLARLA ÝLGÝSÝ YOKTUR, RAPOR ÝÇÝN YAZILMIÞTIR. ÇÖZÜM ÝÇÝN GEREKLÝ DEÐÝLDÝR.
    float gercekDeger;
    printf("Denklemin aranacak noktada gercek degerini giriniz : ");
    scanf("%f", &gercekDeger);

    printf("\n\n");
    float sonuc = rungeKutta(x0, y0, x_aranan, h, denklem);

    printf("y(%f) = %f\n", x_aranan, sonuc);
    printf("Denklemin %f noktasindaki yaklasik degeri: %f\n", x_aranan, sonuc);

    mutlakHatayiYazdir(gercekDeger, sonuc);

    return 0;
}

void denklemYazdir(DENKLEM *denklem)
{
    int i;

    printf("%d*y' + %d*y = ", denklem->y_turev_katsayisi, denklem->y_katsayisi);
    for (i = 0; i < denklem->gx_terim_sayisi - 1; i++)
    {
        printf("( %lf * x^%d )+ ", denklem->gx_katsayilar[i], denklem->gx_usler[i]);
    }
    printf("(%lf * x^%d ) ", denklem->gx_katsayilar[i], denklem->gx_usler[i]);
    printf("\n");
}

float turev(float x, float y, DENKLEM *denklem)
{

    // a * y' + b * y = g(x)
    // y' = (g(x) - b * y) / a
    return (gx_hesapla(denklem, x) - denklem->y_katsayisi * y) / denklem->y_turev_katsayisi;
}

float rungeKutta(float x0, float y0, float x, float h, DENKLEM *denklem)
{

    int i;
    float k1, k2, k3, k4;

    float y = y0;

	//eger girilen x0 aranan x noktasýndan fazlaysa x0 azaltýlarak iterasyonlar yapilmai
    if (x < x0)
    {
        h = -h;
    }
    // adým sayýsý
    int n = (int)((x - x0) / h);

    printf("ITERASYONLAR\n");
    for (i = 0; i < n; i++)
    {

        printf("f(%lf)=%lf\n", x0, y);
        k1 = h * turev(x0, y, denklem);
        k2 = h * turev(x0 + 0.5 * h, y + 0.5 * k1, denklem);
        k3 = h * turev(x0 + 0.5 * h, y + 0.5 * k2, denklem);
        k4 = h * turev(x0 + h, y + k3, denklem);

        y = y + (1 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 = x0 + h;
    }

    return y;
}

float gx_hesapla(DENKLEM *denklem, float t)
{
    int i;
    float sonuc = 0;
    for (i = 0; i < denklem->gx_terim_sayisi; i++)
    {
        sonuc += denklem->gx_katsayilar[i] * pow(t, denklem->gx_usler[i]);
    }
    return sonuc;
}

void mutlakHatayiYazdir(float gercekDeger, float yaklasikDeger)
{
    printf("Mutlak hata: %f\n", fabs(gercekDeger - yaklasikDeger));
}
