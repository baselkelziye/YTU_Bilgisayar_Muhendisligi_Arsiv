# Ders 3 Çalışma Özeti

## Genel Konular

- Algoritmadan programa geçiş
  - Algoritmayı tasarlamak tek başına yetmez; algoritmanın bir makinede çalışabilmesi için programa dönüştürülmesi gerekir. Program, algoritmanın bir ifade biçimidir.
  - Basit algoritmalar kağıt üzerinde izlenebilir (trace), ama gerçek problemlerde algoritmayı programa çevirip çalıştırmak gerekir.
  - Program bir donanım (hardware) üzerinde, özellikle CPU üzerinde çalışır; komutlar CPU'nun anladığı dile çevrilmelidir.
- Programlama dillerinin seviyeleri (ekrandan, 00:20:00)
  - Makine dili (machine language): 0 ve 1'lerden oluşur, CPU'ya özeldir (machine dependent). İşlemci modeli değişince program da değişmek zorunda kalır; taşınabilirlik (portability) yoktur.
  - Assembly dili: makine dilinin anımsatıcı (mnemonic) kısaltmalarla yazılmış hâlidir (`ADD`, `MOV`, `INC`, `DEC`). Makine diliyle birebir karşılık geldiği için o da makineye bağlıdır. Bu ikisi düşük seviyeli dillerdir (low-level).
  - Orta seviyeli dil (mid-level): C. Az işlemle assembly ve makine diline çevrilebilir. Sistem programlama, işletim sistemleri ve gömülü sistemlerde kullanılır. Makineden bağımsızdır (machine independent).
  - Yüksek seviyeli diller (high-level): Java, C#, Python, Rust, JavaScript. Kullanıcıya yakındır; kullanıcıdan uzaklaştıkça araya giren çeviri katmanları artar ve bu bir ek yük (overhead) getirir.
  - Programlama dilleri biçimsel (formal) dillerdir; her birinin alfabesi ve grameri vardır. Günlük konuşma dilleri ise doğal dillerdir (natural languages).
- C dilinin özellikleri
  - 1972 civarında Bell Laboratuvarları'nda geliştirilmiştir. Eğitimde genellikle C89 (ANSI C, standart C) ve C99 standartları kullanılır.
  - Kullanım alanları: işletim sistemleri, mikrodenetleyiciler, gömülü sistemler, DSP işlemcileri; kısaca hızın ve donanıma yakınlığın önemli olduğu uygulamalar.
  - Avantajlar: küçük alfabe ve basit gramer, kullanıcı tanımlı bileşik veri tipleri, işaretçilerle (pointer) bellek kontrolü, dizilerin verimli kullanımı, dış kütüphanelerin eklenebilmesi, kolay derleme, makrolar.
  - Dezavantaj ve tehlikeler: kelime dağarcığı az olduğu için programlar uzayabilir (web veya mobil uygulama yazmak zahmetlidir); dizi sınır denetimi (range checking) yoktur; çalışma zamanında tip denetimi yapılmaz, yanlış girdi programı çökertebilir.
- Yüksek seviyeli dillerin genel değerlendirmesi
  - Avantajlar: taşınabilirlik, okunup anlaşılma kolaylığı, bakım (sürdürülebilirlik) kolaylığı.
  - Dezavantajlar: verimlilik kaybı, derleyiciye bağımlılık ve çeviri gerekliliği. Aynı kaynak kod farklı derleyicilerle farklı makinelere uygun farklı makine dili programlarına dönüşür (ekrandan, 00:30:00).
  - Derleme (compiler) programın tamamını çevirir; yorumlama (interpreter) programı satır satır ya da parça parça çevirip çalıştırır.
- Yazılım üretiminin aşamaları (ekrandan, 00:35:00)
  - Ürün tanımı (product specification), mimari tasarım, proje planlama, ayrıntılı tasarım (akış diyagramı), kodlama, hata ayıklama (debugging), test ve bakım.
  - Köprü benzetmesi: köprü baştan sağlam planlanır ve sonradan değiştirilmez; yazılım ise değişim için tasarlanmalı, yeniden kullanılabilir ve test edilebilir parçalardan oluşmalıdır.
- Derleme süreci ve IDE (ekrandan, 00:40:00)
  - Birden çok kaynak dosya (source file) ayrı ayrı derlenip nesne dosyalarına (object file) dönüşür; bunlar çalışma zamanı kütüphaneleriyle (runtime library, örneğin `printf`) bağlanarak (link) çalıştırılabilir dosya üretilir.
  - IDE (Integrated Development Environment): kod düzenleme (renklendirme, hata gösterme, öneri, otomatik tamamlama), derleme, bağlama, çalıştırma ve hata bildirme işlerini tek yazılımda toplar. Derste Dev-C++, Code::Blocks ya da Mac'te Xcode/gcc önerildi.
- gcc ile derleme ve ara dosyalar (ekrandan, 01:20:00 ve 01:55:00)
  - Komut: `gcc myprogram.c -save-temps -o mycompiledprogram`. `gcc` derleyici programdır, `myprogram.c` kaynak koddur, `-save-temps` ara dosyaların silinmemesini sağlayan bayraktır, `-o` çıktı adını veren bayraktır.
  - Ön işleme (preprocessing): `#include`, `#define` ve makrolar yerine yazılır, yorumlar silinir. Girdi `myprogram.c`, çıktı `myprogram.i`.
  - Derleme (compilation): kaynak kod assembly koduna çevrilir. Girdi `myprogram.i`, çıktı `myprogram.s`. `printf` gibi daha önce derlenmiş fonksiyonlar henüz çözülmez.
  - Çeviri (assembly): assembly kodu kodlanmış makine koduna çevrilir. Girdi `myprogram.s`, çıktı `myprogram.o`.
  - Bağlama (linking): diğer `.o` dosyaları (örneğin `printf`'in derlenmiş kodu) birleştirilir ve çalıştırılabilir dosya (`.exe`) üretilir. Sonra çalıştırılır.
  - Bu adımlardan önce algoritmanın tasarlanması ve programın yazılıp düzenlenmesi (edit) gelir.
- Noktalı virgül kuralı
  - Noktalı virgül emir bildiren ifadelerin (atama, `printf`, `scanf`, artırma) sonuna konur.
  - `if`, `for`, `while` başlıklarının sonuna konmaz; konursa gövde boş kalır. İstisna: `do-while` döngüsünün sonunda noktalı virgül vardır.
- Değişkenler, sabitler ve veri tipleri
  - Değişken, bellekte bir adrese ve değere sahip etiketli bir alandır; her atama satırı bir deyimdir (statement) (ekrandan, 01:35:00).
  - İsimlendirme kuralları: harf, rakam ve alt çizgi içerebilir; harf ya da alt çizgiyle başlar, rakamla başlayamaz; ayrılmış kelime olamaz; C büyük-küçük harfe duyarlıdır.
  - Skaler (ilkel) tipler: tam sayı tipleri, kayan noktalı tipler, işaretçiler ve enum. Bileşik (aggregate) tipler temel tiplerden yeni tip oluşturur (örnek: merkez x, y ve yarıçaptan oluşan bir daire tipi).
  - Tip boyutları ve aralıkları tablosu (ekrandan, 01:40:00); `sizeof` bir operatördür, boyut makineden makineye değişebilir.
  - Bildirim (declaration) ve ilk değer vererek tanımlama (definition/initialization) ayrımı; camelCase isimlendirme.
  - Sabitler: `const` anahtar kelimesi ya da `#define` ön işlemci yönergesi (ekrandan, 01:45:00).
  - Değişmezler (literal): `22`, `22u`, `22L`, `0x4`, `1.5e3` gibi doğrudan yazılan sabit değerler.
- Giriş-çıkış ve tip dönüşümleri
  - `printf` biçim dizisi ve biçim belirleyiciler (`%c`, `%d`, `%f`, `%5d`); `scanf` ile okumada değişkenin adresi `&` ile verilir (ekrandan, 01:50:00).
  - Karışık tipli işlemlerde küçük tip büyük tipe örtük olarak dönüşür (implicit conversion). Açık dönüşüm tip zorlamasıyla (type casting) yapılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- C'de her şeyi kendiniz yapmak zorundasınız
  - Dil, sınır denetimi ve çalışma zamanı tip denetimi yapmaz; bu iş programcıya kalır. Bellek ayrıntılarına hakim olmak bir bilgisayar mühendisini diğer programcılardan ayırır.
  - Hata ancak çalışma sırasında ortaya çıkarsa program müşteride çökebilir; her şey baştan düşünülmelidir.
- Hataları erken keşfetmek
  - Tasarım ve planlama, proje büyüdükçe daha önemli hâle gelir. Küçük bir tip dönüşümü hatasının bile ağır sonuçları olabilir.
- Kaynak dosyayı `.c` uzantısıyla kaydetmek
  - `.cpp` olarak kaydedilen dosya C++ standardına göre derlenir; bu derste dosyalar C olarak kaydedilmelidir.
- Derleyicinin arka planda yaptıklarını bilmek
  - IDE'nin tek tıkla yaptığı ön işleme, derleme, çeviri ve bağlama adımlarını bir mühendis olarak tek tek anlamak gerekir.
- Değişken tipini değer aralığına göre seçmek
  - Çok büyük değerler beklenen yerde `long long` gibi geniş tipler kullanılmalıdır.
- Örtük dönüşüm tehlikelidir
  - İki tam sayının bölümü tam sayıdır (`1/2` sıfır olur). Büyük tipten küçük tipe dönüşümde veri kaybı olur; sayısal hesaplardaki pek çok yanlış sonuç buradan gelir.
- Ezber değil pratik
  - Sözdizimi ezberlenmez; kod yazdıkça, hata yaptıkça ve derleyici mesajlarını okudukça öğrenilir.

## Kısa Tekrar Notları

- Makine dili ve assembly makineye bağlıdır (düşük seviye); C orta seviyeli ve makineden bağımsızdır; Java, Python vb. yüksek seviyelidir.
- Programlama dilleri biçimsel dillerdir: alfabe ve gramer.
- Derleme zinciri: `.c` → (ön işleme) `.i` → (derleme) `.s` → (çeviri) `.o` → (bağlama) `.exe`.
- `gcc kaynak.c -save-temps -o program` ara dosyaları saklar.
- Ön işleme: `#include` içeriği yapıştırılır, `#define` adları değerle değiştirilir, yorumlar silinir.
- `printf` derleme ve çeviri aşamalarında çözülmez; bağlama aşamasında kütüphaneden gelir.
- 1 KB'lık kaynak koddan yüz kilobaytı aşan çalıştırılabilir dosya çıkmasının nedeni bağlanan kütüphane kodlarıdır.
- `main` içindeki `return 0` programın hatasız bittiğini bildirir.
- Noktalı virgül emir bildiren ifadelerin sonuna konur; `if`/`for`/`while` başlığından sonra konmaz; `do-while` istisnadır.
- Değişken adı harf ya da `_` ile başlar, ayrılmış kelime olamaz, büyük-küçük harf farklıdır.
- `char` 1 bayt: işaretli $-128 \ldots 127$, işaretsiz $0 \ldots 255$. `int` 4 bayt: $-2^{31} \ldots 2^{31}-1$.
- `sizeof` fonksiyon değil operatördür.
- `#define` ile tanımlanan ad değişken değildir; `PI = PI + 3;` yazılamaz. `const` değişken de değiştirilemez.
- Örtük dönüşüm: `1/2 = 0`, `1/2.0 = 0.5`; açık dönüşüm: `(float)j/k`.

## Detaylı Açıklamalar

- **Dil seviyeleri ve çeviri.** CPU yalnız kendi makine dilini anlar. Makine dilinde yazılan bir program yalnız o işlemci ailesinde çalışır. Assembly, bu 0-1 dizilerinin `ADD`, `MOV`, `INC`, `DEC` gibi anımsatıcılarla yazılmış hâlidir ve yazmayı kolaylaştırsa da makineye bağlılığı ortadan kaldırmaz. Hoca, makineye en yakın dillerin en hızlı olduğunu tercüman benzetmesiyle anlattı: bilmediğiniz bir dili konuşan biriyle tercüman aracılığıyla konuşursanız, sürenin bir kısmı çeviriye gider. C gibi orta seviyeli diller az bir çeviriyle makine koduna inebildiği için hızlıdır; yüksek seviyeli diller ise kullanıcıya yaklaştıkça daha fazla çeviri katmanı gerektirir. Hangi seviyede yazılırsa yazılsın, en sonunda kodun çalışacağı CPU'nun diline yukarıdan aşağıya bir çeviri (translation) gerekir (ekrandan, 00:20:00).
- **Biçimsel ve doğal diller.** Programlama dilleri, makine dili ve assembly dahil, biçimsel (formal) dillerdir: belirli bir alfabeleri ve kuralları (gramerleri) vardır. İnsanların konuştuğu diller doğal dillerdir ve bunlarla doğal dil işleme alanı ilgilenir. Bir programlama dilini tasarlamak ile o dilde program yazıp makine koduna çevirmek ayrı konulardır; bu derste ikincisi yapılır. Dil tasarımı ayrıntıları hesaplama kuramı ve programlama dilleri derslerinin konusudur.
- **Yüksek seviyeli dillerde tek kaynak, çok derleyici.** Aynı kaynak kod, A, B, C derleyicileriyle derlendiğinde her biri kendi bilgisayarına uygun ayrı bir makine dili programı üretir (ekrandan, 00:30:00). Bu taşınabilirlik sağlar ama derleyiciye bağımlılık yaratır. Günümüzde web, mobil, masaüstü ve IoT uygulamalarında hazır çatılar (framework) ve kütüphaneler sayesinde yüksek seviyeli dillerle çok daha hızlı geliştirme yapılır; sistem ve gömülü programlar ise C'nin alanıdır.
- **C'nin bıçak gibi özellikleri.** Hoca C'yi bıçağa benzetti: doğru kullanılırsa çok faydalı, yanlış kullanılırsa tehlikeli. Beş elemanlı bir dizinin altıncı elemanına erişmeyi bazı diller engeller, C engellemez. `int a; scanf("%d", &a);` satırında kullanıcı sayı yerine harf girerse C bunu önceden denetlemez; program çalışma sırasında hatalı davranabilir ya da çökebilir.
- **Yazılım geliştirme ve köprü benzetmesi.** Yazılım aşamaları sırasıyla ürün tanımı, mimari tasarım, proje planlama, ayrıntılı tasarım, kodlama, hata ayıklama, test ve bakımdır (ekrandan, 00:35:00). Problem metninden girdiler ve çıktılar çıkarılır, akış diyagramı çizilir, kod yazılır, uç değerlerle test edilir. Köprü yapımında önce zemin incelenir, temel atılır, kuleler dikilir, kedi yolu kurulur ve tabliyeler iki uçtan birleştirilir; köprü bittikten sonra şerit eklenemez. Yazılım ise ihtiyaçlar değiştikçe güncellenen bir ürün olduğu için değişime açık, yeniden kullanılabilir ve test edilebilir tasarlanmalıdır.
- **Dev-C++ ile derleme.** Hoca Dev-C++'ta `File > New > Source File` ile şu kodu yazdı (ekrandan, 00:50:00):

  ```c
  #include <stdio.h>

  int main(){
      int a=5;
      printf("a = %d",a);

      return 0;
  }
  ```

  Bu kod `gcc -Wall` ile derlendi ve çalıştırıldı; çıktı `a = 5`, çıkış kodu 0. Dev-C++'ın derleme günlüğünde 0 hata, 0 uyarı ve yaklaşık 145 KiB çıktı boyutu görüldü; 1 KB'lık kaynak dosyadan bu kadar büyük bir dosya çıkmasının nedeni `stdio.h` ile gelen ve bağlanan kütüphane kodlarıdır. `return 0`, programın hatasız bittiğini gösteren bir gelenektir.
- **Komut satırından gcc.** Windows'ta `gcc` komutunun her klasörden çalışması için gcc'nin bulunduğu klasörün (Dev-C++ kurulumunda `MinGW64\bin`) ortam değişkenlerindeki `Path` listesine eklenmesi gerekir: Bilgisayar özellikleri > Gelişmiş sistem ayarları > Ortam değişkenleri > Path > Düzenle > Yeni. Komut istemi yeniden açıldıktan sonra yalnız `gcc` yazıldığında `fatal error: no input files` mesajı gelir; bu, gcc'nin bulunduğunu ama girdi verilmediğini gösterir. `gcc Kod1.c -o BenimProgramim` komutu çalıştırılabilir dosyayı üretir (ekrandan, 00:55:00 ve 01:00:00).
- **Ara dosyaları görmek.** `-save-temps` bayrağıyla `.i`, `.s` ve `.o` dosyaları silinmez. Hoca koda `#define MAX 100` ekleyip `int a=MAX;` yazdı ve yorum satırları ekledi. `.i` dosyasında yaklaşık 690 satırlık `stdio.h` içeriğinin (`vsscanf`, `snprintf` gibi bildirimler) koda yapıştırıldığı, `#define` satırının ve yorumların kaybolduğu, `MAX` yerine `100` yazıldığı görüldü (ekrandan, 01:15:00). `.s` dosyası assembly koduna benzer; 100 değerinin bir yere aktarıldığı ama `printf` çağrısının hâlâ çözülmeden durduğu görüldü. `.o` dosyası insan için okunaksız kodlanmış makine kodudur. Bağlama sonunda `printf`'in kodu da eklenir ve çalıştırılabilir dosya oluşur. Bu davranış gcc ile ayrıca denendi: `.i` dosyasında `int a=100;` satırı, `.s` dosyasında `movl $100, ...` ve `call printf` satırları görüldü.
- **Hata mesajları.** `printf` satırının sonundaki noktalı virgül silinip derlendiğinde gcc, `return`'den önce `;` beklendiğini bildirir. Ön işleme yorumları ve boş satırları sildiği için noktalı virgül, arada çalıştırılabilir bir ifade olmadıkça bir sonraki satırın başına da konabilir. Bir başka denemede silinen virgül için derleyici parantez hatası bildirdi; yani hata mesajı her zaman asıl hatayı göstermeyebilir.
- **Tip boyutları ve aralıkları.** Ekrandaki tabloda (ekrandan, 01:40:00) `char` 1 bayt ($-128$ ile $127$), `unsigned char` 1 bayt ($0$ ile $255$), `short int` 2 bayt ($-32768$ ile $32767$), `int` 4 bayt ($-2\,147\,483\,648$ ile $2\,147\,483\,647$), `unsigned int` 4 bayt ($0$ ile $4\,294\,967\,295$), `long int` 8 bayt ($-2^{63}$ ile $2^{63}-1$), `unsigned long int` 8 bayt ($0$ ile $2^{64}-1$), `float` 4 bayt ve `double` 8 bayttır. İşaretli $n$ bitlik tipte bir bit işarete gider, aralık $-2^{n-1}$ ile $2^{n-1}-1$ olur; işaretsizde aralık $0$ ile $2^n-1$ olur. `float` IEEE 754'ün 32 bitlik, `double` 64 bitlik biçimine karşılık gelir.
  - Ders sonrası not: tabloda `unsigned short int` üst sınırı 65536 yazıyor; doğrusu $2^{16}-1 = 65535$ (python ile doğrulandı).
  - Ders sonrası not: `long` boyutu platforma bağlıdır; hocanın Windows'taki `sizeof` denemesinde 4 bayt çıktı, tablodaki 8 bayt ise büyük olasılıkla 64 bit Linux içindir.
- **Sabitler.** `const float PI=3.142857;`, `const int maxHour=24;`, `const double force=9.912391;` ile `#define PI 3.142857` ve `#define MAX 100` gösterildi (ekrandan, 01:45:00). `#define` ön işlemede yerine yazıldığı için `PI = PI + 3;` ifadesi `3.142857 = 3.142857 + 3;` gibi anlamsız bir şeye dönüşür; `const` değişken de değiştirilemez. `#define` satırının sonunda noktalı virgül yoktur.
- **Tip dönüşümleri.** `1/2` iki tam sayının bölümü olduğu için 0 verir, `1/2.0` 0.5 verir. `-3/4 + 2.5` ifadesinde önce tam sayı bölmesi 0 olur, sonuç 2.5'tir. `2 + 3.5` işleminde 2, 2.0'a dönüşür ve sonuç 5.5 olur. `(float)j/k` ile $j=3$, $k=2$ için önce $j$ 3.0'a çevrilir ve sonuç 1.5 olur. Bu değerler küçük bir C programıyla derlenip doğrulandı. Dönüşüm hiyerarşisinde en üstte `long double`, sonra `double`, `float` ve tam sayı tipleri gelir; aşağıdan yukarı dönüşüm güvenli, yukarıdan aşağı dönüşüm veri kaybına açıktır.
  - Ders sonrası not: hoca açık dönüşüme bir an "unboxing" dedi; C'deki doğru terim tip zorlaması (type casting) ya da açık dönüşümdür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
