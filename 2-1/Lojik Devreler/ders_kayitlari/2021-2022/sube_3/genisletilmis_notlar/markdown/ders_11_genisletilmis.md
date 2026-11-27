# Ders 11 Genişletilmiş Notu: Kanonik Formlar, Mintermler ve Maxtermler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Boole cebri tekrarı ve sadeleştirme örnekleri
- 2. Kanonik formlara giriş ve doğruluk tablosu
- 3. Mintermler
- 4. Maxtermler
- 5. İndeks gösterimi ve minterm-maxterm ilişkisi
- 6. İndekslerden fonksiyon kurma
- 7. Kanonik mintermler toplamı (SOM)
- 8. Kanonik maxtermler çarpımı (POM)
- 9. Karışık gösterimler ve sadeleştirmenin önemi
- Örnek Sorular
- Dersin Toparlaması

## 1. Boole cebri tekrarı ve sadeleştirme örnekleri

Ders bir önceki haftanın kısa tekrarıyla başlar. Geçen hafta Boole cebrine giriş yapılmış, aksiyomlar ve teoremler anlatılmış, doğruluk tablosundan lojik diyagrama ve Boole ifadesine geçiş, işlem önceliği ve De Morgan kurallarıyla sadeleştirme örnekleri işlenmişti.

Hoca Boole cebrinin neden önemli olduğunu yeniden hatırlatır. Bir sözel problemden ya da verilmiş bir lojik diyagramdan elde edilen çıkış fonksiyonu $F$, Boole cebri sayesinde matematiksel işlemlerle daha sade bir biçime getirilebilir. Daha sade ifade, daha az kapı ve daha az karmaşık bir lojik diyagram demektir. Bütün teoremlerin arka planında VE, VEYA ve TÜMLEYEN işlemlerinin mantıksal davranışı vardır; örneğin bir önermenin 1 ile VE'lenmesi önermenin kendisini verir.

### 1.1 Yutma teoreminin ispatı

Slaytta yutma (absorption) teoreminin adım adım ispatı yer alır (ekrandan, 00:05:00):

| Adım | Gerekçe |
|---|---|
| $A + A\cdot B$ | |
| $= A\cdot 1 + A\cdot B$ | $X = X\cdot 1$ |
| $= A\cdot(1 + B)$ | $X Y + X Z = X(Y+Z)$ (dağılma) |
| $= A\cdot 1$ | $1 + X = 1$ |
| $= A$ | $X\cdot 1 = X$ |

### 1.2 Sadeleştirme örneği 1

Hoca tahtaya bir ifade yazıp öğrencilerin çözmesini bekler (ekrandan, 00:10:00):

$$\bar A\bar B\bar C + A\,(C\bar D + \bar B) = \,?$$

Çözüm tahtada şu adımlarla yapılır (ekrandan, 00:15:00):

1. $A$ parantezin içine dağıtılır: $\bar A\bar B\bar C + AC\bar D + A\bar B$.
2. $\bar B$ içeren iki terimde $\bar B$ ortak paranteze alınır: $\bar B(\bar A\bar C + A) + AC\bar D$.
3. Parantez içindeki $A + \bar A\bar C$, "$A$ artı"nın dağılma özelliğiyle açılır: $(A + \bar A)(A + \bar C) = 1\cdot(A + \bar C) = A + \bar C$. Hoca burada kestirme bir sonucun bilindiğini, ama bunu mantıkla oturtmanın daha doğru olduğunu söyler.
4. $\bar B(A + \bar C) + AC\bar D$ dağıtılır: $\bar B A + \bar C\bar B + AC\bar D$.

Hoca buradan $\bar B$ yeniden ortak alınıp $\bar B(A + \bar C)$ yazılabileceğini, ama ifadenin daha fazla sadeleşmediğini belirtir. Sonuç python ile 16 girişin hepsi için doğrulandı.

### 1.3 Sadeleştirme örneği 2

İkinci ifade şudur (ekrandan, 00:15:00):

$$(\bar A + ABC)(A + \bar C) = \,?$$

Bir öğrenci tahtada çarpımı üç terime birden dağıtarak çözer; tahtada ilk satır $\bar A A + \bar A\bar C + \dots$ biçimindedir ve hoca sonucu doğru bulur. <!-- BELİRSİZ: öğrencinin tahtaya yazdığı son satır karelerde görünmüyor --> Hocanın anlattığı kısa yol şudur: bir VEYA'nın girişlerinden biri, diğer girişin içinde tümlenmiş olarak geçiyorsa o değişken diğer terimden silinebilir. Burada $\bar A$, $ABC$ terimindeki $A$'yı götürür:

$$\bar A + ABC = (\bar A + A)(\bar A + BC) = \bar A + BC$$

Sonra çarpım açılır (ara adım eklendi):

$$(\bar A + BC)(A + \bar C) = \bar A A + \bar A\bar C + ABC + BC\bar C = \bar A\bar C + ABC$$

Sonuç python ile doğrulandı (mintermler 0, 2, 7). Hoca, öğrencinin üç terimi birden dağıtınca da $A$'nın diğer taraftaki $\bar A$ yüzünden zaten gittiğini, ama örneğin $\bar A$ yerine $\bar D$ olsaydı bu sadeleşmenin olmayacağını ve bir sonraki adımda ekstra iş gerekeceğini söyler. Bu durumu baştan görmek işi kısaltır.

> **Hocanın vurgusu:** Bu konuyla ilgili mutlaka örnek soru çözün; bu kesinlikle önemli bir konu.

## 2. Kanonik formlara giriş ve doğruluk tablosu

Günün konusu kanonik formlardır (canonical forms). Kanonik form, bir Boole fonksiyonunu belli bir standartta göstermeye yarayan biçimdir. İki türü vardır: minterm ve maxterm gösterimleri. Bir $F$ fonksiyonu mintermlerle ya da maxtermlerle, indeksler kullanılarak yazılabilir. Doğruluk tablosunda birden fazla satırda $F = 1$ olduğunda bu terimler birleştirilir: mintermlerin toplamı (sum of minterms, SOM) ya da maxtermlerin çarpımı (product of maxterms, POM). Bu iki gösterim birbirinin tümleyeni gibidir.

### 2.1 Doğruluk tablosunun tekrarı

Kanonik formların çıkarıldığı yer doğruluk tablosudur (truth table). Tablonun solunda giriş değişkenleri ($x, y, z$ ya da daha fazlası), sağında çıkış $F$ bulunur (ekrandan, 00:20:00). Sol taraf, bütün giriş kombinasyonlarının test edildiği kısımdır; her kombinasyon için çıkışın 1 mi 0 mı olduğu, yani önermenin doğru olup olmadığı yazılır.

Bütün kombinasyonları üretmek için $2^0, 2^1, 2^2$ kuralı kullanılır: en sağdaki sütun 0'dan başlayıp her satırda değişir, bir soldaki sütun iki satır aynı kalıp sonra değişir, en soldaki sütun dört satır aynı kalıp sonra değişir.

Örnek olarak $F = x + yz$ alınır (ekrandan, 00:30:00). $000$ satırında $yz = 0$, $x = 0$ olduğundan $F = 0$ olur. VEYA kapısı olduğu için $x = 1$ olan bütün satırlarda $F = 1$'dir. $x = 0$ iken $yz$ bir VE olduğundan yalnız $y = z = 1$ satırında $F = 1$ olur:

| $x$ | $y$ | $z$ | $F$ |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 |

### 2.2 Kanonik forma neden geçiyoruz?

Slayta göre Boole fonksiyonlarını şu özellikleri taşıyan bir biçimde yazmak yararlıdır (ekrandan, 00:25:00):

- Eşitlik karşılaştırmasına izin vermesi.
- Doğruluk tablosuyla birebir karşılığı olması.

Hoca bunu şöyle açıklar: iki devre ya da iki fonksiyon, örneğin $x + yz$ ile $y + z$, kapı sayısına bakılarak kıyaslanabilir (birinde iki, diğerinde bir kapı), ama birbirine eşit olup olmadıkları bu sadeleşmiş hallerinden anlaşılamaz. İkisi de kanonik formda açılırsa açılmış halleri terim terim karşılaştırılabilir. İkinci neden, sadeleşmiş bir ifadede bir terimin birden fazla satırı 1 yapmasıdır; kanonik formda ise her terim doğruluk tablosunda tek bir satıra karşılık gelir.

Kanonik formlarla elde edilen $F$ sadeleşmemiş, genelleşmiş bir fonksiyondur; Boole cebri ancak bundan sonra uygulanır.

## 3. Mintermler

Slayttaki tanım (ekrandan, 00:30:00):

- Minterm, her değişkenin ya olduğu gibi ya da tümlenmiş olarak bulunduğu bir VE terimidir.
- Her ikili değişken normal ($x$) ya da tümlenmiş ($\bar x$) olabildiği için $n$ değişken için $2^n$ minterm vardır.
- İki değişken ($X$, $Y$) için $2 \times 2 = 4$ minterm vardır: $XY$ (ikisi normal), $X\bar Y$ ($X$ normal, $Y$ tümlenmiş), $\bar X Y$ ($X$ tümlenmiş, $Y$ normal), $\bar X\bar Y$ (ikisi tümlenmiş).

Hoca mintermi şöyle özetler: doğruluk tablosunda $F$'yi 1 yapan her satır, değişkenlere bağlı bir VE (çarpım) terimiyle gösterilir. Satırda 1 olan değişken olduğu gibi, 0 olan değişken tümlenmiş yazılır; böylece o satırda VE'nin sonucu 1 olur.

$F = x + yz$ tablosunda $F = 1$ olan satırların mintermleri (ekrandan, 00:30:00):

| Satır | $xyz$ | Minterm |
|---|---|---|
| 3 | 011 | $\bar x y z$ |
| 4 | 100 | $x\bar y\bar z$ |
| 5 | 101 | $x\bar y z$ |
| 6 | 110 | $x y\bar z$ |
| 7 | 111 | $x y z$ |

Örneğin 3. satırda $x = 0$ olduğu için $\bar x$, $y = z = 1$ olduğu için $y z$ yazılır. $F = 0$ olan satırlar için de terim yazılabilir (örneğin $000$ için $\bar x\bar y\bar z$), ama mintermlerle çalışırken bunlar kullanılmaz; yalnız 1'lerin satırları önemlidir.

## 4. Maxtermler

Maxtermler aynı mantıkla, ama VEYA kapılarıyla yazılır ve bu kez 0'lara bakılır. Doğruluk tablosunda $F = 0$ olan her satır için, o satırda 0 sonucunu veren bir VEYA terimi yazılır. Bunun için satırda 0 olan değişken olduğu gibi, 1 olan değişken tümlenmiş yazılır.

Örneğin $000$ satırı için $x + y + z$ yazılır: üç değişken de 0 olduğu için VEYA'nın sonucu 0'dır. Değişkenler tümlenmiş yazılsaydı VEYA 1 verirdi; amaç 0 olduğu için böyle yazılmaz. $010$ satırı için $x + \bar y + z$ yazılır; bu satırda $\bar y = 0$ olur ve terim 0'a düşer.

Hoca iki değişkenli durumu yan yana koyar. Mintermler $00 \to \bar X\bar Y$, $01 \to \bar X Y$, $10 \to X\bar Y$, $11 \to XY$ diye yazılır. Maxtermlerde ise $00$ için $X + Y$ yazılır, yani 0 olan değişken olduğu gibi kalır ki VEYA 0 versin; 1 olan değişkenler tümlenir.

Özetle: mintermde 1 bir değişkenin tümlenmemiş, 0 tümlenmiş halini gösterir; maxtermde 0 değişkenin kendisini, 1 tümleyenini gösterir. Bunun nedeni mintermde VE işleminin sonucunun 1, maxtermde VEYA işleminin sonucunun 0 olması gerekmesidir.

## 5. İndeks gösterimi ve minterm-maxterm ilişkisi

### 5.1 Üç değişkende indeks

Slayttaki üç değişkenli örnek (ekrandan, 00:35:00): değişkenler $X, Y, Z$'dir ve standart sıra önce $X$, sonra $Y$, sonra $Z$'dir. İndeks 0 (onluk) $= 000$ (ikilik) için minterm 0'da üç değişken de tümlenmiştir ($\bar X\bar Y\bar Z$), maxterm 0'da hiçbiri tümlenmemiştir ($X + Y + Z$).

Gösterimde küçük $m$ minterm, büyük $M$ maxterm içindir:

$$m_0 = \bar X\bar Y\bar Z, \qquad M_0 = X + Y + Z$$

Yani $\bar X\bar Y\bar Z$ yazmak yerine kısaca $m_0$, $X + Y + Z$ yazmak yerine $M_0$ yazılabilir.

### 5.2 Minterm 6 ve maxterm 6

Hoca öğrencilere $m_6$ ve $M_6$'yı sorar. Bir öğrencinin VEYA ile yazdığı ifade üzerine hoca, VEYA ile kurulan terimin minterm değil maxterm olduğunu, minterm için VE kullanılması gerektiğini söyler. Ayrıca üç değişkenin de tümlenmemiş olduğu $XYZ$ çarpımı $111$, yani $m_7$'dir. Doğru cevaplar:

- $6 = 110$ olduğundan $m_6 = X Y\bar Z$ (VE'nin sonucu bu satırda 1).
- $M_6 = \bar X + \bar Y + Z$: $110$ girişinde $\bar X = 0$, $\bar Y = 0$, $Z = 0$ olur ve VEYA 0 verir.

Hoca dört değişkenli bir maxterm de söyler: $1100$ için 1 olan $A$ ve $B$ tümlenir, 0 olan $C$ ve $D$ olduğu gibi kalır.

> **Ders sonrası not:** Altyazıda bu ifade "$\bar A + \bar B + C + \bar D$" gibi duyuluyor; kurala göre doğrusu $M_{12} = \bar A + \bar B + C + D$'dir (büyük olasılıkla Whisper hatası ya da dil sürçmesi).

### 5.3 Minterm ve maxterm birbirinin tümleyenidir

Bu iki gösterim arasında De Morgan bağıntısı vardır. Örneğin $\overline{XY} = \bar X + \bar Y$. Yani bir mintermin tümleyeni aynı indeksli maxterm, bir maxtermin tümleyeni aynı indeksli mintermdir:

$$\overline{m_i} = M_i, \qquad \overline{M_i} = m_i$$

## 6. İndekslerden fonksiyon kurma

### 6.1 Mintermlerle: $F_1 = m_1 + m_4 + m_7$

Slayttaki örnekte (ekrandan, 00:40:00) $F_1 = m_1 + m_4 + m_7$ istenir. Küçük $m$ olduğu için terimler VE ile kurulur ve VEYA ile birleştirilir:

- $m_1$: $1 = 001$, yani $\bar x\bar y z$.
- $m_4$: $4 = 100$, $y$ ve $z$ tümlenir: $x\bar y\bar z$.
- $m_7$: $7 = 111$, hepsi normal: $xyz$.

$$F_1 = \bar x\bar y z + x\bar y\bar z + xyz$$

Bu üç kombinasyon dışındaki bütün mintermlerde $F_1 = 0$'dır. İfade daha sonra Boole cebriyle sadeleştirilip lojik diyagrama dönüştürülebilir.

### 6.2 Beş değişkenli örnek

Beş değişkenli bir fonksiyonda 2, 9, 17 ve 23 numaralı mintermler verilir. <!-- BELİRSİZ: bu slayt karelerde yok; değişken adları (A..E) ve indeksler altyazıdan alındı --> Her indeks beş bitlik ikiliğe çevrilir:

| İndeks | Hesap | İkilik ($ABCDE$) | Minterm |
|---|---|---|---|
| 2 | $2$ | 00010 | $\bar A\bar B\bar C D\bar E$ |
| 9 | $8 + 1$ | 01001 | $\bar A B\bar C\bar D E$ |
| 17 | $16 + 1$ | 10001 | $A\bar B\bar C\bar D E$ |
| 23 | $16 + 4 + 2 + 1$ | 10111 | $A\bar B C D E$ |

$$F = \bar A\bar B\bar C D\bar E + \bar A B\bar C\bar D E + A\bar B\bar C\bar D E + A\bar B C D E$$

İkilik açılımlar python ile kontrol edildi. Hoca, gerekiyorsa bu ifadenin sonra Boole cebriyle ya da ileride işlenecek Karnaugh haritalarıyla sadeleştirileceğini, beş değişkenin geri kalan bütün kombinasyonlarında $F = 0$ olduğunu belirtir.

### 6.3 Maxtermlerle: $F_1 = M_0 M_2 M_3 M_5 M_6$

Maxtermler büyük $M$ ile gösterilir ve VE (çarpım) ile birleştirilir (ekrandan, 00:45:00). Her maxtermde, indeksin ikilik değerinde 1 olan değişkenler tümlenir ki o girişte VEYA sonucu 0 olsun:

| Maxterm | İkilik | Terim |
|---|---|---|
| $M_0$ | 000 | $x + y + z$ |
| $M_2$ | 010 | $x + \bar y + z$ |
| $M_3$ | 011 | $x + \bar y + \bar z$ |
| $M_5$ | 101 | $\bar x + y + \bar z$ |
| $M_6$ | 110 | $\bar x + \bar y + z$ |

$$F_1 = (x+y+z)(x+\bar y+z)(x+\bar y+\bar z)(\bar x+y+\bar z)(\bar x+\bar y+z)$$

$000$ girişinden 0 elde etmenin tek yolu üç değişkeni doğrudan VEYA'lamaktır. Hoca, terimler ikilik yazılmayacaksa bu harfli biçimde gösterilebileceğini söyler.

### 6.4 Dört değişkenli maxterm örneği

Slayttaki örnek (ekrandan, 00:50:00):

$$F(A,B,C,D) = M_3 \cdot M_8 \cdot M_{11} \cdot M_{14}$$

- $M_3$: $0011$ girişinde 0 elde etmek için $C$ ve $D$ tümlenir: $A + B + \bar C + \bar D$.
- $M_8$: $1000$ için $A$ tümlenir: $\bar A + B + C + D$.
- $M_{11}$: $11 = 8 + 3 = 1011$ için $A$, $C$, $D$ tümlenir: $\bar A + B + \bar C + \bar D$.
- $M_{14}$: $1110$ için $\bar A + \bar B + \bar C + D$ (ara adım eklendi; derste tahtaya ilk üç çarpan yazıldı).

## 7. Kanonik mintermler toplamı (SOM)

Ara sonrasında hoca, minterm ve maxtermlerin birleştirilerek bütün bir $F$ fonksiyonunu gösterdiği yapılara geçer. Önceki örnekler aslında bunun uygulamalarıydı. Doğruluk tablosunda 1 veren mintermlerin toplamı, tablonun tamamını üreten $F$ fonksiyonunu verir; buna mintermlerin toplamı (SOM) gösterimi denir.

Slayttaki kurallar (ekrandan, 01:00:00):

- Her Boole fonksiyonu mintermlerin toplamı olarak yazılabilir.
- Fonksiyon tablosunda kullanılan mintermler 1'lere karşılık gelenlerdir.
- İfadeden yazarken önce bütün terimler açılır ki bütün mintermler açıkça görünsün. Bunun için bir değişkeni eksik olan her terim $(v + \bar v)$ ile VE'lenir.

### 7.1 Örnek: $f = x + \bar x\bar y$

Minterm ve maxtermlerde her terimde girişteki bütün değişkenlerin bulunması gerekir; sadeleştirmede kaybolacak olsalar bile gösterilmeleri gerekir. $x$ teriminde $y$ eksiktir. $y + \bar y = 1$ olduğundan (biri 0 ise diğeri 1'dir) $x$ terimi bununla çarpılır, böylece $x$ ve $y$'ye bağlı fazladan terimler üretilir (ekrandan, 01:00:00):

$$f = x(y + \bar y) + \bar x\bar y = xy + x\bar y + \bar x\bar y$$

Üç minterm vardır, yani doğruluk tablosunda üç satırın $f$ değeri 1'dir:

$$f = m_3 + m_2 + m_0$$

Bu ifadedeki $f$ ile başlangıçtaki $f$ aynı fonksiyondur; ilki sadeleşmiş, ikincisi kanonik (SOM) gösterimdir.

> **Ders sonrası not:** Hoca kısa gösterimi söylerken "$m_1, m_2, m_3$" dedi; slayttaki doğru sonuç $m_0 + m_2 + m_3$'tür ($xy = 11 \to 3$, $x\bar y = 10 \to 2$, $\bar x\bar y = 00 \to 0$).

### 7.2 Örnek: $F = A + \bar B C$

Hoca bu örneği önce öğrencilere bırakır (ifade slayttan, ekrandan, 01:05:00). Üç değişkenli bir yapıdır, $A, B, C$'ye göre açılır:

- $A$ teriminde $B$ ve $C$ eksik: $A(B + \bar B)(C + \bar C)$.
- $\bar B C$ teriminde $A$ eksik: $(A + \bar A)\bar B C$.

Hepsi çarpılınca:

$$A(B+\bar B)(C+\bar C) = ABC + A\bar B C + AB\bar C + A\bar B\bar C$$

$$(A+\bar A)\bar B C = A\bar B C + \bar A\bar B C$$

İlk kontrol, $A, B, C$'nin hepsini içermeyen bir terim kalıp kalmadığıdır. $A\bar B C$ iki kez geçer; tekrarlardan biri atılır. İndeksler:

| Terim | İkilik | Minterm |
|---|---|---|
| $ABC$ | 111 | $m_7$ |
| $AB\bar C$ | 110 | $m_6$ |
| $A\bar B C$ | 101 | $m_5$ |
| $A\bar B\bar C$ | 100 | $m_4$ |
| $\bar A\bar B C$ | 001 | $m_1$ |

Sıralanınca $F = m_1 + m_4 + m_5 + m_6 + m_7$ olur. Bunun daha kısa, matematiksel gösterimi de vardır (ekrandan, 01:05:00):

$$F(A,B,C) = \Sigma m(1, 4, 5, 6, 7)$$

$\Sigma$ toplam işaretidir ve $m$ ile birlikte "mintermlerin toplamı" anlamına gelir. Yani $A, B, C$ kombinasyonlarına göre $F$'nin 1 olduğu durumlar minterm 1, 4, 5, 6 ve 7'dir. Soru doğrudan bu biçimde sorulabilir ya da cevap bu biçimde yazılabilir. Sonuç python ile doğrulandı.

## 8. Kanonik maxtermler çarpımı (POM)

Diğer gösterim maxtermlerin çarpımıdır (POM). Bu kez $F$'yi 0 yapan terimler VEYA kapılarıyla kurulur ve VE ile birleştirilir.

Slayttaki kurallar (ekrandan, 01:10:00):

- Her Boole fonksiyonu maxtermlerin çarpımı (POM) olarak yazılabilir.
- Fonksiyon tablosunda kullanılan maxtermler 0'lara karşılık gelenlerdir.
- İfadeden yazarken önce bütün terimler açılır. Bunun için önce ikinci dağılma kuralı uygulanır, $V$ değişkeni eksik olan terimlere $V\bar V$ VEYA'lanır ve dağılma kuralı yeniden uygulanır.

### 8.1 Örnek: $f(x,y,z) = x + \bar x\bar y$

Önce dağılma kuralı uygulanır (ekrandan, 01:10:00):

$$x + \bar x\bar y = (x + \bar x)(x + \bar y) = 1\cdot(x + \bar y) = x + \bar y$$

$x + \bar y$ bir maxtermdir. Yalnız iki değişken düşünülürse $x = 0, y = 1$ girişinde 0 olduğundan $M_1$'e karşılık gelir. Ama $z$ de bir giriştir; doğruluk tablosunda bu terim, $z$ ne olursa olsun iki satırı kapsar. POM'a geçmek için $z$ de eklenmelidir.

SOM'da eksik değişken $(v + \bar v) = 1$ ile çarpılıyordu, çünkü 1 VE'de etkisiz elemandır. Burada tersi yapılır: $z\bar z = 0$ terimi VEYA ile eklenir, çünkü 0 VEYA'da etkisizdir. Sonra dağıtılır:

$$x + \bar y + z\bar z = (x + \bar y + z)(x + \bar y + \bar z)$$

Maxtermler 0'ı hedefler. $x + \bar y + z$, $010$ girişinde 0 olur, yani $M_2$; $x + \bar y + \bar z$, $011$ girişinde 0 olur, yani $M_3$. Sonuç:

$$f = M_2 \cdot M_3$$

Python kontrolü: $f$'nin üç değişkenli mintermleri 0, 1, 4, 5, 6, 7; eksik indeksler 2 ve 3'tür.

### 8.2 Örnek: $f(A,B,C) = A\bar C + BC + \bar A\bar B$

Hoca bu örneğin minterm ile maxterm arasındaki farkı iyi gösterdiğini söyler ve önce SOM'unu yazar (ifade slayttan, ekrandan, 01:15:00). Eksik değişkenler eklenir: $A\bar C(B + \bar B)$, $BC(A + \bar A)$, $\bar A\bar B(C + \bar C)$. Dağıtılınca:

$$AB\bar C + A\bar B\bar C + ABC + \bar A BC + \bar A\bar B C + \bar A\bar B\bar C$$

Tekrar yoktur. İndeksler 6, 4, 7, 3, 1, 0'dır; sıralanınca:

$$f(A,B,C) = \Sigma m(0, 1, 3, 4, 6, 7)$$

İstenen ise POM'dur. Bir öğrencinin belirttiği gibi 0-7 arasında eksik olan indeksler 2 ve 5'tir; mintermlerin tümleyeni maxtermleri verdiği için sonuç $M_2 \cdot M_5$ olmalıdır. Hoca bunun nasıl elde edildiğini, sonuca nasıl ulaşıldığını görmek ister.

> **Ders sonrası not:** Hoca bir yerde maxterm indekslerini "0, 1, 2 ve 5" diye söyledi; doğrusu yalnız 2 ve 5'tir. Minterm indeksleri 0, 1, 3, 4, 6, 7 olduğundan 0 ve 1 maxterm olamaz (python ile doğrulandı).

> **Hocanın vurgusu:** $A + BC = (A + B)(A + C)$ dağılma biçimini öğrenciler hep unutuyor; maxterm işlemlerinde en çok kullanılacak dağıtım budur.

**Birinci yol: çift tümleyen (bir öğrencinin çözümü).** Tahtada bir öğrenci şu yolu izler (ekrandan, 01:25:00). Bir fonksiyon tümleyeninin tümleyenine eşittir: $f = \overline{\overline{f}}$. Bu kural kanonik formlar arasında geçiş için kullanılabilir, çünkü De Morgan ile $\overline{A + B} = \bar A\,\bar B$ olur; yani VEYA'dan VE'ye, maxterm biçiminden minterm biçimine geçilir.

1. İçteki tümleyen De Morgan ile dağıtılır: $\bar f = \overline{A\bar C + BC + \bar A\bar B} = (\bar A + C)(\bar B + \bar C)(A + B)$.
2. İlk iki çarpan açılır: $(\bar A\bar B + \bar A\bar C + C\bar B)(A + B)$ ($C\bar C = 0$ düşer).
3. Kalan çarpımla açılır: $\bar A\bar B A$, $\bar A\bar B B$, $\bar A\bar C A$ ve $C\bar B B$ terimleri $X\bar X = 0$ kuralıyla düşer; geriye $\bar A B\bar C + A\bar B C$ kalır.
4. Dıştaki tümleyen yeniden dağıtılır: $f = \overline{\bar A B\bar C + A\bar B C} = (A + \bar B + C)(\bar A + B + \bar C)$.

Bu, $M_2 \cdot M_5$'tir.

**İkinci yol: slayttaki dağılma kuralı.** Hocanın gösterdiği yaklaşımda De Morgan kullanılmaz (ekrandan, 01:30:00):

1. $x + yz = (x + y)(x + z)$ kuralı $x = A\bar C + BC$, $y = \bar A$, $z = \bar B$ ile uygulanır: $f = (A\bar C + BC + \bar A)(A\bar C + BC + \bar B)$.
2. $x + \bar x y = x + y$ kuralı kullanılır: ilk çarpanda $\bar A$, $A\bar C$'deki $A$'yı götürür ve $\bar C$ kalır; ikinci çarpanda $\bar B$, $BC$'deki $B$'yi götürür ve $C$ kalır: $f = (\bar C + BC + \bar A)(A\bar C + C + \bar B)$.
3. Aynı kural ikinci kez uygulanır: ilk çarpanda $\bar C$, $BC$'deki $C$'yi; ikinci çarpanda $C$, $A\bar C$'deki $\bar C$'yi götürür: $f = (\bar C + B + \bar A)(A + C + \bar B)$.
4. Standart sıraya dizilir: $f = (\bar A + B + \bar C)(A + \bar B + C) = M_5 \cdot M_2$.

İki yol da aynı sonuca ulaşır. Hoca, minterm gösterimindeki indekslerin tümleyeni olan indekslerin maxterm gösterimini verdiğini yeniden hatırlatır.

## 9. Karışık gösterimler ve sadeleştirmenin önemi

SOP (çarpımların toplamı) ve POS (toplamların çarpımı) dışında karışık gösterimler de vardır: bir kısmı toplamların çarpımı, bir kısmı çarpımların toplamı gibi görünen, ne SOP ne POS denebilecek ifadeler. Bunlar da önce SOP ya da POS biçimine getirilip sonra çözülür. Ardından Boole cebriyle ya da Karnaugh haritalarıyla sadeleştirilerek aynı devre daha az kapıyla tasarlanır.

Hoca örnek olarak mintermleri 1, 4, 5, 6, 7 olan fonksiyonu ele alır. Bu ham haliyle tasarlamanın anlamı yoktur. Örneğin $AB\bar C$ ve $ABC$ terimlerine bakınca $C$'den bağımsız olarak $A = B = 1$ iken çıkışın 1 olduğu görülür; burada $C$'nin etkisi yoktur. Doğrudan gerçekleştirilirse hocanın sayımına göre 6 DEĞİL, 10 VE ve 4 VEYA kapısı gerekir. <!-- BELİRSİZ: bu sayım büyük olasılıkla iki girişli kapılar ve her tümlenmiş değişken için ayrı DEĞİL kapısı varsayımıyla yapıldı --> Sadeleşmiş hali $A + \bar B C$ ise bir DEĞİL, bir VE ve bir VEYA kapısıyla kurulur.

Soldaki (kanonik) gösterim yine de önemlidir: kanonik formlar arasında geçiş yapılarak farklı sadeleştirmelerle farklı kapı yapıları elde edilebilir; ayrıca aynı fonksiyonu veren farklı sadeleşmiş yapıları kıyaslamak için en açık gösterim budur. Sadeleşmiş $A + \bar B C$ ise artık kanonik bir SOM değildir.

Slaytta bu bölümün sonucu şöyle verilir (ekrandan, 01:35:00):

- Kanonik formlar (mintermlerin toplamı, maxtermlerin çarpımı) ve diğer standart formlar (SOP, POS) karmaşıklık bakımından farklıdır.
- Boole cebri, denklemleri daha basit biçimlere getirmek için kullanılabilir.
- Daha basit denklemler, daha basit iki seviyeli gerçekleştirmelere yol açar.
- Açık sorular: "En basit" ifadeye nasıl ulaşılır? Tek bir minimum maliyetli devre mi vardır?

> **Ek bilgi (derste anlatılmadı):** POM için de SOM'daki $\Sigma m(\dots)$ gösterimine benzer bir kısa gösterim kullanılır: $\Pi M(\dots)$. Örneğin bu derste bulunan sonuç $f(A,B,C) = \Pi M(2, 5)$ biçiminde yazılır. Aynı fonksiyonun SOM ve POM indeksleri birlikte $0, \dots, 2^n - 1$ aralığının tamamını, örtüşmeden kapsar.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): $\bar A\bar B\bar C + A(C\bar D + \bar B)$ ifadesini sadeleştirin.

> **Çözüm:** $\bar A\bar B\bar C + AC\bar D + A\bar B = \bar B(\bar A\bar C + A) + AC\bar D = \bar B(A + \bar C) + AC\bar D = \bar B A + \bar C\bar B + AC\bar D$ (ekrandan, 00:15:00).

**Soru 2** (ekrandan, 00:15:00): $(\bar A + ABC)(A + \bar C)$ ifadesini sadeleştirin.

> **Çözüm:** $\bar A + ABC = \bar A + BC$ olduğundan $(\bar A + BC)(A + \bar C) = \bar A A + \bar A\bar C + ABC + BC\bar C = \bar A\bar C + ABC$. (Derste bir öğrenci tahtada çözdü ve hoca doğru buldu; son satır karelerde görünmediği için sonuç python ile doğrulandı.)

**Soru 3** (derste sözlü, 00:35:43): $X, Y, Z$ değişkenleri için minterm 6 ve maxterm 6'yı yazın.

> **Çözüm:** $6 = 110$; $m_6 = XY\bar Z$, $M_6 = \bar X + \bar Y + Z$.

**Soru 4** (ekrandan, 00:40:00): $F_1 = m_1 + m_4 + m_7$ fonksiyonunu açık biçimde yazın.

> **Çözüm:** $F_1 = \bar x\bar y z + x\bar y\bar z + xyz$.

**Soru 5** (ekrandan, 00:45:00): $F_1 = M_0 \cdot M_2 \cdot M_3 \cdot M_5 \cdot M_6$ fonksiyonunu maxtermlerle gerçekleştirin.

> **Çözüm:** $F_1 = (x+y+z)(x+\bar y+z)(x+\bar y+\bar z)(\bar x+y+\bar z)(\bar x+\bar y+z)$.

**Soru 6** (ekrandan, 00:50:00): $F(A,B,C,D) = M_3 \cdot M_8 \cdot M_{11} \cdot M_{14}$ fonksiyonunu açık biçimde yazın.

> **Çözüm:** $F = (A+B+\bar C+\bar D)(\bar A+B+C+D)(\bar A+B+\bar C+\bar D)(\bar A+\bar B+\bar C+D)$. (Son çarpan derste tahtaya yazılmadı; ikilik açılımla tamamlandı.)

**Soru 7** (ekrandan, 01:00:00): $f = x + \bar x\bar y$ fonksiyonunu mintermlerin toplamı olarak yazın.

> **Çözüm:** $f = x(y+\bar y) + \bar x\bar y = xy + x\bar y + \bar x\bar y = m_3 + m_2 + m_0$.

**Soru 8** (ekrandan, 01:05:00): $F = A + \bar B C$ fonksiyonunun mintermlerin toplamı gösterimini bulun.

> **Çözüm:** $A(B+\bar B)(C+\bar C) + (A+\bar A)\bar B C$ açılıp tekrar atılınca $F(A,B,C) = \Sigma m(1, 4, 5, 6, 7)$.

**Soru 9** (ekrandan, 01:10:00): $f(x,y,z) = x + \bar x\bar y$ fonksiyonunu maxtermlerin çarpımına çevirin.

> **Çözüm:** $x + \bar x\bar y = x + \bar y = x + \bar y + z\bar z = (x+\bar y+z)(x+\bar y+\bar z) = M_2 \cdot M_3$.

**Soru 10** (ekrandan, 01:15:00): $f(A,B,C) = A\bar C + BC + \bar A\bar B$ fonksiyonunu maxtermlerin çarpımına çevirin.

> **Çözüm:** SOM: $\Sigma m(0,1,3,4,6,7)$. Dağılma kuralıyla: $f = (A\bar C + BC + \bar A)(A\bar C + BC + \bar B) = (\bar C + B + \bar A)(A + C + \bar B) = (\bar A + B + \bar C)(A + \bar B + C) = M_5 \cdot M_2$ (ekrandan, 01:30:00).

## Dersin Toparlaması

Bu derste Boole cebriyle sadeleştirme iki örnekle tekrarlandıktan sonra kanonik formlara geçildi. Minterm, her değişkeni içeren ve doğruluk tablosunda $F = 1$ olan bir satırı temsil eden VE terimi; maxterm ise $F = 0$ olan bir satırı temsil eden VEYA terimidir. İndeks gösterimiyle $m_i$ ve $M_i$ kısa yazılır ve De Morgan ile birbirinin tümleyenidir. Herhangi bir fonksiyon, eksik değişkenler $(v + \bar v)$ ile çarpılarak mintermlerin toplamına (SOM, $\Sigma m$), ikinci dağılma kuralı ve $v\bar v$ eklenerek maxtermlerin çarpımına (POM) dönüştürülebilir. Bir fonksiyonun maxterm indeksleri, minterm indekslerinde bulunmayanlardır.

Kanonik formlar fonksiyonları karşılaştırmak ve doğruluk tablosuyla birebir eşlemek için en açık gösterimdir, ama doğrudan gerçekleştirildiklerinde çok kapı gerektirir. Bir sonraki derste bu ifadeleri daha sade hale getirmek ve minimum devreye ulaşmak için Karnaugh haritaları işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
