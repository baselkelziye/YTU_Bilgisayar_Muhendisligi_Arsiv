# Ders 7 Genişletilmiş Notu: Bağlamdan Bağımsız Gramerlerin Sadeleştirilmesi, Normal Formlar ve Yığıtlı Otomatlara Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağlamdan bağımsız gramerlerin tekrarı
- 2. Üretim sırası, üretim ağaçları ve belirsizlik
- 3. Gramerlerin sadeleştirilmesi ve yerine koyma kuralı
- 4. Null üretimlerin atılması
- 5. Birim üretimlerin atılması
- 6. Gereksiz değişken ve üretimlerin atılması
- 7. Chomsky normal formu
- 8. Greibach normal formu
- 9. Yığıtlı otomatlar (PDA)
- 10. PDA örneği: $a^n b^n$
- 11. PDA örneği: $v v^R$ ve paralel makineler
- Örnek Sorular
- Dersin Toparlaması

## 1. Bağlamdan bağımsız gramerlerin tekrarı

Dersin ilk yarım saati önceki dersin Türkçe tekrarıyla geçti; yeni konular İngilizce anlatıldı. Önceki derste bağlamdan bağımsız dillere (context-free languages) başlanmıştı. Düzenli diller daha önce öğrenilmişti; bağlamdan bağımsız diller onların üst kümesidir (süper kümesi). Örneğin $\{a^n b^n : n \ge 0\}$ düzenli değildir ama bağlamdan bağımsızdır. Aynı şekilde $w w^R$ biçimindeki dizgeler de düzenli değil, bağlamdan bağımsızdır.

Bu dilleri tanımlamak için iki yol vardır: bağlamdan bağımsız gramerler (context-free grammars) ve yığıtlı otomatlar (pushdown automata). Gramerler önceki derste görülmüştü, yığıtlı otomatlara bu dersin sonunda başlandı.

> **Ders sonrası not:** Hoca bu cümlede "düzenli dilleri tanımlayabilmek için iki alternatifimiz var" dedi; bağlamın gösterdiği gibi kastedilen bağlamdan bağımsız dillerdir.

### 1.1 Gramerin yapısı

Bir gramerde değişken (variable) ve üretim kuralları (production rules) vardır. Üretim kuralı, bir değişkenin nasıl açılabileceğini, neler üretebileceğini söyler. Önceki dersin İngilizce gramer örneğinde $\langle sentence \rangle$, bir $\langle noun\_phrase \rangle$ ve arkasından bir $\langle predicate \rangle$ olarak açılır; $\langle noun\_phrase \rangle$ bir $\langle article \rangle$ ve bir $\langle noun \rangle$ olarak; $\langle predicate \rangle$ bir $\langle verb \rangle$ olarak açılır. Köşeli ayraç içinde olanlar değişkendir. Ayraç içinde olmayan $a$, $the$, $dog$ gibi semboller bitiş sembolleridir (terminals); artık değişken değildir, açılmaya çalışılmaz.

Kuralları bir arada kullanarak farklı dizgeler (cümleler) üretilebilir. "the dog sleeps" şöyle üretilir (ekrandan, 00:10:00):

$$\langle sentence \rangle \Rightarrow \langle noun\_phrase \rangle \langle predicate \rangle \Rightarrow \langle noun\_phrase \rangle \langle verb \rangle \Rightarrow \langle article \rangle \langle noun \rangle \langle verb \rangle$$
$$\Rightarrow the\ \langle noun \rangle \langle verb \rangle \Rightarrow the\ dog\ \langle verb \rangle \Rightarrow the\ dog\ sleeps$$

Türetime $\langle sentence \rangle$'tan başlanır, $\langle noun\_phrase \rangle$'tan başlanamaz. Kurallar yazılırken en üstteki, en soldaki değişken başlangıç değişkenidir (start variable). "a cat runs" da aynı şekilde üretilir. Bu biçimde üretilebilecek bütün dizgeler ("a cat runs", "a cat sleeps", "the cat runs", "the dog sleeps" vb.) gramerin dilini oluşturur.

### 1.2 $a^n b^n$ grameri

İkinci örnekte başlangıç değişkeni $S$'dir (ekrandan, 00:15:00):

$$S \to aSb, \qquad S \to \varepsilon$$

Birinci kural, $a$ ile $b$ arasında yine $S$'i içeren bir dizi üretir; yani $S$ kendini de içeren bir dizi üretir. İkinci kural $S$'in boş dize (null) üretebileceğini, yani $S$ yerine boş dize yazılabileceğini söyler. $ab$ şöyle üretilir: $S \Rightarrow aSb$ (birinci kural), sonra ikinci kuralla $S$ yok edilir ve $ab$ kalır. Benzer şekilde $aabb$ ve $aaabbb$ üretilebilir. Üç örnekten görülen, eşit sayıda $a$ ve $b$ içeren $a^n b^n$ dizgeleridir. Gramerin dili

$$L = \{a^n b^n : n \ge 0\}.$$

Birkaç adımda üretilebilirliği göstermek için $\stackrel{*}{\Rightarrow}$ işareti kullanılır; İngilizcede "implies" diye okunabilir. Ekrandaki örnekler: $S \stackrel{*}{\Rightarrow} \varepsilon$, $S \stackrel{*}{\Rightarrow} ab$, $S \stackrel{*}{\Rightarrow} aaabbb$, $S \stackrel{*}{\Rightarrow} aaSbb \stackrel{*}{\Rightarrow} aaaaaSbbbbb$ (ekrandan, 00:15:00).

Bir değişkenin bütün kurallarını alt alta yazmak yerine dik çizgiyle yan yana da yazabiliriz; dik çizgi "or" (veya) diye okunur. $S \to aSb \mid \varepsilon$ aynı anlama gelir.

### 1.3 Biçimsel tanım

Gramer esasen bir dörtlüdür:

$$G = (V, T, S, P)$$

Birinci eleman bütün değişkenleri içeren küme, ikinci eleman bitiş sembollerini içeren küme, üçüncü eleman başlangıç değişkeni, dördüncü eleman üretim kurallarının kümesidir. Üretim kuralları virgülle ayrılarak küme elemanları gibi yazılabilir. Elle çalışırken kuralları yazmak yeterlidir; bir bilgisayar programı yazılacaksa gramer biçimsel olarak bu dört yapıdan oluşur.

**Soru:** Slaytta dörtlünün sırası böyle verilmiş, kitapta başlangıç değişkeni farklı bir sıradaydı. Yazarken hangisini tercih etmeliyiz?
**Cevap:** Sıranın ezberlenmesini gerektiren bir soru sorulmaz; başlangıç değişkeninin ne olduğu sorulabilir ama dörtlünün içindekilerin sırası sorulmaz. Normalde derste anlatılan ve slaytlar önceliklidir; böyle bir farklılık görülürse belirtilmesi faydalıdır.

Bunlarla bir gramerin dili tanımlanır. $G$ gramerinin dili $L(G)$, başlangıç değişkeninden başlayıp bir kısım adım sonunda ulaşılabilen ve bitiş sembolleriyle yazılan dizgelerden oluşur:

$$L(G) = \{ w \in T^* : S \stackrel{*}{\Rightarrow} w \}$$

Bir dile, onu üreten bir bağlamdan bağımsız gramer varsa bağlamdan bağımsız denir: $L$ bağlamdan bağımsızdır, eğer $L = L(G)$ olan bir bağlamdan bağımsız $G$ grameri varsa (ekrandan, 00:20:00).

### 1.4 Gramerin ürettiği dili bulmak

Tekrar edilen bir başka gramer, bir ön kısım ve hemen arkasından ön kısmın tersini, yani $w w^R$ biçimindeki dizgeleri üretir. Bunlara palindrom denir; bu gramer çift uzunluklu palindromları üretir. Önceki derste görülen bir diğer gramer ise eşleşen parantezleri, yani her açılan parantezin bir kapanışı olduğu dizgeleri üretir. <!-- BELİRSİZ: Palindrom ve parantez gramerlerinin kuralları incelenen karelerde görünmüyor; yalnız ürettikleri dil altyazıdan alındı. -->

> **Hocanın vurgusu:** Sınavda "bu gramer neyi üretir?" diye sorulduğunda kağıt kalemi alıp gramerin ürettiği 3-5 dizgeyi çıkarmak, onlara bakıp toparlamak gerekir. Hoca, parantez gramerine bakınca eşleşen parantezleri ürettiğini kendisinin de hemen göremeyeceğini söyledi.

## 2. Üretim sırası, üretim ağaçları ve belirsizlik

### 2.1 Soldan ve sağdan üretim

Beş kurallı bir gramerde $aab$ dizgesinin üretimine bakıldı. Her adımda önce en soldaki değişken yerine konuyorsa bu üretime soldan üretim (leftmost derivation) denir. Her adımda en sağdaki değişken yerine konuyorsa sağdan üretim (rightmost derivation) olur. Slaytta $aab$'nin hem soldan hem sağdan üretimi gösterildi. <!-- BELİRSİZ: Bu gramerin kuralları ve iki üretim incelenen karelerde görünmüyor. Anlatım (S'nin iki dala, bir değişkenin üç dala bölünmesi, beş yaprak) büyük olasılıkla Busch slaytlarındaki S → AB, A → aaA | ε, B → Bb | ε gramerine uyar; bu durumda soldan üretim S ⇒ AB ⇒ aaAB ⇒ aaB ⇒ aaBb ⇒ aab olur. -->

### 2.2 Üretim ağacı

Üretim sırası bir ağaç yapısı oluşturur. İlk kullanılan üretim $S$'yi iki dala böler; sonra bir değişken yerine konunca o da örneğin üç dala bölünür; bir başka değişken iki dala bölünür; boş dizeye giden değişkenden tek dal çıkar. Bittiği yerlere yaprak denir. Hocanın örneğinde toplamda beş yapraklı bir ağaç oluştu. Bu ağaca üretim ağacı (derivation tree, parse tree) denir. Üretim ağacı dizgenin anlamını ifade eder.

Çoğu zaman sağdan ya da soldan üretmek fark etmez, aynı ağaç ortaya çıkar. Ama bazen aynı dizgenin iki farklı soldan üretimi ve dolayısıyla iki farklı ağacı olabilir.

### 2.3 Belirsizlik (ambiguity)

Gramer (ekrandan, 00:25:00):

$$E \to E + E \mid E * E \mid (E) \mid a$$

$a + a * a$ dizgesinin bir soldan üretimi $E \Rightarrow E + E \Rightarrow a + E \Rightarrow a + E * E \Rightarrow a + a * E \Rightarrow a + a * a$ biçimindedir; ağacın kökünde $+$ vardır. Ekrandaki başka bir soldan üretim ise

$$E \Rightarrow E * E \Rightarrow E + E * E \Rightarrow a + E * E \Rightarrow a + a * E \Rightarrow a + a * a$$

biçimindedir (ekrandan, 00:25:00). Bu ağacın kökü $E * E$'dir; sol $E$, $E + E$ olarak açılır, yani ağaç $(a + a) * a$ yapısındadır. İkisi de soldan üretim olduğu halde farklı ağaçlar çıkar. <!-- BELİRSİZ: İlk soldan üretimin adımları incelenen karede yok; altyazıdaki anlatımdan ve ikinci ağacın tersi olmasından kuruldu. -->

Bu bir sorundur, çünkü dizge bu gramere göre iki farklı anlama gelebilir. Özellikle C, Java, Python gibi programlama dillerinde yazılan kodun anlamının tekil olması istenir; orada müphemlik, belirsizlik istenmez. Hocanın sayısal örneği: $a = 2$ denirse bir ağaca göre ifade $6$'ya, diğerine göre $8$'e eşittir:

$$2 + (2 \cdot 2) = 6, \qquad (2 + 2) \cdot 2 = 8.$$

Bu soruna belirsizlik (ambiguity) denir.

Bir başka belirsizlik örneği: $\langle statement \rangle$, "if $\langle expression \rangle$ then $\langle statement \rangle$" olarak da "if $\langle expression \rangle$ then $\langle statement \rangle$ else $\langle statement \rangle$" olarak da açılabilir. Hoca bunun C'de iki geçerli açılım olduğunu belirtti. Bu durumda iç içe bir if ifadesi iki ayrı anlama gelebilir. Dilin kendisi böyle bir belirsizlik içeriyorsa belirsizliği kaldırmak programcıya düşer; programcı süslü parantezler, blok parantezleri kullanarak ne demek istediğini kesinleştirir.

> **Ek bilgi (derste anlatılmadı):** Bu durum derleyici kitaplarında "dangling else" (sarkan else) sorunu olarak bilinir. C gibi dillerde kural olarak `else`, en yakın eşleşmemiş `if`'e bağlanır.

### 2.4 Belirsizliği gidermek ve doğası gereği belirsiz diller

Bazen gramer değiştirilerek belirsizlik giderilir: gramer, aynı işi görecek ama belirsiz olmayacak biçimde yeniden yazılır. Slaytta, belirsizlik içeren $E$ grameri için belirsiz olmayan bir gramer gösterildi. Bunu çıkarmak uğraş ister, kolay olmayabilir; bazen yapılabilir, bazen yapılması hiç mümkün olmaz. <!-- BELİRSİZ: Belirsiz olmayan gramerin kuralları incelenen karelerde görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** Bu tür gramerlerde öncelik büyük olasılıkla katmanlı değişkenlerle sağlanır; ders kitaplarında sık görülen biçim $E \to E + T \mid T$, $T \to T * F \mid F$, $F \to (E) \mid a$ şeklindedir.

Dilin kendisi belirsizse belirsizlik içermeyen bir gramer yazılamaz. Örnek dil:

$$L = \{a^n b^n c^m\} \cup \{a^n b^m c^m\}$$

Birinci kümede $a$ ve $b$ sayısı aynıdır, $c$ farklı olabilir; ikinci kümede $b$ ve $c$ sayısı aynıdır, $a$ farklı olabilir. Bu dili üreten gramerde $S$ önce $S_1$'e ya da $S_2$'ye geçer: $S_1$ birinci kümeyi, $S_2$ ikinci kümeyi üretir. Üçünün de sayısı eşit olan $a^n b^n c^n$ dizgeleri iki kümede birden vardır. Bu yüzden $a^n b^n c^n$ dizgesinin her zaman iki farklı üretim ağacı olur, hangi gramer seçilirse seçilsin (ekrandan, 00:30:00). Ekrandaki ağaçlardan biri $S \to S_1$, $S_1 \to S_1 c$ ile, diğeri $S \to S_2$, $S_2 \to a S_2$ ile başlar. Başta hangi alt kümeye gidileceğine karar vermek gerekir ve dilin kendisindeki bu belirsizlik kaldırılamaz. Böyle dillere doğası gereği belirsiz (inherently ambiguous) dil denir.

## 3. Gramerlerin sadeleştirilmesi ve yerine koyma kuralı

Bu bölümden itibaren ders İngilizce sürdü. Konu, bağlamdan bağımsız gramerlerin sadeleştirilmesidir (simplification).

Neden sadeleştirme gerekir? Bazı uygulamalarda, örneğin ayrıştırıcı (parser) yazarken, gramerin sadeleştirilmiş ya da belirli bir normal biçimde olması daha iyidir. Örneğin Chomsky normal formu denen bir biçim vardır ve ayrıştırıcı yazılıyorsa Chomsky normal formundaki bir gramer kullanmak daha iyidir. Ayrıca gramerlerde gereksiz kurallar bulunabilir; bunlar grameri anlamayı zorlaştırır.

### 3.1 Yerine koyma kuralı (substitution rule)

Gramer (ekrandan, 00:35:00):

$$S \to aB, \quad A \to aaA, \quad A \to abBc, \quad B \to aA, \quad B \to b$$

$B \to b$ kuralı, $B$ değişkeninin $b$ bitiş sembolünü üretebileceğini söyler. Bu kuraldan kurtulmak isteyelim. Kural $B$ değişkeniyle ilgili olduğu için geri kalan kurallar taranır ve sağ tarafta geçen bütün $B$'ler bulunur. $S \to aB$ kuralında $B$ var; $B$ yerine $b$ yazılarak bir seçenek eklenir: $S \to aB \mid ab$. $A \to abBc$ kuralında da $B$ var; aynı şekilde $A \to abBc \mid abbc$ eklenir. Bu kuralı kullanmadan aynı sonuca nasıl ulaşılacağı böylece sağlanmış olur ve $B \to b$ silinir. Eşdeğer gramer (ekrandan, 00:35:00):

$$S \to aB \mid ab, \quad A \to aaA, \quad A \to abBc \mid abbc, \quad B \to aA$$

Şimdi $B \to aA$ kuralından da kurtulalım; böylece $B$ değişkeni tamamen ortadan kalkar ama aynı dil korunur. Yine geri kalan kurallarda iki $B$ görülür. Her biri için $B$'nin ürettiği eklenir: $S \to aB \mid ab \mid aaA$ ($B$ yerine $aA$) ve $A \to abBc \mid abbc \mid abaAc$. Gerekli kurallar eklendiği için $B \to aA$ silinir (ekrandan, 00:40:00).

Bu noktada $S \to aB$ seçeneği hiçbir yere varmaz, çünkü artık sol tarafında $B$ olan bir kural yoktur. Bu üretim gereksizdir, kullanılamaz; doğrudan silinebilir. Aynısı $abBc$ seçeneği için de geçerlidir; ekranda ikisinin de üstü çizildi (ekrandan, 00:40:00). Sonuç:

$$S \to ab \mid aaA, \quad A \to aaA, \quad A \to abbc \mid abaAc$$

> **Ders sonrası not:** Altyazıda $B$ yerine "AA" yazılacağı geçiyor; ekranda yazılan $aA$'dır (küçük $a$, büyük $A$).

Genel olarak: $A \to xBz$ ve $B \to y_1$ kuralları varsa ve $B \to y_1$ atılmak isteniyorsa, $B$ yerine $y_1$ yazılan ek bir kural eklenir:

$$A \to xBz \mid x y_1 z$$

ve ardından $B \to y_1$ silinir.

## 4. Null üretimlerin atılması

$X \to \varepsilon$ biçimindeki kurala null üretim ($\varepsilon$-üretimi, null production) denir. Bu kuralı olan $X$ değişkenine boşalabilir değişken (nullable variable) denir.

Null üretimleri atmak neden istenir? Bazı uygulamalar null üretimlere izin vermez. Diğer değişkenler için null üretimler her zaman atılabilir; ama başlangıç değişkeni boş dize üretiyorsa bu atılamaz, çünkü başlangıç değişkeni $S$ silinemez.

Diğer değişkenler için yapılacak tek şey az önce öğrenilen yerine koyma kuralıdır: $M$ nerede görülüyorsa, $M$ yerine boş dize konunca ne olacağı düşünülür. Örnek (ekrandan, 00:45:00):

$$S \to aMb, \quad M \to aMb, \quad M \to \varepsilon$$

$M \to \varepsilon$ atılmak istendiği için geri kalan kuralların sağ tarafındaki $M$'ler taranır; iki tane vardır. Her biri için "veya" ile bir seçenek konur: $M$ yerine boş dize yazılır, $a \varepsilon b$. Boş dize "hiçbir dize yok" demek olduğu için $a \varepsilon b$ aslında $ab$'dir. Sonuç gramer:

$$S \to aMb \mid ab, \qquad M \to aMb \mid ab$$

Bütün null üretimler atıldıktan sonra bütün boşalabilir değişkenler ortadan kalkar; başlangıç değişkeni bunun istisnasıdır (ekrandan, 00:45:00). Hoca ekrana $S \to \varepsilon$ yazarak, başlangıç değişkeninde böyle bir kural olsaydı onun kalacağını gösterdi.

## 5. Birim üretimlerin atılması

Birim üretim (unit production) $X \to Y$ biçimindedir: bir değişken başka bir değişken üretir ve kuralda başka bir şey yoktur; iki tarafta da tek bir değişken vardır.

Örnek gramer: $S \to aA$, $A \to a$, $A \to B$, $B \to A$, $B \to bb$. Burada $A \to B$ ve $B \to A$ birim üretimlerdir. Bunlar tek adımda atılamaz; yerine koymalar tek tek yapılmalıdır. <!-- BELİRSİZ: Başlangıç grameri incelenen karelerde görünmüyor; altyazıdaki adımlar ve 00:50:00 karesindeki son gramerle kuruldu. -->

Önce $A \to B$ atılır. Geri kalan kuralların sağ tarafında iki $A$ vardır. $S \to aA$ için $A$ yerine $B$ yazılır: $S \to aA \mid aB$. $B \to A$ için de: $B \to A \mid B$. Yeni kurallar eklendikten sonra $A \to B$ silinir.

Sonra $B \to B$ kuralı görülür. Bir değişkenin kendisini üretmesi hiçbir bilgi vermez; hiçbir şey yapmadan doğrudan silinir.

Kalan birim üretim $B \to A$'dır. $S \to aA \mid aB$ kuralındaki $B$ yerine $A$ yazılarak $S \to aA \mid aB \mid aA$ elde edilir ve $B \to A$ silinir. Şimdi $aA$ seçeneği iki kez tekrar eder; tekrarlanan kural yeni bilgi vermediği için doğrudan silinir (ekrandan, 00:50:00). Son gramer:

$$S \to aA \mid aB, \qquad A \to a, \qquad B \to bb$$

## 6. Gereksiz değişken ve üretimlerin atılması

Atılmak istenen bir başka üretim türü gereksiz üretimlerdir (useless productions).

### 6.1 Hiç sonlanmayan türetim

Gramer (ekrandan, 01:05:00):

$$S \to aSb, \quad S \to \varepsilon, \quad S \to A, \quad A \to aA$$

$A$ için tek kural $A \to aA$'dır. $S \to A$ ile $A$'ya geçilir, $A$, $aA$ üretir; bu $A$ yerine yine $aA$ konur ve bu böyle sürer: $S \Rightarrow A \Rightarrow aA \Rightarrow aaA \Rightarrow \cdots$. $A$'dan hiçbir zaman kurtulunamaz; bu türetim hiçbir zaman yalnız bitiş sembollerinden oluşan bir dizge vermez. Bu yüzden $A \to aA$ gereksizdir.

### 6.2 Ulaşılamayan değişken

İkinci örnekte $S$'den bir şekilde $A$'ya ulaşılır; $A$, $aA$ üretir ve $A \to \varepsilon$ ile sonlanır. Ama $S$'den başlandığında hiçbir zaman $B$ elde edilemez. Bu yüzden $B$'nin kuralı yine gereksizdir. <!-- BELİRSİZ: Bu örneğin kuralları incelenen karelerde görünmüyor; büyük olasılıkla S → A, A → aA | ε, B → bA'dır. -->

### 6.3 Tanım

Önce yararlı tanımlanır: başlangıç değişkeninden başlayıp yerine koymalar yapıldığında, içinde değişken olmayan, yalnız bitiş sembollerinden oluşan bir dizgeye, yani gramerin dilindeki bir dizgeye ulaşılırken $A$ değişkeni kullanılabiliyorsa $A$ yararlıdır (useful). Aksi halde $A$ gereksizdir (useless). Bir üretimin değişkenlerinden herhangi biri gereksizse üretim de gereksizdir.

Ekrandaki örnek (ekrandan, 01:10:00):

$$S \to aSb, \quad S \to \varepsilon, \quad S \to A, \quad A \to aA, \quad B \to C, \quad C \to D$$

$A$ gereksizdir, çünkü hiçbir zaman sonlanmaz. $B$ gereksizdir, çünkü $S$'den $B$'ye hiç ulaşılamaz; $B$'ye ulaşılamadığı için $C$'ye de ulaşılamaz. Dolayısıyla $A$, $B$, $C$ (ve ekranda $D$) gereksizdir. $A$ gereksiz olduğu için $S \to A$ üretimi de gereksizdir; ekranda $S \to A$, $A \to aA$, $B \to C$ ve $C \to D$ üretimlerinin hepsi gereksiz olarak işaretlendi.

### 6.4 Gereksizleri atma yöntemi

Gereksizler sistemi, grameri karmaşıklaştırdığı için atılmak istenir. Örnek gramer (ekrandan, 01:15:00):

$$S \to aS \mid A \mid C, \quad A \to a, \quad B \to aa, \quad C \to aCb$$

Önce tersi yapılır: yararlı değişken ve üretimler bulunur. Sonunda yalnız bitiş sembolleri ya da boş dize kalması istenir; yani yerine koymalardan sonra bütün değişkenlerden kurtulmak gerekir.

**Birinci aşama (round 1).** Yalnız bitiş sembolü ya da boş dize üreten kurallar aranır. $A \to a$ bir bitiş sembolüyle, $B \to aa$ bir bitiş dizisiyle biter. Bu yüzden $A$ ve $B$ seçilir. Sonra $S$ de eklenir, çünkü $S \to A$ vardır: elde olan değişkenleri üreten her değişken listeye eklenir. Böylece $A$'yı, $B$'yi ya da $S$'yi üreten bir değişken olup olmadığı denetlenir. Olası yararlı değişkenler $\{A, B, S\}$'dir. Bunların dışındaki değişkenleri kullanan üretimler silinir: $S \to C$ silinir, çünkü $C$ listede yok; $C \to aCb$ de silinir. Sonuç (ekrandan, 01:15:00):

$$S \to aS \mid A, \quad A \to a, \quad B \to aa$$

**İkinci aşama.** Düğümleri değişkenler olan bir bağımlılık grafiği (dependency graph) çizilir ve $S$'den ulaşılabilen değişkenler bulunur. $S \to aS$ ile $S$ kendini üretir, yani $S$ üzerinde bir döngü vardır. $S \to A$ ile $S$'den $A$'ya bir kenar çizilir. $A \to a$ bir bitiş sembolü üretir; bağımlılık grafiğinde bitiş sembolleri yazılmaz, bunun için kenar eklenmez. $B \to aa$ için de kenar eklenmez; yalnız $B$ değişkeni için bir düğüm vardır. Grafik (ekrandan, 01:15:00):

```text
S -> S   (döngü)
S -> A
B        (gelen kenar yok: S'den ulaşılamaz)
```

$S$'den $A$'ya ulaşılır ama $B$'ye hiçbir zaman gidilemez; $B$ ulaşılamazdır (unreachable), dolayısıyla gereksizdir. $B$'yi içeren kural silinir. Sonuç gramer yalnız yararlı değişken ve üretimleri içerir:

$$S \to aS \mid A, \qquad A \to a$$

Başlangıçta altı kural ve dört değişken ($A$, $B$, $C$, $S$) vardı; sonunda üç kural ve iki değişken kaldı. Çok daha basittir.

### 6.5 Sadeleştirme sırası

Genel olarak hepsi yapılmak istenir: önce boşalabilir değişkenler (null üretimler), sonra birim üretimler, sonra gereksiz değişkenler atılır. <!-- BELİRSİZ: Hoca bu sıranın bir adı olduğunu söyledi ama altyazının bu kısmı (01:18:17-01:18:30) bozuk; ad okunamadı. -->

## 7. Chomsky normal formu

### 7.1 Tanım ve örnekler

Bir gramerin her üretimi şu iki biçimden birindeyse gramer Chomsky normal formundadır (Chomsky normal form, CNF):

$$A \to BC \quad \text{(iki değişken)} \qquad \text{ya da} \qquad A \to a \quad \text{(tek bitiş sembolü)}$$

Örnekler (ekrandan, 01:20:00):

| Gramer 1 | Gramer 2 |
|---|---|
| $S \to AS$ | $S \to AS$ |
| $S \to a$ | $S \to AAS$ |
| $A \to SA$ | $A \to SA$ |
| $A \to b$ | $A \to aa$ |
| Chomsky normal formunda | Chomsky normal formunda değil |

Birinci gramerde her kural ya iki değişken ya tek bitiş sembolü üretir; hepsi uygun CNF üretimleridir. İkinci gramerde $S \to AS$ ve $A \to SA$ uygundur, ama $S \to AAS$ üç değişken, $A \to aa$ iki bitiş sembolü içerir; bu yüzden CNF'de değildir.

### 7.2 Dönüşüm örneği

CNF'ye dönüştürmek aslında oldukça basittir; yeni değişkenler eklenir. Gramer (ekrandan, 01:25:00):

$$S \to ABa, \quad A \to aab, \quad B \to Ac$$

Bitiş sembolleri $a$, $b$, $c$'dir. Her biri için yeni bir değişken eklenir: $a$ için $T_a$, $b$ için $T_b$, $c$ için $T_c$. Her biri tek bir değişkendir. Kurallar bu değişkenlerle yeniden yazılır: $a$ yerine $T_a$, $aab$ yerine $T_a T_a T_b$, $c$ yerine $T_c$:

$$S \to ABT_a, \quad A \to T_a T_a T_b, \quad B \to AT_c, \quad T_a \to a, \quad T_b \to b, \quad T_c \to c$$

Yeni eklenen $T_a \to a$, $T_b \to b$, $T_c \to c$ kuralları CNF'dedir (tek değişken, tek bitiş sembolü). $B \to AT_c$ da uygundur (tek değişkenden iki değişken). Üç değişkenli kurallar ise bölünmelidir.

$S \to ABT_a$ yerine yeni bir $V_1$ değişkeniyle $S \to AV_1$ ve $V_1 \to BT_a$ yazılır; eski kural silinir. Kural iki parçaya bölünmüş olur ve yeni parçaların ikisi de iki değişkenlidir. Aynısı $A$ için yapılır: $V_1$ kullanıldığı için yeni değişkenin adı $V_2$ olur: $A \to T_a V_2$, $V_2 \to T_a T_b$ (ekrandan, 01:25:00). Son gramer:

$$S \to AV_1, \quad V_1 \to BT_a, \quad A \to T_a V_2, \quad V_2 \to T_a T_b, \quad B \to AT_c, \quad T_a \to a, \quad T_b \to b, \quad T_c \to c$$

Daha çok kural vardır ama kurallar standart biçimdedir: ya değişken bir bitiş sembolü ya da iki değişken üretir.

### 7.3 Genel yöntem

Boş dize üretmeyen ve CNF'de olmayan herhangi bir bağlamdan bağımsız gramerden şu yöntemle eşdeğer bir CNF grameri elde edilir:

- İlk temizlik yapılır: boşalabilir değişkenler, birim üretimler ve isteğe bağlı olarak gereksiz değişkenler atılır.
- Her $a$ bitiş sembolü için yeni bir $T_a$ değişkeni eklenir ve $T_a \to a$ üretimi kurallara eklenir. Diğer kurallarda $a$ görülen her yere $T_a$ yazılır. Zaten $A \to a$ biçiminde olan bir kural için $T_a$ eklemeye gerek yoktur; o kural istenen biçimdedir.
- Bundan sonra iki tür kural kalır: $T_a \to a$ gibi kurallar ya da $A \to C_1 C_2 \cdots C_n$ gibi $n$ değişkenli kurallar. Üç ya da daha çok değişkenli her kural ara değişkenlerle ikişerli kurallara bölünür:

$$A \to C_1 V_1, \quad V_1 \to C_2 V_2, \quad V_2 \to C_3 V_3, \quad \ldots, \quad V_{n-2} \to C_{n-1} C_n$$

### 7.4 CNF neden öğrenildi?

CNF ayrıştırma (parsing) ve bazı teoremlerin ispatı için iyidir. Boş dize üretmeyen her bağlamdan bağımsız gramer için CNF'yi bulmak kolaydır (ekrandan, 01:30:00). Hoca, gramer boş dize üretiyorsa, yani başlangıç değişkeni boş dize üretiyorsa, gramerin CNF'ye çevrilemeyeceğini; bu olmazsa kolayca çevrilebileceğini ve elde edilen gramerin ayrıştırmada, teorem ispatında ya da programlarda kullanılabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Sipser'in kitabındaki CNF tanımı, yalnız başlangıç değişkeni için $S \to \varepsilon$ kuralına izin verir (başlangıç değişkeni sağ tarafta görünmemek şartıyla). Bu tanımla boş dizeyi içeren diller de CNF gramerle üretilebilir; slaytlardaki tanım bu istisnayı içermez.

## 8. Greibach normal formu

Benzer bir normal form Greibach normal formudur (Greibach normal form, GNF). Bu formda bütün üretimler şu biçimde olmalıdır (ekrandan, 01:30:00):

$$A \to a V_1 V_2 \cdots V_k, \qquad k \ge 0$$

Başta bir bitiş sembolü, ardından bir miktar değişken gelir. $k$ sıfır ya da daha çok olabilir; hiç değişken olmaması da kabul edilir.

İlk örnek gramerde kurallar sırasıyla "bitiş sembolü ve değişkenler", "bitiş sembolü ve tek değişken", "bitiş sembolü ve tek değişken", "bitiş sembolü ve değişken yok", yine "bitiş sembolü ve değişken yok" biçimindeydi; bu gramer GNF'dedir. Sağdaki gramer GNF'de değildir: bir kuralda baştaki bitiş sembolünden sonra ikinci bir bitiş sembolü, başka bir kuralda baştaki bitiş sembolünden sonra iki bitiş sembolü daha vardır. GNF'de bitiş sembolleri yalnız başta olabilir ve her üretimde tek bir bitiş sembolü bulunur. <!-- BELİRSİZ: GNF örnek gramerlerinin kuralları incelenen karelerde görünmüyor; büyük olasılıkla Busch slaytlarındaki S → cAB, A → aA | bB | b, B → b (GNF'de) ve S → abSb, S → aa (GNF'de değil) gramerleridir. -->

Dönüşüm için yine $T_a \to a$, $T_b \to b$ gibi yeni değişkenler eklenir; baştaki dışında kalan her bitiş sembolünün yerine bu değişkenler yazılır. Örneğin, büyük olasılıkla slayttaki gramer için, $S \to abSb \mid aa$ kuralları $S \to a T_b S T_b \mid a T_a$, $T_a \to a$, $T_b \to b$ olur (ara adım eklendi).

GNF neden gereklidir? Slayta göre dizgeleri ayrıştırmak için çok iyidir, hatta CNF'den daha iyidir. Slaytta bir gramerin GNF'sini bulmanın zor olduğu da yazar (ekrandan, 01:35:00); hoca bunun neden zor sayıldığını anlamadığını, kendisine çok kolay geldiğini söyledi.

> **Ders sonrası not:** Derste görülen örnekte bütün kurallar zaten bir bitiş sembolüyle başladığı için dönüşüm kolaydı. Genel durumda bir kuralın sağ tarafı bir değişkenle başlıyorsa (örneğin $A \to BC$ ya da sol özyinelemeli $A \to Aa$), önce bu değişkenlerin yerine konması ve sol özyinelemenin kaldırılması gerekir; slayttaki "zordur" ifadesi büyük olasılıkla bu genel durumu kastediyor.

### 8.1 Bölümün Türkçe özeti

Hoca bu kısmı Türkçe toparladı: gramerleri temizlemek, yani gereksiz üretim kurallarını bulup yok etmek; boş dize üreten null üretimleri yok etmek; bir değişkenin başka bir değişkeni ürettiği birim üretimleri yok etmek. Ardından iki normal form öğrenildi: Chomsky normal formu ve Greibach normal formu. Bu formlar, bir programın ayrıştırılması sırasında ya da bazı teorem ispatlarında daha faydalıdır. Genel yaklaşım, ek değişkenler ekleyip bunlarla gramere CNF ya da GNF biçimi vermektir. CNF'de her üretim ya bir değişkenden tek bir bitiş sembolü ya da iki değişken üretir; GNF'de her üretim bir başlangıç bitiş sembolü ve sonrasında sıfır ya da daha çok değişkenden oluşur.

> **Hocanın vurgusu:** Bir gramer verip CNF ya da GNF karşılığını çıkarmak, gramerden null üretimleri ya da birim üretimleri çıkarmak gibi sorular sınavda çıkabilir. Bu tür alıştırmaları çözmeniz tavsiye edilir.

## 9. Yığıtlı otomatlar (PDA)

### 9.1 Yapı

Yeni bir otomat türü: yığıtlı otomat (pushdown automaton, PDA). Şimdiye kadar öğrenilen DFA ve NFA'lara çok benzer (ekrandan, 01:55:00). Yine bir giriş dizgisi vardır ve sembollerin giriş dizgisinden okunması gerekir. Bir kontrol birimi vardır; kontrol biriminde durumlar, durum geçişleri, ret ve kabul durumları, başlangıç durumu bulunur. Bunlara ek olarak bir yığıt (stack) vardır ve kontrol birimi yığıta yazıp yığıttan okuyabilir.

Yığıt, en üstten okunan ya da en üstten çıkarılan (pop) bir veri yapısıdır. Normal bir bellek değildir; yığıt olarak kullanılmalıdır, yani ona yalnız sembol eklenebilir (push) ya da ondan sembol çıkarılabilir (pop).

Başlangıçta yığıtta özel bir sembol olduğu varsayılır; bu sembol yığıtın dibindedir. Örnekte bu $\$$ işaretidir. Sıfır anında, yani hiçbir giriş okunmadan önce $\$$ oradadır. $\$$ kullanmak zorunlu değildir; alfabeye bağlıdır, alfabede olmayan bir sembol olmalıdır. Sembol çıkarılırken $\$$ çıkarılırsa bu, yığıtın dibine ulaşıldığını ve artık çıkarılmaması gerektiğini söyler. Bazı kaynaklarda bunun yerine $z$ kullanılır.

### 9.2 Geçişler

Diğer otomatlar gibi PDA'da da durumlar vardır ($q_1$, $q_2$ gibi). Durum geçişlerine üç şey yazılır (ekrandan, 02:00:00):

$$q_1 \xrightarrow{\;a,\ b\ \to\ c\;} q_2$$

Önce girişten okunacak sembol ($a$) yazılır ve arkasına virgül konur. Sonra yığıttan çıkarılacak sembol ($b$) yazılır. Bu geçiş şu üç koşul doğruysa gerçekleşir: o anda $q_1$'deyiz, girişten $a$ okunuyor ve yığıttan $b$ çıkarılabiliyor. Üçü de doğruysa $q_2$'ye geçilir ve geçerken yığıta yeni bir sembol ($c$) eklenir.

Ekrandaki örnekte okuma kafası bir $a$'yı gösteriyor, durum $q_1$, yığıt içeriği üstten alta $b, h, e, \$$ ve en üstte $b$ var. Bu adımda $a$ okunur, yığıtın üstündeki $b$ çıkarılır; üç koşul da sağlanmıştır. $q_2$'ye geçilir ve yığıta $c$ eklenir: $b$ çıkarılıp yerine $c$ konmuş olur (replace). Yeni yığıt üstten alta $c, h, e, \$$'dır (ekrandan, 02:00:00).

$\varepsilon$ ile yazılan durumlar:

- $a, \varepsilon \to c$: hiçbir şey çıkarılmaz, yalnız eklenir (push). Geçiş iki koşula bağlıdır: $q_1$'de olmak ve girişten $a$ okumak. Yığıtta ne olduğu önemsizdir. Geçişle $q_2$'ye gidilir ve yığıta $c$ eklenir.
- $a, b \to \varepsilon$: hiçbir şey eklenmez, yalnız çıkarılır (pop). Üç koşul gerekir: $q_1$'de olmak, $a$ okumak ve yığıtın üstünde $b$ bulunması; $b$ çıkarılır. Yığıttaki eleman sayısı azalır.
- $a, \varepsilon \to \varepsilon$: ne çıkarılır ne eklenir. İki koşul vardır: $q_1$'de olmak ve $a$ okumak. Yığıta dokunulmaz.

### 9.3 Determinizm olmayışı

PDA'lar deterministik değildir (ekrandan, 02:05:00). Bunun iki nedeni vardır.

Birincisi, aynı giriş ve yığıt koşulu için farklı durumlara gidilebilir: $q_1$'den $a, b \to c$ etiketiyle hem $q_2$'ye hem $q_3$'e geçiş olabilir. Bu aynı geçişe benzer ama aynı anda iki farklı duruma girilir. NFA'lardaki gibi paralel makineler vardır; makine kendini çoğaltır.

İkincisi, null geçişine izin verilir: hiçbir şey okumadan geçiş yapılabilir. Bu durumda okunacak sembolün yerine $\varepsilon$ yazılır, örneğin $q_1 \xrightarrow{\varepsilon,\ b\ \to\ c} q_2$. Bu geçiş $q_1$'deyken, hiçbir şey okumadan, yığıttan $b$ çıkarılabiliyorsa gerçekleşir.

> **Ders sonrası not:** Altyazıda bazı yerlerde "copy" geçiyor; bağlamdan anlaşıldığı gibi kastedilen yığıttan çıkarmadır (pop).

## 10. PDA örneği: $a^n b^n$

PDA $M$'nin dili

$$L(M) = \{a^n b^n : n \ge 0\}$$

olsun, yani $a$ sayısı ile $b$ sayısı aynı olan $ab$, $aabb$ gibi dizgeler. PDA bu dizgeleri kabul etmeli; bir şekilde $a$ ve $b$ sayılarının sayılması ya da eşleştirilmesi gerekir. Temel fikir (ekrandan, 02:10:00):

1. Okunan $a$'ları yığıta koy.
2. Girişteki $b$'leri yığıttaki $a$'larla eşleştir.
3. Eşleşme bulundu: kabul et.

Geçişler (ekrandan, 02:10:00):

| Kaynak | Etiket (oku, çıkar $\to$ ekle) | Hedef |
|---|---|---|
| $q_0$ (başlangıç, kabul) | $\varepsilon, \varepsilon \to \varepsilon$ | $q_1$ |
| $q_1$ | $a, \varepsilon \to a$ | $q_1$ |
| $q_1$ | $b, a \to \varepsilon$ | $q_2$ |
| $q_2$ | $b, a \to \varepsilon$ | $q_2$ |
| $q_2$ | $\varepsilon, \$ \to \$$ | $q_3$ (kabul) |

$a$'lar okunurken hiçbir şey çıkarılmaz, $a$'lar yığıta eklenir; $q_1$ üzerindeki döngü bunu yapar. Bir $b$ okununca $a$'lar bitmiş, $b$'ler başlamış demektir: bir $a$ çıkarılır, hiçbir şey eklenmez ve $q_2$'ye geçilir. $q_2$ üzerindeki döngüyle her $b$ için yığıttan bir $a$ çıkarılır. $b$ sayısı $a$ sayısına eşitse son $b$ okunduğunda son $a$ da çıkarılır ve yığıtta yalnız dipteki özel sembol $\$$ kalır. $q_2 \to q_3$ geçişi bunu denetler: girişten bir şey okumadan, yığıtta $\$$ varsa $\$$'ı yerinde bırakıp kabul durumuna gidilir. Kabul için girişin tamamı okunmuş, okunacak bir şey kalmamış olmalı ve yığıtın dibinde olunmalıdır.

Başlangıç durumu da kabul durumudur. Bunun nedeni $n$'nin sıfır olabilmesidir: $a^0 b^0$ boş dizedir, yani dil boş dizeyi içerir. Hiçbir giriş yoksa makine kabul eder. Ayrıca null geçişi nedeniyle $q_1$ de hemen etkinleşir: sıfır anında, hiçbir şey okunmadan iki durum etkindir, $q_0$ ve $q_1$. $q_0$ kabul durumu olduğu için makine hiçbir şey okumadan kabul eder. Sonra bir $a$ okunursa $q_0$ onu alamaz ($q_0$'dan $a$ ile çıkan geçiş yoktur) ve ölür; $q_1$ ise döngüsü sayesinde $a$'yı alır ve $q_1$'de kalır. $a$'lar okundukça $q_1$'de kalınır; bir $b$ okununca $b$'lerin başladığı anlaşılır ve $q_2$'ye geçilir.

### 10.1 Kabul edilen giriş: $aaabbb$

Giriş üç $a$ ve üç $b$'dir. Hiçbir şey okunmadan $q_0$ ve $q_1$ etkindir (hoca, slayttaki resmin $q_0$'ın da etkin olduğunu göstermediğini belirtti). Birinci $a$ okunur ve yığıta eklenir; ikinci ve üçüncü $a$ da eklenir. Ardından her $b$ için bir $a$ çıkarılır. Son $b$ okunduktan sonra iki durum etkindir: $q_2$ ve $q_3$, çünkü $q_2 \to q_3$ bir $\varepsilon$ geçişidir. İkisinin de yığıtı aynıdır (yalnız $\$$); genel durumda paralel makinelerin yığıtları farklı olabilir. $q_3$ kabul durumu olduğu ve giriş bittiği için dizge kabul edilir.

Bir dizge şu durumda kabul edilir: girişin tamamını tüketen ve son durumu kabul durumu olan bir hesaplama dalı (computation) vardır. Kabul eden hesaplamanın sonunda yığıtta ne kaldığı önemsizdir; yalnız girişin tamamının tüketilip tüketilmediğine ve kabul durumunda olunup olunmadığına bakılır.

### 10.2 Reddedilen giriş: $aab$

Burada $a$ sayısı $b$ sayısından fazladır. Sıfır anında $q_0$ ve $q_1$ etkindir. Bir $a$ okunur ve yığıta eklenir; ikinci $a$ da eklenir; $b$ okunur ve bir $a$ çıkarılır. Artık $q_2$'deyiz. $q_3$'e ulaşılabilir mi? Hayır, çünkü bunun için yığıtın üstünde $\$$ görülmelidir, ama yığıtın üstünde $a$ vardır. $q_2$'de kalınır. Girişin tamamı okunmuştur ve $q_2$ kabul durumu değildir; dizge reddedilir.

## 11. PDA örneği: $v v^R$ ve paralel makineler

Bu sefer PDA $M$'nin dili, bir ilk kısım ve onun tersinden oluşan dizgelerdir; semboller alfabeden gelir (ekrandan, 02:30:00):

$$L(M) = \{ v v^R : v \in \{a, b\}^* \}$$

Geçişler (ekrandan, 02:30:00):

| Kaynak | Etiket | Hedef |
|---|---|---|
| $q_0$ (başlangıç) | $a, \varepsilon \to a$ | $q_0$ |
| $q_0$ | $b, \varepsilon \to b$ | $q_0$ |
| $q_0$ | $\varepsilon, \varepsilon \to \varepsilon$ | $q_1$ |
| $q_1$ | $a, a \to \varepsilon$ | $q_1$ |
| $q_1$ | $b, b \to \varepsilon$ | $q_1$ |
| $q_1$ | $\varepsilon, \$ \to \$$ | $q_2$ (kabul) |

Başlangıç durumu kabul durumu değildir; $q_1$ de değildir; $q_2$ kabul durumudur.

### 11.1 Boş dize kabul edilir mi?

**Soru (hocanın sınıfa sorusu):** Burada boş dize kabul edilir mi?
**Cevap (bir öğrenci):** Evet. Başlangıçta $q_0$ etkindir; $q_0$'dan hiçbir şey okumadan $q_1$'e geçilir. $q_1$'den de bir şey okumak gerekmez; yığıtta $\$$ görülmesi gerekir ve başlangıçta yığıtta zaten $\$$ vardır. Dolayısıyla $q_2$ de etkin olur ve giriş bittiği için kabul edilir. Hoca bunu doğruladı: hiçbir şey okunmadan üç durumun üçü de ($q_0$, $q_1$, $q_2$) etkindir. Bunlar aslında birer geçiş değil, eklemedir; şu anda üç durum birlikte etkindir.

### 11.2 Tek $a$ ve her makinenin kendi yığıtı

Ardından tek bir $a$ girişi ele alındı. Hoca önce bir izleme denedi ve tek $a$'yı yanlışlıkla kabul ettirdi; bunun üzerine durup düşünce biçimini yeniden kontrol etti. Doğru izlemenin kilit noktası şudur: makine kendini çoğaltırken her kopya yığıtın bir kopyasını alır; makineler yığıtlarını paylaşmaz.

Doğru izleme:

- Hiçbir şey okunmadan: $(q_0, \$)$, $(q_1, \$)$, $(q_2, \$)$ etkindir. $q_2$ kabul durumu olduğu için boş dize kabul edilir.
- $a$ okunur. $q_0$, $a$'yı alır, hiçbir şey çıkarmaz, yığıta $a$ ekler ve yine $q_0$'a gider: $(q_0, a\$)$.
- $q_1$ de $a$'yı almaya çalışır, ama kendi yığıtında yalnız $\$$ vardır, $a$ yoktur. $a, a \to \varepsilon$ geçişi çalışmaz; bu $q_1$ ölür.
- $q_2$ zaten hiçbir sembol almaz; o da ölür.
- $(q_0, a\$)$, null geçişi ile kendini $q_1$'e çoğaltır; kopya yığıtı da alır: $(q_1, a\$)$.
- Bu $q_1$'den $q_2$'ye geçiş var mı? Yok, çünkü bunun için yığıtın üstünde $\$$ olmalıdır, ama üstte $a$ vardır.

Tek $a$ okunduğunda elde iki durum kalır: $(q_0, a\$)$ ve $(q_1, a\$)$. $q_2$ etkin olamaz; dizge kabul edilmez. Hoca, düşünce biçiminde bir sorun olmadığını, yalnız yığıtların ayrı tutulması gerektiğini belirtti.

### 11.3 $aa$ girişi

İkinci bir $a$ okunduğunda bu $a$, $q_0$'a ve $q_1$'e ayrı ayrı gönderilir (ekrandan, 02:35:00):

- $(q_0, a\$)$, $a$'yı alır ve yığıtına $a$ ekler: $(q_0, aa\$)$.
- $(q_1, a\$)$, $a$'yı okur, bir $a$ çıkarır, hiçbir şey eklemez ve $q_1$'e döner: $(q_1, \$)$. Yığıtı boşalmış, yalnız $\$$ kalmıştır.
- $q_0$'dan null geçişi ile, hiçbir şey yapmadan, bir $q_1$ daha elde edilir: $(q_1, aa\$)$.
- Bu iki $q_1$ farklı makinelerdir: ikisi de $q_1$ durumunda olsa da yığıtları farklıdır, bu yüzden davranışları da farklı olur.
- Üstteki $(q_1, \$)$'ın yığıtında $\$$'dan başka bir şey yoktur; $q_2$'ye geçiş gerçekleşir ve yığıt değişmez: $(q_2, \$)$. $q_2$ kabul durumudur.
- $(q_1, aa\$)$'tan $q_2$'ye geçilemez, çünkü yığıtta iki $a$ vardır.

$aa$ okunduğunda dört etkin makine vardır: $(q_0, aa\$)$, $(q_1, aa\$)$, $(q_1, \$)$ ve $(q_2, \$)$. Paralel çalışan dört makine vardır ve $q_2$ kabul durumu olduğu için $aa$ kabul edilir. Bütün bu makineleri ve yığıtlarını birlikte düşünmek gerekir.

### 11.4 Genel çalışma

$q_0$ üzerindeki ilk döngü, ilk kısmı ($v$'yi) yığıta koyar: ne okunursa $q_0$ onu yığıta ekler. Her girişte null geçişi nedeniyle $q_1$ de etkinleşir. $q_1$, okunan her sembol için yığıtın üstünde aynı sembol varsa onu çıkarır; yani okunan şeyin yığıttakiyle aynı olup olmadığını denetler, bir eşleştirme yapar.

Yığıt son giren ilk çıkar (last in, first out, LIFO) olduğu için bu denetim $v$'nin tersini denetler. Bir öğrenci düzeltmesiyle netleştirildi: son konan ilk çıkar, dolayısıyla ilk konan son çıkar (first in, last out). Yığıt sırayı tersine çevirdiği için ikinci okunan kısmın birincinin tersine eşit olup olmadığı denetlenmiş olur. Girişin sonunda yığıtta $\$$'dan başka bir şey yoksa eşleşme vardır.

### 11.5 Kabul edilen giriş: $abba$

Giriş $abba$'dır ve otomat bunu kabul etmelidir. Yığıtta yalnız $\$$ var, başlangıç durumu $q_0$. $a$ okunur ve yığıta eklenir; $b$ okunur ve yine eklenir. Yığıt üstten alta $b, a, \$$'dır (ekrandan, 02:40:00). Slayt, $\varepsilon, \varepsilon \to \varepsilon$ geçişinin dizgenin ortasını "tahmin ettiğini" (guess the middle of string) söyler. Hoca, kendi anlayışının çoklu makinelere dayandığını, slaytın ise bu ayrıntıyı önemsemeden daha genel anlattığını belirtti.

$q_1$'de bir değer okunduğunda onun yığıtta bulunup çıkarılması umulur. Üçüncü sembol $b$ okunur ve yığıttaki $b$ çıkarılır; böylece bu $b$, ikinci $b$ ile eşleşmiş olur. Sonra $a$ okunur ve yığıtta bir $a$ bulunur; bu $a$ ilk $a$'dan gelmiştir, yani son $a$ ilk $a$ ile eşleşir. Eşleşmenin tersten yapıldığı böylece görülür. Sonunda yığıt boş olduğu için (yalnız $\$$) $q_2$'ye geçilir ve dizge kabul edilir.

### 11.6 Reddedilen giriş: $abbb$

Giriş $abbb$'dir ve reddedilecektir. $a$ okunup yığıta, $b$ okunup yığıta eklenir. Ortanın tahmin edildiği hesaplamada üçüncü sembol $b$ okunur ve yığıtta bir $b$ görülüp çıkarılır; bu $b$ ikinci $b$ ile eşleşir. Ama dördüncü $b$ okunduğunda yığıtta $a$ vardır; $b, b \to \varepsilon$ kuralı çalışmaz, aslında çalışabilecek hiçbir kural yoktur. Bu durum girişi tüketemez ve kabul durumu değildir; dizge bu hesaplamada reddedilir.

Slaytta aynı dizge üzerinde başka bir hesaplama da gösterilir. Hoca bunu, bütün paralel makinelerin ve durumlarının bir hesaplama oluşturduğu biçiminde açıkladı. Bu hesaplamada null geçişi hiç kullanılmaz: her sembol $q_0$ döngüsüyle yığıta eklenir ve durum $q_0$'da kalır. Giriş tüketilmiş olsa da kabul durumuna ulaşılmaz; yine ret.

Sonuçta $abbb$'yi kabul eden hiçbir hesaplama yoktur, yani $abbb \notin L(M)$ (ekrandan, 02:45:00).

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): $E \to E + E \mid E * E \mid (E) \mid a$ gramerinde $a + a * a$ dizgesinin iki farklı soldan üretimini yazın. $a = 2$ için her ağaç hangi değeri verir?

> **Çözüm:** Birinci soldan üretim: $E \Rightarrow E + E \Rightarrow a + E \Rightarrow a + E * E \Rightarrow a + a * E \Rightarrow a + a * a$; ağaç $a + (a * a)$ yapısındadır ve $2 + 4 = 6$ verir. İkinci soldan üretim (ekrandaki): $E \Rightarrow E * E \Rightarrow E + E * E \Rightarrow a + E * E \Rightarrow a + a * E \Rightarrow a + a * a$; ağaç $(a + a) * a$ yapısındadır ve $4 \cdot 2 = 8$ verir. İki farklı ağaç olduğu için gramer belirsizdir.

**Soru 2** (ekrandan, 01:20:00): Aşağıdaki gramerlerden hangisi Chomsky normal formundadır? (a) $S \to AS$, $S \to a$, $A \to SA$, $A \to b$. (b) $S \to AS$, $S \to AAS$, $A \to SA$, $A \to aa$.

> **Çözüm:** (a) CNF'dedir; her kural ya iki değişken ya tek bitiş sembolü üretir. (b) CNF'de değildir; $S \to AAS$ üç değişken, $A \to aa$ iki bitiş sembolü içerir.

**Soru 3** (ekrandan, 01:25:00): $S \to ABa$, $A \to aab$, $B \to Ac$ gramerini Chomsky normal formuna çevirin.

> **Çözüm:** $S \to AV_1$, $V_1 \to BT_a$, $A \to T_a V_2$, $V_2 \to T_a T_b$, $B \to AT_c$, $T_a \to a$, $T_b \to b$, $T_c \to c$.

**Soru 4** (ekrandan, 01:15:00): $S \to aS \mid A \mid C$, $A \to a$, $B \to aa$, $C \to aCb$ gramerinden gereksiz değişken ve üretimleri atın.

> **Çözüm:** Birinci aşamada bitiş sembolü üretebilen değişkenler $\{A, B, S\}$ bulunur; $C$'yi kullanan $S \to C$ ve $C \to aCb$ silinir. İkinci aşamada bağımlılık grafiğinde $S$'den $B$'ye ulaşılamadığı görülür; $B \to aa$ silinir. Sonuç: $S \to aS \mid A$, $A \to a$.

**Soru 5** (derste sözlü, 02:18:48): $L(M) = \{v v^R : v \in \{a, b\}^*\}$ için verilen PDA'da boş dize kabul edilir mi?

> **Çözüm:** Evet. Hiçbir şey okunmadan $q_0 \to q_1$ ($\varepsilon, \varepsilon \to \varepsilon$) ve yığıtın üstünde $\$$ olduğu için $q_1 \to q_2$ ($\varepsilon, \$ \to \$$) geçişleri gerçekleşir; $q_2$ kabul durumudur ve giriş boştur.

**Soru 6** (ekrandan, 02:35:00): Aynı PDA'da $a$ ve $aa$ girişleri için her adımdaki etkin makineleri (durum, yığıt) listeleyin. Hangisi kabul edilir?

> **Çözüm:** $a$ sonrası: $(q_0, a\$)$, $(q_1, a\$)$; kabul durumu yok, $a$ reddedilir. $aa$ sonrası: $(q_0, aa\$)$, $(q_1, aa\$)$, $(q_1, \$)$, $(q_2, \$)$; $q_2$ kabul durumu olduğu için $aa$ kabul edilir. Bu sonuçlar ve $abba$'nın kabulü, $abbb$'nin reddi, ajan tarafından yazılan küçük bir PDA benzetimiyle doğrulandı.

## Dersin Toparlaması

Ders, önceki derste başlanan bağlamdan bağımsız gramerlerin tekrarıyla açıldı: gramerin dörtlü tanımı, gramerin dili, soldan ve sağdan üretim, üretim ağaçları ve aynı dizgenin iki farklı ağacı olmasıyla ortaya çıkan belirsizlik. Belirsizliğin bazen gramer yeniden yazılarak giderilebildiği, bazen ise dilin kendisinin doğası gereği belirsiz olduğu görüldü. Yeni konu olarak gramerlerin sadeleştirilmesi işlendi: yerine koyma kuralı, null üretimlerin, birim üretimlerin ve gereksiz değişkenlerin atılması. Ardından ayrıştırma ve teorem ispatı için kullanışlı iki normal form, Chomsky normal formu ve Greibach normal formu, ve bunlara ek değişkenlerle dönüşüm öğrenildi.

Dersin son bölümünde bağlamdan bağımsız dilleri tanımanın ikinci yolu olan yığıtlı otomatlara başlandı. PDA'nın NFA'ya bir yığıt eklenmiş hali olduğu, geçişlerin "oku, çıkar, ekle" üçlüsüyle yazıldığı, PDA'ların deterministik olmadığı ve kabulün girişin tükenip bir dalın kabul durumunda bitmesine bağlı olduğu görüldü. $a^n b^n$ ve $v v^R$ örnekleri adım adım izlendi; özellikle çoğalan her makinenin kendi yığıt kopyasını taşıdığı vurgulandı. Yığıtlı otomatlar üzerinde sonraki derste durulmaya devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
