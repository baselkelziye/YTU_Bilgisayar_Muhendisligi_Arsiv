# Ders 13 Çalışma Özeti

## Genel Konular

- 8251 Proteus örneklerinin devre yapısı
  - Devrede 8086, yolları ayrıştıran 74273 tutucuları, adres çözümleme devresi (74HC154 4'e 16 kod çözücü, 74HC4002 ve 74HC4078 NOR kapıları, NOT kapıları), 8251A, mantık analizörü ve sanal terminal (virtual terminal) bulunur. (ekrandan, 00:05:00)
  - 8251'in RxC ve TxC uçlarına 9600 Hz'lik kare dalga bağlıdır. Asenkron modda bu frekans, mod yazmacındaki baud faktörüne bölünerek kullanılır. İki uca farklı saat bağlansaydı alma ve gönderme farklı hızlarda olurdu.
  - Simülasyonda CTS ve RESET uçları toprağa bağlanır; modem uçları kullanılmaz.
  - Mantık analizörü, bağlı uçtaki lojik değer değiştikçe tetiklenen, kayıt yapan bir osiloskop gibi çalışır. Sanal terminal, sistemin konuştuğu dış çevre birimi rolündedir.
  - Sanal terminalin ayarları sabit kabul edilir: 9600 baud, 8 veri biti, parite yok, 1 stop biti. 8086 tarafı buna uydurulur.
- Adres çözümleme: 208H'den itibaren ardışık çift adreslere yerleştirilmiş 8251
  - Adresler 0208H ve 020AH'dir. 208H'den sonraki çift adres 20AH'dir, 210H değildir. (ekrandan, 00:15:00)
  - 8251'in bir adres ucu (C/D) olduğu için iki adres arasında yalnız bir bit değişmelidir. 208H ile 210H arasında iki bit (A4 ve A3) değişir; bu, 4 baytlık bir alan demektir ve hatadır.
  - Aranan koşul: A15-A10, A8-A4, A2, A0 = 0; A9 = A3 = 1; M/$\overline{IO}$ = 0 (G/Ç işlemi). A1 serbesttir ve 8251'in C/D ucuna bağlanır. (ekrandan, 00:20:00)
  - Port adresi 8 bite sığmadığı için yazılımda adres önce DX'e yüklenir, erişim DX üzerinden yapılır.
- Tasarım yönünde çözüm (hocanın kendi tasarımı)
  - 74HC154'ün iki aktif sıfır izin ucu (E1, E2) ve dört seçim ucu (D, C, B, A; D en anlamlı) vardır. İzinler 0 ise D C B A ile yazılan sayının numaralı çıkışı 0, diğerleri 1 olur.
  - "Girişlerin hepsi 0 iken 0, diğer durumlarda 1" doğruluk tablosu OR kapısıdır. 0 olması gereken adres bitleri bir OR kapısından E1'e, A0 ve M/$\overline{IO}$ ikinci bir OR kapısından E2'ye verilir.
  - A9 → D, A3 → C, B ve A toprağa bağlanır. Doğru adreste DCBA = 1100 = 12 olur, Y12 çıkışı 8251'in $\overline{CS}$ ucunu sürer.
- Analiz yönünde çözüm (Proteus'taki devre)
  - Devrede A0 → A, A2 → B, A3 → C, A9 → D bağlıdır; $\overline{CS}$ 12 numaralı çıkıştan alınır. (ekrandan, 00:25:00)
  - E1 = 0 için NOT girişindeki NOR çıkışı 1 olmalı, yani A15, A14, A13 ve M/$\overline{IO}$ 0 olmalı. E2 için A12, A11, A10, A8, A7, A6, A5, A4 0 olmalı.
  - Sonuç: 0208H (A1 = 0) veri yazmaçları, 020AH (A1 = 1) kontrol/durum yazmaçları adresidir.
- Örnek 1: hazır olduğu sürece sürekli "A" gönderen program
  - Başlangıç: 020AH'ye bir mod sözcüğü yazılır (son iki biti 00 dışında olsun ki asenkron mod seçilsin ve sonraki yazma kontrol yazmacına gitsin), sonra 40H yazılarak yazılımsal reset yapılır.
  - Gerçek ayar: mod yazmacına 01001101B (1 stop, parite yok, 8 veri biti, faktör ×1), kontrol yazmacına 00010001B (hata bitlerini temizle, yalnız gönderici etkin). (ekrandan, 00:30:00)
  - Döngü: 020AH'den durum sözcüğü okunur, `AND AL, 01H` ile TxRDY bakılır; 0 ise bekle, 1 ise 0208H'ye 41H ("A") yazılır ve başa dönülür. (ekrandan, 00:40:00)
  - Mantık analizöründe A0 kanalına TxRDY, A1 kanalına TxD bağlıdır. 41H çerçevesi: idle 1, start 0, LSB önce 1 0 0 0 0 0 1 0, stop 1. (ekrandan, 00:45:00)
- Örnek 2: gelen her karakterin bir sonrakini geri gönderen program
  - Başlangıç aynıdır; kontrol yazmacına bu kez 00010101B yazılır: hata temizleme, alıcı ve gönderici etkin. (ekrandan, 00:50:00)
  - Durum sözcüğünde D0 = TxRDY, D1 = RxRDY'dir. `AND AL, 02H` ile RxRDY 1 olana kadar beklenir, 0208H'den veri okunur, `INC AL` ile bir artırılıp BL'de saklanır; ardından TxRDY 1 olana kadar beklenip değer 0208H'ye yazılır.
  - Seri bağlantıda 8251'in TxD ucu terminalin RXD ucuna, terminalin TXD ucu 8251'in RxD ucuna bağlanır.
- 8254 Programlanabilir Aralık Zamanlayıcısı (PIT): giriş
  - Yazılım denetimli, kesin ve doğru zaman gecikmeleri üretmek için kullanılır; ayrıca olay sayıcı, gerçek zamanlı saat, kare dalga üreteci, karmaşık dalga üreteci ve tek darbe (one shot) üreteci olabilir. (ekrandan, 01:15:00)
  - Yazılımla gecikme (boş döngü, komut çevrim sayısı) saat frekansına bağlıdır ve araya giren kesmelerle bozulur; bu yüzden donanım zamanlayıcıya ihtiyaç vardır.
  - Zamanlayıcı ile sayıcı farkı: CLK girişine sabit frekanslı saat bağlanırsa zamanlayıcı (örneğin 1 kHz → 1 ms çözünürlük), bir sensör çıkışı (konveyör banttaki kızılötesi sensör gibi düzensiz darbeler) bağlanırsa olay sayıcı olur.
  - Üç bağımsız 16 bitlik, programlanabilir, aşağı sayan sayıcı vardır; her biri 6 moddan birinde çalışır; CLK girişi 8 MHz'e kadar çıkabilir.
  - Sayıcı, yüklenen değere göre frekans bölücü gibi çalışır (asenkron flip-flop sayıcısında her katın frekansı ikiye bölmesine benzer).
  - PC'deki kullanımı: sistem saati için saniyede 18.2 frekanslı işaret, 15 µs'de bir dinamik RAM yenileme işareti, PC hoparlöründen uyarı sesleri. (ekrandan, 01:20:00)
- 8254 iç yapısı ve uçları
  - Her sayıcının CLK (saat ya da sensör girişi), GATE (dış kontrol/tetikleme) ve OUT (sayma bitince işaret; INTR için kullanılabilir) uçları vardır. (ekrandan, 01:25:00)
  - D0-D7 veri yolu nedeniyle 8 bitlik bir çevre birimidir; 8086'ya ardışık çift ya da ardışık tek adreslerle bağlanır.
  - $\overline{CS}$, $\overline{RD}$, $\overline{WR}$ aktif sıfırdır. İki adres ucu (A1, A0) olduğu için adres uzayında 4 bayt kaplar: 00 Counter 0, 01 Counter 1, 10 Counter 2, 11 kontrol yazmacı.
- 8254 kontrol sözcüğü (A1 A0 = 11, $\overline{CS}$ = 0, $\overline{RD}$ = 1, $\overline{WR}$ = 0) (ekrandan, 01:30:00)
  - D7-D6 (SC1 SC0): sayıcı seçimi; 11 Read-Back komutu (özel durum).
  - D5-D4 (RW1 RW0): 01 yalnız düşük bayt, 10 yalnız yüksek bayt, 11 önce düşük sonra yüksek bayt; 00 Counter Latch komutu (özel durum).
  - D3-D1 (M2 M1 M0): mod 0-5; mod 2 ve mod 3'te M2 "X"tir.
  - D0 (BCD): 0 ikili 16 bit sayma, 1 BCD (4 basamak) sayma.
  - İkili modda en büyük sayma değeri FFFFH (65536 farklı değer), BCD'de 9999'dur (10000 adım). BCD insanın okuması için kolay, ikili mod daha geniş aralık sağlar.
- 8254 ayarlama örneği (98H'den itibaren ardışık çift adresler) (ekrandan, 01:40:00)
  - İşlemcinin A1, A2 uçları 8254'ün A0, A1 uçlarına bağlıysa: 98H Counter 0, 9AH Counter 1, 9CH Counter 2, 9EH kontrol.
  - Counter 0, ikili, mod 3, 4282'ye bölme: kontrol sözcüğü 00110110B = 36H; sayma değeri önce düşük, sonra yüksek bayt olarak 98H'ye yazılır.
  - Counter 2, ikili, mod 3, C26AH'ye bölme: kontrol sözcüğü 10110110B = B6H; değer 9CH'ye iki bayt olarak yazılır.
  - CLK0 = 1.2 MHz için OUT0 ≈ 280 Hz, CLK2 = 1.8 MHz için OUT2 ≈ 36 Hz.

## Hocanın Özellikle Vurguladığı Kısımlar

- 208H'den sonraki çift adres 20AH'dir
  - Hoca bunun en sık yapılan hatalardan biri olduğunu söyledi. Kontrol yolu: iki baytlık bir cihazın iki adresinde yalnız bir bit değişmelidir; iki bit değişiyorsa adresler 4 baytlık alana yayılmıştır.
- 8251'i bilinen duruma getirme sırası
  - Açılışta 8251'in hangi durumda olduğu bilinmez. Önce mod yazmacına son iki biti 00 olmayan bir değer yazılır (00 senkron mod demektir ve 8251 senkronizasyon karakterlerini bekler), sonra kontrol yazmacına 40H ile reset verilir, ancak bundan sonra gerçek ayarlar yazılır.
- Durumu bekleyip öyle okuma/yazma
  - Veri, 8251 hazır olmadan okunmaz (tampondaki çöp okunur) ve gönderici hazır olmadan yazılmaz (önceki veri ezilir). RxRDY = 1 "8086 Data In tamponunu okuyabilir", TxRDY = 1 "8086 Data Out tamponuna yazabilir" demektir.
- Aynı kod çözücüyle farklı genişlikteki iki cihaz
  - Bir 8255 (4 bayt) ve bir 8251'i (2 bayt) tek bir adres çözümleme devresiyle çözmek, çalışılması önerilen bir alıştırmadır.
- 8254'te zamanlayıcı ile sayıcı ayrımı
  - Hoca bunların iki ayrı kavram olduğunu ve birbirinden ayırt edilmesi gerektiğini vurguladı: CLK'ya saat üreteci bağlamak zamanlayıcı, sensör çıkışı bağlamak olay sayıcı demektir.
- BCD ve ikili sayma
  - 16 bitlik sayıcıya ikili modda en çok FFFFH, BCD modda en çok 9999 yazılabilir.

## Kısa Tekrar Notları

- 8251'in tek adres ucu var → 2 bayt; 8254'ün iki adres ucu var → 4 bayt.
- 208H'den itibaren çift adresler: 0208H (veri), 020AH (kontrol/durum). A1 → 8251 C/D.
- 74HC154: E1, E2 aktif sıfır; D en anlamlı seçim ucu; DCBA = 1100 → Y12.
- "Hepsi 0 iken 0" çıkış veren kapı OR'dur; NOR + NOT de aynı işi görür.
- 8251 başlangıç: mod (D1D0 ≠ 00) → 40H (reset) → 4DH (1 stop, parite yok, 8 bit, ×1) → 11H (yalnız gönderme) ya da 15H (alma + gönderme).
- 8251 durum sözcüğü: D0 TxRDY, D1 RxRDY.
- 41H = "A"; seri çerçeve: start 0, LSB önce 10000010, stop 1.
- 8254: 3 sayıcı, 16 bit, aşağı sayar, 6 mod, CLK en çok 8 MHz.
- 8254 kontrol sözcüğü: SC1 SC0 | RW1 RW0 | M2 M1 M0 | BCD.
- Counter 0, LSB+MSB, mod 3, ikili → 36H; Counter 2 aynı ayarla → B6H.
- Çıkış frekansı ≈ giriş frekansı / sayma değeri.
- İkili en büyük değer FFFFH, BCD en büyük değer 9999.

## Detaylı Açıklamalar

- Adres çözümlemenin amacı, belli bir anda yalnız bir cihazın mikroişlemciyle konuşmasını, diğerlerinin hatta veri çıkarmamasını sağlamaktır. Bu derste 208H'den itibaren ardışık çift adreslere yerleştirilmiş bir 8251 için önce sıfırdan bir devre tasarlanır, sonra Proteus'taki hazır devreye bakılarak cihazın adresi geri çıkarılır. İki adresin ikilik açılımı (ekrandan, 00:15:00):

  ```text
  bit    15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
  0208H   0  0  0  0  0  0  1  0  0  0  0  0  1  0  0  0
  020AH   0  0  0  0  0  0  1  0  0  0  0  0  1  0  1  0
  ```

  Yalnız A1 değişir; bu yüzden A1 kod çözücüye değil 8251'in C/D ucuna gider. C/D = 1 kontrol tipli yazmaçlara (yazmada kontrol/mod, okumada durum), C/D = 0 veri yazmaçlarına erişir.

- Hocanın tasarımında 16 adres biti ve M/$\overline{IO}$ ile toplam 17 koşul, kod çözücünün 6 girişine (2 izin, 4 seçim) sığdırılır. Sıfır olması gereken bitler OR kapılarıyla toplanıp aktif sıfır izin uçlarına verilir; bir olması gereken A9 ve A3 seçim uçlarına verilir. Proteus devresi aynı mantığı NOR + NOT ile kurar ve A0 ile A2'yi de seçim uçlarına koyar; iki tasarım da Y12 çıkışını verir.

- Örnek 1 kodu (ekrandan, 00:30:00 ve 00:40:00):

  ```asm
      MOV DX, 020Ah
      MOV AL, 01001101B   ; mod yazmacı (D1D0 ≠ 00 → asenkron)
      OUT DX, AL
      MOV AL, 40H         ; kontrol: yazılımsal reset
      OUT DX, AL
      MOV AL, 01001101B   ; mod: 1 stop, parite yok, 8 bit, x1
      OUT DX, AL
      MOV AL, 00010001B   ; kontrol: hata temizle, TxEN
      OUT DX, AL
  ENDLESS:
      MOV DX, 020AH
  TEKRAR:
      IN  AL, DX          ; durum sözcüğü
      AND AL, 01H         ; TxRDY
      JZ  TEKRAR
      MOV DX, 0208H
      MOV AL, 41H         ; 'A'
      OUT DX, AL
      JMP ENDLESS
  ```

  Faktör ×1 olduğu için RxC/TxC'deki 9600 Hz doğrudan 9600 baud olur ve terminalle uyumludur. Mantık analizöründe TxRDY'nin 1'e çıktığı anda yeni karakter yazılır; TxD'de önce idle (1), sonra start biti (0), sonra 41H'nin bitleri en düşük anlamlıdan başlayarak (1, beş tane 0, 1, 0) ve en sonda stop biti (1) görülür.

- Örnek 2'de başlangıç aynıdır ama kontrol sözcüğü 00010101B'dir. Kod iki bekleme bloğundan oluşur: birincisi `AND AL, 02H` ile RxRDY'yi bekler ve gelen karakteri okuyup bir artırır, ikincisi TxRDY'yi bekleyip artırılmış karakteri gönderir. Terminalde "a" yazılınca "b", "A" yazılınca "B" döner. Hoca simülasyonun eski sürümlerinde alınan verinin fazladan bir bit ötelendiğini, bu sürümde hatanın giderildiğini belirtti.

- 8254'ün kontrol sözcüğünde RW bitleri sayma değerinin kaç bayt halinde gönderileceğini belirler. 100 gibi 8 bite sığan bir değer için 01 (yalnız düşük bayt) yeter; 60000 gibi bir değer için 11 seçilip önce düşük, sonra yüksek bayt gönderilir; 256'nın tam katları için 10 (yalnız yüksek bayt) kullanılabilir. İkili modda 8000H'den sonraki değer 7FFFH, BCD modda 8000'den sonraki değer 7999'dur.

- 8254 ayarlama örneği kodu (derste anlatıldı):

  ```asm
      MOV AL, 36H      ; Counter 0, LSB+MSB, mod 3, ikili
      OUT 9EH, AL
      MOV AX, 4282     ; ondalık 4282 (= 10BAH)
      OUT 98H, AL      ; önce düşük bayt
      MOV AL, AH
      OUT 98H, AL      ; sonra yüksek bayt

      MOV AL, 10110110B ; Counter 2, LSB+MSB, mod 3, ikili (B6H)
      OUT 9EH, AL
      MOV AX, 0C26AH
      OUT 9CH, AL
      MOV AL, AH
      OUT 9CH, AL
  ```

  Çıkış frekansları: $1.2\,\text{MHz} / 4282 \approx 280.24\,\text{Hz}$ ve $1.8\,\text{MHz} / 49770 \approx 36.17\,\text{Hz}$ (C26AH = 49770).

- Ders sonrası not: Hoca 4282 bölmesinin tam bölündüğünü ve sonucun 280 Hz olduğunu söyledi; 1 200 000 / 4282 tam bölünmez, sonuç yaklaşık 280.24 Hz'dir (python ile kontrol edildi).
- Ders sonrası not: Hoca adres uçları 00 iken "sayıcı 1'e" erişildiğini söyledi; slayttaki tabloya göre 00 Counter 0, 01 Counter 1, 10 Counter 2, 11 kontrol yazmacıdır.
- Ders sonrası not: Hoca ders sonunda "5 tane modumuz var" dedi; slaytta ve dersin başındaki anlatımda olduğu gibi 8254'te mod 0'dan mod 5'e kadar 6 mod vardır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
