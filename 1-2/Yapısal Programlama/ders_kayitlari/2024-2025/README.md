# Yapısal Programlama Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Yapısal Programlama (BLM1031)
* **Hoca:** Dr. Ahmet Elbir
* **Dönem:** Bahar
* **Akademik Yıl:** 2024-2025
* **Şube:** BLM1031 - 3

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 2** | Bilgisayar Mimarisi Tekrarı, Veri Tipleri ve IEEE 754, Tip Dönüşümü, Operatörler, printf Biçimlendirme ve enum | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | typedef, İfadeler ve Operatörler (Kalan, Bit, Koşul), Kontrol Akışı, switch ve Döngüler, Makrolar ve Koşullu Derleme | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Uygulama: Pisagor Üçlüsü ve 2B Konvolüsyon; Örüntü Eşleme, Matriste Arama ve Çok Boyutlu Diziler | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 6** | Uygulama-2 (Zar Olasılık Matrisi, Collatz, Fatura, Lab 1 Çözümü), realloc, Düzensiz Matris, Fonksiyondan Dizi Döndürme ve main Argümanları | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Dinamik Matris Çarpımı, Oy Sayma Algoritmaları, Polinomların Dizide Tutulması ve Struct'lara Giriş | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 9** | Uygulama-3: Struct ile Çalışan Veritabanı, Dinamik Dizi ve Bağlı Liste Karşılaştırması, Başlık Dosyaları ve Makrolar | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 11** | Bağlı Liste Kodlama (Ekleme, Yazdırma, Silme), Yapı Hizalaması, Bit Alanları, Union ve Özyineleme | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 13** | Void İşaretçi, Dosya İşlemlerine Giriş: Stream, Metin ve İkili Dosyalar, fopen Kipleri ve Dönem Projesi | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 17** | Çok İş Parçacıklı Programlama (pthread) ve void* ile Genel Fonksiyonlar | [Özet](altyazi_ozetleri/ders_17_ozet.md) | [PDF (İndir)](ders_17_ozet.pdf) |

> [!NOTE]
> 1, 5, 8, 10, 12, 14, 15 ve 16 numaralı ders kayıtları bu şubenin kayıt arşivinde bulunmamaktadır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 2: Bilgisayar Mimarisi Tekrarı, Veri Tipleri ve IEEE 754, Tip Dönüşümü, Operatörler, printf Biçimlendirme ve enum
* **Genel Konular:**
  - Bu saat normalde uygulama saati. Konulardan geri kalmamak için birkaç hafta ders olarak kullanılacak. Ders notları ve derste yazılan kodlar paylaşılan linkte.
  - Bilgisayar mimarisi (kısa tekrar)
    - Von Neumann mimarisi: bir işlemci ve bir ana bellek vardır. Programın komutları ve verileri aynı bellekte durur. Ayrıca giriş/çıkış birimleri vardır.
  - C programının yapısı
    - Her C programında bir `main` fonksiyonu olmak zorundadır.
  - Veri tipleri
    - Dört temel tip: tam sayı (`int`), tek duyarlıklı ve çift duyarlıklı ondalıklı sayı (`float`, `double`), karakter (`char`). Diziler ve string bunlardan türer.
  - Tam sayılar
    - `int` 32 bittir. `signed` (varsayılan) için 1 bit işarete gider: aralık $-2^{31}$ ile $2^{31}-1$.
  - Ondalıklı sayılar: IEEE 754 standardı
    - Sayı bilimsel gösterimle yazılır: işaret biti, üs (exponent) ve kesir (fraction/mantissa).
  - Karakterler
    - `char` 1 bayttır, 0-255 arası değer alabilir. ASCII tablosunda her sayı bir sembole karşılık gelir.
* **Hocanın Vurgusu:**
  - Örtük dönüşümler daha tehlikelidir, çünkü koddan görünmez.
  - Tam sayı bölmesinde ondalık kısım kesilir, yuvarlama yoktur.
    - Ondalıklı sayıyı tam sayıya atarken de kesilir.
  - Bu tür operatör önceliği ve tip dönüşümü soruları sınavlarda sorulabilir.
    - Ama `m++ * m++` gibi kafa karıştırıcı ifadeler sorulmaz.
  - Biçim belirtecini değişkenin tipine uygun seçin.
  - Ondalık sayılarda virgül değil nokta kullanın.

### 🔹 Ders 3: typedef, İfadeler ve Operatörler (Kalan, Bit, Koşul), Kontrol Akışı, switch ve Döngüler, Makrolar ve Koşullu Derleme
* **Genel Konular:**
  - Derste Yapay Zeka bölümünden öğrenciler de var. Geçen haftanın kayıtları Online Yıldız'da yayınlanamadığı için hoca WhatsApp kanalındaki linke (Drive) yükledi.
  - `typedef`
    - Var olan bir C tipine yeni bir isim verir: `typedef long int int32;` sonra `int32 j;`.
  - İfadeler (expressions)
    - Sabit ifadeler: `5`, `5 + 6 * 13 / 3.0`. İkincisinde çarpma ve bölme aynı öncelikte, soldan sağa: $6 \cdot 13 = 78$, $78 / 3.0 = 26.0$, sonuç 31.0.
  - Virgül operatörü (tekrar): `return 3,4,5;` 5 döndürür. `return 2,3,4;` örneği derste denendi.
  - Operatör sınıflandırması
    - Tekli (unary), ikili (binary), üçlü (ternary). Operatörlerin çoğu ikilidir. Tek üçlü operatör koşul operatörüdür (`?:`).
  - Kalan operatörü (`%`)
    - Yalnızca tam sayı operand alır: `6 % 2` geçerli, `6.0 % 2.0` geçersiz.
  - Aritmetik atama operatörleri
    - `m += n + x - y` aslında `m = m + (n + x - y)` demektir.
* **Hocanın Vurgusu:**
  - `break` yalnızca `switch` içinde.
    - `continue`, `goto` ve `switch` dışı `break` kullanan çözümler kabul edilmez.
  - `if`, `else`, döngü bloklarında tek satır için bile süslü parantez kullanın.
  - Döngü bitince sayaç değişkeninin son değerine dikkat edin.
  - Ondalıklı sayıları `==` ile karşılaştırmayın, tolerans kullanın.
  - Makro parametrelerini parantez içine alın.

### 🔹 Ders 4: Uygulama: Pisagor Üçlüsü ve 2B Konvolüsyon; Örüntü Eşleme, Matriste Arama ve Çok Boyutlu Diziler
* **Genel Konular:**
  - Dersin ilk yarısı uygulama: Arş. Grv. Muhammet Taha Gökcan iki soru çözdü. İkinci yarıda Dr. Ahmet Elbir string ve matris konularıyla devam etti.
  - Duyurular
    - Gelecek hafta laboratuvarda, bu haftaya kadarki ve bu hafta işlenecek konulardan quiz tarzında bir soru verilecek ve çözümün yüklenmesi istenecek. Uyulması gereken kurallar ayrıca duyurulacak. Bu haftaki uygulama laboratuvara hazırlıktır.
  - Asistanın sesi kayıtta yer yer kesik ve anlaşılmaz. Kod ayrıntıları ekran görüntülerinden alındı.
  - Soru 1: Pisagor üçlüsü
    - Verilen bir dizide $a^2 + b^2 = c^2$ eşitliğini sağlayan bir üçlü olup olmadığını bulup ekrana yazdıran program. Örnek dizi: 3, 13, 5, 6, 4, 12, 8.
  - Soru 2: İki boyutlu konvolüsyon
    - Girdi (input) matrisinin üzerinde bir çekirdek (kernel) matrisi gezdirilir. Her konumda üst üste gelen elemanlar çarpılır, çarpımlar toplanır ve sonuç çıktı (output) matrisine yazılır.
  - Konvolüsyon filtreleri (Dr. Ahmet Elbir)
    - Keskinleştirme (sharpen): merkezdeki pikselin 5 katından dört komşusu (üst, alt, sol, sağ) çıkarılır.
  - Örüntü eşleme (pattern matching)
    - Bir metinde (text) aranan bir örüntünün (pattern) hangi indisten başladığını bulmak. Word'deki Ctrl+F gibi.
* **Hocanın Vurgusu:**
  - Bütün kombinasyonları denerken indisleri bir öncekinden başlatın, aynı kombinasyonu tekrar denemeyin.
  - Kullanıcı girdisini `do-while` ile kontrol edin.
  - Matrisi fonksiyona gönderirken sütun boyutunu mutlaka yazın.
  - Dizi zaten bir adres olduğu için `scanf("%s", dizi)` içinde `&` kullanılmaz.
  - Değişkenleri blok başında tanımlayın.

### 🔹 Ders 6: Uygulama-2 (Zar Olasılık Matrisi, Collatz, Fatura, Lab 1 Çözümü), realloc, Düzensiz Matris, Fonksiyondan Dizi Döndürme ve main Argümanları
* **Genel Konular:**
  - Dersin ilk yarısında Arş. Grv. Begüm Özbay "Yapısal Programlama Uygulama-2"yi (24.03.2025) yaptı: üç soru ve Lab 1'in çözümü. Ardından Ahmet Hoca ek ders olarak `realloc`, düzensiz (jagged) matris, fonksiyondan dizi döndürme ve `main` argümanlarını anlattı.
  - Uygulama Soru 1: Üç zarın toplam olasılık matrisi
    - Üç zar birlikte atılıyor. Matrisin birinci sütununa olası toplamlar (3-18), ikinci sütuna bu toplamın olasılığı yazılacak. Matris dinamik bellekle tanımlanacak.
  - Uygulama Soru 2: Collatz dizisi
    - $f(n) = \frac{n}{2}$ (n çift), $f(n) = 3n + 1$ (n tek). Collatz problemi her pozitif tam sayıdan başlanınca dizinin sonunda 4, 2, 1 döngüsüne girip 1'e ulaşacağını iddia eder. Hâlâ kanıtlanmamış bir problemdir.
  - Uygulama Soru 3: Toptancı faturası
    - Ürünler: soda (10 TL), meyve suyu (15 TL), kola (20 TL), su (5 TL). Kullanıcı her üründen kaç koli aldığını girer.
  - Lab 1 çözümü
    - İki adet $2 \times n$ matris. İlk satırda benzersiz tam sayılar, ikinci satırda bunlara karşılık gelen değerler var. İki matrisin ilk satırlarında ortak olan sayılar bulunup karşılık değerleri toplanacak.
  - Ek ders: `realloc`
    - Daha önce `malloc` veya `calloc` ile açılmış bir alanın boyutunu program çalışırken değiştirir: `realloc(eski_isaretci, yeni_boyut)`.
  - Ek ders: düzensiz (jagged / ragged) matris
    - Her satırın sütun sayısı farklıdır. C'de hazır böyle bir yapı yoktur, işaretçilerle kurulur.
* **Hocanın Vurgusu:**
  - `realloc` sonucunu her zaman geçici bir işaretçide kontrol edin, sonra asıl işaretçiye atayın.
  - Fonksiyondan yerel (stack'teki) dizinin adresini döndürmeyin.
    - Dinamik bellek kullanın. Bu hata sınavda puan almaz.
  - `malloc` ile oluşturulan her şey heap'tedir.
    - Sabit uzunluklu diziler stack'tedir. İşaretçi döndürmek alanı heap'e taşımaz.
  - Düzensiz matriste iç döngünün sınırı o satırın kendi boyutudur.
  - `main` argümanları string'dir, sayıya çevirmek gerekir.

### 🔹 Ders 7: Dinamik Matris Çarpımı, Oy Sayma Algoritmaları, Polinomların Dizide Tutulması ve Struct'lara Giriş
* **Genel Konular:**
  - Ders, dinamik bellekle matris çarpımı örneğiyle başlar. Ardından fazla parametreli fonksiyonların sorunları, eski bir alışveriş sepeti örneği, oy sayma algoritmaları ve polinomların dizide tutulması işlenir. Son bölümde struct'lara giriş yapılır.
  - Bu grup register, static, extern depolama sınıflarını işlemişti. Diğer grup işlememiş.
  - Dinamik matris çarpımı
    - Fonksiyonlar: `int **create_matrix(int m, int n)`, `void fill_matrix(int **matrix, int m, int n)`, `void print_matrix(...)`, `int **multiply_matrices(int **m1, int m, int n, int **m2, int k, int l)`.
  - `getopt`: komut satırı seçeneklerini (`-a`, `-b`…) ayrıştırıp `switch` ile işlemeyi sağlar. Linux'ta çalışır, sınavda sorulmayacak. Örnek olarak `ls`, `dir /s` gibi komutların parametreleri gösterildi.
  - İyi programlama alışkanlığı: parametre sayısı
    - Bir fonksiyona çok sayıda parametre göndermek iyi bir alışkanlık değildir. Her parametre stack'e kopyalanır.
  - Alışveriş sepeti örneği (eski bir asistanlık örneği)
    - Fiyatlar `basket` dizisinde tutulur. Gıda ve gıda dışı ürünlerin fiyatlarının adresleri ayrı iki dizide (`ptr_food`, `ptr_other`) tutulur. Bunlar `double**`'dır: adresleri tutan diziler.
  - Oy sayma (seçim) algoritmaları
    - Versiyon 1: herkes 1-10 arası bir partiye oy veriyor. En çok oyu alan kim?
* **Hocanın Vurgusu:**
  - Fonksiyon başka bir şey üretmiyorsa `void` yapın.
    - Yeni bir yapı üretiyorsa işaretçi döndürün.
  - Kod tekrarından kaçının: var olan `create_matrix` fonksiyonunu çarpım içinde de kullanın.
  - Çok sayıda parametre yerine kendi veri tipinizi (struct) tanımlayın.
  - Zaman-bellek takasını düşünün: frekans dizisi küçük bir bellekle büyük zaman kazandırır.
  - Struct tanımını onu kullanan fonksiyonlardan önce yazın.

### 🔹 Ders 9: Uygulama-3: Struct ile Çalışan Veritabanı, Dinamik Dizi ve Bağlı Liste Karşılaştırması, Başlık Dosyaları ve Makrolar
* **Genel Konular:**
  - Bu kayıt "Yapısal Programlama Uygulama-3"tür (21.04.2025). Uygulamayı bir araştırma görevlisi yaptı. Ahmet Hoca derse yetkiyi verip ayrıldı.
  - Kaydın sesi çok düşük ve anlaşılmaz olduğu için bu özet büyük ölçüde ekran paylaşımındaki koddan çıkarıldı.
  - Problem: bir şirketin çalışan bilgilerini saklayan bir veritabanı. Menü üzerinden çalışan ekleme, isme göre arama, kayıt silme, tüm kayıtları listeleme ve sonunda bütün dinamik belleği serbest bırakma işlemleri yapılacak. Aynı işlev iki farklı veri yapısıyla yazılıp karşılaştırılıyor: dinamik dizi ve bağlı liste (linked list).
  - Struct'lar
    - `typedef struct job { char *Name; } JOB;` çalışanın meslek adı.
  - 1. Dizi tabanlı yaklaşım
    - `typedef struct database { PERSON **Data; int peopleCount; int databaseCount; } DATABASE;`
  - 2. Bağlı liste (linked list) yaklaşımı
    - Yeni yapı: `typedef struct node { PERSON *Person; struct node *Next; } NODE;`. `Next`, bir sonraki düğümü gösterir; sonuncunun `Next`'i `NULL`'dır. `next` ile bütün liste dolaşılır.
  - Dizi ve bağlı liste karşılaştırması
    - Bağlı liste bellek el verdiği sürece büyür. Dizide dolunca iki katına çıkarıp yeniden yer ayırmak (`realloc`) gerekir.
* **Hocanın Vurgusu:**
  - Struct içindeki string işaretçiler için `strlen + 1` kadar ayrı yer ayırın ve `strcpy` ile kopyalayın.
  - Serbest bırakma sırası: önce iç alanlar (isimler, iş), sonra struct'ın kendisi.
  - Bağlı listede baş işaretçisi değişebilecekse fonksiyona işaretçinin adresini (`NODE **`) gönderin.
  - Bağlı listeden silerken bir önceki düğümü (`previous`) takip edin.
  - Sık ekleme-silme varsa bağlı liste, sık indisli erişim varsa dizi.

### 🔹 Ders 11: Bağlı Liste Kodlama (Ekleme, Yazdırma, Silme), Yapı Hizalaması, Bit Alanları, Union ve Özyineleme
* **Genel Konular:**
  - Dersi dersin hocası Dr. Ahmet Elbir anlatıyor (Dev-C++ ekranındaki kullanıcı yolu `C:\Users\AHMETELBIR\...`). Ders 30 Nisan 2025 tarihli. Konular: bağlı listeler (linked list) ile kod yazma, yapı hizalaması (structure alignment), bit alanları (bit field), birlikler (union) ve özyineleme (recursion).
  - Bağlı listeye kısa tekrar
    - Her düğüm (node) bir veri (data) ve bir sonraki düğümün adresini tutan bir işaretçi (`next`) içerir.
  - Düğüm yapısı
    - `typedef struct node { int data; struct node *next; } node;`
  - Düğüm oluşturma: neden `malloc`?
    - Fonksiyon içinde `node n;` diye yerel bir düğüm tanımlayıp adresini listeye bağlamak yanlıştır. Yerel değişken stack bölgesindedir. Fonksiyon bitince o alan başka değişkenlere verilir ve düğüm "garanti" olmaktan çıkar.
  - Listeyi yazdırma (`printList`)
    - `while (head != NULL) { printf("%d ", head->data); head = head->next; }`.
  - Sona ekleme (`addLast`)
    - İlk denemede döngü `while (head != NULL)` ile kuruldu ve sonra `head = n` atandı. Bu çalışmaz: `head` `NULL` olana kadar gidildiğinde son düğümle bağlantı kaybolur. Yeni düğüm listeye bağlanmaz, ayrıca yalnızca yerel `head` değişir.
  - Bütün listeyi silme (`deleteList`)
    - Kaç düğüm oluşturulduysa o kadar `free` gerekir.
* **Hocanın Vurgusu:**
  - Bağlı liste düğümleri mutlaka `malloc` ile heap'te oluşturulmalı.
    - Yerel değişkenin adresini listeye bağlamayın.
  - Yeni düğümün `next`'ini `NULL` yapın.
  - `head`'i kaybetmeyin.
    - Gezinirken ve silerken geçici işaretçi kullanın.
  - `head`'i değiştiren işlemlerde (başa ekleme, baştan silme, listeyi silme) yeni `head` geri döndürülmeli veya `node **` kullanılmalı.
  - Global değişkenle çözüm kolay görünür ama tavsiye edilmez.

### 🔹 Ders 13: Void İşaretçi, Dosya İşlemlerine Giriş: Stream, Metin ve İkili Dosyalar, fopen Kipleri ve Dönem Projesi
* **Genel Konular:**
  - Dersi dersin hocası Dr. Ahmet Elbir online anlatıyor (12 Mayıs 2025). Konular: `void` işaretçi, dosya işlemlerine giriş (stream, metin ve ikili dosyalar, `fopen` erişim kipleri, dosya konum göstergesi), dosya kopyalama örneği ve dönem projesinin tanıtımı.
  - Duyurular: sınav çözümleri ve değerlendirmesi çarşamba günü online yapılacak. Cuma sabahı 9-12 arası ek ders var (uygulamaya ve projeye hazırlık).
  - `void` işaretçi (genel işaretçi)
    - Her türden değişkenin adresini tutabilen genel (generic) işaretçidir: `void *ptr;`. `int*`, `float*`, `char*` veya bir yapı işaretçisi yerine kullanılabilir.
  - Neden dosya?
    - Şimdiye kadar girdi klavyeden, çıktı ekrana yapıldı. Program kapanınca veriler kaybolur, çünkü program uçucu bir bellek olan RAM'de çalışır.
  - Stream (akış)
    - Program (RAM) ile dosya (disk) veya cihaz arasında kurulan mantıksal bağlantıdır. Sıralı bir bayt dizisidir.
  - Metin (text) ve ikili (binary) dosyalar
    - Metin dosyası: satırlardan oluşur, satırlar `\n` ile biter. Herhangi bir metin editöründe insanın okuyabileceği şekilde görünür (ör. `.c`, `.txt`, `.csv`).
  - Dosya konum göstergesi (file position indicator)
    - Dosya işaretçisi (`FILE*`) dosyayı gösterir. İçindeki dosya konum göstergesi ise dosyada şu an nerede olunduğunu gösterir, komut satırındaki imleç gibi.
* **Hocanın Vurgusu:**
  - `void*` dereferans edilemez, önce asıl türe çevrilmelidir.
  - `"w"` kipi var olan dosyanın içini siler.
  - `fopen` sonucu `NULL` mı diye mutlaka kontrol edilmeli.
    - `fopen` yapınca hemen `fclose`'u yazın.
  - Bir dosya nasıl yazıldıysa öyle okunur.
    - Dosya biçimini mühendislik yaparak tasarlayın.
  - Satır okumak için karakter karakter okumayın, disk yavaştır.

### 🔹 Ders 17: Çok İş Parçacıklı Programlama (pthread) ve void* ile Genel Fonksiyonlar
* **Genel Konular:**
  - Dönemin son dersi (28 Mayıs 2025). Dersi dersin hocası Dr. Ahmet Elbir online anlatıyor. Konular: çok iş parçacıklı (multi-thread) programlama, POSIX thread (`pthread`) kütüphanesi ve `void*` ile genel (generic) fonksiyonlar.
  - Önceki dersin konusu: çok dosyalı programların derlenmesi, `make` ve `makefile`.
  - Tek akışlı ve çok akışlı programlar
    - Şimdiye kadarki programlar tek akışlıdır: `main`'den başlar, bir fonksiyona gidilir, o bitince geri dönülür. Herhangi bir anda yalnızca bir fonksiyon çalışır.
  - Senkron ve asenkron
    - Senkron: işler belirli bir sırayla ve denetimle eşleştirilir. Örnek: telsiz (biri konuşur, bitirir, diğeri dinler), e-posta senkronizasyonu.
  - Süreç (process) ve iş parçacığı (thread)
    - Süreç, çalışmakta olan programdır. Bir uygulama birden çok süreçle de yapılabilir, ama her sürecin kendi bellek bölgesi vardır. Bir süreç diğerinin belleğine erişemez, bu yüzden süreçler arası haberleşme zahmetlidir.
  - Bağlam değiştirme (context switching)
    - Tek işlemcide P1 ve P2 süreçleri sırayla çalışır: P1 bir süre çalışır, durdurulur, P2 çalışır, sonra P1 kaldığı yerden devam eder.
  - POSIX thread (`pthread`)
    - `#include <pthread.h>`. Fonksiyon adları alt çizgiyle ayrılır (`pthread_create`, `pthread_join`). Bu bir POSIX standardıdır.
* **Hocanın Vurgusu:**
  - İş parçacıklarının çalışma sırası önceden bilinemez.
  - `main` bitmeden önce iş parçacıklarını `pthread_join` ile bekleyin.
  - İş parçacığı fonksiyonu `void*` alıp `void*` döndürür.
  - `void*` dereferans edilemez ve üzerinde aritmetik yapılamaz.
    - `char*`'a çevirip eleman boyutuyla çarpın, kopyalama için `memcpy` kullanın.
  - Final sorularında `void*`, dönüştürme ve `sizeof` ile ilgili ekran çıktısı soruları olabilir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
