# Ders 22 Genişletilmiş Notu: Program Bölme ve Makefile, Makrolar, Bit İşlemleri, Dosya ve Özyineleme Örnekleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Programı Dosyalara Bölmek
- 2. Derleme Zinciri ve Nesne Dosyaları
- 3. Bağımlılık ve Makefile
- 4. Dev-C++ Projesinde Çok Dosyalı Derleme
- 5. Önişlemci Makrolarına Dönüş
- 6. Makro ve Fonksiyon Karşılaştırması
- 7. Makrolarda Sık Yapılan Hatalar ve Üç Sayının Minimumu
- 8. #undef, Hazır Makrolar ve Koşullu Derleme
- 9. Bit Düzeyinde İşlemler
- 10. Header Dosyalarında Yapılan Hata
- 11. Örnek: Binary Dosyaya Struct Yazma ve Kayıt Arama
- 12. Örnek: Diziyi Özyinelemeyle Ters Çevirme
- 13. Özyinelemeli Fonksiyonların Karmaşıklığı
- 14. Örnek: String ve String Dizisini Tersten Yazdırma
- Örnek Sorular
- Dersin Toparlaması

## 1. Programı Dosyalara Bölmek

Ders, önişlemci konusunda kalan birkaç başlıkla başladı. İlk konu, bir C projesinin birden fazla dosyadan oluşturulmasıydı. Bir proje birden çok `.c` dosyasından ve bunlarla ilişkili birden çok `.h` (header) dosyasından oluşabilir. Hoca bunun derste verilen projeyle ilgili olmadığını, orada tek dosya istendiğini belirtti; konu genel proje yönetimi içindir.

Ekrandaki "Splitting Your Program" slaytında şu maddeler vardı (ekrandan, 00:20:00):

- Dış C kütüphaneleriyle çalışırken birden fazla dosyada duran kodla uğraşmak gerekir.
- Kendi C fonksiyonları ve veri yapıları kütüphanenizi kurup tekrar kullanabilirsiniz.
- Header dosyası fonksiyon prototiplerini, veri yapısı tanımlarını, makro tanımlarını ve global verileri içerir; `.c` dosyası kodun tamamını içerir.
- Dosyalardan en az biri `main()` fonksiyonuna sahip olmalıdır.
- Başka bir dosyadaki fonksiyonu, yapıyı vb. kullanmak için ilgili `.h` dosyası `.c` dosyasına `#include` ile eklenir.
- İki dosyada aynı adlı fonksiyon bulunmamalıdır.
- Global değişkenlere dikkat edilmelidir.

Program bölmenin nedeni yönetimi kolaylaştırmak ve tekrar kullanılabilirliği artırmaktır. Hoca bunun eskiden, bellek kısıtlı olduğu dönemlerde daha çok yapıldığını anlattı: matematik ya da dosya işlemleri gibi sık kullanılan kodlar bir kez yazılıp derlenir, saklanır ve daha sonra projeye eklenirdi. Nesneye yönelik dillerde bu düzen hâlâ yaygındır; C'de bugün biraz daha az kullanılır.

`#include` yönergesinin iki biçimi vardır. Açılı parantezli biçim (`#include <stdio.h>`) derleyicinin standart kütüphane dizinlerinde arar. Tırnaklı biçim (`#include "salute.h"`) önce üzerinde çalışılan dosyanın bulunduğu klasöre bakar. Bir `.c` dosyası ile onun header dosyasına aynı adı vermek (örneğin `salute.c` ve `salute.h`) gelenektir.

Slayttaki örnekte bir `main.c` dosyası, bir header dosyasını ekleyip o header'da prototipi bulunan bir fonksiyonu çağırıyordu. Header'ın içinde, bir makro tanımlı değilse onu tanımlayan bir koşullu önişlemci bloğu ve fonksiyonun prototipi vardı. Fonksiyonun gövdesi ayrı bir `.c` dosyasındaydı ve o dosya da aynı header'ı ekliyordu. <!-- BELİRSİZ: slayttaki bu ilk örneğin dosya adları ve header içeriği karede görülmedi; altyazıda "say.h", "sayHello" ve "num" diye geçiyor. -->

## 2. Derleme Zinciri ve Nesne Dosyaları

Bir C programının çalıştırılabilir dosyaya dönüşmesi birkaç aşamadan geçer:

- **Önişlemci (preprocessor):** Makro ve sabit tanımlarını açar, `#include` ile belirtilen dosyaları ekler.
- **Derleyici (compiler):** C kodunu assembly koduna çevirir.
- **Assembler:** Assembly kodunu makine koduna, yani nesne dosyasına (`.o`) çevirir.
- **Bağlayıcı (linker):** Derlenmiş nesne dosyalarını ve kütüphaneleri programa bağlar, sonuçta çalıştırılabilir dosyayı üretir.

Hoca burada önemli bir noktaya dikkat çekti: daha önce derlenmiş ve değiştirilmemiş kod yeniden derlenmez. Örneğin `printf` ve `scanf` gibi fonksiyonlar önceden derlenmiş olarak saklanır ve bağlama aşamasında programa eklenir. `salute` örneğinde `main.c` derlenince `main.o`, `salute.c` derlenince `salute.o` oluşur; linker bu iki nesne dosyasını birleştirerek tek bir çalıştırılabilir dosya üretir.

## 3. Bağımlılık ve Makefile

Projede 20-30 dosya olduğunu ve hepsini sizin yazdığınızı düşünün. Her denemede bütün dosyalar için derleme komutlarını tek tek yazıp her şeyi yeniden derlemek hem uzun hem gereksizdir. Makefile, derleme işinin "kodunu" bir kez yazmayı sağlar. `make` aracı bir dosya daha önce derlenmiş ve o zamandan beri değişmemişse onu yeniden derlemez.

### 3.1 Bağımlılık ağacı

Slayttaki "How Dependency Works" örneğinde şu bağımlılık ağacı vardı (ekrandan, 00:25:00):

```text
project1
├── data.o  <- data.c, data.h
├── main.o  <- data.h, main.c, io.h
└── io.o    <- io.h, io.c
```

Senaryo şöyledir (ekrandan, 00:25:00):

- Programı test ederken `io.c` içindeki bir fonksiyonda hata olduğunu fark ediyorsunuz.
- Hatayı düzeltmek için `io.c` dosyasını değiştiriyorsunuz.
- `io.c` değiştiği için `io.o` güncellenmelidir.
- `io.o` değiştiği için `project1` de güncellenmelidir.

Benzer şekilde `data.h` değişirse hem `data.o` hem `main.o` etkilenir. Bu ilişkiler bir ağaç olarak çıkarılabilir; elle takip etmek zahmetli ve hataya açıktır. Makefile bu sorunu çözer.

### 3.2 Örnek makefile

Hocanın anlattığı örnek makefile'da önce `project1` hedefinin `data.o`, `main.o` ve `io.o` dosyalarından oluştuğu ve gcc'nin bu üç nesne dosyasını birleştirerek `project1` çalıştırılabilir dosyasını üreteceği yazılır. Sonra her nesne dosyasının hangi dosyalardan ve hangi komutla üretileceği tanımlanır. Yukarıdaki ağaca göre yapı şöyledir:

```text
project1: data.o main.o io.o
	gcc data.o main.o io.o -o project1

data.o: data.c data.h
	gcc -c data.c

main.o: data.h io.h main.c
	gcc -c main.c

io.o: io.h io.c
	gcc -c io.c
```

<!-- BELİRSİZ: slayttaki makefile metni karede görülmedi; yukarıdaki yapı bağımlılık ağacından ve hocanın anlatımından kuruldu, komut satırlarının biçimi (bayraklar) slayttakinden farklı olabilir. -->

> **Ek bilgi (derste anlatılmadı):** Makefile'da komut satırları boşlukla değil bir sekme (TAB) karakteriyle başlamalıdır. `make` bir hedefin dosya tarihini bağımlılıklarının tarihleriyle karşılaştırır; bağımlılıklardan biri hedeften yeniyse komutu çalıştırır.

Derleme yapılırken bu komutlar her seferinde yazılmaz; yalnız `make` çağrılır. Dosyanın adı geleneksel olarak `Makefile`'dır.

### 3.3 Makefile içinde makro

Makefile'da da makro (değişken) tanımlanabilir. Örneğin nesne dosyalarının listesi bir değişkene atanır ve makefile'ın her yerinde bu değişken kullanılır. Bu tanımların C koduyla ilgisi yoktur; satır sonunda noktalı virgül bulunmaz. Böylece makefile kısalır.

> **Ek bilgi (derste anlatılmadı):** Bu tür bir tanım genelde `OBJECTS = data.o main.o io.o` biçiminde yazılır ve `$(OBJECTS)` diye kullanılır.

Hoca makefile'ın çok uzun ve ayrıntılı bir konu olduğunu, ileride ilgilenmek isteyenler için slaytta iki kaynak gösterildiğini söyledi. Bu bilginin özellikle gömülü sistemler ve düşük seviyeli programlama yapılan yerlerde, eski işletim sistemlerinde ve gömülü sistemlerde hâlâ kullanıldığını belirtti. Ayrıca bir programın derlenmesi ve bağlanmasının adım adım, hiçbir aşama atlanmadan anlatılmasının bir soru olarak karşınıza çıkabileceğini ekledi.

## 4. Dev-C++ Projesinde Çok Dosyalı Derleme

Hoca örneği Dev-C++'ta gösterdi. `salute.c` tek başına açılıp derlenmeye çalışıldığında bağlayıcı hata verdi: `undefined reference to 'WinMain'` ve `ld returned 1 exit status` (ekrandan, 00:30:00). Bunun nedeni dosyada `main` fonksiyonu bulunmaması ve dosyaların bir proje olarak birlikte derlenmemesidir. Bunun üzerine yeni bir "Console Application", "C Project" oluşturuldu; projeye `main.c`, `salute.h` ve `salute.c` eklendi.

`salute.c` dosyası (ekrandan, 00:30:00):

```c
/* salute.c implements the .h in a .c file: */

#include <stdio.h>
#include "salute.h"
void salute( void ) {
    printf("\n\n HELLO!!! \n\n");
}
```

`main.c` dosyası (ekrandan, 01:05:00):

```c
#include <stdio.h>
#include "salute.h"
int main ( void ) {
    salute();
    return 0;
}
```

`salute.h` dosyası beş satırdı: bir yorum (prototipleri içerdiğini söyleyen), bir `#ifndef` satırı, bir `#define` satırı, `void salute(void);` prototipi ve `#endif` (ekrandan, 01:20:00). <!-- BELİRSİZ: salute.h içindeki koruma makrosunun adı karede kesik. -->

Proje derlendiğinde Dev-C++ arka planda bir makefile üretti ve `make` aracını çalıştırdı. Proje klasöründe nesne dosyaları oluştu. Hoca üretilen makefile'ın içeriğini gösterdi: projenin hangi nesne dosyalarından oluşacağı, `main.c` ve `salute.c`'den hangi `.o` dosyalarının üretileceği, C++ için `g++`, C için `gcc` derleyicisinin kullanılacağı, bağlanacak kütüphaneler, optimizasyon bayrakları ve eski dosyaları silen bölümler bu dosyada tanımlıydı. Hoca, IDE'de "derle" ya da "çalıştır" düğmesine basıldığında arka planda olanın bu olduğunu vurguladı. Program çalıştırıldığında `main`, header aracılığıyla `salute.c`'deki fonksiyonu çağırdı ve mesaj ekrana yazıldı.

Ders arasından sonra hoca bir noktayı daha gösterdi: `main.c` içinde `salute.c` hiçbir şekilde eklenmez; yalnız `salute.h` eklenir. Fonksiyonun gövdesiyle bağlantıyı derleme sonrası linker kurar.

## 5. Önişlemci Makrolarına Dönüş

Hoca, dönem başında anlatılan önişlemci konusunu hızlıca özetledi ve daha önce görülmeyen bazı yönergeleri ekledi. Önişlemci komutları program derlenmeden önce işlenir. Şimdiye kadar çoğunlukla `#define` ve `#include` kullanıldı.

### 5.1 Makro ve fonksiyon çağrısı farkı

Makro, fonksiyona benzeyen bir yapıdır, ama çalışma biçimi farklıdır. Bir fonksiyon çağrıldığında program fonksiyonun bulunduğu yere atlar (assembly'deki karşılığıyla jump/call). Bu sırada program sayacı, bayrak yazmacı ve o anki değişkenlerin değerleri yığına (stack) kaydedilir; fonksiyon bitince bu bilgiler geri alınır. Sürekli fonksiyon çağırmak sürekli dallanma, yığına kopyalama ve geri dönme demektir; bu süreç zaman alır.

Hoca farkı şöyle özetledi: fonksiyonda biz fonksiyonun bulunduğu yere gideriz; makroda ise makronun gövdesi bizim bulunduğumuz yere gelir. Makro adı her geçtiği yerde gövdesiyle yer değiştirir. Buna yerine koyma (substitution) ya da açılım (expansion) denir. Bu yüzden programın yazılmış hali ile derlenmiş hali arasında ciddi fark olabilir.

### 5.2 Makro yerine koyma

"Macro substitution" slaytı (ekrandan, 00:40:00):

- Makro, makro gövdesi denen bir metin parçasıyla ilişkilendirilmiş bir addır.
- Sabit belirten makro adları geleneksel olarak yalnız büyük harflerle yazılır. Bu, makro adlarını değişken adlarından ayırmayı kolaylaştırır.
- Makro adı tanımı dışında bir yerde geçtiğinde gövdesiyle değiştirilir. Bu değiştirme işlemine makro açılımı (macro expansion) denir.

Slayttaki örnek (ekrandan, 00:40:00):

```c
#define BUFF_LEN   512
char buf[BUFF_LEN];
char buf[512];      /* önişlemciden sonraki hali */
```

Hoca, gövdenin çok daha uzun işlemler de olabileceğini söyledi. Örneğin bir dosya açma komutu (`fopen` ve dosya adı) bir makroya konursa, kodda o makronun geçtiği her yere bu komut kopyalanır.

Bir makro birden fazla satıra yayılacaksa satır sonuna ters bölü (`\`) konur. Makro tanımının sonuna noktalı virgül konmaz ve tanımda eşittir işareti kullanılmaz.

### 5.3 Fonksiyon benzeri makrolar

Fonksiyon benzeri bir makro yazmak için makro adından hemen sonra parantez içinde argümanlar virgülle ayrılarak yazılır; bir boşluk bırakıldıktan sonra makronun gövdesi gelir. Gövdede her parametre ayrıca parantez içine alınmalıdır. Hoca bunun nedenini yan etki örnekleriyle gösterdi.

Bir sayıyı iki katına çıkaran bir makro, kodda bir değişkene atanacak şekilde çağrıldığında bir fonksiyona gidilmez; çağrı yerinde ifade açılır (örneğin 5 için `5 + 5` hesaplanır) ve sonuç değişkene atanır. Makro tanımında tip belirtilmediği için aynı makro `int` için de `double` için de kullanılabilir.

İki sayının küçüğünü bulan makro slayttaki gibidir (ekrandan, 00:50:00):

```c
#define min(a,b)  ((a) < (b) ? (a) : (b))
```

### 5.4 Parametrelerin parantez içinde olması

Hoca bir makroya `a-1` gönderildiğini ve `a`'nın değerinin 3 olduğunu düşündürdü. Makroya önce `3-1` hesaplanıp 2 gitmez; `3-1` metni olduğu gibi gider. Gövdede yalnız toplama varsa bu bir sorun yaratmaz, çünkü işlemler aynı öncelikte kalır. Ama gövdede çarpma olsaydı ve parametreler parantezsiz yazılsaydı ifade `3-1*3-1` olurdu: önce `1*3 = 3` hesaplanır, `3-3-1 = -1` bulunur. Beklenen sonuç ise $2 \cdot 2 = 4$'tür. <!-- BELİRSİZ: bu örnekte kullanılan makronun tanımı karede görülmedi; sayısal sonuç hocanın anlatımından alındı. -->

### 5.5 Yan etki (side effect)

"SIDE EFFECT" slaytı (ekrandan, 00:50:00):

```c
#define min(a,b)  ((a) < (b) ? (a) : (b))

z = min(x++, y);
/* önişlemci bunu şuna çevirir: */
z = ((x++) < (y) ? (x++) : (y));
```

Slayttaki açıklamaya göre, karşılaştırma doğru çıkarsa `x` iki kez artırılır; istenen bu değildir. Güvenli tarafta kalmak için makroya yan etkili operatör (`++`, `--`) içeren argüman verilmemelidir.

Hesap: `x = 1`, `y = 5` için önce `x++ < 5` karşılaştırılır (1 < 5, doğru) ve `x` 2 olur. Koşul doğru olduğu için `(x++)` dalı çalışır: `z` 2 değerini alır, `x` 3 olur (gcc ile denendi). Fonksiyon olsaydı `z = 1`, `x = 2` olurdu.

> **Ders sonrası not:** Slaytta "If b<c, it gets incremented twice" yazıyor; bu örnekte değişkenler `x` ve `y` olduğu için doğrusu "`x < y` ise `x` iki kez artar"dır.

## 6. Makro ve Fonksiyon Karşılaştırması

"macros vs. functions" slaytı (ekrandan, 00:45:00):

| Avantajlar | Dezavantajlar |
|---|---|
| Makrolar fonksiyon çağrısı yükünden (function call overhead) kurtardığı için genelde fonksiyonlardan hızlıdır. | Makro argümanları gövdede her geçtiğinde yeniden hesaplanır; argüman yan etki içeriyorsa beklenmedik davranış oluşur. |
| Argümanlara tip kısıtı konmaz; bir makro birden çok veri tipi için çalışabilir (tüm veri tipleri için çalışan genel fonksiyonları makrolar kadar kolay yazamazsınız). | Fonksiyon gövdeleri bir kez derlenir ve çağrılar aynı kodu paylaşır; makrolar ise programda her geçtikleri yerde açılır. |
| | Makrolar argüman sayısını denetler, argüman tiplerini denetlemez. |
| | Makro içeren programlarda hata ayıklamak daha zordur, çünkü kaynak kod ek bir çeviri katmanından geçer. |

Hoca avantajları şöyle açıkladı: tip kısıtı olmadığı için aynı makro `int`, `float`, `char` ya da bir struct için kullanılabilir. C'de bütün veri tipleri için çalışan genel bir fonksiyon yazmak pek mümkün değildir; `void` işaretçilerle kısmen yapılabilir, ama makrolarla daha kolaydır. Dezavantajlarda ise derlenmiş bir fonksiyon çağrıldığında herhangi bir açılım olmadığını, makroda ise her çağrının bir kopyala-yapıştır gibi davrandığını vurguladı. Gönderilen argümanların doğruluğu, C'nin genelinde olduğu gibi, programcının sorumluluğundadır. Makrolar doğrudan açıldığı için adım adım (step by step) hata ayıklama ile alt adımları incelemek mümkün değildir.

## 7. Makrolarda Sık Yapılan Hatalar ve Üç Sayının Minimumu

### 7.1 Üç sık hata

Hoca makro yazarken en çok yapılan hataları sıraladı:

- Makro tanımının sonuna noktalı virgül koymak.
- Makro tanımında eşittir işareti kullanmak.
- Gövdede parametreleri ayrı ayrı parantez içine almamak.

Eşittir hatası için hoca şu durumu anlattı: `#define N = 100` gibi bir tanım yapılırsa makro gövdesi `= 100` olur. Hoca bunun kullanıldığı satırda bir ilk değer atama yerine `== 100` gibi bir karşılaştırma ifadesine dönüşebileceğini, sonucun 0 ya da 1 olup programın hata vermeden çalışmaya devam edebileceğini söyledi; bu yüzden dikkat edilmelidir. <!-- BELİRSİZ: slayttaki hatalı makronun tam tanımı ve kullanıldığı satır karede görülmedi. -->

> **Ders sonrası not:** Hatanın sonucu makronun kullanıldığı yere bağlıdır. Örneğin `int j = N;` satırı `int j = = 100;` olarak açılır ve derleme hatası verir. Yani bu hata her zaman sessiz kalmaz, ama her durumda istenen anlam bozulur.

Parantez hatası için örnek:

```c
#define SQUARE(x) x*x
```

`SQUARE(3+4)` çağrısı `3+4*3+4` olarak açılır. Önce çarpma yapılır: $4 \cdot 3 = 12$, sonra $3 + 12 + 4 = 19$ bulunur. İstenen ise $7^2 = 49$'du (gcc ile denendi: çıktı 19). Doğru tanım `#define SQUARE(x) ((x)*(x))` biçimindedir.

> **Ders sonrası not:** Hoca hesaplarken önce "38 gibi bir şey" dedi ve istenen sonucu "2 çarpı 7'nin karesi" olarak andı. Doğrusu: parantezsiz makronun sonucu 19, istenen sonuç $7^2 = 49$'dur.

### 7.2 Üç ve dört sayının minimumu

Hoca, iki sayının küçüğünü bulan `min` makrosunu üç sayı için uyarlamayı sordu. Öğrencilerden gelen cevaplardan birinde üç parametreli uzun yeni bir makro yazılmıştı; diğerinde mevcut makro iç içe çağrılmıştı. Hoca ikisinin de doğru olduğunu, ama iç içe çağrının daha pratik olduğunu söyledi:

```c
#define min(a,b)  ((a) < (b) ? (a) : (b))

m3 = min(a, min(b, c));          /* üç sayının en küçüğü */
m4 = min(min(a, b), min(c, d));  /* dört sayının en küçüğü */
```

Açılım şöyle işler: önişlemci önce `min(b, c)` yerine onun gövdesini koyar, sonra dıştaki `min(a, ...)` için gövdeyi bir kez daha kopyalar. Üç sayı için ayrı bir makro, dört sayı için ayrı bir makro yazmak gerekmez; her şey zaten yerine koyma ile açılacağı için en basit makroyu iç içe kullanmakla uzun makroyu yazmak arasında sonuç bakımından fark yoktur (gcc ile denendi: `min(4, min(2, 7)) = 2`, `min(min(9, 3), min(6, 8)) = 3`).

> **Hocanın vurgusu:** Basit bir makro verilip bir makro çağrısının yerine koymadan sonraki halini yazmanız istenebilir. İç içe çağrıdan uzun açılımı üretebilmeniz gerekir; burada çok hata yapılıyor.

## 8. #undef, Hazır Makrolar ve Koşullu Derleme

### 8.1 #undef

Tanımlanmış bir makro kaldırılabilir. Üzerinde değişiklik yapılacaksa önce `#undef` ile tanım iptal edilir, sonra yeniden tanımlanır:

```c
#undef min
/* artık min yeniden tanımlanabilir */
```

### 8.2 Hazır makrolar ve CHECK örneği

Hazır (built-in) makrolar dönem başında görülmüştü: hangi satırda olunduğu (`__LINE__`), hangi dosyada olunduğu (`__FILE__`), saat (`__TIME__`), tarih (`__DATE__`) ve derleyicinin ANSI standardına uyup uymadığı (`__STDC__`).

Slayttaki bir örnekte birden fazla satıra yayılan bir `CHECK` makrosu tanımlanmıştı. Makro iki değeri karşılaştırır; değerler farklıysa normal bir `fail` fonksiyonunu, iki değerle birlikte dosya adı ve satır numarasını vererek çağırır. Fonksiyon "check failed in file ... at line ..." biçiminde, alınan (received) ve beklenen (expected) değerleri gösteren bir mesaj yazar. Örneğin `x` ile `0` kontrol edilirken önce makro açılır, makro içinden fonksiyon çağrılır ve dosya ile satır bilgisini başka hazır makrolar sağlar. Yani bir makro normal bir fonksiyonu tetikleyebilir. Hoca bu tarz makroların projelerde kolaylık sağlayacağını söyledi. <!-- BELİRSİZ: CHECK makrosunun kodu karede görülmedi; açıklama altyazıdan. -->

### 8.3 Koşullu derleme

Belirli bir koşula göre derleme yapılabilir: bir makro tanımlıysa şu kodu, tanımlı değilse önce tanımlayıp bu kodu derle gibi. `#if`, `#elif`, `#else` ve `#endif` yönergeleri bir switch yapısına benzer: `#if` ilk durumdur, `#elif`'ler diğer durumlar, `#else` varsayılan durumdur.

"conditional compilation" slaytındaki kurallar (ekrandan, 00:55:00):

- `#if` ya da `#elif` satırındaki koşulun parantez içine alınması gerekmez.
- Koşullu önişlemci yönergesinin kontrolündeki deyim blokları süslü paranteze alınmaz.
- Her `#if` bloğunda istenen sayıda `#elif` bulunabilir, ama en fazla bir `#else` bulunabilir ve o da en sonda olmalıdır.
- Her `#if` bloğu bir `#endif` ile bitmelidir.

Slayttaki örnek (ekrandan, 00:55:00):

```c
#if   x==1
      #undef  x
      #define x 0
#elif x == 2
      #undef  x
      #define x 3
#else
      #define y 4
#endif
```

`x` 1 ise önce tanımı kaldırılır, sonra 0 olarak yeniden tanımlanır. `x` 2 ise kaldırılıp 3 olarak tanımlanır. Hiçbiri değilse `y` 4 olarak tanımlanır.

Tipik bir kullanım hata ayıklama kodudur: `DEBUG` tanımlıysa belirli işlemler (örneğin ara değerleri yazdırma) derlenir, değilse derlenmez. Hoca bunların eskiden çok sık kullanıldığını, bugün daha az kullanıldığını söyledi.

### 8.4 #ifdef, #ifndef ve defined

`#if` ile `defined` birlikte kullanılabilir; bunu kısaltan `#ifdef` ve `#ifndef` yönergeleri de vardır. Slayttaki örneklerde `TEST` adlı bir makro tanımlıysa "This is a test", değilse "This is not a test" yazdıran bir kontrol yapıldı. Başka bir örnekte `FALSE` tanımlı değilse tanımlanıyor, tanımlıysa önce `#undef` ile kaldırılıp yeniden tanımlanıyordu. `#ifndef` kullanıldığında ayrıca `defined` yazmaya gerek kalmaz. <!-- BELİRSİZ: bu slaytların kodu karede görülmedi. -->

> **Ek bilgi (derste anlatılmadı):** `#ifdef X` ifadesi `#if defined(X)` ile, `#ifndef X` ifadesi `#if !defined(X)` ile aynı anlamdadır. Header dosyalarındaki `#ifndef ... #define ... #endif` koruması aynı header'ın bir derleme biriminde iki kez eklenmesini önler.

## 9. Bit Düzeyinde İşlemler

Önişlemciden sonra kalan son konu bit düzeyinde (bitwise) işlemlerdi. Bunlar hem gömülü sistemlerde hem de uygulamalarda karşılaşılan operatörlerdir; mantık devrelerindeki işlemlerin çoğu burada bit bazında kullanılır.

### 9.1 Operatörler

| Operatör | İşlem | Kural |
|---|---|---|
| `&` | AND | İki bit de 1 ise sonuç 1, aksi halde 0 |
| `\|` | OR | Bitlerden biri 1 ise sonuç 1 |
| `^` | XOR | Bitler aynıysa 0, farklıysa 1 |
| `~` | Bire tümleme (NOT) | Her bit tersine çevrilir |
| `<<` | Sola kaydırma | Bitler sola kayar, sağdan 0 gelir |
| `>>` | Sağa kaydırma | Bitler sağa kayar, taşan bitler kaybolur |

> **Hocanın vurgusu:** `^` operatörünü üs alma sanıp kullananlar var. C'de `^` üs alma değildir, XOR'dur.

Hoca bit düzeyindeki `&` ve `|` işlemlerinin `if` koşullarındaki mantıksal `&&` ve `||` ile karıştırılmaması gerektiğini de söyledi: mantıksal operatörler iki koşulun sonucunu birleştirir, bit operatörleri ise sayıların her bitini karşılıklı işler.

### 9.2 Ekrandaki örnek kod

Ekrandaki `Bitwise.c` dosyasında `a`, `b` işaretsiz tamsayı olarak tanımlanmış, `int c = 0;` ve `int x = 30;` satırları vardı; ardından `c = a & b;`, `c = a | b;`, `c = a ^ b;`, `c = ~a;`, `c = a << 2;`, `c = a >> 2;` işlemleri yapılıp her biri yazdırılıyordu (ekrandan, 01:00:00). Hoca örnekte `a = 60`, `b = 13` olduğunu söyledi. Hoca bir `int`'in 4 bayt olduğunu, bu yüzden 60'ın ikilik karşılığının önünde 0'lardan oluşan başka baytlar da bulunduğunu hatırlattı.

> **Çözüm (derste verilmedi):** `a = 60` (`0011 1100`), `b = 13` (`0000 1101`) için: `a & b = 12` (`0000 1100`), `a | b = 61` (`0011 1101`), `a ^ b = 49` (`0011 0001`), `a << 2 = 240`, `a >> 2 = 15`. `~a` bütün 32 biti tersine çevirir; `unsigned int` olarak yazdırılınca 4294967235, `int` olarak yorumlanınca $-61$ olur (gcc ile denendi).

### 9.3 AND ve OR örneği

Hoca 24 ile 17'yi kullanarak işlemleri tahtada gösterdi (ekrandan, 01:05:00). $24 = 16 + 8$ olduğundan ikilik karşılığı `11000`, $17 = 16 + 1$ olduğundan `10001`'dir.

```text
   24 = 1 1 0 0 0
   17 = 1 0 0 0 1
  ---------------
  AND = 1 0 0 0 0  = 16
   OR = 1 1 0 0 1  = 25
```

AND'de karşılıklı bitlerin ikisi de 1 ise sonuç 1'dir; yalnız en soldaki bitte iki taraf da 1 olduğundan sonuç $16$'dır. Hoca önce sonucu 8 olarak söyledi, sonra düzeltip 16 dedi. OR'da bitlerden biri 1 ise sonuç 1'dir: $16 + 8 + 1 = 25$. Sonuç `printf` ile yazdırılırsa bu değerler görülür. XOR'da bitler aynıysa sonuç 0, farklıysa 1'dir; `~` ise sayının bire tümleyenini alır.

> **Çözüm (derste verilmedi):** `24 ^ 17 = 01001 = 9` (gcc ile denendi).

### 9.4 Kaydırma

Bitleri sola kaydırmak sayıyı 2 ile çarpmak, sağa kaydırmak 2'ye bölmek gibidir. Hoca `a = 5` örneğini kullandı (ekrandan, 01:05:00). $5$'in ikilik karşılığı `0101`'dir; önünde 4 bayta kadar 0'lar vardır. Sola kaydırılınca 0 ve 1'ler sola doğru gider, sağdan boşalan yerlere 0 gelir. Sağa kaydırmada ise sağdan taşan bitler başa dönmez, kaybolur; soldan 0 gelir. Bir kez sağa kaydırınca $5 / 2 = 2$, bir kez daha kaydırınca $1$ elde edilir.

```text
a      = 0000 0101   (5)
a << 2 = 0001 0100   (20)
a >> 2 = 0000 0001   (1)
```

> **Ders sonrası not:** Hoca `a << 2` için sonucun 10 olacağını söyledi (tahtada da `010100` yazdı). Doğrusu: `5 << 2 = 20`, `5 << 1 = 10`. Ayrıca hoca bu işlemlere "rotate" dedi; C'deki `<<` ve `>>` döndürme değil kaydırma (shift) işlemidir; hocanın da belirttiği gibi taşan bitler geri gelmez (gcc ile denendi: `5<<2 = 20`, `5>>2 = 1`, `5<<1 = 10`, `5>>1 = 2`).

Hoca bit işlemlerinin özellikle mülakat tarzı sorularda karşımıza çıktığını ekledi.

## 10. Header Dosyalarında Yapılan Hata

Aradan sonra hoca program bölme konusuna kısa bir ek yaptı. Bazı öğrenciler programı bölmüş olmak için fonksiyonların implementasyonlarını (gövdelerini) header dosyalarına koyuyor. Bu doğru değildir. Bölme yapılacaksa implementasyon `salute.c` örneğinde olduğu gibi bir `.c` dosyasına yazılır. Header'da yalnız fonksiyon prototipleri, makro tanımları ve struct tanımları bulunabilir; header'ın amacı budur. Hoca bunu nesneye yönelik dillerdeki arayüzlere (interface) benzetti. Örnek hata olarak bir `main.c` ile birlikte dört ayrı `.h` dosyası açılmış ve fonksiyonların gövdelerinin bu `.h` dosyalarına yazılmış olduğu bir durumu anlattı.

## 11. Örnek: Binary Dosyaya Struct Yazma ve Kayıt Arama

Hoca bu dersten sonra yeni konu anlatmayıp çeşitli konulardan örnekler yapacağını söyledi. İlk örnek, `fwrite` ve `fread` ile binary bir dosyaya yazma ve dosyada kayıt aramaydı.

### 11.1 Struct ile yapılandırılmış kayıt

Dosya projede olduğu gibi yapılandırılmışsa, onu bir struct üzerinden okumak kod yazarken büyük avantaj sağlar; her alan için ayrı değişken tutmak gerekmez. Öğrenci kaydı ad, numara ve puan alanlarından oluşur (ekrandan, 01:25:00):

```c
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct ogr{
    char ad[MAX];
    int no;
    int puan;
}OGR;
```

### 11.2 Dosya adı kullanıcıdan alınır

> **Hocanın vurgusu:** Hiçbir projede dışarıdan girilecek bir veri kodun içine gömülmez. Biri "şu dosyayı okuyacağım" dediğinde kodu açıp dosya adını değiştirmezsiniz; dosya adı kullanıcıdan alınır ve program buna göre tasarlanır.

### 11.3 Yazma fonksiyonu

`print_file` fonksiyonu dosya adını parametre olarak alır, dosyayı binary yazma kipinde (`"wb"`) açar, kullanıcıdan öğrenci sayısını alır (ekrandan, 01:25:00). Döngü içinde her öğrencinin adı, numarası ve puanı klavyeden okunur. Hoca burada `fscanf` fonksiyonunu dosya yerine standart girişle (`stdin`) kullandı; yani `fscanf(stdin, ...)` klavyeden okur. Okunan struct tek seferde, tek blok halinde `fwrite` ile yazılır: `fwrite` önce yazılacak verinin adresini (`&e`), sonra bir kaydın boyutunu (`sizeof(OGR)`), kaç kayıt yazılacağını (1) ve dosya işaretçisini alır. Döngü bitince dosya `fclose` ile kapatılır.

```c
void print_file(char ad[20]){
    int N, i;
    OGR e;
    FILE *fp=fopen(ad,"wb");
    printf("Ogrenci Sayisi giriniz"); scanf("%d",&N);
    printf("Bilgiler\n Ad  - No  -  Puan\n");
    for(i=0;i<N;i++){
        fscanf(stdin,"%s %d %d",e.ad,&e.no,&e.puan);
        fwrite(&e,sizeof(OGR),1,fp);
    }
    fclose(fp);
}
```

Fonksiyonun ilk altı satırı ve döngü başlığı ekrandan alındı (ekrandan, 01:25:00 ve 01:35:00); döngü gövdesi ve `fclose` satırı hocanın anlatımından kuruldu. <!-- BELİRSİZ: döngü gövdesi karede görünmüyor; altyazıda fscanf(stdin, "%s %d %d", ...) ve fwrite(&e, sizeof(OGR), 1, fp) olarak anlatılıyor. -->

### 11.4 Okuma ve arama

`main` önce dosya adını alıp `print_file` ile kayıtları yazdırır. Sonra dosyayı binary okuma kipinde (`"rb"`) açar. Dosya işaretçisi `NULL` değilse kullanıcıdan aranacak öğrenci numarası alınır. Aranan kayıt ilk kayıt da olabileceği için önce bir `fread` yapılır, sonra bir `while` döngüsüyle kayıtlar okunmaya devam eder. Ekrandaki ilk sürüm şöyleydi (ekrandan, 01:35:00):

```c
int main(){
    char dosya[20];
    FILE *fp;
    int no;
    OGR ogr;
    printf("Dosya adı giriniz");
    scanf("%s",dosya);
    printf_file(dosya);
    fp=fopen(dosya,"rb");
    if(fp!=NULL){
        printf("Ogrenci No"); scanf("%d",&no);
    }
    fread(&ogr,sizeof(OGR),1,fp);
    while((ogr.no<no) && (!feof(fp))){
        fread(&ogr,sizeof(OGR),1,fp);
    }
    if(ogr.no==no){
        printf("Bulunan bilgiler");
        printf("\n%s %d %d\n",ogr.ad,ogr.no,ogr.puan);
    }
    else{
        printf("Kayıt bulunamadı");
    }
    retun 0;
}
```

`feof(fp)` dosyanın sonuna gelinip gelinmediğini denetler. Hoca koşulları ayrı ayrı paranteze aldı; böylece operatör önceliği hatırlanmasa bile `&&` ile karışma olmaz. Döngü, koşul sağlandıkça bir kayıt daha okur; döngüye hiç girilmeyebilir. Döngüden çıkınca kaydın bulunup bulunmadığına bakılır. Hoca, metin ya da binary formatta olsun, dosyada arama yaparken bir dizide arar gibi sıralı işlem yapmak gerektiğini söyledi.

Derleme sırasında projede `main.c` dosyası da bulunduğu için "multiple definition of main" hatası alındı; dosyalar kapatılıp örnek tek başına derlendi. `return` satırındaki yazım hatası da düzeltildi.

> **Ders sonrası not:** Ekrandaki kodda `main` içinde `printf_file(dosya)` çağrılıyor, fonksiyonun adı ise `print_file`; fonksiyon `main`'den sonra tanımlandığı için `main`'den önce bir prototip gerekir. `fread` ve arama satırları `if(fp!=NULL)` bloğunun dışında kaldığından dosya açılamazsa `NULL` işaretçiyle okunmaya çalışılır; okuma bloğun içine alınmalı ve dosya sonunda `fclose(fp)` ile kapatılmalıdır. Aşağıdaki düzeltilmiş sürüm gcc -Wall ile uyarısız derlendi ve denendi.

### 11.5 Programın çalıştırılması ve koşulun genelleştirilmesi

Program çalıştırıldı: dosya adı olarak bir `.dat` dosyası, öğrenci sayısı olarak 3 girildi ve kayıtlar yazıldı. İlk denemede aranan numara için "kayıt bulunamadı" çıktı. Hoca dosyayı Notepad++ ile açtı: binary dosyada adlar okunabilir, ama `int` alanlar ve dizinin kullanılmayan baytları NUL ve okunamayan karakterler olarak görünüyordu (ekrandan, 01:40:00). Hata ayıklayıcıda (debug) `ogr` ve `no` değişkenleri izlendiğinde okumanın doğru yapıldığı, ikinci denemede kaydın bulunduğu görüldü.

**Soru:** İlk denemede, dosyadaki ilk öğrencinin numarası girilen numaradan büyük olduğu için mi döngüye ve aramaya girilmedi? **Cevap:** Hoca kayıtları sırasız girmiş olabileceğini, bu yüzden bulunamadığını kabul etti. `ogr.no < no` koşulu ancak kayıtlar numaraya göre sıralıysa doğru çalışır. Kayıtların sıralı olduğu biliniyorsa (örneğin projede numaralar otomatik artan şekilde veriliyorsa) bu koşul işi kolaylaştırır. Genel çözüm için koşul "farklı olduğu sürece oku" yapılır:

```c
while((ogr.no!=no) && (!feof(fp))){
    fread(&ogr,sizeof(OGR),1,fp);
}
```

Böylece sıraya bakmadan arama yapılır: kayıt döngü içinde bulunursa döngüden çıkılır, bulunamazsa dosya sonuna kadar okunur. Sonuçta bulunup bulunmadığı yazdırılır.

Düzeltilmiş ve denenmiş tam program (prototip, `NULL` denetimi ve `fclose` eklendi, ara adım eklendi):

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct ogr{
    char ad[MAX];
    int no;
    int puan;
}OGR;

void print_file(char ad[20]);

int main(){
    char dosya[20];
    FILE *fp;
    int no;
    OGR ogr;
    printf("Dosya adi giriniz");
    scanf("%s",dosya);
    print_file(dosya);
    fp=fopen(dosya,"rb");
    if(fp!=NULL){
        printf("Ogrenci No"); scanf("%d",&no);
        fread(&ogr,sizeof(OGR),1,fp);
        while((ogr.no!=no) && (!feof(fp))){
            fread(&ogr,sizeof(OGR),1,fp);
        }
        if(ogr.no==no){
            printf("Bulunan bilgiler");
            printf("\n%s %d %d\n",ogr.ad,ogr.no,ogr.puan);
        }
        else{
            printf("Kayit bulunamadi\n");
        }
        fclose(fp);
    }
    return 0;
}

void print_file(char ad[20]){
    int N, i;
    OGR e;
    FILE *fp=fopen(ad,"wb");
    printf("Ogrenci Sayisi giriniz"); scanf("%d",&N);
    printf("Bilgiler\n Ad  - No  -  Puan\n");
    for(i=0;i<N;i++){
        fscanf(stdin,"%s %d %d",e.ad,&e.no,&e.puan);
        fwrite(&e,sizeof(OGR),1,fp);
    }
    fclose(fp);
}
```

Deneme: üç kayıt numaraları 3, 1, 2 sırasıyla girilip 2 numara arandığında `!=` koşuluyla kayıt bulundu. Aynı girdiyle ilk sürümdeki `<` koşulu ilk kayıtta (3 < 2 yanlış) döngüden çıktığı için "kayıt bulunamadı" verir; derste görülen durum budur.

### 11.6 Birden çok kayıt dönerse

Hoca şunu sordu: aranan alan numara değil de puan olsaydı ve aynı puanı alan birden fazla öğrenci olabilseydi ne yapmak gerekirdi? Hoca bunun veritabanı ve nesneye yönelik programlamanın konusu olduğunu söyleyip bir kitap sitesi örneği verdi: arama kutusuna bir harf yazınca o harfle başlayan bütün kitaplar gelir, her yeni harfle liste daralır, harf silinince yeniden genişler. Sorgu veritabanında da dosyada da yapılsa, sonuçlar bir tabloda ya da alt alta listelenecekse tek bir değişken yetmez. Okunan her kayıt dinamik bir struct dizisine eklenmelidir; çünkü dosyadan okunan verinin bellekte kalıcı bir adresi yoktur, belleğe kopyalanması gerekir.

**Soru:** Kayıt sayısı 100, 300 ya da $N$ olabiliyorsa bu dizi nasıl tanımlanır? **Cevap:** Bir öğrenci `malloc` ile tanımlanacağını söyledi; hoca doğruladı. Önce bir kayıtlık yer ayrılır, kayıt bulundukça alan genişletilir (`realloc`). Başka bir strateji nesneye yönelik dillerdeki ArrayList mantığıdır: önce örneğin 1000 elemanlık yer açılır; 500 kayıt kullanılırsa geri kalanı belleğe iade edilir, 1000 dolarsa boyut otomatik olarak yaklaşık 1,5 katına çıkarılır. Arka planda olan yine `malloc`/`realloc` işlemleridir; başlangıçta 10 açıp dolunca 20, 30 yapmak gibi stratejiler kullanılabilir. Okunan veri başka bir fonksiyona gönderilip işlenecek ya da başka bir dosyaya yazılacaksa dinamik bellek yönetimi daha da önemli hale gelir; normal bir dizi bu durumda sıkıntı yaratır.

## 12. Örnek: Diziyi Özyinelemeyle Ters Çevirme

Hoca özyinelemenin derste kısa görüldüğünü, gelecek derste bağlı listeler ve ikili arama ağacı (binary search tree) anlatılırken gezinme (traverse) işlemlerinde özyinelemeden yararlanılacağını, bu yüzden biraz daha ayrıntıya girmek istediğini söyledi.

### 12.1 Dizinin eleman sayısı

Örnek, `int a[] = {1,2,3,4,5};` dizisiyle başladı ve fonksiyon `reverse(a, 0, sizeof(a)/sizeof(a[1]))` biçiminde çağrıldı (ekrandan, 01:45:00).

**Soru:** `sizeof(a)` ve `sizeof(a)/sizeof(a[1])` ne verir? **Cevap:** `sizeof(a)` dizinin tamamının bayt cinsinden boyutudur; 5 tamsayı için ayrılan yer $5 \cdot 4 = 20$ bayttır. Bunu bir elemanın boyutuna (4 bayt) bölmek eleman sayısını, yani 5'i verir.

Hoca aynı hesabı bir makroyla da yaptı: `#define MAX(a) sizeof(a)` tanımlandı ve `int N=MAX(a)/MAX(a[1]);` yazıldı. Hata ayıklayıcıda `MAX(a) = 20`, `MAX(a[1]) = 4` ve `N = 5` görüldü (ekrandan, 01:55:00).

### 12.2 Elemanları yerinde bırakarak tersten yazdırma

İlk sürümde dizinin kendisi değişmez, elemanlar yalnız tersten yazdırılır. Fonksiyon dizinin ilk elemanının adresini (`int *ar`), bir başlangıç indisi `i` ve eleman sayısı `n` alır (ekrandan, 01:55:00):

```c
void reverse(int *ar, int i, int n){
    if(i<n){
        reverse(ar, i+1,n);
        printf("%d,", ar[i]);
    }
}
```

İzleme (hocanın tahtadaki çizimiyle, ekrandan, 01:50:00): ilk çağrı `(0, 5)` ile yapılır. $0 < 5$ olduğu için `(1, 5)` çağrılır; aynı şekilde `(2, 5)`, `(3, 5)`, `(4, 5)` ve `(5, 5)` çağrılır. `(5, 5)` çağrısında $5 < 5$ yanlış olduğu için hiçbir şey yapılmadan dönülür. Kontrol `(4, 5)` çağrısındaki özyinelemeli çağrı satırının sonrasına döner ve `ar[4] = 5` yazdırılır; bu çağrı da biter. Ardından `(3, 5)` çağrısı `ar[3] = 4`'ü, `(2, 5)` çağrısı 3'ü, `(1, 5)` 2'yi, `(0, 5)` 1'i yazdırır. Çağıracak başka fonksiyon kalmayınca işlem biter. Hoca bunu yığın (stack) mantığıyla düşünmek gerektiğini vurguladı.

Derste önce yazdırma satırında bir eksiklik nedeniyle çıktı beklenenden farklı çıktı; hata ayıklayıcıyla bakıldı ve `printf` satırı düzeltildi. Doğru çıktı (gcc ile denendi):

```text
1-2-3-4-5-
5,4,3,2,1,
```

### 12.3 Yer değiştirerek gerçekten ters çevirme

İkinci sürüm (`reverse2`) diziyi gerçekten ters çevirir: ilk ve son eleman yer değiştirir, sonra ortaya doğru ilerlenir. Bunun için geçici bir değişken gerekir. Burada `n` son elemanın indisidir, bu yüzden fonksiyon `reverse2(a, 0, N-1)` ile çağrılır; her adımda `i` bir artar, `n` bir azalır. `if(i<n)` koşulu bir `while` döngüsünün koşulu gibi düşünülebilir.

Ekrandaki kod (ekrandan, 02:00:00):

```c
void reverse2(int *ar, int i, int n){
    int tmp;
    if(i<n){
        tmp=ar[i];
        ar[i]=ar[n];
        ar[n]=tmp;
        reverse(ar,i+1,n-1);
    }
}
```

İzleme: `(0, 4)` ile `ar[0]` ve `ar[4]` yer değiştirir, dizi `5, 2, 3, 4, 1` olur. Sonra `(1, 3)` ile `ar[1]` ve `ar[3]` yer değiştirir, dizi `5, 4, 3, 2, 1` olur. `(2, 2)` çağrısında $2 < 2$ yanlış olduğu için dönülür. `(1, 3)` çağrısında başka işlem kalmadığı için o da döner, ardından `(0, 4)` döner ve kontrol `main`'e geri gelir.

> **Ders sonrası not:** Ekrandaki kodda özyinelemeli çağrı yanlışlıkla `reverse(ar,i+1,n-1)` olarak yazılmış; bu, yazdırma yapan ilk fonksiyonu çağırır. Hoca hata ayıklarken bunu fark etti ("reverse2 yapacaktık") ama kodu düzeltmeden devam etti. Bu haliyle yalnız ilk yer değiştirme yapılır, dizi `5, 2, 3, 4, 1` kalır ve araya `3,2,` yazdırılır. Doğrusu `reverse2(ar,i+1,n-1);` çağrısıdır. Düzeltilmiş sürüm gcc -Wall ile derlendi; çıktı `5-4-3-2-1-` oldu.

Düzeltilmiş tam program (gcc -Wall ile derlendi ve çalıştırıldı):

```c
#include <stdio.h>
#define MAX(a) sizeof(a)

void reverse(int *ar, int i, int n){
    if(i<n){
        reverse(ar, i+1,n);
        printf("%d,", ar[i]);
    }
}

void reverse2(int *ar, int i, int n){
    int tmp;
    if(i<n){
        tmp=ar[i];
        ar[i]=ar[n];
        ar[n]=tmp;
        reverse2(ar,i+1,n-1);
    }
}

int main(){
    int i, a[]={1,2,3,4,5};
    int N=MAX(a)/MAX(a[1]);
    for(i=0;i<N;i++){
        printf("%d-",a[i]);
    }
    printf("\n");
    reverse(a,0,N);
    printf("\n");
    reverse2(a,0,N-1);
    for(i=0;i<N;i++){
        printf("%d-",a[i]);
    }
    printf("\n");
    return 0;
}
```

Çıktı:

```text
1-2-3-4-5-
5,4,3,2,1,
5-4-3-2-1-
```

Hoca hata ayıklayıcıda "Into function" ile özyinelemeli çağrıların içine girmeyi gösterdi ve `ar[i]`, `ar[n]` değerlerini izledi.

> **Hocanın vurgusu:** Özyinelemeyi izlemenin (trace) en kolay yolu yığın çizmektir; arka planda yığın mantığıyla çalışır.

## 13. Özyinelemeli Fonksiyonların Karmaşıklığı

Hoca, özyinelemeli bir kodun karmaşıklığına kabaca ve hızlıca karar vermenin yolunu anlattı. Geri ve ileri yerine koyma (backward/forward substitution) yöntemleri ayrık matematikte görülmüştü, veri yapılarında daha ayrıntılı görülecek. Hızlı karar için verinin her çağrıda nasıl azaldığına ve kaç özyinelemeli çağrı olduğuna bakılır:

- Veri her çağrıda birer birer azalıyorsa ($n$'den 1'e) ve tek özyinelemeli çağrı varsa karmaşıklık $O(n)$'dir. Yukarıdaki `reverse` fonksiyonları bu türdendir.
- Veri her çağrıda yarıya iniyorsa ($n \to n/2$) ve tek çağrı varsa karmaşıklık $O(\log n)$'dir.
- Fibonacci gibi iki çağrı varsa ($f(i-1) + f(i-2)$), her çağrı kendi içinde yeniden iki çağrı yapar ve karmaşıklık $O(2^n)$ olur. Fibonacci'nin çağrı ağacı açıldığında ikili bir ağaç ortaya çıkar.
- Üç çağrının her biri $n-1$'e iniyorsa karmaşıklık $O(3^n)$ olur.

Hoca üç çağrının her biri $n/2$'ye inseydi durumun farklılaşacağını, karmaşıklığın "3 üzeri log n" gibi olacağını söyledi.

> **Ders sonrası not:** Hoca "3 üzeri log n" sonucunun yine üstel olduğunu söyledi. $T(n) = 3T(n/2) + c$ için çağrı sayısı $3^{\log_2 n} = n^{\log_2 3} \approx n^{1.585}$'tir; bu üstel değil, polinom bir büyümedir. Ayrıca $T(n) = 2T(n-1) + c$ için tam ifade $O(2^n)$, Fibonacci için daha sıkı sınır $O(\varphi^n)$ ($\varphi \approx 1.618$) olur; $O(2^n)$ bir üst sınırdır.

## 14. Örnek: String ve String Dizisini Tersten Yazdırma

### 14.1 Tek bir string

Bir string'i tersten yazdırırken eleman sayısını bilmeye gerek yoktur, çünkü string'in sonu özel bir karakterle (`'\0'`) belirlidir. Fonksiyon şöyledir (ekrandan, 02:10:00):

```c
void reverse(char *str){
    if(*str){
        reverse(str+1);
        printf("%c",*str);
    }
}
```

`if(*str)` "string'in sonuna gelmediysen" demektir: sona gelindiğinde `str`'nin gösterdiği yerdeki değer `'\0'`, yani 0 olur. Sona gelinmediyse önce bir sonraki karaktere gidilir (`reverse(str+1)`), dönüşte o anki karakter yazdırılır.

Hoca izlemeyi `"yapisal programlama"` string'i üzerinde yığın çizerek anlattı (ekrandan, 02:10:00). İlk çağrıya ilk karakterin adresi gelir; karakter 0'dan farklı olduğu için bir sonraki adresle yeni çağrı yapılır ve bu, yığına yeni bir kayıt eklenmesi demektir. Bu böyle sürer; `'\0'` karakterinin adresiyle yapılan çağrıda koşul sağlanmaz ve fonksiyon hemen döner (assembly'deki `ret` komutu gibi). Kontrol bir önceki çağrıya döner ve o çağrının karakteri yazdırılır; sonra o çağrı da biter ve bir öncekine dönülür. Hoca her çağrının yığında, kaldığı satırın numarasını (program sayacı, dönüş adresi) da sakladığını vurguladı: her çağrı özyinelemeli çağrının yapıldığı satırda kalmıştır ve döndüğünde bir sonraki satırdan, yani `printf` satırından devam eder. Böylece karakterler sondan başa doğru yazdırılır.

```c
int main(){
    char a[] = "yapisal programlama";
    reverse(a);
    ...
}
```

Çıktı (gcc ile denendi): `amalmargorp lasipay`.

### 14.2 String dizisi: char ** ile dinamik bellek

Son örnekte kullanıcıdan $n$ tane string alınıp ters sırayla yazdırıldı.

**Soru:** $n$ tane string dinamik bellekle saklanacaksa nasıl bir karakter işaretçisi tanımlanmalı: tek işaretçi mi, çift işaretçi mi? **Cevap:** Bir öğrenci "dizilerin dizisi" diye cevap verdi; hoca bunu doğruladı. Kullanıcıdan alınan bir string için saklanması gereken şey ilk karakterinin adresidir; yani string'in kendisi zaten bir işaretçidir. Bu tür birçok string saklanacağı için onların adreslerini tutacak bir üst seviye işaretçi gerekir. String'ler birinci dereceden işaretçi olduğuna göre, hepsini tutan yapı ikinci dereceden bir işaretçidir: `char **`.

Hoca bunu bir matrise benzetti: her satırda bir kelime vardır, ama satırların uzunlukları farklıdır. Her kelime bellekte ayrı bir dizi olarak durur; bu dizilerin ilk elemanlarının adreslerini tutan bir diziye ihtiyaç vardır. Hoca çift işaretçi kullanımının bazen karıştırıldığını, dikkat edilmesi gerektiğini söyledi.

Kod adım adım şöyle kuruldu (ekrandan, 02:15:00 ve 02:20:00):

- Eleman sayısı `n` kullanıcıdan alınır.
- `kelimeler = (char **) calloc(n, sizeof(char*));` ile $n$ tane karakter işaretçisi için yer ayrılır.
- Döngüde her kelime önce geçici bir diziye (`dummy`) okunur. Hoca, `scanf` ile `%s` kullanıldığı için kelimelerin içinde boşluk olmaması gerektiğini söyledi.
- `m = strlen(dummy);` ile kelimenin uzunluğu bulunur.
- `kelimeler[i] = (char*) calloc(m+1, sizeof(char));` ile kelime için yer ayrılır. `strlen` sondaki `'\0'` karakterini saymadığı için bir fazla yer ayrılır.
- `strcpy(kelimeler[i], dummy);` ile kelime ayrılan yere kopyalanır.

> **Hocanın vurgusu:** Burada derin kopya (deep copy) yapmak zorundayız; `dummy` her turda değişecek. Eşittir operatörü dizilerin elemanlarını tek tek kopyalamak için tanımlı değildir. Bunun için `strcpy` ya da onun daha genel hali olan `memcpy` kullanılır.

Ters yazdırma fonksiyonu tamsayı dizisindekiyle aynı mantıktadır (ekrandan, 02:20:00):

```c
void reverse_str_array(char **k, int i, int n){
    if(i<n){
        reverse_str_array(k,i+1,n);
        printf("%s",k[i]);
    }
}
```

İlk derlemede `calloc`, `strlen` ve `strcpy` için "incompatible implicit declaration of built-in function" uyarıları geldi (ekrandan, 02:20:00). Nedeni `stdlib.h` ve `string.h` dosyalarının eklenmemiş olmasıydı; eklenince sorun çözüldü. Program çalıştırıldığında girilen kelimeler ters sırayla yazdırıldı. Hoca hata ayıklayıcıyla `kelimeler[i]` için her turda farklı bir adresin ayrıldığını gösterdi. Bu sürümde veriler bellekteki yerlerinde durur, yer değiştirmez; yalnız ters sırayla yazdırılır.

Tam program (başlık dosyaları ve `free` eklendi, kelimeler arasına boşluk kondu; gcc -Wall ile uyarısız derlendi):

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str){
    if(*str){
        reverse(str+1);
        printf("%c",*str);
    }
}

void reverse_str_array(char **k, int i, int n){
    if(i<n){
        reverse_str_array(k,i+1,n);
        printf("%s ",k[i]);
    }
}

int main(){
    char a[] = "yapisal programlama";
    char **kelimeler;
    int i, n, m;
    char dummy[30];
    reverse(a);
    printf("\nEleman sayisi: ");
    scanf("%d",&n);
    kelimeler = (char **) calloc(n, sizeof(char*));
    for(i=0;i<n;i++){
        scanf("%s",dummy);
        m=strlen(dummy);
        kelimeler[i]=(char*)calloc(m+1,sizeof(char));
        strcpy(kelimeler[i],dummy);
    }
    reverse_str_array(kelimeler,0,n);
    printf("\n");
    for(i=0;i<n;i++) free(kelimeler[i]);
    free(kelimeler);
    return 0;
}
```

Deneme: `3` ve ardından `elma armut kiraz` girildiğinde çıktı `amalmargorp lasipay` ve `kiraz armut elma` oldu.

Hoca, işaretçileri yer değiştirerek dizinin kendisini ters çeviren sürümü (yani `reverse2` mantığıyla `k[i]` ve `k[n]` adreslerinin yer değiştirmesi) alıştırma olarak bıraktı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:48:17): İki sayının küçüğünü bulan `#define min(a,b) ((a) < (b) ? (a) : (b))` makrosunu üç sayı için uyarlayın.

> **Çözüm (derste verilen):** `min(a, min(b, c))`. Makro iç içe kullanılır; önişlemci içteki çağrıyı açtıktan sonra dıştakini açar. Dört sayı için `min(min(a, b), min(c, d))`.

**Soru 2** (ekrandan, 00:50:00): `#define min(a,b) ((a) < (b) ? (a) : (b))` tanımlıyken `z = min(x++, y);` satırı önişlemciden sonra neye dönüşür, sorun nedir?

> **Çözüm (derste verilen):** `z = ((x++) < (y) ? (x++) : (y));`. Karşılaştırma doğruysa `x` iki kez artırılır. Örneğin `x = 1`, `y = 5` için sonuç `z = 2`, `x = 3` olur (gcc ile denendi).

**Soru 3** (derste sözlü, 00:47:31): `#define SQUARE(x) x*x` tanımlıyken `SQUARE(3+4)` ne verir?

> **Çözüm:** `3+4*3+4 = 3 + 12 + 4 = 19`; istenen 49'dur. Doğru tanım `((x)*(x))`. (Derste hesap sözlü yapıldı; değer gcc ile doğrulandı.)

**Soru 4** (ekrandan, 01:05:00): `24 & 17` ve `24 | 17` nedir?

> **Çözüm (derste verilen):** `11000 & 10001 = 10000 = 16`, `11000 | 10001 = 11001 = 25`.

**Soru 5** (ekrandan, 01:05:00): `a = 5` için `a << 2` ve `a >> 2` nedir?

> **Çözüm:** `a << 2 = 10100 = 20`, `a >> 2 = 1`. (Hoca derste `a << 2` için 10 dedi; doğrusu 20'dir, gcc ile denendi.)

**Soru 6** (derste sözlü, 01:32:16): Dosyada numara yerine puana göre arama yapılsaydı ve aynı puandan birden çok kayıt bulunabilseydi ne yapmak gerekirdi? Kayıt sayısı 100, 300 ya da $N$ ise yapı nasıl tanımlanır?

> **Çözüm (derste verilen):** Bulunan her kayıt dinamik bir struct dizisine kopyalanmalıdır. Önce küçük bir yer `malloc` ile ayrılır, kayıt buldukça `realloc` ile genişletilir (ArrayList mantığı: dolunca yaklaşık 1,5 katına büyütme).

**Soru 7** (derste sözlü, 01:43:23): `int a[] = {1,2,3,4,5};` için `sizeof(a)` ve `sizeof(a)/sizeof(a[1])` nedir?

> **Çözüm (derste verilen):** `sizeof(a) = 20` bayt (5 adet 4 baytlık `int`), `sizeof(a)/sizeof(a[1]) = 20/4 = 5`, yani eleman sayısı.

**Soru 8** (derste sözlü, 02:10:20): $n$ tane string dinamik bellekle saklanacaksa tek işaretçi mi, çift işaretçi mi gerekir?

> **Çözüm (derste verilen):** Çift işaretçi (`char **`). Her string kendi başına bir `char *` (ilk karakterin adresi) olduğundan, bu adresleri tutan dizi `char **` olur: `calloc(n, sizeof(char*))`, ardından her kelime için `calloc(m+1, sizeof(char))`.

**Soru 9** (derste sözlü, 02:17:27): `reverse_str_array` fonksiyonunu, kelimeleri yalnız tersten yazdırmak yerine işaretçileri yer değiştirerek diziyi gerçekten ters çevirecek şekilde yazın.

> **Çözüm (derste verilmedi):** `reverse2` mantığıyla adresler yer değiştirilir; kelimelerin kendisi kopyalanmaz.
>
> ```c
> void reverse_str_array2(char **k, int i, int n){
>     char *tmp;
>     if(i<n){
>         tmp=k[i];
>         k[i]=k[n];
>         k[n]=tmp;
>         reverse_str_array2(k,i+1,n-1);
>     }
> }
> /* çağrı: reverse_str_array2(kelimeler, 0, n-1); */
> ```
>
> `elma armut kiraz` girdisi için çağrıdan sonra dizi sırayla yazdırıldığında `kiraz armut elma` çıkar (gcc -Wall ile derlenip denendi).

## Dersin Toparlaması

Dersin ilk yarısında bir C programının birden çok `.c` ve `.h` dosyasına nasıl bölüneceği, header dosyasının yalnız arayüz bilgisi (prototip, struct, makro) taşıması gerektiği, derleme zincirinin (önişlemci, derleyici, assembler, linker) aşamaları ve makefile ile yalnız değişen dosyaların yeniden derlenmesi görüldü. Ardından önişlemci makroları tekrar edildi: makronun bir yerine koyma olduğu, bu yüzden parametrelerin parantezlenmesi, sonuna noktalı virgül ve tanımda eşittir konmaması gerektiği, yan etkili argümanların tehlikesi, makro ile fonksiyonun avantaj ve dezavantajları, `#undef`, hazır makrolar ve koşullu derleme yönergeleri işlendi. Bit düzeyindeki operatörler (`&`, `|`, `^`, `~`, `<<`, `>>`) örneklerle gösterildi.

İkinci yarıda örnekler yapıldı: struct kullanarak binary dosyaya `fwrite` ile yazma ve `fread` ile sıralı kayıt arama, dizinin özyinelemeyle tersten yazdırılması ve yer değiştirerek ters çevrilmesi, özyinelemeli fonksiyonların karmaşıklığını hızlıca kestirme, bir string'in `'\0'` karakterine dayanarak tersten yazdırılması ve `char **` ile dinamik bir string dizisinin oluşturulması. Hoca gelecek derste bu konuların uygulaması olarak bağlı listelere ve ikili arama ağacının gerçeklenmesine (in-order, pre-order, post-order gezinme) geçileceğini, ağaçta ekleme ve silmenin mantığına bakılacağını, zaman kalırsa thread konusuna girileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
