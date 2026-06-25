# Veritabanı Yönetimi Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.

## Genel Bilgiler

- **Ders Adı:** Veritabanı Yönetimi
- **Dersi Veren Akademisyen:** Dr. M. Utku Kalay
- **Dönem:** Güz
- **Akademik Yıl:** 2020-2021

## Müfredat ve Belge Dizini Tablosu

| Ders No | Ders İçeriği / Konu Başlığı | Markdown Kaynak Notu | PDF |
|---------|----------------------------|----------------------|-----|
| Ders 1 | Veritabanı Temel Kavramları, VTYS, Dosya Tipleri, Transaction | [ders_1_ozet.md](altyazi_ozetleri/ders_1_ozet.md) | [ders_1_ozet.pdf](ders_1_ozet.pdf) |
| Ders 2 | VTYS Kullanıcıları, DDL/DML, Üç Şema Mimarisi, Veri Bağımsızlığı, ER Modeline Giriş | [ders_2_ozet.md](altyazi_ozetleri/ders_2_ozet.md) | [ders_2_ozet.pdf](ders_2_ozet.pdf) |
| Ders 3 | ER Diyagramı Tasarımı, Varlık/Bağıntı Kavramları, Cardinality, Participation | [ders_3_ozet.md](altyazi_ozetleri/ders_3_ozet.md) | [ders_3_ozet.pdf](ders_3_ozet.pdf) |
| Ders 4 | ER Örnekleri, İlişkisel modele dönüşüm | [ders_4_ozet.md](altyazi_ozetleri/ders_4_ozet.md) | [ders_4_ozet.pdf](ders_4_ozet.pdf) |
| Ders 4 Lab | SQL'e Giriş, Temel Sorgular | [ders_4_lab_ozet.md](altyazi_ozetleri/ders_4_lab_ozet.md) | [ders_4_lab_ozet.pdf](ders_4_lab_ozet.pdf) |
| Ders 5 | İlişkisel Model, İlişkisel Cebir, SQL'e Dönüşüm Kuralları | [ders_5_ozet.md](altyazi_ozetleri/ders_5_ozet.md) | [ders_5_ozet.pdf](ders_5_ozet.pdf) |
| Ders 5 Lab | SQL Sorguları, Tek Tablo Üzerinde İşlemler | [ders_5_lab_ozet.md](altyazi_ozetleri/ders_5_lab_ozet.md) | [ders_5_lab_ozet.pdf](ders_5_lab_ozet.pdf) |
| Ders 6 | İlişkisel Cebir Örnekleri, SQL'e Giriş | [ders_6_ozet.md](altyazi_ozetleri/ders_6_ozet.md) | [ders_6_ozet.pdf](ders_6_ozet.pdf) |
| Ders 6 Lab | Çok Tablolu Sorgular, JOIN İşlemleri | [ders_6_lab_ozet.md](altyazi_ozetleri/ders_6_lab_ozet.md) | [ders_6_lab_ozet.pdf](ders_6_lab_ozet.pdf) |
| Ders 7 | İlişkisel Cebir Sonları, SQL Sorguları, JOIN Tipleri | [ders_7_ozet.md](altyazi_ozetleri/ders_7_ozet.md) | [ders_7_ozet.pdf](ders_7_ozet.pdf) |
| Ders 7 Lab | SQL JOIN, GROUP BY, HAVING | [ders_7_lab_ozet.md](altyazi_ozetleri/ders_7_lab_ozet.md) | [ders_7_lab_ozet.pdf](ders_7_lab_ozet.pdf) |
| Ders 8 | Veri Bütünlüğü, Assertion, Trigger | [ders_8_ozet.md](altyazi_ozetleri/ders_8_ozet.md) | [ders_8_ozet.pdf](ders_8_ozet.pdf) |
| Ders 8 Lab | PostgreSQL ile Uygulama | [ders_8_lab_ozet.md](altyazi_ozetleri/ders_8_lab_ozet.md) | [ders_8_lab_ozet.pdf](ders_8_lab_ozet.pdf) |
| Ders 9 | Veritabanı Güvenliği, RBAC, Gömülü SQL | [ders_9_ozet.md](altyazi_ozetleri/ders_9_ozet.md) | [ders_9_ozet.pdf](ders_9_ozet.pdf) |
| Ders 9 Lab | Güvenlik Uygulamaları | [ders_9_lab_ozet.md](altyazi_ozetleri/ders_9_lab_ozet.md) | [ders_9_lab_ozet.pdf](ders_9_lab_ozet.pdf) |
| Ders 10 | JDBC/ODBC, Gömülü SQL, İndeks Yapıları (B-tree, Hash) | [ders_10_ozet.md](altyazi_ozetleri/ders_10_ozet.md) | [ders_10_ozet.pdf](ders_10_ozet.pdf) |
| Ders 10 Lab | JDBC ile Veritabanı Uygulaması | [ders_10_lab_ozet.md](altyazi_ozetleri/ders_10_lab_ozet.md) | [ders_10_lab_ozet.pdf](ders_10_lab_ozet.pdf) |
| Ders 11 | XQuery, XML Veritabanları | [ders_11_ozet.md](altyazi_ozetleri/ders_11_ozet.md) | [ders_11_ozet.pdf](ders_11_ozet.pdf) |
| Ders 14 | İndeks Yapısı, Dosya Düzenleme, Ders Özeti | [ders_14_ozet.md](altyazi_ozetleri/ders_14_ozet.md) | [ders_14_ozet.pdf](ders_14_ozet.pdf) |

## Detaylı Özetler

### Ders 1: Veritabanı Temel Kavramları, VTYS, Dosya Tipleri, Transaction

**Genel Konular:**
- **Veri ve Veritabanı Temel Kavramları**
  - Veri: Anlamı olan, kaydedilen gerçekler (isim, adres, telefon vb.). Bilgisayar içinde binary olarak saklanır, kodlanmış bit dizileri anlamlı bilgiler oluşturur.
  - Veritabanı: Birden çok uygulama tarafından kullanılan, gereksiz yinelemelerden arınmış, düzenli saklanan, birbiriyle ilişkili ve uyumlu, sürekli fakat statik olmayan, belirli bir amaç için bir araya getirilmiş veri topluluğu.
- **Veritabanı Tanımının 6 Temel Maddesi**
  - Birden çok uygulama tarafından kullanılması, birçok kişiye bakması, gereksiz yinelemelerden arınması, düzenli saklanması, sürekli fakat statik olmaması, belirli bir amaç için bir araya getirilmesi.
- **Veritabanı Yönetim Sistemi (DBMS / VTYS)**
  - Veritabanıyla ilgili her türlü işletimsel gereksinimi karşılamak için kullanılan sistem seviyesinde karmaşık, merkezi yazılım sistemi.
- **VTYS'nin Sağladığı Olanaklar**
  - Tanımlama, gerçekleme, kullanım/paylaşım, kontrollü tekrar, verimli erişim, çok kullanıcılı hizmet, eşzamanlılık, veri kurtarma ve yedekleme, iş kısıtlamaları, güvenlik.
- **Veritabanı Sistem Dosyaları (4 Temel Dosya Tipi)**
  - Veri dosyaları, indeks dosyaları, log dosyaları, veri sözlüğü (metadata).
- **Transaction (Hareket / İşlem)**
  - ACID kriterleri: Atomiklik, Consistency, Isolation, Durability.

**Hocanın Özellikle Vurguladığı Kısımlar:**
- Veri tekrarının dengelenmesi: Gereksiz yineleme olmamalı ama kontrollü yineleme (yabancı anahtar, indeks) sistemin yürümesi için gerekli.
- Sıralama ve erişim hızı farkı: 10 milyon kayda sırayla bakmak vs. binary search ile 16-17 adımda erişim.
- Metadata (üst veri) sorgu optimizasyonu için kritik.

**Detaylı Açıklamalar:**
Veritabanı yönetim sistemleri, "veri sakla ve getir" işinin arkasında müthiş bir düzenleme ve optimizasyon gerektirir. Google'ın Bigtable'ında terabyte'larca veri içinde bir kelime arandığında 45 milisaniyede sonuç gelmesi, arada cache'ler, tampon bölgeler, indeks yapıları ve çok gelişmiş algoritmalar sayesindedir. Veri tekrarının dengelenmesi önemli bir tasarım sorunudur — bir öğrencinin bilgilerinin birden çok yerde saklanması düşünüldüğünde, adres değişikliği durumunda tüm kopyaların güncellenmesi gerekir ve güncelleme sürecinde sistem tutarsız kalır.

---

### Ders 2: VTYS Kullanıcıları, DDL/DML, Üç Şema Mimarisi, Veri Bağımsızlığı, ER Modeline Giriş

**Genel Konular:**
- **VTYS Dosya Yapısı ve Kullanıcıları**
  - DBA, Tasarımcı, Sistem Analisti, Uygulama Yazılımcısı, Son Kullanıcı, Sistem Yazılımcısı rolleri.
- **DDL ve DML**
  - Data Definition Language: CREATE TABLE, DROP TABLE, CREATE SCHEMA.
  - Data Manipulation Language: SELECT, INSERT, UPDATE, DELETE.
- **Üç Şema Mimarisi**
  - Internal (fiziksel), Conceptual (kavramsal), External (dış) şema.
- **Veri Bağımsızlığı**
  - Physical Data Independence ve Logical Data Independence.
- **ER Modeline Giriş**
  - Varlık (Entity), Nitelik (Attribute), Bağıntı (Relationship) kavramları.
  - ER notasyonu: Dörtgen (varlık), yuvarlak (nitelik), eşkenar dörtgen (bağıntı).

**Hocanın Özellikle Vurguladığı Kısımlar:**
- Üç şema mimarisi ve veri bağımsızlığı kavramları VTYS'nin temelini oluşturur.
- ER diyagramı, veritabanı tasarımının ilk ve en kritik adımıdır.

**Detaylı Açıklamalar:**
VTYS kullanıcıları farklı rollerde sisteme erişir. DBA tüm sistemi yönetirken, son kullanıcı görsel arayüz veya tarayıcı üzerinden sorgularını gönderir. Üç şema mimarisi sayesinde verinin fiziksel saklanma biçimi ile mantıksal yapısı ve kullanıcı görüntüleri birbirinden bağımsız hale gelir. Bu bağımsızlık, sistemin esnekliğini ve bakım kolaylığını sağlar.

---

### Ders 3: ER Diyagramı Tasarımı, Varlık/Bağıntı Kavramları, Cardinality, Participation

**Genel Konular:**
- **Veritabanı Tasarım Aşamaları**
  - Gereksinim toplama → Kavramsal tasarım → Mantıksal tasarım → Fiziksel tasarım.
- **Varlık Seti (Entity Set) Kavramı**
  - Benzer varlıkların oluşturduğu küme.
- **Bağıntı (Relationship) Kavramı**
  - İki veya daha çok varlık arasındaki olayı tanımlayan kavram.
- **Cardinality (Eleman Sayısı) Oranları**
  - 1:1, 1:N, N:M bağıntı türleri.
- **Katılım (Participation) Kısıtlaması**
  - Tam (total) ve kısmi (partial) katılım.
- **Nitelik Türleri ve Notasyonları**
  - Basit, kompozit, çok değerli, türetilmiş nitelikler.

**Hocanın Özellikle Vurguladığı Kısımlar:**
- Cardinality ve katılım kısıtlamaları yanlış modellenirse veritabanı ciddi sorunlara yol açar.
- ER diyagramında her varlık ve bağıntı dikkatle tanımlanmalıdır.

**Detaylı Açıklamalar:**
ER tasarımı, gerçek dünyadaki veri yapısının soyut bir temsili olarak kullanılır. Varlık kümesi benzer nesnelerin topluluğudur (örn. tüm öğrenciler). Bağıntı ise farklı varlık kümeleri arasındaki ilişkileri tanımlar (örn. öğrenci ders alır). Cardinality, bir varlıktan diğerine kaç tane ilişkinin olabileceğini belirler. Katılım ise bir varlığın bir bağıntıda yer alıp almadığını zorunlu kılıp kılmadığını belirtir.

---

### Ders 4: ER Örnekleri, İlişkisel Modele Dönüşüm

**Genel Konular:**
- **ER Diyagramı Örnekleri**
  - Gerçek dünya problemlerinden ER modelleri oluşturma.
- **İlişkisel Modele Dönüşüm Kuralları**
  - ER diyagramından tablo yapısına geçiş.
  - Varlıklardan tablolar, bağıntılardan ilişkisel tablolar türetme.
- **İlişkisel Model Tanımları**
  - Tablo (relation), satır (tuple), sütun (attribute), birincil anahtar (primary key).

**Hocanın Özellikle Vurguladığı Kısımlar:**
- ER'den ilişkisel modele dönüşüm kuralları sınavlarda sıkça sorulur.
- N:M bağıntılarında ara tablo oluşturulması zorunludur.

**Detaylı Açıklamalar:**
ER diyagramından ilişkisel modele geçiş, veritabanı tasarımının en önemli adımlarından biridir. Her varlık kümesi bir tabloya dönüşür. Bağıntılar ise duruma göre farklı biçimlerde tablolara dönüştürülür: 1:1 ve 1:N bağıntıları doğrudan yabancı anahtar ile, N:M bağıntıları ise ara tablolar ile temsil edilir.

---

### Ders 5: İlişkisel Model, İlişkisel Cebir, SQL'e Dönüşüm Kuralları

**Genel Konular:**
- **İlişkisel Model Temelleri**
  - Tablo, nitelik, tuple, birincil anahtar, yabancı anahtar kavramları.
- **İlişkisel Cebir**
  - Seçme (σ),投影 (π), birleştirme (∪), fark (−), çarpma (×), birleştirme (⋈) işlemleri.
- **SQL'e Dönüşüm Kuralları**
  - İlişkisel cebir ifadelerinin SQL sorgularına dönüştürülmesi.

**Hocanın Özellikle Vurguladığı Kısımlar:**
- İlişkisel cebir SQL'in temelini oluşturur; cebirsel işlem bilgisi sorgu yazma hızını artırır.
- SQL'de FROM, WHERE, SELECT cümlelerinin ilişkisel cebirdeki karşılıklarını bilmek sınavda avantaj sağlar.

**Detaylı Açıklamalar:**
İlişkisel cebir, veritabanı sorgularının formal bir dille ifade edilmesini sağlar. Seçme işlemi (σ) belirli koşulları sağlayan satırları filtreler,投影 (π) ise belirli sütunları seçer. Birleştirme iki tabloyu dikey olarak birleştirir. İlişkisel cebirdeki her bir işlem SQL'de bir karşılığa sahiptir ve bu dönüşümleri bilmek sorguları daha verimli yazmayı sağlar.

---

### Ders 6: İlişkisel Cebir Örnekleri, SQL'e Giriş

**Genel Konular:**
- **İlişkisel Cebir Uygulama Örnekleri**
  - Gerçek veritabanı problemleri üzerinde cebirsel çözümler.
- **SQL'e Giriş**
  - SELECT, FROM, WHERE cümlelerinin kullanımı.
  - Temel sorgu kalıpları.

**Hocanın Özellikle Vurguladığı Kısımlar:**
- SQL'de sorgulama düşünce yapısının gelişmesi dersin en önemli çıktısıdır.
- Sorguları yazarken önce ilişkisel cebirde düşünüp sonra SQL'e çevirmek faydalıdır.

**Detaylı Açıklamalar:**
İlişkisel cebir örnekleri ile pekiştirilen bilgiler ardından SQL'e geçilir. SQL, veritabanı ile iletişimin standart dilidir. SELECT cümleciği ile veriler çekilir, FROM ile tablo belirtilir, WHERE ile filtreleme yapılır. Bu temel yapılar ile veritabanından istenen bilgilere erişilir.

---

### Ders 7: İlişkisel Cebir Sonları, SQL Sorguları, JOIN Tipleri

**Genel Konular:**
- **JOIN İşlemleri**
  - Inner Join, Left Outer Join, Right Outer Join, Full Outer Join.
  - Semijoin ve Antijoin kavramları.
- **SQL Sorgularında İleri Düzey**
  - GROUP BY, HAVING, ORDER BY cümleleri.
  - Aggregate fonksiyonlar: COUNT, SUM, AVG, MAX, MIN.

**Hocanın Özellikle Vurguladığı Kısımlar:**
- JOIN türleri arasındaki farkları bilmek sınavda hayati önem taşır.
- OUTER JOIN'de NULL değerlerin nasıl oluştuğunu anlamak gerekir.

**Detaylı Açıklamalar:**
JOIN işlemleri iki veya daha fazla tabloyu belirli koşullar altında birleştirir. Inner Join sadece eşleşen satırları döndürürken, Outer Join eşleşmeyen satırları da NULL değerleriyle birlikte dahil eder. GROUP BY ile veriler gruplandırılır, HAVING ile gruplama sonrası filtreleme yapılır. Aggregate fonksiyonlar grup düzeyinde hesaplamalar yapar.

---

### Ders 8: Veri Bütünlüğü, Assertion, Trigger

**Genel Konular:**
- **Veri Bütünlüğü (Data Integrity)**
  - Alan bütünlüğü, tablo bütünlüğü, referans bütünlüğü.
- **Assertion (Sağlama İfadesi)**
  - Genel kısıtlamalar için SQL ifadeleri.
  - Assertion örnekleri ve kullanımları.
- **Trigger'lar (Tetikleyiciler)**
  - Otomatik tetiklenen depolanmış prosedürler.
  - BEFORE, AFTER, INSTEAD OF tetikleme zamanları.
  - Row-level ve statement-level çalışma düzeyleri.

**Hocanın Özellikle Vurguladığı Kısımlar:**
- Assertion'lar pratikte pek kullanılmaz ama kavram olarak bilinmelidir.
- Trigger'lar veri bütünlüğünü programlama tarafında sağlamak için güçlü bir araçtır.

**Detaylı Açıklamalar:**
Veri bütünlüğü, veritabanındaki verilerin doğru ve tutarlı olmasını sağlar. Alan bütünlüğü her sütundaki verinin tanımlı değerler içerisinde olmasını, referans bütünlüğü ise yabancı anahtarların geçerli birincil anahtarları göstermesini保证 eder. Assertion'lar SQL düzeyinde tanımlanan genel kısıtlamalardır. Trigger'lar ise belirli bir olay (INSERT, UPDATE, DELETE) gerçekleştiğinde otomatik olarak çalışan prosedürlerdir ve veri bütünlüğünü programlama düzeyinde sağlamak için kullanılır.

---

### Ders 9: Veritabanı Güvenliği, RBAC, Gömülü SQL

**Genel Konular:**
- **Veritabanı Güvenliği**
  - GRANT ve REVOKE komutları.
  - WITH GRANT OPTION ile yetki aktarımı.
  - CASCADE ile zincirleme yetki iptali.
- **Rol Tabanlı Erişim Kontrolü (RBAC)**
  - Rollerin tanımlanması ve kullanıcıya atanması.
  - WITH ADMIN OPTION ile rol aktarımı.
- **Güvenlik Seviyeleri**
  - S (Secret), C (Confidential), TS (Top Secret), TC (Top Confidential).
- **Gömülü SQL (Embedded SQL)**
  - Uygulama dillerinin içinde SQL kullanımı.
  - Shared variables, SQLCA, cursor mekanizması.

**Hocanın Özellikle Vurguladığı Kısımlar:**
- GRANT ve REVOKE arasındaki farkları, özellikle CASCADE davranışını iyi kavramak gerekir.
- WITH ADMIN OPTION ile WITH GRANT OPTION arasındaki davranış farkı (REVOKE cascade göstermez).

**Detaylı Açıklamalar:**
Veritabanı güvenliği, yetkisiz erişimi önlemek için çok katmanlı bir yapıya sahiptir. GRANT komutu ile kullanıcılar tablo düzeyinde okuma/yazma yetkisi alır, REVOKE ile bu yetkiler geri alınır. RBAC sisteminde roller tanımlanır ve kullanıcılar bu rollere atanır, böylece yönetimsel kolaylık sağlanır. Gömülü SQL ise Java, C gibi dillerin içinde SQL sorgularının çalıştırılmasını sağlayan bir mekanizmadır.

---

### Ders 10: JDBC/ODBC, Gömülü SQL, İndeks Yapıları (B-tree, Hash)

**Genel Konular:**
- **JDBC ve ODBC API'leri**
  - Driver, Connection, Statement, ResultSet nesneleri.
  - Veritabanı bağlantı döngüsü.
- **İndeks Yapıları**
  - B-tree (k-yollu arama ağaçları): Sıralama esaslı, aralık sorguları için uygun.
  - Hash organizasyonları: Eşitlik esaslı, O(1) erişim.
- **XML ve İlişkisel Model Karşılaştırması**
  - 1:N ve N:M ilişkilerin XML'de temsili.
  - SSDM (Semantic Structure Discovery Model) diyagramları.

**Hocanın Özellikle Vurguladığı Kısımlar:**
- B-tree ve Hash arasındaki temel farkları bilmek sınavda sıkça sorulur.
- JDBC bağlantı döngüsünü adım adım bilmek uygulama geliştirme için gereklidir.

**Detaylı Açıklamalar:**
JDBC, Java uygulamalarından PostgreSQL gibi veritabanlarına erişim sağlayan bir API'dir. Bağlantı süreci: Driver yüklenir → Connection açılır → Statement oluşturulur → Sorgu çalıştırılır → ResultSet işlenir → Bağlantı kapatılır. İndeks yapıları veritabanı performansını doğrudan etkiler. B-tree indeksleri sıralı veri üzerinde hızlı arama sağlarken, Hash indeksleri eşitlik sorgularında O(1) erişim sunar. Hangi indeks türünün seçileceği sorgu paternine bağlıdır.

---

### Ders 11: XQuery, XML Veritabanları

**Genel Konular:**
- **XQuery Nedir?**
  - XML dosyaları üzerinde sorgulama dili.
  - SQL'in XML dünyasındaki karşılığı.
- **XML Dosya Yapısı**
  - Etiket (tag), öğe (element), nitelik (attribute), kök öğe (root element).
- **XQuery Sorgu Kalıpları**
  - FLWR (For, Let, Where, Return) ifadeleri.
  - XPath ile yol tabanlı erişim.

**Hocanın Özellikle Vurguladığı Kısımlar:**
- XQuery bir bilgi olsun; ileride gerekirse kullanılabilir.
- XML veritabanları ilişkisel modelin bir alternatifi olarak görülmemeli, tamamlayıcı bir araç olarak düşünülmelidir.

**Detaylı Açıklamalar:**
XQuery, XML verileri üzerinde sorgulama yapmak için geliştirilmiş bir dildir. SQL'in tablo tabanlı yapısının aksine, XQuery hiyerarşik (ağaç yapısında) veriler üzerinde çalışır. FLWR ifadeleri ile XML belgeleri taranır, filtrelenir ve istenen форматda çıktı üretilir. XML veritabanları, yapılandırılmamış veya yarı yapılandırılmış verilerin yönetiminde ilişkisel modele alternatif olarak kullanılır.

---

### Ders 14: İndeks Yapısı, Dosya Düzenleme, Ders Özeti

**Genel Konular:**
- **İndeks Yapısı Detayları**
  - B-tree derinliği, yaprak düğümler, aralık sorguları.
  - Hash indekslerde çökme (collision) yönetimi.
- **Dosya Düzenleme ve Fiziksel Tasarım**
  - Dosya organizasyonu türleri: Sıralı, hash, çok seviyeli indeks.
  - Disk sayfa yönetimi ve tampon bölgeler.
- **Ders Genel Özeti**
  - Dönem boyunca işlenen konuların derlemesi.

**Hocanın Özellikle Vurguladığı Kısımlar:**
- İndeks seçimi sorgu performansını binlerce kat etkileyebilir.
- Dosya düzenleme dersinin detayları bu derste özetlenmiştir.

**Detaylı Açıklamalar:**
Dersin son bölümünde indeks yapılarının detaylarına inilmiştir. B-tree indeksleri büyük veri setlerinde verimli arama sağlar; yaprak düğümler sıralı veri tutar ve aralık sorguları bu yapı üzerinde çok hızlı çalışır. Hash indeksler ise nokta sorguları için idealdir ancak aralık sorgularında başarısızdır. Dosya düzenleme, verinin fiziksel olarak disk üzerinde nasıl organize edileceğini belirler ve bu kararlar veritabanı performansını doğrudan etkiler.

---

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
