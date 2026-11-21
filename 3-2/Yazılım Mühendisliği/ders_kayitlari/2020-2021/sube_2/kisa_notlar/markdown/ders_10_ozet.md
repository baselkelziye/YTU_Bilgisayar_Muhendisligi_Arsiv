# Ders 10 Çalışma Özeti

## Genel Konular

- Yazılım Proje Yönetimi: Risk Yönetimi (*Risk Management*)
  - **Risk** kavramının tanımı (ortaya çıkması belirli bir olasılık dâhilinde olup kesin olmayan, ancak gerçekleştiğinde istenmeyen sonuç ve kayıplar doğuran olumsuz durumlar) ve riskle başa çıkmada iki temel yaklaşım: **Reaktif (Sonradan — yangın çıktıktan sonra itfaiyenin söndürmesi)** ve **Proaktif (Önceden — elektrik tesisatının standartlara uygun planlanarak yangının çıkmadan önlenmesi)**.
  - Yazılım geliştirme sürecindeki üç temel risk kategorisi (ekrandan, 00:10:00):
    1. **Proje Riskleri:** Proje planını (zamanlama, maliyet ve kapsam/işlev üçgenini) tehdit eden riskler (*bütçe riskleri, zaman riskleri, kilit personelin ayrılması/hastalanması gibi personel riskleri*) (ekrandan, 00:10:00).
    2. **Teknik Riskler:** Üretilen yazılımın kalitesini ve zamanında bitirilmesini etkileyen; gerçekleştiğinde yazılımı gerçeklemeyi zorlaştıran veya imkânsızlaştıran *çözümleme, tasarım, gerçekleme ve bakım* aşaması riskleri (ör. iyi belgelenmemiş, hatalar barındıran veya topluluk desteği kesilebilecek **"son teknoloji" (*cutting-edge*)** çatıları [*frameworks*] kullanma; planlanandan düşük kod yeniden kullanımı) (ekrandan, 00:10:00).
    3. **İşletme (İş / Ticari) Riskleri:** Ürünün hitap edeceği pazarla (*pazar riskleri* — ürüne talep olup olmaması; ör. tıraş bıçağı tercih edilen pazarda tıraş makinesi üretmek) ve satış/pazarlama ekibinin ürünü nasıl satacağını bilip bilmemesiyle (*satış riskleri*) ilgili *MIS/MBA* kapsamındaki riskler (ekrandan, 00:10:00).
  - Proaktif risk yönetimi adımları: Farklı uzmanlıklardan geniş bir katılımla **Özet Risk Tablosu** (`Risk ID`, `Adı`, `Türü/Grubu`, `Etkisi`, `Olasılık`) oluşturma, **Etki–Olasılık (4 Kadranlı) Grafiği** üzerinde önceliklendirme ve izlenecek riskler için **Ayrıntılı Risk Bilgi Sayfası** (*Açıklama, İşaretler, Önlemler*) hazırlama (ekrandan, 00:27:30; ekrandan, 00:33:00).
- Yazılım Sınama Teknikleri (*Software Testing*) ve Doğrulama/Geçerleme Sınamaları
  - Sınamanın (*testing*) amacının yazılımdaki hataları keşfetmek, hata ayıklamanın (*debugging*) ise bulunan hataları düzeltmek olması; değişiklik maliyetinin yaşam döngüsü ilerledikçe üstel arttığı göz önüne alınarak gereksinim, çözümleme ve tasarım aşamalarında da **Biçimsel Teknik İnceleme (*Formal Technical Review — FTR*)** yoluyla sınama yapılması.
  - Sınama türlerinin iki farklı açıdan sınıflandırılması (ekrandan, 01:00:05):
    1. **Yaklaşım Tarzlarına Göre:** **Kara Kutu Sınaması (*Black-box testing*)** (iç işleyiş bilinmeden beklenen girdilere karşı beklenen çıktıların üretilip üretilmediğine bakılması) ve **Beyaz Kutu Sınaması (*White-box testing*)** (kaynak kodun iç işleyişi ve `if-else` dallanmaları bilinerek tüm denetim akışlarını kapsayacak sınamaların belirlenmesi) (ekrandan, 01:00:05).
    2. **Yürütülme Sıralarına Göre:** Yazılım ekibi tarafından yapılan **Doğrulama Sınamaları (*Verification tests*: 1. Birim sınamaları, 2. Tümleştirme sınamaları)** ve son kullanıcılar tarafından yapılan **Geçerleme Sınamaları (*Validation tests*: 3. Alfa sınaması, 4. Beta sınaması)** (ekrandan, 01:00:05).
  - **Birim Sınamaları (*Unit Testing*):** Nesneye yönelik programlamada bireysel sınıfların sınanması; kodlamadan önce (**TDD — *Test Driven Design***), kodlama sırasında veya kodlamanın ardından tasarlanabilmesi ve bağımlı olunan diğer sınıfların yerine **vekil/sahte kod (*stub, dummy, surrogate, proxy*)** kullanılması (ekrandan, 01:10:00).
- JUnit (3.x ve 4.x) Çatısı ile Birim Sınaması Uygulaması
  - **JUnit 3.x Mimarisi:** `junit.framework.TestCase` sınıfından kalıtım alma, `# setUp()` metodunu ezerek (*override*) her `testXXX()` metodu öncesinde test sahnesini yeniden kurma, `Assert` sınıfının statik metotlarını (`assertEquals`, `assertNotEquals`, `assertTrue`, `assertFalse`, `assertNull`, `assertNotNull`) kullanma ve `TestAll.suite()` statik metoduyla test sınıflarını tek bir *TestSuite* altında toplama (ekrandan, 01:16:30).
  - **JUnit 4.x Yenilikleri:** Geriye dönük uyumluluk korunarak **ek açıklama (*annotation*)** desteğinin (`@Before`, `@Test`) ve beklenen istisnaların sınanması desteğinin (`@Test(expected=SomeException.class)`) gelmesi (ekrandan, 01:23:30).
  - Martin Fowler'ın *Refactoring* kitabındaki **Video Kaset Kiralama (`Customer`, `Rental`, `Movie`)** örneği üzerinde JUnit birim testlerinin (`TestMovie`, `TestCustomer`, `TestAll`) Eclipse ortamında incelenmesi, kasıtlı hata (*bug*) eklenerek `Failure Trace` karşılaştırma çıktısının analizi ve **gerileme sınaması (*regression testing*)** (ekrandan, 01:31:40; ekrandan, 01:45:40; ekrandan, 01:58:30; ekrandan, 02:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Teknik Risk ile Proje Riskinin Kök Neden Üzerinden Ayırt Edilmesi
  - Bir teknik risk (örneğin yeni ve belgelemesi eksik bir *framework* kullanılması veya kod yeniden kullanım oranının düşük kalması) gerçekleştiğinde doğal bir yan etki olarak projenin bitiş tarihi sarkar; ancak buradaki **kök neden** kullanılan yazılım bileşeni veya teknik süreç olduğundan bu risk **proje riski değil, teknik risk** olarak sınıflandırılmalıdır (ekrandan, 00:10:00).
  - Geciken bir projede süreyi telafi etmek için sonradan ekibe yeni programcı eklemenin projeyi hızlandırmak yerine (yeni gelenlerin mevcut kodu öğrenme maliyeti yüzünden) daha da geciktireceği (*Brooks Yasası*) unutulmamalıdır.
- Etki–Olasılık Grafiğinde 4 Kadran Kararı ve Pilot Uygulama Önlemi
  - Risk değerlendirme grafiğinde **Olasılığı Yüksek – Etkisi Büyük** (sağ üst) kadrandaki riskler **mutlaka izlenmeli**, **Olasılığı Düşük – Etkisi Küçük** (sol alt) kadrandaki riskler ise izleme maliyetine değmeyeceği için **elenmelidir**. Diğer iki kadran (yüksek olasılık–küçük etki ve düşük olasılık–büyük etki) üst yönetimin stratejik kararıyla seçilir (ekrandan, 00:27:30).
  - Risk bilgi sayfasında yer alan *"Bir ya da iki firma ile pilot uygulama yapmak ve bu firmalara ürünü özel indirim ile satmak"* önlemi, hem yazılımın gereksinimden sınamaya kadar gerçek saha şartlarında doğrulanmasını hem de ilk referans müşterilerin kazanılmasını sağlayan çift taraflı (*kazan-kazan*) çok etkili bir endüstri uygulamasıdır (ekrandan, 00:33:00).
- Sınama Odaklı Tasarım (TDD) ve Vekil Sınıf (*Stub / Dummy*) Kullanımı
  - **TDD (*Test Driven Design*)** yaklaşımının temel savı şudur: Bir yazılım bileşenini kodlamadan önce birim sınamasını yazmaya çalıştığınızda o bileşeni yeterince ince kırılımda sınayamıyorsanız, tasarımınız problem alanının kırılım düzeyine inememiş (hatalı/kaba tasarlanmış) demektir; bu sayede tasarım hatası daha kod yazılmadan fark edilir (ekrandan, 01:10:00).
  - Bir sınıfın metodunu sınarken o metodun çağırdığı başka sınıfların kodlanmasını beklemek yerine, çağrılan metotların gövdesinde sabit bir değer (ör. `return true;` veya sabit bir sayı) döndüren basit **vekil/sahte sınıflar (*stub, dummy, surrogate, proxy*)** kullanılır; sınıfların birlikte çalışırken üreteceği yan etkileri bulmak ise birim sınamasının değil, **tümleştirme sınamasının (*integration testing*)** görevidir (ekrandan, 01:10:00).
- Video Kiralama Tasarımında Bağlaşımı (*Coupling*) Düşürme ve Geçici Değişkenlerden Kaçınma
  - `Customer.statement()` metodu makbuz basarken filmin adını öğrenmek için `aRental.getMovie().getTitle()` şeklinde `Movie` nesnesine doğrudan erişmez; bunun yerine `Rental` sınıfındaki `getMovieTitle()` aracılı metodu çağrılır. Böylece `Customer` ile `Movie` arasında doğrudan bir kullanma/bağlaşım oku oluşması engellenir ve **bağlaşım (*coupling*) düşürülür** (ekrandan, 01:31:40).

## Kısa Tekrar Notları

- **Reaktif vs. Proaktif Risk Yönetimi:** Reaktif yaklaşım risk gerçekleştiğinde zararı azaltmaya çalışır; proaktif yaklaşım ise risk daha ortaya çıkmadan önlem alır ve yazılım mühendisliğinde esas olan proaktif yaklaşımdır.
- **Özet Risk Tablosu Sütunları (ekrandan, 00:27:30):** `Risk ID`, `Adı`, `Türü/Grubu` (*Proje, Teknik, İş*), `Etkisi` (*Küçük, Orta, Büyük*), `Olasılık` (*Düşük, Orta, Yüksek*).
- **Risk Bilgi Sayfası Alanları (ekrandan, 00:33:00):** `Risk #ID: Adı`, `Olasılık`, `Etki`, `Türü`, `Açıklama`, `İşaretleri` (riskin gerçekleşmeye başladığını gösteren erken uyarı belirtileri), `Önlemler`.
- **Sınama Harcaması Oranı:** Endüstride proje çabasının/zamanının yaklaşık **`%10`**'unun sınama etkinliklerine ayrılması makul ve yeterli bir hedef kabul edilir.
- **Sınama Yürütülme Sırası (ekrandan, 01:00:05):** `1. Birim Sınamaları` $\rightarrow$ `2. Tümleştirme Sınamaları` *(Doğrulama / Verification — Yazılım ekibi)* $\rightarrow$ `3. Alfa Sınaması` $\rightarrow$ `4. Beta Sınaması` *(Geçerleme / Validation — Son kullanıcılar)*.
- **JUnit 3.x Kuralları (ekrandan, 01:16:30):** Test sınıfı `TestCase`'den türetilir, sınıf ve test metotlarının adı `Test` / `test` ile başlar, `# setUp()` her test metodundan önce otomatik çalışır, `TestAll.suite()` statik metodu test sınıflarını birleştirir.
- **JUnit 4.x Notasyonları (ekrandan, 01:23:30):** `@Before` (`setUp` yerine, her testten önce çalışır), `@Test` (metot adının `test` ile başlaması zorunluluğunu kaldırır), `@Test(expected=SomeException.class)` (beklenen istisna fırlatılırsa testi başarılı sayar).

## Detaylı Açıklamalar

### 1. Risk Yönetimi: Risk Türleri, Risk Tablosu ve Risk Bilgi Sayfası

Risk, gerçekleşmesi kesin olmayan (belirli bir olasılığa sahip olan) ancak gerçekleştiğinde projede istenmeyen kayıplar doğuran olumsuz durumdur. Yazılım projelerinde riskler üç ana grupta toplanır (ekrandan, 00:10:00):
1. **Proje Riskleri:** Proje planını tehdit eder; gerçekleşirse zamanlama ileri tarihlere sarkar ve maliyet artar (*Bütçe riskleri, zaman riskleri, personel riskleri vb.*).
2. **Teknik Riskler:** Üretilen yazılımın kalitesini ve zamanında bitirilmesini etkiler; gerçekleşirse yazılımı gerçekleme zorlaşır veya imkânsızlaşır. Çözümleme, tasarım, gerçekleme ve bakım aşamalarıyla ilgili risklerdir (örneğin *"son teknoloji"* ürünlerdeki *bug*'lar, eksik dokümantasyon veya teknolojinin terk edilmesi riski).
3. **İşletme Riskleri:** Pazar riskleri (*Ürüne talep olur mu? Ör. Tıraş bıçağı, tıraş makinesi*) ve satış riskleri (*Pazarlama ekibi ürünü nasıl satacağını biliyor mu?* — *MIS/MBA konuları*).

**Örnek Özet Risk Tablosu ve Etki–Olasılık Grafiği (Slayt 156) (ekrandan, 00:27:30):**

| Risk ID | Adı | Türü, Grubu | Etkisi | Olasılık |
| :--- | :--- | :--- | :--- | :--- |
| `01` | Organizasyon | Proje | Orta | Yüksek |
| `02` | Tahmin | Proje | Büyük | Düşük |
| `03` | Kullanışlılık | Teknik | Büyük | Düşük |
| `04` | Doğruluk | Teknik | Orta | Düşük |
| `05` | Güvenilirlik | Teknik | Büyük | Düşük |
| `06` | Personel | Proje | Küçük | Düşük |
| `07` | Araçlar | Teknik | Orta | Orta |
| `08` | Metot | Teknik | Orta | Orta |
| `09` | Pazarlama | İş | Büyük | Yüksek |

```text
  Etkisi
    ▲
    │   2          │        9
  Büyük     5      │
    │   3          │
    ├──────────────┼──────────────
    │     4   7  8 │
  Küçük            │        1
    │   6          │
    └──────────────┴──────────────► Olasılığı
       Düşük          Yüksek
```

- **Sonuç (ekrandan, 00:27:30):** Sol alt kadranda kalan **`4, 6, 7, 8.` risklerin izlenmesine gerek yoktur**; diğer riskler (`9` mutlaka; üst yönetimin stratejik kararıyla `2, 3, 5` ve `1`) için ayrıntılı risk bilgi sayfaları oluşturulmalıdır.

**Örnek Risk Bilgi Sayfası (Slayt 157) (ekrandan, 00:33:00):**
- **RİSK #09:** Pazarlama | **Olasılık:** Yüksek | **Etki:** Büyük | **Türü:** Ticari
- **Açıklama:** Firmamız sadece yazılım geliştiricilerden oluşan çekirdek kadroyla çalışmaktadır. Ortaya çıkaracağımız yazılımın piyasada çok fazla alternatifi vardır.
- **İşaretleri:**
  1. Müşteri adayları ile görüşmede dinleyicilerin ilgisizliği ve *"Biz zaten X yazılımını kullanıyoruz. Neden sizi seçelim?"* türü yorumları.
  2. Bakım aşamasının ilk altı aylık süresince ürünümüzün kendisini amorti etme oranının `%50`'nin altında kalması.
- **Önlemler:**
  1. Bir programcımıza MBA yaptırmak *(uzun vadeli — ~10 aylık önlem)*.
  2. Gereksinim mühendisliği aşamasında konu uzmanlığı odaklı danışmanlık hizmeti almak *(kısa vadeli)*.
  3. Bir ya da iki firma ile pilot uygulama yapmak ve bu firmalara ürünü özel indirim ile satmak *(kısa vadeli, kazan-kazan önlemi)*.

### 2. Yazılım Sınama Teknikleri ve JUnit Mimarisi (3.x ve 4.x)

**Sınama Türleri (Slayt 164) (ekrandan, 01:00:05):**
- **Yaklaşım Tarzlarına Göre:**
  - **Kara Kutu Sınaması (*Black-box testing*):** Sınanacak birimin iç işleyişi bilinmez; sadece birimin beklenen girdilere karşı beklenen çıktıları üretip üretmediğine bakılır.
  - **Beyaz Kutu Sınaması (*White-box testing*):** Sınanacak birimin iç işleyişi (kaynak kodu ve dallanmaları) bilinir ve yapılacak sınamalar buna göre belirlenir.
- **Yürütülme Sıralarına Göre:**
  - **Doğrulama Sınamaları (*Verification tests* — Yazılım ekibi tarafından yapılır):** 1) *Birim sınamaları*, 2) *Tümleştirme sınamaları*.
  - **Geçerleme Sınamaları (*Validation tests* — Son kullanıcılar tarafından yapılır):** 3) *Alfa sınaması*, 4) *Beta sınaması*.

**JUnit Sürüm 3.x ve 4.x Yapısı (Slayt 176–177) (ekrandan, 01:16:30; ekrandan, 01:23:30):**

```text
+-----------------------------------------------+     +---------------------------------------------+
| junit.framework                               |     | myPackage                                   |
|  +-----------------------------------------+  |     |  +----------------+       +---------------+ |
|  |                TestCase                 |  |     |  | TestAppClass1  | - - > |   AppClass1   | |
|  +-----------------------------------------+  |     |  +----------------+       +---------------+ |
|  | # setup()                               |<----------| + testXXX()    |<--+                     |
|  +-----------------------------------------+  |     |  +----------------+   |   +---------------+ |
|                       |                       |     |                       +---|    TestAll    | |
|                       v                       |     |  +----------------+   |   +---------------+ |
|  +-----------------------------------------+  |     |  | TestAppClass2  |<--+   | + suite():Test| |
|  |                 Assert                  |  |     |  +----------------+       +---------------+ |
|  +-----------------------------------------+  |     |  | + testYYY()    | - - > +---------------+ |
|  | + assertEquals(beklenen, sonuc: Object) |  |     |  +----------------+       |   AppClass2   | |
|  | + assertNotEquals(Object, Object)       |  |     |                           +---------------+ |
|  | + assertTrue(boolean)                   |  |     +---------------------------------------------+
|  | + assertFalse(boolean)                  |  |
|  | + assertNull(Object)                    |  |
|  | + assertNotNull(Object)                 |  |
|  +-----------------------------------------+  |
+-----------------------------------------------+
```

- **JUnit 4.x Notasyon ve İstisna Sınaması Örneği (ekrandan, 01:23:30):**
```java
@Before
public void setUp() { /* Preparations */ }

@Test
public void testSomething() { /* Do test */ }

@Test(expected=SomeException.class)
public void testTheException() throws Exception {
    doSomethingThatCreatesTheException();
}
```

### 3. Video Kaset Kiralama Uygulaması ve JUnit Birim Test Kodları

Martin Fowler'ın *Refactoring: Improving the Design of Existing Code* (1999) kitabından alınan örnekte; `Customer`, `Rental` (`- _daysRented: int`) ve `Movie` (`- _priceCode: int`; `REGULAR = 0`, `NEW_RELEASE = 1`, `CHILDRENS = 2`) sınıfları yer alır (ekrandan, 01:31:40; ekrandan, 01:40:00; ekrandan, 01:45:40):

- **`Movie.getCharge(int daysRented)` Fiyatlandırma Kuralları (ekrandan, 01:45:40):**
  - `Movie.REGULAR` (`0`): İlk 2 gün için sabit `2.0` birim; 2 günü aşan her gün için `(daysRented - 2) * 1.5` birim eklenir.
  - `Movie.NEW_RELEASE` (`1`): Kiralanan her gün için `daysRented * 3` birim (`3.0` birim/gün).
    - **Ders sonrası not:** Hoca kodu sözlü açıklarken `NEW_RELEASE` için *"kiraladığınız her gün için 2 lira yazılıyor"* demiştir (01:46:28); ancak ekrandaki `Movie.java` kodunda `result += daysRented * 3;` (günlük `3` birim) yazılıdır ve `TestCustomer.java` içindeki tüm beklenen test sonuçları da günlük `3.0` birim üzerinden hesaplanmıştır (ekrandan, 01:45:40; ekrandan, 01:58:30; ekrandan, 02:00:00).
  - `Movie.CHILDRENS` (`2`): İlk 3 gün için sabit `1.5` birim; 3 günü aşan her gün için `(daysRented - 3) * 1.5` birim eklenir.
  - `getBonus(int daysRented)`: Her kiralama `1` puan kazandırır; film `NEW_RELEASE` ise ve 1 günden fazla (`daysRented > 1`) kiralanmışsa `2` puan kazandırır.

- **`TestCustomer.java` İçindeki Test Senaryoları (ekrandan, 01:58:30; ekrandan, 02:00:00):**
  1. `testGetName()`: Müşteri adının (`"Yunus Emre Selçuk"` — Türkçe karakter desteği dahil) doğru döndürüldüğünü `assertEquals` ile sınar.
  2. `testStatementWhenEmpty()`: Hiç film kiralanmadığında borcun `0.0` ve puanın `0` olduğunu sınar (ekrandan, 01:58:30).
  3. `testStatementWithMoviesLongRent()`: *The Matrix* (`REGULAR`, 3 gün $\rightarrow 2 + 1\times 1{,}5 = 3{,}5$), *Monsters, Inc.* (`CHILDRENS`, 4 gün $\rightarrow 1{,}5 + 1\times 1{,}5 = 3{,}0$) ve *Surrogates* (`NEW_RELEASE`, 2 gün $\rightarrow 2\times 3 = 6{,}0$) kiralandığında toplam borcun `12.5` ve toplam bonusun `4` (`1 + 1 + 2`) olduğunu sınar (ekrandan, 01:58:30).
  4. `testStatementWithMoviesShortRent()`: *The Matrix* (1 gün $\rightarrow 2{,}0$), *Monsters, Inc.* (1 gün $\rightarrow 1{,}5$) ve *Surrogates* (1 gün $\rightarrow 3{,}0$) kiralandığında toplam borcun `6.5` ve bonusun `3` olduğunu sınar (ekrandan, 02:00:00).
  5. `testNewReleaseRentalBonus()`: İki `NEW_RELEASE` filmden *Surrogates* (2 gün $\rightarrow 6{,}0$, `2` puan) ve *Terminator Salvation* (1 gün $\rightarrow 3{,}0$, `1` puan) kiralandığında toplam borcun `9.0` ve bonusun `3` olduğunu sınar (ekrandan, 02:00:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
