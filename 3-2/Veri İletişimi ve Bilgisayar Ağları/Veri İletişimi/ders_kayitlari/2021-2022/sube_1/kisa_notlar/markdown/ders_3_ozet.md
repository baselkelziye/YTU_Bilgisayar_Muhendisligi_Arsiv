# Ders 3 Çalışma Özeti

## Genel Konular

- Veri bağı protokollerinin görevleri
  - Veri bağı kontrolünü (Data Link Control) yapan protokol akış kontrolü, hata kontrolü ve iletişim kurallarını yerine getirir.
  - Bunun için veriye kontrol bilgileri eklenir: çerçevenin başı ve sonu, adres bilgisi, sıra numarası, hata sezme kodu (checksum, CRC vb.).
  - Hata sezmede hatalı çerçevenin yeniden gönderilmesi, hata düzeltmede ise ek alanlar gerekir. Bu yüzden veri çerçevesi, kontrol çerçevesi ve ikisini birlikte taşıyan (piggyback) yapılara ihtiyaç vardır.
- Eşzamansız ve eşzamanlı protokoller
  - Eşzamansız protokoller modem bağlantılarında kullanılır. Başlangıç ve bitiş bitleriyle mantıksal eşzamanlama sağlanır. Ek bilgi yüzünden daha yavaştır. Örnekler: X-Modem, Y-Modem, Z-Modem, Kermit (ekrandan, 00:30:00).
  - Hoca bu tür protokollerin bugün mikrodenetleyici (ör. ARM tabanlı işlemci) ve ROM programlamada hâlâ benzer biçimde kullanıldığını söyledi.
  - Eşzamanlı protokollerde iki tür eşzamanlılık vardır: fiziksel seviyede ortak saat işaretiyle, mantıksal (veri bağı) seviyede FLAG'lerle (ekrandan, 00:35:00).
  - Başa konan eşzamanlama öncülü (preamble) ve sona konan ardılı (postamble) genel olarak flag diye anılır. Protokole göre adı değişir (SYN, EOT, HDLC'de flag).
- Byte (karakter) yönelimli protokoller
  - Çerçeve, her biri bir byte olan karakterlerin dizisi (byte stream) olarak görülür. Kontrol karakterleri kullanılan kodlamanın (ASCII, EBCDIC) karakter kümesinden, harf, sayı ve noktalama dışındaki kodlardan seçilir (ekrandan, 00:40:00).
  - Kontrol karakterleri: SYN, PAD, DLE, ENQ, SOH, STX, ETX, ETB, EOT, ACK, NUL, ters kesme (reverse interrupt), geçici metin gecikmesi gibi karakterler.
  - Temel çerçeve: `SYN SYN STX Veri ETX BCC` (ekrandan, 00:45:00).
  - Veri şeffaflığı sorunu ve DLE ile byte doldurma (byte stuffing).
  - Blok yapısı: bir çerçevede birden fazla blok, her bloğun kendi BCC'si.
  - Çok çerçeveli iletim: ara çerçeveler ETB ile, son çerçeve ETX ile biter. Her çerçeveye ACK0/ACK1 kontrol çerçevesiyle cevap verilir.
  - Örnek protokol: IBM BSC.
- Bit yönelimli protokoller
  - Çerçeve bit dizisi olarak görülür. Kontrol dizileri bit kalıplarıdır, şeffaflık bit doldurma (bit stuffing) ile sağlanır. Ek yük byte doldurmaya göre azdır.
  - Örnekler: SDLC, HDLC, LAPB, LAPD, LAPM (ekrandan, 01:05:00).
- HDLC
  - İstasyon tipleri (birincil, ikincil, birleşik), yapılanış (dengeli, dengesiz), iletişim kipleri (NRM, ARM, ABM).
  - Çerçeve tipleri (I, S, U), çerçeve alanları, flag, bit doldurma, adres alanı, kontrol alanı ve P/F biti.
- LAP ailesi ve SDLC
  - LAP protokolleri HDLC'nin basitleştirilmiş alt kümeleridir. SDLC, IBM'in SNA mimarisinde ikinci katmanda kullandığı protokoldür.
- Yerel alan ağlarına (LAN) giriş
  - Sınırlı bir coğrafi alanda, ortak bir iletim ortamını paylaşan çok noktalı haberleşme.
  - Ortam paylaşımı yaklaşımları: sabit atama, çekişme temelli, rezervasyon temelli ve karma yapılar.
  - IEEE 802 referans modeli: veri bağı katmanı MAC ve LLC diye ikiye bölünür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kontrol karakterinin verinin içinde geçmesi
  - Resim, ses, çalıştırılabilir dosya gibi ikili (binary) veride 0-255 aralığındaki her değer geçebilir. Örneğin ETX'in değeri verinin ortasında geçerse alıcı çerçevenin erken bittiğine karar verir. Bu yüzden veri şeffaflığı sağlanmalıdır.
- Byte doldurmanın ek yükü
  - Veride geçen her kontrol karakteri için bir byte daha eklenir. 50 özel karakter içeren bir çerçeve en az 50 byte ek yük taşır. Bit yönelimli protokollere geçişin nedeni budur.
- Pencere büyüklüğü ve hat gecikmesi
  - Hat gecikmesi yüksekse büyük pencere seçilir. Gecikme sırasında hat boşta kalacağı için o sürede daha çok çerçeve gönderilebilsin istenir. Hoca sınavda bununla ilgili soru olduğunu hatırlattı.
- Kodların ezberlenmesi gerekmez
  - Hoca, S ve U çerçevelerindeki kodların sayısal değerlerini ezber için değil, her kodun ayrı bir işe karşılık geldiğini görmek için verdiğini söyledi.
- HDLC'nin önemi
  - HDLC doğrudan kullanılmasa da birçok protokol (LAP ailesi, SDLC, Wi-Fi'deki bazı yapılar) onun mantığını kullanır.

## Kısa Tekrar Notları

- Veri bağı protokolü: akış kontrolü + hata kontrolü + iletişim kuralları.
- Eşzamansız: başlangıç/bitiş biti, modem, yavaş. Eşzamanlı: saat işareti (fiziksel) ya da flag (mantıksal).
- Byte yönelimli: karakter dizisi, kod bağımlı, DLE ile byte doldurma.
- Şeffaf veri: `DLE STX ... DLE ETX`, veride geçen DLE iki kez yazılır, alıcı ilkini atar.
- Blok yapısı: blokların her biri ayrı BCC ile kontrol edilir, hata olursa çerçevenin tamamı yeniden gönderilir.
- BSC: IBM, half-duplex, stop-and-wait, kod bağımlı.
- Bit yönelimli: bit dizisi, kod bağımsız, bit doldurma.
- HDLC flag: `01111110`. Art arda beş 1'den sonra araya 0 eklenir.
- Kontrol alanının ilk bitleri: `0` → I, `10` → S, `11` → U.
- I çerçevesi: `0 | N(S) | P/F | N(R)`, 3 bitlik numaralarla pencere en çok 7. Genişletilmiş kipte 7 bitlik numaralar, pencere en çok 127.
- S kodları: `00` RR, `01` REJ, `10` RNR, `11` SREJ.
- U çerçevesi: 2 + 3 = 5 bitlik kod, 32 durum.
- P/F: birincilden ikincile poll, ikincilden birincile final.
- NRM ve ARM dengesiz, ABM dengeli yapılanış içindir.
- LAN: paylaşılan ortam, patlamalı (bursty) trafik. 802'de veri bağı = MAC + LLC.

## Detaylı Açıklamalar

- **Veri bağı protokolleri ve çerçeve türleri.** Bir iletişim hattı üzerinden bilgi gönderirken yalnız veri değil, çeşitli kontrol bilgileri de gönderilir. Seri haberleşmedeki başlangıç ve bitiş bitleri bunun alt seviyedeki örneğidir. Üst seviyede çerçevenin boyutu, adresi, sıra numarası ve hata sezme kodu gibi alanlar gerekir. Byte yönelimli protokollerde iki tip çerçeve vardır: kontrol çerçevesi ve veri çerçevesi. Kontrol çerçevesi bağlantının kurulması, sürdürülmesi, akış kontrolü (stop-and-wait, Go-Back-N, Selective Repeat), alındı bilgisinin iletimi ve bağlantının sonlandırılması için kullanılır (ekrandan, 01:00:00). Veri çerçevesi de SOH, STX, ETX gibi kontrol karakterleri içerir. Yani kontrol bilgisi yalnız kontrol çerçevesinde bulunmaz.

- **Byte yönelimli çerçeve yapısı.** Her çerçeve iki SYN karakteriyle başlar. Bu, alıcıya yeni bir çerçevenin gelmekte olduğunu bildirir ve eşzamanlama sağlar. STX kontrol bilgisinin bittiğini ve verinin başladığını gösterir. Verinin büyüklüğü aktarılmadığından verinin sonu ETX ile belirlenir. Hata kontrolü için en sona BCC (Block Check Character) eklenir (ekrandan, 00:45:00). BCC sabit bir değer değildir. LRC ya da CRC gibi bir yöntemle hesaplanan sonuçtur ve her zaman en sona konur. Çok noktalı (bus) yapılarda gönderen ve alıcı adresi, sıra numarası gibi bilgiler başlıkta (header) taşınır. Başlığın başladığını SOH gösterir.

- **Veri şeffaflığı ve byte doldurma.** Bu protokoller başlangıçta metin aktarmak için tasarlanmıştı. İkili veri gönderilince kontrol karakterleri verinin içinde geçebilir. Çözüm DLE'dir: SOH, STX ve ETX'in önüne DLE konur. Bu durumda verinin içinde bir DLE geçerse önüne bir DLE daha eklenir. Kontrol amaçlı DLE her zaman tek görülür. Alıcı art arda iki DLE görürse ilkini atar ve ikincisini veri sayar. Ekrandaki şekilde verinin içinde `DLE ETX` geçen bir çerçeve, şeffaf hâlde `... DLE STX ... DLE DLE ETX ... DLE ETX BCC` olarak gönderilir. Eklenen DLE alıcı tarafından değerlendirilmez (ekrandan, 00:50:00).

  ```text
  Doldurma öncesi : SYN SYN DLE SOH Header DLE STX [ ... DLE ETX ... ] DLE ETX BCC
  Doldurma sonrası: SYN SYN DLE SOH Header DLE STX [ ... DLE DLE ETX ... ] DLE ETX BCC
  ```

- **Blok yapısı ve çok çerçeveli iletim.** Çerçeve büyüdükçe hata olasılığı artar, hatanın tespiti ve iletinin tekrarı daha uzun sürer. Çerçeve küçülünce de her çerçevenin başına ve sonuna eklenen alanlar ek yük olur. Bu yüzden ileti daha küçük bloklara ayrılır ve bir çerçevede birden çok blok taşınır. Ekrandaki yapı: `SYN SYN SOH Header STX Veri ITB BCC STX Veri ETX BCC` (Blok1, Blok2) (ekrandan, 00:55:00). Hata olursa çerçevenin tamamı yine yeniden gönderilir. Kazanç iki yönlüdür: ayrı çerçeveler için başlık tekrarlanmaz, daha küçük parçalar ayrı BCC ile kontrol edildiği için hata sezme şansı artar. Veri tek çerçeveye sığmazsa birden fazla çerçeve gönderilir. Ara çerçeveler ETB (End of Transmission Block), sonuncusu ETX ile biter. Stop-and-wait kullanılıyorsa her çerçeveye ACK0 ya da ACK1 içeren kontrol çerçevesiyle cevap verilir. Alındı her zaman beklenen bir sonraki çerçeveyi gösterir. Kontrol çerçevesi `SYN SYN | diğer kontrol bilgileri | BCC` yapısındadır (ekrandan, 01:00:00).

- **BSC.** IBM'in byte yönelimli protokolü BSC 1960'larda kullanıldı. Noktadan noktaya ve çok noktalı bağlantıya uygundur. Yarı çift yönlü (half-duplex) çalışır, akış kontrolünde stop-and-wait kullanır ve kod bağımlıdır: tek byte üzerinden çalıştığı için ASCII ve EBCDIC'te farklı kontrol karakteri değerleri gerekir.

- **Bit yönelimli protokoller ve HDLC'nin özellikleri.** Çerçeve bit dizisi olarak yorumlanır. Belirli bit kalıplarına kontrol anlamı verilir, bu kalıbın veride oluşması bit doldurma ile engellenir. Bit yönelimli protokollerin çoğu ISO'nun standartlaştırdığı HDLC'nin alt kümesidir. Genel özellikleri: noktadan noktaya veya çok noktaya bağlantıya uygundur, hem yarı hem tam çift yönlü çalışır, akış kontrolü ve ARQ için kayan pencere kullanır ve kodlama sisteminden bağımsızdır (ekrandan, 01:20:00).

- **İstasyonlar, yapılanış ve kipler.** Birincil (primary) istasyon hattın kontrolünü ve yönetimini yapar. İkincil (secondary) istasyon birincilin izniyle iletişime katılır. Birleşik istasyon farklı anlarda iki rolü de üstlenebilir. Bir birincile karşı çok sayıda ikincil varsa yapılanış dengesizdir (unbalanced). Noktadan noktaya eşit iki istasyon varsa dengelidir (balanced). Kipler (ekrandan, 01:25:00):
  - NRM (Normal Response Mode): dengesiz yapılanış için. İkincil, birincilin izni olmadan iletemez.
  - ARM (Asynchronous Response Mode): dengesiz yapılanış için. Hat boşken ikincil izinsiz iletebilir. Hattı başlatma, hata kontrolü ve sonlandırma sorumluluğu yine birincildedir. Hoca nadir kullanıldığını söyledi.
  - ABM (Asynchronous Balanced Mode): dengeli yapılanış için. Eşit haklara sahip istasyonlardan herhangi biri istediği an iletime geçebilir.

- **HDLC çerçeveleri.** I çerçevesi (bilgi) kullanıcı verisini ve ona ait kontrol bilgisini taşır. S çerçevesi (gözetim, supervisory) hata ve akış kontrolü için kullanılır. U çerçevesi (numarasız, unnumbered) sistem yönetimiyle ilgili özel amaçlı çerçevedir. Hepsi iki flag arasındadır: I çerçevesi `Flag | Adres | Kontrol | Kullanıcı verisi | FCS | Flag`, S çerçevesi `Flag | Adres | Kontrol | FCS | Flag`, U çerçevesi `Flag | Adres | Kontrol | Yönetim bilgisi | FCS | Flag`. Bu bölümün slaytları kaybolduğu için hoca anlatımı sözlü yaptı.

- **Flag ve bit doldurma.** Flag 8 bittir: `01111110`. Hem çerçevenin başını ve sonunu belirler hem eşzamanlama sağlar. Bu kalıbın çerçeve içinde oluşmaması için gönderici, art arda beş 1 gönderdikten sonra araya bir 0 ekler. Alıcı beş 1'den sonra gelen biti inceler: 0 ise doldurma bitidir ve atılır.

- **Adres alanı.** Adres alanı her zaman ikincil istasyonun adresini taşır. Çerçeveyi birincil gönderdiyse adres hedefi ("to"), ikincil gönderdiyse kaynağı ("from") gösterir. Adres bir ya da daha fazla byte olabilir. Her byte'ın bir biti adresin devam edip etmediğini gösterir, adres için 7 bit kalır.

- **Kontrol alanı.**
  - Çerçeve tipi kontrol alanının ilk bitlerinden anlaşılır: `0` I, `10` S, `11` U.
  - I çerçevesinde alan `0 | N(S) (3 bit) | P/F | N(R) (3 bit)` biçimindedir. N(S) gönderilen, N(R) beklenen çerçevenin sıra numarasıdır. N(R) aynı zamanda alındı (acknowledgement) bilgisidir. Kontrol alanı 2 byte'a çıkarılırsa ilk bit yine 0 olur, kalan 15 bitin 7'si N(S), 7'si N(R), biri P/F olur. $2^7 = 128$ olduğundan pencere 127'ye kadar çıkar.
  - S çerçevesinde alan `10 | kod (2 bit) | P/F | N(R) (3 bit)` biçimindedir. Gönderilen veri olmadığından yalnız N(R) yeterlidir. Kodlar: `00` RR (Receive Ready), `01` REJ (Reject, Go-Back-N), `10` RNR (Receive Not Ready), `11` SREJ (Selective Reject). Gönderilecek veri yoksa ve alındı bildirmek gerekiyorsa piggyback yerine S çerçevesi kullanılır.
  - U çerçevesinde alan `11 | kod (2 bit) | P/F | kod (3 bit)` biçimindedir. 5 bitlik kod $2^5 = 32$ durum verir. Kategoriler: kip ayarlama, numarasız değişim (unnumbered exchange), bağlantıyı sonlandırma, bağlantıyı başlatma ve diğerleri. Örnekler: SNRM `00 001`, SARM `11 000`, DISC `00 010`, RD `00 010`, DM.
  - P/F (poll/final) biti: birincilden ikincile giden çerçevede poll, ikincilden birincile cevapta final anlamındadır. Adres alanında hep ikincilin adresi bulunduğundan yönü P/F belirler.

- **LAP ailesi ve SDLC.** LAPB (Link Access Procedure Balanced) ABM'yi uygular. LAPD (Link Access Procedure on D Channel) ISDN'in bant dışı sinyalleşme için kullanılan D kanalında çalışır. LAPM (Link Access Procedure for Modem) V.42 modem standardında kullanılır. Hepsi HDLC'nin basitleştirilmiş alt kümesidir. SDLC, IBM'in SNA mimarisinde ikinci katmanda, noktadan noktaya ve çok noktalı bağlantılarda kullanılan, hata algılamalı, yarı ve tam çift yönlü çalışabilen protokoldür.

- **Yerel alan ağları.** LAN, sınırlı bir coğrafi alandaki bilgisayarların ortak bir iletim ortamını kullanarak çok noktalı haberleşmesidir. Bugün en yaygın örnekleri kablosuz LAN ve Ethernet'tir. Token bus, token ring, FDDI ve CDDI de vardır. FDDI ve CDDI dışındakiler IEEE 802 ailesini (802.1, 802.2, 802.3, 802.4, 802.5) kullanır. Bilgisayar ağlarının trafiği patlamalıdır (bursty), yani kararlı değil tepeler yapan bir trafiktir. Ortam paylaşımının yolları:
  - Sabit atama: herkese zaman ya da frekans dilimi verilir. Radyo yayını frekans bazlı örnektir. Bilgisayar ağlarında cihaz sayısı sürekli değiştiği ve çoğu cihaz çoğu zaman göndermediği için verimsizdir.
  - Çekişme temelli (contention based): veri olan doğrudan gönderir, çarpışma olursa fark edilir. Taşıyıcı algılama (carrier sense) varsa önce hat dinlenir, yoksa çarpışmadan kaçınma (collision avoidance) denenir. ALOHA, slotted ALOHA ve persistent yöntemler sonraki konulardır.
  - Rezervasyon temelli: çoğunlukla bir token kullanılır (token ring, token bus).
  - Karma: hat kanallara bölünür, bir kısmı çekişme, bir kısmı rezervasyonla kullanılır.

- **IEEE 802 referans modeli.** OSI'nin yedi katmanından (uygulama, sunum, oturum, taşıma, ağ, veri bağı, fiziksel) 802 yalnız alt kısmı tanımlar. Veri bağı katmanı MAC (Medium Access Control) ve LLC (Logical Link Control) diye ikiye bölünür. Üstte ağ katmanına geçişi sağlayan Service Access Point bulunur. Alt tarafta 802.3, 802.4 (token bus) ya da 802.5 (token ring) kullanılsa da LLC standarttır. MAC, fiziksel katmanla LLC arasındaki geçişi tek biçimli hâle getirir.

<!-- BELİRSİZ: Hoca U çerçevesinde DM kodunu "1100" diye söyledi, altyazı eksik olabilir; standartta DM büyük olasılıkla 11 000'dır. Slayt kaybolduğu için kareden doğrulanamadı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
