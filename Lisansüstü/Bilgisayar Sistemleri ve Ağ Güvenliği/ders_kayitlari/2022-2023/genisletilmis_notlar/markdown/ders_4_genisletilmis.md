# Ders 4 Genişletilmiş Notu: BT Güvenlik Kontrolleri, Planları ve Prosedürleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş ve önceki dersle bağlantı
- 2. BT güvenlik yönetimi kontrolleri ve uygulaması
- 3. Güvenlik kontrolünün tanımı ve sınıflandırılması
- 4. Standartlarda güvenlik kontrolleri: NIST SP 800-53 ve ISO/IEC 27002
- 5. Artık risk ve maliyet-fayda analizi
- 6. BT güvenlik planı ve uygulama planı örneği
- 7. Güvenlik planının uygulanması ve takibi
- 8. Vaka çalışması: Gümüş Yıldız Madenleri uygulama planı
- Örnek Sorular
- Dersin Toparlaması

## 1. Giriş ve önceki dersle bağlantı

Bu ders, lisans düzeyinde görülen bilgisayar güvenliği konularının üzerine kurulan ve daha üst düzey, yönetimsel süreçleri ele alan bir dizinin parçasıdır. Önceki derste BT ve bilgisayar sistemlerinin güvenlik yönetimi bağlamında risk değerlendirmesi konuşulmuş, örnek bir maden şirketi olan Gümüş Yıldız Madenleri'nin (Silver Star Mines) BT risk değerlendirmesi yapılıp riskler önceliklendirilmişti.

Bu derste aynı risk değerlendirmesinin üzerine güvenlik kontrolleri, güvenlik planları ve güvenlik prosedürleri eklenir. Dersin akışı şöyledir: BT güvenlik uygulamasının adımları, güvenlik kontrollerinin ve önlemlerinin tanımı, BT güvenlik planı, kontrollerin uygulanması, risklerin izlenmesi ve son olarak vaka çalışmasının bu yeni bilgilerle kademe kademe tamamlanması.

## 2. BT güvenlik yönetimi kontrolleri ve uygulaması

Slaytta BT güvenlik yönetiminin kontrol ve uygulama süreci üç adımlık bir akış olarak verildi (ekrandan, 00:15:00):

```text
Adım 1: Riskleri Önceliklendirin
        (risklerin yönetim tarafından gözden geçirilmesi)
            |
            v
2. Adım: Risklere Müdahale Edin
        Risk Yanıtını Belirleyin (kabul et, kaçın, hafiflet, paylaş)
            -> Önerilen Kontrol Seçeneklerini Değerlendirin
            -> Kontrolleri Seç
            -> Uygulama Planı Geliştirin
            -> Seçili Kontrolleri Uygula
            |
            v
3. Adım: Riskleri İzleyin
```

### 2.1 Birinci adım: riskleri önceliklendirmek

Önceki derste yapılan iş budur: belirlenen riskler yönetim tarafından gözden geçirilir ve önceliklendirilir.

### 2.2 İkinci adım: risklere müdahale etmek

Kuruluşun varlıkları ve bu varlıklar üzerinde riskler vardır; bu risklere müdahale edilmesi gerekir. Önce riske nasıl yanıt verileceği belirlenir. Hoca seçenekleri örneklerle açıkladı:

- **Kabul etmek:** Risk gerçekleşirse katlanılacağı, yapılacak bir şey olmadığı kabul edilir.
- **Kaçınmak:** Riskli iş yapılmaz. Örneğin e-posta sunucusu risk oluşturuyorsa artık e-posta hizmeti verilmez; dışarıdan gelen internet bağlantısı risk taşıyorsa internet bağlantısından vazgeçilir.
- **Hafifletmek:** Riski azaltmak için prosedürler belirlenir ve önlemler alınır.
- **Paylaşmak ya da devretmek:** Risk üçüncü taraflarla paylaşılır ya da onlara devredilir.

Seçilen yanıta göre önerilen kontrol seçenekleri belirlenir ve değerlendirilir. Bunlardan uygun olanlar seçilir, seçilen kontroller için bir uygulama planı geliştirilir ve plan uygulanır. Bu alt adımların hepsi "risklere müdahale" adımının parçasıdır.

### 2.3 Üçüncü adım: riskleri izlemek

Planlama yapılıp uygulandıktan sonra, kontrollerin doğru işlediğinin ve riskleri bertaraf ettiğinin ya da planlanan ölçüde azalttığının kontrol edilmesi gerekir. Bu adım risklerin izlenmesidir.

## 3. Güvenlik kontrolünün tanımı ve sınıflandırılması

### 3.1 Tanım

Standart dokümanlardaki tanıma göre güvenlik kontrolü; bir güvenlik ihlalini ortadan kaldırarak ya da önleyerek, neden olabileceği zararı en aza indirerek ya da ihlali keşfedip raporlayarak düzeltici eylemi mümkün kılarak riski azaltan bir eylem, cihaz, prosedür veya başka bir önlemdir. Kısacası riski hafifletmek için kullanılan her türlü eylem, cihaz ya da prosedür bir kontroldür.

### 3.2 Kontrol sınıfları

İkinci adımda kontrollerin belirlenmesi için önce kontrollerin sınıflandırılması gerekir. Kontroller üç grupta tanımlanır (ekrandan, 00:20:00):

- **Yönetim kontrolleri:** Kayıp riskini azaltmak ve kuruluşun misyonunu korumak için operasyonel ve teknik kontrollerin seçimini etkileyen güvenlik politikalarına, planlamaya, yönergelere ve standartlara odaklanır. Bu kontroller yönetimin ele alması gereken hususları ifade eder. Hoca, standartları, politikaları ve yönergeleri belirleyenin yönetim olduğunu, yönetimin planlayıcı bir rolü bulunduğunu vurguladı.
- **Operasyonel kontroller:** Güvenlik politikaları ve standartlarının doğru uygulanmasını ve kullanımını ele almak, güvenlik operasyonlarında tutarlılığı sağlamak ve tespit edilen operasyonel eksiklikleri düzeltmektir. Bu kontroller sistemlerden çok insanlar tarafından uygulanan mekanizmalar ve prosedürlerle ilgilidir ve bir sistemin ya da sistem grubunun güvenliğini artırmak için kullanılır.
- **Teknik kontroller:** Sistemlerde donanım ve yazılım güvenlik özelliklerinin doğru kullanımını içerir. Kritik ve hassas verileri, bilgileri ve BT sistem işlevlerini güvenceye almak için birlikte çalışan, basitten karmaşığa uzanan önlemlerdir.

> **Hocanın vurgusu:** Bu yapı hiyerarşiktir. Yönetim stratejileri ve yönergeleri belirler, buna ve misyona bağlı olarak planlama yapılır; teknik kontroller ise en basitten en karmaşığa kadar teknik kontrol süreçlerini içerir.

### 3.3 Teknik güvenlik kontrollerinin katmanlı yapısı

Hoca teknik güvenlik kontrollerinin katmanlı bir yapı oluşturduğunu bir diyagram üzerinden anlattı. Bir tarafta kaynaklar, diğer tarafta kullanıcılar ya da işlemler bulunur. Aradaki katmanlarda nesne yeniden kullanımı, süreç ayırma ve güvenlik yönetimi gibi destekleyici bileşenler ile korumalı iletişim (işlem gizliliği, inkâr edememe), kimlik doğrulama, yetkilendirme ve erişim kontrolü yer alır; bunların yanında durumu geri yükleme ile izinsiz giriş tespiti ve engelleme bileşenleri bulunur. Diyagram bu süreçlerin birbirleriyle bağlantılarını gösterir.

<!-- BELİRSİZ: katmanlı teknik kontrol diyagramının slaytı okunan karelerde yok; bileşen adları ve hangi katmanda oldukları yalnız altyazıdan alındı -->

> **Ek bilgi (derste anlatılmadı):** Bu diyagram büyük olasılıkla NIST SP 800-30 kaynaklı "teknik güvenlik kontrolleri" şemasıdır. O şemada kontroller destekleyici, önleyici ve algılama-kurtarma olarak üç kümede gösterilir ve kullanıcı ya da işlemden kaynağa giden yol üzerinde sıralanır.

### 3.4 Kontrol türleri: destekleyici, önleyici, algılama ve kurtarma

Yönetim, operasyonel ve teknik kontrol sınıflarının her biri şu türlerden birini ya da birkaçını içerir:

- **Destekleyici kontroller:** Diğer birçok kontrolle ilişkili olan ve onlar tarafından kullanılan yaygın, genel, temel teknik BT güvenlik yetenekleridir. Diğer kontrollerin çalışmasını mümkün kılar.
- **Önleyici kontroller:** Güvenlik politikalarını ihlal etme ya da bir güvenlik açığından yararlanma girişimlerini engelleyerek güvenlik ihlallerinin oluşmasını önlemeye çalışır.
- **Algılama ve kurtarma kontrolleri:** Bir ihlal oluşursa devreye girer. İhlaller, ihlal girişimleri ya da bir güvenlik açığının tespit edilen istismarı konusunda uyarıda bulunur ve kaybedilen BT kaynaklarını geri yüklemek için araçlar sağlayarak ihlale verilen yanıta odaklanır. Amacı sistemi kurtarmaktır.

## 4. Standartlarda güvenlik kontrolleri: NIST SP 800-53 ve ISO/IEC 27002

### 4.1 NIST SP 800-53 kontrol aileleri

NIST SP 800-53 dokümanı güvenlik kontrollerini aileler halinde sıralar ve her aileyi yukarıdaki üç sınıftan birine bağlar (ekrandan, 00:25:00):

| Sınıfı | Kontrol Ailesi |
|---|---|
| Yönetim | Planlama |
| Yönetim | Program Yönetimi |
| Yönetim | Risk değerlendirmesi |
| Yönetim | Güvenlik Değerlendirmesi ve Yetkilendirme |
| Yönetim | Sistem ve Hizmet Alımı |
| Operasyonel | Farkındalık ve Eğitim |
| Operasyonel | Konfigürasyon yönetimi |
| Operasyonel | Acil Durum Planlaması |
| Operasyonel | Olay Müdahalesi |
| Operasyonel | Bakım onarım |
| Operasyonel | Medya Koruması |
| Operasyonel | Personel Güvenliği |
| Operasyonel | Fiziksel ve Çevresel Koruma |
| Operasyonel | Sistem ve Bilgi Bütünlüğü |
| Teknik | Giriş kontrolu |
| Teknik | Denetim ve Hesap Verebilirlik |
| Teknik | Tanımlama ve Kimlik Doğrulama |
| Teknik | Sistem ve İletişim Koruması |

Hoca, yönetim ailelerinin (planlama, program yönetimi, risk ve güvenlik değerlendirmesi, sistem ve hizmet alımı) doğrudan karar mekanizmasına ait olduğunu belirtti. Operasyonel aileler işin işleyişine yöneliktir: farkındalık ve eğitim, konfigürasyonun gerçeklenmesi değil yönetimi, acil durum planlaması, olay müdahalesi, bakım onarım, bilginin saklandığı medyanın korunması, kullanıcı ve güvenlik personelinin güvenliği, fiziksel ve çevresel koruma, sistem ve bilgi bütünlüğü. Teknik aileler ise giriş kontrolü, denetim ve hesap verebilirlik, tanımlama ve kimlik doğrulama ile sistem ve iletişim korumasıdır.

### 4.2 ISO/IEC 27002 kontrol kategorileri ve amaçları

İkinci standart ISO/IEC 27002'dir. Bu standart her kontrol kategorisini bir amaçla tanımlar. Tablonun ilk sayfasındaki kategoriler altyazıdan şöyle aktarılmıştır:

<!-- BELİRSİZ: ISO/IEC 27002 tablosunun ilk sayfası (1/2) okunan karelerde yok; aşağıdaki yedi kategori ve amaçları altyazıdan alındı -->

- **Güvenlik politikaları:** İş gereksinimlerine ve ilgili yasa ve yönetmeliklere uygun olarak bilgi güvenliği için yönetim yönlendirmesi ve desteği sağlamak.
- **Bilgi güvenliği organizasyonu:** Kuruluş içinde bilgi güvenliğinin uygulanmasını ve işleyişini başlatmak ve kontrol etmek için bir yönetim çerçevesi oluşturmak; uzaktan çalışmanın (tele çalışma) ve mobil cihaz kullanımının güvenliğini sağlamak.
- **İnsan kaynakları güvenliği:** Çalışanların ve yüklenicilerin sorumluluklarını anlamalarını ve atandıkları rollere uygun olmalarını sağlamak; bilgi güvenliği sorumluluklarını bilmelerini ve yerine getirmelerini sağlamak; istihdamın değişmesi ya da sona ermesi sürecinde kuruluşun çıkarlarını korumak.
- **Varlık yönetimi:** Kurumsal varlıkları belirlemek ve uygun koruma sorumluluklarını tanımlamak; bilginin kuruluş için önemine göre uygun düzeyde korunmasını sağlamak; ortamda (medyada) saklanan bilginin yetkisiz ifşasını, değiştirilmesini, kaldırılmasını ya da imhasını önlemek.
- **Erişim (giriş) kontrolü:** Bilgiye ve bilgi işleme tesislerine erişimi sınırlamak; yetkili kullanıcı erişimini sağlamak ve sistem ve hizmetlere yetkisiz erişimi engellemek; kullanıcıları kendi kimlik doğrulama bilgilerini korumaktan sorumlu kılmak; sistem ve uygulamalara yetkisiz erişimi önlemek.
- **Kriptografi:** Bilginin gizliliğini, gerçekliğini ve bütünlüğünü korumak için kriptografinin doğru ve etkin kullanımını sağlamak.
- **Fiziksel ve çevresel güvenlik:** Kuruluşun bilgi ve bilgi işleme tesislerine yetkisiz fiziksel erişimi, hasarı ve müdahaleyi önlemek; varlıkların kaybolmasını, hasar görmesini, çalınmasını ya da tehlikeye girmesini ve kuruluşun operasyonlarının kesintiye uğramasını önlemek.

Tablonun ikinci sayfası kareden şöyledir (ekrandan, 00:30:00):

| Kontrol Kategorisi | Amaç |
|---|---|
| Operasyon Güvenliği | Bilgi işleme tesislerinin doğru ve güvenli çalışmasını sağlamak; bilgi ve bilgi işleme tesislerinin kötü amaçlı yazılımlara karşı korunmasını sağlamak; veri kaybına karşı korumak; olayları kaydetmek ve kanıt oluşturmak; operasyonel sistemlerin bütünlüğünü sağlamak; teknik güvenlik açıklarının kötüye kullanılmasını önlemek; denetim faaliyetlerinin operasyonel sistemler üzerindeki etkisini en aza indirmek. |
| İletişim Güvenliği | Ağlardaki ve destekleyici bilgi işleme tesislerindeki bilgilerin korunmasını sağlamak; bir kuruluş içinde ve harici bir varlıkla aktarılan bilgilerin güvenliğini sağlamak. |
| Sistem Edinimi, Geliştirme ve Bakım | Kamusal ağlar üzerinden hizmet sağlayan bilgi sistemlerine ilişkin gereksinimler de dahil olmak üzere, bilgi güvenliğinin tüm yaşam döngüsü boyunca bilgi sistemlerinin ayrılmaz bir parçası olmasını sağlamak; bilgi güvenliğinin bilgi sistemlerinin geliştirme yaşam döngüsü içinde tasarlanmasını ve uygulanmasını sağlamak; test için kullanılan verilerin korunmasını sağlamak. |
| Tedarikçi İlişkileri | Kuruluşun tedarikçiler tarafından erişilebilen varlıklarının korunmasını sağlamak; tedarikçi anlaşmaları doğrultusunda üzerinde anlaşılmış bir bilgi güvenliği ve hizmet sunumu düzeyini sürdürmek. |
| Bilgi Güvenliği Olay Yönetimi | Güvenlik olayları ve zayıflıkları hakkında iletişim de dahil olmak üzere bilgi güvenliği olaylarının yönetimine tutarlı ve etkili bir yaklaşım sağlamak. |
| Bilgi Güvenliği Sürekliliği | BT sürekliliğini organizasyonun iş sürekliliği yönetim sistemlerine yerleştirmek; bilgi işleme tesislerinin kullanılabilirliğini sağlamak. |
| Uyma | Bilgi güvenliği ve herhangi bir güvenlik gereksinimi ile ilgili yasal, düzenleyici veya sözleşmeye dayalı yükümlülüklerin ihlallerini önlemek; bilgi güvenliğinin kurumsal politika ve prosedürlere uygun olarak uygulanmasını ve işletilmesini sağlamak. |

Hoca tedarikçi ilişkileri satırında, kontrollerin yalnız kuruluşun kendi içinde değil, sisteme hizmet veren tedarikçiler için de bulunması gerektiğini belirtti. "Uyma" kategorisinde kastedilen kurallara ve kanunlara uymaktır.

> **Ders sonrası not:** Hoca standardı "ISO'nun ya da eski haliyle IEC'nin" 27002'si diye andı. ISO/IEC 27002, ISO (Uluslararası Standardizasyon Örgütü) ile IEC'nin (Uluslararası Elektroteknik Komisyonu) ortak yayımladığı bir standarttır; IEC, ISO'nun eski adı değildir.

### 4.3 Detaylı NIST SP 800-53 kontrolleri

NIST SP 800-53 her kontrol ailesinin altında ayrıntılı kontrolleri listeler. Hoca listeleri sırayla okudu; okunan iki sayfa kareden şöyledir (ekrandan, 00:35:00):

| Aile | Kontroller |
|---|---|
| Giriş kontrolu | Erişim Kontrolü Politikası ve Prosedürleri, Hesap Yönetimi, Erişim Uygulaması, Bilgi Akışı Uygulaması, Görevlerin Ayrılması, En Az Ayrıcalık, Başarısız Giriş Denemeleri, Sistem Kullanım Bildirimi, Önceki Oturum Açma (Erişim) Bildirimi, Eşzamanlı Oturum Kontrolü, Oturum Kilitleme, Oturum Sonlandırma, İzin Verilen Eylemler Tanımlama veya Kimlik Doğrulama Olmadan, Güvenlik Nitelikleri, Uzaktan Erişim, Kablosuz Erişim, Mobil Cihazlar için Erişim Kontrolü, Harici Bilgi Sistemlerinin Kullanımı, Bilgi Paylaşımı, Herkese Açık İçerik, Veri Madenciliği Koruması, Erişim Kontrol Kararları, Referans Monitör |
| Farkındalık ve Eğitim | Güvenlik Bilinci ve Eğitimi Politika ve Prosedürleri, Güvenlik Bilinci, Eğitim, Rol Tabanlı Güvenlik Eğitimi, Güvenlik Eğitimi Kayıtları |
| Denetim ve Hesap Verebilirlik | Denetim ve Hesap Verebilirlik Politikası ve Prosedürleri, Denetim Olayları, Denetim Kayıtlarının İçeriği, Denetim Depolama Kapasitesi, Denetim İşleme Hatalarına Müdahale, Denetim İnceleme, Analiz ve Raporlama, Denetim Azaltma ve Rapor Oluşturma, Zaman Damgaları, Denetim Bilgilerinin Korunması, İnkar Etmeme, Denetim Kayıt Tutma, Denetim Oluşturma, Bilgi Açıklamasının İzlenmesi, Oturum Denetimi, Alternatif Denetim Yeteneği, Kuruluşlar Arası Denetim |
| Güvenlik Değerlendirmesi ve Yetkilendirme | Güvenlik Değerlendirmesi ve Yetkilendirme Politikaları ve Prosedürleri, Güvenlik Değerlendirmeleri, Sistem Arabağlantıları, Eylem Planı ve Kilometre Taşları, Güvenlik Akreditasyonu, Sürekli İzleme, Sızma Testi, Dahili Sistem Bağlantıları |
| Konfigürasyon yönetimi | Konfigürasyon Yönetimi İlkesi ve Prosedürleri, Temel Konfigürasyon, Konfigürasyon Değişikliği Kontrolü, Güvenlik Etki Analizi, Değişiklik için Erişim Kısıtlamaları, Konfigürasyon Ayarları, En Az İşlevsellik, Bilgi Sistemi Bileşen Envanteri, Konfigürasyon Yönetim Planı, Yazılım Kullanım Kısıtlamaları, Kullanıcı Tarafından Yüklenen Yazılım |
| Acil Durum Planlaması | Acil Durum Planlama Politikası ve Prosedürleri, Acil Durum Planı, Acil Durum Eğitimi, Acil Durum Planı Testi, Alternatif Depolama Sahası, Alternatif İşleme Sahası, Telekomünikasyon Hizmetleri, Bilgi Sistemi Yedekleme, Bilgi Sistemi Kurtarma ve Yeniden Oluşturma, Alternatif İletişim Protokolleri, Güvenli Mod, Alternatif Güvenlik Mekanizmaları |

Hoca giriş kontrolündeki bazı maddeleri açıkladı: "en az ayrıcalık" (least privilege) bir kişiye işini yapmaya yetecek en az yetkiyi tanımlamaktır; oturum kilitleme belli bir süre sonra oturumun kilitlenmesi ya da zaman aşımıyla (session timeout) otomatik sonlandırılmasıdır; veri madenciliği koruması daha önce görülen çıkarım saldırılarıyla ilgilidir.

İkinci sayfa (ekrandan, 00:40:00):

| Aile | Kontroller |
|---|---|
| Tanımlama ve Kimlik Doğrulama | Tanımlama ve Doğrulama Politikası ve Prosedürleri, Tanımlama ve Doğrulama (Kurumsal Kullanıcılar), Cihaz Tanımlama ve Doğrulama, Tanımlayıcı Yönetimi, Doğrulayıcı Yönetimi, Doğrulayıcı Geri Bildirimi, Kriptografik Modül Doğrulama, Tanımlama ve Doğrulama (Kurumsal Olmayan Kullanıcılar), Hizmet Tanımlama ve Doğrulama, Uyarlamalı Tanımlama ve Doğrulama, Yeniden kimlik doğrulama |
| Olay Müdahalesi | Olay Müdahale Politikası ve Prosedürleri, Olay Müdahale Eğitimi, Olay Müdahale Testi, Olay Yönetimi, Olay İzleme, Olay Raporlama, Olay Müdahale Yardımı, Olay Müdahale Planı, Bilgi Dökülmesine Müdahale, Entegre Bilgi Güvenliği Analiz Ekibi |
| Bakım onarım | Sistem Bakım Politikası ve Prosedürleri, Kontrollü Bakım, Bakım Araçları, Lokal Olmayan Bakım, Bakım Personeli, Zamanında Bakım |
| Medya Koruması | Medya Koruma Politikası ve Prosedürleri, Medya Erişimi, Medya İşaretleme, Medya Depolama, Medya Taşıma, Medya Temizliği, Medya Kullanımı, Medya indirme (download) |
| Fiziksel ve Çevresel Koruma | Fiziksel ve Çevresel Koruma Politikası ve Prosedürleri, Fiziksel Erişim Yetkileri, Fiziksel Erişim Kontrolü, İletim Ortamı için Erişim Kontrolü, Çıkış Cihazları için Erişim Kontrolü, Fiziksel Erişimin İzlenmesi, Ziyaretçi Erişim Kayıtları, Güç Ekipmanları ve Kablolama, Acil Durum Kapatma, Acil Güç, Acil Aydınlatma, Yangından Korunma, Sıcaklık ve Nem Kontrolleri, Su Hasarlarından Korunma, Teslim ve Kaldırma, Alternatif Çalışma Sahası, Bilgi Sistemi Bileşenlerinin Yerleşimi, Bilgi Sızıntısı, Varlık İzleme ve Takibi |
| Planlama | Güvenlik Planlama Politikası ve Prosedürleri, Sistem Güvenlik Planı, Davranış Kuralları, Güvenlik İşlemleri Kavramı, Bilgi Güvenliği Mimarisi, Merkezi Yönetim |
| Personel Güvenliği | Personel Güvenliği Politikası ve Prosedürleri, Pozisyon Riski Belirleme, Personel Taraması, Personel Fesih, Personel Transferi, Erişim Sözleşmeleri, Üçüncü Kişi Personel Güvenliği, Personel Yaptırımları |
| Risk değerlendirmesi | Risk Değerlendirme Politikası ve Prosedürleri, Güvenlik Sınıflandırması, Risk Değerlendirmesi, Güvenlik Açığı Taraması, Teknik Gözetim Önlemleri Anketi |

Üçüncü sayfanın karesi okunmadı; altyazıya göre bu sayfada şu aileler yer alır:

<!-- BELİRSİZ: detaylı NIST SP 800-53 tablosunun 3/3 sayfası karelerde yok; aşağıdaki maddeler altyazıdan alındı -->

- **Sistem ve Hizmet Alımı:** edinme politikaları ve prosedürleri, kaynakların tahsisi, sistem geliştirme yaşam döngüsü, edinme (alım) süreci, bilgi sistemi dokümantasyonu, güvenlik mühendisliği ilkeleri.
- **Sistem ve İletişim Koruması:** politika ve prosedürler, uygulama bölümleme, güvenlik işlevi yalıtımı, paylaşılan kaynaklardaki bilgi, hizmet reddine karşı koruma <!-- BELİRSİZ: altyazıda "hizmeti koruması" geçiyor; NIST listesindeki karşılığı büyük olasılıkla hizmet reddi (DoS) korumasıdır -->, kaynak kullanılabilirliği, sınır koruması.
- **Sistem ve Bilgi Bütünlüğü:** politika ve prosedürler, hataları giderme, kötü amaçlı kod koruması, bilgi sistemi izleme, güvenlik uyarıları ve yönergeleri, güvenlik işlevlerini doğrulama, yazılım ve ürün yazılımı (firmware) bütünlüğü, spam koruması, bilgi girişi doğrulaması, hata işleme, bilgi işleme ve saklama, öngörülebilir arıza önleme, bilgi çıkışı filtreleme, bellek koruma.
- **Program Yönetimi:** bilgi güvenliği program planı, kıdemli bilgi güvenliği görevlisi, bilgi güvenliği kaynakları, eylem planı ve kilometre taşları süreci, bilgi sistemi envanteri, bilgi güvenliği performans ölçütleri, kurumsal mimari, kritik altyapı planı, risk yönetimi stratejisi, güvenlik yetkilendirme süreci, iş/görev tanımı, içeriden tehdit programı, bilgi güvenliği iş gücü, test-eğitim ve izleme, güvenlik grupları ve dernekleriyle iletişim, tehdit farkındalık programı.

## 5. Artık risk ve maliyet-fayda analizi

### 5.1 Artık risk

Sistemin güvenliği için önlemler alınır ve yeni altyapılar kurulur; ancak eklenen her cihaz ve yazılım kendisi de bir risk oluşturur. Yeni ve geliştirilmiş kontrollerin amacı sistemdeki hataları ve zayıflıkları en aza indirmektir. Bunun için hedef kontroller belirlenir ve bu kontrollerle sorunun etkisinin büyüklüğü azaltılır. Kontrollerden sonra kalan risk (artık risk) de kendi başına bir risk oluşturabilir; bu yüzden onun da ayrıca azaltılması gerekir.

### 5.2 Maliyet-fayda analizi

Hâlâ yönetimsel süreçlerin içinde, planlama aşamasındayız. Planlamada ilk iş maliyet-fayda analizidir. Bunun nedeni, riske karşı seçeneklerden birinin riski kabullenmek olmasıdır: riski bertaraf etmek için gereken yatırım, korunan varlığın değerinden fazla olabilir ya da göze alınamayacak kadar büyük olabilir.

Slayttaki maddeler (ekrandan, 00:45:00):

- Mevcut kaynaklar göz önüne alındığında, kuruluşa en büyük faydayı sağlayan kontrolleri belirlemek için yönetim tarafından yürütülmelidir.
- Niteliksel veya niceliksel olabilir.
- Riskteki azalmayla gerekçelendirilen maliyeti göstermelidir.
- Bir kontrolün uygulanıp uygulanmamasının etkisi ile maliyet tahminini karşılaştırmalıdır.
- Yönetim, kontrol seçeneklerinden birini seçer.
- Riski çok fazla ya da yeterince azaltıp azaltmadığını, çok maliyetli ya da uygun olup olmadığını değerlendirir.
- Temelde bir iş kararıdır.

Hoca bunu basit bir benzetmeyle açıkladı: 10 liralık değerli bir varlığımız varsa, onu kaybettiğimizde 10 lira kaybederiz. Riski bertaraf etmek için yapılacak yatırımın maliyeti ile bu yatırımın ne kadarlık bir riski ortadan kaldırdığı birlikte gösterilmelidir. Bir kontrol konduğunda riskin ne kadar düşeceği ve bunun maliyetinin ne olacağı karşılaştırılır. Her kontrol seçeneği için (örneğin hizmeti üçüncü tarafa devretmek, hizmeti vermekten vazgeçmek, güvenlik duvarı almak) maliyetler ayrı ayrı çıkarılır ve yönetim bunlardan birini seçer.

> **Hocanın vurgusu:** Maliyet-fayda analizinin amacı, yönetimin riski azaltacak kontrol mekanizmalarından birini seçebilmesidir; sonuçta bu yönetimin aldığı bir iş kararıdır.

## 6. BT güvenlik planı ve uygulama planı örneği

### 6.1 BT güvenlik planının içeriği

BT güvenlik planı şunların ayrıntılarını sağlar (ekrandan, 00:50:00):

- Ne yapılacak?
- Hangi kaynaklara ihtiyaç var?
- Sorumlu kim?

Amaç, risk profilinde tespit edilen eksiklikleri iyileştirmek için gereken eylemleri detaylandırmaktır. Plan şunları içermelidir:

- Riskler, önerilen kontroller, eylem önceliği.
- Seçilen kontroller, gerekli kaynaklar.
- Sorumlu personel, uygulama tarihleri.
- Bakım gereksinimleri.

> **Hocanın vurgusu:** Güvenlik yapılıp unutulacak bir işlem değildir; bu yüzden plan bakım gereksinimlerini de içermelidir.

### 6.2 Uygulama planı örneği: internet yönlendiricisi

Hoca, planın her kalemi tek tek ayrıntılandırdığını bir internet yönlendiricisi örneğiyle gösterdi. Bu örnek altyazıdan aktarılmıştır.

<!-- BELİRSİZ: yönlendirici uygulama planı slaytı okunan karelerde yok; kalemler ve sayılar altyazıdan alındı -->

- **Varlık ve risk:** İnternet yönlendiricisi. Kuruluş internete bu cihaz üzerinden çıktığı için risk seviyesi yüksektir.
- **Önerilen kontroller:**
  - Dışarıdan (harici) telnet erişiminin devre dışı bırakılması.
  - Yapılandırmayı etkileyen yüksek öncelikli (yönetici) komutların denetime alınması.
  - Çevrimdışı sözlük saldırılarıyla ya da tahmin edilebilir yöntemlerle tahmin edilemeyecek güçlü bir parola politikası. Yönetici parolası güçlü olursa parolanın kırılması ve ardından yönlendiriciye erişilip yetkili komutların kötüye kullanılması önlenir.
  - Yönlendirici yapılandırma dosyası için yedekleme stratejisi.
  - Yönlendirici yapılandırmasının değiştirilmesi için kontrol politikası.
  - Etkilenen personel için eğitim ve ilgili prosedürlerin güncellenmesi.
- **Öncelik:** Risk seviyesi yüksek olduğu için öncelik de yüksektir; yönetim önerilen kontrollerin hepsini uygulamayı seçer.
- **Gerekli kaynak:** Yönlendirici yapılandırmasını değiştirmek, doğrulamak ve ilgili politikayı yazmak için 3 günlük BT ağ yöneticisi zamanı; yönlendiriciyi kullanan personel için 1 günlük eğitim.
- **Sorumlu:** Baş ağ/sistem yöneticisi (eğitimi de verir) ve kurumsal BT ekibinden bir kişi.
- **Zaman çizelgesi:** Üç günlük bir başlangıç-bitiş aralığı.
- **Bakım:** Yapılandırma ve politika kullanımının periyodik olarak test edilmesi ve gözden geçirilmesi; yeni ortaya çıkan risklere karşı güncellenmesi.

> **Hocanın vurgusu:** Yönlendiricinin yapılandırma yedeği yönlendiricinin içinde tutulursa, cihaza erişen biri yedeği de değiştirebilir. Bu yüzden yedeğin nerede tutulacağı da politikanın parçasıdır.

## 7. Güvenlik planının uygulanması ve takibi

### 7.1 Planın uygulanması

Uygulama aşamasında elde bir plan ve tanımlanmış personel vardır (ekrandan, 00:55:00):

- **BT güvenlik planı belgeleri:** seçilen her kontrol için yapılması gerekenler, sorumlu personel, kaynaklar ve zaman çerçevesi.
- **Tanımlanan personel:** yeni veya gelişmiş denetimleri uygular. Bu iş sistem yapılandırma değişikliklerine, yükseltmelere ya da yeni sistem kurulumuna ihtiyaç duyabilir; yeni veya genişletilmiş prosedürlerin geliştirilmesini de içerebilir. Süreç yönetim tarafından teşvik edilmeli ve izlenmelidir; hoca güvenliğe özen gösteren personelin teşvik edilmesi gerektiğini ekledi.
- **Uygulama tamamlandığında** yönetim, sistemi operasyonel kullanım için yetkilendirir.

### 7.2 Uygulamanın takibi

Güvenlik yönetimi döngüsel bir süreçtir: tasarlanır, planlanır, uygulanır, kontrol edilir; bir güncelleme gerekiyorsa yeniden plan aşamasına dönülür ve süreç tekrarlanır. Bilgi sistemindeki ve risk ortamındaki değişikliklere yanıt verebilmek için bu süreç sürekli tekrarlanmalıdır. Uygulanan kontrollerin gerçekten riski azaltıp azaltmadığı izlenmeli, güvenliği etkileyen değişiklikler değerlendirilmelidir; aksi halde güvenlik ihlali olasılığı artar.

Takibin birçok yönü vardır:

- Güvenlik kontrollerinin bakımı (kontrollerin de güncellenmesi).
- Güvenlik uyumluluğunun denetimi.
- Değişiklik ve konfigürasyon yönetimi.
- Olay yönetimi.

### 7.3 Bakım onarım

Sürekli doğru işleyişi ve uygunluğu sağlamak için uygulanan kontrollerin sürekli bakımına ve izlenmesine ihtiyaç vardır. Amaç kontrollerin amaçlandığı gibi çalışmasını sağlamaktır. Bakım onarım kapsamındaki görevler:

- Kontrollerin periyodik olarak gözden geçirilmesi.
- Yeni gereksinimleri karşılamak için kontrollerin güncellenmesi.
- Sistem değişikliklerinin kontrolleri olumsuz etkilemediğinin denetlenmesi.
- Yeni tehditlerin ve güvenlik açıklarının ele alınması.

### 7.4 Güvenlik uyumluluğu

Slayttaki maddeler (ekrandan, 01:00:00):

- Güvenlik süreçlerini gözden geçirmek için yapılan denetim sürecidir.
- Amaç, güvenlik planına uygunluğu doğrulamaktır.
- Dahili veya harici personel kullanılır. Hoca, kurum içindeki personelin yanında dışarıdan bir "üçüncü göz" olarak harici personelden de yararlanılabileceğini söyledi.
- Genellikle şunları doğrulayan kontrol listelerinin kullanımına dayanır: uygun politikalar ve planlar oluşturuldu mu, uygun kontroller seçildi mi, bakımlar yapıldı ve doğru kullanıldı mı.
- Genellikle daha geniş kapsamlı genel bir denetimin parçasıdır.

### 7.5 Değişiklik ve konfigürasyon yönetimi

Güvenlik yeni tehditlere bağlı olarak sürekli güncellendiği için değişiklik ve konfigürasyon yönetimi de güvenliğin bir parçasıdır.

- **Değişiklik yönetimi:** Sistemlerde önerilen değişiklikleri gözden geçirme sürecidir; gayri resmi (informal) ya da resmi (formal) olabilir. Eklenen yamaların mevcut uygulamaları olumsuz etkilemediğinden emin olmak için test edilmesi gerekir. Değişikliğin etkisi değerlendirilmeli; bazı durumlarda etki çok büyükse değişiklik göze alınmayabilir. Genel sistem yönetimi sürecinin önemli bir bileşenidir.
- **Konfigürasyon yönetimi:** Kullanımdaki her sistemin konfigürasyonunu ve yapılan değişiklikleri takip eder. Hangi yamaların ya da yükseltmelerin gerektiğini bilmekle ilgilidir ve genel sistem yönetimi sürecinin parçasıdır. Bir sorundan sonra sistemi geri yükleyebilmek için her sistemde yüklü donanım ve yazılım sürümlerinin listesi saklanmalıdır.

Hoca bunun nedenini şöyle açıkladı: bir hata oluştuğunda hangi yamaların yapıldığı ve hangi programın hangi sürümünün kullanıldığı bilinmelidir; uygulama harici kütüphaneler kullanıyorsa o kütüphanelerin sürümleri de programın çalışması için önemlidir.

## 8. Vaka çalışması: Gümüş Yıldız Madenleri uygulama planı

Önceki dersteki risk değerlendirmesinin ardından bir sonraki aşama, bu riskler için kontrolleri belirlemektir. Değerlendirmeye göre:

- Birçok kontrol kategorisinin kullanımda olmadığı açıktır.
- Sistemlerin yamalanmaması ya da yükseltilmemesiyle ilgili bir sorun olabilir.
- Acil durum planlamasına ihtiyaç vardır.
- SCADA ağına izinsiz giriş tespit sistemi eklenmesi gerekebilir.
- Veri bütünlüğü için depolamanın daha iyi merkezileştirilmesi ve e-posta sistemi için bir yedekleme sistemi düşünülebilir.

Uygulama planı tablosu (ekrandan, 01:05:00):

| Risk (Varlık/Tehdit) | Risk Seviyesi | Önerilen Kontroller | Öncelik | Seçilen Kontroller |
|---|---|---|---|---|
| Tüm riskler (genel olarak uygulanabilir) | — | 1. Sunucular için yapılandırma ve periyodik bakım politikası; 2. Kötü amaçlı kod (SPAM, casus yazılım) önleme; 3. Sunucularda denetim izleme, analiz, azaltma ve raporlama; 4. Acil durum planlaması ve olay müdahale politikaları ve prosedürleri; 5. Sistem yedekleme ve kurtarma prosedürleri | 1 | 1, 2, 3, 4, 5 |
| SCADA düğümlerinin ve ağının güvenilirliği ve bütünlüğü | Yüksek | 1. Saldırı tespit ve müdahale sistemi | 2 | 1 |
| Depolanan dosya ve veritabanı bilgilerinin bütünlüğü | Ekstrem | 1. Kritik belgelerin denetimi; 2. Belge oluşturma ve saklama politikası; 3. Kullanıcı güvenliği eğitimi | 3 | 1, 2, 3 |
| Mali, tedarik ve bakım/üretim sistemlerinin kullanılabilirliği ve bütünlüğü | Yüksek | — | — | (Genel kontrol) |
| Posta hizmetlerinin kullanılabilirliği, bütünlüğü ve gizliliği | Yüksek | 1. Acil durum planlaması — yedek e-posta hizmeti | 4 | 1 |

Hoca tabloyu satır satır açıkladı:

- **Genel kontroller** bütün risklere karşı alınabilecek ortak önlemlerdir; önceliği birinci sıradadır ve yönetim beşinin de uygulanmasını seçmiştir.
- **SCADA ağı:** risk yüksektir; çünkü buraya yapılacak bir saldırı hayati sonuçlar doğurabilir. Önerilen kontrol bir saldırı tespit ve müdahale sistemidir.
- **Depolanan dosya ve veritabanı bütünlüğü:** önerilen üç kontrolün (kritik belgelerin denetimi, belge oluşturma ve saklama politikası, kullanıcılara güvenlik eğitimi) üçü de yönetimce seçilmiştir.
- **Mali, tedarik ve bakım/üretim sistemleri:** ayrıca önerilen bir kontrol yoktur; genel kontrollerle sürekli izlenir.
- **E-posta hizmeti:** acil durum planlaması kapsamında yedek bir e-posta sistemi kurulması önerilmiş ve seçilmiştir.

<!-- BELİRSİZ: hoca SCADA satırını anlatırken önceliği "bir numara ... hepsi iki" gibi karışık okudu; tablodaki değerler kareden alındı -->

> **Ders sonrası not:** Slaytta SCADA satırı İngilizce kalmış ("Reliability and integrity of SCADA nodes and network"); hoca da bunun çevrilmeyi unutulduğunu söyledi. Tablodaki "Genel Kontol" yazımı "Genel kontrol" olarak, "Ekstrim" yazımı "Ekstrem" olarak düzeltildi.

> **Hocanın vurgusu:** Bu plan yalnız bir tablo değildir. Önerilen her kontrolün bir maliyeti ve süresi vardır; plan, derste anlatılan ayrıntılarla birlikte hangi personelin sorumlu olduğunu, ne kadar maliyetli olduğunu ve ne kadar sürede yapılacağını da içerir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:13:20): Varlıklarımız üzerindeki risklere nasıl müdahale edebiliriz? Riske verilebilecek yanıtlar nelerdir?

> **Cevap (derste verildi):** Riske dört biçimde yanıt verilebilir: kabul etmek (gerçekleşirse katlanmak), kaçınmak (riskli işi yapmamak, örneğin e-posta hizmetini kapatmak), hafifletmek (prosedür ve önlemlerle riski azaltmak), paylaşmak ya da devretmek (üçüncü taraflarla). Yanıta göre kontrol seçenekleri değerlendirilir, kontroller seçilir, uygulama planı geliştirilir ve uygulanır.

**Soru 2** (derste sözlü, 00:47:32): Bir BT güvenlik planı neleri içerir?

> **Cevap (derste verildi):** Ne yapılacağını, hangi kaynaklara ihtiyaç olduğunu ve sorumlunun kim olduğunu ayrıntılandırır. İçeriği: riskler, önerilen kontroller ve öncelikleri; seçilen kontroller ve gerekli kaynaklar; sorumlu personel ve uygulama tarihleri; bakım gereksinimleri.

**Soru 3** (derste sözlü, 00:44:37): Riski bertaraf etmek mümkünken neden riski kabullenmek tercih edilebilir?

> **Cevap (derste verildi):** Riski bertaraf etmek için yapılacak yatırım, korunan varlığın değerinden fazla olabilir ya da göze alınamayacak kadar büyük olabilir. Bu yüzden yönetim maliyet-fayda analizi yaparak her kontrolün maliyetini riskteki azalmayla karşılaştırır ve bir iş kararı verir.

## Dersin Toparlaması

Bu derste, önceki derste yapılan risk değerlendirmesinden sonra gelen adımlar ele alındı. Riskler önceliklendirildikten sonra her risk için bir yanıt (kabul, kaçınma, hafifletme, paylaşma) seçilir; yanıta göre kontrol seçenekleri değerlendirilir, maliyet-fayda analiziyle uygun olanlar seçilir ve bir BT güvenlik planına dönüştürülür. Kontroller yönetim, operasyonel ve teknik olarak üç sınıfa; işlevine göre de destekleyici, önleyici ve algılama-kurtarma olarak üç türe ayrılır. NIST SP 800-53 ve ISO/IEC 27002, bu kontrolleri aileler ve kategoriler halinde listeleyen iki temel standarttır.

Plan uygulandıktan sonra süreç bitmez: güvenlik yönetimi döngüseldir. Kontrollerin bakımı, güvenlik uyumluluğu denetimi, değişiklik ve konfigürasyon yönetimi ve olay yönetimi ile kontrollerin beklenen etkiyi sürdürüp sürdürmediği izlenir. Gümüş Yıldız Madenleri vaka çalışmasında bu adımlar uygulanarak her risk için önerilen kontroller, öncelikler ve yönetimin seçtiği kontroller bir uygulama planı tablosunda toplandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
