# Ders 8 Genişletilmiş Notu: Dinamik Bellek Yönetimi ve Fonksiyonlara Parametre Aktarımı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Karakter matrisinde gösterici kullanımı (önceki dersin devamı)
- 2. Göstericiyi gösteren gösterici
- 3. Bellek ayırma fonksiyonları
- 4. Tek boyutlu dinamik alan ve NULL kontrolü
- 5. Dinamik iki boyutlu matris
- 6. Metin matrisi üzerinde gösterici aritmetiği
- 7. Dinamik alan üzerinde sıralama
- 8. Değerle ve adresle parametre aktarımı
- 9. Dizileri fonksiyona parametre olarak aktarma
- 10. Fonksiyondan dizi döndürme
- Örnek Sorular
- Dersin Toparlaması

## 1. Karakter matrisinde gösterici kullanımı (önceki dersin devamı)

Ders, önceki derste karakter matrisi (`char metinler[...][...]`) üzerinde yazılan dizgi işlemlerinin kısa bir tekrarıyla başladı. Hatırlatılan konular şunlardı: bir dizgi içinde başka bir dizgiyi arayan kod, dizgi uzunluğunu sonlandırıcı karaktere kadar ilerleyerek bulma, hazır `strstr` fonksiyonunun bir gösterici döndürmesi ve aranan konumun "başlangıç adresi ile dönen adres arasındaki fark" olarak bulunması, küçük-büyük harf dönüşümünde ASCII kodları arasındaki 32 farkı (yalnız aksansız `A`–`Z` harfleri için geçerli).

### 1.1 Bir satırın ortasından başlayarak yazdırma

Önceki derste `char *p` göstericisine `&metinler[0][1]` yani sıfırıncı satırın ikinci karakterinin adresi atanmış ve `listOneLineOfText(p)` ile satır o karakterden başlayarak yazdırılmıştı. Hoca bu sefer ara göstericiye gerek olup olmadığını denedi: `listOneLineOfText(&metinler[0][1]);` biçiminde adres doğrudan parametre olarak verildi (ekrandan, 00:10:00). Fonksiyonun imzası zaten bir `char *` beklediği için bu çağrı sorunsuz çalıştı ve aynı çıktı alındı.

### 1.2 İki karakterin farkını tamsayı olarak yazdırma

Sonra şu satır denendi (ekrandan, 00:15:00):

```c
printf("%d", metinler[1][3] - metinler[1][2]);
```

İki karakter çıkarıldığında aslında ASCII kodları çıkarılır ve `%d` ile fark tamsayı olarak yazılır. Örnekte ilgili harfler arasında iki harf olduğu için ekrana 2 yazıldı. Aynı ifade `%s` ile yazdırılmaya çalışılırsa anlamsız bir sonuç çıkar, çünkü sayısal değer bir adres gibi yorumlanır; `%c` ile yazdırılırsa o koda karşılık gelen (belki görünmez, örneğin bip sesi üreten) karakter basılır.

## 2. Göstericiyi gösteren gösterici

Göstericiler tek düzeyde kalmak zorunda değildir; bir göstericiyi gösteren gösterici de tanımlanabilir. Ekrandaki örnek (ekrandan, 00:20:00):

```c
int r = 5;
int *q = &r;
int **p = &q;
//p=&q;   (tanım ve atama ayrı satırlarda da yazılabilir)
```

`q`, `r`'yi gösteren bir göstericidir. `p` ise göstericinin göstericisidir, bu yüzden iki yıldızla tanımlanır ve `q`'nun adresini tutar. Tanım ve ilk değer ataması aynı satırda yapılabileceği gibi `int **p;` tanımından sonra `p = &q;` diye de yazılabilir.

Bu durumda `r = 10;`, `*q = 10;` ve `**p = 10;` aynı işi yapar. Hepsinin aynı gözü etkilediğini göstermek için hoca atanan değerleri 10, 11, 12 yaptı ve her atamadan sonra `r`, `*q`, `**p` değerlerini yazdırdı (ara adım eklendi: programın tamamı aşağıda).

```c
#include <stdio.h>
int main(void) {
    int r = 5;
    int *q = &r;
    int **p = &q;
    r = 10;   printf("%d %d %d\n", r, *q, **p);
    *q = 11;  printf("%d %d %d\n", r, *q, **p);
    **p = 12; printf("%d %d %d\n", r, *q, **p);
    return 0;
}
```

Bu program ders sonrası `gcc -Wall` ile derlenip çalıştırıldı; çıktı `10 10 10`, `11 11 11`, `12 12 12` oldu. Göstericinin göstericisi olunca değere ulaşmak için iki yıldız (`**p`) yazmak gerekir.

Hoca bu yapının, ileride bir göstericinin başlangıç yerini korumak gibi durumlarda işe yarayacağını söyledi ve uyardı: bir yıldızın ya da bir `&` işaretinin olup olmaması sonucu tamamen değiştirebilir.

## 3. Bellek ayırma fonksiyonları

Dinamik bellek yönetimi bölümünde tek boyutlu bir dizi gibi alan ayırma, iki ve üç boyutlu matrisler için alan ayırma ve bunlarla çalışma görüldü. Üç temel fonksiyon `stdlib.h` içindedir (ekrandan, 00:25:00):

- `void* malloc(total_size_in_bytes)`: belirtilen bayt kadar yer ayırır, ayrılan bloğun başlangıç adresini döndürür.
- `void* calloc(number_of_elements, element_size)`: `malloc` gibidir, ama ayrılan baytları sıfırlar. İki parametresi vardır; toplam alan yine aynıdır: $\text{toplam} = n \times \text{eleman boyutu}$.
- `void* realloc(void *prev_ptr, total_size_in_bytes)`: daha önce ayrılmış `prev_ptr` bloğunun boyutunu değiştirir.

### 3.1 malloc ile calloc farkı

`malloc` ayırdığı alanı sıfırlamaz; daha önce o bellek bölgesinde başka kodlardan ne kalmışsa o değerler görülür. `calloc` alanı sıfırlar. Bu açıdan `calloc` avantajlıdır, ama sıfırlama için ek komut çalıştırdığı için `malloc` biraz daha hızlıdır. Hangisinin kullanılacağı problemin doğasına bağlıdır; mantık olarak ikisi aynıdır.

### 3.2 realloc

`realloc` ayrılmış bir bloğun kapasitesini artırır ya da azaltır. Bunu yaparken mevcut alanın sonuna mı ekleme yapacağı, yoksa her şeyi bellekte başka bir yere taşıyıp orada mı daha büyük yer açacağı garanti edilmez. Merak edilirse eski ve yeni göstericinin başlangıç adresleri karşılaştırılabilir: aynıysa sona eklenmiştir, farklıysa taşınmıştır. Yeni eklenen kısmın sıfırlanacağı da garanti değildir; farklı kütüphaneler bunu farklı gerçekleştirebilir. Tek garanti, önceki verinin kaybolmamasıdır; zaten öyle olmasaydı `realloc`'un bir anlamı kalmazdı.

### 3.3 Dönüş türü ve dönüştürme

Bu fonksiyonların dönüş türü `void*`'dır. Böylece ayrılan bellek her türlü veriyi saklamak için kullanılabilir. Bu yüzden dönen adres, alanda saklanacak veri türünün göstericisine dönüştürülür (cast). Toplam boyutu verebilmek için saklanacak veri türünün kaç baytla temsil edildiğini de bilmek gerekir: eleman sayısı × eleman boyutu.

### 3.4 free

> **Hocanın vurgusu:** Ayrılan bellek alanıyla iş bittikten sonra `free` fonksiyonuyla boşaltılmak zorundadır. C'de bellek yönetiminin bütün sorumluluğu programcıdadır. Her `malloc` ya da `calloc` için tam ona karşılık gelen bir `free` olacak; iç içe ayırmalarda en son açılan, en içteki blok önce kapatılır. Bu hem kendi çalışmanızda hem lablarda hem sınavlarda böyle yapılmalıdır.

`realloc` ile genişletilip taşınan bir alanda da en sonunda alanın (güncel) başlangıç göstericisi `free`'ye verilir.

## 4. Tek boyutlu dinamik alan ve NULL kontrolü

Dizilerin eleman sayısı tanımlandıktan sonra değiştirilemez. Dinamik bellek yönetiminde böyle bir sorun yoktur. Örnekte kullanıcı `n` tane sayı girecektir; `n` tamsayısı ve alanın başlangıcını tutacak bir `int *` gösterici tanımlanır. `n` okunduktan sonra:

```c
p = (int *) malloc(n * sizeof(int));
/* ya da: p = (int *) calloc(n, sizeof(int)); */
```

Buraya `n * 4` de yazılabilirdi, ama kodun taşınabilirliği düşer: başka bir platformda `int` iki ya da sekiz baytla temsil ediliyor olabilir. Bu yüzden `sizeof(int)` yazmak daha akıllıcadır.

Bellek istendi, ama bellekte boş yer olmayabilir. O zaman fonksiyon `NULL` döndürür ve bunun kontrol edilmesi gerekir:

```c
if (p == NULL) {
    printf("%s:%d>Can not allocate memory for the array...\n", __FILE__, __LINE__);
    return -1;
}
```

`__FILE__` ve `__LINE__` (iki alt çizgiyle başlayıp biten) hazır makrolardır: yazıldıkları yerde hangi `.c` dosyasında ve kaçıncı satırda bulunduklarını verirler. Kullanıcının bunu bilmesi gerekmeyebilir, ama programcıya hata ayıklamada kolaylık sağlar. Bellek ayrılamamışsa programın devam etmesinin anlamı yoktur; `main` içinde `return -1;` ya da `exit(-1);` ile çıkılır. Sorun yoksa alan kullanılır ve en sonunda `free(p);` yazılır.

## 5. Dinamik iki boyutlu matris

### 5.1 Düzensiz satırlar

Hoca bir tablolama programında iki boyutlu dinamik alanın yapısını çizdi (ekrandan, 00:35:00). Gösterici ile ayrılan bir `**mat` için, örneğin 5 satır düşünülürse, her satırın sütun sayısının eşit olması gerekmez. Örnekte beş satıra farklı uzunlukta beş isim yerleştirildi: bazı satırlar 4, bazıları 3, bazıları 5 karakterlik. Bunu 5×5 bir kare matris olarak tanımlamak zorunda olsaydık 25 hücre harcanacaktı; dinamik ayırmada gerekmeyen hücreler hiç yer kaplamaz. Çok boyutlu matrisler göstericiler üzerinden ayrıldığında altyapı hep böyledir.

Bu yüzden iki boyutlu bir alan ayrılırken önce kaç satır göstericisi gerektiği kadar yer ayrılır, sonra her satır için ayrı ayrı sütun sayısı kadar yer ayrılır. "Doğrudan 5×5 ya da 3×3×3 alan ver" diye bir kullanım yoktur.

### 5.2 Slayttaki kod

Slayttaki örnek (ekrandan, 00:30:00):

```c
int **mat, i;
int n,m;
printf("Please enter number of rows");scanf("%d", &n);
printf("Please enter number of columns");scanf("%d", &m);
mat = (int **) malloc( n * sizeof(int *) );
if(mat == NULL)  {
    printf("%s:%d>Can not allocate memory for the array...\n",__FILE__, __LINE__);
    return -1;
}
for(i = 0; i < n; i++)  {
    mat[i] = (int *)malloc(m * sizeof(int) );
}
//will be continued in the next slide
```

İlk `malloc`'ta satır göstericileri için yer ayrılır. Burada `sizeof(int *)` yazıldığına dikkat: satır dizisinin elemanları `int` değil `int` göstericisidir. İlk ayırmanın başarılı olduğu kontrol edildikten sonra döngüde her satır için `m * sizeof(int)` kadar yer ayrılır, çünkü satırlarda artık ilkel `int` değerleri saklanacaktır; dönen adres `int *`'a dönüştürülür. Böylece iki boyutlu `mat` aslında `mat[0]`, `mat[1]`, `mat[2]`, ... gibi gösterici dizileri olur. Örnekte `n` ile `m` aynı girilirse kare matris oluşur, ama satırlar istenirse farklı uzunlukta da ayrılabilir.

Matris işlemlerinden sonra eşlenik `free` komutları gerekir: satırlar bir döngüde `malloc` edildiği için önce yine bir döngüde her satır `free` edilir, en sonunda da `mat` boşaltılır.

```c
for (i = 0; i < n; i++)
    free(mat[i]);
free(mat);
```

### 5.3 Öğrenci sorusu

**Soru:** Kullanıcıdan dizinin uzunluğunu almadan, örneğin tek bir kelime için, kaç harfli olduğunu sormadan dinamik olarak yer ayırabilir miyiz?

**Cevap:** Sormadan mümkün değil. Girilecek metin bir yere atanacak ve o yer için önceden yer ayrılması gerekiyor. Sorulmazsa tahmin etmek gerekir (bin karakter mi, beş bin karakter mi?); tahmine dayalı ayırma, alan sonradan geri verilse bile, program çalıştığı sürece gereğinden fazla bellek harcar. Doğru yol, kullanıcıya önce kaç satır ve en fazla kaç karakter gireceğini sormak, sonra `malloc` ya da `calloc` ile o kadar yer ayırmaktır. Dinamik bellek yönetimi zaten bu esnekliği kazanmak için vardır. Örnekte satır sayısının sabit olması yalnız örneği kısa tutmak içindir.

## 6. Metin matrisi üzerinde gösterici aritmetiği

### 6.1 Programın kurulması

Ekrandaki program (ekrandan, 00:40:00, 00:45:00 ve 00:50:00) üç satırlık bir metin matrisi kurar:

```c
#define ROWS 3
#define COLS 64
...
char **text = (char**) calloc( ROWS, sizeof(char*) );
char *mat[ROWS] = {"012345\n","6789AB\n","CDEFGH\n"};
char *bp, *mp; /* same as char *bp; char *mp;
 Notice where * is aligned, *mp does not become **mp. */
if( text == NULL ) {
    printf("Can not allocate memory for the text"); return -1;
}
for( i=0; i < ROWS; i++ )
    text[i] = (char*) calloc( COLS, sizeof(char) );

strcpy(text[0], "012345\n");
strcpy(text[1], "6789AB\n");
strcpy(text[2], "CDEFGH\n");
for(i = 0; i < ROWS; i++)
    printf("%s",text[i]);
```

Satırlar `calloc` ile ayrıldığı için başlangıçta hepsi sıfırdır. `text` aslında satır sayısı kadar `char *` elemanı olan bir gösterici dizisidir; bu satırlara kullanıcı girişi yerine program içinden veri kopyalamak için `strcpy` kullanılır ve ilk parametre olarak başına yıldız koymadan `text[0]`, `text[1]`, `text[2]` verilir. Her satırın sonuna `\n` konmuştur ki yazdırırken otomatik olarak yeni satıra geçilsin. `strcpy` kopyanın sonuna `'\0'` ekler.

### 6.2 Yıldızın yeri

`char *bp, *mp;` satırındaki açıklama önemli bir ayrıntıyı anlatır. Yıldız `char`'a yapıştırılıp `char* bp, mp;` yazılırsa ikinci değişkenin yıldızı silinmiş olur: virgülle ayrılan her ad ayrı değerlendirilir, böylece `bp` gösterici, `mp` ise sıradan bir `char` olur. Boşluklar yalnız insanın daha iyi okuması içindir. Aynı türden birden fazla gösterici tanımlanacaksa her birinin başına yıldız konur.

> **Hocanın vurgusu:** Ufak ama önemli bir ayrıntı: yıldız konmayan ad, o türden normal bir değişken olur.

### 6.3 Çıktıların tahmini

Sonra `bp = text[0]; mp = text[1]; j = 1;` ile `bp` (beginning pointer) birinci satırın, `mp` (mid pointer) ikinci satırın başını gösterir; `j` çıktı numarasını tutar. Ekrandaki satırlar (ekrandan, 00:50:00 ve 01:25:00):

```c
printf("Output %d:%s", j, mp); j++; //(#1)
printf("Output %d:%s", j, mp+1); j++; //(#2)
printf("Output %d:%s", j, mp+2); j++; //(#3)
printf("Output %d:%s\n", j, text ); j++; //(#4) buggy
printf("Output %d:%s", j, *text ); j++; //(#5) **text:crash
printf("Output %d:%c\n", j, text ); j++; //(#6) buggy
printf("Output %d:%c\n", j, *bp); j++; //(#7) %c & *bp: OK
printf("Output %d:%c\n", j, bp); j++; //(#8)%c & bp: buggy
printf("Output %d:%c\n", j, *(bp+2) ); j++; //(#9)
printf("Output%d:%c\n", j, *text ); j++; //(#10)buggy
printf("Output%d:%c\n", j, **text ); j++; //(#11)
printf("Output%d:%c\n", j, *(*(text+1)+2) ); j++; //(#12)
printf("Output%d:%c\n", j, *((text[1])+3) ); j++; //(#13) +3:OK [3]:error
printf("Output%d:%c\n", j, *(*(mat+1))+3 ); j++; //(#14) +3:OK [3]:error
printf("Output%d:%c\n", j, *(*(mat+1)+2) ); j++; //(#15)
printf("Output%d:%d\n", j, mat[2][4]-mat[1][4] ); j++;//(#16)
```

Hoca her satır için önce tahmin yaptı, sonra programı çalıştırdı:

- **#1:** `mp` ikinci satırın başını gösterir; `%s` ile o satır yazılır: `6789AB` ve yeni satır.
- **#2:** `mp` sıradan bir `char *` olduğu için `mp+1` bir sonraki karakteri, yani `7`'yi gösterir. `%s` ilk `'\0'`'a kadar yazar: `789AB`.
- **#3:** Aynı mantıkla `89AB`.
- **#4:** `text` tek başına iki düzeyli bir göstericidir; `%s` ile verildiğinde birden fazla satır olduğu için doğru çalışmaz, "buggy"dir. Çalıştırıldığında anlamsız karakterler çıktı, hatta sonraki satırın görünümünü bozdu (ok, Home, End gibi tuşların kodlarına karşılık gelen kontrol karakterleri olabileceği söylendi).
- **#5:** `*text` ilk satırın başını verir; `%s` ile `012345`. Yerine `**text` verilirse program doğrudan çöker.
- **#6:** `%c` ile `text`: #4 ile aynı nedenle buggy.
- **#7:** `bp` normal bir `char *`; `*bp` ilk satırın ilk karakteri `0`'dır. Sorun yoktur.
- **#8:** Yıldız konmazsa `%c`, göstericinin tuttuğu adres değerini karakter olarak yazmaya çalışır; büyük bir onaltılık sayının en düşük baytına denk gelen anlamsız bir karakter basılır. Hocaya göre görece "güvenli" bir hatadır, yalnız garip bir karakter yazar.
- **#9:** `bp` sütunlar boyunca ilerler; `*(bp+2)` → `2`.
- **#10:** `%c` ile `*text`: `*text` bir `char *`'dır, tek karakter değildir; buggy.
- **#11:** `**text` en baştaki karakterdir: `0`.
- **#12:** `*(*(text+1)+2)`.
- **#13:** `*((text[1])+3)`.
- **#14, #15, #16:** aynı ifadelerin `char *mat[3]` dizgi sabitleri dizisi üzerinde denenmesi.

### 6.4 Hocanın düzelttiği tahmin: önce satır, sonra sütun

Hoca #12 için önce `D`, #13 için `E` tahmin etmişti (ilk toplamanın sütunda, ikincisinin satırda ilerlediğini düşünmüştü). Çalıştırınca #12'de `8`, #13'te `9` çıktı. Hoca hatasını şöyle açıkladı: `text+1` satır göstericileri dizisinde bir ilerler, yani bir satır aşağı iner; `*(text+1)` ikinci satırın başını verir; buna `+2` eklemek o satırda iki sütun ilerler. Sonuç `text[1][2]` = `8`'dir. #13'te `text[1]` zaten ikinci satırın başıdır, `+3` ile `text[1][3]` = `9` olur.

> **Hocanın vurgusu:** İlk toplama satırlarda, ikinci toplama sütunlarda gider. Bir dönem geçince bunu insan unutabiliyor; bu işlerle sürekli uğraşılmazsa yanılmak normaldir, o yüzden çok dikkatli olmak gerekir.

### 6.5 mat ile denemeler

Ara sonrası `char *mat[ROWS] = {"012345\n","6789AB\n","CDEFGH\n"};` dizisi de açıldı (ekrandan, 01:30:00). Bu bir dizgi sabitleri dizisidir ve içeriği `text` ile aynıdır.

- **#14:** `*(*(mat+1))+3`: parantez yeri önemlidir. `*(*(mat+1))` ikinci satırın ilk karakteri `'6'`'dır; buna 3 eklenince karakter kodu `'9'` olur. Sonuç `9`'dur, ama bu bir karaktere sayı eklemedir, matriste üç sütun ilerleme değildir.
- **#15:** `*(*(mat+1)+2)` → `mat[1][2]` = `8`. Hoca, #12 ile #15'in aynı biçimde çalıştığını gösterdi. Gösterilen karakterin sayı eklemesiyle mi yoksa gerçekten matriste ilerleyerek mi bulunduğundan emin olmak için ikinci satırın sonraki karakterleri değiştirildi ve #15'in hâlâ matristeki doğru hücreyi verdiği görüldü.
- **#16:** `%d` ile `mat[2][4]-mat[1][4]`: üçüncü satırın beşinci karakteri `G`, ikinci satırın beşinci karakteri `A`'dır. ASCII kodları 71 ve 65 olduğu için fark $71 - 65 = 6$'dır. Hoca daha sonra ikinci satırdaki `A` ve `B`'yi `X` ve `Y` yaptı; bu kez `G`'den `X` çıkarılınca fark ters yönde 17 oldu ($71 - 88 = -17$).
- **#17:** Köşeli parantez gösterimi `text[1][3]` de denendi; `9` verdi.

Ekrandaki çıktı listesi (ekrandan, 01:35:00) şöyleydi (buggy satırlar yorum satırı yapıldıktan sonra):

```text
1:6789AB
2:789AB
3:89AB
4:buggy
5:012345
6:buggy
7:0
8:buggy
9:2
10:buggy
11:0
12:8
13:9
14:9
15:8
16:6
17:9
```

En sonda `free` satırları da çalıştırıldı ve program sorunsuz sonlandı: önce döngüyle her satır, sonra `text`.

Buggy satırlar çıkarılarak yeniden düzenlenen program ders sonrası `gcc -Wall` ile derlenip çalıştırıldı ve yukarıdaki listeyle aynı sonuçları verdi:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 3
#define COLS 64
int main(void) {
    int i, j;
    char **text = (char **) calloc(ROWS, sizeof(char *));
    char *mat[ROWS] = {"012345\n", "6789AB\n", "CDEFGH\n"};
    char *bp, *mp;
    if (text == NULL) { printf("Can not allocate memory for the text"); return -1; }
    for (i = 0; i < ROWS; i++)
        text[i] = (char *) calloc(COLS, sizeof(char));
    strcpy(text[0], "012345\n");
    strcpy(text[1], "6789AB\n");
    strcpy(text[2], "CDEFGH\n");
    for (i = 0; i < ROWS; i++)
        printf("%s", text[i]);
    bp = text[0]; mp = text[1]; j = 1;
    printf("Output %d:%s", j, mp); j++;          /* 1 */
    printf("Output %d:%s", j, mp + 1); j++;      /* 2 */
    printf("Output %d:%s", j, mp + 2); j++;      /* 3 */
    j++;                                         /* 4 buggy: %s ile text */
    printf("Output %d:%s", j, *text); j++;       /* 5 */
    j++;                                         /* 6 buggy: %c ile text */
    printf("Output %d:%c\n", j, *bp); j++;       /* 7 */
    j++;                                         /* 8 buggy: %c ile bp */
    printf("Output %d:%c\n", j, *(bp + 2)); j++; /* 9 */
    j++;                                         /* 10 buggy: %c ile *text */
    printf("Output%d:%c\n", j, **text); j++;     /* 11 */
    printf("Output%d:%c\n", j, *(*(text + 1) + 2)); j++; /* 12 */
    printf("Output%d:%c\n", j, *((text[1]) + 3)); j++;   /* 13 */
    printf("Output%d:%c\n", j, *(*(mat + 1)) + 3); j++;  /* 14 */
    printf("Output%d:%c\n", j, *(*(mat + 1) + 2)); j++;  /* 15 */
    printf("Output%d:%d\n", j, mat[2][4] - mat[1][4]); j++; /* 16 */
    printf("Output%d:%c\n", j, text[1][3]); j++;         /* 17 */
    for (i = 0; i < ROWS; i++)
        free(text[i]);
    free(text);
    return 0;
}
```

> **Ders sonrası not:** Buggy satırlarda (`%s` ile `char **`, `%c` ile `char **` ya da `char *`) biçim belirteci ile argümanın türü uyuşmaz. Bu C standardına göre tanımsız davranıştır; `gcc -Wall` bu satırların hepsi için `-Wformat` uyarısı verir. Çıktının ne olacağı derleyiciye ve çalıştırmaya göre değişebilir; nitekim derste programın tekrar çalıştırılmasında #4'ün çıktısı değişti. `%s` ile `**text` verilmesi de bir karakter değerinin adres gibi kullanılması demektir ve çökme bu yüzden olur.

> **Ders sonrası not:** Hoca bir yerde "`text` iki boyutlu, pointer'ın pointer'ı değil" dedi. Türü bakımından `text` bir `char **`, yani göstericiyi gösteren göstericidir; her satırı ayrı ayrı ayrıldığı için iki boyutlu bir dizi gibi kullanılır. Hocanın anlatmak istediği, `text`'in tek bir karaktere değil satır göstericilerine işaret etmesi, bu yüzden tek karakter için iki kez `*` gerekmesidir.

### 6.6 Öğrenci soruları

**Soru:** Üçüncü çıktı tekrar açıklanabilir mi?

**Cevap:** Hoca tabloda `**text`'i çizdi (ekrandan, 01:40:00). Ayırma işlemlerinden sonra `text[0]`, `text[1]`, `text[2]` üç ayrı karakter göstericisi, yani üç ayrı tek boyutlu karakter dizisi gibi düşünülebilir. `mp = text[1]` olduğu için `mp` ikinci satırın ilk karakterini gösterir. `mp` tek düzeyli bir karakter göstericisi olduğu için `mp+1` bir sonraki hücreyi, `mp+2` ondan sonrakini gösterir. Ayrılan satırın sonuna kadar böyle gidilebilir; satırın dışına çıkılırsa ayrılmamış bir bellek bölgesine erişilir ve orada ne olduğu bilinmez. Program çökebilir de çökmeyebilir de; bu aynı zamanda bir güvenlik açığıdır. Derleyici ya da işletim sistemi bunu fark edip programı durdurabilir.

**Soru:** `mp` tek karakter gösteriyorsa neden yalnız `8` değil de `89AB` yazıldı?

**Cevap:** Çünkü `%s` kullanıldı. `printf`, `%s` ile verilen adresten başlar ve `'\0'` karakterini görene kadar yazar. Bu bölge ayrılan alanın içinde olduğu için sorun çıkmadı. `%c` kullanılsaydı yalnız tek karakter yazılırdı.

### 6.7 Ayrılan alanın dışına çıkma

Hoca #3'te `mp+2` yerine `mp+20` yazdı. Program çökmedi, bir şey de yazmadı. Hoca bunun, üç satırın toplamının (3 × 7 ≈ 20 karakter) hâlâ içinde kalınmasından olabileceğini düşündü. Sonra `mp+500` denendi: bu kez ekrana işletim sisteminin ortam değişkenlerinden biri (komut satırında yazılan bir programın, bulunduğu dizinde bulunamazsa arandığı diğer dizinlerin listesi, PATH) basıldı.

> **Hocanın vurgusu:** Buffer overflow hatası budur. Erişim hakkımız olmayan bir adrese erişebilmek, verilmemesi gereken bilgilerin dışarı sızması demektir.

> **Ders sonrası not:** Her satır `calloc(COLS, sizeof(char))` ile 64 karakter olarak ayrılmıştı; yani `mp+20` hâlâ `text[1]` satırının içindedir ve orası `calloc` sayesinde sıfırdır. `printf` hemen `'\0'` görüp boş dizgi yazdığı için hiçbir şey çıkmamıştır (ders sonrası denendi). Ayrıca ayrı `calloc` çağrılarıyla ayrılan satırların bellekte art arda durması garanti değildir. `mp+500` ise ayrılan bloğun dışındadır ve tanımsız davranıştır; oradan okunan içerik ortama göre değişir.

### 6.8 Sınavda çıktı tahmini için strateji

Hoca, bu örnekteki gibi çıktı tahmini sorularında şöyle çalışmayı önerdi: önce her satırı en iyi tahminle (eğitimli tahminle) yazıp bitirmek, sonra zaman kalırsa "hileli" olabilecek yerlere geri dönüp kontrol etmek. 15 çıktılık bir soruda iki çıktı karışsa bile çoğu doğru olur; kalan zaman en çok kazandıracak yerlere harcanmalıdır.

## 7. Dinamik alan üzerinde sıralama

Daha önceki sıralama örneklerinde sabit boyutlu diziler kullanılıyordu; parametre aktarımında sorunlar çıkıyor, global değişkenlere başvuruluyordu. Bu örnekte sıralama, dinamik olarak ayrılmış bir alan üzerinde yapıldı (ekrandan, 01:50:00 ve 01:55:00):

```c
void printList( int *list, int n );

int getPosOfMin( int *list, int n, int fromPos ) {
    int i, minIndex;
    minIndex = fromPos;
    for( i=fromPos+1; i<n; i++ )
        if( *(list+i) < *(list+minIndex) )
            minIndex = i;
    return minIndex;
}

void selectionSort( int *b, int n ) {
    int i, minPos, tmp;
    for( i=0; i<n-1; i++ ) {
        minPos = getPosOfMin( b, n, i );
        if( *(b+i) > *(b+minPos) ) {
            tmp = *(b+i); *(b+i) = *(b+minPos); *(b+minPos) = tmp;
        }
        //printList( b, n );
    }
}
```

`getPosOfMin` fonksiyonunun parametreleri:

- Birinci parametre, dinamik olarak ayrılmış bir alanın (artık "dizi" değil "liste") başlangıç göstericisidir.
- İkinci parametre `n`, kaç eleman arasında arama yapılacağıdır. Bu artık zorunludur: dizgilerle çalışırken sonu `'\0'` ile anlaşılıyordu, ama sayılarda böyle bir işaret yoktur. Alan keyfi genişlikte olabilir.
- Üçüncü parametre `fromPos`, selection sort'un gereğidir: aramanın hangi konumdan başlayacağını söyler.

Genel kural şudur: dinamik ayrılmış bir alan üzerinde işlem yapılacaksa ve alanın sonunu anlamanın bir yolu yoksa ya da bu sınır problemden probleme değişebiliyorsa, eleman sayısı ilgili fonksiyonlara parametre olarak verilir.

Değerlere `*(list+i)` biçiminde gösterici aritmetiğiyle erişilir. `list[i]` de aynı sonucu verir, ama hoca artık gösterici aritmetiğinin kullanılmasını istedi.

Fonksiyon tanımında parametre `int *b` olarak yazılır; çağrıda ise yalnız göstericinin adı verilir, başına `*` ya da `&` konmaz (`selectionSort(p, n)`, `printList(b, n)`).

Takas işleminde geçici olarak saklanması gereken şey bir değerdir, adres değildir; bu yüzden `tmp` sıradan bir `int`'tir. `b+i` adresindeki değer ile `b+minPos` adresindeki değer değiştirilir: `*(b+i)` ve `*(b+minPos)`. Göstericiler değişmez, gösterdikleri bellek hücrelerinin değerleri değişir.

Bubble sort da aynı biçimde gösterici alır. Ekrandaki sürümde karşılaştırma hâlâ dizi gösterimiyle yazılmıştı (`if( b[i] > b[j] )`, yanında `//*(b+i) > *(b+j) de olur.` açıklaması vardı); hoca iki yolun da çalıştığını, ama artık gösterici gösteriminin tercih edilmesini söyledi.

`main` içinde kullanıcıdan eleman sayısı istenir, o kadar `int`'lik alan `malloc` ile ayrılıp `int *`'a dönüştürülür, `NULL` kontrol edilir, sayılar tek tek okunur, girilen liste yazdırılır, sıralanır, sıralı liste yazdırılır ve alan `free` edilir. Derste dokuz sayı girilerek denendi ve liste doğru sıralandı. <!-- BELİRSİZ: girilen sayıların tamamı altyazıda bozuk; kesin değerler aktarılmadı. -->

Ekrandaki fonksiyonlara `main` eklenerek ders sonrası `gcc -Wall` ile derlenip çalıştırılan sürüm (`printList` ve `main` gövdesi ajan tarafından altyazıdaki anlatıma göre yazıldı):

```c
#include <stdio.h>
#include <stdlib.h>
void printList(int *list, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", *(list + i));
    printf("\n");
}
int getPosOfMin(int *list, int n, int fromPos) {
    int i, minIndex;
    minIndex = fromPos;
    for (i = fromPos + 1; i < n; i++)
        if (*(list + i) < *(list + minIndex))
            minIndex = i;
    return minIndex;
}
void selectionSort(int *b, int n) {
    int i, minPos, tmp;
    for (i = 0; i < n - 1; i++) {
        minPos = getPosOfMin(b, n, i);
        if (*(b + i) > *(b + minPos)) {
            tmp = *(b + i); *(b + i) = *(b + minPos); *(b + minPos) = tmp;
        }
    }
}
int main() {
    int i, n, *p;
    printf("How many numbers? ");
    scanf("%d", &n);
    p = (int *) malloc(n * sizeof(int));
    if (p == NULL) { printf("out of memory"); return -1; }
    for (i = 0; i < n; i++)
        scanf("%d", p + i);
    printf("Entered list: "); printList(p, n);
    selectionSort(p, n);
    printf("Sorted list:  "); printList(p, n);
    free(p);
    return 0;
}
```

`5 34 23 87 15 46` girdisiyle çıktı `Sorted list:  15 23 34 46 87` oldu.

## 8. Değerle ve adresle parametre aktarımı

Bu bölümde ilkel değişkenlerin fonksiyonlara nasıl aktarıldığı görüldü. Çağıran taraftan bakıldığında "pass by value / pass by reference", fonksiyonun parametreyi nasıl ele aldığına bakıldığında "call by value / call by reference" denir. Bölümün sonunda `main`'in `argc` ve `argv` parametrelerine de girilecekti; bu derste oraya gelinmedi.

### 8.1 Değerle aktarım

Slayttaki ifade (ekrandan, 02:15:00): C argümanları değerle aktardığı için bir fonksiyon, gerçek argümanları etkilemeden biçimsel argümanlara değer atayabilir. Fonksiyon içinde parametrenin değeri değiştirilirse bu değişiklik yalnız fonksiyon çalıştığı sürece geçerlidir; fonksiyondan dönüldüğünde çağıran yerdeki değişken eski değerindedir. Bu bazı senaryolarda istenen bir şeydir, bazılarında değildir.

### 8.2 Adresle aktarım

Değişikliğin kalıcı olması isteniyorsa fonksiyon parametresi gösterici olarak tanımlanır ve değişken fonksiyona değeriyle değil adresiyle gönderilir; atama da gösterilen nesne üzerinden yapılır. `scanf` de böyle çalışır: kendisine verilen adresteki alana yazamasaydı kullanıcıdan alınan girdi boşa giderdi. Önceki derslerde yazılan `indexOf` fonksiyonu da hatırlatıldı.

Örnekte `main` içinde `a = 3`, `b = 5` tanımlandı:

- `increaseRegular(int a, int b)` geriye bir şey döndürmez; ilk parametreyi ikinci parametre kadar artırır ve fonksiyon içinde artmış değeri (8) yazar. `main`'e dönüldüğünde `a` hâlâ 3'tür.
- `increasePointer(int *aa, int b)` ise `a`'nın adresini alır (`increasePointer(&a, b)`). Bu, tek bir `main` içinde `int *aa;` tanımlayıp `aa = &a;` atamasını yapmakla aynıdır: tanım fonksiyon imzasında, atama ise fonksiyon çağrısıyla otomatik olarak yapılır. `*aa` değeri `b` kadar artırılır; fonksiyon içinde de `main`'de de 8 yazılır.

Çalıştırıldığında `increaseRegular` 8 gösterdi ama `main` hâlâ 3 dedi; `increasePointer` sonrasında `main` 8 dedi. Çoğunlukla istenen ikinci davranıştır.

Fonksiyon çağrısının akışı da hatırlatıldı: çağrı noktasına gelince denetim fonksiyona geçer, komutlar yürütülür ve kalınan yerden devam edilir. C her şeyin kullanılmadan önce tanımlanmasını (ya da prototipinin bildirilmesini) ister.

> **Ders sonrası not:** Hoca faktöriyel örneğinden söz ederken değerin 7-8 faktöriyelden itibaren `int`'e sığmayacağını söyledi. 32 bitlik `int`'in en büyük değeri $2^{31}-1 = 2\,147\,483\,647$'dir; $12! = 479\,001\,600$ hâlâ sığar, ilk taşan $13! = 6\,227\,020\,800$'dür. 16 bitlik `int` kullanan eski bir platformda ise sınır $7! = 5040$ ile $8! = 40320$ arasına düşer; hocanın verdiği aralık büyük olasılıkla buna dayanır.

### 8.3 swap örneği

> **Hocanın vurgusu:** Call by value ile call by reference ayrımı bilinmezse zorlanılacak bir konudur; bu yüzden örnek birlikte yazıldı.

Hoca önce iki fonksiyonu aynı adla yazdı (ekrandan, 02:25:00):

```c
void swap1(int x, int y) {
    int tmp = x; x = y; y = x;
}
void swap1(int *x, int *y, int z) {
    int tmp = *x; *x = *y; *y = *x;
}
```

Derleyici `conflicting types for 'swap1'` ve `too few arguments to function 'swap1'` hataları verdi. Hoca, parametre listesi farklı olduğu için iki fonksiyonun ayırt edileceğini bekliyordu; üçüncü bir parametre eklense de sonuç değişmedi. C'de aynı adlı iki fonksiyon tanımlanamaz. İkinci fonksiyonun adı `swap2` yapıldı.

İlk çalıştırmada değerler beklenen biçimde değişmedi, çünkü iki fonksiyonda da takasın son adımı yanlış yazılmıştı (`y = x` ve `*y = *x`). Doğrusu, son adımda geçici değişkende saklanan değeri kullanmaktır (`y = tmp`, `*y = tmp`). Düzeltilmiş program ders sonrası `gcc -Wall` ile derlenip çalıştırıldı:

```c
#include <stdio.h>
#include <stdlib.h>
void swap1(int x, int y) {
    int tmp = x; x = y; y = tmp;
}
void swap2(int *x, int *y) {
    int tmp = *x; *x = *y; *y = tmp;
}
int main() {
    int a = 3, b = 5;
    swap1(a, b);
    printf("main says the values are %d %d\n", a, b);
    swap2(&a, &b);
    printf("main says the values are %d %d\n", a, b);
    return 0;
}
```

Çıktı önce `3 5`, sonra `5 3`'tür: `swap1` yalnız kendi kopyalarını değiştirir, `swap2` ise `main`'deki değişkenlerin adreslerine yazar. `swap2` çağrılırken değişkenlerin adresleri (`&a`, `&b`) verilmek zorundadır.

## 9. Dizileri fonksiyona parametre olarak aktarma

Diziler daha önce de (`indexOf` gibi fonksiyonlarda) parametre olarak kullanılmıştı; bu bölümde önemli noktalar tekrar edildi (ekrandan, 02:30:00):

- Birçok yolu vardır.
- Unutulmaması gerekenler: sınır denetimi yoktur (no boundary checking!) ve fonksiyon yazma amacınız hatırlanmalıdır.
- Gerçek dizi boyutunu kullanmak: `void printArray( int ar[5] )`. Çok kullanışlı değildir; farklı boyutlarda diziler yazdırılmak istenirse ne olacak?
- Dizi ve bir boyut parametresi kullanmak: `void printArray( int ar[], int size )`. Öncekinden daha kullanışlıdır.
- Bir gösterici ve bir tamsayı kullanmak: `void myFunction( int *ar, int size )`. Bu da kullanışlıdır.

Çağıran ve çağrılan tarafta dizinin dizi olarak mı gösterici olarak mı tanımlandığı fark etmez. Köşeli parantez içine sabit bir sayı yazılsa bile C, dizinin kaç elemanlı olduğunu denetlemez. Bu yüzden eleman sayısı mutlaka parametre olarak verilmelidir. Farklı boyutlar için aynı adlı ayrı fonksiyonlar da yazılamayacağı (aşırı yükleme olmadığı) için en doğrusu eleman sayısını parametre olarak vermek ya da dinamik bellek kullanmaktır. Bir işi ayrı bir iş olarak ele alabiliyorsanız fonksiyon yazmak yönetimi kolaylaştırır.

**Soru (hocanın sorduğu):** Eleman sayısı verilmese de `sizeof(dizi) / sizeof(bir eleman)` ile hesaplanamaz mı?

**Cevap:** Hesaplanamayabilir; bu yüzden güvenilir bir yol değildir.

> **Ek bilgi (derste anlatılmadı):** Bir dizi fonksiyona parametre olarak verildiğinde ilk elemanının adresine dönüşür; `int ar[]` parametresi aslında `int *ar`'dır. Bu yüzden fonksiyonun içinde `sizeof(ar)` dizinin değil göstericinin boyutunu verir. `sizeof(dizi)/sizeof(dizi[0])` hesabı yalnız dizinin tanımlandığı kapsamda doğru sonuç verir.

Selection sort örneği tek boyutlu bir alan üzerinde zaten yapıldığı için slayttaki dizi sıralama örneği atlandı.

## 10. Fonksiyondan dizi döndürme

### 10.1 Birden fazla değer döndürme

Bir fonksiyondan yalnız tek bir değer döndürülebilir. Birden fazla değer döndürmek gerekiyorsa çeşitli çözümler vardır. Döndürülecek değerlerin hepsi aynı türdense fonksiyon içinde bir bellek alanı oluşturulup bu alanın başlangıç adresi döndürülebilir. Ama kaç eleman döndürüldüğü de çağırana bildirilmelidir. İkinci bir `return` yapılamayacağı için bu sayı, fonksiyonun son parametresi olarak adresle aktarılır ve fonksiyon onu uygun yerde yazar. İstenirse bellek alanı da fonksiyona parametre olarak verilebilir ve fonksiyon onu doldurur; hangisi daha uygun geliyorsa o yapılabilir.

Slayttaki kurallar (ekrandan, 02:35:00):

- Fonksiyondan dizi döndürülmez; döndürülecek dizinin başlangıç adresini tutan bir gösterici döndürülür.
- Dizinin, fonksiyon bittikten sonra da var olduğundan emin olunmalıdır: yerel diziler döndürülemez!
- Çözüm: dinamik bellek ayırma.

Fonksiyon içinde bellek ayrılıyorsa o alan fonksiyon bittikten sonra da kullanılacağı için fonksiyonda `free` yapılmaz. `free`, `main`'de yapılır. İlk yöntemde (fonksiyon gösterici döndürür) `main` dönen göstericiyi saklar ve en sonunda `free` eder. İkinci yöntemde (alan parametre olarak verilir) `main` alanı `malloc` ile ayırır, fonksiyona verir, fonksiyon alanı doldurur ve `main` en sonunda yine alanı `free` eder. Yapılamayacak tek şey, fonksiyon içinde yerel bir dizi tanımlayıp onu döndürmektir.

### 10.2 Birleştirme örneği: concatArraysV1

Örnek, bir dizinin sonuna diğerini eklemektir. Dizgiler değil tamsayılar birleştirilir; dizgi için `int`'ler `char` yapılabilir. `int` seçilmesinin nedeni, gösterici aritmetiğinde `++`'nın bir bayt değil bir eleman (bir tamsayı) ilerlediğinin görülebilmesidir.

Slayttaki kod (ekrandan, 02:50:00):

```c
int* concatArraysV1( int arr1[], int size1, int arr2[], int size2 ) {
    int *merged = (int*) malloc( (size1+size2)*sizeof(int) );
    int i;
    for( i=0; i<size1; i++ )           merged[i] = arr1[i];
    for( ; i<size1+size2; i++ )        merged[i] = arr2[i-size1];
    return merged;
}
int main() {
    int arr1[] = {1,5,7,19}, arr2[] = {2,6,8,11,28};
    int *ptrM = concatArraysV1(
        arr1, SIZE_OF_ARRAY(arr1), arr2, SIZE_OF_ARRAY(arr2));
    ...
```

Fonksiyon iki diziyi ve iki dizinin eleman sayısını alır. Köşeli parantezlerin içinde sayı yoktur, çünkü sayı yazmak çok kısıtlayıcı olurdu. Birleşik alanın eleman sayısının ayrıca çağırana bildirilmesi gerekmez: tekrar eden elemanlar elenmediği için yeni boy, iki boyun toplamıdır. Önce `malloc` ile `size1+size2` tamsayılık yer ayrılır. İlk döngüde birinci dizinin bütün elemanları kopyalanır. İkinci döngüde `i` sıfırlanmaz, kaldığı yerden devam eder; bu yüzden ikinci diziden doğru eleman `arr2[i-size1]` ile alınır. (`i` sıfırdan başlatılsaydı `merged[i+size1] = arr2[i]` yazılırdı; ikisi aynı sonucu verir.) En sonunda yeni alanın başlangıç adresi döndürülür.

`main`'de dönen değer bir `int *`'a atanır. Tanım ve çağrı iki satırda yapılsaydı `int *ptrM;` ve ardından başına yıldız koymadan `ptrM = concatArraysV1(...);` yazılırdı. Birleşik dizi yazdırıldıktan sonra `ptrM` `free` edilir: `main`'de `malloc` yapılmamış olsa da alan fonksiyonun içinde `malloc` edilmiştir.

Slayttaki bir açıklama notunda ("yer kalmamışsa kontrolünü de yap") ve hocanın kendi hatırlatmasında belirtildiği gibi, fonksiyondaki `malloc`'tan sonra `NULL` kontrolü eksikti; yapılması gerekir.

### 10.3 Makro tanımı

Eleman sayısını hesaplamak için bir makro kullanıldı (ekrandan, 02:45:00):

```c
#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof((x)[0]))
```

`#define` ile başlayan satır bir makro tanımlar. Makronun `x` adlı bir parametresi vardır, ama bu parametrenin türü yoktur ve belirtilemez. Derleme aşamasında kodda `SIZE_OF_ARRAY(arr1)` görülen her yere `(sizeof(arr1) / sizeof((arr1)[0]))` metni kopyalanıp yapıştırılmış gibi olur; kaynak kodumuz değişmez, derlenen kopyası değişir. Aynı iş normal bir fonksiyonla da yapılabilirdi; makro kullanmak zorunlu değildir.

### 10.4 Alanı main'de ayırma (V3)

Hoca ikinci olarak sabit boyutlu dizilerle çalışan bir `main` gösterdi: `size1`, `size2` dizilerin boyutundan hesaplanıp `size3 = size1 + size2` atandı ve sonuç dizisi bu boyutta yerel bir dizi olarak tanımlandı. Kullanıcıdan eleman sayısı istenip ona göre dizi tanımlanmak istenseydi bunun mümkün olmayacağını söyledi.

> **Ders sonrası not:** Boyutu çalışma anında belli olan yerel dizi (`int arr3[size3];`) C99'dan beri "değişken uzunluklu dizi" (VLA) olarak desteklenir ve derste kullanılan derleyici bunu kabul etti; hoca da buna şaşırdı. Ancak C11'de VLA isteğe bağlı bir özellik olmuştur ve büyük diziler için yığında taşmaya yol açabilir; dersin genel yaklaşımı olan dinamik bellek büyük olasılıkla daha güvenli bir tercihtir.

Son sürümde (V3) birleştirme fonksiyonu `void` yapıldı ve sonucu yazacağı alanı parametre olarak aldı; alan `main`'de ayrıldı (ekrandan, 03:00:00):

```c
int size1 = sizeof(arr1)/sizeof(arr1[0]);
int size2 = sizeof(arr2)/sizeof(arr2[0]);
int size3 = size1+size2;
int *arr3;
arr3 = (int*) malloc(sizeof(int)*size3);
if( arr3 == NULL ) { printf("out of memory"); return -1;}
```

Ardından birleştirme fonksiyonu `arr1, size1, arr2, size2, arr3` parametreleriyle çağrıldı, üç dizi yazdırıldı ve `free(arr3)` ile alan boşaltıldı. <!-- BELİRSİZ: ekranda bu çağrıda fonksiyon adı concatArraysV2 olarak görünüyor, altyazıda V3 deniyor; bu notta main'de ayırma yapan sürüm V3 diye anıldı. -->

Hoca sonuçta V1 ile V3'ün ikisinin de kullanılabileceğini, aralarındaki tek farkın bellek ayırmanın fonksiyonda mı `main`'de mi yapıldığı olduğunu, altyapının aynı olduğunu söyledi. `arr1` ve `arr2`'nin de dizi yerine dinamik alanla oluşturulması alıştırma olarak bırakıldı.

V1 ve V3'ü bir arada içeren, ders sonrası `gcc -Wall` ile derlenip çalıştırılan program (`printArray` gövdesi ve iki sürümün tek `main`'de toplanması ajan tarafından yapıldı):

```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof((x)[0]))
void printArray(int *ar, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", *(ar + i));
    printf("\n");
}
int *concatArraysV1(int arr1[], int size1, int arr2[], int size2) {
    int *merged = (int *) malloc((size1 + size2) * sizeof(int));
    int i;
    if (merged == NULL) return NULL;
    for (i = 0; i < size1; i++)        merged[i] = arr1[i];
    for (; i < size1 + size2; i++)     merged[i] = arr2[i - size1];
    return merged;
}
void concatArraysV3(int arr1[], int size1, int arr2[], int size2, int *arr3) {
    int i;
    for (i = 0; i < size1; i++)        arr3[i] = arr1[i];
    for (; i < size1 + size2; i++)     arr3[i] = arr2[i - size1];
}
int main() {
    int arr1[] = {1, 5, 7, 19}, arr2[] = {2, 6, 8, 11, 28};
    int size1 = SIZE_OF_ARRAY(arr1);
    int size2 = SIZE_OF_ARRAY(arr2);
    int size3 = size1 + size2;
    int *ptrM, *arr3;

    ptrM = concatArraysV1(arr1, size1, arr2, size2);
    if (ptrM == NULL) { printf("out of memory"); return -1; }
    printf("V1: "); printArray(ptrM, size3);
    free(ptrM);

    arr3 = (int *) malloc(sizeof(int) * size3);
    if (arr3 == NULL) { printf("out of memory"); return -1; }
    concatArraysV3(arr1, size1, arr2, size2, arr3);
    printf("V3: "); printArray(arr3, size3);
    free(arr3);
    return 0;
}
```

Çıktının iki satırı da `1 5 7 19 2 6 8 11 28` oldu; derste ekranda görülen birleşik dizi de buydu.

## Örnek Sorular

### Soru 1: Gösterici ifadelerinin çıktısı

(ekrandan, 00:50:00) `text` 3 satır × 64 karakterlik `calloc` ile ayrılmış, satırları `"012345\n"`, `"6789AB\n"`, `"CDEFGH\n"` olan bir `char **`; `bp = text[0]`, `mp = text[1]`; `char *mat[3]` aynı dizgileri tutan bir dizgi sabitleri dizisi. Aşağıdakilerin çıktısı nedir?

```c
printf("%s", mp+1);
printf("%c", *(bp+2));
printf("%c", **text);
printf("%c", *(*(text+1)+2));
printf("%c", *((text[1])+3));
printf("%c", *(*(mat+1))+3);
printf("%d", mat[2][4]-mat[1][4]);
```

> **Çözüm:** Derste ekranda verilen sonuçlar: `789AB`, `2`, `0`, `8`, `9`, `9`, `6`. İlk toplama satırı, ikinci toplama sütunu değiştirir. `*(*(mat+1))+3`, `'6'` karakterine 3 ekler. Son ifade `'G' - 'A'` = 71 − 65 = 6'dır. Sonuçlar ders sonrası gcc ile doğrulandı.

### Soru 2: Hangi satırlar hatalıdır?

(ekrandan, 00:50:00) Aynı tanımlarla `printf("%s\n", text)`, `printf("%c\n", text)`, `printf("%c\n", bp)`, `printf("%c\n", *text)` ve `printf("%s", **text)` satırlarında ne olur?

> **Çözüm:** Hepsi biçim belirteci ile argüman türünün uyuşmadığı satırlardır. İlk dördü derste "buggy" olarak işaretlendi ve anlamsız karakterler basıldı; `%s` ile `**text` ise programı çökertti. Bunlar tanımsız davranıştır; `gcc -Wall` her biri için `-Wformat` uyarısı verir.

### Soru 3: Sormadan dinamik yer ayırma

(derste sözlü, 00:41:13) Kullanıcıya uzunluğu sorulmadan bir kelime için dinamik olarak tam gerektiği kadar yer ayrılabilir mi?

> **Çözüm:** Derste verilen cevap: hayır. Girilen metnin konacağı yer önceden ayrılmalıdır; uzunluk sorulmazsa tahmine dayanılır ve gereğinden fazla bellek harcanır. Kullanıcıya önce en fazla kaç karakter gireceği sorulur, sonra `malloc`/`calloc` yapılır.

### Soru 4: swap neden çalışmıyor?

(ekrandan, 02:25:00) `void swap1(int x, int y) { int tmp = x; x = y; y = x; }` fonksiyonu `main`'deki `a = 3`, `b = 5` değişkenlerini neden takas etmez? Doğru sürüm nasıl yazılır?

> **Çözüm:** Derste verilen çözüm: değerle aktarımda fonksiyon yalnız kopyaları değiştirir. Doğru sürüm adresleri alır: `void swap2(int *x, int *y) { int tmp = *x; *x = *y; *y = tmp; }` ve `swap2(&a, &b)` ile çağrılır; `main` önce `3 5`, sonra `5 3` yazar. Ekrandaki ilk sürümde son adım da hatalıydı (`y = x`, `*y = *x`); son adımda `tmp` kullanılmalıdır.

### Soru 5: İki sıralı diziyi sıralı biçimde birleştirme

(ekrandan, 02:55:00) Alıştırma olarak verildi: iki sıralı diziyi alıp birleşimini döndüren bir fonksiyon yazın; dönen dizi de sıralı olmalıdır. Birleştirdikten sonra sıralama fonksiyonu çağrılmayacak, aynı elemanlar elenmeyecek, diziler üzerinde indis yerine gösterici kullanılacaktır. Ekrandaki diziler: `dizi1 = 1, 5, 8, 9, 15, 27` ve `dizi2 = 2, 4, 5, 7, 9, 10`.

Hoca yöntemi şöyle anlattı: her iki dizinin başına birer gösterici konur. Gösterilen iki değerden küçüğü sonuç dizisine yazılır ve o dizinin göstericisi bir ilerletilir. Örnekte önce 1 ile 2 karşılaştırılır, 1 yazılır; sonra 5 ile 2, 2 yazılır; sonra 5 ile 4, 4 yazılır; sonra 5 ile 5 eşittir, ikisinden biri alınır, ve böyle devam edilir. Zaten sıralı iki dizi varken birleştirip yeniden sıralamak gereksiz yere masraflıdır.

> **Çözüm (derste verilmedi):** Aşağıdaki program ajan tarafından yazıldı, `gcc -Wall` ile derlenip çalıştırıldı. Çıktı: `1 2 4 5 5 7 8 9 9 10 15 27`.

```c
#include <stdio.h>
#include <stdlib.h>
int *mergeSorted(int *p1, int n1, int *p2, int n2) {
    int *merged = (int *) malloc((n1 + n2) * sizeof(int));
    int *p3 = merged, *end1 = p1 + n1, *end2 = p2 + n2;
    if (merged == NULL) return NULL;
    while (p1 < end1 && p2 < end2) {
        if (*p1 <= *p2) *p3++ = *p1++;
        else            *p3++ = *p2++;
    }
    while (p1 < end1) *p3++ = *p1++;
    while (p2 < end2) *p3++ = *p2++;
    return merged;
}
int main() {
    int dizi1[] = {1, 5, 8, 9, 15, 27}, dizi2[] = {2, 4, 5, 7, 9, 10};
    int i, *dizi3 = mergeSorted(dizi1, 6, dizi2, 6);
    if (dizi3 == NULL) { printf("out of memory"); return -1; }
    for (i = 0; i < 12; i++)
        printf("%d ", *(dizi3 + i));
    printf("\n");
    free(dizi3);
    return 0;
}
```

Döngü, dizilerden biri bitene kadar karşılaştırma yapar; sonra öbür dizide kalan elemanlar olduğu gibi sona eklenir. Her eleman bir kez kopyalandığı için iş, toplam eleman sayısıyla doğru orantılıdır.

## Dersin Toparlaması

Ders, göstericilerden dinamik bellek yönetimine geçişi ve bunun fonksiyonlarla birlikte kullanımını işledi. Çift gösterici ile bir göstericinin de adresinin tutulabileceği görüldü. `malloc`, `calloc` ve `realloc` arasındaki farklar, `void*` dönüşünün cast edilmesi, `NULL` kontrolü ve her ayırmaya karşılık bir `free` yazılması kuralı üzerinde duruldu. İki boyutlu matrisin önce satır göstericileri, sonra her satır ayrı ayrı ayrılarak kurulduğu ve satırların farklı uzunlukta olabildiği gösterildi. Uzun bir metin matrisi örneğinde `*(*(text+i)+j)` ifadelerinde ilk toplamanın satırı, ikincisinin sütunu değiştirdiği, biçim belirteci ile tür uyuşmazlıklarının anlamsız çıktıya ya da çökmeye yol açtığı ve ayrılan alanın dışına çıkmanın bir güvenlik açığı olduğu canlı olarak görüldü.

İkinci yarıda dinamik alan üzerinde selection sort yazıldı, ardından fonksiyonlara değerle ve adresle parametre aktarımı `increase` ve `swap` örnekleriyle karşılaştırıldı. Dizilerin parametre olarak aktarılmasında sınır denetimi olmadığı ve eleman sayısının ayrıca verilmesi gerektiği, fonksiyondan yerel dizi döndürülemeyeceği, bunun yerine dinamik alanın adresinin döndürüldüğü ya da alanın çağıran tarafta ayrılıp fonksiyona verildiği iki birleştirme sürümüyle gösterildi. Bölümün kalan kısmı, `main`'in `argc` ve `argv` parametreleri, sonraki derste ele alınacaktı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
