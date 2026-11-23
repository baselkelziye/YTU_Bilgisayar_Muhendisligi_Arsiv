# Ders 3 Genişletilmiş Notu: Deterministik ve Deterministik Olmayan Sonlu Otomatlar (DFA ve NFA)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Diller ve Dizgi İşlemleri
- 2. Deterministik Sonlu Otomat (DFA) Fikri
- 3. Kabul ve Ret Örnekleri
- 4. Tuzak Durum ve Sonsuz Diller
- 5. DFA'nın Biçimsel Tanımı
- 6. Geçiş Fonksiyonu, Geçiş Tablosu ve Genişletilmiş Geçiş Fonksiyonu
- 7. Bir DFA'nın Dili
- 8. Daha Fazla DFA Örneği
- 9. Düzenli Diller ve Düzenli Olmayan Diller
- 10. Deterministik Olmayan Sonlu Otomat (NFA)
- 11. Epsilon (Null) Geçişleri
- 12. Hesaplama Ağacı
- 13. Diğer NFA Örnekleri
- 14. NFA'nın Biçimsel Tanımı
- 15. NFA'da Genişletilmiş Geçiş Fonksiyonu ve Dil

## 1. Önceki Dersin Tekrarı: Diller ve Dizgi İşlemleri

Hoca derse geçen haftanın kısa bir özetiyle başladı. Bir **dil** (language), bir dizgi (string) kümesidir. Bir **dizgi** ise bir alfabeden alınan sembollerin dizisidir. Örneğin alfabe olarak İngiliz alfabesi ($a$'dan $z$'ye) alınırsa $a$ bir sembol, $b$ başka bir semboldür; $cat$, $dog$, $house$, $bird$ bu alfabede dizgilerdir. $\{cat, dog, house\}$ ise bir dildir.

Hesaplama problemlerini bu dillerle tarif edebiliriz. Örneğin $PRIMES$ asal sayıların, $EVEN$ çift sayıların kümesidir. "$x$ sayısı asal mı?" problemi "$x$, $PRIMES$ dilinin elemanı mı?" problemine, yani bir **küme üyeliği** problemine çevrilebilir. Hoca, dersin ilerleyen kısımlarında bu çeviriyi çok yapacağımızı söyledi.

**Tekli (unary) sayılar**, değeri 1'lerin sayısına eşit olan dizgilerdir: $11$ ikiyi, $111$ üçü, $1111$ dördü gösterir.

Dizgi işlemleri şöyle özetlendi:

- **Birleştirme (concatenation):** iki dizgiyi yan yana yazmak.
- **Ters çevirme (reverse)** ve **uzunluk** $|w|$.
- **Boş dizgi** ($\lambda$ ya da $\varepsilon$), **alt dizgi**, **önek** (dizginin ilk sembolüyle başlayan alt dizgi) ve **sonek** (son sembolüyle biten alt dizgi).
- **Üs alma:** $w^n$, $w$'nin $n$ kez kendisiyle birleştirilmesidir; tanım gereği $w^0 = \lambda$.
- **Yıldız kapanışı:** $\Sigma^*$, alfabedeki sembollerle yazılabilen bütün dizgilerin kümesidir. $\Sigma = \{a, b\}$ için $\Sigma^* = \{\lambda, a, b, aa, ab, ba, bb, aaa, \dots\}$.
- **Artı kapanışı:** $\Sigma^+$, yıldız kapanışına benzer ama boş dizgiyi dışarıda bırakır.

Diller küme olduğu için birleşim, kesişim, fark ve tümleyen gibi bilinen küme işlemleri dillere de uygulanır. Dizgi işlemleri de küme işlemlerine çevrilebilir:

- **Ters çevirme:** kümedeki her dizginin tersi alınır; $\{ab\}$'nin tersi $\{ba\}$'dır.
- **Birleştirme:** $L_1 L_2$, birinci kümeden bir dizgi ile ikinci kümeden bir dizginin bütün olası birleştirmelerinden oluşur.
- **Üs alma:** $L^n$, $n$ tane $L$ kümesinin birleştirilmesidir; ilk parça birinci kümeden, ikinci parça ikinci kümeden gelir ve böyle devam eder. Tanım gereği $L^0 = \{\lambda\}$.
- **Yıldız kapanışı:** $L^* = L^0 \cup L^1 \cup L^2 \cup \dots$, yani boş dizgi ve elemanların bütün olası birleştirmeleri. **Artı kapanışı** $L^+$ yine boş dizgiyi (yani $L^0$ terimini) dışarıda bırakır.

## 2. Deterministik Sonlu Otomat (DFA) Fikri

Bu dersin yeni konusu **deterministik sonlu otomattır** (Deterministic Finite Automaton, DFA). Sonlu otomat bir hesaplama modelidir; hoca onu "yetenekleri çok sınırlı küçük bir bilgisayar" olarak düşünmemizi istedi. Otomat bir **giriş şeridinden** (input tape) sembolleri okur ve yalnız iki çıktıdan birini verir: **kabul** (accept) ya da **ret** (reject). Yani çıktısı aslında Boole türündendir.

Otomat bir **geçiş grafiği** (transition graph) ile gösterilir (ekrandan, 00:20:00):

- Her daire bir **durumdur** (state). İlk örnekte $q_0$'dan $q_5$'e kadar durumlar vardır.
- **Başlangıç durumu** (initial state), hiçbir durumdan çıkmayan, "boşluktan gelen" okun gösterdiği durumdur. Diğer bütün oklar bir durumdan çıkar; bu ok çıkmaz. Örnekte başlangıç durumu $q_0$'dır.
- Durumlar arasındaki oklar **geçişlerdir** (transition) ve üzerlerinde okunan sembol yazar.
- **Çift daireli** durumlar **kabul durumlarıdır** (accepting state).

Otomat her an bu durumlardan **yalnız birindedir**; aynı anda iki durumda olamaz, durumlar birbirini dışlar. Otomat başlangıç durumunda başlar, şeritten sembolleri sırayla okur ve okuduğu sembolün etiketli olduğu geçişi izleyerek durum değiştirir. Grafikte yalnız $a$ ve $b$ sembolleri geçtiği için alfabe $\{a, b\}$'dir. Başlangıç durumunda $a$ okunursa $q_1$'e, $b$ okunursa $q_5$'e geçilir.

Dizginin tamamı okunduktan sonra otomat bir kabul durumundaysa dizgi **kabul edilir**; değilse **reddedilir**.

DFA'da her durum için alfabedeki **her sembolün** ne yaptığı gösterilmelidir. İlk örnekte $q_0$, $q_1$, $q_2$ ve diğer bütün durumlardan hem $a$ hem $b$ için bir geçiş vardır.

## 3. Kabul ve Ret Örnekleri

İlk örnekteki DFA'nın geçişleri grafikten şöyle okunur (ekrandan, 00:20:00):

| $\delta$ | $a$ | $b$ |
|---|---|---|
| $q_0$ (başlangıç) | $q_1$ | $q_5$ |
| $q_1$ | $q_5$ | $q_2$ |
| $q_2$ | $q_5$ | $q_3$ |
| $q_3$ | $q_4$ | $q_5$ |
| $q_4$ (kabul) | $q_5$ | $q_5$ |
| $q_5$ | $q_5$ | $q_5$ |

### 3.1 $abba$ girdisi: kabul

Şeritte $abba$ vardır ve otomat başlangıçta $q_0$'dadır. Okuma kafası sembolleri sırayla tarar:

- İlk sembol $a$: $q_0 \to q_1$.
- İkinci sembol $b$: $b$ etiketli geçiş izlenir, $q_1 \to q_2$.
- Üçüncü sembol $b$: $q_2 \to q_3$.
- Dördüncü sembol $a$: $q_3 \to q_4$.

Okuma bittiğinde son durum $q_4$'tür ve bu bir kabul durumudur; otomat $abba$'yı kabul eder.

### 3.2 $aba$ girdisi: ret

$q_0 \xrightarrow{a} q_1 \xrightarrow{b} q_2 \xrightarrow{a} q_5$. Girdi bitmiştir ve son durum $q_5$ kabul durumu değildir; otomat $aba$'yı reddeder. Hoca burada da sonucu **son durumun** belirlediğini vurguladı.

### 3.3 Boş girdi: ret

Şerit boşsa hiçbir şey okunmaz ve otomat $q_0$'da kalır. $q_0$ kabul durumu olmadığı için boş dizgi reddedilir.

Bu otomat yalnız tek bir dizgiyi, $abba$'yı kabul eder; diğer her dizgi reddedilir. Özetle:

- Bir dizgiyi **kabul etmek** için girdinin tamamı taranmalı ve son durum kabul durumu olmalıdır.
- Bir dizgiyi **reddetmek** için girdinin tamamı taranmalı ve son durum kabul olmayan bir durum olmalıdır.

### 3.4 Aynı grafik, farklı kabul durumları

İkinci örnekte grafik aynıdır, ama bu kez $q_0$, $q_2$ ve $q_4$ kabul durumudur (ekrandan, 00:30:00). Başlangıç durumu zaten kabul durumu olduğu için hiçbir şey okumadan kabul durumundayız; demek ki boş dizgi kabul edilir (girdi, bir şey okumadan bitmiştir ve otomat kabul durumundadır). $ab$ okununca $q_2$'ye, $abba$ okununca $q_4$'e varılır. Bu otomatın dili:

$$L = \{\varepsilon, ab, abba\}$$

Bu küme, otomatın kabul ettiği dizgilerin kümesidir ve **otomatın dili** adını alır.

## 4. Tuzak Durum ve Sonsuz Diller

### 4.1 $\{a^n b : n \ge 0\}$ örneği

Sıradaki DFA'da (ekrandan, 00:35:00) hoca önce "bunun neyi kabul ettiğini görebiliyor musunuz?" diye sordu. Grafik şöyledir:

| $\delta$ | $a$ | $b$ |
|---|---|---|
| $q_0$ (başlangıç) | $q_0$ | $q_1$ |
| $q_1$ (kabul) | $q_2$ | $q_2$ |
| $q_2$ (tuzak) | $q_2$ | $q_2$ |

$q_2$ bir **tuzak durumdur** (trap state). Otomat $q_2$'ye girdiğinde $a$ okusa da $b$ okusa da yine $q_2$'de kalır, çünkü alfabedeki her iki sembol için de $q_2$'den $q_2$'ye dönen geçiş vardır. Tuzak durumdan çıkılamaz ve bu durum kabul durumu olmadığından, otomat oraya bir kez girince girdinin geri kalanı ne olursa olsun dizgiyi reddeder.

Başlangıç durumunda $a$ için bir döngü (loop) vardır, sonra tek bir $b$ geçişi kabul durumuna götürür. Yani istenen sayıda $a$, ardından bir $b$ kabul edilir. Hiç $a$ okumadan doğrudan $b$ okumak da kabul durumuna götürdüğü için yalnız $b$ de kabul edilir. $b$'den sonra herhangi bir sembol okunursa tuzağa düşülür.

- $aab$: birinci ve ikinci $a$ döngüde kalır, $b$ kabul durumuna götürür; **kabul**.
- $bab$: $q_0 \xrightarrow{b} q_1 \xrightarrow{a} q_2 \xrightarrow{b} q_2$; **ret**.

Hoca, otomatın dilini İngilizce (ya da Türkçe) anlatmak yerine bu derste genellikle **küme olarak** yazmamız gerektiğini söyledi:

$$L = \{a^n b : n \ge 0\}$$

Burada $n$'nin $0$ ya da daha büyük olabilmesi önemlidir: $n = 0$ yalnız $b$'yi, $n = 1$ $ab$'yi verir. $n$'nin üst sınırı olmadığı için bu otomatın kabul ettiği dizgi sayısı **sonsuzdur**.

### 4.2 Tekli çift sayılar

Bu örnekte alfabe yalnız $\{1\}$'dir (ekrandan, 00:40:00). $q_0$ hem başlangıç hem kabul durumudur; $q_0$'dan 1 ile $q_1$'e, $q_1$'den 1 ile tekrar $q_0$'a geçilir. Hiç 1 okumamak, $11$ ve $1111$ kabul edilir; yani 1'lerin sayısı çift olmalıdır. Dizgiyi tekli sayı olarak düşünürsek bu otomat **çift sayıları** kabul eder:

$$EVEN = \{x : x \in \Sigma^* \text{ ve } x \text{ çift}\} = \{\varepsilon, 11, 1111, 111111, \dots\}$$

Dile $L$ yerine $EVEN$ gibi anlamlı bir ad da verilebilir. Bu tanımda boş dizgi de çift sayılır.

## 5. DFA'nın Biçimsel Tanımı

Şimdiye kadar örneklere bakıldı ama otomat biçimsel olarak tanımlanmadı. Bir deterministik sonlu otomat bir **5'lidir** (5-tuple). Hoca 5'liyi beş elemanlı ve sırası önemli bir liste gibi düşünmemizi söyledi:

$$M = (Q, \Sigma, \delta, q_0, F)$$

- $Q$: durumlar kümesi.
- $\Sigma$: giriş alfabesi. Boş dizgi alfabenin elemanı değildir.
- $\delta$: geçiş fonksiyonu; bir durumun bir sembolü okuyunca ne olacağını söyler.
- $q_0$: başlangıç durumu.
- $F$: kabul durumları kümesi.

Biçimsel tanım neden gerekir? Hoca bir örnek verdi: bir otomatın bir dizgiyi kabul edip etmediğine otomatik karar veren bir bilgisayar programı yazdığınızı düşünün. Bu program durum kümesini, alfabeyi, geçiş fonksiyonunu bilmek zorundadır; bunları tanımlamanız gerekir. Biçimsel tanımlar matematiksel ispatlarda da kullanılır.

> **Hocanın vurgusu:** Sınavlarda zaman zaman biçimsel tanım ya da biçimsel tanımın bir parçası sorulur.

İlk örnek için biçimsel tanımın parçaları grafikten doğrudan okunur:

- $Q = \{q_0, q_1, q_2, q_3, q_4, q_5\}$ (durumların içine yazılan etiketler).
- $\Sigma = \{a, b\}$.
- Başlangıç durumu, boşluktan gelen oktan anlaşıldığı gibi $q_0$'dır.
- Çift daireli tek durum $q_4$ olduğu için $F = \{q_4\}$. $F$'nin birden fazla elemanı da olabilir.

## 6. Geçiş Fonksiyonu, Geçiş Tablosu ve Genişletilmiş Geçiş Fonksiyonu

### 6.1 Geçiş fonksiyonu

Geçiş fonksiyonunun tanım kümesi, durumlar kümesi ile alfabenin Kartezyen çarpımıdır (ekrandan, 00:45:00):

$$\delta : Q \times \Sigma \to Q$$

Birinci parametre bir durum, ikinci parametre bir semboldür; fonksiyon bize yine bir durum verir. $\delta(q, x) = q'$, "otomat $q$ durumundayken sıradaki sembol $x$ okunursa otomat $q'$ durumuna geçer" demektir. Grafikte bu, $q$'dan $q'$'ye giden ve üzerinde $x$ yazan bir oktur. Geçiş fonksiyonu, grafikteki bütün geçişleri tarif eder: her durum ve her sembol için ne olacağını tanımlamalıdır. Örneğin $\delta(q_0, a) = q_1$.

### 6.2 Geçiş tablosu

Bütün geçişler listelenirse bir **geçiş tablosu** (transition table) elde edilir. Satır başlıklarına durumlar, sütun başlıklarına semboller yazılır. Bölüm 3'teki tablo, ilk örneğin geçiş tablosudur; örneğin $q_3$ satırı ile $b$ sütununun kesişiminde $q_5$ vardır, yani $q_3$'te $b$ okunursa otomat $q_5$'e geçer. Hoca her fonksiyonun tablo olarak yazılamayabileceğini, ama bu fonksiyonun yazılabildiğini belirtti.

### 6.3 Genişletilmiş geçiş fonksiyonu

**Genişletilmiş geçiş fonksiyonu** $\delta^*$ ile gösterilir. Bu kez ikinci parametre tek bir sembol değil, alfabeden yazılabilen bir dizgidir:

$$\delta^* : Q \times \Sigma^* \to Q$$

$\delta^*(q, w) = q'$, "$q$ durumundayken $w$ dizgisinin tamamı okunursa son durum $q'$ olur" demektir. Hoca bunun kısa bir gösterim olduğunu söyledi. İlk örnek için:

- $\delta^*(q_0, ab) = q_2$: $q_0 \xrightarrow{a} q_1 \xrightarrow{b} q_2$ (ekrandan, 00:50:00).
- $\delta^*(q_0, abbba) = q_5$: $q_0 \to q_1 \to q_2 \to q_3 \xrightarrow{b} q_5 \xrightarrow{a} q_5$.
- $\delta^*(q_1, bba) = q_4$: $q_1 \to q_2 \to q_3 \to q_4$.

<!-- BELİRSİZ: İkinci örneğin slayttaki tam dizgisi karede görünmüyor; altyazıda "ABBBA" geçiyor. Bu dizgiyle sonuç q5 çıkıyor (python ile doğrulandı). -->

Özel bir durum: herhangi bir $q$ durumunda boş dizgi okunursa, yani aslında hiçbir şey okunmazsa durum değişmez:

$$\delta^*(q, \lambda) = q$$

Genel olarak $\delta^*(q, w) = q'$ ise, $q$'dan $q'$'ye giden ve etiketleri sırayla $w = \sigma_1 \sigma_2 \cdots \sigma_k$ sembollerini veren bir **geçiş yürüyüşü** (walk) vardır. $q$'dan başlanır, önce $\sigma_1$, sonra $\sigma_2$ okunur ve son sembol okunduğunda $q'$'ye varılır. Bu yürüyüşte bazı durumlar tekrar edebilir; örneğin bir döngüde birkaç kez dönüp sonra $q'$'ye girilebilir.

## 7. Bir DFA'nın Dili

Aradan sonra hoca DFA'nın dilini tanımladı (ekrandan, 01:00:00). $M$ DFA'sının kabul ettiği dil $L(M)$ ile gösterilir ve $M$'nin kabul ettiği bütün dizgileri içerir. Ayrıca "$M$, $L(M)$'yi **tanır**" (recognizes) da denir; yani dildeki dizgileri kabul eder.

Matematik gösterimiyle, $M = (Q, \Sigma, \delta, q_0, F)$ için (ekrandan, 01:10:00):

$$L(M) = \{ w \in \Sigma^* : \delta^*(q_0, w) \in F \}$$

Okunuşu şöyledir: alfabeden yazılabilen bütün dizgiler arasından öyle $w$'ler ki, başlangıç durumu $q_0$'dan başlayıp $w$ taranınca varılan $q'$ durumu $F$'nin, yani kabul durumları kümesinin elemanıdır.

$M$'nin **reddettiği dil**, kabul ettiği dilin tümleyenidir. Gösterim neredeyse aynıdır; tek fark son durumun kabul durumları kümesinde olmamasıdır:

$$\overline{L(M)} = \{ w \in \Sigma^* : \delta^*(q_0, w) \notin F \}$$

## 8. Daha Fazla DFA Örneği

Hoca, alfabe yine $\{a, b\}$ iken birkaç küçük DFA'yı sırayla gösterip her birinin dilini sordu:

- **Kabul durumu olmayan DFA:** tek durumlu ve kabul durumu yok. Dil boş kümedir: $L(M) = \{\}$.
- **Tek durumlu, kabul eden DFA:** tek durum hem başlangıç hem kabul durumudur. Her dizgiyi kabul eder: $L(M) = \Sigma^*$.
- **Yalnız boş dizgi:** başlangıç durumu kabul durumudur; hangi sembol okunursa okunsun tuzak durum $q_1$'e geçilir ve orada kalınır. Başta kabul durumundayız, sonra ne okunursa ret. Dil $L(M) = \{\lambda\}$.
- **$ab$ önekli bütün dizgiler:** başlangıçta $b$ okunursa tuzağa düşülür; kabul durumuna varmak için önce $a$, sonra $b$ okunmalıdır. Kabul durumunda $a$ ve $b$ için döngü vardır, yani baştaki $ab$'den sonra ne okunduğu önemli değildir. Dil: $\{a, b\}^*$ içindeki $ab$ önekli bütün dizgiler.

### 8.1 001 alt dizgisini içeren ikili dizgiler

Bu örnekte (ekrandan, 01:15:00) durumlar, o ana kadar okunan ilgili kısmı gösteren etiketler taşır: başlangıç durumu $\lambda$ ile etiketlidir. Geçişler:

| Durum | $0$ | $1$ |
|---|---|---|
| $\lambda$ (başlangıç) | $0$ | $\lambda$ |
| $0$ | $00$ | $\lambda$ |
| $00$ | $00$ | $001$ |
| $001$ (kabul) | $001$ | $001$ |

Kabul durumuna nasıl varılır? Başta istenen sayıda 1 okunabilir ($\lambda$'da döngü), sonra bir 0 ile "$0$" durumuna, bir 0 daha ile "$00$" durumuna geçilir. "$00$" durumunda 0 için döngü vardır, yani buradan sonra istenen sayıda 0 okunabilir. Ardından bir 1 okununca kabul durumu "$001$"e varılır ve orada 0 ve 1 için döngü olduğundan sonrasında ne okunursa okunsun kabul edilir. Hoca bunu "$n$ tane 1, iki 0, $m$ tane 0, bir 1, sonra herhangi bir şey" diye özetledi ve koşulun dizgide $001$ alt dizgisinin bulunması olduğunu söyledi:

$$L(M) = \{\text{001 alt dizgisini içeren bütün ikili dizgiler}\}$$

> **Ders sonrası not:** Hocanın "$1^n\,00\,0^m\,1\ldots$" özeti yalnız sezgi içindir. "$0$" durumunda 1 okununca başa ($\lambda$'ya) dönüldüğü için $01001$ gibi önünde 0 bulunan dizgiler de kabul edilir. Dilin doğru tarifi "001 alt dizgisini içeren" tarifidir; tablodaki DFA'nın bu dili tanıdığı 10 uzunluğa kadar bütün dizgilerle python ile doğrulandı.

### 8.2 001 içermeyen dizgiler: tümleyen

Sıradaki grafik neredeyse aynıdır, ama bu kez $\lambda$, $0$ ve $00$ kabul durumu, $001$ ise kabul olmayan durumdur. Bu otomat önceki otomatın tersi gibidir: önceki otomatın kabul ettiği her dizgiyi reddeder, reddettiği her dizgiyi kabul eder. Dili $001$ alt dizgisini **içermeyen** bütün ikili dizgilerdir.

> **Hocanın vurgusu:** Bir dilin tümleyenini tanıyan DFA'yı çizmek için önce özgün dilin DFA'sı çizilir, sonra kabul durumları kabul olmayan, kabul olmayanlar kabul durumu yapılır. Bu yer değiştirme sonucunda dil, özgün dilin tümleyeni olur.

### 8.3 $\{awa : w \in \{a,b\}^*\}$

Dil, $a$ ile başlayıp $a$ ile biten dizgilerden oluşur; arada $\{a, b\}$ ile yazılabilen her şey olabilir (ekrandan, 01:20:00). $w$ boş dizgi olabilir, o zaman dizgi $aa$ olur; yani dizgide en az iki $a$ bulunur. DFA:

| $\delta$ | $a$ | $b$ |
|---|---|---|
| $q_0$ (başlangıç) | $q_2$ | $q_1$ |
| $q_1$ (tuzak) | $q_1$ | $q_1$ |
| $q_2$ | $q_3$ | $q_2$ |
| $q_3$ (kabul) | $q_3$ | $q_2$ |

Hoca tasarımı şöyle açıkladı. İlk sembol $a$ olmalıdır; $b$ ise tuzak durum $q_1$'e gidilir. İlk $a$'dan sonra istenen sayıda $b$ gelebilir ($q_2$'de döngü). $q_2$'de bir döngü $a$ için de konabilirdi, ama son sembol $a$ olduğunda otomatın kabul etmesi gerekir. Bu yüzden $q_2$'den $a$ ile kabul durumu $q_3$'e geçilir ve $a$ geldikçe orada kalınır, çünkü son sembol hâlâ $a$'dır. $b$ gelince son sembol $b$ olur; dizgi reddedilmelidir, bu yüzden $q_2$'ye dönülür. $q_2$ kabul olmayan bir durumdur; $b$ geldikçe orada kalınır, $a$ gelir gelmez tekrar kabul durumuna geçilir.

## 9. Düzenli Diller ve Düzenli Olmayan Diller

Bir $L$ dilini kabul eden bir $M$ DFA'sı varsa, yani $L(M) = L$ ise, $L$ **düzenli** (regular) bir dildir. Hoca "dil ailesi" kavramını da tanıttı: bir dil ailesi, bir şekilde birbirine benzeyen dillerin kümesidir. **Düzenli diller ailesi**, DFA'ların kabul ettiği bütün dillerden oluşur.

Düzenli dil örnekleri (ekrandan, 01:25:00):

- $\{abba\}$, $\{\lambda, ab, abba\}$
- $\{a^n b : n \ge 0\}$, $\{awa : w \in \{a,b\}^*\}$
- $\{a,b\}^*$ içinde $ab$ önekli bütün dizgiler
- $001$ alt dizgisini içermeyen bütün ikili dizgiler
- $\{x : x \in \{1\}^* \text{ ve } x \text{ çift}\}$
- $\{\}$, $\{\varepsilon\}$, $\{a, b\}^*$

Hoca bu kümelerin hepsinin önceki slaytlarda örnek olarak geçtiğine dikkat çekti: hepsi için onları kabul eden bir DFA gördük, demek ki hepsi düzenlidir.

Bazı diller ise **düzenli değildir**; yani onları kabul eden hiçbir DFA yoktur.

- $\{a^n b^n : n \ge 0\}$: $a$'ların sayısı $b$'lerin sayısına eşit olmalıdır ($ab$, $aabb$, $aaabbb$, ...; boş dizgi de dildedir). DFA'ların sembol sayma özelliği yoktur; iki farklı sembolün sayısını sayıp eşleştiremezler. Böyle bir DFA çizmeyi deneyebilirsiniz ama çizemezsiniz.
- Tekli toplama dili: sayılar tekli yazıldığında $z$'deki 1 sayısı $k$, $n + m$'ye eşit olmalıdır. Burada da bir denklem vardır.

Her iki dilde de bir eşitlik denetimi gerekir ve DFA'lar bu tür bir denetim yapamaz. Hoca bunun ispatlanabileceğini ve nasıl ispatlanacağını ilerleyen derslerde göreceğimizi söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu tür dillerin düzenli olmadığı genellikle düzenli diller için pompalama önsavı (pumping lemma) ile ispatlanır. Sezgisel neden, DFA'nın sonlu sayıda durumu olması ve bu yüzden sınırsız büyüyebilen bir sayacı tutamamasıdır.

Hoca bu kısmın kolay ve hatta eğlenceli olduğunu söyleyerek NFA'lara geçti.

## 10. Deterministik Olmayan Sonlu Otomat (NFA)

### 10.1 Birden çok geçiş ve paralel hesaplama

**Deterministik olmayan sonlu otomatlar** (Nondeterministic Finite Automaton, NFA) yine sonlu otomattır ama deterministik değildir. İlk örnekte alfabe yalnız $\{a\}$'dır (ekrandan, 01:30:00):

- $q_0 \xrightarrow{a} q_1$, $q_1 \xrightarrow{a} q_2$ ($q_2$ kabul durumu)
- $q_0 \xrightarrow{a} q_3$

$q_0$ durumunda $a$ okunduğunda **iki farklı duruma** gidilebilir. DFA'da bir sembol okununca gidilebilecek tek bir durum vardı; NFA'da birden fazla olabilir. Bu kafa karıştırıcı olabilir, çünkü sonlu otomat bir anda tek durumdadır. Hoca bunu şöyle düşünmemizi önerdi: bu noktada otomat **kendini çoğaltır**; artık iki paralel makine, yani iki paralel hesaplama vardır.

### 10.2 $aa$ girdisi: kabul

İlk $a$ okununca iki etkin dal vardır: $q_1$ ve $q_3$. İkinci $a$ okununca:

- $q_3$'ten $a$ için geçiş yoktur; bu paralel makine durur, ölür. Girdi tüketilemez ve otomat bu dalda durur (halts) (ekrandan, 01:35:00).
- $q_1$'deki makine devam eder, $a$'yı okuyup $q_2$'ye geçer; $q_2$ kabul durumudur.

Bir hesaplama dalının kabul etmesi yeterlidir: alt dal kabul etmese de üst dal $aa$'yı kabul ettiği için otomat $aa$'yı kabul eder. Hoca slaytlardaki sunuşta makinenin önce bir daldaki olanlara, sonra diğer dala bakıyormuş gibi gösterildiğini, ama bunların paralel hesaplamalar olduğunu belirtti.

Burada DFA'dan bir fark daha ortaya çıkar. DFA'da her sembol için ne olacağı gösterilmek zorundadır. NFA'da bir durum için bir sembolün geçişi yazılmamışsa, bu yalnız o durumun o sembolü okuyamayacağı anlamına gelir. Her sembol için geçiş yazmak gerekmediğinden grafik daha sade olur.

Özetle, bir NFA bir dizgiyi şu durumda **kabul eder**: dizgiyi kabul eden en az bir hesaplama yolu vardır, yani

- girdinin bütün sembolleri işlenmiştir ve
- hesaplama yollarından birinde son durum bir kabul durumudur.

### 10.3 Ret örnekleri

- **$a$ girdisi:** üst yol $q_1$'de, alt yol $q_3$'te biter; ikisi de kabul durumu değildir. Her iki yol da reddettiği için otomat $a$'yı reddeder.
- **$aaa$ girdisi:** üst yolda ilk iki $a$ ile kabul durumu $q_2$'ye varılır, ama üçüncü $a$ için $q_2$'den çıkan geçiş yoktur; ret. Alt yolda ilk $a$'dan sonra ikinci $a$ okunamaz; ret.

Bir NFA bir dizgiyi, dizgiyi kabul eden **hiçbir hesaplama yolu yoksa** **reddeder**. Başka bir deyişle her olası hesaplama yolu için ya girdinin tamamı tüketilmiş ve otomat kabul olmayan bir durumdadır ya da girdi tüketilememiştir. Bu NFA'nın dili $\{aa\}$'dır; yalnız $aa$ dizgisini kabul eder.

## 11. Epsilon (Null) Geçişleri

NFA'ların DFA'lardan bir farkı da **$\varepsilon$ geçişleri** (null transition) içerebilmeleridir. Örnek (ekrandan, 01:40:00):

$$q_0 \xrightarrow{a} q_1 \xrightarrow{\varepsilon} q_2 \xrightarrow{a} q_3 \quad (q_3 \text{ kabul})$$

$q_1$'deyken makine **hiçbir şey okumadan** doğrudan $q_2$'ye geçer. Bu da bir dallanma gibidir: geçiş olduğunda $q_1$ hâlâ etkindir; makine bir $a$ alırsa $q_1$ de onu okuyabilir. Etkin olarak $\varepsilon$ geçişleri de hesaplama dalları oluşturur.

- **$aa$ girdisi:** başta $q_0$'dayız. $a$ okunur, $q_1$'e geçilir. Hiçbir şey okunmadan $q_2$'ye geçilir; bu sırada giriş şeridinin okuma kafası **ilerlemez**. Sonraki $a$'yı $q_2$ okur ve $q_3$'e geçer. Girdinin tamamı tüketilmiştir ve bulunulan durum bir kabul durumudur; $aa$ kabul edilir.
- **$aaa$ girdisi:** $q_0 \xrightarrow{a} q_1 \xrightarrow{\varepsilon} q_2 \xrightarrow{a} q_3$. Girdinin tamamını okumak için bir $a$ daha okunmalıdır ama $q_3$'ten $a$ geçişi yoktur; otomat durur ve $aaa$ reddedilir.

Bu NFA'nın dili de $\{aa\}$'dır.

> **Ders sonrası not:** Altyazıda $aaa$ örneğinde hoca bir an "Q2 cannot consume" dedi; tüketemeyen durum $q_3$'tür. Ayrıca "language rejected is again AA" dedi; kastedilen kabul edilen dildir: $L(M) = \{aa\}$.

## 12. Hesaplama Ağacı

Sonraki örnekte $\varepsilon$ geçişleri bir döngü oluşturur (ekrandan, 01:45:00):

- $q_0 \xrightarrow{a} q_1 \xrightarrow{b} q_2$ ($q_2$ kabul durumu)
- $q_2 \xrightarrow{\varepsilon} q_3$, $q_3 \xrightarrow{\varepsilon} q_0$

$q_0$'dan başlanır, $a$ okununca $q_1$'e, $b$ okununca $q_2$'ye geçilir. Ama hiçbir şey yapmadan, $\varepsilon$ geçişi yüzünden $q_3$ de etkin olur, bir sonraki $\varepsilon$ geçişi yüzünden $q_0$ da yeniden etkin olur. Yani $ab$ okunduktan sonra **üç paralel otomat**, üç paralel hesaplama yolu vardır: $q_2$, $q_3$, $q_0$.

Bundan sonra bir sembol daha okunursa, bu yolların her birinin o sembolü okuyup okuyamadığına tek tek bakmak gerekir. Örneğin bir $a$ okunsun:

- $q_2$ $a$'yı okuyamaz; bu yol durur, ölür.
- $q_3$'ten çıkan $a$ geçişi yoktur; bu yol da ölür.
- $q_0$ $a$'yı okur ve $q_1$'e geçer.

Bu örnekte hesaplama dalları üçten bire iner. Başka örneklerde dallar ölmeyebilir; o zaman aynı anda birkaç hesaplama yolu etkin kalır ve her biri sonraki sembolü tüketebilir ya da tüketemez. Hoca bu sırada "accept" demek yerine "consume" (tüketmek) ya da "read" (okumak) demek gerektiğini, çünkü kabulün dizgi düzeyinde bir kavram olduğunu belirtti.

Bu şekilde etkin durumları her sembol için alt alta dallandırarak çizerseniz bir **hesaplama ağacı** (computation tree) elde edersiniz (ekrandan, 01:50:00). $aba$ girdisi için tahtada çizilen ağaç şöyledir:

```text
q0
 |-- a --> q1
            |-- b --> q2 (kabul)
                       |-- eps --> q3
                       |            |-- eps --> q0
                       |
okunan a:  q2: X (okuyamaz)   q3: X (okuyamaz)   q0 --a--> q1
```

> **Hocanın vurgusu:** Bu kısım slaytlarda yok. Bir NFA'nın ne yaptığı bakınca hemen görülebiliyorsa ağaç çizmeye gerek yok. Ama hoca, bazı NFA'ların ne yaptığını anlamak için birkaç örnek girdi üzerinde hesaplama ağacı çizmeyi kendisinin de tercih ettiğini söyledi ve not alınmasını istedi. Hesaplama ağacı girdiye bağlıdır; çizmek için bir girdiniz olmalıdır. Kavram ders kitabında da geçer.

Hoca bu NFA'nın dilini de verdi:

- $ab$: $q_0 \xrightarrow{a} q_1 \xrightarrow{b} q_2$; kabul.
- $abab$: $a$, $b$ ile $q_2$'ye varılır, $\varepsilon$ geçişleriyle hiçbir şey okumadan $q_0$'a dönülür; sonraki $a$ ve $b$ ile yine $q_2$'ye varılır; kabul.

Dil iki kümenin birleştirmesi olarak yazılır: birinci küme yalnız $ab$ dizgisini, ikinci küme $\{ab\}$'nin yıldız kapanışını içerir.

$$L(M) = \{ab\}\{ab\}^*$$

Yani her zaman bir ilk $ab$ vardır; ondan sonra sıfır ya da daha fazla $ab$ gelebilir.

## 13. Diğer NFA Örnekleri

### 13.1 $\{10\}^*$

Hoca ikinci aradan sonra bu NFA'yı gösterip "bunun neyi kabul ettiğini düşünüyorsunuz?" diye sordu (ekrandan, 02:15:00):

- $q_0$ hem başlangıç hem kabul durumu.
- $q_0 \xrightarrow{1} q_1$, $q_1 \xrightarrow{0} q_0$, $q_1 \xrightarrow{0,1} q_2$.
- $q_0 \xrightarrow{\varepsilon} q_2$.

Başlangıç durumu kabul durumu olduğu için boş dizgi dildedir. Hiçbir şey okumadan $\varepsilon$ geçişiyle $q_2$'ye de ulaşıldığı için başta iki etkin durum vardır: $q_0$ ve $q_2$.

- 1 okununca: $q_0$, $q_1$'e geçer. $q_2$'den hiçbir geçiş çıkmadığı için $q_2$ 1'i okuyamaz ve ölür.
- Ardından 0 okununca: $q_1$, $q_0$'a geçer; $q_0$ da $\varepsilon$ ile doğrudan $q_2$'ye geçer. Ayrıca $q_1$ 0 ile kendisi de $q_2$'ye gider. Yani $q_2$'ye iki farklı yoldan ulaşılır; ikinci bir $q_2$ yazılabilir ama sonucu değiştirmez, biri yeterlidir.

$q_2$ hiçbir sembolü okuyamadığı ve kabul durumu olmadığı için bir tür tuzak durumdur; oraya giden kısımla ilgilenmemiz gerekmez. Kabul eden kısım şudur: bir 1 ve ardından bir 0 okununca kabul durumu $q_0$'a dönülür. Böylece $10$, $1010$, ... kabul edilir:

$$L(M) = \{10\}^* = \{\varepsilon, 10, 1010, 101010, \dots\}$$

(Altı uzunluğa kadar bütün ikili dizgiler denenerek python ile doğrulandı.)

### 13.2 Basit NFA'lar ve NFA'ların avantajı

Alfabe $\{a\}$ iken iki basit NFA gösterildi: biri **hiçbir şeyi** kabul etmez (dil $\{\}$), diğeri yalnız **boş dizgiyi** kabul eder (dil $\{\lambda\}$).

NFA'lar dilleri çizerken daha kolay ifade eder (ekrandan, 02:20:00). Örneğin $\{a\}$ dili için:

- NFA $M_1$: $q_0 \xrightarrow{a} q_1$ ($q_1$ kabul). Bu kadar.
- DFA $M_2$: $q_0 \xrightarrow{a} q_1$ ($q_1$ kabul), $q_1 \xrightarrow{a} q_2$, $q_2$'de $a$ ile döngü. DFA'da her durumdan her sembol için geçiş gerektiğinden tuzak durum eklenmek zorundadır.

Her iki otomatın dili de $\{a\}$'dır. Hoca alfabe $\{a, b, c\}$ gibi büyüdüğünde DFA'da her durum için $a$, $b$ ve $c$'nin ne yaptığını göstermek gerektiğini, bunun grafikleri epey kalabalık ve karmaşık yapabildiğini, NFA'ların ise aynı dili daha temiz bir grafikle ifade edebildiğini söyledi.

## 14. NFA'nın Biçimsel Tanımı

NFA'nın biçimsel tanımı DFA'nınkine çok benzer; yine bir 5'lidir:

$$M = (Q, \Sigma, \delta, q_0, F)$$

- $Q$: bütün durumların kümesi.
- $\Sigma$: alfabe, yani semboller kümesi; boş dizgi yine alfabede değildir.
- $\delta$: geçiş fonksiyonu.
- $q_0$: başlangıç durumu.
- $F$: kabul durumları kümesi.

Fark geçiş fonksiyonundadır. NFA'da $q$ durumunda $x$ okununca birden fazla duruma gidilebilir. Bu yüzden $\delta(q, x)$ tek bir durum değil, $q$'dan $x$ ile gidilebilecek **bütün durumların kümesidir**:

$$\delta(q, x) = \{q_1, q_2, \dots, q_k\}$$

DFA'da sonuç $q_1$ ya da $q_2$ gibi tek bir durumdu; burada bir durum kümesidir. $\{10\}^*$ örneğindeki NFA için (ekrandan, 02:25:00):

- $\delta(q_0, 1) = \{q_1\}$
- $\delta(q_1, 0) = \{q_0, q_2\}$: $q_1$'den 0 okununca $q_0$'a ya da $q_2$'ye gidilebilir; fonksiyon ikisini de içeren kümeyi verir.
- $\delta(q_0, \varepsilon) = \{q_2\}$: $q_0$'dan hiçbir şey okumadan $q_2$'ye ulaşılır; bu da hesaba katılmalıdır.
- $\delta(q_2, 1) = \emptyset$: $q_2$ 1'i tüketemez, hiçbir yere gidilemez; sonuç boş kümedir.

> **Ek bilgi (derste anlatılmadı):** Bu tanıma göre NFA'nın geçiş fonksiyonu genellikle $\delta : Q \times (\Sigma \cup \{\varepsilon\}) \to 2^Q$ biçiminde yazılır; $2^Q$, $Q$'nun bütün alt kümelerinin kümesidir (kuvvet kümesi).

## 15. NFA'da Genişletilmiş Geçiş Fonksiyonu ve Dil

### 15.1 $\delta^*$

DFA'da olduğu gibi NFA için de genişletilmiş geçiş fonksiyonu $\delta^*$ tanımlanır. İkinci parametre bir dizgidir ve sonuç yine bir durum kümesidir. Hoca $F = \{q_0, q_5\}$ olan şu NFA'yı kullandı (ekrandan, 02:35:00):

- $q_0 \xrightarrow{a} q_1$
- $q_1 \xrightarrow{a} q_4$, $q_1 \xrightarrow{a} q_5$
- $q_1 \xrightarrow{b} q_2$
- $q_2 \xrightarrow{\varepsilon} q_3$, $q_3 \xrightarrow{\varepsilon} q_0$

Örnekler:

- $\delta^*(q_0, a) = \{q_1\}$.
- $\delta^*(q_0, aa) = \{q_4, q_5\}$: ilk $a$ ile $q_1$'e, ikinci $a$ ile $q_4$'e ya da $q_5$'e gidilir. Sonuçta ikisi birden etkindir. Hoca kümedeki virgülün matematikte "ve" diye okunduğunu söyledi.
- $\delta^*(q_0, ab) = \{q_2, q_3, q_0\}$: üçü de etkindir.

Her $q$ durumu için $q \in \delta^*(q, \lambda)$'dır: bir durum boş dizgiyi alırsa kendisi sonuç kümesindedir. Kümede başka elemanlar da olabilir (örneğin $\varepsilon$ geçişleriyle ulaşılan durumlar), ama $q$ mutlaka bir elemandır. Hoca bunun mantıklı olduğunu belirtti.

Genel olarak $q_j \in \delta^*(q_i, w)$ ise, $q_i$'den $q_j$'ye $w$ etiketli bir yürüyüş vardır (ekrandan, 02:30:00). $w = \sigma_1 \sigma_2 \cdots \sigma_k$'nın sembolleri bazı durumlar tarafından tek tek tüketilir, arada döngüler olabilir ve son sembol tarandığında $q_j$'ye varılır. Bu bir NFA olduğu için sonuç kümesinde başka $q_k$ durumları da olabilir, ama $q_j$ sonuç kümesindedir.

### 15.2 NFA'nın dili

NFA'nın dili DFA'nınkine çok benzer şekilde tanımlanır. $M$'nin kabul ettiği dil, başlangıç durumu $q_0$'dan başlayıp tarandığında elde edilen durum kümesinin **en az bir elemanı** kabul durumu olan dizgilerden oluşur:

$$L(M) = \{ w \in \Sigma^* : \delta^*(q_0, w) \cap F \neq \emptyset \}$$

Resimle: $q_0$'dan başlanır, $w$ taranır ve bazı durumlara varılır; bu durumlardan en az biri çift daireli olmalıdır.

<!-- BELİRSİZ: Bu slaytın gösterimi karede görünmüyor; hoca tanımı sözlü olarak "sonuç kümesinin elemanlarından biri kabul durumları kümesinin de elemanıdır" diye verdi. Yukarıdaki kesişim yazımı bu sözlü tanımın karşılığıdır. -->

### 15.3 Örnek üzerinde dil

Aynı NFA ($F = \{q_0, q_5\}$) için:

- **$aa$:** $\delta^*(q_0, aa) = \{q_4, q_5\}$. $q_5$ kabul durumu olduğu için $aa \in L(M)$.
- **$ab$:** $a$ ile $q_1$'e, $b$ ile $q_2$'ye gidilir; hiçbir şey okumadan $q_3$ ve $q_0$'a da ulaşılır. $\delta^*(q_0, ab) = \{q_2, q_3, q_0\}$ ve $q_0$ kabul durumu olduğu için $ab \in L(M)$.
- **$abaa$:** $a$, $b$ ile $q_0$'a dönülür, sonra $a$ ile $q_1$'e, son $a$ ile $q_4$ ve $q_5$'e gidilir. $q_5$ kabul durumu olduğu için $abaa \in L(M)$.
- **$aba$:** $a$, $b$ ile $q_2$'ye gidilir; $q_3$ ve $q_0$ da etkindir. Sonra bir $a$ gelir: $q_2$ ve $q_3$ $a$'yı tüketemez, yalnız $q_0$ $q_1$'e geçer. Sonuç kümesinde yalnız $q_1$ vardır: $\delta^*(q_0, aba) = \{q_1\}$. $q_1$ kabul durumu olmadığı için $aba \notin L(M)$.

Bu sonuçlar python ile de doğrulandı. Sonuçta bu otomatın dili şöyledir:

$$L(M) = \{ab\}^* \cup \{ab\}^*\{aa\}$$

Nedeni şudur: bir $a$ ve ardından $b$ taranınca $q_2$'ye varılır ve $\varepsilon$ geçişleriyle $q_0$'a dönülür. Böylece $ab$, $abab$, $ababab$, ... yani istenen sayıda $ab$ kabul edilir ($q_0$ kabul durumu olduğu için sıfır tane $ab$ de). Hoca birleşimin matematikte "veya" diye okunduğunu hatırlattı: sıfır ya da daha fazla $ab$, **veya** birkaç $ab$ ile başa dönüldükten sonra bir $aa$ okunup $q_5$'e varılması. Bu iki kümenin birleşimi otomatın dilidir.

Hoca, sıradaki konunun büyük olduğunu ve kalan süreye sığmayacağını söyleyerek dersi burada bitirdi; bir sonraki konu "NFA'lar düzenli dilleri kabul eder" başlığıdır (ekrandan, 02:40:00).

## Örnek Sorular

**Soru 1** (derste sözlü, 00:32:02): Aşağıdaki DFA neyi kabul eder? $q_0$'da $a$ ile döngü, $q_0 \xrightarrow{b} q_1$ (kabul), $q_1 \xrightarrow{a,b} q_2$, $q_2$'de $a,b$ ile döngü.

> **Çözüm:** $q_2$ tuzak durumdur. Önce istenen sayıda $a$, sonra tek bir $b$ okunmalıdır; $b$'den sonra gelen her sembol tuzağa götürür. $L = \{a^n b : n \ge 0\}$; dil sonsuzdur.

**Soru 2** (derste sözlü, 01:11:08): Alfabe $\{a,b\}$ iken (a) kabul durumu olmayan tek durumlu DFA, (b) tek durumu kabul durumu olan DFA, (c) başlangıç durumu kabul durumu olan ve her sembolde bir tuzak duruma giden DFA neyi kabul eder?

> **Çözüm:** (a) $\{\}$, (b) $\{a,b\}^*$, (c) $\{\lambda\}$.

**Soru 3** (derste sözlü, 01:19:01): $\{awa : w \in \{a,b\}^*\}$ dilini kabul eden bir DFA nasıl kurulur?

> **Çözüm:** Bölüm 8.3'teki tablo: ilk sembol $b$ ise tuzak; ilk $a$'dan sonra son okunan sembol $a$ ise kabul durumu $q_3$'te, $b$ ise $q_2$'de bulunulur. En kısa kabul edilen dizgi $aa$'dır.

**Soru 4** (derste sözlü, 02:13:22): Bölüm 13.1'deki NFA ($q_0 \xrightarrow{1} q_1$, $q_1 \xrightarrow{0} q_0$, $q_1 \xrightarrow{0,1} q_2$, $q_0 \xrightarrow{\varepsilon} q_2$; $q_0$ başlangıç ve kabul) neyi kabul eder?

> **Çözüm:** $q_2$ ölü bir daldır; kabul eden tek yol $1$ ve ardından $0$ ile $q_0$'a dönmektir. $L = \{10\}^*$.

**Soru 5** (derste sözlü, 02:35:51): $F = \{q_0, q_5\}$ olan Bölüm 15.1'deki NFA için $aa$, $ab$, $abaa$ ve $aba$ dilde midir?

> **Çözüm:** $\delta^*(q_0, aa) = \{q_4, q_5\}$, $\delta^*(q_0, ab) = \{q_2, q_3, q_0\}$, $\delta^*(q_0, abaa) = \{q_4, q_5\}$: üçü de dilde. $\delta^*(q_0, aba) = \{q_1\}$: dilde değil.

**Soru 6** (derste sözlü, 02:10:34; hocanın paylaştığı alıştırma setinden): Alfabe $\{0, 1\}$ iken 1 ile başlayıp 0 ile biten dizgileri kabul eden DFA'yı çizin.

> **Çözüm (derste verilmedi):** Durumlar $A$ (başlangıç), $B$, $C$ (kabul), $T$ (tuzak):
>
> | $\delta$ | $0$ | $1$ |
> |---|---|---|
> | $A$ | $T$ | $B$ |
> | $B$ | $C$ | $B$ |
> | $C$ (kabul) | $C$ | $B$ |
> | $T$ | $T$ | $T$ |
>
> İlk sembol 0 ise tuzağa düşülür. İlk 1'den sonra son okunan sembol 0 ise $C$'de, 1 ise $B$'de bulunulur. Sekiz uzunluğa kadar bütün ikili dizgilerle python ile doğrulandı.

**Soru 7** (ekrandan, 02:10:00; alıştırma setinin ilk sorusu): Hesaplamaya neden ihtiyaç duyarız? Hesaplama için neden programlama diline ihtiyaç duyarız? Programlama dilini tanıyan/kabul eden otomatlara ya da makinelere neden ihtiyaç duyarız?

> **Çözüm (derste verilmedi):** Bu soru kavramsal bir tartışma sorusudur ve derste cevaplanmadı. Bu dersin çerçevesinde kısa bir cevap şöyle kurulabilir: hesaplama problemleri dillerin üyelik problemlerine çevrilebilir; bir programlama dili de geçerli programlardan oluşan bir dildir. Bir dizginin (programın) bu dile ait olup olmadığına karar verebilmek için onu tanıyan bir makine (otomat) gerekir. Otomatlar hangi problemlerin hangi kaynaklarla çözülebildiğini incelemenin matematiksel modelleridir.

## Dersin Toparlaması

Bu derste önce dil ve dizgi işlemleri hatırlatıldı, sonra ilk hesaplama modeli olan deterministik sonlu otomat (DFA) tanıtıldı. DFA bir giriş şeridini okuyup kabul ya da ret çıktısı veren, her an tek bir durumda bulunan ve her durum-sembol çifti için tam olarak bir geçişi olan bir makinedir. Biçimsel olarak $M = (Q, \Sigma, \delta, q_0, F)$ 5'lisidir; geçiş fonksiyonu tablo olarak yazılabilir, genişletilmiş geçiş fonksiyonu $\delta^*$ bir dizginin tamamının sonucunu verir ve dil $L(M) = \{w : \delta^*(q_0, w) \in F\}$ olarak tanımlanır. Bir DFA'nın kabul ettiği dillere düzenli diller denir; $\{a^n b^n\}$ gibi sayma gerektiren diller ise düzenli değildir. Tümleyen dil için kabul durumlarını yer değiştirmek yeterlidir.

İkinci bölümde deterministik olmayan sonlu otomatlar (NFA) görüldü. NFA'da bir sembolle birden fazla duruma geçilebilir, bazı geçişler tanımsız bırakılabilir ve $\varepsilon$ geçişleri girdi okumadan durum değiştirir. NFA, en az bir hesaplama yolu girdiyi tüketip kabul durumunda bitiyorsa dizgiyi kabul eder; paralel yolları izlemek için hesaplama ağacı çizmek yararlıdır. NFA'nın geçiş fonksiyonu ve genişletilmiş geçiş fonksiyonu durum kümesi döndürür ve dil, $\delta^*(q_0, w)$ kümesinde en az bir kabul durumu bulunan dizgilerden oluşur. Bir sonraki derste NFA'ların tam olarak düzenli dilleri kabul ettiği konusu işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
