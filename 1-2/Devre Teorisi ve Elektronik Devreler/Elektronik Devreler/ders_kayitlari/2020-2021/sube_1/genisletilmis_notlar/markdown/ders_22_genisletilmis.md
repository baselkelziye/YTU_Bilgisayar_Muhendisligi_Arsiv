# Ders 22 Genişletilmiş Notu: FET Özeti, FET Öngerilim Devreleri ve Soru Çözümleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. FET Çeşitlerinin Hatırlatılması
- 2. Transfer Eğrileri ve Formüller
- 3. FET DC Öngerilim Devreleri
- 4. Çalışma Noktasının Grafikle Bulunması
- 5. Soru Çözümleri: Transfer Eğrisi Çizimi
- 6. Soru Çözümleri: Öngerilim Devreleri
- Örnek Sorular
- Dersin Toparlaması

## 1. FET Çeşitlerinin Hatırlatılması

Ders, önceki haftanın konusunun hatırlatılmasıyla başlar. Transistörlerde ilk geliştirilen tip olan BJT'den (bipolar jonksiyon transistör) sonra alan etkili transistörlere (FET, Field Effect Transistor) geçilmişti. Ekranda önceki slayt dosyasının son sayfasındaki özet tablo açıktır (ekrandan, 00:10:00). Tablo n-kanal tipler için hazırlanmıştır; p-kanal tiplerde her şey bunun tersidir.

FET'ler kanal tipine göre n-kanallı ve p-kanallı olarak ikiye ayrılır. Üç ana çeşit vardır:

- JFET (jonksiyon FET).
- Kanal ayarlamalı MOSFET (depletion type, D-MOSFET).
- Kanal oluşturmalı MOSFET (enhancement type, E-MOSFET).

Üçünün de gate (G), drain (D) ve source (S) olmak üzere üç bacağı vardır. Son ikisi MOSFET olsa da $I_D$–$V_{GS}$ formüllerine bakıldığında JFET ile kanal ayarlamalı MOSFET birbirine daha çok benzer. Kanal oluşturmalı MOSFET'in yapısı farklıdır: önce bir kanal oluşturulur, akım ancak bu kanal oluştuktan sonra akar.

### 1.1 Akım kontrolü ve gerilim kontrolü

Hoca ekranda iki satırlık bir karşılaştırma yazar (ekrandan, 00:10:00): BJT akım kontrollüdür (belirleyici $I_B$), FET gerilim kontrollüdür (belirleyici $V_{GS}$). BJT'de devrenin açılıp kapanmasını ve karakteristiğini baz akımı belirliyordu. FET'te ise belirleyici parametre gate ile source arasındaki gerilim $V_{GS}$'dir. Bu yüzden FET'lerde $I_D$–$V_{GS}$ grafiği, yani drain'den source'a akan akımla gate–source gerilimi arasındaki ilişki çok önemlidir.

### 1.2 Sembol ve kanal tipi

JFET'te kanalın etrafını bir kuşak gibi saran, kanaldan farklı tipte bir malzeme vardır; n-kanal JFET'te kanal n tipi, onu saran malzeme p tipidir. MOSFET'te drain ve source arasında kanal bölgesi bulunur, gate ise bu bölgeye bir yalıtkan tabaka üzerinden bağlıdır. Hazırda bir kanal varsa ve gate gerilimi bu kanalın genişliğini ayarlıyorsa yapı kanal ayarlamalıdır (D-type). Kanal yoksa, gate–source arasına belli bir gerilim uygulanınca oluşuyorsa ve sonra genişliği ayarlanıyorsa yapı kanal oluşturmalıdır (E-type).

Sembolde ok içeri bakıyorsa kanal n tipidir. Bu kural hem JFET'te hem MOSFET'lerde geçerlidir (ekrandan, 00:15:00).

### 1.3 Ortak eşitlikler

Bütün FET tiplerinde gate'ten akım geçmez ve drain ile source akımları birbirine tam eşittir:

$$I_G = 0\ \text{A}, \qquad I_D = I_S$$

BJT'de $I_C \approx I_E$ yaklaşık bir eşitlikti; FET'te $I_D = I_S$ tam eşitliktir. Hoca BJT'de de $I_B$'nin sıfıra çok yakın, mikroamper seviyesinde olduğunu hatırlatır.

## 2. Transfer Eğrileri ve Formüller

### 2.1 JFET

n-kanal JFET'te $V_{GS}$'ye negatif gerilim uygulanır. Belli bir negatif değerde, pinch-off gerilimi $V_P$'de, PN ekleminin etrafındaki fakirleşmiş bölge (depletion region) kanalı tamamen kapatır ve akım sıfır olur. $V_{GS}$ sıfıra getirildiğinde, yani hiç gerilim uygulanmadığında, akım en büyük değerine ulaşır; buna $I_{DSS}$ denir. Demek ki n-kanal JFET'te $V_{GS}$, $V_P$ ile 0 arasında değişir.

Formül Shockley denklemidir (ekrandan, 00:10:00):

$$I_D = I_{DSS}\left(1 - \frac{V_{GS}}{V_P}\right)^2$$

Burada $V_{GS}$ girdidir; $I_{DSS}$ ve $V_P$ transistöre özgü sabitlerdir (slaytta mavi kutuda verilirler). Matematiksel olarak bu bir eğrisel (karesel) ifadedir.

Eğriyi yaklaşık çizmek için iki yardımcı nokta kullanılır (ekrandan, 00:15:00 ve 00:20:00):

- A noktası: $I_D = I_{DSS}/2$ yaklaşık olarak $V_{GS} = 0{,}3V_P$'ye denk gelir.
- B noktası: $V_{GS} = V_P/2$ iken $I_D = I_{DSS}/4$ olur.

$V_P$ ve $I_{DSS}$ noktaları da bilindiğine göre dört noktadan geçen bir eğri çizilerek yaklaşık transfer karakteristiği elde edilir.

> **Ek bilgi (derste anlatılmadı):** $V_{GS} = V_P/2$ denklemde yerine konursa $I_D = I_{DSS}(1 - 1/2)^2 = I_{DSS}/4$ tam olarak çıkar. $I_D = I_{DSS}/2$ için ise $1 - V_{GS}/V_P = 1/\sqrt{2}$, yani $V_{GS} \approx 0{,}293V_P$ çıkar; $0{,}3V_P$ bunun yuvarlatılmış hâlidir.

### 2.2 Kanal ayarlamalı MOSFET (D-MOSFET)

D-MOSFET aynı formüle uyar ve JFET'e benzer. Hazırda bir kanal vardır. $V_{GS}$ negatifte belli bir değerde ($V_P$) kanal tamamen yok olur ve akım akmaz. $V_{GS}$ negatiften sıfıra yaklaştıkça kanal genişler. Farkı şudur: JFET'te kanal en geniş hâline $V_{GS} = 0$'da ulaşıp orada durur; D-MOSFET'te ise pozitif gerilimlere de geçilebilir. Pozitif $V_{GS}$ kanalın daha da genişlemesi, kanaldan daha çok elektron geçmesi demektir. Bu yüzden akım $I_{DSS}$'de durmaz, pozitif $V_{GS}$ verdikçe artmaya devam eder (ekrandan, 00:20:00). Eğri üzerinde $I'_D$ ile gösterilen ve $I_{DSS}$'nin üstünde kalan nokta bu pozitif bölgeyi gösterir.

Yardımcı noktalar ($0{,}3V_P$ ve $V_P/2$) D-MOSFET için de aynıdır.

### 2.3 Kanal oluşturmalı MOSFET (E-MOSFET)

E-MOSFET'te başlangıçta kanal yoktur. n-kanal tipte gate'e belli bir pozitif gerilim uygulandıktan sonra kanal oluşur. Kanalın oluştuğu gerilime eşik gerilimi (threshold), $V_{GS(Th)}$ ya da $V_T$ denir. Bu gerilimin altında akım sıfırdır. Formül farklıdır:

$$I_D = k\,(V_{GS} - V_{GS(Th)})^2$$

$k$ transistöre özgü bir katsayıdır, birimi A/V²'dir; $V_{GS(Th)}$ da transistöre özgüdür. Eşik geriliminden sonra akım bu karesel ifadeye göre yukarı doğru artar. Hoca slayttaki formülde $V_{GS}$'nin eksik yazıldığını söyler. <!-- BELİRSİZ: 00:18:33'te hoca slayttaki E-MOSFET formülünde bir terimin eksik kaldığını söylüyor; o anın karesi yok. -->

Bu devrelerin çözümünde $k$'nın bulunması önemli bir adımdır. $k$, verilen bir çalışma noktasından ($V_{GS(on)}$, $I_{D(on)}$) hesaplanır (ekrandan, 01:05:00):

$$k = \frac{I_{D(on)}}{(V_{GS(on)} - V_{GS(Th)})^2}$$

### 2.4 p-kanal tipler

p-kanal tiplerde eğriler tam tersidir. Ders slaytına göre p-kanal grafikleri, n-kanal grafiklerinin $I_D$ eksenine göre, yani $V_{GS} = 0$ noktasından geçen dikey eksene göre aynalanmış şeklidir:

- p-kanal JFET: eğri pozitif bir $V_P$'den başlar, $V_{GS} = 0$'da $I_{DSS}$'ye varır.
- p-kanal D-MOSFET: pozitif bir $V_P$'den başlar, negatif $V_{GS}$'ye doğru artar.
- p-kanal E-MOSFET: negatif bir eşikten başlar.

### 2.5 Formüllerde değişkenler

Hoca formüllerde sabitleri yuvarlak içine alarak gösterir: JFET ve D-MOSFET formülünde $I_{DSS}$ ve $V_P$, E-MOSFET formülünde $k$ ve $V_T$ sabittir. Geriye yalnız $I_D$ ve $V_{GS}$ kalır. Devre analizinde bu iki değişken arasında ikinci bir ilişki (devre denklemi) kurulur ve ikisi birlikte çözülür.

## 3. FET DC Öngerilim Devreleri

BJT'lerde olduğu gibi FET'leri de DC olarak çalışma bölgesine getirmek için çeşitli devre yapıları vardır. Amaç, transistörün çalışma bölgesinde stabil kalması ve üzerindeki AC işaretleri rahatça işleyebilmesidir. Yapılar şunlardır:

- JFET: sabit öngerilim (fixed-bias), kendinden öngerilim (self-bias), gerilim bölücü (voltage-divider).
- D-MOSFET: kendinden öngerilim ve gerilim bölücü.
- E-MOSFET: geri beslemeli (feedback) ve gerilim bölücü.

Bu yapılar bir sonraki soru çözümlerinin temelidir.

### 3.1 Sabit öngerilim (fixed-bias)

Slayttaki devrede (ekrandan, 00:25:00) $V_{DD}$, $R_D$ üzerinden drain'e bağlıdır, source doğrudan topraktadır, gate'e ters bağlı bir $V_{GG}$ kaynağı uygulanır. Source'u sabitlemek için bir direnç konmamıştır.

Hoca önce bir öğrenciye sorar: ok içeri bakan bir JFET hangi tiptir? **Cevap:** n tipi. Sonra: n-kanal JFET'te çalışma bölgesinde $V_{GS}$ pozitif mi negatif mi? **Cevap:** negatif. Hoca bunun hemen transfer eğrisini akla getirmesi gerektiğini söyler; gerçekten de bu devrede gate ile source arasına negatif gerilim uygulanmıştır.

Drain kolunda Kirchhoff gerilim yasası:

$$V_{DD} = I_D R_D + V_{DS}$$

Slayttaki eşitlikler (ekrandan, 00:25:00):

$$V_{DS} = V_{DD} - I_D R_D, \qquad V_S = 0\ \text{V}, \qquad V_{GS} = -V_{GG}$$

Slaytta "$V_C = V_{DS}$" yazar; hoca bunun $V_D$ olması gerektiğini söyler. $V_{DS} = V_D - V_S$ ve $V_S = 0$ olduğundan $V_D = V_{DS}$'dir. Slayttaki "$V = V_{GS}$" ifadesinde de kastedilen, gate'e uygulanan DC gerilimdir; $V_{GS} = -V_{GG}$.

### 3.2 Kendinden öngerilim (self-bias)

Bu yapıda hem drain'e hem source'a birer direnç bağlıdır. Gate–source çevresinde:

$$V_G = V_{GS} + I_S R_S$$

$I_S = I_D$ olduğundan bu çevrenin denklemi $V_{GS}$ ile $I_D$ arasında bir ilişki verir. Gate direncinden akım geçmediği için gate gerilimi sıfırdır ve:

$$V_{GS} = -I_S R_S = -I_D R_S$$

Drain–source kolunda ise:

$$V_{DD} = I_D R_D + V_{DS} + I_S R_S$$

### 3.3 Gerilim bölücü (voltage-divider)

Hoca önce en basit gerilim bölücüyü hatırlatır (ekrandan, 00:30:00). Seri iki direnç ve üstten bir $V$ uygulanmışsa orta noktadaki (B) gerilim:

$$V_B = \frac{R_2}{R_1 + R_2}\,V$$

Hocanın örneği: üst direnç 3 birim, alt direnç 2 birim (örneğin 3 kΩ ve 2 kΩ), kaynak 10 V.

- Toplam: $R_1 + R_2 = 5$ birim.
- Orta nokta: $\frac{2}{5} \cdot 10 = 4$ V.
- 3 birimlik dirençte 6 V, 2 birimlik dirençte 4 V düşer.

İkisinden de aynı akım geçtiği için ($I R_1 + I R_2 = 10$ V) direnci büyük olanda daha çok gerilim toplanır. Dirençler eşit olsaydı orta nokta 5 V olurdu.

FET'li gerilim bölücüde (ekrandan, 00:30:00 ve 00:35:00) gate'e akım girmediği için ($I_G = 0$) $V_G$ doğrudan bu oranla bulunur:

$$V_G = \frac{R_2 V_{DD}}{R_1 + R_2}$$

Gate–source çevresinden:

$$V_G = V_{GS} + I_S R_S \;\Rightarrow\; V_{GS} = V_G - I_D R_S$$

Drain kolundan:

$$V_{DD} = I_D R_D + V_{DS} + I_S R_S$$

Hoca $V_{GS}$'yi iki noktanın gerilim farkı olarak da açıklar. Bir kara kutunun (direnç ya da kondansatör olabilir) A ve B uçları arasındaki gerilim $V_{AB} = V_A - V_B$'dir. Aynı şekilde $V_{GS} = V_G - V_S$ ve $V_S = I_S R_S$'dir (ekrandan, 00:35:00).

### 3.4 D-MOSFET'te gerilim bölücü

Slaytta n-kanal kanal ayarlamalı bir MOSFET'in gerilim bölücü devresi vardır. Mavi kutudaki değerler transistöre özgü karakteristiklerdir. Hoca devreden $V_G = \frac{R_2}{R_1 + R_2} \cdot 18$ V yazar ve source direncini 750 Ω, $V_P = -3$ V, $I_{DSS} = 6$ mA olarak okur. Bu iki değerle iki nokta bulunur:

- $V_P/2 = -1{,}5$ V'ta $I_D = I_{DSS}/4 = 1{,}5$ mA.
- $I_{DSS}/2 = 3$ mA, $V_{GS} = 0{,}3V_P = -0{,}9$ V'a denk gelir.

D-MOSFET'te eğri pozitif bölgeye de geçtiği için dış kısmı çizmek üzere bir de pozitif $V_{GS}$ değerinin bilinmesi gerekir. Denklem yine $V_{GS} = V_G - I_D R_S$ biçimindedir.

O anda ekrandaki slayt grafiğinde (ekrandan, 00:40:00) transfer eğrisi $V_P = -3$ V'tan başlar; doğru, $V_{GS} = 0$'da yaklaşık 10 mA'dan ve $I_D = 0$'da yaklaşık $+1{,}5$ V'tan geçer; Q noktası $I_{DQ} = 7{,}6$ mA, $V_{GS} = +0{,}35$ V'tur. <!-- BELİRSİZ: Slayt grafiğindeki doğrunun 10 mA kesimi, hocanın okuduğu 750 Ω ile uyuşmuyor (1,5 V / 750 Ω = 2 mA olurdu). Hocanın okuduğu değerler büyük olasılıkla ders sonunda çözülen 6.29 numaralı soruya ait; slayt grafiğinin devre değerleri karede görünmüyor. -->

### 3.5 E-MOSFET'te geri beslemeli öngerilim

Slayttaki devrede (ekrandan, 00:45:00) drain ile gate arasına $R_G$ direnci bağlıdır, source topraktadır. Sembolde ok içeri baktığı için oluşacak kanal n tipidir.

- $I_G = 0$ olduğundan $R_G$'den akım geçmez ve $V_{R_G} = 0$ V'tur.
- Bu yüzden drain tarafındaki A noktasının gerilimi aynen gate'te görülür: $V_G = V_A = V_D$.
- $V_S = 0$ olduğundan $V_{DS} = V_D$ ve $V_{GS} = V_G$.

Sonuç:

$$V_{GS} = V_{DS} = V_{DD} - I_D R_D$$

Buradaki $V_{DS}$ ifadesi drain kolundan gelir: $V_{DD} = I_D R_D + V_{DS}$. Gerçekten de drain'den gate'e bir geri besleme yapılmaktadır; gate'ten akım geçmediği için drain'in gerilimi doğrudan gate'te oluşur. $V_{DD}$ ve $R_D$ sabit olduğundan bu da $y = a - bx$ biçiminde doğrusal bir denklemdir.

### 3.6 E-MOSFET'te gerilim bölücü

Yapı JFET'teki gibidir: $V_G = \frac{R_2 V_{DD}}{R_1 + R_2}$, gate–source çevresinden $V_{GS} = V_G - I_D R_S$, drain kolundan $V_{DS} = V_{DD} - I_D(R_D + R_S)$.

## 4. Çalışma Noktasının Grafikle Bulunması

Gerilim bölücü devrede $V_G$ bulunduktan sonra $V_{GS} = V_G - I_D R_S$ denklemi $V_{GS}$ ile $I_D$ arasında doğrusal bir ilişkidir. Hoca bunu $y = c - ax$ biçimine benzetir: $V_G$ ve $R_S$ sabit, $V_{GS}$ ve $I_D$ değişkendir (ekrandan, 00:35:00). Q noktası (çalışma noktası) şöyle bulunur (ekrandan, 00:40:00):

- Transistörün transfer eğrisi $I_{DSS}$, $V_P$ ve hesaplanan ara noktalarla çizilir.
- Doğru denkleminde $V_{GS} = 0$ verilir, $I_D$ eksenini kestiği nokta bulunur ($I_D = V_G/R_S$).
- $I_D = 0$ verilir, $V_{GS}$ eksenini kestiği nokta bulunur ($V_{GS} = V_G$).
- Bu iki noktadan geçen doğru çizilir. Doğrunun transfer eğrisini kestiği yer Q noktasıdır.
- Q noktasından $V_{GSQ}$ ve $I_{DQ}$ okunur, yani çalışmadaki gate–source gerilimi ve drain akımı.

Slayt aynı adımların JFET kendinden öngerilim devrelerinde de kullanıldığını belirtir. Q bulunduktan sonra diğer büyüklükler hesaplanır. Örneğin slayttaki biçimde $V_{DS}$ bir tarafa çekilir: $V_D = V_{DD} - I_D R_D$, $V_S = I_D R_S$. Hoca uçları tek tek gösterir: drain, elemanın akımın girdiği ucudur; drain ucu $V_D$, source ucu $V_S$, gate ucu $V_G$'dir.

> **Hocanın vurgusu:** MOSFET sorularında önce transistörün karakteristiğini, yani $I_D$–$V_{GS}$ eğrisini doğru çizmek gerekir. Ancak ondan sonra devreden bulunan doğru denklemiyle çakıştırılarak transistörün nerede çalıştığı bulunabilir.

## 5. Soru Çözümleri: Transfer Eğrisi Çizimi

Hoca soru çözümlerine geçer. Ekrandaki dosya ElkDev_Sorular2.pdf'tir; sorular ve çözümler Boylestad & Nashelsky kitabındaki örneklerdir.

### 5.1 JFET transfer eğrisi

Soru: $I_{DSS} = 12$ mA, $V_P = -6$ V olan bir JFET'in transfer eğrisini çizin (ekrandan, 00:50:00).

- Uç noktalar: $V_{GS} = 0$'da $I_D = I_{DSS} = 12$ mA; $V_{GS} = V_P = -6$ V'ta $I_D = 0$.
- $I_D = I_{DSS}/2 = 6$ mA'da $V_{GS} \cong 0{,}3V_P = 0{,}3(-6) = -1{,}8$ V.
- $V_{GS} = V_P/2 = -3$ V'ta $I_D = I_{DSS}/4 = 12/4 = 3$ mA.

Dört nokta elde edildiğinde eğri yaklaşık olarak çizilir.

### 5.2 BJT ile JFET'in karşılaştırılması

Hoca burada iki elemanı karşılaştırır. İkisi de üç bacaklıdır. BJT'de kollektör, baz ve emitter uçları vardır; baz–emitter gerilimi silisyumda 0,7 V sabit alınır, $I_B$ çok düşüktür, $I_C \approx \beta I_B$ ve $I_C \approx I_E$'dir. JFET'te drain, gate ve source uçları vardır; sabit kabul edilen şey $I_G \approx 0$'dır ve ana koldaki akımlar $I_D = I_S$ eşittir (BJT'deki $I_C \approx I_E$ gibi). Ana değişkenler $V_{GS}$ ile $I_D$ arasında karesel bir ilişki vardır. Bunlar soru çözümlerinde mutlaka akılda tutulmalıdır.

### 5.3 D-MOSFET transfer eğrisi

Soru: $I_{DSS} = 10$ mA, $V_P = -4$ V olan n-kanal kanal ayarlamalı MOSFET'in transfer eğrisini çizin (ekrandan, 00:55:00).

- $V_{GS} = 0$'da $I_D = 10$ mA; $V_{GS} = -4$ V'ta $I_D = 0$.
- $V_{GS} = V_P/2 = -2$ V'ta $I_D = 10/4 = 2{,}5$ mA (A noktası).
- $I_D = 5$ mA'da $V_{GS} = 0{,}3(-4) = -1{,}2$ V (B noktası).
- Pozitif bölge için $+1$ V seçilir:

$$I_D = 10\text{ mA}\left(1 - \frac{+1}{-4}\right)^2 = 10\text{ mA}(1{,}25)^2 = 10\text{ mA}(1{,}5625) \cong 15{,}63\text{ mA}$$

Hoca $V_P/2$ noktasının neden $I_{DSS}/4$ verdiğini de gösterir: $V_{GS} = -2$ V konunca parantez $1 - \frac{1}{2} = \frac{1}{2}$ olur, karesi $\frac{1}{4}$'tür, yani akım $I_{DSS}$'nin dörtte biridir.

Slayt, $I_D$'nin pozitif $V_{GS}$ ile çok hızlı arttığını, bu yüzden denklemde yerine konacak değerin temkinli seçilmesi gerektiğini söyler; +1 V eğriyi tamamlamak için yeterlidir.

Hoca burada ara verir; aradan sonra E-MOSFET eğrisinin çizimiyle devam eder.

### 5.4 E-MOSFET transfer eğrisi

Soru: Veri sayfasındaki değerler ve ortalama eşik gerilimi $V_{GS(Th)} = 3$ V ile (a) $k$ değerini, (b) transfer karakteristiğini bulun (ekrandan, 01:05:00). Çalışma noktası $I_{D(on)} = 3$ mA, $V_{GS(on)} = 10$ V olarak verilmiştir. Hoca bu noktanın soruda gösterilmediğini, ama $k$'yı bulmak için mutlaka verilmesi gerektiğini söyler.

(a)

$$k = \frac{I_{D(on)}}{(V_{GS(on)} - V_{GS(Th)})^2} = \frac{3\text{ mA}}{(10 - 3)^2\ \text{V}^2} = \frac{3 \times 10^{-3}}{49} = 0{,}061 \times 10^{-3}\ \text{A/V}^2$$

(b) $I_D = 0{,}061 \times 10^{-3}(V_{GS} - 3)^2$. Örneğin $V_{GS} = 5$ V için:

$$I_D = 0{,}061 \times 10^{-3}(2)^2 = 0{,}244\text{ mA}$$

$V_{GS} = 8, 10, 12, 14$ V için $I_D$ sırasıyla 1,525 mA, 3 mA (verilen nokta), 4,94 mA ve 7,38 mA olur. Bu ara noktalarla eğri çizilecek kalitede nokta elde edilir.

> **Ders sonrası not:** Ekrandaki değerler yuvarlatılmış $k = 0{,}061 \times 10^{-3}$ ile hesaplanmıştır. $k = 3/49 \times 10^{-3}$ tam değeriyle python kontrolünde 12 V için 4,96 mA, 14 V için 7,41 mA çıkar; fark yuvarlamadandır.

## 6. Soru Çözümleri: Öngerilim Devreleri

### 6.1 JFET sabit öngerilim

Devre (ekrandan, 01:10:00): $V_{DD} = 16$ V, $R_D = 2$ kΩ, gate 1 MΩ üzerinden ters bağlı 2 V'luk kaynağa bağlı, source toprakta. $I_{DSS} = 10$ mA, $V_P = -8$ V. İstenen: $V_{GSQ}$, $I_{DQ}$, $V_{DS}$, $V_D$, $V_G$, $V_S$.

Transistör n-kanal JFET olduğu için eğri $V_P = -8$ V'tan başlar, $V_{GS} = 0$'da 10 mA'ya ulaşır.

(a) $I_G = 0$ olduğundan 1 MΩ'luk dirençte düşen gerilim 0 V'tur. Gate tarafındaki A noktası, kaynak ters bağlı olduğu için $-2$ V'tadır ve bu doğrudan $V_{GS}$'dir. Böylece hiçbir çizim yapmadan:

$$V_{GSQ} = -V_{GG} = -2\text{ V}$$

(b) $V_{GS}$ bilindiği için akım doğrudan formülden bulunur:

$$I_{DQ} = 10\text{ mA}\left(1 - \frac{-2}{-8}\right)^2 = 10\text{ mA}(0{,}75)^2 = 10\text{ mA}(0{,}5625) = 5{,}625\text{ mA}$$

> **Ders sonrası not:** Hoca sonucu söylerken "5,625 volt" dedi; bu bir akımdır, doğrusu 5,625 mA'dır (ekrandan, 01:10:00). Hoca soruyu okurken pinch-off gerilimini "8 V" dedi; slaytta $V_P = -8$ V yazar.

(c) Drain kolunda $16 = I_D \cdot 2\text{ k}\Omega + V_{DS}$. Birimler tam yazılmalıdır (mA için $10^{-3}$, kΩ için $10^{3}$; ikisi birbirini götürür):

$$V_{DS} = 16 - (5{,}625\text{ mA})(2\text{ k}\Omega) = 16 - 11{,}25 = 4{,}75\text{ V}$$

(d) $V_D = V_{DS} + V_S$, $V_S = 0$ olduğundan $V_D = V_{DS} = 4{,}75$ V. Tersten de gidilebilir: $V_D = 16 - 2\text{ k}\Omega \cdot I_D$, aynı sonuç.

(e) $V_G = V_{GS} = -2$ V.

(f) $V_S = 0$ V (source doğrudan toprakta).

### 6.2 JFET gerilim bölücü

Devre (ekrandan, 01:15:00): $V_{DD} = 16$ V, $R_1 = 2{,}1$ MΩ, $R_2 = 270$ kΩ, $R_D = 2{,}4$ kΩ, $R_S = 1{,}5$ kΩ (kuplaj ve source kondansatörleri DC'de açık devredir). $I_{DSS} = 8$ mA, $V_P = -4$ V. İstenen: $I_{DQ}$ ve $V_{GSQ}$, $V_D$, $V_S$, $V_{DS}$, $V_{DG}$.

**Transfer eğrisi.** $I_{DSS}/2 = 4$ mA'ya $0{,}3V_P = -1{,}2$ V denk gelir; $V_P/2 = -2$ V'ta $I_D = 8/4 = 2$ mA'dır.

**Gate gerilimi.**

$$V_G = \frac{R_2 V_{DD}}{R_1 + R_2} = \frac{(270\text{ k}\Omega)(16\text{ V})}{2{,}1\text{ M}\Omega + 0{,}27\text{ M}\Omega} = 1{,}82\text{ V}$$

**Doğru denklemi.** $V_G = V_{GS} + I_S \cdot 1{,}5$ kΩ ve $I_S = I_D$ olduğundan:

$$V_{GS} = 1{,}82\text{ V} - I_D(1{,}5\text{ k}\Omega)$$

- $I_D = 0$ verilince $V_{GS} = 1{,}82$ V.
- $V_{GS} = 0$ verilince $I_D = 1{,}82/1{,}5 = 1{,}21$ mA.

İki noktadan geçen doğru eğriyi kestiği yerde Q noktası okunur. Hoca 2,4 ya da 2,5 mA denebileceğini, çözümde 2,4 mA alındığını; gerilimin $-1{,}8$ ile $-1{,}9$ V arasında olduğunu, çözümde $-1{,}8$ V alındığını söyler:

$$I_{DQ} \approx 2{,}4\text{ mA}, \qquad V_{GSQ} \approx -1{,}8\text{ V}$$

**Noktasal ve farksal gerilimler.**

- $V_D = V_{DD} - I_D R_D = 16 - (2{,}4\text{ mA})(2{,}4\text{ k}\Omega) = 16 - 5{,}76 = 10{,}24$ V.
- $V_S = I_S R_S = (2{,}4\text{ mA})(1{,}5\text{ k}\Omega) = 3{,}6$ V.
- $V_{DS} = V_D - V_S = 10{,}24 - 3{,}6 = 6{,}64$ V. İkinci yol: $V_{DS} = V_{DD} - I_D(R_D + R_S) = 16 - 2{,}4 \cdot 3{,}9 = 6{,}64$ V. İkisi aynı çıkmalıdır.
- $V_{DG} = V_D - V_G$. Hoca yöntemi söyler; sayısal değer: $10{,}24 - 1{,}82 = 8{,}42$ V (ara adım eklendi).

> **Ders sonrası not:** Python ile denklem takımı sayısal çözüldüğünde $I_{DQ} \approx 2{,}42$ mA, $V_{GSQ} \approx -1{,}80$ V çıkar; grafikten okunan değerler bununla uyumludur.

### 6.3 D-MOSFET gerilim bölücü

Devre (ekrandan, 01:20:00): $V_{DD} = 18$ V, $R_1 = 110$ MΩ, $R_2 = 10$ MΩ, $R_D = 1{,}8$ kΩ, $R_S = 750\ \Omega$. $I_{DSS} = 6$ mA, $V_P = -3$ V. İstenen: (a) $I_{DQ}$ ve $V_{GSQ}$, (b) $V_{DS}$.

**Transfer eğrisi.** n-kanal D-MOSFET eğrisi $V_P$'den başlar ve pozitif bölgeye taşar.

- $V_{GS} = 0$'da 6 mA, $V_{GS} = -3$ V'ta 0.
- $V_P/2 = -1{,}5$ V'ta $I_D = 6/4 = 1{,}5$ mA.
- $I_{DSS}/2 = 3$ mA'da $V_{GS} = 0{,}3(-3) = -0{,}9$ V.
- Dış nokta, $V_{GS} = +1$ V: $I_D = 6\left(1 - \frac{1}{-3}\right)^2 = 6 \cdot \frac{16}{9} \approx 10{,}67$ mA.

> **Hocanın vurgusu:** Eksi ve artılara mutlaka dikkat edin. Kendi çizimlerinizde eksenlere eşit aralıklar verin; öbür türlü doğru denklemiyle kesişimden $V_{GSQ}$ okunurken çok kayma olur.

**Gate gerilimi.** Dirençler 110 ve 10 birimdir, toplam 120 birim (hoca bir an "11 birim" der, sonra 18 V'un $1/12$'sini alır):

$$V_G = \frac{10}{110 + 10} \cdot 18 = \frac{18}{12} = 1{,}5\text{ V}$$

**Doğru denklemi.** $V_{GS} = V_G - I_S R_S$ ve $I_S = I_D$:

$$V_{GS} = 1{,}5 - I_D(0{,}75\text{ k}\Omega)$$

- $I_D = 0$'da $V_{GS} = 1{,}5$ V.
- $V_{GS} = 0$'da $I_D = 1{,}5/0{,}75 = 2$ mA (ara adım eklendi).

Kesişimden yaklaşık 3 mA denebilir; çözümde (ekrandan, 01:25:00):

$$I_{DQ} = 3{,}1\text{ mA}, \qquad V_{GSQ} = -0{,}8\text{ V}$$

(b) Drain kolundan $18 = I_D(1{,}8\text{ k}\Omega) + V_{DS} + I_D R_S$:

$$V_{DS} = V_{DD} - I_D(R_D + R_S) = 18 - (3{,}1\text{ mA})(1{,}8\text{ k}\Omega + 0{,}75\text{ k}\Omega) \cong 10{,}1\text{ V}$$

> **Ders sonrası not:** Hoca sonucu "$V_D$'yi bulursunuz ... 10,1 V" diye söyledi; 10,1 V, $V_{DS}$'dir (ekrandan, 01:25:00). $V_D = 18 - 3{,}1 \cdot 1{,}8 \approx 12{,}42$ V olur. Python ile sayısal çözümde $I_{DQ} \approx 3{,}12$ mA, $V_{GSQ} \approx -0{,}84$ V çıkar.

### 6.4 D-MOSFET kendinden öngerilim

Devre (ekrandan, 01:25:00 ve 01:30:00): $V_{DD} = 20$ V, $R_D = 6{,}2$ kΩ, gate 1 MΩ ile toprağa, $R_S = 2{,}4$ kΩ. $I_{DSS} = 8$ mA, $V_P = -8$ V. İstenen: (a) $I_{DQ}$ ve $V_{GSQ}$, (b) $V_D$.

**Doğru denklemi.** Gate–source çevresinden $V_G = V_{GS} + I_S R_S$. Gate ucu girişin geldiği yerdir; $I_G = 0$ olduğu için 1 MΩ'dan da akım geçmez ve bu dirençte gerilim düşmez. Dolayısıyla $V_G = 0$:

$$V_{GS} = -I_S R_S = -I_D(2{,}4\text{ k}\Omega)$$

**Transfer eğrisi.**

- $I_{DSS}/2 = 4$ mA'da $V_{GS} = 0{,}3(-8) = -2{,}4$ V.
- $V_P/2 = -4$ V'ta $I_D = 8/4 = 2$ mA.
- Dış nokta, $V_{GS} = +2$ V: $I_D = 8\left(1 - \frac{2}{-8}\right)^2 = 8(1{,}25)^2 = 12{,}5$ mA.

> **Ders sonrası not:** Hoca değerleri okurken "$I_{DSS}$ 8 volt" ve "0,3 ile çarpınca 2,4" dedi; doğrusu $I_{DSS} = 8$ mA ve $0{,}3V_P = -2{,}4$ V'tur.

**Doğrunun çizimi.** $V_{GS} = -a \cdot I_D$ biçimindeki doğru orijinden geçer ($y = -ax$, sabit $a$ burada $R_S = 2{,}4$ kΩ). İkinci nokta için dışarıdan bir değer seçilir: $V_{GS} = -6$ V için $I_D = 6/2{,}4 = 2{,}5$ mA. Orijin ile bu noktadan geçen doğru eğriyle kesiştirilir. Hoca 1,8 de denebileceğini, çözümde 1,7 alındığını; gerilimin $-4$'ü biraz aştığını, $-4{,}2$ denebileceğini, çözümde $-4{,}3$ alındığını söyler:

$$I_{DQ} \approx 1{,}7\text{ mA}, \qquad V_{GSQ} \approx -4{,}3\text{ V}$$

(b) Drain kolu $20 = I_D(6{,}2\text{ k}\Omega) + V_{DS} + I_D(2{,}4\text{ k}\Omega)$'dur. $V_D$ istendiği için yalnız $R_D$'de düşen gerilim çıkarılır:

$$V_D = V_{DD} - I_D R_D = 20 - (1{,}7\text{ mA})(6{,}2\text{ k}\Omega) = 20 - 10{,}54 = 9{,}46\text{ V}$$

Hoca yöntemi söyler; sayısal sonuç ders sonrası hesaplanmıştır (ara adım eklendi).

> **Ders sonrası not:** Python ile sayısal çözümde $I_{DQ} \approx 1{,}77$ mA, $V_{GSQ} \approx -4{,}24$ V çıkar; grafikten okunan 1,7 mA ve $-4{,}3$ V yaklaşık değerlerdir.

### 6.5 Gate'i toprakta olan D-MOSFET

Bu devrede kanal ayarlamalı MOSFET'in gate'i doğrudan toprağa bağlıdır, bu yüzden $V_{GS} = 0$'dır. D-MOSFET eğrisinde $V_{GS} = 0$ noktası $I_{DSS}$'dir; transistör başka bir gerilim alamayacağı için çalışma noktası buradadır:

$$I_{DQ} = I_{DSS} = 10\text{ mA}$$

$V_D$ için drain direncinde (1,5 kΩ) düşen gerilim besleme geriliminden çıkarılır: $10\text{ mA} \times 1{,}5\text{ k}\Omega = 15$ V düşer ve $V_D = 5$ V kalır. <!-- BELİRSİZ: Bu sorunun karesi yok. 5 V ve 15 V altyazıdan; besleme geriliminin bu yüzden büyük olasılıkla 20 V olduğu çıkarılıyor. -->

### 6.6 E-MOSFET geri beslemeli öngerilim

Devre (ekrandan, 01:35:00): $V_{DD} = 12$ V, $R_D = 2$ kΩ, drain ile gate arasında $R_G = 10$ MΩ, source toprakta. $I_{D(on)} = 6$ mA, $V_{GS(on)} = 8$ V, $V_{GS(Th)} = 3$ V. İstenen: $I_{DQ}$ ve $V_{DSQ}$.

**Devre ilişkisi.** $I_G = 0$ olduğundan 10 MΩ'dan da akım geçmez, uçları arasında gerilim düşmez; $V_D = V_G$. $V_S = 0$ olduğundan $V_{GS} = V_G = V_D$. Drain kolundan:

$$V_{GS} = V_{DD} - I_D R_D = 12 - I_D(2\text{ k}\Omega)$$

Hoca bunun, $V_{GS}$ ile $I_D$'nin değişken olduğu doğru denkleminin bu sefer "tam tersi yerden", drain tarafından elde edildiğini vurgular.

**$k$ ve eğri.**

$$k = \frac{6\text{ mA}}{(8 - 3)^2} = 0{,}24\ \text{mA/V}^2$$

- Eğri 3 V'tan başlar, (8 V, 6 mA) noktasından geçer.
- $V_{GS} = 6$ V: $I_D = 0{,}24 \cdot 3^2 = 2{,}16$ mA.
- $V_{GS} = 10$ V: $I_D = 0{,}24 \cdot 7^2 = 11{,}76$ mA.

**Doğru.** $I_D = 0$ verilince $V_{GS} = 12$ V; $V_{GS} = 0$ verilince $I_D = 12/2 = 6$ mA. Kesişimden:

$$I_{DQ} \approx 2{,}75\text{ mA}, \qquad V_{GSQ} \approx 6{,}4\text{ V}$$

$V_{DSQ} = V_{GSQ}$ olduğundan $V_{DSQ} \approx 6{,}4$ V.

> **Ders sonrası not:** Hoca doğrunun kesimlerini anlatırken bir an "$I_D$'ye 10 mA" dedi; anlatılan, $I_D = 0$ ve $V_{GS} = 0$ verilerek 12 V ve 6 mA kesimlerinin bulunmasıdır. Python ile sayısal çözümde $I_{DQ} \approx 2{,}79$ mA, $V_{GSQ} \approx 6{,}41$ V çıkar.

### 6.7 E-MOSFET gerilim bölücü

Son örnekte (ekrandan, 01:40:00) kanal oluşturmalı MOSFET gerilim bölücü yapıdadır. Gerilim bölücüden $V_G = 18$ V bulunmuştur ve $R_S = 0{,}82$ kΩ'dur. Transistör: $V_{GS(Th)} = 5$ V, $I_{D(on)} = 3$ mA ($V_{GS(on)} = 10$ V'ta). <!-- BELİRSİZ: Devrenin $V_{DD}$ ve diğer direnç değerleri o anın karesinde görünmüyor. -->

**Doğru denklemi.**

$$V_{GS} = V_G - I_D R_S = 18\text{ V} - I_D(0{,}82\text{ k}\Omega)$$

- $V_{GS} = 0$'da $I_D = V_G/R_S = 18/0{,}82 = 21{,}95$ mA.
- $I_D = 0$'da $V_{GS} = V_G = 18$ V.

**$k$ ve eğri.** Eşik gerilimiyle tek bir nokta yetmez, önce $k$ bulunur:

$$k = \frac{3\text{ mA}}{(10 - 5)^2} = 0{,}12 \times 10^{-3}\ \text{A/V}^2, \qquad I_D = 0{,}12 \times 10^{-3}(V_{GS} - 5)^2$$

Ara noktalar için 15 V ve 20 V seçilmiştir: $I_D(15) = 0{,}12 \cdot 100 = 12$ mA, $I_D(20) = 0{,}12 \cdot 225 = 27$ mA (ara adım eklendi). Eğri ile doğru kesiştirildiğinde:

$$I_{DQ} \approx 6{,}7\text{ mA}, \qquad V_{GSQ} \approx 12{,}5\text{ V}$$

Bundan sonra örneğin $V_{DS}$ sorulursa $V_{DS} = V_{DD} - I_D(R_S + R_D)$ ile, yani besleme geriliminden dirençlerde düşen gerilimler çıkarılarak bulunur. $V_D$, $V_{DG}$, $V_{DS}$ gibi noktasal ve farksal gerilimlerin iyi bulunması gerekir.

> **Ders sonrası not:** Python ile sayısal çözümde $I_{DQ} \approx 6{,}72$ mA, $V_{GSQ} \approx 12{,}49$ V çıkar.

## Örnek Sorular

### Soru 1 (ekrandan, 00:50:00)

$I_{DSS} = 12$ mA ve $V_P = -6$ V olan bir JFET'in transfer karakteristiğini çizin.

**Çözüm (derste verildi):** Uç noktalar (0 V, 12 mA) ve (−6 V, 0). $V_{GS} = V_P/2 = -3$ V'ta $I_D = 3$ mA; $I_D = 6$ mA'da $V_{GS} \cong 0{,}3V_P = -1{,}8$ V. Dört noktadan eğri çizilir.

### Soru 2 (ekrandan, 00:55:00)

$I_{DSS} = 10$ mA ve $V_P = -4$ V olan n-kanal kanal ayarlamalı MOSFET'in transfer karakteristiğini çizin.

**Çözüm (derste verildi):** $-2$ V'ta 2,5 mA, $-1{,}2$ V'ta 5 mA, $0$ V'ta 10 mA; pozitif bölge için $+1$ V'ta $I_D = 10(1{,}25)^2 \cong 15{,}63$ mA.

### Soru 3 (ekrandan, 01:05:00)

$I_{D(on)} = 3$ mA ($V_{GS(on)} = 10$ V) ve ortalama $V_{GS(Th)} = 3$ V verilen bir E-MOSFET için (a) $k$ değerini, (b) transfer karakteristiğini bulun.

**Çözüm (derste verildi):** $k = 3\text{ mA}/49\ \text{V}^2 = 0{,}061 \times 10^{-3}$ A/V². $V_{GS} = 5, 8, 10, 12, 14$ V için $I_D \approx 0{,}244$; 1,525; 3; 4,94; 7,38 mA.

### Soru 4 (ekrandan, 01:10:00)

16 V besleme, $R_D = 2$ kΩ, gate 1 MΩ üzerinden ters bağlı 2 V'a bağlı, source toprakta; $I_{DSS} = 10$ mA, $V_P = -8$ V olan JFET için $V_{GSQ}$, $I_{DQ}$, $V_{DS}$, $V_D$, $V_G$, $V_S$'yi bulun.

**Çözüm (derste verildi):** $V_{GSQ} = -2$ V, $I_{DQ} = 10(0{,}75)^2 = 5{,}625$ mA, $V_{DS} = 16 - 11{,}25 = 4{,}75$ V, $V_D = 4{,}75$ V, $V_G = -2$ V, $V_S = 0$ V.

### Soru 5 (ekrandan, 01:15:00)

$V_{DD} = 16$ V, $R_1 = 2{,}1$ MΩ, $R_2 = 270$ kΩ, $R_D = 2{,}4$ kΩ, $R_S = 1{,}5$ kΩ; $I_{DSS} = 8$ mA, $V_P = -4$ V olan JFET gerilim bölücü devresinde (a) $I_{DQ}$ ve $V_{GSQ}$, (b) $V_D$, (c) $V_S$, (d) $V_{DS}$, (e) $V_{DG}$'yi bulun.

**Çözüm (derste verildi, e şıkkının sayısı hesaplandı):** $V_G = 1{,}82$ V, $V_{GS} = 1{,}82 - 1{,}5I_D$; Q: $I_{DQ} \approx 2{,}4$ mA, $V_{GSQ} \approx -1{,}8$ V. $V_D = 10{,}24$ V, $V_S = 3{,}6$ V, $V_{DS} = 6{,}64$ V.

> **Çözüm (derste verilmedi):** $V_{DG} = V_D - V_G = 10{,}24 - 1{,}82 = 8{,}42$ V (python ile kontrol edildi).

### Soru 6 (ekrandan, 01:20:00)

$V_{DD} = 18$ V, $R_1 = 110$ MΩ, $R_2 = 10$ MΩ, $R_D = 1{,}8$ kΩ, $R_S = 750\ \Omega$; $I_{DSS} = 6$ mA, $V_P = -3$ V olan n-kanal D-MOSFET için (a) $I_{DQ}$ ve $V_{GSQ}$, (b) $V_{DS}$'yi bulun.

**Çözüm (derste verildi):** $V_G = 1{,}5$ V, $V_{GS} = 1{,}5 - 0{,}75I_D$. Eğri noktaları: $-1{,}5$ V'ta 1,5 mA, $-0{,}9$ V'ta 3 mA, $+1$ V'ta 10,67 mA. Q: $I_{DQ} = 3{,}1$ mA, $V_{GSQ} = -0{,}8$ V. $V_{DS} = 18 - 3{,}1(2{,}55) \cong 10{,}1$ V.

### Soru 7 (ekrandan, 01:25:00)

$V_{DD} = 20$ V, $R_D = 6{,}2$ kΩ, $R_G = 1$ MΩ, $R_S = 2{,}4$ kΩ; $I_{DSS} = 8$ mA, $V_P = -8$ V olan n-kanal D-MOSFET için (a) $I_{DQ}$ ve $V_{GSQ}$, (b) $V_D$'yi bulun.

**Çözüm (derste verildi, b şıkkının sayısı hesaplandı):** $V_{GS} = -2{,}4I_D$ (orijinden geçer; $-6$ V'ta 2,5 mA). Eğri: $-2{,}4$ V'ta 4 mA, $-4$ V'ta 2 mA, $+2$ V'ta 12,5 mA. Q: $I_{DQ} \approx 1{,}7$ mA, $V_{GSQ} \approx -4{,}3$ V.

> **Çözüm (derste verilmedi):** $V_D = 20 - 1{,}7 \cdot 6{,}2 = 9{,}46$ V (python ile kontrol edildi).

### Soru 8 (ekrandan, 01:35:00)

$V_{DD} = 12$ V, $R_D = 2$ kΩ, drain–gate arasında $R_G = 10$ MΩ, source toprakta; $I_{D(on)} = 6$ mA, $V_{GS(on)} = 8$ V, $V_{GS(Th)} = 3$ V olan E-MOSFET için $I_{DQ}$ ve $V_{DSQ}$'yu bulun.

**Çözüm (derste verildi):** $k = 0{,}24$ mA/V²; eğri noktaları 6 V'ta 2,16 mA, 10 V'ta 11,76 mA. Doğru $V_{GS} = 12 - 2I_D$ (kesimler 12 V ve 6 mA). Q: $I_{DQ} \approx 2{,}75$ mA, $V_{GSQ} = V_{DSQ} \approx 6{,}4$ V.

### Soru 9 (ekrandan, 01:40:00)

Gerilim bölücülü E-MOSFET devresinde $V_G = 18$ V, $R_S = 0{,}82$ kΩ; $V_{GS(Th)} = 5$ V, $I_{D(on)} = 3$ mA ($V_{GS(on)} = 10$ V). $I_{DQ}$ ve $V_{GSQ}$'yu bulun.

**Çözüm (derste verildi):** $k = 0{,}12 \times 10^{-3}$ A/V²; doğru $V_{GS} = 18 - 0{,}82I_D$ (kesimler 21,95 mA ve 18 V). Q: $I_{DQ} \approx 6{,}7$ mA, $V_{GSQ} \approx 12{,}5$ V.

### Soru 10 (derste sözlü, 00:23:32)

Sembolde ok içeri bakan bir JFET hangi tiptir ve çalışma bölgesinde $V_{GS}$ pozitif mi negatiftir?

**Cevap (derste verildi):** n tipidir; çalışma bölgesinde $V_{GS}$ negatiftir ($V_P \le V_{GS} \le 0$).

## Dersin Toparlaması

Bu derste önce üç FET çeşidi (JFET, kanal ayarlamalı MOSFET, kanal oluşturmalı MOSFET) özet tablo üzerinden tekrar edildi. FET'in gerilim kontrollü olduğu, bütün tiplerde $I_G = 0$ ve $I_D = I_S$ olduğu, JFET ile D-MOSFET'in Shockley denklemine, E-MOSFET'in ise $k(V_{GS} - V_{GS(Th)})^2$ ifadesine uyduğu hatırlatıldı. Transfer eğrisinin $0{,}3V_P \to I_{DSS}/2$ ve $V_P/2 \to I_{DSS}/4$ yardımcı noktalarıyla, E-MOSFET'te ise önce $k$ bulunarak nasıl çizileceği gösterildi. Ardından sabit, kendinden, gerilim bölücü ve geri beslemeli öngerilim devrelerinin denklemleri çıkarıldı.

Dersin ikinci yarısında bu bilgilerle kitaptaki sorular çözüldü. Her soruda aynı yol izlendi: transistörün transfer eğrisini çiz, devreden $V_{GS}$–$I_D$ doğrusunu çıkar, doğrunun eksen kesimlerini bul, kesişimden $I_{DQ}$ ve $V_{GSQ}$'yu oku, sonra $V_D$, $V_S$, $V_{DS}$, $V_{DG}$ gibi gerilimleri Kirchhoff yasasıyla hesapla. Hoca bir sonraki haftanın dersin son dersi olacağını ve az bir konu kaldığını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
