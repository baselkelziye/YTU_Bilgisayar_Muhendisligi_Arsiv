# Ders 22 Genişletilmiş Notu: 8254 Uygulamaları (Kaskat Sayıcılar, Frekans Ölçer) ve DAC

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. 8254 ile saniyede bir darbe: kaskat bağlı sayıcılar
- 2. 8254 ile frekans ölçer
- 3. DAC ve ADC'ye neden ihtiyaç var?
- 4. Analog ve dijital sinyal
- 5. DAC mimarileri: binary weighted ve R/2R merdiven
- 6. DAC0830 entegresi
- 7. DAC örneği: testere dişi dalga ve çözünürlük
- 8. Birinci ara sınavın çözümü
- Örnek Sorular

## 1. 8254 ile saniyede bir darbe: kaskat bağlı sayıcılar

Ders, önceki derste anlatılan 8254 Programlanabilir Aralık Zamanlayıcısının örnekleriyle başladı. Hoca, bu örneklerin teori kısmından daha karmaşık olduğunu, laboratuvar sorularının ise önceki dersteki bilgilerle çözülebileceğini söyledi.

### 1.1 Problem

Ekranda gösterilen soru şuydu (ekrandan, 00:20:00):

> A9H adresinden itibaren ardışık tek adreslere yerleştirilmiş 8254 (simülasyonda 8253) kullanarak periyodik olarak 1 saniyede bir darbe (pulse) işareti üretin. 8254 için yalnız 2 MHz frekansında bir saat işareti olduğunu düşünün.

Ardışık tek adresler kuralına göre Counter 0 A9H, Counter 1 ABH, Counter 2 ADH ve kontrol yazmacı AFH adresindedir.

### 1.2 Tek sayıcı neden yetmez?

Bir sayıcıya binary modda yazılabilecek en büyük sayma değeri 65536'dır. 2 MHz bu değere bölünürse

$$\frac{2\times10^6}{65536} \approx 30\ \text{Hz}$$

elde edilir. Oysa istenen 1 Hz'tir; 2 MHz'i çok daha büyük bir sayıya, toplam $2\times10^6$'ya bölmek gerekir. Hoca öğrencilere bunun ne anlama geldiğini sordu. Sonuç: tek bir sayıcıyla, en büyük değer yazılsa bile, 2 MHz'lik bir işaret 1 Hz'e indirilemez.

### 1.3 Kaskat bağlantı

Çözüm iki sayıcıyı **kaskat** bağlamaktır: birinin çıkışı (OUT) diğerinin saat girişine (CLK) bağlanır. Böylece bölme oranları çarpım olarak etki eder ve sistem sanki 16 + 16 = 32 bitlik tek bir sayıcıymış gibi çalışır. $2\times10^6 = 2000 \times 1000$ olduğundan biri 2000'e, diğeri 1000'e bölerse çıkış

$$\frac{2\times10^6}{2000\times1000} = 1\ \text{Hz}$$

olur. Öndeki sayıcı arkadakine saat ürettiği için bir kare dalga (mod 3) üretmesi uygundur. Arkadaki sayıcıdan saniyede bir **darbe** istendiği için o da periyodik darbe üreten mod 2'de çalışır.

Ekrandaki cevap metninde her iki sayıcının da mod 2'de ayarlanması gerektiği yazıyordu (ekrandan, 00:20:00). Hoca anlatımında öndeki sayıcının mod 2 ya da mod 3'te olabileceğini, fark etmeyeceğini söyledi ve pratik açıdan mod 3'ü önerdi.

### 1.4 Devre

Proteus'taki devrede Counter 0'ın CLK girişine 2 MHz bağlıdır, Counter 0'ın OUT ucu Counter 1'in CLK girişine gider (ekrandan, 00:30:00). GATE uçları lojik 1'dedir. Mod 2 ve mod 3'te GATE yalnız duraklatma için kullanıldığından, 1'de olması sayıcıların kesintisiz çalışması demektir. Counter 1'in çıkışı ve izlemek amacıyla Counter 0'ın çıkışı osiloskoba bağlanmıştır.

### 1.5 Kod

Program iki adımlıdır: önce sayıcıların modu ayarlanır, sonra sayma değerleri gönderilir. Bundan sonra yazılımın başka işi yoktur; darbeyi donanım kendisi üretir, program sonsuz döngüde bekler.

```asm
MOV AL, 00110101B   ; Counter 0: SC=00, RW=11 (LSB sonra MSB), mod 2, BCD
OUT 0AFH, AL
MOV AL, 01110101B   ; Counter 1: SC=01, RW=11, mod 2, BCD
OUT 0AFH, AL
XOR AL, AL          ; AL = 00H
OUT 0A9H, AL        ; Counter 0 LSB
OUT 0ABH, AL        ; Counter 1 LSB
MOV AL, 20H
OUT 0A9H, AL        ; Counter 0 MSB -> 2000 (BCD)
MOV AL, 10H
OUT 0ABH, AL        ; Counter 1 MSB -> 1000 (BCD)
ENDLESS:
```

(ekrandan, 00:25:00)

Kontrol sözcüklerinin çözümü:

| Kontrol sözcüğü | SC1 SC0 | RW1 RW0 | M2 M1 M0 | BCD | Anlamı |
|---|---|---|---|---|---|
| `00110101B` | 00 | 11 | 010 | 1 | Counter 0, LSB/MSB, mod 2, BCD |
| `01110101B` | 01 | 11 | 010 | 1 | Counter 1, LSB/MSB, mod 2, BCD |

Sayma tipi BCD seçildiği için değerler BCD olarak yazılmalıdır. 2000'in dört BCD basamağı 2, 0, 0, 0'dır (0010 0000 0000 0000), yani gönderilecek değer `2000H`'tir. 1000 için de `1000H` gönderilir.

> **Hocanın vurgusu:** BCD modda saydırılacak bir sayıcıya 1000 ondalık (03E8H) gönderilirse yanlış sonuç elde edilir; BCD karşılığı olan 1000H gönderilmelidir.

RW = 11 seçildiği için her sayıcıya önce düşük anlamlı bayt, sonra yüksek anlamlı bayt yazılır. İki sayma değerinin de düşük baytı 00H olduğu için önce 00H üretilip iki sayıcıya da gönderilir, sonra Counter 0'a 20H, Counter 1'e 10H gönderilir. Buradan şu sonuç çıkar: iki sayıcıya değerler parça parça ve karışık sırayla yazılabilir; önce birinin iki baytını bitirip sonra diğerine geçmek zorunlu değildir.

### 1.6 Osiloskopla doğrulama

Kod çalıştırıldığında osiloskobun B kanalında (Counter 1'in çıkışı) tam 1 saniye aralıklı darbeler görüldü. Yaklaştırıldığında mod 2 çıkışının bir saat çevrimi boyunca 0, diğer bütün zamanlarda 1 olduğu görülür. Counter 0'ın çıkışı ise 2 MHz'i 2000'e böldüğü için 1 kHz olmalıdır; osiloskopta bir periyodu 1 ms ölçüldü. Yani Counter 0 1 kHz'lik bir işaret üretir, Counter 1 bunu 1000'e bölerek 1 Hz'lik darbe üretir.

**Soru:** Önce 1000'e, sonra 2000'e bölseydik son çıkışta bir şey değişir miydi?
**Cevap:** Değişmez. Hoca bunu simülasyonda gösterdi: son çıkış yine saniyede bir darbe üretti (osiloskopta 0.1 s/bölmelik ekranda 10 bölme). Ara çıkış ise artık 2 kHz oldu: periyodu 500 µs ölçüldü ve $1/(500\times10^{-6}) = 2\times10^3$ Hz. Daha küçük bir sayıya bölündüğü için ara frekans yükselir, ama kaskat yapıda son sonuç aynı kalır.

## 2. 8254 ile frekans ölçer

Hoca bu örneğin biraz karmaşık olduğunu belirtti. Örnek, ekranda açılan "Frequency Counter by using 8254 PIT with Hardware and Software" başlıklı belgeden anlatıldı (ekrandan, 00:35:00).

### 2.1 Mantık

Frekans ölçer, bir sinyalin bir saniye boyunca kaç kez 0-1 (ya da 1-0) geçişi yaptığını sayar; bir saniyedeki değişim sayısı sinyalin frekansıdır. Bunun için üç şey gerekir:

- **Bir saniyelik hassas bir zaman penceresi.** 2 MHz'lik saatle bu, önceki örnekteki gibi kaskat bağlı iki sayıcıyla elde edilir.
- **Geçişleri sayan bir sayıcı.** 8254 sayıcıları saat girişinin düşen kenarında sayma değerini bir azaltır. Yalnız 1-0 geçişlerini saymak frekansı bulmak için yeterli olduğundan, ölçülecek sinyal doğrudan bir sayıcının saat girişine bağlanabilir.
- **Ölçüm sınırı.** En fazla 9999 Hz ölçülmek istenir; daha yüksek frekanslarda sistem "aralık dışı" (out of range) uyarısı vermelidir. Sayıcı aşağı saydığı için 9999 ilk değeriyle başlatılır. Bir saniye dolmadan sıfıra ulaşırsa 10000 geçiş olmuş demektir ve sinyal aralık dışıdır. Sıfıra ulaşmazsa frekans, 9999'dan kalan değer çıkarılarak bulunur. Hoca örnek verdi: 9999'dan başlayan sayıcı bir saniye sonunda 999'da ise $9999 - 999 = 9000$ adım saymıştır, frekans 9000 Hz'tir.

### 2.2 Donanım bağlantısı

Bağlantı şeması (ekrandan, 00:40:00):

```text
2 MHz ----------> CLK0   Counter 0 (N0'a böler)   GATE0 <- +5V
                  OUT0 -> CLK1
                         Counter 1 (N1'e böler)   GATE1 <- +5V
                  OUT1 -> GATE2
f_in -----------> CLK2   Counter 2 (olay sayıcı)  OUT2 -> izlenir
Veri yolu D7-D0, RD, WR, A0, A1, CS
G/Ç adresleri: F0H Counter 0, F1H Counter 1, F2H Counter 2, F3H kontrol yazmacı
```

Counter 1'in çıkışı Counter 2'nin GATE ucuna bağlıdır. Bunun anlamı: OUT1 = 1 iken Counter 2 sayar, OUT1 0'a düştüğünde Counter 2'nin sayması durur.

İstenen, 1 saniye 1'de ve 1 saniye 0'da kalan, yani periyodu 2 s (frekansı 0.5 Hz) olan bir kare dalgadır. Bunun için toplam bölme oranı

$$\frac{2\times10^6}{0.5} = 4\times10^6 = 2000\times2000$$

olmalıdır. Counter 0 ve Counter 1 mod 3'te (kare dalga) ve ikisi de 2000 sayma değeriyle yüklenir. Counter 0'ın çıkışı 1 kHz, Counter 1'in çıkışı 0.5 Hz'lik kare dalga olur. Belgede de aynı hesap vardır: $2\times10^6/(2000\times2000) = 0.5$ Hz; 0.5 Hz'lik kare dalganın periyodu 2 s'dir (ekrandan, 00:45:00).

Counter 2 mod 0'da çalışır. Mod 0'da çıkış 0'da başlar, sayma bitince 1'e çıkar ve tek seferliktir; bu yüzden her ölçüm çevriminde Counter 2 mod 0'da ve 9999 değeriyle yeniden yüklenmelidir.

Ölçüm akışı şöyledir: OUT1 1'de olduğu bir saniye boyunca GATE2 aktiftir ve Counter 2 $f_{in}$'in düşen kenarlarını sayar. Bir saniye biter bitmez OUT1 0'a düşer ve sayma hassas biçimde durur. OUT1'in 0 kaldığı bir saniyelik boşlukta yazılım Counter 2'yi okur, 9999'dan çıkarır ve frekansı hesaplar. Sayma daha önce sıfıra düşmüş ve OUT2 1'e çıkmışsa aralık dışı hatası verilir.

### 2.3 Kodun ayar kısmı

```asm
        mov al,00110110B  ; counter 0, mode3, binary
        out 0f3h,al       ; control port
        mov al,01110110B  ; counter 1, mode3, binary
        out 0f3h,al       ; control port
; Make each counter a divide-by 2000 (07D0H)
        mov al,0d0h       ; LSB
        out 0f0h,al       ; counter 0
        out 0f1h,al       ; counter 1
        mov al,07h        ; MSB
        out 0f0h,al       ; counter 0
        out 0f1h,al       ; counter 1
; Make counter 2 an event counter
cycle:  mov al,10110001B  ; counter 2, Mode 0, BCD
        out 0f3h,al       ; control port
        mov al,99h        ; initial count is 9999
        out 0f2h,al       ; LSB
        out 0f2h,al       ; MSB
```

(ekrandan, 00:35:00 ve 01:00:00)

Counter 0 ve 1 binary modda, önce LSB sonra MSB yazılacak şekilde mod 3'te ayarlanır. 2000'in onaltılık karşılığı 07D0H'dir; iki sayıcıya aynı değer yazılacağı için önce iki sayıcıya da D0H, sonra 07H gönderilir. Bu noktadan sonra iki sayıcı da 2000 ilk değeriyle saymaya başlar.

Counter 2 olay sayıcıdır: saat girişinde sabit frekanslı bir işaret değil, sayılacak olaylar vardır. Mod 0'da, BCD olarak ayarlanır. 9999 BCD olarak 99H 99H'dir; bu yüzden aynı 99H değeri hem LSB hem MSB olarak gönderilir. `cycle` etiketi, her ölçümden sonra buraya dönülerek Counter 2'nin yeniden yüklenmesini sağlar.

### 2.4 OUT1'in beklenmesi: read-back ile durum okuma

OUT ucunun durumunu öğrenmenin yolu durum baytıdır (status byte); durum baytının en yüksek anlamlı biti OUT ucunun değeridir. Durum baytı yalnız read-back komutuyla okunabilir: kontrol yazmacına read-back komutu yazılır, ardından ilgili sayıcının adresinden yapılan okuma durum baytını verir.

```asm
stat:   mov al,0e4h       ; Read-back counter 1 ( 11 10 0100B )
        out 0f3h,al       ; control port
        in  al,0f1h       ; counter 1 status
        rol al,1          ; move out1 to carry
        jc  stat          ; wait until low
```

(ekrandan, 00:50:00)

Burada önce Counter 1'e bakılır, çünkü hesaplamaya ne zaman geçileceğini Counter 1'in çıkışı belirler. `0E4H = 1110 0100B` read-back komutudur. Sayma tutma (COUNT) ve durum tutma (STATUS) bitleri aktif 0'dır: COUNT = 1 olduğu için sayma tutulmaz, STATUS = 0 olduğu için durum tutulur; seçim bitlerinden yalnız Counter 1'inki 1'dir. Durum Counter 1'in adresi olan F1H'den okunur. `rol al,1` ile en yüksek bit (OUT1) carry bayrağına düşer. OUT1 1 olduğu sürece döngüde beklenir, yani sayma devam eder. Döngüden çıkıldığında OUT1 0'a düşmüştür ve GATE2'ye bağlı olduğu için Counter 2'nin sayması da otomatik olarak durmuştur.

### 2.5 Counter 2'nin okunması ve taşma kontrolü

```asm
        mov al,0c8h       ; Read-back counter 2 ( 11 00 100 0B )
        out 0f3h,al       ; control port
        in  al,0f2h       ; First read is status
        rol al,1          ; Test out
        jc  ovflw         ; If set then overflow
; Read the count and adjust for display
        in  al,0f2h       ; get LSB
        call adj          ; call subroutine to subtract from 99
        inr al            ; first clock pulse not counted
        out 0,al          ; LSB display assumed at port 0
        in  al,0f2h       ; get MSB
        call adj          ; call subroutine to subtract from 99
        out 1,al          ; MSB display assumed at port 1
        jmp cycle         ; Next cycle
; If overflow then come here and show FF in display
ovflw:  in  al,0f2h       ; finish the reads
        in  al,0f2h
        mov al,0ffh       ; overflow code
        out 0,al          ; LSB display
```

(ekrandan, 00:50:00 ve 00:55:00)

Counter 2'de hem durum hem sayma değerine bakılmalıdır. Durum, OUT2'nin 1'e çıkıp çıkmadığını (aralık dışı) gösterir; sayma değeri ise kaç kenar sayıldığını. `0C8H = 1100 1000B` komutu Counter 2 için hem sayma hem durumu tutar (iki bit de 0). Hem sayma hem durum read-back ile tutulduğunda ilk okuma durum baytını, ikinci ve üçüncü okumalar sayma değerinin LSB ve MSB'sini verir.

İlk okumada OUT2 biti carry'ye alınır. Carry 1 ise Counter 2 9999 adımı çoktan bitirmiş, OUT2 1'e çıkmıştır: taşma vardır. Taşma durumunda sayma değeri hâlâ tutulu durumdadır ve tutulan değer okunmadan yeniden tutma yapılamaz. Bu yüzden `ovflw` kısmında iki boş okuma yapılır, sonra göstergeye FFH gönderilir; göstergenin bu kodla "aralık dışı" yazdığı varsayılabilir.

> **Hocanın vurgusu:** Taşma kolundaki iki boş okuma önemlidir. Durum ve sayma birlikte tutulduğunda yalnız durum okunup bırakılırsa sayma değerleri tutulu kalır ve bir sonraki çevrimde yeniden tutma yapılamaz.

Taşma yoksa ikinci okumayla LSB okunur ve `adj` alt programı çağrılır. Hoca `adj`'nin AL'yi BL'ye aldığını, AL'ye 99 yazdığını ve okunan değeri 99'dan çıkardığını anlattı; amaç, değerin 9999'dan kaç adım azaldığını bulmaktır. Bu işlem düşük ve yüksek anlamlı kısım için birbirinden bağımsız yapılabilir. <!-- BELİRSİZ: adj alt programının kodu karelerde görünmüyor. --> Sonuç port 0'daki göstergeye yazılır. Üçüncü okumayla MSB okunur, yine `adj` ile 99'dan çıkarılır ve port 1'deki göstergeye yazılır. Ardından `cycle` etiketine dönülür ve Counter 2 yeniden mod 0'da, BCD, 9999 ile yüklenir. Yeni sayma değeri OUT1'in bir sonraki 1'e geçişinden sonra etkin olur.

Belgedeki `inr al` satırı için hoca, buraya yanlış bir şey gelmiş olabileceğini söyledi. <!-- BELİRSİZ: "inr" 8085 komutudur, 8086'da karşılığı INC'dir; satırın açıklaması ("first clock pulse not counted") derste ayrıca anlatılmadı. -->

> **Ek bilgi (derste anlatılmadı):** BCD olarak 99H'den bir bayt çıkarılırken her basamak $9-d \geq 0$ olduğundan basamaklar arası ödünç oluşmaz; bu yüzden düz `SUB` sonucu doğrudan geçerli bir BCD değeridir. Ancak bu sonuca 1 eklenirse (ör. 09H + 1) BCD düzeltmesi gerekebilir; 8086'da bu iş `DAA` ile yapılır.

### 2.6 Dalga şekli üzerinden özet ve sayısal örnek

Belgedeki dalga şekli üzerinden akış: OUT1 1'de iken Counter 2 9999'dan geriye doğru sayar; OUT1 0'a düşünce Counter 2 durur; Counter 2 okunur ve 9999'dan çıkarılır; hesap bittikten sonra Counter 2 yeniden yüklenir.

Belgedeki örnek (ekrandan, 00:45:00): OUT1 0'a düştükten hemen sonra Counter 2'de 3275 bulunuyorsa CLK2 girişinin frekansı

$$f = 9999 - 3275 = 6724\ \text{Hz}$$

olur.

Hoca, Counter 2'nin neden tekrarsız mod 0'da olduğunu da açıkladı: OUT2'nin 1'e çıkışı bir taşma göstergesidir. Tekrarlı bir mod kullanılsaydı çıkış yeniden değişebilir ve bu 1 hali kaçırılabilirdi.

**Soru:** CLK2'ye bağlanan $f_{in}$ tam olarak nedir?
**Cevap:** Frekansı ölçülmek istenen, frekansı bilinmeyen sinyaldir. Sayıcı olarak kullanıldığı için periyodik olmak zorunda değildir. Hoca düzensiz aralıklı dört düşen kenarı olan bir sinyal çizdi: bir saniyede dört kenar varsa sinyal periyodik olmasa bile ortalamada 4 Hz'lik bir sinyal gibi düşünülebilir. Yani bu yöntemle bulunan değer, bir saniyedeki değişim sayısından elde edilen ortalama frekanstır.

## 3. DAC ve ADC'ye neden ihtiyaç var?

Aradan sonra 8254'ün tamamlandığı söylendi ve yeni bir yardımcı devre konusu olan dijital-analog (DAC) ve analog-dijital (ADC) dönüştürücülere geçildi. Plan şuydu: DAC için iki farklı yaklaşım, DAC0830 entegresi ve bir örnek; ADC için iki yöntem, ADC0804 entegresi ve bir örnek. Bu derste DAC kısmı işlendi, ADC sonraki derse kaldı.

Slayttaki temel fikir (ekrandan, 01:15:00):

- µP dijital değerlerle çalışır, ama fiziki dünya analogdur.
- Sıcaklık, basınç, nem, hız, ses gibi büyüklükler analog değerlerdir.
- Fiziki dünya ile µP arasında etkileşim için analog↔dijital dönüştürücü gerekir.

Fiziki büyüklükler ayrık değil süreklidir: sürekli her $t$ anı için ölçülebilirler ve aldıkları değer de süreklidir.

### 3.1 Fan örneği

Hoca bir senaryo verdi: odadaki sıcaklık ölçülüyor ve buna göre bir fan çalıştırılıyor. Sıcaklık sürekli bir değer olduğu için önce dijitale çevrilmelidir. Mikroişlemci bu dijital değeri referans değerlerle karşılaştırır: örneğin ölçülen değer 100'ün üzerindeyse fan hızlı, 200'ün üzerindeyse çok hızlı dönsün, ya da aradaki değerlere göre ölçekli bir hızda dönsün. Fanı belirli bir hızda döndürmek için motor sürücüsüne belirli bir analog gerilim uygulamak gerekir. Bu kez dijital hız bilgisinin analog bir gerilime çevrilmesi gerekir.

Bir ayrıntı daha vardır: dijital sistemler elektriksel seviyelerle çalışır. Sıcaklık ise ısıya ait ayrı bir fiziki enerjidir; önce elektriksel bir işarete dönüştürülmelidir. Aynı şekilde DAC'ın ürettiği elektriksel analog seviye de fan hızı gibi başka bir enerji türüne dönüştürülmelidir. ADC'nin önünde ve DAC'ın arkasında enerji türleri arasında dönüşüm yapan bu elemana **transducer** (dönüştürücü) denir.

Slayttaki akış (ekrandan, 01:20:00):

```text
Fiziki Dünya --Sıcaklık (analog)--> Transducer --Elektriksel (analog)--> ADC
ADC --Elektriksel (dijital)--> µP
µP --İşlenmiş Veri (elektriksel-dijital)--> DAC
DAC --Elektriksel (analog)--> Transducer --Fan Hızı (analog)--> Fiziki Dünya
```

### 3.2 ADC ve çözünürlük

ADC elektriksel analog değeri elektriksel dijital değere çevirir. Belirli bir en küçük ve en büyük giriş gerilimi arasında ölçüm yapar ve bu aralığı doğrusal olarak sayısal değerlere eşler. Üretilen değerlerin aralığı çözünürlüğe bağlıdır: 8 bitlik bir ADC 00H ile FFH, yani 0 ile 255 arasında değer üretir. Giriş 0-5 V ise 0 V'a 00H, 5 V'a FFH karşılık gelir. 10 bitlik bir ADC ise 0 ile 1023 arasında, toplam 1024 ayrık değer üretir.

> **Ders sonrası not:** Hoca 8 bitlik örneği anlatırken bir an "5 volta karşılık 1023" dedi (01:21:23). 1023, 10 bitlik dönüştürücünün en büyük değeridir; 8 bitte 5 V'a FFH (255) karşılık gelir. Hoca hemen ardından 8 bit için 0-255, 10 bit için 0-1023 aralığını doğru verdi.

Ölçülmek istenen büyüklük her zaman analogdur ama elektriksel olmayabilir (sıcaklık, basınç). ADC girişine bağlanabilmesi için önce bir transducer ile elektriksel analog değere çevrilmelidir. Hoca devre laboratuvarlarından örnek verdi: sıcaklıkla ya da ışıkla direnci değişen elemanlar uygun koşullama devresiyle bağlanırsa ortam ışığına ya da sıcaklığına göre değişen analog bir gerilim elde edilir. Bu elemanlar birer transducer'dır.

### 3.3 DAC

DAC'ın girişi sayısal bir değerdir (8 bit, 10 bit), çıkışı ise elektriksel analog bir değerdir. Fan örneğinde mikroişlemci DC motorun uçlarına uygulanacak gerilimi hesaplar, DAC bu değeri analog gerilime çevirir. Motorun kendisi de bir transducer'dır: uçlarına bağlanan gerilimi fan hızına çevirir.

**Soru:** 0-5 V aralığında çalışan 8 bitlik bir DAC'ın girişine 7FH verilirse çıkış kaç volt olur?
**Cevap:** 7FH = 0111 1111B = 127, yani 255'in yaklaşık yarısıdır. 00H verilseydi 0 V, FFH verilseydi 5 V çıkacaktı. 7FH tam ortaya karşılık geldiği için çıkış 2.5 V olur.

> **Ders sonrası not:** Tam hesapla $127/255 \times 5 \approx 2.49$ V'tur; derste yuvarlanarak 2.5 V denmiştir.

## 4. Analog ve dijital sinyal

Slayttaki tablo dört sinyal türünü karşılaştırır (ekrandan, 01:30:00):

| | Zamanda sürekli | Zamanda ayrık |
|---|---|---|
| Genliği sürekli | Analog sinyal (sürekli bir eğri) | Belirli anlarda örneklenmiş, genliği herhangi bir gerçel değer olabilen sinyal |
| Genliği ayrık | Her an tanımlı, ama yalnız belirli seviyelerde değer alan basamaklı sinyal | Dijital (sayısal) sinyal: belirli anlarda, belirli seviyelerde |

- **Sol üst:** Her sürekli $t$ anı için bir değere sahiptir. Ne kadar yakınlaşılırsa yakınlaşılsın ($t = 1.00001$, $t = 1.0000001$, ...) her an için değer alır ve bu değer de süreklidir. Bu sinyal **analog** sinyaldir.
- **Sağ üst:** Yalnız belirli aralıklarla değer alır, yani zamanda ayrıktır; ama aldığı değer herhangi bir gerçel sayı olabilir (genlikte sürekli).
- **Sol alt:** Her $t$ anı için değer alır, ama genliği yalnız belirli seviyelerden biri olabilir: zamanda sürekli, genlikte ayrık.
- **Sağ alt:** Hem zamanda hem genlikte ayrıktır; değerler kuantalanmış seviyelerden biridir. Bu sinyal **sayısal (dijital)** sinyaldir.

Köşegen dışındaki iki sinyal sayısal sinyal değildir. Genliği sürekli olan sinyalin genliği bilgisayarda ifade edilemez, çünkü sonsuz küsuratlı bir değer olabilir. Zamanda sürekli olan sinyal ise sonsuz sayıda örnekle ifade edilmesi gerektiği için örnekleme açısından ifade edilemez.

## 5. DAC mimarileri: binary weighted ve R/2R merdiven

### 5.1 Binary weighted DAC

Slayttaki devre (ekrandan, 01:35:00):

```text
MSB --[R ]--+
    --[2R]--+--(eksi giriş)--+--[4R/7]--+
LSB --[4R]--+                |          |
                       op-amp (artı giriş toprakta) --> Vout
```

Bu yapı bir toplayıcı op-amp devresidir. Sol taraftaki girişlere en anlamlı bitten en az anlamlı bite doğru dijital değerin bitleri bağlanır; elektriksel olarak 1 için 5 V, 0 için 0 V düşünülür. Her kol bir direnç üzerinden ortak bir düğüme bağlıdır.

İdeal op-amp'ın iki özelliği kullanılır: eksi ve artı girişler arasındaki gerilim eşittir ve girişlerden içeri akım akmaz. Artı giriş toprağa bağlı olduğu için 0 V'tur, dolayısıyla eksi giriş de 0 V'tur. Her koldaki akım (5 V - 0 V)/direnç kadardır. LSB'ye doğru direnç iki katına çıktığı için akım yarıya iner; en büyük katkıyı MSB yapar. Kol akımlarının toplamı eksi girişe akamayacağı için tamamen geri besleme direnci üzerinden döner ve $V_{out}$'u belirler. Her basamakta katkının iki kat azalması, ikilik bir sayının ondalık karşılığının hesaplanmasına benzer.

Girişler 1-1-1 (hepsi 5 V) için hesap:

$$I = \frac{5}{R} + \frac{5}{2R} + \frac{5}{4R} = \frac{20+10+5}{4R} = \frac{35}{4R}$$

$$\frac{0 - V_{out}}{4R/7} = \frac{35}{4R} \quad\Rightarrow\quad V_{out} = -\frac{35}{4R}\cdot\frac{4R}{7} = -5\ \text{V}$$

Girişler 0-0-0 iken hiç akım akmaz ve çıkış 0 V olur. Aradaki değerler doğrusal olarak ölçeklenir. Her kolda bir öncekinin iki katı direnç kullanılarak n bitlik bir DAC elde edilebilir.

Bu yapının dezavantajı, toleransı düşük (hassas) ve her kol için birbirinden farklı dirençler gerektirmesidir; imalatı zordur.

### 5.2 R/2R merdiven DAC

İkinci yapı yalnız iki direnç değeri kullanır: R ve 2R (ekrandan, 01:40:00). Hoca süperpozisyon mantığıyla yalnız LSB kolunu ele aldı. LSB girişi 2R üzerinden bir düğüme, o düğüm de 2R üzerinden toprağa bağlıdır; bu bir gerilim bölücüdür ve düğümde LSB/2 gerilimi oluşur. Bu iki paralel 2R'nin eşdeğeri R'dir; buna seri R eklenince yine 2R olur ve bir sonraki düğümde başlangıçtaki 2R-2R durumunun aynısı tekrarlanır. Böylece her düğümde gerilim yarıya bölünür (örneğin bir düğümde X ise sonrakinde X/2) ve sonuçta yapı yine toplayıcı op-amp mantığına dönüşür. Avantajı, yalnız iki farklı direnç değeriyle aynı sonucu vermesidir.

İki yaklaşım da op-amp temelli toplayıcı devrelerdir.

## 6. DAC0830 entegresi

8086'ya bağlanabilecek DAC entegresi olarak DAC0830 incelendi (ekrandan, 01:45:00). Derste entegrenin iç bağlantıları hazır yapılmış kabul edilir; dışarıdan görülen uçlar şunlardır:

- 8 veri ucu (DI0-DI7; şemada AD0-AD7'ye bağlı),
- $\overline{CS}$ (chip select; şemada $\overline{IO8}$ sinyaline bağlı),
- $\overline{WR}$ (write; WR1),
- analog çıkış (çıkıştaki op-amp üzerinden).

VREF'e -5 V verilir. Hoca bunun sebebini şöyle açıkladı: içerideki ters çeviren op-amp devresi -5 V üretiyordu; VREF'e -5 V vermek bunu ters yönde dengeler. Böylece çıkış 0 ile 5 V arasında olur: 00H için 0 V, 7FH için 2.5 V, FFH için 5 V ve aradaki değerler doğrusal ölçeklidir (ekrandan, 01:50:00).

**Soru:** Bu entegrenin kaç adres ucu var?
**Cevap:** Hiç yok. Bir öğrenci $\overline{IO8}$ ve WR uçlarını önerdi, ama $\overline{IO8}$ başka bir yerden gelip chip select'e giden bir sinyaldir, WR de yazma ucudur. AD uçları da adres değil veri uçlarıdır: 8254, 8255, 8251 gibi entegrelerde olduğu gibi mikroişlemcinin veri uçlarına bağlanırlar.

**Soru:** 8086'nın G/Ç uzayına yerleştirildiğinde kaç bayt yer kaplar?
**Cevap:** 8255'in iki adres ucu vardı ve 4 bayt kaplıyordu; 8251'in bir adres ucu (C/$\overline{D}$) vardı ve 2 bayt kaplıyordu. DAC0830'un adres ucu olmadığı için 1 bayt kaplar. Yani "bu cihaz F0H adresine yerleştirilmiştir" gibi tek bir adres verilir. Adres çözme devresi o adres için chip select'i aktif eder; `OUT` işlemi yapıldığı için mikroişlemcinin WR ucu da 0 olur ve cihaza erişilir.

Kullanımı:

```asm
MOV AL, 0FFH        ; ya da 00H, 7FH ...
OUT DAC_ADDR, AL
```

(ekrandan, 01:50:00)

> **Hocanın vurgusu:** Bu entegrenin püf noktası, hiç adres ucu olmaması ve çalışma mantığıdır: cihazın adresine yapılan her `OUT` ile gönderilen veri, 0-255 aralığından 0-5 V aralığına ölçeklenmiş bir analog çıkış üretir.

### 6.1 Zamanlama

`OUT` komutu yürütüldüğünde DAC'ın adresiyle işlem yapıldığı için adres çözme devresi cihazı seçer ($\overline{CS}$ 0'a düşer). `OUT` bir yazma işlemi olduğundan $\overline{WR}$ da 0'a düşer. Bunlardan önce mikroişlemci AL'deki değeri veri uçlarına koyar. DAC değeri aldıktan sonra merdiven ya da binary weighted yapının kararlı bir analog değer üretmesi biraz zaman alır; çıkış bir süre sonra sabit bir seviyeye oturur (settle).

## 7. DAC örneği: testere dişi dalga ve çözünürlük

Slayttaki örnek (ekrandan, 01:55:00):

```asm
MOV DX, 1000H
MOV AL, 00H
TEKRAR:
OUT DX, AL
CALL DELAY
INC AL
JMP TEKRAR
```

DAC0830 1000H adresine yerleştirilmiştir. Adres 8 bite sığmadığı için port adresi DX üzerinden verilir. AL 0'dan başlar, 1000H portuna gönderilir, bir süre beklenir, AL artırılır ve başa dönülür. Bekleme, DAC'ın gönderilen değeri alıp analog çıkışı oturtmasına yetecek kadar süre tanımak içindir.

Çizim adım adım yapıldı: 00H için 0 V, FFH için 5 V. Her adımda değer bir arttığında gerilimin ne kadar arttığı soruldu.

**Soru:** Sayısal değer bir arttığında analog çıkış ne kadar artar?
**Cevap:** 00H'den FFH'ye 256 farklı değer, ama 255 aralık vardır. Bir adım toplam aralığın $1/255$'i, gerilim olarak

$$\frac{1}{255}\times 5 \approx 0.0196 \approx 0.02\ \text{V}$$

kadardır. Hoca, bir öğrencinin önerdiği "3/32" gibi bir değerin doğru olmadığını, 0.02 V cevabının ise doğru olduğunu belirtti.

Gerilim her adımda yaklaşık 0.02 V artar, 7FH'de yaklaşık 2.5 V'a, FFH'de 5 V'a ulaşır. FFH'den sonra `INC AL` 8 bitlik AL'yi 00H'ye döndürür ve gerilim yeniden 0'dan artmaya başlar. Çıkıştaki dalga şekli **testere dişi** dalgadır.

Bir adımlık artış DAC'ın **çözünürlüğüdür**. 8 bitlik DAC için $5/255$ V'tur. DAC 10 bitlik olsaydı ve yine 0-5 V aralığında çalışsaydı adım sayısı 1023 olur ve çözünürlük $5/1023 \approx 0.0049$ V olurdu.

## 8. Birinci ara sınavın çözümü

Dersin son kısmında hoca, bu grupta çözülemeyen birinci ara sınavın sorularını cevap belgesinden özetledi (ekrandan, 02:00:00-02:20:00). Soruların metni ve çözümleri aşağıdaki Örnek Sorular bölümündedir. Sınav ikinci kısmında iki renkli 3x3 LED matris, iki 8255 ve bir tuş tarama entegresiyle bir tic-tac-toe oyunu tasarımı üzerine kuruluydu.

### 8.1 Sistemin tanımı

- Adres çözme devresinin iki çıkışı vardır: biri LED matrisin bağlı olduğu birinci 8255'i, diğeri tuş tarama entegresinin bağlı olduğu ikinci 8255'i seçer.
- Her iki renkli LED'in R ve G girişi vardır (ekrandan, 02:15:00):

| R girişi | G girişi | Renk |
|---|---|---|
| 0 | 0 | Sönük |
| 0 | 1 | Yeşil |
| 1 | 0 | Kırmızı |
| 1 | 1 | Sarı |

- Aynı satırdaki LED'lerin R uçları OAR, G uçları OAG pinleriyle, aynı sütundaki LED'lerin ortak katot uçları OK pinleriyle sunulur. Hoca bunun, üç basamaklı bir yedi parçalı (seven segment) gösterge sürmeye benzediğini söyledi: katotlar ortaktır, basamak seçilerek her basamakta değer oluşturulur. Fark, anotların kırmızılar ve yeşiller için ayrı ayrı ortaklanmış olmasıdır. LED numaraları sütun sütun gider: birinci sütunda 0, 1, 2; ikincide 3, 4, 5; üçüncüde 6, 7, 8.
- Tuş tarama entegresi basılan tuşu kendisi tarar ve tuş kodunu DCBA veri uçlarına koyar; geçerli veri olduğunu $\overline{DAV}$ = 0 ile bildirir. Karşı taraf veriyi alıp $\overline{ACK}$ gönderdiğinde veri ve $\overline{DAV}$ kaldırılır. 8255 mod 1'de kullanılınca ayrıca tuş tarama yazılımına gerek kalmaz.
- Oyun: yeşille oynayan oyuncu bir kare seçer, LED yeşil yanar. İkinci oyuncu daha önce seçilmiş bir LED'e basarsa o LED sarı yanar ve sarı kalır (hatalı tuş için kısmi bir hak kaybı). Kırmızı oyuncu daha önce basılmamış bir tuşa basınca o LED kırmızı olur, sarı olan LED de eski rengine döner. Yatayda ya da dikeyde aynı renkten üç LED olunca oyun biter.

## Örnek Sorular

**1. Kaskat sayıcıyla 1 Hz darbe** (ekrandan, 00:20:00)

A9H adresinden itibaren ardışık tek adreslere yerleştirilmiş 8254 kullanarak periyodik olarak 1 saniyede bir darbe işareti üretin. 8254 için yalnız 2 MHz'lik bir saat işareti vardır.

> **Çözüm (derste verildi):** Counter 0 A9H, Counter 1 ABH, Counter 2 ADH, kontrol yazmacı AFH'dedir. Tek sayıcıyla en düşük frekans $2\times10^6/65536 \approx 30$ Hz olduğu için iki sayıcı kaskat bağlanır: OUT0 → CLK1. Counter 0 2000'e, Counter 1 1000'e böler: $2\times10^6/(2000\times1000) = 1$ Hz. Counter 1 mod 2'dedir (periyodik darbe); Counter 0 mod 2 ya da mod 3 olabilir. Kod için bkz. Bölüm 1.5.

**2. Frekans ölçer** (ekrandan, 00:45:00)

Counter 0 ve 1 mod 3'te 2000'e bölen sayıcılar olarak programlanmış, sistem saati 2 MHz'tir. OUT1 0'a düştükten hemen sonra Counter 2'de 3275 bulunuyorsa CLK2 girişinin frekansı nedir?

> **Çözüm (derste verildi):** OUT1'in frekansı $2\times10^6/(2000\times2000) = 0.5$ Hz, periyodu 2 s'dir; Counter 2 tam 1 saniye sayar. 9999'dan başladığı için $f = 9999 - 3275 = 6724$ Hz.

**3. DAC çıkışı** (derste sözlü, 01:24:54)

0-5 V aralığında çalışan 8 bitlik bir DAC'ın girişine 7FH verilirse çıkış kaç volt olur?

> **Çözüm (derste verildi):** 7FH = 127, aralığın yaklaşık ortasıdır; çıkış yaklaşık 2.5 V'tur (tam olarak $127/255\times5 \approx 2.49$ V).

**4. DAC0830'un adres uçları ve G/Ç uzayında kapladığı yer** (derste sözlü, 01:44:08 ve 01:45:30)

DAC0830'un kaç adres ucu vardır? 8086'nın G/Ç uzayında kaç bayt yer kaplar?

> **Çözüm (derste verildi):** Adres ucu yoktur (veri uçları, $\overline{CS}$ ve $\overline{WR}$ adres ucu değildir). $2^0 = 1$ bayt yer kaplar (8255: 2 adres ucu → 4 bayt, 8251: 1 adres ucu → 2 bayt).

**5. Testere dişi ve çözünürlük** (ekrandan, 01:55:00)

1000H adresindeki DAC0830'a, Bölüm 7'deki programla AL 00H'den başlayıp artırılarak sürekli gönderilirse çıkışta ne görülür? Bir adımda gerilim ne kadar artar?

> **Çözüm (derste verildi):** Gerilim her adımda $5/255 \approx 0.02$ V artarak 0 V'tan 5 V'a çıkar; FFH'den sonra AL 00H'ye döner ve dalga yeniden başlar. Çıkış testere dişi dalgadır. 10 bitlik DAC'ta bir adım $5/1023$ V olurdu.

**6. Ara sınav Soru 1: Boşluk doldurma** (ekrandan, 02:00:00)

- a) 8086 mikroişlemcisinin I/O uzayı ____ boyutundadır.
- b) 8255 mod 1'de input yönü ayarlanmışsa port uçlarındaki verinin 8255'e otomatik olarak alınmasını sağlayan ____ ucudur.
- c) 8086'da A/D uçlarından adres bilgisi ayrıştırılırken ____ ucu kullanılır.
- d) 8086, veri ve program hafızalarının aynı veri yolunu kullanması açısından ____ mimarisindedir.
- e) 8086'da ____ ucu izole I/O haritalamada adres çözümleme için kullanılır.

> **Çözüm (derste verildi):** a) 64 KB: en büyük port adresi DX ile verilir, DX 16 bit olduğu için $2^{16} = 64$K göz, her biri bir bayt. b) $\overline{STB}$. c) ALE: AD uçlarında adres varken ALE 1 olur ve adresin kopyalanmasını sağlar. d) von Neumann (farklı yollar kullanılsaydı Harvard olurdu). e) M/$\overline{IO}$.

**7. Ara sınav Soru 2: 8086'nın veri yolu, adres yolu, kapasite ve arayüzü** (ekrandan, 02:00:00; şıklar karede görünmüyor)

8086 için sırasıyla veri yolu genişliği, adres yolu genişliği, hafıza kapasitesi ve hafıza arayüzünün doğru verildiği şıkkı işaretleyiniz.

> **Çözüm (derste verildi):** Veri yolu 16 bit, 20 adres ucu; $2^{20} = 1$M göz, her biri bayt ise kapasite 1 MB. 8086 16 bitlik veri yolu görmek istediği için arayüz 512K × 16'dır. Derste doğru cevap B şıkkı olarak verildi. <!-- BELİRSİZ: şıkların metni karede görünmüyor. -->

**8. Ara sınav: yanlış ifade ve tutucu entegre** (derste sözlü, 02:01:07-02:01:30)

Bir soruda ALE ucuyla ilgili ifadelerden yanlış olan istendi; Soru 4'te ise 8086'da veri/adres karışıklığının önlenmesi için hangi devrenin kullanılması gerektiği soruldu (seçeneklerden biri "Buffer").

> **Çözüm (derste verildi):** ALE'nin veri yoluyla bir ilgisi yoktur; adres ve veri uçlarında adresi ayırmak için kullanılır, bu yüzden ALE'yi veri yoluyla ilişkilendiren ifade (B şıkkı) yanlıştır. Adresin tutulmasını sağlayan entegre bir tutucudur (latch); ALE bir latch entegresine bağlıdır. <!-- BELİRSİZ: bu soruların seçenek metinleri karede tam görünmüyor. -->

**9. Ara sınav: adres ucu sayısı** (derste sözlü, 02:01:37)

1G × 32'lik hafıza arayüzüne sahip bir mikroişlemcinin kaç adres ucu vardır?

> **Çözüm (derste verildi):** 1G × 32 = 4G × 8, yani 4 GB. $4\text{G} = 4\times2^{30} = 2^{32}$; $\log_2$ alınınca 32 adres ucu bulunur.

**10. Ara sınav: fiziksel adres** (derste sözlü, 02:02:08)

Verilen IP ve CS değerleri için fiziksel adres nedir?

> **Çözüm (derste verildi):** Fiziksel adres = segment × 10H + offset; segment değerinin sonuna 0 eklenip offset ile toplanır. Derste sonuç 12000H olarak verildi. Hoca, ezber olmasın diye soruda değerlerin sırasını ters yazdığını belirtti. <!-- BELİRSİZ: CS ve IP değerleri karede görünmüyor. -->

**11. Ara sınav: adres çözme** (derste sözlü, 02:05:52)

Birinci 8255 50H'den itibaren ardışık çift adreslere, ikinci 8255 59H'den itibaren ardışık tek adreslere yerleştirilecektir. Tek bir dekoder ile adres çözme devresini tasarlayınız.

> **Çözüm (derste verildi):** Adresler 50H, 52H, 54H, 56H ve 59H, 5BH, 5DH, 5FH'dir:
>
> | Adres | A7 A6 A5 A4 | A3 A2 A1 A0 |
> |---|---|---|
> | 50H | 0 1 0 1 | 0 0 0 0 |
> | 56H | 0 1 0 1 | 0 1 1 0 |
> | 59H | 0 1 0 1 | 1 0 0 1 |
> | 5FH | 0 1 0 1 | 1 1 1 1 |
>
> A2 ve A1 her iki entegrede de dört farklı değer alır; 8255'lerin A1, A0 adres girişlerine bağlanır. İki entegreyi birbirinden ayıran A3 ve A0'dır; dekoderin seçim girişlerine bağlanmalıdır. A7 = 0, A6 = 1, A5 = 0, A4 = 1 ve M/$\overline{IO}$ = 0 olmalıdır. A7 ve A5 ikisi 0 iken 0 üretmek için bir OR kapısından aktif-0 enable girişine, M/$\overline{IO}$ aktif-0 enable girişine, A4 aktif-1 enable girişine bağlanır. Boşta kalan A6 (hep 1) da bir seçim girişine bağlanır: C = A6, B = A3, A = A0. Birinci 8255 için CBA = 100, yani 4 numaralı çıkış; ikinci 8255 için CBA = 111, yani 7 numaralı çıkış kullanılır.

**12. Ara sınav: 8255 kontrol sözcükleri** (ekrandan, 02:10:00)

Birinci 8255'in üç portu LED matrisi sürmek için çıkış (mod 0), ikinci 8255'in A portu tuş tarama entegresinden okumak için mod 1 giriş olarak ayarlanacaktır. Kontrol sözcüklerini yazan kodu veriniz.

> **Çözüm (derste verildi):**
>
> ```asm
> MOV AL, 80H     ; 1. 8255: grup A mod 0, grup B mod 0, tüm portlar çıkış
> OUT 56H, AL     ; 1. 8255 kontrol yazmacı
> MOV AL, 0B0H    ; 2. 8255: grup A mod 1, port A giriş
> OUT 5FH, AL     ; 2. 8255 kontrol yazmacı
> ```
>
> 80H = 1000 0000B, B0H = 1011 0000B (mod ayar biti 1, grup A mod 01, port A giriş).

**13. Ara sınav Soru 9: Tuş tarama entegresi ile 8255 bağlantısı** (ekrandan, 02:10:00)

Tuş tarama entegresinin 8255 Grup A Mod 1 ile kullanılabilmesi için tuş tarama entegresinin uçları ile 8255 uçları arasında yapılması gereken bağlantıyı çizerek gösteriniz.

> **Çözüm (derste verildi):**
>
> ```text
> 8255_2                 TUŞ TARAMA
> PA.0  ---------------- A
> PA.1  ---------------- B
> PA.2  ---------------- C
> PA.3  ---------------- D
> PC.4 (STB_A) --------- DAV (aktif 0)
> PC.5 (IBF_A) --NOT---- ACK (aktif 0)
> ```
>
> Bit sırasına dikkat edilmelidir: D yüksek anlamlı, A düşük anlamlı uca bağlanır. $\overline{DAV}$, mod 1'deki $\overline{STB}$ ucuna bağlanır; veri hazır olunca strobe tetiklenir. Aktif-1 olan IBF ucu, karşı tarafa aktif-0 $\overline{ACK}$ olarak gönderilebilmesi için bir NOT kapısından geçirilir.

**14. Ara sınav Soru 10: LED matris ile 8255 bağlantısı** (ekrandan, 02:10:00)

3×3 LED matrisi birinci 8255 ile uygun şekilde sürebilmek için LED matris ile 8255 uçları arasında yapılması gereken bağlantıyı çizerek gösteriniz.

> **Çözüm (derste verildi):** Ortak G'ler (OAG1-3) port A'nın, ortak R'ler (OAR1-3) port B'nin, ortak katotlar (OK1-3) port C'nin alt uçlarının ilgili sıradaki pinlerine bağlanır; üç port da çıkıştır. Hoca cevap belgesinde kendi koduna uygun olarak çapraz bir bağlantı çizdiğini, koddan bağımsız olarak doğru sırayla bağlantıyı yapan cevapları da doğru kabul ettiğini söyledi. <!-- BELİRSİZ: çapraz bağlantının tam sırası karede tam görünmüyor. -->

**15. Ara sınav: INTR A üzerinden tuş okuma** (derste sözlü, 02:10:58)

İkinci 8255'in INTR A çıkışı üzerinden okunacak veri olup olmadığını kontrol edip okunan değeri TUS değişkenine alan kodu yazınız. İpucu: INTR A'yı kullanabilmek için INTE A bit set/reset moduyla ayarlanmalıdır.

> **Çözüm (derste anlatıldı, kod karede görünmüyor):** INTE A, mod 1 giriş yönünde $\overline{STB}$ ile aynı uçtadır (PC4). Bit set/reset sözcüğüyle PC4 1 yapılır ve ikinci 8255'in kontrol adresine (5FH) yazılır; ayrıca mod 1 ayar sözcüğü gönderilir. Ardından port C okunur ve INTR A (PC3) 08H maskesiyle sınanır; 0 ise beklemeye devam edilir. 1 olunca port A'dan (59H) okunan değer TUS değişkenine yazılır. Bit set/reset sözcüğü için büyük olasılıkla 09H (0000 1001B: PC4 = 1) kullanılır.
>
> **Ek bilgi (derste anlatılmadı):** 8255'e mod ayar sözcüğü yazılması iç durum flip-floplarını sıfırlar; bu yüzden INTE biti büyük olasılıkla mod sözcüğünden **sonra** set edilmelidir.

**16. Ara sınav: LED matrisin TICTACTOE dizisine göre sürülmesi** (derste sözlü, 02:12:54)

TICTACTOE dizisinin her elemanında en düşük anlamlı bit yeşilin, bir sonraki bit kırmızının yanıp yanmayacağını belirtir; negatif değer gözün daha önce seçildiğini gösterir. LED'leri bu diziye göre süren kodu yazınız.

> **Çözüm (derste anlatıldı):** Üç basamaklı yedi parçalı gösterge sürmek gibidir: birinci sütun seçilir, o sütunun R ve G değerleri gönderilir, kısa bir süre beklenir, sonra ikinci ve üçüncü sütunlar için aynısı yapılır ve bu sonsuz döngüde tekrarlanır. Her sütundaki üç satır için iç içe iki üç adımlı döngü kullanılır; toplam 9 göz taranır. Ortak katodu aktif etmek için ilgili OK ucuna 0 verilir; DL'deki seçim değeri her sütunda bir kez döndürülerek (rotate) sıradaki sütun seçilir. Her eleman bir kez döndürülünce yeşil biti carry'ye düşer ve BL'de biriktirilir; bir kez daha döndürülünce kırmızı biti carry'ye düşer ve BH'de biriktirilir. Sütun bitince OK'lar FFH ile söndürülür, yeşil değerler port A'dan, kırmızı değerler port B'den gönderilir ve sıradaki sütunun OK'u aktif edilir. <!-- BELİRSİZ: kodun tamamı karede görünmüyor. -->

**17. Ara sınav: TICTACTOE dizisinin güncellenmesi** (derste sözlü, 02:16:38)

Kırmızı oyuncu (oyuncu 2) bir tuşa bastığında (TUS) diziyi güncelleyen kodu yazınız.

> **Çözüm (derste anlatıldı):** TICTACTOE[TUS] sıfırdan farklıysa göz daha önce basılmıştır ve sarı yapılmalıdır: iki bitin de 1 olması için değer 3 ile OR'lanır. Sıfırsa göz kırmızı yapılır. Ardından dizinin bütün elemanları taranır ve önceki turda sarı yapılmış gözler (3 ya da -1 olanlar) özgün değerlerine döndürülür: kırmızı biti sıfırlanır, yani değer 1 ile AND'lenir. <!-- BELİRSİZ: hocanın burada söylediği "oyuncu 1, değeri 1" ifadesi ile kırmızı göz için yazılan değer altyazıdan net çıkmıyor; kod karede görünmüyor. -->

**18. Ara sınav Soru 14: Kazanma kontrolü** (ekrandan, 02:20:00)

Oyuncu 1 daha önce basılmamış bir butona basıp TICTACTOE dizisi güncellendikten sonra oyunun sonlanıp sonlanmadığını kontrol eden Assembly kodunu yazınız.

> **Çözüm (derste verildi):** Satır/sütun eleme yöntemi kullanılır. BH'nin bitleri "bu sütundan kazanılabilir", BL'nin bitleri "bu satırdan kazanılabilir" anlamına gelir. Değeri 1 olmayan her göz, kendi satırının ve sütununun bitini sıfırlar. Göz numarası $s$ için sütun $s/3$, satır $s \bmod 3$'tür. Sonunda BX sıfırdan farklıysa oyuncu kazanmıştır.
>
> ```asm
> MOV BX, 0000011100000111B ; BH = 07H (sütun), BL = 07H (satır)
> XOR SI, SI
> MOV CX, 9
> MOV DL, 3
> L1:
> CMP TICTACTOE[SI], 1
> JE L2
> MOV AX, SI
> DIV DL             ; AL = SI / 3 (sütun), AH = SI mod 3 (satır)
> PUSH CX
> MOV CL, AH
> MOV DH, 0FEH
> ROL DH, CL
> AND BL, DH         ; satır bitini sıfırla
> MOV CL, AL
> MOV DH, 0FEH
> ROL DH, CL
> AND BH, DH         ; sütun bitini sıfırla
> POP CX
> L2:
> INC SI
> LOOP L1
> CMP BX, 0
> JE KAZANAMADI
> KAZANDI:
> ```
>
> **Ders sonrası not:** Cevap belgesinde ilk satır `MOV BX, 01110111B` olarak yazılmıştı (BH = 00H olur). Hoca bunun hatalı olduğunu söyleyip düzeltti: BH'de de BL'de de 7 olmalıdır, yani BX = 0707H. Kod bu düzeltmeyle verilmiştir.

## Dersin Toparlaması

Bu derste 8254'ün iki uygulamasıyla zamanlayıcı konusu tamamlandı. İlk örnekte tek bir 16 bitlik sayıcının 2 MHz'lik saati 1 Hz'e indiremeyeceği gösterildi ve iki sayıcı kaskat bağlanarak (2000 × 1000) saniyede bir darbe üretildi. BCD modda sayma değerlerinin BCD olarak yazılması ve LSB/MSB baytlarının sayıcılara karışık sırayla yazılabilmesi de bu örnekte görüldü. İkinci örnekte kaskat bağlı iki sayıcıdan elde edilen 0.5 Hz'lik kare dalga, bir saniyelik ölçüm penceresi olarak Counter 2'nin GATE ucuna verildi. Ölçülen sinyal Counter 2'nin saat girişine bağlandı ve read-back komutlarıyla okunan durum ve sayma değerlerinden frekans (9999 - kalan) ya da aralık dışı durumu bulundu.

Ardından analog-dijital dönüşüm konusuna geçildi. Fiziki dünyanın analog, mikroişlemcinin dijital olduğu, aradaki dönüşümün transducer, ADC ve DAC zinciriyle yapıldığı anlatıldı. Analog ve dijital sinyal zamanda ve genlikte süreklilik açısından tanımlandı. Binary weighted ve R/2R merdiven DAC yapıları op-amp toplayıcı mantığıyla çözüldü. DAC0830'un adres ucu olmadığı, G/Ç uzayında tek bayt kapladığı ve her `OUT` ile 0-5 V arasında ölçekli bir çıkış ürettiği gösterildi. AL'yi sürekli artırarak testere dişi dalga üretildi ve çözünürlük ($5/255$ V) hesaplandı. Dersin sonunda birinci ara sınav çözüldü. ADC kısmı (iki ADC yöntemi ve ADC0804) sonraki derse kaldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
