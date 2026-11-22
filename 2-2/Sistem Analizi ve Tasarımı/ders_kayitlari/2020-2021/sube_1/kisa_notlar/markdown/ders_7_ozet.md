# Ders 7 Çalışma Özeti

## Genel Konular

- Alan modeli (domain model)
  - Alan modeli, bilgi sistemi hazırlanacak uygulama alanındaki önemli kavramları ya da nesneleri UML sınıf diyagramı notasyonuyla görselleştirir. Bir tür "görsel sözlük"tür; yazılım sınıflarının resmi değildir (ekrandan, 00:05:00).
  - Önemli bilgiyi tanımlamaya, ilişkilendirmeye ve görselleştirmeye yardım eder; sonraki tasarım sınıflarına ilham verir ve alan ile yazılım arasındaki "temsil boşluğunu" (representational gap) azaltır.
  - Örnek: hastane bilgi sisteminde hastalar, doktorlar ve yapılan işlemler hakkında bilgi tutulur. Derste ana örnek video kiralama mağazasıdır: mağaza, müşteriler, stoktaki videolar ve bunlar arasındaki ilişkiler.
  - Aday kavram listesiyle başlanır, kavramsal sınıf diyagramı (analiz aşamasındaki sınıf diyagramı) en basit haliyle kurulur ve her iterasyonda eklemelerle geliştirilir.
  - Bağlantılar (association) ok yönünde okunur: "Video mağazası videoları depolar." Çokluluk (multiplicity) `1`, `0..1`, `*` (sıfır ya da çok), `1..*` (bir ya da çok) gibi gösterilir; belirli bir sayı da yazılabilir ama yaygın değildir.
  - Nitelik yönergesi (ekrandan, 00:10:00): Başka bir kavramsal sınıfı gösteren bilgi nitelik olarak yazılmamalıdır. `Customer` içinde `rentedVideos: List of Video` ya da `Video` içinde `renter: Customer` yazmak "daha kötü"dür; "daha iyi"si iki sınıfı `Customer 1 — Rents — 1..* Video` bağlantısıyla bağlamaktır.
  - Ders sonundaki hedefler (ekrandan, 00:15:00): alan modeli için UML sınıf diyagramı notasyonunu okuyup yazabilmek, alan modeli oluşturabilmek, yönergeleri uygulayabilmek, alan modelini diğer ürünlerle (artifact) ilişkilendirebilmek.
- Nesneye yönelik analizde aşamalar
  - Önce iş modelleme (business modeling) ile alan modeli çıkarılır; bilgi toplandıkça model büyür.
  - Sonra gereksinimler: use case metinleri ve use case diyagramları yazılır. Ekip metinle diyagramı paralel ya da sırayla hazırlayabilir. Ardından sistem sıralama (sequence) diyagramlarına geçilir.
  - En son tasarım modeli gelir. Tasarım kalıpları (patterns) tasarım aşamasında anılır, ayrıntısı sonraki derslerdedir.
  - Kaynak olarak Craig Larman'ın "Applying UML and Patterns" kitabı ve Alistair Cockburn'ün "Writing Effective Use Cases" yaklaşımı gösterildi (ekrandan, 00:20:00).
- Use case (kullanım durumu, kullanım öyküsü)
  - Use case'ler işlevsel gereksinimleri yakalamanın yoludur: sistemi kullanan "hikayeler"dir. Bir hedef belirlenir, sistemin bu hikayeyi nasıl gerçekleştirdiği gösterilir; birincil (primary) aktör ve destekleyici aktörler verilir.
  - Use case seviyeleri: önce genel bakış, sonra ayrıntı. Her şeyi baştan tek bir use case'e koymak doğru değildir; veri akış diyagramlarındaki gibi kademe kademe gidilir. Ekrandaki soru: "Negotiate a Supplier Contract", "Rent Videos", "Log In", "Start Up" hedeflerinden hangisi yararlı seviyededir? (ekrandan, 00:25:00)
  - Hem metin bir belge hem diyagram üretilir. Diyagramda da önce bağlam düzeyinde genel bir diyagram, sonra ayrıntılı diyagramlar çizilir.
- Use case diyagramı
  - Örnek: Video Store Information System (ekrandan, 00:30:00). Aktörler Clerk, Customer, Administrator (çöp adam) ve «actor» Credit Authorization Service (dikdörtgen). Use case'ler: Pay Fines, Rent Items, Manage Memberships, Log In, Manage Inventory, Manage Users.
  - Semboller: elips = use case (alt işlem), çöp adam = canlı aktör, dikdörtgen = canlı olmayan aktör (başka bir yazılım, servis, sensör), büyük dikdörtgen = sistem sınırı.
  - Birincil aktör genellikle solda, destek aktörleri sağda çizilir.
  - Slayttaki uyarı: diyagrama fazla zaman harcamayın; use case çalışması metin yazmaktır.
- Use case belgesi (fully dressed format)
  - Bölümler: use case adı, birincil aktör, paydaşlar ve ilgileri, ön koşullar, son koşullar, ana başarılı senaryo (temel akış, "happy path"), uzantılar (alternatif akışlar).
  - Video kiralama örneği: birincil aktör görevli (clerk). Ön koşul: görevlinin tanıtılması ve doğrulanması. Paydaşlar: görevli doğru ve hızlı giriş, müşteri az çabayla hızlı servis, muhasebe doğru kayıt, pazarlama müşteri alışkanlıklarını izleme ister.
  - Uzantı örnekleri (ekrandan, 00:35:00): `a*` her an sistem çökerse görevli sistemi yeniden başlatır, giriş yapar, önceki durumdan kurtarma ister; `1a` yeni müşteri ise Manage Membership çalışır; `2a` müşteri kimliği bulunamazsa yeniden girilir, olmazsa Manage Membership; `2b` ödenmemiş ceza varsa Pay Fines.
  - Temel ve somut use case (ekrandan, 00:40:00): "Arayüzü dışarıda tut." Temel (essential) use case arayüz ayrıntısını erteler, aktörün niyetine odaklanır: "Clerk enters Customer ID." Somut (concrete) yazım daha kötüdür: "Clerk takes Customer ID card and reads the bar code with laser scanner."
  - Use case'ler ilgili gereksinimleri bir bağlam içinde bir araya getirir ("Requirements in Context") (ekrandan, 00:50:00). Teknik olmayan kişiler de kolay takip eder.
- Nesneye yönelik analiz (Türkçe slaytlar)
  - Uygulama alanının çözümlenmesi (domain analysis): amaç, uygulama alanını anlamak ve bilgiyi analiz modeline taşımaktır. Kaynaklar: teknik literatür, mevcut uygulamalar, müşteri anketleri, uzman tavsiyeleri; mevcut ve gelecekteki gereksinimler (ekrandan, 00:55:00).
  - Gereksinim belgesi doğal dille yazılır. Örnek: web satışını da destekleyecek perakende satış programı; her işlem saklanır, mali bilgiler harici bütçe sistemine, mal çıkışı harici envanter sistemine gider, fiş verilir, KDV ayrıca hesaplanır, şubelerin işlemleri merkezi sunucuya iletilir.
  - Kullanım öyküsü, programın işlerini ayrıntılı adımlarla ve kurallara uyarak anlatır; son kullanıcı ile yazılım ekibi arasında anlaşma zemini ve testler için temel oluşturur.
  - Satış işlemi öyküsü: birincil aktör kasiyer; ön koşul kasiyerin kimliğinin doğrulanması; son koşul ödemenin tahsili, satışın kaydı ve fişin yazılması. Ana öykü 11 adımdır (ekrandan, 01:00:00). Alternatif öyküler: `3a` geçersiz barkodda uyarı ve kaydın reddi; `3-7` arasında müşteri bir kalemi çıkarmak isterse barkod okutulur, sistem güncel toplamı bildirir.
  - Kullanıcı gereksinimleri belgesinden ve senaryolardan sınıflar, saklanacak bilgiler ve gereken hizmetler çıkarılır. Sınıfların üyeleri ve sorumlulukları CRC (Class-Responsibility-Collaboration) kartlarıyla belirlenir. Sorumluluklar tek yerde yoğunlaşmamalı, dağıtılmalıdır.
  - ATM örneği (ekrandan, 01:05:00): Bank Customer (Withdraw Cash, Transfer Funds, Deposit Funds), Maintenance Person (Refill Machine), sağda Bank aktörü.
- Veri varlığı ile nesne arasındaki fark
  - Geleneksel yaklaşımda veri varlıkları (data entity) hakkında veri saklanan şeylerdir; varlık ilişki (ER) diyagramıyla modellenir ve ilişkisel veri tabanında tutulur. Veri bir yerde, işlemler (İşlem 1, 2, 3) başka yerde durur; veri tabanından alınıp işlenir ve geri yazılır.
  - Nesneye yönelik yaklaşımda nesne hem veriyi hem bu veriyi işleyen metotları kapsüller (encapsulation). Metotlar mesajla tetiklenir.
  - Sınıf, bilgi tutulan şeyin tipidir; nesne sınıfın özel bir örneğidir; metotlar nesnenin davranışlarıdır.
  - Basit ER örneği (ekrandan, 01:15:00): bir müşteri sıfır ya da daha çok sipariş verebilir; bir sipariş tam olarak bir müşteri tarafından verilir. Sipariş de bir ya da çok ürün kalemiyle ilişkilidir.
  - Sınıf diyagramında genelleştirme/özelleştirme hiyerarşisi (motorlu taşıt, araba, sedan, spor araba), kalıtım ve bütün-parça (aggregation) ilişkisi (bilgisayar ve parçaları) gösterilebilir.
  - Varlık sembolünde iki bölme vardır: ad ve özellikler. Sınıf sembolünde üç bölme vardır: ad, nitelikler, metotlar (ekrandan, 01:20:00: `Customer`; `name, address, phone`; `addNew, delete, change, connectToAccount`).
- Yapısal yaklaşımla gereksinim analizi ve VAD kuralları (tekrar)
  - Gereksinim analizi modelinin ortasında veri sözlüğü vardır; çevresinde varlık ilişki diyagramı (veri nesnesi tanımı), veri akış diyagramı (süreç spesifikasyonu) ve durum geçiş diyagramı (kontrol spesifikasyonu) bulunur (ekrandan, 01:25:00).
  - Yapısal yaklaşımda tasarımda yapı diyagramı ve ER diyagramı, nesneye yönelik yaklaşımda sıralama (sequence) ve sınıf diyagramı kullanılır.
  - VAD kuralları: varlıktan varlığa, varlıktan veri saklama ortamına, veri saklama ortamından varlığa ya da başka bir veri saklama ortamına doğrudan veri akmaz; arada mutlaka bir işlem olur. İşlemden işleme veri akabilir. Tekrar çizilen varlık işaretlenir. Her veri ayrı okla gösterilir. Bağlam diyagramında tek işlem vardır. Düzeyler arasında tutarlılık olmalıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Use case diyagramlarını ve veri akış diyagramlarını "okur yazar" olmak
  - Verilen bir diyagramın ne dediğini anlayıp tasarıma aktarabilmek ve düz yazıyla verilmiş bir hikayeyi diyagrama çevirebilmek beklenir.
- Varlık ile nesne farkı
  - Hoca bu farkı bir öğrencinin sorusu üzerine dersin sonunda ayrı slaytla yeniden anlattı: varlıkta yalnız ad ve özellikler, nesnede bunlara ek olarak uygulanan işlemler vardır.
- VAD'de doğrudan veri aktarımı olmaz
  - Varlıktan varlığa, dosyadan dosyaya veri "kendiliğinden" gidemez. Hatalı bir diyagram verildiğinde doğrusunu bulabilmek gerekir.
- Use case seviyeleri ve kademeli ayrıntı
  - Bütün organizasyonu tek bir ayrıntılı use case'e koymak, tek bir VAD'de bütün ayrıntıyı vermek gibi takip edilemez sonuç verir.
- Kullanım öyküsünde adımların sırası ve tekliği
  - Adımlar alan modellemede dinlenen iş sırasına uymalıdır; algoritmalardaki gibi her adım tek bir temel işi anlatmalıdır.

## Kısa Tekrar Notları

- Alan modeli: UML sınıf notasyonuyla görsel sözlük; yazılım sınıfı değildir.
- Bağlantı ok yönünde okunur; çokluluk `1`, `0..1`, `*`, `1..*`.
- Başka sınıfı gösteren nitelik yazma, bağlantı çiz.
- Aşamalar: iş modelleme (alan modeli) → gereksinimler (use case metni + diyagram) → tasarım.
- Use case = işlevsel gereksinim hikayesi; birincil aktör solda, destek aktörü sağda.
- Çöp adam canlı aktör, dikdörtgen canlı olmayan aktör, elips use case.
- Fully dressed belge: aktör, paydaş ve ilgileri, ön koşul, son koşul, ana akış, uzantılar.
- Temel use case arayüz ayrıntısı vermez; aktörün niyetini anlatır.
- CRC: sınıf, sorumluluk, iş birliği; sorumluluk dağıtılır.
- Varlık: ad + özellikler (ER). Sınıf: ad + nitelikler + metotlar.
- Yapısal model: veri sözlüğü merkezde; ERD, VAD, durum geçiş diyagramı çevrede.
- VAD: varlık/depo arasında doğrudan akış yok, arada işlem olmalı.

## Detaylı Açıklamalar

- Alan modeli, analiz aşamasında "bu uygulamada neler hakkında bilgi tutmamız gerekiyor" sorusunun cevabıdır. Video mağazası örneğinde mağaza videoları depolar, müşteri video kiralar; kiralama ödemeden sonra gerçekleşir ve kiralamanın tarih ve zamanı tutulur. Mağazanın bir kataloğu vardır, video tanımları kategorilere ayrılabilir. Müşteri üye olabilir ya da tek seferlik alım yapabilir; müşteri ile üyelik arasında bire bir ilişki vardır. Bağlantılar ok yönünde okunduğunda "bir video mağazası çok sayıda video saklar"; ters yönde okunduğunda "bir videoyu hiçbir müşteri kiralamamış olabilir" gibi kurallar çıkar. <!-- BELİRSİZ: müşteri-video-üyelik bağlantılarının slayttaki tam çokluluk değerleri karede görünmüyor; altyazıda "sıfırdan bire", "bire çoklu" deniyor. -->
- Use case ile veri akış diyagramı farkı bir öğrencinin sorusuyla ele alındı. İkisi de sistemin nasıl çalıştığını anlatır. Klasik yaklaşımda varlıklar ve işlemler ayrı tanımlanır ve VAD'lerde birleştirilir; işlem hiyerarşisi bağlam diyagramı, birinci düzey ve ikinci düzey VAD ile kademe kademe gösterilir. Nesneye yönelik yaklaşımda nesnenin hem özellikleri hem ona uygulanan işlemler tanımlanır ve nesnelerin hangi hikayelerde birlikte çalıştığı use case'lerle gösterilir. Use case diyagramı klasik yaklaşımda da kullanılabilir, ama esas olarak nesneye yönelik analizde kullanılır.
- Use case diyagramında canlı olmayan aktörler de vardır: kredi onay servisi gibi başka bir yazılım ya da ev güvenlik sistemindeki bir sensör sisteme girdi sağladığı için aktördür ve dikdörtgenle gösterilir. ATM örneğinde "Bank" çöp adam olarak çizilmişti; bir öğrenci bunu sordu, hoca arkada bankamatik sistemi çalıştığı için dikdörtgen çizilmesinin daha uygun olacağını söyledi.
- Fully dressed use case belgesi önce aktörleri ve paydaşları, sonra ön koşulları, sonra sorunsuz ana akışı verir. Video kiralamada görevli müşteri kimliğini girer, her ürün için kiralama bilgisini girer (adımlar tekrarlanır), sistem toplam fiyatı hesaplar, müşteri öder, görevli kiralama raporunu alır ve müşteriye verir. Sorun çıkan durumlar uzantılar bölümünde numaralı alternatiflerle yazılır; uzantı numarası hangi ana adımdan ayrıldığını gösterir (`2a`, `2b`), `a*` ise her adımda olabilecek durumu belirtir.
- Satış işlemi kullanım öyküsünde paydaşların ilgileri ayrıntılıdır: kasiyer doğru ve hızlı giriş ister, kasa açığı maaşından kesildiği için ödeme hatası istemez; satıcı (mağazada müşteriye yardım eden, satış yaparsa komisyon alan kişi) diğer ilgililer arasındadır; müşteri en az çabayla hızlı hizmet ve iade için fiş ister. Alternatif öykü `3-7`, 3. ile 7. adımlar arasında herhangi bir anda olabilecek durumu anlatır: müşteri toplamı duyunca bir ürünü çıkarmak isteyebilir.
- Varlık-nesne farkı geleneksel ve nesneye yönelik mimari karşılaştırmasıyla anlatıldı. Geleneksel uygulamada veri tabanında duran veri İşlem 1, İşlem 2, İşlem 3 gibi farklı işlemlere aktarılır ve sonra geri yazılır. Nesneye yönelik yaklaşımda nesneye ait veri ve onu işleyen yöntemler nesne tanımı içindedir; dışarıdan gelen mesaj bir metodun çalışmasını tetikler. Sınıf diyagramı çizilse bile veri sonunda ilişkisel veri tabanına yazılacaksa ER diyagramına çevrilebilir.
- VAD tekrarında örnek birinci seviye diyagramda (Öğrenci, Öğretim Üyeleri; Ders Seç, Sınav sonuçlarını sisteme ekle, Sınav sonucu görüntüle işlemleri; Öğrenci-Ders ve Öğrenci-Not veri tabanı tabloları) öğrenci varlığı ikinci kez çizildiği halde işaretlenmemişti; hoca bunun bir hata olduğunu, tekrar çizilen varlığın ucuna "daha önce kullanıldı" çizgisi konması gerektiğini söyledi (ekrandan, 01:30:00). İkinci düzey VAD örneğinde (2.0 işleminin 2.1, 2.2, 2.3 alt işlemleri) dış girdiler de gösterilir ve tekrar eden Hasta varlığı işaretlidir (ekrandan, 01:35:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
