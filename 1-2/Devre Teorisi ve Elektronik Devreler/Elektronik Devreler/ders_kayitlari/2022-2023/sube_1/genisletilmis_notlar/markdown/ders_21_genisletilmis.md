# Ders 21 Genişletilmiş Notu: FET Kutuplama Devreleri ve Transfer Eğrisi Çizimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. FET türlerinin tekrarı
- 2. Karakteristikler ve temel denklemler
- 3. FET kutuplama devreleri
- 4. JFET kutuplama yapıları
- 5. D-MOSFET kutuplaması
- 6. E-MOSFET kutuplaması
- 7. Transfer eğrisinin çizimi
- 8. JFET ile BJT karşılaştırması
- 9. Çözümlü sorular
- Örnek Sorular
- Dersin Toparlaması

## 1. FET türlerinin tekrarı

Ders, önceki haftada başlanan FET'lerin kısa bir tekrarıyla açılır. FET'ler iki ana gruba ayrılır: JFET'ler (jonksiyon FET) ve MOSFET'ler (metal oksit yarı iletken FET). Her iki grup da kendi içinde N kanallı ve P kanallı olarak ikiye ayrılır.

MOSFET'ler de iki ayrı yapıdadır:

- **D-MOSFET** (depletion-type), Türkçe adıyla **kanal ayarlamalı** MOSFET.
- **E-MOSFET** (enhancement-type), Türkçe adıyla **kanal oluşturmalı** MOSFET.

Hocanın ekrana çizdiği şemada FET; JFET ve MOSFET dallarına, MOSFET de D-MOSFET (kanal ayarlamalı) ve E-MOSFET (kanal oluşturmalı) dallarına ayrılır; her birinin altında n ve p tipleri yer alır (ekrandan, 00:10:00). JFET ile D-MOSFET'in karakteristikleri birbirine çok benzer, aynı formülü kullanır. E-MOSFET ise ayrı bir yapı olarak değerlendirilmelidir.

Sembollerde okun yönü kanalı gösterir. Ok içeri doğruysa kanal N tipidir. Derste ele alınan bütün örnekler N kanallıdır; P kanallı elemanlarda karakteristikler N kanallıların aynalanmış hâli olarak çizilir.

## 2. Karakteristikler ve temel denklemler

### 2.1 Gerilim kontrollü eleman

FET'lerin en önemli özelliği gerilim kontrollü olmalarıdır. Ana parametre gate-source gerilimi $V_{GS}$'dir. Daha önce görülen BJT'ler ise akım kontrollüdür; kollektör akımı baz akımı $I_B$ ile kontrol edilir.

FET'lerde gate'ten akım akmaz ($I_G = 0$). BJT'de baz akımı küçük de olsa akıyordu; FET'te gate kolundan akım geçmez. Ayrıca drain akımı source akımına **tam olarak** eşittir: $I_D = I_S$. BJT'de bu ilişki yalnız yaklaşık olarak geçerliydi ($I_C \cong I_E$).

### 2.2 JFET

N kanallı bir JFET'i bir silindir gibi düşünüp ortadan kesersek, ortada N tipi bir kanal ve bu kanalın etrafını kuşak gibi saran P tipi malzeme görülür. Gerilim uygulanmadığında ($V_{GS}=0$) kanal tam açıktır ve en büyük akım $I_{DSS}$ akar. $V_{GS}$ negatif yapıldıkça kanal yavaş yavaş kapanır. Sonunda, hocanın benzetmesiyle iki parmağın ucunun birleşmesi gibi kanal kapanır ve akım geçmez; bu gerilim pinch-off gerilimi $V_P$'dir. Aradaki gerilimlerde belirli $I_D$ akımları akar. Örneğin N kanallı JFET'te $V_P$ yaklaşık $-4$ V gibi negatif bir değerdir.

Transfer karakteristiği Shockley denklemiyle verilir (ekrandan, 00:05:00):

$$I_D = I_{DSS}\left(1-\frac{V_{GS}}{V_P}\right)^2$$

$I_{DSS}$ ve $V_P$ o transistöre özgü parametrelerdir. Formül bir fonksiyon gibi düşünülürse, tek değişken $V_{GS}$'dir: $V_{GS}$ bilinince $I_D$ bulunur.

> **Ders sonrası not:** Hoca eğrinin artışını "eksponansiyel" diye anlattı ve bir yerde $I_{DSS}$'den "gerilim" diye söz etti. Shockley denklemi karesel (parabolik) bir ilişkidir, $I_{DSS}$ de bir akımdır.

### 2.3 D-MOSFET (kanal ayarlamalı)

D-MOSFET, JFET ile aynı formülü kullanır ve negatif bölgedeki karakteristikleri aynıdır. Fark, kanalın boyutunu büyütme imkânı olmasıdır: $V_{GS}$ pozitif değerlere geçtiğinde akım $I_{DSS}$'yi aşarak artmaya devam eder (ekrandan, 00:10:00). Slaytta da D-MOSFET'in pozitif $V_{GS}$ ile ve $I_{DSS}$'yi aşan $I_D$ değerleriyle çalışabildiği, bunun dışında kutuplama devrelerinin JFET'tekilere benzediği belirtilir (ekrandan, 00:30:00).

### 2.4 E-MOSFET (kanal oluşturmalı)

N kanallı E-MOSFET'te başlangıçta kanal yoktur. Gate ile yarı iletken arasında yalıtkan (izole) bir tabaka vardır. Gate'e pozitif bir $V_{GS}$ verildiğinde N tipi bir tabaka, yani kanal, oluşmaya başlar. Kanalın ilk oluştuğu gerilim eşik gerilimi $V_{GS(Th)}$'dir. Bu gerilimin altında $I_D=0$'dır; eşik aşıldıktan sonra pozitif gerilim arttıkça kanal büyür ve akım hızla artar. Karakteristiği diğerlerinden farklıdır, yine sağa doğru yönelir (ekrandan, 00:35:00):

$$I_D = k\,(V_{GS}-V_{GS(Th)})^2, \qquad k = \frac{I_{D(on)}}{(V_{GS(on)}-V_{GS(Th)})^2}$$

Burada $k$ ve $V_{GS(Th)}$ transistöre özgü parametrelerdir.

### 2.5 P kanallı elemanlar

P kanallı JFET ve D-MOSFET'te $V_P$ pozitif olur ve eğri pozitif $V_{GS}$ tarafında oluşur. P kanallı E-MOSFET'te karakteristik negatif $V_{GS}$ tarafında, sola doğru oluşur. Kısacası P kanallı grafikler N kanallıların aynalanmış çizimleridir.

## 3. FET kutuplama devreleri

Slaytta incelenecek kutuplama devreleri şöyle sıralanır (ekrandan, 00:15:00):

| Eleman | Kutuplama yapıları |
|---|---|
| JFET | Sabit kutuplama (fixed bias), kendinden kutuplama (self-bias), gerilim bölücülü kutuplama |
| D-MOSFET (kanal ayarlamalı) | Kendinden kutuplama, gerilim bölücülü kutuplama |
| E-MOSFET (kanal oluşturmalı) | Geri beslemeli yapı (feedback configuration), gerilim bölücülü kutuplama |

Bütün FET tiplerinde çözümün temel varsayımları aynıdır: gate akımı sıfır (sıfıra çok yakın) kabul edilir ve drain ile source akımları birbirine eşittir. JFET ve D-MOSFET'te Shockley denklemi, E-MOSFET'te $k$'lı denklem kullanılır.

Temel çözüm fikri şudur: devrenin yapısından $V_{GS}$ ile $I_D$ arasında **doğrusal** bir denklem çıkarılır. Bu doğru, elemanın transfer eğrisiyle kesiştirilir. Kesişim noktası çalışma noktasıdır (Q noktası, quiescent point): $I_{DQ}$ ve $V_{GSQ}$. Bunlar bulunduktan sonra sorunun büyük kısmı çözülmüş olur; diğer gerilimler devre denklemlerinden hesaplanır.

## 4. JFET kutuplama yapıları

### 4.1 Sabit kutuplama

Sabit kutuplamalı JFET devresinde gate, ters bağlanmış bir $V_{GG}$ kaynağına bir direnç üzerinden bağlıdır. Ana kolda, BJT'lerde yapıldığı gibi, karşılaşılan gerilimler toplanır:

$$V_{DD} = I_D R_D + V_{DS}$$

Gate direncinden akım akmadığı için üzerinde gerilim düşmez ve $V_{GS}$ doğrudan ters bağlı kaynağın gerilimine eşittir: $V_{GS} = -V_{GG}$.

### 4.2 Kendinden kutuplama

Kendinden kutuplamada source ile toprak arasında $R_S$ direnci vardır. Ana koldan gidildiğinde (ekrandan, 00:20:00):

$$V_{DD} = I_D R_D + V_{DS} + I_S R_S$$

$R_S$ üzerine düşen $I_S R_S$ gerilimi hiçbir zaman unutulmamalıdır; $I_D = I_S$ olduğu da hatırlanır. Slayttaki sonuç denklemleri:

$$V_{DS} = V_{DD} - I_D(R_S+R_D), \qquad V_S = I_D R_S, \qquad V_D = V_{DS}+V_S = V_{DD}-V_{R_D}$$

Slayttaki çözüm adımları: $I_{DSS}$'den küçük bir $I_D$ seçilip $R_S$ ile $V_{GS}$ hesaplanır, bu nokta ile eksen başlangıcı arasına doğru çizilir; transfer eğrisi $I_{DSS}$, $V_P$ ve $I_{DSS}/4$, $I_{DSS}/2$ gibi noktalarla çizilir; Q noktası doğrunun eğriyi kestiği yerdir (ekrandan, 00:20:00).

**Soru:** $V_D$, $I_D R_D$'ye eşit olmuyor mu?
**Cevap:** Hayır. $V_D$, toprağa göre drain noktasının gerilimidir. $V_{DD}$'den $R_D$ üzerinde düşen gerilim çıkarılınca drain noktasına varılır: $V_D = V_{DD} - I_D R_D$. Aynı değer alt yoldan da bulunabilir: $V_D = V_{DS} + I_S R_S$. Örneğin $V_{DD}=20$ V ise $R_D$ üzerinde düşen gerilim çıkarılınca $V_D$ elde edilir; bu da $V_{DD} = I_D R_D + V_D$ biçiminde yazılabilir.

### 4.3 Gerilim bölücülü kutuplama

Önce gerilim bölücü hatırlatılır. Girişe $V_{in}$ verilen, iki dirençle ($R_1$, $R_2$) toprağa giden yapıda orta noktadan alınan çıkış:

$$V_{out} = \frac{R_2}{R_1+R_2}V_{in}$$

FET devresinde orta nokta gate'tir:

$$V_G = \frac{R_2}{R_1+R_2}V_{DD}$$

Gerilim, dirençlerin büyüklüğüne göre paylaşılır. $V_{DD}=20$ V iken $R_1=R_2$ ise (örneğin ikisi de 1 k) her birine 10 V düşer. $R_1 = 1{,}5$ k, $R_2 = 0{,}5$ k ise $R_1$ üzerine 15 V, $R_2$ üzerine 5 V düşer (ekrandan, 00:25:00):

$$V_G = \frac{0{,}5}{1{,}5+0{,}5}\cdot 20 = \frac{1}{4}\cdot 20 = 5\text{ V}$$

Dikkat: $V_G$, $V_{GS}$'ye eşit değildir. Gate'ten source üzerinden toprağa giden koldan gidildiğinde:

$$V_G = V_{GS} + I_S R_S \quad\Rightarrow\quad V_{GS} = V_G - I_D R_S$$

Tek harfle yazılan $V_X$ gerilimi, o noktanın toprağa göre gerilimidir. $V_G$ ayrıca $R_2 I_2$ olarak da yazılabilir.

### 4.4 Kutuplama doğrusu ve Q noktası

$V_{GS} = V_G - I_D R_S$ denkleminde $V_G$ ve $R_S$ sabittir; bu, $y = a - bx$ biçiminde ters eğimli bir doğru denklemidir. Doğrunun iki noktası kolayca bulunur:

- $V_{GS}=0$ için: $I_D = V_G/R_S$.
- $I_D=0$ için: $V_{GS} = V_G$.

Bu iki noktadan geçen doğru çizilir. Elemanın transfer eğrisiyle ($I_D = I_{DSS}(1-V_{GS}/V_P)^2$) kesiştiği nokta Q çalışma noktasıdır. Transfer eğrisini çizebilmek için $I_{DSS}$ ve $V_P$ verilmelidir.

Q noktasından sonra istenen diğer büyüklükler bulunur. Örneğin $V_{DS}$ için $V_{DD}$'den iki direnç üzerinde düşen gerilim çıkarılır: $V_{DS} = V_{DD} - I_D(R_D+R_S)$.

## 5. D-MOSFET kutuplaması

D-MOSFET kutuplama devreleri JFET'tekilerle aynı mantıkla çözülür. Slayttaki gerilim bölücülü D-MOSFET devresi (ekrandan, 00:30:00):

| Eleman | Değer |
|---|---|
| $V_{DD}$ | 18 V |
| $R_1$ (üst bölücü direnci) | 110 MΩ |
| $R_2$ (alt bölücü direnci) | 10 MΩ |
| $R_D$ | 1,8 kΩ |
| $R_S$ | 750 Ω |
| $I_{DSS}$ | 6 mA |
| $V_P$ | $-3$ V |

$$V_G = \frac{10}{10+110}\cdot 18 = \frac{18}{12} = 1{,}5\text{ V}$$

$R_2$ üzerine 1,5 V, $R_1$ üzerine kalan 16,5 V düşer. Ardından $V_G = V_{GS} + I_S\cdot 750\ \Omega$ yazılır. Önce transistörün kendi transfer eğrisi çizilir (bunun için $I_{DSS}$ ve $V_P$ verilmelidir), sonra devreden çıkan doğru çizilir, kesişimden $I_D$ bulunur. $V_{DS}$ sorulursa $V_{DS} = 18 - (1{,}8\text{ k}+750\ \Omega)\cdot I_D$ yazılır. Bu sorunun tam çözümü 9.4'tedir.

## 6. E-MOSFET kutuplaması

E-MOSFET'te de yöntem aynıdır: elemanın kendi karakteristiği çizilir, devreden çıkarılan doğrusal denklemle kesiştirilir ve $I_{DQ}$, $V_{GSQ}$ bulunur. Eğriyi çizmek için $k$ ve $V_{GS(Th)}$ verilmelidir; değişik $V_{GS}$ değerleri formüle konarak noktalar hesaplanır.

### 6.1 Geri beslemeli yapı

N kanallı E-MOSFET'li geri beslemeli yapıda drain ile gate arasında $R_G$ direnci vardır. $I_G=0$ olduğu için $R_G$'den akım akmaz ve üzerindeki gerilim sıfırdır ($V_{R_G}=0$). Bu yüzden:

- $V_D = V_G$ (iki nokta arasında gerilim düşmez).
- Source doğrudan toprağa bağlı olduğundan $V_S=0$; dolayısıyla $V_G = V_{GS}$ ve $V_D = V_{DS}$.
- $V_D = V_{DD} - I_D R_D$.

Sonuç olarak:

$$V_{GS} = V_{DD} - I_D R_D$$

Bu da $V_{DD}$ ve $R_D$ sabit olduğundan doğrusal bir denklemdir. $V_{GS}=0$ verilirse $I_D = V_{DD}/R_D$, $I_D=0$ verilirse $V_{GS} = V_{DD}$ bulunur. Doğru çizilir ve eğriyle kesişimi çalışma noktasını verir.

E-MOSFET'li gerilim bölücülü yapıda da aynı çözüm tarzı geçerlidir: önce $V_G$ bulunur, sonra $V_{GS}$ ile $I_D$ arasındaki bağıntı yazılır; istenirse $V_{DS}$ de hesaplanır.

## 7. Transfer eğrisinin çizimi

### 7.1 JFET ve D-MOSFET için kısa yol noktaları

Soru setinin başında üç elemanın özet tablosu yer alır (ekrandan, 00:40:00): N kanal JFET, N kanal ayarlamalı (D-MOSFET) ve N kanal oluşturmalı (E-MOSFET). Hepsinin eğrisi sağa doğru yükselir; P tipi olsalardı aynalanmış şekilleri çizilirdi.

JFET ve D-MOSFET'in eğrisini elle çizmek için dört kolay nokta kullanılır:

| $V_{GS}$ | $I_D$ |
|---|---|
| $V_P$ | 0 |
| $V_P/2$ | $I_{DSS}/4$ |
| $0{,}3\,V_P$ | $I_{DSS}/2$ |
| 0 | $I_{DSS}$ |

Hoca önce $I_{DSS}/2$ noktasının $V_P$'nin yaklaşık üçte biri ($0{,}33V_P$) olduğunu söyler, ardından slaytta $0{,}3V_P$ kullanıldığını belirtir. $V_P/2$ noktasında akım $I_{DSS}$'nin dörtte biridir. Bu noktalar bulununca mavi eğri bunlardan geçecek biçimde çizilir.

> **Ek bilgi (derste anlatılmadı):** Bu iki kural doğrudan Shockley denkleminden gelir. $V_{GS}=V_P/2$ konursa $I_D = I_{DSS}(1-1/2)^2 = I_{DSS}/4$ olur. $I_D = I_{DSS}/2$ için $(1-V_{GS}/V_P)^2 = 0{,}5$, yani $V_{GS} = (1-1/\sqrt2)V_P \approx 0{,}293V_P$ bulunur; $0{,}3V_P$ bunun yuvarlatılmış hâlidir.

### 7.2 D-MOSFET'in pozitif bölgesi

D-MOSFET'te eğri pozitif $V_{GS}$ bölgesine de uzanır. Bunun için pozitif bölgeden bir $V_{GS}$ değeri (örneğin $+1$ V) seçilip Shockley denklemine konur ve eğri bu noktaya kadar uzatılır. Pozitif bölgede akım çok hızlı arttığı için küçük bir pozitif değer seçmek yeterlidir.

### 7.3 E-MOSFET'in eğrisi

E-MOSFET'te $I_{DSS}/2$ ve $V_P/2$ gibi referans noktalar yoktur. Önce $k$ bulunur, sonra ana formüle değişik $V_{GS}$ değerleri konarak ara noktalar hesaplanır.

### 7.4 Ölçekli çizim

Grafik çözümler elle yapıldığı için eksenlerin aralıkları dikkatle belirlenmelidir. Örneğin $I_D$ ekseninde 10 mA işaretlenecekse önce 10 mA yeri belirlenir ve yarısı tam 5 mA'nın yerine gelmelidir. Aralıklar eşit alınmazsa çizilen doğru yanlış yerden geçer, bulunan $I_{DQ}$ ve $V_{GSQ}$ hatalı çıkar.

> **Hocanın vurgusu:** Sınavda bu tür sorularda eksen takımlarını doğru çizip eşit aralıklara bölmek çok önemlidir. Şekli küçük çizerseniz hafif bir oynamada kesişim $-3$ V yerine $-2$ V'ta görünebilir; grafiği geniş çizin.

## 8. JFET ile BJT karşılaştırması

Slaytta N tipi bir BJT ile N kanallı bir JFET yan yana karşılaştırılır (ekrandan, 00:45:00):

| JFET | BJT |
|---|---|
| $I_D = I_{DSS}\left(1-\dfrac{V_{GS}}{V_P}\right)^2$ | $I_C = \beta I_B$ |
| $I_D = I_S$ | $I_C \cong I_E$ |
| $I_G \cong 0$ A | $V_{BE} \cong 0{,}7$ V |

BJT'de baz akımı içeri girer, $V_{BE}$ 0,7 V kabul edilir ve emiterden $I_E$ çıkar. JFET'te gate akımı sıfırdır ve $I_D$ tam olarak $I_S$'ye eşittir. JFET'te çıkış akımı $I_D$, $V_{GS}$ ile $I_{DSS}$, $V_P$'ye bağlı karesel bir denklemle bulunur; BJT'de çıkış akımı $I_C$ ile baz akımı arasında $\beta$ ile doğrusal bir ilişki vardır. Genel kabuller: silisyum BJT'de $V_{BE} \cong 0{,}7$ V, JFET'te giriş (gate) akımı 0.

## 9. Çözümlü sorular

### 9.1 D-MOSFET transfer eğrisinin çizimi

**Soru (ekrandan, 00:50:00):** $I_{DSS} = 10$ mA ve $V_P = -4$ V olan N kanallı D-MOSFET'in transfer karakteristiğini çizin.

$V_P$ negatif verildiği için eleman N kanal ayarlamalı MOSFET'tir (pozitif verilseydi P kanallı olurdu). Noktalar:

- $V_{GS}=0$ V: $I_D = I_{DSS} = 10$ mA.
- $V_{GS}=V_P=-4$ V: $I_D=0$.
- $V_{GS}=V_P/2=-2$ V: $I_D = I_{DSS}/4 = 2{,}5$ mA.
- $I_D = I_{DSS}/2 = 5$ mA: $V_{GS} = 0{,}3V_P = 0{,}3(-4) = -1{,}2$ V.

Bu dört noktayla eğri $V_{GS}=0$'a kadar çizilir. Pozitif bölge için $V_{GS}=+1$ V seçilir:

$$I_D = 10\text{ mA}\left(1-\frac{+1\text{ V}}{-4\text{ V}}\right)^2 = 10\text{ mA}(1+0{,}25)^2 = 10\text{ mA}(1{,}5625) \cong 15{,}63\text{ mA}$$

Bu değer eğriyi tamamlamak için yeterince yüksektir.

**Soru:** Pozitif bölgede $V_{GS}=+4$ V verirsek akım sıfır mı olur?
**Cevap:** Hayır. $1 - \dfrac{4}{-4} = 1+1 = 2$ olur; işaret ters dönmez, akım büyümeye devam eder.

> **Ders sonrası not:** Hoca bu durumda akımın 20 mA'ya doğru gideceğini söyledi. Formülle $I_D = 10\text{ mA}\cdot(2)^2 = 40$ mA bulunur (python ile kontrol edildi).

### 9.2 E-MOSFET transfer eğrisinin çizimi

**Soru (derste sözlü, 00:50:42):** $V_{GS(Th)} = 3$ V olan N kanallı E-MOSFET'in $k$ değerini bulun ve transfer karakteristiğini çizin.

Eşik gerilimi pozitif verildiği için eleman N kanallıdır. $k$'yı bulmak için elemanın bilgi föyünden (spec) $I_{D(on)}$ ve $V_{GS(on)}$ okunur; föy slayta konmamıştır. Hocanın söylediğine göre $V_{GS(on)} = 10$ V ve $I_{D(on)} = 3$ mA'dir <!-- BELİRSİZ: bu değerler altyazıdan alındı, ilgili slayt karelerde görünmüyor -->:

$$k = \frac{I_{D(on)}}{(V_{GS(on)}-V_{GS(Th)})^2} = \frac{3\text{ mA}}{(10-3)^2} = \frac{3\text{ mA}}{49} \approx 0{,}061\text{ mA/V}^2$$

Sonra $I_D = k(V_{GS}-3)^2$ denklemine değişik $V_{GS}$ değerleri konarak ara noktalar bulunur ve eğri çizilir. Hoca örnek olarak $V_{GS}=5$ V için yaklaşık 0,22 mA okur. <!-- BELİRSİZ: hocanın okuduğu değer altyazıda "0.22"; k = 3/49 mA/V² ile hesaplanan değer 0,245 mA'dir, slayttaki değer görülemedi -->

> **Ders sonrası not:** $k = 3/49$ mA/V² ile ara noktalar (python ile hesaplandı): $V_{GS}=4$ V için 0,061 mA, 5 V için 0,245 mA, 6 V için 0,551 mA, 8 V için 1,531 mA, 10 V için 3 mA. Altyazıdaki 0,22 mA büyük olasılıkla Whisper ya da okuma hatasıdır.

### 9.3 Sabit kutuplamalı JFET

**Soru (ekrandan, 00:55:00):** Şekildeki devre için (a) $V_{GSQ}$, (b) $I_{DQ}$, (c) $V_{DS}$, (d) $V_D$, (e) $V_G$, (f) $V_S$ değerlerini bulun.

Devre:

| Eleman | Bağlantı ve değer |
|---|---|
| $V_{DD}$ | 16 V, $R_D$ üzerinden drain'e |
| $R_D$ | 2 kΩ |
| JFET | N kanal, $I_{DSS}=10$ mA, $V_P=-8$ V |
| $R_G$ | 1 MΩ, gate ile $V_{GG}$ kaynağının eksi ucu arasında |
| $V_{GG}$ | 2 V, artı ucu toprakta (gate'e ters bağlı) |
| Source | doğrudan toprağa bağlı |

Önce soru öğrencilere sorulur: kullanılan FET tipi nedir? Bir öğrenci N kanallı JFET olduğunu, şeklini ezberlediği için bildiğini söyler; başka bir öğrenci ters bağlı gerilimden yola çıkar. Hocanın cevabı: okun yönü içeri gösteriyor, demek ki kanal N tipindedir; ezbere gerek yoktur.

Çözüm:

- (a) $I_G=0$ olduğu için 1 MΩ üzerinde gerilim düşmez; $V_{GS}$ doğrudan ters bağlı kaynak gerilimidir: $V_{GSQ} = -V_{GG} = -2$ V.
- (b) $I_{DQ} = 10\text{ mA}\left(1-\dfrac{-2}{-8}\right)^2 = 10\text{ mA}(0{,}75)^2 = 10\text{ mA}(0{,}5625) = 5{,}625$ mA.
- (c) $V_{DS} = V_{DD} - I_D R_D = 16 - (5{,}625\text{ mA})(2\text{ kΩ}) = 16 - 11{,}25 = 4{,}75$ V.
- (d) Source toprakta olduğundan $V_D = V_{DS} = 4{,}75$ V.
- (e) $V_{GS} = V_G - V_S$ ve $V_S = 0$ olduğundan $V_G = V_{GS} = -2$ V.
- (f) $V_S = 0$ V.

Sonuçlar python ile kontrol edildi.

### 9.4 Gerilim bölücülü JFET

**Soru (ekrandan, 01:00:00):** N kanallı JFET'li gerilim bölücülü devrede $I_{DQ}$, $V_{GSQ}$, $V_D$, $V_S$, $V_{DS}$ ve $V_{DG}$'yi bulun.

Değerler: $V_{DD}=16$ V, $R_2 = 270$ kΩ (sözlü), $R_D = 2{,}4$ kΩ, $R_S = 1{,}5$ kΩ, $I_{DSS} = 8$ mA, $V_P = -4$ V. <!-- BELİRSİZ: devrenin şekli ve R1 değeri karelerde görünmüyor; değerler slayttaki çözüm adımlarından ve altyazıdan alındı -->

Önce bölücünün orta noktasındaki gerilim bulunur; 16 V uygulandığında 270 k üzerinde düşen gerilim $V_G = 1{,}82$ V'tur. Sonra:

$$V_{GS} = V_G - V_S = 1{,}82\text{ V} - I_D(1{,}5\text{ kΩ})$$

Bu, $V_{GS}$ ile $I_D$'yi içeren kutuplama doğrusudur. Transfer eğrisi için: $V_{GS}=0$'da 8 mA; $I_{DSS}/2 = 4$ mA'de $V_{GS} = 0{,}3(-4) = -1{,}2$ V; $V_P/2 = -2$ V'ta $I_{DSS}/4 = 2$ mA; $V_P=-4$ V'ta 0.

> **Ders sonrası not:** Hoca soruya başlarken $I_{DSS}$'yi bir an "2 mA" diye okudu; slayttaki ve çözümdeki değer 8 mA'dir (ekrandan, 01:00:00).

Doğrunun uç noktaları:

- $V_{GS}=0$: $0 = 1{,}82 - I_D(1{,}5\text{ k}) \Rightarrow I_D = \dfrac{1{,}82\text{ V}}{1{,}5\text{ kΩ}} = 1{,}21$ mA (A noktası).
- $I_D = 0$: $V_{GS} = +1{,}82$ V (B noktası).

Bu iki nokta cetvelle birleştirilince eğriyle kesişim (ekrandan, 01:00:00):

$$I_{DQ} = 2{,}4\text{ mA}, \qquad V_{GSQ} = -1{,}8\text{ V}$$

Elle okunan değerler olduğu için 2,5 mA ya da $-1{,}9$ V demek de sorun değildir; ancak işaret önemlidir. Python ile denklemin kesin çözümü $I_{DQ} \approx 2{,}42$ mA, $V_{GSQ} \approx -1{,}80$ V'tur.

Q noktasından sonra:

- $V_D = V_{DD} - I_D R_D = 16 - (2{,}4\text{ mA})(2{,}4\text{ kΩ}) = 10{,}24$ V.
- $V_S = I_D R_S = (2{,}4\text{ mA})(1{,}5\text{ kΩ}) = 3{,}6$ V.
- $V_{DS} = V_{DD} - I_D(R_D+R_S) = 16 - (2{,}4\text{ mA})(2{,}4\text{ k}+1{,}5\text{ k}) = 6{,}64$ V.
- Daha kolay yol (sağlama): $V_{DS} = V_D - V_S = 10{,}24 - 3{,}6 = 6{,}64$ V.
- $V_{DG} = V_D - V_G = 10{,}24 - 1{,}82 = 8{,}42$ V (ara adım eklendi; derste yalnız $V_D$ ve $V_G$ bilindiğinde bulunabileceği söylendi).

### 9.5 Gerilim bölücülü D-MOSFET

**Soru (ekrandan, 01:05:00):** Şekildeki N kanallı D-MOSFET için (a) $I_{DQ}$ ve $V_{GSQ}$, (b) $V_{DS}$ değerlerini bulun. Devre 5. bölümdeki tablodadır: $V_{DD}=18$ V, $R_1=110$ MΩ, $R_2=10$ MΩ, $R_D=1{,}8$ kΩ, $R_S=750\ \Omega$, $I_{DSS}=6$ mA, $V_P=-3$ V.

Kanal ayarlamalı olduğu için karakteristiğin bir kısmı pozitif bölgeye taşacaktır. Önce bölücü gerilimi:

$$V_G = \frac{10}{10+110}\cdot 18 = 1{,}5\text{ V}$$

Transfer eğrisinin noktaları:

| $V_{GS}$ (V) | $I_D$ (mA) | Açıklama |
|---|---|---|
| $-3$ | 0 | $V_P$ |
| $-1{,}5$ | 1,5 | $V_P/2$, $I_{DSS}/4$ |
| $-0{,}9$ | 3 | $0{,}3V_P$, $I_{DSS}/2$ |
| 0 | 6 | $I_{DSS}$ |
| $+1$ | 10,67 | $6(1+1/3)^2$ |

Pozitif bölge için $+1$ V yerine $+2$ V da seçilebilir.

Kutuplama doğrusu:

$$V_{GS} = V_G - I_D R_S = 1{,}5\text{ V} - (750\ \Omega)I_D$$

- $I_D = 0$: $V_{GS} = 1{,}5$ V (B noktası).
- $V_{GS} = 0$: $I_D = 1{,}5/0{,}75 = 2$ mA (A noktası).

Doğru çizilince kesişimden $I_{DQ} \approx 3{,}1$ mA okunur; sınavda 3 mA yazmak da sorun değildir. Python ile kesin çözüm $I_{DQ} \approx 3{,}12$ mA, $V_{GSQ} \approx -0{,}84$ V'tur ($V_{GSQ}$ değeri derste söylenmedi, ara adım eklendi).

$$V_{DS} = V_{DD} - I_D(R_D+R_S) = 18 - (3{,}1\text{ mA})(1{,}8\text{ k}+0{,}75\text{ k}) \approx 10{,}1\text{ V}$$

## Örnek Sorular

1. **(ekrandan, 00:40:00)** $I_{DSS}=12$ mA ve $V_P=-6$ V ile tanımlanan transfer eğrisini çizin.

   Derste kısa yol noktaları bu değerlerle anlatıldı: $I_{DSS}/2 = 6$ mA noktası $V_{GS} = 0{,}3V_P = -1{,}8$ V'a, $V_P/2 = -3$ V noktası $I_{DSS}/4 = 3$ mA'ya denk gelir. Eğri $(-6;\,0)$, $(-3;\,3)$, $(-1{,}8;\,6)$, $(0;\,12)$ noktalarından geçer.

2. **(ekrandan, 00:50:00)** $I_{DSS}=10$ mA, $V_P=-4$ V olan N kanallı D-MOSFET'in transfer karakteristiğini çizin. Çözüm 9.1'dedir: noktalar $(-4;0)$, $(-2;2{,}5)$, $(-1{,}2;5)$, $(0;10)$, $(+1;15{,}63)$.

3. **(derste sözlü, 00:50:42)** $V_{GS(Th)}=3$ V, $V_{GS(on)}=10$ V, $I_{D(on)}=3$ mA olan N kanallı E-MOSFET için $k$'yı bulun ve eğriyi çizin. Çözüm 9.2'dedir: $k \approx 0{,}061$ mA/V².

4. **(ekrandan, 00:55:00)** Sabit kutuplamalı JFET ($V_{DD}=16$ V, $R_D=2$ k, $R_G=1$ MΩ, $V_{GG}=2$ V, $I_{DSS}=10$ mA, $V_P=-8$ V): $V_{GSQ}$, $I_{DQ}$, $V_{DS}$, $V_D$, $V_G$, $V_S$. Cevaplar: $-2$ V; 5,625 mA; 4,75 V; 4,75 V; $-2$ V; 0 V.

5. **(ekrandan, 01:00:00)** Gerilim bölücülü JFET ($V_G=1{,}82$ V, $R_D=2{,}4$ k, $R_S=1{,}5$ k, $I_{DSS}=8$ mA, $V_P=-4$ V): $I_{DQ}$, $V_{GSQ}$, $V_D$, $V_S$, $V_{DS}$. Cevaplar: 2,4 mA; $-1{,}8$ V; 10,24 V; 3,6 V; 6,64 V.

6. **(ekrandan, 01:05:00)** Gerilim bölücülü D-MOSFET ($V_{DD}=18$ V, $R_1=110$ MΩ, $R_2=10$ MΩ, $R_D=1{,}8$ k, $R_S=750\ \Omega$, $I_{DSS}=6$ mA, $V_P=-3$ V): $I_{DQ}$, $V_{GSQ}$, $V_{DS}$. Cevaplar: yaklaşık 3,1 mA; yaklaşık $-0{,}84$ V; yaklaşık 10,1 V.

## Dersin Toparlaması

Bu derste FET türleri (JFET, kanal ayarlamalı D-MOSFET, kanal oluşturmalı E-MOSFET) ve bunların karakteristik denklemleri tekrar edildi, ardından FET kutuplama devreleri işlendi. Bütün yapılarda çözüm aynı iki adıma dayanır: devreden $V_{GS}$ ile $I_D$ arasında doğrusal bir kutuplama doğrusu çıkarmak ve bunu elemanın karesel transfer eğrisiyle kesiştirmek. Kesişim çalışma noktasını ($I_{DQ}$, $V_{GSQ}$) verir; $V_D$, $V_S$, $V_{DS}$ gibi diğer büyüklükler bundan sonra basit devre denklemleriyle bulunur. Sabit kutuplamada $V_{GS}$ doğrudan kaynaktan okunduğu için grafik gerekmez.

Transfer eğrisini elle çizmek için JFET ve D-MOSFET'te $(V_P,0)$, $(V_P/2, I_{DSS}/4)$, $(0{,}3V_P, I_{DSS}/2)$, $(0, I_{DSS})$ noktaları, D-MOSFET'in pozitif bölgesi için ek bir pozitif $V_{GS}$ noktası, E-MOSFET'te ise $k$ ile hesaplanan ara noktalar kullanılır. Grafik çözümün doğruluğu eksenlerin eşit aralıklı ve yeterince geniş çizilmesine bağlıdır. Kalan sorular sonraki derste çözülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
