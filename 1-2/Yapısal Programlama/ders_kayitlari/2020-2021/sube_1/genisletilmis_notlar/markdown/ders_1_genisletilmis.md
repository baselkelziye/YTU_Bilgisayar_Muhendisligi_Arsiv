# Ders 1 Genişletilmiş Notu: Derse Giriş ve C Dilinin Temelleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Kapsamı
- 2. Program Geliştirme: Derleyici, Bağlayıcı ve Çalışma Zamanı Kitaplığı
- 3. Değişkenler, Sabitler ve Bellek
- 4. İsimlendirme Kuralları
- 5. Ayrılmış Anahtar Kelimeler
- 6. İfadeler ve Atama
- 7. Yorumlar
- 8. Fonksiyonlar
- 9. Kaynak Kodun Biçimlendirilmesi
- 10. main() Fonksiyonu ve exit()
- 11. printf() ve scanf()
- 12. Önişlemci, #define ve #include
- 13. İlk Program: Hello World ve Dev-C++
- Örnek Sorular

## 1. Dersin Amacı ve Kapsamı

Yapısal Programlama dersi, giriş dersinde öğrenilen yapısal programlamanın bir adım ötesine geçer. Amaç, bir yapısal programı daha iyi tasarlayıp kodlamak için C dilinin sunduğu araçları tanıtmak ve bunlarla ilgili beceri kazandırmaktır. Uygulama dili C'dir.

Ders önce kısa bir hatırlatmayla başlayacak: C'deki veri tipleri, işlemler, kontrol deyimleri, `for` ve `if` gibi yapılar hızlıca gözden geçirilecek. Ardından öğrencileri zorlayan asıl konulara geçilecek. Ekrandaki ders içeriği şöyledir (ekrandan, 00:20:00):

- Hatırlatma: C'de veri tipleri, bitsel işlemler, kontrol deyimleri, döngüler, diziler
- İşaretçiler: işaretçi aritmetiği, diziler ve işaretçiler, işaretçi dizileri, karakter dizileri, işaretçilerin işaretçisi
- Dinamik bellek yönetimi ve fonksiyonlar, fonksiyon işaretçileri, özyineleme
- Yerel ve global değişkenler, depolayıcı sınıflar, yapılar, birlikler
- Dosya işlemleri
- C önişlemcileri ve makrolar
- Statik ve dinamik kütüphaneler

### 1.1 Konuların kısa tanıtımı

**İşaretçiler (pointer).** Hoca bu konu üzerinde özellikle duracaklarını söyledi. Kendisi öğrenciyken işaretçileri kolay kavrayamadığını, ama bir kez kavrandıktan sonra rahatça kullanılabildiğini anlattı. İşaretçi, bellekteki bir gözü gösterir; bu sayede o gözün hem içeriği hem de bellek adresi istenildiği gibi kullanılabilir. Başlı başına bir konu olan işaretçi aritmetiği de işlenecek. Diziler, dizi kavramı yerine işaretçiler üzerinden de erişilip kullanılabilir.

**Karakter dizileri.** C'de ayrı bir string türü yoktur; string aslında bir karakter dizisidir. String'lerin uzunluğu çoğu zaman önceden bilinmediği için sabit genişlikli diziler yerine genişleyebilen bir bellek alanı işaretçi üzerinden kullanılır. Hoca, işaretçilerin işaretçisi olabildiğini "inception modunda" diye esprili bir benzetmeyle anlattı. Bütün bunların asıl amacı dinamik bellek yönetimi becerisi kazandırmaktır.

**C'nin gücü.** Hoca C'yi çok güçlü, alt düzey bir dil olarak tanımladı: kullanılan makinenin en alt düzey yeteneklerini bile doğrudan kullanmaya izin verir. Bu, dile karmaşıklık getirir, ama başka dillerde yapılamayan önemli işler C'de yapılabilir. İşaretçiler yalnız değişkenlere değil fonksiyonlara da tanımlanabilir, çünkü program kodu da bellekte bir yerde durur ve kodun başlangıç noktasına bir işaretçi edinilebilir.

**Özyineleme (recursion).** Bir fonksiyonun kendi kendini çağırmasıdır. Farklı bir algoritmik düşünme biçimi ister. Bazı problemleri özyinelemeyle çözmeyi tasarlamak daha zor olabilir, ama ortaya çıkan kod daha etkin olabilir.

**Kapsam (scope), struct ve union.** Değişkenlerin kod içinde görünür olduğu bölgeye kapsam denir; bu anlamda yerel ve global değişkenler işlenecek. `struct` ve `union` yapılarında belleğin verimli kullanılması için alanların farklı tanımlanma yolları görülecek.

**Dosya işlemleri, önişlemci ve makrolar.** C'de dosya erişim kipleri (metin kipi, ikili kip), sıralı ve rastgele erişim ayrıntılı işlenecek. Bir iş fonksiyonla yapılabileceği gibi makroyla da yapılabilir; bu konu da görülecek. Statik ve dinamik kütüphane bağlantılarına ise zaman kalmayabilir.

Hoca bu konuların birbirine geçmiş olduğunu, en iyi tek bir anlatım sırası bulunmadığını söyledi. Konular kabaca bu sırayla anlatılacak, gerektiğinde geri dönülecek.

### 1.2 Kaynaklar

Temel kaynak Darnell P. A. ve Margolis P. E., *C: A Software Engineering Approach*, 3. baskı, Springer-Verlag, 1996'dır (ekrandan, 00:20:00). Hoca kitabın eski olduğunu, ama C'nin de eski bir dil olduğunu belirtti. Kitabı almak gerekmez; aynı konuları anlatan herhangi bir C kitabıyla ek çalışma yapılabilir. Ders notları (yaklaşık 300 yansı) önceki yıllarda başka hocaların katkısıyla hazırlanmış, hoca tarafından düzeltilip genişletilmiştir.

**Soru:** Yapısal programlama sadece C'ye mi özgüdür? **Cevap:** Hayır. Ama sektörde en yaygın kullanılan yapısal programlama dili C'dir. Eskiden Pascal'ın da önemli bir yeri vardı; programlamaya giriş bir zamanlar Pascal ile öğretilirdi. Java gibi nesneye yönelik bir dil de hiç sınıf kullanmadan, yalnızca fonksiyonlarla yapısal mantıkla kullanılabilir, ama bu, iş için yanlış aracı seçmek olur.

## 2. Program Geliştirme: Derleyici, Bağlayıcı ve Çalışma Zamanı Kitaplığı

### 2.1 Derleme ve bağlama

C derlenen bir dildir. Metin olarak yazılan `.c` uzantılı kaynak dosyalar derleyiciden geçirilir ve bir ya da daha fazla nesne (object) dosyası elde edilir. Her kaynak dosya bir nesne dosyasına (`.o`) dönüşür. Bu nesne dosyaları bir araya getirilerek çalıştırılabilir kod üretilir.

Slayttaki şema bu süreci gösterir (ekrandan, 00:35:00): üç kaynak dosyadan üç nesne dosyası çıkar; bu nesne dosyaları ve çalışma zamanı kitaplığı (runtime library) bağlayıcıya (linker) girer; bağlayıcının çıktısı çalıştırılabilir koddur (executable code). Slayttaki maddeler:

- Derleyicinin görevi kaynak kodu makine koduna çevirmektir.
- Derleyicinin girdisi kaynak kod, çıktısı nesne koddur.
- Bağlayıcı ayrı nesne dosyalarını tek bir dosyada birleştirir.
- Bağlayıcı gerekirse çalışma zamanı kitaplığındaki fonksiyonları da ekler.
- Bağlama genellikle otomatik yapılır.

Hoca bu mekanizmanın alt düzey olduğunu, C'nin kendi içinde farklı standartları bulunduğunu ve ayrıntıların derleyiciye ve bağlayıcıya göre değişebildiğini vurguladı. Bağlama genelde otomatik olur, ama takılınan yerlerde araya girip düzeltmek gerekebilir.

### 2.2 Çalışma zamanı kitaplığı ve başlık dosyaları

C'nin küçük bir çekirdeği vardır. C ile işe yarar bir şey yapmak için geniş bir çalışma zamanı kitaplığına ihtiyaç duyulur. Slayttaki açıklama (ekrandan, 00:40:00): C'nin bu kadar küçük bir dil olmasının nedenlerinden biri, birçok işlemi büyük bir çalışma zamanı kitaplığına bırakmasıdır. Kitaplık nesne dosyalarından oluşur; her dosya geniş bir hizmet yelpazesinden birini yapan bir fonksiyonun makine komutlarını içerir. Fonksiyonlar G/Ç, bellek yönetimi, matematiksel işlemler ve karakter dizisi işlemleri gibi gruplara ayrılır. Her grup için, bu fonksiyonları kullanmak için gereken bilgiyi içeren bir **başlık dosyası** (header file) vardır; geleneksel olarak adı `.h` ile biter.

Başlık dosyalarında yalnızca kitaplığın sunduğu fonksiyonların imzaları, tanımları bulunur. Programcı bu dosyayı `#include` ile ekleyince, kodunda o fonksiyonları derleme hatası almadan kullanabilir. Asıl kod bağlama aşamasında projenin geri kalanına eklenir ve program bütün olarak çalışır.

En basit örnek ekrana bir satır yazdırmaktır. `printf()` fonksiyonu `stdio.h` kitaplığındadır; bunu kullanmak için kaynak dosyaya `#include <stdio.h>` satırı yazılır. `stdio`, "standard input output" kısaltmasıdır: kullanıcıdan bilgi almak ve kullanıcıya bilgi vermek. Hoca bu tür kısaltmaların nedenini anlattı: eski işletim sistemleri, özellikle DOS, en fazla 8 karakterlik dosya adı ve 3 karakterlik uzantı destekliyordu.

### 2.3 Platform bağımlılığı

Çalışma zamanı kitaplıkları üzerinde çalışılan işletim sistemine, hatta mikroişlemcinin ayrıntılarına bağlıdır. Bu, bilinmesi gereken bilginin derinliğini artırır. C'nin kendi içinde de farklı standartları vardır ve farklı standartlar, farklı işletim sistemi sürümlerinde ve farklı işlemcilerde farklı davranabilir. <!-- BELİRSİZ: hocanın saydığı standart adları altyazıda bozuk ("Antisistik standartı", "C, 80, C, 90"); büyük olasılıkla ANSI C ve C89/C90 kastediliyor. -->

C'nin küçük bir dil olması, gömülü sistemlerde ve sınırlı kaynaklı işlemcilerde verimli çalışan kod yazmayı sağlar. Ama bu alanda çalışacak biri, kullanacağı kitaplıkların her ayrıntısına hâkim olmak zorundadır.

Hoca derste Dev-C++ 4 IDE'sini kullanacağını söyledi. Örnekler bu IDE'de proje oluşturulup kaydedilerek, çalıştırılıp çıktısı görülerek, sonra kod değiştirilip "şöyle yaparsak ne olur" diye farklı açılardan denenerek anlatılacak. Kimi durumlarda komut satırı kullanmak gerekecek; çünkü IDE yaklaşık 20 yıllık bir programdır ve o sürede işletim sistemleri, güncellemeler ve antivirüs programları çok değişmiştir.

## 3. Değişkenler, Sabitler ve Bellek

Herhangi bir değişken kullanılmadan önce tanımlanmalıdır. Örneğin `j = 5 + 10` gibi bir işlemden önce `int j;` diyerek `j`'nin türü bildirilir. Sonra bu komut verildiğinde ifade hesaplanır ve sonuç `j`'ye atanır; `=` atama işlecidir.

Veriler sabit ya da değişken olarak ele alınabilir. Sabite bir kez değer verilir ve bu değer bir daha değişmez. Değişkene ise türü kaç bayt ile gösteriliyorsa bellekte o kadar baytlık alan ayrılır.

Bellek, gösterim kolaylığı için birbirini izleyen kutucuklar olarak çizilir. İşletim sisteminin sağladığı çalışma ortamındaki bellek uzayında ilk adres 0'dır: 0. bayt, 1. bayt, ... örneğin 2486. bayt. Derleyici o anda uygun ve boş gördüğü bir yere değişkeni yerleştirir. Programcı "bu değişkeni belleğin şu gözüne koy" diye komut veremez, ama değişkenin bellekteki adresini öğrenebilir, yani ona bir işaretçi alabilir. Böylece ileriki haftalarda görülecek pek çok işlem yapılabilir. Kısacası `j` değişkenine verilen ad mantıksal bir addır; değişken bellekte bir adres aralığında saklanır ve bir başlangıç noktası vardır.

## 4. İsimlendirme Kuralları

C dilinde, dilin kendi anahtar kelimeleri dışında hemen her şey isim olarak kullanılabilir. Değişkenler, sabitler, fonksiyonlar ve ileride görülecek yapılar isimlendirilir. Slayttaki kurallar (ekrandan, 00:45:00):

- C'de hemen her şey isimlendirilebilir: değişkenler, sabitler, fonksiyonlar, hatta programdaki bir konum.
- İsimler harf, rakam ve alt çizgi (`_`) içerebilir, ama harf ya da alt çizgiyle başlamalıdır.
- C büyük-küçük harfe duyarlıdır (case sensitive): `VaR`, `var`, `VAR`.
- İsim, ayrılmış anahtar kelimelerden biriyle aynı olamaz.

**Program konumu (etiket).** Kaynak koddaki belirli bir komutu gösteren bir etiket tanımlanabilir. Hoca bunun yapılmamasını istedi: etiket kullanmanın tek nedeni oraya `goto` ile atlamaktır.

> **Hocanın vurgusu:** `goto` bu derste kesinlikle yasaktır. Yapısal programlamanın düzenini alt üst eden, kodu karmakarışık hale getiren bir uygulamadır. "Yapabilirsiniz ama yapmıyoruz."

**Başlangıç karakteri.** İsim rakamla başlayamaz. "Birinci sayı" anlamında `1sayi` denemez, ama `sayi1` denebilir. Hocanın örnekleri: `j` ve `c5` geçerli, `5j` geçersizdir. `$` ya da `#` ile de başlanamaz. `#` önişlemci komutlarının başlangıcıdır, `%` mod alma işlecidir, `*` işaretçi işlecidir, `@` da kullanılamaz. Alt çizgiyle başlayan isimler ve büyük harf kullanılabilir.

**Büyük-küçük harf duyarlılığı.** Bir değişken `VaR` diye tanımlandıysa hep böyle erişilir. `var` ve `VAR` ayrı değişkenler olarak tanımlanabilir; üçü üç ayrı değişkendir. Yalnızca küçük harfle `var` tanımlanıp sonra büyük harfle `VAR` kullanılırsa derleyici, böyle bir değişken tanımlanmadığı için hata verir.

**Anahtar kelimeler.** `int` tam sayı türünü tanımlamak için ayrılmış bir kelimedir; bir değişkenin adı `int` olamaz.

**Türkçe karakter.** Değişken ve fonksiyon adlarında Türkçe karakter kullanılmaz; ciddi uyumsuzluklara yol açar, program derlenmeyebilir bile. String içinde Türkçe karakter kullanılabilir, ama IDE ya da komut satırı bunları genellikle bozuk karakter olarak gösterir.

## 5. Ayrılmış Anahtar Kelimeler

Slayttaki tablo (ekrandan, 00:50:00):

| | | | |
|---|---|---|---|
| auto | double | int | struct |
| break | else | long | switch |
| case | enum | register | typedef |
| char | extern | return | union |
| const | float | short | unsigned |
| continue | for | signed | void |
| default | goto | sizeof | volatile |
| do | if | static | while |

Hoca listedeki kelimeleri tek tek açıkladı:

- `break`: bir döngüden, iç içe döngülerde en içteki döngüden çıkmak için kullanılır.
- `case`: `switch`-`case` yapısı, bir değişkenin değeri şuysa böyle yap, buysa şöyle yap diye dallanır.
- `char`: karakter veri tipi. `const`: sabit değişken.
- `continue`: `break` ile birlikte anılır; döngüde devam etmeyi sağlar.
- `default`: hoca önce hatırlayamadı; bir öğrencinin hatırlatmasıyla, `switch` yapısında hiçbir `case`'e girilmezse yapılacak iş olduğunu söyledi.
- `do`, `while`: döngüler. `double`: ondalıklı veri tipi. `if`, `else`: karar yapısı.
- `enum`: bir değişkenin yalnızca belirli değerleri alması istendiğinde kullanılır. Hocanın örneği giysi bedeni: small, medium, large, x-large; başka değer olamaz. Bu yapı ders kapsamında büyük olasılıkla görülmeyecek.
- `extern`: kullanılan bir değişkenin ya da fonksiyonun başka bir kaynak kod dosyasında tanımlı olduğunu belirtir.
- `float`: ondalıklı tür. `for`: döngü yapısı.
- `goto`: kesinlikle kullanılmayacak.
- `long`: iki kat bellek alanı ayrılan değişken. `int` 2 ya da 4 bayt olabilir ve bu işletim sistemine bağlıdır. `int` 2 bayt ise `long int` 4 bayt, `int` 4 bayt ise `long int` 8 bayt olur. Kullanılan C standardının `int`'i nasıl tanımladığı da ayrı bir etkendir.
- `register`: bellek hiyerarşisinde işlemciye RAM'den bile yakın, işlemci çipinin içindeki en hızlı ama en dar ve bu yüzden en pahalı bellek türü yazmaçtır. Değişken yazmaç değişkeni olarak tanımlanabilir. Bu konu Bilgisayar Mimarisi dersinde görülecek.
- `return`: fonksiyondan değer döndürür.
- `short`: değişkenin boyutunu yarıya indirir. Örneğin `int` 2 bayt ama değişkenin alacağı değerler 1 bayta sığıyorsa ve kaynaklar kısıtlıysa `short int` kullanılabilir.
- `signed`: sayısal değişkenin artı-eksi işaretinin olup olmamasıyla ilgilidir. `unsigned` bunun tersidir; işaret olmadığında o alan da değer aralığına katılır. Örneğin yalnız pozitif değer alacak bir sayıda kullanılabilir.
- `sizeof`: bir yapının kaç baytlık alan kapladığını verir; özellikle işaretçi işlemlerinde gerekecek.
- `struct`, `union`: aynı varlıkla ilgili farklı türden verileri bir araya getirip bir kayıt yapısı oluşturur. Son haftalara doğru görülecek. Bunun bir ötesi, veriye fonksiyonları da ekleyip bir nesne haline getirmektir; bu da sonraki dönemin nesneye yönelik programlama dersinin konusudur.
- `typedef`: tanımlanan `struct` ya da `union`'a özel bir ad verip onu böyle kullanmayı sağlar.
- `void`: geriye değer döndürmeyen fonksiyonun türüne verilen addır.
- `volatile`: hoca emin olmadığını belirterek "değeri sadece o anda kullan, sonra saklama" gibi bir anlamı olduğunu söyledi ve bilmediği bir şeyi söylemek istemediğini ekledi.

> **Ders sonrası not:** Hoca `float` için "ondalıklı tam sayı türü" dedi. `float` kayan noktalı bir türdür, tam sayı türü değildir.

> **Ders sonrası not:** Hoca `unsigned` ile "bir bayttan tasarruf edildiğini" söyledi. Kazanılan, işaret için ayrılan tek bir bittir; bu bit de değer aralığına katılır. Örneğin 8 bitlik işaretli bir tür −128 ile 127, işaretsiz tür 0 ile 255 arasında değer alır.

> **Ders sonrası not:** `volatile`, değişkenin değerinin programın denetimi dışında (donanım, kesme, başka bir iş parçacığı) değişebileceğini bildirir. Derleyici bu değişkene her erişimde değeri bellekten yeniden okur ve bu erişimleri optimize ederek kaldırmaz. Hocanın verdiği anlam bununla örtüşmüyor.

> **Ek bilgi (derste anlatılmadı):** Listede açıklanmadan geçilen `auto`, yerel değişkenlerin varsayılan depolama sınıfıdır ve blok bitince değişkenin ömrü de biter; bu yüzden pratikte nadiren yazılır. `static` ise yerel bir değişkenin değerini fonksiyon çağrıları arasında korumasını ya da global bir ismin yalnız kendi dosyasında görünmesini sağlar. İkisi de ders içeriğindeki "depolayıcı sınıflar" başlığına girer.

## 6. İfadeler ve Atama

Bir C ifadesinde işleçlerin, sayıların ve isimlerin herhangi bir birleşimi kullanılabilir. Hocanın örnekleri:

- `5`: sayısal bir sabittir. Derleyici bunu kendisine ayrılan bir yere yazar ve değişmeyeceğini bildiği için optimizasyon yapabilir. Örneğin küçük sabitleri `short int` gibi daha dar bir yere koyabilir, hatta en fazla iki bayt tutan iki sabiti tek bir tam sayılık yere sıkıştırabilir. Programcı da isterse bir baytı iki yarım olarak düşünüp kod yazabilir; C bütün bunlara izin verir.
- `j`: bir değişkendir. Daha önce bir yerde türüyle tanımlanmış olması gerekir. Bunun bir fonksiyon olmadığı bilinir, çünkü fonksiyon çağrısında parantez çifti bulunur.
- `5 + j`: bir aritmetik işlemdir. `+` toplama işlecinin iki işleneni vardır: biri sabit `5`, öteki değişken `j`.
- `f()`: bir fonksiyon çağrısıdır. Fonksiyon parametre almasa bile, onu değişken ifadesinden ayırmak için parantez gerekir.
- `f()/4` benzeri bir ifade, fonksiyon çağrısıyla aritmetik işlemi birleştirir. Derleyici önce fonksiyonu çağırır, dönen değeri 4 sabitine böler, çıkan sonucu da varsa atama ile bir değişkene yazar. <!-- BELİRSİZ: slayttaki son ifadenin tam yazımı karede görünmüyor; altyazıdan fonksiyon çağrısının 4'e bölündüğü anlaşılıyor. -->

### 6.1 Atama işleci

Atama işleci `=`'dir; solunda bir hedef, sağında bir ifade bulunur ve her C komutu gibi noktalı virgülle biter. Sağ taraf (right value, rvalue) hesaplanır, sonuç sol tarafın (left value, lvalue) gösterdiği yere yazılır.

Sol taraf mutlaka bir bellek adresine çevrilebilen bir ifade olmalıdır. Bu bir değişken olabilir; o zaman sonuç değişkenin bellek adresine yazılır. İleriki haftalarda görüleceği gibi bir işaretçi de olabilir. Örneğin iki sayının çarpımı bir değişkene yazılabilir, ama sol tarafı bir bellek adresine karşılık gelmeyen bir atama yazılamaz.

## 7. Yorumlar

Slayttaki maddeler (ekrandan, 01:15:00):

- Yorum, kaynak dosyaya kodun ne yaptığını açıklamak için eklenen metindir. Yorumlar insan okuyucular içindir, derleyici onları yok sayar.
- C, `/*` ve `*/` sembolleri arasına yorum yazmaya izin verir.
- İç içe yorum desteklenmez.
- Neye yorum yazılır: fonksiyon başlığına ve koddaki değişikliklere.

Slayttaki fonksiyon başlığı yorumu örneği:

```c
/* square()
 * Author : P. Margolis
 * Initial coding : 3/87
 * Params : an integer
 * Returns : square of its parameter
 */
```

Hoca, ileride bir yazılım şirketinde çalışırken uyulması gereken bir kodlama standardı olacağını anlattı. Standart her fonksiyonun başında yazarın, ilk kodlama tarihinin, parametrelerin, dönüş değerinin ve fonksiyonun ana hatlarıyla yaptığı işin yazılmasını istiyorsa, takım oyuncusu olup yazılım geliştirme sürecini aksatmamak için bu biçime uyulur.

Hoca bir de soru sordu: bir `/* ... */` yorumunun içine bir `/* ... */` çifti daha konabilir mi? Konamaz; yorumlar iç içe yazılamaz.

## 8. Fonksiyonlar

### 8.1 Söz dizimi

Slayttaki şema fonksiyon tanımının söz dizimini gösterir (ekrandan, 01:20:00): fonksiyon türü → fonksiyon adı → `(` → argümanlar → `)` → `{` → tanımlar (declarations) → C deyimleri (statements) → `}`. Slayttaki maddeler:

- C fonksiyonu, C dili işlemlerinin bir topluluğudur. Dilin hazır işlemlerinden daha karmaşık bir işlem yapar, ama aynı zamanda anlaşılması zor olacak kadar karmaşık olmamalıdır.
- Argümanlar, çağıran fonksiyondan çağrılan fonksiyona aktarılan verilerdir.

**Fonksiyon türü**, fonksiyon bir hesaplama yapıp geriye değer döndürüyorsa döndürdüğü değerin türüdür. **Fonksiyon adı** anlamlı olmalıdır. Hoca burada kısaltma kullanılmamasını istedi: gerekirse ad uzun olsun, yeter ki anlaşılır olsun. Parantez içinde, fonksiyon parametre alacaksa bunlar listelenir; almayacaksa bile parantez çifti gereklidir. Her parametre türü ve adıyla yazılır, örneğin `int katsayi`, `float oran`. Sonra süslü parantez bloğu içinde fonksiyonun kodu yazılır.

Fonksiyon bloğunun içinde ek tanımlar yapılabilir. Bunların ömrü o blokla sınırlıdır: fonksiyon içinde `int i` diye tanımlanan bir değişken fonksiyon bitene kadar yaşar.

### 8.2 Neden fonksiyon?

Fonksiyonun mantığı, belli bir amaca yönelik işlemleri yapan komutları bir arada tutmak ve böylece modüler kod yazmaktır. Her şey `main` içinde de yazılabilir, ama orada yapılan anlamlı alt işlere hem aynı kodun başka yerlerinde hem de daha sonra yazılacak kodlarda yeniden ihtiyaç duyulabilir.

Slayttaki maddeler (ekrandan, 01:25:00):

- Kendi fonksiyonlarınızı yazabilirsiniz ve yazmalısınız!
- Bir alt işi yapan deyimleri bir fonksiyon altında toplamak modüler yazılım sağlar.
- Fonksiyonlar farklı programlarda yeniden kullanılabilir.
- Fonksiyonlar, bir hata düzeltmesi ya da değişiklik isteği çıktığında programın birçok yerinde düzeltilmesi gereken yinelenen kodu önler. Hatalar ve gereksinim değişiklikleri yazılım geliştirmede kaçınılmazdır.

Hoca kopyala-yapıştırın sakıncasını şöyle anlattı: aynı kod birçok yere yapıştırılmışsa ve sonra bu kodda bir hata fark edilirse, düzeltmek için "bunları nereye yapıştırmıştım" diye tek tek aramak gerekir; bul-değiştir genelde çözüm olmaz.

Hoca ileriki haftalar için bir not da düştü: argümanların aktarım yönü önemli bir ayrıntıdır. İşaretçi kullanılmazsa aktarım tek yönlü, işaretçi kullanılırsa çift yönlü olur.

### 8.3 Fonksiyon ne kadar uzun olmalı?

Hoca uzun ve karmaşık fonksiyonlar yerine odaklanmış kısa fonksiyonlar yazmayı önerdi. Sihirli bir sayı yoktur; hocanın göz kararıyla 30 satırlık bir fonksiyon fazla uzun, 10 satır civarı makul bir ortalamadır. Ama bu uzunluk hem kullanılan dile hem de problem alanına bağlıdır. C'de bir iş için daha fazla alt ayrıntı bilmek ve daha fazla komut yazmak gerekebilirken, Java gibi bir dilde tek bir metot çağrısı arka planda pek çok komutun çalışmasına yol açabilir. Karmaşık bir problem alanında bazı fonksiyonlar ister istemez uzun kalabilir.

Öte yandan 2-3 satırlık bir fonksiyon da değmez. Her fonksiyon çağrısı sisteme bir ek yük getirir; 2-3 komutluk işler için fonksiyon yerine makro yazmak daha yararlı olabilir. Makrolar ile fonksiyonların karşılaştırması ileriki haftalarda görülecek.

Hoca kısa fonksiyonların bilişsel bir yararını da anlattı: insan karmaşık bir problemle uğraşırken aynı anda en fazla 7±2 parçayı aklında tutabilir. Hoca kendisi gibi ayrıntıyı az tutabilenler için bunun 5'e indiğini, çok odaklanmış biri için 7-9'a çıktığını esprili biçimde söyledi. Bu yüzden 30-40 satırı aynı anda anlamaya çalışmak zordur. Ama 30 satırlık bir kod A, B, C işlerini yapan 10'ar satırlık üç fonksiyona bölünürse, önce ana fonksiyonun ne yaptığı görülür; sorun A işindeyse yalnızca A fonksiyonuna bakılır.

> **Ek bilgi (derste anlatılmadı):** Hocanın andığı "7±2" sınırı, psikolog George A. Miller'ın 1956'daki ünlü makalesine dayanır ve kısa süreli belleğin aynı anda tutabildiği öğe sayısına ilişkindir. Sonraki çalışmalar bu sayının büyük olasılıkla daha düşük (yaklaşık 4) olduğunu ileri sürmüştür.

### 8.4 Kullanmadan önce tanımlama ve allusion

Bir fonksiyon kullanılmadan önce tanımlanmalıdır. Farklı C standartları bu konuda esneklik sağlıyor olabilir, ama buna güvenilmemelidir.

Hocanın örneğinde kombinasyon hesaplayan bir `combination` fonksiyonu vardı ve başka bir fonksiyon bu fonksiyonu çağırıyordu. İki seçenek vardır:

- `combination` fonksiyonu, ona ihtiyaç duyan bütün fonksiyonlardan daha yukarıda yazılır.
- Ya da önce fonksiyonun imzası verilir. Kitap buna **allusion** der. İmzada parametre adları gerekmez, türleri yeterlidir. Aşağıda fonksiyonun tanımı yazılırken parametre adları verilmek zorundadır. İmza yukarıda verildikten sonra, kodun daha aşağısındaki fonksiyonlar bu fonksiyonu çağırabilir ve derleme hatası alınmaz.

<!-- BELİRSİZ: combination fonksiyonunun slayttaki imzası altyazıda bozuk ("İnt, a, int, bir tane parametre alıyor"); bu anın karesi yok. Büyük olasılıkla iki int parametreli bir imza. -->

> **Ek bilgi (derste anlatılmadı):** Bugün "allusion" yerine genellikle "fonksiyon prototipi" ya da "bildirim (declaration)" terimi kullanılır, örneğin `int combination(int, int);`. Fonksiyonun gövdesini içeren kısım ise "tanım (definition)" diye adlandırılır.

## 9. Kaynak Kodun Biçimlendirilmesi

Derleyici kaynak kodun nasıl biçimlendirildiğine bakmaz. Biçimlendirme, programcının ve ekip arkadaşlarının kodu anlayabilmesi içindir.

Slayttaki örnek, bir sayının karesini alıp döndüren `square` fonksiyonunun üç farklı yazımını karşılaştırır (ekrandan, 01:30:00). Doğru kabul edilen yazım:

```c
int square (num) {
        int answer;
        answer = num * num;
        return answer;
}
```

Yanlış kabul edilen iki yazımdan birinde bütün satırlar girintisiz, sola yaslıdır. Ötekinde ise `int` ile `answer;` ayrı satırlara bölünmüş, `answer = num` ile `* num;` farklı satırlara ve rastgele girintilere dağıtılmıştır. Fonksiyon bir geçici değişken tanımlar, ona sayının karesini yazar ve onu döndürür. Hoca `return num * num;` diye de yazılabileceğini, örneğin girintilemeyi göstermek için seçildiğini söyledi.

Genel kural (rule of thumb): bir süslü parantez açıldığında, sonraki satırlar bir sekme içeriden yazılır. Kodun içine döngüler, `if`, `for`, `while` girdikçe her yeni blokta bir sekme daha içeri girilir. Süslü parantezin fonksiyon imzasıyla ya da `if`/`for` ile aynı satırda mı, bir alt satırda mı açılacağı ya kişisel tercihtir ya da çalışılan ekibin veya firmanın kodlama standardının belirlediği bir şeydir. Her durumda açılan parantezden sonraki satırların girintili yazılması kodun anlaşılırlığını artırır. Öte yandan bir ifadeyi gereksiz yere çok fazla satıra bölmek de doğru değildir.

> **Hocanın vurgusu:** Okunabilirliği artıracak her şeye sıkıca sarılmak gerekir. Hoca öğrencilerden geçen yıl yazdıkları ödevlerin kaynak koduna dönüp bakmalarını istedi: ödev çok basit değilse, kodu kendileri yazmış olsalar bile ilk bakışta anlayamayacaklarını söyledi. İnsan bir projeyi tek oturuşta bitiremez; girintileme ve yorumlar, kaçınılmaz olarak çıkacak hataları düzeltirken işi kolaylaştırır.

> **Ders sonrası not:** Slayttaki `int square (num)` yazımında parametrenin türü yazılmamıştır. Bu, eski K&R stilidir ve parametrenin `int` olduğu varsayılır. Bu yazım `gcc -std=c89` ile derlenir, ama gcc 15'in varsayılan modunda `type of 'num' defaults to 'int'` hatası verir (ajan tarafından denendi). Güncel C'de `int square(int num)` yazılmalıdır.

## 10. main() Fonksiyonu ve exit()

`main` özel bir fonksiyondur: C programının çalışmaya başladığı noktadır. Program çalıştırılınca önce `main`'in ilk komutu yürütülür.

Slayttaki örnek (ekrandan, 01:35:00):

```c
int main ( ) {
        extern int square();
        int solution;
        solution = square(5);
        exit(0);
}
```

Slayttaki maddeler:

- `exit()` fonksiyonu, programı bitirip denetimi işletim sistemine geri veren bir çalışma zamanı kitaplığı rutinidir.
- `exit()`'e verilen argüman sıfırsa program hatasız, normal biçimde bitiyor demektir.
- Sıfırdan farklı argümanlar programın anormal sonlandığını gösterir.
- `main()` içinden `exit()` çağırmak, `return` deyimini yürütmekle tamamen aynıdır.

Hoca `exit()`'in nerede işe yarayacağını şöyle örnekledi: komut satırında dönen bir menüsü olan bir uygulamada, kullanıcı "çıkış" seçeneğini seçtiğinde program `exit` ile sonlandırılabilir. Sıfırdan farklı bir değer, programın bir hata ya da olumsuzluk nedeniyle çıktığının işaretidir; bu değerin nerede tutulduğu ve kaydının nasıl izlendiği ayrı programlara ya da IDE'nin desteğine bağlıdır. Programın akışı zaten son komutta bitiyorsa `exit` yazmak şart değildir: slayttaki `main`, `square(5)` çağrıldıktan sonra `exit` olmasa da normal biçimde kapanır. `main`'den `return` ile dönmek de bir kodlama geleneğidir.

Slayttaki parçalar güncel yazımla tam bir programa dönüştürüldü. Bu birleştirme ve `printf` satırı derste yazılmadı; program ajan tarafından `gcc -Wall` ile derlendi ve çalıştırıldı, çıktı `square(5) = 25` oldu:

```c
#include <stdio.h>
#include <stdlib.h>

int square(int num);   /* allusion (prototip) */

int main(void) {
    int solution;
    solution = square(5);
    printf("square(5) = %d\n", solution);
    exit(0);
}

int square(int num) {
    int answer;
    answer = num * num;
    return answer;
}
```

## 11. printf() ve scanf()

`scanf` bir girdi fonksiyonudur: herhangi bir türden bir değişken için kullanıcıdan, komut satırından ya da (ileride görüleceği gibi) dosyadan veri almaya yarar. `printf` ise ekrana bir şeyler yazdırır. İkisi de `stdio.h` kitaplığındadır; kullanmak için bu dosya `#include` ile eklenmelidir. Hoca söz diziminin biraz karışık olduğunu, bu yüzden hatırlatmak istediğini söyledi.

Slayttaki örnek (ekrandan, 01:40:00):

```c
int num;
scanf("%d", &num);
printf("num : %d\n", num);
```

### 11.1 scanf

`scanf`'in iki parametresi vardır. Birincisi biçim dizgisidir (format string). İkincisi değer atanacak değişkendir, ama aslında değişkenin kendisi değil, adresidir. Değişken bellekte bir yerde saklanır ve o yerin bir adresi vardır; `scanf` bu adresi bekler. "Kullanıcıdan okuyacağın veriyi `num` değişkeninin gösterdiği adrese yaz" diyebilmek için değişkenin başına `&` konur; `&` adres anlamına gelir. Değişken `*` ile tanımlanmış bir işaretçiyse `&` yazılmaz, çünkü işaretçi zaten bellekte bir alanı gösterir.

Biçim dizgisi, kullanıcının girdiği verinin nasıl yorumlanıp neye çevrileceğini belirtir. `%d`, verinin tam sayı olarak yorumlanacağı anlamına gelir. Değişken zaten `int` tanımlanmışken buna neden gerek olduğu sorusunu hoca şöyle cevapladı: C çok esnektir. Kullanıcı örneğin büyük `A` harfini girerse, bilgisayar belleğinde harfler de sayıyla tutulduğu için (ASCII kodu) bu 65 olarak değişkene yazılabilir. Her yetenek bir bedelle gelir; bu esnekliğin bedeli karmaşıklıktır. Bu yüzden "girilen veriyi tam sayı olarak yorumla" demek için `%d` gerekir.

### 11.2 printf

`printf`'in ilk parametresi yazılacak metindir ve içinde biçim belirteçleri bulunabilir. İsteğe bağlı olarak ikinci, üçüncü, ... n tane parametre daha verilebilir. `printf` metinde gördüğü her biçim belirteci için sıradaki parametreyi alır: birinci belirteç ikinci parametreyle, ikinci belirteç üçüncü parametreyle eşleşir ve bu böyle zincirleme ilerler. Veri tiplerinin hangi biçim belirteçlerine karşılık geldiği birkaç yansı sonra (bir sonraki derste) listelenecek.

Slayttaki maddeler:

- `printf()` istenen sayıda argüman alabilir.
- İlk argümana biçim dizgisi denir. Çift tırnak içine yazılır ve metin ile biçim belirteçleri içerebilir.
- `scanf()`, `printf()`'in aynadaki görüntüsüdür. Terminale yazmak yerine klavyeden girilen veriyi okur. İlk argümanı bir biçim dizgisidir.
- `scanf()` ile `printf()` arasındaki temel fark, veri argümanlarının lvalue olması gerektiğidir.

Hoca son maddeyi şöyle açıkladı: `scanf`'in veri argümanı, bir değerin saklanabileceği bir alan olmalıdır. <!-- BELİRSİZ: hoca burada "num + num gibi bir işlem de sonuçta hesaplanıp left value olarak kullanılabilir" dedi; bu ifade lvalue tanımıyla örtüşmüyor, altyazı da karışık. -->

> **Ders sonrası not:** `num + num` bir lvalue değildir; sonucu bir değerdir ama saklanabileceği bir adresi yoktur, bu yüzden `scanf`'e ya da atamanın soluna verilemez. lvalue, `num` gibi bellekte bir yeri gösteren ifadedir.

### 11.3 Kaçış dizileri

`printf` içinde ters bölü (`\`) ile başlayan karakterler özel karakterlerdir: ters bölü görüldüğünde bir sonraki karaktere bakılır ve ikisi birlikte yorumlanır. Bunlara kaçış dizisi (escape sequence) denir. `\n` yeni satır, `\t` sekme demektir. Benzer biçimde `%` ve ardından gelen karakter de birlikte bir biçim belirteci oluşturur.

Slayttaki parçalar `main` içine konup tam program yapıldı (birleştirme ajan tarafından yapıldı). `gcc -Wall` ile derlendi; `7` girdisiyle `num : 7` çıktısı alındı:

```c
#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);
    printf("num : %d\n", num);
    return 0;
}
```

## 12. Önişlemci, #define ve #include

### 12.1 Önişlemci nedir?

Her C kodunda ister istemez önişlemci (preprocessor) kısmına ihtiyaç vardır. Bir fonksiyonu başka bir fonksiyondan çağırabilmek için bile onun önceden tanımlanmış olması gerekir. Bu tanımların ve daha sonra bağlayıcı tarafından koda eklenecek kitaplıkların derleyici tarafından önceden gözden geçirilmesi gerekir. Bu aşamaya yönelik komutlara önişlemci komutları denir; `#` ile başlarlar.

Hoca bağımlılığı şöyle açıkladı: A, B'ye ihtiyaç duyuyorsa (fonksiyon olabilir, değişken tanımı olabilir), B A'dan önce tanımlanmalı ya da B'nin tanımı verilmelidir. Yoksa derleyici A'yı derlerken "burada B'ye ihtiyacım var, ama B'yi henüz tanımıyorum" deyip hata verir. Bunu önlemek için önceden bakılır, ileride B'nin tanımının olacağı bilinir.

Slayttaki maddeler (ekrandan, 01:45:00):

- Önişlemci, program derlenirken kendiliğinden çalışır.
- Bütün önişlemci yönergeleri `#` ile başlar; `#` satırdaki boşluk olmayan ilk karakter olmalıdır.
- C deyimlerinin aksine önişlemci yönergesi noktalı virgülle değil, yeni satırla biter.
- Önişlemci ayrıca makro işleme, koşullu derleme ve hazır makrolarla hata ayıklama da yapabilir.

`#` ile başlayan bir yönerge, yeni satır karakteri görülene kadar tek bir komut sayılır; araya noktalı virgül konamaz.

> **Ders sonrası not:** Hoca önişlemci komutlarının "programın ilk satırları olmak zorunda" olduğunu söyledi. Slayttaki kural, `#`'in satırdaki boşluk olmayan ilk karakter olmasıdır. Önişlemci yönergeleri büyük olasılıkla dosyanın herhangi bir yerinde bulunabilir; `#include` satırlarının başa yazılması bir gelenektir ve içeriği kullanılmadan önce eklenmesi gerektiği içindir.

### 12.2 Koşullu derleme

Hoca bu konunun üzerinde durmayacaklarını, yalnızca ne olduğunu anlatacağını söyledi. Bir yazılım daha geliştirme aşamasındayken programcı ona test fonksiyonları, komut ve veri akışını izlemek için komutlar ekler. Program tamamlanıp kullanıma verilirken bunlara ihtiyaç kalmaz. Koşullu derlemeyle "hata ayıklama (debug) kipinde derlenirse bunu da kat, uygulama kipinde katma" denebilir. Derleme sırasında IDE'de ya da komut satırında bir debug parametresi verilirse test komutları da derlenir; müşteriye verilecek sürüm bu bayrak olmadan derlenir ve daha yalın bir kod üretilir. Bu yetenekler Ant gibi başka araçlarla da sağlanabildiği için derste bu konuya girilmeyecek.

### 12.3 #define

Slayttaki maddeler (ekrandan, 01:50:00):

- `define` olanağıyla bir isim bir sabitle eşleştirilebilir: `#define NOTHING 0`
- Sabitler için bütün harfleri büyük yazmak yaygın bir uygulamadır.
- Sabitleri adlandırmanın iki önemli yararı vardır: anlamsız bir sayıya açıklayıcı bir ad verir ve programı değiştirmeyi kolaylaştırır.
- Sabitleri değişken gibi kullanmamaya dikkat edilmelidir: `NOTHING = j + 5` yanlıştır.

Hocanın örneği: bir kullanıcının yaşı girilmemiş olabilir. Sıfır yaşında bir bebek kullanıcı da olabileceği için bu durum arka planda örneğin −1 ile tutulur. Ama kod başka bir sistemde de kullanılacaksa ve o sistem girilmemiş alanı 0 ile gösteriyorsa, `NOTHING` bir sistemde −1, ötekinde 0 olarak tanımlanır. Kodun her yerinde girilmemiş alan için `NOTHING` kullanılır. Sabit kullanılmasaydı ve kod "0 ise veri girilmemiştir" diye yazılsaydı, başka bir sisteme taşırken bütün 0'ları −1'e çevirmek gerekirdi; kafadan bütün sıfırları değiştirmek de 10 gibi sayıların içindeki sıfırı bozabilirdi.

Büyük harf kullanımı sabitleri göze çarpan, kolay fark edilen hale getirir. Ayrıca "0" tek başına bir anlam taşımazken `NOTHING` adı onun "girilmemiş alan" olduğunu söyler; bu da anlaşılırlığı artırır.

### 12.4 #include

C'nin geniş bir çalışma zamanı kitaplığı vardır, ama kullanılacak kitaplık parçası koda dahil edilmelidir. Bunun için önişlemci aşamasında `#include` komutu kullanılır. Başlık dosyasının adı ya küçüktür-büyüktür işaretleri (`< >`) ya da çift tırnak (`" "`) içinde verilir. Bu ikisinin önemli bir farkı vardır:

- `< >` kullanılırsa derleyici, işletim sisteminin ona bildirdiği özel bir dizine gidip dosyayı orada arar.
- `" "` kullanılırsa dosya, yazılan kaynak dosyayla aynı dizinde olmalıdır. Orada değilse göreli yol (örneğin `../dizin/dosya.h`) verilebilir.

Ayrıntılar IDE'den IDE'ye ve C standardına göre değişebilir. Pratikte derleyici dosyayı aynı dizinde bulamazsa sistem dizinine de bakabilir, bakmayabilir de. Dev-C++'ta IDE ve derleyici birlikte bir paket halinde geldiği için derleyiciye nereye bakacağı söylenmiştir; bu yüzden `< >` yeterlidir. Hoca bu tür ayrıntıların sistemden sisteme değişmesinin, C'nin taşınabilirliğinin yüksek olmamasının nedenlerinden biri olduğunu söyledi: C hedef platforma çok bağlıdır ve bu bağımlılığın kaynak kod düzeyinde etkileri büyüktür.

> **Ders sonrası not:** Hoca `< >` ile verilen dosya bulunamazsa "linker hatası" alınacağını söyledi. Başlık dosyası bulunamazsa hata büyük olasılıkla önişleme/derleme aşamasında verilir ("No such file or directory"). Linker hatası, bildirimi bulunan bir fonksiyonun kodu bağlama sırasında hiçbir nesne dosyasında ya da kitaplıkta bulunamadığında görülür.

## 13. İlk Program: Hello World ve Dev-C++

### 13.1 Program

Slayttaki program (ekrandan, 01:55:00):

```c
#include <stdio.h>

int main ( void ) {
        printf("Hello World...\n");
        return 0;
}
```

Slayttaki açıklamalar: `#include <stdio.h>` standart girdi-çıktı kitaplığını ekler; `int main(void)` programın başlangıç noktasıdır; `return 0;` çağıran programa bir değer döndürür, bu durumda başarıyı göstermek için 0.

Hoca satır satır açıkladı. Önce `printf` kullanılabilsin diye standart girdi-çıktı kitaplığı eklenir. `main`'in birden fazla tanımlama biçimi vardır ve fark parametre listesindedir: program daha ilk komutu çalışmadan önce ona dışarıdan parametre aktarmak isteniyorsa bu parametreler `main`'in parametreleri olur. Bu konuya girilmedi; parametre almayan biçim kullanıldı. Program ekrana değişken içermeyen bir mesaj yazar, `\n` ile alt satıra geçer ve sonlanır. Sonlanma `exit(0)`, `return 0` ile ya da hiçbir şey yazmadan olabilir. Ama `main` `int` olarak tanımlandığı için kullanılan C standardı bir değer döndürülmesini zorunlu tutabilir; o zaman `return 0` yazılır.

Bu program ajan tarafından `gcc -Wall` ile derlendi ve çalıştırıldı; çıktısı `Hello World...` oldu.

### 13.2 Dev-C++ kurulumu ve kullanımı

Hoca Dev-C++'ın 4. ve 5. sürümlerinin bulunduğunu, 4. sürümü daha rahat kurup kullandığı için onu tercih ettiğini söyledi; öğrenciler başka bir IDE ya da derleyiciye alışkınsa onu kullanabilir. Bloodshed Dev-C++ kendi içinde MinGW derleyicisini barındırır, ayrı bir derleyici indirmeye gerek yoktur.

Kurulumla ilgili ipuçları:

- Program yaklaşık 20 yıllık olduğu için antivirüs programları kurulumda ya da çalışırken şüpheli davranabilir. Programı güvenilir uygulamalar listesine eklemek gerekebilir.
- Hoca programı `C:\DevCpp4` gibi kısa adlı bir dizine kurdu, `Program Files` gibi bir yere kurmadı. Eski derleyiciler boşluklu ve uzun yol adlarını sevmez, hata verebilir.
- İlk çalıştırmada simge dizininin bulunamadığına dair bir hata çıkarsa, kurulum dizinindeki simge klasörünün adını değiştirmek (`Icons` ↔ `Icon`) çözüm olabilir.

Proje oluşturma adımları: File → New Project → Console Application (Windows uygulaması değil), dil olarak C seçilir ve projeye bir ad verilir. Hoca eski DOS 8+3 adlandırmasına uygun kısa bir ad (D01P01) seçti ve projeyi kurulum dizinindeki bir `code` klasörüne kaydetti (ekrandan, 02:00:00 ve 02:05:00). IDE, `stdio.h`'yi ekleyen, `main`'i ve `return 0;`'ı içeren hazır bir iskelet verir. Henüz `.c` dosyası oluşmamıştır, yalnızca proje dosyası vardır; bu yüzden önce kaydetmek gerekir.

> **Hocanın vurgusu:** Kodu yansılardan kopyalayıp yapıştırırken dikkat edin. Yansıdaki çift tırnaklar tipografik tırnaklardır (“ ”); C düz çift tırnak (`"`) ister. Bu, gözden kaçabilecek bir ayrıntıdır; tırnaklar klavyeden yeniden yazılmalıdır.

Derlemeden önce dosya kaydedilir. Compile düğmesi kodu derler; arka planda bağlayıcı da çalışır. Hata yoksa program çalıştırılır. Ama çalıştırılınca bir pencere açılıp hemen kapanır: yazı ekrana yazılır ve pencere hemen kaybolur. Programın doğru çalışıp çalışmadığını görmek için iki yol vardır:

- **Komut satırından çalıştırmak.** Hoca `cmd` ile komut istemini açtı, `cd \DevCpp4\code` ile proje dizinine geçti (Tab tuşu ile otomatik tamamlama), `.exe` dosyasını çalıştırdı ve `Hello World...` çıktısını gördü (ekrandan, 02:05:00). Pencere komut satırından açıldığı için kapanmadı.
- **Programın sonunda bir tuşa basılmasını beklemek.** `return 0;`'dan önce bir tuş bekleyen komut eklenir. Hoca bunun için `conio.h` kitaplığındaki bir fonksiyonu kullandı ve programı yeniden çalıştırınca pencere açık kaldı (ekrandan, 02:10:00). <!-- BELİRSİZ: fonksiyonun adı altyazıda "Pulse", "geç yaş" diye bozuk geçiyor; bağlamdan büyük olasılıkla getch(). Kodun yazıldığı an karelerde görünmüyor. -->

Hoca bazı sistemlerde bu bekleme komutunun bir kez yazılmasının yetmediğini, önceki yıl bir Windows sürümünde iki kez yazmak gerektiğini anlattı. Bir öğrenci, Dev-C++ 5.11'de `return 0;` ile bırakıldığında pencerenin zaten beklediğini söyledi. Hoca bir deneyimini de paylaştı: bir sınav sorusunun çözümü, aynı işletim sistemini ve aynı IDE'yi kullanan iki hocanın bilgisayarında farklı davranmış, birinde doğru çalışıp ötekinde hata vermişti. C ile çalışırken bu düzeyde ince ayrıntılarla uğraşmak gerekebilir.

Ekranda IDE'nin otomatik girintisinin fazla içeriden başladığı da görüldü; hoca girintinin önemini anlattığı için bunu düzeltti.

> **Ek bilgi (derste anlatılmadı):** `conio.h` ve `getch()` standart C'nin parçası değildir; DOS/Windows derleyicilerine özgüdür ve Linux'ta gcc ile derlenmez. Taşınabilir bir bekleme için `stdio.h` içindeki `getchar()` kullanılabilir. Ancak önceki bir `scanf` girdisinden tamponda kalan yeni satır karakteri `getchar()`'ı hemen geçirebilir; büyük olasılıkla hocanın "bazen iki kez yazmak gerekiyor" dediği durum da buna benzer bir tampon etkisidir.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:22:22): Yapısal programlama sadece C diline mi özgüdür?

Derste verilen cevap: Hayır. Sektörde en yaygın kullanılan yapısal programlama dili C'dir; eskiden Pascal da yaygındı. Nesneye yönelik bir dil (örneğin Java) da sınıf kullanmadan yalnızca fonksiyonlarla yapısal biçimde kullanılabilir, ama bu, iş için yanlış aracı seçmek olur.

**Soru 2** (derste sözlü, 00:49:32 ve 00:50:01): `switch` yapısında `default` anahtar kelimesi ne işe yarar?

Derste verilen cevap (bir öğrencinin hatırlatmasıyla): `switch` içindeki `case`'lerin hiçbiri tutmazsa çalışacak kısmı belirtir.

**Soru 3** (derste sözlü, 01:16:24): Bir `/* ... */` yorumunun içine ikinci bir `/* ... */` yorum çifti konabilir mi?

Derste verilen cevap: Konamaz; C'de iç içe yorum desteklenmez (slaytta da "Nested comments are NOT supported" yazar, ekrandan, 01:15:00).

**Soru 4** (ekrandan, 00:45:00 ve derste sözlü, 00:47:36): Aşağıdaki isimlerden hangileri geçerli C değişken adıdır: `j`, `c5`, `5j`, `$x`, `_tmp`, `int`?

Derste verilen cevap: `j` ve `c5` geçerli, `5j` geçersizdir (rakamla başlar). `$` ile başlanamaz. Alt çizgiyle başlayan isimler geçerlidir. `int` ayrılmış anahtar kelime olduğu için kullanılamaz.

## Dersin Toparlaması

Bu ilk derste önce dersin kapsamı tanıtıldı: işaretçiler, dinamik bellek yönetimi, fonksiyon işaretçileri, özyineleme, kapsam, `struct`/`union`, dosya işlemleri ve önişlemci, dersin ana konularıdır. Ardından C'nin temelleri hatırlatıldı. Kaynak dosyalar derlenip nesne dosyalarına dönüşür, bağlayıcı bunları çalışma zamanı kitaplığıyla birleştirir. Başlık dosyaları fonksiyon imzalarını taşır. İsimlendirme kuralları ve anahtar kelimeler, ifadeler ve lvalue/rvalue ayrımı, yorumlar, fonksiyonların söz dizimi ve neden kısa ve odaklanmış olmaları gerektiği, kullanmadan önce tanımlama (allusion), girintileme, `main` ve `exit`, `printf`/`scanf` ve biçim dizgileri, önişlemcinin `#define` ve `#include` yönergeleri işlendi. Ders, Dev-C++ ile ilk "Hello World" programının derlenip çalıştırılmasıyla bitti.

Hoca bir sonraki derste kısa bir tekrarla başlayıp kalınan yerden, veri tipleri ve biçim belirteçlerinin listesiyle devam edeceklerini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
