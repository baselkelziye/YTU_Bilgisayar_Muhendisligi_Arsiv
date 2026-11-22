# Ders 23 Genişletilmiş Notu: FET Kutuplama (Sabit, Kendinden ve Gerilim Bölücü Kutuplama, E Tipi MOSFET)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvarın amacı üzerine kısa akademik açıklama
- 2. Önceki dersin tekrarı: BJT ile FET farkı
- 3. FET'lerin temel akım bağıntıları
- 4. Transfer eğrisinin çizimi
- 5. E tipi MOSFET ve eşik gerilimi
- 6. JFET kutuplama yapıları
- 7. D tipi MOSFET kutuplama yapıları
- 8. E tipi MOSFET kutuplama yapıları
- 9. P kanallı elemanlar ve kullanım alanları
- 10. Çözümlü örnekler
- Örnek Sorular
- Dersin Toparlaması

## 1. Laboratuvarın amacı üzerine kısa akademik açıklama

Ders, laboratuvar soruları üzerine bir öğrenci sorusuyla başladı. Öğrenci, CMOS ile lojik kapı tasarımı gibi konuların derste ayrıntılı işlenmediğini söyledi. Hoca bunun akademik yanını şöyle açıkladı: laboratuvar, dersteki sayısal örneklerin tekrarı değildir; öğrenciyi araştırmaya yöneltmek içindir. CMOS kapı tasarımının temelinde de yine bir anahtarlama vardır. Transistörün kutuplama gerilimiyle iletime ya da kesime sokulması, yani "tetikleme" mantığı anlaşılırsa kapı tasarımı soruları çözülebilir.

Hoca daha önce DC'de transistörün 5 V'luk bir aç-kapa (on-off) devresinde kullanımını gösterdiğini hatırlattı. Lojik kapılar, birbirini tetikleyen aç-kapa yapılarıdır; örneğin VE (AND) kapısında iki transistörün ikisi de tetiklendiğinde çıkış oluşur. Kutuplamanın aslında bir tetikleme işlevi gördüğünü ve iki transistörle bu tetiklemenin nasıl kullanılacağını düşünmek, bu tür soruların özüdür. Hoca bu yaklaşıma "devre sentezi" dedi: verilen elemanlarla mantık yürüterek istenen işlevi kuran bir devre tasarlamak.

## 2. Önceki dersin tekrarı: BJT ile FET farkı

Önceki derste BJT'lerden sonra FET'ler, MOSFET'ler ve MOSFET'in D (depletion, fakirleşmeli) ve E (enhancement, zenginleşmeli) tipleri anlatılmış, ama soru çözülmemişti. Bu derste BJT'deki gibi sabit kutuplama ve gerilim bölücü kutuplama gibi yapılar FET'ler için incelendi ve sorular çözüldü.

Temel fark şudur:

- BJT akım kontrollü bir anahtarlama elemanıdır: baz akımı kolektör akımını denetler.
- FET gerilim kontrollü bir elemandır: kapı-kaynak arasındaki gerilim $V_{GS}$, dren-kaynak arasındaki $I_D$ akımını denetler.

N kanallı bir JFET'te kapı P malzemesidir. Kanalı daraltıp akımı denetlemek için kapıya kaynağa göre negatif bir gerilim verilir, yani $V_{GS}$ negatiftir. P kanallıda bunun tersi geçerlidir: $V_{GS}$ pozitiftir.

MOSFET'lerin JFET'ten farkı, doğru yönde (N kanalda pozitif) $V_{GS}$ ile de çalışabilmeleridir:

- D tipi MOSFET, negatif $V_{GS}$ ile JFET gibi çalışır; pozitif $V_{GS}$ verildiğinde de çalışmaya devam eder ve akım $I_{DSS}$'nin üstüne çıkar.
- E tipi MOSFET (N kanal) yalnız pozitif $V_{GS}$ ile ve belli bir eşik geriliminden sonra iletime geçer.

## 3. FET'lerin temel akım bağıntıları

### 3.1 Kapı akımı sıfırdır

Slaytta "For all FETs" başlığı altında $I_G \cong 0$ A ve $I_D = I_S$ yazar (ekrandan, 00:30:00). Bu bir formül değil, bir kabuldür. FET gerilim kontrollü olduğu için kapıdan akım akmadığı kabul edilir. KCL'ye göre bir düğüme giren akımlar çıkanlara eşit olduğundan, $I_G = 0$ ise drenden giren akım aynen kaynaktan çıkar: $I_D = I_S$.

Bunun pratik önemi şudur: dren tarafında $R_D$, kaynak tarafında $R_S$ olan bir devrede iki dirençten aynı akım geçer, bu yüzden KVL yazarken $I_D(R_D + R_S)$ diye ortak parantez alınabilir. BJT'de bu doğrudan yapılamıyordu, çünkü baz akımı sıfır kabul edilemez, $I_C = \beta I_B$ denklemi ayrıca yazılmalıydı.

> **Ders sonrası not:** Hoca slayta bu bağıntıyı $V_{DD} = I_D(R_D + R_S)$ diye yazdı (ekrandan, 00:30:00). Doğrusu dren-kaynak gerilimini de içerir: $V_{DD} = I_D(R_D + R_S) + V_{DS}$. Hoca dersin ilerisinde (00:44:00 civarı) bunu doğru biçimde $V_{DS} = V_{DD} - I_D(R_D + R_S)$ diye kullandı.

### 3.2 JFET ve D tipi MOSFET: Shockley denklemi

JFET ve D tipi MOSFET için kullanılan temel denklem (ekrandan, 00:30:00):

$$I_D = I_{DSS}\left(1 - \frac{V_{GS}}{V_P}\right)^2$$

Burada $I_{DSS}$ ve $V_P$ (pinch-off, kısılma gerilimi) elemanın karakteristik değerleridir ve soruda verilir.

- $V_{GS} = 0$ ise parantez 1 olur, $I_D = I_{DSS}$. JFET'te bu, geçebilecek en büyük akımdır.
- $I_D = 0$ olması için parantezin sıfır olması gerekir, yani $V_{GS} = V_P$. Akımın kesildiği bu nokta kısılma noktasıdır.

### 3.3 E tipi MOSFET denklemi

E tipi MOSFET'in denklemi farklıdır (ekrandan, 00:35:00):

$$I_D = k(V_{GS} - V_T)^2$$

$V_T$ (ya da $V_{GS(Th)}$) eşik gerilimidir; $V_{GS}$ bu değeri aşmadıkça akım geçmez. $k$ bazen verilmez. O durumda soruda eğri üzerindeki bir nokta, yani birbirine karşılık gelen $I_{D(on)}$ ve $V_{GS(on)}$ değerleri verilir ve $k$ bu noktadan çekilir:

$$k = \frac{I_{D(on)}}{\left(V_{GS(on)} - V_T\right)^2}$$

$k$'nın birimi A/V²'dir. Hoca $k$'yı bir tür eğim parametresi gibi düşünebileceğimizi, ama ilişki doğrusal olmadığı için tam bir eğim olmadığını söyledi. İlişki doğrusal olsaydı tek bir noktadan orantıyla başka noktalar bulunabilirdi; karesel olduğu için önce $k$ bulunmalıdır.

## 4. Transfer eğrisinin çizimi

### 4.1 Kısa yol noktaları

Transfer (aktarım) eğrisi, yatay eksende $V_{GS}$, düşey eksende $I_D$ olan karakteristik eğridir. Hoca bunu "karakteristik curve" diye andı. Eğri Shockley denkleminden nokta üretilerek çizilir. Uç noktalar $(0,\ I_{DSS})$ ve $(V_P,\ 0)$'dır. Aradaki noktalar için iki kısa yol kullanılır:

- $V_{GS} = V_P/2$ alınırsa: $I_D = I_{DSS}(1 - 1/2)^2 = I_{DSS}/4$.
- $V_{GS} \cong 0{,}3V_P$ alınırsa: $I_D \cong I_{DSS}/2$ (01:08:25 civarı).

Bu dört nokta birleştirilerek eğri çizilir. Hoca bunların zorunlu olmadığını, ara değerlerin de denklemde denenebileceğini söyledi; örneğin $V_P = -4$ V ise $-3$ V da denenebilir. Nokta sayısı arttıkça eğri daha düzgün olur ve kesişim noktası daha net okunur.

> **Ek bilgi (derste anlatılmadı):** $0{,}3V_P$ kuralı yaklaşıktır. Denkleme $V_{GS} = 0{,}3V_P$ konursa $I_D = I_{DSS}(0{,}7)^2 = 0{,}49\,I_{DSS}$ çıkar; bu yüzden "yaklaşık yarısı" denir.

### 4.2 D tipi MOSFET'te eğrinin uzatılması

D tipi MOSFET için denklem aynıdır, ama $V_{GS}$'nin pozitif değerleri de denenir. Böylece eğri $I_{DSS}$'nin üstüne, sağ tarafa uzatılır. Hoca bu bölgede akımın çok hızlı arttığını, eğrinin yukarıya dik bir şekilde gittiğini belirtti.

> **Hocanın vurgusu:** Bazen kutuplama doğrusu eğriyi pozitif $V_{GS}$ tarafında keser. Eğri uzatılmazsa Q noktası bulunamaz. Bu yüzden elemanın D tipi olduğunu fark edip eğriyi uzatmak gerekir. Elemanın tipi soruda yazmayabilir; tipi transistör sembolünden anlamak gerekir.

> **Ders sonrası not:** Hoca D tipi MOSFET'in pozitif $V_{GS}$ bölgesine "depletion bölgesi" dedi. Kitaplarda bu bölgenin adı zenginleşme (enhancement) bölgesidir; negatif $V_{GS}$ tarafı fakirleşme (depletion) bölgesidir.

## 5. E tipi MOSFET ve eşik gerilimi

E tipi MOSFET'in transfer eğrisi $V_{GS} = V_T$'ye kadar sıfırdır, sonra karesel olarak yükselir. Bu eğri de $k$ bulunduktan sonra birkaç $V_{GS}$ değeri denklemde denenerek çizilir.

**Soru:** Böyle bir eşiğe neden ihtiyaç duyuluyor?

**Cevap:** Hoca önce yapısal bir sezgi verdi: transistörün içinde arka arkaya bağlı eklemler vardır ve doğru polarma için bu eklemlerin eşiğini aşmak gerekir. Sonra kullanım açısından açıkladı: eşik, devrenin hangi değerden sonra akım geçireceğini ayarlamaya yarar. Örneğin bir sıcaklık sensörü devresinde 2 derecenin altında akım geçmesi istenmiyorsa, eşik bu seviyeye göre ayarlanır; 2 derecenin üstünde anahtarlama elemanı akımı yönlendirir. MOSFET'ler çoğunlukla tümleşik devrelerde kullanıldığı için bu tür küçük eşikler önemlidir. Örneğin anahtarlar konum değiştirirken titreşim olur; bu titreşim gürültüdür ve devrenin bunu algılamaması gerekir.

> **Ders sonrası not:** Hocanın "iç içe diyotlar" sezgisi bir benzetmedir. E tipi MOSFET'te eşik gerilimi, büyük olasılıkla kapı altındaki alt tabakada iletim kanalının (evirtim katmanının) oluşması için gereken en küçük $V_{GS}$ değeri olarak tanımlanır.

**Soru:** Laboratuvar belgesindeki NMOS ve PMOS farklı bir eleman mı?

**Cevap:** Hayır. NMOS N kanallı MOSFET, PMOS P kanallı MOSFET demektir.

## 6. JFET kutuplama yapıları

### 6.1 Sabit kutuplama (fixed bias)

Slayttaki devrede (ekrandan, 00:40:00) N kanallı bir JFET vardır. Dren $R_D$ üzerinden $V_{DD}$'ye, kaynak doğrudan toprağa bağlıdır. Kapı ile toprak arasında, eksi ucu kapıya bakan bir $V_{GG}$ kaynağı vardır. Slayttaki bağıntılar:

- $V_{DS} = V_{DD} - I_D R_D$
- $V_S = 0$ V
- $V_D = V_{DS}$
- $V_G = V_{GS}$
- $V_{GS} = -V_{GG}$

N kanallı elemanda kapı P malzemesi olduğundan, akımı denetlemek için negatif $V_{GS}$ gerekir; $V_{GG}$ ters bağlandığı için $V_{GS} = -V_{GG}$ olur. Kaynakta direnç olsaydı bu eşitlik yazılamazdı, çünkü $I_D R_S$ kadar bir gerilim düşümü de $V_{GS}$'ye katılırdı.

Sabit kutuplamada $V_{GS}$ doğrudan bilindiği için Q noktası grafik çizmeden Shockley denkleminden hesaplanır.

### 6.2 Kendinden kutuplama (self-bias)

Bu yapıda kapıya DC bir gerilim verilmez. Kapı bir dirençle toprağa bağlıdır, kaynakta $R_S$ vardır. Şekildeki $V_i$ bir AC giriş işaretidir; hoca bunu şöyle açıkladı: transistörler aslında AC devrelerde kullanılır, ama DC analizde yalnız DC katkı incelenir. Elemanı tetikleyen DC gerilimdir; AC denetimi bu DC tetiklemeyle sağlanır.

Kapıda DC kaynak olmadığı ve kapı akımı sıfır olduğu için kapı gerilimi sıfırdır. Kapı-kaynak çevresinde KVL yazılırsa:

$$V_{GS} = -I_D R_S$$

Bu doğru orijinden geçer. Q noktası, bu doğrunun transfer eğrisini kestiği noktadır. $I_{D_Q}$ bulunduktan sonra dren-kaynak gerilimi bulunur.

Burada hoca öğrencilere $V_{DD} - I_D R_D$ ifadesinin $V_{DS}$'yi verip vermediğini sordu.

**Soru:** Bu devrede $V_{DD} - I_D R_D$, $V_{DS}$'yi verir mi?

**Cevap:** Bir öğrenci vermeyeceğini söyledi; bu ifade drendeki gerilimi ($V_D$) verir. $V_{DS}$ için kaynak direncindeki düşüm de çıkarılmalıdır. $I_D = I_S$ olduğundan ortak parantez alınır:

$$V_{DS} = V_{DD} - I_D(R_D + R_S)$$

Bu, dren-kaynak çevresinde bir KVL denklemidir.

### 6.3 Gerilim bölücü kutuplama

Slayttaki devrede (ekrandan, 00:45:00) kapı, $V_{DD}$ ile toprak arasındaki $R_1$-$R_2$ bölücüsüne bağlıdır. Dren $R_D$ üzerinden beslenir, kaynakta $R_S$ ve ona paralel $C_S$ vardır; giriş $C_1$, çıkış $C_2$ ile bağlanır. Slayttaki notlar: $I_G = 0$ A ve $I_D$, $V_{GS}$'deki değişimlere tepki verir.

Kapı akımı sıfır olduğundan bölücü yüksüzdür:

$$V_G = \frac{R_2}{R_1 + R_2} V_{DD}$$

Kapı-kaynak çevresinde KVL:

$$V_{GS} = V_G - I_D R_S$$

Hoca, FET'lerde ve MOSFET'lerde en önemli parametrenin $V_{GS}$ olduğunu, çünkü transfer eğrisinden akımın onunla bulunacağını vurguladı.

### 6.4 Gerilim bölücüde Q noktasının bulunması

Slaytta üç adım vardır (ekrandan, 00:50:00):

1. Doğruyu iki noktadan çiz: $V_{GS} = V_G$, $I_D = 0$ A ve $V_{GS} = 0$ V, $I_D = V_G/R_S$.
2. Transfer eğrisini $I_{DSS}$, $V_P$ ve hesaplanan $I_D$ değerleriyle çiz.
3. Q noktası, doğrunun transfer eğrisini kestiği yerdir.

Hoca doğrunun neden bu iki noktadan geçtiğini denklemden gösterdi. $V_{GS} = V_G - I_D R_S$ denkleminde:

- $V_{GS} = 0$ alınırsa $I_D = V_G/R_S$ olur. Bu, düşey eksendeki noktadır.
- $I_D = 0$ alınırsa $V_{GS} = V_G$ olur. Bu, yatay eksendeki (pozitif taraftaki) noktadır.

Bu iki nokta birleştirilip uzatılır; eğriyi kestiği yerden $V_{GS_Q}$ ve $I_{D_Q}$ okunur. Sonra devrenin istenen öteki büyüklükleri $I_{D_Q}$ ile hesaplanır:

- $V_D = V_{DD} - I_{D_Q} R_D$
- $V_S = I_{D_Q} R_S$
- $V_{DS} = V_{DD} - I_{D_Q}(R_D + R_S)$
- $R_1$ ve $R_2$ üzerindeki akım: $V_{DD}/(R_1 + R_2)$

Hoca kesişimi şöyle yorumladı: sol taraftaki eğri elemanın kendi karakteristiğidir. Doğru ise bu direnç değerleriyle elemanın nasıl çalışacağını söyler. Kesişim, bu konfigürasyonda ve bu dirençlerle elemandan geçen akımdır.

## 7. D tipi MOSFET kutuplama yapıları

D tipi MOSFET'te kutuplama devreleri JFET'tekilerle aynı adımlarla çözülür. Slaytta "These are the same steps used to analyze JFET self-bias circuits" ve gerilim bölücü için de aynı cümle yazar (ekrandan, 00:55:00 ve 01:00:00). Tek fark, transfer eğrisinin pozitif $V_{GS}$ tarafına uzatılmasıdır.

Hoca bir slaytta başlığın karıştığını belirtti: "Self-Bias" başlıklı slayttaki adımlar ve grafik (doğru $V_{GS} = V_G$, $I_D = V_G/R_S$ noktalarından geçiyor) aslında gerilim bölücü yapıya aittir. Bu slayttaki grafikte doğru, düşey ekseni 10 mA'de keser ve eğriyi pozitif tarafta keser: $I_{D_Q} = 7{,}6$ mA, $V_{GS} = +0{,}35$ V (ekrandan, 00:55:00). Bu, kesişimin pozitif $V_{GS}$ tarafında olabileceğinin bir örneğidir.

Gerilim bölücülü D tipi MOSFET'in grafiği (ekrandan, 01:00:00) Bölüm 10.4'teki örneğe aittir: $I_{DSS} = 6$ mA, $V_P = -3$ V, doğru $(1{,}5\text{ V};\ 0)$ ve $(0;\ 2\text{ mA})$'den geçer, $I_{D_Q} = 3{,}1$ mA, $V_{GS_Q} = -0{,}8$ V.

> **Hocanın vurgusu:** Sınavda ya da kağıtta Q noktası takribi okunur, ama çizim olabildiğince düzgün yapılmalıdır. 3,1 mA yerine 3 ya da 3,2 almak kabul edilebilir; 4 almak ise bariz bir hatadır.

## 8. E tipi MOSFET kutuplama yapıları

### 8.1 Geri beslemeli kutuplama

E tipi MOSFET'in geri beslemeli yapısında kapı, büyük bir dirençle drene bağlıdır. Kapı akımı sıfır olduğu için bu dirençte gerilim düşmez, yani kapı gerilimi dren gerilimine eşittir. Kaynak toprakta olduğundan:

$$V_{GS} = V_D = V_{DD} - I_D R_D$$

Slayttaki adımlar (ekrandan, 01:05:00):

1. Doğruyu $V_{GS} = V_{DD}$, $I_D = 0$ ve $I_D = V_{DD}/R_D$, $V_{GS} = 0$ noktalarıyla çiz.
2. Veri sayfasındaki değerlerle transfer eğrisini çiz: $V_{GS(Th)}$'de $I_D = 0$, bir de $V_{GS(on)}$, $I_{D(on)}$ noktası.
3. Q noktası, doğru ile eğrinin kesiştiği yerdir.
4. Q noktasındaki $I_D$ ile devredeki öteki büyüklükleri hesapla.

Kaynakta direnç olsaydı denkleme $-I_D R_S$ terimi de eklenirdi.

### 8.2 Gerilim bölücülü E tipi MOSFET

Bu yapıda da hiçbir şey değişmez: $V_G = V_{DD}\,\frac{R_2}{R_1 + R_2}$ bulunur, $V_{GS} = V_G - I_D R_S$ yazılır. $I_D = 0$ iken $V_{GS} = V_G$, $V_{GS} = 0$ iken $I_D = V_G/R_S$ olur. Doğru eşik geriliminden sonra yükselen eğriyi keser ve Q noktası okunur.

## 9. P kanallı elemanlar ve kullanım alanları

P kanallı elemanlarda yöntem değişmez. JFET ve D tipi MOSFET'te negatif yerine pozitif $V_{GS}$ ile, E tipinde pozitif yerine negatif $V_{GS}$ ile işlem yapılır. Transfer eğrileri düşey eksene göre aynalanmış olur.

Slaytta sayılan kullanım alanları arasında gerilim kontrollü direnç devreleri, JFET voltmetreler ve fiber optik devreler vardır.

## 10. Çözümlü örnekler

### 10.1 Transfer eğrisi çizimi

Soru: $I_{DSS} = 12$ mA ve $V_P = -6$ V ile tanımlanan transfer eğrisini çizin (ekrandan, 01:10:00).

Çözüm:

- $V_{GS} = 0$ V iken $I_D = I_{DSS} = 12$ mA.
- $V_{GS} = V_P = -6$ V iken $I_D = 0$.
- $V_{GS} = V_P/2 = -3$ V iken $I_D = I_{DSS}/4 = 3$ mA.
- $I_D = I_{DSS}/2 = 6$ mA iken $V_{GS} \cong 0{,}3V_P = -1{,}8$ V.

Bu dört nokta birleştirilerek eğri çizilir. Sonra soru bir $I_{D_Q}$ ya da $V_{DS}$ isterse bu grafik üzerine kutuplama doğrusu çizilir.

> **Ders sonrası not:** Python ile kontrol edildi: $V_{GS} = -1{,}8$ V'ta tam değer $12(1 - 0{,}3)^2 = 5{,}88$ mA'dir; 6 mA yuvarlanmış değerdir.

### 10.2 BJT ile JFET karşılaştırması

Hoca bir slaytta BJT ile JFET'i karşılaştırdı. JFET'te $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$ ve $I_D = I_S$ (çünkü $I_G = 0$). BJT'de $I_C = \beta I_B$; $I_E = I_C + I_B$ olduğu için $I_C$'nin $I_E$'ye eşitliği doğrudan söylenemez. Ama $I_B$ mikroamper düzeyinde olduğundan yaklaşık $I_C \cong I_E$ alınır. BJT'de baz-emiter gerilimi silisyum için 0,7 V alınır.

### 10.3 D tipi ve E tipi eğri çizimi

D tipi MOSFET için $I_{DSS} = 10$ mA, $V_P = -4$ V olan bir örnekte negatif taraf aynı kısa yollarla ($V_P/2$, $0{,}3V_P$) çizilir. Pozitif taraf için denkleme $V_{GS} = +1$ V konur ve çıkan değer eğrinin $I_{DSS}$'nin üstündeki kısmını verir. Hoca bu bölgede akımın çok hızlı arttığını, $+2$ V'ta daha da yükseldiğini ve pek denetlenebilir bir bölge olmadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu değerlerle $V_{GS} = +1$ V için $I_D = 10(1 + 0{,}25)^2 = 15{,}6$ mA bulunur (python ile hesaplandı).

E tipi MOSFET için bir örnekte $V_{GS(Th)} = 3$ V verilmiş, $k$ istenmiştir. Kitaptaki şekilde eğri üzerinde bir nokta ($I_{D(on)}$, $V_{GS(on)}$) yazılıdır; slayta bu nokta konmamıştı. $k$ bu noktadan A/V² biriminde bulunur ve sonra farklı $V_{GS}$ değerleri (5, 8, 10, 12, 14 V gibi) için $I_D$ hesaplanarak eğri çizilir. <!-- BELİRSİZ: Altyazıda 5 V için 0,244 mA geçiyor; bu anın karesi yok ve k değeri altyazıdan okunamıyor. -->

### 10.4 Sabit kutuplamalı JFET

Soru (ekrandan, 01:15:00): Şekildeki devre için (a) $V_{GS_Q}$, (b) $I_{D_Q}$, (c) $V_{DS}$, (d) $V_D$, (e) $V_G$, (f) $V_S$ değerlerini bulun. Devre: $V_{DD} = 16$ V, $R_D = 2$ kΩ, kapı 1 MΩ üzerinden eksi ucu kapıya bakan 2 V'luk kaynağa bağlı, kaynak toprakta; $I_{DSS} = 10$ mA, $V_P = -8$ V.

Çözüm (slayttaki matematiksel yol):

- (a) $V_{GS_Q} = -V_{GG} = -2$ V.
- (b) $I_{D_Q} = 10\text{ mA}\left(1 - \frac{-2}{-8}\right)^2 = 10(0{,}75)^2 = 10(0{,}5625) = 5{,}625$ mA.
- (c) $V_{DS} = V_{DD} - I_D R_D = 16 - (5{,}625\text{ mA})(2\text{ kΩ}) = 16 - 11{,}25 = 4{,}75$ V.
- (d) $V_D = V_{DS} = 4{,}75$ V.
- (e) $V_G = V_{GS} = -2$ V.
- (f) $V_S = 0$ V.

Hoca, burada grafik çizmeye gerek olmadığını vurguladı: $V_{GS}$ başka bir gerilime bağlı değildir, sabittir; $I_D$ doğrudan denklemden çıkar. Kaynakta direnç olmadığı için $V_D$ ile $V_{DS}$ aynıdır. Sonuçlar python ile doğrulandı.

### 10.5 Gerilim bölücülü JFET

Devre: $V_{DD} = 16$ V, $R_1 = 2{,}1$ MΩ, $R_2 = 270$ kΩ, $R_D = 2{,}4$ kΩ, $R_S = 1{,}5$ kΩ, $I_{DSS} = 8$ mA, $V_P = -4$ V. İstenen: $I_{D_Q}$, $V_{GS_Q}$, $V_D$, $V_S$, $V_{DS}$, $V_{DG}$ (ekrandan, 01:20:00; $R_1$ ve $R_2$ altyazıdan).

Çözüm:

- Transfer eğrisi: $(0;\ 8\text{ mA})$, $(-4\text{ V};\ 0)$, $(-2\text{ V};\ 2\text{ mA})$, $(-1{,}2\text{ V};\ 4\text{ mA})$.
- $V_G = \frac{270\text{ kΩ}}{2{,}1\text{ MΩ} + 270\text{ kΩ}} \cdot 16 = 1{,}82$ V.
- $I_D = 0$ iken $V_{GS} = +1{,}82$ V.
- $V_{GS} = 0$ iken $I_D = 1{,}82/1{,}5\text{ kΩ} = 1{,}21$ mA.
- Kesişim: $I_{D_Q} = 2{,}4$ mA, $V_{GS_Q} = -1{,}8$ V.
- $V_D = 16 - (2{,}4\text{ mA})(2{,}4\text{ kΩ}) = 10{,}24$ V.
- $V_S = (2{,}4\text{ mA})(1{,}5\text{ kΩ}) = 3{,}6$ V.
- $V_{DS} = 16 - (2{,}4\text{ mA})(2{,}4 + 1{,}5)\text{ kΩ} = 6{,}64$ V; ya da $V_{DS} = V_D - V_S = 10{,}24 - 3{,}6 = 6{,}64$ V.
- $V_{DG} = V_D - V_G = 10{,}24 - 1{,}82 = 8{,}42$ V.

Hoca $V_{DS}$'nin iki yoldan bulunabileceğini gösterdi: ya yukarıdan $V_{DD} - I_D(R_D + R_S)$ ile, ya da $V_D$ ve $V_S$ ayrı ayrı bulunup birbirinden çıkarılarak.

> **Ders sonrası not:** Python ile kesişim sayısal olarak çözüldü: $V_{GS_Q} = -1{,}80$ V, $I_{D_Q} = 2{,}42$ mA. Grafik sonucu (2,4 mA) doğrudur.

### 10.6 Gerilim bölücülü D tipi MOSFET

Bu örnek derste öğrencilerin denemesi için verildi, sonra birlikte çözüldü. Ayrıntısı aşağıda "Örnek Sorular" bölümünde 2. sorudadır.

### 10.7 Kendinden kutuplamalı D tipi MOSFET

Soru (ekrandan, 01:40:00): Şekildeki devre için (a) $I_{D_Q}$ ve $V_{GS_Q}$, (b) $V_D$ değerlerini bulun. Devre: $V_{DD} = 20$ V, $R_D = 6{,}2$ kΩ, kapı 1 MΩ ile toprağa bağlı, $R_S = 2{,}4$ kΩ; $I_{DSS} = 8$ mA, $V_P = -8$ V.

Çözüm:

- Transfer eğrisi: $V_{GS} = V_P/2 = -4$ V iken $I_D = I_{DSS}/4 = 2$ mA; $V_{GS} = 0{,}3V_P = -2{,}4$ V iken $I_D \cong 4$ mA; $(0;\ 8\text{ mA})$ ve $(-8\text{ V};\ 0)$.
- Pozitif taraf: $V_{GS} = +1$ V için $I_D = 8\left(1 - \frac{1}{-8}\right)^2 = 8 \cdot \frac{81}{64} = \frac{81}{8} = 10{,}125$ mA. Slayttaki çözüm pozitif taraf için $+2$ V'u kullanmıştır; hoca bunun önemli olmadığını söyledi.
- Kendinden kutuplama: $V_{GS} = -I_D R_S$. $I_D = 0$ için $V_{GS} = 0$, yani doğru orijinden geçer.
- Orijinden geçen doğru için ikinci nokta başka bir değerle bulunur: $V_{GS} = -6$ V alınırsa $I_D = 6/2{,}4 = 2{,}5$ mA.
- Kesişim: $I_{D_Q} \approx 1{,}7$ mA, $V_{GS_Q} \approx -4{,}3$ V.
- $V_D = 20 - (1{,}7\text{ mA})(6{,}2\text{ kΩ}) = 9{,}46$ V.

Hoca, doğruyu çizmek için illa birini sıfır yapmak gerekmediğini, sıfır vermenin yalnız işlem kolaylığı olduğunu söyledi. Doğru orijinden geçiyorsa sıfır yalnız bir nokta verir; ikinci nokta denklemde başka bir değer denenerek bulunur. Amaç iki nokta bulup doğruyu çizmek ve kesişimi belirlemektir.

Slaytta, kendinden kutuplamada $V_{GS} = -I_D R_S$ olduğu için $V_{GS}$'nin sıfırdan küçük olacağı, bu yüzden pozitif taraf için eğri çizmenin aslında gerekmediği, ama karakteristiği tamamlamak için çizildiği de yazar (ekrandan, 01:40:00).

> **Ders sonrası not:** Hoca bu örnekte eğriyi çizerken bir an "$V_P/2 = -4$ V, $I_{DSS}/2$'ye karşılık gelir" dedi (01:38:15 civarı). Doğrusu $-4$ V'un $I_{DSS}/4 = 2$ mA'e karşılık geldiğidir; ekrandaki çizim de böyledir.

> **Ders sonrası not:** Python ile kesişim sayısal olarak çözüldü: $V_{GS_Q} = -4{,}24$ V, $I_{D_Q} = 1{,}77$ mA. Bununla $V_D = 20 - 1{,}77 \cdot 6{,}2 \approx 9{,}05$ V çıkar. Derste ve slaytta grafikten okunan 1,7 mA ile 9,46 V bulunmuştur; fark grafik okumadan gelir.

### 10.8 $V_{GS} = 0$ olan D tipi MOSFET

Hoca bunu mantık sorusu olarak sundu. Soru (ekrandan, 01:45:00): Şekildeki devre için $V_{DS}$'yi bulun. $V_{DD} = 20$ V, $R_D = 1{,}5$ kΩ, kapı doğrudan kaynağa bağlı, kaynak toprakta; $I_{DSS} = 10$ mA.

Çözüm: Kapı ile kaynak arasında polarma yoktur, $V_{GS} = 0$. Shockley denkleminde $V_{GS} = 0$ konursa $I_D = I_{DSS}$ olur:

- $V_{GS_Q} = 0$ V, $I_{D_Q} = 10$ mA.
- $V_{DS} = V_D = V_{DD} - I_{DSS} R_D = 20 - (10\text{ mA})(1{,}5\text{ kΩ}) = 20 - 15 = 5$ V.

Transfer eğrisi çizmeye gerek yoktur. Hoca burada ilk FET dersindeki çıkış eğrilerini hatırlattı: $V_{GS}$'ye negatif değer verildikçe $I_D$, $I_{DSS}$'nin altına düşer. Örneğin $V_{GS} = -5$ V iken $V_{GS} = -8$ V'takinden daha fazla akım geçer. Bu, denklemde $V_{GS}$'nin büyüklüğü arttıkça parantezin küçülmesinden görülür.

**Soru:** Bu yapıda kapıya pozitif gerilim bağlarsak akım artıyordu, değil mi?

**Cevap:** Evet. Eleman D tipi olduğu için pozitif $V_{GS}$ verildiğinde akım artar ve $I_D$, $I_{DSS}$'yi geçer. Normal JFET'ten farkı budur.

**Soru:** Bunun bir üst sınırı var mı?

**Cevap:** Gerçekte eleman bozulur. Sınır veri sayfasında yazar; belli bir gerilimin üstü yanma (kırılma) bölgesi olarak verilir.

### 10.9 Geri beslemeli E tipi MOSFET

Dersin son örneği geri beslemeli bir E tipi MOSFET devresiydi. $V_{GS(Th)} = 3$ V'tur; 3 V'a kadar $I_D = 0$'dır. E tipi eğri için iki yaklaşım vardır: ya $k$ verilir ve $I_D = k(V_{GS} - V_{GS(Th)})^2$ ile birkaç nokta hesaplanır, ya da $k$ verilmez ve eğri üzerinde bir nokta verilir. Bu örnekte $k$ verilmemiş, bir nokta verilmiştir; buradan $k \approx 0{,}24$ mA/V² bulunur. <!-- BELİRSİZ: Verilen nokta altyazıda "16 mA iken 18 V" diye geçiyor, ama bu değerler k = 0,24 sonucunu vermiyor (16/15² ≈ 0,071 mA/V²). 0,24 ile tutarlı nokta büyük olasılıkla I_D(on) = 6 mA, V_GS(on) = 8 V'tur (6/5² = 0,24); bu anın karesi yok. -->

Sonra $k$ ile birkaç değer daha hesaplanıp eğri düzgün biçimde çizilir. Kutuplama denklemi: kaynakta direnç olmadığı için $V_{GS} = V_D = V_{DD} - I_D R_D$. $I_D = 0$ konursa $V_{GS} = V_{DD} = 12$ V bulunur; $V_{GS} = 0$ konursa $I_D = V_{DD}/R_D$ olur. Doğru çizilir ve kesişimdeki $I_{D_Q}$ ile devredeki istenen büyüklükler hesaplanır. Kaynakta direnç olsaydı denkleme $-I_D R_S$ terimi eklenmesi gerekirdi.

Dersin sonunda ekranda bir sonraki örnek (gerilim bölücülü E tipi MOSFET) görünüyordu, ama çözümüne geçilmedi (ekrandan, 01:50:00).

## Örnek Sorular

**1. (ekrandan, 01:15:00)** Şekildeki devre için (a) $V_{GS_Q}$, (b) $I_{D_Q}$, (c) $V_{DS}$, (d) $V_D$, (e) $V_G$, (f) $V_S$ değerlerini bulun. $V_{DD} = 16$ V, $R_D = 2$ kΩ, kapı 1 MΩ üzerinden $V_{GG} = 2$ V'a (eksi ucu kapıya bakar) bağlı, kaynak toprakta; $I_{DSS} = 10$ mA, $V_P = -8$ V.

> **Çözüm (derste verildi):** $V_{GS_Q} = -2$ V; $I_{D_Q} = 10(1 - 0{,}25)^2 = 5{,}625$ mA; $V_{DS} = 16 - 11{,}25 = 4{,}75$ V; $V_D = 4{,}75$ V; $V_G = -2$ V; $V_S = 0$ V.

**2. (ekrandan, 01:25:00)** Şekildeki N kanallı D tipi MOSFET için (a) $I_{D_Q}$ ve $V_{GS_Q}$, (b) $V_{DS}$ değerlerini bulun. $V_{DD} = 18$ V, $R_1 = 110$ MΩ, $R_2 = 10$ MΩ, $R_D = 1{,}8$ kΩ, $R_S = 750$ Ω; $I_{DSS} = 6$ mA, $V_P = -3$ V.

Hoca bu soruyu öğrencilerin çözmesi için birkaç dakika verdi. Bir öğrenci önce eğri noktalarını hesaplamaya başladı; $V_{GS}$ için işareti karıştırınca hoca negatif tarafı birlikte çizdi.

> **Çözüm (derste verildi, ekrandan 01:35:00):**
> - Transfer eğrisi: $V_{GS} = V_P/2 = -1{,}5$ V iken $I_D = 6/4 = 1{,}5$ mA; $V_{GS} = 0{,}3V_P = -0{,}9$ V iken $I_D \cong 6/2 = 3$ mA; $(0;\ 6\text{ mA})$; $(-3\text{ V};\ 0)$.
> - Eleman D tipi olduğu için pozitif taraf: $V_{GS} = +1$ V iken $I_D = 6\left(1 - \frac{1}{-3}\right)^2 = 6 \cdot \frac{16}{9} = \frac{32}{3} \approx 10{,}67$ mA.
> - $V_G = 18 \cdot \frac{10}{110 + 10} = 1{,}5$ V.
> - Kapı-kaynak çevresinde KVL: $V_{GS} = V_G - I_D R_S = 1{,}5 - 750\,I_D$.
> - $I_D = 0$ iken $V_{GS} = 1{,}5$ V; $V_{GS} = 0$ iken $I_D = 1{,}5/750 = 2$ mA.
> - Kesişim: $I_{D_Q} \approx 3{,}1$ mA, $V_{GS_Q} \approx -0{,}8$ V.
> - $V_{DS} = 18 - I_D(R_D + R_S) = 18 - (3{,}1\text{ mA})(2{,}55\text{ kΩ}) \approx 10{,}1$ V.

> **Hocanın vurgusu:** Bu tarz bir soru doğrudan final sorusudur.

> **Ders sonrası not:** Hoca $32/3$'ü önce "9 nokta bir şey" dedi, bir öğrenci düzeltti; doğrusu $10{,}67$ mA'dir. Derste $V_{DS}$ hesabının son satırı tahtada tamamlanmadı; $18 - 3{,}1 \cdot 2{,}55 = 10{,}095 \approx 10{,}1$ V python ile hesaplandı. Python ile kesişim sayısal olarak çözüldü: $V_{GS_Q} = -0{,}84$ V, $I_{D_Q} = 3{,}12$ mA; grafik sonucu doğrudur.

**3. (ekrandan, 01:40:00)** Şekildeki devre için (a) $I_{D_Q}$ ve $V_{GS_Q}$, (b) $V_D$ değerlerini bulun. $V_{DD} = 20$ V, $R_D = 6{,}2$ kΩ, $R_G = 1$ MΩ, $R_S = 2{,}4$ kΩ; $I_{DSS} = 8$ mA, $V_P = -8$ V.

> **Çözüm (derste verildi):** $V_{GS} = -I_D R_S$ doğrusu orijinden ve $(-6\text{ V};\ 2{,}5\text{ mA})$ noktasından geçer. Kesişim $I_{D_Q} \approx 1{,}7$ mA, $V_{GS_Q} \approx -4{,}3$ V; $V_D = 20 - 1{,}7 \cdot 6{,}2 = 9{,}46$ V. (Sayısal çözüm: $I_{D_Q} = 1{,}77$ mA, $V_{GS_Q} = -4{,}24$ V.)

**4. (ekrandan, 01:45:00)** Şekildeki devre için $V_{DS}$'yi bulun. $V_{DD} = 20$ V, $R_D = 1{,}5$ kΩ, kapı doğrudan kaynağa bağlı, kaynak toprakta; $I_{DSS} = 10$ mA.

> **Çözüm (derste verildi):** $V_{GS} = 0 \Rightarrow I_D = I_{DSS} = 10$ mA; $V_{DS} = 20 - (10\text{ mA})(1{,}5\text{ kΩ}) = 5$ V.

**5. (ekrandan, 01:50:00)** Şekildeki devre için $I_{D_Q}$, $V_{GS_Q}$ ve $V_{DS}$'yi bulun. $V_{DD} = 40$ V, $R_1 = 22$ MΩ, $R_2 = 18$ MΩ, $R_D = 3$ kΩ, $R_S = 0{,}82$ kΩ; E tipi MOSFET, $V_{GS(Th)} = 5$ V, $V_{GS(on)} = 10$ V'ta $I_{D(on)} = 3$ mA.

Ekrandaki çözümün ilk kısmı: $V_G = \frac{18 \cdot 40}{22 + 18} = 18$ V; $V_{GS} = 18 - I_D(0{,}82\text{ kΩ})$; $I_D = 0$ iken $V_{GS} = 18$ V; $V_{GS} = 0$ iken $I_D = 18/0{,}82 = 21{,}95$ mA. Derste soru buraya kadar gösterildi, devamı çözülmedi.

> **Çözüm (derste verilmedi):** $k = \frac{3}{(10 - 5)^2} = 0{,}12$ mA/V². $V_{GS} = 18 - 0{,}82\,I_D$ ile $I_D = 0{,}12(V_{GS} - 5)^2$ birlikte çözülür (python ile): $V_{GS_Q} \approx 12{,}5$ V, $I_{D_Q} \approx 6{,}7$ mA. $V_{DS} = 40 - I_D(3 + 0{,}82) \approx 14{,}3$ V.

## Dersin Toparlaması

Bu derste FET'lerin DC kutuplama analizi işlendi. Bütün yöntem iki fikre dayanır: kapı akımı sıfırdır ($I_D = I_S$) ve $I_D$, $V_{GS}$ ile karesel bir ilişkiyle denetlenir. Bu yüzden her devrede önce kapı-kaynak çevresinden $V_{GS}$'yi $I_D$ cinsinden veren denklem çıkarılır: sabit kutuplamada $V_{GS} = -V_{GG}$, kendinden kutuplamada $V_{GS} = -I_D R_S$, gerilim bölücüde $V_{GS} = V_G - I_D R_S$, geri beslemeli E tipi MOSFET'te $V_{GS} = V_{DD} - I_D R_D$. Bu doğru, elemanın transfer eğrisiyle (JFET ve D-MOSFET için Shockley denklemi, E-MOSFET için $k(V_{GS} - V_T)^2$) kesiştirilir ve Q noktası bulunur. Ardından $V_D$, $V_S$ ve $V_{DS}$ Q noktasındaki akımla hesaplanır.

D tipi MOSFET'te eğrinin pozitif $V_{GS}$ tarafına uzatılması, E tipinde ise $k$'nın verilen bir noktadan bulunması gerektiği vurgulandı. Hoca birkaç örneğin kaldığını ve bir sonraki derste bunlara bakılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
