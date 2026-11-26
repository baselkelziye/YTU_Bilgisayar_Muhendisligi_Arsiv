# Ders 1 Çalışma Özeti

## Genel Konular

- Önceki konuların kısa tekrarı
  - Değişken adları rakamla başlayamaz; harf, rakam ve alt çizgi kullanılır, alt çizgi harf gibi sayılır. Anahtar kelimeler ad olarak kullanılamaz.
  - Atamada sol taraf (left value) her zaman bir bellek alanını gösteren ifade olmalıdır (değişken, dizi elemanı, işaretçi). Sağ taraf (right value) bunlar olabileceği gibi hesaplanabilen herhangi bir ifade de olabilir.
  - `main` programın başlangıç noktasıdır. 0 dönüş kodu düzgün çıkış demektir; sorun varsa 0 dışında bir kodla çıkılır.
  - `scanf` değeri bir adrese okur; basit değişkenlerde adres almak için `&` işleci kullanılır. `%d` tam sayı biçim karakteridir.
- `system("PAUSE")` kullanımı
  - IDE'den çalıştırılan program hemen kapandığı için çıktıyı görmek amacıyla `system("PAUSE")` kullanılır. `system` fonksiyonu, kodun çalıştığı işletim sisteminin komutunu çalıştırır.
  - `PAUSE` bir C komutu değil, DOS/Windows komutudur. Unix gibi başka bir sistemde bu komut olmayabilir; hangi işletim sisteminde çalışılıyorsa ona uygun komut verilmelidir.
  - Hoca `getch` fonksiyonunun her işletim sisteminde ve sürümde aynı davranmadığını deneyimlediği için `system("PAUSE")`'u tercih ettiğini söyledi.
- Önişlemci: `#define` (ekrandan, 00:15:00)
  - `#define NOTHING 0` bir ada sabit değer bağlar. Derleyici, derlemeden önce kaynak kodda `NOTHING` geçen her yere `0` yapıştırır (kopyala-yapıştır gibi). Diskteki kaynak dosya değişmez; bu iş bellekte yapılır.
  - Sabit adları geleneksel olarak büyük harfle yazılır. Adlandırılmış sabitin iki yararı vardır: anlamsız bir sayıya açıklayıcı bir ad verir (örneğin geçersiz değer için `-1` yerine `INVALID`) ve programı değiştirmeyi kolaylaştırır.
  - Değişken yerine `#define` kullanmanın avantajı bellekte yer kaplamamasıdır. `int nothing = 0;` dört baytlık yer ayırır, `#define` hiç yer ayırmaz. Değeri bir kez belirlenip değişmeyen matematik sabitleri için uygundur: `#define PI 3.1416`.
  - Sabitler değişken gibi kullanılamaz: `NOTHING = j + 5` ya da `PI += 1.0` hatalıdır ("invalid lvalue in assignment"), çünkü `PI` bir bellek adresi değildir. Ama `PI + 1` gibi bir ifade içinde kullanılabilir.
- Önişlemci: `#include`
  - `#include <dosya.h>`: dosya, derleyicinin ya da işletim sisteminin belirlediği include dizininde aranır.
  - `#include "dosya.h"`: önce projenin bulunduğu dizinde, bulunamazsa `< >` ile aranan yerde aranır. Kendi `.h`/`.c` dosyalarımızı proje dizinine koyarak ekleyebiliriz.
- `main` fonksiyonunun biçimi (ekrandan, 00:20:00 ve 00:25:00)
  - Tam biçim `int main(int argc, char *argv[])`'dir: `argc` argüman sayısı, `argv` karakter dizilerinden oluşan argümanlardır. C'de ayrı bir string türü yoktur; karakter dizileri kullanılır. Ayrıntılar işaretçi ve komut satırı argümanları konusunda görülecek.
  - Parametre kullanılmayacaksa `int main(void)` yazılabilir; hocanın derleyicisi bunu kabul etti. `void main` ise derleyici tarafından reddedildi; `main` bir değer döndürmelidir.
  - Konsolda Türkçe karakterler (örneğin "ü") düzgün görünmedi. Çıktının sonuna `\n` konmazsa "Press any key to continue" mesajı aynı satıra yapışır.
- Veri tiplerinin sınıflandırılması (ekrandan, 00:30:00)
  - Veri tipleri: `void`, skaler türler ve birleşik (aggregate) türler.
  - Skaler türler: aritmetik türler (tam sayı türleri ve kayan noktalı türler), işaretçiler ve `enum`.
  - Birleşik türler skaler türlerin birleşimidir; `struct` ve `union` ileriki haftalarda görülecek.
  - C kuvvetli tiplemeli bir dildir: her değişkenin mutlaka bir türü vardır. `void` yalnız fonksiyonların dönüş türü (bir şey döndürmüyorsa) ya da parametre listesi (parametre almıyorsa) için kullanılır.
  - İşaretçi başlı başına bir skaler türdür; gösterdiği bellek alanında hangi türde veri saklandığı da belirtilmelidir.
  - `enum`, değeri yalnız belli bir küme içinden alınabilen veriler içindir: pizza boyu (small, medium, large), kan grubu gibi.
- Skaler veri tipleri ve niteleyiciler (ekrandan, 00:35:00)
  - Skaler türler için 9 ayrılmış kelime vardır: `char`, `int`, `float`, `double`, `enum` (temel türler) ve `long`, `short`, `signed`, `unsigned` (niteleyiciler).
  - `float` ve `double` ikisi de ondalıklı sayıdır. `double` daha hassastır ama daha fazla bellek kullanır ve işlemleri biraz daha yavaştır; `float` tersidir.
  - `long` kapasiteyi iki katına çıkarmayı, `short` yarıya indirmeyi amaçlar. `unsigned`, işaret bitini de veri için kullanarak negatif sayılardan vazgeçme pahasına pozitif aralığı iki katına çıkarır. Varsayılan olarak tam sayılar işaretlidir.
  - Tanım: `int j;`, aynı türden birden fazla değişken: `int j, k;`. Bir bloktaki bütün tanımlar çalıştırılabilir deyimlerden önce gelmelidir.
- Tam sayı türleri, boyutları ve biçim karakterleri (ekrandan, 00:40:00)
  - ANSI standardı yalnız şunu ister: bayt en az 8 bit, `int` en az 16 bit olmalı ve bilgisayarın "doğal" boyutunu (işlemcinin tek komutta işlediği bit sayısı) temsil etmelidir.

    | Tür | Boyut (bayt) | Değer aralığı | Biçim |
    |---|---|---|---|
    | `int` | 4 | $-2^{31}$ .. $2^{31}-1$ | `%d` |
    | `unsigned int` | 4 | $0$ .. $2^{32}-1$ | `%u` |
    | `short int` | 2 | $-2^{15}$ .. $2^{15}-1$ | `%hi` |
    | `long int` | 4 | $-2^{31}$ .. $2^{31}-1$ | `%li` |
    | `unsigned short int` | 2 | $0$ .. $2^{16}-1$ | `%hu` |
    | `unsigned long int` | 4 | $0$ .. $2^{32}-1$ | `%lu` |
    | `signed char` | 1 | $-2^{7}$ .. $2^{7}-1$ | `%c` |
    | `unsigned char` (pek anlamlı değil) | 1 | $0$ .. $2^{8}-1$ | `%uc` |

  - Karakterlerin arka planda sayısal karşılığı vardır; bu eşleme ASCII standardıyla yaygınlaştı. 65 büyük `A`'dır. ASCII Türkçe ya da başka dillere özgü karakterleri desteklemez.
- Aynı verinin farklı biçim karakterleriyle yorumlanması (ekrandan, 01:00:00 ve 01:05:00)
  - Değişkenin türü değişmez, ama bellekteki 0 ve 1'ler `printf` biçim karakterine göre farklı yorumlanabilir.
  - `65`: bütün tam sayı biçimlerinde 65, `char` olarak `A` yazıldı. `%uc` ise `65c` yazdı: derleyici `%u`'yu sayı olarak basıp `c`'yi düz karakter olarak ekledi.
  - `66000`: `short` ve `unsigned short` biçimlerinde 464 çıktı. 2 bayta sığmayan sayının üst kısmı atılıp alt 2 baytı yazılır: $66000 - 65536 = 464$.
  - `-66`: `unsigned int` ve `unsigned long` biçimlerinde 4294967230, `unsigned short` biçiminde 65470 çıktı. Negatif sayılar ikiye tümleyen (two's complement) ile saklandığı için işaretsiz yorumlandığında büyük pozitif sayılar ortaya çıkar.
- Sekizli ve onaltılı tam sayı sabitleri (ekrandan, 01:20:00)
  - Tam sayı sabitleri onluk, sekizli (başta `0`) ya da onaltılı (başta `0x`) yazılabilir. Negatif işaret `0x`'in soluna gelir. Örnekler: 21 = `025` = `0x15`, -87 = `-0127` = `-0x57`, 255 = `0377` = `0xFF`.
  - Bir tam sayı sabiti `int`'e sığıyorsa `int`, sığmıyorsa `long int` türündedir. Son ekler: `u`/`U` işaretsiz, `l`/`L` long.
  - Onaltılı gösterim renk kodlarında (RGB, her bileşen 0-255) ya da ikili verileri okurken işe yarar. Onaltılı yazdırmak için biçim karakteri `%x`'tir.
- Kayan noktalı türler (ekrandan, 01:25:00)
  - `float` için `%f`, `double` için `%lf`. `double` "çift hassasiyet" demektir; genelde `float` 4, `double` 8 bayttır. `long double` tanımlanabilir ama bazı platformlarda düz `double` olur.
  - Ondalık nokta yazımları: `0.356`, `5.0`, `0.000001`, `.7`, `7.`; bilimsel gösterim (`%e`): `3e2`, `5E-5`.
  - `%5.7f` gibi biçimlerde noktanın sağındaki sayı ondalık kısımda kaç basamak yazılacağını belirtir. Soldaki sayı toplam genişliktir; sayı daha büyükse kırpılmaz, yalnız hizalama için başa boşluk konur.
- İlk değer atama (ekrandan, 01:40:00)
  - Tanım değişkene bellek ayırır ama oraya bir ilk değer koymayabilir. Açık bir atama yapmadan değeri okumak öngörülemeyen sonuçlar verir.
  - `char ch = 'A';` ile `char ch; ch = 'A';` aynıdır. Karakter sabitleri tek tırnakla yazılır.
- Tür hiyerarşisi ve örtük dönüşümler (ekrandan, 01:45:00)
  - Türler dardan genişe sıralanabilir: `char`, `short`, `int`, `unsigned int`, `long`, `unsigned long`, `float`, `double`, `long double`. Aşağıdan yukarı (dar türden geniş türe) atama güvenlidir, tersi veri kaybına yol açabilir.
  - Derleyici bir ifadeyi alt ifadelere böler; her alt ifadede bir işleç ve ona bağlı işlenenler vardır. Çoğu ikili işleç iki işlenenin aynı türde olmasını ister; türler farklıysa derleyici tür hiyerarşisine bakarak birini ötekine çevirir.
  - `1 + 2.5` bir `int` ve bir `double` içerir; sonuç güvenli taraf olan `double` olarak hesaplanır (3.5). Elle yazılan ondalıklı sabitler `double` kabul edilir.
  - Ondalıklı bir değer tam sayıya atanırken ondalık kısım yuvarlanmadan atılır (`2.9` → `2`).
- İşaretli ve işaretsiz türlerin karıştırılması (ekrandan, 01:55:00)
  - `unsigned int a = 5; int b = -11;` ile `a + b` sonucu `int`'e atanıp `%d` ile basılınca -6, `unsigned int`'e atanıp `%u` ile basılınca büyük bir pozitif sayı (4294967290) çıkar.
  - Sonucu negatif olabilecek işlemlerin sonucu işaretli bir türe atanmalıdır.
- Tam sayı bölmesi ve açık tür dönüşümü (ekrandan, 02:05:00)
  - `int j = 2, k = 3; float f; f = k / j;` sonucu 1.000000'dır: iki işlenen de tam sayı olduğu için tam sayı bölmesi yapılır ve 0.5 kaybolur.
  - `f = (float) k / j;` 1.5 verir. Tür dönüşümü (cast) yalnız hemen sağındaki değere uygulanır, ama işlenenlerden birinin ondalıklı olması bölmenin ondalıklı yapılması için yeter. `3.0 / 2` de 1.5 verir.
  - `f = (float)(k / j);` yine 1.0 verir, çünkü önce tam sayı bölmesi yapılır, sonra sonuç çevrilir.
  - Parantezle açıkça yazılan dönüşüme açık (explicit) dönüşüm, derleyicinin kendi yaptığına örtük (implicit) dönüşüm denir.
- `enum` ve `typedef` (ekrandan, 02:30:00 ve 02:40:00)
  - `enum { red, blue, green, yellow } color;` ile `color` yalnız bu değerleri alması amaçlanan bir değişken olur. Değerler arka planda 0'dan başlayan tam sayılarla saklanır: `red` 0, `blue` 1, `green` 2, `yellow` 3.
  - Slayta göre `color = bright;`, `intensity = blue;` ve `color = 1;` tür çatışması, `color = green + blue;` yanıltıcı kullanımdır. Ancak hocanın derleyicisi bunların hiçbirine hata vermedi; `green + blue` 3 olarak basıldı. Hoca bu davranışı beklemediğini ve bunların yine de yapılmaması gerektiğini söyledi.
  - `typedef` (type definition) bir veri tipine kendi adımızı vermeyi sağlar: `typedef long int INT32;` sonrasında `INT32 j;` yazılabilir. `typedef` önişlemci komutu değil, dil komutudur; başına `#` konmaz. Adlar dikkat çeksin diye büyük harfle yazılır.
  - `typedef enum { red, blue, green, yellow } COLORS;` ile `COLORS color = yellow; COLORS color2 = green;` gibi aynı türden birden çok değişken tanımlanabilir. `typedef` olmadan da `enum { ... } color, color2;` virgül yazımıyla birden çok değişken tanımlanabildi. `typedef`'in asıl yararı, türün birden çok yerde (örneğin başka `.c` dosyalarında) kopyalanmadan kullanılmasıdır.
  - `void` türünün iki amacı: fonksiyonun bir şey döndürmediğini belirtmek ve türden bağımsız genel amaçlı işaretçi (`void *`) tanımlamak.

## Hocanın Özellikle Vurguladığı Kısımlar

- `#define` sabitleri değişken değildir
  - Sabite değer atanamaz; yalnız ifadelerde kullanılır. Bellekte yer kaplamaması asıl avantajıdır.
- Derleme hatalarında ilk hataya odaklanmak
  - Değişken tanımlanmadan kullanılınca ilk hata zincirleme başka hatalara yol açar. Hatalar tek tek, ilkinden başlayarak çözülmelidir.
- Türlerin kapladığı alanı ve dönüşümlerin güvenliğini bilmek
  - Hangi dönüşümün güvenli, hangisinin güvensiz olduğu bilinmeli. Güvensiz işlemler en yakın güvenli ortak türde yapılmalıdır. Hoca, bir aracın kontrol yazılımında böyle bir hatanın fiziksel zarara yol açabileceği örneğini verdi. <!-- BELİRSİZ: altyazıda araç adı bozuk ("donumun"), büyük olasılıkla dron -->
  - Ders sonrası not: Tablodaki `long int` = 4 bayt bilgisi hocanın kullandığı Windows derleyicisi içindir. Boyutlar platforma bağlıdır; örneğin 64 bit Linux'ta gcc ile `long` 8 bayttır.
- İlk değere güvenmemek
  - İlk değer atanmamış değişkenin 0 olacağına güvenilmemeli; değişkenler kullanılmadan önce anlamlı bir değerle ilklendirilmeli. Özellikle bayrak değişkenlerinde ve işaretçilerde bu daha da önemlidir.
- Tam sayı bölmesine dikkat
  - İki tam sayının bölümü ondalıklı bir değişkene atansa bile tam sayı bölmesi yapılır. İşlenenlerden biri açıkça `(float)` ile çevrilmelidir; `(float)(k / j)` işe yaramaz.
- Belirsizliği parantezle gidermek
  - Karmaşık ifadelerde işlem sırasını ve türleri anlaşılır kılmak için parantez kullanılmalıdır.
- Uç durumların amacı
  - Hoca, bu uç durum örneklerinin sınavda ezberlensin diye değil, arka plandaki karmaşıklık ve gerçeklemeye bağlı garip davranışlar fark edilsin diye yapıldığını söyledi.

## Kısa Tekrar Notları

- `#define AD deger`: derlemeden önce metin yerine koyma; bellek harcamaz, atanamaz.
- `#include <...>` sistem/derleyici dizininde, `#include "..."` önce proje dizininde arar.
- `system("PAUSE")` işletim sistemine bağlıdır (DOS/Windows komutu).
- Veri tipleri: `void`, skaler (aritmetik, işaretçi, `enum`), birleşik (`struct`, `union`).
- 9 skaler kelime: `char`, `int`, `float`, `double`, `enum`, `long`, `short`, `signed`, `unsigned`.
- Biçimler: `%d`, `%u`, `%hi`, `%li`, `%hu`, `%lu`, `%c`, `%x`, `%f`, `%lf`, `%e`.
- 66000 `short` olarak 464 ($66000 - 2^{16}$); -66 `unsigned` olarak $2^{32} - 66 = 4294967230$.
- Onaltılı sabit `0x` ile, sekizli sabit `0` ile başlar.
- `float` → `int` atamada ondalık kısım atılır (yuvarlama yok).
- `int / int` tam sayı bölmesidir; `(float) k / j` doğru, `(float)(k / j)` yanlış.
- `enum` değerleri 0'dan başlayan tam sayılardır; `typedef` türe yeni ad verir.

## Detaylı Açıklamalar

- **`#define` neden değişkenden iyi?** Hoca, `int nothing = 0;` gibi bir değişkenin bellekte boşuna dört bayt kaplayacağını, `#define NOTHING 0` tanımının ise derleyiciye yönelik bir metin değiştirme talimatı olduğu için hiç yer kaplamadığını anlattı. Derleyici kodu taramadan önce `NOTHING` gördüğü her yere `0` yazar. Bu yüzden `PI` gibi sabitler ifadelerde kullanılabilir (`PI + 1` 4.1416 verdi), ama `PI += 1.0` gibi bir atama "invalid lvalue in assignment" hatası verir, çünkü sol taraf bir bellek adresi değildir.

- **`main` ve ilk program.** Hoca ekranda şu kodla başladı (ekrandan, 00:20:00):

  ```c
  #include <stdio.h>
  #define PI 3.1416

  int main(int argc, char *argv[])
  {
      ...
      system("PAUSE");
      return 0;
  }
  ```

  Sonra parametre listesini `void` yaptı ve derleme sorunsuz tamamlandı (ekrandan, 00:25:00). `main`'in dönüş türü `void` yapıldığında ise derleyici `main`'in `int` döndürmesi gerektiğini söyledi.

- **Biçim karakterleriyle yorumlama deneyi.** Hoca bir `int sayi` değişkenini sırasıyla `%d`, `%u`, `%hi`, `%li`, `%hu`, `%lu`, `%c` ve `%uc` ile yazdırdı ve önce Not Defteri'ne beklediği çıktıları yazdı. `sayi = 66000` için çıktı (ekrandan, 01:00:00):

  ```text
       int    66000
   uns.int    66000
   srt.int    464
   lng.int    66000
  usrt.int    464
  ulng.int    66000
      char    (anlamsız bir karakter)
  uns.char    66000c
  ```

  Bir öğrenci $65536 + 464 = 66000$ olduğunu fark etti; yani `short` yorumlamada sayının 2 bayta sığmayan üst kısmı atılıyor. `sayi = -66` için (ekrandan, 01:05:00) `int`, `short`, `long` biçimleri -66; `unsigned int` ve `unsigned long` 4294967230; `unsigned short` 65470; `%uc` ise `4294967230c` verdi.

- **Kayan noktalı sayıların yazdırılması.** Hoca `float ondalikli = 7000000.555;` değişkenini `%f`, `%.3f`, `%.4f`, `%.5f`, `%lf` ve `%e` ile yazdırdı (ekrandan, 01:30:00). Ondalık kısmın beklenmedik biçimde ".500" gibi göründüğünü, yani basamakların "yutulduğunu" gördü; bir öğrencinin önerisiyle küçük bir sayı (`7.777`) denendiğinde çıktı beklendiği gibi oldu (ekrandan, 01:35:00): `%f` 7.777000, `%.2f` 7.78, `%.4f` 7.7770, `%.5f` 7.77700, `%e` 7.777000e+000. `7.555` ile `%.2f` denendiğinde 7.56 yerine 7.55 çıktı.
  - Ders sonrası not: Hoca büyük sayıdaki kaybı derleyici hatası olarak yorumladı. Doğrusu, `float` yaklaşık 7 anlamlı basamak tutabilir; 7000000 civarında iki komşu `float` arasındaki fark 0.5'tir, bu yüzden `7000000.555` en yakın `float` olan `7000000.5` olarak saklanır (gcc ile denendi: `%f` 7000000.500000). Benzer şekilde `7.555`, `float` olarak 7.5549998... saklandığı için `%.2f` ile 7.55 yazılır; `printf` yuvarlama yapar ama saklanan değer zaten 7.555'in biraz altındadır.

- **Örtük dönüşüm ve `-3 / 4 + 2.5`.** Slaytta `-3 / 4 + 2.5` ifadesinin üç işleç (`-`, `/`, `+`) içerdiği yazıyor (ekrandan, 01:45:00). Hoca tekli eksinin en yüksek önceliğe sahip olduğunu, önce bölmenin, sonra toplamanın yapıldığını ağaç çizerek gösterdi.
  - Ders sonrası not: Hoca bölmenin -0.75 vereceğini söyledi. Doğrusu, C'de `-3 / 4` iki tam sayının bölümüdür ve 0 verir; ifadenin sonucu 2.5'tir (gcc ile denendi). -0.75 elde etmek için işlenenlerden biri ondalıklı olmalıdır: `-3.0 / 4 + 2.5` = 1.75.

- **İşaretsiz toplama örneği** (ekrandan, 01:55:00):

  ```c
  unsigned int a = 5;
  int b = -11;
  unsigned int c = a+b;
  printf("c=%u\n",c);
  ```

  Çıktı büyük bir pozitif sayıdır: $2^{32} - 6 = 4294967290$ (gcc ile derlendi ve çalıştırıldı). Önce `c` `%d` ile yazdırıldığında -6 görüldü; bir öğrenci değerin işaretsiz saklandığını ama `%d` ile işaretli yorumlandığını hatırlattı.

- **Açık tür dönüşümü** (ekrandan, 02:05:00): `int j=2, k=3; float f; f = k / j;` → `f=1.000000`. `(float) k / j` ve `(float) k / (float) j` → 1.500000; `(float)(k / j)` → 1.000000 (gcc ile denendi).

- **`enum` ve `typedef` denemesi** (ekrandan, 02:40:00):

  ```c
  typedef enum { red, blue, green, yellow } COLORS;
  typedef enum { bright, medium, dark } INTENSITY;

  int main( )
  {
      COLORS color = yellow;   // OK
      COLORS color2 = green;   // OK
      ...
      printf("Color: %d\n", color);
      printf("Color2: %d\n", color2);
  ```

  Çıktı 3 ve 2 oldu. `%c` ile yazdırıldığında 3 numaralı karakter konsolda kalp işareti olarak göründü.
  - Ders sonrası not: C'de `enum` değerleri `int` gibi davrandığı için farklı `enum`'lar arasında ya da `enum` ile tam sayı arasında atama derleme hatası değildir; bu yüzden hocanın derleyicisi hata vermedi. Güncel gcc yalnız `-Wall -Wextra` ile farklı `enum` türleri arası atamada uyarı veriyor (denendi). C++'ta ise bu atamalar hatadır (büyük olasılıkla hocanın beklentisi buradan geliyordu).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
