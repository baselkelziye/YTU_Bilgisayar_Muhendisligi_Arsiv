# Ders 24 Genişletilmiş Notu: FET Soru Çözümlerinin Sonu ve İşlemsel Yükselteçlere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ara Sınav Sorularının Çözüm Yolları
- 2. FET Kutuplama Özet Tablosu
- 3. BJT ve n Kanallı JFET'in Birlikte Olduğu Devre
- 4. Gerilim Bölücülü JFET'te Kaynak Direncini Bulma
- 5. Geri Beslemeli E-MOSFET'te Besleme ve Drain Direnci
- 6. p Kanallı JFET, Gerilim Bölücülü Kutuplama
- 7. İşlemsel Yükselteçlere Giriş
- 8. Gerilim Kazancı, Eviren ve Evirmeyen Kavramları
- 9. Eviren Yükselteç
- 10. Evirmeyen Yükselteç
- 11. Diğer Yararlı Op-amp Devreleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Ara Sınav Sorularının Çözüm Yolları

Dersin başında hoca, ekranda "ElkDev_Sorular2.pdf" dosyası açıkken ara sınavdaki dört sorunun çözüm yolunu kısaca hatırlattı (ekrandan, 00:15:00). Sınav soruları, çözüm derslerinde sorulan soruların direnç değerleri ya da diyot ve direnç yerleri değiştirilmiş benzerleriydi.

**Soru 1** standart bir gerilim bölücülü BJT devresiydi. Önce Thevenin gerilimi ve Thevenin direnci bulunur, sonra $I_B$, ondan $I_C$ ve en sonda $V_C$ hesaplanır. Devrede 10 kΩ ve 2 kΩ'luk dirençler vardı.

**Soru 2**'de bir giriş dalga şekli, bir diyot ve ters bağlanmış bir kaynak içeren bir devre verilmişti. Doğru çıkış, girişin belirli seviyelerde düzlenmiş halidir; tahtaya üst seviye 15 V, alt seviye −5,7 V olarak yazıldı (ekrandan, 00:15:00). Hoca birçok öğrencinin çıkışı yuvarlatarak ya da en alta kadar inen bir sinüs gibi çizdiğini söyledi. Bu sorunun benzeri hem ödev hem simülasyon olarak verilmişti.

<!-- BELİRSİZ: Soru 2 devresinin tam bağlantısı ve giriş dalgasının genliği karede tam okunmuyor; tahtada üçgen biçimli bir giriş ve 15, 20, −5,7 değerleri görülüyor. -->

**Soru 3**'te $R_1$ ve $R_C$ verilmemiş, $I_C$ verilmişti. Emitör direnci 1,2 kΩ, alt bölücü direnci 4 kΩ, besleme 22 V, $V_{CE} = 10$ V'tur (ekrandan, 00:15:00 ve 00:20:00). Çözüm yolu:

- $V_E = I_C \cdot 1{,}2\,\text{k}\Omega$ (ara adım: $I_E \approx I_C$).
- $V_B = V_E + V_{BE} = V_E + 0{,}7$ V.
- Bölücüden $V_B = \dfrac{4\,\text{k}\Omega}{4\,\text{k}\Omega + R_1} \cdot 22$ V; buradan $R_1$ çekilir.
- Kollektör-emitör çevresinden $R_C$ çekilir.

> **Ders sonrası not:** Hoca son adımı "$22 = I_C R_C + V_{CE}$" diye söyledi. Emitör direnci olan devrede çevre denklemi büyük olasılıkla $22 = I_C R_C + V_{CE} + I_E R_E$ olmalıdır; yani $R_C = (22 - V_{CE} - V_E)/I_C$. Verilen $I_C$ değeri altyazıda ve karede okunmadığı için sayısal sonuç yazılmadı.

**Soru 4**'te bir tam dalga doğrultucu vardı. Dirençlerin paralel durumundan dolayı girişin üçte biri çıkışa düşüyor, çıkışın tepe değeri 33 V oluyordu. DC (ortalama) değer $33 \cdot 0{,}636 \approx 21$ V'tur (ekrandan, 00:20:00).

<!-- BELİRSİZ: Soru 4'te girişin tepe değeri ve direnç değerleri söylenmedi; "üçte bir" oranının hangi dirençlerden geldiği altyazıdan net değil. -->

### 1.1 Köprüde negatif yarım dalganın pozitife dönmesi

**Soru:** Son soruda negatif dalga neden pozitife dönüştü?

**Cevap:** Hoca bunun köprü doğrultucu dersinde ayrıntılı anlatıldığını hatırlattı ve devreyi tahtada iki duruma ayırdı. Çıkışın soruda sol ucu eksi, sağ ucu artı olarak tanımlanmıştı. Negatif yarım periyotta girişin artı ucu daha düşük potansiyeldedir, bu yüzden bir diyot kesime gider ve devre birbirine paralel iki dirence indirgenir. Bu durumda çıkışın artı ucu yüksek potansiyelli tarafta kalır. Pozitif yarım periyotta öteki diyot iletime geçer, yine iki direnç paralel olur ve çıkışın artı ucu yine yüksek potansiyelde kalır. Çıkışın artı ucu her iki yarım periyotta da yüksek tarafta kaldığı için çıkış tam dalga doğrultulmuş olur. Hoca bunu bir simülasyon programında (ör. Workbench) denemeyi önerdi.

### 1.2 Çözüm yazımı üzerine uyarılar

> **Hocanın vurgusu:** Birimler mutlaka yazılmalı. "4" yazıp bırakan, kΩ mı MΩ mı olduğunu belirtmeyen çözümlerden puan kesildi. Mili ve mikro karıştırılmamalı.

Dalga şekilleri eksenleri ($x$, $t$) belirtilerek ve mümkünse ölçekli çizilmelidir. Bir yerde azalma mı yoksa düzlenme mi olduğu anlaşılmayan, sinüsü düzgün çizilmemiş şekiller değerlendirilemez. Dalga şekillendirme soruları ezberle değil, diyotların hangi aralıkta iletimde olduğu düşünülerek çözülmelidir; çıkışı otomatik olarak sinüse dönüştürmek yanlıştır.

## 2. FET Kutuplama Özet Tablosu

Hoca, önceki hafta FET'lerle ilgili çok soru çözüldüğünü hatırlatıp kitaptaki özet tabloyu gösterdi. Tabloda her FET türü ve kutuplama biçimi için devre, denklemler ve grafik çözüm birlikte verilir (ekrandan, 00:05:00):

| Tür | Denklemler |
|---|---|
| JFET, kendinden kutuplama ($R_D = 0$) | $V_{GS} = -I_D R_S$, $V_D = V_{DD}$, $V_S = I_D R_S$, $V_{DS} = V_{DD} - I_S R_S$ |
| D-MOSFET, sabit kutuplama | $V_{GSQ} = +V_{GG}$, $V_{DS} = V_{DD} - I_D R_S$ |
| D-MOSFET, gerilim bölücülü | $V_G = \dfrac{R_2 V_{DD}}{R_1 + R_2}$, $V_{GS} = V_G - I_S R_S$, $V_{DS} = V_{DD} - I_D(R_D + R_S)$ |
| E-MOSFET, geri beslemeli | $V_{GS} = V_{DS}$, $V_{GS} = V_{DD} - I_D R_D$ |
| E-MOSFET, gerilim bölücülü | $V_G = \dfrac{R_2 V_{DD}}{R_1 + R_2}$, $V_{GS} = V_G - I_D R_S$ |

Hoca bu tablonun sınava hazırlıkta yararlı olacağını söyledi.

## 3. BJT ve n Kanallı JFET'in Birlikte Olduğu Devre

Bu soruda üstte bir npn BJT, altta n kanallı bir JFET aynı seri kol üzerindedir (ekrandan, 00:25:00 ve 00:30:00). Değerler:

- BJT: $\beta = 80$, baz direnci $R_B = 470$ kΩ, kollektör direnci $R_C = 3{,}6$ kΩ.
- JFET: $I_{DSS} = 8$ mA, $V_P = -4$ V, kaynak direnci $R_S = 2{,}4$ kΩ.
- Besleme: 16 V.
- İstenen: iki transistörün arasındaki orta düğümün gerilimi $V_D$.

### 3.1 JFET'in çalışma noktası

JFET'in kapısı doğrudan toprağa bağlı olduğu için $V_G = 0$'dır. Kaynak gerilimi $V_S = I_S \cdot 2{,}4\,\text{k}\Omega$ ve $I_S = I_D$ olduğundan:

$$V_{GS} = V_G - V_S = -I_D \cdot 2{,}4\,\text{k}\Omega$$

Hoca tahtaya önce $V_{GS} = 2{,}4\,\text{k}\Omega \cdot I_D$ yazdı (ekrandan, 00:25:00); slayttaki çözüm $V_{GS} = -I_D R_S$ şeklindedir (ekrandan, 00:30:00).

> **Ders sonrası not:** Tahtadaki ifadede eksi işareti eksik kaldı; doğrusu $V_{GS} = -I_D \cdot 2{,}4\,\text{k}\Omega$'dur. Hoca grafikte doğruyu doğru yönde (negatif $V_{GS}$ tarafına) çizdi.

Transfer eğrisi (Shockley eğrisi) için hoca iki kısayol noktası kullandı:

- $V_{GS} = 0{,}3V_P = -1{,}2$ V'ta $I_D \approx I_{DSS}/2 = 4$ mA.
- $V_{GS} = V_P/2 = -2$ V'ta $I_D = I_{DSS}/4 = 2$ mA.

Bu noktalar, $V_{GS} = 0$'daki $I_{DSS} = 8$ mA ve $V_{GS} = V_P = -4$ V'taki $I_D = 0$ ile birlikte eğriyi çizmeye yeter. Hoca, sınavda bu noktaların hesaplanarak bulunduğunun görünmesini istedi.

Kendinden kutuplama doğrusu $V_{GS} = 0$ için $I_D = 0$ verir, yani orijinden geçer. İkinci nokta için $V_{GS} = -4$ V konur: $I_D = 4\,\text{V} / 2{,}4\,\text{k}\Omega = 1{,}67$ mA (ekrandan, 00:30:00). İki noktadan geçen doğru eğriyi kestiği yerde çalışma noktası okunur: $V_{GSQ} = -2{,}6$ V, $I_{DQ} = 1$ mA (ekrandan, 00:30:00). Hoca kendi çiziminde kesişimi $-2{,}5$ V ve yaklaşık 1,1 ile 1,2 mA arasında okudu ve grafik çözümde bu kadar farkın önemli olmadığını söyledi.

> **Ders sonrası not:** Shockley denklemi $I_D = 8(1 + V_{GS}/4)^2$ mA ile $V_{GS} = -2{,}4 I_D$ birlikte çözülünce $V_{GSQ} \approx -2{,}54$ V, $I_{DQ} \approx 1{,}06$ mA çıkar (python ile kontrol edildi). Grafikten okunan değerler buna yakındır.

### 3.2 BJT tarafı ve $V_D$

JFET ile BJT aynı koldadır; bu yüzden $I_D = I_S$, aynı zamanda BJT'nin emitör akımı $I_E$'dir ve $I_E \approx I_C$:

$$I_E \approx I_C = I_D = 1\,\text{mA}$$

$$I_B = \frac{I_C}{\beta} = \frac{1\,\text{mA}}{80} = 12{,}5\,\mu\text{A}$$

Baz düğümünün gerilimi, 470 kΩ üzerindeki düşüm beslemeden çıkarılarak bulunur:

$$V_B = 16\,\text{V} - (12{,}5\,\mu\text{A})(470\,\text{k}\Omega) = 16 - 5{,}875 = 10{,}125\,\text{V}$$

$$V_E = V_D = V_B - V_{BE} = 10{,}125 - 0{,}7 = 9{,}425\,\text{V}$$

(ekrandan, 00:30:00). Hoca aynı sonucun KVL ile $16 = I_B \cdot 470\,\text{k}\Omega + V_{BE} + V_D$ yazılarak da bulunabileceğini gösterdi.

**Soru:** Kollektör akımı bilindiğine göre neden baz akımı üzerinden gittik, kollektör tarafından hesaplayamaz mıydık?

**Cevap:** Kollektör tarafından gitmek için $V_{CE}$ ve $V_{DS}$'nin de bilinmesi gerekir. Şu ana kadar bulunan yalnız $V_{GS}$'dir, $V_{DS}$ bulunmadı. Bu bilinmeyenler çıkarılmadan o yoldan gidilemez.

## 4. Gerilim Bölücülü JFET'te Kaynak Direncini Bulma

Kitaptaki Örnek 6.16'da (Şekil 6.52) besleme 16 V, bölücü dirençleri 91 kΩ (üst) ve 47 kΩ (alt), drain direnci 1,8 kΩ'dur. Drain gerilimi $V_D = 12$ V ve $V_{GSQ} = -2$ V verilmiş, $R_S$ isteniyor (ekrandan, 00:35:00).

Önce bölücüden kapı gerilimi bulunur (kapıdan akım akmaz):

$$V_G = \frac{47\,\text{k}\Omega \cdot 16\,\text{V}}{47\,\text{k}\Omega + 91\,\text{k}\Omega} = 5{,}44\,\text{V}$$

Drain direncinin iki ucunun gerilimi bilindiği için üzerinden geçen akım bulunur:

$$I_D = \frac{V_{DD} - V_D}{R_D} = \frac{16 - 12}{1{,}8\,\text{k}\Omega} = 2{,}22\,\text{mA}$$

Son olarak $V_{GS}$ denklemi kurulur:

$$V_{GS} = V_G - I_D R_S \;\Rightarrow\; -2 = 5{,}44 - (2{,}22\,\text{mA}) R_S \;\Rightarrow\; R_S = \frac{7{,}44\,\text{V}}{2{,}22\,\text{mA}} = 3{,}35\,\text{k}\Omega$$

(ekrandan, 00:35:00). Slayta göre en yakın standart ticari değer 3,3 kΩ'dur. Hoca akımı sözlü olarak 2,2 mA diye yuvarladı; sonuç değişmez (python ile kontrol: $V_G = 5{,}449$ V, $I_D = 2{,}222$ mA, $R_S = 3{,}35$ kΩ).

## 5. Geri Beslemeli E-MOSFET'te Besleme ve Drain Direnci

Kitaptaki Örnek 6.17'de (Şekil 6.53) n kanallı bir E-MOSFET (kanal oluşturmalı MOSFET) kapı ile drain arasına bağlı 10 MΩ'luk bir dirençle geri beslenmiştir. Eleman verileri: $V_{GS(on)} = 6$ V, $I_{D(on)} = 4$ mA, $V_{GS(Th)} = 3$ V. Ayrıca $V_{DS} = V_{DD}/2$ ve $I_D = I_{D(on)}$ verilmiştir. $V_{DD}$ ve $R_D$ isteniyor (ekrandan, 00:40:00).

- $I_D = I_{D(on)} = 4$ mA olduğuna göre bu akımdaki kapı-kaynak gerilimi $V_{GS} = V_{GS(on)} = 6$ V'tur.
- Kaynak doğrudan toprağa bağlı olduğundan $V_S = 0$, dolayısıyla $V_G = 6$ V.
- 10 MΩ'luk dirençten akım akmaz (kapı akımı sıfır), bu yüzden direncin iki ucu aynı gerilimdedir: $V_D = V_G$, yani $V_{DS} = V_{GS} = 6$ V.
- $V_{DS} = V_{DD}/2$ olduğundan $V_{DD} = 12$ V. Gerilimin yarısı elemana, yarısı $R_D$'ye düşer.
- $R_D$ üzerindeki gerilim $12 - 6 = 6$ V'tur: $R_D = \dfrac{6\,\text{V}}{4\,\text{mA}} = 1{,}5\,\text{k}\Omega$.

Slayta göre 1,5 kΩ standart bir ticari değerdir (ekrandan, 00:40:00).

## 6. p Kanallı JFET, Gerilim Bölücülü Kutuplama

### 6.1 p kanalın grafiği

Hoca önce dersin başındaki n kanallı JFET grafiğini hatırlattı: n kanalda transfer eğrisi $V_{GS}$ ekseninin negatif tarafında, pinch-off gerilimi negatif olan, sağa doğru yükselen bir eğridir. p kanallı JFET'te her şey terstir: eğri sola doğru yükselir, pinch-off gerilimi pozitiftir. Bu soruda $V_P = +4$ V ve $I_{DSS} = 8$ mA'dir (ekrandan, 00:45:00).

### 6.2 Devre ve çalışma noktası

Devre gerilim bölücülüdür ama besleme $-20$ V'tur; yani $V_{DD}$ pozitif değil, devre ters yapıda kurulmuştur. Bölücü dirençleri 68 kΩ ve 20 kΩ, $R_S = 1{,}8$ kΩ, $R_D = 2{,}7$ kΩ'dur (ekrandan, 00:45:00). İstenen: $I_{DQ}$, $V_{GSQ}$ ve $V_{DS}$.

Kapı gerilimi, işaretlere dikkat edilerek:

$$V_G = \frac{20\,\text{k}\Omega \cdot (-20\,\text{V})}{20\,\text{k}\Omega + 68\,\text{k}\Omega} = -4{,}55\,\text{V}$$

Hoca burada işaretin neden değiştiğini vurguladı. n kanalda $V_{GS} = V_G - V_S$ yazılırken kaynak direncinin gerilimi akımın yönüne göre tanımlanıyordu. p kanalda akım ters yönde aktığı için kaynak direncinin gerilimi de ters yazılır. Kapı-kaynak çevresinde KVL:

$$V_G - V_{GS} + I_D R_S = 0 \;\Rightarrow\; V_{GS} = V_G + I_D R_S$$

(ekrandan, 00:45:00). Kutuplama doğrusunun eksen kesimleri:

- $I_D = 0$ için $V_{GS} = V_G = -4{,}55$ V.
- $V_{GS} = 0$ için $I_D = -\dfrac{V_G}{R_S} = -\dfrac{-4{,}55\,\text{V}}{1{,}8\,\text{k}\Omega} = 2{,}53$ mA.

Transfer eğrisi n kanaldaki kısayollarla, bu kez pozitif tarafta çizilir: $0{,}3V_P = 1{,}2$ V'ta $I_D \approx 4$ mA, $V_P/2 = 2$ V'ta $I_D = 2$ mA. Doğru cetvelle çizilir ve kesişim okunur:

$$I_{DQ} = 3{,}4\,\text{mA}, \qquad V_{GSQ} = 1{,}4\,\text{V}$$

(ekrandan, 00:45:00).

> **Hocanın vurgusu:** p kanalda bu değerler eksili olmuyor; $V_{GSQ}$ pozitif çıkar. Sınava cetvel getirilmeli, eğri ve doğru düzgün çizilmeli.

> **Ders sonrası not:** $I_D = 8(1 - V_{GS}/4)^2$ mA ve $V_{GS} = -4{,}55 + 1{,}8 I_D$ birlikte çözülünce $I_{DQ} \approx 3{,}32$ mA, $V_{GSQ} \approx 1{,}42$ V çıkar (python ile kontrol edildi). Grafikten okunan 3,4 mA ve 1,4 V bunun okuma hassasiyetindeki karşılığıdır.

### 6.3 $V_{DS}$

Drain-kaynak çevresinde, akım ters yönde aktığı için dirençlerin gerilimleri eksi işaretle girer (ekrandan, 00:45:00):

$$-I_D R_S + V_{DS} - I_D R_D + V_{DD} = 0 \;\Rightarrow\; V_{DS} = -V_{DD} + I_D (R_D + R_S)$$

$$V_{DS} = -20\,\text{V} + (3{,}4\,\text{mA})(2{,}7\,\text{k}\Omega + 1{,}8\,\text{k}\Omega) = -20 + 15{,}3 = -4{,}7\,\text{V}$$

Burada $V_{DD}$, beslemenin büyüklüğü 20 V olarak alınmıştır. Hoca bununla FET'lerin bütün türlerinden soru çözülmüş olduğunu söyledi.

## 7. İşlemsel Yükselteçlere Giriş

Dersin son konusu işlemsel yükselteçlerdir (operational amplifier, op-amp). Slayt dosyası "ElDev_12.pdf"tir (ekrandan, 00:50:00). Op-amp'ler elektronikte özellikle gerilim yükseltmede çok sık kullanılır; hem ayaklı (delikli montaj) hem yüzey montajlı çip olarak bulunur.

### 7.1 Sembol ve uçlar

Op-amp bir üçgenle gösterilir. Üstte eksi ucu (eviren giriş, inverting input, $V_{in}^-$), altta artı ucu (evirmeyen giriş, non-inverting input, $V_{in}^+$), sağda çıkış $V_{out}$ vardır. Çizimlerde eviren giriş genellikle üstte gösterilir.

Bunların dışında besleme uçları vardır: $V_{pos}$ ve $V_{neg}$. Çıkış gerilimini oluşturabilmek için op-amp'e ayrıca güç bağlamak gerekir; bu besleme örneğin +12 V / −12 V ya da +5 V / −5 V olabilir. Hesaplarda op-amp yine üç uçlu (iki giriş, bir çıkış) bir eleman gibi düşünülür.

Bir pakette tek, iki ya da dört op-amp bulunabilir (ekrandan, 00:50:00):

- Tekli op-amp (8 bacak): 2 eviren giriş, 3 evirmeyen giriş, 4 $V_{neg}$, 6 çıkış, 7 $V_{pos}$.
- İkili op-amp (8 bacak): 1 çıkış, 2 eviren, 3 evirmeyen, 4 $V_{neg}$; 5 evirmeyen, 6 eviren, 7 çıkış, 8 $V_{pos}$.
- Dörtlü op-amp (14 bacak): 4 $V_{pos}$, 11 $V_{neg}$; diğer bacaklar dört op-amp'in giriş ve çıkışlarıdır.

### 7.2 İdeal op-amp

İdeal op-amp'te gerilim kazancı sonsuz, giriş direnci sonsuz, çıkış direnci sıfır kabul edilir. Bunun iki sonucu vardır:

- Kazanç sonsuz ve çıkış sonlu olduğuna göre girişler arasındaki gerilim sıfır olmalıdır: $V_+ = V_-$. Eviren giriş, evirmeyen girişle aynı gerilimdedir.
- Giriş direnci sonsuz olduğundan op-amp'in girişlerinden içeri akım akmaz: $I_+ = I_- = 0$.

## 8. Gerilim Kazancı, Eviren ve Evirmeyen Kavramları

Gerilim kazancı çıkış geriliminin giriş gerilimine oranıdır (ekrandan, 01:05:00):

$$A_v = \frac{V_o}{V_i}$$

Girişe 1 V verip çıkışta 2 V alıyorsanız kazanç 2'dir. Slayttaki blok gösterimde $A_v = 2$ olan bir yükselteç sinüs girişin genliğini iki katına çıkarır. Giriş üçgen dalga olsaydı çıkış iki kat genlikli üçgen, kare dalga olsaydı iki kat genlikli kare olurdu. Periyot değişmez, faz kayması olmaz; işaret olduğu gibi büyütülür. Bu, evirmeyen (non-inverting) yükseltecin davranışıdır.

$A_v = -2$ olduğunda genlik yine iki katına çıkar, ama baştaki eksi işaret 180°'lik faz kaymasını gösterir: girişin pozitif tepeleri çıkışta negatif, negatif tepeleri pozitif olur. Bu eviren (inverting) yükselteçtir. Hoca bunu sinüs ile kosinüs arasındaki 90°'lik farkla karşılaştırdı: negatiflerin tamamen pozitife döndüğü durumda fark 180°'dir.

> **Ders sonrası not:** Hoca bir yerde (01:05:10) "180 derecelik veya pi bölü 2'lik faz farkı" dedi; 180° radyan cinsinden $\pi$'dir, $\pi/2$ ise 90°'dir.

> **Hocanın vurgusu:** Kazançtaki eksi işareti negatif yönde bir kazanç anlamına gelmez; yalnız fazın ne kadar kaydığını (180°) gösterir.

Kazancı $-1$ olan bir yükselteç girişin işaretini tam tersine çevirir, genliği değiştirmez.

## 9. Eviren Yükselteç

Hoca en temel yapı olduğu için önce eviren yükselteci anlattı (ekrandan, 01:10:00 ve 01:15:00). Devrede giriş $V_i$, $R_2$ direnci üzerinden eviren girişe (A düğümü) bağlanır. Çıkıştan eviren girişe $R_1$ geri besleme direnci bağlıdır. Evirmeyen giriş doğrudan topraktadır.

### 9.1 Akım yönüne göre işaret

Hoca türetmeye geçmeden önce akım yönüne göre gerilim yazmayı ayrı bir örnekle açıkladı. Bir noktadan başlayıp iki direnç üzerinden toprağa gidildiğini düşünelim. İki akım da aynı yönde tanımlanmışsa $I_1 = I_2$'dir ve aradaki düğümün gerilimi $V_x = I_2 R_2$ diye yazılır. $I_2$ ters yönde tanımlanmışsa bu dirençte oluşan gerilimin kutbu da terstir, ifade $-I_2 R_2$ olur. Bir dirençteki gerilim, akımın tanımlandığı yöne göre yazılır.

### 9.2 Türetme

Slayttaki tanımlara göre $I_2$, $V_i$'den A düğümüne doğru; $I_1$ ise $V_o$'dan A düğümüne doğru akar. İki akım da A düğümüne girer ve op-amp'e akım akmaz, bu yüzden:

$$I_1 = -I_2$$

$V_+$ toprağa bağlı olduğundan $V_- = V_+ = 0$'dır. Akımlar:

$$I_1 = \frac{V_o - V_-}{R_1} = \frac{V_o}{R_1}, \qquad I_2 = \frac{V_i - V_-}{R_2} = \frac{V_i}{R_2}$$

Yerine konunca:

$$\frac{V_i}{R_2} = -\frac{V_o}{R_1} \;\Rightarrow\; A_v = \frac{V_o}{V_i} = -\frac{R_1}{R_2}$$

(ekrandan, 01:10:00 ve 01:25:00). Kazancı geri besleme direncinin giriş direncine oranı belirler.

> **Ders sonrası not:** Hoca tekrar türetirken (01:16:10) oranı önce "eksi R2 bölü R1" diye söyledi, hemen ardından "burası R1, burası R2 olacak, yanlış yaptım" diye düzeltti. Slayttaki gösterimle doğrusu $-R_1/R_2$'dir; tahtadaki son satırda da paydaki $R_2$ düzeltilmiş görünüyor (ekrandan, 01:25:00).

Sayısal örnekler:

- $R_1 = R_2 = 1$ kΩ: $A_v = -1$. Devre girişi yalnız evirir.
- $R_1 = 2$ kΩ, $R_2 = 1$ kΩ: $A_v = -2$. Çıkış hem evrilir hem genliği iki katına çıkar.
- $R_1 = 25$ kΩ, $R_2 = 1$ kΩ: $A_v = -25$.

> **Hocanın vurgusu:** Op-amp'li bir soruda bilinmesi gereken temel şey $V_- = V_+$'dır. Bu soruda ikisi de sıfırdır, çünkü $V_+$ doğrudan toprağa bağlıdır. $V_+$ ile toprak arasında bir direnç olsaydı bu kadar kolay söylenemezdi.

**Soru:** Devrenin eviren mi evirmeyen mi olduğunu soruda belirtiyorlar mı?

**Cevap:** Sonuçtan anlaşılır. Kazanç bulununca işaretine bakılır.

## 10. Evirmeyen Yükselteç

Bu konfigürasyonda giriş $V_i$ evirmeyen uca uygulanır. Çıkış ile toprak arasında $R_1$ (üstte) ve $R_2$ (altta) seri bağlıdır; ikisinin ortak düğümü eviren girişe bağlıdır (ekrandan, 01:20:00).

$V_+ = V_i$ ve $V_- = V_+$ olduğundan eviren giriş de, yani $R_1$-$R_2$ ortak düğümü de $V_i$ gerilimindedir. Amaç her zaman $A_v = V_o/V_i$'yi bulmaktır.

**Birinci yol (gerilim bölücü):** Op-amp'e akım akmadığı için $R_1$ ve $R_2$ bir gerilim bölücüdür (hoca transistörlerde hep çözülen bölücüyü hatırlattı):

$$V_i = \frac{R_2}{R_1 + R_2} V_o \;\Rightarrow\; A_v = \frac{V_o}{V_i} = \frac{R_1 + R_2}{R_2}$$

**İkinci yol (akım eşitliği):** $R_1$'den geçen akım $R_2$'den geçen akıma eşittir, $I_1 = I_2$:

$$\frac{V_o - V_i}{R_1} = \frac{V_i - 0}{R_2} \;\Rightarrow\; R_2 V_o - R_2 V_i = R_1 V_i \;\Rightarrow\; R_2 V_o = V_i (R_1 + R_2)$$

$$A_v = \frac{R_1 + R_2}{R_2} = 1 + \frac{R_1}{R_2}$$

İki yol aynı sonucu verir. Dirençler negatif değer almadığı için bu kazanç her zaman pozitiftir. Örneğin $R_1 = R_2 = 1$ kΩ seçilirse kazanç 2 olur ve çıkış evrilmez; bu yüzden devrenin adı evirmeyen yükselteçtir (non-inverting amplifier). Farklı dirençler bağlanarak farklı kazançlar elde edilir; sorularda genellikle bir giriş verilip kaç kat kazanç oluştuğu sorulur.

## 11. Diğer Yararlı Op-amp Devreleri

<!-- BELİRSİZ: Bu bölümdeki tampon, akım-gerilim dönüştürücü, toplayıcı ve integral alıcı slaytlarının karesi yok (fark yükselteci hariç); bağıntılar hocanın sözlü anlatımından kuruldu. -->

### 11.1 Birim kazançlı tampon yükseltici

Unity gain buffer amplifier (birim kazançlı tampon yükseltici) devresinde çıkış doğrudan eviren girişe bağlıdır, giriş evirmeyen uçtadır. $V_- = V_o$ ve $V_+ = V_i$; $V_+ = V_-$ olduğundan $V_o = V_i$'dir.

Kazancı 1 olduğu için ilk bakışta yararsız görünebilir. Ama op-amp'in giriş direnci çok yüksek, çıkış direnci çok düşük olduğu için tampon olarak kullanılır. Hoca mikroişlemci ve mikrodenetleyici derslerinde görülen tampon yapısını örnek verdi: bir gerilim çıkışa aktarılmak istenir; çıkışta bir kısa devre olursa bunun devrenin içine zarar vermemesi için araya op-amp'li tampon konur.

Tampon, evirmeyen yükseltecin özel hali olarak da görülebilir: evirmeyen formülde $R_1 = 0$ (geri besleme kısa devre) ve $R_2 = \infty$ (eviren uçtan toprağa bir şey bağlı değil) alınırsa $A_v = 1 + 0/\infty = 1$ olur.

### 11.2 Akımdan gerilime dönüştürücü

Bu devrede giriş akımı $I_i$ eviren düğüme girer, çıkıştan eviren girişe bir $R$ direnci bağlıdır, evirmeyen giriş topraktadır. Op-amp'e akım girmediği için giriş akımı tamamen $R$ üzerinden akar; $I_R$ ters yönde tanımlandığından $I_i = -I_R$:

$$I_R = \frac{V_o - V_-}{R}, \qquad V_- = V_+ = 0 \;\Rightarrow\; I_i = -\frac{V_o}{R} \;\Rightarrow\; V_o = -I_i R$$

Sonuçta giriş gerilimiyle ilgili bir terim yoktur; çıkış gerilimi giriş akımıyla orantılıdır. $R$ sabit bir katsayıdır (ör. 1 ya da 2 kΩ). Yalnız gerilim ölçebilen bir multimetreniz varsa böyle bir devre kurup çıkış gerilimini ölçerek girişteki akımı $R$ oranında, evrilmiş biçimde bulabilirsiniz.

### 11.3 Fark yükselteci (çıkarıcı)

Slayttaki devrede $V_2$, $R_2$ üzerinden eviren girişe; $V_1$, $R_2$ üzerinden evirmeyen girişe bağlıdır. Eviren tarafta geri besleme direnci $R_1$, evirmeyen girişten toprağa yine $R_1$ vardır (ekrandan, 01:30:00).

Evirmeyen giriş (B noktası) bir gerilim bölücüdür:

$$V_+ = \frac{R_1}{R_1 + R_2} V_1 = V_-$$

Eviren tarafta (A noktası) $V_A = V_B$ alınır ve $I_2 = I_1$ yazılır:

$$\frac{V_2 - V_A}{R_2} = \frac{V_A - V_o}{R_1}, \qquad V_A = \frac{R_1 V_1}{R_1 + R_2}$$

(ara adım eklendi: akım eşitliği hocanın sözlü kurduğu biçimde, yönler slayta göre yazıldı). Sadeleştirilince slayttaki sonuç çıkar (ekrandan, 01:30:00):

$$V_o = (V_1 - V_2)\frac{R_1}{R_2}$$

$R_1/R_2$ bir orandır; $R_1$, $R_2$'nin iki katı seçilirse çarpan 2, yarısı seçilirse 1/2 olur. Devre iki gerilimin farkını bir katsayıyla çarptığı için fark yükselteci (differential amplifier) adını alır.

### 11.4 Eviren toplayıcı

Bu devrede iki giriş $V_1$ ve $V_2$, her biri $R_2$ direnci üzerinden eviren girişe bağlıdır; geri besleme direnci $R_1$'dir, $V_+ = 0$'dır. Eviren düğümde $I_1 + I_2 = -I_3$ yazılır:

$$\frac{V_1 - 0}{R_2} + \frac{V_2 - 0}{R_2} = -\frac{V_o - 0}{R_1} \;\Rightarrow\; V_o = -\frac{R_1}{R_2}(V_1 + V_2)$$

(son eşitlik ara adım eklendi; hoca yalnız sadeleştirmenin yapılacağını söyledi). Devre hem evirir (eksi işaret) hem toplar; bu yüzden eviren toplayıcı (inverting summer) adını alır. $R_1 = R_2$ seçilirse çıkış doğrudan girişlerin toplamının eksi işaretlisidir.

### 11.5 İntegral alıcı ve türev alıcı

İntegral alıcıda (integrator) çıkış, girişin 0'dan $t$ anına kadar altında kalan alanın toplamıyla orantılıdır:

$$V_o = -\frac{1}{RC}\int_0^t V_i\,dt$$

$R$ ve $C$ sayısal değerler olduğu için $1/RC$ sabit bir katsayıdır. Baştaki eksi işaret çıkışın girişe göre 180° faz farklı olduğunu gösterir. $R$ ile $C$ yer değiştirirse devre türev alıcı olur ve çıkış $dV_i/dt$ ile orantılı çıkar; hoca bunun devre teorisinden bilinen kondansatör akım-gerilim bağıntısından elde edildiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Türev alıcının çıkışı büyük olasılıkla $V_o = -RC\,\dfrac{dV_i}{dt}$ biçimindedir. Bu, kondansatör akımının $i_C = C\,dv/dt$ olmasından ve $V_- = 0$ kabulünden çıkar.

### 11.6 Op-amp sorularında genel yöntem

Hoca konuyu şöyle bağladı: op-amp'li bir soruda op-amp'in içinden akım akmadığı ($I_+ = I_- = 0$) ve iki girişin aynı gerilimde olduğu ($V_+ = V_-$) bilinir. Bu iki kurala göre düğüm akımları akım yönlerine dikkat edilerek yazılır ve istenen büyüklük ($V_o/V_i$, akım ya da gerilim) bulunur.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): Tam dalga doğrultucunun çıkışının tepe değeri 33 V'tur. Çıkışın DC değeri nedir?

> **Çözüm:** Tam dalga doğrultulmuş sinüsün ortalaması tepe değerin $2/\pi \approx 0{,}636$ katıdır: $V_{DC} = 0{,}636 \cdot 33 \approx 21$ V (python ile kontrol: $20{,}99$ V).

**Soru 2** (ekrandan, 00:25:00 ve 00:30:00): Üstte $\beta = 80$ olan bir npn BJT ($R_B = 470$ kΩ, $R_C = 3{,}6$ kΩ), altta $I_{DSS} = 8$ mA, $V_P = -4$ V olan n kanallı bir JFET ($R_S = 2{,}4$ kΩ, kapı toprakta) aynı koldadır; besleme 16 V'tur. $V_D$'yi bulun.

> **Çözüm:** $V_{GS} = -I_D \cdot 2{,}4$ kΩ doğrusu ile transfer eğrisinin kesişiminden $V_{GSQ} \approx -2{,}6$ V, $I_{DQ} \approx 1$ mA. $I_C = 1$ mA, $I_B = 12{,}5$ µA, $V_B = 16 - 5{,}875 = 10{,}125$ V, $V_D = V_E = 10{,}125 - 0{,}7 = 9{,}425$ V.

**Soru 3** (ekrandan, 00:35:00): Gerilim bölücülü JFET devresinde $V_{DD} = 16$ V, bölücü 91 kΩ / 47 kΩ, $R_D = 1{,}8$ kΩ'dur. $V_D = 12$ V ve $V_{GSQ} = -2$ V ise $R_S$ nedir?

> **Çözüm:** $V_G = 5{,}44$ V, $I_D = 4\,\text{V}/1{,}8\,\text{k}\Omega = 2{,}22$ mA, $R_S = (5{,}44 + 2)/2{,}22\,\text{mA} = 3{,}35$ kΩ (standart değer 3,3 kΩ).

**Soru 4** (ekrandan, 00:40:00): Geri beslemeli E-MOSFET devresinde $V_{GS(on)} = 6$ V, $I_{D(on)} = 4$ mA, $V_{GS(Th)} = 3$ V, $R_G = 10$ MΩ'dur. $I_D = I_{D(on)}$ ve $V_{DS} = V_{DD}/2$ ise $V_{DD}$ ve $R_D$ nedir?

> **Çözüm:** $V_{DS} = V_{GS} = 6$ V, $V_{DD} = 12$ V, $R_D = (12 - 6)\,\text{V}/4\,\text{mA} = 1{,}5$ kΩ.

**Soru 5** (ekrandan, 00:45:00): p kanallı JFET ($I_{DSS} = 8$ mA, $V_P = 4$ V), besleme $-20$ V, bölücü 68 kΩ / 20 kΩ, $R_S = 1{,}8$ kΩ, $R_D = 2{,}7$ kΩ. $I_{DQ}$, $V_{GSQ}$ ve $V_{DS}$'yi bulun.

> **Çözüm:** $V_G = -4{,}55$ V, $V_{GS} = V_G + I_D R_S$; doğru $(-4{,}55\text{ V};\ 0)$ ve $(0;\ 2{,}53\text{ mA})$ noktalarından geçer. Grafikten $I_{DQ} = 3{,}4$ mA, $V_{GSQ} = 1{,}4$ V. $V_{DS} = -20 + 3{,}4\,\text{mA} \cdot 4{,}5\,\text{k}\Omega = -4{,}7$ V.

**Soru 6** (derste sözlü, 01:22:29): Eviren yükselteçte geri besleme direnci $R_1 = 25$ kΩ, giriş direnci $R_2 = 1$ kΩ ise kazanç nedir?

> **Çözüm:** $A_v = -R_1/R_2 = -25$. Çıkış girişin 25 katı genlikte ve 180° faz farklıdır.

**Soru 7** (derste sözlü, 01:21:30): Evirmeyen yükselteçte $R_1 = R_2 = 1$ kΩ ise kazanç nedir, çıkış evrilir mi?

> **Çözüm:** $A_v = 1 + R_1/R_2 = 2$. Kazanç pozitif olduğundan çıkış evrilmez.

## Dersin Toparlaması

Dersin ilk yarısında ara sınav sorularının çözüm yolları hatırlatıldı ve FET soru çözümleri tamamlandı. BJT ile JFET'in aynı kolda olduğu devrede önce JFET'in çalışma noktası grafikle bulunup bu akım BJT tarafına taşındı. Gerilim bölücülü JFET'te verilen çalışma noktasından $R_S$, geri beslemeli E-MOSFET'te $V_{GS} = V_{DS}$ eşitliğinden $V_{DD}$ ve $R_D$ bulundu. p kanallı JFET'te besleme negatif olduğu için akım yönüne göre işaretlerin ters yazılması gerektiği ve $V_{GSQ}$'nun pozitif çıktığı gösterildi. Böylece kitaptaki bütün FET türlerinden soru çözülmüş oldu.

İkinci yarıda dersin son konusu olan işlemsel yükselteçlere girildi. İdeal op-amp'in iki kuralı ($V_+ = V_-$ ve giriş akımlarının sıfır olması) ile gerilim kazancı ve kazançtaki eksi işaretin 180° faz farkı anlamı anlatıldı. Bu kurallardan eviren ($-R_1/R_2$) ve evirmeyen ($1 + R_1/R_2$) yükselteçlerin kazancı türetildi. Ardından tampon, akım-gerilim dönüştürücü, fark yükselteci, eviren toplayıcı ve integral alıcı devreleri aynı yöntemle incelendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
