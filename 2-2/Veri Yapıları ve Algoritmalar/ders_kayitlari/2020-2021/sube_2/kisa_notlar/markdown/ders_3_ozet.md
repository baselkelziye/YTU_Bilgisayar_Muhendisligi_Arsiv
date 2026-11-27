# Ders 3 Çalışma Özeti

## Genel Konular

- Önceki uygulama saatinden kalan iki C örneği
  - Ortalama ve standart sapma: komut satırından argüman alma (`argc`, `argv`, `atoi`), `typedef` ile tip tanımlama, kendi yazılan rastgele sayı fonksiyonu ve `math.h` içindeki `sqrt` kullanımı.
  - Yazı-tura simülasyonu: hilesiz bir parayı $N$ kez atınca $k$ tura gelme olasılığının binom dağılımına uyduğunu simülasyonla gösterme; sonuçların yıldızlarla histogram olarak basılması.
- Neden algoritma tasarlarız?
  - 600.000 kelimelik sıralı bir veri kümesinde bir kelimeyi sırayla aramak ile ikili arama (binary search) yapmak arasındaki büyük süre farkı.
  - Daha güçlü donanım almak yerine daha iyi algoritma tasarlamak.
- Algoritmanın özellikleri ve hazırlanma süreci
  - Kesin, yoruma yer bırakmayan, uygulanabilir adımlar; sonlu sayıda adımda bitme (sürekli akan veri üzerinde çalışan yöntemler istisna).
  - Süreç: tasarım, doğruluğun ispatı (validasyon), performans analizi, kodlama ve test, kullanıma alma.
- Algoritma tasarım teknikleri (stratejileri)
  - Kaba kuvvet (brute force), açgözlü (greedy), böl ve yönet (divide and conquer), azalt ve yönet (decrease and conquer), değiştir ve yönet (transform and conquer), dinamik programlama, artımlı iyileştirme (iterative improvement), geri takip (backtracking).
- OBEB (en büyük ortak bölen, gcd) bulma
  - Ortaokul yöntemi (asal çarpanlara ayırıp ortakları çarpma) ile Öklid algoritmasının karşılaştırılması; Öklid algoritmasının adımları ve akış diyagramı.
- $n$'ye kadar olan asal sayıları bulma
  - Her sayıyı önceki asallara bölmeyi deneyen temel (baseline) yöntem, $\sqrt{n}$'e kadar bakma iyileştirmesi ve Eratosthenes'in eleği (Sieve of Eratosthenes).
  - Aynı algoritmanın iki farklı akış diyagramı ve bit düzeyinde yer tasarrufu fikri.
- Sıralama problemi ve basit sıralama algoritmaları
  - Sıralama probleminin formal tanımı; eşit elemanların sırasının korunup korunmamasının algoritma seçimini etkilemesi.
  - Seçmeli sıralama (Selection Sort), kabarcık sıralama (Bubble Sort), kabuk sıralama (Shell Sort, yalnız sözlü) ve eklemeli sıralama (Insertion Sort); karşılaştırma ve yer değiştirme sayıları.
- Öğrenci sorusu üzerine: derlenen (compiled) ve yorumlanan (interpreted) diller arasındaki fark.

## Hocanın Özellikle Vurguladığı Kısımlar

- Aynı problemi çözen farklı algoritmalar arasındaki fark, donanımı güçlendirerek kapatılamayacak kadar büyük olabilir.
  - Sırayla arama yaklaşık 166 saat sürerken ikili arama yaklaşık 20 saniyede aynı sonucu verir. 10 kat güçlü bilgisayar sırayla aramayı yalnız yaklaşık 16 saate indirir.
- Bir yöntemin algoritma sayılabilmesi için her adımın kesin ve uygulanabilir olması gerekir.
  - Ortaokuldaki OBEB yöntemi bu yüzden algoritma sayılmaz: "asal çarpanları bul" ve "ortakları bul" adımlarının nasıl yapılacağı tanımlı değildir.
- Algoritmanın sonlu adımda bittiği gösterilmelidir.
  - Öklid algoritmasında her adımda mod alındığı için $n$ küçülür ve sonunda 0 olur.
- Eratosthenes'in eleğinde iki önemli fikir vardır:
  - Bulunan her asalın katlarını ileriye doğru silmek (geriye dönük bölme kontrolü yapmamak).
  - Yalnız $\sqrt{n}$'e kadar olan sayılar için silme yapmanın yeterli olması.
- Aynı algoritmanın birden fazla akışı, birden fazla gerçeklemesi olabilir. Biri daha kolay anlaşılır, diğeri daha az yer kaplar ya da daha hızlı çalışır.
- Sıralama probleminin bile varyasyonları vardır. Eşit elemanların girdideki sırasının korunması isteniyorsa bazı hızlı algoritmalar (hocanın örneği: quicksort) kullanılamaz.
- Yalnız toplam karmaşıklığa değil, karşılaştırma ve yer değiştirme (bellek ya da disk erişimi) sayılarına da bakılmalıdır.
  - Yer değiştirme pahalıysa $N$ yer değiştirme yapan Selection Sort daha uygun olabilir.
- Insertion Sort, dizi kısmen sıralıysa çok karşılaştırmadan kurtarır. Ters sıralı dizide ise en kötü davranışı gösterir.
  - Başka bir algoritmayla sıralayıp az eleman kalınca Insertion Sort'a geçmek toplam performansı artırır.
- Çalışma önerisi: derste gösterilen algoritmaları kendiniz kodlayın, farklı girdilerle deneyin, her adımda ara durumları yazdırarak nasıl çalıştığını gözlemleyin.

## Kısa Tekrar Notları

- `typedef float Number;` ile yeni bir tip adı tanımlanır. Bu kısa yol ileride struct'larla (bağlı liste, yığıt) sık kullanılacak.
- Standart sapma: $\sigma = \sqrt{\overline{x^2} - \bar{x}^2}$.
- Hilesiz parayı $N$ kez atınca $k$ tura gelme olasılığı: $\binom{N}{k}\dfrac{1}{2^N}$.
- 600.000 kelimede sırayla arama $\approx 600.000$ saniye $\approx 166$ saat; ikili arama $\log_2 600.000 \approx 20$ saniye.
- Tasarım teknikleri ve derste verilen örnekleri:
  - Kaba kuvvet: Selection Sort, şifre kırma.
  - Açgözlü: Prim (minimum kapsayan ağaç), Dijkstra (en kısa yol).
  - Böl ve yönet: Merge Sort. Azalt ve yönet: Insertion Sort. Değiştir ve yönet: Heap Sort.
  - Dinamik programlama: Fibonacci'yi doğrusal karmaşıklıkla hesaplama.
  - Artımlı iyileştirme: Newton yöntemiyle kök bulma. Geri takip: sudoku çözme.
- Öklid: $\gcd(m,n) = \gcd(n,\ m \bmod n)$, $n = 0$ olunca sonuç $m$.
  - $\gcd(60,24)=12$; $\gcd(1785,546)=21$ (5 mod işlemi).
- Eratosthenes'in eleği: $p = 2 \ldots \lfloor\sqrt{n}\rfloor$ için $A[p] \neq 0$ ise $p^2$'den başlayıp $p$'şer artarak katları sıfırla. 100'e kadar 25 asal kalır.
- Sıralama: girdinin öyle bir permütasyonu bulunur ki $a'_1 \le a'_2 \le \dots \le a'_n$ olur.
- Selection Sort: yaklaşık $N^2/2$ karşılaştırma, $N$ yer değiştirme (her durumda).
- Bubble Sort: ikili komşu karşılaştırma; her dış turda kalanların en büyüğü sona gider; $O(n^2)$; yer değiştirme sayısı girdiye bağlı.
- Shell Sort: uzaktaki elemanları belirli aralıklarla karşılaştırarak elemanları daha hızlı yerine taşır.
- Insertion Sort: sıradaki eleman (anahtar), sıralı kısımda sağdan sola karşılaştırılarak yerine sokulur; yaklaşık $N^2/2$ karşılaştırma ve yer değiştirme, kısmen sıralı dizilerde çok daha az.
- Derlenen dil: kaynak kod derlenir, kütüphanelerle bağlanır (link), makine diline çevrilip çalıştırılabilir dosya üretilir. Yorumlanan dil: kod çalışma anında satır satır işletilir, hata ancak o satıra gelince fark edilir.

## Detaylı Açıklamalar

- **Ortalama ve standart sapma örneği.** Program $N$'yi komut satırından alır (`N = atoi(argv[1])`). Kendi yazılan `randNum()` fonksiyonu `1.0*rand()/RAND_MAX` ile 0-1 arasında bir sayı döndürür. Döngüde her sayı için `m1 += x/N` ve `m2 += x*x/N` toplanır. Böylece `m1` ortalamayı, `m2` karelerin ortalamasını tutar. Standart sapma `sqrt(m2 - m1*m1)` ile bulunur (ekrandan, 00:10:00). Kod birkaç satır olmasına rağmen tip tanımlama, fonksiyon yazma, komut satırından argüman alma ve matematik kütüphanesi kullanmayı bir arada gösterir.

  ```c
  #include <math.h>
  #include <stdlib.h>
  #include <stdio.h>

  typedef float Number;

  Number randNum (){
     return 1.0*rand()/RAND_MAX;
  }

  int main(int argc, char *argv[]){
     int i, N = atoi(argv[1]);
     float m1 = 0.0, m2 = 0.0;
     Number x;

     for (i = 0; i < N; i++){
        x = randNum();
        m1 += ((float) x)/N;
        m2 += ((float) x*x)/N;
     }

     printf(" Average: %f\n", m1);
     printf("Std.Dev.: %f\n", sqrt(m2-m1*m1));
  }
  ```

  - Ders sonrası not: Kod `gcc -Wall ... -lm` ile uyarısız derlendi ve `N = 100000` ile çalıştırıldı. Ortalama yaklaşık 0,4999, standart sapma yaklaşık 0,2886 çıktı. Bu, 0-1 arası düzgün dağılımın kuramsal değerleriyle ($0{,}5$ ve $1/\sqrt{12} \approx 0{,}2887$) uyumludur.
  - Hoca, kullanıcının sayı dışında bir şey girmesine karşı kontrol yapılması gerekebileceğini, ama bu basit örnekte yapılmadığını belirtti.

- **Yazı-tura simülasyonu.** $N$ kez atılan hilesiz parada $k$ tura görme olasılığı $\binom{N}{k}/2^N$'dir ve büyük $N$ için normal dağılıma yaklaşır. Program `heads()` adlı tek satırlık bir fonksiyon kullanır: `rand()` değeri `RAND_MAX/2`'den küçükse 1 (tura), değilse 0 döndürür. Komut satırından $N$ ve $M$ (deney sayısı) okunur, $N+1$ elemanlı bir sayaç dizisi için yer ayrılıp sıfırlanır. Her deneyde para $N$ kez atılır, tura sayısı bulunup o sayının sayacı artırılır. Sonunda her tura sayısı için her 10 deneye bir yıldız basılır. <!-- BELİRSİZ: yazı-tura kodunun slaydı karelerde yok; kod yapısı altyazıdan aktarıldı. -->
  - Ekrandaki çıktıda (ekrandan, 00:15:00) $N=32$, $M=1000$ için en uzun yıldız satırı 16 turada, 15 ve 17'de biraz daha kısa; uçlara doğru yıldız kalmıyor. $N=16$, $M=1000$ için en yüksek değerler 8 civarında ve dağılım daha geniş görünüyor.
  - Hoca, $M$'yi 10, 100, 1000 diye artırarak deneme sayısı arttıkça dağılımın normal dağılıma daha çok yaklaştığının gözlenebileceğini söyledi.

- **Neden algoritma tasarlarız?** Her satırda 10 kelime olan 20 satırlık 3000 mektup, toplam 600.000 kelime eder. Kelimeler A'dan Z'ye sıralı tutuluyor ve her karşılaştırma 1 saniye sürüyor (ekrandan, 00:20:00). Belirli bir adın geçtiği yerleri bulmak için ilk akla gelen yöntem baştan sona sırayla bakmaktır. Aranan kelime bulunduktan sonra bile yöntem sona kadar devam eder ve toplam 600.000 saniye (yaklaşık 166 saat) sürer. Daha akıllı yöntem, sıralı dizinin ortasına bakmaktır. Aranan kelime ortadakinden küçükse sağ yarının tamamı atılır, sonra kalan yarının ortasına bakılır. Arama uzayı her adımda yarıya indiği için yaklaşık $\log_2 600.000 \approx 20$ karşılaştırma yeterlidir. Hoca sondaki birkaç komşu kelimeye bakmayı da ekleyerek yaklaşık 20-25 saniye dedi.
  - Ders sonrası not: Hoca 166 saati "bir haftadan fazla" diye yorumladı. 166 saat yaklaşık 6,9 gündür, yani bir haftaya yakın ama bir haftadan biraz azdır.

- **Algoritma tasarım teknikleri** (ekrandan, 00:30:00):
  - *Kaba kuvvet:* problem hakkında hiçbir ön bilgi kullanmadan bütün olasılıkları sırayla dener. Şifre kırmada bütün anahtarları tek tek denemek; Selection Sort.
  - *Açgözlü:* her adımda o an en iyi görünen seçimi yapar, geçmişi ve geleceği düşünmez. Prim algoritması (dönemin ilerleyen haftalarında çizgelerle birlikte).
  - *Böl ve yönet:* problemi küçük parçalara böler, parçaları çözer, sonra birleştirir. Merge Sort.
  - *Azalt ve yönet:* problemi her adımda biraz küçülterek ilerler. Insertion Sort.
  - *Değiştir ve yönet:* problemi başka bir veri yapısına dönüştürüp orada daha kolay çözer. Heap Sort.
  - Dinamik programlama, artımlı iyileştirme (Newton-Raphson) ve geri takip (sudoku) yalnız adıyla tanıtıldı; hoca bunların bu dönemin kapsamında olmayacağını söyledi.

- **OBEB ve Öklid algoritması.** Ortaokul yöntemi: iki sayıyı asal çarpanlarına ayır, ortak çarpanları bul, çarp. Öklid (MÖ 300, *Elements*) yöntemi: $\gcd(m,n) = \gcd(n, m \bmod n)$, $n=0$ olana kadar (ekrandan, 00:40:00).
  - $\gcd(60,24)$: $60 \bmod 24 = 12 \Rightarrow \gcd(24,12)$; $24 \bmod 12 = 0 \Rightarrow \gcd(12,0) = 12$.
  - $\gcd(1785,546)$: $1785 \bmod 546 = 147$; $546 \bmod 147 = 105$; $147 \bmod 105 = 42$; $105 \bmod 42 = 21$; $42 \bmod 21 = 0$. Sonuç 21 (python ile doğrulandı).
  - Sözde kod ve akış (ekrandan, 00:45:00): Adım 1, $n=0$ ise $m$'yi döndür ve dur. Adım 2, $m$'yi $n$'ye böl, kalanı $r$'ye ata. Adım 3, $m \leftarrow n$, $n \leftarrow r$, Adım 1'e dön. Akış diyagramında "$n \neq 0$" koşulu doğru olduğu sürece `r ← m mod n`, `m ← n`, `n ← r` bloğu tekrarlanır, sonra $m$ yazdırılır.

- **Asal sayılar ve Eratosthenes'in eleği.** Temel yöntemde her sayı o ana kadar bulunan asallara bölünmeye çalışılır. Sayı büyüdükçe karşılaştırma sayısı da artar. Derste bir öğrencinin önerdiği gibi $\sqrt{n}$'e kadar olan asallara bakmak iyileştirir, ama yine de her sayıya geriye dönük bakılır. Elek yöntemi ise ileriye doğru süpürür: 2'nin katları silinir, sonra silinmemiş ilk sayı olan 3'ün katları, sonra 5'in, 7'nin katları. 11'in silinmemiş ilk katı $11 \cdot 11 = 121 > 100$ olduğu için orada durulur. Kalan 25 asal: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 (python ile doğrulandı).

  ```text
  Input: Integer n ≥ 2
  Output: n'den küçük eşit asal sayılar

  for p ← 2 to n do  A[p] ← p

  for p ← 2 to ⌊√n⌋ do
     if A[p] ≠ 0   //p önceden listeden silinmediyse
        j ← p * p
        while j ≤ n  do
           A[j] ← 0   // asal değil olarak işaretle
           j ← j + p
  ```

  (ekrandan, 01:15:00)
  - İkinci akışta (ekrandan, 01:25:00) dizi gözleri sayı yerine 1/0 (doğru/yanlış) tutar: `A(i) ← 1` ile ilklenir, $A(i)=1$ ise `j ← i` başlayıp `i*j < N` olduğu sürece `A(i*j) ← 0` yapılır. Bu yapı bitlerle gerçeklenirse bellekte 8-16 kat yer kazanılabilir.
  - Ders sonrası not: Hoca karmaşıklık için kabaca "$n \log n$" dedi; Eratosthenes'in eleğinin bilinen karmaşıklığı büyük olasılıkla $O(n \log \log n)$'dir.

- **Sıralama problemi.** Girdi $\{a_1, \dots, a_n\}$, çıktı $a'_1 \le a'_2 \le \dots \le a'_n$ koşulunu sağlayan bir permütasyon (ekrandan, 01:30:00). Örnek girdi `8 2 4 4 4 9 3 6` içinde üç farklı renkte 4 vardır. Tanım sırayı korumayı istemediği için 4'lerin her dizilimi doğru bir çıktıdır. Sıranın korunması isteniyorsa bu, probleme eklenen yeni bir kısıttır ve kullanılabilecek algoritmaları değiştirir.

- **Selection Sort** (ekrandan, 01:40:00): her turda kalanların en küçüğü bulunup sıradaki göze yerleştirilir. `8 5 2 6 9 3 1 4 0 7` dizisinde turların minimumları sırayla 0 (indis 8), 1 (indis 6), 2 (yerinde), 3 (indis 5), 4 (indis 7), 5 (indis 6), 6 (yerinde), 7 (indis 9), 8 (yerinde) olur (ekrandan, 01:45:00; python ile doğrulandı). Karşılaştırma sayısı yaklaşık $N^2/2$, yer değiştirme sayısı $N$'dir.
  - Ders sonrası not: Slayttaki iç döngü `for j ← (i + 1) to n` biçiminde. 0 tabanlı dizide son indis $n-1$ olduğu için doğrusu büyük olasılıkla `to n-1`'dir.

- **Bubble Sort** (ekrandan, 01:50:00): `for i ← 0 to n−2`, `for j ← 0 to n−2−i`, `A[j+1] < A[j]` ise ikisi yer değiştirir. Her dış turda kalanların en büyüğü kabarcık gibi sona gider. Aynı dizide turların sonundaki diziler: `5 2 6 8 3 1 4 0 7 9`, `2 5 6 3 1 4 0 7 8 9`, `2 5 3 1 4 0 6 7 8 9`, ... ve son turda `0 1 2 ... 9` (ekrandan, 02:10:00 ve 02:15:00; python ile doğrulandı, toplam 28 yer değiştirme). Karşılaştırma sayısı sabit ($O(n^2)$), yer değiştirme sayısı girdiye bağlıdır.

- **Insertion Sort** (ekrandan, 02:20:00): iskambil kağıtlarını elde sıralamak gibi. Sıradaki eleman anahtar olarak alınır, sıralı kısımda sağdan sola karşılaştırılır, kendinden büyükler bir sağa kaydırılır, anahtar boşalan yere konur. Kendinden küçük bir elemana gelince durulur, daha soldakilerle karşılaştırma yapılmaz. <!-- BELİRSİZ: Insertion Sort sözde kodunun slaydı karelerde yok; döngü sınırları (i 1'den n−1'e, j i−1'den başlayıp j ≥ 0 ve A[j] > key olduğu sürece) altyazıdan aktarıldı. -->
  - Aynı dizide (ekrandan, 02:35:00): 5, 2, 6, 9 az karşılaştırmayla yerleşir; 3, 1, 0 gibi sona yakın küçük değerler çok kaydırma gerektirir. Toplam 33 karşılaştırma ve 28 kaydırma yapılır (python ile sayıldı).

- **Derlenen ve yorumlanan diller.** Derleyici kaynak kodu ve kullanılan kütüphane fonksiyonlarını bir ara koda çevirir, bağlayıcı (linker) bunları birleştirir ve hedef işlemcinin makine dilinde çalıştırılabilir tek bir dosya üretir (Windows'ta `.exe`). Yorumlanan dillerde böyle bir ön derleme yoktur. Kod çalışma anında satır satır işletilir, hatalar ancak o satıra gelince ortaya çıkar. Derlenen dillerde birçok hata en baştan yakalanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
