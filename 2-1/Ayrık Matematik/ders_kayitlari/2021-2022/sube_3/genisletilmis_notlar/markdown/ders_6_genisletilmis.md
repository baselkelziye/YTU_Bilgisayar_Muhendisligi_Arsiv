# Ders 6 Genişletilmiş Notu: Asimptotik Notasyonlar, Algoritma Analizi ve Rekürans Bağıntılarının Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Asimptotik Notasyonlara Neden İhtiyaç Var?
- 2. Büyük-O (Big-O) Gösterimi
- 3. Temel Karmaşıklık Sınıfları ve Büyüme Sırası
- 4. Büyük-Omega ve Büyük-Theta Gösterimleri
- 5. Farklı Problemlerde Girdi Boyutu ve Parçalı Algoritmalar
- 6. Limit Yöntemiyle Büyüme Hızı Karşılaştırma
- 7. Tümevarımla Büyüklük İspatı
- 8. İteratif Algoritmaların Analizi: Insertion Sort ve Selection Sort
- 9. Öz Yinelemeli Algoritmaların Analizi
- 10. Forward ve Backward Substitution
- 11. Özyineleme Ağacı Yöntemi
- 12. Master Teoremi
- 13. Rekürans Bağıntılarının Sınıflandırılması
- 14. Karakteristik Denklem Yöntemi
- 15. Homojen Olmayan Bağıntılar ve Özel Çözüm
- 16. Sayı Dizisinden Rekürans Bağıntısı Kurma
- 17. Problemlerin Karmaşıklığı: P, NP, NP-Tam, NP-Zor
- Örnek Sorular
- Dersin Toparlaması

## 1. Asimptotik Notasyonlara Neden İhtiyaç Var?

Ders, bir önceki derste kalınan asimptotik notasyonlardan devam etti. Bir algoritmanın çalışmasını incelediğimizde, temel işlemin kaç kez yapıldığını $n$'e bağlı bir fonksiyon olarak buluruz; örneğin $T(n) = n^2 + 5n$ gibi. Bu fonksiyonu olabildiğince sade biçimde yazmak ve algoritmanın çalışmasının **alt sınırını, üst sınırını ya da sıkı (ortalama) sınırını** görmek için asimptotik notasyonlar kullanılır.

İki algoritma belli bir $n$ değerine kadar karşılaştırıldığında biri daha iyi görünebilir, ama $n$ büyüdükçe öbürü daha iyi çıkabilir. Asimptotik notasyonlar algoritmalara "daha genelden bakmanın" yoludur. Temel olarak üç gösterim kullanılır: Büyük-O, Büyük-Omega ve Büyük-Theta. Hoca bunların yanında küçük-o, küçük-omega ve tilda gösterimlerinin de olduğunu, ama bu derste bunlara girilmeyeceğini söyledi.

## 2. Büyük-O (Big-O) Gösterimi

### 2.1 Tanım

Big-O görünce akla **asimptotik üst sınır (upper bound)** gelmelidir: "Benim algoritmam olsa olsa bu kadar sürer." Slayttaki tanım (ekrandan, 00:15:00):

$f$ ve $g$, tamsayı kümesinden ya da reel sayı kümesinden reel sayılara tanımlanmış olsun ($\mathbb{Z}^+ \to \mathbb{R}$). Eğer $x>k$ olduğunda

$$|f(x)| \le C\,|g(x)|$$

oluyorsa ve bu eşitsizliği sağlayan $C$ ve $k$ gibi sabit sayılar varsa $f(x) = O(g(x))$ olur.

Hoca tanımın bir mantık ifadesi olduğunu belirtti. İlk şart $x > k$'dır: $n$'in küçük değerlerinde iki algoritmanın birbirine üstünlüğü çok önemli değildir; belli bir $k$ noktasından sonraki **bütün** $x$ değerleri için $f(x) \le C\,g(x)$ sağlanmalıdır. Bu yüzden $g$, algoritmamızı **üstten baskılayan** bir fonksiyon gibi düşünülür.

### 2.2 İlk örnek: $4n^2+5n = O(n^2)$

Hoca tahtaya $4n^2+5n$ yazıp bunun $O(n^2)$ olarak yazılıp yazılamayacağını sordu. $C=9$ seçilirse $4n^2 + 5n \le 9n^2$ olur mu? İki taraftan $4n^2$ sadeleşince $5n \le 5n^2$ kalır; $n$ pozitif olduğu için bu her zaman sağlanır. Böyle bir $C$ bulunduğu için $4n^2+5n$ yerine daha basit olan $O(n^2)$ yazılabilir.

Ters yönde, bu fonksiyon hiçbir zaman $O(n)$ biçiminde yazılamaz: $n$'i hangi sabitle çarparsak çarpalım, belli bir $k$ noktasından sonraki bütün değerler için $4n^2+5n$'i geçemez.

### 2.3 Slayt örneği: $x^2+2x+1 = O(x^2)$

Slayttaki örnek (ekrandan, 00:20:00): $f(x) = x^2+2x+1$'in $O(x^2)$ olduğunu gösterin.

- $x>1$ iken $x < x^2$ ve $1 < x^2$'dir. Hoca, eleman sayılarının negatif olmadığını ($0, 1, 2, 3, \dots$), bu yüzden bu kabulün rahatça yapılabildiğini söyledi.
- Her terim $x^2$ ile üstten sınırlanır ("her terimi $x^2$'ye tamamladık"):
  $$0 \le x^2+2x+1 \le x^2+2x^2+x^2 = 4x^2$$
- Böylece $C=4$, $k=1$ tanık (witness) olarak alınabilir ve $f(x)$, $O(x^2)$'dir.

Alternatif çözüm: $x>2$ iken $2x \le x^2$ ve $1<x^2$ olduğundan
$$0 \le x^2+2x+1 \le x^2+x^2+x^2 = 3x^2.$$
Bu kez $C=3$, $k=2$ tanık olur. Hoca, eşitsizliği haklı çıkaran **bir tane** tanık çifti bulmanın yeterli olduğunu, bulunamazsa fonksiyonun o sınıfta olmadığını söyledi.

### 2.4 Kısa yol

Bir fonksiyonun Big-O karşılığını en kısa yoldan bulmak için **en yüksek dereceli terim alınır, diğerleri atılır; en yüksek dereceli terimin önünde sabit bir katsayı varsa o da atılır.** Bu örnekte zaten katsayı 1'dir, sonuç $x^2$'dir.

### 2.5 Grafik yorum

Grafikte $f(x)$ algoritmamız, $C\cdot g(x)$ de onu sınırlayan eğridir. Öyle bir $k$ noktası vardır ki bu noktadan öncesi küçük girdiler olduğu için önemli değildir. $k$'dan sonra $f(x)$ hep $C\,g(x)$'in altında kalıyorsa $f(x)=O(g(x))$ denir (ekrandan, 00:15:00; tahtadaki çizimde $f(x)$ eğrisi $k$ noktasından sonra üstteki eğrinin altında kalıyor).

### 2.6 Sıralı arama örneği

Sıralı arama (sequential search) algoritmasında temel işlem, dizinin $i$. elemanının aranan $K$ değerine eşit olup olmadığının kontrolüdür.

- **En iyi durum:** Aranan eleman ilk sırada ise döngü hiç dönmeden çıkılır: 1 karşılaştırma, $O(1)$.
- **En kötü durum:** $n$ kez arama yapılır ve eleman bulunmaz ya da en sonda bulunur: $O(n)$.
- **Ortalama durum:** Eleman arada bir yerde bulunur; slayttaki değer yaklaşık $(n+1)/2$'dir. Sabitler atılınca bu da $O(n)$ olur.

Hoca $O(1)$ ile $O(n)$'in farklı şeyler olduğunu ayrıca vurguladı.

## 3. Temel Karmaşıklık Sınıfları ve Büyüme Sırası

### 3.1 Temel sınıflar ve örnekler

Big-O gösteriminde en sık kullanılan fonksiyonlar $O(1)$, $O(\log n)$, $O(n)$, $O(n\log n)$, $O(n^2)$, $O(n^3)$, $O(2^n)$ ve $O(n!)$'dir. Hoca her sınıf için bir örnek verdi:

| Sınıf | Ad | Örnek |
|---|---|---|
| $O(1)$ | sabit zaman | bağlı listenin (linked list) başına eleman ekleme |
| $O(\log n)$ | logaritmik | ikili arama ağacında (binary search tree) arama |
| $O(n)$ | doğrusal | sıralı olmayan dizide eleman arama (en kötü durum) |
| $O(n\log n)$ | doğrusal-logaritmik | Quick Sort |
| $O(n^2)$ | karesel | Bubble Sort, en kısa yol bulma |
| $O(n^3)$ | kübik | doğrusal denklemler, iki matrisin çarpımı |
| $O(2^n)$ | üstel | Hanoi kuleleri, parola deneme |

Bağlı listenin başına eleman eklemede yeni düğüm, eski baş düğümü gösterecek şekilde bağlanır ve baş işaretçisi yeni düğüme çevrilir; bu bir birimlik işlemdir.

Hoca üstel algoritmaların neden "korkunç" olduğunu parola örneğiyle anlattı: yalnız 0 ve 1'den oluşan 5 haneli kaç parola üretilebilir? $2^5 = 32$; az görünür. Ama hane sayısı 50 olunca $2^{50}$ çok büyük bir sayıdır.

### 3.2 Fonksiyonları büyüme hızına göre sıralama

Slayttaki soru (ekrandan, 00:25:00): Aşağıdaki fonksiyonları, her biri listede kendinden sonra gelenin Big-O'su olacak şekilde sıralayın.

- $f_1(n) = (1.5)^n$
- $f_2(n) = 8n^3+17n^2+111$
- $f_3(n) = (\log n)^2$
- $f_4(n) = 2^n$
- $f_5(n) = \log(\log n)$
- $f_6(n) = n^2(\log n)^3$
- $f_7(n) = 2^n(n^2+1)$
- $f_8(n) = n^3+n(\log n)^2$
- $f_9(n) = 10000$
- $f_{10}(n) = n!$

Hoca öğrencilerle birlikte sıraladı. En küçük $f_9$'dur, çünkü $n$'e bağlı bir büyüme yoktur; sabit zamandır. Sonra $f_5=\log\log n$ gelir; $\log\log n$, $\log n$'den küçüktür (hoca interpolation search'ü bu tür bir örnek olarak andı). Sonra $(\log n)^2$; $\log n$'in iki kez çarpılmış hâlidir. Ardından $n^2(\log n)^3$ gelir. Sonra $n^3$'lü iki fonksiyon ($f_8$ ve $f_2$), ardından üstel $1.5^n$, sonra $2^n$, sonra $2^n(n^2+1)$ ve en sonda $n!$. Çözüm bölümünde ayrıca verilmiştir.

## 4. Büyük-Omega ve Büyük-Theta Gösterimleri

### 4.1 Büyük-Omega: alt sınır

Büyük-Omega, Big-O'nun tam tersidir. $C$ ve $k$ sabitleri için her şey aynıdır, yalnız eşitsizlik yön değiştirir:

$$|f(x)| \ge C\,|g(x)| \quad (x>k).$$

Bu bize **asimptotik alt sınırı (lower bound)** verir: "Algoritmam en iyi ihtimalle bu karmaşıklıkta çalışır."

Hoca öğrencilere sordu: Bir diziyi sıralamak için en iyi ihtimalle kaç adım gerekir? Bir adımda dizinin sıralı olup olmadığı bile kontrol edilemez; en azından bütün elemanlara bir kez bakmak gerekir. Bu yüzden sıralamanın alt sınırı $n$'dir. Sıralı aramada ise alt sınır 1'dir.

### 4.2 Omega örneği: $8x^3+5x^2+7$

Slayttaki örnek (ekrandan, 00:30:00): $f(x) = 8x^3+5x^2+7$'nin $\Omega(g(x))$, $g(x)=x^3$ olduğunu gösterin.

Çözüm: bütün pozitif reel $x$ için $f(x) = 8x^3+5x^2+7 \ge 8x^3$. Yani $C=8$ ile eşitsizlik sağlanır ve $f(x) \in \Omega(x^3)$'tür.

Slayttaki ek soru: $g(x)=x^3$ aynı zamanda $O(8x^3+5x^2+7)$ midir? Hoca bu fonksiyonun aynı zamanda $O(x^3)$ olarak da yazılabileceğini gösterdi: bütün terimler $x^3$'lü terim gibi düşünülürse $8+5+7=20$ gelir ve $x\ge1$ için $8x^3+5x^2+7 \le 20x^3$ olur (tahtada $C=20$ yazılı).

### 4.3 Üst ve alt sınırı eşit olan algoritmalar

Hoca, üst sınırı alt sınırına eşit olan bir algoritma örneği istedi. Bubble Sort'ta elemanlara ikişer ikişer bakılır; bir tur boyunca hiçbir değişiklik olmazsa sıralama bitirilebilir. Bu yüzden Bubble Sort'ta Big-O $n^2$ iken Big-Omega $n$'dir: dizi zaten sıralıysa bir tur yeter.

Selection Sort'ta ise her seferinde kalan elemanlar arasında en küçüğü aranıp başa getirilir. En iyi ihtimalle de, en kötü ihtimalle de bu arama yapılır; karmaşıklık her iki durumda $n^2$'dir. Bu yüzden Selection Sort'un Big-O'su ile Big-Omega'sı birbirine eşittir. (Hoca önce Bubble Sort dedi, sonra Selection Sort diye düzeltti.)

### 4.4 Gereğinden büyük üst sınır

Hoca sordu: $n^2+8$ algoritmasını Big-O ile göstermek için en az ne yazmak gerekir? Kurala göre sabitler ve düşük dereceli terimler atılır: $n^2$. Peki bu algoritmaya $O(n^3)$ denebilir mi?

Big-O üstten sınırlayan bir gösterimdir. $n^2$ için bulunan $C$ sabiti $n^3$ ile de eşitsizliği sağlar, çünkü $n^3$, $n^2$'yi zaten üstten sınırlar. Yani matematiksel olarak $n^2$ olan bir algoritma $O(n^3)$, $O(2^n)$, $O(n^n)$ da yazılabilir. Ama bu "fazla mütevazı" olur: algoritmayı olduğundan kötü göstermiş oluruz.

### 4.5 Büyük-Theta: sıkı sınır

Big-Theta, Big-O ile Big-Omega'nın kesişimidir. $x>k$ için

$$C_1\,|g(x)| \le |f(x)| \le C_2\,|g(x)|$$

sağlayan iki pozitif reel $C_1$, $C_2$ sabiti bulunabiliyorsa $f(x)=\Theta(g(x))$ yazılır. Buna **sıkı sınır (tight bound)** denir: algoritmanın çalışmasını hem alttan hem üstten kontrol ederek daha doğru ifade eder.

Örnek: $3x^2 + 8x\log x$, $\Theta(x^2)$ midir?

- Üst sınır: $x\log x \le x^2$ olduğundan $8x\log x \le 8x^2$, toplam $3x^2+8x\log x \le 11x^2$. Üstten sınırlayan sabit $11$.
- Alt sınır: $3x^2 + 8x\log x \ge 3x^2$. Alttan sınırlayan sabit $3$.

Hem üst hem alt sınır $x^2$'li olduğu için bu fonksiyon $\Theta(x^2)$'dir; "kesin olarak $x^2$ karmaşıklıkla çalışıyor" denebilir.

Ayrıca $f(x) \in \Theta(g(x))$ ise $g(x) \in \Theta(f(x))$'tir. Örneğin $3x^2 \in \Theta(x^2)$ ise $x^2 \in \Theta(3x^2)$ da yazılabilir; ikisi birbirini alttan ve üstten sınırlar.

Polinom biçimindeki bir karmaşıklıkta Big-Theta ve Big-Omega için de aynı kural geçerlidir: en yüksek dereceli terim alınır, diğer terimler atılır; en yüksek dereceli terimin önünde **sabit** bir sayı varsa o da silinir. Hoca, katsayı $x$ gibi bir değişken olursa atılamayacağına dikkat çekti.

### 4.6 Üç gösterimin anlamı

- $f(n) = O(g(n))$: $f$, $g$'den daha hızlı büyüyemez; onun altında kalır.
- $f(n) = \Theta(g(n))$: $f$ ile $g$ yaklaşık aynı hızda büyür.
- $f(n) = \Omega(g(n))$: $f$, $g$'nin altına düşemez.

Hoca bunu sıralama örneğiyle bağladı: sıralama algoritmasında en az $n$ kontrol yapmak gerektiği için alt sınır $n$'dir; arama algoritmasında alt sınır 1'dir. Grafiklerde her üç gösterimde de belli bir $n_0$ öncesi önemsenmez; Theta'da algoritma iki eğri arasında "gidip gelir".

## 5. Farklı Problemlerde Girdi Boyutu ve Parçalı Algoritmalar

### 5.1 Girdi boyutu her zaman $n$ değildir

Dizilerde girdi boyutu eleman sayısı $n$'dir. Graflarda ise boyut düğüm (vertex, $V$) ve kenar (edge, $E$) sayılarıyla ölçülür. Slayttaki arama algoritmaları tablosu (ekrandan, 00:35:00):

| Algoritma | Veri yapısı | Ortalama zaman | En kötü zaman | En kötü bellek |
|---|---|---|---|---|
| Derinlik öncelikli arama (DFS) | $V$ düğümlü, $E$ kenarlı graf | — | $O(\lvert E\rvert+\lvert V\rvert)$ | $O(\lvert V\rvert)$ |
| Genişlik öncelikli arama (BFS) | $V$ düğümlü, $E$ kenarlı graf | — | $O(\lvert E\rvert+\lvert V\rvert)$ | $O(\lvert V\rvert)$ |
| İkili arama (binary search) | $n$ elemanlı sıralı dizi | $O(\log n)$ | $O(\log n)$ | $O(1)$ |
| Doğrusal arama (brute force) | dizi | $O(n)$ | $O(n)$ | $O(1)$ |
| Dijkstra en kısa yol (min-heap öncelik kuyruğu) | graf | $O((\lvert V\rvert+\lvert E\rvert)\log\lvert V\rvert)$ | $O((\lvert V\rvert+\lvert E\rvert)\log\lvert V\rvert)$ | $O(\lvert V\rvert)$ |
| Dijkstra en kısa yol (sırasız dizi öncelik kuyruğu) | graf | $O(\lvert V\rvert^2)$ | $O(\lvert V\rvert^2)$ | $O(\lvert V\rvert)$ |
| Bellman-Ford en kısa yol | graf | $O(\lvert V\rvert\,\lvert E\rvert)$ | $O(\lvert V\rvert\,\lvert E\rvert)$ | $O(\lvert V\rvert)$ |

Hoca, min-heap kullanan Dijkstra'nın $O((V+E)\log V)$ karmaşıklığının $n\log n$'e benzediğini söyledi. $V$ ile $E$ sayıca birbirine yakın alınırsa Bellman-Ford'un $O(V\cdot E)$'si $n^2$'ye yakın bir şey olur. Hoca bu algoritmaların ileride anlatılacağını belirtti. Benzer tablolarda sıralama algoritmalarının ve heap türlerinin (binary heap, binomial heap, Fibonacci heap) zaman ve bellek (space complexity) karmaşıklıklarının da $n$'e bağlı verildiğini gösterdi; örneğin insertion sort'un bellek karmaşıklığı $O(1)$'dir.

### 5.2 Birden çok parçadan oluşan algoritma

Bir program birden fazla alt programdan oluşuyorsa, örneğin bir parçası $n^2$'lik, bir parçası $n^3$'lük, bir parçası $n^2$'lik, bir parçası $n\log n$'lik ise, algoritmanın Big-O'su **en büyük olanıdır**: $O(n^3)$. Algoritmayı en kötü hâle götüren parça belirleyicidir. Slayttaki maksimum örneklerinde $\max(O(\log n), O(n)) = O(n)$; $c<d$ için $n^c$ ile $n^d$'den $n^d$; $2^n$ her polinomdan büyüktür.

### 5.3 Çarpım ve toplam içeren ifadeler

Hoca $3n$ ile $\log n!$ içeren bir ifadeyi parça parça ele aldı. $\log n!$ için $n! \le n^n$ düşünülürse $\log n! \le \log n^n = n\log n$, yani $O(n\log n)$ bulunur. $3n$, $O(n)$'dir. İkisinin çarpımı $O(n)\cdot O(n\log n) = O(n^2\log n)$ olur. İfadenin öbür parçası da $n^2\log n$'lik olduğundan sonuç $O(n^2\log n)$'dir.

<!-- BELİRSİZ: 00:38:02 civarındaki ifadenin tam hâli karelerde görünmüyor; altyazıda yalnız "3n, log n!" ve ikinci parçanın "n kare log n'lik" olduğu geçiyor. -->

Hoca, hesaplamaların genelde sadeleştirme ve yuvarlama üzerine kurulduğunu, çok fazla matematiksel ayrıntıyla uğraşmaya gerek olmadığını söyledi.

Slayttaki ikinci soru (ekrandan, 00:40:00): $F(x) = (x+1)\log(x^2+1) + 3x^2$ için Big-O nedir?

- $(x+1)$, $O(x)$'tir.
- $\log(x^2+1)$'de $+1$ atılırsa $\log x^2 = 2\log x$ kalır; 2 de sabit olduğu için atılır: $O(\log x)$.
- İlk parça: $O(x)\cdot O(\log x) = O(x\log x)$.
- İkinci parça: $3x^2 \to O(x^2)$.
- $O(x^2)$ daha büyük olduğundan $F(x) = O(x^2)$.

## 6. Limit Yöntemiyle Büyüme Hızı Karşılaştırma

### 6.1 Kural

İki algoritmayı karşılaştırmanın bir diğer yolu, oranlarının limitini sonsuzda almaktır. Slayttaki kural (ekrandan, 00:45:00):

$$\lim_{n\to\infty}\frac{T(n)}{g(n)} = \begin{cases} 0 & T(n) \text{ daha yavaş büyür},\; T(n)\in O(g(n)) \\ c>0 & \text{aynı hızda büyür},\; T(n)\in\Theta(g(n)) \\ \infty & T(n) \text{ daha hızlı büyür},\; T(n)\in\Omega(g(n)) \end{cases}$$

Sonucun 0 çıkması, payın paydaya göre küçük kaldığını gösterir ("sayı bölü sonsuz sıfır"). Sonsuz çıkması payın büyük olduğunu gösterir. Limitte belirsizlik çıkarsa **L'Hôpital kuralı** uygulanır: $\lim f(n) = \lim g(n) = \infty$ ve türevler varsa $\lim \frac{f(n)}{g(n)} = \lim \frac{f'(n)}{g'(n)}$.

### 6.2 $2^n$ ile $n!$

Slayttaki örnek: $2^n$ ile $n!$. $n!$'in doğrudan türevi yoktur, ama yaklaşık değeri **Stirling formülü** ile bulunabilir (ekrandan, 00:45:00):

$$n! \approx \sqrt{2\pi n}\left(\frac{n}{e}\right)^n$$

$n!$ daha hızlı büyür. Bu yüzden $2^n \in O(n!)$ denebilir. Ama aynı zamanda $2^n \in O(2^n)$ de doğrudur ve daha sıkıdır.

**Soru:** $2^n$ ile $n!$ karşılaştırmasını tekrar anlatabilir misiniz? **Cevap:** $2^n = 2\cdot2\cdot2\cdots2$, $n! = 1\cdot2\cdot3\cdot4\cdots n$. Belli bir noktadan sonra $n!$'teki çarpanların hepsi 2'den büyüktür, bu yüzden başta $n!$ daha küçük olsa da sonra hep daha büyük kalır; asimptotik karşılaştırmada önemli olan bu sonraki kısımdır. Limitle yapılırsa $\lim 2^n/n!$'de belirsizlik çıkar; türev alınarak belirsizlik giderilir ve $2^n$'in $n!$'ten her zaman küçük kaldığı görülür. Bu yüzden $2^n \in O(n!)$; ama $2^n$'lik bir algoritmayı $n!$ ile ifade etmeye gerek yoktur, $O(2^n)$ yeterlidir.

### 6.3 $4x^3+3x^2$ ile $x^4$

Hoca, sınavda "limitle kanıtlayın" ya da "Big-O kuralıyla ($C$ sabiti bularak) kanıtlayın" diye sorulabileceğini söyledi.

$f(x) = 4x^3+3x^2$, $g(x)=x^4$:
$$\lim_{x\to\infty}\frac{4x^3+3x^2}{x^4} = \lim_{x\to\infty}\left(\frac{4}{x}+\frac{3}{x^2}\right) = 0+0 = 0.$$

Limit sıfır çıktığı için kurala göre $4x^3+3x^2 \in O(x^4)$'tür. Tanımla da gösterilebilir: $x\ge1$ için $4x^3+3x^2 \le 7x^4$; $C=7$ tanıktır.

> **Ders sonrası not:** Hoca limit sonucunu söylerken "elemanıdır Big-O $x^3$" dedi. Limitte payda $x^4$ olduğu için bu limitin gösterdiği $4x^3+3x^2 \in O(x^4)$'tür. Fonksiyonun $O(x^3)$ olduğu da doğrudur, ama bu limitten değil, $\lim (4x^3+3x^2)/x^3 = 4$ hesabından çıkar.

## 7. Tümevarımla Büyüklük İspatı

Hoca, ispat yöntemleri dersinde anlatılan tümevarımla bir büyüklük ilişkisi ispatladı. Slayttaki el yazısı örnek (ekrandan, 00:50:00): $n>6$ ve $n$ bir tamsayı iken $3n < n!$ olduğunu ispatlayın.

1. **Başlangıç:** $n \in \{7, 8, 9, \dots\}$ kümesinden. $n=7$ için $3\cdot7 = 21 < 7! = 5040$; doğru.
2. **Kabul:** $n=k$ için $3k < k!$ doğru kabul edilir.
3. **Adım:** $n=k+1$ için $3(k+1) < (k+1)!$ gösterilmelidir.
   $$3k+3 < (k+1)\cdot k! = k\cdot k! + k!$$
   $3k < k!$ zaten kabul edildi. Geriye $3 < k\cdot k!$ olduğunu göstermek kalır. $k>6$ için $k\cdot k!$ çok büyüktür, bu yüzden doğrudur.

Sonuç: $3n < n!$. Bu yüzden $3n \in O(n!)$ denebilir. Hoca, $3n$ için $O(n^2)$, $O(n^3)$, $O(n!)$ da denebileceğini, ama en doğru ifadenin $O(n)$ olduğunu, daha büyüğünü söylemenin algoritmayı "kötülemek" anlamına geldiğini tekrarladı.

## 8. İteratif Algoritmaların Analizi: Insertion Sort ve Selection Sort

### 8.1 Genel adımlar

İteratif algoritmalarda:

1. Girdi boyutu (input size) belirlenir.
2. Temel operasyon belirlenir.
3. En iyi ve en kötü durum için $T(n)$ bulunur (örneğin $T_1(n)$ en iyi, $T_2(n)$ en kötü durum).
4. $T(n)$ asimptotik notasyonla en sade hâliyle gösterilir.

### 8.2 Insertion Sort

Insertion Sort'ta bir eleman alınır ve önündeki sıralı kısımda yerine yerleştirilir; yerleştirirken elemanlar kaydırılır (shift). Hoca bir dizi üzerinde adımları gösterdi: önce 7 ile 11 karşılaştırılır ve yer değiştirir; 15 zaten yerindedir, 11 ve 7 ile ayrıca karşılaştırılmasına gerek yoktur; 3'ün yeri bulunur ve en başa gelir; 16 yerinde kalır; 13 alınıp araya yerleştirilir.

<!-- BELİRSİZ: Insertion Sort örneğindeki dizinin başlangıç sırası karelerde görünmüyor; altyazıdan 7, 11, 15, 3, 16, 13 elemanlarının işlendiği anlaşılıyor. -->

Kodun satır satır analizinde dış döngü yaklaşık $n$ kez, döngü içindeki atamalar $n-1$ kez çalışır; iç döngü ise elemanın kaç kez kaydırılacağına bağlıdır. Hoca, toplamda $n^3$'lü bir terim çıkmayacağını, iç döngü dış döngüyle çarpıldığında en fazla $n^2$'li bir terim geleceğini söyledi.

Slayttaki sonuçlar (ekrandan, 00:55:00):

- **En iyi durum: $O(n)$.** Dizi başlangıçta sıralı ise yer değiştirme yapılmaz, yalnız kontrol yapılır.
- **Ortalama durum: $O(n^2)$.**
- **En kötü durum: $O(n^2)$.** Dizi başlangıçta büyükten küçüğe sıralı ise her eleman için **en başa kadar** karşılaştırma yapılır. Tahtadaki örnek: $8, 7, 6, 5, 4$. 7 alınıp başa konur, 6 alınıp başa konur, 5 alınıp başa konur, 4 alınıp başa konur.

Hoca ortalama durumun uzun ispatlarının bu dersin kapsamında olmadığını, algoritma analizi dersinde anlatılacağını söyledi.

**Soru (hocanın sorusu):** En iyi durum için $O(n)$ yanında $\Theta(n)$ ve $\Omega(n)$ da denebilir mi? **Cevap:** Evet. Her durumda en az $n$ kontrol yapmak gerektiği için $\Omega(n)$; başka kontrol yapılmadığı için $O(n)$. İkisi birden sağlandığı için $\Theta(n)$ otomatik olarak doğrudur. En kötü durumda genelde $O(n^2)$ ve $\Theta(n^2)$ söylenebilir; Big-Omega için elemanların dağılımına bakmak gerektiğinden çok şey denemez.

### 8.3 Selection Sort

Selection Sort her seferinde kalan elemanlar arasından en küçüğü bulur ve dizinin başına getirir. Hoca örnekte en küçük eleman olan 14'ü bulup baştaki 17 ile yer değiştirdiğini, sonra kalan elemanlardan en küçüğünü (17) öne aldığını, sonra 18'i ve 33'ü yerleştirdiğini gösterdi.

Slayttaki kod (ekrandan, 01:00:00):

```c
void selection(int A[], int N)
{ int i, j, temp;
  for (j = 0; j < N-1; j++)
  { int min_idx = j;
    for (i = j+1; i < N; i++)
      if (A[i] < A[min_idx])
        min_idx = i;
    temp = A[min_idx];
    A[min_idx] = A[j];
    A[j] = temp;
  }
}
```

Dış döngü $N-1$ kez, iç döngü $N-1-j$ kez çalışır (iç döngünün tekrar sayısı $j$'ye bağlıdır). Temel işlem `if (A[i] < A[min_idx])` karşılaştırmasıdır; atama ve yer değiştirme her zaman yapılmadığı için sayılmaz.

Toplam karşılaştırma sayısı:
$$T(N) = \sum_{j=0}^{N-2}\sum_{i=j+1}^{N-1} 1 = \sum_{j=0}^{N-2}(N-1-j).$$

İç toplamda terim sayısı "son terim − ilk terim + 1" ile bulunur: $(N-1)-(j+1)+1 = N-1-j$. Dış toplam açılırsa $(N-1)$ sabit terimi $N-1$ kez toplanır, $j$'ler ise $0$'dan $N-2$'ye kadar toplanır:
$$T(N) = (N-1)(N-1) - \frac{(N-2)(N-1)}{2} = \frac{2N^2-4N+2-(N^2-3N+2)}{2} = \frac{N^2-N}{2} = \frac{N(N-1)}{2}.$$

Bu, slayttaki $T(N) = (N-1)+(N-2)+\dots+2+1 = N(N-1)/2$ sonucuyla aynıdır. Slayttaki not: $N^2$ mertebesi, iç döngüde $N$ olduğu için değil, toplamdan gelir.

> **Ders sonrası not:** Hoca tahtada sadeleştirirken sonucu "kabaca $n^2-n-1$" olarak söyledi. Doğru sonuç $\frac{N^2-N}{2} = \frac{N(N-1)}{2}$'dir (python ile $N=2, 5, 10$ için karşılaştırma sayısı sayılarak doğrulandı). Big-O sonucu değişmez: $O(n^2)$.

Sonuç: sabit terim ve düşük dereceli terimler atılınca $O(n^2)$. Hoca, temel işlem karşılaştırma olduğu için bunun en kötü, ortalama ve en iyi durumda aynı olduğunu vurguladı: karşılaştırma her hâlükârda yapılır. Atama sayılsaydı durumlar ayrışırdı. Bu yüzden Selection Sort için $O(n^2)$, $\Omega(n^2)$ ve $\Theta(n^2)$ denebilir.

## 9. Öz Yinelemeli Algoritmaların Analizi

Ara sonrasında ders öz yinelemeli (recursive) algoritmalarla devam etti. Burada da iteratif algoritmalardaki gibi bir yol izlenir, ama algoritma bir yerden sonra kendini tekrar çağırdığı için iş biraz karışır. Slayttaki adımlar (ekrandan, 01:05:00):

- $n$ girdi boyutu (input size) belirlenir.
- Algoritmanın temel operasyonu (basic operation) saptanır.
- Temel işlemin gerçekleştirilme sayısının aynı boyuttaki farklı girişlere göre değişip değişmediği kontrol edilir; değişiyorsa en kötü, ortalama ve en iyi durum ayrı ayrı analiz edilir.
- Temel işlemin kaç kez yürütüldüğünü ifade eden, uygun bir başlangıç koşuluyla bir özyineleme bağıntısı (recurrence relation) kurulur.
- Bağıntı uygun bir yöntemle çözülür; elde edilen $n$'e bağlı $T(n)$ asimptotik notasyonla ifade edilir.

Faktöriyel örneğinde $n=0$ (ya da $n=1$) ise doğrudan 1 döndürülür, değilse $n\cdot f(n-1)$ hesaplanır. Bu iki durum ayrı analiz edilir; ilk durum başlangıç koşulunu verir.

Hoca, rekürans bağıntılarının aslında **fark denklemleri (difference equations)** olduğunu, diferansiyel denklemlere benzer biçimde çözüldüğünü söyledi. Çözüm sonucunda yine $n$'e bağlı bir $T(n)$ fonksiyonu elde edilir ve bu fonksiyon asimptotik notasyonla ifade edilir. Örneğin $T(n) = T(n-1)+1$ bağıntısında her adımda bir birimlik işlem yapılır ve bağıntı $n-1$, $n-2$, … diye başlangıç koşuluna kadar iner.

Slayttaki çözüm yöntemleri (ekrandan, 01:15:00):

- İleriye doğru yerine koyma (Forward Substitution)
- Geriye doğru yerine koyma (Backward Substitution)
- Özyineleme ağacı yöntemi (Recursive Tree Method)
- Master teoremi
- Karakteristik denklem yöntemi (2. ya da daha yüksek dereceden bağıntılar için)

Hoca, rekürans bağıntısını kurmanın asıl olarak algoritma analizi dersinin konusu olduğunu; bu derste genelde bağıntının verilip çözümünün istendiğini söyledi.

## 10. Forward ve Backward Substitution

### 10.1 İleriye doğru yerine koyma

Bağıntı $T(n) = T(n-1)+1$ ve başlangıç koşulu $T(1) = 2$ olsun. Başlangıç koşulundan ileriye doğru değerler hesaplanır:

$$T(1)=2,\quad T(2)=3,\quad T(3)=4,\quad T(4)=5,\ \dots$$

Her değer bir öncekinden bir fazladır. Buradan tahmin: $T(n) = n+1$. Tahmin kontrol edilir: $T(n-1)+1 = [(n-1)+1]+1 = n+1$ ve $T(1) = 1+1 = 2$; ikisi de tutar. Bu algoritma Big-O ile ifade edilirse sabit atılır ve $O(n)$ bulunur.

### 10.2 İlk $n$ sayının toplamı

Slayttaki örnek (ekrandan, 01:20:00): 1'den $n$'e kadar sayıların toplamı. Gauss'un yöntemiyle toplam iki kez, biri tersten yazılıp alt alta toplanır:

$$1+2+\dots+(n-1)+n = \frac{n(n+1)}{2}.$$

Rekürsif yazılırsa $f(n) = n + f(n-1)$, ilk değer $f(1)=1$. $f(5)$ hesaplanırken 5 kendi içinden 4'ü, 4 kendi içinden 3'ü çağırır ve 1'e kadar iner. Açılım $n + (n-1) + (n-2) + \dots$ biçimindedir; Big-O olarak $O(n^2)$'dir. Hoca bu noktada sınıfa tekrar hatırlattı: Big-O bulmak "tahmin edilecek bir şey değil"; en büyük dereceli terim alınır, düşük dereceli terimler ve katsayılar atılır. $\frac{n^2+n}{2}$'den $n^2$ kalır. "İspat edin" denirse $C$ katsayısı bulunmalıdır.

> **Ders sonrası not:** Tahtadaki açılımda sonuç $n\cdot k - \frac{k(k+1)}{2}$ biçiminde yazılıp $k=n$ konmuş ve $\frac{n^2+n}{2}$ bulunmuş; ara satırdaki işaret karışık görünüyor. Doğru sonuç slayttaki $\frac{n(n+1)}{2}$'dir. Big-O değişmez: $O(n^2)$.

### 10.3 Faktöriyel ve geriye doğru yerine koyma

Faktöriyel algoritmasında $n=0$ ise 1 döndürülür. Aksi hâlde bir karşılaştırma, bir çarpma ve bir çıkarma ($n-1$ hesabı) yapılır. Böylece bağıntı:

$$T(n) = T(n-1) + 3, \qquad T(0) = 1.$$

Backward substitution ifadeyi geriye doğru açar:

$$T(n) = T(n-1)+3 = T(n-2)+6 = T(n-3)+9 = \dots = T(n-k)+3k.$$

$k=n$ olduğunda $T(0)$'a ulaşılır:

$$T(n) = T(0) + 3n = 3n+1.$$

Big-O olarak $O(n)$. Hoca ileri yönde açmanın bir tahmin gerektirdiğini, bağıntı ve başlangıç koşulu verildiğinde geriye doğru açmanın daha rahat olduğunu söyledi.

### 10.4 İkinci backward substitution örneği

Slayttaki örnek (ekrandan, 01:25:00): $T(n) = T(n-1) + 1$, $T(1)=2$.

$$T(n) = [T(n-2)+1]+1 = [[T(n-3)+1]+1]+1 = \dots = T(n-k) + k \quad (k \text{ tane } 1).$$

$k = n-1$ alınırsa:

$$T(n) = T(n-(n-1)) + (n-1) = T(1) + (n-1) = 2 + (n-1) = n+1.$$

Kontrol: $T(n) = T(n-1)+1 = [(n-1)+1]+1 = n+1$ ve $T(1)=1+1=2$. Sonuç $O(n)$.

> **Ders sonrası not:** Hoca anlatırken çözümü bir an "$n-1$" diye söyledi; slayttaki ve hesaptaki sonuç $T(n) = n+1$'dir.

## 11. Özyineleme Ağacı Yöntemi

Özyineleme ağacı (recursive tree) yöntemi, bağıntıda $n-1$, $n-2$ gibi azaltma yerine $n/2$ gibi **bölme** olduğunda işe yarar. Böl ve yönet (divide and conquer) algoritmalarında, özellikle ikiye bölmeli olanlarda tercih edilir.

Örnek: $T(n) = 4T(n/2) + n$.

- Kökte $n$ birimlik maliyet vardır.
- Bir alt seviyede problem $n/2$ boyutlu alt problemlere bölünür. Hoca tahtada bu seviyenin toplam maliyetini $2n$ olarak gösterdi.
- Bir sonraki seviyede $n/4$'lük alt problemler oluşur; toplam maliyet $4n$ olur.
- Genel olarak $i$. seviyede toplam maliyet $2^i n$'dir.

Ağaç ne zamana kadar açılır? Alt problem boyutu 1 olana kadar: $n/2^k = 1$, yani $n = 2^k$. İki tarafın logaritması alınırsa $k = \log_2 n$ bulunur. Ağaç $\log_2 n$ derinliğe kadar açılır.

Seviye maliyetleri toplanır ve $n$ parantezine alınır:

$$n\,(1 + 2 + 4 + 8 + \dots + 2^{\log_2 n}).$$

Bu geometrik toplam yerine konunca sonuç $n^2$ mertebesinde çıkar; hoca sonucu "yaklaşık $n^2-n$" olarak söyledi ve algoritmanın $\Theta(n^2)$ olduğunu gösterdi. Yöntemin amacı ağacın ne kadar derinleşeceğini ve her derinlik seviyesinde ne kadar işlem yapıldığını bulmaktır. Hoca bu konuda farklı örneklerle alıştırma yapmayı önerdi.

> **Ders sonrası not:** $1+2+\dots+2^{\log_2 n} = 2^{\log_2 n+1}-1 = 2n-1$ olduğundan toplam $n(2n-1) = 2n^2-n$ olur ($T(1)=1$ için python ile $n=1,2,4,\dots,32$ değerlerinde doğrulandı). Hocanın söylediği "$n^2-n$" katsayı bakımından farklıdır, ama asimptotik sonuç aynıdır: $\Theta(n^2)$.

## 12. Master Teoremi

Bölmeli bağıntılar için daha genel bir yöntem Master teoremidir. Slayttaki biçim (ekrandan, 01:30:00):

$$T(n) = a\,T\!\left(\frac{n}{b}\right) + \Theta(n^d), \qquad T(1) = c,$$

$n = b^k$ ($k$ pozitif tamsayı), $a\ge1$, $b\ge2$, $c>0$, $d\ge0$ sabitler. Bu durumda:

$$T(n) \in \begin{cases} \Theta(n^d), & a < b^d \quad (\text{Durum 1}) \\ \Theta(n^d \log n), & a = b^d \quad (\text{Durum 2}) \\ \Theta(n^{\log_b a}), & a > b^d \quad (\text{Durum 3}) \end{cases}$$

Yapılacak iş $a$, $b$ ve $d$'yi tespit etmektir; sonra ağaç ya da başka yöntemlere gerek kalmadan sonuç bulunur. Hoca bölme işlemine ($n/b$), üs alma işlemine ($n^d$) ve çarpma işlemine ($a$) dikkat edilmesini söyledi. Bağıntıdaki "$=$" yerine "$\le$" ya da "$\ge$" konursa $O$ ya da $\Omega$ performansı elde edilir.

Örnek: $T(n) = 16\,T(n/4) + 5n^3$. Burada $a=16$, $b=4$, $d=3$. $b^d = 4^3 = 64 > 16$ olduğundan Durum 1 geçerlidir: $T(n) \in \Theta(n^3)$.

Hocanın sezgisel açıklaması: Master teoremi aslında özyineleme ağacının ne kadar derinleşeceğini bulur. Her çağrıda $n^d$ kadar işlem yapılır. $a<b^d$ ise ek bir derinlik etkisi yoktur ve sonuç $n^d$'dir. $a=b^d$ ise işlem $\log n$ derinlik boyunca tekrarlanır, sonuç $n^d\log n$ olur. $a>b^d$ ise $n^d$ terimi devre dışı kalır, ondan daha büyük bir maliyet gelir.

> **Ders sonrası not:** Hoca üçüncü durumu "üstel (eksponansiyel) bir sonuç" diye anlattı. Slayttaki sonuç $\Theta(n^{\log_b a})$'dır; bu polinom bir karmaşıklıktır, üstel değildir. Örneğin $T(n)=4T(n/2)+n$ için sonuç $\Theta(n^2)$'dir.

## 13. Rekürans Bağıntılarının Sınıflandırılması

### 13.1 Rekürans bağıntısı nedir?

Rekürans bağıntısı, ayrık zamanlı sistemlerde olduğu gibi, dizinin bir elemanını kendinden önceki elemanlar cinsinden veren bir bağıntıdır. Örneğin $a_n = 2a_{n-1} - 3$ bağıntısında $a_0$ verilirse yerine koyarak dizinin bütün elemanları bulunabilir. Hoca, iki önceki terime bağlı bir bağıntıda $a_0$ ve $a_1$ verildiğinde $a_2$, $a_3$, $a_4$ hesaplanarak $a_5 = 58$ değerine ulaşıldığını gösterdi.

<!-- BELİRSİZ: $a_5 = 58$ bulunan örneğin bağıntısı ve başlangıç değerleri karelerde görünmüyor. -->

Ayrık matematikteki hedef, rekürans bağıntılarının tiplerini ayırt etmek, tiplerine göre çözüp algoritma karmaşıklığını hesaplamak ya da sözel bir problemi rekürans bağıntısına çevirmektir. Çözümde $a_n$, $a_{n-1}$, $a_{n-2}$ gibi terimlerden kurtulup yalnız $n$'e bağlı bir ifade elde edilir.

### 13.2 Derece (order)

Derece, terimin içindeki kuvvetler değildir; bağıntının **kaç önceki terime** gittiğidir. $a_{n-1}$ içeren bağıntı birinci derecedir (yalnız bir önceki terimi bilmek gerekir); $a_{n-2}$ içeren ikinci, $a_{n-3}$ içeren üçüncü, $a_{n-4}$ içeren dördüncü derecedir.

### 13.3 Homojenlik

Slayttaki örnekler (ekrandan, 01:35:00):

| Bağıntı | Homojen mi? |
|---|---|
| $a_n = 3a_{n-1}$ | evet |
| $a_n = a_{n-1} - 2a_{n-2}$ | evet |
| $a_n = 3a_{n-1} + n\cdot a_{n-2} + 3^n$ | hayır ($3^n$ terimi) |
| $a_n = a_{n-1} + 2a_{n-3} - 4$ | hayır ($-4$ terimi) |
| $a_n = a_{n-2} + n^3 + n^2$ | hayır (polinom terimi) |

Homojenlik, bağıntının yalnız $a_n$'li terimlerden oluşup oluşmadığıdır. $a_n$'li terimlerin dışında ayrı bir terim varsa bağıntı homojen değildir.

### 13.4 Doğrusallık

$a_n$'li terimler birbiriyle çarpılıyorsa ya da $a_n$'li bir terimin kuvveti alınıyorsa bağıntı doğrusal (lineer) değildir. $n\cdot a_{n-2}$ gibi bir terimde $n$ sabit bir sayı gibi davranır, $a_n$'li bir terim değildir; bu yüzden doğrusallığı bozmaz. $n^2$ gibi terimler de doğrusallığı bozmaz. Ama iki $a_n$'li terimin çarpımı ya da $a_n$'li bir terimin küpü doğrusallığı bozar.

<!-- BELİRSİZ: Doğrusallık ve sabit katsayılılık slaytlarındaki bağıntıların tam listesi karelerde görünmüyor. -->

### 13.5 Sabit katsayılılık

$a_n$'li terimlerin katsayıları $n$'e bağlı değil de 3, 5 gibi sabitlerse bağıntı sabit katsayılıdır. $a_n$'li olmayan terimlerin ne olduğu bu sınıflandırmada önemli değildir. Örneğin $n\cdot a_{n-2}$ terimi sabit katsayılılığı bozar; $3^n\cdot a_{n-1}$ gibi bir çarpım da bozar.

Bu derste çözülecek olan, **sabit katsayılı (homojen) rekürans bağıntılarıdır**.

## 14. Karakteristik Denklem Yöntemi

### 14.1 Ne zaman kullanılır?

$T(n) = T(n-1)+3$ ya da $T(n) = T(n/2)+8$ gibi bağıntılarda Master teoremi, forward substitution ya da özyineleme ağacı işe yarar. Ama $T(n) = T(n-1) + T(n-2)$ gibi bir bağıntıda (Fibonacci sayılarının algoritmasını hatırlatır: önce $f(n-1)$, sonra $f(n-2)$ çağrılıp toplanır) iki terim olduğu için yerine koyma yöntemleri işe yaramaz. Bu tür sabit katsayılı bağıntılarda, genelde ikinci ya da daha yüksek dereceli olanlarda, **karakteristik kök yöntemi** kullanılır. Hoca bunun diferansiyel denklemlerden bilinen yönteme benzediğini söyledi.

Bağıntı homojense homojen çözümü bulmak yeter: $a_n = a_n^{(h)}$. Homojen değilse bir homojen çözüm, bir de özel çözüm bulunup toplanır: $a_n = a_n^{(h)} + a_n^{(\text{ö})}$ (ekrandan, 01:40:00). Hoca homojen olmayanları homojen hâle getirip çözmenin dersin ilgisi dışında olduğunu, isteyenin slaytlara bakabileceğini de söyledi.

### 14.2 Karakteristik denklemin kurulması: $a_n = 3a_{n-1} + 4a_{n-2}$

Slayttaki örnek (ekrandan, 01:40:00): sabit katsayılı homojen 2. dereceden bir rekürans bağıntısı.

- En düşük indisli terime 1, sonrakine $r$, $a_n$'e $r^2$ denir: $a_{n-2} \to 1$, $a_{n-1} \to r$, $a_n \to r^2$.
- Karakteristik denklem: $r^2 = 3r + 4$, yani $r^2 - 3r - 4 = 0$.
- Çarpanlara ayrılır: $(r-4)(r+1)=0$, kökler $r_1 = 4$, $r_2 = -1$.
- İki farklı kök olduğu için: $a_n = c_1\cdot 4^n + c_2\cdot(-1)^n$.

Bu bağıntı $4^n$ mertebesindedir; $c$ katsayıları başlangıç koşullarından bulunur.

### 14.3 Kök durumlarına göre çözüm biçimi

İkinci dereceden sabit katsayılı bağıntıda:

- $r_1 \ne r_2$ ise: $a_n = c_1 r_1^n + c_2 r_2^n$.
- $r_1 = r_2 = r$ ise: $a_n = c_1 r^n + c_2\, n\, r^n$ (aynı terim iki kez gelmesin diye ikinci terime $n$ çarpanı eklenir).

Üçüncü dereceden bağıntıda ($a_{n-1}$, $a_{n-2}$, $a_{n-3}$ içeren):

- Kökler farklıysa: $a_n = c_1 r_1^n + c_2 r_2^n + c_3 r_3^n$.
- Üç kök aynıysa: $a_n = c_1 r^n + c_2\, n\, r^n + c_3\, n^2 r^n$.
- İki kök aynı, biri farklıysa: farklı olan ayrı yazılır, aynı olan ikisine $n$ çarpanı eklenir.

Aynı mantık dördüncü dereceye de uyarlanır: farklı kökler doğrudan yazılır, tekrarlanan köklere $n$, $n^2$, … çarpanları eklenir.

### 14.4 Başlangıç koşullarıyla örnek: kökler 5 ve $-2$

Bağıntı homojen ve sabit katsayılıdır; karakteristik denklem $r^2 - 3r - 10 = 0$'dır (yani bağıntı $a_n = 3a_{n-1} + 10a_{n-2}$). $(r-5)(r+2) = 0$, kökler $r_1 = 5$, $r_2 = -2$.

$$a_n = c_1\cdot 5^n + c_2\cdot(-2)^n, \qquad a_0 = 5,\; a_1 = 8.$$

- $n=0$: $5 = c_1 + c_2$.
- $n=1$: $8 = 5c_1 - 2c_2$.
- İlk denklem 2 ile çarpılıp ikinciyle toplanınca $18 = 7c_1$, $c_1 = \frac{18}{7}$, $c_2 = \frac{17}{7}$.

$$a_n = \frac{18}{7}\cdot 5^n + \frac{17}{7}\cdot(-2)^n.$$

Hoca bunun Big-O karşılığını sordu: en yüksek "dereceli" terim $5^n$'dir, bu yüzden $O(5^n)$. (Python ile $c_1$, $c_2$ değerleri doğrulandı.)

### 14.5 Çakışık kök örneği

Slayttaki soru (ekrandan, 01:45:00): $a_n = -4a_{n-1} - 4a_{n-2}$, $a_0 = 3$, $a_1 = 5$ başlangıç koşullarıyla verilen rekürans bağıntısının çözümünü bulunuz.

- 1. adım: bağıntı sabit katsayılı ve homojendir, $a_n = a_n^{(h)}$.
- Karakteristik denklem: $r^2 = -4r - 4$, yani $r^2 + 4r + 4 = 0$, $(r+2)^2 = 0$.
- Çakışık kök: $r_1 = r_2 = -2$.
- Çözüm biçimi: $a_n = c_1(-2)^n + c_2\, n\,(-2)^n$.
- $n=0$: $a_0 = c_1 = 3$.
- $n=1$: $a_1 = -2c_1 - 2c_2 = 5 \Rightarrow -6 - 2c_2 = 5 \Rightarrow c_2 = -\frac{11}{2}$.

$$a_n = 3\cdot(-2)^n - \frac{11}{2}\, n\,(-2)^n.$$

Big-O cinsinden $n\cdot 2^n$ mertebesindedir. Hoca, algoritmalarda pek negatif tabanlı ifadeler çıkmadığını; bunun üstel bir fonksiyonla doğrusal bir fonksiyonun çarpımı olarak düşünülebileceğini söyledi. (Python ile $a_0$–$a_7$ değerleri bağıntıyla karşılaştırıldı.)

## 15. Homojen Olmayan Bağıntılar ve Özel Çözüm

Bağıntı sabit katsayılı ama homojen değilse, yani $a_n$'li terimlerin dışında bir terim varsa iş zorlaşır. Hoca hepsine bakılmayacağını söyledi. Ek terim sıfırıncı, birinci, ikinci, üçüncü dereceden bir **polinom** ise bir türlü, **üstel bir fonksiyon** ise başka türlü bir **özel çözüm** tahmini yapılır. Genel çözüm $a_n = a_n^{(h)} + a_n^{(\text{ö})}$'dir.

### 15.1 Sabit terimli örnek

Bağıntı $a_n = 2a_{n-1} + 3a_{n-2} + 5$, $a_0 = 4$, $a_1 = 10$ (karakteristik denklem $r^2 - 2r - 3 = 0$).

- Doğrusal mı? Evet; $a_n$'li terimler kendi aralarında çarpılmıyor ve kuvvetleri alınmıyor.
- Homojen kısım: $r^2-2r-3 = 0$, kökler $3$ ve $-1$: $a_n^{(h)} = c_1\cdot 3^n + c_2\cdot(-1)^n$.
- Özel çözüm: ek terim $5$ sabit olduğu için $a_n = a_{n-1} = a_{n-2} = A$ tahmini yapılır. Yerine konunca $A = 2A + 3A + 5$, yani $-4A = 5$, $A = -\frac{5}{4}$.
- Genel çözüm: $a_n = c_1\cdot 3^n + c_2\cdot(-1)^n - \frac{5}{4}$.
- Başlangıç koşulları: $c_1 + c_2 - \frac54 = 4$ ve $3c_1 - c_2 - \frac54 = 10$. Buradan $c_1 = \frac{33}{8}$, $c_2 = \frac{9}{8}$.

$$a_n = \frac{33}{8}\cdot 3^n + \frac{9}{8}\cdot(-1)^n - \frac{5}{4}.$$

Sonuç $O(3^n)$. Özel çözüm, başlangıç koşulları yerine konmadan önce bulunmalıdır; koşullar genel çözüme uygulanır. (Python ile $a_0$–$a_7$ doğrulandı.)

<!-- BELİRSİZ: Bu örneğin bağıntısı karelerde görünmüyor; $a_n = 2a_{n-1}+3a_{n-2}+5$ biçimi, altyazıdaki karakteristik denklem, kökler, $A=-5/4$ ve $c_1$, $c_2$ değerleriyle tutarlıdır. -->

### 15.2 Birinci dereceden polinom terimli örnek

Slayttaki örnek (ekrandan, 01:50:00): $a_n = a_{n-1} + 2a_{n-2} + 3n + 4$, $a_0 = 5$, $a_1 = 7$ başlangıç koşullarıyla verilen rekürans bağıntısını çözünüz.

- 1. adım: $a_n^{(g)} = a_n^{(h)} + a_n^{(\text{ö})}$.
- 2. adım (homojen kısım): $a_n = a_{n-1} + 2a_{n-2} \Rightarrow r^2 = r + 2$, $r^2 - r - 2 = 0$, $(r-2)(r+1) = 0$, kökler $2$ ve $-1$:
  $$a_n^{(h)} = c_1\cdot 2^n + c_2\cdot(-1)^n.$$
- 3. adım (özel çözüm): ek terim $3n+4$ birinci dereceden bir polinom olduğu için $a_n^{(\text{ö})} = An + B$ tahmini yapılır. Buna göre $a_{n-1} = An - A + B$, $a_{n-2} = An - 2A + B$. Yerine konunca:
  $$An + B = An - A + B + 2An - 4A + 2B + 3n + 4$$
  $$-2An + 5A - 2B = 3n + 4$$
  $n$'li terimler eşitlenince $-2A = 3$, $A = -\frac{3}{2}$ (ekrandan, 01:50:00). Sabit terimler eşitlenince $5A - 2B = 4$, buradan $B = -\frac{23}{4}$ (ara adım eklendi).
- Genel çözüm $a_n = c_1\cdot 2^n + c_2\cdot(-1)^n - \frac{3}{2}n - \frac{23}{4}$ olur; başlangıç koşulları yerine konunca $c_1 = \frac{25}{3}$, $c_2 = \frac{29}{12}$ bulunur (ara adım eklendi, python ile doğrulandı).

Hoca bu ayrıntıların dersle çok ilgili olmadığını söyleyip sonucu verdi: en yüksek terim $2^n$ olduğundan algoritma $O(2^n)$'dir.

<!-- BELİRSİZ: Hoca $B$ ve $c_1$, $c_2$ değerlerini sözlü olarak net vermedi ("3 bölü 2", "3 bölü 4" gibi parçalar geçiyor); $B$, $c_1$, $c_2$ yukarıda hesapla bulundu. -->

### 15.3 Üstel terimli örnek

Ek terim üstel bir fonksiyon ise (bu örnekte $5^n$'li bir terim) homojen kısım yine aynı biçimde çözülür, özel çözüm ise $A\cdot 5^n$ biçiminde tahmin edilir. $a_n$, $a_{n-1}$, $a_{n-2}$ yerine $A\cdot5^n$, $A\cdot5^{n-1}$, $A\cdot5^{n-2}$ konur; $5^n$ parantezine alınınca $A/5$ ve $A/25$'li terimler gelir ve katsayı $A = \frac{25}{24}$ bulunur. Özel çözümde $5^n$'li bir terim olduğu için en yüksek terim $5^n$'dir ve sonuç $O(5^n)$ olur. Hoca bu kısmın sınavda sorulmayacağını, yalnız nasıl çözüldüğü görülsün diye gösterdiğini söyledi.

<!-- BELİRSİZ: Üstel terimli örneğin bağıntısı ve başlangıç koşulları karelerde görünmüyor; altyazıda yalnız $A=25/24$ ve $O(5^n)$ sonucu net. -->

## 16. Sayı Dizisinden Rekürans Bağıntısı Kurma

Bir sayı dizisi verildiğinde ondan rekürans bağıntısı üretmek de bir soru türüdür; aslında örüntü tanımayla ilgilidir.

- İlk örnekte başlangıç değeri 4'tür ve her terim bir önceki terimin iki katının bir eksiğidir: $8-1 = 7$, $14-1 = 13$, $26-1 = 25$. Yani $a_n = 2a_{n-1} - 1$, $a_0 = 4$: $4, 7, 13, 25, \dots$
- İkinci örnekte her terim, bir önceki terimin iki katı ile iki önceki terimin toplamıdır: $2\cdot3 + 1 = 7$, $2\cdot7 + 3 = 17$.

<!-- BELİRSİZ: Sayı dizisi örneklerinin tam terimleri karelerde görünmüyor; ikinci örneğin dizisi altyazıdan 1, 3, 7, … biçiminde anlaşılıyor. -->

Hoca, örüntüyü görmenin her zaman kolay olmadığını, ama sorulacak soruların basit olacağını söyledi.

Homojen olmayan bir örnek: $a_n = a_{n-1} + a_{n-2} + 2^{n-1}$. $a_2$ hesaplanırken bir önceki ile iki önceki terim toplanır ve $2^1 = 2$ eklenir: $3 + 1 + 2 = 6$. Sonra $6 + 3 + 2^2$ diye devam edilir.

<!-- BELİRSİZ: Altyazıda başlangıç değerleri "A0'a 1, A1'e 2" diye geçiyor, ama hesapta $a_1 = 3$ kullanılıyor ($3+1+2 = 6$). -->

### 16.1 "00" içeren ikili diziler

Slayttaki soru (ekrandan, 01:55:00): Sadece 0 ve 1'lerden oluşan $n$ birim uzunluğunda sayı dizileri oluşturuluyor. Bu sayı dizilerinden $n$ uzunluğunda olup "00" içerenlerin sayısını veren rekürans bağıntısını başlangıç koşullarını da belirterek yazınız.

Slayttaki sayım:

| $n$ | Diziler | "00" içerenler | $a_n$ |
|---|---|---|---|
| 0 | dizi yok | — | $a_0 = 0$ |
| 1 | 0, 1 | — | $a_1 = 0$ |
| 2 | 00, 01, 10, 11 | 00 | $a_2 = 1$ |
| 3 | 000, 001, 010, 100, 011, 101, 110, 111 | 000, 001, 100 | $a_3 = 3$ |
| 4 | 16 dizi | 0000, 0001, 0010, 0100, 1000, 0011, 1001, 1100 | $a_4 = 8$ |

Dizi $0, 0, 1, 3, 8, \dots$ biçiminde ilerler. Slayttaki bağıntı:

$$a_n = 2a_{n-1} + a_{n-2} + 1, \quad n \ge 2, \qquad a_0 = 0,\; a_1 = 0.$$

Hoca bunun olasılık ve permütasyon düşüncesiyle kurulabileceğini, örneğin sonu "00" ile bitenlerin ayrı sayılması gerektiğini söyledi.

> **Ders sonrası not:** Slayttaki bağıntı $a_2$, $a_3$, $a_4$ değerlerini doğru verir, ama $n=5$ için $2\cdot8+3+1 = 20$ bulur. Uzunluğu 5 olan ve "00" içeren ikili dizilerin gerçek sayısı 19'dur (python ile 32 dizi tek tek sayıldı). Doğru bağıntı büyük olasılıkla şöyle kurulur: dizi 1 ile başlıyorsa kalan $n-1$ uzunluk "00" içermelidir ($a_{n-1}$); 01 ile başlıyorsa kalan $n-2$ uzunluk içermelidir ($a_{n-2}$); 00 ile başlıyorsa kalan $n-2$ bit serbesttir ($2^{n-2}$). Buradan $a_n = a_{n-1} + a_{n-2} + 2^{n-2}$ ($n\ge2$, $a_0=a_1=0$) çıkar ve $0, 0, 1, 3, 8, 19, 43, \dots$ verir.

## 17. Problemlerin Karmaşıklığı: P, NP, NP-Tam, NP-Zor

Şimdiye kadar algoritmaların karmaşıklığına bakıldı. Problemlerin de karmaşıklığı vardır ve bu, problemin polinom zamanda çözülüp çözülemediğiyle ilgilidir.

- **İzlenebilir (tractable) problemler:** Polinom zamanda çözülebilen problemlerdir. Karmaşıklık $O(1)$, $O(\log n)$, $O(n)$, $O(n\log n)$, $O(n^2)$, $O(n^3)$ olabilir; ama $n^n$ ya da $2^n$ gibi olamaz. Makul büyüklükteki verilerde çözüme gidilmesi beklenir. Hoca, polinomun derecesinin genelde 3, 5, 7, 10 gibi küçük olduğunu; 100, 200 dereceli polinomların pratikte bu kapsama pek girmediğini söyledi.
- **İzlenemez (intractable) problemler:** Polinom zamanlı algoritmalarla çözülemeyen problemlerdir. Çok küçük girdilerde bile çok uzun sürede yanıt veren algoritmalar bu durumdadır. Bu tür problemlerde kesin çözüm yerine yaklaşık bir çözüm bulunup bulunamayacağına bakılır.
- **Çözülemez (unsolvable) problemler:** Örneğin **durma problemi (halting problem)**: bir A programı için, A'nın sonlanıp sonlanmayacağını bulan bir B programı yazmak. Alan Turing bu problemin çözülemez olduğunu kanıtlamıştır.

Slayttaki problem sınıfları (ekrandan, 02:00:00):

- Çözülebilir problemlerin **P sınıfına** (Class P, polinomsal) ait olduğu söylenir.
- Polinomsal zamanda kontrol edilebilen bir çözüm için problemlerin **NP sınıfına** (Class NP) ait olduğu söylenir.
- NP kısaltması **belirli olmayan polinomsal zamanlı (nondeterministic polynomial time)** anlamına gelir. Hoca, NP'nin "non-polynomial" değil "non-deterministic polynomial" olduğuna dikkat çekti; polinom zamanda olup olmadığı belli değildir, "ucu açıktır".
- Problemlerin herhangi biri polinomsal en kötü durum zaman algoritmalarıyla çözülebildiğinde NP sınıfındaki tüm problemler de polinomsal en kötü durum zaman algoritmalarıyla çözülebiliyorsa, bu özelliği taşıyan problemlere **NP-tam (NP-complete)** problemler denir.
- **NP-zor (NP-Hard):** Slayttaki tanıma göre, polinomsal zamanda bir çözümü olduğunu ispatlayamadığımız karar problemlerinin karmaşıklık sınıfıdır.

Tahtadaki çizimde P, NP'nin içinde küçük bir küme olarak gösterildi.

> **Hocanın vurgusu:** P, NP, NP-tam ve NP-zor kavramlarını bilmek gerekir. Bir problem verilip P mi, NP mi, NP-zor mu, NP-tam mı olduğu bilgi sorusu olarak sorulabilir.

> **Ek bilgi (derste anlatılmadı):** NP-zor sınıfının yaygın tanımı şudur: NP'deki her problem polinom zamanda ona indirgenebiliyorsa o problem NP-zordur. NP-zor bir problemin NP'de olması gerekmez; hem NP'de hem NP-zor olan problemler NP-tamdır. Slayttaki "çözümü olduğunu ispatlayamadığımız" ifadesi bu biçimsel tanımın sezgisel bir özetidir.

Ders sonunda hoca, iteratif ve öz yinelemeli algoritmaların analizi, backward substitution ve özyineleme ağacı yöntemleri için kaynak kitaptan (Rosen, *Discrete Mathematics and Its Applications*, 7. baskı) çalışmayı önerdi. Kitapta böl ve yönet bağıntılarına örnek olarak ikili arama ($f(n) = f(n/2) + 2$), bir dizinin en büyük ve en küçük elemanını bulma ($f(n) = 2f(n/2) + 2$) ve birleştirmeli sıralama (merge sort) bağıntıları ile Master teoremi ve sabit katsayılı bağıntıların karakteristik denklemle çözümü bulunur (ekrandan, 02:05:00). Hoca bu bölümlerdeki alıştırmaları çözmenin yeterli olacağını söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): $f(x) = x^2+2x+1$'in $O(x^2)$ olduğunu gösteriniz.

> **Çözüm (derste verildi):** $x>1$ için $x<x^2$ ve $1<x^2$ olduğundan $0 \le x^2+2x+1 \le x^2+2x^2+x^2 = 4x^2$. Tanıklar $C=4$, $k=1$. Alternatif: $x>2$ için $2x\le x^2$ olduğundan $x^2+2x+1 \le 3x^2$; tanıklar $C=3$, $k=2$.

**Soru 2** (ekrandan, 00:25:00): $f_1(n) = (1.5)^n$, $f_2(n) = 8n^3+17n^2+111$, $f_3(n) = (\log n)^2$, $f_4(n) = 2^n$, $f_5(n) = \log(\log n)$, $f_6(n) = n^2(\log n)^3$, $f_7(n) = 2^n(n^2+1)$, $f_8(n) = n^3+n(\log n)^2$, $f_9(n) = 10000$, $f_{10}(n) = n!$ fonksiyonlarını, her biri listede kendinden sonrakinin Big-O'su olacak şekilde sıralayınız.

> **Çözüm (derste sözlü verildi):** $f_9,\ f_5,\ f_3,\ f_6,\ f_8,\ f_2,\ f_1,\ f_4,\ f_7,\ f_{10}$. ($f_8$ ile $f_2$ ikisi de $\Theta(n^3)$ olduğu için aralarındaki sıra iki yönde de geçerlidir.)

**Soru 3** (ekrandan, 00:30:00): $f(x) = 8x^3+5x^2+7$'nin $\Omega(x^3)$ olduğunu gösteriniz. $x^3$ aynı zamanda $O(8x^3+5x^2+7)$ midir?

> **Çözüm (derste verildi):** Bütün pozitif $x$ için $8x^3+5x^2+7 \ge 8x^3$ olduğundan $\Omega(x^3)$. Ayrıca $x\ge1$ için $8x^3+5x^2+7 \le 20x^3$ olduğundan fonksiyon $O(x^3)$'tür; sonuç olarak $\Theta(x^3)$'tür ve $x^3 \in O(8x^3+5x^2+7)$ de doğrudur (her pozitif $x$ için $x^3 \le 8x^3+5x^2+7$).

**Soru 4** (ekrandan, 00:40:00): $F(x) = (x+1)\log(x^2+1) + 3x^2$ için Big-O nedir?

> **Çözüm (derste verildi):** $(x+1) = O(x)$, $\log(x^2+1) = O(\log x)$, çarpım $O(x\log x)$; $3x^2 = O(x^2)$. Büyük olan $x^2$ olduğundan $F(x) = O(x^2)$.

**Soru 5** (ekrandan, 00:45:00): $2^n$ ile $n!$'in büyüme hızlarını karşılaştırınız.

> **Çözüm (derste verildi):** $n!$ daha hızlı büyür; $\lim_{n\to\infty} 2^n/n! = 0$. Bu yüzden $2^n \in O(n!)$; en sıkı ifade ise $2^n \in O(2^n)$'dir.

**Soru 6** (derste sözlü, 00:46:53): $4x^3+3x^2$ fonksiyonunun $x^4$ ile ilişkisini limitle ve tanımla gösteriniz.

> **Çözüm (derste verildi):** $\lim_{x\to\infty}(4x^3+3x^2)/x^4 = \lim(4/x + 3/x^2) = 0$, bu yüzden $4x^3+3x^2 \in O(x^4)$. Tanımla: $x\ge1$ için $4x^3+3x^2 \le 7x^4$, $C=7$.

**Soru 7** (ekrandan, 00:50:00): $n>6$ ve $n$ bir tamsayı iken $3n<n!$ olduğunu ispatlayınız.

> **Çözüm (derste verildi):** Tümevarım. $n=7$: $21<5040$. $3k<k!$ kabul. $3(k+1) = 3k+3 < k\cdot k! + k! = (k+1)!$, çünkü $3k<k!$ ve $k>6$ için $3<k\cdot k!$. Bölüm 7'ye bakınız.

**Soru 8** (derste sözlü, 00:54:24): Insertion Sort'un en iyi durumu için $O(n)$ yanında $\Theta(n)$ ve $\Omega(n)$ denebilir mi?

> **Çözüm (derste verildi):** Evet. En az $n$ kontrol gerektiği için $\Omega(n)$, fazlası yapılmadığı için $O(n)$; ikisi birlikte $\Theta(n)$ demektir.

**Soru 9** (ekrandan, 01:00:00): Selection Sort'taki karşılaştırma sayısını bulup Big-O ile ifade ediniz.

> **Çözüm (derste verildi):** $T(N) = \sum_{j=0}^{N-2}(N-1-j) = \frac{N(N-1)}{2}$; $O(n^2)$. Karşılaştırma her durumda yapıldığı için en iyi, ortalama ve en kötü durumda $\Theta(n^2)$.

**Soru 10** (ekrandan, 01:25:00): $T(n) = T(n-1)+1$, $T(1)=2$ bağıntısını backward substitution ile çözünüz.

> **Çözüm (derste verildi):** $T(n) = T(n-k)+k$; $k=n-1$ için $T(n) = T(1) + n - 1 = n+1$; $O(n)$.

**Soru 11** (derste sözlü, 01:30:20): $T(n) = 16\,T(n/4) + 5n^3$ bağıntısının karmaşıklığını Master teoremiyle bulunuz.

> **Çözüm (derste verildi):** $a=16$, $b=4$, $d=3$; $b^d = 64 > 16$ olduğundan Durum 1: $\Theta(n^3)$.

**Soru 12** (ekrandan, 01:45:00): $a_n = -4a_{n-1} - 4a_{n-2}$, $a_0 = 3$, $a_1 = 5$ başlangıç koşulları ile verilen rekürans bağıntısının çözümünü bulunuz.

> **Çözüm (derste verildi):** $r^2+4r+4 = 0$, $r=-2$ (çakışık). $a_n = 3(-2)^n - \frac{11}{2}n(-2)^n$.

**Soru 13** (ekrandan, 01:50:00): $a_n = a_{n-1} + 2a_{n-2} + 3n + 4$, $a_0 = 5$, $a_1 = 7$ başlangıç koşulları ile verilen rekürans bağıntısını çözünüz.

> **Çözüm (derste kısmen verildi, tamamlandı):** $a_n^{(h)} = c_1 2^n + c_2(-1)^n$; $a_n^{(\text{ö})} = An+B$ ile $A = -\frac32$, $B = -\frac{23}{4}$. Başlangıç koşullarından $c_1 = \frac{25}{3}$, $c_2 = \frac{29}{12}$:
> $$a_n = \frac{25}{3}2^n + \frac{29}{12}(-1)^n - \frac32 n - \frac{23}{4}.$$
> Python ile $a_0$–$a_7$ için bağıntıyla karşılaştırıldı. Karmaşıklık $O(2^n)$.

**Soru 14** (ekrandan, 01:55:00): Sadece 0 ve 1'lerden oluşan $n$ birim uzunluğunda sayı dizileri oluşturuluyor. Bu dizilerden $n$ uzunluğunda olup "00" içerenlerin sayısını veren rekürans bağıntısını başlangıç koşullarını da belirterek yazınız.

> **Çözüm (derste verildi, düzeltmeli):** Slayttaki sayım $a_0=0$, $a_1=0$, $a_2=1$, $a_3=3$, $a_4=8$. Slaytta bağıntı $a_n = 2a_{n-1}+a_{n-2}+1$ olarak verildi, ama bu $a_5$'i 20 bulur; doğru değer 19'dur. Doğru bağıntı $a_n = a_{n-1} + a_{n-2} + 2^{n-2}$, $n\ge2$, $a_0=a_1=0$ (Bölüm 16.1'deki ders sonrası nota bakınız).

**Soru 15** (derste sözlü, 02:00:09): Verilen bir problemin P, NP, NP-tam ya da NP-zor sınıfından hangisine ait olduğunu belirtiniz.

> **Çözüm:** Derste belirli bir problem verilmedi; hoca bu biçimde bilgi sorusu sorulabileceğini söyledi. Tanımlar için Bölüm 17'ye bakınız.

## Dersin Toparlaması

Bu derste algoritma karmaşıklığının matematiksel dili tamamlandı. Big-O üst sınırı, Big-Omega alt sınırı, Big-Theta sıkı sınırı verir; üçünde de belli bir $k$ noktasından sonraki davranış önemlidir ve tanıklar ($C$, $k$) bulunarak ispat yapılır. Pratikte en yüksek dereceli terim alınır, katsayı ve düşük dereceli terimler atılır; iki fonksiyon limitle de karşılaştırılabilir. Insertion Sort ve Selection Sort üzerinden en iyi, ortalama ve en kötü durum analizi yapıldı. Temel işlem olarak karşılaştırma seçildiğinde Selection Sort'un her durumda $\Theta(n^2)$ olduğu görüldü.

Dersin ikinci yarısında öz yinelemeli algoritmaların analizine geçildi. Rekürans bağıntıları forward ve backward substitution, özyineleme ağacı, Master teoremi ve karakteristik denklem yöntemiyle çözüldü. Bağıntılar derece, homojenlik, doğrusallık ve sabit katsayılılık açısından sınıflandırıldı. Homojen olmayan bağıntılarda özel çözümün nasıl tahmin edildiği gösterildi. Ders, problemlerin karmaşıklık sınıflarıyla (P, NP, NP-tam, NP-zor) ve durma problemiyle kapandı. Hoca sonraki konuların (ağaçlar, graflar) temellerinin bu derste anlatılan analiz yöntemlerine dayandığını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
