# Ders 3 Genişletilmiş Notu: C'de Veri Tipleri, Tip Dönüşümleri, Operatörler ve Kontrol Deyimleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin kapsamı ve önceki dersin hatırlatması
- 2. C'de veri tiplerinin sınıflandırılması
- 3. Tam sayı tipleri, boyutlar ve format belirteçleri
- 4. Format belirteci denemesi
- 5. Sekizlik ve on altılık tam sayı sabitleri
- 6. Ondalıklı sayılar ve ilk değer atama
- 7. Tip karıştırma: işaretsiz aritmetik, örtük ve açık dönüşüm
- 8. enum ve typedef
- 9. İfadeler ve operatör önceliği
- 10. Atama, artırma ve azaltma operatörleri
- 11. Virgül operatörü
- 12. İlişkisel ve mantıksal operatörler
- 13. Bit operatörleri
- 14. cast, sizeof, koşul ve bellek operatörleri
- 15. Kontrol deyimleri: if, switch, döngüler, break
- 16. Ders sonundaki soru-cevaplar
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin kapsamı ve önceki dersin hatırlatması

Bu ders C dilinin ileri düzey yeteneklerine geçmeden önce temelleri hızlıca tekrar eder. Ders notları dersin ana kitabı olan Darnell ve Margolis'in *C: A Software Engineering Approach* (3. baskı, Springer-Verlag, 1996) kitabından hazırlanmıştır (ekrandan, 00:05:00). Slaytta dönemin ders içeriği şöyle sıralanır: veri tipleri, bitsel işlemler, kontrol deyimleri, döngüler ve diziler (hatırlatma); işaretçiler, işaretçi aritmetiği, işaretçi dizileri, karakter dizileri; dinamik bellek yönetimi, fonksiyonlar, fonksiyon işaretçileri, özyineleme; yerel ve global değişkenler, depolayıcı sınıflar, yapılar ve birlikler; dosya işlemleri; C önişlemcileri ve makrolar; statik ve dinamik kütüphaneler.

Önceki derste çeşitli veri türleri ve format dizgileri (format string), `main` fonksiyonunun programın başlangıç noktası olduğu, `#define` ve kod kitaplığı eklemeye yarayan `#include` önişlemci komutları anlatılmıştı. Bu derste kaldığı yerden devam edilir.

## 2. C'de veri tiplerinin sınıflandırılması

C'de veri tipleri üç gruba ayrılır:

- **`void`:** herhangi bir tipi olmayan veri. Hesap sonucu döndürmeyen fonksiyonların tipidir. C'de `void` değişken olmaz. İleride görülecek genel (generic) işaretçilerde de `void` kullanılır.
- **Skaler tipler:** aritmetik tipler (tam sayı ve ondalıklı), işaretçiler ve `enum`.
- **Birleşik tipler:** `struct` ve `union`. Sonraki haftalarda görülecek.

Hoca, tipi baştan yazmayı zorunlu kılan kuvvetli tiplemeyi bazı dillerdeki `var` benzeri tipsiz tanımla karşılaştırdı. Tipsiz dillerde değişken yalnız adıyla tanımlanır ve tipi ona atanan ilk değerden çıkar. Kuvvetli tipleme derleme anında hata yakalama olasılığını artırdığı için genelde tercih edilir. Tipsiz dillerin esnekliği ise disiplinsizlik ve zor yakalanan hatalar gibi yan etkilerle gelir. Hocanın deyişiyle "hiçbir şey bedava değil".

`enum`, yalnız belirli ve sınırlı bir küme içinden değer alabilen tiptir. Hocanın örneği giysi bedenleridir: Small, Medium, Large, Extra Large. "A bedeni" diye bir beden olamaz; bu tür durumlar `enum` ile modellenir.

## 3. Tam sayı tipleri, boyutlar ve format belirteçleri

### 3.1 Skaler tipler için 9 ayrılmış kelime

Slayta göre skaler veri tipleri için 9 ayrılmış kelime vardır (ekrandan, 00:10:00):

- Temel tipler: `char`, `int`, `float`, `double`, `enum`.
- Niteleyiciler (qualifier): `long`, `short`, `signed`, `unsigned`.

Bu beş temel tipin önüne dört niteleyiciden biri konunca anlam değişir. `long` iki kat kapasite, `short` yarı kapasite anlamına gelir (byte cinsinden). `signed` pozitif ya da negatif olabilen, `unsigned` negatif olamayan sayı demektir.

Bir değişken `int j;` biçiminde tanımlanır. Aynı tipte birden fazla değişken tek bildirimde virgülle ayrılarak tanımlanabilir: `int j, k;`. Slaytta altı çizili olarak şu kural da yer alır: bir bloktaki bütün bildirimler çalıştırılabilir komutlardan önce gelmelidir.

> **Ek bilgi (derste anlatılmadı):** "Bildirimler bloğun başında olmalı" kuralı büyük olasılıkla C89/C90 standardına aittir. C99 ve sonrasında bildirim ile komut karışık yazılabilir. Dersin kod örneğinde de görülen `for (int i = 0; ...)` biçimi büyük olasılıkla C99 ve sonrası ister.

`char` bir byte ile gösterilir. Hoca bunun bir sınırlama olduğunu, geniş karakter destekleyen C standartlarının bu konuda daha rahat olduğunu söyledi.

### 3.2 İşaret biti ve değer aralıkları

Pozitif ve negatif ayrımı yapılacaksa en baştaki bit işaret için kullanılır: 0 pozitif, 1 negatif. Bu yüzden aynı bit sayısıyla ulaşılabilen en büyük pozitif değer yarıya iner.

> **Ders sonrası not:** Altyazıda 1 byte'lık örnekteki sayılar bozuk geçiyor ("0 ile 258 eksi bir", "eksi 177, 628", "7 byte"). Doğrusu: 1 byte 8 bittir. İşaretsiz aralık $0$ ile $2^8 - 1 = 255$ arasıdır. İşaretli aralık (iki tümleyen gösterimiyle) $-128$ ile $127$ arasıdır ve işaret biti ayrılınca geriye 7 bit kalır.

Hoca önce `int`'in normalde 2 byte, `long int`'in 4 byte olduğunu söyledi. Slayttaki tabloya gelince "int 4 byte'mış, eskileri kalmış aklımda" diyerek düzeltti. ANSI standardı byte'ın en az 8 bit, tam sayının en az 16 bit olmasını ister; "tam 4 byte olacak" demez. Yaygın platformlarda `int` 4 byte ile gösterilir. 4 byte = 32 bitlik işaretsiz bir tam sayı $0$ ile $2^{32} - 1$ arasında değer alır. İşaretli tam sayıda bir bit işarete ayrılır ve aralık $-2^{31}$ ile $2^{31} - 1$ arasıdır.

> **Hocanın vurgusu:** C alt düzey bir dil olarak güçlüdür ama üstünde çalıştığınız platformun ayrıntılarını çok iyi bilmeniz gerekir.

Değişkenin hiçbir zaman $2^{16}$ gibi bir değere ulaşmayacağı biliniyorsa `short int` kullanılabilir.

### 3.3 Format belirteçleri

`scanf` ile girişte ve `printf` ile çıkışta her tipin kendi format belirteci vardır:

| Tip | Belirteç |
|---|---|
| `int` | `%d` |
| `unsigned int` | `%u` |
| `short int` | `%hi` |
| `long int` | `%li` |
| `unsigned short int` | `%hu` |
| `unsigned long int` | `%lu` |
| `char` | `%c` |
| `float` / `double` | `%f`, `%lf` |
| bilimsel gösterim | `%e` |

`short` için harf `h`, `long` için `l`'dir. Hoca `short` için neden `s` değil de ikinci harf `h`'nin seçildiğini anlayamadığını söyledi. Ayrıca `unsigned short`'ta `h` başa gelirken (`%hu`), `unsigned long`'da `l`'nin de başa geldiğini (`%lu`) belirtti. Ders sırasında bir öğrencinin uyarısıyla bu sıranın ekrandaki kodda yanlış yazıldığı fark edildi (bkz. Bölüm 4).

Karakterler için normalde negatif sayıya gerek yoktur, çünkü ASCII kodu sıfırdan başlar. `char` 1 byte'tır ama içine sayı da saklanabilir. 65 sayısı ASCII'de büyük `A` harfine karşılık gelir. Bu yüzden 65 içeren bir değişken `%c` ile yazdırılınca `A`, `%d` ile yazdırılınca 65 çıkar. Tersine, bir `char` değişkene `'A'` atanıp `%d` ile yazdırılırsa 65 basılır.

Hoca hangi veri türünün kaç byte olduğunun "üç aşağı beş yukarı" akılda kalmasını istedi.

## 4. Format belirteci denemesi

### 4.1 Ortam

Hoca örnekleri Dev-C++ 4 ile yazdı (ekrandan, 00:20:00). Yeni proje penceresinde "Console Application" ve "C project" seçilir. "Make default language" işaretlenirse sonraki projeler de C olarak açılır. Önceki haftalardaki "merhaba dünya" örneğinde konsol penceresinin hemen kapanmaması için bir tuşa basılması beklenmişti. Bunun için `conio.h`'deki `getch()` ya da `stdlib.h`'deki `system("pause")` kullanılır. `stdio.h` ise `printf` ve `scanf` için gereklidir.

Hoca kod PowerPoint'ten IDE'ye kopyalanınca girintilerin kaydığını, girintinin önemini unutmamak gerektiğini söyledi.

### 4.2 Kod

Ekrandaki program (ekrandan, 00:25:00). Ekranda dosya 23 satırdı; aşağıda görünen satırlar verilmiştir. Hocanın sonradan düzelttiği `%lu` satırı ve sonradan eklediği `%.3f` satırı dahil edilmiş, kapanış satırları eklenmiştir. Program `gcc -Wall` ile derlendi ve çalıştırıldı. Derleyici `%li` ve `%lu` satırlarında "long bekleniyor, int verilmiş" uyarısı verir. Bu uyarı da hocanın anlattığı "uygun olmayan format belirteci" sorununun bir örneğidir.

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int sayi = 65;
    float ondalikli = 7000000.555;
    printf("     int \t%d\n",sayi);
    printf(" uns.int \t%u\n",sayi);
    printf(" srt.int \t%hi\n",sayi);
    printf(" lng.int \t%li\n",sayi);
    printf("usrt.int \t%hu\n",sayi);
    printf("ulng.int \t%lu\n",sayi);
    printf("     char\t%c\n",sayi);
    printf("\n");
    printf("     dbl \t%f\n",ondalikli);
    printf("     dbl \t%.3f\n",ondalikli);
    printf(" lng.dbl \t%lf\n",ondalikli);
    printf("     exp \t%e\n",ondalikli);
    return 0;
}
```

Ekrandaki ilk sürümde `uns.char \t%uc` satırı da vardı ve hoca onu yoruma aldı. `%uc` gerçekte `%u` belirteci ile düz bir `c` harfidir; bu yüzden çıktıda "65c" gibi bir şey göründü. Hoca, `unsigned char`'ın nasıl yazdırılacağını sonra araştıracağını söyledi.

> **Ek bilgi (derste anlatılmadı):** Büyük olasılıkla C99'dan beri `unsigned char` sayı olarak `%hhu` ile, karakter olarak ise yine `%c` ile yazdırılır. `char`/`unsigned char` gibi küçük tipler `printf`'e geçirilirken `int`'e yükseltildiği için `%d` ve `%u` da çoğu durumda beklenen sayıyı basar.

### 4.3 Çıktıların yorumu

**`sayi = 65` iken:** `%d`, `%u`, `%hi`, `%li`, `%hu`, `%lu` hepsi 65 basar, çünkü 65 pozitif ve küçük bir sayıdır. `%c` ise büyük `A` basar.

**`sayi = -65` iken:** `%d` ile -65 basıldı. `%u` ile 4,2 milyar civarında bir sayı çıktı. Bunun nedeni, işaretli gösterimde en baştaki işaret bitinin 1 olması ve `%u`'nun bu biti de sayının bir basamağı gibi okumasıdır. gcc ile denendiğinde `-65` değeri `%u` ile 4294967231 basar. `%hu` ile de anlamsız bir değer çıktı (gcc'de alttaki 16 bit okunur ve 65471 çıkar). `%c` ile de 65'e karşılık gelmeyen bir karakter basıldı.

> **Hocanın vurgusu:** Yanlış format belirteci programın hatalı çalışmasına neden olabilir. Programlamada her zaman dikkatli olmak gerekir, alt düzey dillerde daha da çok.

**`ondalikli` için:** `%f` varsayılan olarak noktadan sonra 6 basamak gösterir. `%lf` aynı gösterimi verdi. `%e` sayıyı bilimsel gösterimde, $a \times 10^{x}$ biçiminde basar. `%.3f` noktadan sonra yalnız 3 basamak gösterir. Ekranda `7000000.555` değeri `7000000.500000` olarak göründü (ekrandan, 00:30:00).

> **Ek bilgi (derste anlatılmadı):** `float` büyük olasılıkla (IEEE 754 tek hassasiyet) yaklaşık 7 anlamlı ondalık basamak tutar. 7000000 civarında iki komşu `float` arasındaki fark 0.5 olduğundan `7000000.555` en yakın `float` olan `7000000.5` olarak saklanır. Aynı değer `double` ile tutulsaydı küsurat korunurdu.

**`sayi = 659999` iken (ekrandan, 00:30:00):** `int`, `unsigned int`, `long int` doğru olarak 659999 bastı. `short` (`%hi`) ve `unsigned short` (`%hu`) ise 4639 bastı. Sayı 16 bitlik alana sığmadığı için üst bitler kesilmiş, alttaki 16 bit okunmuştur (ara adım eklendi):

$$659999 = 10 \times 65536 + 4639 \quad\Rightarrow\quad 659999 \bmod 2^{16} = 4639$$

Ekrandaki `%ul` satırı ise sayının sonuna bir `l` harfi ekledi ("659999l"). Bir öğrencinin uyarısıyla hoca, `%u`'nun belirteç olarak okunduğunu ve `l`'nin düz metin olarak basıldığını, doğrusunun `%lu` olduğunu gösterdi. Düzeltilmiş satır 659999 bastı.

> **Ders sonrası not:** Hoca `short` alana sığmama durumunu "buffer overflow" olarak andı. Buradaki olay tam sayı taşması ya da kesilmedir. Tampon taşması (buffer overflow) bir dizinin sınırının dışına yazmak demektir.

## 5. Sekizlik ve on altılık tam sayı sabitleri

Tam sayılar normalde onluk tabanda yazılır, ama 8'lik ve 16'lık tabanda da ifade edilebilir. Sekizlik sabitin başına `0`, on altılık sabitin başına `0x` konur. Slayttaki tablo (ekrandan, 00:35:00):

| Onluk | Sekizlik | On altılık |
|---|---|---|
| 3 | `003` | `0x3` |
| 8 | `010` | `0x8` |
| 15 | `017` | `0xF` |
| 16 | `020` | `0x10` |
| 21 | `025` | `0x15` |
| -87 | `-0127` | `-0x57` |
| 255 | `0377` | `0xFF` |

Hoca birkaç satırı basamak değerleriyle açıkladı. Sekizlik tabanda basamaklar 1'ler, 8'ler, 64'ler basamağıdır. `010` için 1'ler basamağında 0, 8'ler basamağında 1 vardır: $1 \times 8 + 0 = 8$. `017` için $1 \times 8 + 7 = 15$. On altılık tabanda bir basamak 0 ile 15 arasında değer alır. 9'dan sonra rakam olmadığı için 10 yerine `A`, 11 yerine `B`, sonra `C`, `D`, `E`, `F` kullanılır; 15 = `0xF`.

Negatif on altılık sayıda eksi işareti `0x`'in önüne konur: `-0x57`. Doğrulama: $5 \times 16 + 7 = 87$ ve $1 \times 64 + 2 \times 8 + 7 = 87$.

Slayta göre bir tam sayı sabiti `int`'e sığıyorsa `int`, sığmıyorsa `long int` tipindedir. Son ekler: `u` ya da `U` unsigned, `l` ya da `L` long anlamına gelir.

## 6. Ondalıklı sayılar ve ilk değer atama

### 6.1 float ve double

Ondalıklı sayılar için `float` ya da `double` kullanılır. `double` "çift hassasiyet" demektir ve ondalıklı sayının doğru hesaplanma hassasiyetiyle ilgilidir. Bilgisayar ikilik sistem kullandığı için onluk küsuratların ikilikte tam gösterilememesi sorunu vardır. Hoca bunun "Bilgisayar Bilimlerine Giriş" dersinde anlatıldığını hatırlattı. Hassas mühendislik ve bilim hesaplarında `double` ile çalışmak daha doğrudur. Hoca, bu tür hataların milyon dolarlık kayıplara yol açabildiğini, bir taşma hatası yüzünden düşen bir roket olduğunu söyledi.

> **Ders sonrası not:** Hoca olayı "buffer overflow" diye andı. Andığı olay büyük olasılıkla 1996'daki Ariane 5 kazasıdır. Orada 64 bitlik bir ondalıklı değer 16 bitlik işaretli tam sayıya çevrilirken taşma oluşmuştu. Yani olay "buffer overflow" değil, tip dönüşümündeki tam sayı taşmasıdır.

Ondalıklı sayı için genişlik ve hassasiyet verilebilir. Örneğin `%5.2f` gibi bir belirteçte ilk sayı toplam alan genişliğini, nokta sonrası sayı küsurat basamak sayısını belirler. Daha geniş bir sayı verilirse kırpılmaz. Daha kısa sayılar ise hizalı bir tablo görüntüsü için boşlukla doldurulur.

<!-- BELİRSİZ: Slayttaki genişlik/hassasiyet örneğinin tam biçimi (00:36:39 civarı) karelerde görülemedi; altyazıda "beş basamak", "yedi basamak" geçiyor. -->

### 6.2 İlk değer atama

Bir değişken tanımlandığında henüz ilk değeri atanmamıştır. Hoca sayısal tiplerde ilk değerin "normalde" sıfır olduğunu ama buna güvenilemeyeceğini söyledi. `int i;` dendiğinde `i`'ye bellekte hangi göz ayrıldıysa ve orası boşaltılmadıysa, orada rastgele bir sayı olabilir. Bu yüzden algoritmalarda sayaç ya da birikimli toplam (faktöriyel çarpımı gibi) olarak kullanılacak değişkenlere mutlaka uygun ilk değer verilir.

> **Ek bilgi (derste anlatılmadı):** C'de global ve `static` değişkenler büyük olasılıkla bütün uyumlu derleyicilerde otomatik olarak sıfırla başlar. Fonksiyon içindeki yerel (otomatik) değişkenlerin ilk değeri ise belirsizdir. Hocanın "güvenmeyin" uyarısı bu ikinci gruba aittir.

Değişken tanımlandığı anda da değer alabilir: `char ch = 'A';`. Karakter sabitleri tek tırnak içinde yazılır.

### 6.3 Kapsam (scope)

Bir değişken tanımlandığı noktadan itibaren ve tanımlandığı süslü parantez bloğu içinde erişilebilir. Programın başında, önişlemci komutlarından sonra tanımlanan değişkenlere global değişken denir ve bütün kodda kullanılabilir.

## 7. Tip karıştırma: işaretsiz aritmetik, örtük ve açık dönüşüm

### 7.1 Güvenli ve güvensiz dönüşüm

Farklı tipler bir arada kullanılabilir ama dikkat gerekir. Bir tipin kaç bitle saklandığı hatırlanmalıdır. `int`'i `unsigned`'a, `long`'a ya da `float`'a çevirmek güvenlidir. Ondalıklı bir sayıyı `int`'e atamak ise veri kaybına yol açar. Hocanın benzetmesi: küçük kaptaki su büyük kaba sığar, ama büyük kaptaki su küçük kaba aktarılırsa taşar.

### 7.2 Operatörlerin işlenen kuralları

Hoca `-3 / 4 + 2.5` ifadesini örnek verdi. Burada üç operatör vardır: tekli eksi (negatif işaret), bölme ve toplama. Her operatörün işlenen (operand) tipleriyle ilgili kendi kuralı vardır ve bu kurallar standarttan standarda değişebilir. Tekli eksiyi $0 - 3$ gibi, eksik işleneni 0 olan bir çıkarma olarak da düşünebiliriz.

> **Ders sonrası not:** Hoca bu kısımda "bölme işleminin sonucu her zaman ondalıklı sayı olarak yorumlanır; 4/4 bile ondalıklı çıkar" dedi. C'de iki tam sayının bölümü tam sayıdır ve küsurat atılır: `4 / 4 == 1`, `3 / 2 == 1`, `-3 / 4 == 0`. İşlenenlerden biri ondalıklıysa bölme ondalıklı yapılır. Bu nedenle `-3 / 4 + 2.5` ifadesi C'de $0 + 2.5 = 2.5$ verir.

### 7.3 İşaretsiz aritmetik denemesi

Slaytta "10u - 15 ne çıkar?" türünden bir soru vardı. İşaretsiz bir değerden ondan büyük bir sayı çıkarılınca sonucun -5 mi yoksa "kırık" bir sayı mı olacağı sorulur. Hoca bunu yeni bir projede denedi (Bölüm Örnek Sorular, soru 1). `unsigned` bir `i`'ye 10 verip `i - 15` hesapladı ve yazdırdı. `%d` ile -5 göründü. `%u` ile 4294967291 göründü.

Hoca sonucun iki etkene bağlı olduğunu vurguladı: kullanılan format belirteci ve sonucun atandığı değişkenin tipi.

### 7.4 Örtük dönüşüm

Derleyicinin ek bir komut olmadan kendiliğinden yaptığı dönüşümlere slaytta "invisible conversions" denir (ekrandan, 00:50:00):

```c
int j;
float f;
j + f;          // j is converted to float
j + f + 2.5;    // j and f both converted to double
```

Hoca burada "geniş kap" fikrini kullandı. `int` daha dar, `float` daha geniş kaptır; sonuç geniş kapta olmak zorundadır. `j` 3 ise 3.0 olarak ele alınır. `2.5` sabiti double olduğu için üç terimli ifade en geniş kap olan double'da hesaplanır.

**Soru:** Ondalıklı bir sabit varsayılan olarak double sayılmıyor mu? **Cevap:** Hoca derleyicinin 2.5 sabitini float mı double mı saydığını o an hatırlamadığını söyledi. Bunun için kullanılan derleyicinin belgelerine bakmak gerektiğini ekledi. Alt düzey dillerle çalışırken biraz "paranoyak" ya da şüpheci olmanın doğal olduğunu söyledi.

> **Ders sonrası not:** Hoca bunu hatırlamadığını söyledi. C standardında son eki olmayan `2.5` gibi ondalıklı sabitler büyük olasılıkla bütün uyumlu derleyicilerde `double` tipindedir (standart böyle tanımlar). `float` sabit için `2.5f`, `long double` için `2.5L` yazılır. Slayttaki "j and f both converted to double" yorumu da bununla uyumludur.

Slaytta "Loss of precision" başlığı altında iki örnek vardır (ekrandan, 00:50:00):

```c
j = 2.5;                  // j's value is 2
j = 999999999999.888888;  // overflow
```

İlk atamada küsurat atılır; 2.1 de 2.9 da olsa yalnız 2 saklanır. Bu davranış bazen işe yarar, işe yaramıyorsa `j` float olarak tanımlanmalıdır. İkinci atamada önce küsurat atılır. Sonra sayı `int`'in bit sayısına sığmadığından taşma olur. Hocaya göre ikili gösterimde sağdan, en düşük anlamlı bitten itibaren `int`'in bit sayısı kadar bit sayılır, ötesi kesilir ve kalan bitlerin onluk karşılığı sonuç olur.

> **Ders sonrası not:** Hoca sonucun alttaki bitlerden oluşacağını söyledi. C standardına göre ondalıklı bir değerin tam sayı kısmı hedef tipe sığmıyorsa davranış büyük olasılıkla tanımsızdır (undefined behavior); yani sonucun "alttaki bitler" olacağı garanti değildir ve derleyiciden derleyiciye değişebilir.

### 7.5 Açık dönüşüm (cast)

Dilin davranışından emin olunmadığında ya da kodun her platformda aynı çalışması istendiğinde dönüşüm programcı tarafından açıkça yazılabilir. Buna açık dönüşüm (explicit conversion) ya da tip dönüştürme (type casting) denir. Slayttaki örnek (ekrandan, 01:05:00):

```c
int j=2, k=3;
float f;
f = k / j;
f = (float) k / j;
```

Bir ifadeyi dönüştürmek için hedef tip parantez içinde ifadenin hemen önüne yazılır. Hoca burada da şüpheci davrandı: `(float) k / j` yalnız `k`'yi mi, yoksa `k / j` işlemini mi float'a çeviriyor? Emin olmak için ifade ayrıca parantezlenebilir.

> **Ders sonrası not:** Hoca burada emin olmadığını söyledi. Dersin kendi öncelik tablosunda (Bölüm 9.3) cast tekli bir operatördür ve bölmeden önce gelir. Bu yüzden `(float) k / j` önce `k`'yi 3.0 yapar, sonra bölme ondalıklı yapılır ve sonuç 1.5 olur. `(float)(k / j)` yazılsaydı önce tam sayı bölmesi yapılır (1), sonra 1.0'a çevrilirdi. gcc ile denendi: `f = k / j` → 1.000000, `f = (float) k / j` → 1.500000.

## 8. enum ve typedef

### 8.1 enum

`enum` adlandırılmış sabitler tanımlar. Kullanılan standart izin veriyorsa, sabitleri tam sayılarla ifade etmek yerine `enum` kullanmak daha yararlıdır. Örneğin bir sistemde yalnız dört renk ve üç yoğunluk varsa ve başka değer alınmaması isteniyorsa iki `enum` tanımlanır. Slayttaki örnek (ekrandan, 01:10:00):

```c
enum { red, blue, green, yellow } color;
enum { bright, medium, dark } intensity;

color = yellow;          // OK
color = bright;          // Type conflict
intensity = bright;      // OK
intensity = blue;        // Type conflict
color = 1;               // Type conflict
color = green + blue;    // Misleading usage
```

Hoca burada bir düzeltme yaptı: bu tanımlar adsız (anonim) `enum`'lardır; `color` ve `intensity` tip adı değil, bu tiplerden tanımlanmış değişkenlerdir. `enum`'a ad vermek için `typedef` gibi araçlar gerekebilir. `color` yalnız ilk kümedeki dört değerden birini alabilir. `color = yellow` geçerlidir. `color = bright` ise ikinci kümenin değeri olduğundan tip çatışmasıdır. Hoca bunu bir tür tip güvenliği (type safety) olarak tanımladı.

Slayta göre varsayılan değerler sıfırdan başlar ve her yeni adla birer artar; istenirse başka değerler verilebilir.

Bunun yerine `#define RED 1`, `#define BLUE 2`, ... ve `#define BRIGHT 1`, `#define MEDIUM 2`, ... gibi sabitler tanımlansaydı, `RED` ile `BRIGHT` aynı değeri (1) taşıdığından `color`'a `BRIGHT` atanabilirdi. Mantıken `RED` atanmış olurdu ve bu, programın denetim akışında istenmeyen mantık hatalarına yol açabilirdi. `color = green + blue` gibi bir ifade de `enum` değerleri aritmetik işleme sokulacak şeyler olmadığı için mantıksızdır; arka planda sayısal değerleri olsa da anlam taşımaz.

> **Ders sonrası not:** C'de `enum` sabitleri `int` tipindedir. `gcc -Wall` ile denendiğinde `color = bright;` ve `intensity = blue;` atamaları hatasız ve uyarısız derlendi. Slayttaki "Type conflict" etiketleri büyük olasılıkla C++ derleyicileri ya da ek denetim araçları için geçerlidir. C'de `enum` tip güvenliğini derleyici zorlamaz; anlam ve okunabilirlik kazancı ise geçerlidir.

### 8.2 void hakkında ek not

Hoca `void` için unuttuğu bir kullanımı ekledi: genel (generic) işaretçiler de `void` ile tanımlanır. Ayrıntısı işaretçiler konusunda görülecek.

### 8.3 typedef

`typedef` programcının kendi tip adlarını tanımlamasını sağlar. Daha çok `struct` ve `union` ile kullanılacaktır. Slayttaki örnek (ekrandan, 01:15:00):

```c
typedef long int INT32;

long int j;
INT32 j;
```

Kod içinde her yerde `long int` yazmak istemeyen bir programcı ona `INT32` adını verebilir. `typedef`'ten sonra istenen C tipi yazılır; bu tip `long int` gibi iki, `unsigned long int` gibi üç kelimeden oluşabilir. En sondaki boşluksuz tek kelime yeni addır. Bundan sonra `long int j;` ile `INT32 j;` eş anlamlıdır. Gelenek olarak `typedef` adları büyük harfle yazılır; böylece bunun dilin standart bir tipi değil, programcının tanımladığı bir ad olduğu anlaşılır.

## 9. İfadeler ve operatör önceliği

### 9.1 İfade türleri

Dersin ikinci bölümü (slaytta "Structured Programming, Part 2") ifadeleri, kontrol akışını, karar verme yapılarını, `switch-case`'i, döngüleri ve operatör önceliğini hatırlatır. Slayttaki ifade türleri (ekrandan, 01:20:00):

- **Sabit ifadeler:** `5`, `5 + 6 * 13 / 3.0`.
- **Tam sayı ifadeleri (`int j, k`):** `j`, `j / k * 3`, `k - 'a'`, `3 + (int) 5.0`.
- **Ondalıklı ifadeler (`double x, y`):** `x / y * 5`, `3 + (float) 4`.
- **İşaretçi ifadeleri (`int *p`):** `p`, `p + 1`, `"abc"`.

Aritmetik işlemlerde ifade soldan sağa okunur. Önce çarpma ve bölme (hangisi daha soldaysa), sonra toplama ve çıkarma yapılır. `5 + 6 * 13` ifadesinde önce çarpma yapılır. 5 ile 6 önce toplanacaksa parantez gerekir.

`3 + (float) 4` açık dönüşüm örneğidir: 4 float'a çevrilip 3 ile toplanır, sonuç daha geniş kap olan float'ta saklanır. Bu sonuç `%d` ile yazdırılırsa ya da bir `int`'e atanırsa veri kaybı olmaz, çünkü değer 7'dir ve küsuratı yoktur.

> **Ders sonrası not:** Hoca `j / k * 3` için "j ve k int olsa da sonuç aslında ondalıklı çıkacaktır" dedi. C'de `j / k` tam sayı bölmesidir, sonuç tam sayıdır. Slaytta da bu ifade "Integral expressions" başlığı altındadır.

İşaretçi ifadeleri sonraki derslerde görülecek. Dizgi (string) ifadeleri çift tırnakla, karakterler tek tırnakla yazılır.

### 9.2 Aynı öncelikteki operatörler ve yan etkiler

Aynı önceliğe sahip operatörler peş peşe gelince beklenmedik yan etkiler olabilir. Hoca `a = b = c` ifadesini örnek verdi. İki operatör de atamadır. Hoca ifadeyi önce `b = c` atamasının yapılması, sonra bu atama ifadesinin sonucunun `a`'ya atanması olarak açıkladı. Asıl soru şudur: bir atama ifadesinin sonucu nedir? Atama yapıldıysa doğru mu, değilse sıfır mı? Hocaya göre bu tür karmaşık yazımlar hataya götürür.

> **Ders sonrası not:** Hoca ifadeyi önce "soldan sağa" diye açıkladı ve atama ifadesinin değerinin ne olduğunu açık bıraktı. Atama operatörü büyük olasılıkla bütün C derleyicilerinde sağdan sola birleşir: `a = b = c` ifadesi `a = (b = c)` olarak değerlendirilir. Bir atama ifadesinin değeri, atamadan sonra sol taraftaki değişkenin aldığı değerdir; doğru/yanlış değildir. Sonuçta hem `b` hem `a` `c`'nin değerini alır.

> **Hocanın vurgusu:** Bir ifadenin davranışı işinize yarasa bile onu bu şekilde yazmayın. Birkaç komuta bölün; böylece kod daha anlaşılır olur ve farklı sistemlerde aynı biçimde çalışma olasılığı artar.

Hoca bir örnek daha verdi: `a < b < c`. İlişkisel operatörler doğru ya da yanlış döndürür. Derleyici doğruyu 1, yanlışı 0 olarak tutuyorsa `b < c` doğruysa ifade `a < 1` sorgusuna dönüşür. Yani bu ifade "a, b'den küçük ve b, c'den küçük mü?" sorusu için kullanılamaz.

> **Ders sonrası not:** `<` soldan sağa birleştiği için (Bölüm 9.3'teki tablo) `a < b < c` aslında `(a < b) < c` olarak değerlendirilir: önce `a < b` sonucu (0 ya da 1) bulunur, sonra bu sonuç `c` ile karşılaştırılır. Hocanın sözlü örneğindeki sıra (önce `b < c`) yanlış olsa da vardığı sonuç aynıdır: ifade amaçlanan sınamayı yapmaz.

Doğrusu `if (a < b && b < c)` biçiminde yazmaktır.

### 9.3 Öncelik tablosu

Slayttaki öncelik ve birleşme yönü tablosu (ekrandan, 01:25:00), yüksekten düşüğe:

| Sınıf | Operatörler | Birleşme |
|---|---|---|
| birincil (primary) | `()` `[]` `->` `.` | soldan sağa |
| tekli (unary) | cast, `sizeof`, `&` (adres), `*` (içerik), `-` `+`, `~` `++` `--` `!` | sağdan sola |
| çarpımsal | `*` `/` `%` | soldan sağa |
| toplamsal | `+` `-` | soldan sağa |
| kaydırma | `<<` `>>` | soldan sağa |
| ilişkisel | `<` `<=` `>` `>=` | soldan sağa |
| eşitlik | `==` `!=` | soldan sağa |

Hoca tabloyu kısaca yorumladı:

- Normal parantez her şeyin önüne geçer.
- Köşeli parantez dizi işlemidir: `a[i]` dendiğinde önce dizinin `i`. elemanı getirilir, diğer işlemler ondan sonra yapılır.
- `->` ve `.` yapılarda (struct) kullanılır: biri yapıya işaretçi üzerinden, diğeri yapının kendisi üzerinden erişir. Hoca bunu bir öğrencinin hatırlatmasıyla tamamladı.
- Tekli operatörler arasında cast, `sizeof` (bir ifadenin kaç byte ile gösterileceğini döndürür), adres ve içerik operatörleri vardır. Buradaki `*` çarpma değil, işaretçinin gösterdiği değerdir.
- Sonra çarpımsal (`*`, `/`, `%`) ve toplamsal operatörler gelir.
- Kaydırma operatörlerinin önceliği daha düşüktür. `a << 1` sayının ikili gösterimini bir bit sola kaydırır; sağa eklenen bit 0'dır.
- İlişkisel ve eşitlik operatörleri en altta yer alır.

Tablonun ikinci kısmında bit düzeyinde VE, XOR, VEYA, mantıksal VE ve VEYA, koşul operatörü (`?:`), atama operatörleri ve en sonda virgül operatörü yer alır. Bunların öncelikleri daha düşüktür. Hoca koşul operatörünün bir `if-else`'i tek satırda yazmaya yaradığını, kendisinin bu ifadeye pek hayran olmadığını söyledi.

> **Hocanın vurgusu:** Öncelik sırasına dayanan karmaşık bir ifade yazmak yerine onu birbirini izleyen birkaç ayrı ifadeye bölün.

### 9.4 Parantez örnekleri

`(2 - 3) * 4` ifadesinde parantez önce işlenir: $2 - 3 = -1$, sonra $-1 \times 4 = -4$. Parantez olmasaydı sanki çarpma parantezlenmiş gibi önce çarpma yapılırdı: $2 - 3 \times 4 = 2 - 12 = -10$ (ara adım eklendi).

İç içe parantezlerde en içteki parantez önce işlenir. Hocanın örneği:

$$1 + (((3 + 1) / (8 - 4)) - 5)$$

- En içte `(3 + 1)` ve `(8 - 4)` vardır; soldan sağa işlenir: $3 + 1 = 4$, $8 - 4 = 4$.
- Bir üst düzeyde $4 / 4 = 1$.
- Sonra $1 - 5 = -4$.
- En sonda $1 + (-4) = -3$.

Sonuç $-3$'tür (gcc ile doğrulandı).

## 10. Atama, artırma ve azaltma operatörleri

### 10.1 Aritmetik atama operatörleri

Slayttaki tablo (ekrandan, 01:30:00):

| Operatör | Simge | Biçim | İşlem |
|---|---|---|---|
| atama | `=` | `a = b` | `b`'nin değerini `a`'ya koy |
| topla-ata | `+=` | `a += b` | `a+b`'yi `a`'ya koy |
| çıkar-ata | `-=` | `a -= b` | `a-b`'yi `a`'ya koy |
| çarp-ata | `*=` | `a *= b` | `a*b`'yi `a`'ya koy |
| böl-ata | `/=` | `a /= b` | `a/b`'yi `a`'ya koy |
| kalan-ata | `%=` | `a %= b` | `a%b`'yi `a`'ya koy |

Bu ifadelerin sonucunu doğru tahmin etmek için her operatörün ne tür işlenen beklediğini bilmek gerekir.

### 10.2 Bileşik atama örnekleri

`m += n + x - y` ifadesi `m = m + ((n + x) - y)` olarak değerlendirilir. `+` ve `-` aynı önceliğe sahiptir ve soldan sağa işlenir: önce `n + x`, sonra sonuçtan `y` çıkarılır. Sonra bu `m` ile toplanır ve sonuç `m`'nin üzerine yazılır.

Hoca `x += y -= m` ifadesini "lütfen böyle ifadeler kullanmayın" diyerek gösterdi. Değerlendirme şöyledir: önce `y -= m` yapılır, yani `y`'den `m` çıkarılıp sonuç `y`'ye atanır. Sonra bu sonuç `x` ile toplanıp `x`'e atanır. Yalnız matematiksel sonuçla ilgilenilirse `y - m` yazmaktan farkı yoktur. Ama `-=` kullanıldığı için `y`'nin değeri de değişmiş olur.

### 10.3 Artırma ve azaltma

`a++`, `a = a + 1` demektir. Operatörün değişkenin önünde ya da arkasında olması farklıdır:

- `i = a++;` önce `a`'nın değeri `i`'ye atanır, sonra `a` bir artırılır (son ek, postfix).
- `i = ++a;` önce `a` bir artırılır, sonra yeni değer `i`'ye atanır (ön ek, prefix).
- Aynı kural `--` için de geçerlidir.

Slayttaki örnek (ekrandan, 01:35:00). Aşağıdaki iki program birleştirilmiş, `#include <stdio.h>` ve `int` dönüş tipi eklenmiş biçimde `gcc -Wall` ile derlendi ve çalıştırıldı:

```c
main () {
    int j=5, k=5;
    printf("j: %d\t k : %d\n", j++, k--);
    printf("j: %d\t k : %d\n", j, k);
    return 0;
}
```

```c
main () {
    int j=5, k=5;
    printf("j: %d\t k : %d\n", ++j, --k);
    printf("j: %d\t k : %d\n", j, k);
    return 0;
}
```

Son ek sürümde ilk `printf` `j`'nin ve `k`'nin o anki değerlerini (5 ve 5) basar, ardından `j` 6'ya çıkar, `k` 4'e iner. İkinci satır 6 ve 4 basar. Ön ek sürümde değerler basılmadan önce değişir: ilk satır 6 ve 4 basar, ikinci satır da 6 ve 4.

```text
Postfix:            Prefix:
j: 5     k : 5      j: 6     k : 4
j: 6     k : 4      j: 6     k : 4
```

### 10.4 Kaçınılması gereken ifadeler

Hoca `m++ - --c` gibi ifadeleri örnek verdi. Değerlendirme: önce `c` bir azaltılır ve azalmış değeri kullanılır, `m`'nin artmadan önceki değerinden bu çıkarılır, `m` sonra artırılır. Hoca önce "m'nin artmış hali" dedi, sonra bir öğrencinin uyarısıyla `m`'nin o anki değerinin kullanıldığını kabul etti. Ayrıca okuyan için "burada eksi tuşuna yanlışlıkla mı basıldı?" sorusu doğar; bu tür ifadeler mantık hatası üretmeye adaydır.

`m += ++c * 2` gibi bir ifadede ise hangisinin önce yapılacağını bilmek için öncelik tablosuna bakmak gerekir.

Slayttaki üçüncü ifadenin sonucu her zaman belli değildir; farklı C standartlarında ve derleyicilerde farklı çıkabilir.

<!-- BELİRSİZ: Slayttaki üçüncü "tanımsız/derleyiciye bağlı" ifadenin metni karelerde görülemedi. -->

> **Hocanın vurgusu:** Böyle karmaşık ifadeler yerine birkaç alt komut yazın; kod derleyiciye bağlı (implementation dependent) olmasın. Hoca bunun sınavda sorulabileceğini ama sorulursa çok büyük ağırlık verilmeyeceğini söyledi.

## 11. Virgül operatörü

Virgül operatörü tek bir ifadenin beklendiği yerde iki ya da daha fazla ifadenin değerlendirilmesini sağlar. En çok `for` döngülerinde işe yarar (ekrandan, 01:40:00):

```c
for (j = 0, k = 100; k - j > 0; j++, k--)
```

Slayta göre virgül ifadesinin sonucu en sağdaki işlenenin değeridir.

Hoca `for` döngüsünün yapısını hatırlattı. Parantez içinde noktalı virgülle ayrılan üç ifade vardır:

- **Başlangıç ifadesi:** döngüye girmeden önce bir kez işlenir.
- **Devam ifadesi:** her iterasyondan önce bakılır; doğruysa gövde bir kez daha yürütülür.
- **Son ifade:** her iterasyonun sonunda otomatik olarak yürütülür; genelde sayaç artırma ya da azaltma burada yapılır.

Virgül sayesinde başlangıç ve son ifadeye birden fazla komut yazılabilir. Örnekte başlangıçta `j` sıfır, `k` 100 yapılır; her iterasyonda `j` bir artar, `k` bir azalır. Aynı sonuç virgül kullanmadan da elde edilir: `k = 100` döngüden önce yazılır, `k--` gövdenin sonuna konur.

## 12. İlişkisel ve mantıksal operatörler

### 12.1 İlişkisel sonucun sayısal değeri

`>`, `<`, `==`, `!=` gibi ilişkisel operatörlerin doğru ve yanlış sonuçlarının arka planda sayısal karşılıkları vardır. `a > b` ifadesi `a` gerçekten `b`'den büyükse 1, değilse 0 değerini alır. `a == b` ise `a > b` yanlıştır ve sonuç 0'dır. Bu sonuç bir tam sayıya atanabilir; derleyici en fazla uyarı verebilir.

> **Hocanın vurgusu:** Mantıksal ve sayısal ifadeleri birbirine karıştırmanın anlamı yok. Mantıksal işlemler mantıksal, sayısal işlemler sayısal olarak ayrı yapılmalı.

Slaytta bazı değişken tanımlarıyla birlikte `c <= m >= n` gibi ifadelerin nasıl parantezlendiği ve sonuçları verildi. Hoca bu ifadeyi açıkladı: `<=` ve `>=` aynı önceliğe sahiptir ve soldan sağa değerlendirilir. Önce `c <= m` sonucu (0 ya da 1) bulunur, sonra bu sonucun `n`'den büyük ya da eşit olup olmadığına bakılır. Slayttaki değerlerle sonuç 1 çıkıyordu.

<!-- BELİRSİZ: Slayttaki değişken ilk değerleri ve ifade listesi (01:41:40 civarı) karelerde görülemedi. -->

### 12.2 Sıfır olmayan değerler

Mantıksal işlemlerde 0 ve 0.0 yanlış sayılır. Slaytta "non-zero values are interpreted as false" yazıyordu. Hoca bunun önceki slaytla (doğru = 1) çeliştiğini fark etti; öğrenciler de slaydın yanlış olduğunu söyledi. Hoca bunu canlı olarak denedi. Önce `c` (0) ile `m` (1) için mantıksal VE sonucunun 0 olduğunu gösterdi. Sonra negatif sayıların nasıl yorumlandığını görmek için `n = -1` ile `printf("%d\n", j || n);` yazdı (`j` 0). Çıktı 1 oldu: negatif sayılar da doğru sayılıyor. Hoca slaydı "All non-zero values are interpreted as true, to include negative values" olarak düzeltti.

## 13. Bit operatörleri

### 13.1 & ile && farkı

`&&` mantıksal VE'dir. Tek `&` ise iki tam sayıyı bitlerine ayırır ve aynı anlamlı basamaktaki bitleri tek tek VE işlemine sokar. Slaytta bu fark verilmediği için hoca Excel'de gösterdi (ekrandan, 01:50:00).

- `a = 9`: ikilik `1001` ($8 + 1 = 9$).
- `b = 5`: ikilik `0101` ($4 + 1 = 5$).
- `a && b`: iki değer de sıfır olmadığı için doğru sayılır; sonuç doğrudur (sayısal olarak 1).
- `a & b`: her basamak ayrı VE'lenir; yalnız 1 ve 1 1 verir. `1001 & 0101 = 0001` = 1.

Hoca sayıları öyle seçtiği için iki sonucun da 1 çıktığını fark etti ve `b`'yi 6 (`0110`) yaptı:

- `a & b`: `1001 & 0110 = 0000` = 0.
- `a && b`: yine 1.

Yani `9 & 6 = 0`, `9 && 6 = 1` (gcc ile doğrulandı).

### 13.2 Kaydırma

Slayttaki tablo (ekrandan, 01:55:00), 16 bitlik gösterimle:

| İfade | Sol işlenenin ikilik gösterimi | Sonucun ikilik gösterimi | Sonuç |
|---|---|---|---|
| `5 << 1` | `00000000 00000101` | `00000000 00001010` | 10 |
| `255 >> 3` | `00000000 11111111` | `00000000 00011111` | 31 |
| `8 << 10` | `00000000 00001000` | `00100000 00000000` | $2^{13}$ |
| `1 << 15` | `00000000 00000001` | `10000000 00000000` | $-2^{15}$ |

`5 << 1`: bütün bitler bir basamak sola gider, en soldaki bit "uçurumdan düşer", sağdan 0 gelir. `101` → `1010` = 10. `255 >> 3`: her basamak üç kez sağa kayar, sağdaki üç tane 1 düşer, soldan 0'lar gelir. Sekiz tane 1 beşe iner: `11111` = 31. `8 << 10`: $8 = 2^3$, on bit sola kayınca $2^{13}$ olur. `1 << 15`: 1 işaret bitine kadar gider; 16 bitlik işaretli gösterimde bu $-2^{15}$'tir.

Slaytın ikinci kısmı `-5 >> 2` içindir. Hoca negatif sayıların gösterimini hatırlamadığını, "beşi yazıp işaret bitini 1 yapmak" kadar basit olmadığını söyledi ve satırlardan birinde yazım hatası olduğunu belirtti.

> **Ders sonrası not:** 16 bitlik iki tümleyen gösteriminde $-5$ = `11111111 11111011` olur. gcc'de işaretli bir sayıyı sağa kaydırmak işaret bitini çoğaltır (aritmetik kaydırma): `-5 >> 2` = `11111111 11111110` = $-2$. Aynı bit dizisi işaretsiz olarak kaydırılırsa (mantıksal kaydırma) `00111111 11111110` = 16382 = $2^{14} - 2$ çıkar (gcc ile denendi). Slayttaki "$2^{13} - 1$" değeri bu bit dizisiyle uyuşmuyor. İkinci satırdaki sol işlenen (`11111111 11111111`) de $-5$ değil $-1$'dir. Negatif bir işaretli sayının sağa kaydırılmasının sonucu C standardında derleyiciye bırakılmıştır.

Slaytlarda ayrıca bir onluk sayının ikilik ve on altılık karşılıklarını gösteren bir tablo ve bit düzeyinde VE/VEYA'nın hizalanmış ikilik tablosu vardı. Hoca bunların bilimsel hesap makinesiyle kolayca bulunabileceğini söyleyip ayrıntıya girmedi.

<!-- BELİRSİZ: Bit düzeyinde VE/VEYA tablosundaki sayılar (altyazıda "9430" ve "5722" gibi geçiyor) karelerde görülemedi. -->

XOR (`^`) ve NOT (`~`) işlemleri de aynı şekilde bit bit yapılır. `+=` gibi `<<=`, `>>=`, `&=`, `|=` kısaltmaları da vardır.

### 13.3 Kaydırma ile çarpma ve bölme

Kaydırma 2'nin kuvvetleriyle çarpma ya da bölme anlamına da gelir. Bir bit sola kaydırmak 2 ile, iki bit sola kaydırmak $2^2 = 4$ ile çarpmaktır. Sağa kaydırma bölmedir: üç bit sağa kaydırmak 8'e bölmek gibidir. Ama tek sayılarda ve basamak kayıplarında onluk anlamda tam bölme değildir. Hocaya göre sola kaydırma çarpma için güvenlidir, sağa kaydırma tam bölme yapmaz.

> **Ders sonrası not:** Hoca 01:57:15'te "5'i 1 bit sağa ötelediğinizde 2 ile çarpmış olursunuz" dedi; doğrusu sola kaydırmadır. Cümlenin devamında kendisi de sola kaydırmayı çarpma, sağa kaydırmayı bölme olarak anlattı. Ayrıca sola kaydırma da bit sayısı aşılırsa taşar; `1 << 15` örneğinde olduğu gibi işaret bitine ulaşan değer negatif görünür.

## 14. cast, sizeof, koşul ve bellek operatörleri

### 14.1 cast

Cast bir değeri başka bir tipe çevirir. Büyük kaptan küçük kaba dönüşümde veri kaybı olabilir, küçükten büyüğe dönüşümde olmaz. Slayttaki örnek (ekrandan, 02:10:00): `3 / 2` ve `(float) 3 / 2`. Hocanın açıklamasına göre bir derleyici iki tam sayının bölümü olan 1.5'i 1'e kırpıp float değişkene 1.0 olarak atayabilir. Kodun taşınabilirliği önemliyse işlemden önce float'a açık dönüşüm yapmak "sağlama almak" demektir. Bazı platformlarda gereksiz olabilir ama bazılarında gerekebilir.

### 14.2 sizeof

`sizeof` bir değerin bellekte kaç byte yer kapladığını döndürür. Slayta göre `sizeof` iki tür işlenen alır: bir ifade ya da bir veri tipi. İfadenin tipi fonksiyon ya da `void` olamaz, bit alanı (bit field) da olamaz. Slayttaki örnekler: `sizeof(3+5)` int'in boyutunu döndürür; `sizeof(short)`.

> **Ders sonrası not:** Hoca `sizeof(3+5)` için şunu anlattı: "8 ikilikte 3 bittir; 3 biti alabilecek en dar kap `short`'tur, o da 1 byte'tır." Doğrusu slayttaki gibidir: `3+5` bir `int` ifadesidir ve `sizeof(3+5) == sizeof(int)` olur. Değerin kaç bitle yazılabildiğine bakılmaz. gcc/x86-64'te `sizeof(3+5)` 4, `sizeof(short)` 2'dir (gcc ile denendi). `short` genelde 1 değil 2 byte'tır.

### 14.3 Koşul operatörü

Hoca koşul operatörüne pek sıcak bakmadığını ama kullanılabileceğini söyledi. Slayt (ekrandan, 02:15:00): `a ? b : c` biçimindedir; `a` sıfırdan farklıysa sonuç `b`, değilse `c`'dir. C'deki tek üçlü (ternary) operatördür ve yaygın bir `if-else` dalının kısaltmasıdır:

```c
z = ((x < y) ? x : y);
```

```c
if (x < y)
    z = x;
else
    z = y;
```

Soru işaretinin solundaki ifade mantıksal olarak değerlendirilir. Doğruysa iki noktayla ayrılan ifadelerden soldaki, yanlışsa sağdaki seçilir ve bütün ifadenin değeri olur; bu değer `z`'ye atanır. Hoca her zaman `if-else` biçimini tercih ettiğini söyledi.

### 14.4 Bellek operatörleri

`int a;` dendiğinde bellekte bu değişkene bir yer ayrılır ve atanan değer oraya yazılır. Değişkenin adresini almak için başına `&` konur. `a` bir işaretçiyse `*a`, işaretçinin gösterdiği adresteki değeri kullan demektir. Yapılar için de doğrudan erişim ve işaretçi üzerinden erişim olmak üzere iki gösterim vardır. Ayrıntılar işaretçiler konusunda görülecek.

## 15. Kontrol deyimleri: if, switch, döngüler, break

### 15.1 if, else if, else

`if`'ten sonra parantez içinde mantıksal bir ifade gelir. Ardından tek bir komut ya da süslü parantez içinde birden fazla komut yazılır. İsteğe bağlı olarak istenildiği kadar `else if` ve en sonda, önceki bütün koşullar yanlışsa çalışacak bir `else` eklenebilir. `else if`'ler ve `else` tamamen seçimliktir.

Süslü parantez yoksa `if` yalnız bir sonraki tek komutu bağlar:

```c
if (x)
    statement1;
statement2;
```

Burada `statement1` yalnız `x` doğruysa (sıfırdan farklıysa) yürütülür, `statement2` her zaman yürütülür.

```c
if (x)
    statement1;
else
    statement2;
statement3;
```

Burada `x` doğruysa `statement1`, değilse `statement2` yürütülür; `statement3` her durumda yürütülür.

### 15.2 Asılı else problemi

Slayttaki örnek (ekrandan, 02:20:00):

```c
if (a < b)
    if (a < c)
        return a;
    else
        return c;
else if (b < c)
    return b;
else
    return c;
```

Slayta göre bir `else`'in hemen ardından `if` gelirse ikisi genelde aynı satıra yazılır ve buna `else if` denir. İç içe `if`'lerde her `else`'in doğru `if`'e eşleştirilmesi sorunu ortaya çıkar; buna asılı else (dangling else) problemi denir. Kural: `else` her zaman en yakın önceki `if`'e aittir.

Hoca örneği şöyle izledi: ilk `else`, `if (a < c)` ile birliktedir. `a < b` doğruysa `a < c` sınanır; doğruysa `a`, değilse `c` döndürülür. `a < b` yanlışsa dıştaki `else`'e geçilir ve `b < c` sınanır; doğruysa `b`, değilse `c` döndürülür. Yani `else if (b < c)` dıştaki `if (a < b)`'nin `else`'idir. Hoca açıklama sırasında bir an kararsız kaldı, sonra bu eşleşmeyi doğruladı.

Girinti yalnız insanın anlaması içindir. `else` dıştaki `if` hizasına yazılsa bile derleyici onu iç `if`'e bağlar. Boşluklar derleyicinin davranışını değiştirmez.

> **Hocanın vurgusu:** `else`'in dıştaki `if`'e ait olması isteniyorsa süslü parantez kullanın. Süslü parantez bu anlam karmaşasına son noktayı koyar.

### 15.3 switch-case

`switch-case`, bir tam sayı değişkeninin aldığı farklı değerlere göre karar veren `if - else if` zincirinin yerine kullanılabilir. Case etiketleri tam sayı ya da karakter gibi ayrık değerler olmalıdır; ondalıklı sayı olamaz. Hoca ekranda şu iskeleti yazdı (ekrandan, 02:25:00):

```c
switch(j) {
    case 1:     //if( j == 1 )
        //yürütülecek komutlar
        break;
    case 2:     //if( j == 2 )
        //yürütülecek komutlar
        break;
}
```

Ekranda kod bu aşamadaydı. Hoca ardından anlatım sırasında altına bir `default:` kısmı ekledi.

Bir case'in altına süslü parantez olmadan birden fazla komut yazılabilir. En sonda `break` verilir. `break` konmazsa program sonraki case'in komutlarını da yürütmeye devam eder. Hocanın benzetmesi: merdivenin bir basamağından su dökmeye başlarsanız su, bir `break` basamağı görene kadar aşağı akar. Bu davranış isteniyorsa `break` konmaz; `break` tamamen seçimliktir. Ama `switch` genelde `if - else if` zincirinin bir karşılığı olarak kullanıldığı için `break`'ler çoğunlukla konur. `default` en sona konur. Oradaki `break` gerekmez, çünkü zaten `switch` bloğundan çıkılır.

Hoca `break`'i case etiketinin içine girintili yazmayı tercih ettiğini söyledi; `case 1:` ifadesini bir açılış süslü parantezi, `break`'i de kapanışı gibi düşünüyor. Bu tamamen ekip içinde benimsenen yazım biçimine bağlıdır.

İki case etiketi aynı değeri taşıyamaz: bir yerde `case 1:` varken bir yerde daha `case 1:` yazılırsa derleme hatası olur.

### 15.4 while ve do-while

`while` döngüsünde giriş koşulu doğruysa döngüye girilir; yani döngüye hiç girilmeme olasılığı vardır. `do-while`'da ise ilk iterasyon mutlaka yapılır ve sonunda koşula bakılır. Koşul doğruysa sıradaki iterasyon yapılır. Yani `do-while` gövdesi en az bir kez yürütülür.

### 15.5 Boş komut

Bir koşulda hiçbir şey yapılmaması isteniyorsa yalnız noktalı virgülden oluşan boş komut (null statement) kullanılabilir. Hocanın örneği bir `if - else if` zinciridir:

```c
if (j == 1)
    /* çeşitli komutlar */;
else if (j == 2)
    /* çeşitli komutlar */;
else if (j == 3)
    ;   /* 3 için hiçbir şey yapma */
else if (j == 4)
    /* çeşitli komutlar */;
else if (j == 5)
    /* çeşitli komutlar */;
```

Bu, `switch` içinde `case 3:` için hiçbir şey yazmamaya denk gelir. Akış bir sonraki adımla devam eder.

Boş komut sonsuz döngülere de çok aday bir noktadır. Hocanın örneğinde bir `for` döngüsü başta kullanıcıdan bir karakter alır. Devam koşulunda karakterin boşluk olup olmadığına bakılır, her iterasyon sonunda yeni bir karakter okunur ve gövde yalnız `;`'dir. Bu döngü kullanıcı boşluk girdiği sürece karakter istemeye devam eder.

<!-- BELİRSİZ: Bu for döngüsünün slayttaki tam metni (02:31:06 civarı, isspace benzeri bir fonksiyon geçiyor) karelerde görülemedi. -->

### 15.6 İç içe döngüler

Dışta `j` için 1'den 10'a (10 dahil), onun içinde `k` için 1'den 10'a giden iki `for` döngüsü düşünelim. İç döngü daha sık, dış döngü daha seyrek döner. `j = 1` için `k` 1, 2, ..., 10 değerlerini alır. Sonra `j = 2` için `k` yine 1'den 10'a gider, böyle devam eder. `for` içinde `while`, onun içinde `if` gibi her yapı algoritmanın gerektirdiği şekilde iç içe yazılabilir.

### 15.7 break, continue, goto

Hoca `continue` ve `goto`'yu kesinlikle yasakladı. Gerekçesi şudur: `goto` bir etikete atlar, başka koşullarda başka etiketlere gidilir ve kontrol akışı karmakarışık olur; kod spagetti koda döner. C bunları desteklese de düzgün bir yapısal kod için kullanılmamalıdır. `break` ise kullanılır.

`break` yalnız `switch-case` ile ilgili değildir. Döngü içinde verilen `break` o döngüden çıkmayı sağlar. Bir `break` yalnız içinde bulunduğu tek düzey döngüden çıkar; bütün döngülerden zincirleme çıkış söz konusu değildir. İç `k` döngüsündeki bir `break`, dış `j` döngüsünden çıkılmasına neden olmaz.

> **Ders sonrası not:** Hoca iç döngüde `printf`'in üstüne `if (k == 3) break;` konursa "k'nın 3 olduğu değer atlanır, 1-2 ve 4-10 işlenir" dedi. Bu `continue`'nun davranışıdır. `break` ile iç döngü `k = 3` olduğunda tamamen biter; her `j` için yalnız `k = 1` ve `k = 2` işlenir, sonra dış döngü bir sonraki `j` ile devam eder.

## 16. Ders sonundaki soru-cevaplar

**Soru:** `continue` deyimini birkaç kez kullandım; neden kullanmamamız gerektiğini tekrar söyler misiniz? **Cevap:** Hoca `continue`'nun daha çok `goto` ile birlikte anıldığını söyledi. O kodu yazarken biraz daha zorlansanız da iş başka şekilde kodlanabilir. Böylece daha sonra siz ya da bir başkası koda döndüğünde neyin nasıl yapıldığını daha kolay anlar. Hocaya göre deneyimli programcılar da `continue`'nun programın yapısal akışını izlemeyi zorlaştırdığını söyler. Slayta göre `continue` döngünün başına normalden erken dönülmesini sağlar. `break` ise döngüden çıkar. İkisi tam aynı değildir ama algoritmalarda benzer amaçlarla kullanılabilir.

**Soru:** Aynı uzunlukta olmayan veri tipleri bit operatörleriyle işleme sokulabilir mi? **Cevap:** Hoca, derleyiciyi kendisi yazsaydı kısa olan tipin değerinin soluna sıfırlar doldurup işlemi öyle yapacağını söyledi. Bu sonucu etkilemez. Ama sonuç geniş olan tipe aktarılmalıdır, yoksa veri kaybı olur.

> **Ders sonrası not:** C'de bit operatörlerinden önce iki işlenen de büyük olasılıkla "olağan aritmetik dönüşümlerle" ortak bir tipe getirilir. Kısa işaretsiz değer gerçekten sıfırla genişler. Ama kısa işaretli ve negatif bir değer işaret biti ile (1'lerle) genişletilir; bu durumda sonuç hocanın dediği "sola sıfır doldurma" ile aynı olmaz.

**Soru:** Bitwise operatör nedir? **Cevap:** İki sayının ikilik gösterimleri üzerinde bit bit yapılan işlemlerdir. Örneğin 9 ile 6 bit düzeyinde VE'lenince her basamak kendi içinde VE işlemine sokulur. VE, VEYA, XOR, NOT ve sağa/sola kaydırma bit operatörleridir.

**Soru:** `for` içinde `if`, `if`'in içinde iç komut ve dışarıda `else` gibi bir yapı nasıl çalışır? **Cevap:** Hoca bunu süslü parantezlerle hem kendinizin doğru anlayacağı hem bilgisayara doğru anlatacağınız şekilde kodlamanızı tavsiye etti. Ardından ekranda denedi (ekrandan, 02:50:00 ve 02:55:00):

```c
#include <conio.h>
/*
if for if(içte) elsedışta
*/
int main(int argc, char *argv[])
{
    int  i, j=0, k, m=1, n=-1;
    for( int i=0; i<10; i++ )
        if( m > 5 )
            //do something 1 : 10 kez ama m > 5 ise
    //do something 2 : 1 kez
    getch(); return 0;
}
```

Süslü parantez olmadığı için `for` yalnız kendinden sonraki tek komutu, yani `if`'i görür. `if` de kendinden sonraki tek komutu görür. Bu yüzden "do something 1" ancak `m > 5` ise 10 kez yapılır; aksi halde 10 iterasyonda hiçbir şey yapılmaz. "do something 2" ise döngüden bağımsızdır ve her durumda yalnız bir kez yapılır. Bunu girintili yazmak da anlamı değiştirmez.

> **Ders sonrası not:** Ekrandaki kodda iki yorum satırı gerçek komut olmadığı için `if`'in gövdesi aslında bir sonraki gerçek komut olan `getch();` olur. Kod bu hâliyle hocanın anlattığı davranışı göstermez. Anlatılan davranışı görmek için yorumların yerine gerçek komutlar konmalıdır (bkz. Örnek Sorular, soru 8). Ayrıca `getch()` ve `conio.h` Windows'a özgüdür; Linux'ta gcc ile derlenmez.

Hoca son olarak öğrencileri soru sormaya teşvik etti. Yanlış, eksik, anlamsız ya da saçma soru diye bir şey olmadığını, yalnız açığa çıkarılması gereken noktalar olduğunu söyledi. Bir soruyu sormadan önce "cevap ne olur?" diye tahmin etmeye çalışmanın, tahmin yanlış çıksa bile bu işlerin ne kadar karmaşık olduğunu görmeyi sağladığını ekledi.

## Örnek Sorular

**Soru 1** (derste sözlü ve canlı denendi, 00:43:57 - 00:48:47): `unsigned int i = 10;` için `i - 15` ifadesi `%d` ve `%u` ile yazdırılırsa ne çıkar?

> **Çözüm (derste verildi, gcc ile doğrulandı):** İşaretsiz aritmetikte $10 - 15$, $2^{32}$ modunda hesaplanır: $2^{32} - 5 = 4294967291$. Bu bit dizisi `%u` ile 4294967291, `%d` ile (işaretli yorumla) -5 olarak basılır. Sonuç, kullanılan format belirtecine ve sonucun atandığı değişkenin tipine bağlıdır.

**Soru 2** (ekrandan, 00:30:00): `int sayi = 659999;` değeri `%hi` ile yazdırılırsa ne çıkar, neden?

> **Çözüm (derste verildi):** 4639. `short` 16 bittir ve yalnız alttaki 16 bit okunur: $659999 = 10 \times 65536 + 4639$.

**Soru 3** (ekrandan, 00:35:00): 21 ve -87 sayılarını sekizlik ve on altılık sabit olarak yazın.

> **Çözüm (slayttaki tablo):** 21 = `025` = `0x15` ($2 \times 8 + 5 = 21$, $1 \times 16 + 5 = 21$). -87 = `-0127` = `-0x57` ($64 + 16 + 7 = 87$, $5 \times 16 + 7 = 87$).

**Soru 4** (ekrandan, 01:35:00): Aşağıdaki iki programın çıktısı nedir?

```c
int j=5, k=5;
printf("j: %d\t k : %d\n", j++, k--);
printf("j: %d\t k : %d\n", j, k);
```

```c
int j=5, k=5;
printf("j: %d\t k : %d\n", ++j, --k);
printf("j: %d\t k : %d\n", j, k);
```

> **Çözüm (derste verildi, gcc ile doğrulandı):** Son ek: `j: 5  k : 5` ve `j: 6  k : 4`. Ön ek: `j: 6  k : 4` ve `j: 6  k : 4`.

**Soru 5** (derste sözlü, 01:28:19): $1 + (((3 + 1) / (8 - 4)) - 5)$ ifadesinin değeri nedir?

> **Çözüm (derste verildi):** $3 + 1 = 4$, $8 - 4 = 4$, $4 / 4 = 1$, $1 - 5 = -4$, $1 + (-4) = -3$.

**Soru 6** (ekrandan, 01:50:00 ve derste sözlü, 02:44:58): `a = 9`, `b = 6` için `a & b` ve `a && b` nedir?

> **Çözüm (derste verildi, gcc ile doğrulandı):** `1001 & 0110 = 0000`, yani `a & b = 0`. İki değer de sıfırdan farklı olduğu için `a && b = 1`.

**Soru 7** (ekrandan, 01:55:00): `5 << 1` ve `255 >> 3` nedir?

> **Çözüm (slayttaki tablo, gcc ile doğrulandı):** `101` → `1010` = 10; `11111111` → `00011111` = 31.

**Soru 8** (ekrandan, 02:55:00): Süslü parantez kullanılmayan aşağıdaki kodda "1" ve "2" komutları kaçar kez çalışır? (`m = 1`)

```c
for (i = 0; i < 10; i++)
    if (m > 5)
        komut1;
komut2;
```

> **Çözüm (derste verildi):** `for` yalnız `if`'i, `if` yalnız `komut1`'i bağlar. `m = 1` olduğundan `komut1` hiç çalışmaz (`m > 5` olsaydı 10 kez çalışırdı). `komut2` döngüden bağımsızdır ve bir kez çalışır. Komutlar yerine sayaç konulan bir sürüm `gcc -Wall` ile derlenip çalıştırıldı; çıktı "1: 0 kez, 2: 1 kez" oldu.

**Soru 9** (ekrandan, 02:20:00): Asılı else örneğinde `a = 5, b = 3, c = 4` için hangi değer döndürülür?

> **Çözüm (derste verilmedi):** `a < b` yanlış (5 < 3 değil), dıştaki `else`'e geçilir. `b < c` doğru (3 < 4), `b` yani 3 döndürülür. Kod üç sayının en küçüğünü bulur.

**Soru 10** (derste sözlü ve canlı denendi, 01:46:17): `j = 0`, `n = -1` için `j || n` kaç basar?

> **Çözüm (derste verildi, gcc ile doğrulandı):** 1. Negatif sayılar da sıfırdan farklı olduğu için doğru sayılır.

## Dersin Toparlaması

Bu derste C'nin temel yapı taşları hızlıca ama platform ayrıntılarına dikkat çekilerek tekrar edildi. Skaler tipler, niteleyiciler, değer aralıkları ve format belirteçleri canlı bir programla denendi. Yanlış belirtecin işaretli bir sayıyı dev bir pozitif sayıya ya da büyük bir sayıyı 16 bite kesilmiş bir değere dönüştürebildiği görüldü. Sekizlik ve on altılık sabitler, `float` ile `double` arasındaki hassasiyet farkı, ilk değer atamanın önemi, örtük ve açık dönüşüm ile "küçük kaptan büyük kaba" kuralı anlatıldı. `enum` ve `typedef` ile programcının kendi anlamlı tiplerini kurabileceği gösterildi.

İkinci yarıda ifadeler, operatör önceliği ve birleşme yönü, bileşik atama ve artırma/azaltma operatörleri, virgül operatörü, ilişkisel ve mantıksal operatörlerin sayısal karşılıkları, bit operatörleri ve kaydırma, `cast`, `sizeof` ve koşul operatörü ele alındı. Ders `if`/`else` zinciri, asılı else problemi, `switch-case`, `while`/`do-while`, boş komut, iç içe döngüler ve `break` ile tamamlandı. Dersin bütününde öne çıkan ilke şudur: öncelik kurallarına dayanan karmaşık ifadeler yerine süslü parantez ve ayrı komutlarla açık ve taşınabilir kod yazılmalıdır. Sonraki derslerde işaretçiler, yapılar ve `typedef`'in `struct` ile kullanımı ayrıntılı olarak görülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
