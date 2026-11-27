# Ders 6 Çalışma Özeti

## Genel Konular

- Asimptotik notasyonların amacı
  - Bir algoritmanın çalışma süresi $T(n)$ gibi $n$'e bağlı bir fonksiyonla bulunur (örneğin $4n^2+5n$). Asimptotik notasyonlar bu fonksiyonu en sade hâle getirir ve algoritmanın üst sınırını, alt sınırını ya da sıkı sınırını gösterir.
  - $n$'in küçük değerlerinde algoritmalar arasındaki fark önemli değildir; belli bir $k$ noktasından sonraki büyüme hızı karşılaştırılır.
- Büyük-O (Big-O) gösterimi: asimptotik üst sınır
  - Tanım (ekrandan, 00:15:00): $f$ ve $g$, $\mathbb{Z}^+ \to \mathbb{R}$ tanımlı olsun. $x > k$ olduğunda $|f(x)| \le C\,|g(x)|$ eşitsizliğini sağlayan $C$ ve $k$ sabitleri varsa $f(x) = O(g(x))$ olur.
  - "Algoritmam olsa olsa bu kadar sürer" anlamındadır. $C$ ve $k$ değerlerine tanık (witness) denir; bir tane tanık çifti bulmak yeterlidir.
  - Kısa yol: en yüksek dereceli terim alınır, düşük dereceli terimler ve en yüksek dereceli terimin sabit katsayısı atılır.
- Büyük-Omega ($\Omega$): asimptotik alt sınır
  - Tanımdaki eşitsizlik $|f(x)| \ge C\,|g(x)|$ olur. "Algoritma en iyi ihtimalle bu karmaşıklıkta çalışır" demektir.
  - Örnek: bir diziyi sıralamak için en az bir kez bütün elemanlara bakmak gerekir, bu yüzden sıralamanın alt sınırı $\Omega(n)$'dir.
- Büyük-Theta ($\Theta$): sıkı sınır (tight bound)
  - $x > k$ için $C_1|g(x)| \le |f(x)| \le C_2|g(x)|$ sağlanıyorsa $f(x) = \Theta(g(x))$ olur. $\Theta$, $O$ ile $\Omega$'nın kesişimidir.
  - $f = \Theta(g)$ ise $g = \Theta(f)$ da doğrudur.
- Temel karmaşıklık sınıfları
  - Sabit $O(1)$, logaritmik $O(\log n)$, doğrusal $O(n)$, doğrusal-logaritmik $O(n\log n)$, karesel $O(n^2)$, kübik $O(n^3)$, üstel $O(2^n)$, faktöriyel $O(n!)$.
  - Örnekler: bağlı listenin başına eleman ekleme $O(1)$; ikili arama ağacında arama $O(\log n)$; sırasız dizide arama $O(n)$; Quick Sort $O(n\log n)$; Bubble Sort $O(n^2)$; matris çarpımı $O(n^3)$; Hanoi kuleleri ve parola deneme $O(2^n)$.
- Limit yöntemiyle büyüme hızı karşılaştırma
  - $\lim_{n\to\infty} T(n)/g(n)$ hesaplanır: sonuç $0$ ise $T(n) \in O(g(n))$; $c>0$ sabiti ise $T(n)\in\Theta(g(n))$; $\infty$ ise $T(n)\in\Omega(g(n))$ (ekrandan, 00:45:00).
  - Belirsizlik çıkarsa L'Hôpital kuralı, faktöriyel için Stirling formülü $n! \approx \sqrt{2\pi n}\,(n/e)^n$ kullanılır.
- İteratif algoritmaların analizi
  - Girdi boyutu ve temel operasyon belirlenir, en iyi ve en kötü durum için $T(n)$ bulunur, sonra asimptotik olarak sadeleştirilir.
  - Sıralı arama: en iyi $O(1)$, en kötü $O(n)$, ortalama yaklaşık $(n+1)/2$ yani $O(n)$.
  - Insertion Sort: en iyi durum (dizi sıralı) $O(n)$, ortalama ve en kötü durum (dizi ters sıralı) $O(n^2)$.
  - Selection Sort: karşılaştırma sayısı her durumda $N(N-1)/2$, yani en iyi, ortalama ve en kötü durumda $\Theta(n^2)$.
- Öz yinelemeli (recursive) algoritmaların analizi
  - Temel işlemin kaç kez yürütüldüğü bir başlangıç koşulu ile özyineleme bağıntısı (recurrence relation) olarak yazılır, sonra çözülüp asimptotik notasyonla ifade edilir.
  - Çözüm yöntemleri (ekrandan, 01:15:00): ileriye doğru yerine koyma (forward substitution), geriye doğru yerine koyma (backward substitution), özyineleme ağacı (recursive tree), Master teoremi, karakteristik denklem yöntemi.
- Master teoremi
  - $T(n) = aT(n/b) + \Theta(n^d)$, $T(1)=c$, $a\ge1$, $b\ge2$, $d\ge0$ için: $a<b^d$ ise $\Theta(n^d)$; $a=b^d$ ise $\Theta(n^d\log n)$; $a>b^d$ ise $\Theta(n^{\log_b a})$ (ekrandan, 01:30:00).
- Rekürans bağıntılarının sınıflandırılması
  - Derece (order): bağıntıda geriye en çok kaç terim gidildiği.
  - Homojenlik: yalnız $a_n$'li terimlerden oluşuyorsa homojendir.
  - Doğrusallık: $a_n$'li terimler birbiriyle çarpılmıyor ve kuvveti alınmıyorsa doğrusaldır.
  - Sabit katsayılılık: $a_n$'li terimlerin katsayıları $n$'e bağlı değilse sabit katsayılıdır.
- Karakteristik denklem yöntemi
  - Sabit katsayılı homojen ikinci dereceden bağıntıda $a_n = r^2$, $a_{n-1}=r$, $a_{n-2}=1$ yazılarak karakteristik denklem kurulur.
  - Farklı iki kök: $a_n = c_1 r_1^n + c_2 r_2^n$. Çakışık kök: $a_n = c_1 r^n + c_2\, n\, r^n$. $c_1, c_2$ başlangıç koşullarından bulunur.
  - Homojen olmayan bağıntıda genel çözüm $a_n = a_n^{(h)} + a_n^{(\text{ö})}$; özel çözüm sağ taraftaki fonksiyonun türüne göre tahmin edilir (sabit için $A$, birinci derece polinom için $An+B$, $5^n$ için $A\cdot 5^n$).
- Sayı dizisinden rekürans bağıntısı kurma
  - Örnek soru: içinde "00" geçen $n$ uzunluklu ikili dizilerin sayısını veren bağıntı.
- Problemlerin karmaşıklığı
  - Polinom zamanda çözülebilen problemler izlenebilir (tractable), çözülemeyenler izlenemez (intractable) problemlerdir. Durma problemi (halting problem) çözülemez (unsolvable) bir problemdir.
  - P, NP, NP-tam (NP-complete) ve NP-zor (NP-hard) sınıfları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Big-O'nun kısa yolu
  - En yüksek dereceli terim alınır, diğer terimler ve katsayı atılır. Hoca bunun "tahmin edilecek bir şey değil, doğrudan bakınca anlaşılan" bir kural olduğunu birkaç kez vurguladı.
  - "İspat edin" denirse tanımdaki $C$ ve $k$ tanıkları bulunmalıdır. Sınavda limitle ya da tanımla kanıt istenebileceğini söyledi.
- Gereğinden büyük üst sınır yazmak
  - $n^2$ olan bir algoritma matematiksel olarak $O(n^3)$, $O(2^n)$ da yazılabilir; ama en doğru ifade en sıkı sınırdır. Daha büyüğünü yazmak algoritmayı olduğundan kötü göstermektir.
- Selection Sort ile Bubble Sort farkı
  - Selection Sort her durumda en küçük elemanı aramak zorunda olduğu için en iyi ve en kötü durumu aynıdır ($\Theta(n^2)$). Erken bitirme kontrolü olan Bubble Sort'ta ise en iyi durum $\Omega(n)$'dir.
- Karşılaştırma sayısı ile atama sayısı
  - Selection Sort'ta temel işlem karşılaştırmadır; karşılaştırma her durumda yapılır. Atama sayılsaydı en iyi ve en kötü durum ayrı çıkardı.
- Backward substitution
  - İleri yönde yerine koymada bir tahmin yapmak gerekir; geriye doğru açmak, bağıntı ve başlangıç koşulu verildiğinde daha rahattır.
- P, NP, NP-tam, NP-zor kavramları
  - Hoca bu kavramlardan bilgi sorusu sorulabileceğini söyledi: bir problemin hangi sınıfta olduğu sorulabilir.
- Kaynak kitap
  - Rosen'in Discrete Mathematics and Its Applications kitabının algoritmalar, özyineleme ve rekürans bağıntıları bölümlerindeki örneklerin çözülmesini önerdi.

## Kısa Tekrar Notları

- $f(x)=O(g(x))$: $x>k$ için $|f(x)| \le C|g(x)|$. Üst sınır.
- $f(x)=\Omega(g(x))$: $x>k$ için $|f(x)| \ge C|g(x)|$. Alt sınır.
- $f(x)=\Theta(g(x))$: hem $O$ hem $\Omega$. Sıkı sınır.
- $x^2+2x+1 \le 4x^2$ ($x>1$) olduğundan $x^2+2x+1 = O(x^2)$; tanıklar $C=4$, $k=1$ (ya da $C=3$, $k=2$).
- $8x^3+5x^2+7 \ge 8x^3$ olduğundan $\Omega(x^3)$; aynı zamanda $O(x^3)$, yani $\Theta(x^3)$.
- $3x^2+8x\log x$ için $3x^2 \le f(x) \le 11x^2$ olduğundan $\Theta(x^2)$.
- Büyüme sırası: $10000 \prec \log\log n \prec (\log n)^2 \prec n^2(\log n)^3 \prec n^3$'lü terimler $\prec 1.5^n \prec 2^n \prec 2^n(n^2+1) \prec n!$.
- Parçalı algoritmanın karmaşıklığı en büyük parçanın karmaşıklığıdır.
- $\lim T/g = 0 \Rightarrow O$; $=c>0 \Rightarrow \Theta$; $=\infty \Rightarrow \Omega$.
- $2^n \in O(n!)$ ve $2^n \in O(2^n)$; en sıkı ifade ikincisidir.
- Sıralı arama: $O(1)$ / $O(n)$ / $O(n)$. Insertion Sort: $O(n)$ / $O(n^2)$ / $O(n^2)$. Selection Sort: her durumda $\Theta(n^2)$.
- $T(n)=T(n-1)+1$, $T(1)=2$ $\Rightarrow$ $T(n)=n+1 = O(n)$.
- Faktöriyel: $T(n)=T(n-1)+3$, $T(0)=1$ $\Rightarrow$ $T(n)=3n+1 = O(n)$.
- $f(n)=n+f(n-1)$, $f(1)=1$ $\Rightarrow$ $n(n+1)/2 = O(n^2)$.
- $T(n)=4T(n/2)+n$: ağaç derinliği $\log_2 n$, toplam $\Theta(n^2)$.
- Master: $16T(n/4)+5n^3$ için $a=16<4^3=64$ $\Rightarrow$ $\Theta(n^3)$.
- Karakteristik denklem: farklı kökler $c_1r_1^n+c_2r_2^n$, çakışık kök $c_1r^n+c_2nr^n$.
- Rekürans çözümünün Big-O'su en büyük tabanlı üstel terimdir (örneğin $5^n$ ile $(-2)^n$ varsa $O(5^n)$).
- P: polinom zamanda çözülebilen; NP: çözümü polinom zamanda kontrol edilebilen (nondeterministic polynomial); NP-tam: biri polinom zamanda çözülürse bütün NP çözülür; NP-zor: polinom zamanlı çözümü olduğu ispatlanamayan karar problemleri sınıfı (slayt tanımı).

## Detaylı Açıklamalar

- **Big-O tanımının kullanımı.** $4n^2+5n$ için $C=9$ seçilirse $n\ge1$ iken $5n \le 5n^2$ olduğundan $4n^2+5n \le 9n^2$ olur; bu yüzden $4n^2+5n = O(n^2)$'dir. Hiçbir $C$ için $4n^2+5n \le Cn$ eşitsizliği belli bir noktadan sonra her $n$ için sağlanmaz, bu yüzden bu fonksiyon $O(n)$ değildir. Slayttaki örnekte (ekrandan, 00:20:00) $x>1$ için $x<x^2$ ve $1<x^2$ olduğundan $0 \le x^2+2x+1 \le x^2+2x^2+x^2 = 4x^2$ bulunur; $C=4$, $k=1$ tanıktır. Alternatif olarak $x>2$ için $2x \le x^2$ olduğundan $x^2+2x+1 \le 3x^2$; bu kez $C=3$, $k=2$ tanıktır.
- **Omega ve Theta örnekleri.** $f(x)=8x^3+5x^2+7$ bütün pozitif $x$ için $f(x)\ge 8x^3$ olduğundan $\Omega(x^3)$'tür (ekrandan, 00:30:00). Hoca aynı fonksiyonun $C=20$ gibi bir sabitle $O(x^3)$ da olduğunu gösterdi. $3x^2+8x\log x$ için $x\log x \le x^2$ kullanılarak üstten $11x^2$, alttan $3x^2$ ile sınırlanır; bu yüzden $\Theta(x^2)$'dir.
- **Fonksiyonları büyüme hızına göre sıralama.** Slayttaki on fonksiyon (ekrandan, 00:25:00): $(1.5)^n$, $8n^3+17n^2+111$, $(\log n)^2$, $2^n$, $\log(\log n)$, $n^2(\log n)^3$, $2^n(n^2+1)$, $n^3+n(\log n)^2$, $10000$, $n!$. Sabit $10000$ en küçüktür, çünkü $n$'e bağlı bir büyüme yoktur. Sonra $\log\log n$, $(\log n)^2$, $n^2(\log n)^3$, iki kübik fonksiyon, $1.5^n$, $2^n$, $2^n(n^2+1)$ ve $n!$ gelir.
- **Karmaşık ifadelerin Big-O'su.** Bir program farklı karmaşıklıkta parçalardan oluşuyorsa en büyük parça belirleyicidir. $F(x)=(x+1)\log(x^2+1)+3x^2$ örneğinde (ekrandan, 00:40:00) $\log(x^2+1)$ yaklaşık $2\log x$, yani $O(\log x)$; $(x+1)$ ise $O(x)$ olduğundan ilk parça $O(x\log x)$, ikinci parça $O(x^2)$'dir. Büyük olan $x^2$ olduğundan $F(x)=O(x^2)$. <!-- BELİRSİZ: 00:38:02 civarındaki "3n, log n!" örneğinin tam ifadesi karede yok; hoca $\log n! = O(n\log n)$ ve sonucu $n^2\log n$ olarak verdi. -->
- **Limit yöntemi.** $\lim_{x\to\infty}(4x^3+3x^2)/x^4 = \lim(4/x + 3/x^2) = 0$ olduğundan $4x^3+3x^2 \in O(x^4)$'tür. $2^n$ ile $n!$ karşılaştırıldığında $n!$'in çarpanları belli bir noktadan sonra hep 2'den büyük olduğu için $n!$ daha hızlı büyür; $2^n \in O(n!)$ doğrudur ama en sıkı ifade $2^n \in O(2^n)$'dir.
- **Tümevarımla $3n < n!$.** $n>6$ için (ekrandan, 00:50:00): $n=7$'de $21 < 5040$. $3k<k!$ kabul edilir. $3(k+1) = 3k+3$ ve $(k+1)! = k\cdot k! + k!$; $3k<k!$ olduğundan $3 < k\cdot k!$ göstermek yeterlidir, bu da $k>6$ için açıktır. Sonuç: $3n<n!$, yani $3n \in O(n!)$; ama $3n$ için en doğru ifade $O(n)$'dir.
- **Insertion Sort.** Her eleman sıralı kısımda yerine yerleştirilir. Dizi baştan sıralıysa yer değiştirme olmaz, yalnız $n$ kontrol yapılır: $O(n)$ (ekrandan, 00:55:00). Dizi ters sıralıysa ($8,7,6,5,4$ gibi) her eleman en başa kadar karşılaştırılır: $O(n^2)$. En iyi durum için $O(n)$, $\Theta(n)$ ve $\Omega(n)$ üçü de söylenebilir.
- **Selection Sort analizi.** Dış döngü $j=0,\dots,N-2$, iç döngü $i=j+1,\dots,N-1$ ve temel işlem `if (A[i] < A[min_idx])` karşılaştırmasıdır (ekrandan, 01:00:00). İç döngü $N-1-j$ kez çalışır. Toplam $\sum_{j=0}^{N-2}(N-1-j) = (N-1)+(N-2)+\dots+1 = N(N-1)/2$, yani $\Theta(n^2)$.
- **Backward substitution.** $T(n)=T(n-1)+1$, $T(1)=2$ için $T(n) = T(n-k)+k$ bulunur; $k=n-1$ konunca $T(n) = T(1)+n-1 = n+1$ (ekrandan, 01:25:00). Faktöriyelde her çağrıda bir karşılaştırma, bir çarpma, bir çıkarma vardır: $T(n)=T(n-1)+3$, $T(0)=1$; açılınca $T(n-k)+3k$ ve $k=n$ için $T(n)=3n+1$.
- **Özyineleme ağacı.** $T(n)=4T(n/2)+n$'de seviyelerin maliyeti $n, 2n, 4n, \dots$ olarak artar; $n/2^k=1$ olduğunda $k=\log_2 n$'dir. Maliyetler toplanınca $\Theta(n^2)$ bulunur. Master teoremiyle de $a=4$, $b=2$, $d=1$, $a>b^d$ olduğundan $\Theta(n^{\log_2 4}) = \Theta(n^2)$'dir.
- **Karakteristik denklem örnekleri.**
  - $a_n = 3a_{n-1}+4a_{n-2}$: $r^2-3r-4=0$, $r=4$, $r=-1$; $a_n = c_1 4^n + c_2(-1)^n$ (ekrandan, 01:40:00).
  - $a_n = 3a_{n-1}+10a_{n-2}$, $a_0=5$, $a_1=8$: $r=5$, $r=-2$; $c_1=18/7$, $c_2=17/7$; $O(5^n)$.
  - $a_n=-4a_{n-1}-4a_{n-2}$, $a_0=3$, $a_1=5$: $(r+2)^2=0$; $a_n = 3(-2)^n - \tfrac{11}{2}n(-2)^n$ (ekrandan, 01:45:00).
  - $a_n = 2a_{n-1}+3a_{n-2}+5$, $a_0=4$, $a_1=10$: kökler $3$, $-1$; özel çözüm $A=-5/4$; $c_1=33/8$, $c_2=9/8$; $O(3^n)$.
  - $a_n = a_{n-1}+2a_{n-2}+3n+4$, $a_0=5$, $a_1=7$: $a_n^{(h)}=c_1 2^n + c_2(-1)^n$, özel çözüm $An+B$ ile $A=-3/2$ (ekrandan, 01:50:00); $O(2^n)$.
- **"00" içeren ikili diziler.** $a_0=0$, $a_1=0$, $a_2=1$, $a_3=3$, $a_4=8$ (ekrandan, 01:55:00).

> **Ders sonrası not:** Slayttaki bağıntı $a_n=2a_{n-1}+a_{n-2}+1$ ilk değerleri ($0,0,1,3,8$) doğru verir ama $n=5$ için 20 bulur; gerçek sayı 19'dur (python ile sayıldı). Doğru bağıntı $a_n=a_{n-1}+a_{n-2}+2^{n-2}$ ($n\ge2$, $a_0=a_1=0$) olur.

> **Ders sonrası not:** Master teoreminin üçüncü durumunu ($a>b^d$) hoca "üstel" diye anlattı; slayttaki sonuç $\Theta(n^{\log_b a})$ polinom bir karmaşıklıktır, üstel değildir.

- **P ve NP.** Çözülebilir problemler P sınıfındadır. Polinom zamanda kontrol edilebilen çözümleri olan problemler NP sınıfındadır; NP "belirli olmayan polinom zamanlı" (nondeterministic polynomial time) demektir. Herhangi biri polinom zamanda çözülürse bütün NP'nin çözüleceği problemler NP-tamdır (ekrandan, 02:00:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
