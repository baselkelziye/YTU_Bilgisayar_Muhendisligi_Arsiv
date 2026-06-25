# Ders 7 Çalışma Özeti

## Genel Konular

- Seri Haberleşme Temel Kavramlarının Tekrarı
  - Seri haberleşme, verilerin tek bir hat üzerinden peş peşe (sequential) bitler halinde gönderilmesi ve alınması işlemidir. Mikro işlemci tarafında IN/OUT komutları 8 bit paralel veri ile çalışırken, seri cihazlarla iletişim için bu verinin seri hale dönüştürülmesi gerekir.
  - Senkron haberleşmede iki cihaz ortak bir clock palsi ile senkronizedir ve sürekli iletim yapılır. Asenkron haberleşmede ise clock palsi yoktur; start ve stop bitleri ile verinin sınırları belirlenir.

- Yazılımsal Seri Veri Gönderim Algoritması
  - Veri AL register'ında tutulur. D0 hattı seri veri çıkışı için kullanılır. Toplam paket boyutu (start + data bitleri + stop) counter'a yüklenir.
  - CLC (Carry Clear) ile carry temizlenir, RCL (Rotate Carry Left) ile AL'deki veri bir bit sola kaydırılır; carry'ye düşen bit A0 hattına yazılır ve seri olarak gönderilir. Her adımda delay prosedürü ile bit zamanı kadar beklenir.
  - Gönderim sonrası RCR (Rotate Carry Right) ile veri eski haline geri döndürülür ve carry tekrar 1'e set edilir (STC). Bu sayede bir sonraki adımda carry'den 1 girerek verinin sol tarafı 1'lerle dolar; son adımda stop biti olarak 1 gönderilmiş olur.
  - Döngü counter sıfıra ulaşana kadar devam eder.

- USART (Universal Synchronous/Asynchronous Receiver/Transmitter) - 8251 Entegresi
  - 8251, hem senkron hem asenkron seri haberleşmeyi destekleyen, veri alıp gönderebilen 28 bacaklı bir entegredir. Mikro işlemci ile seri cihaz arasında köprü görevi görür: paralel dünyayı seri dünyaya, seri dünyayı paralel dünyaya dönüştürür.
  - İç yapısında transmit buffer ve receive buffer bulunur. Ayrıca hata kontrolü (parity error, overrun error), parity check ve senkronizasyon işlemleri donanımsal olarak gerçekleştirilir.

- 8251 Pin Yapısı ve Bağlantıları
  - D0-D7: 8 bitlik veri yolu (mikro işlemciye bağlantı).
  - C/D (Control/Data) pini: A0 adres hattı ile belirlenir. C/D=0 ise veri gönderimi/alımı, C/D=1 ise kontrol/mod sözcüğü işlemi yapılır.
  - CS (Chip Select): Active low; adres çözümleme devresinden gelen sinyal ile entegre seçilir.
  - RD ve WR: Okuma ve yazma kontrol sinyalleri; mikro işlemciden gelir, active low'dur.
  - TXD: Seri veri çıkış pini (transmit).
  - RXD: Seri veri giriş pini (receive).
  - CLK: Clock girişi; baud rate'i belirler. Veri hızının belirli bir katı (faktör: 1x, 16x, 64x) olarak ayarlanır.
  - RESET: Entegreyi sıfırlar (active high).
  - CTS (Clear To Send): Transmit devresini aktif etmek için active low olarak toprağa bağlanır.
  - TxRDY ve RxRDY: Transmit ve receive hazır durum sinyalleri.
  - SYNDET: Senkron modda senkronizasyon tespit pini (genelde kullanılmaz).

- Adres Çözümleme ve C/D Pini
  - 8251'de sadece 2 adres kullanılır: biri veri (D), diğeri kontrol (C) için. 8255'teki gibi 4 port yoktur.
  - Peş peşe gelen iki adreste değişen tek bit tespit edilir ve bu bit C/D pinine bağlanır. Örneğin adresler 0280h ve 0282h ise değişen bit A1'dir; A1, 8251'in C/D girişine bağlanır.
  - C/D=0 (D aktif): IN komutu ile veri okuma, OUT komutu ile veri yazma.
  - C/D=1 (C aktif): IN komutu ile status okuma, OUT komutu ile mod/command yazma.

- 8251 İlk Ayar (Initialization) Süreci
  - İlk adım: Reset işlemi. Dışarıdan RESET pini ile veya yazılımsal olarak kontrol yazmacı üzerinden D6 biti set edilerek internal reset yapılır.
  - İkinci adım: Mod Instruction gönderimi. Reset sonrası ilk OUT işlemi otomatik olarak mod yazmacına yazılır. Bu sözcükte senkron/asenkron seçimi, baud rate faktörü, karakter uzunluğu (5-8 bit), parity kullanımı, parity tipi (even/odd) ve stop bit sayısı (asenkron için) belirlenir.
  - Üçüncü adım: Command Instruction gönderimi. Mod ayarından sonra ikinci OUT işlemi komut yazmacına yazılır. Bu sözcükte transmit enable, receive enable, hata sıfırlama, boşluk karakteri gönderme gibi kontrol ayarları yapılır.
  - Bu sıralama kritiktir: Reset → Mod → Command şeklinde ilerlenmelidir. Reset yapılmazsa mod ve komut ayarları düzgün çalışmaz.

- Mod Yazmacı (Mode Register) Detayları
  - En anlamlı iki bit (D1-D0): Senkron/asenkron seçimi. 00 = senkron; 01 = asenkron ×1 faktör; 10 = asenkron ×16 faktör; 11 = asenkron ×64 faktör.
  - D3-D2: Karakter uzunluğu. 00=5 bit, 01=6 bit, 10=7 bit, 11=8 bit.
  - D4: Parity enable. 0=parity yok, 1=parity var.
  - D5: Parity tipi. 0=even parity, 1=odd parity.
  - D7-D6: Stop bit sayısı (sadece asenkron modda anlamlı). 00=geçersiz, 01=1 stop biti, 10=1.5 stop biti, 11=2 stop biti.
  - Senkron modda D7-D6 senkronizasyon karakter sayısı bilgisini taşır.

- Baud Rate Faktörü
  - Asenkron modda clock frekansı, baud rate ile doğrudan ilişkili bir çarpan ile belirlenir: ×1, ×16 veya ×64.
  - ×16 ve ×64 çarpanları, alıcı tarafın veriyi doğru örnekleyebilmesi için kullanılır; clock frekansı baud rate'in 16 veya 64 katı olduğunda alıcı her bit için birden fazla örnekleme yapar ve güvenilirlik artar.
  - Clock değeri, karşı cihazın veri sheet'inde belirtilen baud rate ile uyumlu olmalıdır.

- Komut Yazmacı (Command Register) Detayları
  - D0: Transmit Enable (TXE). 1=transmit aktif, 0=transmit kapalı.
  - D1: Data Terminal Ready (DTR).
  - D2: Receive Enable (RXE). 1=receive aktif, 0=receive kapalı.
  - D3: Send Break Character. 1=boşluk karakteri gönderir.
  - D4: Error Reset. 1=hata bayrakları sıfırlanır.
  - D5: Request To Send (RTS).
  - D6: Internal Reset. 1=iç reset yapılır; reset sonrası tekrar mod ve komut gönderilmelidir.
  - D7: Hunt Mode. Senkron modda senkronizasyon karakteri aranır.

- Durum Yazmacı (Status Register) Detayları
  - D0: Tx Empty. Transmit buffer boş mu? 1=boş, veri gönderilebilir.
  - D1: Rx Ready. Alınacak veri var mı? 1=veri hazır.
  - D2: Tx Ready. Transmit hazır mı? 1=hazır.
  - D3: Parity Error. 1=parity hatası tespit edildi.
  - D4: Overrun Error. 1=overrun hatası; okunan veri üzerine yazılmış.
  - D5: Framing Error (Asenkron). 1=stop biti doğru algılanmamış.
  - D6: Break Detect. 1=break karakteri algılandı.
  - D7: DSR (Data Set Ready).

- Transmit ve Receive İşlemleri
  - Transmit: Status okunur, Tx Empty veya Tx Ready kontrol edilir. Hazırsa veri OUT komutu ile transmit buffer'a yazılır.
  - Receive: Status okunur, Rx Ready kontrol edilir. Hazırsa veri IN komutu ile receive buffer'dan okunur.
  - Bu kontroller yazılımsal olarak polling (sürekli kontrol döngüsü) ile veya donanımsal olarak TxRDY/RxRDY pinleri ile yapılabilir.

- 1.5 Stop Biti Kavramı
  - 1.5 stop biti, 1 tam clock cycle artı yarım clock cycle süresince stop biti (lojik 1) gönderilmesi anlamına gelir.
  - Avantajı: Veri içindeki bitlerin stop biti ile karışmasını önler. Örneğin 1 stop biti kullanıldığında, veri içindeki ardışık 1'ler stop biti olarak algılanabilir. 1.5 stop biti, bu yanlış algılamayı engeller çünkü yarım cycle ek süre, ayırt ediciliği artırır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Reset-Mod-Command Sıralamasının Kritik Olduğu
  - 8251'de ilk ayar süreci kesinlikle Reset → Mod → Command sırasını takip etmelidir. Reset yapılmadan gönderilen mod veya komut sözcükleri dikkate alınmaz. Reset sonrası ilk OUT mod yazmacına, ikinci OUT komut yazmacına yazılır.

- Internal Reset ile External Reset Farkı
  - External reset: RESET pinine fiziksel olarak sinyal uygulanarak yapılır. Internal reset: Komut yazmacının D6 biti set edilerek yazılımla yapılır. Her iki reset de aynı etkiyi yaratır; ancak internal reset yazılımsal kontrol sağlar.

- CTS Pininin Toprağa Bağlanması Gerektiği
  - CTS (Clear To Send) pini, transmit devresini aktif hale getirmek için active low'dur. Kullanılmadığında toprağa bağlanmalıdır; aksi halde transmit işlemi başlamaz.

- Adres Çözümlemede Değişen Bitin C/D'ye Bağlanması
  - 8251 sadece 2 adres kullanır. Peş peşe gelen iki adres arasında hangi bitin değiştiği tespit edilerek o bit C/D pinine bağlanır. Bu, veri ve kontrol işlemlerinin ayrımını sağlar.

## Kısa Tekrar Notları

- 8251 USART: Hem senkron hem asenkron seri haberleşme entegresi.
- C/D pini: 0=veri, 1=kontrol/mod. A0 adres hattı ile belirlenir.
- İlk ayar sırası: Reset → Mod Instruction → Command Instruction.
- Mod yazmacı: Senkron/asenkron, baud rate faktörü (1x/16x/64x), karakter uzunluğu (5-8 bit), parity (even/odd), stop bit sayısı (0/1/1.5/2).
- Komut yazmacı: TXE (D0), DTR (D1), RXE (D2), Send Break (D3), Error Reset (D4), RTS (D5), Internal Reset (D6), Hunt (D7).
- Status yazmacı: Tx Empty (D0), Rx Ready (D1), Tx Ready (D2), Parity Error (D3), Overrun Error (D4), Framing Error (D5), Break Detect (D6), DSR (D7).
- Yazılımsal seri gönderim: CLC → RCL → OUT → Delay → RCR → STC → döngü.
- Baud rate = saniyedeki bit sayısı (bps). Karakter rate = saniyedeki paket sayısı.
- CTS toprağa bağlanır (active low, transmit enable için).
- 1.5 stop biti: Veri içindeki 1'lerin stop biti ile karışmasını önler.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**8251 USART'ın Çalışma Prensibi:**
8251, mikro işlemci ile seri haberleşen cihazlar arasında köprü görevi görür. Mikro işlemci tarafında 8 bit paralel veri yolu (D0-D7) üzerinden veri girer veya çıkar. Seri tarafta ise TXD (transmit) ve RXD (receive) pinlerinden tek hat üzerinden bit bit veri akar. İç yapıda transmit buffer ve receive buffer bu iki dünya arasında dönüşümü sağlar. Gönderim sırasında paralel veri seri hale dönüştürülür, start/parity/stop bitleri eklenir ve clock sinyali ile senkronize edilerek TXD'den gönderilir. Alım sırasında RXD'den gelen seri veri tespit edilir, start biti algılanır, veri bitleri örneklenir, parity kontrolü yapılır ve sonuç receive buffer'da 8 bit paralel veri olarak mikro işlemciye sunulur.

**İlk Ayar (Initialization) Sürecinin Detayları:**
8251 güç açıldığında veya resetlendiğinde hiçbir ayar varsayılan olarak yapılmış değildir. İlk olarak reset işlemi uygulanır (dışarıdan RESET pini ile veya internal reset komutu ile). Reset sonrası entegre, gelecek ilk OUT işlemini mod yazmacı olarak yorumlar. Bu nedenle ilk OUT komutu mod sözcüğünü içermelidir. Mod sözcüğünde entegrenin senkron mu asenkron mu çalışacağı, baud rate faktörü, karakter uzunluğu, parity ayarları ve stop bit sayısı belirlenir.

Mod sözcüğü gönderildikten sonra ikinci OUT komutu komut yazmacına yazılır. Bu komutta transmit ve receive enable, hata sıfırlama, boşluk karakteri gönderme gibi işletme ayarları yapılır. Bu sıralama kesinlikle değiştirilmemelidir: Reset → Mod → Command. Eğer reset yapılmazsa, entegre hangi modda olduğunu bilemez ve gönderilen sözcükleri yanlış yorumlar.

**Yazılımsal Seri Gönderim Algoritmasının Adımları:**
Bu algoritma, 8251 gibi bir donanım kullanmadan yazılımsal olarak seri veri gönderimini simüle eder. AL register'ında gönderilecek veri tutulur. Counter, toplam paket boyutuna (start + data + stop bitleri) ayarlanır.

Döngü başında CLC ile carry temizlenir. RCL ile AL bir bit sola kaydırılır; en alt bit carry'ye düşer, carry'deki 0 (ilk adımda start biti) AL'nin en altına girer. Carry'deki değer (yani gönderilecek bit) A0 hattına OUT edilir. Delay prosedürü ile bit zamanı kadar beklenir. RCR ile veri geri kaydırılır (AL eski haline döner). STC ile carry 1'e set edilir (bir sonraki adımda carry'den 1 girecek, böylece verinin sol tarafı 1'lerle dolacak ve son adımda stop biti gönderilecektir). Counter azaltılır ve sıfır değilse döngüye devam edilir.

**Durum Yazmacı ve Hata Kontrolü:**
Status register, 8251'in o anki durumunu gösteren 8 bitten oluşur. Tx Empty (D0) biti, transmit buffer'ın boş olduğunu ve yeni veri yazılabileceğini gösterir. Rx Ready (D1) biti, receive buffer'da okunacak bir veri olduğunu belirtir. Tx Ready (D2) biti, transmit işleminin hazır olduğunu gösterir.

Hata bitleri: Parity Error (D3), alınan veride parity uyumsuzluğu olduğunu gösterir. Overrun Error (D4), önceki veri okunmadan yeni veri geldiğini ve eski verinin üzerine yazıldığını belirtir. Framing Error (D5), asenkron modda stop bitinin beklenen zamanda algılanamadığını gösterir. Break Detect (D6), hat üzerinde uzun süreli lojik 0 (break) tespit edildiğini belirtir. Hata bayrakları, komut yazmacının D4 biti (Error Reset) set edilerek temizlenebilir.

**Baud Rate Faktörünün Anlamı:**
Asenkron modda 8251'in clock pini, doğrudan baud rate'e eşit olmak zorunda değildir. ×1, ×16 veya ×64 faktörleri ile clock frekansı baud rate'in katları olarak seçilebilir. ×16 ve ×64 faktörleri, alıcı tarafın her bit süresince birden fazla örnekleme yapmasını sağlar. Bu, bit geçişlerinin daha güvenilir tespit edilmesini ve hata oranının düşürülmesini sağlar. Örneğin 9600 baud asenkron iletişim için ×64 faktörü seçilirse clock frekansı 9600 × 64 = 614.400 Hz olmalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
