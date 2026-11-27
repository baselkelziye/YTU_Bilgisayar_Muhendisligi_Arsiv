# Ders 6 Genişletilmiş Notu: Fonksiyonel Çözümleme: Veri Akış Diyagramları, Süreç Tanımlama ve Veri Sözlüğü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yeri: iş analizinden fonksiyonel çözümlemeye
- 2. Gereksinim analizi modeli (tekerlek modeli)
- 3. Veri akış diyagramı ve öğeleri
- 4. VAD sembolleri
- 5. VAD kuralları
- 6. VAD düzeyleri
- 7. Düzeyler arası tutarlılık
- 8. Kavramsal veri modeli ve varlık ilişki diyagramları
- 9. Mantıksal ve fiziksel VAD
- 10. Süreç tanımlama formu ve süreç mantığı
- 11. Karar tabloları ve karar ağaçları
- 12. Veri sözlüğü
- 13. Gerçek gereksinim listesi ve SRS (IEEE 830)
- Örnek Sorular

## 1. Dersin yeri: iş analizinden fonksiyonel çözümlemeye

Ders altıncı haftada sistem analizi konusuna devam ederek başladı. Önceki hafta iş analizi işlenmişti: işin nasıl yapıldığı, iş modelinin ne olduğu, kurulacak bilgi sistemiyle çözülmeye çalışılan problemin ne olduğu, bunun gerçek işi yapan insanlardan ve birimlerden nasıl öğrenileceği ve sonuçların bir iş gereksinimleri belgesiyle (business requirements document) nasıl raporlanacağı. Bu belge, gereksinim analizinin fonksiyonel çözümleme ya da kavramsal model oluşturma aşamasına zemin hazırlar.

Slayttaki ders başlıkları şunlardır (ekrandan, 00:10:00):

- Sistem Analizi
- Fonksiyonel Çözümleme
- SRS
- Kavramsal Modelin Oluşturulması

Bu hafta daha teknik tarafa geçilir: fonksiyonel çözümleme ve SRS (Software Requirements Specification, yazılım gereksinim tanımları belgesi). Kavramsal modelin oluşturulması ise sonraki haftaya bırakıldı. Bunun nedeni, problem uzayını modellemede iki temel yaklaşım bulunmasıdır:

- **Yapısal (geleneksel, işlevsel) yaklaşım**, slayttaki adıyla fonksiyonel çözümleme.
- **Nesneye yönelik çözümleme**: gerçek dünya nesneleri soyutlanarak yazılıma taşınır. Bunun için önceki hafta gereksinim raporlama yöntemlerinden biri olarak görülen kullanım senaryoları (use case) kullanılacak; use case modeliyle problem (domain) modelinin ilişkisi ve tasarıma geçiş sonraki derste işlenecek.

### 1.1 Gereksinim analizinin amacı

Gereksinim analizinde bir model oluşturulur. Amaç, gereksinimleri formal biçimde, değişmeyecek ve herkesin okuduğunda aynı şeyi anlayacağı şekilde açıklamak ve bununla birlikte teknik ayrıntıları vermeye başlamaktır. Böylece gerçekleştirilecek, kodlanacak bir çözüm önerisinin (tasarımın) temelleri ortaya konur.

Hoca bir noktaya özellikle dikkat çekti: sürecin daha başındayız ama aynı zamanda sürecin sonundaki test ve onay mekanizmaları için bir denetim unsuru da yaratıyoruz. Bilgi sistemi devreye alındığında gerçekten ihtiyaçları karşılayıp karşılamadığı, istekleri düzgün yerine getirip getirmediği analiz modeline, örneğin senaryolara geri dönülerek kontrol edilir: sistem girdileri alıp gerekli işlemleri yaparak gerekli çıktıları ve hizmetleri üretebiliyor mu? Yani analiz modeli aynı zamanda bir onay, kontrol ve takip listesi işlevi görür.

## 2. Gereksinim analizi modeli (tekerlek modeli)

Hoca bu kısmın biraz teorik olduğunu, ama mühendis olarak sistem analizi ve tasarımının altında yatan tekniği bilmek gerektiğini söyledi. Gereksinim analizi modeli yuvarlanan bir tekerlekle gösterilir (ekrandan, 00:15:00). Slayttaki tanımlar şunlardır:

- **Veri Sözlüğü:** Tüm veri nesnelerinin tanımları (metadata)
- **Varlık İlişki Diyagramı (ERD):** Veri nesneleri arası ilişkiler
- **Veri Akış Diyagramı (VAD):** Verilerin nasıl taşındığı, veri akışını sağlayan fonksiyonların neler olduğu
- **Durum Geçiş Diyagramı (STD):** Sistem dışındaki olaylar sonucunda sistemin nasıl hareket ettiği

Tekerleğin yapısı metin olarak şöyledir:

| Halka | Süreç tarafı | Veri tarafı | Kontrol tarafı |
|---|---|---|---|
| Dış halka (spesifikasyon) | Süreç Spesifikasyonu | Veri Nesne Tanımı | Kontrol Spesifikasyonu |
| Orta halka (diyagram) | Veri Akış Diyagramı | Varlık İlişki Diyagramı | Durum Geçiş Diyagramı |
| Merkez | Veri Sözlüğü | Veri Sözlüğü | Veri Sözlüğü |

Üç eşit parçanın anlamı şudur:

- **Süreç spesifikasyonu:** Süreç, belirli bir zaman içinde belirli eylemlerin yapılmasıyla ortaya konan iştir, yani iş akışlarıdır. Analiz modelinde bunların tanımlanması gerekir. Temel araç veri akış diyagramıdır (data flow diagram, DFD). Hoca slaytta İngilizce kısaltmaların arasında Türkçe "VAD" kaldığını fark edip kalemle üzerine "DFD" yazdı (ekrandan, 00:20:00).
- **Veri nesne tanımı:** Süreçlerde kullanılan veri nesneleri, yani hakkında bilgi tutulması, kayıt altına alınması, yazılı ya da basılı saklanması gereken kavramlar ve bunların birbirleriyle ilişkisi. Varlık ilişki diyagramı (entity relationship diagram) ile modellenir.
- **Kontrol spesifikasyonu:** Süreçler veri kullanarak işletilirken sistemin belirli bir uyaranla hangi parçalarının hangi durumlara geçeceği. Hoca bunu bir yazıcıyla örnekledi: yazıcı boşta (idle) beklerken veri akmaya başlayınca çalışıyor durumuna geçer, motor ve çarklar çalışmaya başlar, ikili sinyali toner ya da mürekkeple kâğıda basar. Bu geçişler durum geçiş diyagramlarıyla (state transition diagram) tanımlanır.

Süreç, veri nesneleri ve kontrol bir arada tanımlandığında tam bir analiz modeli ortaya konur. Bu modelde üretilen her şeyin ayrıntılı tanımı merkezdeki **veri sözlüğünde** tutulur. Veri sözlüğü üst veri (metadata), yani veriyi tanımlayan veri olarak da düşünülebilir.

Ders kapsamı şöyle sınırlandı: kontrol spesifikasyonu ders kapsamı dışındadır (hoca slaytta altına çarpı koydu). Varlık ilişki diyagramı ileriki haftalarda, özellikle tasarımla birlikte işlenecek. Bu haftanın odağı süreç spesifikasyonu, yani akışların, işlevlerin ve senaryolarda yapılması gerekenlerin nasıl modelleneceği ve veri sözlüğüdür.

## 3. Veri akış diyagramı ve öğeleri

### 3.1 Öğeler ve ilk örnek

Slayttaki tanım şudur: sistemdeki varlıklar, süreçler (işlemler), veri depoları ve aralarında verinin akışı (ekrandan, 00:25:00). Hoca slayttaki basit çizimi gösterip "bu bir veri akış diyagramı, bitti" diye şaka yaptı, ama bunun bir mantığı ve kuralları olduğunu ekledi.

VAD süreç spesifikasyonu için kullanılır. Süreçler, sistemin işlevleri ya da kabaca modülleridir: "şu işlem grubum var, bu işlem grubum var". Diyagram şunları sorar:

- İş analiziyle keşfedilen **varlıklar** neler? Bunlar kullanım senaryolarındaki aktörlere karşılık gelir.
- **Süreçler (işlemler)** neler? Hangi sorumluluklar, hangi senaryolar, hangi işlevler yerine getirilmeli? Bunlar kompozit yapılardır, içlerinde başka süreçler barındırırlar. Hoca süreç ve işlem kelimelerini tamamen aynı anlamda kullandığını belirtti.
- **Veri depoları** neler? Veriler nerede tutulmalı: bir veri tabanı tablosu, bir JSON dosyası, bir web servisine gönderilen veri, bir bulut depolama ortamı, hatta kâğıt form ya da basılı öğrenci karnesi.
- Bunlar arasındaki **veri akışları** neler?

> **Hocanın vurgusu:** Bu diyagramın adı veri akış diyagramıdır; dolayısıyla en önemli öğeleri oklardır. Kutular varlık, işlem ve depo anlamı taşır, ama esas olan süreci işletmek için gereken akışlardır.

Slayttaki örnek şöyledir (ekrandan, 00:25:00):

```text
[Öğrenci] --Kimlik Bilgileri--> (1.1 Yeni Öğrenci Kaydı) --Yeni öğrenci bilgisi--> [D1 | Öğrenciler]
```

Hoca diyagramın okunuşunu şöyle anlattı: Öğrenci varlığı, yeni öğrenci kaydı işleminin çalışması için bir girdi sağlar. Öğrencinin ne vereceği iş analiziyle belirlenir ve okun üzerine adı yazılır. Bu veri tekil olabileceği gibi kompozit de olabilir; bir öğrencinin transkripti bile bir akış olabilir. Oklar kavramsal dünyadadır, integer ya da string gibi düşünülmemelidir; büyük veri blokları, tablolar da olabilir.

Süreçten çıkan bir ok, sürecin bir çıktı üretip onu bir yere gönderdiğini gösterir. Bu çıktı:

- bir veri deposuna kaydedilebilir (öğrenci bilgileri öğrenci tablosuna),
- başka bir sürece girdi olarak verilebilir,
- bir dış varlığa gönderilebilir.

Hoca örneği slayt üzerinde genişletti (ekrandan, 00:30:00). Kayıttan sonra öğrenciye bir danışman atanmalıdır; bunun bir karar mekanizması, yani bir süreci vardır. Bu yüzden 1.2 Danışman Ataması süreci eklendi ve aynı "Yeni öğrenci bilgisi" oku ikiye bölünerek bu sürece de gönderildi. Ardından YÖK (Yükseköğretim Kurulu) dış varlığı eklendi ve yeni öğrenci bilgisi oraya da gönderildi:

```text
[Öğrenci] --Kimlik Bilgileri--> (1.1 Yeni Öğrenci Kaydı)
(1.1) --Yeni öğrenci bilgisi--+--> [D1 | Öğrenciler]
                              +--> (1.2 Danışman Ataması)
                              +--> [YÖK]
```

YÖK'e gönderim, tasarımda ve gerçekleştirmede belki bir web servisine REST API ile JSON gönderilmesine dönüşecektir. Ama şu anda problem modellenmektedir; ortada ne REST API, ne JSON dosyası, ne de algoritma vardır. Yalnız süreçten çıkanların bir yere kaydedildiği, bir dış paydaşa gönderildiği ya da başka bir sürece girdi olduğu modellenir.

### 3.2 Slayttaki kurallar

Slayttaki maddeler şunlardır (ekrandan, 00:25:00):

- Birden fazla varlık olabilir.
- Okların çakışmaması için aynı varlık tekrarlanabilir.
- Oklar tek yönlüdür.
- Okların tek bir kaynağı ve hedefi vardır.
- İşlemler hiyerarşiye uygun numaralandırılır.

Hoca bunları şöyle açıkladı. Oklar arttıkça çakışmalar olur; bu yüzden örneğin öğrenci varlığı kopyalanıp diyagramın başka bir yerine bir daha konabilir. Bu başka bir varlık değil, aynı aktördür.

Oklar veri akışıdır, kaynaktan hedefe gider ve iki tarafa birden gitmez. Ters yönde bir veri gidecekse bu başka bir oktur. Hoca örnek olarak kayıt sürecinden öğrenciye giden kırmızı bir ok çizdi: öğrenci kimlik kartı, öğrenci numarası ya da kayıt belgesi. Bu, kimlik bilgileriyle aynı akış değildir; adı farklıdır, yönü farklıdır, ayrı bir okla gösterilir.

İşlemler hiyerarşik numaralanır. Üst düzey modüller (genel sorumluluklar) 1.0, 2.0, 3.0, 4.0 diye numaralanır. Örneğin yeni öğrenci kaydının içinde önce MERNİS sorgulaması, sonra ÖSYM'den puan ya da kazanılan bölüm bilgisinin sorgulanması, sonra öğrenci işlerinde dosya açma süreci gerekebilir. Bu alt işlevlere 1.1, 1.2, 1.3 gibi hiyerarşik numaralar verilir. Bu numaralandırma birinci ve ikinci düzey diyagramlarda anlam kazanır.

### 3.3 Öğelerin tanımları

Hoca öğeleri tekrar özetledi:

- **Varlıklar:** Kişi, kurum, birim ya da sistem olabilir; illa insan olmaz. Kullanım senaryolarındaki birinci aktörlere karşılık gelir. Ya veri sağlarlar ya da veri alırlar.
- **Veri akışları:** Bir kaynaktan bir hedefe hareket eden verilerdir. Tek bir barkod numarası da olabilir, bir rapor çıktısı ya da bir koleksiyon da olabilir.
- **Süreçler:** Elle ya da bilgisayarla yürütülen etkinlik ya da fonksiyondur. Manuel süreçler de VAD'da gösterilir. Emir kipinde yüklemlerle adlandırılmaları doğrudur, örneğin "Randevu Al". Her süreç tekil bir etkinlik içermelidir; "şu ve şu işlemleri" diye bir süreç olmaz, bunlar örneğin 3.0 ve 4.0 diye ayrı süreçler olarak modellenir.
- **Veri depoları:** Verilerin kalıcı olarak bulunduğu yerlerdir. Dosya, klasör, veri tabanı, veri tabanı tablosu, bulut ortamı, form, çıktı, hatta karekod olabilir; karekod da veriyi kodlayan bir depodur.

## 4. VAD sembolleri

VAD çizerken iki temel sembol ailesi kullanılır (ekrandan, 00:35:00). Hoca, farklı kaynaklarda süreç için daire, veri deposu için üstü ve altı çizgili semboller görülebileceğini, bunun DeMarco ve Yourdon ailesi olduğunu belirtti. Derste ve çizim araçlarında (CASE araçları) daha yaygın olan Gane ve Sarson sembolleri kullanılır.

| Anlamı | DeMarco ve Yourdon | Gane ve Sarson | Örnek |
|---|---|---|---|
| Süreç (S) | Daire içinde süreç adı | Üstte numara (1), altta süreç adı olan köşeleri yuvarlatılmış dikdörtgen | 1.1 Profil Bilgileri Gir |
| Veri Akışı (VA) | Adı yazılı ok | Adı yazılı ok | Doğrula (kötü örnek) |
| Veri Deposu (VD) | Üstü ve altı çizgili "D1 Veri Deposu Adı" | Solda D1 kutusu, sağı açık dikdörtgen | D3 Hasta Kimlik |
| Harici Varlık (HV) | Dikdörtgen | Dikdörtgen | Hasta |

Açıklamalar:

- Gane ve Sarson'da süreç numaralandırılır, hiyerarşik numaralandırma bu ailede de vardır.
- Veri akışının adı okun üzerine yazılır. En önemli husus, akış adlarının **isim** olmasıdır. Adda fiil (eylem, iş) varsa o bir süreçtir ve süreç olarak modellenmelidir. Slayttaki "Doğrula" akışı kötü bir örnektir; hoca üzerine çarpı koydu. "Doğrulanmış veri" ya da "doğrulanmış ... verisi" olmalıydı.
- Veri depoları D1, D2, D3 ... DN diye numaralanır; adı "... dosyası", "... tablosu", "... servisi" gibi olabilir.
- Harici varlıklar dikdörtgenle gösterilir. Bir varlık okları dolaştırmamak için tekrar ediyorsa dikdörtgenin köşesine çentik atılır (köşeye çapraz bir çizgi çizilir); bu, tekrar eden varlık anlamına gelir.
- Örnek sütunundaki "Profil Bilgileri Gir" bir sosyal medya uygulamasında profil bilgilerinin girilmesi süreci, "Hasta" ise bir harici varlıktır.

## 5. VAD kuralları

Hoca kuralları tablo halinde bir daha geçti.

### 5.1 Girdi ve çıktı kuralları

- **İşlemlerin yalnız çıkışı olmaz.** Girdi, işlem, çıktı (input, process, output) mantığıyla çalışılır; hiç girdi almadan çıktı üreten işlem olmaz.
- **İşlemlerin yalnız girişi olmaz.** Girdisi olup çıktısı olmayan bir işlem hiçbir şey yapmıyor demektir; en azından bir akış çıkmalı ya da bir yere kaydedilmelidir.
- **İşlem girişleri istenen çıkışı verecek kadar yeterli olmalıdır.** Üst seviyeli modelleme yapılsa da yeterli ayrıntı gösterilmelidir.

Hoca son kuralı maaş hesaplama örneğiyle açıkladı. Bir maaş hesaplama süreci yalnız çalışma dosyasından çalışma saatlerini alıyorsa model eksiktir. Maaş yalnız saatle hesaplanamaz: çalışanın görevi, unvanı (muhasebeci, büro elemanı, teknisyen, birim yöneticisi, genel müdür) maaş katsayılarını ve fazla mesai ücretini değiştirir. Bu yüzden süreç hem saatleri hem çalışan verilerini farklı veri depolarından almalıdır. Böyle bir model, ileride tasarımı yapacak ya da kodlayacak kişilere daha analiz modelinden yol gösterir.

<!-- BELİRSİZ: bu ilk kural tablosunun slaytı karelerde yok; kurallar anlatımdan aktarıldı. -->

### 5.2 Veri deposu kuralları ve iki yönlü ok

Slayttaki tablo şöyledir (ekrandan, 00:40:00):

| Kural | Yanlış | Doğru |
|---|---|---|
| Her veri deposu bir işlemle ilgili olmalıdır. | S1 Veri Deposu → (Veri Akışı) → S2 Veri Deposu | S1 Çalışma Dosyası → (Çalışma Saatleri) → 1.0 Maaş Hesaplama |
| Veri deposu bir varlıkla doğrudan ilişkide olamaz. | Entity Source/Sink → (Veri Akışı) → S1 Veri Deposu | 0.0 İşlem → (Veri Akışı) → S1 Veri Deposu |
| Veri akışı oku iki yönlü olamaz. Bir işlemle veri deposu arasında karşılıklı veri akışı varsa farklı tek yönlü oklarla gösterilmelidir. | 0.0 İşlem ↔ (Veri Akışı) ↔ S1 Veri Deposu | 0.0 İşlem → (Veri Akışı) → S1 Veri Deposu ve S1 Veri Deposu → (Veri Akışı) → 0.0 İşlem |

Hoca kuralları şöyle açıkladı:

- Bir veri deposundan başka bir veri deposuna doğrudan akış olmaz ("tablodan aldım, öbür tabloya yazdım" olmaz). Arada mutlaka bir işlem, bir süreç bulunur.
- Bir dış varlıktan bir veri deposuna da doğrudan akış olmaz. Kayıt örneğinde öğrenci gelip kimlik ve ÖSYM bilgilerini doğrudan üniversitenin öğrenci tablosuna "insert into" ile yazamaz; bu bir süreçtir, arada en az bir işlem olmalıdır. Tablodaki "doğru" sütununda işlemin girdisi yer darlığından çizilmemiştir.
- İki yönlü ok kullanılmaz; karşılıklı akışlar farklı verilerdir ve ayrı oklarla gösterilir.

### 5.3 Diğer kurallar

- **Aynı veri birden çok işleme gidiyorsa** ayrı ayrı oklar yerine tek bir akışın dallanmasıyla gösterilmesi daha okunaklıdır; ilk örnekte okların okun içinden bağlanması bunun örneğidir.
- **Kendine dönen akış:** Bir işlemin hiçbir işlemden geçmeden çıktısını kendine geri beslemesi doğal değildir. Böyle bir durum aslında sürecin içinde 1.1'den 1.2'ye giden bir akış olduğunu gösterir ve bunun yeri ikinci düzey diyagramdır. Beklenen, bir işlemin başka bir işleme akış sağlaması, o işlemin de başka bir işleme ya da ilkine başka bir akış göndermesidir.
- **Veri akışı adları isimdir:** "Siparişi Doğrula" yanlıştır, bir iştir. "Doğrulanmış Sipariş" olmalıdır; bu kompozit bir veridir (sipariş kimliği, tarih, saat, içerik listesi, tutarlar, adres, ödeme bilgisi, banka onayı içerebilir). "Zaman Çizelgesini Tamamla" yerine "Tamamlanmış Zaman Çizelgesi" ya da "Zaman Çizelgesi" yazılmalıdır.

## 6. VAD düzeyleri

VAD tek seferde çizilemez; düzeylendirilir. Süreçlerin içinde alt süreçler olması bunun işaretidir. Hoca ileride bir hafta boyunca bir vaka çalışması (case study) yapmayı düşündüklerini söyledi.

### 6.1 Taslak (bağlam) VAD

Slayttaki maddeler şunlardır (ekrandan, 00:45:00):

- Ön inceleme sonucunda belirlenir.
- Sistemle varlıklar arası ilişkiyi gösterir.
- Ayrıntılı süreç ve veri depoları bulunmaz.
- Bağlam diyagramı olarak da bilinir.

Taslak VAD analizin en başında, ön inceleme ya da ilk iş analizi sırasında bile çizilebilir. Bütün sistem tek bir süreçtir; sistemin ana aktörleri çevrede dış varlık olarak bulunur; temel veri akışları gösterilir. Veri depoları yoktur, çünkü depolar sürecin iç işleyişi içindir. Bu diyagrama **context diagram** (bağlam diyagramı) da denir; hepsi aynı şeydir. Kuş bakışı bir ana resimdir.

Slayttaki örnek bir faturalama sistemidir:

```text
[Doktor] --Muayene Kaydı--> (FATURALAMA SİSTEMİ)
[Hasta]  --Sigorta Formu--> (FATURALAMA SİSTEMİ)
(FATURALAMA SİSTEMİ) --Hasta Faturası-->   [Hasta]
(FATURALAMA SİSTEMİ) --Sigorta Faturası--> [Sigorta]
```

Sigorta ile hasta arasında da işlemler olabilir, ama bunlar sistemin sınırları dışındadır; onlar başka bir sigortalama sisteminin konusudur.

Hoca diyagramın arkasındaki iş analizini bir senaryoyla anlattı. Özel bir diş kliniği için faturalama sistemi yapılmaktadır. Klinikte iki diş hekimi vardır ve özel sigortalarla anlaşmaları vardır; sigortalar bazı tedavilerin %50'sini, bazılarının %100'ünü karşılar. Analist gözlem yöntemiyle kenarda oturup işi izler: hekim dolgu yapar, muayene kayıtlarını faturayı hazırlayan çalışana verir. Çalışan hastaya sigortası olup olmadığını sorar, sigorta bilgilerini alır, sigortacıyla hangi işleme ne kadar indirim yapılacağını ve kimin ne ödeyeceğini konuşur; bu bir süreçtir. Sonra iki fatura üretir: hasta faturası (örneğin dolgu işlemi hasta payı 50 lira) ve sigorta faturası (dolgu işlemi sigorta payı 150 lira). Sigorta faturası zarfla postalanır, hasta faturası hastaya verilir ve hasta kartla ya da nakit öder. Kalabalık bir klinikte birkaç çalışan iş bölümü yapmış olabilir (biri dolgulara, biri diş tellerine bakar).

Analistin çıkardığı sonuç basittir: bir faturalama problemi vardır; doktordan ve hastadan bir şeyler alınır, hastaya ve sigortaya bir şeyler üretilir. Bu çizim müşteriye (klinik sahibine) gösterildiğinde müşteri onaylayabilir ya da eksik söyleyebilir: "SGK işlemleri de var, onları her akşam yarım saat yapıyoruz." Bu durumda bağlam diyagramına bir dış varlık olarak SGK eklenir ve sistemden SGK'ya "SGK gün dökümleri" adlı bir akış çizilir. Model güncellenmiştir ama hâlâ taslak düzeydedir; içi henüz açılmamıştır.

<!-- BELİRSİZ: SGK eklemesi slayt üzerine elle çizildi; bu anın karesi yok, akışın adı altyazıdan alındı. -->

### 6.2 Düzey adlandırması

Taslak düzeye **sıfırıncı düzey** de denir. Bazı kaynaklar taslak, 0, 1; bazıları 0, 1, 2 der: taslağa taslak deyip 1. düzeye 0, 2. düzeye 1 diyenler vardır. Hangisi olursa olsun temel olarak üç düzey tanımlıdır.

### 6.3 Birinci düzey VAD

Birinci düzeye geçmek, bağlam diyagramındaki tek süreç kutusunu "çift tıklayıp" açmak gibidir; hoca bunu içinden ne çıkacağı bilinmeyen kutuların açıldığı bir yarışmaya benzetti. Slayttaki maddeler şunlardır (ekrandan, 00:55:00):

- Süreçleri ve işlemleri, ilişkili veri depoları, varlıklar ve depolarla işlemler arası ilişkileri gösterir.
- Sistemdeki tüm süreçlerin birbiriyle ve dış kaynaklarla olan ilişkisi belirlenir.
- Öncesinde «Bağlam VAD» kullanıldıysa, «Düzey 0 VAD» olarak da isimlendirilir.

Faturalama sisteminin birinci düzey diyagramı şöyledir:

| Kaynak | Veri akışı | Hedef |
|---|---|---|
| Doktor | Muayene Kaydı | 1.0 Muayene Kaydı İnceleme ve Ücret Hesabı |
| 1.0 | Ücret | D1 Ücret Listeleri |
| 1.0 | Doğrulanmış Ücret | 2.0 Fatura Hazırlama |
| Hasta | Sigorta Formu | 2.0 |
| D3 Sigorta Şirketleri | Sigorta Şirketi Adı ve Adresi | 2.0 |
| D2 Hastalar | Hasta Adresi | 2.0 |
| 2.0 | Hasta Faturası | Hasta (tekrar eden varlık, çentikli) |
| 2.0 | Sigorta Faturası | Sigorta Şirketi |
| Hasta (çentikli) | Hasta Ödeme | 3.0 Hasta Ödemeleri İşleme |
| Sigorta Şirketi | Sigorta Ödeme | 4.0 Sigorta Ödemeleri İşleme |
| 3.0 | Hasta Ödeme | D4 Muhasebe Kayıtları |
| 4.0 | Sigorta Ödeme | D4 Muhasebe Kayıtları |

(ekrandan, 00:55:00)

Hoca diyagramı şöyle yorumladı:

- 1.0 adında "ve" kullanılmıştır; bu iyi bir şey değildir (her süreç tekil bir etkinlik olmalıdır). Burada muayene kaydı doktordan alınır, kullanılan malzemeye göre hesap yapılır. Örneğin sarf malzemelerinin fiyat listesinden de bilgi alınabilirdi; slaytta yoktur.
- 2.0 Fatura Hazırlama hastadan sigorta formunu, sigorta şirketleri dosyasından şirketin adını ve adresini, hastalar dosyasından hastanın adresini alır; hastaya ve sigorta şirketine fatura gönderir. Hangi bilginin hangi dosyadan geleceği analize göre değişir; bu bir örnektir.
- Hastanın ödeme işlemi ve sigorta şirketinin ödeme işlemi aynı muhasebe kayıtları dosyasına yazılır, ama farklı süreçler oldukları için ayrı modellenmişlerdir. Hasta varlığının köşesi tekrar ettiği için çentiklidir.
- Sonuç olarak faturalama sisteminde dört temel modül bulunmuştur: muayeneden ücret hesabı, fatura hazırlama, hasta ödemeleri ve sigorta şirketi ödemeleri.

Bu düzeyde hâlâ sistemin daha ayrıntılı bir taslağı çizilmektedir; amaç işlevsel kırılımları ortaya çıkarmaktır. En önemli öğeler süreçler, bunların ihtiyaç duyduğu temel veri akışları, veri depolarıyla ve birbirleriyle ilişkileridir. İş analiziyle, gözlemle ya da anketle toplanan gereksinimler burada işletilmesi gereken süreçler olarak modellenir.

### 6.4 İkinci düzey VAD

Bir sürece birkaç akış giriyor ve birkaç akış çıkıyorsa o karmaşık bir süreçtir; içinde alt işlemler, alt modüller olmalıdır. Slayttaki maddeler şunlardır (ekrandan, 01:00:00):

- Her sürecin alt işlemleri ayrıntılarıyla gösterilir.
- 1. düzeydeki her süreç için bir 2. düzey VAD çizilir.
- Tek bir süreçle veri kaynakları arası ilişki detaylı gösterilir.
- Öncesinde «Düzey 0 VAD» kullanıldıysa, «Düzey 1 VAD» olarak da isimlendirilir.

2.0 Fatura Hazırlama sürecinin açılımı şöyledir:

| Kaynak | Veri akışı | Hedef |
|---|---|---|
| Hasta | Sigorta Formu | 2.1 Hastanın Sigorta Durumunun İncelenmesi |
| 1.0 Muayene Kaydı İnceleme ve Ücret Hesabı | Doğrulanmış Ücret | 2.1 |
| 2.1 | Sigorta ve Ücret Bilgisi | 2.2 Listelenen Miktarla Faturayı Kıyaslama |
| D3 Sigorta Şirketleri | Sigorta Şirketi Adı ve Adresi | 2.2 |
| 2.2 | Sigorta Faturası | Sigorta Şirketi |
| 2.2 | Hastanın Ödemesi Gereken Tutar | 2.3 Hastanın Ödemesi Gereken Tutarın Faturalanması |
| D2 Hastalar | Hasta Adresi | 2.3 |
| 2.3 | Hasta Faturası | Hasta (çentikli) |

(ekrandan, 01:00:00)

Bu diyagramda 1.0 başka bir dış işlem, Hasta bir dış varlık gibi görünür. İkinci düzeyde birinci düzeydeki işlemlerin alt işlem kırılımları gösterilir. Hoca slayttaki "her süreç için çizilir" ifadesinin her zaman zorunlu olmadığını belirtti: bir süreç tek bir senaryo ya da tek bir süreç tanımlama formuyla tasarıma ve kodlamaya hazır hale getirilebiliyorsa ikinci düzey diyagram gerekmeyebilir. Ancak gerçek sistemlerde birinci düzey genellikle yeterli kalmaz. Derste üçüncü düzeye geçilmez; sistem, ana modüller ve alt modüller kırılımı problemi modellemek için yeterlidir.

## 7. Düzeyler arası tutarlılık

Hoca bir "Hata Nerede?" slaytı gösterip öğrencilere düşünmeleri için ara verdi; aradan sonra cevabı açıkladı (ekrandan, 01:05:00; 01:15:00). Soru ve çözüm Örnek Sorular bölümündedir.

Bu örnekten çıkan ilke şudur:

> **Hocanın vurgusu:** Veri akış diyagramlarında düzeylendirme yapılırken bir önceki ve bir sonraki düzey arasında tutarlılık esastır. Özellikle harici varlıklar ve bu varlıklarla olan veri akışları tutarlı olmalıdır. Hiçbir şey yoktan var olmaz, hiçbir şey bir anda yok olmaz.

Düzeyler arasında geçerken dış varlıklarla birlikte yeni varlıklar ve yeni dış veri akışları türetilmemelidir. Buna karşılık iç süreçler, iç veri akışları ve veri depoları bağlam diyagramında ya da düzey 0'da yoktur ama alt düzeyde ortaya çıkabilir; bu normaldir. Örneğin bir süreç içinde A ve B'nin türevleri gibi yeni iç akışlar üretilebilir.

Hoca ikinci bir "sorun var mı" örneği daha gösterdi: farklı veri akışlarını tek bir okta birleştirmek. Bu da Örnek Sorular bölümündedir.

## 8. Kavramsal veri modeli ve varlık ilişki diyagramları

Tekerleğin üçte biri (süreç spesifikasyonu) görüldükten sonra hoca kavramsal veri modeline kısaca değindi. Slayttaki maddeler şunlardır (ekrandan, 01:20:00):

- Yüksek seviyelidir, kullanıcı topluluğuyla iletişim için kullanılır.
- Veri yapısı, donanım, yazılım bilgisi yer almaz.
- Tam ve yeterli bileşenler ile sistemin bilgi gereksinimlerinin gerçek gösterimini oluşturur.
- **Varlık ilişki diyagramları:** verinin kavramsal gösterimini sunar.
  - Veri nesneleri ile aralarındaki ilişkilerin grafiksel gösterimi
  - Kavramsal veri modellemesinin yapılmasını sağlar
- İleriki haftalarda

Kavramsal veri modeli, problemin önemli parçalarını ve bunlar hakkında tutulması gereken verileri gösterir. Örneğin bir ders verisinin kodu, adı, kredisi, uygulama kredisi, veren öğretim üyesi, belki kapasitesi ve sınıfı vardır. Aynı modelle çok sayıda öğrencinin ve çok sayıda dersin verisi tutulabilir. Asıl soru aralarındaki ilişkidir: öğrenci ders alır, derse öğrenci kayıtlıdır; bu nasıl bir ilişki tipidir? Bunlar varlık ilişki diyagramlarında gösterilir.

Böylece üç model tamamlanır: süreç modeli, veri modeli, kontrol modeli. Şimdilik süreç ve veriye odaklanılır, kontrol ders kapsamı dışındadır. Varlık ilişki diyagramlarının temel özellikleri ileride tasarım tarafında, veri modelinin nasıl tasarlanacağıyla birlikte işlenecek. Oluşturma ayrıntıları ve normalizasyon veri tabanı yönetim sistemleri dersinin konusudur; bu derste bir bilgi sisteminin verilerini modelleyecek kadarı öğrenilir.

## 9. Mantıksal ve fiziksel VAD

Hoca "veri akış diyagramlarıyla tasarım da gösterilebilir mi?" sorusunu bir yere kadar evet diye cevapladı ve iki tür VAD'dan söz etti:

- **Mantıksal VAD (logical DFD):** Analiz safhasında üretilir. Süreçler, işler, faaliyetler, varlıklar, veriler ve veri akışları tanımlanır; buraya kadar işlenen konu budur.
- **Fiziksel VAD:** Mantıksal VAD'a sistemin nasıl uygulanacağına yönelik yönergeler eklenir: donanım, yazılım, dosya ya da insan kaynaklarıyla ilgili ayrıntılar. Tasarım aşamasının bir ürünüdür.

Örnek, bir hastane bilgi sisteminde eczaneden ilaç temin etme sürecinin mantıksal VAD'ıdır (ekrandan, 01:25:00):

```text
[Hasta] --Alınacak İlaçlar--> (1 İlacı Bul) --İlaç No--> (2 Fiyatı Ara)
[D1 | Fiyatlar] --Fiyatlar--> (2 Fiyatı Ara)
(2 Fiyatı Ara) --İlaçlar ve Fiyatlar--> (3 Reçete Toplamı Hesapla)
(3 Reçete Toplamı Hesapla) --Ödenecek Miktar--> (4 Ödeme Al ve Fatura Ver)
[Hasta] --Ödeme--> (4 Ödeme Al ve Fatura Ver)
[Hasta] --Fatura--> (4 Ödeme Al ve Fatura Ver)   (slayttaki hatalı yön)
```

Hoca senaryoyu şöyle anlattı: hastanın getirdiği ilaç listesiyle (reçeteyle) biri ilacı bulmak için önce bir tablodan kategorisine, sonra hangi koridorda ve rafta durduğuna bakar; bunun sonucunda ilaç numaraları bulunur. İlaç numaraları fiyat bulma sürecine verilir; bu süreçten sorumlu çalışan fiyat dosyasından ilaçların fiyatlarını bulur. Sonra reçetenin toplam tutarı hesaplanır (bir ilaçtan birkaç kutu verilmiş olabilir, belki SGK indirimi uygulanır) ve ödenecek miktar bulunur. Bu miktar ödeme alıp fatura basma sürecine gider.

Hoca slayttaki iki kusuru belirtti:

- "İlaçlar ve Fiyatlar" adı kötüdür; "İlaç Fiyatları" gibi bir ad daha iyi olurdu.
- Fatura oku ters çizilmiştir: fatura hastadan sürece değil, süreçten hastaya gitmelidir.

Aynı diyagram bir adım ileri taşınıp gerçekleştirme ayrıntısı eklenince fiziksel VAD olur: ilaç barkodu tarama süreci, fiyatı aramak için ilaç numarasının sorguyla tabloya verilmesi ve ilacın tanımıyla fiyatının dönmesi, toplam maliyet için ilaçlar, fiyatlar ve alt toplamları tutan geçici bir dosya, elle yapılan ödeme işlemlerinde nakit ödemenin gelmesi ve faturanın gitmesi gibi. Bu, gerçekleştirmeye yönelik bir tasarıma yol gösterir ya da yapılmış bir tasarımı anlatmak için kullanılabilir.

<!-- BELİRSİZ: fiziksel VAD slaytı karelerde yok; öğeler yalnız anlatımdan aktarıldı. -->

Fiziksel VAD her zaman yapılmaz ama yapılırsa şaşırılmamalıdır. Aksi söylenmedikçe derste VAD denince hep mantıksal VAD, yani analiz modelini ve problem uzayını gösteren diyagram kastedilir.

## 10. Süreç tanımlama formu ve süreç mantığı

### 10.1 Neden gerekir?

Buraya kadar sistemin yapısı, varlıkları, veri akışları ve depoları çizildi; bir sürecin işlemesi için neyin alınıp neyin çıkacağı modellendi. Ama süreç kutularının içi henüz boştur: nasıl yapılacaklarına dair bir yöntem, yaklaşım ya da algoritma akışı verilmemiştir. Düzgün bir model tanımı için süreçlerin iç yapısı ve işlevleri de ifade edilmelidir. Bunun için basit bir **süreç tanımlama formu** kullanılır.

İş akışının mantığını (business logic, süreç mantığı) tanımlamak için üç temel yöntem vardır:

- Akış diyagramı ya da onun karşılığı olan yapısal dil (pseudocode)
- Karar tabloları
- Karar ağaçları

Karar tabloları ve ağaçları özellikle karmaşık süreçleri modellemek için kullanılır.

### 10.2 Form örneği

Slayttaki form, eczane örneğindeki 4 numaralı süreç içindir (ekrandan, 01:30:00):

| Alan | Değer |
|---|---|
| No | 4 |
| Ad | Ödemeyi Al ve Fatura Ver |
| Tanım | Reçetedeki ilaçların toplam maliyetine bağlı olarak hasta ödemesi nakit ya da kart ile tahsil edilecek ve fatura verilecek. |
| Girdi Veri Akışı | Süreç 3'ten hesaplanarak gelecek olan "ne kadar ödeme yapılacağı" bilgisi; hastadan yapılacak tahsilat. |
| Çıktı Veri Akışı | Fatura |
| Süreç Tipi | Çevrimiçi (işaretsiz), Otomatik (işaretsiz), El ile (işaretli) |
| Süreç Mantığı | Aşağıdaki pseudocode |
| Çözülmeyen Sorunlar | Nakit ödeme dışında bir ödeme biçiminin kabul edilip edilmeyeceği belli değil. Reçete kayıp ya da unutulmuş ise nasıl bir işlem yapılacak? |

Süreç mantığı alanı:

```text
READ ÖDENECEK_MİKTAR
ÖDEME Al
SELECT CASE
   CASE 1 (ÖDEME büyüktür ÖDENECEK_MİKTAR)
      DO Para üstü ver
         ÖDEME=Tamam
   CASE 2 (ÖDEME eşittir ÖDENECEK_MİKTAR)
      DO ÖDEME=Tamam
   CASE 3 (ÖDEME küçüktür ÖDENECEK_MİKTAR)
      DO ÖDEME=Tamam değil
END SELECT
IF ÖDEME eşittir Tamam
   THEN Fatura ver
ELSE
   Hastaya bilgi ver
END IF
```

Hoca alanları şöyle açıkladı:

- **No ve Ad:** sürecin numarası ve VAD'daki adı.
- **Tanım:** iş analizinden gelen bir parçadır, bir yönetmelik maddesi gibi düşünülebilir; gözlemle görülen işin nasıl yapıldığı burada yazılır.
- **Girdi ve çıktı veri akışları:** VAD'da okların üzerine yazılanlarla aynıdır.
- **Süreç tipi:** El ile çalışan süreç, kullanıcı istediğinde (örneğin menüden seçerek) çalıştırılır ve kullanıcılara hizmet olarak sunulur. Otomatik süreç kendiliğinden çalışır: her gün sonunda faiz hesabı ya da her dönem sonunda genel not ortalaması hesabı gibi.
- **Süreç mantığı:** Buraya akış diyagramı, karar tablosu ya da karar ağacı da konabilirdi; form metin olarak yazıldığı için pseudocode sık kullanılır. Ödeme ödenecek miktardan büyükse para üstü verilir ve ödeme tamamdır; eşitse ödeme tamamdır; küçükse ödeme tamamlanmamıştır. Ödeme tamamsa fatura verilir, değilse hastaya bilgi verilir; belki tekrar ödeme alma adımına dönülmesi gerekir. Hoca bunun daha iyi modellenebileceğini, basit bir örnek olduğunu söyledi.
- **Çözülmeyen sorunlar:** Tanımda "nakit ya da kart" denmiş, ama süreç mantığında yalnız nakit ödeme ele alınmıştır. Reçetesini unutan hasta için belki başka bir veri kaynağından ya da sürece kimlik numarası verilip son reçetelerin istenmesi gerekecektir; bu da yoktur. Bu alan, henüz çözülmemiş konulara dair ileriye yönelik niyet beyanıdır.

Veri akış diyagramındaki **bütün süreçler** için böyle birer form oluşturulmalıdır. Form use case'leri andırır, ama use case'ler daha üst seviyeli ve kavramsaldır; form gerçekleştirmeye daha yakın, seçenekler halinde tanımlanmış bir mantık gösterimidir.

### 10.3 Yapısal dil

Yapısal dil, mantıksal bir ifadeyi standart İngilizce kelimelerin bir alt kümesiyle tanımlamaktır. Ardışık işlemler, durum ya da karar yapıları ve döngüler (belirli sayıda ya da bir koşul doğru olduğu sürece dönen) içerir. Slayttaki bloklar şunlardır (ekrandan, 01:35:00):

| Yapısal dil bloğu | Açıklama | Örnek |
|---|---|---|
| Ardışık Blok Yapısı | Herhangi bir yönlendirmenin bulunmadığı, özel işlemler ya da kontrol gerektirmeyen işlem bloklarıdır. | Eylem #1, Eylem #2, Eylem #3, Eylem #4 |
| Karar İşlem Bloğu | IF ifadesinden sonra verilen koşul doğru ise THEN ifadesinden sonraki eylemler uygulanır; aksi durumda ELSE ifadesinden sonraki eylemler uygulanır. | Aşağıda |
| Durum Kontrol Bloğu | Karar işlem bloğunun özel bir tipidir. Bir koşulun izleyebileceği birden fazla durum varsa ve bu durumlardan biri oluştuğunda diğerleri oluşamıyorsa kullanılan blok yapısıdır. | Aşağıda |
| Döngü Blok Yapısı | Koşul sağlanana kadar tekrarlanması gereken eylemler varsa kullanılır. | Aşağıda |

Karar işlem bloğu örneği:

```text
IF Koşul 1 Doğru
   THEN Eylem#1 uygula
ELSE Eylem#2 uygula
END IF
```

Durum kontrol bloğu örneği:

```text
READ Kontrol-edilecek-değer
SELECT CASE
   CASE 1 (Kontrol-edilecek-deger=Koşul1)
      DO Eylem#1
   CASE 2 (Kontrol-edilecek-deger=Koşul2)
      DO Eylem#2
   CASE 3 (Kontrol-edilecek-deger=Koşul3)
      DO Eylem#3
   CASE 4 (Kontrol-edilecek-deger=Koşul4)
      DO Eylem#4
END CASE
```

Döngü blok yapısı örneği:

```text
DO WHILE Koşul1 doğru oldukça
   Eylem#1
ENDDO
Veya
DO
   Eylem#1
UNTIL Koşul1 doğru olunca
```

(ekrandan, 01:35:00)

Hoca SELECT CASE yapısının IF, ELSE IF, ELSE IF zinciriyle aynı şey olduğunu, döngülere "bütün elemanlar için" ya da "100 kez tekrarla" gibi FOR yapısının da eklenebileceğini söyledi. Algoritmaların akış diyagramları da kullanılabilir, ama burada algoritma değil süreç anlatıldığı için pseudocode tercih edilir.

### 10.4 Stok kontrolü örneği

Hoca bir başka pseudocode örneğinde stok miktarına göre durumları anlattı:

- Stok miktarı kritik stoktan fazlaysa hiçbir şey yapılmaz.
- Kritik stoğa eşitse çalışana "bu ilaçta kritik stok var" bildirimi sunulur.
- Daha da düştüyse otomatik sipariş üretilir; bu, süreç tipindeki otomatik sürece bir örnektir.
- Stok sıfırlandıysa muadil ilaçlar gösterilir.
- Bu durumların dışında, ilacın üretimi durduysa ilacın reçeteye yazılması engellenir.

<!-- BELİRSİZ: bu slaytın karesi yok; koşulların ve eylemlerin tam metni ekrandan doğrulanamadı. -->

## 11. Karar tabloları ve karar ağaçları

### 11.1 Karar tablosu

Karar tablosu da aslında pseudocode ile anlatılabilecek bir şeydir, yalnız yazması daha uzun sürer. Çok bileşenli kurallar ve durumlar olduğunda hangi adımın işletileceğine karar vermek için bir eşleşme tablosu oluşturulur. Slayttaki maddeler şunlardır (ekrandan, 01:40:00):

- Karmaşık kararların mantığını belirleme mekanizması
- Durumlar, Kurallar, İşlemler, Kararlardan oluşur

Slayttaki burs örneği:

| Durum / İşlem | Kural 1 | Kural 2 | Kural 3 | Kural 4 | Kural 5 |
|---|---|---|---|---|---|
| Durum: Disiplin cezası almış | E | H | H | H | H |
| Durum: Not ortalaması > 70 | H | E | H | E | H |
| Durum: Giriş puanı > Giriş ortalaması | H | E | E | H | H |
| İşlem: Okul süresince tam burs | | X | | | |
| İşlem: 1 yıl yarım burs | | | X | | |
| İşlem: Okul süresince yarım burs | | | | X | |
| İşlem: Burs alamaz | X | | | | X |

(ekrandan, 01:40:00)

Hoca tabloyu şöyle çözümledi:

- Üç durum vardır, her biri evet ya da hayır değeri alır. Disiplin cezası 2, not ortalaması 2 (70'ten büyük ya da küçük eşit) seçenekle 4 kombinasyon eder; giriş puanının ortalamadan büyük olup olmaması da 2 seçenek olduğundan toplam $2 \times 2 \times 2 = 8$ olası kombinasyon vardır (python ile doğrulandı).
- Her kombinasyona ayrı işlem tanımlanmaz, bazıları birleştirilebilir. Disiplin cezası almış öğrenci diğer hiçbir şeye bakılmadan burs alamaz (kural 1). Bu yüzden disiplin cezası "evet" olan 4 kombinasyon tek kurala iner ve 8 kombinasyon 5 kurala düşer (ara adım eklendi: $4 + 1 = 5$).
- Disiplin cezası almamış öğrenciler için not ortalaması ve giriş puanı alt tablosu oluşur. Not ortalaması 70'in üzerindeyse ve giriş puanı ortalamadan yüksekse okul süresince tam burs; not ortalaması düşük ama giriş puanı yüksekse bir yıl yarım burs; notu yüksek ama giriş puanı ortalamadan düşükse okul süresince yarım burs; ikisi de düşükse disiplin cezası olmasa da burs alamaz.

Daha çok durum ve kural olduğunda IF, ELSE IF yapıları içinden çıkılmaz hale gelir; karar tabloları bunları okunaklı göstermek için kullanılır.

İkinci örnek bir hasta indirim tablosuydu. Koşullar çalışan hasta, emekli hasta, toplam tutar ≤ 50 ve toplam tutar > 50 idi. Hoca tablonun sadeleştirilebileceğini gösterdi: çalışan ve emekli birbirini dışlar (mutually exclusive); bir hasta ya çalışandır ya emeklidir, bu iki satır tek bir "çalışan hasta mı: evet/hayır" satırına indirgenebilir. Tutar koşulları da aynı anda doğru olamaz, tek satıra indirilebilir. Böylece yalnız iki koşul kalır ve $2^2 = 4$ kombinasyon çıkar. Bu tabloda dörtten fazla eylem vardır: indirim oranı 1, 2, 3, 4 ve ek %10 indirim. Emekli ve toplam tutarı 50'den büyük hastaya hem indirim oranı 4 hem ek %10 indirim uygulanır; yani bir kurala iki eylem birden işaretlenebilir. Hoca aynısını çalışan hasta için de istese ilgili sütuna ikinci bir çarpı koyacağını gösterdi.

<!-- BELİRSİZ: hasta indirim tablosunun karesi yok; hangi kombinasyona hangi indirim oranının düştüğü doğrulanamadı. -->

### 11.2 Karar ağacı

Karar tablosunun alternatifi karar ağacıdır. Daha az karmaşık yapılar için uygundur, görseldir ve olasılık kullanılmaz. Karar tablosu ve karar ağacı birbirine doğrudan dönüştürülebilir.

Burs tablosunun karar ağacı hocanın anlatımıyla şöyledir:

```text
Disiplin cezası almış mı?
├─ Evet → Burs alamaz
└─ Hayır → Not ortalaması > 70 mi?
    ├─ Hayır → Giriş puanı > giriş ortalaması mı?
    │   ├─ Evet → 1 yıl yarım burs
    │   └─ Hayır → Burs alamaz
    └─ Evet → Giriş puanı > giriş ortalaması mı?
        ├─ Evet → Okul süresince tam burs
        └─ Hayır → Okul süresince yarım burs
```

> **Ders sonrası not:** Hoca slayttaki ağaçta not ortalaması 70'in üzerindeki dalda "ortalamadan büyükse yarım burs, değilse tam burs" yazdığını ve bunu büyük olasılıkla ters yazdığını söyledi. Karar tablosuyla tutarlı olan doğru hali yukarıdaki ağaçtır: giriş puanı ortalamadan büyükse okul süresince tam burs, değilse okul süresince yarım burs.

<!-- BELİRSİZ: karar ağacı slaytlarının karesi yok; ağaç anlatımdan ve karar tablosundan kuruldu. -->

Hasta indirim tablosunun ağacında kök hasta tipidir; birinci düzey dallar çalışan ve emeklidir (ikisi aynı anda olamaz). İkinci düzeyde her iki dal için toplam tutar karşılaştırılır (≤ 50 ya da > 50). Yapraklarda indirim oranı 1, 2, 3, 4 bulunur; emekli ve > 50 yaprağında indirim oranı 4 ile ek %10 indirim birlikte yer alır.

Tablo genelde daha karmaşık, çok bileşenli koşulların olduğu durumlarda; ağaç daha basit yapılarda ve görsel takip için kullanılır.

## 12. Veri sözlüğü

### 12.1 Neden gerekir?

Hoca tekerleği bir daha çizdi: süreç kısmı bitti, veri kısmından bahsedildi, kontrol kapsam dışıdır. Ama yalnız VAD ya da ERD çizip bırakmak yetmez; merkeze bunların hepsini formal olarak bağlayacak ve tanımlayacak veri sözlüğü oturtulmalıdır. Slayttaki maddeler şunlardır (ekrandan, 01:45:00):

- Sadece VAD yeterli değil
- Tüm bilişim maddeleri tanımlanmalı
  - Veri Akış Sözlük Girişi
  - Veri Deposu Sözlük Girişi
  - Veri Yapısı Sözlük Girişi
  - Veri Elemanı Sözlük Girişi
  - İşlem Sözlük Girişi
- Veri akış ve işlemler (kısa tanımlanmışlardı) sözlükte tanımlanmalı
- Bileşik veriler öğelerine göre, basit veriler anlamlarına göre tanımlanır

Hoca veri sözlüğünü işin en sevimsiz, yazısı bol kısmı olarak nitelendirdi. Gerekçesi dokümantasyondur: bir analist ekipten ayrılırsa kafasındaki analiz bilgisinin bir yerde tutuluyor olması gerekir ki başkaları kalınan yerden devam edebilsin. Bakım ya da yenileme gerektiğinde de tanımlara dönmek gerekir. Veri sözlüğü daha çok kontratlı, formal, ihale tarzı işlerde yapılır; çevik yaklaşımlarla birlikte yazan pek kalmamıştır. Ama kurumsal hafıza ve proje hafızası açısından önemlidir. Sıkıntısı, model değiştikçe sözlüğün de baştan gözden geçirilip güncellenmesi gerekmesidir.

### 12.2 Sözlük girişleri

Her giriş, belgenin bir sayfası gibi bir kart olarak düşünülebilir.

- **Veri akış sözlük girişi:** Adı (VAD'dan gelir), tanımı (örneğin müşteriye fatura edilecek belge için gerekli bilgiler), nereden geldiği, nereye gittiği, içerdiği veri yapıları (örneğin fatura ve müşteri detayları; bunların kompozit mi elementer mi olduğu) ve ek açıklamalar.
- **Veri deposu sözlük girişi:** Adı, tanımı, tuttuğu veri yapıları, hacmi (örneğin günde yaklaşık 100 kayıt), kimin erişeceği, kimin görme ve değiştirme yetkisi olduğu ve ek açıklamalar.
- **Veri yapısı sözlük girişi:** Her kompozit veri için yazılır. Örneğin satış sipariş kayıtlarının tanımı ve içindeki elemanlar, C'deki bir struct'ın alanları gibi. Slayttaki örnekte yıldız konan elemanlar her parça kaydı için ayrıca oluşturulur. Elemanların elementer mi kompozit mi olduğu belirtilir; tarih gibi kompozit bir eleman ayrıca tanımlanmalıdır.
- **Veri elemanı sözlük girişi:** Elementer her veri için tanım, tip, uzunluk, değer aralığı ve ek ayrıntılar yazılır. Örneğin müşteri numarasının son rakamlarının bir kontrol kodu (hocanın ifadesiyle CRC) ile oluşturulması. Yalnız belirli değerler alan bir eleman (il kodları, ilçe adları gibi) için alabileceği değerler tablo olarak konabilir.

<!-- BELİRSİZ: veri akışı, veri deposu, veri yapısı ve veri elemanı kartlarının slaytları karelerde yok; alanlar anlatımdan aktarıldı. -->

- **İşlem sözlük girişi:** VAD'daki süreçler (2.0, 3.0 ...) de sözlükte tanımlanır. Slayttaki kart şöyledir (ekrandan, 01:50:00):

| Alan | Değer |
|---|---|
| İşlem Adı | 2.0 Sipariş Satış Verisini Gir |
| Girdi | Satış siparişleri |
| İşlem Tanımı | ... yap, eğer değilse ....... yap vb. |
| Çıktı | Girilmiş satış siparişleri |

Hoca süreç tanımlama formunun doğrudan bu girişe yapıştırılabileceğini söyledi.

Sonuç olarak modeldeki bütün bilişim maddeleri (veri akışları, veri depoları, veri yapıları, bunları oluşturan veri elemanları ve süreçler) tanımlanarak sistemin parçaları bir sözlük, bir külliyat halinde barındırılmalıdır.

## 13. Gerçek gereksinim listesi ve SRS (IEEE 830)

Dersin son dakikalarında hoca ekranında gerçek belgeler gösterdi.

### 13.1 Gerçek bir projenin iş gereksinimleri listesi

Listede gereksinim numarası, gereksinim tipi (işlevsel ve işlevsel olmayan birlikte), önem derecesi (örneğin kritik), durumu (yeni mi, var mı) ve zorunlu ya da opsiyonel olduğu yer alıyordu. İşlevsel örnekler: kullanıcıya rol atanabilecek, roller istendiği kadar güncellenebilecek, kullanıcı ve rol oluşturma yalnız belirli role sahip kullanıcılarca yapılabilecek. İşlevsel olmayan örnekler:

- Bir kullanıcı aynı anda birden çok oturumda aktif olamayacak; başka bir bilgisayardan girildiğinde aktif oturum sonlanacak.
- Birden fazla veri tabanı sağlayıcısını destekleyen bir yapı olacak.
- Bir sayfanın output cache olarak saklanması sağlanacak.

Bunlar işlev değildir ama tasarımı etkiler: birden çok veri tabanı desteği adaptörler yazmayı gerektirir; "output cache" yazması kolay bir cümledir ama bütün önbellek mekanizmasının tasarlanmasını gerektirir.

### 13.2 IEEE 830 SRS şablonu

SRS, buraya kadar yazılan, anlatılan ve çizilen bütün gereksinimlerin barındırıldığı belgedir. Standardı IEEE 830'dur. Şablonun yapısı şöyledir:

- 1. Giriş: amaç, belge kuralları, hedef okuyucular, kapsam, referanslar.
- 2. Genel tanım: ürün perspektifi, ürün işlevleri, kullanıcı sınıfları, çalışma ortamı, tasarım ve gerçekleştirme kısıtları, kullanıcı dokümantasyonu, varsayımlar.
- 3. Dış arayüzler: kullanıcı arayüzleri (belki mock-up'larla), donanım, yazılım ve iletişim arayüzleri.
- 4. Sistem özellikleri: doğrudan gereksinim analizi; bütün süreçler, süreç formları, pseudocode'lar ya da use case'ler. Ekrandaki sayfada "4.1 System Feature 1" altında 4.1.1 Description and Priority, 4.1.2 Stimulus/Response Sequences, 4.1.3 Functional Requirements (REQ-1, REQ-2) alt başlıkları görülüyordu (ekrandan, 01:55:00).
- 5. Diğer işlevsel olmayan gereksinimler: performans gereksinimleri ve yazılım kalite kriterleri (ekrandan, 01:55:00).

Belgede kimin hangi tarihte ne değiştirdiğini ve hangi sürüme gelindiğini gösteren bir revizyon geçmişi (revision history) mutlaka tutulur.

<!-- BELİRSİZ: 1-3. bölümlerin alt başlıkları karede görünmüyor; anlatımdan aktarıldı. -->

### 13.3 Örnek SRS belgeleri

Basit bir örnek, bir kişisel yatırım (hocanın ifadesiyle kişisel harcama) yönetim sistemi (Personal Investment Management System) için hazırlanmış SRS'tir: amaç, kapsam, tanımlar ve kısaltmalar, genel tanım, use case'lerin adı ve kısa tanımıyla tablo halinde listesi, sonra işlevsel gereksinimler başlığı altında her use case için birincil aktör, ön koşul, ana senaryo ve alternatif senaryo (use case 1'den 11'e kadar), performans ve tasarım kısıtları. Eklerde belirli hesaplar (örneğin faiz) için kullanılacak formüller ve kullanıcı arayüzlerinin taslak çizimleri (butonlar, sol menü, ana ekran, navigasyon) yer alır.

Bir başka belgede iş kuralları ve iş gereksinimleri (işlevsel / işlevsel olmayan), kullanıcı tipleri, kullanım senaryolarının listesi ve her use case'in adım adım tablo halinde yazılışı vardı. Use case'ler metin olarak da tablo olarak da yazılabilir.

## Örnek Sorular

**Soru 1** (ekrandan, 01:05:00): Aşağıdaki bağlam VAD ve düzey 0 VAD verilmiştir. Hata nerededir?

```text
Bağlam VAD:
[Varlık 1] --A--> (0 Süreç 0) --B--> [Varlık 2]

Düzey 0 VAD:
[Varlık 3] --A--> (1.0 Süreç 1.0)
[Varlık 4] --C--> (1.0 Süreç 1.0)
(1.0) --A Türevi--> (2.0 Süreç 2.0)
(1.0) --B Türevi--> (2.0 Süreç 2.0)
(2.0) --B--> [Varlık 2]
```

> **Çözüm (derste verilen cevap, ekrandan, 01:15:00):** Düzeyler arasında tutarlılık bozulmuştur. Bağlam diyagramında yalnız Varlık 1 ve Varlık 2 varken düzey 0'da Varlık 3 ve Varlık 4 ile C akışı yoktan ortaya çıkmıştır; Varlık 1 ise düzey 0'da yoktur. Süreç 1.0 ve 2.0 ile A Türevi ve B Türevi iç akışları sorun değildir, iç süreçler ve akışlar alt düzeyde ortaya çıkabilir. Varlık 2'ye giden B de tutarlıdır. Slayttaki çözüm: "Varlık 3 ve Varlık 4 bağlam VAD'da yer almalıdır." Bağlam VAD'da Varlık 1 → A, Varlık 3 → A ve Varlık 4 → C akışları Süreç 0'a girer, Süreç 0 → B → Varlık 2. Hoca bir alternatif de söyledi: Varlık 3 aslında Varlık 1'in hatalı adıysa A akışı tek varlıktan gelir, ama Varlık 4 ve C akışı yine de bağlam diyagramına eklenmelidir.

**Soru 2** (derste sözlü, 01:15:35): Düzey 0'da Süreç X'e "A ve B" etiketli tek bir ok girmektedir. Düzey 1'de ise A akışı X.1'e, B akışı X.2'ye girmektedir. Bir sorun var mıdır?

> **Çözüm (derste verilen cevap):** Vardır. A ve B iki farklı veri akışıdır; kompozit olabilirler ama iki farklı kompozit yapı tek bir okta gösterilemez. Düzey 0'da da Süreç X'e ayrı bir A oku ve ayrı bir B oku girmelidir. Bir ok az çizmek tasarruf gibi görünse de iki farklı akışı aynıymış gibi birleştirmek kurallara aykırıdır.

<!-- BELİRSİZ: Soru 2'nin slaytı karelerde yok; diyagram anlatımdan kuruldu. -->

**Soru 3** (derste sözlü, 01:37:45): Burs karar tablosunda disiplin cezası, not ortalaması > 70 ve giriş puanı > giriş ortalaması olmak üzere üç evet/hayır durumu vardır. Kaç olası kombinasyon vardır ve tablo neden 5 kurala iner?

> **Çözüm (derste verilen cevap, sayı python ile doğrulandı):** $2 \times 2 \times 2 = 8$ kombinasyon vardır. Disiplin cezası alan öğrenci diğer koşullara bakılmadan burs alamadığı için disiplin cezası "evet" olan 4 kombinasyon tek kurala birleşir; geriye disiplin cezası "hayır" olan 4 kombinasyon kalır ve toplam $1 + 4 = 5$ kural olur.

**Soru 4** (derste sözlü, 01:40:42): Hasta indirim tablosunda "çalışan hasta", "emekli hasta", "toplam tutar ≤ 50" ve "toplam tutar > 50" satırları vardır. Tablo nasıl sadeleştirilir ve kaç kombinasyon kalır?

> **Çözüm (derste verilen cevap):** Çalışan ve emekli birbirini dışladığı için tek bir "çalışan hasta mı" satırına, iki tutar koşulu da tek bir "toplam tutar > 50 mi" satırına indirilir. İki koşul kalır ve $2^2 = 4$ kombinasyon çıkar.

## Dersin Toparlaması

Bu derste yapısal (fonksiyonel) çözümlemenin araçları işlendi. Gereksinim analizi modeli süreç, veri ve kontrol spesifikasyonlarından ve merkezdeki veri sözlüğünden oluşur; derste süreç tarafı ayrıntılı, veri tarafı kısaca ele alındı, kontrol kapsam dışında bırakıldı. Süreçler veri akış diyagramlarıyla modellenir: dış varlıklar, süreçler, veri depoları ve aralarındaki adlandırılmış, tek yönlü veri akışları. Diyagramlar bağlam düzeyinden birinci ve ikinci düzeye doğru açılır ve düzeyler arasında dış varlıklar ile dış akışlar tutarlı kalmalıdır. Süreç kutularının içi süreç tanımlama formlarıyla, form içindeki mantık ise pseudocode, karar tablosu ya da karar ağacıyla anlatılır. Bütün öğeler veri sözlüğünde tanımlanır ve sonunda hepsi IEEE 830 yapısındaki bir SRS belgesinde toplanır.

Sonraki derste problem uzayının nesneye yönelik yaklaşımla nasıl modelleneceği, kavramsal modelin sınıf temelinde nasıl ifade edileceği ve bunun için senaryoların nasıl kullanılacağı işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
