# Ders 22 Çalışma Özeti

## Genel Konular

- 8254 uygulaması 1: kaskat bağlı sayıcılarla 1 Hz'lik darbe üretme (ekrandan, 00:20:00)
  - Soru: A9H adresinden itibaren ardışık tek adreslere yerleştirilmiş 8254 ile, yalnız 2 MHz'lik bir saat işareti varken, periyodik olarak saniyede bir darbe (pulse) üretilecek. Simülasyon ortamında 8254 yerine 8253 bulunur.
  - Adresler: Counter 0 = A9H, Counter 1 = ABH, Counter 2 = ADH, kontrol yazmacı = AFH.
  - Tek sayıcıyla elde edilebilecek en düşük frekans $2\times10^6/65536 \approx 30$ Hz'dir. 1 Hz için toplam $2\times10^6$'ya bölmek gerekir; bu da tek 16 bitlik sayıcıyla mümkün değildir.
  - Çözüm: iki sayıcı kaskat bağlanır (birinin OUT'u diğerinin CLK girişine). Bölme oranları çarpılır; sistem 32 bitlik bir sayıcı gibi davranır. Counter 0 2000'e, Counter 1 1000'e böler: $2\times10^6/(2000\times1000) = 1$ Hz.
  - Darbe üretimi mod 2'nin (periyodik darbe) işidir; son sayıcı mod 2'de çalışır. Öndeki sayıcı ikinci sayıcıya saat ürettiği için mod 2 ya da mod 3'te (kare dalga) olabilir.
  - GATE uçları +5V'a bağlıdır; mod 2 ve mod 3'te GATE yalnız duraklatma için kullanıldığından sayıcılar kesintisiz çalışır.
- Örneğin Assembly kodu (ekrandan, 00:25:00)
  - Kontrol sözcükleri `00110101B` (Counter 0, önce LSB sonra MSB, mod 2, BCD) ve `01110101B` (Counter 1, LSB/MSB, mod 2, BCD) AFH'ye yazılır.
  - BCD sayımda 2000 ondalık değer `2000H`, 1000 ise `1000H` olarak gönderilir. Her ikisinin LSB'si 00H olduğu için önce iki sayıcıya 00H, sonra Counter 0'a 20H, Counter 1'e 10H yazılır.
  - Program bundan sonra sonsuz döngüde bekler; darbeyi donanım kendi üretir.
- Osiloskopla doğrulama
  - Counter 1 çıkışında tam 1 saniye aralıklı darbeler görülür; mod 2 çıkışı bir saat çevrimi boyunca 0, diğer zamanlarda 1'dir.
  - Counter 0 çıkışının periyodu 1 ms (1 kHz) ölçülür.
  - Bölme sırası değiştirilirse (önce 1000, sonra 2000) son çıkış yine 1 Hz kalır; ara çıkış 2 kHz olur (periyot 500 µs).
- 8254 uygulaması 2: frekans ölçer (ekrandan, 00:35:00-00:55:00)
  - Frekans, bir sinyalin bir saniyede kaç kez geçiş yaptığıdır. Bunun için 1 saniyelik hassas bir zaman penceresi ve geçişleri sayan bir sayıcı gerekir.
  - 8254 sayıcıları saat girişinin düşen kenarında azaldığı için ölçülecek sinyal ($f_{in}$) doğrudan Counter 2'nin CLK girişine bağlanır. Counter 2 olay sayıcı (event counter) olarak çalışır.
  - Counter 0 ve Counter 1 kaskat bağlıdır, ikisi de mod 3'te 2000'e böler: $2\times10^6/(2000\times2000) = 0.5$ Hz. OUT1 1 saniye 1'de, 1 saniye 0'da kalan, periyodu 2 s olan bir kare dalgadır.
  - OUT1, GATE2'ye bağlıdır: OUT1 = 1 iken Counter 2 sayar, OUT1 0'a düşünce sayma tam bir saniye sonunda durur.
  - Ölçüm sınırı 9999 Hz: Counter 2 mod 0'da, BCD, 9999 ilk değeriyle yüklenir. Bir saniye dolmadan sıfıra ulaşırsa (OUT2 = 1) ölçüm aralık dışıdır (out of range).
  - Frekans = 9999 - (Counter 2'nin bir saniye sonundaki değeri). Belgedeki örnekte sayıcıda 3275 kalır ve $f = 9999-3275 = 6724$ Hz bulunur.
  - Adresler: F0H Counter 0, F1H Counter 1, F2H Counter 2, F3H kontrol yazmacı.
- Frekans ölçerin yazılım akışı
  - Counter 0 ve 1: `00110110B` ve `01110110B` (mod 3, binary), sayma değeri 2000 = 07D0H (önce iki sayıcıya D0H, sonra 07H).
  - `cycle:` Counter 2 için `10110001B` (mod 0, BCD), LSB ve MSB olarak 99H.
  - `stat:` Counter 1'e read-back komutu `0E4H` (yalnız durumu tut), F1H'den durum okunur, `rol al,1` ile OUT1 biti carry'ye alınır, `jc stat` ile OUT1 0'a düşene kadar beklenir.
  - Counter 2'ye read-back `0C8H` (sayma ve durumu birlikte tut). İlk okuma durum baytıdır; OUT2 = 1 ise taşma (`ovflw`).
  - Taşma yoksa ikinci okuma LSB, üçüncü okuma MSB'dir; her biri `adj` alt programıyla 99'dan çıkarılıp port 0 ve port 1'deki göstergeye yazılır, sonra `jmp cycle`.
  - Taşmada kalan iki okuma boşa yapılır (tutulan sayma değeri okunmadan yeniden tutma yapılamaz), göstergeye FFH gönderilir.
  - Counter 2'nin tek seferlik mod 0'da olması, OUT2'nin 1'e çıkışının kaçırılmamasını sağlar.
- DAC ve ADC'ye giriş (ekrandan, 01:15:00-01:20:00)
  - Mikroişlemci dijital değerlerle çalışır, fiziki dünya analogdur (sıcaklık, basınç, nem, hız, ses). Etkileşim için analog-dijital ve dijital-analog dönüştürücüler gerekir.
  - Akış: Fiziki dünya → (sıcaklık, analog) → Transducer → (elektriksel analog) → ADC → (elektriksel dijital) → µP → (işlenmiş veri) → DAC → (elektriksel analog) → Transducer → (fan hızı, analog) → Fiziki dünya.
  - Transducer bir enerji türünü başka bir enerji türüne çevirir (sıcaklık ya da ışıkla direnci değişen elemanlar, DC motor).
  - ADC çıkışı çözünürlüğe bağlıdır: 8 bit için 00H-FFH (0-255), 10 bit için 0-1023. 0-5 V aralığı doğrusal olarak bu değerlere eşlenir.
- Analog ve dijital sinyal (ekrandan, 01:30:00)
  - Zamanda sürekli ve genlikte sürekli sinyal analogdur; zamanda ayrık ve genlikte ayrık sinyal dijitaldir (sayısal).
  - Zamanda ayrık-genlikte sürekli ve zamanda sürekli-genlikte ayrık sinyaller sayısal sinyal değildir.
- DAC mimarileri (ekrandan, 01:35:00 ve 01:40:00)
  - Binary weighted DAC: toplayıcı op-amp; MSB'de R, sonra 2R, 4R dirençleri, geri besleme 4R/7. Girişler 111 (5V) iken $I = 35/(4R)$, $V_{out} = -5$ V.
  - Her bit bir öncekinin yarısı kadar katkı yapar. Dezavantajı, toleransı düşük ve birbirinden farklı çok sayıda direnç gerektirmesidir.
  - R/2R merdiven DAC: yalnız R ve 2R dirençleri kullanılır; her düğüm gerilim bölücü gibi davranır (LSB/2, ...), sonuç yine toplayıcı op-amp mantığına varır.
- DAC0830 entegresi (ekrandan, 01:45:00-01:50:00)
  - Dışarıdan görülen uçlar: 8 veri ucu (DI0-DI7, AD0-AD7'ye bağlı), $\overline{CS}$, $\overline{WR}$ ve analog çıkış. VREF'e -5 V verilir; çıkıştaki op-amp ters çevirdiği için çıkış 0-5 V olur.
  - Adres ucu yoktur; G/Ç uzayında tek bayt (tek adres) kaplar.
  - Cihazın adresine yapılan her `OUT` ile gönderilen değer 0-255 aralığından 0-5 V aralığına doğrusal olarak çevrilir: 00H → 0 V, 7FH → yaklaşık 2.5 V, FFH → 5 V.
- DAC örneği: testere dişi dalga (ekrandan, 01:55:00)
  - DAC 1000H adresinde; adres 8 bite sığmadığı için DX ile `OUT DX, AL` kullanılır. AL 00H'den başlar, her adımda gönderilir, `CALL DELAY` ile beklenir, `INC AL` ile artırılır.
  - FFH'den sonra AL 00H'ye döner; çıkış 0'dan 5 V'a basamaklı yükselip tekrar düşen testere dişi dalgadır.
  - Çözünürlük: 8 bitte bir basamak $5/255 \approx 0.0196 \approx 0.02$ V; 10 bitte $5/1023$ V.
- Birinci ara sınavın çözümü (ekrandan, 02:00:00-02:20:00)
  - Boşluk doldurma, 8086 veri/adres yolu ve bellek arayüzü, fiziksel adres, iki 8255 ile adres çözme, iki renkli 3x3 LED matris ve tuş tarama entegresiyle tic-tac-toe oyunu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tek sayıcı yetmiyorsa kaskat bağlantı
  - En büyük sayma değeri (65536) bile 2 MHz'i 1 Hz'e indiremez; sayıcılar art arda bağlanınca bölme oranları çarpılır.
- BCD modda sayma değeri
  - 2000 ondalık BCD'de `2000H` olarak yazılır. Ondalık 1000 gönderilip BCD modda çalıştırılırsa yanlış sonuç alınır.
- Sayma değerleri parça parça ve karışık sırayla yazılabilir
  - Önce iki sayıcının LSB'leri, sonra MSB'leri yazılabilir; önce birini tamamen bitirmek zorunlu değildir.
- Read-back ile hem sayma hem durum tutulduysa okuma sırası
  - İlk okuma durum baytı, ikinci LSB, üçüncü MSB'dir. Tutulan değerler okunmadan yeniden tutma yapılamaz; bu yüzden taşmada boş okumalar gerekir.
- DAC0830'un adres ucu yoktur
  - G/Ç uzayında 1 bayt kaplar (8255: 2 adres ucu → 4 bayt, 8251: 1 adres ucu → 2 bayt). Çalışma mantığı, cihazın adresine yapılan `OUT` ile gönderilen değerin analog karşılığının üretilmesidir.
- DAC çözünürlüğü
  - 256 değer ama 255 aralık vardır; bir basamak $5/255$ V'tur.

## Kısa Tekrar Notları

- $2\times10^6/65536 \approx 30$ Hz: tek sayıcıyla 1 Hz olmaz; iki sayıcı kaskat bağlanır ($2000\times1000 = 2\times10^6$).
- Periyodik darbe → mod 2; kare dalga → mod 3; tek seferlik sayma → mod 0.
- Kontrol sözcüğü: SC1 SC0 | RW1 RW0 | M2 M1 M0 | BCD.
- Frekans ölçer: OUT1 (0.5 Hz kare dalga) → GATE2; $f_{in}$ → CLK2; Counter 2 mod 0, BCD, 9999. $f = 9999 - \text{kalan}$; OUT2 = 1 ise aralık dışı.
- Read-back `0E4H`: Counter 1 yalnız durum; `0C8H`: Counter 2 sayma + durum.
- Durum baytının en yüksek biti OUT'tur; `rol al,1` ile carry'ye alınır.
- Analog: zamanda ve genlikte sürekli; dijital: zamanda ve genlikte ayrık.
- Binary weighted DAC: R, 2R, 4R, ... (çok farklı direnç); R/2R merdiven: yalnız iki direnç değeri.
- DAC0830: adres ucu yok, 1 bayt; 00H → 0 V, 7FH → ~2.5 V, FFH → 5 V.
- AL'yi sürekli artırıp DAC'a göndermek testere dişi dalga üretir.

## Detaylı Açıklamalar

- **Kaskat sayıcılarla düşük frekans.** 8254'ün her sayıcısı 16 bitlik bir frekans bölücüdür. Binary modda yazılabilecek en büyük sayma değeri 65536 olduğundan 2 MHz'lik saatle elde edilebilecek en düşük çıkış frekansı yaklaşık 30 Hz'tir. Saniyede bir darbe için toplam bölme oranı $2\times10^6$ olmalıdır. Counter 0'ın OUT ucu Counter 1'in CLK girişine bağlanırsa iki sayıcının bölme oranları çarpılır ve sistem 32 bitlik tek bir sayıcı gibi davranır. Derste Counter 0'a 2000, Counter 1'e 1000 yüklendi; Counter 0'ın çıkışı 1 kHz, Counter 1'in çıkışı 1 Hz oldu. Son sayıcı periyodik darbe istendiği için mod 2'dedir. Ekrandaki kodda Counter 0 da mod 2'de (`00110101B`) ayarlıydı; hoca öndeki sayıcının mod 2 ya da mod 3'te olabileceğini, kare dalga ürettiği için mod 3'ün daha pratik olduğunu söyledi.

  ```asm
  MOV AL, 00110101B   ; Counter 0, LSB/MSB, mod 2, BCD
  OUT 0AFH, AL
  MOV AL, 01110101B   ; Counter 1, LSB/MSB, mod 2, BCD
  OUT 0AFH, AL
  XOR AL, AL          ; iki sayıcının LSB'si 00H
  OUT 0A9H, AL
  OUT 0ABH, AL
  MOV AL, 20H         ; Counter 0 MSB -> 2000 (BCD)
  OUT 0A9H, AL
  MOV AL, 10H         ; Counter 1 MSB -> 1000 (BCD)
  OUT 0ABH, AL
  ENDLESS:            ; sonsuz döngü
  ```
  (ekrandan, 00:25:00)

- **Frekans ölçer.** Amaç, bilinmeyen bir sinyalin bir saniyedeki düşen kenar sayısını saymaktır; sinyal periyodik olmak zorunda değildir, bulunan değer ortalama frekanstır. Counter 0 ve Counter 1, 2000 × 2000 bölme ile periyodu 2 s olan bir kare dalga üretir. Bu dalganın 1 olduğu bir saniye boyunca GATE2 aktiftir ve Counter 2 $f_{in}$'in kenarlarını sayar. OUT1 0'a düşünce Counter 2 hassas biçimde durur ve OUT1'in 0 kaldığı bir saniyelik boşlukta yazılım Counter 2'yi okuyup hesabı yapar. Counter 2 mod 0'da 9999 ile yüklendiği için bir saniye dolmadan 10000 kenar gelirse OUT2 1'e çıkar ve bu durum aralık dışı kabul edilir. Mod 0 tekrarsız olduğundan OUT2'nin 1'e çıkışı kaçırılmaz. Her çevrim sonunda `cycle` etiketine dönülerek Counter 2 yeniden yüklenir; yeni sayma, OUT1'in bir sonraki 1'e geçişiyle başlar.

  ```asm
          mov al,00110110B  ; counter 0, mode3, binary
          out 0f3h,al
          mov al,01110110B  ; counter 1, mode3, binary
          out 0f3h,al
          mov al,0d0h       ; 2000 = 07D0H, LSB
          out 0f0h,al
          out 0f1h,al
          mov al,07h        ; MSB
          out 0f0h,al
          out 0f1h,al
  cycle:  mov al,10110001B  ; counter 2, mode 0, BCD
          out 0f3h,al
          mov al,99h        ; initial count 9999
          out 0f2h,al       ; LSB
          out 0f2h,al       ; MSB
  stat:   mov al,0e4h       ; read-back counter 1 (11 10 0100B)
          out 0f3h,al
          in  al,0f1h       ; counter 1 status
          rol al,1          ; out1 -> carry
          jc  stat          ; wait until low
          mov al,0c8h       ; read-back counter 2 (11 00 100 0B)
          out 0f3h,al
          in  al,0f2h       ; first read is status
          rol al,1          ; out2 -> carry
          jc  ovflw         ; if set then overflow
          in  al,0f2h       ; get LSB
          call adj          ; subtract from 99
          inr al            ; first clock pulse not counted
          out 0,al          ; LSB display (port 0)
          in  al,0f2h       ; get MSB
          call adj
          out 1,al          ; MSB display (port 1)
          jmp cycle
  ovflw:  in  al,0f2h       ; finish the reads
          in  al,0f2h
          mov al,0ffh       ; overflow code
          out 0,al
  ```
  (ekrandan, 00:35:00, 00:50:00, 00:55:00, 01:00:00)

  - Hoca `adj` alt programının AL'yi BL'ye aldığını, AL'ye 99 yazıp okunan değeri bundan çıkardığını anlattı. <!-- BELİRSİZ: adj alt programının kodu karelerde görünmüyor; yalnız sözlü anlatım var. -->
  - Belgedeki `inr al` satırını hoca yanlış geldiğini düşündüğü bir satır olarak geçti. <!-- BELİRSİZ: "inr" 8086 komutu değildir (8085'teki karşılığıdır); 8086'da INC olmalıdır. Satırın amacı (ilk saat darbesinin sayılmaması) derste açıklanmadı. -->

- **DAC ve ADC.** Bir odanın sıcaklığına göre fanı farklı hızlarda çalıştıran sistem örneğinde sıcaklık önce transducer ile elektriksel analog gerilime, sonra ADC ile sayıya çevrilir. Mikroişlemci bu sayıyı referans değerlerle karşılaştırıp bir hız değeri hesaplar; DAC bu değeri motoru sürecek analog gerilime çevirir, motor da (bir transducer olarak) bu gerilimi fan hızına dönüştürür. 0-5 V aralığında çalışan 8 bitlik bir DAC'a 7FH (127) verilirse çıkış yaklaşık 2.5 V olur.
  - Ders sonrası not: Hoca 8 bitlik ADC'yi anlatırken bir an "5 volta karşılık 1023" dedi (01:21:23); 1023 10 bitlik dönüştürücünün en büyük değeridir, 8 bitte 5 V'a FFH (255) karşılık gelir. Hoca hemen ardından 10 bitte 0-1023 aralığını doğru verdi.
  - Ders sonrası not: 7FH için tam değer $127/255 \times 5 \approx 2.49$ V'tur; derste yuvarlanarak 2.5 V denmiştir.

- **Binary weighted DAC hesabı.** İdeal op-amp'ta eksi giriş sanal topraktadır (0 V). Girişler 1-1-1 (5 V) iken kol akımları $5/R$, $5/(2R)$, $5/(4R)$ olur; toplam $35/(4R)$. Bu akım geri besleme direnci $4R/7$ üzerinden geçer: $(0-V_{out})/(4R/7) = 35/(4R)$, dolayısıyla $V_{out} = -5$ V. Girişler 000 iken akım yoktur ve $V_{out} = 0$ V; aradaki değerler doğrusaldır (ekrandan, 01:35:00).

- **DAC0830 ile testere dişi.** DAC0830'un adres ucu olmadığı için adres çözme devresi tek bir adres için $\overline{CS}$'yi aktif eder; `OUT` komutu da $\overline{WR}$'yi 0'a çeker. Veri uçlarına gelen değer DAC içinde dönüştürülür ve çıkış kısa bir süre sonra kararlı bir değere oturur (settle). Bu yüzden testere dişi örneğinde her `OUT` sonrası bir gecikme çağrılır.

  ```asm
  MOV DX, 1000H
  MOV AL, 00H
  TEKRAR:
  OUT DX, AL
  CALL DELAY
  INC AL
  JMP TEKRAR
  ```
  (ekrandan, 01:55:00)

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
