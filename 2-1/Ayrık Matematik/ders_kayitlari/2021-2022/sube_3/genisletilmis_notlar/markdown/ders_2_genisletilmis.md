# Ders 2 Genişletilmiş Notu: İspat Yöntemleri ve Boole Cebrine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İspatın Yapı Taşları
- 2. Doğrudan İspat
- 3. Dolaylı İspat (Karşıt Tersle İspat)
- 4. Tümevarımla İspat
- 5. Çelişkiyle İspat
- 6. Aksine Örnek ve Deneme Yoluyla İspat
- 7. Tümevarımla Bir Algoritma Karşılaştırması: $3n < n!$
- 8. Boole Cebrinin Donanım Temeli
- 9. Boole İşlemleri ve Lojik Kapılar
- 10. Boole Fonksiyonları
- 11. Boole Cebrindeki Özdeşlikler ve Sadeleştirme
- 12. Çarpımların Toplamı ve Toplamların Çarpımı
- Örnek Sorular

## 1. İspatın Yapı Taşları

Ders, önceki derste görülen karşı örnek konusunun ardından ispat konusuna girişle başladı. İspat, özellikle matematiksel teoremlerin doğruluğunu ya da yanlışlığını göstermek için kullanılır. Bir matematik sisteminde dört temel kavram vardır (ekrandan, 00:15:00).

**Tanımlanmamış terimler (undefined terms)** sistemin temel taşlarıdır. Başka bir kavramdan türetilmezler, başlangıç kavramı olarak kabul edilirler. Öklid geometrisinde nokta ve doğru bunlara örnektir.

**Tanım (definition)**, yeni bir kavram yaratmak amacıyla daha önce kabul edilmiş kavramlardan ya da tanımlanmamış terimlerden kurulan önermedir. Örneğin iki üçgenin karşılıklı kenarları ve açıları birbirine eşitse bu iki üçgen eştir; "eş üçgen" kavramı kenar, açı ve eşitlik kavramlarından türetilir. Benzer biçimde toplamı 180 derece olan iki açıya birbirini tamamlayan açılar denir.

**Aksiyom (axiom)**, matematiksel bir sistem içinde ispat yapılmaksızın doğru kabul edilen önermedir. Slayttaki Öklid geometrisi örnekleri:

- İki nokta verilmiş olsun. Bu noktalardan geçen bir doğru her zaman mevcuttur.
- Bir doğru ve doğru üzerinde yer almayan bir nokta mevcut olsun. Bu noktadan geçen doğruların bir tanesi verilen doğruya mutlaka paraleldir.

Hoca ilk aksiyom için "bunu doğru kabul ediyoruz ama ispatını yapmak sonsuz tane deneme yapmak gibi bir şey" dedi. İkinci aksiyom için de hesaplama açısından bir soru sordu: noktanın koordinatları ve doğrunun eğimi biliniyorsa bu noktadan geçen ve doğruya paralel olan doğru çizilebilir.

**Teorem**, önceden ispatlanmış teoremler, aksiyomlar ve tanımlar kullanılarak ve $p$'nin doğru olduğu farz edilerek doğruluğu gösterilebilen $p \rightarrow q$ biçimindeki önermedir.

## 2. Doğrudan İspat

Doğrudan ispat (direct proof) $p \rightarrow q$ biçimindeki önermelere uygulanır ve üç adımı vardır (ekrandan, 00:20:00):

1. $p \rightarrow q$ için $p$ doğru kabul edilir.
2. $q$ önermesinin doğru olduğu gösterilmeye çalışılır.
3. Gösterilirse $p \rightarrow q$ doğrudur denir.

Hoca $p$'yi doğru kabul etmenin anlamını koşullu önermenin doğruluk tablosuyla açıkladı. $p \rightarrow q$ yalnız $p=1, q=0$ satırında yanlıştır. $p$ doğru kabul edildiğinde geriye $p=1$ olan iki satır kalır ve önermenin doğruluğu tamamen $q$'ya bağlı olur. Bu yüzden $p=0$ satırlarıyla uğraşmaya gerek yoktur.

Doğrudan ispat için $p$ tarafı **basit ve karmaşık olmayan** bir önerme olmalıdır. Hocanın ilk örneği "$n$ tek sayı ise $n^2$ tektir" önermesiydi. Burada $p$: "$n$ tek sayıdır", $q$: "$n^2$ tektir". $q$ tarafı daha karmaşıktır; $p$ doğru kabul edilerek $q$'nun doğruluğu gösterilebilir.

Sonra hoca doğrudan ispatın işlemediği bir örnek verdi: bir $m+n$ toplamının çift olmasından tek tek terimlerin özelliğine geçmek. Toplamın çift olduğunu kabul edip buradan terimlerin kendisine dair bir sonuç çıkaracak matematiksel bir yol yoktur; bu yüzden bu tür bir önerme doğrudan ispatla ispatlanamaz.

<!-- BELİRSİZ: Altyazıda önerme "M artı N çift sayı ise M ... çifttir" biçiminde geçiyor; tam metni karede görünmüyor. -->

> **Ders sonrası not:** "$m+n$ çift ise $m$ ve $n$ çifttir" biçimindeki bir önerme aslında yanlıştır ($m=n=1$ için $m+n=2$ çifttir ama $m$ ve $n$ tektir). Yanlış bir önerme hiçbir yöntemle ispatlanamaz; bu durumda aksine örnek (Bölüm 6) kullanılır. Derste örneğin amacı, karmaşık $p$ tarafından doğrudan sonuç çıkarılamayacağını göstermekti.

### 2.1 Örnek: $n$ çift ise $n^2$ çifttir

Tahtadaki çözüm (ekrandan, 00:25:00):

- $p$: "$n$ çift sayıdır", $q$: "$n^2$ çift sayıdır".
- **1. adım:** $n = 2k$, $k \in \mathbb{Z}$ doğru kabul edilir. Her çift sayı bu biçimde yazılabilir.
- **2. adım:** $n^2 = 4k^2 = 2(2k^2) = 2u$, burada $u = 2k^2$ ve $u \in \mathbb{Z}$. Dolayısıyla $n^2 = 2u$.
- **3. adım:** $n^2 = 2u$ bir çift sayı biçimindedir. $\therefore$ (sonuç olarak, *as a result*, *therefore*) $n^2$ çift sayıdır.

Hoca iki gösterimi de tanıttı: "$\therefore$" (üç nokta, üçgen biçiminde) "sonuç olarak" anlamına gelir; ters çevrilmiş hali "$\because$" ise "çünkü, olduğu için" (*since*) anlamına gelir. İngilizcede cümle *because* ile değil *as* ya da *since* ile başladığı için bu simge *since* olarak okunur. Örneğin "$\because n^2 = 2u$ çift olduğu için" diye yazılabilir.

## 3. Dolaylı İspat (Karşıt Tersle İspat)

Dolaylı ispat (indirect proof), derste Türkçede "olmayana ergi yöntemi" olarak da anıldı. $p \rightarrow q$ biçiminde doğrudan yapılamayan ispatlarda kullanılır; tipik olarak $p$ tarafının karmaşık olduğu, örneğin "$n^2$ tekse $n$ tektir" gibi önermelerde karşımıza çıkar.

Yöntem, önermenin karşıt tersini (contrapositive) ispatlamaktır: $p \rightarrow q$ yerine $\lnot q \rightarrow \lnot p$ yazılır ve bu doğrudan ispat yöntemiyle, aynı üç adımla ispatlanır.

Bunun neden geçerli olduğu bir öğrenciye soruldu: $p \rightarrow q$ ile $\lnot q \rightarrow \lnot p$ mantıksal olarak denktir (logically equivalent), çünkü doğruluk tablolarında bütün satırlar aynıdır. Mantıksal olarak denk iki önermeden birini ispatlamak diğerini ispatlamak demektir. Önceki derste bunun için "bugün pazarsa yarın pazartesidir" ve karşıt tersi "yarın pazartesi değilse bugün pazar değildir" örneği verilmişti.

### 3.1 Örnek: $n^2$ tek ise $n$ tektir

Tahtadaki çözüm (ekrandan, 00:30:00):

- $p$: "$n^2$ tek sayıdır", $\lnot p$: "$n^2$ çift sayıdır".
- $q$: "$n$ tek sayıdır", $\lnot q$: "$n$ çift sayıdır".
- Problem $\lnot q \rightarrow \lnot p$, yani "$n$ çift ise $n^2$ çifttir" önermesine dönüşür.
- **1. adım:** $n = 2k$, $k \in \mathbb{Z}$ doğru kabul edilir.
- **2. adım:** $n^2 = 4k^2 = 2(2k^2)$.
- **3. adım:** $n^2 = 2u$ ($u = 2k^2$) biçimindedir, yani çift tam sayıdır.

Karşıt ters önerme doğru olduğu için asıl önerme $p \rightarrow q$ da doğrudur: $n^2$ tek ise $n$ tektir.

### 3.2 Örnek: $3n+2$ tek ise $n$ tektir

Slayttaki örnek: "$n$ bir tam sayı ve $3n+2$ tek ise $n$'nin tek olduğunu ispatlayınız." Burada $p$ tarafı karmaşıktır.

Önce doğrudan ispat denendi. $3n + 2$ tek olduğundan $3n + 2 = 2k + 1$ yazılır, buradan $3n + 1 = 2k$ bulunur. Ancak bu eşitlikten $n$'nin tek olduğu ispat tekniğiyle gösterilemez; doğrudan ispat burada tıkanır ve bizi dolaylı ispata götürür.

Dolaylı ispatta $n$ çift varsayılır: $n = 2k$ için

$$3n + 2 = 3(2k) + 2 = 6k + 2 = 2(3k + 1)$$

olur ve bu çift bir sayıdır. Böylece "$n$ çift ise $3n+2$ çifttir" ispatlanmış olur; karşıt ters doğru olduğundan asıl önerme doğrudur.

Hoca bu örneği mantık kullanmadan da yorumladı: $3n + 1 = 2k$ çift ise $3n$ tek olmalıdır, $3n$'nin tek olması için de $n$ tek olmalıdır. Bu sonuç matematiksel olarak doğrudan çıkarılabilir, ama bir ispat tekniği (doğrudan veya dolaylı) kullanılmak istenirse yukarıdaki işlem yapılır.

## 4. Tümevarımla İspat

Tümevarım (matematiksel sonuç çıkarma, *mathematical induction*), fonksiyonların, bağıntıların ve eşitliklerin doğruluğunu ya da yanlışlığını göstermek için kullanılır. Slayttaki tanım (ekrandan, 00:35:00):

- $\forall n \in A,\ S(n)$ biçimindeki ifadenin ispatına bakılır.
- $N$, pozitif tam sayılar veya doğal sayılardan oluşan bir kümedir.
- $A$, $N$'nin bir alt kümesidir.
- $S(n)$ bir önermedir.
- Genel olarak özdeşliklerin ispatında kullanılır (ör. $\frac{n(n+1)}{2}$).

Tümevarım, basit denemelerden karmaşık denemelere giden ve herhangi bir adımla bir sonraki adım arasındaki tutarlılığı gösteren bir ispat tekniğidir. Hoca bunu ders kitabındaki **merdiven** benzetmesiyle anlattı: merdivenin ilk basamağı önermeyi sağlamalıdır; $k$. basamakla $(k+1)$. basamak arasında tutarlılık varsa önerme doğrudur. Bir basamakta önerme sağlanmıyorsa ileriye bakmaya gerek yoktur.

Adımlar:

1. **Temel adım (basis step):** Önermenin kümenin ilk elemanı için doğruluğu test edilir. İlk elemanın 1 olması gerekmez; küme $-1$ ya da $-5$ ile de başlayabilir. İstenirse ikinci eleman da denenebilir.
2. **Kabul:** Herhangi bir $k$ (ya da $i$) değeri için $S(k)$'nin doğru olduğu kabul edilir.
3. **Tümevarım adımı (inductive step):** $S(k)$ doğru kabul edildiğinde $S(k+1)$'in de doğru olduğu gösterilir. Gösterilirse $S(n)$ doğrudur, gösterilemezse yanlıştır.

### 4.1 Örnek: $1 + 2 + \dots + n = \frac{n(n+1)}{2}$

Tahtadaki çözüm, $n \in N^+ = \{1, \dots, n\}$ (ekrandan, 00:40:00):

- **1. adım:** $n = 1$ için $\frac{1 \cdot 2}{2} = 1$, doğru. $n = 2$ için $1 + 2 = 3$ ve $\frac{2 \cdot 3}{2} = 3$, doğru.
- **2. adım:** $n = k$ için $1 + 2 + \dots + k = \frac{k(k+1)}{2}$ doğru kabul edilir.
- **3. adım:** $n = k+1$ için

$$1 + 2 + \dots + k + (k+1) \stackrel{?}{=} \frac{(k+1)(k+2)}{2}.$$

Sol taraftaki ilk $k$ terim yerine kabul edilen ifade yazılır:

$$\frac{k(k+1)}{2} + (k+1) = \frac{k(k+1) + 2(k+1)}{2} = \frac{(k+1)(k+2)}{2}.$$

Payda eşitlenip $(k+1)$ ortak çarpan parantezine alınınca sol taraf (LHS) sağ tarafa (RHS) eşit çıkar. Dolayısıyla $P(n)$ önermesi doğrudur. Hoca bu toplamın daha sonra algoritma karmaşıklığında da kullanılacağını belirtti.

### 4.2 Yanlış bir önerme: $1 + 2 + \dots + n = \frac{n(n+2)}{2}$

Hoca tümevarımın yanlış bir önermede nasıl tıkandığını göstermek için bir önerme uydurdu:

- $n = 1$ için $\frac{1 \cdot 3}{2} = 1.5 \ne 1$. Temel adım zaten sağlanmıyor.
- Bu atlanıp tümevarım adımına bakılsa bile: $n = k$ için $\frac{k(k+2)}{2}$ kabul edilir. $n = k+1$ için hedef $\frac{(k+1)(k+3)}{2} = \frac{k^2 + 4k + 3}{2}$'dir.
- Sol taraf: $\frac{k(k+2)}{2} + (k+1) = \frac{k^2 + 2k + 2k + 2}{2} = \frac{k^2 + 4k + 2}{2}$.

$k^2 + 4k + 2 \ne k^2 + 4k + 3$ olduğundan eşitlik sağlanmaz. Merdivenin basamakları arasındaki bağlantı "sakat" olduğu için önerme yanlıştır.

### 4.3 Örnek: İlk $n$ pozitif tek sayının toplamı $n^2$'dir

Slayttaki çözüm (ekrandan, 00:45:00): $S_n = 1 + 3 + 5 + \dots = n^2$.

1. $n = 1$ için $1 = 1^2 = 1$ (doğru). $n = 2$ için $1 + 3 = 2^2 = 4$ (doğru).
2. $n = k$ için $1 + 3 + 5 + \dots + (2k-1) = k^2$ doğru kabul edilir. Tek sayıların toplamında son terim $2k-1$ ile gösterilir.
3. $n = k+1$ için

$$\underbrace{1 + 3 + 5 + \dots + (2k-1)}_{k^2} + (2(k+1) - 1) = (k+1)^2,$$

$$k^2 + (2k+1) = k^2 + 2k + 1 = (k+1)^2.$$

Bütün terimler birbirine eşit çıktığı için önerme doğrudur. Hoca, adımların basit olduğunu, yalnızca prosedürü uygulamak gerektiğini söyledi.

### 4.4 Örnek: $n^3 - n$, 3'e tam bölünür

$n$ pozitif tam sayı iken $n^3 - n$'nin 3'e tam bölündüğü ispatlanır; yani $(n^3 - n) \bmod 3 = 0$.

- $n = 1$ için $1^3 - 1 = 0$, $0 \bmod 3 = 0$, doğru.
- $n = 2$ için $2^3 - 2 = 6$, $6 \bmod 3 = 0$, doğru.
- $n = k$ için $k^3 - k$'nın 3'e tam bölündüğü kabul edilir.
- $n = k+1$ için:

$$(k+1)^3 - (k+1) = k^3 + 3k^2 + 3k + 1 - k - 1 = (k^3 - k) + 3(k^2 + k).$$

$k^3 - k$ kabulden dolayı 3'e bölünür; $3(k^2 + k)$ ise 3 çarpanı içerdiği için 3'e bölünür. İkisinin toplamı da 3'e bölünür; önerme doğrudur.

> **Ders sonrası not:** Hoca $n=2$ adımında bir an "6 mod 3 eşittir 2" dedi, hemen ardından "tam bölünüyor, kalan 0" diye düzeltti. Doğrusu $6 \bmod 3 = 0$'dır.

## 5. Çelişkiyle İspat

Hoca çelişkiyle ispatın (proof by contradiction) bu dersin slaytlarında olmadığını ama bir örnek göstermek istediğini söyledi (ekrandan, 01:05:00 ve 01:10:00).

Çelişkiyle ispat, bir $p$ önermesi ya da $p \rightarrow q$ biçimindeki bir önerme için, **olumsuzunun yanlış olduğu ispat edilerek** yapılan ispattır. $p$'nin olumsuzu doğrudan $\lnot p$'dir. $p \rightarrow q$'nun olumsuzu ise doğrudan yazılamaz; önce temel operatörler cinsinden eşdeğeri yazılır:

$$\lnot(p \rightarrow q) \equiv \lnot(\lnot p \lor q) \equiv p \land \lnot q.$$

Son adım De Morgan kuralıdır. Dolayısıyla $p \land \lnot q$'nun yanlış olduğu ispatlanmalıdır; bunun yanlışlığı, olumsuzunun yani $p \rightarrow q$'nun doğru olduğu anlamına gelir.

### 5.1 Örnek: $n$ tek ise $n^2$ tektir

Bu önerme doğrudan ispatla da yapılabilir, ama çelişkiyle ispatlandı:

- $p$: "$n$ tektir", $q$: "$n^2$ tektir", $\lnot q$: "$n^2$ çifttir".
- Gerekli olan $p \land \lnot q$, yani "$n$ tek ise $n^2$ çift sayıdır" ifadesi; bunun yanlış olduğu gösterilecek.
- $n = 2k + 1$, $k \in \mathbb{Z}$ doğru kabul edilir.
- $n^2 = 4k^2 + 4k + 1 = 2(2k^2 + 2k) + 1$. $l = 2k^2 + 2k$ denirse $n^2 = 2l + 1$, yani tek sayıdır.

$n^2$'nin çift olduğu varsayımıyla çelişen bir sonuç elde edildi. Sembolik olarak $p = 1$ yerine konur, $\lnot q$ ise 0 çıkar; $1 \land 0 = 0$, yani $p \land \lnot q$ yanlıştır. Bunun tersi olan $p \rightarrow q$ doğrudur.

**Soru:** (sohbetten) Dolaylı ispatla çelişkiyle ispat arasındaki fark nedir? **Cevap:** Dolaylı ispat $p \rightarrow q$ yerine $\lnot q \rightarrow \lnot p$'yi ispatlar; bunun eşdeğeri $q \lor \lnot p$'dir (ekrandan, 01:10:00). Çelişkiyle ispatta ise $p \land \lnot q$'nun yanlış olduğu gösterilir.

**Soru:** (sohbetten) Çift sayıyı neden hep $2k$ biçiminde yazıyoruz? **Cevap:** Bu bir kabuldür. Her $k$ tam sayısı için $2k$ çift sayıdır; bugüne kadar kimse $2k$ biçimindeki bir sayının tek olduğunu gösteremedi. İspatlar bu kabulün üzerine kurulur.

Çelişkiyle ispat, $p \rightarrow q$'nun doğrudan ispatının mümkün olmadığı durumlarda ya da "bütün asal sayılar tek sayıdır" gibi tek bir $p$ önermesinde kullanılır.

## 6. Aksine Örnek ve Deneme Yoluyla İspat

### 6.1 Aksine örnek (counterexample)

Aksine örnek, önermelerdeki **yanlışlığın** ispatında kullanılır (ekrandan, 01:15:00). "Tüm asal sayılar tek sayıdır" önermesini $P$ ile gösterirsek $P = P(2) \land P(3) \land \dots$ olur. Doğruluğunu göstermek için sonsuz sayıdaki asalın hepsine bakmak gerekirdi. Oysa önermeyi yanlışlayan tek bir örnek, $2$, $P$'yi yanlış (F) yapar ve diğerlerine bakmaya gerek kalmaz.

İkinci örnek: her gerçel $x$ için $x^2 > 0$ önermesi. Doğrudan ya da dolaylı yoldan $x$ ile $x^2$ arasındaki ilişkiyi ispatlamaya çalışmak zordur; ama $x = 0$ için $0^2 = 0$ olduğundan önerme yanlıştır. Hoca ayrıca "karesi kendisinden büyük" gibi bir önermenin $x = \frac{1}{2}$ ile yanlışlanabileceğini söyledi.

<!-- BELİRSİZ: x = 1/2 örneğinin hangi önermeye (ör. x^2 ≥ x) ait olduğu altyazıda net değil. -->

### 6.2 Deneme yoluyla ispat

Deneme yoluyla ispat (altyazıda "try and ..." olarak geçti), $p$ veya $p \rightarrow q$ önermelerinde **sonlu kümeler** üzerinde yapılır. Kümenin her elemanı tek tek denenir; hepsi sağlıyorsa önerme doğrudur, en az biri sağlamıyorsa yanlıştır. Bu iş bir programla kolayca yapılabilir.

Örnek: tanım kümesi $\{-1, 0, 1\}$ olmak üzere $P(x): x^2 < 5$.

- $(-1)^2 = 1 < 5$, sağlıyor.
- $0^2 = 0 < 5$, sağlıyor.
- $1^2 = 1 < 5$, sağlıyor.

Bütün elemanlar sağladığı için önerme doğrudur.

> **Ek bilgi (derste anlatılmadı):** Bu yönteme kaynaklarda genellikle "tüketerek ispat" (proof by exhaustion) denir. Yalnızca sonlu ve küçük kümelerde uygulanabilir.

## 7. Tümevarımla Bir Algoritma Karşılaştırması: $3n < n!$

Hoca slaytlarda olmayan bir örnek ekledi (ekrandan, 01:20:00). Önceki dönemde yapısal programlamaya girişte algoritmalar Big-O gösterimiyle karşılaştırılmıştı ($O(n)$, $O(n^2)$ gibi). İki algoritma olsun: $T_1 = 3n$, $T_2 = n!$.

**Soru:** Hangi algoritma daha kötüdür? **Cevap (bir öğrenci):** $n!$ olan. Hoca: 10 eleman varsa $T_2$ ile $10!$ işlem, $T_1$ ile 30 işlem yapılır.

Bunu ispatlamak için $n > 6$, $n \in \mathbb{Z}$ için $3n < n!$ önermesi ele alınır. Bir eşitsizlik (özdeşlik benzeri bir ifade) olduğu için tümevarım kullanılabilir. Hoca, sınavda ya da ödevde "şu önermeyi ispatlayın" denildiğinde hangi yöntemin kullanılacağının problemden çıkarılması gerektiğini vurguladı. Küme $n = \{7, 8, \dots\}$'dir.

1. **Temel adım:** $3 \cdot 7 = 21 < 7! = 5040$, doğru.
2. **Kabul:** $n = k$ için $3k < k!$ doğru kabul edilir.
3. **Tümevarım adımı:** $n = k+1$ için $3(k+1) < (k+1)!$ gösterilmelidir. $(k+1)! = (k+1) \cdot k! = k \cdot k! + k!$ olduğundan

$$3k + 3 \stackrel{?}{<} k \cdot k! + k!.$$

Kabulden $3k < k!$ bilinir. $k \ge 7$ olduğundan $k \cdot k!$ her durumda 3'ten büyüktür, yani $3 < k \cdot k!$. İki eşitsizlik toplanınca $3k + 3 < k! + k \cdot k! = (k+1)!$ elde edilir. Dolayısıyla $3n < n!$ doğrudur.

Hoca, yöntemin seçimine dair öğrenci sorusuna ders sonunda da döndü: hangi ispat yönteminin seçileceğinin bir algoritması yoktur, tamamen tecrübe ve bol soru çözme işidir. Ders kitabının (Rosen) bölüm sonlarındaki örnek sorular önerildi.

## 8. Boole Cebrinin Donanım Temeli

Dersin ikinci kısmında kitabın bir sonraki bölümü olan Boole cebrine (Bölüm 3) geçildi (ekrandan, 01:25:00). Boole cebri, bilgisayarlarda hafıza ve işlem elemanlarının temelini oluşturan, mantığa dayalı bir konudur ve öğrencilerin aynı dönem aldığı lojik devreler konularıyla bağlantılıdır.

Bilgisayarda bilgiyi saklamak ya da işlemek için elektriksel işaretler gerekir. Hoca önce çok seviyeli bir kodlama düşündürdü (ekrandan, 01:30:00):

```text
4 V -> A
3 V -> B
2 V -> C
1 V -> D
0 V -> E
```

Bu yaklaşımın iki sorunu vardır. Birincisi çok sayıda, aralıkları geniş voltaj seviyesine ihtiyaç duyulur. İkincisi her iletkenin bir direnci vardır:

$$R = \rho \frac{L}{A},$$

burada $\rho$ öz direnç katsayısı, $L$ iletkenin uzunluğu, $A$ kesit alanıdır. Bir kişiden diğerine 4 V gönderildiğinde karşı taraf örneğin 3,8 V ölçer; seviyeler birbirine yakın olduğunda hangi harfin kastedildiği karışır. Hoca bunu analog algılardaki hatalara ve "kulaktan kulağa" oyununa benzetti: mesaj aktarıldıkça bozulur.

Çözüm, tek bir hat yerine birden fazla hat kullanmak ve her hatta yalnız iki durum göndermektir: elektrik var (yaklaşık 5 V) ya da yok (0 V). 5 V gönderilen bir hat karşıda hiçbir zaman 0 V görünmez; 4 V ya da 3 V görülse bile "var" olarak kabul edilebilir. 3 hatla $2^3 = 8$ farklı bilgi en az hatayla temsil edilir.

Bu iki durumu saklayan devre elemanları vardır. En basiti **kondansatördür**: içi elektrik yüküyle doluysa 1 (5 V), boşsa 0 okunur; $n$ kondansatör $2^n$ durum saklar. Fiziksel olarak daha uygun olanlar **yarı iletken** elemanlardır. Örneğin bir diyodun bariyer gerilimi silisyumda yaklaşık 0,7 V, germanyumda yaklaşık 0,3 V'tur; uçları arasındaki potansiyel fark bu değere eşit ya da daha büyükse diyot iletken gibi davranır. Yarı iletkenler çok küçültülebildiği için işlemci ve bellek tasarımında kullanılır; diyot ve transistör gibi elemanlardan **lojik kapılar** kurulur. Elektriğin varlığına ya da yokluğuna 0/1, F/T, OFF/ON gibi anlamlar yüklenir.

<!-- BELİRSİZ: Karede germanyum değeri "0.3 V" ya da "0.1 V" gibi okunuyor; altyazıda 0.3 volt geçiyor. -->

## 9. Boole İşlemleri ve Lojik Kapılar

Boole cebri, önermeler mantığının doğrudan bir uygulamasıdır. Önermelerin yerini girişler, önermenin sonucunun yerini çıkış alır. Bağlaçların (connectives) karşılığı da **kapılardır (gates)**. Üç temel kapı vardır (ekrandan, 01:25:00):

- **OR kapısı:** girişi içeri doğru kıvrımlı, ucu sivri sembol; çıkışı $A + B$.
- **AND kapısı:** girişi düz, ucu yuvarlak sembol; çıkışı $AB$.
- **NOT kapısı:** üçgen ve ucunda küçük bir daire; çıkışı $\bar{A}$.

Boole cebri yalnız 0 ve 1 üzerinde çalışır ve üç temel işlemi vardır:

- **Boole toplamı (Boolean sum)** = mantıksal OR. Operatörün iki yanındakilerden en az biri 1 ise sonuç 1, ikisi de 0 ise 0'dır. Örneğin iki girişe 5 V verilirse çıkıştan 5 V (1) alınır; 1 ve 0 verilirse 1, 0 ve 0 verilirse 0 alınır.
- **Boole çarpımı (Boolean product)** = mantıksal AND (ekrandan, 01:35:00): $1 \cdot 1 = 1$, $1 \cdot 0 = 0$, $0 \cdot 1 = 0$, $0 \cdot 0 = 0$.
- **Tümleyen (complement)** = NOT: $\bar{0} = 1$, $\bar{1} = 0$. Değil işlemi üst çizgiyle ya da üs işaretiyle ($x'$) gösterilir.

Hoca $1 \cdot 0$ yazımının aritmetikteki çarpma olarak değil, "1 ve 0" olarak okunması gerektiğini hatırlattı.

### 9.1 Örnek: $1 \cdot 0 + \overline{(0+1)}$

Slayttaki çözüm (ekrandan, 01:35:00):

$$1 \cdot 0 + \overline{(0 + 1)} = 0 + \bar{1} = 0 + 0 = 0.$$

### 9.2 Örnek: $A \rightarrow B$'nin devresi

Lojik devrelerde "ise" diye bir kapı yoktur; önce mantıksal eşdeğeri yazılır: $A \rightarrow B \equiv \bar{A} + B$. Devre şöyle kurulur:

```text
A ---[NOT]--- A' ---\
                     [OR]--- A' + B
B ------------------/
```

Doğruluk tablosuyla kontrol:

| $A$ | $B$ | $\bar{A}$ | $\bar{A} + B$ | $A \rightarrow B$ |
|---|---|---|---|---|
| 0 | 0 | 1 | 1 | 1 |
| 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 | 0 |
| 1 | 1 | 0 | 1 | 1 |

Devre, koşullu önermenin bütün satırlarını sağlar. Hoca bu tür devrelerin lojik simülatörlerde kurulup denenebileceğini söyledi.

## 10. Boole Fonksiyonları

Boole cebrinde küme iki elemanlıdır: $B = \{0, 1\}$. $n$. dereceden bir Boole fonksiyonu $B^n$'den $B$'ye bir fonksiyondur; $B^n$, $B$'nin kendisiyle $n$ kez kartezyen çarpımıdır ve $n$ bitlik değerlerin $2^n$ olası durumuna karşılık gelir. Doğruluk tablosunda bütün durumlar yazılır, durumlardan fonksiyon çıkarılır ve bu fonksiyon en sade hale getirilir.

### 10.1 Örnek: $F(x,y,z) = xy + \bar{z}$

Slayttaki tablo (ekrandan, 01:50:00). $x, y, z$ girişler, $F$ çıkıştır. Tabloda satırlar 111'den 000'a doğru sıralanmıştır: $x$ sütununda dört 1 dört 0, $y$'de ikişerli, $z$'de birer birer değişim vardır. Ara sütunlar olarak $xy$ ve $\bar{z}$ kullanılmıştır.

| $x$ | $y$ | $z$ | $xy$ | $\bar{z}$ | $F = xy + \bar{z}$ |
|---|---|---|---|---|---|
| 1 | 1 | 1 | 1 | 0 | 1 |
| 1 | 1 | 0 | 1 | 1 | 1 |
| 1 | 0 | 1 | 0 | 0 | 0 |
| 1 | 0 | 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 1 | 1 |
| 0 | 0 | 1 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 1 | 1 |

İşlem önceliği önemlidir: önce NOT, sonra AND, en son OR uygulanır. Bu yüzden $xy$ önce hesaplanır.

Hoca gerçek problemlerde bu denklemin verilmeyeceğini, bunun yerine bir cümle ya da paragraf verileceğini anlattı. Örneğin $x$, $y$ ve $z$ üç asansör olsun ve dördüncü asansörün çalışması bu üçüne bağlı olsun ("üçü de çalışıyorsa dördüncü çalışır", "$x$ ve $y$ çalışıyorsa dördüncü çalışır" gibi). Senaryodan sonucun 1 olduğu satırlar işaretlenir ve her 1 satırı bir çarpım terimi olarak yazılır:

$$F = xyz + xy\bar{z} + x\bar{y}\bar{z} + \bar{x}y\bar{z} + \bar{x}\bar{y}\bar{z}.$$

Bu ifade doğrudan devreye dökülürse beş adet üç girişli AND kapısı, bunları birleştiren OR kapıları ve NOT kapıları gerekir. Oysa aynı işi $xy + \bar{z}$ yalnız bir AND, bir OR ve bir NOT kapısıyla yapar. Dersin amacı, verilen problemi doğruluk tablosuna yerleştirmek, ifadeyi yazmak ve kurallarla sadeleştirmektir. Hoca bu iki ifadenin denk olduğunu öğrencilerin tabloya bir sütun ekleyip kendilerinin denemesini önerdi.

**Soru:** Tabloda 0 olan satırları da ifadeye katmamız gerekmez mi? **Cevap:** Hayır. Buradaki gösterim çarpımların toplamıdır (sum of products). Yalnız 1 olan satırları almak yeterlidir, çünkü diğer bütün durumlarda ifade zaten 0 verir. Bunun gerekçesi Karnaugh haritalarında ayrıca görülecektir.

### 10.2 Tümleyen, eşitlik, toplam ve çarpım

Slayttaki tanımlar (ekrandan, 01:55:00):

- $F$'nin tümleyeni: $\bar{F}(x_1, \dots, x_n) = \overline{F(x_1, \dots, x_n)}$.
- $n$ değişkenli iki Boole fonksiyonu $F$ ve $G$'nin eşit kabul edilmesi için $B$'nin bütün $b_1, \dots, b_n$ elemanlarında $F(b_1, \dots, b_n) = G(b_1, \dots, b_n)$ sağlanmalıdır. Bu, mantıksal denklik kavramına karşılık gelir.
- Örnek: $xy$, $xy + 0$ ve $xy \cdot 1$ birbirine denktir. Bir şeyi 0 ile OR'lamak ya da 1 ile AND'lemek sonucu değiştirmez.
- $(F + G)(x_1, \dots, x_n) = F(x_1, \dots, x_n) + G(x_1, \dots, x_n)$.
- $(FG)(x_1, \dots, x_n) = F(x_1, \dots, x_n)\, G(x_1, \dots, x_n)$.

### 10.3 Kaç farklı Boole fonksiyonu vardır?

$n$ değişkenle doğruluk tablosunda $2^n$ satır vardır. Her satırın çıkışı 0 ya da 1 olabildiği için $2^{2^n}$ farklı Boole fonksiyonu yazılabilir.

- $n = 1$: $2^1 = 2$ satır, $2^2 = 4$ fonksiyon.
- $n = 2$: $2^2 = 4$ satır, $2^4 = 16$ fonksiyon ($F_1, \dots, F_{16}$). Bunlar bütün çıkışların 1 olduğu fonksiyondan bütün çıkışların 0 olduğu fonksiyona kadar uzanır.

İki girişli bir senaryoda okunan cümlelerden doldurulan çıkış sütunu mutlaka bu 16 fonksiyondan biridir; 17. bir fonksiyon yoktur. Hoca asansör örneğine dönerek dört girişli bir durumda $2^4 = 16$ satır ve $2^{16}$ farklı senaryo olabileceğini söyledi.

## 11. Boole Cebrindeki Özdeşlikler ve Sadeleştirme

Özdeşlikler, devre tasarımlarının sadeleştirilmesinde kullanılır (ekrandan, 02:00:00). Slayttaki tablo:

| Özdeşlik | Adı |
|---|---|
| $\bar{\bar{x}} = x$ | Çift tümleyen (double complement) |
| $x + x = x$, $x \cdot x = x$ | Eş güçlülük (idempotent) |
| $x + 0 = x$, $x \cdot 1 = x$ | Birim (identity) |
| $x + 1 = 1$, $x \cdot 0 = 0$ | Baskınlık (domination) |
| $x + y = y + x$, $xy = yx$ | Değişme (commutative) |
| $x + (y+z) = (x+y) + z$, $x(yz) = (xy)z$ | Birleşme (associative) |
| $x + yz = (x+y)(x+z)$, $x(y+z) = xy + xz$ | Dağılma (distributive) |
| $\overline{xy} = \bar{x} + \bar{y}$, $\overline{x+y} = \bar{x}\,\bar{y}$ | De Morgan |
| $x + xy = x$, $x(x+y) = x$ | Yutma (absorption) |
| $x + \bar{x} = 1$ | Birim özelliği (unit property) |
| $x\bar{x} = 0$ | Sıfır özelliği (zero property) |

Hocanın açıklamaları:

- **Çift tümleyen:** olumsuzun olumsuzu kendisidir.
- **Eş güçlülük:** önermelerdeki $p \land p = p$, $p \lor p = p$ ile aynıdır. Bir AND kapısının iki girişine de $A$ verilirse çıkış $A$ olur; gereksiz bir kapıdır.
- **Baskınlık:** 1, OR'da "yutan elemandır". Programlamadaki bir `if` koşulunda ilk terim 1 ise ve ardından OR'lar geliyorsa geri kalanlara bakmaya gerek yoktur. AND'de ise 0 yutan elemandır.
- **Değişme ve birleşme:** aynı operatörler arasında terimlerin yeri değiştirilebilir.
- **Dağılma:** $x + yz = (x+y)(x+z)$, yani OR'un AND üzerine dağılması, aritmetikte olmayan ama ikili mantıkta tanımlı bir özelliktir. AND'in OR üzerine dağılması, $x(y+z) = xy + xz$, aritmetikten tanıdık olandır.
- **De Morgan:** bir ifadenin değili alınınca içerideki terimlerin değili alınır, AND OR'a, OR AND'e dönüşür.

### 11.1 Yutma kuralının türetilmesi

$x + xy = x$: $x$ ortak çarpan parantezine alınır.

$$x + xy = x(1 + y) = x \cdot 1 = x.$$

$1 + y = 1$ olduğu için (baskınlık) sonuç $x$'tir.

$x(x + y) = x$: dağıtılır.

$$x(x+y) = xx + xy = x + xy = x.$$

Hoca bu kuralları ezberlemeye gerek olmadığını, doğrudan türetilebileceğini söyledi.

### 11.2 Örnek: $x(y+z) = xy + xz$ doğru mudur?

Slayttaki doğrulama tablosu (ekrandan, 02:00:00):

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

$x(y+z)$: $x$ 1 iken $y+z$ 1 ise sonuç 1, $x$ 0 iken sonuç her zaman 0'dır. $xy + xz$: $xy$ ve $xz$'nin 1 olduğu satırlar OR'lanır; üç satırda 1 çıkar. İki sütun aynıdır, ifadeler mantıksal olarak denktir.

Bir öğrencinin isteği üzerine hoca iki devreyi de çizdi:

```text
Devre 1: x(y + z)
  y, z  -> [OR]  -> (y + z)
  x, (y + z) -> [AND] -> çıkış        toplam 2 kapı

Devre 2: xy + xz
  x, y -> [AND] -> xy
  x, z -> [AND] -> xz
  xy, xz -> [OR] -> çıkış             toplam 3 kapı
```

**Soru:** Hangisi daha iyi? **Cevap (bir öğrenci):** Soldaki, yani $x(y+z)$; daha az kapı kullanır.

**Soru:** Bu çizimlerde devreyi nasıl tamamlıyoruz; giren elektriğin geri dönmesi gerekmez mi? **Cevap:** Bu bir analog devre değildir. Girişler verilir, çıkış ölçülür; kapalı bir çevrim gerekmez (belki bir toprak bağlantısı gerekir). Çıkıştan girişe geri besleme (feedback) olursa bu, ardışık lojik (sequential logic) konusuna girer.

### 11.3 Önemli bir kural: $x + \bar{x}y = x + y$

Hoca bunu önemli bir kural olarak gösterdi ve ispatladı:

$$x + \bar{x}y = x(1 + y) + \bar{x}y = x + xy + \bar{x}y = x + y(x + \bar{x}) = x + y \cdot 1 = x + y.$$

İlk adımda $x$ yerine $x(1+y)$ yazılır; $1 + y = 1$ olduğu için bu sonucu değiştirmez. Sonra içeri dağıtılır ve $y$ ortak parantezine alınır. $x + \bar{x} = 1$ olduğundan sonuç $x + y$ olur. Bir terim ve değili OR'lanırken değilin yanındaki çarpan varsa, aradaki değil "gider". $y$ yerine $yz$ gibi bir çarpım da gelebilir; o zaman sonuç $x + yz$ olur ve ispat aynı yolla yapılır.

Kolay bir kural daha: $x \cdot \bar{x}y = 0$, çünkü $x\bar{x} = 0$ ve geri kalan AND'ler sonucu değiştirmez. Hoca bu tür kurallardan birinin literatürde numarasıyla ("17. kural") meşhur olduğunu söyledi.

<!-- BELİRSİZ: "Rule 17" adının hangi kurala (x + x̄y = x + y mi, x·x̄y = 0 mı) verildiği altyazıda net değil. -->

### 11.4 Uzlaşma teoremi

Hoca bir kaynakta Boole cebri kurallarını gösterdi (değişme, çift olumsuzlama, De Morgan, Boole postülatları) ve uzlaşma (consensus) teoremini okudu:

$$AB + \bar{A}C + BC = AB + \bar{A}C.$$

$BC$ terimi gereksizdir. Kaynakta bunun ispatı ve duali de verilmişti; dual alma bu dersin ana konusu olmadığı için ayrıntıya girilmedi. Hoca, işlem yeteneğinin bu tür örnekler çözülerek gelişeceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Uzlaşma teoreminin duali $(A + B)(\bar{A} + C)(B + C) = (A + B)(\bar{A} + C)$ biçimindedir; dual, AND ile OR'un ve 0 ile 1'in yer değiştirmesiyle elde edilir.

### 11.5 Örnek: Tablodan $F$ ve $G$ ifadelerini bulma

Slayttaki soru (ekrandan, 02:15:00): Tabloda verilen $F(x,y,z)$ ve $G(x,y,z)$ fonksiyonlarını tanımlayan Boole ifadelerini bulunuz. Üç giriş ($x, y, z$) ve iki çıkışlı ($F, G$) bir blok şeması olarak düşünülebilir.

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

$F$ yalnız $x = z = 1$ ve $y = 0$ iken 1'dir: $F = x\bar{y}z$. Kontrol: $(0,1,0)$ verilince $0 \cdot \bar{1} \cdot 0 = 0$; $(1,1,1)$ verilince $1 \cdot 0 \cdot 1 = 0$. Yalnız ilgili satırda 1 çıkar.

$G$ iki satırda 1'dir: $G = xy\bar{z} + \bar{x}y\bar{z}$. Bu haliyle dört AND, bir OR ve üç NOT kapısı gerekir. $y\bar{z}$ parantezine alınırsa

$$G = y\bar{z}(x + \bar{x}) = y\bar{z} \cdot 1 = y\bar{z}.$$

$x$'in sonuca hiçbir etkisi yoktur: $y = 1, z = 0$ iken $x$ 1 de olsa 0 da olsa sonuç 1'dir. Boole kurallarıyla kapı sayısı sekizden ikiye (bir AND, bir NOT) düşer.

## 12. Çarpımların Toplamı ve Toplamların Çarpımı

Hoca tablodan ifade yazmanın aslında bütün satırları kullandığını gösterdi: 1 olan satırların terimleri 1 ile, 0 olan satırlarınkiler 0 ile çarpılmış gibi düşünülebilir; 0 ile çarpılanların etkisi olmadığı için yazılmaz. Bu yazım biçimleri iki gösterime götürür: **çarpımların toplamı (sum of products)** ve **toplamların çarpımı (product of sums)**.

De Morgan kuralıyla aynı ifade iki biçimde yazılabilir. Bir ifadenin iki kez değili alınırsa kendisi bulunur; bir kez değili alınıp De Morgan uygulanırsa:

$$x\bar{y}z = \overline{\overline{x\bar{y}z}} = \overline{\bar{x} + y + \bar{z}}.$$

İki yazımın kapı sayıları farklıdır; bazı durumlarda biri, bazı durumlarda diğeri işe yarar.

> **Ders sonrası not:** Altyazıda değili alınmış ifade "X'in değili veya Y'nin değili veya Z" biçiminde geçiyor; $x\bar{y}z$'nin değili $\bar{x} + y + \bar{z}$'dir (python ile 8 satırda doğrulandı).

Boole cebri kurallarını uygulamak geometri gibidir; bir sadeleştirmeyi gözden kaçırmak kolaydır. Bunun önüne geçen daha sistematik yöntemler Karnaugh haritaları ve daha ileri indirgeme tablolarıdır; sonraki derste bunlara geçilecektir.

> **Ek bilgi (derste anlatılmadı):** Toplamların çarpımı gösteriminde tablodaki 0 satırları kullanılır: her 0 satırı için değişkenlerin (1 ise değili alınarak) OR'landığı bir toplam terimi yazılır ve bu terimler AND'lenir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): $n$ çift sayı ise $n^2$'nin çift sayı olduğunu doğrudan ispatla gösteriniz.

> **Çözüm:** $n = 2k$, $k \in \mathbb{Z}$ kabul edilir. $n^2 = 4k^2 = 2(2k^2) = 2u$, $u = 2k^2 \in \mathbb{Z}$. $\therefore$ $n^2$ çifttir.

**Soru 2** (ekrandan, 00:30:00): $n^2$ tek sayı ise $n$'nin tek sayı olduğunu ispatlayınız.

> **Çözüm:** Karşıt ters: $n$ çift ise $n^2$ çifttir. $n = 2k \Rightarrow n^2 = 2(2k^2)$ çift. Karşıt ters doğru olduğundan önerme doğrudur.

**Soru 3** (derste slayttan, 00:31:42): $n$ bir tam sayı ve $3n + 2$ tek ise $n$'nin tek olduğunu ispatlayınız.

> **Çözüm:** $n = 2k$ varsayılırsa $3n + 2 = 6k + 2 = 2(3k+1)$ çifttir. Karşıt ters ispatlandığından önerme doğrudur.

**Soru 4** (ekrandan, 00:40:00): Tümevarımla $1 + 2 + \dots + n = \frac{n(n+1)}{2}$ olduğunu ispatlayınız.

> **Çözüm:** $n=1$: $1 = 1$. $n = k$ kabulüyle $\frac{k(k+1)}{2} + (k+1) = \frac{(k+1)(k+2)}{2}$.

**Soru 5** (derste sözlü, 00:41:21): $1 + 2 + \dots + n = \frac{n(n+2)}{2}$ önermesini tümevarımla inceleyiniz.

> **Çözüm:** $n = 1$ için $1.5 \ne 1$. Tümevarım adımında $\frac{k^2+4k+2}{2} \ne \frac{k^2+4k+3}{2}$. Önerme yanlıştır.

**Soru 6** (ekrandan, 00:45:00): İlk $n$ adet pozitif tek sayının toplamının $n^2$ olduğunu ispatlayınız.

> **Çözüm:** $n=1$: $1 = 1^2$. $1 + 3 + \dots + (2k-1) = k^2$ kabulüyle $k^2 + (2k+1) = (k+1)^2$.

**Soru 7** (derste slayttan, 00:45:52): $n$ pozitif tam sayı iken $n^3 - n$'nin 3'e tam bölündüğünü ispatlayınız.

> **Çözüm:** $n=1$: $0$, $n=2$: $6$, ikisi de 3'e bölünür. $(k+1)^3 - (k+1) = (k^3 - k) + 3(k^2 + k)$; iki terim de 3'e bölünür.

**Soru 8** (ekrandan, 01:10:00): $n$ tek ise $n^2$'nin tek olduğunu çelişkiyle ispatlayınız.

> **Çözüm:** $n = 2k+1$ ve $n^2$ çift varsayılır. $n^2 = 2(2k^2 + 2k) + 1$ tektir; çelişki. $p \land \lnot q$ yanlış, dolayısıyla $p \rightarrow q$ doğru.

**Soru 9** (ekrandan, 01:15:00): "Tüm asal sayılar tek sayıdır" önermesinin yanlış olduğunu gösteriniz.

> **Çözüm:** $2$ asaldır ve çifttir; tek bir aksine örnek önermeyi yanlışlar.

**Soru 10** (derste sözlü, 01:15:09): Her gerçel $x$ için $x^2 > 0$ önermesi doğru mudur?

> **Çözüm:** Hayır. $x = 0$ için $0^2 = 0$, $0 > 0$ değildir.

**Soru 11** (derste sözlü, 01:16:43): Tanım kümesi $\{-1, 0, 1\}$ iken $x^2 < 5$ önermesi doğru mudur?

> **Çözüm:** $1, 0, 1$ değerlerinin hepsi 5'ten küçüktür; önerme doğrudur.

**Soru 12** (ekrandan, 01:20:00): $T_1 = 3n$ ve $T_2 = n!$ algoritmalarından hangisi daha kötüdür? $n > 6$ için $3n < n!$ olduğunu ispatlayınız.

> **Çözüm:** $n!$ daha kötüdür. $3 \cdot 7 = 21 < 5040$. $3k < k!$ kabulüyle $3(k+1) = 3k + 3 < k! + k \cdot k! = (k+1)!$, çünkü $k \cdot k! > 3$.

**Soru 13** (ekrandan, 01:35:00): $1 \cdot 0 + \overline{(0+1)}$ ifadesinin değeri nedir?

> **Çözüm:** $0 + \bar{1} = 0 + 0 = 0$.

**Soru 14** (derste sözlü, 01:45:23): $A \rightarrow B$ işini yapan lojik devreyi tasarlayınız.

> **Çözüm:** $A \rightarrow B \equiv \bar{A} + B$; $A$ bir NOT kapısından geçirilir, $B$ ile OR'lanır. Çıkış yalnız $A=1, B=0$ iken 0'dır.

**Soru 15** (ekrandan, 01:50:00): $F(x,y,z) = xy + \bar{z}$ Boole fonksiyonunun değerleri nedir?

> **Çözüm:** 111'den 000'a sırasıyla $F = 1, 1, 0, 1, 0, 1, 0, 1$ (Bölüm 10.1'deki tablo).

**Soru 16** (ekrandan, 02:00:00): $x(y+z) = xy + xz$ doğru mudur?

> **Çözüm:** Evet. Doğruluk tablosunda iki sütun bütün satırlarda aynıdır (Bölüm 11.2).

**Soru 17** (ekrandan, 02:15:00): Tabloda verilen $F(x,y,z)$ ve $G(x,y,z)$ fonksiyonlarını tanımlayan Boole ifadelerini bulunuz.

> **Çözüm:** $F = x\bar{y}z$. $G = xy\bar{z} + \bar{x}y\bar{z} = y\bar{z}$.

## Dersin Toparlaması

Dersin ilk kısmında ispatın yapı taşları (tanımlanmamış terim, tanım, aksiyom, teorem) ve temel ispat yöntemleri görüldü: $p$ basit olduğunda doğrudan ispat, $p$ karmaşık olduğunda karşıt tersle dolaylı ispat, özdeşlik ve eşitsizlikler için tümevarım, olumsuzun yanlışlığını göstererek çelişkiyle ispat, yanlışlık için aksine örnek ve sonlu kümelerde deneme yoluyla ispat. Hangi yöntemin seçileceğinin bir algoritması yoktur; bol soru çözerek tecrübe kazanılır.

İkinci kısımda Boole cebrine geçildi. Bilginin neden iki seviyeli işaretlerle saklandığı, OR, AND ve NOT kapıları, Boole fonksiyonları, doğruluk tablosundan ifade yazma ve Boole cebri özdeşlikleriyle devre sadeleştirme anlatıldı. Sonraki derste çarpımların toplamı ve toplamların çarpımı gösterimleri ile sistematik sadeleştirme yöntemi olan Karnaugh haritalarına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
