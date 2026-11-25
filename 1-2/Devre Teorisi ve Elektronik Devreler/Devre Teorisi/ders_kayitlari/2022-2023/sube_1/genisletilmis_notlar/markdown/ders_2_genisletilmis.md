# Ders 2 Genişletilmiş Notu: Güç İşareti, Ohm Yasası ve Kirchhoff Yasaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Akım, Gerilim, Güç ve Enerji Tanımlarının Tekrarı
- 2. Güç İşareti ve Referans Yönleri
- 3. Enerjinin Korunumu ve Akım Referans Yönü Seçimi
- 4. Ohm Yasası
- 5. Direnç, Öz Direnç ve İletkenlik
- 6. Düğüm, Yol, Çevrim ve Dal
- 7. Kirchhoff Akım Yasası (KCL)
- 8. Kirchhoff Gerilim Yasası (KVL)
- 9. KCL Örnekleri
- 10. KVL Örnekleri
- 11. Tek Çevreli Devreler ve Güç Dengesi
- 12. Bağımlı Kaynaklı Tek Çevreli Devreler
- 13. Tek Düğüm Çiftli Devreler
- Örnek Sorular
- Dersin Toparlaması

## 1. Akım, Gerilim, Güç ve Enerji Tanımlarının Tekrarı

Ders, bir önceki haftada tanımlanan temel büyüklüklerin kısa bir tekrarıyla başladı.

**Akım**, birim zamandaki net yük değişimidir. Ayrık gösterimde $i = \Delta q / \Delta t$, sürekli gösterimde $i = dq/dt$ olarak yazılır. $\Delta t$ sürede $\Delta q$ kadar net yük geçmişse akım bu oranla verilir.

**Gerilim (potansiyel fark)**, yükü hareket ettiren elektromotor kuvvettir. Birim yüke 1 joule enerji kazandıracak potansiyel farka 1 volt denir (ekrandan, 00:05:00):

$$1\ \text{V} = \frac{1\ \text{J}}{1\ \text{C}}, \qquad v = \frac{dw}{dq}$$

**Güç**, birim zamanda harcanan enerjidir: $p = dw/dt$. İfade $dq$ ile çarpılıp bölünürse iki tanıdık terim ortaya çıkar:

$$p = \frac{dw}{dt} = \frac{dw}{dq}\cdot\frac{dq}{dt} = v\,i$$

İlk terim birim yüke aktarılan enerji, yani gerilimdir. İkinci terim birim zamandaki net yük, yani akımdır. Bu yüzden devre teorisinde bir elemanın gücü, uçları arasındaki gerilim farkı ile içinden akan akımın çarpımıdır. Birimi watt'tır ve $1\ \text{W} = 1\ \text{V}\cdot\text{A}$ olarak da yazılabilir.

**Enerji**, belirli bir zaman aralığında harcanan toplam güçtür, yani gücün o aralıktaki integralidir: $w = \int p\,dt$.

## 2. Güç İşareti ve Referans Yönleri

Doğru referans yönleriyle hesaplanan güç pozitifse eleman **güç tüketir** (absorbe eder). Negatifse eleman devreye **güç sağlar**. Hoca burada geçen haftaki bir uyarıyı tekrarladı: Bir gerilim ya da akım kaynağının gücü de pozitif çıkabilir. Kaynak olması gücünün her zaman negatif olacağı anlamına gelmez. En iyi örnek şarj edilen bir pildir.

### 2.1 Ölçü aletlerinin bağlanması

- **Ampermetre** elemana seri bağlanır. Bütün akım üzerinden geçmeli ki kolun akımını gerçekten ölçebilsin. Bu yüzden ideal ampermetre kısa devre gibi davranır, iç direnci sıfırdır.
- **Voltmetre** elemana paralel bağlanır. Ölçtüğü elemandan hiç akım çekmemeli ki gerçek gerilim düşümünü görebilsin. Bu yüzden ideal voltmetre açık devre gibi davranır, iç direnci sonsuzdur.
- İki alette de kırmızı prob artı, siyah prob eksi uçtur. Ölçülen değerin işareti bu bağlantı yönüne göredir.

### 2.2 Ölçümle güç hesabı

Bir elemanın kolundan, ampermetrenin artı ucundan eksi ucuna doğru 1 A okunsun. Voltmetre de elemanın uçlarına bağlansın ve 1 V okusun (ekrandan, 00:10:00).

- Akım, elemanın gerilim referansının artı ucundan giriyorsa güç $(1\ \text{A})(1\ \text{V}) = +1$ W'tır.
- Aynı elemanda voltmetre ters bağlanırsa $-1$ V okunur. Ama akım bu kez referansın eksi ucundan girmektedir. Bu yüzden bir eksi daha gelir ve sonuç yine $+1$ W olur. Yani ölçü aletinin nasıl bağlandığı fiziksel sonucu değiştirmez; önemli olan hesabın seçilen referans yönlerine uygun yapılmasıdır.

Slaytta bu iki durum "**Bir elemanın tükettiği güç pozitiftir: $P = +1$ W**" başlığıyla gösterildi (ekrandan, 00:10:00). Sonraki slaytta ise "**Üretilen gücün işareti negatiftir: $P = -1$ W**" durumları vardı (ekrandan, 00:15:00). Orada akım, elemanın gerilim referansının eksi ucundan girmekte ve o yöndeki gerilim 1 V'tur. Akım yönünde bakıldığında gerilim düşümü $-1$ V olduğundan:

$$p = (-1\ \text{V})(1\ \text{A}) = -1\ \text{W}$$

Bu elemanlar devreye güç sağlar, önceki elemanlar ise güç tüketir.

> **Hocanın vurgusu:** Güç hesabında alınan akım ve gerilim referans yönlerine mutlaka dikkat edilmelidir. Hesap bu yönler üzerinden yapılır.

### 2.3 Ölçüm yönü ve işaret

Bir elemana voltmetre bağlanıp artı ucu üstte 2 V okunsun. Voltmetre ters bağlanırsa $-2$ V okunur. İki okuma da aynı şeyi söyler: üst düğüm alt düğümden 2 V daha yüksek potansiyeldedir. Benzer şekilde, dışarı doğru 1 A okunan bir akım, içeri doğru $-1$ A okunmasıyla aynıdır.

Özetle, akım ve gerilim referans yönleri uyumluysa (akım gerilim referansının artısından girip eksisinden çıkıyorsa) $p = v\,i$ yazılır. Bu yönlerle hesaplanan $i$ negatif çıkarsa, değer olduğu gibi yerine konur. Sonuç negatifse eleman verilen yönler için negatif güce sahiptir, yani devreye enerji verir. Kısaca, $v\,i$ hesabında güç pozitifse eleman devreden güç tüketir, negatifse devreye güç sağlar.

## 3. Enerjinin Korunumu ve Akım Referans Yönü Seçimi

### 3.1 Kapalı sistemde güç dengesi

Bir devre bir sistem gibi düşünülebilir: gözleri, bağlantıları, dirençleri, gerilim ve akım kaynakları vardır. Çizilen şeklin dışından bir girdi almıyor ve dışarıya bir çıktı vermiyorsa bu bir **kapalı sistemdir**. İdeal durumda kapalı bir sistemde üretilen güç tüketilen güce eşittir. Bu yüzden devreye sağlanan güç ile devrede tüketilen güçlerin cebirsel toplamı sıfır olmalıdır.

Bu sayede, dört komponentli bir devrede üç komponentin gücü biliniyorsa dördüncünün gücü toplamın sıfır olması koşulundan bulunabilir. Hoca, bunun devre çözümlerinde kullanılacak bir yöntem olduğunu söyledi.

### 3.2 Akım referans yönü

Bir gerilim kaynağı ile bir dirençten oluşan basit bir devrede akımın yönü doğrudan söylenebilir: akım kaynağın pozitif ucundan çıkıp dirence doğru akar (ekrandan, 00:20:00: 1 V kaynak ve 1 Ω dirençli basit DC devre). Daha karmaşık devrelerde ise her kola bir **akım referans yönü** kendimiz atarız; herhangi bir yön seçilebilir.

Devre çözüldükten sonra:

- akım pozitif çıkarsa gerçek akım seçilen yöndedir;
- negatif çıkarsa gerçek akım seçilen yönün tersindedir.

İkisi aynı bilgiyi taşır: bir kolda "bu yönde 1 A" demekle "ters yönde $-1$ A" demek eşdeğerdir. Gerilim düşümlerinin yönleri de seçilen akım yönüne göre kendiliğinden belirlenir. Çözümden sonra akım negatifse, akımın o kolda seçilen yönün tersine aktığı not edilir.

## 4. Ohm Yasası

### 4.1 Deneyle Ohm yasası

Sabit bir direnç seçilip bir gerilim kaynağıyla beslendiğinde, gerilim artırıldıkça direnç değişmez ama akım değişir. Akımdaki değişim gerilimdeki değişimle doğru orantılıdır. Deneyi bilimsel olarak yürütmek için:

1. sabit bir direnç seçilir,
2. gerilim belirli bir aralıkta değiştirilir ve akım değerleri not edilir,
3. deney birkaç farklı direnç için tekrarlanır,
4. her direnç için elde edilen grafiğin eğimine bakılır.

Hoca deneyin $I$-$V$ grafiğini tahtada çizdi (ekrandan, 00:25:00). Ölçüm noktaları tam bir doğru üzerinde olmayabilir, ama kabaca bir doğru oturtulabilir; ilişki doğrusaldır. Bu doğrunun eğimi sabittir:

$$\tan\alpha = \frac{\Delta I}{\Delta V} = \text{sabit} = \frac{1}{R_1}$$

Aynı deney $R_2$ direnciyle tekrarlandığında da sıfırdan geçen bir doğru elde edilir ve eğimi $1/R_2$'dir. $R_2$ doğrusunun eğimi daha küçükse, aynı gerilim değişimine daha az akım değişimi karşılık gelir; bu durumda $R_2$ daha büyüktür.

Sezgi için hoca bir su benzetmesi kullandı: Kablolar dirençsiz borular, direnç ise akışa karşı koyan bir darboğazdır. Gerilim arttıkça su basıncı artar ve akış hızlanır, yani akım artar. Direnç arttıkça darboğaz daralır ve akım azalır.

Slayttaki ifade (ekrandan, 00:25:00):

$$V = IR \qquad (\text{yalnız direnç elemanı için})$$

Slaytta ayrıca küçük bir örnek vardı: $2\ \Omega$'luk bir dirençten 2 A akıyorsa akımın girdiği uç $x + 4$ V, çıktığı uç $x$ V'tur. Uçların mutlak değeri bilinmese de aralarındaki fark $2 \cdot 2 = 4$ V'tur. Slaytta ayrıca "teorik olarak elektrik telinin direnci 0 Ω'dur" notu bulunuyordu.

### 4.2 Akım ve gerilimin taşınması

Tek gözlü bir devrede akım bütün noktalarda aynıdır. Gerekçe yine net yük değişimidir: devrenin küçük bir parçası etrafına kapalı bir sınır çizilsin ve bu sınıra 1 A girsin. İçeride kaynak yoksa çıkan akım da 1 A olmalıdır. Bu sınır sonsuz küçültülüp devrenin her noktasına taşınırsa her noktada 1 A akım olduğu görülür.

Gerilim ise iki nokta arasındaki fark olarak, bir referansa göre tanımlanır. 1 V kaynak ve 1 Ω dirençten oluşan devrede kaynağın eksi ucu 0 V referans seçilsin. Kaynağın artı ucu 1 V'tur. Dirençsiz tel boyunca başka bir elemana rastlanmadıkça bu 1 V dirence kadar taşınır. Telin iki noktası arasında gerilim düşümü yoktur. Direnç üzerinde voltmetreyle 1 V'luk düşüm okunur. Referans 0 V seçildiği için direncin üst ucu "1 V'tadır" da denebilir.

### 4.3 Kopuk devre (ekrandan, 00:30:00)

Aynı devrede direncin kaynak tarafındaki bağlantısı koparılsın. Kaynağın artı ucu 1 V'tur. Direncin kolunda akım oluşturacak bir yol yoktur, akım 0 A'dır. Akım yoksa direnç üzerinde gerilim düşümü de yoktur, bu yüzden direncin alt ucundaki 0 V üst ucuna aynen taşınır ve direncin açık ucu 0 V'tadır.

Bu kez direncin referans (0 V) tarafındaki bağlantısı koparılsın. Kaynak ve ona bağlı tel 1 V'tadır. Direnç bu potansiyeli düşürebileceği bir referansa bağlı değildir, kolda akım akmaz. Akım sıfır olduğu için direnç üzerinde düşüm yoktur ve direncin açık ucu da 1 V'tadır. Hoca mantık sırasını özellikle vurguladı: önce akımın sıfır olduğu görülür, bu yüzden gerilim düşümü olmadığı sonucuna varılır.

## 5. Direnç, Öz Direnç ve İletkenlik

Bu kısım ikinci slayt grubunun başıdır (ekrandan, 00:35:00: "Ohm's Law, Kirchhoff's Current Law (KCL), Kirchhoff's Voltage Law (KVL)").

### 5.1 Direncin bağlı olduğu büyüklükler

Bir elemanın uçlarına uygulanan gerilime karşı akımın nasıl değişeceği üç şeye bağlıdır: malzemenin kendine özgü özellikleri (öz direnç), elemanın uzunluğu ve kesit alanı, uygulanan gerilim.

Malzemelerin öz dirençleri çok farklıdır. Metallerde çok küçüktür, bu yüzden metaller iletkendir. Yarı iletkenlerde görece yüksek, yalıtkanlarda ise çok çok yüksektir. <!-- BELİRSİZ: Hocanın gösterdiği öz direnç tablosunun sayısal değerleri karelerde görülmedi. --> Malzeme seçimi kullanım amacına göre yapılır. Isıdan doğan verim kayıplarını önlemek için yüksek iletkenlikli malzeme istenir; örneğin bazı konektörlerin uçları altınla kaplanır. Yüksek gerilim hatlarını zeminden ya da telleri birbirinden yalıtmak için ise çok yüksek yalıtkanlıkta malzeme gerekir. Yani yalıtkan olmak kötü, iletken olmak iyi demek değildir.

Direnç şöyle hesaplanır:

$$R = \rho\,\frac{L}{A}$$

Malzeme uzadıkça direnç artar, çünkü akım daha uzun bir darboğazdan geçer. Kesit alanı büyüdükçe direnç azalır.

### 5.2 Birimler

Ohm yasasından $V = IR$ olduğu için volt aynı zamanda amper·ohm olarak yazılabilir. Akım birim zamandaki net yük olduğundan amper de coulomb/saniyedir.

> **Ders sonrası not:** Altyazıda bu kısım "gerilim değerimizi coulomb bölü saniye olarak da verebiliriz" diye geçiyor. Coulomb/saniye akımın birimidir; büyük olasılıkla kastedilen $1\ \text{V} = 1\ \text{A}\cdot\Omega = 1\ (\text{C/s})\cdot\Omega$ ifadesidir.

### 5.3 Uç durumlar: kısa devre ve açık devre

**Kısa devre ($R = 0$).** Direnci sıfır olan eleman mükemmel bir iletkendir, ideal bir kablo gibi davranır. Üzerinden ne kadar akım geçerse geçsin uçları arasında gerilim düşümü olmaz (ekrandan, 00:40:00):

$$R = 0\ \Omega \;\Rightarrow\; v = iR = 0\ \text{V}$$

Direnci sıfırdan farklı olsaydı, akım arttıkça gerilim düşümü de artardı. Gerilim sıfır olduğundan kısa devre elemanı güç harcamaz.

**Açık devre ($R = \infty$).** Direnci sonsuz olan elemandan akım akamaz. İdeal voltmetre böyledir; teli kopartılmış gibi davranır. Uygulanan gerilim ne kadar artırılırsa artırılsın akım her zaman sıfırdır, bu yüzden açık devre de güç harcamaz.

### 5.4 İletkenlik

Direncin tersi **iletkenlik**tir. Birimi siemens'tir (S); ters yazılmış ohm işaretiyle (℧, "mho") de gösterilir.

$$G = \frac{1}{R} = \sigma\,\frac{A}{L}, \qquad \sigma = \frac{1}{\rho}$$

İletkenlik işlem kolaylığı için tanımlanır. İleride görülecek yöntemlerden bazıları (çevre akımları) akımlar ve dirençlerle çalışır. Bazıları ise (düğüm gerilimleri) her düğüme giren net akımlarla çalışır; orada her düğümün gerilimi hesaplanır ve $G$ kullanmak pratiktir. Seri dirençlerde toplam direnç aritmetik toplamla bulunur. Paralel elemanlarda toplam akımı bulmak için iletkenlikler aritmetik olarak toplanır. $G$ tanımlanmasaydı paralel kollarda $1/R$'lerle uğraşmak gerekirdi. $R$ ve $G$ her zaman pozitif gerçel sayılardır.

### 5.5 Dirençte harcanan güç (ekrandan, 00:45:00)

$v = iR$, $i = v/R$, $v = i/G$ ve $i = vG$ bağıntıları $p = iv$ içine konunca dört eşdeğer ifade çıkar:

$$p = iv = i(iR) = i^2R$$
$$p = iv = (v/R)\,v = v^2/R$$
$$p = iv = i(i/G) = i^2/G$$
$$p = iv = (vG)\,v = v^2G$$

İdeal direncin karakteristik eğrisi belirli eğimli bir doğrudur. İdeal olmayan elemanlarda gerilim artırıldıkça akım aynı oranda artmayabilir. <!-- BELİRSİZ: Hoca ideal olmayan elemanlarda enerjinin bir kısmının ısıya dönüştüğünden söz ediyor; altyazıda cümle kesik. --> Kısa devre elemanında gerilim, açık devre elemanında akım sıfır olduğu için ikisinin de harcadığı güç sıfırdır.

## 6. Düğüm, Yol, Çevrim ve Dal

- **Düğüm (node):** İki ya da daha fazla elemanın birleştiği nokta. Bir düğüm tel boyunca kaydırılabilir; bir başka elemanın sınırına kadar taşınabilir ve topoloji değişmez. Ama bir elemanın üzerinden atlayamaz; atlarsa farklı bir düğüm olur. Örnek devrede bir numaralı düğüme akım kaynağı ile $R_1$, $R_2$ ve $R_3$ dirençlerinin birer ucu bağlıdır; devrede üç tekil düğüm vardır.
- **Yol (path):** Herhangi iki düğüm arasında izlenebilen geçiş. Birden fazla düğüm ve eleman içerebilir, ama kapalı bir çevrim içeremez.
- **Çevrim (loop):** Bir düğümden başlayıp elemanlardan geçtikten sonra aynı düğümde biten yol.
- **Dal (branch):** Başlangıç ve bitiş noktaları arasında yalnız bir eleman bulunan yol.

### 6.1 Alıştırma (ekrandan, 00:50:00)

Devre şöyledir:

| Eleman | Bağlı olduğu düğümler |
|---|---|
| Gerilim kaynağı | A (artı) – E (eksi, alt tel) |
| Direnç | A – B |
| Direnç | B – E |
| Direnç | B – C |
| Direnç | C – D |
| Direnç | F – D |

C, F ve G aynı üst tel üzerindedir (G açık uçtur). D ve E aynı alt tel üzerindedir.

- **a. Eleman sayısı:** 6 (1 kaynak, 5 direnç).
- **Tekil düğüm sayısı:** 4. Bunlar {A}, {B}, {C, F, G} ve {D, E}'dir.
- **b. B→C→D:** Bir yoldur. Kapalı çevrim içermediği için çevrim değildir.
- **c. E→D→C→B→E:** Başladığı düğümde bittiği için hem yol hem çevrimdir.

Hoca ayrıca, bir çevrimin içinden başka elemanlarla kesilmemesinin şart olmadığını belirtti. Önemli olan başlanan düğüme geri dönmektir. D ve E eşdeğer düğümler olduğu için E-B-C-D de bir çevrimdir.

## 7. Kirchhoff Akım Yasası (KCL)

Bir düğüm etrafına kapalı bir sınır çizilsin. İçeride bağımsız bir kaynak ya da biriken yük yoksa, sınıra giren akımlar ile çıkan akımların cebirsel toplamı sıfır olmalıdır. Genelde düğüme giren akımlar pozitif, çıkanlar negatif alınır. $i_A$ ve $i_B$ giren, $i_C$ ve $i_D$ çıkan akımlar ise:

$$i_A + i_B - i_C - i_D = 0$$

İşaretler ters seçilirse (girenler negatif, çıkanlar pozitif) bütün terimler karşı tarafa atılmış olur; sonuç değişmez. Aynı yasa "**giren akımlar toplamı çıkan akımlar toplamına eşittir**" diye de yazılabilir:

$$i_A + i_B = i_C + i_D$$

Üç gösterim de aynı şeyi ifade eder.

## 8. Kirchhoff Gerilim Yasası (KVL)

KVL enerjinin korunumuna dayanır. Bir çevrim boyunca elemanlar üzerindeki gerilim düşümlerinin cebirsel toplamı sıfırdır. Bir yükü A noktasından B noktasına götürmek için gereken enerji seçilen yoldan bağımsızdır (ekrandan, 00:55:00):

$$\sum_{m=1}^{M} v_m = 0 \quad (M:\ \text{çevrimdeki dal sayısı}), \qquad \sum v_{\text{düşüm}} = \sum v_{\text{yükseliş}}$$

Sezgisi şöyledir: B noktasından belirli bir potansiyelle başlanır. Elemanlardan geçerken gerilim düşümleri ve yükselişleri yaşanır, sonunda yine B'ye dönülür. Başlangıç ve bitiş aynı nokta olduğundan aradaki net potansiyel fark sıfır olmalıdır.

Slayttaki örnekte üç eleman vardır: $v_1$ (eleman 1, A-B arasında, artısı üstte), $v_2$ (eleman 2, A-C arasında, artısı A tarafında) ve $v_3$ (eleman 3, C-B arasında, artısı altta). Hoca çevrime bir akım yönü verdi ve o yönde düşümleri topladı. Eleman 2'ye artı ucundan girildiği için $+v_2$ yazılır. Eleman 3'e ve eleman 1'e eksi ucundan girildiği için $-v_3$ ve $-v_1$ yazılır:

$$-v_1 + v_2 - v_3 = 0$$

Dolaşım yönü ters seçilirse denklem $v_1 - v_2 + v_3 = 0$ olur. Bu, aynı denklemin terimlerini karşı tarafa atmaktır; sonuç değişmez.

### 8.1 Kaynakların tanım bağıntıları

Devre çözerken kaynakların şu özellikleri kullanılır:

- **Akım kaynağı** devreye kendi yönünde sabit bir akım sağlar. Uçlarındaki gerilimi devrenin geri kalanı belirler.
- **Gerilim kaynağı** uçları arasında üzerinde yazan potansiyel farkı sağlar. İçinden geçen akımı devrenin geri kalanı belirler.
- Kaynaklar için ayrıca gerilim referans yönü tanımlamaya gerek yoktur; kaynağın kendi artı ve eksi işaretleri kullanılır.

## 9. KCL Örnekleri

### 9.1 Kaynak akımı verilen devre (ekrandan, 01:00:00)

Soldan sağa devre şöyledir: 10 V gerilim kaynağı, üst kolda seri $R_1$, sonra üst düğümden toprağa inen $R_2$ ve $R_3$, en sağda yukarı doğru 5 A akım kaynağı. Gerilim kaynağının 3 A sağladığı bilinmektedir. $R_2$'den aşağı 2 A geçer. $R_3$'ten aşağı geçen $i$ istenmektedir.

$R_2$ ve $R_3$'ün üst uçları aynı düğümdür. Bu düğüme $R_1$ üzerinden 3 A ve akım kaynağından 5 A girer; $R_2$'den 2 A ve $R_3$'ten $i$ çıkar:

$$3 - 2 - i + 5 = 0 \;\Rightarrow\; i = 3 - 2 + 5 = 6\ \text{A}$$

Hoca, "kaynak 3 A sağlıyor" bilgisinin bu devreye özgü olduğunu söyledi. Farklı bir devrede gerilim kaynağının akımı farklı olurdu, çünkü onu devrenin geri kalanı belirler.

### 9.2 Beş kollu düğüm

Bir düğüme $i_A$ ve $i_B$ giriyor; $i_C$, $i_D$ ve $i_E$ çıkıyor. Denklem önce verilen referans yönlerine göre kurulur:

$$i_A + i_B - i_C - i_D - i_E = 0$$

a şıkkında $i_A = 1$ A, $i_C = 3$ A, $i_D = -2$ A ve $i_E = 4$ A verilmiştir, $i_B$ istenir. $i_D$'nin işareti negatif diye yönünü çevirmeye gerek yoktur, çünkü denklem zaten bu referans yönüne göre kurulmuştur. Değer işaretiyle konur:

$$i_B = i_C + i_D + i_E - i_A = 3 + (-2) + 4 - 1 = 4\ \text{A}$$

İkinci şıkta $i_E$ istenmiş ve sonucu $0$ A çıkmıştır. Bu, $i_E$ kolunun iki ucundaki düğümler arasında gerilim farkı olmadığı ve akım akmadığı anlamına gelir. <!-- BELİRSİZ: Bu şıkta verilen diğer akım değerleri karelerde ve altyazıda yok. -->

### 9.3 Gerilim kaynağı akımı ve gücü

Bir düğüme dört kol bağlıdır: $R_1$, $R_2$, $R_3$ ve 3 V'luk $V_1$ kaynağı. İlk durumda $R_3$ üzerinden 1.9 mA ve $R_1$ üzerinden 0.5 mA düğüme girer, kaynaktan $I$ girer, $R_2$ üzerinden 3 mA çıkar:

$$1.9 + 0.5 + I = 3 \;\Rightarrow\; I = 0.6\ \text{mA}$$

<!-- BELİRSİZ: Bu ilk durumun slaytı karelerde yok; değerler altyazıdan alındı. --> Akım kaynağın eksi ucundan girip artı ucundan çıkar. Akım yönündeki gerilim düşümü $-3$ V olduğu için güç negatiftir, yani kaynak devreye güç verir. Hoca sayısal değeri söylemedi; değer $p = (-3\ \text{V})(0.6\ \text{mA}) = -1.8$ mW'tır (ara adım eklendi).

İkinci durumda $R_2$ ve $R_3$'teki akım yönleri değişir (ekrandan, 01:05:00). $R_2$'den 3 mA, $R_1$'den 0.5 mA ve kaynaktan $I$ düğüme girer; $R_3$'ten 1.9 mA çıkar:

$$3 + 0.5 + I = 1.9 \;\Rightarrow\; I = 1.9 - 3.5 = -1.6\ \text{mA}$$

Akım referans yönü kaynağın eksi ucundan girer. Gerilim düşümü $-3$ V olduğundan:

$$p = (-3\ \text{V})(-1.6\ \text{mA}) = +4.8\ \text{mW}$$

Güç pozitiftir. Bu durumda kaynak güç tüketir, yani şarj olan bir kaynak gibi davranır (slaytta "V1 is dissipating power").

> **Hocanın vurgusu:** Denklem verilen yönlere göre kurulur ve hesaplanan değerler cebirsel olarak yerine konur. Negatif bir değer görüp "akım aslında ters yöndeymiş" diyerek yönü değiştirirsek, denklemi baştan kurmamız gerekir. Aynı işi tekrar tekrar yapmamak için bu yol izlenmelidir.

### 9.4 Gerilim düşümleri verilmişse: önce Ohm, sonra KCL (ekrandan, 01:10:00)

Aynı düğümde bu kez akımlar yerine dirençlerin değerleri ve gerilim düşümleri verilmiştir:

| Direnç | Değer | Gerilim düşümü (referans yönünde) | Akım referansı |
|---|---|---|---|
| $R_1$ | 7 kΩ | 2 V | $I_1$, düğümden çıkar |
| $R_2$ | 2 kΩ | 4 V | $I_2$, düğüme girer |
| $R_3$ | 5 kΩ | 1.75 V | $I_3$, düğüme girer |
| $V_1$ | 3 V | – | $I$, düğüme girer |

Örneğin $R_3$'ün sağ ucu $A$ volt ise sol ucu $A + 1.75$ V'tur. Sol uç ne olursa olsun, sağ uçtan 1.75 V daha yüksektir. Akım yüksek potansiyelden düşük potansiyele doğru akar. $I_3$ referans yönünde giriş ucunun geriliminden çıkış ucunun gerilimi çıkarılır ve dirence bölünür:

$$I_3 = \frac{1.75\ \text{V}}{5\ \text{k}\Omega} = 0.35\ \text{mA}, \quad I_2 = \frac{4\ \text{V}}{2\ \text{k}\Omega} = 2\ \text{mA}, \quad I_1 = \frac{2\ \text{V}}{7\ \text{k}\Omega} \approx 0.286\ \text{mA}$$

Volt kilo-ohm'a bölündüğü için sonuçlar miliamper cinsindendir. Ardından KCL:

$$I_2 + I_3 + I = I_1 \;\Rightarrow\; I = 0.286 - 2.35 = -2.06\ \text{mA}$$

Hoca, $I$ negatif çıktığı için kaynağın bu durumda da devreden güç tüketen bir eleman olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Akım kaynağın eksi ucundan girdiği için güç $p = (-3\ \text{V})(-2.06\ \text{mA}) \approx +6.19$ mW olur; pozitif işaret kaynağın güç tükettiğini doğrular.

## 10. KVL Örnekleri

Dersin ikinci yarısı KVL örnekleriyle başladı. Her örnekte aynı yol izlendi: kaynakların yönleri kendi işaretlerinden alınır, dirençler için referans yönleri verilir, KVL denklemi kurulur ve cebirsel değerler çözülür.

### 10.1 İki tek çevreli devre (ekrandan, 01:35:00)

**Birinci devre:** soldan 5 V kaynak (artısı üstte), üstte 7 V kaynak (soldan sağa "− +"), sağda 100 Ω direnç ($v_x$, artısı üstte). $i_x$ saat yönündedir. Saat yönünde dolaşılırken 5 V kaynağa eksi ucundan, 7 V kaynağa eksi ucundan, dirence artı ucundan girilir:

$$-5 - 7 + v_x = 0 \;\Rightarrow\; v_x = 12\ \text{V}$$

Akımı gerilim kaynakları değil, direnç belirler. Gerilim kaynağı üzerinde yazan gerilimi sağlar ama içinden geçen akımı diğer elemanlar belirler. Tek çevrede bu akım bütün elemanlar için aynıdır:

$$i_x = \frac{v_x}{100} = \frac{12}{100}\ \text{A} = 120\ \text{mA}$$

Bu çözümde Ohm yasası, KVL ve gerilim kaynağının tanım bağıntısı birlikte kullanıldı.

**İkinci devre:** solda 3 V kaynak (artısı altta), üstte 1 V kaynak (soldan sağa "+ −"), sağda 10 Ω direnç ($v_x$, artısı üstte). Saat yönünde dolaşılırken iki kaynağa da artı ucundan girilir:

$$+3 + 1 + v_x = 0 \;\Rightarrow\; v_x = -4\ \text{V}$$

$v_x$'in $-4$ V olması, verilen referansın tersine, alt düğümün üst düğümden daha yüksek potansiyelde olduğunu gösterir. Akım:

$$i_x = \frac{v_x}{10} = \frac{-4}{10} = -0.4\ \text{A} = -400\ \text{mA}$$

> **Hocanın vurgusu:** Referans yönleri bir kez tanımlandıktan sonra onlara sadık kalınır; sonrası cebirsel işlemdir. İzlenecek en önemli ilke budur.

### 10.2 Çok gözlü devre (ekrandan, 01:40:00)

Devrenin yapısı (soldan sağa):

| Konum | Eleman ve işaretler |
|---|---|
| Sol dikey kol (c düğümü üstü) | 4 V'luk direnç; artısı altta, eksisi üstte |
| Üst kol | 36 V kaynak; soldan sağa "− +" |
| Orta dikey kol | $R_2$; $v_{R2}$ artısı üstte |
| Üst kol, devamı | Direnç, $+12\ \text{V}-$ (soldan sağa); ardından düzensiz şekilli bir eleman, $+14\ \text{V}-$ |
| a-b arası | Açık uçlar; $v_x$ artısı a'da, eksisi b'de |
| Sağ bölüm | Düzensiz şekilli eleman ($-\,v_2\,+$), $v_{s1}$ kaynağı (artısı altta), $R_1$ ($v_{R1}$ artısı üstte) |

**a. $v_{R2}$:** Sol göz saat yönünde dolaşılır. 4 V'luk dirence artı ucundan, 36 V kaynağa eksi ucundan, $R_2$'ye artı ucundan girilir:

$$4 - 36 + v_{R2} = 0 \;\Rightarrow\; v_{R2} = 32\ \text{V}$$

**b. $v_x$:** Bir çevrim yalnız elemanlardan geçmek zorunda değildir; tanımlı bir gerilim referansı da çevrimi kapatabilir. a ile b arasında sanki sanal bir eleman varmış gibi düşünülür. Çevrim $R_2$'den yukarı çıkar, 12 V'luk dirençten ve 14 V'luk elemandan geçer, a'dan b'ye inip $R_2$'nin alt ucuna döner. Sağ taraftaki $v_2$, $v_{s1}$ ve $R_1$ kullanılmaz; onları kullansaydık $v_2$ ve $v_{s1}$'i de bulmamız gerekirdi, sonunda bu terimler birbirini götürecekti.

$$-32 + 12 + 14 + v_x = 0 \;\Rightarrow\; v_x = 6\ \text{V}$$

Hoca, ölçülen bu gerilimlerin devre çalışırken voltmetreyle alındığını düşünmemizi istedi. Bu örnek, çevrimlerin tek bir gözle sınırlı olmadığını, başladığı yerde biten ve birden fazla gözü kapsayan çevrimler alınabileceğini gösterir.

### 10.3 Aynı devre, farklı değerler

Aynı devrenin değerleri değiştirilmiş bir sürümünde de aynı yol izlendi. Sol göz için verilen referanslar alınınca:

$$-8 - 12 + v_{R2} = 0 \;\Rightarrow\; v_{R2} = 20\ \text{V}$$

Sonra $v_{R1} = 1$ V ve kaynağın 3 V olduğu verilip $v_2$ istendi. Yeşil çevrim boyunca:

$$-20 + 7 - 9 - v_2 - 3 + v_{R1} = 0 \;\Rightarrow\; v_2 = -24\ \text{V}$$

<!-- BELİRSİZ: Bu sürümün slaytı karelerde yok. Denklemin terimleri altyazıdan alındı; hangi elemanın 7 V ve 9 V olduğu doğrulanamadı. -->

### 10.4 Akım kaynaklı devre (ekrandan, 01:45:00)

Devrenin yapısı:

| Konum | Eleman |
|---|---|
| Sol dikey kol | 60 V kaynak, artısı üstte |
| Üst kol, sol | 8 Ω; $v_8$ artısı solda; içinden sağa doğru 5 A |
| Orta dikey kol | 10 Ω; $v_{10}$ artısı üstte; $i_{10}$ aşağı |
| Üst kol, sağ | 4 Ω; $v_4$ artısı solda; $i_4$ sağa |
| Sağ dikey kol | 2 Ω; $i_2$ aşağı |
| En sağ dikey kol | Akım kaynağı $i_x$ (yukarı); uçlarında $v_x$, artısı üstte |

$v_x$ isteniyor. İlk gözde iki bilinmeyen ($v_8$ ve $v_{10}$) varmış gibi görünür, ama 8 Ω'dan 5 A geçtiği bilindiği için $v_8 = 5 \cdot 8 = 40$ V'tur:

$$-60 + v_8 + v_{10} = 0 \;\Rightarrow\; v_{10} = 60 - 40 = 20\ \text{V}$$

10 Ω'dan geçen akım $i_{10} = 20/10 = 2$ A'dır. Orta üst düğüme 5 A girip 2 A çıktığına göre 4 Ω'a giden akım:

$$i_4 = 5 - i_{10} = 5 - \frac{20}{10} = 3\ \text{A}, \qquad v_4 = (4)(3) = 12\ \text{V}$$

İkinci gözde 10 Ω'a eksi ucundan, 4 Ω'a artı ucundan girilir ve 2 Ω'un uçlarındaki gerilim $v$ olarak adlandırılır:

$$-v_{10} + v_4 + v_x = 0 \;\Rightarrow\; v_x = 20 - 12 = 8\ \text{V}$$

2 Ω ile akım kaynağı paraleldir, bu doğrudan da söylenebilirdi; ama hoca Kirchhoff yasalarından gitmeyi tercih etti. Ardından bilinmeyen $i_x$ de bulundu:

$$i_2 = \frac{8}{2} = 4\ \text{A}, \qquad i_4 + i_x = i_2 \;\Rightarrow\; i_x = 4 - 3 = 1\ \text{A}$$

### 10.5 Uygun çevrim seçimi

Bir sonraki devrede bir gerilim kaynağı, $R_1$ ve $R_2$ dirençleri ve bir akım kaynağı vardır. Kaynak AC sembolüyle çizilmişti ama hoca şimdilik DC gibi düşünülmesini istedi. Akım kaynağının uçlarında 3 V oluştuğu verilmiştir. Gerilim kaynağı 5 V'tur ve $v_{R1}$ istenir.

<!-- BELİRSİZ: Bu devrenin (5 V'luk sürüm) slaytı karelerde yok; elemanların yerleşimi altyazıdan kurulamadı. -->

Önce küçük göz (mavi çevrim): akım kaynağının artısından girilir ($+3$ V), $R_2$'nin eksisinden çıkılır ($-v$). Buradan $v = 3$ V bulunur; paralel oldukları için bu zaten beklenen sonuçtur. Sonra yeşil çevrim:

$$-5 - v_{R1} + 3 = 0 \;\Rightarrow\; v_{R1} = -2\ \text{V}$$

Hoca daha sonra aynı sonucun, $R_2$'yi hiç kullanmadan doğrudan kaynak, $R_1$ ve akım kaynağı üzerinden geçen tek bir çevrimle (kırmızı çevrim) de bulunabileceğini gösterdi:

$$-5 - v_{R1} + 3 = 0 \;\Rightarrow\; v_{R1} = -2\ \text{V}$$

> **Hocanın vurgusu:** Uygun bir çevrim seçmek hesabı kolaylaştırır. İlla tek, ayrık, küçük gözler seçmek zorunda değiliz.

Ekranda aynı devrenin değerleri değişmiş bir sürümü de vardı (ekrandan, 01:50:00). Bu sürümde 11.5 V'luk $V_1$ kaynağı, üstte $R_1$ (+2.4 V−), ortada 4.7 kΩ'luk $R_2$, üstte 1.1 kΩ'luk $R_3$ (sağa 1 mA) ve sağda 1 mA'lık $I_1$ akım kaynağı (uçlarında 8 V) bulunur. $R_2$'nin gerilimi bilindikten sonra akımı Ohm yasasıyla bulunur:

$$v_{R2} = 11.5 - 2.4 = 9.1\ \text{V}, \qquad I_{R2} = \frac{9.1\ \text{V}}{4.7\ \text{k}\Omega} \approx 1.94\ \text{mA}$$

Hoca bu sürümün yalnız değerlerinin değiştiğini söyleyip üzerinde durmadı.

Buraya kadar bağımlı kaynak içermeyen; bağımsız gerilim ve akım kaynakları ile dirençlerden oluşan çok gözlü, çok düğümlü devreler bu mantıkla çözülebilir.

## 11. Tek Çevreli Devreler ve Güç Dengesi

### 11.1 Tek çevreli devre

Tek çevreli (tek gözlü) devre, seri elemanların davranışına götüren bir topolojidir. Tek çevre olduğu için bütün elemanlardan aynı $i$ akımı geçer. $v_{s1}$, $R_1$, $v_{s2}$ ve $R_2$ elemanlı genel bir tek çevrede saat yönünde KVL (ekrandan, 01:55:00, slayt listesi):

$$-v_{s1} + v_{R1} + v_{s2} + v_{R2} = 0, \qquad v_{R1} = R_1 i,\quad v_{R2} = R_2 i$$

$$-v_{s1} + R_1 i + v_{s2} + R_2 i = 0 \;\Rightarrow\; i = \frac{v_{s1} - v_{s2}}{R_1 + R_2}$$

Yani ana kol akımı, gerilim kaynaklarının net toplamının dirençlerin aritmetik toplamına bölümüdür. Kaynaklardan birine dolaşım yönünde eksi ucundan, diğerine artı ucundan girildiği için kaynaklar farklı işaretle gelir.

### 11.2 Enerjinin korunumu örneği (ekrandan, 01:55:00)

Slaytta iki ifade vardı:

$$\sum_{\text{tüm elemanlar}} p_{\text{absorbe}} = 0, \qquad \sum p_{\text{absorbe}} = \sum p_{\text{sağlanan}}$$

Örnek devrede beş eleman vardır. Hoca slaytta bağımlı kaynakla ilgili bazı verilerin eksik olduğunu, güç değerlerinin doğrudan yazıldığını söyledi. Bu yüzden güçleri örtüp her elemanın akım ve geriliminden tek tek hesapladı.

Önce verilerin tutarlılığı kontrol edildi. Sol üst düğüme 7 A girer, 2 A ve 5 A çıkar. Sağ üst düğüme 5 A ve 3 A girer, 8 A çıkar. Paralel iki elemanlı çevrimde $-8 + 8 = 0$, orta çevrimde $-8 - 12 + 20 = 0$, sağ çevrimde $-20 + 20 = 0$ sağlanır; yani sağdaki bağımlı kaynağın gerilimi de 20 V olmalıdır.

| Eleman | Gerilim | Akım | Güç |
|---|---|---|---|
| Soldaki 7 A'lık kaynak | 8 V | 7 A | $-56$ W (sağlar) |
| 2 A'lık kol | 8 V | 2 A | $+16$ W (tüketir) |
| Üstteki eleman | $-12$ V | 5 A | $-60$ W |
| 8 A'lık kol | 20 V | 8 A | $+160$ W (tüketir) |
| Sağdaki bağımlı kaynak ($0.25v_x$) | 20 V | 3 A, eksi ucundan girer | $-60$ W |

$$\sum p_{\text{abs}} = -56 + 16 - 60 + 160 - 60 = -176\ \text{W} + 176\ \text{W} = 0$$

Dışarıyla bağlantısı olmayan bu kapalı devrede net güç sıfırdır.

## 12. Bağımlı Kaynaklı Tek Çevreli Devreler

### 12.1 Gerilim kontrollü gerilim kaynağı (ekrandan, 02:00:00)

Devre: 120 V kaynak (artısı üstte), üst kolda 30 Ω ($v_{30}$, artısı solda), üst kolda bağımlı gerilim kaynağı $2v_A$ (soldan sağa "+ −"), sağ kolda 15 Ω. 15 Ω'un gerilimi $v_A$'nın referansı alt uç artı, üst uç eksi olacak şekilde verilmiştir; beklenenin tersi bir yöndür. $i$ akımı saat yönündedir. Her elemanın absorbe ettiği güç istenir.

Bilinmeyenler $i$, $v_{30}$ ve $v_A$ gibi görünür, ama $v_{30}$ ve $v_A$ $i$'ye bağlıdır; bağımlı kaynağın gerilimi de $v_A$'ya bağlıdır. Yani gerçek bilinmeyen yalnız $i$'dir.

Saat yönünde KVL: 120 V kaynağa eksi ucundan girilir, 30 Ω'a artı ucundan, bağımlı kaynağa artı ucundan, 15 Ω'a ise $v_A$ referansının eksi ucundan girilir:

$$-120 + v_{30} + 2v_A - v_A = 0$$

$v_{30}$'un referansı akım yönüyle uyumludur, $v_{30} = 30i$. $v_A$ ise akım yönünde ölçülen düşümün tersidir. 15 Ω'un üst ucu $V_1$, alt ucu $V_2$ olsun: $i = (V_1 - V_2)/15$ ve $V_1 - V_2 = -v_A$. Bu yüzden:

$$v_{30} = 30i, \qquad v_A = -15i$$

$$-120 + 30i - 30i + 15i = 0 \;\Rightarrow\; i = \frac{120}{15} = 8\ \text{A}$$

> **Hocanın vurgusu:** Bu devrede yapılabilecek en büyük hata, referans yönlerine rağmen $v_A = 15i$ yazmaktır. $i$ yönündeki gerilim düşümü $-v_A$'ya eşittir. 15 Ω ile akım arasındaki ilişki doğru kurulursa devre çözülür. Bu devre, referans yönlerinin anlaşılması ve Kirchhoff yasalarının kullanımı açısından önemlidir.

Güçler:

- 120 V kaynak: Akım kaynağın eksi ucundan girer; $p = (120)(-8) = -960$ W. Kaynak güç sağlar.
- 30 Ω: $p = i^2R = 8^2 \cdot 30 = 1920$ W. Direnç güç tüketir.
- Bağımlı kaynak: $v_A = -15 \cdot 8 = -120$ V. Bir voltmetre $v_A$ referansıyla bağlansa $-120$ V okurdu. Akım bağımlı kaynağın artı ucundan girer; $p = (2v_A)(8) = 2(-15)(8)(8) = -1920$ W. Bağımlı kaynak güç sağlar.
- 15 Ω: Akım $v_A$ referansının eksi ucundan girer; $p = -v_A \cdot i = -(-120)(8) = 960$ W. Bu da $8^2 \cdot 15 = 960$ W ile aynıdır.

Toplam: $-960 + 1920 - 1920 + 960 = 0$.

> **Hocanın vurgusu:** Direnç kesinlikle güç tüketen bir elemandır. Referans yönleri ne olursa olsun, bir direncin gücü negatif çıkıyorsa referans yönlerinde ya da cebirsel hesapta bir hata vardır. Bu, kendi çözümlerinizde kullanabileceğiniz bir kontrol yöntemidir.

### 12.2 Bağımlı kaynağın güç sağladığı devre (ekrandan, 02:10:00)

Devre: sol kolda 30 Ω ($v_x$, artısı üstte; $i$ yukarı), üst kolda 12 V kaynak (soldan sağa "− +"), sağda seri 8 Ω ve 7 Ω, sağ kolda bağımlı gerilim kaynağı $4v_x$ (artısı üstte). Beş elemanın absorbe ettiği güç ve toplam gücün kontrolü istenir.

Hoca önce bir uyarı yaptı: $v_x$ referansı verilmemiş olsaydı ve biz onu ters yazsaydık, çözüm yine yapılırdı; tek fark $v_x$'in cebirsel olarak eksi işaretli çıkması olurdu.

Mavi okla verilen dolaşım yönünde KVL: 30 Ω'a $v_x$ referansının eksi ucundan girilir ($-v_x$), 12 V kaynağa eksi ucundan girilir ($-12$), 8 Ω ve 7 Ω'dan aynı akım geçer ($+15i$), bağımlı kaynağa artı ucundan girilir ($+4v_x$):

$$-v_x - 12 + (8 + 7)i + 4v_x = 0$$

30 Ω'da akımın girdiği uç $v_x$ referansının eksi ucudur. O uca artı probu konan bir voltmetre $-v_x$ okur. Bu yüzden:

$$i = \frac{-v_x}{30} \;\Rightarrow\; v_x = -30i$$

Yerine konunca:

$$30i - 12 + 15i - 120i = 0 \;\Rightarrow\; -75i = 12 \;\Rightarrow\; i = -\frac{12}{75} = -\frac{4}{25} = -0.16\ \text{A}, \qquad v_x = \frac{24}{5} = 4.8\ \text{V}$$

Güçler:

- **12 V kaynak:** Akım yönündeki değişim $-12$ V, akım $-0.16$ A'dır: $p = (-12)(-0.16) = +1.92$ W. Kaynak olmasına rağmen gücü pozitiftir, yani güç tüketir.
- **8 Ω:** Hoca önce $v \cdot i$ ile hesapladı ve bir aritmetik hata yaptı, sonra düzeltti. Doğru hesap: $v = 8 \cdot (-0.16) = -1.28$ V ve $p = (-1.28)(-0.16) = 0.2048$ W $= 204.8$ mW. Sonuç pozitiftir.
- **Daha pratik yol:** $p = i^2R$ kullanılırsa akımın yönü ya da işaretiyle uğraşmaya gerek kalmaz; sonuç her zaman pozitiftir. 8 Ω için $0.16^2 \cdot 8 = 204.8$ mW, 7 Ω için $0.16^2 \cdot 7 = 179.2$ mW.
- **30 Ω:** $p = \dfrac{(24/5)^2}{30} = 768$ mW.
- **Bağımlı kaynak:** $p = i \cdot 4v_x = (-0.16)\cdot 4 \cdot (-30i) = 0.16^2 \cdot 4 \cdot (-30) = -3.072$ W.

Toplam kontrol (ekrandan, 02:10:00):

$$768 + 1920 + 204.8 + 179.2 - 3072 = 0\ \text{mW}$$

Bu devrede beklentinin aksine bağımsız kaynak güç tüketirken, devreye gücü bağımlı kaynak vermektedir.

## 13. Tek Düğüm Çiftli Devreler

Tek çevreli devreler olduğu gibi tek düğümlü (tek düğüm çiftli) devreler de vardır. Bütün elemanlar aynı iki düğüm arasına bağlıdır. Bu iki düğümden biri referans seçildiği için devreye "tek düğümlü" denir. Peş peşe alınan KVL çevrimleri, bütün paralel kollardaki gerilimin aynı olduğunu gösterir. Tek çevreli devrede ortak büyüklük akımdır; tek düğümlü devrede ortak büyüklük gerilimdir. Bu tür devreler KCL ile çözülür.

### 13.1 İki akım kaynaklı devre (ekrandan, 02:25:00)

Devre (soldan sağa, hepsi aynı iki düğüm arasında): 120 A akım kaynağı (yukarı), $R_1 = 1/30$ Ω ($i_1$ aşağı), 30 A akım kaynağı (aşağı), $R_2 = 1/15$ Ω ($i_2$ aşağı). Ortak gerilim $v$, artısı üstte. Her elemanın gerilimi, akımı ve gücü istenir.

Bilinmeyen tek değişken $v$'dir; diğer her şey $v$ cinsinden yazılabilir. Üst düğüme 120 A girer; $i_1$, 30 A ve $i_2$ çıkar:

$$120 = i_1 + 30 + i_2 \;\Rightarrow\; i_1 + i_2 = 90\ \text{A}$$

Hoca iki kolun geriliminin eşit olmasından gitti: $i_1 \cdot \tfrac{1}{30} = i_2 \cdot \tfrac{1}{15}$, buradan $i_1 = 2i_2$. Böylece $3i_2 = 90$, yani $i_2 = 30$ A ve $i_1 = 60$ A. Slayttaki eşdeğer yol (ekrandan, 02:25:00):

$$-120 + i_1 + 30 + i_2 = 0, \quad i_1 = 30v,\ i_2 = 15v \;\Rightarrow\; -120 + 30v + 30 + 15v = 0 \;\Rightarrow\; v = 2\ \text{V}$$

Hoca $v$'yi $v = 30 \cdot \tfrac{1}{15} = 2$ V olarak da doğruladı.

Güçler:

- **120 A kaynak:** Akımı kendisi zorlar. Akım yönünde gerilim değişimi $-2$ V'tur: $p = 120(-2) = -240$ W. Kaynak güç sağlar.
- **30 A kaynak:** Gerilimini dirençler belirler, 2 V'tur ve artısı üsttedir. Akım bu kaynağa gerilim referansının artı ucundan girer: $p = 30(2) = 60$ W. Kaynak güç tüketir.
- **$R_1$:** $p = 60^2 \cdot \tfrac{1}{30} = 30(2)^2 = 120$ W.
- **$R_2$:** $p = 30^2 \cdot \tfrac{1}{15} = 15(2)^2 = 60$ W.

Toplam $-240 + 120 + 60 + 60 = 0$'dır.

### 13.2 Bağımlı akım kaynaklı devre (ekrandan, 02:35:00)

Devre (soldan sağa, hepsi aynı iki düğüm arasında): 6 kΩ ($i_6$ aşağı), bağımlı akım kaynağı $2i_x$ (yukarı), 24 mA'lık bağımsız akım kaynağı (yukarı), 2 kΩ. $i_x$ 2 kΩ'dan düğüme doğru (sağdan sola) tanımlıdır. $v$ ve bağımsız kaynağın gücü istenir.

Hoca bu örneğin biraz daha zor olduğunu söyledi. Akım kaynağının gerilimini diğer elemanlar belirler; bağımlı kaynağın akımı da başka bir noktadaki akıma bağlıdır. "Çifte bağımlılık" varmış gibi görünür. Ama devre tek düğümlü olarak görülürse KCL ile pratik biçimde çözülür. Birimler karışmasın diye her şey ampere çevrilir: 24 mA = 0.024 A.

Hocanın kurduğu KCL (çıkan $i_6$ eksi, girenler artı):

$$-i_6 + 2i_x + 0.024 + i_x = 0 \;\Rightarrow\; 3i_x = i_6 - 0.024$$

Slayttaki eşdeğer yazım: $i_6 - 2i_x - 0.024 - i_x = 0$.

Her kolda gerilim $v$'dir:

$$i_6 = \frac{v}{6000}, \qquad i_x = \frac{-v}{2000}$$

$i_x$ ifadesinin eksi işareti şuradan gelir: $i_x$ yönünde ölçüm için voltmetrenin artısı 2 kΩ'un alt ucuna, eksisi üst ucuna bağlanmalıdır, bu da $-v$ okur.

$$-\frac{3v}{2000} = \frac{v}{6000} - 0.024 \;\Rightarrow\; \frac{9v}{6000} + \frac{v}{6000} = 0.024 \;\Rightarrow\; \frac{10v}{6000} = 0.024 \;\Rightarrow\; v = 600 \cdot 0.024 = 14.4\ \text{V}$$

Hoca payda eşitlerken bir an 16'ya böldü, sonra paydanın 10 olduğunu fark edip düzeltti.

Bağımsız kaynağın gücü: Kaynak kolundaki akımı kendisi sağlar ve akım yönünde gerilim değişimi $-14.4$ V'tur:

$$p_{24} = -14.4\,(0.024) = -0.3456\ \text{W} = -345.6\ \text{mW}$$

Bağımsız kaynak devreye 345.6 mW güç sağlar.

> **Hocanın vurgusu:** Devreyi nasıl gördüğümüz çok önemlidir, çünkü çözüm yöntemini o belirler. $i_x$, $i_6$ ve $v$ bilinmiyor gibi görünse de devre tek düğümlü olduğu için hepsi $v$ cinsinden yazılır. Tek denklem ve tek bilinmeyen kalır.

### 13.3 Karmaşık görünen tek düğümlü devre (ekrandan, 02:40:00)

Devre çok karmaşık görünür ama üstteki bütün bağlantılar tek bir ortak düğümdür. Topolojik olarak bütün elemanlar bir düğümden dağılır. Soldan sağa elemanlar: 5.6 A akım kaynağı (yukarı), 18 Ω ($i_A$ aşağı), gerilim kontrollü bağımlı akım kaynağı $0.1v_x$ (yukarı; $i_B$ aşağı tanımlı), 9 Ω ($i_C$ aşağı), 2 A akım kaynağı (aşağı). Ortak gerilim $v_x$'tir. $i_A$, $i_B$ ve $i_C$ istenir.

Bağımlı akım kaynağı ana kol gerilimiyle, yani her elemanın üzerindeki ortak $v_x$ gerilimiyle kontrol edilir. $i_B$'nin referans yönü kaynağın ürettiği akımın tersidir. Bu yüzden $i_B = -0.1v_x$'tir ve KCL'de $-i_B$ terimi $+0.1v_x$ olarak gelir.

$$5.6 - \frac{v_x}{18} + 0.1v_x - \frac{v_x}{9} - 2 = 0$$

$$\frac{3v_x}{18} - \frac{v_x}{10} = 3.6 \;\Rightarrow\; \frac{30v_x - 18v_x}{180} = 3.6 \;\Rightarrow\; \frac{12v_x}{180} = 3.6 \;\Rightarrow\; v_x = 54\ \text{V}$$

$$i_A = \frac{54}{18} = 3\ \text{A}, \qquad i_B = -0.1v_x = -5.4\ \text{A}, \qquad i_C = \frac{54}{9} = 6\ \text{A}$$

Slayttaki kontrol: $5.6 = i_A + i_B + i_C + 2 = 3 - 5.4 + 6 + 2 = 5.6$.

Hoca bu devrede dikkat edilecek en önemli noktanın, verilen referans yön ile kaynağın ürettiği akım yönünün ters olması nedeniyle ikisinin birbirinin negatifi olması olduğunu söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:50:00): Aşağıdaki devre için: a) Devre elemanlarını sayınız. b) B'den C'ye, C'den D'ye gidilirse bir yol ve/veya çevrim oluşur mu? c) E'den D'ye, C'ye, B'ye ve tekrar E'ye gidilirse bir yol ve/veya çevrim oluşur mu? (Devre: A-E arasında gerilim kaynağı; A-B, B-E, B-C, C-D ve F-D arasında dirençler; C-F-G aynı tel, D-E aynı tel.)

> **Çözüm:** a) 6 eleman; 4 tekil düğüm. b) Yol, ama çevrim değil. c) Hem yol hem çevrim.

**Soru 2** (ekrandan, 01:00:00): Gerilim kaynağının 3 A sağladığı biliniyorsa $R_3$'ten geçen akımı KCL ile bulunuz. (Akım kaynağı 5 A, $R_2$'den 2 A.)

> **Çözüm:** $3 - 2 - i + 5 = 0 \Rightarrow i = 6$ A.

**Soru 3** (derste sözlü, 01:01:18): Bir düğüme $i_A$ ve $i_B$ giriyor; $i_C$, $i_D$ ve $i_E$ çıkıyor. $i_A = 1$ A, $i_C = 3$ A, $i_D = -2$ A, $i_E = 4$ A ise $i_B$ nedir?

> **Çözüm:** $i_B = 3 + (-2) + 4 - 1 = 4$ A.

**Soru 4** (ekrandan, 01:05:00): $R_2$'deki akımın düğüme girdiği (3 mA), $R_3$'teki akımın düğümden çıktığı (1.9 mA) ve $R_1$'den 0.5 mA girdiği durumda 3 V'luk kaynağın akımını ve güç durumunu bulunuz.

> **Çözüm:** $I = 1.9 - 3.5 = -1.6$ mA, $p = (-3)(-1.6) = +4.8$ mW; kaynak güç tüketir.

**Soru 5** (ekrandan, 01:10:00): Akımlar yerine gerilim düşümleri verilmiştir ($R_1 = 7$ kΩ'da 2 V, $R_2 = 2$ kΩ'da 4 V, $R_3 = 5$ kΩ'da 1.75 V). Gerilim kaynağından çıkan $I$ akımını bulunuz.

> **Çözüm:** $I_1 = 0.286$ mA, $I_2 = 2$ mA, $I_3 = 0.35$ mA; $I = 0.286 - 2.35 = -2.06$ mA.

**Soru 6** (ekrandan, 01:35:00): Şekildeki iki devre için $v_x$ ve $i_x$'i bulunuz.

> **Çözüm:** Birinci devre: $v_x = 12$ V, $i_x = 120$ mA. İkinci devre: $v_x = -4$ V, $i_x = -400$ mA.

**Soru 7** (ekrandan, 01:40:00): Şekildeki devre için a) $v_{R2}$, b) $v_x$'i bulunuz.

> **Çözüm:** a) $4 - 36 + v_{R2} = 0 \Rightarrow v_{R2} = 32$ V. b) $-32 + 12 + 14 + v_x = 0 \Rightarrow v_x = 6$ V.

**Soru 8** (ekrandan, 01:45:00): Şekildeki devre için $v_x$'i bulunuz.

> **Çözüm:** $v_{10} = 20$ V, $i_4 = 3$ A, $v_4 = 12$ V, $v_x = 8$ V (derste ayrıca $i_x = 1$ A bulundu).

**Soru 9** (ekrandan, 02:00:00): Şekildeki bağımlı kaynaklı devrede her elemanın absorbe ettiği gücü hesaplayınız.

> **Çözüm:** $i = 8$ A; $p_{120V} = -960$ W, $p_{30\Omega} = 1920$ W, $p_{\text{bağımlı}} = -1920$ W, $p_{15\Omega} = 960$ W.

**Soru 10** (ekrandan, 02:10:00): Devredeki beş elemanın her birinin absorbe ettiği gücü bulunuz.

> **Çözüm:** $i = -4/25$ A, $v_x = 24/5$ V; $768$ mW, $1.92$ W, $204.8$ mW, $179.2$ mW, $-3.072$ W; toplam 0.

**Soru 11** (ekrandan, 02:25:00): Devredeki her elemanın gerilimini, akımını ve gücünü bulunuz.

> **Çözüm:** $v = 2$ V, $i_1 = 60$ A, $i_2 = 30$ A; $p_{R1} = 120$ W, $p_{R2} = 60$ W, $p_{120A} = -240$ W, $p_{30A} = 60$ W.

**Soru 12** (ekrandan, 02:35:00): $v$'yi ve bağımsız akım kaynağının absorbe ettiği gücü bulunuz.

> **Çözüm:** $v = 14.4$ V, $p_{24} = -345.6$ mW (kaynak 345.6 mW sağlar).

**Soru 13** (ekrandan, 02:40:00): Tek düğüm çiftli devre için $i_A$, $i_B$ ve $i_C$'yi bulunuz.

> **Çözüm:** $v_x = 54$ V; $i_A = 3$ A, $i_B = -5.4$ A, $i_C = 6$ A.

## Dersin Toparlaması

Bu derste güç işaretinin referans yönlerine göre nasıl yorumlanacağı tekrarlandı. Ardından Ohm yasası, direnç-öz direnç-iletkenlik ilişkileri, kısa devre ve açık devre uç durumları ile düğüm, yol, çevrim ve dal kavramları ele alındı. Kirchhoff akım ve gerilim yasaları tanımlandı ve Ohm yasasıyla birlikte çok sayıda örnek devrede uygulandı. Bütün örneklerde aynı ilke izlendi: referans yönleri bir kez seçilir, denklemler bu yönlere göre kurulur ve hesap cebirsel olarak tamamlanır. Bağımlı kaynaklı tek çevreli devreler ve tek düğüm çiftli devreler, ortak büyüklüğün (tek çevrede akım, tek düğüm çiftinde gerilim) fark edilmesiyle tek bilinmeyenli denklemlere indirgendi. Güç dengesi ve "direncin gücü her zaman pozitiftir" kuralı da çözüm kontrolü olarak kullanıldı.

Hoca, bu yöntemlerin tek bir düğüm ya da tek bir çevreyle ilgilenilen durumlar için çözüm sunduğunu söyledi. Sonraki adımda seri ve paralel devreler ile gerilim ve akım bölücüler incelenecek, daha karmaşık devreler için çevre ve düğüm çözümlemesi yöntemlerine geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
