# Ders 3 Genişletilmiş Notu: Birleşim Kuralı, Sürekli Uzaylar, Şartlı Olasılık, Bağımsızlık ve Toplam Olasılık Kuralı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı
- 2. Yeni Olasılık Kuralları: Birleşim ve Alt Küme
- 3. Sürekli Olasılık Uzayları
- 4. Şartlı Olasılık: Fikir ve Gösterim
- 5. Şartlı Olasılığın Formülü
- 6. Şartlı Olasılık Bir Olasılık Ölçüsüdür
- 7. Uçuş Örneği ve Problem Modelleme
- 8. Bağımsızlık
- 9. Ayrık ve Bağımsız Aynı Şey Değildir
- 10. Yağmur ve Para Örneğinde Örneklem Uzayı
- 11. Bağımsızlık Kuralları ve Üç Olayın Bağımsızlığı
- 12. Toplam Olasılık Kuralı

## 1. Önceki Dersin Tekrarı

Hoca derse Türkçe bir tekrarla başladı. Geçen hafta olasılıkların nasıl hesaplanabileceğini düşünmeye başlamıştık. Yola üç aksiyomla çıkmıştık:

- **Aksiyom 1:** Olasılıklar negatif olamaz, $P(A) \ge 0$.
- **Aksiyom 2:** Bütün örneklem uzayının olasılığı birdir, $P(\Omega) = 1$.
- **Aksiyom 3:** Kümeler kesişmiyorsa birleşimlerinin olasılığı, olasılıklarının toplamına eşittir.

> **Ders sonrası not:** Hoca tekrarda "tüm olasılıklar sıfırdan büyüktür", ayrıca "olasılıklar birden küçüktür" dedi. Doğrusu "sıfıra eşit ya da büyüktür" ve "bire eşit ya da küçüktür" olmalıdır, çünkü $P(\emptyset) = 0$ ve $P(\Omega) = 1$'dir. Hoca dersin ilerleyen kısmında Aksiyom 1'in şartlı biçimini "sıfıra eşit ya da büyüktür" diye doğru söyledi.

Bu üç aksiyomdan başka kurallar türetilmişti. Bir deneyde çıktılar eşit olasılıklıysa her bir çıktının olasılığı, 1 bölü deneydeki çıktı sayısıdır. Hocanın örneği 6 yüzlü hilesiz zardı: her sayının gelme olasılığı birbirine eşittir, dolayısıyla her biri $1/6$'dır.

<!-- BELİRSİZ: 00:08-00:11 arası altyazı çok bozuk. Eşit olasılıklı çıktılara verilen başka örnekler, tümleyen kuralının tekrarı ve boş küme kuralı burada anlatılmış görünüyor, ayrıntıları okunmuyor. -->

Tekrarda boş kümenin olasılığının $0$ olduğu ve olasılıkların birden büyük olamayacağı da anıldı. Ayrıca geçen hafta evde kendi başınıza yapmanız için bırakılan bir kural vardı: fark kuralı.

$$P(A \setminus B) = P(A) - P(A \cap B)$$

Hoca bunu Venn şemasıyla gösterdi. Örneklem uzayının içinde $A$ ve $B$ kümelerini çizelim. $A \setminus B$, $A$'nın $B$ ile kesişmeyen bölgesidir. Bu bölgenin olasılığını bulmak için $A$'nın olasılığından $A$ ile $B$'nin kesişiminin olasılığını çıkarırız. Hoca bunun 3. aksiyomdan rahatlıkla çıkarılabileceğini söyleyip devam etti.

## 2. Yeni Olasılık Kuralları: Birleşim ve Alt Küme

Bu noktadan sonra ders İngilizce devam etti.

### 2.1 Birleşim Kuralı

Hoca bunu önemli kurallardan biri olarak tanıttı. $A$ ve $B$ ayrıksa $P(A \cup B) = P(A) + P(B)$ olduğunu biliyoruz. Peki ayrık değillerse, yani bir kesişimleri varsa? O zaman kesişimi çıkarmak gerekir:

$$P(A \cup B) = P(A) + P(B) - P(A \cap B)$$

Bunun nedeni Venn şemasında kolayca görülür. $P(A)$'yı topladığımızda $A$ bölgesinin olasılığını almış oluruz. $P(B)$'yi eklediğimizde $B$ bölgesinin olasılığını da ekleriz. Kesişimdeki elemanlar bu arada iki kez eklenmiş olur. Onları bir kez saymak için kesişimi bir kez çıkarırız.

### 2.2 Alt Küme Kuralı

$A$, $B$'nin alt kümesiyse $A$'nın olasılığı $B$'ninkini geçemez:

$$A \subseteq B \Rightarrow P(A) \le P(B)$$

Bu da Venn şemasından görülür. $B$'yi çizip $A$'yı onun içine yerleştirelim. $A$'nın elemanları $B$'ninkinden azdır. En fazla $B$ ile aynı sayıda elemanı olabilir, çünkü her küme kendisinin alt kümesidir. Daha az elemanı olduğu için olasılığı da daha küçük olur.

Hoca bunu daha matematiksel biçimde de yazdı:

1. Venn şemasından $B$, $A$ ile $B \setminus A$ farkının birleşimidir. Bu iki parça ayrık olduğu için 3. aksiyomdan (ara adım eklendi) $P(B) = P(A) + P(B \setminus A)$ olur.
2. Olasılıklar negatif olamayacağı için $P(B \setminus A) \ge 0$'dır.
3. Demek ki $P(A) \le P(B)$'dir.

> **Ders sonrası not:** Hoca "olasılıklar sıfırdan büyüktür" bilgisini "sanırım Aksiyom 2" diye andı. Doğrusu **Aksiyom 1**'dir. Aksiyom 2, $P(\Omega) = 1$'dir. Hoca aksiyomları dersin ilerleyen kısmında sayarken bunu doğru sıraladı.

## 3. Sürekli Olasılık Uzayları

Şimdiye kadar genel olarak kesikli (discrete) uzayları gördük. Sürekli uzaylar (continuous spaces) dersin ilerleyen kısmında ayrıntılı işlenecek. Hoca burada onlardan kısaca söz etti.

### 3.1 Tek Noktanın Olasılığı

Deneyimiz, reel sayılarda $0$ ile $1$ arasında bir nokta seçmek olsun. Tek bir noktanın, örneğin $a$ noktasının, olasılığı sıfırdır. Bir şey seçtiğimiz için bu sezgiye aykırı görünebilir. Ama şöyle düşünelim: Herhangi iki sayı arasında sonsuz sayıda nokta vardır, $0$ ile $1$ arasında da öyle. Her noktanın seçilme olasılığının eşit olduğunu varsayarsak, az önce gördüğümüz kural bize "1 bölü kümenin eleman sayısı" der. Eleman sayısı sonsuz olduğu için bu "1 bölü sonsuz" yani sıfırdır.

> **Ders sonrası not:** Hoca "1 bölü sonsuz sıfırdır" dedi. Bu bir sezgidir, sonsuz bir sayı olmadığı için kesin bir hesap değildir. Kesin gerekçe şöyledir: Her noktanın olasılığı aynı $p$ sayısı olsun. Herhangi $n$ farklı nokta için aksiyom 3 ve alt küme kuralından $n \cdot p \le 1$ olur. Bu her $n$ için sağlanacaksa $p = 0$ olmak zorundadır.

> **Ek bilgi (derste anlatılmadı):** Sürekli uzayda olasılığı sıfır olan bir olay imkânsız demek değildir; nokta sıfır olasılığa rağmen seçilebilir. Noktaların olasılıklarını toplayıp $1$ elde edemeyiz, çünkü aksiyom 3 sayılabilir birleşimler içindir ve bir aralığın noktaları sayılamaz. Tek noktanın olasılığı sıfır olduğu için aralığın uçlarını dahil edip etmemek olasılığı değiştirmez.

### 3.2 Aralıklarla Çalışmak

Bu tür uzaylarla nasıl çalışacağız? Aralıklarla. Tek nokta yerine "seçilen $a$ noktasının $0.5$ ile $0.75$ arasında olma olasılığı nedir?" diye sorarız. Hocanın deyişiyle bu daha doğru bir sorudur. Bu aralığın olasılığından söz edebiliriz ve bu olasılık sıfır olmak zorunda değildir.

Örnek olarak $[0, 1]$ aralığı üzerinde düzgün (uniform) olasılık varsayalım. Bütün aralığın olasılığı $1$'dir. Tek boyutta olduğumuz için olasılığı uzunluktan buluruz:

- Bütün aralığın uzunluğu: $1 - 0 = 1$.
- İlgilendiğimiz aralığın uzunluğu: $0.75 - 0.5 = 0.25$.
- Olasılık: $P(0.5 \le a \le 0.75) = \dfrac{0.25}{1} = \dfrac{1}{4}$.

Yani ilgilendiğimiz parça bütün aralığın dörtte biridir.

### 3.3 Gösterim

Hoca burada biraz farklı bir gösterim kullandığını belirtti. Şimdilik eşitsizlikleri eşitlikli alıp şu ikisinin aynı anlama geldiğini yazdı:

$$P(0.5 \le a \le 0.75) = P([0.5,\ 0.75])$$

Bu gösterimlerden biri Pishro-Nik'in, öbürü daha çok Baron'un kitabında kullanılıyor.

<!-- BELİRSİZ: Hoca tahtayı göstererek "this" dediği için hangi gösterimin hangi kitaba ait olduğu altyazıdan okunmuyor. Kısa nota göre eşitsizlikli yazım Baron'un, aralıklı yazım Pishro-Nik'indir. -->

### 3.4 İki Boyutta Alan

Sürekli uzaylarda bir bakıma geometriye geçiyoruz. İki boyutlu bir uzayda uzunluk yerine alan kullanılır. Örneğin bir bölgemiz olsun ve bütün bölgenin olasılığı $1$ kabul edilsin. Bu çizim örneklem uzayına, bir Venn şemasına benzer ama hoca bunun Venn şeması olmadığını vurguladı. Burada bölge gerçekten geometrik bir alandır ve bir alt bölgenin olasılığı alanı üzerinden düşünülür.

Soru okurken ne olup bittiğini anlamak gerekir: Tek bir doğru üzerinde mi çalışıyoruz, yoksa bir alan mı söz konusu?

### 3.5 Aksiyomlar İki Tür Uzayda da Geçerlidir

Hocaya göre bu kısmın en önemli çıkarımı şudur: Olasılık aksiyomları hem kesikli hem sürekli uzaylarda geçerlidir. Sürekli olmayan uzaya kesikli uzay deriz. Üç aksiyom ikisinde de sağlandığı için onlardan elde ettiğimiz bütün kurallar da iki uzayda geçerlidir. Örneğin $P(A^c) = 1 - P(A)$ kuralı hem kesikli hem sürekli uzayda doğrudur.

## 4. Şartlı Olasılık: Fikir ve Gösterim

Hoca şimdi çok önemli bir konuya geçtiğini söyledi: şartlı olasılık (conditional probability).

Şimdiye kadar olayların olasılığını yalnızca kendi başlarına düşündük. Yağmuru ele alalım ve herhangi bir günde yağmur yağma olasılığı $0.3$ olsun. Şimdi evden çıktığımızı ya da pencereden baktığımızı ve gökte bulut gördüğümüzü varsayalım. Bulut varken yağmur olasılığı daha büyük mü, daha küçük mü olur? Daha büyük olur. Yağmurun olasılığını "bulut varken" yazabilmek isteriz ve bunun için şu gösterimi kullanırız:

$$P(\text{yağmur} \mid \text{bulut})$$

Burada bulutun var olduğunu biliyoruz: görmüş olabiliriz ya da birisi söylemiş olabilir. Bu bilgiye dayanarak yağmurla ilgili kanaatimiz, tahminimiz değişir. Artık olasılık $0.3$ değildir. Hoca örneğin $0.5$ yazdı ve Türkçe tekrarda şunu ekledi: Buraya $0.5$ yazdım ama $0.5$ olmak zorunda değil, muhtemelen $0.3$'ten büyük bir şey. Hatta daha da büyük olabilir. Önemli olan, yeni bir bilginin olasılığı değiştirmesidir.

$P(A \mid B)$ yazdığımızda $B$ şarttır (condition) ve olmuş kabul edilir. Dikey çizgi "given" (verildiğinde) diye okunur, yani $P(A \mid B)$ "$B$ verildiğinde $A$'nın olasılığı" (probability of $A$ given $B$) demektir. Türkçesi şartlı olasılıktır.

Hoca Türkçe tekrarda şartlı düşünmenin çok faydalı olduğunu, düşünürken çoğu zaman şartları da hesaba katmamız gerektiğini söyledi. Hocanın örneği: Bu dersi kitaplara çalışarak geçme olasılığınız, hiç çalışmadan geçme olasılığınız ve dersleri dinleyerek geçme olasılığınız birbirinden farklıdır.

## 5. Şartlı Olasılığın Formülü

Hoca $0.5$ sayısını öylesine yazmıştı. Peki bu olasılık gerçekte nasıl hesaplanır? Önce bir örnek üzerinde düşünelim.

### 5.1 Zar Örneği

Hilesiz bir zar atıyoruz. Sonucun $3$ veya daha küçük olduğu biliniyor. Sonucun çift olma olasılığı nedir?

<!-- BELİRSİZ: 00:55:10-00:55:34 arasında hoca Türkçe bir benzetme yapıyor; zarı bir arkadaşın görüp sonucun 3 veya küçük olduğunu söylemesi gibi görünüyor, altyazı okunmuyor. -->

Hocanın Türkçe tekrarda altını çizdiği ilk adım şudur: Olaylar kümedir, dolayısıyla çoğu zaman ilk yapmanız gereken şey olayları, yani kümelerin elemanlarını listelemektir.

- $B$ = sonucun $3$ veya daha küçük olması $= \{1, 2, 3\}$
- $A$ = sonucun çift olması $= \{2, 4, 6\}$
- $A \cap B = \{2\}$

Sonucun $B$'de olduğunu biliyoruz, yani $1$, $2$ veya $3$ gelmiştir. Bunlardan hangisi çifttir? Yalnızca $2$. Üç elemandan biri işimize yaradığı için:

$$P(A \mid B) = \frac{|A \cap B|}{|B|} = \frac{1}{3}$$

Bu mantıklıdır, çünkü adeta örneklem uzayını değiştiriyoruz. $B$'nin olduğunu biliyoruz, uzaydaki diğer şeylerle uğraşmanın anlamı yok. $B$ bir nevi yeni örneklem uzayımız olur. Bu yeni uzayda ilgilendiğimiz olay da kesişimdir.

### 5.2 Eleman Sayısından Olasılığa

Eleman sayılarıyla yazılan bu ifade iyidir ama yeterince iyi değildir, hocaya göre daha kullanışlı bir yol vardır. Eleman sayılarından olasılıklara geçmek için pay ve paydayı örneklem uzayının eleman sayısına böleriz:

$$P(A \mid B) = \frac{|A \cap B|}{|B|} = \frac{|A \cap B| \,/\, |\Omega|}{|B| \,/\, |\Omega|}$$

Pay, $A \cap B$'nin olasılığıdır. Payda, $B$'nin olasılığıdır. Böylece son formüle ulaşırız:

$$P(A \mid B) = \frac{P(A \cap B)}{P(B)}$$

Venn şemasında da aynı şey görülür. $B$'nin olduğunu biliyoruz, yani çıktı $B$ bölgesinin içindedir ve bu bölge yeni örneklem uzayımızdır. Bu bölgede $A$'nın olasılığını istiyoruz, dolayısıyla yalnızca $A$ ile de ortak olan parça, yani $A \cap B$ ilgimizi çeker.

> **Hocanın vurgusu:** Bu önemli bir kuraldır ve bilmeniz gerekir.

**Soru:** Parantez içinde $A$, düz çizgi, $B$ ne demek? $A$ ile $B$ diye iki farklı şeyin şartlı olasılığının formülü mü bu?

**Cevap:** Aynen. Bunlardan $B$ olmuştur ve bunu biliyoruz. O durumda $A$'nın olasılığını merak ediyoruz.

<!-- BELİRSİZ: 00:58-00:59 arası Türkçe tekrarda eleman sayısıyla yazılan formülün neden yetmediği anlatılıyor, altyazı okunmuyor. -->

### 5.3 Biçimsel Tanım

Aradan sonra hoca tanımı biçimsel olarak yazdı. $B$'nin olduğu bilindiğinde $A$'nın olma olasılığı, yani $A$'nın $B$ verildiğindeki şartlı olasılığı:

$$P(A \mid B) = \frac{P(A \cap B)}{P(B)}, \qquad P(B) > 0$$

Bu formülü yazabilmek için $P(B)$ sıfır olmamalıdır. Sıfırsa ifade tanımsızdır. Hoca tanımı yazarken eşit olasılıklı çıktılar şartı koymadı.

## 6. Şartlı Olasılık Bir Olasılık Ölçüsüdür

Hoca önemli bir noktaya geçti: Olasılık aksiyomları şartlı olasılık için de geçerlidir. Her olağan aksiyomun karşılığı olan bir şartlı aksiyom vardır.

### 6.1 Şartlı Aksiyomlar

Aksiyomları tek tek şartlı biçime çevirelim:

- **Şartlı Aksiyom 1:** Herhangi bir $A$ olayı için $P(A \mid B) \ge 0$.
- **Şartlı Aksiyom 2:** $P(\Omega \mid B) = 1$.
- **Şartlı Aksiyom 3:** $A_1, A_2, \dots$ ayrıksa $P(A_1 \cup A_2 \cup \dots \mid B) = P(A_1 \mid B) + P(A_2 \mid B) + \dots$

Hoca ikinci aksiyomu önce $P(B \mid B) = 1$ diye yazdı, sonra bunun yanlış olabileceğini söyleyip geri döndü. Olağan ikinci aksiyom $P(\Omega) = 1$ olduğu için şartlı karşılığı da $P(\Omega \mid B) = 1$'dir. Mantığı şöyledir: $B$'nin olduğunu biliyoruz, yani çıktı $B$'nin içindedir. $B$ zaten örneklem uzayının alt kümesi olduğu için çıktı kesinlikle örneklem uzayının da içindedir. Dolayısıyla bu olasılık $1$'dir.

Üçüncü aksiyomu hoca şöyle hatırlattı: Olaylar ayrıksa birleşimlerinin olasılığı, tek tek olasılıklarının toplamına eşittir. Şartlı biçiminde de $A_1, A_2, A_3, \dots$ kümelerinin ayrık olduğunu biliyoruz, $B$ de olmuştur. Birleşimin şartlı olasılığı, tek tek şartlı olasılıkların toplamıdır.

### 6.2 Bütün Kuralların Şartlı Biçimi Vardır

Şartlı olasılık bu aksiyomların hepsine uyduğu için bir olasılık ölçüsüdür (probability measure). Dolayısıyla şimdiye kadar gördüğümüz bütün kurallar şartlı biçime çevrilebilir. Hoca bunları tek tek yazmayacağını, ama yazılabileceğini bilmemiz gerektiğini söyledi. Örnek olarak en basit kurallardan birini aldı:

$$P(A^c) = 1 - P(A) \quad \Longrightarrow \quad P(A^c \mid B) = 1 - P(A \mid B)$$

Türkçe tekrarda hoca bu kuralı sayılarla da söyledi: $A$'nın olasılığı $0.9$ ise tümleyeninin olasılığı $0.1$'dir, çünkü toplamları $1$ olmalıdır. Aynı ilişki $B$ şartı altında da geçerlidir.

<!-- BELİRSİZ: 01:29-01:31 arası Türkçe tekrar büyük ölçüde okunmuyor. 0.9 ve 0.1 sayıları anlaşılıyor; altyazıdaki "total is 1.1" ifadesi bozuk, "toplam 1" diye yorumlandı. -->

> **Hocanın vurgusu:** Dikkat edin, şu eşitlik **yanlıştır**:
> $$P(A \mid B^c) = 1 - P(A \mid B)$$
> Tümleyen kuralını yazabilmek için şartların aynı olması gerekir. Burada bir tarafta şart $B$, öbür tarafta $B^c$'dir. Kuralların hepsini yazabilirsiniz, ama aynı şart altında.

## 7. Uçuş Örneği ve Problem Modelleme

### 7.1 Problem

İstanbul'dasınız ve Adana'dan uçakla gelecek bir arkadaşınızı bekliyorsunuz. Uçak Adana'dan kalkıp İstanbul'a inecek. Şunları biliyoruz:

- Uçuşların %90'ı zamanında kalkıyor.
- Uçuşların %80'i zamanında iniyor.
- Uçuşların %75'i hem zamanında kalkıyor hem zamanında iniyor.

İki soru var:

- **(a)** Uçağın zamanında kalktığını biliyorsunuz (bu bilgiyi gösteren web siteleri var). Zamanında inme olasılığı nedir?
- **(b)** Zamanında kalkıp kalkmadığını bilmiyorsunuz, ama arkadaşınızın zamanında indiğini biliyorsunuz. Uçağın zamanında kalkmış olma olasılığı nedir?

### 7.2 Problemi Modellemek

Hoca bu tür soruların nasıl çözüleceğini adım adım gösterdi. Önce modellenir:

1. Olaylara büyük harfle ad verilir. $D$ = zamanında kalkış (departs on time), $A$ = zamanında varış (arrives on time). Ad verince denklemleri yazmak kolaylaşır.
2. Verilenler bu harflerle yazılır: $P(D) = 0.90$, $P(A) = 0.80$. Üçüncü bilgideki "ve" (and) kelimesi genellikle kesişim demektir, yani iki olayın birlikte olması: $P(A \cap D) = 0.75$.
3. Sorulan şey bu harflerle yazılır: (a) şıkkında $P(A \mid D)$, (b) şıkkında tersi olan $P(D \mid A)$.
4. Modelleme bittikten sonra geriye olasılık kurallarını uygulamak kalır. Soru şartlı olasılıkla ilgili olduğu için şartlı olasılık kuralı kullanılır.

### 7.3 Çözüm

**(a) şıkkı.**

$$P(A \mid D) = \frac{P(A \cap D)}{P(D)} = \frac{0.75}{0.90} \approx 0.833$$

Hoca hesabı dersin bir sonraki kısmında makineyle yapıp $0.8333\ldots$ buldu. Sonucun beklenen bir sonuç olduğunu şöyle açıkladı: Birden küçük bir sayıya böldüğümüz için sonuç $0.75$'ten büyük olur. Üstelik mantıklıdır: Uçağın zamanında kalktığını biliyorsak zamanında inme olasılığı artar, $0.80$'den $0.833$'e çıkar.

**(b) şıkkı.** Hoca bunu aynı kuralla evde yapmamızı istedi.

> **Ders sonrası not:** (b) şıkkının sonucu derste hesaplanmadı. Aynı kuralla $P(D \mid A) = \dfrac{P(A \cap D)}{P(A)} = \dfrac{0.75}{0.80} = 0.9375$ bulunur. Python ile hesaplandı.

## 8. Bağımsızlık

### 8.1 Tanım

Hoca önce tanımı verdi. $A$ ve $B$ olayları ancak ve ancak (if and only if) şu durumda bağımsızdır (independent):

$$P(A \mid B) = P(A)$$

Eşdeğer olarak:

$$P(A \cap B) = P(A)\,P(B)$$

> **Ders sonrası not:** Hoca iki yazımı koşulsuz olarak eşdeğer verdi. Doğrusu, $P(A \mid B)$ yalnız $P(B) > 0$ iken tanımlı olduğu için ilk yazım bu şartı ister. Çarpım yazımı $P(B) = 0$ iken de yazılabilir.

### 8.2 Sezgi: Bağımlı Olaylar

Önceki uçuş örneğine dönelim. Zamanında varış olasılığı başlangıçta $0.80$'di. Uçağın zamanında kalktığını öğrenince $0.75 / 0.90 = 0.8333\ldots$ oldu. Olasılık değişti, yani zamanında kalkış ve zamanında varış **bağımlı** (dependent) olaylardır: Biri olunca öbürünün olasılığı değişir. Bağımsız olaylarda ise birinin olması bize öbürü hakkında hiçbir bilgi vermez.

### 8.3 Sezgi: Yağmur ve Para

Bu nasıl olabilir? Hocanın örneği şudur: $A$ yağmur yağması, $B$ de bir para attığımızda yazı (tails) gelmesi olsun. İstediğiniz kadar para atabilirsiniz, bu yağmur ihtimalini etkilemez. Dolayısıyla

$$P(\text{yağmur} \mid \text{yazı}) = P(\text{yağmur})$$

olur. Para atmak bize hava hakkında hiçbir şey söylemez. Bu yüzden yağmur ve yazı olayları bağımsızdır.

### 8.4 Çarpım Kuralının Türetilmesi

İlk yazım mantıktan geliyor: Birbirine bağlı değillerse $B$'nin olup olmaması bize bir şey söylemez. İkinci yazıma ise şartlı olasılığın tanımından ulaşılır. Hoca bunu derste deneyerek gösterdi:

1. Tanımdan başlanır: $P(A \mid B) = \dfrac{P(A \cap B)}{P(B)}$.
2. $P(B)$ öbür tarafa geçirilir: $P(A \cap B) = P(A \mid B)\,P(B)$.
3. Olaylar bağımsız olduğu için $P(A \mid B)$ yerine $P(A)$ yazılır: $P(A \cap B) = P(A)\,P(B)$.

### 8.5 Uçuş Örneğinde Bağımsızlık Testi

Soru: Zamanında varış ve zamanında kalkış bağımsız mıdır? Verilenler $P(A) = 0.80$, $P(D) = 0.90$, $P(A \cap D) = 0.75$.

Test için elimizde iki kural var: $P(A \mid D) = P(A)$ ve $P(A \cap D) = P(A)\,P(D)$. Bütün değerler elimizde hazır olduğu için ikincisi daha kolaydır:

$$0.80 \times 0.90 = 0.72 \neq 0.75 = P(A \cap D)$$

Eşitlik sağlanmıyor, yani $A$ ve $D$ bağımsız değildir, bağımlıdır.

> **Hocanın vurgusu:** Bağımsızlığı test ederken çoğu zaman çarpım kuralını kullanmak daha kolaydır.

## 9. Ayrık ve Bağımsız Aynı Şey Değildir

**Soru:** Bağımsız (independent), karşılıklı dışlayan (mutually exclusive) ve ayrık (disjoint) aynı anlama mı geliyor?

**Cevap:** Hayır. Ayrık ile karşılıklı dışlayan aynı şeydir, bağımsız ise başka bir şeydir.

Karşılaştıralım:

- **Ayrık:** $A \cap B = \emptyset$. Kümelerle ilgili bir özelliktir, çünkü olaylar kümedir. Boş kesişim aranır.
- **Bağımsız:** $P(A \cap B) = P(A)\,P(B)$. Olasılıklarla ilgili bir özelliktir. Çarpımların eşitliği aranır.

Hoca önce "biri küme, öbürü olasılıkla ilgili" diye ayırdı, sonra her ikisinde de sonuçta olaylardan söz ettiğimizi ekledi. Asıl fark, yapılan testin farklı olmasıdır.

İkinci önemli nokta şudur: $A$ ve $B$ ayrıksa bağımsız değildirler. Düşünelim: Kesişimleri yok. $B$ oldu dediğimizde çıktı $B$'nin içindedir. Demek ki çıktı $A$'nın içinde olamaz. Yani birinin olması bize öbürü hakkında bilgi verir: Biri olursa öbürü olmaz. Bağımsızlıkta ise böyle bir bilgi söz konusu değildir.

> **Ders sonrası not:** Hoca "ayrık olaylar bağımsız değildir" dedi. Bu, yalnız $P(A) > 0$ ve $P(B) > 0$ iken doğrudur. Olaylardan birinin olasılığı $0$ ise $P(A \cap B) = 0 = P(A)\,P(B)$ olur ve olaylar hem ayrık hem bağımsızdır.

## 10. Yağmur ve Para Örneğinde Örneklem Uzayı

**Soru:** Bağımsızlıkta $A$ kesişim $B$ yazıyoruz. Yazı tura ve yağmur yağması örneğinde $A$ ve $B$ olayları farklı örneklem uzaylarında diyebilir miyiz? Venn şemasında gösterirken kafam karıştı.

**Cevap:** Hayır, ikisi de aynı örneklem uzayındadır. Örneklem uzayı ikisini birlikte içerecek şekilde tanımlanır.

Hoca bunu somutlaştırdı. Durumu basite indirgemek için ya yağmur (R) ya güneş (S) olduğunu, para için de yazı (T) ya da tura (H) geldiğini varsayalım. Örneklem uzayı ikililerden oluşur:

$$\Omega = \{(R,T),\ (S,T),\ (R,H),\ (S,H)\}$$

Olaylar da bu ikililerin kümeleridir:

- $A$ = yağmur yağması $= \{(R,T),\ (R,H)\}$
- $B$ = yazı gelmesi $= \{(R,T),\ (S,T)\}$
- $A \cap B = \{(R,T)\}$

Yağmurun ve güneşin eşit olasılıklı, yazının ve turanın da eşit olasılıklı olduğunu varsayalım. Bağımsızlık testi:

- $P(A) = 2/4 = 1/2$
- $P(B) = 2/4 = 1/2$
- $P(A)\,P(B) = 1/4$
- $P(A \cap B) = P(\{(R,T)\}) = 1/4$

Eşitlik sağlanıyor, yani olaylar bağımsız çıkıyor. Hesap python ile de doğrulandı.

> **Ders sonrası not:** Hoca soruyu cevaplarken bir an "örneklem uzayı ikililerden oluşmayacak galiba, Rain, Sun, Tails gibi elemanları olacak" dedi, sonra yeniden düşünüp ikililerle hesapladı. Doğrusu, ikililerden oluşan uzaydır. Az önceki hesap da bu uzayda bağımsızlığı doğruluyor.

<!-- BELİRSİZ: 02:24:38-02:25:49 arasında hocanın bu örnek için son yorumu okunmuyor. -->

## 11. Bağımsızlık Kuralları ve Üç Olayın Bağımsızlığı

### 11.1 Bağımsızlık Kuralları

$A$ ve $B$ bağımsızsa $P(A \mid B) = P(A)$ olduğunu biliyoruz. Bunun tersi de doğrudur:

$$P(B \mid A) = P(B)$$

Yağmur yağması, para attığımızda yazı mı tura mı geleceği konusunda bilgi vermez. Yağmur yağıyor olabilir, ama bu paranın sonucunu etkilemez.

Ayrıca bağımsız iki olayın tümleyenleri de bağımsızdır:

- $A^c$ ile $B$ bağımsızdır.
- $A$ ile $B^c$ bağımsızdır.
- $A^c$ ile $B^c$ bağımsızdır.

Bu da mantıklıdır. Örneğin yağmur yağmaması ile yazı gelmesi için $P(\text{yağmur yok} \mid \text{yazı}) = P(\text{yağmur yok})$ yazılır.

> **Ek bilgi (derste anlatılmadı):** Hoca tümleyenlerin bağımsızlığını ispatsız söyledi. Fark kuralıyla kısa bir ispatı vardır: $P(A^c \cap B) = P(B) - P(A \cap B) = P(B) - P(A)P(B) = P(A^c)\,P(B)$. Öbür iki durum da aynı adımlarla çıkar.

### 11.2 Üç Olayın Bağımsızlığı

$A$, $B$, $C$ olayları ancak ve ancak şu dört eşitliğin hepsi sağlanıyorsa bağımsızdır. İkili kesişimlerin hepsi ve üçlü kesişim düşünülmelidir:

- $P(A \cap B) = P(A)\,P(B)$
- $P(A \cap C) = P(A)\,P(C)$
- $P(B \cap C) = P(B)\,P(C)$
- $P(A \cap B \cap C) = P(A)\,P(B)\,P(C)$

> **Ek bilgi (derste anlatılmadı):** Tanımda dördüncü eşitliğin ayrıca istenmesinin nedeni, ikili eşitliklerin üçlü eşitliği garanti etmemesidir. Üç ikili eşitliğin sağlanıp üçlü eşitliğin sağlanmadığı olay üçlüleri vardır. Bu durum iki para atışı modelinde sayılarak python ile denetlendi.

$n$ olayın bağımsızlığı da benzer şekilde düşünülür. İkililer, üçlüler, dörtlüler, beşliler, altılılar diye gider. $n$ arttıkça bütün kesişimlerin tek tek olasılıkların çarpımına eşit olması gerekir, hepsi bu kurala uymalıdır.

## 12. Toplam Olasılık Kuralı

Hoca son olarak yine çok önemli bir konuya geçti: toplam olasılık kuralı (law of total probability).

### 12.1 Kural

$B_1, B_2, B_3, \dots$ örneklem uzayının bir bölüntüsü (partition) olsun ve her $i$ için $P(B_i) > 0$ olsun. Bu durumda herhangi bir $A$ olayı için:

$$P(A) = \sum_i P(A \cap B_i) = \sum_i P(A \mid B_i)\,P(B_i)$$

> **Ek bilgi (derste anlatılmadı):** Hoca bölüntüyü tanımlamadı, Venn şeması üzerinde gösterdi. Bölüntü, örneklem uzayını kesişmeyen parçalara ayıran kümeler topluluğudur: Parçaların ikişerli kesişimleri boştur, birleşimleri de bütün örneklem uzayıdır. Bu yüzden her çıktı tam olarak bir parçaya düşer.

### 12.2 Mantığı

Karmaşık görünse de kural aslında çok basittir. Venn şeması üzerinde düşünelim. Örneklem uzayı $B_1, B_2, B_3, B_4$ parçalarına bölünmüş olsun. $A$ da aynı uzaydadır ve bu parçaları keser. $A$'nın olasılığını arıyoruz, bilmiyoruz. Ama bu kuralla çözülebilen problemlerin yapısı şudur: Kesişimleri bir şekilde biliyoruz. Bütün kesişimlerin olasılıklarını toplarsak $P(A)$'yı elde ederiz:

$$P(A) = P(A \cap B_1) + P(A \cap B_2) + P(A \cap B_3) + P(A \cap B_4) = \sum_{i=1}^{4} P(A \cap B_i)$$

Kuralın ilk kısmı yalnız bunu söyler. Toplam işaretiyle yazılınca kafa karıştırıcı görünür, ama uzun toplamın kısa yazılışından ibarettir.

İkinci kısım ayrı bir kural değildir, kesişimleri çarpım olarak yazmaktan ibarettir. Şartlı olasılık tanımından başlarız:

$$P(A \mid B_i) = \frac{P(A \cap B_i)}{P(B_i)}$$

$P(B_i)$'yi öbür tarafa geçirince $P(A \cap B_i) = P(A \mid B_i)\,P(B_i)$ olur. Bunu toplamda yerine yazarsak:

$$P(A) = \sum_{i=1}^{4} P(A \mid B_i)\,P(B_i)$$

### 12.3 Örnek: Hileli Paralar

Hoca süre az kaldığı için bu örneği evde yapılmak üzere bıraktı. Torbada 3 hileli para var. "Hileli" için derste "unfair" ve "tricky" kullanıldı, öneri olarak "loaded" ve "fixed" da geçti. Tura (heads) gelme olasılıkları:

- 1. para: $0.9$
- 2. para: $0.6$
- 3. para: $0.3$

Torbadan rastgele bir para çekip atıyoruz. Tura gelme olasılığı nedir? Hoca soruyu Türkçe de açıkladı: Paraların her birinin seçilme olasılığı birbirine eşittir. Ama her biriyle farklı şekilde oynanmıştır, dolayısıyla tura gelme olasılıkları farklıdır. Bu işlemin sonucunda toplamda tura gelme olasılığı sorulmaktadır.

> **Ders sonrası not:** Örneğin çözümü derste yapılmadı. $B_i$ = "$i$. para çekildi" ve $T$ = "tura geldi" olsun. $P(B_i) = 1/3$ ve toplam olasılık kuralıyla $P(T) = \frac{1}{3}(0.9) + \frac{1}{3}(0.6) + \frac{1}{3}(0.3) = 0.3 + 0.2 + 0.1 = 0.6$ bulunur. Python ile hesaplandı.

## Dersin Toparlaması

Ders, kesişen olaylar için birleşim kuralı ve alt küme kuralıyla başladı. Sürekli uzaylara kısa bir giriş yapıldı: Tek noktanın olasılığı sıfırdır, bu yüzden aralıklar ve alanlarla çalışılır. Aksiyomlar ve onlardan türetilen kurallar iki tür uzayda da geçerlidir. Sürekli uzaylar dersin ilerleyen kısmında ayrıntılı işlenecektir.

Dersin ağırlığı şartlı olasılıktaydı. $P(A \mid B) = P(A \cap B) / P(B)$ formülü, yeni bir bilginin olasılığı nasıl değiştirdiğini ifade eder ve şartlı olasılık da bir olasılık ölçüsüdür. Bağımsızlık, bu yeni bilginin hiçbir şeyi değiştirmemesi demektir ve çoğu zaman çarpım kuralıyla test edilir; ayrık olmakla karıştırılmamalıdır. Toplam olasılık kuralı da şartlı olasılık tanımını kullanarak bir olayın olasılığını örneklem uzayının parçaları üzerinden hesaplar. Problem çözerken önce modellemek, sonra kuralları uygulamak hocanın bütün örneklerde izlediği yoldur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
