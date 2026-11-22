# Ders 1 Genişletilmiş Notu: Lojik Kapılar ve Boole Cebri Tekrarı, Karnaugh Haritası, Sayı Gösterimleri, Multiplexer ve Decoder

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Kapsamı
- 2. Temel Lojik Kapılar
- 3. Tam (Complete) Kapı Kümeleri
- 4. Lojik Fonksiyonların İfade Biçimleri ve Çoğunluk Fonksiyonu
- 5. Boole Cebri Eşitlikleri
- 6. Çoğunluk Fonksiyonunun Yalnız NAND ile Gerçeklenmesi
- 7. Karnaugh Haritası
- 8. Sayı Sistemleri ve İşaretli Sayı Gösterimleri
- 9. Karnaugh Haritasında Don't Care ve XOR Durumları
- 10. Multiplexer (MUX)
- 11. Decoder
- Örnek Sorular

## 1. Dersin Amacı ve Kapsamı

Ders, bir bilgisayarın hangi birimlerden oluştuğunu, bu birimlerin arka planda nasıl tasarlandığını ve birbirine nasıl bağlandığını inceler. Temel amaç bir işlemcinin iç yapısını tasarlamak ve çalışan bir örneğini analiz etmektir. Bunun için Lojik Devreler dersindeki bilgiler gerekir; ancak orada fonksiyonlar tek bir değişken (tek bit) üzerinden tanımlanmıştı. Modern bir bilgisayarda ise veri yolları ve adres yolları vardır, bu yüzden bu derste kombinasyonel ve ardışıl devrelerin n bitlik versiyonları ele alınır.

Haftalık planda konular şu sırayla ilerler (ekrandan, 00:10:00): bilgisayar donanımına giriş, kombinasyonel ve ardışıl lojik devreler, saklayıcılar ve sayıcılar, programlanabilir yapılar (PLD, PLA, PAL), bellek birimleri (RAM, ROM), saklayıcılar arası transfer işlemleri ile ortak veri yolu oluşturma, komut yapısı ve adresleme yöntemleri, merkezi işlem birimi tasarımı ve pipeline ile veri işleme, giriş/çıkış birimleri ve haberleşme, ön bellek (cache) yapısı ve eşleme (map) teknikleri, sanal bellek yapısı ve sayfa tabloları. Saklayıcı (register) yapılarından başlayarak ALU, veri aktarımı, komut çözme (instruction decode), ROM ve RAM gibi birimler eklenerek bir CPU tasarımı adım adım kurulacaktır. Merkezi işlem birimi kısmında önce toplayıcı-çıkarıcı devre, sonra aritmetik ve lojik birimlerden oluşan ALU ve shifter modülü tasarlanıp sisteme eklenecektir.

Hoca, donanımın komut kümesiyle yakından ilişkili olduğunu vurguladı: desteklenmesi istenen her komutun (instruction) donanım tarafında bir karşılığı olmalıdır. Bu yüzden ders, assembly ya da komut kümesi mimarisi (instruction set architecture) ile onun donanım karşılığını birbirine bağlayacaktır.

Referans kitap M. M. Mano ve C. R. Kime, *Logic and Computer Design Fundamentals*, 5. baskıdır (ekrandan, 00:10:00). Dersteki akış ve temel örnekler bu kitaba dayanır.

**Soru:** Derste ne kadar assembly ve kod yazımı, algoritma gerçekleme yapılacak? **Cevap:** Ders kapsamında kod yazma yoktur. Ancak hoca, yapılan tasarım örneklerini mümkün olduğunca Verilog ile göstermeye çalışacağını söyledi.

## 2. Temel Lojik Kapılar

Lojik Devreler dersinden bilindiği gibi temel kapılar AND, OR ve NOT'tır; NAND, NOR ve XOR bunların türevleridir. Bu üç işlem (AND, OR, NOT) temel lojik fonksiyonlardır ve diğer bütün lojik fonksiyonlar bunlar üzerinden tanımlanabilir.

Dijital tasarım teknolojisinin geldiği noktada NAND ya da NOR temelli tasarımlar öne çıkmıştır. AND, OR ve NOT kapılarının hepsi tek çeşit kapıyla (örneğin yalnız NAND ile) gerçeklenebildiği için üreticiler tek bir lojik tasarım üzerinden üretim yapmayı tercih eder. Bunda CMOS (complementary MOS) teknolojisinin gelişmesinin önemli katkısı vardır. Transistör üretim teknolojileri sırasıyla RTL (direnç-transistör lojiği), TTL (transistör-transistör lojiği), MOS ve CMOS olarak gelişmiştir. CMOS'un en büyük katkısı, yalnız durum değişimi anında enerji harcaması, bunun dışında (küçük kaçak akımlar ihmal edilirse) enerji harcamadan durumunu tutabilmesidir. Bu, daha düşük enerjiyle çalışan sistemlerin ortaya çıkmasını sağlamıştır.

Kapıların tanımları:

- AND: iki ya da n girişli olabilir; herhangi bir girişi 0 olduğunda çıkışı 0'dır. Gösterimi $A\cdot B$.
- OR: girişlerinden herhangi biri 1 olduğunda çıkışı 1'dir. Gösterimi $A+B$.
- NOT: girişin lojik tersini üretir. Gösterimi $A'$ ya da $\bar{A}$. Şemada üçgen bir buffer'a, yuvarlak ise tersleyiciye karşılık gelir; NOT kapısı bu ikisinin birleşimidir.
- NAND: AND kapısının tersi; iki giriş de 1 iken 0, diğer durumlarda 1. Bu tek satır durumu, "iki giriş de 1 olduğunda aktif 0 üreten" bir yapı olarak düşünülebilir; aktif 0 chip select girişine sahip bir entegreyi seçmekte kullanılabilir.
- OR'un 0 çıktığı tek satır, girişlerin ikisinin de 0 olduğu satırdır; yani iki giriş de 0 iken aktif 0 çalışan bir entegre seçilebilir.
- NOR: $(A+B)'$; iki giriş de 0 iken çıkışı 1'dir, bu yüzden aktif 0 girişlerle aktif 1 bir entegre seçilebilir.
- XOR: girişler aynıyken 0, farklıyken 1. Temel işlemler cinsinden $A\oplus B = A\bar{B} + \bar{A}B$.

> **Hocanın vurgusu:** Lojik kapı sembolleri doğru çizilmelidir. Çizimden emin değilseniz kapının içine gerçekleştirmesini istediğiniz fonksiyonu (AND, OR vb.) mutlaka yazın. Hoca, üst sınıflardaki mikroişlemciler dersinde bile kapı çizimlerinin ayırt edilemediği durumlar yaşandığını anlattı.

## 3. Tam (Complete) Kapı Kümeleri

Tam küme kavramı, her türlü lojik fonksiyonu gerçekleyebileceğimiz kapı kümesini ifade eder. Slayttaki tanıma göre bir kapı kümesi, yalnız kümedeki kapı türleri kullanılarak herhangi bir lojik fonksiyon gerçeklenebiliyorsa tamdır. Minimal tam küme ise gereksiz elemanı olmayan tam kümedir (ekrandan, 00:25:00). Yani kümeden herhangi bir kapı çıkarıldığında artık bazı fonksiyonlar gerçeklenemiyorsa küme minimaldir.

Slayttaki örnek tam kümeler: {AND, OR, NOT} (minimal değil), {AND, NOT}, {OR, NOT}, {NAND}, {NOR}.

### 3.1 {AND, OR, NOT} neden minimal değil?

Bu kümeden bir kapı (örneğin OR) çıkarılsa bile kalan iki kapıyla çıkarılan kapının fonksiyonu elde edilebilir. Hoca, yalnız AND ve NOT kullanarak $A+B$'nin nasıl elde edileceğini sordu.

**Soru:** Yalnız AND ve NOT kullanarak $A+B$ nasıl elde edilir? **Cevap:** Bir öğrenci De Morgan kuralını önerdi. $\bar{A}\cdot\bar{B}$ ifadesinin tersi alınır: $(\bar{A}\cdot\bar{B})'$. De Morgan kuralına göre dıştaki tümleyen içeri dağıtılırken hem değişkenler terslenir hem de işlem ikiz işlemine (AND yerine OR) dönüşür: $(\bar{A}\cdot\bar{B})' = A + B$. Böylece {AND, NOT} kümesi tam kümedir.

Aynı mantık {OR, NOT} için de geçerlidir: AND işlemi $A\cdot B = (\bar{A}+\bar{B})'$ olarak yalnız OR ve NOT ile elde edilir.

### 3.2 Yalnız NAND ile NOT, AND ve OR

Yalnız NAND ile çalışırken önce NOT kapısından başlamak pratiktir. Tahtada iki girişli NAND'in doğruluk tablosu yazıldı: $AB = 00, 01, 10, 11$ için çıkış $1, 1, 1, 0$ (ekrandan, 00:30:00).

**Soru:** İki girişli bir NAND kapısıyla $X$ girdisinden $X'$ nasıl üretilir? **Cevap:** Bir öğrenci girişlerin birleştirilmesini önerdi. Girişler birleştirilince doğruluk tablosunun yalnız iki girişin eşit olduğu satırları (00 ve 11) kullanılır; bu satırlarda çıkış girişin tersidir (00 → 1, 11 → 0). Dolayısıyla çıkış $X'$ olur.

**Soru:** Başka bir çözüm var mı? **Cevap:** Bir öğrenci bir girişe $X$, diğerine 1 verilmesini önerdi. $B = 1$ olan satırlarda $A$'ya ne verilirse çıkış onun tersidir. NAND simetrik olduğu için ($A$ ve $B$'nin yerleri değişebilir) $A = 1$ olan satırlarda da aynı durum geçerlidir; hangi uca 1 verildiği fark etmez. Hoca pratik olduğu için ilk yöntemi (girişleri birleştirme) kullanacaklarını söyledi.

**Soru:** NAND ile AND nasıl yapılır? **Cevap:** Bir öğrenci sona bir NOT eklemeyi önerdi. $X$ ve $Y$ girişli NAND'in çıkışı $(X\cdot Y)'$'dir; bu çıkış, NAND'den yapılmış bir NOT kapısına verilince $((X\cdot Y)')' = X\cdot Y$ elde edilir (ekrandan, 00:35:00).

OR işlemi biraz daha karışıktır. NAND $(X\cdot Y)'$ üretir; De Morgan ile bu $X' + Y'$'dir, yani girişlerin terslerini toplar. Toplama vardır ama girişlerin tersleri gelmiştir. O halde NAND'in girişlerine $X'$ ve $Y'$ verilirse çıkış $(X'\cdot Y')' = X + Y$ olur. Devrede $X$ ve $Y$ önce NAND ile yapılmış iki NOT kapısından geçirilir, sonra bir NAND'e verilir (ekrandan, 00:35:00).

Aynı işlemler yalnız NOR kapısıyla da yapılabilir; hoca bunu zorunlu olmayan bir alıştırma olarak bıraktı (bkz. Örnek Sorular).

Özetle: {AND, NOT}, {OR, NOT}, yalnız NAND ve yalnız NOR kümeleri minimal tam kümelerdir. {AND, OR, NOT} ise bir kapı çıkarılarak daha küçük bir tam küme elde edilebildiği için minimal değildir.

## 4. Lojik Fonksiyonların İfade Biçimleri ve Çoğunluk Fonksiyonu

Slayta göre lojik fonksiyonlar birkaç şekilde ifade edilebilir: doğruluk tablosu, lojik ifadeler, grafik biçim ve HDL kodu (ekrandan, 00:40:00). Bunlar sözel bir tanımdan donanım gerçeklemesine geçmenin dört yoludur.

- **Doğruluk tablosu:** Sözel olarak tanımlanan fonksiyon bir doğruluk tabloya dökülür. Bu, look-up table (LUT) tabanlı tasarım için önemlidir. Look-up table aslında bir ROM gibi bir bellek birimidir: n girişli, m çıkışlı bir ROM, n girişli m çıkışlı bir fonksiyon grubunun doğruluk tablosunu tutar. ROM'un adresleri doğruluk tablosunun satırlarına, ROM'un çıkışları fonksiyon çıkışlarına karşılık gelir.
- **Lojik ifadeler:** Doğruluk tablosundan bir adım ilerisi; çarpımlar toplamı ya da toplamlar çarpımı biçimindeki ifadeler ve bunların Karnaugh haritasıyla indirgenmiş halleri. Yazılan bir fonksiyonda bir değişken ya da işlem kaldırıldığında sonuç değişmiyorsa, fonksiyon daha da indirgenebilir demektir. Verilog'da lojik fonksiyonlar doğrudan yazılarak çıktı elde edilebilir.
- **Grafik biçim:** Şematik çizim. Bazı FPGA araçlarında grafik tasarım doğrudan koda dönüştürülebilir.
- **HDL kodu:** Verilog, VHDL gibi donanım tanımlama dilleriyle yazım.

### 4.1 Çoğunluk fonksiyonunun tanımı ve doğruluk tablosu

Örnek olarak üç girişli çoğunluk (majority) fonksiyonu ele alındı: $M = f(a,b,c)$; girişlerin çoğunluğu 1 ise $M = 1$, aksi halde $M = 0$ (ekrandan, 00:45:00). Üç girişte çoğunluk, iki ya da üç girişin 1 olması demektir.

Üç lojik giriş varsa her değişken iki değer alabildiğinden doğruluk tablosu $2^3 = 8$ satırlıdır. Tahtadaki tablo (ekrandan, 00:45:00):

| a | b | c | M |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 |

**Soru:** Üç değişkenle kaç farklı lojik fonksiyon yazılabilir? **Cevap:** Bir öğrenci önce $2^3$ dedi; hoca cevabın $2^3$ olmadığını söyledi, öğrenci $2^8$ diye düzeltti. Doğrusu $2^{2^3} = 2^8 = 256$'dır. Tabloda 8 satır vardır ve her satırın çıkışı 0 ya da 1 olabilir; her satır için 2 seçenek olduğundan toplam $2^8$ farklı fonksiyon yazılır. Bunlardan biri her satırda 0 üreten fonksiyon, biri her satırda 1 üreten fonksiyon, biri de $C$'den bağımsız $A\cdot B$ fonksiyonudur. Yani kaç bitlik olursa olsun bütün fonksiyonlar baştan sayılabilir.

### 4.2 Çarpımlar toplamı (mintermler)

Fonksiyonun en genel minterm yazımı şudur:

$$M = \sum_{i} m_i \cdot M(i)$$

Burada $m_i$, $i$ numaralı satırın mintermi; $M(i)$ ise o satırdaki fonksiyon çıkışıdır. $i$ numaralı minterm, o satırdaki değerler verildiğinde 1 üreten çarpım terimidir. Satırda 0 olan değişkenin tersi, 1 olan değişkenin kendisi yazılır:

- $m_0$: $a = 0, b = 0, c = 0$ iken 1 üreten terim, yani $\bar{a}\bar{b}\bar{c}$.
- $m_1$: $\bar{a}\bar{b}c$.
- $m_7$: $abc$.

Genel formül açıldığında $M = \bar{a}\bar{b}\bar{c}\cdot 0 + \bar{a}\bar{b}c\cdot 0 + \bar{a}b\bar{c}\cdot 0 + \bar{a}bc\cdot 1 + a\bar{b}\bar{c}\cdot 0 + a\bar{b}c\cdot 1 + ab\bar{c}\cdot 1 + abc\cdot 1$ olur. Sıfırla çarpılan terimler düşer; 1 çarpmada etkisiz eleman olduğundan diğerlerinden atılır. Geriye yalnız çıkışı 1 olan satırların (doğru mintermlerin) toplamı kalır:

$$M = \bar{a}bc + a\bar{b}c + ab\bar{c} + abc$$

Bu, doğru mintermlerin toplamıdır: fonksiyonun 1 olduğu satırların mintermleri toplanır.

**Soru:** Minterm yazarken bütün değerlerin 1 olmasını mı istiyoruz? Çoğunluk fonksiyonunda değişkenlerden biri 0 olsa da çıkış 1 olabiliyor. **Cevap:** Örneğin $m_0$ için $a = 0, b = 0, c = 0$ verildiğinde 1 üreten tek bir çarpım terimi aranır; bu $\bar{a}\bar{b}\bar{c}$'dir. Öğrencinin söylediği durum fonksiyonun çıkış sütunuyla ilgilidir. Herhangi bir üç değişkenli fonksiyonun mintermleri aynı şekilde yazılır; fonksiyona göre değişen tek şey her mintermin 0 ile mi 1 ile mi çarpıldığıdır.

### 4.3 Toplamlar çarpımı (maxtermler)

Aynı fonksiyon maxtermlerle de yazılabilir. Maxterm ile karışmaması için fonksiyonun adı $Maj$ olarak yazıldı:

$$Maj = \prod_i \left(M_i + Maj(i)\right)$$

Bu kez ilgili satırdaki değerler verildiğinde 0 üreten bir toplam terimi aranır. $M_0$, $a = b = c = 0$ iken 0 üreten toplamdır: $(a+b+c)$. Pratik kural: satırdaki değer 0 ise değişken olduğu gibi, 1 ise tersi yazılır. $M_1$ için $a = 0, b = 0, c = 1$ olduğundan $(a+b+c')$ yazılır (ekrandan, 01:10:00).

Genel formül açılınca $(a+b+c+0)(a+b+c'+0)(a+b'+c+0)(a+b'+c'+1)\cdots(a'+b'+c'+1)$ biçimini alır (ekrandan, 01:10:00). Çıkışı 1 olan satırlarda parantez 1 olur ve çarpmada etkisiz olduğundan düşer; çıkışı 0 olan satırlarda eklenen 0 toplamada etkisizdir ve atılır. Geriye çıkışı 0 olan satırların (yanlış maxtermlerin) çarpımı kalır:

$$Maj = (a+b+c)(a+b+c')(a+b'+c)(a'+b+c)$$

> **Ders sonrası not:** Hoca bu kısmın sonunda bir önceki örneği bir an "yanlış min termlerin toplamı" diye andı, hemen ardından "doğru min termlerin toplamı" diye düzeltti. Doğrusu: çarpımlar toplamı doğru mintermlerin toplamı, toplamlar çarpımı yanlış maxtermlerin çarpımıdır.

### 4.4 Lojik çıkarımla indirgenmiş hal ve grafik gösterim

Çoğunluğun 1 olması, $a$, $b$, $c$'den en az ikisinin 1 olması demektir (ekrandan, 01:15:00). Bu durumda $a, b$ çifti; $b, c$ çifti ya da $a, c$ çiftinden biri tamamen 1 ise çıkış 1 olmalıdır. Bir çiftin ikisinin de 1 olduğu, o çiftin çarpımının 1 olmasıyla anlaşılır ($a\cdot b = 1$ ise $a$ ve $b$ 1'dir). Sonuç:

$$Maj = ab + bc + ac$$

Grafik gösterimde $a$, $b$, $c$ için dikey hatlar (ray) çizilir, $ab$, $bc$, $ac$ çarpım terimleri üç adet iki girişli AND kapısıyla oluşturulur ve üç girişli bir OR kapısında birleştirilir (ekrandan, 01:15:00).

Dört girişli çoğunluk fonksiyonunda en az üç girişin 1 olması gerekir; bu durumda dört adet üçlü çarpım teriminin ($abc$, $abd$, $acd$, $bcd$) 1 olup olmadığı kontrol edilir (ara adım eklendi: altyazıda terimlerden biri bozuk duyulmuş, dörtte üçlü dört kombinasyon budur).

## 5. Boole Cebri Eşitlikleri

Boole cebrinin temel eşitlikleri hatırlatıldı:

- **Etkisiz eleman:** AND için 1 ($x\cdot 1 = x$), OR için 0 ($x + 0 = x$).
- **Tümleyen:** Bir değişkenin tersi, değişkenle birlikte işleme sokulduğunda o işlemin yutan elemanını üretir: $x\cdot x' = 0$, $x + x' = 1$. Bu, matematikteki işlem konusundaki ters eleman tanımına benzer.
- **Yutan eleman:** $x\cdot 0 = 0$ (0, AND için yutan eleman), $x + 1 = 1$ (1, OR için yutan eleman).
- **Değişme:** $x\cdot y = y\cdot x$, $x + y = y + x$.
- **Dağılma:** Alışılmışın aksine hem AND'in OR üzerine hem de OR'un AND üzerine dağılma özelliği vardır: $x(y+z) = xy + xz$ ve $x + yz = (x+y)(x+z)$.
- **Idempotent (ara adım eklendi: adı hoca söylemedi):** $x\cdot x = x$, $x + x = x$.

Burada 0 ve 1 sabitlerdir; elektriksel olarak 0 volt lojik 0'a, 5 volt lojik 1'e karşılık gelir. $x$ ise 0 ya da 1 değerini alabilen, sabit olmayan bir lojik (boolean) değişkendir.

Slayttaki devam eşitlikleri (ekrandan, 01:20:00):

| Ad | AND versiyonu | OR versiyonu |
|---|---|---|
| Involution | $x = (x')'$ | — |
| Absorption (yutma) | $x\cdot(x+y) = x$ | $x + (x\cdot y) = x$ |
| Associative (birleşme) | $x(yz) = (xy)z$ | $x + (y+z) = (x+y)+z$ |
| De Morgan | $(x\cdot y)' = x' + y'$ | $(x+y)' = x'\cdot y'$ |

Involution yalnız NOT işlemiyle tanımlı olduğundan tek versiyonu vardır: tersin tersi değişkenin kendisidir. Yutma eşitlikleri doğruluk tablosuyla ya da formal olarak ispatlanabilir. De Morgan kuralı NOT işleminin değişkenlere ve AND/OR işlemlerine nasıl dağıldığını gösterir; slaytta da bu kuralın özellikle çok kullanışlı olduğu yazılıdır.

## 6. Çoğunluk Fonksiyonunun Yalnız NAND ile Gerçeklenmesi

Üretim teknolojisi açısından yalnız NAND ya da yalnız NOR ile tasarım önemli olduğu için, çoğunluk fonksiyonunun yalnız iki ve üç girişli NAND kapılarıyla gerçeklenip gerçeklenemeyeceğine bakıldı. Fonksiyon $Maj = ab + ac + bc$'dir ve AND-OR devresiyle çizilmiştir.

### 6.1 Grafik yöntem

$(x')' = x$ eşitliği grafik olarak şöyle kullanılır: bir hat üzerine art arda iki tersleyici (iki yuvarlak) konursa hiçbir şey değişmez. Bu tersleyicilerden biri AND kapısının çıkışına, diğeri OR kapısının girişine kaydırılır. Her AND kapısı çıkışındaki yuvarlakla NAND'e dönüşür (ekrandan, 01:25:00).

Geriye girişleri terslenmiş üç girişli OR kapısı kalır. Girişleri $x$, $y$, $z$ olan bu kapı $x' + y' + z'$ üretir. Tersin tersi alınıp ilk tümleyen içeri dağıtılırsa:

$$x' + y' + z' = \left((x' + y' + z')'\right)' = (x\cdot y\cdot z)'$$

Bu, üç girişli bir NAND kapısıdır (ekrandan, 01:25:00). Sonuç: girişleri $(a,b)$, $(b,c)$, $(a,c)$ olan üç adet iki girişli NAND ve bunların çıkışlarını birleştiren bir üç girişli NAND, çoğunluk fonksiyonunu verir.

### 6.2 Formal yöntem

$Maj = ab + bc + ac$ ifadesinin tersinin tersi alınır ve içteki tümleyen De Morgan ile dağıtılır:

$$Maj = \left((ab + bc + ac)'\right)' = \left((ab)'\cdot(bc)'\cdot(ac)'\right)'$$

İki değişkenin çarpımının tersi bir NAND kapısıdır; $(ab)'$, $(bc)'$ ve $(ac)'$ birer iki girişli NAND'dir. Bunlara $X$, $Y$, $Z$ denirse dıştaki $(X\cdot Y\cdot Z)'$ da üç girişli bir NAND'dir. Böylece grafik ve formal yöntem aynı sonucu verir. Bu eşdeğerlik python ile 8 satırın hepsinde kontrol edilmiştir.

## 7. Karnaugh Haritası

Karnaugh haritası indirgenmiş fonksiyonları yazmayı sağlar. Haritada iki komşu hücreyi birlikte almak, her iki terimde de aynı geçen değişkenleri ortak paranteze almak ve değişen değişkeni düşürmek demektir.

Doğruluk tablosundan haritaya geçerken satır ve sütun etiketlerine dikkat edilir: 00, 01, 11, 10 sırasında her adımda yalnız bir bit, yani yalnız bir değişken değişir. Dört değişkenli haritada hem satırlar hem sütunlar 00, 01, 11, 10 sırasıyla etiketlenir. Örneğin satır etiketi $x_1x_2 = 10$, sütun etiketi $x_3x_4 = 10$ olan hücre, ikili $1010$, yani doğruluk tablosunun 10 numaralı satırıdır.

### 7.1 Örnek: 2 bitlik karşılaştırma fonksiyonu

Hoca dört girişli bir fonksiyon tanımladı (ekrandan, 01:35:00):

$$f(a_1, a_0, b_1, b_0) = \begin{cases} 1, & (b_1b_0)_2 > (a_1a_0)_2 \\ 0, & \text{diğer durumlarda} \end{cases}$$

Burada $a_1a_0$ ikilisi 2 bitlik $A$ sayısını, $b_1b_0$ ikilisi $B$ sayısını oluşturur. Fonksiyon $B$, $A$'dan büyükse 1, eşit ya da küçükse 0 üretir; yani $A$ ile $B$'yi karşılaştıran bir devredir.

Doğruluk tablosu 16 satırlıdır. Örneğin $a_1a_0 = 00$, $b_1b_0 = 11$ satırında $B = 3 > A = 0$ olduğundan $f = 1$; $a_1a_0 = 11$, $b_1b_0 = 01$ satırında $A = 3$ büyük olduğundan $f = 0$. Bir öğrenci 6. satırı ($a_1a_0 = 01$, $b_1b_0 = 10$) sordu; burada $B = 2 > A = 1$ olduğundan $f = 1$'dir. Çıkışı 1 olan satırlar 1, 2, 3, 6, 7 ve 11 numaralı satırlardır (ekrandan, 01:35:00; python ile doğrulandı).

Karnaugh haritasında satırlar $a_1a_0$, sütunlar $b_1b_0$ ile etiketlenir. Doğruluk tablosunun ilk dört satırı ($a_1a_0 = 00$) haritanın ilk satırına yazılır; ancak sütun sırası 00, 01, 11, 10 olduğundan tablonun 3. ve 4. satırlarının yerleri değişir. Harita (ekrandan, 01:40:00):

| $a_1a_0 \backslash b_1b_0$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 00 | 0 | 1 | 1 | 1 |
| 01 | 0 | 0 | 1 | 1 |
| 11 | 0 | 0 | 0 | 0 |
| 10 | 0 | 0 | 1 | 0 |

Gruplama kuralları: birlikte alınan hücre sayısı 2'nin kuvveti (2, 4, 8, 16) olmalıdır. Bir satırın dördü, bir kare dörtlü, sekizli bir blok ya da hepsi aynıysa bütün harita alınabilir. Burada mintermlerle (1'ler) çalışılır; aynı işlem maxtermlerle 0'lar gruplanarak da yapılabilir. Gruplar olabildiğince büyük seçilmeli ve dışarıda hiçbir 1 kalmamalıdır. Tek kalan bir 1, daha önce bir gruba girmiş olsa bile başka bir hücreyle birlikte gruplanmalıdır. Harita üstten alta ve sağdan sola birbirine komşu bir küre gibi düşünülür; en üst satırdan en alt satıra geçişte de yalnız bir değişken değişir.

Gruplar (ekrandan, 01:40:00):

- **Turuncu dörtlü** ($a_1a_0 \in \{00, 01\}$, $b_1b_0 \in \{11, 10\}$): $a_1$ iki satırda da 0, $a_0$ değişiyor. $\bar{a}_1a_0 + \bar{a}_1\bar{a}_0 = \bar{a}_1(a_0 + \bar{a}_0) = \bar{a}_1$ olduğundan $a_0$ düşer. Sütunlarda $b_1 = 1$ sabit, $b_0$ değişiyor ve düşer. Dörtlü grupta dört değişkenden ikisi düşer, iki değişkenli terim kalır: $\bar{a}_1b_1$.
- **Yeşil ikili** ($a_1a_0 = 00$, $b_1b_0 \in \{01, 11\}$): Tek başına alınsaydı dört değişkenli bir terim gelirdi; yan komşusuyla alınınca bir değişken ($b_1$) düşer: $\bar{a}_1\bar{a}_0b_0$.
- **Kahverengi ikili** ($b_1b_0 = 11$, $a_1a_0 \in \{00, 10\}$, alt satırdan yukarı kenar komşuluğu): $b_1$ ve $b_0$ 1, $a_1$ değişiyor ve düşer: $\bar{a}_0b_1b_0$.

$$F = \bar{a}_1b_1 + \bar{a}_1\bar{a}_0b_0 + \bar{a}_0b_1b_0$$

Bu ifade python ile 16 satırın hepsinde doğrulanmıştır.

### 7.2 Eşitlik durumunun eklenmesi

Fonksiyon $B \ge A$ olarak değiştirilirse yalnız $A = B$ olan dört satır ($0000$, $0101$, $1010$, $1111$) 1 olur; haritada köşegendeki dört hücre eklenir (ekrandan, 01:45:00). Bu durumda daha büyük gruplar alınabilir. Karede görülen gruplar: üst satırın tamamı ($\bar{a}_1\bar{a}_0$), $b_1b_0 = 11$ sütununun tamamı ($b_1b_0$), ilk iki satır ile $01, 11$ sütunlarından oluşan kare ($\bar{a}_1b_0$), ilk iki satır ile $11, 10$ sütunlarından oluşan kare ($\bar{a}_1b_1$) ve $00$ ile $10$ satırlarının $11, 10$ sütunlarından oluşan kenar komşuluğu ($\bar{a}_0b_1$). Hoca "eksik ya da fazla aldıysam söyleyin" diyerek bu grupları gösterdi, terimleri ayrıca yazmadı.

> **Ek bilgi (derste anlatılmadı):** Karedeki beş gruptan oluşan $\bar{a}_1\bar{a}_0 + b_1b_0 + \bar{a}_1b_0 + \bar{a}_1b_1 + \bar{a}_0b_1$ ifadesi, $B \ge A$ fonksiyonunu 16 satırın hepsinde doğru verir (python ile kontrol edildi).

### 7.3 Mintermlerle yazmak ve Karnaugh indirgemesi

**Soru:** Karnaugh haritasıyla indirgemek ile mintermler şeklinde yazmak aynı şey mi? **Cevap:** Aynı şey değildir. Mintermlerle yazmak, doğruluk tablosundaki her 1 değerini hiç gruplama yapmadan tek tek fonksiyona eklemektir. Bu ifade yazıldıktan sonra formal olarak parantez işlemleri yapılsaydı, Karnaugh haritasında birlikte alınan grupların karşılığı elde edilirdi. Karnaugh haritasıyla indirgemek ise olası parantezleri görerek doğrudan indirgenmiş hali yazmaktır. Maxtermlerle çalışılsaydı her 0 satırı tek tek maxterm olarak yazılır, haritada da 0'lar 2'nin kuvveti büyüklüğünde gruplanırdı.

## 8. Sayı Sistemleri ve İşaretli Sayı Gösterimleri

Dijital bilgisayarda tutulan değerler ayrıklaştırılmıştır ve ikili (binary) olarak ifade edilir. Ancak ikili lojik tek seçenek değildir; üçlü ya da dörtlü değerli lojikler ve bunlara ait cebirler de tanımlanmıştır. Hoca, Sovyet döneminde her veri biriminin üç farklı değerden birini tutabildiği üçlü (ternary) bir bilgisayarın fiziksel olarak gerçekleştirildiğini anlattı. 8 veri biriminde ikili sistemde $2^8 = 256$ farklı değer (0-255) tutulabilirken, üçlü sistemde $3^8 = 6561$ farklı değer tutulabilir; kapasite büyük ölçüde artar.

Sayı sistemleri CPU tasarımında önemlidir; çünkü işaretli ve işaretsiz sayılarla aritmetik işlemler yapılacaktır ve bu değerlerin gösterimini bilmek gerekir.

### 8.1 İkili, sekizli ve onaltılı gösterim

Ondalık bir sayının ikili karşılığı, sayı sürekli ikiye bölünerek ve her bölümden kalan en düşük anlamlı bitten başlayarak yerleştirilerek bulunur. Kodlama aşamasında ve komut kümesi mimarisinde sayılar sekizli (octal) ve onaltılı (hexadecimal) da yazılabilir.

- **İkiliden sekizliye:** Üç ikili basamak 000'dan 111'e, yani 0-7 arasında değer alır; bu tam bir sekizli basamaktır. Sağdan itibaren üçlü gruplar ayrılır. Örnek: $12_{10} = 001\,100_2$; $100 = 4$, $001 = 1$, dolayısıyla $12_{10} = 14_8$ (ekrandan, 01:50:00).
- **İkiliden onaltılıya:** Dört ikili basamak 0000'dan 1111'e, yani 0-15 (0-F) arasında değer alır. Sağdan dörtlü gruplar ayrılır. Örnek: $18_{10} = 0001\,0010_2$; $0010 = 2$, $0001 = 1$, dolayısıyla $18_{10} = 12_{16}$ (ekrandan, 01:50:00).

Bu dönüşümler python ile kontrol edilmiştir.

> **Ders sonrası not:** Hoca onaltılı örneğe başlarken bir an "decimal 14" dedi, hemen ardından tablodaki 18 değerine geçti. Örnekteki sayı 18'dir.

### 8.2 İşaretsiz sayılar

İşaretsiz gösterimde sayının bütün basamakları genliği (büyüklüğü) hesaplamak için kullanılır. 4 bitlik aritmetikte 0000'dan 1111'e kadar her gösterimin 0-15 arasında bir ondalık karşılığı vardır.

### 8.3 İşaretli sayılar

İşaretli sayılar için üç yöntem vardır: işaret-büyüklük (sign and magnitude), 1'e tümleyen ve 2'ye tümleyen. Tasarımda 2'ye tümleyen kullanılacaktır; çünkü diğer iki yöntemde tekrarlı gösterim vardır (ekrandan, 01:55:00).

Slayttaki 4 bitlik işaretli sayı tablosunun bazı satırları (ekrandan, 01:50:00):

| $b_3b_2b_1b_0$ | İşaret-büyüklük | 1'e tümleyen | 2'ye tümleyen |
|---|---|---|---|
| 0111 | +7 | +7 | +7 |
| 0001 | +1 | +1 | +1 |
| 0000 | +0 | +0 | +0 |
| 1000 | −0 | −7 | −8 |
| 1001 | −1 | −6 | −7 |
| 1100 | −4 | −3 | −4 |
| 1110 | −6 | −1 | −2 |
| 1111 | −7 | −0 | −1 |

**İşaret-büyüklük:** 4 bitlik $ABCD$ sayısında en yüksek anlamlı bit işaret bitidir; 0 ise pozitif, 1 ise negatif. Kalan üç bit genliktir. Örnekler: $1001$'de işaret biti 1, genlik $001 = 1$, sayı $-1$; $0110$'da işaret biti 0, genlik $110 = 6$, sayı $+6$. Tekrarlı gösterim sıfırdadır: genlik sıfır olduğunda işaretin anlamı kalmaz; $0000 = +0$ ve $1000 = -0$ aynı değerdir. $2^4 = 16$ gösterimden biri boşa gider.

**1'e tümleyen:** Yine en yüksek bit işarettir. Sayı negatifse bütün bitlerin tersi ($\bar{A}\bar{B}\bar{C}\bar{D}$) alınıp genlik hesaplanır. Örnekler: $0101$ pozitif, $+5$; $1010$ negatif, tersi $0101 = 5$, sayı $-5$. Kayıp yine sıfırdadır: $0000 = +0$, $1111$'in tersi $0000$ olduğundan $1111 = -0$.

**2'ye tümleyen:** En yüksek bit 0 ise genlik olduğu gibi hesaplanır; 1 ise sayının 2'ye tümleyeni alınarak genlik bulunur. 2'ye tümleyen iki yolla hesaplanır:

- Önce 1'e tümleyen alınır, sonra 1 eklenir.
- Pratik yol: sağdan itibaren ilk 1 dahil bitler aynen bırakılır, sonraki bütün bitlerin tersi alınır.

Örnekler: $0100$ pozitif, genlik $4$, sayı $+4$. $1100$ negatif; 1'e tümleyeni $0011$, 1 eklenince $0100 = 4$, sayı $-4$. Pratik yolla: sağdan ilk bit 0 (aynen), ikinci bit 0 (aynen), üçüncü bit 1 (ilk 1, aynen), dördüncü bit 1'in tersi 0; sonuç $0100$, genlik 4. Hesaplar python ile kontrol edilmiştir.

## 9. Karnaugh Haritasında Don't Care ve XOR Durumları

Hoca, Karnaugh haritası anlatılırken atlanan iki konuya aradan sonra döndü.

### 9.1 Don't care durumları

Fonksiyon tanımında bazı satırların hangi değeri alacağı önemli değilse bunlar don't care (önemsiz) durumlar olarak ele alınır ve X ile işaretlenir. Bir X, daha büyük bir grup almayı sağlıyorsa 1 kabul edilir.

Örnek (ekrandan, 02:15:00):

$$F(A,B,C,D) = \sum m(1, 3, 7, 11, 15), \qquad d(A,B,C,D) = \sum m(0, 2, 5)$$

Dört değişkenli haritada satırlar $AB$, sütunlar $CD$ ile 00, 01, 11, 10 sırasında etiketlenir. Satırlar sırasıyla 0-3, 4-7, 12-15 ve 8-11 numaralı mintermlere karşılık gelir (hücre içindeki sıra 00, 01, 11, 10 sütun sırasını izler). 1 olan hücreler $m_1, m_3, m_7, m_{11}, m_{15}$; X olan hücreler $m_0, m_2, m_5$'tir.

- Don't care hiç hesaba katılmasa bile $CD = 11$ sütunundaki dört 1 ($m_3, m_7, m_{15}, m_{11}$) bir dörtlü olarak alınır: $CD$.
- Geriye $m_1$ kalır. $m_3$ ile ikili alınabilir; ancak $m_5$ (X) de 1 kabul edilirse $m_1, m_3, m_5, m_7$ dörtlüsü alınabilir. Bu tercih edilir.

Böylece $m_5$ doğru minterm olarak sabitlenmiş olur. Gruba alınmayan $m_0$ ve $m_2$ ise 0 olarak sabitlenmiş sayılır. İkili alınsaydı üç değişkenli bir çarpım terimi çıkacaktı; dörtlü alınınca terim iki değişkenliye iner.

> **Ek bilgi (derste anlatılmadı):** Gruplardan çıkan terimler $CD$ ve $\bar{A}D$'dir; sonuç $F = CD + \bar{A}D$ olur. Don't care kullanılmasaydı ikinci terim $\bar{A}\bar{B}D$ olacaktı. Sonuç python ile, don't care olmayan 13 satırın hepsinde doğrulanmıştır.

### 9.2 XOR durumları

Haritada 1'ler çapraz yerleşmişse (dama tahtası deseni) doğrudan gruplanamaz; ancak bu desen XOR olarak ifade edilir. İki değişkenli $A$, $B$ haritasında XOR tanımı gereği değerler aynıyken 0, farklıyken 1 vardır; 1'ler çaprazda durur ve fonksiyon $A\oplus B$ olarak yazılır. Üç değişkenli haritada aynı desen $A\oplus B\oplus C$'ye, dört değişkenlide de benzer şekilde dört değişkenli XOR'a karşılık gelir.

**Soru:** Don't care durumları bize verilmediğinde fonksiyona bakarak bunları nasıl anlayabiliriz? **Cevap:** Sözel olarak tanımlanmamışsa ya da verilmemişse bilinemez. Ya açıkça verilir ya da sözel tanımdan çıkarılır. Örneğin 0, 1, 2, 3, 4, 5 sayıp tekrar 0'a dönen bir sayıcı 3 bitle tasarlanırsa, kullanılmayan durumlar don't care olur. Bu tasarım ihtiyacından çıkarılır. Derste çözülen örnekte de don't care durumları sözel tanımdan doğruluk tablosuna geçilirken belirlenmiş ve özet olarak verilmişti.

> **Ders sonrası not:** Hoca sayıcı örneğinde kullanılmayan durumları "6, 7 ve 8 numaralı durumlar" diye saydı. 3 bitle 0-7 arası sekiz durum vardır; 0-5 sayan sayıcıda kullanılmayan durumlar 6 ve 7'dir.

## 10. Multiplexer (MUX)

Bu noktadan sonra temel kavramlar bitip kombinasyonel lojik bloklara geçildi. Lojik derslerinde bunların tek bitlik versiyonları görülmüştü; bu derste n bitlik versiyonları da tanımlanacaktır.

### 10.1 Tanım

Multiplexer, birden fazla girdi arasından hangisinin çıkışa iletileceğini belirleyen bir yapıdır. Slayta göre (ekrandan, 02:20:00):

- n ikili giriş (her biri 1 bit),
- $\log_2 n$ ikili seçim girişi,
- 1 ikili çıkış,
- işlevi: n girişten biri çıkışa aktarılır,
- adı: n'e 1 (n-to-1) multiplexer.

Ters yönden bakılırsa n seçim ucu varsa $2^n$ giriş ucu olur. Seçim uçlarına yazılan ikili değerin ondalık karşılığı olan numaralı giriş çıkışa aktarılır. İsimlendirme 2'ye 1, 4'e 1, 8'e 1 MUX biçimindedir.

### 10.2 2'ye 1 ve 4'e 1 MUX'un iç yapısı

2'ye 1 MUX'ta iki giriş vardır ve $\log_2 2 = 1$ seçim ucu gerekir. $s = 0$ ise $w_0$, $s = 1$ ise $w_1$ çıkışa aktarılır. İç yapı, minterm genel formülü $f = \sum_i m_i\cdot f(i)$ kullanılarak hızla bulunur: tek değişken olduğundan $m_0 = \bar{s}$ ve $f(0) = w_0$; $m_1 = s$ ve $f(1) = w_1$:

$$f = \bar{s}\,w_0 + s\,w_1$$

İki terim AND kapılarıyla oluşturulur ve bir OR kapısıyla toplanır.

4'e 1 MUX'ta dört giriş ve iki seçim ucu ($s_1$, $s_0$) vardır. Girişler anlam sırasıyla 0-3 numaralandırılır; $s_1s_0 = 00$ ise $w_0$, $01$ ise $w_1$, $10$ ise $w_2$, $11$ ise $w_3$ çıkışa aktarılır. Aynı formülle (ekrandan, 02:25:00):

$$f = \bar{s}_1\bar{s}_0w_0 + \bar{s}_1s_0w_1 + s_1\bar{s}_0w_2 + s_1s_0w_3$$

Slayttaki devrede (kaynak: Brown ve Vranesic) $s_0$ ve $s_1$ tersleyicilerden geçer, dört adet üç girişli AND kapısı bu dört terimi üretir ve dört girişli bir OR kapısı bunları toplar. Genel minterm formülü fonksiyon tanımlamada büyük pratiklik sağlar.

### 10.3 Soyutlama ve küçük MUX'larla büyük MUX

CPU tasarımına giden yolda çeşitli seviyelerde soyutlama (abstraction) kullanılacaktır. Bir blok kara kutu olarak ele alınıp "fonksiyonu budur" denecek ve oradan devam edilecektir. Örneğin her biri m bitlik 16 girişi, m bitlik bir çıkışı ve 4 seçim ucu olan bir MUX bloğu kullanılacaktır. Ama bunun alt seviyelerde m bitlik MUX'un birer bitlik MUX'lardan, 16'ya 1 MUX'un 2'ye 1 MUX'lardan, 2'ye 1 MUX'un AND, OR ve NOT kapılarından, kapıların transistörlerden ve transistörlerin de elektromanyetik hesaplamalarla tasarlanabileceği bilinmektedir. Bu katmanlar bir kez tasarlandıktan sonra tekrar sıfırdan tasarlanmaz.

**2'ye 1 MUX'larla 4'e 1 MUX** (ekrandan, 02:35:00): 2'ye 1 MUX'un iki girişi olduğundan dört giriş için giriş katında iki MUX gerekir. Bu iki MUX'un çıkışları arasında seçim yapmak için çıkış katında bir 2'ye 1 MUX daha kullanılır. Giriş katındaki MUX'ların ortak seçim ucu, seçilen MUX içinde bir adım (bir giriş) oynatır; birler basamağı gibidir, yani $s_0$'dır. Çıkış katındaki seçim ucu üst ya da alt MUX'u seçer, yani girişi iki birim öteler; ikiler basamağı gibidir, yani $s_1$'dir.

Hoca entegre çizimlerinde bir kural da belirtti: entegrenin içine yazılan etiketler entegrenin kendi uçlarını ve fonksiyonunu gösterir; uca dışarıdan bağlanan $X$, $Y$ gibi adlar ise dış dünyadan o uca bağlanan değeri gösterir.

**4'e 1 MUX'larla 16'ya 1 MUX** (ekrandan, 02:35:00): 16 giriş için giriş katında dört adet 4'e 1 MUX kullanılır. Bunların iki seçim ucu ortaklanır ve seçilen MUX içindeki adımı belirler; bunlar düşük anlamlı seçim uçlarıdır ($s_1$, $s_0$). Dört MUX arasından seçim için çıkış katında bir 4'e 1 MUX daha kullanılır; bu MUX'lar arası seçim yaptığı için seçim uçları yüksek anlamlıdır ($s_3$, $s_2$). Toplam: $w_0$-$w_{15}$ girişleri, $s_3$-$s_0$ seçim uçları ve bir $f$ çıkışı.

### 10.4 MUX ile lojik fonksiyon gerçekleme

Örnek olarak yine 2 bitlik karşılaştırma fonksiyonu alındı: $B = (b_1b_0)_2 > A = (a_1a_0)_2$ ise 1, aksi halde 0. Tahtadaki soru: "Fonksiyonu gerekli büyüklükte MUX ile gerçekleyin." (ekrandan, 02:40:00). Doğruluk tablosu Bölüm 7.1'deki ile aynıdır; çıkış sütunu satır sırasıyla $0,1,1,1,\ 0,0,1,1,\ 0,0,0,1,\ 0,0,0,0$'dır (ekrandan, 02:40:00).

**16'ya 1 MUX ile:** Bir öğrenci $a_1, a_0, b_1, b_0$ değerlerinin seçim ucu olarak kullanılmasını, 16 girişe de karşılık gelen değerlerin verilmesini önerdi. Tabloyu birebir aktarmak pratik olduğundan en yüksek anlamlı seçim ucuna $a_1$, sonra $a_0$, $b_1$, $b_0$ bağlanır ($s_3 = a_1, \dots, s_0 = b_0$). $b_0$'dan başlanarak bağlansaydı tabloyu takip etmek zorlaşırdı. Girişlere doğruluk tablosunun çıkış sütunu aynen verilir: $I_0 = 0$, $I_1 = 1$, $I_2 = 1$, ..., $I_{15} = 0$ (ekrandan, 02:45:00).

**8'e 1 MUX ile:** Bir öğrenci seçim uçlarına $a_1, a_0, b_1$ bağlanmasını, $b_0$'ın ise girişlere verilmesini önerdi. Artık her giriş tek bir satıra değil, $b_0$'ın 0 ve 1 olduğu iki satırlık bir gruba karşılık gelir. Her girişe $b_0$'ın bir fonksiyonu bağlanmalıdır.

**Soru:** Tek değişkenli kaç farklı lojik fonksiyon yazılabilir? **Cevap:** Bir öğrenci 4 dedi. Bunlar $f(x) = x$, $f(x) = x'$, $f(x) = 0$ ve $f(x) = 1$'dir (ekrandan, 02:45:00). Bu, $2^{2^1} = 4$ formülüyle de uyumludur.

Dolayısıyla 8'e 1 MUX'un girişlerine $b_0$, $b_0'$, 0 ya da 1 bağlanır. İkili gruplara bakılır:

- $a_1a_0b_1 = 000$: $f$ değerleri 0, 1, yani $f = b_0$ → $I_0 = b_0$.
- $001$: 1, 1 → $I_1 = 1$.
- $010$: 0, 0 → $I_2 = 0$.
- $011$: 1, 1 → $I_3 = 1$.
- $100$: 0, 0 → $I_4 = 0$.
- $101$: 0, 1 → $I_5 = b_0$.
- $110$: 0, 0 → $I_6 = 0$.
- $111$: 0, 0 → $I_7 = 0$.

$b_0'$ gereken bir grup yoktur. Sonuç $I_0..I_7 = b_0, 1, 0, 1, 0, b_0, 0, 0$; python ile doğrulanmıştır.

**4'e 1 MUX ile:** Seçim uçlarına $a_1$ ve $a_0$ bağlanır; girişlere bağlanacak değerler $b_1$ ve $b_0$ cinsinden fonksiyonlar olur. Hoca bu girişleri açıkça yazmadı (bkz. Örnek Sorular).

## 11. Decoder

### 11.1 Tanım ve çalışma mantığı

Decoder, n girişi ve $2^n$ çıkışı olan bir devredir; ayrıca çıkışın aktif değer üretip üretmeyeceğini kontrol eden bir enable ucu vardır (ekrandan, 02:50:00). Girişler bir adres değeri gibi davranır: girişlere verilen ikili değerin ondalık karşılığı hangi sayıysa o numaralı çıkış aktif olur. n girişli decoder "n'e $2^n$" (n-to-$2^n$) decoder olarak adlandırılır.

Aktif 1 ve aktif 0 çıkışlı decoder'lar vardır. Aktif 1 decoder'da seçilen çıkış 1, diğerleri 0 olur; aktif 0 decoder'da seçilen çıkış 0, diğerleri 1 olur. Enable ucu etkin değilken hiçbir çıkış aktif olmaz. Fiziksel entegrelerde birden fazla enable ucu da olabilir; derste tek enable ucu kullanılacaktır.

Decoder'larda giriş uçları genellikle harf sırasıyla adlandırılır: en düşük anlamlı giriş A'dır, alfabede ilerledikçe anlamlılık artar. Tahtada iki adet 3'e 8 decoder çizildi (ekrandan, 02:50:00), ikisinde de enable aktif 0:

- **Aktif 0 çıkışlı 3'e 8 decoder:** $E = 1$ ise (aktif 0 enable etkin değil) $Y_0, \dots, Y_7$ hepsi 1 olur. $E = 0$ ise $CBA$ numaralı çıkış ($Y_{CBA}$) 0, diğerleri 1 olur.
- **Aktif 1 çıkışlı 3'e 8 decoder:** $E = 1$ ise $Y_0, \dots, Y_7$ hepsi 0 olur. $E = 0$ ise $Y_{CBA}$ 1, diğerleri 0 olur.

Aktif 0 çıkışlar, aktif 0 enable uçlarına sahip entegrelerle birlikte kullanıldığında anlamlıdır. Decoder girişleri adres gibi davrandığından bu yapı çoğunlukla adres çözümleme devrelerinde kullanılır; slaytta da decoder'ların sıkça RAM/ROM adreslemede kullanıldığı yazılıdır. Mikroişlemciler derslerinde de sıklıkla karşılaşılacaktır. Ayrıca lojik fonksiyonların gerçeklenmesinde de kullanılır.

### 11.2 2'ye 4 decoder ve mintermler

Slayttaki 2'ye 4 decoder'da (kaynak: Brown ve Vranesic) enable aktif 1'dir (ekrandan, 02:55:00):

| En | $w_1$ | $w_0$ | $y_3$ | $y_2$ | $y_1$ | $y_0$ |
|---|---|---|---|---|---|---|
| 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| 1 | 0 | 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 0 | 0 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 | 0 |
| 0 | – | – | 0 | 0 | 0 | 0 |

Doğruluk tablosuna dökülen decoder, dört lojik fonksiyonu eş zamanlı gerçekleyen bir yapıdır. Enable dışarıda bırakılırsa her çıkış sütununda yalnız bir doğru minterm vardır (ekrandan, 02:55:00):

$$y_3 = w_1w_0, \quad y_2 = w_1w_0', \quad y_1 = w_1'w_0, \quad y_0 = w_1'w_0'$$

Enable da eklenince her terim ayrıca $En$ ile çarpılır; slayttaki devrede iki tersleyici ve dört adet üç girişli AND kapısı bu terimleri üretir.

Hoca burada öğrencilerden bir gözlem bekledi: decoder'ın çıkışları, girişlere ait ilgili numaralı mintermlerdir. Yani $w_1$ ve $w_0$'a ait bütün mintermler decoder çıkışında hazır elde edilir. Bu yüzden bir lojik fonksiyon decoder ile gerçeklenmek istendiğinde, doğru mintermlere karşılık gelen çıkışlar bir OR kapısıyla birleştirilir. Decoder ile devre tasarımı bu şekilde yapılır.

Daha küçük bloklarla büyük blokların kurulması ve decoder ile lojik devre tasarımı bir sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:26:11): Yalnız AND ve NOT kapılarını kullanarak $A + B$ işlemini nasıl elde edersiniz?

> **Çözüm (derste verildi):** De Morgan kuralıyla $A + B = (\bar{A}\cdot\bar{B})'$. $A$ ve $B$ terslenir, AND'e verilir, çıkış bir kez daha terslenir.

**Soru 2** (ekrandan, 00:30:00 ve 00:35:00): İki girişli NAND kapılarıyla NOT, AND ve OR kapılarını gerçekleyin.

> **Çözüm (derste verildi):** NOT: girişler birleştirilir ($(x\cdot x)' = x'$) ya da bir girişe 1 verilir ($(x\cdot 1)' = x'$). AND: $((xy)')' = xy$, yani NAND çıkışına NAND'den yapılmış bir NOT eklenir. OR: $(x'\cdot y')' = x + y$, yani $x$ ve $y$ önce NAND ile terslenir, sonra bir NAND'e verilir.

**Soru 3** (derste sözlü, 00:34:52): Aynı işlemleri (NOT, AND, OR) yalnız NOR kapılarıyla gerçekleyin. Hoca bunu zorunlu olmayan bir alıştırma olarak verdi.

> **Çözüm (derste verilmedi):** NOT: girişler birleştirilir, $(x + x)' = x'$. OR: NOR çıkışı NOR'dan yapılmış bir NOT'tan geçirilir, $((x+y)')' = x + y$. AND: girişlerin tersleri bir NOR'a verilir, $(x' + y')' = x\cdot y$ (De Morgan). Üç eşitlik doğruluk tablosuyla kontrol edilebilir.

**Soru 4** (derste sözlü, 00:41:19): Üç değişkenle kaç farklı lojik fonksiyon yazılabilir?

> **Çözüm (derste verildi):** Doğruluk tablosu $2^3 = 8$ satırlıdır ve her satırın çıkışı 0 ya da 1 olabilir. Dolayısıyla $2^{2^3} = 2^8 = 256$ farklı fonksiyon vardır.

**Soru 5** (ekrandan, 00:45:00 ve 01:10:00): Üç girişli çoğunluk fonksiyonunun doğruluk tablosunu oluşturun; çarpımlar toplamı, toplamlar çarpımı ve indirgenmiş biçimlerini yazın; yalnız NAND kapılarıyla gerçekleyin.

> **Çözüm (derste verildi):** Çıkış sütunu 0, 0, 0, 1, 0, 1, 1, 1. Çarpımlar toplamı $\bar{a}bc + a\bar{b}c + ab\bar{c} + abc$; toplamlar çarpımı $(a+b+c)(a+b+c')(a+b'+c)(a'+b+c)$; indirgenmiş hal $ab + bc + ac$; yalnız NAND ile $((ab)'(bc)'(ac)')'$, yani üç adet iki girişli NAND ve bir üç girişli NAND.

**Soru 6** (ekrandan, 01:35:00): $f(a_1,a_0,b_1,b_0)$, $(b_1b_0)_2 > (a_1a_0)_2$ ise 1, aksi halde 0 olsun. Doğruluk tablosunu oluşturup Karnaugh haritasıyla indirgeyin. Koşul $\ge$ olursa haritada ne değişir?

> **Çözüm (derste verildi):** 1 olan satırlar 1, 2, 3, 6, 7, 11. $F = \bar{a}_1b_1 + \bar{a}_1\bar{a}_0b_0 + \bar{a}_0b_1b_0$. Koşul $\ge$ olunca köşegendeki dört hücre (0, 5, 10, 15 numaralı satırlar) 1 olur ve daha büyük gruplar alınır (bkz. Bölüm 7.2).

**Soru 7** (ekrandan, 02:15:00): $F(A,B,C,D) = \sum m(1,3,7,11,15)$, $d(A,B,C,D) = \sum m(0,2,5)$ fonksiyonunu don't care durumlarını kullanarak Karnaugh haritasıyla indirgeyin.

> **Çözüm (derste verildi, son ifade derste yazılmadı):** $CD = 11$ sütunundaki dört 1 bir dörtlüdür ($CD$). $m_5$ 1 kabul edilince $m_1, m_3, m_5, m_7$ dörtlüsü ($\bar{A}D$) alınır. $F = CD + \bar{A}D$; $m_0$ ve $m_2$ 0 kabul edilmiş olur. Sonuç python ile doğrulanmıştır.

**Soru 8** (ekrandan, 02:40:00): Soru 6'daki karşılaştırma fonksiyonunu gerekli büyüklükte MUX ile gerçekleyin (16'ya 1, 8'e 1 ve 4'e 1 MUX).

> **Çözüm (16'ya 1 ve 8'e 1 derste verildi):** 16'ya 1 MUX: seçim uçlarına $a_1, a_0, b_1, b_0$; girişlere doğruluk tablosunun çıkış sütunu. 8'e 1 MUX: seçim uçlarına $a_1, a_0, b_1$; girişlere $I_0..I_7 = b_0, 1, 0, 1, 0, b_0, 0, 0$.

> **Çözüm (4'e 1 kısmı derste verilmedi):** Seçim uçlarına $a_1, a_0$ bağlanır. Her giriş, $a_1a_0$ sabitken $b_1b_0$'ın dört satırlık bloğudur. $a_1a_0 = 00$ bloğu $0,1,1,1$ → $I_0 = b_1 + b_0$; $01$ bloğu $0,0,1,1$ → $I_1 = b_1$; $10$ bloğu $0,0,0,1$ → $I_2 = b_1b_0$; $11$ bloğu $0,0,0,0$ → $I_3 = 0$. Bloklar python ile doğrulanmıştır.

**Soru 9** (derste sözlü, 02:44:10): Tek değişkenli ($x$ bir boolean değer) bir $f(x)$ fonksiyonu kaç farklı şekilde yazılabilir?

> **Çözüm (derste verildi):** Dört şekilde: $x$, $x'$, $0$, $1$.

## Dersin Toparlaması

Bu ders, bilgisayar organizasyonuna gerekli olan lojik tasarım temelini tekrar etti. Temel kapılar ve tam kapı kümeleri üzerinden yalnız NAND ya da yalnız NOR ile her fonksiyonun kurulabileceği gösterildi. Çoğunluk fonksiyonu örneğiyle bir fonksiyonun doğruluk tablosu, minterm ve maxterm yazımları, indirgenmiş hali, AND-OR ve yalnız NAND şemaları adım adım çıkarıldı. Boole cebri eşitlikleri, Karnaugh haritası (2 bitlik karşılaştırma devresi, don't care ve XOR desenleri), sayı sistemleri arası dönüşümler ve üç işaretli sayı gösterimi hatırlatıldı; tasarımda 2'ye tümleyenin kullanılacağı belirtildi.

Son bölümde kombinasyonel temel bloklara geçildi. Multiplexer'ın iç yapısı genel minterm formülünden çıkarıldı, küçük MUX'larla büyük MUX kurma ve MUX ile fonksiyon gerçekleme gösterildi. Decoder çıkışlarının giriş mintermleri olduğu, bu yüzden decoder ve OR kapısıyla her fonksiyonun gerçeklenebileceği görüldü. Hoca, bundan sonra bu blokları kara kutu olarak kullanıp soyutlama seviyelerini yükselterek CPU tasarımına ilerleyeceklerini söyledi. Küçük bloklarla büyük blok kurma ve decoder ile devre tasarımı bir sonraki derste ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
