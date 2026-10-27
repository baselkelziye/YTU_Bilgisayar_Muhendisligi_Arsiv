# Ders 14 Çalışma Özeti

## Genel Konular

- Ders 29 Kasım 2021 Pazartesi günü online yapıldı. Kayıt yaklaşık 2 saat.
- Bu dersten itibaren dersi Dr. Furkan Çakmak anlatıyor. Vize haftasına kadar grubu Dr. Ziya Cihan Tayşi yürütmüştü.
- Kısa tekrar: OSI modeli, fiziksel katman ve veri bağlantı katmanı. Bu ve sonraki haftalarda hâlâ veri bağlantı katmanında kalınacak.
- Veri bağlantı denetim protokolleri (data link control protocols):
  - asenkron protokoller,
  - senkron protokoller: bayt yönelimli (byte/character-oriented) ve bit yönelimli (bit-oriented).
- Bayt yönelimli protokoller:
  - ASCII denetim karakterleri (SYN, STX, ETX, ETB, ITB, SOH, DLE, ENQ, ACK0/ACK1, NAK, EOT, NULL vb.),
  - veri çerçevesi ve denetim çerçevesi yapısı,
  - veri saydamlığı (data transparency) ve DLE ile kaçış,
  - IBM'in BSC (Binary Synchronous Communication) protokolü.
- Bit yönelimli protokoller ve HDLC (High-Level Data Link Control):
  - istasyon tipleri, yapılandırmalar ve üç çalışma modu (NRM, ARM, ABM),
  - çerçeve yapısı: bayrak, adres, denetim, bilgi, FCS,
  - I-frame, S-frame, U-frame,
  - P/F (poll/final) biti,
  - bağlantı kurma, veri aktarma ve bağlantıyı kesme örnekleri.
- Vize sonuçlarına dair kısa değerlendirme.

## Hocanın Özellikle Vurguladığı Kısımlar

- Senkron protokoller bugün de kullanılıyor. Hoca, şu an derste ses ve görüntünün de büyük olasılıkla senkron ve bit yönelimli bir protokolle geldiğini söylüyor.
- Asenkron iletimde her bayta başlangıç ve bitiş bitleri eklenir. Bu ek yük yüksektir ve çerçeveler arasında boşluklar oluşur. Bu yüzden asenkron iletim senkron iletime göre yavaştır.
- Senkron iletimde başlangıç ve bitiş birer bit ile değil, özel bayraklarla (flag) belirtilir. 1000–1500 baytlık bir çerçeve için yalnız birkaç denetim baytı eklenir. Ek yük çok daha düşüktür.
- Cihazların saatleri zamanla kayar. Fiziksel katmanda ortak saat işareti (common clock signal), mantıksal seviyede de bayraklar senkronizasyonu sağlar.
- **Veri saydamlığı** önemli bir kavramdır ve farklı derslerde karşınıza çıkacaktır. Gri tonlu bir resim gibi ikili verinin içinde bir bayt tesadüfen bir denetim karakteriyle (ör. ETX) aynı olabilir. Bu durum DLE kaçış karakteriyle çözülür.
- Noktadan noktaya hatta adres gerekmez; yalnız iki taraf vardır. Çok noktalı hatta hem alıcının hem göndericinin adresi gerekir. Hoca vizede bu soruda çok hata yapıldığını söylüyor.
- Bit yönelimli protokoller daha verimli çerçeveleme yaptıkları için daha yaygındır. Karakter tabanlı olmadıkları için veri saydamlığı sorunu neredeyse yoktur.
- HDLC bir ISO standardıdır. Sonraki birçok protokol onu temel alır.
- Kayan pencere boyutu hattın kapasitesine, mesafesine ve hata oranına göre seçilir. Hata oranı yüksekse pencereyi küçültmek daha uygun olabilir.
- U-frame bit dizilerini ezberlemeyin. Hoca "bu bit dizisi ne anlama gelir" diye sormayacaklarını, yalnız hangi tür işlerin yapıldığını bilmenizi istediklerini söylüyor.
- Piggybacking (sırtlama): ACK bilgisini veri çerçevesinin (I-frame) içine yerleştirmektir. Gönderecek verisi olmayan taraf ACK'yı S-frame ile yollar.

## Kısa Tekrar Notları

- **Asenkron iletim:** Her bayt başlangıç ve bitiş biti ile çerçevelenir. Yüksek ek yük, düşük hız. Eski modemlerde kullanılırdı.
- **Senkron iletim:** Çerçevenin başı ve sonu bayraklarla belirlenir. Düşük ek yük.
- **Bayt yönelimli = karakter yönelimli:** Denetim bilgisi ASCII denetim karakterleriyle verilir.
- **Temel karakterler:**
  - SYN: senkronizasyon, her çerçeve SYN SYN ile başlar,
  - SOH: başlık (header) başlangıcı,
  - STX / ETX: metin başlangıcı / sonu,
  - ITB / ETB: ara blok sonu / blok sonu,
  - DLE: veri bağlantı kaçışı (escape),
  - ENQ: sorgu,
  - ACK0 / ACK1: dönüşümlü onay,
  - NAK: olumsuz onay,
  - EOT: iletimin sonu,
  - NULL: dolgu.
- **BCC (Block Check Count):** LRC ise 1 bayt, CRC ise 2 bayt.
- **Veri saydamlığı:** Veri içindeki denetim karakterine benzeyen baytların önüne DLE eklenir. Veri içinde DLE varsa o da ikilenir (DLE DLE).
- **BSC:** IBM, 1960'ların sonu. Noktadan noktaya ve çok noktalı. Yarı çift yönlü (half-duplex). Dur ve bekle akış denetimi, dur ve bekle ARQ. Kod bağımlı.
- **HDLC:** ISO standardı. Noktadan noktaya ve çok noktalı. Yarı ve tam çift yönlü (full-duplex). Kayan pencere. Kod bağımsız.
- **İstasyon tipleri:** Birincil (primary), ikincil (secondary), birleşik (combined).
- **Modlar:**
  - NRM (Normal Response Mode): dengesiz; ikincil yalnız birincil izin verince gönderir,
  - ARM (Asynchronous Response Mode): dengesiz; ikincil izin beklemeden gönderebilir,
  - ABM (Asynchronous Balanced Mode): dengeli; tüm istasyonlar birleşik tiptedir.
- **HDLC bayrağı:** `01111110`.
- **Denetim alanının ilk bitleri:** `0` → I-frame, `10` → S-frame, `11` → U-frame.
- **S-frame kodları:** `00` RR, `01` REJ, `10` RNR, `11` SREJ.
- **P/F biti:** Birincilden ikincile giderken P (poll), ikincilden birincile giderken F (final).
- **Pencere:** Denetim alanı 1 bayt ise numaralar 3 bit (pencere en çok 7); 2 bayt ise 7 bit (pencere en çok 127).

## Detaylı Açıklamalar

### Asenkron ve Senkron Protokoller

Asenkron hatta veri belli periyotlarla gelmez. Gönderici istediği zaman gönderir ve alıcı baytın başını ve sonunu başlangıç/bitiş bitlerinden anlar. Hatta farklı uzunlukta boşluklar oluşur ve hat kullanım oranı düşer.

Senkron hatta gönderici çerçevenin nerede başlayıp bittiğini bayraklarla söyler. Çerçeve kaybolursa veya bozulursa zaman aşımı mekanizmaları devreye girer ve çerçeve yeniden gönderilir.

### Bayt Yönelimli Çerçeveler

**Basit veri çerçevesi:**

```
SYN SYN STX [veri] ETX BCC
```

**Başlıklı veri çerçevesi:**

```
SYN SYN SOH [başlık] STX [veri] ETX BCC
```

**Ara bloklu çerçeve:** Uzun bir veri üzerinde CRC hesaplamak, özellikle donanım kısıtlıysa, zaman alır. Bu yüzden veri ara bloklara bölünür ve her bloğun ayrı denetim baytı olur.

```
SYN SYN SOH [başlık] STX [blok 1] ITB BCC STX [blok 2] ETB BCC
```

Çerçeve ETB ile bitiyorsa gönderici daha veri gönderecektir. ETX ile bitiyorsa metin bitmiştir.

**ACK0/ACK1:** BSC dur ve bekle kullandığı için iki onay karakteri yeterlidir. Alıcı 0 numaralı çerçeveyi alınca ACK1 ("1'i bekliyorum"), 1'i alınca ACK0 gönderir. Bu, iki çerçevelik bir pencere gibi çalışır.

**Denetim çerçevesi:**

```
SYN SYN [denetim karakterleri] BCC
```

### Veri Saydamlığı

Bu protokoller ilk geliştirildiğinde yalnız metin gönderiliyordu. Denetim karakterleri metinde geçmeyen, yazdırılamayan (unprintable) ASCII karakterlerinden seçilmişti.

Ses, görüntü veya gri tonlu resim gibi ikili veri gönderilince veri içindeki bir bayt tesadüfen bir denetim karakteriyle aynı olabilir. Alıcı bunu yanlışlıkla çerçeve sonu sanabilir.

Çözüm:

- Denetim anlamı taşıyan STX, ETX, ETB, ITB, SOH karakterlerinin önüne DLE konur. Alıcı, önünde DLE olanı denetim karakteri, olmayanı veri sayar.
- Veri içinde DLE ve ardından denetim karakteri geçiyorsa gönderici veriyi bayt bayt tarar ve önüne bir DLE daha ekler. Alıcı ilk DLE'yi atar ve kalanı veri olarak alır.

### HDLC

HDLC, bit yönelimli protokollerin en yaygınıdır. Kod bağımsızdır; yani karakter tablosuna bağlı değildir. Üzerine kurulmuş birçok bağlantı erişim prosedürü (LAP) vardır.

**Yapılandırmalar:**

- **Dengesiz (unbalanced):** Bir birincil ve bir veya daha çok ikincil. Yetki birincildedir.
- **Dengeli (balanced):** İki birleşik istasyon. Her iki taraf hem komut hem cevap gönderebilir.

**Modlar:**

- **NRM:** Poll/select düzeni. Birincil "gönderecek bir şeyin var mı?" (poll) veya "sana veri göndereceğim" (select) der. İkincil yalnız izin aldığında gönderir.
- **ARM:** İkincil, hat boşsa birincilin iznini beklemeden iletime başlayabilir. Hat yönetimi yine birincildedir.
- **ABM:** Tüm istasyonlar birleşik tiptedir ve eşit yetkiye sahiptir.

**Çerçeve tipleri:**

- **I-frame (information):** Kullanıcı verisini taşır. Piggybacking ile ACK da taşıyabilir.
- **S-frame (supervisory):** Akış ve hata denetimi içindir (onay, ret, hazır/hazır değil). Veri alanı yoktur.
- **U-frame (unnumbered):** Bağlantı yönetimi içindir (mod seçme, bağlantı kurma/kesme, sıfırlama vb.). Beş kod biti ile $2^5 = 32$ farklı komut/cevap tanımlanabilir.

**Çerçeve alanları:**

```
Bayrak | Adres | Denetim | Bilgi | FCS | Bayrak
```

**Bayrak alanı:** Sabit dizi `01111110`. Çerçevenin başını ve sonunu belirtir.

Veri içinde aynı dizinin oluşmasını engellemek için bit doldurma (bit stuffing) kullanılır:

- Gönderici, veride art arda beş tane 1 gördüğünde araya bir 0 ekler.
- Alıcı, beş tane 1'den sonra gelen 0'ı atar.
- Altı tane 1 ve ardından 0 gelirse bu bayraktır.

**Adres alanı:** İkincil istasyonun adresini taşır.

- Tek baytlık adreste 7 bit adres kullanılır. Son bit 1 ise adres o baytta biter. Böylece $2^7 = 128$ adres tanımlanabilir.
- Adres birden çok bayta yayılabilir. Ara baytların son biti 0, son baytın son biti 1 olur. İki baytta $2^{14}$ adres elde edilir.

**Denetim alanı:** Çerçevenin tipini ve akış denetim bilgisini taşır. Pencere en çok 7 ise 1 bayt, en çok 127 ise 2 bayttır. Gecikmesi yüksek WAN hatlarında 127'lik pencere mantıklıdır.

**I-frame denetim alanı (1 bayt):**

```
0 | N(S) 3 bit | P/F | N(R) 3 bit
```

- N(S): Gönderilen çerçevenin sıra numarası.
- N(R): Alıcının beklediği bir sonraki çerçevenin numarası; yani piggyback onayı.

**S-frame denetim alanı:**

```
1 0 | kod 2 bit | P/F | N(R) 3 bit
```

| Kod | Ad | Anlam |
|---|---|---|
| 00 | RR (Receive Ready) | N(R)'ye kadar alındı, devam et |
| 01 | REJ (Reject) | N(R)'den itibaren hepsini yeniden gönder (Go-Back-N) |
| 10 | RNR (Receive Not Ready) | N(R)'ye kadar alındı ama şu an hazır değilim |
| 11 | SREJ (Selective Reject) | Yalnız N(R) numaralı çerçeveyi yeniden gönder |

**P/F ile kullanımlar:**

- Birincil RR ve P=1 gönderirse: "Bana gönderecek bir şeyin var mı?" (poll).
- Birincil RNR ve P=1 gönderirse: "Sana veri göndereceğim, uygun musun?" (select).
- İkincil RR ve F=1 ile cevap verirse kabul eder, RNR ve F=1 ile cevap verirse reddeder.
- İkincilin gönderdiği I-frame'lerde F=0 "devamı var", F=1 "bu son parça" demektir.

Bir cevabın poll'a mı select'e mi ait olduğu bit dizisinden anlaşılmaz. Birincil kendi sorduğu soruyu bildiği için cevabı doğru yorumlar.

**U-frame:** Komutlar beş grupta toplanır: mod seçme, bilgi değişimi (ör. zaman ayarı), bağlantı kesme, başlatma (initialization) ve diğer işler. Örnekler:

- SNRM: normal response modunu başlat (pencere 7); SNRME 127'lik sürümüdür.
- SABM: asenkron dengeli modu başlat; SABME 127'lik sürümüdür.
- UA (Unnumbered Acknowledgement): U-frame komutunun onayı.
- DISC: bağlantıyı kes.
- RSET: sıfırla.

Aynı bit dizisi, birincilden gelince komut, ikincilden gelince cevap anlamı taşıyabilir. Örneğin bağlantı kesme için DISC (komut) ile RD (Request Disconnect, cevap) aynı kodu kullanır. Bir öğrenci tablodaki iki satırın kodlarının aynı olduğunu fark etti. Hoca önce yanlışlık olduğunu düşündü, sonra öğrencinin açıklamasının doğru olduğunu kabul etti.

### HDLC İşleyiş Örnekleri

**Üç evre:** Bağlantı kurma, veri aktarma, bağlantıyı kesme.

**Bağlantı kurma ve kesme:**

1. A, B'ye mod belirten bir U-frame (ör. SABM) gönderir, P=1.
2. B, UA ile ve F=1 olarak cevap verir.
3. Veri aktarımı I, S ve U çerçeveleriyle yürür.
4. A, DISC gönderir. B, UA ile onaylar.

**Piggybacking ile çift yönlü aktarım:**

- A: I-frame, N(S)=0, N(R)=0 ("0'ı yolluyorum, senden 0'ı bekliyorum").
- B: I-frame, N(S)=0, N(R)=1 ("0'ı yolluyorum, senin 0'ını aldım, 1'i bekliyorum").
- A: I-frame, N(S)=1, N(R)=1.
- A: I-frame, N(S)=2, N(R)=1.
- B: I-frame, N(S)=1, N(R)=3 (1'i ve 2'yi tek onayla kabul eder).
- A'nın gönderecek verisi kalmadığı için onayı S-frame ile verir: RR, N(R)=2.

**Alıcının hazır olmaması:** A, 3 numaralı çerçeveyi gönderir. B "3'ü aldım ama hazır değilim" der (RNR 4). A birkaç kez RR, P=1 ile durumu sorar. B hazır olunca RR 4 gönderir ve A 4'ü yollar. Hazır olmamanın nedeni tamponun dolu olması veya istasyonun daha öncelikli bir işle meşgul olması olabilir.

**Kaybolan çerçeve (REJ):** A, 3, 4 ve 5'i gönderir. 4 yolda kaybolur. B, 3'ten sonra 5'i görünce 4'ün eksik olduğunu anlar ve REJ 4 gönderir. 5'in içeriğine hiç bakmaz. A, 4'ten itibaren hepsini yeniden gönderir. SREJ kullanılsaydı yalnız 4 yeniden gönderilirdi.

**Çok noktalı hat (poll):** Birincil, A istasyonuna RR, P=1 ile poll yapar. A'nın verisi vardır ve I-frame'lerle gönderir. Son parçada F=1 olur. Birincil "2'ye kadar hepsini aldım" diye onaylar.

Bir öğrenci, A'nın gönderdiği çerçevede adres alanına neden A yazıldığını sordu. Hoca cevap verdi: Birincil zaten bellidir. Adres alanı her zaman ikincilin adresini taşır; böylece birincil mesajın hangi ikincilden geldiğini anlar. A, B'ye veri göndermek isterse bunu birincil üzerinden yapar.

### Duyurular

- Furkan Hoca'nın odası D122'dir (bölüm sekreterliğinin bulunduğu birinci kat). Görüşmek için e-posta ile randevu alınabilir.
- Hoca soruların sohbet kutusuna yazılmasını değil, sesli sorulmasını istiyor.
- Vize ortalaması 42. Hoca dersi 200'den fazla öğrencinin aldığını ve bu gidişle yarısının kalabileceğini söyledi. Online grubun notları henüz ilan edilmemişti; Cihan Hoca'nın en kısa zamanda ilan etmesi bekleniyor.
- Gelecek hafta LAN teknolojileri ve IEEE 802 projesi anlatılacak.

### Ders sonrası notlar

- **Asenkron ek yük:** Hoca asenkron iletimde genellikle iki başlangıç ve bir bitiş biti olduğunu, ek yükün %30–40 olduğunu söylüyor. Yaygın düzen (ör. 8N1) bir başlangıç ve bir bitiş bitidir. 8 veri biti için ek yük $2/10 = \%20$ olur. Eşlik biti ve iki bitiş biti eklense bile oran yaklaşık %27'dir.
- **Artık yıl:** Hoca günlerin tam 24 saat olmadığını ve bu farkın birikip dört yılda bir artık güne dönüştüğünü söylüyor. Artık yılın nedeni günün uzunluğu değil, yılın yaklaşık 365,2422 gün olmasıdır. Dünyanın dönüşündeki düzensizlik ise artık saniye (leap second) ile düzeltilir.
- **ETB'nin anlamı:** Hoca ETB'yi "transmission'ın bittiği" diye açıklıyor. ETB "End of Transmission Block", yani blok sonudur. İletimin tamamen bittiğini EOT bildirir.
- **N(S) ve N(R):** Hoca bir yerde ACK'nın N(S) alanına yazıldığını söylüyor. Onay (piggyback ACK) N(R) alanında taşınır. N(S), gönderilen çerçevenin kendi numarasıdır.
- **Denetim alanı bitleri:** Hoca bir anda "ilk biti 1, ikinci biti 0 ise I-frame" diyor, sonra düzeltiyor. Doğrusu: ilk bit 0 ise I-frame, `10` ise S-frame, `11` ise U-frame.
- **S-frame kodları:** Hoca poll'u anlatırken bir yerde RR'yi "0-1", RNR'yi "1-0" diye söylüyor. Kodlar RR=`00`, REJ=`01`, RNR=`10`, SREJ=`11`'dir.
- **Bit doldurma:** Hoca alıcı tarafındaki kuralı "beş birden sonra gelen bir ise sıfırları say; 15'ten azsa veridir, fazlaysa hat boştur" diye anlatıyor. Doğrusu:
  - Gönderici, beş tane 1'den sonra bir 0 ekler.
  - Alıcı, beş tane 1'den sonra 0 görürse o 0'ı atar.
  - `01111110` bayraktır.
  - Art arda 7–14 tane 1 iptal (abort) anlamına gelir.
  - 15 veya daha fazla art arda 1 hattın boşta (idle) olduğunu gösterir.
- **Adres alanı:** Hoca HDLC adres alanının ağ katmanı adresi olduğunu söylüyor. Bu doğru değil. HDLC adresi veri bağlantı katmanında ikincil istasyonu belirten yerel bir adrestir; IP gibi ağ katmanı adresi değildir. Ayrıca hocanın "7 bayt" ve "14 bayt" dediği değerler 7 ve 14 bittir.
- **ABM'nin tanımlı olmaması:** Hoca dengeli yapılandırmanın HDLC'nin temel sürümünde tanımlı olmadığını söylüyor. ABM, HDLC'nin standart üç modundan biridir. LAPB gibi yaygın protokoller doğrudan ABM kullanır.
- **ARM'de ikinciller:** Hoca ARM'de ikincillerin birincilden onay almadan kendi aralarında konuşabildiğini söylüyor. ARM'de ikincil izin beklemeden iletim başlatabilir ama yine yalnız birincille haberleşir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
