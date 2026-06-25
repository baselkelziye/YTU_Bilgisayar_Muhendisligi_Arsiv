# Ders 10 Çalışma Özeti

## Genel Konular

- Gömülü SQL (Embedded SQL)
  - Uygulama programları ile veritabanı arasında köprü görevi görür
  - Ana bilgisayar değişkenleri (host variables): Uygulama programı ile veritabanı arasındaki ortak değişkenlerdir
  - Uygulama programı kendi dilinde yazılır (C, Java, Python vb.), veritabanı ise SQL ile sorgulanır
  - Ana bilgisayar değişkenleri, uygulama programında tanımlanır ve SQL cümlelerinde parametre olarak kullanılır
  - İki yönlü veri aktarımı sağlar: uygulamadan veritabanına (input) ve veritabanından uygulamaya (output)
  - Connect ifadesi ile veritabanı bağlantısı kurulur, yetkilendirme (authorization) yapılır
  - Bağlantı kapatma işlemleri Disconnect ile gerçekleştirilir

- JDBC/ODBC API Mimarisi
  - Veritabanı sürücüleri (drivers): Platforma özgü sürücüler kullanılır
  - Bağlantı nesnesi (connection object): Veritabanı bağlantısını temsil eder
  - İfade nesnesi (statement object): SQL sorgularını çalıştırmak için kullanılır
  - Sonuç kümesi nesnesi (resultset object): Sorgu sonuçlarını tutar
  - Her veritabanı için farklı sürücü gerekir (MySQL, Oracle, SQL Server vb.)
  - Platform bağımsızlık sağlamak için ODBC/JDBC katmanları kullanılır

- B-tree ve Hash İndeksleme
  - B-tree ve hash yapıları endeksleme (indexing) için her yerde kullanılır
  - Veritabanı performansı için temel yapılardan biridir
  - B-tree: Dengeli ağaç yapısı, arama, ekleme ve silme işlemlerinde高效
  - Hash: Doğrudan erişim (direct access) için kullanılır, belirli bir anahtar ile hızla ulaşım sağlar

- XML ve İlişkisel Model Karşılaştırması
  - XML, hiyerarşik (nested) bir veri yapısına sahiptir
  - İlişkisel model düz (flat) tablolar üzerine kuruludur
  - XML'de 1:N (bir-çok) ilişkileri natural olarak ifade edilir (iç içe elemanlar)
  - İlişkisel modelde 1:N ilişkileri foreign key ile kurulur
  - N:M (çok-çok) ilişkileri her iki modelde de farklı şekilde ele alınır
  - XML'de tekrarlayan elemanlar (örneğin yazar, kitap) alt eleman olarak nested edilir
  - İlişkisel modelde bu tür ilişkiler ayrı tablolar ve join'ler ile çözülür

- SSDM (Şema Şekilleri) Diyagramları
  - İlişkisel modellerin görsel temsili için kullanılır
  - Tablolar ve aralarındaki ilişkileri gösterir
  - XML yapısını ilişkisel modele dönüştürürken referans olarak kullanılır
  - Örnek: Takım-oyuncu-taraftan renkleri ilişkisi üzerinden modelleme

## Hocanın Özellikle Vurguladığı Kısımlar

- Gömülü SQL'de ana bilgisayar değişkenlerinin doğru tanımlanması kritik önem taşır
- Bağlantı kurulumunda sürücü seçimi ve yetkilendirme adımları atlanmamalıdır
- B-tree ve hash indeksleme yapıları veritabanı performansının temelini oluşturur
- XML'de 1:N ilişkileri doğal olarak ifade edilirken, ilişkisel modelde bunun için foreign key ve join gerekir
- SSDM diyagramları, veri modelleme sürecinde görsel destek sağlar
- Platform bağımsızlık için ODBC/JDBC gibi soyutlama katmanlarının kullanılması gerekir

## Kısa Tekrar Notları

- Gömülü SQL = Uygulama programı ile veritabanı arasındaki köprü
- Ana bilgisayar değişkenleri = Uygulama ve veritabanı arasındaki ortak değişkenler
- Connect = Veritabanı bağlantısı kurma
- Disconnect = Bağlantıyı kapatma
- Sürücü (driver) = Platforma özgü veritabanı erişim katmanı
- Bağlantı nesnesi = Veritabanı bağlantısını temsil eder
- İfade nesnesi = SQL sorgularını çalıştırır
- Sonuç kümesi = Sorgu sonuçlarını tutar
- B-tree = Dengeli ağaç yapısı, endeksleme için kullanılır
- Hash = Doğrudan erişim yapısı, hızlı arama sağlar
- XML = Hiyerarşik veri yapısı (iç içe elemanlar)
- İlişkisel model = Düz tablolar ve foreign key'ler
- 1:N ilişkisi = XML'de doğal, ilişkisel modelde foreign key ile
- N:M ilişkisi = Her iki modelde de ek tablo veya junction table gerekir
- SSDM = İlişkisel modellerin görsel temsili

## Detaylı Açıklamalar

- **Gömülü SQL ve Ana Bilgisayar Değişkenleri:** Gömülü SQL, uygulama programları ile veritabanı arasında veri değişimini sağlamak için kullanılır. Ana bilgisayar değişkenleri (host variables), bu sürecin temel yapı taşıdır. Uygulama programında tanımlanan bu değişkenler, SQL cümlelerinde parametre olarak yer alır. İki yönlü çalışır: uygulamadan veritabanına veri göndermek (input parametreleri) ve veritabanından uygulamaya veri çekmek (output parametreleri). Bağlantı Connect, yetkilendirme ve Disconnect adımları ile yönetilir.

- **JDBC/ODBC API Nesne Modeli:** Veritabanı erişimi için dört temel nesne kullanılır: (1) Sürücü (driver) — platforma özgü iletişim katmanı, (2) Bağlantı nesnesi (connection) — veritabanı bağlantısını temsil eder, (3) İfade nesnesi (statement) — SQL sorgularını çalıştırmak için kullanılır, (4) Sonuç kümesi (resultset) — sorgu sonuçlarını depolar. Her veritabanı için farklı sürücü gerekir; ODBC/JDBC katmanları platform bağımsızlık sağlar.

- **B-tree ve Hash İndeksleme:** B-tree (denge ikili arama ağacı) ve hash (dağılım tablosu) yapıları, veritabanı indeksleme sistemlerinin temelini oluşturur. B-tree, arama, ekleme ve silme işlemlerinde dengeli ve高效 bir yapı sunar. Hash ise belirli bir anahtar ile doğrudan erişim sağlayarak arama süresini önemli ölçüde azaltır. Her iki yapı da veritabanı performansı için kritik önem taşır.

- **XML ve İlişkisel Model Farkları:** XML hiyerarşik (nested) bir yapıya sahipken, ilişkisel model düz tablolar üzerine kuruludur. XML'de 1:N (bir-çok) ilişkileri doğal olarak ifade edilir — örneğin bir yazarın birden fazla kitabı XML'de iç içe eleman olarak kolayca temsil edilir. İlişkisel modelde ise bunun için ayrı bir tablo ve foreign key ile join gereklidir. N:M (çok-çok) ilişkileri her iki modelde de ek yapılar gerektirir.

- **SSDM Diyagramları:** Şema Şekilleri diyagramları (SSDM), ilişkisel veri modellerinin görsel temsili için kullanılır. Tablolar, nitelikler ve aralarındaki ilişkileri gösterir. Bu diyagramlar, XML yapısını ilişkisel modele dönüştürürken referans olarak kullanılır. Örneğin, takım-oyuncu-taraftar ve renkler ilişkisi SSDM diyagramları ile modellenebilir.

- **Platform Bağımsızlık ve Sürücü Seçimi:** ODBC (Open Database Connectivity) ve JDBC (Java Database Connectivity) katmanları, farklı veritabanları arasında platform bağımsızlık sağlamak için kullanılır. Her veritabanı için özel bir sürücü gerekir; bu sürücüler, uygulama programı ile veritabanı arasındaki iletişimi yönetir. Doğru sürücü seçimi, performans ve uyumluluk açısından önemlidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.