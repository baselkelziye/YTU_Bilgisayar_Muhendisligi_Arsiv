# Ders 4 Çalışma Özeti

## Genel Konular

- Bir gerçek dünya problemini algoritmayla çözme adımlarının tekrarı
  - Adımlar sırasıyla: problemi anlamak (girdi ve çıktıyı belirlemek), kesin (exact) mi yaklaşık (approximate) mı çözüm aranacağına ve tasarım tekniğine karar vermek, algoritmayı tasarlamak, doğruluğunu kanıtlamak (prove correctness), algoritmayı analiz etmek ve kodlamak (ekrandan, 00:15:00).
  - Analiz başlığı altında best, average ve worst case incelenir; sonuçlar asimptotik notasyonlarla ($\Omega$, $\Theta$, $O$, $o$, $\omega$) yazılır. Derste ağırlık $\Omega$, $\Theta$ ve $O$ üzerindedir.
  - Algoritmanın dört özelliği: zaman verimliliği (time efficiency), bellek verimliliği (space efficiency), basitlik (simplicity) ve genellik (generality). İlk ikisi matematiksel olarak ölçülebilir.
  - Algoritmalar iteratif ve özyinelemeli (recursive) olarak iki türlü analiz edilir. İkisinde de bir temel operasyon (basic operation) seçilip sayılır: iteratifte toplam sembolüyle, özyinelemelide yineleme bağıntısı kurulup geriye doğru yerine koyma (backward substitution) ya da Master teoremiyle.
- Kaba kuvvet (Brute Force) ve kapsamlı arama (Exhaustive Search)
  - Tanım (ekrandan, 00:35:00): "Brute force is a straightforward approach to solve a problem, usually directly based on the problem statement and definitions of the concepts involved." Yani problemin tanımından doğrudan çıkan, ilk akla gelen düz yaklaşım.
  - Yaklaşım (approach) ile algoritma farklıdır: yaklaşım çözümün kafadaki fikridir; algoritma bu fikrin bilgisayarda kodlanabilecek kadar açık (unambiguous) ve sonlu yazılmış hâlidir.
  - Derste verilen kaba kuvvet örnekleri (ekrandan, 00:40:00): $a^n$ hesabı ($a^n = a \cdot a \cdots a$, $n$ çarpma), $\gcd(m,n)$, Selection / Bubble / Insertion Sort, doğrusal (sıralı) arama, string matching, en yakın nokta çifti (closest pair).
  - Kapsamlı arama, kaba kuvvetin bir alt kümesidir: permütasyon, kombinasyon, alt küme gibi kombinatoryal problemlerde bütün olası çözümler üretilip en iyisi seçilir. Örnekler: gezgin satıcı (Traveling Salesman), sırt çantası (Knapsack), iş atama (Assignment) problemleri.
- Azalt ve fethet (Decrease and Conquer)
  - Problem, çözülüp genişletilecek daha küçük bir alt probleme indirgenir: "problem with size $n$ → subproblem of size $n-1$ → solution of subproblem → overall solution" (ekrandan, 01:10:00).
  - Üç türü: sabit miktarda azaltma (decrease by a constant, genelde 1), sabit çarpanla azaltma (decrease by a constant factor, genelde 2) ve değişken boyutlu azaltma (variable size decrease).
  - Örnekler: $a^n = a^{n-1}\cdot a$ (bir azaltma), $a^n = (a^{n/2})^2$ (sabit çarpan), Öklid algoritması (değişken boyut), ikili arama (sabit çarpan).
- Böl ve fethet (Divide and Conquer)
  - Üç adım (ekrandan, 02:15:00): böl (divide), alt problemleri aynı algoritmayla çöz (conquer), çözümleri birleştir (combine).
  - Bu algoritmalar yineleme bağıntılarıyla (recurrence relations) analiz edilir; en kısa yol Master teoremidir.
- Master teoremi (tekrar)
  - $T(n) = a\,T(n/b) + f(n)$ ve $f(n) \in \Theta(n^d)$, $d \ge 0$ ise (ekrandan, 01:35:00):
    - $a < b^d$ ise $T(n) \in \Theta(n^d)$
    - $a = b^d$ ise $T(n) \in \Theta(n^d \log n)$
    - $a > b^d$ ise $T(n) \in \Theta(n^{\log_b a})$
  - $a$: özyinelemeli çağrı sayısı, $b$: problemin kaça bölündüğü, $f(n)$: her çağrıda yapılan temel operasyon maliyeti.
  - Örnek: $A(n) = 2A(n/2) + 1$ için $a=2$, $b=2$, $d=0$; $a > b^d$ olduğundan $A(n) \in \Theta(n^{\log_2 2}) = \Theta(n)$.
- Merge Sort ve analizi
  - Örnek dizi 8, 3, 2, 9, 7, 1, 5, 4 tek elemanlı parçalara kadar ikiye bölünür, sonra birleştirilerek 1, 2, 3, 4, 5, 7, 8, 9 elde edilir (ekrandan, 01:40:00).
  - Karşılaştırma sayısı bağıntısı: $C(n) = 2C(n/2) + C_{merge}(n)$, $n > 1$; $C(1) = 0$; en kötü durumda $C_{merge}(n) = n - 1$ (ekrandan, 02:00:00).
  - Master teoremiyle $a = 2$, $b = 2$, $d = 1$, $a = b^d$ olduğundan $C(n) \in \Theta(n \log n)$. Best, worst ve average case'in hepsi $\Theta(n\log n)$'dir.
  - Bellek karmaşıklığı: birleştirmede $n$ elemanlı geçici dizi açıldığı için $S(n) \in \Theta(n)$ (ekrandan, 02:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Yaklaşım ile algoritma aynı şey değildir
  - Bir fikri algoritma sayabilmek için her adımı açık olmalıdır. Örneğin OBEB'i "ortak asal bölenleri çarparak" bulmak istersek, bilgisayara bir sayının asal olduğunu ve bir sonraki asalın ne olduğunu da tarif etmemiz gerekir; problem içinden yeni problemler çıkar.
- Kaba kuvvetin yeri
  - Basittir, birçok probleme uygulanır ve küçük verilerde makul sonuç verir. Ama büyük verilerde kabul edilemez derecede yavaş olabilir: $n$ nokta için en yakın çift $n^2$ karşılaştırma ister, $n = 10^6$ için $10^{12}$ eder.
  - Kapsamlı arama çoğu zaman kesin çözüm için bilinen tek yoldur, ama uygulanabilirliği şüphelidir: 81 ilde gezgin satıcı $80!$ tur, $n$ eşyalı knapsack $2^n$ alt küme, $n$ kişilik iş atama $n!$ atama demektir.
- Kaba kuvvet ile kapsamlı arama farkı (ders sonu sorusu)
  - Kaba kuvvet genel bir tekniktir; $a^n$ hesabı gibi arama olmayan işler de kaba kuvvetle yapılır. Kapsamlı arama ise bir arama uzayında en iyi çözümü arayan yöntemdir ve kaba kuvvetin alt kümesidir. Problem (ör. gezgin satıcı) ile ona önerilen çözüm yöntemi (kapsamlı arama) farklı şeylerdir.
- Master teoremi sorularda en kısa yoldur
  - "Master teoremiyle çöz" denirse sonuç birkaç satırda çıkar; "backward substitution ile çöz" denirse açılım uzun uzun yazılmalıdır.
- Merge Sort'ta durum farkı yoktur
  - Dizi ne olursa olsun bölme $\log_2 n$ derinliğe kadar iner ve her seviyede birleştirme $n$ eleman taşır. Bu yüzden best, average ve worst case aynıdır: $\Theta(n\log n)$.
- Zaman ile bellek arasındaki ödünleşim (trade-off)
  - Selection ve Bubble Sort $n^2$ iken Merge Sort, $\Theta(n)$ ek bellek karşılığında süreyi $n\log n$'e indirir. Ek bellek kullanmayan yerinde (in-place) Merge Sort sürümleri de vardır.

## Kısa Tekrar Notları

- Problem çözme adımları: anla → exact/approximate ve teknik seç → tasarla → doğruluğunu kanıtla → analiz et → kodla.
- Brute force: problemin tanımından doğrudan çıkan düz yaklaşım. Örnekler: $a^n$, gcd, Selection/Bubble Sort, doğrusal arama, string matching, closest pair.
- Exhaustive search: bütün adayları üretip en iyisini seçmek. Gezgin satıcı $\approx (n-1)!$, knapsack $2^n$, iş atama $n!$ aday.
- Kaba kuvvet string matching: metnin her konumunda desen soldan sağa karşılaştırılır; uyuşmazlıkta desen bir kaydırılır.
- Kaba kuvvet polinom değerlendirme $\Theta(n^2)$ çarpmadır; $x^i$ bir önceki kuvvetten elde edilirse $\Theta(n)$'e iner.
- Decrease and conquer türleri: sabit (1), sabit çarpan (2), değişken boyut.
- $a^n$: $f(a,0) = 1$, $f(a,n) = f(a,n-1)\cdot a$; $f(2,3) = 8$.
- $a^n$ (sabit çarpan): $n$ çiftse $(a^{n/2})^2$, tekse $(a^{(n-1)/2})^2 \cdot a$, $n = 0$ ise 1.
- Öklid: $\gcd(m,n) = \gcd(n, m \bmod n)$, $m \bmod n = 0$ olunca sonuç $n$. $\gcd(42,4) = \gcd(4,2) = \gcd(2,0) \to 2$.
- İkili arama: $C_{best}(n) \in O(1)$; $C_w(n) = C_w(\lfloor n/2 \rfloor) + 1$, $C_w(n) = \lfloor\log_2 n\rfloor + 1 \in O(\log n)$.
- Master teoremi: $a$ ile $b^d$ karşılaştırılır; $<$ ise $n^d$, $=$ ise $n^d\log n$, $>$ ise $n^{\log_b a}$.
- Merge Sort: $C(n) = 2C(n/2) + (n-1)$, $C(1) = 0$ → $\Theta(n\log n)$ her durumda; bellek $\Theta(n)$.

## Detaylı Açıklamalar

- **Tekrar: özyineleme derinliği.** Hoca Master teoreminin sezgisini $T(n) = 2T(n/2) + n^2$ üzerinden anlattı: her seviyede temel operasyon yapılır ve $n/2, n/4, \dots$ diye bölünme $\log n$ derinliğe kadar sürer. Amaç, temel operasyonun her derinlikte kaç kez yapıldığını $n = 1$'e ulaşana kadar saymaktır.
  - **Ders sonrası not:** Hoca bu örneğin sonucunu $n^2\log n$ olarak söyledi. Seviye maliyetleri $n^2, n^2/2, n^2/4, \dots$ diye azaldığı için toplam $\Theta(n^2)$'dir; Master teoremiyle de $a = 2 < b^d = 4$ olduğundan $T(n) \in \Theta(n^2)$ çıkar.
- **Kaba kuvvet ile OBEB.** Derste önerilen kaba kuvvet yöntemi şudur: iki sayıdan küçüğü $x = \min(m,n)$ bulunur, $x$'ten 1'e doğru inilir ve iki sayıyı da tam bölen ilk değerde durulur (ekrandan, 00:30:00). Örneğin 6 ve 14 için 6, 5, 4, 3 bölmez, 2 ikisini de böler: OBEB 2. 5 ve 12 için 1'e kadar inilir; 1'de durmak sayıların aralarında asal olduğunu gösterir. İlkokulda öğretilen "en küçük asaldan başlayıp ortak bölenleri çarpma" yöntemi ise bilgisayara asal sayıyı ve bir sonraki asalı da tarif etmeyi gerektirir. Öklid algoritması bu işi daha kısa yapar.
- **Kaba kuvvet sıralama ve arama.** Selection Sort en kaba sıralama yaklaşımıdır: dizinin en küçüğü bulunup başa konur, sonra kalanların en küçüğü ikinci sıraya konur. Bubble Sort da kaba kuvvettir. Insertion Sort, elemanı doğru yere yerleştirdiği için bu ikisine göre daha iyi konumdadır. Aramada kaba kuvvet örneği doğrusal (sıralı, sequential) aramadır: dizinin sıralı olup olmadığına bakılmadan ilk elemandan son elemana kadar gezilir.
- **String matching.** "abcdefghj" metninde "abz" aranırken her konumda desenin karakterleri sırayla karşılaştırılır; uyuşmazlık olursa desen bir konum kaydırılır. Hoca, karşılaştırmaya desenin sonundan başlamanın çoğu zaman avantajlı olduğunu da söyledi: son karakter uyuşmuyorsa öncekilere bakmaya gerek kalmaz ve daha ileri atlanabilir. Bu fikir ileride görülecek farklı bir tekniktir. Bu problem yalnız belge içinde arama değildir; biyoinformatikte gen dizilimlerini eşleştirmek de string matching'dir ve büyük verilerde kaba kuvvet çok yavaş kalır.
  <!-- BELİRSİZ: Hoca kaba kuvvet string matching için "n çarpı n" karşılaştırma dedi; kitabın formülü karede görülmedi. -->
- **Kaba kuvvet polinom değerlendirme.** $p(x) = a_n x^n + a_{n-1}x^{n-1} + \dots + a_1 x + a_0$ değerini $x = x_0$ noktasında bulmak için (ekrandan, 00:45:00):

  ```text
  p <- 0.0
  for i <- n downto 0 do
      power <- 1
      for j <- 1 to i do        // compute x^i
          power <- power * x
      p <- p + a[i] * power
  return p
  ```

  Çarpma sayısı $\sum_{0 \le i \le n} i \in \Theta(n^2)$'dir. $x^i$ bir önceki kuvvetten tek çarpmayla elde edilirse iç döngüye gerek kalmaz ve maliyet $\Theta(n)$'e iner.
- **Kapsamlı arama örnekleri.** Gezgin satıcı problemi: bir şehirden başlayıp bütün şehirleri birer kez gezip başlangıca dönen en kısa tur aranır. 81 il için İstanbul'dan başlanırsa $80!$ farklı sıra vardır; her turun maliyeti kolay hesaplanır ama turları üretmek imkânsız derecede uzun sürer. Knapsack: $W$ kapasiteli torbaya ağırlık ve değeri verilen eşyalardan en değerli uygun alt küme seçilir; bütün $2^n$ alt küme denenir, kapasiteyi aşanlar uygun (feasible) sayılmaz. İş atama: $n$ kişi $n$ işe birer birer atanır, $C[i,j]$ kişi $i$'nin iş $j$'yi yapma maliyetidir; bütün $n!$ atama denenip en ucuzu seçilir. Hoca bu problemin Macar (Hungarian) yöntemiyle çok daha hızlı çözülebildiğini belirtti (ekrandan, 00:50:00).
- **Azalt ve fethet ile $a^n$.** Bir azaltma sürümünde $f(2,3) = f(2,2)\cdot 2$, $f(2,2) = f(2,1)\cdot 2$, $f(2,1) = f(2,0)\cdot 2$ ve $f(2,0) = 1$ olur; dönüşte 1, 2, 4, 8 bulunur (ekrandan, 01:15:00). Sabit çarpan sürümünde $a^7 \to (a^3)^2\cdot a$, $a^3 \to (a^1)^2 \cdot a$, $a^1 \to (a^0)^2 \cdot a = 1 \cdot a$ biçiminde iner.
- **Öklid algoritması (değişken boyutlu azaltma).** $m > n$ iken $\gcd(m,n) = \gcd(n, m \bmod n)$; $m \bmod n = 0$ olunca sonuç $n$'dir (ekrandan, 01:20:00). $\gcd(12,4) = \gcd(4,0) \to 4$. Her adımda azaltma miktarı sayılara göre değiştiği için değişken boyutlu azaltmadır. Mod işlemi çoğu dilde temel operatör olduğundan tek işlem sayılır; üs alma ise çoğu dilde operatör değildir ve arkasında yinelemeli bir işlem gerektirir.
- **İkili arama (sabit çarpanla azaltma).** Sıralı $A[0..n-1]$ dizisinde $K$ aranır; bulunursa indeksi, yoksa $-1$ döner (ekrandan, 01:25:00):

  ```text
  l <- 0, r <- n-1
  while (l <= r) {
      m = (l + r) / 2
      if K = A[m] return m;
      else if K < A[m] r <- m-1
      else l <- m+1
  }
  return -1;
  ```

  En iyi durumda eleman ilk orta noktadadır: $C_{best}(n) \in O(1)$. En kötü durumda her adımda dizinin yarısı elenir: $C_w(n) = C_w(\lfloor n/2\rfloor) + 1$. $n = 2^k$ koyup geriye doğru açınca $C_w(2^k) = k + 1$, yani $C_w(n) = \lfloor \log_2 n\rfloor + 1 \in O(\log n)$.
- **Merge Sort kodu (derste tahtaya yazılan, ekrandan, 01:55:00).**

  ```c
  void MS(int A[], int p, int r) {
      if (p < r) {
          q = (p + r) / 2;
          MS(A, p, q);
          MS(A, q + 1, r);
          merge(A, p, q, r);
      }
  }

  merge(int A, p, q, r) {
      int i, j, k, n, *B;   // B: malloc ile açılan geçici dizi
      while ((i <= q) && (j <= r)) {
          if (A[i] <= A[j])
              B[k++] = A[i++];
          else
              B[k++] = A[j++];
      }
      while (i <= q) B[k++] = A[i++];
      while (j <= r) B[k++] = A[j++];
      copy(A, B);
  }
  ```

  Tahtadaki kod başlangıç değerlerini ($i = p$, $j = q+1$, $k = 0$) ve `copy` işlemini açık yazmaz. Bunlar tamamlanıp kod `gcc -Wall` ile derlendi ve 8, 3, 2, 9, 7, 1, 5, 4 dizisi 1, 2, 3, 4, 5, 7, 8, 9 olarak sıralandı (tamamlama ajan tarafından yapıldı, derste yazılmadı).
- **Çağrı izi.** $A = [8,3,2,9,7,1,5,4]$ için $p = 0$, $r = 7$, $q = 3$: önce MS(0,3), sonra MS(4,7) çağrılır. MS(0,3) içinde $q = 1$: MS(0,1) ve MS(2,3). MS(0,1) içinde MS(0,0) ve MS(1,1) hemen döner ($p < r$ sağlanmaz), sonra 8 ile 3 birleştirilip 3, 8 olur (ekrandan, 01:50:00).
- **Merge Sort analizinin iki yolu.**
  - Master teoremiyle: $C(n) = 2C(n/2) + (n - 1)$, $-1$ ihmal edilince $f(n) = n$, $d = 1$; $a = 2 = b^d$ olduğundan $\Theta(n\log n)$.
  - Geriye doğru yerine koyma ile (ekrandan, 02:05:00): $T(n) = 2T(n/2) + n = 4T(n/4) + 2n = 8T(n/8) + 3n = \dots = 2^i T(n/2^i) + i\,n$. $n = 2^i$, yani $i = \log_2 n$ konunca $T(n) = n\,T(1) + n\log_2 n$. $T(1) = 0$ alınırsa $n\log_2 n$, bazı kaynaklardaki gibi $T(1) = 1$ alınırsa $n\log_2 n + n$ çıkar; ikisi de $\Theta(n\log n)$'dir, çünkü $n\log n$, $n$'den hızlı büyür.
- **Durum analizi.** Hoca birleştirilecek iki yarım için üç durum gösterdi: 1, 2, 3, 4 ile 5, 6, 7, 8 (bir yarı tamamen küçük), karışık bir dizi ve elemanların sırayla iki yarıdan geldiği 1, 3, 5, 7 ile 2, 4, 6, 8 benzeri bir dizi. Üçünde de geçici diziye $n$ eleman aktarılır. Selection ve Bubble Sort'ta temel işlem karşılaştırma ve takas (swap) iken burada temel iş yeni diziye kopyalamadır ve sayısı durumdan bağımsızdır.
  - **Ders sonrası not:** Hoca durumlar arasında hiç fark olmadığını söyledi. Bu, kopyalama sayısı için doğrudur; karşılaştırma sayısı ise bir yarı tamamen küçükken $n/2$, en kötü durumda $n-1$ olur. İki durumda da birleştirme $\Theta(n)$ olduğu için sonuç değişmez: Merge Sort her durumda $\Theta(n\log n)$'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
