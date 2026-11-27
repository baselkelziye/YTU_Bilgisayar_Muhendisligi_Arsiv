# Ders 5 Çalışma Özeti

## Genel Konular

- Algoritma kavramı
  - Algoritma, bir hesaplama ya da gerçek dünya problemini çözmek için sonlu sayıda, kesin (muğlak olmayan, "unambiguous") ve sıralı adımdan oluşan bir yöntemdir.
  - "Sayının karekökünü al" gibi bir ifade tek başına algoritma değildir; karekökün nasıl alınacağı adım adım söylenmelidir.
  - Sonluluk kodun satır sayısıyla değil, çalışmanın sonlu sayıda adımda bitmesiyle ilgilidir.
  - Algoritma sözle, adım adım yazıyla, sözde kodla (pseudocode), akış şemasıyla ya da bir programlama diliyle ifade edilebilir.
  - Örnek: bir tamsayı dizisinde en büyük elemanı bulma. İlk eleman geçici maksimum seçilir, sonraki her eleman onunla karşılaştırılır, büyükse geçici maksimuma atanır, dizi bitince sonuç bulunmuş olur.
- Algoritmaların özellikleri (ekrandan, 00:20:00)
  - Giriş (input), çıkış (output), doğruluk (correctness), sonluluk (finiteness), etkililik (effectiveness), genellik (generality).
  - Doğruluk her problemde yüzde yüz aranmaz: kesin çözümü çok pahalı olan problemlerde (örneğin gezgin satıcı problemi) yaklaşık ya da optimuma yakın çözüm yeterli olabilir.
  - Genellik: algoritma yalnız 10 elemanlı diziyi değil, $n$ elemanlı her diziyi işleyebilmelidir.
- Arama algoritmaları
  - Doğrusal arama (linear search): kaba kuvvet (brute force) yöntemiyle dizinin elemanlarını baştan başlayarak tek tek inceler (ekrandan, 00:25:00).
  - Döngü arada bir yerde bitebileceği için `for` yerine `while` kullanılır; döngü koşulu $i \le n$ ve $x \ne a_i$ birlikte kontrol edilir.
  - Aramada genellikle elemanın değeri değil, konumu (location) döndürülür; bulunamazsa 0 (ya da -1, null) döner.
  - İkili arama (binary search): dizi sıralı olmalıdır. Sol uç $i$, sağ uç $j$ ile tutulur, orta nokta $m$ bulunur, $x > a_m$ ise $i = m+1$, değilse $j = m$ yapılır; her adımda aranacak bölgenin yarısı elenir.
- Sıralama algoritmaları
  - Sıralama, öğeleri varsayılan olarak artan sıraya koymaktır; bir tür indeksleme olarak kayıtlara hızlı erişimi sağlar (ekrandan, 00:30:00).
  - Kabarcık sıralama (bubble sort): komşu elemanlar karşılaştırılır, sıra dışıysa yer değiştirilir. Her turun sonunda kalanların en büyüğü sona gider (ekrandan, 00:35:00).
  - Hiç yer değiştirme (swap) yapılmayan bir turdan sonra dizi sıralıdır; bir bayrak (flag) değişkeniyle algoritma erken bitirilebilir.
  - Seçmeli sıralama (selection sort): kalanlar içinden en küçüğü bulunup sıradaki konuma yazılır. Eleman konumları açısından kabarcık sıralamanın tersi gibi düşünülebilir.
  - Araya eklemeli sıralama (insertion sort): oyun kartlarını dizmeye benzer. İlk eleman sıralı kabul edilir, sonraki her eleman sıralı kısımda yerine eklenir; araya ekleme için diğer elemanların kaydırılması (shift) gerekir (ekrandan, 00:40:00).
- Öklid algoritması ile EBOB (GCD)
  - Klasik yol: küçük sayıdan geriye doğru inip iki sayıyı da bölen ilk sayıyı bulmak (ardışık tamsayı kontrolü).
  - Öklid: $\gcd(m,n) = \gcd(n, m \bmod n)$, $n=0$ olunca $m$ döndürülür (ekrandan, 00:45:00).
  - Örnekler: $\gcd(60,24)=12$, $\gcd(18,12)=6$, aralarında asal sayılar için $\gcd(7,3)=1$.
- Algoritma tasarım yöntemleri (ekrandan, 00:50:00)
  - Kaba kuvvet, böl ve yönet (divide and conquer), azalt ve yönet (decrease and conquer), dönüştür ve yönet (transform and conquer), bellek-zaman ödünleşimi, açgözlü (greedy), dinamik programlama, yinelemeli iyileştirme, geri izleme (backtracking), dal ve sınır (branch and bound).
  - Dönüştür ve yönet örneği: yalnız en küçüğü bulan bir fonksiyonla en büyüğü bulmak için tüm elemanlar $-1$ ile çarpılır, en küçük bulunur, sonuç tekrar $-1$ ile çarpılır.
- Temel problem türleri
  - Sıralama, arama, metin işleme (bir metinde örüntü arama), çizge problemleri, kombinatorik problemler, geometrik ve sayısal problemler (ikiye bölme ve regula falsi yöntemleri).
- Temel veri yapıları
  - Dizi (array) ve bağlı liste (linked list) bir boyutludur; bellek de bir boyutlu olduğu için diğer bütün veri yapıları bunların üzerine kurulan soyutlamalardır.
  - Dizi bellekte ardışık hücrelerde durur, rastgele erişim sağlar; araya ekleme kaydırma gerektirir.
  - Bağlı listede düğümler bellekte dağınık durabilir, her düğüm bir sonrakinin (çift yönlüde öncekinin de) adresini tutar; liste `head` işaretçisiyle başlar, son düğüm `NULL` gösterir; erişim sıralıdır, araya ekleme kaydırmasız yapılır.
  - Yığın (stack): ekleme ve çıkarma yalnız tepeden yapılır (LIFO). İşlemler `push` ve `pop`. Fonksiyon çağrılarında dönüş adreslerinin saklanması tipik kullanımıdır.
  - Kuyruk (queue): sondan (tail) ekleme, baştan (head) çıkarma yapılır (FIFO). İşlemler `enqueue` ve `dequeue`. Yazıcı kuyruğu ve BFS tipik kullanımlardır.
  - Öncelikli kuyruk (priority queue): elemanlar geliş sırasına göre değil önceliğe göre çıkar; örneğin işletim sistemindeki süreç öncelikleri.
- Yığın uygulaması: infix, prefix, postfix notasyonları (ekrandan, 01:30:00)
  - Infix: operatör iki operandın ortasında ($A+B$). Prefix (Polish notation): operatör önde ($+AB$). Postfix (Reverse Polish notation): operatör sonda ($AB+$).
  - Infix ifadede operatör önceliği işlemi zorlaştırır; bu yüzden ifade postfix ya da prefix biçime dönüştürülüp öyle hesaplanır. Dönüşümler yığınla ya da ikili ağaçla yapılır.
  - Infix değerlendirme iki yığınla yapılır (operand yığını ve operatör yığını). Örnek: $2 * (5 * (3+6)) / 15 - 2 = 4$ (ekrandan, 01:35:00).
  - Prefix değerlendirme: ifade ters çevrilir, tek yığın kullanılır; operatör gelince $s_1$ ve $s_2$ çekilip $s_1 \text{ op } s_2$ hesaplanır. Örnek: `- / * 20 * 50 + 3 6 300 2` $= 28$ (ekrandan, 01:45:00).
  - Postfix değerlendirme: soldan sağa okunur, tek yığın; operatör gelince $s_1$ ve $s_2$ çekilip $s_2 \text{ op } s_1$ hesaplanır. Örnek: `2 5 3 6 + * * 5 / 2 -` $= 16$ (ekrandan, 01:50:00).
  - Infix'ten postfix'e dönüşüm: operandlar doğrudan sonuca yazılır, operatörler önceliğe göre yığında bekletilir. Örnek: $A+B*(C\hat{\ }D-E) \Rightarrow$ `ABCD^E-*+` (ekrandan, 01:55:00).
  - Infix'ten prefix'e dönüşüm: ifade ters çevrilir, parantezler yer değiştirir, postfix algoritması uygulanır, sonuç ters çevrilir. Örnek: $A+B*(C\hat{\ }D-E) \Rightarrow$ `+A*B-^CDE` (ekrandan, 02:10:00).
  - Postfix'ten infix'e, prefix'ten infix'e, prefix'ten postfix'e ve postfix'ten prefix'e dönüşümler de tek yığınla yapılır; infix'e dönüşümde her ara sonuç paranteze alınır. Örnek: `*-A/BC-/AKL` (prefix) $\Leftrightarrow$ `ABC/-AK/L-*` (postfix) $\Leftrightarrow ((A-(B/C))*((A/K)-L))$ (ekrandan, 02:15:00).
- Algoritma analizine giriş
  - Deneysel (kaba) analiz: kodun başına ve sonuna saat ölçümü ya da sayaç konur, farklı girdi boyutları için süre ya da adım sayısı ölçülür.
  - Teorik analiz: zaman verimliliği, girdi boyutunun fonksiyonu olarak temel işlemin (basic operation) tekrar sayısıyla belirlenir (ekrandan, 02:20:00).
  - Temel işlem örnekleri: sıralama ve aramada karşılaştırma, matris işlemlerinde toplama ve çarpma, asallık testinde bölme ya da kalan işlemi (girdi boyutu sayının bit sayısı), çizgelerde düğüm ve kenar sayısı.
  - Yürütme zamanı $T(n)$ ve alan maliyeti (ek bellek ihtiyacı).
  - Seçmeli sıralama kodunun ayrıntılı analizi $T(n) = 2n^2 + 6n + 5$ sonucunu verir; baskın terim $n^2$'dir (ekrandan, 02:30:00).
  - Asimptotik notasyonlar: Büyük-O, Büyük-Omega, Büyük-Teta, küçük-o, küçük-omega (ve az kullanılan tilde).
  - Büyüme sıralaması: $1 < \log n < n < n\log n < n^2 < n^3 < 2^n < n!$.
  - En kötü durum (worst case), en iyi durum (best case) ve ortalama durum (average case) analizleri (ekrandan, 02:35:00).
  - Büyük-O tanımı: $x > k$ için $|f(x)| \le C\,|g(x)|$ sağlayan $C$ ve $k$ sabitleri varsa $f(x) = O(g(x))$ (ekrandan, 02:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Aramada değer değil konum döndürülür
  - Konum bilinirse o kaydın bütün alanlarına (örneğin bir öğrenci kaydının numarası, adı, soyadı) ulaşılabilir.
- Kabarcık sıralamada bayrak değişkeni
  - Bir turda hiç yer değiştirme olmazsa dizi sıralıdır; bütün $n-1$ turu çalıştırmaya gerek kalmaz. Hoca bunu yapısal programlama için iyi bir alıştırma olarak önerdi.
- Infix değerlendirmenin zorluğu
  - İki yığın ve operatör öncelikleri işi karmaşıklaştırır; prefix ya da postfix ifadede tek yığın yeter ve öncelik kontrolüne gerek kalmaz.
  - Derleyiciler matematiksel ifadeleri arka planda postfix ya da prefix biçime dönüştürüp öyle hesaplar.
- Operandların sırası
  - Prefix değerlendirmede ilk çekilen operand sola yazılır ($s_1 \text{ op } s_2$), postfix değerlendirmede ilk çekilen sağa yazılır ($s_2 \text{ op } s_1$). Bölme ve çıkarmada bu sıra sonucu değiştirir.
- Elle kısa yol ile yığınla çözüm farklıdır
  - Soru "yığın kullanarak" diyorsa yığının adım adım durumu gösterilmelidir; kısa yol ancak izin verildiğinde kullanılır.
- En kötü durum analizi
  - Genellikle en kötü duruma bakılır; büyük $n$ için belirleyici olan budur.
- Veri yapıları ve algoritmalar
  - Hoca bu konuların ileriki derslerin temeli olduğunu, yığın ve kuyruk kodlarını C ile yazmanın faydalı olacağını söyledi.

## Kısa Tekrar Notları

- Algoritma: sonlu, kesin, sıralı adımlar. Özellikler: giriş, çıkış, doğruluk, sonluluk, etkililik, genellik.
- Doğrusal arama en kötü $n$ karşılaştırma, en iyi 1 karşılaştırma. İkili arama sıralı dizi ister.
- Kabarcık sıralama: komşuları karşılaştır, her turda en büyük sona gider; en fazla $n-1$ tur.
- Araya eklemeli sıralama: soldaki sıralı kısma ekle, kaydırma gerekir.
- Öklid: $\gcd(m,n)=\gcd(n, m \bmod n)$, $\gcd(m,0)=m$.
- Yığın LIFO (`push`, `pop`), kuyruk FIFO (`enqueue`, `dequeue`).
- Infix $A+B$, prefix $+AB$, postfix $AB+$.
- Prefix değerlendirme: ters oku, $s_1 \text{ op } s_2$. Postfix değerlendirme: düz oku, $s_2 \text{ op } s_1$.
- Infix → postfix: operand sonuca, operatör yığına; düşük öncelikli operatör gelince yığındaki yüksek öncelikliler sonuca aktarılır; `)` gelince `(` görülene kadar boşaltılır.
- Infix → prefix: ters çevir, parantezleri değiştir, postfix algoritması, sonucu ters çevir.
- Teorik analiz: temel işlemin tekrar sayısı $T(n)$; baskın terim karmaşıklığı belirler.
- $n \ge 5$ için $n^2 < 2^n$; üstel algoritma büyük $n$ için polinom algoritmadan kötüdür.

## Detaylı Açıklamalar

- **En büyük elemanı bulma algoritması.** Dizinin ilk elemanı geçici maksimum seçilir. Ardından ikinci elemandan başlanarak her eleman geçici maksimumla karşılaştırılır; daha büyükse geçici maksimum bu elemana eşitlenir. Bu işlem dizinin son elemanına kadar tekrarlanır. Burada kullanılan işlemler (atama, karşılaştırma, koşul, tekrar) sonlu bir işlem kümesinin elemanlarıdır ve her biri bilgisayarda doğrudan karşılığı olan kesin işlemlerdir (örneğin karşılaştırma için Assembly'de `CMP`, C'de `if`). Algoritma $2$'den $n$'e kadar çalıştığı için genel, sonlu ve test edilebilirdir; bu yüzden altı özelliği de sağlar.

- **Doğrusal ve ikili arama.** Doğrusal aramanın sözde kodu (ekrandan, 00:25:00):

  ```text
  procedure linear search(x: integer, a1, a2, ..., an: distinct integers)
  i := 1
  while (i <= n and x != ai)
      i := i + 1
  if i <= n then location := i
  else location := 0
  return location
  ```

  En iyi durumda eleman ilk denemede bulunur; en kötü durumda $n$ karşılaştırma gerekir. İkili aramada dizi sıralı olduğu için orta elemanla karşılaştırma yapılır ve her adımda dizinin yarısı aramanın dışında kalır. Hocanın yorumuyla slayttaki sürümde $x > a_m$ ise $i = m+1$, değilse $j = m$ yapılır; döngü $i < j$ olduğu sürece sürer, sonunda $a_i = x$ ise konum $i$ döner, değilse 0.

- **Kabarcık sıralama örneği.** Dizi $4, 2, 7, 8, 3, 1$ ile hoca ilk iki turu tahtada yaptı (python ile doğrulandı):
  - 1. tur: $4,2$ yer değiştirir → $2,4,7,8,3,1$; $4,7$ ve $7,8$ sıralı; $8,3$ yer değiştirir → $2,4,7,3,8,1$; $8,1$ yer değiştirir → $2,4,7,3,1,8$. En büyük eleman (8) sona geldi.
  - 2. tur: $7,3$ yer değiştirir → $2,4,3,7,1,8$; $7,1$ yer değiştirir → $2,4,3,1,7,8$. Son iki eleman yerine oturdu.
  - Aynı biçimde devam edilince 3. turda $2,3,1,4,7,8$, 4. turda $2,1,3,4,7,8$, 5. turda $1,2,3,4,7,8$ elde edilir (ara adımlar eklendi).
  - Slayttaki sözde kod (ekrandan, 00:35:00): `for i := 1 to n-1`, içinde `for j := 1 to n-i`, `if a_j > a_{j+1} then interchange a_j and a_{j+1}`.

- **Araya eklemeli sıralama örneği.** Slayttaki dizi $3, 2, 4, 1, 5$ (ekrandan, 00:40:00): A) ilk iki eleman yer değiştirir → $2,3,4,1,5$; B) üçüncü eleman yerinde kalır → $2,3,4,1,5$; C) dördüncü eleman (1) başa yerleştirilir → $1,2,3,4,5$; D) beşinci eleman yerinde kalır → $1,2,3,4,5$. Hoca 1'in başa geçmesi için 2, 3 ve 4'ün birer konum sağa kaydırılması gerektiğini, bu kaydırmanın algoritmayı biraz verimsiz yaptığını vurguladı.

- **Öklid algoritması.** Sözde kod (ekrandan, 00:45:00):

  ```text
  while n != 0 do
      r <- m mod n
      m <- n
      n <- r
  return m
  ```

  $\gcd(60,24)$: $60 \bmod 24 = 12$ → $(24,12)$; $24 \bmod 12 = 0$ → $(12,0)$; sonuç 12. $\gcd(18,12)$: $(12,6)$ → $(6,0)$; sonuç 6. Ardışık tamsayı kontrolü yönteminde ise $t = \min(m,n)$'den başlanır, $t$ hem $m$'yi hem $n$'yi bölene kadar birer azaltılır; $18$ ve $12$ için $t = 12, 11, \dots, 6$ denenir ve 6 bulunur. Bu yol daha uzundur.
  - Ders sonrası not: Hoca $m=7$, $n=3$ örneğinde ilk kalanı 4 olarak söyledi; doğrusu $7 \bmod 3 = 1$'dir. Doğru izleme $(7,3) \to (3,1) \to (1,0)$ olur ve sonuç 1'dir (python ile doğrulandı). Hocanın vardığı sonuç (aralarında asal sayıların EBOB'u 1) doğrudur.

- **Yığının fonksiyon çağrılarında kullanımı.** `main` içinde 100. satırda `f` çağrılsın, `f` içinde 200. satırda `g` çağrılsın, `g` de 300. satırda kendini çağırsın. Dönüş adresi tek bir değişkende tutulursa yeni çağrı eski adresin üzerine yazar ve kaybolur. Yığında ise her çağrıda dönüş adresi tepeye eklenir; çağrılar bittikçe tepeden çekilir: önce 300 (g), sonra 200 (f), sonra 100 (main). Böylece program kaldığı yerden doğru biçimde devam eder.

- **Kuyruk örneği.** `enqueue 3`, `enqueue 4`, `enqueue 5`, `dequeue` → 3 çıkar; `enqueue 8`; iki kez `dequeue` → 4 ve 5 çıkar; kuyrukta yalnız 8 kalır.

- **Infix değerlendirme örneği** (ekrandan, 01:35:00). İfade $2 * (5 * (3+6)) / 15 - 2$:
  - 2 operand yığınına, `*` ve `(` operatör yığınına, 5 operand yığınına, `*` ve `(` operatör yığınına, 3 operand yığınına, `+` operatör yığınına, 6 operand yığınına atılır.
  - İlk `)`: 6 ve 3 çekilir, `+` çekilir, $3+6=9$ operand yığınına; `(` çekilir.
  - İkinci `)`: 9 ve 5 çekilir, `*` çekilir, $5 \cdot 9 = 45$; `(` çekilir.
  - `/` gelir (önceliği `*` ile eşit), yığına atılır; 15 operand yığınına.
  - `-` gelir: `/` daha yüksek öncelikli olduğu için 15 ve 45 çekilir, $45/15 = 3$; sonra `*` için 3 ve 2 çekilir, $2 \cdot 3 = 6$; `-` yığına atılır.
  - 2 operand yığınına; ifade bitince 2 ve 6 çekilir, $6-2=4$. Sonuç 4 (python ile doğrulandı).

- **Prefix değerlendirme örneği** (ekrandan, 01:45:00). İfade `- / * 20 * 50 + 3 6 300 2`. Elle kısa yol: sondan başa doğru ilk operatöre kadar gidilir; `+ 3 6` → 9; `* 50 9` → 450; `* 20 450` → 9000; `/ 9000 300` → 30; `- 30 2` → 28. Yığınla çözümde ifade ters çevrilir (`2 003 6 3 + 05 * 02 * / -`), her sayı da ters okunduğu için yeniden çevrilir (`003` → 300). Operatör gelince $s_1$ ve $s_2$ çekilir, $s_1 \text{ op } s_2$ yığına konur. Yığının son hali $[28]$ olur.

- **Postfix değerlendirme örneği** (ekrandan, 01:50:00). İfade `2 5 3 6 + * * 5 / 2 -`. 2, 5, 3, 6 yığına; `+`: $3+6=9$; `*`: $5 \cdot 9 = 45$; `*`: $2 \cdot 45 = 90$; 5 yığına; `/`: $90/5 = 18$; 2 yığına; `-`: $18 - 2 = 16$. Sonuç 16.

- **Infix'ten postfix'e dönüşüm örneği** (ekrandan, 01:55:00). Öncelik sırası: `^` en yüksek, sonra `*` `/`, sonra `+` `-`; parantez öncelikleri geçersiz kılar. $A+B*(C\hat{\ }D-E)$ için: A sonuca, `+` yığına, B sonuca, `*` (`+`'dan yüksek) yığına, `(` yığına, C sonuca, `^` yığına, D sonuca; `-` gelince `^` sonuca aktarılır, `-` yığına; E sonuca; `)` gelince `-` sonuca, `(` atılır; ifade bitince `*` ve `+` sırayla sonuca aktarılır. Sonuç `ABCD^E-*+`.

- **Postfix'ten infix'e dönüşüm örneği.** `ABC/-AK/L-*` soldan okunur: $B/C$ → $(A-(B/C))$; $A/K$ → $((A/K)-L)$; son `*` ile $((A-(B/C))*((A/K)-L))$. Prefix'ten infix'e dönüşümde ifade sağdan sola okunur ve $s_1 \text{ op } s_2$ yazılır; `*-A/BC-/AKL` aynı infix ifadeyi verir. Prefix'ten postfix'e dönüşümde sağdan sola okunur, $s_1\,s_2\,\text{op}$ yazılır ve `ABC/-AK/L-*` bulunur (python ile doğrulandı).

- **Seçmeli sıralamanın ayrıntılı analizi** (ekrandan, 02:30:00). Slayttaki tabloda kodun her satırı için işlem ve tekrar sayıları:

  | Satır | İşlem | Tekrar | Toplam |
  |---|---|---|---|
  | I (dış `for`) | 1, 1, 1 | 1, $n$, $n$ | $2n+1$ |
  | II (`min=i`) | 1 | $n$ | $n$ |
  | III (iç `for`) | 1, 1, 1 | $n$, $n(n+1)/2$, $n(n+1)/2$ | $n + 2n(n+1)/2$ |
  | IV (`if`) | 1 | $n(n+1)/2$ | $n(n+1)/2$ |
  | V (`min=j`) | 1 | $n(n+1)/2$ | $n(n+1)/2$ |
  | VI (yer değiştirme) | 1, 1, 1 | 1, 1, 1 | 3 |
  | VII (`return`) | 1 | 1 | 1 |

  Toplam $4n(n+1)/2 + 4n + 5 = 2n^2 + 6n + 5$.
  - Ders sonrası not: Hoca VI. satırdaki üç atamanın dış döngü içinde olduğu için 1'er değil $n$'er kez çalıştığını belirtip slaytı düzeltti; bu durumda VI. satırın toplamı $3n$ olur ve toplam büyük olasılıkla $2n^2 + 9n + 2$ çıkar (python ile hesaplandı). Her iki durumda da baskın terim $2n^2$'dir.

- **$2^n$ ile $n^2$ karşılaştırması.** $n=2$ ve $n=4$ için eşit ($4=4$, $16=16$), $n=3$ için $2^3=8 < 9$, $n=5$ için $32 > 25$. Dolayısıyla $n \ge 5$ için $n^2$ zamanlı algoritma daha iyidir; büyük $n$ için üstel algoritma polinom algoritmadan her zaman kötüdür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
