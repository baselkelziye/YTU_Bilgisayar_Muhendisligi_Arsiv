# Ders 22 Çalışma Özeti

## Genel Konular

- Programı birden fazla dosyaya bölmek (splitting)
  - Büyük bir C projesi birden çok `.c` dosyasından ve bunlara ait `.h` (header) dosyalarından oluşabilir. Bölmenin amacı yönetimi kolaylaştırmak ve kodu tekrar kullanılabilir kılmaktır; kendi fonksiyon ve veri yapısı kütüphanenizi kurabilirsiniz.
  - Header dosyası fonksiyon prototiplerini, veri yapısı (struct/typedef) tanımlarını, makro tanımlarını ve global verileri içerir; `.c` dosyası kodun kendisini (implementasyonu) içerir (ekrandan, 00:20:00).
  - Dosyalardan en az biri `main()` fonksiyonunu içermelidir. Başka dosyadaki fonksiyonu kullanmak için ilgili `.h` dosyası `#include` ile eklenir. İki dosyada aynı adlı fonksiyon olmamalı, global değişkenlere dikkat edilmelidir (ekrandan, 00:20:00).
  - `#include <...>` derleyicinin sistem dizinlerinde, `#include "..."` önce bulunulan klasörde arar.
- Derleme zinciri
  - Önişlemci makro ve sabitleri açar; derleyici (compiler) C kodunu assembly'ye, assembler assembly'yi makine koduna (nesne dosyası, `.o`) çevirir; bağlayıcı (linker) nesne dosyalarını ve kütüphaneleri birleştirip çalıştırılabilir dosyayı üretir.
  - Önceden derlenmiş ve değişmemiş kod yeniden derlenmez; bu, çok dosyalı projelerde zaman kazandırır.
- Bağımlılık (dependency) ve makefile
  - Örnek ağaç: `project1` ← `data.o`, `main.o`, `io.o`; `data.o` ← `data.c`, `data.h`; `main.o` ← `data.h`, `main.c`, `io.h`; `io.o` ← `io.h`, `io.c` (ekrandan, 00:25:00).
  - `io.c` içinde bir hata düzeltilirse `io.o` yeniden üretilmeli, `io.o` değiştiği için `project1` de yeniden bağlanmalıdır (ekrandan, 00:25:00).
  - Makefile, her hedefin neye bağlı olduğunu ve nasıl üretileceğini bir kez yazmayı sağlar; `make` komutu yalnız değişen dosyaları yeniden derler. Dosya adı geleneksel olarak `Makefile`'dır. Makefile içinde de makro (değişken) tanımlanabilir (örneğin nesne dosyaları listesi).
  - Dev-C++ gibi IDE'ler proje derlenirken arka planda kendi makefile'ını üretir ve `make` ile derler; derste bir Dev-C++ projesinin ürettiği makefile gösterildi.
  - `salute` örneği: `salute.h` prototipi, `salute.c` implementasyonu, `main.c` çağrıyı içerir (ekrandan, 00:30:00 ve 01:05:00).
- Önişlemci makrolarının tekrarı
  - Makro, bir ada bağlı metin parçasıdır (makro gövdesi). Makro adı geçtiği her yerde gövdesiyle yer değiştirir: buna makro açılımı (macro expansion, substitution) denir. Örnek: `#define BUFF_LEN 512` sonrası `char buf[BUFF_LEN];` satırı `char buf[512];` olur (ekrandan, 00:40:00).
  - Sabit belirten makro adları geleneksel olarak büyük harfle yazılır.
  - Fonksiyon çağrısında programın akışı fonksiyona gider (dallanma, yığına kayıt atma); makroda ise gövde çağrının olduğu yere kopyalanır.
  - Uzun makro satır sonuna `\` konarak birden fazla satıra yayılabilir.
  - Fonksiyon benzeri makro: `#define min(a,b) ((a) < (b) ? (a) : (b))` (ekrandan, 00:50:00).
  - `#undef` ile bir makro kaldırılıp yeniden tanımlanabilir.
  - Hazır makrolar: `__LINE__`, `__FILE__`, `__TIME__`, `__DATE__`, `__STDC__`. Makro içinden normal bir fonksiyon da çağrılabilir (CHECK makrosu örneği).
- Makro ve fonksiyon karşılaştırması (ekrandan, 00:45:00)
  - Avantajlar: makrolar fonksiyon çağrısı yükünden kurtardığı için genelde daha hızlıdır; argümanlarda tip kısıtı yoktur, tek makro birden çok veri tipi için çalışır.
  - Dezavantajlar: argümanlar gövdede her geçtiği yerde yeniden hesaplanır (yan etki); fonksiyon bir kez derlenir, makro her kullanıldığı yerde açılır; makrolar argüman sayısını denetler ama tipini denetlemez; makrolu kodda hata ayıklamak (adım adım izlemek) zordur.
- Koşullu derleme (ekrandan, 00:55:00)
  - `#if`, `#elif`, `#else`, `#endif`: switch yapısına benzer. Koşulun parantez içinde olması gerekmez, bloklar süslü paranteze alınmaz. Bir `#if` bloğunda istenen sayıda `#elif`, en fazla bir `#else` (en sonda) olabilir; her `#if` bir `#endif` ile kapanmalıdır.
  - `#ifdef`, `#ifndef`, `defined(...)`: bir makronun tanımlı olup olmadığına göre derleme. Hata ayıklama (DEBUG) kodunu açıp kapatmak için kullanılır.
- Bit düzeyinde işlemler
  - Operatörler: `&` (AND), `|` (OR), `^` (XOR), `~` (bire tümleme), `<<` (sola kaydırma), `>>` (sağa kaydırma).
  - `24 & 17 = 16`, `24 | 17 = 25` (ekrandan, 01:05:00).
  - Sola bir bit kaydırmak 2 ile çarpmak, sağa bir bit kaydırmak 2'ye bölmek gibidir. Taşan bitler kaybolur, boşalan yerlere 0 gelir.
- Örnek: binary dosyaya struct ile yazma ve dosyada kayıt arama (`fwrite`, `fread`, `feof`)
- Örnek: özyinelemeyle diziyi tersten yazdırma ve yer değiştirerek ters çevirme
- Özyinelemeli fonksiyonların karmaşıklığını kabaca kestirme
- Örnek: string'i özyinelemeyle tersten yazdırma; `char **` ile dinamik string dizisi oluşturup tersten yazdırma

## Hocanın Özellikle Vurguladığı Kısımlar

- Header dosyasına implementasyon konmaz
  - Header'da yalnız fonksiyon prototipleri, makro tanımları ve struct tanımları bulunur. Fonksiyon gövdeleri ayrı `.c` dosyasına yazılır. Fonksiyonların gövdesini `.h` dosyalarına koymak yanlıştır.
- Makro yazarken üç sık hata
  - Makro tanımının sonuna noktalı virgül koymak.
  - Makro tanımında `=` kullanmak (`#define N = 100` gibi).
  - Parametreleri gövdede parantez içine almamak: `#define SQUARE(x) x*x` ile `SQUARE(3+4)` ifadesi `3+4*3+4 = 19` olur, beklenen 49 değil.
- Yan etki (side effect)
  - `z = min(x++, y);` satırı `z = ((x++) < (y) ? (x++) : (y));` olarak açılır; `x < y` ise `x` iki kez artar (ekrandan, 00:50:00). Makroya yan etkili argüman (`++`, `--`) verilmemelidir.
- Makronun açılımını elle yazabilmek
  - Verilen bir makro çağrısının önişlemciden sonra neye dönüştüğünü yazabilmek gerekir; hoca bunu ölçme açısından önemli bir beceri olarak andı.
- `^` üs alma değildir
  - C'de `^` bit düzeyinde XOR'dur, üs alma operatörü değildir.
- Dosya adı koda gömülmez
  - Gerçek bir projede okunacak dosyanın adı koddan değiştirilmez, kullanıcıdan alınır.
- Struct ile okuma/yazma kolaylık sağlar
  - Yapılandırılmış bir dosya struct üzerinden tek blok halinde (`fwrite`/`fread`) yazılıp okunursa her alan için ayrı değişken gerekmez.
- Birden çok kayıt dönecekse dinamik dizi gerekir
  - Aramada birden fazla kayıt çıkabiliyorsa (örneğin aynı puana sahip öğrenciler), bulunan kayıtlar `malloc`/`realloc` ile büyütülen bir struct dizisine kopyalanmalıdır.
- Dizi `=` ile kopyalanmaz
  - String'i yeni ayrılan alana kopyalamak için `strcpy` (ya da daha genel `memcpy`) kullanılır.
- Özyinelemeyi izlemenin en kolay yolu yığın (stack) çizmektir
  - Her çağrıda yerel değerler ve dönülecek satır yığına konur; temel duruma gelince çağrılar ters sırayla geri döner.

## Kısa Tekrar Notları

- `.h`: prototip, struct, makro, global; `.c`: implementasyon. Bir dosyada `main` olmalı.
- Derleme: önişlemci, derleyici (C'den assembly'ye), assembler (`.o`), linker (çalıştırılabilir dosya).
- Makefile: hedef, bağımlılıklar, komut. `make` yalnız değişenleri derler.
- Makro: metin yerine koyma. Sonunda `;` yok, `=` yok, her parametre ve tüm gövde parantezli.
- `min` üç sayı için: `min(a, min(b, c))`; dört sayı için: `min(min(a, b), min(c, d))`.
- Makro: hızlı, tipten bağımsız; ama yan etki, kod büyümesi, tip denetimi yok, zor hata ayıklama.
- `#if/#elif/#else/#endif`, `#ifdef/#ifndef`, `#undef`.
- `&`, `|`, `^`, `~`, `<<`, `>>`; `x << 1` iki katı, `x >> 1` yarısı (tamsayı bölme).
- `fwrite(&e, sizeof(OGR), 1, fp)` ve `fread(&ogr, sizeof(OGR), 1, fp)`; dosyalar `"wb"`/`"rb"` ile açılır.
- Sıralı arama: kayıt bulunana ya da `feof(fp)` doğru olana kadar oku. Kayıtların sıralı olduğu bilinmiyorsa `<` yerine `!=` koşulu kullanılır.
- Özyineleme karmaşıklığı: tek çağrı ve $n-1$ ile $O(n)$; tek çağrı ve $n/2$ ile $O(\log n)$; iki çağrı ve $n-1$ ile $O(2^n)$.
- String dizisi: `char **kelimeler = calloc(n, sizeof(char*))`; her kelimeye `calloc(m+1, sizeof(char))`; `+1` sondaki `'\0'` için.

## Detaylı Açıklamalar

Dersin ilk bölümünde programın birden fazla dosyaya bölünmesi ele alındı. Bir projede `main.c`, birkaç yardımcı `.c` dosyası ve bunlara ait `.h` dosyaları bulunabilir. Header dosyası "arayüz" görevi görür: hangi fonksiyonların var olduğunu (prototip), hangi veri yapılarının ve makroların kullanılacağını bildirir. Fonksiyonların gövdesi ise aynı adlı `.c` dosyasında yazılır. Derste kullanılan `salute` örneğinde `salute.h` fonksiyonun prototipini, `salute.c` gövdesini içerir:

```c
/* salute.c implements the .h in a .c file: */

#include <stdio.h>
#include "salute.h"
void salute( void ) {
    printf("\n\n HELLO!!! \n\n");
}
```

(ekrandan, 00:30:00)

```c
#include <stdio.h>
#include "salute.h"
int main ( void ) {
    salute();
    return 0;
}
```

(ekrandan, 01:05:00)

`salute.h` dosyası bir yorum satırı, bir `#ifndef`/`#define` koruması, `void salute(void);` prototipi ve `#endif` içeriyordu; korumanın makro adı karede okunamadı. <!-- BELİRSİZ: salute.h içindeki koruma makrosunun adı karede kesik (01:20:00). --> Bu üç dosya derlenince `main.o` ve `salute.o` nesne dosyaları oluşur, linker bunları birleştirip tek bir çalıştırılabilir dosya üretir. Projede `main` içermeyen `salute.c` tek başına derlenip çalıştırılmak istendiğinde bağlayıcı `main` (Windows'ta `WinMain`) bulamadığı için "undefined reference" hatası verir (ekrandan, 00:30:00); bu yüzden dosyalar bir proje içinde birlikte derlenmelidir.

Dosya sayısı 20-30'a çıktığında her denemede bütün dosyaları tek tek derlemek zahmetlidir. Makefile her hedefin bağımlılıklarını ve üretim komutunu bir kez tanımlar. Bağımlılık ağacında bir `.c` dosyası değişirse yalnız ona bağlı `.o` dosyası ve onu kullanan çalıştırılabilir dosya yeniden üretilir. Hoca bu bilginin gömülü sistemler ve düşük seviyeli programlama yapılan yerlerde, ayrıca bir programın derlenip bağlanma adımlarını adım adım anlatma sorusunda karşınıza çıkabileceğini söyledi.

Makrolar konusunda en önemli fikir, makronun bir fonksiyon çağrısı değil metin yerine koyma olmasıdır. Bu yüzden parametreler değerlendirilmeden, oldukları gibi gövdeye yerleştirilir. Parantezsiz bir gövde öncelik hatalarına, `x++` gibi argümanlar da birden çok artırmaya yol açar. Derste üç sayının en küçüğünü bulan makro soruldu. Bir öğrencinin cevabında mevcut iki parametreli `min` makrosu iç içe çağrıldı: `min(a, min(b, c))`. Hoca bunun doğru ve pratik olduğunu, makro zaten açılacağı için dört sayı için `min(min(a, b), min(c, d))` yazmakla ayrı uzun bir makro yazmak arasında sonuç bakımından fark olmadığını söyledi.

Bit işlemlerinde her bit karşılıklı olarak işleme girer. `24 = 11000` ve `17 = 10001` olduğundan AND sonucu `10000 = 16`, OR sonucu `11001 = 25` olur (ekrandan, 01:05:00). Kaydırmada `5 = 0101` için `5 >> 1 = 2`, `5 >> 2 = 1` olur; taşan bitler başa dönmez, yerlerine 0 gelir.

> **Ders sonrası not:** Hoca `5 << 2` için sonucun 10 olacağını söyledi; tahtada da `010100` yazdı. Doğrusu: `5 << 2 = 20` (`10100`), `5 << 1 = 10`. Hoca bu işlemlere "rotate" de dedi; C'deki `<<` ve `>>` döndürme değil kaydırma (shift) işlemidir. Hocanın da söylediği gibi dışarı taşan bitler kaybolur. (gcc ile denendi.)

İkinci bölümde örnekler yapıldı. Dosya örneğinde öğrenci bilgileri (ad, numara, puan) bir `OGR` struct'ında tutuldu. `print_file` fonksiyonu kullanıcıdan alınan dosya adıyla dosyayı `"wb"` kipinde açar, kullanıcıdan kayıt sayısını ve her kaydı alır, her kaydı `fwrite` ile tek blok halinde yazar. `main` dosyayı `"rb"` kipinde açar, aranacak numarayı alır, `fread` ile kayıtları okuyarak numarayı arar (ekrandan, 01:35:00). Hocanın ilk koşulu `ogr.no < no` idi; bu koşul yalnız kayıtlar numaraya göre sıralı yazıldığında çalışır. Sırasız girilen kayıtlarda kayıt bulunamadı; bir öğrencinin sorusu üzerine koşul `ogr.no != no` yapılarak genel hale getirildi.

Özyineleme örneklerinde dizi önce elemanlar yerinde kalarak tersten yazdırıldı (`reverse`), sonra baştaki ve sondaki eleman yer değiştirilip ortaya doğru ilerlenerek gerçekten ters çevrildi (`reverse2`). Bir string, sonundaki `'\0'` karakterine kadar ilerleyip dönüşte karakterleri yazdırarak tersten yazdırıldı. Son olarak kullanıcıdan alınan $n$ kelime `char **` ile tutulan dinamik bir diziye kopyalandı ve kelimeler ters sırayla yazdırıldı. Hoca, işaretçileri yer değiştirerek diziyi gerçekten ters çeviren sürümü alıştırma olarak bıraktı.

Karmaşıklık için hoca hızlı bir kural verdi: problem her çağrıda $n-1$'e iniyor ve tek özyinelemeli çağrı varsa $O(n)$; problem her çağrıda yarıya iniyorsa $O(\log n)$; Fibonacci gibi iki çağrı varsa $O(2^n)$, üç çağrı varsa $O(3^n)$ kabaca beklenir.

> **Ders sonrası not:** Hoca üç çağrının her biri $n/2$'ye inerse karmaşıklığın "3 üzeri log n" olduğunu ve bunun yine üstel olduğunu söyledi. $T(n) = 3T(n/2) + c$ için $3^{\log_2 n} = n^{\log_2 3} \approx n^{1.585}$ olur; bu üstel değil, polinom bir büyümedir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
