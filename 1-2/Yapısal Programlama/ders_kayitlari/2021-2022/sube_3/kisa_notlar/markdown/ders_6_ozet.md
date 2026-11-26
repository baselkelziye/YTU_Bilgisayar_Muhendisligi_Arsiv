# Ders 6 Çalışma Özeti

## Genel Konular

- Kayıt yapısı
  - Kaydın ilk bölümü teori dersidir: işaretçi aritmetiğine kısa dönüş, C'de karakter dizileri (stringler), `string.h` fonksiyonları, örüntü eşleştirme, çok boyutlu diziler, işaretçi dizileri ve harf dönüşümü.
  - İkinci bölüm uygulama (lab) oturumudur: dinamik bellekle iki boyutlu dizi (matris) oluşturma, `enum`, histogram matrisi ve üç zar toplamının olasılık matrisi.
- İşaretçi aritmetiğine kısa dönüş
  - Bir dizinin ilk elemanını gösteren `p` işaretçisi için `*(p+3)` ile `p[3]` aynı elemana erişir. Köşeli parantezli gösterimde başa `*` konmaz.
- C'de string kavramı
  - Standart C'de ayrı bir string türü yoktur; string, null karakteriyle (`'\0'`, sayısal değeri 0) biten bir `char` dizisidir (ekrandan, 00:20:00).
  - Çift tırnak içindeki metin bir string sabitidir; her karakter 1 bayt yer tutar.
  - Dizi boyutu sabittir. Problemdeki en uzun string düşünülerek yer ayrılır; kısa stringlerde kalan yer boşa gider.
  - `char str[] = "some text";` boyutu ilk değere göre belirler. `char str[10] = "yes";` geçerlidir. `char str[3] = "four";` hatalıdır, çünkü dört harf ve sondaki `'\0'` sığmaz (ekrandan, 00:20:00).
  - `char *ptr = "more text";` sabit bir string oluşturur; bu stringin karakterleri değiştirilemez.
- String atamaları: neler yapılabilir, neler yapılamaz (ekrandan, 00:25:00)
  - `array = "not OK";` derlenmez: dizi adı bir adrestir, bir adrese string atanamaz.
  - `array[5] = 'A';` derlenir ama anlamsızdır; dizinin önceki gözleri doldurulmamıştır. Atamaya her zaman 0. indisten başlanır.
  - `array[0]='O'; array[1]='K'; array[2]='\0';` doğru bir karakter karakter atamadır.
  - `ptr1[8] = 'r';` (ptr1 sabit stringi gösterirken) çalışma anında hataya yol açar; program sessizce kapanır.
  - `*ptr2 = "not OK";` tür uyuşmazlığıdır.
  - `ptr2 = "OK";` her derleyicide aynı davranmaz.
- Değiştirilebilir string: `malloc` + `strcpy`
  - `malloc(n)` n baytlık yer ayırır ve `void *` döndürür; bu `(char*)` ile dönüştürülür (cast).
  - `strcpy(hedef, kaynak)` sabit stringin içeriğini ayrılan alana kopyalar; artık karakterler değiştirilebilir (ekrandan, 00:40:00).
- `scanf("%s", ...)` ile string okuma
  - Önce yeterince büyük bir dizi ya da bellek alanı gerekir. `%s` ile yalnız dizi adı verilir (`&` gerekmez).
  - `scanf` sona `'\0'` koyar ama boşlukta durur; boşluktan sonrası okunmaz.
- `string.h` fonksiyonları (ekrandan, 01:15:00)
  - `strlen`, `strcpy`, `strncpy`, `strcat`, `strncat`, `strcmp`, `strncmp`, `strstr`.
  - Kopyalama ve ekleme fonksiyonları hedef adresi de döndürür.
- Örüntü eşleştirme (pattern matching)
  - Bir stringin içinde başka bir stringin ilk geçtiği konumu bulan `indexOfV1` (iki işaretçiyle elle arama) ve `indexOfV2` (`strstr` ile) yazılır; bulunamazsa `-1` döner (ekrandan, 01:40:00 ve 02:10:00).
- Çok boyutlu diziler
  - `int ar[5][3]` 5 satır, 3 sütunluk 15 elemanlı bir dizidir; bellekte satır satır art arda durur.
  - `ar[1][2]`, `*(ar[1]+2)` ve `*(*(ar+1)+2)` aynı elemandır (ekrandan, 02:40:00).
  - İlk değer verirken iç süslü parantezler satırları belirler; verilmeyen elemanlar 0 olur (ekrandan, 02:20:00).
- İşaretçi dizileri
  - `char *ar_of_p[5];` beş işaretçiden oluşan bir dizidir; her eleman bir adres tutar (ekrandan, 02:25:00).
- Harf dönüşümü
  - ASCII'de `A`=65 ... `Z`=90, `a`=97 ... `z`=122; aradaki fark 32'dir (ekrandan, 02:40:00).
  - `toUpperCase` ve `toLowerCase` fonksiyonları yalnız harf aralığındaki karakterlere 32 ekler ya da çıkarır.
- Uygulama: dinamik iki boyutlu dizi, histogram ve zar olasılıkları
  - `int **resim` için önce `N` adet satır işaretçisi, sonra her satıra `M` adet `int` için yer ayrılır; her ayırmadan sonra `NULL` kontrolü yapılır (ekrandan, 03:35:00).
  - `calloc` ayırdığı alanı sıfırlar, `malloc` sıfırlamaz. İş bitince `free` ile önce satırlar, sonra satır işaretçisi dizisi serbest bırakılır.
  - Histogram: piksel değeri `tmp` için satır indisi `tmp/127` ile bulunur (0→0, 128→1, 255→2) (ekrandan, 03:55:00).
  - Zar: `float **deger` 16×2'lik bir matristir; üç iç içe döngüde `toplam-3` satırına toplam ve olasılık (`1/216`) eklenir (ekrandan, 04:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Stringleri her zaman null karakteriyle bitirin
  - Kütüphane fonksiyonlarının çoğu stringin `'\0'` ile bittiğini varsayar. Bazen olmadan da çalışır ama koymanın zararı yoktur, çoğu yerde zorunludur.
- Çift tırnaklı metin sabittir
  - `char *ptr1 = "10 spaces";` ile oluşturulan stringin karakterini değiştirmeye çalışmak (`ptr1[8]='r'` ya da `*(ptr1+8)='r'`) hata verir. Çözüm `malloc` ile yer ayırıp `strcpy` ile kopyalamaktır.
- Dizi adı bir adrestir
  - `array = "..."` ya da `p = 'A'` gibi bir adrese değer atanamaz; adresin gösterdiği göze değer atamak için `*p` kullanılır.
- İşaretçinin "saklandığı yer" ile "gösterdiği yer" farklıdır
  - `p` kendi adresinde saklanır (örneğin 1000 numaralı göz); `p = &ch` yapılınca gösterdiği yer `ch`'nin adresidir (örneğin 1002). Bu ayrım bir öğrenci sorusu üzerine düzeltilerek anlatıldı.
- Fonksiyona string parametresini `char *` olarak vermek en esnek yoldur
  - Böylece fonksiyona hem dizi hem işaretçi verilebilir. Çağırırken yalnız dizinin adı yazılır, köşeli parantez yazılmaz.
- `scanf("%s")` boşlukta durur
  - Boşluklu metin girildiğinde yalnız ilk kelime okunur. Bu kütüphanenin davranışıdır, kullanıcının hatası değildir.
- Sınır değerlerle test (off-by-one)
  - Döngü sınırlarında bir fazla ya da bir eksik yineleme sık yapılan bir hatadır. Arama fonksiyonu baştaki, ortadaki, sondaki ve olmayan örüntüyle denenmelidir.
- Dizi sınırının dışına taşmamak
  - Arama döngüsü `len1-len2`'ye kadar gider; daha ötesine bakmak ayrılan belleğin dışına taşmak olur.
- Uygulamada: ayrılan belleği `free` ile geri verin ve gereğinden fazla yer ayırmayın
  - Büyük problemlerde gereksiz bellek tutmak kaynak israfıdır. İki boyutlu yapıda önce satırlar, sonra satır işaretçisi dizisi serbest bırakılır.

## Kısa Tekrar Notları

- String = `'\0'` ile biten `char` dizisi. `'a'` bir karakterdir (tek tırnak), `"a"` bir stringdir (çift tırnak).
- `char str[3] = "four";` hatalıdır; `'\0'` için de yer gerekir.
- Dizi adına `=` ile string atanamaz; `strcpy` kullanılır.
- `char *p = "metin";` sabittir, karakterleri değiştirilemez. Değiştirilebilir string için `malloc` + `strcpy`.
- `malloc` `void *` döndürür; `(char*)` ile dönüştürülür.
- `strlen` `'\0'`'a kadar olan karakter sayısını verir, dizinin kapasitesini vermez.
- `strcpy(hedef, kaynak)`, `strncpy(hedef, kaynak, n)`, `strcat(hedef, kaynak)`, `strncat(hedef, kaynak, n)`.
- `strcmp(s1, s2)`: s1 sözlükte sonra geliyorsa pozitif, önce geliyorsa negatif, eşitse 0. Büyük harfler ASCII'de küçük harflerden önce gelir.
- `strstr(s1, s2)`: s2'nin s1'deki ilk geçtiği yeri gösteren işaretçi ya da `NULL`. Konum = dönen işaretçi − s1.
- `ar[i][j]` ≡ `*(*(ar+i)+j)`; adres farkı `i*sütun_sayısı + j` elemandır.
- `{ {1,2,3}, {4}, {5,6,7} }` ile `{ 1,2,3,4,5,6,7 }` farklı yerleşim verir.
- `char *ar_of_p[5]` beş işaretçilik bir dizidir.
- Büyük harf + 32 = küçük harf. Aralıklar: 65–90 ve 97–122.
- Dinamik matris: `int **m = malloc(N*sizeof(int*))`, sonra her satıra `malloc(M*sizeof(int))`; serbest bırakma ters sırada.
- `calloc(adet, boyut)` alanı sıfırlar; sayaç ve toplama kullanılacak alanlarda `calloc` tercih edilir.
- `enum Palet { Siyah=0, Gri=128, Beyaz=255 };` ile adlandırılmış sabitler tanımlanır.

## Detaylı Açıklamalar

- Değiştirilebilir string oluşturma
  - Derste `char *ptr1 = "10 spaces";` ile oluşturulan string üzerinde `ptr1[8] = 'r';` denendiğinde program hiçbir şey yazmadan kapandı. Satır yorum yapılınca string ekrana yazıldı. Bunun nedeni çift tırnaklı metnin sabit olarak oluşturulmasıdır.
  - Aynı iş şu şekilde doğru çalıştı ve ekrana `10 spacer` yazdı (ekrandan, 00:40:00; gcc ile derlenip çalıştırıldı):

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *ptr1 = (char*) malloc(10);
    strcpy(ptr1, "10 spaces");
    ptr1[8] = 'r';
    printf("ptr1 :%s\n", ptr1);
    free(ptr1);
    return 0;
}
```

  - Derste `#include <string.h>` ve `free` satırları ekranda yoktu; Dev-C++ bunları istemeden derledi. gcc ile temiz derleme için eklendi.
- Kendi `strLen` fonksiyonumuz (ekrandan, 01:10:00)
  - Fonksiyon `'\0'` görene kadar indisi artırır ve son indisi döndürür. Kütüphanedeki `strlen` ile karışmasın diye adı `strLen` yazılmıştır.

```c
int strLen( char *str ) {
    int i=0;
    while( str[i] != '\0' ) {
        i++;
    }
    return i;
}
```

  - Derste 9 harflik boşluksuz bir girişte iki fonksiyon da 9 verdi. Boşluklu girişte `scanf` yalnız ilk kelimeyi okuduğu için uzunluk 5 çıktı.
- `strcat` ve `strcmp` denemeleri
  - `MAX_CHAR` 80 olmak üzere iki işaretçiye `malloc(MAX_CHAR)` ile yer ayrıldı. Birine `strcpy` ile bir kelime ve boşluk kopyalandı, `strcat` ile ikinci kelime eklendi; birleştirme sorunsuz yapıldı ve `strlen` boşluk dahil karakter sayısını verdi (ekrandan, 01:25:00).
  - `strcmp` denemesinde ilk sonuç beklenmedikti. Bir öğrenci ikinci işaretçiye `strcpy` yerine `strcat` yazıldığını fark etti; ilk değeri verilmemiş bir alana ekleme yapılmıştı. Düzeltildikten sonra sonuçlar beklendiği gibi çıktı: ilk string büyükse +1, ikinci büyükse −1, eşitse 0. Büyük harfle başlayan bir kelime, aynı kelimenin küçük harfle başlayanıyla karşılaştırıldığında −1 verdi (ekrandan, 01:30:00).
  - > **Ders sonrası not:** Hoca sonucun +1, −1 ya da 0 olduğunu söyledi; bu, kullanılan derleyicinin kütüphanesinde böyledir. C standardı yalnız işareti garanti eder. gcc/glibc ile aynı denemede pozitif ve negatif değerler 1'den farklı çıktı (ör. 20 ve −20). Bu yüzden sonuç `> 0`, `< 0`, `== 0` diye kontrol edilmelidir.
- Örüntü eşleştirme: `indexOfV1` (ekrandan, 01:40:00)

```c
int indexOfV1( char *ptr1, char *ptr2 ) {
    int i, matchCount = 0;
    int len1 = strlen(ptr1), len2 = strlen(ptr2);
    for( i=0; i<=len1-len2; i++ ) {
        while( *ptr1 == *ptr2 && matchCount != len2 ) {
            matchCount++; ptr1++; ptr2++;
        }
        if( matchCount == len2 ) return i;
        else {
            ptr1 -= (matchCount-1);
            ptr2 -= matchCount; matchCount = 0;
        }
    }
    return -1;
}
```

  - Dış döngü ana stringde en çok `len1-len2` konumuna kadar gider; daha ötede aranan stringe yer kalmaz.
  - İç döngü karakterler eşit olduğu sürece iki işaretçiyi ilerletir ve eşleşme sayısını artırır.
  - Eşleşme sayısı `len2`'ye ulaşırsa başlangıç konumu `i` döndürülür.
  - Ulaşmazsa `ptr2` eşleşme sayısı kadar geri çekilerek aranan stringin başına döner. `ptr1` ise `matchCount-1` kadar geri çekilir; sonuçta bir önceki başlangıçtan tam bir karakter ileriye gelir. Eşleşme hiç yoksa `matchCount-1 = -1` olduğundan `ptr1` bir ilerler.
  - Fonksiyon içinde işaretçilerin ilerletilmesi `main`'deki işaretçileri değiştirmez, çünkü işaretçilerin kopyaları gönderilir. Derste bu, çağrıdan önce ve sonra yazdırılarak gösterildi.
- Örüntü eşleştirme: `indexOfV2` (ekrandan, 02:10:00)

```c
int indexOfV2( char *ptr1, char *ptr2) {
    char *ptr;
    ptr = strstr(ptr1, ptr2);
    if( ptr != NULL )   return ptr-ptr1;
    else                return -1;
}
```

  - `strstr` bulduğu yeri gösteren bir işaretçi döndürür. İki işaretçinin farkı konumu verir: ana string 1000 adresinde başlıyor ve eşleşme 1005'teyse sonuç 5'tir.
  - Derste `"abcdeabceef"` içinde aramalar iki sürümle de aynı sonucu verdi: `"abce"` → 5, sondaki örüntü → 8, baştaki örüntü → 0, olmayan örüntü → −1 (gcc ile de doğrulandı).
- Çok boyutlu dizilerde işaretçi aritmetiği
  - `int ar[5][3]` için `ar[1][2]` elemanına baştan `1*3 + 2 = 5` eleman ilerleyerek ulaşılır.
  - İki boyutlu dizi, 3 elemanlı 5 tek boyutlu dizi gibi düşünülebilir. `ar[1]` ikinci satırın başıdır; `*(ar[1]+2)` ve `*(*(ar+1)+2)` aynı elemanı verir.
  - Üç boyutlu `char x[3][4][5]`, üst üste konmuş üç tane 4×5 matris gibi düşünülebilir.
- Çok boyutlu dizilerde ilk değer (ekrandan, 02:20:00)
  - `int exap[5][3] = { {1,2,3}, {4}, {5,6,7} };` satırları 1 2 3 / 4 0 0 / 5 6 7 / 0 0 0 / 0 0 0 olur.
  - `int exap[5][3] = { 1,2,3, 4, 5,6,7 };` değerleri sırayla yerleştirir: 1 2 3 / 4 5 6 / 7 0 0 / 0 0 0 / 0 0 0. Alt satıra geçmek derleyici için bir şey ifade etmez.
- İşaretçi dizisi örneği (ekrandan, 02:25:00)
  - `char *ar_of_p[5]; char c0='a'; char c1='b';` tanımlanır. Slaytta her işaretçi 4 bayt yer tutar: `ar_of_p[0]` 0x1000, `ar_of_p[1]` 0x1004, ..., `ar_of_p[4]` 0x1010 adresindedir.
  - `c0` 0x2000, `c1` 0x2001 adresinde olsun. `ar_of_p[0] = &c0; ar_of_p[1] = &c1;` sonrasında 0x1000 gözünde 2000, 0x1004 gözünde 2001 yazar; diğer elemanlar tanımsızdır.
- Harf dönüşümü (ekrandan, 02:30:00 ve 02:35:00)
  - `SIZE` 5 olmak üzere `char metinler[SIZE][SIZE]` dizisine beş satır okunur; her satır `toUpperCase(metinler[i])` ile büyük harfe çevrilir. Fonksiyon gelen işaretçiyi her adımda bir ilerletir.

```c
void toUpperCase( char *p ) {
    int j;
    for( j=0; j<SIZE; j++ ) {
        if( *p >= 97 && *p <= 122 )
            *p -= 32;
        p++;
    }
}
void toLowerCase( char *p ) {
    int j;
    for( j=0; j<SIZE; j++ ) {
        if( *p >= 65 && *p <= 90 )
            *p += 32;
        p++;
    }
}
```

  - Ekranda üst sınırlar önce `<= 123` ve `<= 91` yazılmıştı; hoca bunu ders içinde fark edip sınırları 122 ve 90 olacak şekilde düzeltmeyi söyledi. Yukarıdaki kod düzeltilmiş hâlidir ve gcc ile 4 harflik girişlerle denendi.
  - Bir satırı yazdıran `listOneLineOfText(char *p)` fonksiyonu `SIZE` karakteri `%c` ile yazar ve satır sonu koyar. Tüm matrisi tek döngü ve tek işaretçiyle yazdırmak da mümkündür, çünkü satırlar bellekte art arda durur.
  - > **Ders sonrası not:** Derste satır başına 5 harf (ve bir denemede 6 harf) girildi ve hoca `scanf`'in taşma yapmadığını söyledi. `char metinler[5][5]` satırında 5 harf ve `'\0'` için 6 bayt gerekir; fazla bayt bir sonraki satırın başına yazılır. Satırlar sırayla okunduğu için bu bayt sonraki `scanf` ile üzerine yazıldığından sorun görünmemiştir. Son satırdaki taşma ise dizinin dışına yazar. Güvenli kullanım satır başına en çok `SIZE-1` harf girmek ya da `scanf("%4s", metinler[i])` gibi genişlik sınırı vermektir.
- Uygulama: histogram matrisi (ekrandan, 03:15:00–03:55:00)
  - Problem: N×M boyutlu bir resim matrisi 0 (siyah), 128 (gri), 255 (beyaz) piksel değerlerinden oluşur. Renk paleti `enum` ile tanımlanacak, N ve M ile matris değerleri kullanıcıdan alınacak, piksel değeri ve frekansını tutan 3×2'lik histogram matrisi oluşturulacak; iki matris de dinamik olarak ayrılacak.
  - Resim matrisi `int **resim` için önce `resim = (int**)malloc(N*sizeof(int*));`, sonra her satıra `resim[i] = (int*)malloc(M*sizeof(int));` yapılır; her ayırmadan sonra `NULL` ise "Bellekte yer ayrilamadi!!" yazılıp çıkılır.
  - Histogram satırları `histogram[i] = (int*)calloc(2, sizeof(int));` ile sıfırlanmış olarak ayrılır, çünkü frekanslar sıfırdan sayılacaktır.
  - Her piksel için `tmp = resim[i][j]; histogram[(tmp/127)][0] = tmp; histogram[(tmp/127)][1]++;`. Tam sayı bölmesinde 0/127 = 0, 128/127 = 1, 255/127 = 2 olduğundan arama yapmadan satır indisi bulunur. Bu kısa yol yalnız bu üç değer için geçerlidir.
  - Belgedeki 6×6 örnek matris için histogram 0 → 11, 128 → 14, 255 → 11'dir (python ile sayıldı). Derste 3×3'lük bir girişte 0 → 5, 128 → 2, 255 → 2 elde edildi.
- Uygulama: üç zar toplamı olasılık matrisi (ekrandan, 04:15:00–04:30:00)
  - Toplam en az 3, en çok 18'dir; 16 farklı değer vardır. Matrisin 16 satırı ve 2 sütunu olur: birinci sütun toplam, ikinci sütun olasılık.
  - Her sonucun olasılığı $\frac{1}{6^3} = \frac{1}{216}$'dır. Üç iç içe döngüde (`i`, `j`, `k` 1'den 6'ya) `deger[toplam-3][0] = toplam; deger[toplam-3][1] += P;` yapılır. `toplam-3` toplamı 3 → satır 0, 18 → satır 15'e eşler.
  - Sonuçlar 3 → 0.00462963, 4 → 0.01388889, 5 → 0.02777778, ..., 10 ve 11 → yaklaşık 0.125, ..., 18 → 0.00462963'tür (python ile doğrulandı: kombinasyon sayıları 1, 3, 6, 10, 15, 21, 25, 27, 27, 25, 21, 15, 10, 6, 3, 1).
  - Bir öğrenci, `malloc` ile ayrılan alanın ilk değeri belirsizken üzerine `+=` yapıldığını sordu. Satırlar `calloc(2, sizeof(float))` ile ayrılacak şekilde düzeltildi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
