# Ders 23 Genişletilmiş Notu: FET Kutuplama Soru Çözümleri (JFET, D-MOSFET, E-MOSFET)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. FET türlerinin ve karakteristiklerinin hatırlatılması
- 2. Grafik çözüm yönteminin mantığı
- 3. Öz kutuplamalı N kanal D-MOSFET
- 4. Kapısı toprağa bağlı D-MOSFET
- 5. Geri beslemeli E-MOSFET
- 6. Gerilim bölücülü E-MOSFET
- 7. Kutuplama türlerinin özet tablosu
- 8. JFET ve BJT'nin birlikte olduğu devre
- 9. Tasarım örneği: gerilim bölücülü JFET'te $R_S$
- 10. Tasarım örneği: geri beslemeli E-MOSFET'te $V_{DD}$ ve $R_D$
- 11. Gerilim bölücülü P kanal JFET
- Örnek Sorular
- Dersin Toparlaması

## 1. FET türlerinin ve karakteristiklerinin hatırlatılması

Ders, önceki haftalarda başlanan FET kutuplama konusunun soru çözümleriyle devam eder. Ekranda İngilizce bir ders kitabından alınmış örnekleri ve çözümleri içeren bir PDF açıktır; hoca örneklerin üzerine kalemle işaret koyarak, ara notlar yazarak anlatır.

Önce sınıflandırma hatırlatılır. FET'ler iki ana gruba ayrılır: JFET ve MOSFET. MOSFET'ler de kendi içinde ikiye ayrılır:

- **Kanal ayarlamalı MOSFET** (D-MOSFET, depletion type): kanal yapıda zaten vardır; kapı gerilimiyle kanalın genişliği ayarlanır.
- **Kanal oluşturmalı MOSFET** (E-MOSFET, enhancement type): başlangıçta kanal yoktur; kapıya yeterli gerilim verilince kanal oluşur.

Bu üç türün her birinin N kanal ve P kanal çeşidi vardır. Hoca, sembol çizimlerinden de bunun anlaşılabileceğini belirtir: kanal oluşturmalı MOSFET'in sembolünde kanal çizgisi kesik kesiktir, yani kanal henüz oluşmamıştır; kanal ayarlamalıda kanal sürekli çizilir.

> **Ders sonrası not:** Hoca karakteristik tablosunu anlatırken D-MOSFET'e önce "kanal oluşturmalı" dedi, hemen ardından düzeltti: D-MOSFET kanal ayarlamalı, E-MOSFET kanal oluşturmalıdır.

### 1.1 Transfer eğrilerinin karşılaştırılması

N kanal yapıların hepsinde $I_D$-$V_{GS}$ eğrisi sağa doğru yükselen, üstel görünüşlü (karesel) bir eğridir. P kanal yapılarda bütün eğilimler bunun tersidir.

- **N kanal JFET:** eğri negatif bir $V_P$ değerinden (örneğin $-4$ V) başlar ve $V_{GS}=0$'da $I_{DSS}$ değerine ulaşır; orada biter.
- **N kanal D-MOSFET:** eğrisi JFET'inkine çok benzer; negatif $V_P$'den başlar, $V_{GS}=0$'da $I_{DSS}$'den geçer, ama pozitif $V_{GS}$ bölgesine de devam edebilir. Yani $I_{DSS}$ aşılabilir.
- **N kanal E-MOSFET:** onlardan çok farklıdır. $V_{GS}=0$ iken akım yoktur; eğri pozitif bir eşik geriliminden ($V_{GS(Th)}$, örneğin $3$ V) sonra başlar. Kanal önce bu gerilimle oluşur, sonra akım artmaya başlar.

## 2. Grafik çözüm yönteminin mantığı

FET devrelerinde amaç çalışma noktasını, yani $I_{D_Q}$ ve $V_{GS_Q}$ değerlerini bulmaktır. Bütün karakteristikler $I_D$ ve $V_{GS}$ değişkenleri üzerine kurulduğu için çözüm de bu iki değişkenle yapılır. Hoca bunu $x$-$y$ düzlemine benzetir: $V_{GS}$ yatay eksendeki $x$ değişkeni, $I_D$ dikey eksendeki $y$ değişkenidir.

Çözüm iki parçadan oluşur:

- **Transistörün kendi eğrisi:** verilen parametrelerden ($I_{DSS}$ ve $V_P$ ya da $k$ ve $V_{GS(Th)}$) çizilen transfer eğrisi. Bu eğri devreden değil, elemanın kendisinden gelir.
- **Devrenin kutuplama doğrusu:** devreden yazılan, $V_{GS}$ ile $I_D$ arasındaki doğrusal denklem. Bu doğrunun eksenleri kestiği noktalar bulunup doğru çizilir.

İkisinin kesiştiği nokta çalışma noktasıdır. Hoca "işin özü" olarak bunu vurgular: transistöre has eğriyi bulduktan sonra devreden bir doğru denklemi bulup ikisini kesiştirmek.

FET'te kapı akımı sıfırdır ($I_G=0$). Bu iki sonuç doğurur:

- Kaynak akımı savak akımına eşittir: $I_S=I_D$.
- Kapıya bağlı dirençten akım akmadığı için üzerinde gerilim düşmez. Hoca bunu bir direncin iki ucu üzerinden açıklar: dirençten geçen akım $I=0$ ise $V_{AB}=I\cdot R=0$ olur, yani $V_A=V_B$; direncin iki ucu aynı gerilimdedir.

Gerilim bölücülü yapılarda önce $V_G$ bulunur. Hoca daha önceki haftalarda çözülen bir örneği hatırlatır: $110$ ve $10$'luk dirençlerden oluşan bir bölücüde $V_G=\frac{10}{110+10}V_{DD}$ yazılır, sonra $V_{GS}=V_G-I_DR_S$ ile doğru denklemi elde edilir. N kanalda akım aşağı doğru (savaktan kaynağa) alınır; P kanalda yukarı doğru hesaplanır.

### 2.1 JFET ve D-MOSFET eğrisi için pratik noktalar

Eğriyi Shockley denklemiyle her nokta için hesaplamak mümkündür:

$$I_D = I_{DSS}\left(1-\frac{V_{GS}}{V_P}\right)^2$$

Ama hoca sınav için pratik yolu önerir. Şu dört nokta eğriyi çizmeye yeter (ekrandan, 00:20:00):

| $V_{GS}$ | $I_D$ |
|---|---|
| $V_P$ | $0$ |
| $V_P/2$ | $I_{DSS}/4$ |
| $0{,}3\,V_P$ | $I_{DSS}/2$ |
| $0$ | $I_{DSS}$ |

D-MOSFET'te eğrinin pozitif bölgedeki gidişini görmek için bir dış nokta daha gerekir; bunun için Shockley denkleminde pozitif bir $V_{GS}$ değeri (örneğin $+1$ ya da $+2$ V) yerine konur.

### 2.2 E-MOSFET eğrisi

E-MOSFET için denklem şudur:

$$I_D = k\,(V_{GS}-V_{GS(Th)})^2$$

$k$ verilmişse doğrudan kullanılır. Verilmemişse verilen bir çalışma noktasından ($I_{D(on)}$, $V_{GS(on)}$) denklem ters çevrilerek bulunur:

$$k = \frac{I_{D(on)}}{(V_{GS(on)}-V_{GS(Th)})^2}$$

Sonra eşikten büyük birkaç $V_{GS}$ değeri yerine konup noktalar bulunur ve eğri bu noktalardan geçirilir.

## 3. Öz kutuplamalı N kanal D-MOSFET

### 3.1 Soru

Devre (ekrandan, 00:10:00):

- $V_{DD}=20$ V, savak direnci $R_D=6{,}2$ kΩ, kaynak direnci $R_S=2{,}4$ kΩ.
- Kapı, 1 MΩ'luk dirençle toprağa bağlıdır; giriş $V_i$ bir kondansatörle kapıya, çıkış $V_o$ bir kondansatörle savağa bağlanır.
- Transistör: N kanal D-MOSFET, $I_{DSS}=8$ mA, $V_P=-8$ V.
- İstenen: (a) $I_{D_Q}$ ve $V_{GS_Q}$, (b) $V_D$.

Hoca önce türü belirler: sembolde ok kanala doğru işaret ettiği için N kanaldır; kanal sürekli çizildiği için kanal ayarlamalıdır.

### 3.2 Kutuplama doğrusu

Burada gerilim bölücü yoktur. Kapıdan akım akmadığı için 1 MΩ'luk dirençten de akım akmaz; bu direnç yalnız giriş için kullanılır ve üzerinde gerilim düşmez. Bu yüzden $V_G=0$ V'tur. Kaynakta $V_S=I_SR_S=I_DR_S$ olduğundan:

$$V_{GS}=V_G-V_S=-I_DR_S=-I_D\,(2{,}4\ \text{k}\Omega)$$

Bu doğru orijinden geçer: $V_{GS}=0$ verilirse $I_D=0$ çıkar, $I_D=0$ verilirse yine $V_{GS}=0$ çıkar. Eksen kesişimleri tek bir nokta verdiği için ikinci bir nokta gerekir. Hoca keyfi olarak $V_{GS}=-6$ V seçer (ekrandan, 00:25:00):

$$I_D=-\frac{V_{GS}}{R_S}=-\frac{-6\ \text{V}}{2{,}4\ \text{k}\Omega}=2{,}5\ \text{mA}$$

Hoca $-8$ V'un da seçilebileceğini gösterir: $8/2{,}4=3{,}33$ mA. Hangisi seçilirse seçilsin aynı doğru elde edilir.

### 3.3 Transfer eğrisi

Pratik noktalar (ekrandan, 00:20:00):

- $V_{GS}=V_P=-8$ V'ta $I_D=0$.
- $V_{GS}=0{,}3V_P=-2{,}4$ V'ta $I_D=I_{DSS}/2=4$ mA.
- $V_{GS}=V_P/2=-4$ V'ta $I_D=I_{DSS}/4=2$ mA.
- $V_{GS}=0$'da $I_D=I_{DSS}=8$ mA.
- Dış nokta (kanal ayarlamalı olduğu için): $V_{GS}=+2$ V konarak

$$I_D=8\ \text{mA}\left(1-\frac{+2\ \text{V}}{-8\ \text{V}}\right)^2=8\ \text{mA}\,(1{,}25)^2=12{,}5\ \text{mA}$$

### 3.4 Çalışma noktası ve $V_D$

Doğru ile eğrinin kesişiminden kitap çözümü $I_{D_Q}=1{,}7$ mA ve $V_{GS_Q}=-4{,}3$ V verir (ekrandan, 00:25:00). Hoca grafikten okurken $1{,}7$-$1{,}8$ mA ve $-4{,}1$ ile $-4{,}2$ V arası değerlerin de kabul edilebileceğini söyler; grafik çözüm yaklaşıktır.

(b) Savak gerilimi:

$$V_D=V_{DD}-I_DR_D=20\ \text{V}-(1{,}7\ \text{mA})(6{,}2\ \text{k}\Omega)=9{,}46\ \text{V}$$

> **Ders sonrası not:** Denklemlerin analitik çözümü (python ile kontrol edildi) $V_{GS_Q}\approx-4{,}24$ V, $I_{D_Q}\approx1{,}77$ mA verir; bu, grafik okumayla uyumludur. Bu akımla $V_D\approx9{,}05$ V olur. Kitaptaki $9{,}46$ V, grafikten okunan $1{,}7$ mA ile hesaplanmıştır. Hoca bir yerde sonucu sözlü olarak "$V_{DD}$" diye andı; bulunan değer $V_D$'dir.

> **Hocanın vurgusu:** $V_{GS_Q}$'nun eksi oluşu, mA ve µA gibi birimler unutulmamalı. İşaret ya da birim hatası yapılırsa işlemler yanlış olur ve puan kaybedilir.

### 3.5 Soru-cevap

**Soru:** Kesişim noktasını nasıl bulduk?

**Cevap:** Önce verilen $I_{DSS}$ ve $V_P$ ile transistörün eğrisi çizildi. Sonra devreden $V_{GS}$ ile $I_D$ arasındaki doğru denklemi yazıldı: $V_G=0$, $V_S=I_DR_S$ olduğundan $V_{GS}=-I_DR_S$. Bu doğruda $V_{GS}=0$ ya da $I_D=0$ vermek yalnız orijini verir. Bu yüzden eğrinin dışında bir değer ($-6$ ya da $-8$ V) verilip ikinci nokta bulunur ($2{,}5$ ya da $3{,}33$ mA). İki nokta birleştirilince doğru çizilir; doğrunun eğriyi kestiği yer çalışma akımı ve gerilimidir.

## 4. Kapısı toprağa bağlı D-MOSFET

N kanal kanal ayarlamalı bir yapıda $I_{DSS}=10$ mA, $V_P=-1$ V verilmiştir. Kapı doğrudan toprağa, kaynak da doğrudan toprağa bağlıdır; $V_{DD}=20$ V, $R_D=1{,}5$ kΩ'dur. $V_{DS}$ istenir. <!-- BELİRSİZ: bu örneğin kare görüntüsü yok; devre ve değerler altyazıdan kuruldu. -->

Kapı toprağa bağlı olduğu için $V_{GS}=0$'dır. Eğri $V_{GS}=0$'da $I_D$ eksenini $I_{DSS}$'de kestiği için çalışma noktası doğrudan bellidir:

$$V_{GS_Q}=0\ \text{V},\qquad I_{D_Q}=I_{DSS}=10\ \text{mA}$$

Kaynak toprakta olduğundan $V_S=0$ ve:

$$V_{DS}=V_D-V_S=V_{DD}-I_DR_D=20\ \text{V}-(10\ \text{mA})(1{,}5\ \text{k}\Omega)=5\ \text{V}$$

Hoca bunun basit bir soru olduğunu, $V_{GS}$ ekseni üzerinden sabit bir gerilim uygulandığını belirtir.

## 5. Geri beslemeli E-MOSFET

### 5.1 Soru

N kanal kanal oluşturmalı bir yapı verilmiştir: $V_{DD}=12$ V, $R_D=2$ kΩ, kapı ile savak arasında büyük bir direnç vardır (hoca 10 MΩ der). Transistör için $I_{D(on)}=6$ mA, $V_{GS(on)}=8$ V, $V_{GS(Th)}=3$ V verilmiştir. $I_{D_Q}$ ve $V_{GS_Q}$ istenir. <!-- BELİRSİZ: devre şeması karede görünmüyor; bağlantılar altyazıdan ve ekrandaki çözüm sayfasından (ekrandan, 00:30:00) kuruldu. -->

### 5.2 Transfer eğrisi

Önce $k$ bulunur:

$$k=\frac{I_{D(on)}}{(V_{GS(on)}-V_{GS(Th)})^2}=\frac{6\ \text{mA}}{(8-3)^2}=0{,}24\times10^{-3}\ \text{A/V}^2$$

Eğri $V_{GS(Th)}=3$ V'tan başlar. Noktalar (ekrandan, 00:30:00):

- $V_{GS}=6$ V: $I_D=0{,}24\times10^{-3}(6-3)^2=0{,}24\times10^{-3}(9)=2{,}16$ mA.
- $V_{GS}=8$ V: $I_D=I_{D(on)}=6$ mA (verilen nokta).
- $V_{GS}=10$ V: $I_D=0{,}24\times10^{-3}(10-3)^2=0{,}24\times10^{-3}(49)=11{,}76$ mA.

Bu dört nokta ($3$, $6$, $8$, $10$ V) eğriyi çizmek için yeterlidir.

### 5.3 Kutuplama doğrusu

Kaynak topraktadır, yani $V_S=0$ ve $V_{GS}=V_G$. Kapı direncinden akım akmadığı için direncin iki ucu aynı gerilimdedir: $V_G=V_D$. Savak gerilimi ise $V_D=V_{DD}-I_DR_D$'dir. Buradan (ekrandan, 00:30:00):

$$V_{GS}=V_{DD}-I_DR_D=12\ \text{V}-I_D\,(2\ \text{k}\Omega)$$

Eksen kesişimleri:

- $I_D=0$ iken $V_{GS}=V_{DD}=12$ V.
- $V_{GS}=0$ iken $I_D=\frac{V_{DD}}{R_D}=\frac{12\ \text{V}}{2\ \text{k}\Omega}=6$ mA.

### 5.4 Çalışma noktası

Doğru ile eğrinin kesişiminden hoca yaklaşık $V_{GS_Q}\approx6{,}5$ V ve $I_{D_Q}\approx2{,}8$ mA okur.

> **Ders sonrası not:** Analitik çözüm (python ile kontrol edildi) $V_{GS_Q}\approx6{,}41$ V, $I_{D_Q}\approx2{,}79$ mA verir; hocanın grafik okumasıyla uyumludur.

> **Hocanın vurgusu:** Sınavda kesişimi doğru okuyabilmek için eksen aralıkları eşit ve tutarlı çizilmeli, doğru tam doğru noktalardan geçirilmelidir.

## 6. Gerilim bölücülü E-MOSFET

### 6.1 Soru

Devre (ekrandan, 00:35:00):

- $V_{DD}=40$ V; kapı bölücüsü üstte $R_1=22$ MΩ, altta $R_2=18$ MΩ.
- $R_D=3$ kΩ, $R_S=0{,}82$ kΩ.
- Transistör (2N4351): $V_{GS(Th)}=5$ V, $I_{D(on)}=3$ mA, $V_{GS(on)}=10$ V.
- İstenen: $I_{D_Q}$, $V_{GS_Q}$ ve $V_{DS}$.

### 6.2 Kutuplama doğrusu

Önce $V_G$ bulunur:

$$V_G=\frac{R_2V_{DD}}{R_1+R_2}=\frac{(18\ \text{M}\Omega)(40\ \text{V})}{22\ \text{M}\Omega+18\ \text{M}\Omega}=18\ \text{V}$$

FET'te $I_S=I_D$ olduğundan:

$$V_{GS}=V_G-I_DR_S=18\ \text{V}-I_D\,(0{,}82\ \text{k}\Omega)$$

- $I_D=0$ iken $V_{GS}=18$ V.
- $V_{GS}=0$ iken $I_D=\frac{18\ \text{V}}{0{,}82\ \text{k}\Omega}=21{,}95$ mA.

### 6.3 Transfer eğrisi

$k$ verilmediği için verilen nokta kullanılır:

$$k=\frac{3\ \text{mA}}{(10-5)^2}=0{,}12\times10^{-3}\ \text{A/V}^2,\qquad I_D=0{,}12\times10^{-3}(V_{GS}-5)^2$$

Eğri $5$ V'tan başlar ve $(10\ \text{V},3\ \text{mA})$ noktasından geçer. Bu iki nokta yalnız gidişatı gösterir; eğrinin doğruyu keseceği bölgeyi görmek için hoca $15$ ve $20$ V gibi daha büyük değerlerin de denklemde yerine konmasını önerir.

### 6.4 Çalışma noktası ve $V_{DS}$

Kesişimden (ekrandan, 00:40:00):

$$I_{D_Q}=6{,}7\ \text{mA},\qquad V_{GS_Q}=12{,}5\ \text{V}$$

Savak-kaynak gerilimi için normalde $V_{DS}=V_{DD}-I_DR_D-I_SR_S$ yazılır; $I_S=I_D$ olduğundan tek parantezde toplanır:

$$V_{DS}=V_{DD}-I_D(R_S+R_D)=40\ \text{V}-(6{,}7\ \text{mA})(0{,}82\ \text{k}\Omega+3{,}0\ \text{k}\Omega)=40\ \text{V}-25{,}6\ \text{V}=14{,}4\ \text{V}$$

> **Ders sonrası not:** Analitik çözüm (python ile kontrol edildi) $V_{GS_Q}\approx12{,}49$ V, $I_{D_Q}\approx6{,}72$ mA verir; kitap değerleriyle uyumludur.

## 7. Kutuplama türlerinin özet tablosu

Hoca kitaptaki "FET Bias Configurations" tablosunu gösterir (ekrandan, 00:40:00). Tabloda her kutuplama türü için devre, ilgili denklemler ve grafik çözüm yan yana verilmiştir. Ekranda görünen satırlar:

| Tür | İlgili denklemler |
|---|---|
| JFET sabit kutuplama | $V_{GS_Q}=-V_{GG}$, $V_{DS}=V_{DD}-I_DR_S$ (tabloda yazıldığı gibi) |
| JFET öz kutuplama | $V_{GS}=-I_DR_S$, $V_{DS}=V_{DD}-I_D(R_D+R_S)$ |
| JFET gerilim bölücü | $V_G=\frac{R_2V_{DD}}{R_1+R_2}$, $V_{GS}=V_G-I_DR_S$, $V_{DS}=V_{DD}-I_D(R_D+R_S)$ |
| JFET ortak kapı | $V_{GS}=V_{SS}-I_DR_S$ |

Hoca tablonun devamında kanal ayarlamalı MOSFET (sabit ve gerilim bölücülü) ile kanal oluşturmalı MOSFET (geri beslemeli ve gerilim bölücülü) satırlarının da bulunduğunu söyler. <!-- BELİRSİZ: tablonun alt satırları karede görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** Sabit kutuplamalı JFET'te $R_S$ yoktur, kaynak topraktadır; bu yüzden savak-kaynak gerilimi büyük olasılıkla $V_{DS}=V_{DD}-I_DR_D$ biçimindedir. Tablodaki $R_S$ harfi kaynak görüntüsündeki bir dizgi farkı olabilir.

> **Hocanın vurgusu:** Tablodaki bütün yapılar N kanal içindir. P kanalda yönler ve işaretler tam tersine çevrilerek kullanılmalıdır.

## 8. JFET ve BJT'nin birlikte olduğu devre

### 8.1 Soru

Bu soruda iki konu birleşir: devrede hem bir BJT hem de bir N kanal JFET vardır (ekrandan, 00:45:00). Bilinen değerler:

- Besleme $16$ V; BJT'nin beyzi $470$ kΩ'luk dirençle beslemeye bağlıdır; $\beta=80$.
- BJT'nin emetörü JFET'in savağına bağlıdır; iki transistör aynı ana kol üzerindedir.
- JFET öz kutuplamalıdır, $R_S=2{,}4$ kΩ; eğri grafiğinden $I_{DSS}=8$ mA ve $V_P=-4$ V okunur.
- İstenen: iki transistörün birleştiği orta noktanın gerilimi ($V_D$).

<!-- BELİRSİZ: devre şemasının tamamı karede görünmüyor; bağlantılar altyazıdan ve ekrandaki çözüm sayfasından kuruldu. -->

### 8.2 Çözüm

Hoca ilk olarak ana koldan geçen akımların yaklaşık eşit olduğunu belirtir:

$$I_E\cong I_C=I_D=I_S$$

Bu devrede doğrudan bir gerilim ya da akım bulmanın açık bir yolu yoktur. Bu yüzden öz kutuplamalı JFET'ten başlanır. $V_G=0$ olduğundan:

$$V_{GS}=-I_DR_S=-I_D\,(2{,}4\ \text{k}\Omega)$$

Doğru orijinden geçer. İkinci nokta için hoca $V_{GS}=V_P=-4$ V koyar: $I_D=4/2{,}4=1{,}67$ mA (ekrandan, 00:45:00). Başka bir değer ($-6$ V gibi) de seçilebilir, sonuç aynı doğrudur. Eğri ile doğrunun kesişiminden:

$$V_{GS_Q}=-2{,}6\ \text{V},\qquad I_{D_Q}=1\ \text{mA}$$

Hoca grafikten $-2{,}5$ V okumanın da kabul edilebileceğini söyler.

BJT tarafında $I_C\approx I_D=1$ mA'dir. Beyz akımı:

$$I_B=\frac{I_C}{\beta}=\frac{1\ \text{mA}}{80}=12{,}5\ \mu\text{A}$$

> **Ders sonrası not:** Hoca bu değeri sözlü olarak "12,5 mA" dedi; doğrusu ekrandaki gibi $12{,}5$ µA'dir. Benzer biçimde $V_{GS_Q}$ için sözlü "2,5 ohm" dedi; kastedilen $-2{,}5$ V civarıdır.

Beyz gerilimi, beslemeden $470$ kΩ üzerinde düşen gerilim çıkarılarak bulunur:

$$V_B=16\ \text{V}-I_B(470\ \text{k}\Omega)=16\ \text{V}-(12{,}5\ \mu\text{A})(470\ \text{k}\Omega)=16\ \text{V}-5{,}875\ \text{V}=10{,}125\ \text{V}$$

$V_{BE}=0{,}7$ V sabittir ve emetör aynı noktada JFET'in savağına bağlı olduğu için $V_E=V_D$'dir:

$$V_E=V_D=V_B-V_{BE}=10{,}125\ \text{V}-0{,}7\ \text{V}=9{,}425\ \text{V}$$

> **Ders sonrası not:** Analitik çözüm (python ile kontrol edildi) $V_{GS_Q}\approx-2{,}54$ V, $I_{D_Q}\approx1{,}06$ mA verir; grafik okumayla uyumludur.

## 9. Tasarım örneği: gerilim bölücülü JFET'te $R_S$

### 9.1 Soru

Bu örnekte çalışma noktası verilir, bir direnç değeri istenir (ekrandan, 00:50:00):

- $V_{DD}=16$ V; bölücü üstte $91$ kΩ, altta $47$ kΩ; $R_D=1{,}8$ kΩ.
- $V_D=12$ V ve $V_{GS_Q}=-2$ V verilmiştir.
- İstenen: $R_S$.

### 9.2 Çözüm

Standart çözüme devam edilir; önce $V_G$:

$$V_G=\frac{47\ \text{k}\Omega\,(16\ \text{V})}{47\ \text{k}\Omega+91\ \text{k}\Omega}=5{,}44\ \text{V}$$

$R_D$'nin iki ucundaki gerilimler bilindiği için savak akımı doğrudan bulunur:

$$I_D=\frac{V_{DD}-V_D}{R_D}=\frac{16\ \text{V}-12\ \text{V}}{1{,}8\ \text{k}\Omega}=2{,}22\ \text{mA}$$

Bilinenler $V_{GS}$ denkleminde yerine konur:

$$V_{GS}=V_G-I_DR_S\ \Rightarrow\ -2\ \text{V}=5{,}44\ \text{V}-(2{,}22\ \text{mA})R_S$$

$$R_S=\frac{7{,}44\ \text{V}}{2{,}22\ \text{mA}}=3{,}35\ \text{k}\Omega$$

Kitap en yakın standart ticari değerin $3{,}3$ kΩ olduğunu da not eder (ekrandan, 00:50:00).

## 10. Tasarım örneği: geri beslemeli E-MOSFET'te $V_{DD}$ ve $R_D$

Bu örnekte kanal oluşturmalı MOSFET kapı-savak arası dirençle geri beslemelidir. Kapı akımı sıfır olduğu için kapı direncinden akım akmaz; kapı noktası savak noktasıyla aynı gerilimdedir ($V_G=V_D$, $V_{GS}=V_{DS}$). Soruda $V_{DS}=V_{DD}/2$ şartı verilmiş, yani $R_D$ üzerinde düşen gerilim $V_{DS}$'ye eşittir. $V_{DD}$ ve $R_D$ istenir. <!-- BELİRSİZ: bu örneğin kare görüntüsü yok; devre ve değerler altyazıdan kuruldu. -->

Verilen çalışma noktasında $V_{GS(on)}=6$ V olduğundan $V_{DS}=V_{GS}=6$ V'tur. $V_{DS}=V_{DD}/2$ şartından:

$$V_{DD}=2V_{DS}=12\ \text{V}$$

$R_D$ üzerinde de $6$ V düşer ve akım $I_{D(on)}=4$ mA'dir:

$$R_D=\frac{V_{DD}-V_{DS}}{I_{D(on)}}=\frac{6\ \text{V}}{4\ \text{mA}}=1{,}5\ \text{k}\Omega$$

> **Ders sonrası not:** Hoca bu örneği anlatırken önce $V_{GS}$'yi "0 volt" dedi, hemen "6 volt verilmiş" diye düzeltti. Ayrıca bir yerde "burası 16 volt, burası 12 volt" dedi; bu ifade büyük olasılıkla önceki örnekten kalmıştır, bu soruda $V_{DD}=12$ V'tur.

Hoca bu örnekle sorularda yalnız çalışma noktasının değil, direnç ya da besleme değerlerinin de istenebileceğini gösterir.

## 11. Gerilim bölücülü P kanal JFET

### 11.1 Soru

Bu soruda P kanal JFET verilmiştir (ekrandan, 00:55:00):

- Besleme $-20$ V; kapı bölücüsü $68$ kΩ ve $20$ kΩ; $R_D=2{,}7$ kΩ, $R_S=1{,}8$ kΩ.
- $I_{DSS}=8$ mA, $V_P=+4$ V.
- İstenen: $I_{D_Q}$, $V_{GS_Q}$ ve $V_{DS}$.

Hoca P kanal JFET görünce eğrinin tersine döndüğünü hatırlatır: eğri pozitif $V_P$'den ($4$ V) başlar ve $V_{GS}=0$'da $I_{DSS}$'ye çıkar. Akım artık yukarı doğru (kaynaktan savağa) akar; hesaplarda bu yön dikkate alınmalıdır.

### 11.2 Kutuplama doğrusu

$$V_G=\frac{20\ \text{k}\Omega\,(-20\ \text{V})}{20\ \text{k}\Omega+68\ \text{k}\Omega}=-4{,}55\ \text{V}$$

Kirchhoff gerilim yasası, akım yönü ters olduğu için şöyle yazılır (ekrandan, 00:55:00):

$$V_G-V_{GS}+I_DR_S=0\ \Rightarrow\ V_{GS}=V_G+I_DR_S$$

Hoca bunu "eksiler birbirini götürür" diye açıklar: $V_S$ yazılırken $1{,}8$ kΩ üzerindeki gerilimin işareti terstir.

- $I_D=0$ iken $V_{GS}=V_G=-4{,}55$ V.
- $V_{GS}=0$ iken $I_D=-\frac{V_G}{R_S}=-\frac{-4{,}55\ \text{V}}{1{,}8\ \text{k}\Omega}=2{,}53$ mA.

### 11.3 Transfer eğrisi

Pratik noktalar P kanalda işaretleri ters olarak kullanılır:

- $V_{GS}=V_P=4$ V'ta $I_D=0$.
- $V_{GS}=V_P/2=2$ V'ta $I_D=I_{DSS}/4=2$ mA.
- $V_{GS}=0{,}3V_P=1{,}2$ V'ta $I_D=I_{DSS}/2=4$ mA.
- $V_{GS}=0$'da $I_D=8$ mA.

### 11.4 Çalışma noktası ve $V_{DS}$

Kesişimden (ekrandan, 00:55:00):

$$I_{D_Q}=3{,}4\ \text{mA},\qquad V_{GS_Q}=1{,}4\ \text{V}$$

Savak-kaynak gerilimi için Kirchhoff yasası:

$$-I_DR_S+V_{DS}-I_DR_D+V_{DD}=0$$

$$V_{DS}=-V_{DD}+I_D(R_D+R_S)=-20\ \text{V}+(3{,}4\ \text{mA})(2{,}7\ \text{k}\Omega+1{,}8\ \text{k}\Omega)=-20\ \text{V}+15{,}3\ \text{V}=-4{,}7\ \text{V}$$

Hoca ters yönde gidildiği için $I_D$ teriminin eksi değil artı olarak yazıldığını vurgular.

> **Ders sonrası not:** Hoca sonucu sözlü olarak "4,7 ohm" dedi; doğrusu $V_{DS}=-4{,}7$ V'tur. Analitik çözüm (python ile kontrol edildi) $V_{GS_Q}\approx1{,}42$ V, $I_{D_Q}\approx3{,}32$ mA verir; grafik okumayla uyumludur.

> **Hocanın vurgusu:** Hangi bölgede (N ya da P kanal, pozitif ya da negatif $V_{GS}$) çalışıldığına dikkat edilmeli ki $I_{D_Q}$ ve $V_{GS_Q}$ doğru işaretlerle verilsin.

## Örnek Sorular

Aşağıdaki sorular derste ekranda gösterilen ve çözülen kitap örnekleridir. Ayrıntılı çözümler yukarıdaki bölümlerdedir.

**Soru 1** (ekrandan, 00:10:00): $V_{DD}=20$ V, $R_D=6{,}2$ kΩ, $R_S=2{,}4$ kΩ, kapı 1 MΩ ile toprağa bağlı, $I_{DSS}=8$ mA, $V_P=-8$ V olan öz kutuplamalı N kanal D-MOSFET devresinde (a) $I_{D_Q}$ ve $V_{GS_Q}$, (b) $V_D$ değerlerini bulun.

> **Çözüm:** $V_{GS}=-I_D(2{,}4\ \text{k}\Omega)$; $V_{GS}=-6$ V'ta $I_D=2{,}5$ mA. Eğri $(-8,0)$, $(-4,2)$, $(-2{,}4,4)$, $(0,8)$, $(+2,12{,}5)$ noktalarından çizilir. $I_{D_Q}=1{,}7$ mA, $V_{GS_Q}=-4{,}3$ V; $V_D=20-(1{,}7)(6{,}2)=9{,}46$ V. (Bölüm 3)

**Soru 2** (derste sözlü, 00:25:39): Kapısı ve kaynağı toprağa bağlı, $I_{DSS}=10$ mA, $V_P=-1$ V olan N kanal D-MOSFET'te $V_{DD}=20$ V, $R_D=1{,}5$ kΩ ise $I_{D_Q}$ ve $V_{DS}$ nedir?

> **Çözüm:** $V_{GS_Q}=0$ olduğundan $I_{D_Q}=I_{DSS}=10$ mA; $V_{DS}=20-(10)(1{,}5)=5$ V. (Bölüm 4)

**Soru 3** (ekrandan, 00:30:00): Geri beslemeli N kanal E-MOSFET'te $V_{DD}=12$ V, $R_D=2$ kΩ, $V_{GS(Th)}=3$ V, $I_{D(on)}=6$ mA, $V_{GS(on)}=8$ V ise çalışma noktasını bulun.

> **Çözüm:** $k=0{,}24\times10^{-3}$ A/V²; doğru $V_{GS}=12-2I_D$ (kesişimler $12$ V ve $6$ mA). Kesişim yaklaşık $V_{GS_Q}\approx6{,}4$ V, $I_{D_Q}\approx2{,}8$ mA. (Bölüm 5)

**Soru 4** (ekrandan, 00:35:00): $V_{DD}=40$ V, $R_1=22$ MΩ, $R_2=18$ MΩ, $R_D=3$ kΩ, $R_S=0{,}82$ kΩ, $V_{GS(Th)}=5$ V, $I_{D(on)}=3$ mA ($V_{GS(on)}=10$ V) olan gerilim bölücülü E-MOSFET devresinde $I_{D_Q}$, $V_{GS_Q}$ ve $V_{DS}$ değerlerini bulun.

> **Çözüm:** $V_G=18$ V, $V_{GS}=18-0{,}82I_D$; $k=0{,}12\times10^{-3}$ A/V². $I_{D_Q}=6{,}7$ mA, $V_{GS_Q}=12{,}5$ V, $V_{DS}=40-6{,}7(3{,}82)=14{,}4$ V. (Bölüm 6)

**Soru 5** (ekrandan, 00:45:00): $16$ V beslemeli, beyz direnci $470$ kΩ, $\beta=80$ olan BJT'nin emetörü, $R_S=2{,}4$ kΩ ile öz kutuplanmış ($I_{DSS}=8$ mA, $V_P=-4$ V) N kanal JFET'in savağına bağlıdır. Orta noktanın gerilimi $V_D$'yi bulun.

> **Çözüm:** JFET'ten $I_{D_Q}=1$ mA, $V_{GS_Q}=-2{,}6$ V. $I_B=1\ \text{mA}/80=12{,}5$ µA, $V_B=16-5{,}875=10{,}125$ V, $V_D=V_E=10{,}125-0{,}7=9{,}425$ V. (Bölüm 8)

**Soru 6** (ekrandan, 00:50:00): Gerilim bölücülü JFET devresinde ($V_{DD}=16$ V, $91$ kΩ / $47$ kΩ, $R_D=1{,}8$ kΩ) $V_D=12$ V ve $V_{GS_Q}=-2$ V ise $R_S$ değerini bulun.

> **Çözüm:** $V_G=5{,}44$ V, $I_D=2{,}22$ mA, $R_S=7{,}44/2{,}22=3{,}35$ kΩ. (Bölüm 9)

**Soru 7** (derste sözlü, 00:50:30): Geri beslemeli E-MOSFET'te $V_{GS(on)}=6$ V, $I_{D(on)}=4$ mA ve $V_{DS}=V_{DD}/2$ isteniyorsa $V_{DD}$ ve $R_D$ ne olmalıdır? <!-- BELİRSİZ: soru metni ekranda görülmedi, altyazıdan kuruldu. -->

> **Çözüm:** $V_{DS}=V_{GS}=6$ V, $V_{DD}=12$ V, $R_D=6\ \text{V}/4\ \text{mA}=1{,}5$ kΩ. (Bölüm 10)

**Soru 8** (ekrandan, 00:55:00): $-20$ V beslemeli, $68$ kΩ / $20$ kΩ bölücülü, $R_D=2{,}7$ kΩ, $R_S=1{,}8$ kΩ, $I_{DSS}=8$ mA, $V_P=4$ V olan P kanal JFET devresinde $I_{D_Q}$, $V_{GS_Q}$ ve $V_{DS}$ değerlerini bulun.

> **Çözüm:** $V_G=-4{,}55$ V, $V_{GS}=V_G+1{,}8I_D$ (kesişimler $-4{,}55$ V ve $2{,}53$ mA). $I_{D_Q}=3{,}4$ mA, $V_{GS_Q}=1{,}4$ V, $V_{DS}=-20+3{,}4(4{,}5)=-4{,}7$ V. (Bölüm 11)

## Dersin Toparlaması

Bu derste FET kutuplama konusu tamamen soru çözümüyle pekiştirildi. Bütün örneklerin ortak iskeleti aynıdır: transistörün kendi transfer eğrisi verilen parametrelerden çizilir (JFET ve D-MOSFET için $I_{DSS}$ ile $V_P$, E-MOSFET için $k$ ile $V_{GS(Th)}$), devreden $V_{GS}$-$I_D$ doğru denklemi yazılır ve ikisinin kesişimi çalışma noktasını verir. Kutuplama türü yalnız doğru denklemini değiştirir: öz kutuplamada $V_{GS}=-I_DR_S$, gerilim bölücüde $V_{GS}=V_G-I_DR_S$, geri beslemeli E-MOSFET'te $V_{GS}=V_{DD}-I_DR_D$, kapısı toprağa bağlı yapıda $V_{GS}=0$. Çalışma noktası bulunduktan sonra $V_D$, $V_{DS}$ gibi diğer büyüklükler Kirchhoff yasasıyla hesaplanır; tasarım sorularında ise aynı denklemler bilinmeyen direnç ya da besleme için çözülür.

Hoca sorular birbirine çok benzediği için birkaç soru kendi başına çözüldükten sonra genel mantığın oturacağını, ama izlerken kolay görünen ayrıntıların (işaretler, birimler, P kanalda akım yönü) tek başına çözerken kaçabileceğini vurgular.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
