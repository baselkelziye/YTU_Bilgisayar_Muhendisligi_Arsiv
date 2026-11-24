# Ders 4 Çalışma Özeti

## Genel Konular

- Önceki dersle bağlantı: BT güvenlik yönetimi ve risk değerlendirmesi
  - Önceki derste BT ve bilgisayar sistemleri güvenliği yönetimi bağlamında risk değerlendirmesi yapılmış, örnek bir maden şirketinin (Gümüş Yıldız Madenleri / Silver Star Mines) riskleri belirlenip önceliklendirilmişti.
  - Bu derste o risk analizinin üzerine güvenlik kontrolleri, güvenlik planı ve güvenlik prosedürleri eklenir.
  - Bu ders lisans düzeyindeki teknik güvenlik konularının üzerine kurulan, daha üst düzey ve yönetimsel süreçleri ele alır.
- BT güvenlik yönetimi kontrolleri ve uygulaması (ekrandan, 00:15:00)
  - Adım 1, riskleri önceliklendirmek: risklerin yönetim tarafından gözden geçirilmesi.
  - Adım 2, risklere müdahale etmek:
    - Risk yanıtını belirlemek: kabul et, kaçın, hafiflet, paylaş.
    - Önerilen kontrol seçeneklerini değerlendirmek.
    - Kontrolleri seçmek.
    - Uygulama planı geliştirmek.
    - Seçili kontrolleri uygulamak.
  - Adım 3, riskleri izlemek: uygulanan kontrollerin riski planlanan ölçüde giderip gidermediğinin takibi.
- Güvenlik kontrolünün tanımı
  - Kontrol; bir güvenlik ihlalini ortadan kaldırarak ya da önleyerek, neden olabileceği zararı en aza indirerek veya ihlali keşfedip raporlayıp düzeltici eylemi mümkün kılarak riski azaltan bir eylem, cihaz, prosedür ya da başka bir önlemdir.
  - Standart dokümanlarda güvenlik kontrolü bu biçimde tanımlanır.
- Kontrol sınıflandırmaları (ekrandan, 00:20:00)
  - Yönetim kontrolleri: kayıp riskini azaltmak ve kuruluşun misyonunu korumak için operasyonel ve teknik kontrollerin seçimini etkileyen güvenlik politikalarına, planlamaya, yönergelere ve standartlara odaklanır; yönetimin ele alması gereken hususları ifade eder.
  - Operasyonel kontroller: yönetimin belirlediği güvenlik politikaları ve standartlarının doğru uygulanmasını ve kullanımını ele alır, güvenlik operasyonlarında tutarlılık sağlar ve tespit edilen operasyonel eksiklikleri düzeltir. Sistemlerden çok insanlar tarafından uygulanan mekanizma ve prosedürlerle ilgilidir.
  - Teknik kontroller: sistemlerde donanım ve yazılım güvenlik özelliklerinin doğru kullanımıdır; kritik ve hassas verileri ve BT sistem işlevlerini güvenceye almak için birlikte çalışan, basitten karmaşığa uzanan önlemlerdir.
  - Hoca bu yapıyı hiyerarşik olarak özetledi: yönetim strateji ve yönergeleri belirler, buna göre planlama yapılır, teknik kontroller en basitten en karmaşığa uygulanır.
- Teknik güvenlik kontrollerinin katmanlı yapısı
  - Bir tarafta kaynaklar, diğer tarafta kullanıcılar ya da işlemler bulunur; arada katmanlı kontroller yer alır.
  - Anlatımda geçen bileşenler: nesne yeniden kullanımı, süreç ayırma, güvenlik yönetimi, korumalı iletişim (işlem gizliliği, inkâr edememe), kimlik doğrulama, yetkilendirme, erişim kontrolü, durumu geri yükleme, izinsiz giriş tespiti ve engelleme. <!-- BELİRSİZ: katmanlı diyagramın slaytı karelerde yok; bileşenler ve aralarındaki bağlantılar yalnız altyazıdan alındı -->
- Kontrol türleri (işlevine göre)
  - Her kontrol sınıfı (yönetim, operasyonel, teknik) şu türlerden birini ya da birkaçını içerir:
    - Destekleyici kontroller: diğer birçok kontrolün dayandığı ve kullandığı yaygın, genel, temel teknik BT güvenlik yetenekleri.
    - Önleyici kontroller: güvenlik politikasını ihlal etme ya da bir güvenlik açığından yararlanma girişimlerini engelleyerek ihlalin oluşmasını önler.
    - Algılama ve kurtarma kontrolleri: ihlal ya da ihlal girişimi konusunda uyarır ve kaybedilen BT kaynaklarını geri yüklemek için araç sağlayarak ihlale verilen yanıta odaklanır.
- NIST SP 800-53 güvenlik kontrol aileleri (ekrandan, 00:25:00)
  - Yönetim: Planlama; Program Yönetimi; Risk Değerlendirmesi; Güvenlik Değerlendirmesi ve Yetkilendirme; Sistem ve Hizmet Alımı.
  - Operasyonel: Farkındalık ve Eğitim; Konfigürasyon Yönetimi; Acil Durum Planlaması; Olay Müdahalesi; Bakım Onarım; Medya Koruması; Personel Güvenliği; Fiziksel ve Çevresel Koruma; Sistem ve Bilgi Bütünlüğü.
  - Teknik: Giriş (erişim) Kontrolü; Denetim ve Hesap Verebilirlik; Tanımlama ve Kimlik Doğrulama; Sistem ve İletişim Koruması.
- ISO/IEC 27002 güvenlik kontrol kategorileri ve amaçları
  - Güvenlik politikaları, bilgi güvenliği organizasyonu, insan kaynakları güvenliği, varlık yönetimi, erişim kontrolü, kriptografi, fiziksel ve çevresel güvenlik (altyazıdan).
  - Operasyon güvenliği, iletişim güvenliği, sistem edinimi-geliştirme-bakım, tedarikçi ilişkileri, bilgi güvenliği olay yönetimi, bilgi güvenliği sürekliliği, uyma (ekrandan, 00:30:00).
- Detaylı NIST SP 800-53 kontrolleri (ekrandan, 00:35:00 ve 00:40:00)
  - Her kontrol ailesinin altında politika ve prosedürlerle başlayan ayrıntılı kontrol listeleri vardır (örneğin giriş kontrolünde hesap yönetimi, görevlerin ayrılması, en az ayrıcalık, oturum kilitleme, referans monitör).
- Artık risk ve maliyet-fayda analizi
  - Eklenen her yeni cihaz ve yazılım kendisi bir risk oluşturabilir; yeni ve geliştirilmiş kontrollerle hata ve zayıflıklar en aza indirilir, sorunun etkisinin büyüklüğü azaltılır, geriye kalan artık risk de ayrıca ele alınmalıdır.
  - Maliyet-fayda analizi (ekrandan, 00:45:00): mevcut kaynaklar göz önüne alındığında kuruluşa en büyük faydayı sağlayan kontrolleri belirlemek için yönetim tarafından yürütülür; niteliksel ya da niceliksel olabilir; riskteki azalmayla gerekçelendirilen maliyeti gösterir; kontrolü uygulamanın ve uygulamamanın etkisi maliyet tahminiyle karşılaştırılır; yönetim seçeneklerden birini seçer; temelde bir iş kararıdır.
- BT güvenlik planı (ekrandan, 00:50:00)
  - Ne yapılacağını, hangi kaynaklara ihtiyaç olduğunu ve sorumlunun kim olduğunu ayrıntılandırır.
  - Amaç, risk profilinde tespit edilen eksiklikleri iyileştirmek için gereken eylemleri detaylandırmaktır.
  - İçermesi gerekenler: riskler, önerilen kontroller ve eylem önceliği; seçilen kontroller ve gerekli kaynaklar; sorumlu personel ve uygulama tarihleri; bakım gereksinimleri.
- Uygulama planı örneği: internet yönlendiricisi (altyazıdan)
  - Varlık internet yönlendiricisi, risk seviyesi yüksek; önerilen kontroller: harici telnet erişiminin kapatılması, yüksek öncelikli (yetkili) komutların denetime alınması, güçlü parola politikası, yapılandırma dosyası için yedekleme stratejisi, yapılandırma değişikliği kontrol politikası, etkilenen personelin eğitimi.
  - Gerekli kaynak: 3 günlük ağ yöneticisi zamanı ve kullanıcılar için 1 günlük eğitim; sorumlu: baş ağ/sistem yöneticisi; ardından periyodik test ve gözden geçirme.
- Güvenlik planının uygulanması (ekrandan, 00:55:00)
  - Plan belgeleri: seçilen her kontrol için yapılması gerekenler, sorumlu personel, kaynaklar ve zaman çerçevesi.
  - Tanımlanan personel yeni ya da gelişmiş denetimleri uygular; bu iş sistem yapılandırma değişikliği, yükseltme ya da yeni sistem kurulumu ve yeni prosedürler gerektirebilir; yönetim teşvik etmeli ve izlemelidir.
  - Uygulama tamamlanınca yönetim sistemi operasyonel kullanım için yetkilendirir.
- Uygulamanın takibi
  - Güvenlik yönetimi döngüseldir: planla, uygula, kontrol et, gerekirse yeniden planla.
  - Takibin bileşenleri: güvenlik kontrollerinin bakımı, güvenlik uyumluluğu denetimi, değişiklik ve konfigürasyon yönetimi, olay yönetimi.
- Bakım onarım, güvenlik uyumluluğu, değişiklik ve konfigürasyon yönetimi
  - Bakım: kontrollerin periyodik gözden geçirilmesi, yeni gereksinimlere göre güncellenmesi, sistem değişikliklerinin kontrolleri olumsuz etkilememesi, yeni tehdit ve açıkların ele alınması.
  - Güvenlik uyumluluğu (ekrandan, 01:00:00): güvenlik süreçlerini gözden geçiren denetimdir; amaç güvenlik planına uygunluğu doğrulamaktır; dahili ya da harici personel kullanılır; kontrol listelerine dayanır; genellikle daha geniş kapsamlı bir denetimin parçasıdır.
  - Değişiklik yönetimi önerilen değişiklikleri (resmi ya da gayri resmi) gözden geçirme sürecidir; konfigürasyon yönetimi her sistemin konfigürasyonunu, yapılan değişiklikleri, yüklü donanım ve yazılım sürümlerini takip eder.
- Vaka çalışması: Gümüş Yıldız Madenleri uygulama planı (ekrandan, 01:05:00)
  - Risk değerlendirmesine göre birçok kontrol kategorisinin kullanılmadığı, yama/yükseltme sorunları olabileceği, acil durum planlamasına ve SCADA ağına saldırı tespit sistemine ihtiyaç olduğu, depolamanın merkezileştirilmesi ve e-posta için yedek sistem gerektiği belirlendi.
  - Risklere göre önerilen kontroller, öncelikler ve seçilen kontroller tablo halinde verildi (ayrıntı genişletilmiş notta).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kontrol sınıflarının hiyerarşik yapısı
  - Standartları, politikaları ve yönergeleri belirleyen yönetimdir; operasyonel kontroller bunları insanlar eliyle uygular; teknik kontroller donanım ve yazılım özellikleriyle gerçekleşir.
- Riske verilecek yanıtın maliyete bağlı olması
  - Riski bertaraf etmenin maliyeti varlığın değerinden fazlaysa risk kabullenilebilir; bu nedenle maliyet-fayda analizi yönetimin bir iş kararıdır.
- Güvenlik bir kez yapılıp unutulan bir iş değildir
  - Planda bakım gereksinimleri bulunmalı; güvenlik yönetimi döngüsel bir süreç olarak sürekli tekrarlanmalıdır, aksi halde ihlal olasılığı artar.
- Yedeğin nerede tutulduğu
  - Yönlendirici yapılandırmasının yedeği yönlendiricinin içinde tutulursa, cihaza erişen saldırgan yedeği de değiştirebilir.
- Güvenlik planı yalnız bir tablo değildir
  - Her kontrolün sorumlu personeli, maliyeti ve süresi de planın parçasıdır.

## Kısa Tekrar Notları

- Risk yönetimi üç adım: önceliklendir, müdahale et, izle.
- Risk yanıtları: kabul et, kaçın, hafiflet, paylaş (devret).
- Kontrol sınıfları: yönetim, operasyonel, teknik.
- Kontrol türleri: destekleyici, önleyici, algılama ve kurtarma.
- NIST SP 800-53: 5 yönetim, 9 operasyonel, 4 teknik kontrol ailesi.
- ISO/IEC 27002: her kontrol kategorisi bir amaçla tanımlanır.
- Maliyet-fayda analizi: yönetim yürütür, niteliksel ya da niceliksel olabilir, temelde iş kararıdır.
- BT güvenlik planı: ne yapılacak, hangi kaynakla, kim sorumlu, ne zaman, bakım gereksinimi.
- Uygulama sonrası: bakım, güvenlik uyumluluğu denetimi, değişiklik ve konfigürasyon yönetimi, olay yönetimi.
- Konfigürasyon yönetimi geri yükleme için yüklü donanım/yazılım sürümlerini (kütüphane sürümleri dahil) kaydeder.

## Detaylı Açıklamalar

- Risk değerlendirmesi bir kuruluşun varlıklarını ve bu varlıklar üzerindeki riskleri ortaya koyar; ancak tek başına koruma sağlamaz. Bu derste değerlendirmenin ardından gelen adımlar anlatıldı. Yönetim riskleri gözden geçirip önceliklendirdikten sonra her risk için bir yanıt seçer. Risk kabul edilebilir (gerçekleşirse katlanılır), riskli işten vazgeçilerek kaçınılabilir (örneğin riskli e-posta hizmetini tamamen kapatmak), prosedür ve önlemlerle hafifletilebilir ya da üçüncü taraflarla paylaşılabilir veya devredilebilir. Seçilen yanıta göre olası kontroller değerlendirilir, uygun olanlar seçilir, bir uygulama planına dönüştürülür ve uygulanır. Son adım, kontrollerin beklenen etkiyi gösterip göstermediğini izlemektir.
- Kontroller iki boyutta sınıflanır. Birinci boyut kimin uyguladığıdır: yönetim kontrolleri politika, plan ve standart düzeyindedir; operasyonel kontroller bu politikaların insanlar eliyle uygulanmasıdır; teknik kontroller donanım ve yazılımın güvenlik özelliklerinin doğru kullanılmasıdır. İkinci boyut kontrolün işlevidir: destekleyici kontroller diğer kontrollerin dayandığı temel yeteneklerdir, önleyici kontroller ihlali baştan engeller, algılama ve kurtarma kontrolleri ise ihlali fark edip sistemi geri yüklemeye yarar.
- NIST SP 800-53 ve ISO/IEC 27002 bu kontrolleri aileler ve kategoriler halinde listeleyen iki standart dokümandır. NIST tablosunda her aile yönetim, operasyonel ya da teknik sınıfa bağlanır; detaylı listelerde her ailenin altında, politika ve prosedürlerle başlayan somut kontroller sayılır. ISO/IEC 27002 ise her kontrol kategorisi için bir amaç tanımlar; örneğin kriptografinin amacı bilginin gizliliğini, gerçekliğini ve bütünlüğünü korumak için kriptografinin doğru ve etkin kullanımını sağlamaktır.
- Kontroller maliyetsiz değildir ve eklenen her yeni cihaz ya da yazılım kendisi yeni bir risk kaynağı olabilir. Bu yüzden yönetim, her kontrol seçeneğinin maliyetini ve riski ne kadar azalttığını karşılaştıran bir maliyet-fayda analizi yapar. Seçilen kontroller BT güvenlik planına yazılır: her kontrol için ne yapılacağı, gerekli kaynak, sorumlu personel, uygulama tarihleri ve bakım gereksinimleri. Derste internet yönlendiricisi örneğinde harici telnet erişiminin kapatılması, yetkili komutların denetlenmesi, sözlük saldırısına dayanıklı güçlü parola politikası ve yapılandırma yedekleme stratejisi gibi kontroller, 3 günlük ağ yöneticisi zamanı ve 1 günlük eğitimle planlandı.
- Plan uygulandıktan sonra süreç bitmez. Kontrollerin bakımı yapılır, güvenlik uyumluluğu kontrol listeleriyle denetlenir, değişiklikler değişiklik ve konfigürasyon yönetimiyle kayıt altına alınır, olaylar olay yönetimiyle ele alınır. Hangi sistemde hangi yazılım ve kütüphane sürümünün yüklü olduğunun bilinmesi, bir hata sonrası geri yükleme için önemlidir. Vaka çalışmasında Gümüş Yıldız Madenleri için genel kontroller (sunucu bakım politikası, kötü amaçlı kod önleme, denetim izleme, acil durum planlaması, yedekleme) birinci önceliğe, SCADA düğümleri için saldırı tespit ve müdahale sistemi ikinci önceliğe, depolanan dosya ve veritabanı bütünlüğü üçüncü önceliğe, e-posta hizmeti için yedek e-posta sistemi dördüncü önceliğe konuldu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
