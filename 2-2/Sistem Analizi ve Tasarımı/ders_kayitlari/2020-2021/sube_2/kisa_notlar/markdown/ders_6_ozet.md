# Ders 6 Çalışma Özeti

## Genel Konular

- Dersin yeri ve kapsamı (ekrandan, 00:10:00)
  - Slayttaki başlıklar: Sistem Analizi, Fonksiyonel Çözümleme, SRS, Kavramsal Modelin Oluşturulması.
  - Önceki hafta iş analizi ve iş gereksinimleri belgesi (business requirements document) işlenmişti. Bu hafta daha teknik tarafa geçilir: fonksiyonel (yapısal, işlevsel) çözümleme ve yazılım gereksinim tanımları belgesi (SRS).
  - Problem uzayını modellemede iki temel yaklaşım vardır: yapısal (geleneksel, fonksiyonel) çözümleme ve nesneye yönelik çözümleme. Nesneye yönelik kavramsal model (use case ve alan modeli) sonraki derse bırakılır.
- Gereksinim analizinin amacı
  - Gereksinimleri herkesin aynı şeyi anlayacağı biçimde, formal olarak tanımlamak ve tasarıma zemin hazırlamak.
  - Analiz modeli aynı zamanda sürecin sonundaki test ve onay için bir denetim listesi olur: devreye alınan sistem senaryolardaki işleri doğru yapıyor mu, analiz modeline dönülerek kontrol edilir.
- Gereksinim analizi modeli (tekerlek modeli) (ekrandan, 00:15:00)
  - Dış halka üç eşit parçadır: Süreç Spesifikasyonu, Veri Nesne Tanımı, Kontrol Spesifikasyonu. Ortada Veri Sözlüğü bulunur.
  - Süreç spesifikasyonu Veri Akış Diyagramı (VAD, İngilizcesi DFD) ile, veri nesneleri Varlık İlişki Diyagramı (ERD) ile, kontrol spesifikasyonu Durum Geçiş Diyagramı (STD) ile modellenir.
  - Veri Sözlüğü: tüm veri nesnelerinin tanımları (metadata, yani veriyi tanımlayan veri).
  - Kontrol spesifikasyonu ders kapsamı dışındadır; ERD tasarım konularıyla birlikte ileriki haftalarda işlenir. Bu dersin odağı süreç spesifikasyonu ve veri sözlüğüdür.
- Veri akış diyagramının öğeleri (ekrandan, 00:25:00)
  - Varlıklar (dış varlıklar, aktörler), süreçler (işlemler), veri depoları ve aralarındaki veri akışları.
  - Slayttaki örnek: Öğrenci → (Kimlik Bilgileri) → 1.1 Yeni Öğrenci Kaydı → (Yeni öğrenci bilgisi) → D1 Öğrenciler. Hoca aynı akışı ikiye bölerek 1.2 Danışman Ataması sürecine ve YÖK dış varlığına da gönderdi (ekrandan, 00:30:00).
  - Kurallar: birden fazla varlık olabilir; okların çakışmaması için aynı varlık tekrarlanabilir; oklar tek yönlüdür; okların tek bir kaynağı ve hedefi vardır; işlemler hiyerarşiye uygun numaralandırılır (1.0, 2.0; alt süreçler 1.1, 1.2).
- VAD sembolleri (ekrandan, 00:35:00)
  - İki sembol ailesi vardır: DeMarco ve Yourdon (süreç daire, veri deposu üstü ve altı çizgili) ile Gane ve Sarson (süreç numaralı, köşeleri yuvarlatılmış dikdörtgen; veri deposu D1, D2 ... kutulu açık dikdörtgen). Derste Gane ve Sarson kullanılır.
  - Harici varlık dikdörtgendir; tekrar eden varlığın köşesine çentik atılır.
  - Süreç adı emir kipinde fiildir ("Profil Bilgileri Gir"); veri akışı adı isimdir. "Doğrula" adlı bir veri akışı yanlıştır, "doğrulanmış veri" gibi bir ad olmalıdır.
- VAD kuralları (ekrandan, 00:40:00)
  - Bir işlemin yalnız çıkışı ya da yalnız girişi olamaz: girdi, işlem, çıktı.
  - İşlem girişleri istenen çıkışı üretecek kadar yeterli olmalıdır (maaş hesaplama için yalnız çalışma saatleri yetmez, çalışan bilgileri de gerekir).
  - Her veri deposu bir işlemle ilgili olmalıdır: veri deposundan veri deposuna doğrudan akış olmaz.
  - Veri deposu bir varlıkla doğrudan ilişkide olamaz: arada bir işlem bulunmalıdır.
  - Veri akışı oku iki yönlü olamaz; karşılıklı akış farklı tek yönlü oklarla gösterilir.
  - Aynı veri birden çok işleme gidiyorsa tek akışın dallanmasıyla gösterilir; işlemin hiçbir işlemden geçmeden kendine dönmesi uygun değildir.
- VAD düzeyleri (ekrandan, 00:45:00; 00:55:00; 01:00:00)
  - Taslak (bağlam, context, düzey 0) VAD: ön inceleme sonucunda belirlenir, tüm sistem tek bir süreçtir, çevresinde dış varlıklar ve temel veri akışları bulunur; ayrıntılı süreç ve veri depoları yoktur.
  - 1. düzey VAD: süreçleri, ilişkili veri depolarını ve süreçlerin birbiriyle ve dış kaynaklarla ilişkisini gösterir. Bağlam VAD kullanıldıysa "Düzey 0 VAD" diye de adlandırılır.
  - 2. düzey VAD: her sürecin alt işlemlerini ayrıntılı gösterir. Gerekmeyen süreçler için çizilmeyebilir. Derste üçüncü düzeye inilmez.
- Düzeyler arası tutarlılık (ekrandan, 01:05:00; 01:15:00)
  - Alt düzeyde bağlam diyagramında olmayan yeni dış varlık ya da dış varlıkla yeni veri akışı ortaya çıkamaz. İç süreçler, veri depoları ve iç akışlar alt düzeyde yeni ortaya çıkabilir.
- Kavramsal veri modeli ve varlık ilişki diyagramları (ekrandan, 01:20:00)
  - Yüksek seviyelidir, kullanıcı topluluğuyla iletişim içindir; veri yapısı, donanım, yazılım bilgisi içermez. ERD veri nesnelerini ve aralarındaki ilişkileri grafiksel olarak gösterir. Ayrıntısı ileriki haftalarda ve veri tabanı dersindedir.
- Mantıksal ve fiziksel VAD (ekrandan, 01:25:00)
  - Mantıksal VAD analiz safhasının ürünüdür: işler, varlıklar, veriler ve akışlar. Fiziksel VAD donanım, yazılım, dosya ve insan kaynağı ayrıntısını ekler ve tasarımın ürünüdür. Aksi söylenmedikçe VAD denince mantıksal VAD kastedilir.
- Süreç tanımlama formu ve süreç mantığı (ekrandan, 01:30:00)
  - Her süreç için form doldurulur: No, Ad, Tanım, Girdi Veri Akışı, Çıktı Veri Akışı, Süreç Tipi (Çevrimiçi, Otomatik, El ile), Süreç Mantığı, Çözülmeyen Sorunlar.
  - Süreç mantığı üç yolla anlatılır: akış diyagramı ya da yapısal dil (pseudocode), karar tabloları, karar ağaçları.
- Yapısal dil blokları (ekrandan, 01:35:00)
  - Ardışık blok, karar (IF-THEN-ELSE-END IF), durum kontrol (SELECT CASE ... END CASE), döngü (DO WHILE ... ENDDO ya da DO ... UNTIL).
- Karar tabloları ve karar ağaçları (ekrandan, 01:40:00)
  - Karar tablosu durumlar, kurallar, işlemler ve kararlardan oluşur; karmaşık kararlar için kullanılır. Karar ağacı daha basit yapılar için uygundur; ikisi birbirine dönüştürülebilir.
- Veri sözlüğü (ekrandan, 01:45:00; 01:50:00)
  - Sadece VAD yeterli değildir; tüm bilişim maddeleri tanımlanmalıdır: veri akış, veri deposu, veri yapısı, veri elemanı ve işlem sözlük girişleri.
- SRS ve IEEE 830 (ekrandan, 01:55:00)
  - Gerçek bir projenin iş gereksinimleri listesi ve IEEE 830 SRS şablonu gösterildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- VAD'da esas olan oklardır
  - Kutular varlık, işlem ve depo anlamı taşır; ama diyagramın amacı süreci işletmek için gereken veri akışlarını göstermektir.
- Veri akışı adı isim, süreç adı fiil olmalıdır
  - Akış adında fiil varsa o bir iştir ve süreç olarak modellenmelidir: "Siparişi Doğrula" değil "Doğrulanmış Sipariş", "Zaman Çizelgesini Tamamla" değil "Tamamlanmış Zaman Çizelgesi".
- İki yönlü ok kullanılmaz
  - Karşılıklı iki akış farklı verilerdir; ayrı adlı, ayrı tek yönlü oklarla gösterilir.
- Veri deposundan depoya ya da dış varlıktan depoya doğrudan akış olmaz
  - Arada mutlaka bir işlem olmalıdır.
- Düzeyler arası tutarlılık esastır
  - Hiçbir dış varlık ya da dış akış alt düzeyde yoktan var olmaz, yok olmaz.
- Farklı veri akışları tek okta birleştirilmez
  - Bir oku az çizmek tasarruf gibi görünse de iki farklı akışı aynıymış gibi göstermek yanlıştır.
- Veri sözlüğü kurumsal ve proje hafızasıdır
  - Ekipten ayrılan analistin bilgisinin kaybolmaması ve bakım için gereklidir. Güncel tutulması zahmetlidir; model değiştikçe sözlük de gözden geçirilmelidir.

## Kısa Tekrar Notları

- Gereksinim analizi modeli: süreç (VAD), veri (ERD), kontrol (STD) ve merkezde veri sözlüğü.
- VAD öğeleri: dış varlık, süreç, veri deposu, veri akışı.
- Gane ve Sarson: numaralı yuvarlatılmış dikdörtgen süreç, D1 kutulu açık dikdörtgen depo, dikdörtgen dış varlık, çentikli köşe tekrar eden varlık.
- Süreç adı emir kipinde fiil, akış adı isim, her süreç tek bir etkinlik.
- Yasaklar: yalnız girişli ya da yalnız çıkışlı işlem, depodan depoya akış, varlıktan depoya akış, iki yönlü ok, işlemsiz kendine dönen akış.
- Düzeyler: taslak (bağlam, düzey 0) → 1. düzey → 2. düzey; adlandırma kaynağa göre kayabilir.
- Mantıksal VAD analiz, fiziksel VAD tasarım ürünüdür.
- Süreç tanımlama formu alanları: No, Ad, Tanım, Girdi, Çıktı, Süreç Tipi, Süreç Mantığı, Çözülmeyen Sorunlar.
- Süreç mantığı: pseudocode, karar tablosu, karar ağacı.
- $n$ adet evet/hayır koşulu $2^n$ kombinasyon verir; birbirini dışlayan koşullar tek satıra indirilerek tablo sadeleştirilir.
- Veri sözlüğü girişleri: veri akışı, veri deposu, veri yapısı, veri elemanı, işlem.
- SRS standardı: IEEE 830.

## Detaylı Açıklamalar

- Tekerlek modeli
  - Hoca gereksinim analizi modelini yuvarlanan bir tekerleğe benzetti. Süreç spesifikasyonu, belirli bir zamanda belirli eylemlerle yürütülen iş akışlarını tanımlar. Veri nesne tanımı, bu işlerde kullanılan, hakkında kayıt tutulması gereken kavramları ve aralarındaki ilişkileri tanımlar. Kontrol spesifikasyonu, bir uyaran geldiğinde sistemin hangi duruma geçeceğini tanımlar; hoca bunu bekleme durumundayken veri gelince çalışma durumuna geçen bir yazıcıyla örnekledi. Üçü birlikte tanımlanınca tam bir analiz modeli ortaya çıkar; tüm tanımlar merkezdeki veri sözlüğünde tutulur.
- Veri akış diyagramını okumak
  - Öğrenci örneğinde öğrenci varlığı, yeni öğrenci kaydı sürecinin çalışması için kimlik bilgilerini sağlar. Akışlar tekil veri (bir barkod numarası) olabileceği gibi transkript, rapor ya da tablo gibi kompozit yapılar da olabilir. Süreçten çıkan ok bir çıktıdır: bir veri deposuna (öğrenci tablosu) kaydedilebilir, başka bir sürece (danışman ataması) girdi olarak verilebilir ya da bir dış varlığa (YÖK) gönderilebilir. YÖK'e gönderim tasarımda belki bir REST API çağrısına dönüşür, ama analiz safhasında ne API ne JSON vardır; yalnız problem modellenir.
  - Veri deposu her şey olabilir: veri tabanı tablosu, JSON dosyası, bulut depolama, kâğıt form, basılı karne, hatta karekod.
  - Süreçler hiyerarşik numaralanır. Örneğin yeni öğrenci kaydı (1.0) içinde MERNİS sorgulaması, ÖSYM'den yerleşme bilgisinin sorgulanması ve öğrenci dosyası açılması gibi alt süreçler 1.1, 1.2, 1.3 olarak numaralanır.
- Klinik faturalama sistemi örneği (ekrandan, 00:45:00; 00:55:00; 01:00:00)
  - Bağlam diyagramında tek süreç FATURALAMA SİSTEMİ'dir. Doktor → Muayene Kaydı; Hasta → Sigorta Formu; sistem → Hasta Faturası (Hasta'ya) ve Sigorta Faturası (Sigorta'ya).
  - Hoca senaryoyu iş analizinde gözlem yöntemiyle anlattı: iki diş hekimli bir klinik özel sigortalarla anlaşmalıdır; faturayı hazırlayan çalışan doktordan muayene kaydını, hastadan sigorta bilgisini alır, sigortayla payları konuşur, hasta payı faturasını (örneğin dolgu için 50 lira) ve sigorta payı faturasını (150 lira) üretir. Müşteri modele SGK'yı eklemek isterse bağlam diyagramına SGK dış varlığı ve "SGK gün dökümleri" akışı eklenir; diyagram hâlâ taslak düzeydedir.
  - 1. düzey VAD'da dört süreç vardır: 1.0 Muayene Kaydı İnceleme ve Ücret Hesabı, 2.0 Fatura Hazırlama, 3.0 Hasta Ödemeleri İşleme, 4.0 Sigorta Ödemeleri İşleme. Depolar: D1 Ücret Listeleri, D2 Hastalar, D3 Sigorta Şirketleri, D4 Muhasebe Kayıtları. Hoca süreç adındaki "ve" bağlacının iyi bir şey olmadığını belirtti.
  - Birkaç akış giren ve çıkan bir süreç karmaşıktır, alt işlemlere bölünmelidir. 2.0 Fatura Hazırlama'nın 2. düzeyinde 2.1 Hastanın Sigorta Durumunun İncelenmesi, 2.2 Listelenen Miktarla Faturayı Kıyaslama, 2.3 Hastanın Ödemesi Gereken Tutarın Faturalanması bulunur.
- Eczane örneği: mantıksal ve fiziksel VAD (ekrandan, 01:25:00)
  - Mantıksal VAD: Hasta → (Alınacak İlaçlar) → 1 İlacı Bul → (İlaç No) → 2 Fiyatı Ara (D1 Fiyatlar'dan Fiyatlar) → (İlaçlar ve Fiyatlar) → 3 Reçete Toplamı Hesapla → (Ödenecek Miktar) → 4 Ödeme Al ve Fatura Ver; Hasta ile 4 arasında Ödeme ve Fatura akışları.
  - Hoca iki hata gösterdi: "İlaçlar ve Fiyatlar" yerine "İlaç Fiyatları" daha iyi bir ad olurdu; Fatura oku ters çizilmiştir, fatura hastaya gitmelidir.
  - Fiziksel VAD ilaç barkodu tarama, fiyat tablosu sorgusu, alt toplamlar için geçici dosya, nakit ödeme gibi gerçekleştirme ayrıntılarını ekler. <!-- BELİRSİZ: fiziksel VAD slaytı karede yok; ayrıntılar yalnız anlatımdan. -->
- Süreç tanımlama formu örneği (ekrandan, 01:30:00)
  - No 4, Ad "Ödemeyi Al ve Fatura Ver", Tanım: reçetedeki ilaçların toplam maliyetine bağlı olarak hasta ödemesi nakit ya da kart ile tahsil edilecek ve fatura verilecek. Girdi: Süreç 3'ten hesaplanarak gelecek "ne kadar ödeme yapılacağı" bilgisi ve hastadan yapılacak tahsilat. Çıktı: Fatura. Süreç Tipi: El ile.
  - Süreç mantığı:

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

  - Çözülmeyen sorunlar: nakit dışında ödeme biçiminin kabul edilip edilmeyeceği belli değil; reçete kayıp ya da unutulmuşsa nasıl işlem yapılacağı belli değil.
  - Form use case'leri andırır, ama use case daha kavramsal kalır; form gerçekleştirmeye daha yakındır.
- Stok kontrolü pseudocode örneği
  - Stok kritik stoktan fazlaysa bir şey yapılmaz; kritik stoğa eşitse çalışana bildirim gösterilir; daha da düştüyse otomatik sipariş üretilir; sıfırlandıysa muadil ilaçlar gösterilir; ilacın üretimi durduysa reçeteye yazılması engellenir. <!-- BELİRSİZ: bu slayt karede yok; koşulların tam metni ekrandan doğrulanamadı. -->
- Karar tablosu: burs örneği (ekrandan, 01:40:00)

  | Durum / İşlem | 1 | 2 | 3 | 4 | 5 |
  |---|---|---|---|---|---|
  | Disiplin cezası almış | E | H | H | H | H |
  | Not ortalaması > 70 | H | E | H | E | H |
  | Giriş puanı > Giriş ortalaması | H | E | E | H | H |
  | Okul süresince tam burs | | X | | | |
  | 1 yıl yarım burs | | | X | | |
  | Okul süresince yarım burs | | | | X | |
  | Burs alamaz | X | | | | X |

  - Üç evet/hayır koşulu $2^3 = 8$ kombinasyon verir. Disiplin cezası alan öğrenci diğer koşullara bakılmadan burs alamaz; bu yüzden 8 kombinasyon 5 kurala iner (kural 1'de diğer iki koşul önemsizdir).
- Karar tablosu: hasta indirimi örneği
  - Koşullar çalışan hasta, emekli hasta, toplam tutar ≤ 50 ve toplam tutar > 50 idi. Çalışan ile emekli birbirini dışlar, iki tutar koşulu da birbirini dışlar; tablo iki koşula ve $2^2 = 4$ kombinasyona indirgenebilir. Eylemler indirim oranı 1-4 ve ek %10 indirimdir; emekli ve tutarı 50'den büyük hastaya hem indirim oranı 4 hem ek %10 uygulanır. <!-- BELİRSİZ: bu tablo karede yok; hangi kombinasyona hangi indirim oranının düştüğü doğrulanamadı. -->
- Karar ağacı
  - Burs tablosunun ağacı: disiplin cezası almışsa burs alamaz; almamışsa not ortalamasına, sonra giriş puanına bakılır. Hasta tipi ağacında kök hasta tipidir (çalışan/emekli), ikinci düzey toplam tutardır (≤ 50 / > 50).
  - Ders sonrası not: hoca ağaçta not ortalaması 70'in üzerindeki dalda "giriş ortalamadan büyükse yarım burs, değilse tam burs" yazdığını ve bunun ters olabileceğini söyledi. Karar tablosuna göre doğrusu: giriş puanı ortalamadan büyükse okul süresince tam burs, değilse okul süresince yarım burs. <!-- BELİRSİZ: karar ağacı slaytı karede yok. -->
- Veri sözlüğü girişleri (ekrandan, 01:45:00; 01:50:00)
  - Veri akış sözlük girişi: adı, tanımı, nereden geldiği, nereye gittiği, içerdiği veri yapıları (örneğin fatura ve müşteri detayları).
  - Veri deposu sözlük girişi: adı, tanımı, tuttuğu veri yapıları, hacmi (örneğin günde yaklaşık 100 kayıt), kimin erişip değiştirebileceği.
  - Veri yapısı sözlük girişi: kompozit verinin içindeki elemanlar, C'deki struct alanları gibi; tarih gibi kompozit elemanlar ayrıca tanımlanır.
  - Veri elemanı sözlük girişi: tanım, tip, uzunluk, değer aralığı ve ek ayrıntılar (örneğin müşteri numarasının son hanesinin kontrol kodu olması); sabit değer kümesi varsa tablo verilebilir.
  - İşlem sözlük girişi (ekrandan): İşlem Adı "2.0 Sipariş Satış Verisini Gir", Girdi "Satış siparişleri", İşlem Tanımı "... yap, eğer değilse ....... yap vb.", Çıktı "Girilmiş satış siparişleri". Süreç tanımlama formu buraya konabilir.
  - Bileşik veriler öğelerine göre, basit veriler anlamlarına göre tanımlanır.
- SRS
  - Gerçek bir projenin iş gereksinimleri listesinde gereksinim numarası, tipi (işlevsel / işlevsel olmayan), önem derecesi, durumu ve zorunlu / opsiyonel bilgisi vardı. İşlevsel olmayan örnekler: bir kullanıcı aynı anda birden çok oturum açamaz; birden fazla veri tabanı sağlayıcısı desteklenir; sayfalar output cache ile saklanır. Bunlar işlev değildir ama tasarımı etkiler.
  - IEEE 830 şablonu: 1 Giriş (amaç, kapsam, tanımlar, referanslar), 2 Genel tanım (ürün perspektifi, ürün işlevleri, çalışma ortamı, tasarım ve gerçekleştirme kısıtları, varsayımlar), 3 Dış arayüzler (kullanıcı, donanım, yazılım, iletişim), 4 Sistem özellikleri (işlevsel gereksinimler, süreç formları, use case'ler), 5 İşlevsel olmayan gereksinimler (performans, kalite). Bir revizyon geçmişi tutulur (ekrandan, 01:55:00).
  - Örnek SRS: Personal Investment Management System; use case tablosu, her use case için birincil aktör, ön koşul, ana ve alternatif senaryo, eklerde formüller ve arayüz taslakları.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
