# Ders 20 Çalışma Özeti

## Genel Konular

- Özyinelemeli fonksiyonların karmaşıklığı: kısa tekrar (ekrandan, 00:10:00 - 00:25:00)
  - Sonsuz çağrıyı önlemek için temel durum yazılır: `if(N==0) return;`.
  - `func1`: yalnız karşılaştırma ve `func(N-1)` çağrısı. $T(N)=1+T(N-1)$, $T(0)=1$, sonuç $O(N)$: $N$ çağrı, her çağrıda bir birim iş.
  - `func2`: çağrıdan önce $N$ kez dönen bir `for` döngüsü. $T(N)=N+T(N-1)$, sonuç $O(N^2)$.
  - `func3`: döngü `for(i=1;i<=N;i*=2)`, yani $1,2,4,8,\dots,2^k$; döngü yaklaşık $\log_2 N$ kez döner. $T(N)=\log_2 N+T(N-1)$, sonuç $O(N\log N)$.
  - `func4`: $N$ kez dönen döngü ve iki ayrı `func4(N-1)` çağrısı. $T(N)=N+2T(N-1)$, üstel ($2^N$ mertebesinde) karmaşıklık. Mesaj sayısı $N=3$ için $11$, $N=10$ için $2036$ (ekranda sayaçla gösterildi; ajan da derleyip doğruladı).
  - Özyinelemeli Fibonacci (ekrandan, 00:20:00): `if(N==0) return 0; if(N==1) return 1; return fib(N-1)+fib(N-2);`. $T(N)=1+T(N-1)+T(N-2)$; yazması kolay, karmaşıklığı kötü.
- Özyinelemeli bağıntıyı koddan okumak ve özyineleme ağacıyla çözmek
  - $T(n)=aT(n/b)+f(n)$ biçiminde: $a$ ağacın her düğümündeki dal sayısını (fonksiyonun kendini kaç kez çağırdığını), $b$ ağacın ne hızla derinleştiğini, $f(n)$ her çağrıdaki ek maliyeti verir.
  - Yöntem: her seviyedeki toplam maliyet yazılır, toplam sembolüne çevrilir, ağacın yüksekliği $h$ bulunur, geometrik seri formülüyle kapalı biçime getirilir.
  - Kullanılan seri formülü: $\sum_{i=0}^{h} a^i=\dfrac{a^{h+1}-1}{a-1}$; $|a|<1$ ve sonsuz toplamda $\dfrac{1}{1-a}$.
- Bölerek gelen örnekler (divide and conquer)
  - $T(n)=2T(n/4)+n$ (ekrandan, 00:35:00): seviye maliyetleri $n, n/2, n/4, \dots$; $h=\log_4 n$; $T(n)=2n-\sqrt n=O(n)$.
  - $T(n)=8T(n/2)+n$ (ekrandan, 00:40:00): seviye maliyetleri $n,4n,16n,\dots$; $h=\log_2 n$; $T(n)=\frac{n}{3}(4n^2-1)=O(n^3)$.
  - $T(n)=8T(n/2)+n^2$ (ekrandan, 00:50:00): seviye maliyetleri $n^2,2n^2,4n^2,\dots$; $T(n)=n^2(2n-1)=O(n^3)$.
  - $T(n)=8T(n/2)+1$: slaytta sonuç $O(n^3)$ olarak verildi, çözümü alıştırma olarak bırakıldı (ekrandan, 00:50:00).
  - $T(n)=4T(n/3)+1$ (ekrandan, 01:10:00): seviyelerde $1,4,16,\dots$ birim; $h=\log_3 n$; $T(n)=O(n^{\log_3 4})\approx O(n^{1.26})$.
  - $T(n)=9T(n/3)+1$ (ekrandan, 01:15:00): $\sum_{i=0}^{h}9^i=\frac{9n^2-1}{8}=O(n^2)$.
  - $T(n)=4T(n/3)+n$ (ekrandan, 01:20:00): $n\sum_{i=0}^{h}(4/3)^i$, $h=\log_3 n$; sonuç $O(n^{\log_3 4})\approx O(n^{1.26})$.
- Azaltarak gelen örnekler (decrease and conquer)
  - $T(n)=2T(n-1)+1$ (ekrandan, 01:25:00): seviyelerde $1,2,4,\dots$; ağaç $n$ derinliğe iner; $T(n)=2^{n+1}-1=O(2^n)$.
  - $T(n)=T(n-1)+T(n-2)$ (Fibonacci, ekrandan, 01:30:00): ağaç dengesizdir, sol kol daha derine iner. Bu derste çözülmedi; sonucu $O(\varphi^n)$, $\varphi=\frac{1+\sqrt5}{2}\approx1.618$ (altın oran), kabaca $2^n$ diye verildi.
- Fibonacci için daha hızlı algoritmalar
  - İteratif çözüm: iki değişkenle tek döngü, $O(n)$.
  - Matris yöntemi (ekrandan, 01:35:00 - 01:40:00): $F=\begin{bmatrix}1&1\\1&0\end{bmatrix}$, $F^n=\begin{bmatrix}f(n+1)&f(n)\\f(n)&f(n-1)\end{bmatrix}$. Hızlı üs alma ($a^n=a^{n/2}\cdot a^{n/2}$) ile $F^n$ sabit sayıda işlemli $2\times2$ çarpımlarla $O(\log_2 n)$ zamanda bulunur.
- Flood fill (taşırma) algoritması
  - Paint'teki boya kovası: bir piksele dokunulur, aynı renkteki bağlı bölgenin tamamı boyanır.
  - Sağa, sola, yukarı, aşağı giden `while` döngüleriyle iteratif çözüm yalnız düz çizgileri boyar, arada boşluk kalır. Özyinelemeli çözümde her piksel kendi komşuları için fonksiyonu yeniden çağırır ve bölge tamamen dolar.
- Bağlı bileşen etiketleme (connected component labeling) (ekrandan, 02:05:00 - 02:20:00)
  - Görüntüdeki bağlı bölgeleri (nesneleri) bulur ve numaralar; görüntü işlemede örneğin doku görüntüsündeki bölgeleri ya da paraları saymak için kullanılır.
  - Matris iki `for` ile gezilir; etiketsiz bir `1` görülünce `etiketle` fonksiyonu yeni bir etiket numarasıyla çağrılır ve komşulara özyinelemeli yayılır.
  - 4 komşulukta örnek matriste 6, 8 komşulukta 3 bileşen bulundu. 8 komşulukta çaprazlar da bağlı sayıldığı için bileşen sayısı azalır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağıntıdaki üç parametrenin anlamı
  - Dal sayısı (fonksiyonun kendini kaç kez çağırdığı), derinleşme miktarı ($n/2$, $n/3$, $n-1$ gibi) ve her seviyedeki maliyet. Bir kod verildiğinde bunları okuyup $T(n)$ bağıntısını yazabilmek gerekir.
- Çözüm sırası
  - Önce ağacı çiz ve seviye maliyetlerini yaz, sonra toplam sembolüne çevir, sonra ağacın yüksekliğini bul, en son seri formülüyle sadeleştir.
- Temel durum
  - $n/3^h=1$ eşitlemesi temel durumdur: problem küçüle küçüle $1$'e (ya da $0$'a) iner. Merge Sort'ta tek elemanlı dizi temel durumdur. $n-h$ biçiminde azalan ağaçta $n-h=0$ almak hesabı kolaylaştırır.
- Problem küçülürken maliyet artmaz
  - $f(n)=1$ ise $n/3$, $n/9$ için de maliyet $1$'dir; sabit maliyet veri boyutuna bağlı değildir.
- Özyinelemeli Fibonacci kötü bir çözümdür
  - Aynı alt değerler (örneğin $f(1)$, $f(2)$) defalarca yeniden hesaplanır. 10. sayı için iteratif çözüm yaklaşık 10 adım, özyinelemeli çözüm yaklaşık $2^{10}=1024$ adım ister.
- $T(n)$ ile $O(\cdot)$ farkı
  - $T(n)$ algoritmanın $n$'e bağlı çalışma zamanı fonksiyonudur (iteratifte de özyinelemelide de). $O(\cdot)$ bu fonksiyonun mertebesini gösteren gösterimdir; ikisi arasında denklem ilişkisi yoktur.
- Sabit katsayılar atılır
  - $n/2$, $n/3$ gibi sabitle bölünmüş terimler yine $O(n)$'dir; matris çarpımındaki 12 işlem gibi sabitler de atılır.

## Kısa Tekrar Notları

- Kendini bir kez çağıran, her çağrıda sabit iş yapan fonksiyon: $O(n)$; her çağrıda $n$ iş yapan: $O(n^2)$; her çağrıda $\log n$ iş yapan: $O(n\log n)$.
- Kendini $n-1$ için iki kez çağıran fonksiyon üsteldir: $T(n)=2T(n-1)+1=O(2^n)$.
- $T(n)=2T(n/4)+n=O(n)$; $T(n)=8T(n/2)+n=O(n^3)$; $T(n)=8T(n/2)+n^2=O(n^3)$; $T(n)=8T(n/2)+1=O(n^3)$.
- $T(n)=4T(n/3)+1=O(n^{\log_3 4})$; $T(n)=9T(n/3)+1=O(n^2)$; $T(n)=4T(n/3)+n=O(n^{\log_3 4})$; $\log_3 4\approx1.26$.
- Ağaç yüksekliği: $n/b^h=1\Rightarrow h=\log_b n$; $n-h=0\Rightarrow h=n$.
- Logaritma kuralı: $a^{\log_b n}=n^{\log_b a}$ (örneğin $4^{\log_2 n}=n^2$, $9^{\log_3 n}=n^2$).
- Fibonacci: özyinelemeli $O(\varphi^n)$, iteratif $O(n)$, matris üssüyle $O(\log n)$.
- Çalışma süresi tahmini: $n=1000$ için 1 ms süren kod, $n=2000$ için $O(1)$'de 1 ms, $O(n)$'de 2 ms, $O(n^2)$'de 4 ms, $O(n^3)$'te 8 ms sürer.
- Flood fill bir noktadan başlayıp bağlı bölgeyi boyar; bağlı bileşen etiketleme bütün bağlı bölgeleri bulup numaralar. İkisi de özyinelemeli komşu ziyaretine dayanır.

## Detaylı Açıklamalar

- Koddan bağıntıya
  - `func4` örneğinde (ekrandan, 00:15:00) fonksiyon $N$ kez mesaj yazar, sonra `func4(N-1)`'i iki kez çağırır. İlk çağrı zinciri tamamen bitmeden ikinci çağrıya geçilmez. $N=3$ için sıra şöyledir: 3 mesaj, `func4(2)` içinde 2 mesaj, `func4(1)` içinde 1 mesaj, sonra geri dönüşlerde aynı alt çağrılar ikinci kez çalışır; toplam 11 mesaj. Bağıntı $T(N)=N+2T(N-1)$ olur.
  - Fibonacci kodunda iki temel durum ($N=0$ ve $N=1$) vardır. `fib(3)` sonucu $2$, `fib(8)` sonucu $21$'dir (dizinin sıfırıncı terimi $0$ alınır). `F4` çağrısı izlenince `F2`, `F1`, `F0` gibi değerlerin farklı dallarda yeniden hesaplandığı görülür; iki çağrı yapan fonksiyon iki kollu bir ağaç gibi derinleşir.
  - Dersin başında $f(n)=n$ ve iki tane $T(n/4)$ içeren bir kod taslağı yazıldı: döngü `for(i=0;i<n;i++)`, ardından `g(n/4); g(n/4);`. Ekranda ayrıca iç içe iki döngü ve sekiz `g(N/2)` çağrısı içeren bir taslak gösterildi (ekrandan, 00:45:00); bu, $8T(n/2)+n^2$ bağıntısına karşılık gelir.
- $T(n)=2T(n/4)+n$ çözümü (ekrandan, 00:25:00 - 00:35:00)
  - Seviye 0: 1 adet $n$, maliyet $n$. Seviye 1: 2 adet $n/4$, toplam $n/2$. Seviye 2: 4 adet $n/16$, toplam $n/4$. Seviye 3: 8 adet $n/64$, toplam $n/8$.
  - $T(n)=n\left(1+\frac12+\frac14+\dots\right)=n\sum_{i=0}^{\log_4 n}\left(\frac12\right)^i$.
  - Seri formülüyle $T(n)=2n\left(1-2^{-(\log_4 n)-1}\right)=2n\left(1-\frac{1}{2\sqrt n}\right)=2n-\sqrt n=O(n)$.
- $T(n)=8T(n/2)+n$ çözümü (ekrandan, 00:40:00)
  - 1 adet $n$, 8 adet $n/2$ (toplam $4n$), 64 adet $n/4$ (toplam $16n$), 512 adet $n/8$ (toplam $64n$).
  - $T(n)=n\sum_{i=0}^{\log_2 n}4^i=n\cdot\frac{4^{\log_2 n+1}-1}{3}=\frac n3\left(4n^{\log_2 4}-1\right)=\frac n3(4n^2-1)=O(n^3)$.
- $T(n)=8T(n/2)+n^2$ çözümü (ekrandan, 00:50:00)
  - 1 adet $n^2$, 8 adet $(n/2)^2$ (toplam $2n^2$), 64 adet $(n/4)^2$ (toplam $4n^2$).
  - $T(n)=n^2\sum_{i=0}^{\log_2 n}2^i=n^2\left(2\cdot2^{\log_2 n}-1\right)=n^2(2n-1)=O(n^3)$.
- $T(n)=4T(n/3)+1$ ve $T(n)=9T(n/3)+1$ (ekrandan, 01:10:00 ve 01:15:00)
  - İlkinde seviyelerde $1\cdot1$, $4\cdot1$, $16\cdot1$ birim vardır; $T(n)=\sum_{i=0}^{h}4^i=\frac{4\cdot4^h-1}{3}$. $n/3^h=1$ alınınca $h=\log_3 n$ ve $4^{\log_3 n}=n^{\log_3 4}$; sonuç $O(n^{\log_3 4})$, üs yaklaşık $1.26$.
  - İkincisinde dallanma 9'dur: $1+9+81+729+\dots=\sum_{i=0}^{h}9^i=\frac{9\cdot9^{\log_3 n}-1}{8}=\frac{9n^2-1}{8}=O(n^2)$.
- $T(n)=4T(n/3)+n$ (ekrandan, 01:20:00)
  - Seviyeler: $n$, $4\cdot\frac n3$, $16\cdot\frac n9$, $64\cdot\frac n{27}$. Toplam $n\left(1+\frac43+\frac{16}9+\frac{64}{27}+\dots\right)=n\sum_{i=0}^{\log_3 n}\left(\frac43\right)^i$.
  - Payda $\frac43-1=\frac13$ olur; sadeleştirince sonuç $n^{\log_3 4}$ mertebesindedir. Hesap makinesiyle $\log_3 4\approx1.26$ bulundu.
- Azaltarak giden ağaç: $T(n)=2T(n-1)+1$ (ekrandan, 01:25:00)
  - Her düğümde 1 birim iş vardır. Seviyelerde $1,2,4,\dots$ düğüm; ağaç $n$'den $n-1$, $n-2$, ..., $n-h$'ye iner. $n-h=0$ alınca $h=n$.
  - $T(n)=\sum_{i=0}^{n}2^i=\frac{2^{n+1}-1}{2-1}=2\cdot2^n-1=O(2^n)$.
- Fibonacci için matris yöntemi (ekrandan, 01:35:00 - 01:40:00)
  - $F^2=\begin{bmatrix}1&1\\1&0\end{bmatrix}\begin{bmatrix}1&1\\1&0\end{bmatrix}=\begin{bmatrix}2&1\\1&1\end{bmatrix}$, $F^3=\begin{bmatrix}2&1\\1&1\end{bmatrix}\begin{bmatrix}1&1\\1&0\end{bmatrix}=\begin{bmatrix}3&2\\2&1\end{bmatrix}$. Sol üst eleman $f(n+1)$'dir.
  - $2\times2$ matris çarpımı için üç iç içe döngü gerekmez; dört ifade yeterlidir: $\begin{bmatrix}a&b\\c&d\end{bmatrix}^2=\begin{bmatrix}a^2+bc&ab+bd\\ac+cd&bc+d^2\end{bmatrix}$.
  - Daha önce derste gösterilen hızlı üs alma ($a^n=a^{n/2}\cdot a^{n/2}$) burada sayı yerine matrisle uygulanır. Her adım sabit sayıda (yaklaşık 12) işlemdir; toplam $O(\log_2 n)$. Zamandan kazanılır, buna karşılık biraz daha fazla bellek kullanılır.
- Bağlı bileşen etiketleme kodu (ekrandan, 02:10:00 - 02:20:00)
  - Girdi $8\times10$'luk `m` matrisidir; `label` matrisi sıfırla başlatılır (0 = etiketsiz), `component = 1`.
  - `etiketle(x, y, current_label, m, row_count, col_count, label)`: önce sınır kontrolü (`x<0 || x==row_count`, `y<0 || y==col_count`), sonra hücre zaten etiketliyse ya da `m`'de 0 ise dönüş. Aksi halde `label[x][y] = current_label;` yapılır ve $(x+1,y)$, $(x,y+1)$, $(x-1,y)$, $(x,y-1)$ için fonksiyon yeniden çağrılır.
  - 8 komşuluk sürümünde yönler diziyle verilir: `dx[] = {+1, 0, -1, 0, -1, -1, +1, +1}`, `dy[] = {0, +1, 0, -1, -1, +1, -1, +1}`; bir `for` ile 8 çağrı yapılır. Kod kısalır, karmaşıklık değişmez.
  - Ana programda `if (!label[i][j] && m[i][j]) etiketle(i, j, component++, ...);` her yeni bileşene bir sonraki numarayı verir. En büyük etiket bileşen sayısıdır.
  - Ders sonrası not: Ekranda gösterilen 4 komşuluk kodunda kontrol `label[x][y]==1` biçimindeydi (ekrandan, 02:15:00). Bu yalnız 1 numaralı bileşen için doğru çalışır; 2 ve sonraki bileşenlerde etiketli hücreye geri dönülünce çağrılar bitmez ve yığın taşar (ajan derleyip denedi, program segmentation fault verdi). Doğrusu 8 komşuluk kodundaki gibi `if (label[x][y] || !m[x][y]) return;` olmalıdır. Hoca derste bir şeyin yanlış silinmiş olabileceğini söyledi.
  - Ajan, 4 komşuluk dosyasındaki matrisi (ekrandan, 02:10:00) düzeltilmiş kontrolle `gcc -Wall` ile derleyip çalıştırdı: 4 komşulukta 6, 8 komşulukta 3 bileşen çıktı; derste görülen sayılarla aynıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
