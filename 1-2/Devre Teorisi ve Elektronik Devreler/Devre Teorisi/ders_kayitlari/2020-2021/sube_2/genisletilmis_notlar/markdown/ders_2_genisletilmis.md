# Ders 2 Genişletilmiş Notu: Ohm Yasası, Devre Terminolojisi ve Kirchhoff Yasaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Akım Yönü ve Güç İşareti
- 2. Dersin Amaçları
- 3. Direnç ve Özdirenç
- 4. Ohm Yasası
- 5. Kısa Devre ve Açık Devre
- 6. İletkenlik ve Güç Formülleri
- 7. Devre Terminolojisi
- 8. Kirchhoff'un Akım Yasası (KCL)
- 9. Kirchhoff'un Gerilim Yasası (KVL)
- 10. KCL Örnekleri
- 11. Dirençler Her Zaman Tüketir mi?
- 12. KVL Örnekleri
- 13. Ders Sonu Soru-Cevap: Kısa Devrede Akım
- Örnek Sorular

## 1. Önceki Dersin Tekrarı: Akım Yönü ve Güç İşareti

Ders, bir önceki haftanın kısa bir tekrarıyla başlar. Bir maddede artı yüklerin fazla olması, aslında içindeki elektronların az olması demektir; eksi uç ise elektronların fazla olduğu uçtur. Elektronlar elektronun az olduğu yere, yani eksi uçtan artı uca doğru hareket eder. Devre analizinde kullanılan akım ($i$, İngilizce *current*) ise elektron hareketinin tam tersi yöndedir. Sorularda "$i$'yi bulun" dendiğinde kastedilen her zaman bu, elektron hareketinin tersi yöndeki akımdır.

<!-- BELİRSİZ: Hoca bu akım türünün adını ve sembolünü söylüyor ("Natural Currency" gibi duyuluyor), ama altyazı bozuk ve o anın karesi yok. -->

> **Ek bilgi (derste anlatılmadı):** Elektron hareketinin tersi yönde tanımlanan bu akıma Türkçede "geleneksel akım", İngilizcede *conventional current* denir. Akım yönü tarihsel olarak artı yüklerin hareket yönü kabul edildiği için bu tanım korunmuştur.

Akım, iki nokta arasındaki yükün zamana göre değişimidir: $i = dq/dt$. Hoca bunu, suyun yukarıdan aşağıya akmasına benzetir: elektronların hareketi ve akımın yönü fiziksel bir eğilimin sonucudur. Elektromotor kuvvet (EMF) de elektronların iç dinamiğinden doğan bu etkiyi anlatır.

### 1.1 Tüketilen ve üretilen güç

Hoca tek bir gerilim kaynağı ve ne olduğu önemli olmayan tek bir devre elemanından oluşan bir devre çizer. Bataryanın uzun çizgisi artı, kısa çizgisi eksi ucu gösterir. Elektronlar eksi uçtan artı uca gider, akım ise ters yönde, kaynağın artı ucundan çıkıp elemandan geçerek eksi uca döner.

Her devre elemanı üzerinde bir güç harcanır. Kaynağın artı ucundan çıkan akım, eleman bir üreteç değilse, onu kutuplar (polarize eder): akımın girdiği uç artı, çıktığı uç eksi olur. Kaynak gücü ürettiği için gücü eksi ($-P$) yazılır; eleman bu gücü tükettiği için gücü artı ($+P$) yazılır. Üretilen gücün tüketilen güce eşit olması devrenin dengesidir.

Bu kutuplaşmanın önemi şudur: akım bir elemana artı ucundan girerse eleman güç tüketir, gücü artı işaretlidir. Akım kaynağın eksi ucundan girip artı ucundan çıktığı için kaynak açısından akım "ters yönlüdür" ve kaynak güç üretir. Artı güç tüketen elemanlara, eksi güç üreten elemanlara verilir.

> **Hocanın vurgusu:** KCL ve KVL sorularındaki esas kritik nokta elemanların polarizasyonudur. Bu kutuplaşma durumları ders boyunca bütün örneklerde tekrar tekrar görülecektir.

## 2. Dersin Amaçları

Slaytta dersin amaçları üç madde halinde verilir (ekrandan, 00:20:00):

- Kirchhoff'un akım ve gerilim yasalarını tanıtmak.
- Bu yasaların bir devredeki akım ve gerilimleri bulmak için nasıl kullanıldığını göstermek.
- Bu yasaların Ohm yasasıyla birlikte nasıl kullanılacağını açıklamak.

Bazı problemler yalnız KCL ve KVL ile çözülebilir; daha iç içe devrelerde ise bu yasalar Ohm yasasıyla birlikte kullanılır.

## 3. Direnç ve Özdirenç

Ohm yasasındaki $R$'nin neye bağlı olduğunu anlamak için direnç kavramına geri dönülür. $R$, *resistivity* kökünden gelen, bir malzemenin ya da devre elemanının yük hareketine karşı gösterdiği direnç özelliğidir. Hoca bunu günlük hayattaki sürtünmeye benzetir: havada duran her şey bile bir dirençle karşılaşır. Devre tasarımında kullanılan bütün malzemelerde de, yüklerin artı tarafa olan hareketine karşı, malzemenin iç yapısından doğan bir direnç etkisi vardır.

### 3.1 Malzemelerin özdirenci

Slayttaki tablo oda sıcaklığında (300 K) yaygın malzemelerin özdirencini verir (ekrandan, 00:25:00):

| Malzeme | Özdirenç ($\Omega\cdot$cm) | Kullanım |
|---|---|---|
| Gümüş | $1{,}64\times10^{-8}$ | İletken |
| Bakır | $1{,}72\times10^{-8}$ | İletken |
| Alüminyum | $2{,}8\times10^{-8}$ | İletken |
| Altın | $2{,}45\times10^{-8}$ | İletken |
| Karbon (grafit) | $4\times10^{-5}$ | İletken |
| Germanyum | $0{,}47$ | Yarı iletken |
| Silisyum | $640$ | Yarı iletken |
| Kağıt | $10^{10}$ | Yalıtkan |
| Mika | $5\times10^{11}$ | Yalıtkan |
| Cam | $10^{12}$ | Yalıtkan |
| Teflon | $3\times10^{12}$ | Yalıtkan |

Gümüş bakırdan daha iyi bir iletkendir, ama pahalı olduğu için günlük hayattaki iletken teller bakırdan yapılır; bakır doğada daha kolay bulunur ve özdirenci gümüşe çok yakındır. Alüminyum ve altının etkisi de benzerdir.

> **Ders sonrası not:** Hoca iletkenlerin özdirencini anlatırken $10^{-8}$ için "milyarda bir" dedi. $10^{-8}$ yüz milyonda birdir.

Yarı iletkenler bazı koşullarda yalıtkan, bazı koşullarda iletken davranır. İkinci sınıftaki elektronik dersinde görülecek bütün devre bileşenleri bu yarı iletken kavramıyla incelenecektir. Devre teorisinin konusu ise iletkenler ve dirençlerdir. Kağıt, mika ve cam gibi malzemeler elektriği iletmeyen yalıtkanlardır; özdirençleri çok büyüktür.

### 3.2 Direnç formülü

Bir elemanın direnci şu formülle hesaplanır:

$$R = \rho\,\frac{L}{A}$$

Burada $\rho$ tablodaki, malzemeye özgü özdirenç katsayısıdır; $L$ elemanın uzunluğu, $A$ ise kesit (yüzey) alanıdır. Kesit alanının büyümesi direnci azalttığı için $A$ paydadadır; uzunluğun artması direnci artırdığı için $L$ paydadır. İnce ve uzun bir kablonun direnci büyüktür.

Buna göre bir malzemenin direncini düşürmek isteyen biri üç şey yapabilir: alanı artırabilir, malzemeye daha iyi iletken bir malzeme katarak $\rho$'yu düşürebilir ya da uzunluğu kısaltabilir.

## 4. Ohm Yasası

Ohm yasası slaytta şöyle verilir (ekrandan, 00:30:00): bir direnç üzerindeki gerilim düşümü, dirençten geçen akımla orantılıdır.

$$v = iR, \qquad \text{V} = \text{A}\,\Omega, \qquad \text{A} = \text{C/s}$$

Hoca yasayı sözle şöyle anlatır: bir devreden akım geçerken, akımın aktığı yol üzerindeki her devre elemanının üzerinde, o elemanın iç yapısından doğan dirence bağlı bir gerilim oluşur. Bir ana besleme gerilimi akımı oluşturur; akım dirençli bir elemandan geçtiği anda onun üzerinde gerilim biriktirir.

Volt gerilim birimidir ve amper-ohm olarak da yazılabilir. Akımın birimi amperdir; akım yükün zamana göre değişimi olduğu için amper coulomb/saniyedir. $R$ ise $\rho L/A$ olarak malzemeye ve geometriye bağlıdır. Hoca bu formüllerin iç içe kullanılabileceğini, bu yüzden her terimin nereden geldiğini bilmek gerektiğini söyler.

## 5. Kısa Devre ve Açık Devre

### 5.1 Kısa devre

Kısa devre (*short circuit*), üzerinde direnç gösteren hiçbir elemanın olmadığı, yani direnci sıfır olan yoldur. Ohm yasasına göre $v = iR$ olduğundan $R = 0$ ise bu yol üzerinde gerilim oluşmaz. Kısa devre, direnci sıfır olan ve üzerinde gerilim biriktirmeyen yol demektir.

Gerçek hayatta böyle bir yol yoktur, çünkü bakır telin bile küçük de olsa bir direnci vardır. Kısa devre teorik bir kavramdır. Direnç sıfıra giderken akım sınırsız büyür; hoca bunu "kısa devrede direnç sıfır, akım sonsuz" diye özetler.

> **Ders sonrası not:** Hoca kısa devreyi ilk anlatırken bir yerde "oradan akım geçmeyen kol" dedi. Aynı bölümün sonunda ve ders sonundaki soruda doğrusunu söyledi: kısa devrede gerilim sıfırdır ve teorik olarak akım sonsuza gider. Akım geçmeyen yol açık devredir.

### 5.2 Açık devre

Açık devre, direncin sonsuz olduğu noktadır. Ohm yasasından $i = v/R$ olduğu için

$$\lim_{R\to\infty} \frac{v}{R} = 0$$

yani açık devreden akım geçmez. Adı üstünde, yol kesilmiştir ve devre tamamlanmaz. Kaynak ne kadar gerilim verirse versin akım oluşmaz, $i = 0$ olur.

Bu iki durum Ohm yasasının iki uç halidir: kısa devrede direnç sıfır, gerilim sıfır; açık devrede direnç sonsuz, akım sıfır.

## 6. İletkenlik ve Güç Formülleri

### 6.1 İletkenlik (conductance)

Direncin tersi olan büyüklüğe iletkenlik (*conductance*) denir (ekrandan, 00:35:00):

$$G = R^{-1} = \frac{i}{v}$$

Direnç $R = v/i$ olduğuna göre iletkenlik $G = i/v$'dir. Birimi siemens (S) ya da mho'dur ($\mho$). Çok sık kullanılan bir terim değildir. Direnç formülünün tersi olarak

$$G = \frac{A\sigma}{L}$$

yazılır; burada $\sigma$ iletkenlik katsayısıdır ve özdirencin tersidir: $\sigma = 1/\rho$. Yani iletkenlikte her şey direncin tersidir.

### 6.2 Güç formülleri

Temel güç formülü $p = vi$'dir: bir elemandan geçen akım ile o akımın elemanın direnci nedeniyle oluşturduğu gerilimin çarpımı. Ohm yasası yerine konarak farklı biçimler elde edilir:

$$p = vi = i^2R = \frac{v^2}{R} = \frac{i^2}{G} = v^2G$$

$v = iR$ konursa $i^2R$; $i = v/R$ konursa $v^2/R$; $R = 1/G$ olduğundan $v = i/G$ konursa $i^2/G$, $i = vG$ konursa $v^2G$ elde edilir.

Gücü soğuran (tüketen) elemanın, örneğin direncin, gücü her zaman artıdır. Güç üreten elemanda akım o elemana ters yönden girdiği için gücü eksi yazılır. Pratikte üretilen gücün tamamı tüketilemez; bir kısmı ısı olarak çıkar, kablolarda harcanır. Ama derste teorik olarak soğurulan ve üretilen güç eşit kabul edilir.

Kısa devrede direnç sıfır olduğu için gerilim, açık devrede akım sıfır olduğu için güç sıfırdır. Yani açık ve kısa devrede hiçbir güç üretilmez ya da tüketilmez.

## 7. Devre Terminolojisi

KCL ve KVL'de sıkça kullanılacak terimler slaytta iki devre şekliyle tanımlanır (ekrandan, 00:40:00). Şekilde bir akım kaynağı, 1 ve 2 düğümleri arasında iki paralel direnç ve 1-3-2 üzerinden seri iki direnç vardır.

- **Düğüm (node):** iki ya da daha fazla elemanın ortak bağlandığı nokta. Örnekte 1. düğümde akım kaynağı ve üç direnç, 3. düğümde iki direnç birleşir. Aralarında hiçbir eleman olmayan bağlantı noktalarının hepsi aynı düğümdür ve aynı adla anılır; ikinci şekilde 1. düğüm tek nokta yerine bir tel parçası olarak çizilmiştir.
- **Yol (path):** düğümlerin tekrar etmediği güzergah, örneğin $1\to3\to2$ ya da $1\to2\to3$. Yol birden fazla eleman içerebilir. Bir soru "1-3-2 yolundaki akımı bulun" diye sorulabilir; kastedilen o güzergahtan geçen akımdır.
- **Döngü (loop):** aynı düğümde başlayıp biten yol, örneğin $3\to1\to2\to3$ ya da $1\to2\to1$. $1\to3\to2\to1$ bir yol değildir, döngüdür.
- **Kol (branch):** ağdaki tek elemanlı yol; tek eleman ve iki uç düğüm içerir, örneğin $1\to2$, $1\to3$, $3\to2$. $1\to3\to2$ bir kol değil yoldur; $1\to3$ ve $3\to2$ ayrı kollardır.

Hoca kol için Türkçede "dal" ya da "kol" denebileceğini söyler. Yol genelde bir güzergahtaki akımı sormak için, kol ise tek bir elemandaki akımı (örneğin $3\to2$ arasındaki $R_x$ direncinin akımını) sormak için kullanılır.

### 7.1 Alıştırma

Slayttaki alıştırma (ekrandan, 00:45:00) $A$, $B$, $C$, $F$, $G$ üst ve $E$, $D$ alt düğümlü bir merdiven devresi için üç soru sorar.

- (a) Eleman sayısı: 5 direnç ve 1 DC gerilim kaynağı, toplam 6 eleman.
- (b) $B\to C\to D$ hareketi bir yoldur. Döngü olması için $E$ ve $B$'ye geri dönülmesi gerekir.
- (c) $E\to D\to C\to B\to E$ hareketi başlangıç düğümüne döndüğü için bir döngüdür.

## 8. Kirchhoff'un Akım Yasası (KCL)

Kirchhoff'un akım yasası (*Kirchhoff's Current Law*, KCL) düğümler üzerinde uygulanır. Hoca bunun her zaman akılda tutulmasını ister: KCL denince düğümlerle çalışılır.

Yasa şunu söyler: bir düğüme giren akımların toplamı, o düğümden çıkan akımların toplamına eşittir. Aynı şey, giren akımlar artı ve çıkan akımlar eksi işaretle alındığında düğümdeki akımların cebirsel toplamının sıfır olması olarak da söylenebilir:

$$\sum i_{\text{giren}} = \sum i_{\text{çıkan}} \quad\Longleftrightarrow\quad \sum i = 0$$

Bu kural, yüklerin sistem içinde kayba uğramadan hareket etmesine, yani yükün korunumuna dayanır. KCL'ye dayalı çözüm yöntemine ileride düğüm analizi (*node analysis*) denecektir.

## 9. Kirchhoff'un Gerilim Yasası (KVL)

KVL, enerjinin korunumuna dayanır. Enerjinin korunumu, güç tüketen ve üreten elemanlar arasındaki dengedir. Slayttaki ifadeler şunlardır (ekrandan, 00:50:00):

- Bir döngü etrafındaki elemanlar üzerindeki gerilimlerin cebirsel toplamı sıfırdır.
- Bir yükü A noktasından B noktasına taşımak için gereken enerji seçilen yoldan bağımsızdır.

$$\sum_{m=1}^{M} v_m = 0 \qquad \sum v_{\text{düşüm}} = \sum v_{\text{yükselme}}$$

Burada $M$ döngüdeki kol sayısıdır.

Slayttaki örnekte üç eleman (1, 2, 3) bir döngü oluşturur. Elemanların polariteleri döngü boyunca "eksi-artı, artı-eksi, eksi-artı" sırasıyla karşılaşılacak biçimdedir. Bir eleman için $+v_1$ yazılırsa, ters yönde kutuplanmış eleman için $-v_2$, $v_1$ ile aynı yönde kutuplanmış eleman için $+v_3$ yazılır: $v_1 - v_2 + v_3 = 0$. İlk kabul $-v_1$ olarak yapılırsa bütün işaretler değişir: $-v_1 + v_2 - v_3 = 0$. İki denklem aynı bilgiyi verir.

KCL akımlarla ve düğümlerle, KVL gerilimlerle ve döngülerle çalışır. KVL'ye dayalı yönteme ileride çevre analizi (*mesh analysis*) denecektir; şimdilik "döngü" denir.

**Soru:** Türkçede "çevrim" yerine "döngü" denmiyor muydu? **Cevap:** Döngü de denir; ileride bunun için "mesh" terimi kullanılacak, şimdilik döngü analizi denebilir.

## 10. KCL Örnekleri

### 10.1 Example-01: Kaynak akımı bilinen devre

Soru (ekrandan, 00:55:00): 10 V'luk gerilim kaynağının 3 A'lik akım verdiği biliniyorsa $R_3$'ten geçen akım nedir? Devrede kaynak, $R_1$ üzerinden üst düğüme bağlıdır; $R_2$ ve $R_3$ aşağıya iner, sağda 5 A'lik akım kaynağı yukarı doğru akım verir. $R_2$'den aşağı 2 A geçer.

- $R_1$ ile $R_2$ arasındaki nokta bir düğümdür, çünkü iki eleman arasındadır. Bu düğüme 3 A girer, $R_2$'den 2 A çıkar. KCL'ye göre $3 - 2 = 1$ A sağdaki düğüme gider.
- Sağdaki düğüme bu 1 A ve akım kaynağından 5 A girer. Çıkan tek akım $R_3$'ten aşağı inen $i$'dir: $i = 1 + 5 = 6$ A.

### 10.2 Example-02: Tek düğüm

Soru (ekrandan, 01:00:00): tek bir düğüme $i_A$ ve $i_B$ giriyor, $i_C$, $i_D$ ve $i_E$ çıkıyor. KCL:

$$i_A + i_B - i_C - i_D - i_E = 0$$

(a) $i_A = 1$ A, $i_D = -2$ A, $i_C = 3$ A, $i_E = 4$ A ise $i_B$ nedir?

Burada ilk akla gelen soru eksi bir akımın nasıl olabileceğidir. Akımın önündeki işaret yönünü belirler: $i_D$ okuyla çizilmiş yönde $-2$ A, ters yönde çizilirse $+2$ A'dir. Akımın yönü değiştirilip işareti de değiştirilirse hiçbir şey değişmez.

Girenler çıkanlara eşittir: $1 + i_B = 3 + 4 + (-2)$, yani

$$i_B = -1 + 3 - 2 + 4 = 4\ \text{A}$$

$i_D$ ters çevrilip 2 A olarak giren akımlar tarafına yazılsa da sonuç yine 4 A çıkar. Sonuç $-4$ A çıksaydı, şekildeki $i_B$ okunun yanlış verildiği, akımın düğümden dışarı doğru 4 A olduğu söylenirdi; $-4$ A yazmak da yanlış değildir.

(b) $i_A = i_B = i_C = i_D = -1$ A ise $i_E$ nedir?

$$i_E = i_A + i_B - i_C - i_D = -1 - 1 + 1 + 1 = 0\ \text{A}$$

Giren ve çıkan akımlar birbirini götürdüğü için $i_E$ kolundan akım geçmez.

> **Hocanın vurgusu:** Devreler karmaşıklaşacak, düğüm sayısı artacak, ama mantık her zaman aynıdır: girenler çıkanlara eşittir ya da toplam sıfırdır.

### 10.3 Example-03: Kaynak akımı ve güç yönü

Soru (altyazıdan, 01:00:24): gerilim kaynağından çıkan akım soruluyor. Düğümden 3 mA çıkıyor; 0,5 mA, 1,9 mA ve kaynağın $I$ akımı giriyor. Çıkanlar eksi, girenler artı alınırsa:

$$-3 + 0{,}5 + 1{,}9 + I = 0 \Rightarrow I = 0{,}6\ \text{mA}$$

<!-- BELİRSİZ: Example-03'ün şekli karelerde yok. Değerler ve kaynağın polaritesi altyazıdan alındı (kaynağın artı ucu düğüm tarafında). -->

Akım 0,6 mA ve kaynağın artı ucundan çıkıyor. Artıdan çıkıp eksiye giren akımı olan kaynak güç üretir. Hoca, kaynakların hepsinin üretmek zorunda olmadığını hatırlatır: biri 9 V, biri 3 V olan ve ters bağlanmış iki pilde 9 V'luk pil üretir, 3 V'luk pil tüketir. $I$, $-0{,}6$ bulunsaydı akımın gerçek yönü ters olurdu, akım kaynağa artı ucundan girerdi ve kaynak güç tüketirdi (*dissipating*).

Hoca soruda verilen bir akım yönünün, aksi söylenmedikçe, o direnç üzerinde akımın girdiği uç artı olacak biçimde bir polarizasyon oluşturduğunu da belirtir.

### 10.4 Example-04: Eksi çıkan kaynak akımı

Soru (ekrandan, 01:05:00): $R_2$'den geçen akımın düğüme girdiği, $R_3$'ten geçen akımın düğümden çıktığı varsayılıyor. $R_2$'den 3 mA aşağı (düğüme) geliyor, $R_1$'den 0,5 mA giriyor, $R_3$'ten 1,9 mA çıkıyor, 3 V'luk $V_1$ kaynağından yukarı doğru $I$ geliyor. Hoca bunu önce öğrencilere sordu, bir öğrenci $-1{,}6$ cevabını verdi.

Girenler artı, çıkanlar eksi alınırsa (ekrandaki el yazısı):

$$3 + 0{,}5 - 1{,}9 + I = 0 \Rightarrow I = -1{,}6\ \text{mA}$$

Akım eksi çıktığı için gerçek yönü şekildeki okun tersidir: akım aşağı doğru 1,6 mA'dir. Bu durumda akım kaynağa artı ucundan girer, yani kaynak güç üretmez, tüketir. Gücü:

$$P = 1{,}6\ \text{mA} \times 3\ \text{V} = 4{,}8\ \text{mW}\ (\text{tüketilen})$$

> **Ders sonrası not:** Hoca bu gücü önce "5,8", sonra "4,8 watt" diye söyledi. Akım miliamper olduğu için doğrusu 4,8 mW'tır.

Bir gerilim kaynağının bu şekilde tüketen durumda olması şöyle açıklanır: devrenin üst taraflarında örneğin 100 V'luk başka bir kaynak olabilir; oradan gelen akımlar bu kaynağı tüketen konuma sokar.

> **Hocanın vurgusu:** Gerilim kaynağı denince akla hemen "güç üretiyordur" gelmemeli.

### 10.5 Example-05: Akım yerine gerilim düşümü verilmesi

Soru (ekrandan, 01:10:00): aynı düğümde bu kez akımlar yerine dirençlerin üzerindeki gerilim düşümleri verilmiş. $R_2 = 2\ \text{k}\Omega$ üzerinde 4 V (artı ucu üstte, düğümden uzak tarafta), $R_1 = 7\ \text{k}\Omega$ üzerinde 2 V (artı ucu düğüm tarafında), $R_3 = 5\ \text{k}\Omega$ üzerinde 1,75 V (artı ucu düğümden uzak tarafta). $R_3$'ün gerilim değeri karede bir etiketle kapalıdır, altyazıdan alınmıştır. Soruyu bir öğrenci tahtada çözdü.

Dirençte akım artı uçtan girer. Buna göre $R_2$ ve $R_3$'ün akımı düğüme girer, $R_1$'in akımı düğümden çıkar. Ohm yasasından $i = v/R$:

- $i_{R1} = 2\ \text{V} / 7\ \text{k}\Omega \approx 0{,}286$ mA (çıkan)
- $i_{R2} = 4\ \text{V} / 2\ \text{k}\Omega = 2$ mA (giren)
- $i_{R3} = 1{,}75\ \text{V} / 5\ \text{k}\Omega = 0{,}35$ mA (giren)

KCL:

$$2 + 0{,}35 + I = 0{,}286 \Rightarrow I \approx -2{,}06\ \text{mA}$$

Sonuç eksi olduğu için akımın gerçek yönü şekildekinin tersidir.

**Soru:** Dirençlerde akımın artı uçtan girdiğini söyleyebilmemizin nedeni dirençlerin tüketen eleman olması mı? **Cevap:** Evet. Ayrıca soruda dirençlerin polariteleri verilmiştir. Verilmeseydi, devrenin geri kalanı bilinmediği için akım yönünü buradan çıkarmak imkansız olurdu. Direnç tüketen eleman olduğu için akım artıdan girip eksiden çıkmak zorundadır.

## 11. Dirençler Her Zaman Tüketir mi?

Aradan sonra gelen bir soru üzerine hoca bu konuyu açar.

**Soru:** Dirençler her zaman tüketen mi olmak zorunda? **Cevap:** Evet, direnç adı üstünde tüketir. Ama bakış açısı, yani referans değişebilir.

Hoca bunu iki kaynaklı bir devreyle anlatır: bir döngüde 10 V'luk ve ters yönlü bağlanmış 5 V'luk iki kaynak olsun. İki kaynağın akımları birbirini kısmen söndürür. Hesap yapıldıktan sonra net (ana) akım, gerilimi büyük olan 10 V'luk kaynağın yönünde akar. Direncin polarizasyonu bu ana akıma göre belirlenir. İlk bakışta, hesaba girmeden, direnç kaynaklardan birine göre tüketmiyor gibi görünebilir, ama ana akıma göre tüketir. Bu yüzden dikkatli hesap yapmak gerekir.

## 12. KVL Örnekleri

KVL'de bir döngüdeki üretilen gerilimler tüketilen gerilimlere eşittir; ya da enerji anlamında üretilen enerji tüketilen enerjiye eşittir. KCL'de düğümü doğru bulmak nasıl önemliyse, KVL'de de döngüyü doğru bulmak önemlidir.

### 12.1 Example-06: Tek döngü

Soru (ekrandan, 01:25:00): iki ayrı devrede $v_x$ gerilimini ve $i_x$ akımını bulun. İki devrede de $i_x$ saat yönündedir.

**Sol devre:** 5 V'luk kaynak (artı ucu üstte), 7 V'luk kaynak (eksi ucu solda, artı ucu sağda) ve $100\ \Omega$'luk direnç (üstü artı). Saat yönünde giderken iki kaynağa da eksi ucundan girilir; ikisi aynı yönde kutuplanmıştır ve döngüde güç üretir. Direnç bu iki kaynağa ters polaritededir. Slayttaki çözüm (ekrandan, 01:30:00):

$$-5 - 7 + v_x = 0 \Rightarrow v_x = 12\ \text{V}, \qquad i_x = \frac{v_x}{100} = \frac{12}{100} = 120\ \text{mA}$$

**Sağ devre:** 3 V'luk kaynak (eksi ucu üstte, artı ucu altta), 1 V'luk kaynak (artı ucu solda, eksi ucu sağda) ve $10\ \Omega$'luk direnç (üstü artı). Saat yönünde giderken bütün elemanlara artı ucundan girilir. Hepsi artı alınırsa:

$$3 + 1 + v_x = 0 \Rightarrow v_x = -4\ \text{V}, \qquad i_x = \frac{-4}{10} = -0{,}4\ \text{A}$$

Gerilimin eksi çıkması, sorudaki $v_x$ polaritesinin ters verildiğini gösterir: direncin üzerinde 4 V birikir, ama alt ucu artıdır. Akım da saat yönünün tersine akar.

> **Ders sonrası not:** Hoca burada önce "10 ohm'a böldüğümüzde eksi 1 amper" dedi, sonra cevabı 400 mA olarak düzeltti. Doğrusu $-4\ \text{V}/10\ \Omega = -0{,}4$ A'dir.

**Soru:** Akımın yönünü ve polariteyi düzelttik değil mi? **Cevap:** $-4$ V yazmakta yanlış bir şey yoktur, yalnız akımın yönü okla gösterilen gibi değildir. Ok saat yönündeyse $i_x = -400$ mA yazılır; bu doğrudur. Ok ters çevrilirse 400 mA yazılır ve polarite de artı-eksi ters konarak 4 V yazılabilir. Yanlış olan, oku saat yönünde bırakıp "400 mA" yazmaktır, çünkü o yönde 400 mA'lik bir akım yoktur. Hoca bunu "eksi 10 kilo yoktur" benzetmesiyle açıklar: fiziksel büyüklüğün kendisi 400 mA'dir, eksi işareti yalnız yönü gösterir.

> **Hocanın vurgusu:** Akımı belirleyen iki şey vardır: büyüklüğü ve yönü (sağdan sola mı, soldan sağa mı). İkisi de önemlidir.

### 12.2 Example-07: Çok döngülü devre ve kara kutu

Soru (ekrandan, 01:35:00): devrede (a) $v_{R2}$, (b) $v_x$ bulunacak. Solda $c$ düğümüne inen ve üzerinde 4 V bulunan bir direnç (eksi ucu üstte, artı ucu altta), üstte 36 V'luk kaynak (eksi solda, artı sağda), ortada $R_2$ (üstü artı), sağda $+12\ \text{V}-$ olan bir direnç, $+14\ \text{V}-$ olan bir eleman (kara kutu), $a$ noktası, $-\ v_2\ +$ olan bir eleman, $v_{s1}$ kaynağı ve $R_1$ vardır; $a$ ile $b$ arasındaki gerilim $v_x$'tir.

Devrede üç döngü görülebilir: sol küçük döngü, sağ döngü ve dıştaki büyük döngü. $v_{R2}$'yi bulmak için sol döngü yeterlidir. Döngü yönü saat yönü seçilir; artıdan girilen eleman artı, eksiden girilen eleman eksi yazılır. Bu bir kabuldür, yani akımın yönünü kabul etmektir.

(a) Sol döngü (slayttaki denklem):

$$4 - 36 + v_{R2} = 0 \Rightarrow v_{R2} = 32\ \text{V}$$

(b) $a$ ve $b$ noktaları arasındaki gerilim sorulduğunda, noktaların sağındaki elemanları ($v_2$, $v_{s1}$, $v_{R1}$) tek tek çözmek gerekmez. Bunların hepsi bir kara kutu (ya da bir direnç) gibi düşünülür ve üzerindeki gerilim $v_x$ kabul edilir. Sağ döngüde de aynı yön ve aynı işaret kuralı kullanılır. $R_2$'ye bu kez eksi ucundan girildiği için $-32$ yazılır:

$$-32 + 12 + 14 + v_x = 0 \Rightarrow v_x = 6\ \text{V}$$

Sonuç artı çıktığı için soruda verilen polarite doğrudur.

> **Hocanın vurgusu:** Bir devrede döngüler için bir karar verildiyse (örneğin artıdan girilene artı, eksiden girilene eksi), devrenin bütün döngülerinde aynı işaret kuralı ve aynı yön kullanılmalıdır. Bir döngüde bir yön, ötekinde ters yön seçilemez. Sol döngüde tüketen konumda olan $R_2$, sağ döngüde eksi işaretiyle üreten konumda görünür. Bu yüzden "bütün dirençler tüketir, hepsine artı yazalım" denemez; işaret o anki döngüye ve akım yönüne göre değişir.

**Soru:** Döngülerde çizilen akım yönü aynı olmak zorunda mı? **Cevap:** Evet, iki döngüde de soldan sağa, saat yönünde alındı. Dıştaki büyük döngü de kullanılsaydı aynı yönde alınırdı.

### 12.3 Example-08: Eksi verilmiş gerilim

Soru (ekrandan, 01:40:00): (a) $v_{R2}$, (b) $v_{R1} = 1$ V ise $v_x$. Devre Example-07'ye benzer: sol direncin üzerinde $-8$ V verilmiş (eksi ucu üstte, artı ucu altta), üstte 12 V'luk kaynak (eksi solda, artı sağda), sağda $+7\ \text{V}-$ olan bir direnç, $-9\ \text{V}+$ olan bir eleman, $-\ v_2\ +$ olan eleman, 3 V'luk kaynak (eksi ucu üstte, artı ucu altta) ve $R_1$ (üstü artı).

İnce nokta şudur: sol direnç için soruda $-8$ V verilmiştir ve artıdan girildiği için değer işareti değiştirilmeden alınır. Bu, aslında üzerinde ters polariteli 8 V olduğu anlamına gelir.

(a) Sol döngü:

$$-8 - 12 + v_{R2} = 0 \Rightarrow v_{R2} = 20\ \text{V}$$

(b) Derste sağ taraftaki büyük döngü yazıldı. Hoca soruyu $v_2$'yi bulmak olarak ele aldı. $R_2$'ye eksiden girildiği için $-20$, 7 V'luk dirence artıdan girildiği için $+7$, 9 V'luk elemana eksiden girildiği için $-9$, $v_2$'ye eksiden girildiği için $-v_2$, 3 V'luk kaynağa eksiden girildiği için $-3$, $R_1$'e artıdan girildiği için $+1$:

$$-20 + 7 - 9 - v_2 - 3 + 1 = 0 \Rightarrow v_2 = -24\ \text{V}$$

Polaritenin işareti değiştirilmezse $v_2 = -24$ V yazılır; polarite ters çevrilirse 24 V yazılır. İkisi aynı şeydir.

> **Ders sonrası not:** Slayttaki (b) şıkkı $a$-$b$ arasındaki $v_x$'i soruyor; derste bunun yerine $v_2$ bulundu. $v_x$, $a$-$b$ noktalarının solundaki döngüden bulunabilir: $-20 + 7 - 9 + v_x = 0 \Rightarrow v_x = 22$ V. Sağ taraftan gidildiğinde de $v_x = -v_2 - 3 + v_{R1} = 24 - 3 + 1 = 22$ V çıkar (python ile kontrol edildi).

### 12.4 Example-09: KVL, Ohm yasası ve KCL birlikte

Soru (ekrandan, 01:45:00): devrede $v_x$'i bulun. Solda 60 V'luk kaynak, üstte 5 A'lik akımın geçtiği $8\ \Omega$ ($v_8$), ortada $10\ \Omega$ ($v_{10}$, $i_{10}$ aşağı), üstte $4\ \Omega$ ($v_4$, $i_4$ sağa), sağda $2\ \Omega$ ($i_2$ aşağı) ve en sağda $i_x$ akım kaynağı; $v_x$ akım kaynağının gerilimidir. Hoca soruyu öğrencilere bıraktı; bazı öğrenciler $+8$, bazıları $-8$ buldu. Bir öğrenci çözümü tahtada yaptı (ekrandan, 01:55:00).

- $8\ \Omega$'dan 5 A geçtiği için Ohm yasasından $v_8 = 5\times8 = 40$ V.
- Sol döngü: $60 - 40 - v_{10} = 0 \Rightarrow v_{10} = 20$ V.
- $i_{10} = 20/10 = 2$ A. Üst düğümde KCL: $i_4 = 5 - 2 = 3$ A.
- $v_4 = 3\times4 = 12$ V.
- Orta döngü: $20 - 12 - v_2 = 0 \Rightarrow v_2 = 8$ V (öğrenci tahtada bunu $V_4$ diye adlandırdı).
- Sağ döngü: $8 - v_x = 0 \Rightarrow v_x = 8$ V.

Öğrenci döngülerde eksiden girilen elemana artı, artıdan girilen elemana eksi yazdı; hocanın kuralının tersi olsa da bütün döngülerde tutarlı kullanıldığı için sonuç doğrudur.

Hoca son adımın aslında gerekmediğini söyler: akım kaynağı ile $2\ \Omega$ arasında başka bir direnç olmadığı için ikisi paraleldir ve $v_x$ doğrudan $2\ \Omega$'un gerilimine, yani 8 V'a eşittir. Arada bir direnç olsaydı gerilimin bir kısmı onun üzerinde kalırdı. Paralel ve seri devreler ileride ayrıca görülecektir.

$-8$ bulan bir öğrenci büyük döngüyü kullanmıştı. Kendi çözümünü anlatırken hatasını fark etti: $v_x$'e artıdan girildiği için denkleme $-v_x$ yazılır ve denklemden $v_x = 8$ çıkar; o ise denklemdeki eksi işaretini doğrudan sonuca taşımıştı. Hoca, denklemdeki eksinin yalnız seçilen yönden geldiğini, gerilimin değerinin işareti olmadığını vurgular. $v_x = -8$ diyebilmek için işaret kuralı uygulandıktan sonra denklemin çözümünün $-8$ çıkması gerekir.

### 12.5 Example-10: Paralel elemanın gerilimi

Soru (ekrandan, 02:00:00): $R_1$ ($1{,}8\ \text{k}\Omega$) üzerindeki $v_{R1}$ gerilimi soruluyor. Devrede 5 V'luk $V_1$ kaynağı, $R_1$ (polaritesi slaytta $-\ v_{R1}\ +$, yani eksi ucu solda), $R_2$ ($4{,}7\ \text{k}\Omega$) ve 0,2 mA'lik $I_1$ akım kaynağı vardır; akım kaynağının üzerindeki gerilim 3 V'tur (üstü artı).

Döngüler aynı yönde seçilir. Önce 5 V'luk kaynak, $R_1$ ve akım kaynağından geçen dış döngü kullanılabilir: 5 V'a eksiden girildiği için $-5$, $v_{R1}$'e eksiden girildiği için $-v_{R1}$, 3 V'a artıdan girildiği için $+3$ yazılır.

Slaytta "yeşil döngü" seçeneği de gösterilir: $R_2$ akım kaynağına paralel olduğu için onun da gerilimi 3 V'tur. Bu, $R_2$ ile akım kaynağından oluşan küçük döngüden de görülür: $-3 + 3 = 0$ olması için $R_2$'nin gerilimi kaynakla ters yönlü yazılmalıdır ve aralarında başka eleman yoktur. Yeşil döngü (5 V, $R_1$, $R_2$):

$$-5 - v_{R1} + 3 = 0$$

**Soru:** Küçük döngüde dirençteki gerilime eksi, kaynağınkine artı demek gerekmez miydi? **Cevap:** Akım kaynağının gerilimi ve polaritesi soruda verilmiştir. Dirence $x$ denirse, seçilen yöne göre $-x$, kaynağa artıdan girildiği için $+3$ yazılır: $-x + 3 = 0 \Rightarrow x = 3$ V. Buradaki eksi işareti seçilen yöndendir, değerin kendisi değildir. Dirence içerik olarak $-3$ V yazılırsa, eksi eksi artı yapar ve toplam 6 V olur; korunum sağlanmaz.

**Soru:** Akımın o yönde gittiğini nereden biliyoruz? **Cevap:** Bilmiyoruz, kabul ediyoruz. Her döngü için bir yön tayin edilir. Bütün elemanlara aynı kural uygulandığı için yön ters seçilse de matematik değişmez; yalnız bulunan akımın işareti değişir. Sonuç eksi çıkarsa ilk tayinin ters yapıldığı anlaşılır.

> **Ders sonrası not:** Slayttaki $-5 - v_{R1} + 3 = 0$ denkleminin çözümü $v_{R1} = -2$ V'tur, ama slaytta "$v_{R1} = 2$ V" yazıyor. Bir öğrenci cevabın $-2$ olup olmadığını sordu. Hoca önce 2 dedi, sonra slayttaki polariteyle ($-\ v_{R1}\ +$) değerin $-2$ V, ters polariteyle (artı ucu solda) 2 V olduğunu kabul etti. Yani $R_1$ üzerinde 2 V vardır ve artı ucu kaynak tarafındadır.

### 12.6 Example-11: Gerilim ve akımın birlikte bulunması

Soru (ekrandan, 02:10:00): $R_2$ üzerindeki gerilimi ve $R_2$'den geçen akımı bulun. Devrede 11,5 V'luk $V_1$ kaynağı, üzerinde $+2{,}4\ \text{V}-$ olan $R_1$, $R_2 = 4{,}7\ \text{k}\Omega$ ($v_{R2}$, üstü artı), $R_3 = 1{,}1\ \text{k}\Omega$ ve 1 mA'lik $I_1$ akım kaynağı (üzerinde 8 V, üstü artı) vardır. Hoca soruyu öğrencilere bıraktı; sonucu yaklaşık 9,1 olarak verdi ve bir öğrenci sol döngüyü tahtada çözdü.

Sol döngüde kaynak gerilimi, $R_1$'in gerilimi ve $R_2$'nin gerilimi polaritelerine göre yazılır:

$$11{,}5 - 2{,}4 - v_{R2} = 0 \Rightarrow v_{R2} = 9{,}1\ \text{V}$$

Sağ döngü ("mavi döngü") ile de aynı sonuç bulunur (ekrandan, 02:15:00). Önce $R_3$ üzerindeki gerilim bulunur:

$$1\ \text{mA}\times1{,}1\ \text{k}\Omega = 1\times10^{-3}\ \text{A}\times1{,}1\times10^{3}\ \Omega = 1{,}1\ \text{V}$$

Soruda $R_3$'ün polaritesi verilmemiştir; akım kaynağının yönüne göre seçilen akım yönüyle $R_3$'e girilen uç artı kabul edilir. Döngü denklemi:

$$-v_{R2} + v_{R3} + 8 = 0 \Rightarrow v_{R2} = 1{,}1 + 8 = 9{,}1\ \text{V}$$

$R_2$'nin akımı Ohm yasasıyla bulunur:

$$i_{R2} = \frac{9{,}1\ \text{V}}{4{,}7\ \text{k}\Omega} \approx 1{,}94\ \text{mA}$$

Hoca ek olarak üst düğümde KCL uygular: 1,94 mA aşağı iniyor ve 1 mA akım kaynağına gidiyorsa, $R_1$'den gelen ana koldaki akım $1{,}94 + 1 = 2{,}94$ mA'dir.

Kilo ve mili önekleri önemlidir: $\text{k} = 10^{3}$, $\text{m} = 10^{-3}$; çarpıldıklarında üsler birbirini götürür ve 1,1 V kalır.

Hoca polarite kuralını özetler: soruda polarite verilmemişse kabul edilen akım yönüne göre bütün elemanlar polarize edilir; akımın girdiği uç artı olur. Soruda polarite verilmişse (Example-10'daki $v_{R1}$ gibi) ona dokunulmaz.

## 13. Ders Sonu Soru-Cevap: Kısa Devrede Akım

**Soru:** Gerilimi olan bir pili dirençsiz bir devreye bağladığımızda gerilim sıfırlanıyor; bu, akımın sonsuz olmasından mı kaynaklanıyor? **Cevap:** Hoca önce soruyu, kaynağın hiçbir elemana bağlı olmadığı, havada tutulan bir pil gibi anladı: tüketen eleman yoksa akım da oluşmaz, bu açık devredir. Öğrenci kısa devreyi sorduğunu belirtince hoca şunu söyledi: direnci olmayan bir yola bağlamak kısa devredir. $i = v/R$'de $R$ sıfıra götürülürse akım maksimuma, teorik olarak sonsuza gider. Gerçekte direnci tam sıfır olan bir devre yoktur. Direnci sonsuz olan devrelerde ise akım sıfırdır.

## Örnek Sorular

Aşağıdaki sorular derste slaytta gösterilip çözülen sorulardır.

**1. Terminoloji alıştırması** (ekrandan, 00:45:00). $A$-$B$-$C$-$F$-$G$ üst, $E$-$D$ alt düğümlü devrede: (a) eleman sayısı, (b) $B\to C\to D$ yol mu döngü mü, (c) $E\to D\to C\to B\to E$ yol mu döngü mü?

> **Çözüm:** (a) 5 direnç + 1 kaynak = 6 eleman. (b) Yol. (c) Döngü.

**2. Example-01** (ekrandan, 00:55:00). 10 V'luk kaynak 3 A veriyor, $R_2$'den 2 A iniyor, sağda 5 A'lik akım kaynağı var. $R_3$'ün akımı nedir?

> **Çözüm:** $3 - 2 = 1$ A, $i = 1 + 5 = 6$ A.

**3. Example-02** (ekrandan, 01:00:00). $i_A + i_B - i_C - i_D - i_E = 0$ olan tek düğümde (a) $i_A = 1$, $i_D = -2$, $i_C = 3$, $i_E = 4$ A için $i_B$; (b) $i_A = i_B = i_C = i_D = -1$ A için $i_E$.

> **Çözüm:** (a) $i_B = 4$ A. (b) $i_E = 0$ A.

**4. Example-04** (ekrandan, 01:05:00). $R_2$'nin 3 mA'i düğüme giriyor, $R_3$'ün 1,9 mA'i çıkıyor, $R_1$'den 0,5 mA giriyor. 3 V'luk kaynaktan gelen $I$ nedir, kaynak üretiyor mu?

> **Çözüm:** $I = -1{,}6$ mA; akım kaynağa artı ucundan girer, kaynak 4,8 mW tüketir.

**5. Example-05** (ekrandan, 01:10:00). $R_1 = 7\ \text{k}\Omega$ (2 V), $R_2 = 2\ \text{k}\Omega$ (4 V), $R_3 = 5\ \text{k}\Omega$ (1,75 V, altyazıdan) verildiğinde $I$ nedir?

> **Çözüm:** $I = 0{,}286 - 2 - 0{,}35 \approx -2{,}06$ mA.

**6. Example-06** (ekrandan, 01:25:00). İki tek döngülü devrede $v_x$ ve $i_x$.

> **Çözüm:** Sol: $v_x = 12$ V, $i_x = 120$ mA. Sağ: $v_x = -4$ V, $i_x = -0{,}4$ A.

**7. Example-07** (ekrandan, 01:35:00). $v_{R2}$ ve $v_x$.

> **Çözüm:** $v_{R2} = 32$ V, $v_x = 6$ V.

**8. Example-08** (ekrandan, 01:40:00). $v_{R2}$ ve $v_{R1} = 1$ V iken $v_x$.

> **Çözüm:** $v_{R2} = 20$ V. Derste $v_2 = -24$ V bulundu.

> **Çözüm (derste verilmedi):** Slayttaki asıl soru olan $v_x$ için sol döngüden $-20 + 7 - 9 + v_x = 0 \Rightarrow v_x = 22$ V (python ile kontrol edildi).

**9. Example-09** (ekrandan, 01:45:00). 60 V, $8\ \Omega$ (5 A), $10\ \Omega$, $4\ \Omega$, $2\ \Omega$ ve akım kaynağından oluşan devrede $v_x$.

> **Çözüm:** $v_{10} = 20$ V, $i_4 = 3$ A, $v_4 = 12$ V, $v_2 = 8$ V, $v_x = 8$ V.

**10. Example-10** (ekrandan, 02:00:00). 5 V'luk kaynak, $R_1 = 1{,}8\ \text{k}\Omega$, $R_2 = 4{,}7\ \text{k}\Omega$ ve üzerinde 3 V olan 0,2 mA'lik akım kaynağından oluşan devrede $v_{R1}$.

> **Çözüm:** $-5 - v_{R1} + 3 = 0 \Rightarrow v_{R1} = -2$ V (slayttaki polariteyle); $R_1$ üzerinde 2 V vardır ve artı ucu kaynak tarafındadır.

**11. Example-11** (ekrandan, 02:10:00). $R_2$'nin gerilimi ve akımı.

> **Çözüm:** $v_{R2} = 9{,}1$ V, $i_{R2} \approx 1{,}94$ mA; $R_1$ akımı $2{,}94$ mA.

## Dersin Toparlaması

Bu derste önce devre teorisinin temel büyüklükleri tekrarlandı: akım yönü, güç işareti, malzemelerin özdirenci, $R = \rho L/A$, Ohm yasası, kısa ve açık devre, iletkenlik ve gücün farklı biçimleri. Ardından düğüm, yol, döngü ve kol terimleri tanımlandı ve Kirchhoff'un iki yasası verildi: KCL yükün korunumuna dayanır ve düğümlerde giren akımların çıkan akımlara eşit olduğunu söyler; KVL enerjinin korunumuna dayanır ve bir döngüdeki gerilimlerin cebirsel toplamının sıfır olduğunu söyler.

Örneklerin ortak dersi işaret ve polarite yönetimidir. Akımın ya da gerilimin eksi çıkması, seçilen yönün ya da verilen polaritenin ters olduğunu gösterir; büyüklük ve yön birlikte doğru yazılmalıdır. Döngülerde tek bir yön ve tek bir işaret kuralı bütün devrede tutarlı kullanılmalı, soruda verilen polariteler değiştirilmemelidir. Paralel elemanların aynı gerilime sahip olması ve iki nokta arasındaki gerilimin "kara kutu" yaklaşımıyla bulunması çözümü kısaltır. Hoca seri ve paralel devre analizinin ve birbirini söndüren kaynaklı devrelerin ileriki derslerde ayrıca işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
