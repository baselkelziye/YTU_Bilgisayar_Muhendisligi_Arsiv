# Ders 19 Genişletilmiş Notu: 8254 Örnekleri (Kaskat Sayıcı, Frekansmetre) ve DAC Yapıları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. 8254 örneği 1: 1 saniyede bir pulse
- 2. Örnek 1'in donanımı: adres çözümleme
- 3. Örnek 1'in yazılımı ve simülasyon
- 4. 8254 örneği 2: frekansmetre
- 5. ADC ve DAC'ye neden ihtiyaç var
- 6. Analog ve sayısal işaret
- 7. Binary weighted (ikili ağırlıklı) DAC
- 8. R/2R merdiven DAC
- 9. DAC0830 entegresi
- 10. DAC0830 ile testere dişi dalga örneği
- Örnek Sorular

## 1. 8254 örneği 1: 1 saniyede bir pulse

Önceki haftada 8254'ün modları görülmüştü; bu ders, o konunun örnekleriyle başlar. İlk soru ekranda şöyledir (ekrandan, 00:05:00):

> A9H adresinden itibaren ardışık tek adreslere yerleştirilmiş 8254 (8253'te olur) kullanarak periyodik olarak 1 sn'de bir pulse işareti üretin. 8254 için sadece 2 MHz frekansında bir saat işaretinin var olduğunu düşünün.

Soruda dikkat edilecek üç bilgi vardır: üretilecek işaret 1 saniyede bir pulse'tır, elde yalnız 2 MHz'lik bir saat vardır ve cihaz A9H'den başlayan ardışık tek adreslerdedir. Bu adresler A9H (CNTR0), ABH (CNTR1), ADH (CNTR2) ve AFH (kontrol yazmacı) olur.

### 1.1 Gereken bölme oranı

Sayıcı aslında bir frekans bölücüdür. Saniyede bir pulse demek, periyodun 1 s, frekansın 1 Hz olması demektir. 2 MHz'ten 1 Hz'e inmek için frekansın $2\times10^6$'ya bölünmesi gerekir.

Tek bir sayıcıya yazılabilecek en büyük değer 65535'tir; ama 0 da yazılabilir ve 0 yazıldığında sayıcı 65536 adım sayar. Yani tek sayıcı ile en fazla 65536'ya bölme yapılabilir:

$$f_{min} = \frac{2\times10^6}{65536} \cong 30\,\text{Hz}$$

(ekrandan, 00:05:00). Tek sayıcıyla elde edilebilecek en düşük frekans yaklaşık 30 Hz olduğuna göre 1 Hz için ikinci bir sayıcı gerekir.

### 1.2 Kaskat (zincir) bağlantı

İki sayıcı şöyle bağlanır: 2 MHz'lik işaret birinci sayıcının CLK ucuna, birinci sayıcının OUT ucu ikinci sayıcının CLK ucuna verilir. Böylece birinci sayıcının çıkışı ikinci sayıcının saat işareti olur. Bunun çalışması için birinci sayıcının çıkışı **periyodik** bir işaret olmalıdır.

Periyodik çıkış veren modlardan biri mod 2'dir. Mod 2'de çıkış uzun süre 1'de kalır, anlık olarak kısa bir pulse (0) verir, yine uzun süre 1'de kalır ve bu tekrarlanır. İki pulse arasındaki süre sayma değerine bağlıdır. İkinci sayıcı da mod 2'de çalıştırılırsa, birinci sayıcının her pulse'ında bir adım sayar ve sonuçta istenen pulse işaretini verir.

Toplam bölme, iki sayma değerinin çarpımıdır; çarpımın $2\times10^6$ olması gerekir. Hoca yuvarlak değerler seçer: birinci sayıcı 2000'e, ikinci sayıcı 1000'e bölsün.

- Birinci sayıcının çıkışı: $2\times10^6 / 2000 = 1000\,\text{Hz} = 1\,\text{kHz}$.
- İkinci sayıcının çıkışı: $1000 / 1000 = 1\,\text{Hz}$.

Ekrandaki çözüm de aynıdır: $\frac{2\times10^6}{2000\times1000}=1\,\text{Hz}$, kullanılacak sayıcılar CNTR0 ve CNTR1, kontrol yazmacı AFH (ekrandan, 00:10:00). Şemada 2 MHz → [A9H, CLK, 2000] → 1 kHz → [ABH, CLK, 1000] → 1 Hz zinciri çizilidir.

> **Ders sonrası not:** Hoca 00:09:12'de "Counter 1 adresimiz A9H", ardından "counter 2'nin adresi ABH" dedi. Kullanılan sayıcılar CNTR0 ve CNTR1'dir; doğrusu CNTR0 = A9H, CNTR1 = ABH'dir (ekrandaki çözümde de böyledir). Kontrol yazmacı AFH'dir.

## 2. Örnek 1'in donanımı: adres çözümleme

Aynı soru Proteus'ta bir simülasyon olarak incelenir. Devrede 8086, adres tutucuları (74273), bir 3'e 8 kod çözücü (74LS138), bir OR kapısı ve 8253A bulunur (ekrandan, 00:20:00).

### 2.1 Sayıcı bağlantıları

CNTR0'ın CLK ucuna 2 MHz'lik işaret bağlıdır, CNTR0'ın OUT ucu CNTR1'in CLK ucuna gider. Gözlem için OUT0 ve OUT1 bir osiloskoba (ya da lojik analizöre) bağlanmıştır. Mod 2'de GATE ucu 0 iken sayma durdurulur (inhibe edilir); sayıcıların normal çalışması için iki sayıcının GATE ucu da lojik 1'e (5 V) bağlanmıştır. 8253 ve 8254 bu örnekte aynı biçimde çalışır.

### 2.2 Veri yolu ve 8254'ün adres uçları

Cihaz ardışık **tek** adreslere yerleştirildiği için veri yolunun yüksek anlamlı yarısına bağlanmalıdır: işlemcinin D8-D15 uçları 8254'ün D0-D7 uçlarına bağlanır (ekrandan, 00:15:00).

Adreslerin ikili karşılıkları (ekrandan, 00:15:00):

| Adres | İkili | Kullanım |
|---|---|---|
| A9H | 1010 1001 | CNTR0 |
| ABH | 1010 1011 | CNTR1 |
| ADH | 1010 1101 | CNTR2 |
| AFH | 1010 1111 | Kontrol |

Dört adres arasında yalnız A2 ve A1 bitleri değişir; bu iki bit dört kombinasyonu oluşturur. Bu yüzden işlemcinin A1 ucu 8254'ün A0 ucuna, işlemcinin A2 ucu 8254'ün A1 ucuna bağlanır (ekranda "A2 → A1, A1 → A0"). Bunun yanında G/Ç cihazı olduğu ve ayrı G/Ç (isolated I/O) kullanıldığı için `IN`/`OUT` komutlarında M/$\overline{IO}$ = 0 olmalıdır.

### 2.3 74LS138 ile kod çözme

Sabit kalması gereken uçlar: A0 = 1, A3 = 1, A4 = 0, A5 = 1, A6 = 0, A7 = 1 ve M/$\overline{IO}$ = 0. Toplam yedi koşul vardır. 74LS138'in üç seçim ucu (anlam sırasıyla C, B, A) ve üç izin ucu (E1 aktif 1, $\overline{E2A}$ ve $\overline{E2B}$ aktif 0) vardır; toplam altı giriş eder. Çıkışların hepsi aktif sıfırdır. Yedi koşulu altı girişe sığdırmak için iki koşul bir kapıyla birleştirilir.

Hocanın tahtada çizdiği tasarımda M/$\overline{IO}$ ve A4 birleştirilir. İkisi de 0 olduğunda 0, diğer durumlarda 1 üreten kapı OR kapısıdır; çıkışı aktif sıfır bir izin ucuna verilir. A6 doğrudan diğer aktif sıfır izin ucuna bağlanır. 1 olması gereken A0, A3, A5, A7 kalır: A7 → C, A5 → B, A3 aktif 1 izin ucuna, A0 da kalan seçim ucuna bağlanır. Doğru adreste seçim uçları 111 olur, yani Y7 çıkışı 0'a düşer ve 8254'ün $\overline{CS}$ ucunu sürer.

Proteus'taki devre bundan biraz farklıdır, ama aynı adresleri seçer (ekrandan, 00:20:00):

- A0 → A, A5 → B, A7 → C (seçim uçları)
- A3 → E1 (aktif 1)
- A4 → $\overline{E2}$ (aktif 0)
- A6 ve M/$\overline{IO}$ → OR → $\overline{E3}$ (aktif 0)
- Y7 → $\overline{CS8255}$ etiketiyle 8253A'nın $\overline{CS}$ ucuna

Doğru adreste CBA = 111 = 7 olduğundan iki tasarımda da Y7 seçilir.

## 3. Örnek 1'in yazılımı ve simülasyon

### 3.1 Kontrol sözcükleri

Program EXE tipindedir; veri ve yığın tanımları vardır ama örnekte veri kullanılmaz. Sayıcıları ayarlayan satırlar ekranda şöyledir (ekrandan, 00:25:00):

```text
MOV AL, 00110101B ; CNTR0, 16 bit sayma (2000H)- önce LSB sonra MSB, mod 2, BCD
OUT 0AFH, AL      ; 8254 control word

MOV AL, 01110101B ; CNTR1, 16 bit sayma (1000H)- önce LSB sonra MSB, mod 2, BCD
OUT 0AFH, AL

XOR AL, AL        ; AX xor AX : AX<-0
OUT 0A9H, AL
OUT 0ABH, AL

MOV AL, 20H
OUT 0A9H, AL

MOV AL, 10H
OUT 0ABH, AL

ENDLESS:
```

Kontrol sözcüğünün çözümlemesi, `00110101B` için:

- D7-D6 = 00: CNTR0 seçilir.
- D5-D4 = 11: 16 bit sayma değeri, önce LSB sonra MSB yazılır.
- D3-D1 = 010: mod 2.
- D0 = 1: BCD sayma.

`01110101B` aynı ayarları CNTR1 için yapar (D7-D6 = 01). İki sözcük de AFH'deki kontrol yazmacına yazılır. Mod 2 seçimi, bölüm 1'de tasarım sırasında verilen karardır.

### 3.2 BCD sayma değerleri

Tasarımda sayma değerleri 2000 ve 1000'dir. Sayma BCD yapılacağı için sayıcılara yazılacak değerler `2000H` ve `1000H`'dir; yani her onluk basamak bir nibble'a yazılır. Sayıcı bu değeri BCD olarak sayar: 2000H'den bir adım sonra 1999H gelir. Binary sayılsaydı 2000H'den sonra 1FFFH gelirdi ve bu, 2000H'in ikili değeri olan 8192'den saymaya karşılık gelirdi.

BCD bu örnek için yeterli olduğundan ve BCD'nin nasıl çalıştığını göstermek için seçilmiştir. Sayma değeri 9999'dan büyük olsaydı BCD'ye sığmazdı ve binary kullanmak zorunlu olurdu.

### 3.3 LSB ve MSB'nin yazılması

İki değerin de düşük anlamlı baytı 00H'dir. Bu yüzden önce AL sıfırlanır ve iki sayıcıya LSB olarak gönderilir. `XOR AL, AL` bir sayıyı kendisiyle XOR'ladığı için AL'yi sıfırlar, yani `MOV AL, 0` ile aynı işi yapar. Hoca XOR'un tercih nedenini veri sayfasındaki çevrim sayılarıyla açıkladı: `MOV AL, 0` 4 saat çevrimi, `XOR AL, AL` daha az saat çevrimi sürer.

> **Ders sonrası not:** Hoca `XOR AL, AL` için 2 saat çevrimi dedi. 8086 veri sayfasında yazmaçtan yazmaca XOR büyük olasılıkla 3, yazmaca anlık değer yükleyen MOV 4 saat çevrimidir. Sonuç değişmez: XOR yine daha hızlıdır. Ekrandaki yorum satırında "AX xor AX" yazsa da komut AL üzerindedir; hoca bunu derste düzeltti.

Sayıcılar birbirinden bağımsız çalıştığı için bir sayıcıya 16 bitlik değerin iki baytını art arda yazmak gerekmez. Önce CNTR0'ın LSB'si, sonra CNTR1'in LSB'si, ardından CNTR0'ın MSB'si yazılabilir. Programda sıra şöyledir:

1. CNTR0'a LSB (00H), CNTR1'e LSB (00H).
2. AL ← 20H, CNTR0'a MSB.
3. AL ← 10H, CNTR1'e MSB.

Bu noktada iki sayıcı da mod 2'dedir, CNTR0 2000 (BCD), CNTR1 1000 (BCD) ile yüklüdür ve kaskat bağlıdır. 2 MHz CNTR0'da 2000'e bölünüp 1 kHz olur, CNTR1'de 1000'e bölünüp 1 Hz olur. Son sayıcının çıkışı mod 2 nedeniyle bir pulse işaretidir: uzun süre 1'de kalır, bir saat periyodu boyunca 0'a düşer ve bu periyodik olarak tekrarlanır.

Sayıcılar ayarlandıktan sonra yazılımın zamanlayıcıyla başka bir işi kalmaz; program `ENDLESS` etiketinde boş döngüde bekler. 1 Hz pulse üretimi tamamen 8254 tarafından yürütülür.

### 3.4 Simülasyonda ölçüm

Osiloskopta sarı kanal CNTR0'ın, mavi kanal CNTR1'in çıkışıdır. İmleçlerle (cursor) bakıldığında OUT0'ın iki pulse'ı arasında 4 ms ile 5 ms arası, yani 1 ms vardır. 1 ms periyot $1/10^{-3} = 1000\,\text{Hz}$ demektir. Simülasyon yavaş ilerlediği için ikinci kanal biraz beklenerek ölçülür: OUT1'in pulse'ları 3. ve 4. saniyelerdedir, yani aralarında 1 s vardır ve işaret 1 Hz'tir.

Bu örneğin dersi şudur: bazen tek sayıcı istenen işlemi yapmaya yetmez. O zaman iki sayıcı kaskat bağlanır, birinin OUT'u diğerinin CLK'ına verilir ve istenen frekans elde edilir.

## 4. 8254 örneği 2: frekansmetre

İkinci örnek bir frekansmetredir ve kod üzerinden incelenir. Kaynak belgenin başlığı "Frequency Counter by using 8254 PIT with Hardware and Software"dır (ekrandan, 00:35:00).

### 4.1 Fikir

Frekansmetre, bir işaretin 1 saniyede kaç kez değiştiğini sayar. Bunun için hassas bir 1 saniyelik süreye ihtiyaç vardır. Frekansı 0,5 Hz olan bir kare dalga bu işi görür: periyodu 2 s'dir, 1 saniye 1'de, 1 saniye 0'da kalır. Kare dalganın 1'de kaldığı 1 saniye boyunca ölçülecek işaretin değişimleri sayılır, 0'da kaldığı 1 saniyede hesaplar yapılır. Böylece her 2 saniyede bir hassas bir ölçüm sonucu üretilir.

Elde yine yüksek frekanslı bir saat (2 MHz) varsa, 0,5 Hz'lik referansı üretmek için önceki örnekteki gibi iki sayıcı birlikte kullanılır. Üçüncü sayıcı da ölçülecek dış işaretin değişimlerini saymak için kullanılır: dış işaret doğrudan bu sayıcının CLK ucuna bağlanır.

### 4.2 Donanım

- 2 MHz → CNTR0 CLK; OUT0 → CNTR1 CLK. İki sayıcı da mod 3'te (kare dalga) 2000 ile yüklenir.
- OUT1 0,5 Hz'lik referans kare dalgadır.
- Ölçülecek işaret → CNTR2 CLK.
- OUT1 → CNTR2 GATE.

OUT1'in CNTR2'nin GATE ucuna bağlanması şu anlama gelir: CNTR2, OUT1 = 1 olan 1 saniye boyunca sayar, sonraki 1 saniye boyunca sayma inhibe edilir. Böylece tam 1 saniyelik sayım yapılır.

Belgede 8254 adresleri şöyle verilmiştir (ekrandan, 00:55:00): F0H CNTR0, F1H CNTR1, F2H CNTR2, F3H kontrol yazmacı. Hoca bu örnekte cihazın F0H'den itibaren ardışık adreslere yerleştirildiğinin varsayıldığını söyledi.

Belgedeki hesap (ekrandan, 00:55:00):

$$f_{OUT1} = \frac{2\times10^6}{2000\times2000} = 0{,}5\,\text{Hz}$$

0,5 Hz'lik kare dalganın periyodu 2 s'dir: 1 s yüksek, 1 s alçak.

### 4.3 CNTR0 ve CNTR1'in ayarı

Kodun ilk kısmı (ekrandan, 00:40:00):

```text
; Program to use 8254 as a frequency counter
;Program counters 0 and 1 for square wave mode
;
mov al,00110110B   ;counter 0, mode3, binary
out 0f3h,al        ;control port
mov al,01110110B   ;counter 1, mode3, binary
out 0f3h,al        ;control port
;
; Make each counter a divide-by 2000 (07D0H)
mov al,0d0h  ;LSB
out 0f0h,al     ;counter 0
out 0f1h,al     ;counter 1
;
mov al,07h    ;MSB
out 0f0h,al     ;counter 0
out 0f1h,al     ;counter 1
```

`00110110B`: CNTR0, önce LSB sonra MSB, mod 3 (011), binary. `01110110B` aynı ayarı CNTR1 için yapar. Sayma değeri 2000'dir; binary sayıldığı için yazılacak değer $2000 = 07D0\text{H}$'dir. Önce LSB (`0D0h`) iki sayıcıya, sonra MSB (`07h`) iki sayıcıya gönderilir. Hoca, değerin hex yerine doğrudan onluk 2000 olarak da verilebileceğini, assembler'ın ikili karşılığı hesaplayacağını söyledi.

### 4.4 Ölçüm aralığı ve CNTR2

1 saniye içinde ölçülen işaret CNTR2'nin sayabileceğinden fazla değişim gösterirse (en uç durumda 65536'dan fazla), 1 saniye bitmeden CNTR2'nin çıkışında bir değişim olur ve ölçüm yapılamaz. Hoca bunu düzenli hale getirmek için CNTR2'ye yazılan sayma değerini ölçülebilecek en yüksek frekans olarak tanımlar ve çıkış ucunu kontrol ederek frekansın aralıkta olup olmadığına bakar.

Bu örnekte en yüksek ölçülebilir frekans 9999 Hz seçilir; 10 kHz'lik bir işaret ölçülemez. CNTR2 mod 0'da, önce LSB sonra MSB, BCD olarak ayarlanır (ekrandan, 01:00:00):

```text
;Make counter 2 an event counter
cycle:  mov al,10110001B   ;counter 2, Mode 0 , BCD
        out 0f3h,al        ;control port
        mov al,99h         ;initial count is 9999
        out 0f2h,al        ;LSB
        out 0f2h,al        ;MSB
```

`99h` iki kez gönderilir; BCD olduğu için 9999H, 9999 adımlık sayma demektir.

Mod 0'ın davranışı slayttan hatırlatılır (ekrandan, 00:45:00): kontrol sözcüğü (CW = 10) ve LSB = 4 yazıldıktan sonra OUT 0'a düşer; sayıcı 4, 3, 2, 1, 0 diye sayar; 0'a ulaşınca OUT 1'e çıkar ve 1'de kalır. Sayıcı bundan sonra FFFF, FFFE diye saymaya devam eder ama çıkış değişmez. Mod 0 tekrarsız, bir seferlik bir moddur.

Buna göre CNTR2'ye 9999 (BCD) yüklendiğinde, herhangi bir anda OUT2 1 görülürse ölçülen frekans 9999'dan büyüktür.

> **Ek bilgi (derste anlatılmadı):** Mod 0'da sayma değeri yazıldıktan sonraki ilk CLK pulse'ı değeri sayıcıya yüklemek için kullanılır ve sayma azaltılmaz. Bu yüzden N yüklenen bir sayıcının çıkışı büyük olasılıkla N+1. pulse'ta 1'e çıkar. Slayttaki dalga şeklinde de LSB = 4 yazıldıktan sonra sayıcıda 4 görünmeden önce bir saat periyodu daha geçer.

### 4.5 OUT1'in düşüşünü yakalamak: read-back ile durum okuma

Sistem kurulduktan sonra kendiliğinden çalışır. Programın ilk işi, OUT1'in 0'a düştüğü anı yakalamaktır. O anda CNTR2'nin OUT ucuna bakılır; 1 değilse sayma değeri geçerlidir ve frekans hesabı yapılır.

Bir sayıcının durumunu okumanın tek yolu read-back komutudur. Counter latch komutu yalnız sayma değerini tutar; durum (status) için mutlaka read-back gerekir. Read-back komutu bir ya da birkaç sayıcının sayma ve durum değerlerini tutmaya (latch) yarar. Komut biçimi:

- D7-D6 = 11 (read-back komutu)
- D5 = $\overline{\text{COUNT}}$ (0 ise sayma değeri tutulur)
- D4 = $\overline{\text{STATUS}}$ (0 ise durum tutulur)
- D3, D2, D1 = CNT2, CNT1, CNT0 seçimi
- D0 = 0

CNTR1'in yalnız durumunu tutmak için: sayma istenmez (D5 = 1), durum istenir (D4 = 0, aktif sıfır), CNT1 seçilir. Sonuç $1110\,0100_2 = \text{E4H}$'dir. Belgedeki yorum da "Read-back counter 1 (11 10 0100B)" şeklindedir (ekrandan, 01:00:00).

```text
stat:   mov al,0e4h     ;Read-back counter 1 ( 11 10 0100B )
        out 0f3h,al     ;control port
        in al,0f1h      ;counter 1 status
        rol al,1        ;move out1 to carry
        jc  stat        ;wait until low
```

`E4H` kontrol yazmacına (F3H) yazıldıktan sonra CNTR1'in adresinden yapılan okuma doğrudan durum baytını verir. Durum baytı slayttan (ekrandan, 00:50:00):

| D7 | D6 | D5 | D4 | D3 | D2 | D1 | D0 |
|---|---|---|---|---|---|---|---|
| OUTPUT | NULL COUNT | RW1 | RW0 | M2 | M1 | M0 | BCD |

D7 = 1 ise OUT ucu 1, 0 ise OUT ucu 0'dır. D6 = 1 "null count", 0 "sayma değeri okunabilir" demektir. D5-D0 sayıcının programlandığı modu verir.

En anlamlı bit OUTPUT olduğu için `ROL AL,1` ile sola döndürülür. Döndürme komutlarında en anlamlı bit carry'e geçer (carry'deki eski değer de bu komutta en düşük anlamlı bite gider). Böylece OUTPUT biti carry bayrağına taşınmış olur. Carry 1 olduğu sürece `JC stat` ile başa dönülüp durum yeniden tutulur ve okunur. Döngüden çıkıldığında carry 0'dır, yani OUT1 0'a düşmüştür ve CNTR2 1 saniye boyunca saymıştır.

### 4.6 CNTR2'nin taşma kontrolü ve sayma değerinin okunması

Şimdi 1 saniyede CNTR2'deki sayımın 9999'u aşıp aşmadığına bakılır. CNTR2 mod 0'da olduğundan, 9999 ya da daha az değişim olduysa OUT2 0'da kalır; GATE artık 0 olduğu için ikinci saniye boyunca da sayamaz.

> **Ders sonrası not:** Hoca 00:51:43'te "out ucu 0 ise overflow" dedi. Doğrusu, OUT2 = 1 ise taşma (overflow) vardır; OUT2 = 0 ise sayma değeri geçerlidir. Hoca da hemen sonra (00:53:17, 01:01:12) bu biçimde anlattı.

Önce yalnız CNTR2'nin durumu için komut kurulur: D7-D6 = 11, D5 = 1, D4 = 0, CNT2 seçili; sonuç $1110\,1000_2 = \text{E8H}$. Ancak koddaki değer `C8H`'dir. Bunun nedeni, taşma yoksa sayma değerinin de alınacak olmasıdır; bu yüzden sayma değeri de tutulur (D5 = 0): $1100\,1000_2 = \text{C8H}$. Böylece hem durum hem sayma değeri tek komutla tutulur.

Read-back ile bir sayıcının hem sayma değeri hem durumu tutulduysa, sayıcının adresinden yapılan **ilk okuma durum baytıdır**. Sonraki bir ya da iki okuma, sayıcının 8 bit mi 16 bit mi programlandığına göre tutulan sayma değeridir.

GATE 0'a düştüğü için sayma zaten durmuştur; bu yüzden OUT2'yi bir kez kontrol etmek yeterlidir. İkinci saniye içinde herhangi bir anda OUT2 = 1 görülürse sonuç taşmadır. Program bu kontrolü OUT1 düşer düşmez yapar:

1. `C8H` kontrol yazmacına yazılır.
2. CNTR2'nin adresinden okunan ilk bayt durum baytıdır; `ROL AL,1` ile OUTPUT carry'e alınır.
3. Carry 1 ise `JC` ile `overflow` etiketine gidilir. Orada göstergelere FF yazılır; hoca bu kısmın sistemin geri kalanı görülmediği için tam anlamlı olmadığını, iki göstergede FF görülecek gibi düşünülebileceğini söyledi.
4. Carry 0 ise CNTR2'den sırayla LSB ve MSB okunur (sayıcı önce LSB sonra MSB olarak ayarlandığı için).

<!-- BELİRSİZ: 00:56:00-00:59:30 arasındaki taşma ve "adjust" kod satırları hiçbir karede görünmüyor; aşağıdaki akış altyazıdan kurulmuştur. -->

### 4.7 BCD basamakların hesaplanması

Sayıcılar aşağı sayar: CNTR2 9999'dan başlayıp geriye doğru saymıştır. Geçen adım sayısı, başlangıç değerinden okunan değerin çıkarılmasıyla bulunur. BCD gösterimde bu, her bayt için 99'dan çıkarmaya karşılık gelir. Programdaki `adjust` alt yordamı okunan baytı 99'dan çıkarır.

- Önce LSB okunur, `adjust` ile 99'dan çıkarılır ve sonuç 0 numaralı porta yazılır. Hoca burada 0 adresli bir 8255'e bağlı bir 7 parçalı gösterge sürücüsü olduğunu varsaymayı önerdi: bu porta yazmak, düşük anlamlı iki BCD basamağı göstermektir.
- Sonra MSB okunur, yine 99'dan çıkarılır ve yüksek anlamlı basamaklar başka bir porta yazılır.
- Döngü `cycle` etiketinden baştan başlar.

Hoca kodda bir `INC AL` satırının bulunduğunu ve bu satırın bozuk kaldığını söyledi; gerekçe olarak sayımın 0'dan başlamasını ve bunun da bir adım sayılmasını gösterdi. <!-- BELİRSİZ: 00:58:20-00:58:44 arasında INC AL satırının koddaki yeri ve amacı kesin anlaşılmıyor; ekrandaki belge sonucu INC olmadan 9999-3275=6724 Hz olarak veriyor. -->

Mod 0 tekrarlı değildir; her ölçümden sonra sayma değeri yazılımla yeniden yüklenmelidir. Mod ayarı döngü dışında bırakılabilirdi, ama değer yazan satırlar mutlaka döngü içinde kalmalıdır.

> **Hocanın vurgusu:** Bu örnek kapsayıcı ve bütüncül bir örnektir; read-back komutu, durum tutma, OUT kontrolü ve sayma değeriyle işlem bir arada görülür. Anlamak önemlidir; üzerinde denemeler ve değişiklikler yapılarak incelenmelidir.

### 4.8 Sayısal örnek

Belgedeki soru: OUT1 düştükten hemen sonra CNTR2'de 3275 bulunuyorsa, CLK2 girişinin frekansı nedir? (ekrandan, 00:55:00)

- Başlangıç değeri: 9999 (BCD).
- Okunan değer: 3275.
- Geçen adım: $9999 - 3275 = 6724$.
- 1 saniyede 6724 değişim olduğuna göre $f = 6724\,\text{Hz} = 6{,}724\,\text{kHz}$.

BCD bayt bayt bakıldığında: $99 - 75 = 24$ ve $99 - 32 = 67$; basamaklar birleşince 6724 olur.

**Soru:** Yüksek anlamlı kısımla düşük anlamlı kısım ayrı ayrı mı yazdırılıyor? **Cevap:** Evet. BCD olduğu ve 9999'dan bir sayı çıkarıldığında kesinlikle ödünç (borrow) oluşmadığı için iki baytı ayrı ayrı işlemekte sorun yoktur.

### 4.9 Özet

2 MHz'lik saatten 2 saniye periyotlu kare dalga üretilir (CNTR0 ve CNTR1, mod 3). OUT1 1 iken CNTR2 (mod 0) ölçülen işareti sayar, OUT1 0'a düşünce GATE ile sayma durur. Read-back ile OUT1'in düşüşü yakalanır, CNTR2'nin OUT'una bakılır: 0 ise sayılan değer 9999'dan küçüktür ve anlamlıdır; 1 ise sayıcı 9999'u ne zaman devirdiği bilinemeyeceği için taşma vardır. Taşma yoksa okunan değer 9999'dan çıkarılarak frekans bulunur.

## 5. ADC ve DAC'ye neden ihtiyaç var

Arada verilen molanın ardından hoca 8254 konusunun bu iki örnekle tamamlandığını söyleyip yeni konuya geçer: ADC (analog-digital converter) ve DAC (digital-analog converter) sistemleri. Plan şudur: DAC için binary weighted DAC ve R/2R merdiven DAC, ADC için paralel ADC ve ramp converter ADC yapıları; ardından yardımcı entegreler DAC0830 ve ADC0804, en son örnekler.

Mikroişlemci tarafı sayısal bir sistemdir. Fiziki dünya ise analogdur: sıcaklık, basınç, nem, hız gibi değerler analogdur. Sayısal sistemin dış dünyadan bir girdi alması için bu değerin bir ADC'den geçmesi, dış dünyaya bir çıktı üretmesi için de bir DAC kullanılması gerekir.

### 5.1 Örnek: oda sıcaklığının fanla ayarlanması

Slayttaki akış (ekrandan, 01:25:00):

```text
Fiziki Dünya --Sıcaklık (analog)--> Transducer --Elektriksel (analog)--> ADC
   --Elektriksel (dijital)--> μP --İşlenmiş Veri (elektriksel-dijital)--> DAC
   --Elektriksel (analog)--> Transducer --Fan Hızı (analog)--> Fiziki Dünya
```

Dış dünyadan okunan değer analog bir sıcaklık değeridir. Sıcaklığı doğrudan sayısala çevirecek bir yapı yoktur; önce elektriksel bir analog gerilime çevrilmesi gerekir. Bir enerji türünü elektriksel işarete çeviren sisteme **transducer** (dönüştürücü) denir. Ancak bundan sonra elde edilen elektriksel analog değer ADC'den geçirilerek sayısal hale getirilebilir.

İşlemci bu değere göre karar verir: ortam istenenden sıcaksa fan hızlandırılır, eşik değerinden soğuksa fan durdurulabilir. Kararın sonucu DAC ile motora uygulanacak analog gerilime çevrilir. Bu taraftaki transducer motorun kendisidir: uçlarına elektriksel işaret uygulanınca açısal hız üretir.

**Soru:** Sıcaklığı elektriksel analog değere çevirmek için nasıl bir eleman kullanılabilir? **Cevap:** Devre deneylerinde kullanılan, sıcaklığı arttıkça direnci değişen NTC ya da termistör gibi bir eleman. Üzerinden geçen akım ölçülerek ya da gerilim bölücü olarak kullanılarak analog bir gerilim elde edilir.

## 6. Analog ve sayısal işaret

Slayt, işaretleri zamanda ve genlikte sürekli/ayrık olmalarına göre dörde ayırır (ekrandan, 01:30:00):

| | Zamanda sürekli | Zamanda ayrık |
|---|---|---|
| Genliği sürekli | Analog işaret | Zamanda ayrık işaret |
| Genliği ayrık | Ayrık genlikli işaret | Sayısal işaret |

- **Analog işaret:** her $t$ anı için bir değeri vardır; hem yatay eksende (zaman) hem dikey eksende (genlik) süreklidir.
- **Ayrık genlikli işaret:** zamanda süreklidir, ama genlik yalnız belirli kuantalı değerleri alabilir, ara değer alamaz (basamaklı biçim).
- **Zamanda ayrık işaret:** genlik sürekli olabilir, ama yalnız belirli periyotlarda ölçüm değeri verir.
- **Sayısal (dijital) işaret:** hem zamanda belirli periyotlarda örneklenmiş hem de genliği yalnız belirli kuantalarda değer alabilen işarettir.

Hoca sayısal işareti, yalnız tamsayı tutan 100 elemanlı bir diziye benzetir. Float tutan bir dizi de gösterimi itibariyle sayısal olarak ifade edilebilir.

## 7. Binary weighted (ikili ağırlıklı) DAC

İlk DAC yapısı, devre teorisinden bilinen opamplı toplama devresidir (ekrandan, 01:35:00). V1 (MSB) R, V2 2R, V3 (LSB) 4R direnci üzerinden opampın eksi girişine bağlanır; artı giriş topraktadır, geri besleme direnci $4R/7$'dir.

### 7.1 İdeal opamp bağıntıları

- $V_n = V_p$ (iki giriş düğümünün gerilimi eşittir).
- $i_p = i_n = 0$ (ideal opampın girişlerine akım akmaz).

$V_p$ toprağa bağlı olduğu için $V_p = 0$, birinci bağıntıdan $V_n = 0$'dır.

### 7.2 Çıkış geriliminin bulunması

V1, V2, V3 sayısal girişlerdir: lojik 0 ya da 1, yani 0 V ya da 5 V. Ortak düğüm 0 V olduğu için kol akımları:

$$\frac{V_1}{R},\quad \frac{V_2}{2R},\quad \frac{V_3}{4R}$$

Opampın girişine akım akmadığından bu üç akımın toplamı geri besleme direncinden geçer. Akım düğümden çıkışa doğru aktığı için çıkış negatiftir (evirici):

$$V_{out} = -\left(\frac{V_1}{R}+\frac{V_2}{2R}+\frac{V_3}{4R}\right)\cdot\frac{4R}{7}$$

(ekrandan, 01:40:00). Hesaplanan durumlar (python ile doğrulandı):

| V1 | V2 | V3 | $V_{out}$ |
|---|---|---|---|
| 5 | 5 | 5 | −5 V |
| 0 | 0 | 0 | 0 V |
| 5 | 0 | 0 | −20/7 V |
| 0 | 5 | 0 | −10/7 V |
| 0 | 0 | 5 | −5/7 V |

Örneğin yalnız V1 = 5 V iken: $-\frac{5}{R}\cdot\frac{4R}{7} = -\frac{20}{7}$ V. Diğer kombinasyonlarda çıkış 0 ile −5 V arasında olur. Ekrandaki yazımda −20/7'nin eksi işareti eksik kalmıştır; hoca derste eksiyi ekledi.

En düşük dirençli kol çıkışa en büyük katkıyı yapar (−20/7). Ortadaki kol bunun yarısı, alttaki kol ortadakinin yarısı kadar katkı verir: 4 : 2 : 1. Direnç dizisi R, 2R, 4R, 8R gibi ikinin kuvvetleriyle artırılırsa, R ile sürülen giriş en anlamlı bit (MSB) gibi davranır. Bir ikili sayının bitleri uygun sırayla girişlere verilirse çıkışta bu sayıya karşılık gelen analog gerilim (burada 0 ile −5 V arasında) elde edilir.

## 8. R/2R merdiven DAC

### 8.1 İki yapının farkı

Hoca iki DAC'yi karşılaştırmayı sorar. İkisi de aynı genlikte bir ikili sayıyı kabul edecek biçimde ayarlanmıştır, ama birincinin bir sakıncası vardır: direnç değerleri bit sayısıyla büyür. Bu devrelerde tolerans çok önemlidir; dirençler hassas ayarlanmazsa sistem doğru çalışmaz. 8 bitlik bir binary weighted DAC için 8 farklı direnç değeri ve her biri için hassas ayarlanmış 8 ayrı tolerans gerekir. R/2R merdivende ise yalnız iki tür direnç vardır ve değerleri birbirine yakındır; yalnız iki tolerans hassas ayarlanarak daha iyi bir sonuç alınır.

### 8.2 Thevenin eşdeğeriyle çözüm

Merdivende LSB, ortadaki bit ve MSB 2R dirençleri üzerinden yatay R-R dizisine bağlanır; dizinin LSB tarafındaki ucu 2R ile toprağa gider, MSB tarafındaki ucu opampın eksi girişine bağlanır, geri besleme direnci 2R'dir (ekrandan, 01:45:00).

LSB tarafındaki düğüm için Thevenin eşdeğeri yazılır. Bu düğümde bir kaynak (V3), iki eşit direnç (2R ve 2R) ve toprak vardır; yapı gerilimi tam ikiye bölen bir gerilim bölücüdür:

$$V_{th} = \frac{V_3}{2}$$

Eşdeğer direnç için kaynak sıfırlanır. Bu durumda iki 2R direncinin bir ucu aynı düğümde, diğer uçları toprakta olduğundan paraleldirler:

$$R_{th} = 2R \parallel 2R = R$$

Devrenin bu kısmı yerine $V_3/2$ kaynağı ve seri R konabilir. Bu R, merdivendeki yatay R ile seri olduğundan toplam 2R olur. Bir sonraki düğümde yine bir kaynak ve 2R, öbür tarafta V2 ve 2R bulunur; yani başlangıçtaki yapının aynısı ortaya çıkar. Her kademede düşük anlamlı kaynağın katkısı bir kez daha ikiye bölünür. Sonuçta katkılar:

- V1 (MSB): $V_1/2$
- V2: $V_2/4$
- V3 (LSB): $V_3/8$

Her bitin katkısı ikili yazılıştaki sırasıyla orantılıdır. Bu katkılar opampın 2R geri besleme direnciyle çarpılarak çıkışa aktarılır. Son eşdeğer ($V_{th}=V_1/2+V_2/4+V_3/8$, $R_{th}=R$) sanal toprağa bağlandığı için çıkış $V_{out}=-\frac{2R}{R}\left(\frac{V_1}{2}+\frac{V_2}{4}+\frac{V_3}{8}\right)=-\left(V_1+\frac{V_2}{2}+\frac{V_3}{4}\right)$ olur (ara adım eklendi).

Yalnız R ve 2R dirençleriyle bir toplayıcı opamp devresi elde edilmiş olur; iki farklı tolerans yeterli olduğu için bu yapı daha avantajlıdır.

## 9. DAC0830 entegresi

Derste ve deneylerde kullanılacak DAC yardımcı entegresi DAC0830'dur. Entegre öğrencilere hazır bir bağlantı yapısıyla verilecektir (ekrandan, 01:50:00):

- $\overline{CS}$ (pin 1) ← $\overline{IO8}$ (adres çözümleme çıkışı)
- $\overline{WR1}$ (pin 2) ve $\overline{WR2}$ (pin 18) ← $\overline{WR}$
- DI0-DI7 ← AD0-AD7
- VREF (pin 8) ← −5 V
- ILE (pin 19) VCC'ye bağlı
- IOUT1 (pin 11) → opamp eksi girişi; IOUT2 (pin 12) → opamp artı girişi ve toprak
- RFB (pin 9) → opamp çıkışı

Uçların görevleri slaytta (ekrandan, 01:55:00):

- $\overline{CS}$: aktif 0 yonga seçimi; ILE ile birlikte $\overline{WR1}$'i etkinleştirir.
- ILE: aktif 1 giriş tutucu izni.
- $\overline{WR1}$: aktif 0; DI bitlerini giriş tutucusuna yükler. $\overline{WR1}$ 1 iken veri tutulur. Giriş tutucusunu güncellemek için ILE 1 iken $\overline{CS}$ ve $\overline{WR1}$ 0 olmalıdır.
- $\overline{WR2}$: aktif 0; $\overline{XFER}$ ile birlikte giriş tutucusundaki 8 bitlik veriyi DAC yazmacına aktarır.
- $\overline{XFER}$: aktif 0 aktarım denetimi; $\overline{WR2}$'yi etkinleştirir.
- DI0-DI7: sayısal girişler.
- IOUT1, IOUT2: DAC akım çıkışları, opampa gider.
- RFB: R-2R için geri besleme direnci.
- VREF: harici hassas gerilim kaynağını içteki R-2R merdivenine bağlayan referans girişi. VCC ve GND besleme uçlarıdır.

### 9.1 Kara kutu olarak DAC0830

Hoca yapıyı bir kara kutu gibi düşünmeyi önerir: −5 V ve diğer koşullandırmalar kutunun içindedir. Dışarıdan görülen yalnız veri uçları, $\overline{CS}$, $\overline{WR}$ ve analog çıkıştır. WR1 ve WR2 birleştirilip tek bir yazma ucu olarak dışarı çıkarıldığı için bu uç cihazın yazma ucu gibi düşünülür. Veri uçları DI0-DI7 olmak üzere 8 tanedir ve mikroişlemcinin veri yoluna bağlanır; cihaz 8 bitliktir, 16 bitlik bir arayüze 8 bitlik bir yardımcı devre olarak bağlanır.

VREF'e −5 V bağlanmasının nedeni, önceki hesaplarda görülen opamp bağlantısının evirici olmasıdır: çıkışın başına bir eksi işareti gelir. Referans 5 V seçilirse çıkış 0 ile −5 V arasında olur; −5 V seçilirse çıkış 0 ile 5 V arasında olur.

Cihaz seçildikten sonra veri uçlarına değer konup yazma yapılır; belirli bir hesaplama süresinin ardından çıkışta kararlı gerilim oluşur. Bu gerilim bir opamp üzerinden alınır. Binary weighted ve R/2R örneklerindeki dirençler entegrenin içindedir, ama opamp dışarıdan bağlanır. Deneylerde de yapı bu şekilde verilecektir.

### 9.2 IO uzayında kapladığı yer

**Soru:** Bu cihazın kaç adres ucu vardır ve IO uzayında kaç bayt yer kaplar? **Cevap:** Derste "0 bayt" cevabı geldi; hoca bunun olamayacağını söyledi. 8254'ün iki adres ucu vardır ve 4 bayt yer kaplar; 8255'in de iki adres ucu vardır ve 4 bayt kaplar. DAC0830'un hiç adres ucu yoktur; $2^0 = 1$ olduğundan IO uzayında 1 bayt yer kaplar.

Bu yüzden soru metinlerinde "8086'lı sistemde IO uzayında 100H adresine bir DAC entegresi yerleştirilmiştir" gibi tek bir adres verilir. Cihazın fiziksel adres ucu yoktur; verilen adrese karşılık $\overline{CS}$'yi adres çözümleme devresi üretir. 8254'te dört ardışık adres yazılırken burada tek adres vardır.

> **Hocanın vurgusu:** Bu kısım önemlidir: adres ucu olmayan bir cihaz IO uzayında bir adres (1 bayt) kaplar; $\overline{CS}$ seçildikten sonra veri uçlarına yazma yapıldığında, belirli bir süre sonra analog çıkışta gönderilen veriye karşılık gelen gerilim oluşur.

## 10. DAC0830 ile testere dişi dalga örneği

Dersin son örneğinde 1000H adresine yerleştirilmiş bir DAC0830 üzerinde şu kod çalıştırılır (ekrandan, 02:00:00):

```text
MOV DX, 1000H
MOV AL, 00H
TEKRAR:
OUT DX, AL
CALL DELAY
INC AL
JMP TEKRAR
```

8 bitlik çalışmada FFH gönderildiğinde cihazın 5 V, 00H gönderildiğinde 0 V üretmesi beklenir; aradaki değerler için çıkış doğrusaldır. Kod önce 0 gönderir (0 V), biraz bekler, AL'yi bir artırır, başa dönüp 1'i gönderir; 2, 3, 4, 5 diye her değer sırayla gönderilir ve her biri bir süre çıkışta tutulur.

### 10.1 Bir adımlık gerilim farkı

**Soru:** AL'deki X değeri gönderildiğinde çıkış $V_X$, X+1 gönderildiğinde $V_{X+1}$ ise $V_{X+1} - V_X$ nedir? **Cevap:** 5 V/256. FFH için 5 V, 00H için 0 V üretildiğine göre toplam 256 adım 5 V'luk aralığı karşılar; orantıyla bir adım 5 V/256'dır.

> **Ders sonrası not:** "FFH için tam 5 V" varsayımıyla 0'dan 255'e 255 adım vardır ve adım 5 V/255 ≈ 19,6 mV olurdu. Gerçek DAC0830'da çıkış büyük olasılıkla $V_{REF}\cdot D/256$ biçimindedir; o zaman adım 5 V/256 ≈ 19,5 mV olur ve FFH için çıkış ≈ 4,98 V'tur (python ile hesaplandı).

### 10.2 Dalga şekli

AL artırıla artırıla FFH'ye ulaşır; gerilim de 5 V'a kadar basamak basamak çıkar. Döngüde sürekli `INC AL` olduğu için FFH'den sonra AL bir artınca 00H'ye döner ve çıkış yeniden 0 V olur. Ardından yine adım adım artar, 255'te tekrar 0'a düşer. Böyle elde edilen analog işarete **testere dişi** işaret denir.

## Örnek Sorular

**1. (ekrandan, 00:05:00)** A9H adresinden itibaren ardışık tek adreslere yerleştirilmiş 8254 kullanarak periyodik olarak 1 sn'de bir pulse işareti üretin. 8254 için sadece 2 MHz'lik bir saat işareti vardır.

> **Çözüm (derste verildi):** CNTR0 A9H, CNTR1 ABH, CNTR2 ADH, kontrol AFH. Tek sayıcıyla en düşük frekans $2\times10^6/65536 \cong 30$ Hz olduğundan iki sayıcı kaskat bağlanır. İkisi de mod 2'de; CNTR0 2000, CNTR1 1000 ile yüklenir: $2\times10^6/(2000\times1000) = 1$ Hz. BCD sayımla kontrol sözcükleri `00110101B` ve `01110101B`, sayma değerleri `2000H` ve `1000H`. Kod çözmede A0, A3, A5, A7 = 1; A4, A6, M/$\overline{IO}$ = 0; işlemcinin A1 → 8254 A0, A2 → 8254 A1; veri D8-D15'ten.

**2. (derste sözlü, 00:48:26 ve 00:52:08)** 8254 için şu read-back komutlarını yazın: (a) yalnız CNTR1'in durumunu tut, (b) yalnız CNTR2'nin durumunu tut, (c) CNTR2'nin hem sayma değerini hem durumunu tut.

> **Çözüm (derste verildi):** Biçim 11, $\overline{\text{COUNT}}$, $\overline{\text{STATUS}}$, CNT2, CNT1, CNT0, 0. (a) $1110\,0100_2$ = E4H, (b) $1110\,1000_2$ = E8H, (c) $1100\,1000_2$ = C8H. (c)'de ilk okuma durum baytıdır, sonraki okumalar sayma değeridir.

**3. (ekrandan, 00:55:00)** Frekansmetre örneğinde CNTR2 9999 (BCD) ile yüklüdür ve OUT1 düştükten hemen sonra CNTR2'de 3275 bulunmaktadır. CLK2 girişinin frekansı nedir?

> **Çözüm (derste verildi):** $f = 9999 - 3275 = 6724$ Hz. BCD baytlarla: $99-75=24$, $99-32=67$.

**4. (ekrandan, 00:55:00)** Frekansmetrede CNTR0 ve CNTR1 mod 3'te 2000'e bölen sayıcılar olarak programlanmıştır ve sistem saati 2 MHz'tir. OUT1'deki frekans ve periyot nedir?

> **Çözüm (derste verildi):** $2\times10^6/(2000\times2000) = 0{,}5$ Hz; periyot 2 s (1 s yüksek, 1 s alçak).

**5. (ekrandan, 01:40:00)** R, 2R, 4R girişli ve $4R/7$ geri beslemeli binary weighted DAC'de (girişler 0 ya da 5 V) şu durumlar için $V_{out}$ nedir: hepsi 5 V; hepsi 0; yalnız V1 = 5 V; yalnız V2 = 5 V; yalnız V3 = 5 V?

> **Çözüm (derste verildi):** $V_{out}=-(V_1/R+V_2/2R+V_3/4R)\cdot4R/7$. Sırasıyla −5 V, 0 V, −20/7 V, −10/7 V, −5/7 V.

**6. (derste sözlü, 01:42:14)** R/2R merdiven DAC'nin binary weighted DAC'ye göre üstünlüğü nedir?

> **Çözüm (derste verildi):** Binary weighted DAC'de bit sayısı kadar farklı direnç değeri ve her biri için hassas tolerans gerekir; direnç değerleri büyür. R/2R'de yalnız birbirine yakın iki tür direnç (R ve 2R) vardır, iki tolerans hassas ayarlanarak daha iyi sonuç alınır.

**7. (derste sözlü, 01:50:43)** DAC0830'un kaç adres ucu vardır ve IO uzayında kaç bayt yer kaplar?

> **Çözüm (derste verildi):** Adres ucu yoktur; $2^0 = 1$ bayt yer kaplar.

**8. (ekrandan, 02:00:00)** 1000H adresindeki DAC0830 üzerinde `MOV DX,1000H / MOV AL,00H / TEKRAR: OUT DX,AL / CALL DELAY / INC AL / JMP TEKRAR` kodu çalıştırılıyor. (a) Ardışık iki değer arasındaki gerilim farkı nedir? (b) Çıkışta nasıl bir işaret oluşur?

> **Çözüm (derste verildi):** (a) 5 V/256 (bkz. 10.1'deki ders sonrası not). (b) FFH'den sonra AL 00H'ye döndüğü için 0'dan 5 V'a basamaklı yükselip 0'a düşen testere dişi dalga.

**9. (derste sözlü, 01:26:20)** Sıcaklığı elektriksel analog değere çevirmek için nasıl bir transducer kullanılabilir?

> **Çözüm (derste verildi):** Sıcaklıkla iç direnci değişen bir eleman, örneğin NTC ya da termistör; gerilim bölücüyle analog gerilim elde edilir.

## Dersin Toparlaması

Dersin ilk yarısında 8254 konusu iki örnekle kapatıldı. İlk örnekte tek sayıcının 2 MHz'ten en fazla ≈30 Hz'e inebildiği görüldü ve iki sayıcı mod 2'de kaskat bağlanarak 1 Hz'lik pulse üretildi; adres çözümleme, tek adresler için veri yolunun yüksek baytı, BCD sayma değerleri ve osiloskopta doğrulama bu örnekte işlendi. İkinci örnek olan frekansmetrede iki sayıcı mod 3'te 0,5 Hz'lik bir referans kare dalga üretti, bu dalga üçüncü sayıcının GATE ucunu sürerek tam 1 saniyelik sayım sağladı; read-back komutuyla durum baytı okunarak OUT1'in düşüşü yakalandı, mod 0'ın OUT ucuyla taşma algılandı ve sayma değeri 9999'dan çıkarılarak frekans bulundu.

İkinci yarıda ADC/DAC konusuna geçildi: fiziki dünyanın analog, işlemcinin sayısal olması nedeniyle dönüştürücülere ihtiyaç duyulduğu, transducer kavramı ve işaretlerin zamanda/genlikte sürekli ya da ayrık olmasına göre sınıflandırılması anlatıldı. Binary weighted DAC ve R/2R merdiven DAC opamp bağıntıları ve Thevenin eşdeğeriyle çözüldü, DAC0830 bir kara kutu olarak tanıtıldı ve sayaçla sürülen bir DAC'nin testere dişi dalga ürettiği gösterildi. Sonraki derste bu konunun kısaca tekrar edilip ADC yapılarına (paralel ADC, ramp converter ADC, ADC0804) geçilmesi planlanıyor.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
