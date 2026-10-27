# Ders 10 Çalışma Özeti

## Genel Konular

- Dersin tarihi 1 Kasım 2021 Pazartesi. Ders online yapıldı.
  - Asıl anlatım yaklaşık 00:10:24'te başlıyor. Öncesi katılım beklemesi.
  - Hoca iki kez kısa süre ayrıldı: 00:19:59-00:20:48 ve 01:03:17-01:04:16.
  - Ara verilmeden yaklaşık 02:05'e kadar devam edildi.
- Bu hafta grup diğer gruplardan önde olduğu için hoca hızlı gitmeyeceğini, yönlendirilmiş ortamlarla (guided media) duracağını söyledi.
- Sayısal veri iletim teknikleri
  - Paralel iletim, paralel port (DB25, Centronics).
  - Seri iletim, RS-232 ve RS-422.
  - Eş zamansız (asynchronous) iletim: başlangıç/bitiş bitleri, eşlik biti (parity), 8N1 gösterimi.
  - Eş zamanlı (synchronous) iletim: saat bilgisinin taşınması, önsöz (preamble).
  - DTE ve DCE kavramları, sıfır modem (null modem) bağlantısı.
- İletim ortamı (transmission medium)
  - Altyapı yatırımı olarak kablolama ve yedeklilik.
  - Yönlendirilmiş (guided) ve yönlendirilmemiş (unguided) ortam.
  - Eş eksenli (coaxial) kablo: Kalın (Thick) ve İnce (Thin) Ethernet.
  - Burgulu çift (twisted pair) kablolar: UTP, STP, FTP, renk kodları, RJ45, T568A ve T568B, kategoriler, çapraz girişim türleri.
  - Fiber optik kablo: yapısı, tek modlu ve çok modlu fiber, ışık kaynakları, bakırla karşılaştırma.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Fiziksel katmanda henüz çerçeve (frame) veya paket yok:** Bir öğrenci verinin hatlara paket olarak mı bölündüğünü sordu. Hoca burada sadece bitlerin ortam üzerinden nasıl aktarıldığından söz edildiğini söyledi. Çerçeveleme veri bağı katmanının işidir.
- **Paralel iletim:**
  - Avantajı hızdır.
  - Dezavantajları maliyet (çok tel) ve mesafe kısıtıdır.
- **Pin tablolarına takılmayın:** Konnektörlerin bacak bağlantıları genel kültür. Önemli olan teori ve çalışma mantığı.
- **Eş zamansız iletimin temel sorunu saatlerin bağımsız olmasıdır:**
  - Hoca bunu "yarın 17.34'te buluşalım" örneğiyle anlattı. Herkesin saati ayrı bir kaynağa bağlı olduğundan biri 17.30'da, biri 17.40'ta gelir.
  - Hız arttıkça bit süresi kısalır. Kaymaların etkisi büyür.
- **Eş zamanlı ve eş zamansız iletimin karşılaştırması:**
  - Eş zamanlı iletim: daha etkin kullanım, daha iyi hata denetimi, daha yüksek hız.
  - Eş zamansız iletim: basit, ucuz, ek zamanlama çabası gerektirmez. Ama hata denetimi sınırlıdır ve başlangıç/bitiş bitleri yüzünden bant genişliği kaybı yüksektir.
- **Sınav uyarısı:** Karşılaştırma sorularında "biri şöyle, diğeri böyle" diye yazmayın. Hangi özelliğin hangi yönteme ait olduğunu açıkça yazın.
- **Kablolama en ucuz kalemdir, ama bir altyapı yatırımıdır:**
  - Kazı, döşeme ve kapatma işi pahalıdır.
  - Bu yüzden ilk seferde yedekli kablo çekmek mantıklıdır.
  - Yedek kablo farklı bir güzergâhtan geçmelidir.
- **Burgulu kablonun amacı:** Dış gürültünün iki tele benzer şekilde etki etmesini, yani gürültünün düzgün dağılmasını (uniform) sağlamak.
- **Fiber elektromanyetik gürültüden etkilenmez:** Hoca öğrencinin "sinyal" cevabını düzeltti. Doğru cevap elektromanyetik gürültü. Fiberden elektrik değil, ışık aktarılır.
- **Lazer güvenliği:** Lazer kullanan fiber konnektöre gözle bakmayın. Lazer ışını göze zararlıdır. Ortamı karartın ve kabloyu yere doğru tutarak ışığa bakın.

## Kısa Tekrar Notları

- Paralel iletim:
  - Bir grup bit (ör. 8 bit) aynı anda ayrı tellerden gönderilir.
  - Eski PC'lerde paralel port vardı. Bugün yerini USB (Universal Serial Bus) aldı.
  - ECP ve EPP paralel portlar o dönemin seri portlarına göre çok hızlıydı.
- Paralel port:
  - PC tarafında DB25 konnektör vardır: 8 veri hattı ve kontrol/durum hatları (Error, Paper Out, Busy, Acknowledge, Select vb.).
  - Yazıcı tarafında Centronics konnektör vardır.
  - Kablo uzunluğu slayta göre 7,5 m ile sınırlı.
- Seri iletim: bitler tek hat üzerinden peş peşe gönderilir.
- RS-232 (EIA-232):
  - NRZ-L kodlama kullanılır.
  - 1 (mark) negatif gerilimle, 0 (space) pozitif gerilimle ifade edilir.
  - Boşta hatta sürekli 1, yani negatif gerilim vardır.
- RS-422: çok daha uzun mesafeye gider.
- Eş zamansız çerçeve:
  - 1 başlangıç biti (start bit, 0).
  - 8 veri biti.
  - İsteğe bağlı eşlik biti.
  - 1, 1,5 veya 2 bitlik bitiş biti (stop bit).
- Eşlik biti:
  - Çift eşlikte (even parity) toplam 1 sayısı çift olur. Veride üç tane 1 varsa eşlik biti 1 olur.
  - Tek eşlikte (odd parity) toplam 1 sayısı tek olur. Veride üç tane 1 varsa eşlik biti 0 olur.
- 8N1 gösterimi:
  - 8: veri biti sayısı.
  - N: eşlik yok (E: çift, O: tek).
  - 1: bitiş biti sayısı.
- Eş zamansız ek yük (8N1):
  - Toplam 10 bitin 2'si denetim bitidir: $\frac{2}{10} = \%20$.
  - Veriye göre bakılırsa $\frac{2}{8} = \%25$.
- Eş zamanlı iletim:
  - Büyük bloklar halinde gönderilir. Bloklar arası boşluklar düzenlidir.
  - Saat bilgisi ayrı bir hattan gönderilir veya veriye gömülür (Manchester, diferansiyel Manchester).
- DTE (Data Terminal Equipment): veriyi üreten veya işleyen cihazdır. Örnekler: bilgisayar, yazıcı.
- DCE (Data Circuit-terminating Equipment): modülasyon ve demodülasyonu yapar. Örnek: modem.
- DTE-DCE standartları:
  - EIA: RS-232, RS-422, RS-449.
  - ITU: V.24, V.32, V.34, X serisi.
- Eş eksenli kablo empedansı:
  - 75 Ω: TV ve uydu alıcısı.
  - 50 Ω: sayısal haberleşme (Ethernet).
- Kalın Ethernet (Thick Ethernet):
  - Kablo RG-8, standart adı 10BASE5. Sarı renkli.
  - Bağlantı vampir uç (vampire tap) ile yapılır.
  - Arayüz 15 pinli AUI (Attachment Unit Interface).
  - Segment başına en fazla 100 cihaz ve 500 m.
  - Hattın iki ucunda 50 Ω sonlandırma direnci vardır.
- İnce Ethernet (Thin Ethernet):
  - Kablo RG-58 (10BASE2).
  - BNC konnektör ve T konnektör kullanılır.
  - Topoloji yine yoldur (bus).
- Burgulu çift kablo türleri:
  - UTP (Unshielded Twisted Pair): kılıfsız.
  - STP (Shielded Twisted Pair): kılıflı.
  - FTP/ScTP (Foiled/Screened Twisted Pair): alüminyum folyolu.
  - Ofislerde en çok UTP kullanılır. Hiçbir şeye karşı tam korumalı değildir.
- Renk kodları:
  - 4 çift: mavi, turuncu, yeşil, kahverengi.
  - Her rengin bir de beyazlı ("pijamalı") eşi vardır.
- Konnektörler:
  - Ethernet'te RJ45 (8 pin).
  - Telefonda RJ11.
- Kablo dizilimi: T568A ve T568B standartları. Turuncu, mavi ve yeşilin hangi pine gideceğini belirler.
- Kategori kablolar:
  - CAT1, CAT2, CAT3: ses ve veri (telefon, token ring).
  - Bugün CAT5, CAT5e ve CAT6 kullanılıyor.
  - CAT7'den itibaren konnektör değişiyor.
  - Kategori sadece frekansı değil, en büyük uzunluk gibi başka özellikleri de belirtir.
- Çapraz girişim türleri:
  - NEXT: yakın uçta çapraz girişim.
  - FEXT/ELFEXT: uzak uçta çapraz girişim.
  - PSNEXT: güç toplamlı çapraz girişim.
  - Bunlara ek olarak zayıflama.
- Fiber kablo yapısı (içten dışa):
  - Çekirdek (core).
  - Kılıf (cladding).
  - Birincil tampon (primary buffer), ikincil tampon.
  - Dış ortam kablosunda metal zırh (armor) ve dış plastik kaplama.
- Karanlık fiber (dark fiber): döşenmiş ama kullanılmayan fiber. İçinden ışık geçmediği için bu adı alır.
- Fiber türleri:
  - Tek modlu (single-mode): ışık düz bir yol izler. Giriş darbesi çıkışta düzgün görünür. Daha pahalıdır.
  - Çok modlu (multimode): ışık farklı yollardan kırılarak gider ve darbe bozulur. İki türü vardır: basamaklı kırılma indisli (step-index) ve dereceli kırılma indisli (graded-index).
- Işık kaynakları:
  - LED: ucuz çözüm, çok modlu fiber için.
  - Lazer diyot (injection laser diode, ILD): tek modlu fiber için.
- Alıcı: fotodiyot. Üzerine ışık düşünce elektrik işareti üretir.

## Detaylı Açıklamalar

### Paralel Port ile PC'den PC'ye Bağlantı

- Paralel port yazıcı için tasarlanmıştı. Haberleşme asimetriktir: veri PC'den yazıcıya gider, yazıcıdan çok az bilgi döner.
- PC hızlı, yazıcı yavaştır. Bu yüzden yazıcının meşgul olduğunu veya hata durumunu (kâğıt bitti vb.) bildirecek kontrol işaretleri vardır.
- Zamanında iki PC paralel portla da bağlanıyordu:
  - İşletim sistemi bunu doğrudan desteklemiyordu. Çapraz bağlı kablo ve üçüncü parti bir program gerekiyordu.
  - Kabloda veri pinleri karşı tarafın durum pinlerine bağlanır. Örneğin bir tarafın 2 numaralı pini diğer tarafın 15 numaralı pinine gider.
  - Veri biti 0 ve 1 karşıda Error ve Select'e, veri biti 2 Paper Out'a, 3 Acknowledge'a, 4 Busy'ye bağlanır. Diğer yönde de aynısı yapılır.
  - Bu bir tür sıfır modem bağlantısıdır.

### RS-232'de Neden Yüksek Gerilim

- RS-232'de gerilim aralıkları geniştir. Hocanın anlatımına göre 1 için $-15$ ile $-5$ V, 0 için $+5$ ile $+15$ V.
- Sebebi şu: Mesafe uzadıkça telin direnci işareti zayıflatır. Geniş aralık, zayıflamış işaretin de doğru okunmasını sağlar.

### Eş Zamansız İletim ve Saat Kayması

- İki taraf her bitin hatta ne kadar kalacağı konusunda önceden anlaşır. Örneğin 10 ms.
- Gönderici verisi olduğunda hatta basar. Ortak bir saat işareti beklenmez.
- Örnek: 10 Hz'de saniyede 10 değişiklik yapılır. Her işaret 100 ms sürer.
- İki tarafın saat kaynağı farklıdır:
  - Bir tasarımcı %1 hatalı iyi bir osilatör kullanır.
  - Diğeri ucuz bir RC devresi kurar ve hata %10 olur.
  - Biri 100 geçiş yaparken diğeri 90 veya 110 yapar.
- Telefonlar saati GSM operatöründen günceller, ama bu belli periyotlarla yapılır. Saniyeler düzeyinde fark yine olabilir.
- Verinin başladığını anlamak için hattaki sürekli 1'den farklı bir şey gerekir. Bu da 0 olan başlangıç bitidir.
- Kayma birikerek büyür:
  - %5'lik bir kayma 1. bitte %5, 2. bitte %10 olur.
  - Başlangıç biti de sayılırsa son bitte %45'e yaklaşır.
  - Son bitin yanlış okunma ihtimali yüksektir.
- Ek yükü azaltmak için 8 yerine 16, 32, 64 bitlik bloklar gönderilebilir. Ama blok uzadıkça saat farkı yüzünden hata ihtimali artar.
- Hoca eş zamansız iletimin bugünkü bir kullanımını anlattı:
  - Bazı merkezi sistemler (mainframe) ve disk birimleri hata bildirimi için ayrı dial-up modem kullanıyordu.
  - Veri merkezinde normal bağlantı koptuğunda hata, bu ayrı hat üzerinden bildirilebiliyordu. Bu bir tür yedekleme (failover) sağlıyordu.
  - Bugün bunun yerine 3G/4G kullanmak daha mantıklı.

### Eş Zamanlı İletimde Saat Bilgisi

- **Yol 1:** Ortak bir saat işareti. Taraflardan biri saat darbesi üretir.
  - Bir öğrenci "aynı clock cycle'a bağlamak" diye önerdi. Hoca bunu en temiz yollardan biri olarak kabul etti.
  - Sorun: Uzun mesafede saat işareti DC bileşen oluşturur ve zayıflama yüzünden bozulur.
- **Yol 2:** Saati veriye gömmek.
  - Manchester ve diferansiyel Manchester kodlamada her bitte geçiş olduğu için saat bilgisi veriyle birlikte gider.
  - Hoca bunu "verinizi saatle kiplemek" diye özetliyor.
- **Yol 3:** Kablosuz ortamlarda (Wi-Fi, ZigBee, RF) mantıksal düzeyde eş zamanlama.
  - Ortamda sürekli bir saat darbesi yoktur, sadece taşıyıcı işaret vardır.
  - Her çerçevenin önüne bilinen bir desen (preamble) konur.
  - Alıcı bu deseni yakalayınca bir çerçevenin başladığını anlar.
- Slaytta denetim bilgisinin "100 biti geçmez" diye yazdığını belirtti. Hoca bunu yanlış buluyor ve böyle bir sayının ezberlenmemesini istiyor.

### Eş Zamanlı İletimde Ek Yük Örneği (HDLC)

- 1000 karakterlik bir veri bloğu: $1000\times 8 = 8000$ bit.
- Denetim bilgisi 48 bit. Toplam 8048 bit.
- Ek yük: $\frac{48}{8048} \approx \%0{,}6$.
- Eş zamansız iletimdeki %20 ile karşılaştırıldığında çok küçüktür.

### DTE, DCE ve Sıfır Modem

- Tipik yapıda iki uçta DTE'ler, onlara bağlı DCE'ler (modemler) ve arada bir ağ vardır.
- Bilgisayar ile yazıcı arasındaki bağlantıda ikisi de DTE'dir.
- Aynı odadaki iki bilgisayarı bağlamak için modemler kaldırılır. DTE'ler sıfır modem kablosuyla doğrudan bağlanır.
- Bugün modemler bilgisayara Wi-Fi veya Ethernet ile bağlanıyor. Öbür tarafta fiber, kablo veya ADSL modülasyonu yapıyor.
- RS-232 için DB25 veya DB9 konnektör kullanılır. DB25'teki pinlerin çoğu tanımlanmış ama hiç kullanılmamıştır. Standart bir modem için 9 pin yeterlidir.

### Kablolamada Yedeklilik: Kampüs Örneği

- Davutpaşa kampüsüne yaklaşık 47 km fiber döşendi. Omurgadan 17 farklı noktaya gidiliyordu.
- Tek hat çekmenin riski: Başkaları kazı yaparken kabloyu kesebilir. Hoca bunların yaşanmış olaylar olduğunu söylüyor:
  - Sulama borusu döşenirken veri hattı parçalandı.
  - Caminin elektriği bağlanırken veri hattı parçalandı.
- Aynı kanala iki kablo koymak yetmez, çünkü ikisi birden kesilir.
- Doğru senaryo:
  - A'dan B'ye en kısa yoldan iki kablo çekilir.
  - Ayrı bir güzergâhtan iki kablo daha çekilir.
  - Toplam 4 bağlantı olur.
- Uçlarda yeterli arayüz varsa 4 bağlantı birlikte kullanılabilir (link aggregation).
  - 4 × 10 Gbps = 40 Gbps.
  - Bir bağlantı koparsa 30 Gbps'e düşülür ve çalışma devam eder.
  - İlk ihtiyaç 10 Gbps ise performans kaybı hissedilmez bile.

### Burgulu Kablo Ayrıntıları

- Burgu sayısı, çiftlerin seçimi ve çiftler arası yalıtım farklı kablo adlarını belirler.
- Tellerin iç yapısı:
  - Tek parça kalın tel (solid) olabilir.
  - Birden çok ince telden örülmüş (stranded) olabilir.
- Çok telli kablo daha esnektir ve darbelere dayanıklıdır. Ama hocaya göre deri etkisi (skin effect) yüzünden işaret daha çok zayıflar.
- Fast Ethernet'e geçişte (1990'ların ortası) yeni bir fiziksel katman tasarlamak yerine mevcut yapıyı hızlandırmak ve geriye uyumluluğu korumak tercih edildi. Hem CAT3 hem CAT5 seçeneği sunuldu.
- Shield'ın amacı kablonun dayanımını artırmak ve elektromanyetik gürültüyü azaltmaktır.
- Folyonun ve shield'ın yeri değişebilir: çiftlerin içinde, dışında veya her ikisinde. Kablo adları bu kombinasyonları anlatır.
- Eskiden bazı ucuz cihazlar T568A veya T568B dizilimli kabloyla çalışmayabiliyordu. Bugün bu sorun kalmadı.

### Graded-Index Fiber Neden Daha İyi

- Step-index fiberde yansıma açıları keskindir.
- Graded-index fiberde kırılma indisi merkezden kenara doğru azalır ve ışık yumuşak bir eğriyle kırılır:
  - Merkezde giden ışın daha yoğun ortamda yavaş ilerler, ama yolu kısadır.
  - Kenarlara saçılan ışın daha az yoğun ortamda hızlı ilerler, ama yolu uzundur.
  - Sonuçta ışınlar uca neredeyse aynı anda varır. Darbe daha az yayılır ve işaret daha güçlü ulaşır.
- Bu yüzden çok modlu fiberde çoğunlukla graded-index kullanılır.

### Bakır ve Fiber Karşılaştırması

- Fiberin avantajları:
  - Zayıflama çok daha azdır.
  - Elektromanyetik girişimden etkilenmez.
  - Farklı ışık dalga boylarıyla çok kanallı iletim yapılabilir. Frekans bandı geniştir.
  - Elektriksel yalıtım sağlar. Yanından yüksek gerilim hattı geçse bile çapraz girişim olmaz.
  - Daha ince ve hafiftir, daha az yer kaplar.
  - Güvenlik: Fiberin uç bağlantısı bir tür kaynakla yapılır. Kabloyu makasla kesip araya konnektör ekleyerek dinlemek mümkün değildir. Kalın Ethernet'te ise vampir uçla veya BNC ile herkes ortama kolayca bağlanabilir.
- Fiberin dezavantajları:
  - Çok hassastır. Üzerine basmak, oturmak veya konnektördeki küçük bir pürüz kabloyu kullanılamaz hâle getirebilir.
  - Konnektörlerin çok iyi hizalanması gerekir. Bir tarafın lazeri karşının fotodiyoduna tam oturmalıdır. Konnektör elde kolayca yapılamaz.
  - Toz, çizik, yağ, kir ve pasa karşı hassastır. Küçük bir toz tanesi bağlantıyı bozabilir veya hata oranını artırabilir.
  - Uç sonlandırması uzmanlık ister. Hoca, santral önündeki araçta kabloları tek tek eklemeye çalışan teknisyen örneğini veriyor.

### Ders sonrası notlar

- **RS-232 hız ve mesafe:** Hoca "155 kbps ve 15 m" dedi. Doğrusu:
  - RS-232 standardı 15 m (50 ft) için yaklaşık 20 kbps tanımlar.
  - Uygulamada yaygın üst hız 115,2 kbps'tir.
  - RS-422 düşük hızlarda yaklaşık 1200 m'ye kadar gidebilir. Hoca 300 m dedi.
- **RS-232 gerilim seviyeleri:** Verici $\pm 5$ ile $\pm 15$ V arası üretir. Alıcı $\pm 3$ ile $\pm 15$ V arasını geçerli sayar. $-3$ ile $+3$ V arası tanımsız bölgedir.
- **Paralel portun hatları:** DB25 konnektörde 17 sinyal hattı (8 veri, 4 kontrol, 5 durum) ve 8 toprak hattı vardır. Hocanın "18 tel" demesi bu sayıya yakın bir yaklaşık değerdir.
- **HDLC'de "preamble":** HDLC çerçevelerinde ayrı bir önsöz yoktur. Çerçeve başı ve sonu bayrak (flag) baytıyla, yani 01111110 ile işaretlenir.
  - Örnekteki 48 bit; bayraklar, adres, kontrol ve FCS alanlarının toplamıdır.
  - Ayrı bir önsöz kullanan protokol örneği Ethernet'tir: 7 baytlık preamble ve 1 baytlık SFD vardır.
- **DCE'nin açılımı:** Doğru açılım *Data Circuit-terminating Equipment*'tır. Bazı kaynaklarda *Data Communications Equipment* olarak da geçer.
- **Kalın Ethernet hızı:** 10BASE5 saniyede 10 megabit (10 Mbps) aktarır. Hoca "10 MHz" dedi. İnce Ethernet'te (10BASE2) segment başına sınır 185 m ve 30 cihazdır.
- **İki bilgisayarı doğrudan bağlamak:** Hoca iki uçta aynı dizilimin kullanılması gerektiğini, böylece iki bilgisayarın konuşabileceğini söyledi.
  - Bilgisayar-switch bağlantısında iki uç aynı dizilimle yapılır. Buna düz kablo (straight-through) denir.
  - İki bilgisayarı doğrudan bağlamak için klasik olarak bir uç T568A, diğer uç T568B yapılır. Buna çapraz kablo (crossover) denir.
  - Günümüz cihazlarının çoğunda Auto-MDIX olduğu için düz kablo da çalışır.
- **Çift kullanımı:** 10BASE-T ve 100BASE-TX dört çiftten yalnızca ikisini kullanır: bir gönderme, bir alma. 1000BASE-T dört çiftin hepsini aynı anda iki yönde kullanır.
- **Kategorilerin frekansları:**
  - CAT5 ve CAT5e: 100 MHz. Hoca CAT5e için 125 MHz dedi. 125 değeri, 1000BASE-T'nin her çiftteki sembol hızıdır (125 Mbaud).
  - CAT6: 250 MHz.
  - CAT6A: 500 MHz.
  - CAT7: 600 MHz.
  - "CAT6E" diye resmi bir kategori yoktur, bu bir pazarlama adıdır.
- **Deri etkisi ve çok telli kablo:** Deri etkisi, yüksek frekansta akımın iletkenin dış yüzeyine yakın akması demektir. Çok telli (stranded) kablonun zayıflamasının daha yüksek olmasının sebebi teller arası boşluklar ve yüzey düzensizlikleridir.
  - Bu yüzden kabinlerdeki kısa ara kablolar (patch cord) çok telli, binadaki uzun yatay kablolar tek telli (solid) yapılır.
- **Burgunun asıl etkisi:** Gürültü iki tele eşit bindiğinde alıcı iki tel arasındaki farkı ölçer (differential signaling). Böylece ortak gürültü birbirini götürür.
- **Fiber güvenliği:** Fiber bakıra göre dinlemeye çok daha dayanıklıdır, ama dinlemek imkânsız değildir. Kabloyu bükerek dışarı sızan ışıkla dinleme (bend tapping) yöntemleri vardır. Hassas veride şifreleme yine gerekir.
- **Çok kanallı iletim:** Fiberde farklı dalga boylarını aynı anda kullanmanın adı dalga boyu bölmeli çoğullamadır (wavelength-division multiplexing, WDM).
- **Altyazı hataları:**
  - "Gayret" guided, "Doğutbaşa" Davutpaşa demektir.
  - "Ares 232" ve "Arası 232" RS-232, "Nando'dan" ve "non-modem" null modem demektir.
  - "Data Circle Terminated Equipment" Data Circuit-terminating Equipment, "Zipbi" ZigBee demektir.
  - "OnBase 5" 10BASE5, "Tick/Tin Ethernet" Thick/Thin Ethernet demektir.
  - "UDP Unshielded Twisted Payer" UTP (Unshielded Twisted Pair), "RC45" RJ45 demektir.
  - "Elf X" ELFEXT, "Führer kablo" fiber kablo, "ÖLD" ILD (injection laser diode) demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
