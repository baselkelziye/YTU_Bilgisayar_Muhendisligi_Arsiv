# Ders 9 Çalışma Özeti

## Genel Konular

- 8254 Programlanabilir Zamanlayıcı/Sayıcı Entegresi'ne giriş
  - 8254, yazılım kontrollü bir kesme üretmek amacıyla kullanılan bir zamanlayıcı devresidir. İçerisinde bir sayı yüklenir ve bu sayı her clock pulse'ında bir azaltılarak (decrement) sıfıra ulaşıldığında bir kesme sinyali üretir.
  - Kesme üretmenin yanı sıra olay sayma, kare dalga üretme ve gerçek zamanlı saat uygulamalarında da kullanılabilir.
- 8254'ün iç yapısı ve temel özellikleri
  - Entegre içerisinde üç adet bağımsız 16-bit sayıcı (counter) bulunur. Her bir sayıcı 0'dan 65.535'e kadar (2^16 - 1) değer alabilir.
  - Her sayıcı 6 farklı çalışma modundan birinde programlanabilir (Mod 0 - Mod 5).
  - Maksimum 8 MHz clock frekansında çalışabilir.
  - Her clock pulse'ında sayıcıdaki değer 1 azalır; sayıcı sıfıra ulaştığında OUT pininde bir sinyal değişimi meydana gelir.
- 8254'ün pin yapısı ve adresleme
  - Her counter'ın ayrı clock girişi (CLK), çıkış pini (OUT) ve kontrol ucu (GATE) bulunur.
  - A0 ve A1 adres pinleri ile üç counter ve kontrol register'ı seçilir: 00 = Counter 0, 01 = Counter 1, 10 = Counter 2, 11 = Kontrol Register.
  - Veri yolu 8-bit olduğundan, 16-bitlik bir sayıyı yüklemek için LSB ve MSB ayrı ayrı gönderilir.
- Kontrol Kelimesi (Control Word) yapısı
  - 8-bitlik kontrol kelimesinin ilk iki biti (D0, D1) hangi counter'ın programlanacağını belirler.
  - D2 ve D3 bitleri veri yükleme formatını belirler: 01 = sadece LSB, 10 = sadece MSB, 11 = önce LSB sonra MSB (2 cycle), 00 = latch (o anki sayım değerini dondurma).
  - D4, D5, D6 bitleri çalışma modunu seçer (Mod 0 - Mod 5).
  - D7 biti sayım formatını belirler: 0 = binary (hex), 1 = BCD (decimal).
- Binary ve BCD sayım farkı
  - Binary modda sayıcıya yüklenen hex değer doğrudan binary karşılığına çevrilerek sayılır. Örneğin 92H = 146'dan geriye sayar.
  - BCD modda ise her hane ayrı ayrı decimal olarak yorumlanır. Örneğin 92H = 92'den geriye sayar.
  - BCD modda yazılabilecek en yüksek değer 9999, binary modda ise FFFF'tir (65.535).
- Frekans ve sayma ilişkisi
  - Clock frekansı ne kadar yüksekse, sayıcı o kadar hızlı düşer ve kesme o kadar çabuk oluşur.
  - 1 Hz clock ile 65.535 yüklenirse, kesmenin oluşması 65.535 saniye sürer.
  - Sayıcının sıfıra inme süresi = yüklenen değer / clock frekansı formülüyle hesaplanır.
- PC'de kullanım alanları
  - Sistem saatini (time of day) belirlemek için 1,19 MHz'lik bir clock ile kullanılır.
  - RAM yenileme (refresh) sinyali üretmek için 15 ms'de bir sayıcı sıfırlanacak şekilde ayarlanır.
- 8254 programlama örnekleri
  - Verilen bir başlangıç adresine (örn. 98H) yerleştirilmiş 8254 için kontrol kelimesi hesaplanıp gönderilmesi.
  - Counter 0'ı Mod 3, binary sayım, LSB+MSB yükleme şeklinde programlama.
  - 16-bitlik sayı değerinin (örn. 4282H) counter'a LSB ve MSB sırasıyla gönderilmesi.
  - Farklı clock frekanslarına sahip counter'ların çıkış frekanslarının hesaplanması.

## Hocanın Özellikle Vurguladığı Kısımlar

- Frekans ve zaman arasındaki ters orantı
  - Frekans arttıkça clock pulse'ları daha sık gelir ve sayıcı daha hızlı düşer. Öğrencilerin mega ve kilo hertz kavramlarını karıştırmaması, frekansın yüksek olmasının daha sık sinyal gönderilmesi anlamına geldiğini anlaması vurgulanmıştır.
- Kontrol kelimesinin doğru oluşturulması
  - Counter seçimi, veri yükleme formatı (LSB/MSB), mod seçimi ve binary/BCD ayrımının kontrol kelimesinde doğru biçimde ayarlanması gerektiği özellikle vurgulanmıştır.
- 16-bit sayının 8-bit veri yolundan gönderilmesi
  - 8254'ün 16-bit sayıcıları olmasına rağmen veri yolunun 8-bit olması nedeniyle, 11 (önce LSB sonra MSB) seçeneği kullanılarak iki adımda yükleme yapılması gerektiği anlatılmıştır.
- BCD ile binary sayım arasındaki fark
  - BCD modda hex sayıların her hanəsi ayrı decimal olarak yorumlanır; bu farkın programlama ve sayma değerinin hesaplanmasında kritik olduğu vurgulanmıştır.

## Kısa Tekrar Notları

- 8254 içinde 3 adet bağımsız 16-bit sayıcı barındırır.
- Maksimum sayım değeri: binary modda 65.535 (FFFF), BCD modda 9999.
- A0-A1 pinleri ile counter seçimi: 00, 01, 10 = counter'lar; 11 = kontrol register.
- Kontrol kelimesi 8 bit: D0-D1 counter seçimi, D2-D3 veri formatı, D4-D6 mod seçimi, D7 binary/BCD.
- Her clock pulse'ında sayıcı 1 azalır; sıfıra ulaşınca OUT sinyali değişir.
- Mod 0: Sayım bitince interrupt üretir (tek seferlik).
- Mod 1: Gate ucunun 0→1 geçişi ile tetiklenen, tekrarlanabilir sayım.
- Mod 2: Pulse (darbe) üreteci; sayım bitince 1 clock süreli negatif pulse.
- Mod 3: Kare dalga (square wave) üreteci; %50 duty cycle.
- Mod 4 ve Mod 5: Yazılım ve donanım tabanlı tetikleyici.
- GATE ucu: Mod 0'da duraklatma, Mod 1'de resetleme/tetikleme, Mod 2 ve 3'te duraklatma ve gate değişimiyle resetleme.
- Counter'lar uç uca (cascade) bağlanarak daha düşük frekanslar elde edilebilir.
- PC'de sistem saati ve RAM yenileme için kullanılır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**8254 Entegresi ve Temel Çalışma Prensibi:**
8254, mikroişlemci sistemlerinde yazılım kontrollü zamanlayıcı ve sayıcı işlevi gören bir entegredir. İçerisinde birbirinden bağımsız üç adet 16-bit sayıcı devresi bulunur. Her bir sayıcıya 0 ile 65.535 arasında bir değer yüklenebilir. Sayıcı, kendisine uygulanan clock pulse'larının her bir düşen kenarında yüklenen değerden bir azaltarak geriye doğru sayar. Sayıcı sıfıra ulaştığında OUT pininde bir sinyal değişimi (moduna bağlı olarak 0→1 veya 1→0) meydana gelir. Bu değişim bir kesme (interrupt) olarak kullanılabilir, bir LED yakılabilir veya başka bir devreyi tetiklemek için kullanılabilir.

**Kontrol Kelimesi (Control Word) Detaylı Analiz:**
Kontrol register'ına gönderilen 8-bitlik kontrol kelimesi, seçilen counter'ın nasıl çalışacağını belirler. İlk iki bit (D0, D1) hangi counter'ın programlanacağını seçer: 00 = Counter 0, 01 = Counter 1, 10 = Counter 2. D2 ve D3 bitleri veri yükleme şeklini belirler: 00 = latch (sayıcıdaki mevcut değeri dondurup okumak için), 01 = sadece LSB (8-bit) yükleme, 10 = sadece MSB (8-bit) yükleme, 11 = önce LSB sonra MSB (16-bit yükleme, 2 cycle). D4, D5 ve D6 bitleri mod seçimini yapar (Mod 0'dan Mod 5'e kadar). D7 biti ise sayım formatını belirler: 0 = binary, 1 = BCD.

**Frekans Hesaplama ve Zaman İlişkisi:**
Sayıcının sıfıra ulaşma süresi doğrudan yüklenen değer ve clock frekansı ile ilişkilidir. Örneğin, 2 MHz'lik bir clock ile 100 sayısını yüklersek, her clock pulse'ında sayıcı 1 azalacağı için 100 clock pulse sonra sıfıra ulaşır. 2 MHz = saniyede 2 milyon pulse olduğuna göre, 100 sayım = 100 / 2.000.000 = 50 mikrosaniye sürer. Tersine, istenen bir süre varsa (örneğin 50 mikrosaniyede bir pulse), gerekli sayım değeri = clock frekansı × istenen süre = 2.000.000 × 50×10⁻⁶ = 100 olarak hesaplanır.

**Counter'ların Kademeli (Cascade) Bağlanması:**
Tek bir counter'ın maksimum sayım değeri 65.535 olduğundan, çok düşük frekanslar (örneğin 1 Hz) elde etmek için tek counter yeterli olmayabilir. Bu durumda iki counter uç uca bağlanır: Birinci counter belirli bir değere ayarlanır ve sayım bitiminde ürettiği pulse, ikinci counter'ın clock girişi olarak kullanılır. Örneğin, 2 MHz clock ile Counter 0'a 2000, Counter 1'e 1000 yüklenirse; Counter 0 her 2000 sayımda bir pulse üretir (1 kHz), bu pulse Counter 1'i tetikler ve Counter 1 de her 1000 pulse'da bir çıkış üretir. Sonuç: 2.000.000 / (2000 × 1000) = 1 Hz elde edilir.

**Mod 0 - Interrupt on Terminal Count:**
Control word yazıldıktan sonra OUT pini 1'den 0'a düşer. Her clock düşen kenarında sayıcı 1 azalır. GATE = 1 iken sayma devam eder, GATE = 0 iken sayma duraklar. Sayıcı sıfıra ulaştığında OUT 0'dan 1'e yükselir ve bu seviyede kalır. Tek seferlik bir kesme üretimi için uygundur. Yeni bir değer yüklenmedikçe veya control word güncellenmedikçe kendini tekrar etmez.

**Mod 1 - Programmable One-Shot:**
Mod 0'dan farklı olarak, OUT pinini sıfıra indirmek için GATE ucunun 0'dan 1'e geçmesi (rising edge) gerekir. Control word yazıldığında OUT 1 olur, GATE'teki 0→1 geçişinden sonraki ilk clock düşen kenarında sayıcı yüklenir ve sayma başlar. Sayma bitince OUT 0'dan 1'e yükselir. GATE tekrar 0→1 geçişi yaparsa sayma yeniden başlar. Sayma bitmeden GATE değişirse sayma sıfırlanır.

**Mod 2 - Rate Generator (Pulse Üreteci):**
Sayma değeri 1 olduğunda OUT 1'den 0'a düşer, bir clock sonra otomatik olarak 0'dan 1'e yükselir. Bu şekilde bir clock pulse'ı genişliğinde bir darbe (pulse) üretilmiş olur. Bu işlem periodik olarak tekrarlanır. GATE = 0 olduğunda sayma duraklar. Yeni sayma değeri mevcut cycle bitince etkin olur. Belirli bir frekansta pulse üretmek için kullanılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
