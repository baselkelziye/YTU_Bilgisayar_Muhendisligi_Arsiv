# Ders 19 Çalışma Özeti

## Genel Konular

- Paralel ve seri veri iletimi (ekrandan, 00:15:00)
  - Paralel iletimde birden fazla bit aynı anda ayrı tellerden (ya da kanallardan) gönderilir. 8 ya da 16 bit bir seferde aktarılır; eski IDE disk kabloları ve anakart üzerindeki yollar örnek olarak verildi.
  - Seri iletimde veri bit bit gönderilir. Gönderici taraf yazmaçtaki paralel veriyi serileştirir (en düşük anlamlı bitten başlayarak), alıcı taraf gelen bitleri biriktirip yeniden bayta çevirir.
  - Paralel iletim kısa mesafede hızlıdır ama tel sayısı arttıkça maliyet yükselir, uzun mesafede veri kaybı riski artar ve bunu tespit etmek zorlaşır. Seri iletim az telle (düşük maliyetle) uzun mesafede çalışabilir; dezavantajı yavaş olmasıdır.
- Senkron ve asenkron seri iletişim (ekrandan, 00:20:00)
  - Senkron iletişimde iki terminal ortak bir saat işareti kullanır. Zaman kayması riski çok düşük olduğu için büyük veri blokları gönderilebilir; blokların başı ve sonu birer bit dizisiyle (senkron karakterleriyle) işaretlenir. Slayta göre daha verimlidir (daha az ek yük) ama pahalıdır.
  - Asenkron iletişimde her terminalin kendi saati vardır. Saatler arasındaki küçük frekans ve faz farkları uzun veride bit kaybına yol açabileceği için veri küçük parçalar (yaklaşık bir bayt) halinde gönderilir. Başlangıç ve bitiş birer start ve 1, 1,5 ya da 2 stop biti ile işaretlenir.
  - Asenkron bağlantı 3 tel ister (gönderme, alma, ortak toprak); senkron bağlantıya ortak saat teli eklenir ve 4 tel olur.
  - Derste yalnız asenkron iletişim kullanılacak.
- Asenkron çerçeve yapısı (ekrandan, 00:25:00)
  - Hat boştayken lojik 1'dir. Gönderici hattı bir bit süresi boyunca 0'a çekerek start biti gönderir, sonra veri bitlerini D0'dan başlayarak gönderir, varsa parite bitini ekler, en sonda hattı 1, 1,5 ya da 2 bit süresi 1'de tutarak stop bitlerini gönderir.
  - İki taraf baştan şunlarda anlaşmış olmalıdır: start ve stop biti sayısı, parite kullanılıp kullanılmayacağı ve türü, veri biti sayısı, baud rate. Bu "anlaşma" ayrı bir veri alışverişi değildir; örneğin bir sensörün veri sayfasında "9600 baud, 8 veri biti, 1 start, 2 stop, even parity" diye yazar.
  - Bir bitin hatta kalma süresi baud rate'in tersidir: 9600 baud için $1/9600 \approx 104\ \mu s$. 1,5 stop biti $\approx 156\ \mu s$, 2 stop biti $\approx 208\ \mu s$ demektir.
  - Alıcı bir biti yaklaşık ortasında ve sonunda iki kez örnekler; iki örnek aynıysa biti doğru okuduğunu kabul eder.
- Parite hesabı (ekrandan, 00:35:00)
  - Even (çift) parite: parite biti dahil 1'lerin sayısı çift olur. Odd (tek) parite: parite biti dahil 1'lerin sayısı tek olur.
  - Slayttaki veri `1 1 0 1 1 1 1 0` altı tane 1 içerir: çift paritede P = 0, tek paritede P = 1.
- Simpleks, yarı dupleks ve tam dupleks (ekrandan, 00:40:00)
  - Simpleks: tek yönlü kanal; örnek karasal radyo ve TV yayını.
  - Yarı dupleks: iki yön de desteklenir ama aynı anda yalnız bir yön kullanılır; örnek telsiz.
  - Tam dupleks: iki yönde eş zamanlı aktarım; örnek cep telefonu görüşmesi.
- Baud rate ve data rate
  - Data rate saniyede gönderilen gerçek veri biti sayısıdır. Baud rate start, stop ve parite bitleri dahil hatta saniyede yapılabilen değişim (bit) sayısıdır.
  - 1200 baud için bir bit hatta yaklaşık 0,83 ms kalır.
- Hata tespiti (ekrandan, 00:45:00)
  - Hata kaynakları: uzun hatta elektromanyetik girişim (örneğin yakındaki bir motor) bitleri bozabilir; start ya da stop bitlerinde kayma çerçeve hatasına yol açar.
  - Parite kontrolü: gönderici pariteyi hesaplayıp verinin ardından gönderir; alıcı aldığı veriden kendi paritesini hesaplar ve gelen parite ile karşılaştırır, farklıysa veriyi atar. Tek sayıda bit hatasını yakalar, çift sayıda bit hatasını yakalayamaz.
  - Checksum: veri blokları üzerinde toplama yapılıp toplam karşı tarafa gönderilir.
  - CRC: slayta göre veri akışı bir polinomla ifade edilip sabit bir polinoma bölünür ve kalan kontrol bitleri olarak gönderilir.
- Yazılımsal seri gönderme (ekrandan, 00:50:00 ve 00:55:00)
  - Bir 8255 portunun D0 biti seri çıkış olarak kullanılır. 8 veri biti + 1 start + 1 (ya da 2) stop = 10 (ya da 11) bit gerekir; 8 bitlik AL buna yetmez.
  - Çözüm: elde bayrağı (CF) ile AL birleşerek 9 bitlik sanal yazmaç oluşturur (`RCL`/`RCR`). `CLC` + `RCL AL,1` ile 0 (start biti) D0'a gelir, her adımda `RCR AL,1` sıradaki biti D0'a getirir, `STC` ile AL soldan 1'lerle beslenir ve veri bitince D0'a 1 (stop biti) gelir.
  - Her bit `OUT` ile porta yazılır ve `DELAY` ile bir bit süresi (9600 baud için yaklaşık 104 µs) beklenir.
- 8251 USART uç tanımları (ekrandan, 01:15:00)
  - USART: Universal Synchronous/Asynchronous Receiver/Transmitter. Seri veriyi hem alır hem gönderir, senkron ve asenkron modları destekler.
  - 8 veri ucu (D7-D0) olduğu için 8086'ya 8255 gibi ardışık çift ya da ardışık tek adreslere yerleştirilir.
  - Tek adres ucu C/$\overline{D}$ olduğu için G/Ç uzayında 2 bayt kaplar, ama dışarıdan erişilen 7 yazmacı vardır: mod, senkron karakteri 1 ve 2, kontrol, data-in, data-out ve durum (status).
  - $\overline{CS}$ adres çözücü çıkışına bağlanır; 0 iken entegre seçilir. Seçilmediğinde ya da $\overline{RD}$/$\overline{WR}$ aktif değilken veri uçları yüksek empedanstadır.
  - RxD seri giriş, TxD seri çıkış ucudur. $\overline{RxC}$ ve $\overline{TxC}$ alma ve gönderme saatleridir; baud rate bunlardan (1, 16 ya da 64'e bölünerek) elde edilir. CLK ucu iç zamanlama içindir, baud rate ile ilgisi yoktur. RESET ucu entegreyi donanımsal olarak sıfırlar. Modem kontrol uçları (DSR, DTR, CTS, RTS) derste kullanılmayacak.
  - RxRDY: alınan bayt data-in tamponuna konunca 1 olur. TxRDY: data-out tamponu boşalınca, yani yeni bayt yazılabilir olunca 1 olur. İkisi de fiziksel uçtur (kesme isteği için) ve aynı zamanda durum yazmacında birer bittir (polling için).
- Yazmaçlara erişim kuralı
  - C/$\overline{D}$ = 0, okuma: data-in tamponu; C/$\overline{D}$ = 0, yazma: data-out tamponu.
  - C/$\overline{D}$ = 1, okuma: durum yazmacı.
  - C/$\overline{D}$ = 1, yazma: sıraya bağlıdır. Resetten sonraki ilk yazma mod yazmacına gider; asenkron modda sonraki yazmalar kontrol yazmacına gider. Kontrol yazmacındaki internal reset biti ile akış başa döner (ekrandan, 01:30:00).
- Mod yazmacı, asenkron mod (ekrandan, 01:35:00)
  - Bit düzeni `S2 S1 EP PEN L2 L1 B2 B1`.
  - B2 B1 (baud rate faktörü): 00 senkron mod, 01 faktör 1, 10 faktör 16, 11 faktör 64. Faktör $\overline{RxC}$ ve $\overline{TxC}$'ye birlikte uygulanır.
  - L2 L1 (veri biti): 00 → 5, 01 → 6, 10 → 7, 11 → 8.
  - PEN: 0 parite yok, 1 parite var. EP: 0 odd, 1 even.
  - S2 S1 (stop biti): 00 geçersiz, 01 → 1, 10 → 1,5, 11 → 2.
- Kontrol yazmacı
  - D0 TxEN (gönderme izni), D2 RxE (alma izni), D4 ER (hata bitlerini temizle), D6 IR (internal reset, yazılımsal reset). Modem bitleri kullanılmayacak.
- Durum yazmacı (ekrandan, 01:40:00)
  - Bit düzeni `DSR SYNDET FE OE PE TxE RxRDY TxRDY` (D7 → D0).
  - D0 TxRDY, D1 RxRDY, D2 TxE (verici boş), D3 PE (parite hatası), D4 OE (overrun hatası: önceki veri bitmeden üzerine yazma ya da veri hazır olmadan okuma), D5 FE (çerçeve hatası: beklenen stop biti gelmedi).
- 8251 programlama örnekleri (Proteus, ekrandan, 01:45:00-02:00:00)
  - 8251 208H (data) ve 20AH (kontrol/durum) adreslerine yerleştirilmiş; A1 adres hattı C/$\overline{D}$'ye bağlı. Adres 8 bite sığmadığı için `MOV DX, adres` ve `OUT DX, AL` / `IN AL, DX` (dolaylı G/Ç adresleme) kullanılır.
  - $\overline{RxC}$ ve $\overline{TxC}$'ye 9600 Hz saat bağlı, sanal terminal 9600 baud, 8 veri biti, paritesiz, 1 stop bitine ayarlı; bu yüzden faktör 1 seçilir.
  - Başlatma sırası: mod `01001101B` (4DH), kontrol `40H` (internal reset), yine mod `01001101B`, sonra kontrol `00010001B` (11H: ER + TxEN).
  - Gönderme örneği: durum yazmacı okunur, `AND AL, 01H` ile TxRDY test edilir, 1 olunca data portuna 41H ('A') yazılır; sonsuz döngüde sürekli 'A' gönderilir.
  - Alma ve gönderme örneği: RxRDY (D1) beklenir, data portundan karakter okunur, bir artırılır, TxRDY beklenip geri gönderilir (terminalde 'a' basılınca 'b' gelir).

## Hocanın Özellikle Vurguladığı Kısımlar

- Asenkron iletişimde çerçeve ayarlarının iki tarafta önceden aynı olması şarttır
  - Start/stop biti sayısı, parite ve baud rate iki terminalde de aynı olmazsa alıcı bitleri yanlış örnekler.
- Start biti tam bir bit süresi 0'da kalmalıdır
  - Alıcı start bitini ortada ve sonda örnekleyip doğrular. Bu koşul sağlanmazsa çerçeve hatası oluşur ve hat boşa çıkana kadar gelen veri çöpe atılır.
- RCL/RCR ile CF'nin 9. bit olarak kullanılması
  - 8 bitlik yazmaçla 10-11 bitlik çerçeve göndermenin anahtarı budur.
- 8251'in tek adres ucuyla 7 yazmaca erişimi
  - C/$\overline{D}$ = 1 iken yapılan yazmaların sırası önemlidir: önce yazılımsal reset, sonra mod, sonra kontrol.
- RxRDY tampon dolunca, TxRDY tampon boşalınca 1 olur
  - Biri doluluğu, diğeri boşluğu gösterir; ikisi de hem uç hem durum biti olduğu için kesme ya da polling ile kullanılabilir.
- 8251'in çalışması için RESET ve $\overline{CTS}$ uçlarının 0'da olması gerekir.

## Kısa Tekrar Notları

- Seri iletim: az tel, düşük maliyet, uzun mesafe, yavaş. Paralel: hızlı, kısa mesafe, pahalı.
- Senkron: ortak saat, büyük bloklar. Asenkron: ayrı saatler, bayt bayt, start/stop bitleri. Derste asenkron kullanılır.
- Asenkron bağlantı 3 tel, senkron 4 tel.
- Hat boşta 1; start biti 0; veri LSB önce; isteğe bağlı parite; stop biti 1 (1, 1,5 ya da 2 bit).
- Bit süresi = 1 / baud rate: 9600 baud → yaklaşık 104 µs; 1200 baud → yaklaşık 0,83 ms.
- Even parite: toplam 1 sayısı çift; odd parite: toplam 1 sayısı tek. Parite tek sayıda bit hatasını yakalar.
- Simpleks: TV/radyo yayını; yarı dupleks: telsiz; tam dupleks: telefon.
- Yazılımsal gönderme: `CLC`, `RCL AL,1`, döngüde `OUT` + `DELAY` + `RCR AL,1` + `STC`, 10 tur.
- 8251: 2 bayt adres, 7 yazmaç; C/$\overline{D}$ = 0 veri, 1 kontrol/mod/durum.
- Mod yazmacı `S2 S1 EP PEN L2 L1 B2 B1`; 4DH = 1 stop, paritesiz, 8 bit, faktör 1.
- Kontrol: 40H yazılımsal reset; 11H hata temizle + gönderme izni; alma için RxE (D2) de 1 olmalı.
- Durum: D0 TxRDY, D1 RxRDY, D3 PE, D4 OE, D5 FE.

## Detaylı Açıklamalar

- Ders, veri iletiminin paralel ve seri olarak ikiye ayrılmasıyla başladı. Paralel iletimde her bit ayrı bir telden aynı anda gider; bu nedenle bir seferde 8 ya da 16 bit aktarılır ama tel sayısı ve maliyet artar. Seri iletimde ise gönderici yazmaçtaki veriyi en düşük anlamlı bitten başlayarak tek tek hatta koyar, alıcı bu bitleri biriktirip yeniden bayt haline getirir. Seri iletim yavaştır ama gönderme ve alma için birer tel ile ortak toprak yeterli olduğu için uzun mesafede ucuzdur; ayrıca veri kaybını tespit eden yöntemler kullanılabilir.
- Seri iletişim senkron ve asenkron olarak ikiye ayrılır. Senkronda ortak saat olduğu için iki taraf arasında kayma olmaz ve büyük bloklar gönderilir; bu blokların başlangıç ve bitişi tek bit yerine bit dizileriyle işaretlenir. Asenkronda her terminal kendi saatini kullanır. Saatlerin frekansı ya da başlangıç fazı biraz farklı olabileceği için uzun veride kayma birikir; bu yüzden veri küçük paketler halinde gönderilir ve her paketin başı ve sonu birer bitle işaretlenir. Küçük pakete büyük başlangıç/bitiş işaretleri koymak ek yükü çok artıracağından bu seçim mantıklıdır.
- Asenkron çerçevede (ekrandan, 00:25:00) hat boştayken 1'dedir. Gönderici hattın kontrolünü elinde tutar; alıcı yalnız örnekleme yapar. 9600 baud için her bit hatta yaklaşık 104 µs kalır. Alıcı start bitini yaklaşık 50. ve 100. mikrosaniyede iki kez örnekler; iki değer aynıysa start bitini kabul eder ve sonraki bitleri D0'dan başlayan veri olarak okur. Slayttaki örnekte veri bitleri sırasıyla `1 1 0 1 1 1 1 0`'dır; altı tane 1 olduğu için çift paritede parite biti 0, tek paritede 1 olur (ekrandan, 00:35:00). Stop biti 1,5 seçilirse hat $1{,}5 \times 104 \approx 156\ \mu s$, 2 seçilirse yaklaşık $208\ \mu s$ boyunca 1'de kalır.
- Hata tespitinde en temel yöntem paritedir. Gönderici pariteyi hesaplar, veriyi ve ardından parite bitini gönderir; alıcı aldığı bitlerden yeniden parite hesaplar ve karşılaştırır. İki bit birden bozulursa parite değişmez ve hata fark edilmez. Checksum bloklar üzerindeki toplamı gönderir. Slayta göre checksum'da baytlar eldesiz toplanıp 2'ye tümleyeni alınır ve toplam sonucunun sıfır olması beklenir; CRC'de ise veri bir polinoma bölünür ve kalan gönderilir (ekrandan, 00:45:00).
- Yazılımsal seri gönderme örneğinde (ekrandan, 00:55:00) karakter AL'de gelir ve seri veri bir portun 0. bitinden çıkar. `CLC` ile CF = 0 yapılır ve `RCL AL,1` ile bu 0 AL'nin 0. bitine gelir (A7 CF'ye geçer). Döngüde AL porta yazılır, `DELAY` ile bir bit süresi beklenir, `RCR AL,1` ile sıradaki bit 0. konuma gelir ve `STC` ile CF = 1 yapılır. Böylece veri bitleri bittikten sonra 0. konuma 1 gelir ve bu stop biti olarak gönderilir. `CX = 10` start, 8 veri ve 1 stop biti içindir; 2 stop biti için 11 yapmak yeterlidir. 41H için çıkan bit dizisi python ile denendi: `0, 1 0 0 0 0 0 1 0, 1` (start, LSB'den MSB'ye veri, stop). Alıcı tarafın yazılımsal gerçeklemesi (start bitini CF'ye alıp kontrol etme, 8 biti döndürerek biriktirme, sonda stop bitini kontrol etme) yalnız akış olarak anlatıldı, kodu derste verilmedi.
- 8251'de C/$\overline{D}$ = 1 iken yapılan ilk yazma mod yazmacına gider. Mod yazmacının son iki biti 00 değilse entegre asenkron moddadır ve bu bitler baud rate faktörünü seçer. Sonraki yazmalar kontrol yazmacına gider; kontrol sözcüğünde IR (D6) 1 ise entegre yazılımsal olarak resetlenir ve bir sonraki yazma yine mod yazmacına gider. Bu nedenle örnek kodlarda önce bir mod sözcüğü, ardından 40H (internal reset), sonra gerçek mod sözcüğü ve son olarak gerçek kontrol sözcüğü yazılır.
- Gönderme örneğinde (ekrandan, 01:50:00 ve 01:55:00) kod şu sırayla çalışır: DX = 020AH, mod 01001101B, kontrol 40H, mod 01001101B, kontrol 00010001B. Ardından `ENDLESS` döngüsünde 20AH'den durum okunur, `AND AL, 01H` ve `JZ TEKRAR` ile TxRDY beklenir, sonra DX = 0208H ve AL = 41H ile `OUT DX, AL` yapılır. Mantık analizöründe TxRDY 1'e çıktıktan sonra TxD hattında start biti, 41H'nin bitleri (LSB önce) ve stop biti görülür. Alma-gönderme örneğinde kontrol sözcüğüne alma izni ve hata temizleme verilir; RxRDY (durum D1) beklenip 208H'den karakter okunur, bir artırılıp BL'de tutulur, TxRDY beklenip geri yazılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
