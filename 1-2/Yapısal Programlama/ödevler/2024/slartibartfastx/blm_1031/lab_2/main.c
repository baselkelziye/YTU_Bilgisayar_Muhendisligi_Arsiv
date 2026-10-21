#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KELIME_UZUNLUK 50

int elemanGir(char** kelimeler, int kelimeSayisi);
void diziyiYazdir(char** kelimeler, int kelimeSayisi, int enUzunKelimeUzunlugu);
void diziyiSil(char** kelimeler, int kelimeSayisi);
void satirBoyutunuAyarla(char** kelimeler, int kelimeSayisi, int enUzunKelimeUzunlugu);

int main() {
	int i,j;
    char** kelimeler = NULL;
    int kelimeSayisi, enUzunKelimeUzunlugu = 0;

    printf("Kac kelime gireceksiniz? ");
    scanf("%d", &kelimeSayisi);

    kelimeler = (char**)malloc(kelimeSayisi * sizeof(char*));
    
    for (i = 0; i < kelimeSayisi; i++) {
        kelimeler[i] = (char*)malloc(MAX_KELIME_UZUNLUK * sizeof(char));
    }

    elemanGir(kelimeler, kelimeSayisi);

    for (i = 0; i < kelimeSayisi; i++) {
        int kelimeUzunlugu = strlen(kelimeler[i]);
        if (kelimeUzunlugu > enUzunKelimeUzunlugu) {
            enUzunKelimeUzunlugu = kelimeUzunlugu;
        }
    }

    satirBoyutunuAyarla(kelimeler, kelimeSayisi, enUzunKelimeUzunlugu);

    diziyiYazdir(kelimeler, kelimeSayisi, enUzunKelimeUzunlugu);

    diziyiSil(kelimeler, kelimeSayisi);

    return 0;
}

int elemanGir(char** kelimeler, int kelimeSayisi) {
    int i;

    for (i = 0; i < kelimeSayisi; i++) {
        printf("Kelime %d: ", i + 1);
        scanf("%s", kelimeler[i]);
    }
       for (i = 0; i < kelimeSayisi; i++) {
         if (strlen(kelimeler[i]) > MAX_KELIME_UZUNLUK) {
         	printf("Girilen kelime 50 karakterden uzun. Program sona eriyor.\n");
           diziyiSil(kelimeler, kelimeSayisi);  
		   return 0;    
        }
    }
    return 0;
}

void satirBoyutunuAyarla(char** kelimeler, int kelimeSayisi, int enUzunKelimeUzunlugu) {
    int i;
    for (i = 0; i < kelimeSayisi; i++) {
        kelimeler[i] = (char*)realloc(kelimeler[i], (enUzunKelimeUzunlugu + 1) * sizeof(char));
    }
}


void diziyiYazdir(char** kelimeler, int kelimeSayisi, int enUzunKelimeUzunlugu) {
    int i, j;

    printf("\nMatris:\n");
    for (i = 0; i < kelimeSayisi; i++) {
        int kelimeUzunlugu = strlen(kelimeler[i]);
        printf("%s", kelimeler[i]);

        for (j = 0; j < enUzunKelimeUzunlugu - kelimeUzunlugu; j++) {
            printf("*");
        }

        printf("\n");
    }
}


void diziyiSil(char** kelimeler, int kelimeSayisi) {
    int i;

    for (i = 0; i < kelimeSayisi; i++) {
        free(kelimeler[i]);
    }
    free(kelimeler);

    kelimeSayisi = 0; 
}
