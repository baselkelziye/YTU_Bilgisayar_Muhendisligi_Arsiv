# Ders 31 Genişletilmiş Notu: Arama Algoritmaları: Doğrusal Arama, İkili Arama ve Karmaşıklık

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Arama algoritmalarına giriş
- 2. Sırasız dizide doğrusal arama
- 3. Sıralı dizide doğrusal arama
- 4. İkili arama (binary search)
- 5. Zaman karmaşıklığı
- 6. Özel durumlar: matris, tekrarlı elemanlar, sıralama maliyeti
- 7. Doğrudan adresleme ve hash tablosu
- 8. Antrenman sorusu: ikili tümleyen matrisini onluğa çevirme
- 9. Jump search
- Örnek Sorular

## 1. Arama algoritmalarına giriş

Dersin konusu arama algoritmalarıdır (ekranda başlık: "Search Algorithms", ekrandan, 00:15:00). Arama denince bir veri grubu içinde belirli bir bilgiyi aramak akla gelir. Genelde tekrar etmeyen (unique) veriler üzerinde arama yapılır. Hocanın örnekleri: bir okul numarasını başka bir öğrenci kullanamaz, bir T.C. kimlik numarası tek bir kişiye aittir, kütüphanede her kitabın tek bir kodu vardır, bankada her müşterinin bir hesap numarası vardır. İlgili öğrencinin, kitabın ya da müşterinin bilgisine erişmek için binlerce, milyonlarca kayıt arasında bu anahtar aranır.

Bilgiler iki biçimde saklanabilir: sıralı (sorted) ya da sırasız (unsorted). Derste veriler dizi olarak ele alındı; hoca aramanın yalnız dizilerde değil, matrislerde ve başka veri yapılarında da yapılabildiğini, bunların ileride görüleceğini söyledi.

- Sırasız bir dizide arama için doğrusal arama (linear search) kullanılır.
- Sıralı bir dizide doğrusal arama biraz değiştirilerek kullanılabilir.
- Verinin sıralı olması daha verimli algoritmalar tasarlamaya imkan verir. Literatürde bunlardan bazıları: binary search, jump search, interpolation search, exponential search.

Arama probleminin iki sonucu vardır: aranan eleman dizide varsa yeri söylenir, yoksa bilgisayar "bu kayıt yoktur" bilgisini vermelidir.

## 2. Sırasız dizide doğrusal arama

### 2.1 Problem ve en kötü durum

Örnek dizi `5, 1, 2, 3, 6, 4`, eleman sayısı $N = 6$ (ekrandan, 00:25:00). Aranan eleman (örneğin 5) varsa yeri, yoksa olmadığı söylenecek.

**Soru:** Sırasız bir dizide en kötü durumda kaç arama yapılır? **Cevap:** Dizideki eleman sayısı kadar, yani $N$ kez.

**Soru:** Aranan eleman dizide yoksa (örneğin 8 aranıyorsa) kaç kontrol yapılır? **Cevap:** Bir öğrenci $N$ dedi; hoca bunun eksik olduğunu söyledi. Altı elemana tek tek bakıldıktan sonra indis bir kez daha artırılır ve 7 olur; bu noktada dizinin sonuna gelinip gelinmediği kontrol edilir. Bu son kontrol yüzünden başarısız aramada $N + 1$ kontrol yapılır.

### 2.2 Hangi döngü?

Okuma işlemi hızlı yazmak için tek kutuda yapıldı: `N, A[N], X` (ekrandan, 00:20:00). Bütün dizi gezilebileceği için bir döngü gerekir.

**Soru:** Bu döngü `for` mu olmalı `while` mı? **Cevap:** Bir öğrenci $N$ kez gidileceği için `for` önerdi. Başka bir öğrenci `while` kullanıp eleman bulununca çıkmayı, sonra bir `if` ile indisin $N$'den küçük olup olmadığına bakmayı önerdi. Hoca `while` kullanılması gerektiğini anlattı: elemanın nerede bulunacağı bilinmez, birinci adımda da $N$'inci adımda da bulunabilir. Eleman bulunduktan sonra geriye kalan (örneğin bir milyon) kayda boşu boşuna bakılmamalıdır. Bu yüzden burada `for` kullanmak yanlıştır.

> **Hocanın vurgusu:** Arama işinde eleman bulunduğu anda durulması gerektiği için kullanılması gereken döngü `while` döngüsüdür.

### 2.3 Akış diyagramı

Döngüde temelde iki kontrol vardır: dizinin sonuna ulaşılıp ulaşılmadığı ve aranan elemanın bulunup bulunmadığı. Döngünün içinde yapılacak tek iş, bir öğrencinin söylediği gibi indisi artırmaktır; kontroller zaten `while` koşulunda yapılır. Tahtadaki diyagram (ekrandan, 00:25:00):

```text
START
  |
[ N, A[N], X ]            (okuma)
  |
[ I = 1 ]
  |
< I <= N AND A[I] ≠ X > --doğru--> [ I = I + 1 ] --> (koşula geri dön)
  | yanlış
< I <= N >
  doğru  --> I yazdır
  yanlış --> 'Not found' yazdır
  |
STOP
```

Döngüden çıkıldığında hangi koşul yüzünden çıkıldığı bilinmez: eleman bulunduğu için mi, dizinin sonuna gelindiği için mi? Bunu ayırt etmek için çıkışta `I <= N` sorulur. Doğruysa eleman bulunmuştur ve `I` yazdırılır; yanlışsa "Not found" yazdırılır. İki kol STOP'ta birleşir.

> **Hocanın vurgusu:** Bu çizimlerde en büyük hatalardan biri kolları yanlış yere bağlamaktır (örneğin döngüden çıkan bir kolu başka bir yere ya da döngünün içine bağlamak). Akış düzgün çizilmelidir.

### 2.4 İz sürme

Tahtada `I`, `A[I]`, `X`, `N` sütunlarıyla bir tablo kuruldu (ekrandan, 00:25:00).

`X = 3` için:

| I | A[I] | X | I <= N ve A[I] ≠ X |
|---|------|---|--------------------|
| 1 | 5 | 3 | doğru, I = 2 |
| 2 | 1 | 3 | doğru, I = 3 |
| 3 | 2 | 3 | doğru, I = 4 |
| 4 | 3 | 3 | yanlış (3 = 3), çık |

Çıkışta $4 \le 6$ doğru olduğu için 4 yazdırılır: eleman dördüncü gözdedir.

`X = 4` için `5, 1, 2, 3, 6` elemanlarının hiçbiri 4'e eşit olmadığı için `I` 6'ya kadar artar; `A[6] = 4` eşitliği koşulu bozar, çıkışta $6 \le 6$ doğrudur ve 6 yazdırılır.

`X = 7` için `I = 6`'da da eşitlik yoktur, `I` 7 olur. $7 \le 6$ yanlış olduğu için döngüden çıkılır, çıkıştaki `I <= N` de yanlıştır ve "Not found" yazdırılır.

> **Ek bilgi (derste anlatılmadı):** Bu diyagram C'ye `while (i <= n && a[i] != x)` biçiminde aktarılırsa `&&` işlecinin kısa devre değerlendirmesi önemlidir: `i <= n` yanlış olduğunda `a[i]` hiç okunmaz. Koşulların sırası ters yazılırsa son turda dizinin dışındaki bir göz okunur.

## 3. Sıralı dizide doğrusal arama

### 3.1 Problem

Ekrandaki soru (ekrandan, 00:30:00): "Verilen bir elemanın varsa yerini yoksa bulunmadığı bilgisini ekrana yazdıran algoritmanın akış diyagramını çiziniz. (Sıralı bir dizide)". Örnek dizi: `1, 3, 5, 8, 12, 25, 32` (indisler 1-7).

**Soru:** Sıralı dizide arama yapmanın farkı nedir, algoritmada neyi değiştirmek gerekir? Örneğin 4 aranıyor. **Cevap:** Sohbetten gelen cevaba göre, 4'ten büyük bir değere gelindiğinde aramaya devam etmeye gerek yoktur. 4'ün olup olmadığını anlamak için dizinin sonuna kadar gitmek gerekmez; kendisinden büyük bir değere gelindiğinde o noktadan sonra bulunma ihtimali ortadan kalkar. Yine `while` kullanılır, ama kontroller biraz değişir.

Hoca bu tasarım için öğrencilere yaklaşık 5 dakika süre verdi. Bir öğrenci sözlü olarak döngü koşuluna `i <= n` ile aranan değerin `a[i]`'den büyük olduğu durumu yazdığını, eşitlikte durmak gerektiğini anlattı.

### 3.2 İlk tasarım

Bu sefer dizi `B`, aranan eleman `Y` olarak adlandırıldı (ekrandan, 00:40:00):

```text
START
  |
[ N, B[N], Y ]
  |
[ I = 1 ]
  |
< I <= N AND Y > B[I] > --doğru--> [ I = I + 1 ] --> (koşula geri dön)
  | yanlış
< Y = B[I] >
  doğru  --> I yazdır
  yanlış --> 'Not found' yazdır
  |
STOP
```

Hoca karar kutusuna önce `A[I] = Y` yazdı, sonra dizinin adı `B` olduğu için `B[I]` olarak düzeltti. Bir öğrenci de çıkışta eşitlik sorulup doğruysa `I`'nın, yanlışsa "Not found"'un yazılacağını söyledi.

İz sürme:

- 1 aranırsa: ilk turda $1 > 1$ yanlış, çıkılır; `B[1] = 1` eşit, 1 yazdırılır. Doğru.
- 32 aranırsa: `I` 7'ye kadar artar; $7 \le 7$ ama $32 > 32$ yanlış, çıkılır; `B[7] = 32` eşit, 7 yazdırılır. Doğru.
- 35 aranırsa: `I = 7`'de $35 > 32$ doğru olduğu için `I` 8 olur, $8 \le 7$ yanlış, çıkılır. Çıkışta `B[8]`'e bakılır.

**Soru:** 35 için `B[8]`'e bakınca ne olur? **Cevap:** Bilinmez; dizi 7 elemanlıdır ve oraya erişilip erişilemeyeceğinin garantisi yoktur. Bu tasarım, aranan değerin dizinin bütün elemanlarından büyük olduğu durumda çalışmaz. 9 ya da 4 gibi aradaki değerlerde çalışır.

### 3.3 Düzeltme 1: çıkışa ek koşul

**Soru:** Bunu düzeltmek için ne yapılabilir? **Cevap:** Bir öğrenci sondaki karara bir koşul daha eklemeyi önerdi: `I <= N`. Çıkıştaki karar `I <= N AND Y = B[I]` olur. 35 için `I = 8` olduğundan koşul sağlanmaz ve "Not found" yazılır. Aradaki bir değer için (hoca 24 örneğini verdi) $I \le N$ doğrudur ama `B[I]` aranan değere eşit değildir, yine "Not found" yazılır.

> **Ders sonrası not:** Bu çözümün C karşılığında da `&&` işlecinin kısa devre özelliği gerekir: önce `i <= n` yazılmalıdır ki `i = n + 1` iken `b[i]` okunmasın.

### 3.4 Düzeltme 2: ek koşul olmadan

**Soru:** Bu ekstra koşulu koymadan çözülebilir mi? **Cevap:** Hoca döngü koşulunu küçük bir değişiklikle `I ≠ N AND Y > B[I]` yaptı, çıkışta yalnız `Y = B[I]` sordu (ekrandan, 01:00:00).

```text
START
  |
[ N, B[N], Y ]
  |
[ I = 1 ]
  |
< I ≠ N AND Y > B[I] > --doğru--> [ I = I + 1 ] --> (koşula geri dön)
  | yanlış
< Y = B[I] >
  doğru  --> I yazdır
  yanlış --> 'Not found' yazdır
  |
STOP
```

İz sürme:

- 1 aranırsa: $1 \ne 7$ ama $1 > 1$ yanlış, çıkılır; `B[1] = 1`, bulunur.
- 4 aranırsa: $4 > 1$, $4 > 3$ doğru; `I = 3`'te $4 > 5$ yanlış, çıkılır; `B[3] = 5` 4'e eşit değil, "Not found". Doğru.
- 32 aranırsa: `I` 7 olunca $7 \ne 7$ yanlış, çıkılır; `B[7] = 32` eşit, 7 yazdırılır. Doğru.
- 35 aranırsa: yine `I = 7`'de döngü biter; `B[7] = 32` 35'e eşit değil, "Not found". Bu durumda da doğru çalışır.

`I <= N` yerine `I ≠ N` yazılınca son eleman döngüde hiç karşılaştırılmaz, her zaman çıkıştaki kararda kontrol edilir. Böylece dizinin dışına çıkma olasılığı kalmaz. Çıkıştaki karar eşitlikte `I`'yı, eşitlik yoksa "Not found"'u gösterir.

### 3.5 Bir başka kurgu

Hoca bazı öğrencilerin eşitlik kontrolünü döngü içine aldığını da gösterdi: döngü içinde bir karar kutusu ve "found" gibi bir bayrak değişkeni kullanılarak eleman bulununca döngüden çıkılabilir. Bu da çalışır, ama her turda bir kontrol daha yapılmış olur. Kontrolü doğrudan `while` koşulunda yapmak daha akıllıcadır.

<!-- BELİRSİZ: Bu alternatif diyagramın kutuları altyazıda parça parça geçiyor ve o anın karesi yok; kutuların tam sırası aktarılamadı. -->

## 4. İkili arama (binary search)

### 4.1 Sayı tahmin oyunu

Şimdiye kadar görülen algoritma doğrusal arama, ya da başka bir adıyla sıralı (sequential) aramadır. İkili aramayı anlatmak için hoca bir oyun önerdi: 1 ile 100 arasında bir sayı tutulmuş olsun, tahmin edene "küçük" ya da "büyük" ipucu verilsin. Örneğin tutulan sayı 22 iken 25 denirse "küçük", 18 denirse "büyük" cevabı gelir.

**Soru:** Böyle bir oyunda tahmine nereden başlarsınız? **Cevap:** Öğrencilerin hepsi 50 dedi. 50'den sonra "büyük" denirse 75 söylenir. Yani her adımda başlangıç ve son noktasının ortası söylenerek arama olabildiğince hızlı bitirilir. İkili arama aynı stratejiyi uygular.

### 4.2 Fikir

Örnek dizi: `1, 5, 8, 12, 25, 38, 42, 56` (ekrandan, 01:10:00). Aramaya dizinin orta noktasından başlanır. Aranan eleman 42 ise ve ortada 25'e (tahtadaki oklara göre) bakılmışsa, 42 > 25 olduğu için aranan eleman sağ yarıdadır; sol yarı artık ihtimal dışıdır. Sonra kalan aralığın ortasındaki 38'e bakılır ve aralık iyice küçülür. Sonunda yaklaşık $\log_2 N$ adımda sonuca ulaşılır. $N = 100$ için bu 7 adımdır; doğrusal aramada en kötü durumda 100 kontrol gerekirdi.

> **Hocanın vurgusu:** İkili arama çok güzel bir stratejidir ama tek şartı vardır: dizinin elemanları sıralı olmalıdır.

### 4.3 Akış diyagramının tasarlanması

Hoca öğrencilere yaklaşık 6 dakika verdi ve ipucu olarak başlangıç kutusunu yazdı: `bas = 1`, `son = N`, `mid = (bas + son) / 2` ve tek bir `while` döngüsü olacağını söyledi. Sonra değişken adlarını Türkçe yapmak için `mid` yerine `orta` yazdı ve bölmeyi `DIV 2` (tam sayı bölmesi) olarak düzeltti (ekrandan, 01:25:00).

Bir öğrenci, döngü içinde bir `if` olacağını; ortadaki eleman aranan sayıdan küçükse `bas = orta + 1` yapılacağını söyledi. Hoca bunu şöyle toparladı: döngünün her turunda ya baş ya son değişir. Başlangıçta baş 1, son $N$'dir. Sağ tarafa gidilirse başlangıç `orta + 1` olur, son değişmez. Sol tarafa gidilirse son `orta - 1` olur, başlangıç aynı kalır. Baş ya da son değiştiği için orta da her seferinde değişir.

Döngü koşulunun iki parçası vardır. Baş ile son soldan ve sağdan yaklaşırken her zaman `bas <= son` olur; bu düzen son başı geçtiğinde bozulur. İkinci parça aranan elemanın henüz bulunmamasıdır: `X ≠ A[orta]`.

```text
START
  |
[ N, A[N], X ]
  |
[ bas = 1 ; son = N ; orta = (bas + son) DIV 2 ]
  |
< bas <= son AND X ≠ A[orta] > --doğru--> < X > A[orta] >
  |                                          doğru  --> [ bas = orta + 1 ]
  |                                          yanlış --> [ son = orta - 1 ]
  |                                       [ orta = (bas + son) DIV 2 ] --> (koşula geri dön)
  | yanlış
< bas <= son >
  doğru  --> orta yazdır
  yanlış --> 'Not found' yazdır
  |
STOP
```

### 4.4 Diyagramdaki hatalar

Hoca diyagramı ilk çizdiğinde karşılaştırmaları `A[I]` ile yazdı (ekrandan, 01:20:00) ve diyagramda çok bariz bir hata olduğunu söyleyerek öğrencilere sordu.

**Soru:** `orta = (bas + son) DIV 2` yalnız yanlış kolunda mı yapılmalı? **Cevap:** Hayır. Baş ya da sondan biri değiştiğinde orta da değişir; bu yüzden iki kolda da güncellenir (iki kol birleştikten sonra tek kutuda).

**Soru:** Son, $N$ mi olmalı $N - 1$ mi? **Cevap:** İndis 1'den başladığı için son eleman $N$'dir. 0'dan başlansaydı $N - 1$ olurdu.

**Soru:** Döngü zaten `bas <= son` koşuluyla çıkıyorsa çıkışta neden bu koşul tekrar soruluyor? **Cevap:** Döngüde iki koşul vardır. Eleman bulunduğu için çıkılmışsa `bas <= son` hala doğrudur, eleman bulunmuştur. `bas <= son` bozulduğu için çıkılmışsa "Not found" denir. Ama belirgin hata bu değildir.

**Soru:** `I`'nın ilk değeri atanmamış mı? **Cevap:** Bu algoritmada `I` diye bir değişken yoktur. Kontrol yanlıştır; `A[I]` değil `A[orta]` olmalıdır, çünkü ortadaki elemana bakılıyor. Bu cevabı bir öğrenci verdi ve hoca iki karşılaştırmayı da `A[orta]` olarak düzeltti.

### 4.5 İz sürme

Tahtada `bas`, `orta`, `son`, `N`, `X`, `A[orta]` sütunlarıyla tablo kuruldu (ekrandan, 01:25:00). Dizi: `1, 5, 8, 12, 25, 38, 42, 56` (indisler 1-8), $N = 8$.

`X = 42` için:

| bas | orta | son | A[orta] | Karar |
|-----|------|-----|---------|-------|
| 1 | 4 | 8 | 12 | 42 ≠ 12, 42 > 12 → bas = 5 |
| 5 | 6 | 8 | 38 | 42 ≠ 38, 42 > 38 → bas = 7 |
| 7 | 7 | 8 | 42 | 42 = 42 → döngüden çık |

Ara adımlar: $(5 + 8)\ \mathrm{DIV}\ 2 = 13\ \mathrm{DIV}\ 2 = 6$, $(7 + 8)\ \mathrm{DIV}\ 2 = 7$. Çıkışta $7 \le 8$ doğru, `orta = 7` yazdırılır; 42 bulunmuştur.

`X = 43` için ilk iki tur aynıdır. Üçüncü turda `A[7] = 42`, 43 > 42 olduğu için `bas = 8`, `orta = (8 + 8) DIV 2 = 8` olur. `A[8] = 56` 43'e eşit değildir ve $8 \le 8$ doğrudur, döngüye yeniden girilir. 43 > 56 yanlış olduğu için `son = orta - 1 = 7` olur; orta yine $(8 + 7)\ \mathrm{DIV}\ 2 = 7$ hesaplanır. Koşulda $8 \le 7$ yanlış olduğu için döngüden çıkılır, çıkıştaki `bas <= son` da yanlıştır ve "Not found" yazdırılır.

> **Ders sonrası not:** Hoca bu kısmı anlatırken bir an "orta 8 olacaktı" dedi; `son = 7` olduktan sonra `(8 + 7) DIV 2 = 7` olur. Sonuç değişmez, çünkü döngü zaten `bas <= son` bozulduğu için biter.

> **Ek bilgi (derste anlatılmadı):** Tahtadaki diyagram C'ye çevrilip 1'den başlayan indisler için (0. göz boş bırakılarak) gcc ile derlendi ve aynı dizide çalıştırıldı: 42 → 7, 1 → 1, 56 → 8; 43, 0 ve 60 için bulunamadı sonucu verdi. Koşul `bas <= son && x != a[orta]` sırasıyla yazıldığında aralık boşaldığında `a[orta]` okunmaz.

## 5. Zaman karmaşıklığı

En kötü durum (worst case) için iki algoritma karşılaştırıldı (ekrandan, 01:30:00):

| | Doğrusal arama | İkili arama |
|---|---|---|
| Bulunursa (found) | $O(N)$ | $O(\log_2 N)$ |
| Bulunamazsa (not found) | $N + 1$ | $\log_2 N + 1$ |
| $N = 100$ | 100 | yaklaşık 7 |
| $N = 1000$ | 1000 | yaklaşık 10 |

Bir yerde 1000 kontrol yapılırken öbür tarafta yalnız 10 kontrolle elemanın var olup olmadığı bulunur. ($\lceil \log_2 100 \rceil = 7$, $\log_2 1000 \approx 9{,}97$.)

Hoca karmaşıklık konusuna dersin esas konusu olmadığı için çok girmedi, ama kabaca şunu anlattı: karmaşıklık, bir algoritmanın en kötü durumda kaç adımda sonlanacağını söyler. İç içe iki döngü varsa genelde $N^2$ ortaya çıkar. Tek döngüler, döngünün yapısına göre $N$ ya da $\log_2 N$ olabilir. $\log_2 N$ karmaşıklık elde edilirse oldukça verimli bir algoritma tasarlanmış demektir; $N$ de tatmin edicidir. $N^2$, $N^3$ gibi karmaşıklıklardan uzak durulmak istenir: $N^2$, 1000 eleman için $1000 \times 1000$, 10000 eleman için $10000 \times 10000$ işlem demektir.

## 6. Özel durumlar: matris, tekrarlı elemanlar, sıralama maliyeti

### 6.1 Sırasız matriste arama

Tahtadaki örnek matris `1, 5, 7, 8, 9 / 3, 2, 4, 6, 10 / 12, 11, ...` gibi sırasız değerler içerir (ekrandan, 01:30:00). Sırasız bir matriste bütün matrisi gezmek gerekir: birinci satırdan başlayıp bütün sütunlar, sonra ikinci satıra geçip kalan sütunlar gezilerek arama yapılır.

### 6.2 Tekrarlı elemanlar

Elemanlar unique değilse, örneğin `3, 1, 3, 4, 2, 5, 5` dizisinde 3'ten ya da 5'ten kaç tane olduğu aranıyorsa, dizinin sonuna kadar gitmek gerekir; burada `while` yerine `for` kullanmak doğru tercihtir (ekrandan, 01:35:00). Dizi sıralıysa, örneğin `1, 2, 3, 3, 4, 5, 5`, 3 arandığında 3'lerden sonraki ilk büyük değere gelindiği noktadan itibaren kalan kısma bakmaya gerek yoktur; bu durumda `while` kullanmak daha akıllıcadır. Amaç, aranan elemanın hangi gözlerde olduğunu söyleyebilmektir.

### 6.3 Sırasız diziye ikili arama

**Soru (sohbetten):** Sırasız dizide doğrusal arama hep $N$ mertebesinde; sırasız diziyi önce sıralarsak ne olur? **Cevap:** İkili arama uygulamak için dizinin sıralı olması gerekir. Sırasız bir diziyi sıralamanın maliyeti, karşılaştırmalı bir sıralama algoritmasıyla en iyi ihtimalle $O(N \log N)$'dir. Önce sıralama $O(N \log N)$, sonra arama $O(\log N)$ olduğu için büyük olan seçilir: sırasız diziye ikili arama uygulamanın toplam karmaşıklığı $O(N \log N)$'e çıkar.

## 7. Doğrudan adresleme ve hash tablosu

**Soru:** Bir öğrenci her elemanı kendi değerine eşit indiste saklamayı önerdi (3 numaralı eleman 3. indiste, 7 numaralı eleman 7. indiste). Bu yer kullanımını artırır ama aramayı çok hızlandırır; ikisi arasındaki en uygun denge nasıl kurulur? **Cevap:** Bu bir hash yapısıdır, buna hashing denir. Öğrencinin önerdiği doğrudan adreslemedir (direct addressing). Daha uygun olanı bir hash fonksiyonu kullanmaktır; bu fonksiyon tek adımda değerin hangi göze denk geldiğini hesaplar ve değeri o göze yerleştirir.

Tahtadaki örnek (ekrandan, 01:35:00): değerler `1, 7, 8, 15, 22`, hash fonksiyonu mod 13.

| Değer | Değer mod 13 | Göz |
|-------|--------------|-----|
| 1 | 1 | 1 |
| 7 | 7 | 7 |
| 8 | 8 | 8 |
| 15 | 2 | 2 |
| 22 | 9 | 9 |

Böylece iki yaklaşım vardır:

- Direct address table: öğrencinin bahsettiği yöntem. Doğrudan erişim için kullanılır ama yer açısından çok verimli değildir.
- Hash table: bazı değerler aynı adresi gösterdiğinde bu değerler belli bir kural çerçevesinde farklı yerlere yazılır; yerler daha verimli kullanılır.

Bu iki yöntem arama çözümlerinde çok sık kullanılır ve ikili aramanın $O(\log_2 N)$ karmaşıklığını $O(1)$ düzeyine, yani tek adımda elemanın yerini bulma noktasına taşıyabilir. Hoca bunların ilerleyen derslerde çok daha ayrıntılı görüleceğini söyledi.

## 8. Antrenman sorusu: ikili tümleyen matrisini onluğa çevirme

Hoca antrenman için bir soru verdi (ekrandan, 01:40:00). 1 ve 0'lardan oluşan, 8 sütunlu ve $N$ satırlı bir matriste her satır, işaretli tam sayı sisteminde (ikili tümleyen) bir sayının ikili karşılığını saklıyor. Her satırdaki sayının onluk sistemdeki karşılığını bir diziye yazdıran algoritmanın akış diyagramı istendi. Tahtadaki matris:

| Satır | Bitler | Onluk |
|-------|--------|-------|
| 1 | 1 0 1 0 1 1 1 1 | (derste hesaplanmadı) |
| 2 | 0 1 1 0 1 0 1 1 | (derste hesaplanmadı) |
| 3 | 0 1 1 1 1 1 1 1 | 127 |
| 4 | 1 0 0 0 1 0 0 0 | −120 |
| 5 | 0 0 0 0 0 0 0 1 | 1 |

**Soru:** 3. satırın değeri kaçtır? **Cevap:** Bir öğrenci önce 128 dedi; hoca işaretli tam sayı sisteminde 8 bitle en büyük sayının 127 olduğunu hatırlattı. Doğru cevap 127'dir.

**Soru:** 4. satırın değeri kaçtır? **Cevap:** En soldaki bit 1 olduğu için sayı negatiftir. İkiye göre tümleyeni alınır: önce bire göre tümleyen `01110111`, sonra 1 eklenir: `01111000`. Bu sayı $64 + 32 + 16 + 8 = 120$ eder; başına eksi konunca −120 olur. Bu değer dizinin 4. gözüne yazılır.

**Soru:** Eksi ve artı sayılar varken nasıl bir taktik izlenir? **Cevap:** Bir öğrenci en soldaki biti (most significant bit) hesaba katmadan değeri bulmayı, en soldaki bit 1 ise sonucu ayarlamayı önerdi. Hoca, işaret biti 1 ise satırın işaretsiz değerini 256'dan çıkarıp sonucu eksi yapmanın daha akıllıca olabileceğini söyledi; öğrenci de 256'dan çıkarmanın doğru olduğunu onayladı. Hoca kabaca bu yaklaşımın akıllıca göründüğünü, algoritma pratiği için güzel bir antrenman sorusu olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** 8 bitlik ikili tümleyende işaret biti 1 olan bir satırın onluk değeri, satırın işaretsiz değeri eksi 256'dır. Örneğin `10001000` işaretsiz 136'dır ve $136 - 256 = -120$. Bu, öğrencinin "MSB'yi ayrı tut, 1 ise −128 ekle" fikriyle de aynı sonucu verir: $8 - 128 = -120$.

## 9. Jump search

Sıralı veride bir başka arama algoritması jump search'tür (ekrandan, 01:45:00). Örnek dizi: `1, 5, 8, 12, 96, 172, 251, 255, 3000, ...`. Temel yaklaşım, belirli adımlarla atlayarak elemanı aramaktır: önce bir noktaya, sonra birkaç göz ilerideki noktaya bakılır. Atlamalar dörder, beşer, onar, yirmişer olabilir.

Örneğin 96 aranıyorsa: 96, 12'den büyük olduğu için bir sonraki atlama taşına gidilir. Bir sonraki atlama taşı 251'dir ve 96 bundan küçüktür. Demek ki 96 bu iki atlama taşı arasındaki aralıktadır; o aralıkta doğrusal arama yapılır.

**Soru:** Atlama boyu ne kadar olmalı? **Cevap:** Bir öğrenci dizinin uzunluğuna göre belirlenmesi gerektiğini söyledi. Hoca $N/2$ seçilirse yapılanın zaten az önceki (ikili aramaya benzer bir bölme) olacağını, $N/4$ de olabileceğini söyledi. Sohbetten bir öğrenci $N^{1/2}$ yazdı: atlama boyu $\sqrt{N}$ olursa elemana en uygun düzeyde ulaşılır. Bu algoritmanın karmaşıklığı da $O(\sqrt{N})$'dir.

**Soru (sohbetten):** Bu algoritma ikili aramadan daha mı iyi? **Cevap:** Hayır, ikili aramadan daha iyi bir karmaşıklığı yoktur. Hoca, büyük olasılıkla doğrusal aramadan daha iyi bir çözüm bulmak için ortaya atılmış bir yöntem olduğunu söyledi: ikili aramaya göre yavaş, doğrusal aramadan hızlıdır. İkili arama ile doğrusal aramayı birleştiren yaklaşımlar da vardır; dersin başında yazılan algoritma adlarına bakılarak bu farklı yaklaşımlar öğrenilebilir.

Bütün bu yöntemler sıralı veriler için geçerlidir. Sırasız veride hangi büyüklükte değerin nerede geleceği bilinmediği için daha uygun bir algoritma kurma şansı yoktur. Arama için en sağlıklı ve en iyi yöntem hash tablosudur; ama hash'in yer karmaşıklığı (space complexity) yüksek olduğu için her zaman kullanılamaz ve bazen ikili arama tercih edilir.

## Örnek Sorular

**1. Sırasız dizide arama** (derste sözlü, 00:17:35 ve ekrandan, 00:25:00)

`5, 1, 2, 3, 6, 4` dizisinde ($N = 6$) aranan bir elemanın varsa yerini, yoksa bulunmadığını yazan akış diyagramını çiziniz. En kötü durumda kaç kontrol yapılır?

> **Çözüm:** Bölüm 2.3'teki diyagram: `I = 1`; `I <= N AND A[I] ≠ X` sürdükçe `I = I + 1`; çıkışta `I <= N` ise `I`, değilse "Not found". Bulunursa en çok $N$, bulunamazsa $N + 1$ kontrol yapılır. `X = 3` → 4, `X = 4` → 6, `X = 7` → "Not found".

**2. Sıralı dizide arama** (ekrandan, 00:30:00)

"Verilen bir elemanın varsa yerini yoksa bulunmadığı bilgisini ekrana yazdıran algoritmanın akış diyagramını çiziniz. (Sıralı bir dizide)" Dizi: `1, 3, 5, 8, 12, 25, 32`.

> **Çözüm:** Bölüm 3.4'teki diyagram: `I = 1`; `I ≠ N AND Y > B[I]` sürdükçe `I = I + 1`; çıkışta `Y = B[I]` ise `I`, değilse "Not found". 1 → 1, 32 → 7, 4 ve 35 → "Not found". `I <= N` ile kurulan ilk tasarım 35 için dizinin dışına (`B[8]`) bakar.

**3. İkili arama** (derste sözlü, 01:08:23 ve ekrandan, 01:10:00)

`bas = 1`, `son = N`, `orta = (bas + son) DIV 2` ipucu ve tek bir `while` döngüsü kullanarak sıralı dizide ikili arama akış diyagramını çiziniz. `1, 5, 8, 12, 25, 38, 42, 56` dizisinde 42 ve 43 için iz sürünüz.

> **Çözüm:** Bölüm 4.3'teki diyagram. 42 için (bas, orta, son): (1, 4, 8) → (5, 6, 8) → (7, 7, 8), sonuç 7. 43 için (8, 8, 8) adımından sonra `son = 7`, `bas > son`, sonuç "Not found".

**4. Diyagramdaki hata** (ekrandan, 01:20:00)

İkili arama diyagramında karşılaştırmalar `X ≠ A[I]` ve `X > A[I]` olarak yazılmış. Belirgin hata nedir?

> **Çözüm:** Algoritmada `I` değişkeni yoktur; karşılaştırmalar ortadaki elemanla yapılmalıdır: `X ≠ A[orta]` ve `X > A[orta]`.

**5. Antrenman sorusu: işaretli sayılar matrisi** (ekrandan, 01:40:00)

8 sütunlu, $N$ satırlı bir 0/1 matrisinde her satır işaretli tam sayı sisteminde bir sayının ikili karşılığını saklıyor. Her satırın onluk karşılığını bir diziye yazdıran algoritmanın akış diyagramını çiziniz. Tahtadaki satırlar: `10101111`, `01101011`, `01111111`, `10001000`, `00000001`.

Derste 3., 4. ve 5. satırlar hesaplandı (127, −120, 1) ve yaklaşım konuşuldu; tam algoritma verilmedi.

> **Çözüm (derste verilmedi):** Her satır için `deger = 0`; soldan sağa her bit için `deger = deger * 2 + bit`; en soldaki bit 1 ise `deger = deger - 256`; `D[i] = deger`. Aşağıdaki C kodu gcc -Wall ile derlendi ve çalıştırıldı; çıktı `-81 107 127 -120 1` oldu.

```c
#include <stdio.h>

#define N 5
#define M 8

int main(void) {
    int b[N][M] = {
        {1, 0, 1, 0, 1, 1, 1, 1},
        {0, 1, 1, 0, 1, 0, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1}
    };
    int d[N];
    int i, j, deger;

    for (i = 0; i < N; i++) {
        deger = 0;
        for (j = 0; j < M; j++)          /* işaretsiz değer: Horner yöntemi */
            deger = deger * 2 + b[i][j];
        if (b[i][0] == 1)                /* işaret biti 1 ise negatif */
            deger = deger - 256;
        d[i] = deger;
    }
    for (i = 0; i < N; i++)
        printf("%d ", d[i]);
    printf("\n");
    return 0;
}
```

**6. Sırasız diziye ikili arama** (derste sözlü, 01:34:22)

Sırasız bir diziye ikili arama uygulamak istenirse toplam karmaşıklık ne olur?

> **Çözüm:** Önce karşılaştırmalı sıralama en iyi $O(N \log N)$, sonra ikili arama $O(\log N)$; büyük olan baskın olduğundan toplam $O(N \log N)$.

**7. Jump search atlama boyu** (derste sözlü, 01:42:25)

Jump search'te atlama boyu neye göre ve ne kadar seçilmelidir?

> **Çözüm:** Dizinin uzunluğuna göre; en uygun atlama boyu $\sqrt{N}$, karmaşıklık $O(\sqrt{N})$.

## Dersin Toparlaması

Bu derste arama problemi önce sırasız, sonra sıralı diziler üzerinde akış diyagramlarıyla ele alındı. Sırasız dizide doğrusal aramanın `while` ile, iki koşullu bir döngü ve çıkışta "neden çıktım" kontrolüyle kurulduğu görüldü. Sıralı dizide aranan değerden büyük bir elemana gelince durulabildiği, ama en büyük elemandan büyük bir değer arandığında dizinin dışına çıkma tehlikesi olduğu ve bunun `I ≠ N` koşuluyla ek kontrol gerektirmeden çözüldüğü gösterildi. İkili arama, sayı tahmin oyunu sezgisiyle anlatıldı; `bas`, `son`, `orta` değişkenleriyle akış diyagramı çizilip iz sürülerek doğrulandı.

Son bölümde doğrusal ($O(N)$) ve ikili ($O(\log_2 N)$) aramanın en kötü durum karmaşıklıkları karşılaştırıldı; tekrarlı elemanlar, sırasız matrisler, sıralamanın $O(N \log N)$ maliyeti, doğrudan adresleme ve hash tablosu ($O(1)$) ile jump search ($O(\sqrt{N})$) kısaca tanıtıldı. Hash yöntemleri ve karmaşıklık analizi ilerideki derslerde ayrıntılı görülecek konular olarak anıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
