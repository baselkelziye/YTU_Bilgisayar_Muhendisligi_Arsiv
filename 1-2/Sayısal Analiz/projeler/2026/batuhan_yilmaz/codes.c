#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/* ===== SABITLER VE STRUCT TANIMLAMALARI ===== */

typedef enum {
    T_SAYI, T_DEGISKEN, T_ARTI, T_EKSI, T_CARPI, T_BOLU, T_US,
    T_SOL_PAR, T_SAG_PAR, T_FONK, T_IC_LOG, T_ON_LOG, T_SON
} KisimTipi;

typedef struct {
    KisimTipi tip;
    double sayi;
    char Isim[20];
} Kisim;

typedef struct {
    const char* Gosterici;
    Kisim Mevcut;
} AyristiriciDurumu;

/* AST (Abstract Syntax Tree) Node Yapisi */
typedef struct IslemAgaci {
    int DugumTipi; /* 0: Sayi, 1: Degisken, 2: Operator, 3: Fonksiyon */
    double Deger;
    char Isim[20];
    struct IslemAgaci* Sol;
    struct IslemAgaci* Sag;
} IslemAgaci;

/* Dinamik Matris Yapisi */
typedef struct {
    int Satirlar;
    int Sutunlar;
    double** Veri;
} Matris;

/* ===== MATRIS FONKSIYONLARI ===== */

Matris* matrisOlustur(int Satirlar, int Sutunlar) {
    Matris* m = (Matris*)malloc(sizeof(Matris));
    m->Satirlar = Satirlar;
    m->Sutunlar = Sutunlar;
    m->Veri = (double**)malloc(Satirlar * sizeof(double*));
    int i;
    for (i = 0; i < Satirlar; i++) {
        m->Veri[i] = (double*)malloc(Sutunlar * sizeof(double));
    }
    return m;
}

void matrisSerbestBirak(Matris* m) {
    if (m == NULL) return;
    int i;
    for (i = 0; i < m->Satirlar; i++) {
        free(m->Veri[i]);
    }
    free(m->Veri);
    free(m);
}

/* ===== MATEMATIKSEL IFADE AYRISTIRICI (AST + RDP) ===== */

void sonrakiJeton(AyristiriciDurumu* Durum) {
    while (isspace(*(Durum->Gosterici))) {
        Durum->Gosterici++;
    }
    
    if (*(Durum->Gosterici) == '\0') {
        Durum->Mevcut.tip = T_SON;
        return;
    }
    
    char c = *(Durum->Gosterici);
    
    if (c == '+') { Durum->Mevcut.tip = T_ARTI; Durum->Gosterici++; return; }
    if (c == '-') { Durum->Mevcut.tip = T_EKSI; Durum->Gosterici++; return; }
    if (c == '*') { Durum->Mevcut.tip = T_CARPI; Durum->Gosterici++; return; }
    if (c == '/') { Durum->Mevcut.tip = T_BOLU; Durum->Gosterici++; return; }
    if (c == '^') { Durum->Mevcut.tip = T_US; Durum->Gosterici++; return; }
    if (c == '(') { Durum->Mevcut.tip = T_SOL_PAR; Durum->Gosterici++; return; }
    if (c == ')') { Durum->Mevcut.tip = T_SAG_PAR; Durum->Gosterici++; return; }
    if (c == '_') { Durum->Mevcut.tip = T_IC_LOG; Durum->Gosterici++; return; }
    
    if (strncmp(Durum->Gosterici, "log_", 4) == 0) {
        Durum->Mevcut.tip = T_ON_LOG;
        Durum->Gosterici += 4;
        return;
    }
    
    if (isalpha(c)) {
        if ((c == 'x' || c == 'X') && !isalpha(*(Durum->Gosterici + 1))) {
            Durum->Mevcut.tip = T_DEGISKEN;
            Durum->Gosterici++;
            return;
        }
        int i = 0;
        while (isalpha(*(Durum->Gosterici)) && i < 19) {
            Durum->Mevcut.Isim[i++] = *(Durum->Gosterici);
            Durum->Gosterici++;
        }
        Durum->Mevcut.Isim[i] = '\0';
        
        if (strcmp(Durum->Mevcut.Isim, "e") == 0) {
            Durum->Mevcut.tip = T_SAYI;
            Durum->Mevcut.sayi = 2.718281828459045;
            return;
        }
        if (strcmp(Durum->Mevcut.Isim, "pi") == 0) {
            Durum->Mevcut.tip = T_SAYI;
            Durum->Mevcut.sayi = 3.141592653589793;
            return;
        }
        if (strcmp(Durum->Mevcut.Isim, "x") == 0 || strcmp(Durum->Mevcut.Isim, "X") == 0) {
            Durum->Mevcut.tip = T_DEGISKEN;
            return;
        }
        Durum->Mevcut.tip = T_FONK;
        return;
    }
    
    if (isdigit(c) || c == '.') {
        char* son;
        Durum->Mevcut.sayi = strtod(Durum->Gosterici, &son);
        Durum->Gosterici = son;
        Durum->Mevcut.tip = T_SAYI;
        return;
    }
    
    Durum->Gosterici++;
    sonrakiJeton(Durum);
}

IslemAgaci* dugumSayiOlustur(double DegerV) {
    IslemAgaci* n = (IslemAgaci*)malloc(sizeof(IslemAgaci));
    n->DugumTipi = 0; n->Deger = DegerV; n->Sol = NULL; n->Sag = NULL;
    return n;
}

IslemAgaci* dugumDegiskenOlustur() {
    IslemAgaci* n = (IslemAgaci*)malloc(sizeof(IslemAgaci));
    n->DugumTipi = 1; n->Sol = NULL; n->Sag = NULL;
    return n;
}

IslemAgaci* dugumIslemOlustur(char op, IslemAgaci* l, IslemAgaci* r) {
    IslemAgaci* n = (IslemAgaci*)malloc(sizeof(IslemAgaci   ));
    n->DugumTipi = 2; n->Isim[0] = op; n->Isim[1] = '\0'; n->Sol = l; n->Sag = r;
    return n;
}

IslemAgaci* dugumFonkOlustur(const char* Isim, IslemAgaci* Arguman) {
    IslemAgaci* n = (IslemAgaci*)malloc(sizeof(IslemAgaci));
    n->DugumTipi = 3; strcpy(n->Isim, Isim); n->Sol = Arguman; n->Sag = NULL;
    return n;
}

void agaciSerbestBirak(IslemAgaci* n) {
    if (n == NULL) return;
    agaciSerbestBirak(n->Sol);
    agaciSerbestBirak(n->Sag);
    free(n);
}

IslemAgaci* ifadeAyristir(AyristiriciDurumu* Durum);
IslemAgaci* terimAyristir(AyristiriciDurumu* Durum);
IslemAgaci* carpanAyristir(AyristiriciDurumu* Durum);
IslemAgaci* usAyristir(AyristiriciDurumu* Durum);

IslemAgaci* usAyristir(AyristiriciDurumu* Durum) {
    if (Durum->Mevcut.tip == T_ARTI) {
        sonrakiJeton(Durum);
        return usAyristir(Durum);
    }
    if (Durum->Mevcut.tip == T_EKSI) {
        sonrakiJeton(Durum);
        return dugumIslemOlustur('*', dugumSayiOlustur(-1.0), usAyristir(Durum));
    }
    if (Durum->Mevcut.tip == T_SOL_PAR) {
        sonrakiJeton(Durum);
        IslemAgaci* n = ifadeAyristir(Durum);
        if (Durum->Mevcut.tip == T_SAG_PAR) sonrakiJeton(Durum);
        /* Kısaltma: (x+1)3 -> (x+1)^3 desteği */
        if (Durum->Mevcut.tip == T_SAYI) {
            double p = Durum->Mevcut.sayi;
            sonrakiJeton(Durum);
            return dugumIslemOlustur('^', n, dugumSayiOlustur(p));
        }
        return n;
    }
    if (Durum->Mevcut.tip == T_FONK) {
        char Isim[20];
        strcpy(Isim, Durum->Mevcut.Isim);
        sonrakiJeton(Durum);
        return dugumFonkOlustur(Isim, terimAyristir(Durum)); 
    }
    if (Durum->Mevcut.tip == T_ON_LOG) {
        sonrakiJeton(Durum);
        IslemAgaci* Taban = terimAyristir(Durum);
        IslemAgaci* DegerV = terimAyristir(Durum);
        return dugumIslemOlustur('_', Taban, DegerV);
    }
    if (Durum->Mevcut.tip == T_DEGISKEN) {
        sonrakiJeton(Durum);
        IslemAgaci* DegiskenDugumu = dugumDegiskenOlustur();
        /* Kısaltma: x3 -> x^3 desteği */
        if (Durum->Mevcut.tip == T_SAYI) {
            double p = Durum->Mevcut.sayi;
            sonrakiJeton(Durum);
            return dugumIslemOlustur('^', DegiskenDugumu, dugumSayiOlustur(p));
        }
        return DegiskenDugumu;
    }
    if (Durum->Mevcut.tip == T_SAYI) {
        double DegerV = Durum->Mevcut.sayi;
        sonrakiJeton(Durum);
        return dugumSayiOlustur(DegerV);
    }
    return dugumSayiOlustur(0.0);
}

IslemAgaci* carpanAyristir(AyristiriciDurumu* Durum) {
    IslemAgaci* Sol = usAyristir(Durum);
    int IslemMi = 1;
    while (IslemMi) {
        if (Durum->Mevcut.tip == T_US || Durum->Mevcut.tip == T_IC_LOG) {
            char op = (Durum->Mevcut.tip == T_US) ? '^' : '_';
            sonrakiJeton(Durum);
            Sol = dugumIslemOlustur(op, Sol, usAyristir(Durum));
        } else {
            IslemMi = 0;
        }
    }
    return Sol;
}

IslemAgaci* terimAyristir(AyristiriciDurumu* Durum) {
    IslemAgaci* Sol = carpanAyristir(Durum);
    int IslemMi = 1;
    while (IslemMi) {
        if (Durum->Mevcut.tip == T_CARPI || Durum->Mevcut.tip == T_BOLU) {
            char op = (Durum->Mevcut.tip == T_CARPI) ? '*' : '/';
            sonrakiJeton(Durum);
            Sol = dugumIslemOlustur(op, Sol, carpanAyristir(Durum));
        } else if (Durum->Mevcut.tip == T_DEGISKEN || Durum->Mevcut.tip == T_FONK || 
                   Durum->Mevcut.tip == T_SOL_PAR || Durum->Mevcut.tip == T_ON_LOG || 
                   Durum->Mevcut.tip == T_SAYI) {
            /* Örtük Çarpım (Implicit Multiplication): "5x" -> "5 * x" */
            Sol = dugumIslemOlustur('*', Sol, carpanAyristir(Durum));
        } else {
            IslemMi = 0;
        }
    }
    return Sol;
}

IslemAgaci* ifadeAyristir(AyristiriciDurumu* Durum) {
    IslemAgaci* Sol = terimAyristir(Durum);
    int IslemMi = 1;
    while (IslemMi) {
        if (Durum->Mevcut.tip == T_ARTI || Durum->Mevcut.tip == T_EKSI) {
            char op = (Durum->Mevcut.tip == T_ARTI) ? '+' : '-';
            sonrakiJeton(Durum);
            Sol = dugumIslemOlustur(op, Sol, terimAyristir(Durum));
        } else {
            IslemMi = 0;
        }
    }
    return Sol;
}

double agaciDegerlendir(IslemAgaci* n, double x) {
    if (n == NULL) return 0.0;
    if (n->DugumTipi == 0) return n->Deger;
    if (n->DugumTipi == 1) return x;
    if (n->DugumTipi == 2) {
        double l = agaciDegerlendir(n->Sol, x);
        double r = agaciDegerlendir(n->Sag, x);
        if (n->Isim[0] == '+') return l + r;
        if (n->Isim[0] == '-') return l - r;
        if (n->Isim[0] == '*') return l * r;
        if (n->Isim[0] == '/') return l / r;
        if (n->Isim[0] == '^') return pow(l, r);
        /* _ operatörü: a _ b = log_a(b) */
        if (n->Isim[0] == '_') return log(r) / log(l);
    }
    if (n->DugumTipi == 3) {
        double Arguman = agaciDegerlendir(n->Sol, x);
        if (strcmp(n->Isim, "sin") == 0) return sin(Arguman);
        if (strcmp(n->Isim, "cos") == 0) return cos(Arguman);
        if (strcmp(n->Isim, "tan") == 0) return tan(Arguman);
        if (strcmp(n->Isim, "cot") == 0) return 1.0 / tan(Arguman);
        if (strcmp(n->Isim, "exp") == 0) return exp(Arguman);
        if (strcmp(n->Isim, "log") == 0 || strcmp(n->Isim, "ln") == 0) return log(Arguman);
        if (strcmp(n->Isim, "log10") == 0) return log10(Arguman);
        if (strcmp(n->Isim, "arcsin") == 0 || strcmp(n->Isim, "asin") == 0) return asin(Arguman);
        if (strcmp(n->Isim, "arccos") == 0 || strcmp(n->Isim, "acos") == 0) return acos(Arguman);
        if (strcmp(n->Isim, "arctan") == 0 || strcmp(n->Isim, "atan") == 0) return atan(Arguman);
        if (strcmp(n->Isim, "sec") == 0) return 1.0 / cos(Arguman);
        if (strcmp(n->Isim, "csc") == 0) return 1.0 / sin(Arguman);
    }
    return 0.0;
}

IslemAgaci* ayristiriciOlustur(const char* IfadeMetni) {
    AyristiriciDurumu Durum;
    Durum.Gosterici = IfadeMetni;
    sonrakiJeton(&Durum);
    return ifadeAyristir(&Durum);
}

double ifadeDegeriOku() {
    char buffer[256];
    scanf("%255s", buffer);
    IslemAgaci* agac = ayristiriciOlustur(buffer);
    double val = agaciDegerlendir(agac, 0.0);
    agaciSerbestBirak(agac);
    return val;
}

/*Yontemler*/

/* 1. Bisection Yöntemi */
void ikiyeBolmeYontemi(IslemAgaci* f, double a, double b, double Tolerans) {
    if (agaciDegerlendir(f, a) * agaciDegerlendir(f, b) >= 0) {
        printf("Hata: f(a) * f(b) >= 0. Bu aralikta kok garanti edilemez veya kok yoktur.\n");
        return;
    }
    double c = a;
    int Adim = 0;
    int CalisiyorMu = 1;
    printf("\n%-10s %-15s %-15s %-15s %-15s\n", "Iterasyon", "a", "b", "c", "f(c)");
    
    while (CalisiyorMu && (b - a) >= Tolerans && Adim < 100) {
        c = (a + b) / 2.0;
        double FC = agaciDegerlendir(f, c);
        Adim++;
        printf("%-10d %-15.6lf %-15.6lf %-15.6lf %-15.6lf\n", Adim, a, b, c, FC);
        
        if (FC == 0.0) {
            CalisiyorMu = 0;
        } else {
            if (FC * agaciDegerlendir(f, a) < 0) {
                b = c;
            } else {
                a = c;
            }
        }
    }
    printf("Bulunan Kok: %.6lf\n", c);
}

/* 2. Regula-Falsi Yöntemi */
void regulaFalsiYontemi(IslemAgaci* f, double a, double b, double Tolerans) {
    if (agaciDegerlendir(f, a) * agaciDegerlendir(f, b) >= 0) {
        printf("Hata: f(a) * f(b) >= 0. Bu aralikta kok garanti edilemez veya kok yoktur.\n");
        return;
    }
    double c = a, EskiC;
    int Adim = 0;
    int CalisiyorMu = 1;
    printf("\n%-10s %-15s %-15s %-15s %-15s\n", "Iterasyon", "a", "b", "c", "f(c)");
    
    while (CalisiyorMu && Adim < 100) {
        EskiC = c;
        double FA = agaciDegerlendir(f, a);
        double FB = agaciDegerlendir(f, b);
        c = (a * FB - b * FA) / (FB - FA);
        double FC = agaciDegerlendir(f, c);
        Adim++;
        printf("%-10d %-15.6lf %-15.6lf %-15.6lf %-15.6lf\n", Adim, a, b, c, FC);
        
        if (fabs(c - EskiC) < Tolerans || FC == 0.0) {
            CalisiyorMu = 0;
        } else {
            if (FC * FA < 0) {
                b = c;
            } else {
                a = c;
            }
        }
    }
    printf("Bulunan Kok: %.6lf\n", c);
}

/* 3. Newton-Raphson Yöntemi */
double noktadaSayisalTurev(IslemAgaci* f, double x) {
    double h = 1e-5;
    return (agaciDegerlendir(f, x + h) - agaciDegerlendir(f, x - h)) / (2 * h);
}

void newtonRaphsonYontemi(IslemAgaci* f, double x0, double Tolerans) {
    double x1;
    int Adim = 0;
    int CalisiyorMu = 1;
    printf("\n%-10s %-15s %-15s %-15s %-15s\n", "Iterasyon", "x0", "f(x0)", "f'(x0)", "x1");
    
    while (CalisiyorMu && Adim < 100) {
        double FX = agaciDegerlendir(f, x0);
        double TFX = noktadaSayisalTurev(f, x0);
        
        if (isnan(FX) || isnan(TFX)) {
            printf("Hata: Fonksiyon veya turevi x0 = %.6lf noktasinda tanimsiz (NaN) oldu.\n", x0);
            break;
        }
        
        if (TFX == 0.0) {
            printf("Turev sifir oldu, hesaplama durduruldu.\n");
            CalisiyorMu = 0;
        } else {
            x1 = x0 - (FX / TFX);
            Adim++;
            printf("%-10d %-15.6lf %-15.6lf %-15.6lf %-15.6lf\n", Adim, x0, FX, TFX, x1);
            
            if (fabs(x1 - x0) < Tolerans) {
                CalisiyorMu = 0;
            } else {
                x0 = x1;
            }
        }
    }
    printf("Bulunan Kok: %.6lf\n", x1);
}

/* 4. NxN Matrisin Tersi (Gauss-Jordan) */
void matrisTersiYontemi() {
    int n, i, j, k;
    printf("Matris boyutunu (N) giriniz (NxN): ");
    scanf("%d", &n);
    
    Matris* m = matrisOlustur(n, n);
    Matris* EkMatris = matrisOlustur(n, 2 * n);
    
    printf("Matris elemanlarini giriniz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &m->Veri[i][j]);
            EkMatris->Veri[i][j] = m->Veri[i][j];
        }
        for (j = n; j < 2 * n; j++) {
            EkMatris->Veri[i][j] = (i == (j - n)) ? 1.0 : 0.0;
        }
    }
    
    int TekilMi = 0;
    for (i = 0; i < n && !TekilMi; i++) {
        double Gecici = EkMatris->Veri[i][i];
        if (Gecici == 0.0) {
            TekilMi = 1;
        } else {
            for (j = 0; j < 2 * n; j++) {
                EkMatris->Veri[i][j] /= Gecici;
            }
            for (k = 0; k < n; k++) {
                if (i != k) {
                    double Carpan = EkMatris->Veri[k][i];
                    for (j = 0; j < 2 * n; j++) {
                        EkMatris->Veri[k][j] -= Carpan * EkMatris->Veri[i][j];
                    }
                }
            }
        }
    }
    
    if (TekilMi) {
        printf("Matrisin tersi yok (Pivot sifir).\n");
    } else {
        printf("\nTers Matris:\n");
        for (i = 0; i < n; i++) {
            for (j = n; j < 2 * n; j++) {
                printf("%8.4lf ", EkMatris->Veri[i][j]);
            }
            printf("\n");
        }
    }
    
    matrisSerbestBirak(m);
    matrisSerbestBirak(EkMatris);
}

/* 5. Cholesky Yontemi */
void choleskyYontemi() {
    int n, i, j, k;
    printf("Matris boyutunu (N) giriniz (NxN): ");
    scanf("%d", &n);
    
    Matris* m = matrisOlustur(n, n);
    Matris* L = matrisOlustur(n, n);
    Matris* U = matrisOlustur(n, n);
    double* b = (double*)malloc(n * sizeof(double));
    double* y = (double*)malloc(n * sizeof(double));
    double* x = (double*)malloc(n * sizeof(double));
    
    printf("Matris elemanlarini giriniz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &m->Veri[i][j]);
            L->Veri[i][j] = 0.0;
            U->Veri[i][j] = 0.0;
        }
        L->Veri[i][i] = 1.0;
    }
    
    printf("Sonuc (B) vektoru elemanlarini giriniz:\n");
    for (i = 0; i < n; i++) {
        printf("B[%d]: ", i);
        scanf("%lf", &b[i]);
    }
    
    int HataVarMi = 0;
    for (i = 0; i < n && !HataVarMi; i++) {
        for (j = i; j < n; j++) {
            double Toplam = 0.0;
            for (k = 0; k < i; k++) {
                Toplam += L->Veri[i][k] * U->Veri[k][j];
            }
            U->Veri[i][j] = m->Veri[i][j] - Toplam;
        }
        for (j = i + 1; j < n; j++) {
            double Toplam = 0.0;
            for (k = 0; k < i; k++) {
                Toplam += L->Veri[j][k] * U->Veri[k][i];
            }
            if (U->Veri[i][i] == 0.0) {
                HataVarMi = 1;
            } else {
                L->Veri[j][i] = (m->Veri[j][i] - Toplam) / U->Veri[i][i];
            }
        }
    }
    
    if (HataVarMi) {
        printf("LU Ayristirmasi yapilamiyor (Sifira bolme hatasi).\n");
    } else {
        printf("\nL Matrisi (Alt Ucgensel):\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) printf("%8.4lf ", L->Veri[i][j]);
            printf("\n");
        }
        printf("\nU Matrisi (Ust Ucgensel):\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) printf("%8.4lf ", U->Veri[i][j]);
            printf("\n");
        }
        
        /* Ileri yerlestirme (Ly = b) */
        for (i = 0; i < n; i++) {
            double Toplam = 0.0;
            for (j = 0; j < i; j++) {
                Toplam += L->Veri[i][j] * y[j];
            }
            y[i] = (b[i] - Toplam) / L->Veri[i][i];
        }
        
        /* Geri yerlestirme (Ux = y) */
        for (i = n - 1; i >= 0; i--) {
            double Toplam = 0.0;
            for (j = i + 1; j < n; j++) {
                Toplam += U->Veri[i][j] * x[j];
            }
            x[i] = (y[i] - Toplam) / U->Veri[i][i];
        }
        
        printf("\nKokler (x vektoru):\n");
        for (i = 0; i < n; i++) {
            printf("x[%d] = %.6lf\n", i + 1, x[i]);
        }
    }
    
    matrisSerbestBirak(m);
    matrisSerbestBirak(L);
    matrisSerbestBirak(U);
    free(b);
    free(y);
    free(x);
}

/* 6. Gauss-Seidel Yöntemi */
void gaussSeidelYontemi() {
    int n, i, j;
    printf("Denklem sayisini (N) giriniz: ");
    scanf("%d", &n);
    
    Matris* A = matrisOlustur(n, n);
    double* b = (double*)malloc(n * sizeof(double));
    double* x = (double*)malloc(n * sizeof(double));
    double* EskiX = (double*)malloc(n * sizeof(double));
    
    printf("A matrisi elemanlarini giriniz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            A->Veri[i][j] = ifadeDegeriOku();
        }
    }
    printf("Sonuc Vektoru Elemanlarini Giriniz:\n");
    for (i = 0; i < n; i++) {
        printf("B[%d]: ", i);
        b[i] = ifadeDegeriOku();
        x[i] = 0.0; /* Baslangic tahmini sifir */
        EskiX[i] = 0.0;
    }

    double Tolerans;
    printf("Hata toleransini giriniz (orn: 0.001): ");
    Tolerans = ifadeDegeriOku();
    
    int Adim = 0, MaksAdim = 100;
    int DevamEt = 1;
    
    while (Adim < MaksAdim && DevamEt) {
        for (i = 0; i < n; i++) {
            EskiX[i] = x[i];
        }     
        for (i = 0; i < n; i++) {
            double Toplam = b[i];
            for (j = 0; j < n; j++) {
                if (i != j) {
                    Toplam -= A->Veri[i][j] * x[j];
                }
            }
            if (A->Veri[i][i] != 0.0) {
                x[i] = Toplam / A->Veri[i][i];
            }
        }
        
        DevamEt = 0;
        for (i = 0; i < n; i++) {
            if (fabs(x[i] - EskiX[i]) >= Tolerans) {
                DevamEt = 1;
            }
        }
        Adim++;
    }
    
    printf("\n%d iterasyon sonunda Gauss-Seidel sonuclari:\n", Adim);
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.6lf\n", i + 1, x[i]);
    }
    
    matrisSerbestBirak(A);
    free(b);
    free(x);
    free(EskiX);
}

/* 7. Sayısal Türev */
void SayisalTurev(IslemAgaci* f, double x, double h) {
    double FX = agaciDegerlendir(f, x);
    double f_x_plus_h = agaciDegerlendir(f, x + h);
    double f_x_minus_h = agaciDegerlendir(f, x - h);
    
    double ileri = (f_x_plus_h - FX) / h;
    double geri = (FX - f_x_minus_h) / h;
    double merkezi = (f_x_plus_h - f_x_minus_h) / (2 * h);
    
    printf("\nx = %lf icin Sayisal Turev Sonuclari:\n", x);
    printf("Ileri Fark  : %.6lf\n", ileri);
    printf("Geri Fark   : %.6lf\n", geri);
    printf("Merkezi Fark: %.6lf\n", merkezi);
}

/* 8. Simpson Yöntemi (1/3 ve 3/8) */
void simpsonYontemleri(IslemAgaci* f, double a, double b, int n) {
    int i;
    /* Simpson 1/3 */
    printf("\n--- Simpson 1/3 Yontemi ---\n");
    int n13 = n;
    if (n13 % 2 != 0) {
        n13++;
        printf("Uyari: 1/3 yontemi icin N cift olmalidir. N, %d olarak guncellendi.\n", n13);
    }
    double h13 = (b - a) / n13;
    double toplam13 = agaciDegerlendir(f, a) + agaciDegerlendir(f, b);
    for (i = 1; i < n13; i++) {
        if (i % 2 == 0) {
            toplam13 += 2.0 * agaciDegerlendir(f, a + i * h13);
        } else {
            toplam13 += 4.0 * agaciDegerlendir(f, a + i * h13);
        }
    }
    toplam13 = toplam13 * h13 / 3.0;
    printf("Simpson 1/3 Sonucu: %.6lf\n", toplam13);
    
    /* Simpson 3/8 */
    printf("\n--- Simpson 3/8 Yontemi ---\n");
    int n38 = n;
    if (n38 % 3 != 0) {
        n38 += (3 - (n38 % 3));
        printf("Uyari: 3/8 yontemi icin N 3'un kati olmalidir. N, %d olarak guncellendi.\n", n38);
    }
    double h38 = (b - a) / n38;
    double toplam38 = agaciDegerlendir(f, a) + agaciDegerlendir(f, b);
    for (i = 1; i < n38; i++) {
        if (i % 3 == 0) {
            toplam38 += 2.0 * agaciDegerlendir(f, a + i * h38);
        } else {
            toplam38 += 3.0 * agaciDegerlendir(f, a + i * h38);
        }
    }
    toplam38 = toplam38 * 3.0 * h38 / 8.0;
    printf("Simpson 3/8 Sonucu: %.6lf\n", toplam38);
}

/* 9. Trapez Yöntemi */
void trapezYontemi(IslemAgaci* f, double a, double b, int n) {
    double h = (b - a) / n;
    double Toplam = (agaciDegerlendir(f, a) + agaciDegerlendir(f, b)) / 2.0;
    int i;
    for (i = 1; i < n; i++) {
        Toplam += agaciDegerlendir(f, a + i * h);
    }
    Toplam *= h;
    printf("\nTrapez Yontemi Sonucu: %.6lf\n", Toplam);
}

/* 10. Gregory Newton Enterpolasyonu */
void gregoryNewtonYontemi() {
    int n, i, j;
    printf("\nVeri noktasi sayisini (N) giriniz: ");
    scanf("%d", &n);
    
    double* x = (double*)malloc(n * sizeof(double));
    double** farklar = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        farklar[i] = (double*)malloc(n * sizeof(double));
    }
    
    printf("x ve y degerlerini sirasiyla giriniz:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i);
        scanf("%lf", &farklar[i][0]);
    }
    
    double hedef_x;
    printf("Hesaplanacak hedef x degerini giriniz: ");
    scanf("%lf", &hedef_x);
    
    /* İleri Farklar Tablosunu Olustur */
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            farklar[i][j] = farklar[i + 1][j - 1] - farklar[i][j - 1];
        }
    }
    
    double h = x[1] - x[0];
    double sonuc = farklar[0][0];
    double terim_x = 1.0;
    double fakt = 1.0;
    double h_us = 1.0;
    
    for (j = 1; j < n; j++) {
        terim_x *= (hedef_x - x[j - 1]);
        fakt *= j;
        h_us *= h;
        sonuc += (farklar[0][j] / (fakt * h_us)) * terim_x;
    }
    
    printf("\nGregory-Newton Enterpolasyon Sonucu: %.6lf\n", sonuc);
    
    free(x);
    for (i = 0; i < n; i++) free(farklar[i]);
    free(farklar);
}

/*Menu*/

int main() {
    int secim;
    char ifade[256];
    int kontrol = 1;
    double a, b, hataDegeri, h, DegerV;
    int n;
    
    do {
        printf("    SAYISAL ANALIZ DONEM PROJESI - Batuhan Yilmaz\n");
        printf("1. Bisection Yontemi\n");
        printf("2. Regula-Falsi Yontemi\n");
        printf("3. Newton-Raphson Yontemi\n");
        printf("4. NxN Matris Tersi\n");
        printf("5. Cholesky (ALU) Yontemi\n");
        printf("6. Gauss Seidel Yontemi\n");
        printf("7. Sayisal Turev (Ileri, Geri, Merkezi)\n");
        printf("8. Simpson Yontemi (1/3 ve 3/8)\n");
        printf("9. Trapez Yontemi\n");
        printf("10. Gregory Newton Enterpolasyonu\n");
        printf("0. Cikis\n");
        printf("Lutfen bir secim yapiniz: ");
        scanf("%d", &secim);
        
        if (secim == 0) {
            printf("Programdan cikiliyor...\n");
            kontrol = 0;
        } else if (secim == 1) {
            printf("Fonksiyonu giriniz (orn: log_x(sin(5x^2 + sin5x))): ");
            scanf(" %[^\n]s", ifade);
            printf("Baslangic (a) ve Bitis (b) degerlerini giriniz: ");
            scanf("%lf %lf", &a, &b);
            printf("Hata toleransini giriniz: ");
            scanf("%lf", &hataDegeri);
            IslemAgaci* f1 = ayristiriciOlustur(ifade);
            ikiyeBolmeYontemi(f1, a, b, hataDegeri);
            agaciSerbestBirak(f1);
        } else if (secim == 2) {
            printf("Fonksiyonu giriniz: ");
            scanf(" %[^\n]s", ifade);
            printf("Baslangic (a) ve Bitis (b) degerlerini giriniz: ");
            scanf("%lf %lf", &a, &b);
            printf("Hata toleransini giriniz: ");
            scanf("%lf", &hataDegeri);
            IslemAgaci* f2 = ayristiriciOlustur(ifade);
            regulaFalsiYontemi(f2, a, b, hataDegeri);
            agaciSerbestBirak(f2);
        } else if (secim == 3) {
            printf("Fonksiyonu giriniz: ");
            scanf(" %[^\n]s", ifade);
            printf("Baslangic tahmini (x0) giriniz: ");
            scanf("%lf", &a);
            printf("Hata toleransini giriniz: ");
            scanf("%lf", &hataDegeri);
            IslemAgaci* f3 = ayristiriciOlustur(ifade);
            newtonRaphsonYontemi(f3, a, hataDegeri);
            agaciSerbestBirak(f3);
        } else if (secim == 4) {
            matrisTersiYontemi();
        } else if (secim == 5) {
            choleskyYontemi();
        } else if (secim == 6) {
            gaussSeidelYontemi();
        } else if (secim == 7) {
            printf("Fonksiyonu giriniz: ");
            scanf(" %[^\n]s", ifade);
            printf("x degerini giriniz: ");
            scanf("%lf", &a);
            printf("Adim buyuklugunu (h) giriniz (orn: 0.01): ");
            scanf("%lf", &h);
            IslemAgaci* f7 = ayristiriciOlustur(ifade);
            SayisalTurev(f7, a, h);
            agaciSerbestBirak(f7);
        } else if (secim == 8) {
            printf("Fonksiyonu giriniz: ");
            scanf(" %[^\n]s", ifade);
            printf("Alt sinir (a) ve Ust sinir (b) giriniz: ");
            scanf("%lf %lf", &a, &b);
            printf("Dilim sayisini (N) giriniz: ");
            scanf("%d", &n);
            IslemAgaci* f8 = ayristiriciOlustur(ifade);
            simpsonYontemleri(f8, a, b, n);
            agaciSerbestBirak(f8);
        } else if (secim == 9) {
            printf("Fonksiyonu giriniz: ");
            scanf(" %[^\n]s", ifade);
            printf("Alt sinir (a) ve Ust sinir (b) giriniz: ");
            scanf("%lf %lf", &a, &b);
            printf("Dilim sayisini (N) giriniz: ");
            scanf("%d", &n);
            IslemAgaci* f9 = ayristiriciOlustur(ifade);
            trapezYontemi(f9, a, b, n);
            agaciSerbestBirak(f9);
        } else if (secim == 10) {
            gregoryNewtonYontemi();
        } else {
            printf("Gecersiz secim, lutfen tekrar deneyiniz.\n");
        }
    } while (kontrol);
    
    return 0;
}
