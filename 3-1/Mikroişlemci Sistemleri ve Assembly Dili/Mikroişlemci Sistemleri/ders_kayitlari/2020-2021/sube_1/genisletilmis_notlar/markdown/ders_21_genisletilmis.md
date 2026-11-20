# Ders 21 Genişletilmiş Notu: ADC Devreleri, ADC0804/DAC0830 Proteus Örnekleri ve 8086 Kesmelerine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. 8254 mod 3 üzerine soru-cevap
- 2. DAC0830 tekrarı ve testere dişi dalga
- 3. Paralel ADC
- 4. Rampa (ramp) dönüştürücü
- 5. ADC0804 entegresi
- 6. ADC0804 programlama örneği
- 7. Proteus DAC örneği: genlik ve frekans
- 8. Proteus ADC örneği ve adres çözümleme
- 9. Veri aktarım yöntemleri: polling, kesme, DMA
- 10. 8086'da kesme kaynakları
- 11. Near, far çağrı ve kesme çağrısı
- 12. NMI, INTR, INTA, IF ve TF
- 13. Kesme vektör tablosu
- 14. Kesme işleminin adımları
- 15. Bayrakları değiştiren komutlar
- Örnek Sorular

## 1. 8254 mod 3 üzerine soru-cevap

Ders, bir öğrencinin önceki haftanın 8254 ödeviyle ilgili sorusuyla başladı. Ekrandaki ödev sorusunda 8254 kullanılarak periyodik olarak 10 saniyede 40 kare dalga üretilmesi isteniyordu (ekrandan, 00:05:00).

**Soru:** Mod 3'te kare dalga ne zamana kadar üretilir, osiloskopta sürekli görülür mü?
**Cevap:** Evet. Yeni bir mod yazılmadıkça kare dalga aynı biçimde, periyodik olarak üretilir. Sayma değeri değiştirilirse yalnız frekansı değişir. Sorudaki süreler yalnız frekans hesabını biraz karmaşıklaştırmak içindir; istenen periyodik bir kare dalgadır.

**Soru:** Sayıcı hangi değeri azaltıyor, uçlara girilen değeri mi?
**Cevap:** 8254'te üç sayıcı vardır; birine odaklanmak yeterli. Sayıcının CLK ucuna sabit frekanslı bir saat bağlanır (örnekte 2 MHz) ve sayıcıya bir sayma değeri yüklenir. Mod 3'te çıkış, sayma değerinin yarısı süresince 1'de, yarısı süresince 0'da kalır. Sayıcı yüklenen değeri her saat darbesinde bir azaltır. 2 MHz'in periyodu $1/(2\times10^6)=0{,}5\,\mu s$ olduğu için azaltma 0,5 µs'de bir yapılır. Sayma bitince sayıcı yeniden başlar ve bu sürekli döner.

Hoca ikinci bir bakış açısı da verdi: yüklenen sayma değeri CLK frekansını o miktarda böler. 2 MHz'lik saat için sayma değeri 1000 yüklenirse çıkış $2\,\text{MHz}/1000=2\,\text{kHz}$ olur (mod periyodikse).

## 2. DAC0830 tekrarı ve testere dişi dalga

### 2.1 Analog dünya ile sayısal sistem

Fiziki dünya analogdur, ama bilgisayarlar yüksek frekanslı sayısal kontrol sistemleridir. Dış dünyadan okunan analog değerler analogdan sayısala çevrilip (ADC) sisteme alınır. Sistemin ürettiği sayısal kontrol işaretleri de sayısaldan analoga çevrilip (DAC) dış dünyaya verilir. Bu iş için iki yardımcı entegre kullanılır: DAC0830 ve ADC0804.

### 2.2 DAC0830 kara kutusu

DAC0830 bir kara kutu gibi ele alınır: içindeki opamp ve benzeri yapılar önceki derste anlatıldı, ama kullanırken içeride olanların otomatik gerçekleştiği varsayılır. Dışarıdan görülen uçlar 8 bitlik veri yolu, $\overline{CS}$, $\overline{WR}$ ve analog çıkıştır. Çalışması için gereken diğer bağlantılar hazır verilir. Cihazın adres ucu yoktur; bu yüzden G/Ç uzayında $2^0=1$ bayt yer kaplar, yani tek bir adresi vardır.

Zamanlama diyagramında (ekrandan, 00:10:00) $\overline{CS}$ (ve ILE) aktifken veri uçlarına geçerli değer konur, $\overline{WR}$ darbesi uygulanır. Yazmadan belli bir süre ($t_S$) sonra çıkış dalgalanmayı bitirip ±½ LSB içinde kararlı değere oturur.

Bunların hepsini tek bir komut sağlar. DAC'nin adresine `OUT` ile değer gönderildiğinde adres çözümleme devresi o adres için $\overline{CS}$ üretir; `OUT` bir yazma işlemi olduğu için $\overline{WR}$ aktif olur; gönderilen değer de veri yoluna çıkar.

### 2.3 Testere dişi örneği

Soru, "DAC0830 entegresi 1000H adresine yerleştirilmiştir; bu kod parçası ne tür bir çıkış üretir?" biçimindedir. Kod (ekrandan, 00:15:00):

```text
        MOV DX, 1000H
        MOV AL, 00H
TEKRAR:
        OUT DX, AL
        CALL DELAY
        INC AL
        JMP TEKRAR
```

AL 00H'den başlar ve her adımda bir artar. FFH'ye geldikten sonra bir artırma daha onu 00H'ye düşürür. Böylece 00H-FFH arasındaki değerler DAC'ye periyodik olarak gönderilir. Cihaz 8 bitlik olduğu için 00H 0 V'a, FFH 5 V'a karşılık gelir ve aradaki değerler doğrusal olarak artar. Gerilim-zaman grafiği 0'dan başlayarak merdiven gibi yükselir; her basamağın yatay genişliği DELAY fonksiyonunun beklediği süredir. 5 V'a ulaşıldıktan sonraki adımda çıkış birden 0'a düşer. Bu dalga şekline testere dişi denir.

Başka dalga şekilleri de istenebilir: çıkış birden düşmek yerine adım adım azalırsa üçgen dalga oluşur. Daha zor bir örnek olarak sinüzoidal dalga da istenebilir. Bunların hepsi DAC ile üretilebilir.

### 2.4 Çözünürlük

8 bitlik DAC 00H ile FFH arasında 256 kademe gösterir. 00H 0 V'a, FFH 5 V'a karşılık geldiğinde ikili değer bir arttığında gerilimdeki artış 5 V/256 olur. Aynı mantıkla 10 bitlik bir cihazda adım 5 V/$2^{10}$ = 5 V/1024 olur.
<!-- BELİRSİZ: 00:15:22'de altyazı karışık ("FFH, 8 bitlik bir cihaz olduğunu varsayalım ... 5 volt bölü 2 üzeri 10"); hocanın 10 bitlik bir cihazı kastettiği varsayıldı. -->

> **Ders sonrası not:** FFH tam 5 V verseydi adım 5 V/255 ≈ 19,6 mV olurdu. DAC0830'da çıkış büyük olasılıkla $V_{REF}\cdot D/256$ biçimindedir; o zaman adım 5 V/256 ≈ 19,5 mV, FFH için çıkış ≈ 4,98 V olur.

## 3. Paralel ADC

ADC, fiziki dünyadaki analog bir değerin ikili karşılığını elde etmek için kullanılan yapıdır. İlk donanım örneği paralel ADC'dir (ekrandan, 00:20:00). Önemli özelliği hızıdır: girişteki analog değere karşılık bütün bitler tek seferde hesaplanır. Bunun için farklı referans gerilimleri gerekir.

### 3.1 Gerilim bölücü

Bir referans gerilimi bir direnç dizisiyle bölünür. Hesabı kolaylaştırmak için hoca referansı 7 V aldı. Dizide yedi eşit R direnci vardır, toplam direnç 7R'dir. Koldaki akım:

$$I=\frac{7V}{7R}$$

En alttaki düğümün gerilimi (V7 diye adlandırıldı):

$$V_7=I\cdot R=\frac{7V}{7R}\cdot R=1\,\text{V}$$

Bir üstteki düğümde iki R üzerinden gerilim düştüğü için 2 V vardır; aynı mantıkla yukarı doğru 3, 4, 5, 6 V elde edilir. En üstteki karşılaştırıcının eşiği doğrudan 7 V'tur. Böylece referanstan eşit aralıklı gerilimler elde edilir.

Kaç adıma bölüneceği çıkışın bit sayısına bağlıdır. 3 bitlik çıkış için $2^3=8$ seviye gerekir: 7, 6, 5, 4, 3, 2, 1 V eşikleri ve sekizinci değer olarak 0.

### 3.2 Karşılaştırıcı ve öncelikli kodlayıcı

Giriş gerilimi her eşikle bir karşılaştırıcıda karşılaştırılır. Karşılaştırıcının çalışması:

$$\text{çıkış}=\begin{cases}1, & V_+>V_-\\ 0, & V_-\ge V_+\end{cases}$$

İkinci katta 8'den 3'e öncelikli kodlayıcı (priority encoder) vardır. En anlamlı girişi I7 (en üst karşılaştırıcı), en anlamsızı I0'dır. Kodlayıcı en anlamlı girişten başlayarak 1 gördüğü ilk girişin numarasını ikili olarak verir.

Örnek 1: Giriş 8 V ise bütün karşılaştırıcılar 1 verir. Kodlayıcı yukarıdan bakınca ilk 1'i I7'de görür, çıkış 111 olur. Sistem 8 V'u 111 olarak kodlamıştır.

Örnek 2: Giriş 3 V olsun. 7, 6, 5, 4 V eşikli karşılaştırıcılar 0 verir; 3 V eşiğinde de giriş eşiğe eşit olduğundan çıkış 0'dır. 2 V ve 1 V eşikli karşılaştırıcılar 1 verir. İlk 1 I2'dedir, çıkış 010 yani ikili 2 olur.

Özetle paralel ADC, gerilim bölücü direnç dizisi, karşılaştırıcılar ve öncelikli kodlayıcıdan oluşur.

## 4. Rampa (ramp) dönüştürücü

İkinci ADC yapısı rampa dönüştürücüdür (ekrandan, 00:25:00). İçinde bir sayıcı (CTR), sayıcı çıkışını analoga çeviren bir DAC, bir karşılaştırıcı ve bir kaydırmalı yazmaç (SRG) vardır. Yani içinde DAC bulunan bir ADC'dir. Karşılaştırıcının + ucunda $V_{in}$, − ucunda DAC çıkışı vardır.

Örnekte $V_{in}=2{,}5$ V alınır. Sayıcı başlangıçta 00H ile yüklüdür; DAC çıkışı 0 V'tur. 2,5 V > 0 V olduğu için karşılaştırıcı çıkışı 1'dir. Bu çıkış sayıcının aktif sıfır $\overline{Load}$ ucuna gider; ucu 1 olduğu için sayıcı girişlerdeki sıfırları yeniden yüklemez ve her saat darbesinin yükselen kenarında bir artar: 00, 01, 02, 03, … Bu sırada SRG'nin içindeki değerin bir önemi yoktur.

Sayıcı arttıkça DAC çıkışı 0 V'tan yükselir. DAC çıkışı 2,5 V'u geçtiği anda karşılaştırıcı çıkışı 0'a döner. Bu anda sayıcının o anki değeri asenkron olarak SRG'ye yüklenir; hoca bunu kabaca 7FH civarı diye verdi. Aynı anda $\overline{Load}$ ucuna 0 gelir ve sayıcı bir sonraki saat kenarında yeniden 0 ile yüklenir.

> **Ders sonrası not:** Tam ölçek 5 V ve adım 5 V/256 alınırsa 2,5 V, 128 = 80H'ye karşılık gelir; DAC çıkışı 2,5 V'u 80H civarında geçer. Hocanın "7FH gibi" demesi kaba bir tahmindir.

Bu yapının sakıncası süresidir: sonuç için DAC çıkışının 0'dan giriş gerilimine kadar adım adım yükselmesi beklenir. Giriş ne kadar büyükse dönüşüm o kadar uzun sürer.

## 5. ADC0804 entegresi

8086 ile uyumlu ADC entegresi ADC0804'tür. Bu da kara kutu olarak ele alınır (ekrandan, 00:30:00). Kullanılan uçlar $\overline{CS}$, $\overline{RD}$, $\overline{WR}$, $\overline{INTR}$, analog giriş (VIN+, bir potansiyometreden) ve DB0-DB7 veri uçlarıdır. Saat işareti kara kutunun içinde kabul edilir.

ADC0804'ün de adres ucu yoktur; G/Ç uzayında $2^0=1$ bayt kaplar ve tek bir adresi vardır.

Rampa dönüştürücüde olduğu gibi, dönüşüm için bir tetik gerekir ve dönüşüm biraz zaman alır. Dönüşüm bitmeden yeni dönüşüm istenirse anlamlı bir sonuç alınamayabilir. Bu yüzden tetikten sonra cevap beklenir; beklemenin ne zaman biteceği $\overline{INTR}$ ucundan anlaşılır.

Zamanlama (ekrandan, 00:35:00): Dönüşüm, cihaz $\overline{CS}$ ile seçiliyken bir $\overline{WR}$ darbesiyle başlar. $\overline{WR}$'den sonra $\overline{INTR}$ 1'e çıkar ve dönüşüm süresince 1'de kalır. Dönüşüm bitince sonuç çıkış tutucularında geçerli olur ve $\overline{INTR}$ 0'a iner. Bundan sonra cihaz yine seçilip bir $\overline{RD}$ işaretiyle, yani `IN` komutuyla sonuç okunur.

### 5.1 INTR ucu için ayrı bir G/Ç cihazı

Kesmeler henüz görülmediği için $\overline{INTR}$ ucu şöyle değerlendirilir: bu uç da sanki bir veri ucuymuş gibi bir 74125 üç durumlu tamponla (tri-state buffer) ikinci, 1 bitlik bir G/Ç cihazına dönüştürülür (ekrandan, 00:30:00). Bu cihazın tek görevi $\overline{INTR}$ değerini veri yolu üzerinden işlemciye aktarmaktır. Tamponun izin ucu bu küçük cihazın $\overline{CS}$ ucudur; adres çözümlemeden gelen ayrı bir seçim işareti buraya bağlanır. Tamponun çıkışı veri yolunun en anlamlı ucu AD7'ye bağlanır. Bu cihaz da G/Ç uzayında 1 bayt kaplar.

Sonuçta iki adres vardır: ADC'nin adresi ve tampon cihazının adresi. İşlem sırası:

1. ADC'nin adresine yazarak dönüşümü başlat.
2. Tampon cihazının adresinden oku, en anlamlı bit 0 oldu mu diye bak; olmadıysa okumaya devam et (polling).
3. Bit 0 olunca dönüşüm bitmiştir; ADC'nin adresinden okuyarak sonucu al.

> **Hocanın vurgusu:** "Burayı anlamak çok önemli." ADC'ye yazma ile dönüşüm başlar, $\overline{INTR}$ cihazı yoklanır, $\overline{INTR}$ 0 olunca ADC okunur. Kısaca: if $\overline{INTR}=0$, `IN` ADC0804.

## 6. ADC0804 programlama örneği

Sorunun açıklaması: ADC0804, G/Ç uzayında 200H adresine yerleştirilmiştir. ADC'nin $\overline{INTR}$ ucu için 400H adresine sahip bir G/Ç cihazı tanımlanmıştır; yani $\overline{INTR}$'yi süren üç durumlu tampon 400H'ye bağlıdır. Amaç, ADC'nin girişindeki analog değerin sayısal karşılığını okumaktır.

Kod (slayt 17; ekrandan, 00:40:00):

```text
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
<!-- BELİRSİZ: kod, 00:40:00 karesindeki PowerPoint küçük resminden okundu; altyazıdaki anlatımla uyumlu. -->

Adımlar:

- Adres 8 bite sığmadığı için DX kullanılır. 200H'ye yapılan `OUT` hem $\overline{CS}$ hem $\overline{WR}$ üretir ve dönüşümü başlatır. AL'ye konan değerin hiçbir önemi yoktur.
- 400H'den okuma yapılır. Bu cihazın yalnız AD7 ucunda anlamlı değer vardır, diğer uçlar boştadır. Okunan değer `TEST AL, 80H` ile sınanır.
- Sonuç sıfır değilse $\overline{INTR}$ hâlâ 1'dir, okuma ve test tekrarlanır. Sonuç sıfırsa en anlamlı bit 0'dır, dönüşüm bitmiştir.
- 200H'den yapılan `IN` cihazı seçer ve $\overline{RD}$ üretir; sonuç AL'ye okunur. Kısa bir beklemeden sonra döngü yeni bir dönüşüm başlatır.

**Soru:** $\overline{INTR}$ AD7'ye bağlıysa, ADC sonucunun en anlamlı biti de AD7'den gelir; ikisi karışmaz mı? (soru bağlantı sorunu nedeniyle altyazıda tam duyulmuyor, cevaptan kuruldu)
**Cevap:** ADC ve tampon cihazı farklı adreslere yerleştirilmiştir (örnekte 200H ve 400H), bu yüzden aynı anda seçilmezler. ADC seçiliyken tamponun çıkışı yüksek empedanstadır, sanki hattan kopmuş gibidir; tampon seçiliyken de ADC'nin veri uçları yüksek empedanstadır. İşlemci bir anda ya tamponla konuşup $\overline{INTR}$ değerini okur ya da ADC ile konuşup dönüşüm sonucunu okur. Bağlantı MSB ile $\overline{INTR}$'yi birbirine bağlamış gibi görünse de öyle değildir.

## 7. Proteus DAC örneği: genlik ve frekans

### 7.1 Devre ve kod

Proteus'taki devre derste anlatılanın aynısıdır (ekrandan, 00:50:00). DAC0830 1000H adresine yerleştirilmiştir; veri uçları işlemcinin veri uçlarına bağlıdır, VREF'e −5,1 V bağlıdır ve çıkış bir opamp üzerinden osiloskopun A kanalına verilmiştir. Amaç testere dişi üretmektir. Osiloskopta A kanalında testere dişi görüldü.

Kod (ekrandan, 00:45:00):

```text
        MOV DX, 1000H
        MOV AL, 00H
ENDLESS:
        OUT DX, AL
        CALL DELAY
        INC AL
        JMP ENDLESS

DELAY PROC NEAR
        PUSH CX
        MOV CX, 00FFH
L1:     LOOP L1
        POP CX
        RET
DELAY ENDP
```

Adres 8 bite sığmadığı için DX kullanılır. Sonsuz döngüde sıradaki değer gönderilir, beklenir, değer artırılır. DELAY, CX'i 00FFH'den 0'a kadar boş bir döngüde azaltır. DELAY içinde CX geçici olarak kullanıldığı ve dönüş değeri taşımadığı için, çağıran programın değeri bozulmasın diye fonksiyona girerken `PUSH CX`, çıkmadan önce `POP CX` yapılır.

### 7.2 Birinci parametre: genlik

Osiloskopta minimum değer 0 V, tepe değeri 5 V civarındaydı (hoca imleci tam koyamadığı için 4,90 küsur ile 5 küsur arasında bir değer okudu). FFH'ye varmadan sıfıra dönülürse tepe genliği azalır. Bunun için `INC AL` sonrasına şu eklendi:

```text
        INC AL
        CMP AL, 7FH
        JBE DEVAM
        XOR AL, AL
DEVAM:
```

AL 7FH'den büyük olunca sıfırlanır, değilse olduğu gibi devam edilir. Değer 0'dan 7FH'ye kadar artar, sonra yeniden 0 olur. Çıktı 0-5 V yerine yaklaşık 0-2,5 V oldu. Teorik tepe değeri bağlanan 5,1 V'tur; 7FH'de kesildiği için yaklaşık yarısı elde edilir.

> **Ders sonrası not:** Hoca bu değeri "2.9 volt olarak gerçekleşmiş" diye okudu (00:47:44). VREF 5,1 V iken 7FH için beklenen çıkış büyük olasılıkla $5{,}1\cdot127/256\approx2{,}53$ V'tur; hoca hemen öncesinde de "0 ile 2.5 volt arasında" demişti.

### 7.3 İkinci parametre: frekans

Osiloskop tek çekim (one shot) ve duraklatma ile incelendi: işaret yaklaşık −220 ms'den yükselmeye başlayıp 180 ms'de sıfıra düşüyordu, yani periyot yaklaşık 400 ms'dir.

Frekans, her değerin hatta kalma süresi değiştirilerek ayarlanır. DELAY'de CX'e daha büyük bir değer yüklenirse periyot uzar, frekans düşer. CX 01FFH yapıldığında periyot yaklaşık 800 ms ölçüldü; iki katına çıktı. Bu beklenen sonuçtur: döngü sayısı FFH'den (kabaca 100H) 1FFH'ye (kabaca 200H) çıktı, periyot da doğrusal olarak iki katına çıktı ($511/255\approx2{,}0$).
<!-- BELİRSİZ: 00:49:19'da altyazıda CX'e "FFF" yüklendiği geçiyor; hoca 00:51:16'da "1FFH, yani 200H" dediği için değer 01FFH kabul edildi. -->

> **Hocanın vurgusu:** DAC'de genlik ve periyot parametrelerini uygun ayarlayarak istenen frekans ve genlikte dalga üretmek lablarda ve sınavlarda istenebilir.

**Soru:** İşlemcinin frekansı dalga şeklini etkiler mi? (soru altyazıda duyulmuyor, cevaptan kuruldu)
**Cevap:** Kesinlikle etkiler. Bekleme bir yazılım döngüsüyle yapıldığı için `LOOP` döngüsünün ne kadar sürdüğü tamamen işlemcinin saat frekansına bağlıdır. Bekleme 8254 gibi sabit frekanslı bir kaynaktan beslenen bir zamanlayıcıyla yapılsaydı, saat frekansından daha bağımsız bir sonuç elde edilirdi.

## 8. Proteus ADC örneği ve adres çözümleme

### 8.1 Devre ve lojik analizör

Bir potansiyometre ölçülecek analog girişi üretir. ADC0804'ün veri uçları işlemciye bağlıdır; ADC için bir adres çözümleme devresi $\overline{CS}$ üretir. Aynı adres çözümleme ile $\overline{INTR}$ için 1 bitlik bir G/Ç cihazı daha oluşturulmuştur; anlamlı biti veri yolunun en anlamlı bitindedir. Değerleri görmek için bir lojik analizör kullanıldı (ekrandan, 00:55:00).

Lojik analizör tamponun seçim ucuyla tetiklenirse $\overline{INTR}$ her yoklandığında bir yakalama olur ve veri uçlarındaki ara (kaçak) değerler de görülür. $\overline{INTR}$ ucunun kendisiyle, yalnız düşen kenarda tetiklenirse, dönüşümün bittiği andaki anlamlı veri yakalanır. Potansiyometre %100'deyken FFH, %50 civarındayken 80H görüldü. Böylece okumanın $\overline{INTR}$'nin sıfıra düştüğü anda yapılabileceği gösterildi.

### 8.2 Adres çözümleme

Devrede ADC 200H'de, $\overline{INTR}$ cihazı 400H'dedir (ekrandan, 01:00:00). Adres çözümleme bütün G/Ç uzayını çözmemektedir, ama bu iki adres için doğru seçim ürettiği kontrol edildi:

- 74154 (4'ten 16'ya kod çözücü) girişleri: A = A9, B = A10, C = A11, D = A12.
- E1 (aktif sıfır): A13, A14, A15 bir 7427 NOR kapısına, NOR çıkışı bir NOT kapısına girer. E1 = 0 için A13 = A14 = A15 = 0 olmalıdır.
- E2 (aktif sıfır): A0 ile M/$\overline{IO}$ bir OR kapısına girer. E2 = 0 için A0 = 0 ve M/$\overline{IO}$ = 0 olmalıdır.
- IO1 çıkışı için A = 1, B = C = D = 0 gerekir: yalnız A9 = 1, yani adres $2^9$ = 200H.
- IO2 çıkışı için B = 1, diğerleri 0: yalnız A10 = 1, yani adres $2^{10}$ = 400H.

Program derstekiyle aynıdır: 200H'ye boş bir yazma ile dönüşüm başlatılır, 400H'deki cihaz okunup en anlamlı biti test edilir, sonuç sıfır değilse $\overline{INTR}$ hâlâ 1'dir ve döngüde kalınır. $\overline{INTR}$ 0 olunca 200H'deki ADC okunur, bir süre beklenip yeni dönüşüm başlatılır.

### 8.3 Karma örnek fikri

Hoca ipucu olarak bir karma örnek tarif etti: iki sinyalin üst üste binmesiyle oluşmuş bir analog işaret ADC ile okunup sayısala çevrilir, yüksek frekanslı bileşen sayısal olarak süzülür ve süzülmüş sonuç DAC ile tekrar analog olarak dış dünyaya verilir.

**Soru:** 8254 lab sorusunda osiloskopta görülen dalga tam kare olmuyor; bir ayar mı gerekiyor?
**Cevap:** Proteus'taki osiloskoptan kaynaklanıyor olabilir. Testere dişi örneğinde de FFH'den sonra dikey düşüş yerine çok dik bir eğim görünmüştü. 8254 mod 3'e ayarlanıp uygun sayma değeri verildiyse sorun yoktur.

## 9. Veri aktarım yöntemleri: polling, kesme, DMA

Aradan sonra kesme konusuna geçildi. Konu başlıkları slaytta: polling-interrupt, kesme kaynakları (donanım ve yazılım), kesme vektör tablosu, kesme adımları, özel kesme alt programı yazma (DIV0), donanımsal kesmeler (NMI, INTR) ve 8259A (uç tanımları, iç yapı, ICW ve OCW ile ayarlama, örnek) (ekrandan, 01:25:00). Bu derste donanımsal kesme uçlarına kadar ilerlendi.

### 9.1 Polling

Şimdiye kadar görülen bütün yardımcı devrelerde işlemin bitip bitmediği kontrol edildi. 8255'te el sıkışmada verinin hazır olup olmadığı bir bitin yoklanmasıyla anlaşılıyordu. 8251'de veri göndermeye ya da almaya hazır olup olmadığı yine birer bit üzerinden yoklanıyordu. 8254'te doğrudan OUT ucu kontrol ediliyordu. ADC örneğinde $\overline{INTR}$ ayrı bir cihaz olarak okunuyordu.

Bunların hepsi polling mantığıdır: cihazdan aktif olarak okuma yapılır, ilgili bitler maskelenir, istenen durum oluşmuş mu diye bakılır; oluşmamışsa kontrol tekrarlanır. Durum oluşunca okuma ya da yazma yapılır. Polling tanımı gereği işlemciyi bloklar: kontrol sürerken işlemci başka bir işle uğraşamaz.

### 9.2 Kesme tabanlı aktarım

İşlemci yardımcı cihazı uygun biçimde programladıktan sonra, ilgili koşul oluştuğunda kesme istek ucu üzerinden uyarılır. İşlemci o sırada başka işlerle uğraşabilir; uyarı geldiğinde gerekli işlemi yapar. Koşulun hazır olduğu donanımsal olarak bildirilmiş olur.

### 9.3 DMA

Üçüncü yöntem Direct Memory Access'tir. DMA dışındaki bütün durumlarda bir G/Ç cihazından okunan veri önce işlemciye alınır, sonra öbür cihaza yazılır. DMA'da ise işlemci, ara devreyi programladıktan sonra devreden çekilir. DMA denetleyicisi iki G/Ç cihazını ya da bir G/Ç cihazı ile belleği aynı anda etkinleştirir, ne kadar veri aktarılacağını da denetleyerek aktarımı kendisi yapar.

### 9.4 Kova benzetmesi

Hoca polling ile kesmeyi bir benzetmeyle anlattı (ekrandan, 01:30:00). Sınav var ve su kesilmiş. Varil kovayla doldurulmalı, ders de çalışılmalı, ama kova taşmamalı. Öğrenci ara ara gidip kovayı kontrol eder, dolunca varile boşaltıp dersine döner: bu polling'dir. Suyun ne zaman dolacağı belli değildir, sürekli kontrol gerekir ve geç kalınırsa kova taşabilir (veri kaybı).

Kesme benzetmesinde öğrenci bir düzenek kurar: kova dolunca bir hoparlör çalar (kesme isteği). Öğrenci dersini yalnız uyarı geldiğinde keser, kovayı varile boşaltır ve dersine döner.

Buradan bir ilke çıkar: kovayı boşaltma işi kısa sürmelidir.

> **Hocanın vurgusu:** Kesme alt programları mümkün olduğunca kısa sürede dönecek biçimde tasarlanmalıdır. Bu, mikrodenetleyici programlamada da geçerli bir ilkedir.

## 10. 8086'da kesme kaynakları

Slayttaki özet (ekrandan, 01:35:00): yazılımsal olarak INT, INTO, INT 3; donanımsal olarak INTR, NMI; donanım kesmesinin onayı $\overline{INTA}$; kesmeyle ilgili bayraklar IF, TF; dönüş komutu IRET.

Yazılımsal kaynakta bazı komutlar doğrudan kesme fonksiyonu çağırır. `INT` komutunun yanına yazılan 8 bitlik değerle INT 00H'den INT FFH'ye kadar tanımlanabilecek her kesme alt programı tetiklenebilir. Bu yüzden toplam 256 farklı kesme tipi (vektör tipi) vardır. Özel bir komut olarak `INTO` (interrupt on overflow), taşma oluşmuşsa kesmeyi tetikler.

## 11. Near, far çağrı ve kesme çağrısı

Kesme özel bir fonksiyon gibi düşünülebilir. Farkı görmek için önce normal çağrılar hatırlatıldı.

Near tipinde bir fonksiyon çağrıldığında, bir sonraki komuta karşılık gelen IP değeri yığına atılır ve IP, çağrılan fonksiyonun başlangıç adresiyle güncellenir. `RET` yığının en üstündeki değeri IP'ye yükler.

Far tipinde fonksiyon başka bir segmentin başka bir offsetindedir. Önce mevcut CS yığına atılır, sonra CALL'dan sonraki komutun offseti (IP) yığına atılır. Çağrılan fonksiyonun segment ve offset değerleri CS ve IP'ye yüklenir. `RETF` yığının en üstündeki değeri IP'ye, sıradakini CS'ye yükler; program CALL'dan sonraki komutla devam eder.

Kesmelerde bayrakların durumunun da korunması gerekir. Bu yüzden kesme çağrıldığında yığına önce bayrak yazmacı, sonra mevcut CS, sonra INT'ten sonraki komutun offseti atılır ve kesme alt programının segment ve offset değerleri yüklenir. Dönüş `IRET` (interrupt return) ile yapılır. Yalnız `RETF` kullanılsaydı yalnız IP ve CS çekilirdi, oysa bayraklar da yığına atılmıştır. `IRET` yığının en üstündeki değeri IP'ye, sıradakini CS'ye, sıradakini bayrak yazmacına atar. Böylece üç çağrı tipi ve üç dönüş tipi vardır.

## 12. NMI, INTR, INTA, IF ve TF

### 12.1 NMI ve INTR

8086'nın iki donanımsal kesme ucu vardır: INTR (interrupt request) ve NMI (non-maskable interrupt).

NMI ucundan istek gelirse işlemcide her zaman tip 2 kesmesi tetiklenir; tip baştan bellidir. Yazılımsal kesmede tip, INT komutunun yanında doğrudan verilir.

INTR ucundan istek gelirse işlemci tipi veri yolundan öğrenir. İşlemci veri uçlarının düşük anlamlı 8 bitini örnekleyerek bir değer okur; bu değer kesme tipidir. Yani INTR üzerinden kesme göndermek isteyen yardımcı cihaz önce isteği gönderir, sonra kendisine atanmış kesme tipini veri yolunun düşük baytına koyar.

INTR isteklerinin el sıkışma mantığında bir cevabı da vardır: aktif sıfır $\overline{INTA}$ (interrupt acknowledge) ucu. İşlemci kesme tipini ancak isteği $\overline{INTA}$ ile onayladıysa okur ve değerlendirir.

> **Ek bilgi (derste anlatılmadı):** 8086'da INTR onayı büyük olasılıkla art arda iki $\overline{INTA}$ darbesiyle yapılır; kesme tipi ikinci darbe sırasında veri yolunun düşük baytından okunur. 8259 gibi kesme denetleyicileri bu el sıkışmaya uygun tasarlanmıştır.

NMI'nın adı da önemlidir: INTR istekleri IF bayrağıyla kapatılabilir, NMI istekleri hiçbir bayrakla kapatılamaz. Bu yüzden NMI'ya sistem açısından kritik istekler bağlanır. Örneğin bellek yoksa ya da açılışta bazı eksikler varsa sistemin uyarı verip açılmaması, ya da besleme gerilimi kararlı bir değere ulaşmadığında sistemin açılmasının engellenmesi NMI ile sağlanabilir.

### 12.2 IF ve TF bayrakları

IF bayrağı INTR ucunun etkin olup olmadığını belirler. IF = 0 ise INTR'den ne kadar istek gelirse gelsin değerlendirilmez. IF = 1 ise işlemci $\overline{INTA}$ ile onay verdikten sonra veri yolundaki tipe göre kesme karşılanır.

TF bayrağı 1 olduğu sürece her komut yürütüldükten sonra otomatik olarak bir kesme oluşur. Bunun amacı tek adımlı (single step) hata ayıklamadır.

> **Ders sonrası not:** Hoca TF ile oluşan kesmenin "tip 3" olduğunu söyledi (01:40:18); 01:46:54'te kendisi düzeltti: tek adım kesmesi tip 1'dir, tip 3 breakpoint kesmesidir.

IF = 1 iken INTR'den istek gelip kesme alt programına dallanıldığını düşünelim. IF hâlâ 1 olsaydı alt program içindeyken yeni bir istek gelince kesme içinde kesme oluşurdu. Bu yüzden varsayılan olarak kesme alt programına gidilirken IF ve TF sıfırlanır; iç içe kesme engellenir.

## 13. Kesme vektör tablosu

Slayttaki tanım (ekrandan, 01:45:00): kesme oluştuğunda mevcut CS:IP ile gösterilen kodun yürütülmesi bırakılır, kesmeye ilişkin fonksiyonun bulunduğu kesim ve offsetteki kod işlenir. Her kesmenin fonksiyonunun hangi bellek adresinde olduğu kesme vektör tablosunda tutulur.

256 kesme tipinin bir kısmı donanıma, bir kısmı BIOS'a, bir kısmı DOS işletim sistemine, bir kısmı kullanıcı programlarına ayrılmıştır. Tetiklenen tip ile çağrılacak alt program bu tablo üzerinden eşleşir.

Tablo belleğin en düşük kısmındadır ve 256 gözden oluşur; her kesme tipine bir göz düşer. Her göz 4 bayttır, toplam boyut $256\times4=1024$ bayttır. Gözün 2 baytı offset, 2 baytı segment değeridir: düşük adreste offset (word), yüksek adreste segment (word) bulunur. Tip 0 gözü 0H'den, tip 1 gözü 4H'den, tip 2 gözü 08H'den başlar; genel olarak tip $n$'nin gözü $4n$ adresindedir (ara adım eklendi).

Örneğin tip 15 bir kesme tetiklenirse tablonun 15 numaralı gözüne gidilir, ilk word IP'ye, ikinci word CS'ye yüklenir. Bu değerleri önceden kim yazmıştır? Bir BIOS kesmesiyse BIOS yazılımı, işletim sistemi açılırken işletim sistemi ya da program çalıştığı sürece kendi kesme alt programları için kullanıcı programı yazmış olabilir.

> **Ek bilgi (derste anlatılmadı):** Tablonun 1024 baytı büyük olasılıkla 00000H-003FFH fiziksel adres aralığıdır. Bir kesme alt programının adresi, tablodaki ilgili göze yazılarak kullanıcı tarafından tanımlanabilir; slaytın sonraki konusu olan "özel kesme alt programı yazma (DIV0)" bunu ele alır.

Özel tipler:

| Tip | Anlam |
|---|---|
| 0 | Sıfıra bölme (DIV komutunda bölen 0) |
| 1 | Tek adım (TF bayrağı) |
| 2 | NMI ucundan gelen istek |
| 3 | Kesme noktası (breakpoint) |
| 4 | Taşma (INTO) |

Bunların dışında belirli bir alan BIOS ve işletim sistemine, geri kalanı kullanıcıya ayrılmıştır.

## 14. Kesme işleminin adımları

Slayttaki adımlar (ekrandan, 01:50:00). Sıradaki işlem bittiğinde işlemci:

1. Komut işlemeyle oluşan kesme, single-step, NMI, INTR ve INT sırasıyla bir kesme olup olmadığını kontrol eder.
2. Kesme varsa: PUSHF.
3. IF ← 0, TF ← 0 (INTR ve single-step kesmeleri engellenir).
4. PUSH CS.
5. PUSH IP.
6. IP ← kesme vektör tablosu, CS ← kesme vektör tablosu.

Bu PUSHF, PUSH CS, PUSH IP işlemlerini programcı yazmaz; işlemci kendisi yapar. Önce dönüş bilgisi kaybolmasın diye yığına değerler atılır, iç içe kesmeyi engellemek için bayraklar sıfırlanır. Sonra tetiklenen kesmenin tipi bellidir: NMI tip 2, single step tip 1, INTR'nin tipi veri yolundan okunur, INT komutunda tip komutun yanında verilir. İşlemci tabloda bu tipin gözünden offseti IP'ye, segmenti CS'ye alır ve alt programa geçer.

Alt programda gereken işlem yapılır; örneğin 8255 el sıkışmada veri hazırsa veri okunur. Dönüş IRET ile olur: yığından sırasıyla IP, CS ve bayraklar alınır.

Bayraklar yığına atıldıktan sonra IF ve TF sıfırlandığı için, alt programda bunlarla ilgili bir işlem yapılmadıysa IRET'e kadar 0 kalırlar. Kesmeden önce IF = 1 idiyse, IRET yığındaki eski bayrak değerini geri yüklediğinde IF kendiliğinden yeniden 1 olur.

## 15. Bayrakları değiştiren komutlar

IF için iki özel, parametresiz komut vardır: `STI` (Set Interrupt Flag) IF'yi 1, `CLI` (Clear Interrupt Flag) IF'yi 0 yapar.

TF için böyle bir komut yoktur. TF ya da diğer bayraklarda bit işlemi yapmak için bayrak yazmacı yığına atılır (`PUSHF`), yığının üstünde bit işlemi yapılır ve değer yeniden bayrak yazmacına yüklenir (`POPF`). Diğer bir yol `LAHF` ve `SAHF` komutlarıdır: `LAHF` bayrak yazmacının 8 bitini AH'ye alır, AH'de bit işlemi yapılır, `SAHF` ile geri yazılır.

> **Ek bilgi (derste anlatılmadı):** TF, bayrak yazmacının yüksek baytındadır (bit 8). `LAHF`/`SAHF` yalnız düşük baytı (SF, ZF, AF, PF, CF) taşıdığı için TF büyük olasılıkla yalnız `PUSHF`/`POPF` yoluyla değiştirilebilir.

Kesme örneklerine bir sonraki derste devam edileceği söylendi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00): 78H adresinden itibaren ardışık çift adreslere yerleştirilmiş 8254 kullanarak periyodik olarak 10 sn'de 40 tane kare dalga üretmek için gerekli tasarımı yapınız. Kullanacağınız 8254 için saat (1 saat için) işaretinin frekansının 2 MHz olduğunu kabul ediniz.

Derste yalnız sorunun periyodik bir kare dalga istediği ve sürelerin frekans hesabını karmaşıklaştırmak için verildiği söylendi.

> **Çözüm (derste verilmedi):** 10 s'de 40 dalga, $f=40/10=4$ Hz demektir. Gereken bölme $2\times10^6/4=500000$'dir; bu 65536'dan büyük olduğu için tek sayıcı yetmez, iki sayıcı kaskat bağlanır (CNTR0'ın OUT'u CNTR1'in CLK'ına). Örneğin CNTR0 mod 3'te 1000 (03E8H) ile 2 kHz, CNTR1 mod 3'te 500 (01F4H) ile 4 Hz üretir; $1000\times500=500000$. Adresler: CNTR0 78H, CNTR1 7AH, CNTR2 7CH, kontrol 7EH. İkili sayma, önce LSB sonra MSB, mod 3 için kontrol sözcükleri CNTR0: `00 11 011 0B` = 36H, CNTR1: `01 11 011 0B` = 76H. Sayma değerlerinin çarpımı 500000 olan başka seçimler de geçerlidir.

**Soru 2** (derste sözlü, 00:04:09): 8254'ün CLK ucuna 2 MHz bağlı ve sayıcıya 1000 yükleniyor. Sayıcı ne sıklıkla azalır, periyodik modda çıkış frekansı nedir?

Çözüm (derste verildi): Saat periyodu $1/(2\times10^6)=0{,}5\,\mu s$'dir; sayıcı 0,5 µs'de bir azalır. Çıkış frekansı $2\,\text{MHz}/1000=2\,\text{kHz}$'dir.

**Soru 3** (ekrandan, 00:15:00): DAC0830 entegresi 1000H adresine yerleştirilmiştir. `MOV DX,1000H / MOV AL,00H / TEKRAR: OUT DX,AL / CALL DELAY / INC AL / JMP TEKRAR` kod parçası bu cihazda ne tür bir çıkış üretir?

Çözüm (derste verildi): AL 00H'den FFH'ye birer artar, sonra 00H'ye döner. Çıkış 0 V'tan 5 V'a basamaklarla yükselip birden 0 V'a düşer: testere dişi dalga. Basamak genişliği DELAY süresidir, adım 5 V/256'dır.

**Soru 4** (ekrandan, 00:20:00): $V_{ref}=7$ V ve yedi eşit dirençli 3 bitlik paralel ADC'de giriş 8 V ve 3 V iken çıkış nedir?

Çözüm (derste verildi): Eşikler 1, 2, …, 7 V'tur. 8 V'ta bütün karşılaştırıcılar 1, öncelikli kodlayıcı I7'yi görür: 111. 3 V'ta yalnız 1 V ve 2 V eşikli karşılaştırıcılar 1 verir, ilk 1 I2'dedir: 010.

**Soru 5** (ekrandan, 00:40:00): ADC0804 200H adresine yerleştirilmiş, $\overline{INTR}$ ucu için 400H adresinde bir G/Ç cihazı tanımlanmıştır ($\overline{INTR}$ AD7'de). Analog girişin sayısal karşılığını sürekli okuyan programı yazınız.

Çözüm (derste verildi): Bölüm 6'daki kod. 200H'ye boş yazma ile dönüşüm başlatılır, 400H okunup `TEST AL,80H` sıfır verene dek beklenir, sonra 200H'den sonuç okunur.

**Soru 6** (derste sözlü, 00:46:21 ve 00:49:19): Proteus'taki testere dişinin genliği ve frekansı nasıl değiştirilir?

Çözüm (derste verildi): Genlik için değer aralığı kısıtlanır (`CMP AL,7FH / JBE DEVAM / XOR AL,AL`): tepe yaklaşık yarıya iner. Frekans için DELAY'deki döngü sayısı değiştirilir: CX 00FFH'den 01FFH'ye çıkınca periyot yaklaşık 400 ms'den 800 ms'ye çıkar.

## Dersin Toparlaması

Dersin ilk yarısında analog-sayısal dönüşüm tamamlandı. DAC0830 ile testere dişi dalga üretimi tekrar edildi, ardından iki ADC yapısı incelendi: bütün bitleri tek seferde bulan, direnç merdiveni, karşılaştırıcılar ve öncelikli kodlayıcıdan oluşan hızlı paralel ADC ile sayıcı, DAC ve karşılaştırıcıyla çalışan, girişe ulaşana kadar sayması gereken rampa dönüştürücü. Adres ucu olmayan ADC0804'ün `OUT` ile başlatılıp $\overline{INTR}$ ucunun ayrı bir 1 bitlik G/Ç cihazı üzerinden yoklanarak `IN` ile okunması örnek kod ve Proteus devresiyle gösterildi. Proteus'ta DAC çıkışının genliği ve periyodu koddan değiştirildi, ADC örneğinin 200H ve 400H adresleri 74154 tabanlı adres çözümleme devresi üzerinden doğrulandı.

İkinci yarıda yoklamanın işlemciyi bloklaması üzerinden kesme ve DMA kavramlarına geçildi. 8086'nın yazılımsal (INT, INTO, INT 3) ve donanımsal (NMI, INTR) kesme kaynakları, $\overline{INTA}$ el sıkışması, IF ve TF bayrakları, kesmenin near ve far çağrıdan farkı, IRET, 1024 baytlık kesme vektör tablosu ve kesme sırasında işlemcinin kendiliğinden yaptığı adımlar anlatıldı. Bir sonraki derste kesme örneklerine ve slaytta sıradaki konular olan özel kesme alt programı yazma ile 8259A kesme denetleyicisine geçileceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
