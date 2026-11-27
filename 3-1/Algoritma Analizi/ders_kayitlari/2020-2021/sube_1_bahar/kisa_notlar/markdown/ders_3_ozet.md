# Ders 3 Çalışma Özeti

## Genel Konular

- Asimptotik notasyonların tekrarı ve tanımları
  - Asimptotik notasyonlar, çalışma zamanı (ya da bellek) fonksiyonunu makineden bağımsız, sade biçimde yazmak ve algoritmanın alt sınırını, üst sınırını ya da sıkı sınırını göstermek için kullanılır.
  - Beş sembol: Big-O ($O$, üst sınır, $\le$), little-o ($o$, kesin üst sınır, $<$), Big-Omega ($\Omega$, alt sınır, $\ge$), little-omega ($\omega$, $>$) ve Big-Theta ($\Theta$, sıkı sınır, $\approx$). Little-o ve little-omega ayrıntılı işlenmedi (ekrandan, 00:10:00).
- Big-O tanımı ve ispat örnekleri
  - $f(n) \in O(g(n))$: $n > n_0 > 0$ olan bütün $n$ için $0 \le f(n) \le c \cdot g(n)$ olacak biçimde $c > 0$ ve $n_0$ bulunabiliyorsa. Derste $c$ ve $n_0$ tam sayı alındı (ekrandan, 00:25:00).
  - $n_0$, fonksiyonun küçük $n$ değerlerindeki düzensiz davranışını dışarıda bırakır; önemli olan $n \to \infty$ iken davranıştır.
  - Örnekler: $10n + 30 \in O(n)$ ($c = 40$, $n_0 = 1$); $n^2 + 2n + 1 \in O(n^2)$ ($c = 4$, $n_0 = 1$); $n^2 + n \in O(n^3)$; $n^2 + n \notin O(n)$.
- Big-Omega tanımı ve örnekleri
  - $f(n) \in \Omega(g(n))$: $n_0$'dan büyük bütün $n$ için $f(n) \ge c \cdot g(n)$ olacak biçimde $c > 0$, $n_0 > 0$ varsa (ekrandan, 00:40:00).
  - $5n^2 \in \Omega(n^2)$ ($c = 1$, $n_0 = 1$) ve $5n^2 \in \Omega(n)$.
  - Örnek: sıralı dizide aramanın en iyi durumu 1 adımdır; bayraklı Bubble Sort en iyi durumda diziyi bir kez gezer ($n$ karşılaştırma).
- Big-Theta tanımı ve örneği
  - $f(n) \in \Theta(g(n))$: hem $O(g(n))$ hem $\Omega(g(n))$; "$f(n)$, $g(n)$'e asimptotik olarak eşittir" (ekrandan, 00:50:00).
  - Örnek: $2n + 5 \in \Theta(n)$; önce $O(n)$, sonra $\Omega(n)$ ispatlanır (ekrandan, 01:15:00).
- Slayt örnekleri ve sadeleştirme kuralları
  - $2n + 10 \in O(n)$ ($c = 3$, $n_0 = 10$); $n^2 \notin O(n)$; $3n^3 + 20n^2 + 5 \in O(n^3)$; $3\log n + 5 \in O(\log n)$ (ekrandan, 01:10:00).
  - Düşük dereceli terimler ve sabit çarpanlar atılır; mümkün olan en küçük ve en sade sınıf yazılır ($O(3n)$ değil $O(n)$).
  - Büyüme sırası: $1 < \log n < n < n\log n < n^2 < n^3 < 2^n < n! < n^n$.
- Limit ile karşılaştırma
  - $\lim_{n\to\infty} T(n)/g(n)$: $0$ ise $T \in O(g)$, sabit $c$ ise $T \in \Theta(g)$, $\infty$ ise $T \in \Omega(g)$ (ekrandan, 01:20:00).
  - Belirsizlikte türev alınır: $n^2 / 2n^2 \to 2n/4n \to 1/2$.
- Analiz için matematik araçları
  - Logaritma kuralları, kombinatorik ($n!$, $\binom{n}{k}$, $2^n$), toplam formülleri, toplam manipülasyonları, taban ve tavan fonksiyonları.
- Özyinelemeli olmayan (iteratif) algoritmaların analizi
  - Adımlar: girdi boyutu $n$ belirlenir, temel operasyon (basic operation) seçilir, en içteki döngüye bakılır, $T(n)$ toplam olarak kurulur, asimptotik notasyona geçilir.
  - Gerekirse best, worst ve average case ayrı ayrı incelenir.
  - Örnekler: MaxElement, benzersiz elemanlar (unique elements), sıralı arama, Insertion Sort.
- Özyinelemeli algoritmaların analizi
  - Temel operasyon üzerinden bir yineleme bağıntısı (recurrence relation) ve başlangıç koşulu (initial condition) kurulur, sonra çözülür.
  - Yöntemler: geriye doğru yerine koyma (backward substitution), ileriye doğru yerine koyma (forward substitution), Master teoremi.
  - Örnekler: faktöriyel, bir sayının ikili basamak sayısı, $x(n) = x(n-1) + n$, Master teoremi örnekleri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tanımdan ispat istenirse $c$ ve $n_0$ ikilisi gösterilmelidir
  - Bir tane uygun ikili bulmak yeter, ama eşitsizlik $n_0$'dan sonraki bütün $n$ değerleri için sağlanmalıdır. Yalnız $n = 1$'de sağlanan bir ikili (örneğin $n^2 + n \le 2n$) ispat değildir; hatalar genelde burada yapılır.
  - Kısa yol: polinomdaki her terimi en büyük dereceli terim gibi düşünmek. $10n + 30 \le 10n + 30n = 40n$ olduğundan $c = 40$, $n_0 = 1$ seçilir.
- Mümkün olan en sıkı ve sade sınıf yazılmalıdır
  - $n^2$'lik bir algoritmaya $O(n^3)$ demek matematiksel olarak doğru, mantıksal olarak gereksizdir. $O(n-1)$ ya da $O(3n)$ gibi yazımlar kullanılmaz.
- Temel operasyon, her durumda mutlaka yürütülen ve algoritmanın yükünü çeken işlemdir
  - MaxElement'te atama her zaman yapılmaz ama karşılaştırma her zaman yapılır. Bu yüzden temel operasyon karşılaştırmadır.
- Temel operasyon kesin sayıda yürütülüyorsa best, worst ve average case aynıdır
  - Sayı girdinin dağılımına bağlıysa (örneğin `while` döngüsünde arama) üç durum ayrı ayrı analiz edilir. Average case en zor olanıdır, çünkü olasılık hesabı gerektirir.
- Özyinelemeli analizde başlangıç koşulunda temel operasyonun yapılıp yapılmadığına dikkat edilmelidir
  - Faktöriyelde $n = 0$ için çarpma yoktur: $M(0) = 0$. İkili basamak sayısında $n = 1$ için toplama yoktur: $A(1) = 0$.
- Backward substitution genelde en pratik yöntemdir
  - Forward substitution'da düzeni görmek daha zordur.

## Kısa Tekrar Notları

- $O$: üst sınır, en kötü durum. $\Omega$: alt sınır, en iyi durum. $\Theta$: ikisinin kesişimi, sıkı sınır.
- $f \in O(g)$ ise $f$, $g$'den hızlı büyümez. $f \in \Theta(g)$ ise ikisi aynı hızla büyür.
- Limit testinde sonuç $0$ ise $O$, sabit ise $\Theta$, $\infty$ ise $\Omega$.
- $\sum_{i=l}^{u} 1 = u - l + 1$, $\sum_{i=1}^{n} i = \frac{n(n+1)}{2}$, $\sum_{i=1}^{n} i^2 = \frac{n(n+1)(2n+1)}{6}$.
- $\lceil \log_2(n+1) \rceil = \lfloor \log_2 n \rfloor + 1$; bu eşitlik ikili aramada sık geçer.
- MaxElement: $T(n) = \sum_{i=1}^{n-1} 1 = n - 1 \in \Theta(n)$.
- Unique elements: $T(n) = \sum_{i=0}^{n-2} \sum_{j=i+1}^{n-1} 1 = \frac{n(n-1)}{2} \in \Theta(n^2)$.
- Sıralı arama: $C_{worst} = n$, $C_{best} = 1$, $C_{avg}(n) = \frac{p(n+1)}{2} + n(1-p)$.
- Insertion Sort: worst $\Theta(n^2)$ (ters sıralı dizi), best $\Theta(n)$ (sıralı dizi), average yaklaşık $n^2/4$.
- Faktöriyel: $M(n) = M(n-1) + 1$, $M(0) = 0$, sonuç $M(n) = n$.
- İkili basamak sayısı: $A(n) = A(n/2) + 1$, $A(1) = 0$, sonuç $A(n) = \log_2 n$.
- $x(n) = x(n-1) + n$, $x(0) = 0$, sonuç $x(n) = \frac{n(n+1)}{2} \in \Theta(n^2)$.
- Master teoremi: $T(n) = aT(n/b) + f(n)$, $f(n) \in \Theta(n^d)$:
  - $a < b^d$ ise $\Theta(n^d)$, $a = b^d$ ise $\Theta(n^d \log n)$, $a > b^d$ ise $\Theta(n^{\log_b a})$.

## Detaylı Açıklamalar

- **Big-O ispatı.** $f(n) = 10n + 30$ için $10n + 30 \le c \cdot n$ eşitsizliğinde $n_0 = 1$ alınırsa $40 \le c$ bulunur ve $c = 40$ seçilir (ekrandan, 00:25:00). Eşitsizlik $30 \le n(c - 10)$ biçiminde de yazılabilir: sol taraf sabit, sağ taraf $n$ ile büyüdüğü için uygun bir $c > 10$ seçildiğinde eşitsizlik bir yerden sonra hep sağlanır. $c = 1$ seçilirse $n \ge 10n + 30$ hiçbir $n$ için sağlanmaz, bu yüzden o ikili geçersizdir. $10n + 30 \in O(\log n)$ olamaz, çünkü $\log n$, $n$'den daha yavaş büyür ve hiçbir sabit bunu kapatamaz.
- **Bir fonksiyonun $O(n)$ olmadığını göstermek.** $n^2 + n \le c \cdot n$ eşitsizliği $n^2 \le n(c-1)$, yani $n \le c - 1$ olur. Sürekli artan $n$ hiçbir zaman sabit bir sayıdan küçük kalamaz; çelişki çıktığı için $n^2 + n \notin O(n)$ (ekrandan, 00:35:00). Aynı fonksiyon $O(n^3)$'tür.
  - > **Ders sonrası not:** Derste $n^2 + n \le c\,n^3$ için $c = 2$, $n_0 = 1$ ikilisinin sağlanmadığı söylendi ve ekranda $c = 2$, $n = 5$ ikilisi işaretlendi. Aslında $n = 1$'de $2 \le 2$ olduğundan $c = 2$, $n_0 = 1$ de geçerlidir (python ile kontrol edildi).
- **Big-Omega ve Big-Theta.** $5n^2 \ge c\,n^2$ eşitsizliği $(5 - c)n^2 \ge 0$ olur; $c \le 5$ olan her pozitif $c$ ile sağlanır (ekrandan, 00:40:00). Big-Theta için $2n + 5$ önce $2n + 5 \le c_1 n$ ile $O(n)$ ($c_1 = 7$, $n_0 = 1$), sonra $2n + 5 \ge c_2 n$ ile $\Omega(n)$ gösterilir (ekrandan, 01:15:00).
  - > **Ders sonrası not:** Ekranda $\Omega$ kısmı için $n = 1$, $c_2 = 4$ seçildi. Ancak $2n + 5 \ge 4n$ eşitsizliği $n \ge 3$ için sağlanmaz. Bütün $n \ge 1$ için geçerli bir seçim $c_2 = 2$'dir (python ile kontrol edildi).
- **Limit yöntemi.** İki fonksiyonun oranının $n \to \infty$ limiti hesaplanır. $T(n) = n^2$, $g(n) = 2n^2$ için L'Hôpital ile $2n/4n$ ve ardından $2/4 = 1/2$ bulunur; sonuç sabit olduğundan $T \in \Theta(g)$. Hoca $2^n$ ile $n!$'i bu yolla karşılaştırmayı alıştırma olarak önerdi.
  - > **Ders sonrası not:** Hoca alıştırmayı verirken $2^n$'in daha hızlı büyüdüğünü söyledi. Doğrusu, $n!$ daha hızlı büyür: $n \ge 4$ için $n! > 2^n$ ve $\lim 2^n/n! = 0$, yani $2^n \in O(n!)$. Derste yazılan büyüme sırası da ($2^n$'den sonra $n!$) bununla uyumludur.
- **Toplam formülleri** (ekrandan, 01:30:00). $\sum_{i=1}^{n} i^k \approx \frac{1}{k+1} n^{k+1}$; $\sum_{i=0}^{n} a^i = \frac{a^{n+1} - 1}{a - 1}$ ($a \ne 1$); $\sum_{i=1}^{n} \frac{1}{i} \approx \ln n + 0.5772$. Manipülasyonlar: sabit dışarı alınır, toplamın toplamı ayrılır, sınır bölünür ($\sum_{l}^{u} = \sum_{l}^{m} + \sum_{m+1}^{u}$), sınır kaydırılır ($\sum_{i=2}^{5} a_i = \sum_{i=0}^{3} a_{i+2}$).
  - > **Ders sonrası not:** Ekranda $\sum i^k$ için payda $k$ ve geometrik toplam için payda $a$ yazıldı. Doğrusu, paydalar sırasıyla $k+1$ ve $a-1$'dir. Hoca $\sum i^k$ için "eksponansiyel bir durum" dedi; sonuç $n$'in polinomudur.
- **İteratif analiz örnekleri.** MaxElement'te karşılaştırma `for` içinde her adımda yapılır: $T(n) = n - 1$ ve üç durum da $\Theta(n)$ (ekrandan, 01:40:00). Unique elements iç içe iki döngüdür: iç toplam $n - 1 - i$, dış toplam $\frac{n(n-1)}{2}$ (ekrandan, 01:50:00). Sıralı aramada karşılaştırma `while` içindedir; sayı girdiye bağlı olduğundan üç durum ayrı hesaplanır (ekrandan, 02:10:00). Insertion Sort'ta iç `while` döngüsü ekleme yerini arar; ters sıralı dizide her eleman başa taşınır ($\Theta(n^2)$), sıralı dizide iç döngüye hiç girilmez ($\Theta(n)$) (ekrandan, 02:20:00).
- **Özyinelemeli analiz.** Faktöriyelde $M(n) = M(n-1) + 1$ geriye doğru açılırsa $M(n-i) + i$ elde edilir; $i = n$ için $M(0) + n = n$. İkili basamak sayısında $A(n) = A(n/2) + 1 = A(n/4) + 2 = A(n/2^i) + i$ olur (ekrandan, 02:40:00); $n/2^i = 1$ için $i = \log_2 n$ ve $A(n) = \log_2 n$. $n = 2^k$ yazarak da aynı sonuca ulaşılır.
- **Master teoremi.** $T(n) = aT(n/b) + f(n)$, $T(1) = c$ biçimindeki bağıntılarda $a$ özyinelemeli çağrı sayısını, $b$ her çağrıda girdinin kaça bölündüğünü, $d$ de $f(n) = n^d$'deki üssü gösterir (ekrandan, 02:50:00). Örnekler: $2A(n/2) + 1$ için $a = 2$, $b = 2$, $d = 0$, $2 > 2^0$, sonuç $\Theta(n)$. $3T(n/2) + n^2$ için $3 < 2^2$, sonuç $\Theta(n^2)$. $T(2n/3) + 1$ için $a = 1$, $b = 3/2$, $d = 0$, $1 = (3/2)^0$, sonuç $\Theta(\log n)$ (ekrandan, 02:55:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
