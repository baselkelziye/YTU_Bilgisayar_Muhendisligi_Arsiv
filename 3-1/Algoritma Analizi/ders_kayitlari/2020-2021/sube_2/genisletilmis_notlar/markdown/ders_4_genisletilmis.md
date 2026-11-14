# Ders 4 Genişletilmiş Notu: Uygulama: Insertion Sort Ortalama Durum Analizi ve Limitle Büyüme Derecesi Karşılaştırma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Asimptotik Gösterimde Sadeleştirme Hatırlatması
- 2. Insertion Sort'un Ortalama Durum Analizi
- 3. Doğru-Yanlış Soruları: Bir Fonksiyon $O(n^2)$'nin Elemanı mı?
- 4. Büyüme Derecelerini Limitle Karşılaştırma
- 5. Zaman Karmaşıklığı mı, Bellek Karmaşıklığı mı?
- Örnek Sorular
- Dersin Toparlaması

## 1. Asimptotik Gösterimde Sadeleştirme Hatırlatması

Bu kayıt, aynı haftanın teori dersinin ardından yapılan uygulama (laboratuvar) oturumudur. Oturumun amacı, teoride görülen konular üzerinde küçük analizler ve örnekler yapmaktır.

Oturum, asimptotik gösterim (asymptotic notation) ile ilgili bir hatırlatmayla başladı. Hoca tahtaya karesel bir ifade yazdı ve bunun büyüme derecesinin nasıl bulunacağını adım adım gösterdi. İfadedeki sabitler olarak $\frac{2}{4}$, $\frac{3}{4}$ ve $\frac{1}{4}$ sayıldı. Bu, ilerleyen bölümde insertion sort için bulunacak $\frac{1}{4}n^2+\frac{3}{4}n+\frac{2}{4}$ ifadesiyle aynı yapıdadır.

<!-- BELİRSİZ: Tahtadaki ifadenin tamamı altyazıda okunmuyor; yalnız "n kare bölü 4 artı ..." ve 2/4, 3/4, 1/4 sabitleri geçiyor. Ekran paylaşımı da bu sırada başlatıldı. -->

Sadeleştirme şu adımlarla yapılır:

- **Sabitler elenir:** Tek başına duran sabit terim ($\frac{2}{4}$ gibi) atılır.
- **Katsayılar elenir:** Terimlerin önündeki çarpanlar ($\frac{1}{4}$, $\frac{3}{4}$) atılır.
- **Düşük dereceli terimler (lower-order terms) elenir:** $n$ gibi daha yavaş büyüyen terimler atılır.

Bu işlemlerden sonra elde yalnız en yüksek dereceli terim kalır. Girdi boyutu $n$ olduğundan sonuç $n^2$ cinsinden yazılır ve ifade $O(n^2)$ olur.

## 2. Insertion Sort'un Ortalama Durum Analizi

Şimdiye kadar derslerde en kötü durum (worst case) ve en iyi durum (best case) konuşulmuş, asimptotik gösterimin bütün notasyonları görülmüştü. Ama ortalama durum (average case) için bir örnek yapılmamıştı. Hoca bunun için insertion sort'u güzel bir örnek olarak seçti.

### 2.1 Algoritmanın Döngü Yapısı

Hoca önce sınıfa insertion sort'ta kaç döngü olduğunu sordu.

**Soru:** Insertion sort'ta kaç döngü var? Bu döngüler için `for` mu `while` mı kullanılır? **Cevap:** İki döngü vardır. Dış döngü için `for` kullanılır, çünkü bütün elemanların gezilmesi gerekir. İç döngü için `while` kullanılır, çünkü iç döngü tek bir karşılaştırmada da sonlanabilir.

Hoca bu açıklamayı doğru buldu. İç döngünün kaç adım süreceği önceden belli olmadığı için ortalama durum analizi tam olarak bu iç döngünün beklenen adım sayısını bulmaya dayanır.

### 2.2 Model: $k$. Elemanın $j$. Konuma Yerleşmesi

Birinci elemandan $n$. elemana kadar giden bir sayı dizisi düşünelim. Dış döngü bir noktada $k$. elemana gelmiş olsun. Bu noktada önceki $k-1$ eleman zaten sıralanmıştır. Yapılması gereken, $k$. elemanı sıralı kısımda olması gereken konuma getirmektir.

Bu konumun neresi olacağını bilmiyoruz. Bu yüzden ona parametre olarak $j$ diyoruz ($1 \le j \le k$). $k$. eleman $j$. konuma yerleşecekse $k$'dan $j$'ye kadar geri gidilir. Bu da $k-j+1$ adım demektir. Yani $k-j+1$ kadar kontrol yapılır ve o kontrolün sonucunda durulur. Bu ifade iç döngü için geçerlidir.

Her konum eşit olasılıklı kabul edilir. $k$ tane olası konum olduğundan her birinin etkisi $\frac{1}{k}$ kadardır. Hoca bunu "her bir elemanın ne kadar kayma ihtimali olduğunu değerlendirdik" diye özetledi.

### 2.3 İç Döngünün Ortalama Adım Sayısı

İç döngünün ortalama karşılaştırma sayısı:

$$\frac{1}{k}\sum_{j=1}^{k}(k-j+1)$$

Hoca toplamı şöyle açtı. $\sum_{j=1}^{k} k = k^2$, $\sum_{j=1}^{k} j = \frac{k(k+1)}{2}$ ve $\sum_{j=1}^{k} 1 = k$ olduğundan:

$$\frac{1}{k}\left(k^2 - \frac{k(k+1)}{2} + k\right) = \frac{2k^2 - k^2 - k + 2k}{2k} = \frac{k^2 + k}{2k} = \frac{k+1}{2}$$

Son eşitlikteki $\frac{k^2+k}{2k}$ sadeleştirmesi ara adım olarak eklendi. Sonuç olarak iç döngüde ortalama $\frac{k+1}{2}$ karşılaştırma (işlem) yapılır.

### 2.4 Dış Döngü ve Toplam Ortalama

Hoca sınıfa dış döngünün nereden nereye gittiğini sordu.

**Soru:** $k$ kaçtan başlayıp kaça kadar gider? **Cevap:** $2$'den $n$'ye kadar.

Dış döngünün toplam işaretinin içine iç döngüden gelen sonuç yazılır:

$$A(n) = \sum_{k=2}^{n}\frac{k+1}{2}$$

Hoca bu toplamı açarak

$$A(n) = \frac{1}{2}\cdot\frac{(n+1)(n+2)}{2} = \frac{1}{4}\left(n^2 + 3n + 2\right)$$

sonucunu yazdı.

> **Ders sonrası not:** Hoca toplamı $\frac{(n+1)(n+2)}{4}$ olarak yazdı; bu, toplamı $k=0$'dan başlatmaya karşılık gelir. $k=2$'den başlayan toplamın tam değeri $A(n)=\frac{n^2+3n-4}{4}=\frac{(n+4)(n-1)}{4}$'tür, yani hocanın ifadesinden $\frac{6}{4}$ küçüktür. Örneğin $n=4$ için $\frac{3}{2}+2+\frac{5}{2}=6$ çıkar; hocanın formülü $\frac{15}{2}$ verir. Asimptotik sonuç değişmez. Python ile $n=2,3,4,5,10,100$ için kontrol edildi.

Insertion sort'ta en kötü durumun $n^2$ olduğunu biliyoruz. Ortalama durum da $n^2$'ye gelir: $A(n)\approx\frac{n^2}{4}$. Bu nedenle ortalama durum $O(n^2)$ ile ifade edilir. Hoca, alt sınırı da düşünülürse bunun Theta cinsinden de ifade edilebileceğini söyledi: $A(n)\in\Theta(n^2)$.

> **Ders sonrası not:** Modeldeki $k-j+1$ sayımı, eleman en başa ($j=1$) yerleştiğinde de $k$ karşılaştırma sayar. Gerçek insertion sort'ta bu durumda dizinin başına gelinince döngü karşılaştırma yapmadan biter, yani $k-1$ karşılaştırma yapılır. Bütün permütasyonlar üzerinden kesin ortalama $\frac{n^2+3n}{4}-H_n$'dir ($H_n=1+\frac{1}{2}+\dots+\frac{1}{n}$). Örneğin $n=4$ için $\frac{59}{12}\approx 4.92$ çıkar. Bu da $\Theta(n^2)$'dir. Python ile $n=2,\dots,7$ için bütün permütasyonlar sayılarak doğrulandı.

> **Hocanın vurgusu:** Her algoritma için ortalama durumu bu kadar rahat hesaplayamayabilirsiniz. Insertion sort bunun için güzel bir örnek olduğu için incelendi.

### 2.5 Soru-Cevap: Sıralı Kısmın Dışındaki Elemanlar

**Soru:** $1$'den $k$'ya kadar sıralı dedik. Peki $k$'dan $n$'ye kadar olan sayıları da dizmemiz gerekmiyor mu? İç döngüdeki toplam bunları da hesaba katmalı değil mi?

**Cevap:** Hoca işlemin aslında ilk elemandan başladığını hatırlattı. İkinci eleman alınır ve ilk elemanla karşılaştırılır. Yani seçilebilecek ilk $k$ ikinci elemandır. Bu elemanın gelebileceği tek alternatif konum birinci elemandır, bu da $j=1$'dir. Bu ilk senaryoda $k=2$, $j=1$ olduğundan $k-j+1$ ifadesi bize kontrol sayısını verir.

Her adımda $k$ artırılır, ama elemanın hangi konuma ($j$) geleceği bilinmez. Örneğin ikinci elemandan üçüncü elemana geçildiğinde $k=3$ olur. Bu eleman ikinci elemanın yerine de, birinci elemanın yerine de gelebilir. Bu olasılıklar hesaplanarak dizinin başından sonuna, yani $n$'ye kadar gidilir. Her adımda $k$, karşılaştırmanın yapıldığı sıralı kısmın sınırıdır. Örneğin $k=10$ ise 10. eleman yoluna başlar. Yerinin 3. konum olduğu ortaya çıkınca ($j=3$) oraya yerleşir. Hesap buna göre yapılır.

Kısacası $k$ zaten $2$'den $n$'ye kadar bütün değerleri alır. Sıralı kısmın sağındaki elemanlar, dış döngü onlara geldiğinde ayrı ayrı yerleştirilir. Bu yüzden iç döngü hesabına girmezler.

## 3. Doğru-Yanlış Soruları: Bir Fonksiyon $O(n^2)$'nin Elemanı mı?

Hoca önceki dersle ilgili birkaç örnek soru çözmek istedi ve tahtaya şu ifadeleri yazdı:

- $n \in O(n^2)$
- $100n + 5 \in O(n^2)$
- $\frac{1}{2}n(n-1) \in O(n^2)$

Sorulan şey, her ifadenin doğru mu yanlış mı olduğuydu. Sınıftan uzun süre cevap gelmeyince hoca öğrencilere tek tek sordu.

> **Hocanın vurgusu:** Bu sorular çok basit görünüyor ve "zaten belli" denebilir. Ama önceki yıllarda böyle düşünüp bu soruları doğru yapamayan çok öğrenci oldu. Hoca bu yüzden bu konunun üzerinde özellikle durduğunu söyledi.

### 3.1 $n \in O(n^2)$

Cevap doğru. Gerekçe: $O(n^2)$ bir üst sınırdır (upper bound) ve $n$, $n^2$'den daha hızlı büyümez.

### 3.2 $100n + 5 \in O(n^2)$

Cevap doğru. Katsayı $100$ ve sabit $5$ atıldığında geriye $n$ kalır. Bu da $n^2$ ile üstten sınırlıdır.

### 3.3 $\frac{1}{2}n(n-1) \in O(n^2)$

Cevap doğru. Bir öğrenci önce "doğru gibi geldi" dedi. Hoca bunun nedenini sordu ve şu adımları birlikte kurdular. İfade açılınca $\frac{1}{2}n^2 - \frac{1}{2}n$ olur. Büyüme derecesine karar verirken düşük dereceli terim ($-\frac{1}{2}n$) elenir, sabit katsayı ($\frac{1}{2}$) elenir. Geriye $n^2$ kalır. Bu da ifadenin doğru olduğunu gösterir.

### 3.4 $n^3 \in O(n^2)$

Hoca bir sonraki örnek olarak $n^3 \in O(n^2)$ ifadesini sordu. Cevap yanlış. $O$ bir üst sınıra baktığı için $n^3$, $O(n^2)$'nin elemanı değildir. $n^3$ en az $n^2$ kadar büyür.

**Soru:** Bu ifadeyi doğru hale getirmek için $O$ yerine ne koymalıyız? **Cevap:** Omega. $n^3 \in \Omega(n^2)$ ifadesi doğrudur.

Hoca ardından aynı ifade için başka bir yol sordu: Notasyonu değiştirmeden, tek bir hareketle ifadeyi doğru yapmak için ne değiştirilebilir? Bir öğrenci önce Theta dedi. Sonra başka bir öğrenci doğru cevabı verdi: "elemanıdır" işaretini "elemanı değildir" yapmak.

$$n^3 \notin O(n^2)$$

Bu ifade doğrudur. Hoca bunun biraz bulmaca gibi olduğunu kabul etti. Ama bu ifadelerin yalnız "elemanıdır" ($\in$) olarak değil, "elemanı değildir" ($\notin$) olarak da yazılabileceğine ve böylece doğru hale geleceğine dikkat etmek gerektiğini söyledi.

### 3.5 $0.0001n^3$ ve $O(n^2)$

Son olarak hoca $0.0001n^3$ ile $O(n^2)$ arasına hangi işaretin gelmesi gerektiğini sordu. Cevap "elemanı değildir" oldu:

$$0.0001n^3 \notin O(n^2)$$

Katsayı ne kadar küçük olursa olsun, büyüme derecesine karar verirken katsayı elenir ve geriye $n^3$ kalır.

> **Ek bilgi (derste anlatılmadı):** Küçük katsayı yalnızca kesişme noktasını geciktirir. $0.0001n^3 > n^2$ eşitsizliği $n > 10000$ için sağlanır. Bu noktadan sonra $0.0001n^3$, $n^2$'nin hiçbir sabit katıyla üstten sınırlanamaz.

## 4. Büyüme Derecelerini Limitle Karşılaştırma

Hoca, büyüme derecelerine karar verirken şimdiye kadar katsayılardan, sabitlerden ve düşük dereceli terimlerden kurtulduğumuzu hatırlattı. İki fonksiyonun büyüme dereceleri arasında ilişki kurmak, birbirlerine göre büyük ya da küçük olduklarını göstermek için bir yöntem daha vardır: limit almak.

### 4.1 Limit Kuralı

İki fonksiyon $t(n)$ ve $g(n)$ şöyle karşılaştırılır ($t(n)$ yerine $f(n)$ de yazılabilir):

$$\lim_{n\to\infty}\frac{t(n)}{g(n)}$$

Bu limitin üç sonucu olabilir: $0$, bir sabit $c$ ya da $\infty$.

- **Limit $0$ ise:** $t(n)$, $g(n)$'den daha düşük büyüme derecesine sahiptir ($t(n)$ has a smaller order of growth than $g(n)$).
- **Limit sabit $c$ ise:** $t(n)$ ile $g(n)$ aynı büyüme derecesine sahiptir ($t(n)$ has the same order of growth as $g(n)$). Hoca bu satır için "ne yazarsınız?" diye sorduğunda sınıftan "eşit" cevabı geldi.
- **Limit $\infty$ ise:** $t(n)$, $g(n)$'den daha yüksek büyüme derecesine sahiptir ($t(n)$ has a larger order of growth than $g(n)$).

> **Ek bilgi (derste anlatılmadı):** Bu üç durum notasyonlarla şöyle eşleşir. Limit $0$ ise $t\in O(g)$ olur, ama $t\notin\Theta(g)$. Limit $c>0$ ise $t\in\Theta(g)$ olur, bu da hem $O(g)$ hem $\Omega(g)$ demektir. Limit $\infty$ ise $t\in\Omega(g)$ olur, ama $t\notin\Theta(g)$. Bu kural yalnız limit var olduğunda kullanılabilir.

### 4.2 Örnek: $\frac{1}{2}n(n-1)$ ile $n^2$

Verilen: $t(n) = \frac{1}{2}n(n-1)$ ve $g(n) = n^2$.

İşlem: Limit alınır, $\frac{1}{2}$ sabit olarak dışarı çıkar:

$$\lim_{n\to\infty}\frac{\frac{1}{2}n(n-1)}{n^2} = \frac{1}{2}\lim_{n\to\infty}\frac{n^2-n}{n^2}$$

Ara sonuç: Pay ve payda $n^2$'ye bölünür:

$$\frac{1}{2}\lim_{n\to\infty}\left(1-\frac{1}{n}\right)$$

$n$ sonsuza gittiğinde $\frac{1}{n}$ sıfıra gider, parantez içinden $1$ gelir. $1 \cdot \frac{1}{2}$'den de $\frac{1}{2}$ gelir.

Sonuç: Limit bir sabittir ($\frac{1}{2}$). Sabit gelmesi, iki fonksiyonun aynı büyüme derecesine sahip olduğunu gösterir: $\frac{1}{2}n(n-1)\in\Theta(n^2)$. Bu, Bölüm 3.3'teki sonucun limit yoluyla gösterilmesidir.

### 4.3 Soru-Cevap: Sonuçtaki $\frac{1}{2}$ Ne Anlama Geliyor?

Ekranın alt kısmı görünmediği için bir öğrenci tahtanın aşağı alınmasını istedi. Ardından başka bir öğrenci sondaki $\frac{1}{2}$'nin ne anlama geldiğini sordu.

**Soru:** Son kısımdaki $\frac{1}{2}$ ne anlama geliyor?

**Cevap:** Önce bir öğrenci açıkladı: $\frac{1}{2}$ parantezine alındığında, $n$ sonsuza giderken $\frac{1}{n}$ sıfıra gider. Limit değeri $\frac{1}{2}$ çıkar, yani dereceleri aynıdır. Sabitin değerinin önemi yoktur. Hoca bunu tekrarlayıp kuralı yeniden özetledi:

- $t(n)$, $g(n)$'den daha düşük dereceye sahipse, yani $g(n)$ daha hızlı büyüyorsa, sonucun otomatik olarak $0$ çıkmasını bekleriz.
- $t(n)$ ile $g(n)$ aynı derecedeyse bir sabit değer çıkmasını bekleriz.
- $t(n)$, $g(n)$'den daha yüksek dereceye sahipse sonsuza giden bir değer çıkmasını bekleriz.

Yani burada önemli olan sabitin kaç olduğu değil, sonucun $0$, sabit ya da $\infty$ olmasıdır.

## 5. Zaman Karmaşıklığı mı, Bellek Karmaşıklığı mı?

Oturumun sonunda bir öğrenci önce $n^3$'ün $O$ notasyonuyla nasıl gösterileceğini sordu, ardından asıl sorusunu netleştirdi.

<!-- BELİRSİZ: Öğrencinin n küp gösterimiyle ilgili ilk sorusu altyazıda net değil; öğrenci soruyu hemen bellek sorusuna çevirdi. -->

**Soru:** Insertion sort için $O(n^2)$ dedik. Burada bellek (memory) karmaşıklığını mı kastediyoruz? Örneğin toplam 8 eleman varsa $8^2$ mi?

**Cevap:** Hayır. Bütün bu ifadeler zaman karmaşıklığı (time complexity), yani işlem karmaşıklığı üzerindendir. Bellekle ilgili bir şey söylenmedi. $n^2$ ile vurgulanmak istenen şuydu: Tersten sıralı bir diziyi sıralarken her turda baştan sona bir karşılaştırma yapma olasılığı vardır. Bu yüzden $n^2$'lik bir karmaşıklık söz konusu olur.

> **Ek bilgi (derste anlatılmadı):** Insertion sort elemanları dizinin kendi içinde kaydırarak sıralar. Ek bellek olarak yalnız birkaç değişken kullanır, yani bellek karmaşıklığı $O(1)$'dir. Bu tür sıralamalara yerinde sıralama (in-place sorting) denir. Tersten sıralı dizide karşılaştırma sayısı $\frac{n(n-1)}{2}$'dir.

## 6. Örnek Sorular

Bu derste ekran karesi kullanılmadı. Aşağıdaki sorular derste sözlü olarak sorulan sorulardır.

**Soru 1** (derste sözlü, 00:05:42): Insertion sort'ta kaç döngü vardır? Hangisi için `for`, hangisi için `while` kullanılır ve neden?

> **Çözüm:** İki döngü vardır. Dış döngü `for`dur, çünkü bütün elemanlar gezilir. İç döngü `while`dır, çünkü tek bir karşılaştırmada da sonlanabilir.

**Soru 2** (derste sözlü, 00:08:59): Insertion sort'un ortalama durum analizinde dış döngünün toplamı $k$'nın hangi değerleri üzerinden alınır ve toplamın içine ne yazılır?

> **Çözüm:** $k=2$'den $n$'ye kadar. İçine iç döngünün ortalaması $\frac{k+1}{2}$ yazılır: $A(n)=\sum_{k=2}^{n}\frac{k+1}{2}=\frac{n^2+3n-4}{4}\in\Theta(n^2)$. Hoca toplamı $\frac{1}{4}(n^2+3n+2)$ olarak yazdı; farkı Bölüm 2.4'teki ders sonrası notta açıklandı.

**Soru 3** (derste sözlü, 00:15:41): Aşağıdaki ifadeler doğru mu, yanlış mı?

- (a) $n \in O(n^2)$
- (b) $100n+5 \in O(n^2)$
- (c) $\frac{1}{2}n(n-1) \in O(n^2)$

> **Çözüm:** Üçü de doğrudur. Sabitler, katsayılar ve düşük dereceli terimler atılınca (a) ve (b)'de $n$, (c)'de $n^2$ kalır. Hepsi $n^2$ ile üstten sınırlıdır.

**Soru 4** (derste sözlü, 00:21:13): $n^3 \in O(n^2)$ doğru mudur? Değilse, ifadeyi doğru yapmak için ne değiştirilebilir?

> **Çözüm:** Yanlıştır. İki düzeltme yolu derste verildi: $O$ yerine $\Omega$ yazmak ($n^3\in\Omega(n^2)$) ya da $\in$ yerine $\notin$ yazmak ($n^3\notin O(n^2)$).

**Soru 5** (derste sözlü, 00:24:03): $0.0001n^3$ ile $O(n^2)$ arasına hangi işaret gelmelidir?

> **Çözüm:** $0.0001n^3 \notin O(n^2)$. Katsayı elenir, geriye $n^3$ kalır.

**Soru 6** (derste sözlü, 00:28:52): $t(n)=\frac{1}{2}n(n-1)$ ve $g(n)=n^2$ fonksiyonlarının büyüme derecelerini limitle karşılaştırın.

> **Çözüm:** $\lim_{n\to\infty}\frac{\frac{1}{2}n(n-1)}{n^2}=\frac{1}{2}\lim_{n\to\infty}\left(1-\frac{1}{n}\right)=\frac{1}{2}$. Sonuç sabit olduğundan iki fonksiyon aynı büyüme derecesine sahiptir: $\frac{1}{2}n(n-1)\in\Theta(n^2)$.

## Dersin Toparlaması

Bu uygulama oturumunda önce asimptotik gösterimde sadeleştirme kuralları hatırlatıldı: sabitler, katsayılar ve düşük dereceli terimler atılır, en yüksek dereceli terim kalır. Ardından insertion sort'un ortalama durumu hesaplandı. $k$. elemanın sıralı kısımdaki $k$ konumdan birine eşit olasılıkla yerleştiği varsayılınca iç döngü ortalama $\frac{k+1}{2}$ adım sürer. Bu, $k=2$'den $n$'ye toplanınca yaklaşık $\frac{n^2}{4}$ eder. Yani insertion sort'un ortalama durumu da en kötü durumu gibi $\Theta(n^2)$'dir. Doğru-yanlış sorularında bir ifadenin yalnız $\in$ ile değil, $\notin$ ile ya da notasyonu değiştirerek ($\Omega$) de doğru hale getirilebileceği görüldü. Son olarak iki fonksiyonun büyüme derecesini $\lim_{n\to\infty} t(n)/g(n)$ limitinin $0$, sabit ya da $\infty$ çıkmasına göre karşılaştırma yöntemi öğrenildi.

Hoca, asimptotik gösterimlerle ilgili oldukça yol alındığını söyledi: büyüme dereceleri, bunları ispatlama yaklaşımları ve iki fonksiyon arasındaki "elemanıdır / değildir" ifadesini doğrulama yolları görüldü. Bunların hepsi algoritmaları birbirleriyle kıyaslama imkânı verir. Gelecek hafta toplam (summation) formülleriyle ilgili matematik hatırlatmaları yapılacak, ardından iteratif ve özyinelemeli (recursive) algoritmaların matematiksel analizine geçilecek ve büyüme dereceleri asimptotik gösterimle ifade edilmeye başlanacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
