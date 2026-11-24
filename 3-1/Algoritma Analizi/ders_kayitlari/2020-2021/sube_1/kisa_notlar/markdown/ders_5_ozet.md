# Ders 5 Çalışma Özeti

## Genel Konular

- Önceki dersin asimptotik gösterim örneklerine dönüş
  - $n^2 + n \in O(n)$ iddiası yanlıştır. $c = 5$, $n_0 = 1$ seçilirse $n = 1, 2, 3, 4$ için $n^2 + n \le 5n$ sağlanır, ama $n = 5$ için $30 \le 25$ olur ve şart bozulur. Tanım, şartın bir $n_0$ noktasından sonra **her** $n$ için sağlanmasını ister; küçük $n$'lerde sağlanması yetmez.
  - Big Θ (tight bound) tanımı: $0 \le c_1 g(n) \le f(n) \le c_2 g(n)$, $n \ge n_0$ (ekrandan, 00:05:00). $2n + 5 \in \Theta(n)$ diyebilmek için hem $O(n)$ hem $\Omega(n)$ şartı sağlanmalıdır.
  - $O(n)$ tarafı için $c = 7$, $n_0 = 1$ seçimi doğrudur: $2n + 5 \le 7n$, $n \ge 1$.
  - $\Omega(n)$ tarafında önceki derste seçilen $c = 4$ yanlıştır: $n = 3$ için $11 \ge 12$ sağlanmaz. Hoca bunu bir öğrencinin sorusu üzerine fark etti; önemli olanın seçilen sabit ve $n_0$ olduğunu söyledi.
- Özyinelemeli (rekürsif) algoritmaların matematiksel analizi (ekrandan, 00:10:00)
  - Rekürsif olmayan algoritmalarda temel işlem (basic operation) en çok tekrar eden, genellikle döngü içindeki işlemdi. Rekürsif algoritmalarda fonksiyon kendini çağırdığı için hesap farklı yapılır.
  - Adımlar (ekrandan, 00:25:00):
    - Temel işlemi belirle (rekürsif çağrının yapıldığı kısım).
    - Bu işlem için bir yineleme bağıntısı (recurrence relation) kur; durma şartını (başlangıç koşulunu) da yaz.
    - Bağıntıyı çöz.
  - Yineleme bağıntısı (recurrence), bir fonksiyonun kendisi cinsinden (rekürsif) tanımıdır.
- Örnek 1: faktöriyel
  - $F(n) = 1$ ($n = 0$), $F(n) = n \cdot F(n-1)$ ($n > 0$).
  - Temel işlem çarpmadır. $M(n)$ = çarpma sayısı: $M(n) = M(n-1) + 1$, $M(0) = 0$. $M(n-1)$, $F(n-1)$'in hesabındaki çarpmalar; $+1$, $n \cdot F(n-1)$ çarpmasıdır (ekrandan, 00:15:00).
  - Geriye doğru yerine koyma: $M(n) = M(n-2) + 2 = M(n-3) + 3 = \dots = M(n-i) + i$. $i = n$ alınınca $M(n) = M(0) + n = n$ (ekrandan, 00:20:00).
  - Sonuç: $M(n) \in \Theta(n)$; faktöriyelde en iyi, ortalama ve en kötü durum aynıdır.
- Örnek 2: pozitif bir ondalık tamsayının ikili gösterimindeki basamak sayısı (ekrandan, 00:30:00)
  - 27 sürekli 2'ye bölünür: 27 → 13 → 6 → 3 → 1. Kalanlar tersten okunur: $27 = 11011_2$, 5 basamak.
  - Kod (ekrandan, 00:35:00):
    - `if (n == 1) return 1; else return binary(n/2) + 1;`
  - Temel işlem toplamadır. $A(n)$ = toplama sayısı: $A(n) = A(n/2) + 1$ ($n > 1$), $A(1) = 0$.
  - Geriye doğru yerine koyma: $A(n) = A(n/4) + 2 = A(n/8) + 3 = A(n/2^i) + i$. $n = 2^i$ alınınca $i = \log_2 n$ ve $A(n) = A(1) + \log_2 n = \log_2 n$.
- Yineleme bağıntılarını çözme yolları
  - Geriye doğru yerine koyma (backward substitution). Ek örnek: $x(n) = x(n-1) + n$, $x(0) = 0$ ise $x(n) = 1 + 2 + \dots + n = \frac{n(n+1)}{2} \in O(n^2)$.
  - İleriye doğru yerine koyma (forward substitution): $x(n) = 2x(n-1) + 1$ ($n > 1$), $x(1) = 1$ için $x(1) = 1$, $x(2) = 3$, $x(3) = 7$, $x(4) = 15$; yani $x(n) = 2^n - 1$ (ekrandan, 00:55:00). Hesabı geriye doğru yerine koymadan daha zahmetlidir.
  - Master teoremi (ekrandan, 01:10:00):
    - $T(n) = a\,T(n/b) + f(n)$, $f(n) \in \Theta(n^d)$, $d \ge 0$.
    - $a < b^d$ ise $T(n) \in \Theta(n^d)$; $a = b^d$ ise $T(n) \in \Theta(n^d \log n)$; $a > b^d$ ise $T(n) \in \Theta(n^{\log_b a})$.
    - Aynı sonuçlar $O$ ve $\Omega$ için de geçerlidir.
    - $a$: alt problem sayısı; $n/b$: her alt problemin boyutu; $f(n)$: rekürsif çağrıların dışında yapılan ek iş.
- Böl ve yönet (divide and conquer) algoritmaları (ekrandan, 01:35:00)
  - Üç aşama: böl (divide), her parçayı ayrı çöz (conquer), parçaların çözümlerini birleştir (combine).
  - $n$ boyutlu problem genellikle yaklaşık $n/2$ boyutlu iki alt probleme bölünür; alt problemler birbirine karışmadan çözülür.
  - Böl ve yönet algoritmaları rekürsiftir. Her problem bu yaklaşıma uygun değildir; bölmenin gerçekten kazanç getirip getirmediğine bakılmalıdır.
- Merge sort (top-down)
  - Kod iskeleti (ekrandan, 01:50:00):
    - `if (p < r) { q = (p+r)/2; mergesort(A, p, q); mergesort(A, q+1, r); merge(A, p, q, r); }`
  - $p = r$ ise tek eleman kalmıştır, rekürsiyon durur.
  - 8 3 2 9 7 1 5 4 dizisinin izlenmesi; sonuç 1 2 3 4 5 7 8 9.
  - `merge` aynı dizinin $[p..q]$ ve $[q+1..r]$ parçalarını birleştirir; bunu A üzerinde yerinde yapmak sırayı bozar, bu yüzden `malloc` ile yer alınan geçici bir B dizisi kullanılır, sonunda B, A'ya kopyalanır (ekrandan, 01:55:00).
  - Analiz: $T(n) = 2T(n/2) + n$, $T(1) = 1$ (ekrandan, 02:00:00). Geriye doğru yerine koyma ile $T(n) = 2^i T(n/2^i) + i\,n$; $n = 2^i$ alınınca $T(n) = n + n \log_2 n \in \Theta(n \log n)$.
  - İyileştirmeler (ekrandan, 02:05:00): küçük alt dizilerde insertion sort kullan; birinci yarının en büyük elemanı ikinci yarının en küçüğünden küçük ya da eşitse birleştirmeye gerek yoktur.
- Quick sort
  - Diziyi değere göre böler: pivottan küçükler sola, büyükler sağa. Bölme noktası pivotun sıralı dizideki yerine bağlıdır, tam ortadan bölme gibi bir durum yoktur.
  - 5 3 1 9 8 2 4 7 örneği (pivot = 5) sonunda 2 3 1 4 **5** 8 9 7 elde edilir (ekrandan, 02:10:00); sol ve sağ parça ayrı ayrı sıralanır.
  - Sıralı dizide ilk eleman pivot alınırsa en kötü durum $n^2$ olur. Çözüm: diziyi baştan karıştırmak (shuffle) ya da pivotu başka bir elemandan seçmek.

## Hocanın Özellikle Vurguladığı Kısımlar

- Asimptotik gösterimde şart, $n_0$'dan sonraki her $n$ için sağlanmalıdır.
  - Küçük $n$'lerde sağlanıp $n$ büyüyünce bozulan bir eşitsizlik, o gösterime ait olmayı kanıtlamaz. Bu yanlış anlama sınavda sorun çıkarır.
- Yineleme bağıntısı yazarken durma şartı mutlaka yazılmalıdır.
  - Bağıntı, durma noktası kullanılarak çözülür; geriye doğru giderken bilinmeyenden ancak durma koşuluna ulaşılınca kurtulunur.
- Master teoremi ile hesap yapmaya gerek kalmaz.
  - Yalnız $a$, $b$, $d$ bulunur, $a$ ile $b^d$ karşılaştırılır, karşılık gelen ifade yazılır.
  - Teorem polinom biçimli bağıntılar içindir; $x(n) = 2x(n-1) + 1$ gibi $n-1$ içeren bağıntıya uygulanamaz.
  - $T(n/b)$ biçiminde $b$ böleni alınır: $T(2n/3)$ için $b = 3/2$ olur (bir öğrencinin düzeltmesi).
- Böl ve yönet uygulanmadan önce bölmenin kazanç getirip getirmediğine bakılmalı.
  - Quick sort'ta pivot yerine oturunca sol parçayı sıralarken sağ parçaya hiç bakılmaz; bu, algoritmayı değerli kılan özelliktir.
- Küçük dizilerde rekürsif sıralama kullanılmaz.
  - Rekürsiyonun ek yükü (overhead) küçük dizilerde kazancı siler; Java'nın sıralama kütüphanesi de küçük diziler için insertion sort çağırır.
- Merge sort'ta $\Theta(n \log n)$ yazılabilir.
  - `merge` her durumda $n$ elemanın hepsini yerleştirir, bölme de her durumda aynıdır; en iyi, ortalama ve en kötü durum aynıdır.

## Kısa Tekrar Notları

- Rekürsif analiz: temel işlem → yineleme bağıntısı + başlangıç koşulu → çözüm.
- Faktöriyel: $M(n) = M(n-1) + 1$, $M(0) = 0$ → $M(n) = n \in \Theta(n)$.
- İkili basamak sayısı: $A(n) = A(n/2) + 1$, $A(1) = 0$ → $A(n) = \log_2 n$.
- $x(n) = x(n-1) + n$, $x(0) = 0$ → $\frac{n(n+1)}{2} \in O(n^2)$.
- $x(n) = 2x(n-1) + 1$, $x(1) = 1$ → $2^n - 1$.
- Master teoremi: $a < b^d \Rightarrow \Theta(n^d)$; $a = b^d \Rightarrow \Theta(n^d \log n)$; $a > b^d \Rightarrow \Theta(n^{\log_b a})$.
- $T(n) = 3T(n/2) + n^2$: $3 < 4$ → $\Theta(n^2)$. $T(n) = T(2n/3) + 1$: $a = 1$, $b = 3/2$, $d = 0$, $1 = 1$ → $\Theta(\log n)$.
- Merge sort: $T(n) = 2T(n/2) + n$ → $\Theta(n \log n)$; geçici dizi gerekir.
- Quick sort: ortalama $n \log n$, sıralı dizide ilk eleman pivotsa $n^2$.
- Hocanın verdiği süre tablosu (saniyede $10^8$ karşılaştırma): $n = 10^6$ için insertion sort 2,8 saat, merge sort 1 saniye, quick sort 0,6 saniye; $n = 10^9$ için 317 yıl, 18 dakika, 12 dakika.

## Detaylı Açıklamalar

- Ders, önceki derste çözülen iki asimptotik gösterim örneğinin açıklığa kavuşturulmasıyla başladı. $n^2 + n$ fonksiyonu için $c = 5$, $n_0 = 1$ seçildiğinde $n = 1$ için $2 \le 5$, $n = 2$ için $6 \le 10$, $n = 3$ için $12 \le 15$, $n = 4$ için $20 \le 20$ sağlanır; ama $n = 5$ için $30 \le 25$ yanlıştır ve bundan sonra hiç sağlanmaz. Bu nedenle $n^2 + n \notin O(n)$. İkinci örnekte $2n + 5 \in \Theta(n)$ gösterilirken üst sınır için $c = 7$ doğru seçilmişti, ama alt sınır için seçilen $c = 4$ ile $2n + 5 \ge 4n$ eşitsizliği $n = 3$'te bozulur ($11 < 12$).
- > **Ders sonrası not:** Hoca $c_2$ değerini sonra düzelteceğini söyledi; bu kayıtta düzeltme yok. Örneğin $c = 2$ (ya da $c = 1$) seçilirse $2n + 5 \ge 2n$ her $n \ge 1$ için sağlanır, böylece $2n + 5 \in \Omega(n)$ ve $\Theta(n)$ olur (python ile doğrulandı).
- Rekürsif bir algoritmada basit bir döngü sayımı yapılamaz, çünkü fonksiyon kendini çağırır. Bu yüzden önce maliyet bir yineleme bağıntısıyla yazılır. Faktöriyelde $M(n) = M(n-1) + 1$ bağıntısı açık bir ifade değildir: $M(n-1)$'in değeri bilinmez. Geriye doğru yerine koyma ile $M(n-1) = M(n-2) + 1$ yazılır, böyle devam edilince $M(n-i) + i$ kalıbı görülür. Bilinmeyenden kurtulmak için durma koşuluna gidilir: $n - i = 0$, yani $i = n$ olunca $M(0) = 0$ (hiç çarpma yok) kullanılır ve $M(n) = n$ bulunur. Hoca, $n = 0$ kontrolü bir işlem sayılırsa $M(0) = 1$ de denebileceğini, ama çarpma sayıldığı için 0 demenin daha doğru olduğunu söyledi.
- İkili basamak örneğinde algoritma $n$ 1 olana kadar 2'ye böler ve her bölmede bir basamak sayar. Koddaki `+1` bir sayaç gibi çalışır: her çağrıda bir basamak daha bulunmuştur. Toplama sayısı $A(n) = A(n/2) + 1$, $A(1) = 0$ bağıntısını verir. Bunun çözümü $\log_2 n$'dir; 27 için toplama sayısı 4, basamak sayısı 5'tir (python ile doğrulandı; $n = 2^i$ olmayan sayılarda $\lfloor \log_2 n \rfloor$). Problem yalnız pozitif sayılar için tanımlıdır; 0 ele alınmaz.
- Master teoremi, $T(n) = aT(n/b) + f(n)$ biçimindeki bağıntılar için hazır sonuç verir. Merge sort'ta $f(n) = n$ (iki sıralı parçayı birleştirme işi), yani $d = 1$; ikili basamak örneğinde ek iş tek bir toplama olduğu için $f(n) = 1 = n^0$, yani $d = 0$. Derste $T(n) = 3T(n/2) + n^2$ için $a = 3$, $b = 2$, $d = 2$; $3 < 2^2$ olduğundan $\Theta(n^2)$ bulundu. $T(n) = T(2n/3) + 1$ için $a = 1$, $b = 3/2$, $d = 0$; $1 = (3/2)^0$ olduğundan $\Theta(\log n)$ bulundu.
- > **Ders sonrası not:** Hoca master teoremini ikili basamak örneğine uygularken bağıntıyı $2A(n/2) + 1$ olarak yazdı ($a = 2$) ve $a > b^d$ durumundan $\Theta(n)$ buldu. Derste kurulan bağıntı $A(n) = A(n/2) + 1$'dir (ekrandan, 01:05:00); doğrusu $a = 1$, $b = 2$, $d = 0$, $1 = 2^0$ olduğundan $\Theta(\log n)$'dir. Bu, geriye doğru yerine koymayla bulunan $\log_2 n$ ile de uyumludur. $\Theta(n)$ sonucu yalnız $T(n) = 2T(n/2) + 1$ bağıntısı için doğrudur.
- Merge sort izlemesinde (8 3 2 9 7 1 5 4) önce $ms(0,7)$, $q = 3$ ile $ms(0,3)$ çağrılır; o da $q = 1$ ile $ms(0,1)$'i, o da $ms(0,0)$ (8) ve $ms(1,1)$'i (3) çağırır; birleştirme 3 8'i verir. Sonra $ms(2,3)$: $ms(2,2)$ (2) ve $ms(3,3)$ (9), birleştirme 2 9'u verir. $merge(0,1,3)$ ile 2 3 8 9 elde edilir. Sağ yarı aynı şekilde 1 4 5 7 olur ve son birleştirme 1 2 3 4 5 7 8 9'u verir (python ile doğrulandı).
- > **Ders sonrası not:** Tahtada $ms(2,2) \to 9$ ve $ms(3,3) \to 7$ yazıldı (ekrandan, 01:50:00); hoca bunu fark edip düzeltti. Dizinin 2. gözünde 2, 3. gözünde 9 vardır; doğrusu $ms(2,2) \to 2$, $ms(3,3) \to 9$'dur.
- `merge` aynı A dizisinin iki parçasını karşılaştırır: $i = p$, $j = q+1$ ile başlanır, `while (i <= q && j <= r)` döngüsünde küçük olan eleman B'ye yazılır, sonra biten taraf dışında kalan elemanlar da B'ye aktarılır ve B, A'ya geri kopyalanır. Elemanları A üzerinde yer değiştirerek birleştirmek sırayı bozar; örneğin 8 9 ile 2 7 birleştirilirken 2 ile 8 yer değiştirirse 8, 7'den önce kalır.
- Quick sort'ta pivot 5 iken soldan 9 (5'ten büyük), sağdan 4 (5'ten küçük) bulunur ve yer değiştirir: 5 3 1 4 8 2 9 7. Sonra 8 ile 2 yer değiştirir: 5 3 1 4 2 8 9 7. Son olarak pivot, son küçük eleman olan 2 ile yer değiştirir: 2 3 1 4 5 8 9 7. Sol parçada pivot 2 ile 3 ve 1 yer değiştirir, sonra pivot yerine oturur: 1 2 3 4. Sağ parçada pivot 8 ile 9 ve 7 yer değiştirir, sonra 7 ile 8: 7 8 9. Sonuç 1 2 3 4 5 7 8 9 (python ile doğrulandı).
- Quick sort'un merge sort'a göre daha hızlı olmasının nedeni daha az yer değiştirme yapmasıdır. Merge sort'un pek söylenmeyen bir dezavantajı da geçici dizi gerektirmesidir; eleman sayısı çok büyükse bu ek bellek sorun olur. Quick sort'un dezavantajı ise sıralı dizide ilk eleman pivot alınırsa her bölmede bütün elemanların bir tarafta kalması ve karmaşıklığın $n^2$'ye çıkmasıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
