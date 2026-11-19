# Ders 5 Genişletilmiş Notu: Ön İşlemci Komutları, Değişken Kapsamı ve Saklama Sınıfları, İşaretçilere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Hatırlatması
- 2. Ön İşlemci Komutları
- 3. Makrolar
- 4. Makronun Yan Etkisi
- 5. Makro mu, Fonksiyon mu?
- 6. Makro Tanımını Geri Almak: #undef
- 7. Hazır Makrolar
- 8. Koşullu Derleme
- 9. #include ve Başlık Dosyaları
- 10. Koşullu Derleme Örneği
- 11. Kapsam ve Ömür
- 12. static Anahtar Kelimesi
- 13. Kapsam Türleri
- 14. Global Değişkenler, Tanım ve Anma
- 15. Saklama Sınıfları: register, extern, const, volatile
- 16. İşaretçilerin Temeli
- 17. Diziler
- 18. Dizi Elemanlarına İşaretçiyle Erişim
- Örnek Sorular

## 1. Önceki Dersin Hatırlatması

Hoca derse geçen haftayı özetleyerek başladı. C'nin yapısı, operatör önceliği ve bit düzeyi (bitwise) işlemler hatırlatıldı. İki değeri `&&` ile birleştirmek mantıksal bir işlemdir: sıfır dışındaki her değer doğru (true), sıfır yanlış (false) sayılır. Tek `&` ise iki sayının ikili gösterimindeki aynı basamaktaki bitleri tek tek mantıksal işlemden geçirir. Bir önceki derste de `printf` biçim belirteçlerinin (format specifier) tablosu verilmişti. Bu dersle birlikte C'nin daha ileri özelliklerine geçiliyor.

## 2. Ön İşlemci Komutları

Ön işlemci (preprocessor) komutları `#` ile başlayan satırlardır. Derleyici kodu derlemeye başlamadan önce bu satırları ele alır, gerektirdikleri işlemleri kaynak kodun geri kalanına uygular, ancak ondan sonra asıl derlemeyi yapar. Ön işlemciyle şunlar yapılabilir:

- Tip tanımlamaları (geçen hafta küçük bir örneği görülmüştü).
- Kod kitaplıklarını eklemek (`#include`).
- Makro tanımlamak.
- Koşula göre derleme (conditional compilation): örneğin kodu test modunda programcıya yönelik ek çıktılarla, üretim modunda bu çıktılar olmadan derlemek.
- Kodun hangi satırında olunduğu gibi bilgileri koda yerleştirmek.

Slayttaki kurallar (ekrandan, 00:10:00):

- Bütün ön işlemci komutları `#` ile başlar ve `#` satırdaki ilk boşluk olmayan karakter olmalıdır. Önünde boşluk, sekme gibi beyaz boşluk (white space) karakterleri olabilir.
- C deyimlerinden farklı olarak makro komutu noktalı virgülle değil, satır sonuyla biter.
- Bir makroyu birden fazla satıra yaymak için satır sonundan hemen önce ters bölü (`\`) konur. Derleyici bu karakteri sonraki satırın önceki komutun devamı olduğu şeklinde yorumlar.

```c
#define LONG_MACRO "This is a very long \
macro that spans two lines"
```

## 3. Makrolar

Makro, `#define` ile bir ada bir metin bağlamaktır. Derleyici kodda makro adını gördüğü her yere, satırın geri kalanında yazan gövdeyi yapıştırıyormuş gibi davranır. Kaynak dosya değişmez; derleme sırasında makro adının geçtiği her yerde gövde varmış gibi derlenir.

**Soru:** Bunun fonksiyondan farkı ne? **Cevap:** Hoca ayrıntısını sonraki slaytlarda göstereceğini söyledi ve temel farkı açıkladı: bir fonksiyon çağrıldığında çağrılan fonksiyon için yeni bir bellek bağlamı kurulmalıdır. Parametre aktarımı için ek alan ayrılır, fonksiyonun geçici değişkenleri saklanır. Bu iş yığın (stack) mantığıyla yürür: her çağrıda yığında yeni bir alan açılır, fonksiyon dönünce alan yığından çekilir (pop). Makroda bu çağrı yükü yoktur, ama başka dezavantajları vardır.

### 3.1 Sabit tanımlamak

Makronun en basit kullanımı sabit bir değer tanımlamaktır. C'de ayrı bir karakter katarı (string) türü yoktur, yalnız karakter dizileri vardır. En büyük katar uzunluğu ya da bir tampon belleğin (buffer) en büyük boyutu gibi değerleri sabit olarak tanımlamak yerinde olur:

```c
#define BUFLEN 512
```

Kodda `BUFLEN` geçen her yere 512 yazılır. Aynı değer `int buflen = 512;` diye değişken olarak tanımlansaydı, bellekte o tam sayı için (sisteme göre 2 ya da 4 baytlık) yer ayrılacaktı. Sabit tanımlamada yer ayrılmaz, küçük bir bellek kazancı olur.

### 3.2 Fonksiyon benzeri makrolar

Slayttaki örnekler (ekrandan, 00:15:00):

```c
/* Example 1 */
#define MUL_BY_TWO(a)  ((a) + (a))

j = MUL_BY_TWO(5);
f = MUL_BY_TWO(2.5);

/* Example 2 */
#define min(a, b) ( (a) < (b) ? (a) : (b))
```

Slayttaki uyarılar: makronun sonuna `;` konmaz, makro tanımında `=` kullanılmaz; makro argümanlarında tür denetimi yoktur.

- `MUL_BY_TWO` adı fonksiyon gibi kullanılır ve tek parametre alır. Aslında çarpma yapmaz; parametreyi kendisiyle toplar. Atama, makronun çağrıldığı yerde yapılır: `j = MUL_BY_TWO(5);` 5'i kendisiyle toplayıp sonucu `j`'ye yazar.
- `a`'nın türü belirtilmez. İlk örnekte tam sayı, ikinci örnekte ondalıklı sayı olarak değerlendirilir.
- `min` makrosu iki parametre alır; parametreler fonksiyonlardaki gibi virgülle ayrılır. Geçen hafta görülen `? :` operatörünü kullanır: soru işaretinden önceki ifade doğruysa `?` ile `:` arasındaki ifade, değilse `:`'nın sağındaki ifade sonuç olur.

Hoca, tür denetimi olmamasının önemli bir yan etki olduğunu vurguladı. C güçlü tipli bir dildir; ama makro koda yapıştırıldığında tür uyuşmazlığı derleme hatası vermeyebilir. Örneğin toplama yapılacak yere karakterler gelirse derleyici karakterlerin ASCII kodlarını toplar. Bu davranış programın mantığı açısından beklenmeyen bir şey olabilir. Makroyu başkası yazmışsa ve siz varlığından haberdar değilseniz, normal bir işlem yaptığınızı sanarken makro devreye girer ve kod beklendiği gibi çalışmaz.

Makro adlarının büyük harfle yazılması bir gelenektir. Böylece kodda neyin normal fonksiyon, neyin makro olduğu kolayca görülür.

**Soru:** Bu `min` neden küçük harfle yazılmış, büyük olması gerekmiyor muydu? Zorunluluk mu? **Cevap:** Hoca da büyük olması gerektiğini söyledi. Zorunluluk değil, bir kodlama alışkanlığı ya da kodlama standardıdır.

**Soru:** Makroyla yapılanlar fonksiyonla, fonksiyonla yapılanlar makroyla da yapılabiliyor, yalnız biri uzun biri kısa oluyor; doğru mu? **Cevap:** Evet. Hoca bir şeyi vurguladı: makrolar normalde tek satırda halledilecek işler içindir. İkinci satır gerektiğinde ters bölüyle bölünür, ama bu iki satırdan sonra rahatsız edici olur.

> **Hocanın vurgusu:** Bir satır, bilemediniz en çok iki satırlık makro. Satır sayısı arttıkça "bunu fonksiyonla yapsam daha doğru olmaz mıydı?" diye kararınızı sorgulamanız lazım.

## 4. Makronun Yan Etkisi

Slaytta `min` makrosu bir argümanında artırma işlemiyle çağrılıyor (ekrandan, 00:20:00):

```c
#define min(a,b)  ((a) < (b) ? (a) : (b))

a = min(b++, c);

/* ön işlemcinin ürettiği: */
a =  ((b++) < (c) ? (b++) : (c));
```

Ön işlemci gövdede `a` gördüğü yere `b++`, `b` gördüğü yere `c` yazar. `b`'nin değeri `c`'den küçükse koşul doğru olur ve `b++` iki kez çalışır: bir kez koşul denetlenirken, bir kez de seçilen dal değerlendirilirken. Böylece `b` iki artmış olur. Aynı iş `if (ilk < ikinci) return ilk; else return ikinci;` şeklinde bir fonksiyonla yapılsaydı `b++` yalnız bir kez çalışacaktı.

Hoca bu durumun sonucunu şöyle anlattı: bir fonksiyon çağırıyorsunuz, bazen sonuç beklediğinizden farklı çıkıyor, bazen doğru çalışıyor. Her zaman aynı yanlışı ya da her zaman doğruyu verse sorun kolay bulunur. Ama bazen doğru bazen yanlış çalışan bir kodun hatasını ayıklamak çok daha fazla çaba ister.

### 4.1 Derste yapılan deneme

Hoca C kodlarını Dev-C++ 4 ile yazdığını hatırlattı. Bu IDE kendi C derleyicisiyle geldiği için ayrıca derleyici kurmaya ve IDE ile entegre etmeye gerek yoktur; eski bir yazılım olduğu için dosya adlarında uzun isimlerden kaçınmak gerekir.

Önce aynı iş fonksiyonla yazıldı, sonra makro eklendi. Fonksiyonla karışmasın diye makro adı büyük harfle `MIN` yapıldı (C büyük/küçük harfe duyarlıdır). Ekrandaki son hali (ekrandan, 00:30:00):

```c
#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b)  ((a) < (b) ? (a) : (b))

int min( int a, int b ) {
    if( a < b ) return a;
    return b;
}

int main(int argc, char *argv[]){
    int x = 3, y = 10;

    printf("min: %d\n", MIN(x++,y));
    printf("x: %d\n",x);
    printf("y: %d\n",y);

    system("PAUSE");
    return 0;
}
```

- `min(x, y)` ve `MIN(x, y)` artırma olmadan 3 verdi; beklenen sonuç.
- Fonksiyonla `min(x++, y)`: fonksiyona `x`'in değeri olarak 3 gider, `x` bir kez artar. Çıktı: `min: 3`, `x: 4`, `y: 10`.
- Makroyla `MIN(x++, y)`: ifade `((x++) < (y) ? (x++) : (y))` olur. Koşulda 3 ile 10 karşılaştırılır, doğrudur ve `x` 4 olur (ara adım eklendi). Seçilen dalda `x++` yeniden çalışır: değer olarak 4 döner, `x` 5 olur. Çıktı: `min: 4`, `x: 5`, `y: 10`. Hoca da makroya `x`'in 4 olarak girdiğini ve `x`'in 5 olduğunu gösterdi.

İki sürüm gcc -Wall ile derlendi ve çalıştırıldı (`system("PAUSE")` Linux'ta çıkarıldı); çıktılar yukarıdakiyle aynıdır.

> **Ders sonrası not:** Hoca farkı "makro yazımının önceliği daha düşük" diye açıkladı. Asıl neden öncelik değildir: makro gövdesinde `a` iki kez geçtiği için `x++` argümanı iki kez değerlendirilir. Slayttaki "Macro arguments are reevaluated at each mention in the macro body" maddesi bu durumu anlatır. Hoca fonksiyon için de "fonksiyon bittikten sonra x arttırılıyor" dedi; C'de artırma fonksiyon çağrısından önce tamamlanır, fonksiyona yalnızca eski değer gider. Sonuç aynıdır.

> **Hocanın vurgusu:** Çalışma mekanizmasını iyi bilirsek bu yan etkilere şaşırmayız; bilmezsek son derece şaşırabiliriz.

## 5. Makro mu, Fonksiyon mu?

Slayttaki karşılaştırma (ekrandan, 00:35:00):

| Avantajlar | Dezavantajlar |
|---|---|
| Makrolar genelde fonksiyonlardan hızlıdır, çünkü fonksiyon çağrısı ek yükünden (function call overhead) kaçınırlar. | Makro argümanları gövdede geçtikleri her yerde yeniden değerlendirilir; argümanda yan etki varsa beklenmedik davranış olur. |
| Argümanlara tür kısıtı konmadığından tek bir makro birçok veri türüne hizmet edebilir. | Fonksiyon gövdesi bir kez derlenir ve çağrılar aynı kodu paylaşır; makro ise programda her geçtiği yerde açılır. |
| | Makrolar argüman sayısını denetler ama türünü denetlemez. |
| | Kaynak kod ek bir çeviri katmanından geçtiği için makro içeren programda hata ayıklamak daha zordur. |

Hoca maddeleri tek tek açıkladı:

- **Hız:** Her fonksiyon çağrısında yeni bir bellek bağlamı açılır. Örneğin çağıran fonksiyonda ve çağrılan fonksiyonda ayrı ayrı `x` adlı geçici değişkenler varsa, eskisi yığında daha dipte, yenisi daha yukarıda saklanır. Makroda bu yük yoktur.
- **Tür bağımsızlığı:** Fonksiyonla iki tam sayının en küçüğü için bir `min`, iki ondalıklı sayı için başka bir `min` yazmak gerekir. İş biraz karmaşıksa aynı kodu kopyala yapıştır ile çoğaltırsınız; bir değişiklik gerektiğinde bunu kopyaladığınız her yerde yapmanız gerekir.
- **Kod büyüklüğü:** Aynı fonksiyona yapılan çağrılar bellekte aynı kod noktasına gider. Makro ise her kullanımda yeniden yazılır. Makro uzadıkça ve kullanıldığı yer arttıkça çalıştırılabilir kod, aynı işi fonksiyonla yapsaydınız oluşacak koddan daha fazla makine komutu içerir; programın bellekte kapladığı alan artar.
- **Tür denetimi yok:** Esneklik sağlar ama olası yanlış kullanımlara da kapı aralar.
- **Hata ayıklama:** Makro üzerinde çalışılması gereken ek bir karmaşıklık katmanı getirir.

Hoca dezavantaj tarafının çok daha kalabalık olduğuna dikkat çekti.

## 6. Makro Tanımını Geri Almak: #undef

Bir makro tanımlandıktan sonra geçersiz kılınabilir. Ayrıca ön işlemci komutlarının kodun en başında olması zorunlu değildir; kodun ortasında da yazılabilir.

Hocanın örneği: kaynak kodu elinizde olmayan iki kod kitaplığını çağırmanız gerekiyor. Birinin arka planı "false 1 ile kodlanır" mantığına, diğeri "false 0 ile kodlanır" mantığına göre kurulmuş. İkisini de çalıştırmak için:

```text
#define FALSE 1
... FALSE'un 1 olduğu kodu çağır ...
#undef FALSE
#define FALSE 0
... FALSE'un 0 olduğu kodu çağır ...
```

`#undef FALSE` "yaptığın tanımı geri al" demektir. `#undef` yazmadan doğrudan `#define FALSE 0` denirse sorun çıkar. Hocanın anlatımına göre ikinci tanım öncekinin üstüne yazılır ve program çalışmadan önce her yerde FALSE 0 kalmış olur.

> **Ders sonrası not:** `#undef` kullanmak doğru yoldur, ama hocanın gerekçesi tam doğru değildir. Ön işlemci dosyayı yukarıdan aşağı işler ve her tanım yalnız kendisinden sonraki satırlar için geçerlidir; ikinci tanım öncekilerin "üstüne yazmaz". Asıl sorun, bir makroyu `#undef` yapmadan farklı bir gövdeyle yeniden tanımlamanın C standardına aykırı olmasıdır. gcc ile denendiğinde "‘FALSE’ redefined" uyarısı alındı; ikinci tanımdan önceki kullanım 1, sonraki kullanım 0 değerini aldı.

## 7. Hazır Makrolar

C ile birlikte gelen önceden tanımlı makrolar (ekrandan, 00:40:00). Adların başında ve sonunda yan yana iki alt çizgi vardır; hoca slayttaki yazı tipinde iki çizginin tek çizgi gibi göründüğünü belirtti.

- `__LINE__`: çağrıldığı kaynak dosya satırının numarasına açılır.
- `__FILE__`: çağrıldığı dosyanın adına açılır.
- `__TIME__`: programın derlenme saatine açılır.
- `__DATE__`: programın derlenme tarihine açılır.
- `__STDC__`: derleyici ANSI standardına uyuyorsa 1 sabitine açılır.

Hocanın verdiği kullanım örnekleri: bir `print_version` fonksiyonunda `printf` ile "This utility compiled on ..." yazdırıp `__DATE__` ve `__TIME__` vermek; ya da "bu mesaj şu kaynak dosyanın şu satırındadır" demek için `__LINE__` ve `__FILE__` kullanmak.

**Soru:** `__LINE__` ya da `__FILE__` yazdırırken `%s` mi `%d` mi kullanılacağını nereden biliyoruz? **Cevap:** Ne döndürdüklerini bildiğimiz için. `__LINE__` satır numarası, yani sayıdır: `%d`. `__FILE__` dosya adıdır (ör. `Project1.c`), karakter katarıdır: `%s`. Satır 65 iken `__LINE__` `%c` ile yazdırılırsa 65'in ASCII karşılığı olan `A` görünür.

> **Ders sonrası not:** Hoca `__STDC__` için "aksi takdirde herhalde sıfır döndürüyor" dedi. Standarda uymayan bir derleyicide bu makronun tanımlı olacağı garanti değildir; büyük olasılıkla hiç tanımlanmaz ya da derleyiciye göre değişir. Linux'taki gcc'de `__STDC__` 1 olarak denendi.

## 8. Koşullu Derleme

Slayttaki açıklama (ekrandan, 00:45:00):

- Ön işlemci, derlenmesi istenmeyen kaynak kod kısımlarını ayıklamanıza izin verir. Bu, `if` ve `else` deyimlerine benzeyen bir dizi ön işlemci komutuyla yapılır: `#if`, `#else`, `#elif`, `#endif`.
- Koşullu derleme özellikle hata ayıklama aşamasında kullanışlıdır: bir makronun değerini değiştirerek kodun bölümlerini açıp kapatabilirsiniz.
- Çoğu derleyicinin derleme başlamadan makro tanımlamaya izin veren bir komut satırı seçeneği vardır: `gcc -DDEBUG=1 test.c`.

`#elif` "else if" anlamına gelir. Derleme sırasında "şu an hata ayıklama modundayım" anlamında `-DDEBUG=1` parametresi verilirse kod hata ayıklama modunda, verilmezse normal modda derlenir.

Hocanın aktardığı kurallar:

- `#if` bir karar verme komutudur. Normal `if`'te koşul parantez içinde yazılır; ön işlemcide parantez zorunlu değildir, kullanılırsa da hata vermez. Süslü parantez kesinlikle kullanılmaz.
- `#if`'ten sonra sıfır ya da daha fazla `#elif` gelebilir.
- Normal kodda `else`'in hangi `if`'e ait olduğu süslü parantezlerle gösterilir; parantez yoksa `else` en yakın `if`'e aittir. Ön işlemcide tek bir `#else` olur, en son komut odur.
- Açılan her `#if` bir `#endif` ile kapanmak zorundadır.

> **Ders sonrası not:** Hoca "iç içe if yazamıyorsunuz, belki problem olmuyordur, deneriz" dedi. C'de `#if ... #endif` blokları iç içe yazılabilir; kural, her `#if` bloğunun en çok bir `#else` içermesi ve o `#else`'in bloğun son dalı olmasıdır. Hocanın "sadece bir tane elsif kullanabiliyorsunuz" ifadesi de büyük olasılıkla `#else` için söylenmiştir; slayt ve yukarıdaki kural birden çok `#elif`'e izin verir.

### 8.1 Tanımlı olup olmadığını sınamak

Slayttaki biçimler (ekrandan, 00:50:00):

```c
#if defined TEST          /* #if defined (TEST)   */
#if defined macro_name    /* #ifdef macro_name    */
#if !defined macro_name   /* #ifndef macro_name   */
```

`TEST` adlı bir makro tanımlanmışsa, ya da belirli bir adla makro tanımlanmamışsa (`!` ile "değil") gibi koşullar yazılabilir. Parantez kullanmak serbesttir. `#if defined` yerine kısaca `#ifdef`, `#if !defined` yerine `#ifndef` yazılabilir. Böylece `#if`, `#elif`, `#else`, `#endif`'e ek olarak `#ifdef` ve `#ifndef` komutları da görülmüş oldu.

> **Ders sonrası not:** Hoca `#ifdef` ve `#ifndef` için "bazı derleyiciler destekliyormuş" dedi. İkisi de C standardının parçasıdır ve bütün standart derleyicilerde vardır.

## 9. #include ve Başlık Dosyaları

Aradan sonra hoca `#include` komutunu yeniden ele aldı. `#include` ile koda başka kod kitaplıkları eklenir: C ile gelen kitaplıklar da, sizin ya da başka bir programcının hazırladığı kitaplıklar da. Komuttan sonra kitaplığın nerede olduğu ve adı belirtilir.

- Dosya adı `< >` içinde yazılırsa derleyici, işletim sisteminin varsayılan olarak tanımladığı dizinlere bakar. Bu dizinler işletim sistemine göre değişir; Unix sistemlerde `/usr/include` altındadır.
- Dosya adı tırnak (`" "`) içinde yazılırsa dosyanın kaynak kodun bulunduğu dizinde olduğu söylenmiş olur. Orada bulunamazsa yine işletim sistemine bakılır; örneğin Windows'ta PATH ortam değişkenindeki yollara bakılır. Hiçbir yerde bulunamazsa derleme aşamasında "dosya bulunamadı" hatası alınır.

Hoca Windows'ta sistem ortam değişkenlerini gösterdi: bir komut verildiğinde komut o anki dizinde yoksa sistemin PATH değişkenindeki yollara, sonra kullanıcı için tanımlı PATH'teki ek yollara bakılır.

Eklenecek kod dosyaları için önce bir tanıtım dosyası hazırlanır. Bunun uzantısı geleneksel olarak `.h`'dir (header file, başlık dosyası). Bir fonksiyonu kullanmak için ya kodunun daha yukarıda tanımlanması ya da imzasının yukarıda verilip kodun aşağıda yazılması gerektiği daha önce konuşulmuştu. Başlık dosyalarında da aynısı yapılabilir ve yapılmalıdır. Hoca `__LINE__` ve `__FILE__` gibi bilgilerin, derleme öncesinde ya da sonrasında çalışan başka araçlara bilgi aktarmak için kullanılabileceğini söyledi, ama bu konuya fazla girmeyeceklerini belirtti.

## 10. Koşullu Derleme Örneği

Hoca slaytta olmayan bir örnek yazdı. Önce `#if` bloğunun çalışabilmesi için en başta `x`'in tanımlanması gerektiğini belirtti. İlk sürümde blok `main`'den önceydi (ekrandan, 01:10:00):

```c
#define x 1

#if    x==1
    #undef  x
    #define     x   0
#elif   x == 2
    #undef  x
    #define     x   3
#else
    #define     y   4
#endif
```

Okunuşu: `x` 1 ise `x`'in tanımını geri al ve `x`'i 0 yap; değilse ve `x` 2 ise tanımı geri al ve `x`'i 3 yap; ikisi de değilse `y`'yi 4 olarak tanımla. Bu sürümde `main` içinde `x` yazdırılınca 0 çıktı.

Sonra hoca `x`'in `main`'de ve bir fonksiyonda farklı davrandığını göstermek için bloğu `main`'den sonraya taşıdı (ekrandan, 01:15:00):

```c
#include <stdio.h>
#include <stdlib.h>

#define x 1

void myFunc( );

int main(int argc, char *argv[]){
    printf("main x: %d\n",x);
    myFunc( );
    system("PAUSE");
    return 0;
}

#if    x==1
    #undef  x
    #define     x   0
#elif   x == 2
    #undef  x
    #define     x   3
#else
    #define     y   4
#endif

void myFunc( ){
    printf("myFunc x: %d\n",x);
}
```

<!-- BELİRSİZ: myFunc gövdesi karede görünmüyor; hocanın anlatımına göre fonksiyon yalnızca x'i yazdırıyor. -->

Çıktı `main x: 1`, `myFunc x: 0` oldu. Hocanın açıklaması: önce `x` 1 olarak tanımlanır, sonra derleyiciye `myFunc`'ın aşağıda tanımlanacağı söylenir (imza). `main`'in içinde `x` diye bir değişken yoktur; ön işlemci `x` gördüğü yere 1 koyar. `myFunc` aşağıdadır ve ondan önce ön işlemci `#if ... #endif` komutlarını işler, `x`'i 0 yapar. Hoca, bu `#if` satırlarının `main`'in üstünde olmamasına rağmen `myFunc` için işini yaptığına dikkat çekti. `x` 2 tanımlansaydı `main`'de 2, `myFunc`'ta 3 yazacaktı.

**Soru:** Bu kodda `y`'ye de bakabilir miyiz? **Cevap:** `y`'nin tanımlanması için `x`'in 1 ya da 2 olmaması gerekir. `x` 1 iken `myFunc` içinde `y` yazdırılmaya çalışılınca "y tanımlanmamış" derleme hatası alındı. `x` 5 yapılınca ilk iki koşul tutmadı, `#else` dalında `y` 4 olarak tanımlandı ve proje derlendi. `x`'i değiştiren bir dal olmadığı için `main`'de de `myFunc`'ta da `x` 5, `y` 4 göründü.

Bu kod gcc -Wall ile derlendi ve çalıştırıldı (`system("PAUSE")` çıkarılarak): `x` 1 için `main x: 1` / `myFunc x: 0`; `x` 2 için 2 / 3; `x` 5 iken `myFunc`'ta `y` de yazdırılınca 5 / 5 ve `y: 4`. `x` 1 iken `y` kullanan sürüm "‘y’ undeclared" hatası verdi.

### 10.1 Makro kullanmak gerekir mi?

**Soru:** Bir öğrenci, Brian Kernighan'ın makroların eski bilgisayarlarda fonksiyon çağrısı yükünden kaçınmak için kullanıldığını ve artık kullanılmaması gerektiğini söylediğini aktardı. Makro kullanmamızı gerektirecek özel durumlar var mı? **Cevap:** Hoca Kernighan'ın haklı olduğunu söyledi; makroların dezavantaj tarafı çok daha ağır bastığı için mümkün olduğunca kullanılmazlar. Bugün yüksek kaynaklı sistemlerle çalışıyoruz, ama hâlâ çok sınırlı kod belleğine sahip cihazlar var: bir düğme büyüklüğündeki küçük IoT cihazları gibi. Her baytın kazanılması gereken böyle yerlerde fonksiyon çağrısından kaçınmak için bazı makrolar hazırlanabilir. Bunlar özel durumlardır; makro kullanmamak daha iyidir ama konuyu öğrenmek gerekir.

## 11. Kapsam ve Ömür

Dersin bu bölümünde değişkenin kapsamı (scope), global değişken tanımı, `register` niteleyicisi, saklama sınıfları (storage classes) ve dinamik bellek ayırmaya giriş planlandı.

Genelde değişkenler üzerinden konuşulsa da fonksiyonların da kapsamı vardır. C bu konuda tutucu bir dildir: bir değişkeni ya da fonksiyonu kullanmadan önce ya tanımlanmış olmasını ya da en azından daha sonra tanımlanacağını bildiren bir başlık satırının bulunmasını zorunlu tutar.

- **Kapsam (scope):** Bir değişken ya da fonksiyonun adının ve kullanımının hangi kod satırları ve blokları arasında geçerli olduğunu, yani erişilebilir olduğunu anlatır.
- **Ömür (duration, lifetime):** Değişkenin bellekte yer aldığı süredir. Değişken belli bir anda erişilemez olabilir, ama bellekte bir yerde duruyorsa yaşıyordur. Hoca bunu cep telefonunu "erişilemez" duruma almaya benzetti.

Hoca "otomatik ömür"ün pek ayrı bir kavram olmadığını, asıl kullanılan kavramın sabit ömür (fixed duration) olduğunu söyledi. Sabit ömürlü bir değişkenin kapsamından çıkıldığında da değeri bellekte saklanır ve kapsamına yeniden girilince erişilebilir.

> **Ders sonrası not:** Hoca "otomatik ömür diye bir kavram pek yok" dedi, ama slaytın başlığı "Fixed vs. Automatic Duration"dır (ekrandan, 01:30:00) ve slaytta `j`'nin varsayılan olarak otomatik ömre sahip olduğu yazar. Otomatik ömür, bloğa girişte oluşan ve bloktan çıkınca yok olan yerel değişkenlerin ömrüdür.

Örnek: `main`'de değeri 5 olan bir `x` tanımlandı, sonra başka bir fonksiyon çağrıldı ve onda da değeri 3 olan bir `x` tanımlandı. Çağrı sırasında `main`'deki `x` erişilemez hale gelir ama değeri bellekte kalır. Yeni fonksiyon çağrılınca yığına yeni bir bellek alanı itilir ve yeni `x` orada tanımlanır. Fonksiyon bitince onun saklama alanı yığından çekilir ve ömrü biter. Aynı fonksiyon başka bir yerden yeniden çağrılınca yine bir `x` oluşur, ama o artık başka bir değişkendir.

## 12. static Anahtar Kelimesi

Bir fonksiyon ya da `main` içinde tanımlanan değişkenlere yerel değişken denir. Fonksiyon her çağrıldığında yerel değişken yeniden ilk değerini alır. Örneğin fonksiyon içinde `int x = 3;` var, hesaplamalar sonunda `x` 5 oldu ve fonksiyon bitti. Fonksiyon yeniden çağrılınca `int x = 3;` satırı yeniden çalışır ve `x` 3 olur. Önceki çağrıda ulaşılan 5'in saklanması isteniyorsa değişken `static` olarak tanımlanır: `static int x = 3;` ile fonksiyon bir kez çağrılıp `x` 5 olduktan sonra, bir sonraki çağrıda `x` 5'ten devam eder.

`auto` diye bir anahtar kelime de vardır ama çok nadir kullanılır ve aslında gerekmez. Özetle yerel değişkenin ömrü tanımlandığı blok kadardır; ömrünün bitmemesi isteniyorsa değişken `static` ile işaretlenir. `static` değişkene yalnız bir kez ilk değer atanır. Hiçbir şey yazılmadan blok içinde tanımlanan değişkenler otomatiktir: bloğa her girişte yeniden ilk değer alırlar, son değerlerini korumazlar.

### 12.1 increment() örneği

Slayttaki kod (ekrandan, 01:30:00):

```c
void increment ( void ) {
   int j = 1;
   static int k = 1;
   j++;
   k++;
   printf("j : %d\t k:%d\n", j, k);
}
main ( void ) {
         increment(); // j:2 k:2
         increment(); // j:2 k:3
         increment(); // j:2 k:4
}
```

Slayttaki maddeler: sabit ömürlü değişkenlere yalnız bir kez ilk değer verilir, otomatik değişkenlere ise blokları her yeniden girildiğinde. `increment()` iki değişkeni artırır, ikisinin de ilk değeri 1'dir; `j` varsayılan olarak otomatik ömürlüdür, `k` `static` nedeniyle sabit ömürlüdür.

Fonksiyon parametre almadığı için parantez içine `void` yazmak zorunlu değildir, boş bırakılabilir. `main` fonksiyonu `increment`'i üç kez çağırır. Her seferinde `j` 1'den başlayıp 2 olur. `k`'ye ilk değer yalnız ilk çağrıda verilir ve 2 olur; sonraki çağrılarda `static` tanım yeniden çalışmaz, `k` 3 ve 4 olur. Hoca kodu Dev-C++'ta çalıştırdı ve aynı çıktıyı gösterdi.

Kod gcc -Wall ile derlendi ve çalıştırıldı (`main` için `int` dönüş tipi ve `#include <stdio.h>` eklendi): `j : 2  k:2`, `j : 2  k:3`, `j : 2  k:4`.

### 12.2 static mi, global mi?

Bu kalıcılık nerede istenir? Örneğin bir dizide ya da kayıt listesinde dolaşırken en son okunan kaydın yerini saklamak için. Bunun iki yolu vardır: fonksiyon içinde `static` değişken ya da `static int k = 1;` satırını fonksiyondan çıkarıp hepsinin üstüne `int k = 1;` diye bir global değişken. İkisi de aynı etkiyi verir. Hoca ikinci sürümü de çalıştırdı ve aynı sonucu aldı.

Fark şudur: `k` global olursa başka bir fonksiyon, hatta `main`, `k = 5` ya da `k = 7` diyerek onu değiştirebilir. `k` `increment` içinde tanımlıysa kapsamı yalnız o fonksiyondur ve başka hiçbir yerden erişilemez. Hoca bunu da gösterdi: `k` fonksiyon içinde `static` iken `main`'e eklenen `k` atamaları derleme hatası verdi. Derleyici hatayı yalnız ilk gördüğü yerde gösterip diğerleri için tekrarlamadığını belirtti.

> **Hocanın vurgusu:** Bir değişkenin denetiminin sıkı sıkıya tek bir fonksiyonda kalmasını istiyorsanız onu o fonksiyonun içinde tanımlarsınız, kalıcı olması için de `static` ile işaretlersiniz.

## 13. Kapsam Türleri

Dört kapsam türü vardır. Hoca önce "global kapsam" diye söze başladı, sonra ders notuna bakıp örneklerini düzeltti. Derste yalnız tek bir `.c` dosyasıyla çalışıldığını, birden fazla `.c` dosyasını birleştirme işine girilmeyeceğini belirtti. Ekrandaki son hali (ekrandan, 01:45:00):

```c
#include <stdio.h>
#include <stdlib.h>

int g = 3; //program scope
static int s = 5; //file scope

void increment ( void )  {
    int j = 1; //function scope
    static int k = 1; //function scope
    for( g=1; g<10; g++ ) {
        int y = 4; //block scope
        if( g % 2 == 0 ) {
            printf("%d",y);
        }
        printf("%d",k);
    }
    j++;
    k++;
    printf("new: j : %d\t k:%d\n", j, k);
}
```

- **Program kapsamı:** Projedeki bütün dosyaların ortak olarak gördüğü değişken. Fonksiyonların dışında tanımlanan `int g = 3;` program kapsamındadır.
- **Dosya kapsamı:** Fonksiyonların dışında `static` ile tanımlanan değişken (`static int s = 5;`) yalnız o `.c` dosyasındaki fonksiyonlarca erişilebilir.
- **Fonksiyon kapsamı:** `increment` içindeki `int j` ve `static int k`. Fonksiyonun içinde ve alt bloklarında geçerlidir. Örneğin fonksiyon içinde açılan `for` bloğunda da `k`'ye erişilebilir.
- **Blok kapsamı:** `for` bloğunun içinde tanımlanan `int y = 4;` yalnız o blokta ve onun alt bloklarında (örneğin içindeki `if` bloğunda) geçerlidir. `if` içinde tanımlanan bir değişken de blok kapsamlı olurdu.

Hoca kodun derleme hatası vermediğini gösterdi.

Kapsamlar iç içedir: en kapsayıcısı program kapsamı, altında dosya kapsamı, onun altında fonksiyon kapsamı, en içte blok kapsamı. Hoca bu şeklin yanıltmaması gerektiğini vurguladı: blok kapsamında tanımlanan bir değişkene dış kapsamlardan erişilemez. Örneğin `for` bloğundaki `y`'ye `main`'den ya da başka bir fonksiyondan erişilemez.

> **Ders sonrası not:** Hoca dosya kapsamlı `static` değişken için "bu C dosyasındaki herhangi bir fonksiyonu çağıracağımız zaman g her zaman için 3'e sıfırlanarak tekrar kullanılıyor olacak" dedi. Bu doğru değildir. Fonksiyon dışındaki `static` değişkene program başında bir kez ilk değer verilir; fonksiyon çağrılarında sıfırlanmaz. Buradaki `static`'in tek etkisi, değişkenin adını yalnız o dosyaya görünür kılmaktır (slayt: "For variables declared outside a function, the static keyword gives the variable file scope", ekrandan 01:55:00).

### 13.1 İç blokta aynı adlı değişken

Bir blokta tanımlanan değişken o bloğun dışından erişilemez. Gerekirse bir iç blokta aynı adla yeniden değişken tanımlanabilir. Bu durumda içteki ve dıştaki değişken bellekte farklı yerlerde saklanan ayrı değişkenlerdir. İçteki, dıştakini örter (ezer): iç blokta o ad kullanıldığında hep içteki kastedilir ve dıştakinin değerine iç bloktan erişilemez. Dıştakine erişmek gerekiyorsa içtekine başka bir ad verilmelidir.

Hoca bunun hata ayıklamada işe yarayabileceğini söyledi: bir döngü içinde hata ayıklama amaçlı tanımlanan bir değişken üstteki aynı adlı değişkeni örter; iyi ki de öyle yapar, yoksa hata ayıklama kodu programın asıl mantığını bozabilirdi.

## 14. Global Değişkenler, Tanım ve Anma

Slayttaki maddeler (ekrandan, 01:50:00):

- Genel olarak global değişkenlerden mümkün olduğunca kaçınılmalıdır:
  - Karmaşıklığı artırdıkları için programın bakımını zorlaştırırlar.
  - Modüller arasında çakışma olasılığı yaratırlar.
  - Tek avantajları daha hızlı kod üretmeleridir.
- İki tür bildirim vardır: tanım (definition) ve anma (allusion).
- Anma, tanım gibi görünür, ama değişken için bellek ayırmak yerine derleyiciye belirtilen türde bir değişkenin var olduğunu ve başka yerde tanımlandığını bildirir: `extern int j;`. `extern` anahtar kelimesi derleyiciye değişkenlerin başka yerde tanımlandığını söyler.

Hoca uyarıyı şöyle açıkladı: farklı fonksiyonlarda tanımlanan aynı adlı değişkenler global değişkenin adını örter; bazı fonksiyonlarda bu ad tanımlı değildir ve orada global olan kullanılır. Koda hâkimseniz karıştırmazsınız, ama uzun ve karmaşık bir kodda bir değişkenin global mi, dosya kapsamlı mı, yerel mi olduğunu düşünmek işi anlamayı ve çalışmayı zorlaştırır.

Fonksiyonlarda tanım ve anma farkı daha önce görülmüştü: fonksiyonun imzası önce verilip gövdesi sonra yazılabilir. Aradaki fonksiyonlar o fonksiyonu çağırabilir ve derleme hatası alınmaz. Yukarıdaki imza (anma) silinirse derleme yapılamaz. Tanım ise kodun bloğunu yazmaktır.

## 15. Saklama Sınıfları: register, extern, const, volatile

### 15.1 register

Bir değişkene çok sık erişiliyorsa onun normal RAM yerine, mikroişlemciyle aynı tümleşik devrede bulunan saklama alanlarında tutulması istenebilir. Bu alanlara yazmaç (register) denir. Sayıları azdır ama işlemciyle aynı devrede oldukları için erişimleri çok hızlıdır. Bu yüzden kritik bazı değişkenler ya da işaretçiler `register` olarak tanımlanabilir. Slaytta altı çizili olarak belirtildiği gibi derleyici bu isteği yok saymakta serbesttir (compiler is free to ignore it); yapabiliyorsa değerlendirir. Örneğin işletim sistemi işlemci yazmaçlarına doğrudan erişimi kapatmış olabilir.

Hoca bir uyarıda bulundu: ileride işaretçilerle değişkenin bellek adresi alınacak. Yazmaçların bellek adresi yoktur ve böyle bir değişkenin adresini almaya çalışmak sakıncalıdır. Ne olacağını (yalnız programın mı donacağını, sistemin mi çökeceğini) bilmediğini, derleyicinin büyük olasılıkla daha en baştan derleme hatası vereceğini umduğunu ve işaretçiler konusunda bunu deneyeceklerini söyledi.

> **Ders sonrası not:** C'de `register` olarak tanımlanan bir değişkenin adresi alınamaz; bu bir derleme hatasıdır. `register int r = 5; int *q = &r;` satırları gcc ile derlenince "address of register variable ‘r’ requested" hatası verdi. Yani program çalışma aşamasına hiç gelmez.

### 15.2 Saklama sınıfları özeti

Slayttaki özet (ekrandan, 01:55:00):

| Sınıf | Açıklama |
|---|---|
| `auto` | Gereksizdir, nadiren kullanılır. |
| `static` | Fonksiyon içindeki bildirimlerde değişkene sabit ömür verir. Fonksiyon dışında bildirilen değişkenlere dosya kapsamı verir. |
| `extern` | Fonksiyon içinde bildirilen değişkenler için global bir anma anlamına gelir. Fonksiyon dışındaki bildirimlerde global bir tanımı belirtir. |
| `register` | Değişkeni otomatik yapar, ayrıca derleyiciye mümkünse değişkeni bir yazmaçta saklaması için ipucu verir. |
| `const` | Değişkenin değerinin değiştirilemeyeceğini garanti eder. |
| `volatile` | Derleyicinin bazı optimizasyonları kapatmasını sağlar. Aygıt yazmaçları ve derleyicinin bilgisi dışında değişebilen diğer veri bölümleri için kullanışlıdır. |

Hocanın açıklamaları:

- `auto` belirsiz olduğu için üzerinde durulmadı.
- `static`, kapsamdan çıkıp geri gelindiğinde değişkenin son değerini tutmasını sağlar.
- `extern`, değişkenin ya da fonksiyonun üzerinde çalışılan dosyanın dışında başka bir kod dosyasında tanımlandığını belirtir.
- `register`, değişkenin değerinin mikroişlemciyle aynı devredeki özel saklama alanında tutulmasını ister.
- `const`: bir değişkene bir kez değer atanır ve bir daha değiştirilemez. Sonradan değer atamaya çalışan kod derleme aşamasında hatayla durdurulur.
- `volatile`: hoca pratikte pek kullanmadığını, değişkenin bellekte saklanmasıyla ilgili bazı optimizasyonları kapattığını söyledi.

> **Ders sonrası not:** Hoca `volatile`'ı, `main`'in durumu yığına itilirken volatile değişkenin bu bilgiye dahil edilmemesi ve değerin kaybedilmesi diye örneklendirdi. Bu açıklama doğru değildir. Slaytta da yazdığı gibi `volatile`, değişkenin derleyicinin bilgisi dışında değişebileceğini bildirir (ör. bir donanım yazmacı). Derleyici bu yüzden değeri bir yazmaçta önbelleğe almaz; değişkene her erişimde değeri bellekten yeniden okur ve her yazmayı belleğe yapar.

## 16. İşaretçilerin Temeli

Son aradan sonra diziler ve işaretçiler (pointer) konusuna geçildi. Plan: işaretçi temelleri, dizi ve işaretçi tanımları, dizilerin bellekte nasıl saklandığı, dizilere ilk değer verme, dizi elemanlarına işaretçiyle erişim. Temel uygulama alanı karakter katarları olacak, çünkü C'de string türü yoktur, yalnız karakter dizileri vardır. Daha sonra çok boyutlu dizilere kısaca değinilecek; örnekler bir ve iki boyutlu diziler üzerinden gidecek.

Bir değişken adının başında `*` görülürse o bir işaretçidir (yönlendirme değişkeni). İşaretçi arka planda bir tam sayıdır, çünkü bellek gözlerinin adresleri sayısal değerlerdir: sıfırıncı gözden başlar, ayrılan bayt kadar ilerler. Örneğin bir tam sayı 4 baytla tutuluyorsa işaretçi, o tam sayının bellekte saklanmaya başladığı noktayı gösterir.

### 16.1 "Basics" örneği

Slayttaki kod (ekrandan, 02:10:00):

```c
#include <stdio.h>
int main(int argc, char *argv[]) {
   short i,j; //short integers
   short *p;  //pointer to short
   i = 123;   //statement #1
   j = 321;   //statement #2
   p = &i;    //statement #3: p now shows the memory address of i
   j = *p;    //statement #4: * means: use the indirect (pointer) value of p
   printf("i:%d j:%d", i, j);
   i += 2; j += 3; printf("i:%d j:%d", i, j); //statement #5
   return 0;
}
```

Slaytın altında "What will happen?" sorusu var. Hocanın satır satır anlatımı:

- `i` ve `j` iki `short` tam sayıdır; 4 bayt yerine 2 baytta saklanırlar.
- `p`, bu değişkenlerden herhangi birini gösterebilecek, `short` türüne işaretçidir. İşaretçi olduğunu adının başındaki `*` gösterir.
- `i`'ye 123, `j`'ye 321 atanır.
- `p = &i;` ile `p`, `i`'nin saklandığı bellek adresini gösterir. `&` (ampersand) "saklandığı bellek adresi" diye okunur.
- `j = *p;` ile `j`'ye `p`'nin gösterdiği adresteki değer atanır. Burada `j = p` demek doğru olmaz, çünkü işaretçinin gösterdiği adresteki değer kullanılmak isteniyor.

Hoca önce "artık `i` de `j` de bellekte aynı yeri ifade ediyor; `i` 2, `j` 3 artınca ikisi de 128 olur" dedi. Kodu Dev-C++'ta çalıştırmadan önce kendisi düzeltti: işaretçinin gösterdiği yer değişebilir, ama değişkenlerin bellekteki yeri değişmez. `j = *p` yalnız değeri kopyalar.

Doğru sonuç: ilk `printf` `i:123 j:123` yazar. Sonra `i` 2 artıp 125, `j` 3 artıp 126 olur.

### 16.2 Bellek tablosu

Hoca slayttaki tabloyu adım adım anlattı (ekrandan, 02:25:00). Bellek bayt dizileri şeklindedir; `short` 2 bayt olduğu için tablodaki her kutu 2 baytlık bir alandır. İşletim sisteminin programa 1200 adresinden başlayan bir bellek alanı verdiği varsayılır; bu sayı tamamen rastgeledir ve her çalıştırmada farklı olur.

| Komut | `i` (adres 1200) | `j` (adres 1202) | `p` (adres 1204) |
|---|---|---|---|
| Tanımdan sonra | ? | ? | ? |
| #1, #2, #3 sonrası | 123 | 321 | 1200 |
| #4 sonrası | 123 | 123 | 1200 |
| #5 sonrası | 125 | 126 | 1200 |

- #3 sonrası: `p` 1204 numaralı gözde saklanır ve içinde `i`'nin adresi olan 1200 yazar. Hoca, `i`'nin adresiyle `p`'nin içeriğinin aynı sayı olduğunu kalın yazarak vurguladı.
- #4 sonrası: `p`'nin içindeki 1200 adresine gidilir, oradaki 123 okunur ve `j`'nin gözüne yazılır. İki gözdeki değer aynıdır ama gözler farklıdır; biri ötekinin aynısı değildir, yalnız değerleri eşittir.
- #5 sonrası: 1200'deki değer 123'ten 125'e, 1202'deki değer 123'ten 126'ya çıkar. `p`'nin içeriği değişmez.

Kod gcc -Wall ile derlendi ve çalıştırıldı (çıktıyı ayırmak için `before`/`after` ve `\n` eklendi): `before i:123 j:123`, `after i:125 j:126`.

### 16.3 Yıldızı unutursak

Hoca burada yapılabilecek bir hatayı gösterdi: `j = *p` yerine `j = p` yazmak. Bu durumda `j`'ye `p`'nin gösterdiği değer değil, `i`'nin adresinin sayısal değeri atanır. Derleyici tür güvenliği uyarısı verdi; hoca adresin 2 baytlık `short`'a sığmayacağını belirtip değişkenleri `int` yaptı ve `j = (int)p;` diye açık dönüşüm yazdı (ekrandan, 02:30:00). Çıktıda `i`'nin adresi olarak 37814028 gibi bir sayı göründü; `j += 3` sonrası 37814031 oldu.

**Soru:** Bu kodda adres değerini elle değiştirirsek ne olur? **Cevap:** `j = 2020` gibi bir atama yalnız `j`'nin gözündeki değeri değiştirir. İşaretçiye rastgele bir sayı atanırsa işaretçi bellekte o numaralı gözü gösterir, ama o göze erişim hakkımız olup olmadığını bilemeyiz; programın bellekte hangi alandan itibaren yerleştiği bilinmez. Hoca 2020 numaralı gözdeki değeri yazdırmayı denedi, ama istediği sonucu alamadı ve işaretçi aritmetiği konusunu çalıştıktan sonra bu soruya daha doğru cevap verebileceğini söyledi.

**Soru (öğrenci yorumu):** İşaretçinin `int` ile aynı boyutta olma zorunluluğu yokmuş; sayı atarken kayıp olduğu için onu adres gibi kullanamıyor olabilir. **Cevap:** Hoca olabileceğini, derleyicinin verdiği uyarıda bir hikmet olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** 64 bitlik sistemlerde işaretçiler genelde 8 bayt, `int` ise 4 bayttır. Bu yüzden bir adresi `int`'e dönüştürmek adresin üst bitlerini kaybettirebilir; derleyicinin uyarısı bundandır. Adresler `printf` ile `%p` biçim belirteciyle yazdırılır.

## 17. Diziler

Dizi tanımında önce elemanların türü (ör. tam sayılar için `int`), sonra dizinin adı yazılır. Köşeli parantez dizi simgesidir; içine dizinin kaç eleman alacağı yazılır, sonra noktalı virgül konur. Slayttaki sözdizimi (ekrandan, 02:35:00): tür belirteci → dizi adı → `[` → dizi boyutu → `]` → isteğe bağlı ilk değer listesi.

```c
int dailyTemp[365];
dailyTemp[0] = 38;
dailyTemp[0] = 23;
```

Hoca örneği sonbahara uygun sayılarla anlattı: dizinin ilk gözüne 18, ikinci gözüne 23 yazılır ve böyle devam edilir. Dizi indisleri 0'dan başlar (slayt: "subscripts begin at 0, not 1!").

> **Ders sonrası not:** Slaytta iki atama da `dailyTemp[0]` olarak yazılmış; büyük olasılıkla ikinci satırın `dailyTemp[1] = 23;` olması amaçlanmıştır. Hoca da anlatırken "ikinci gözüne 23" dedi.

### 17.1 Dizilerin bellekte saklanması

Slayttaki örnek (ekrandan, 02:40:00):

```c
int ar[5]; /* declaration */
ar[0] = 15;
ar[1] = 17;
ar[3] = ar[0] + ar[1];
```

| Eleman | Adres | İçerik |
|---|---|---|
| `ar[0]` | 0x1000 | 15 |
| `ar[1]` | 0x1004 | 17 |
| `ar[2]` | 0x1008 | tanımsız |
| `ar[3]` | 0x100C | 32 |
| `ar[4]` | 0x1010 | tanımsız |

Bellekte 0x1000 numaralı gözden itibaren boş yer olduğu varsayılır. Adresler on altılık (hexadecimal) düzendedir; hoca 1000'in onluk düzende bin olmadığını hatırlattı. `int` 4 bayt olduğu için her eleman bir öncekinden 4 bayt sonra gelir. `ar[3] = ar[0] + ar[1]` ile dördüncü göze 15 + 17 = 32 yazılır.

Slayttaki not: `ar[2]` ve `ar[4]` tanımsızdır; bu gözlerin içeriği önceki program çalıştırmasından kalan değerdir. Hoca iki olasılık saydı: işletim sistemi belleği programa vermeden önce sıfırlıyorsa 0 görünür, ama her işletim sistemi bunu yapmaz; genelde adres olduğu gibi verilir ve gözlerde başka programların bıraktığı değerler kalır. Bu değerler bize rastgele gelir, ama aslında o gözlerin daha önce nasıl kullanıldığına bağlıdır.

Derste yazılan kod (ekrandan, 02:45:00):

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int ar[5]; /* declaration */
    int i;
    ar[0] = 15;
    ar[1] = 17;
    ar[3] = ar[0] + ar[1];
    for( i=0; i<5; i++ )
        printf("%d ",ar[i]);

    system("PAUSE");
    return 0;
}
```

Çıktıda 15, 17 ve 32 doğru göründü; diğer iki gözde rastgele değerler vardı. Hoca farklı bir komut satırı penceresinde başka değerler bekledi, ama aynı değerler geldi ve işletim sisteminin ortak bir bellek alanı kullandırdığını yorumladı. İşin özü: içine değer atanmamış bellek gözlerinde önceden ne varsa o görünür.

> **Ek bilgi (derste anlatılmadı):** İlk değer verilmemiş yerel bir değişkeni okumak C standardında tanımsız davranıştır; değer çalıştırmadan çalıştırmaya, derleyiciden derleyiciye değişebilir. Bu yüzden bu programın 2. ve 4. elemanlar için yazdığı sayılar güvenilmezdir. Global ya da `static` diziler ise programın başında otomatik olarak 0 ile doldurulur.

### 17.2 Tanımla birlikte ilk değer verme

Dizi tanımlanırken eşittir işaretinden sonra süslü parantez içinde değerler yazılabilir. Hoca, 365 değeri tek tek yazmak uzun süreceği için bunun daha az elemanlı dizilerde kullanıldığını söyledi. Örnek olarak beş elemanlı bir diziye `1, 2, 3.5, 4.5, 5` gibi değerler verildi. Dizinin türü `int` olduğu için ondalıklı değerlerin ondalık kısmı yuvarlanmadan kesilip atılır; dizi 1, 2, 3, 4, 5 değerleriyle tek satırda hem tanımlanmış hem de ilk değerlerini almış olur.

<!-- BELİRSİZ: İlk değer listesinin slayttaki tam hali karede yok; altyazıda "1, 2, 3,5, 4,5" diye geçiyor. -->

Liste dizinin boyutundan kısa olursa ne olur? Hoca önce kalan elemanların tanımsız olacağını söyledi; bir öğrenci kalan elemanların 0 olacağını yazdı. Hoca bunu denedi: beş elemanlı bir diziye yalnız üç değer (3, 6, 9) verip bütün elemanları yazdırdı ve kalan elemanların gerçekten 0 olduğunu gördü. Boş bırakma yalnız sondan yapılabilir; baştan ya da ortadan eleman atlanamaz.

Değerler yazılarak tanım yapılıyorsa köşeli parantezin içine boyut yazmak zorunlu değildir. Derleyici listeye bakar: listede beş eleman varsa beş elemanlık, üç eleman varsa üç elemanlık yer açar. Boyut 5 yazılıp üç değer verilirse beş elemanlık yer açılır, ilk üçüne değerler atanır, kalanlar 0 olur. Her durumda köşeli parantezin kendisi yazılmalıdır, çünkü değişkenin dizi olduğunu o gösterir.

Bu davranış gcc -Wall ile denendi: `int c[5] = {3, 6, 9};` dizisi `3 6 9 0 0` yazdı; `int d[] = {1, 2, 3, 4, 5};` dizisinin boyutu 5 eleman çıktı.

## 18. Dizi Elemanlarına İşaretçiyle Erişim

Slayttaki örnek (ekrandan, 02:50:00):

```c
short ar[4];
short *p;

p = & ar[0]; // assigns the address of array element 0 to p.
```

- `short` elemanlı, `ar` adlı dört elemanlı bir dizi ve aynı türe işaretçi olan `p` tanımlanır.
- `p = &ar[0];` "`ar` dizisinin sıfırıncı indisli, yani ilk elemanının adresini al ve `p`'ye yaz" demektir. Bundan sonra `p` dizinin ilk elemanını, başka bir deyişle dizinin başlangıç noktasını gösterir.
- `p = ar;` yukarıdaki atamayla tamamen aynıdır; bir kısaltmadır.
- `*(p+3)`, `ar[3]` ile aynı bellek içeriğini gösterir.

Püf nokta: `p + 3` ifadesindeki 3 sayısal olarak 3 bayt değildir. `p` `short` türüne işaret ettiği için, arka planda 3 tane `short` kadar bayt eklenir. `ar[0]` 0x1000 adresindeyse `ar[1]` 0x1002'dedir (ara adım eklendi) ve `p + 3` 3 × 2 = 6 bayt ileriyi gösterir. Kısacası işaretçiye eklenen sayı, işaretçinin türünün kapladığı bayt sayısıyla çarpılır.

> **Hocanın vurgusu:** Buradaki 3, 3 bayt değildir. Dizinin türü, dolayısıyla işaretçinin türü kaç bayt ise o bayt çarpı 3'tür.

Bu, gcc ile denendi: `short ar[4] = {10, 20, 30, 40}; short *p = ar;` için `*(p+3)` ve `ar[3]` ikisi de 40 verdi; `p` ile `p+3` arasındaki fark 6 bayt çıktı.

### 18.1 Geçerli ve geçersiz atamalar

Slayttaki ikinci örnek (ekrandan, 02:50:00):

```c
float ar[5], *p;
...
p = ar ;          // legal
ar = p;           // illegal
&p = ar;          // illegal
ar++;             // illegal
ar[1] = *(p+3);   // legal
p++;              // legal
```

- `p = ar;` geçerlidir: işaretçi artık dizinin başlangıcını, yani ilk elemanını gösterir.
- `ar = p;` geçersizdir: dizi bellekte sabit bir yer olarak tanımlanmıştır. Dizinin beş elemanlık bloğunu "git, işaretçinin gösterdiği yere taşın" diye başka yere taşıyamayız. Taşımak gerekiyorsa hedefi gösteren başka bir işaretçi açılır ve elemanlar o adresten itibaren tek tek kopyalanır.
- `&p = ar;` geçersizdir: `&p`, `p` işaretçisinin kendisinin saklandığı gözün adresidir. Oraya bir dizi yazılamaz; hoca bunu elmayla armudu karşılaştırmaya benzetti: `p` tek birimlik bir öğe, `ar` beş birimlik.
- `ar++;` geçersizdir: dizinin elemanlarına ancak köşeli parantezle (ya da bir işaretçiyle) erişilir; dizi adı artırılamaz.
- `ar[1] = *(p+3);` geçerlidir: `p` dizinin başını gösterdiği için `*(p+3)` `ar[3]` demektir; dizinin 3 indisli gözündeki değer 1 indisli göze yazılır. `p = ar` ataması yapılmamış olsaydı `p` bilinmeyen bir yeri gösterecek ve sonuç bilinmeyen bir değer olacaktı.
- `p++;` geçerlidir: `p = p + 1` demektir. `p` hangi elemanı gösteriyorsa artık bir sonrakini gösterir. `p` 0 indisli elemanı gösterirken `p++` ile 1 indisli elemanı gösterir.

> **Ders sonrası not:** Hoca `float` için "8 bayt ile gösteriliyorsa 3 × 8 = 24 bayt ilerlemiş oluyor" dedi. Yaygın derleyicilerde `float` 4 bayttır (gcc ile `sizeof(float)` 4 çıktı); 8 bayt olan `double`'dır. Bu durumda `p + 3` 12 bayt, `p++` 4 bayt ilerler. Kural değişmez: ilerleme miktarı eleman boyutu çarpı adım sayısıdır.

### 18.2 *(p + i) ve dizi sınırı

`*(p + i)` gibi bir ifade, `i` işaretçi değil normal bir tam sayı değişken olduğu sürece rahatlıkla kullanılabilir. Ancak dikkat gerekir: `p = ar` ataması yapılmış ve dizi 5 elemanlı olsun. `i` çok büyükse dizinin dışına düşülür (slayttaki not: "If i is too large, we will drop off the array"). Örneğin `p++` ile `p` 1 indisli elemanı gösterirken `i = 10` alınırsa `p + i` dizinin 11 indisli yerini gösterir. Bu dizinin sınırlarının dışındadır; orada bellekte ne yazdığı bilinmez ve o değer dizinin elemanıymış gibi işlenirse algoritma doğru sonuç vermez.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Slayttaki alıştırma: "Try to expand min macro example for three numbers", yani `min` makrosunu üç sayının en küçüğünü bulacak şekilde genişletin.

> **Çözüm (derste verilmedi):** İki sayılık makro iç içe kullanılabilir:
>
> ```c
> #define MIN(a,b)     ((a) < (b) ? (a) : (b))
> #define MIN3(a,b,c)  MIN(MIN(a,b),c)
> ```
>
> `MIN3(7,2,5)` 2, `MIN3(4,9,1)` 1, `MIN3(2.5,1.5,3.0)` 1.5 verir (gcc -Wall ile derlenip denendi). Dikkat: iç içe açılımda argümanlar birden fazla kez değerlendirildiği için `MIN3(x++, y, z)` gibi yan etkili argümanlar 4. bölümdeki sorunu büyütür.

**Soru 2** (ekrandan, 00:30:00): `int x = 3, y = 10;` iken `printf("min: %d\n", MIN(x++,y));` ardından `x` ve `y` yazdırılırsa çıktı ne olur? Aynısı `min(x++,y)` fonksiyonuyla yapılırsa?

Çözüm (derste verildi): Makroyla `min: 4`, `x: 5`, `y: 10`; fonksiyonla `min: 3`, `x: 4`, `y: 10`. Makro `((x++) < (y) ? (x++) : (y))` olarak açıldığı için `x++` iki kez çalışır.

**Soru 3** (ekrandan, 01:15:00): 10. bölümdeki koşullu derleme kodunda `#define x 1` iken çıktı nedir? `x` 2 ve 5 olursa ne değişir?

Çözüm (derste verildi): `x` 1 için `main x: 1`, `myFunc x: 0`. `x` 2 için `main`'de 2, `myFunc`'ta 3. `x` 5 için ikisinde de 5 ve `#else` dalı yüzünden `y` 4 olarak tanımlıdır. `x` 1 iken `myFunc`'ta `y` kullanılırsa derleme hatası alınır.

**Soru 4** (ekrandan, 01:30:00): `increment()` fonksiyonu (`int j = 1; static int k = 1; j++; k++;`) üç kez çağrılırsa ekrana ne yazar?

Çözüm (derste verildi): `j:2 k:2`, `j:2 k:3`, `j:2 k:4`. `j` her çağrıda yeniden 1 olur; `k`'ye yalnız ilk çağrıda ilk değer verilir.

**Soru 5** (ekrandan, 02:10:00): "Basics" kodu için "What will happen?" İki `printf` ne yazar?

Çözüm (derste verildi): `i:123 j:123`, ardından `i:125 j:126`. `j = *p` yalnız `i`'nin değerini `j`'nin gözüne kopyalar; `i` ve `j` ayrı gözlerdir.

**Soru 6** (ekrandan, 02:45:00): `int ar[5]; ar[0] = 15; ar[1] = 17; ar[3] = ar[0] + ar[1];` sonrası döngüyle bütün elemanlar yazdırılırsa ne görülür?

Çözüm (derste verildi): `ar[0]`, `ar[1]`, `ar[3]` için 15, 17, 32; `ar[2]` ve `ar[4]` için bellekte önceden kalan, önceden bilinemeyen değerler.

**Soru 7** (derste sözlü, 02:44:43): Beş elemanlı bir dizi tanımlanırken süslü parantez içinde yalnız üç değer verilirse kalan iki eleman ne olur?

Çözüm (derste verildi): Hoca denedi; kalan elemanlar 0 olur. Boş bırakma yalnız sondan yapılabilir.

**Soru 8** (derste sözlü, 02:26:46): "Basics" kodunda `j = *p` satırındaki yıldız silinirse ne olur?

Çözüm (derste verildi): `j`'ye `p`'nin gösterdiği değer değil, `i`'nin bellek adresinin sayısal değeri atanır. Derleyici tür uyarısı verir; derste bu değer 37814028 gibi bir sayı olarak göründü.

**Soru 9** (ekrandan, 02:50:00): `float ar[5], *p;` için `p = ar;`, `ar = p;`, `&p = ar;`, `ar++;`, `ar[1] = *(p+3);`, `p++;` atamalarından hangileri geçerlidir?

Çözüm (derste verildi): Geçerli: `p = ar;`, `ar[1] = *(p+3);`, `p++;`. Geçersiz: `ar = p;`, `&p = ar;`, `ar++;`.

## Dersin Toparlaması

Bu derste önce ön işlemci ele alındı. Makrolar derleme öncesinde metin olarak yerine konur. Bu sayede fonksiyon çağrısı yükü olmaz ve tek makro farklı türlerle çalışır; buna karşılık tür denetimi yoktur, argümanlar birden çok kez değerlendirilebilir (`MIN(x++, y)` örneği), kod büyür ve hata ayıklama zorlaşır. Bu yüzden makrolar ancak özel durumlarda kullanılmalıdır. `#undef`, hazır makrolar (`__LINE__`, `__FILE__`, `__DATE__`, `__TIME__`, `__STDC__`), koşullu derleme komutları (`#if`, `#elif`, `#else`, `#endif`, `#ifdef`, `#ifndef`) ve `#include`'un iki biçimi de görüldü. Ardından kapsam ve ömür kavramları ayrıldı. `static` ile yerel bir değişkenin değerinin çağrılar arasında korunacağı, dört kapsam türünün iç içe olduğu, global değişkenlerden kaçınılması gerektiği ve `register`, `extern`, `const`, `volatile` niteleyicileri anlatıldı.

Son bölümde işaretçilere ve dizilere giriş yapıldı. `&` adres, `*` dolaylı değer demektir; `j = *p` değeri kopyalar, değişkenleri birleştirmez. Diziler bellekte ardışık saklanır ve indisler 0'dan başlar. Değer atanmayan elemanlar tanımsızdır, eksik ilk değer listesinde ise kalan elemanlar 0 olur. `p = ar`, `*(p+3) == ar[3]` ve `p++` ile işaretçi aritmetiğine ilk adım atıldı; işaretçiye eklenen sayının eleman boyutuyla çarpıldığı vurgulandı. Hoca sonraki derste işaretçi konusunu kısaca tekrar edip örneklere, ardından işaretçiler kullanılarak yazılacak kabarcık sıralaması (bubble sort) ve seçmeli sıralama (selection sort) gibi algoritmalara geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
