# Ders 2 Çalışma Özeti

## Genel Konular

- Algoritmaları neden analiz ederiz
  - Amaç, bir algoritmanın verilen girdiden çıktıyı kaç adımda ürettiğini (zaman) ve bunu yaparken ne kadar ek bellek harcadığını (yer) ölçmek ve algoritmaları bu ölçütlerle karşılaştırmaktır.
  - Ders slaytları R. Sedgewick ve K. Wayne'in *Algorithms, 4th Edition* kitabının "1.4 Analysis of Algorithms" bölümünden alındı; konu başlıkları: giriş, gözlemler, matematiksel modeller, büyüme derecesi sınıfları, algoritmalar kuramı, bellek (ekrandan, 00:15:00).
  - Kullanım amaçları: performansı önceden tahmin etmek, algoritmaları karşılaştırmak, bir performans garantisi vermek ve performans hatalarından (yavaş çalışan sistem, tükenen bellek) kaçınmak.
- Örnek: Ayrık Fourier Dönüşümü (DFT) ve Hızlı Fourier Dönüşümü (FFT)
  - DFT, iç içe iki döngüyle hesaplandığı için $n$ örnekli bir sinyalde yaklaşık $n^2$ adım ister; FFT aynı işi $n\log n$ adımda yapar (ekrandan, 00:25:00 ve 00:35:00).
  - Karşılaştırma tablosu: A (DFT) $n^2$ adım, bellek $M(n^2)$; B (FFT) $n\log n$ adım, bellek $M(n^3)$. Bellek değerleri hocanın örnek için uydurduğu değerlerdir (ekrandan, 00:35:00).
- Yerinde (in-place) ve kararlı (stable) algoritma kavramlarının tekrarı
  - Yerinde algoritma diziyi başka bir diziye kopyalamadan, en fazla birkaç geçici değişkenle işler. Seçmeli sıralama (selection sort) yerindedir; birleştirmeli sıralama (merge sort) yerinde değildir.
- Bilimsel yöntem ve deneysel (empirical) analiz
  - Gözlem → hipotez (model) → tahmin → doğrulama döngüsü.
  - 3-SUM problemi: $N$ farklı tam sayı içinde toplamı sıfır olan üçlüleri saymak. Kaba kuvvet çözümü üç iç içe döngüdür (ekrandan, 00:45:00).
  - Süre ölçümü tablosu: $N=250, 500, 1000, 2000, 4000, 8000$ için $0.0, 0.0, 0.1, 0.8, 6.4, 51.1$ saniye; $N$ iki katına çıkınca süre yaklaşık 8 katına çıkar (ekrandan, 00:50:00).
  - Log-log grafikte doğrunun eğimi yaklaşık 3'tür; hipotez $T(N) \approx 1.006 \times 10^{-10} \times N^{2.999}$ saniyedir. Tahmin: $N=8000$ için 51.0 s, $N=16000$ için 408.1 s; gözlem 51.1, 51.0, 51.1 ve 410.8 s, yani hipotez doğrulanır (ekrandan, 00:55:00).
- Çalışma süresini etkileyen etkenler
  - Sistemden bağımsız: algoritma ve girdi verisi.
  - Sisteme bağlı: donanım (işlemci, bellek, önbellek, veri yolu), yazılım (derleyici, yorumlayıcı, çöp toplayıcı), sistem (işletim sistemi, ağ, aynı anda çalışan diğer uygulamalar).
- Çalışma süresinin matematiksel modeli
  - Toplam çalışma süresi $= \sum (\text{maliyet} \times \text{sıklık})$, tüm işlemler üzerinden. Maliyet makineye ve derleyiciye, sıklık algoritmaya ve girdiye bağlıdır (ekrandan, 01:15:00).
  - Bu modeli D. Knuth *The Art of Computer Programming* kitaplarında önermiştir.
  - 1-SUM ve 2-SUM örneklerinde her işlem türünün kaç kez yapıldığı sayıldı (ekrandan, 01:20:00 ve 01:25:00).
- Temel işlem (basic operation) ve tilde gösterimi
  - Bütün işlemleri saymak sıkıcıdır ve yine makineden bağımsız bir sonuç vermez. Bunun yerine algoritmanın tamamına "vekâlet eden" (proxy), en sık tekrarlanan tek bir işlem seçilir.
  - Tilde gösterimi: düşük dereceli terimler atılır, $f(N) \sim g(N)$ ise $\lim_{N\to\infty} f(N)/g(N) = 1$.
  - Ayrık toplamlar integralle tahmin edilir: $\sum_{i=1}^{N} i \sim \tfrac12 N^2$, $\sum_{i=1}^{N} i^k \sim \tfrac{1}{k+1}N^{k+1}$, $\sum_{i=1}^{N} \tfrac1i \sim \ln N$ (ekrandan, 01:35:00).
- Büyüme dereceleri
  - $1 \ll \log n \ll n \ll n\log n \ll n^2 \ll n^3 \ll \dots \ll 2^n \ll 3^n \ll \dots \ll n!$ (ekrandan, 03:30:00).
  - Tanım: $f(N) \sim c\,g(N)$ ise $f(N)$'nin büyüme derecesi $g(N)$'dir; baştaki katsayı ve düşük dereceli terimler yok sayılır (ekrandan, 01:40:00).
  - Tipik kod kalıpları: tek işlem (sabit), her adımda yarıya inen `while` döngüsü ($\log n$), tek döngü ($n$), iç içe iki döngü ($n^2$), üç döngü ($n^3$), bütün alt kümeleri deneme ($2^n$).
  - Üstel büyüme örneği: 20 haneli ikili şifre $2^{20}$, 256 karakterli ASCII ile 20 haneli şifre $256^{20}$ farklı olasılık (ekrandan, 01:45:00).
- Seçmeli sıralama ve kabarcık sıralamasının analizi
  - Temel işlem karşılaştırma, problem boyutu $n$ (ekrandan, 02:15:00).
  - $T_1(n) = \sum_{i=0}^{n-2}\sum_{j=i+1}^{n-1} 1 = \dfrac{n(n-1)}{2}$ (seçmeli sıralama).
  - $T_2(n) = \sum_{i=0}^{n-2}\sum_{j=0}^{n-i-2} 1 = \dfrac{n(n-1)}{2}$ (kabarcık sıralaması).
  - İyileştirilmiş kabarcık sıralaması: bir tur boyunca hiç yer değiştirme olmazsa dizi sıralıdır ve algoritma durur (ekrandan, 02:25:00).
- En iyi, ortalama ve en kötü durum
  - Sıralı arama: en iyi 1, en kötü $n$ karşılaştırma. İkili arama: en iyi 1 (aranan eleman ortadaki eleman), en kötü yaklaşık $\log n + 1$.
  - Sıralamada en iyi durum sıralı girdi, en kötü durum ters sıralı girdi, ortalama durum rastgele girdidir.
  - 3-SUM için $N^2\log N$ algoritması: önce sırala, sonra her $(a[i], a[j])$ çifti için ikili aramayla $-(a[i]+a[j])$ ara (ekrandan, 02:30:00).
- Algoritmalar kuramı
  - Ayrıntıları bastır (sabit çarpana kadar analiz et), girdi modelindeki değişkenliği ele (en kötü duruma odaklan). Üst sınır: her girdi için performans garantisi; alt sınır: hiçbir algoritmanın daha iyisini yapamayacağının kanıtı; optimal algoritma: alt sınır = üst sınır (ekrandan, 02:45:00).
- Asimptotik gösterimlere giriş
  - $O$ (üst sınır), $o$ (kesin üst sınır), $\Omega$ (alt sınır), $\omega$ (kesin alt sınır), $\Theta$ (sıkı sınır) (ekrandan, 03:15:00).
  - Big-O tanımı: $c>0$ ve $n_0>0$ sabitleri için $n \ge n_0$ olan her $n$'de $T(n) \le c\,f(n)$ ise $T(n) \in O(f(n))$ (ekrandan, 03:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Süre ölçmek kullanılabilir ama güvenilir bir ölçüt değildir
  - Aynı algoritma farklı makinelerde, hatta aynı makinede farklı anlarda farklı sürelerde çalışır. Bu yüzden süre yerine girdi boyutuna bağlı adım sayısı kullanılır.
- Hıza bakıp hemen karar verilmez
  - $n\log n$ adımlı algoritma daha hızlıdır, ama çalışılacak sistemin (gömülü sistem, Raspberry Pi, sunucu) belleği yetmiyorsa kullanılamaz. Bellek kısıtlı sistemlerde yerinde (in-place) algoritma şarttır.
- Temel işlemi doğru seçmek
  - Bir kod verildiğinde ilk iş temel işlemi ve problem boyutunu belirlemektir. Girdi okuma, dosyaya yazma gibi kısımlar değil, kodun algoritmik çekirdeği analiz edilir.
  - Ödev ve sınavlarda "iki döngü var, demek ki $O(n^2)$" demek yetmez; temel işlemin sayısını veren toplam yazılıp çözülmelidir.
- En kötü duruma göre analiz
  - Algoritmalar genellikle en kötü duruma göre kıyaslanır. Ortalama durum, en iyi ve en kötü durumun ortalaması değildir; olasılıklarla ayrıca hesaplanır.
- Big-O sorusu
  - Sınavda "üst sınırı Big-O ile yazın" denince yalnızca $T(n)$'i yazmak yetmez; $O(\cdot)$ biçiminde yazılmalı ve gerekirse $c$ ile $n_0$ bulunarak kanıtlanmalıdır.
  - En makul (en sıkı) üst sınır söylenmelidir: $n^2$ olan bir algoritmaya $O(n^3)$ demek matematiksel olarak doğrudur ama algoritmayı olduğundan kötü gösterir.
- Ayrık toplam formüllerini hatırlamak
  - $\sum_{i=1}^{n} i = \dfrac{n(n+1)}{2}$ gibi formüller analizde sürekli kullanılır.

## Kısa Tekrar Notları

- Algoritma analizi = girdi boyutu $n$'ye göre temel işlemin kaç kez yapıldığını bulmak.
- Deneysel analiz: farklı $N$ için süre ölç, log-log grafikte eğimi bul; makineye bağlı olduğu için kaba bir yöntemdir.
- Süreyi etkileyen sistemden bağımsız etkenler: algoritma, girdi. Sisteme bağlı etkenler: donanım, yazılım, işletim sistemi.
- Maliyet modeli: $\sum \text{maliyet} \times \text{sıklık}$; basitleştirmek için tek temel işlem ve tilde gösterimi.
- $\sum_{i=1}^{N} i \sim N^2/2$; $\sum i^k \sim N^{k+1}/(k+1)$; $\sum 1/i \sim \ln N$.
- Büyüme sırası: $1 < \log n < n < n\log n < n^2 < n^3 < 2^n < n!$.
- Seçmeli ve kabarcık sıralamasında karşılaştırma sayısı $n(n-1)/2$, yani $n^2$ mertebesi.
- İyileştirilmiş kabarcık sıralaması sıralı girdide tek turda ($n-1$ karşılaştırma) biter.
- Sıralı arama en kötü $n$, ikili arama en kötü yaklaşık $\log_2 n$ (1024 eleman → 10 adım).
- 3-SUM: kaba kuvvet $N^3$; sıralama + ikili arama $N^2\log N$.
- $O$: üst sınır, $\Omega$: alt sınır, $\Theta$: ikisi birden (sıkı sınır).
- $T(n) \in O(f(n)) \iff \exists\, c>0,\ n_0>0:\ T(n) \le c\,f(n)\ \ \forall n \ge n_0$.
- Örnek: $3n^2 - 100n + 6 \le 3n^2$, $n \ge 1$ için doğru; $c=3$, $n_0=1$ ile $O(n^2)$.

## Detaylı Açıklamalar

- **DFT ve FFT örneği.** Bir ses kaydı, örnekleme frekansı ile süresinin çarpımı kadar elemanlı bir dizidir. Ayrık Fourier Dönüşümü bu diziyi zaman düzleminden frekans düzlemine geçirir. Hoca formülü tahtada önce integral olarak yazdı, sonra bilgisayarda integralin toplama dönüştüğünü göstererek $\sum_n \sum_n x[n]\,e^{-j2\pi f n}$ biçimine getirdi (ekrandan, 00:25:00). Dış toplam frekanslar, iç toplam örnekler üzerinde döndüğü için iç içe iki döngü vardır ve $n^2$ işlem gerekir. Hocanın örneğinde 4 dakikalık kayıt $240 \times 10^6$ örnek sayıldı; bu durumda $n^2 \approx 5.8 \times 10^{16}$ işlem gerekir. FFT aynı sonucu $n\log n$ adımda verir.
  - Ders sonrası not: Hoca "1 kilohertz, yani saniyede 1 milyon örnek" dedi. 1 kHz saniyede 1000 örnek demektir; $240 \times 10^6$ sayısı ancak saniyede 1 milyon örnekle (1 MHz) elde edilir. Büyük olasılıkla örnek yalnızca büyüklük fikri vermek için seçilmiştir.
- **Hangi algoritmayı seçmeli?** A algoritması $n^2$ adım ve $M(n^2)$ bellek, B algoritması $n\log n$ adım ve $M(n^3)$ bellek kullanıyorsa seçim sisteme bağlıdır. Bellek yetiyorsa B seçilir ("param varsa uçakla giderim"). Örneğin 4 MB belleği olan bir sistemde 3 MB'lık veri işlenecekse yerinde olmayan bir algoritma 3 MB daha isteyebilir ve sığmaz.
- **Kararlılık ve yerinde çalışma.** Seçmeli sıralamada en küçük eleman bulunur ve dizinin başındaki konumla yer değiştirir; bunun için tek bir geçici değişken yeter, yani algoritma yerindedir.
  - Ders sonrası not: Derste kararlılık (stability), seçmeli sıralamanın bir elemanı kendisiyle gereksiz yere yer değiştirmesiyle ilişkilendirildi ve `if (min != i)` kontrolünün bunu önlediği söylendi. Kararlılık aslında eşit anahtarlı elemanların göreli sırasının korunması demektir. Seçmeli sıralama, uzak mesafeli yer değiştirmeler eşit elemanların sırasını bozabildiği için kararsızdır; `if (min != i)` kontrolü yalnızca gereksiz yer değiştirmeyi önler, algoritmayı kararlı yapmaz.
- **Deneysel analiz.** 3-SUM için kaba kuvvet kodu üç iç içe döngüdür; `j` `i+1`'den, `k` `j+1`'den başlar (ekrandan, 00:45:00):

  ```java
  for (int i = 0; i < N; i++)
     for (int j = i+1; j < N; j++)
        for (int k = j+1; k < N; k++)
           if (a[i] + a[j] + a[k] == 0)
              count++;
  ```

  Ölçülen sürelerde $N$ iki katına çıkınca süre yaklaşık $2^3 = 8$ katına çıkar. Log-log grafikte eğim yaklaşık 3 bulunur ve $T(N) = a N^b$ modelinde $b \approx 3$ çıkar. Sonuç kod incelemesinden bulunan $N^3$ ile uyuşur. Bu yöntem bilimsel yönteme uygundur, ama sonuç makineye bağlıdır, tam sonuç vermez ve her kod bu kadar düzenli döngülerden oluşmaz.
- **1-SUM ve 2-SUM işlem sayımı.** `for (int i = 0; i < N; i++) if (a[i] == 0) count++;` kodunda değişken tanımı 2, atama 2, `<` karşılaştırması $N+1$, `==` karşılaştırması $N$, dizi erişimi $N$, artırma $N$ ile $2N$ arasında yapılır (ekrandan, 01:20:00). 2-SUM'da (iki iç içe döngü) değişken tanımı ve atama $N+2$, `<` karşılaştırması $\tfrac12(N+1)(N+2)$, `==` karşılaştırması $\tfrac12 N(N-1)$, dizi erişimi $N(N-1)$, artırma $\tfrac12 N(N-1)$ ile $N(N-1)$ arasındadır; slayttaki ifadeyle bunu tam saymak "sıkıcı"dır (ekrandan, 01:25:00). İç döngünün toplam dönüşü $0+1+\dots+(N-1) = \tfrac12 N(N-1) = \binom{N}{2}$'dir.
- **Temel işlem.** Döngü değişkeni tanımı, atama gibi işlemler her makinede aynı şekilde yapılır ve aralarındaki nanosaniyelik farklar önemsizdir. Bu yüzden en sık tekrarlanan işlem (çoğunlukla en içteki karşılaştırma ya da dizi erişimi) seçilir ve analiz onun sayısı üzerinden yapılır. Toplam ifadesindeki en yüksek dereceli terim zaten bu işlemden gelir; örneğin $\tfrac16 N^3 + 20N + 16$ ifadesinde $N$ büyüdükçe yalnızca $N^3$ terimi önem taşır.
- **Seçmeli sıralamanın analizi.** Kod (ekrandan, 01:50:00):

  ```c
  for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++) {
          if (array[min] > array[j])
              min = j;
      }
      if (min != i) {
          swap = array[i];
          array[i] = array[min];
          array[min] = swap;
      }
  }
  ```

  Temel işlem `array[min] > array[j]` karşılaştırmasıdır. İç döngü $n-1-i$ kez döner:
  $$T_1(n) = \sum_{i=0}^{n-2} (n-1-i) = n(n-1) - \frac{(n-2)(n-1)}{2} - (n-1) = \frac{n(n-1)}{2}.$$
  Hoca tahtada ara adımlarda birkaç işaret hatası yaptı ve sonra düzeltti; sonuç $n(n-1)/2$'dir (ekrandan, 02:15:00).
- **Kabarcık sıralamasının analizi.** Kod (ekrandan, 01:50:00):

  ```c
  for (i = 0; i < n - 1; i++) {
      for (j = 0; j < n - i - 1; j++) {
          if (array[j] > array[j+1]) {
              swap = array[j];
              array[j] = array[j+1];
              array[j+1] = swap;
          }
      }
  }
  ```

  Her turda yan yana iki eleman karşılaştırılır ve sıra bozuksa yer değiştirir; tur sonunda en büyük eleman en sona itilmiş olur. Örnek dizi 6, 4, 8, 2, 3, 5, 3 ilk turdan sonra 4, 6, 2, 3, 5, 3, 8 olur. İç döngü yine $n-1-i$ kez döner, bu yüzden $T_2(n) = n(n-1)/2$ çıkar. Seçmeli sıralama bir turda en fazla bir uzun mesafeli yer değiştirme yaparken kabarcık sıralaması çok sayıda komşu yer değiştirme yapar.
- **İyileştirilmiş kabarcık sıralaması.** Bir tur boyunca hiç yer değiştirme olmazsa dizi sıralıdır ve kalan turlara gerek yoktur. Hocanın kodu bunu bir `swapped` bayrağı ve `while` döngüsüyle yapar; bayrak döngüye girmeden önce 1 yapılır (ekrandan, 02:25:00):

  ```c
  //for(i=0;swapped && i<MAX;i++){
  while (swapped && i < MAX) {
      swapped = 0;
      for (j = 0; j < MAX - i - 1; j++) {
          if (dizi[j] < dizi[j+1]) {
              tmp = dizi[j];
              dizi[j] = dizi[j+1];
              dizi[j+1] = tmp;
              swapped = 1;
          }
      }
      i++;
  }
  ```

  Aynı mantık `do { ... } while (swapped && i < MAX);` ile de yazılabilir. Bu iyileştirme en kötü durumu değiştirmez, ama sıralı girdide algoritma tek turda ($n-1$ karşılaştırma) biter. Bu yüzden analizde en iyi, ortalama ve en kötü durum ayrı ayrı düşünülür.
  - Ders sonrası not: Ekrandaki kodda koşul `dizi[j] < dizi[j+1]` olduğu için dizi büyükten küçüğe sıralanır (kod derlenip denendi). Küçükten büyüğe sıralamak için koşul `dizi[j] > dizi[j+1]` olmalıdır.
- **Arama algoritmalarında durumlar.** Sıralı aramada en iyi durum aranan elemanın ilk eleman olmasıdır (1 karşılaştırma); en kötü durum elemanın sonda olması ya da hiç olmamasıdır ($n$). İkili arama sıralı dizide ortadaki elemana bakar ve arama aralığını her adımda yarıya indirir; en iyi durumda ortadaki eleman aranan elemandır (1 karşılaştırma), en kötü durumda yaklaşık $\log_2 n + 1$ karşılaştırma gerekir. İkili aramada ilk ya da son elemanı aramak en iyi değil, en kötü durumlardandır.
- **3-SUM için daha iyi algoritma.** Önce $N$ farklı sayı sıralanır, sonra her $(a[i], a[j])$ çifti için ikili aramayla $-(a[i]+a[j])$ aranır. Ekleme sıralamasıyla birinci adım $N^2$, ikinci adım $N^2\log N$ olduğundan toplam $N^2\log N$'dir (ekrandan, 02:30:00). Deneyde $N=8000$ için süre 51.1 s'den 0.96 s'ye iner.
  - Ders sonrası not: Hoca daha iyi bir sıralama algoritmasıyla toplamın $n\log^2 n$'e inebileceğini söyledi. Sıralama $N\log N$'e inse bile ikinci adım ($N^2$ çift × $\log N$ ikili arama) değişmez, bu yüzden toplam yine $N^2\log N$ olur.
- **Algoritmalar kuramı ve sınırlar.** Üst sınır, algoritmanın her girdi için en fazla ne kadar süreceğini söyleyen garantidir. Alt sınır, problemi çözen hiçbir algoritmanın bundan daha iyisini yapamayacağını gösterir; örneğin karşılaştırmaya dayalı sıralamada dizinin üzerinden en az bir kez geçmek gerekir. Alt ve üst sınır sabit çarpan dışında eşitse algoritma optimaldir.
- **Asimptotik gösterimler.** $T(n)$ algoritmanın bulunan fonksiyonu, $f(n)$ ise $1, \log n, n, n\log n, n^2, \dots$ gibi bilinen bir fonksiyon olsun (ekrandan, 03:15:00):
  - $T(n) \in O(f(n))$: $T(n)$, $f(n)$'den hızlı büyümez (üst sınır).
  - $T(n) \in o(f(n))$: $T(n)$, $f(n)$'den kesin olarak yavaş büyür.
  - $T(n) \in \Omega(f(n))$: $T(n)$, $f(n)$'den yavaş büyümez (alt sınır).
  - $T(n) \in \omega(f(n))$: $T(n)$, $f(n)$'den kesin olarak hızlı büyür.
  - $T(n) \in \Theta(f(n))$: hem $O(f(n))$ hem $\Omega(f(n))$ (sıkı sınır). En çok $O$, $\Omega$ ve $\Theta$ kullanılır; "küçük" gösterimler pek kullanılmaz.
- **Big-O kanıtı örnekleri.**
  - $T(n) = \tfrac12 n^2 - 3n \in O(n^2)$ mi? $\tfrac12 n^2 - 3n \le c\,n^2 \Rightarrow n^2 - 6n \le 2c\,n^2$. $c=1$ alınırsa $-n^2 \le 6n$, yani $-n \le 6$ olur ve bu her pozitif $n$ için doğrudur (ekrandan, 03:35:00).
  - $3n^2 - 100n + 6 \in O(n^2)$ mi? Önce sabitler, düşük dereceli terimler ve katsayılar silinerek aday $n^2$ bulunur. $c=3$ seçilirse $3n^2 - 100n + 6 \le 3n^2 \Rightarrow 6 \le 100n$, bu da $n \ge 1$ için doğrudur; $c=3$, $n_0=1$ (ekrandan, 03:40:00).
  - Aynı fonksiyon $O(n^3)$'tür ($c=1$, $n_0=4$ gibi), ama bu algoritmayı olduğundan kötü gösterir. $O(n)$ ya da $O(n\log n)$ değildir, çünkü hiçbir $c$ bulunamaz.
  - Ders sonrası not: Tahtada $c$ ve $n_0$ için "integer" yazıldı ve koşul "for all $n>0$" olarak kutulandı. Standart tanımda $c$ pozitif bir gerçel sabittir ve eşitsizliğin her $n$ için değil, yalnızca $n \ge n_0$ için sağlanması gerekir; $n_0$'ın anlamı da budur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
