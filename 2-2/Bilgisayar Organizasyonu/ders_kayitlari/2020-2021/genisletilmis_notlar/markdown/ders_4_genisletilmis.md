# Ders 4 Genişletilmiş Notu: Bellek Yapıları ve Programlanabilir Lojik Cihazlar (ROM, PLA, PAL, PLD)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri ve Akışı
- 2. Bellek Yapıları: ROM ve RAM
- 3. Programlanabilir Lojik Cihazlara Genel Bakış
- 4. ROM ile Lojik Fonksiyon Gerçekleme
- 5. Sigorta Yakma ve ROM Türleri
- 6. Örnek: Tam Toplayıcının ROM ile Gerçeklenmesi
- 7. Örnek: Programlanmış Bir ROM'un Okunması
- 8. PLA (Programmable Logic Array)
- 9. PLA ile Tasarım: Ortak Çarpım Terimleri
- 10. PAL (Programmable Array Logic)
- 11. Bir PLD Cihazı: WinCUPL ve Proteus Örnekleri
- 12. FPGA ve Verilog'a Kısa Bakış
- 13. Örnek Sorular

## 1. Dersin Yeri ve Akışı

Kayıt yaklaşık 00:04:25'te başlar. Önceki derste senkron ardışıl devre blokları incelenmişti. Bu dersin ana konusu programlanabilir lojik cihazlardır: ROM, PAL, PLA ve PLD. Hoca, ROM ile programlamayı anlatmadan önce RAM ve ROM'un iç yapısına kısaca değineceğini, vakit kalırsa FPGA'ya ve şimdiye kadar görülen blokların Verilog kodlarına bakacağını söyledi. Verilog kısmı bilgi amaçlıdır; derste Icarus Verilog kullanılacağı, PLD cihazları için de WinCUPL adlı bir programın gösterileceği belirtildi.

## 2. Bellek Yapıları: ROM ve RAM

Hoca bu konuya ileride iki kez daha dönüleceğini, şimdi yalnız programlanabilir cihazlara zemin hazırlamak için kısaca bakılacağını söyledi.

### 2.1 ROM (Read Only Memory)

ROM, çalışma sırasında yalnız okunabilen bir bellektir. İçinde saklanan değerler enerji kesildiğinde kaybolmaz: enerji yeniden verildiğinde aynı adreslerden aynı değerler okunur. Slayttaki maddeler (ekrandan, 00:10:00): RAM'e benzer ama yalnız okunur, adreslenebilir bir bellektir, senkron (saatli) ya da asenkron (saatsiz) olabilir.

Blok yapısında adres uçları ($m$ tane), veri çıkış uçları ($n$ tane) ve okuma (read) kontrol ucu vardır. Hoca slaytta eksik olan bir ucu da ekledi: cihazı etkinleştiren yonga seçme (chip select) ucu.

$m$ adres ucuyla $2^m$ hafıza gözü adreslenir. Her gözde $n$ bit saklanır. Bu yüzden ROM'un kapasitesi kabaca

$$2^m \times n \text{ bit}$$

olur.

İç yapıda adres uçları $m \times 2^m$ boyutlu bir dekodere bağlıdır. Dekoder, verilen adrese göre $2^m$ satırdan yalnız birini aktif yapar. Her sütun kendi içinde bağlıdır; sütunlar seçilen satırın bitlerini dışarı çıkarır. Her hafıza biti için bir sigorta vardır. Sigorta, ROM türüne göre elektriksel olarak durumu değiştirilerek ya da fiziksel olarak yakılarak programlanır. Okuma kontrolü aktifse, cihaz seçilmiş ve adres uygulanmışsa çıkıştaki üç durumlu tamponlar (tri-state buffer) açılır ve veri dışarı verilir. Okuma aktif değilse tamponlar yüksek empedans gösterir; bu, cihazın veri yolundan koparılması gibi bir etki yapar.

### 2.2 RAM (Random Access Memory)

RAM'de hafıza gözlerine rastgele erişilebilir, yani herhangi bir göze doğrudan gidilebilir. Hoca rastgele erişimin karşıtı olarak sıralı erişimi hatırlattı: eskiden kullanılan veri kasetleri ve bantlar, veriye sırayla erişilen yapılardı.

RAM'de mantık ROM'a benzer, ama veri hem okunur hem yazılır ve bellek geçicidir: enerji kesilince saklanan veri kaybolur. $m$ adres ucu, $2^m$ göz ve her gözde $n$ bit vardır. Yazma ve okuma kontrolüne göre seçilen göze dışarıdan veri yazılır ya da o gözdeki veri dışarı aktarılır.

Slayttaki şekilde (ekrandan, 00:15:00) adres uçları $a_0 \ldots a_{m-1}$ bir "m-to-$2^m$ decoder"a girer; dekoder $Sel_0 \ldots Sel_{2^m-1}$ seçim hatlarını üretir. Üstte Write kontrollü giriş tamponları ($d_{n-1} \ldots d_0$), altta Read kontrollü çıkış tamponları ($q_{n-1} \ldots q_0$) vardır. Şekilde veri girişi ve çıkışı iki ayrı yol olarak çizilmiş olsa da günümüzde pratikte tek bir veri yolu kullanılır: okuma yönü ayarlandığında yol dışarı veri verir, yazma yönü ayarlandığında dışarıdan veri alır; bunu üç durumlu kontrol sağlar.

> **Hocanın vurgusu:** RAM ve ROM yapılarında akılda kalması gereken asıl nokta, adres uçlarına karşılık seçimi bir dekoderin yapmasıdır.

## 3. Programlanabilir Lojik Cihazlara Genel Bakış

Programlanabilir lojik cihazlar ROM, PAL, PLA ve PLD yapılarıdır; en gelişmiş hâli FPGA'dır. "Programlanabilir" demek şudur: cihaz üretimden geldiğinde içinde rastgele ya da sıfır değerler vardır. Biz onu programlayınca belirli girişlere karşılık istediğimiz çıkışları üretecek bir "kod" gömmüş oluruz.

Lojik tasarımda önce doğruluk tablosu yapılır, sonra fonksiyon çarpımlar toplamı olarak yazılır: doğru mintermler toplanır. Bu cihazların hepsinde çarpım terimlerini üreten bir AND katı ve bunları toplayan bir OR katı vardır. Cihazları birbirinden ayıran, hangi katın programlanabildiğidir. Slayttaki tanımlar (ekrandan, 00:20:00):

- **ROM:** sabit bir AND kapıları dizisi ve programlanabilir bir OR kapıları dizisi.
- **PAL (Programmable Array Logic):** programlanabilir bir AND dizisi, sabit bir OR dizisini besler.
- **PLA (Programmable Logic Array):** programlanabilir bir AND dizisi, programlanabilir bir OR dizisini besler.
- **CPLD / FPGA:** "mimari" denecek kadar karmaşık cihazlar.

ROM'da AND katı sabittir, programlanamaz; bütün çarpım terimleri, yani $m_0$'dan $m_{2^m-1}$'e kadar bütün mintermler üretilir. OR katının programlanabilir olması, bu mintermlerden istediklerimizi birleştirip bir fonksiyon üretebilmek demektir. Her OR kapısının çıkışı bir fonksiyondur. Böylece $m$ adres ve $n$ veri ucu olan bir ROM ile $m$ girişli $n$ taneye kadar fonksiyon gerçeklenebilir. Hoca bunu ROM için önemli bir özellik olarak belirtti.

PAL'da AND katı programlanabilir: istenen çarpım terimleri üretilir. OR katı ise sabittir; kaç OR kapısı varsa o kadar fonksiyon üretilebilir ve bir OR kapısına bağlanabilecek terim sayısı bellidir. Burada üretilen çarpım terimlerinin minterm olması gerekmez. Karnaugh haritasında gruplanarak sadeleştirilmiş terimler gibi indirgenmiş terimler olabilir. Aynısı PLA için de geçerlidir; PLA'da hem üretilecek çarpım terimleri hem de bunların OR ile nasıl birleştirileceği programlanır.

Karmaşık PLD ve FPGA'lar ise inşa bloklarından oluşur. Bu bloklar programa göre bir hafıza elemanından bir AND kapısına, bir look-up table'a kadar farklı işlevler gösterebilir.

## 4. ROM ile Lojik Fonksiyon Gerçekleme

### 4.1 Dekoderin çıkışları mintermdir

Hoca ROM'un içindeki dekoderi tahtaya büyüterek çizdi (ekrandan, 00:25:00): $m$ adres ucu (0'dan $m-1$'e), $m \times 2^m$ dekoder, $Y_0 \ldots Y_{2^m-1}$ çıkışları. Sonra dekoderin nasıl çalıştığını sordu.

**Soru:** Dekoder nasıl çalışıyordu? **Cevap:** Bir öğrenci, girilen değere karşılık gelen çıkışın 1, diğerlerinin 0 olacağını söyledi. Hoca tamamladı: girişteki değerin ondalık karşılığı hangi numaraysa o çıkış aktif olur. Aktif 0 cihazlarda aktif uç 0, aktif 1 cihazlarda 1 değerini alır. Çizimdeki dekoder aktif 1 çıkışlıdır.

Hoca sonra $Y_i$'nin girişler cinsinden neye eşit olduğunu sordu. $Y_i$'nin doğruluk tablosunda yalnız bir satır 1'dir. Bu yüzden $Y_i$, $i$ numaralı mintermin kendisidir: $Y_i = m_i$. Bir fonksiyonu en genel hâliyle

$$F = \sum_i F_i \, m_i$$

diye yazıyorduk; $m_i$ $i$ numaralı minterm, $F_i$ doğruluk tablosunun o satırındaki çıkış değeridir. Dekoderle elimizde bütün mintermler hazırdır.

### 4.2 OR katının gösterimi ve programlama

Şemalarda OR kapısına tek bir çizgi bağlıymış gibi çizilir. Bu basitleştirilmiş bir gösterimdir. Gerçekte OR kapısının girişlerine bütün dekoder çıkışları bağlıdır ve her bağlantı noktası bir sigortadır. Sigorta korunacaksa o noktaya çarpı (X) konur. Sigorta yakılacaksa hiçbir işaret konmaz.

Tahtadaki örnek (ekrandan, 00:30:00): girişler $x$ (en anlamlı), $y$, $z$ dekoderin $C$, $B$, $A$ seçim uçlarına bağlıdır. Dekoder çıkışları sırasıyla $x'y'z'$, $x'y'z$, $x'yz'$, $x'yz$, $xy'z'$, $xy'z$, $xyz'$, $xyz$ mintermleridir. OR kapısında 0, 4 ve 7 numaralı çıkışların sigortaları korunmuş, 5, 6 ve diğerleri yakılmıştır. Çıkış:

$$f = x'y'z' + xy'z' + xyz$$

Günümüzde sigortası kalıcı yakılan ROM'lar artık kullanılmıyor; elektriksel olarak tekrar programlanabilen ROM'lar (EEPROM) var. Bunlarda bir gerilim uygulanarak bağlantı kurulur ya da koparılır; ters yönde gerilim verilerek aynı bağlantı yeniden açılıp kapanabilir.

### 4.3 ROM'da AND katı nerede?

Hoca şemada hiç AND kapısı görmediğini, AND katının nerede olduğunu sordu.

**Soru:** ROM'da hem AND hem OR katı var; OR katını programladık ama AND katı nerede? **Cevap:** Bir öğrenci AND katını dekoderin sağladığını söyledi. Hoca doğruladı: dekoderin çıkışları çarpım terimleridir. Önceki derslerden hatırlanacağı gibi dekoderin içi AND ve NOT kapılarından oluşan bir lojik bloktur; AND katı bunun içindedir. OR tarafının programlanması ise dekoder çıkışlarıyla OR girişleri arasındaki bağlantıları korumak ya da yakmaktır.

### 4.4 Blok yapıyla bağlantı

Hoca 3 adres ($A_0$, $A_1$, $A_2$) ve 4 veri ucu ($D_0 \ldots D_3$) olan basit bir ROM'un bu iç yapıyla nasıl kurulacağını sordu. Adres uçları dekodere, anlam sırası korunarak bağlanır: $A_0$ en düşük anlamlıdır ve dekoderin en düşük anlamlı seçim ucuna gider. $D_0 \ldots D_3$ ise OR kapılarının çıkışlarıdır. Veri ucu sayısı kadar OR kapısı vardır ve bu kapıların girdileri birbirinden bağımsızdır: bir kapıya bağlanan mintermler diğerine bağlananlardan bağımsızdır, her minterm istenen her çıkışa bağlanabilir.

## 5. Sigorta Yakma ve ROM Türleri

### 5.1 Sigorta nasıl yakılır?

**Soru:** Bir öğrenci, programlarken sigorta yakmanın ne demek olduğunu sordu. **Cevap:** Örneğin $D_7$ çıkışı ile OR kapısı arasındaki bağlantıyı bir transistör sağlar ve transistöre bir sigorta elemanı bağlıdır. Transistörde uygun gerilim oluşturulursa bağlantı sağlanır. Sigortanın bir en büyük akım değeri vardır. Transistörü bozmayacak biçimde, baz ucuna bağlı sigortadan bu değerden yüksek bir akım geçirilirse sigorta yanar ve dekoder çıkışıyla OR kapısı arasındaki bağlantı kopar. Bu yapılar geri dönülemezdir. Hoca bu örneği BJT tipi transistör üzerinden düşündüğünü söyledi. Geri dönülebilir yapılarda (MOSFET tipi) gerilim seviyesi belirli bir değerde tutulup bırakılarak bağlantı açılıp kapanabilir; kapı (gate) "float" eder gibi bir durum oluşur, bağlantı kalıcı olarak yakılmaz.

### 5.2 ROM türleri

Slayttaki liste (ekrandan, 00:35:00) ve hocanın açıklamaları:

1. **ROM (maskeli):** üretim aşamasında programlanır, sonra yeniden programlanamaz.
2. **PROM:** üretimde programlanmaz; kullanıcı bir kez programlar (sigorta ya da antisigorta).
3. **EPROM:** silinebilir PROM. Yonganın üstünde küçük bir pencere vardır; bu pencereden yeterince uzun süre morötesi (UV) ışık tutulursa program silinir.
4. **EEPROM ($E^2PROM$):** elektriksel olarak silinebilen ve yazılabilen ROM. Adres ve veri uçları dışında programlama koşullama uçları vardır; bunlara uygun elektrik seviyeleri verilince cihaz silinir ve yeniden programlanır.
5. **Flash bellek:** EEPROM'a benzer; teknolojisi gereği yazma, okuma ve silme blok blok yapılır.

Aynı slaytta 5'ten 32'ye dekoderli, 8 çıkışlı ($A_7 \ldots A_0$) bir ROM'un iç yapısı da görünüyordu; derste ayrıntısına girilmedi.

## 6. Örnek: Tam Toplayıcının ROM ile Gerçeklenmesi

Hoca tahtaya şu soruyu yazdı (ekrandan, 00:40:00): "1 bitlik tam toplayıcıyı uygun büyüklükteki bir ROM cihazı ile gerçekleyiniz." Hangi sigortaların korunacağı, hangilerinin yakılacağı sorulmaktadır.

### 6.1 ROM büyüklüğü

ROM'lar $2^m \times n$ diye tanımlanıyordu: $m$ adres ucu sayısı, $n$ veri ucu sayısıdır. Hoca en küçük ROM için $m$ ve $n$ değerlerini sordu.

**Soru:** Bu problem için en küçük ROM nedir? **Cevap:** Bir öğrenci "3'e 2" dedi: girişler $A$, $B$ ve elde girişi, çıkışlar toplam ve elde çıkışı. Hoca doğruladı.

Tam toplayıcı $a + b + c_{in}$ toplamını iki bitlik $(c_{out}\, s)_2$ sayısı olarak üretir. 3 girdi olduğu için $m = 3$, 2 çıktı olduğu için $n = 2$'dir. Gereken ROM (hipotetik olarak) $2^3 \times 2$'dir. İçinde bir 3x8 dekoder ($Y_0 \ldots Y_7$ çıkışlı) ve 2 OR kapısı vardır. $A$, $B$, $C_{in}$ dekoder girişlerine; bir OR kapısının çıkışı $C_{out}$'a, diğeri $S$'ye bağlanır.

### 6.2 Doğruluk tablosu ve programlama

| $A$ | $B$ | $C_{in}$ | Minterm | $C_{out}$ | $S$ |
|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 | 0 | 1 |
| 0 | 1 | 0 | 2 | 0 | 1 |
| 0 | 1 | 1 | 3 | 1 | 0 |
| 1 | 0 | 0 | 4 | 0 | 1 |
| 1 | 0 | 1 | 5 | 1 | 0 |
| 1 | 1 | 0 | 6 | 1 | 0 |
| 1 | 1 | 1 | 7 | 1 | 1 |

$C_{out}$ için doğru mintermler 3, 5, 6 ve 7'dir. Bu yüzden $C_{out}$ OR kapısında bu dört dekoder çıkışının bağlantısı korunur:

$$C_{out} = \sum m(3,5,6,7) = A'BC_{in} + AB'C_{in} + ABC_{in}' + ABC_{in}$$

$S$ için doğru mintermler 1, 2, 4 ve 7'dir:

$$S = \sum m(1,2,4,7) = A'B'C_{in} + A'BC_{in}' + AB'C_{in}' + ABC_{in}$$

Diğer bütün bağlantıların sigortası yakılır. Hoca bunu pratik bir yol olarak özetledi: doğruluk tablosunu yap, 1 olan satırları işaretle, o mintermleri ilgili OR'a bağla.

Tablo ve iki ifade python ile doğrulandı.

## 7. Örnek: Programlanmış Bir ROM'un Okunması

Slayttaki örnek (ekrandan, 00:45:00): "8 X 4 ROM ($N = 3$ giriş hattı, $M = 4$ çıkış hattı). Sabit AND dizisi 3 girişli, 8 çıkışlı bir dekoderdir. Programlanabilir OR dizisi bir OR kapısının bütün girişlerini tek çizgiyle gösterir; dizideki X, mintermin OR'a bağlanması demektir. Okuma örneği: $(A_2,A_1,A_0) = 001$ girişi için çıkış $(F_3,F_2,F_1,F_0) = 0011$'dir. $F_3$, $F_2$, $F_1$ ve $F_0$ fonksiyonları $(A_2, A_1, A_0)$ cinsinden nedir?" Hoca, önceki ROM tanımıyla burada $N$ ve $M$ harflerinin yer değiştirdiğini, anlamın aynı olduğunu belirtti. Girişler $A$, $B$, $C$ sırasıyla $A_2$, $A_1$, $A_0$'a bağlıdır.

Şemadaki X'ler şöyledir:

| Çıkış | Bağlı dekoder çıkışları |
|---|---|
| $F_3$ | $D_2$, $D_5$, $D_7$ |
| $F_2$ | $D_0$, $D_7$ |
| $F_1$ | $D_1$, $D_4$ |
| $F_0$ | $D_1$, $D_5$, $D_7$ |

### 7.1 İçeriğin okunması

Soru şöyle düşünülmeli: ROM önceden programlanmış geliyor ve biz adres uçlarına karşılık çıkışları kontrol ediyoruz. Adres 000 uygulanınca dekoderin $D_0$ çıkışı aktif (1), diğerleri 0 olur.

**Soru:** Bir öğrenci $D_7$'nin 1 göründüğünü söyledi. **Cevap:** Hoca, 000 seçim değeri verilince dekoderin $D_0$ çıkışının aktif olacağını hatırlattı. Şemadaki çarpılar dekoderin değil, OR bağlantılarının durumunu gösterir.

Adres 000 için: $F_3$'e bağlı mintermlerin hepsi şu anda 0, yani $F_3 = 0$. $F_2$'ye $D_0$ bağlıdır; OR kapısında bir tane 1 bulmak yeter, $F_2 = 1$. $F_1$ ve $F_0$'da $D_0$ bağlantısı yakılmış, ikisi de 0. Bu yüzden 0 adresinin içeriği $0100$, yani ondalık 4'tür. Aynı yolla:

- Adres 001 ($D_1$ aktif): $F_1$ ve $F_0$ 1 olur, içerik $0011$.
- Adres 010 ($D_2$ aktif): yalnız $F_3$ bağlı, içerik $1000$.
- Adres 111 ($D_7$ aktif): $F_3$, $F_2$, $F_0$ bağlı, içerik $1101$.

### 7.2 Fonksiyonların yazılması

Doğruluk tablosu kurmadan da fonksiyonlar doğrudan mintermlerden yazılabilir (ekrandan, 00:50:00). $A = A_2$, $B = A_1$, $C = A_0$ ile:

$$F_0 = A'B'C + AB'C + ABC \quad (m_1 + m_5 + m_7)$$

$$F_1 = A'B'C + AB'C' \quad (m_1 + m_4)$$

$$F_2 = A'B'C' + ABC \quad (m_0 + m_7)$$

$$F_3 = A'BC' + AB'C + ABC \quad (m_2 + m_5 + m_7)$$

Bunlar indirgenmiş değil, çarpımlar toplamı hâlleridir; istenirse daha da sadeleştirilebilir. Hoca örneğin iki yönü olduğunu vurguladı: tasarımda ROM'a hangi değerlerin yazılacağı, analizde ise programlanmış ROM'daki değerlerin nasıl okunacağı.

## 8. PLA (Programmable Logic Array)

Aradan sonra hoca PLA cihazlarına geçti. PLA'nın temel özelliği hem AND hem OR katının programlanabilmesidir. Ancak ROM'dan farklı olarak AND katında bütün mintermler üretilmez. 3 girişli bir ROM'da 8 AND çıkışı (dekoder çıkışı) varken, slayttaki 3 girişli PLA'da yalnız 4 AND kapısı vardır (ekrandan, 01:10:00). Girişler $A$, $B$, $C$ ve tümleyenleri ($A'$, $B'$, $C'$) AND kapılarına programlanabilir bağlantılarla gelir.

Bütün mintermler üretilmediği için bazı fonksiyonlar hiç gerçeklenemeyecek mi? Hayır. OR katı da programlanabilir ve en önemlisi, son katta programlanabilir bir XOR katı vardır. XOR'un ikinci girişi 0'a ya da 1'e bağlanabilir. Böylece OR çıkışı ya olduğu gibi ya da tümlenmiş olarak dışarı verilir. Bir fonksiyonun tümleyenini alabilmek, kabaca geri kalan mintermleri içeren fonksiyonları da gerçekleyebilmek demektir.

Aynı yonga alanını kaplayan bir ROM ile bir PLA karşılaştırıldığında PLA çok daha geniş bir giriş uzayını destekler. Bu yüzden ROM ile gerçeklemenin pratik olmadığı, çok girişli fonksiyonlar için kullanılır.

### 8.1 PLA analizi

Slayttaki programlanmış PLA'da (ekrandan, 01:10:00) gösterim yine ROM'dakine benzer: her AND kapısına tek çizgi çizilmiştir ama aslında 6 tel ($A, A', B, B', C, C'$) 6 girişli bir AND kapısına bağlıdır. Bir çarpı, ilgili telin o kapıya bağlı olduğunu gösterir ("X Closed, + Open").

Hoca ekran paylaşımında bir an yalnız PDF'in göründüğünü fark edip açıklamayı tekrarladı. AND kapılarının çıkışları:

- 1: $AB'$
- 2: $AC$
- 3: $BC$
- 4: $A'BC'$

OR kapıları da 4 girişlidir; her giriş bir AND çıkışına bağlıdır. Hocanın tahtadaki okuması (ekrandan, 01:15:00): birinci OR kapısı $CB + CA$ (3 ve 2), ikinci OR kapısı $AB' + AC + A'BC'$ (1, 2 ve 4) üretir.

XOR katı: $F_1$'e giden XOR'un kontrol girişi 0'a bağlıdır. XOR'un bir girişi 0 ise $0' \cdot x + 0 \cdot x' = x$ olur; diğer giriş olduğu gibi geçer. Hoca bunu, tam toplayıcı entegresinden tam çıkarıcı yaparken 1'e tümleyen almak için XOR kullanılmasına benzetti. Böylece

$$F_1 = AB' + AC + A'BC'$$

$F_2$'ye giden XOR'un kontrol girişi 1'e bağlıdır. $1' \cdot x + 1 \cdot x' = x'$ olduğu için diğer girişin tümleyeni çıkar:

$$F_2 = \overline{CB + CA} = \overline{CB} \cdot \overline{CA} = (C' + B')(C' + A') = C' + C'A' + B'C' + A'B' = C' + A'B'$$

(Son sadeleştirme adımı eklendi; hoca ifadeyi dört terimli hâliyle bıraktı.) İki sonuç python ile doğruluk tablosu üzerinden kontrol edildi: $F_1 = \sum m(2,4,5,7)$, $F_2 = \sum m(0,1,2,4,6)$.

Slaytın ikinci sorusu "PLA bu fonksiyonları XOR kapıları olmadan gerçekleyebilir miydi?" idi. Hocanın cevabı: XOR katı esneklik için vardır. Bazı fonksiyonlar XOR'suz (0 bağlantılı XOR gibi) gerçeklenebilir, ama gereken fonksiyona göre tümleyen almak gerekebilir; genel olarak XOR katı olmadan her fonksiyon gerçeklenemez.

## 9. PLA ile Tasarım: Ortak Çarpım Terimleri

Slayttaki örnek (ekrandan, 01:20:00), Mano'nun kitabından Örnek 6-3:

$$F_1(A,B,C) = \sum m(3,5,6,7), \qquad F_2(A,B,C) = \sum m(1,2,3,7)$$

### 9.1 Neden ortak terim aranır?

Fonksiyon ya olduğu gibi ya da tümleyeni üzerinden gerçeklenecektir. Elde yalnız 4 AND kapısı olduğu için iki fonksiyonun toplam farklı çarpım terimi sayısı 4'ü geçemez. Bu yüzden her fonksiyonun hem kendisi hem tümleyeni yazılır ve en çok ortak terim veren eşleşme seçilir.

Fonksiyonun kendisi iki yolla hesaplanabilir: doğru mintermler (1'ler) Karnaugh haritasında gruplanır ya da yanlış makstermlerden (0'lar) gidilir. Tümleyeni bulmak için ise 0 olan gözler sanki 1'miş (doğru mintermmiş) gibi gruplanır. Hoca bu ikisinin karıştırılmaması gerektiğini söyledi.

### 9.2 Karnaugh haritaları

$F_1$ haritası (satır $A$, sütun $BC$ = 00, 01, 11, 10): $A = 0$ satırı 0, 0, 1, 0; $A = 1$ satırı 0, 1, 1, 1. 1'lerden:

$$F_1 = AB + AC + BC$$

Tümleyen için 0'lar gruplanır. Slayttaki mavi gruplar: $BC = 00$ sütunundaki iki 0 birlikte ($B'C'$), $m_1$ ve $m_2$ tek başına:

$$\overline{F_1} = A'B'C + A'BC' + B'C'$$

$F_2$ haritası: $A = 0$ satırı 0, 1, 1, 1; $A = 1$ satırı 0, 0, 1, 0. En sade hâli

$$F_2 = A'B + A'C + BC$$

Ortak terim üretmek için ikinci bir yazım (mavi gruplar):

$$F_2 = A'B'C + A'BC' + BC$$

**Soru:** Bir öğrenci, $\overline{F_1}$ hesaplanırken 000 ve 001 gözlerindeki 0'ların neden tek grup yapılmadığını sordu. **Cevap:** Amaç her iki fonksiyonda ortak çarpım terimleri üretmektir. 000 ve 100 gözleri iki fonksiyonda da 0 olduğu için birlikte alınabilir. Ama 001 ve 010 gözleri $F_2$'de 1'dir; onları $F_1$'in tümleyeninde başka gözlerle gruplarsak $F_2$'de karşılığı olan bir terim çıkmaz. Bu yüzden tekil bırakılırlar. Yani bir yandan kapı optimizasyonu yapıldığı için olası en büyük gruplar alınamaz.

Hoca $\overline{F_2}$'yi de yazdı: 0'lar 1 gibi alınınca $B'C'$ ortak grubu ve tekil kalan $AB'C$, $ABC'$ terimleri gelir:

$$\overline{F_2} = B'C' + AB'C + ABC'$$

Hoca iki fonksiyonun da tümleyenini almanın her zaman anlamlı olmayabileceğini, çünkü birinin tümleyeninin diğerinin orijinaline denk gelebileceğini; yine de bütün seçenekleri görmek için dört yazımın da çıkarıldığını söyledi.

**Soru:** Bir öğrenci ortak terim oluşturmanın neden yapıldığını sordu. **Cevap:** PLA bir ROM gibi değildir; bütün çarpım terimleri üretilemez. 3 girişte bütün çarpım terimleri için $2^3 = 8$ AND kapısı gerekir. Daha fazla giriş destekleyebilmek için AND kapısı sayısından feragat edilmiş, onun yerine çıkışta tümleyen alınabilsin diye XOR katı konmuştur. Bu yüzden bir fonksiyon için üretilen kapılar diğer fonksiyonun ya kendisinde ya tümleyeninde aranır. Tümleyende bulunursa aynı AND çıkışı paylaşılır ve sonuç XOR'da tümlenir.

### 9.3 Seçim ve gerçekleme

$F_1$ tümleyeniyle, $F_2$ ise ikinci yazımıyla alınınca ortak terim sayısı en yüksek olur: $A'B'C$ ve $A'BC'$ ikisinde de vardır; farklı olanlar $B'C'$ ve $BC$'dir. Slayttaki çözüm (ekrandan, 01:30:00):

$$F_1 = \overline{A'B'C + A'BC' + B'C'}$$

$$F_2 = A'B'C + A'BC' + BC$$

Hoca bunu PLA şemasının üstüne kırmızı çarpılarla gerçekledi (ekrandan, 01:35:00):

- AND 1: $A'B'C$ (ortak)
- AND 2: $A'BC'$ (ortak)
- AND 3: $B'C'$
- AND 4: $BC$

$F_1$'in OR kapısına 1, 2 ve 3 numaralı terimler; $F_2$'nin OR kapısına 1, 2 ve 4 numaralı terimler bağlanır. $F_1$ tümleyen olarak tanımlandığı için XOR kontrol girişi 1'e, $F_2$ olduğu gibi geçeceği için 0'a bağlanır. Bu, 4 çarpım terimi sınırına tam sığar. Hoca, başka fonksiyonlarda belki $F_2$'nin tümleyeni ile $F_1$'in daha çok ortak terim vereceğini, bunun her seferinde analiz edilmesi gereken bir optimizasyon olduğunu söyledi.

Hoca tahtadaki yazımda bir terimi yanlış yazdığını fark edip düzeltti; yukarıdaki terimler slayttaki çözümden alındı. İki ifade python ile doğrulandı: $\overline{A'B'C + A'BC' + B'C'} = \sum m(3,5,6,7)$, $A'B'C + A'BC' + BC = \sum m(1,2,3,7)$.

## 10. PAL (Programmable Array Logic)

PAL'da AND katı programlanabilir, OR katı sabittir. Hoca genel iç yapıyı gösterip temel kısıtın nereden geldiğini sordu. PLA'da kısıt AND kapısı sayısıydı. Bir öğrenci kısıtın OR kapısından geldiğini söyledi; hoca doğruladı: bir OR kapısı yalnız belirli sayıda AND çıkışını kabul eder. Örnekteki yapıda toplanabilecek çarpım terimi sayısı 3 ile sınırlıdır.

3'ten fazla çarpım terimi toplamak için bir yol vardır: bir çıkış ($W$) aynı zamanda AND katına geri besleme olarak verilir. Böylece 3 terimin toplamı, başka bir kapıdaki 2 terime eklenebilir ve 5 terimli fonksiyon yazılabilir. Yine de bir sınır vardır. Bunun için ortak toplam terimleri üretmek gerekir.

Slaytta PAL'ın özellikleri de yazılıydı (ekrandan, 01:40:00): aynı iç karmaşıklıkta PAL daha büyük $N$ ve $M$ değerlerine sahip olabilir; bazı PAL'ların çıkışları tümlenebilir, bu da POS fonksiyonları ekler; ROM'da (çıkıştan girişe dış bağlantı olmadan) çok katlı devre kurulamaz, PAL'da ise OR terimlerinin çıkışları bütün AND terimlerine iç giriş olarak verildiği için çok katlı devre kurmak kolaydır.

### 10.1 PAL örneği

Slayttaki örnek (ekrandan, 01:40:00): 4 girişli, 3 girişli sabit OR terimli bir PAL.

$$W(A,B,C,D) = \sum m(2,12,13)$$

$$X(A,B,C,D) = \sum m(7,8,9,10,11,12,13,14,15)$$

$$Y(A,B,C,D) = \sum m(0,2,3,4,5,6,7,8,10,11,15)$$

$$Z(A,B,C,D) = \sum m(1,2,8,12,13)$$

En az terime sadeleştirilince:

$$W = ABC' + A'B'CD'$$

$$X = A + BCD$$

$$Y = A'B + CD + B'D'$$

$$Z = ABC' + A'B'CD' + AC'D' + A'B'C'D = W + AC'D' + A'B'C'D$$

$Z$ dört terimlidir, ama bir OR kapısında en fazla 3 terim olabilir. $Z$'nin ilk iki terimi $W$'ye eşittir. Bu yüzden $Z = W + \ldots$ yazılınca $Z$ de üç terimli bir toplama indirgenir.

Gerçekleme: $A, B, C, D$ ve tümleyenleri girdi olarak verilmiştir. $W$ bölümünde birinci AND'e $A$, $B$, $C'$ bağlanır ($ABC'$), ikinciye $A'$, $B'$, $C$, $D'$ bağlanır ($A'B'CD'$). Üçüncü AND'in hiç bağlantısı yoktur; bu kapı devreden çıkarılmış gibidir ve çıkışı her zaman 0 kabul edilebilir, çünkü OR katında etkisiz eleman 0'dır. $Z$ bölümünde birinci AND'e geri beslenen $W$ bağlanır; ikincisine $A$, $C'$, $D'$ ($AC'D'$); üçüncüsüne $A'$, $B'$, $C'$, $D$ ($A'B'C'D$). $X$ ve $Y$'nin terim sayıları 2 ve 3 olduğu için olduğu gibi gerçeklenebilir. Hoca daha üst düzey bir optimizasyonun gerekebileceğini, ama PAL'ın çalışma mantığının bu olduğunu söyledi.

> **Ders sonrası not:** Dört sadeleştirilmiş ifade python ile minterm listeleriyle karşılaştırıldı; hepsi slayttaki $\sum m$ tanımlarıyla aynıdır.

## 11. Bir PLD Cihazı: WinCUPL ve Proteus Örnekleri

Hoca bu kısmın zorunlu olmadığını, bilgi amaçlı gösterdiğini söyledi.

### 11.1 22V10 ve barrel shifter

GAL 22V10 adlı PLD cihazı, PAL, PLA ve ROM'daki AND-OR dizilerinden farklı olarak daha karmaşık lojik eleman blokları şeklinde tasarlanmıştır. Her blokta bir D flip-flop ve ilgili lojik kapılar vardır; blok programlanabilir genel bir lojik eleman gibi davranır. Proteus şemasında (ekrandan, 01:45:00) AM22V10 cihazının girişlerine 8 veri anahtarı, 3 kaydırma seçim anahtarı, saat işareti, çıkış yetkilendirme ve preset uçları bağlıdır.

Örnek, derste daha önce görülen barrel shifter'dır: sağa ya da sola döndürerek işlem yapan birim. Program WinCUPL ile yazılır. Hoca programın eski olduğunu ve bir hatası olduğunu söyledi: derlemeden önce projeyi kapatmak gerekiyor, yoksa derlerken pencere kapanıyor.

Ekrandaki kodun ana kısmı (ekrandan, 01:50:00):

```text
/** Inputs **/
PIN 1          = clock;        /* Register Clock            */
PIN [2..9]     = [D7..0];      /* Data Inputs               */
PIN [10,11,14] = [S2..0];      /* Shift Count Select Inputs */
PIN 13         = !out_enable;  /* Register Output Enable    */
PIN 23         = preset;       /* Set to Ones Input         */

/** Outputs **/
PIN [15..22] = [Q7..0];        /* Register Outputs          */

field shift  = [S2..0];
field input  = [D7..0];
field output = [Q7..0];

output.d  =  [D7, D6, D5, D4, D3, D2, D1, D0] & shift:0
          #  [D0, D7, D6, D5, D4, D3, D2, D1] & shift:1
          #  [D1, D0, D7, D6, D5, D4, D3, D2] & shift:2
          #  [D2, D1, D0, D7, D6, D5, D4, D3] & shift:3
          #  [D3, D2, D1, D0, D7, D6, D5, D4] & shift:4
          #  [D4, D3, D2, D1, D0, D7, D6, D5] & shift:5
          #  [D5, D4, D3, D2, D1, D0, D7, D6] & shift:6
          #  [D6, D5, D4, D3, D2, D1, D0, D7] & shift:7;

output.sp = preset;     /* synchronous preset        */
output.oe = out_enable; /* tri-state control         */
output.ar = 'h'00;      /* asynchronous reset not used */
```

Açıklama: her cihazda giriş ve çıkış olarak kullanılabilecek pinler cihaza özeldir. Pin 1 saat, pin 2-9 sekiz bitlik veri girişi olarak adlandırılır; anlam sırası korunur (pin 2 $D_7$'ye, pin 9 $D_0$'a karşılık gelir). 3 bitlik kontrol ucu ($S_2 S_1 S_0$) kaydırmanın nasıl yapılacağını belirler. Pin 13 çıkış yetkilendirme, pin 23 preset ucudur. Çıkışlar ($Q$) entegrenin 15-22 numaralı bacaklarına karşılık gelir. `field` tanımları bitleri birleştirerek bir "struct" gibi tek bir alan yapar. Mantık denklemi bir `case` kontrolü gibidir: `shift` 0 ise girişler olduğu gibi, 1 ise bir basamak döndürülmüş, ... 7 ise yedi basamak döndürülmüş olarak çıkış registerının D girişlerine (`output.d`) yazılır. Arka planda bu alan, D flip-flop'lardan oluşan 8 bitlik bir registerdır; preset, çıkış yetkilendirme ve asenkron reset uçlarıyla bit bit yönetilebilir.

> **Ders sonrası not:** Hoca 23 numaralı pindeki preset ucunu "asenkron preset" diye tanıttı; ekrandaki kodda `output.sp` satırının yorumu "synchronous preset" diyor, asenkron reset (`output.ar`) ise kullanılmıyor.

Derleme sonunda JED uzantılı bir dosya oluşur. Bu dosya WinCUPL ile entegreye yüklenebilir ya da simülasyon için Proteus'ta cihazın özelliklerinden (edit properties) dosya yolu gösterilerek yüklenir. Simülasyonda kaydırma kontrolü 0 iken girişler saat işaretiyle senkron olarak çıkışa geçti; preset ucuna basılınca çıkışlar 1 oldu; sonraki saat işaretinde girişteki değer yeniden yüklendi. Sonra 1, 2, 3 ve 7 basamaklık döndürmeler gösterildi.

### 11.2 4 bitlik toplayıcı

İkinci örnek 16V8 tipi bir cihazda (Proteus'ta AM16V8, ekrandan, 01:55:00) 4 bitlik toplayıcıdır. Program mantığı aynıdır: fiziksel pinlerin etiketleri tanımlanır; 4 bitlik $X$ ve $Y$ sayıları, 4 bitlik toplam, her bit için elde ve son elde çıkışı pinlere atanır. Bir fonksiyon tanımlanır; girdileri $X$, $Y$, elde girişi ve elde çıkışıdır. $C_{out}$, $X$, $Y$ ve eldeye bağlı olarak yazılır. Kodda `$` işareti XOR'dur; toplam biti bütün girdilerin XOR'udur. Sonra bu 1 bitlik toplayıcı fonksiyonu farklı girdilerle dört kez çağrılır ve her bitin eldesi bir sonraki bite (kaskat bağlı "bit slice") aktarılır. <!-- BELİRSİZ: toplayıcı kodunun satırları karelerde görünmüyor; yalnız anlatım altyazıdan aktarıldı. -->

Simülasyonda en düşük anlamlı bitlerde 1 + 1 = 2 elde edildi; en yüksek anlamlı bitlerde 8 + 8 toplanınca taşan elde, elde çıkışında görüldü.

Hoca bu cihazla tek başına ardışıl devre tasarımı yapılamayacağını, bunun için dışarıdan flip-flop entegreleri eklemek gerektiğini söyledi. Cihazın gelişmiş sürümlerinde ise register olarak kullanılanlar dışında tek tek programlanabilen flip-flop'lar da vardır.

## 12. FPGA ve Verilog'a Kısa Bakış

PLD'nin gelişmiş bir sürümü, bugün prototiplemede çok yaygın kullanılan FPGA yongalarıdır. Bunlar VHDL ya da Verilog dilleriyle kodlanır. Icarus Verilog ile derleme yapılıp modüller oluşturulabilir. Zaman kısıtlı olduğu için yalnız iki örnek gösterildi. <!-- BELİRSİZ: Verilog kodları karelerde görünmüyor; aşağıdaki açıklama yalnız altyazıdan. -->

- **Yarım toplayıcı modülü:** Verilog'da bir modül tanımıdır; modülün adı ve giriş-çıkışları tanımlanır. İki 1 bitlik sayıyı alır, toplamlarını 2 bitlik ikili sayı olarak $C$ ve $S$ biçiminde üretir. Gerçekleme yerleşik (built-in) `and` ve `xor` ilkel modülleriyle yapılmıştır.
- **3'e 8 dekoder:** bir `always` bloğu içinde yazılmıştır. Blok, ikili giriş ya da enable ucu her değiştiğinde çalışır ve bir `case` kontrolüyle girişin ondalık karşılığına göre farklı çıkış değerleri üretir. Hoca koddaki girişin 4 bit olarak tanımlandığını, bunun yanlış olduğunu, 3 bit olması gerektiğini belirtti.

Hoca `always` bloğunun, saat işaretinin yükselen ya da düşen kenarıyla birlikte senkron ardışıl devre tasarımında kullanılacak blok olduğunu söyledi.

## 13. Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): 1 bitlik tam toplayıcıyı uygun büyüklükteki bir ROM cihazı ile gerçekleyiniz. Hangi sigortalar korunur, hangileri yakılır?

> **Çözüm (derste verildi):** 3 giriş ($A$, $B$, $C_{in}$), 2 çıkış ($C_{out}$, $S$) olduğu için $2^3 \times 2$ ROM yeterlidir (3x8 dekoder + 2 OR). $C_{out}$ kapısında 3, 5, 6, 7; $S$ kapısında 1, 2, 4, 7 numaralı dekoder çıkışlarının sigortaları korunur, diğerleri yakılır. $C_{out} = \sum m(3,5,6,7)$, $S = \sum m(1,2,4,7)$.

**Soru 2** (ekrandan, 00:45:00): 8 x 4 ROM'da (şemadaki bağlantılar: $F_3$: $D_2, D_5, D_7$; $F_2$: $D_0, D_7$; $F_1$: $D_1, D_4$; $F_0$: $D_1, D_5, D_7$) $(A_2,A_1,A_0) = 001$ için çıkışın $0011$ olduğunu gösteriniz. $F_3$, $F_2$, $F_1$, $F_0$ fonksiyonlarını $(A_2, A_1, A_0)$ cinsinden yazınız.

> **Çözüm (derste verildi):** 001 adresi $D_1$'i aktif eder; $D_1$'e bağlı çıkışlar $F_1$ ve $F_0$ olduğu için içerik $0011$'dir. Derste ayrıca 000 → 0100, 010 → 1000, 111 → 1101 okundu. $F_0 = A'B'C + AB'C + ABC$, $F_1 = A'B'C + AB'C'$, $F_2 = A'B'C' + ABC$, $F_3 = A'BC' + AB'C + ABC$ ($A = A_2$, $B = A_1$, $C = A_0$).

> **Çözüm (derste verilmedi, tamamlama):** Okunmayan adresler python ile hesaplandı: 011 → 0000, 100 → 0010, 101 → 1001, 110 → 0000.

**Soru 3** (ekrandan, 01:10:00): AND kapıları $AB'$, $AC$, $BC$, $A'BC'$ olan, birinci OR'u $BC + AC$, ikinci OR'u $AB' + AC + A'BC'$ toplayan, $F_1$ XOR'u 0'a, $F_2$ XOR'u 1'e bağlı PLA için $F_1$ ve $F_2$ denklemleri nedir? PLA bu fonksiyonları XOR kapıları olmadan gerçekleyebilir miydi?

> **Çözüm (derste verildi):** $F_1 = AB' + AC + A'BC'$; $F_2 = \overline{BC + AC} = C' + A'B'$. XOR katı tümleyen alma esnekliği içindir; genel olarak XOR katı olmadan her fonksiyon gerçeklenemez.

**Soru 4** (ekrandan, 01:20:00): $F_1(A,B,C) = \sum m(3,5,6,7)$ ve $F_2(A,B,C) = \sum m(1,2,3,7)$ fonksiyonlarını 4 AND kapılı, 3 girişli bir PLA ile gerçekleyiniz (Mano Örnek 6-3).

> **Çözüm (derste verildi):** $\overline{F_1} = A'B'C + A'BC' + B'C'$ ve $F_2 = A'B'C + A'BC' + BC$ seçilirse yalnız 4 çarpım terimi gerekir: $A'B'C$, $A'BC'$, $B'C'$, $BC$. $F_1$ OR'una 1, 2, 3; $F_2$ OR'una 1, 2, 4 numaralı terimler bağlanır. $F_1$ XOR'u 1'e (tümleme), $F_2$ XOR'u 0'a bağlanır.

**Soru 5** (ekrandan, 01:40:00): 4 girişli, 3 girişli sabit OR terimli bir PAL ile $W = \sum m(2,12,13)$, $X = \sum m(7,8,9,10,11,12,13,14,15)$, $Y = \sum m(0,2,3,4,5,6,7,8,10,11,15)$, $Z = \sum m(1,2,8,12,13)$ fonksiyonlarını gerçekleyiniz.

> **Çözüm (derste verildi):** $W = ABC' + A'B'CD'$, $X = A + BCD$, $Y = A'B + CD + B'D'$, $Z = W + AC'D' + A'B'C'D$. $Z$ dört terimli olduğu için $W$ çıkışı AND katına geri beslenir ve $Z$'nin OR kapısına bir terim olarak bağlanır; $W$ bölümündeki kullanılmayan üçüncü AND'in bağlantısı yoktur (çıkışı 0).

## Dersin Toparlaması

Bu derste önce RAM ve ROM'un iç yapısı görüldü: ikisinde de adres uçlarına karşılık satırı bir dekoder seçer. Ardından programlanabilir lojik cihazlar karşılaştırıldı. ROM'da AND katı sabittir (dekoder bütün mintermleri üretir) ve OR katı sigortalarla programlanır; bu yüzden ROM ile tasarım, doğruluk tablosundaki 1'lerin mintermlerini ilgili OR'a bağlamaktan ibarettir. Tam toplayıcı örneğinde $2^3 \times 2$ ROM ile tasarım, 8 x 4 ROM örneğinde ise programlanmış bir ROM'un içeriğinin ve fonksiyonlarının okunması yapıldı.

PLA'da iki kat da programlanabilir ama AND kapısı sayısı sınırlıdır. Çıkıştaki programlanabilir XOR katı tümleme imkânı verir; tasarımda fonksiyonların kendileri ve tümleyenleri Karnaugh haritalarından çıkarılıp en çok ortak çarpım terimi veren eşleşme seçilir. PAL'da AND katı programlanabilir, OR katı sabittir ve kısıt bir OR kapısına bağlanabilecek terim sayısıdır; bu sınır, bir çıkışın AND katına geri beslenmesiyle aşılır. Son olarak bir PLD cihazında (22V10, 16V8) WinCUPL ile barrel shifter ve 4 bitlik toplayıcı programlandı, Verilog'da yarım toplayıcı ve dekoder modüllerine kısaca bakıldı. Hoca `always` bloğunun ileride senkron ardışıl devre tasarımında kullanılacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
