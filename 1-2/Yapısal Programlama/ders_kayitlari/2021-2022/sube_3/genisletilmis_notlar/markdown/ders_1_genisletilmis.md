# Ders 1 Genişletilmiş Notu: Önişlemci, Veri Tipleri, Tür Dönüşümleri ve enum

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Konuların Tekrarı
- 2. system("PAUSE") ve İşletim Sistemine Bağlılık
- 3. Önişlemci: #define ve #include
- 4. İlk Program ve main Fonksiyonunun Biçimi
- 5. Veri Tiplerinin Sınıflandırılması
- 6. Skaler Türler, Niteleyiciler ve Tanımlama Kuralı
- 7. Tam Sayı Türleri, Boyutları ve Biçim Karakterleri
- 8. Aynı Verinin Farklı Biçimlerde Yorumlanması
- 9. Sekizli ve Onaltılı Sabitler
- 10. Kayan Noktalı Türler ve Biçimlendirme
- 11. İlk Değer Atama
- 12. Tür Hiyerarşisi ve Örtük Dönüşümler
- 13. İşaretli ve İşaretsiz Türlerin Karıştırılması
- 14. Tam Sayı Bölmesi ve Açık Tür Dönüşümü
- 15. enum, void ve typedef
- Örnek Sorular

## 1. Önceki Konuların Tekrarı

Ders, bir önceki haftada anlatılanların kısa bir tekrarıyla başladı. Değişken adları rakamla başlayamaz; harf ve rakam karışık kullanılabilir, alt çizgi (`_`) harf gibi değerlendirilir. Anahtar kelimeler değişken adı olarak kullanılamaz.

Atama işlecinde iki kavram vardı: sol taraf (left value) ve sağ taraf (right value). Sol taraf her zaman bir bellek alanını gösteren bir ifade olmalıdır; bu bir değişken, bir dizi elemanı ya da bir işaretçi olabilir. Sağ taraf ise bunların yanında hesaplanabilen daha karmaşık ifadeler de olabilir.

Fonksiyon tanımında ve değişken tanımında sıranın önemli olduğu, kodun düzgün biçimlendirilmesi gerektiği ve `main` fonksiyonunun programın başlangıç noktası olduğu hatırlatıldı. Program 0 koduyla çıkarsa düzgün bitmiş demektir; hiçbir şey yazılmazsa da 0 ile çıkılır. Bir sorun olduğunda 0 dışında bir kodla çıkılabilir.

`printf` ve `scanf` fonksiyonları görülmüştü. `scanf` değeri bir adrese okur; bu yüzden basit bir değişkene okurken değişkenin bellek adresini veren `&` (ampersand) işleci konur. Biçim dizgisinde (format string) `%d` tam sayı anlamına gelir; diğer biçim karakterleri bu derste ayrıntılı ele alındı. Önişlemci komutlarına da kısaca girilmişti: `#include` ile kod kitaplıkları eklenir, `#define` ile tanımlar yapılır.

## 2. system("PAUSE") ve İşletim Sistemine Bağlılık

Program IDE'den çalıştırıldığında her şey çok hızlı olur; konsol penceresi hemen kapanır ve çıktıyı inceleme fırsatı kalmaz. Bu yüzden hoca, bir tuşa basılana kadar beklemek için `system` fonksiyonunu kullanıyor. `system`, kodun üzerinde çalıştığı işletim sisteminin bir komutunu çalıştırır. Örnekte verilen komut `PAUSE`'dur; komut satırında `pause` yazıldığında "Press any key to continue" mesajı çıkar ve bir tuşa basılması beklenir.

`PAUSE` bir C komutu değil, bir işletim sistemi (burada DOS/Windows) komutudur. Unix tabanlı bir sistemde böyle bir komut olmayabilir; o zaman "bilinmeyen komut" denip program yine hemen kapanır. Hangi işletim sisteminde çalışan kod yazılıyorsa ona uygun bir komut verilmelidir.

Hoca, bir karakter bekleyen `getch` fonksiyonunun da kullanılabileceğini, döndürdüğü karakterin bir değişkene atanabileceğini söyledi. Ancak `getch`'in her işletim sisteminde ve her sürümde aynı biçimde çalışmadığını deneyimlediği için `system("PAUSE")`'u tercih ettiğini belirtti.

Hoca `system` fonksiyonunun da `printf` ve `scanf` gibi `stdio.h` kitaplığında yer aldığını, bu işleri yapan her programda bu kitaplığın ekleneceğini söyledi.

> **Ders sonrası not:** Standart C'de `system` fonksiyonu `stdio.h`'de değil `stdlib.h`'de bildirilir. Hocanın eski Dev-C++ derleyicisi `stdio.h` ile yetiniyor; güncel derleyiciler `stdlib.h` eklenmezse uyarı verir.

## 3. Önişlemci: #define ve #include

### 3.1 #define

`#define`, önişlemciye bir tanım yapma komutu verir. Yapılan tanım, kaynak kodun her yerine sanki kopyala-yapıştır yapılmış gibi uygulanır (ekrandan, 00:15:00):

- `#define NOTHING 0` bir adı bir sabitle ilişkilendirir.
- Sabitler için bütün harflerin büyük yazılması yaygın bir alışkanlıktır.
- Sabitleri adlandırmanın iki önemli yararı vardır: anlamsız bir sayıya açıklayıcı bir ad verir ve programı değiştirmeyi kolaylaştırır.
- Sabitleri değişken gibi kullanmamaya dikkat edilmelidir: `NOTHING = j + 5` yanlıştır.

`#define NOTHING 0` yazıldığında derleyici önce kodda büyük harflerle `NOTHING` geçen her yere `0` yapıştırır, sonra derler. Diskteki kaynak kod değişmez; bu işlem bellekte yapılır. Hoca bir örnek daha verdi: tam sayılarla çalışırken geçersiz bir değeri `-1` ile gösteriyorsak, kodun her yerinde `-1` görmek anlaşılmayı zorlaştırır. `#define INVALID -1` gibi anlamlı bir ad kodu çok daha okunur yapar.

Peki bu iş için neden bir değişken kullanmıyoruz? Kodun başında `int nothing = 0;` diye bir değişken tanımlansa, bir tam sayı değişken bellekte dört bayt yer kaplar; bu yer boşuna harcanmış olur. `#define` ise bellekte hiç yer kaplamaz, çünkü derleyiciye yönelik bir metin değiştirme talimatıdır. Değeri bir kez belirlenip hiç değişmeyecek sabitler, örneğin matematik sabitleri, için idealdir: `#define PI 3.1416` yazıldığında bir `float` değişkenlik yerden tasarruf edilir.

### 3.2 #include

`#include` çeşitli kod kitaplıklarını programa ekler. Dosya adı iki biçimde verilebilir:

- `#include <stdio.h>`: dosya, işletim sisteminin ya da derleyicinin belirlediği bir dizinde aranır. Dev-C++ kurulduysa bu, programın kurulu olduğu yerdeki `include` klasörüdür. Kendi `.h` ve `.c` dosyalarımızı da oraya kopyalayabiliriz.
- `#include "dosya.h"`: önce projenin bulunduğu dizine bakılır; orada bulunamazsa `< >` ile aranan yere bakılır. Kendi kodumuzu eklemek için dosyayı proje dizinine koymak yeterlidir.

Hoca kendi kodlarını Dev-C++'ın kurulu olduğu dizin içinde açtığı bir `code` klasöründe tuttuğunu söyledi.

## 4. İlk Program ve main Fonksiyonunun Biçimi

Bir "Merhaba dünya" programı yazmak için standart giriş/çıkış kitaplığı `stdio.h` eklenmelidir. Hoca ekranda şu koddan başladı (ekrandan, 00:20:00):

```c
#include <stdio.h>
#define PI 3.1416

int main(int argc, char *argv[])
{
    /* ... yoruma alınmış satırlar ... */
    system("PAUSE");
    return 0;
}
```

`main`'in parametreleri verilebilir de verilmeyebilir de, ama her derleyici boş parametre listesine izin vermez; o zaman normalde verilmesi gereken parametreler yazılır. Birinci parametre `argc` argüman sayısıdır. İkinci parametre `argv` ise karakter dizilerinden oluşur. C'de ayrı bir string türü yoktur; karakter dizileri üzerinden gidilir. Bir karakter dizisine istenen sayıda harf konabilir, ama programa ilk çalıştırılırken birden fazla parametre vermek için ya iki boyutlu dizi kullanılır ya da ikinci boyut işaretçi olarak düşünülür. İşaretçi ve dizi ayrıntıları ile komut satırı argümanlarının okunması ileriki haftalarda ele alınacak; şimdilik bu biçim bir kalıp olarak hatırlanmalı.

Hoca parametre listesine `void` yazdı; derleyici sorun çıkarmadı ve program sorunsuz derlendi (ekrandan, 00:25:00). Sonra `printf("Merhaba Dunya...")` ile ekrana yazdırdı. İki gözlem yapıldı:

- Kodda Türkçe karakter (örneğin "ü") kullanmak derleyiciye sorun çıkarmaz, ama çıktı DOS komut satırında gösterildiği için "ü" garip bir karakter olarak görünür.
- Mesajın sonuna yeni satır karakteri (`\n`) konmazsa "Press any key to continue" mesajı aynı satıra bitişik gelir.

Ardından `main`'in dönüş türü de `void` yapılıp `return 0;` satırı kaldırıldı. Bu kez derleyici `main`'in bir değer (`int`) döndürmesi gerektiğini söyleyerek hata verdi. Yani hocanın derleyicisi parametresiz `int main(void)`'e izin veriyor, `void main`'e izin vermiyor. Başka derleyiciler `argc` ve `argv` parametrelerinin mutlaka yazılmasını isteyebilir.

`#define PI 3.1416` örneği de denendi. Ondalıklı sayı yazdırmak için biçim karakteri `%f`'tir (f: float). `printf`'in birinci parametresi yazılacak metindir; metindeki ilk `%f` ikinci parametreyle, sonraki biçim karakterleri sonraki parametrelerle eşleşir. `printf("%f", PI)` ekrana 3.141600 yazdı.

Sabit bir ifade içinde işleme sokulabilir ama ona değer atanamaz. `PI += 1.0` ya da `PI = ...` gibi bir komut "invalid lvalue in assignment" hatası verdi, çünkü `PI` bir bellek adresi değil, yalnız bir sabit tanımıdır. Buna karşılık `PI + 1` ifadesini yazdırmakta bir sakınca yoktur; çıktı 4.1416 oldu (gcc ile denendi: `4.141600`).

## 5. Veri Tiplerinin Sınıflandırılması

C'de veri tipleri üç grupta incelenir (ekrandan, 00:30:00):

```text
Veri tipleri
├── void
├── Skaler türler
│   ├── Aritmetik türler
│   │   ├── Tam sayı türleri
│   │   └── Kayan noktalı türler
│   ├── İşaretçiler
│   └── enum
└── Birleşik (aggregate) türler
```

**void.** Herhangi bir türü olmayan şeylerdir; bunlar ancak fonksiyon olabilir. Bir değişken tanımlandığında mutlaka bir türü olmalıdır. C kuvvetli tiplemeli (strongly typed) bir dil kategorisindedir: her değişkenin bir türü vardır. Bazı fonksiyonlar geriye bir değer döndürmek zorunda değildir; böyle bir fonksiyonun dönüş türü `void` yazılır. Fonksiyon parametre almıyorsa parantez içine de `void` yazılabilir, ama bu şart değildir.

**Birleşik türler.** Skaler türlerin birleşimidir ("aggregate" birleşik demektir). `struct` ve `union` yapıları bunlara örnektir ve ileriki haftalarda görülecektir.

**Skaler türler.** Tam sayı ve ondalıklı sayı türleri (aritmetik türler), işaretçiler ve `enum`'dur. İşaretçi de başlı başına bir skaler türdür. İşaretçi normalde bir bellek alanının başlangıcını gösterir; ama o bellek alanında hangi türde veri saklandığı da belirtilmelidir, çünkü C kuvvetli tiplemeli bir dildir.

`enum` şu anlama gelir: bir varlık yalnızca belirli bir değer kümesinden değer alabiliyor, başka bir değer alamıyorsa `enum` olarak tanımlanır. Hoca iki örnek verdi: bir pizza dükkânı yalnızca üç standart boy satıyorsa (small, medium, large) başka bir değer olamaz; kan grubu da A, B, AB ve 0 gruplarından biridir. Rh faktörü (pozitif/negatif) için ya ayrı bir `enum` değişkeni ya da bir birleşik tür tanımlanabilir.

## 6. Skaler Türler, Niteleyiciler ve Tanımlama Kuralı

Skaler veri türleri için 9 ayrılmış kelime vardır (ekrandan, 00:35:00):

| | | | |
|---|---|---|---|
| `char` | `double` | `short` | `signed` |
| `int` | `enum` | `long` | `unsigned` |
| `float` | | | |

Temel türler `char` (karakter), `int` (tam sayı), `float` ve `double` (ikisi de ondalıklı sayı) ve `enum`'dur. `float` ile `double` arasındaki fark hassasiyettir. `double` ile noktadan sonra daha fazla basamağa kadar anlamlı sonuç saklanır. Fark özellikle devirli sayılarda görülür: $1/3 = 0.3333\ldots$ sonsuza kadar gider ve bir noktada kesilmesi gerekir; nerede kesileceğini `float` ya da `double` seçimi belirler. `double`'ın bir maliyeti vardır: daha fazla bellek harcar ve onunla yapılan işlemler biraz daha yavaştır. `float` ise daha az hassastır ama daha az bellek kullanır ve daha hızlıdır. Hoca bu derste çok hassas işler yapılmayacağı için ikisinden herhangi birinin kullanılabileceğini, ama farkın bilinmesi gerektiğini söyledi.

<!-- BELİRSİZ: hoca float için "noktadan sonra en fazla 8 basamak" dedi; float'ın hassasiyeti noktadan sonraki basamak sayısıyla değil, toplam anlamlı basamakla (yaklaşık 7) sınırlıdır, bkz. Bölüm 10 -->

**Niteleyiciler (qualifiers).** `long`, `short`, `signed`, `unsigned` temel türlerin (`enum` hariç) başına gelen sıfatlardır ve yapılarını değiştirir:

- `long` kapasiteyi, yani kullanılan bayt sayısını iki katına çıkarmayı amaçlar; `short` yarıya indirir. Örneğin tam sayı 4 bayttır ve işaretli olarak yaklaşık ±2 milyar değer tutar. Daha küçük bir aralık yetiyorsa 4 bayt yerine 2 bayt kullanan `short int` tanımlanır.
- `signed` ve `unsigned` sayının pozitif/negatif ayrımının gerekip gerekmediğini belirtir. Normalde bütün tam sayılar işaretlidir. Negatif sayılar bellekte saklanırken en baştaki bit işaret bitidir: 0 ise sayı pozitif, 1 ise negatiftir. Hiç negatif sayıyla çalışılmayacaksa bu bit de veri için kullanılabilir; böylece negatif sayılardan vazgeçme pahasına pozitif aralık iki katına çıkar. `unsigned int` ile ±2 milyar yerine 0 ile yaklaşık 4,29 milyar arası saklanabilir.

Değişkenin türü tanımlandıktan sonra değişmez; kuvvetli tiplemeli dillerin özü budur. Ama o bellek alanındaki 0 ve 1'ler, biçim dizgisinde türün kendi biçim karakterinden farklı karakterler kullanılarak farklı biçimlerde yorumlanabilir (Bölüm 8).

**Tanımlama.** Önce tür, sonra değişken adı yazılır ve noktalı virgül konur: `int j;`. Aynı türden birden fazla değişken tek satırda tanımlanabilir: `int j, k;`. Kodun tamamı düzeyinde de olsa bir fonksiyon düzeyinde de olsa, bir bloktaki bütün tanımlar çalıştırılabilir deyimlerden önce gelmelidir.

Hoca bunu canlı gösterdi: `ondalikli` adlı bir değişken tanımlanıp aşağıda kullanılıyordu. Tanım kullanımın altına taşındığında derleyici, değişkenin tanımlanmadan önce kullanıldığını söyleyen bir hata verdi ("first use in this function"). Bu ilk hata zincirleme başka hatalara da yol açtı.

> **Hocanın vurgusu:** Hata düzeltirken her zaman ilk hataya odaklanın ve hataları tek tek çözün; böyle daha hızlı ilerlersiniz.

> **Ek bilgi (derste anlatılmadı):** Tanımların blok başında olma zorunluluğu C89/ANSI C kuralıdır. C99 ve sonraki standartlarda tanımlar deyimler arasında da yapılabilir; ama değişken yine kullanılmadan önce tanımlanmış olmalıdır.

## 7. Tam Sayı Türleri, Boyutları ve Biçim Karakterleri

C'nin en yaygın standartlarından biri ANSI standardıdır. Bu standardın tek şartı şudur: bir bayt en az 8 bit olmalı, `int` en az 16 bit (2 bayt) olmalı ve bilgisayarın "doğal" boyutunu temsil etmelidir. Doğal boyut, işlemcinin tek bir komutta işlediği bit sayısıdır (ekrandan, 00:40:00). Bugünkü bilgisayarların doğal genişliği 64 bittir, ama tam sayılar uzun yıllardır standart olarak 32 bit (4 bayt) alınır.

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

Tablonun açıklaması:

- `int` işaretli aralıkta $-2^{31}$ ile $2^{31}-1$ arasıdır; bu yaklaşık ±2,1 milyardır. `%d`'deki d "decimal" (onluk) demektir.
- `unsigned int` negatif sayılara gerek olmadığında iki kat geniş aralık verir: 0 ile $2^{32}-1$. `%u`'daki u "unsigned" demektir.
- `short int` 2 bayttır: $-2^{15}$ ile $2^{15}-1$ arası, biçimi `%hi`.
- `long int` ANSI standardında `int`'i 4 bayttan 8 bayta çıkarmaz; hocanın Dev-C++ ile gelen derleyicisi de böyledir. Biçimi `%li`'dir. Hoca Java ve C# gibi daha güncel dillerde `long`'un 8 bayt olduğunu söyledi.
- İki niteleyici birlikte kullanılabilir. `unsigned short int` 2 baytta 0 ile $2^{16}-1$ arası değer tutar, biçimi `%hu`. `unsigned long int` bu standartta `unsigned int` ile aynı aralıktadır, ama farklı bir biçim karakteri (`%lu`) vardır; bu, farkın olduğu platformlarda işe yarar.
- `char` karakterdir, ama bilgisayar için her şey 0 ve 1 olduğundan her karakterin sayısal bir karşılığı vardır. Bu eşleme ASCII standardıyla yaygınlaştı. ASCII Türkçe karakterleri, Almancadaki "ß" ya da Baltık dillerindeki üst işaretli harfleri desteklemez; İngiliz alfabesinin 26 harfini, rakamları ve çerçeve çizgileri, kalp, telif işareti gibi bazı simgeleri içerir. 65 sayısı büyük `A`'ya karşılık gelir. `char` 1 bayttır ve sayı olarak da yorumlanabildiği için `signed`/`unsigned` ile nitelenebilir.

> **Ders sonrası not:** Tablodaki boyutlar hocanın kullandığı Windows derleyicisi içindir; C standardı yalnız alt sınırları belirler. Örneğin 64 bit Linux'ta gcc ile `long` 8 bayttır (bu not denetlenirken kullanılan sistemde `sizeof(long)` 8 çıktı). Ayrıca `%uc` gerçek bir biçim belirteci değildir: `printf` bunu `%u` ve ardından düz bir `c` harfi olarak işler (Bölüm 8'deki çıktılar bunu gösteriyor).

> **Ders sonrası not:** Hoca 2 baytlık aralığı hesaplarken önce "eksi 65.536'dan artı 65.535'e" dedi, sonra işaretli aralığın bunun yarısı (yaklaşık 32 bin) olduğunu söyledi. Doğrusu: 2 bayt = 16 bit, $2^{16} = 65536$ farklı değer; işaretsiz 0 .. 65535, işaretli $-32768$ .. $32767$.

## 8. Aynı Verinin Farklı Biçimlerde Yorumlanması

Hoca, bir `int sayi` değişkenini tablodaki her biçim karakteriyle bir kez yazdıran bir program kurdu. Ezberlemek gerekmesin diye her satırın başına hangi türe göre yazdırıldığını da kısaltarak yazdı (`int`, `uns.int`, `srt.int`, `lng.int`, `usrt.int`, `ulng.int`, `char`, `uns.char`). Çalıştırmadan önce beklediği çıktıları Not Defteri'ne yazdı.

### 8.1 sayi = 65

65 özellikle `A` harfinin ASCII karşılığı olduğu için seçildi. Pozitif ve küçük bir sayı olduğundan bütün tam sayı biçimlerinde 65 yazılması beklendi. 2 baytın aralığını hatırlamak için hoca hesap makinesinde $2^{16} = 65536$ hesapladı (ekrandan, 00:50:00): işaretsiz 2 bayt 65535'e kadar, işaretli ise yaklaşık 32 bine kadar değer tutar ve 65 bunlara rahatça sığar.

Çıktıda ilk altı satır 65, `char` satırı büyük `A` oldu. `uns.char` satırında ise `A` yerine `65c` çıktı: derleyici `%uc`'yi `%u` gibi düşünüp sayıyı yazdı, ardından `c` harfini ekledi. Hoca bu derleyicinin `unsigned char`'ı bu biçimde kullanmadığını, zaten pek anlamı olmadığını söyledi.

### 8.2 sayı aralıklarının hesabı

Hoca daha büyük sayılarla denemeden önce Excel'de 2, 4 ve 8 baytın tutabileceği değerleri hesapladı (ekrandan, 00:55:00): $2^{32} = 4294967296$, bunun yarısı $2^{31} = 2147483648$ (±2 milyar civarı). 8 bayt için $2^{64}$ yaklaşık $1{,}8 \times 10^{19}$, işaretlisi yaklaşık $9{,}2 \times 10^{18}$'dir.

### 8.3 sayi = 66000

66000, 2 baytın sınırını (65535) aşar. Beklenti: `int`, `unsigned int`, `long` ve `unsigned long` biçimlerinde sorun yok; `short` ve `unsigned short` biçimlerinde ilk bakışta 66000 ile ilgisi anlaşılmayan "garip bir sayı"; `char` biçiminde anlamsız bir karakter. Çıktı (ekrandan, 01:00:00):

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

Hoca, 66000'in ikili gösteriminde `short` olarak bakılınca sol yarının kesildiğini tahmin etti. Bir öğrenci $65536 + 464 = 66000$ olduğunu fark etti. Yani sayının 2 bayta sığmayan üst kısmı atılıyor, yalnız alttaki 2 bayt yorumlanıyor: $66000 - 2^{16} = 464$. Sayı pozitif olduğu için `short` ve `unsigned short` aynı sonucu verdi.

### 8.4 sayi = -66

Beklenti: `int`, `short`, `long` biçimlerinde -66; işaretsiz biçimlerde garip sayılar. Negatif sayının 4 baytlık alanda en baştaki biti 1'dir ve geri kalan bitler doğrudan 66'yı göstermez: bellekte ikiye tümleyen (two's complement) algoritmasıyla saklanır. Bu yüzden işaretsiz yorumlandığında çok büyük bir pozitif sayı çıkar. Çıktı (ekrandan, 01:05:00):

```text
     int    -66
 uns.int    4294967230
 srt.int    -66
 lng.int    -66
usrt.int    65470
ulng.int    4294967230
    char    ¥
uns.char    4294967230c
```

$2^{32} - 66 = 4294967230$ ve $2^{16} - 66 = 65470$'tir (python ile doğrulandı). `unsigned short` biçiminde baştaki iki bayt atılır, kalan iki bayt da çoğunluğu 1 olan bir dizi olduğundan 65536'ya yakın büyük bir sayı çıkar. `unsigned long`, `unsigned int` ile aynı sonucu verdi. `char` biçiminde konsolda yen işareti çıktı.

> **Ek bilgi (derste anlatılmadı):** Gösterilen değerler bu derste gcc ile, her biçime uygun türe açıkça çevrilmiş değerlerle yeniden üretildi ve aynı sonuçlar alındı. `printf`'e biçim karakterinin beklediği türden farklı bir tür vermek (örneğin `int` değişkeni `%li` ile yazdırmak) standarda göre tanımsız davranıştır; sonuç platforma göre değişebilir.

## 9. Sekizli ve Onaltılı Sabitler

İkinci ders saatinde, kayan noktalı sayılara geçmeden önce tam sayılarla ilgili birkaç şey daha anlatıldı (ekrandan, 01:20:00):

- Tam sayı sabitleri onluk (decimal), sekizli (octal) ya da onaltılı (hexadecimal) yazılabilir.
- Genel olarak bir tam sayı sabitinin türü, değeri `int`'e sığıyorsa `int`'tir; sığmıyorsa `long int`'tir.
- Son ekler: `u` ya da `U` işaretsiz (unsigned), `l` ya da `L` long anlamına gelir.

| Onluk | Sekizli | Onaltılı |
|---|---|---|
| 3 | `003` | `0x3` |
| 8 | `010` | `0x8` |
| 15 | `017` | `0xF` |
| 16 | `020` | `0x10` |
| 21 | `025` | `0x15` |
| -87 | `-0127` | `-0x57` |
| 255 | `0377` | `0xFF` |

Tablodaki dönüşümler python ile doğrulandı. Onaltılı sayıların başına `0x` konur; ardından yazılan sayı 16 tabanında yorumlanır. Taban dönüşümünde $16^0$ birler, $16^1$ on altılar basamağıdır; 15 `F`, 16 ise `10` olarak yazılır. Negatif işaret `0x`'in soluna gelir.

Hoca sekizli gösterimin pratikte pek anlamı olmadığını, onaltılı gösterimin ise yararlı olduğunu söyledi. Örneğin renk kodları: bir renk, kırmızı, yeşil ve mavi (RGB) bileşenlerinin her birinin 0-255 aralığındaki değerleriyle gösterilir ve bu yaklaşık 16 milyon renk eder; bu sayılar onaltılı biçimde anlamlıdır. İkili (binary) verilerle çalışırken de her bayt onaltılı bir sayı olarak ele alınabilir.

Hoca örnek olarak `sayi = 0x15;` yazdı ve programı çalıştırdı; `%d` ile ekrana 21 yazıldı. Onaltılı yazdırmanın biçim karakterini sordu; sohbetten bir öğrenci `%x` olduğunu yazdı. `%x` eklenince ekrana 15 yazıldı. Hoca karışmasın diye satırın başına "hex" etiketini ekledi.

## 10. Kayan Noktalı Türler ve Biçimlendirme

### 10.1 Slayt

Kayan noktalı türler (ekrandan, 01:25:00):

- Kayan noktalı değer tutabilecek değişken tanımlamak için `float` (`%f`) ve `double` (`%lf`) kullanılır.
- `double` "double-precision", yani çift hassasiyet demektir: `float`'ın yaklaşık iki katı hassasiyeti temsil edebilir. Bir `float` genelde 4, bir `double` genelde 8 bayt gerektirir. Sınırlar için `<limits.h>`'e bakılabilir.
- `long double` tanımlanabilir, ama bazı platformlarda düz `double` olur.
- Ondalık nokta ile yazım: `0.356`, `5.0`, `0.000001`, `.7`, `7.`
- Bilimsel gösterim (`%e`): `3e2`, `5E-5`
- `%5.7f` gibi farklı gösterim belirteçleri için kaynak kitaba ve internete bakılabilir.

`%` ile `f` arasına sayı konabilir. Noktanın sağındaki sayı, sayının noktadan sonra kaç basamakla yazılacağını belirtir. Noktanın solundaki sayı ise tam sayı kısmı için ayrılacak genişlikle ilgilidir. Bu kırpma yapmaz: yazılacak sayı daha büyükse yine tam yazılır, yalnız hizalama kayar. Amacı, birden fazla sayı peş peşe ya da sekmelerle yazılırken küçük sayıların başına boşluk koyarak hizalamayı korumaktır.

> **Ek bilgi (derste anlatılmadı):** Standart C'de noktanın solundaki sayı tam sayı kısmının değil, nokta ve ondalık basamaklar dahil bütün alanın en küçük genişliğidir. Örneğin `printf("[%8.2f]", 3.14159)` çıktısı `[    3.14]` olur (8 karakter).

### 10.2 Büyük sayı denemesi

Hoca şu kodu yazdı (ekrandan, 01:30:00):

```c
#include <stdio.h>
#define PI 3.1416

int main( )
{
    float ondalikli = 7000000.555;
    printf("     dbl \t%f\n",ondalikli);
    printf("     dbl \t%.3f\n",ondalikli);
    printf("     dbl \t%.4f\n",ondalikli);
    printf("     dbl \t%.5f\n",ondalikli);
    printf(" lng.dbl \t%lf\n",ondalikli);
    printf("     exp \t%e\n",ondalikli);
    system("PAUSE");
    return;
}
```

Not Defteri'ne beklentiler yazıldı: `%f` ve `%.3f` ile 7000000.555, `%.4f` ile sonuna bir 0 eklenmiş hali (7000000.5550), `%e` ile $7 \times 10^6$ civarı bir gösterim. Çalıştırınca ondalık kısımdaki basamaklar "yutuldu": 7000000.555 yerine nokta sonrası farklı bir değer görüldü; bilimsel gösterim ise `7.000000e+006` biçimindeydi. Hoca bunu ilginç bulup derleyicinin ondalıklı sayıları doğru gerçekleyememesine bağladı.

Bir öğrenci, `float` ile böyle sorunların sürekli yaşandığını, örneğin 1001'i 10'a bölünce 100.099998 gibi sonuçlar çıktığını söyledi. Hoca bir işlem yapmadığını, değeri doğrudan elle yazdığını, bu yüzden aynısını görmeyi beklediğini belirtti. Sonra `%.2f` ile yuvarlamalı bir gösterim (7000000.56) beklediğini söyledi; bu da olmadı.

Bir öğrenci daha küçük sayılarla denenirse beklenen etkinin görüleceğini önerdi ("1.55 denerseniz") ve bunun belgelerden değil deneyimden geldiğini söyledi. Hoca sayıyı `7.777` yaptı; çıktı beklendiği gibi oldu (ekrandan, 01:35:00):

```text
    dbl    7.777000
    dbl    7.78
    dbl    7.7770
    dbl    7.77700
lng.dbl    7.777000
    exp    7.777000e+000
```

Burada `%.2f`, üçüncü basamaktaki 7 yüzünden ikinci basamağı 8'e yuvarladı. `7.555` ile `%.2f` denendiğinde ise 7.56 değil 7.55 çıktı; hoca ".5'in yukarı yuvarlanması gerekirdi" dedi. Hoca büyük sayılardaki davranışı şöyle yorumladı: ondalıklı sayıların gösterimi için IEEE standartları vardır; `float` için ayrılan alanı aşan bir sayı yazılınca bari tam sayı kısmı kaybolmasın diye daha az değerli olan ondalık kısım feda ediliyor olabilir.

> **Ders sonrası not:** Hoca durumu bir derleyici hatası ya da gerçekleme eksikliği olarak yorumladı. Doğrusu, bu `float`'ın hassasiyet sınırıdır. `float` (IEEE 754 tek hassasiyet) 24 bitlik anlamlı kısımla yaklaşık 7 anlamlı basamak tutar. 7000000 civarında iki komşu `float` arasındaki fark 0.5'tir; bu yüzden `7000000.555` en yakın `float` olan `7000000.5` olarak saklanır. gcc ile denendiğinde çıktı `7000000.500000`, `7000000.500`, `7000000.5000`, `7000000.50000` ve `7.000000e+06` oldu. Benzer şekilde `7.555` `float` olarak `7.5549998...` saklanır; `printf` aslında yuvarlama yapar, ama saklanan değer 7.555'in biraz altında olduğu için `%.2f` sonucu 7.55 olur (denendi). Değişken `double` tanımlansaydı bu örneklerde beklenen sonuçlar alınırdı.

> **Hocanın vurgusu:** Bu örnekler sınavda "şöyle yazarsak ne çıkar" diye ezberlemek için değil, arka plandaki karmaşıklığı görmek içindir. Gerçeklemeler ince noktalarda garip davranışlara yol açabilir; bunun farkında olun.

## 11. İlk Değer Atama

Değişkenlere ilk değer atamak çok önemlidir (ekrandan, 01:40:00):

- Tanım, değişken için bellek ayırır ama o konuma bir ilk değer koymayabilir.
- Böyle bir değişkenin değeri açık bir atama yapılmadan okunursa sonuç öngörülemez.
- İlk değer vermek için değişken adından sonra bir atama ifadesi yazılır: `char ch = 'A';`
- Bu, `char ch;` ve `ch = 'A';` yazmakla aynıdır.

Sayısal bir değişkene ilk değer atanmamışsa genelde 0 (ondalıklıysa 0.0) olması beklenir, ama C'de bu her gerçeklemede böyle olmayabilir; buna güvenilmemelidir. Değişken yalnız bir hesap sonucunu saklamak için değil de örneğin bir bayrak değişkeni olarak kullanılıyorsa doğru ilk değeri alması daha da önemlidir.

İşaretçilerde iş daha da karışır. İşaretçi belirli bir bellek alanının başlangıcıdır. Bellekten yer istenirken iki farklı yol olduğu görülecek: ayrılan alanı sıfırlayarak vermek ya da "sıfırlamaya uğraşma, ben yönetirim" diyerek olduğu gibi vermek. Ayrıca işaretçiler, ayrılan alanın sonrasına erişmeye bile izin verir. O adreste hangi 0 ve 1'lerin olduğu ve işaretçinin türüne göre nasıl bir değer çıkacağı bilinemez. Bu yüzden basit bir değişken bile olsa, kullanmadan önce ona anlamlı bir değer atanmış olmalıdır.

Karakter türünde değer atanırken tek tırnak kullanılır; karakterin ayırt edicisi tek tırnaktır. Tanımdan sonra başka tanımlar da yapılabilir (`char ch = 'A'; int i = 5;` gibi); yeter ki tanımlar en başta olsun, ardından diğer komutlar gelsin.

## 12. Tür Hiyerarşisi ve Örtük Dönüşümler

### 12.1 Tür hiyerarşisi

Veri türleri en dardan (en az baytla gösterilenden) en genişe doğru bir piramit gibi sıralanır: `char`, `short`, `int`, `unsigned int`, `long int`, `unsigned long int`, `float`, `double`, `long double`. `long int` pratikte bayt sayısını artırmasa da teoride daha geniş çizilmiştir. <!-- BELİRSİZ: piramit slaytının karesi okunmadı; sıra altyazıdaki anlatımdan kuruldu -->

Bu piramitte aşağıdan yukarıya yapılan atamalar güvenlidir, yukarıdan aşağıya yapılanlar güvenli değildir. Örneğin bir `int`'i `long int` olarak ele almak veri kaybına yol açmaz; ama `long int` 8 bayt olsaydı onu 4 baytlık `int`'e atamak değer kaybettirirdi. `int`'i `float`'a atamak genelde sorunsuzdur: 2 milyon tam sayısı `float`'ta 2000000.0 olur. Ama 2000000.999999 gibi bir sayı `int`'e çevrilirse ondalık kısım yuvarlanmadan tamamen kesilip atılır ve bu bilgi kaybolur.

### 12.2 İfadelerin alt ifadelere bölünmesi

Slayttaki anlatım (ekrandan, 01:45:00):

- Derleyici bir ifadeyle karşılaştığında onu alt ifadelere böler. Her alt ifade bir işleç ve ona bağlı bir ya da daha fazla nesneden (işlenen, operand) oluşur.
- Örnek: `1 + 2.5` iki tür içerir: bir `int` ve bir `double`.
- Örnek: `-3 / 4 + 2.5` üç işleç içerir: `-`, `/`, `+`.
- Her işlecin işlenen türlerinin uyumu için kendi kuralları vardır, ama çoğu ikili işleç iki işlenenin aynı türde olmasını ister. Türler farklıysa derleyici işlenenlerden birini ötekine uyacak şekilde çevirir. Bu çevirmede veri tipleri hiyerarşisine başvurur.

Hoca bunu kalemle ağaç çizerek gösterdi. `1 + 2.5` için kökte `+` işleci, sol işleneni 1, sağ işleneni 2.5'tir. `-3 / 4 + 2.5` için işlem önceliğine dikkat edilir: derleyici soldan sağa işler, ama bölmenin toplamaya göre önceliği vardır. Önce `/` alınır; işlenenleri -3 ve 4'tür. Sonra `+` alınır; sol işleneni bölmenin sonucu, sağ işleneni 2.5'tir.

```text
        +
       / \
      /   2.5
     / \
   -3   4
```

Buradaki eksi aslında ayrı bir işleçtir. Normal çıkarma işleci bölmeden önceliksizdir; ama bu eksi "sayıyı negatife çevir" anlamındaki tekli işleç olduğundan en yüksek önceliğe sahiptir. Sanki önünde bir 0 varmış gibi düşünülebilir.

Hoca çizimin sonucunu şöyle yorumladı: bölme -0.75 verir, sağ tarafta 2.5 vardır; iki ondalıklı sayı toplanır ve sonuç ondalıklı olur. `1 + 2.5`'te ise sol tarafta tam sayı, sağda ondalıklı sayı vardır; `+` işleci veri kaybetmemek için sonucu daha güvenli tür olan ondalıklı sayı olarak hesaplar ve 3.5 bulur.

> **Ders sonrası not:** Hoca `-3 / 4` için -0.75 dedi. Doğrusu, C'de `-3` ve `4` iki tam sayıdır, bu yüzden tam sayı bölmesi yapılır ve sonuç 0'dır (sıfıra doğru kesme). Ardından `0 + 2.5` toplamında 0 `double`'a çevrilir ve sonuç 2.5 olur. gcc ile denendi: `-3/4+2.5` = 2.500000, `-3.0/4+2.5` = 1.750000. Bu örnek, Bölüm 14'teki tam sayı bölmesi tuzağının ta kendisidir.

İfadeler karıştıkça nasıl yorumlanacakları net olmayabilir. Bu yüzden belirsizliğe yol açmamak için doğru parantezlemeyle açık ifadeler yazmakta her zaman yarar vardır.

## 13. İşaretli ve İşaretsiz Türlerin Karıştırılması

İşaretli ve işaretsiz türler aynı kapasitedeki alanlarda saklandıkları için karıştırılabilir; ama sonucun nasıl yorumlanacağı sorundur. -5 ile 10'u toplarken `+` ikisini de işaretli sayı olarak alır, sorun yoktur. Hoca şu kodu yazdı (ekrandan, 01:55:00):

```c
#include <stdio.h>
#define PI 3.1416

int main( )
{
    unsigned int a = 5;
    int b = -11;
    unsigned int c = a+b;
    printf("c=%u\n",c);
    system("PAUSE");
    return;
}
```

İlk denemede `c` işaretli `int` olarak tanımlanmıştı ve $5 + (-11) = -6$ beklendiği gibi -6 yazıldı. Sonra `c` `unsigned int` yapıldı. Hoca, -6 işaretsiz yorumlanınca ikiye tümleyen yüzünden büyük bir pozitif sayı çıkmasını bekledi, ama ekranda yine -6 gördü. Bir öğrenci, değerin işaretsiz olarak saklandığını ama `printf`'te `%d` ile normal `int` gibi yorumlanıp yazdırıldığını söyledi. Biçim `%u` yapılınca büyük bir pozitif sayı göründü: $2^{32} - 6 = 4294967290$ (gcc ile derlenip çalıştırıldı).

Hoca benzer şekilde, işaretsiz bir sayıdan daha büyük bir sayı çıkarılınca sonucun negatif olacağını ve işaretsiz bakıldığında büyük bir sayıya döneceğini söyledi. Sonucu negatif çıkabilecek işlemlerin sonucunu doğru yorumlayabilmek için normal işaretli bir tam sayıya atamak gerekir.

> **Hocanın vurgusu:** Farklı tiplerle çalışırken her tipin ne kadar alan kapladığını bilin; hangi dönüşümlerin güvenli, hangilerinin güvensiz olduğunu bilin. Güvensiz işlemleri en yakın güvenli ortak türde yapın. Yazdığınız kod bir aracın kontrol yazılımıysa bu tür hatalar fiziksel zarara bile yol açabilir. <!-- BELİRSİZ: altyazıda araç adı bozuk ("donumun"), büyük olasılıkla dron -->

Hoca uç durumları tahmin etmeye çalışmanın değerini de vurguladı: tahmin tutmazsa nedenini anlamaya çalışırız; anlayamazsak bilen birine sorarız.

### 13.1 Örtük dönüşümün devamı

`int j;` ve `float f;` tanımlıyken `j + f` işleminde `+` işleci `j`'yi ondalıklıya çevirerek işlem yapar. İfadeye bir de `2.5` eklenirse: elle yazılan ondalıklı sabitler varsayılan olarak `float` değil `double` kabul edilir. `double` daha geniş bir tür olduğundan derleyici güvenli oynar ve her şeyi en güvenli ortak üst türe, `double`'a toplar: `f` de `j` de `double`'a çevrilir ve sonuç `double` olur.

Ama sonuç bir atamayla daha dar bir türe yazılırsa veri kaybı olabilir. `int j = 2.6;` (hatta 2.9) gibi bir atamada ondalık kısım tamamen kaybolur ve `j` 2 olur. Hoca bunu yukarı yuvarlama olup olmadığından emin olmak için 2.6/2.9 ile denedi ve kısmın atıldığını gösterdi (gcc ile `int g = 2.9;` → 2).

Hoca `int`'in aralığını aşan çok büyük bir ondalıklı sabiti (çok sayıda 9'dan oluşan) bir `int`'e atadı. En büyük işaretli `int` değerinin (yaklaşık 2,1 milyar) çıkmasını bekledi. Derleyici bunun güvenli olmadığını bir uyarıyla bildirdi; yine de çalıştırıldığında ekrana başka bir değer çıktı, değişken `unsigned` yapılınca da yaklaşık 3 milyar civarında başka bir sayı. <!-- BELİRSİZ: bu örneğin sabiti ve çıktı değerleri karede okunmadı; altyazıda "727 milyon" ve "3 milyar" geçiyor --> Sabit küçültülüp ondalık kısım içeren makul bir değer yazıldığında ise derleyici uyarı bile vermedi; ondalık kısım atıldı ve `c` 9 olarak görüldü. Hoca bunun nedenini, taban değere yuvarlamanın bazı algoritmalarda bilerek kullanılan bir çalışma biçimi olmasına bağladı.

> **Ek bilgi (derste anlatılmadı):** Kayan noktalı bir değeri, hedef tam sayı türünün aralığına sığmayacak şekilde çevirmek C standardında tanımsız davranıştır. Bu yüzden böyle bir atamanın sonucu (en büyük değere sabitlenme, garip bir sayı vb.) derleyiciye ve işlemciye göre değişir; sonuca güvenilmemelidir.

## 14. Tam Sayı Bölmesi ve Açık Tür Dönüşümü

Bölme gibi işlemlerde özellikle dikkatli olmak gerekir. Hoca şu kodu yazdı (ekrandan, 02:05:00):

```c
#include <stdio.h>
#define PI 3.1416

int main( )
{
    int j=2, k=3;
    float f;
    f = k / j;
    printf("f=%f\n",f);
    system("PAUSE");
    return;
}
```

Hoca önce 2/3'ü kastettiğini, `/` işlecinin solunda ve sağında tam sayı gördüğü için tam sayı bölmesi yapacağını ve sonucun 0 olacağını tahmin etti. Ekranda 1 çıktı; çünkü kodda `k / j`, yani $3/2 = 1.5$ yazıyordu ve tam sayı bölmesi 0.5'i atıp 1 verdi. Sonuç ondalıklı bir değişkene atansa bile bilgi kaybı olur.

Bir öğrenci, `k` ve `j`'ye 3.0 ve 2.0 gibi değerler verilse bile (değişkenler `int` kaldıkça) aynı sonucun çıkacağını söyledi. Hoca bunu doğruladı: değişkenler tam sayı tanımlıysa `/` iki tarafta da tam sayı görür. Ama doğrudan `3.0 / 2` yazıldığında sonuç doğru olarak 1.5 çıktı, çünkü iki taraftan biri ondalıklıdır. Hoca bir önceki slayda dayanarak elle yazılan bu değerlerin `double` kabul edildiğini hatırlattı.

Her şeyi elle yazmak mümkün değildir; değişkenlerin değerlerini çoğu zaman kullanıcı girer ve problem değişkenlerin tam sayı olmasını gerektirebilir. O zaman bölmeyi bilgi kaybetmeden yapmak için açık bir dönüşüm yazılır:

```c
f = (float) k / j;
```

Bu ifade "`k`'yı ondalıklı sayıya çevir, sonra işlemi yap" demektir. Dönüşüm parantez içinde yazılır ve yalnızca hemen sağındaki değeri çevirir; ama işlenenlerden birinin ondalıklı olması bölmenin ondalıklı yapılması için yeter ve sonuç 1.5 olur. Önce `k`'nın kendisi `float` tanımlanarak da denendi; yine 1.5 çıktı. Bazı dillerde ya da standartlarda iki işlenenin de çevrilmesi gerekebileceği için `(float) k / (float) j` de denendi ve 1.5 verdi.

Ama dönüşüm yanlış yere yazılırsa işe yaramaz:

```c
f = (float) (k / j);
```

Burada önce parantez içindeki tam sayı bölmesi yapılır (1), sonra sonuç `float`'a çevrilir; 0.5 yine kaybolur ve sonuç 1.0 olur. gcc ile dört durum denendi: `k / j` → 1.000000, `3.0 / 2` → 1.500000, `(float) k / j` → 1.500000, `(float) k / (float) j` → 1.500000, `(float) (k / j)` → 1.000000.

Parantezle kendimiz açıkça yaptığımız bu dönüşüme açık (explicit) dönüşüm denir; derleyicinin bizim farkında olmadan yaptığı dönüşüm ise örtük (implicit) dönüşümdür.

> **Hocanın vurgusu:** Tam sayı değişkenleri bölerken çok dikkatli olun; doğru sonuç için işlenenlerden en az biri bölmeden önce ondalıklı türe çevrilmelidir.

## 15. enum, void ve typedef

### 15.1 enum

Üçüncü ders saatinde `enum`'un kodda nasıl yazıldığına geçildi. Hoca şu senaryoyu verdi: bir firma, bisiklet de olsa fare de olsa ürettiği ürünleri yalnızca dört renkte üretiyor: kırmızı, mavi, yeşil, sarı. Bunu ifade etmek için `enum` anahtar kelimesi yazılır, küme parantezi içinde değerler sıralanır, parantez kapatılır ve bir ad verilir. Slayt koduyla birlikte yazılan program (ekrandan, 02:30:00):

```c
#include <stdio.h>
#define PI 3.1416

int main( )
{
    enum { red, blue, green, yellow } color;
    enum { bright, medium, dark } intensity;
    color = yellow;      // OK
    color = bright;      // Type conflict
    intensity = bright;  // OK
    intensity = blue;    // Type conflict
    color = 1;           // Type conflict
    color = green + blue;   // Misleading usage

    system("PAUSE");
    return;
}
```

Burada verilen ad (`color`) bir değişken olur; `enum` bir kez tanımlanmış ve başka bir yerde tür olarak kullanılmamıştır. `enum`'a bir ad verip onu tür olarak kullanmak daha esnek kod sağlar; bu, `typedef` ile yapılacaktır.

Fikir şudur: `color` yalnızca `red`, `blue`, `green`, `yellow` değerlerinden birini alabilmelidir; 1, 3, 5 gibi bir sayı ya da başka bir `enum`'un değeri atanamamalıdır. Değerler arka planda 0'dan başlayıp artan tam sayılarla saklanır (`red` 0, `blue` 1, `green` 2, `yellow` 3), ama bu yalnız arka plandaki saklama içindir. Bu yüzden slaytta `color = 1;` tür çatışması, `color = green + blue;` gibi değerler arasında aritmetik ise anlamsız ve yanıltıcı kullanım olarak işaretlenmiştir. İkinci `enum` da üç değerden birini alabilen `intensity` değişkenini tanımlar: `bright`, `medium` ya da `dark`.

Hoca "tür çatışması" yazan satırlarda derleme hatası bekledi, ama derleyici hepsine izin verdi. `color` değeri `%d` ile yazdırılınca 3 çıktı: `green` (2) + `blue` (1) = 3. `%s` ile denendiğinde bir karakter dizisi bekleyen `printf` arka planda işaretçi işlemleri yaptığı için program hiçbir mesaj göstermeden kapandı. `%c` ile ise 3 numaralı ASCII karakteri, konsolda kalp işareti olarak göründü. `intensity` satırları kaldırılıp `medium + dark` gibi ifadeler denendi; yine hata alınmadı. Tanımlar global yapıldığında da durum değişmedi. Hoca bu davranışı beklemediğini ve hatalı bir davranış olarak gördüğünü, ders notlarında da böyle geçtiğini söyledi.

> **Ders sonrası not:** C'de `enum` sabitleri `int` türündedir ve `enum` değişkenleri tam sayılarla serbestçe karışabilir; bu yüzden slayttaki "tür çatışması" satırları C'de derleme hatası değildir (gcc ile denendi, yalnız `-Wall -Wextra` ile farklı `enum` türleri arasındaki atamalarda uyarı verdi; `color = 1;` ve `green + blue` için uyarı bile yok). Bu atamalar C++'ta hatadır; slayttaki işaretler büyük olasılıkla bu katı yorumu ya da iyi programlama alışkanlığını yansıtıyor.

### 15.2 void

`void` veri türünün iki önemli amacı vardır:

- Bir fonksiyonun geriye bir şey döndürmediğini belirtmek. Fonksiyon tanımında dönüş türü atlanamaz; atlanırsa derleme hatası alınır.
- Türden bağımsız, genel amaçlı bir işaretçi tanımlamak. Bu konu daha sonra tartışılacak.

### 15.3 typedef

`typedef`, "type definition" kısaltmasıdır. Bu anahtar kelime veri tiplerine kendi adlarımızı vermemizi sağlar. Örneğin her yerde `long int` yazmak yerine `INT32` yazabilmek için:

```c
typedef long int INT32;
INT32 j;   /* long int j; ile aynı */
```

Sabit tanımlarında olduğu gibi bu adlar da dikkat çeksin diye büyük harfle yazılır. `typedef` bir önişlemci komutu değil, bir dil komutudur; bu yüzden başına `#` konmaz.

Hoca ardından `enum`'lara birer `typedef` adı verdi (ekrandan, 02:40:00):

```c
#include <stdio.h>
#define PI 3.1416
typedef enum { red, blue, green, yellow } COLORS;
typedef enum { bright, medium, dark } INTENSITY;

int main( )
{
    COLORS color = yellow;   // OK
    COLORS color2 = green;   // OK
    color = bright; // Type conflict
    //intensity = bright;   // OK
    //intensity = blue; // Type conflict
    //color = 1;            // Type conflict
    //color = medium + dark;    // Misleading usage
    printf("Color: %d\n", color);
    printf("Color2: %d\n", color2);
    system("PAUSE");
    return;
}
```

Artık `COLORS` bir tür adıdır ve bu türden birden çok değişken tanımlanabilir. `color = bright;` satırı olmadan çalıştırıldığında `color` için 3 (`yellow`), `color2` için 2 (`green`) yazıldı. Hoca `typedef` ile derleyicinin daha katı davranıp `color = bright;` için hata vereceğini düşündü, ama yine hata alınmadı. Bunun yine de bir çatışma olduğunu ve böyle yapılmaması gerektiğini söyledi.

> **Ders sonrası not:** Bu kod gcc ile `-Wall -Wextra` seçenekleriyle derlendi; `color = bright;` satırı için "implicit conversion from 'enum <anonymous>' to 'COLORS'" uyarısı verdi ve program `Color: 0`, `Color2: 2` yazdı (çünkü `bright` 0'dır). Satır kaldırıldığında çıktı derstekiyle aynıdır: 3 ve 2.

**typedef'in avantajı ne?** Hoca bunu sınamak için `typedef`'siz hale döndü. `enum { ... } color;` biçiminde aynı türden ikinci bir değişkeni ayrı bir satırda `color2` diye tanımlamak mümkün değildi; derleyici `color2`'nin bildirilmediğini söyledi. Ama virgül yazımıyla, `enum { red, blue, green, yellow } color, color2;` biçiminde ikinci değişken tanımlanabildi. Yani `typedef` olmadan da aynı türden birkaç değişken tanımlanabiliyor; `typedef` burada yalnız bir kolaylık sağlıyor.

Hoca `typedef`'in asıl avantajını şöyle açıkladı: her zaman tek bir kaynak dosyada çalışılmaz; birkaç `.c` dosyası bir araya getirilir. Aynı `enum`'u başka bir `.c` dosyasında kullanmak gerektiğinde tanımı kopyalayıp yapıştırmak doğru değildir, çünkü değişiklik gerektiğinde her yerde değiştirmek gerekir. Türe bir ad verip o adı kullanmak bu sorunu çözer.

Ders, işleç önceliği ve birleşme özellikleri, `if`/`else`/`else if`, `switch` ve `for`/`while`/`do while` döngülerinin hatırlatılacağı söylenerek bir sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (ekrandan, 01:00:00 ve derste sözlü, 00:58:48): `int sayi = 66000;` değişkeni `%hi` (short) ve `%hu` (unsigned short) ile yazdırılınca neden 464 çıkar?

> **Çözüm:** `short` 2 bayttır ve en fazla $2^{16} = 65536$ farklı değer tutar. 66000 bu sınırı aşar; sayının üst kısmı atılır, yalnız alt 2 bayt yorumlanır: $66000 - 65536 = 464$. Sayı pozitif ve alt 2 baytın en üst biti 0 olduğu için iki biçim de 464 verir. (Derste bir öğrenci $65536 + 464 = 66000$ olduğunu fark etti.)

**Soru 2** (ekrandan, 01:05:00): `int sayi = -66;` değişkeni `%u`, `%hu` ve `%lu` ile yazdırılınca ne çıkar?

> **Çözüm:** -66 ikiye tümleyenle saklanır. 4 baytlık işaretsiz yorumda $2^{32} - 66 = 4294967230$, 2 baytlık işaretsiz yorumda $2^{16} - 66 = 65470$ çıkar. Hocanın derleyicisinde `%lu` da 4294967230 verdi (ekrandaki çıktı).

**Soru 3** (ekrandan, 01:30:00): `float ondalikli = 7000000.555;` değişkeni `%f`, `%.3f`, `%.4f`, `%.5f`, `%lf`, `%e` ile yazdırılınca ne çıkar?

> **Çözüm (derste tam açıklanmadı, gcc ile denendi):** `float` yaklaşık 7 anlamlı basamak tutar ve 7000000 civarında çözünürlüğü 0.5'tir; değer `7000000.5` olarak saklanır. Çıktılar: `7000000.500000`, `7000000.500`, `7000000.5000`, `7000000.50000`, `7000000.500000`, `7.000000e+06` (hocanın Windows derleyicisinde üs `e+006` biçiminde yazılır). Değişken `double` tanımlansaydı 7000000.555 doğru tutulurdu.

**Soru 4** (ekrandan, 01:45:00): `1 + 2.5` ve `-3 / 4 + 2.5` ifadelerinin değeri ve türü nedir?

> **Çözüm (derleyiciyle denendi):** `1 + 2.5`: 1 `double`'a çevrilir, sonuç `double` 3.5'tir. `-3 / 4 + 2.5`: tekli eksi en önce uygulanır, sonra `-3 / 4` tam sayı bölmesi yapılır ve 0 verir; ardından `0 + 2.5` = 2.5 (`double`). Derste bölmenin -0.75 vereceği söylendi; bu ancak `-3.0 / 4` yazılırsa doğrudur ve o zaman sonuç 1.75 olur.

**Soru 5** (ekrandan, 01:55:00): `unsigned int a = 5; int b = -11; unsigned int c = a+b;` ardından `printf("c=%u\n",c);` ne yazdırır?

> **Çözüm:** $5 + (-11) = -6$; işaretsiz 32 bitte bu $2^{32} - 6 = 4294967290$ olarak yorumlanır. Çıktı `c=4294967290` (gcc ile derlenip çalıştırıldı). Aynı değer `%d` ile yazdırılırsa -6 görünür.

**Soru 6** (ekrandan, 02:05:00): `int j=2, k=3; float f;` için `f = k / j;`, `f = (float) k / j;` ve `f = (float) (k / j);` sonrasında `f` kaçtır?

> **Çözüm:** `k / j` tam sayı bölmesidir: 1 → `f=1.000000`. `(float) k / j`: `k` önce 3.0 olur, bölme ondalıklı yapılır → `f=1.500000`. `(float) (k / j)`: önce tam sayı bölmesi (1), sonra çevrim → `f=1.000000`. (Derste gösterildi; gcc ile de denendi.)

**Soru 7** (ekrandan, 02:30:00): `enum { red, blue, green, yellow } color;` ve `enum { bright, medium, dark } intensity;` tanımlarından sonra slaytta "Type conflict" olarak işaretlenen `color = bright;`, `intensity = blue;`, `color = 1;` satırları derlenir mi? `color = green + blue;` sonrasında `color` kaçtır?

> **Çözüm:** C'de `enum` değerleri tam sayıdır, bu satırlar derleme hatası vermez (derste hocanın derleyicisi derledi; gcc yalnız `-Wextra` ile farklı `enum` türleri arasındaki iki atamada uyarı verdi). `green` 2, `blue` 1 olduğu için `color` 3 olur. Yine de bu kullanımlar anlamsız ve yanıltıcıdır, yapılmamalıdır.

## Dersin Toparlaması

Bu derste C'nin önişlemci komutları (`#define`, `#include`) tekrar edildikten sonra veri tiplerinin yapısına girildi: `void`, skaler türler (tam sayı ve kayan noktalı türler, işaretçiler, `enum`) ve birleşik türler. Tam sayı türlerinin boyutları, değer aralıkları ve biçim karakterleri tablo halinde verildi; aynı bellek içeriğinin farklı biçim karakterleriyle nasıl farklı yorumlandığı 65, 66000 ve -66 örnekleriyle canlı olarak gösterildi. Onaltılı ve sekizli sabitler, `float`/`double` farkı, `printf`'te ondalık basamak denetimi ve `float`'ın hassasiyet sınırları denendi.

Dersin ikinci yarısı tür dönüşümlerine ayrıldı: tür hiyerarşisinde aşağıdan yukarıya dönüşümlerin güvenli, tersinin güvensiz olduğu; ifadelerin alt ifadelere bölünüp işlenenlerin en güvenli ortak türe çevrildiği; işaretli ve işaretsiz türlerin karıştırılmasının sonuçları; tam sayı bölmesinin tuzağı ve `(float)` ile açık tür dönüşümünün doğru yeri. Son olarak `enum`'un yazımı, `void`'in iki amacı ve `typedef` ile türlere ad verme görüldü. Bir sonraki derste işleç önceliği ve birleşme özellikleri, karar yapıları (`if`, `else if`, `switch`) ve döngüler (`for`, `while`, `do while`) hatırlatılacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
