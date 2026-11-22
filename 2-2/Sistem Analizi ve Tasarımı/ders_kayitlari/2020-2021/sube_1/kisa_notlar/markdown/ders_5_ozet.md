# Ders 5 Çalışma Özeti

## Genel Konular

- MS Project ile iş akış planı: Gantt şeması (tekrar)
  - Örnek proje, kitap satışı yapılacak bir web sitesinin tasarımından kullanıma sunulmasına kadar olan süreçtir (ekrandan, 00:05:00). Toplam süre 27 iş günü, 24.03.21 ile 29.04.21 arası.
  - İş, iş kırılım yapısı (Work Breakdown Structure, WBS) ile hiyerarşik olarak numaralandırılmış faaliyetlere ayrılır: 1 Analiz (1.1 Fizibilite Çalışması, 1.2 Gereksinimlerin Belirlenmesi, 1.3 Analiz Bitimi Toplantısı), 2 Tasarım (2.1 Ön Tasarım, 2.2 Ayrıntılı Tasarım, 2.3 Tasarım Bitimi Toplantısı), 3 Geliştirme ve Test (3.1 Ön Yüz Geliştirme, 3.2 Arka Plan Geliştirme, 3.3 Birim Test, 3.4 Sistem Testi, 3.5 Kullanıcı Testleri), 4 Proje Teslim Toplantısı.
  - Kırılım yazılım geliştirme sürecinin aşamalarına göre yapılabileceği gibi ürünün modüllerine göre de yapılabilir (örneğin bir öğrenci bilgi sisteminde öğrenci kaydı, ders tanımlama, ders alma modülleri).
  - Faaliyetin başlangıç tarihi ve süresi girilir; bitiş tarihi otomatik hesaplanır.
  - Toplantılar 0 günlük kilometre taşlarıdır (dönüm noktası), şemada eşkenar dörtgenle gösterilir.
- Faaliyetler arası bağlantı tipleri
  - Finish-Start (FS): bir işin başlaması için öncekinin bitmesi gerekir; varsayılan tiptir, öncül sütununda ayrıca yazılmaz (ör. tasarım, analiz bitince başlar).
  - Start-Start (SS): bir işin başlaması için diğerinin başlamış olması gerekir. Örnekte gereksinimlerin belirlenmesi `2SS+1 day`, yani fizibilite başladıktan bir gün sonra başlar (ekrandan, 00:05:00).
  - Finish-Finish (FF): bir işin bitmesi için diğerinin bitmesi gerekir. Örnekte birim test `11FF;10SS` öncülüne sahiptir.
  - Start-Finish (SF): bir işin bitmesi için diğerinin başlamış olması gerekir; yazılım projelerinde örneği zorlamadır.
- Kritik yol ve bolluk
  - Kritik yol üzerindeki faaliyetlerden biri X gün ertelenirse proje bitişi de en az X gün ertelenir. Bu faaliyetlere kritik faaliyet denir, Gantt şemasında kırmızıyla gösterilir (ekrandan, 00:10:00).
  - Kritik yolda olmayan faaliyet mavi gösterilir ve bolluk (slack) süresi vardır. Örnekte sistem testi 27.04'te bitecekken projeyi geciktirmeden 29.04'e kadar, yani 2 iş günü kayabilir.
- Kaynak atamaları
  - Kaynak, projenin tamamlanması için gereken her şeydir: insan, ekipman, para. Kaynaklar kişi (Work) ya da materyal (Material) olabilir.
  - Ekrandaki kaynak tablosu (ekrandan, 00:15:00): Analist-1 ve Analist-2 30 TL/saat, Yazılımcı-1 ve Yazılımcı-2 50 TL/saat, Test Uzmanı-1/2/3 30 TL/saat, hepsi en fazla %100; Hosting Service materyaldir. <!-- BELİRSİZ: Hosting Service tutarının ilk hanesi imleçle örtülü ("?000,00 TL"). -->
  - %100 kullanım kişinin projeye adanmış olduğu anlamına gelir; başka projede de çalışan biri için %50 ya da %70 yazılabilir. Ücret saat ya da gün bazında verilir, maliyet buna göre hesaplanır.
  - Görev adına "Analist-1" gibi rol yerine kişi adı yazılarak kişiselleştirilmiş görev planı çıkarılabilir.
- PERT (Program Evaluation and Review Technique) ağ diyagramı
  - Graf temelli yöntemdir: düğümler faaliyetler, kenarlar faaliyetler arası bağlantılardır. Her düğümde başlangıç, bitiş, süre ve atanan kaynak görülür; kritik yol kırmızı (pembe), kilometre taşları eşkenar dörtgen gösterilir.
  - Yazılım projelerinde faaliyet süreleri belirsizdir, üç tahminle hesaplanır: en kötümser $A$, en iyimser $B$, en olası $C$. Hocanın verdiği formüller: $\dfrac{A+4C+B}{6}$ ya da $\dfrac{A+2C+B}{4}$.
  - Süreleri belli olan otomasyon süreçlerinde (fabrika bandı, kimya prosesi) bu hesaba gerek yoktur.
- MS Project menüleri ve proje planlama adımları
  - Menüler (ekrandan, 00:20:00): Calendar (takvim), Gantt Chart, PERT Chart (ağ diyagramı), Task Usage, Tracking Gantt, Resource Graph. Kaynak kullanım yüzdeleri, atıl kaynaklar ve kaynak maliyetleri analiz edilebilir.
  - Gantt şemasından elde edilenler: faaliyet süreleri, başlangıç ve bitiş tarihleri, bağımlılıklar, kritik yol, bolluklar, toplam süre ve bitiş tarihi.
  - Microsoft Project Map adımları (ekrandan, 00:25:00): Define the project; Build the plan (1 başlangıç tarihi, 2 görevler, 3 süreler, 4 kaynak atama, 5 görevleri bağlama, 6 planı yazdırma, 7 ince ayar); Track and manage (8 baseline, 9 gerçekleşenleri girme, 10 planı ayarlama); Close the project.
  - Baseline: planın ilk hali kaydedilir; gerçekleşenlerle fark çıkarsa plan güncellenir ve yeni baseline oluşturulur. Plan proje bitene kadar izlenir.
  - Tools > Options > Calendar ile haftanın başlangıç günü (Monday), mali yılın başlangıcı (January), varsayılan başlangıç 08:00, bitiş 17:00, günde 8, haftada 40 saat, ayda 20 gün ayarlanır (ekrandan, 00:30:00).
  - Project menüsünden görevler filtrelenebilir: bütün görevler, tamamlanmış görevler, tamamlanmamış görevler, kritik yol (ekrandan, 00:35:00).
- Fizibilite türlerinin tekrarı
  - Teknik fizibilite (teknolojik olarak yapılabilir mi), ekonomik fizibilite (maliyet ve getiri kıyası), kullanılabilirlik fizibilitesi (kullanıcı kabul eder mi, iş hayatına uygun mu), alternatif fizibilite (farklı çözümlerin her birinin bu açılardan değerlendirilmesi), yasal fizibilite.
- Analiz ve tasarımın farkı
  - Analiz, yazılımı yapılacak sistemin ne olduğunu ve ne yaptığını anlamaktır; teknik altyapı, veritabanı seçimi gibi sorular sorulmaz. Kullanıcılar, alt işler, ortam ve farklı bakış açıları (öğretim üyesi, öğrenci, öğrenci işleri) incelenir.
  - Tasarım, bu sistemin bilgisayar ortamına nasıl aktarılacağını belirler: önce genel tasarım, sonra alt sistemlerin ayrıntılı tasarımı.
- Modeller ve modelleme
  - Analist bilgi sistemi gereksinimlerini bir model kümesiyle anlatır; karmaşık sistemler birden fazla model türü gerektirir; her model sistemin bir yönünü temsil eder (ekrandan, 00:40:00).
  - Model türleri: matematiksel (formüller), tanımsal (anlatı, kullanım durumu belgeleri, hikayeler), grafik (diyagramlar: kullanım durumu, veri akış diyagramı).
  - Analizde mantıksal modeller (teknolojiden bağımsız), tasarımda fiziksel modeller (teknik ayrıntılar) kullanılır.
  - Modelleme soyutlama ile karmaşıklığı azaltır, ekip ve kullanıcılarla iletişimi ve bakım için belgelemeyi sağlar.
- Olayların belirlenmesi ve olay tablosu
  - Olayları belirlemek zordur, koşul ve yanıtla karıştırılır; bir işlemin (transaction) yaşam döngüsünü izlemek yardımcı olur; sistem kontrolleri gibi bazı olaylar "kusursuz teknoloji varsayımı" ile tasarıma bırakılır (ekrandan, 00:50:00).
  - Olay tablosu sütunları: Event, Trigger, Source, Activity/Use Case, Response, Destination (ekrandan, 01:05:00).
- Varlıklar (things), ilişkiler, nitelikler ve nesneler
  - Analizde saklanması gereken bilgiler, varlıklar (öğrenci, öğretim üyesi, ders, sınıf), aralarındaki ilişkiler ve nitelikleri belirlenir; gereksiz nitelikler elenir.
  - Nitelik ve değer örneği: müşteri numarası, ad, soyad, telefon.
  - Basit varlık-ilişki diyagramı: bir müşteri sıfır ya da daha çok sipariş verebilir, bir sipariş tam olarak bir müşteri tarafından verilir (ekrandan, 01:15:00).
  - Nesneler sistemde işi yapar ve bilgi saklar; davranış ve nitelikleri vardır. Sınıf: şeyin türü; nesne: belirli bir şey; metot: nesnenin davranışı. Metotlar mesajlarla etkinleştirilir (ekrandan, 01:10:00).
- Müşteri destek sistemi örneği: hedefler ve yetenekler
  - Şirket satışları, müşteri desteğini ve envanteri iyileştirmek, sipariş hatalarını azaltmak, siparişi hızlandırmak, internet satış kanalını etkin kullanmak ve müşteri sadakatini artırmak istiyor.
  - Sistemin yetenek listesi ekrandan alındı (ekrandan, 01:20:00): çevrim içi müşteri, sipariş, geri sipariş ve iade bilgisi; telefon ve posta kataloğu satışı için hızlı giriş ekranları; internetten satış ve sipariş takibi; pazar analizi için veritabanı ve geçmiş bilgisi; müşteri sorguları için işlem geçmişi; hacim %300 ya da daha fazla artsa da performans düşmemesi; yeni siparişlerin 24 saat gönderimi; birden çok depodan gönderimin koordinasyonu; satış analizi ve talep tahmini için geçmişin saklanması.
- Bağlam (context) diyagramı ve veri akış diyagramı paketi
  - Veri akış diyagramı (VAD, DFD) üç kademelidir: bağlam (özet) diyagramı, birinci düzey ayrıntılı VAD, ikinci düzey ayrıntılı VAD.
  - Bağlam diyagramında tek bir süreç (0 numaralı müşteri destek sistemi) ve onunla veri alışverişi yapan dış varlıklar bulunur (ekrandan, 01:25:00).
  - Birinci düzeyde sistemin alt süreçleri açılır; ikinci düzeyde her alt süreç için ayrı diyagram çizilir.
- Bilgi toplama yolları (kısaca)
  - Anket, görüşme (interview), toplantı, yerinde inceleme ve benzer sistemi kullananların sistemlerini inceleme.
  - Analiz aşaması bilgi toplama, modelleme ve analiz raporunun hazırlanıp değerlendirilmesinden oluşur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Analiz "ne", tasarım "nasıl" sorusudur
  - Analizi iyi yapıp sistemin ne yapması gerektiğini anlamışsak, bunu bilgisayar sistemine nasıl aktaracağımıza da daha doğru karar veririz.
- Ayrıntıya boğulmadan yukarıdan aşağıya gitmek
  - Sistem analizinde işin en ince ayrıntısı öğrenilir, ama büyük resim (sistemin hedefleri) kaybedilmeden, planlı biçimde ve her paydaştan bilgi toplanarak.
- Kritik yolda gecikme projeyi geciktirir
  - Kritik faaliyetteki her gecikme doğrudan proje bitişine eklenir; bolluk yalnız kritik yolda olmayan faaliyetlerde vardır.
- Yazılım projelerinde süre belirsizdir
  - Süreler önceden verilmez, geçmiş benzer projelere ve üç noktalı PERT tahminine dayanır.
- Bağlam diyagramında tek süreç vardır
  - Sistemin alt parçaları gösterilmez; yalnız dış varlıklarla veri akışları gösterilir.

## Kısa Tekrar Notları

- WBS: faaliyetlerin hiyerarşik numaralandırılması (1, 1.1, 1.2 ...).
- Kilometre taşı: 0 günlük dönüm noktası, eşkenar dörtgen.
- Varsayılan bağlantı Finish-Start; SS, FF, SF ayrıca yazılır (ör. `2SS+1 day`, `11FF;10SS`).
- Kritik yol kırmızı, kritik olmayan faaliyet mavi; bolluk = kritik olmayan faaliyetin projeyi geciktirmeden kayabileceği süre.
- Kaynak: kişi (Work) ya da materyal; en fazla kullanım yüzdesi ve standart ücret (TL/saat) girilir.
- PERT süresi: $(A+4C+B)/6$, $A$ kötümser, $B$ iyimser, $C$ en olası.
- Baseline: planın kaydedilmiş hali; sapma olunca plan güncellenir.
- Model türleri: matematiksel, tanımsal, grafik. Analiz: mantıksal model; tasarım: fiziksel model.
- Olay tablosu: Event, Trigger, Source, Activity/Use Case, Response, Destination.
- Sınıf: türü; nesne: belirli örnek; metot: davranış.
- VAD paketi: bağlam diyagramı, 1. düzey, 2. düzey.
- Bilgi toplama: anket, görüşme, toplantı, yerinde inceleme, benzer sistemleri inceleme.

## Detaylı Açıklamalar

Ders, bir önceki haftanın konusu olan MS Project ile iş akış planının tekrarıyla başladı. Örnek proje bir kitap satış web sitesidir ve Gantt şemasında 15 faaliyete ayrılmıştır. Faaliyetler WBS numarasıyla hiyerarşik gösterilir: analiz 6 gün (fizibilite 4 gün, gereksinimlerin belirlenmesi 5 gün, analiz bitimi toplantısı 0 gün), tasarım 7 gün (ön tasarım 3, ayrıntılı tasarım 4, toplantı 0), geliştirme ve test 14 gün (ön yüz 8, arka plan 10, birim test 10, sistem testi 2, kullanıcı testleri 4) ve proje teslim toplantısı 0 gün. Bunların toplamı 27 iş günüdür (6 + 7 + 14); takvimdeki tarihler hafta sonları atlanarak hesaplanmıştır. Süreler, daha önceki benzer işlere göre tahmin edilmiştir. Toplantılar sıfır günlük kilometre taşlarıdır: analiz bitişi ve tasarım bitişi birer dönüm noktasıdır ve burada değerlendirme toplantısı yapılır.

Faaliyetlerin birbirine bağlanma biçimi geliştirme sürecine bağlıdır. Şelale modeline göre hazırlanan bu örnekte işler çoğunlukla ardışık olduğundan neredeyse bütün faaliyetler kritik yol üzerindedir. Yalnız sistem testi kritik yolda değildir: normalde 27 Nisan'da biter, ama proje 29 Nisan'da bittiği için iki iş günü kayabilir. Bu iki güne bolluk süresi denir. Bir öğrencinin sorusu üzerine hoca, kritik yoldaki faaliyetlerde bolluk olmadığını, birinin aksamasının bütün projeyi o kadar geciktireceğini açıkladı.

Kaynak atamalarında önce kaynaklar tanımlanır (analist, yazılımcı, test uzmanı, hosting hizmeti), sonra faaliyetlere atanır. Kaynak tablosundaki "Max. %100" kişinin bütün çalışma süresini bu projeye ayırdığını gösterir; hoca bunun çoğu zaman gerçekçi olmadığını, örneğin bir test uzmanının aynı anda iki projenin testini yapabileceğini ve %50 ya da %70 yazılabileceğini belirtti. Saat ya da gün ücreti ile çalışılan süreden bütçedeki maliyet çıkar.

PERT diyagramı aynı planın graf biçimidir. Yazılım projelerinde bir faaliyetin süresi baştan belli olmadığından, her faaliyet için en kötümser, en iyimser ve en olası süre tahmin edilir ve ağırlıklı ortalama alınır. Fabrika bandı gibi süreleri belli otomasyon süreçlerinde bu tahmine gerek yoktur.

MS Project'te planlama "Microsoft Project Map" adımlarıyla yürür: proje tanımlanır, başlangıç tarihi, görevler, süreler, kaynaklar ve bağlantılar girilir, plan ince ayarlanır, sonra baseline kaydedilip gerçekleşenler girilerek plan izlenir ve gerektikçe güncellenir. Takvim seçeneklerinde haftanın ilk günü, mali yıl başlangıcı ve çalışma saatleri tanımlanır; bunların ötesi fazla mesai sayılır. Görevler tamamlanma durumuna ya da kritik yola göre filtrelenebilir.

Fizibilitenin kısa bir tekrarından sonra analiz aşamasına geçildi. Analiz, yazılımı hazırlanacak sistemi tanımaktır: bir öğrenci bilgi sistemi için önce hangi veritabanını kullanacağımız değil, sistemin hangi işleri yaptığı, kimlerin kullandığı ve her kullanıcının (öğretim üyesi, öğrenci, öğrenci işleri) hangi gözle baktığı sorulur. Bir öğrencinin sorusu üzerine fizibilite çalışmasını büyük ekiplerde proje yöneticisinin, küçük ekiplerde sistem analistinin yürüttüğü; kararların ağ uzmanı, yazılım tasarımcısı, geliştirici ve veritabanı uzmanına danışılarak verildiği söylendi.

Analizde bilgi toplanır ve modellenir. Modeller matematiksel, tanımsal ya da grafik olabilir; analizde teknolojiden bağımsız mantıksal modeller, tasarımda teknik ayrıntılı fiziksel modeller kurulur. Sistemi etkileyen olaylar ve sıraları belirlenir: mağazadan, web sitesinden ya da telefonla alışverişte müşterinin yaptığı işlemler farklı sıralardadır. Olay tablosunda her olay için tetikleyici, kaynak, etkinlik (kullanım durumu), yanıt ve hedef yazılır. Ayrıca sistemin saklaması gereken varlıklar, nitelikleri ve aralarındaki ilişkiler çıkarılır; geleneksel yaklaşımda bunlar veri varlıkları ve varlık-ilişki diyagramıyla, nesneye yönelik yaklaşımda sınıflar, nesneler ve metotlarla modellenir.

Son bölümde bir şirketin müşteri destek sistemi örneği incelendi. Şirketin stratejik hedeflerinden sistemin karşılaması gereken yetenekler çıkarıldı (çevrim içi sipariş, telefonla sipariş, sipariş takibi, arşiv verisiyle pazar analizi, 24 saat gönderim vb.). Bu yetenekler tasarımda veritabanı ve ağ gereksinimlerine dönüşecektir. Ardından sistemin bağlam diyagramı gösterildi: ortada tek süreç olarak müşteri destek sistemi, çevresinde Marketing, Customer, Bank, Credit bureau, Merchandising (sales), Management ve Shipping dış varlıkları ile aralarındaki veri akışları vardır. Kredi bürosuyla bağlantının kırık (şimşek biçimli) çizgiyle çizilmesi uzaktan bağlantıyı gösterir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
