# Ders 10 Çalışma Özeti

## Genel Konular

- 8254 sayıcı modlarının devamı: Mod 2, Mod 3, Mod 4 ve Mod 5
  - Bir önceki dersten Mod 0, Mod 1 ve Mod 2'nin temel prensipleri hatırlatılmış, Mod 3, Mod 4 ve Mod 5 detaylı olarak işlenmiştir.
  - Modların zaman diyagramları (timing diagram) üzerinden okunmasının, ezber yapılmasından daha önemli olduğu vurgulanmıştır.
- Mod 2 - Rate Generator (Pulse Üreteci) detaylı inceleme
  - Sayma değeri 1 olduğunda OUT 1'den 0'a düşer, bir clock sonra otomatik olarak 0'dan 1'e yükselir ve bu şekilde periodik bir darbe (pulse) üretilir.
  - GATE = 0 olduğunda sayma duraklar; GATE tekrar 1 olduğunda kaldığı yerden devam eder.
  - Yeni sayma değeri, mevcut cycle tamamlandıktan sonra etkin olur.
  - GATE değişimi saymayı duraklatır, gate tekrar aktif olduğunda sayma başlangıç değerinden yeniden başlar (reset).
- Mod 3 - Square Wave Generator (Kare Dalga Üreteci)
  - OUT, sayma değerinin yarısında 1'den 0'a, diğer yarısında 0'dan 1'e geçer. Bu sayede %50 duty cycle'lı bir kare dalga üretilir.
  - Çift sayılarda sayımın tam yarısında çıkış değişir. Tek sayılarda (örn. 5, 7) yükselen kenar tarafında bir adım fazlalık olur.
  - GATE = 0 olduğunda sayma duraklar ve OUT yükselir; GATE tekrar 1 olduğunda ilk düşen kenarda sayma başlangıç değerinden yeniden başlar.
  - Kare dalga istendiğinde doğrudan Mod 3 seçilmelidir.
- Mod 4 - Software Triggered Strobe
  - Mod 2'ye benzer ancak sayma değeri 1 olduğunda OUT 1'den 0'a düşer, bir clock sonra 0'dan 1'e yükselir ve kalır. Tekrar etmez (non-periodik).
  - Yeni sayma değeri yazılmadıkça kendini tekrar etmez.
  - GATE = 0 olduğunda sayma duraklar.
- Mod 5 - Hardware Triggered Strobe
  - Mod 4'e benzer ancak tetikleme GATE ucunun 0→1 geçişi ile yapılır (Mod 1 gibi).
  - GATE'teki her 0→1 geçişinden sonraki ilk clock düşen kenarında sayıcı yüklenir ve sayma başlar.
  - Sayma bitince OUT 1'den 0'a düşer, bir clock sonra 0'dan 1'e yükselir ve kalır.
  - Sayma bitmeden GATE tekrar 0→1 geçişi yaparsa, sayma sıfırlanır ve başlangıç değerinden yeniden başlar.
- Latch (Leçleme) İşlemi ve Readback Command
  - Sayıcı çalışırken içindeki mevcut sayım değerini okumak için önce latch yapılır (control word'de D2-D3 = 00 seçilerek).
  - Latch, o andaki sayım değerini dondurur ve okunabilir hale getirir.
  - Readback Command (D0-D1 = 11): Latch'lenmiş counter verisini ve/veya status bilgisini okumak için kullanılır.
  - Status okuma: Counter'ın hangi modda çalıştığı, OUT pininin mevcut durumu, latch durumu gibi bilgileri içerir.
  - D5-D4 bitleri: 00 = hem counter hem status, 01 = sadece counter, 10 = sadece status okuma.
  - D3 bitleri hangi counter'dan okuma yapılacağını belirler.
  - Latch yapılmadan readback command ile veri okunamaz.
- Counter latch ve status okuma sıralaması
  - Birden fazla counter için latch ve okuma işlemleri adım adım veya tek komutla yapılabilir.
  - Daha önce latch'lenmiş bir counter tekrar latch'lenmez; mevcut latch verisi okunur.
- Frekans hesaplama örnekleri
  - 2 MHz clock ile Counter 0'a 50 mikrosaniyede bir pulse üretmek için: 50 μs = 20 kHz; 2 MHz / 20 kHz = 100 (64H) sayma değeri.
  - 2 MHz clock ile Counter 1'i 1 kHz kare dalga üretecek şekilde ayarlama: 2 MHz / 1 kHz = 2000; 2000 = 07D0H; LSB = D0H, MSB = 07H.
- Counter'ların kademeli (cascade) bağlantısı
  - Tek counter ile elde edilemeyecek düşük frekanslar için birden fazla counter uç uca bağlanır.
  - Birinci counter'ın OUT çıkışı, ikinci counter'ın clock girişi olarak kullanılır.
  - Örnek: 2 MHz clock ile Counter 0'a 20, Counter 1'e 10 yüklenirse; Counter 0 her 20 sayımda bir pulse üretir (100 kHz), bu pulse Counter 1'i tetikler ve Counter 1 her 10 pulse'da bir çıkış üretir (10 kHz).
  - Bu yöntemle 2 MHz'den çok daha düşük frekanslar elde edilebilir.
- Proteus simülasyonu ve adresleme örneği
  - 8254'ün 7. pinden chip select ile adreslendiği bir devre üzerinde counter 0 ve counter 1'in programlanması.
  - XOR ile register sıfırlama, control word gönderme ve sayım değerlerinin counter adreslerine yazılması.

## Hocanın Özellikle Vurguladığı Kısımlar

- Mod seçiminin anahtar kelimeleri
  - "Pulse" denildiğinde Mod 2, "kare dalga" denildiğinde Mod 3 akla gelmelidir. Bu iki modun isimleri bilinmeli, diğer modlar timing diagramdan çıkarılabilir.
- Frekans hesaplama yaklaşımı
  - Mega ve kilo hertz kavramlarının karıştırılmaması: Frekans ne kadar yüksekse clock pulse'ları o kadar sık gelir. Zaman değil frekans bandında düşünülmesi gerektiği özellikle vurgulanmıştır.
  - Verilen süreyi (μs) önce frekansa çevirmek (f = 1/T), ardından giriş frekansı ile oranlamak gerekir.
- Latch olmadan okuma yapılamaz
  - Sayıcıdaki mevcut değeri okumak için mutlaka önce latch komutu gönderilmesi gerektiği, latch yapılmadan readback command'ın geçerli olmayacağı vurgulanmıştır.
- Timing diagram okuma becerisi
  - Modları ezberlemek yerine timing diagramları okuyarak her modun davranışını anlayabilmenin yeterli olduğu, sınavda da bu diyagramların yorumlanmasının isteneceği belirtilmiştir.

## Kısa Tekrar Notları

- Mod 0: Control word ile OUT 1→0, sayım bitince OUT 0→1, tek seferlik interrupt.
- Mod 1: GATE 0→1 geçişi ile tetiklenen one-shot; sayım bitince OUT 0→1.
- Mod 2: Pulse üreteci; sayım 1'de OUT 1→0, bir clock sonra OUT 0→1, periodik tekrar.
- Mod 3: Kare dalga üreteci; sayımın yarısında OUT değişir, %50 duty cycle, periodik tekrar.
- Mod 4: Yazılımsal tetiklemeli strobe; Mod 2'ye benzer ama tekrar etmez.
- Mod 5: Donanımsal tetiklemeli strobe; GATE 0→1 geçişi ile tetiklenir, tekrar etmez.
- GATE: Mod 0 ve 2'de duraklatma, Mod 1 ve 5'te tetikleme/resetleme, Mod 3'te duraklatma ve resetleme.
- Latch (D2-D3 = 00): Sayıcıdaki mevcut değeri dondurur, okunabilir hale getirir.
- Readback (D0-D1 = 11): Latch'lenmiş counter verisini ve/veya status bilgisini okur.
- Status register: OUT durumu, latch durumu, mod bilgisi, LSB/MSB seçimi, binary/BCD bilgisi içerir.
- Cascade bağlantı: Bir counter'ın OUT'u diğerinin CLK'sına bağlanarak daha düşük frekans elde edilir.
- 16-bit sayı 8-bit veri yolundan: D2-D3 = 11 ile önce LSB sonra MSB gönderilir.
- BCD modda max değer: 9999; binary modda max değer: 65535 (FFFF).

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**Mod 2 - Rate Generator (Detaylı):**
Mod 2, belirli bir frekansta darbe (pulse) üretmek için kullanılır. Control word yazıldıktan sonra OUT 1 olur. İlk clock düşen kenarında sayım değeri yüklenir ve her düşen kenarda sayıcı 1 azalır. Sayım değeri 1'e ulaştığında OUT 1'den 0'a düşer, bir sonraki clock'ta otomatik olarak 0'dan 1'e yükselir. Bu, bir clock genişliğinde negatif bir darbe anlamına gelir. Sayım değeri otomatik olarak başlangıç değerine döner ve işlem periodik olarak tekrarlanır. GATE = 0 yapıldığında sayma duraklar; GATE tekrar 1 olduğunda sayma başlangıç değerinden yeniden başlar (resetlenir). Yeni sayma değeri, mevcut cycle bitene kadar bekletilir ve yeni cycle başında etkin olur.

**Mod 3 - Square Wave Generator (Detaylı):**
Mod 3, %50 duty cycle'lı bir kare dalga üretir. Sayma süreci Mod 2'ye benzer ancak OUT, sayım değerinin tam yarısında değişir. Örneğin, sayım değeri 4 ise: 4→3→2 (burada OUT 1→0) →1→0 (burada OUT 0→1) şeklinde ilerler. Çift sayılarda tam yarısında çıkış değişir; tek sayılarda (5, 7 gibi) yükselen kenar tarafında bir adım fazlalık olur. Sayım bittiğinde otomatik olarak başlangıç değerine döner ve periodik olarak devam eder. GATE = 0 saymayı duraklatır ve OUT'u yükseltir; GATE tekrar 1 olduğunda ilk düşen kenarda sayma başlangıç değerinden yeniden başlar.

**Mod 4 ve Mod 5 - Strobe Modları:**
Mod 4 yazılımsal, Mod 5 donanımsal tetiklemeli strobe modlarıdır. Her ikisinde de sayma değeri 1 olduğunda OUT 1'den 0'a düşer, bir clock sonra 0'dan 1'e yükselir ve kalır (tekrar etmez). Mod 4'te sayma, control word ve sayım değeri yazıldıktan sonra clock düşen kenarında otomatik başlar. Mod 5'te ise saymanın başlaması için GATE ucunun 0→1 geçişi gerekir; bu geçişten sonraki ilk düşen kenarda sayıcı yüklenir ve sayma başlar. Her iki modda da sayma bitmeden önce yeni değer yazılırsa, mevcut sayma tamamlandıktan sonra yeni değer etkin olur. Mod 5'te sayma bitmeden GATE tekrar 0→1 geçişi yaparsa sayma sıfırlanır ve başlangıç değerinden yeniden başlar.

**Latch ve Readback Command (Detaylı):**
8254'ün sayıcıları sürekli geriye saydığı için, içindeki mevcut değeri doğru okumak için önce latch yapılması gerekir. Latch komutu, control word'ün D2-D3 bitleri 00 yapılarak gönderilir; bu, ilgili counter'ın o anki değerini latch register'ına kopyalar. Artık sayıcı saymaya devam ederken latch register'ındaki dondurulmuş değer okunabilir. Readback command (D0-D1 = 11) ile latch'lenmiş veri okunur. D5-D4 bitleri ne okunacağını belirler: 00 = hem counter değeri hem status, 01 = sadece counter değeri, 10 = sadece status. D3-D2-D1-D0 bitlerinin devamı hangi counter'lardan okuma yapılacağını seçer. Birden fazla counter aynı anda latch'lenebilir ve sırayla okunabilir. Daha önce latch'lenmiş bir counter tekrar latch'lenmez.

**Status Register:**
Readback command ile status okunduğunda 8-bitlik bir veri elde edilir: D0 = OUT pininin mevcut durumu, D1 = latch durumu (1 = latch'lenmiş, 0 = latch'lenmemiş), D2-D3-D4 = mod seçimi, D5-D6 = LSB/MSB yükleme formatı, D7 = binary/BCD seçimi. Bu bilgiler, counter'ın mevcut konfigürasyonunu doğrulamak için kullanılabilir.

**Cascade (Kademeli) Bağlantı Örneği:**
2 MHz clock ile 1 Hz pulse üretmek istendiğinde, tek counter maksimum 65.535 sayabildiğinden 2.000.000 / 65.535 ≈ 30 Hz'den daha düşük frekans üretilemez. Bu nedenle iki counter kullanılır: Counter 0'a 2000 yüklenirse, her 2000 sayım sonrası bir pulse üretir (2 MHz / 2000 = 1 kHz). Bu pulse Counter 1'in clock girişi olarak bağlanırsa ve Counter 1'e de 1000 yüklenirse, Counter 1 her 1000 pulse'da bir çıkış üretir (1 kHz / 1000 = 1 Hz). Bu yöntemle istenilen düşük frekans elde edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
