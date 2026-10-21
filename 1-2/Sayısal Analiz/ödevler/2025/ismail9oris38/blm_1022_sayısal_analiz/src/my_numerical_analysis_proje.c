#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define E 2.7182818
#define PI 3.1415926

float cot(float x)
{
	return 1.0 / tan(x);
}

float acot(float x)
{
	return atan(1.0 / x);
}

typedef struct
{
	char type;
	char value[20];
} Token;

void scanfMatrix(float **mtr, int N);
void printMatrix(float **mtr, int N);
void matrixDinamikYapma(float ***mtr, int N);
void freematrix(float **mtr, int N);
float **matris_tersini_alma(float **mtr, int N);
float *cholesky_yöntemi(float **mtr, int N, float *değer_mtr);
void L_U_ayırma(float **mtr, int N, float **L_mtr, float **U_mtr);
float *Y_bulma(float **L_mtr, int N, float *değer_mtr);
float *X_bulma(float **U_mtr, int N, float *y_mtr);
void gauss_seidel_yöntemi(float **mtr, float *değer_mtr, int N, float *başlangıç_değerler, float hata_oranı);
void diyagonel_mtr(float **mtr, int N, float *değer_mtr);
Token *fonksiyon_token(char *fonk, float x, int *token_count_ptr);
int precedence(Token token);
Token *token_ayırma_ve_postfix(char *fonk, float x, int *postfix_count);
float postfix_sonuc(Token *postfix, int count);
float fonksiyon_hesap(char *fonk, float x);
float bisection(char *fonk, float start, float end, float epsilon, int iterat);
float regula_falsi(char *fonk, float start, float end, float epsilon, int iterat);
float newton_raphson(char *fonk, float x0, float hata_payı, int iterasyon);
float geri_farklar_ile_sayısal_türev(char *fonk, float nokta, float h);
float ileri_farklar_ile_sayısal_türev(char *fonk, float nokta, float h);
float merkezi_farklar_ile_sayısal_türev(char *fonk, float nokta, float h);
float trapez_yöntemi(char *fonk, float start, float end, int n);
float simson_yöntemi_1_3(char *fonk, float start, float end, int n);
float simson_yöntemi_3_8(char *fonk, float start, float end, int n);
float gregory_Newton_enterpolasyon(float *x_dizi, float *y_dizi, int derece, float x);

int main(void)
{
    int i, j, quit = 1, choice; // quit: programdan çıkış kontrolü, choice: kullanıcı seçimi

    while (quit) // Program kullanıcı çıkmak isteyene kadar çalışır
    {
        // Ana menüyü göster
        printf("\n---------------------------------------------------------------------------------------\n");
        printf("Çıkış: 0\n");
        printf("Bisection Yöntemi: 1\n");
        printf("Regula-Falsi Yöntemi: 2\n");
        printf("Newton-Raphson Yöntemi: 3\n");
        printf("Matris Tersi Alma: 4\n");
        printf("Cholesky Ayrıştırma Yöntemi: 5\n");
        printf("Gauss-Seidel Yöntemi: 6\n");
        printf("Sayısal Türev: 7\n");
        printf("Simpson Kuralı ile İntegral: 8\n");
        printf("Trapez Kuralı ile İntegral: 9\n");
        printf("Gregory-Newton Enterpolasyonu: 10\n");
        printf("Seçiminizi giriniz: ");
        scanf("%d", &choice);

        // Matris işlemleri (4,5,6)
        if (choice == 4 || choice == 5 || choice == 6)
        {
            int N, i, j;
            float **mtr; // Matris için çift pointer
            
            printf("\nMatris boyutunu girin: ");
            scanf("%d", &N);

            matrixDinamikYapma(&mtr, N); // Matris için bellek ayırma
            scanfMatrix(mtr, N); // Matris elemanlarını kullanıcıdan alma

            printf("\nGirilen Matris: [");
            printMatrix(mtr, N); // Matrisi yazdırma
            printf("\n]");

            // Matris tersini alma işlemi
            if (choice == 4)
            {
                float **mtr_ters;

                mtr_ters = matris_tersini_alma(mtr, N);

                if (mtr_ters == NULL)
                {
                    printf("\nBu matrisin tersi bulunmamaktadır.\n");
                }
                else
                {
                    printf("\nMatrisin Tersi: [");
                    printMatrix(mtr_ters, N);
                    printf("\n]");

                    freematrix(mtr_ters, N); // Bellek temizleme 
                }
            }
            // Cholesky yöntemi ile çözüm
            else if (choice == 5)
            {
                float *değer_mtr, *çözüm_mtr;
                değer_mtr = (float *)malloc(sizeof(float) * N);
                printf("\nDenklem sisteminin sağ taraf değerlerini girin (değer matrisi):\n");
                for (i = 0; i < N; i++)
                {
                    scanf("%f", değer_mtr + i);
                }
                çözüm_mtr = cholesky_yöntemi(mtr, N, değer_mtr);
                printf("\nDenklem sisteminin çözümü: \n");
                for (i = 0; i < N; i++)
                {
                    printf("x%d = %f\n", i+1, çözüm_mtr[i]);
                }
                free(değer_mtr);
                free(çözüm_mtr);
            }
            // Gauss-Seidel yöntemi ile çözüm
            else
            {
                float *başlangıç_değerler, *değer_mtr, hata_oranı;
                değer_mtr = (float *)malloc(sizeof(float) * N);
                başlangıç_değerler = (float *)malloc(sizeof(float) * N);

                printf("\nDenklem sisteminin sağ taraf değerlerini girin (değer matrisi):\n");
                for (i = 0; i < N; i++)
                {
                    scanf("%f", değer_mtr + i);
                }

                printf("\nBaşlangıç değerlerini girin: \n");
                for (i = 0; i < N; i++)
                {
                    printf("x%d için başlangıç değeri: ", i+1);
                    scanf("%f", &başlangıç_değerler[i]);
                }

                printf("\nKabul edilebilir hata oranını girin: ");
                scanf("%f", &hata_oranı);

                gauss_seidel_yöntemi(mtr, değer_mtr, N, başlangıç_değerler, hata_oranı);

                printf("\n\nDenklem sisteminin çözümü:\n");
                for (i = 0; i < N; i++)
                {
                    printf("x%d = %f\n", i+1, başlangıç_değerler[i]);
                }
                free(başlangıç_değerler);
                free(değer_mtr);
            }

            freematrix(mtr, N); // Matris belleğini temizle
        }
        // Gregory-Newton enterpolasyonu
        else if (choice == 10)
        {
            int derece, i;
            float result, x;
            float *x_dizi, *y_dizi;
            printf("\nEnterpolasyon yapılacak polinomun derecesini girin: ");
            scanf("%d", &derece);
            derece += 1; // n+1 nokta gerekli
            x_dizi = (float *)malloc(sizeof(float) * derece);
            y_dizi = (float *)malloc(sizeof(float) * derece);
            printf("\nPolinomun bilinen noktalarını girin (x'leri küçükten büyüğe sıralayarak): \n");
            for (i = 0; i < derece; i++)
            {
                printf("%d. noktanın x ve y değerlerini girin (x y): ", i + 1);
                scanf("%f %f", &x_dizi[i], &y_dizi[i]);
            }
            printf("\nHangi x değeri için enterpolasyon yapmak istiyorsunuz: ");
            scanf("%f", &x);
            result = gregory_Newton_enterpolasyon(x_dizi, y_dizi, derece, x);
            printf("\nSonuç: f(%f) = %f\n", x, result);
            free(x_dizi);
            free(y_dizi);
        }
        // Diğer sayısal yöntemler
        else if( choice == 1 || choice == 2 || choice == 3 || choice == 7 || choice == 8 || choice == 9 )
        {
            char *fonk = (char *)malloc(sizeof(char) * 1000); // Fonksiyon için bellek ayır
            printf("\nLütfen fonksiyonu giriniz (örnek: x^2 + log_(sin(5 * x))(x - 5) ): \n");
            scanf(" %[^\n]", fonk);

            // Kök bulma yöntemleri (1,2,3)
            if (choice == 1 || choice == 2)
            {
                float start, end, mid, epsilon;
                int iterat;
                float result;

                printf("\nAralık başlangıcını girin: ");
                scanf("%f", &start);
                printf("\nAralık bitişini girin: ");
                scanf("%f", &end);
                printf("\nKabul edilebilir hata payını girin (epsilon): ");
                scanf("%f", &epsilon);
                printf("\nMaksimum iterasyon sayısını girin: ");
                scanf("%d", &iterat);

                if (choice == 1)
                {
                    result = bisection(fonk, start, end, epsilon, iterat);
                    printf("\nBulunan kök: %f\n", result);
                }
                else
                {
                    result = regula_falsi(fonk, start, end, epsilon, iterat);
                    printf("\nBulunan kök: %f\n", result);
                }
            }
            // Newton-Raphson yöntemi
            if (choice == 3)
            {
                float x0, epsilon;
                int iterat;
                float result;

                printf("\nBaşlangıç değerini girin (x0): ");
                scanf("%f", &x0);
                printf("\nKabul edilebilir hata payını girin (epsilon): ");
                scanf("%f", &epsilon);
                printf("\nMaksimum iterasyon sayısını girin: ");
                scanf("%d", &iterat);

                result = newton_raphson(fonk, x0, epsilon, iterat);

                printf("\nBulunan kök: %f\n", result);
            }
            // Sayısal türev
            if (choice == 7)
            {
                float h, nokta, ileri, geri, merkezi;

                printf("\nTürev alınacak noktayı girin: ");
                scanf("%f", &nokta);

                printf("\nAdım boyutunu girin (h): ");
                scanf("%f", &h);

                geri = geri_farklar_ile_sayısal_türev(fonk, nokta, h);
                ileri = ileri_farklar_ile_sayısal_türev(fonk, nokta, h);
                merkezi = merkezi_farklar_ile_sayısal_türev(fonk, nokta, h);
                printf("\nGeri fark yöntemi ile türev sonucu: %f", geri);
                printf("\nİleri fark yöntemi ile türev sonucu: %f", ileri);
                printf("\nMerkezi fark yöntemi ile türev sonucu: %f\n", merkezi);
            }
            // Sayısal integral
            if (choice == 8 || choice == 9)
            {
                float start, end, result;
                int n;

                printf("\nİntegral alt sınırını girin: ");
                scanf("%f", &start);
                printf("\nİntegral üst sınırını girin: ");
                scanf("%f", &end);
                printf("\nBölme sayısını girin (n): ");
                scanf("%d", &n);

                if (choice == 8)
                {
                    while (n % 6 != 0) 
                    {
                        printf("\nn değeriniz hem çift (simpson 1/3 den kaynaklı) hemde 3 ün katı (simpson3/8 den kaynaklı) olmalı lütfen tekrar giriniz...");
                        printf("\nBölme sayısını girin (n): ");
                        scanf("%d", &n);
                    }
                    
                    result = simson_yöntemi_1_3(fonk, start, end, n);
                    printf("\nSimpson 1/3 kuralı ile integral sonucu: %f\n", result);
                    result = simson_yöntemi_3_8(fonk, start, end, n);
                    printf("\nSimpson 3/8 kuralı ile integral sonucu: %f\n", result);
                }
                else
                {
                    result = trapez_yöntemi(fonk, start, end, n);
                    printf("\nTrapez kuralı ile integral sonucu: %f\n", result);
                }
            }
            free(fonk); // Fonksiyon için ayrılan belleği temizle
        }
        else {
            quit = 0;
        }
        
    }
    printf("\nProgram sona ermiştir...");
    return 0;
}

//kullanıcıdan matris alam fonksiyonu
void scanfMatrix(float **mtr, int N)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("[%d][%d]: ", i, j);
			scanf("%f", &mtr[i][j]);
		}
	}
}

//matrisi yazdırma fonksiyonu
void printMatrix(float **mtr, int N)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		printf("\n");
		for (j = 0; j < N; j++)
		{
			printf("%f  ", mtr[i][j]);
		}
	}
	printf("\n");
}

//matrisi dianmik hale getirme fonksiyonu
void matrixDinamikYapma(float ***mtr, int N)
{
	int i;

	*mtr = (float **)calloc(N, sizeof(float *));
	for (i = 0; i < N; i++)
	{
		(*mtr)[i] = (float *)calloc(N, sizeof(float));
	}
}

//matrisi belleğini temizleme fonksiyonu
void freematrix(float **mtr, int N)
{
	int i;
	for (i = 0; i < N; i++)
	{
		free(mtr[i]);
	}
	free(mtr);
}

//matrisin tersini alma fonksiyonu
float **matris_tersini_alma(float **mtr, int N)
{
    int i, j, k;
    float tmp, başlangıç_değer, **mtr_ters;

    // Ters matris için bellek ayırma
    matrixDinamikYapma(&mtr_ters, N);

    // Birim matris oluşturma (ters matrisin başlangıç değeri)
    for (i = 0; i < N; i++)
    {
        *(*(mtr_ters + i) + i) = 1; // Köşegen elemanları 1 yap
    }

    // Gauss-Jordan eliminasyon yöntemi uygulama
    for (i = 0; i < N; i++)
    {
        // Köşegen eleman sıfır kontrolü
        if (*(*(mtr + i) + i) == 0)
        {
            j = i + 1;
            // Sıfır olmayan satır bulma
            while (j < N && *(*(mtr + j) + i) == 0)
                j++;

            // Eğer tüm sütun sıfırsa matris tersinir değildir
            if (j == N)
            {
                freematrix(mtr_ters, N); // Belleği temizle
                return NULL;             // Ters matris yok
            }
            else
            {
                // Satırları değiştirme (pivoting)
                for (k = i; k < N; k++)
                {
                    tmp = *(*(mtr + i) + k);
                    *(*(mtr + i) + k) = *(*(mtr + j) + k);
                    *(*(mtr + j) + k) = tmp;
                }

                // Ters matris için de satır değiştirme
                for (k = 0; k < N; k++)
                {
                    tmp = *(*(mtr_ters + i) + k);
                    *(*(mtr_ters + i) + k) = *(*(mtr_ters + j) + k);
                    *(*(mtr_ters + j) + k) = tmp;
                }
            }
        }

        // Köşegen elemanı 1 yapma işlemi
        başlangıç_değer = *(*(mtr + i) + i);

        // Mevcut satırı köşegen elemana bölme
        for (j = i; j < N; j++)
        {
            *(*(mtr + i) + j) /= başlangıç_değer;
        }

        // Ters matris satırını da aynı şekilde güncelleme
        for (j = 0; j < N; j++)
        {
            *(*(mtr_ters + i) + j) /= başlangıç_değer;
        }

        // Alt üçgen elemanları sıfırlama (ileri eliminasyon)
        for (j = i + 1; j < N; j++)
        {
            if (*(*(mtr + j) + i) != 0)
            {
                başlangıç_değer = *(*(mtr + j) + i);

                // Temel satır işlemleri
                for (k = i; k < N; k++)
                {
                    *(*(mtr + j) + k) -= başlangıç_değer * *(*(mtr + i) + k);
                }

                // Ters matris için de aynı işlem
                for (k = 0; k < N; k++)
                {
                    *(*(mtr_ters + j) + k) -= başlangıç_değer * *(*(mtr_ters + i) + k);
                }
            }
        }

        // Üst üçgen elemanları sıfırlama (geri eliminasyon)
        for (j = i - 1; j >= 0; j--)
        {
            if (*(*(mtr + j) + i) != 0)
            {
                başlangıç_değer = *(*(mtr + j) + i);

                // Temel satır işlemleri
                for (k = i; k < N; k++)
                {
                    *(*(mtr + j) + k) -= başlangıç_değer * *(*(mtr + i) + k);
                }

                // Ters matris için de aynı işlem
                for (k = 0; k < N; k++)
                {
                    *(*(mtr_ters + j) + k) -= başlangıç_değer * *(*(mtr_ters + i) + k);
                }
            }
        }
    }
    return mtr_ters; // Hesaplanan ters matrisi döndür
}

// Cholesky ayrıştırma yöntemi ile denklem sistemini çözen ana fonksiyon
float *cholesky_yöntemi(float **mtr, int N, float *değer_mtr)
{
    float **U_mtr, **L_mtr;  // Üst ve alt üçgen matrisler
    float *y_mtr, *x_mtr;     // Ara çözüm vektörleri

    // Matrisler için bellek ayırma
    matrixDinamikYapma(&U_mtr, N);
    matrixDinamikYapma(&L_mtr, N);

    // 1. Adım: Matrisi alt (L) ve üst (U) üçgen matrislere ayırma
    L_U_ayırma(mtr, N, L_mtr, U_mtr);
    
    // 2. Adım: Ly = b denklemini çözerek y vektörünü bulma
    y_mtr = Y_bulma(L_mtr, N, değer_mtr);
    
    // 3. Adım: Ux = y denklemini çözerek x vektörünü bulma
    x_mtr = X_bulma(U_mtr, N, y_mtr);

    // Bellek temizleme
    freematrix(U_mtr, N);
    freematrix(L_mtr, N);
    free(y_mtr);

    return x_mtr;  // Sonuç vektörünü döndür
}

// Matrisi alt (L) ve üst (U) üçgen matrislere ayırma fonksiyonu
void L_U_ayırma(float **mtr, int N, float **L_mtr, float **U_mtr)
{
    int i, j, k;
    float temp;

    // İlk köşegen elemanı ayarlama
    L_mtr[0][0] = mtr[0][0];
    
    // Üst üçgen matrisin köşegenini 1 yapma
    for (i = 0; i < N; i++)
    {
        U_mtr[i][i] = 1;

        // Alt üçgen matris (L) hesaplama
        for (j = i; j < N; j++)
        {
            temp = 0;
            // L[j][i] hesaplama
            for (k = 0; k < i; k++)
            {
                temp += L_mtr[j][k] * U_mtr[k][i];
            }
            L_mtr[j][i] = mtr[j][i] - temp;

            // Üst üçgen matris (U) hesaplama (i != j durumu)
            if (i != j)
            {
                temp = 0;
                // U[i][j] hesaplama
                for (k = 0; k < j; k++)
                {
                    temp += L_mtr[i][k] * U_mtr[k][j];
                }
                U_mtr[i][j] = (mtr[i][j] - temp) / L_mtr[i][i];
            }
        }
    }
    
    // Hata ayıklama için matrisleri yazdır
    printf("\nAlt Üçgen Matris (L):\n");
    printMatrix(L_mtr, N);
    printf("\nÜst Üçgen Matris (U):\n");
    printMatrix(U_mtr, N);
}

// Ly = b denklem sistemini çözerek y vektörünü bulan fonksiyon
float *Y_bulma(float **L_mtr, int N, float *değer_mtr)
{
    int i, j;
    float temp;
    float *y_mtr = (float *)malloc(sizeof(float) * N);  // Sonuç vektörü

    // İleri yerine koyma yöntemi
    for (i = 0; i < N; i++)
    {
        temp = 0;
        // Önceki değerlerin katkısını hesapla
        for (j = 0; j < i; j++)
        {
            temp += y_mtr[j] * L_mtr[i][j];
        }
        // y[i] değerini hesapla
        y_mtr[i] = (değer_mtr[i] - temp) / L_mtr[i][i];
    }
    return y_mtr;
}

// Ux = y denklem sistemini çözerek x vektörünü bulan fonksiyon
float *X_bulma(float **U_mtr, int N, float *y_mtr)
{
    int i, j;
    float temp;
    float *x_mtr = (float *)malloc(sizeof(float) * N);  // Sonuç vektörü

    // Geriye doğru yerine koyma yöntemi
    for (i = N - 1; i >= 0; i--)
    {
        temp = 0;
        // Sonraki değerlerin katkısını hesapla
        for (j = i + 1; j < N; j++)
        {
            temp += x_mtr[j] * U_mtr[i][j];
        }
        // x[i] değerini hesapla
        x_mtr[i] = (y_mtr[i] - temp) / U_mtr[i][i];
    }
    return x_mtr;
}

// Gauss-Seidel yöntemi ile lineer denklem sistemini çözen fonksiyon
void gauss_seidel_yöntemi(float **mtr, float *değer_mtr, int N, float *başlangıç_değerler, float hata_oranı)
{
    int i, j, tmp, iterasyon_numarası = 0;
    float *sonuç_değerler, *önceki_değer_tut; // Geçici değerler için bellek

    // Bellek ayırma
    sonuç_değerler = (float *)malloc(sizeof(float) * N);
    önceki_değer_tut = (float *)malloc(sizeof(float) * N);

    // Matrisin diyagonal dominant hale getirilmesi
    diyagonel_mtr(mtr, N, değer_mtr);

    // İterasyon döngüsü
    do
    {
        // Önceki değerleri saklama
        for (i = 0; i < N; i++)
        {
            önceki_değer_tut[i] = başlangıç_değerler[i];
        }

        // Her denklem için Gauss-Seidel güncellemesi
        for (i = 0; i < N; i++)
        {
            sonuç_değerler[i] = değer_mtr[i]; // Sağ taraf değerini başlangıç noktası olarak al
            
            // Diğer değişkenlerin katkılarını çıkarma
            for (j = 0; j < N; j++)
            {
                if (j != i) // Köşegen eleman hariç
                {
                    sonuç_değerler[i] -= mtr[i][j] * başlangıç_değerler[j];
                }
            }
            
            // Köşegen elemana bölerek yeni değeri hesapla
            sonuç_değerler[i] /= mtr[i][i];
            başlangıç_değerler[i] = sonuç_değerler[i]; // Hemen güncelle (Gauss-Seidel'in özelliği)
        }

        // Hata kontrolü
        tmp = 0; // Döngü kontrol değişkeni
        for (i = 0; i < N; i++)
        {
            // Eğer bir değişkende hata payından fazla değişim varsa
            if (fabs(önceki_değer_tut[i] - başlangıç_değerler[i]) > hata_oranı)
            {
                tmp = 1; // İterasyona devam et
            }
        }

        // İterasyon sonuçlarını yazdır
        printf("\n%d. Iterasyon Sonuçları:\n", iterasyon_numarası + 1);
        for (i = 0; i < N; i++)
        {
            printf("x%d = %f\n", i+1, başlangıç_değerler[i]);
        }
        iterasyon_numarası++;

    } while (tmp); // Hata payı altına inene kadar devam et

    // Bellek temizleme
    free(sonuç_değerler);
    free(önceki_değer_tut);
}

// Matrisi diyagonal dominant hale getiren yardımcı fonksiyon
void diyagonel_mtr(float **mtr, int N, float *değer_mtr)
{
    int i, j, büyük;
    float **mtr_kopya;
    float *değer_mtr_copy;

    // Geçici matrisler için bellek ayırma
    matrixDinamikYapma(&mtr_kopya, N);
    değer_mtr_copy = (float *)calloc(N, sizeof(float));

    // Her satır için en büyük elemanı bulma ve satırları yeniden düzenleme
    for (i = 0; i < N; i++)
    {
        büyük = 0; // En büyük elemanın indeksi
        for (j = 0; j < N; j++)
        {
            if (*(*(mtr + i) + j) > *(*(mtr + i) + büyük))
            {
                büyük = j;
            }
        }
        
        // Satırı yeni konumuna kopyala
        for (j = 0; j < N; j++)
        {
            *(*(mtr_kopya + büyük) + j) = *(*(mtr + i) + j);
        }
        *(değer_mtr_copy + büyük) = *(değer_mtr + i);
    }

    // Kopyalanmış matrisi orijinaline geri aktarma
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            *(*(mtr + i) + j) = *(*(mtr_kopya + i) + j);
        }
        değer_mtr[i] = değer_mtr_copy[i];
    }

    // Geçici bellek alanlarını temizle
    freematrix(mtr_kopya, N);
    free(değer_mtr_copy);
}

// Matematiksel ifadeyi tokenlara ayırma fonksiyonu
Token *fonksiyon_token(char *s, float x, int *token_count_ptr)
{
    Token *token = (Token *)malloc(sizeof(Token) * 1000); // Tokenlar için bellek ayırma
    int token_count = 0;
    int value_count;

    // Özel değerlerin string karşılıklarını oluşturma
    char *x_value = (char *)malloc(sizeof(char) * 20);
    sprintf(x_value, "%f", x);
    char *pi_value = (char *)malloc(sizeof(char) * 20);
    sprintf(pi_value, "%f", PI);
    char *e_value = (char *)malloc(sizeof(char) * 20);
    sprintf(e_value, "%f", E);

    int i = 0;
    while (s[i] != '\0') // String sonuna kadar dön
    {
        // Operatör kontrolü
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            if (s[i] == '-' && (token_count == 0 || s[i - 1] == '(') ) {
                token[token_count].value[0] = '0';
                token[token_count].value[1] = '\0';
                token[token_count++].type = 'n';
            }
            token[token_count].value[0] = s[i];
            token[token_count].value[1] = '\0';
            token[token_count++].type = 'o'; // 'o' = operator
        }
        // Parantez kontrolü
        else if (s[i] == '(' || s[i] == ')')
        {
            token[token_count].value[0] = s[i];
            token[token_count].value[1] = '\0';
            token[token_count++].type = 'p'; // 'p' = parantez
        }
        // Değişken ve sabitler
        else if (s[i] == 'x') // x değişkeni
        {
            strcpy(token[token_count].value, x_value);
            token[token_count++].type = 'n'; // 'n' = number
        }
        else if (s[i] == 'e') // e sabiti
        {
            strcpy(token[token_count].value, e_value);
            token[token_count++].type = 'n';
        }
        else if (s[i] == 'p' && s[i + 1] == 'i') // pi sabiti
        {
            strcpy(token[token_count].value, pi_value);
            token[token_count++].type = 'n';
            i++; // Bir sonraki karakteri atla ('i')
        }
        // Sayısal değerler (0-9 ve .)
        else if ((s[i] - '0' < 10 && s[i] - '0' >= 0) || s[i] == '.')
        {
            value_count = 0;
            while ((s[i] - '0' < 10 && s[i] - '0' >= 0) || s[i] == '.')
            {
                token[token_count].value[value_count++] = s[i++];
            }
            token[token_count].value[value_count] = '\0';
            token[token_count++].type = 'n';
            i--; // Fazladan artan i değerini azalt
        }
        // Fonksiyon isimleri (sin, cos, log vb.)
        else if (isalpha(s[i]) || s[i] == '_')
        {
            value_count = 0;
            while ((isalpha(s[i]) || s[i] == '_') && s[i] != 'x')
            {
                token[token_count].value[value_count++] = s[i++];
            }
            token[token_count].value[value_count] = '\0';
            token[token_count++].type = 'f'; // 'f' = function
            i--; // Fazladan artan i değerini azalt
        }
        i++;
    }
    
    // Sonuçları ayarla ve temizlik yap
    *token_count_ptr = token_count;
    free(x_value);
    free(pi_value);
    free(e_value);
    return token;
}

// Operatör öncelik seviyesini belirleme fonksiyonu
int precedence(Token token)
{
    if (token.value[0] == '^') // Üs alma en yüksek öncelik
        return 3;
    else if (token.value[0] == '*' || token.value[0] == '/') // Çarpma ve bölme
        return 2;
    else if (token.value[0] == '+' || token.value[0] == '-') // Toplama ve çıkarma
        return 1;
    else if (token.type == 'f') // Fonksiyonlar
        return 4;
    return 0; // Diğer durumlar
}

// Tokenları ayırıp postfix notasyonuna çeviren fonksiyon
Token *token_ayırma_ve_postfix(char *s, float x, int *postfix_count)
{
    int token_count, stack_count = 0, output_count = 0;
    int i;
    Token *stack = (Token *)malloc(sizeof(Token) * 1000); // Stack için bellek
    Token *output = (Token *)malloc(sizeof(Token) * 1000); // Çıktı için bellek
    Token *token = fonksiyon_token(s, x, &token_count); // Tokenlara ayır

    // Shunting-yard algoritması uygulama
    for (i = 0; i < token_count; i++)
    {
        // Sayısal değerler doğrudan çıktıya
        if (token[i].type == 'n')
        {
            output[output_count++] = token[i];
        }
        // Parantez işlemleri
        else if (token[i].type == 'p')
        {
            if (token[i].value[0] == '(') // Açık parantez stack'e ekle
            {
                stack[stack_count++] = token[i];
            }
            else // Kapalı parantez için stack'ten çıkar
            {
                while (stack_count > 0 && stack[stack_count - 1].value[0] != '(')
                {
                    output[output_count++] = stack[--stack_count];
                }
                stack_count--; // Açık parantezi stack'ten çıkar
            }
        }
        // Operatör işlemleri
        else if (token[i].type == 'o')
        {
            // Yüksek öncelikli operatörleri çıktıya al
            while (stack_count > 0 && precedence(stack[stack_count - 1]) >= precedence(token[i]))
            {
                output[output_count++] = stack[--stack_count];
            }
            stack[stack_count++] = token[i]; // Operatörü stack'e ekle
        }
        // Fonksiyonlar stack'e eklenir
        else if (token[i].type == 'f')
        {
            stack[stack_count++] = token[i];
        }
    }

    // Stack'te kalan tüm elemanları çıktıya al
    while (stack_count > 0)
    {
        output[output_count++] = stack[--stack_count];
    }

    *postfix_count = output_count;

    // Bellek temizliği
    free(token);
    free(stack);
    return output;
}

// Postfix notasyonundaki ifadeyi hesaplama fonksiyonu
float postfix_sonuc(Token *postfix, int count)
{
    float stack[100]; // Hesaplama stack'i
    int top = -1, i; // Stack indeksi
    float val, first, second; // Ara değerler

    for (i = 0; i < count; i++)
    {
        // Sayısal değerleri stack'e ekle
        if (postfix[i].type == 'n')
        {
            stack[++top] = atof(postfix[i].value);
        }
        // Özel log fonksiyonu (log tabanına göre)
        else if (postfix[i].type == 'f' && strcmp(postfix[i].value, "log_") == 0)
        {
            second = stack[top--]; // Taban
            first = stack[top--];  // Sayı
            stack[++top] = log(second) / log(first); // log_ilk(ikinci)
        }
        // Diğer fonksiyonlar
        else if (postfix[i].type == 'f')
        {
            val = stack[top--]; // Fonksiyon parametresi
            if (strcmp(postfix[i].value, "sin") == 0)
                stack[++top] = sin(val);
            else if (strcmp(postfix[i].value, "cos") == 0)
                stack[++top] = cos(val);
            else if (strcmp(postfix[i].value, "tan") == 0)
                stack[++top] = tan(val);
            else if (strcmp(postfix[i].value, "cot") == 0)
                stack[++top] = 1.0/tan(val); // cot = 1/tan
            else if (strcmp(postfix[i].value, "arcsin") == 0)
                stack[++top] = asin(val);
            else if (strcmp(postfix[i].value, "arccos") == 0)
                stack[++top] = acos(val);
            else if (strcmp(postfix[i].value, "arctan") == 0)
                stack[++top] = atan(val);
            else if (strcmp(postfix[i].value, "arccot") == 0)
                stack[++top] = atan(1.0/val); // arccot(x) = arctan(1/x)
            else if (strcmp(postfix[i].value, "ln") == 0)
                stack[++top] = log(val);
        }
        // Operatör işlemleri
        else if (postfix[i].type == 'o')
        {
            second = stack[top--];
            first = stack[top--];
            if (postfix[i].value[0] == '+')
                stack[++top] = first + second;
            else if (postfix[i].value[0] == '-')
                stack[++top] = first - second;
            else if (postfix[i].value[0] == '*')
                stack[++top] = first * second;
            else if (postfix[i].value[0] == '/')
                stack[++top] = first / second;
            else if (postfix[i].value[0] == '^')
                stack[++top] = powf(first, second);
        }
    }
    return stack[top]; // Sonuç stack'in en üstünde
}

// Ana fonksiyon hesaplama fonksiyonu
float fonksiyon_hesap(char *s, float x)
{
    int postfix_count;
    // İfadeyi postfix'e çevir
    Token *postfix = token_ayırma_ve_postfix(s, x, &postfix_count);

    // Postfix ifadeyi hesapla
    float result = postfix_sonuc(postfix, postfix_count);

    free(postfix); // Bellek temizle
    return result;
}

// Verilen fonksiyonun belirli bir x noktasındaki yaklaşık türevini hesaplar
float fonksiyon_türev(char *fonk, float x)
{
	// Türev yaklaşık olarak merkezli fark yöntemiyle hesaplanır
	float h = 0.0001;
    return (fonksiyon_hesap(fonk, x + h) - fonksiyon_hesap(fonk, x - h)) / (2 * h);
}

// Bisection (ikiye bölme) yöntemi ile kök bulma algoritması
float bisection(char *fonk, float start, float end, float epsilon, int iterat)
{
	float hata, mid, tmp, önceki_hata;
	int i = 1;
	do
	{
		önceki_hata = mid;                 // Bir önceki orta nokta değeri hatayı hesaplamak için saklanır
		mid = (start + end) / 2;           // Orta nokta hesaplanır
		hata = mid;                        // Hata, şimdilik orta nokta olarak tanımlanır

		// Bilgiler ekrana yazdırılır
		printf("\n");
		printf("Başlangıç noktası  : %f\n", start);
		printf("Bitiş noktası      : %f\n", end);
		printf("Orta nokta         : %f\n", mid);
		printf("f(Başlangıç)       : %f\n", fonksiyon_hesap(fonk, start));
		printf("f(Bitiş)           : %f\n", fonksiyon_hesap(fonk, end));
		printf("f(Orta nokta)      : %f\n", fonksiyon_hesap(fonk, mid));
		printf("İterasyon sayısı   : %d\n", i);

		//başlangıç ve bitiş aralılarının değeri aynı işaretli ise kök yoktur uyarı verilir
        if (fonksiyon_hesap(fonk,end) * fonksiyon_hesap(fonk, start) > 0) {
            printf("Hata: Verilen (%.4f, %.4f) aralığında kök yoktur.\n", start, end);
            exit(1);
        }

        // İşaret değişimi kontrolü: kökün hangi aralıkta olduğunu belirler
		if (fonksiyon_hesap(fonk, mid) * fonksiyon_hesap(fonk, start) < 0)
		{
			end = mid; // Kök sol yarıda
		}
		else
		{
			start = mid; // Kök sağ yarıda
		}
		i++;
	} while (fabs(hata - önceki_hata) > epsilon && i < iterat); // Hata yeterince küçükse ya da iterasyon sınırı aşılmadıysa devam

	return mid; // Bulunan kök değeri döndürülür
}

// Regula Falsi (yanlış konum) yöntemi ile kök bulma
float regula_falsi(char *fonk, float start, float end, float epsilon, int iterat)
{
	float hata, mid, tmp, önceki_hata;
	int i = 0;
	do
	{
		önceki_hata = mid; // Bir önceki değer saklanır
		// Doğrusal yaklaşım kullanılarak orta nokta (tahmini kök) hesaplanır
		mid = (start * fonksiyon_hesap(fonk, end) - end * fonksiyon_hesap(fonk, start)) / 
		      (fonksiyon_hesap(fonk, end) - fonksiyon_hesap(fonk, start));
		hata = mid;

		// Bilgiler ekrana yazdırılır
		printf("\n");
		printf("Başlangıç noktası  : %f\n", start);
		printf("Bitiş noktası      : %f\n", end);
		printf("Yaklaşık kök       : %f\n", mid);
		printf("f(Başlangıç)       : %f\n", fonksiyon_hesap(fonk, start));
		printf("f(Bitiş)           : %f\n", fonksiyon_hesap(fonk, end));
		printf("f(Yaklaşık kök)    : %f\n", fonksiyon_hesap(fonk, mid));
		printf("İterasyon sayısı   : %d\n", i);

        //başlangıç ve bitiş aralılarının değeri aynı işaretli ise kök yoktur uyarı verilir
        if (fonksiyon_hesap(fonk,end) * fonksiyon_hesap(fonk, start) > 0) {
            printf("\nHata: Verilen (%.4f, %.4f) aralığında kök yoktur.\n", start, end);
            exit(1);
        }

		// İşaret değişimi kontrolü: kökün hangi aralıkta olduğunu belirler
		if (fonksiyon_hesap(fonk, mid) * fonksiyon_hesap(fonk, start) < 0)
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
		i++;

	} while (fabs(hata - önceki_hata) > epsilon && i < iterat); // Hata yeterince küçükse ya da iterasyon sınırı aşılmadıysa devam

	return mid; // Bulunan kök değeri döndürülür
}

// Newton-Raphson yöntemi ile kök bulma algoritması
float newton_raphson(char *fonk, float x0, float epsilon, int iterat)
{
	float x1, hata, önceki_hata;
	int i = 1;
	do
	{

		// Newton-Raphson formülü uygulanarak yeni x değeri hesaplanır
		x1 = x0 - fonksiyon_hesap(fonk, x0) / fonksiyon_türev(fonk, x0);

		// Bilgiler ekrana yazdırılır
		printf("\n");
		printf("x[n]              : %f\n", x0);
		printf("x[n+1] (Yeni x)   : %f\n", x1);
		printf("f(x[n])           : %f\n", fonksiyon_hesap(fonk, x0));
		printf("f'(x[n]) (Türev)  : %f\n", fonksiyon_türev(fonk, x0));
		printf("İterasyon sayısı  : %d\n", i);

		önceki_hata = fabs(fonksiyon_hesap(fonk, x0)); // Önceki hatayı sakla
		x0 = x1;                                       // x güncellenir
		hata = fabs(fonksiyon_hesap(fonk, x0));        // Yeni hata hesaplanır
		i++;

	} while (fabs(hata - önceki_hata) > epsilon && i < iterat); // Hata farkı epsilon’dan büyükse ve iterasyon sınırı aşılmadıysa devam

	return x0; // Bulunan kök değeri döndürülür
}

// Geri farklar yöntemiyle sayısal türev hesaplama fonksiyonu
float geri_farklar_ile_sayısal_türev(char *fonk, float nokta, float h)
{
	float result;

	// Geri farklar formülü: f'(x) ≈ (f(x) - f(x - h)) / h
	result = (fonksiyon_hesap(fonk, nokta) - fonksiyon_hesap(fonk, nokta - h)) / h;

	return result;
}

// İleri farklar yöntemiyle sayısal türev hesaplama fonksiyonu
float ileri_farklar_ile_sayısal_türev(char *fonk, float nokta, float h)
{
	float result;

	// İleri farklar formülü: f'(x) ≈ (f(x + h) - f(x)) / h
	result = (fonksiyon_hesap(fonk, nokta + h) - fonksiyon_hesap(fonk, nokta)) / h;

	return result;
}

// Merkezi farklar yöntemiyle sayısal türev hesaplama fonksiyonu
float merkezi_farklar_ile_sayısal_türev(char *fonk, float nokta, float h)
{
	float result;

	// Merkezi farklar formülü: f'(x) ≈ (f(x + h) - f(x - h)) / (2h)
	result = (fonksiyon_hesap(fonk, nokta + h) - fonksiyon_hesap(fonk, nokta - h)) / (2 * h);

	return result;
}

// Trapez yöntemiyle sayısal integrasyon (alan hesaplama)
float trapez_yöntemi(char *fonk, float start, float end, int n)
{
	float result = 0, h;
	int i;

	// Adım genişliği (b - a) / n
	h = fabs((end - start)) / n;

	// Orta noktalar için fonksiyon değerlerini topluyoruz
	for (i = 1; i < n; i++)
	{
		result += fonksiyon_hesap(fonk, start + i * h);
	}

	// Başlangıç ve bitiş noktalarının değerlerinin yarısı eklenir
	result += (fonksiyon_hesap(fonk, start) + fonksiyon_hesap(fonk, end)) / 2;

	// Sonuç h ile çarpılarak yaklaşık alan elde edilir
	result *= h;

	return result;
}

// Simpson 1/3 yöntemiyle sayısal integrasyon
float simson_yöntemi_1_3(char *fonk, float start, float end, int n)
{
	float result = 0, h, sum_odd;
	int i;

	// Adım genişliği
	h = fabs((end - start)) / n;
    sum_odd = 0;
	// Tek indeksli noktaların (çift sayıda) katsayısı 4
	for (i = 1; i < n; i += 2)
	{
		sum_odd += fonksiyon_hesap(fonk, start + i * h);
	}
	result += 4 * sum_odd;

    sum_odd = 0;
	// Çift indeksli noktaların katsayısı 2
	for (i = 2; i < n; i += 2)
	{
		sum_odd += fonksiyon_hesap(fonk, start + i * h);
	}
	result += 2 * sum_odd;

	// Baş ve son noktaların değeri doğrudan eklenir
	result += (fonksiyon_hesap(fonk, start) + fonksiyon_hesap(fonk, end));

	// Tüm toplam (h / 3) ile çarpılır
	result *= h / 3;

	return result;
}

// Simpson 3/8 yöntemiyle sayısal integrasyon
float simson_yöntemi_3_8(char *fonk, float start, float end, int n)
{
    // Adım genişliğini hesapla
    float h = (end - start) / n;

    // İlk ve son noktadaki fonksiyon değerlerini topla
    float result = fonksiyon_hesap(fonk, start) + fonksiyon_hesap(fonk, end);

    // İç noktalar için ağırlıklı toplam
    for (int i = 1; i < n; i++)
    {
        float x = start + i * h;  // Mevcut x değeri

        if (i % 3 == 0)
            // Her üçüncü noktada katsayı 2
            result += 2 * fonksiyon_hesap(fonk, x);
        else
            // Diğer noktalarda katsayı 3
            result += 3 * fonksiyon_hesap(fonk, x);
    }

    // Sonuç: (3h/8) çarpanı ile ağırlıklı toplam
    result *= (3 * h / 8.0);

    return result;
}

// Gregory-Newton İleri Fark Enterpolasyon Yöntemi
float gregory_Newton_enterpolasyon(float *x_dizi, float *y_dizi, int derece, float x)
{
    float delta[20][20];
    float h, u, result;
    int i, j;

    // delta değerleri tablosunu başlat
    for (i = 0; i < derece; i++)
        delta[i][0] = y_dizi[i];

    // delta k y[i] hesapla
    for (j = 1; j < derece; j++)
    {
        for (i = 0; i < derece - j; i++)
        {
            delta[i][j] = delta[i + 1][j - 1] - delta[i][j - 1];
        }
    }
    printf("\nİleri Fark Tablosu: \n");
    for ( i = 0; i < derece; i++)
    {   
        printf("\nx = %d        ",i);
        for ( j = 0; j < derece - i; j++)
        {
            printf("%f      ",delta[i][j]);
        }
    }
    printf("\n");
    

    // h ve u hesapla (eşit aralıklı olduğu varsayılıyor)
    h = x_dizi[1] - x_dizi[0];
    u = (x - x_dizi[0]) / h;

    // Newton-Gregory ileri fark formülü uygulanıyor
    result = delta[0][0];
    float u_term = 1;
    int fakt = 1;

    for (i = 1; i < derece; i++)
    {
        u_term *= (u - (i - 1));
        fakt *= i;
        result += (u_term * delta[0][i]) / fakt;
    }

    return result;
}


