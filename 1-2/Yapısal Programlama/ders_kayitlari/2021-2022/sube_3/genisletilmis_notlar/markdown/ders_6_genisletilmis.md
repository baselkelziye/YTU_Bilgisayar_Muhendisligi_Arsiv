# Ders 6 Genişletilmiş Notu: Stringler, string.h Fonksiyonları, Çok Boyutlu Diziler ve Uygulama 2 (Dinamik Matrisler)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kaydın Yapısı ve İşaretçi Aritmetiğine Kısa Dönüş
- 2. C'de Stringler: Null Karakterle Biten Karakter Dizileri
- 3. String Atamaları: Neler Yapılabilir, Neler Yapılamaz
- 4. Değiştirilebilir String: malloc ve strcpy
- 5. Tek Karakter, İşaretçi ve Adres Kavramı
- 6. scanf ile String Okuma
- 7. Kendi strLen Fonksiyonumuz ve Fonksiyona String Geçirmek
- 8. string.h Fonksiyonları ve Denemeler
- 9. Örüntü Eşleştirme: indexOfV1 ve indexOfV2
- 10. Çok Boyutlu Diziler
- 11. İşaretçi Dizileri
- 12. Harf Dönüşümü: toUpperCase ve toLowerCase
- 13. Uygulama: Dinamik İki Boyutlu Dizi ve Histogram
- 14. Uygulama: Üç Zar Toplamının Olasılık Matrisi
- Örnek Sorular

## 1. Kaydın Yapısı ve İşaretçi Aritmetiğine Kısa Dönüş

Bu kayıt iki bölümden oluşur. İlk bölüm teori dersidir: slaytlar ve Dev-C++ üzerinde canlı kodlamayla C'de stringler, `string.h` fonksiyonları, örüntü eşleştirme, çok boyutlu diziler, işaretçi dizileri ve harf dönüşümü anlatılır. İkinci bölüm ayrı bir uygulama (lab) oturumudur: dinamik bellekle iki boyutlu dizi kurulur, `enum` kullanılır, bir histogram matrisi ve üç zarın toplam olasılıkları hesaplanır.

Ders, önceki haftanın konusu olan işaretçi aritmetiğine kısa bir dönüşle başlar. İşaretçiye 1 eklemek, gösterdiği veri türünün boyutu kadar (ör. `int` için 4, `short` için 2 bayt) sonraki adrese geçmek demektir. Hoca bunu bayt bayt düşünmenin konuyu gereksiz yere karmaşıklaştırdığını, "bir sonraki eleman" diye düşünmenin yeterli olduğunu söyler. Bir dizinin ilk elemanını gösteren `p` için üç indisli elemana `*(p+3)` ile erişilir; dil `p[3]` gösterimini de destekler. Köşeli parantezli gösterimde başa `*` konmaz, işaretçi aritmetiğiyle yazıldığında ise ifadenin tamamı paranteze alınıp başına `*` konur. Hoca kendisi ya işaretçi aritmetiğini ya da dizi adıyla köşeli parantezi tercih ettiğini belirtir.

Önceki derste kabarcık sıralaması (bubble sort) ile seçmeli sıralama (selection sort) karşılaştırılmıştı: yineleme sayıları aynıydı, yer değiştirme (swap) sayısında seçmeli sıralamanın küçük bir avantajı vardı, ama ikisi de $O(n^2)$ olduğu için verimli algoritmalar sayılmaz.

## 2. C'de Stringler: Null Karakterle Biten Karakter Dizileri

Standart ANSI C'de ayrı bir string türü yoktur; onun yerine karakter dizisi kullanılır. Slayttaki tanım şöyledir: string, null karakteriyle biten bir karakter dizisidir. Null karakterin sayısal değeri 0'dır ve C'de `'\0'` kaçış dizisiyle yazılır. Çift tırnak içine yazılan her karakter dizisi bir string sabitidir; türü `char` dizisidir ve her karakter bir bayt yer tutar (ekrandan, 00:20:00).

Dizilerin boyutu sabittir; tanımlandıktan sonra değiştirilemez. Bu yüzden bir problemde kullanılacak stringlerin en çok kaç harf olabileceği düşünülüp ona göre yer ayrılır. Hoca ad-soyad saklama örneğini verir: iki adı ve iki soyadı olan uzun bir ad için geniş bir alan gerekir, ama kısa bir ad (ör. yedi karakterlik bir ad, sondaki null karakter dahil) geldiğinde dizinin geri kalanı boşa gider. Bu israfı önlemek için dinamik bellek yönetimi fonksiyonları geliştirilmiştir; konu adım adım işlenecektir.

Null karakterle bitirmek önemlidir, çünkü hem C kütüphanesindeki hem de başkalarının yazdığı string fonksiyonlarının çoğu stringin `'\0'` ile bittiğini varsayar.

Slayttaki tanım örnekleri (ekrandan, 00:20:00):

```c
char str[] = "some text";
char str[10] = "yes";
char str[3] = "four";   /* hatalı */
char str[4] = "four";   /* hatalı */
char *ptr = "more text";
```

- `char str[] = "some text";` boyutu verilmeden ilk değerle tanımlanmıştır; derleyici dizinin boyutunu karakter sayısına göre ayarlar.
- `char str[10] = "yes";` on karakterlik bir dizi ayırır ve başına "yes" yazar. Hoca, geri kalan gözlerde önceki program çalışmalarından kalan rastgele değerler olabileceğini, bu yüzden sona `'\0'` eklemenin iyi olacağını söyler.
- Kırmızıyla işaretli iki satır sorunludur. `char str[3] = "four";` dört harflik metni üç elemanlık diziye koymaya çalışır.
- `char *ptr = "more text";` diziyi bir işaretçiye bağlar. Hoca bu tanımın bir sorunu olduğunu söyler: çift tırnaklı metni C sabit bir dizi olarak ele alır, bu yüzden elemanları değiştirilemez. Bu işaretçiyle string üzerinde dolaşıp inceleme fonksiyonları çağrılabilir, ama bir elemanı değiştirmeye kalkınca hata alınır.

> **Ek bilgi (derste anlatılmadı):** `char str[4] = "four";` C'de derlenir, ama dizide `'\0'` için yer kalmaz; bu durumda dizi null karakterle bitmez ve string fonksiyonlarına verilemez. C++'ta aynı satır derleme hatasıdır. Slaytın bu satırı da kırmızıyla göstermesinin nedeni büyük olasılıkla budur.

## 3. String Atamaları: Neler Yapılabilir, Neler Yapılamaz

Hoca önce slayttaki örneği satır satır tartışır, sonra aynı kodu Dev-C++'ta derleyip çalıştırır (ekrandan, 00:25:00):

```c
main () {
    char array[10];
    char *ptr1="10 spaces";   // not uniformly supported between different C standards
    char *ptr2;
    array = "not OK";         // can NOT assign to an address! Does not compile
    array[5] = 'A';           // Buggy because: Array is not populated yet. So, ...
    array[0] = 'O';           // ... Always begin from 0 and
    array[1] = 'K';
    array[2] = '\0';          // use null-terminated strings where necessary
    ptr1[8] = 'r';            // creates a segment violation. Buggy. See next slide.
    *ptr2 = "not OK";         // Type mismatch warning. Does not compile
    ptr2="OK";                // not uniformly supported and would be buggy
}
```

Her satırın anlamı:

- `char *ptr1 = "10 spaces";` bir string işaretçisi oluşturur. Hoca bu gösterimin bütün C standartlarında aynı biçimde desteklenmediğini, bazı derleyicilerde derleme hatası, bazılarında çalışma anında sorun çıkabileceğini söyler; bu yüzden tercih edilmez.
- `array = "not OK";` çalışmaz. Yalnız `array` yazıldığında bu, dizinin bellekteki başlangıç adresidir. Sağ tarafta ise birden çok elemandan oluşan sabit bir string vardır. Tek bir adres kutusuna birden çok eleman atanamaz; hocanın deyişiyle "elmaya armut atamak" gibidir. Dev-C++ bunu "incompatible types in assignment" derleme hatasıyla reddetti.
- `array[5] = 'A';` derlenir ama mantıksızdır. On elemanlık dizinin altıncı gözüne bir harf yazılmıştır; önceki gözlerde ne olduğu bilinmez. Atamaya her zaman ilk elemandan başlamak gerekir.
- `array[0]='O'; array[1]='K'; array[2]='\0';` doğru, harf harf atamadır. Dizide artık "OK" vardır; iki indisli gözde null karakter olduğu için ekrana yazdırma gibi işlemler bu gözün ötesine gitmez. Sonraki gözlerde anlamsız değerler olması sorun değildir.

> **Hocanın vurgusu:** Bazı durumlarda null karakter olmadan da program doğru çalışır, ama null karakter koymanın hiçbir zararı yoktur ve birçok yerde zorunludur. Stringleri null karakterle bitirmeyi alışkanlık edinin.

- `ptr1[8] = 'r';` ile "10 spaces" metninin son harfini değiştirip "10 spacer" elde etmek istenir. `ptr1[8]`, `*(ptr1+8)` ile aynıdır. Ama `ptr1` sabit bir stringi gösterdiği için bu yapılamaz. Derste program derlendi, çalıştırılınca hiçbir şey yazmadan kapandı; satır yorum yapılınca "10 spaces" yazıldı. Komut satırından çalıştırıldığında da hata mesajı vermeden, istenen işi yapmadan kapandı. Hoca köşeli parantez yerine işaretçi aritmetiğiyle (`*(ptr1+8) = 'r';`) de denedi; sonuç değişmedi.
- `*ptr2 = "not OK";` da çalışmaz. `ptr2` bir adrestir, `*ptr2` ise o adresteki tek bir gözdür. Tek bir göze sabit bir string atanmaya çalışılır; yine tür uyuşmazlığıdır.
- `ptr2 = "OK";` `ptr1`'deki tanıma benzer; yine sabit bir string oluşturur ve her derleyicide çalışmaz.

> **Ek bilgi (derste anlatılmadı):** Modern derleyicilerde string sabitleri genellikle salt okunur bir bellek bölümünde tutulur. Bu yüzden `ptr1[8] = 'r';` gcc/Linux'ta tipik olarak "segmentation fault" ile sonlanır; slayttaki "segment violation" ifadesi bunu anlatır. Bu davranış C standardında "tanımsız davranış"tır.

## 4. Değiştirilebilir String: malloc ve strcpy

Hoca önce bir alternatif anar: `string` sınıfı C++'ta vardır, ama sınıflar ve nesneler nesneye yönelik programlamanın konusudur ve bu derste yapısal programlama görülmektedir. Bu yüzden iki yol kalır: normal dizilerle yan etkilerine katlanarak devam etmek ya da bellek ayırma işlemlerini kullanmak.

`malloc` (memory allocation) parametre olarak verilen bayt sayısı kadar yer ayırır. Karakterler bir bayt olduğu için on karakterlik alan için `malloc(10)` yazılır. `malloc` bir `void *` döndürür; böylece ayrılan bellek parçası her türden veriyi saklamakta kullanılabilir. Bu işaretçi ihtiyaç duyulan türe dönüştürülür (cast): başına `(char*)` yazılır ve sonuç bir `char` işaretçisine atanır.

İkinci adım, bu alana istenen metni koymaktır. Metin kullanıcıdan ya da dosyadan da gelebilir; elle verilecekse `strcpy` (string copy) kullanılır. `strcpy`, ikinci parametresindeki stringin içeriğini birinci parametrenin gösterdiği alana kopyalar. İkinci parametre sabit bir string olabilir; kopyalandıktan sonra içerik artık değiştirilebilir bir alandadır (ekrandan, 00:40:00):

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

Bu kod ekrana `ptr1 :10 spacer` yazar. Ekrandaki sürümde yalnız `stdio.h` vardı ve `free` çağrısı yoktu; Dev-C++ yine de derledi. Yukarıdaki sürüm gcc ile `-Wall` seçeneğiyle temiz derlenip çalıştırıldı.

Hoca, metindeki boşluğun da bir karakter olduğunu ve önemli olduğunu hatırlatır. Bu yüzden henüz `scanf` ile string okumaktan bilinçli olarak kaçındığını, bazı derleyicilerin kitaplıklarında aksaklıklar yaşanabildiğini söyler. Alanın genişliği `malloc` çağrısında verilir; hocaya göre bu genişlik ilerleyen satırlarda yine bellek fonksiyonlarıyla değiştirilebilir.

> **Ders sonrası not:** Hoca alanın genişliğinin daha sonra yine `malloc` ile değiştirilebileceğini söyledi. `malloc` her çağrıda yeni bir alan ayırır, eski içeriği taşımaz; var olan bir alanın boyutunu içeriğini koruyarak değiştiren standart fonksiyon `realloc`'tur.

## 5. Tek Karakter, İşaretçi ve Adres Kavramı

String bir karakter dizisidir, karakter ise tek bir elemandır. Karakterler tek tırnakla (`'a'`), stringler çift tırnakla (`"a"`) yazılır ve bir karakter bir bayt yer tutar. `char ch = 'A';` ile `ch` değişkenine `A` atanır.

Hoca tek karakterle işaretçi kullanımını Dev-C++'ta dener. `char *ptr1; ptr1 = &ch;` ile işaretçi `ch`'yi gösterir. Sonra `ch` değişkeni değiştirilip `*ptr1` yazdırılınca yeni değer görülür; `*ptr1 = 'G';` ile işaretçi üzerinden değiştirildiğinde de `ch` değişir. Hoca, slayttaki satırların bir program akışı olarak değil, her birinin "yapılabilir/yapılamaz" diye ayrı ayrı değerlendirilmesi gerektiğini belirtir.

Ardından Excel'de bir bellek tablosu çizerek açıklar: `char *p` için bellekte 1000 numaralı göz ayrılmış olsun, `ch` ise 1002 numaralı gözde saklansın ve içinde `A` (sayısal olarak 65) olsun. Bu durumda yalnız `p` yazmak 1000'i değil, `p`'nin içindeki adresi ifade eder. `p = "A"` yazmak bir adrese değer atamaya çalışmaktır ve geçersizdir; adresin gösterdiği göze değer atamak için `*p` kullanılır.

**Soru:** Bir öğrenci, `p`'nin bini göstermediğini, bin numaralı gözde saklandığını, içinde adres türünde bir değer tuttuğunu söyleyerek açıklamayı sorgular. **Cevap:** Hoca kelime seçiminde hata yaptığını kabul eder ve şöyle düzeltir: `p`'nin *saklandığı yer* 1000 numaralı gözdür. `ptr1 = &ch` yapılınca 1000 numaralı gözün içine 1002 yazılır; artık `p`'nin *gösterdiği yer* 1002'dir. 1002 `ch` değişkeninin adresidir ve içeriği `A` harfidir.

## 6. scanf ile String Okuma

`scanf` ile string okumadan önce girilecek metni alabilecek genişlikte bir karakter dizisi tanımlamak ya da o kadar genişlikte bellek ayırmak gerekir. `scanf`'e `%s` biçimi ve yalnız dizinin adı verilir; başka bir şey yazılmaz. Okunan metin `printf("%s", str)` ile yazdırılarak kontrol edilir. `scanf` metnin sonuna otomatik olarak null karakter koyar.

Derste önce boşluksuz bir metin girildi ve doğru yazdırıldı. Boşluklu metin girildiğinde ise yalnız ilk kelime diziye alındı; boşluktan sonrası bir sonraki girdi sayıldı. Hoca bunun `scanf`'in kütüphanedeki kodlanış biçiminden kaynaklandığını, kullanıcının hatası olmadığını söyler. İçinde boşluk olması gereken metinlerde boşluk yerine alt çizgi gibi bir karakter kullanılabilir.

## 7. Kendi strLen Fonksiyonumuz ve Fonksiyona String Geçirmek

Hoca, `string.h` fonksiyonlarının arka planda nasıl çalıştığını anlamak için bazılarını kendileri de yazacaklarını söyler. İlk örnek uzunluk fonksiyonudur. Burada dizinin kapasitesi değil, null karaktere kadar kaç harf olduğu sorulur. Kütüphanedeki `strlen` ile karışmasın diye `L` harfi büyük yazılmıştır (ekrandan, 01:10:00):

```c
int strLen( char *str ) {
    int i=0;
    while( str[i] != '\0' ) {
        i++;
    }
    return i;
}

int main () {
    char str1[MAX_CHAR];
    printf("Enter string:");
    scanf("%s",str1);
    printf("Length: %d", strLen(str1));
    return(0);
}
```

Slayttaki açıklama: dizinin elemanları tek tek null karaktere ulaşana kadar sınanır. Null karakterin değeri sıfır olduğu için `while` koşulu yanlış olur; `str[i]`'nin başka her değeri koşulu doğru yapar. Null karaktere ulaşılınca döngüden çıkılır ve son indis değeri olan `i` döndürülür.

Slaytta altı çizili eşleşmeler, diziyi fonksiyona parametre olarak geçirmenin nasıl yapıldığını gösterir. Fonksiyonun parametresi dizi olarak değil, `char *` olarak tanımlanmıştır. Böylece kökeni dizi de olsa işaretçi de olsa string işlenebilir. Parametre dizi olarak tanımlansaydı bazı derleyicilerde ve C standartlarında boyutun verilmesi gerekebilirdi; hoca en esnek yöntemin `char *` parametresi olduğunu söyler. Fonksiyon çağrılırken yalnız dizinin adı yazılır; köşeli parantez kullanılmaz. Bu fonksiyon stringi değiştirmez, yalnız karakterleri sayar.

Derste hem kendi `strLen`'i hem `string.h`'deki `strlen` aynı programda çağrıldı. 9 harflik boşluksuz bir girişte ikisi de 9 verdi. Boşluklu girişte yalnız ilk kelime okunduğu için ikisi de 5 verdi. Aynı sonuçlar gcc ile de elde edildi.

## 8. string.h Fonksiyonları ve Denemeler

### 8.1 Fonksiyonların imzaları

Slaytta `string.h` içinde tanımlı başlıca fonksiyonlar şöyle verilir (ekrandan, 01:15:00):

```c
char* strcpy(char* szCopyTo, const char* szSource)
char* strncpy(char* szCopyTo, const char* szSource, size_t sizeMaxCopy)
char* strcat(char* szAddTo, const char* szAdd)
char* strncat(char* szAddTo, const char* szAdd, size_t sizeMaxAdd)
int strcmp(const char* sz1, const char* sz2)
int strncmp(const char* sz1, const char* sz2, size_t sizeMaxCompare)
```

- `strcpy`: kaynak stringi hedefe kopyalar. Birinci parametre hedef, ikincisi kaynaktır. İkinci parametre `const` tanımlıdır; bu yüzden tırnak içinde bir metin doğrudan verilebilir. Fonksiyon hedef adresi de döndürür; dönen işaretçi başka bir işaretçiye atanarak aynı yerin iki işaretçiyle gösterilmesi sağlanabilir. Bu bir esneklik sağlar.
- `strncpy`: buradaki `n` "adet" anlamındadır; kaynağın tamamı değil, üçüncü parametrede verilen sayıda karakter kopyalanır.
- `strcat`: "concatenate", yani birleştirme. Kaynak stringi hedef stringin sonuna ekler ve hedefi gösteren işaretçiyi döndürür.
- `strncat`: sona en çok `n` karakter ekler.
- `strcmp`: iki stringi karşılaştırır ve bir tam sayı döndürür. Sözlükte önce gelen daha küçük sayılır. Büyük-küçük harf ayrımı vardır: ASCII tablosunda büyük harfler önce geldiği için büyük `A`, küçük `a`'dan küçüktür.
- `strncmp`: karşılaştırmayı yalnız ilk `n` karaktere kadar yapar.

Slaytın altında adlardaki kısaltmalar açıklanır: **c**o**py**, con**cat**enate, **c**o**mp**are, **s**i**z**e, data **t**ype. Daha fazla fonksiyon için `string.h` dosyasına ya da herhangi bir C kitabına veya sitesine bakılabilir.

### 8.2 strcat denemesi

Hoca örnekleri işaretçiler ve `malloc` üzerinden yapar. `#define MAX_CHAR 80` ile iki işaretçiye 80'er baytlık yer ayrılır (ekrandan, 01:25:00). Birinci işaretçiye `strcpy` ile bir kelime ve ardından bir boşluk kopyalanır; sonra `strcat` ile ikinci bir kelime eklenir. Sonuç sorunsuzdur: iki kelime arada boşlukla birleşmiştir. `scanf` kullanılmadığı için boşluk da işleme katılmıştır.

Ardından hoca, kopyalanan metnin sonuna elle `'\0'` koymanın gerekli olup olmadığını dener. Bu denemede sorun çıkmadı; hoca `strcat`'in arka planda null karakter ekleyip eklemediğinden emin olmadığını söyler. `strlen` ile uzunluk yazdırıldığında 5 + 1 (boşluk) + 4 = 10 karakter çıktı: alan 80 karakterlik olsa da stringde 10 karakter vardır.
### 8.3 strcmp denemesi ve bir öğrencinin bulduğu hata

Karşılaştırma için birinci işaretçiye `Y` ile, ikinci işaretçiye `E` ile başlayan birer kelime konup `printf("Sonuc: %d\n", strcmp(ptr1,ptr2));` yazdırıldı. İlk denemede sonuçlar beklenmedik çıktı; iki string eşit verildiğinde bile 0 yerine 1 geldi. Ekranda ikinci işaretçiye `strcpy` değil `strcat` ile değer verildiği görülür (ekrandan, 01:25:00).

**Soru:** Bir öğrenci, `strcpy` ile `strcat`'in farklı mı çalıştığını sorarak ikinci satırdaki fonksiyon adına dikkat çeker. **Cevap:** Hoca öğrencinin haklı olduğunu söyler ve satırı `strcpy` olarak düzeltir. `malloc` ile ayrılan alanın içeriği belirsiz olduğu için `strcat` belirsiz bir stringin sonuna ekleme yapmıştı.

Düzeltildikten sonra sonuçlar şöyle çıktı (ekrandan, 01:30:00):

- Birinci string sözlükte sonra geliyorsa (`Y` > `E`): `1`.
- İkinci string sözlükte sonra geliyorsa: `-1`.
- İki string tamamen aynıysa: `0`.
- Karşılaştırma önce ilk karakterlere bakar, eşitse ikinci karakterlere geçer. `Y` ile `E` arasında çok harf olması sonucu değiştirmez; ilk farklı karakterde hangisinin önce geldiğine göre `1` ya da `-1` döner. `Y` harfi `Z` yapıldığında sonuç `-1` oldu.
- Aynı kelimenin büyük harfle başlayanı ile küçük harfle başlayanı karşılaştırıldığında sonuç `-1` oldu, çünkü ASCII'de büyük harfler küçük harflerden önce gelir.

`strncmp` yalnız ilk `n` karakteri karşılaştırdığı için ayrıca denenmedi.

> **Ders sonrası not:** Hoca sonucun +1, −1 ya da 0 olduğunu söyledi; bu derste kullanılan derleyicinin kütüphanesinde böyledir. C standardı yalnız sonucun işaretini garanti eder. gcc/glibc ile aynı deneme pozitif için 20, negatif için −20 verdi (ilk farklı karakterlerin farkı). Bu yüzden sonuç `== 1` diye değil, `> 0`, `< 0`, `== 0` diye sınanmalıdır. Ayrıca hoca karşılaştırmayı ilk anlatırken (hata düzeltilmeden önce) birinci parametre sözlükte daha uzaktaysa negatif sonuç çıktığını söylemişti; doğrusu, düzeltmeden sonra kendisinin de gösterdiği gibi, pozitif sonuçtur.

## 9. Örüntü Eşleştirme: indexOfV1 ve indexOfV2

### 9.1 Problem

Kullanıcıdan iki string alınacak ve birinci stringin içinde ikinci stringin olup olmadığına bakılacaktır. Varsa kaçıncı karakterden itibaren başladığı döndürülür, yoksa `-1` döndürülür. İkinci string birinci stringin ilk harfinden başlıyor olabilir ve ilk harfin indisi 0'dır; bu yüzden "bulunamadı" için 0 değil `-1` kullanılır. Fonksiyon parametre olarak iki karakter işaretçisi alır.

### 9.2 Çözüm fikrinin tartışılması

Hoca önce Excel'de harf konumlarını (0, 1, 2, ...) yazarak yöntemi tartışır (ekrandan, 01:35:00). Tek bir indeks yetmez; iki stringin her birinde dolaşan ayrı birer işaretçi gerekir. Büyük stringin ilk harfiyle küçük stringin ilk harfi karşılaştırılır; eşleşirse ikisi de bir ilerletilir. Bir noktada farklılık çıkarsa küçük stringte en başa dönülür. Büyük stringte ise son karşılaştırmanın bittiği yerden değil, bu denemenin başladığı yerin bir sonrasından devam edilmelidir.

Örnek: büyük string `a b d a b c`, küçük string `a b c` olsun. İlk iki harf eşleşir, üçüncü konumda `d` ile `c` farklıdır. Küçük string başa döner; büyük stringte aramaya 1 indisinden devam edilir.

İkinci örnek `a b c d e a b c e e f` içinde `a b c e` aramaktır. 0 konumundan başlayan denemede `a`, `b`, `c` eşleşir, `d` ile `e` farklıdır; bu anda eşleşme sayısı 3'tür. Büyük stringteki işaretçi 3 ilerlemiştir, `matchCount-1 = 2` kadar geri çekilince 1 konumuna (`b`) gelir. Küçük stringteki işaretçi `matchCount = 3` kadar geri çekilir ve başa döner. Sonra 1, 2, 3, 4 konumlarında ilk harf bile tutmaz. 5 konumunda `a` eşleşir, ardından `b`, `c`, `e` de eşleşir; eşleşme sayısı aranan stringin uzunluğuna (4) ulaşınca 5 döndürülür.

Bulunamama durumu için aranan stringin son harfi `x` yapılır. Bu kez 5 konumundaki deneme de başarısız olur. 6 ve 7 konumlarından sonra aramaya devam etmenin anlamı yoktur: büyük stringte aranan stringi barındıracak kadar yer kalmamıştır. Döngü sınırı bu yüzden $len_1 - len_2$'dir. Daha ileriye bakmak bize ayrılan bellek alanının dışına taşmak olur; hoca bunun çoğu zaman bir hata üretmeyebileceğini ama üreten sistemler olabileceğini, bu yüzden döngünün nereye kadar gideceğinin dikkatle düşünülmesi gerektiğini vurgular. En kötü durumda kaç kez döneceği belli olduğu için `while` yerine `for` tercih edilmiştir.

### 9.3 Birinci çözüm: indexOfV1

Slayttaki çözüm (ekrandan, 01:40:00):

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

- `len1` ve `len2` iki stringin uzunluğudur; `for` döngüsü `i = 0`'dan `len1 - len2`'ye kadar gider.
- `while` döngüsü, iki işaretçinin gösterdiği karakterler eşit olduğu ve eşleşme sayısı henüz `len2`'ye ulaşmadığı sürece eşleşme sayısını artırır ve iki işaretçiyi bir adım ilerletir.
- Eşleşme sayısı `len2`'ye ulaştıysa aramanın başladığı konum `i` döndürülür.
- Ulaşmadıysa `ptr2` başa çekilir (`matchCount` kadar), `ptr1` `matchCount-1` kadar geri çekilir. Hiç eşleşme yoksa `matchCount-1 = -1` olduğundan `ptr1` bir ilerler.

Hoca bu çözümde fonksiyonun sonunda iki işaretçinin de stringlerin başını göstermesine gerek olmadığını, bu esneklikten yararlanıldığını belirtir.

### 9.4 Denemeler ve off-by-one hatası

`main` içinde `int yer = indexOfV1(ptr1, ptr2);` ile sonuç alınıp yazdırıldı (ekrandan, 01:50:00). `"abcdeabceef"` içinde `"abce"` arandığında 5 bulundu. Olmayan bir örüntü için `-1`, baştan başlayan bir örüntü için 0, en sondaki örüntü için 8 elde edildi.

> **Hocanın vurgusu:** Döngü sınırlarındaki küçüktür/küçük-eşittir, artı bir/eksi bir seçimlerinde bir fazla ya da bir eksik yineleme yapmak sık görülen bir hatadır; buna "off by one" hatası denir. Test ederken en baştaki, en sondaki, aradaki ve hiç olmayan değerlerle, yani sınır değerlerle deneme yapmak en doğrusudur.

Aranın ardından hoca, `indexOfV1` içinde işaretçilerin ilerletilmesinin `main`'deki işaretçilere bir yan etkisi olup olmadığını denedi. Çağrıdan önce ve sonra iki string de yazdırıldı; `main`'deki işaretçiler başlangıç noktalarında kaldı. Bu yüzden onları eski yerlerine çekmeye gerek yoktur.

> **Ek bilgi (derste anlatılmadı):** C'de parametreler değerle geçirilir. Fonksiyona işaretçinin bir kopyası gider; fonksiyonun içinde `ptr1++` yapmak yalnız bu kopyayı değiştirir. İşaretçinin gösterdiği veriyi değiştirmek (`*ptr1 = ...`) ise çağıranın verisini değiştirir.

### 9.5 İkinci çözüm: indexOfV2 ve strstr

Bir öğrencinin de belirttiği gibi bu işi yapan hazır bir fonksiyon vardır: `strstr` (ekrandan, 02:10:00).

```c
int indexOfV2( char *ptr1, char *ptr2) {
    char *ptr;
    ptr = strstr(ptr1, ptr2);
    if( ptr != NULL )   return ptr-ptr1;
    else                return -1;
}
```

Slayttaki imza `char* strstr (const char* szSearch, const char *szFor);` biçimindedir. Fonksiyon ya `szFor`'un `szSearch` içinde ilk geçtiği yerin başını gösteren geçerli bir işaretçi ya da null işaretçi döndürür. Problem tanımı kaçıncı karakter olduğunu istediği için ek bir dönüşüm gerekir: ana string bellekte 1000 numaralı gözden başlıyorsa ve alt string 5. karakterden itibaren bulunduysa `strstr` 1005'i gösterir; $1005 - 1000 = 5$ konumu verir.

İki sürüm aynı programda çalıştırıldı ve her durumda aynı sonucu verdi: sondaki örüntü için 8, olmayan örüntü için −1, baştaki örüntü için 0, ortadaki `"abce"` için 5. Bu dört deneme gcc ile de tekrarlandı ve aynı sonuçlar alındı.

## 10. Çok Boyutlu Diziler

### 10.1 Tanım ve indis hesabı

`int ar[5][3];` 5 satır ve 3 sütundan oluşan, toplam $5 \times 3 = 15$ elemanlı iki boyutlu bir dizidir. İki boyutlu diziler matris uygulamalarında pratik olarak çok kullanılır. İndisler sıfırdan başladığı için `ar[1][2]` aslında ikinci satır, üçüncü sütundaki elemandır (ekrandan, 02:15:00).

Bellekte elemanlar satır satır art arda durur. `ar[1][2]` elemanına en baştan itibaren $1 \times 3 + 2 = 5$ göz ilerleyerek ulaşılır (satır indisi × sütun sayısı + sütun indisi). Derleyici dizi adını bir işaretçi gibi değerlendirir. Dizi, her biri 3 elemanlı 5 tane tek boyutlu dizi gibi düşünülebilir; o zaman `ar[1]` ikinci satırın, yani ikinci küçük dizinin başıdır ve `ar[1][2]` o dizinin iki indisli elemanıdır.

Hoca aynı elemanı işaretçi aritmetiğiyle adım adım yazar (ekrandan, 02:40:00):

```c
ar[1][2]
*(ar[1]+2)
*(*(ar+1)+2)
```

Önce `ar[1]` yerine `*(ar+1)` yazılır, sonra sağdaki `+2` ve soldaki `*` eklenir. Üç ifade de aynı elemanı verir. Hoca, normalde koda ikinci ve üçüncü satırdaki gibi ifadeler yazılmadığını, bunların yalnız ifadenin nasıl değerlendirildiğini göstermek için yazıldığını, bu tür işlemlerin işaretçiler üzerinden yapıldığını söyler. gcc ile 0'dan 14'e kadar doldurulan bir `int ar[5][3]` dizisinde üç ifade de 5 değerini verdi.

Üç boyutlu dizi de tanımlanabilir: `char x[3][4][5]`, üst üste konmuş üç tane 4×5'lik matris gibi düşünülebilir. Dört ve beş boyutlu diziler de olabilir, ama üç boyutlu varlıklar olarak bunları görselleştirmekte zorlanırız; teorik matematik ve fizik işlemlerinde kullanılabilir. Derste çoğunlukla iki boyutlu dizilerle çalışılacaktır.

### 10.2 İlk değer verme

Slayttaki iki örnek iç süslü parantezlerin etkisini gösterir (ekrandan, 02:20:00):

```c
int exap[5][3] = { { 1, 2, 3 },
                   { 4 },
                   { 5, 6, 7 } };
```

Sonuç:

```text
1  2  3
4  0  0
5  6  7
0  0  0
0  0  0
```

Normalde 5 satır için her birinde 3 eleman olan 5 süslü parantez grubu yazılır; burada yalnız 3 grup verilmiştir, yani eksik değer verilmiştir. İlk satır tam doldurulmuştur. İlk satırın grubuna dördüncü bir değer yazılamaz, çünkü dizi 3 sütunlu tanımlanmıştır. İkinci satırda yalnız 4 verildiği için diğer iki göz 0 olur. Üçüncü satır 5, 6, 7'dir; kalan satırlar da 0'dır. Hoca, dizi bu şekilde ilk değerle tanımlandığında derleyicinin kalan gözleri sıfırla doldurduğunu, `malloc`'ta böyle bir garanti olmadığını vurgular.

```c
int exap[5][3] = { 1, 2, 3,
                   4,
                   5, 6, 7 };
```

Sonuç:

```text
1  2  3
4  5  6
7  0  0
0  0  0
0  0  0
```

İç süslü parantezler yazılmazsa alt satıra geçmek gibi boşluklar (white space) derleyici için bir şey ifade etmez; yalnız göze hitap eder ve burada yanıltıcıdır. Değerler ilk elemandan başlayarak satır satır art arda yerleştirilir. Hoca bunun normalde pek yapılmadığını ama bilinmesi gerektiğini söyler. İki sonuç gcc ile de doğrulandı.

## 11. İşaretçi Dizileri

`char *ar_of_p[5];` bir işaretçi dizisidir. Köşeli parantez içinde 5 olmasaydı tek bir işaretçi tanımlanmış olurdu; 5 yazıldığı için 5 tane işaretçi tanımlanır (ekrandan, 02:25:00).

Slayttaki bellek resminde her işaretçi 4 bayt yer tutar: `ar_of_p[0]` 0x1000, `ar_of_p[1]` 0x1004, `ar_of_p[2]` 0x1008, `ar_of_p[3]` 0x100C, `ar_of_p[4]` 0x1010 adresindedir. Son eleman 0x1010–0x1013 arasını kaplar (on altılık tabanda 9'dan sonra A, B, C gelir).

Sonra `char c0 = 'a'; char c1 = 'b';` tanımlanır; bu değişkenler 0x2000 ve 0x2001 adreslerinde saklansın. Ardından:

```c
ar_of_p[0] = &c0;
ar_of_p[1] = &c1;
```

Bu atamalardan sonra 0x1000 gözünün içinde 2000, 0x1004 gözünün içinde 2001 yazar. Böylece aynı işaretçi dizisinin iki ayrı elemanı iki ayrı adresi gösterir. `ar_of_p[2]`, `ar_of_p[3]` ve `ar_of_p[4]` tanımsızdır.

> **Ders sonrası not:** Hoca anlatırken önce "her biri bir bayt olacak" dedi, sonra adresleri 1000, 1004, 1008 diye dörder dörder saydı. Slayttaki doğru bilgi, bu örnekte her işaretçinin 4 bayt olmasıdır. İşaretçi boyutu sistemin mimarisine bağlıdır: 32 bitlik sistemlerde genellikle 4, 64 bitlik sistemlerde genellikle 8 bayttır (bu notu hazırlarken kullanılan sistemde `sizeof(char*)` 8 çıktı).

Hoca slayttaki `ArrayOfPointers.c` örnek dosyasını açtı, ama örneğin dinamik bellek yönetimi görülmeden çok anlamlı olmayacağını söyleyerek ayrıntısını sonraki derse bıraktı.

## 12. Harf Dönüşümü: toUpperCase ve toLowerCase

### 12.1 ASCII kodları

Hoca string manipülasyonuna örnek olarak bir stringdeki harfleri büyük ya da küçük harfe çevirmeyi seçer. Excel'deki tabloda İngiliz alfabesinin ASCII kodları görülür (ekrandan, 02:40:00):

```text
A   B   C   D   E   F   ...  Z
65  66  67  68  69  70  ...  90

a   b   c   d   e   f   ...  z
97  98  99  100 101 102 ...  122
```

Büyük harfler küçük harflerden önce gelir; aralarında başka karakterler de vardır. Büyük bir harfin koduna 32 eklenirse küçük harf karşılığı, küçük bir harfin kodundan 32 çıkarılırsa büyük harf karşılığı elde edilir. İngiliz alfabesinde 26 harf olduğu için son harfin kodu ilk harfin koduna 25 eklenerek bulunur: $65 + 25 = 90$, $97 + 25 = 122$. Hoca tabloyu doldururken önce yanlış sayı ekledi, sonra 26 harf olduğunu hatırlayıp 25 eklenmesi gerektiğini düzeltti. Programdaki hata ayıklama satırı da `A` için 65, `a` için 97, `Z` için 90 yazdırdı.

Toplama ve çıkarma yalnız anlamlı aralıkta yapılmalıdır: büyük harfler için 65–90, küçük harfler için 97–122. Aksi hâlde başka karakterler garip karakterlere dönüşür.

### 12.2 Kod

`SIZE` 5 olarak tanımlanmıştır (ekrandan, 02:30:00 ve 02:35:00):

```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void listOneLineOfText( char *p ) {
    int j;
    for( j=0; j<SIZE; j++ ) {
        printf("%c",*p);
        p++;
    }
    printf("\n");
}

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

Ekranda üst sınırlar ilk anda `*p <= 123` ve `*p <= 91` yazılıydı. Hoca 26 harf hesabını düzelttikten sonra bu sınırların ya `<` ile kullanılması ya da sayıların bir azaltılması gerektiğini söyledi ve sayıları azaltmayı tercih etti. Yukarıdaki kod bu düzeltilmiş hâlidir.

Fonksiyonlar başlangıç adresini bir `char` işaretçisiyle alır. Her harf için önce değerin aralıkta olup olmadığına bakılır, aralıktaysa `*p` üzerinden 32 çıkarılır ya da eklenir; döngünün her adımında işaretçi bir sonraki karakteri gösterir. Önceki ders saatinde görüldüğü gibi, sonunda işaretçiyi geri çekmeye gerek yoktur.

`main` içinde 5×5'lik bir karakter matrisi kullanılır; hoca metinleri tutmak için en pratik olanın kare matris olduğunu düşünmüştür (ekrandan, 02:45:00 ve 02:50:00):

```c
int main(int argc, char *argv[]){
    char metinler[SIZE][SIZE], i;
    ...
    for( i=0; i<SIZE; i++ ) {
        printf("Enter text %d: (max %d letters)", i, SIZE);
        scanf("%s",&metinler[i]);
    }
    for( i=0; i<SIZE; i++ ) {
        toUpperCase(metinler[i]);
    }
    listOneLineOfText(metinler[1]);
    ...
}
```

`metinler[i]`, i. satırın başlangıç adresidir; fonksiyona bu verilir. Tek bir satırı yazdırmak için `listOneLineOfText(metinler[1])` gibi bir çağrı yeterlidir; döngü içinde bütün satırlar verilirse bütün metin yazdırılır.

Matrisin tamamını yazdıran fonksiyonda hoca yalnız harf karşılığı olan karakterlerin basılmasını, anlamsız karakterlerin hiç yazılmamasını ve her satırın sonunda yeni satıra geçilmesini ister. Bunun için iki iç içe döngü yerine $5 \times 5 = 25$ kez dönen tek bir döngü kullanılır. Matrisin başını gösteren `p` için `*(p+0)`, `*(p+1)`, `*(p+2)`, ... art arda gelen gözlerdir; "satır indisi × sütun sayısı + sütun indisi" kuralı burada da geçerlidir. Böylece iki boyutlu bir matris üzerinde tek bir işaretçiyle ilerlenebilir. <!-- BELİRSİZ: Bütün satırları yazdıran fonksiyonun (listAllLines) gövdesi okunan karelerde görünmüyor; yalnız main içindeki listAllLines(metinler[0]) çağrısı görülüyor. -->

Derste her satıra en çok beş karakter girildi; girilen satırlar doğru saklandı ve gösterildi. `toLowerCase` sonrasında yalnız büyük harfler küçüldü, zaten küçük olan harfler değişmedi; garip karakter oluşmadı. `toUpperCase` ile de bütün harfler büyük harfe çevrildi. gcc ile 4 harflik girişlerle yapılan denemede de aynı sonuç alındı (gcc `scanf("%s",&metinler[i])` satırı için tür uyarısı verir; doğru biçim `scanf("%s", metinler[i])`'dir).

Hoca bu çevrimin orijinal stringi bilerek değiştirdiğini söyler. Orijinal değişmeden kalsın istenseydi iş daha karmaşık olurdu: fonksiyonda `size*size` elemanlık yedek bir alan ayrılır, içerik oraya kopyalanır, değişiklik kopyada yapılır ve fonksiyon `void` yerine bu kopyayı döndürür. Hoca bu örneği alıştırma olarak bıraktı (bkz. Örnek Sorular).

> **Ders sonrası not:** Hoca satıra bir fazla karakter (6 harf) girildiğinde de sorun çıkmadığını, `scanf`'in taşma yapmadığını söyledi. Bu doğru değildir. `char metinler[5][5]`'in bir satırında 5 harf ve sondaki `'\0'` için 6 bayt gerekir; 5 harf girildiğinde bile `'\0'`, 6 harf girildiğinde son harf ve `'\0'` bir sonraki satırın başına yazılır. Satırlar sırayla okunduğu için bu baytların üzerine sonraki `scanf` yazmış, taşma görünmemiştir. Son satırdaki taşma ise dizinin tamamen dışına yazar. Güvenli kullanım, satıra en çok `SIZE-1` harf girmek ya da `scanf("%4s", metinler[i])` gibi bir genişlik sınırı vermektir.

## 13. Uygulama: Dinamik İki Boyutlu Dizi ve Histogram

Kaydın bu bölümü teori dersinden ayrı bir uygulama oturumudur. Oturumu yürüten öğretim elemanı, bu haftanın konusunun dinamik bellek ayırma ve matrisler üzerinde bazı işlemler olduğunu, iki problemin birlikte kodlanacağını söyler. Dinamik bellek konusunu henüz görmemiş olanlar için konuya baştan girilir. Ekranın solunda problem belgesi, sağında Dev-C++ vardır.

### 13.1 Problem

Belgedeki metin şöyledir (ekrandan, 03:15:00): N×M boyutlu bir resim (matris) renk paletinde bulunan piksel değerlerinden oluşmaktadır. Histogram, bir resimdeki her bir renk değerinin tekrar miktarını gösteren grafiktir. Aşağıdaki maddelere uyarak N×M boyutlu bir resmin histogram grafiğini bir matris ile ifade eden programı yazınız.

1. Renk paleti `enum` kullanılarak oluşturulacaktır (Siyah → 0, Gri → 128, Beyaz → 255).
2. N ve M boyutları kullanıcı tarafından girilecektir.
3. Matrisin değerleri de kullanıcı tarafından girilecektir.
4. Sonuçta piksel değeri ve tekrar miktarı (frekans) bilgilerini içeren 3×2 boyutlu bir matris oluşturulacaktır.
5. Hem resim hem de histogram matrisleri dinamik bellek ayırma ile tanımlanacaktır.

Belgedeki örnek 6×6'lık resim matrisi ve histogram matrisi:

```text
255  255  128  255    0    0
128    0    0  128    0  128
255  128  128  255  255  128
  0  128  128    0  128    0
  0  255  255  255    0  128
128  128  128  255  255    0

Piksel  Frekans
   0      11
 128      14
 255      11
```

Bu frekanslar python ile sayılarak doğrulandı ($11 + 14 + 11 = 36 = 6 \times 6$).

Histogramı sezgisel anlatmak için oturumda 4×4'lük renkli bir örnek çizilir: kırmızı 4, yeşil 6, sarı 6 kez tekrarlanmıştır. Grafikte bunlar çubuk olarak gösterilir; matriste ise her rengin yanına tekrar sayısı (frekans) yazılır.

### 13.2 enum ile renk paleti

```c
enum Palet{
Siyah=0,
Gri=128,
Beyaz=255
};
```

Böylece programın herhangi bir yerinde `Siyah` yazılarak 0 değerine ulaşılabilir (ekrandan, 03:25:00). Oturumun sonunda `Siyah`, `Gri` ve `Beyaz` yazdırılarak 0, 128 ve 255 değerleri gösterildi.

### 13.3 Resim matrisinin dinamik oluşturulması

Değişkenler `int N, M, i, j;` ve `int **resim, **histogram;` olarak tanımlanır. Kullanıcıdan boyutlar alınır (ekrandan, 03:35:00):

```c
printf("Lutfen resim boyutlarını satır ve sutun olarak sirayla giriniz: \n");
scanf("%d %d", &N, &M);

resim = (int**)malloc(N*sizeof(int*));
if(resim == NULL){
    printf("Bellekte yer ayrilamadi!!");
    return -1;
}

for(i = 0; i < N; i++)
{
    resim[i] = (int*)malloc(M*sizeof(int));
    if(resim[i] == NULL){
        printf("Bellekte yer ayrilamadi!!");
        return -1;
    }
}
```

Önce satırlar, sonra sütunlar oluşturulur. `resim` bir işaretçiyi gösteren işaretçidir (`**`): N tane satır işaretçisinden oluşan bir diziyi gösterir. Tek boyutlu bir dizi oluşturulsaydı ikinci `*`'a gerek olmazdı. `malloc` içindeki `*` ise çarpmadır. Her satır işaretçisine sonra M tane `int` için yer ayrılır; burada tek `*` kullanılır, çünkü artık tamsayıları gösteren bir işaretçi istenmektedir.

Bellekte yer olmayabilir; bu durumda `malloc` `NULL` döndürür. Bu kontrol hem satır işaretçisi dizisi için hem de her satır için yapılır; ayrılamamış bir alan varmış gibi devam etmek hataya yol açacağı için program sonlandırılır.

Belgedeki hatırlatmalar:

- `malloc`'un parametresi, kaç eleman tutulacağı ile bir elemanın boyutunun (`sizeof`) çarpımıdır. Belgedeki örnekte 5 tamsayı için $5 \times 4 = 20$ baytlık alan ayrılır. Karakter tutulacak olsaydı `int` yerine `char` yazılırdı.
- `calloc` aynı işi yapar ama parametreleri virgülle ayrı verilir ve ayrılan alana sıfır değeri atanmış olarak gelir. Aradaki tek fark budur.
- İşi biten alan `free` ile geri verilir; böylece bellek o alanı başka bir yere verebilir.

İki boyutlu yapıyı canlandırmak için oturumda bir çizim yapılır: dikey bir sütun düşünülür; bu sütunun her gözü bir satırı gösteren işaretçidir ve her birinden yatay olarak M elemanlı bir dizi çıkar. "Sıfırıncının sıfırıncısı", "sıfırıncının birincisi" diye elemanlara ulaşılır. Statik `int erey[2][3]` için satır indisleri 0 ve 1, sütun indisleri 0, 1, 2'dir.

> **Hocanın vurgusu:** Boyut 3 ise indis 3'e kadar gitmez, 2'de biter. Yeni öğrenenler sıfırdan başlama konusunu sık karıştırır.

Değerler satır satır okunur:

```c
for(i = 0; i < N; i++)
{
    printf("%d. satir elemanlarini giriniz: \n", i);
    for(j = 0; j < M; j++)
    {
        scanf("%d", &resim[i][j]);
    }
}
```

İlk yazımda `printf`'e `i` verilmesi unutulmuştu; bir öğrencinin uyarısıyla eklendi. Matris yazdırılırken her satırdaki elemanlar arada boşluk bırakılarak yazılır ve satır bitince `printf("\n")` ile alt satıra geçilir; yoksa bütün satırlar yan yana yazılır ve resim N×M biçiminde görülmez. İlk denemede 2×3'lük bir matris girildi (ilk satır 0'lar, ikinci satır 128'ler) ve doğru yazdırıldı. Derleme ilk anda kodda kullanılan Türkçe karakterler yüzünden hata verdi; bunlar düzeltildi.

### 13.4 Histogram matrisi ve indis hesabı

Histogram matrisinin boyutu hiçbir zaman değişmez (3×2); statik de tanımlanabilirdi ama alıştırma için dinamik oluşturulur. Satırlar `calloc` ile ayrılır, çünkü frekanslar sıfırdan sayılacaktır (ekrandan, 03:55:00):

```c
for(i = 0; i <= 2; i++)
{
    histogram[i] = (int*)calloc(2, sizeof(int));
}

for(i = 0; i < N; i++)
{
    for(j = 0; j < M; j++)
    {
        tmp = resim[i][j];
        histogram[(tmp/127)][0] = tmp; // Pikselin değerini atadık.
        histogram[(tmp/127)][1]++;     // Frekansını 1 arttırdık.
    }
}
```

Satır işaretçisi dizisinin kendisi de resim matrisindeki gibi ayrılır ve `NULL` kontrolü yapılır. <!-- BELİRSİZ: histogram = (int**)malloc(3*sizeof(int*)); satırı okunan karelerde görünmüyor; altyazıya göre resim için yazılan ayırma ve NULL kontrolü kopyalanıp histogram için düzenlendi. -->

İndis hesabı bir kısa yoldur. Tam sayı bölmesinde $0 / 127 = 0$, $128 / 127 = 1$, $255 / 127 = 2$ olur. Böylece histogramda değeri döngüyle aramak yerine satır indisi doğrudan hesaplanır: 0 değeri 0. satıra, 128 değeri 1. satıra, 255 değeri 2. satıra gider. Sıfırıncı sütuna piksel değeri yazılır, birinci sütundaki frekans `++` ile bir artırılır. Bu yöntem yalnız değerler bu şekilde aritmetik olarak dizildiği için işe yarar; başka değerler olsaydı başka bir çözüm gerekirdi.

Oturumda şu beklenti de tartışılır: resim matrisinde yalnız 128 kullanılmışsa sonuçta 0. ve 2. satırların hem değer hem frekans sütunu 0 kalır, yalnız 1. satırda 128 ve kullanım sayısı görülür.

**Soru:** Bir öğrenci her seferinde piksel değerini (0, 128, 255) yeniden yazmanın gerekli olup olmadığını sorar. **Cevap:** Gerekli değildir; isteyen ilk sütunun değerlerini baştan bir kez atayıp sonra yalnız frekanslarla ilgilenebilir.

Programın geliştirilebileceği bir yer de gösterilir: kullanıcı 0, 128 ve 255 dışında bir değer girerse değeri yeniden girmesi istenebilir.

Histogram 3 satır, 2 sütun olarak `printf("%4d   ", histogram[i][j]);` ile hizalı yazdırılır.

### 13.5 Belleği serbest bırakmak

```c
for(i = 0; i < N; i++)
    free(resim[i]);
free(resim);
```

Önce her satır, sonra satır işaretçisi dizisi serbest bırakılır. Oluştururken önce `resim`, sonra `resim[i]` ayrıldığı için silerken sıra terstir; yalnız `resim` silinirse içindeki satırlar bellekte kalır. Histogram için de aynısı 3 satırla yapılır.

Derste 3×3'lük bir matrisle (ilk satır 0, 128, 255; ikinci satır 255, 128, 0; üçüncü satır 0, 0, 0) çalıştırıldığında histogram 0 → 5, 128 → 2, 255 → 2 çıktı. Programın tamamı gcc ile derlenip hem bu girişle hem belgedeki 6×6 matrisle çalıştırıldı; sonuçlar sırasıyla 5/2/2 ve 11/14/11 çıktı.

**Soru:** Bir öğrenci `free`'ye neden ihtiyaç duyulduğunu sorar. **Cevap:** Bellekte istediğimiz kadar yer ayırırız; örneğin 5 tamsayı için 20 bayt. Bu alanı kullanmayı bıraktığımızı belleğe söylemezsek, daha sonra yer isteyen birine o alan verilemez. Küçük örneklerde alan küçüktür, ama büyük problemlerde ayrılan alanları `free` ile geri vermek gerekir.

**Soru:** Neden doğrudan bir matris tanımlanmadığı sorulur. **Cevap:** N ve M kullanıcıdan alındığı için derleme anında bilinmez; bu yüzden `int eren[N][M]` gibi bir tanım yapılamaz, dinamik ayırma gerekir. En büyük boyut biliniyorsa (ör. 10×10) o kadar yer statik olarak da ayrılabilir. Ama büyük problemlerde ihtiyaç kadar bellek kullanmak daha verimlidir; gereğinden fazla alan ayırmak hoş karşılanmaz.
## 14. Uygulama: Üç Zar Toplamının Olasılık Matrisi

### 14.1 Problem

Belgedeki metin (ekrandan, 04:25:00): Üç adet zar beraber atılıyor ve bu zarların üst yüze gelen rakamları toplanıyor.

- Üç zarın olası her bir toplam sonucunu birinci kolonda, olasılığını da ikinci kolonda tutacağınız bir matrisi dinamik bellek ayırma ile tanımlayınız.
- Matrisin birinci kolonunda bulunan üç zar toplamı değerleri tekrar etmemelidir (ilk kolon tekil olmalıdır).
- İkinci kolondaki olasılık değerlerini döngü/kontrol/aritmetik operasyonlar vb. komutlardan uygun olanlarını kullanarak doldurunuz (elle `mat[i,j] = 0.0046296` şeklinde "hard coded" bir atama yapmayınız).

Belgedeki örnek tablo: 3 → 0.0046296.., 4 → 0.0138888.., 5 → 0.0277777.., ..., 18 → 0.0046296...

### 14.2 Çözüm

Her zar 1 ile 6 arasında gelir. En küçük toplam üçünün de 1 gelmesiyle 3, en büyük toplam üçünün de 6 gelmesiyle 18'dir; 3'ten 18'e 16 farklı toplam vardır. Matris 16 satır ve 2 sütunludur. Olasılıklar ondalıklı olacağı için tür `float`'tur (ekrandan, 04:25:00 ve 04:30:00):

```c
int main(){
    int i, j, k;
    int toplam;
    float **deger;

    deger = (float**)malloc(16*sizeof(float*));
    if(deger == NULL)
    {
        printf("Bellekte yer ayrilamadi!!");
        return -1;
    }
    for(i = 0; i < 16; i++)
    {
        deger[i] = (float*)calloc(2, sizeof(float));
        if(deger[i] == NULL){
            printf("Bellekte yer ayrilamadi!!");
            return -1;
        }
    }

    for(i = 1; i <= 6; i++){
        for(j = 1; j <= 6; j++){
            for(k = 1; k <= 6; k++){
                toplam = i + j + k;
                deger[toplam - 3][0] = toplam;
                deger[toplam - 3][1] += P;
            }
        }
    }

    for(k = 0; k < 16; k++){
        printf("%.f\t%.8f\n", deger[k][0], deger[k][1]);
    }

    for(k = 0; k < 16; k++){
        free(deger[k]);
    }
    free(deger);

    return 0;
}
```

- Üç zar için üç iç içe döngü vardır; indisler 0'dan değil 1'den başlar ve 6'ya kadar gider.
- Her üçlünün olasılığı $\frac{1}{6^3} = \frac{1}{216}$'dır. Bu değer her seferinde hesaplanmasın diye `#define` ile `P` adıyla bir kez tanımlanır. <!-- BELİRSİZ: P'nin #define satırı okunan karelerde görünmüyor; altyazıda "1 bölü 6 üzeri 3" olarak anlatılıyor. Ondalıklı sonuç verebilmesi için 1.0/216 gibi kayan noktalı bir ifade olmalıdır; test için #define P (1.0/216) kullanıldı. -->
- Satır indisi önceki problemdeki gibi bir hesapla bulunur. Toplam 3 ise satır 0, toplam 18 ise satır 15 olmalıdır; aradaki fark 3'tür. Bu yüzden `toplam - 3` kullanılır. Bu nedenle `toplam` indis olarak kullanılacağı için `int` yapılmıştır. Sıfırıncı sütuna toplamın kendisi yazılır, birinci sütuna olasılık eklenir.
- Kodlama sırasında öğrenciler iki yazım hatasını yakaladı: bir satırda `toplam` yerine `top` yazılmıştı, ve yazdırma döngüsü `k` ile dönerken içeride `deger[i]` yazılmıştı. İkisi de düzeltildi.

Çıktı (ekrandan, 04:30:00):

```text
3   0.00462963
4   0.01388889
5   0.02777778
6   0.04629630
7   0.06944445
8   0.09722221
9   0.11574072
10  0.12499997
11  0.12499997
12  0.11574072
13  0.09722221
14  0.06944445
15  0.04629630
16  0.02777778
17  0.01388889
18  0.00462963
```

Python ile sayıldığında 3'ten 18'e kadar toplamların kaç farklı yolla oluştuğu 1, 3, 6, 10, 15, 21, 25, 27, 27, 25, 21, 15, 10, 6, 3, 1'dir (toplam 216); olasılıklar bunların 216'ya bölümüdür. Program gcc ile `calloc`'lu hâliyle derlenip çalıştırıldı ve ekrandakiyle aynı çıktıyı verdi.

> **Ek bilgi (derste anlatılmadı):** Çıktıdaki 0.12499997 gibi değerler tam olarak 0.125 olmalıdır ($27/216$). Fark, `float` türünün sınırlı duyarlılığından ve 27 kez art arda toplamadan kaynaklanan yuvarlama hatasıdır. `double` kullanmak ya da önce sayıp sonra bölmek (`sayac / 216.0`) bu hatayı azaltır.

**Soru:** Bir öğrenci, `malloc` ile ayrılan alana hiç değer atanmadığı hâlde `P`'nin nasıl üzerine toplandığını, ilk değerin sıfır olmadığını sorar; program hata vermemiştir. **Cevap:** Öğretim elemanı öğrencinin haklı olduğunu söyler. Hata vermemesi değerin sıfır olduğunu göstermez; o alanda önceden kalan küçük bir değer olabilir ve sonuca eklenmiş olabilir. Sıfır olduğundan emin olmak her zaman daha doğrudur; bu yüzden satırlar `calloc` ile ayrılmalıdır. Kod `calloc(2, sizeof(float))` olarak düzeltildi; `calloc`'ta parametrelerin çarpım işaretiyle değil virgülle ayrıldığı da ayrıca hatırlatıldı. Yukarıdaki kod düzeltilmiş hâlidir.

## Örnek Sorular

### Soru 1: Örüntü eşleştirme (ekrandan, 01:40:00; derste sözlü, 01:30:37)

Kullanıcıdan iki string alınacak. Birinci stringin içinde ikinci string varsa kaçıncı karakterden itibaren başladığını, yoksa −1 döndüren bir fonksiyon yazınız. Fonksiyon parametre olarak iki karakter işaretçisi almalıdır.

> **Çözüm (derste verildi):** İki çözüm verildi. `indexOfV1` iki işaretçiyle elle arama yapar (bölüm 9.3); `indexOfV2` `strstr` kullanır ve `ptr - ptr1` farkıyla konumu bulur (bölüm 9.5). `"abcdeabceef"` içinde `"abce"` → 5, sondaki `"eef"` → 8, baştaki `"abcd"` → 0, `"abe"` → −1 (gcc ile doğrulandı).

### Soru 2: Orijinali değiştirmeden büyük harfe çevirme (derste sözlü, 02:46:38)

`toUpperCase` fonksiyonunun, kendisine verilen stringi değiştirmeden, stringin büyük harfe çevrilmiş bir kopyasını döndüren sürümünü yazınız.

> **Çözüm (derste verilmedi):** Fonksiyon kopya için `malloc` ile yer ayırır, harfleri dönüştürerek kopyalar ve kopyayı döndürür. Döndürülen alanı çağıran taraf `free` ile serbest bırakmalıdır. Bu sürüm sabit `SIZE` yerine `strlen` kullanır. gcc ile derlenip çalıştırıldı; `"Merhaba dunya 123"` için orijinal değişmedi, kopya `"MERHABA DUNYA 123"` oldu.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *toUpperCopy( const char *p ) {
    size_t n = strlen(p), j;
    char *q = (char*) malloc(n + 1);
    if( q == NULL ) return NULL;
    for( j = 0; j < n; j++ ) {
        if( p[j] >= 'a' && p[j] <= 'z' )
            q[j] = p[j] - 32;
        else
            q[j] = p[j];
    }
    q[n] = '\0';
    return q;
}

int main(void) {
    char metin[] = "Merhaba dunya 123";
    char *buyuk = toUpperCopy(metin);
    if( buyuk == NULL ) return 1;
    printf("orijinal: %s\n", metin);
    printf("kopya   : %s\n", buyuk);
    free(buyuk);
    return 0;
}
```

### Soru 3: Histogram matrisi (ekrandan, 03:15:00)

N×M boyutlu bir resim (matris) 0, 128 ve 255 piksel değerlerinden oluşmaktadır. Renk paleti `enum` ile tanımlanacak (Siyah → 0, Gri → 128, Beyaz → 255), N ve M ile matrisin değerleri kullanıcıdan alınacak, piksel değeri ve frekansını içeren 3×2 boyutlu histogram matrisi oluşturulacaktır. Hem resim hem histogram matrisi dinamik bellek ile tanımlanacaktır. Belgedeki örnek 6×6 matris için histogram nedir?

> **Çözüm (derste verildi):** Bölüm 13'teki program. Satır indisi `tmp/127` ile bulunur, histogram satırları `calloc` ile sıfırlanmış olarak ayrılır, sonunda önce satırlar sonra satır işaretçisi dizisi `free` ile serbest bırakılır. Belgedeki 6×6 matris için histogram 0 → 11, 128 → 14, 255 → 11'dir (python ve gcc ile doğrulandı).

### Soru 4: Üç zar toplamının olasılık matrisi (ekrandan, 04:25:00)

Üç zar beraber atılıyor ve üst yüze gelen rakamlar toplanıyor. Olası her toplamı birinci kolonda, olasılığını ikinci kolonda tutan matrisi dinamik bellekle tanımlayınız. Birinci kolondaki değerler tekrar etmemeli; olasılıklar elle yazılmamalı, döngü ve aritmetik işlemlerle hesaplanmalıdır.

> **Çözüm (derste verildi):** Bölüm 14'teki program. 16×2'lik `float` matris, üç iç içe döngü, satır indisi `toplam - 3` ve her üçlü için $1/216$ ekleme. Sonuçlar: 3 ve 18 → 0.00462963, 4 ve 17 → 0.01388889, 5 ve 16 → 0.02777778, 6 ve 15 → 0.04629630, 7 ve 14 → 0.06944444, 8 ve 13 → 0.09722222, 9 ve 12 → 0.11574074, 10 ve 11 → 0.125 (python ile doğrulandı; `float` toplamada son basamaklarda küçük yuvarlama farkları görülür).

## Dersin Toparlaması

Bu derste C'de stringin ayrı bir tür değil, `'\0'` ile biten bir `char` dizisi olduğu görüldü. Çift tırnaklı metinlerin sabit olduğu, dizi adına string atanamayacağı ve değiştirilebilir bir string için `malloc` ile yer ayırıp `strcpy` ile kopyalamak gerektiği canlı denemelerle gösterildi. `strlen`, `strcpy`, `strncpy`, `strcat`, `strncat`, `strcmp`, `strncmp` ve `strstr` fonksiyonları tanıtıldı. Örüntü eşleştirme önce iki işaretçiyle elle, sonra `strstr` ile çözüldü; sınır değerlerle test ve off-by-one hatası vurgulandı. Çok boyutlu dizilerde `ar[i][j]` ile `*(*(ar+i)+j)` eşdeğerliği, ilk değer vermede iç süslü parantezlerin etkisi, işaretçi dizilerinin bellek görünümü ve ASCII aritmetiğiyle harf dönüşümü işlendi.

Uygulama oturumunda bu konular dinamik bellekle birleştirildi: `int **` ve `float **` ile iki boyutlu diziler kuruldu, `malloc` ve `calloc` farkı, `NULL` kontrolü ve `free` sırası uygulandı. Histogram ve zar olasılığı problemlerinde değerden satır indisini doğrudan hesaplama (`tmp/127`, `toplam-3`) kısa yolu kullanıldı. Hoca, işaretçi dizileri örneğinin dinamik bellek yönetimi görüldükten sonra daha anlamlı olacağını söyleyerek ayrıntısını sonraki derse bıraktı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
