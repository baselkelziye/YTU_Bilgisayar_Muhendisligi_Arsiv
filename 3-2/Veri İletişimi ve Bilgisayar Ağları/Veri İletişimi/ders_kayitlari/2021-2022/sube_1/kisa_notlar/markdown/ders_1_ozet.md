# Ders 1 Çalışma Özeti

## Genel Konular

- Örneksel-sayısal kodlama: PAM ve PCM
  - Örneksel (analog) işaret süreklidir, sonsuz sayıda değerden oluşur. Sayısala çevirmek için belli aralıklarla örnek alınır.
  - PAM (Pulse Amplitude Modulation) işaretten eşit zaman aralıklarında örnek alır. Sonuç, darbe değerlerinden oluşan bir dizidir (ekrandan, 00:15:00).
  - PCM (Pulse Code Modulation) PAM darbelerini niceler (quantize). Slayttaki tanıma göre her darbeye 7 bit ile ifade edilen bir sayı verilir, 8. bit işareti (artı/eksi) gösterir (ekrandan, 00:25:00).
  - Slayttaki örnek dizi: `16 48 50 18 -16 -50 -80 -80 -60 -40 -12 20 45 ...` (ekrandan, 00:25:00).
  - Sayılar ikili düzene çevrilince örneksel işaretin 0 ve 1'lerden oluşan karşılığı elde edilir.
- Örnekleme kuralları
  - Örnekler eşit aralıklarla alınmalıdır. 100 kHz örneklemede iki örnek arası 10 mikrosaniyedir.
  - Örnek sayısı Nyquist teoremine göre seçilir: işaretteki en yüksek frekans bileşeninin en az iki katı kadar örnek alınır.
  - İnsan konuşması yaklaşık 1000-4000 Hz arasındadır. En yüksek bileşen 4 kHz olduğu için saniyede 8000 örnek gerekir.
  - Süreç: PAM ile ölçüm, PCM ile niceleme, ikiliye kodlama, gerekiyorsa sayısal-sayısal kodlama.
- ADC bit genişliği ve SAR
  - ADC'nin bit genişliği (8, 10, 12, 16 bit) ölçülebilecek en küçük ve en büyük değeri belirler.
  - SAR (Successive Approximation) ADC bitleri en anlamlı bitten başlayarak tek tek dener. Bit sayısı arttıkça dönüşüm süresi uzar, örnekleme hızı düşer, maliyet artar.
  - Telefon için 8 bit PCM yeterlidir. Yüksek kalite için 16 ve 24 bitlik PCM sürümleri de vardır.
- Sayısal-örneksel kodlama
  - Örnek: çevirmeli (dial-up) modem. Sayısal veri, telefon şebekesinin 0-4 kHz ses bandında örneksel işaret olarak taşınır (ekrandan, 00:30:00).
  - Günümüzde DSL, aynı bakır hatta DSLAM cihazıyla ses bandının üstünü de kullanır ve çok daha geniş bant sağlar.
  - Taşıyıcı işaretin (carrier signal) üç özelliği değiştirilir: genlik, frekans (sıklık), faz.
  - ASK, FSK, PSK ve genlikle fazın birlikte değiştirildiği QAM.
- Bit hızı ve baud hızı
  - Bit hızı: saniyede gönderilen bit sayısı (bps).
  - Baud hızı: saniyede gönderilen işaret (sembol) sayısı.
  - Bir sembol birden fazla biti taşıyorsa bit hızı baud hızından büyük olur.
- ASK, FSK, PSK ve QAM
  - ASK: frekans ve faz sabit, yalnız genlik değişir. Uygulaması kolaydır ama gürültüye ve zayıflamaya çok duyarlıdır. Slayt örneği: bit hızı 5, baud hızı 5 (ekrandan, 00:40:00).
  - FSK: frekans değişir. Dış parazitlere ASK'dan daha dayanıklıdır, uygulaması biraz daha zordur. Bit hızı 5, baud hızı 5.
  - PSK: işaretin başlangıç fazı değişir. İki fazla (0° ve 180°) her baud 1 bit taşır.
  - 4 fazlı PSK: 00 için 0°, 01 için 90°, 10 için 180°, 11 için 270°. Slayt örneği: bit hızı 10, baud hızı 5 (ekrandan, 00:50:00).
  - QAM: genlik ve faz birlikte değişir. 4 faz ve tek genlik QAM4 olur. 4 faza 2 genlik eklenince 8 birleşim, yani sembol başına 3 bit elde edilir.
  - Yüksek dereceli QAM'de (64, 128) sembol haritasındaki noktalar birbirine çok yakındır. Küçük bir sapma yanlış sembolün algılanmasına yol açar.
- Örneksel-örneksel kodlama
  - Radyo yayını: ses (örneksel), örneksel bir taşıyıcının üzerine bindirilir. AM, FM, PM.
- Sayısal veri iletim teknikleri
  - Bir iletim için tanımlanması gerekenler: konektör tipi, tel sayısı ve her telin görevi, işaretin frekans, genlik ve faz özellikleri (ekrandan, 01:10:00).
  - Paralel iletim: her bit için ayrı tel, bitler tek seferde gönderilir. Avantajı hız, dezavantajı maliyet ve kısa mesafe.
  - Paralel port (DB25): 18 tel kullanılır, 8'i veri, diğerleri kontrol amaçlıdır. En uzun mesafe 25 feet / 7,5 m (Centronics) (ekrandan, 01:15:00).
  - İki PC paralel porttan "interlink" bağlantıyla, bazı pinler çaprazlanarak bağlanabilir (ekrandan, 01:20:00).
  - Seri iletim: daha az tel, daha düşük maliyet, daha uzun mesafe.
- RS-232 (EIA-232)
  - NRZ-L kodlama. Yalnız 3 tel yeter: transmit, receive, ground. Konektör genelde DB9'dur, diğer pinler akış kontrolü (RTS, CTS vb.) içindir.
  - -5 ile -15 V arası 1, +5 ile +15 V arası 0 anlamına gelir. Geniş gerilim aralığı zayıflamaya karşı dayanıklılık sağlar.
- Eş zamansız (asenkron) seri iletim
  - Ortak saat yoktur, iki uç bit süresinde önceden anlaşır.
  - Boş hatta negatif gerilim (1) vardır. Başlama biti 0'dır, bitiş biti 1'dir.
  - 8-N-1: 1 başlama + 8 veri + 1 bitiş biti, eşlik biti yok. İletim LSB'den başlar (ekrandan, 01:30:00).
  - 7-E-1: 7 veri biti, çift (even) eşlik biti, 1 bitiş biti. Bitiş biti 1, 1,5 ya da 2 olabilir.
  - Ek yük: 8 bit veri için 10 bit gönderilir. Veriye göre %25 fazla, toplamın %20'si kontrol bitidir.
  - Veri bloğunun 8 bitle sınırlı olmasının nedeni saat kaymasıdır (clock drift). Kayma ardışık bitlerde birikir.
- Eş zamanlı (senkron) seri iletim
  - Eş zamanlılık üç yolla sağlanır: ayrı bir saat hattı, saatin veriye gömülmesi (Manchester), preamble.
  - Veri çok sayıda byte'lık bloklar halinde gönderilir (ekrandan, 01:35:00).
  - HDLC örneği: 1000 karakter = 8000 bit, kontrol verisi 48 bit, toplam 8048 bit. Ek yük 48/8048 ≈ %0,6 (ekrandan, 01:40:00).
  - Senkron: daha etkin kullanım, daha iyi hata kontrolü, daha yüksek hız. Asenkron: daha basit ve ucuz, ama daha yavaş ve ek yükü yüksek.
- DTE ve DCE
  - DTE (Data Terminal Equipment): veriyi üreten ya da işleyen cihaz (bilgisayar, yazıcı).
  - DCE (Data Circuit-terminating Equipment): veriyi modüle edip ileten cihaz, çoğunlukla modem.
  - Standartlar: RS-232, RS-422, RS-449, ITU V serisi, X serisi.
  - Null modem: iki DTE doğrudan, TD-RD ve RTS-CTS gibi pinler çaprazlanarak bağlanır (ekrandan, 01:45:00).
- İletim ortamı
  - İletim ortamı bir altyapı yatırımıdır. Kablolamanın ömrü uzun, toplam içindeki maliyeti düşüktür (ekrandan, 01:50:00). Yeniden kablolama ise pahalıdır.
  - Yedeklilik için birden fazla kablo, mümkünse farklı güzergâhtan çekilir. Link aggregation ile 4 adet 10 Gbps hat 40 Gbps kapasite ve yedeklilik sağlar.
  - Yönlendirilmiş (guided) ortam: bakır ve fiber kablo. Yönlendirilmemiş (unguided) ortam: RF, kızılötesi, mikrodalga.
- Koaksiyel kablo ve ilk Ethernet
  - TV/uydu için 75 ohm, sayısal veri için 50 ohm. Tek iletkenli olduğu için half-duplex çalışır.
  - Thick Ethernet (RG-8, 10BASE-5): sarı kalın kablo, vampir konektör, 15 iğneli AUI. En fazla 100 bağlantı, azami segment 500 m, iki uçta 50 ohm sonlandırma (ekrandan, 01:55:00).
  - Thin Ethernet (RG-58): BNC ve T konektör. İnce ve kolay döşenen kablo, daha az bağlantı (hocaya göre 30).
- Burgulu (twisted pair) kablolar
  - UTP (100 ohm, CAT sınıfları), FTP/ScTP (alüminyum folyo), STP (150 ohm, bakır örgü) (ekrandan, 02:00:00).
  - Burgulamanın nedeni elektromanyetik gürültünün teller üzerinde eşit (homojen) dağılmasıdır.
  - Tek damarlı tel çok damarlıya göre sinyali daha az zayıflatır.
  - Renk kodları: mavi, turuncu, yeşil, kahverengi ve beyaz çizgili eşleri. RJ45 konektör, 568A ve 568B dizilimleri.
  - Gigabit Ethernet'te dört çiftin hepsi kullanılır. Çapraz girişim türleri: NEXT, FEXT, ELFEXT (ekrandan, 02:05:00).
- Fiber optik kablolar
  - Silika (cam) çekirdek, kılıf (cladding), birincil ve ikincil tampon katmanları.
  - Avantajlar: elektromanyetik gürültüden etkilenmez, çok geniş bant, düşük zayıflama, gizlice dinlenmesi zordur.
  - Single-mode (SMF): ışık neredeyse düz gider, lazerle kullanılır. Multi-mode (MMF): ışık yansıyarak ilerler, LED ile kullanılır (ekrandan, 02:10:00).
  - MMF türleri: step-index (kırılma indisi her yerde aynı, çıkışta yayılma çok) ve graded-index (merkezde indis yüksek, ışınlar birbirine yakın zamanda ulaşır). Graded-index tercih edilir.
  - Alıcıda fotodiyot ışığı elektrik sinyaline çevirir. Kullanılmayan liflere dark fiber denir.
  - Dezavantajlar: kırılgandır, konektördeki toz ve yağ iletimi engeller, lazer göze zararlıdır (ekrandan, 02:15:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Örnekler eşit aralıklarla ve yeterli sayıda alınmalıdır
  - Aralıklar düzensizse yeniden oluşturulan işaret anlam taşımaz. Örnek sayısı azsa işaretin nereden geçtiği bilinemez.
- Nyquist kuralı
  - En yüksek frekans bileşeninin en az iki katı hızda örnekleme gerekir. Konuşma için 8000 örnek/s.
- Modülasyon hassasiyet gerektirir
  - Alıcı da aynı değişikliği algılayıp demodüle etmelidir. ASK'dan FSK'ya, oradan PSK'ya gidildikçe uygulama zorlaşır.
  - Yüksek dereceli QAM her hatta kullanılamaz. Semboller birbirine yakın olduğu için küçük bir sapma tüm bitleri bozabilir.
- Bit hızı ile baud hızı aynı şey değildir
  - ASK, FSK ve 2PSK'da eşittir. 4PSK ve QAM'de bit hızı baud hızının katıdır.
- Pin tabloları ezber için değildir
  - Paralel port ve DTE-DCE pin tabloları genel kültür içindir. Temel sinyaller (TD, RD, RTS, CTS, GND) bilinmelidir.
- Kablolama bir altyapı yatırımıdır
  - Kablo ucuzdur, yeniden kablolama pahalıdır. Yedekli ve farklı güzergâhtan çekim önerilir.
- Fiber güvenliği
  - Lazerli fiberin ucuna doğrudan bakılmamalıdır. Işığın hangi uçtan çıktığı karanlıkta elle kapatarak kontrol edilir.

## Kısa Tekrar Notları

- PAM: eşit aralıklı örnekleme. PCM: niceleme ve ikili kodlama (slaytta 7 bit büyüklük + 1 işaret biti).
- Nyquist: örnekleme hızı ≥ 2 × en yüksek frekans. 4 kHz ses için 8000 örnek/s.
- 100 kHz örnekleme ⇒ örnekler arası 10 µs.
- SAR ADC: bit sayısı arttıkça dönüşüm süresi uzar.
- Sayısal-örneksel: ASK (genlik), FSK (frekans), PSK (faz), QAM (genlik + faz).
- Bit hızı = baud hızı × sembol başına bit. 4PSK, 5 baud ⇒ 10 bps.
- 8 birleşim (4 faz × 2 genlik) ⇒ sembol başına 3 bit.
- ASK gürültüye ve zayıflamaya en duyarlı yöntemdir.
- Örneksel-örneksel: AM, FM, PM (radyo).
- Paralel: hızlı, pahalı, kısa mesafe. DB25'te 18 tel (8 veri).
- RS-232: NRZ-L, 3 tel yeter, -5/-15 V = 1, +5/+15 V = 0.
- Asenkron 8-N-1: 10 bit içinde 8 bit veri, %20 ek yük. LSB önce gider.
- Senkron HDLC: 48/8048 ≈ %0,6 ek yük.
- Senkronizasyon: ayrı saat hattı, Manchester, preamble.
- DTE: veri üreten/işleyen. DCE: modem. Null modem: çapraz bağlantı.
- Koaksiyel: 50 ohm veri, 75 ohm TV. Thick: 500 m, 100 bağlantı, vampir + AUI. Thin: BNC.
- UTP 100 ohm, STP 150 ohm, FTP folyolu. Burgulama gürültüyü eşit dağıtır.
- Fiber: SMF + lazer, MMF + LED. Graded-index tercih edilir. Dark fiber: kullanılmayan lif.

## Detaylı Açıklamalar

- **PAM ve PCM ilişkisi.** Örneksel bir işaret, ölçülebilecek sonsuz değerden oluşur. PAM bu işaretten eşit aralıklarla örnek alır ve her örnekte o anki genliği (gerilim ya da akım) ölçer. Bu ölçümler henüz sayı değildir. Bir ADC ile nicelenmeleri, yani ADC'nin bit genişliğine göre izin verilen aralıkta hangi seviyeye düştüklerinin belirlenmesi gerekir. PCM bu nicelenmiş değerleri sayıya çevirir. Slayttaki örnekte seviyeler -127 ile +127 arasındadır ve her örnek 7 bit büyüklük artı 1 işaret bitiyle gösterilir. Elde edilen dizi tamamen sayısaldır. İkili düzene çevrildikten sonra sayısal bir ortama aktarılacaksa üzerine sayısal-sayısal bir kodlama (örneğin NRZ, Manchester) uygulanır.
- **Neden 8 bit PCM?** İlk PCM telefon hatları için tasarlandı. Amaç kristal netliğinde ses değil, konuşanın anlaşılmasıydı. Bu yüzden 8 bit yeterli görüldü. Daha yüksek kalite isteyen uygulamalar için 16 ve 24 bitlik sürümler vardır.
- **SAR ADC ve bit genişliği.** Bir öğrencinin sorusu üzerine hoca, mikrodenetleyicilerdeki ADC'lerin bit genişliğinin ekonomik bir karar olduğunu anlattı. SAR ADC önce en anlamlı biti 1 yapar ve oluşan gerilimi girişle karşılaştırır. Giriş daha yüksekse bu bit 1 kalır, sonra bir sonraki bite geçilir. Her bit için bir adım gerektiği için bit sayısı arttıkça dönüşüm süresi uzar ve örnekleme hızı düşer. Genel amaçlı mikrodenetleyicilerde bu yüzden 10-12 bit görülür. Ses gibi özel uygulamalara yönelik denetleyicilerde 16 bitlik ADC olabilir. Tek adımda örnek alan ADC türleri de vardır.
- **Sayısal-örneksel kodlama ve modem.** Çevirmeli bağlantıda modem ISP'nin numarasını arar ve sayısal veriyi ses bandında (0-4 kHz) örneksel bir işarete çevirir. Hoca, aynı hattaki başka bir telefonun ahizesi kaldırıldığında veri aktarımının duyulabildiğini, ama aynı anda konuşmanın mümkün olmadığını anlattı. Ahize sert kapatılırsa hattı kesen bir işaret oluşabilirdi. DSL ise aynı bakır hattı kullanır, ancak santral tarafındaki DSLAM sayesinde ses bandının çok üstündeki frekansları da kullanarak daha yüksek bant genişliği sağlar.
- **Bit ve baud.** Baud, saniyede taşıyıcı üzerinde yapılan değişiklik (sembol) sayısıdır. ASK slaytında bir saniyelik aralıkta 5 değişiklik vardır ve her biri 1 bit taşır: 5 baud, 5 bps. 4 fazlı PSK slaytında yine 5 sembol vardır, ama her sembol 2 bit taşıdığı için bit hızı 10 bps olur. QAM'de genlik ve faz birlikte kullanıldığı için sembol başına bit sayısı daha da artar. Slayttaki tabloya göre 4PSK/4QAM'de 2, 8PSK/8QAM'de 3, 16QAM'de 4, 64QAM'de 6, 256QAM'de 8 bit taşınır (ekrandan, 00:55:00).
- **ASK'nın zayıflığı.** Genlik, parazitle ve mesafeye bağlı zayıflamayla değişebilir. 1'i göstermek için gönderilen yüksek genlikli işaret, uzak bir noktada düşük genlikli 0'a benzeyebilir. Bu yüzden ASK uzun mesafede pek tercih edilmez. FSK frekansla oynadığı için genlik bozulmalarından daha az etkilenir. Ancak alıcının frekans değişimini algılaması gerektiğinden uygulaması daha zordur.
- **Asenkron iletimde saat kayması.** Asenkron iletimde iki uç kendi saatlerini kullanır ve başlama bitini gördüklerinde zamanlayıcılarını kurar. Osilatörlerin doğruluğu sınırlıdır (%1, %5 gibi). Bu küçük fark ardışık bitlerde birikir ve uzun bir dizide eninde sonunda yanlış örneklemeye yol açar. Bu yüzden tek seferde gönderilen veri 8 bitle sınırlandırılmıştır ve her byte yeniden bir başlama bitiyle eşlenir.
- **Senkron iletim ve preamble.** Senkron iletimde iki uç aynı saate bağlıdır. Bu, ayrı bir saat hattıyla, Manchester gibi saati veriye gömen kodlamalarla ya da veriden önce gönderilen bir preamble ile sağlanır. Preamble, alıcıya birazdan veri geleceğini bildiren ve alıcının kendini eşlemesini sağlayan bir bit dizisidir. Hoca Wi-Fi'de preamble kullanıldığını söyledi. HDLC örneğinde 1000 karakterlik bloğa 48 bitlik kontrol verisi eklenir. Ek yük binde 6 civarındadır, asenkron iletimdeki %20 ile karşılaştırılınca çok küçüktür.
- **Kablolamada yedeklilik ve link aggregation.** Kazı ve döşeme maliyeti kablo maliyetinden çok yüksektir. Bu yüzden ihtiyaçtan fazla kablo çekilir. Aynı kanaldaki iki kablo aynı kazada birlikte zarar görebileceği için ikinci hattın başka bir güzergâhtan geçmesi önerilir. Hocanın örneğinde 40 Gbps modül çok pahalıysa dört hat çekilip 10 Gbps modüller kullanılır. Hatlar link aggregation ile birleştirilir: kapasite 40 Gbps olur, bir hat koparsa 30 Gbps kalır ve hizmet sürer.
- **Fiberde modlar.** Single-mode fiberde çekirdek çok incedir (slaytta çekirdek 9, dış çap 125) ve ışık neredeyse düz ilerler. Girişteki ve çıkıştaki darbe hemen hemen aynıdır. Multi-mode fiberde (slaytta çekirdek 50 ya da 62,5, dış çap 125) ışık farklı yollardan yansıyarak gider. Step-index türünde kırılma indisi her yerde aynıdır. Uzun yoldan giden ışınlar geç ulaşır ve çıkışta darbe yayılır. Graded-index türünde indis merkezde yüksek, kenarda düşüktür. Kenardan giden ışınlar daha uzun yol alsa da daha hızlı gider ve ışınlar çıkışa yakın zamanlarda ulaşır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
