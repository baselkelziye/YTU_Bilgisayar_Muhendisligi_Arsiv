# Ders 6 Çalışma Özeti

## Genel Konular

- 8255 PPI Mod 1 Handshaking Tekrarı ve Kontrol Sözcüğü
  - 8255 entegresinin Mod 1 çalışma modunda Port A ve Port B arasında handshaking (el sıkışma) tabanlı iletişim kurulur. Bu modda Strobe, IBF (Input Buffer Full), OBF (Output Buffer Full) gibi kontrol sinyalleri Port C pinleri üzerinden yönetilir.
  - Kontrol sözcüğünün (control word) 7. bitinin 1 olması mod selection modunda çalışıldığını gösterir. D4 biti Port A'nın input/output yönünü, D1 biti Port B'nin yönünü belirler. D3 ve D0 bitleri Port C'nin upper ve lower pinlerinin yönünü ayarlar ancak Mod 1'de bu pinlerin çoğu handshaking sinyalleri için rezerve edildiğinden serbestçe kullanılamaz.

- Mod 1'de Port C Pinlerinin Rezerve Edilmesi
  - Port A input olarak kullanıldığında handshaking sinyalleri Port C'nin 6. ve 7. pinlerini kullanır; bu pinler sadece serbest bırakılabilir. Port A output olduğunda ise 4. ve 5. pinler rezerve edilir.
  - Port B için ise Port C'nin alt bitleri (0, 1, 2) kullanılır ve bu pinler her iki Port B yönü durumunda da handshaking için rezerve edilmiştir.

- INT A ve INT B: Interrupt Enable Mekanizması
  - Handshaking iletişiminin tamamlanması sonucunda interrupt üretilebilmesi için INT A (Port A için) ve INT B (Port B için) bayraklarının set edilmesi gerekir.
  - Bu bayraklar Bit Set Reset modülü ile Port C üzerinden set edilir: Port A input ise C6 pinini set etmek, Port A output ise C4 pinini set etmek gerekir. Port B output ise C2 pinini set etmek gerekir.
  - Interrupt enable edilmezse, handshaking sinyalleri doğru çalışsa bile interrupt oluşmaz ve CPU veri transferinden haberdar edilmez.

- Bit Set Reset (BSR) Modülü
  - BSR modü, kontrol sözcüğünün en anlamlı biti 0 olduğunda aktif olur. Bu modda sadece Port C pinleri tek tek set veya reset edilebilir.
  - Format: X (önemsiz), Port C pin numarası (3 bit), ve set/reset değeri (1 bit). Örneğin C6'yı set etmek için ilgili kontrol sözcüğü hesaplanır ve kontrol portuna gönderilir.

- Proteus Üzerinden Mod 1 Örneği Analizi
  - Verilen devrede 8255 entegresinin adres çözümü yapılır: A9-A3 pinlerinden çip seçimi için 001 değeri üretilir, A1-A0 pinleri port seçimi (00=Port A, 10=Port B, 01=Port C, 11=Kontrol) için kullanılır.
  - Kontrol portu adresi 206h olarak belirlenir. Soru işareti ile belirtilen pinler (A8, A7, A0) sıfır alındığında adres 0206h olur.
  - Kod akışı: İlk olarak BSR modunda C6 set edilir (Port A interrupt enable), ardından C2 set edilir (Port B interrupt enable). Sonra mod selection ile Port A Mod 1 input, Port B Mod 1 output yapılır.
  - Port C'den status word okunarak interrupt kontrolü yapılır. 08h ile AND'lenerek Port A interrupt'ı test edilir. Interrupt gelmişse Port A'dan veri okunur, geçici olarak B register'ına kaydedilir. Ardından Port C'den tekrar status okunarak Port B'nin hazır olup olmadığı kontrol edilir (01h ile AND). Hazırsa Port B'ye veri yazılır.

- Seri Haberleşmeye Giriş ve Temel Kavramlar
  - Bilgisayar mimarilerinde veri iletişimi iki şekilde yapılır: paralel ve seri. Paralel iletişim aynı anda birden fazla veri hattı üzerinden toplu veri gönderir; seri iletişim ise veriyi bit bit peş peşe gönderir.
  - Paralel iletişim kısa mesafelerde hızlıdır ancak maliyetlidir (çok hat gerektirir). Seri iletişim daha yavaştır ancak maliyeti düşüktür ve uzun mesafelere veri taşıyabilir.
  - Seri iletişim kendi içinde senkron ve asenkron olarak ikiye ayrılır.

- Senkron ve Asenkron Seri İletişim
  - Senkron iletişimde verici ve alıcı taraf ortak bir clock palsi ile senkronize olur. Sürekli iletim vardır, veri blokları (block) halinde gönderilebilir. Daha maliyetlidir ancak veri kaybı açısından daha güvenilirdir. Sender ve receiver aynı boyutta data paketleri işlemek zorundadır; aksi halde buffer taşması yaşanır.
  - Asenkron iletişimde ortak clock palsi yoktur. Verinin başına start biti (lojik 0), sonuna stop biti (lojik 1) eklenerek verinin nerede başlayıp bittiği belirlenir. Daha esnektir, aralarda boşluklar olabilir. Ancak hata oranı senkrona göre daha yüksektir.

- Baud Rate ve Karakter Rate
  - Baud rate (bps), saniyede transfer edilen bit sayısıdır. Örneğin 1200 bps, saniyede 1200 bitin konum değiştirdiği anlamına gelir. Bir bitin transfer süresi = 1/baud rate formülüyle hesaplanır.
  - Karakter rate, saniyede transfer edilen paket (karakter) sayısıdır. Bir paket start + data + parity + stop bitlerinden oluşur. Toplam paket boyutu hesaplanarak baud rate'ten karakter rate türetilebilir.
  - Örnek: 1 start + 7 data + 1 parity + 1 stop = 10 bitlik paket. 9600 bps hızla 1 milyon byte göndermek = 10.000.000 / 9600 ≈ 1042 saniye ≈ 17 dakika 22 saniye.

- Parity Kontrolü
  - Parity biti, seri iletişimde veri hatası kontrolü için kullanılan en basit mekanizmadır.
  - Even (çift) parity'de, parity biti dahil toplam 1 sayısı çift olacak şekilde ayarlanır. Odd (tek) parity'de toplam 1 sayısı tek olacak şekilde ayarlanır.
  - Parity biti yalnızca tek bitlik hataları tespit edebilir; çift bitlik hatalarda hata gözden kaçabilir.
  - Checksum ve CRC daha gelişmiş hata kontrol teknikleridir; CRC polinom tabanlı bir yaklaşımla çalışır.

- Yazılımsal Seri İletişim Algoritması
  - Yazılımsal olarak seri veri göndermek için: Veri akümülatöre (AL) yüklenir, start biti gönderilir (CLC ile carry temizlenir, RCL ile rotate), her adımda bir bit shift edilip ilgili porta yazılır, bit zamanı kadar beklenir (delay prosedürü), tüm bitler gönderilene kadar döngü devam eder.
  - Alma tarafında: Port okunur, start biti tespit edilir (lojik 0'a düşüş), bir süre low'da kalması beklenir (gürültü filtreleme), sonra counter set edilip bit bit okuma yapılır, register'a yazılır, parity kontrolü yapılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- INT A ve INT B'nin Mutlaka Enable Edilmesi Gerektiği
  - Handshaking iletişimde interrupt'ın oluşabilmesi için hem handshaking sinyallerinin doğru bağlanması hem de ilgili interrupt bayrağının BSR modülü ile set edilmesi şarttır. Bu iki koşuldan biri eksikse interrupt üretilmez.

- Adres Çözümünde "Soru İşareti" Olan Pinlerin Durumu
  - Proteus örneğinde A8, A7 ve A0 pinleri belirsiz (soru işareti) bırakılmıştır. Bunlar sıfır alındığında kontrol portu 0206h olur. Ancak soruda "200'den başlayan adresleme bloğuna yerleştirilsin" deniyorsa, bu pinlerin hepsi spesifik olarak tanımlanmalıdır; aksi halde birden fazla adres aynı entegreyi tetikleyebilir.

- Read/Write Sinyalleri ile Interrupt Sıfırlama İlişkisi
  - Mod 1'de read sinyali geldiğinde interrupt B, write sinyali geldiğinde interrupt A otomatik olarak sıfırlanır. Bu mekanizma, handshaking döngüsünün doğru çalışmasını sağlar.

- Parity'nin Yalnızca Tek Bit Hatasını Bulabildiği
  - Parity kontrolü basit bir mekanizmadır ve yalnızca tek bitlik bozuntuları yakalayabilir. Çift bitlik hatalarda parity doğru görünebilir; bu durumda checksum veya CRC gibi daha güçlü teknikler gerekir.

## Kısa Tekrar Notları

- 8255 Mod 1'de Port A input ise handshaking pinleri PC6-PC7, output ise PC4-PC5'tir.
- Port B handshaking pinleri her durumda PC0-PC2'dir.
- INT A enable için: Port A input ise PC6 set, output ise PC4 set gerekir.
- INT B enable için: Port B output ise PC2 set gerekir.
- BSR modü sadece Port C pinlerini set/reset eder; kontrol sözcüğünün D7=0 olmalıdır.
- Status word Port C'den okunur; 08h ile AND → Port A interrupt kontrolü, 01h ile AND → Port B interrupt kontrolü.
- Read sinyali INT B'yi, write sinyali INT A'yı sıfırlar.
- Seri iletişim: veriyi bit bit gönderme/alma; paralel iletişim: aynı anda 8 bit.
- Senkron: ortak clock palsi, sürekli iletim, blok veri. Asenkron: start/stop bitleri, aralarda boşluk.
- Baud rate = saniyedeki bit değişim sayısı (bps). Karakter rate = saniyedeki paket sayısı.
- Even parity: toplam 1 sayısı çift olacak şekilde parity biti ayarlanır. Odd parity: tek olacak şekilde.
- Parity yalnızca tek bit hatasını bulur.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**8255 Mod 1 Handshaking Mekanizması:**
Mod 1, 8255 entegresinin karşılıklı iletişim (handshaking) tabanlı çalışma modudur. Bu modda Port A ve Port B'den biri veri alışverişi yaparken, Port C'nin belirli pinleri kontrol sinyalleri için kullanılır. Handshaking, verici tarafın "hazırım" (strobe) sinyali göndermesi ve alıcı tarafın "aldım, yenisini gönder" (IBF/Acknowledge) sinyali döndürmesi prensibine dayanır. Bu sayede veri kaybı önlenir çünkü her veri transferi karşılıklı onay ile gerçekleşir.

Port A input olarak Mod 1'de kullanıldığında, PC4 (ACKA), PC5 (STBA) ve PC6 (IBFA) handshaking sinyalleri için rezerve edilir. PC6 ve PC7 serbest kalır. Port A output olduğunda ise PC6 (ACKA), PC7 (OBFA), PC4 (INTR A) rezerve edilir ve PC5 ile PC7 serbest kalır. Port B için ise PC0 (INTRB), PC1 (OBF), PC2 (ACKB) input/output durumuna göre rezerve edilir.

**Interrupt Enable Süreci:**
Handshaking tamamlandığında CPU'ya interrupt gönderilebilmesi için INT A veya INT B bayraklarının aktif olması gerekir. Bu bayraklar BSR modülü ile set edilir. BSR modülüne girmek için kontrol sözcüğünün en anlamlı biti (D7) 0 olmalıdır. Sonraki 3 bit (D6-D4) hangi Port C pinine işlem yapılacağını belirler (000=PC0, 001=PC1, ..., 110=PC6, 111=PC7). Son bit (D0) ise set (1) veya reset (0) işlemini belirler. Örneğin Port A input için INT A enable: D7=0, D6-D4=110 (PC6), D0=1 → kontrol sözcüğü = 0000 1101 = 0Dh.

**Proteus Örneğinin Adım Adım Çözümü:**
Verilen devrede 8255 entegresinin adres çözümü yapılır. Çip seçimi için A9-A3 pinlerinden 001 değeri üretilmelidir (active low chip select). A1 ve A2 port seçimi için kullanılır: 00=Port A, 10=Port B, 01=Port C, 11=Kontrol portu. A0 ve A8 belirsiz bırakılmıştır; sıfır alındığında kontrol portu adresi 0206h olur.

Kod akışında ilk adım interrupt'ları enable etmektir: BSR modunda önce C6 set edilir (Port A input interrupt enable), sonra C2 set edilir (Port B output interrupt enable). Ardından mod selection kontrol sözcüğü gönderilir: Port A Mod 1 input, Port B Mod 1 output. Bu sözcük 0B1h'dir (D7=1, D6-D5=01 Mod 1, D4=0 input, D3=1, D2-D1=01 Mod 1, D0=1 output).

Ana döngüde Port C'den status word okunur. AL = IN 204h (Port C). AL AND 08h → Port A interrupt kontrolü. Sonuç sıfır değilse interrupt gelmiştir, Port A'dan veri okunur (AL = IN 200h), BL register'ına kaydedilir. Sonra tekrar Port C okunur, AL AND 01h → Port B interrupt kontrolü. Sonuç sıfır değilse Port B hazırdır, BL'deki veri Port B'ye yazılır (OUT 202h, AL).

**Seri Haberleşme Temelleri:**
Seri iletişimde veriler tek bir hat üzerinden bit bit gönderilir. Mikro işlemci tarafında IN/OUT komutları 8 bitlik paralel veri ile çalışır; bu verinin seri hatta dönüştürülmesi gerekir. Yazılımsal çözümde bu dönüşüm program tarafından rotate/shift işlemleriyle yapılır. Donanımsal çözümde ise 8251 gibi USART entegreleri bu dönüşümü otomatik gerçekleştirir.

Senkron iletişimde verici ve alıcı aynı clock palsi ile çalışır; veri blokları halinde sürekli akar. Asenkron iletişimde her karakterin başına start biti (lojik 0) ve sonuna stop biti (lojik 1) eklenir. Hat boşken lojik 1 seviyesindedir; start biti ile iletişim başlar, stop biti ile biter. Alıcı taraf start bitini algıladığında bit zamanı kadar bekleyip veri bitlerini örnekler.

**Baud Rate Hesaplamaları:**
Baud rate, saniyedeki bit değişim sayısıdır (bps). Bir bitin transfer süresi = 1/baud_rate saniyedir. Örnek: 3.33 ms/bit → baud rate = 1/0.00333 ≈ 300 bps. Bir karakterin toplam boyutu (start + data + parity + stop) hesaplanarak karakter rate bulunur: 11 bitlik paket ve 300 bps → karakter süresi = 11 × 3.33 = 36.63 ms → karakter rate = 1/0.03663 ≈ 27.3 cps.

**Parity Kontrol Mekanizması:**
Parity biti, veri bitlerinin içerisindeki 1 sayısını even veya odd kurala göre tamamlayan bir ekk bitidir. Gönderici taraf parity bitini hesaplayıp pakete ekler. Alıcı taraf aynı kuralı uygulayarak gelen veriyi kontrol eder; kural bozulmuşsa hata var demektir. Bu yöntem sadece tek bitlik hataları yakalar; iki bit birden bozulursa parity değişmez ve hata fark edilmez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
