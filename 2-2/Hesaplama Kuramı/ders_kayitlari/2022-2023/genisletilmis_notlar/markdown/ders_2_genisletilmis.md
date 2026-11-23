# Ders 2 Genişletilmiş Notu: Matematiksel Ön Bilgiler, İspat Teknikleri ve Diller

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Küme Teorisi Tekrarı
- 2. Boole Mantığı
- 3. Matematiksel Tanımlar
- 4. İspat Teknikleri
- 5. Alfabe, Dize ve Dil
- 6. Dize İşlemleri
- 7. Dil Örnekleri
- 8. Dil İşlemleri
- Örnek Sorular

## 1. Küme Teorisi Tekrarı

Ders, dersin İngilizce kaynaklarına uygun olarak İngilizce yürütüldü; öğrencilerin Türkçe soru sorabileceği belirtildi. Dersin ana kaynağı Michael Sipser'in *Introduction to the Theory of Computation* (3. baskı) kitabıdır. Kitabın yazarına ait çevrimiçi ders videolarına da bakılabileceği söylendi.

Önceki derste başlanan küme teorisi tekrarına kısaca devam edildi. Doğal sayılar, tam sayılar, rasyonel ve reel sayılar, alt küme ve kuvvet kümesi bilinen kavramlar olarak geçildi. Birleşim, kesişim ve fark işlemlerinin yanında **tümleyen**, $A$'da olmayan elemanların kümesidir: $\overline{A} = \{x : x \notin A\}$. **Kartezyen çarpım** $A \times B$, ilk bileşeni $A$'dan, ikinci bileşeni $B$'den gelen sıralı ikililerin kümesidir; yani bir ikililer kümesidir.

### 1.1 İkili İlişki ve Fonksiyon

Slayttaki tanımlar şöyledir (ekrandan, 00:15:00):

- $A$ ve $B$ kümeleri üzerinde bir **ikili ilişki** (binary relation), $A \times B$'nin bir alt kümesidir.
- $A$'dan $B$'ye bir **fonksiyon** $f: A \to B$, her $a \in A$ için ilk bileşeni $a$ olan **tam olarak bir** sıralı ikili içeren bir $R$ ikili ilişkisidir. Bu durumda $f(a) = b$ yazılır, "$f$, $a$'yı $b$'ye götürür" ya da "$a$'nın $f$ altındaki görüntüsü $b$'dir" denir. $A$ kümesine $f$'nin **tanım kümesi** (domain), $\{b \in B : f(a) = b \text{ olan bir } a \in A \text{ vardır}\}$ kümesine $f$'nin **görüntü kümesi** (range) denir.

Hoca, ikili ilişkiyi fonksiyonların bir üst kavramı gibi düşünmeyi önerdi: her fonksiyon bir ikili ilişkidir, ama belirli bir şartı sağlar. $f(a)=b$ ise fonksiyonu $(a,b)$ ikililerinden oluşan bir küme olarak düşünebiliriz.

> **Ders sonrası not:** Hoca anlatırken "$B$ kümesine $f$'nin range'i denir" dedi. Slayttaki tanıma göre range, $B$'nin tamamı değil, $f$'nin gerçekten ulaştığı $b$ değerlerinin kümesidir. $B$'nin tamamı için genellikle "değer kümesi" (codomain) terimi kullanılır.

### 1.2 Denklik İlişkisi

Bir $R \subseteq A \times A$ ikili ilişkisi aşağıdaki üç şartı sağlıyorsa **denklik ilişkisidir** (equivalence relation) (ekrandan, 00:15:00):

- **Yansımalı (reflexive):** Her $a \in A$ için $(a,a) \in R$.
- **Simetrik (symmetric):** Her $a, b \in A$ için $(a,b) \in R$ ise $(b,a) \in R$.
- **Geçişli (transitive):** Her $a, b, c \in A$ için $(a,b) \in R$ ve $(b,c) \in R$ ise $(a,c) \in R$.

**Soru:** "Equivalence"ın Türkçesi nedir? **Cevap:** Bir öğrencinin önerisiyle "denklik" denildi; dolayısıyla "denklik ilişkisi" terimi kullanıldı.

## 2. Boole Mantığı

İspatlarda mantıksal düşünmek gerektiği için Boole mantığına kısaca bakıldı. Boole mantığında iki değer vardır: 1 doğruyu, 0 yanlışı gösterir. Temel işlemler ve sembolleri (ekrandan, 00:20:00):

- **Değil** (negation, NOT): $\neg$
- **Ve** (conjunction, AND): $\wedge$
- **Veya** (disjunction, OR): $\vee$
- **Özel veya** (exclusive-or, XOR): $\oplus$
- **Denklik** (equivalence): $\leftrightarrow$ ya da $\Leftrightarrow$
- **Gerektirme** (implication): $\rightarrow$ ya da $\Rightarrow$

### 2.1 Doğruluk Tablosu

Slayttaki doğruluk tablosu (0 = yanlış, 1 = doğru) (ekrandan, 00:25:00):

| $p$ | $q$ | $\neg p$ | $p \wedge q$ | $p \vee q$ | $p \oplus q$ | $p \Leftrightarrow q$ | $p \Rightarrow q$ |
|---|---|---|---|---|---|---|---|
| 0 | 0 | 1 | 0 | 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 0 | 1 | 1 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 | 0 | 1 | 1 |

Hoca tabloyu sütun sütun okudu:

- **NOT:** yanlışın değili doğru, doğrunun değili yanlıştır.
- **AND:** yalnız iki işlenen de doğruysa doğrudur.
- **OR:** AND'in bir bakıma tersidir; yalnız iki işlenen de yanlışsa yanlıştır.
- **XOR:** işlenenlerden biri doğru, diğeri yanlışsa doğrudur. Bir bakıma işlenenlerin **farklı olup olmadığını** kontrol eder.
- **Denklik:** XOR'un tersidir. "Yanlış yanlışa eşittir", "doğru doğruya eşittir" diye düşünülebilir; işlenenler farklıysa yanlıştır.

### 2.2 Gerektirme

Hoca gerektirmenin kendisi için anlaşılması en zor işlem olduğunu söyledi. $p \Rightarrow q$ bir "eğer ... ise ..." yapısıdır: öncül (koşul) gerçekleşirse sonuç (söz) gerçekleşmelidir. Tabloda yalnız $1 \Rightarrow 0$ durumu yanlıştır.

Slayttaki örnek (ekrandan, 00:25:00):

- $p$: "çöpü çıkarırsın"
- $q$: "bir dolar alırsın"
- $p \Rightarrow q$ yalnız çöpü çıkarıp doları alamadığın durumda yanlıştır.

Hoca bunu bir ebeveynin çocuğuna verdiği söz gibi anlattı. Çöpü çıkarırsan ve doları alırsan ($1 \Rightarrow 1$) söz tutulmuştur, önerme doğrudur. Çöpü çıkarıp doları alamazsan ($1 \Rightarrow 0$) sen üzerine düşeni yapmışsın ama söz tutulmamıştır, önerme yanlıştır. İlginç olan üstteki iki satırdır: çöpü çıkarmadığın durumda doları almasan da ($0 \Rightarrow 0$), yine de alsan da ($0 \Rightarrow 1$) söz bozulmuş olmaz; önerme doğrudur.

## 3. Matematiksel Tanımlar

Hoca bu tanımların ezberlenmesi gerekmediğini, yalnız hatırlatma amaçlı olduğunu söyledi.

- **Teorem:** Doğru olan matematiksel bir önermedir. Bir önermenin ispatı olduğu için ona teorem deriz.
- **İspat:** Bir teoremin doğru olduğunu gösteren, mantıksal bir argüman oluşturan matematiksel önermeler dizisidir.
- **Aksiyom:** Altta yatan matematiksel yapı hakkındaki varsayımlardır; ispatları yoktur. Hoca örnek olarak olasılık teorisinde olasılıkların negatif olmadığının kabul edilmesini verdi. Olasılık teorisinde üç aksiyom vardır; bunlar ispatsız kabul edilir ve teorinin geri kalanı bunlardan ispatlanır.
- **Hipotez:** Sınırlı kanıta dayanan, daha fazla araştırılması gereken bir varsayım ya da tahmindir.
- **Lemma ve sonuç (corollary):** Teoremin farklı biçimleridir. Sonuç, bir teoremin özel bir durumudur.

> **Ek bilgi (derste anlatılmadı):** Lemma genellikle daha büyük bir teoremin ispatında kullanılan yardımcı bir teoremdir. Sonuç (corollary) ise bir teoremden doğrudan, kısa bir akıl yürütmeyle çıkan önermedir.

## 4. İspat Teknikleri

### 4.1 İspat İçin İpuçları

Nasıl ispat yapılacağı probleme bağlıdır, ama bazı genel stratejiler yardımcı olur (ekrandan, 00:35:00):

- İspatlanacak önermeyi **okuyup tamamen anlayın**. Çoğu zaman en zor kısım budur. Önermeyi kendi sözlerinizle yeniden yazın.
- Bazen teoremler içlerinde başka teoremler barındırır. "A özelliği ancak ve ancak B özelliği" iki önermenin ispatını gerektirir: (a) A doğruysa B doğrudur ($A \rightarrow B$), (b) B doğruysa A doğrudur ($B \rightarrow A$).
- "A kümesi B kümesine eşittir" teoremini ispatlamak için $A \subseteq B$ ve $B \subseteq A$ gösterilmelidir; yani $A$'nın her elemanının $B$'de, $B$'nin her elemanının $A$'da olduğu gösterilir.
- İspatlanacak şey üzerinde birkaç basit durum (örnek) deneyin.
- İspatı yazın; yazarken mantığınızdaki hataları görebilir, yeniden yazmanız gerekebilir.
- Sabırlı olun. İspat yapmak kolay değildir; pratikle alışılır.

> **Hocanın vurgusu:** Bu derste her şey kümelere dayandığı için küme eşitliğini iki yönlü alt küme ilişkisiyle ispatlamak çok sık karşımıza çıkacak.

### 4.2 Doğrudan İspat

Doğrudan ispatta teoreme doğrudan yaklaşılır (ekrandan, 00:40:00).

**Teorem:** $n$ tek pozitif tam sayıysa $n^2$ de tektir.

Önce birkaç örnekle teoremin makul olduğu görüldü: $n$ 1, 3, 7 gibi değerler alabilir; $-3$ olamaz, çünkü pozitiftir. $n=3$ için $n^2 = 9$, o da tektir.

**İspat:** Tek pozitif bir tam sayı, bir $k \ge 0$ tam sayısı için $n = 2k+1$ biçiminde yazılabilir. Örneğin $3 = 2 \cdot 1 + 1$, $9 = 2 \cdot 4 + 1$. Kare alınırsa:

$$n^2 = (2k+1)^2 = 4k^2 + 4k + 1 = 2(2k^2 + 2k) + 1$$

$2(2k^2+2k)$ çifttir, çünkü bir sayının 2 katıdır. "Çift artı bir tektir" olduğundan $n^2$ tektir.

### 4.3 İnşa ile İspat

İnşa ile ispat (constructive proof, proof by construction) bu derste çok kullanılacak. Sipser kitabında bir hesaplama modelinin var olduğunu göstermek için o modeli kurar. Bu yöntem genellikle bir tür nesnenin **var olduğunu** ispatlamak istediğimizde kullanılır; en iyi yol o nesneyi kurmaktır.

**Teorem:** $a$ ve $b$'nin ikisi de irrasyonel olmak üzere $a^b$ biçiminde yazılabilen bir rasyonel sayı $p$ vardır. (Rasyonel sayı, iki tam sayının bölümü olarak yazılabilen sayıdır.)

**İspat:** Böyle bir örnek vermek yeterlidir.

- $a = \sqrt{2}$ alınır; irrasyoneldir.
- $b = \log_2 9$ alınır. Bu da irrasyoneldir: $\log_2 9 = m/n$ ($m, n$ tam sayı) olsaydı logaritma özelliklerinden $2^m = 9^n$ olurdu. Ama $9^n$ tek, $2^m$ çifttir; bu olamaz.
- $a^b = \sqrt{2}^{\log_2 9} = 2^{\frac{1}{2}\log_2 9} = 9^{1/2} = 3$ (ara adım eklendi). 3 rasyoneldir.

Teorem böyle bir sayının var olduğunu söylüyordu; biz böyle bir sayıyı kurarak gösterdik.

<!-- BELİRSİZ: Bu slaydın karesi yok; seçilen sayılar altyazıdan alındı ve python ile doğrulandı (a^b = 3). -->

### 4.4 Olmayana Ergi

Olmayana ergi (proof by contradiction), her önermenin ya doğru ya yanlış olduğu, ama aynı anda ikisi birden olamayacağı gerçeğine dayanır (ekrandan, 00:45:00). Teoremin yanlış olduğu varsayılır, yani ispatlanmak istenenin tersi kabul edilir. Birkaç adım sonra bu varsayımın açıkça yanlış bir sonuca (çelişkiye) götürdüğü gösterilir ve buradan teoremin doğru olduğu sonucuna varılır. Bu tür akıl yürütme günlük hayatta da sık kullanılır. Hoca Türkçede bunun "olmayana ergi" yöntemi diye geçtiğini hatırlattı.

> **Hocanın vurgusu:** Olmayana ergi Sipser'in kitabında ve bu derste çok kullanılacak.

**Tanım:** Bir sayı, $p$ ve $q$ tam sayı olmak üzere $p/q$ biçiminde yazılabiliyorsa rasyoneldir; yazılamıyorsa irrasyoneldir.

**Teorem:** $\sqrt{2}$ irrasyoneldir.

**İspat** (ekrandan, 00:50:00):

1. $\sqrt{2}$'nin rasyonel olduğunu varsayalım. O hâlde ortak çarpanı olmayan $p$ ve $q$ tam sayıları için $\sqrt{2} = p/q$ yazılabilir.
2. İki tarafın karesi alınır: $p^2/q^2 = 2$, yani $2q^2 = p^2$.
3. $2q^2$ çift sayı olduğundan $p^2$ de çifttir.
4. Bu, $p$'nin çift olduğunu gösterir (karesi çift olan tam sayı çifttir).
5. O hâlde bir $r$ tam sayısı için $p = 2r$ ve $2q^2 = p^2 = (2r)^2 = 4r^2$.
6. Buradan $2r^2 = q^2$, yani $q$ de çifttir.
7. Bir yanlışlık oluştu: hem "$p$ ve $q$'nun ortak çarpanı yok" hem de "$p$ ve $q$'nun ortak çarpanı (2) var" önermelerine sahibiz. Bu bir çelişkidir.
8. Demek ki varsayım yanlıştır; $\sqrt{2}$ rasyonel değildir, yani irrasyoneldir.

### 4.5 Tümevarım

Tümevarımla ispatı (proof by induction) öğrencilerin birinci sınıf matematik derslerinde gördüğü hatırlatıldı. Genellikle $n$ tam sayısına bağlı bir $P(n)$ önermesi, çoğunlukla bir özdeşlik için kullanılır. İki kısmı vardır:

- **Taban (basis):** Özdeşliğin sabit bir değer için, örneğin $n=1$ için doğru olduğu gösterilir. $n$ yerine 1 yazmak yeterlidir; genellikle çok kolaydır.
- **Tümevarım adımı:** $P(n)$ doğruysa $P(n+1)$'in de doğru olduğu bir alt ispatla gösterilir. $n$ yerine $n+1$ yazılıp özdeşlik biraz düzenlenir; bu da genellikle kolaydır.

Mantığı şudur: $P(1)$ doğrudur. $P(n) \Rightarrow P(n+1)$ olduğundan $P(2)$ doğrudur; $P(2)$ doğru olduğundan $P(3)$ doğrudur ve bu böyle sonsuza kadar gider. Böylece özdeşlik 1'den büyük tüm değerler için doğrudur.

**Teorem:** Her pozitif tam sayı $n$ için (ekrandan, 01:00:00)

$$1 + 2 + 3 + \cdots + n = \frac{n(n+1)}{2}$$

**İspat:**

- **Taban:** $n = 1$ için sol taraf 1'dir; sağ taraf $\frac{1 \cdot 2}{2} = 1$'dir. Teorem $n=1$ için doğrudur.
- **Adım:** $n \ge 1$ olsun ve teoremin $n$ için doğru olduğunu, yani $1 + 2 + \cdots + n = \frac{n(n+1)}{2}$ olduğunu varsayalım. $n+1$ için göstermemiz gereken:

$$1 + 2 + \cdots + n + (n+1) = \frac{(n+1)(n+2)}{2}$$

Sol taraftaki $1 + \cdots + n$ kısmı varsayım gereği $\frac{n(n+1)}{2}$'dir. Hoca bunu tahtada kutu içine alarak gösterdi (ekrandan, 01:00:00). Geriye çarpma ve toplamayı yapmak kalır:

$$\frac{n(n+1)}{2} + (n+1) = \frac{n(n+1) + 2(n+1)}{2} = \frac{(n+1)(n+2)}{2} \quad \text{(ara adım eklendi)}$$

Özdeşlik $n+1$ için de doğrudur. $n=1$ için doğru olduğundan $n = 2, 3, 4, \ldots$ için, yani tüm $n \ge 1$ için doğrudur.

### 4.6 Güvercin Yuvası İlkesi

Bazı ispatlarda güvercin yuvası ilkesi (pigeonhole principle) kullanılır. Çok basit bir fikirdir: **$n+1$ ya da daha fazla nesne $n$ kutuya konursa en az bir kutuda iki ya da daha fazla nesne bulunur.**

Adı şu örnekten gelir: dört güvercin ve insanların güvercinler için yaptığı üç güvercin yuvası olsun. Yuvalar güvercinlerden az olduğundan, güvercinler yuvalara yerleştirildiğinde en az bir yuvada iki güvercin olur. Slaytta üç kutudan ikisinde birer, üçüncüsünde iki güvercin çizilidir ve "bir güvercin yuvası en az iki güvercin içermelidir" yazar (ekrandan, 01:05:00).

## 5. Alfabe, Dize ve Dil

Bir **dil** (language), dizelerin bir kümesidir. Bir **dize** (string), bir alfabeden alınan sembollerin dizisidir. Örneğin "cat", "dog", "house" birer dizedir; "house" dizesi h, o, u, s, e sembollerinden oluşur. $\{cat, dog, house\}$ bir dildir; herhangi bir dize kümesine dil denir.

**Alfabe** genellikle büyük sigma ($\Sigma$) ile gösterilir ve sembollerin bir kümesidir. Bir dildeki dizeler yalnız bu alfabedeki sembolleri içerebilir.

### 5.1 Hesaplama Problemlerini Dillerle Tanımlamak

Bu derste diller hesaplama problemlerini tanımlamak için kullanılacak (ekrandan, 01:25:00). Bir şeyin doğru olup olmadığı, bir şeyin bir kümede ya da dilde olup olmadığı biçiminde tanımlanabilir. Örneğin asal sayılar ve çift sayılar birer küme olarak tanımlanabilir:

$$PRIMES = \{2, 3, 5, 7, 11, 13, 17, \ldots\}, \qquad EVEN = \{0, 2, 4, 6, \ldots\}$$

Bu iki dil $\Sigma = \{0, 1, 2, \ldots, 9\}$ alfabesini kullanır. Bu yaklaşımda 11, PRIMES dilinden bir dizedir. "x sayısı asal mı?" normalde bir hesaplama problemidir; algoritmik olarak 2, 3 gibi çarpanları olup olmadığına bakılır. Ama burada konu problemi çözmek değil, problemi **tanımlamaktır**: bu problem "$x \in PRIMES$ mi?" biçiminde bir küme üyeliği problemine çevrilir. Hesaplama, küme üyeliğine dönüştürülür.

### 5.2 Alfabe ve Dize Örnekleri

$\Sigma = \{a, b\}$ alfabesinden $a$, $ab$, $abba$, $baba$, $aaabbbaabab$ gibi dizeler kurulabilir; hepsinin sembolleri $a$ ya da $b$'dir. Dize değişkenleri de kullanılabilir: örneğin $u = ab$, $v = bbbaaa$.

Sayı alfabeleri (ekrandan, 01:30:00):

- **Onluk sayılar alfabesi** $\Sigma = \{0, 1, 2, \ldots, 9\}$: günlük hayatta en çok kullandığımız alfabedir. $102345$ ve $567463386$ bu alfabeden dizelerdir; onluk sayılar bir dil oluşturur.
- **İkilik sayılar alfabesi** $\Sigma = \{0, 1\}$: $100010001$ ve $101101111$ gibi dizeler ikilik sayılar dilini oluşturur.
- **Tekli sayılar alfabesi** (unary) $\Sigma = \{1\}$: Alfabede tek sembol vardır. Yazılan 1'lerin sayısı, gösterilen sayıdır; örneğin onluk 4, yan yana dört 1 ile ($1111$) gösterilir. Tekli sayılar derste ileride öğrenilecek modellerle çalışmak için çok kolay olduğundan sık kullanılacak.

## 6. Dize İşlemleri

### 6.1 Birleştirme

$w = a_1 a_2 \cdots a_n$ ve $v = b_1 b_2 \cdots b_m$ olsun; örneğin $w = abba$, $v = bbbaaa$. **Birleştirme** (concatenation) $wv = a_1 a_2 \cdots a_n b_1 b_2 \cdots b_m$ yeni bir dizedir: ilk kısmı $w$, ikinci kısmı $v$'dir; $v$'nin sembolleri $w$'nin sembollerinin hemen ardından gelir.

### 6.2 Ters

$w = a_1 a_2 \cdots a_n$ dizesinin **tersi** $w^R = a_n \cdots a_2 a_1$'dir. Orijinal dize soldan sağa, ters dize sağdan sola okunduğunda aynı semboller elde edilir.

### 6.3 Uzunluk

Dizenin **uzunluğu** iki dikey çizgiyle gösterilir: $|w|$. Dizede $n$ sembol varsa uzunluk $n$'dir. Örneğin $|abba| = 4$, $|aa| = 2$, $|a| = 1$.

Birleştirmenin uzunluğu uzunlukların toplamıdır: $|uv| = |u| + |v|$. Slayttaki örnek (ekrandan, 01:35:00): $u = aab$, $|u| = 3$; $v = abaab$, $|v| = 5$; $|uv| = |aababaab| = 8$ ve $|u| + |v| = 3 + 5 = 8$.

### 6.4 Boş Dize

**Boş dize** (empty string, null string) hiç sembol içermeyen dizedir. Kitapta ve derste $\varepsilon$ ya da $\lambda$ ile gösterilir. Uzunluğu $|\varepsilon| = 0$'dır. Boş dize başka bir dizeyle birleştirildiğinde orijinal dize elde edilir; hiçbir sembol eklemez: $\varepsilon w = w \varepsilon = w$. Dizenin ortasına konsa da sonuç değişmez; örneğin $ab\varepsilon ba = abba$.

### 6.5 Alt Dize, Önek ve Sonek

**Alt dize** (substring), dizenin ardışık karakterlerinden oluşan bir alt dizidir. $abbab$ dizesinde $ab$, $abba$, $b$ ve $bbab$ birer alt dizedir.

**Önekler** (prefix) dizenin başından başlayan alt dizelerdir; **sonekler** (suffix) dizenin sonunda biten alt dizelerdir. $w = uv$ yazıldığında $u$ bir önek, $v$ bir sonektir. $abbab$ için (ekrandan, 01:40:00):

| Önekler | Sonekler |
|---|---|
| $\varepsilon$ | $abbab$ |
| $a$ | $bbab$ |
| $ab$ | $bab$ |
| $abb$ | $ab$ |
| $abba$ | $b$ |
| $abbab$ | $\varepsilon$ |

Boş dize bir önektir: başa boş dize eklense dize değişmez, dolayısıyla başta boş dize olduğu varsayılabilir. Dizenin kendisi de kendisinin önekidir, çünkü başta başlar ve orijinal dizenin içindedir. Aynı şekilde dizenin kendisi ve boş dize birer sonektir.

**Soru:** Önek ve soneklerde araya epsilon konabilir mi; örneğin $a\varepsilon b$ bir önek midir, bunun işe yarar bir kullanımı var mı? **Cevap:** $ab$ bir önektir ve araya epsilon koyunca aynı dize elde edilir, dolayısıyla öyle yazılabilir. Ama araya istediğiniz kadar epsilon konabileceği için sonsuz yazım çıkar; hoca bunun bir kullanımını görmediğini söyledi.

### 6.6 Dize Kuvveti

Dize kuvveti sayılardaki kuvvet işlemi **değildir**: $w^2$, $w$ çarpı $w$ demek değildir. $w^2 = ww$, yani iki $w$'nin birleştirilmesidir. Genel olarak $w^n = \underbrace{ww \cdots w}_{n}$. Örneğin $(abba)^2 = abbaabba$.

Tanım gereği $w^0 = \varepsilon$'dur; hiç $w$ birleştirilmemiş gibi düşünülebilir. Örneğin $(abba)^0 = \varepsilon$. Hoca, tanım gereği olan şeylerin "neden" diye tartışılmadığını söyledi.

### 6.7 Kleene Yıldızı ve Artı İşlemi

**Kleene yıldızı** çoğunlukla bir alfabe üzerinde kullanılır: $\Sigma^*$, $\Sigma$ alfabesinden kurulabilecek tüm olası dizelerin kümesidir. $\Sigma = \{a, b\}$ için

$$\Sigma^* = \{\varepsilon, a, b, aa, ab, ba, bb, aaa, aab, \ldots\}$$

Boş dize her zaman bu kümededir. Bu küme sonsuzdur.

**Artı işlemi** yıldıza çok benzer: $\Sigma^+$, boş dize hariç tüm olası dizelerin kümesidir (ekrandan, 01:45:00):

$$\Sigma^+ = \Sigma^* - \{\varepsilon\} = \{a, b, aa, ab, ba, bb, aaa, aab, \ldots\}$$

Buradaki eksi işareti küme farkıdır: $\Sigma^*$'ın, yalnız boş dizeyi içeren kümeden farkı, boş dize dışındaki bütün elemanlardır. Bazı yazarlar küme farkı için ters eğik çizgi kullanır ($A \setminus B$: $A$'da olup $B$'de olmayan elemanlar), bazıları ise eksi işareti kullanır.

## 7. Dil Örnekleri

Bir dil, alfabedeki dizelerden oluşan bir kümedir; yani $\Sigma^*$'ın herhangi bir alt kümesi bir dildir. $\Sigma = \{a, b\}$ için şunların hepsi birer dildir (ekrandan, 02:05:00):

$$\{\}, \quad \{\varepsilon\}, \quad \{a, aa, aab\}, \quad \{\varepsilon, abba, baba, aa, ab, aaaaaa\}$$

Boş küme de bir alt küme olduğu için elemansız bir dildir; yalnız boş dizeyi içeren küme de ayrı bir dildir.

### 7.1 Dilleri Özellikle Tanımlamak

Elemanları listelemek yerine elemanların özelliğini tanımlamak çoğu zaman daha kolaydır:

$$L = \{a^n b^n : n \ge 0\}$$

Bu dilin dizeleri $n$ tane $a$ ve ardından tam olarak aynı sayıda $b$'den oluşur. Elemanlar $n$'ye değer verilerek bulunur: $n=0$ için hiç $a$, hiç $b$ yoktur, yani $\varepsilon$; $n=1$ için $ab$; $n=2$ için $aabb$ ve böyle devam eder:

$$L = \{\varepsilon, ab, aabb, aaabbb, \ldots\}$$

$abb$ gibi bir dize dilde değildir, çünkü $a$ ve $b$ sayıları farklıdır; $b$ ile başlayan bir dize de dilde değildir, çünkü dize $a$ ile başlamalıdır. $n$ sonsuza kadar gidebildiği ve her $n$ değeri yeni bir dize verdiği için bu dil **sonsuz dildir**.

<!-- BELİRSİZ: Dilde olmayan örnek dizeler slaytta gösterildi ama karesi yok; "abb" ve "b ile başlayan dize" altyazıdaki açıklamadan kuruldu. -->

### 7.2 Asal, Çift ve Tek Sayılar

Asal sayılar 1'e ve kendisine bölünebilen sayılardır (ekrandan, 02:10:00). Alfabe $\Sigma = \{0, 1, 2, \ldots, 9\}$'dur. $PRIMES = \{2, 3, 5, 7, 11, 13, 17, \ldots\}$ diye listelemek mümkündür, ama listeye bakınca 17'nin neden orada olduğu kolayca anlaşılmaz. Özellikle tanımlamak daha anlaşılırdır:

$$PRIMES = \{x : x \in \Sigma^* \text{ ve } x \text{ asaldır}\}$$

Benzer şekilde $EVEN = \{x : x \in \Sigma^* \text{ ve } x \text{ çifttir}\}$ ve $ODD = \{x : x \in \Sigma^* \text{ ve } x \text{ tektir}\}$ yazılabilir.

### 7.3 Toplama Dili (Tekli Sayılarla)

Toplama da bir dil olarak tanımlanabilir (ekrandan, 02:15:00). Tekli sayılar burada yazımı kolaylaştırır. Alfabe $\Sigma = \{1, +, =\}$'dir.

$$ADDITION = \{x + y = z : x = 1^n,\ y = 1^m,\ z = 1^k,\ n + m = k,\ n \ge 1,\ m \ge 1\}$$

Bu dil **geçerli (doğru) toplamaları** tanımlar.

- $11 + 111 = 11111 \in ADDITION$ ($2 + 3 = 5$).
- $111 + 111 = 111 \notin ADDITION$, çünkü $3 + 3 = 3$ değildir, 6 olmalıdır.
- $ADDITION = \{1+1=11,\ 1+11=111,\ 11+1=111,\ 11+11=1111, \ldots\}$, yani $1+1=2$, $1+2=3$, $2+1=3$, $2+2=4$, ... $n, m \ge 1$ olduğundan boş dize bu dilde değildir.

**Soru:** Epsilonun üzerindeki yıldız alt kümeleri mi temsil ediyor? **Cevap:** Hayır. Bir öğrencinin sohbette yazdığı gibi, yıldız o alfabeyle türetilebilecek tüm dizelerden oluşan kümeyi temsil eder ve boş dize de buna dahildir.

<!-- BELİRSİZ: Soru altyazıda "Epsilon'un üzerindeki yıldız" diye geçiyor; cevaba bakılırsa soru büyük olasılıkla Sigma'nın (alfabenin) üzerindeki yıldızla ilgiliydi. -->

### 7.4 Kare Alma Dili

Tekli gösterimde $\#$ sembolü "kuvveti" anlamında kullanılarak **geçerli kare alma işlemleri** dili tanımlanır:

$$SQUARES = \{x \# y : x = 1^n,\ y = 1^m,\ m = n^2\}$$

Dizenin ilk kısmı $x$, ardından $\#$, ardından $y$ gelir. $x$, $n$ tane 1'den; $y$, $m$ tane 1'den oluşur ve $m = n^2$ olmalıdır. Hoca, örneğin $11 \# 1111$ ($2^2 = 4$) dizesinin dilde olduğunu, $3^2$ 9 olması gerekirken sağ tarafta 4 bulunan bir dizenin ise dilde olmadığını anlattı. Dil listelenirse $1^2 = 1$, $2^2 = 4$, $3^2 = 9$, ... işlemlerine karşılık gelen dizeler çıkar.

Burada iki farklı kuvvet işlemi vardır: $x = 1^n$ ifadesinde kuvvet bir dize üzerindedir ve birleştirme anlamına gelir; $m = n^2$ ifadesinde ise $n$ ve $m$ sayıdır ve kuvvet bildiğimiz aritmetik kare almadır. Hangisi olduğu işlenenlerin türünden anlaşılır. Hoca bunu nesneye yönelik programlamadaki **operatör aşırı yüklemeye** (operator overloading) benzetti: bir işlem, aldığı argümanlara göre farklı şeyler yapabilir.

<!-- BELİRSİZ: SQUARES slaydının karesi yok; dil tanımı ve örnekler altyazıdan kuruldu. Dilde olmayan örnek büyük olasılıkla 111#1111 idi. -->

### 7.5 İki Özel Dil

Kolayca karıştırılan iki dil vardır (ekrandan, 02:20:00):

- **Boş dil:** Hiç elemanı yoktur; $\{\}$ ya da $\emptyset$ ile gösterilir.
- **Boş dizeli dil:** $\{\varepsilon\}$; bir elemanı vardır, o da boş dizedir.

Dilin boyutu (eleman sayısı):

$$|\{\}| = 0, \quad |\{\varepsilon\}| = 1, \quad |\{a, aa, ab\}| = 3, \quad |\{\varepsilon, aa, bb, abba, baba\}| = 5$$

Ayrıca $\{\} \ne \{\varepsilon\}$; $|\{\}| = |\emptyset| = 0$ bir küme boyutu iken $|\varepsilon| = 0$ bir dize uzunluğudur. $|\{\varepsilon\}| = 1$'dir, çünkü boş dize kümenin bir elemanıdır.

> **Hocanın vurgusu:** Boş dil, boş dizeli dil, küme boyutu ve dize uzunluğu kolayca birbirine karıştırılır; bunlara dikkat edin.

## 8. Dil İşlemleri

### 8.1 Küme İşlemleri ve Tümleyen

Diller dize kümeleri olduğundan birleşim, kesişim ve fark gibi olağan küme işlemleri dillere uygulanabilir. **Tümleyen** şöyle tanımlanır:

$$\overline{L} = \Sigma^* - L$$

$\Sigma^*$ tüm olası dizelerin kümesi olduğundan, $L$'nin tümleyeni $L$'de olmayan ama alfabenin tüm dizeleri kümesinde olan dizelerdir. Slayttaki örnekte sonlu bir dilin tümleyeninin sonsuz bir dil olduğu gösterildi.

<!-- BELİRSİZ: Tümleyen örneğinin slaytı karede yok; altyazıda dil "ABA" diye geçiyor, büyük olasılıkla {a, ba} dili ve tümleyeni {ε, b, aa, ab, bb, aaa, ...} idi. -->

### 8.2 Dilin Tersi

Daha önce dizenin tersini görmüştük; şimdi bir dilin (kümenin) tersi tanımlanır. Bir dilin tersi, elemanları orijinal dilin elemanlarının tersleri olan başka bir kümedir (ekrandan, 02:25:00):

$$L^R = \{w^R : w \in L\}$$

Örnek: $\{ab, aab, baba\}^R = \{ba, baa, abab\}$.

$L = \{a^n b^n : n \ge 0\}$ ise $L^R = \{b^n a^n : n \ge 0\}$; artık $b$'ler dizenin başındadır.

### 8.3 Dil Birleştirme

Dize birleştirmeden sonra dil (küme) birleştirme tanımlanır:

$$L_1 L_2 = \{xy : x \in L_1,\ y \in L_2\}$$

İki kümenin birleştirmesi başka bir küme verir; elemanları, orijinal kümelerin elemanlarının birleştirmeleridir. Slayttaki örnekte $L_1$ üç, $L_2$ iki elemanlı olduğundan sonuçta $2 \cdot 3 = 6$ eleman vardı; tüm olası birleştirmeler yazılır.

<!-- BELİRSİZ: Dil birleştirme örneğinin karesi yok; altyazıda "A, AB, BA" ve "B, AA" diye geçiyor, büyük olasılıkla {a, ab, ba}{b, aa} = {ab, aaa, abb, abaa, bab, baaa} örneğiydi. -->

### 8.4 Dil Kuvveti

Dil birleştirmeye dayanarak dil kuvveti tanımlanır: $L^n$, $L$'nin kendisiyle $n$ kez birleştirilmesidir (ekrandan, 02:30:00):

$$L^n = \underbrace{L L \cdots L}_{n}$$

Adım adım yapmak kolaydır: önce ilk iki dil birleştirilir, sonra sonuç üçüncü dille birleştirilir ve böyle devam edilir.

Örnek: $\{a,b\}^3 = \{a,b\}\{a,b\}\{a,b\} = \{aaa, aab, aba, abb, baa, bab, bba, bbb\}$. Eleman sayısı $2 \cdot 2 \cdot 2 = 8$'dir; her elemanın ilk sembolü birinci, ikincisi ikinci, üçüncüsü üçüncü dilden gelir.

**Özel durum:** $L^0 = \{\varepsilon\}$. Bu tanım gereğidir; "$L$'yi kendisiyle hiç birleştirmemek" diye düşünülebilir. Örneğin $\{a, bba, aaa\}^0 = \{\varepsilon\}$.

### 8.5 $L^2$ Örneği

$L = \{a^n b^n : n \ge 0\}$ için (ekrandan, 02:35:00):

$$L^2 = \{a^n b^n a^m b^m : n, m \ge 0\}$$

Burada virgül "ve" diye okunur: $n$ ve $m$ sıfır ya da daha büyüktür. Örneğin $aabbaaabbb \in L^2$.

Hoca slayta ilk baktığında neden $\{a^n b^n a^n b^n\}$ olmadığını düşündüğünü söyledi ve bunu açıkladı. $L$'nin birkaç elemanı yazılır: $L = \{\varepsilon, ab, aabb, \ldots\}$. $L^2$, $L$'nin kendisiyle birleştirilmesidir; birinci $L$'den $aabb$, ikinci $L$'den $aaabbb$ seçilebilir. Bu iki seçim birbirinden bağımsız olduğundan iki parçanın $a$ ve $b$ sayıları farklı olabilir; bu yüzden ayrı bir $m$ kullanılır. $aabbaaabbb$ dizesi $aabb \cdot aaabbb$ diye bölünür; $n = 2$, $m = 3$ (ara adım eklendi).

Ayrıca $n$ sıfır olabildiği için $L$'nin bir elemanı boş dize de olabilir; o zaman $L^2$'nin bazı elemanları $L$'nin elemanlarıyla aynıdır.

**Soru (öğrencinin eklemesi):** $L$'nin elemanı boş da olabilir, çünkü $n \ge 0$; dizeyi tam ortadan bölerek sağdaki örneği elde edebilir miyiz? **Cevap:** Hoca sıfır olabileceği konusunda öğrenciye hak verdi. Ancak dize tam ortadan bölündüğünde iki yarı birbirinin aynısı olmaz; $a$ ve $b$ sayıları farklıdır. Önemli olan, iki parçanın ayrı ayrı $L$'den seçilmesidir.

### 8.6 Kleene Yıldızı (Yıldız Kapanışı)

**Kleene yıldızı** ya da yıldız kapanışı (star closure), $L$'deki dizelerin birleştirilmesiyle kurulabilecek tüm dizeleri verir (ekrandan, 02:40:00):

$$L^* = L^0 \cup L^1 \cup L^2 \cup \cdots$$

$L^1$, $L$'nin kendisidir; $L^2$, $L$'nin $L$ ile birleştirilmesidir ve böyle devam eder. Örnek:

$$\{a, bb\}^* = \{\varepsilon,\ a, bb,\ aa, abb, bba, bbbb,\ aaa, aabb, abba, abbbb, \ldots\}$$

Burada $\varepsilon$ $L^0$'dan; $a, bb$ $L^1$'den; $aa, abb, bba, bbbb$ $L^2$'den; $aaa, aabb, abba, abbbb, \ldots$ $L^3$'ten gelir. $L^3$'teki her dizenin üç parçası vardır ve her parça $a$ ya da $bb$ olabilir. Sonuç, orijinal dilin tüm olası birleştirmelerini içeren çok büyük bir dildir.

Hoca yıldızın üç farklı şeyin üzerine konabileceğini toparladı:

- **Alfabe üzerinde:** O alfabeyle oluşturulabilecek tüm dizeler.
- **Dize üzerinde:** Dizenin tüm kuvvetleri. Örneğin $(ab)^*$: $(ab)^0 = \varepsilon$, $(ab)^1 = ab$, $(ab)^2 = abab$, ...
- **Dil üzerinde:** Dilin tüm kuvvetlerinin birleşimini içeren küme.

**Soru:** Beş köşeli yıldız ile altı köşeli yıldız arasında fark var mı? **Cevap:** Yok; ikisi de Kleene yıldızıdır.

### 8.7 Pozitif Kapanış

**Pozitif kapanış** (positive closure) yıldız kapanışına çok benzer; farkı, $L^0$'ı içermemesidir:

$$L^+ = L^1 \cup L^2 \cup \cdots$$

Dolayısıyla sonuç kümede $L^0$'dan gelen boş dize bulunmaz.

> **Ek bilgi (derste anlatılmadı):** $L$'nin kendisi $\varepsilon$ içeriyorsa $\varepsilon$, $L^1$ üzerinden $L^+$'ya da girer. Bu yüzden genel olarak $L^+ = L^* - \{\varepsilon\}$ eşitliği yalnız $\varepsilon \notin L$ iken doğrudur; her zaman doğru olan eşitlik $L^+ = LL^*$'dır.

## Örnek Sorular

**1.** (ekrandan, 00:40:00) $n$ tek pozitif tam sayıysa $n^2$'nin de tek olduğunu doğrudan ispatla gösterin.

> **Çözüm:** $n = 2k+1$ ($k \ge 0$) yazılır. $n^2 = 4k^2 + 4k + 1 = 2(2k^2+2k) + 1$. İlk terim çift olduğundan $n^2$ tektir.

**2.** (derste sözlü, 00:42:05) $a$ ve $b$ irrasyonel olmak üzere $a^b$ biçiminde yazılabilen bir rasyonel sayının var olduğunu inşa ile ispatlayın.

> **Çözüm:** $a = \sqrt{2}$, $b = \log_2 9$. $b = m/n$ olsaydı $2^m = 9^n$ olurdu (çift = tek), olanaksız; $b$ irrasyoneldir. $a^b = 2^{\frac{1}{2}\log_2 9} = \sqrt{9} = 3$ rasyoneldir.

**3.** (ekrandan, 00:50:00) $\sqrt{2}$'nin irrasyonel olduğunu olmayana ergi ile ispatlayın.

> **Çözüm:** $\sqrt{2} = p/q$, $p, q$ ortak çarpansız varsayılır. $2q^2 = p^2$ olduğundan $p$ çifttir, $p = 2r$. $2q^2 = 4r^2 \Rightarrow q^2 = 2r^2$, $q$ da çifttir. Ortak çarpan 2 çıkar; çelişki.

**4.** (ekrandan, 01:00:00) Her pozitif tam sayı $n$ için $1 + 2 + \cdots + n = \frac{n(n+1)}{2}$ olduğunu tümevarımla ispatlayın.

> **Çözüm:** Taban: $n=1$ için $1 = \frac{1\cdot 2}{2}$. Adım: $\frac{n(n+1)}{2} + (n+1) = \frac{(n+1)(n+2)}{2}$.

**5.** (derste sözlü, 01:46:36) $abbab$ dizesi için $ab$ bir önek, $bab$ bir sonek denebilir mi?

> **Çözüm (derste verilmedi):** Evet. $abbab = ab \cdot bab$ biçiminde yazılabildiğinden ($w = uv$, $u = ab$, $v = bab$) $ab$ bir önek, $bab$ bir sonektir. Önek tablosunda $ab$, sonek tablosunda $bab$ yer alır.

**6.** (ekrandan, 02:15:00) Aşağıdaki dizeler ADDITION dilinde midir?

- $11 + 111 = 11111$
- $111 + 111 = 111$

> **Çözüm:** Birincisi $2 + 3 = 5$ olduğundan $\in ADDITION$. İkincisi $3 + 3 = 3$ olmadığından (6 olmalı) $\notin ADDITION$.

**7.** (ekrandan, 02:30:00) $\{a,b\}^3$ ve $\{a, bba, aaa\}^0$ kümelerini yazın.

> **Çözüm:** $\{a,b\}^3 = \{aaa, aab, aba, abb, baa, bab, bba, bbb\}$ (8 eleman). $\{a, bba, aaa\}^0 = \{\varepsilon\}$.

**8.** (ekrandan, 02:35:00) $L = \{a^n b^n : n \ge 0\}$ için $L^2$ nedir? $aabbaaabbb \in L^2$ midir?

> **Çözüm:** $L^2 = \{a^n b^n a^m b^m : n, m \ge 0\}$. $aabbaaabbb = aabb \cdot aaabbb$; $n = 2$, $m = 3$ olduğundan $L^2$'dedir.

## Dersin Toparlaması

Bu derste dersin matematiksel ön bilgileri tamamlandı. Küme teorisinden ikili ilişki, fonksiyon ve denklik ilişkisi; Boole mantığından temel işlemler ve doğruluk tablosu, özellikle gerektirme tekrar edildi. Ardından ispat teknikleri görüldü: doğrudan ispat, bu derste çok kullanılacak olan inşa ile ispat ve olmayana ergi, tümevarım ve güvercin yuvası ilkesi.

Dersin ikinci yarısında hesaplama kuramının temel nesnesi olan diller tanıtıldı. Alfabe, dize ve dil kavramlarıyla hesaplama problemlerinin küme üyeliği problemine çevrilebileceği görüldü. Dize işlemleri (birleştirme, ters, uzunluk, boş dize, önek/sonek, kuvvet, $\Sigma^*$ ve $\Sigma^+$) ve dil işlemleri (tümleyen, ters, birleştirme, kuvvet, Kleene yıldızı ve pozitif kapanış) tanımlandı. Bir sonraki derste deterministik sonlu otomatlara geçileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
