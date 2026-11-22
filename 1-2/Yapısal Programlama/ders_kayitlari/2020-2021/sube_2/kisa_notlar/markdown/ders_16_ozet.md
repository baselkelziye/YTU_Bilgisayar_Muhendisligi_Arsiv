# Ders 16 Çalışma Özeti

## Genel Konular

- Oturumun yapısı
  - Bu kayıt kısa bir soru çözümü oturumudur. Dev-C++ ortamında struct dizisiyle bir öğrenci listesi programı baştan kodlandı. Ardından hazır bir çözüm dosyası üzerinden araç (CAR) sorusu, karmaşık sayı dizisinin işaretçiyle yazdırılması ve üç boyutlu dizilerde işaretçi aritmetiği gösterildi. Sonunda struct ile ilgili önceki haftanın konuları kısaca tekrar edildi.
- Soru: Öğrenci bilgilerini dinamik struct dizisinde tutmak (ekrandan, 00:15:00, 00:20:00, 00:45:00)
  - Her öğrencinin ID, yaş, not ve ad bilgisi vardır. Öğrenci sayısı $N$ kullanıcıdan alınır, dizi dinamik olarak açılır, veriler `main` içinde okunur.
  - Struct tanımı: `typedef struct STD { int id, age, grade; char name[20]; } STUDENT;`
  - Fonksiyonlar: `liste_yaz` (ekrana tablo halinde yazar), `nota_gore_sirala`, `ada_gore_sirala`. `main` sırasıyla listeyi yazar, nota göre sıralar, yazar, ada göre sıralar, yazar ve `free(std)` ile belleği bırakır.
- `typedef struct STD { ... } STUDENT;` yazımında etiket adı
  - `STD` etiketi yazılırsa hem `struct STD a;` hem `STUDENT b;` ile değişken tanımlanabilir. Etiket yazılmazsa yalnız `STUDENT` adı kullanılabilir. Kısa olduğu için genelde `STUDENT` tercih edilir.
- `calloc` ile struct dizisi açma (ekrandan, 00:20:00)
  - `std = (STUDENT*)calloc(N, sizeof(STUDENT));` İlk parametre eleman sayısı, ikincisi bir elemanın bayt cinsinden boyutudur. `calloc` `malloc`'tan farklı olarak alanı sıfırlar.
  - Dönen işaretçi `NULL` değilse veri okunur, değilse `"Error"` yazılır.
- Struct dizisi elemanına erişim ve `scanf`
  - `&std[i].id`, `&std[i].grade`, `&std[i].age`: dizinin $i$. elemanının ilgili alanının adresi. Alanlar ayrı adreslerde olduğu için `&` gerekir.
  - `std[i].name` bir karakter dizisidir; dizi adı zaten adres olduğu için `&` yazılmaz ve format `%s` olmalıdır (ilk yazımda `%d` hatası düzeltildi).
- Sıralama ve struct takası (ekrandan, 00:35:00, 00:40:00)
  - İç içe iki döngüyle kabarcık benzeri bir sıralama yazıldı. Takas için `STUDENT tmp;` kullanılır; `tmp = std[j]; std[j] = std[j+1]; std[j+1] = tmp;` ile struct'ın bütün alanları bir seferde kopyalanır.
  - Nota göre: `std[j].grade < std[j+1].grade` ise takas (büyükten küçüğe).
  - Ada göre: `strcmp(std[j].name, std[j+1].name)` sonucuna göre takas. İlk yazım `== 1` idi; derste `> 0` yazmanın daha doğru olduğu söylendi.
  - Fonksiyon `void`'dir, çünkü gönderilen dizinin kendisi (adres) değişir; yeni bir dizi döndürmeye gerek yoktur.
- `strcmp` ile string karşılaştırma
  - İki string `<`, `>` ile doğrudan karşılaştırılamaz. `strcmp` karakter karakter çıkarma yapar (Assembly'deki `cmp` mantığına benzer).
  - Bir öğrencinin önerdiği "karakterlerin ASCII değerlerini toplayıp karşılaştırma" yöntemi yanlıştır: `ABA` ile `BAA` toplamları eşittir ama stringler farklıdır.
  - ASCII sırası nedeniyle büyük harfle başlayan adlar küçük harfle başlayanlardan önce gelir.
- Çok ölçütlü sıralama
  - Notları aynı olanları ada göre sıralamak için tek sıralama içinde ikinci bir `if` eklenir. Bu, nesneye yönelik programlamada ve veri yapılarında sık kullanılan nesne sıralamasının (object sorting) temelidir.
- Soru: CAR struct'ı ve `AllocateSpace` (ekrandan, 00:50:00)
  - `typedef struct car { unsigned int fiyat; unsigned int model; char marka[25]; } CAR;`
  - `CAR* AllocateSpace(int)` diziyi fonksiyon içinde heap'te açıp adresini döndürür. `get_info` verileri okur, `write_info` yazar, `FindCars(CAR*, int, int)` model yılı verilen yıla eşit olan araçları yazar.
- İşaretçi döndüren fonksiyon ve heap/stack
  - Fonksiyondaki yerel işaretçi değişkeni stack'tedir ve fonksiyon bitince yok olur. `malloc` ile heap'te açılan alan kalıcıdır; adresi döndürülürse çağıran yer bu alanı kullanmaya devam eder.
- Karmaşık sayı dizisini yazdırmanın üç yolu (ekrandan, 00:55:00)
  - İndeksle `c[i].real`, geçici işaretçiyle `tmp->real` ve `tmp++`, işaretçi aritmetiğiyle `*(c+i)`. Dizinin başını kaybetmemek için ayrı bir `tmp` işaretçisi kullanılır; `tmp++` işaretçiyi struct boyutu kadar ilerletir.
- Üç boyutlu diziler (ekrandan, 01:00:00)
  - `int a[2][2][2] = {{{0,1},{2,3}},{{4,5},{6,7}}};` biçiminde iç içe süslü parantezle ilk değer verilir.
  - `a[i][j][k]` ile `*(*(*(a+i)+j)+k)` aynı elemana erişir: $i$ hangi matris, $j$ o matrisin hangi satırı, $k$ hangi sütun.
- Struct tekrarı
  - `typedef` ile yeni tür adı tanımlanır. Struct işaretçisi kullanılmadan önce geçerli bir struct değişkenini göstermelidir.
  - İki işaretçi aynı struct'ı gösterirse (sığ kopya, shallow copy) birindeki değişiklik diğerinden de görülür.
  - Struct değişkeni fonksiyona değerle (call by value) gider; asıl değişkeni değiştirmek için adresi gönderilir. Struct dizisi ise adres olarak gider.

## Hocanın Özellikle Vurguladığı Kısımlar

- String karşılaştırmasında `strcmp` kullanılmalı
  - ASCII toplamı gibi kestirme yöntemler farklı stringleri eşit gösterebilir. `strcmp` sonucu `0`'dan büyük/küçük diye denetlenmelidir.
- Struct'ı `tmp` ile takas etmek her zaman güvenli değildir
  - Bu soruda struct'ın alanları sabit boyutludur ($3 \times 4 + 20 = 32$ bayt). İçinde işaretçi olan struct'larda düz atama yalnız adresi kopyalar; bu durumda `memcpy` gibi yöntemler gerekir (sonraki konularda ele alınacak).
- Dizinin başını gösteren işaretçiyi kaybetmeyin
  - İşaretçi aritmetiğiyle dolaşırken ayrı bir geçici işaretçi kullanılmalıdır.
- Operatörleri birbiri cinsinden yazabilmek
  - `.`, `->`, `*`, `[]` operatörlerinin birbirine nasıl çevrildiğini öğrenin.
- Fonksiyon dönüş türünü gerekçelendirmek
  - Ekrana yazan bir fonksiyon için `void` uygundur; başarı bilgisi döndürmek isteyen `int` kullanabilir. Makul gerekçe yeterlidir.

## Kısa Tekrar Notları

- `calloc(N, sizeof(STUDENT))`: $N$ eleman, alan sıfırlanır; `NULL` kontrolü yapılır, iş bitince `free`.
- `scanf("%d", &std[i].id);` ama `scanf("%s", std[i].name);` (dizi adı adrestir).
- Struct atama `tmp = std[j];` bütün alanları kopyalar.
- `strcmp(a, b)`: negatif $\Rightarrow$ `a` önce, `0` $\Rightarrow$ eşit, pozitif $\Rightarrow$ `a` sonra. `== 1` değil `> 0` yazılır.
- ASCII: `'A' = 65`, `'B' = 66`, `'a' = 97`; büyük harfler küçüklerden önce sıralanır.
- Heap'te açılan alanın adresi fonksiyondan döndürülebilir; yerel dizinin adresi döndürülmez.
- `a[i][j][k] == *(*(*(a+i)+j)+k)`.
- `(c+i)->real == (*(c+i)).real == c[i].real`.

## Detaylı Açıklamalar

- Öğrenci programının tamamı karelerden derlendi (ekrandan, 00:15:00 - 00:45:00). Derste parametre adı `N`, döngülerde `n` olarak karışık yazılmıştı; aşağıda tek ad kullanıldı ve `strcmp` koşulu derste önerilen `> 0` biçimine getirildi. Kod `gcc -Wall` ile uyarısız derlendi; dört öğrencilik bir girdiyle (notlar 88, 34, 6, 4) çalıştırıldı, nota göre sıra 88, 34, 6, 4; ada göre sıra `Aa`, `BA`, `Ba`, `aa` çıktı.

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STD{
 int id, age, grade;
 char name[20];
}STUDENT;

void liste_yaz(STUDENT* std, int n);
void nota_gore_sirala(STUDENT* std, int n);
void ada_gore_sirala(STUDENT* std, int n);

int main(){
    int N, i;
    STUDENT *std;
    printf(" N degeri"); scanf("%d",&N);
    std = (STUDENT*)calloc(N,sizeof(STUDENT));
    if(std!=NULL){
        for(i=0;i<N;i++){
            printf("%d. Ogrenci id",i); scanf("%d",&std[i].id);
            printf("%d. Ogrenci adi",i); scanf("%s",std[i].name);
            printf("%d. Ogrenci notu",i); scanf("%d",&std[i].grade);
            printf("%d. Ogrenci yasi",i); scanf("%d",&std[i].age);
        }
        liste_yaz(std, N);
        nota_gore_sirala(std, N);
        liste_yaz(std, N);
        ada_gore_sirala(std, N);
        liste_yaz(std, N);
        free(std);
    }
    else{
        printf("Error");
        return 0;
    }
    return 0;
}
void nota_gore_sirala(STUDENT* std, int n){
    int i, j;
    STUDENT tmp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(std[j].grade<std[j+1].grade){
                tmp=std[j];
                std[j]=std[j+1];
                std[j+1]=tmp;
            }
        }
    }
}
void ada_gore_sirala(STUDENT* std, int n){
    int i, j;
    STUDENT tmp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(strcmp(std[j].name,std[j+1].name)>0){
                tmp=std[j];
                std[j]=std[j+1];
                std[j+1]=tmp;
            }
        }
    }
}
void liste_yaz(STUDENT* std, int n){
    int i;
    printf("\nID\tAD\tNOT\tYAS\n");
    for(i=0;i<n;i++){
        printf("%d\t%s\t%d\t%d\n",std[i].id,std[i].name,std[i].grade,std[i].age);
    }
}
```

- Prototipler `main`'den önce yazılmalıdır; `STUDENT` türü kullanıldığı için prototipler struct tanımından sonra gelir. İleride fonksiyonlar ayrı bir başlık dosyasına (header) taşındığında prototiplerde tür adları açıkça yazılmalıdır.
- Sıralama döngüsünde iç döngü `j < n-1` ile her geçişte bütün diziyi dolaşır. Derste `j < n-1-i` yazmanın düşünüldüğü ama ekranda `n-1` bırakıldığı görüldü; iki biçim de doğru sonuç verir, `n-1-i` gereksiz karşılaştırmaları atlar.
- CAR sorusunda `AllocateSpace` fonksiyonunun içinde yerel bir `CAR *` değişkeni tanımlanır, `malloc` ile heap'te $N$ elemanlık yer açılır ve adres döndürülür. Fonksiyon bitince yerel işaretçi stack'ten silinir, ama heap'teki alan durur; `main` dönen adresi `ptrCar`'da saklar. Daha önceki haftalarda en küçük elemanın değerini, indisini ve adresini döndüren üç fonksiyon yazılmıştı; adres döndüren sürüm de bir işaretçi döndürüyordu.
- Karmaşık sayı örneğinde `COMPLEX *tmp = c;` ile başlangıç adresi yedeklenir. `tmp->real` ifadesi "tmp'nin gösterdiği struct'ın real alanı" demektir. `tmp++` ile işaretçi `sizeof(COMPLEX)` bayt ilerler.
- Üç boyutlu dizide `a + i` $i$. matrisin adresini, `*(a+i) + j` o matrisin $j$. satırının adresini, `*(*(a+i)+j) + k` o satırın $k$. elemanının adresini verir. En dıştaki `*` değeri okur. Bu ifadeyi içeren tam program derste ekranda tamamlandı; aşağıdaki sürüm derlendi ve iki yöntemle de `0 1 2 3 4 5 6 7` yazdırdı. <!-- BELİRSİZ: Ekrandaki son ilk değer listesi karede görünmüyor; 01:00:00 karesinde {{{0,1},{2,3}},{{4,5},{5,6}}} yazıyor, altyazıda sonradan 0-7 yazdırıldığı söyleniyor. -->

```c
#include <stdio.h>
int main(){
int a[2][2][2]={{{0,1},{2,3}},{{4,5},{6,7}}};
int i, j, k;
for(i=0;i<2;i++){
    for(j=0;j<2;j++){
        for(k=0;k<2;k++){
            printf("%d ",a[i][j][k]);
        }
        printf("\n");
    }
}
for(i=0;i<2;i++)
    for(j=0;j<2;j++)
        for(k=0;k<2;k++)
            printf("%d ",*(*(*(a+i)+j)+k));
printf("\n");
return 0;
}
```

- Ders sonrası not: Hoca `strcmp`'nin yalnız `-1`, `0`, `1` döndürdüğünü ve bir yerde "-1 dönerse birincisi daha büyüktür" dedi. Doğrusu: C standardı yalnız işareti tanımlar (negatif, sıfır, pozitif); negatif sonuç birinci stringin sözlük sırasında önce geldiğini (daha küçük olduğunu) gösterir. Bu yüzden `== 1` yerine `> 0` yazılmalıdır; hoca da derste buna geçti.
- Ders sonrası not: Hoca `'B'` için 67 dedi; doğrusu `'A' = 65`, `'B' = 66`, `'C' = 67`, `'a' = 97`.
- Ders sonrası not: Hoca içinde `char *` olan bir struct'ın `tmp` ile kopyalanırken "ne kadar yer kaplayacağının belli olmadığını" söyledi. Struct'ın boyutu işaretçi alanı olsa da derleme anında sabittir; sorun, atamanın gösterilen karakterleri değil yalnız adresi kopyalamasıdır (sığ kopya).
- Ders sonrası not: Ekrandaki karmaşık sayı dosyasında yorum satırı olarak duran `*(c+i).real` ifadesi derlenmez, çünkü `.` operatörü `*`'dan önce uygulanır. Doğrusu `(*(c+i)).real` ya da `(c+i)->real`'dir (gcc ile denendi).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
