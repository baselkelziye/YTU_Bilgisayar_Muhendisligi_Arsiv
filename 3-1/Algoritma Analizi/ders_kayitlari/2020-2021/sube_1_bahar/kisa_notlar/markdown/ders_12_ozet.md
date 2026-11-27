# Ders 12 Çalışma Özeti

## Genel Konular

- Sınav sorularının çözümü: kavram soruları
  - Kaba kuvvet (brute force): bütün olasılıkları tek tek deneyerek sonuca ulaşma yöntemidir. "Aklımıza ilk gelen yöntem" demek tek başına yeterli bir tanım değildir.
  - En kötü durum analizi: algoritmanın en kötü girdi koşullarında harcayacağı zaman ve bellek miktarıdır. Yalnız zamandan söz etmek eksiktir; zaman ve bellek birlikte ele alınır.
  - Büyük Omega ($\Omega$): algoritmanın en iyi koşullarda zaman ya da bellek açısından nasıl davrandığını anlatır.
  - Azalt ve fethet (decrease and conquer): problemi daha küçük bir örneğine indirip onu çözmektir. Küçültme sabit bir sayı çıkararak ya da sabit bir sayıya bölerek yapılabilir. <!-- BELİRSİZ: hocanın ikili arama (binary search) örneği hakkındaki yorumu altyazıda bozuk ("divide by Concuradur"); hangi sınıfa koyduğu net değil. -->
  - İki algoritmanın verimliliğini karşılaştırmak için: ikisinin zaman ve bellek karmaşıklıkları en iyi, en kötü ve ortalama durum için analiz edilir; doğrulukları ve hangi koşullarda (kısıtlı ya da parametrik) çalıştıkları incelenir.
- Sınav sorusu: dizgi (string) üzerinde kabarcık sıralaması (bubble sort)
  - Soru bir metni (karakter dizisini) sıralamayı istiyordu; tamsayı dizisiyle çözmek sorudan sapmaktır.
  - En iyi durumu iyileştirmek için `swapped` bayrağı kullanılır: bir tur boyunca hiç yer değiştirme olmazsa dizi sıralıdır ve döngü biter. Hoca kodu `do-while` ile yeniden yazdı (ekrandan, 00:20:00).
  - Temel işlem karşılaştırmadır (yer değiştirme değil), çünkü her çalışmada kesinlikle yapılır.
  - Ders denemesinde 6 harfli ters sıralı dizgi "FEDCBA" 15 karşılaştırmayla, sıralı "ABCDEF" 5 karşılaştırmayla sıralandı.
  - En kötü durum $O(n^2)$, en iyi durum (sıralı girdi, tek tur) $O(n)$.
- Sınav sorusu: yarıya indirerek (decrease by half) $\lfloor \log_2 n \rfloor$ hesaplama
  - Yineleme bağıntısı: $n \le 1$ ise $0$, değilse $1 + f(\lfloor n/2 \rfloor)$.
  - $f(1024)$ çağrısı $1 + f(512)$, $1 + f(256)$, ... diye iner ve 10 döner.
  - Geriye doğru yerine koyma: $T(n) = 1 + T(n/2) = i + T(n/2^i)$; $n/2^i = 1$ için $i = \log_2 n$, sonuç $O(\log n)$.
  - Master teoremi: $a = 1$, $b = 2$, $d = 0$; $a = b^d$ olduğundan $\Theta(n^d \log n) = \Theta(\log n)$. Tam puan için iki yolun aynı sonucu verdiği gösterilmelidir.
- Sınav sorusu: robotla para (havuç) toplama, dinamik programlama
  - Robot $5 \times 6$'lık tabloda sol üst köşeden sağ alt köşeye yalnız sağa ya da aşağıya giderek en fazla para toplar.
  - Yineleme bağıntısı (ekrandan, 00:30:00): $P(i,j) = \max\{P(i-1,j),\ P(i,j-1)\} + M(i,j)$; ilk satır $P(1,j) = P(1,j-1) + M(1,j)$, ilk sütun $P(i,1) = P(i-1,1) + M(i,1)$.
  - Tablo doldurulunca en fazla 5 para toplanır; yol, sağ alt köşeden geriye doğru her adımda büyük olan komşu seçilerek bulunur.
  - Zaman ve bellek karmaşıklığı $\Theta(m \cdot n)$: tablonun bütün hücreleri kesinlikle dolar.
- Öncelikli kuyruk (priority queue)
  - Elemanların kuyruğa giriş sırasına değil, önceliğine (değerine) göre yerleştiği kuyruktur. İşletim sistemlerindeki öncelikli süreçler buna örnektir.
  - Dizi ya da bağlı listeyle gerçeklenirse: yer bulma en iyi $\Omega(1)$, en kötü $O(n)$; dizide ekleme kaydırma (shift) gerektirdiği için $O(n)$, bağlı listede $O(1)$. Toplamda en kötü durum $O(n)$, $n$ eleman için $O(n^2)$.
- Yığın (heap) veri yapısı
  - Dengeli bir ikili ağaçtır: bir seviye dolmadan sonrakine geçilmez, düğümler soldan sağa eklenir.
  - Min-heap: ebeveyn çocuklarından küçüktür. Max-heap: ebeveyn çocuklarından büyüktür. Kardeşler arasında (sol-sağ) bir ilişki yoktur; ikili arama ağacıyla karıştırılmamalıdır.
  - Dizide saklanır, işaretçi gerekmez: $LC(i) = 2i+1$, $RC(i) = 2i+2$, $P(i) = \lfloor (i-1)/2 \rfloor$ (ekrandan, 00:55:00).
  - Ekleme = sona yazma + yukarı doğru yığınlaştırma (heapify up). Kök alma (getRoot) = kökü al, son elemanı köke taşı, aşağı doğru yığınlaştırma (heapify down).
  - Kök sürekli çekilirse elemanlar sıralı çıkar; heap sort bu fikre dayanır.
- Problem sınıfları: P, NP, NP-complete, NP-hard
  - Sınıflandırma algoritmalara değil, problemlere yapılır.
  - P (polynomial): polinom zamanlı çözümü olan problemler; bunlara izlenebilir (tractable) denir. Polinom zamanda çözülemeyenler izlenemez (intractable).
  - Polinom zaman örnekleri: $O(1)$, $O(\log n)$, $O(n)$, $O(n \log n)$, $O(n^2)$, $O(n^3)$. Polinom olmayan: $O(2^n)$, $O(n!)$, $O(n^n)$.
  - Karar problemi: cevabı evet/hayır olan problem (ör. "bu çizge 3 renkle boyanabilir mi?"). "Kaç renkle boyanır?" ise karar problemi değildir.
  - Belirlenimci olmayan (non-deterministic) algoritma: rastgele seçim, başarı ve başarısızlık adımları vardır; tahmin aşaması belirlenimci değildir, doğrulama aşaması belirlenimci ve polinomdur.
  - NP: çözümü polinom zamanda doğrulanabilen problemler. P, NP'nin içindedir; $P = NP$ olup olmadığı açık bir sorudur.
  - Polinom indirgeme: $D_1$'in örneklerini $D_2$'nin örneklerine evet→evet, hayır→hayır olacak biçimde dönüştüren, polinom zamanda hesaplanabilen bir $t$ fonksiyonu varsa $D_1$, $D_2$'ye polinom olarak indirgenebilir (ekrandan, 02:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Yineleme bağıntısını yazmak
  - Dinamik programlama sorularında önce yineleme bağıntısı kurulur; bağıntı ortaya çıktıktan sonra kodlama ve analiz çok kolaylaşır.
  - Robot problemi derste çözülen coin-row ve knapsack örneklerine çok benzer; knapsack'teki gibi ek bir satır/sütun gerekmez, çünkü burada $W$ gibi ek bir parametre yoktur.
- Temel işlemin seçimi
  - Analizde temel işlem, algoritma boyunca kesinlikle çalışan işlemdir; kabarcık sıralamasında bu karşılaştırmadır.
- Heap'te sol-sağ ilişkisi yoktur
  - Yalnız ebeveyn-çocuk (alt-üst) ilişkisi vardır. Bu yüzden düğüm yapısında sol/sağ işaretçisine gerek yoktur; dinamik bir dizi yeterlidir.
- Aşağıdan yukarıya yığınlaştırma (heapify up) mekanizması
  - Eklenen eleman ebeveyniyle karşılaştırılır, kural bozuksa yer değiştirilir ve aynı işlem ebeveyn için özyinelemeli tekrarlanır.
- P ve NP ayrımı
  - Bir problemin çözümünü bulmak ile verilen bir çözümü doğrulamak ayrı işlerdir. Bir çizgeyi boyamak çok zaman alabilir; verilen boyamanın 3 renkle geçerli olup olmadığını kontrol etmek çok daha kolaydır.
- Algoritma tasarımında uzmanlaşma
  - Mülakat ve yarışmalar için dinamik programlama ve özyineleme (recursion) konularında uzmanlık artırılmalıdır.

## Kısa Tekrar Notları

- Kaba kuvvet: bütün olasılıkları tek tek denemek.
- En kötü durum analizi zaman ve bellek için birlikte yapılır; $\Omega$ en iyi durumu anlatır.
- `swapped` bayraklı kabarcık sıralaması: en kötü $O(n^2)$, en iyi $O(n)$.
- $f(n) = 1 + f(\lfloor n/2 \rfloor)$, $f(1)=0$: $\lfloor \log_2 n \rfloor$; $T(n) = 1 + T(n/2) \Rightarrow \Theta(\log n)$ (Master: $a = b^d$ durumu).
- Robot para toplama: $P(i,j) = \max\{P(i-1,j), P(i,j-1)\} + M(i,j)$, $\Theta(mn)$ zaman ve bellek.
- Öncelikli kuyruk dizi/bağlı listeyle: tek ekleme en kötü $O(n)$, $n$ ekleme $O(n^2)$.
- Heap dizide: $2i+1$, $2i+2$, $(i-1)/2$.
- Ekleme: sona yaz + heapify up. Kök alma: son elemanı köke getir + heapify down (küçük çocukla yer değiştir).
- P: polinom zamanda çözülen; NP: çözümü polinom zamanda doğrulanabilen; $P \subseteq NP$, $P \stackrel{?}{=} NP$ açık.
- Belirlenimci olmayan algoritma: tahmin aşaması (rastgele) + doğrulama aşaması (belirlenimci, polinom); çıktı başarı/başarısızlık.

## Detaylı Açıklamalar

- **Kabarcık sıralaması kodu (ekrandan, 00:20:00).** Hoca sınavda istenen fonksiyonu önce `while (swapped && i < N)` biçiminde yazdı, sonra gövdenin en az bir kez çalışacağını belirterek `do-while`'a çevirdi:

  ```c
  do{
      swapped=0;
      for(j=0;j<N-i-1;j++){
          c++;
          if(dizi[j]>dizi[j+1]){
              tmp=dizi[j];
              dizi[j]=dizi[j+1];
              dizi[j+1]=tmp;
              swapped=1;
          }
      }
      i++;
  } while(swapped && i<N);
  ```

  Burada `c` karşılaştırma sayacıdır, `N = strlen(dizi)`. Bu parça, ajan tarafından küçük bir `main` ile derlenip denendi: "FEDCBA" için 15, "ABCDEF" için 5 karşılaştırma çıktı.

- **En kötü durumun matematiksel analizi.** Dış döngü $i = 0, \dots, n-1$, iç döngü $j = 0, \dots, n-i-2$ çalışır ve her adımda bir karşılaştırma yapılır. Hoca tahtada iç toplamı $n-i$ alarak $\sum_{i=0}^{n-1}(n-i) = n^2 - \frac{n(n-1)}{2} = \frac{n^2+n}{2}$ buldu ve sonucu $O(n^2)$ diye verdi (ekrandan, 00:20:00).

  > **Ders sonrası not:** İç döngünün üst sınırı ($j < n-i-1$) dahil olmadığı için iç döngü $n-i-1$ kez döner. Doğru sayım $\sum_{i=0}^{n-2}(n-1-i) = \frac{n(n-1)}{2}$'dir; $n = 6$ için 15 eder ve derste çalıştırılan programın çıktısıyla uyuşur. Büyük O sonucu ($O(n^2)$) değişmez.

  En iyi durumda (dizi zaten sıralı) ilk turda hiç yer değiştirme olmaz, `swapped` 0 kalır ve döngü biter: $n-1$ karşılaştırma, yani $O(n)$.

- **$\lfloor \log_2 n \rfloor$ fonksiyonu.** Yineleme bağıntısı yazıldıktan sonra kod kolaydır: `if (n <= 1) return 0; else return 1 + f(n/2);`. Tamsayı bölmesi aşağı yuvarlamayı kendiliğinden sağlar. $f(1024)$: $1 + f(512) \to 1 + f(256) \to \dots \to 1 + f(1) = 1 + 0$; toplam 10 (ekrandan, 00:25:00). Analiz için $T(n) = 1 + T(n/2)$ yazılır; yerine koyunca $T(n) = i + T(n/2^i)$ olur, $n/2^i = 1$ iken $i = \log_2 n$ ve $T(1) = 0$ olduğundan $T(n) = \log_2 n$. Master teoreminde $a=1$ (tek özyinelemeli çağrı), $b=2$ (problem ikiye bölünür), ek iş sabit olduğu için $d=0$; $a = b^d = 1$ durumunda sonuç $\Theta(n^0 \log n) = \Theta(\log n)$'dir.

- **Robot para toplama tablosu.** Paraların konumları (satır, sütun): (1,5), (2,2), (2,4), (3,4), (3,6), (4,3), (4,6), (5,1), (5,5) (ekrandan, 00:30:00). Doldurulan $P$ tablosu (ekrandan, 00:35:00; ajan Python ile doğruladı):

  | $i \backslash j$ | 1 | 2 | 3 | 4 | 5 | 6 |
  |---|---|---|---|---|---|---|
  | 1 | 0 | 0 | 0 | 0 | 1 | 1 |
  | 2 | 0 | 1 | 1 | 2 | 2 | 2 |
  | 3 | 0 | 1 | 1 | 3 | 3 | 4 |
  | 4 | 0 | 1 | 2 | 3 | 3 | 5 |
  | 5 | 1 | 1 | 2 | 3 | 4 | 5 |

  Geriye izleme (5,6)'dan başlar: (4,6) → (3,6) → (3,5) → (3,4) → (2,4) → (2,3) → (2,2) → başlangıca (ya (1,2) üzerinden ya (2,1) üzerinden; ikisi de 0 olduğu için rota tek değildir). Toplanan paralar (2,2), (2,4), (3,4), (3,6), (4,6): 5 para.

- **Öncelikli kuyrukta durumlar (ekrandan, 00:40:00 ve 00:45:00).** Örnekte sırayla 5, 8, 3 gelir; 3 en öne geçer. Ekleme üç durumda incelenir: (1) front'un gösterdiği yere ekleme: dizide 1 ekleme + $n$ kaydırma $= O(n)$, bağlı listede $O(1)$; (2) rear'ın gösterdiği yere ekleme: ikisinde de kaydırma yok, $O(1)$; (3) araya ekleme: dizide kaydırma gerektiği için $O(n)$, bağlı listede $O(1)$. Bunlardan önce yerin bulunması gerekir: en iyi $\Omega(1)$, en kötü $O(n)$. Bu yüzden tek ekleme en kötü $O(n)$, $n$ elemanı sırayla eklemek $O(n^2)$ olur; heap bu maliyeti düşürmek için kullanılır.

- **Heap örneği ve ekleme (ekrandan, 00:50:00 ve 00:55:00).** 5, 8, 11, 13, 9, 20, 30, 40 sırayla eklenince dizi `5 8 11 13 9 20 30 40` olur; kök en küçük elemandır. Hoca sonra 40 yerine 2 ekledi: 2 indis 7'ye yazılır, ebeveyni indis 3'teki 13 ile yer değiştirir, sonra indis 1'deki 8 ile, sonra kökteki 5 ile; sonuç `2 5 11 8 9 20 30 13`. Ekleme ve yukarı yığınlaştırma için tahtadaki sözde kod (ekrandan, 01:00:00):

  ```text
  void Add(A, N, MAX, e)
      if (MAX == N) return (FULL)
      else
          N++
          A[N-1] = e
          HeapUp(A, N-1)
          SUCCESSFUL

  void HeapUp(A, i)
      if (i == 0) return
      p = getP(i)
      if (A[p] > A[i])
          swap(A[p], A[i])
          HeapUp(A, p)
  ```

  <!-- BELİRSİZ: HeapUp gövdesinin "if" ve "swap" satırları karelerde görünmüyor; altyazıdaki anlatımdan (00:59:38-01:01:07) kuruldu. -->

- **Kök alma ve aşağı yığınlaştırma (ekrandan, 01:20:00 ve 01:25:00).** Kök `*e`'ye alınır, son eleman köke taşınır, eleman sayısı bir azaltılır ve kökten başlayarak aşağı yığınlaştırılır. Aşağı yığınlaştırmada önce sağ çocuğa bakılır: sağ çocuk yoksa ve sol da yoksa dönülür; yalnız sol varsa `min = left`; ikisi de varsa küçük olan seçilir. Düğüm bu çocuktan büyükse yer değiştirilir ve işlem o çocuk için tekrarlanır. Örnek: 8, 9, 11, 13, 35, 20 heap'inden sırayla kök alınınca 8, 9, 11, 13, 20, 35 çıkar (ajan C ile doğruladı).

- **Belirlenimci olmayan arama ve sıralama (ekrandan, 01:45:00).** Belirlenimci olmayan aramada rastgele bir $j$ seçilir ve $A[j] = x$ ise başarı, değilse başarısızlık döner; maliyet $O(1)$'dir ama her seferinde bulma garantisi yoktur. Belirlenimci olmayan sıralamada (NSort) $A$'nın her elemanı $B$'de rastgele seçilen boş bir yere konur (tahmin, $O(n)$), sonra $B$'nin sıralı olup olmadığı tek geçişte kontrol edilir (doğrulama, $O(n)$). Tahmin aşaması her çalıştırmada farklı sonuç verebilir; doğrulama aşaması aynı girdiyle hep aynı sonucu verir.

- **Problem sınıfları şeması (ekrandan, 01:55:00).** Bir $X$ problemi için polinom zamanlı bir çözüm varsa $X$, P tipindedir. Çözüm polinom zamanda bulunamıyor ama verilen bir çözüm polinom zamanda doğrulanabiliyorsa $X$ NP problemidir. Tahtadaki şemada P, NP'nin içindedir; NP-complete için "çözüm NP, doğrulama P", NP-hard için "çözüm NP, P'de doğrulanamaz" yazıldı.

  > **Ders sonrası not:** Standart tanımlarda NP-hard, her NP probleminin polinom zamanda indirgenebildiği problemler sınıfıdır; NP-complete ise hem NP'de hem NP-hard olan problemlerdir (şemadaki kesişim). Gezgin satıcı probleminin karar biçimi NP-complete, en iyileme biçimi NP-hard'dır. Hoca durma problemini (halting problem) "polinom zamanda çözülemeyen" bir problem olarak andı; doğrusu, durma problemi hiçbir algoritmayla çözülemez (karar verilemez, undecidable).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
