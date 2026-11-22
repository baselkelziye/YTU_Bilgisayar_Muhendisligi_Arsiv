# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin amacı ve kapsamı
  - Ders, bir işlemcinin iç yapısını adım adım tasarlamayı ve çalışan bir örneği analiz etmeyi hedefler. Lojik Devreler dersindeki tek bitlik kombinasyonel ve ardışıl devreler burada n bitlik (yol/bus genişliğinde) versiyonlarıyla ele alınır.
  - Konu akışı: kombinasyonel ve ardışıl devreler, saklayıcılar (register) ve sayıcılar, programlanabilir yapılar (PLD, PLA, PAL), bellek birimleri (RAM, ROM), saklayıcılar arası veri transferi, ortak veri yolu, komut yapısı ve adresleme yöntemleri, merkezi işlem birimi (ALU, aritmetik ve lojik birim, shifter) ve pipeline, giriş/çıkış birimleri, önbellek ve eşleme (mapping) teknikleri, sanal bellek ve sayfa tabloları (ekrandan, 00:10:00).
  - Komut kümesi mimarisi (ISA) ile donanım karşılığı arasındaki bağ kurulacaktır: desteklenmesi istenen her komutun donanımda bir karşılığı olmalıdır.
  - Referans kitap: M. M. Mano, C. R. Kime, *Logic and Computer Design Fundamentals*, 5. baskı (ekrandan, 00:10:00). Tasarım örnekleri mümkün olduğunca Verilog ile de gösterilecektir.
- Temel lojik kapılar
  - AND: herhangi bir girişi 0 ise çıkış 0. OR: herhangi bir girişi 1 ise çıkış 1. NOT: girişin tersi. XOR: girişler aynıysa 0, farklıysa 1. NAND, NOR, XOR türev kapılardır.
  - Gösterim: AND için nokta ($A\cdot B$), OR için artı ($A+B$), NOT için üs işareti ya da üst çizgi ($A'$, $\bar{A}$). $A \oplus B = A\bar{B} + \bar{A}B$.
  - NAND ve NOR tabanlı tasarımlar yaygındır; tek tip kapıyla her fonksiyon gerçeklenebildiği için üreticiler tek lojik tasarım üzerinden üretim yapmayı tercih eder. CMOS teknolojisi yalnız durum değişiminde enerji harcadığı için (kaçak akımlar ihmal edilirse) enerji verimlidir.
- Tam (complete) kapı kümeleri
  - Bir kapı kümesi, yalnız o kümedeki kapı türleriyle her lojik fonksiyon gerçeklenebiliyorsa tamdır. Minimal tam küme, gereksiz elemanı olmayan tam kümedir (ekrandan, 00:25:00).
  - {AND, OR, NOT} tamdır ama minimal değildir. {AND, NOT}, {OR, NOT}, {NAND}, {NOR} minimal tam kümelerdir.
  - {AND, NOT} ile OR: $A+B = (\bar{A}\cdot\bar{B})'$ (De Morgan). {OR, NOT} ile AND: $A\cdot B = (\bar{A}+\bar{B})'$.
  - Yalnız NAND ile: NOT için iki giriş birleştirilir ya da bir girişe 1 verilir; AND için NAND çıkışına NAND'den yapılmış NOT eklenir; OR için girişlerin tersleri NAND'e verilir: $(x'\cdot y')' = x+y$ (ekrandan, 00:35:00).
- Lojik fonksiyonların ifade biçimleri
  - Doğruluk tablosu, lojik ifade, grafik (şematik) biçim ve HDL kodu (ekrandan, 00:40:00). Doğruluk tablosu doğrudan bir look-up table (ROM) olarak gerçeklenebilir: ROM adresleri tablo satırları, ROM çıkışları fonksiyon çıkışlarıdır.
  - n değişkenle yazılabilecek farklı fonksiyon sayısı $2^{2^n}$'dir; 3 değişken için $2^8 = 256$.
- Çoğunluk (majority) fonksiyonu örneği
  - Üç girişten en az ikisi 1 ise çıkış 1. Doğruluk tablosu çıkış sütunu: 0, 0, 0, 1, 0, 1, 1, 1 (ekrandan, 00:45:00).
  - Çarpımlar toplamı (doğru mintermler): $M = \bar{a}bc + a\bar{b}c + ab\bar{c} + abc$.
  - Toplamlar çarpımı (yanlış maxtermler): $M = (a+b+c)(a+b+c')(a+b'+c)(a'+b+c)$ (ekrandan, 01:10:00).
  - Lojik çıkarımla indirgenmiş hal: $M = ab + bc + ac$; üç adet iki girişli AND ve bir üç girişli OR ile çizilir (ekrandan, 01:15:00). Yalnız NAND ile: üç adet iki girişli NAND ve bunları birleştiren bir üç girişli NAND (ekrandan, 01:25:00).
- Boole cebri eşitlikleri
  - Etkisiz eleman ($x\cdot1=x$, $x+0=x$), tümleyen ($x\cdot x'=0$, $x+x'=1$), yutan eleman ($x\cdot0=0$, $x+1=1$), değişme, dağılma (AND'in OR üzerine ve OR'un AND üzerine), idempotent ($x\cdot x = x$, $x+x=x$), involution ($(x')'=x$), yutma ($x(x+y)=x$, $x+xy=x$), birleşme ve De Morgan ($(xy)'=x'+y'$, $(x+y)'=x'y'$) (ekrandan, 01:20:00).
- Karnaugh haritası
  - Komşu hücreler arasında yalnız bir değişken değişir (00, 01, 11, 10 sırası). Gruplar 2'nin kuvveti büyüklükte ve olabildiğince büyük alınır; harita kenarları birbirine komşudur (küre gibi düşünülür).
  - Örnek: 2 bitlik iki sayı için $B > A$ karşılaştırma fonksiyonu: $F = \bar{a}_1 b_1 + \bar{a}_1\bar{a}_0 b_0 + \bar{a}_0 b_1 b_0$ (ekrandan, 01:40:00).
  - Don't care (X) durumları, daha büyük grup sağlıyorsa 1 kabul edilir; gruba alınmayan X'ler 0 olarak sabitlenmiş olur.
  - Çapraz (dama tahtası) desenli haritalar XOR ile ifade edilir: $A\oplus B$, $A\oplus B\oplus C$.
- Sayı sistemleri ve işaretli sayılar
  - Ondalıktan ikiliye sürekli ikiye bölme ile geçilir. Sekizliye geçişte sağdan üçlü, onaltılıya geçişte sağdan dörtlü bit grupları alınır: $12_{10} = 1100_2 = 14_8$, $18_{10} = 10010_2 = 12_{16}$ (ekrandan, 01:50:00).
  - İşaretli gösterimler: işaret-büyüklük (sign magnitude), 1'e tümleyen, 2'ye tümleyen. İlk ikisinde sıfırın iki gösterimi vardır (+0 ve −0). Tasarımda 2'ye tümleyen kullanılır.
- Multiplexer (MUX)
  - n giriş, $\log_2 n$ seçim ucu, 1 çıkış; seçim uçlarındaki ikili değerin karşılığı olan giriş çıkışa aktarılır (ekrandan, 02:20:00).
  - İç yapı, minterm genel formülünden çıkar: 2'ye 1 MUX için $f = \bar{s}w_0 + sw_1$; 4'e 1 MUX için $f = \bar{s}_1\bar{s}_0w_0 + \bar{s}_1s_0w_1 + s_1\bar{s}_0w_2 + s_1s_0w_3$ (ekrandan, 02:25:00).
  - Küçük MUX'larla büyük MUX: üç adet 2'ye 1 MUX ile 4'e 1 MUX, beş adet 4'e 1 MUX ile 16'ya 1 MUX kurulur; giriş katı düşük anlamlı, çıkış katı yüksek anlamlı seçim uçlarını kullanır (ekrandan, 02:35:00).
  - MUX ile fonksiyon gerçekleme: karşılaştırma fonksiyonu 16'ya 1, 8'e 1 ya da 4'e 1 MUX ile gerçeklenebilir (ekrandan, 02:45:00).
- Decoder
  - n giriş, $2^n$ çıkış ve enable ucu. Girişler adres gibi davranır; girişteki ikili değerin numaralı çıkışı aktif olur. Aktif 1 ve aktif 0 çıkışlı türleri vardır (ekrandan, 02:50:00).
  - 2'ye 4 decoder çıkışları girişlerin mintermleridir: $y_3 = w_1w_0$, $y_2 = w_1w_0'$, $y_1 = w_1'w_0$, $y_0 = w_1'w_0'$ (her biri ayrıca $En$ ile çarpılır) (ekrandan, 02:55:00). Bu yüzden decoder ve bir OR kapısıyla her fonksiyon gerçeklenebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Lojik kapı şemaları
  - Kapı sembolleri doğru çizilmelidir; çizimden emin olunmuyorsa kapının içine gerçekleştirdiği fonksiyon (AND, OR vb.) yazılmalıdır. Hoca, üst sınıf derslerinde bile kapı çizimlerinde karışıklık yaşandığını belirtti.
- Minterm ve maxterm ile yazmanın pratiği
  - Çarpımlar toplamı: yalnız çıkışı 1 olan satırların mintermleri toplanır (sıfırla çarpılan terimler düşer). Toplamlar çarpımı: yalnız çıkışı 0 olan satırların maxtermleri çarpılır (1 eklenen terimler 1 olur ve düşer).
  - Minterm yazarken satırdaki 0 olan değişkenin tersi alınır; maxterm yazarken satırdaki 1 olan değişkenin tersi alınır.
- Mintermlerle yazmak ile Karnaugh indirgemesi aynı şey değildir
  - Mintermlerle yazmak her 1 satırını tek tek fonksiyona eklemektir. Karnaugh haritası, ortak paranteze alınabilecek grupları görerek indirgenmiş ifadeyi yazmaktır.
- Soyutlama (abstraction)
  - CPU tasarımına giderken bloklar kara kutu olarak kullanılacaktır. Bir n bitlik 16'ya 1 MUX, 2'ye 1 MUX'lardan; 2'ye 1 MUX kapılardan; kapılar transistörlerden kurulabilir. Bu katmanlar bir kez bilindikten sonra tekrar tasarlanmaz.
- 2'ye tümleyen gösterimi
  - Sıfırın tek gösterimi olduğu için tasarımda 2'ye tümleyen kullanılacaktır. Pratik yol: sağdan ilk 1 dahil bitler aynen bırakılır, sonraki bitlerin tersi alınır.

## Kısa Tekrar Notları

- Minimal tam kümeler: {AND, NOT}, {OR, NOT}, {NAND}, {NOR}. {AND, OR, NOT} tamdır ama minimal değildir.
- NAND ile NOT: iki girişi birleştir ya da bir girişe 1 ver. NAND ile OR: $(x'y')' = x+y$.
- n değişkenli farklı fonksiyon sayısı: $2^{2^n}$. Tek değişkenli fonksiyonlar: $0$, $1$, $x$, $x'$.
- Çoğunluk fonksiyonu: $M = ab + bc + ac$.
- Yutma: $x + xy = x$, $x(x+y) = x$. De Morgan: $(xy)' = x'+y'$, $(x+y)' = x'y'$.
- Karnaugh grupları 1, 2, 4, 8, 16 hücrelik olur; kenarlar komşudur; X'ler işe yarıyorsa 1 alınır.
- 4 bitte işaret-büyüklük ve 1'e tümleyen aralığı −7..+7 (iki sıfır), 2'ye tümleyen aralığı −8..+7.
- 2'ye 1 MUX: $f = \bar{s}w_0 + sw_1$. n giriş için $\log_2 n$ seçim ucu.
- Decoder çıkışları giriş mintermleridir; decoder + OR ile her fonksiyon kurulur.
- Aktif 0 enable ucuna 1 verilirse entegre seçilmemiş olur.

## Detaylı Açıklamalar

- **Tam küme ve NAND ile kapı gerçekleme.** Bir kapı kümesinden bir kapı çıkarıldığında bazı fonksiyonlar artık gerçeklenemiyorsa küme minimaldir. {AND, OR, NOT} kümesinden OR çıkarılsa bile OR, De Morgan ile $A+B=(\bar{A}\bar{B})'$ olarak elde edilir; bu yüzden küme minimal değildir. Yalnız NAND ile çalışırken önce NOT kurulur: NAND doğruluk tablosunda iki girişin eşit olduğu satırlarda (00 → 1, 11 → 0) çıkış girişin tersidir, bu yüzden girişler birleştirilince $x'$ elde edilir. Bir girişe 1 verildiğinde de diğer girişin tersi çıkar; NAND simetrik olduğu için hangi uca 1 verildiği fark etmez. AND, NAND çıkışının bir kez daha terslenmesiyle; OR ise $x'$ ve $y'$ değerlerinin bir NAND'e verilmesiyle elde edilir. Aynı işlemi yalnız NOR ile yapmak hocanın zorunlu olmayan alıştırma olarak bıraktığı bir sorudur.
- **Çoğunluk fonksiyonu.** Fonksiyonun genel minterm yazımı $M = \sum_i m_i \cdot M(i)$ biçimindedir: her satırın mintermi, o satırdaki fonksiyon çıkışıyla çarpılır. Çıkışı 0 olan satırlar düşer, 1 olanlar kalır: $M = \bar{a}bc + a\bar{b}c + ab\bar{c} + abc$. Aynı fonksiyon maxtermlerle $M = \prod_i (M_i + M(i))$ olarak yazılır; çıkışı 1 olan satırlarda parantez 1 olur ve düşer, geriye çıkışı 0 olan satırların maxtermleri kalır: $(a+b+c)(a+b+c')(a+b'+c)(a'+b+c)$ (ekrandan, 01:10:00). Lojik çıkarımla "en az iki giriş 1" koşulu $ab$, $bc$ ya da $ac$ çiftlerinden birinin 1 olması demektir: $M = ab + bc + ac$. Dört girişli çoğunluk fonksiyonunda en az üç giriş 1 olmalıdır; bu durumda dört adet üçlü çarpım terimi kontrol edilir.
- **Çoğunluk fonksiyonunun yalnız NAND ile kurulması.** AND-OR devresinde her AND çıkışına ve OR girişine art arda iki tersleyici eklenir; $(x')' = x$ olduğu için devre değişmez. AND ile bir tersleyici NAND olur. OR girişlerindeki tersleyicilerle oluşan "girişleri terslenmiş OR" ise De Morgan ile $(x'+y'+z')=(xyz)'$, yani üç girişli NAND'dir (ekrandan, 01:25:00). Formal yoldan: $M = ((ab)'(bc)'(ac)')'$ ifadesinde her parantez bir iki girişli NAND, dıştaki tümleyen de üç girişli NAND'dir.
- **Karnaugh haritası ile karşılaştırma devresi.** $f(a_1,a_0,b_1,b_0)$, $B=(b_1b_0)_2 > A=(a_1a_0)_2$ ise 1, aksi halde 0 olan bir fonksiyondur. Doğruluk tablosunda 1 olan satırlar 1, 2, 3, 6, 7 ve 11 numaralı satırlardır (ekrandan, 01:35:00). Haritada satırlar $a_1a_0$, sütunlar $b_1b_0$ ile 00, 01, 11, 10 sırasında yazılır. Gruplar: $a_1a_0\in\{00,01\}$, $b_1b_0\in\{11,10\}$ dörtlüsü $\bar{a}_1b_1$; $a_1a_0=00$, $b_1b_0\in\{01,11\}$ ikilisi $\bar{a}_1\bar{a}_0b_0$; $b_1b_0=11$, $a_1a_0\in\{00,10\}$ ikilisi (üst ve alt kenar komşu) $\bar{a}_0b_1b_0$. Sonuç $F = \bar{a}_1 b_1 + \bar{a}_1\bar{a}_0 b_0 + \bar{a}_0 b_1 b_0$ (ekrandan, 01:40:00). Koşul $B \ge A$ yapılınca köşegendeki dört hücre de 1 olur ve daha büyük gruplar alınabilir (ekrandan, 01:45:00). Bu ifadeler python ile 16 satırın hepsinde doğrulanmıştır.
- **Don't care örneği.** $F(A,B,C,D)=\sum m(1,3,7,11,15)$, $d=\sum m(0,2,5)$ (ekrandan, 02:15:00). $CD=11$ sütunundaki dört 1 ($m_3, m_7, m_{15}, m_{11}$) bir dörtlüdür: $CD$. $m_1$ tek başına $m_3$ ile ikili alınırsa üç değişkenli terim ($\bar{A}\bar{B}D$) çıkar; don't care $m_5$ 1 kabul edilirse $m_1, m_3, m_5, m_7$ dörtlüsü $\bar{A}D$ olur. Böylece $F = CD + \bar{A}D$ elde edilir; $m_0$ ve $m_2$ gruba alınmadığı için 0 sayılır. Bu sonuç python ile doğrulanmıştır.
- **İşaretli sayılar.** 4 bitte işaret-büyüklükte en yüksek bit işarettir, kalan üç bit büyüklüktür: $1001 = -1$, $0110 = +6$. 1'e tümleyende negatif sayının büyüklüğü bütün bitler terslenerek bulunur: $1010 \to 0101 = 5$, yani $-5$; $1111$ ise $-0$'dır. 2'ye tümleyende büyüklük 1'e tümleyene 1 eklenerek bulunur: $1100 \to 0011 + 1 = 0100$, yani $-4$ (ekrandan, 01:55:00). Hesaplar python ile kontrol edilmiştir.
- **MUX ile fonksiyon gerçekleme.** Karşılaştırma fonksiyonu 16'ya 1 MUX ile gerçeklenirken seçim uçlarına anlam sırasıyla $a_1, a_0, b_1, b_0$ bağlanır, girişlere doğruluk tablosunun çıkış sütunu aynen verilir. 8'e 1 MUX'ta seçim uçlarına $a_1, a_0, b_1$ bağlanır; her giriş iki satırlık bir gruba karşılık gelir ve girişe $b_0$'ın tek değişkenli fonksiyonlarından biri ($0$, $1$, $b_0$, $b_0'$) bağlanır: $I_0..I_7 = b_0, 1, 0, 1, 0, b_0, 0, 0$ (ekrandan, 02:45:00; python ile doğrulandı). 4'e 1 MUX'ta seçim uçlarına $a_1, a_0$ bağlanır ve girişler $b_1, b_0$ cinsinden fonksiyonlar olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
