# Ders 11 Çalışma Özeti

## Genel Konular

- Ders 8 Kasım 2021 Pazartesi günü online yapıldı. Hoca dönemin 6. haftası olduğunu söylüyor. Kayıt yaklaşık 1 saat 29 dakika.
- Yönlendirilmemiş (kablosuz) iletim ortamının (unguided media) devamı:
  - radyo dalgaları (radio waves),
  - mikrodalga (microwave),
  - kızılötesi (infrared),
  - elektromanyetik tayftaki frekans bantlarının adları.
- Çoğullama (multiplexing) ve çoğullamayı çözme (demultiplexing):
  - frekans bölmeli çoğullama (FDM, Frequency Division Multiplexing) ve OFDM,
  - zaman bölmeli çoğullama (TDM, Time Division Multiplexing): eş zamanlı (senkron) ve istatistiksel (asenkron) TDM,
  - dalga boyu bölmeli çoğullama (WDM, Wavelength Division Multiplexing).
- Hata nedenleri ve hata türleri: tek bit hatası, çok bitli hata, hata patlaması (burst error).
- Hata algılama (error detection) yöntemleri:
  - VRC (Vertical Redundancy Check, eşlik biti),
  - LRC (Longitudinal Redundancy Check),
  - CRC (Cyclic Redundancy Check),
  - sağlama toplamı (checksum).
- Hata düzeltme (error correction): gereken artıklık biti sayısı ve Hamming kodu.
- Vize sınavının biçimi ve hoca değişikliği duyurusu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kablosuz ortamın temel kazancı hareketlilik (mobility) ve kablolama maliyetinin olmamasıdır. Kırsal ve uç bölgelere servis vermek için çok tercih edilir.
- Düşük frekanslı radyo dalgaları engellerin içinden geçebilir ve uzağa gider. Bunun bedeli izolasyonun olmamasıdır. Komşuların Wi-Fi ağlarını görmeniz bundandır.
- Frekans arttıkça kapsama alanı daralır, sinyal yönlü hale gelir ve engelden geçmek yerine sekmeye başlar. 5 GHz'e geçmek bu yüzden komşu ağlarla çakışmayı azaltır.
- Aynı kanalda yayın yapan çok sayıda erişim noktası birbiriyle çakışır. Hoca bölümün B blokundaki ilk Wi-Fi kurulumunu örnek veriyor: kanallar ayarlanana kadar hiçbir şey düzgün çalışmamış.
- Bluetooth da 2,4 GHz'te çalışır. İlk sürümler frekans atlamayı (frequency hopping) düzgün yapamadığı için Wi-Fi ile çakışıyordu. Sonraki sürümler dolu kanalı atlayan uyarlamalı atlama kullanır.
- Mikrodalga görüş hattı (line of sight) ister ve atmosfer koşullarından etkilenir. Yüksek güçte canlı sağlığı açısından sorunludur.
- Kızılötesinin ortak bir protokolü yoktur; her üretici kendi protokolünü kullanır. Güneş ışığı da kızılötesi içerdiği için açık havada kumanda neredeyse çalışmaz.
- Çoğullamanın amacı, düşük kapasiteli çok sayıda hattın trafiğini tek ve yüksek kapasiteli bir hatta taşımaktır. Her kullanıcıya omurgaya (backbone) kadar ayrı hat çekmek pahalıdır.
- Çoğullama tek taraflı değildir. Bir uçta çoğullama yapılıyorsa öbür uçta çözülmesi gerekir.
- Eski çevirmeli (dial-up) dönemde "santralde yer yok" cevabı, üst taraftaki T1 hattının kapasitesinin dolu olması demekti.
- FDM'de kanallar arasına koruma bandı (guard band) konur. Radyoda iki istasyon arasındaki cızırtı bu boşluktur.
- Senkron TDM'de her kullanıcının slotu sabittir. Göndereceği bir şey olmasa bile slot ona ayrılır. Bu yüzden verim düşer.
- İstatistiksel TDM'de slotlar ihtiyaca göre doldurulur. Ancak slotun kime ait olduğu belli olmadığı için her slota adres bilgisi eklenmelidir.
- Gerçek hayatta hatalar genellikle tek tek değil, patlama (burst) şeklinde gelir.
- Günümüzdeki temel yaklaşım: gönderici veriden bir kontrol bilgisi üretir ve veriyle birlikte yollar. Alıcı aynı hesabı yapar ve sonuçları karşılaştırır.
- Hata düzeltme mi, yeniden gönderim mi sorusunun cevabı hattın hata karakteristiğine bağlıdır:
  - Hata oranı yüksekse yeniden gönderilen çerçeve de bozuk gelebilir. Bu durumda düzeltme kodu kullanmak gerekir.
  - Hata oranı düşükse düzeltmeyle uğraşmak yerine yeniden gönderim istenir.
- Hamming kodunda kontrol bitleri yalnız veri bitlerini değil, kendilerini de korumalıdır. Bu yüzden hesap $m+1$ ile değil, $m+r+1$ ile yapılır.

## Kısa Tekrar Notları

- **Radyo frekansı:** Yaklaşık 1 GHz'e kadar. Her yöne yayılır (omnidirectional). Düşük frekanslar engelden geçer.
- **Mikrodalga:** Yaklaşık 1–300 GHz. Tek yönlü antenler ve görüş hattı gerekir. Bant genişliği yüksektir.
- **Kızılötesi:** Kısa mesafe, noktadan noktaya. Duvardan geçmez, güneşten etkilenir.
- **ISM bandı:** Lisans gerektirmeyen, herkesin kullanabildiği bant (ör. 2,4 GHz).
- **FDM:** Her kaynağa ayrı taşıyıcı frekans. Kanallar arasında koruma bandı. Örnek: radyo, TV.
- **OFDM:** Alt taşıyıcılar dik (ortogonal) seçilir. Spektrumları üst üste binebilir ama birbirini bozmaz. Daha çok kanal sığar, gerçeklemesi daha zordur.
- **Senkron TDM:** Sabit slot, round-robin. Boş slot da gönderilir.
- **İstatistiksel TDM (STDM):** Slot sayısı giriş sayısından azdır. Slotlar doluysa gönderilir, her slotta adres vardır.
- **WDM:** Fiber optikte farklı dalga boyları (renkler) farklı kanallara verilir.
- **Hata nedenleri:** Zayıflama (attenuation), gecikme bozulması, termal gürültü, modülasyon gürültüsü, çapraz karışma (crosstalk), dış elektromanyetik gürültü.
- **VRC:** Veri bitlerinin XOR'u eşlik biti olur. Tek sayıda hatayı yakalar, çift sayıda hatayı kaçırır.
- **LRC:** Bloklar alt alta yazılır. Her satıra ve her sütuna eşlik biti eklenir.
- **CRC:** Veri, üreteç polinomuna mod-2 (XOR ile) bölünür. Kalan, verinin sonuna eklenir. Alıcıda kalan sıfırsa veri kabul edilir.
- **Checksum:** Veri $m$ bitlik parçalara bölünür ve bire tümleyen (one's complement) aritmetiğiyle toplanır. Toplamın tümleyeni gönderilir.
- **Hamming koşulu:** $2^r \ge m + r + 1$.

## Detaylı Açıklamalar

### Yönlendirilmemiş İletim Ortamı

Kablosuz iletim atmosferi kullanır. Günlük kullanımda daha çok yere yakın yayılan yer dalgaları (ground wave) önemlidir. Yüksek frekanslarda iyonosferdeki değişimler iletimi etkileyebilir.

Elektromanyetik tayf frekansa göre bantlara ayrılır. Hoca bu adlandırmanın tarihsel bir sorunu olduğunu söylüyor. İlk adlar verilirken üst bantlar öngörülmediği için "very high", "ultra high", "super high", "extremely high" gibi giderek abartılı adlar ortaya çıkmış.

En düşük frekanslar (ELF, VLF) iletimin en zor olduğu yerde, su altında kullanılır. Frekans arttıkça atmosferin üst katmanlarına ve uzaya doğru çıkılır.

| Bant | Yaklaşık aralık | Örnek kullanım |
|---|---|---|
| LF | 30–300 kHz | Seyrüsefer |
| MF | 300 kHz–3 MHz | AM radyo |
| HF | 3–30 MHz | Kısa dalga |
| VHF | 30–300 MHz | FM radyo, TV |
| UHF | 300 MHz–3 GHz | TV, cep telefonu, Wi-Fi (2,4 GHz) |
| SHF | 3–30 GHz | Uydu, mikrodalga bağlantı |
| EHF | 30–300 GHz | Radar, deneysel |

Frekans kullanımı ulusal düzenlemelere bağlıdır. Bazı aralıklar askeri kullanıma, bazıları FM'e, bazıları da lisanssız ISM kullanımına ayrılır.

### Çoğullama

Kablo modem örneği: apartmandaki kutu, abonelerin hatlarını toplar ve bir üst noktaya taşır. Oradan da daha üst noktalara ve en sonunda omurgaya gidilir. Dönüşte trafik her seviyede çözülerek hedefe ulaşır.

Telefon sistemlerinde abone hatları 9600 bps ile 64 kbps arasındadır. Santralin trafiği bir üste T1 hatlarıyla aktarılır. T1'in kapasitesi 1,544 Mbps'tir.

**FDM:** Her gönderici için ayrı bir taşıyıcı işaret kullanılır ve gönderilecek sinyal bu taşıyıcıyla modüle edilir. Kanallar karışmasın diye aralarına koruma bandı konur. OFDM'de alt taşıyıcılar ortogonal seçildiği için koruma bandına gerek kalmadan spektrumlar üst üste binebilir.

**Senkron TDM örneği:** A, B, C, D adlı dört kaynak var. Birinci çerçevede dördünün de verisi var. İkincide A, B, C'nin verisi var. Üçüncüde yalnız A ve C'nin verisi var. Dördüncüde yalnız A'nın verisi var. Dört çerçevede toplam 16 slot kullanılıyor ama yalnız 10'u dolu.

$$U = \frac{10}{16} = 0{,}625$$

Aynı veri istatistiksel TDM ile üç çerçevede taşınabilir. Bedeli her slota eklenen adres bilgisidir. Adres küçükse kazanç büyüktür.

**WDM:** Işığın farklı dalga boyları farklı kanallara ayrılır. Fiber optik hatlarda kullanılır.

### Hata Türleri

Örnek veri `1000111` olsun:

- **Tek bit hatası:** Yalnız bir bit değişir. Hocaya göre bu tür hata daha çok bellekte görülür.
- **Çok bitli hata:** Birbirinden bağımsız iki veya daha fazla bit değişir.
- **Hata patlaması:** Art arda gelen bitler birlikte bozulur. Gerçek hatların çoğu bu şekildedir.

Veriyi iki kez gönderip karşılaştırmak hem iki kat zaman harcar hem de veri iki seferde aynı şekilde bozulabilir. Bu yüzden kontrol bilgisi yaklaşımı kullanılır.

### VRC ve LRC

**VRC:** Gönderilen veri `0100110`. Bitlerin XOR'u 1 çıkar (üç tane 1 var). Eşlik biti 1 eklenince birlerin sayısı çift olur. Alıcı tüm bitleri eşlik biti dahil XOR'lar ve 0 bulmalıdır.

- Tek bit bozulursa sonuç 1 çıkar ve hata yakalanır. Hatanın yeri bulunamaz.
- İki bit bozulursa sonuç yine 0 çıkar. Hatalı veri doğru sanılır.

**LRC:** Baytlar alt alta yazılır. Her baytın sonuna kendi eşlik biti eklenir. Ayrıca sütunlar için bir eşlik baytı üretilip en sona konur. Örnekte 4 bayt için 1 bayt kontrol üretilmiş. Pratikte 16, 32 veya 64 baytlık bloklar üzerinde uygulanır.

LRC de her şeyi yakalamaz. İki baytın aynı iki bit pozisyonunda hata olursa hem satır hem sütun eşlikleri değişmez ve hata görünmez.

### CRC

Ethernet (IEEE 802) 32. dereceden bir üreteç polinomu kullanır:

$$G(x) = x^{32}+x^{26}+x^{23}+x^{22}+x^{16}+x^{12}+x^{11}+x^{10}+x^{8}+x^{7}+x^{5}+x^{4}+x^{2}+x+1$$

Adımlar:

1. Üreteç $n$ bitlikse verinin sonuna $n-1$ tane 0 eklenir.
2. Sonuç üretece XOR ile (mod-2) bölünür.
3. Kalan ($n-1$ bit), eklenen sıfırların yerine yazılır.
4. Alıcı gelen veriyi aynı üretece böler. Kalan 0 ise veri doğrudur.

**Örnek:** Üreteç $x^3+x^2+1$, yani `1101`. Veri `100100`. Sona üç tane 0 eklenir ve `100100000` bölünür. Kalan `001` çıkar. Gönderilen çerçeve `100100001` olur. Bu sonuç Python ile doğrulandı.

Hoca, CRC-32'nin yakalayamadığı hata oranının "neredeyse sıfır" olduğunu ama sıfır olmadığını vurguluyor.

### Checksum

1. Veri $m$ bitlik parçalara bölünür (ör. 16 bit).
2. Parçalar bire tümleyen aritmetiğiyle toplanır. Taşan bit başa eklenir.
3. Toplamın tümleyeni sağlama alanına yazılır.
4. Alıcı tüm parçaları sağlama alanıyla birlikte toplar. Sonucun tümleyeni 0 ise hata yoktur.

Checksum daha çok veri bağlantı katmanında değil, taşıma (transport) katmanında ve daha büyük parçalar üzerinde kullanılır.

### Hata Düzeltme ve Hamming Kodu

$m$ bitlik bir veride hata herhangi bir bitte olabilir veya hiç olmayabilir. Kontrol bitlerinin de bozulabileceği hesaba katılınca $m+r+1$ durum ayırt edilmelidir:

$$2^r \ge m + r + 1$$

**Örnek:** $m = 7$ için $r = 3$ yetmez ($8 < 11$). $r = 4$ yeterlidir ($16 \ge 12$). Toplam kod sözcüğü 11 bittir.

Kontrol bitleri 2'nin kuvveti olan pozisyonlara (1, 2, 4, 8) konur. Veri bitleri kalan pozisyonlara yerleşir. Her kontrol biti belirli pozisyonların eşliğini tutar:

- $r_1$: 1, 3, 5, 7, 9, 11
- $r_2$: 2, 3, 6, 7, 10, 11
- $r_4$: 4, 5, 6, 7
- $r_8$: 8, 9, 10, 11

Alıcı aynı XOR hesaplarını tekrar yapar. Hepsi 0 çıkarsa hata yoktur. Sıfırdan farklı çıkan sonuçlar hatalı bitin pozisyonunu verir.

Bu yapı tek bit hatasını düzeltir. Tüm çok bitli hata kombinasyonlarını düzeltmek için gereken kontrol biti sayısı çok büyür. Bu yüzden pratikte bir veya en fazla iki hata için tasarım yapılır. Daha güçlü kodlar (Reed–Solomon, LDPC vb.) var ama matematikleri bu dersin kapsamı dışında.

### Duyurular

- Dersin sonunda hoca bu haftanın 6. hafta olduğunu ve 8. haftanın vize haftası olduğunu söyledi. Önümüzdeki hafta bir konu anlatımı daha olacak, ardından vize yapılacak.
- Vizeden sonra grup başka bir hocaya devredilecek. Hoca öğrencileri "bir anda Cihan Hoca çok değişmiş" diye şaşırmamaları için önceden uyardı.
- Vize "çoktan çok seçmeli" olacak:
  - Bir soruda birden fazla doğru şık olabilir.
  - Yalnız doğru şıkları işaretlerseniz soru doğru sayılır.
  - Bir tane bile yanlış şık işaretlerseniz soru yanlış sayılır.
  - Yanlışlar doğruları götürür. Dört şıklı sistemde üç yanlış bir doğruyu götürür.

### Ders sonrası notlar

- **ISM bandı:** Hoca Türkiye'de ISM bandının 2,4 GHz, ABD'de 5 GHz olduğunu söylüyor. Bu doğru değil. 2,4 GHz ISM bandı dünyanın hemen her yerinde lisanssızdır. 5 GHz Wi-Fi bantları (U-NII) Türkiye'de de belirli güç ve kanal kısıtlarıyla kullanılabilir.
- **TDM verimi:** Hoca örnekteki verimi "neredeyse %50, hadi %60" diye söylüyor. Doğru değer $10/16 = \%62{,}5$'tir.
- **T1 hızı:** Hocanın "1,5 Mb" dediği T1 hattı tam olarak 1,544 Mbps'tir.
- **İstatistiksel TDM slayt hatası:** Hoca slayttaki çerçeve indekslerinin kaydığını derste düzeltti. Doğru sıra: önce A1, B1, C1, D1; sonra A2, B2, C2, A3; en son C3, A4.
- **Hamming hesabı:** Hoca önce $\log_2(m+1)$ ile 3 bit buluyor, sonra kontrol bitlerinin de bozulabileceğini ekleyip 4'e çıkıyor. Doğru koşul baştan $2^r \ge m+r+1$'dir.
- **Gecikme bozulması:** Hoca Fourier bileşenlerinin (3., 5., 7. harmonik) gecikmeye yol açtığını söylüyor. Kastedilen, farklı frekans bileşenlerinin ortamda farklı hızlarda ilerlemesinden doğan gecikme bozulmasıdır (delay distortion).
- **CRC-32'nin Hamming mesafesi:** Hocanın adını hatırlayamadığı çalışma, Philip Koopman'ın 2002 tarihli "32-Bit Cyclic Redundancy Codes for Internet Applications" makalesidir. Makale, IEEE 802.3 CRC-32'nin birçok çerçeve boyunda Hamming mesafesinin 4 olduğunu, daha iyi polinomlarla 6'ya çıkılabileceğini gösterir.
- **Bozuk altyazı:** Ders sonunda hocanın saydığı ileri hata düzeltme kodlarından biri altyazıda "binary formal regional codes" diye bozuk çıkmış. Kodun adı kayıttan anlaşılamıyor; büyük olasılıkla BCH veya konvolüsyonel kodlar kastediliyor.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
