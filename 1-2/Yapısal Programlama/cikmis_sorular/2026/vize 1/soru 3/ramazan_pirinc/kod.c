// Cidden güzel soruydu. N adet öğrenci için nx2 matris oluşturmamızı, Extendandfill ile kullanıcıdan almamızı istiyordu. Ama öğrenciler 2'den fazla kurs seçebiliyordu (Kurs dediğimiz, ders kodu integer yani)
// Eğer öğrenci 2'den fazla kurs seçerse o satırı genişletmemizi, Print ile yazdırmamızı ve de FreeMemory ile hafızayı temizlememizi istiyordu
#include <stdio.h>
#include <stdlib.h>

int** CreateMatrix(int);
void ExtendandFill(int**,int,int**); // Sorunun güzelliği buradaydı. Bize 3 tane boşluk vermiş. Hocamız aslında kurs adedini bir yerde tut diyormuş :)
void PrintMatrix(int**,int,int*);
void FreeMemory(int**,int,int*);

int main() {
    int n;
    printf("Kac adet ogrenci girilecek\n");
    scanf( "%d", &n);
    int *sutun_sayilari = NULL; // Şimdi sorunun anahtarı olan bu diziye geleyim. Başta pointer olarak oluşturduk ama Extend'e pointer'ın adresini gönderdik
                                // Çünkü pointerda değişiklik yapılması için adresini göndermeliyiz. Gönderdiğimiz adresi içerde açıp mallocla dizi oluşturacağız
    int **matris = CreateMatrix(n);
    ExtendandFill(matris, n, &sutun_sayilari);
    PrintMatrix(matris, n, sutun_sayilari);
    FreeMemory(matris, n, sutun_sayilari);

    return 0;
}

int** CreateMatrix(int n) {
    int **mat = (int**)malloc(n * sizeof(int*));
    for (int i=0; i<n; i++) {
        mat[i] = (int*)malloc(2*sizeof(int));
    }
    return mat;
}

void ExtendandFill(int **mat, int n, int **colCounts) {
    *colCounts = (int*)malloc(n*sizeof(int)); // * koyduk artık bir pointer(dizi) hükmünde. Kullanıcıdan ne kadar gireceğini sorup (veya sormamıza izin yoksa counter tutup) her sütunun kurs adedini tutacağız

    for (int i=0; i<n; i++) {
        printf("%d. ogrenci kac kurs sececek? ", i + 1);
        scanf("%d", &((*colCounts)[i])); // Veya scanf("%d", *colCounts + i);

        if ((*colCounts)[i] > 2){ // realloc kullanımı: ilk parametre => değiştirilmek istenen alan, ikinci parametre => SON HALİNİN TOPLAM kaplayacağı alan. Realloc bu genişletilmiş alanı return eder. Biz de bunu mat[i]'ye atadık
            mat[i] = (int*)realloc(mat[i], (*colCounts)[i] * sizeof(int));
        }

        for (int j=0; j<(*colCounts)[i]; j++) {
            printf("%d. ogrenci: ", i+1);
            scanf("%d", *(mat+i)+j);
        }
    }
}

void PrintMatrix(int **mat, int n, int *colCounts) {
    for (int i=0; i<n; i++) {
        printf("Ogrenci %d: ", i+1);
        for (int j=0; j<colCounts[i]; j++) {
            printf("%d ", *(*(mat+i)+j));
        }
        printf("\n");
    }
}

void FreeMemory(int **mat, int n, int *colCounts) {
    for (int i=0; i<n; i++) {
        free(mat[i]);
    }
    free(mat);      
    free(colCounts);
}