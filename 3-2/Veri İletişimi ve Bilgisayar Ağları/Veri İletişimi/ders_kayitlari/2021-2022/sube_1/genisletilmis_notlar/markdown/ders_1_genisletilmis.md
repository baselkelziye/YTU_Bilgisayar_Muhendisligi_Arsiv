# Ders 1 Genişletilmiş Notu: Kodlama Teknikleri, Seri ve Paralel İletim, İletim Ortamları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Örneksel-Sayısal Kodlama: PAM ve PCM
- 3. Örnekleme Kuralları ve Nyquist Teoremi
- 4. Sayısal-Örneksel Kodlama
- 5. Bit Hızı ve Baud Hızı
- 6. ASK, FSK, PSK ve QAM
- 7. Örneksel-Örneksel Kodlama
- 8. Sayısal Veri İletim Teknikleri ve Paralel İletim
- 9. Seri İletim ve RS-232
- 10. Eş Zamansız (Asenkron) Seri İletim
- 11. Eş Zamanlı (Senkron) Seri İletim
- 12. DTE-DCE Ara Birimleri
- 13. İletim Ortamı ve Kablolama
- 14. Koaksiyel Kablo ve İlk Ethernet
- 15. Burgulu (Twisted Pair) Kablolar
- 16. Fiber Optik Kablolar
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Planı

Ders online yapıldı ve hoca slaytlarını paylaşarak anlattı. Önce bir önceki derste yetişmeyen kodlama tekniklerinin kalanı bitirilecekti: örneksel-sayısal, sayısal-örneksel ve örneksel-örneksel kodlama. Ardından sayısal veri iletim teknikleri (paralel ve seri iletim) ve iletim ortamı konuşulacaktı.

İletim ortamı, veri iletimini fiziksel olarak sağlayan yapıdır. Hoca örnek olarak kabloyu, radyo frekansını, kızılötesini, mikrodalgayı ve ışığı saydı.

## 2. Örneksel-Sayısal Kodlama: PAM ve PCM

### 2.1 Örneksel İşareti Sayısallaştırmak

Örneksel (analog) işaret süreklidir. Bu yüzden sonsuz sayıda değerden oluştuğu kabul edilir. Onu sayısala çevirmek için işaretten belli aralıklarla örnek almak gerekir. Alınan örnek sayısı arttıkça kayıp azalır, çünkü işaretin yönündeki ve genliğindeki değişimler daha hassas izlenir. Kısa sürede çok örnek almak, daha yüksek çözünürlük demektir.

Hoca sesi örnek verdi. Mikrofondan gelen ses örneklenip sayısala çevrilir, hoparlöre giderken yeniden örneksele çevrilir. Arada sayısal bir aşama vardır.

### 2.2 PAM (Pulse Amplitude Modulation)

Örnekleme için kullanılan yöntemin adı PAM'dir. Slaytta solda sürekli bir örneksel işaret, sağda aynı işaretin eşit aralıklarla alınmış dikdörtgen darbeleri vardır (ekrandan, 00:15:00). Slayttaki ilke şudur: PAM kullanılırken dikkat edilmesi gereken önemli noktalardan biri örneklerin eşit zaman aralıklarında alınmasıdır.

Hoca sağdaki grafikte yaklaşık 22 örnek saydı. Bu kadar örnek varken yalnız darbelere bakarak bile özgün işarete çok yakın bir eğri çizilebilir. 22 yerine 3 ya da 5 örnek alınsaydı işaretin nereden geçtiği bilinemezdi.

### 2.3 Niceleme ve ADC

PAM ile elde edilen değerler, işaretin o anki genliğine karşılık gelen ölçümlerdir. Elektriksel bir işaret olduğu için bunlar gerilim ya da akım değerleridir. Bu değerlerin nicelenmesi (quantize) gerekir.

Ölçüm bir ADC (analog-digital converter) ile yapılır. ADC'nin bir bit genişliği vardır: 8, 10, 12 ya da 16 bit gibi. Bit genişliğine bağlı olarak ölçülebilecek en küçük ve en büyük değer belirlenir. Ölçülen genliğin bu aralık içinde nereye düştüğü hesaplanır. Niceleme budur.

Slayta göre PAM sonucunda dalga şeklindeki işaret yalnız darbe değerlerinden oluşan bir dizi örneksel değerdir. Bu darbelerin sayısallaştırılması PCM (Pulse Code Modulation) ile yapılır. Slayttaki grafikte seviyeler -127, -64, -32, 32, 64, 127 çizgileriyle gösterilmiştir (ekrandan, 00:20:00).

### 2.4 PCM (Pulse Code Modulation)

Slayttaki tanım şöyledir (ekrandan, 00:25:00):

- PCM ile her darbeye karşılık 7 bit ile ifade edilebilen bir sayı verilerek işaret nicelenir.
  - 8. bit işareti (artı ya da eksi) belirtmek için kullanılır.
- Bu sayısal değerler ikili sayı düzeninde ifade edilince örneksel işaretin 0 ve 1'lerden oluşan sayısal karşılığı elde edilir.

Slayttaki örnek dizi:

```text
16  48  50  18  -16  -50  -80  -80  -60  -40  -12  20  45 ...
```

Bu dizi tamamen sayısaldır. Hoca PCM'in 8 bit olmak zorunda olmadığını da söyledi. İlk sürüm telefon hatları için çıktığından 8 bit fazlasıyla yetiyordu. Kaliteyi ya da duyarlılığı artırmak için 16 ve 24 bitlik sürümler de vardır.

### 2.5 Soru-Cevap: ADC Bit Genişlikleri

**Soru:** ADC'lerin bit sayıları neden düzensiz artıyor? 8'in ya da 2'nin katı olmayan değerler (10, 12) görülüyor.

**Cevap:** Hoca bunun tamamen ekonomik bir karar olduğunu söyledi. Günümüzde mikrodenetleyicilerde 8 bit artık olmazsa olmazdır. Üretici kaliteyi artırmak için 10 ya da 12 bit de sunabilir. Ama ADC'nin iç çalışması bunun bir bedeli olduğunu gösterir. Mikrodenetleyicilerdeki ADC'ler çoğunlukla SAR (Successive Approximation, ardışık yaklaşım) yöntemiyle çalışır:

1. En anlamlı bit 1 yapılır ve oluşan gerilim örneklenen işaretle karşılaştırılır.
2. İşaret daha yukarıdaysa bu bit 1 olarak kalır ve bir sonraki bite geçilir.
3. Aynı karşılaştırma en anlamsız bite kadar sürer.

Her bit için bir adım gerektiğinden bit sayısı arttıkça dönüşüm süresi uzar, örnekleme hızı düşer. Tek adımda örnek alabilen ADC türleri de vardır, onlarda süre kaybı olmaz. Bit genişliğini artırmak maliyet demektir. Bu yüzden genel amaçlı mikrodenetleyicilerde 16 ya da 24 bitlik ADC pek görülmez. Ses uygulamalarına özel bir mikrodenetleyicide ise doğrudan 16 bitlik ADC olabilir.

Soru kodlama tekniği açısından düşünülürse, PCM'in 8 bitle başlamasının nedeni teknolojinin ve ihtiyacın yeterliliğidir. Telefonda kristal netliğinde ses ya da her nefes sesini duymak gerekmez. Amaç karşıdakini anlamaktır.

## 3. Örnekleme Kuralları ve Nyquist Teoremi

### 3.1 Eşit Aralık

PAM'de örnekler eşit aralıklarla alınmalıdır. Hoca 100 kHz örnekleme örneğini verdi: iki örnek arasındaki süre

$$T = \frac{1}{100\,000\ \text{Hz}} = 10\ \mu\text{s}$$

olmalıdır. Örnekler arasında bir 9, bir 5, bir 2 mikrosaniye fark olursa ortalık karışır ve elde edilen değerler bir şey ifade etmez.

### 3.2 Örnek Sayısı: Nyquist

İkinci kural ne kadar örnek alınacağıdır. Bunu belirleyen genelde Nyquist teoremidir. Herkesin kabul ettiği kural şudur:

> **Hocanın vurgusu:** Bir örneksel işaretin düzgün şekilde sayısallaştırılabilmesi için işaret içindeki en yüksek frekans (sıklık) bileşeninin en az iki katı kadar örnek alınması gerekir.

$$f_{\text{örnekleme}} \geq 2 \cdot f_{\max}$$

Örnek: 1000 ile 4000 Hz arasında frekans bileşenleri olan bir işaret, yani insan konuşması. En yüksek bileşen 4 kHz olduğundan saniyede $2 \times 4000 = 8000$ örnek alınmalıdır.

Hoca, Nyquist'in üzerine başka çalışmaların da geliştiğini söyledi. Örneğin compressed sensing alanında, örnekleme hızı iki kat olmasa da işaretin yeniden oluşturulup oluşturulamayacağı (reconstruct) araştırılır.

### 3.3 Sürecin Tamamı

Sesin bir şebeke üzerinden aktarılması ya da sayısal ortama kaydedilmesi şu adımlarla olur:

1. PAM ile ölçüm (örnekleme).
2. PCM ile niceleme.
3. İkiliye kodlama (encode).
4. Sayısal ortama aktarılacaksa sayısal-sayısal kodlama.

## 4. Sayısal-Örneksel Kodlama

### 4.1 Çevirmeli Modem Örneği

Sayısal-örneksel kodlamanın en bilinen kullanımı eskiden internete bağlanmak için kullanılan modemlerdi. Slayttaki bilgiler (ekrandan, 00:30:00):

- Evdeki bilgisayarla internete bağlanırken genelde ses iletişimi için kurulmuş örneksel telefon şebekesi kullanılır.
  - Eskiden internete, 0-4 kHz aralığındaki ses işaretlerini taşımak için tasarlanmış telefon şebekesi (POTS, Plain Old Telephony System) üzerinden erişilirdi.
  - Bu bağlantılar çevirmeli (dial-up) bağlantı olarak bilinir. Kapasiteleri ses şebekesinin bant genişliğiyle sınırlıdır.
  - Günümüzde DSL teknolojileri çok daha geniş bant sağlar.
- Bu durumda bilgisayardaki sayısal bilginin örneksel şebeke üzerinden iletilebilir hale getirilmesi gerekir. Bunun için sayısal-örneksel dönüşüm teknikleri kullanılır.

Modem ISP'nin telefon numarasını arar. Sonra sayısal bilgi, telefon hattında ses görüşmesine ayrılmış bant üzerinden örneksel işaret olarak gönderilir. Hoca bir ayrıntı anlattı: aynı hatta paralel bağlı bir telefonun ahizesi kaldırılınca veri aktarımı duyulabiliyordu. Ama aynı anda hem veri aktarıp hem konuşmak mümkün değildi, çünkü veri zaten ses bandında taşınıyordu. Ahize sertçe kapatılırsa hattın teknolojisine göre bir kapatma (hang-up) işareti oluşup bağlantı kopabilirdi.

### 4.2 DSL

Günümüzde 0-4 kHz bandına sıkışılmaz. DSL (Digital Subscriber Line) yine aynı bakır telefon hattını kullanır. Ancak hat santral tarafında DSLAM denen bir cihaza bağlanır. Böylece yalnız ses bandı değil, onun çok üstündeki frekanslar da kullanılır ve çok daha yüksek bant genişliği elde edilir.

> **Ders sonrası not:** Altyazıda ADSL "Asenkron Digital Subscriber Line" diye geçiyor. Doğrusu Asymmetric (asimetrik) Digital Subscriber Line'dır. Sorun büyük olasılıkla Whisper'ın yanlış yazmasından kaynaklanıyor.

### 4.3 Taşıyıcı İşaret ve Üç Temel Özellik

Sayısal bilgiyi örneksele çevirmek için örneksel bir işaretin özellikleriyle oynanır. Örneksel işaretin üç temel özelliği vardır: genlik, frekans (sıklık) ve faz. Bunlara karşılık gelen yöntemler:

- Genlik: ASK (Amplitude Shift Keying).
- Frekans: FSK (Frequency Shift Keying).
- Faz: PSK (Phase Shift Keying).
- Genlik ve faz birlikte: QAM (Quadrature Amplitude Modulation). QAM'nin 32, 64, 128 gibi sürümleri vardır.

Özellikleri değiştirilecek işarete taşıyıcı işaret (carrier signal) denir. Slayttaki tanım (ekrandan, 00:35:00):

- Örneksel iletimde gönderici, taşıyıcı işaret olarak adlandırılan ve bilginin hedefe iletilmesini sağlayacak yüksek frekanslı bir işaret üretir.
  - Alıcı kendini bu taşıyıcı işarete göre ayarlamaya çalışır.
  - İki uç, anlaşabildikleri uygun frekansı bulana kadar kendilerini ayarlar.

Bağlantının kapasitesi birkaç şeye bağlıdır. Ortamın, yani kablonun desteklediği kapasite bunlardan biridir. Taşıyıcının frekansı da aktarılabilecek veri miktarını belirler: frekans yüksekse birim zamanda işaret üzerinde daha çok değişiklik yapılabilir.

## 5. Bit Hızı ve Baud Hızı

- **Bit hızı (bps):** Bir saniyede gönderilen bit sayısıdır.
- **Baud hızı:** Bir saniyede gönderilen işaret (sembol) sayısıdır, yani taşıyıcı üzerinde yapılan değişiklik sayısı.

Taşıyıcının frekansı arttıkça baud hızı, baud hızı arttıkça da bit hızı artar. ASK, FSK ve iki fazlı PSK'da her baud tek bir biti (0 ya da 1) taşır, bu yüzden bit hızı ile baud hızı aynıdır. Daha fazla seviye kullanıldığında bir sembol 00, 01, 10 ya da 11'i gösterebilir. O zaman bit hızı baud hızının iki katı olur. QAM'de sembol başına üç ya da daha fazla bit taşınabilir.

Slayttaki tablo (ekrandan, 00:55:00):

| Kodlama tekniği | Ünite | Baud hızı | Bit hızı | Bit / Baud |
|---|---|---|---|---|
| ASK, FSK, 2PSK | Bit | N | N | 1 |
| 4PSK, 4QAM | Dibit | N | 2N | 2 |
| 8PSK, 8QAM | Tribit | N | 3N | 3 |
| 16QAM | Quadbit | N | 4N | 4 |
| 32QAM | Pentabit | N | 5N | 5 |
| 64QAM | Hexabit | N | 6N | 6 |
| 128QAM | Septabit | N | 7N | 7 |
| 256QAM | Octabit | N | 8N | 8 |

> **Ek bilgi (derste anlatılmadı):** Tablodaki ilişki genel olarak $\text{bit hızı} = \text{baud hızı} \times \log_2 M$ diye yazılır. Burada $M$ farklı sembol sayısıdır.

## 6. ASK, FSK, PSK ve QAM

### 6.1 ASK (Genlik Modülasyonu)

ASK'da işaretin frekansı ve fazı sabit tutulur, yalnız genliği değiştirilir. Hangi genlik seviyesinin neyi göstereceğine sistemi tasarlayan karar verir. Örneğin düşük genlik 0, yüksek genlik 1 olabilir.

Hoca sınıfa ASK'nın doğasından gelen sorunları sordu. Bir öğrenci parazit cevabını verdi. Hoca bunu onayladı ve daha önce konuşulan zayıflamayı (attenuation) da ekledi: 1'i göstermek için gönderilen yüksek genlikli işaret, mesafeye bağlı olarak örneğin 50 metre sonra düşük genlikli bir işarete dönüşebilir. Bu yüzden ASK uzun mesafede ve gürültülü ortamda sorunludur ve pek sevilen bir yöntem değildir.

Slayttaki bilgi (ekrandan, 00:40:00):

- ASK dış ortamdan gelen parazitlere (gürültü) son derece duyarlıdır.
  - Dış ortamdan gelen ısı ve elektromanyetik etkiler taşıyıcının üzerine gerilim ekleyebilir. Bu, gönderilen 0'ın 1 olarak (ya da tersi) anlaşılmasına yol açabilir.
- Grafik: düşük ve yüksek genlikli dalgalar sırayla gelir. Her aralık "1 Bit" ve "1 Baud" diye etiketlenmiştir. Kalın dikey çizgiye kadar bir saniyelik bölümde 5 aralık vardır: **bit hızı = 5, baud hızı = 5**.

### 6.2 FSK (Frekans Modülasyonu)

FSK'da işaretin frekansı artırılıp azaltılır. Slayttaki örnekte 0 bir frekansla, 1 iki katı frekansla gösterilir. Bir saniyelik bölümde yine 5 aralık, yani 5 değişiklik vardır. Her biri 1 bit taşıdığından bit hızı 5 bps, baud hızı 5 baud'dur. FSK'nın iyi tarafı, genlikle değil frekansla oynandığı için dış ortam parazitlerinden ASK kadar kolay etkilenmemesidir.

### 6.3 Soru-Cevap: FSK'nın Eksisi

**Soru:** Frekans modülasyonunun bir eksisi ya da yan etkisi var mı?

**Cevap:** Hoca uygulama zorluğunu anlattı. Genliği değiştirmek çok kolaydır: işaretin hepsini gönderen sizsiniz, çıkışa bir yükselteç (amplifier) koyarak genliği hemen değiştirebilirsiniz. FSK'da işaretin frekansını sürekli değiştirmek gerekir. Daha önemlisi, işaret yalnız gönderilmez, karşı tarafta da algılanmalıdır. Frekans değişikliğini algılamak daha zordur. Faz değişikliğini algılamak ise daha da zordur. Her modülasyonun karşı tarafta bir demodülasyonu olmalıdır ve bu hassasiyet gerektirir.

Hoca konuyu radyoya bağladı. Radyodaki FM ve AM bantları frekans ve genlik modülasyonunun günlük hayattaki karşılıklarıdır. Orada birebir FSK yapılmaz, örneksel bir işaret örneksel bir taşıyıcıya bindirilir, ama mantık benzerdir.

### 6.4 PSK (Faz Modülasyonu)

PSK'da işaretin başlangıç noktası, yani fazı değiştirilir. En basit hali 0° ve 180°'dir: işaret ters çevrilerek öbür değer gösterilir. Bu durumda her baud bir bit taşır, bit hızı ile baud hızı aynıdır.

Daha fazla faz kullanılırsa her sembol birden fazla bit taşır. 0°, 90°, 180° ve 270° olmak üzere 4 faz varsa bunları göstermek için 2 bit yeterlidir. Hocanın anlattığı eşleme:

| Bit çifti | Faz |
|---|---|
| 00 | 0° (özgün işaret) |
| 01 | 90° |
| 10 | 180° |
| 11 | 270° |

Slayttaki örnek dizi (ekrandan, 00:50:00): sırasıyla `01`, `10`, `10`, `11`, `00`. Beş baud vardır ve her baud 2 bit taşır: **bit hızı = 10, baud hızı = 5**.

> **Ders sonrası not:** Slayttaki 4 fazlı PSK grafiğinde her aralığın üstünde "1 Bit" yazıyor. Oysa her aralık iki bit (01, 10 vb.) taşıyor ve slaytın kendi sonucu da "bit hızı = 10". Etiket büyük olasılıkla önceki slayttan kalmıştır. Doğrusu her baud için 2 bittir.

### 6.5 QAM

Genlik ve faz birlikte değiştirilince baud başına taşınan bit sayısı artar. Bu durumda semboller bir harita üzerinde gösterilir.

- 4 faz ve tek genlik seviyesi: QAM4. Her sembol 2 bit taşır.
- 4 faz ve 2 genlik: $4 \times 2 = 8$ birleşim. Her sembol $\log_2 8 = 3$ bit taşır.

Hocanın 8 birleşimli örnekte anlattığı semboller:

- `000`: özgün, değiştirilmemiş işaret.
- `001`: aynı işaretin genliği artırılmış hali.
- `100`: işaret 180° çevrilmiş.
- `101`: işaret 180° çevrilmiş ve genliği artırılmış.

<!-- BELİRSİZ: 8'li QAM haritasının kalan dört sembolünün (010, 011, 110, 111) hangi faz ve genliğe karşılık geldiği derste sözlü anlatılmadı ve o anın karesi yok. -->

Yüksek dereceli QAM her hatta kullanılamaz. 64 ya da 128 kullanıldığında haritadaki semboller birbirine çok yakındır. Küçük bir sapmada karşı taraf örneğin 0000 yerine 1111 algılayabilir ve iletişim tamamen bozulur.

## 7. Örneksel-Örneksel Kodlama

Örneksel-örneksel kodlamanın en bilinen örneği radyo yayınıdır. Zaten örneksel olan bir işaret (ses), yine örneksel bir taşıyıcının üzerine bindirilip gönderilir. Üç temel modülasyon vardır:

- **AM:** Taşıyıcının genliği, gönderilmek istenen örneksel işaretle değiştirilir (kiplenir). Genlik doğrudan iki seviye arasında değiştirilmez, taşınan işaretle birleştirilerek değiştirilir.
- **FM:** Taşıyıcının frekansı, taşınan işaretin genlik değerlerine göre değiştirilir.
- **PM:** Taşıyıcının fazı, taşınan işaretin genlik değerlerine göre değiştirilir.

Hoca genelde FM'in kullanıldığını söyledi.

## 8. Sayısal Veri İletim Teknikleri ve Paralel İletim

### 8.1 Tanımlanması Gerekenler

Şimdiye kadar alıcı, verici ve işaret üzerinde yapılabilecek modülasyonlar konuşuldu. Ama alıcı ve vericinin ortama nasıl bağlanacağı da belirlenmelidir. Slayttaki bilgi (ekrandan, 01:10:00):

- Kodlanmış bilginin bir iletim ortamından aktarılabilmesi için bazı özelliklerin tanımlanmış, standartların belirlenmiş olması gerekir:
  - İletim ortamına mekanik bağlantıyı sağlayacak konektör tipi.
  - Bağlantıda kullanılacak tel sayısı ve bu tellerden hangi tip işaretlerin hangi amaçla gönderileceği.
  - Gönderilecek işaretin frekans, genlik ve faz gibi özellikleri.
- İki uç arasındaki sayısal veri iletimi paralel ya da seri olabilir.

Örneğin seri haberleşmede senkron, asenkron ya da izosenkron bir yapı olabilir. Buna göre bir saat (clock) sinyali olacak mı, olacaksa hangi telden gidecek, hangi tel transmit, hangi tel receive, kontrol sinyalleri hangi tellerde olacak gibi sorular önceden belirlenmelidir.

### 8.2 Paralel İletim

Paralel iletimde n bit (8, 4, 16 ya da 32 olabilir) aynı anda aktarılır. Her bit için ayrı bir tel kullanılır ve bitlerin hepsi kendi telleri üzerinden tek seferde gönderilir.

Hoca sınıfa paralel iletimin en büyük avantajını ve dezavantajını sordu. Avantaj hızdır. Dezavantajı bir öğrenci tel sayısının fazla olması diye cevapladı. Hoca bunun sonucunun maliyet olduğunu vurguladı. 5 metrelik bir bağlantıda 8 bitlik paralellik için bir yerine 8 kablo, yani 5 yerine 40 metre kablo gerekir. Kısa mesafede bu çok batmayabilir, ama bir kilometrelik bir bağlantıda can sıkıcıdır.

### 8.3 Paralel Port ve Kontrol Pinleri

Paralel haberleşmenin en çok kullanıldığı yer yazıcılardı. Bu yapıda her bit için bir pin yanında kontrol pinleri de vardır. Yazıcının bilgisayara veri göndermesi normalde söz konusu değildir, ama bazı durumları bildirebilmesi gerekir: kağıt bitti, tamponum dolu, daha yavaş gönder gibi. Yazıcı özellikle eskiden büyük ölçüde mekanik bir cihazdı. Bilgisayar ise veriyi çok daha hızlı gönderebilir.

Slayttaki bilgi (ekrandan, 01:15:00):

- Paralel bağlantıda 18 tel kullanılır.
  - 8 tanesi veri iletimi için.
  - Diğerleri kontrol amaçlı.
- Paralel iletişimdeki en büyük problem, çok kablolu iletimin getirdiği maliyet ve iletişimin kısa mesafeli oluşudur.
  - En uzun mesafe 25 feet / 7,5 m (Centronics).

Slayttaki DB25 erkek konektör şeması (ekrandan, 01:15:00):

| Pin | Sinyal | Pin | Sinyal |
|---|---|---|---|
| 1 | Strobe | 14 | Autofeed |
| 2 | Data bit 0 | 15 | Error |
| 3 | Data bit 1 | 16 | Reset |
| 4 | Data bit 2 | 17 | Select |
| 5 | Data bit 3 | 18 | Signal ground |
| 6 | Data bit 4 | 19 | Signal ground |
| 7 | Data bit 5 | 20 | Signal ground |
| 8 | Data bit 6 | 21 | Signal ground |
| 9 | Data bit 7 | 22 | Signal ground |
| 10 | Acknowledge | 23 | Signal ground |
| 11 | Busy | 24 | Signal ground |
| 12 | Paper out | 25 | Signal ground |
| 13 | Select | | |

Hoca kontrol pinlerinin çoğunun doğrudan kullanılmadığını, tasarım gereği standarda konduğunu söyledi. Seri bağlantıda ise en fazla 4 tel (ground, clock, transmit, receive gibi) yeterlidir. Diferansiyel kodlama kullanıp saat telinden vazgeçerek, özellikle tek yönlü çalışmada, bu sayı 3'e ya da 2'ye bile inebilir. Paralel iletimin bir başka sorunu mesafe sınırıdır. Hoca bunun temel nedeninin aktarımın yine bir saat üzerinden yapılması olduğunu söyledi.

> **Hocanın vurgusu:** Konektörün hangi pininin ne için kullanıldığını ezberlemeniz beklenmiyor. Bu tablolar genel kültür içindir.

### 8.4 İki PC Arasında Paralel Bağlantı (Interlink)

PC-yazıcı arasındaki paralel haberleşme değiştirilerek eskiden iki PC arasında da kullanılabiliyordu. Ancak yazıcıya özgü pinler olduğu için iki paralel port doğrudan bağlanıp çalışması beklenemez. Bunun yerine bazı pinler çaprazlanarak null modem benzeri bir bağlantı yapılır ve özel bir yazılımla haberleşme sağlanır.

Slayttaki "interlink paralel bağlantı için gerekli bacak bağlantıları" tablosu (ekrandan, 01:20:00):

| Bağlantı 1 | Bağlantı 2 | 1. uçtaki sinyal | 2. uçtaki sinyal |
|---|---|---|---|
| 2 | 15 | Data bit 0 | Error |
| 3 | 13 | Data bit 1 | Select |
| 4 | 12 | Data bit 2 | Paper Out |
| 5 | 10 | Data bit 3 | Acknowledge |
| 6 | 11 | Data bit 4 | Busy |
| 10 | 5 | Acknowledge | Data bit 3 |
| 11 | 6 | Busy | Data bit 4 |
| 12 | 4 | Paper Out | Data bit 2 |
| 13 | 3 | Select | Data bit 1 |
| 15 | 2 | Error | Data bit 0 |
| 25 | 25 | Signal ground | Signal ground |

Tablo kendi içinde ayna gibidir. Bir uçtaki 5 veri biti, karşı uçta hep kontrol pinlerine (Error, Select, Paper Out, Acknowledge, Busy) bağlanır. Hileli tarafı buradadır: bir uçtan veri çıktığında karşı tarafta kontrol pinlerinden en az biri tetiklenir ve bir uyarı (interrupt) oluşur. Böylece karşı taraf veri geldiğini anlar.

## 9. Seri İletim ve RS-232

### 9.1 Seri İletimin Avantajları

Seri iletimin en temel avantajı tel sayısının azalmasıdır. Paralelde 8 ya da 16 tel gerekirken seride böyle bir kısıt yoktur. Tel azaldığı için maliyet azalır. İkinci avantaj mesafe kısıtının kalkmasıdır. Hoca uzun mesafenin sorunlarını hatırlattı: sayısal işaretin ortalamasına bağlı olarak bir DC bileşen oluşabilir, kablo uzadıkça işaret zayıflar ve uzun mesafede saat sinyali taşımak kaymalara yol açar. Seri iletimde bunları çözen teknikler kullanılır.

Seri iletim iki kategoriye ayrılır: eş zamansız (asenkron) ve eş zamanlı (senkron). Eş zamanlılık, alıcı ve göndericinin aynı saat sinyalini kullanması demektir. Saati iki uçtan biri üretir ve iki uç da hattaki veri değişimini bu sinyale göre izler. Ancak saati her zaman ayrı bir hatta göndermek istenmez, bu yüzden eş zamanlılık farklı yollarla da sağlanır.

### 9.2 RS-232 (EIA-232)

Seri iletim denince akla gelen ilk standart RS-232'dir. Standardı koyan kuruluşun adıyla EIA-232 diye de anılır.

- Kodlama: NRZ-L (Non-Return to Zero Level).
- Yalnız 3 tel yeterlidir: transmit, receive, ground.
- Konektör genelde 9 pinli DB9'dur. Kalan pinler isteğe bağlı olarak akış kontrolü için (Ready to Send, Clear to Send vb.) kullanılır.
- Gerilim seviyeleri:
  - -5 V ile -15 V arası: 1.
  - +5 V ile +15 V arası: 0.

Uzun mesafede işaret zayıflar. Gerilim aralığı geniş tutulursa, bir uçta -15 V basıldığında birkaç metre sonra zayıflasa bile değer -4, -2 ya da 0'a çıkmaz ve hâlâ anlamlandırılabilir aralıkta kalır.

## 10. Eş Zamansız (Asenkron) Seri İletim

### 10.1 Temel İlke

Slayttaki tanım (ekrandan, 01:25:00):

- Zamanlamanın önemli olmamasından dolayı eş zamansız adını alan bu iletimde, gelen bilgiler önceden anlaşılmış bir dizilişe uygun olarak, geliş ritmine bakılmaksızın alınır.
  - İki uç ortak bir zamanlama işaretine bağlı hareket etmez.
  - Her uç, aralarında anlaştıkları saat frekansına bağlı kalmak kaydıyla kendi saat darbesine göre çalışır.
    - Bazı ufak kaçıklıklar olabilir (clock drift).
- Gönderici veri hazır olduğu anda gönderir, alıcı veri geldiği anda almaya hazırdır.

Ortak bir saat olmadığı için iki taraf bir bit aralığının süresinde önceden anlaşmış olmalıdır. Hoca slayttaki grafikte bir başlama biti, ardından değişen ve değişmeyen bitler (arada dört 0) gösterdi. Ardışık iki 0 arasında hatta değişim olmaz, ama alıcı süreden ikinci 0'ın başladığını anlar.

### 10.2 Başlama ve Bitiş Biti

RS-232'de hatta veri yokken bile negatif gerilim (-15 V), yani 1 basılır. Gönderici herhangi bir anda veri gönderebilir. Verinin başladığını göstermenin en iyi yolu hattaki durumun tersini, yani pozitif gerilimi (0) göndermektir. Bu yüzden başlama biti 0'dır.

Slayttaki bilgi (ekrandan, 01:30:00):

- Alıcının gönderilen byte'ın bittiğini anlaması ve hattaki iletimin sona erdiğini görmesi için bir bitiş (stop) biti kullanılır.
  - Bu bit "1" değerini (negatif gerilim) taşır.
  - Böylece hatta en son negatif gerilim bırakılarak veri iletimi olmadığı belirtilir.
- Yaygın seri iletim formatı 8-N-1 olarak adlandırılır.
  - 1 başlama biti + 8 veri biti + 1 bitiş biti.
  - İletim en az anlamlı bitten (LSB) başlar.
  - N harfi eşlik (parity) bitinin kullanılmayacağını belirtir.
- 7-E-1 kodlaması: 1 başlama biti + 7 veri biti + 1 eşlik biti (Even) + 1 bitiş biti.

Eşlik biti, aktarılan veride hata olup olmadığını izlemek için eklenir. İki türü vardır: tek (odd, O) ve çift (even, E). Gösterimde başlama biti hiç yazılmaz, çünkü her seferinde bir başlama biti konacağı standarttır. Bitiş biti ise 1, 1,5 ya da 2 olabildiği için ayrıca belirtilir.

### 10.3 Neden 8 Bit? Saat Kayması

Başlama bitini gören iki taraf kendi zamanlayıcılarını kurar. Bu iki zamanlayıcı birbirinden bağımsız saat sinyallerine bağlıdır ve aralarında kayma (drift) olabilir. Bir osilatör ne kadar hassas üretilirse üretilsin bir doğruluk değeri vardır: %1, %5, %10 gibi. Hoca %10'un pratikte işe yaramadığını, %1'in iyi bir seviye olduğunu söyledi. Mikrosaniyeler düzeyinde her zaman bir kayma olasılığı vardır ve bu kayma ardışık bitlerde birikir. Hocanın örneğiyle ilk bitte %5 olan kayma ikincide %10, üçüncüde %15, dördüncüde %20 olur ve sonunda mutlaka hataya yol açar. Hata oranını makul tutmak için tek seferde aktarılan bit sayısı 8 ile sınırlanmıştır.

> **Ders sonrası not:** Hoca %1'lik hata için bir dakikanın 66 ya da 54 saniye ölçülebileceğini söyledi. 60 saniyenin %1'i 0,6 saniyedir. Doğrusu 60,6 ya da 59,4 saniyedir. 66 ve 54 saniye %10'luk sapmaya karşılık gelir.

### 10.4 Ek Yük ve Zamanlama

8 bitlik veri için bir başlama ve bir bitiş biti eklenince 10 bit gönderilir:

- Veriye göre: $2/8 = \%25$ fazla bit gönderilir.
- Toplama göre: $2/10 = \%20$'si kontrol bilgisidir.

Asenkron iletimde veri, düzenli ya da eşit aralıklı bir yapıda gönderilmez. Gönderici "her saniyenin başında gönderirim" gibi bir kurala bağlı değildir. Bilgi ne zaman hazırsa o zaman hatta çıkar.

## 11. Eş Zamanlı (Senkron) Seri İletim

### 11.1 Eş Zamanlılığı Sağlamanın Yolları

Seri iletim eş zamanlı yapılacaksa iki taraf arasında eş zamanlılık sağlanmalıdır. Hoca üç yol saydı:

1. **Ortak bir saat sinyali:** Alıcı ya da gönderici hatta sürekli bir saat basar (gerilim olarak 5, 0, 5, 0 gibi). Karşı taraf saatteki değişime, örneğin düşen ya da yükselen kenara göre kendini eşler ve veri hattındaki değişikliği o anda okur.
2. **Saati veriye gömmek:** Manchester kodlamada saat ayrıca gönderilmez. Veri saate bağlı olarak kiplenir.
3. **Preamble:** Veriden önce hatta belirli bir dizi gönderilir. Bu dizi gelince karşı taraf birazdan veri geleceğini anlar ve kendini eşler.

**Soru:** Saat sinyalinden kastınız bir sinyal gönderip iki tarafta da saati başlatmak mı?

**Cevap:** Hayır. Alıcının ya da göndericinin hatta sürekli bir saat (0, 1, 0, 1 gibi) basması kastediliyor. Karşı taraf bu saatteki değişimlere göre kendini eşler.

Hoca sınıfa Manchester kodlamanın özelliğini sordu. Bir öğrenci, verinin değişimine göre işaretin karakterinin değiştirildiğini hatırladı. Hoca, Manchester'da saatin veriyle birleştirildiğini, özellikle diferansiyel türde sürekliliği sağlamak için kullanıldığını hatırlattı. Değer statik seviyelerle değil geçişlerle gösterilir: negatiften pozitife ya da pozitiften negatife bir geçiş bir değeri ifade eder.

Hoca preamble'ın fiziksel bir teknik olmadığını, LLC (Logical Link Control) seviyesinde çalıştığını söyledi. Radyo frekansıyla haberleşmede, örneğin Wi-Fi'de, preamble kullanılır. Slaytta "100 biti geçmez" gibi bir ifade olduğunu, ama aslında geçebildiğini ekledi. HDLC protokolünde de 48 bitlik kontrol verisi vardır.

> **Ders sonrası not:** Ethernet ve Wi-Fi'deki preamble büyük olasılıkla fiziksel katmanın (PHY) parçasıdır, LLC alt katmanının değil. Ayrıca slayttaki HDLC örneğindeki 48 bit büyük olasılıkla preamble değil, çerçevenin bayrak, adres, kontrol ve hata denetimi alanlarının toplamıdır. Slayt bu değeri "kontrol verisi" diye veriyor.

### 11.2 Blok Halinde İletim

Slayttaki bilgi (ekrandan, 01:35:00):

- Veri, içinde çok sayıda byte'ın yer aldığı (>1000 byte) bir dizi olarak alıcıya gönderilir.
- Eş zamanlı iletimde her veri bloğunun başını ve sonunu belirleyen ek bitler ve boşluklar yoktur. Verinin ayrıştırılması alıcıya bırakılmıştır.
- İletimin olmadığı anlar, 0 ve 1'lerden oluşan ve hatta veri olmadığını gösteren özel bir bit dizisiyle doldurulur.

### 11.3 HDLC Ek Yük Örneği

Slayttaki örnek (ekrandan, 01:40:00):

- 1000 karakterden oluşan bir veri bloğu HDLC veri bağı protokolüyle gönderilmek istendiğinde aktarılması gereken veri 8048 bittir.
  - 1 karakter → 8 bit
  - 1000 karakter → 1 blok
  - Kontrol verisi → 48 bit
  - 1 blok → 8000 bit
  - 1 blok + kontrol verisi → 8048 bit
- Blok başına kontrol verisinin getirdiği ek yük: $48 / 8048 \approx \%0{,}6$.

Hesap: $1000 \times 8 = 8000$ bit, $8000 + 48 = 8048$ bit, $48/8048 = 0{,}00596 \approx \%0{,}6$. Bu binde 6 civarındadır. Asenkron iletimdeki %20 ile karşılaştırınca arada çok büyük fark vardır.

### 11.4 Karşılaştırma

| | Eş zamanlı (senkron) | Eş zamansız (asenkron) |
|---|---|---|
| Artıları | Daha etkin kullanım, daha iyi hata kontrolü, daha yüksek hız | Daha basit, daha ucuz, eş zamanlılık için ek çaba yok |
| Eksileri | | Hız sınırlı, hata kontrolü sınırlı (RS-232'de yalnız bir eşlik biti), ek yük yüksek (%20) |

## 12. DTE-DCE Ara Birimleri

### 12.1 DTE ve DCE

Haberleşme paralel ya da seri olsun, cihazlar iki temel sınıfa ayrılır:

- **DTE (Data Terminal Equipment, veri uç birimi):** Veriyi üreten ya da işleyen cihaz. Örnek: veriyi üreten bilgisayar, veriyi işleyen yazıcı.
- **DCE (Data Circuit-terminating Equipment, veri iletişim birimi):** Bir taraftan aldığı veriyi uygun modülasyona sokup ileten cihaz. Bir yönde modülasyon, öbür yönde demodülasyon yaptığı için çoğunlukla modem denir.

Haberleşme için iki tarafta da bir DTE olmalı, her DTE bir DCE'ye bağlı olmalı ve DCE'ler bir ağ üzerinden haberleşmelidir. Eskiden DCE çevirmeli modemdi, DTE yine PC'ydi ve arada V.32, V.34 gibi standartlara uygun seri bağlantı vardı. Ağ yoksa iki bilgisayar null modem bağlantısıyla doğrudan bağlanabiliyordu. Günümüzde de bir DCE vardır: ADSL modem, kablo modem ya da fiber optik modem. Değişen, DTE ile DCE arasındaki bağlantıdır. Eskiden DB9 konektörlü seri ya da paralel bağlantılar kullanılırken bugün Wi-Fi ya da Ethernet kullanılır.

DTE ile DCE arasında tanımlanmış standartlar vardır: RS-232, RS-422, RS-449 ve ITU'nun V serisi standartları. Yönlendirici tipi cihazlarda hâlâ X serisi standartlar kullanılır.

> **Hocanın vurgusu:** DTE-DCE ara birimindeki her pinin ne işe yaradığı tek tek ezberlenecek bilgi değildir. Ama temel sinyaller (Receive Data, Transmit Data, Clear to Send, Data Terminal Ready, ground) tanınmalıdır.

### 12.2 Null Modem

İki PC aynı ortamdaysa bilgi aktarmak için modem ve internet kullanmak yerine DTE'ler doğrudan bağlanabilir. Bunun için pinler çaprazlanmalıdır: birinin transmit'i ötekinin receive'ine, birinin request to send'i ötekinin clear to send'ine bağlanır. Böylece birinin gönderdiği öteki tarafından algılanır. Çoğu zaman ek bir yazılım gerekmez.

Slayttaki null modem tablosu (ekrandan, 01:45:00):

| 1. uç sinyal | DB-25 | DB-9 | DB-9 | DB-25 | 2. uç sinyal |
|---|---|---|---|---|---|
| FG (Frame Ground) | 1 | - | - | 1 | FG |
| TD (Transmit Data) | 2 | 3 | 2 | 3 | RD |
| RD (Receive Data) | 3 | 2 | 3 | 2 | TD |
| RTS (Request To Send) | 4 | 7 | 8 | 5 | CTS |
| CTS (Clear To Send) | 5 | 8 | 7 | 4 | RTS |
| SG (Signal Ground) | 7 | 5 | 5 | 7 | SG |
| DSR (Data Set Ready) | 6 | 6 | 4 | 20 | DTR |
| DTR (Data Terminal Ready) | 20 | 4 | 6 | 6 | DSR |

## 13. İletim Ortamı ve Kablolama

### 13.1 Altyapı Yatırımı Olarak Kablolama

Bir ağ kurulurken kablolu ortamın toplam harcama içindeki payı küçüktür. Harcamanın çoğu aktif cihazlara ve onların bileşenlerine gider. Slayttaki bilgi (ekrandan, 01:50:00):

- İletişimin gerçekleşmesi için olmazsa olmaz parçalardan biri iletim ortamıdır.
  - İletim ortamı bir altyapı yatırımı olarak değerlendirilmelidir.
  - Altyapı yatırımına yapılan harcama oransal olarak daha azdır.
- Slayttaki grafik ömür ve maliyeti karşılaştırır. Kablolamanın ömrü en uzun, maliyeti en düşüktür. Sırasıyla yerel alan ağı teknolojisi, bilgisayar teknolojisi ve yazılımda ömür kısalır, maliyet artar.

> **Hocanın vurgusu:** Kablolama maliyeti düşüktür, ama bir sorun olduğunda yeniden kablolama ya da onarım maliyeti yüksektir.

Örneğin kampüste A noktasından B noktasına kablo götürmenin asıl maliyeti kazı ve hattın döşenmesidir. Kablonun kendisi çok daha ucuzdur. Bu yüzden tek kablo yetse bile aynı kanala birkaç kablo çekilir. Bu, kemirgen hasarı ya da atık su, sulama, elektrik gibi başka bir altyapı çalışmasında kabloya zarar verilmesi gibi kazalara karşı korur. Ancak bir kazada bir kablo zarar görürse aynı kanaldaki öbürü de büyük olasılıkla zarar görür. Bu yüzden asıl yapılması gereken, ikinci hattı başka bir güzergâhtan dolaştırarak çoklamaktır. Bu başta boşa yatırım gibi görünse de arıza anında sağladığı fayda çok daha yüksektir.

### 13.2 Link Aggregation Örneği

Hoca bir örnek verdi. 40 Gbps'lık fiber modüller çok pahalıysa, A ile B arasında bir yerine dört hat çekilip 10 Gbps'lık modüller kullanılabilir. Örneğin 10'luk modül 1 birim, 40'lık modül 10 birim fiyatındaysa bu yaklaşım ucuzdur. Hatlar bağlantı seviyesinde birleştirilir (link aggregation):

- Toplam kapasite: $4 \times 10 = 40$ Gbps.
- Bir hat koparsa: $3 \times 10 = 30$ Gbps kalır.
- Asıl ihtiyaç 10 Gbps ise hizmet sürer. Bir hat daha koparsa iki hatla çalışmaya devam edilir ve sorun kimseye hissettirmeden çözülebilir.

### 13.3 Yönlendirilmiş ve Yönlendirilmemiş Ortam

- **Yönlendirilmiş (guided):** İşaretin belli bir sınır içinde kalmasını sağlayan ortam, yani kablo. Bakır kabloda elektrik işareti taşınır. Fiber kablo silika (cam) tabanlıdır ve içinden ışık taşınır.
- **Yönlendirilmemiş (unguided):** Kızılötesi, radyo frekansı (RF), mikrodalga.

Kablolama için çok sayıda standart vardır: ABD'de EIA, uluslararası ISO, Avrupa Birliği için CENELEC. Bunlar çoğu zaman örtüşür ve en azından bazı temel şartları ortak sağlar.

## 14. Koaksiyel Kablo ve İlk Ethernet

### 14.1 Koaksiyel (Eş Eksenli) Kablo

Yönlendirilmiş kablo denince akla ilk gelen koaksiyel kablodur. Bugün en çok uydu alıcılarında görülür: çanaktaki LNB'den alıcıya gelen, genelde beyaz renkli kablo koaksiyeldir ve 75 ohm empedans gösterir. Sayısal veri iletiminde kullanılan koaksiyel kablolar 50 ohm'dur.

Tek iletkenli bir yapı olduğu için ortam half-duplex'tir. Aynı anda birden fazla uç gönderirse çarpışma (collision) olur ve gönderilenler anlamsızlaşır. Bu yüzden herhangi bir anda yalnız bir ucun gönderebildiği bir yapı gerekir.

### 14.2 Thick Ethernet (RG-8)

Ethernet zaman içinde evrim geçirmiş bir teknolojidir. İlk sürümler yol (bus) topolojisindeydi. Thick Ethernet'te RG-8 denen sarı, kalın kablo kullanılır. Kablonun üzerine takılan konektörün dış yalıtımı delip bakıra kadar giren dişleri vardır. Buna vampir konektör denir. Konektörün bir ucunda 15 pinli bir arayüz vardır ve bilgisayara başka bir kabloyla bağlanılır. Kablonun istenen herhangi bir yerine bağlantı yapılabilir. Bu bağlanmayı çok kolaylaştırır, ama güvenlik açısından sorundur: kabloyu gören istenmeyen biri de kendini bağlayabilir.

Slayttaki bilgi (ekrandan, 01:55:00):

- Vampir ile bilgisayar ya da dağıtım ünitesi arasındaki bağlantıda 15 iğneli AUI (Attachment Unit Interface) kullanılır.
- Omurga üzerinde en fazla 100 bağlantı.
- Azami segment uzunluğu 500 m.
- Omurganın iki ucunda 50 Ω'luk dirençle sonlandırma yapılmalıdır.
- Şemada 10BASE-5 kartı, DB-15'ten AUI'ye kablo, Thicknet omurgası ve transceiver görülür.

### 14.3 Thin Ethernet (RG-58)

Sonra Thin Ethernet geldi. Bağlantı için BNC denen özel aparatlar kullanılır. BNC'nin bir tarafı kabloya oturur, öbür tarafında bir kilit mekanizması vardır. Yol topolojisi boyunca kablonun herhangi bir yeri kesilip bir T bileşeni takılır ve bu kilitle sabitlenir. Hoca Thin Ethernet'te desteklenen bağlantı sayısının daha az olduğunu söyledi (Thick'te 100, Thin'de 30). Kablo ince olduğu için kablolama daha rahat ve düzenlidir.

> **Ders sonrası not:** Altyazıda Thin Ethernet'te segment boyutunun daha büyük olduğu söyleniyor. Thin Ethernet'in (10BASE-2) azami segment uzunluğu büyük olasılıkla yaklaşık 185 m'dir. Bu, Thick Ethernet'in 500 m'sinden kısadır. Hoca büyük olasılıkla Thick Ethernet'i kastetti.

### 14.4 Switched ve Fast Ethernet

Buraya kadarki yapılar ilk Ethernet'tir ve 10 Mbps hızında çalışır. Sonra Ethernet hızlandırıldı. İlk adım anahtarlamalı (switched) yapıdır: yol topolojisinde herhangi bir anda yalnız bir uç konuşabilirken, anahtarlama farklı uçların kendi aralarında konuşabilmesini sağlar. Sonraki adım Fast Ethernet'tir: hız 10 Mbps'tan 100 Mbps'a çıkar. Bu geçişte hem bağlantı tipi hem kablo tipi değişti ve burgulu kablo kullanılmaya başlandı. Hoca bu gelişimin veri bağı katmanında ayrıca konuşulacağını söyledi.

## 15. Burgulu (Twisted Pair) Kablolar

### 15.1 Türler

Burgulu kablonun içinde ikişer ikişer kendi etrafında burgulanmış tel çiftleri vardır. İsimlendirme, çiftlerin ve dış yüzeyin nasıl korunduğuna göre değişir. Slayttaki bilgi (ekrandan, 02:00:00):

- Temelde 3 tip burgulu kablo vardır.
- **UTP (Unshielded Twisted Pair):** 100 Ω'luk bir kablodur. Desteklediği frekanslara göre CAT adı verilen numaralı alt sınıflara ayrılır.
- **ScTP/FTP (Screened/Foiled Twisted Pair):** 100 Ω'luk UTP kablonun etrafı, elektromanyetik gürültüyü azaltmak için alüminyum folyoyla sarılmıştır.
- **STP (Shielded Twisted Pair):** 150 Ω'luk burgulu kablodur. Çiftler ayrı kılıflar içindedir, hepsinin dışından bakır örgü geçirilir.

Hoca folyoyu mutfakta kullanılan alüminyum folyoya benzetti. Bakır örgü, kablonun darbe gibi dış etkilere dayanımını da artırır. Ortadan çiftleri ayıran plastik bir ayırıcının geçmesi, folyonun tüm çiftlere bir kez ya da her çifte ayrı sarılması gibi isimlendirmeyi karmaşıklaştıracak kadar çok tür vardır. Ama üç temel tip UTP, FTP ve STP'dir.

### 15.2 Neden Burgulanır?

Ortamda her zaman elektromanyetik gürültü olabilir. Kablo burgulanmazsa gürültünün aynı kablodaki farklı tellere etkisi birbirinden farklı olur. Burgulamanın temel nedeni bu etkinin teller üzerinde eşit (homojen) dağılmasını sağlamaktır.

### 15.3 Tek Damar ve Çok Damar

Teller tek damarlı olabileceği gibi birden fazla ince telden de oluşabilir. Çok damarlı kablo esneklik ve kırılmaya dayanım açısından daha iyidir. Ancak hoca, işaretin telin dış yüzeyi ile merkezi arasındaki bölgede taşındığını, çok damarlı kabloda her damar çok ince olduğu için bu alanın küçüldüğünü ve işaretin zayıfladığını anlattı. Bu yüzden tek damar tercih edilir.

### 15.4 Renk Kodları ve RJ45

Her çifte bir renk verilir: mavi, turuncu, yeşil ve kahverengi. Çiftin içinde biri düz renk (örneğin mavi), öbürü beyaz çizgili (mavi-beyaz) olur. Beyaz çizgili tellere halk arasında "pijamalı" denir, bilardo toplarında olduğu gibi.

Konektör olarak artık BNC ya da vampir yerine RJ45 kullanılır. Kablonun iki ucunda teller aynı sırayla dizildiği sürece sıranın önemsiz olduğu düşünülebilir. Ancak 568A ve 568B diye iki standart vardır ve bazı cihazlar ya da ağ kartları bunlardan birini isteyebilir. Günümüzde cihazlar çoğunlukla otomatik algılama yapar, ama kablolamayı standarda uygun yapmak her zaman daha etkilidir.

### 15.5 Çapraz Girişim

Dört çiftin hepsi, özellikle 1 Gbps haberleşmede, veri aktarımı için kullanılır. Bu yüzden aynı kablodaki çiftler birbirini etkiler. Hoca bu etkilerin adlarını saydı: yakın uç çapraz girişim (NEXT), uzak uç çapraz girişim (FEXT) ve eş düzey uzak uç çapraz girişim (ELFEXT). Bir çift, aynı uçtaki diğer çiftlerle de, kablonun öbür ucundaki çiftlerle de etkileşebilir. Bu yüzden pin dizilimi önemlidir.

Slayttaki şemada (ekrandan, 02:05:00) yerel (local) ve uzak (remote) uçta dört TX/RX çifti vardır. Her çiftin ucunda "H" kutusu bulunur. Şemada şu etkiler okla gösterilmiştir:

- ECHO: yerel uçta kendi gönderdiğinin geri yansıması.
- ATTENUATION: uzak uçtan gelen işaretin kablo boyunca zayıflaması.
- NEXT: aynı (yerel) uçtaki diğer çiftlerin gönderdiğinin girişimi.
- ELFEXT: uzak uçtaki diğer çiftlerin gönderdiğinin girişimi.

### 15.6 CAT Sınıfları

UTP kablolar CAT 1, 2, 3, 4, 5 diye sınıflanır. Günümüzde CAT5, CAT5e ve CAT6 kullanılır. Üniversitede görülen kablolar çoğunlukla CAT5 ya da CAT5e, zaman zaman CAT6'dır. CAT7 ve sonrasında konektör değişir.

## 16. Fiber Optik Kablolar

### 16.1 Yapı ve Avantajlar

Fiber kablo temelde silika ve plastikten üretilir. İç tarafta cam bir katman vardır. Üretimi pahalıdır, ama birçok avantajı vardır:

- İçinde elektrik işareti değil ışık taşınır. Bu yüzden elektromanyetik etkilerden ve gürültüden etkilenmez.
- Işığın farklı dalga boyları kullanılarak çok geniş bant genişliği elde edilir.
- Gecikme ve işaret zayıflaması açısından avantajlıdır.
- Güvenlik sağlar. Thick Ethernet'te ya da bugünkü CAT5/CAT6 kablolarda kablo kesilip araya dal atılarak dinleme yapılabilir. Fiberde bağlantı için ek (kaynak) yapmak ve bunu düzgün yapmak gerekir. Bu gizlice yapılabilecek bir iş değildir.

Altyapı firmaları ve ISP'ler kablolamada tek fiber çekmez. İçinde 16, 24, 32, 48 gibi çok sayıda lif olan kablolar çekerler. İhtiyaç olunca yalnız cihaz ekleyerek kapasite artırılır, yeniden kazı gerekmez. Bu liflerden bazılarından ışık geçer, aktif cihaza bağlı olmayanlardan geçmez. Içinde ışık olmayan liflere **dark fiber** denir.

Fiberin yapısı: ortada cam çekirdek (core), etrafında kılıf (cladding), sonra birincil ve ikincil tampon (buffer) katmanları. Bu iç ortamda iki aktif cihazı bağlamak için kullanılan yapıdır. Dış ortam fiberlerinde toprağa gömülme, kemirgenler ve başka kazılara karşı ek koruyucu katmanlar vardır. Dış ortam kablosu, çekirdek, kılıf ve birincil tampondan oluşan çok sayıda lifin (20, 40, 50 gibi) tek bir kablo içinde toplanmasıyla oluşturulur.

### 16.2 Single-Mode ve Multi-Mode

Slayttaki bilgi (ekrandan, 02:10:00):

- Fiber optik kablolar farklı çekirdek (core) ve kılıf (cladding) çaplarıyla üretilir.
  - Buna göre SMF (Single Mode Fiber) ve MMF (Multi Mode Fiber) olarak adlandırılırlar.
- Slayttaki kesitlerde dış/çekirdek çapı çiftleri: 125/9, 125/50, 125/62,5 ve 140/100.

**Single-mode fiber** ışığı neredeyse hiç kırılmadan, bükülmeden düz gönderir. Girişteki darbe ile çıkıştaki darbe arasında neredeyse fark yoktur. Üretimi maliyetlidir ama etkilidir.

**Multi-mode fiberde** ışık saçılarak ve yansıyarak ilerler, öbür uca farklı yollardan gelir. Bu yüzden girişteki ve çıkıştaki darbe arasında belirgin fark olabilir. İki türü vardır:

- **Step-index:** Kablodaki silikanın kırılma özelliği (hocanın deyişiyle yoğunluğu) her noktada aynıdır. Kenarlara çarparak sekerek ilerleyen ışınlar daha uzun yol alır ama aynı hızla gider. Kaynaktan çıkan işaretin parçaları çıkışa farklı zamanlarda ulaşır.
- **Graded-index:** Merkezde yoğunluk fazla, kenarlarda azdır. Merkezde ışık daha yavaş, kenarlarda daha hızlı gider. Kenardan giden ışın daha uzun yol alsa da daha hızlı gittiği için ışınlar çıkışta birbirine yakın zamanlarda birleşir. Bu yüzden graded-index multi-mode fiber daha çok tercih edilir.

> **Ek bilgi (derste anlatılmadı):** Hocanın "yoğunluk" dediği özellik optikte kırılma indisidir. Kırılma indisi yüksek olan bölgede ışık daha yavaş ilerler. Graded-index fiberde indis merkezden kenara doğru kademeli olarak azalır.

### 16.3 Işık Kaynakları ve Alıcı

İki temel ışık kaynağı vardır:

- **Lazer (injection laser diode, ILD):** Kesintisiz, düz ve odaklanmış işaret üretir. Single-mode fiberle kullanılır.
- **LED:** Odaklanma yoktur, ışık yayılır. Bu yüzden multi-mode fiber için uygundur.

Alıcı tarafta ışığı algılayan bir bileşen gerekir: fotodiyot. Üzerine ışık düşünce bunu elektrik işaretine çevirir.

### 16.4 Dezavantajlar ve Güvenlik

Fiberin eksileri de vardır. Hoca bir örnek verdi: çalışma odasında sandalyeyle bakır kablonun üzerinden geçilse kablo hırpalansa da çalışmaya devam eder. Aynı şey fiberde olursa o kablo bir daha kullanılamaz. Fiber ince olduğu için az yer kaplar, ama o kadar da narindir. Konektörde bir yağ lekesi ya da toz haberleşmeyi doğrudan engeller. Kullanılmayan uçların ve aktif cihaz portlarının kapakları takılı tutulmalıdır.

Slayttaki bilgi (ekrandan, 02:15:00):

- İki uçta kullanılan fiberlerin çekirdek kısımları tam olarak örtüşmelidir. Sorun çıkaranlar:
  - Kaymalar.
  - Açılı bağlantılar.
  - Bağlantı arasındaki mesafe.
  - Işık iletimini engelleyebilecek kir, yağ, toz ve çizikler.
- Fiber kablolar cam gibi kırılgandır, yumuşak bir şekilde kıvrılarak muhafaza edilmelidir.

Fiber bağlantı bir çiftle yapılır: bir lif transmit, öbürü receive içindir. Bir uçta lazer, öbür uçta fotodiyot vardır. Bir uçtaki lazer karşı uçtaki fotodiyoda bağlanır. Verici ve alıcı fiziksel olarak da ayrılmıştır.

> **Hocanın vurgusu:** Lazer kullanılan fiberde ışık göze zararlıdır. Kablonun hangi ucundan ışık çıktığını anlamak için ucu çevirip yüzünüze bakmayın. Ortamı karartın ya da karanlıkta ucu elinizle kapatıp ışığın hangi taraftan çıktığına bakın.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:39:35): ASK'nın, yönteminin doğası gereği yol açtığı sorunlar nelerdir?

> **Çözüm:** Genlik dış ortam parazitleriyle değişebilir. Ayrıca işaret mesafeye bağlı olarak zayıflar (attenuation). 1'i göstermek için gönderilen yüksek genlikli işaret, uzak bir noktada düşük genlikli bir işarete benzeyip 0 olarak algılanabilir. Bu yüzden ASK uzun mesafede ve gürültülü ortamda zayıftır.

**Soru 2** (ekrandan, 00:40:00): Slayttaki ASK grafiğinde bir saniyede 5 aralık vardır ve her aralık 1 bit taşır. Bit hızı ve baud hızı nedir?

> **Çözüm:** Her aralık bir sembol (baud) ve bir bittir. Baud hızı = 5 baud, bit hızı = 5 bps.

**Soru 3** (ekrandan, 00:50:00): 4 fazlı PSK'da (0°, 90°, 180°, 270°) bir saniyede 5 sembol gönderiliyor. Gönderilen dizi 01, 10, 10, 11, 00'dır. Bit hızı ve baud hızı nedir?

> **Çözüm:** 4 faz $\log_2 4 = 2$ bit/sembol demektir. Baud hızı = 5, bit hızı = $5 \times 2 = 10$ bps. Fazlar sırasıyla 90°, 180°, 180°, 270°, 0°'dir.

**Soru 4** (derste sözlü, 00:53:08): 4 faza 2 genlik seviyesi eklenirse her sembol kaç bit taşır?

> **Çözüm:** $4 \times 2 = 8$ birleşim vardır. $\log_2 8 = 3$ bit/sembol.

**Soru 5** (derste sözlü, 00:28:28): 1000-4000 Hz arasında frekans bileşenleri olan bir işaret (insan konuşması) sayısallaştırılacaktır. Saniyede kaç örnek alınmalıdır?

> **Çözüm:** Nyquist'e göre en yüksek bileşenin (4 kHz) en az iki katı: $2 \times 4000 = 8000$ örnek/s.

**Soru 6** (derste sözlü, 00:46:11): Radyoda dinlenen FM ve AM bantlarının adlarındaki harfler neyi ifade eder?

> **Çözüm:** FM, Frequency Modulation (frekans modülasyonu); AM, Amplitude Modulation (genlik modülasyonu). Bunlar örneksel bir işaretin örneksel bir taşıyıcıya bindirildiği örneksel-örneksel kodlama örnekleridir.

**Soru 7** (derste sözlü, 01:12:10): Paralel iletimin en büyük avantajı ve en büyük dezavantajı nedir?

> **Çözüm:** Avantajı hızdır. Dezavantajı tel sayısının fazlalığından gelen maliyettir. Örneğin 5 metrelik 8 bitlik paralel bağlantı için 40 metre kablo gerekir. Ayrıca mesafe kısıtlıdır.

**Soru 8** (derste sözlü, 01:36:19): Manchester kodlamanın özelliği neydi? Eş zamanlı iletimde nasıl kullanılır?

> **Çözüm:** Manchester kodlamada saat veriyle birleştirilir. Değerler statik seviyelerle değil, geçişlerle (negatiften pozitife ya da pozitiften negatife) gösterilir. Böylece ayrı bir saat hattı göndermeden alıcı kendini verideki geçişlere göre eşleyebilir.

**Soru 9** (ekrandan, 01:40:00): 1000 karakterlik bir veri bloğu HDLC ile gönderilecektir. Bir karakter 8 bit, kontrol verisi 48 bittir. Aktarılacak toplam bit sayısı ve ek yük oranı nedir?

> **Çözüm:** $1000 \times 8 = 8000$ bit veri. $8000 + 48 = 8048$ bit toplam. Ek yük $48/8048 \approx 0{,}006 = \%0{,}6$.

**Soru 10** (derste sözlü, 01:32:35): Asenkron 8-N-1 iletimde 1 byte gönderilirken ek yük oranı nedir?

> **Çözüm:** 1 başlama + 8 veri + 1 bitiş = 10 bit. Veriye göre $2/8 = \%25$ fazla bit gönderilir. Toplamın $2/10 = \%20$'si kontrol bilgisidir.

## Dersin Toparlaması

Dersin ilk yarısında kodlama teknikleri tamamlandı. Örneksel bir işaret PAM ile eşit aralıklarla örneklenir, PCM ile nicelenir ve ikili sayılara çevrilir. Örnekleme hızı Nyquist kuralına göre en yüksek frekansın en az iki katı olmalıdır. Sayısal veriyi örneksel bir ortamda taşımak için taşıyıcının genliği (ASK), frekansı (FSK), fazı (PSK) ya da genlik ve fazı birlikte (QAM) değiştirilir. Sembol başına taşınan bit sayısı arttıkça bit hızı baud hızının katlarına çıkar, ama alıcı tarafında hassasiyet ihtiyacı artar. Örneksel-örneksel kodlamanın günlük örnekleri AM, FM ve PM radyo yayınlarıdır.

İkinci yarıda sayısal veri iletim teknikleri ve iletim ortamı konuşuldu. Paralel iletim hızlıdır ama pahalı ve kısa mesafelidir. Seri iletim RS-232 gibi standartlarla az telle uzun mesafeye gider. Asenkron iletimde başlama ve bitiş bitleri her byte'ı eşler, ama %20 ek yük getirir. Senkron iletimde ortak saat, Manchester ya da preamble ile büyük bloklar çok düşük ek yükle gönderilir. DTE-DCE ayrımı ve null modem bağlantısı anlatıldı. İletim ortamında kablolamanın bir altyapı yatırımı olduğu vurgulandı, koaksiyel, burgulu ve fiber kablolar karşılaştırıldı. Bir sonraki derste yönlendirilmemiş ortamlar (radyo frekansı, mikrodalga, kızılötesi), çoğullama (multiplexing) ve zaman kalırsa hata sezme ve düzeltme konuşulacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
