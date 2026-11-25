# Ders 16 Çalışma Özeti

## Genel Konular

- Özyinelemeli (recursive) algoritmaların analizi: fark denklemi (recurrence relation)
  - İteratif algoritmalarda döngünün kaç kez döndüğü sayılır. Özyinelemeli algoritmada döngü yoktur; tekrar, fonksiyonun kendini çağırmasıyla olur. Bu tekrar bir fark denklemiyle (recurrence relation) yazılır.
  - Özyinelemeli algoritma iki kısımdan oluşur: temel adım (basic step, algoritmanın sonsuza gitmesini engeller) ve özyinelemeli adım (recursive step).
  - Genel biçim (ekrandan, 00:10:00): $T(n)=\alpha+T(n-a)$ ya da $T(n)=\alpha+T(n/b)$. $\alpha$ temel adımın maliyetidir (döngü yoksa sabit, $1$ alınır; döngü varsa $n$, $n^2$ gibi olabilir).
  - İki bilinmeyenden ($T(n)$ ve $T(n-a)$) kurtulmak için başlangıç koşulu (initial condition) kullanılır: $T(0)=1$ ya da $T(1)=1$.
  - Karmaşıklık bulmak, fonksiyonun döndürdüğü değeri ($n!$ gibi) bulmak değildir; yapılan işlem sayısını bulmaktır.
- Fark denklemini çözme yöntemleri
  - Geriye doğru yerine koyma (backward substitution): bilinmeyen $n$'den bilinen temel duruma ($0$ ya da $1$) doğru açılır, bir örüntü bulunur, $k$ yerine temel duruma götüren değer yazılır.
  - İleriye doğru yerine koyma (forward substitution): bilinenden bilinmeyene gider; derste yalnız adı geçti.
  - Özyineleme ağacı (recursion tree): her çağrının maliyeti ağacın düğümüne yazılır, ağacın yüksekliği bulunur, bütün düğümler toplanır.
- Faktöriyel örneği (ekrandan, 00:15:00)
  - `myFactorial`: `if(N==0) return 1;` ve `T = N*myFactorial(N-1);`. Kontrol ve `return` sabit işlemdir, $1$ alınır.
  - $T(N)=1+T(N-1)$, $T(0)=1$. Açılım: $T(N-2)+2$, $T(N-3)+3$, ..., $T(N-k)+k$. $k=N$ için $T(0)+N=N+1$, yani $O(N)$.
  - Özyineleme ağacı da aynı sonucu verir: her seviyede bir birim iş, ağacın derinliği $N$.
  - İteratif çözüme göre zaman kazancı yoktur; ayrıca her fonksiyon çağrısı bellek (yığın) harcar.
- $x^n$ hesabı için beş algoritma (ekrandan, 00:25:00 - 00:55:00)
  - `power1`: `for` döngüsüyle $n$ çarpma, $T(n)=\sum_{i=1}^{n}1=n$.
  - `power2`: `return x*power2(x,n-1);`, $T(n)=1+T(n-1)$, $O(n)$.
  - `power3`: iteratif hızlı üs alma. $n$ çiftse `x=x*x; n=n/2;`, tekse `r=r*x; n=n-1;`. $O(\log_2 n)$.
  - `power4`: `power4(x,n/2)*power4(x,n/2)` (tekse başa `x*`). $T(n)=1+2T(n/2)$, sonuç $O(n)$; aynı alt problem iki kez hesaplandığı için kazanç yok.
  - `power5`: `t = power5(x,n/2);` bir kez hesaplanır, çiftse `t*t`, tekse `x*t*t` döndürülür. $T(n)=1+T(n/2)$, $T(1)=1$, sonuç $\log_2 n+1$, yani $O(\log n)$.
- Merge Sort (ekrandan, 01:15:00 - 01:45:00)
  - Merge: iki sıralı diziyi (örnek `1 4 7` ve `2 5 8`) `i`, `j` işaretçileri ve yerleştirme indisi `k` ile birleştirir; sonuç `1 2 4 5 7 8`. Maliyet $n+m=N$.
  - Merge Sort: dizi tek elemanlı parçalar kalana kadar ikiye bölünür, sonra parçalanmaya simetrik olarak sıralı parçalar birleştirilir.
  - Kod: `if(l<r){ m = l + (r-l)/2; mergeSort(d,l,m); mergeSort(d,m+1,r); merge(d,l,m,r); }`.
  - $T(N)=2T(N/2)+N$, $T(1)=1$. Çözüm $N\log_2 N+N$, yani $O(N\log N)$.
  - Quick Sort için de fark denklemi aynıdır; ama Quick Sort bu derste ayrıntılı anlatılmadı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hazır `pow` fonksiyonu varken neden kendimiz yazıyoruz?
  - Amaç olayın mantığını anlamak ve algoritma tasarlamayı öğrenmektir. Bazı problemlerde kendi özyinelemeli fonksiyonunuzu yazmak zorunda kalırsınız; basit örnekleri yapmadan karmaşık olanları tasarlamak zordur.
- Karmaşıklık değer hesabı değildir
  - Fark denklemiyle $n!$'in değeri bulunmaz, yapılan işlem sayısı bulunur.
- Aynı alt problemi iki kez çağırmak kazancı yok eder
  - `power4` ile `power5` arasındaki tek fark, $x^{n/2}$ sonucunun bir değişkende saklanmasıdır. Bu küçük değişiklik $O(n)$'i $O(\log n)$'e indirir.
- Backward substitution açılırken dıştaki katsayı unutulmamalı
  - Hoca `power4` açılımında $2$ katsayısını önce unuttuğunu fark edip düzeltti: $n/2$ açılırken dıştaki $2$ de çarpılır, katsayı $2^k$ olur.
- Merge Sort neden iyi?
  - Bubble, insertion ve selection sort $O(n^2)$ iken Merge Sort ve Quick Sort $O(n\log n)$'dir. Merge Sort ek dizi kullanır; Quick Sort sıralamayı dizinin kendi yerinde yapar.

## Kısa Tekrar Notları

- Özyinelemeli algoritma = temel adım + özyinelemeli adım; analiz için fark denklemi ve başlangıç koşulu yazılır.
- Yöntemler: backward substitution, forward substitution, recursion tree.
- $T(n)=1+T(n-1)$ → $O(n)$ (faktöriyel, `power2`).
- $T(n)=1+T(n/2)$ → $O(\log n)$ (`power5`, iteratif karşılığı `power3`).
- $T(n)=1+2T(n/2)$ → $2n-1$, $O(n)$ (`power4`).
- $T(n)=2T(n/2)+n$ → $n\log_2 n+n$, $O(n\log n)$ (Merge Sort, Quick Sort).
- $n/2^k=1$ ise $k=\log_2 n$; ağacın yüksekliği $\log_2 n$'dir.
- İki sıralı diziyi birleştirmenin maliyeti toplam eleman sayısı kadardır.

## Detaylı Açıklamalar

Derse bir önceki derste başlanan özyinelemeli algoritmaların analiziyle devam edildi. İteratif algoritmalarda döngünün dönme sayısı sayılıyordu. Özyinelemeli algoritmada döngü yoktur, bu yüzden tekrar bir bağıntıyla yazılır. Algoritmanın karmaşıklığına $T(n)$ denir. Temel adımdan $n$'e bağlı bir maliyet çıkar (döngü yoksa sabit), özyinelemeli adımdan ise $T(n-a)$ ya da $T(n/b)$ gibi daha küçük bir problemin maliyeti gelir. Bu iki bilinmeyenden birini, temel adıma karşılık gelen başlangıç koşuluyla ($T(0)=1$ gibi) yok ederiz. Bağıntı, $n$ bu başlangıç koşuluna yaklaşana kadar açılır.

Faktöriyel fonksiyonunda temel adım `N==0` kontrolü ve `return 1`'dir; bu iki birimlik iş $n$'den bağımsız olduğu için $1$ kabul edilir. Fonksiyon kendini $N-1$ ile çağırdığı için $T(N)=1+T(N-1)$ olur. Geriye doğru açınca $T(N)=T(N-k)+k$ örüntüsü çıkar; $k=N$ seçilince $T(0)+N=N+1$ bulunur. Yani faktöriyelin özyinelemeli sürümü de iteratif sürüm gibi $O(N)$'dir, üstelik her çağrı yığında yer tuttuğu için bellek açısından daha verimsizdir.

$x^n$ örneğinde önce iteratif `power1` yazıldı (`n==0 && x!=0` ise $1$, `n==0 && x==0` ise tanımsızlığı göstermek için $-1$ döndürülüyor). Sonra özyinelemeli `power2` yazıldı; ikisi de $O(n)$. `power3` iteratif hızlı üs almadır: $n$ çiftse taban karesine çıkarılıp üs yarıya iner, tekse sonuç bir kez tabanla çarpılıp üs bir azaltılır. Üs çoğunlukla yarılandığı için döngü yaklaşık $\log_2 n$ kez döner. `power4` bu fikrin doğrudan özyinelemeli karşılığıdır ama $x^{n/2}$'yi iki kez çağırır; fark denklemi $T(n)=1+2T(n/2)$ olur ve çözüm $O(n)$ çıkar. `power5` ise $x^{n/2}$'yi bir kez hesaplayıp `t` değişkeninde saklar; $T(n)=1+T(n/2)$ olur ve çözüm $\log_2 n+1$, yani $O(\log n)$'dir. Bu, özyinelemenin gerçek bir avantaj sağladığı ilk örnektir.

> **Ders sonrası not:** Hoca `power4` için backward substitution yaparken genel terimi $2^k T(n/2^k)+k\cdot1$ yazıp sonucu $n+\log_2 n$ buldu. Toplamsal kısım her seviyede ikiye katlandığı için doğrusu $2^kT(n/2^k)+(2^k-1)$'dir; $k=\log_2 n$ için $T(n)=2n-1$ olur (python ile $n=16$ için $31$, $n=1024$ için $2047$ doğrulandı). Derste gösterilen ders notunda da (ekrandan, 01:10:00) sonuç $2N-1=O(n)$ olarak yazılıdır. Varılan $O(n)$ sonucu değişmez.

Merge Sort'ta önce merge işlemi hatırlatıldı: iki sıralı dizide `i` ve `j` işaretçileri ilerletilir, küçük olan eleman `k` konumuna yazılır. Toplam $n+m$ eleman için $n+m$ işlem yapılır. Merge Sort diziyi `l` ve `r` sınırlarıyla ikiye böler (`m = l + (r-l)/2`), iki yarıyı ayrı ayrı sıralar, sonra `merge(d,l,m,r)` ile birleştirir. Ders sırasında `main` içinde 8 elemanlı bir dizi `mergeSort(d,0,N-1)` ile çağrıldı ve dizi sıralamadan önce ve sonra yazdırıldı. Fark denklemi $T(N)=2T(N/2)+N$'dir; geriye doğru açınca $2^kT(N/2^k)+kN$ örüntüsü çıkar, $k=\log_2 N$ için $N\cdot T(1)+N\log_2 N=N\log_2 N+N$ bulunur. Ağaç yöntemiyle bakınca her seviyede toplam $N$ iş vardır ve $\log_2 N$ seviye olduğundan sonuç yine $O(N\log N)$'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
