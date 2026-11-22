# Ders 6 Genişletilmiş Notu: Önişlemci, Depolama Sınıfları ve İşaretçilere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yeri ve sık yapılan hatalar
- 2. Önişlemci ve makrolar
- 3. Fonksiyon benzeri makrolar ve yan etki
- 4. Makrolar ve fonksiyonlar
- 5. #undef, hazır makrolar ve koşullu derleme
- 6. #include ve #line
- 7. Depolama sınıfları: kapsam ve ömür
- 8. Kapsam türleri
- 9. Global değişkenler, extern, register, const, volatile
- 10. İşaretçilere giriş
- 11. Dev-C++ uygulaması: adresler, işaretçiler ve işaretçi aritmetiği
- Örnek Sorular

## 1. Dersin yeri ve sık yapılan hatalar

### 1.1 Yapısal programlama neye odaklanır?

Hoca derse, bu dersin önceki dönemlerde alınan temel bilgisayar bilimleri ve algoritma dersleri ile "Yapısal Programlamaya Giriş" dersinin üzerine kurulduğunu hatırlatarak başladı. Bu ders bir veri yapıları ya da algoritma analizi dersi değildir; ödevler ileri algoritma bilgisi istemez. Yapısal programlama dersinin asıl amacı C dilini farklı problemlerle karşılaşarak öğrenmek, programlama dillerinin mantığını kavramaktır: bellek sorunları, veri yapılarıyla ilgili problemler ve programı daha modüler hale getirmek bu dersin ana konularıdır. Hoca, basit algoritmik beceriye örnek olarak "Fibonacci dizisini yazdırmak" gibi işleri verdi; ödevler bu tür becerilerin üzerine yeni bilgiler ekleyerek sorgular.

### 1.2 Artık kabul edilmeyen hatalar

Hoca, öğrencilerin C ile en az üçüncü kez karşılaştığını, bu yüzden bazı hataların artık "ilk kez C gören birinin hatası" sayılmayacağını söyledi ve örnekler verdi (ekrandan, 00:20:00):

- **Döngü başında tanım.** `for (int i = 0; ...)` biçimi öğrencinin kendi bilgisayarında, dosya büyük olasılıkla C++ olarak kaydedildiği için derlenir; ama derste kullanılan C derleyicisinde değişken önce yukarıda tanımlanmalıdır.
- **`=` ile `==` karışıklığı.** `if (a = 5)` derlenir ve çalışır, ama sonuç yanlış çıkar. Hoca bunun neden derlendiğini ilerleyen derslerde göreceklerini söyledi.
- **`scanf`'te `&` unutmak.** Ödevde `scanf` satırında `&` bile yoksa bu dersin en temel gereksinimi karşılanmamış demektir.
- **`static` ile sıfırlama.** Dizinin içi boş olsun diye başına `static` yazmak yaygın bir hatadır. `static` değişkenin değerlerini sıfırlar ama başka etkileri de vardır (bkz. Bölüm 7); sıfırlamak için gereken ilk değer verme yazılmalıdır.
- **Global değişken.** Yapısal programlamada global değişken kullanılmaz; değerler fonksiyonlar arasında parametreyle aktarılır. Hoca bunun yalnız bölümün kuralı olmadığını, Java gibi dillerde de değişkenin kullanıldığı yerde tanımlanmasının istendiğini söyledi.

> **Ders sonrası not:** "C'de `for (int i = 0; ...)` yok" kuralı C89/C90 standardı için doğrudur; C99 ve sonraki standartlar bu yazıma izin verir. Kural büyük olasılıkla derste kullanılan derleyici ayarlarından kaynaklanır.

## 2. Önişlemci ve makrolar

### 2.1 Önişlemci nedir?

Bugünkü konu önişlemcidir (ekrandan, 00:10:00). Hoca, şimdiye kadar hiç kod tasarlamadıklarını, programların yapılarını analiz ettiklerini hatırlattı. Önişlemci yönergeleri genellikle `main` öncesinde yazılan, `#` ile başlayan (`#define`, `#include` gibi) ve derleme öncesinde işlenen satırlardır. Bu bölümün konuları: makro yerine koyma (macro substitution), makronun tanımlanması ve kaldırılması, makrolarla fonksiyonların karşılaştırılması, hazır makrolar, koşullu derleme, `#include` ve satır denetimi.

### 2.2 Makro yazım kuralları

Ekrandaki slayt (ekrandan, 00:25:00):

- Bütün önişlemci yönergeleri `#` (pound sign) ile başlar; `#` satırdaki boşluk olmayan ilk karakter olmalıdır.
- C deyimlerinden farklı olarak makro komutu noktalı virgülle değil, satır sonuyla biter.
- Makroyu birden fazla satıra yaymak için satır sonundan hemen önce ters bölü (`\`) konur.

```c
#define LONG_MACRO "This is a very long macro that \
spans two lines"
```

`#define`'dan sonra bir etiket (makro adı), bir boşluk ve etiketin yerine geçecek metin yazılır. Hoca, slayttaki örneğin sonuna noktalı virgül konmayacağını çizerek gösterdi.

### 2.3 Makro nasıl çalışır? "Makro bize gelir"

Programın içinde `LONG_MACRO` bir `printf` ya da bir string fonksiyonu içinde kullanılabilir. Derleme öncesinde bu adın yerine tanımın karşılığı kopyalanır. Hoca bunu fonksiyon çağrısıyla karşılaştırdı: `scanf` gibi bir fonksiyon çağrıldığında programda bir dallanma (jump) olur, ilgili fonksiyonun bulunduğu yere gidilir. Makroda tersi olur: makro bizim onu çağırdığımız yere gelir. Hoca bunu "birbirinin tam simetriği" diye tanımladı ve önemli bir ayrım olduğunu vurguladı.

> **Hocanın vurgusu:** Makro sizin çağırdığınız yere gelir; fonksiyonda ise siz onun tanımlandığı yere gidersiniz. Bu ayrımı çok iyi yapın.

### 2.4 Sayısal sabit tanımlama

Makronun en çok kullanıldığı amaç sayısal sabitlere ad vermektir. Hoca `BUFFER_LEN` adlı bir etiketle örnek verdi:

```c
#define BUFFER_LEN 512
char buf[BUFFER_LEN];
```

Önişlemci `BUFFER_LEN` yazan her yere 512 koyar. Böylece programın her yerinde 512'yi tek tek değiştirmek yerine tanımdaki tek değeri değiştirmek bütün programa yansır. Makro adları genellikle büyük harfle yazılır; bu, onun sıradan bir değişken değil önişlemci tanımı olduğunu gösteren bir gelenektir. Hoca, eskiden global değişkenlerin adının başına alt çizgi konduğunu, böylece okuyanın değişkenin global olduğunu anladığını; büyük harfli adın da benzer biçimde "bu bir makro" mesajı verdiğini söyledi.

Makro tip adı için de kullanılabilir: `#define TIP int` yazıp değişkenleri `TIP` ile tanımlarsanız, tipi tek yerden değiştirebilirsiniz. Bu, genel (jenerik) programlamaya doğru bir adımdır; daha gelişmiş biçimleri sonra görülecek.

**Soru (hocanın sorusu):** 512'yi `int n = 512;` diye tanımlayıp dizi boyutu olarak `n` kullansak olur mu? **Cevap:** Hoca, bunun bellekte ayrıca bir yer açtığını ve boyutun derleme öncesinde değil çalışma sırasında belirlenmesi anlamına geldiğini, bunun iyi bir yöntem olmadığını söyledi; makroyla değer derleme öncesinde yerine yazılır.

## 3. Fonksiyon benzeri makrolar ve yan etki

### 3.1 Parametreli makrolar

Makrolar iki sayıyı toplamak, çarpmak gibi işler için fonksiyona benzer biçimde de tanımlanabilir. Ekrandaki slayt (ekrandan, 00:30:00):

- Makronun sonunda `;` ve tanımında `=` kullanmamaya dikkat edin.
- Makro argümanları için tip denetimi yoktur.
- `min` makrosunu üç sayı için genişletmeyi deneyin.

```c
/* Example 1 */
#define MUL_BY_TWO(a)  ((a) + (a))

j = MUL_BY_TWO(5);
f = MUL_BY_TWO(2.5);

/* Example 2 */
#define min(a, b) ( (a) < (b) ? (a) : (b))
```

Makroya bir ad verilir, ardından parantez içinde parametre yazılır. Parametrenin tipi yazılmaz, çünkü bu bir fonksiyon değildir; program nerede çağırıyorsa orada metin olarak yerine konacaktır. `int j` ve `float f` için `MUL_BY_TWO(5)` yazıldığında yerine `((5) + (5))`, `MUL_BY_TWO(2.5)` yazıldığında `((2.5) + (2.5))` gelir; sonuçlar 10 ve 5.0 olur. Aynı makro hem tamsayı hem ondalıklı sayı için çalıştı; tip denetimi olmamasının sonucu budur.

İkinci örnekte `min(a, b)` iki parametre alır, aralarına virgül konur. `a < b` ise koşul işleci (`? :`) `a`'yı, değilse `b`'yi verir. Çağrı örneği olarak hoca `printf("%d", min(-3, 6));` yazdı; tanım nasılsa çağrı da öyle yapılır. Hoca, her parametrenin neden ayrı ayrı paranteze alındığına sonra döneceğini, parantezsiz yazımın da şimdilik çalışacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** Parantezlerin amacı işlem önceliğini korumaktır. Örneğin `#define KARE(x) x*x` tanımıyla `KARE(1+2)` ifadesi `1+2*1+2` olur ve 5 verir; `((x)*(x))` yazılsaydı 9 verirdi.

### 3.2 Yan etki (side effect)

Hoca makro kullanımında bir yan etki olduğunu, bunun gönderilen parametrelerin işlem önceliğinin karışması olduğunu söyledi. Ekrandaki slayt (ekrandan, 00:35:00):

```c
#define min(a,b)  ((a) < (b) ? (a) : (b))

a = min(b++, c);

/* The preprocessor translates this into: */
a =  ((b++) < (c) ? (b++) : (c));
```

`b++` makroya gönderildiğinde gövdede `a` kaç yerde geçiyorsa oraya kopyalanır; burada iki yer vardır. Hoca önce `b` yerine `3++`, `c` yerine 4 yazarak başladı, sonra `b = 2`, `c = 4` ile adım adım çözdü:

- Verilen: `b = 2`, `c = 4`.
- Koşul: `(b++) < (c)` → `2 < 4` doğrudur; karşılaştırmadan sonra `b` 3 olur.
- Koşul doğru olduğu için `(b++)` dalı çalışır: `a`'ya `b`'nin o anki değeri olan 3 atanır, sonra `b` artırılır.
- Sonuç: `a = 3`, `b = 4`.

Oysa beklenen `min(2, 4) = 2` idi. Hoca bunu "bizim 3 diye bir şeyimiz yoktu" diye yorumladı: makro yazarken bir yeri doğru yapsanız bile aynı metnin öteki yere de kopyalanacağını unutmamak gerekir. Bu kod `gcc -Wall` ile derlenip çalıştırıldı, `a=3 b=4` sonucu doğrulandı.

## 4. Makrolar ve fonksiyonlar

Ekrandaki karşılaştırma slaytı (ekrandan, 00:40:00) ve hocanın açıklamaları:

**Avantajlar**

- Makrolar genellikle fonksiyonlardan daha hızlıdır, çünkü fonksiyon çağrısının ek yükünden (function call overhead) kaçınırlar.
- Argümanlara tip kısıtı konmaz; bir makro birden çok veri tipine hizmet edebilir.

**Dezavantajlar**

- Makro argümanları makro gövdesinde her geçtikleri yerde yeniden değerlendirilir; argüman yan etki içeriyorsa beklenmedik davranış olur.
- Fonksiyon gövdeleri bir kez derlenir ve aynı fonksiyona yapılan çağrılar aynı kodu paylaşır; makrolar ise programda her geçtikleri yerde genişletilir.
- Makrolar argüman sayısını denetler ama tiplerini denetlemez.
- Makro içeren programların hata ayıklaması daha zordur, çünkü kaynak kod fazladan bir çeviri katmanından geçer.

### 4.1 Fonksiyon çağrısında ne yedeklenir?

**Soru (hocanın sorusu):** Bir fonksiyona gidip gelirken yedekleme (backup) ve geri yükleme (restore) yapılır. Sizce ne yedekleniyor olabilir? **Cevap:** Bir öğrenci değişkenlerin değerlerini söyledi. Hoca bunu doğruladı ve genişletti: program satır satır çalışır; çalışılan satırın bilgisi (program sayacı), işlemcideki yazmaçların (register) değerleri ve programdaki değişkenlerin değerleri saklanmalıdır, çünkü çağrılan fonksiyon kendi yazdığınız bir fonksiyon olsa bile başka bir program parçasıdır. Önce yedekleme yapılır, alt programın `return`'ü görülünce geri yükleme yapılır ve program kaldığı yerden sağlıklı biçimde devam eder. Hoca, her alt programın bir `return`'ü olmak zorunda olduğunu ve bu konunun Assembly dersinde daha ayrıntılı görüleceğini söyledi.

Bu gidip gelmelerdeki yedekleme işlemleri zaman alır. Makroda böyle bir şey yoktur; makro çağrıldığı yere kendini kopyalar, program olduğu gibi akar.

### 4.2 Genişletme ve hata ayıklama

Fonksiyon derlenir ve çalışma sırasında ona bir sıçrama yapılır. Makroda ise program genişletilir (expand): kodda üç yerde makro çağırdıysanız, üç yere de tanımın bütün metni kopyalanır. Makrolar argüman tipini denetlemez; bu bir esneklik sağlar ama tip kontrolü programcıya kalır.

Hata ayıklamada program adım adım çalıştırılır. Ekranda gördüğünüz kodda makro adı vardır ama makro derleme öncesinde zaten yerine yerleşmiştir; gördüğünüz kod ile arkada çalışan kod farklıdır. Hoca bu yüzden makro içeren programların hata ayıklamasının zor, bazen imkânsız olduğunu söyledi. Ayrıca fonksiyonlar parantezler, satır geçişleri ve girintilerle daha düzgün yazılabilir; makroda bu daha zordur.

## 5. #undef, hazır makrolar ve koşullu derleme

### 5.1 #undef

Tanımlanmış bir makro normalde kaynak kodun sonuna kadar değerini korur. `#undef` yönergesiyle tanım istenen noktada geçersiz kılınabilir. Hoca örnek olarak `FALSE` adlı bir makroyu anlattı: `#define` ile tanımlanır, bir süre kullanılır, sonra `#undef` ile kaldırılır. `#undef` ile `#define` arasındaki satırlarda makro kullanılamaz; sonra yeniden `#define` edilip farklı bir değerle kullanılabilir. Hoca, bir makroyu `#undef` etmeden yeniden tanımlamanın olmadığını, `#undef` sonrası yeniden tanımlamanın ise mümkün olduğunu söyledi. <!-- BELİRSİZ: slayttaki #undef örneğinin tam kodu karelerde görünmüyor. -->

Hoca ayrıca `GetOs` adlı bir makronun işletim sisteminin adını öğrenen bir fonksiyona bağlanabileceğini, buna göre "Linux ise şöyle, Windows ise böyle çalış" denebileceğini ve makronun sonra `#undef` edilebileceğini anlattı; bu şartlı derlemeye bir örnektir.

### 5.2 Hazır makrolar

Ekrandaki slayt (ekrandan, 00:45:00):

- `__LINE__`: çağrıldığı kaynak dosya satır numarasına genişler.
- `__FILE__`: çağrıldığı dosyanın adına genişler.
- `__TIME__`: programın derlendiği saate genişler.
- `__DATE__`: programın derlendiği tarihe genişler.
- `__STDC__`: derleyici ANSI standardına uyuyorsa 1 sabitine genişler.

Hoca bunların hepsinin "expand" ettiğini vurguladı: programda nerede çağırdıysanız, o yere tanımın karşılığı kopyalanır. Başındaki ve sonundaki iki alt çizgi, bunların hazır (built-in) makrolar olduğunu gösteren bir gösterimdir. `__LINE__` ve `__FILE__` hata ayıklamada kullanılır: bulunulan satırı `%d`, dosya adını `%s` ile yazdırabilirsiniz. `__DATE__` ve `__TIME__` için önemli bir ayrıntı: bunlar programın çalıştığı zamanı değil, derlendiği zamanı verir. Programı bir gün derleyip başka bir gün çalıştırırsanız ekranda yine derleme anı görünür. Hoca slayttaki örnekte bunların bir "sürüm yazdırma" fonksiyonunda kullanıldığını anlattı.

### 5.3 Koşullu derleme

Koşullu derleme, önişlemcide şart ifadeleri kullanarak programın bazı satırlarını derleyip bazılarını derlememektir. Bunlar C'nin `if`/`else`'i değil, önişlemcinin `#if`, `#else`, `#elif` ve `#endif` yönergeleridir. Program geliştirme ve hata ayıklama sırasında özellikle kullanışlıdır: programın farklı bölümlerini farklı değerlere göre derleyip derlememeye siz karar verirsiniz.

Hoca, bütün derleyicilerin komut satırı seçeneklerine (command line option) sahip olduğunu ve bu sayede derleme aşamasında makro tanımlanabildiğini söyledi; örneğin "hata ayıklama kipini aç ve test programını ona göre derle" denebilir. Komut satırı argümanları ileride ayrıca görülecek.

Kurallar:

- Koşullu ifade `#if` ile başlar ve `#endif` ile bitmek zorundadır.
- Birden fazla şart için `#elif` yazılır; `switch`'teki `default` gibi varsayılan durum `#else` ile yazılır.
- Bir `#if` bloğu birden çok `#elif` içerebilir ama yalnız bir `#else` içerir ve o da en sonda olur.
- Süslü parantez gerekmez.

Hocanın anlattığı örnekte: `x` 1 ise `x` `#undef` edilip 0 olarak yeniden tanımlanır; `x` 2 ise yine `#undef` edilip 3 olarak tanımlanır; son durumda `x` programın başka bir yerindeki bir tamsayı değişkenine bağlanabilir. <!-- BELİRSİZ: bu slaytın tam kodu karelerde görünmüyor; yalnız sözlü anlatım var. -->

### 5.4 defined ve türetilmiş yönergeler

Ekrandaki slayt (ekrandan, 00:50:00) eşdeğer yazımları yan yana verir:

| Uzun biçim | Kısa biçim |
|---|---|
| `#if defined TEST` | `#if defined (TEST)` |
| `#if defined macro_name` | `#ifdef macro_name` |
| `#if !defined macro_name` | `#ifndef macro_name` |

`defined` bir makronun tanımlı olup olmadığını sınar ve doğru ya da yanlış verir. `#ifdef` "tanımlıysa", `#ifndef` "tanımlı değilse" anlamına gelen türetilmiş yönergelerdir. Hoca bunlarla ilgili basit örneklerin uygulama saatinde yapılacağını söyledi.

## 6. #include ve #line

### 6.1 #include

Ekrandaki slayt (ekrandan, 00:55:00):

- `#include <filename>`: önişlemci dosyayı derleyiciye özgü bir yer listesinde arar. UNIX sistemlerinde standart başlık dosyaları genellikle `/usr/include` dizinindedir.
- `#include "filename"`: önişlemci dosyayı işletim sisteminin dosya belirtme kurallarına göre arar; orada bulamazsa açılı parantezle yazılmış gibi arar.
- `#include`, birden çok kaynak dosyanın paylaştığı ortak tanım dosyaları (başlık dosyaları) oluşturmayı sağlar. Bunlar geleneksel olarak `.h` uzantılıdır ve veri yapısı tanımlarını, makro tanımlarını, fonksiyon prototiplerini ve global veriyi içerir.

Hoca `#include`'ü hazır bir kaynak kodun programa dahil edilmesi olarak anlattı: `stdio.h` ile kendi `myprog` programınız birleştirilir. Açılı parantezli biçim daha genel bir arama yapar, bulunduğunuz klasörün dışındaki standart yerlere de bakar; tırnaklı biçim ise programınızın bulunduğu yere, örneğin kendi oluşturduğunuz bir klasörün altına bakar.

`#include` kendi başlık dosyanızı yazarak programınızı modüler hale getirmenizi sağlar; proje birden çok kaynak dosyadan oluşur. Hoca burada sık yapılan bir hatayı anlattı: bir öğrenci programı modüler yapmak için `f` fonksiyonunu gövdesiyle birlikte bir `.h` dosyasına, başka bir fonksiyonu başka bir `.h` dosyasına koyuyor, `main`'i de ana programa yazıyor. Bu doğru değildir.

> **Hocanın vurgusu:** Yapı tanımları, makro tanımları ve fonksiyon prototipleri `.h` dosyasında yer alır ve bu dosya programdan çağrılır. Fonksiyonların gerçekleştirimi (gövdesi) yine programın kendi içinde, `.c` dosyasında olur.

### 6.2 #line (satır denetimi)

Hoca son olarak satır denetimini tanıttı. Slaytta `#line 100` ve ardından `#line 200 newname` gibi yönergeler vardı. Bunların `main` öncesinde yazılması zorunlu değildir, program içinde de kullanılabilir. Hoca bu özelliğin bir C programının kaynak metni başka bir araçla üretilirken kullanışlı olduğunu söyledi, örneklerin sonra yapılacağını belirtti ve bunu şimdilik bir tanıtım olarak bıraktı.

> **Ek bilgi (derste anlatılmadı):** `#line n "dosya"` yönergesi, derleyicinin bir sonraki satırı `n` numaralı ve verilen adlı dosyadaki satır olarak saymasını sağlar; `__LINE__`, `__FILE__` ve hata mesajları buna göre değişir. Başka bir dilden C kodu üreten araçlar, hata mesajlarının özgün kaynak dosyayı göstermesi için bunu kullanır.

## 7. Depolama sınıfları: kapsam ve ömür

### 7.1 Konunun çerçevesi

Aradan sonra hoca depolama sınıflarına (storage classes) geçti. `double d;` gibi bir tanımın önüne bazı anahtar sözcükler gelebilir; bunlar değişkenin ömrü (duration) ve kapsamıyla (scope) ilgilidir. Bu bölümün konuları: sabit ve otomatik ömür, kapsamlar, global değişkenler, `register` ve diğer belirteçler.

### 7.2 Kapsam ve ömür tanımları

Ekrandaki slayt (ekrandan, 01:10:00):

- **Kapsam (scope)**, C kaynak metninde bir adın bildiriminin etkin olduğu bölgeyi gösteren teknik terimdir.
- **Ömür (duration)**, değişkenin bellekteki yerinin yaşam süresini anlatır.
  - Sabit ömürlü (fixed duration) değişkenlerin, kapsamlarından çıkıldıktan sonra bile değerlerini korumaları garanti edilir.
  - Otomatik ömürlü (automatic duration) değişkenler için böyle bir garanti yoktur.
- Sabit değişken durağandır (stationary); otomatik değişkenin bellek yeri ise program çalışırken otomatik olarak ayrılır.
- Yerel değişkenler (kapsamı bir blokla sınırlı olanlar) varsayılan olarak otomatiktir; ama bildirimde `static` anahtar sözcüğü kullanılarak sabit yapılabilir.
- `auto` anahtar sözcüğü değişkeni açıkça otomatik yapar, ama gereksiz olduğu için nadiren kullanılır.

Hoca "kapsamın bitmesini" şöyle açıkladı: bir fonksiyon içinde `int a;` tanımladınız ve `a`'yı 5 yaptınız. Fonksiyon bitince bu değişkenin ömrü tamamlanır; fonksiyon dışında onun kalan değerine erişemezsiniz. Fonksiyon bitmeden yazdırırsanız 5 görürsünüz, ama sonra o bellek yerine bir şekilde erişseniz 5'i göremeyebilirsiniz. Sabit ömürlü değişkende ise fonksiyon bitse bile değer saklanır. `auto` her yerel değişkende zaten örtük (implicit) olarak vardır; açıkça yazmak isterseniz başına `auto` eklersiniz.

### 7.3 static ile otomatik değişken örneği

Ekrandaki slayt (ekrandan, 01:15:00):

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

Slayttaki açıklama: sabit değişkenler yalnız bir kez ilklenir, otomatik değişkenler ise bloklarına her yeniden girildiğinde ilklenir. `increment()` iki değişkeni, `j` ve `k`'yi artırır; ikisi de 1 ile ilklenmiştir. `j` varsayılan olarak otomatik ömürlüdür; `k` ise `static` nedeniyle sabit ömürlüdür.

Hocanın adım adım çözümü:

- Birinci çağrı: `j = 1`, `k = 1` ile başlar; artırmadan sonra `j = 2`, `k = 2`; ekrana `j:2 k:2`.
- İkinci çağrı: `j` yeniden tanımlanıp 1 ile ilklenir ve 2 olur. `k`'nin ilk değer satırı bir daha çalışmaz; `k` 2'den devam eder ve 3 olur; ekrana `j:2 k:3`.
- Üçüncü çağrı: aynı biçimde `j:2 k:4`.

Hoca `k`'nin bellek adresinin sabitlendiğini, değişkenin program bitene kadar yaşadığını ve bunun `static` sayesinde olduğunu vurguladı; otomatik değişken ise bloğa her girişte yeniden oluşturulur ve yeniden ilklenir. Kod `int main(void)` ve `return 0;` eklenerek `gcc -Wall` ile derlenip çalıştırıldı; çıktı slayttaki yorumlarla aynıdır.

### 7.4 static'in dizilerde kullanımı

Hoca `static`'in başka bir kullanımını anlattı: `int a[5];` dediğinizde dizinin elemanları otomatik olarak sıfırlanmaz, içinde çöp (garbage) değerler kalabilir. `static int a[5];` dediğinizde elemanlar sıfırlanır. Ama bu durumda dizi "sabitlenir" ve içindeki değerler program sonlanana kadar kalır. Hoca bu yüzden `static`'in gelişigüzel kullanılmamasını istedi. Ayrıca sabit bir değişkene başlangıç değeri verilmezse 0 atanır: örnekte `static int k;` yazılsaydı `k` ilk çağrıda 0 ile başlardı.

## 8. Kapsam türleri

### 8.1 Dört kapsam

Ekrandaki slayt (ekrandan, 01:20:00): Bir değişkenin kapsamı, değişkene adıyla erişebileceğiniz bölgeyi belirler. Dört kapsam türü vardır:

- **Program kapsamı:** değişken, çalıştırılabilir programın tamamını oluşturan farklı kaynak dosyalar arasında etkindir. Program kapsamlı değişkenlere genellikle global değişken denir.
- **Dosya kapsamı:** değişken, bildirildiği noktadan kaynak dosyanın sonuna kadar etkindir.
- **Fonksiyon kapsamı:** ad, fonksiyonun başından sonuna kadar etkindir.
- **Blok kapsamı:** değişken, bildirildiği noktadan içinde bildirildiği bloğun sonuna kadar etkindir. Blok, süslü parantez içine alınmış herhangi bir deyimler dizisidir; bileşik deyimleri ve fonksiyon gövdelerini de içerir.

Hoca bunu bir proje üzerinde çizdi: `f.c`, `a.c`, `b.c` ve `main.c` dosyaları ile `f.h`, `a.h`, `b.h` başlık dosyaları olsun; hepsini `main`'den çağırıp modüler bir program yazabilirsiniz. Bunların tamamı programdır; her biri bir dosyadır; her dosyanın içinde fonksiyonlar, fonksiyonların içinde bloklar olabilir. Program kapsamlı bir değişkene başka bir dosyadan erişilebilir (örneğin `f.c` içindeki bir değişkene `b.c`'den). Dosya kapsamlı bir değişkene o dosyanın her yerinden erişilebilir; hoca "global değişken kullanmayın" derken genellikle bunu kastettiklerini söyledi. Fonksiyon kapsamı bir fonksiyonun başladığı ve bittiği yer arasıdır. Blok kapsamı bunun alt kümesi gibidir: bir program parçasında, fonksiyon olmadan bir blok açıp kapatabilir ve içinde değişken tanımlayabilirsiniz.

Hoca, bir kod örneğinde fonksiyonların dışında tanımlanan değişkenin program kapsamlı olduğunu, `static` ile sınırlandırılırsa dosya kapsamına indiğini; bir fonksiyon içindeki `k` ve `m` gibi değişkenlere yalnız o fonksiyonda erişilebildiğini; fonksiyon içinde açılan ayrı bir bloktaki değişkenin blok kapsamlı olduğunu gösterdi. Her değişkene tanımlandığı kapsam içinde erişilir; burada sözü edilen yalnız ad değil, o ada ait değer ve bellek yeridir.

### 8.2 Blok kapsamı ve değişken gizleme

Blok kapsamlı bir değişkene bloğunun dışından erişilemez. Hoca slayttaki `foo` fonksiyonu örneğinde, fonksiyon içinde bir `j` değişkeni varken iç blokta yeniden bir `j` tanımlandığını gösterdi: iç blokta geçerli olan iç `j`'dir. Dış `j` örneğin bir döngüde 11'e kadar çıkabilir, ama iç blokta `j`'yi 0 olarak okursunuz. Bu, iç içe bloklarda aynı adla yeni değişken tanımlamaktır (variable hiding) ve hata ayıklama sırasında kullanılabilir; ancak fark edilmesi zor hatalara yol açabilir. Hoca'nın tavsiyesi: dışarıda `j` tanımladıysanız iç blokta başka bir ad kullanın. <!-- BELİRSİZ: foo örneğinin tam kodu karelerde görünmüyor. -->

### 8.3 Fonksiyon kapsamı: goto etiketleri

Ekrandaki slayt (ekrandan, 01:25:00):

- Fonksiyon kapsamına sahip tek adlar `goto` etiketleridir.
- Etiketler fonksiyonun başından sonuna kadar etkindir; bu, etiketlerin fonksiyon içinde tek (unique) olması gerektiği anlamına gelir.
- Farklı fonksiyonlar aynı etiket adlarını çakışma olmadan kullanabilir.

Hoca `goto`'yu kısaca gösterdi: `start:` diye bir etiket konur, bir işlem yapılır, bir şart sağlanınca `goto start;` ile o etikete geri dönülür. Aynı fonksiyonda aynı adla ikinci bir etiket tanımlanamaz. Derste `goto` kullanılmayacağı için bu konu çok önemli değildir.

### 8.4 Dosya ve program kapsamı

Ekrandaki slayt (ekrandan, 01:30:00):

- Değişkene dosya kapsamı vermek, onu dosyanın geri kalanında etkin yapar; dosyada birden fazla fonksiyon varsa bildirimden sonra gelen bütün fonksiyonlar değişkeni kullanabilir.
- Dosya kapsamı vermek için değişken bir fonksiyonun dışında, `static` anahtar sözcüğüyle bildirilir.
- Program kapsamlı değişkenler (global değişkenler) kendi dosyalarının yanında başka dosyalardaki rutinlerden de görünür.
- Global değişken oluşturmak için değişken bir fonksiyonun dışında, `static` olmadan bildirilir.

Hoca `#include <stdio.h>` altında `int a, b = 3;` gibi tanımlarla bu değişkenlere her yerden erişilebileceğini, ama bunun yerine ileride yapıların (struct) tanımlarının bu düzeyde yazılacağını anlattı; dışarıda yapının değişkeni değil, yapının tanımı yer alacaktır. Global değişken derleyici açısından hata vermez, ama derste kullanımı yasaktır.

Sayaç ve boyut gibi bütün fonksiyonların kullanacağı değerler için de global değişken kullanılmaz. Ekranda hoca şunu çizdi: `#define MAX 100` kabul edilir; `int max = 100;` kabul edilmez. Makro tanımı üzerinde `MAX = MAX + 10` gibi bir değişiklik yapılamaz, global bir değişkende ise yapılabilir; bu da sorunların kaynağıdır. Bu tür sayaç ve boyutlar için ya makro tanımlanmalı ya da parametre aktarımı yapılmalıdır.

## 9. Global değişkenler, extern, register, const, volatile

### 9.1 Global değişkenlerden neden kaçınılır?

Ekrandaki slayt (ekrandan, 01:35:00):

- Genel olarak global değişken kullanmaktan olabildiğince kaçınmalısınız.
  - Karmaşıklığı artırdıkları için programın bakımını zorlaştırırlar.
  - Modüller arasında çatışma olasılığı yaratırlar.
  - Global değişkenlerin tek avantajı daha hızlı kod üretmeleridir.

Hoca, işletim sistemi ya da gömülü sistem projelerinde global değişkenlerin çakışma, karşılıklı dışlama (mutual exclusion) ve kilitlenme (deadlock) gibi sorunlara yol açtığını anlattı ve bir banka örneği verdi. Bir hesabın bakiyesi (`amount`) global olsun; bir fonksiyon para ekler, öteki para çıkarır. 100 lira varken önce 10 lira eklenir, sonra 15 lira çıkarılır. Toplama ve çıkarma, işlemci düzeyinde (Assembly ya da bilgisayar organizasyonu derslerinde görülecek) daha küçük mikro işlem adımlarından oluşur. Global değişken nedeniyle bu adımlar birbirine karışabilir: bakiyenin 110, sonra 95 olması gerekirken 115 görünebilir. Bunun nedeni bir işlemin tamamlanmadan ötekinin araya girmesidir.

Hoca ayrıca nesneye yönelik programlamada global değişken yerine sınıf özelliği (property) tanımlandığını, bunun ayrı bir kavram olduğunu söyledi. Yapısal programlamada ise bazı öğrencilerin global değişkeni fonksiyonların arasına gizleyerek tanımladığını, bunun da tespit edilebildiğini belirtti.

### 9.2 Tanım ve ima (definition ve allusion)

Slayttaki devamı: iki tür bildirim vardır, tanım (definition) ve ima (allusion). İma bir tanım gibi görünür, ama değişken için bellek ayırmak yerine derleyiciye belirtilen tipte bir değişkenin var olduğunu ve başka bir yerde tanımlandığını bildirir:

```c
extern int j;
```

`extern` anahtar sözcüğü derleyiciye değişkenin başka yerde (başka bir dosyada ya da başka bir yerde) tanımlandığını söyler. `int a = 3;` ise gerçek bir tanımdır: bellekte yer ayırır ve içine 3 yazar. Hoca `extern`'in kullanımına sonra döneceklerini söyledi.

### 9.3 register

`register` belirteci değişkenin bellekte değil işlemcinin yazmacında saklanmasını ister; amaç hızdır. Bu her zaman mümkün değildir, genellikle de olmaz; karar derleyicinin ve sistemin uyumuna bağlıdır.

**Soru (hocanın sorusu):** Değişken işlemcide saklanıyorsa bellek adresi var mıdır? **Cevap:** Yoktur. Bu yüzden `register` bir değişkene `&` uygulanamaz (örneğin `scanf` içinde `&len` yazılamaz). Tipik kullanımı döngülerdeki sayaç değişkenleridir; başına `register` eklemek yeterlidir.

### 9.4 Özet: auto, static, extern, register, const, volatile

- `auto`: yerel değişkenin varsayılan, otomatik sınıfı.
- `static`: değişkenin kapsamını ve ömrünü ayarlar.
- `extern`: bir değişkene birden çok yerden, birden çok dosyadan erişirken kullanılır.
- `register`: değişkeni yazmaçta tutmayı ister.
- `const`: değişkenin değerini sabitler; `const int x = 5;` sonrası `x = x + 1` yapılamaz.
- `volatile`: derleyiciye bazı optimizasyonları kapatmasını söyler (uçucu değişken). Hoca bunun eski bir kullanım olduğunu, bazı gömülü sistemlerde hâlâ kullanıldığını ve derleyici ile işletim sistemi arasında değişkenin değerinin saklanıp saklanmaması konusunda bir özellik sağladığını söyledi.

> **Ek bilgi (derste anlatılmadı):** `volatile`, değişkenin program dışından (donanım yazmacı, kesme işleyicisi gibi) değişebileceğini bildirir; derleyici bu yüzden değeri bir yazmaçta önbelleğe almaz, her erişimde bellekten yeniden okur.

## 10. İşaretçilere giriş

### 10.1 Değişkenin özellikleri

"Pointers and Arrays" bölümüne geçildi (ekrandan, 01:40:00). Hoca, bundan sonraki konuların daha yoğun olacağını ve örneklerin artacağını söyledi. Bir değişkenin özellikleri şunlardır: etiket (ad, label), değer, adres, tip, boyut (size), ömür ve kapsam. İşaretçi konusunda en çok adres, değer, etiket, tip ve boyutla ilgilenilir.

İşaretçi kullanmanın amacı bazı değişkenlere adres üzerinden erişmektir; değişkene doğrudan adıyla işlem yapılamayan durumlar vardır. `swap` fonksiyonu buna örnektir. En basit örnek `scanf`'tir: `scanf("%d", &a)` yazarken `scanf` "bana bir adres ver" der ve okuduğu değeri o adrese yazar.

### 10.2 İşaretçi türleri ve atama kuralı

Genel türden işaretçi `void *` ile tanımlanabilir, ama genellikle `short` için `short *`, `int` için `int *` tanımlanır. İşaretçilerde atama yapılırken sağ ve sol tarafın işaretçi türü aynı olmalıdır. Hoca bunu şöyle anlattı: `int` bir türdür, `int *` başka bir türdür, `int **` başka bir türdür, `int ***` başka bir türdür. Bunlara `p`, `pp`, `ppp` dersek, `p`'yi `p` türünden bir işaretçiye atayabilirsiniz, ama `pp`'yi `p`'ye ya da `ppp`'yi `p`'ye atayamazsınız; bunlar yasal olmayan işlemlerdir (ekrandan, 01:45:00).

Hoca ayrıca `short` değişkenin adresini `int *` gibi farklı türden bir işaretçiye atamanın bazı derleyicilerde `short`'u bir tamsayı türevi sayıp gizli dönüşümle çalışabildiğini, ama bazı derleyicilerde kesinlikle çalışmayacağını söyledi.

### 10.3 Temel örnek: "What will happen?"

Ekrandaki slayt (ekrandan, 01:45:00):

```c
#include <stdio.h>
int main(int argc, char *argv[]) {
    short i,j;  //short integers
    short *p;   //pointer to short
    i = 123;    //statement #1
    j = 321;    //statement #2
    p = &i;     //statement #3: p now shows the memory address of i
    j = *p;     //statement #4: * means: use the indirect (pointer) value of p
    printf("i:%d j:%d", i, j);
    i += 2; j += 3; printf("i:%d j:%d", i, j); //statement #5
    return 0;
}
```

Bellek tablosu (ekrandan, 01:50:00), varsayımsal adreslerle:

| Değişken | Adres | Başlangıç içeriği | 1-3. deyimlerden sonra |
|---|---|---|---|
| `i` | 0x1200 | boş | 123 |
| `j` | 0x1202 | boş | 321 |
| `p` | 0x1204 | boş | 1200 |

Slayttaki not: 1200 yalnız bir varsayımdır; değişkenlerin tutulacağı gerçek adresler çalışma zamanında belirlenir. Hoca, sınavda böyle bir analiz sorusu sorulursa "`p`'nin adresi 1200 olsun" gibi bir varsayımın verileceğini, adreslerin gerçekle ilgisi olmadığını vurguladı.

Adım adım çözüm:

- 1. ve 2. deyim: `i = 123`, `j = 321`.
- 3. deyim: `p = &i;` → `p`'nin içine `i`'nin adresi (1200) yazılır.
- 4. deyim: `j = *p;` → `*p`, "`p`'nin gösterdiği adrese git, oradaki değeri al" demektir (dereference). 1200 adresindeki 123 alınır ve `j`'ye yazılır; `j`'nin eski değeri 321 kaybolur.
- Birinci `printf`: `i:123 j:123`.
- 5. deyim: `i += 2` → 125; `j += 3` → 126. `j` artık `i`'den bağımsızdır.
- İkinci `printf`: `i:125 j:126`.

Hoca, 4. deyimdeki atamanın bir defalık olduğunu, `p`'nin ya da `j`'nin bundan sonra `i`'yi sürekli takip etmediğini vurguladı. Kod `gcc -Wall` ile derlenip çalıştırıldı; çıktı `i:123 j:123i:125 j:126` oldu (`printf`'lerde `\n` olmadığı için iki çıktı bitişik yazılır).

> **Ders sonrası not:** Hoca bir yerde son değerleri "123 ve 126" diye söyledi; doğrusu `i = 125`, `j = 126`'dır. Hocanın aynı dakikadaki adım adım anlatımı da 125 ve 126'dır.

### 10.4 Derin ve sığ kopyalama

Hoca 4. deyimin bir kopyalama işlemi olduğunu, bilgisayar bilimlerinde kopyalamanın iki türlü yapıldığını anlattı:

- **Derin kopyalama (deep copy):** gerçek bir kopyadır; değerler kopyalanır. `j = *p;` ile `p`'nin gösterdiği 123 `j`'ye kopyalanır; bundan sonra `i` ve `j` birbirinden bağımsızdır. Birine 2, ötekine 3 eklerseniz her biri kendi başına değişir (125 ve 126).
- **Sığ (shallow) ya da gölge kopyalama:** adresler kopyalanır. İki işaretçi aynı bellek bölgesini gösterir; tek bir hücre üzerinde birinden 2 artırırsanız 123 125 olur, ötekinden 3 artırırsanız 125 128 olur.

## 11. Dev-C++ uygulaması: adresler, işaretçiler ve işaretçi aritmetiği

### 11.1 Kodun kurulması

Hoca Dev-C++ üzerinde bir örnek yazdı ve yanında bellek düzenini çizdi (ekrandan, 01:55:00 ve 02:00:00). `a = 100`, `b = 200`, `c = a` (derin kopya, `c` de 100 olur). `pa = &a`, `pb = &b`, `pt = &a`, `ptt = pa`. Çizimde `a`, `b`, `c` için varsayımsal 1, 2, 3 adresleri kullanıldı: `pa` ve `pt` içinde 1, `pb` içinde 2 yazar; `ptt = pa` satırından sonra `ptt` de 1'i, yani `a`'yı gösterir. Sonuçta `pa`, `pt` ve `ptt` aynı `a` hücresini (100) gösterir.

**Soru (hocanın sorusu):** `ptt = pa;` yasal mı? **Cevap:** Evet. `pa` ve `ptt` ikisi de `int *` türündedir. `pa = &a;` de yasaldır: `a` bir `int`'tir, `&a` ise `int *` türünde bir değerdir, `int *` bir değişkene atanabilir.

Derste yazılan kodun son hali (ekrandan, 02:25:00; tek fark aşağıdaki ders sonrası notta):

```c
#include<stdio.h>
int main(){
    int a,b;
    int c,d;
    int *pa,*pb,*pt,*ptt;
    char ch='a';
    char *pch=&ch;
    a=100;
    b=200;
    c=a; //deep copy
    pa=&a;
    pb=&b;
    pt=&a;
    ptt=pa;
    printf("A:%d Adres-A:%d\n",a,&a);
    printf("A_1:%d A_2:%d Adres-A:%d\n",*pa,*ptt,pt);
    printf("Bu nereden cikti-1 %d %d %d\n",&pa, &pt, &ptt);
    printf("Bu nereden cikti-2 %d %d %d\n",*&pa, &*pt, *&*&ptt);
    printf("Bu nereden cikti-3 %d %d %d\n",&*&pa, *&*pt, &*&ptt);
    pa=pa+1;
    printf("B:%d Adres-B:%d\n",b,pb);
    printf("Yeni Adresler\nA_1:%d A_2:%d Adres-A:%d\n",pa,*ptt,pt);
    printf("Before:C=%c, C=%c &C=%d &C=%d\n",ch,*pch,&ch,pch);
    pch++; //pch=pch+1*sizeof(char)
    printf("After:C=%c, C=%c &C=%d &C=%d\n",ch,*pch,&ch,pch);
}
```

Hoca adresleri şimdilik `%d` ile yazdırdı; adres biçiminde yazmak için `%p` kullanılabileceğini, ama ondalık yazmak için `%d`'nin yeterli olduğunu söyledi.

> **Ders sonrası not:** Bu kod bu hâliyle `gcc -Wall` ile derlenir ama adreslerin `%d` ile yazdırılması için biçim uyarıları verir; 64 bit Linux'ta adresler kesilip negatif sayı olarak görünebilir. Adresleri `%p` ve `(void *)` dönüşümüyle yazdıran bir sürüm de derlenip çalıştırıldı ve aşağıdaki bütün ilişkiler aynen gözlendi.

### 11.2 a'ya ve adresine farklı yollardan ulaşmak

İlk iki `printf`'te hoca `a`'nın değerini ve adresini farklı yollardan yazdırdı:

- `a`'nın değeri: doğrudan `a`, ya da `*pa` ("`pa`'nın gösterdiği yerdeki değer"), ya da `*ptt`.
- `a`'nın adresi: `&a`, ya da `pt`. `pt`'nin önüne `&` konmaz, çünkü `pt` zaten içinde `a`'nın adresini saklar.

Derste bir çalıştırmada ekrandaki çıktı (ekrandan, 02:05:00): `A:100 Adres-A:2358844` ve `A_1:100 A_2:100 Adres-A:2358844`. Aynı sonuçlar üç farklı yoldan elde edildi.

### 11.3 "Bu nereden çıktı?" İşaretçinin kendi adresi

**Soru (hocanın sorusu):** `&pa`, `&pt`, `&ptt` nedir, bunlar nereden çıktı? Bu satırdaki üç değer aynı mı olacak, farklı mı? **Cevap:** İşaretçi de sonuçta bir değişkendir ve bellekte kendi adresi vardır. `&pa`, `pa` değişkeninin oturduğu adrestir. Üç işaretçi farklı yerlerde durduğu için üç değer farklıdır. Ekranda: `Bu nereden cikti-1 2358832 2358824 2358816` (ekrandan, 02:05:00).

### 11.4 * ve & birbirini götürür

Hoca bunun Deitel'in kitabında da bulunduğunu söyledi: `*` ve `&` art arda geldiğinde birbirini iptal eder.

- `*&pa`: önce `pa`'nın adresi alınır, sonra o adresteki değere gidilir; sonuç `pa`'nın kendisi, yani `a`'nın adresidir.
- `&*pt`: önce `pt`'nin gösterdiği yere (a'ya) gidilir, sonra onun adresi alınır; sonuç yine `pt`, yani `a`'nın adresidir.
- `*&*&ptt`: işlem iki kez yapılır, sonuç `ptt`, yani yine `a`'nın adresidir.

Ekranda: `Bu nereden cikti-2 2358844 2358844 2358844` (ekrandan, 02:15:00); üçü de `a`'nın adresidir.

Sonra hoca bir adım daha ekledi:

- `&*&pa` → `&pa` (pa'nın kendi adresi, 2358832).
- `*&*pt` → `*pt` (pt'nin gösterdiği değer, 100).
- `&*&ptt` → `&ptt` (ptt'nin kendi adresi, 2358816).

Ekranda: `Bu nereden cikti-3 2358832 100 2358816` (ekrandan, 02:15:00). Birinci ve üçüncü değer "cikti-1" satırındaki `&pa` ve `&ptt` ile aynıdır, ortadaki 100 ise `a`'nın değeridir.

Hoca bunların "ÖSS tarzı" sorular olduğunu, ikisinin birbirini götürdüğünü görmenin yeterli olduğunu, ama dikkat edilmesi gereken durumlar bulunduğunu söyledi: adresin adresinin adresi diye bir şey yoktur. `ptt`'nin kendine ait bir adresi vardır, ama "onun adresinin adresi" yoktur; bu yüzden `&` işlecini üst üste getirmeye çalıştığı satır derleme hatası verdi. <!-- BELİRSİZ: hata veren satırın tam yazımı karelerde görünmüyor; büyük olasılıkla `&&ptt` gibi art arda iki `&` içeriyordu. -->

> **Ek bilgi (derste anlatılmadı):** `&` işleci yalnız bellekte yeri olan bir nesneye (lvalue) uygulanabilir. `&ptt` bir değerdir, bellekte ayrı bir değişken olarak durmaz; bu yüzden `&(&ptt)` geçersizdir. `*` ise bir adres değerine uygulanabildiği için `*&*&ptt` gibi zincirler geçerlidir.

### 11.5 İşaretçi aritmetiği: pa + 1

Hoca, dizilerde `pa = pa + 1` gibi ifadelerin sık kullanılacağını söyleyerek sordu: `pa` bir artınca kaç artar? "Bir bayt değil, dört bayt da değil; bu ezber" dedi. `pa`'nın bir tipi vardır ve artış tipe göre olur: `pa + 1`, adres değerine 1 × tipin boyutu kadar ekler. Tamsayı genelde 4 bayt olduğu için adres 4 artar; örneğin içerik 1 iken 5 olur.

Derste `pa = pa + 1;` çalıştırıldıktan sonra `pa`'nın değeri yazdırıldı. Hoca önce yanlışlıkla `*pa` yazdırdığını fark edip `pa` olarak düzeltti. Sonuç: `pa` 2358844'ten 2358848'e geçti, yani 4 bayt ilerledi. `pt` ve `ptt` ise hâlâ `a`'yı (100'ü) gösterir; `pa` artık başka bir yeri gösterir ve orada ne olduğunu bilmeye gerek yoktur, ama eski `a`'nın adresi olmadığı kesindir.

Hoca sonra `b`'nin adresine baktı. `pa+1`'in `b`'ye denk gelip gelmediğini görmek istedi. İlk denemede yanlış değişkeni yazdırdı; bir öğrenci "`b`'nin adresi için `pb`'ye bakmamız gerekmiyor muydu?" diye sordu, hoca haklı olduğunu söyleyip `pb`'yi yazdırdı. `b`'nin adresi 2358840 çıktı: `b`, `a`'dan sonra tanımlanmasına rağmen bellekte `a`'dan önce duruyordu. Yani ardışık tanımlanan değişkenlere ardışık adresler verileceği garanti değildir ve adresler her çalıştırmada değişebilir. Dizilerde ise durum farklıdır: dizinin sıfırıncı elemanını `pa` gösteriyorsa `pa + 1` birinci elemanı, `pa + 2` ikinci elemanı gösterir; bir döngüyle dizinin bütün elemanlarına böyle erişilir. Hoca `pa++` ifadesini de araştırmayı önerdi; aynı sonuç görülecektir.

### 11.6 char işaretçisinde artış

Farkı görmek için hoca bir `char` örneği ekledi: `char ch = 'a'; char *pch = &ch;`. "Before" satırında `ch` ve `*pch` ikisi de `a` yazdı, `&ch` ve `pch` aynı adresi verdi (derste ilk denemede yanlış değişkenin adresi yazdırıldı, sonra `ch`'nin adresi olarak düzeltildi). Sonra `pch++` yapıldı. "After" satırında `ch` hâlâ `a`'dır, çünkü karakter yerinde durur; ama `pch` 1 bayt ilerlemiştir ve `*pch` o sonraki bayttaki değeri verir. Derste o baytta `4` karakteri görüldü. Yani `char *` için artış 1 bayt, `int *` için 4 bayttır: artış her zaman `sizeof` kadardır ve işletim sistemine ya da derleyiciye göre değişebilir. Hoca bunun dinamik bellek yönetiminde kullanılacağını, bu yüzden "tipin boyutu kadar" düşünmeye alışmak gerektiğini söyledi. Ekrandaki yorum satırı da bunu anlatır: `pch++` ifadesi `pch = pch + 1*sizeof(char)` demektir (bayt düzeyinde).

> **Ders sonrası not:** Ekranda son olarak `pa=pa+1;` satırı `pa=pa+1*sizeof(int);` olarak değiştirildi (ekrandan, 02:25:00). C'de işaretçi aritmetiği zaten tipin boyutuyla ölçeklenir; bu satır `pa + 4` demektir ve adresi 4 × 4 = 16 bayt ilerletir. "Adres + 1 × sizeof" kuralı bayt düzeyinde ne olduğunu anlatır; kodda yalnız `pa = pa + 1;` yazılmalıdır. `char` için `sizeof(char)` 1 olduğundan yorumdaki ifade sonucu değiştirmez. Hoca bir yerde bunu "`sizeof(pa)` kadar" diye de söyledi; doğrusu `sizeof(*pa)` ya da `sizeof(int)`'tir, çünkü `sizeof(pa)` işaretçinin kendi boyutudur (64 bit sistemde büyük olasılıkla 8).

### 11.7 Öğrenci sorusu: %d ile okumak

**Soru:** `pch`'yi bir artırdıktan sonra karşımıza `4` karakteri çıktı. Baktığımız şey `%d` olsaydı, 4 baytlık alanın tamamı mı okunurdu, yoksa yalnız bir baytlık kısmın tamsayı karşılığı mı verilirdi? **Cevap:** Hoca, `%d` ile o adresten başlayarak 4 baytlık alanın alınıp gösterileceğini söyledi ve denedi; ekranda 52 çıktı. Hoca bunu biçim belirteçlerinin (format specifier) önemine bağladı.

> **Ders sonrası not:** Hocanın açıklaması doğru değildir. `*pch` bir `char`'dır; `printf`'e `int`'e yükseltilerek tek bir bayt olarak gider, `%d` bellekten 4 bayt okumaz. 52, `'4'` karakterinin ASCII kodudur: `%c` ile `4` olarak görünen aynı bayt, `%d` ile 52 olarak yazılmıştır. 4 baytlık bir okuma için işaretçinin `int *` olması gerekirdi.

## Örnek Sorular

**1. Üç sayı için min makrosu** (ekrandan, 00:30:00)

Slayttaki alıştırma: "Try to expand min macro example for three numbers." `#define min(a, b) ((a) < (b) ? (a) : (b))` makrosunu üç sayının en küçüğünü bulacak biçimde genişletin. Hoca bunu öğrencilere bıraktı.

> **Çözüm (derste verilmedi):** `#define min3(a, b, c) (min(min((a), (b)), (c)))`. Önce ilk iki sayının küçüğü bulunur, sonra o üçüncüyle karşılaştırılır. `gcc -Wall` ile denendi: `min3(4, -2, 7)` = -2, `min3(5, 9, 1)` = 1, `min3(3, 3, 8)` = 3, `min3(-1, 0, -6)` = -6. Bölüm 3.2'deki yan etki burada daha da büyür: argümanlar iç içe genişlemede birden çok kez kopyalanır, bu yüzden `min3(x++, y, z)` gibi bir çağrı yapılmamalıdır.

**2. Makro yan etkisi** (ekrandan, 00:35:00)

`#define min(a,b) ((a) < (b) ? (a) : (b))` tanımlıyken `a = min(b++, c);` önişlemcide neye dönüşür? `b = 2`, `c = 4` ise işlemden sonra `a` ve `b` kaçtır?

Derste verilen çözüm: Satır `a = ((b++) < (c) ? (b++) : (c));` olur. `2 < 4` doğrudur, `b` 3 olur; doğru dalda `a = b++` ile `a = 3` atanır, `b` 4 olur. Sonuç: `a = 3`, `b = 4`.

**3. static ve otomatik değişken** (ekrandan, 01:15:00)

Bölüm 7.3'teki `increment()` fonksiyonu `main`'den üç kez çağrılırsa ekrana ne yazılır?

Derste verilen çözüm: `j:2 k:2`, `j:2 k:3`, `j:2 k:4`. `j` her çağrıda yeniden 1 ile ilklenir; `static` olan `k` yalnız bir kez ilklenir ve değerini korur.

**4. "What will happen?"** (ekrandan, 01:45:00)

Bölüm 10.3'teki `short i, j, *p` programının çıktısı nedir?

Derste verilen çözüm: Birinci `printf` `i:123 j:123`, ikinci `printf` `i:125 j:126` yazar. `j = *p;` bir derin kopyadır; sonra `i` ve `j` bağımsız artar.

**5. Fonksiyon çağrısında yedeklenenler** (derste sözlü, 00:37:03)

Bir fonksiyona gidip gelirken yapılan yedekleme ve geri yükleme işlemlerinde neler yedeklenir?

Derste verilen çözüm: Çalışılan satırın bilgisi (program sayacı), işlemci yazmaçlarının değerleri ve programdaki değişkenlerin değerleri. `return` görülünce geri yüklenir ve program kaldığı yerden devam eder.

**6. register değişkenin adresi** (derste sözlü, 01:37:05)

İşlemci yazmacında saklanan bir `register` değişkenin bellek adresi var mıdır?

Derste verilen çözüm: Yoktur; bu yüzden `register` değişkene `&` uygulanamaz.

**7. İşaretçi ataması yasal mı?** (derste sözlü, 01:58:12)

`int *pa, *ptt;` ve `int a;` için `pa = &a;` ve `ptt = pa;` yasal mıdır?

Derste verilen çözüm: İkisi de yasaldır; `&a` `int *` türündedir ve `pa`, `ptt` de `int *` türündedir. Atamada iki tarafın işaretçi türü aynıdır.

**8. "Bu nereden çıktı?"** (ekrandan, 02:05:00)

`printf("Bu nereden cikti %d %d %d", &pa, &pt, &ptt);` satırı neyi yazdırır? Üç değer aynı mı olur?

Derste verilen çözüm: Üç işaretçi değişkeninin kendi bellek adreslerini yazdırır; işaretçiler ayrı değişkenler olduğu için üç değer farklıdır (derste 2358832, 2358824, 2358816).

**9. * ve & zincirleri** (ekrandan, 02:15:00)

`pa`, `pt`, `ptt` üçü de `a`'yı gösteriyor ve `a = 100` iken `*&pa`, `&*pt`, `*&*&ptt`, `&*&pa`, `*&*pt`, `&*&ptt` ifadeleri neyi verir?

Derste verilen çözüm: `*&pa`, `&*pt`, `*&*&ptt` üçü de `a`'nın adresini verir (derste 2358844). `&*&pa` = `&pa`, `*&*pt` = `*pt` = 100, `&*&ptt` = `&ptt`.

## Dersin Toparlaması

Bu derste önce önişlemci işlendi. Makroların derleme öncesinde metin olarak yerine konduğu ("makro bize gelir, biz fonksiyona gideriz"), sabit ve tip tanımlamada nasıl kullanıldığı, fonksiyon benzeri makrolarda parantezlerin ve yan etkinin önemi görüldü. Makroların hız ve tipten bağımsızlık avantajları ile hata ayıklama güçlüğü ve yeniden değerlendirme dezavantajları karşılaştırıldı. `#undef`, hazır makrolar, koşullu derleme, `#include` ve başlık dosyası düzeni, `#line` tanıtıldı. Ardından depolama sınıflarına geçildi: kapsam ile ömür ayrımı, `static` ile otomatik değişken farkı, dört kapsam türü, global değişkenlerin neden yasak olduğu, tanım ile ima (`extern`) farkı ve `register`, `const`, `volatile` belirteçleri anlatıldı.

Dersin son bölümünde işaretçilere giriş yapıldı. Değişkenin özellikleri, işaretçi türlerinin birbirine atanamaması, adres ve içerik işleçleri, derin ve sığ kopyalama, `*` ile `&`'nin birbirini götürmesi ve işaretçi aritmetiğinin tipin boyutuyla ölçeklenmesi Dev-C++'ta çalıştırılarak gösterildi. Hoca bir sonraki derste dizilerin tanımlanmasından devam edileceğini; karakter dizileri, çok boyutlu diziler, işaretçi dizileri ve dinamik bellek ayırma konularına geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
