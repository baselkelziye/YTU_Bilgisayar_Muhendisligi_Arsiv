# Ders 23 Genişletilmiş Notu: DAC ve ADC Uygulamaları ve Kesmelere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki dersin tekrarı: analog ve sayısal dünya
- 2. DAC0830: uçlar, çıkış değerleri ve zamanlama
- 3. DAC ile testere dişi dalga örneği
- 4. ADC iç yapıları: paralel ADC
- 5. ADC iç yapıları: rampa dönüştürücü
- 6. ADC0804 entegresi ve INTR ucunun yoklanması
- 7. Proteus uygulaması: DAC ile dalga üretimi
- 8. Proteus uygulaması: ADC0804 ve lojik analizör
- 9. Kesmelere giriş
- Örnek Sorular

## 1. Önceki dersin tekrarı: analog ve sayısal dünya

Ders, bir önceki haftada başlanan ADC ve DAC entegrelerinin incelenmesine devam ederek açıldı. İçinde bulunduğumuz fiziki dünya analogdur; mikroişlemci ya da bilgisayar sistemleri ise sayısaldır. Dış dünyaya ilişkin bir ölçüm yapıp bir kontrol işlemi yürütmek istiyorsak mutlaka bir ADC'ye (analog-dijital dönüştürücü) ve bir DAC'ye (dijital-analog dönüştürücü) ihtiyaç duyarız. ADC elektriksel analog bir işareti dijitale, DAC dijital bir işareti elektriksel analog işarete dönüştürür.

Bunlara ek olarak bir de dönüştürücüye (transducer) ihtiyaç vardır. Ölçmek istediğimiz fiziki değişken (sıcaklık gibi) önce elektriksel bir işarete dönüştürülmelidir; kontrol yönünde de elektriksel işaretin başka bir fiziki enerjiye (örneğin dönme hareketine) dönüştürülmesi gerekir. Slayttaki akış şöyledir (ekrandan, 00:05:00):

```text
Fiziki Dünya --Sıcaklık (analog)--> Transducer --Elektriksel (analog)--> ADC
   --Elektriksel (dijital)--> µP --İşlenmiş Veri (elektriksel-dijital)--> DAC
   --Elektriksel (analog)--> Transducer --Fan Hızı (analog)--> Fiziki Dünya
```

Geçen haftanın örneğinde ortam sıcaklığı ölçülüp buna göre bir fan çalıştırılıyordu. Ölçüm tarafındaki dönüştürücü sıcaklıkla direnci değişen bir eleman olabilir; çıkış tarafındaki dönüştürücü ise bizatihi motorun kendisidir.

Analog ve sayısal işaretin farkı da hatırlatıldı. Bir işaretin analog olması için zamanın her $t$ anında değer alması ve bu değerin sürekli bir kümeden gelmesi gerekir. Sayısal işaret ise hem zamanda belirli aralıklarla alınan örneklere dayanır, hem de her örnekleme anında alabileceği değer belirli kuantalarla sınırlıdır. Örneğin 8 bitlik bir ADC çıktısı 00H ile FFH arasında toplam 256 farklı değer üretir. Yani sayısal işaret hem zamanda hem genlikte ayrıktır.

## 2. DAC0830: uçlar, çıkış değerleri ve zamanlama

### 2.1 Dış dünyaya açılan uçlar

DAC0830'un şemasında hoca bir ucu chip select ($\overline{CS}$) olarak yeniden adlandırdı. Öğrencinin bilmesi gereken uçlar şunlardır: D0-D7 veri uçları, $\overline{CS}$, $\overline{WR}$ ve analog çıkış ucu. Bunların dışındaki iç bağlantılar hazır verilmiş kabul edilir; slaytta ayrıntıları bulunmakla birlikte öğrenci bunlardan sorumlu değildir.

Bu entegrenin adres ucu sayısı 0'dır. Dolayısıyla 8086'nın G/Ç uzayında $2^0 = 1$ baytlık yer kaplar: cihaza bir adres verilir ve yalnız o adres üzerinden erişilir. DAC yalnız çıkış yönlü çalışır; aynı adresten yapılan okuma işlemlerinde cihazın seçilmemesi gerekir, bu da $\overline{WR}$ ucuyla zaten sağlanır.

### 2.2 Çıkış değerleri

8 veri ucu olduğu için cihaza 0-255 arasında 8 bitlik bir değer gönderilir. Buna karşılık çıkışta 0 ile 5 V arasında analog bir gerilim üretilir. Hocanın tablosu:

| Giriş | Analog çıkış |
|-------|--------------|
| 00H | 0 V |
| 7FH | yaklaşık 2,5 V |
| FFH | 5 V |

Çıkış doğrusal ölçektedir. Bir adım $5/255 \approx 0{,}0196$ V'tur (python ile doğrulandı; 7FH tam olarak $127 \cdot 5/255 \approx 2{,}49$ V eder).

### 2.3 Zamanlama diyagramı

Slayttaki DAC0830 zamanlama diyagramında ILE/$\overline{CS}$, $\overline{WR}$, veri bitleri ve $I_{OUT1}/I_{OUT2}$ çıkışı görülür; $t_{CS}$, $t_{CH}$, $t_W$, $t_{DS}$, $t_{DH}$ ve $t_S$ süreleri işaretlidir, çıkış $t_S$ sonunda "±½ LSB'ye oturmuş" (settled to ±½ LSB) olur (ekrandan, 00:10:00).

Mikroişlemci DAC adresine bir değer gönderdiğinde (`MOV AL, değer` ve ardından `OUT DAC_ADRES, AL`) üç şey olur:

- Adres çözme devresi işlemcinin ürettiği adresi çözerek $\overline{CS}$ işaretini üretir.
- `OUT` bir yazma işlemi olduğu için işlemci $\overline{WR}$ işaretini üretir.
- İşlemci gönderilecek veriyi veri uçlarına koyar.

Veri hazır, cihaz seçili ve yazma işareti verilmişken DAC 8 bitlik değeri alır ve belirli bir oturma süresi (settling time) sonunda buna karşılık gelen analog değeri çıkışta üretir. Bu nedenle cihaza bir değer gönderdikten sonra cihazın hazır olması için bir süre beklemek gerekir.

> **Hocanın vurgusu:** DAC'ye değer gönderdikten sonra belirli bir süre beklemekte fayda vardır; çıkış ancak oturma süresinden sonra kararlıdır.

## 3. DAC ile testere dişi dalga örneği

Geçen haftanın örneğinde DAC 1000H adresine yerleştirilmişti ve verilen kodu çalıştırınca analog çıkışta yaklaşık ne görüleceği soruluyordu. Adres 1000H olduğu için doğrudan (immediate) port adresi olarak verilemez, DX üzerinden verilmelidir. AL 0'dan başlatılır, DAC'ye gönderilir, biraz beklenir, AL artırılır ve yeni değer gönderilir. AL FFH'a ulaşıp bir kez daha artırıldığında 00H'a döner.

Çıkış 0 V'tan başlayıp FFH'a karşılık gelen 5 V'a kadar doğrusal olarak artar, sonra birden 0'a düşer ve yeniden yükselir. Sonuç yükselen eğik kenarlar ve dik düşen kenarlardan oluşan bir testere dişi dalgadır.

## 4. ADC iç yapıları: paralel ADC

ADC tarafında önce ADC entegrelerinin içinde neler olabileceğine dair iki devre yapısı, sonra ADC0804 entegresi, dalga şekli ve örneği incelendi.

### 4.1 Karşılaştırıcı

Paralel ADC bir karşılaştırıcı dizisi ve bir öncelik kodlayıcıdan (priority encoder) oluşur (ekrandan, 00:15:00). Karşılaştırıcı geri beslemesi olmayan bir opamp gibi düşünülebilir; artı ($A$) ve eksi ($B$) girişleri vardır:

- $A > B$ ise çıkış lojik 1'dir.
- $A \le B$ ise çıkış lojik 0'dır. Analog değerlerde tam eşitliği yakalamak pek mümkün değildir, ama tanım böyle yapılır.

(Hoca daha sonra 5 V örneği anlamlı olsun diye eşitliği 1 tarafına aldı: $A \ge B$ ise 1.)

### 4.2 Devre

Dönüştürülecek giriş işareti $V_{in}$'dir. $V_{ref}$ ölçülebilecek en büyük gerilime karşılık gelir; 0-5 V aralığında çalışılıyorsa $V_{ref} = 5$ V'tur. $V_{ref}$'ten toprağa seri bağlı 7 eşit direnç ($R$) vardır. Her düğüm bir karşılaştırıcının eksi girişine, $V_{in}$ ise bütün karşılaştırıcıların artı girişine gider. Karşılaştırıcı çıkışları "8-line to 3-line priority encoder" bloğuna, kodlayıcının çıkışı da "Binary output" olarak dışarı verilir.

### 4.3 Düğüm gerilimleri

Hoca öğrencilere bir düğümün gerilimini sordu. Bir öğrenci önce 5,6 V buldu; hoca bunun 5 V'tan küçük olması gerektiğini söyleyip gerilim bölücüyle çözdü. Koldan akan akım $I = 5/(7R)$'dir. En üstteki dirençten sonraki düğüm toprağa 6 direnç üzerinden bağlıdır:

$$V = \frac{5}{7R} \cdot 6R = \frac{30}{7} \approx 4{,}29 \text{ V}$$

Bir alttaki düğüm için $\frac{5}{7R} \cdot 5R \approx 3{,}57$ V bulunur. Aynı şekilde diğer düğümler $4R, 3R, 2R, R$ ile hesaplanır (python ile doğrulandı):

| Düğüm | Gerilim |
|-------|---------|
| $V_{ref}$ | 5 V |
| $6R$ üstü | 4,29 V |
| $5R$ üstü | 3,57 V |
| $4R$ üstü | 2,86 V |
| $3R$ üstü | 2,14 V |
| $2R$ üstü | 1,43 V |
| $R$ üstü | 0,71 V |

### 4.4 Öncelik kodlayıcı ve örnekler

Öncelik kodlayıcı en yüksek anlamlı girişinden başlayarak ilk kez 1 gördüğü girişin numarasını ikili olarak çıkışa verir. 8 girişi olduğu için çıkış 000 ile 111 arasındadır. Girişler üstten 7, 6, 5, ..., 0 diye numaralanır; en alttaki giriş toprağa bağlı olduğundan her zaman 0'dır.

$V_{in} = 4$ V için (ekrandan, 00:25:00):

- 1. karşılaştırıcı: artı uçta 4 V, eksi uçta 5 V → 0
- 2. karşılaştırıcı: 4 V ile 4,29 V → 0
- 3. karşılaştırıcı: 4 V ile 3,57 V → 1
- Aşağıdakilerin hepsi → 1

İlk 1 giriş 5'tedir, çıkış $101_2$ olur. Yani 0-5 V aralığındaki 4 V, 3 bitlik bir ADC sonucu olarak 5'e dönüştürülmüş olur.

$V_{in} = 0$ V ise bütün karşılaştırıcılar 0 verir ve çıkış 000 olur. $V_{in} = 5$ V ise (eşitlik 1 tarafına alındıktan sonra) en üstteki karşılaştırıcı 1 verir; bu 7 numaralı giriştir ve çıkış 111 olur. Böylece karşılaştırıcılar ve öncelik kodlayıcıyla 0-5 V arasında 3 bitlik çözünürlükte bir ADC elde edilir.

> **Ek bilgi (derste anlatılmadı):** Bu yapı literatürde "flash ADC" olarak da bilinir. $n$ bitlik çözünürlük için büyük olasılıkla $2^n - 1$ karşılaştırıcı gerekir; bu yüzden çok hızlıdır ama bit sayısı arttıkça donanım hızla büyür.

## 5. ADC iç yapıları: rampa dönüştürücü

İkinci yapı rampa dönüştürücüdür (ramp converter). Hoca karmaşık olduğu için dikkatle takip edilmesini istedi.

- 8 bitlik bir sayıcı (counter) başlangıçta 0'dır. Saat işaretiyle birlikte değeri artar; 00H'tan FFH'a kadar sırayla sayar.
- Sayıcının çıkışı bir DAC'ye verilir. 00H'a karşılık 0 V'tan başlayarak DAC çıkışı $5/255$ V'luk adımlarla artar.
- Bir karşılaştırıcı, ölçmek istediğimiz gerilimle DAC çıkışını karşılaştırır. DAC çıkışı ölçülen gerilimin üzerine geçtiği anda karşılaştırıcı çıkışı 0 olur.
- Bu anda sayıcının o anki değeri düşen kenarda bir yazmaca (shift register) kopyalanır; sayıcının load ucuna 0 geldiği için sayıcı da sıfırlanır.
- Yazmaçtaki 8 bitlik değer ADC'nin ikili çıktısıdır.

Kısacası sayıcıyla sıralı sayısal değerler üretilir, DAC'den geçirilir ve analog değerin ölçülen değeri geçtiği an yakalanır; o andaki sayısal değer sonuçtur. Bir öğrenci anlatımın anlaşıldığını söyledi.

Bu yapıdan önemli bir sonuç çıkar: ADC işlemi zaman alır. Sıfırdan başlayıp ölçülen değeri geçene kadar beklemek gerekir; ölçülen gerilim ne kadar yüksekse sonuç o kadar geç gelir. Bu yüzden ADC'ye "dönüşüme başla" denince sonuç hemen dönmez ve ADC dönüşümün bittiğini bir fiziki uç üzerinden bildirmelidir.

> **Hocanın vurgusu:** ADC'nin dönüşümün bittiğini bir fiziki uç üzerinden bildirmesi çok önemli bir noktadır; bu ucun nasıl kullanıldığına dikkat edin.

## 6. ADC0804 entegresi ve INTR ucunun yoklanması

### 6.1 Uçlar

ADC0804 de kara kutu olarak ele alınır; besleme ve saat gibi uçlar hazır kabul edilir. Slayttaki şemada (ekrandan, 00:30:00) U111 olarak ADC0804 görülür:

| Uç | Bağlantı |
|----|----------|
| 1 $\overline{CS}$ | $\overline{IO1}$ (birinci chip select) |
| 2 $\overline{RD}$ | $\overline{RD}$ |
| 3 $\overline{WR}$ | $\overline{WR}$ |
| 4 CLK IN | saat işareti |
| 5 $\overline{INTR}$ | 74125 tamponunun 2 numaralı girişine |
| 6 VIN+ | RV1 potansiyometresinin (1k) orta ucuna |
| 7 VIN-, 8 A GND, 10 D GND | toprak |
| 18-11 DB0(LSB)-DB7(MSB) | AD0-AD7 veri yolu |
| 20 VCC | besleme |

74125 üç durumlu tamponun (U4:A) 3 numaralı çıkışı AD7'ye, kontrol ucu (1) ise $\overline{IO2}$'ye bağlıdır. Hoca $\overline{IO2}$'yi ikinci chip select ($\overline{CS2}$) olarak adlandırdı.

Analog giriş ucundaki değer dijitale çevrilir ve sonuç veri uçlarından okunur. Ayrıca bir $\overline{CS}$, $\overline{RD}$, $\overline{WR}$ ve ikinci bir chip select vardır; bu ikinci chip select aslında $\overline{INTR}$ ucunun aktarıldığı tamponu kontrol eder.

### 6.2 Çalışma mantığı

Entegreye bir "boş yazma" yapıldığında, yani AL ne olursa olsun cihazın adresine `OUT` yapıldığında, analog girişteki değerin dönüşümü başlar. Dönüşüm bitince $\overline{INTR}$ ucu 0 olur; bu, başlatılan dönüşümün başarıyla tamamlandığı anlamına gelir.

Cihazın hiç adres ucu yoktur. Bu yüzden bir durum yazmacını okuyup yoklama yapmak mümkün değildir. Çözüm, $\overline{INTR}$ ucunu tek başına 1 bitlik ayrı bir G/Ç cihazı gibi ele almaktır. Bu uç üç durumlu bir tampondan geçirilir; tamponun kontrol ucu bu 1 bitlik cihazın chip select ucu olur. Tampon şöyle çalışır: 1 numaralı uçta lojik 0 varsa 2 numaralı uçtaki değer 3 numaralı uca aktarılır.

Anlatımdaki yerleşim (ekrandan, 00:35:00):

- ADC0804 100H adresinde: adres çözme 100H için $\overline{CS}$ üretir.
- $\overline{INTR}$ için sanal cihaz 200H adresinde: adres çözme 200H için $\overline{CS2}$ üretir.

Akış:

1. 100H adresine boş bir `OUT` yapılır; dönüşüm başlar.
2. Hemen ardından 200H adresinden sürekli okunur. Bu adreste anlamlı tek bir bit vardır ve D7'ye bağlıdır. Diğer bitler maskelenir, en yüksek anlamlı bit test edilir.
3. Bit 0'a düşmüşse dönüşüm bitmiştir; 100H adresinden okuma yapılarak sonuç alınır.

Kesmeler öğrenildikten sonra bu sanal cihaza gerek kalmayacaktır: $\overline{INTR}$ ucu doğrudan mikroişlemcinin kesme istek ucu olarak kullanılabilecektir.

> **Hocanın vurgusu:** Mantık önemli: cihazın yazmacını okuyamadığımız ve adres ucu olmadığı için (1 bayt yer kaplar) $\overline{INTR}$ ucunu bir port okur gibi okuruz. Hangi veri ucuna bağlıysa o bit maskelenip 0 olup olmadığı kontrol edilir.

### 6.3 Dalga şekli

Dalga şekli iki aşamada incelendi:

- **Boş yazma aşaması:** ADC adresine yazma yapılınca adres çözme cihazı seçer, işlemci $\overline{WR}$ gönderir. Cihaz belirli bir süre dönüşümle uğraşır. Dönüşüm bitince geçerli veriyi (valid data) veri uçlarına hazırlar ve kısa bir süre sonra $\overline{INTR}$ ucunu lojik 0'a çeker.
- **Okuma aşaması:** $\overline{INTR}$ 0'a düştükten sonra ADC adresinden okuma yapılır; geçerli değer işlemciye aktarılır. Okumayla $\overline{INTR}$ yeniden 1'e çıkar ve döngü başa döner.

### 6.4 Çift adres

Cihazlar çift adrese yerleştirildiği için tampon çıkışı veri yolunun düşük anlamlı D0-D7 bitlerinden herhangi birine bağlanabilir. Maskeleme ve test işlemi bağlanılan bite göre yapılır.

> **Ek bilgi (derste anlatılmadı):** 8086'da çift adreslere yapılan bayt erişimleri veri yolunun düşük yarısını (D0-D7), tek adreslere yapılanlar yüksek yarısını (D8-D15) kullanır. Bu yüzden 8 bitlik bir cihaz çift adresteyse D0-D7'ye bağlanır.

### 6.5 Örnek kod

Slayttaki örnek kodda ADC 0200H'ta, $\overline{INTR}$ sanal cihazı 0400H'tadır (ekrandan, 00:40:00):

```asm
TEKRAR:
        MOV DX, 0200H
        MOV AL, 00H
        OUT DX, AL
        MOV DX, 0400H
INTR_KONTROL:
        IN AL, DX
        TEST AL, 80H
        JNZ INTR_KONTROL
        MOV DX, 0200H
        IN AL, DX
        CALL DELAY
        JMP TEKRAR
```

Anlatım: 200H DX'e alınır, AL'ye rastgele bir değer (burada 0) konur ve cihazın adresine boş yazma yapılır. Sonra 400H DX'e alınır ve bu adresten okunur. Okunan değerin en yüksek anlamlı biti $\overline{INTR}$'dir; `TEST AL, 80H` ile test edilir. Henüz 0'a düşmemişse okuma ve test tekrarlanır. 0'a düşünce ADC'nin adresinden (200H) okuma yapılır. Ardından cihazın kendini yeniden hazırlaması için biraz beklenir ve başa dönülür.

> **Ders sonrası not:** Hoca devre anlatımında ADC'yi 100H'a, sanal cihazı 200H'a yerleştirdi; slayttaki kod ve Proteus örneği ise ADC için 200H, sanal cihaz için 400H kullanır. İki yerleşimde de mantık aynıdır; yalnız adresler farklıdır.

## 7. Proteus uygulaması: DAC ile dalga üretimi

### 7.1 Testere dişi ve periyot

Proteus'ta DAC örneği açıldı. Cihazın adresi 1000H'tır ve bu adresi seçen bir 4x8 dekoder yapısı vardır. Kod şöyledir (ekrandan, 00:45:00):

```asm
STAK    SEGMENT PARA STACK 'STACK'
        DW 20 DUP(?)
STAK    ENDS

DATA    SEGMENT PARA 'DATA'
DIGITS  DB 00H
DATA    ENDS

CODE    SEGMENT PARA 'CODE'
        ASSUME CS:CODE, DS:DATA, SS:STAK
START PROC
        MOV AX, DATA
        MOV DS, AX

        mov DX, 1000H
        MOV AL, 00H

ENDLESS:
        OUT DX, AL
        CALL DELAY
        INC AL

        JMP ENDLESS
        RET
START ENDP

DELAY PROC NEAR
PUSH CX
MOV CX, 00FFH
L1:
LOOP L1
POP CX
RET
DELAY ENDP
```

Osiloskobun A kanalında testere dişi dalga görüldü; çıkışa bağlanan voltmetre de değerin sürekli bir analog değer olduğunu gösterdi. Tek seferlik kayıtla (one shot) ölçülen periyot yaklaşık 800 ms'dir.

Hoca önce periyodun nasıl artırılıp azaltılacağını ve periyodu neyin belirlediğini sordu. Bir öğrenci periyodu AL'nin FF sınırını aşmasının belirlediğini söyledi; hoca bunun tam olarak cevap olmadığını belirtip ekranı yakınlaştırdı. Dalga aslında basamak basamak değerlerden oluşur: bir analog değer gönderilir ve bir süre beklenir. Basamaklarda bekleme ne kadar uzunsa periyot o kadar büyür, basamaklar ne kadar darsa periyot o kadar küçülür. DELAY yalnız bir basamağın genişliğini belirler, ama bir periyotta 255 kez peş peşe çağrıldığı için periyodu doğrudan etkiler. DELAY içinde CX'e bir değer atanıp boş döngü döndürülür.

**Soru:** Periyodu belirleyen nedir? **Cevap:** AL'nin FF'i aşması değil, her değerden sonra çağrılan DELAY alt programının ne kadar süre boş bekleme yaptığıdır.

Deneyler:

- Gecikme sayacı büyütüldü; önce bir periyot ekrana sığmadı. Değer "5FF" civarına indirilince periyot yaklaşık 4,7 s oldu.
- Gecikme sayacı 0FH'a (hocanın deyişiyle 16 adımlık sayma) indirildi (ekrandan, 00:50:00); periyot yaklaşık 60 ms'ye düştü.

<!-- BELİRSİZ: Hoca 00:48:23'te "ilk başta 400 milisaniyeydi" dedi; ilk ölçüm 00:43:18'de 800 ms olarak söylenmişti. -->

### 7.2 Üçgen dalga

İkinci soru testere dişi yerine, çıkış ve inişleri yaklaşık aynı eğimde olan bir üçgen dalga üretmekti. Değer 0'dan 255'e artırılmalı, sonra 0'a düşmeden 255'ten 0'a adım adım azaltılmalıdır. Hoca önce `CMP AL, 255` gibi bir karşılaştırmayı düşündü ve öğrencilere sordu.

**Soru:** Kod nasıl değiştirilmeli ki üçgen dalga elde edilsin? **Cevap (bir öğrenci):** `INC AL`'nin altında 255 olup olmadığı kontrol edilir; 255'e eşitse azaltma yapan ikinci bir döngüye geçilir, onun altında 0'a eşitlik kontrol edilip baştaki sonsuz döngüye dönülür. Hoca bunun doğru olduğunu söyleyip `LOOP` ile daha kısa bir çözüm yazdı (ekrandan, 00:55:00):

```asm
ENDLESS:
        MOV CX, 255
L1:
        OUT DX, AL
        CALL DELAY
        INC AL
        LOOP L1

        MOV CX, 255
L2:
        OUT DX, AL
        CALL DELAY
        DEC AL
        LOOP L2
        JMP ENDLESS
```

İlk döngü 255 adım döner; 0'dan başlandığı için AL 255'e ulaşır. İkinci döngü 255'ten başlayıp her adımda `DEC AL` yapar. Önce üçgenin yükselen, sonra düşen kenarı çizilir ve bu sonsuza kadar tekrarlanır. Testere dişinin periyodu 60 ms olduğundan üçgen dalganın periyodu iki katı, yaklaşık 120 ms çıktı. İmleçlerle ölçülen en düşük değer 0 V, en yüksek değer 5 V'tur.

### 7.3 0-3 V arası, 5 Hz üçgen dalga

Üçüncü soru: 0 ile 3 V arasında değişen ve frekansı 5 Hz olan bir üçgen dalga üretin. (Hoca önce 50 Hz düşündü; periyodu $1000/50 = 20$ ms olacağı için 5 Hz'e geçti.)

**Genlik:** FFH = 255 → 5 V olduğundan:

$$\frac{3}{5} = \frac{x}{255} \quad\Rightarrow\quad x = \frac{255 \cdot 3}{5} = 153 = 99\text{H}$$

(Hesap makinesinde $255 \times 3 = 765$, $765 / 5 = 153$; ekrandan, 00:55:00. Python ile doğrulandı.) Adımlar 99H'a kadar gidince çıkış 0-3 V arasında sınırlanır. İlk denemede tepe değer yaklaşık 2 V çıktı; neden, kodda 99'un onluk yazılmış olmasıydı. 99H yazılınca tepe değer 3 V oldu.

**Periyot:** Bu haliyle periyot yaklaşık 72-73 ms'dir. 5 Hz için gereken periyot $1/5 = 200$ ms'dir, bu yüzden gecikme büyütülmelidir. Gecikme deneme yanılmayla ayarlandı: 7FH ile yaklaşık 400 ms (fazla yavaş), 3FH ile yaklaşık 245-250 ms elde edildi; bir ayar daha yapılınca yaklaşık 210 ms, yani yaklaşık 200 ms'lik periyot bulundu.

Hassas hesap zordur, çünkü alt program çağrılırken yığına atılan, dönüşte yığından çekilen değerler, `LOOP` ve atama komutları da süre harcar. Aslında her komutun kaç saat çevrimi sürdüğü ve işlemcinin saat frekansı bellidir; bu nedenle DELAY'in çağrılıp dönmesine kadar geçen süre hassas biçimde hesaplanabilir, ama derste bu hesaba girilmedi. Zamanlama hassasiyeti işlemci saatinin çözünürlüğüyle sınırlıdır; genlikte daha fazla hassasiyet için ise daha çok bitli bir DAC kullanmak gerekir.

Hoca örneği dalga şeklini, periyodu ve genliği değiştirerek çeşitlendirmenin ve üzerinde denemeler yapmanın faydalı olacağını söyledi.

## 8. Proteus uygulaması: ADC0804 ve lojik analizör

### 8.1 Devre

ADC örneğinde 8086, adres mandalları, adres çözme kapıları, ADC0804 ve 74125 tamponu tek bir şemadadır (ekrandan, 01:00:00). Analog giriş bir potansiyometreyle üretilir. Voltmetreyle gösterildiği gibi potansiyometre %100'deyken çıkış 5 V'a çok yakındır (yaklaşık 4,9995 V), 0'a yaklaştırılınca 0 V'a çok yakındır. Potansiyometre bir gerilim bölücü gibi çalışır ve 0-5 V arası bir gerilim verir.

Kodda 200H ADC'nin kendi adresi, 400H $\overline{INTR}$ için oluşturulan sanal cihazın adresidir. Akış: 200H'a boş yazma, 400H'tan okuyup ilgili veri ucunun 0'a düşüp düşmediğini kontrol etme, düşmüşse ADC'nin adresinden okuma. Süreç bir lojik analizörle izlendi.

### 8.2 Gözlem

Potansiyometre ortaya (%50) alındı; tam ortada değer yaklaşık 7FH-80H civarında olmalıdır. Lojik analizörde (ekrandan, 01:05:00) $\overline{INTR}$'nin bağlı olduğu A7 kanalı 0'a düştüğü anda veri yolunda 80H görüldü. 80H orta değerdir: $128 \cdot 5/255 \approx 2{,}51$ V (python ile doğrulandı).

Arada görülen 00H değerleri, dönüşümü başlatmak için yapılan boş yazmada AL'den gönderilen 0'dır. Okuma yapılınca $\overline{INTR}$ yeniden 1'e çıkar ve bir sonraki çevrim başlar.

### 8.3 Tamponu AD0'a bağlamak

Tampon çıkışı AD7 yerine AD0'a bağlandı (ekrandan, 01:10:00).

**Soru:** Tampon AD0'a bağlansaydı kontrol hangi değerle yapılmalıydı? **Cevap:** En düşük anlamlı bit için 01H ile.

Yeni yakalamada 01H değeri görüldü, ama 80H ilk başta görünmedi. Ekran yakınlaştırılınca açıklandı: 00H ADC'ye yapılan boş yazma, 01H 400H okunurkenki değer, aradaki çok kısa süreli değer ise ADC'den okunan asıl değerdir (80H). Bu okuma $\overline{INTR}$ ile ilgili zaman aralığında yapılır.

Bu örnek, bir yazmaçtan okunamayan ama yoklanması gereken bir fiziki ucun nasıl okunacağını gösterir. Tampon illa AD7'ye bağlanmak zorunda değildir; cihaz çift adreste olduğu için D0-D7'den herhangi birine bağlanabilir ve maskeleme ile test o bite göre yapılır.

## 9. Kesmelere giriş

### 9.1 Konular

Sonraki haftanın konusu olan kesmelere kısa bir giriş yapıldı. Slayttaki konu listesi (ekrandan, 01:15:00): Polling-Interrupt, kesme kaynakları (Hardware Int., Software Int.), kesme vektör tablosu, kesme adımları, özel kesme alt programı yazma (DIV0), donanımsal kesmeler (NMI, INTR), 8259A (uç tanımları, iç yapı, ayarlama: ICW'ler, OCW'ler) ve 8259A örneği.

Şimdiye kadar yoklama mantığıyla yapılan veri aktarımlarının hepsi 8259 ile kesme tabanlı yapılabilecektir. Örneğin:

- 8255'te mod 1'de INTRA ve INTRB, mod 2'de INTR uçları vardı. Bunlar el sıkışma (handshaking) modunda verinin hazır olduğunu bildirir ve ayrıca bir durum yazmacında bit olarak sunulur. Şimdiye kadar bu bitler yoklanıyordu; kesmelerle bu uçlar 8259 üzerinden işlemcinin kesme istek ucuna bağlanacak ve veri hazır olduğunda aktarım kesmeyle yapılacaktır.
- 8251'de transmit ready ve receive ready uçları kesme isteği için kullanılabilir.
- ADC'nin $\overline{INTR}$ ucu da kesme isteği oluşturmak için kullanılabilir.

### 9.2 Yoklama ve kesme: kova benzetmesi

Ders çalışırken suyun kesildiğini ve kovayla su biriktirildiğini düşünün; su bazen akıyor, bazen akmıyor. **Yoklama:** biraz ders çalışırsınız, sonra gidip kovaya bakarsınız; dolmuşsa boşaltırsınız, dolmamışsa geri dönersiniz ve bunu sürekli tekrarlarsınız. Kovanın dolduğunu size bildiren bir işaret yoktur, gidip kontrol etmek zorundasınız. **Kesme:** kovaya bir sensör takılır ve hoparlöre bağlanır. Ders çalışmaya devam edersiniz; kova dolunca hoparlör uyarır, gidip boşaltır, boş kovayı yerine koyar ve çalışmaya dönersiniz. Olay gerçekleştiğinde sizi bir şeyin tetiklemesi, işlemcinin bir kesme isteğine cevap vermesine benzer.

### 9.3 Kesme kaynakları

Slayt (ekrandan, 01:20:00): yazılımsal olarak INT, INTO, INT 3; donanımsal olarak INTR, NMI; donanım kesmesiyle ilgili onay $\overline{INTA}$; kesmeyle ilgili bayraklar IF, TF; dönüş komutu IRET.

**Yazılımsal kesmeler** iki grupta incelenir:

- Doğrudan `INT n` komutu: $n$ 00H-FFH (0-255) arasındadır ve çağrılacak kesme tipini belirtir. `INTO` (interrupt on overflow) komutu da doğrudan çalıştırılabilir.
- Komut sonucunda oluşan kesmeler: bir sayı sıfıra bölünürse otomatik olarak sıfıra bölme kesmesi oluşur; işlem sonunda taşma oluşmuşsa taşma kesmesi yürütülebilir.

**Donanımsal kesmeler** için iki fiziki uç vardır:

- **NMI (non-maskable interrupt):** adından da anlaşılacağı gibi maskelenemez, kapatılamaz; bu uca gelen istekler mutlaka değerlendirilir. Hayati durumlar için kullanılır; örneğin açılışta RAM hatası olması ya da elektriksel seviyenin kararlı bir değere ulaşmaması.
- **INTR (interrupt request):** maskelenebilir kesme istek ucudur. Bu uca gelen istekler yalnız IF bayrağı 1 iken değerlendirilir; IF 0 ise maskelenir.

Üçüncü bir uç da aktif 0 olan $\overline{INTA}$ (interrupt acknowledge) ucudur. Bir kesme isteği işlemci bir komutun ortasındayken gelirse işlemci önce yürüttüğü komutu bitirir, sonra kesmeyi değerlendirir. INTR'den gelen isteğe cevap verecekse $\overline{INTA}$ üzerinden karşı tarafa onay (0) gönderir; böylece kesmenin değerlendirildiği anlaşılır.

### 9.4 Bayraklar

- **IF (interrupt flag):** INTR ucuyla ilişkilidir. IF = 1 ise INTR'den gelen istekler değerlendirilir, IF = 0 ise maskelenir.
- **TF (trap flag):** TF = 1 ise her komut yürütüldükten sonra bir kesme tetiklenir. Bu, donanımsal adım adım hata ayıklama için kullanılır: örneğin her komuttan sonra kesme alt programına gidilip bütün yazmaçların değerleri bir göstergede gösterilebilir.

Kesme alt programına girildiğinde IF ve TF işlemci tarafından otomatik olarak 0 yapılır; ana programda 1 yapılmış olsalar bile. Sebep: IF 1 iken bir kesme gelip alt programa girildiğinde aynı kesme yeniden gelirse alt program içinde onu da değerlendirmek gerekirdi. Varsayılan olarak iç içe kesme olmaması için IF, benzer şekilde TF de sıfırlanır. Kullanıcı kesme alt programında IF'yi 1 yaparak iç içe kesmeye izin verebilir, ama bu kullanıcının sorumluluğundadır.

### 9.5 Kesme alt programının dönüşü

Kesme alt programı bir yordam gibi düşünülebilir, ama FAR tipindedir; NEAR tipinde kesinlikle yazılamaz. NEAR bir yordam `RET` ile, FAR bir yordam `RETF` ile döner. Kesme alt programı ise `IRET` (interrupt return) ile dönmek zorundadır.

> **Ek bilgi (derste anlatılmadı):** `IRET`, `RETF`'ten farklı olarak yığından CS ve IP'nin yanında bayrak yazmacını da geri yükler; kesme oluşurken işlemci bayrakları da yığına attığı için büyük olasılıkla bu fark gereklidir.

### 9.6 Kesme vektör tablosu

Slayt (ekrandan, 01:25:00): "Kesme Vektör Tablosu hafıza uzayında 00000H-003FFH adres aralığındaki 1024 byte'lık alandır. Kesme Vektör Tablosu toplamda 256 farklı kesme için ilgili fonksiyonların offset ve kesim değerlerini saklar."

8086'da 0-255 arası 256 farklı kesme tipi tanımlanabilir. Bellek uzayının en düşük bölgesinde 256 gözlü bir tablo vardır; her göz 4 bayttır: 2 bayt offset ve 2 bayt segment. Bunlar ilgili kesme tipine bağlı kesme alt programının adresini verir; bir FAR fonksiyonun adresi segment ve offsetle belirlendiği için böyledir. Tablonun boyutu $256 \times 4 = 1024$ bayttır (hoca bir yerde "255×4 veya 256×4" dedi; doğrusu 256×4) ve 0H-3FFH (0-1023) adreslerini kaplar. Bir kesme tetiklendiğinde işlemci tablodan o kesmenin offset ve segment değerlerini alır ve kesme alt programına dallanır. Ayrıntılar sonraki derste ele alınacaktır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:16:55; ekrandan, 00:20:00): $V_{ref} = 5$ V ve 7 eşit $R$'den oluşan paralel ADC direnç dizisinde, en üstteki dirençten sonraki düğümün gerilimi nedir?

> **Çözüm (derste verildi):** $I = 5/(7R)$. Düğüm toprağa 6R üzerinden bağlıdır: $V = \frac{5}{7R}\cdot 6R = 30/7 \approx 4{,}29$ V. Bir alttaki düğüm $\frac{5}{7R}\cdot 5R \approx 3{,}57$ V'tur.

**Soru 2** (derste sözlü, 00:20:08; ekrandan, 00:25:00): Aynı 3 bitlik paralel ADC'ye 4 V, 0 V ve 5 V uygulanırsa çıkış ne olur?

> **Çözüm (derste verildi):** 4 V: karşılaştırıcılar üstten 0, 0, 1, 1, 1, 1, 1; ilk 1 giriş 5'te → 101. 0 V: hepsi 0 → 000. 5 V (eşitlik 1 sayılırsa): ilk 1 giriş 7'de → 111.

**Soru 3** (derste sözlü, 00:43:32; ekrandan, 00:45:00): 1000H adresindeki DAC'ye AL'yi sürekli artırarak yazan programda testere dişi dalganın periyodu yaklaşık 800 ms'dir. Periyodu ne belirler, nasıl artırılır ya da azaltılır?

> **Çözüm (derste verildi):** Periyodu, her `OUT`'tan sonra çağrılan DELAY alt programının bekleme süresi belirler. DELAY bir basamağın genişliğidir ve bir periyotta 255 kez çağrılır. CX'e yüklenen değer büyütülürse periyot artar (derste yaklaşık 4,7 s), küçültülürse azalır (0FH ile yaklaşık 60 ms).

**Soru 4** (derste sözlü, 00:49:01; ekrandan, 00:55:00): Aynı kodu testere dişi yerine üçgen dalga üretecek şekilde değiştirin.

> **Çözüm (derste verildi):** `MOV CX, 255` ile `INC AL` yapan bir `LOOP L1` döngüsü, ardından yine `MOV CX, 255` ile `DEC AL` yapan bir `LOOP L2` döngüsü yazılır ve `JMP ENDLESS` ile başa dönülür (kod 7.2 bölümünde). Periyot testere dişinin iki katı olur (yaklaşık 120 ms).

**Soru 5** (derste sözlü, 00:53:33): 0 ile 3 V arasında değişen, frekansı 5 Hz olan bir üçgen dalga üretin.

> **Çözüm (derste verildi):** Genlik için döngü sınırı $255 \cdot 3/5 = 153 = 99\text{H}$ olmalıdır (onluk 99 değil). 5 Hz için periyot 200 ms olmalıdır; DELAY sayacı deneme yanılmayla ayarlanarak yaklaşık 200-210 ms elde edildi.

**Soru 6** (derste sözlü, 01:06:34): ADC0804'ün $\overline{INTR}$ ucunu taşıyan tampon AD7 yerine AD0'a bağlanırsa yoklama döngüsünde hangi maske kullanılmalıdır?

> **Çözüm (derste verildi):** En düşük anlamlı bit test edilmelidir: `TEST AL, 01H`.

## Dersin Toparlaması

Bu derste DAC ve ADC konusu tamamlandı. DAC0830'un uçları, doğrusal 0-5 V çıkışı ve zamanlama diyagramı tekrar edildi; çıkışın oturma süresinden sonra kararlı olduğu için her yazmadan sonra beklemek gerektiği vurgulandı. ADC iç yapıları olarak gerilim bölücü, karşılaştırıcılar ve öncelik kodlayıcıdan oluşan paralel ADC ile sayıcı, DAC ve karşılaştırıcıdan oluşan rampa dönüştürücü incelendi. Rampa yapısı, dönüşüm süresinin girişe bağlı olduğunu ve dönüşümün bittiğini bildiren bir uca neden gerek olduğunu gösterdi. ADC0804'te bu uç ($\overline{INTR}$) üç durumlu bir tamponla 1 bitlik sanal bir G/Ç cihazına dönüştürülüp yoklandı. Proteus'ta DAC ile testere dişi, üçgen ve sınırlı genlikli üçgen dalgalar üretildi; ADC örneğinde lojik analizörle orta konumdaki potansiyometre için 80H okundu.

Dersin sonunda kesmelere girildi: yoklama ile kesmenin farkı, yazılımsal ve donanımsal kesme kaynakları, INTR, NMI ve $\overline{INTA}$ uçları, IF ve TF bayrakları, kesme alt programının FAR olup IRET ile dönmesi ve 00000H-003FFH aralığındaki kesme vektör tablosu. Sonraki derste tanımlar tamamlanıp 8259 ile şimdiye kadar görülen bütün entegrelerin kesme tabanlı kontrolüne ve örneklere geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
