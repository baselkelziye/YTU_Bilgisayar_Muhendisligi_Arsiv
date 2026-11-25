# Ders 12 Çalışma Özeti

## Genel Konular

- İteratif algoritmaların analizi
  - İteratif algoritma: genellikle `for` ya da `while` döngüsü içeren, döngü içinde çoğunlukla `if` bulunmayan algoritmadır.
  - İki tür analiz yapılır: değer analizi (döngü bitince bir değişkenin, örneğin `T`'nin, değeri ne olur?) ve karmaşıklık analizi (döngü ya da içindeki işlem kaç kez tekrar eder?).
  - Yöntem: kod toplam ($\sum$) ya da çarpım ($\prod$) sembolüyle yazılır, alt ve üst sınırlar belirlenir, sonra bilinen toplam formülleri kullanılır.
- Kullanılan toplam eşitlikleri (ekrandan, 00:10:00)
  - Toplamı bölme: $\sum_{i=a}^{b}(x+y)=\sum_{i=a}^{b}x+\sum_{i=a}^{b}y$.
  - Sınırı kaydırma: $\sum_{i=a}^{b}f(i)=\sum_{i=0}^{b}f(i)-\sum_{i=0}^{a-1}f(i)$.
  - Sabiti dışarı alma: $\sum c\,f(i)=c\sum f(i)$; sabitin toplamı: $\sum_{i=0}^{n-1}c=cn$.
  - Gauss: $\sum_{i=0}^{n-1}i=\frac{n(n-1)}{2}$; üst sınır $n$ ise $\sum_{i=1}^{n}i=\frac{n(n+1)}{2}$.
  - Kareler: $\sum_{i=0}^{n-1}i^2=\frac{n(n-1)(2n-1)}{6}$; üst sınır $n$ ise $\frac{n(n+1)(2n+1)}{6}$.
  - Küpler: $\sum_{i=1}^{n}i^3=\left(\frac{n(n+1)}{2}\right)^2$.
  - Sonlu geometrik seri ($x\neq1$): $\sum_{i=0}^{n-1}x^i=\frac{x^n-1}{x-1}$; sonsuz seri ($-1<x<1$): $\sum_{i=0}^{\infty}x^i=\frac{1}{1-x}$. $x>1$ ise sonsuz toplam sonsuza gider.
  - Logaritma kuralları: çarpım toplamaya, bölüm çıkarmaya döner, üs başa gelir; $a^{\log_b c}=c^{\log_b a}$; taban değiştirme yapılabilir.
- Büyük O (order) gösterimi
  - $O(n^2)$: döngü en fazla $n^2$ mertebesinde döner demektir. En yüksek dereceli terim alınır, küçük terimler ihmal edilir.
  - Değer analizi ile order farklıdır: `T=T+i` yazınca $T$'nin değeri $n^4$ mertebesine çıkabilir ama döngü yine $n^3$ kez döner.
- Derste çözülen döngü örnekleri (ekrandan, 00:20:00 - 01:35:00)
  - Tek döngü `for i=1:N`: `T=T+1` ise $N$; `T=T+2` ise $2N$; `T=T+i` ise $\frac{N(N+1)}{2}$; `T=T+2i` ise $N(N+1)$; `T=T+T` ise başlangıç `T=0` için $0$, `T=1` için $2^N$.
  - `for i=1:N`, `for j=1:N*N`: `T+1` → $N^3$; `T+i` → $\frac{N^3(N+1)}{2}$; `T+j` → $\frac{N^5+N^3}{2}$; order $O(N^3)$.
  - `for j=1:i*i`: `T+1` → $\frac{N(N+1)(2N+1)}{6}$; `T+i` → $\left(\frac{N(N+1)}{2}\right)^2$; `T+j` → $\frac{1}{2}\left(\sum i^4+\sum i^2\right)$; order $O(N^3)$.
  - `while (i<=N)` ve `i=i*2`: döngü $\lfloor\log_2 N\rfloor+1$ kez döner; `T+1` için order $O(\log N)$.
  - `if mod(j,i)==0` eklenince: her $i$ için koşul $i$ kez doğru, $T=\frac{N(N+1)}{2}$; `else` kolunda sayılırsa $\sum(i^2-i)$.
  - Önce `K=K*2` ile $K=2^N$, sonra `for j=1:K`: $T=N\cdot2^N$, order $O(N\cdot2^N)$.
  - `while (j<K)`, `j=j*2`, $K=2^N$: iç döngü $N$ kez döner, $T=N^2$.
  - Üç iç içe döngü (`j=1:i`, `k=1:j`): $T=\frac{N(N+1)(N+2)}{6}$, order $O(N^3)$.
  - `j=3:N` → $N(N-2)$; `j=i:N` → $\frac{N(N+1)}{2}$.
- Desen çizdiren algoritma (ekrandan, 01:50:00)
  - Bir daire üzerinde $m$ nokta düşünülür; `yi=mod(i*s,m)` ile bir sonraki nokta bulunur ve `i` ile `yi` arasına çizgi çekilir. Farklı $m$ ve $s$ değerleri farklı desenler verir.
- Rastgele sayı üretimi (C)
  - `rand()` sözde rastgele (pseudo-random) sayı üretir. Aynı başlangıç değeriyle her çalıştırmada aynı dizi gelir.
  - `srand(tohum)` başlangıç değerini (seed) değiştirir; `srand(time(NULL))` ile her çalıştırmada farklı bir tohum kullanılır. `srand` programın başında bir kez çağrılır.
  - Doğrusal eşlik üreteci: $X_{n+1}=(aX_n+c)\bmod m$.
  - $[x,y]$ aralığında tam sayı: `rand()%(y-x+1)+x`.
  - Zar simülasyonu ve histogram: atış sayısı arttıkça her yüzün frekansı birbirine yaklaşır (uniform dağılım).
- 52 kartı karıştırma
  - Yöntem 1: `visited` dizisiyle daha önce çıkmamış sayıyı yazmak. Döngü `while (i<52)` olmalıdır; kaç tur süreceği rastgeledir (derste 292, 382, 175 tur görüldü).
  - Yöntem 2: kartları sırayla diziye yerleştirip rastgele iki indisin yerini değiştirmek. Döngü sayısı sabittir.
  - Karıştırma, Quicksort'un kötü durumdan kaçınması için de kullanılır.
- İki uniform sayının toplamıyla çan biçimli dağılım
  - 1-99 arası iki sayının toplamı 2-198 arasındadır. Ortadaki toplamlar çok sayıda ikiliyle oluşur, uçtakiler az ikiliyle.
  - Kod: `dizi[s1+s2]++` ve yıldızlı histogram.
- Rastgele gezen robot
  - `if`/`switch`li çözüm: 4 yön için 4 `case`.
  - `if`siz çözüm: yön değişimlerini $(0,1),(0,-1),(-1,0),(1,0)$ gibi bir tabloda tutmak. 8 yön için yalnız tablo büyür.
- Monte Carlo ile $\pi$
  - $[0,1]\times[0,1]$ karesine rastgele noktalar atılır, $x^2+y^2<1$ olanlar sayılır. $\frac{say}{N}\to\frac{\pi}{4}$, dolayısıyla $T=4\cdot\frac{say}{N}\to\pi$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Toplam formülleri
  - $\frac{n(n+1)}{2}$ mutlaka bilinmeli; kareler ve küpler toplamı da akılda tutulmalı. Daha yüksek kuvvetlerin açılımı ezberlenmez.
- Sınırları ve artış miktarını doğru belirlemek
  - Döngü birer birer artmıyorsa (örneğin `i=i*2`) üst sınır $N$ değil, tekrar sayısıdır ($\log_2 N$ mertebesi).
  - `i` ikişer katına çıkarken `T=T+i` yazılırsa toplama eklenen terimler $1,2,4,8,\dots$ olur; bu $\sum i$ değil $\sum 2^i$'dir.
- Üç döngü her zaman $O(n^3)$ demek değildir
  - İç döngü $\log n$ kez dönüyorsa $O(n^2\log n)$ gibi sonuçlar çıkabilir. Artışlar açıkça yazılarak hesaplanmalıdır.
- `srand` ve kütüphaneler
  - `srand` bir kez çağrılmalıdır. `rand`/`srand` için `stdlib.h`, `time` için `time.h` eklenmelidir; derleyici eklemeden çalıştırsa bile eklemek doğrudur.
- Karıştırmada `for` yerine `while`
  - Daha önce çıkmış sayı tekrar gelebileceği için 52 turluk `for` bütün kartları doldurmaz.
- Sınav tipi soru
  - "Bu kod çalışınca `T` değeri ne olur?" sorusu sözde kod ya da akış diyagramıyla sorulur (Monte Carlo örneği).

## Kısa Tekrar Notları

- Değer analizi = değişkenin son değeri; karmaşıklık analizi = tekrar sayısı.
- İç içe toplamda önce içteki toplam çözülür; dış değişkene bağlı olmayan terim sabittir, dışarı alınır.
- $\sum_{i=1}^{n}1=n$, $\sum i=\frac{n(n+1)}{2}$, $\sum i^2=\frac{n(n+1)(2n+1)}{6}$, $\sum i^3=\left(\frac{n(n+1)}{2}\right)^2$.
- Terim sayısı = son terim − ilk terim + 1 (birer artışta). Örneğin `j=i:N` için $N-i+1$.
- `i=i*2` döngüsü $\lfloor\log_2 N\rfloor+1$ kez döner.
- `T=T+T` ($T=1$) çarpım sembolüyle yazılır: $\prod_{i=1}^{N}2=2^N$.
- `rand()%k` → $0..k-1$; `rand()%6+1` → zar.
- `srand(time(NULL))`: tohum = 1970'ten beri geçen saniye.
- Histogramla dağılım gözlenir; deney sayısı arttıkça frekanslar beklenen değere yaklaşır.
- Kart karıştırma: ziyaret dizisi (yavaş, tur sayısı belirsiz) ya da sırayla yerleştirip takas (hızlı, tur sayısı sabit).
- Robot: yön tablosu kullanmak `if`/`switch` sayısını ortadan kaldırır.
- Monte Carlo: $\pi\approx4\cdot\frac{say}{N}$.

## Detaylı Açıklamalar

- Değer analizinde döngüdeki güncelleme toplam sembolüne çevrilir. Örneğin `for i=1:N; for j=1:i*i; T=T+1;` için $T=\sum_{i=1}^{N}\sum_{j=1}^{i^2}1$. İçteki toplam $i^2$'dir, dıştaki toplam $\sum_{i=1}^{N}i^2=\frac{N(N+1)(2N+1)}{6}$ olur. Aynı yapıda `T=T+i` yazılırsa içteki toplam $i\cdot i^2=i^3$ olur ve $T=\left(\frac{N(N+1)}{2}\right)^2$ bulunur. Order her iki durumda da döngü sayısına bağlıdır ve $O(N^3)$'tür.
- `while` döngüsünde değişken çarpılarak büyüyorsa önce tekrar sayısı bulunur. `i=1; while (i<=N) { T=T+1; i=i*2; }` için $i$ değerleri $2^0,2^1,\dots,2^k$'dir ve $2^k\le N$ olduğu sürece döngü devam eder. Buradan $k\le\log_2N$ ve tekrar sayısı $\lfloor\log_2N\rfloor+1$ çıkar. `T=T+i` yazılırsa eklenen değerler $1,2,4,\dots$ olduğundan $T=\sum_{i=0}^{k}2^i=2^{k+1}-1$ olur; $N$ ikinin kuvvetiyse $T=2N-1$.
- Sonlu geometrik serinin formülü derste şöyle türetildi: $T=a^0+a^1+\dots+a^n$ yazılır, iki taraf $a$ ile çarpılıp farkı alınır, $T(a-1)=a^{n+1}-1$ ve $T=\frac{a^{n+1}-1}{a-1}$ bulunur. Benzer biçimde $\sum i\,a^i$ için $T-aT$ farkı kullanılır.
- `if mod(j,i)==0` içeren örnekte tabloyla örüntü aranır: $i=1$ için $j=1$, $i=2$ için $j=2,4$, $i=3$ için $j=3,6,9$, $i=4$ için $j=4,8,12,16$ koşulu sağlar. Her $i$ için $i$ değer sayıldığından $T=\sum i=\frac{N(N+1)}{2}$. `else` kolu sayılırsa "tüm durum eksi aksi durum" mantığıyla $\sum_{i=1}^{N}(i^2-i)=\frac{N^3-N}{3}$ elde edilir.
- C'de `rand()` gerçek rastgele değildir: bir başlangıç değeri $X_0$'dan $X_{n+1}=(aX_n+c)\bmod m$ gibi bir kuralla sonraki değerler üretilir. Tohum aynı kaldıkça dizi aynıdır. `srand(10)` gibi sabit bir tohum diziyi değiştirir ama her çalıştırmada yine aynı diziyi verir. `srand(time(NULL))` her saniye değişen bir tohum kullanır.
- $[x,y]$ aralığında sayı üretmek için önce $y-x+1$'e göre mod alınır ($0..y-x$), sonra $x$ eklenir. Örnek: $x=2,y=8$ için `rand()%7+2` sonucu $2..8$ arasındadır.
- Kart karıştırmanın ilk yönteminde `visited[r]==0` ise `dizi[i]=r`, `visited[r]=1`, `i++` yapılır. Döngü `while (i<52)` ile kurulur. Son kartlara doğru boş yer bulmak zorlaştığı için tur sayısı 52'yi çok aşar. İkinci yöntemde `dizi[i]=i` ile sıralı dizi kurulur, sonra 52 kez rastgele `r` ve `c` indisleri seçilip `dizi[r]` ile `dizi[c]` takas edilir.
- İki uniform sayının toplamında, toplamı ortadaki bir değere eşit olan ikili sayısı uçtakilerden çok fazladır. Bu yüzden histogram ortada yüksek, uçlarda alçak bir çan biçimi alır. Derste dizi boyutu 199'dan 51'e, mod değeri 99'dan 25'e indirilerek ve sayılar 100'e bölünerek görüntü netleştirildi.
- Monte Carlo örneğinde $[0,1]$ aralığındaki $x,y$ noktaları birim karenin içine düşer. $x^2+y^2<1$ olanlar çeyrek dairenin içindedir. Çeyrek dairenin alanı $\frac{\pi}{4}$, karenin alanı $1$ olduğundan çok sayıda atışta $\frac{say}{N}\approx\frac{\pi}{4}$ ve $4\cdot\frac{say}{N}\approx\pi$ olur. Derste $N$ 10'un kuvvetleri olarak artırıldı ve sonuç 2.8, 3.24, 3.14 gibi değerlerden $\pi$'ye yaklaştı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
