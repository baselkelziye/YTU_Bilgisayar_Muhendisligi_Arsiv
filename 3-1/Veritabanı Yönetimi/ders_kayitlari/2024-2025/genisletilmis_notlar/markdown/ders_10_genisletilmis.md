# Ders 10 Genişletilmiş Notu: İndeksleme (Disk Erişimi, Sıralı İndeksler, B+ Ağacı, Hash ve Çok Nitelikli İndeksler)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Saklama Ortamı ve Veri Yapısı
- 2. Disk Darboğazı ve Terminoloji
- 3. İndekslemenin Amacı ve İndeks Aileleri
- 4. Sıralı İndeks Dosyası
- 5. Varsayılan İndeksler ve İndeksin Bedeli
- 6. Kümelenmiş ve İkincil İndeksler
- 7. Seçicilik ve İndeksin Kullanılıp Kullanılmaması
- 8. Seyrek İndeks ve Çok Düzeyli İndeks
- 9. B+ Ağacı
- 10. Hash İndeksleri
- 11. Çok Anahtarlı Erişim ve Bileşik İndeksler
- 12. SQL'de İndeks Oluşturma
- Örnek Sorular

## 1. Saklama Ortamı ve Veri Yapısı

Hoca bu dersin ve bir sonraki dersin veritabanlarındaki veri yapıları üzerine olacağını söyleyerek başladı. Verinin olduğu her ortamda onu saklamak ve ona erişmek için bir düzene ihtiyaç vardır; bu ana hafızada da böyledir, diskte de. Ama verinin saklandığı ortam, kullanılacak veri yapısını ve algoritmayı önemli ölçüde etkiler.

Bunu görmek için hoca ana hafızadaki sıralama problemini hatırlattı.

**Soru:** Ana hafızadaki bir listeyi hangi algoritmalarla sıralayabiliriz? **Cevap:** Merge sort, quick sort, bazı özel durumlarda radix sort, bubble sort ve daha birçokları. Bu algoritmaların karmaşıklık analizleri bilinir.

**Soru:** Bir sıralama algoritmasının olabilecek en iyi karmaşıklığı nedir? **Cevap:** $O(n \log n)$. Hoca bundan daha iyisinin olmadığının ispatlandığını, aranmaması gerektiğini söyledi. $\log n$ çok iyidir, çünkü elemanların hepsine bakılmaz; $n$'de hepsine bakılır. $n \log n$ ise karesel değildir ama doğrusal da değildir; biraz masraflıdır. Diskte saklanan bir veri kümesini sıralamak da yine $n \log n$ maliyetlidir.

> **Ek bilgi (derste anlatılmadı):** $O(n \log n)$ alt sınırı karşılaştırma esaslı sıralama algoritmaları içindir. Radix sort gibi karşılaştırma yapmayan algoritmalar belirli veri türlerinde doğrusal zamanda çalışabilir; hocanın "özel durumlarda radix sort da iyi" demesi buna karşılık gelir.

## 2. Disk Darboğazı ve Terminoloji

### 2.1 Gecikme farkı

Neden ortama göre ayrım yapıldığının ilk cevabı, diskin ana hafızaya göre çok yavaş olmasıdır. SSD de ana hafızaya göre yavaştır.

**Soru:** Ana hafızada ortalama bir işlemin gecikmesi hangi mertebededir? **Cevap:** Nanosaniye.

Diskte rastgele bir noktaya erişmek, yani oradaki veriyi okumak ya da yazmak milisaniye mertebesindedir. Milisaniye, mikrosaniye, nanosaniye arasında $10^3$ çarpanları vardır; nanosaniye ile milisaniye arasında $10^6$, yani bir milyona yakın fark vardır. Hoca bu farkı hissettirmek için şu benzetmeyi yaptı: Nanosaniyeyi de saniyeyi de doğrudan hissedemeyiz; ama bir milyon kat fark, 3-5 saniyede yapılacak bir işi bir günde yapmak gibidir. Demek ki diskte müthiş bir darboğaz vardır.

<!-- BELİRSİZ: Hoca SSD için bir yerde "2.000'e yakın arada fark var", bir öğrenci sorusundan sonra ise "1.000.000'dan 100.000'e düştük" dedi; SSD ile ana hafıza arasındaki oran altyazıdan net çıkmıyor. -->

Veritabanında verinin saklandığı ortam disktir (manyetik disk ya da SSD), yani ikincil hafızadır (secondary memory). Böyle bir darboğaz olduğu için diskteki veriye erişim, erişilen verinin miktarı ve erişim tarzı hep önemlidir. Bir dosyanın 10 sayfasına erişmekle 500 sayfasına erişmek arasında elbette fark vardır.

### 2.2 Sayfa: aktarım ve ayırma birimi

Hoca terminolojinin bilinmesi gerektiğini, çünkü ileride bunların üzerine bir şeyler koyulacağını vurguladı. Dosyalara erişim disk sayfaları üzerinden olur; sayfa aktarım birimidir (unit of transfer).

**Soru:** Diskten tek bir karakter ya da tamsayı getirebilir miyim? **Cevap:** Hayır, bir sayfa getirebilirim.

Linux'ta sayfa 4 KB'dir; hoca Windows'ta da varsayılanın büyük olasılıkla 4 KB olduğunu söyledi. Tek bir bayta erişmek istense bile 4000 bayt gelir: O kadar uzağa gidilmişken tek bayt getirilmez. Veritabanlarında bu birim daha büyüktür; örneğin PostgreSQL'de varsayılan 8 KB'dir. Veritabanı sisteminin diskle iletişiminde kullandığı aktarım birimi 8 KB'dir.

Hoca bunu bir örnekle somutlaştırdı: `instructor` tablosunda tek bir kayda erişmek istiyoruz. Kayıt 100 bayt olsun. 8000 baytlık sayfada $8000 / 100 = 80$ kayıt vardır; yani sistem bize bir kayıt yerine yaklaşık 80 kayıt gönderir.

> **Ders sonrası not:** Altyazıda hoca bu hesap için "87 tane kayıt" diyor; $8000/100 = 80$'dir. Fark büyük olasılıkla konuşma sırasındaki bir sürçmeden ya da altyazı bozulmasından kaynaklanıyor.

Veritabanı tabloları fiziksel olarak diskte dosya olarak saklanır. Bu dosyaya erişimde iki kelime çok önemlidir: Aktarım birimi (unit of transfer) ve ayırma birimi (unit of allocation); ikisi de varsayılan olarak 8 KB'dir. Veri ambarları ve OLTP tarzı veritabanları gibi farklı tiplerde sayfa boyutunun ayarlanması (tuning) ayrı bir konudur; derste ayrıntısına girilmedi.

### 2.3 Sıralı ve rastgele erişim

Erişim tarzı sıralı (sequential) ya da rastgele (random) olabilir. 1000 sayfalık bir dosya düşünelim: $1000 \times 8\ \text{KB} = 8\ \text{MB}$. Hoca bunun aslında küçük bir dosya olduğunu, ana hafızaya sığacağını ve orada quick sort dahil her şeyin yapılabileceğini söyledi. Disk esaslı algoritmalar dosya 500 MB gibi büyük boyutlara ulaştığında önem kazanır.

Bu dosyanın 100 sayfasına erişeceksek, bu 100 sayfanın fiziksel olarak ardışık olması ile dosyanın farklı noktalarına dağılmış olması çok şeyi değiştirir. Sıralı erişim çok hızlıdır. Rastgele erişimde ise manyetik diskte mekanik bir hadise vardır: Disk kafası dosyanın sayfaları arasında sağa sola gider, bu boşa giden bir seyahat süresidir. Sıralı erişimde kafa doğrudan ardışık sayfaların üzerinden geçer. Hocanın verdiği mertebeye göre sıralı erişim rastgele erişimden 10 kat, bazı durumlarda 100 kata yakın daha hızlıdır. SSD'lerin bu açıdan avantajlı ve dezavantajlı yanları vardır; B+ ağaçlarının SSD ve disk için optimizasyonları farklıdır, ama derste bu ayrıntıya girilmedi.

Hoca güncel yapıların (NoSQL veritabanlarındaki LSM, yani log-structured merge ağaçları gibi) ve indeksin ayrıntılarının veritabanı sistem gerçekleme dersinde işlendiğini söyledi.

### 2.4 SSD, manyetik disk ve NVM

Bir öğrenci sorusu üzerine hoca SSD'yi açıkladı. Manyetik disk mekaniktir; SSD'de mekanik parça yoktur, veri elektronik olarak saklanır ve elektrik kesilince kaybolmaz. Maliyet de önemlidir: Manyetik disk çok ucuzdur. Hoca büyük şirketlerin veri merkezlerinde SSD'nin yaygın olduğunu ama manyetik disklerin de hâlâ kullanıldığını, ikisinin bir performans dengesiyle birlikte işletildiğini söyledi.

Erişim tarzı açısından SSD'de de aktarım birimi yine sayfadır; tek bir bayt değiştirilemez. Bunu değiştiren yeni teknoloji kalıcı bellektir (non-volatile memory, NVM): Veri disk gibi kalıcıdır ama SSD'den çok daha hızlıdır ve bayt adreslenebilirdir; ana hafızada olduğu gibi tek bir bayt adreslenebilir. Diskte ise baytlar bir akış hâlinde gelir, ana hafızaya 4 KB gelir. Hocaya göre 2017-2020 sonrasında bu tür bellek adreslenebilir diskler çıktı; bunlarla bütün sistem ve özellikle veritabanları köklü biçimde değişir. SSD ve manyetik disk esaslı geleneksel yaklaşımlarda ise temel düzen pek değişmedi.

### 2.5 İkinci darboğaz: Ana hafızaya alma ve tutarlılık

Hoca diskin darboğaz olmasının ikinci bir nedenini daha vurguladı: İşlemci diskteki veri üzerinde doğrudan işlem yapamaz. Diskteki veri ana hafızaya alınır, ana hafızada işlenir ve diske geri yazılır. Asıl birincil hafıza ana hafızadır.

Bu basit gerçek ikinci bir darboğaz doğurur, çünkü bir veri tekrarı ortaya çıkar: Veri diskten ana hafızaya alınıp değiştirildiği anda diskteki ile ana hafızadaki arasında tutarsızlık vardır. Ana hafızada değiştirilen verinin diske kavuşması gerekir. Kurtarma (recovery) bu noktada devreye girer: Elektrik kesilse bile, ana hafızada yapılmış ve onaylanmış (commit) bir güncellemenin kaybolmaması gerekir. Bu da ACID özelliklerinden dayanıklılık (durability) ile ilgilidir; hoca bunlara bu derste girmedi.

## 3. İndekslemenin Amacı ve İndeks Aileleri

Hocanın tanımıyla indeksleme, ana hafızaya sığmayan ve manyetik disk ya da SSD'de duran büyük dosyalarda aramayı, rastgele erişimi en aza indirecek şekilde ve en az veriyi aktararak sonlandırmaktır. Hem aktarılan veri miktarı hem rastgele erişim sayısı az olacak bir veri yapısına ihtiyaç vardır.

### 3.1 Sıralama esaslı ve hash esaslı indeksler

İndeksler sıralama esaslı ve sıralama esaslı olmayan diye ikiye ayrılır.

**Soru:** Sıralama masraflı bir şey; sıralı bir veri kümesi neden kıymetlidir? **Cevap:** İkili arama (binary search) yapılabilir. İkili arama logaritmiktir, doğrusal değildir; bu çok kıymetlidir.

Öteki aile hash yöntemleridir: Kayıtlar bir hash fonksiyonuyla yerleştirilir ve aynı fonksiyonla bulunur.

**Soru:** Hash ile aramanın karmaşıklığı nedir? **Cevap:** $O(1)$.

Hoca burada O-notasyonunun aldatıcı olabileceğine dikkat çekti. Sıralama esaslı aramanın maliyeti logaritmik, hash'in $O(1)$ olmasına rağmen yaygın veritabanlarının hocanın tahminiyle %80-90'ında arama yapıları ağaç organizasyonudur, yani sıralama esaslı B+ ağacıdır. Algoritma karmaşıklığı bize bir fikir verir ama bazen aldatıcıdır.

Hash'te kayıt zamana göre değişmeyen bir fonksiyonla yerleştirilir ve aynı fonksiyonla aranır: Varsa bulunur, yoksa bulunmaz. Ama öyle bir fonksiyon bulmak gerekir ki bu kadar veri yığınındaki kayıtların hepsini düzgün (uniform) dağıtsın. Temel sorun çakışmadır (collision): Hem veri kümesinin kendisi düzgün dağılmış değildir hem de fonksiyon mükemmel değildir. Üstelik veritabanı bir arşiv değil dinamik bir ortamdır: Kayıtlar eklenir ve çıkarılır. Günümüzde veri yığınlar hâlinde, patlamalı gelir; sosyal medyada bir olay olunca bütün veri bir anda gelir (hem bursty hem bulk). Bunu hash ile düzenlemek çok zordur.

B+ ağacı yaygın, hatta "ubiquitous", yani her yerde olan yapıdır. NoSQL veritabanlarında da log-structured merge ağacı biçiminde karşımıza çıkar.

### 3.2 Sıralanamayan veri

Konumsal (spatial) ve zamansal (temporal) gibi karmaşık veri tipleri sıralanamaz. Sayısal, alfanümerik, integer, float, date, string verileri sıralayabiliriz: Ankara Bursa'dan küçüktür. Ama iki konumdan hangisinin küçük olduğunu söyleyemeyiz. Bu yüzden B+ ağacı kullanılamaz; kayıtlar yakınlık esasına göre gruplandırılarak düzenlenir. Buna R-ağacı (R-tree) denir. Zamansal ve zaman-uzamsal veri için de ayrı indeks yapıları vardır; hocaya göre bu artık gelişmiş bir konudur.

## 4. Sıralı İndeks Dosyası

Hoca ilk olarak temel kavramları sıralama esaslı indeksler üzerinden anlatacağını, hash'e sonra geleceğini söyledi. Bu derste sunu olarak Silberschatz, Korth ve Sudarshan'ın "Database System Concepts" kitabının 7. baskısının "Chapter 14: Indexing" bölümü kullanıldı (ekrandan, 00:20:00).

### 4.1 Ana dosya ve indeks dosyası

İndeks, bir ana dosya üzerine kurulan yardımcı (auxiliary) dosyalardır; erişim yolları (access paths) da denir. Akla ilk gelen fikir şudur: Sıralama kıymetliyse ana dosyayı sıralayıp onda ikili arama yapalım. Bunun yerine daha küçük bir indeks dosyası kurulur: Üzerinde indeks oluşturulacak nitelik sıralanır ve indeks dosyası bu niteliği içeren kayıtlara işaretçiler (pointer) taşır.

İndeks dosyası sıralıdır, ama ana dosya, yani heap dosyası, oldukça esnektir: Yeni gelen kayıtlar en sona ya da boşalan yerlere eklenir; bir sıralama yoktur ve doğrudan bir aramaya hizmet etmez. İndeks dosyasındaki niteliğe arama anahtarı (search key) denir. Dosya bu anahtara göre sıralıdır; ikili aramayla anahtar logaritmik sürede bulunur, kaydın başka nitelikleri istenirse işaretçiyle ana dosyaya gidilir.

Slaytta `instructor` tablosunun `ID` niteliği üzerinde yoğun (dense) bir indeks vardır (ekrandan, 00:28:50): Her `ID` değeri (10101, 12121, 15151, 22222, ...) için bir indeks kaydı bulunur ve her kayıt ana dosyadaki satırı gösterir. Örnek sorgu:

```sql
SELECT salary FROM instructor WHERE ID = 20000;
```

Bu sorguda indekste ikili arama yapılır. Değer varsa işaretçiyle ana dosyaya gidilir. Hocanın işaret ettiği gibi, slayttaki veride 20000 yoktur; bu indeksten anlaşılır ve ana dosyaya gitmeye hiç gerek kalmaz.

Öteki slaytta `salary` üzerinde bir ikincil indeks vardır (ekrandan, 00:30:00). Slayttaki açıklamaya göre indeks kaydı, o arama anahtarı değerine sahip bütün kayıtların işaretçilerini tutan bir kovaya (bucket) işaret eder ve ikincil indeksler yoğun olmak zorundadır. Bu indeks şu tür sorgulara hizmet eder:

```sql
SELECT name FROM instructor WHERE salary = 40000;
```

### 4.2 Ana dosya neden sıralanmaz?

**Soru:** Madem ikili arama yapmaya bu kadar hevesliyiz, ayrı bir indeks dosyası yerine ana dosyayı sıralasak olmaz mı? **Cevap:** Bir öğrencinin cevabını hoca onayladı ve genişletti: Bir dosya aynı anda yalnız bir niteliğe göre sıralanabilir; hem `ID`'ye hem `salary`'ye göre sıralanamaz, ikinci niteliğin sırasının ilkine denk gelmesi çok küçük bir ihtimaldir. Ayrıca sürekli eklemeler ve çıkarmalar vardır; sıralı dosyayı bu koşullarda sıralı tutmak imkânsıza yakındır.

Bir dosyayı bir kez sıralamak bile ayrı bir külfettir; bunun için ana hafızadaki merge sort değil, harici sıralama (external sort) kullanılır. Yeni gelen kayıtlarla sıralılığı korumak için milyonlarca kaydın arasına yer açıp kaydırma yapmak gerekir; hoca bunun "akıl kârı olmadığını" söyledi.

İndeks dosyasının iki avantajı daha vardır:

- Daha küçüktür. Şeması yalnız "arama anahtarı + işaretçi"dir; örneğin `ID` 5 bayt, işaretçi 4 bayt olsa yaklaşık 10 bayt eder. Ana dosyadaki kayıt 50-60 bayt, 100 bayt ya da daha fazladır. 10 nitelikli bir tabloda indeks dosyası işaretçiler ihmal edilirse kabaca onda bir, 20 nitelikli bir tabloda yirmide bir boyuttadır.
- Sabit uzunluklu kayıtlardan oluşur. Ana dosyada kayıtlar değişken uzunluklu olabildiği için dosyanın ortasındaki kayda erişmek kolay değildir; indeks dosyasında sabit uzunluk ikili aramayı mümkün kılar.

## 5. Varsayılan İndeksler ve İndeksin Bedeli

Veritabanı kurulup veri yüklendiğinde (populate) sistem varsayılan olarak yalnız birincil anahtar üzerinde indeks oluşturur; bazı sistemler yabancı anahtar üzerinde de oluşturur. Hoca bunun PostgreSQL'de (pgAdmin'in sol tarafındaki nesne ağacında "Indexes" altında ya da katalog sorgularıyla) görülebileceğini söyledi.

### 5.1 Neden her niteliğe indeks konmaz?

**Soru:** İş yükünü henüz bilmiyoruz; sorgular bazen `salary`'ye, bazen `name`'e, bazen `dept_name`'e göre gelecek. Kayıt döneminde `takes` tablosunda yoğunlaşma olacak. Hazır olsun diye bütün niteliklere indeks koysak olmaz mı? **Cevap:** Bir öğrencinin cevabını hoca onayladı: İndeks bir veri tekrarıdır. Hoca bunu normalizasyon ve yabancı anahtar konusuna bağladı: Orada da zorunlu bir veri tekrarı vardı. İndeks küçük bir dosyadır ama bir niteliğin bütün değerlerini kopyalayıp sıralar; çok hızlı erişim sağlar ama fazlalık (redundant) bilgidir. `ID` kolay değişmez, `salary` ise kolayca değişir; değişince indeksin de güncellenmesi gerekir, yoksa indeks yanlış hizmet verir.

Hocaya göre yer kaplama çok önemli değildir; terabayt, petabayt ölçeğinde yer boldur. Asıl kritik olan tutarlılıktır: Güncelleme, ekleme yoğun bir iş yükünde arkadaki her indeksin de güncellenmesi sistemi hantallaştırır. Bu yüzden indeksler ihtiyaca göre, iş yüküne duyarlı biçimde oluşturulmalıdır.

### 5.2 Neden birincil anahtara varsayılan indeks?

**Soru:** Sistem neden birincil anahtar üzerinde kendiliğinden indeks oluşturur? **Cevap:** Tabloya ekleme yaparken yeni gelen kaydın birincil anahtarının tabloda zaten olup olmadığına bakılmalıdır. Bunu indeks üzerinden yapmak çok daha hızlıdır; yoksa tablo sırayla taranır. Bu tür sorgulara look-up sorgusu denir: Tek bir yere bakılır, "var mı yok mu" sorulur. Bir aralığı taramak ya da bir değerin başka niteliğine erişmek söz konusu değildir.

Aynı şekilde, o tabloya işaret eden yabancı anahtarı taşıyan başka bir tabloya kayıt eklenirken, girilen yabancı anahtar değerinin işaret edilen tabloda olup olmadığına bakılmalıdır. Yani birincil anahtar indeksi yalnız o tablodaki eklemeler için değil, ona bağlı tablolardaki güncellemeler için de önemlidir.

Ayrıca tablolar join yapılırken çoğu zaman yabancı anahtar ile birincil anahtar eşleştirilir. Join algoritmalarının bir kısmı indeks esaslıdır, bu yüzden bu indeksler kıymetlidir. Bazı sistemler bu nedenle yabancı anahtara da varsayılan indeks koyar; hoca PostgreSQL'in koymadığını söyledi.

Slayttaki ilgili madde de bunu sorar: Birincil anahtar ya da tekil (unique) kısıtı olan nitelikler üzerindeki indeksleri bütün veritabanları kendiliğinden kurar; bazıları yabancı anahtara da kurar (ekrandan, 02:06:45).

## 6. Kümelenmiş ve İkincil İndeksler

Hoca `ID` ve `salary` indekslerini karşılaştırırken terminolojinin karışabileceği uyarısını yaptı ve "birincil indeks" demek yerine şu adları kullandı:

- Kümelenmiş (clustered) indeks: Ana dosya da arama anahtarına göre sıralıdır. Belli bir aralıktaki değerler indekste bir arada olduğu gibi dosyada da bir aradadır; şekildeki oklar paralel aşağı iner.
- Kümelenmemiş (unclustered) ya da ikincil (secondary) indeks: Belli bir aralıktaki değerler dosyada bir arada değildir.

Hoca adların arkasındaki anlamın kavranmasını istedi: "Kümelenmiş" sözcüğü, değer olarak birbirine yakın kayıtların dosyada da fiziksel olarak bir arada olması demektir. İndeks dosyası zaten her zaman sıralıdır; fark ana dosyadadır.

Hoca daha önce ana dosyanın sıralanmaması gerektiğini söylediğini hatırlattı. PostgreSQL'de ana dosya hep heap'tir, sıralı dosya yoktur; dolayısıyla indeksler hep ikincildir. Oracle ve MS SQL Server'da ise kümelenmiş indeks vardır.

### 6.1 Hangi indeks daha kıymetli?

Hoca iki eşitlik sorgusu verdi:

```sql
SELECT * FROM instructor WHERE ID = ...;
SELECT * FROM instructor WHERE salary = 40000;
```

<!-- BELİRSİZ: Altyazıda ilk sorgunun değeri "ID eşittir 21" olarak geçiyor; tam değer anlaşılmıyor. -->

**Soru:** İndeks olmasaydı ne yapardık? Hangi indeks daha kıymetli? **Cevap:** `ID` indeksi olmasaydı, dosya `ID`'ye göre sıralı olduğu için yine ikili arama yapabilirdik. `salary` için ise ikili arama yapamayız, dosyayı sıralı taramak zorundayız. Bu yüzden eşitlik sorgusunda ikincil indeks daha kıymetlidir.

Sonra aralık sorguları geldi. `ID` 20000 ile 60000 arası istenirse, kümelenmiş indeksle 20000'e en yakın değer bulunur ve ana dosyada sırayla ilerlenir; dosya kümelenmiş olduğu için indekse geri dönmeye gerek yoktur. Hoca bunun ezberlenecek bir şey olmadığını, "ben bunu nasıl çalıştırırım" diye düşünülünce cevabın kendiliğinden çıktığını söyledi: İndekse her geri dönüş bir disk erişimidir.

`salary` 40000 ile 80000 arası istenirse: İndekste 40000 bulunur, ana dosyaya gidilir; sonra indekse dönülür, 60000 için yine ana dosyaya gidilir; 62000, ... 80000'e kadar her değer için bu tekrarlanır. Aralık genişledikçe indeksin anlamı kalmaz. Hocanın ifadesiyle, dosyadaki kayıtların %10'una, %20'sine erişilecekse bu sıralı taramayla yapılır; dersin başında söylendiği gibi sıralı erişim rastgele erişimden 10, 20, hatta 100 kata kadar daha iyidir. Kayıtların bir kısmı boşuna okunsa bile indeksten dolaşmaya gerek yoktur. İndeks zaten yer kaplayan, tutarlılık yükü getiren ayrı bir dosyadır.

## 7. Seçicilik ve İndeksin Kullanılıp Kullanılmaması

Hoca bütün bunlardan şu sonucu çıkardı: Sorguya ve indeksin tipine göre içeride ciddi bir ince ayar (tuning) vardır. "Filtrede kullanılan nitelik üzerinde indeks varsa otomatik kullanılır" diye ezbere konuşulamaz.

Buradaki anahtar kelime seçiciliktir (selectivity): Sorgu, kayıtların yüzde kaçını seçiyor? Seçicilik kuvvetliyse az kayıt çıkar, kayıtların büyük bölümü filtreye takılır. Birincil anahtar eşitliğinde tek kayıt gelir. `salary = 40000` dendiğinde ise sonuç farklı maaş değeri sayısına bağlıdır: 1000 hoca ve 10 farklı maaş değeri varsa $1000 / 10 = 100$ kayıt gelir.

Demek ki bir indeksin kullanılma ihtimali, seçiciliğe ve sorgunun eşitlik (equality) mi aralık (between) mı olduğuna göre artar ya da azalır. Hoca bu kavramlarla çok soruya yorum yapılabileceğini, kesin olarak "kullanır" ya da "kullanmaz" denemeyeceğini söyledi.

Hoca ikincil indeks için bir eşik de verdi: Sorgunun seçtiği kayıtlar varsayılan olarak yaklaşık %5, en fazla %10 civarını aşarsa sistem ikincil indeksi hiç kullanmaz, sıralı taramaya düşer; kesin değeri hatırlamadığını da belirtti. Sebep rastgele erişimin çok fazla olmasıdır: 1000 kayıttan 100 tanesine dosyanın dağınık yerlerinde tek tek gitmek gerekir.

> **Ek bilgi (derste anlatılmadı):** Gerçek sistemlerde böyle sabit bir eşik yoktur; iyileştirici (optimizer) indeksli ve indekssiz planların maliyetini tahmin edip ucuz olanı seçer. Hocanın verdiği %5-10, kararın büyük olasılıkla hangi mertebede değiştiğini gösteren kabaca bir değerdir.

Seçiciliği bilmek için iyileştiricinin veri dağılımını, örneğin `salary` alanındaki değerlerin dağılımını bilmesi gerekir. Her eklemede ve çıkarmada bunu kesin güncellemek büyük veride kolay değildir. Bu yüzden dağılım çoğu zaman histogramlarla kabaca tutulur (şu değer aralığında şu kadar kayıt var gibi) ve ara sıra güncellenir; bunun için analiz operatörleri vardır.

Hoca hangi indeksin kullanıldığının `EXPLAIN` ile görülebileceğini söyledi: Sorgunun başına `EXPLAIN` yazılınca o sorgunun çalışmasında kullanılan algoritmalar ve indeksler listelenir; grafik gösterimi de vardır. Aralık genişletildiğinde sistemin indeksi kullanmayı bıraktığı görülebilir, çünkü rastgele erişim sayısı artar. Join'ler ve iç içe sorgular işin içine girince indeksin kullanılıp kullanılmayacağını tahmin etmek çok daha zordur.

## 8. Seyrek İndeks ve Çok Düzeyli İndeks

### 8.1 Disk erişim sayısı örneği

Hoca indeks dosyasının da sonunda büyüdüğüne dikkat çekti. İndeks ana hafızaya sığsaydı, eşitlik sorgusu için tek bir disk erişimiyle (bir sayfa okuyarak) hedefe ulaşılabilirdi. Temsili bir sayısal örnek verdi: Ana dosyada her sayfaya iki kayıt sığsın, dosya 6 sayfa olsun. İndeks dosyasının kayıtları daha küçük olduğu için bir sayfada 6 indeks kaydı olsun. İkisi de diskte olsun.

İndeksle aramada önce indeks sayfasına erişilir, değer bulunur, işaretçiyle ikinci bir disk erişimi yapılarak ana dosyadaki sayfa okunur. Aranan kayıt dosyanın başındaysa indekssiz arama da iki sayfa okuyabilir; küçük dosyalarda fark belli olmaz. Ama kayıt dosyanın ortalarında olsaydı indeksin anlamı çok daha açık görünürdü. Örneğin 80000 maaşlı kayda indeksle bir iki disk erişimiyle, sıralı taramayla ise beşinci sayfaya kadar okuyarak ulaşılır. Milyonlarca sayfa olduğunda sıralı taramada belki 5000. sayfada bulunur; indeks ise sayfa başına daha çok kayıt içerdiği, sıralı olduğu ve ikili aramaya izin verdiği için çok daha hızlıdır.

İndeks dosyası da ana hafızaya sığmayacak kadar büyürse aynı sorun onun da başına gelir; o zaman onun üzerine de bir indeks kurulabilir, kurulursa iyi olur.

### 8.2 Seyrek indeks

Seyrek (sparse) indeks, yalnız bazı arama anahtarı değerleri için indeks kaydı içerir (ekrandan, 00:57:10). Slayttaki tanıma göre kayıtlar arama anahtarına göre sıralıysa uygulanabilir. $K$ arama anahtarlı kaydı bulmak için:

- $K$'dan küçük en büyük arama anahtarı değerine sahip indeks kaydı bulunur.
- Dosya, bu indeks kaydının gösterdiği kayıttan başlayarak sıralı taranır.

Slayttaki örnekte `ID`'ye göre sıralı `instructor` dosyası üzerinde yalnız 10101, 32343 ve 76766 değerleri için indeks kaydı vardır. Hocanın açıkladığı mantık şudur: Her bloğun başındaki değeri indekse koymak yeterlidir; aranan değerin hangi blokta olabileceği buradan çıkarılır. Örneğin bir değer arandığında, indeksteki komşu iki değer arasında olduğu için ancak tek bir blokta olabileceği anlaşılır.

### 8.3 Logaritmanın tabanını büyütmek

Kümelenmiş bir dosya üzerinde böyle seyrek bir indeks kurulup bu indeks de büyüdükçe onun da indeksi kurulursa, hocanın "olayın özeti" dediği sonuç ortaya çıkar: Aramadaki logaritmanın tabanı 2'den daha yukarıya çıkar. Her adımda, bir disk sayfasında kaç kayıt tutuluyorsa o oranda daraltılmış bir bölgeye gidilir. Bu, ikili aramadan daha iyi bir noktadır.

## 9. B+ Ağacı

### 9.1 Yapı

Slaytta B+ ağacı örneği gösterildi (ekrandan, 00:59:35). Slayttaki nota göre bu, `name` üzerinde ikincil ve yoğun bir indekstir. Yapı metin olarak şöyledir:

```text
Kök:           [Mozart]
İç düğümler:   [Einstein | Gold]                [Srinivasan]
Yapraklar:     [Brandt | Califieri | Crick] -> [Einstein | El Said] -> [Gold | Katz | Kim]
               -> [Mozart | Singh] -> [Srinivasan | Wu]
Ana dosya (ID'ye göre): 10101 Srinivasan, 12121 Wu, 15151 Mozart, 22222 Einstein,
               32343 El Said, 33456 Gold, 45565 Katz, 58583 Califieri,
               76543 Singh, 76766 Crick, 83821 Brandt, 98345 Kim
```

Hoca yaprak düzeyinin, başta gördüğümüz basit ve yoğun indeks olduğunu açıkladı: Ana dosyadaki bütün `name` değerleri burada sıralı olarak geçer. Milyonlarca kayıt olduğunda bu düzeyde de çok sayıda sayfa olur. Bunun üzerine seyrek bir indeks kurulur: Her yaprak sayfasının başındaki değer bir üst düzeye taşınır (Einstein, Gold, Mozart, Srinivasan gibi). Böyle yukarı doğru köke kadar çıkılır. Kökten yapraklara inerken her aşamada arama, bir sayfanın tutabileceği kayıt sayısı oranında daralır; hocanın deyişiyle budama miktarı çok artar.

### 9.2 Sayısal sezgi

Ağacın her düğümü bir disk sayfasıdır. Sayfa 8 KB, bir girdi kabaca 100 bayt olsun; sayfada yaklaşık 100 girdi, yani "arama anahtarı + işaretçi" çifti bulunur. Kökten başlayan aramada her düğümde bu 100 işaretçiden birinin altına inilir, yani her adımda veri kümesinin %1'lik bölümüne odaklanılır. Böylece arama $\log_2 n$ yerine $\log_{100} n$ adım sürer.

Hoca yeni bir algoritmanın keşfedilmediğini vurguladı: Karmaşıklık yine logaritmiktir. Ama tabanın 2 yerine $k$ olması pratikte algoritmayı çok kullanışlı yapar. Sayfa başına girdi sayısı, 8000 baytlık sayfalarda ve sıkıştırmayla tipik olarak 300-500'e kadar çıkar. Milyonlarca, milyarlarca kayıtta bile ağacın yüksekliği 3, 4, 5 olur, daha fazla olmaz. (Python ile denetim: $\log_2 10^6 \approx 19{,}9$, $\log_{100} 10^6 = 3$; $\log_{300} 10^9 \approx 3{,}6$, $\log_{500} 10^9 \approx 3{,}3$.)

Hocaya göre veri merkezlerindeki milyonlarca kayıt içinde bizimle ilgili bir veriye hızla erişilmesinin en dibinde yatan veri yapısı B+ ağacıdır. NoSQL veritabanlarında, işletim sistemlerinde ve dosya sistemlerinde de B+ ağacı ya da varyantları vardır.

### 9.3 Disk erişimi karşılaştırması

Hoca aynı temsili örneği (sayfa başına iki kayıt) ağaçla tekrar ele aldı: Ana dosyanın sonundaki `Kim` kaydına sıralı taramayla 6 sayfa okunarak ulaşılır. Ağaçta ise kök, iç düğüm, yaprak ve ana dosya sayfası olmak üzere 4 erişim yeter. Bu küçük şekilde fark 6'ya karşı 4'tür; asıl kazanç büyük dosyalarda ortaya çıkar.

Üstelik ağacın en çok erişilen kısmı olan kök ve iç düğümlerin çoğu zaten ana hafızaya sığar. Hocanın verdiği gerçekçi örnekte yükseklik 3-4 ise kök ve iç düğümler çoğu zaman ana hafızadadır; asıl aramada bir ya da iki disk erişimiyle, yani yalnız bir rastgele erişimle, milyonlarca kayıt arasında doğrudan hedefe gidilir. Ana dosyada aynı aramayı yapmak sıralı taramayı gerektirir.

Ağacın şeklini belirleyen derece (order) gibi parametreler ve yapının ayrıntıları slaytlarda vardır; derste bunlara girilmedi.

### 9.4 Her zaman dengeli

Arama, ekleme, çıkarma ve güncellemede her zaman kökten başlanır. Örneğin ana dosyada bir hocanın adı değişirse `name` indeksindeki girdinin de bulunup değiştirilmesi gerekir; bu da kökten başlayan bir aramayla olur.

B+ ağacı her zaman dengelidir. Ana hafızadaki ikili arama ağacı (BST) gelen verinin sırasına bağlıdır: Tam dengeli bir BST için veri statik ve hazır olmalı, sıralanmalı, sonra ortanca (median) kök yapılarak alt ağaçlar aynı şekilde kurulmalıdır. Veri artan sırada gelirse ağaç sürekli sağa doğru uzar ve bağlı listeye benzer. B+ ağacı ise gelişlerin sırasından bağımsız olarak dengeli kalır; bu yapılara kendini düzenleyen (self-organizing) yapılar denir. Ekleme ve silme algoritmaları bölme (split) ve birleştirme (merge) yapar; eklemeler her zaman yapraklardan yapılır ve etkisi köke doğru yayılır. Hoca bu algoritmaları öğrenmenin faydalı olduğunu ama derste ayrıntılandırmayacağını söyledi.

Sonuç: Ağaç her zaman logaritmik yüksekliktedir; en kötü durum analizi düzgündür. Veri hangi sırada gelirse gelsin en kötü durum ortalama durumla aynıdır.

### 9.5 Arama algoritması ve örnek

Slayttaki `find(v)` fonksiyonu şöyledir (ekrandan, 01:13:25):

```text
function find(v)
1. C = root
2. while (C is not a leaf node)
     1. Let i be least number s.t. V <= K_i
     2. if there is no such number i then
     3.     Set C = last non-null pointer in C
     4. else if (v = C.K_i) Set C = P_{i+1}
     5. else set C = C.P_i
3. if for some i, K_i = V then return C.P_i
4. else return null /* no record with search-key value v exists */
```

Bu slayttaki ağaç biraz farklıdır: Kök `Mozart`; iç düğümler `Califieri | Einstein | Gold` ve `Srinivasan`; yapraklar `Adams | Brandt`, `Califieri | Crick`, `Einstein | El Said`, `Gold | Katz | Kim`, `Mozart | Singh`, `Srinivasan | Wu`.

`Kim` araması (hocanın anlatımı): Kök sayfası ana hafızaya getirilir. `Kim`, `Mozart`'ın solunda olmalıdır; sol alt ağaca gidilir. Sağ alt ağaca hiç bakılmaz, o kısım budanmış (prune) olur; aramanın logaritmik olması budur. İç düğümde `Kim`, `Gold`'dan büyük olduğu için son işaretçiden ilgili yaprağa inilir ve `Kim` orada bulunur.

- Sorgu `SELECT salary FROM instructor WHERE name = 'Kim'` ise ana dosyaya gidilip `Kim`'in kaydından maaş okunur.
- Sorgu yalnız `Kim`'in var olup olmadığını soruyorsa cevap indeksten anlaşılır. Buna yalnız indeksle değerlendirme (index-only evaluation) denir; ana dosyaya ayrı bir disk erişimi gerekmez.

Aralık sorgusu: Adları `Califieri` ile `Srinivasan` arasında olan kaç hoca var?

```sql
SELECT COUNT(*) FROM instructor WHERE name BETWEEN 'Califieri' AND 'Srinivasan';
```

Kökten `Califieri`'ye inilir. Sonra yapraklardaki işaretçilerle sağa doğru gidilir; yukarı çıkmaya gerek yoktur. Yapraklar bu indeks dosyasının 8 KB'lık sayfalarıdır ve sıralıdır. `Califieri`'den `Srinivasan`'a kadar sayılır ve durulur. Sorgunun arkada işlenişi budur.

### 9.6 İndeks kullanılır mı?

**Soru:** Sorgu `COUNT` yerine `SELECT SUM(salary) FROM instructor WHERE name BETWEEN 'Califieri' AND 'Srinivasan'` olsaydı indeks kullanılır mıydı? **Cevap:** Bir öğrencinin cevabı üzerine hoca, aralığın veri alanının önemli bir kısmını kapladığını, bu yüzden indeksin kullanılmayabileceğini söyledi: Her kayıt için ana dosyaya gitmek gerekir ve rastgele erişim sayısı artar. `COUNT` sorgusunda ise aralık geniş olsa da ana dosyaya gitmek gerekmediği için indeks kullanılır.

## 10. Hash İndeksleri

### 10.1 Neden geç benimsendi?

Hoca hash'in de önemli olduğunu ama B+ ağacı kadar yaygın olmadığını söyledi. Hocanın verdiği örneğe göre PostgreSQL'de hash indeksinin gerçek anlamda kullanılması 10. sürümden sonra başladı. Hash 70-80'lere dayanan klasik bir yöntem olmasına rağmen ancak 20-30 yıl sonra bir sistemde gerçek anlamda kullanılabildi. Sebebi hem çakışmalar ve taşmalar hem de sistem bütünleşmesidir: Hash indeksinin eş zamanlılık ve kurtarma gibi modüllerle ve onların algoritmalarıyla uyumlu çalışması gerekir; B+ ağacı bunlara daha uyumlu olmuştur. Günümüzde hash yöntemleri PostgreSQL'in `EXPLAIN` çıktılarında ve başka veritabanlarında görülebilmektedir.

> **Ders sonrası not:** Hoca PostgreSQL 10'un 2008-2010 yıllarına denk geldiğini söyledi. PostgreSQL 10 büyük olasılıkla 2017'de yayımlandı; hash indekslerinin kalıcı günlüğe (WAL) yazılması ve böylece çökme sonrası güvenli hâle gelmesi de büyük olasılıkla bu sürümle geldi.

### 10.2 Kova ve hash fonksiyonu

B+ ağacında kayıtlar sıralanarak düzenlenirken hash'te bir $h$ fonksiyonuyla kovalara (bucket) dağıtılır. Slayttaki tanımlar şunlardır (ekrandan, 01:40:00):

- Kova, bir ya da daha fazla girdi içeren saklama birimidir; genellikle bir disk bloğudur. Bir girdinin kovası arama anahtarı değerinden hash fonksiyonuyla bulunur.
- Hash fonksiyonu $h$, bütün arama anahtarı değerlerinin kümesi $K$'dan bütün kova adreslerinin kümesi $B$'ye bir fonksiyondur.
- Hash fonksiyonu erişim, ekleme ve silmede girdinin yerini bulmak için kullanılır.
- Farklı arama anahtarı değerleri aynı kovaya düşebilir; bu yüzden girdiyi bulmak için bütün kova sıralı taranır.
- Hash indeksinde kovalar kayıtlara işaretçi içeren girdileri, hash dosya organizasyonunda ise kayıtların kendisini tutar.

Hoca B+ ağacındaki düğümlerin sayfalara denk gelmesi gibi burada da kovaların disk sayfalarına denk geldiğini söyledi. Fonksiyon, veriyi dağıtacağımız fiziksel dosyanın sayfa sayısına bağlıdır: Veri kümesi yaklaşık 100 sayfalıksa, $f(x) \bmod N$ gibi bir fonksiyon kullanılır; $f(x)$ istenen bir değer üretir, $\bmod N$ ile adres alanına (100 sayfaya) normalize edilir. Arama yaparken de aynı fonksiyon kullanılır.

Hoca terminolojiye de değindi: Kayıtların kendisi hash esaslı yerleştirilirse buna hash dosyası (hash file) denir. Aynısı B+ ağacında da vardır: Kayıtlar bir arama anahtarına göre B+ ağacında yerleştirilirse B+ ağacı dosyası olur. Derste ise yine "heap dosyası + üzerinde B+ ağacı ya da hash indeksi" düzeniyle devam edildi.

### 10.3 Taşma

Gerçek hayatta hash'in kullanılmasına engel olan önemli problemlerden biri taşmalardır (overflow). İki sebebi vardır: Veri kümesinde aynı arama anahtarını taşıyan çok kayıt olabilir (seçicilik düşüktür, değer tekil değildir ve hepsi aynı kovaya düşer) ya da hash fonksiyonu veriyi düzgün dağıtamaz. Düzgün ve rastgele dağıtım için matematiksel modeller (randomized fonksiyonlar) vardır; hoca veritabanı derslerinde bunun pek işlenmediğini söyledi.

Taşma olunca bir kovaya taşma kovaları zincirlenir. Arama sırasında o kovaya gelindiğinde bütün taşan kovalarda aranır; kova içinde ikili arama da yoktur, sıralama yoktur. Kayıtlar sayfa içinde ayrıca sıralı tutulabilir, ama bu işlemciyi ilgilendiren küçük bir iştir; asıl ölçü disk erişimidir ve disk darboğazının yanında böyle bir düzenleme çok küçük kalır.

### 10.4 Slayt örneği

Slayttaki örnek (ekrandan, 01:45:10): `instructor` dosyasının `dept_name` anahtarıyla hash dosya organizasyonu.

- 10 kova vardır.
- $i$. harfin ikili gösteriminin $i$ tamsayısı olduğu varsayılır.
- Hash fonksiyonu karakterlerin ikili gösterimlerinin toplamının 10'a göre modunu döndürür.
- Örnekler: $h(\text{Music}) = 1$, $h(\text{History}) = 2$, $h(\text{Physics}) = 3$, $h(\text{Elec. Eng.}) = 3$.

Hoca bir sonraki slayttaki şekilde bazı kovaların boş kaldığını, taşma olmadığını ama yeni veri gelince bazı kovalarda yığılma olup taşmaların başlayacağını söyledi.

<!-- BELİRSİZ: Hoca şekil için "baştan 8 sayfa allocate etmişim, sadece 6 tanesini doldurmuşuz" dedi; önceki slayt 10 kova diyor. Şekil karesi okunmadı. -->

### 10.5 Statik hash'in sorunu

**Soru:** Bazı kovalar çok dolarsa, veri artık bu düzene sığmazsa ne çözüm önerirsiniz? **Cevap:** Bir öğrenci kovaları birbirine bağlamayı önerdi; hoca bunun zaten yapıldığını (taşma zinciri) ama zincir uzadıkça düzenin anlamını kaybettiğini, arama maliyetinin arttığını söyledi. Başka bir öğrencinin önerdiği yeniden hash'leme (rehash) için hoca şunu söyledi: Hash fonksiyonu değiştirilir ve bütün veri yeniden dağıtılır. Ama bu çevrim içi yapılamaz; sorgular ve aramalar gelirken sistem durdurulup yeniden hash'lenip tekrar hizmete sokulmalıdır. Bu ancak gece 3'te bir toplu iş (batch) olarak yapılabilir.

Temel sorun statik olmasıdır. $\bmod N$ ile 100 sayfalık bir dosya ayarlarız, ama veritabanında gerçek veri miktarını önceden bilemeyiz; yeni kayıtlar gelir, eskiler çıkar. B+ ağacı kendini düzenleyen bir yapıdır: Ne kadar veri gelirse gelsin dengesini kaybetmez, ihtiyaç kadar yavaş yavaş yükselir. Hash'ten de böyle bir yapı beklenir: Bir sayfalık kovayla başlayıp veri geldikçe iki, üç, dört sayfaya kademeli (gradually) büyümek.

**Soru:** Ana hafıza algoritmalarında kendini düzenleyen hangi ağaç yapıları vardır? **Cevap:** AVL ağacı ve kırmızı-siyah ağaç (red-black tree); bunlar belli bir kritere kadar kendilerini dengeler.

Hash için bu tür kademeli büyüyüp küçülen algoritmalar doğrusal hash (linear hashing) ve genişletilebilir hash (extendible hashing) gibi dinamik hash yöntemleridir. Hoca bunların da B+ ağacı gibi çok özgün algoritmalar olduğunu, derste yalnız adlarını andığını, merak edenlerin incelemesini önerdi.

> **Ek bilgi (derste anlatılmadı):** Genişletilebilir hash'te bir dizin (directory) kovaları gösterir; bir kova taşınca yalnız o kova bölünür, gerekirse dizin iki katına çıkar. Doğrusal hash'te dizin yoktur; kovalar sırayla, birer birer bölünür. İkisi de bütün dosyayı yeniden hash'lemeden büyümeyi sağlar.

### 10.6 Hash ve aralık sorguları

**Soru:** `Califieri` ile `Srinivasan` arasındaki adlar için kullanılan indeks B+ ağacı değil de hash indeksi olsaydı ne olurdu? **Cevap:** B+ ağacında `Califieri`'ye ulaşıldıktan sonra yol açıktır: `Califieri`, `Crick`, `Einstein`, `El Said`, `Gold`, ... yan yanadır, çünkü yapı sıralama esaslıdır. Hash indeksinde ise `Califieri`'nin kovasına bir kez gidilir; ama o kovada ona alfabetik olarak yakın değerler yoktur, dağıtım rastgeledir. Bu yüzden aralık sorgularında hash indeksi kullanılamaz.

**Soru:** Ne zaman mümkün olur? **Cevap:** Bir öğrencinin cevabını hoca tamamladı: Aralık çok darsa ve alan tamsayıysa, örneğin 10 ile 12 arası, 10, 11 ve 12 değerleri tek tek aranabilir. Ama alan float ya da double ise aralık ne kadar dar olursa olsun hangi değerlere bakılacağı bilinemez. Genel olarak aralık sorgularında hash indeksinin kullanıldığı görülmez; eşitlik sorgularında ise kullanılabilir. Hatta hash fonksiyonu veri dağılımına göre başarılıysa birincil anahtar için B+ ağacı yerine hash indeksi bile varsayılan olarak oluşturulabilir, çünkü hash indeksi de look-up yapabilir.

Hoca hash'in ikinci planda kalmasının iki sebebini özetledi: Birincisi sistem bütünleşmesinin (eş zamanlılık ve kurtarma ile uyum) kritik olması; ikincisi, belki ilk sırada söylenmesi gereken, aralık sorguları gibi çok yaygın bir sorgu tipinde hiç kullanılamaması. Ortalaması 3 ile 3,5 arasında olan ya da 3'ten yüksek olan öğrencileri aramak gibi sorgular çok yaygındır.

## 11. Çok Anahtarlı Erişim ve Bileşik İndeksler

### 11.1 Birden çok koşullu sorgu

Şimdiye kadarki örnekler tek koşulluydu; ama yüklemde birden çok nitelik olabilir. Slayttaki örnek (ekrandan, 01:54:40):

```sql
select ID
from instructor
where dept_name = 'Finance' and salary = 80000;
```

**Soru:** Bu sorgu için hangi nitelik üzerindeki indeksin kesinlikle hiçbir anlamı yoktur? **Cevap:** `ID`. `ID` üzerinde arama yapılmıyor; koşulu sağlayan kayda ulaşıldıktan sonra `ID` yalnız okunuyor.

`dept_name` üzerinde, `salary` üzerinde, ikisinde birden ya da hiçbirinde indeks olabilir. Slayttaki stratejiler ve hocanın açıklamaları:

- Sıralı tarama (table scan, sequential scan): İndeks olsa bile seçilebilir. Bütün tablo taranır, her kayıtta `dept_name = 'Finance'` ve `salary = 80000` denetlenir. Hocaya göre bu kabul edilebilir bir yoldur. İyileştirici önce indeks olup olmadığına, varsa seçiciliğine bakar; indeks çok kayıt çıkarıyorsa kullanmaz.
- `dept_name` indeksiyle bölümü Finance olan hocalar bulunur, bu kayıtlara dosyada erişilip `salary = 80000` testi yapılır.
- `salary` indeksiyle maaşı 80000 olanlar bulunur, ana dosyada `dept_name = 'Finance'` testi yapılır.
- İki indeks birlikte kullanılır: `dept_name` indeksinden Finance kayıtlarının, `salary` indeksinden 80000 kayıtlarının işaretçileri alınır ve iki işaretçi kümesinin kesişimi alınır. Dosyaya yalnız iki koşulu da kesin sağlayan kayıtlar için gidilir; ıskalama yoktur, ana dosyada ek bir işlem gerekmez.
- Bileşik indeks (composite index).
- Bitmap indeksi: Slayta göre iki indeksin seçiciliği düşükse, yani her biri az sayıda farklı değer içeriyorsa (ekrandan, 01:54:40). Hoca bitmap indekslerine derste girmedi.

**Soru:** İki nitelikte de indeks varken iyileştirici hiçbirini kullanmayabilir mi? **Cevap:** Bir öğrencinin "sıralı tarama yapar" cevabını hoca onayladı. Finance bölümünden çok kayıt çıkabilir; farklı maaş değeri sayısı azsa 80000 de çok kayıt döndürür. Bu durumda hiçbir indeks kullanılmayıp sıralı taramaya düşülebilir.

Hoca bunların sorgu işlemedeki (query execution) algoritmalara bir adım olduğunu, join'lerin ise ayrı algoritmalar gerektirdiğini söyledi. Join'ler kartezyen çarpım esaslı olduğu için maliyetlidir ve ilişkisel veritabanlarında önemli bir potansiyel darboğazdır.

### 11.2 Bileşik indeks

Şimdiye kadar tek nitelikli indeksler konuşuldu. İki nitelik yan yana getirilip birlikte sıralanabilir mi? Evet: `dept_name` ve `salary` yan yana konur ve önce birincisine, eşitlikte ikincisine göre sıralanır (Finance 80000, Finance 90000, Finance 100000, sonra başka bir bölüm). Buna sözlük sırası (lexicographic order) denir. Sıralanabiliyorsa küçük-büyük ilişkisi tanımlıdır, dolayısıyla üzerine indeks kurulabilir.

Slayttaki açıklama (ekrandan, 02:03:00): `(dept_name, salary)` bileşik arama anahtarı üzerinde bir indeks olsun.

- `where dept_name = 'Finance' and salary = 80000` koşulunda bu indeks yalnız iki koşulu da sağlayan kayıtları getirir. Ayrı indeksler kullanmak daha az verimlidir; yalnız bir koşulu sağlayan çok sayıda kayıt ya da işaretçi getirilebilir.
- `where dept_name = 'Finance' and salary < 80000` de verimli işlenir.
- `where dept_name <= 'Finance' and salary = 80000` ise verimli işlenemez: İlk koşulu sağlayan ama ikinciyi sağlamayan çok kayıt getirilebilir.

Slayttaki yaprak dizilimi şöyledir:

```text
Acc 1000, Acc 2000, Acc 4000, Acc 8000, Acc 10000, ...,
Business 1000, Business 4000, Business 8000, Business 10000, ...,
Finance 1000, Finance 2000, Finance 4000, Finance 8000, Finance 10000
```

Hoca bunu şöyle yorumladı: `dept_name = 'Finance' and salary < 80000` sorgusunda iyileştirici doğrudan Finance bölgesine gider ve yalnız o bölgeyi (slaytta mavi gösterilen kısım) okur; boşa hiçbir yere erişmez. Yani `salary` tarafında aralık olan sorgularda `(dept_name, salary)` çok iyidir. Aralık `dept_name` tarafında olsaydı `(salary, dept_name)` sırası gerekirdi.

### 11.3 Nitelik sırası

**Soru:** Bu nitelikler üzerinde çok sorgu geliyor ve bileşik indeks kurmaya karar verdik. `(dept_name, salary)` mı daha iyi, `(salary, dept_name)` mi? **Cevap:** Öğrencilerin cevaplarını hoca toparladı: Seçim seçiciliğe ve sorgu tipine bağlıdır. İki koşul da eşitlikse fark azdır; ama bazı sorgularda `salary` üzerinde aralık geliyorsa `(dept_name, salary)` tercih edilir.

Hoca bir başka noktaya daha dikkat çekti: `(dept_name, salary)` indeksi yalnız `dept_name` üzerinde yapılan bir aramaya hizmet eder, çünkü bütün bölümler sıralıdır. Ama yalnız `salary` üzerindeki bir aramaya hizmet etmez: Maaşlar yalnız aynı bölümün içinde sıralıdır, global olarak sıralı değildir. `SELECT ... FROM instructor WHERE salary = ...` sorgusu için bu indeksin hiçbir anlamı yoktur. Bu yüzden ilk sırada hangi niteliğin olacağını seçmek çok önemlidir.

> **Hocanın vurgusu:** Veritabanı indeks ayarlama (index tuning) çok geleneksel bir problemdir ve kesin bir çözümü yoktur, çünkü ortam dinamiktir ve arama uzayı çok geniştir. Gerçek bir veritabanında 10-20 tablo ve her tabloda 8-20 nitelik olabilir; iş yüküne göre hangi tabloda hangi niteliklere tekli ya da iki, üç nitelikli bileşik indeks kurulacağı zor bir problemdir. Üstelik iş yükü saatler ve günler içinde değişir, indekslerin de değişmesi gerekir. Bu yüzden yıllardır çalışılan bir konudur.

## 12. SQL'de İndeks Oluşturma

Slayttaki örnek (ekrandan, 02:06:45):

```sql
create index takes_pk on takes (ID, course_ID, year, semester, section);
drop index takes_pk;
```

Slaytta ayrıca şu maddeler vardır: Çoğu veritabanı sistemi indeksin türünün ve kümelenmesinin belirtilmesine izin verir; birincil anahtar ya da tekil kısıt taşıyan nitelikler üzerindeki indeksleri bütün veritabanları kendiliğinden kurar; bazıları yabancı anahtar nitelikleri üzerinde de indeks kurar. Örneğin $takes \bowtie \sigma_{name='Shankar'}(student)$ sorgusunda yabancı anahtar indeksi işe yarar. İndeksler aramaları çok hızlandırır ama güncellemelere maliyet getirir; bazı veritabanlarında iş yüküne göre indeks seçen indeks ayarlama yardımcıları (tuning assistants/wizards) vardır.

Hoca varsayılan indeks türünün B+ ağacı olduğunu, başka bir tür istenirse `using` ile belirtildiğini (örneğin `using hash`) söyledi. Sistemlerde 7-8 farklı indeks türü vardır, çünkü konumsal veri, metin, görüntü ve çoklu ortam gibi karmaşık veriler için de indeksler oluşturulur.

> **Ek bilgi (derste anlatılmadı):** PostgreSQL'de bu sözdizimi `CREATE INDEX ad ON tablo USING hash (nitelik);` biçimindedir. `USING` yazılmazsa `btree` (B+ ağacı ailesi) kullanılır; diğer seçenekler arasında GiST, GIN, SP-GiST ve BRIN vardır.

Son olarak hoca konumsal verinin indekslenmesine kısaca değindi: Konumsal veride sıralama olmadığı için kayıtlar konumsal yakınlığa (proximity) göre gruplanır; birbirine yakın olanlar aynı disk sayfasına konur. Bir sorgu geldiğinde ilgili kayıtların büyük olasılıkla aynı sayfada yakalanması amaçlanır. Bu esasla B+ ağacına benzer bir ağaç kurulur.

Dersin sonunda bir öğrenci kümelenmiş indeks kavramını sordu. Hoca, indeksin kendisinin zaten her zaman sıralı olduğunu, "kümelenmiş" sözcüğünün değer olarak birbirine yakın kayıtların ana dosyada da fiziksel olarak bir arada olup olmadığını anlattığını, ana dosya sıralı olduğunda indeksin kümelenmiş indeks olduğunu tekrarladı; bunun anahtarın tekil olmasıyla ilgisi olmadığını da ekledi.

## Örnek Sorular

**1.** (derste sözlü, 00:01:33-00:03:27) Ana hafızadaki bir listeyi sıralamak için hangi algoritmalar kullanılır ve bir sıralama algoritmasının olabilecek en iyi karmaşıklığı nedir?

Cevap (derste verildi): Merge sort, quick sort, özel durumlarda radix sort, bubble sort gibi algoritmalar. En iyi karmaşıklık $O(n \log n)$'dir; diskteki bir veri kümesini sıralamak da $n \log n$ maliyetlidir.

**2.** (derste sözlü, 00:04:07-00:05:21) Ana hafızada ve diskte bir erişimin gecikmesi hangi mertebededir, aradaki fark ne kadardır?

Cevap (derste verildi): Ana hafızada nanosaniye, diskte rastgele erişim milisaniye mertebesindedir; fark yaklaşık $10^6$ kattır.

**3.** (derste sözlü, 00:20:32-00:21:37) Sıralı bir veri kümesi neden kıymetlidir? Hash ile aramanın karmaşıklığı nedir ve buna rağmen veritabanlarında neden B+ ağacı baskındır?

Cevap (derste verildi): Sıralı veride logaritmik ikili arama yapılabilir. Hash aramasının karmaşıklığı $O(1)$'dir; ama çakışmalar, taşmalar, verinin dinamik ve patlamalı gelmesi, sistem bütünleşmesinin zorluğu ve aralık sorgularında kullanılamaması yüzünden B+ ağacı baskındır.

**4.** (derste sözlü, 00:30:41-00:32:34) İkili arama için ayrı bir indeks dosyası kurmak yerine neden ana dosyayı sıralamıyoruz?

Cevap (derste verildi): Bir dosya aynı anda yalnız bir niteliğe göre sıralanabilir; sürekli ekleme ve silme altında sıralı tutmak çok pahalıdır. İndeks dosyası daha küçüktür ve sabit uzunluklu kayıtlardan oluştuğu için ikili aramaya uygundur.

**5.** (derste sözlü, 00:35:14-00:37:23) Veritabanı kurulunca bütün tabloların bütün niteliklerine indeks koymak neden doğru değildir?

Cevap (derste verildi): İndeks bir veri tekrarıdır; her güncellemede indeksin de güncellenmesi gerekir. Güncelleme yoğun iş yükünde sistem hantallaşır. Asıl sorun yer değil tutarlılık yüküdür; indeksler iş yüküne göre seçilmelidir.

**6.** (derste sözlü, 00:39:02-00:41:58) Sistem neden birincil anahtar üzerinde varsayılan olarak indeks oluşturur? Bazı sistemler neden yabancı anahtara da indeks koyar?

Cevap (derste verildi): Birincil anahtar kısıtını denetlemek için yeni kaydın anahtarının tabloda olup olmadığına bakmak (look-up) gerekir; yabancı anahtar içeren tablolara ekleme yapılırken de işaret edilen tabloda birincil anahtar aranır. Yabancı anahtar indeksi ise yabancı anahtar ile birincil anahtar üzerinden yapılan join'leri hızlandırır.

**7.** (derste sözlü, 00:44:20-00:47:51) `ID` üzerinde kümelenmiş, `salary` üzerinde ikincil indeks var. (a) `ID = ...` ve `salary = 40000` eşitlik sorgularında hangi indeks daha kıymetlidir? (b) `ID` 20000-60000 ve `salary` 40000-80000 aralık sorguları indeksle nasıl işlenir?

Cevap (derste verildi): (a) İkincil indeks daha kıymetlidir; çünkü `ID` indeksi olmasa da dosya `ID`'ye göre sıralı olduğu için ikili arama yapılabilir, `salary` için ise sıralı tarama gerekir. (b) Kümelenmiş indeksle aralığın başı bulunur, ana dosyada sırayla ilerlenir. İkincil indekste her değer için indeks ile ana dosya arasında gidip gelinir; aralık genişledikçe (kayıtların yaklaşık %10-20'si) sıralı tarama daha ucuz olur.

**8.** (ekrandan, 01:13:25; derste sözlü, 01:11:33-01:12:45) Slayttaki B+ ağacında (kök `Mozart`; iç düğümler `Califieri | Einstein | Gold` ve `Srinivasan`) `Kim` nasıl aranır? Sorgu yalnız `Kim`'in var olup olmadığını soruyorsa ana dosyaya gidilir mi?

Cevap (derste verildi): Kökte `Kim` < `Mozart` olduğu için sol alt ağaca inilir, sağ alt ağaç budanır. İç düğümde `Kim` > `Gold` olduğu için son işaretçiden `Gold | Katz | Kim` yaprağına inilir ve `Kim` bulunur. Yalnız varlık soruluyorsa cevap indeksten çıkar (index-only evaluation), ana dosyaya gidilmez; maaş isteniyorsa işaretçiyle ana dosyaya gidilir.

**9.** (derste sözlü, 01:13:09-01:15:48) `SELECT COUNT(*) FROM instructor WHERE name BETWEEN 'Califieri' AND 'Srinivasan'` ve aynı koşulla `SELECT SUM(salary) ...` sorgularında `name` üzerindeki B+ ağacı indeksi kullanılır mı?

Cevap (derste verildi): `COUNT` sorgusunda indeks kullanılır: `Califieri` yaprağı bulunur, bağlı yapraklarda sağa doğru `Srinivasan`'a kadar sayılır, ana dosyaya gidilmez. `SUM(salary)` sorgusunda her kayıt için ana dosyaya gitmek gerekir; aralık veri alanının büyük kısmını kapsadığı için iyileştirici indeksi kullanmayabilir. Bu, `EXPLAIN` ile denetlenebilir.

> **Çözüm (derste verilmedi):** Slayttaki yapraklarda (ekrandan, 01:13:25) `Califieri` ile `Srinivasan` arasında, ikisi dahil `Califieri, Crick, Einstein, El Said, Gold, Katz, Kim, Mozart, Singh, Srinivasan` olmak üzere 10 ad vardır; `COUNT(*)` sonucu 10'dur. (Python ile sayıldı.)

**10.** (derste sözlü, 01:46:14-01:47:44) Statik hash'te bazı kovalar çok dolup taşarsa ne yapılabilir?

Cevap (derste verildi): Taşma kovaları zincirlenir, ama zincir uzadıkça arama pahalılaşır. Yeniden hash'leme yapılabilir, ama bu çevrim içi yapılamaz; sistem durdurulmalıdır. Asıl çözüm kademeli büyüyüp küçülen dinamik hash yöntemleridir (doğrusal hash, genişletilebilir hash).

**11.** (derste sözlü, 01:50:17-01:52:54) `name` üzerindeki indeks B+ ağacı değil hash indeksi olsaydı `Califieri` ile `Srinivasan` arasındaki aralık sorgusu için kullanılabilir miydi? Hash indeksi aralık sorgusunda ne zaman kullanılabilir?

Cevap (derste verildi): Kullanılamaz; hash yakın değerleri aynı kovaya koymaz, dağıtım rastgeledir. Yalnız alan tamsayıysa ve aralık çok darsa (10 ile 12 arası gibi) değerler tek tek aranabilir; float ya da double alanda mümkün değildir.

**12.** (ekrandan, 01:54:40; derste sözlü, 01:54:47-02:00:35) `select ID from instructor where dept_name = 'Finance' and salary = 80000` sorgusu için hangi nitelik üzerindeki indeksin anlamı yoktur? Tek nitelikli indekslerle hangi stratejiler kullanılabilir?

Cevap (derste verildi): `ID` üzerindeki indeksin anlamı yoktur. Stratejiler: `dept_name` indeksi + `salary` testi; `salary` indeksi + `dept_name` testi; iki indeksin işaretçi kümelerinin kesişimi; bileşik indeks; bitmap indeksi; indeks olsa da sıralı tarama. İki koşul da çok kayıt seçiyorsa iyileştirici sıralı taramaya düşebilir.

**13.** (ekrandan, 02:03:00; derste sözlü, 02:01:24-02:06:31) `(dept_name, salary)` bileşik indeksi hangi koşulları verimli işler? `(dept_name, salary)` ile `(salary, dept_name)` arasında nasıl seçim yapılır? `(dept_name, salary)` indeksi yalnız `salary` üzerindeki bir sorguya hizmet eder mi?

Cevap (derste verildi): `dept_name = 'Finance' and salary = 80000` ve `dept_name = 'Finance' and salary < 80000` verimli işlenir; `dept_name <= 'Finance' and salary = 80000` verimli işlenemez. Seçim seçiciliğe ve iş yükündeki sorgu tipine bağlıdır: Aralık `salary` tarafındaysa `(dept_name, salary)`, `dept_name` tarafındaysa `(salary, dept_name)` uygundur. `(dept_name, salary)` yalnız `dept_name` sorgularına hizmet eder; maaşlar global olarak sıralı olmadığı için yalnız `salary` sorgularına hizmet etmez.

## Dersin Toparlaması

Bu derste indekslemenin neden gerektiği disk darboğazından başlayarak kuruldu: Disk erişimi ana hafızadan yaklaşık bir milyon kat yavaştır, aktarım birimi sayfadır ve rastgele erişim sıralı erişimden çok pahalıdır. Bu çerçevede sıralı indeks dosyası, ana dosyanın neden sıralanmadığı, birincil anahtara varsayılan indeksin sebebi, indekslerin bakım yükü, kümelenmiş ve ikincil indeks ayrımı ve iyileştiricinin seçiciliğe göre indeks kullanma kararı ele alındı. Seyrek indeksten çok düzeyli indekse geçilerek B+ ağacının logaritmanın tabanını sayfa başına girdi sayısına çıkardığı, her zaman dengeli kaldığı ve aralık sorgularını bağlı yapraklarla verimli işlediği gösterildi.

Hash indeksleri kovalar, hash fonksiyonu, taşmalar ve statik hash'in büyüyememesi üzerinden anlatıldı; dinamik hash yöntemlerinin adları anıldı ve hash'in aralık sorgularında kullanılamadığı vurgulandı. Son olarak çok koşullu sorgularda tek indeks, işaretçi kesişimi ve bileşik indeks stratejileri, bileşik indekste nitelik sırasının önemi ve SQL'de `create index` ile `drop index` komutları işlendi. Hoca join algoritmalarının ve sorgu işlemenin ayrı bir konu olduğunu belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
