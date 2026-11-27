# Ders 9 Çalışma Özeti

## Genel Konular

- Sistem tasarımına geçiş ve tasarımın aşamaları (ekrandan, 00:10:00)
  - Analiz modeli tamamlandıktan sonra tasarım aşamasına geçilir. Analiz problemi anlamak ve modellemekti; tasarım ise problemin nasıl çözüleceğini gösteren doküman ve diyagramları üretir.
  - Ön tasarım: altyapı belirleme (fizibilitenin gerçekleştirilmesi) ve modül mimarisinin oluşturulması.
  - Ayrıntılı tasarım: sistem etkileşimi tasarımı (çıktı, girdi, arabirim tasarımı), program tasarımı ve veritabanı tasarımı.
- Sistem tasarımı bileşenleri (ekrandan, 00:15:00)
  - Uygulama tasarımı (uygulama sunucusundaki bilgisayar programlarını tanımlar).
  - Veritabanı tasarımı (veritabanı sunucusundaki veritabanının yapısını tanımlar).
  - Kullanıcı arayüz tasarımı (ofis bilgisayarlarındaki ekranları, raporları, girdi/çıktı kontrollerini tanımlar).
  - Sistem arayüz tasarımı (başka sistemlerle haberleşmeyi tanımlar; örneğin web servisleri ya da REST API istek ve yanıtları).
  - Güvenlik ve kontrol tasarımı (internete açılan güvenlik duvarını, yetkilendirme ve erişim kontrollerini tanımlar). Bu ders kapsamında işlenmeyecek ama günümüz sistemlerinde mutlaka ele alınmalıdır.
- Tasarım süreci
  - Gereksinim analizinden gelen girdilerle veri yapıları, modüller ve kısıtlar tanımlanır ve bir ön tasarım raporu yazılır. İncelemeden sonra revizyon ya da kabul gelir.
  - Ön tasarım raporu ayrıntılı tasarımı besler; ayrıntılı tasarım da bir tasarım spesifikasyonu üretir. İnceleme ve revizyonlardan sonra sistem tasarım raporları ortaya çıkar.
- Tasarım yaklaşımları
  - Model güdümlü yaklaşım (Model Driven Architecture): mantıksal analiz modellerinden tasarım modelleri ve alternatif tasarımlar üretilir, uygun olanı seçilir.
  - Hızlı uygulama geliştirme (RAD): prototipleme esastır; model, prototip, iyileştirilmiş model döngüsüyle (spiral modele benzer) çekirdek modülden başlanıp bütün modüller kapsanır.
  - Ortak uygulama geliştirme (JAD): bütün paydaşların katıldığı atölye/seminer tarzı bir çalışmada, analiz modeli temel alınarak beyin fırtınasıyla ortak bir çözüm belirlenir.
  - Hiç tasarım yapmadan kodlamaya geçmek "Big Ball of Mud" (büyük çamur topu) mimarisine ve spagetti koda götürür; günü kurtaran bu çözüm sonunda çöker.
- Ön (genel) tasarım (ekrandan, 00:20:00)
  - Sistem nasıl temin edilecek: kurum içi geliştirme, hazır sistemi satın alıp özelleştirme ya da dışarıdan hizmet olarak alma (outsource). Bu soru ancak analizden sonra cevaplanabilir.
  - İşlevsel olmayan gereksinimler mimari tasarımı etkiler: sistemin hızı, kapasitesi, şifreleme ve virüs kontrolü ihtiyacı gibi.
- Sistem mimari modellemesi (ekrandan, 00:30:00)
  - Merkezi mi dağıtık mı? Veri ağ üzerinde nasıl dağıtılacak, eş zamanlılık ve tutarlılık nasıl sağlanacak? Hangi dil, araç, kütüphane, API, SDK kullanılacak? Satın alınan yazılımlar nasıl bütünleştirilecek? Kullanıcı arayüzü ve diğer sistemlerle arayüz teknolojileri neler olacak?
  - Mimari tasarım yazılım bileşenlerini (veri depolama ve erişim, uygulama mantığı, sunum katmanı) ve donanım bileşenlerini (istemciler, sunucular, iletişim) kapsar.
- Altyapı belirleme
  - Adımlar: mevcut envanteri çıkarma, iş yükünü belirleme, donanım ve yazılımı değerlendirme, satıcıyı seçme, satın alma şeklini belirleme.
  - İş yükü matrisi: yapılan iş, yöntem, personel, maliyet, zamanlama, gerekli insan gücü ve bilgisayar gücü için mevcut ve önerilen değerler karşılaştırılır. Amaç yalnız gerektiği kadarını yenilemektir.
  - Donanım değerlendirme kriterleri (ekrandan, 00:35:00): işlemin ortalama süresi (giriş ve çıkış dahil), toplam kapasite (sorun çıkmadan aynı anda kaç işlem), CPU'nun atıl zamanı, önerilen bellek büyüklüğü. İş yükleri farklı sistemlerde simüle edilerek karşılaştırılır.
  - Yazılım değerlendirme: performans, verimlilik (throughput), kullanım kolaylığı, esneklik, dokümantasyon, üretici desteği.
  - Satıcı değerlendirme: donanım desteği, yazılım desteği, kurulum ve eğitim olanakları, bakım hizmetleri (örneğin acil durumda yanıt süresi).
- Satın alma şeklini belirleme (ekrandan, 00:40:00)
  - Satın alma, leasing (finansal kiralama) ve kiralamanın avantaj ve dezavantajları bir tabloyla karşılaştırıldı (tablo Detaylı Açıklamalar'da).
- Çıktı tasarımı (ekrandan, 00:45:00)
  - Çıktı, sistemin kullanıcılara verdiği bilgi ve ürettiği raporlardır.
  - Amaçlar: belirlenen amaca hizmet etme, kullanıcı için anlamlı olma, uygun sayıda olma, hangi kullanıcılara dağıtılacağının doğru belirlenmesi, zamanında sağlanma (günlük, aylık, yıllık ya da koşula bağlı), doğru çıktı yönteminin (ortamının) seçilmesi.
  - Kullanıcıyı etkileyecek yönlendirmeler: bilgilerin belirli kriterlere göre sıralanması, sınırların belirlenmesi, grafik tipi, rengi ve ölçeğinin belirlenmesi.
- Girdi tasarımı (ekrandan, 00:50:00)
  - "Çöp girerse çöp çıkar" (garbage in, garbage out): kaliteli çıktı için kaliteli girdi gerekir.
  - Formların ve ekranların bir amacı olmalı; girdiler doğru (analizdeki işlemler için gereken bütün veriler alınmalı), ergonomik, uyumlu, basit ve düzgün görünümlü olmalıdır.
  - Prensipler: çevrimiçi ve toplu (bulk) girdiler uygun biçimde birlikte kullanılır, veri kaynağında tutulur, klavye tuşlamaları azaltılır, doğrulama ve geçerleme yapılır (tamlık, biçim, aralık, tutarlılık).
- Ekran ve arabirim tasarımı (ekrandan, 00:55:00)
  - Ekranlar kolay kullanılmalı, gereksiz bilgi içermemeli, gerektiğinde açıklama sunmalı, aynı temayı kullanmalı, fare ve klavyeyle kolay gezilmeli.
  - Kullanıcı arabirimleri: doğal dil, soru-cevap/sorgu, menü, form, komut (script) dili, bildirim arabirimi.
  - Tipik ekran yerleşimi: üstte gezinti (menü, araç kutuları), solda iç gezinti/modül seçimi, ortada etkileşim alanı, altta durum çubuğu.
  - Arabirim tasarım problemleri: düzensiz bilgi yığınları, görevler arasında uyumsuz geçişler, karmaşık terminoloji, açıklayıcı olmayan hata mesajları, anlaşılmaz el kitapları.
- Sistem (uygulama) mimarisini belirleme ve yapı diyagramı (ekrandan, 01:05:00)
  - Modüler program yapısı geliştirilir, modüller arası ilişkilerin denetimi belirlenir, veri yapısı ve program birleştirilir, ara birimler tanımlanır.
  - Gösterim: VAD ve veri sözlüğüne dayanan yapı diyagramı (structure chart). Öğeleri modüller, veri iletişimi, kontrol mesajları, durumlar ve döngülerdir.
- Hiyerarşi ve girdi-süreç-çıktı (HIPO) (ekrandan, 01:20:00)
  - Görsel içerik tablosu (VTOC), genel IPO diyagramı ve ayrıntılı IPO diyagramlarından oluşur. Eski bir tekniktir; ders kapsamında yapı diyagramını bilmek yeterlidir.
- Nesneye dayalı tasarım modelinin oluşturulması (ekrandan, 01:25:00)
  - Kavramsal sınıflar yazılım sınıflarına dönüştürülür; yazılım sınıfları ve aralarındaki işbirliği (etkileşim) belirlenir.
  - Çıktılar: tasarım sınıf diyagramı (DCD) ve etkileşim diyagramları (işbirliği ve ardışıl diyagramlar).
  - Etkileşim, sınıfların davranışlarının belirlenmesidir; yani sorumlulukların atanması.
- Etkileşim diyagramları (ekrandan, 01:30:00)
  - İşbirliği (collaboration) diyagramları: az yer kaplar, dallanma, paralellik ve iterasyon kolay gösterilir, mesaj sırasını anlamak zordur.
  - Ardışıl (sequence) diyagramlar: fazla yer kaplar, mesaj sırasını anlamak kolaydır.
  - Gösterimler: mesaj sıra numaraları, kendine çağrı, koşullu mesaj (opt), if-else (alt), döngü (yıldız ya da loop kutusu).
- Senaryoların gerçeklenmesi (use case realization) (ekrandan, 01:45:00)
  - Nesnelerin iki tür sorumluluğu vardır: bilmesi gerekenler ve yapması gerekenler.
  - İlk iterasyonda ana akışlar, sonraki iterasyonlarda alternatif akışlar gerçeklenir. Tasarımın sonunda tersine gidilerek analiz modelinin son hali elde edilir.
- GRASP tasarım kalıplarına giriş (ekrandan, 01:50:00)
  - GRASP: General Responsibility Assignment Software Patterns (genel sorumluluk atama yazılım kalıpları/prensipleri). Dokuz prensibin ayrıntısı sonraki derse kaldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tasarımın asıl uğraştığı nokta işlevsel olmayan gereksinimlerdir
  - İşlevsel gereksinimlerin karşılanması diyagramlarla (yapı diyagramı, etkileşim diyagramları, tasarım sınıf diyagramı) gösterilir; ama mimariyi belirleyen kararlar hız, kapasite, eş zamanlı kullanıcı sayısı gibi işlevsel olmayan gereksinimlerden doğar.
  - Örnek: 10.000 eş zamanlı kullanıcıya en fazla 1 saniye bekleme süresiyle hizmet istenirse tek sunuculu çözüm çöker; dağıtık mimari, konteyner ya da serverless mimari gibi bambaşka fiziksel tasarımlar gerekir.
- Kullanıcıdan alınan her girdi doğrulanmalı ve geçerlenmelidir
  - Kullanıcıya güvenilmez: tamlık (eksik alan), biçim (tarih formatı), aralık (negatif yaş olamaz) ve tutarlılık (evlilik tarihi doğum tarihinden en az 18 yıl sonra olmalı) kontrol edilir.
- Hata mesajları açıklayıcı olmalıdır
  - "Bilinmeyen hata oluştu" yerine "dosya adını boş geçtiniz" gibi nedenini söyleyen mesajlar verilmelidir.
- Hazır, endüstri standardı kütüphaneler kullanılmalıdır
  - Girdi, çıktı ve ekran tutarlılığı bugün Angular, React, Vue gibi kütüphaneler ve CSS temelli çözümlerle büyük ölçüde standartlaşmıştır.
- Yapı diyagramı ders kapsamında bilinmeli; HIPO kartları beklenmiyor
  - HIPO artık pek kullanılmasa da işlevsel tasarımın temelidir ve bu yüzden tanınmalıdır.
- Ardışıl diyagramlar bazı kaynaklarda iş modellemesinde de kullanılır
  - Ders kapsamında ardışıl diyagramlar tasarım diyagramı olarak ele alınır; esas kullanım yeri tasarımdır.

## Kısa Tekrar Notları

- Ön tasarım = altyapı belirleme + modül mimarisi; ayrıntılı tasarım = çıktı/girdi/arabirim + program + veritabanı tasarımı.
- Sistem tasarımı bileşenleri: uygulama, veritabanı, kullanıcı arayüzü, sistem arayüzü, güvenlik ve kontrol tasarımı.
- Tasarım yaklaşımları: MDA (alternatif modeller), RAD (prototipleme), JAD (ortak atölye çalışması). Tasarımsız kodlama = Big Ball of Mud.
- Temin seçenekleri: kurum içi geliştirme (ürün ve bilgi birikimi sizin, ama uzun sürebilir), hazır alıp özelleştirme (hızlı, ama tam uymayabilir), outsource (risk karşı tarafa geçer, ama risk fiyatlanır ve kaynak kod sizde olmayabilir).
- Altyapı: envanter → iş yükü → donanım/yazılım değerlendirme → satıcı seçimi → satın alma şekli (satın alma, leasing, kiralama).
- Donanım kriterleri: ortalama işlem süresi, toplam kapasite, CPU atıl zamanı, bellek büyüklüğü.
- Yazılım kriterleri: performans, verimlilik, kullanım kolaylığı, esneklik, dokümantasyon, üretici desteği.
- Girdi geçerleme: tamlık, biçim, aralık, tutarlılık.
- Yapı diyagramı sembolleri: dikdörtgen modül, iki dikey çizgili kütüphane modülü, içi boş halkalı ok veri iletişimi, içi dolu halkalı ok kontrol mesajı, eşkenar dörtgen koşullu seçim, kavisli ok döngü.
- HIPO = VTOC + genel IPO + ayrıntılı IPO.
- Nesneye dayalı tasarım: tasarım sınıf diyagramı + etkileşim diyagramları; sorumlulukların atanması.
- İşbirliği diyagramı kompakt, ardışıl diyagram sırayı kolay gösterir; ikisi aynı bilgiyi taşır.
- Ardışıl diyagram kutuları: opt (koşul), alt (if-else), loop (döngü, örneğin [i=1..N]).
- Nesne sorumlulukları: bilmek (kendi verisi, ilişkili nesneler, hesaplanabilen veriler) ve yapmak (hesap, nesne yaratma/yok etme, başka nesneleri çağırma, denetleme).
- GRASP: genel sorumluluk atama prensipleri; GoF kalıpları 23 tanedir.

## Detaylı Açıklamalar

- **Tasarımın yeri.** Ders, analiz modelinin bittiğini ve artık dersin adının ikinci kısmı olan tasarıma geçildiğini söyleyerek başladı. Tasarım, analizi yapılan sistemin gerçekleştirilmeye hazırlandığı ve çözümün ortaya konduğu aşamadır. Ön tasarımda fizibiliteye geri dönülerek altyapı seçimleri somutlaştırılır ve modül mimarisi kurulur. Ayrıntılı tasarımda sistemin girdileri, çıktıları ve ara birimleri, yazılımın mimari tasarımı ve veri modeli tasarlanır. Veritabanı tasarımı sonraki derse bırakıldı.

- **Sistem tasarımı bileşenleri resmi** (ekrandan, 00:15:00). Slayttaki şekilde ağ omurgasına bağlı uygulama sunucusu, veritabanı sunucusu ve ofis bilgisayarları vardır; internet ve başka sistemler bir güvenlik duvarının arkasından bağlanır. Her parçanın yanında hangi tasarımın onu tanımladığı yazar:

  | Parça | Tasarım | Ne tanımlar |
  |---|---|---|
  | Uygulama sunucusu | Uygulama tasarımı | Bilgisayar programlarını |
  | Veritabanı sunucusu | Veritabanı tasarımı | Veritabanının yapısını |
  | Ofis bilgisayarı | Kullanıcı arayüz tasarımı | Ekranları, raporları, girdi/çıktı kontrollerini |
  | Başka sistemler | Sistem arayüz tasarımı | Diğer sistemlerle haberleşmeyi |
  | Internet bağlantısı | Güvenlik ve kontrol tasarımı | Güvenlik duvarını |

- **İşlevsel olmayan gereksinimler ve mimari.** Hoca bir öğrenci bilgi sistemi örneği verdi. Tek, güçlü bir sunucu başlangıçta yeterli görünebilir. Ama "sistem eş zamanlı 10.000 kullanıcıya en fazla 1 saniye bekleme süresiyle hizmet verecek" gereksinimi gelince tek sunucu çözümü çöker ve dağıtık mimariye geçmek gerekir. Sunucu başına 10.000 dolardan 5 sunucu 50.000 dolarlık yatırım demektir. Yük yalnız ders kayıt döneminde yoğunlaştığı için bu yatırımın büyük kısmı (hocanın verdiği rakamla 45.000 dolarlık bölümü) dönem içinde boşa çalışır. "Yük olduğunda karşılansın" gibi yeni bir işlevsel olmayan gereksinim konteyner mimarisini, yeni konteyner ayağa kalkarken yaşanan gecikme de serverless mimariyi gündeme getirir. Bunların hiçbiri veri akış diyagramında görünmez; tasarımda çözülmesi gerekir.

- **Temin seçenekleri.** Kurum içi geliştirmede ürün ve bilgi birikimi tamamen kurumundur ve ihtiyaca tam özelleştirilir. Ama uzun sürebilir, ekip başka işlerle uğraşır, deneyim eksikliği eğitim maliyeti doğurabilir. Hazır sistem hızlıdır ama tam uymayabilir ve özelleştirme emeği büyüyebilir. Outsource etmede risk karşı tarafa geçer, ama karşı taraf riski fiyatlar: hocanın örneğinde kurum içinde 15 adam-ay sürecek bir iş için 10 adam-ay risk payı eklenip 25 adam-ay fatura çıkarılabilir. Ayrıca ürün sizin değildir, analiz modeli yanlış anlaşılabilir ve kaynak kod sizde olmadığı için bakım ve değişiklik zorlaşabilir.

- **Satın alma şeklini belirleme tablosu** (ekrandan, 00:40:00):

  | Şekil | Avantajları | Dezavantajları |
  |---|---|---|
  | Satın alma | Uzun dönemde leasing ve kiralamadan ucuz olması; sistemin değiştirilebilmesi; vergi indirimi sağlaması; tam kontrol | İlk ödemenin yüksek olması; eskime riski; seçimin yanlış yapılması sonucu yatırımın batma riski; tam sorumluluk |
  | Leasing | Sermayenin bağlanmaması; finansmana ihtiyaç olmaması; kira bedelinden düşük olması | Sözleşme bittiğinde işletmenin sisteme sahip olamaması; ödemenin gecikmesi durumunda yüksek faiz oranı; satın almadan daha pahalı olması |
  | Kiralama | Sermayenin bağlanmaması; finansmana ihtiyaç duyulmaması; sistemin kolayca değiştirilmesi; genelde bakım ve garantinin fiyat kapsamında olması | İşletmenin sistemin gerçek sahibi olmaması; satıcı kendi riskini üstlendiği için kira bedelinin çok yüksek olması |

  - Hoca, leasing satırındaki "sözleşme bittiğinde sahip olamaması" ifadesinin yanlış yazıldığını, doğrusunun "sözleşme bitene kadar sahip olamaması" olduğunu söyledi. Leasing banka kredisiyle almaya benzer: örneğin 3 yıl sonunda sunucu işletmenin olur, ama o zamana kadar büyük olasılıkla eskimiştir.
  - Kiralama örneği: 12.000 dolarlık bir sunucu 12 ayda aylık 1.000 dolara denk gelirken kiralandığında aylık yaklaşık 1.500 dolar, yani %50 fazla ödenebilir; karşılığında ihtiyaç bitince bırakılabilir ve arıza riski satıcıdadır.

- **Girdi tasarımında tutarlılık örneği.** Doğum tarihi 2000 girilen bir kullanıcının evlilik tarihi 2005 ya da 2010 girilmişse, evlilik tarihinin doğum tarihinden en az 18 yıl (özel durumlarda 15 yıl) sonra olması beklendiği için bir tutarsızlık vardır ve sistem bunu yakalamalıdır. Aralık kontrolüne örnek olarak yaş alanına -57 girilememesi verildi. Kullanıcı kolaylığı için kopyala-yapıştır, otomatik tamamlama (ilk iki üç harften öneri) ve Excel dosyasından toplu yükleme desteklenmelidir.

- **Yapı diyagramı.** Yapı diyagramı modüler çözümlemeyi gösterir. Üstteki kontrol modülü alt modülleri çağırır; hazır bir API, SDK ya da algoritma kullanılıyorsa bu kütüphane modülü kutunun iki yanına dikey çizgi çizilerek gösterilir.
  - Veri iletişimi ve kontrol mesajı örneği (ekrandan, 01:10:00): "Maintain Customer Data" kontrol modülü "Check Customer Status" modülüne "Customer Number" verisini gönderir ve "Customer Status" verisini geri alır (içi boş halkalı oklar, fonksiyon parametresi ve dönüş değeri gibi). "Update Customer File" modülüne "Customer Charges" verisini gönderir; bu modül "Account Overdue" kontrol mesajını (içi dolu halkalı ok, control couple) geri döndürür.
  - Durum örneği (ekrandan, 01:15:00): "Sort Inventory Parts" modülünün altındaki eşkenar dörtgen, "Sort By Part Name", "Sort By Part Number" ve "Sort By Inventory Value" alt modüllerinden yalnız birinin koşula göre çalışacağını gösterir.
  - Döngü örneği (ekrandan, 01:15:00): "Produce Grade Reports" modülü kavisli okla kapsanan "Get Student Grades" ve "Calculate GPA" modüllerini tekrar tekrar çalıştırır. "Get Student Grades" modülüne "Student Number" gider, "Grades" verisi ve "End of File" kontrol mesajı döner. "Calculate GPA" modülüne "Grades" gider, "GPA" döner. Döngü bitince "Produce Grade Report" modülüne "GPA Listing" gider, "Grade Report" döner. Slayttaki not: kavisli ok bu modüllerin tekrarlandığını gösterir.
  - Hoca ayrıca bir bordro (ödeme) modülü örneği anlattı: çalışanın ödeme kayıtlarını al ve doğrula, net ödemeyi hesapla (brüt ödeme, vergi ve sosyal sigorta indirimleri, kayıt güncelleme), bordroyu bas. <!-- BELİRSİZ: bordro yapı diyagramının karesi yok; modül adları altyazıdan alındı -->
  - VAD'daki ikinci düzey süreçler ve onların çalışması için gereken diğer modüller yapı diyagramında kontrol modülleri olarak karşımıza çıkar; süreç tanımlama formundaki sözde kod ve karar tabloları da bu modüllerde gerçeklenir.

- **HIPO.** Yapı diyagramındaki her modülün nasıl çalışacağını ayrıntılandırır. Hocanın örneğinde "envanter güncelleme ve raporlama" ağacında envanter güncelleme işlem girme, doğrulama, düzeltme ve dosya güncelleme; raporlama ise günlük ve özet raporlama alt fonksiyonlarına ayrılır (görsel içerik tablosu). Her kutu için girdilerin, süreç adımlarının (gelişmiş sözde kod) ve çıktıların yazıldığı bir IPO kartı hazırlanır; gerekirse ayrıntılı IPO ile girdilerin kaynağı (veritabanı, ekran, elle giriş) ve çıktıların hedefi belirtilir. Kaynak, veri akış diyagramları ve süreç tanımlama formlarıdır. <!-- BELİRSİZ: VTOC ağacının karesi yok; alt fonksiyon adları altyazıdan alındı -->

- **Tasarım spesifikasyonları.** Ön tasarım spesifikasyonu yazılım/donanım seçimlerini ve genel özellikleri; mimari tasarım spesifikasyonu işlevsel olmayan gereksinimlerin nasıl karşılandığını, yani sistemin yapısını ve kuruluşunu; ayrıntılı tasarım spesifikasyonu ise problemin nasıl çözüldüğünü (yapı diyagramları, nesneye yönelik diyagramlar) raporlar.

- **Mesaj sıra numaraları** (ekrandan, 01:35:00). Slayttaki ardışıl diyagramda dışarıdan gelen `mesaj()` n1'i tetikler. n1, n2'ye `mesaj1()` gönderir; n2 bunun içinde n3'e `mesaj2` gönderir; n3 de bunun içinde n2'nin başka bir metodu olan `mesaj3()`'ü çağırır. Bu zincir bitince n1, n4'e `mesaj4()` gönderir. Hoca bunu sözde kodla şöyle anlattı:

  ```text
  n1.mesaj():
      n2.mesaj1():
          n3.mesaj2():
              n2.mesaj3()
      n4.mesaj4()
  ```

  - Sıra numaraları metodun içinde hangi çağrının hangi sırayla yapıldığını gösterir. <!-- BELİRSİZ: hocanın sözlü numaralandırması ("bu 1, bu 1.1, bu 1.2 ... bu da 2") tam anlaşılmıyor -->
  - Ders sonrası not: UML iç içe numaralandırmasına göre bu diyagram büyük olasılıkla 1: mesaj1, 1.1: mesaj2, 1.1.1: mesaj3, 2: mesaj4 diye numaralanır.

- **Koşul ve döngü gösterimleri.** İşbirliği diyagramında koşul mesajın önüne köşeli parantezle yazılır; ardışıl diyagramda koşullu çağrı "opt" kutusuna, if-else ise kesikli çizgiyle iki bölmeye ayrılmış "alt" kutusuna alınır. Döngü işbirliği diyagramında yıldızla ya da `1: [i=1..N]: işlemYap()` gibi bir koşulla, ardışıl diyagramda `loop [i=1..N]` kutusuyla gösterilir (ekrandan, 01:40:00). Nesnenin kendine çağrısı ayrı bir metot gövdesi olarak çizilir ("this.metot()" gibi).

- **Satış senaryosuyla sorumluluklar.** Analizde kullanılan satış senaryosu (müşteri, kasiyer, satış, satış kalemi, ürün tanımı) yeniden ele alındı. "Yeni bir satış başlatır" adımı bir nesne yaratma sorumluluğudur; "kasiyer ürün tanımlayıcısını girer" bir metot çağrısıdır; "sistem vergilerle birlikte toplam tutarı gösterir" adımı satışın toplamını (örneğin 86 lira 75 kuruş) hesaplama sorumluluğunu doğurur. Bu sorumluluğun nasıl atanacağı GRASP prensipleriyle sonraki derste gösterilecek.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
