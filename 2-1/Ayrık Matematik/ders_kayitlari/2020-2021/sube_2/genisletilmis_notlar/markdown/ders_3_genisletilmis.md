# Ders 3 Genişletilmiş Notu: Boole Cebri ve Karnaugh Haritaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Mantıktan Bool Cebrine
- 2. Bool İfadeleri ve Bool Fonksiyonları
- 3. Bool Cebrinin Özdeşlikleri
- 4. Doğruluk Tablosundan Bool İfadesine
- 5. Derste Eklenen Kurallar: x + x'y ve XOR/XNOR
- 6. Mantık Kapıları ve Devreler
- 7. Karnaugh Haritalarına Giriş
- 8. Dört Değişkenli Karnaugh Haritası Örnekleri
- 9. Senaryodan Devreye: Not Ağırlıklarıyla Geçme Devresi
- Örnek Sorular
- Dersin Toparlaması

## 1. Mantıktan Bool Cebrine

Önceki haftalarda mantık (logic) ve ispat konuları bitirildi. Bu derste mantığın bilgisayar donanımındaki uygulaması işlendi: Bool cebri (slaytta "Boole Cebri", ekrandan, 00:15:00).

Hoca konuyu şöyle bağladı: En küçüğünden en büyüğüne bütün bilgisayar sistemlerinde bilgi 0 ve 1'lerle saklanır. Veri işlenir, komutlar çözülür (decode edilir) ve gereği yapılır. Bunların arkasındaki toplama, çıkarma gibi temel işlemler hafıza birimleri ve mantık kapılarıyla kurulur. Bu yapıların ayrıntısı bilgisayar organizasyonu ve mimarisi derslerinde anlatılır; temelinde ise mantık kuralları çalışır. Bu derste Bool fonksiyonları, gösterimleri, kapılar ve Karnaugh haritaları ele alındı.

Bool cebri 0 ve 1 üzerinde üç temel işlemle çalışır:

- **Bool toplamı** ($+$): mantıktaki "veya"ya (OR) karşılık gelir. $1+1=1$, $1+0=1$, $0+1=1$, $0+0=0$.
- **Bool çarpımı** ($\cdot$): "ve"ye (AND) karşılık gelir. $1\cdot 1=1$, diğer bütün durumlarda sonuç 0'dır.
- **Tümleyen** (complement, $\overline{x}$): "değil"e (NOT) karşılık gelir. $\overline{0}=1$, $\overline{1}=0$.

Hoca toplamayı bir OR kapısı gibi düşünmemizi istedi: doğru ile doğrunun "veya"sı doğrudur, bu yüzden $1+1=1$'dir.

### 1.1 İlk Örnek

Slayttaki örnek (ekrandan, 01:25:00): $1\cdot 0+\overline{(0+1)}$ değeri nedir?

- $1\cdot 0 = 0$.
- $0+1=1$, tümleyeni $\overline{1}=0$.
- $0+0=0$. Sonuç: $0$.

## 2. Bool İfadeleri ve Bool Fonksiyonları

### 2.1 Tanımlar

$B=\{0,1\}$ olsun. $B^n=\{(x_1,x_2,\dots,x_n) \mid x_i\in B,\ 1\le i\le n\}$ kümesi, 0 ve 1'lerden oluşan $n$ uzunluğundaki dizilerdir. Bir değişken yalnız $B$'den değer alıyorsa ona **Bool değişkeni** denir. $B^n$'den $B$'ye bir fonksiyon **$n$. dereceden Bool fonksiyonudur**. Yani bir Bool fonksiyonunun girdisini 0 ve 1'lerden oluşan bir dizi (string) olarak düşünürüz.

### 2.2 Doğruluk Tablosuyla Fonksiyonun Değeri

Örnek (ekrandan, 00:20:00): $F(x,y,z)=xy+\overline{z}$ fonksiyonunun değerleri nedir?

Kaç girdi varsa bütün durumlar için bir doğruluk tablosu yapılır. Ara sütunlar olarak $xy$ ve $\overline{z}$ yazılır, sonra toplanır:

| $x$ | $y$ | $z$ | $xy$ | $\overline{z}$ | $F=xy+\overline{z}$ |
|---|---|---|---|---|---|
| 1 | 1 | 1 | 1 | 0 | 1 |
| 1 | 1 | 0 | 1 | 1 | 1 |
| 1 | 0 | 1 | 0 | 0 | 0 |
| 1 | 0 | 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 1 | 1 |
| 0 | 0 | 1 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 1 | 1 |

$xy$, yalnız $x$ ve $y$ ikisi de 1 iken 1'dir. $\overline{z}$ sütunu $z$ sütununun tersidir. Hoca kitabın tabloyu 1'lerden başlayıp geriye doğru yazdığını, kendisinin genelde 000'dan başladığını söyledi; ikisi de olur.

**Mantık devresi.** Soruda önce devrenin genel şeması istenebilir: üç girişli, tek çıkışlı bir kutu (girişe "3", çıkışa "1" yazılır). Devrenin kendisi şöyledir (ekrandan, 00:25:00):

```text
x ──┐
    AND ── xy ──┐
y ──┘           OR ── F = xy + z'
z ── NOT ── z' ─┘
```

Bunu bir mantık devresi simülatöründe kurup örneğin $x=0$, $y=1$, $z=1$ verirseniz çıkışın 0 olduğunu görürsünüz.

### 2.3 Ters Yön: Tablodan Fonksiyona

Sınavda fonksiyon her zaman hazır verilmez. Doğruluk tablosu ya da bir senaryo verilir. Hoca bir örnek senaryo anlattı: bir öğrencinin iki vize ve final notu üç değişken olsun; belli toplamların sağlandığı durumlarda çıkış 1, diğerlerinde 0 olsun. Senaryodan önce girdi sayısı, sonra her durumun çıkışı bulunur.

Tablodan fonksiyon bulmak için 1 olan satırlara bakılır. Yukarıdaki tabloda $F$ şu satırlarda 1'dir (ekrandan, 00:25:00):

$$F = xyz + xy\overline{z} + x\overline{y}\,\overline{z} + \overline{x}y\overline{z} + \overline{x}\,\overline{y}\,\overline{z}$$

Hoca tümleyeni gösterirken değişkenin üstüne çizgi ya da sağına kesme işareti ($x'$) koyduklarını, öne tilda koymadıklarını belirtti. Sonra sadeleştirmeye başladı:

- $xyz+xy\overline{z}=xy(z+\overline{z})=xy$.
- $x\overline{y}\,\overline{z}+\overline{x}\,\overline{y}\,\overline{z}=\overline{y}\,\overline{z}(x+\overline{x})=\overline{y}\,\overline{z}$.
- Geriye $\overline{x}y\overline{z}$ kalır.

Hoca $\overline{z}$ parantezine almayı da denedi ve kuralları tam göstermeden en sade hali yakalamanın zor olduğunu söyledi. Hedef yine $xy+\overline{z}$'ye ulaşmaktır. (ara adım eklendi) $\overline{y}\,\overline{z}+\overline{x}y\overline{z}=\overline{z}(\overline{y}+\overline{x}y)=\overline{z}(\overline{y}+\overline{x})$ olur ve $xy+\overline{z}(\overline{x}+\overline{y})=xy+\overline{z}\,\overline{(xy)}=xy+\overline{z}$ bulunur. Son adım, aşağıda 5. bölümde göreceğimiz $a+\overline{a}b=a+b$ kuralıdır ($a=xy$, $b=\overline{z}$). Beş terimin toplamının $xy+\overline{z}$'ye eşit olduğu python ile de doğrulandı.

### 2.4 Bool Fonksiyonlarının Eşitliği ve İşlemleri

$n$ değişkenli iki Bool fonksiyonu $F$ ve $G$, her $(b_1,\dots,b_n)$ için $F(b_1,\dots,b_n)=G(b_1,\dots,b_n)$ ise eşittir. Örneğin $xy$, $xy+0$ ve $xy\cdot 1$ denk ifadelerdir: bir fonksiyona 0 eklemek ya da onu 1 ile çarpmak hiçbir şeyi değiştirmez.

İki fonksiyonun toplamı ve çarpımı nokta nokta tanımlanır: $(F+G)(x)=F(x)+G(x)$, $(FG)(x)=F(x)G(x)$. Örneğin $F=x+y$ ve $G=z$ ise $FG=(x+y)z=xz+yz$; parantez, dağılma özelliğiyle açılır.

### 2.5 Kaç Farklı Bool Fonksiyonu Vardır?

Slayttaki örnek (ekrandan, 00:30:00): $n$'nin değerine göre kaç farklı Bool fonksiyonu vardır?

Saymanın temel ilkelerinden çarpma ilkesine göre 0 ve 1'den oluşan farklı $n$'lik dizilerin sayısı $2^n$'dir. Her diziye 0 ya da 1 atanabildiğinden $n$. dereceden $2^{2^n}$ farklı Bool fonksiyonu vardır. Bu, $2^n$ elemanlı bir kümenin alt küme (kuvvet kümesi) sayısıyla aynıdır.

| Derece $n$ | Fonksiyon sayısı |
|---|---|
| 1 | 4 |
| 2 | 16 |
| 3 | 256 |
| 4 | 65.536 |
| 5 | 4.294.967.296 |
| 6 | 18.446.744.073.709.551.616 |

> **Hocanın vurgusu:** Bu önemlidir. Örneğin 5 değişken varsa $2^5=32$ farklı girdi durumu ve bunlardan $2^{32}$ farklı Bool fonksiyonu vardır.

İkinci dereceden bir Bool fonksiyonunun tanım kümesi 4 farklı ikiliden (11, 10, 01, 00) oluşur, değer kümesi $B=\{0,1\}$'dir. Bu yüzden $2^4=16$ farklı ikinci dereceden Bool fonksiyonu vardır. Slayttaki tablo bu 16 fonksiyonu $F_1,\dots,F_{16}$ olarak listeler: $F_1$ dört durumda da 1, $F_{16}$ dört durumda da 0'dır; aradakiler 4 bitlik bütün diğer çıkış dizileridir (ekrandan, 00:30:00).

Tablonun sayıları python ile doğrulandı.

## 3. Bool Cebrinin Özdeşlikleri

Özdeşlikler devre tasarımlarının sadeleştirilmesinde kullanılır. Slayttaki tablo (ekrandan, 00:35:00):

| Özdeşlik | Adı |
|---|---|
| $\overline{\overline{x}}=x$ | Çift tümleyen (double complement) |
| $x+x=x$, $x\cdot x=x$ | Eş kuvvetlilik (idempotent) |
| $x+0=x$, $x\cdot 1=x$ | Birim (identity) |
| $x+1=1$, $x\cdot 0=0$ | Baskınlık (domination) |
| $x+y=y+x$, $xy=yx$ | Değişme (commutative) |
| $x+(y+z)=(x+y)+z$, $x(yz)=(xy)z$ | Birleşme (associative) |
| $x+yz=(x+y)(x+z)$, $x(y+z)=xy+xz$ | Dağılma (distributive) |
| $\overline{(xy)}=\overline{x}+\overline{y}$, $\overline{(x+y)}=\overline{x}\,\overline{y}$ | De Morgan |
| $x+xy=x$, $x(x+y)=x$ | Yutma (absorption) |
| $x+\overline{x}=1$ | Birim özelliği (unit property) |
| $x\overline{x}=0$ | Sıfır özelliği (zero property) |

Hoca kuralları tek tek yorumladı:

- İlk dört satır en temel ve en çok kullanılan kurallardır. 0 ile toplamayı ve 1 ile çarpmayı "birim eleman" gibi düşünebilirsiniz.
- **Değişme ve birleşme:** Programlamadaki operatörler gibi düşünün. Aynı öncelikteki operatörler yan yana ise parantezin anlamı kalmaz; önce $x+y$ yapılıp sonra $z$ ile toplanabilir.
- **De Morgan:** Bir ifadenin değili alınırken içindeki her eleman tersine döner ve işlemler yer değiştirir: çarpma toplamaya (AND → OR), toplama çarpmaya (OR → AND) döner. Bu kural programdaki `if` koşullarını da etkiler.
- **Yutma:** $x+xy$ ifadesinde $x$ parantezine alınırsa $x(1+y)$ gelir; $1+y=1$ olduğundan sonuç $x$'tir. İkinci biçim: $x(x+y)=xx+xy=x+xy=x$.
- **Birim ve sıfır özelliği:** Bir şeyle değilinin toplamı 1, çarpımı 0'dır.

### 3.1 De Morgan'ın Program Koşulunda Kullanımı

Hoca ekrana bir program koşulu yazdı ve öğrencilerden De Morgan ile dönüştürmelerini istedi (ekrandan, 00:35:00):

$$(d<20) \;\&\&\; (c>40)$$

Bu koşulun değili için her karşılaştırmanın tersi alınır ve aradaki operatör de tersine döner: $d<20$'nin tersi $d\ge 20$, $c>40$'ın tersi $c\le 40$, "ve" ise "veya" olur:

$$\overline{(d<20)\land(c>40)} \equiv (d\ge 20)\lor(c\le 40)$$

Öğrencilerden gelen cevap da bu yöndeydi. Hoca, sınır değeri 40'ı da kapsamak istediğimizde eşitliğin hangi tarafa yazılacağına dikkat edilmesi gerektiğini söyledi. <!-- BELİRSİZ: d ve c değişkenlerinin anlamı altyazıda tam anlaşılmıyor; devam ve not benzeri bir geçme koşulu örneği olduğu anlaşılıyor. -->

### 3.2 Özdeşliği Doğruluk Tablosuyla Kanıtlama

Slayttaki örnek (ekrandan, 00:35:00): $x(y+z)=xy+xz$ doğru mudur?

Üç değişkenli bir doğruluk tablosu kurulur. Ara sütunlar ($y+z$, $xy$, $xz$) isteğe bağlıdır, doğrudan da yazılabilir.

| $x$ | $y$ | $z$ | $y+z$ | $xy$ | $xz$ | $x(y+z)$ | $xy+xz$ |
|---|---|---|---|---|---|---|---|
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 0 | 1 | 1 | 0 | 1 | 1 |
| 1 | 0 | 1 | 1 | 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 1 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

Son iki sütun bütün satırlarda birebir aynı olduğu için eşitlik doğrudur. Bu, önceki haftalardaki mantıksal denkliğin (logical equivalence) Bool cebrindeki karşılığıdır. Değişken sayısı arttığında da dağılma ve birleşme kuralları aynı biçimde uygulanır.

## 4. Doğruluk Tablosundan Bool İfadesine

### 4.1 Tablodaki F ve G Fonksiyonları

Slayttaki örnek (ekrandan, 00:40:00): Tabloda verilen $F(x,y,z)$ ve $G(x,y,z)$ fonksiyonlarını tanımlayan Bool ifadelerini bulunuz.

| $x$ | $y$ | $z$ | $F$ | $G$ |
|---|---|---|---|---|
| 1 | 1 | 1 | 0 | 0 |
| 1 | 1 | 0 | 0 | 1 |
| 1 | 0 | 1 | 1 | 0 |
| 1 | 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 | 0 |
| 0 | 1 | 0 | 0 | 1 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |

$F$ yalnız $x=z=1$ ve $y=0$ iken 1'dir; bu yüzden $F(x,y,z)=x\overline{y}z$.

$G$ iki satırda 1'dir: $x=1, y=1, z=0$ ve $x=0, y=1, z=0$. Bu yüzden $G=xy\overline{z}+\overline{x}y\overline{z}$.

**Soru:** Bir terimi yazarken değişkenlerin arasına neden çarpım koyuyoruz? **Cevap:** (Bir öğrencinin cevabı) Çünkü $x$, $y$ ve $z$ bu değerleri aynı anda almıştır; yani "ve" ile bağlıdırlar. Hoca bunu onayladı: $G$'nin ilk 1 olması için $x=1$ **ve** $y=1$ **ve** $z=0$ olmalıdır. İki ayrı satır ise "ya bu ya şu" anlamına geldiğinden terimler arasında "veya", yani toplam vardır.

Sonra sadeleştirme:

$$G = y\overline{z}(x+\overline{x}) = y\overline{z}\cdot 1 = y\overline{z}$$

Yani $G$ için $x$'in 0 ya da 1 olması bir anlam taşımaz; çıkışı $y$ ve $z$ belirler. Devresi: $z$ bir NOT kapısından geçer, $y$ ile birlikte bir AND kapısına girer.

> **Hocanın vurgusu:** İfadeyi bulmakla kalmayıp sadeleştirebildiğimiz kadar sadeleştiririz. Çünkü bu ifadeler devre olacak; devre fiziksel alan ve güç kaybı demektir. Bunları en aza indirmek isteriz.

### 4.2 Çarpımların Toplamı (SOP) ve Mintermler

Yukarıdaki yazım biçimine **çarpımların toplamı** (sum of products, SOP form) denir; mintermlerle gösterim de denir. Bir değişkene ya da tümleyenine **öge** (literal) denir. Ögeler çarpım terimleri halinde yazılır ve terimler toplanır. Hoca bu biçimin günlük hayatta ve mantıkta en çok kullandığımız biçim olduğunu, diğer biçimin de toplamların çarpımı (product of sums) olduğunu ve onun mantık devreleri dersinde gösterildiğini söyledi.

### 4.3 $(x+y)\overline{z}$ Fonksiyonunun Açılımı

Slayttaki örnek (ekrandan, 00:45:00): $F(x,y,z)=(x+y)\overline{z}$ fonksiyonu için açılımı bulunuz.

**Çözüm 1 (doğruluk tablosu):** $x+y$ ve $\overline{z}$ sütunları çarpılır. Fonksiyon 110, 100 ve 010 satırlarında 1'dir:

$$F(x,y,z)=xy\overline{z}+x\overline{y}\,\overline{z}+\overline{x}y\overline{z}$$

**Çözüm 2 (özdeşliklerle):** Eksik değişkeni olan terim, o değişkenle değilinin toplamı (yani 1) ile çarpılarak genişletilir:

$$\begin{aligned}
F &= (x+y)\overline{z} \\
&= x\overline{z}+y\overline{z} && \text{dağılma} \\
&= x\,1\,\overline{z}+1\,y\overline{z} && \text{özdeşlik} \\
&= x(y+\overline{y})\overline{z}+(x+\overline{x})y\overline{z} && \text{birim özelliği} \\
&= xy\overline{z}+x\overline{y}\,\overline{z}+xy\overline{z}+\overline{x}y\overline{z} && \text{dağılma} \\
&= xy\overline{z}+x\overline{y}\,\overline{z}+\overline{x}y\overline{z} && \text{eş kuvvetlilik ve değişme}
\end{aligned}$$

Hoca slaytta dağılma satırındaki son terimin $\overline{x}\,\overline{z}$ diye yazıldığını, burada bir $y$'nin unutulduğunu söyledi; doğrusu $\overline{x}y\overline{z}$'dir. Birinci ve üçüncü terim aynı olduğu için biri silinir (ekrandan, 00:50:00). İki çözüm aynı sonucu verir. Genişletilmiş biçim doğrudur ama devre için en sade biçim olan $(x+y)\overline{z}$ tercih edilir.

> **Ders sonrası not:** Slayttaki soru "toplamların çarpımı açılımı" diyor, ama iki çözümde de bulunan sonuç bir çarpımların toplamıdır (sum-of-products expansion). Büyük olasılıkla kaynak kitaptaki ifade çevrilirken karışmıştır.

## 5. Derste Eklenen Kurallar: x + x'y ve XOR/XNOR

### 5.1 $x+\overline{x}y=x+y$

Hoca slaytta olmayan bir kuralı ekledi ve öğrencilere sonucun ne olduğunu sordu. Gelen cevaplar arasında $x$, $y$ ve $x+y$ vardı; doğrusu $x+y$'dir. Türetme (ekrandan, 01:00:00):

$$\begin{aligned}
x+\overline{x}y &= x\cdot 1+\overline{x}y \\
&= x(1+y)+\overline{x}y && (1+y=1) \\
&= x+xy+\overline{x}y \\
&= x+y(x+\overline{x}) \\
&= x+y
\end{aligned}$$

Hoca ilk denemesinde 1 yerine $y+\overline{y}$ yazdı; bunun ifadeyi başa döndürdüğünü görüp yöntemi değiştirdi. Önemli olan, $\overline{x}$'in yanındaki ifadeyi kullanarak $x$'i $1+y$ ile çarpmaktır.

> **Hocanın vurgusu:** Bu çok kullanışlı bir kuraldır, örneklerde karşınıza çok çıkar. $x$ ile bir şeyin değili çarpı başka bir şey toplanınca aradaki değil gider ve $x+y$ bulunur.

**Soru:** $x$'i $\overline{x}y$ teriminin içine dağıtmak daha doğru olmaz mı? **Cevap:** Burada çarpımların toplamı var; onu toplamların çarpımına çevirmek farklı bir ifade üretir, kendiliğinden sonuca götürmez. Bu yöntemde terim ekleyip çıkarmak gerekir. Diğer bir yol De Morgan'ı iki kez uygulamaktır: ifadenin iki kez değili alınır, böylece ifade kendi haline döner ama ara adımda biçim değişir. Hoca bunun da bir çıkış yolu olabileceğini, ama $1+y$ ile çarpmanın en rahat yol olduğunu söyledi.

Aranın ardından hoca benzer kuralı da gösterdi:

$$x(\overline{x}+y)=x\overline{x}+xy=0+xy=xy$$

Bu ikisi aynı fikrin toplama ve çarpma biçimleridir: değil olan değişken iki durumda da ortadan kalkar.

### 5.2 XOR ve XNOR

Hoca beyaz tahtada XOR (dışlayan veya) ve XNOR'un Bool ifadelerini yazdı (ekrandan, 00:55:00). XOR için:

$$x\oplus y=\overline{x}y+x\overline{y}$$

Hoca bu biçimin derslerde en çok kullanılan biçim olduğunu söyledi. XNOR için:

$$x\odot y=\overline{x}\,\overline{y}+xy$$

Tahtada ayrıca toplamların çarpımı biçimleri yazıldı ve açılarak kontrol edildi. Açılımda $x\overline{x}$ ve $y\overline{y}$ terimleri 0 olduğu için silinir. Hoca açılım sırasında bir hata olduğunu fark etti.

> **Ders sonrası not:** Tahtada $x\oplus y=(x+\overline{y})(\overline{x}+y)$ ve $x\odot y=(x+y)(\overline{x}+\overline{y})$ yazıldı; bu iki toplamların çarpımı biçimi yer değiştirmiştir. Tahtadaki açılım da bunu gösterir: $(x+\overline{y})(\overline{x}+y)=x\overline{x}+xy+\overline{x}\,\overline{y}+y\overline{y}=xy+\overline{x}\,\overline{y}$, yani XNOR. Doğrusu: $x\oplus y=(x+y)(\overline{x}+\overline{y})$ ve $x\odot y=(x+\overline{y})(\overline{x}+y)$. Dört eşitlik python ile doğrulandı.

## 6. Mantık Kapıları ve Devreler

### 6.1 Temel Kapılar

Teoride üç temel eleman vardır (ekrandan, 00:15:00):

- **Inverter (NOT):** 0'ı 1, 1'i 0 yapar. Çıkışı $\overline{A}$.
- **OR kapısı:** Çıkışı $A+B$.
- **AND kapısı:** Çıkışı $AB$.

Uygulamada OR'un ucuna bir değil eklenerek NOR, AND'in ucuna eklenerek NAND kapısı kurulur. Bunlara evrensel (universal, çok amaçlı) kapılar denir. XOR ve XNOR kapıları da vardır. OR ve AND kapılarının iki girişli olması gerekmez; çok girişli de yapılabilir.

Bir değişken birden fazla yerde gerekiyorsa tekrar yazmak yerine aynı hattan bir kol alınıp diğer kapıya bağlanabilir; değili gerekiyorsa koldan bir NOT kapısına girilir. Devrenin çıkışında, doğruluk tablosundaki değerlerin aynısı görülür.

### 6.2 İfadelerden Devre Çizme

Slayttaki örnek (ekrandan, 01:05:00): Aşağıdaki ifadeleri mantık kapıları ile tasarlayınız.

**(a)** $(x+y)\overline{x}$: Toplama bir OR kapısıdır, çarpma bir AND kapısıdır.

```text
x ──┐
    OR ── x+y ──┐
y ──┘           AND ── (x+y)x'
x ── NOT ── x' ─┘
```

**(b)** $\overline{x}\,\overline{(y+\overline{z})}$: $z$'nin önce değili alınır, $y$ ile toplanır, toplamın değili alınır, sonra $\overline{x}$ ile çarpılır.

```text
x ── NOT ── x' ──────────────────────┐
y ──────────┐                        AND ── x'(y+z')'
            OR ── y+z' ── NOT ───────┘
z ── NOT ───┘
```

**(c)** $(x+y+z)(\overline{x}\,\overline{y}\,\overline{z})$: Üç girişli bir OR kapısı ve üç girişli bir AND kapısı kullanılır, iki sonuç tekrar çarpılır.

```text
x,y,z ── OR (3 giriş) ── x+y+z ─────┐
x ── NOT ──┐                        AND ── (x+y+z)(x'y'z')
y ── NOT ──┼─ AND (3 giriş) ── x'y'z' ┘
z ── NOT ──┘
```

Hoca, (c)'de ifadenin tamamının değili istenseydi çıkışa bir NOT kapısı daha ekleneceğini söyledi.

### 6.3 Senaryo Soruları: Havuz Örneği

Hoca bu tür soruların genelde bir senaryo ile sorulduğunu söyledi ve sözlü bir örnek verdi: Bir havuzda farklı seviyelerde üç sensör olsun ($S_1$, $S_2$, $S_3$). Havuz boşken, %60'ı geçince ve %80'i geçince uyarı veren bir sistem için doğruluk tablosu kurulur. Üç sensörün $2^3=8$ farklı durumu vardır. Örneğin $S_3$ havuzun boş olduğunu gösteriyorsa, o durumda $S_1$ ve $S_2$'nin 0 olması beklenir. Tablodaki 1'lerden $F(S_1,S_2,S_3)$ fonksiyonu yazılır ve devresi çizilir. Önce üç girişli, tek çıkışlı devre şeması, sonra doğruluk tablosu, sonra en sade ifade ve devre istenir. <!-- BELİRSİZ: havuz örneğinin tablosu derste tamamlanmadı; sensörlerin hangi durumda 1 olduğu altyazıdan net çıkmıyor. -->

Önemli olan ifadenin en sade halinin bulunmasıdır. Bool cebri kuralları karmaşık ifadelerde bazen yetersiz kalır; o zaman farklı teknikler kullanılır.

### 6.4 Yarım Toplayıcı (Half Adder)

Slayttaki örnek (ekrandan, 01:10:00): İki bitlik yarım toplayıcı devresi. "Yarım" denmesinin sebebi, iki bit toplanınca toplamı tek çıkışla tam gösterememek ve elde için ayrı bir çıkışa ihtiyaç duymaktır.

| $x$ | $y$ | $s$ (toplam) | $c$ (elde) |
|---|---|---|---|
| 1 | 1 | 0 | 1 |
| 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 |
| 0 | 0 | 0 | 0 |

$1+1$ toplanınca sonuç 0, elde 1 olur; $1+0$ ve $0+1$'de sonuç 1; $0+0$'da sonuç 0'dır.

Toplam fonksiyonu tablodan doğrudan SOP olarak $s=\overline{x}y+x\overline{y}$ yazılabilir (hoca bunu tahtaya yazdı). Slayttaki devre ise başka bir biçim kullanır:

$$s=(x+y)\overline{(xy)}, \qquad c=xy$$

Devrede $x$ ve $y$ hem bir OR kapısına hem bir AND kapısına girer. AND çıkışı ($xy$) doğrudan elde çıkışıdır; aynı zamanda bir NOT kapısından geçip OR çıkışıyla birlikte ikinci bir AND kapısına girer ve toplamı verir. Bu iki biçimin denk olduğu (ikisinin de $x\oplus y$ olduğu) python ile doğrulandı. Yarım toplayıcılardan tam toplayıcılar kurulur; bu mantık devreleri dersinin konusudur.

## 7. Karnaugh Haritalarına Giriş

En sade ifadeyi bulmak için kullanılan tekniklerden biri Karnaugh haritalarıdır. Hoca bir diğer yöntem olarak Quine–McCluskey yönteminden de söz etti. Karnaugh haritaları iki, üç ve dört değişkende rahat kullanılır; beş ve altı değişkende de kullanılır ama zorlaşır.

### 7.1 Temel Fikir

Değişkenler bir ızgara (grid) üzerinde gösterilir. Fonksiyonun 1 olduğu hücreler işaretlenir, sonra komşu 1'ler gruplanır. Gruplama, ortak parantez almanın aynısıdır.

- Grup büyüklükleri $2^0, 2^1, 2^2, \dots$ yani 1, 2, 4, 8, 16'dır. Üçlü, altılı grup yoktur. En büyük grup haritanın boyutu kadardır.
- Grup içinde değeri **değişen** değişken yazılmaz; **değişmeyen** değişken yazılır. Değişmeyen değer 1 ise değişkenin kendisi, 0 ise değili yazılır.
- Strateji: önce en büyük grubu ara, bulamazsan bir küçüğüne in.

**Soru:** Değişen değişkeni yazmamamızın sebebi birbirini yok etmesi mi? **Cevap:** Evet. Aslında bu, ortak paranteze alınca $y+\overline{y}=1$ gibi terimlerin birbirini götürmesidir. Değişim varsa yazmıyoruz, değişim yoksa (değer sabitse) yazıyoruz.

### 7.2 İki Değişkenli Harita

Örnek (ekrandan, 01:15:00): $x$ satırda, $y$ sütunda. $x=0$ satırındaki iki hücre (00 ve 01) 1 olsun. Bu ikili grupta $x$ değişmez ve 0'dır, $y$ ise 0'dan 1'e değişir. Sonuç $\overline{x}$.

Bunu cebirle yaparsak: $\overline{x}\,\overline{y}+\overline{x}y=\overline{x}(y+\overline{y})=\overline{x}$. Harita, bu sadeleştirmeye gerek kalmadan sonucu verir.

### 7.3 Etiket Sırası

> **Hocanın vurgusu:** Önemli olan haritanın doğru çizilmesi. Öğrenciler genelde haritayı doğru çizmiyor, sorun buradan çıkıyor.

İki değişkenli bir eksen 00 ile başlar ve her adımda yalnız bir bit değişecek biçimde ilerler: 00, 01, 11, 10. Normal doğruluk tablosu ise ikilik sayma sırasıyla (00, 01, 10, 11) ilerler; orada 01'den 10'a geçerken iki bit birden değişir. Karnaugh haritasında böyle bir geçiş olmaz. Hoca bu iki sıralamanın sık karıştırıldığını söyledi.

### 7.4 Üç Değişkenli Harita

Örnek (ekrandan, 01:20:00): $x$ satırlarda (0, 1), $yz$ sütunlarda (00, 01, 11, 10). 1 olan hücreler:

```text
        yz=00  yz=01  yz=11  yz=10
x=0       .      .      1      .
x=1       1      1      .      1
```

Gruplama: 8'li grup yok; 4'lü grup da yok (yan yana dört 1 gerekir). İkililere bakılır:

- $x=1$ satırında 00–01 ikilisi: $x$ değişmez (1) → $x$; $y$ değişmez (0) → $\overline{y}$; $z$ değişir → yazılmaz. Terim: $x\overline{y}$.
- $x=1$ satırında 00 ile 10 hücresi: harita bir top gibi katlanınca sağ kenar sol kenarla birleşir, bu iki hücre komşudur. $x$ → $x$; $y$ değişir; $z$ değişmez (0) → $\overline{z}$. Terim: $x\overline{z}$.
- Açıkta kalan tek 1: $x=0$, $y=1$, $z=1$ → $\overline{x}yz$.

$$F=x\overline{y}+x\overline{z}+\overline{x}yz$$

Hoca, yalnız $x$ eksenine bakmanın yetmediğini, her grupta üç değişkenin de kontrol edilmesi gerektiğini hatırlattı. Sonuç python ile doğrulandı.

## 8. Dört Değişkenli Karnaugh Haritası Örnekleri

### 8.1 İlk Örnek: Köşeler ve Kenarlar

Hoca aradan önce $x,y$ satırda, $z,t$ sütunda olan dört değişkenli bir harita çizdi (ekrandan, 01:20:00). Kenardaki hücreler karşı kenardakilerle, dört köşe de birbiriyle gruplanabilir. 16'lı ve 8'li grup yoktu; dörtlülere bakıldı:

- Ortadaki dörtlü ($xy=01,11$ ve $zt=01,11$): $x$ değişir, $y$ sabit 1 → $y$; $z$ değişir, $t$ sabit 1 → $t$. Terim: $yt$.
- Dört köşe ($xy=00,10$ ve $zt=00,10$): $x$ değişir; bütün köşelerde $y=0$ → $\overline{y}$; $z$ değişir; $t=0$ → $\overline{t}$. Terim: $\overline{y}\,\overline{t}$.
- $xy=01$ satırında kalan iki hücre ($zt=00$ ve $10$): önce ikili alındı → $\overline{x}y\overline{t}$.

Sonra hoca bir şeyin atlandığını söyledi: bu ikili yerine $xy=01$ satırının dört hücresi birlikte dörtlü grup yapılabilir. Bir hücre birden fazla grupta yer alabilir. Bu dörtlüde $x=0$ ve $y=1$ sabit, $z$ ve $t$ değişir → $\overline{x}y$. Böylece daha basit bir ifade bulunur:

$$F=yt+\overline{y}\,\overline{t}+\overline{x}y$$

Grup ne kadar büyükse terim o kadar sadedir: iki dörtlüden iki harfli terimler, ikiliden üç harfli terim çıkar. <!-- BELİRSİZ: 01:20:00 karesinde köşelerden yalnız alt satırdakiler (xy=10) dolu görünüyor; üst köşelerin (xy=00) sonradan doldurulduğu altyazıdaki "bütün köşelerde y sıfır" anlatımından çıkarıldı. -->

### 8.2 Minterm Gösterimi: $\sum m(1,4,7,9)$

Aradan sonra hoca, Karnaugh sorularında sık gelen bir gösterimi anlattı (ekrandan, 02:10:00):

$$f=\sum(1,4,7,9)$$

Bu, fonksiyonun 1., 4., 7. ve 9. mintermlerin toplamı olduğu anlamına gelir. Buradan yorumlar çıkarılır:

- En büyük indis 9'dur. $2^3=8$ durumla yalnız 0–7 gösterilebildiği için en az 4 değişken gerekir. Harita 4 değişkenli ($4\times 4$) olacaktır.
- Devre şeması istenirse 4 girişli, tek çıkışlı bir devre çizilir.

Önce doğruluk tablosu kurulur. 16 satırın hepsini yazmak yerine yalnız 1 olan satırlar gösterildi (ekrandan, 02:20:00):

| Minterm | $abcd$ | $f$ |
|---|---|---|
| 1 | 0001 | 1 |
| 4 | 0100 | 1 |
| 7 | 0111 | 1 |
| 9 | 1001 | 1 |
| diğerleri | | 0 |

Haritaya aktarma ($ab$ satır, $cd$ sütun; ekrandan, 02:25:00):

```text
         cd=00  cd=01  cd=11  cd=10
ab=00      .      1      .      .
ab=01      1      .      1      .
ab=11      .      .      .      .
ab=10      .      1      .      .
```

16'lı, 8'li ve 4'lü grup çıkmaz. İkili grup: 0001 ile 1001 (aynı sütun, $ab=00$ ve $ab=10$ satırları; kenarlar komşudur). Çapraz grup olmaz. Geriye iki tekli grup kalır.

- Tek hücre 0100: hiçbir değişken değişmez → $\overline{a}b\overline{c}\,\overline{d}$.
- Tek hücre 0111: $\overline{a}bcd$.
- İkili (0001, 1001): $a$ değişir; $b=0$ → $\overline{b}$; $c=0$ → $\overline{c}$; $d=1$ → $d$. Terim: $\overline{b}\,\overline{c}d$.

$$f=\overline{a}b\overline{c}\,\overline{d}+\overline{a}bcd+\overline{b}\,\overline{c}d$$

Sonuç python ile doğrulandı. Hoca grup büyüklüğü ile terim uzunluğu arasındaki ilişkiyi de tahtaya yazdı (ekrandan, 02:25:00). Dört değişkenli bir haritada:

| Grup büyüklüğü | Terim | Örnek |
|---|---|---|
| 16 | 1 (bütün girişlerde çıkış 1) | — |
| 8 | tek harf | $a$ |
| 4 | iki harf | $ab$ |
| 2 | üç harf | $abc$ |
| 1 | dört harf | $abcd$ |

Hiç 1 yoksa çıkış her zaman 0'dır. Hoca bunu fiziksel olarak da yorumladı: 16'lı grupta çıkış sürekli 1 (örneğin 5 volt), hiç 1 yoksa sürekli 0 volt olur.

### 8.3 Köşe ve Kenar Gruplamalı Örnek

Hoca problemden bağımsız bir harita üzerinde gruplamaları gösterdi (ekrandan, 02:15:00 ve 02:20:00). $ab$ satır, $cd$ sütun:

```text
         cd=00  cd=01  cd=11  cd=10
ab=00      1      .      .      1
ab=01      .      1      1      .
ab=11      1      1      1      1
ab=10      1      .      .      1
```

8'li grup yoktur. Gruplar:

- **1. grup**, ortadaki dörtlü ($ab=01,11$; $cd=01,11$): $a$ değişir; $b$ sabit 1 → $b$; $c$ değişir; $d$ sabit 1 → $d$. Terim: $bd$.
- **2. grup**, dört köşe: $a$ değişir; $b$ sabit 0 → $\overline{b}$; $c$ değişir; $d$ sabit 0 → $\overline{d}$. Terim: $\overline{b}\,\overline{d}$.
- **3. grup**, $ab=11$ satırında açıkta kalan $cd=00$ ve $cd=10$ hücreleri. Bunlar ikili alınabilirdi, ama önce daha büyük grup aranır. İki seçenek vardır:
  - $ab=11$ satırının tamamı (yatay dörtlü): $a=1$, $b=1$ sabit; $c,d$ değişir → $ab$.
  - $ab=11$ ve $ab=10$ satırlarının $cd=00$ ve $cd=10$ hücreleri (kenardan dolanan dörtlü): $a$ sabit 1 → $a$; $b$ değişir; $c$ değişir; $d$ sabit 0 → $\overline{d}$. Terim: $a\overline{d}$.

$$f=bd+\overline{b}\,\overline{d}+a\overline{d} \quad\text{ya da}\quad f=bd+\overline{b}\,\overline{d}+ab$$

İki sonuç da doğrudur (python ile doğrulandı). Hoca, köşeleri $ab=00$ ve $ab=10$ satırlarında ikili ikili alıp birleştirmenin de mümkün olduğunu, ama o zaman bir ikilinin açıkta kalacağını söyledi; büyük grup tercih edilir.

### 8.4 Üç Gruplu Örnek

Örnek (ekrandan, 02:30:00):

```text
         cd=00  cd=01  cd=11  cd=10
ab=00      1      1      .      1
ab=01      .      .      .      .
ab=11      1      1      .      .
ab=10      .      .      .      1
```

Dörtlü grup yoktur, üç ikili grup vardır:

- **1. grup** ($ab=00$, $cd=00$–$01$): $a=0$, $b=0$, $c=0$ sabit; $d$ değişir → $\overline{a}\,\overline{b}\,\overline{c}$.
- **2. grup** ($ab=11$, $cd=00$–$01$): $a=1$, $b=1$, $c=0$ → $ab\overline{c}$.
- **3. grup** ($cd=10$ sütununda $ab=00$ ve $ab=10$; kenardan dolanan ikili): $a$ değişir; $b=0$, $c=1$, $d=0$ → $\overline{b}c\overline{d}$.

$$f=\overline{a}\,\overline{b}\,\overline{c}+ab\overline{c}+\overline{b}c\overline{d}$$

Hoca birinci grubu soru olarak sordu. Bir öğrenci "$ab$" dedi; hoca $a$ ve $b$'nin bu satırda 0 olduğunu, değeri 0 olan sabit değişkenin değili ile yazılacağını, bu yüzden $\overline{a}\,\overline{b}$ olacağını açıkladı. Çoğunluk doğru cevabı ($\overline{a}\,\overline{b}\,\overline{c}$) verdi. Sonuç python ile doğrulandı.

### 8.5 Sekizli Grup Örneği

Örnek (ekrandan, 02:30:00): $cd=01$ ve $cd=11$ sütunlarının tamamı 1, ayrıca $ab=10$ satırında $cd=00$ hücresi 1.

```text
         cd=00  cd=01  cd=11  cd=10
ab=00      .      1      1      .
ab=01      .      1      1      .
ab=11      .      1      1      .
ab=10      1      1      1      .
```

- Sekizli grup (iki orta sütun): $a$ ve $b$ değişir, $c$ değişir, yalnız $d$ sabit 1 → $d$.
- $ab=10$ satırında $cd=00$–$01$ ikilisi: $a=1$, $b=0$, $c=0$ → $a\overline{b}\,\overline{c}$.

$$f=d+a\overline{b}\,\overline{c}$$

**Soru:** Sekizli yerine iki dörtlü alamaz mıyız? **Cevap:** Alabilirsiniz, ama sonra Bool cebriyle sadeleştirmeniz gerekir. Üstteki dörtlü $\overline{c}d$, alttaki $cd$ verir (hoca dörtlüleri $c$ sütunlarına göre ayırdı); $d$ parantezine alınca $d(\overline{c}+c)=d$ bulunur. Bu yüzden doğrudan sekizli alınır.

**Soru:** Alt satırdaki ikiliyi de katsak altılı grup olur mu? **Cevap:** Altılı diye bir grup yoktur.

İkinci durum olarak hoca $ab=10$ satırının $cd=10$ hücresine de bir 1 ekledi. O zaman bu satırın dört hücresi bir dörtlü olur: $a=1$, $b=0$ sabit, $c$ ve $d$ değişir → $a\overline{b}$:

$$f=d+a\overline{b}$$

İki sonuç da python ile doğrulandı.

## 9. Senaryodan Devreye: Not Ağırlıklarıyla Geçme Devresi

Hoca konuyu bir senaryo sorusuyla bağladı (ekrandan, 02:35:00 ve 02:40:00). Dört değişken, dört değerlendirme ögesidir ve her biri ya tam puan alınmış (1) ya hiç alınmamış (0) kabul edilir:

- $a$: birinci vize, %20
- $b$: ikinci vize, %10
- $c$: ödev, %20
- $d$: final, %50

Toplam 60 ve üzeriyse öğrenci geçer, çıkış 1 olur. İstenen: mantık şeması, doğruluk tablosu, Karnaugh ile sade ifade.

**Mantık şeması:** 4 giriş, 1 çıkış.

**Doğruluk tablosu:** 16 satır vardır. Hoca hızlı yazmak için bir yöntem gösterdi: son sütun birer birer, bir öncekisi ikişer ikişer, bir öncekisi dörder dörder değişir. Tabloyu kısaltmak için $a=0$ satırlarını yazıp yanına $a=1$ sütununun sonuçlarını ayrı bir sütun olarak ekledi ($bcd$ aynı, yalnız $a$'nın 20 puanı eklenir).

| $bcd$ | Puan ($a=0$) | $f$ ($a=0$) | Puan ($a=1$) | $f$ ($a=1$) |
|---|---|---|---|---|
| 000 | 0 | 0 | 20 | 0 |
| 001 | 50 | 0 | 70 | 1 |
| 010 | 20 | 0 | 40 | 0 |
| 011 | 70 | 1 | 90 | 1 |
| 100 | 10 | 0 | 30 | 0 |
| 101 | 60 | 1 | 80 | 1 |
| 110 | 30 | 0 | 50 | 0 |
| 111 | 80 | 1 | 100 | 1 |

1 olan mintermler: 0011, 0101, 0111, 1001, 1011, 1101, 1111, yani $\sum m(3,5,7,9,11,13,15)$.

**Karnaugh haritası:**

```text
         cd=00  cd=01  cd=11  cd=10
ab=00      .      .      1      .
ab=01      .      1      1      .
ab=11      .      1      1      .
ab=10      .      1      1      .
```

8'li grup yapılamaz. Dörtlüler:

- $cd=11$ sütunu (dört satır): $a,b$ değişir; $c=1$, $d=1$ → $cd$.
- $ab=01,11$ satırlarında $cd=01,11$: $a$ değişir, $b=1$; $c$ değişir, $d=1$ → $bd$.
- $ab=11,10$ satırlarında $cd=01,11$: $a=1$, $b$ değişir; $c$ değişir, $d=1$ → $ad$.

Boşta kalan bir hücreyi ikili ile almak yerine bir dörtlü daha bulunabildi; hücreler birden fazla grupta yer alabilir.

$$f=ad+bd+cd$$

Sonuç python ile doğrulandı.

**Kapı sayısı.** Bu SOP biçimi 3 AND kapısı ($ad$, $bd$, $cd$) ve iki girişli 2 OR kapısı ister. Daha da sadeleştirilebilir mi? $d$ parantezine alınırsa $f=d(a+b+c)$ olur; bu 2 OR ve 1 AND kapısıyla gerçeklenir. Ama bu biçim artık SOP değildir. SOP biçiminde en sade hal $ad+bd+cd$'dir.

**Soru:** Bir OR kapısı yetmez mi? **Cevap:** İki girişli OR kapısıyla üç terimi toplamak için iki OR işlemi gerekir; aradaki "+" işaretlerini operatör gibi düşünün. Üç girişli bir OR kapısı olsaydı bir tane yeterdi. $n$ girişli AND ve OR kapıları vardır, ama devre gerçeklemede genellikle iki girişli kapılar esas alınır; dörtlü, beşli girişler çok özel durumlarda kullanılır.

## Örnek Sorular

**Soru 1** (ekrandan, 01:25:00): $1\cdot 0+\overline{(0+1)}$ ifadesinin değeri nedir?

> **Çözüm:** $1\cdot 0+\overline{(0+1)}=0+\overline{1}=0+0=0$.

**Soru 2** (ekrandan, 00:20:00): $F(x,y,z)=xy+\overline{z}$ Bool fonksiyonunun değerleri nedir?

> **Çözüm:** 2.2'deki tablo. $F$; 111, 110, 100, 010 ve 000 girdilerinde 1, diğerlerinde 0'dır. Devre: $x,y$ → AND; $z$ → NOT; ikisi → OR.

**Soru 3** (ekrandan, 00:30:00): $n$'nin değerine göre kaç farklı Bool fonksiyonu vardır?

> **Çözüm:** $2^n$ farklı girdi dizisi, dolayısıyla $2^{2^n}$ fonksiyon. $n=2$ için 16.

**Soru 4** (ekrandan, 00:35:00): $x(y+z)=xy+xz$ doğru mudur?

> **Çözüm:** 3.2'deki doğruluk tablosunda $x(y+z)$ ve $xy+xz$ sütunları sekiz satırda da aynıdır; eşitlik doğrudur.

**Soru 5** (derste sözlü ve ekrandan, 00:33:31): $(d<20)\;\&\&\;(c>40)$ koşulunu De Morgan kuralıyla başka biçimde yazınız.

> **Çözüm:** Koşulun değili $(d\ge 20)\lor(c\le 40)$'tır; özgün koşul $\overline{(d\ge 20)\lor(c\le 40)}$ olarak da yazılabilir.

**Soru 6** (ekrandan, 00:40:00): Tabloda verilen $F(x,y,z)$ ve $G(x,y,z)$ fonksiyonlarını tanımlayan Bool ifadelerini bulunuz.

> **Çözüm:** $F=x\overline{y}z$; $G=xy\overline{z}+\overline{x}y\overline{z}=y\overline{z}$.

**Soru 7** (ekrandan, 00:45:00): $F(x,y,z)=(x+y)\overline{z}$ fonksiyonunun açılımını bulunuz.

> **Çözüm:** $F=xy\overline{z}+x\overline{y}\,\overline{z}+\overline{x}y\overline{z}$ (4.3'teki iki çözüm).

**Soru 8** (derste sözlü, 00:46:50): $x+\overline{x}y$ neye eşittir?

> **Çözüm:** $x(1+y)+\overline{x}y=x+xy+\overline{x}y=x+y(x+\overline{x})=x+y$.

**Soru 9** (ekrandan, 01:05:00): (a) $(x+y)\overline{x}$, (b) $\overline{x}\,\overline{(y+\overline{z})}$, (c) $(x+y+z)(\overline{x}\,\overline{y}\,\overline{z})$ ifadelerini mantık kapılarıyla tasarlayınız.

> **Çözüm:** 6.2'deki devreler.

**Soru 10** (ekrandan, 01:10:00): İki bitlik yarım toplayıcının doğruluk tablosunu ve devresini veriniz.

> **Çözüm:** 6.4'teki tablo; $s=(x+y)\overline{(xy)}=\overline{x}y+x\overline{y}$, $c=xy$.

**Soru 11** (ekrandan, 02:10:00): $f=\sum m(1,4,7,9)$ fonksiyonunun en az kaç değişkenli olduğunu bulunuz, doğruluk tablosunu kurunuz ve Karnaugh haritasıyla sadeleştiriniz.

> **Çözüm:** 9 > 7 olduğundan 4 değişken. $f=\overline{b}\,\overline{c}d+\overline{a}b\overline{c}\,\overline{d}+\overline{a}bcd$ (8.2).

**Soru 12** (ekrandan, 02:30:00): 8.4'teki haritada birinci grubun ($ab=00$, $cd=00$–$01$) terimi nedir?

> **Çözüm:** $\overline{a}\,\overline{b}\,\overline{c}$. Haritanın tamamı: $f=\overline{a}\,\overline{b}\,\overline{c}+ab\overline{c}+\overline{b}c\overline{d}$.

**Soru 13** (ekrandan, 02:35:00): Birinci vize %20, ikinci vize %10, ödev %20, final %50 ağırlıklıdır ve her öge tam puan (1) ya da sıfır (0) alınmış kabul edilir. Toplam 60 ve üzeriyse çıkışı 1 olan devrenin mantık şemasını, doğruluk tablosunu ve en sade SOP ifadesini bulunuz.

> **Çözüm:** 4 giriş, 1 çıkış; $f=\sum m(3,5,7,9,11,13,15)=ad+bd+cd$ (9. bölüm).

## Dersin Toparlaması

Bu derste mantığın donanımdaki karşılığı olan Bool cebri işlendi. 0 ve 1 üzerinde toplama (OR), çarpma (AND) ve tümleyen (NOT) tanımlandı; $n$ değişkenli $2^{2^n}$ Bool fonksiyonu olduğu gösterildi. Bool cebrinin özdeşlikleri doğruluk tablosuyla kontrol edildi; De Morgan'ın program koşullarında nasıl kullanıldığı görüldü. Doğruluk tablosundan çarpımların toplamı biçiminde ifade yazma, ifadeyi kurallarla sadeleştirme ve devre çizme adım adım yapıldı; derste ayrıca $x+\overline{x}y=x+y$, $x(\overline{x}+y)=xy$ kuralları ve XOR/XNOR ifadeleri eklendi. Yarım toplayıcı, bu adımların küçük bir devre üzerindeki uygulamasıdır.

Bool cebri kuralları karmaşık ifadelerde yetersiz kalınca Karnaugh haritaları kullanılır. Haritanın etiketleri tek bit değişimiyle (00, 01, 11, 10) sıralanır; 1'ler 2'nin kuvveti büyüklüğünde, kenar ve köşeler komşu sayılarak gruplanır; grup içinde değişen değişken atılır. Minterm gösterimi ve not ağırlıklarından geçme devresi örneği, bir senaryodan doğruluk tablosuna, oradan sade ifadeye ve devreye giden tam akışı gösterdi. Hoca bir sonraki derste bu konunun kalan ayrıntılarını bitirip matematiğin temel kavramlarına geçileceğini söyledi; beş ve daha fazla değişkenli haritalar ile Quine–McCluskey yönteminin algoritmik tarafı ise bu derste anlatılmadı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
