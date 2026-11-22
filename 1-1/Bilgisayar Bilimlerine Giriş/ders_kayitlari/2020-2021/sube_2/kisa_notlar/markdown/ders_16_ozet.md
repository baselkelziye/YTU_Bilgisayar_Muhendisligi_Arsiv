# Ders 16 Çalışma Özeti

## Genel Konular

- Program geliştirme süreci
  - Kaynak dosya (source file) bir editörle ya da IDE ile yazılır. Derleyici kaynak kodu nesne koduna (object code) çevirir; bu adım derlemedir (compilation).
  - Bağlayıcı (linker) ayrı nesne dosyalarını tek dosyada birleştirir ve gerekirse çalışma zamanı kütüphanesindeki (runtime library) fonksiyonları ekler. Sonuç çalıştırılabilir koddur (executable). Bağlama genellikle otomatik yapılır (ekrandan, 00:25:00).
  - Gerçek uygulamalarda kod mantıksal parçalara ayrılıp birden fazla kaynak dosyada tutulur (örnek: bir dosya sunucusunda dosya sistemi, soket, iş parçacığı ve ortak yardımcı fonksiyonlar için ayrı dosyalar).
  - gcc derleme ve bağlamayı tek adımda yapar; yalnız derleme isteniyorsa bu ayrıca belirtilmelidir.
  - IDE (Integrated Development Environment): kod yazma, derleme, çalıştırma ve hata ayıklamayı tek ortamda toplayan uygulama. Uzantıya göre renklendirme yapan bir metin editörü (örneğin gedit) IDE değildir.
- C'nin temel yapısı
  - C küçük bir dildir: az kodla çok iş yapılır, çünkü gereken birçok şey büyük bir çalışma zamanı kütüphanesinde hazırdır (matematik, karakter dizisi, giriş-çıkış, bellek yönetimi, süreç).
  - Kütüphane parçalarının içeriği `.h` uzantılı başlık dosyalarında tanımlıdır. Bunlar `#include` ile koda eklenir.
  - Fonksiyon yazımı: fonksiyon tipi, fonksiyon adı, `(`, argümanlar, `)`, `{`, tanımlamalar, C deyimleri, `}` (ekrandan, 00:35:00).
  - Her çalıştırılabilir C programının başlangıç noktası `main` fonksiyonudur.
- Değişken, sabit ve adlandırma
  - Değişken bellekte bir adrese karşılık gelir; `j = 5 + 10;` deyiminde `j` değişken, 5 ve 10 sabittir.
  - Adlar harf, rakam ve alt çizgi içerebilir, ama harf ya da alt çizgiyle başlamalıdır. C büyük-küçük harfe duyarlıdır (`VaR`, `var`, `VAR` farklıdır). Ad, ayrılmış bir anahtar sözcük olamaz (ekrandan, 00:40:00).
- İfade, atama deyimi ve kod düzeni
  - İfade (expression), bir değer hesaplayan operatör, sayı ve ad birleşimidir.
  - Atama deyiminde sol taraf (lvalue) değer tutabilen bir bellek adresine çözümlenmelidir; sağ taraf (rvalue) bir ifadedir. `answer = num * num;` doğru, `num * num = answer;` yanlıştır (ekrandan, 00:45:00).
  - Kod tutarlı bir stille girintilenmeli; tanımlamalarla deyimler arasında boşluk bırakılmalıdır.
  - Yorumlar `/* ... */` (çok satırlı) ya da `//` (satır sonuna kadar) ile yazılır. İç içe yorum desteklenmez. Fonksiyon başlığı ve koddaki değişiklikler yorumlanmalıdır (ekrandan, 00:50:00).
- `main`, `return` ve `exit`
  - Unix sistemlerinde `main` genelde `int` döndürür; 0 başarılı bitişi, sıfır dışı değerler çoğunlukla sorunu gösterir.
  - `main` içinde `return` ile `exit` aynı etkidedir. Başka bir fonksiyonda `exit` programı sonlandırır; yalnız o fonksiyondan dönmek için `return` kullanılır.
- `printf` ve `scanf`
  - İkisinin de ilk argümanı çift tırnak içindeki biçim dizisidir (format string). `%d` ondalık tamsayı biçim belirtecidir; `\n` yeni satır, `\t` sekme kaçış dizisidir.
  - `scanf`'te veri argümanları lvalue olmalıdır, bu yüzden değişkenin adresi `&` ile verilir: `scanf("%d", &num);` (ekrandan, 00:55:00).
  - C'de argümanlar değerle aktarılır (pass by value); fonksiyonun değişkeni değiştirebilmesi için adres aktarılır.
- Önişlemci (preprocessor)
  - Derlemeden önce otomatik çalışır. Bütün yönergeler `#` ile başlar ve noktalı virgülle değil satır sonuyla biter. Makro işleme, koşullu derleme ve yerleşik makrolarla hata ayıklama yapabilir (ekrandan, 01:05:00).
  - `#include <dosya>` işletim sisteminin sistem başlık dosyaları için ayırdığı yerde arar; `#include "dosya"` önce kaynak dosyanın klasöründe arar, bulamazsa açılı parantezli biçim gibi arar (ekrandan, 01:20:00).
  - `#define` ile koddaki sabitler makro olarak tanımlanır; makro adları genelde tamamen büyük harfle yazılır.
- Veri tipleri
  - Sınıflandırma: `void`, skaler tipler (aritmetik tipler: tamsayı ve kayan noktalı; işaretçiler; `enum`) ve birleşik (aggregate) tipler (ekrandan, 01:25:00).
  - Skaler tipler için 9 ayrılmış sözcük vardır: temel tipler `char`, `int`, `float`, `double`, `enum`; niteleyiciler `long`, `short`, `signed`, `unsigned` (ekrandan, 01:40:00).
  - Tamsayı sabitleri ondalık, sekizlik (başta `0`) ve onaltılık (başta `0x`) yazılabilir; `u/U` ve `l/L` sonekleri vardır (ekrandan, 01:45:00).
  - Kayan noktalı sabitler noktayla (`7.0`, `7.`, `0.1`) ya da bilimsel gösterimle (`3e2`, `5e-5`) yazılır; koddaki kayan noktalı sabitler `double` sayılır.
  - İlk değer verilmeyen değişkenin değeri bilinmez; tanımlarken ya da sonra değer atanır (`char ch = 'a';`).
- Tip karışımı ve dönüşümler
  - İfadelerde `char` gibi küçük tipler `int`'e yükseltilir; farklı tipler hiyerarşide büyük olana çevrilir: `int` < `unsigned` < `long int` < `unsigned long int` < `float` < `double` < `long double` (ekrandan, 01:50:00).
  - İki tamsayının bölümü tamsayıdır: `3 / 4` sonucu 0'dır.
  - Aynı bit dizisi işaretsiz ve işaretli olarak farklı yorumlanır.
  - Açık dönüşüm (cast): hedef tip parantez içinde ifadenin önüne yazılır (ekrandan, 02:00:00).
- `enum`, `void` ve `typedef`
  - `enum` adlandırılmış değerleri numaralandırır ve tip denetimi sağlar; makrolarla tanımlanan değerlerde bu denetim yoktur.
  - `void`, parametre ya da dönüş değeri olmadığını gösterir; `void` işaretçisi genel (generic) işaretçidir.
  - `typedef` bir veri tipine yeni ad verir ve taşınabilirlik için kullanılır: `typedef long int INT32;` (ekrandan, 02:05:00).
- Operatörler
  - Öncelik (precedence) ve birleşme yönü (associativity): `a + b - c` soldan sağa, `a = b = c` sağdan sola değerlendirilir. Emin olunmayan yerde parantez kullanılır.
  - Aritmetik: `*`, `/`, `%`, `+`, `-`; `%` yalnız tamsayılarla çalışır. Bileşik atama: `a += b` gibi.
  - Artırma ve azaltma: `a++`, `a--` (önce değeri al, sonra değiştir), `++a`, `--a` (önce değiştir, sonra değeri al) (ekrandan, 02:25:00).
  - İlişkisel: `>`, `<`, `>=`, `<=`, `==`, `!=`; sonuç doğruysa 1, değilse 0'dır (ekrandan, 02:30:00).
  - Mantıksal: `&&`, `||`, `!`.
  - Bit düzeyi: `>>`, `<<`, `&`, `|`, `^`, `~`; bunlar da atamayla birleşebilir (`a >>= 3`).
  - `sizeof` bir tipin, değişkenin ya da ifadenin bayt cinsinden boyutunu verir.
- Kontrol yapıları
  - `if`/`else`, `switch`, `while`, `do-while`, `for`, boş deyim (null statement), iç içe döngüler.
  - `break`, `continue` ve `goto` derste kullanılmayacak; `break` yalnız `switch` içinde kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kod formatlama zorunludur
  - Fonksiyon içindeki ilk deyimden başlayarak dört karakter ya da bir sekme girinti yapılmalı, `if`, `for`, `while` gövdeleri ayrıca içeri alınmalıdır. Kod üç ay sonra yazanın kendisi tarafından da anlaşılabilmelidir.
- Her programın başına yorum
  - `main`'in başına kodun ne zaman ve ne için yazıldığı, ne yaptığı yazılmalıdır. Bu alışkanlık ileride yorumlardan otomatik belge üreten araçlarla da işe yarar.
- Koddaki her sabit makro olmalı
  - 5, 10, 25, 3.14 gibi sabitler `#define` ile tanımlanmalı; değişiklik tek yerden yapılmalıdır.
- Önişlemci yönergelerinin sonuna noktalı virgül konmaz
  - Konursa bazen hata alınmaz, bazen çok anlamsız hatalar çıkar.
- C uyarmadan devam eder
  - C programcının her şeyi bilerek yaptığını varsayar. Örneğin iki biçim belirtecine tek değişken verilirse derleyici hata vermez, en fazla uyarı verir. Derleme uyarıları açık parametrelerle istenmelidir.
- Tip karışımında beklenmedik sonuçlar
  - `3 / 4` sonucu 0 çıkar; 0.75 için işlenenlerden biri kayan noktalı olmalıdır (`3.0 / 4`).
  - Büyük bir `double` değerin `int`'e atanması sonucu bozar.
- Artırma operatörünü başka işlemlerle aynı ifadede kullanmayın
  - Sonuç uygulamaya bağlı olabilir; özellikle makrolara `m++` gibi argüman verilmemelidir.
- `if` içinde `==` yerine `=` yazmayın
  - `if (a = 5)` atama yapar, sonuç 5 olduğu için koşul her zaman doğru sayılır; döngüde sonsuz döngüye yol açabilir.
- Koşulları sınırlayın
  - Bir `if` içinde en fazla 3 koşul birleştirilmelidir; daha fazlası yapının yanlış kurulduğunu gösterir.
- Tek deyim olsa bile süslü parantez kullanın
  - `if` ya da döngü gövdesinde süslü parantez yoksa yalnız ilk deyim gövdeye aittir.
- `for` ve `if` sonuna noktalı virgül koymayın
  - Bu boş deyim oluşturur ve gövdeyi döngüden ya da koşuldan koparır.
- İç içe döngülerde farklı indis
  - İç döngüde dış döngünün indisini artırmak (örneğin `k++` yerine `j++`) sonsuz döngüye yol açar.
- Mod ve kaydırma işlemleri
  - `%` işlemi yalnız pozitif sayılarla, kaydırma işlemleri `unsigned` değişkenlerle kullanılmalıdır.
- Akış diyagramında da C'de de doğru dalı boş `if` yazılmaz
  - Doğru (true) kısmı olmayan `if` kullanılmaz.

## Kısa Tekrar Notları

- Kaynak kod → derleme → nesne kodu → bağlama (çalışma zamanı kütüphanesiyle) → çalıştırılabilir kod. Derlemeden önce önişlemci çalışır.
- Fonksiyon: tip, ad, `(argümanlar)`, `{ tanımlamalar; deyimler; }`. Program `main` ile başlar.
- Ad kuralları: harf/rakam/`_`, rakamla başlamaz, büyük-küçük harf duyarlı, anahtar sözcük olamaz.
- lvalue solda (bellek adresi), rvalue sağda (değer).
- `/* ... */` çok satırlı yorum, `//` tek satır yorum.
- `printf("num : %d\n", num);` yazar; `scanf("%d", &num);` okur, adres ister.
- `#include <...>` sistem klasörü, `#include "..."` önce kaynak klasörü. `#define AD deger` sonunda `;` yok.
- Skaler tipler için 9 sözcük: `char int float double enum` + `long short signed unsigned`.
- `010` sekizlik (= 8), `0x10` onaltılık (= 16); koddaki `2.5` `double`'dır.
- Dönüşüm hiyerarşisi: `int` → `unsigned` → `long int` → `unsigned long int` → `float` → `double` → `long double`.
- `3 / 4 = 0`; `(float) k / j` ile kayan noktalı bölme.
- `enum { RED, BLUE, GREEN, YELLOW }` → 0, 1, 2, 3; ilk değer 100 yapılırsa sonrakiler 101, 102, 103.
- İlişkisel ve mantıksal ifadeler 1 ya da 0 üretir; sıfır dışı her değer doğru sayılır.
- `<<` bir kez sola kaydırma 2 ile çarpar: `5 << 1 = 10`; `255 >> 3 = 31`.
- `break` yalnız `switch` içinde; `continue` ve `goto` kullanılmaz.

## Detaylı Açıklamalar

- **Program geliştirme ve bağlama.** Yazılan kaynak dosya önce nesne koduna çevrilir. Programda kullanılan hazır fonksiyonlar ya da sistem çağrıları nesne kodunda yalnız birer başvuru (referans) olarak durur. Bağlama sırasında bu başvurular çalışma zamanı kütüphanesindeki adreslerle değiştirilir, gerekli kod eklenir ve çalıştırılabilir program oluşur. Birden fazla kaynak dosya ayrı ayrı nesne dosyasına çevrilip tek çalıştırılabilir dosyada birleştirilir (ekrandan, 00:25:00). Hoca, öğrencilerin önce IDE'ye bağlı kalmadan bir metin editöründe kod yazıp editör dışında derleyebilmesini beklediğini söyledi.

- **Fonksiyon kavramı.** Fonksiyon, mantıksal olarak birbiriyle ilişkili işlemlerin bir grubudur ve tekrar tekrar kullanılabilir. Parametre almak zorunda değildir. Dönüş değeri de isteğe bağlıdır, ama dönüş yoksa bunu belirten bir tip (`void`) yazılır. Slayttaki tanıma göre C fonksiyonu, dilin yerleşik işlemlerinden daha karmaşık bir iş yapmalı, ama anlaşılması zor olacak kadar karmaşık olmamalıdır. Argümanlar, çağıran fonksiyondan çağrılan fonksiyona aktarılan verilerdir (ekrandan, 00:35:00).

- **Değişken ve sabit.** `j = 5 + 10;` deyiminde `j` bellekte bir adrese karşılık gelir ve bu adreste sağ taraftaki işlemin sonucu (15) saklanır. 5 ve 10 sabittir; değerleri değiştirilemez, bunlara değer atanamaz. Hoca `scanf` anlatımında aynı örneğe döndü: yalnız `j` yazılınca içerik (15), `&j` yazılınca adres (derste örnek adres olarak 2486 söylendi) kastedilir.
<!-- BELİRSİZ: j değişkeninin örnek adresi (2486) altyazıdan alındı; ilgili slayt karesi okunmadı. -->

- **Ayrılmış sözcükler.** `for`, `if`, `else`, `while`, `do`, `case`, `const`, `int`, `double`, `float`, `void`, `enum` gibi dilin kendi sözcükleri değişken adı olarak kullanılamaz. Örnekler: `j` ve `j5` geçerli; `5j`, nokta, `#`, `*`, `:`, `$`, `!` içeren adlar ve `int` gibi anahtar sözcükler geçersizdir.

- **Hello World.** Derste gösterilen ilk program şu yapıdadır. `void`, `main`'in parametre almadığını gösterir; `return 0;` programı çağıran kabuğa (shell) 0 değeri döndürür. Kod ajan tarafından `gcc -Wall` ile derlenip çalıştırıldı ve `Hello World...` çıktısını verdi.

```c
#include <stdio.h>

int main(void)
{
    printf("Hello World...\n");
    return 0;
}
```
<!-- BELİRSİZ: Kod altyazıdaki anlatımdan kuruldu (01:22-01:24); slayt karesi okunmadı, metnin büyük-küçük harf yazımı doğrulanamadı. -->

- **Veri tipleri ve boyutlar.** C belirtimine göre `int` en az 16 bit ve işlemcinin doğal işlem boyutundadır; 32 bitlik mimaride 4 bayt beklenir. `short int` 2 bayt, `long int` mimariye göre 4 ya da 8 bayttır. `float` genelde 4, `double` 8 bayttır; `double` iki kat duyarlıktadır. Değişkenler varsayılan olarak işaretlidir (`signed`); `signed` sözcüğü yalnız belirtimde tutarlılık için vardır. Hoca, boyutların mimariye ve derleyiciye göre değiştiğini vurguladı.

- **Tamsayı sabitleri tablosu (ekrandan, 01:45:00).**

| Decimal | Octal | Hexadecimal |
|---|---|---|
| 3 | 003 | 0x3 |
| 8 | 010 | 0x8 |
| 15 | 017 | 0xF |
| 16 | 020 | 0x10 |
| 21 | 025 | 0x15 |
| -87 | -0127 | -0x57 |
| 255 | 0377 | 0xFF |

  Tablodaki bütün karşılıklar ajan tarafından gcc ile denetlendi ve doğru çıktı. Slayta göre bir tamsayı sabiti `int`'e sığıyorsa `int`, sığmıyorsa `long int` tipindedir. Sonekler (`U`, `L`) büyük ya da küçük yazılabilir; hoca bunu C'nin büyük-küçük harf duyarlılığındaki istisnalardan biri olarak andı.

- **Örtük dönüşüm.** Derleyici ifadeyi, her biri bir operatör ve ona bağlı işlenenlerden oluşan alt ifadelere böler. Örnek `-3 / 4 + 2.5` üç operatör içerir. Çoğu ikili operatör iki işlenenin aynı tipte olmasını ister; tipler farklıysa biri hiyerarşiye göre diğerine çevrilir. `1 + 2.5` örneğinde `int` olan 1 `double`'a çevrilir (ekrandan, 01:55:00). `-3 / 4` kısmında iki işlenen de tamsayı olduğu için bölüm 0 olur; ifadenin tamamı 2.5 çıkar (ajan gcc ile denetledi).

- **İşaretli ve işaretsiz yorum.** 8 bitlik `11101010` dizisi `unsigned char` olarak 234, `signed char` olarak -22 anlamına gelir. Bellekte kapladıkları yer ve yazılışları aynıdır; değişen yalnız yorumdur.

- **Atamada kayıp.** `int j` için `j = 2.5;` yazılırsa kesir kısmı atılır ve `j` 2 olur. Bir `int`'in tutabileceğinden çok büyük bir `double` atanırsa sonuç anlamsız bir sayı olur.

- **Cast örneği (ekrandan, 02:00:00).** `int j=2, k=3; float f;` için `f = k / j;` tamsayı bölmesi yapar ve `f` 1.0 olur. `f = (float) k / j;` yazılınca `k` kayan noktalı sayılır, `j` de genişletilir ve `f` 1.5 olur.

- **`enum` ve makro farkı.** Renkler (kırmızı 0, turuncu 1, ...) ve haftanın günleri (pazartesi 0, salı 1, ...) makrolarla tanımlanırsa ikisi karıştırıldığında hiçbir denetim yapılmaz. `enum` ile tanımlanınca iki ayrı tip oluşur. Hoca gerçek hayattan soket programlamayı örnek verdi: protokol ailesi (PF) ve adres ailesi (AF) makro olarak tanımlıdır, çoğu kişi birini diğerinin yerine yazar ve değerler aynı olduğu için kod yine çalışır.

- **`void` işaretçisi ve `typedef`.** Bir iş parçacığı (thread) kütüphanesi, kullanıcının yazacağı fonksiyonun parametre ve dönüş tipini bilemez; bu yüzden `void` işaretçisi kullanır, kullanıcı cast ile istediği tipe çevirir. `typedef long int INT32;` sonrasında `long int j;` ile `INT32 j;` eşdeğerdir; mimari değişince yalnız `typedef` satırı (koşullu derlemeyle otomatik olarak) değiştirilir (ekrandan, 02:05:00).

- **İlişkisel ve mantıksal örnekler.** Derste `j = 0`, `m = 1`, `n = -1`, `x = 2.5` değerleriyle `j > m` sonucu 0, `m / n < x` sonucu 1 (`m / n` = -1 < 2.5), `j <= m >= n` sonucu 1 olarak çözüldü. Mantıksal operatör slaytında `j && m` → 0, `j < m && n < m` → 1, `x * 5 && 5 || m / n` → 1 verildi (ekrandan, 02:35:00).

- **Bit düzeyi örnekler (ekrandan, 02:40:00).** 16 bit varsayımıyla `9430` = `0x24D6` = `00100100 11010110`, `5722` = `0x165A` = `00010110 01011010`; `9430 ^ 5722` = `0x328C` = `00110010 10001100`; `~9430` = `0xDB29` = `11011011 00101001`. Değerler ajan tarafından denetlendi.

- **Kontrol yapıları.** `if (x) statement1; statement2;` yapısında `statement1` yalnız `x` sıfır değilse, `statement2` her zaman çalışır; `else` eklenirse `else` dalı yalnız `x` sıfırsa çalışır (ekrandan, 02:45:00). Çok sayıda eşitlik denetimi için (örneğin haftanın günleri) iç içe `if` yerine `switch` kullanılır; okunabilirliği artırır ve arka planda daha iyi uygulanır. `for` deyiminde önce `expression1` (ilk değer), sonra `expression2` (koşul) değerlendirilir; koşul yanlışsa döngüden çıkılır, doğruysa gövde çalışır, ardından `expression3` (artırım) değerlendirilip koşula dönülür (ekrandan, 02:50:00).

> **Ders sonrası not:** Hoca C için "fonksiyonel programlama dili" dedi ve bunu "her şey fonksiyonlar üzerinden yürür" anlamında kullandı. Programlama dilleri sınıflandırmasında C yordamsal (procedural) bir dildir; "fonksiyonel programlama" terimi Haskell gibi dillerin farklı bir paradigmasını anlatır.

> **Ders sonrası not:** Hoca kayan noktalı sınırların `limit.h` dosyasında tanımlı olduğunu söyledi. Tamsayı sınırları `limits.h`, kayan noktalı sınırlar `float.h` başlık dosyasındadır.

> **Ders sonrası not:** Hoca, `int`'e sığmayan büyük bir `double` atandığında taşma olacağını ve kalan kısmın görüleceğini söyledi. C standardında bu durum tanımsız davranıştır (undefined behavior); sonuç derleyiciye ve sisteme göre değişir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
