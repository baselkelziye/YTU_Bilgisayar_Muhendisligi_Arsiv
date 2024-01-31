#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MODEL_NAME_LENGTH 30
#define TABAN_ARABA_UZUNLUGU 0

void mainWrapper();

typedef struct Araba
{
  char MODEL[MAX_MODEL_NAME_LENGTH];
  int YIL;
  int SATIS_FIYATI;
  int ADET;
} Araba;

typedef int (*comparatorFunc)(char *a, char *b);

Araba **allocateArabaListesi(int arabaCount);
Araba **arabaEkle(Araba **arabaListesi, int *arabaCount, Araba araba);
Araba **birBirimGenislet(Araba **arabaListesi, int *arabaCount);
void printCars(Araba **arabaListesi, int arabaCount);
void temizleArabaListesi(Araba **arabaListesi, int arabaCount);
void arabalariSiralaWrapper(Araba **arabaListesi, int arabaCount, comparatorFunc comparator);

int artanSiralama(char *a, char *b);
int azalanSiralama(char *a, char *b);

int main()
{
  mainWrapper();

  return 0;
}

void mainWrapper()
{
  int i;
  int arabaCount = TABAN_ARABA_UZUNLUGU;
  char input, input2;
  Araba eklenecekAraba;
  Araba **arabaListesi, **siraliArabaListesi;

  Araba test1 = {"FiatModel1", 2019, 200000, 3};
  Araba test2 = {"Mercedes1", 2020, 600000, 10};
  Araba test3 = {"RenaultModel1", 2020, 185000, 5};

  arabaListesi = allocateArabaListesi(arabaCount);

  arabaListesi = arabaEkle(arabaListesi, &arabaCount, test1);
  arabaListesi = arabaEkle(arabaListesi, &arabaCount, test2);
  arabaListesi = arabaEkle(arabaListesi, &arabaCount, test3);

  do
  {
    printf("Cikmak icin 0, araba eklemek icin 1, var olan listeyi goruntulemek icin 2 yazip enter basiniz.\n");
    scanf(" %c", &input);

    switch (input)
    {
    case '1':
      printf("----------------\n");
      printf("Ekleyeceginiz yeni arabanin MODELi: ");
      scanf("%s", &eklenecekAraba.MODEL);
      printf("Ekleyeceginiz yeni arabanin YILi: ");
      scanf("%d", &eklenecekAraba.YIL);
      printf("Ekleyeceginiz yeni arabanin SATIS_FIYATi: ");
      scanf("%d", &eklenecekAraba.SATIS_FIYATI);
      printf("Ekleyeceginiz yeni arabanin ADETi: ");
      scanf("%d", &eklenecekAraba.ADET);

      printf("-------EKLENDI---------\n");
      arabaListesi = arabaEkle(arabaListesi, &arabaCount, eklenecekAraba);
      break;
    case '2':
      printf("  Artan siralamada ise 1, azalan sirama ise 2 yaziniz.");
      scanf(" %c", &input2);

      //Normalde böhyle bir dizayn ile gitmezdim cünkü her printte maliyet oluyor. Onun yerine her giriş yapıldığında optimize bir
      // siralama algoritmasi yapip eğer descending sorulursa diziyi ters şekilde yazdirirdim. Fakat func pointer kullanilmam isteniyor
      // Ve ilgili bir sort algoritmasi istendigi icin bu sekilde yapiyorum

      siraliArabaListesi = (Araba **)malloc(arabaCount * sizeof(Araba *));
      memcpy(siraliArabaListesi, arabaListesi, arabaCount * sizeof(Araba *));
      if (input2 == '1')
      {
        printf("------ARTAN SIRALAMA----------\n");
        arabalariSiralaWrapper(siraliArabaListesi, arabaCount, &artanSiralama);
        printCars(siraliArabaListesi, arabaCount);

        free(siraliArabaListesi);
        printf("----------------\n");
      }
      else if (input2 == '2')
      {

        printf("--------AZALAN SIRALAMA--------\n");
        arabalariSiralaWrapper(siraliArabaListesi, arabaCount, &azalanSiralama);
        printCars(siraliArabaListesi, arabaCount);

        free(siraliArabaListesi);
        printf("----------------\n");
      }
      else
      {
        printf(">>> Hatali giris yaptiniz. Sadece 1 ya da 2 girin\n");
      }

      break;
    }
  } while (input != '0');

  temizleArabaListesi(arabaListesi, arabaCount);
  // printCars(arabaListesi, arabaCount);
}
Araba **arabaEkle(Araba **arabaListesi, int *arabaCount, Araba araba)
{
  Araba *sonAraba;
  arabaListesi = birBirimGenislet(arabaListesi, arabaCount);
  sonAraba = arabaListesi[(*arabaCount) - 1];

  strcpy(sonAraba->MODEL, araba.MODEL);
  sonAraba->YIL = araba.YIL;
  sonAraba->SATIS_FIYATI = araba.SATIS_FIYATI;
  sonAraba->ADET = araba.ADET;

  return arabaListesi;
}
Araba **birBirimGenislet(Araba **arabaListesi, int *arabaCount)
{
  (*arabaCount)++;
  Araba **yeniArabaListesi = (Araba **)realloc(arabaListesi, (*arabaCount) * sizeof(Araba *));
  yeniArabaListesi[(*arabaCount) - 1] = (Araba *)malloc(sizeof(Araba));
  return yeniArabaListesi;
}
Araba **allocateArabaListesi(int arabaCount)
{
  int i;
  Araba **arabaListesi = (Araba **)malloc(arabaCount * sizeof(Araba *));

  if (arabaListesi == NULL)
  {
    printf("Memory hatasi.\n");
    exit(1);
  }

  for (i = 0; i < arabaCount; i++)
  {
    arabaListesi[i] = (Araba *)malloc(sizeof(Araba));
    if (arabaListesi[i] == NULL)
    {
      printf("memory error.\n");
      exit(1);
    }
  }
  return arabaListesi;
}
void temizleArabaListesi(Araba **arabaListesi, int arabaCount)
{
  int i;
  for (i = 0; i < arabaCount; i++)
  {
    free(arabaListesi[i]);
  }
  free(arabaListesi);
}
int artanSiralama(char *a, char *b)
{
  return strcmp(a, b);
}
int azalanSiralama(char *a, char *b)
{
  return strcmp(b, a);
}
void arabalariSiralaWrapper(Araba **arabaListesi, int arabaCount, comparatorFunc comparator)
{
  int i, j;
  Araba *temp;
  for (i = 0; i < arabaCount - 1; i++)
  {
    for (j = i + 1; j < arabaCount; j++)
    {
      //if (strcmp(arabaListesi[i]->MODEL, arabaListesi[j]->MODEL) > 0)
      if (comparator(arabaListesi[i]->MODEL, arabaListesi[j]->MODEL) > 0)
      {
        temp = arabaListesi[i];
        arabaListesi[i] = arabaListesi[j];
        arabaListesi[j] = temp;
      }
    }
  }
}

void printCars(Araba **arabaListesi, int arabaCount)
{
  int i;
  for (i = 0; i < arabaCount; i++)
  {
    printf("%s, %d, %d, %d\n", arabaListesi[i]->MODEL, arabaListesi[i]->YIL, arabaListesi[i]->SATIS_FIYATI, arabaListesi[i]->ADET);
  }
}