# Ders 1 Genişletilmiş Notu: Olasılığın Yorumları, Küme Teorisi ve Fonksiyonlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı, Kapsamı ve Kaynakları
- 2. Belirsizlik ve Belirsizlik Altında Karar Verme
- 3. Olasılık Nedir? İki Yorum
- 4. Olasılıklar Neden Kümeler Üzerinden Hesaplanır?
- 5. Küme Kavramı ve Bilinen Kümeler
- 6. Alt Küme, Küme Eşitliği ve Özel Kümeler
- 7. Venn Diyagramları ve Küme İşlemleri
- 8. Ayrık Kümeler ve Bölüntü
- 9. De Morgan Yasası ve Dağılma Yasası
- 10. Çözümlü Örnek: Tümleyenlerin Kesişimi
- 11. Fonksiyonlar
- 12. Birebir (Tersinir) Fonksiyonlar
- 13. Kardinalite, Sonlu ve Sonsuz Kümeler

## 1. Dersin Amacı, Kapsamı ve Kaynakları

Ders olasılık ve istatistik üzerinedir. Anlatım İngilizce yapıldı, bazı terimlerin Türkçesi konuşuldu ve birkaç yer Türkçe tekrar edildi. Hoca, anlaşılmayan İngilizce kelimelerin sorulabileceğini, soruların Türkçe de sorulabileceğini söyledi.

### 1.1 Dersin Amacı ve İçeriği

Dersin amacı, belirsizlik (uncertainty) içeren problemleri olasılıksal ve istatistiksel modeller ve yöntemlerle modellemeyi ve çözmeyi öğrenmektir. Dersin içeriğinde temel olasılık kuralları, kesikli (discrete) ve sürekli (continuous) olasılık modelleri, betimsel istatistik (descriptive statistics) ve temel istatistiksel çıkarım (statistical inference) vardır.

Hoca, dersi geçen bir öğrencinin neler yapabilmesi gerektiğini de saydı:

- Sayısal verilerin istatistiklerini hesaplamak.
- Olaylardaki (phenomena) belirsizliği göstermek için olasılık ve rastgele değişken (random variable) kavramlarını kullanmak.
- Olasılık yoğunluk fonksiyonu (probability density function) ve birikimli dağılım fonksiyonu (cumulative distribution function) içeren olasılık hesaplama problemlerini çözmek.
- Yaygın olasılık dağılımlarını tanımak ve bunlarla ilgili problemleri çözmek.
- Güven aralığı (confidence interval) oluşturmak ve hipotez testi (hypothesis test) yapmak.

Bu kavramların çoğu dönem içinde öğretileceği için hoca, şimdilik anlaşılmamalarının sorun olmadığını belirtti.

### 1.2 Konu Akışı

Hoca, konu sırasının taslak olduğunu, biraz öne ya da arkaya kayabileceğini ve küçük ekleme ya da çıkarmalar olabileceğini söyledi. Dersin ilk bölümü olasılığa, ikinci bölümü istatistiğe ayrılmıştır.

1. Giriş ve temel olasılık.
2. Rastgele değişkenler ve dağılımları (iki hafta).
3. Beklenen değer (expectation), varyans (variance), kovaryans (covariance), korelasyon (correlation). Hoca bunları veriyi özetleyen istatistik parametreleri olarak tanımladı.
4. Kesikli dağılımlar (bir hafta) ve sürekli dağılımlar (iki hafta).
5. İstatistik: parametre tahmini (parameter estimation), güven aralıkları, hipotez testi, p-değerleri, varyanslar hakkında çıkarım.

### 1.3 Kaynak Kitaplar

Dersin iki önerilen kitabı vardır:

- Michael Baron, *Probability and Statistics for Computer Scientists*, 2. baskı.
- Hossein Pishro-Nik, *Introduction to Probability, Statistics and Random Processes*. Bu kitap internette ücretsiz bulunur.

Hoca, önceki yıllarda Baron'un kitabını kullandığını, bu yıl ikisini birlikte kullanmayı düşündüğünü söyledi. İki kitabın içeriği birbirine çok yakındır. Baron'un kitabında çok daha fazla alıştırma olduğu için çalışma açısından daha iyidir. Hocanın tavsiyesi iki kitaptan da çalışmaktır.

Türkçe kaynak önerilmiyor, ancak internetten bulunup kullanılabilir. Herhangi bir olasılık ve istatistik kitabı iş görür. Dersin ilk bölümü için bir olasılık kitabına, ikinci bölümü için bir istatistik kitabına bakılabilir.

> **Hocanın vurgusu:** Öğrenilecek şeylerin çoğu önce İngilizce çıkar, bir kısmı sonra Türkçeye çevrilir. Bu derstekiler gibi bir matematik kitabını İngilizce okuyup anlayamıyorsanız İngilizceye ayrıca zaman ayırmalısınız.

## 2. Belirsizlik ve Belirsizlik Altında Karar Verme

Hoca konuya, bu derste belirsizlikle (belirsizlik, uncertainty) başa çıkma yöntemlerini konuşacağımızı söyleyerek girdi. Bu yöntemlerin iki görevi vardır. Birincisi belirsizliği ölçmek, yani ne kadar belirsizlik olduğunu söyleyebilmektir. İkincisi belirsizlik varken karar vermektir. Hocaya göre belirsizlik altında karar vermek hayatta oldukça yaygındır. Bunu iki örnekle gösterdi.

**Borsa örneği.** Borsanın ya da satın aldığınız hissenin yükselip yükselmeyeceği belirsizdir. Hisse yüksek olasılıkla düşecekse belki satmalısınız. Yükselmesi daha olasıysa belki elinizde tutmalı ya da bir tane daha almalısınız.

**Hava durumu örneği.** Hoca burada sınıfa dolunun İngilizcesini sordu ve kelime *hail* olarak geçti. Soru şudur: Bugün İstanbul'a dolu yağacak mı, yağarsa dolu tanesi çok iri olacak mı? İri dolu bekliyorsak arabamızı kapalı otoparka koymayı düşünürüz. Ama otoparklar da büyük ihtimalle doludur, o zaman ne yapacağız? Hoca, hayatın bu tür belirsizliklerle dolu olduğunu söyledi. Bir şeyin olasılığını belirleyebilmemiz ve kararlarımızı bu olasılıklara dayandırabilmemiz gerekir. Bu ders bunu öğretmeyi amaçlar.

**Yapay zekâ.** Hoca, olasılığı öğrenmek için önemli bir nedeni de yapay zekâ olarak gösterdi. Yapay zekânın çok farklı uygulamaları vardır. Yapay zekâ bilmek iş bulma şansını artırır ve kendi işinizde kullanmanızı sağlar.

> **Hocanın vurgusu:** Yapay zekâ olasılık üzerine kuruludur. Yapay zekâyı anlamak için olasılığı bilmek gerekir. Bu da olasılığı bugün iş bulmak ya da kendi işinde yapay zekâ kullanmak açısından çok önemli kılar.

## 3. Olasılık Nedir? İki Yorum

Olasılığın ne olduğuna dair farklı yorumlar vardır. Hoca iki tanesini anlattı.

### 3.1 Frekans Yorumu

Birinci yorum frekansa dayanır. Hoca önce uzun süre hava durumu gözlemeyi düşündü, sonra daha kolay olduğu için para atışına geçti. Paranın bir yüzünde genellikle çok önemli bir kişinin resmi bulunur, bu yüze tura (heads) denir. Öbür yüzde genellikle paranın değeri yazar, örneğin bir lira. Bu yüze de yazı (tails) denir. Para atıldığında deneyin sonucu (outcome) tura ya da yazı olur.

Hoca, sayıları önce 500 diye başlayıp sonra değiştirerek şu örneği kurdu:

- **Verilen:** Para 1000 kez atılıyor. Yaklaşık 600 kez tura, yaklaşık 400 kez yazı geliyor.
- **Mantık:** Turanın ve yazının frekansı, bu sonuçların olasılıklarını gösterir.
- **İşlem:** Tura olasılığı $\approx \dfrac{600}{1000} = 0.6$. Aynı şekilde yazı olasılığı $\approx \dfrac{400}{1000} = 0.4$ (ara adım eklendi).
- **Sonuç:** Bu paranın tura olasılığı yaklaşık 0.6'dır. Hoca bunun hilesiz (fair) bir para olmadığını, ama olmak zorunda da olmadığını söyledi.

Oranlar python ile hesaplandı. Frekans yorumunun özü budur: Deneyi çok kez tekrarlar, bir sonucun görülme oranına bakarız.

### 3.2 İnanç Yorumu

Bazen olasılıktan söz ederken aslında inançtan (belief) söz ederiz. Bu durumda frekanstan söz etmek çok zordur. Hocanın örneği şu soruydu: Kutuplardaki buz, 50 yıl içinde bugünkü kütlesinin yarısına inecek mi?

Bu sorudaki deneyin uzunluğu 50 yıldır. Bu deneyi 1000 kez deneyemezsiniz. Olay ya bir kez olur ya da olmaz, her iki durumda da yalnızca bir kez yaşanır. Dolayısıyla kutup buzunun erime olasılığı, bizim bu erimeye olan inancımızdır. Bu inanç elbette dayanaksız değildir, bir şeylere dayanmalıdır. Ama sonuçta bir inançtır.

### 3.3 İki Yorumun İlişkisi

Hocaya göre bir noktada iki yorum birleşir ve ikisi için de aynı araçlar kullanılabilir. Daha ileride yollar ayrılır, ancak bu dersin amaçları açısından hangi yorumu seçtiğimizin önemi yoktur. Olasılığın araçlarını geliştireceğiz ve kullanacağız.

> **Ek bilgi (derste anlatılmadı):** Bu iki yorum büyük olasılıkla literatürde sıklıkçı (frequentist) ve Bayesçi yorum adlarıyla karşınıza çıkacaktır. Kısa notta da bu adlar kullanılmıştır. Hocanın "daha ileride yollar ayrılır" dediği yer büyük olasılıkla bu iki yaklaşımın ileri konulardaki farklarıdır.

## 4. Olasılıklar Neden Kümeler Üzerinden Hesaplanır?

Hoca birinci bölümü, olasılıkların kümeler üzerinden hesaplandığını söyleyerek kapattı. Bu yüzden kümeler çok önemlidir. Sıra şöyle olacak: Önce kümeler ve özellikleri, kümelerle nasıl çalışılacağı anlaşıldıktan sonra olasılıklar.

Aradan sonra aynı noktayı örnekle açtı. Olasılıktan söz ettiğimiz her yerde aslında bir küme vardır. Tek bir sonuçtan söz ediyor olsak bile durum aynıdır. "Bugün dolu yağacak mı?" diye sorduğumuzda dolu olasılığı, içinde tek bir olay bulunan bir kümenin olasılığıdır. Birçok zaman küme parantezlerini yazmayız, çünkü yazmamak daha kolaydır. Ama "1'in olasılığı" dediğimizde kastettiğimiz, tek elemanı 1 olan kümenin olasılığıdır:

$$P(1) \text{ yazımının anlamı } P(\{1\}) \text{ demektir.}$$

> **Hocanın vurgusu:** Olasılıktan söz ediyorsak aslında bir kümenin olasılığından söz ediyoruz. Küme teorisini gözden geçirmemizin nedeni budur.

## 5. Küme Kavramı ve Bilinen Kümeler

### 5.1 Küme Nedir, Nasıl Yazılır?

Küme (set), elemanlardan oluşan sırasız bir topluluktur (unordered collection). Bir küme iki yolla anlatılır.

Birincisi elemanları **listelemektir**:

$$B = \{1, 2, 3\}$$

İkincisi kümeyi **tarif etmektir**:

$$A = \{x^2 : x = 1, 2, 3, \dots\}$$

Buradaki iki nokta "öyle ki" (such that) diye okunur. Elemanın biçimini onun sağlaması gereken koşuldan ayırır. Hoca, iki nokta yerine dik çizginin de kullanılabildiğini gösterdi:

$$C = \{x/y \mid x \in \mathbb{N},\ y < 0.3\}$$

Bu örneği "ne olursa olsun" diyerek, yazımı göstermek için verdi. Dik çizgi de "öyle ki" diye okunur. İki gösterim de kullanılır.

> **Ders sonrası not:** Hocanın gösterim için verdiği $C$ kümesinde $y < 0.3$ koşulu $y = 0$ değerini dışlamaz. Altyazıda $y$'nin hangi kümeden geldiği de söylenmiyor. $x/y$ ifadesi $y = 0$ için tanımsız olduğundan $y \neq 0$ koşulu da gerekir.

Küme elemanlarının sayı olması gerekmez. Örneğin $D = \{H, T\}$ kümesi para atışının sonuçlarını gösterir. Tura (heads) için genellikle $H$, yazı (tails) için $T$ yazılır.

### 5.2 Bilinen Kümeler

Bazı kümeler iyi bilinir. Bunlar genellikle içinde çift çizgi bulunan harflerle yazılır.

- **Doğal sayılar** $\mathbb{N} = \{1, 2, 3, \dots\}$. Bunlar sayma sayılarıdır: birinci şey, ikinci şey, üçüncü şey. Bazı tanımlarda 0 bu kümeye dahildir, bazılarında değildir. Hoca bu ders için 0'ın dahil olmadığını kabul etti.
- **Tam sayılar** (integers) $\mathbb{Z} = \{\dots, -2, -1, 0, 1, 2, \dots\}$.
- **Reel sayılar** $\mathbb{R}$. Hocanın örneği 0.23'tür.
- **Rasyonel sayılar** $\mathbb{Q}$.

> **Ders sonrası not:** Rasyonel sayılar için altyazıda "three or two" (üç veya iki) geçiyor. Bu büyük olasılıkla "three over two" ($3/2$) söyleyişinin yanlış çözümlenmesidir. Kısa nottaki tanıma göre rasyonel sayılar $a/b$ ($a, b \in \mathbb{Z}$, $b \neq 0$) biçimindeki sayılardır.

## 6. Alt Küme, Küme Eşitliği ve Özel Kümeler

### 6.1 Alt Küme

$A$ kümesinin her elemanı aynı zamanda $B$'nin de elemanıysa $A$, $B$'nin alt kümesidir (subset). $A \subseteq B$ diye yazılır. Matematiksel olarak:

$$A \subseteq B \iff (x \in A \Rightarrow x \in B)$$

Burada $\in$ simgesi "elemanıdır" ya da "içindedir" diye okunur, $\Rightarrow$ simgesi ise "eğer ... ise" anlamındadır. Hoca, bu simgelerin bir şeyleri daha kısa yazmamızı sağladığını söyledi.

Dersteki iki örnek:

- $A = \{8, 9\}$ ve $B = \{7, 8, 9, 10\}$. $A$'nın her elemanı zaten $B$'de bulunduğu için $A \subseteq B$.
- Doğal sayılar ve tam sayılar. Hangisi alt kümedir? Doğal sayılar: $\mathbb{N} \subseteq \mathbb{Z}$.

### 6.2 Küme Eşitliği

Alt küme kavramıyla küme eşitliği tanımlanabilir:

$$A = B \iff A \subseteq B \text{ ve } B \subseteq A$$

Yani $A$'nın da $B$'nin de bütün elemanları her iki kümede bulunur.

### 6.3 Evrensel Küme ve Örneklem Uzayı

Özel kümelerin ilki evrensel kümedir (universal set). Evrensel küme, problemimizde ilgilendiğimiz bütün şeylerin kümesidir. Olasılık teorisinde bu kümeye örneklem uzayı (sample space) denir.

Gösterim kitaba göre değişir: Baron'un kitabında $\Omega$, Pishro-Nik'in kitabında $S$ kullanılır. Hoca, iki kitaptan da çalışılacaksa ikisinin de bilinmesi gerektiğini söyledi.

> **Ders sonrası not:** Altyazıda bu simge "Sigma" olarak geçiyor, kısa notta ise Baron'un simgesi $\Omega$ yazılı. Derste kullanılan simge büyük olasılıkla $\Omega$'dır. Bu notta da $\Omega$ kullanıldı.

Örneklem uzayı probleme göre değişir, çünkü farklı problemlerde önemli olan şeyler farklıdır. Hoca bunu hava durumuyla gösterdi. Bir uygulamada havanın yağmurlu, dolulu ya da güneşli olmasıyla ilgileniyorsanız ve başka hiçbir şey umurunuzda değilse örneklem uzayınız şudur:

$$\Omega = \{\text{yağmurlu}, \text{dolulu}, \text{güneşli}\}$$

Başka bir uygulamada yalnızca güneşli mi yağmurlu mu olduğuyla ilgilenebilirsiniz. Dolu olup olmamasını önemsemiyorsanız örneklem uzayınız şöyle olabilir:

$$\Omega = \{\text{güneşli}, \text{yağmurlu}\}$$

> **Hocanın vurgusu:** Örneklem uzayı probleme bağlıdır. Birçok olasılık probleminde yapılacak ilk iş örneklem uzayını yazmaktır.

### 6.4 Boş Küme ve Üst Küme

Diğer özel küme boş kümedir (null set, empty set). İçinde hiç eleman yoktur. $\emptyset$ ile ya da içine eleman yazılmamış küme parantezleriyle $\{\}$ gösterilir.

Boş küme her kümenin alt kümesidir. Örneklem uzayı da o problemdeki her kümenin üst kümesidir (superset). $A \supseteq B$ yazımı "$A$, $B$'nin üst kümesidir" demektir, yani $B$'nin bütün elemanları $A$'da da vardır. Üst küme, alt kümenin tersi bir ilişkidir.

> **Ders sonrası not:** Hoca "boş küme her elemanın alt kümesidir, örneklem uzayı her elemanın üst kümesidir" dedi. Alt küme ve üst küme ilişkisi kümeler arasında tanımlandığı için doğrusu "her kümenin" olmalıdır.

**Soru:** Subset'in Türkçesi alt küme ise superset'in Türkçesi nedir? **Cevap:** Hoca Türkçesini hiç duymadığını, "üst küme" diyeceğini ama bunu duymadan söylediğini belirtti.

## 7. Venn Diyagramları ve Küme İşlemleri

### 7.1 Venn Diyagramları

Kümelerle çalışırken güzel bir araç Venn diyagramlarıdır. Bunlar kümelerin görselleştirilmesidir. Genellikle örneklem uzayı bir dikdörtgen olarak çizilir, kümeler de bu dikdörtgenin içine çizilir. Kümelerin birbiriyle ilişkisini, yani kesişimlerini, birleşimlerini ve farklarını görmek için yararlıdır.

### 7.2 Birleşim

İki kümenin birleşimi (union), iki kümenin bütün elemanlarını içeren başka bir kümedir. $\cup$ simgesi (cup) ile gösterilir, $A \cup B$ "A birleşim B" diye okunur. Matematiksel tanım şöyledir:

$$x \in A \cup B \iff x \in A \text{ veya } x \in B$$

Hoca bu tanımı yazarken önce "ve" demeye başladı, sonra düzeltti: $x$ ya $A$'da ya da $B$'de olmalıdır, bu nedenle bağlaç "veya"dır. Venn diyagramında iki kümenin kapladığı bölgenin tamamı birleşimdir.

Örnek: $\{a, b\} \cup \{c\} = \{a, b, c\}$.

### 7.3 Kesişim

Kesişim (intersection), hem $A$'da hem de $B$'de bulunan elemanları içeren kümedir. $A \cap B$ diye yazılır ve "A kesişim B" diye okunur. Venn diyagramında iki kümenin üst üste bindiği alandır.

### 7.4 Tümleyen

Tümleyen (complement), örneklem uzayında olup $A$'da olmayan bütün elemanların kümesidir. Hoca bunun "değil" (not) diye okunabileceğini söyledi. Venn diyagramında dikdörtgenin $A$ dışında kalan kısmıdır.

Gösterim kitaba göre farklıdır: Baron'da $\bar{A}$, Pishro-Nik'te $A^c$. Hoca başka belgelerde üçüncü bir gösterim daha gördüğünü, üçünün de aynı anlama geldiğini söyledi.

<!-- BELİRSİZ: 01:38:55 civarında hocanın başka belgelerde gördüğünü söylediği üçüncü tümleyen gösterimi yalnız tahtada, altyazıda hangi simge olduğu anlaşılmıyor. -->

Hoca bu arada, bu konuların lise seviyesinde olduğunu, çoğu öğrencinin zaten bildiğini düşündüğünü söyledi. Yine de yazmasının iki nedeni vardı: Derste kullanılacak simgeleri belirlemek ve unutanlara hatırlatmak.

### 7.5 Fark

$A$ fark $B$, $A$'da olup $B$'de olmayan bütün elemanların kümesidir. Venn diyagramında $A$'nın $B$ ile kesişmeyen kısmıdır.

İki kitap burada da farklıdır. Şimdiye kadarki gösterim farkları topluca şöyledir:

| Kavram | Baron | Pishro-Nik |
|:---|:---|:---|
| Örneklem uzayı | $\Omega$ | $S$ |
| Tümleyen | $\bar{A}$ | $A^c$ |
| Fark | $A \setminus B$ | $A - B$ |

> **Hocanın vurgusu:** Baron'un fark işaretindeki çizgi ters eğik çizgidir (inverse slash). Dik çizgi ya da bölü işareti gibi yazmayın. Üst ucu sola doğru yatık olmalıdır.

Bunun nedeni, diğer iki simgenin başka anlamlar taşımasıdır. Dik çizgi $|$ ileride koşullu olasılıkta (conditional probability) kullanılacaktır. Eğik çizgi $/$ ise bölmedir, $A/B$ yazımı $2/3$ gibi bir bölme izlenimi verir.

## 8. Ayrık Kümeler ve Bölüntü

### 8.1 Ayrık Kümeler

İki kümenin kesişimi boş kümeyse bu kümelere ayrık (disjoint) ya da birbirini dışlayan (mutually exclusive) kümeler denir:

$$A \cap B = \emptyset$$

İkiden fazla küme için de ayrıklıktan söz edilebilir. $A_1, A_2, \dots, A_n$ kümeleri için:

$$A_i \cap A_j = \emptyset \quad \text{her } i \neq j \text{ için}$$

Yani $i$ ve $j$ farklıysa, örneğin $i = 1$ ve $j = 3$ iken $A_1$ ile $A_3$'ün kesişimi boştur. Bu durum bu kümelerin hepsi için geçerli olmalıdır.

**Soru:** Bunun Türkçesi neydi? **Cevap:** Hoca emin olmadığını söyledi. "Ayrık" demek istediğini, ama "ayrık" kelimesinin *discrete* için de kullanıldığını belirtti.

> **Ek bilgi (derste anlatılmadı):** Kısa notta *disjoint* için "ayrık", *discrete* için "kesikli" karşılığı kullanılmıştır. Bu ayrım büyük olasılıkla hocanın sözünü ettiği karışıklığı önler. Kesikli dağılımlar konusunda bu kelimeler yeniden karşınıza çıkacaktır.

<!-- BELİRSİZ: 01:47:08-01:48:56 arasında sınıfla konuşma var, altyazı bozuk. Disjoint teriminin Türkçesi konuşuluyor gibi, sonuç anlaşılmıyor. -->

### 8.2 Bölüntü

Bölme işlemi (partition), bir kümeyi ayrık kümelere ayırmaktır. Hoca örneklem uzayını bir dikdörtgen olarak çizip $A_1, A_2, A_3, A_4, A_5$ parçalarına böldü. Bu parçalar örneklem uzayının tamamını kaplar ve aralarında kesişim yoktur. O hâlde $A_1, \dots, A_5$ bir bölüntüdür.

Bölüntü bir kümeler topluluğudur. $A_1, \dots, A_n$ topluluğu, iki koşul sağlanıyorsa örneklem uzayının bir bölüntüsüdür:

1. Kümeler ayrıktır.
2. Birleşimleri örneklem uzayıdır: $A_1 \cup A_2 \cup \dots \cup A_n = \Omega$.

> **Ders sonrası not:** Hoca ayrık kümeler için "kesişimleri sıfır" dedi. Doğrusu kesişimleri boş kümedir ($\emptyset$), kendisinin de hemen önce yazdığı gibi. Sıfır bir sayıdır, boş küme değildir.

## 9. De Morgan Yasası ve Dağılma Yasası

### 9.1 De Morgan Yasası

Bir birleşimin tümleyeni, tümleyenlerin kesişimidir. Benzer şekilde bir kesişimin tümleyeni, tümleyenlerin birleşimidir:

$$\overline{A \cup B} = \bar{A} \cap \bar{B}, \qquad \overline{A \cap B} = \bar{A} \cup \bar{B}$$

Hoca bunları Baron'un gösterimiyle yazarken önce parantez koydu, sonra sildi. Üstteki tümleyen çizgisi zaten parantez görevi gördüğü için parantez gerekmez.

Yasa iki kümeyle sınırlı değildir. Pishro-Nik'in gösterimiyle:

$$(A_1 \cup A_2 \cup A_3 \cup \dots \cup A_n)^c = A_1^c \cap A_2^c \cap A_3^c \cap \dots \cap A_n^c$$

Birleşim, tümleyen alınınca kesişime dönüşür.

### 9.2 Dağılma Yasası

Dağılma yasasında (distribution law) $A$, parantez açılırken $B$ ve $C$'ye dağıtılır:

$$A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$$

Birleşim ve kesişimin yerleri değiştirilerek çok benzer ikinci kural elde edilir:

$$A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$$

Bu iki yasa ile De Morgan yasasının iki kümeli biçimleri ve üç kümeli birleşim biçimi, $\Omega = \{1, \dots, 6\}$ kümesinin bütün alt kümeleri üzerinde tek tek denenerek python ile doğrulandı.

## 10. Çözümlü Örnek: Tümleyenlerin Kesişimi

Hoca küme tekrarını kapatmadan önce basit bir örnek çözdü.

**Verilen:** $\Omega = \{1, 2, 3, 4, 5, 6\}$, $A = \{1, 2\}$, $B = \{2, 4, 6\}$.

<!-- BELİRSİZ: 02:16:14-02:16:23 arasında B kümesi altyazıda bozuk ("1, 2. to four six"). Hocanın sonraki hesabındaki B tümleyeni {1,3,5} ve birleşim {1,2,4,6} ile B = {2,4,6} olduğu anlaşılıyor. -->

**Soru:** $A^c \cap B^c$ nedir?

### 10.1 Birinci Çözüm: Doğrudan

1. $A^c = \{3, 4, 5, 6\}$. $\Omega$'dan $A$'nın elemanları çıkarıldı.
2. $B^c = \{1, 3, 5\}$. $B$'de 2, 4 ve 6 olduğu için kalanlar 1, 3 ve 5'tir.
3. Kesişim için iki kümede de bulunan elemanlar seçilir. 3 ikisinde de vardır, 5 de vardır. 1, 4 ve 6 yalnızca birinde bulunur.

$$A^c \cap B^c = \{3, 5\}$$

> **Ders sonrası not:** Altyazıda hoca $A^c$ için "bir, iki, üç, dört, beş, altı" diyor. Bu söyleyiş $\Omega$'nın elemanlarıdır. Doğrusu $A^c = \{3, 4, 5, 6\}$'dır. Hocanın sonraki adımda 4 ve 6'yı birinci kümeye özgü sayması da bununla uyumludur. Sonuç python ile hesaplandı.

### 10.2 İkinci Çözüm: De Morgan ile

Hoca bu tür işlemlerin birden çok yolu olduğunu, tümleyen içeren sorularda De Morgan yasasının gerekli olabileceğini söyledi. Burada önce ifadenin tamamının tümleyeni bulunur:

1. $(A^c \cap B^c)^c = A \cup B$. Tümleyenin tümleyeni kümenin kendisidir, yani $(A^c)^c = A$ ve $(B^c)^c = B$. Kesişim de birleşime dönüşür.
2. $A \cup B = \{1, 2\} \cup \{2, 4, 6\} = \{1, 2, 4, 6\}$. 2 zaten vardır, tekrar yazılmaz.
3. Aradığımız küme bunun tümleyenidir. $\Omega$'da $\{1, 2, 4, 6\}$ dışında yalnızca 3 ve 5 kalır.

$$A^c \cap B^c = (A \cup B)^c = \{3, 5\}$$

İki çözüm aynı sonucu verir. Sonuç python ile hesaplandı.

## 11. Fonksiyonlar

### 11.1 Neden Fonksiyonlar?

Hoca fonksiyonları, olasılıkta kullanacağımız rastgele değişkenlerin (random variable) birer fonksiyon olmasıyla gerekçelendirdi. Fonksiyonlar genel olarak da birçok yerde kullanılır.

> **Ek bilgi (derste anlatılmadı):** Rastgele değişkenin tanım kümesi büyük olasılıkla bu derste tanımlanan örneklem uzayı olacaktır. Bu yüzden küme ve fonksiyon tekrarı, rastgele değişkenler konusunun doğrudan hazırlığıdır.

### 11.2 Tanım Kümesi, Değer Kümesi, Görüntü Kümesi

Bir fonksiyon tanımlanırken genellikle şu gösterim kullanılır:

$$f : X \to Y$$

Bu, "$f$, $X$'ten $Y$'ye tanımlıdır" demektir. Parçaları şunlardır:

- $f$ fonksiyonun adıdır.
- $X$ tanım kümesidir (domain). Fonksiyona verebileceğimiz elemanlar bu kümeden gelir.
- $Y$ değer kümesidir (codomain).
- Görüntü kümesi (range), $f(x)$'in alabileceği bütün değerlerin kümesidir.

Görüntü kümesi her zaman değer kümesinin alt kümesidir. Hoca önce "genellikle" diye başladı, sonra "her zaman" diye düzeltti. Değer kümesi genellikle daha büyük bir kümedir. Hoca bunu bir Venn diyagramıyla çizdi: $f$, $X$ kümesindeki $x$ elemanlarını alır ve görüntü kümesindeki elemanlara götürür. Görüntü kümesi de değer kümesinin içindedir.

Büyük harfler genellikle küme adları, küçük harfler genellikle elemanlar için kullanılır. Bu nedenle $X$ bir küme, $x$ onun bir elemanıdır. Hoca el yazısında büyük ve küçük $x$'i nasıl ayırdığını da tahtada gösterdi.

**Soru:** Bu kısım bitince beş dakikalık bir Türkçe tekrar yapılabilir mi? Tanım kümesi ve değer kümesini oturtmaya çalışıyorum. **Cevap:** Hoca kısaca Türkçe özetledi. Fonksiyon bir eşlemedir (mapping). Fonksiyona verdiğiniz elemanların tanımlı olduğu bir küme vardır, bu tanım kümesidir (domain). Fonksiyon elemanı oradan alır. Değer kümesi (codomain) ile görüntü kümesi (range) birbirine benzeyen, karıştırılabilen kavramlardır. Hoca bunların bir örnekle anlaşılacağını söyledi.

> **Ders sonrası not:** Bu konuşmada altyazıda "değer kümesi, tanım kümesinden daha büyüktür" cümlesi geçiyor. Bu genel olarak doğru değildir. Hocanın anlattığı ilişki görüntü kümesi ile değer kümesi arasındadır: Görüntü kümesi değer kümesinin alt kümesidir. Tanım kümesi ile değer kümesi arasında böyle bir büyüklük ilişkisi yoktur. Aşağıdaki örnekte ikisi de $\mathbb{R}$'dir.

<!-- BELİRSİZ: 02:29:36-02:30:52 arasında Türkçe konuşmanın altyazısı bozuk. Türkçe özetin devamı ve hocanın tahtaya yazdıkları buradan okunamıyor. Hocanın büyük ve küçük x ayrımını anlattığı 02:26 civarındaki cümle de bozuk. -->

### 11.3 Örnek: $f(x) = x^2$

Hoca şu fonksiyonu ele aldı:

$$f : \mathbb{R} \to \mathbb{R}, \qquad f(x) = x^2$$

- **Tanım kümesi:** $\mathbb{R}$. Fonksiyon reel sayılardan herhangi bir değeri alabilir.
- **Değer kümesi:** $\mathbb{R}$. Değerlerin içinden geldiği büyük kümedir.
- **Görüntü kümesi:** Her sayının karesi negatif olamayacağı için değer kümesinden daha küçük bir kümedir:

$$\{y \in \mathbb{R} : y \geq 0\}$$

Yani bu fonksiyona bir değer verdiğinizde, size hem görüntü kümesinde hem de değer kümesinde bulunan başka bir değer verir.

> **Ders sonrası not:** Hoca görüntü kümesi için sözlü olarak "pozitif sayılar", gerekçe olarak da "her şeyin karesi pozitiftir" dedi. $0^2 = 0$ olduğu için doğrusu negatif olmayan sayılardır. Hocanın yazdığı $y \geq 0$ koşulu doğrudur.

<!-- BELİRSİZ: 02:33:10 civarında hocanın "come from R square" sözü altyazıda bozuk. Tahtada ne yazıldığı anlaşılmıyor. -->

## 12. Birebir (Tersinir) Fonksiyonlar

Hoca birebir (one-to-one) ya da tersinir (invertible) fonksiyonları tanımlarken, yanlış bir şey söylememek için tanımı kontrol ettiğini de belirtti. Tanım şudur: Her farklı girdi değeri, farklı bir çıktı değerine eşlenir. $f$ tersinirse $x_1, x_2$ için $f(x_1) = y_1$, $f(x_2) = y_2$ olmak üzere:

$$y_1 = y_2 \text{ ancak } x_1 = x_2 \text{ ise olur.}$$

Hoca bunu iki çizimle karşılaştırdı:

- **$f$ fonksiyonu:** $x_1$, $y_1$'e, $x_2$ de ondan farklı olan $y_2$'ye gider. $f$ tersinirdir.
- **$g$ fonksiyonu:** $x_1$ ve $x_2$'nin ikisi de aynı değere gider. Bu durumda $g$ tersinir değildir.

"Tersinir" derken kastedilen, ters eşlemenin (inverse mapping) de bir fonksiyon olabilmesidir. Ters fonksiyon $f^{-1}$ ile gösterilir. $f$ için $y_1$ ve $y_2$ farklı olduğundan $f^{-1}$ bunları sırasıyla $x_1$ ve $x_2$'ye götürebilir.

$g$ için ise $g^{-1}$ yoktur. Ortak değere $y$ dersek $g^{-1}(y)$ nedir? $x_1$ mi, $x_2$ mi? Bir fonksiyon aynı değeri iki farklı değere götüremez. Dolayısıyla $g^{-1}$ fonksiyon değildir, yani $g$ tersinir değildir.

> **Ek bilgi (derste anlatılmadı):** Birebir bir fonksiyonun tersi büyük olasılıkla değer kümesinin tamamında değil, görüntü kümesi üzerinde tanımlıdır. Bu yüzden bazı kaynaklarda "tersinir" için ek olarak görüntü kümesinin değer kümesine eşit olması istenebilir. Önceki bölümdeki $f(x) = x^2$ de $x$ ve $-x$ aynı değere gittiği için ($x \neq 0$) $g$ gibi davranır, $\mathbb{R}$ üzerinde birebir değildir.

<!-- BELİRSİZ: Hocanın f ve g için tahtaya çizdiği eşleme diyagramları altyazıda yalnız sözlü anlatılıyor. -->

## 13. Kardinalite, Sonlu ve Sonsuz Kümeler

Hoca sayılabilir (countable) ve sayılamaz (uncountable) kümeleri tanımlamak istedi. Bunun için önce kümenin kardinalitesi (cardinality) gerekir. Kardinalite, boyut ya da eleman sayısı için kullanılan süslü bir kelimedir. Bir kümenin kardinalitesi, o kümedeki eleman sayısıdır. $A$ kümesinin kardinalitesi $|A|$ ile gösterilir.

**Örnek.** $A = \{1, a, 2\}$ kümesinde üç eleman vardır, yani $|A| = 3$. Sonuç python ile hesaplandı.

Bazı kümelerde sonsuz sayıda eleman bulunur. Bu ayrım şöyle yapılır:

- **Sonlu küme** (finite set): Eleman sayısı sonsuz değildir. $A$ kümesi $|A| < \infty$ ise sonludur.
- **Sonsuz küme** (infinite set): Örneğin doğal sayılar. Eleman sayısı sonsuzdur: $|\mathbb{N}| = \infty$.

Sayılabilir ve sayılamaz kümeler sonraki derse bırakıldı.

**Soru:** Kardinalitenin Türkçesine baktım, yine "kardinalite" yazıyor. Alacağı değerlerin toplamı gibi bir şey mi, değerler sayısı mı? **Cevap:** Eleman sayısıdır, yani kümede kaç tane eleman olduğudur. Hoca bunun Türkçede de kullandığımız bir kelime olmadığını söyledi.

## Dersin Toparlaması

Bu derste olasılığın belirsizliği ölçmeye ve belirsizlik altında karar vermeye yaradığını gördük. Olasılığın iki yorumunu inceledik: Çok kez tekrarlanabilen deneylerde görülme oranına dayanan frekans yorumu ve tekrarlanamayan olaylarda inanca dayanan yorum. Olasılıklar kümeler üzerinden hesaplandığı için küme teorisini tekrar ettik: gösterimler, bilinen kümeler, alt küme ve eşitlik, örneklem uzayı ve boş küme, birleşim, kesişim, tümleyen, fark, ayrık kümeler, bölüntü, De Morgan ve dağılma yasaları. Bu sırada Baron ile Pishro-Nik'in gösterim farklarını not ettik.

Ardından fonksiyonlara geçtik, çünkü rastgele değişkenler de birer fonksiyondur. Tanım kümesi, değer kümesi ve görüntü kümesini ayırdık, birebir fonksiyonları ve ters fonksiyonu gördük, kardinalite ile sonlu ve sonsuz kümeleri tanımladık. Sonraki derste sayılabilir ve sayılamaz kümelerle devam edilecek, kümeler tamamlandıktan sonra olasılıklara geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
