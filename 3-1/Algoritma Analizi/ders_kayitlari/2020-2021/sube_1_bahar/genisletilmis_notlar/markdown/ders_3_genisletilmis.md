# Ders 3 Genişletilmiş Notu: Asimptotik Notasyonlar, İteratif ve Özyinelemeli Algoritmaların Analizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Asimptotik notasyonların tekrarı
- 2. Big-O notasyonu ve ispat örnekleri
- 3. Big-Omega notasyonu
- 4. Big-Theta notasyonu
- 5. Slayt örnekleri, sadeleştirme kuralları ve limit yöntemi
- 6. Analiz için matematik araçları
- 7. Özyinelemeli olmayan algoritmaların analizi
- 8. Özyinelemeli algoritmaların analizi
- 9. Master teoremi
- Örnek Sorular

## 1. Asimptotik notasyonların tekrarı

Bir algoritmanın çalışma zamanını ya da bellek kullanımını incelerken makineden makineye değişen etkenlerden kurtulmak gerekir. Bunun için önce algoritmadaki temel işlemlerin (toplama, çıkarma, atama, karşılaştırma) maliyetleri ve kaç kez yapıldıkları belirlenip toplam bir maliyet bulunur. Maliyetler de makineye göre değiştiğinden, işin yükünü çeken tek bir temel operasyon üzerinden sayım yapmak tercih edilir. Elde edilen çalışma zamanı fonksiyonu $T(n)$, sonunda daha sade ve alt/üst sınırları gösteren **asimptotik notasyonlarla** yazılır.

Hoca önceki dersten kalan tahtayı göstererek beş sembolü özetledi (ekrandan, 00:10:00):

| Sembol | Ad | Anlamı | İlişki |
|---|---|---|---|
| $O$ | Big-O | üst sınır (upper bound) | $T(n) \le O(f(n))$ |
| $o$ | little-o | kesin üst sınır | $T(n) < o(f(n))$ |
| $\Omega$ | Big-Omega | alt sınır (lower bound) | $T(n) \ge \Omega(f(n))$ |
| $\omega$ | little-omega | kesin alt sınır | $T(n) > \omega(f(n))$ |
| $\Theta$ | Big-Theta | sıkı sınır (tight bound) | $T(n) \cong \Theta(f(n))$ |

Tahtada ayrıca $\Omega(f(n)) \le T(n) \le O(f(n))$ ilişkisi yazılıydı. $f(n)$ yerine gelecek fonksiyonlar $1$, $\log n$, $n$, $n\log n$, $n^2$ gibi sade fonksiyonlardır. Bir de tilde ($\sim$) sembolü vardır, ama derste işlenmedi. Little-o ile little-omega da ayrıntılı ele alınmadı.

Hoca derste genelde çok slayt kullanmayacağını, kullandığı yardımcı slaytları paylaştığını söyledi. Gün içinde algoritmalar iteratif ve özyinelemeli olarak analiz edilecek, bulunan $T(n)$ uygun asimptotik notasyonla ifade edilecekti.

## 2. Big-O notasyonu ve ispat örnekleri

### 2.1 Tanım

$f(n) \in O(g(n))$ denebilmesi için şu koşul sağlanmalıdır (ekrandan, 00:25:00):

$$0 \le f(n) \le c \cdot g(n), \quad \text{her } n > n_0 > 0 \text{ için ve } c > 0.$$

Derste $c$ ve $n_0$ tam sayı (integer) alındı. Hoca bunun gerekçesini şöyle açıkladı: $n_0$ bir dizideki eleman sayısı ya da bir çizgedeki düğüm sayısı gibi düşünülür, dolayısıyla bunlar tam sayılardır.

Grafikte yatay eksen $n$, dikey eksen $T(n)$'dir. Algoritmanın fonksiyonu başlangıçta düzensiz bir davranış gösterebilir, sonra bir örüntüye oturur. Bu oturma noktası $n_0$'dır. $n_0$'dan büyük değerler için algoritmayı üstten saran $c \cdot g(n)$ fonksiyonu bulunursa $f(n) \in O(g(n))$ denir. Böyle bir $c$ ve $n_0$ ikilisine **şahit (witness)** denir.

**Soru:** $n_0$ neden tanıma konuyor? **Cevap:** Bir öğrenci fonksiyonun düzgün bir hal alması için gerekebileceğini söyledi; hoca bunu doğruladı. Küçük $n$ değerleri için bazı algoritmaları analiz etmenin anlamı yoktur, önemli olan $n$ sonsuza giderken davranıştır. Örneğin $n^3$ ile $n^2$ $n = 1$ için ikisi de 1'dir; bir elemanlı girdide karşılaştırmanın bir anlamı yoktur. Fark $n = 2$'den sonra ortaya çıkar.

Üst sınır, algoritmanın "olsa olsa bu kadar olur" diyebileceğimiz en kötü karmaşıklığını gösterir. Daha büyük dereceli bir $g(n)$ ile de üst sınır yazılabilir, ama bu gereksizdir. $n^2$'lik bir algoritmaya $O(n^3)$ demek matematiksel olarak doğrudur, mantıksal olarak doğru değildir. Bilinen en yakın fonksiyon kullanılmalıdır.

**Soru:** $c$ için bir kural var mı; tam sayı mı, rasyonel mi olmalı? **Cevap:** Derste $c$ ve $n_0$ tam sayı olarak alınıyor.

### 2.2 Örnek: $10n + 30 \in O(n)$ mi?

Bu tür bir soru "elemanıdır / elemanı değildir" seçimiyle sorulabilir ve tanımdan yola çıkarak ispat istenebilir (ekrandan, 00:25:00).

Tanıma göre $10n + 30 \le c \cdot n$ sağlanmalıdır.

- Deneme yanılma: $n_0 = 1$ için $40 \le c$ gelir. $c = 40$ seçilir.
- Eşitsizlik çözme yoluyla: $10n$ karşıya atılırsa $30 \le n(c - 10)$ olur. $c - 10$ sabittir, $n$ ise sürekli artar. Uygun bir $c$ (örneğin $c = 11$) seçildiğinde, $n$ yeterince büyüyünce (örneğin $n_0 = 30$) eşitsizlik hep sağlanır.

Sonuç: $10n + 30 \in O(n)$.

Hoca sık yapılan bir hatayı gösterdi. $c = 1$ seçilirse $10n + 30 \le n$ olması gerekir; $10n + 30$ her zaman $n$'den büyük olduğu için bu hiçbir $n$ için sağlanmaz. Bu ikili geçersizdir, başka bir ikili aranmalıdır.

**Kısa yol:** Her terimi en büyük dereceli terim gibi düşünmek. $10n + 30 \le 10n + 30n = 40n$ olduğundan $c = 40$, $n_0 = 1$ hemen bulunur.

> **Hocanın vurgusu:** "İspatını yapın" denirse bu biçimde bir çözüm beklenir: eşitsizlik yazılır, onu $n_0$'dan sonraki bütün $n$ için sağlayan bir $c$, $n_0$ ikilisi gösterilir.

Hoca ters yönlü örneklerin de denenmesini önerdi. $10n + 30 \in O(1)$ olmayacağı açıktır. $10n + 30 \in O(\log n)$ da olamaz: $\log n$, $n$'den her zaman daha yavaş büyür, hiçbir sabit çarpan bu farkı kapatamaz.

### 2.3 Örnek: $n^2 + 2n + 1 \in O(n^2)$

$n^2 + 2n + 1 \le c \cdot n^2$ sağlanmalıdır. $n = 1$ için $1 + 2 + 1 = 4 \le c$ olur, $c = 4$ seçilir. $c = 4$ için $4n^2$ her zaman $n^2 + 2n + 1$'den büyük ya da ona eşittir, çünkü $2n + 1$ terimi $4n^2$'ye karşı hız kazanamaz. Sonuç: $n^2 + 2n + 1 \in O(n^2)$.

> **Ders sonrası not:** Hoca $n = 2$ için $c = 4$'ün yetmediğini, en az 5 gerektiğini söyledi. Oysa $n = 2$'de sol taraf $9$, sağ taraf $4 \cdot 4 = 16$'dır; $c = 4$, $n_0 = 1$ bütün $n \ge 1$ için geçerlidir, çünkü $4n^2 - (n^2 + 2n + 1) = (3n+1)(n-1) \ge 0$ (python ile kontrol edildi).

### 2.4 Örnek: $n^2 + n$, $O(n^3)$ mü, $O(n)$ mi?

Ekranda $f(n) = n^2 + n$ için iki soru yazıldı (ekrandan, 00:35:00).

**$O(n^3)$:** $n^2 + n \le c \cdot n^3$ sağlanmalıdır. Hoca önce $c = 1$, $n_0 = 1$'i denedi: $2 \le 1$ sağlanmaz. Sonra daha büyük $n$ değerleri verdi: $c = 2$ ve $n = 5$ için $25 + 5 = 30 \le 250$; $n = 4$ için $20 \le 128$. $c = 1$ ile bile $n = 3$'te $12 \le 27$ olur. Ekranda $c = 2$, $n = 5$ ikilisi çerçevelendi. Sonuç: $n^2 + n \in O(n^3)$.

> **Ders sonrası not:** Derste $c = 2$, $n_0 = 1$ ikilisinin de sağlanmadığı söylendi. Aslında $n = 1$'de $2 \le 2$ olduğundan bu ikili de geçerlidir; $n \ge 1$ için $n^2 + n \le 2n^3$ (python ile kontrol edildi).

**$O(n)$:** $n^2 + n \le c \cdot n$ sağlanmalıdır. $n = 1$, $c = 2$ ilk bakışta uygun görünür, ama $n = 2$ ya da $n = 3$ için sağlanmaz. Eşitsizlik çözülürse:

$$n^2 \le cn - n = n(c - 1) \;\Rightarrow\; n \le c - 1.$$

Sürekli artan bir şey hiçbir zaman sabit bir şeyden küçük kalamaz. Çelişki çıktığı için $n^2 + n \notin O(n)$.

Bu örnek, sağladığı ve sağlamadığı durum arasındaki farkla $n_0$'ın anlamını da gösterir: küçük değerlerde kurallara uymayan durumlar olabilir, ama asimptotik notasyon $n$'in sonsuza giden değerleriyle ilgilenir.

## 3. Big-Omega notasyonu

Big-Omega alt sınırdır (lower bound): algoritmanın en iyi ihtimalle hangi fonksiyonla ifade edileceğini söyler.

- Sıralı bir dizide arama yapılırken en iyi durum ilk denemede bulmaktır; bir öğrenci bunun 1 olduğunu söyledi, hoca doğruladı.
- Bubble Sort'ta elemanlar ikişer ikişer ($1$-$2$, $2$-$3$, ..., $(n-1)$-$n$) karşılaştırılır, kurala uymayan durumda yer değiştirilir (swap). Bir tur boyunca hiç swap yapılmazsa dizi zaten sıralıdır. Ama bunu anlamak için diziyi en az bir kez baştan sona gezmek gerekir. Bu yüzden en iyi durum $n$ karşılaştırmadır ve alt sınır $n$'dir.

### 3.1 Tanım

$f(n) \in \Omega(g(n))$ denebilmesi için (ekrandan, 00:40:00):

$$f(n) \ge c \cdot g(n), \quad c > 0,\; n_0 > 0,\; \text{her } n > n_0 \text{ için}.$$

Tanım Big-O'nun tam tersidir. Grafikte $c \cdot g(n)$, $n_0$'dan sonra $f(n)$'in altında kalır.

### 3.2 Örnek: $5n^2 \in \Omega(n^2)$

$5n^2 \ge c \cdot n^2$ sağlanmalıdır. Ortak paranteze alınırsa:

$$(5 - c)\,n^2 \ge 0.$$

$n = 1$, $c = 1$ için $4 \ge 0$ sağlanır. $n = 2$ için $(5-1)\cdot 4 = 16 \ge 0$ olur. Parantezin içini negatif yapmayan her $c$ değeri ($1, 2, 3, 4, 5$) uygundur; $n$'in artan değerlerinde sol taraf hep büyük kalır. Sonuç: $5n^2 \in \Omega(n^2)$.

### 3.3 Örnek: $5n^2 \in \Omega(n)$ mi?

Evet. $5n^2$, $n$'i alttan hayli hayli kapsar. $5n^2 \ge c \cdot n$ eşitsizliğinde $n_0 = 1$ ve $5$'ten küçük bir $c$ (örneğin $c = 3$) seçilirse sağlanır.

Hoca bir karşılaştırma yaptı: Big-O'da daha yüksek bir fonksiyon yazmak "mütevazı" davranmaksa, Big-Omega'da daha düşük bir fonksiyon yazmak "cimri" davranmaktır. Algoritmanın en iyi halini olduğundan küçük göstermiş oluruz.

**Soru:** Üst sınır neden en kötü durum senaryosu oluyor? **Cevap:** Örneğin $n$ elemanlı bir diziyi $n^2$'lik bir algoritmayla sıralıyorsanız, bunun $n^2$'den daha kötü olma ihtimali yoktur. Bunu göstermek için en üst sınırı söylemek gerekir; bu yüzden ona upper bound denir.

## 4. Big-Theta notasyonu

### 4.1 Neden gerekli?

$n^2$'lik bir algoritmanın üst sınırı tanım gereği $n^3$ ya da $n^4$ olarak da yazılabilir. Bu durumda "Big-O'su $n^2$ ise algoritma belki daha düşüktür" diye düşünülebilir. Aynı şekilde $\Omega(n^2)$ olan bir şey $\Omega(n)$ diye de yazılabilir. Üst sınırın yukarı, alt sınırın aşağı kaymasını engelleyen, kesin ve sıkı bir ifade **Big-Theta**'dır. Big-Theta, Big-O ile Big-Omega'nın kesişimidir: bir algoritma hem $O(n^2)$ hem $\Omega(n^2)$ ise $\Theta(n^2)$'dir.

### 4.2 Tanım

Grafikte $f(n)$ iki eğrinin arasında kalır: $c_1 \cdot g(n)$ ve $c_2 \cdot g(n)$ (ekrandan, 00:50:00). Ekranda şunlar yazılıydı:

$$f(n) \in \Theta(g(n)), \qquad f(n) \text{ is asymptotically equal to } g(n).$$

Standart tanım:

$$c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n), \quad c_1, c_2 > 0,\; \text{her } n > n_0 \text{ için}.$$

> **Ders sonrası not:** Hoca tanımı anlatırken hangi sabitin alttan, hangisinin üstten sardığını birkaç kez karıştırıp düzeltti; ekrandaki koşul da tam okunmuyor. Yukarıdaki yazım ders kitaplarındaki standart tanımdır. Aşağıdaki örnekte ise hoca $c_1$'i Big-O (üst) için, $c_2$'yi Big-Omega (alt) için kullandı.

$\Theta(n^2)$ olan bir algoritmaya $n^3$ denemez, çünkü hem Big-O'su hem Big-Omega'sı $n^2$'dir. Big-Theta, iki ayrı ispatı (Big-O ve Big-Omega) birlikte yapmak gibidir ve yoruma yer bırakmayan dar bir aralık verir.

### 4.3 Örnek: $2n + 5 \in \Theta(n)$

(ekrandan, 00:50:00 ve 01:15:00)

**Adım 1, $O(n)$:** $2n + 5 \le c_1 \cdot n$. $c_1 = 7$, $n_0 = 1$ seçilirse sağlanır. Eşitsizlik $(c_1 - 2)\,n \ge 5$ biçiminde yazılırsa: $c_1 = 7$ için $5n \ge 5$, bu da bütün $n \ge 1$ için doğrudur. Sonuç: $f(n) \in O(n)$.

**Adım 2, $\Omega(n)$:** $2n + 5 \ge c_2 \cdot n$. $2n$ karşıya atılırsa $5 \ge n(c_2 - 2)$ olur. Ekranda $n = 1$, $c_2 = 4$ seçildi. Sonuç: $f(n) \in \Omega(n)$.

**Sonuç:** İkisinden birlikte $f(n) \in \Theta(n)$.

> **Ders sonrası not:** $c_2 = 4$ seçimi yalnız $n = 1$ ve $n = 2$ için sağlanır; $n = 3$'te $11 \ge 12$ yanlıştır. Bütün $n \ge 1$ için geçerli bir şahit $c_2 = 2$'dir: $2n + 5 \ge 2n$ (python ile kontrol edildi). Sonuç değişmez.

Hoca bazı algoritmalarda en iyi, en kötü ve ortalama durumların eşit olduğunu söyledi. Örneğin 1'den $n$'e kadar sayıları toplarken hiç `if` yoktur, işlem tam $n$ kez yapılır. Böyle durumlarda Big-Theta doğrudan yazılabilir.

## 5. Slayt örnekleri, sadeleştirme kuralları ve limit yöntemi

### 5.1 Slayttaki Big-O örnekleri

Aradan sonra hoca "Analysis of Algorithms" slaytlarından örneklere geçti. Slaytta Big-O'nun çalışma zamanı ve bellek sınırlarını göstermek için yaygın kullanıldığı, sabit çarpanları ve düşük dereceli terimleri görmezden gelip büyümeyi belirleyen ana bileşene odaklanmayı sağladığı yazıyordu (ekrandan, 01:05:00).

- **$2n + 10 \in O(n)$:** $2n + 10 \le cn$ ise $(c - 2)n \ge 10$, yani $n \ge 10/(c - 2)$. $c = 3$ ve $n_0 = 10$ seçilir. Grafikte $3n$ doğrusu $n = 10$'dan sonra $2n + 10$'u üstten sarar.
- **$n^2 \notin O(n)$:** $n^2 \le cn$ ise $n \le c$ olmalıdır. $c$ sabittir; 100 de olsa 1 milyon da olsa sabit ile $n$'in çarpımı $n^2$'yi hiçbir zaman geçemez.
- **$7n - 2 \in O(n)$:** $c = 7$, $n_0 = 1$ (ekrandan, 01:10:00).
- **$3n^3 + 20n^2 + 5 \in O(n^3)$:** Slaytta $c = 4$, $n_0 = 21$ verilmişti (ekrandan, 01:10:00). Hoca kısa yolu gösterdi: her terimi $n^3$ gibi düşününce $3n^3 + 20n^3 + 5n^3 = 28n^3$ olur. $c = 28$ (ya da daha büyük, örneğin 29) ve $n_0 = 1$ ile eşitsizlik sağlanır.
- **$3\log n + 5 \in O(\log n)$:** $3\log n + 5 \le c \log n$ için $c = 8$, $n_0 = 2$ (ekrandan, 01:10:00). $n = 2$'de $\log_2 2 = 1$ olduğundan $8 \le 8$ sağlanır.

> **Hocanın vurgusu:** Polinom biçimli bir soruda ispat istenmiyorsa en yüksek dereceli terimi alıp doğrudan $O(n^k)$ yazmak yeterlidir. Örneğin $n^4 + 3n^3 + \dots$ için $O(n^4)$.

Slayt örnekleri python ile kontrol edildi: $c = 4$, $n_0 = 21$ ikilisi geçerlidir ($n = 20$'de sağlanmaz), $c = 8$, $n_0 = 2$ de geçerlidir.

### 5.2 Büyüme oranı yorumu

$f(n) \in O(g(n))$ ise $f(n)$'in büyümesi $g(n)$'in büyümesinden fazla değildir: $g(n)$ daha hızlı ya da aynı hızda büyür. Örneğin $n^2 + 3n \in O(n^2)$'de ikisi aynı hızda büyür (same growth). Ama $f(n) = n^2$, $g(n) = n^3$ ise $f \in O(g)$ doğrudur, $g \in O(f)$ yanlıştır.

### 5.3 Sadeleştirme kuralları

- Düşük dereceli terimler (lower order terms) atılır: $n^2 + n$'de yükü çeken $n^2$'dir.
- Sabit çarpanlar (constant factors) atılır: $2n \in O(n)$ demek yeterlidir, $O(2n)$ demeye gerek yoktur.
- Mümkün olan en küçük sınıf kullanılır: $2n$'lik bir algoritmaya $O(n^2)$ demek mantıksal olarak doğru değildir.
- En sade ifade kullanılır: $3n + 5 \in O(n)$, $O(3n)$ değil.
- Polinomda en yüksek dereceli terim alınır, katsayılar ve düşük dereceli terimler gider.

Önemli fonksiyonların büyüme sırası (önceki dersten tekrar):

$$1 < \log n < n < n\log n < n^2 < n^3 < 2^n < n! < n^n.$$

Bu sırada yukarıdaki bir fonksiyon, aşağıdakinin üst sınırıdır; örneğin üstel bir fonksiyon, kübik bir fonksiyonun üst sınırıdır. Ters yönde de alt sınır ilişkisi okunur.

### 5.4 Detaylı analizden asimptotik notasyona

Hoca, bir algoritmanın her satırındaki işlemin maliyetini ve kaç kez yapıldığını sayan detaylı analizin bir örneğini başka bir dersten getirdiği bir slaytta gösterdi. Bu analizde iç içe iki döngü içeren bir sıralama algoritmasının satırlarında $2n + 1$, $n$, $\frac{n(n+1)}{2}$ gibi sayılar çıkıyor ve toplam $T(n) = 2n^2 + 6n + 5$ bulunuyordu. <!-- BELİRSİZ: slayt karesi yok; algoritmanın adı altyazıda "Selection Sort" gibi geçiyor ve satır sayımları kareden doğrulanamadı. -->

**Soru:** Bu sonuç Big-O ile nasıl gösterilir? **Cevap:** Bir öğrenci $O(n^2)$ dedi; hoca doğruladı. İspat istenirse bir $c$ ve $n_0$ ikilisi gösterilmelidir.

### 5.5 Limit ile karşılaştırma

İki algoritmayı karşılaştırmanın bir başka yolu limittir (ekrandan, 01:20:00):

$$\lim_{n\to\infty} \frac{T(n)}{g(n)} = \begin{cases} 0 & \Rightarrow T(n) < g(n),\; T(n) \in O(g(n)) \\ c & \Rightarrow T(n) \approx g(n),\; T(n) \in \Theta(g(n)) \\ \infty & \Rightarrow T(n) > g(n),\; T(n) \in \Omega(g(n)) \end{cases}$$

Sonucun 0 çıkması "sayı bölü sonsuz" durumudur: payda daha hızlı büyür. Sabit çıkması iki fonksiyonun aynı ayarda olduğunu gösterir.

Örnek: $T(n) = n^2$, $g(n) = 2n^2$. Limit $\infty/\infty$ belirsizliğidir; türev alınınca $2n/4n$, yine $\infty/\infty$; bir daha türev alınınca $2/4 = 1/2$. Sabit çıktığı için $T(n) \in \Theta(g(n))$.

Hoca çalışma sorusu olarak $2^n$ ile $n!$'i limitle ya da Big-O/Big-Omega tanımıyla karşılaştırmayı önerdi.

> **Ders sonrası not:** Hoca soruyu verirken $2^n$'in daha büyük olduğunu söyledi. Doğrusu, $n!$ daha hızlı büyür: $n \ge 4$ için $n! > 2^n$ ve $\lim_{n\to\infty} 2^n / n! = 0$, yani $2^n \in O(n!)$. Derste yazılan büyüme sırası da bununla uyumludur (python ile kontrol edildi).

## 6. Analiz için matematik araçları

Hoca iteratif ve özyinelemeli algoritmaları analiz etmeden önce sık kullanılan formülleri hatırlattı.

### 6.1 Logaritma özellikleri

(ekrandan, 01:25:00)

1. $\log x^y = y \log x$
2. $\log xy = \log x + \log y$
3. $\log \frac{x}{y} = \log x - \log y$
4. $\log_a x = \log_a b \cdot \log_b x$ (taban değiştirme)
5. $a^{\log_b x} = x^{\log_b a}$

Hoca en çok 1., 2. ve 5. kuralın gerekeceğini söyledi. Örnek kullanım: $2^i = k$ ise iki tarafın 2 tabanında logaritması alınır, $\log_2 k = i \log_2 2$ olur ve $i = \log_2 k$ bulunur. Özyinelemeli analizde bu tür denklemler sık çıkar.

### 6.2 Kombinatorik

(ekrandan, 01:25:00)

- $n$ elemanlı bir kümenin permütasyon sayısı: $P(n) = n!$. Bir algoritma bütün permütasyonları geziyorsa $n!$ kez adım koşar.
- $n$ elemanlı bir kümenin $k$'lı kombinasyon sayısı: $\binom{n}{k} = \frac{n!}{k!\,(n-k)!}$.
- $n$ elemanlı bir kümenin alt küme sayısı: $2^n$.

Üstel ve faktöriyel ifadeler analizde çok kullanılacak.

### 6.3 Toplam formülleri

(ekrandan, 01:30:00)

- $\sum_{i=l}^{u} 1 = u - l + 1$ ($l \le u$); terim sayısı kadar 1'in toplamı. Özel olarak $\sum_{i=1}^{n} 1 = n$.
- $\sum_{i=1}^{n} i = 1 + 2 + \dots + n = \frac{n(n+1)}{2} \approx \frac{1}{2}n^2 \in O(n^2)$.
- $\sum_{i=1}^{n} i^2 = \frac{n(n+1)(2n+1)}{6} \approx \frac{1}{3}n^3$.
- $\sum_{i=1}^{n} i^k = 1^k + 2^k + \dots + n^k \approx \frac{1}{k+1} n^{k+1}$.
- $\sum_{i=0}^{n} a^i = 1 + a + \dots + a^n = \frac{a^{n+1} - 1}{a - 1}$, $a \ne 1$.
- $\sum_{i=1}^{n} \frac{1}{i} = 1 + \frac{1}{2} + \dots + \frac{1}{n} \approx \ln n + 0.5772$.

> **Ders sonrası not:** Ekranda $\sum i^k$ için payda $k$, geometrik toplam için payda $a$ yazıldı. Doğrusu, paydalar sırasıyla $k+1$ ve $a-1$'dir. Hoca $\sum i^k$ sonucuna "eksponansiyel bir durum" dedi; sonuç $n$'in $(k+1)$. dereceden bir polinomudur.

> **Ek bilgi (derste anlatılmadı):** Harmonik toplamdaki $0.5772\ldots$ sabitine Euler-Mascheroni sabiti ($\gamma$) denir. Python ile $n = 10^6$ için $H_n - \ln n \approx 0.57722$ bulunur.

Hoca en çok ilk üç formülün kullanılacağını söyledi.

### 6.4 Toplam manipülasyonları

- Sabit çarpan dışarı alınır: $\sum_{i=l}^{u} c\,a_i = c \sum_{i=l}^{u} a_i$.
- Toplama ve çıkarma ayrılabilir: $\sum_{i=l}^{u} (a_i \pm b_i) = \sum_{i=l}^{u} a_i \pm \sum_{i=l}^{u} b_i$.
- Sınır bölünebilir: $\sum_{i=l}^{u} a_i = \sum_{i=l}^{m} a_i + \sum_{i=m+1}^{u} a_i$, $l \le m < u$.
- Sınır kaydırılabilir: $\sum_{i=2}^{5} a_i = \sum_{i=0}^{3} a_{i+2}$. Alt sınır 2 birim düşürülünce terimdeki indeks 2 artırılır (ara adım eklendi).

### 6.5 Taban (floor) ve tavan (ceiling)

$\lfloor x \rfloor$ aşağı, $\lceil x \rceil$ yukarı yuvarlamadır; bu bir "round" (en yakına yuvarlama) değildir.

- $\lfloor 3.8 \rfloor = 3$, $\lfloor -3.8 \rfloor = -4$.
- $\lceil 2.7 \rceil = 3$, $\lceil -2.7 \rceil = -2$.
- $\lceil \log_2(n+1) \rceil = \lfloor \log_2 n \rfloor + 1$ ($n \ge 1$). Bu eşitlik ikili aramada (binary search) sık karşımıza çıkar (python ile $1 \le n < 5000$ için kontrol edildi).

Hoca buraya kadar anlatılanları şöyle bağladı: asimptotik notasyonlar bir fonksiyonu alt sınır, üst sınır ya da sıkı sınırla en sade biçimde göstermek içindir. Bunu yapmak için önce algoritmada maliyet oluşturan işlemler $n$ cinsinden sayılır, sonra asimptotik notasyonla yazılır.

## 7. Özyinelemeli olmayan algoritmaların analizi

### 7.1 Genel yöntem

Algoritmalar iteratif ve özyinelemeli (recursive) olarak ikiye ayrılır. İteratif algoritmalar ilk satırdan son satıra adımlar sayılarak analiz edilebilir. Ancak her adımı saymaya gerek yoktur: okuma, yazma, atama gibi işler çok önemli değildir; yükü çeken temel operasyonu saymak yeterlidir. Özyinelemeli algoritmalar bir yere kadar iteratif ilerler, sonra kendini tekrar eder; bu farklı bir analiz gerektirir.

Analiz adımları:

1. Girdi boyutu $n$ belirlenir (number of elements).
2. Temel operasyon (basic operation) belirlenir. Bu, her durumda mutlaka yapılan ve algoritmanın yükünü çeken işlemdir.
3. En içteki döngüye (innermost loop) dikkat edilir, çünkü temel operasyon en çok orada yürütülür.
4. Temel operasyonun kaç kez yürütüldüğünü gösteren $T(n)$ bir toplam olarak kurulur.
5. Sonuç asimptotik notasyonla ($O$, $\Omega$, $\Theta$) yazılır.
6. Temel operasyonun sayısı girdinin durumuna bağlıysa best, worst ve average case ayrı ayrı incelenir.

Hoca ek bir yorum yaptı: $T(n)$ polinom zamandan küçükse (ya da eşitse) probleme **tractable / solvable** (çözülebilir), daha büyükse **intractable / non-solvable** denir.

### 7.2 Örnek 1: Dizideki en büyük eleman (MaxElement)

(ekrandan, 01:40:00)

```text
MaxElement(A[0..n-1])
    max <- A[0]
    for i <- 1 to n-1 do
        if A[i] > max
            max <- A[i]
    return max
```

- $n$: eleman sayısı.
- Temel operasyon: karşılaştırma (`A[i] > max`). Döngü her zaman döner ve `if` her adımda kesin çalışır; atama ise her zaman yapılmaz. Döngü sayacının artırılması gibi işlemler de sayılabilir, ama yükü taşıyan karşılaştırmadır.

$$T(n) = \sum_{i=1}^{n-1} 1 = n - 1 \quad (\text{karşılaştırma sayısı}).$$

**Soru:** Bu nasıl bir asimptotik notasyonla yazılır? **Cevap:** Bir öğrenci $O(n)$ dedi. Hoca ayrıca $\Theta(n)$ ve $\Omega(n)$ da denebileceğini sordu ve gerekçesini açıkladı: karşılaştırma $n$ ne olursa olsun kesinlikle yapılır. Bu yüzden ekranda üçü de işaretlendi (ekrandan, 01:50:00):

- $O(n) \to C_{worst}(n)$
- $\Theta(n) \to C_{average}(n)$
- $\Omega(n) \to C_{best}(n)$

**Soru:** $n - 1$ bulunduğuna göre $O(n-1)$ denebilir mi? **Cevap:** Hayır. Asimptotik notasyon en sade fonksiyonlarla ($n$, $n^2$, $n^3$, $\log n$, $n\log n$) yazılır; içine başka terimler yazılmaz.

Temel operasyon atama seçilseydi durumlar farklı olurdu. En büyük eleman ilk sıradaysa atama yalnız bir kez yapılır (en iyi durum); en büyük eleman sonda ve dizi artan sıradaysa her adımda atama yapılır (en kötü durum). Ortalama durum için her pozisyonun olasılığı (100 elemanda $1/100$) hesaba katılmalıdır.

### 7.3 Örnek 2: Benzersiz elemanlar (unique elements)

(ekrandan, 01:50:00)

Bir dizinin yalnız birbirinden farklı elemanlardan oluşup oluşmadığı kaba kuvvet (brute force) yöntemle kontrol edilir: her eleman kendisinden sonraki bütün elemanlarla karşılaştırılır.

```text
for i <- 0 to n-2 do
    for j <- i+1 to n-1 do
        if A[i] == A[j]
            return false
return true
```

Dış döngü $n-2$'ye kadar gider, çünkü son eleman iç döngüde kontrol edilir. Aynı elemanları saymak istenirse `return false` yerine bir sayaç artırılabilir (ekranda `c = 0` ve `c++` notu vardı). Önemli olan döngü yapısıdır.

- $n$: eleman sayısı.
- Temel operasyon: eşitlik karşılaştırması (`==`); maliyeti 1 birim kabul edilir. Bunu bir öğrenci söyledi.

$$T(n) = \sum_{i=0}^{n-2} \sum_{j=i+1}^{n-1} 1 = \sum_{i=0}^{n-2} \big[(n-1) - (i+1) + 1\big] = \sum_{i=0}^{n-2} (n - 1 - i).$$

Toplam ikiye ayrılır (ara adım eklendi):

$$T(n) = \sum_{i=0}^{n-2} (n-1) - \sum_{i=0}^{n-2} i = (n-1)^2 - \frac{(n-2)(n-1)}{2} = \frac{n(n-1)}{2} \approx \frac{1}{2}n^2.$$

Asimptotik olarak $T(n) \in \Theta(n^2)$; aynı zamanda $O(n^2)$ ve $\Omega(n^2)$. Karşılaştırma kesin kes yapıldığından $\Theta(n^2)$ söylemek yeterlidir, diğerlerini kapsar. Python ile $T(n) = n(n-1)/2$ olduğu $n < 50$ için doğrulandı.

Hoca çalışma zamanını şöyle bağladı: temel operasyonun bilgisayardaki maliyeti $c_{op}$ (birim süre) ise toplam çalışma süresi yaklaşık $T_{total} \approx c_{op} \cdot T(n)$ olur. $T(n)$ temel operasyonun frekansını, $c_{op}$ makinedeki birim süreyi verir. Bu örnekte de best, average ve worst case birbirine eşittir.

### 7.4 Örnek 3: Sıralı arama (sequential search)

(ekrandan, 02:10:00)

```c
int search(int n, int a[], int x)
{
    int i = 0;
    while ((i < n) && (a[i] != x))
        i++;
    if (i < n) return 1;
    else return -1;
}
```

Bulunduğunda 1 yerine konum bilgisi $i$ de döndürülebilir. Temel operasyon karşılaştırmadır. Ancak karşılaştırma bu kez `while` döngüsündedir: kaç kez yapılacağı belli değildir. Önceki örneklerde `for` içinde kesin yapılıyordu. Bu yüzden tek bir analiz yetmez; best, worst ve average case ayrı ayrı yapılır. Hocaya göre best ve worst case kolay, average case daha zordur.

- **Worst case:** Eleman dizinin sonundadır ya da yoktur; $n$ karşılaştırma yapılır. $C_{worst}(n) = n \in \Theta(n)$.
- **Best case:** Eleman ilk sıradadır; bir öğrencinin cevabıyla 1 karşılaştırma. $C_{best}(n) = 1 \in \Theta(1)$.
- **Average case:** Elemanın dizide bulunma olasılığı $p$ ($0 \le p \le 1$, successful), bulunmama olasılığı $1 - p$ (unsuccessful) olsun. Pozisyonlara ayrıcalık tanınmadığından elemanın belirli bir pozisyonda olma olasılığı $p/n$'dir. $i$. pozisyonda bulunursa $i$ karşılaştırma yapılmıştır; bulunamazsa $n$ karşılaştırma yapılır:

$$C_{avg}(n) = \left[1\cdot\frac{p}{n} + 2\cdot\frac{p}{n} + \dots + n\cdot\frac{p}{n}\right] + n(1-p) = \frac{p}{n}\cdot\frac{n(n+1)}{2} + n(1-p) = \frac{p(n+1)}{2} + n(1-p).$$

- $p = 1$ (eleman kesin var): $C_{avg}(n) = \frac{n+1}{2}$.
- $p = 0$ (eleman yok): $C_{avg}(n) = n$.

Python ile $n = 10$, $p = 0.6$ için doğrudan toplam ve kapalı formül aynı sonucu ($7.3$) verdi.

Hoca ortalama durumu $O(n)$ olarak yazdı ve gerekçesini şöyle açıkladı: arama ilk denemede de bitebileceği için $\Theta(n)$'in altına düşme ihtimali vardır, bu yüzden $\Theta(n)$ yerine $O(n)$ demeyi tercih etti.

> **Ders sonrası not:** Bu gerekçe en iyi durumla ortalama durumu karıştırıyor. $C_{avg}(n)$ tek bir fonksiyondur ve sabit bir $p$ için $\frac{p(n+1)}{2} + n(1-p)$ ifadesi $n$ ile doğrusal büyür; dolayısıyla ortalama durum $\Theta(n)$'dir. Tek tek girdilerde $\Theta(n)$'in altına düşülebilmesi, bütün girdiler için tek bir sınır verilirken $O(n)$ yazılmasının gerekçesidir.

### 7.5 Örnek 4: Insertion Sort

Insertion Sort çok kullanışlı bir algoritmadır; Shell Sort da onun bir türevidir. Günlük hayatta iskambil kağıtlarını ya da sınav kağıtlarını elde sıralarken kullandığımız yöntemdir: bir kağıt alınıp uygun yere araya eklenir.

**Soru:** Kontrole hangi elemandan başlanır? **Cevap:** Bir öğrenci ikinci elemandan dedi; hoca doğruladı. İlk eleman tek başına sıralı kabul edilir.

Örnek dizi: $9, 2, 1, 7, 4, 5$ (ekrandan, 02:20:00).

- 2, 9 ile karşılaştırılır; düzen bozulduğu için yer değiştirir: $2, 9, 1, 7, 4, 5$.
- 1 geriye doğru uygun yere taşınır: önce 9, sonra 2 ile karşılaştırılır ve en başa yerleşir.
- Sonraki elemanlar için de kendinden önceki elemanlara bakılarak geriye doğru ilerlenir. Sıralı kısımdan daha küçük bir elemana gelince durulur; kendinden öncekilerin zaten sıralı olduğu bilinir.

Dizi sıralıysa her eleman için tek bir kontrol yapılıp geçilir. Değilse elemanlar kaydırılarak (shift) araya ekleme yapılır.

Ekrandaki akış şeması (ekrandan, 02:20:00):

```text
for i <- 1 to n-1:
    tmp <- a[i]
    j <- i
    while (j > 0) and (tmp < a[j-1]):
        a[j] <- a[j-1]
        j <- j - 1
    a[j] <- tmp
```

Eklenecek yer belli olmadığı için iç döngü bir `while` döngüsüdür.

**Worst case:** Dizi tersten sıralıdır. Her eleman en başa kadar taşınır. Dış döngü $n$ civarında, iç döngü her adımda $i$ civarında döner:

$$C_{worst}(n) = \sum_{i=1}^{n} \sum_{j=1}^{i} 1 = \sum_{i=1}^{n} i = \frac{n(n+1)}{2} \in \Theta(n^2).$$

Hoca iç döngüdeki karşılaştırmayı bir birim işlem kabul etti. Sonuç $O(n^2)$, $\Omega(n^2)$ ve $\Theta(n^2)$ olarak da yazılabilir.

**Best case:** Dizi zaten sıralıdır. Her eleman için bir kontrol yapılır, hiç kaydırma yapılmaz; iç döngüye girilmez. $C_{best}(n) = \sum_{i=1}^{n-1} 1 = n - 1 \in \Theta(n)$.

**Average case:** Elemanlar rastgele dağılmıştır (ekrandan, 02:25:00). $k$. pozisyondaki bir eleman $j$. pozisyona getirilecekse $k - j + 1$ karşılaştırma yapılır. $j$'nin $1$ ile $k$ arasındaki her değeri eşit olasılıklı kabul edilip ortalama alınırsa iç döngü için:

$$C_{\text{iç}}(k) = \frac{1}{k}\sum_{j=1}^{k}(k - j + 1) = \frac{1}{k}\left[k^2 - \frac{k(k+1)}{2} + k\right] = \frac{k+1}{2}.$$

Ara işlem: $\sum_{j=1}^{k} k = k^2$, $\sum_{j=1}^{k} j = \frac{k(k+1)}{2}$, $\sum_{j=1}^{k} 1 = k$. $k$ ile sadeleştirilince $k - \frac{k+1}{2} + 1 = \frac{k+1}{2}$ kalır. Python ile $k = 7$ için doğrudan ortalama ve formül aynı sonucu ($4$) verdi.

Dış döngü $k$ üzerinde toplanır. Hoca sonucu şöyle buldu:

$$C_{avg}(n) \approx \frac{1}{2}\cdot\frac{(n+1)(n+2)}{2} = \frac{1}{4}(n^2 + 3n + 2) \approx \frac{n^2}{4}.$$

<!-- BELİRSİZ: dış toplamın sınırları altyazıda net değil ("ikinci elemandan n. elemana"); $\sum_{k=1}^{n}\frac{k+1}{2} = \frac{n^2+3n}{4}$ olur. Sınırlar ne olursa olsun baskın terim $n^2/4$'tür. -->

Hoca ortalama durumu "her zaman kesin $n^2$'ye ulaşılmaz" diyerek $O(n^2)$ olarak yazdı.

> **Ders sonrası not:** Ortalama karşılaştırma sayısı yaklaşık $n^2/4$ olduğundan Insertion Sort'un ortalama durumu da $\Theta(n^2)$'dir. Özet: best $\Theta(n)$, worst $\Theta(n^2)$, average $\Theta(n^2)$.

## 8. Özyinelemeli algoritmaların analizi

### 8.1 Yineleme bağıntısı

İteratif analizde temel operasyon bulunur ve kaç kez tekrarlandığı hesaplanır. Özyinelemeli algoritmalarda ise temel operasyondan sonra fonksiyon kendini tekrar çağırır. Bu yüzden temel operasyonun kaç kez yürütüleceğini söyleyen bir **yineleme bağıntısı (recurrence relation)** kurulur. Bağıntı kurulurken temel durumda (base case) temel operasyon yapılıp yapılmadığına bakılarak bir **başlangıç koşulu (initial condition)** yazılır.

### 8.2 Örnek: Faktöriyel

```text
F(n):
    if n = 0 return 1
    else return F(n-1) * n
```

Bir öğrencinin cevabıyla temel operasyon çarpmadır. $n = 0$ için yalnız 1 döndürülür, hiç çarpma yapılmaz. $n > 0$ için bir çarpma yapılır, bir de $F(n-1)$ çağrılır:

$$M(n) = M(n-1) + 1, \quad M(0) = 0.$$

**Geriye doğru yerine koyma (backward substitution):**

$$M(n) = M(n-1) + 1 = [M(n-2) + 1] + 1 = M(n-2) + 2 = M(n-3) + 3 = \dots = M(n-i) + i.$$

Temel duruma ulaşmak için $i = n$ alınır: $M(n) = M(0) + n = n$. Sonuç $\Theta(n)$; aynı zamanda $O(n)$ ve $\Omega(n)$.

**Soru:** Burada çarpma için en iyi ya da en kötü durum var mı? **Cevap:** Yok. Çarpmadan önce `if` gibi bir dallanma yoktur; çarpma her çağrıda kesin yapılır, toplam $n$ kez. Bu yüzden üç durum da aynıdır.

**İleriye doğru yerine koyma (forward substitution):** $M(0) = 0$'dan başlanır: $M(1) = 0 + 1 = 1$, $M(2) = 1 + 1 = 2$, $M(3) = 3$, ... ve $M(n) = n$ düzeni görülür. Bu yöntemde düzenin ortaya çıkması daha zor olabildiği için hoca backward substitution'ı daha mantıklı buldu. Özyineleme ağacı (recursion tree) yöntemi de olduğunu, ama derste çoğunlukla backward substitution kullanılacağını söyledi.

### 8.3 Örnek: Bir sayının ikili basamak sayısı

Bir sayının ikili gösteriminde kaç basamak olduğu bulunur. Örneğin 13 için: $13/2 = 6$, $6/2 = 3$, $3/2 = 1$; dört basamak vardır ($13 = 1101_2$). Sayılan şey 1'ler değil basamaklardır; basamak 0 da olabilir.

```text
int BinaryDigit(int n):
    if n == 1 return 1
    else return BinaryDigit(n / 2) + 1
```

Temel operasyon toplamadır (her basamak bulunduğunda bir toplama yapılır); fonksiyon çağrısı da seçilebilirdi. $n = 1$ için toplama yapılmaz:

$$A(n) = A(n/2) + 1, \quad A(1) = 0.$$

$A(n/2)$, ne kadar derine inileceğini; $+1$, o adımda bulunan bir basamağı gösterir. Hoca bu bağıntının bir önceki örnekten farkını vurguladı: faktöriyel birer azaltarak ilerliyordu (decrease and conquer), bu ise yarı yarıya bölüyor (divide and conquer).

**Backward substitution** (ekrandan, 02:40:00):

$$A(n) = A(n/2) + 1 = A(n/4) + 1 + 1 = A(n/4) + 2 = A(n/8) + 3 = \dots = A(n/2^i) + i.$$

Temel duruma ulaşmak için $n/2^i = 1$, yani $n = 2^i$ olmalıdır. İki tarafın 2 tabanında logaritması alınırsa $i = \log_2 n$ bulunur:

$$A(n) = A(1) + \log_2 n = 0 + \log_2 n = \log_2 n.$$

Bir öğrenci $A(1)$'in 0 olduğunu hatırlattı; hoca düzeltti. Algoritma yaklaşık $\log n$ işlem yapar.

**$n = 2^k$ ile çözüm:** Başta $n = 2^k$ yazılırsa:

$$A(2^k) = A(2^{k-1}) + 1 = A(2^{k-2}) + 2 = \dots = A(2^0) + k = A(1) + k = k.$$

$k$ geçici bir değişkendir; $n = 2^k$'den $k = \log_2 n$ bulunur.

> **Ek bilgi (derste anlatılmadı):** $n$ ikinin kuvveti değilse bölme tam sayı bölmesidir ve bağıntı $A(n) = A(\lfloor n/2 \rfloor) + 1$ olur. Çözümü $A(n) = \lfloor \log_2 n \rfloor$'dir; fonksiyonun döndürdüğü basamak sayısı da $\lfloor \log_2 n \rfloor + 1$'dir. Python ile $1 \le n < 5000$ için doğrulandı (13 için 4 basamak).

### 8.4 Örnek: $x(n) = x(n-1) + n$

Yalnız bağıntı verilmiş, algoritma verilmemiş bir örnek (ekrandan, 02:45:00):

$$x(n) = x(n-1) + n, \quad x(0) = 0.$$

Bu, fonksiyonu tekrar çağırmadan önce $n$ işlem (örneğin bir döngü) yapan bir koda karşılık gelir. Önceki örnekte her çağrıda tek bir toplama vardı; burada $n$ işlem vardır.

$$x(n) = x(n-1) + n = x(n-2) + (n-1) + n = x(n-3) + (n-2) + (n-1) + n = \dots$$

$$x(n) = x(n-i) + (n-i+1) + (n-i+2) + \dots + n.$$

$i = n$ için:

$$x(n) = x(0) + 1 + 2 + \dots + n = 0 + \frac{n(n+1)}{2} \in \Theta(n^2).$$

### 8.5 Birden fazla özyinelemeli çağrı

Bazı algoritmalar kendini birden fazla kez çağırır; örneğin $n$ için iki kez $n-1$'i ya da iki kez $n/2$'yi. Fibonacci'de $n-1$ ve $n-2$ çağrıları vardır; bunlar daha sonraki derslere bırakıldı. Böyle bağıntılarda backward substitution bir yerden sonra zorlaşır.

## 9. Master teoremi

### 9.1 Genel biçim ve sezgi

Bağıntı şu genel biçimdeyse **Master teoremi** kullanılır (ekrandan, 02:50:00):

$$T(n) = a\,T\!\left(\frac{n}{b}\right) + f(n), \qquad T(1) = c.$$

- $a$: kaç özyinelemeli çağrı yapıldığı.
- $b$: her çağrıda girdinin kaça bölündüğü.
- $f(n)$: çağrılara gelene kadar yapılan iş ($1$, $n$, $n^2$ gibi).

Hocanın sezgisi: $f(n)$ işi her seviyede yapılır, önemli olan bunun aşağıya kaç kez tekrarlandığıdır. Örneğin $f(n) = n$ ve bölme ikiye ise derinlik $\log n$ olur ve yaklaşık $n\log n$ bulunur. $f(n) = n^2$ (iç içe iki döngü) ve derinlik $n$ olsaydı $n^3$, derinlik $\log n$ olsaydı $n^2 \log n$ gibi bir sonuç çıkardı.

### 9.2 Teorem

$f(n) \in \Theta(n^d)$, $d \ge 0$ ise:

$$T(n) \in \begin{cases} \Theta(n^d) & a < b^d \\ \Theta(n^d \log n) & a = b^d \\ \Theta(n^{\log_b a}) & a > b^d \end{cases}$$

Aynı sonuçlar $O$ ve $\Omega$ için de düşünülebilir.

> **Ek bilgi (derste anlatılmadı):** Derste $f(n)$'in polinom ($n^d$) olduğu bu sade sürüm verildi. Master teoremi $T(n-1)$, $T(n-2)$ gibi "eksiltmeli" bağıntılara uygulanamaz; onlar backward substitution ile çözülür.

### 9.3 Örnekler

**Örnek 1:** $A(n) = 2A(n/2) + 1$.

- $a = 2$, $b = 2$; $f(n) = 1 = n^0$, yani $d = 0$.
- $a = 2 > b^d = 2^0 = 1$: üçüncü durum.
- $T(n) \in \Theta(n^{\log_2 2}) = \Theta(n)$.

**Örnek 2:** $T(n) = 3T(n/2) + n^2$ (ekrandan, 02:55:00).

- $a = 3$, $b = 2$, $d = 2$.
- $a = 3 < b^d = 2^2 = 4$: birinci durum.
- $T(n) \in \Theta(n^2)$.

**Soru:** Bir öğrenci bu örnekte $d$'nin nasıl bulunduğunu sordu. **Cevap:** $f(n) = n^d$ biçimindedir; $f(n) = n^2$ olduğundan $d = 2$'dir. $a$ özyinelemeli çağrı sayısı (3), $b$ her çağrıda girdinin bölündüğü sayıdır (2). Hoca, $f(n)$'i bir yerde "$b^d$ formatında" diye anlatmasının kafa karıştırdığını kabul etti ve doğrusunun "$n^d$ formatında" olduğunu söyledi.

**Örnek 3:** $T(n) = T(2n/3) + 1$ (ekrandan, 02:55:00).

- $a = 1$; $n/b = 2n/3$ olduğundan $b = 3/2$; $d = 0$.
- $a = 1 = (3/2)^0$: ikinci durum.
- $T(n) \in \Theta(n^0 \log n) = \Theta(\log n)$.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:19:54; ekrandan, 00:25:00): $f(n) = 10n + 30$ için $f(n) \in O(n)$ olduğunu tanımdan ispatlayın.

> **Çözüm:** $10n + 30 \le 10n + 30n = 40n$ ($n \ge 1$). $c = 40$, $n_0 = 1$ ile $10n + 30 \le c\,n$ sağlanır; dolayısıyla $10n + 30 \in O(n)$.

**Soru 2** (ekrandan, 00:35:00): $f(n) = n^2 + n$ için $f(n) \in O(n^3)$ mü, $f(n) \in O(n)$ mi?

> **Çözüm:** $n^2 + n \le 2n^3$ ($n \ge 1$) olduğundan $O(n^3)$'tür. $n^2 + n \le cn$ ise $n \le c - 1$ gerekir; $n$ sınırsız büyüdüğü için hiçbir sabit $c$ bunu sağlamaz, yani $n^2 + n \notin O(n)$.

**Soru 3** (ekrandan, 00:40:00): $5n^2 \in \Omega(n^2)$ mi? $5n^2 \in \Omega(n)$ mi?

> **Çözüm:** $(5 - c)n^2 \ge 0$ eşitsizliği $c = 1$, $n_0 = 1$ ile sağlanır: $5n^2 \in \Omega(n^2)$. $5n^2 \ge 3n$ ($n \ge 1$) olduğundan $5n^2 \in \Omega(n)$ da doğrudur.

**Soru 4** (ekrandan, 00:50:00): $f(n) = 2n + 5 \in \Theta(n)$ mi?

> **Çözüm:** $2n + 5 \le 7n$ ($n \ge 1$) ile $O(n)$; $2n + 5 \ge 2n$ ($n \ge 1$) ile $\Omega(n)$. İkisinden $f(n) \in \Theta(n)$.

**Soru 5** (derste sözlü, 01:20:01): $2^n$ ile $n!$'den hangisi daha hızlı büyür? Limitle ya da tanımla gösterin.

> **Çözüm (derste verilmedi):** $\frac{2^n}{n!} = \frac{2}{1}\cdot\frac{2}{2}\cdot\frac{2}{3}\cdots\frac{2}{n} \le 2 \cdot \left(\frac{2}{3}\right)^{n-2}$ ($n \ge 3$), bu da $n \to \infty$ iken 0'a gider. Limit 0 olduğundan $2^n \in O(n!)$; $n!$ daha hızlı büyür. Tanımla: $n \ge 4$ için $2^n \le n!$, yani $c = 1$, $n_0 = 4$.

**Soru 6** (ekrandan, 03:05:00, quiz sorusu 1): Aşağıdaki algoritmanın çalışma zamanı fonksiyonu $T(n)$'i temel operasyona göre değil, bütün işlemlere göre belirleyin ve uygun asimptotik gösterimle ifade edin.

```c
void hesapla(int n)
{
    int sayac = 0;
    for (int i = n/2; i <= n; i++)
        for (int j = 1; j + n/2 <= n; j++)
            for (int k = 1; k <= n; k = k * 2)
                sayac++;
}
```

> **Çözüm (derste verilmedi):** Çift $n$ için dış döngü $\frac{n}{2} + 1$ kez, orta döngü $\frac{n}{2}$ kez, iç döngü ($k = 1, 2, 4, \dots \le n$) $\lfloor \log_2 n \rfloor + 1$ kez döner. `sayac++` sayısı $\left(\frac{n}{2}+1\right)\cdot\frac{n}{2}\cdot\left(\lfloor\log_2 n\rfloor + 1\right)$ olur (python ile $n = 8, 16, 100, 1000$ için sayaçla doğrulandı: 80, 360, 17850, 2505000). Döngü karşılaştırmaları, artırmalar ve $k = k \cdot 2$ atamaları da aynı mertebede ya da daha düşük mertebede sayıldığından, hangi birim maliyetler seçilirse seçilsin baskın terim $n^2 \log n$ mertebesindedir: $T(n) \in \Theta(n^2 \log n)$. Tam $T(n)$ ifadesi, her işleme verilen maliyete göre değişir.

**Soru 7** (ekrandan, 03:05:00, quiz sorusu 2): Verilen $T(n)$ fonksiyonlarını asimptotik gösterimlerle ifade edin; her gösterimin mümkün olup olmadığını kuralı kullanarak ispatlayın (örneğin $T(n) \in O(n)$ ya da $T(n) \notin \Omega(n)$).

- $T_1(n) = 8n^3 + 17n^2 + 111$ <!-- BELİRSİZ: üsler karede küçük; 8n³ + 17n² + 111 olarak okundu. -->
- $T_2(n) = 3n\log n + n^2 \log n$

> **Çözüm (derste verilmedi):** $T_1$: $n \ge 1$ için $8n^3 + 17n^2 + 111 \le (8 + 17 + 111)n^3 = 136n^3$, yani $c = 136$, $n_0 = 1$ ile $O(n^3)$; $8n^3 + 17n^2 + 111 \ge 8n^3$ ile $\Omega(n^3)$; dolayısıyla $\Theta(n^3)$. $T_1 \notin O(n^2)$, çünkü $8n^3 \le cn^2$ için $n \le c/8$ gerekir. $T_2$: $n \ge 2$ için $3n\log n \le 3n^2\log n$ olduğundan $T_2 \le 4n^2\log n$ ($c = 4$), ve $T_2 \ge n^2\log n$ ($c = 1$); dolayısıyla $T_2 \in \Theta(n^2 \log n)$.

**Soru 8** (ekrandan, 03:05:00, quiz sorusu 3): Verilen yineleme bağıntılarını backward substitution ile ve uygunsa Master teoremiyle ayrı ayrı çözüp sonuçları karşılaştırın; asimptotik gösterimle ifade edin. Bütün durumlar için $T(0) = 1$ alınız.

- $T_1(n) = T_1(n/2) + n^2$
- $T_2(n) = 3T_2(2n/5) + 2$
- $T_3(n) = T_3(n-2) + 1$

> **Çözüm (derste verilmedi):** $T_1$: Master teoremiyle $a = 1$, $b = 2$, $d = 2$; $1 < 4$ olduğundan $\Theta(n^2)$. Backward substitution ile $T_1(n) = n^2\left(1 + \frac{1}{4} + \frac{1}{16} + \dots\right) + \text{sabit} \le \frac{4}{3}n^2 + \text{sabit}$, yani $\Theta(n^2)$; sonuçlar uyumludur. $T_2$: $a = 3$, $b = 5/2$, $d = 0$; $3 > 1$ olduğundan $\Theta(n^{\log_{5/2} 3}) \approx \Theta(n^{1.199})$. Backward substitution ile $T_2(n) = 3^i\,T_2\!\left((2/5)^i n\right) + 2(3^{i-1} + \dots + 1)$; $i = \log_{5/2} n$ alınınca $3^{\log_{5/2} n} = n^{\log_{5/2} 3}$ baskın terim olur. $T_3$: Master teoremi uygulanmaz (bölme değil eksiltme var). $T_3(n) = T_3(n - 2i) + i$; çift $n$ için $i = n/2$ alınınca $T_3(n) = T_3(0) + n/2 = n/2 + 1 \in \Theta(n)$.

## Dersin Toparlaması

Bu derste önce asimptotik notasyonların tanımları ($O$, $\Omega$, $\Theta$) tekrar edildi ve her biri için $c$, $n_0$ şahit ikilisiyle ispat örnekleri çözüldü. Doğru ispatın, bulunan ikilinin $n_0$'dan sonraki bütün $n$ değerlerinde sağlanmasını gerektirdiği vurgulandı. Ardından sadeleştirme kuralları, büyüme sırası ve iki fonksiyonu limitle karşılaştırma yöntemi verildi. Analizde gerekecek logaritma, kombinatorik, toplam ve yuvarlama formülleri hatırlatıldı.

İkinci bölümde iteratif algoritmaların analizi temel operasyon üzerinden yapıldı: MaxElement ve unique elements örneklerinde temel operasyon kesin sayıda yürütüldüğü için üç durum eşit çıktı; sıralı arama ve Insertion Sort'ta ise best, worst ve average case ayrı ayrı incelendi. Son bölümde özyinelemeli algoritmalar için yineleme bağıntısı kurma, backward ve forward substitution ile çözme ve Master teoremi işlendi. Hoca bir sonraki derste böl ve fethet (divide and conquer) konusuna başlanacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
