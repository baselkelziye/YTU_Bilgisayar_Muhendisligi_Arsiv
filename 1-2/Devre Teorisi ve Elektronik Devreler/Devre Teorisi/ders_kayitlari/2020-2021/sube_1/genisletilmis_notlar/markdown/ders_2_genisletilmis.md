# Ders 2 Genişletilmiş Notu: Direnç ve İletkenlik, Devre Topolojisi, Kirchhoff Akım ve Gerilim Yasaları, Seri-Paralel Bağlama ve Eşdeğer Direnç

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Direnç Elemanı
- 3. İletkenlik
- 4. Direnç Elemanında Güç
- 5. Devre Topolojisi: Düğüm, Yol, Çevre, Kol
- 6. Kirchhoff'un Akımlar Yasası
- 7. Kirchhoff'un Gerilimler Yasası
- 8. Akımlar Yasası Örnekleri
- 9. Gerilimler Yasası Örnekleri
- 10. Tek Çevreli Devreler ve Seri Bağlama
- 11. Tek Düğüm Çiftli Devreler ve Paralel Bağlama
- 12. Seriliği ve Paralelliği Tanımak
- 13. Kaynakların Birleştirilmesi
- 14. Eşdeğer Direnç
- 15. Eşdeğer İletkenlik
- 16. Eşdeğer Devreyle Çözüm Örnekleri
- 17. Direnç Değerinin ve Direnç Sayısının Etkisi
- 18. Dualite

## 1. Dersin Planı

Hoca derse geçen haftanın kaldığı yerden, Ohm kanunundan devam edeceğini söyleyerek başladı. Bu haftanın planı Ohm kanunu, Kirchhoff'un gerilimler ve akımlar yasaları, seri ve paralel devreler, sonra da gerilim bölücü ve akım bölücü devrelerdir. Anlatım şimdilik yalnız direnç elemanı üzerinden yürütülecek, bu yüzden direnç elemanı da bu süreçte tanınacak. Hoca haftanın yoğun geçeceğini, ama temel kavramlar olduğu için konuların çoğunun bilindiğini ve genel çerçevede hatırlatma olarak ilerleneceğini belirtti.

## 2. Direnç Elemanı

### 2.1 Özdirenç (Resistivity)

Direnci tanımlamadan önce resistivity, yani özdirenç kavramına ihtiyaç vardır. Özdirenç, bir malzemenin kendi yapısıyla ilgili bir özelliktir. Birim alan ve birim uzunlukta akıma karşı gösterilen direnç olarak tanımlanır. Malzemeye özel, o malzeme için belli olan bir değerdir.

Değerin malzemeden malzemeye değişmesinin sebebi, malzemenin son atomik katmanındaki elektron sayısı, sıcaklık ve buna bağlı olarak ne kadar serbest elektron bulunabildiğidir. İletken bir maddede özdirenç düşüktür, çünkü serbest elektron sayısı fazladır. Hoca bunu bir benzetmeyle anlattı: Metal içinde bir "elektron denizi" içinde hareket ettiğimizi düşünebiliriz. Bu yüzden metallerde özdirenç düşük, hatta ihmal edilebilir seviyelerdedir.

Etkili olan yalnız serbest elektron miktarı değildir. Elektronların mobilitesi de etki eder. Mobilite, yüklü parçacıkların hızıyla ilgilidir. Malzemeden malzemeye değiştiği gibi, malzemenin uçlarına uygulanan gerilimle de değişir.

Slaytta farklı malzemeler için özdirenç değerleri tablo olarak verildi. Birim ohm santimetredir (Ω·cm). Metalik, yani iletken malzemelerde değerler çok düşük, yarı iletkenlerde ve yalıtkanlarda ise oldukça yüksektir.

<!-- BELİRSİZ: Slayttaki özdirenç tablosunun malzeme adları ve sayısal değerleri altyazıda okunmuyor. -->

### 2.2 Özdirençten Dirence

Özdirenç birim alan ve birim uzunluk için tanımlıydı. Bunu keyfi bir kesit alanı ve keyfi bir uzunluk için düşündüğümüzde ortaya çıkan net etki dirençtir:

$$R = \rho \frac{L}{A}$$

Burada $L$ malzemenin uzunluğu, $A$ kesit alanı, $\rho$ özdirençtir. Formülden iki sonuç hemen okunur: Kesit alanı büyüdükçe direnç azalır, uzunluk arttıkça direnç artar. $\rho$ ise malzemeden malzemeye değişir. Hesabı, malzemenin belirli bir oda sıcaklığında birim hacimde ne kadar serbest elektronu olduğu üzerinden yapılır.

### 2.3 Ohm Kanununun Hatırlatılması

Geçen hafta görüldüğü gibi Ohm kanunu deneysel bir gözleme dayanır: İki terminalli bir elemanın uçlarına uygulanan gerilime göre akım doğrusal, yani doğru orantılı değişiyorsa bu eleman bir direnç elemanıdır. Uçlardaki gerilim ile akım arasındaki oran elemana özgüdür:

$$v = iR$$

Gerilim volt, akım amper birimindedir. Bu konuşma, devreyi kurduğumuz tel gibi elemanların değerlerinin ihmal edildiği durum içindir.

### 2.4 Uç Durumlar: Kısa Devre ve Açık Devre

Direnç elemanının iki özel uç durumu vardır.

**Kısa devre.** Direnç değerinin çok düşük olduğu, sıfıra yaklaştığı durumdur. Kısa devre eleman, yerine ideal bir tel koyduğumuzda aynı etkiyi gösteren bir yapıdır. $R = 0$ kabul edilirse Ohm kanunundan elemanın uçları arasındaki gerilim düşümü sıfır olur. Yani eleman üzerinden ne kadar akım akarsa aksın, uçlarındaki gerilim düşümü sıfırdır.

Hoca bunu hatırlamak için ilk dersteki ampermetreyi örnek gösterdi. Ampermetre kısa devre eşdeğeri bir yapıdır ve devreye seri bağlanır. Bağlarken devredeki kablo bağlantısı çıkarılır, kopan bağlantı ampermetreyle sağlanır. Bütün akım bu elemandan geçmelidir ki akım ölçülebilsin.

**Açık devre.** Direncin sonsuz olduğu durumdur. Teknik olarak bağlantıyı kopardığımız duruma karşılık gelir. Akım yine Ohm kanunundan $i = v / R$ ile bulunur. $R$ sonsuza giderken akım sıfıra yaklaşır, ideal durumda sıfırdır. Yani elemanın uçlarına ne kadar gerilim uygulanırsa uygulansın üzerinden akan akım sıfırdır.

Bunu hatırlatan eleman da voltmetredir. Voltmetre, gerilimi ölçülecek elemana paralel bağlanır. Üzerinden akım geçseydi ölçülmek istenen gerilim bozulurdu. Bu yüzden voltmetre açık devre bir elemandır.

## 3. İletkenlik

Direnç gibi bir de iletkenlik (conductance) tanımlanır. İletkenlik, direncin çarpmaya göre tersidir:

$$G = \frac{1}{R}, \qquad i = Gv$$

Ohm kanunundan gerilim bölü akım direnci verirken, akım bölü gerilim iletkenliği verir. Direncin birimi ohm, iletkenliğin birimi siemens (S) ya da ohm'un tersten yazılmış hali olan mho'dur. Sembol olarak Yunan alfabesindeki ohm simgesinin ters çevrilmiş hali (℧) kullanılır.

İletkenlik de malzemenin uzunluğuna ve kesit alanına bağlı olarak hesaplanabilir. Direnç için $\rho$ üzerinden yapılan hesabın aynısı burada sigma ile yapılır:

$$\sigma = \frac{1}{\rho}, \qquad G = \sigma \frac{A}{L}$$

Burada $\sigma$ iletkenlik katsayısı (conductivity) olup malzemeye özgü, hesaplanmış ve verilmiş bir değerdir. Hocanın kurduğu analoji şudur: İletkenlik direncin çarpmaya göre tersi olduğu gibi, conductivity de resistivity'nin çarpmaya göre tersidir.

Hoca iki bakış açısını ayırdı. Biri, elemanın uçlarına gerilim uygulayınca elde edilen akımla ilgilidir ($i = Gv$). Diğeri, malzemenin kendi özelliğinden hesaplanan iletkenliktir ($G = \sigma A / L$). İkisi birbiriyle örtüşecek şekilde çalışır.

## 4. Direnç Elemanında Güç

İlk derste görüldüğü gibi bir elemanın gücü, üzerindeki gerilim düşümü ile üzerinden geçen akımın çarpımıdır. Güç pozitifse eleman devreden güç çeker, negatifse devreye güç verir. Ohm kanunu ve iletkenlikle bu çarpım farklı biçimlerde yazılabilir:

$$p = vi = i^2 R = \frac{v^2}{R} = \frac{i^2}{G} = v^2 G$$

Adımlar şöyledir:

- $v = iR$ yazılırsa $p = i^2 R$.
- $i = v/R$ yazılırsa $p = v^2 / R$.
- $v = i/G$ yazılırsa $p = i^2 / G$.
- $i = vG$ yazılırsa $p = v^2 G$.

Hoca bu gösterimlerin aynı şeyin farklı notasyonlarla ifadesi olduğunu, avantajlarının ise önümüzdeki haftaki düğüm ve çevre denklemlerinde ortaya çıkacağını söyledi.

> **Ders sonrası not:** Hoca, düğüm denklemlerini dirençler üzerinden, çevre akımlarını iletkenlik cinsinden yazmanın daha pratik olduğunu söyledi. Büyük olasılıkla ikisi yer değiştirerek söylendi. Doğrusu tersidir: Düğüm denklemleri akımlarla yazılır ve $i = Gv$ olduğu için iletkenlikle yazmak pratiktir. Çevre denklemleri gerilimlerle yazılır ve $v = iR$ olduğu için dirençle yazmak pratiktir.

$R$ ve $G$ her zaman pozitiftir. Negatif olabilen gerilim ve akım ise formüllere karesel olarak girer. Bu yüzden direnç elemanı her zaman devreden güç çeken, güç tüketen bir elemandır. Bu güç ısı olarak kaybedilir. Yani direnç, devreden çektiği gücü ısıl olarak yayan bir elemandır.

İki uç durumda güç sıfırdır. Kısa devrede eleman direnç gösteremez, uçlar arasındaki gerilim farkı sıfırdır, dolayısıyla güç sıfırdır. Açık devrede üzerinden akan akım sıfırdır, dolayısıyla harcanan güç yine sıfırdır.

## 5. Devre Topolojisi: Düğüm, Yol, Çevre, Kol

Devre çözümlemesinde kullanılacak terimler şunlardır.

### 5.1 Düğüm (Node)

Düğüm, en az iki elemanın terminallerinin bağlı olduğu noktadır. Terminal, elemanın ucu demektir. Düğümler çizimde genellikle terminallerin birleştiği noktada işaretlenir. Fakat bir tel üzerindeki gerilim düşümü sıfır olduğu için, o noktadan elemanlara kadar giden bütün teller aslında aynı düğümdür.

Hocanın üzerinde çalıştığı devrede üç düğüm vardı:

- **1 numaralı düğüm:** Bağımsız akım kaynağının pozitif terminali ile $R_1$, $R_2$ ve $R_3$'ün birer terminali bağlıdır. Toplam 4 eleman.
- **2 numaralı düğüm:** Referans olarak seçildi. Bağlı terminaller akım kaynağının negatif terminali ile $R_1$, $R_2$ ve $R_4$'ün birer terminalidir. Toplam 4 terminal.
- **3 numaralı düğüm:** $R_3$'ün bir terminali ile $R_4$'ün bir terminali bağlıdır. Toplam 2 eleman.

<!-- BELİRSİZ: 2 numaralı düğüme bağlı dirençler altyazıda karışık okunuyor ("R3, R2 ... R1 ve R2 ... R4"). Liste, hocanın "dört terminal" sayımından ve 3 numaralı düğümdeki bağlantılardan kuruldu. -->

Düğümlerden biri referans seçilir. Diğer düğümlerin gerilimleri bu referansa göre, görece hesaplanır. Referans seçilen düğümün gerilimi sıfır volttur ve ona bağlı bütün teller aynı gerilim seviyesindedir.

### 5.2 Yol (Path)

Yol, kendini tekrar etmeyen düğümler dizisidir. İçinde çevre barındırmaz. Aynı devrede 1'den 3'e, 3'ten 2'ye gidildiğinde iki direnç geçilerek bir yol tamamlanır. 1'den 2'ye, 2'den 3'e gidilerek başka bir yol da tanımlanabilir. Önemli olan, hiçbir düğümün dizide tekrar yer almamasıdır.

### 5.3 Çevre (Loop)

Çevre ya da çevrim, başlangıç ve bitiş düğümü aynı olan kapalı dizidir. Örneğin 3'ten 1'e, 1'den 2'ye, 2'den tekrar 3'e gelinebilir. 1'den 2'ye $R_1$ üzerinden de $R_2$ üzerinden de geçilebilir. Farklı elemanlardan geçen çevrimler farklı çevrelerdir ve her biri için ayrı bir denklem yazılabilir.

**Soru:** Çevrelerin kendisi yol sayılmıyor, değil mi?

**Cevap:** Yolda bir düğümün tekrar etmemesi gerekiyordu. Çevrede başlangıç ve bitiş düğümleri aynı olduğu için çevre bir yol olarak tanımlanamaz. İkisi farklıdır.

### 5.4 Kol (Branch)

Kol, yol kavramının bir alt bileşenidir. Yalnız bir eleman içerir: bir elemanı ve onun iki ucundaki düğümleri tanımlar. Örneğin 1'den 2'ye tek bir direnç üzerinden gitmek bir koldur.

> **Hocanın vurgusu:** Burada önemli olan özellikle düğüm ve çevre kavramlarıdır, diğerleri yardımcı tanımlardır. Düğümün, aynı gerilime sahip, birbirine tellerle komşu noktalardan oluşan bir komşuluk olduğunu mutlaka hatırlayın. Çevrenin kapalı olduğunu, farklı elemanlardan geçen çevrelerin farklı olduğunu ve her biri için ayrı denklem yazılabileceğini de hatırlayın.

### 5.5 Harfli Devre Örneği

Slaytta noktaları harflerle işaretlenmiş bir devre verildi. Devrede bir bağımsız gerilim kaynağı, A-B arasında bir direnç, B-E arasında bir direnç, B-C, C-D ve F-D arasında birer direnç vardır. Kavramlar bu devrede şöyle görülür:

- B'den C'ye, C'den D'ye ilerlemek kapalı bir çevrim oluşturmaz, bir yoldur.
- E'den D'ye, D'den C'ye, C'den B'ye, B'den E'ye dolaşmak bir çevrimdir, çünkü başlangıç ve bitiş ortaktır.
- E ve D ayrı harflerle işaretlenmiştir ama aynı düğümdür.
- C, F ve G de aralarında gerilim düşümü olmadığı ve hiçbir eleman geçmeden birbirine gidilebildiği için aynı düğümdür.

## 6. Kirchhoff'un Akımlar Yasası

Kirchhoff'un akımlar yasası (KCL) şunu söyler: Herhangi bir düğüme giren ve çıkan akımların cebirsel toplamı sıfırdır. Eşdeğer ifadesi, giren akımların toplamının çıkan akımların toplamına eşit olmasıdır.

$$\sum i = 0 \quad \Longleftrightarrow \quad \sum i_{\text{giren}} = \sum i_{\text{çıkan}}$$

Yasa, kapalı bir eğri için de düşünülebilir. Devre üzerinde bazı elemanları kapsayan bir eğri çizildiğinde, eğrinin içine giren akımlarla dışına çıkan akımların toplamı yine sıfırdır. Pratikte ise tek bir düğüm üzerinden çalışılır. Yasanın dayanağı yükün korunumudur: Kapalı bir sistemde toplam yük değişmez.

İşaret seçimi serbesttir. Giren akımlar pozitif, çıkanlar negatif alınabilir, ya da tersi yapılabilir. Bir düğümdeki seçim başka bir düğümdekinden farklı olabilir.

> **Hocanın vurgusu:** Seçim düğüm içinde tutarlı olmalıdır. Aynı düğümde bütün girenlerin işareti aynı, bütün çıkanların işareti aynı olmalıdır.

## 7. Kirchhoff'un Gerilimler Yasası

Kirchhoff'un gerilimler yasası (KVL) şunu söyler: Tek gözlü ya da çok gözlü herhangi bir devrede, herhangi bir çevrim içinde dolaşıldığında elemanların üzerindeki gerilim düşümlerinin toplamı sıfırdır.

$$\sum_{\text{çevre}} v = 0$$

Hoca yasayı enerji ve güçle ilişkilendirdi. Tek çevrimli bir devrede toplam gücün sıfır olması gerekir. Her elemandan aynı akım geçtiği için bu, gerilim düşümlerinin toplamının sıfır olmasını getirir.

> **Ek bilgi (derste anlatılmadı):** Kısa notta bu yasanın dayanağı, bir yükü çevre boyunca dolaştırıp başlangıç noktasına getirmek için net iş gerekmemesi olarak verilmiştir. Bu ifade büyük olasılıkla slayttan alınmıştır, altyazıda sözlü olarak geçmiyor. Aynı fikir, iki düğüm arasındaki gerilimin izlenen yoldan bağımsız olduğunu da söyler. Bölüm 9'daki çevre seçme esnekliği buna dayanır.

İşaret kuralı akımlar yasasındakine benzer. Çevre için bir yön seçilir ve bu yönde ilerlenir. Elemana eksi ucundan girilirse gerilim eksi, artı ucundan girilirse artı yazılır. Hocanın üç elemanlı örneğinde bir yön için

$$-V_1 + V_2 - V_3 = 0$$

yazıldı. Çevre yönü ters seçilince bütün işaretler ters döner:

$$+V_1 - V_2 + V_3 = 0$$

Farklı çevreler için farklı yönler seçilebilir. Önemli olan her çevrede yönün tutarlı olmasıdır. Böylece iki yasa şöyle özetlenir: Biri bir düğüme giren ve çıkan akımların toplamının sıfır olduğunu, diğeri herhangi bir çevre üzerindeki gerilimlerin toplamının sıfır olduğunu söyler.

## 8. Akımlar Yasası Örnekleri

### 8.1 Tek Düğümde Bilinmeyen Akım

Devrede $R_3$'ten geçen $i$ akımı isteniyor. Hoca önce akım kaynağının iki tarafındaki noktaları işaretledi, sonra bunların aynı tel üzerinde olduğunu, yani tek bir düğüm oluşturduğunu gösterdi. Bu ortak düğümde verilenler şunlardır:

- Akım kaynağından düğüme 5 A giriyor.
- Gerilim kaynağı sisteme 3 A veriyor. Kaynak bu akımı kendi referansıyla uyumlu yönde sağladığı için bu kolda düğüme 3 A giriyor.
- $R_2$'den 2 A çıkıyor.
- $R_3$'ten $i$ çıkıyor.

$$3 - 2 - i + 5 = 0 \quad \Rightarrow \quad i = 6 \text{ A}$$

Hocanın okuyuşuyla 8 A girdi, 2 A çıktı, $i$ için 6 A kaldı. Bu sonuca ulaşmak için gerilim kaynağından geçen 3 A'in bilinmesi şarttır.

**Soru:** $R_2$'deki 2 A verilmiş mi, yoksa bir yerden mi bulduk?

**Cevap:** Devre üzerinde verilmiş. Verilenlerle çizdik.

**Soru:** Akım kaynağından gerilim kaynağına doğru bir akım gitmesi mümkün mü?

**Cevap:** Bu, normalde direnç değerlerine ve gerilim düşümlerine göre bulunur. Bu soruda ise net olarak söylenen, bütün etkilere rağmen gerilim kaynağının devreye 3 A sağladığıdır. Sonraki örneklerde direnç değerleri ve diğer kaynaklar verilip bu akımın kendisi bulunacak.

### 8.2 Beş Akımlı Düğüm

Slaytta tek bir düğüme bağlı beş akım vardır. Bir şıkta $i_B$, başka bir şıkta $i_E$ verilmemiştir. Giren ve çıkan akımlar referanslarına göre yazılınca çözüm doğrudan bulunur:

$$i_A + i_B - i_C - i_E - i_D = 0$$

Hoca örneğin basit olduğunu söyleyip üzerinde durmadı.

<!-- BELİRSİZ: Bu örnekteki akımların sayısal değerleri altyazıda okunmuyor. -->

### 8.3 Gerilim Kaynağının Akımı ve Gücü

Düğüme 1.9 mA ve 0.5 mA giriyor, 3 mA çıkıyor. Gerilim kaynağının düğüme doğru akan $I$ akımı bilinmiyor.

Önce referans yön hatırlatıldı: Gerilim kaynaklarında referans akım yönü kaynağın içinden eksi terminalden artı terminale doğrudur. Hoca bunu elektronların hareketiyle bağladı: Elektronlar negatif terminalden pozitif terminale gider. Biz akımı, ters yönde hareket eden sanal pozitif yükler olarak tanımlarız.

> **Ders sonrası not:** Elektronların negatif terminalden pozitif terminale gitmesi kaynağın dışındaki devre için geçerlidir. Kaynağın içinde tanımlanan akım yönünün eksiden artıya olması ise, dışarıda artıdan eksiye akan akımın kaynağın içinden devam etmesindendir. Hoca büyük olasılıkla dış devreyi kastetti, altyazıda bu ayrım yapılmadı.

Girenlerin toplamı çıkana eşit olur:

$$1.9 + 0.5 + I = 3 \quad \Rightarrow \quad I = 0.6 \text{ mA}$$

$I$ pozitif çıktığı için akım kaynağın artı ucundan çıkar. Kaynağın 3 V olduğu verildiğinde gücü:

$$p = -(3 \text{ V})(0.6 \text{ mA}) = -1.8 \text{ mW}$$

Güç negatiftir, yani kaynak devreye 1.8 mW verir.

Hoca sonra $I$ negatif çıksaydı ne olacağını sordu ve bunu bir sonraki slaytla gösterdi. Aynı yapıda giren akımlar pozitif, çıkanlar negatif alındığında bu kez $I = -1.6$ mA bulunur. Bunun anlamı, devrede görmediğimiz bir tarafta devreye güç sağlayan başka bir eleman olduğu ve bu elemanın gerilim kaynağı üzerinde ters yönlü akım oluşturduğudur. Bu durumda gerilim kaynağı devreden güç çeker, yani şarj oluyor gibi davranır.

<!-- BELİRSİZ: I = -1.6 mA sonucunu veren slayttaki akım değerleri altyazıda okunmuyor. -->

### 8.4 Akımlar Yerine Gerilimler Verildiğinde

Aynı problem bu kez elemanların uçları arasındaki gerilim düşümleri verilerek soruldu. Verilenler: $R_1 = 7$ kΩ üzerinde 2 V, $R_2 = 2$ kΩ üzerinde 4 V, $R_3 = 5$ kΩ üzerinde 1.75 V ve 3 V'luk bir gerilim kaynağı. Akımlar, her direnç için artıdan eksiye, yani gerilim düşümüyle uyumlu yönde tanımlandı. Ohm kanunuyla:

$$I_1 = \frac{2 \text{ V}}{7 \text{ k}\Omega} \approx 0.29 \text{ mA}, \qquad I_2 = \frac{4 \text{ V}}{2 \text{ k}\Omega} = 2 \text{ mA}, \qquad I_3 = \frac{1.75 \text{ V}}{5 \text{ k}\Omega} = 0.35 \text{ mA}$$

KCL ile:

$$I + I_2 + I_3 = I_1 \quad \Rightarrow \quad I = 0.29 - 2 - 0.35 = -2.06 \text{ mA}$$

Sonuç negatif olduğu için gerçek akım seçilen yönün tersidir. Gerilim kaynağı burada da devreden güç çeker.

## 9. Gerilimler Yasası Örnekleri

Akımlar yasasıyla kollardaki akımlar bulunduğu gibi, gerilimler yasasıyla da eleman gerilimleri bulunur.

### 9.1 İki Tek Gözlü Devre

İkisinde de çevrim yönü saat yönündedir. Elemana eksi ucundan girilirse gerilim eksi yazılır.

**Birinci devre.** 5 V ve 7 V'luk iki kaynak ile 100 Ω'luk direnç seridir. Çevrim yönü kaynakların eksi terminalinden girer:

$$-5 - 7 + V_x = 0 \quad \Rightarrow \quad V_x = 12 \text{ V}$$

Tek göz olduğu için direncin akımı aynı zamanda ana kol akımıdır:

$$i = \frac{12}{100} = 0.12 \text{ A}$$

**İkinci devre.** Çevrim yönü bu kez kaynakların referans yönüyle uyumludur:

$$3 + 1 + V_x = 0 \quad \Rightarrow \quad V_x = -4 \text{ V}$$

Ana kol akımı 10 Ω'luk direncin akımıdır:

$$I_x = \frac{V_x}{10} = \frac{-4}{10} = -0.4 \text{ A}$$

Eksi işaret, gerçek akımın seçilen yönün tersine aktığını gösterir. Hoca devreyi yeniden çizerek akımı ters yönde 0.4 A olarak da tanımlayabileceğini, ikisinin aynı şey olduğunu hatırlattı.

### 9.2 İki Gözlü Devre ve Çevre Seçme Esnekliği

Gerilimler yasası çok gözlü devrelerde de aynı biçimde kullanılır. Bir çevrim yönü belirlenir, çevrim kapatılır, çevrimdeki elemanların gerilimleri toplamı sıfıra eşitlenir.

Birinci çevrede 4 V'luk eleman, 36 V'luk eleman ve $R_2$ vardır. Yön saat yönündedir. 4 V'luk elemanın referansı yönle uyumlu, 36 V'luk elemanınki terstir, $R_2$'de ise artıdan eksiye gidilir:

$$4 - 36 + V_{R2} = 0 \quad \Rightarrow \quad V_{R2} = 32 \text{ V}$$

Sonra $a$ ve $b$ terminalleri arasındaki $V_x$ isteniyor. Devrede değeri bilinmeyen başka elemanlar da vardır. Fakat çevreyi bütün devreyi dolaşacak kadar uzun seçmek gerekmez. Çevre şöyle kapatılabilir: $R_2$, üzerinde 12 V düşen direnç, üzerinde 14 V düşen ve hocanın "fasulye elemanı" dediği eleman, sonra $a$-$b$ terminalleri. Fasulye elemanı, slaytta türü belirtilmeyen genel bir devre elemanını gösteren fasulye biçimli semboldür.

Bu çevrede $R_2$ referansı tersine geçilir, diğerleri uyumludur:

$$-32 + 12 + 14 + V_x = 0 \quad \Rightarrow \quad V_x = 32 - 26 = 6 \text{ V}$$

Bu örnek, çevre tanımında esnekliğimiz olduğunu gösterir.

### 9.3 Aynı Yapı, Negatif Etiketli Eleman

Devre aynı, değerler farklıdır. Sol kolda değeri $-8$ V olarak yazılmış bir eleman vardır. Hoca referans yönlere ve değerlere şaşırmamak gerektiğini söyledi: Referans yön çevre yönüyle uyumluysa değer olduğu gibi, yani $-8$ olarak kullanılır.

$$-8 - 12 + V_{R2} = 0 \quad \Rightarrow \quad V_{R2} = 20 \text{ V}$$

$V_{R1} = 1$ V verilmiştir. Slayt, büyük çevrim üzerinden gidiyor:

$$-20 + 7 - 9 - V_2 - 3 + V_{R1} = 0 \quad \Rightarrow \quad V_2 = -24 \text{ V}$$

Soruda $V_x$ istenmesine karşın slaytta $V_2$ bulunmuş. Hoca soruda hata olduğunu düşündü ve $V_2$ sorulmuş varsayarak düzeltti. Bu haliyle özel bir çevrim tanımlamadan, büyük çevrim üzerinden sonuca gidilmiş olur.

<!-- BELİRSİZ: Büyük çevrim denklemi ve devre yapısı altyazıda okunmuyor, kısa nottan alındı. Hoca sonucu sözlü olarak işaretsiz "24 volt" diye okudu; kısa nottaki denklem -24 V veriyor. -->

> **Ders sonrası not:** Hoca soruda hata olduğunu söyledi, ama $V_x$ de bulunabilir. Kısa nottaki devre yapısına göre $a$ düğümünden sağ yol üzerinden $b$'ye gidilirse $V_x = -V_2 - 3 + V_{R1} = 24 - 3 + 1 = 22$ V, sol yol üzerinden $V_x = V_{R2} - 7 + 9 = 20 - 7 + 9 = 22$ V olur. İki yol da aynı sonucu verir, python ile hesaplandı. Hocanın kendisi de $V_x$'in "benzer şekilde" bulunabileceğini söylemişti.

### 9.4 Üç Gözlü Devre ve Akım Kaynağı

Devrede 60 V'luk kaynak, ona seri 8 Ω, ortada 10 Ω, üst hatta 4 Ω, sonra 2 Ω ve en sağda uçlarındaki gerilim $V_x$ olan bir bağımsız akım kaynağı vardır. 8 Ω'dan 5 A geçtiği verilmiştir. $V_x$ isteniyor.

Hoca önce akım kaynağının gerilimler yasasına nasıl gireceğini sordu. Akım kaynağının özelliği hatırlanır: Bağlı olduğu kola üzerinde yazılan akımı sağlar, üzerindeki gerilim düşümü ise devrenin diğer elemanları tarafından belirlenir.

Çözüm adımları:

1. Birinci çevrim: $-60 + V_8 + V_{10} = 0$.
2. Akım ve gerilim referansları aynı yönlü olduğu için Ohm kanunundan $V_8 = 8 \cdot 5 = 40$ V. Buradan $V_{10} = 20$ V.
3. İkinci çevrim doğrudan yazılamaz, çünkü 2 Ω'luk dirençten akan akım bilinmiyor.
4. Bunun yerine Ohm kanunundan $I_{10} = 20 / 10 = 2$ A.
5. Düğüme 5 A girmiş, 2 A çıkmıştır, dolayısıyla KCL'den $I_4 = 3$ A.
6. $V_4 = 4 \cdot 3 = 12$ V.
7. Artık 10 Ω, 4 Ω ve akım kaynağından geçen çevre seçilir. Bu çevrede iki değer bilinir, biri aranır:

$$-V_{10} + V_4 + V_x = 0 \quad \Rightarrow \quad -20 + 12 + V_x = 0 \quad \Rightarrow \quad V_x = 8 \text{ V}$$

Hoca, ikinci gözden gidilseydi 2 Ω'luk direncin akımını akım kaynağının değeriyle ilişkilendirmek gerektiğini, yalnız gerilimle ilgilenildiği için farklı bir çevre alarak bu direncin devre dışı bırakıldığını söyledi.

**Soru:** Slaytlardaki bazı kaynaklar neden AC sembolüyle çizilmiş?

**Cevap:** Normalde bu sembol AC kaynak sembolüdür, ama belki başka kaynak koyulamadığı için hatalı konmuş. Değerler sabit olduğu için bunlar DC kaynak olarak düşünülmelidir.

Bu bölümün kalan örnekleri aynı olduğu için hoca incelemeyi öğrencilere bıraktı.

## 10. Tek Çevreli Devreler ve Seri Bağlama

### 10.1 Seriliğin Tanımı

Tek çevreli bir devrede KVL uygulandığında her elemandan geçen akımın aynı olduğu görülür. Hoca burada ince bir ayrım yaptı: "Aynı" derken yalnız matematiksel olarak aynı sonucu vermesinden söz edilmiyor. Örneğin bir kaynağın değeri değiştirildiğinde her elemandaki akım aynı şekilde değişir. Bu durumdaki bütün elemanlar birbirine seri bağlıdır.

Tek çevreli devrede bilinmeyenleri bulmak için iki durum vardır:

- Devrede bir akım kaynağı varsa ana kol akımını zaten o belirler.
- Yalnız bağımsız gerilim kaynakları varsa ana kol akımı KVL ile bulunur.

Saat yönünde çevrim ve aynı yönlü $i$ seçildiğinde hocanın örneğinde şöyle yazılır:

$$-v_{s1} + v_{R1} + v_{s2} + v_{R2} = 0$$

Ohm kanunundan $v_{R1} = iR_1$ ve $v_{R2} = iR_2$ olduğu için:

$$i = \frac{v_{s1} - v_{s2}}{R_1 + R_2}$$

Pay, kaynakların net gerilimi, payda dirençlerin toplamıdır. Yani devrede bağımsız akım kaynağı olmadığı sürece ana kol akımı, kaynak gerilimlerinin yönlü toplamının dirençlerin toplamına bölümüdür. Yönler devreye göre değişebilir.

### 10.2 Güç Dengesi

Kapalı bir sistemde sağlanan ve harcanan güçlerin toplamı sıfırdır. Başka bir deyişle harcanan güç, sağlanan güce eşittir.

> **Ders sonrası not:** Hoca bunu söylerken "harcanan güçler pozitif, tüketilen güçler negatif" dedi. Doğrusu "harcanan (tüketilen) güçler pozitif, sağlanan güçler negatif" olmalıdır. Hocanın dersin başındaki tanımı da budur.

Slaytta elemanların gerilim düşümleri ve referans akım yönleri verilmiş bir sayısal örnek vardı. Üzerinde 8 V düşen ve 7 A geçen elemanda akım eksiden artıya gittiği için eleman enerji verir. $-12$ V ve 5 A olan eleman ile 3 A'in eksiden artıya gittiği eleman da yönlerine göre enerji verir. Diğerlerinde gerilim düşümü ile akım yönü aynı olduğundan güçleri pozitiftir. Hepsi çarpılıp toplanınca sıfır beklenir:

$$-56 + 16 - 60 + 160 - 60 = 0$$

<!-- BELİRSİZ: Toplamdaki 16 ve 160 W'lık elemanların gerilim ve akımı altyazıda okunmuyor, toplam kısa nottan alındı. -->

### 10.3 Bağımlı Kaynaklı Tek Çevreli Devre: $2v_A$

Devrede 120 V'luk kaynak, 30 Ω, değeri $2v_A$ olan gerilime bağlı gerilim kaynağı ve 15 Ω seridir. $v_A$, 15 Ω'luk direnç üzerinde, artısı akım yönünün çıktığı tarafta olacak şekilde tanımlıdır. Her elemanın gücü isteniyor.

Saat yönündeki çevrede bağımlı kaynağın gerilimine $v_B$ denirse:

$$-120 + v_{30} + v_B - v_A = 0, \qquad v_B = 2v_A$$

Hoca, bağımlı kaynağı herhangi bir eleman gibi hesaba kattığını vurguladı. Yerine konunca:

$$v_{30} + v_A = 120$$

Hoca önce bu denklemi eksi işaretle yazdı, bir öğrenci "artı $v_A$ değil mi?" diye uyardı ve düzeltildi. Şimdi gerilimler ana kol akımı cinsinden yazılır:

$$v_{30} = 30i, \qquad v_A = -15i$$

$$30i - 15i = 120 \quad \Rightarrow \quad i = 8 \text{ A}, \qquad v_A = -120 \text{ V}$$

$v_A$'nın eksi işaretli çıkması derste ayrıca tartışıldı.

**Soru:** $2v_A$ ve $-v_A$ yazılırken neden sonuçta $+15i$ çıkıyor? Bağımlı kaynakta artıdan eksiye gidiliyor, ters olmayacak mı?

**Cevap:** İki ayrı işaret vardır. Birincisi KVL'den gelir: Çevre yönü elemana eksi ucundan girerse gerilim eksi yazılır. İkincisi $v_A$'nın kendi tanımından gelir: Akım yönünde bakıldığında 15 Ω'luk direnç üzerindeki gerilim düşümü $15i$'dir. Oysa $v_A$ bunun ters yönünde tanımlanmıştır, bu yüzden $v_A = -15i$ yazılır. Bağımlı kaynağa da aynı $v_A$ taşınır. Burada yalnız büyüklük değil, yön de dikkate alınır. Bağımlı kaynağın gerilimi $2v_A = -30i$ olur.

Hoca kendi çözümündeki hatayı da açıkladı: $v_A$'yı başta ters yönde değilmiş gibi almıştı ve 15 Ω'luk direncin gücü negatif çıkmıştı. Bir öğrencinin uyarısıyla işaret düzeltildi. Eksinin eksisi pozitif olur ve direncin gücü doğru bulunur.

Güçler (çekilen güç):

| Eleman | Hesap | Güç |
|---|---|---|
| 120 V'luk kaynak | $-120 \cdot 8$ | $-960$ W (verir) |
| 30 Ω | $8^2 \cdot 30$ | $1920$ W |
| 15 Ω | $8^2 \cdot 15$ | $960$ W |
| Bağımlı kaynak | $(2v_A)\, i = (-240)(8)$ | $-1920$ W (verir) |
| Toplam | | $0$ |

> **Ders sonrası not:** Hoca, akım ve gerilim referansları aynı yönlü olduğu için bağımlı kaynağın güç tükettiğini söyledi ve bir öğrencinin uyarısıyla gerilimin büyüklüğünü 240 V aldı. Doğrusu şudur: Referansların aynı yönlü olması tek başına yetmez, değerin işareti de önemlidir. $2v_A = -240$ V olduğu için çektiği güç $-1920$ W'tır, yani bağımlı kaynak 1920 W **verir**. Tablodaki toplamın sıfır çıkması bunu doğrular, python ile hesaplandı.

### 10.4 Bağımlı Kaynaklı Tek Çevreli Devre: $4v_x$

Seri bağlı elemanlar: 30 Ω (üzerindeki gerilim $v_x$), 12 V'luk kaynak, 8 Ω, 7 Ω ve $4v_x$ değerli bağımlı gerilim kaynağı. Seçilen çevre yönü $v_x$'in eksi ucundan ve 12 V'luk kaynağın eksi ucundan girer. 8 Ω ve 7 Ω için artı-eksi yönleri akımla uyumlu seçilir:

$$-v_x - 12 + (8 + 7)i + 4v_x = 0 \quad \Rightarrow \quad 15i + 3v_x = 12$$

İki bilinmeyen vardır. $v_x$ referansı ile akım referansı birbirine terstir. Akım yönünde bakıldığında direnç üzerindeki gerilim düşümü $-v_x$ olduğundan:

$$i = -\frac{v_x}{30}$$

Yerine konunca:

$$-\frac{v_x}{2} + 3v_x = 12 \quad \Rightarrow \quad v_x = \frac{24}{5} = 4.8 \text{ V}, \qquad i = -\frac{4}{25} = -0.16 \text{ A}$$

Hoca her elemanın gücünü hangi formülden hesapladığını tek tek gösterdi:

| Eleman | Hesap | Güç |
|---|---|---|
| 30 Ω | $\dfrac{(24/5)^2}{30}$ | $0.768$ W |
| 12 V'luk kaynak | $-i \cdot 12 = -(-\tfrac{4}{25}) \cdot 12$ | $1.92$ W (çeker) |
| 8 Ω | $(-\tfrac{4}{25})^2 \cdot 8$ | $0.2048$ W |
| 7 Ω | $(-\tfrac{4}{25})^2 \cdot 7$ | $0.1792$ W |
| Bağımlı kaynak | $(4v_x)\, i = (19.2)(-0.16)$ | $-3.072$ W (verir) |
| Toplam | | $0$ |

Hesaplarda iki yazım önemlidir. 30 Ω'luk direncin gücünde $(24/5)^2$ alınır, $24^2/5$ değil. Dirençlerde $i^2R$ yazılırken negatif akım parantez içinde karesi alınarak yazılır, böylece sonucun pozitif çıkması garantidir. 12 V'luk kaynakta akım eksi terminalden girdiği için güçte bir eksi vardır, akımın değeri de eksidir, eksi eksi artı olur ve kaynak güç tüketir.

Toplam güç python ile hesaplandı ve sıfır çıktı.

**Soru:** 8 ve 7 Ω'luk dirençlerde artı-eksi yönlerini ters yapsaydık bir şey değişir miydi?

**Cevap:** Dirençler pasif elemandır. Güç tüketebilmeleri için referans yönleri akım yönüyle uyumlu olmalıdır. Ana kol akımının yönü belirlendiği için dirençlerin yönü de ona göre verildi. Akım yönü henüz belirlenmemiş olsaydı dirençlerin yönünü ters çevirip akımı da ona uyumlu olacak şekilde ters yönde seçmek mümkün olurdu.

**Soru:** İlk dirençte peki neden eksiden artıya yazıyoruz?

**Cevap:** 30 Ω'luk dirençte soru $v_x$'i özel olarak tanımlamıştır. $v_x$ ve $i$ incelendiğinde $i$ negatif çıkıyor, sonuçlar kendi içinde uyumludur.

> **Ders sonrası not:** Hoca bu cevapta "sisteme bu gücü verdiği için" dedi. Bir direnç sisteme güç vermez. $i$ negatif çıktığı için gerçek akım $v_x$'in artısından eksisine doğru akar, $v_x$ de pozitiftir, dolayısıyla 30 Ω güç çeker. Gücü python ile 0.768 W olarak hesaplandı. Hoca $i = -v_x/30$ yazarken de sözlü olarak "gerilim düşümü bölü akım" dedi, doğrusu "gerilim düşümü bölü direnç"tir.

**Soru:** Kaynaklardaki gücü watt, dirençlerdekini miliwatt olarak buluyoruz. Neden?

**Cevap:** Özel bir durum yok. Hoca hesabı derste tekrar yaptı: $(24/5)^2 / 30 = 0.768$ W. Sonuç 1 W'tan küçük olduğu için slaytta görsel olarak daha uygun olsun diye miliwatta çevrilmiş.

## 11. Tek Düğüm Çiftli Devreler ve Paralel Bağlama

### 11.1 Paralelliğin Tanımı

Tek çevreli devrelerin karşılığı olarak bir referans düğüm ve onun dışında tek bir düğüm içeren devreler vardır. Bunlara tek düğüm çiftli (single node pair) devre denir. Değerler değiştikçe her elemandaki gerilim düşümü aynı anda ve aynı yönde değişir. Bu özelliğe sahip elemanlardan oluşan devreler paralel devredir.

Şekildeki devrede alttaki bütün noktalar referans düğümdür, sıfır volttur. Üstteki noktalara da başka hiçbir elemandan geçmeden tel üzerinden erişilebildiği için onlar da tek düğümdür. Üst düğümün gerilimi $v$ ise bütün elemanların uçlarında aynı $v$ vardır.

### 11.2 İki Akım Kaynaklı Örnek

Yukarı yönlü 120 A'lik kaynak, $R_1 = \frac{1}{30}$ Ω, aşağı yönlü 30 A'lik kaynak ve $R_2 = \frac{1}{15}$ Ω paraleldir. Üst düğümün gerilimi $v$ olsun.

Direnç akımları Ohm kanunundan:

$$i_1 = \frac{v}{R_1} = 30v, \qquad i_2 = \frac{v}{R_2} = 15v$$

Üst düğümde 120 A giriyor, diğerleri çıkıyor:

$$30v + 30 + 15v = 120 \quad \Rightarrow \quad 45v = 90 \quad \Rightarrow \quad v = 2 \text{ V}$$

Hoca çözümün başında 120 A'lik kaynağın enerji verdiğini peşin söylemişti, bu noktada bir soru geldi.

**Soru:** Eksi ve artıya bakarak kaynak "devreye güç sağlıyor" dedik. O bizim belirlediğimiz bir şey değil mi? Gerilim negatif çıkamaz mı?

**Cevap:** Çıkabilir. Negatif çıksaydı bu eleman enerji tüketen bir eleman olurdu. Yani bu yorumu baştan değil, sonuç olarak söylemek daha doğrudur. $v$ pozitif çıktığı için artık 120 A'lik kaynağın sisteme enerji sağladığı, 30 A'lik kaynağın enerji tükettiği nihai sonuç olarak söylenebilir.

Güçler:

| Eleman | Hesap | Güç |
|---|---|---|
| 120 A'lik kaynak | $-2 \cdot 120$ | $-240$ W (verir) |
| $R_1$ | $\dfrac{v^2}{R_1} = \dfrac{4}{1/30}$ | $120$ W |
| 30 A'lik kaynak | $2 \cdot 30$ | $60$ W (çeker) |
| $R_2$ | $\dfrac{v^2}{R_2} = \dfrac{4}{1/15}$ | $60$ W |
| Toplam | | $0$ |

120 A'lik kaynakta akım, gerilim referansının eksisinden girdiği için eksi işaret vardır.

> **Ders sonrası not:** Hoca 30 A'lik kaynağın gücü için sözlü olarak "I çarpı R'den" dedi. Doğrusu $p = vi$'dir. Değer değişmez, 60 W'tır.

### 11.3 Bağımlı Akım Kaynaklı Örnek

6 kΩ ($i_6$ aşağı yönlü), yukarı yönlü $2i_x$ bağımlı akım kaynağı, yukarı yönlü 24 mA'lik bağımsız kaynak ve 2 kΩ paraleldir. $i_x$, 2 kΩ'luk dirençten üst düğüme doğru tanımlıdır. Bütün elemanların bir terminali üst düğüme, diğer terminali referans düğüme bağlıdır, yani devre paraleldir. Bağımsız kaynağın sağladığı güç isteniyor.

Üst düğümde $i_6$ çıkar, $2i_x$, 24 mA ve $i_x$ girer:

$$i_6 - 2i_x - 0.024 - i_x = 0$$

$i_6$ gerilim referansıyla uyumlu olduğu için $i_6 = v/6000$. $i_x$ ise $v$ referansına ters yönlü verildiği için:

$$i_x = -\frac{v}{2000}$$

Yerine konunca denklem yalnız $v$'ye bağlı kalır:

$$\frac{v}{6000} + \frac{3v}{2000} = 0.024 \quad \Rightarrow \quad \frac{v}{600} = 0.024 \quad \Rightarrow \quad v = 14.4 \text{ V}$$

Buradan $i_6 = 2.4$ mA, $i_x = -7.2$ mA, $2i_x = -14.4$ mA bulunur (ara adım eklendi). Python ile bu değerlerde KCL toplamının sıfır olduğu hesaplandı.

Bağımsız kaynağın gücünde akım, gerilim referansının eksisinden artısına doğru ilerler:

$$p = -14.4 \cdot 0.024 = -345.6 \text{ mW}$$

Güç negatiftir, kaynak devreye yaklaşık 345 mW sağlar.

### 11.4 $v_x$'e Bağlı Örnek

Yukarı yönlü 5.6 A, 18 Ω ($i_A$), yukarı yönlü $0.1v_x$ bağımlı akım kaynağı ($i_B$ aşağı yönlü), 9 Ω ($i_C$) ve aşağı yönlü 2 A paraleldir. Birinci düğüm ile referans düğüm arasında $v_x$ tanımlanır, üst düğümde KCL yazılır:

$$5.6 - \frac{v_x}{18} + 0.1v_x - \frac{v_x}{9} - 2 = 0 \quad \Rightarrow \quad v_x = 54 \text{ V}$$ <!-- BELİRSİZ: Değer altyazıda okunmuyor, kısa nottan alındı. -->

Sonra kol akımları bulunur:

$$i_A = \frac{54}{18} = 3 \text{ A}, \qquad i_B = -0.1 \cdot 54 = -5.4 \text{ A}, \qquad i_C = \frac{54}{9} = 6 \text{ A}$$

Hoca özel bir örnek olmadığını belirterek geçti.

## 12. Seriliği ve Paralelliği Tanımak

### 12.1 Seri Elemanlar

Seri elemanlardan geçen akım, diğer parametreler değiştikçe eş yönlü olarak değişir. Seri bağlılığın bir özelliği, iki elemanın ortak bir terminale sahip olmasıdır. Fakat o ortak düğüme başka bir eleman bağlanırsa serilik bozulur.

Hoca bunu üç gözlü devrede gösterdi. 60 V'luk kaynak ile 8 Ω birbirine seridir. 8 Ω ile 4 Ω ise seri değildir, çünkü ortak düğümlerine başka bir eleman daha bağlıdır.

Başka bir devrede $R_3$ ile 36 V'luk kaynak seridir. $R_4$, fasulye eleman, diğer eleman ve bağımsız kaynak da birbirini takip eden çiftler arasında tek ortak terminal bulunduğu için seridir. $R_2$ için ise herhangi bir serilik söz konusu değildir.

### 12.2 Paralel Elemanlar

Paralel elemanlar iki adet ortak terminal barındırır. Tek düğüm çiftli devrede bütün kaynaklar ve dirençler için her çift iki ortak terminale sahiptir. Bu yüzden her çift kendi arasında paraleldir, dolayısıyla bütün elemanlar birbirine paraleldir.

Üç gözlü devrede ise bağımlı kaynak ile 2 Ω'luk direncin üst ve alt terminalleri ortaktır, bu ikisi paraleldir. Başka tekil bir paralellik yoktur.

### 12.3 Eleman Grupları

Serilik ve paralellik yalnız tekil elemanlar arasında değil, eleman grupları arasında da tanımlanır. 60 V'luk kaynak ile 8 Ω seridir. Bu ikisinin oluşturduğu grup ile 10 Ω'luk direncin terminalleri ortaktır, yani grup ile 10 Ω birbirine paraleldir. Hoca, şeklin farklı çizilmiş olmasının bunu farklı hissettirebileceğini, ama terminallere bakmak gerektiğini gösterdi.

### 12.4 Örnek: Merdiven Yapısı

Verilen devrede 120 mA'lik kaynak, 125 Ω, 50 Ω, 2 Ω, 240 Ω, 40 Ω ve 20 Ω vardır. Devre sağdan sola doğru okunur:

1. Ortak terminal paylaşan 40 Ω ve 20 Ω seridir, eşdeğerleri 60 Ω'dur.
2. Bu 60 Ω'a 240 Ω paraleldir.
3. Bu gruba 2 Ω seridir.
4. Buraya kadarki gruba 50 Ω paraleldir.
5. Sonuçta 50 Ω, 125 Ω, 120 mA'lik kaynak ve işaretlenen grup birbirine paraleldir.

> **Ek bilgi (derste anlatılmadı):** Hoca burada yalnız 60 Ω'u söyledi. İki paralel direnç için $R_1 R_2 / (R_1 + R_2)$ kullanılırsa $60 \parallel 240 = 48$ Ω, 2 Ω ile birlikte 50 Ω olur. Kaynağın gördüğü direnç $50 \parallel 50 \parallel 125 = 20.83$ Ω, kaynak gerilimi 2.5 V'tur. Bölüm 12.6'daki sağ kol ise $2.25 + 3 + 5 + 2 = 12.25$ Ω'dur. Bu değerler kısa nottaki ek hesaplardır ve python ile hesaplandı.

### 12.5 Örnek: Kısa Devre Edilmiş Direnç

Solda 2 A'lik kaynak ve ona seri 1.5 Ω, ortada iki 4 Ω, iki 4 Ω'un üst uçları arasında 2 Ω, sağda 5 A'lik kaynak ve 5 Ω vardır. 2 Ω'un uçları bir kabloyla birbirine bağlanmıştır.

2 Ω'luk direncin terminalleri arasında kısa devre elemanı olduğu için akım kısa devreden geçmeyi tercih eder, 2 Ω yok hükmündedir. Bundan sonra hoca grupları dıştan içe çizdi:

1. 5 A'lik kaynak ile 5 Ω seridir.
2. Bunların oluşturduğu gruba sağdaki 4 Ω paraleldir.
3. Bu ikinci gruba soldaki 4 Ω paraleldir.
4. Bütünüyle 1.5 Ω ve 2 A'lik kaynak seri olur.

> **Ders sonrası not:** Kısa not, 2 A ile 1.5 Ω'dan oluşan seri kolun aynı düğüm çiftine bağlı olduğunu ve 4 Ω'larla paralel olduğunu söylüyor. Hoca ise bu kolu gruba "seri" diye adlandırdı. İki terminalli bir grup, iki terminalli tek bir kola bağlanınca iki ucu da ortak olur. Bu yüzden iki adlandırma büyük olasılıkla aynı yapıyı anlatıyor: kol içinde 1.5 Ω ile 2 A seridir, kolun tamamı ise grupla paraleldir. Şekil altyazıdan doğrulanamıyor.

**Soru:** Kısa devreye sebep olan bağlantı olmasaydı 2 Ω hangi değere paralel olurdu?

**Cevap:** Paralel değil, seri olurdu. Kısa devre olmasaydı 2 Ω, sağdaki 4 Ω ile 5 A-5 Ω'dan oluşan gruba seri olacaktı. Bunların birleştiği üst gruba da soldaki 4 Ω paralel olacaktı. Yani 2 Ω, soldaki 4 Ω ile grubun arasına seri olarak eklenmiş olurdu.

### 12.6 Örnek: Gruplarla Seri Kol

1 A'lik kaynak, 3 Ω ve 5 Ω paraleldir. En sağ kolda da birkaç grup vardır. 3 Ω ile 6 Ω iki ortak terminal paylaştığı için paraleldir. Bu gruba 5 Ω ve 3 Ω seridir. 3 Ω ile 9 Ω'luk paralel grup da bunlara seridir. Sağdaki kol tek bir grup olarak alındığında, 5 Ω, 3 Ω ve 1 A'lik kaynakla paraleldir.

## 13. Kaynakların Birleştirilmesi

### 13.1 Seri Gerilim Kaynakları

Gerilim kaynakları seri bağlanarak toplamları kadar potansiyel elde edilebilir. Seri kaynakların değerleri yönlü olarak toplanır.

Slaytta iki açık renkli terminal arasına $V_1$, $V_2$ ve $V_3$ bağlıdır. Bunların yerine, artı ucu üstte tek bir kaynak koymak istiyoruz. Eksi uçtan artı uca doğru yönlü toplama yapılınca $+V_3 - V_2 - V_1$ yazılır. Hocanın dediği gibi bunun negatifi, artı-eksi yönlü eşdeğer gerilimi verir:

$$V_{\text{eş}} = V_1 + V_2 - V_3$$

Karıştırmamak için artıdan eksiye doğru yönlü toplamak daha kolay olabilir.

<!-- BELİRSİZ: Slayttaki V1, V2, V3 kaynaklarının polariteleri altyazıda okunmuyor, sonuç hocanın sözlü toplamından kuruldu. -->

Hoca seri bağlı 1.5 V'luk kalem pilleri örnek gösterdi. Piller yerleşim olarak farklı görünse de her birinin artı terminali diğerinin eksi terminaline bağlıdır. Her düğüm bir öncekine göre 1.5 V daha yüksek potansiyeldedir. Son uç, referansa göre hepsinin toplamı kadar gerilime sahip olur.

### 13.2 Tek Çevreli Devreyi Basitleştirmek

Bu toplama, tek çevreli devreleri basitleştirmek için kullanılır. Örnek devrede 3 V, 9 V, 5 V ve 1 V'luk kaynaklar ile 100 Ω ve 220 Ω'luk dirençler seridir. KVL:

$$-3 - 9 + 100i - 5 + 1 + 220i = 0 \quad \Rightarrow \quad 320i = 16$$ <!-- BELİRSİZ: Değer altyazıda okunmuyor, kısa nottan alındı. -->

Hocanın okuyuşuyla referans gerilim 9, sonra 12, 1 V düşüp 11, 5 V artıp 16 V olur. Dirençler de seri olduğu için eşdeğer 320 Ω'dur:

$$i = \frac{16}{320} = 50 \text{ mA}$$

Eşdeğer kaynak devre içinde taşınabilir, sağda olmak yerine solda da olabilir. Şart, gerilim referans yönünün korunmasıdır. Yani çevre akım yönü kaynağın eksisinden girip artısından çıkıyorsa, kaynak taşındığında da bu ilişki korunmalıdır.

### 13.3 Paralel Gerilim Kaynakları

Gerilim kaynaklarının paralel bağlanması sıkıntılıdır. Yalnız gerilim değerleri eşitse olabilir. Değerler farklıysa gerilimi düşük olan kaynak, bir pil gibi şarj oluyormuş etkisi gösterir. Aradaki kablo çok düşük dirençli olduğu için bu şarj çok yüksek bir akımla olur. Kaynak bu akımı desteklemiyorsa zarar görür, yanar.

Hoca kendi başından geçen bir olayı anlattı: Bir kuru aküyü ters referans yönüyle yanlışlıkla şarj etmiş ve akünün artı ve eksi yönleri dönmüştü.

> **Hocanın vurgusu:** Farklı değerli gerilim kaynaklarını paralel bağlamak ideal bir bağlantı değildir, pratikte kaçınılması gereken bir durumdur.

### 13.4 Paralel Akım Kaynakları

Akım kaynaklarının paralel bağlanması ise ideal bir durumdur. Bir nokta referans gibi seçilirse, diğer düğümden çıkacak akım paralel kaynakların toplamı olur. Yani içi boş iki düğüm arasında akması gereken akım, paralel kaynakların yönlü toplamıdır. Eşdeğer kaynak yukarı yönlü seçildiyse yukarı yönlü kaynaklar artı, aşağı yönlüler eksi girer.

Aynı kural gerilim kaynaklarında da benzer biçimde akılda tutulabilir: Eşdeğer kaynağın artısı üstteyse, artısı üstte olan kaynaklar toplama artı, ters yönlü olanlar eksi girer.

> **Ek bilgi (derste anlatılmadı):** Kısa not, farklı değerli akım kaynaklarının seri bağlanamayacağını da söylüyor (KCL çiğnenir), altyazıda bu sözlü olarak geçmiyor, büyük olasılıkla slaytta yer alıyor. Aynı biçimde kısa not, farklı değerli gerilim kaynaklarının paralel bağlanmasını KVL'nin çiğnenmesi olarak gerekçelendiriyor. Gerekçe büyük olasılıkla, iki durumda da kaynağın sabitlediği büyüklüğün iki farklı değer almak zorunda kalmasıdır.

### 13.5 Örnek: Üç Paralel Akım Kaynağı

Yukarı yönlü 2.5 A, 5 Ω, aşağı yönlü 2.5 A, 5 Ω ve aşağı yönlü 3 A paraleldir. Üç akım kaynağı tek kaynakla değiştirilebilir. Bunun için kaynağın diğerlerine paralel olması yeterlidir, araya eleman girmesi durumu değiştirmez.

Eşdeğer kaynak yukarı yönlü seçilirse:

$$I_{\text{eş}} = 2.5 - 2.5 - 3 = -3 \text{ A}$$

İki direnç eşit olduğu için akım ikiye bölünür, her birinden $-1.5$ A geçer. Paralel oldukları için gerilimleri de aynıdır:

$$v = -1.5 \cdot 5 = -7.5 \text{ V}$$

Hoca daha sonra bu örneğin aslında bir akım bölücü devre olduğunu, adını vermeden yapıldığını belirtti. Akım bölücü devreler bu derste işlenemedi, önümüzdeki haftaya kaldı.

## 14. Eşdeğer Direnç

### 14.1 Seri Dirençler

Amaç, seri bağlı dirençlerin yerine tek bir eşdeğer direnç koyabilmektir. $N$ adet seri dirençten oluşan tek çevreli bir devrede KVL:

$$v_s = v_1 + v_2 + \dots + v_N$$

Seri devrede bütün elemanlardan aynı akım geçtiği için:

$$v_s = iR_1 + iR_2 + \dots + iR_N = i(R_1 + R_2 + \dots + R_N)$$

Bütün seri dirençlerin yerine tek bir direnç konsaydı $v_s = iR_{\text{eş}}$ yazılacaktı. Karşılaştırınca:

$$R_{\text{eş}} = R_1 + R_2 + \dots + R_N$$

### 14.2 Terminalden Bakma Kavramı

Hoca bir önceki birleştirmeyi hatırlattı: DC kaynak terminalleri ile eşdeğer direnç terminalleri birbirine bağlanarak devre tamamlanmıştı. Burada da kaynağın artı-eksi terminallerine tek dirençlik, iki terminalli bir eleman bağlanıyor. Yani eşdeğer direnç, iki terminal ucundan görüldüğü şekliyle hesaplanır.

Örneğin $a$-$b$ terminallerinden bakıldığında seri bağlı 10, 30 ve 100 Ω'luk dirençlerin eşdeğeri 140 Ω'dur.

> **Hocanın vurgusu:** Hangi terminalden bakıldığı önemlidir. İlerleyen aşamalarda Norton ve Thevenin eşdeğerleri belirli bir terminalden bakılarak hesaplanacak. Bu yüzden terminalden bakma kavramını dikkat ederek öğrenin.

### 14.3 Multimetreyle Ölçüm

Deney yapılsaydı seri dirençler nasıl ölçülürdü? Değerleri tek tek toplamaktan daha pratik bir yol vardır, çünkü dirençlerin toleransları vardır. Seri grubun iki boş ucu olur, diğer bütün uçlar ortak kullanılır. Multimetre direnç ölçme konumuna, yani ohmmetre konumuna getirilir ve bu iki uç arasında ölçüm yapılır.

Direncin polaritesi yoktur. Kırmızı kablo pozitif referans, siyah kablo ortak referanstır, yani 0 V ucudur. Kablolar yer değiştirse de ölçülen değer değişmez.

**Soru:** Devrede bir güç kaynağı olsaydı ve ters bağlasaydık ne olurdu?

**Cevap:** Amaç bir terminalden bakıldığında görülen eşdeğer direnci ölçmekse, pratikte devredeki güç kaynağını ayırmak gerekir. Ayrılmazsa farklı bir ölçüm elde edilir. Bu örnekte zaten kaynak yok, yalnız seri dirençler ölçülüyor.

Aynı mantık paralel dirençlerde ve karmaşık seri-paralel direnç devrelerinde de geçerlidir. Gereklilik, ölçülen devrede kaynak beslemesi olmamasıdır. Bunun en kolay yolu, ölçülecek terminallerden birini devreden çıkarmaktır.

> **Hocanın vurgusu:** Devrede enerji varken ya da devreye kaynak bağlıyken eşdeğer direnç ölçümü yapmak anlamlı sonuç vermez.

### 14.4 Seri Dirençlerde Güç Dağılımı

Seri devrede bütün elemanlardan aynı akım geçer. $p = i^2 R$ formülünden her direncin gücü kendi direnciyle doğru orantılıdır. Direnç ne kadar yüksekse o dirence düşen güç o kadar yüksektir.

### 14.5 Paralel Dirençler

Paralel bağlı bir direnç grubu bir kaynakla besleniyor olsun. Kaynağın akım kaynağı olması bu aşamada daha anlamlı görünür, ama herhangi bir kaynak da olabilir. Bu kez KCL kullanılır:

$$I_s = I_1 + I_2 + \dots + I_N$$

Paralel yapıda her elemanın gerilim düşümü aynı $V$ olduğu için:

$$I_s = \frac{V}{R_1} + \frac{V}{R_2} + \dots + \frac{V}{R_N} = V\left(\frac{1}{R_1} + \frac{1}{R_2} + \dots + \frac{1}{R_N}\right)$$

Eşdeğer devrede kaynak aynen korunduğu için eşdeğer direnç üzerinde de aynı $V$ olmalıdır, yani $I_s = V / R_{\text{eş}}$. Karşılaştırınca:

$$\frac{1}{R_{\text{eş}}} = \frac{1}{R_1} + \frac{1}{R_2} + \dots + \frac{1}{R_N}$$

Terminal kavramı burada da geçerlidir. Bir tarafta yalnız kaynaktan oluşan bir eleman, diğer tarafta paralel direnç dizisinden oluşan bir grup vardır. Bu gruba terminalden bakıldığında görülen eşdeğer dirence karşılık tek bir eleman bağlanabilir. Hoca bu kavramın Norton ve Thevenin eşdeğerlerinde çok daha fazla anlam kazanacağını söyledi.

Pratikte ölçüm yine benzerdir. Paralel grup iki terminalli bir eleman gibi düşünülür. Arkasında karmaşık bir devre de olabilir, paralel dizi de, önemli değildir. Ohmmetre konumundaki multimetre bu terminal çiftine bağlanır. Polarite olmadığı için uçların yönü değişse de aynı değer görülür.

**Soru:** Ohmmetreyle ölçüm yaparken ohmmetre açık devre mi olur?

**Cevap:** Ohmmetre, voltmetre ya da ampermetreden farklıdır. Kaynak gibi davranır: Devreye bir test kaynağı sağlar ve ölçüm yapar. Örneğin bir gerilim uygular, uçlardaki akımı kontrol eder ve buna göre direnci hesaplar.

### 14.6 Paralel Dirençlerde Güç Dağılımı

Paralel elemanlarda gerilim aynı olduğu için hesap $p = v^2 / R$ üzerinden yapılır. $v^2$ bütün elemanlarda aynıdır. Direnç yükseldikçe harcanan güç azalır, yani güç dirençle ters orantılıdır.

### 14.7 Gösterim

Paralel bağlı dirençler için iki dik çizgi kullanılır: Şekildeki üç direnç için $R_1 \parallel R_2 \parallel R_3$ yazılır. Seri bağlı dirençler için ise virgül kullanılabilir.

## 15. Eşdeğer İletkenlik

Aynı mantık direnç değeri yerine iletkenlik değeri üzerinden de yürütülür.

### 15.1 Seri Bağlı İletkenlikler

Tek çevrim için KVL:

$$v_{in} = v_1 + v_2 + \dots + v_N$$

Ohm kanunu iletkenlikle $i = vG$ olduğu için $v_k = i / G_k$ yazılır. Akım bütün elemanlarda aynıdır:

$$v_{in} = i\left(\frac{1}{G_1} + \frac{1}{G_2} + \dots + \frac{1}{G_N}\right)$$

Tek bir eşdeğer eleman için $v_{in} = i / G_{\text{eş}}$ yazılacağından:

$$\frac{1}{G_{\text{eş}}} = \frac{1}{G_1} + \frac{1}{G_2} + \dots + \frac{1}{G_N}$$

Hoca buradaki benzerliğe dikkat çekti: Paralel bağlı dirençlerin eşdeğeri nasıl hesaplanıyorsa, seri bağlı iletkenliklerin eşdeğeri de aynı biçimde hesaplanır.

### 15.2 Paralel Bağlı İletkenlikler

Slaytta gerilim kaynağı bağlanmış, ama akım kaynağı da olur. Hoca akım kaynağıyla yürüdü. KCL:

$$I_s = I_1 + I_2 + \dots + I_N$$

Her elemanda aynı gerilim $V$ düştüğü ve $I_k = V G_k$ olduğu için:

$$I_s = V(G_1 + G_2 + \dots + G_N)$$

Eşdeğer devrede $I_s = V G_{\text{eş}}$ olması gerektiğinden:

$$G_{\text{eş}} = G_1 + G_2 + \dots + G_N$$

## 16. Eşdeğer Devreyle Çözüm Örnekleri

### 16.1 Seri Devre: 80 V'luk Kaynak

$i$ akımı ve 80 V'luk kaynağın gücü isteniyor. Devrede 80 V, 30 V ve 20 V'luk kaynaklar ile 10, 7, 5 ve 8 Ω'luk dirençler seridir. İki özellik kullanılır: Tek çevreli devrede kaynakların eşdeğerliği ve seri dirençlerin eşdeğerliği.

Kaynaklar ve dirençler yer değiştirince ana kol akımı değişmez, yeter ki yönler korunsun. Kaynaklar yan yana getirilir. Çevre yönü 20 V'luk kaynağa artısından giriyorsa kaynak taşındıktan sonra da artısından girmelidir.

Eşdeğer kaynağın artısı üstte seçilince 80 ve 30 katkı yapar, 20 ters yönde katkı yapar:

$$V_{\text{eş}} = 80 + 30 - 20 = 90 \text{ V}$$

Dirençler toplanır, hocanın ara toplamlarıyla 17, 22, 30:

$$R_{\text{eş}} = 10 + 7 + 5 + 8 = 30 \text{ Ω}$$

$$i = \frac{90}{30} = 3 \text{ A}$$

80 V'luk kaynakta akım eksisinden girip artısından çıktığı için:

$$p = -80 \cdot 3 = -240 \text{ W}$$

Kaynak devreye 240 W verir.

### 16.2 Paralel Devre: Üç Akım Kaynağı

Yukarı yönlü 5 A, 10 Ω, aşağı yönlü 1 A, 10 Ω ve yukarı yönlü 6 A paraleldir. $V$ gerilimi isteniyor. Paralel elemanların yerleri de oynatılabildiği için hoca devreyi kaynaklar yan yana gelecek şekilde yeniden çizdi.

Eşdeğer akım kaynağı:

$$I_{\text{eş}} = 5 - 1 + 6 = 10 \text{ A}$$

Eşit iki direnç paralel olduğu için eşdeğer yarı yarıyadır:

$$R_{\text{eş}} = 10 \parallel 10 = 5 \text{ Ω}$$

Hoca önce 10 A'i 5 Ω'a böldü ve kol akımlarından yola çıkarak 10 V buldu. Bir öğrenci amperin volt gibi bölündüğünü gösterdi, hoca da düzeltti. Doğrusu çarpmaktır:

$$V = I_{\text{eş}} R_{\text{eş}} = 10 \cdot 5 = 50 \text{ V}$$

Kontrol: 10 A iki eşit direnç arasında paylaşılır, her birinden 5 A geçer. Her direnç için $5 \cdot 10 = 50$ V bulunur, aynı sonuçtur.

## 17. Direnç Değerinin ve Direnç Sayısının Etkisi

Hoca iki soruyla eşdeğer direncin nasıl etkilendiğini inceledi. Her bir direncin eşit olduğu varsayıldı.

| Değişiklik | Seri bağlama | Paralel bağlama |
|---|---|---|
| Her direncin değeri artırılırsa | Eşdeğer artar | Eşdeğer artar |
| Aynı değerli direnç sayısı artırılırsa | Eşdeğer artar | Eşdeğer azalır |

Paralel bağlı durumda bunun sebebi, aynı direnç değerinin $N$ yerine örneğin $2N$'ye bölünmek zorunda kalmasıdır. $N$ tane eşit $R$ paralel bağlıyken eşdeğer $R / N$ olur. $R$ büyürse eşdeğer büyür, $N$ büyürse eşdeğer küçülür.

## 18. Dualite

Dersin sonunda hoca bir özet tablo üzerinden dualiteden, yani birbirinin ikili durumlarından söz etti. Direnç ile iletkenlik birbirinin dualidir. Seri bağlı dirençlerin eşdeğeri, paralel bağlı iletkenliklerin eşdeğeriyle aynı şekilde hesaplanır. Tersi de doğrudur. Akım ile gerilim de benzer biçimde birbirinin ikilisidir. Bu ilişkiyi önümüzdeki haftanın konuları olan çevre ve düğüm denklemlerinde daha pratik biçimde kullanacağız.

| Seri tarafı | Paralel tarafı |
|---|---|
| Direnç: $R_{\text{eş}} = \sum R_k$ | İletkenlik: $G_{\text{eş}} = \sum G_k$ |
| İletkenlik: $\dfrac{1}{G_{\text{eş}}} = \sum \dfrac{1}{G_k}$ | Direnç: $\dfrac{1}{R_{\text{eş}}} = \sum \dfrac{1}{R_k}$ |
| Aynı akım | Aynı gerilim |

<!-- BELİRSİZ: Slayttaki özet tablonun tam içeriği altyazıda okunmuyor. Yukarıdaki tablo derste türetilen formüllerden kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** Kısa not dual çiftleri KVL ile KCL, kısa devre ile açık devre, gerilim kaynağı ile akım kaynağı olarak da sıralıyor. Bu çiftler altyazıda sözlü olarak geçmiyor, büyük olasılıkla slayttaki özet tablodan alınmıştır. Dualite sayesinde bir yapı için bulunan formül, dual yapıda karşılıkları yerine konarak kullanılır.

## Dersin Toparlaması

Bu derste direnç elemanı özdirençten yola çıkılarak tanıtıldı, iletkenlik onun tersi olarak tanımlandı ve direncin her zaman güç çeken, gücü ısı olarak yayan bir eleman olduğu gösterildi. Düğüm ve çevre kavramları üzerine Kirchhoff'un iki yasası kuruldu. Akımlar yasası yükün korunumuna, gerilimler yasası enerji ile güce dayanır. Akım kaynağı içeren çevrelerde uygun çevre seçmenin, bağımlı kaynakta ise kontrol değişkenini referans yönüyle birlikte ana büyüklük cinsinden yazmanın işi nasıl çözdüğü örneklerle görüldü. Sonuçlar, toplam gücün sıfır çıkmasıyla kontrol edilebilir.

Tek çevreli devreler seriliğe, tek düğüm çiftli devreler paralelliğe götürdü. Seri gerilim kaynakları ve paralel akım kaynakları yönlü olarak toplandı, seri ve paralel dirençler için eşdeğer direnç türetildi. Terminalden bakma fikri ileride Norton ve Thevenin eşdeğerlerinde kullanılacak. Dersin başında planlanan gerilim bölücü ve akım bölücü devreler önümüzdeki haftanın başına kaldı. Dualite ise çevre ve düğüm denklemlerinde yeniden karşımıza çıkacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
