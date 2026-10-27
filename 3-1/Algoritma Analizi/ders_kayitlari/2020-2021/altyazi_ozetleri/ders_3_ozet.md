# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin tarihi 14 Ekim 2020 Çarşamba. Ders Zoom üzerinden yapıldı.
  - Asıl anlatım yaklaşık 00:05'te başlar. 00:42 ile 00:52 arasında ve 01:34 ile 01:45 arasında ara var.
  - Aynı günün laboratuvar oturumu ayrı kayıttır (ders 4).
- Geçen haftanın tekrarı
  - `arrayMax` için en kötü durumda $7n-1$ temel işlem bulunmuştu.
  - En hızlı işlemin süresi $a$, en yavaşınınki $b$ ise süre $a(7n-1)$ ile $b(7n-1)$ arasındadır.
  - Donanım ve yazılım bu sabitleri değiştirir, büyüme derecesini (order of growth) değiştirmez.
- Büyüme derecesini etkilemeyenler
  - Sabit çarpanlar ve düşük dereceli terimler (lower-order terms).
  - Örnek: $10^2 n + 10^5$ doğrusal, $10^5 n^2 + 10^8 n$ karesel (quadratic).
- Büyük-O gösterimi (Big-O, üst sınır)
  - Tanım ve $2n+10$, $n^2$, $7n-2$, $3n^3+20n^2+5$, $3\log n+5$ örnekleri.
  - Büyük-O kuralları: en yakın üst sınırı seçmek, sabitleri yazmamak.
- Yaygın büyüme dereceleri ve örnek algoritmalar: $1$, $\log n$, $n$, $n\log n$, $n^2$, $n^3$, $2^n$, $n!$.
- Önek ortalamaları (prefix averages) örneği: $O(n^2)$ ve $O(n)$ çözümler.
- Asimptotik gösterim kuralları: toplam, çarpım, geçişlilik, $\log$ kuralı.
- Büyük-Omega (Big-Omega, alt sınır) ve Büyük-Teta (Big-Theta, sıkı sınır) gösterimleri.
- Logaritma ve üs kuralları (slayt hatırlatması).
- Slaytın son notu: sabit çarpanlar pratikte önemlidir ($30000n$ ile $3n^2$ karşılaştırması).
- Tahtada çözülen örnekler
  - $4n^2+2n \in O(n)$ yanlış olduğunun gösterimi.
  - $2n+10 \in O(n)$ ve $n \in O(2n+10)$.
  - Büyük-Omega ve Büyük-Teta grafik gösterimleri.
  - $2n+5 \in \Theta(n)$.
  - Insertion sort'un en kötü ve en iyi durum sınırları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu tür sorular her yıl sınavda çıkıyor ve sık hata yapılıyor.
  - "Görüyoruz, $O(n)$'dir" demek yetmez. Sizden eşitsizliği kurup sabitleri bularak çözümleme yapmanız istenir.
- Fonksiyona en yakın üst sınırı seçin.
  - $2n \in O(n^2)$ yanlış değildir, ama doğru ifade $2n \in O(n)$'dir.
  - Sabit yazılmaz: $3n+5 \in O(3n)$ değil, $3n+5 \in O(n)$ yazılır.
- Hangi durumu (en iyi, ortalama, en kötü) analiz ettiğinizi söyleyin. Aksi belirtilmedikçe en kötü durum beklenir.
- Alt sınır ve üst sınır aynı fonksiyonsa sıkı sınır (tight bound, $\Theta$) söylenir. En değerli ifade budur.
- Not tutun. Hoca defterleri toplayıp puanlayacağını tekrar söyledi.
- Derse katılım: Bu haftadan itibaren otomatik yoklama başlıyor. Hoca sorulara sesli cevap bekliyor; derste kimsenin cevap vermemesine sitem etti.

## Kısa Tekrar Notları

- $f(n)\in O(g(n))$: $c>0$ ve $n_0$ vardır ki $n\ge n_0$ için $f(n)\le c\,g(n)$. Üst sınır.
- $f(n)\in \Omega(g(n))$: $c>0$ ve $n_0$ vardır ki $n\ge n_0$ için $f(n)\ge c\,g(n)$. Alt sınır.
- $f(n)\in \Theta(g(n))$: $c_1,c_2>0$ ve $n_0$ vardır ki $n\ge n_0$ için $c_1 g(n)\le f(n)\le c_2 g(n)$. Sıkı sınır.
- $d$. dereceden polinom: $O(n^d)$. Sabitler ve düşük dereceli terimler atılır.
- Kurallar:
  - $d(n)\in O(f(n))$ ve $e(n)\in O(g(n))$ ise $d(n)+e(n)\in O(f(n)+g(n))$ ve $d(n)e(n)\in O(f(n)g(n))$.
  - Geçişlilik: $d\in O(f)$ ve $f\in O(g)$ ise $d\in O(g)$.
  - $p(n)$ polinom ise $\log p(n)\in O(\log n)$. Logaritmanın tabanı büyüme derecesini değiştirmez.
- Büyüme sırası: $1 < \log n < n < n\log n < n^2 < n^3 < 2^n < n!$.
- Insertion sort: en kötü durum $\Theta(n^2)$, en iyi durum $\Theta(n)$.

## Detaylı Açıklamalar

### Büyük-O örnekleri (slayt)

| $f(n)$ | Sonuç | Sabitler |
| :--- | :--- | :--- |
| $2n+10$ | $O(n)$ | $c=3$, $n_0=10$ |
| $n^2$ | $O(n)$ değil | $n\le c$ sabit bir $c$ ile sağlanamaz |
| $7n-2$ | $O(n)$ | $c=7$, $n_0=1$ |
| $3n^3+20n^2+5$ | $O(n^3)$ | $c=4$, $n_0=21$ |
| $3\log n+5$ | $O(\log n)$ | $c=8$, $n_0=2$ |

- $2n+10\le cn \Rightarrow (c-2)n\ge 10 \Rightarrow n\ge \frac{10}{c-2}$. $c=3$ için $n_0=10$.
- $n^2\le cn \Rightarrow n\le c$. $n$ değişken olduğu için hiçbir sabit $c$ bunu bütün büyük $n$'ler için sağlamaz.

### Büyüme derecesi örnekleri (derste konuşulan)

| Büyüme | Örnek |
| :--- | :--- |
| $O(1)$ | Sıralı dizide en büyük veya en küçük eleman |
| $O(\log n)$ | İkili arama (1000 elemanda yaklaşık 10 adım) |
| $O(n)$ | Sırasız dizide bir sayıdan büyük kaç eleman olduğunu sayma |
| $O(n\log n)$ | Heap sort, merge sort |
| $O(n^2)$ | Selection sort, insertion sort (en kötü durum) |
| $O(n^3)$ | Klasik matris çarpımı |
| $O(2^n)$ | $n$ elemanlı kümenin bütün alt kümeleri |
| $O(n!)$ | $n$ elemanın bütün permütasyonları |

- $n=256$ için $n^2=65536$, $n\log_2 n=2048$. Fark 32 kat.
- $n!$, $2^n$'den hızlı büyür: $5!=120$, $2^5=32$.

### Önek ortalamaları

- İlk yöntem: her $i$ için baştan $i$'ye kadar toplamı yeniden hesaplar. İç içe iki döngü, $O(n^2)$.
- İkinci yöntem: o ana kadarki toplamı saklar, her adımda yalnız yeni elemanı ekler. Tek döngü, $O(n)$.
- Hoca bunu dinamik programlamanın ve Fibonacci'deki "önceki sonucu sakla" fikrinin habercisi olarak anlattı.

### Tahtada çözülen örnekler

- **$4n^2+2n \in O(n)$ mi?**
  - $4n^2+2n\le cn \Rightarrow 4n+2\le c \Rightarrow n\le \frac{c-2}{4}$.
  - Sol tarafta değişken, sağda sabit var. Bütün büyük $n$'ler için sağlanamaz. İfade yanlıştır.
- **$2n+10 \in O(n)$:** $c=3$, $n_0=10$ ile doğrudur.
- **$n \in O(2n+10)$:** $n\le c(2n+10)$. $c=1$ için bütün $n\ge 0$'da sağlanır. İfade doğrudur.
  - Bu ikisi birlikte $2n+10\in\Theta(n)$ olduğunu gösterir.
- **Grafik gösterim:** $f(n)$ ile $c\,g(n)$ eğrilerinin kesiştiği nokta $n_0$'dır. $n_0$'dan sonra $f(n)$ hep $c\,g(n)$'nin altında kalıyorsa $g$ bir üst sınırdır.
- **$2n+5 \in \Theta(n)$:**
  - Üst sınır: $2n+5\le c_2 n$. $c_2=7$, $n_0=1$ ile sağlanır.
  - Alt sınır: $2n+5\ge c_1 n$. Örnek: $c_1=2$ bütün $n\ge 1$ için sağlar.
- **Insertion sort:** `5 7 3 1 2 4 6` dizisi üzerinde adım adım gösterildi. İkinci elemandan başlanır, her eleman soldaki sıralı kısımda yerine kaydırılır.
  - En kötü durum (tersten sıralı dizi): $O(n^2)$ ve $\Omega(n^2)$, yani $\Theta(n^2)$.
  - En iyi durum (zaten sıralı dizi): $O(n)$ ve $\Omega(n)$, yani $\Theta(n)$.
  - En iyi durum için $\Omega(1)$ demek yanlış değildir, ama en yakın alt sınır $\Omega(n)$'dir.

### Sabit çarpanlar pratikte önemlidir

- Slayt 40: A algoritması $30000n$, B algoritması $3n^2$.
- Asimptotik olarak A daha iyidir. Ama $30000n=3n^2 \Rightarrow n=10000$.
- Problem boyutu hep 10000'den küçükse karesel B algoritması daha hızlıdır.

### Ders sonrası notlar

- **$2n+5$ alt sınırı:** Hoca alt sınır için $c_1=3$, $n_0=1$ önerdi. $2n+5\ge 3n$ yalnız $n\le 5$ için doğrudur. $n\ge 6$'da bozulur. Doğru seçim $c_1\le 2$ olmalıdır (örneğin $c_1=2$ bütün $n\ge 1$ için sağlar). Sonuç, yani $2n+5\in\Theta(n)$, yine doğrudur.
- **$n^3$ polinomdur:** Hoca "$n^3$ ve $2^n$ gibi büyüme derecelerinde polinom zamanda çözme şansı yok" dedi. $n^3$ polinom zamandır. Polinom olmayan dereceler $2^n$ ve $n!$ gibi üstel ve faktöriyel derecelerdir.
- **$\Theta$ tanımında $c_1\le c_2$:** Bu şart tanımın bir parçası değil, eşitsizliğin doğal sonucudur. Tanım yalnızca $c_1,c_2>0$ ister.
- **$2^n$ ile kaba kuvvet:** Kaba kuvvet her zaman üstel değildir. Sıralı arama da bir kaba kuvvet yöntemidir ve $O(n)$'dir. Şifre kırmadaki kaba kuvvet ise anahtar uzunluğuna göre üstel büyür.
- **Altyazı hataları:** "Algoritmanizm" algoritma analizi, "Neto-Vi-i-Lot" ve "Viner search" binary search, "Gip sort" heap sort, "Mert Sort" merge sort, "Insurge Sult" insertion sort demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
