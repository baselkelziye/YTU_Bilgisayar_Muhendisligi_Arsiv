# Ders 8 Genişletilmiş Notu: Sistem Tasarımı: Ön Tasarım, Yapı Diyagramı ve Ayrıntılı Tasarım

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Analizden tasarıma geçiş
- 2. Ön tasarım (genel tasarım)
- 3. Altyapıyı belirleme süreci
- 4. Yazılım değerlendirme ve satıcı firma seçimi
- 5. Finansal satın alma türü
- 6. Sistem mimarisi ve yapı diyagramı
- 7. Yapı diyagramı örnekleri
- 8. Sınav sorularının çözümü üzerinden tekrar
- 9. Ayrıntılı tasarım
- 10. Çıktı tasarımı
- 11. Girdi tasarımı ve kodlama
- 12. Veri tabanı tasarımı ve ara birim tasarımı
- 13. Yapısal ve nesneye yönelik tasarımın farkı
- Örnek Sorular
- Dersin Toparlaması

## 1. Analizden tasarıma geçiş

Bu ders, dönemin analiz kısmı bittikten sonra tasarım konusunun açıldığı derstir. Hoca önce şimdiye kadar yapılanı hatırlattı: sistem analizinde hem geleneksel (klasik) yöntemle veri akış diyagramlarının nasıl kullanıldığı, hem de nesneye yönelik yaklaşımla kullanım durumu (use case) diyagramlarının nasıl kullanıldığı görülmüş, ayrıca veri analizi de yapılmıştı. Şimdi sıra bu analiz sonuçlarını tasarıma dönüştürmektedir.

Sistem tasarımı, belirlenmiş bir dizi gereksinimin ana sistem içinde işlevsel bir öğe hâline getirilmesi, başka bir deyişle yazılımı hazırlanacak biçime dönüştürülmesidir. Tasarım iki aşamada gerçekleştirilir:

- **Ön tasarım** (genel tasarım da denir),
- **Ayrıntılı tasarım.**

Derste kullanılan slaytlar Türkçe hazırlanmış "Sistem Tasarımı" sunumudur (ekrandan, 00:10:00); dersin ikinci yarısında aynı konunun devam sunumuna geçildi (ekrandan, 00:25:00).

## 2. Ön tasarım (genel tasarım)

Ön tasarımda sistemin belirlenmiş amaç ve hedeflere nasıl ulaştırılabileceğine ilişkin tanımlar geliştirilir. Bu aşamada yapılanlar şunlardır:

- Sistemin işlevleri tanımlanır.
- Gereksinimlere karşılık verecek modüller belirlenir.
- Hazırlanacak yazılım bağımsız öğelere ayrılır.
- Veri yapıları oluşturulur.
- Modül ara birimleri kurulur.
- Kısıtlar belirlenir; yani yazılımı geliştirirken hangi kısıtlamalarla karşı karşıya olunduğu ortaya konur.

Ön tasarım çalışmalarının sonunda bir rapor düzenlenir. Bu rapor incelenir, kabul edilir, gerekirse yeniden düzenlenir.

Hoca genel tasarımın kapsamının yalnız yazılım olmadığını özellikle belirtti. Genel tasarım, sistemin altyapısını belirlemeyi ve sistem mimarisini oluşturmayı kapsar (slayt küçük resminden, ekrandan, 00:20:00). Altyapı tarafında hangi donanım öğelerinin kullanılacağı, hangi platformun seçileceği ve bu platformun kuruluşunda neler yapılacağı belirlenir; yeni yazılım ürünleri alınacaksa alım kararları da burada verilir. Yazılım tarafında ise nasıl bir sistem mimarisi oluşturulacağına karar verilir. Analiz aşamasının sonuçları, yani gereksinimler, bu çalışmaların girdisidir.

## 3. Altyapıyı belirleme süreci

Slaytta bu süreç, işletmede var olan donanımın, yazılımın ve ağ yapısının belirlenmesiyle başlayan ve amacı önerilen sistem çözümüne uygun altyapıyı ortaya koymak olan bir akış olarak verildi (ekrandan, 00:10:00). Akış yukarıdan aşağıya şöyledir:

```text
Var olan bilgisayar donanım ve yazılım envanterini belirleme
        |
İş yüklerinin tahmini
        |
   +----+-----------------+
   |                      |
Donanımı değerlendirme   Yazılımı değerlendirme
   |                      |
   +----+-----------------+
        |
Satıcı firmayı belirleme
        |
Finansal satın alım türünü belirleme
```

Hoca akışı şöyle özetledi: önce işletmede var olan donanım ve yazılım, yani envanter belirlenir. Ardından yeni sistemin altyapısı için bunlardan hangilerinin kullanılacağı, hangilerinin kullanılmayacağı ve hangilerinin satın alınması gerektiği ortaya çıkar. Satın alınacaklar için de satıcı firmanın nasıl seçileceği gündeme gelir.

### 3.1 Envanter belirleme

Envanter belirleme, sistemin şu andaki öz kaynaklarının çıkarılmasıdır. Sistem analisti var olan altyapının durumunu görmek için her teçhizat için şunları belirler:

- Teçhizatın modeli ve üreticisi.
- Teçhizatın durumu: kullanılıyor mu, kullanılmıyor mu, bakıma ihtiyacı var mı, çalışır durumda mı.
- Teçhizatın yaşı ve planlanan yaşı, yani bundan sonra ne kadar daha kullanılabileceği.
- Teçhizatın işletme içindeki fiziksel yeri.
- Teçhizattan sorumlu çalışan ya da bölüm.
- Finansal durumu: işletmenin kendi malı mı, leasing ile mi alınmış, kiralanmış mı.

### 3.2 İş yükü tahmini

İş yükü tahmininde sistem analisti, sistemin var olan ve planlanan iş yüklerini hesaplar ve donanım altyapısının kapasitesinin bu iş yüklerine göre yeterli olup olmadığını belirler. Hoca disk kapasitesini örnek verdi: haftada, ayda, yılda ne kadar kayıt işleneceği ve ne kadar verinin saklanması gerektiği hesaplanır. Aynı soru bütün donanım birimleri için ve ağ için de sorulur: ağda ne kadar iletim gerekecek, var olan altyapı buna yeterli mi?

Slaytta ayrıca bu hesapların tam olarak yapılmasıyla, işletmenin sahip olduğu donanımın her yeni sistemin kurulmasıyla gereksiz yere büyümesinin ve karmaşıklaşmasının önlenebileceği yazıyordu (slayt küçük resminden, ekrandan, 00:15:00).

## 4. Yazılım değerlendirme ve satıcı firma seçimi

### 4.1 Paket yazılımın değerlendirilmesi

Günümüzde paket yazılımların sayısı arttığı için, donanım seçiminde olduğu gibi yazılım seçiminde de sistem analisti satıcılarla karşı karşıya gelir. Bu yüzden analist, belirli ölçütlere göre yazılım alım kararını yönetimle birlikte verir (slayt küçük resminden, ekrandan, 00:15:00). Hoca bu tür yazılımlara örnek olarak altyapıda kullanılacak bir veri tabanı yönetim sistemini, bir proje yönetim programını ya da anahtar teslim geliştirilen bir uygulamanın parçası olarak alınacak hazır bir insan kaynakları paketini verdi. Bu ölçütlere bakılarak hangi işin hazır paketlerle yapılacağına, hangi işin yeniden geliştirileceğine karar verilir.

Ölçütler slayttaki tabloda şöyle verildi (ekrandan, 00:15:00):

| Yazılım gereksinimi | Yazılım özellikleri |
|---|---|
| Performans etkinliği | İhtiyaç duyulan tüm işleri yerine getirme; tüm işleri istenildiği şekilde yerine getirme; iyi tasarlanmış ekran çıktıları; yeterli kapasite |
| Performans verimliliği | Hızlı cevap zamanı; verimli giriş; verimli çıkış; verimli veri saklama; verimli yedekleme |
| Kullanım kolaylığı | İyi tasarlanmış kullanıcı ara birimi; yardım menüleri; esnek ara birim; yeterli geri besleme; hata düzeltme |
| Esneklik | Girdi seçeneği; çıktı seçeneği; diğer yazılımlarla birlikte kullanılma |
| Dokümantasyon kalitesi | İyi organizasyon; yeterli çevrim içi kaynak; web sitesinde sık sorulan soruların (FAQ) bulunması |
| Üretici desteği | Teknik destek; ürün güncellemesinin web sitesi üzerinden yapılabilmesi |

Hoca "performans etkinliği" ile "performans verimliliği" arasındaki farkı şöyle açıkladı: etkinlik, yazılımın istenen işleri yerine getirip getirmediği, iyi tasarlanmış ekran çıktıları ve yeterli kapasitesi olup olmadığıdır; verimlilik ise bunları ne kadar hızlı ve kaynak harcamadan yaptığıdır (hızlı cevap, verimli giriş, çıkış, saklama ve yedekleme).

### 4.2 Satıcı firmayı belirleme

Bir yazılımı, örneğin insan kaynakları paketini almaya karar verildikten sonra hangi firmadan alınacağına karar verilir. Hoca bunu bir örnekle somutlaştırdı: alınacak bir veri tabanı yönetim sisteminin iki bayisi olabilir; hangisinden alınacağı bu aşamada belirlenir.

Satıcı değerlendirmesindeki en önemli etken, satıcının kullanıcıya sunduğu hizmetlerdir ve bunlar dört temel grupta değerlendirilir (slayt küçük resminden, ekrandan, 00:15:00; ayrıntılar anlatımdan):

- **Donanım desteği:** ürünün kalitesi, garantisi.
- **Yazılım desteği:** toplam yazılım ihtiyacını karşılıyor mu; yanına eklemeler gerekiyor mu, özel programlama gereksinimi var mı; garantisi nedir.
- **Kuruluş ve eğitim:** kurulum, işletmenin zaman programına uyuyor mu; eğitim veriliyor mu; müşteri hizmetleri nasıl yürüyecek.
- **Bakım:** rutin bakım işlemleri ve acil durumda cevap verme süresi.

Hoca ön tasarımın bu kısmını şöyle toparladı: önce envanter belirlenir, sonra var olan envanterin kullanılıp kullanılamayacağına bakılır; iş yükü tahmin edilir; kullanılabilecek yazılımlar değerlendirilir ve alım kararı verilir; son olarak satıcı firma seçilir.

## 5. Finansal satın alma türü

İşletme finansal durumuna bağlı olarak bilgisayar donanımını satın almak yerine leasing yapabilir ya da kiralayabilir; üç yöntemin de avantajları ve dezavantajları vardır (slayt küçük resminden, ekrandan, 00:25:00). Slayttaki karşılaştırma tablosu (ekrandan, 00:25:00):

| | Avantajları | Dezavantajları |
|---|---|---|
| Satın alma | Uzun dönemde leasing ve kiralamadan ucuz olması; sistemin değiştirilebilmesi; vergi indirimi sağlaması; tam kontrol | İlk ödemenin yüksek olması; eskime riski; seçimin yanlış yapılması sonucu yatırımın batma riski; tam sorumluluk |
| Leasing | Sermayenin bağlanmaması; finansmana ihtiyaç olmaması; kira bedelinden düşük olması | Sözleşme bittiğinde işletmenin sisteme sahip olamaması; ödemenin gecikmesi durumunda yüksek faiz oranı; satın almadan daha pahalı olması |
| Kiralama | Sermayenin bağlanmaması; finansmana ihtiyaç duyulmaması; sistemin kolayca değiştirilmesi; genelde bakım ve garantinin fiyat kapsamında olması | İşletmenin sistemin gerçek sahibi olmaması; satıcı kendi riskini üstlendiği için kira bedelinin çok yüksek olması |

Hoca satın almanın, uzun süre kullanılabilecek bir ürün söz konusuysa daha iyi olduğunu söyledi. Satın almada tam kontrol vardır ama bununla birlikte tam sorumluluk da gelir: seçim yanlış yapıldıysa ürün işletmenin elinde kalır.

> **Hocanın vurgusu:** Bunlar işin ekonomik tarafıdır, ama teknik kişiler olsanız da zaman zaman bu tür kararlara katılmanız gerekebilir; işin bu yönünü göz ardı etmeyin.

## 6. Sistem mimarisi ve yapı diyagramı

### 6.1 Mimari tasarım

Ön tasarımın yazılımla ilgili kısmı mimari tasarımdır. Mimari tasarımda programın ana yapısal öğeleri arasındaki ilişkiler belirlenir. Ana amaç, modüler bölümlere ayrılmış bir program yapısı geliştirmek ve modüller arasındaki ilişkilerin denetimini göstermektir (ekrandan, 00:25:00, slayt küçük resmi; anlatım 00:26:50). Bu kapsamda şunlar ele alınır:

- Hangi modüllerin olacağı.
- Modüller arasındaki ilişkiler ve bu ilişkilerin tanımları.
- Modülerlik ve yeniden kullanılabilirlik.
- Modüller arasındaki veri alışverişi ve ortak veri kullanımı.

Ayrıca verinin program içinde akışını sağlayacak ara birimler tanımlanır. <!-- BELİRSİZ: Slaytta ve anlatımda "program yapısı ve veri yapısı birbirine karıştırılabilir/karıştırılmakta" deniyor; cümlenin kastı (birbirine bağlanması mı, karıştırılmaması gerektiği mi) net değil. --> Klasik yaklaşımda sistem mimarisi **yapı diyagramı** (structure chart) ile açıklanır.

Hoca yapı diyagramının, yazılım geliştiricinin asıl işinin başladığı yer olduğunu söyledi: gereksinim analizinde çizilen veri akış diyagramları, bu diyagramdan yararlanılarak modül tasarımına dönüştürülür. Önce temel alt modüller belirlenir, sonra her alt modülü gerçekleştirecek alt modüller belirlenir ve bu, gereken düzeye kadar sürdürülür.

### 6.2 Yapı diyagramı sembolleri

Hoca sembolleri örnekler üzerinden tanıttı, sonra toparladı:

- **Dikdörtgen:** modül.
- **Modülleri birleştiren çizgi:** üstteki modülün alttaki modülü çağırması, yani alt bölünme.
- **Ucu içi boş yuvarlak olan küçük ok:** modüller arasında veri aktarımı. Aktarılan şey sayısal ya da karakter bilgidir. Okun yönü, verinin hangi modülden hangisine gittiğini gösterir.
- **Ucu içi dolu yuvarlak olan küçük ok:** kontrol akışı. Bir sayıya ya da bilgiye bakılarak verilmiş bir karar, yani lojik bilgi (evetse çalış, hayırsa çalışma gibi) gönderiliyorsa bu sembol kullanılır.
- **Eşkenar dörtgen:** seçim (if). İki alt modülden yalnız birinin çalışacağını gösterir; iki modülün bağlantısının arasına yerleştirilir.
- **Alt modülleri kapsayan yarım daire ok:** tekrar (döngü). Kapsadığı modüller, örneğin her kayıt için yeniden çalışır.

Modüller veri akış diyagramındaki gibi numaralandırılabilir (bkz. Bölüm 7.3).

> **Hocanın vurgusu:** Yapı diyagramının hedefi, gereksinim analizinde çizilen veri akış diyagramlarını modül yaklaşımıyla yazılım tasarımına dönüştürmektir. Modül sayısı VAD'daki işlem sayısına eşit olmak zorunda değildir; daha çok da olabilir, daha az da. Yapı yaygın bir yelpaze biçiminde de olabilir, daha hiyerarşik de. VAD'ı en iyi nasıl modüler hâle getiriyorsanız tasarımı öyle yaparsınız.

## 7. Yapı diyagramı örnekleri

### 7.1 Ücret bordrosu programı

Slayttaki ilk örnek, bir ders kitabından alınmış İngilizce bir ücret bordrosu (payroll) yapı diyagramıdır (ekrandan, 00:30:00). Programın işi şudur: zaman kartlarına göre her çalışanın kaç saat çalıştığını, fazla mesai yapıp yapmadığını bulmak; buna göre vergiyi ve ödenecek miktarı hesaplamak; bordro çıktısını almak. Bu yüzden üç ana modül vardır. Karedeki hiyerarşi şöyledir:

```text
Payroll program  (altındaki üç modülü kapsayan döngü oku)
|-- Enter time cards
|     |-- Enter employee time card
|     |-- Read employee record
|     |-- Validate time card
|-- Calculate amounts
|     |-- Get employee pay rates
|     |-- Calculate pay amounts
|           |-- Calculate base amount
|           |-- Calculate overtime amount
|           |-- Calculate taxes
|           |-- Calculate other deductions
|-- Output payroll
      |-- Update employee record
      |-- Write payroll transactions
      |-- Update general ledger
```

Bağlantılar üzerindeki veri adları (karede okunduğu kadarıyla, ekrandan, 00:30:00):

- Payroll program ile Enter time cards arasında: Validated time card information.
- Payroll program ile Calculate amounts arasında: Validated time card, Payroll amounts.
- Payroll program ile Output payroll arasında: Payroll information, Employee information.
- Enter time cards altında: Time card, Employee name, Employee data, Valid flag.
- Calculate amounts altında: Employee pay/tax rates, Rates, Payroll amounts.
- Calculate pay amounts altında: Job category, Hours, Base pay, Overtime amount, Taxes, Dependents, Deduction amount, Deduction information.
- Output payroll altında: Payroll information.

Hoca diyagramı şöyle okudu: en üstteki modülün altında bir yarım daire ok vardır; bu bir tekrarlılık, yani döngüdür: her çalışan için bu modüller yeniden çalıştırılır. Zaman kartı modülü geçerli zaman bilgisini (ödemenin kaç saat üzerinden yapılacağını) okuyup ana programa gönderir; bu bilgi hesaplama modülüne geçer. Hesaplama modülünden bordroya yazılacak miktar, çalışanın ayrıntılı bilgileriyle (örneğin hangi bölümde çalıştığı) birlikte bordro çıktısı modülüne aktarılır. Okların ucundaki içi boş yuvarlaklar veri aktarımını gösterir. Hoca bu örnekte kontrol akışı olmadığını söyledi.

> **Ders sonrası not:** Karedeki "Valid flag" (geçerlilik bayrağı) akışı, adından da anlaşıldığı gibi bir doğrulama sonucunu taşır; büyük olasılıkla ders kitabında içi dolu yuvarlakla, yani kontrol akışı olarak çizilmiştir. <!-- BELİRSİZ: Kare çözünürlüğünde bu okun ucunun dolu mu boş mu olduğu seçilemiyor. -->

### 7.2 Yeni sipariş oluşturma

İkinci örnek, daha önceki derslerde VAD örneklerinde de sık geçen sipariş konusudur (ekrandan, 00:35:00; 00:40:00):

```text
Create new order
|-- Record customer information   (alt modüller arasında seçim: eşkenar dörtgen)
|     |-- Get customer information
|     |-- Create customer record
|-- Record order
|     |-- Get order information
|     |-- Process order item      (döngü: her sipariş kalemi için)
|           |-- Get requested item
|           |-- Get product/inventory items
|           |-- Create order line item
|-- Process order transaction
|     |-- Check credit authorization
|     |-- Write transaction
|-- Produce confirmation
```

Bağlantılar üzerindeki veri adları (karede okunduğu kadarıyla, ekrandan, 00:35:00):

- Create new order altında: Customer information; Order header, Order line items, Customer information; Order financials, Customer information; Order line items, Order information.
- Record customer information altında: Customer information.
- Record order altında: Order information, Order ID.
- Process order transaction altında: Credit authorization, Credit information, Order and payment information.
- Process order item altında: Item Id, Qty; Price, QOH; Item information.

Hoca diyagramı şöyle anlattı: idare eden (en üstteki) modül yeni bir sipariş yaratır. Önce müşteri bilgi kaydına erişilir ve müşteri bilgisi alınır, sonra bu müşteri için yeni bir sipariş kaydı açılır ve siparişin tarihi verilir. Ardından siparişteki her bir ürünle ilgili işlemler yapılır ve en sonda onay alınır. Bu diyagramdaki oklar da içi boş yuvarlak uçludur, yani yalnız veri akışı vardır.

Bu örneğin farkı seçim ve döngü sembolleridir:

- **Seçim:** Müşteri bilgisi alınırken önce şu sorulmalıdır: bu müşteri var olan bir müşteri mi? Öyleyse bilgisi hemen aktarılır. Yeni bir müşteriyse yeni bir müşteri kaydı oluşturulur. Bu iki durumlu bir iştir; "Get customer information" ile "Create customer record" arasındaki eşkenar dörtgen ikisinden yalnız birinin çalışacağını gösterir. Hoca, kitaptaki şekilde dörtgenin tam yerine konmadığını, iki modülün arasında olması gerektiğini belirtti.
- **Döngü:** Sipariş kaydında her alınacak birim için aynı işlemler tekrarlanır: istenen birim alınır, ürünün envanterde olup olmadığına ve fiyatına bakılır, yeni bir sipariş satırı eklenir. Karede "Process order item" altında da bir eşkenar dörtgen görülür; hoca burada da bir modülün koşula bağlı olarak çalışacağını ya da çalışmayacağını söyledi.

### 7.3 Envanter güncelleme ve raporlama

Üçüncü örnek, numaralandırmanın nasıl yapılabileceğini gösteren basit bir diyagramdır (ekrandan, 00:45:00):

```text
1.0 Envanter Güncelleme ve Raporlama
|-- 2.0 Envanter Güncelleme
|     |-- 2.1 İşlem Girişi
|     |-- 2.2 İşlem Doğrulama
|     |-- 2.3 İşlem Düzeltme
|     |-- 2.4 Dosya Güncelleme
|-- 3.0 Raporlama
      |-- 3.1 Günlük Raporlama
      |-- 3.2 Özet Raporlama
```

En üstteki temel işin altında iki temel iş vardır: güncelleme ve raporlama. Güncelleme için alt işlemler 2.1-2.4, raporlama için 3.1-3.2 diye numaralanmıştır. Veri akış diyagramında işlemler nasıl numaralandırılıyorsa yapı diyagramında da modüller öyle numaralandırılabilir.

### 7.4 Ara öncesi soru-cevap

**Soru:** Bir kütüphane sisteminde kayıtlı ve kayıtsız üyeler aktör olarak var ve kayıtsız üyelerin yapabildiği her şeyi kayıtlı üyeler de yapabiliyor. Use case diyagramında hepsinden ayrı ayrı ok mu çıkarmak gerekir, yoksa bu bir kalıtım gibi gösterilebilir mi? Benzer biçimde, bir iş yerinde yetkililer de çalışan oldukları için çalışanların yaptığı her şeyi yapabiliyor, ayrıca ek bir işleri var.

**Cevap:** Hoca önce bunun doğrudan bir kalıtım gösterimi olmadığını, aynı okların her aktörden ayrı ayrı çizilmesi gerektiğini söyledi; ardından kalıtımdaki genellemenin orada gösterilebileceğini de ekledi. İkinci örnek için yetkililerden de aynı kullanım durumlarına okların tek tek çıkarılmasını önerdi.

> **Ders sonrası not:** UML kullanım durumu diyagramlarında aktörler arası genelleştirme (actor generalization) tanımlıdır: özel aktörden (kayıtlı üye, yetkili) genel aktöre (kayıtsız üye, çalışan) içi boş üçgen uçlu bir ok çizilir ve özel aktör, genel aktörün bütün kullanım durumlarını devralır. Hocanın cevabı bu konuda kesin değildi; okları tek tek çizmek de anlamca doğru bir modeldir.

Aynı öğrencinin, use case diyagramından sonra raporlamanın her aktör için ayrı mı yapılacağı sorusuna hoca, durumu canlandıramadığı için kesin bir cevap vermedi.

## 8. Sınav sorularının çözümü üzerinden tekrar

Aradan sonra hoca, analiz konularını kapatan sınavdaki iki uygulama sorusunun çözümünü gösterdi. Amacı, ikinci sorudaki veri akış diyagramını yapı diyagramına dönüştürme alıştırması için bir başlangıç vermekti. Soruların metni ve çözümleri "Örnek Sorular" bölümündedir; burada yalnız hocanın vurguladığı noktalar verilmiştir.

- **Use case sorusu:** Soru, temel kullanım durumlarını ve aktörleri ayırt edebilmeyi ölçmek için sorulmuştu; işlemlerin niteliği ya da ayrıntılı ilişkiler (include, extend gibi) istenmemişti. Hoca, cevabın bu kadar basit olduğunu, amaçlananın "hangi aktör hangi işi yapıyor" sorusunu en basit hâliyle modellemek olduğunu söyledi. Kullanım durumlarının bir sistem sınırı dikdörtgeni içine alınması da kabul edilir.
- **Veri akış diyagramı sorusu:** En sık görülen hata VAD kuralının çiğnenmesiydi.

> **Hocanın vurgusu:** Veri akış diyagramında dış varlıktan dış varlığa, dış varlıktan veri saklama ortamına (dosyaya) ya da dosyadan dosyaya doğrudan veri aktarımı olamaz; arada mutlaka bir işlem bulunmalıdır.

Hoca ayrıca bir iki işlemi yazıp olayın bütününü toparlayamamanın da eksik bir çözüm olduğunu belirtti.

## 9. Ayrıntılı tasarım

Genel tasarımda uygulamanın altyapısının nasıl oluşturulacağı, mimari tasarımda da uygulamanın modüler yapısı belirlenmişti. Ayrıntılı tasarımda ön tasarım aşamasında oluşturulan modüller alt modüllere ayrılır ve ayrıntılı olarak tanımlanır; dosyalar ya da tablolar, ekran görüntüleri ve rapor biçimleri tasarlanır, programlar için ayrıntılı planlar düzenlenir (ekrandan, 00:20:00). Hoca bunu "kodlamaya kadar gelecek şekilde" bir tasarım olarak tanımladı.

Bu aşamada şu sorular cevaplanır: çıktılar nasıl görüntülenecek, girdiler nasıl alınacak, ekran yapıları nasıl olacak, veri tabanı tasarımı ve program tasarımı nasıl olacak? Slaytta tasarım sürecindeki ilk işin çıktıların belirlenmesi olduğu, böylece girdi ve saklama ortamlarının ve veri tabanı gereksinimlerinin ortaya konduğu yazıyordu (slayt küçük resminden, ekrandan, 00:35:00). Ayrıntılı tasarımın kapsamı:

- Çıktı tasarımı,
- Girdi tasarımı,
- Veri tabanı tasarımı,
- Program tasarımı,
- Ara birim tasarımı.

## 10. Çıktı tasarımı

Çıktı, bilgi sisteminin kullanıcılara verdiği bilgidir. Sistem analistleri en faydalı çıktıyı elde etmek için kullanıcılarla etkileşimli çalışmalar yaparlar. Çıktı tasarımında şunlar önemlidir (ekrandan, 01:25:00):

- Belirlenen amaca hizmet etme,
- Kullanıcı için anlamlı olma,
- Uygun miktarda olma,
- Çıktıların hangi kullanıcılara dağıtılacağının doğru belirlenmesi,
- Çıktının zamanında sağlanması (günlük, aylık, yıllık ya da koşula bağlı raporlar),
- Doğru çıktı yönteminin (ortamının) seçilmesi.

Çıktıların kullanıcıları etkileyecek biçimde yönlendirilmesi şunlarla gerçekleştirilir (ekrandan, 01:30:00):

- Bilgilerin alfabetik, kronolojik ya da maliyete göre sıralanması,
- Kabul edilebilir sınırların belirlenmesi,
- Grafik tipinin, renginin ve ölçeğinin ayarlanması.

## 11. Girdi tasarımı ve kodlama

### 11.1 Girdi tasarımının ilkeleri

Girilen verinin kalitesi, çıktı olarak elde edilen bilginin kalitesini belirler: girdi tasarımında hatalı veri girilmesine izin verilirse hatalı çıktı alınır. Girdi tasarımında kullanım kolaylığı, uyumluluk, doğru girdi alınması, iyi bir ekran tasarımı, görünüm güzelliği, basitlik ve etkinlik sağlanmalıdır.

> **Hocanın vurgusu:** En önemlisi GIGO kuralıdır. Girdi ekranları öyle tanımlanmalıdır ki kullanıcı hatalı veri giremesin; kullanıcının hatasız giriş yapması için en kolay biçimi sağlayan bir yapı kurulmalıdır.

> **Ek bilgi (derste anlatılmadı):** GIGO, İngilizce "Garbage In, Garbage Out" (çöp girerse çöp çıkar) deyiminin kısaltmasıdır.

### 11.2 Kodlama

Hoca girdi tasarımındaki kodlamanın yazılım geliştirme anlamındaki kodlama olmadığını belirtti. Buradaki kodlama, girilen verilere daha sonra sınıflama yapılmasını kolaylaştıracak, mümkün kılacak kodlar vermektir. Derste verilen örnekler:

- **Yaş:** Yaş bilgisi doğrudan girilirse zamanla eskir; bunun yerine doğum tarihi girilip yaş sürekli güncel tutulabilir.
- **Öğrenim durumu:** "lise", "ortaokul" gibi serbest metin girilirse sonradan sınıflama yapılamaz. İlkokula 1, ortaokula 2, liseye 3, üniversiteye 4 kodu verilirse sınıflama kolaylaşır.
- **Hastalıklar:** Hastalık adı yazılırsa sınıflanması mümkün olmaz; bunun için uluslararası bir hastalık kodlama sistemi geliştirilmiştir.
- **Öğrenci numaraları:** Üniversitede öğrenci numaraları fakülteye ve bölüme göre kodlanmıştır; numaraya bakıldığında öğrencinin hangi fakülte ve bölümden olduğu anlaşılır. Bu kodlar öğrenci bilgi sistemi yazılımı yapılırken düşünülerek verilmiştir.

İyi bir kodlamada dikkat edilmesi gereken durumlar (ekrandan, 01:20:00):

- Kodlamanın mümkün olduğunca kısa olması gerekir.
- Kodlama kolay değişmeyecek biçimde olmalıdır; koda başlamadan önce kesin olarak karar verilmiş olmalıdır.
- Tekrarlanmamalı, tekil (unique) olmalıdır.
- Birbiriyle karıştırılabilecek sembollerden kaçınılmalıdır.
- Kodlamada kısaltmalar varsa anlamlı olmalıdır.
- Araya eleman eklemeye izin verecek biçimde değişikliğe izin verilebilmelidir.

> **Hocanın vurgusu:** İyi bir planlama ve analiz yapılmazsa, sistem geliştirilmeye ve kullanılmaya başlandıktan sonra bu kodları yeniden düzenlemek çok zordur. Kodlar analiz aşamasında, en geç girdi tasarımı sırasında son biçimini almalıdır.

Hoca bu konuyu derste bir öğrenciye sorarak tekrar ettirdi (bkz. Örnek Sorular). Tartışmanın sonunda vardığı sonuç şuydu: kodlama veriyi kısa ve standart biçime oturtur, sayısal olarak daha kolay işlenir ve sınıflamaya, istatistiğe açık hâle getirir. Aksi hâlde örneğin "çalışanlar arasında kaç ilkokul mezunu var?" sorusu, değerler farklı biçimlerde girildiği için cevaplanamaz.

## 12. Veri tabanı tasarımı ve ara birim tasarımı

### 12.1 Veri tabanı tasarımı

Veri yapısının program yapısı üzerindeki etkisi nedeniyle veri tabanı tasarımı, sistem tasarımının kalitesini çok önemli ölçüde etkiler. Gereksinim analizi ve spesifikasyonu aşamasında tanımlanmış olan veri yapılarının mantıksal gösterimleri seçilmelidir. Anlamlı bilgi alma ve veri bütünlüğü, yani veri güvenliği önem taşır.

### 12.2 Ara birim tasarımı

Ara birim, yani ekran yapıları tasarlanırken şunlar önemlidir:

- Etkinlik.
- Kullanıcının alışkanlıklarına uygunluk.
- Hatayı en aza indirme: her bilgiyi yeniden yazdırmak yerine açılır (pull-down) menülerden seçtirme.
- Kullanıcının alıştığı bir tarzda veri girişi.
- Ergonomi.

Hoca renklerin de önemli olduğunu söyledi. Gözü yormayan renkler kullanılmalıdır: beyaz üzerine mavi ya da mavi üzerine beyaz gözü yormaz, ama yeşil ile kırmızı gözü çok yorar. Renklerin çok canlı ve parlak olması da yorucudur; bu renk ergonomisine dikkat etmek gerekir.

Bir yazılım çalışırken farklı farklı ekranlar gelir. Bunların hepsinin aynı tarzda olması, her birinin farklı bir tarzda olmaması önemlidir. Kullanıcının alıştığı bir yapı tutturulduktan sonra bütün ekranlar o biçimde olmalı, kullanıcı şaşırtılmamalı, alışkanlıkları değiştirilmemelidir. Bu ilke hem çıktı hem girdi tasarımında geçerlidir. Bilgi verme ekranları, program kesildiğinde gelen ekranlar ve bir hata olduğunda hatanın tipini yansıtan mesajlar da ara birim tasarımının konusudur.

Hoca bu kavramların ders kitabında daha ayrıntılı bulunabileceğini ve konuya oradan da bakılmasını önerdi.

## 13. Yapısal ve nesneye yönelik tasarımın farkı

Ders sonunda bir öğrenci, anlatılan tasarımın yapısal yönteme mi ait olduğunu sordu.

**Soru:** Bugün anlatılan tasarım yapısal bakış açısıyla yapılan tasarım mı?

**Cevap:** Girdi tasarımı, çıktı tasarımı, kodlama gibi ayrıntılı tasarım tanımları iki yaklaşım için de geçerlidir. Değişen, kullanılan diyagramlar ve ifade biçimidir; klasik yaklaşımla nesneye yönelik yaklaşım arasındaki fark budur. Yapısal yaklaşımda mimari için yapı diyagramı, veri için ER diyagramı çizilir. Nesneye yönelik tasarımda ise sıralama (sequence) diyagramı ve ayrıntıyla oluşturulmuş sınıf diyagramı kullanılır; bu diyagramlar sonraki derslerde görülecektir.

## Örnek Sorular

### Soru 1: Sınav süreçleri için kullanım durumu diyagramı

(ekrandan, 01:00:00; çözüm ekrandan, 01:05:00)

Üniversitede öğrenci bilgi sistemi yenilenecektir. İş analistine, sınav süreçlerini inceleyerek modellemesi görevi verilmiştir. İş analisti yaptığı gözlemler sonucunda şu sonuçları elde etmiştir:

- Sınavları hoca hazırlamaktadır.
- Sınava öğrenciler girmektedir.
- Hocalar ve asistanlar gözetmenlik yapmaktadır.
- Sınavları hoca notlandırmaktadır.
- Öğrenciler notlara itiraz edebilmekte, itirazı asistan değerlendirmektedir.

Problemin kullanım senaryosu modelini oluşturmak için kullanım senaryosu diyagramını (use case diagram) çiziniz.

**Çözüm (derste gösterilen):** Üç aktör ve beş kullanım durumu vardır.

| Aktör | Bağlı olduğu kullanım durumları |
|---|---|
| Hoca | Sınav Hazırlama, Sınav Gözetimi, Sınav Notlandırma |
| Asistan | Sınav Gözetimi, Not İtirazı |
| Öğrenci | Sınava Girme, Not İtirazı |

"Sınav Gözetimi" hem hocaya hem asistana, "Not İtirazı" hem öğrenciye (itirazı yapan) hem asistana (itirazı değerlendiren) bağlıdır. Hoca, kullanım durumlarının bir sistem sınırı dikdörtgeni içine alınmasının da aynı biçimde kabul edildiğini söyledi.

### Soru 2: Araba kiralama şirketi için birinci düzey VAD

(derste sözlü, 01:07:18; çözüm ekrandan, 01:10:00)

Araba kiralama şirketinin işlerini yürütecek bilgi sistemi için şu bilgiler toplanmıştır (soru metni hocanın okumasından kurulmuştur): Yöneticiler kiralama fiyatlarını belirler; fiyat bilgileri saklanır. Galeri, envantere yeni araç ekler; araçların bilgileri kayıt olarak saklanır. Müşteri araç kiralayabilir; bunun için isteklerini bildirir. Şirket fiyat ve araç kayıtlarından bilgi alarak isteklere uygun kiralama işlemini oluşturur; araç bilgileri müşteriyle paylaşılır ve müşterinin hangi kiralama işlemlerini yaptığı kayıt altında saklanır. Araç iade edildiğinde kilometre bilgisiyle ödeme kaydı oluşturulur ve bu kayıt da saklanır. Birinci düzey ayrıntılı veri akış diyagramını çiziniz. <!-- BELİRSİZ: Ekrandaki soru slaytı yalnız küçük resim olarak göründü; metin altyazıdaki okumadan kuruldu. -->

**Çözüm (derste gösterilen):**

- Dış varlıklar: Yönetici, Galeri, Müşteri.
- İşlemler: 1.0 Fiyat Belirleme, 2.0 Araç Kiralama, 3.0 Araç İade Etme, 4.0 Araç Ekleme.
- Veri depoları: D1 Fiyat Dosyası, D2 Kiralama Dosyası, D3 Araç Dosyası, D4 Ödeme Dosyası.

| Kaynak | Hedef | Veri akışı |
|---|---|---|
| Yönetici | 1.0 Fiyat Belirleme | Kira Bedelleri |
| 1.0 Fiyat Belirleme | D1 Fiyat Dosyası | (etiketsiz) |
| Galeri | 4.0 Araç Ekleme | Araç Bilgileri |
| 4.0 Araç Ekleme | D3 Araç Dosyası | Araç Bilgileri |
| D1 Fiyat Dosyası | 2.0 Araç Kiralama | Fiyat Bilgileri |
| D3 Araç Dosyası | 2.0 Araç Kiralama | Araç Bilgileri |
| Müşteri | 2.0 Araç Kiralama | İstekler |
| 2.0 Araç Kiralama | Müşteri | Araç Bilgileri |
| 2.0 Araç Kiralama | D2 Kiralama Dosyası | Kiralama Bilgileri |
| D2 Kiralama Dosyası | 3.0 Araç İade Etme | Kiralama Bilgileri |
| Müşteri | 3.0 Araç İade Etme | Kilometre Bilgisi |
| 3.0 Araç İade Etme | D4 Ödeme Dosyası | Ödeme Bilgileri |

Hocanın anlatımıyla: 1.0 ve 4.0 işlemleri kiralama için ön gereksinimlerdir. Araç kiralamada fiyat dosyasından aracın fiyatı, araç dosyasından aracın künyesi alınır; müşteri isteklerini bildirir, ona uygun araç bilgileri verilir ve müşteri birini kiralar. Kiralama dosyasında hangi müşterinin hangi aracı hangi tarihler arasında kiraladığı durur. 3.0 işleminde müşteri kilometre bilgisini verir, kiralama dosyasından aracın kim tarafından kiralandığı alınır ve ödeme bilgileri ödeme dosyasına kaydedilir. Diyagramda hiçbir akış iki dış varlık, bir dış varlık ile bir depo ya da iki depo arasında doğrudan değildir; her akışın bir ucunda işlem vardır.

### Soru 3: Araba kiralama VAD'ından yapı diyagramı

(derste sözlü, 01:13:41)

Soru 2'deki birinci düzey ayrıntılı veri akış diyagramına göre bu uygulamanın yapı diyagramını (structure chart) çiziniz. Modüller 1.0, 2.0, 3.0, 4.0 işlemlerinin doğrudan karşılığı olmak zorunda değildir; hiyerarşik ya da farklı seviyelendirilmiş bir yapı kurulabilir. Amaç, VAD'ı en iyi tasarıma dönüştürmektir.

> **Çözüm (derste verilmedi):** Aşağıdaki, olası çözümlerden biridir. Kiralama ve iade müşteri işlemleri, fiyat belirleme ve araç ekleme ise yönetim işlemleri olarak iki dala ayrılmıştır. Veri akışları (içi boş yuvarlak uçlu oklar) parantez içinde, akış yönüyle verilmiştir.
>
> ```text
> 0 Araç Kiralama Sistemi
> |-- 1 Yönetim İşlemleri
> |     |-- 1.1 Fiyat Belirle        (Kira bedelleri: aşağı)
> |     |     |-- 1.1.1 Fiyat Dosyasına Yaz
> |     |-- 1.2 Araç Ekle            (Araç bilgileri: aşağı)
> |           |-- 1.2.1 Araç Dosyasına Yaz
> |-- 2 Müşteri İşlemleri
>       |-- 2.1 Araç Kirala          (İstekler: aşağı; Araç bilgileri: yukarı)
>       |     |-- 2.1.1 Uygun Araçları Getir   (İstekler: aşağı; Araç bilgileri: yukarı)
>       |     |-- 2.1.2 Fiyat Bilgisini Getir  (Araç bilgisi: aşağı; Fiyat bilgileri: yukarı)
>       |     |-- 2.1.3 Kiralama Kaydı Yaz     (Kiralama bilgileri: aşağı)
>       |-- 2.2 Araç İade Al         (Kilometre bilgisi: aşağı)
>             |-- 2.2.1 Kiralama Kaydını Getir (Araç: aşağı; Kiralama bilgileri: yukarı)
>             |-- 2.2.2 Ücreti Hesapla         (Kiralama bilgileri, Kilometre: aşağı; Tutar: yukarı)
>             |-- 2.2.3 Ödeme Kaydı Yaz        (Ödeme bilgileri: aşağı)
> ```
>
> İsteğe göre "2.1.1 Uygun Araçları Getir" modülüne, isteğe uyan her araç için tekrar eden bir döngü oku eklenebilir. Uygun araç bulunup bulunmadığı bilgisi bir kontrol akışı (içi dolu yuvarlak uçlu ok) olarak 2.1 modülüne döndürülebilir.

### Soru 4: Girdi tasarımında kodlama

(derste sözlü, 01:27:27)

Girdi tasarımında kodlama nedir? Örneğin hastalık kodlama sistemi neden kullanılır? Personel dosyasına öğrenim durumu (ilkokul, ortaokul...) nasıl girilmelidir ve neden?

**Cevap (derste verilen):** Öğrenci önce girdilerde hata kontrolü yapılması ve hatasız veri alınmasının garanti edilmesi gerektiğini söyledi; hoca soruyu öğrenim durumu örneğine getirdi. Öğrenim durumu metin olarak değil, ilkokul, ortaokul, lise, üniversite için 1, 2, 3, 4 gibi kodlarla girilmelidir. Bu, veriyi kısa ve belli bir standarda oturtur; hoca bunun asıl kazancının sınıflamaya ve istatistiğe açık olmak olduğunu vurguladı. Değerler farklı biçimlerde serbest metinle girilirse "çalışanlar arasında kaç ilkokul mezunu var?" sorusu cevaplanamaz. Hastalık kodları ve bölüme göre kodlanmış öğrenci numaraları da aynı amaçla kullanılır.

### Soru 5: Ayrıntılı tasarımın alt bölümleri

(derste sözlü, 01:32:45)

Ayrıntılı tasarımın alt bölümlerini söyleyiniz; ayrıntılı tasarımda nelere bakılır?

**Cevap (derste verilen):** Ayrıntılı tasarım; girdilerin, çıktıların, uygulamanın (programların) ve veri tabanının ayrıntılı olarak tasarlandığı aşamadır. Alt bölümleri çıktı tasarımı, girdi tasarımı, veri tabanı tasarımı, program tasarımı ve ara birim tasarımıdır (alt bölüm listesi slayttan, bkz. Bölüm 9).

## Dersin Toparlaması

Bu derste analizden tasarıma geçildi. Sistem tasarımı ön (genel) tasarım ve ayrıntılı tasarım olarak iki aşamada ele alındı. Ön tasarımın altyapı tarafında envanter belirleme, iş yükü tahmini, donanım ve yazılım değerlendirme, satıcı firma seçimi ve satın alma, leasing ya da kiralama kararı görüldü. Yazılım tarafında ise mimari tasarım ve onun klasik yaklaşımdaki aracı olan yapı diyagramı, sembolleriyle (modül, veri ve kontrol akışı, seçim, döngü) ve üç örnekle (bordro, sipariş, envanter) incelendi. Sınavdaki use case ve VAD sorularının çözümleri üzerinden, VAD'ı yapı diyagramına dönüştürme alıştırması verildi.

Ayrıntılı tasarımda çıktı, girdi, veri tabanı, program ve ara birim tasarımı tanıtıldı; girdi tasarımında GIGO ilkesi ve sınıflamayı mümkün kılan kodlama, ara birim tasarımında tutarlılık ve renk ergonomisi vurgulandı. Ders, bu ayrıntılı tasarım ilkelerinin nesneye yönelik yaklaşımda da geçerli olduğu, ancak orada yapı diyagramı ve ER diyagramı yerine sıralama diyagramı ve ayrıntılı sınıf diyagramının kullanılacağı bilgisiyle kapandı; nesneye yönelik tasarım sonraki derslerin konusudur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
