# Ders 6 Çalışma Özeti

## Genel Konular

- Bilgi tutulacak "şeylerin" özellikleri: ilişki ve özellik (ekrandan, 00:10:00)
  - İlişki (relationship): belirli şeyler arasında doğal olarak oluşan bağlantıdır. İlişki her zaman iki yönlüdür ve iki yönden de okunur.
  - Kardinalite (çokluk): ilişkinin sayısal yönüdür (bir, çok). İlişkiler ikili (binary), tekli (unary), üçlü (ternary) ya da n'li (n-ary) olabilir.
  - Zorunluluk ve seçimlik: ilişkide karşı tarafta en az bir eleman bulunması gerekiyorsa zorunlu (mandatory), sıfır da olabiliyorsa seçimlik (optional) ilişki vardır.
  - Özellik (attribute): bir şey hakkında tutulan tek bir bilgi parçasıdır. Örneğin bir öğrenci için bölüm, ad, soyad, numara, doğum tarihi.
  - Hangi özelliklerin tutulacağı ezbere seçilmez. Analizde sistemin hangi çıktıları üreteceği (karne, sertifika gibi) ve bu çıktıların nerede kullanılacağı araştırılır; çıktıda görünmesi gereken her bilgi saklanmalıdır.
  - Özellik tanımı geneldir (ör. müşteri numarası, ad, soyad, ev telefonu, iş telefonu); varlığın her bir satırında bu tanımlara karşılık gelen değerler bulunur.
- Veri varlıkları ve nesneler (ekrandan, 00:15:00)
  - Veri varlığı (data entity): geleneksel bilgi sistemi yaklaşımında hakkında veri saklanan şeydir. Varlık ilişki diyagramıyla (ERD) modellenir, genelde ilişkisel veri tabanıyla gerçekleştirilir.
  - Veri varlıkları işlemlerden ayrı durur: işlem 1, 2, 3 ayrı tanımlanır ve işlem gerektiğinde varlıkla veri alışverişi yapılır.
  - Nesne: veriyi ve o veriyi işleyen metotları tek birimde toplar (kapsülleme). Metotlar mesajlarla tetiklenir.
  - Nesne sınıfları veri varlıklarından fazla bilgi taşır: genelleştirme/özelleştirme hiyerarşileri (kalıtım) ve bütün-parça ilişkileri (aggregation) içerir.
- ER diyagramında kardinalite okuma: müşteri ve sipariş
  - Soldan sağa: bir müşteri sıfır ya da çok sipariş verebilir (müşteri kaydı olup henüz sipariş vermemiş olabilir).
  - Sağdan sola: her siparişin karşısında bir ve yalnız bir müşteri vardır. Müşteri tanımlanmadan sipariş kaydı girilemez.
  - Sipariş ile sipariş kalemi: bir sipariş en az bir, en çok çok sayıda kalem içerir (bir fatura en az bir kalem içerir).
- Müşteri, sipariş ve sipariş kalemleri örneği (ekrandan, 00:20:00)
  - Bir müşteri iki sipariş vermiştir (her birinde üç kalem), bir müşterinin henüz siparişi yoktur, bir müşteri tek sipariş vermiştir (üç kalem).
- Sınıf diyagramı örnekleri
  - Sınıf sembolü üç bölmelidir: sınıf adı, özellikler (ad, adres, telefon), metotlar.
  - Bankacılık örneği: bir müşterinin sıfır ya da çok hesabı olabilir; hesap türü de gösterilir.
  - Ders kaydı örneği (ilişki sınıflı sınıf diyagramı): Course 1 — 0..* CourseSection; CourseSection 0..* — 0..* Student; ilişki sınıfı CourseEnrollment (grade, postGrade) (ekrandan, 00:25:00).
- Yapısal yaklaşımla gereksinim (sistem) analizi modeli (ekrandan, 00:30:00)
  - Modelin üç amacı: müşteri ihtiyaçlarını açıklamak; yazılım tasarımı için temel oluşturmak; yazılım bittikten sonra ihtiyaçları karşılayıp karşılamadığını onaylayacak ölçütleri belirlemek.
  - Modelin bileşenleri: merkezde veri sözlüğü; çevresinde varlık ilişki diyagramı (veri/nesne tanımı), veri akış diyagramı (süreç spesifikasyonu) ve durum geçiş diyagramı (kontrol spesifikasyonu).
  - Veri sözlüğü (data dictionary): veri hakkında veri; uygulamada kullanılan ve üretilen bütün veri nesnelerinin, özelliklerin ve işlemlerin tanımı.
- Veri akış diyagramları (VAD / DFD) paketi
  - Aşamalı çizilir: önce bağlam (taslak, özet, context) diyagramı, sonra birinci düzey ayrıntılı, sonra ikinci düzey ayrıntılı diyagram.
  - Semboller: kare/dikdörtgen dış varlık, köşeleri yuvarlatılmış dikdörtgen işlem, bir ucu açık dikdörtgen veri deposu (D1, D2...), oklar giden-gelen veri.
  - Öğrenci bilgi sistemi örneği: bağlam diyagramı ve birinci seviye diyagram (ekrandan, 00:35:00 ve 00:40:00).
  - Doktor muayenehanesi faturalama örneği: bağlam diyagramı (ekrandan, 00:45:00), birinci düzey diyagram (ekrandan, 00:55:00), 2.0 işleminin ikinci düzey diyagramı (ekrandan, 01:05:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağlam diyagramında tek işlem bulunur
  - Sistem ne kadar karmaşık olursa olsun bağlam diyagramında kesinlikle birden fazla işlem kullanılmaz. Tek işlemin adı bütün bilgi sistemini kapsayan ad olmalıdır (ör. "Öğrenci Bilgi Sistemi", "Faturalama Sistemi").
  - Bağlam diyagramında ER diyagramındaki gibi kardinalite ve zorunluluk yoktur; sistemin dış varlıklara hangi bilgiyi gönderdiği ve onlardan hangi bilgiyi aldığı gösterilir.
- Okların üzerinde veri yazar
  - Oklar olay ya da fonksiyon değildir; işlemler, varlıklar ve veri depoları arasında giden-gelen veriyi (girdi-çıktı) gösterir.
- Tekrar kullanılan varlık
  - Aynı dış varlık diyagramda ikinci kez çizildiğinde yeni bir varlık sanılmasın diye ikinci çiziminin köşesine çapraz bir çizgi konur.
- Düzeyler arasında tutarlılık
  - İkinci düzey diyagramdaki alt işlemler, birinci düzeydeki üst işlemin alt işlemleri olmalıdır (2.0 Fatura Hazırlama → 2.1, 2.2, 2.3).
  - Üst işleme giren ve çıkan bütün veri akışları ikinci düzey diyagramda da aynı şekilde görünmelidir.
  - İkinci düzey diyagram her işlem için zorunlu değildir; yalnız gerçekten alt işlemi olan işlemler için çizilir.
- Özellikler analizde çıktılara bakılarak belirlenir
  - Hangi varlık hakkında hangi bilginin tutulacağı, sistemin üreteceği çıktılar araştırılarak belirlenir.

## Kısa Tekrar Notları

- İlişki iki yönlüdür; kardinalite (bir/çok) ve zorunluluk (zorunlu/seçimlik) ile tanımlanır.
- Özellik: bir şey hakkında tek bir bilgi parçası; tanım genel, değerler satır satır.
- Veri varlığı işlemlerden ayrıdır; nesne veri ile metotları birlikte tutar ve mesajla çalışır.
- Müşteri–Sipariş: bir müşteri 0..çok sipariş; her siparişin tam bir müşterisi var. Sipariş–Kalem: bir sipariş 1..çok kalem.
- Yapısal analiz modeli: veri sözlüğü merkezde; ERD (veri), VAD (süreç), durum geçiş diyagramı (kontrol).
- VAD paketi: bağlam → birinci düzey → ikinci düzey.
- Bağlam diyagramı: tek işlem, sistemin adı, dış varlıklarla veri alışverişi.
- Birinci düzey: işlemler 1.0, 2.0, 3.0, 4.0 diye numaralanır; veri depoları D1, D2...
- İkinci düzey: 2.0'ın alt işlemleri 2.1, 2.2, 2.3; giriş-çıkış akışları üst düzeyle tutarlı.
- Bazı kaynaklar birinci düzey ayrıntılı diyagrama "Diyagram 0" (sıfırıncı düzey) der.
- CASE araçları bu tutarlılık kurallarını denetleyerek çizim yaptırır.

## Detaylı Açıklamalar

- **İlişkiler ve kardinalite.** Analizde önce hangi şeyler hakkında bilgi tutulacağı, sonra bunların özellikleri ve aralarındaki ilişkiler belirlenir. Bir ilişki iki yönden okunur. Örneğin öğrenci ile ders arasında bir öğrenci bir dönemde hiç ders almamış olabilir ya da çok sayıda ders almış olabilir; bu, sıfır ya da çok (seçimlik) bir ilişkidir. Buna karşılık bir siparişin ya da faturanın en az bir kalemi olmak zorundadır; bu yönde ilişki zorunludur ve UML gösteriminde `1..*` olarak yazılır. ER diyagramındaki müşteri–sipariş örneğinde sipariş tarafındaki işaret "sıfır ya da çok", müşteri tarafındaki işaret "bir ve yalnız bir" anlamına gelir. Hoca diğer olasılıkları da saydı: "bir ya da çok" (en az bir zorunlu) ve "sıfır ya da bir" (karşıda eleman olmayabilir, olursa yalnız bir tane).
  <!-- BELİRSİZ: ER kardinalite sembollerinin (crow's foot) gösterildiği slaytın karesi yok; sembol çizimleri altyazıdan aktarılamadı. -->
- **Veri varlığı ile nesne farkı.** Ekrandaki şekilde (ekrandan, 00:15:00) üstte "veri varlıkları işlemlerden ayrıdır" başlığı altında girdi alan ve çıktı veren bir yapı içinde process 1, process 2, process 3 kutuları ve bunlarla çift yönlü okla bağlı ayrı bir "Data entity" silindiri görülür. Altta "nesneler veriyi ve veriyi işleyen metotları tek birimde kapsüller" başlığıyla bir "Object" kutusu vardır; içinde "nesneye ait veri" ve "veriyi işleyen metotlar" bulunur, dışarıyla mesajlarla haberleşir.
- **Genelleştirme ve bütün-parça.** Nesne sınıfları üst sınıfların bilgilerini kalıtımla paylaşır. Bütün-parça (aggregation) ilişkisine örnek olarak bilgisayar ve parçaları (işlemci, bellek, klavye) verildi.
- **İlişki sınıflı ders kaydı diyagramı (ekrandan, 00:25:00).** Course sınıfı (courseNumber, title, creditHours; addCourse) ile CourseSection (sectionNumber, startTime, roomNumber; openSection, closeSection) arasında `1` — `0..*` ilişki vardır: bir ders o dönem hiçbir şubede açılmamış olabilir, ama her şube kesin olarak bir derse karşılık gelir (ders kataloğunda olmayan ders açılamaz). CourseSection ile Student (studentID, name, major; admitStudent, recordDegree) arasında iki yönde de `0..*` vardır. Bu ilişkinin kendisi CourseEnrollment ilişki sınıfıdır (grade özelliği, postGrade metodu); kesikli çizgiyle ilişki çizgisine bağlanır.
- **Yapısal analiz modeli (ekrandan, 00:30:00).** Ekrandaki halka şeklinde merkezde "Veri Sözlüğü", çevresinde "Varlık İlişki Diyagramı", "Veri Akış Diyagramı" ve "Durum Geçiş Diyagramı", en dış halkada sırasıyla "Veri Nesne Tanımı", "Süreç Spesifikasyonu" ve "Kontrol Spesifikasyonu" yazar. Süreç spesifikasyonu, veri üzerinde uygulanacak iş süreçlerinin ayrıntılı tanımıdır ve VAD'larla yapılır. Kontrol spesifikasyonu, durumlar arası geçişlerde nasıl bir kontrol mekanizması olduğunu tanımlar. Hoca pratikte en çok ERD ve VAD'ın kullanılacağını söyledi.
- **Öğrenci bilgi sistemi bağlam diyagramı (ekrandan, 00:35:00).** Slayttaki tanım: "Sistemin dışsal birimlerinin sistem ile ilişkisini basitçe gösterildiği diyagramdır. Tek bir işlem olur ve sistemin ismi ile belirtilir."

  ```text
  Öğrenci --(Ders Seçimi)--> [Öğrenci Bilgi Sistemi] --(Sınıf listesi)--> Öğretim Üyeleri
  Öğrenci <--(Sınav sonuçları)-- [Öğrenci Bilgi Sistemi] <--(Sınav sonuçları)-- Öğretim Üyeleri
  ```

- **Öğrenci bilgi sistemi birinci seviye diyagramı (ekrandan, 00:40:00).**

  ```text
  Öğrenci --(Ders Seçimi)--> [Ders Seç]
  [Ders Seç] --(Öğrenci-seçilen dersler bilgisi)--> (Öğrenci-Ders veritabanı tablosu)
  [Ders Seç] --(Öğrenci-seçilen ders bilgileri)--> [Sınav sonuçlarını sisteme ekle]
  [Sınav sonuçlarını sisteme ekle] --(Sınıf listesi)--> Öğretim Üyeleri
  Öğretim Üyeleri --(Sınav sonuçları)--> [Sınav sonuçlarını sisteme ekle]
  [Sınav sonuçlarını sisteme ekle] --(Sınav sonuçları)--> (Öğrenci-Not veritabanı tablosu)
  [Sınav sonuçlarını sisteme ekle] --(Öğrenci-not bilgisi)--> [Sınav sonucu görüntüle]
  (Öğrenci-Not veritabanı tablosu) --(Sınav sonuçları)--> [Sınav sonucu görüntüle]
  [Sınav sonucu görüntüle] --(Sınav sonuçları)--> Öğrenci (tekrar çizilen varlık)
  ```

- **Faturalama sistemi bağlam diyagramı (ekrandan, 00:45:00).** Doktor → Muayene Kaydı → Faturalama Sistemi; Hasta → Sigorta Formu → Faturalama Sistemi; Faturalama Sistemi → Hasta Faturası → Hasta; Faturalama Sistemi → Sigorta Faturası → Sigorta. Hoca daha ayrıntılı düşünülseydi sigortadan hastanın sigorta durumunu bildiren bir veri de alınabileceğini ekledi.
- **Faturalama birinci düzey diyagramı (ekrandan, 00:55:00).** İşlemler: 1.0 Muayene Kaydı İnceleme ve Ücret Hesabı, 2.0 Fatura Hazırlama, 3.0 Hasta Ödemeleri İşleme, 4.0 Sigorta Ödemeleri İşleme. Veri depoları: D1 Ücret Listeleri, D2 Hastalar, D3 Sigorta Şirketleri, D4 Muhasebe Kayıtları. Doktorun muayene kaydındaki her iş ücret listesindeki karşılığıyla eşleştirilir, doğrulanmış ücret 2.0'a gider; 2.0, hastadan sigorta formunu, D3'ten sigorta şirketi adı ve adresini, D2'den hasta adresini alarak hastaya ve sigorta şirketine fatura gönderir; ödemeler 3.0 ve 4.0'da işlenip D4'e yazılır.
- **2.0 Fatura Hazırlama ikinci düzey diyagramı (ekrandan, 01:05:00).** 2.1 Hastanın Sigorta Durumunun İncelenmesi (girdiler: hastadan Sigorta Formu, 1.0'dan Doğrulanmış Ücret), 2.2 Listelenen Miktarla Faturayı Kıyaslama (girdiler: 2.1'den Sigorta ve Ücret Bilgisi, D3'ten Sigorta Şirketi Adı ve Adresi; çıktı: Sigorta Şirketi'ne Sigorta Faturası), 2.3 Hastanın Ödemesi Gereken Tutarın Faturalanması (girdiler: 2.2'den Hastanın Ödemesi Gereken Tutar, D2'den Hasta Adresi; çıktı: Hasta'ya Hasta Faturası).
- **Araçlar.** VAD gibi diyagramları çizmek için CASE (Computer Aided Software Engineering) araçları kullanılabilir; bu araçlar düzeyler arası tutarlılık kurallarını gözeterek çizdirir. Nesneye yönelik diyagramlar için Violet gibi açık kaynaklı, kullanımı kolay araçlar vardır; VAD için açık kaynaklı araçlar daha azdır.
- **Yaklaşımla ilişkisi.** VAD genellikle yapısal yaklaşımın analiz modelidir, ama nesneye yönelik yaklaşımda da bazı şeyleri anlatmak için kullanılabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
