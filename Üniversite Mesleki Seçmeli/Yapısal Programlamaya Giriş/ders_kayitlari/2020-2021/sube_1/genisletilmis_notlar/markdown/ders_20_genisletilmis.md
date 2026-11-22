# Ders 20 Genişletilmiş Notu: Özyinelemeli Fonksiyonlar ve Özyineleme Ağacıyla Karmaşıklık Analizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Karmaşıklığın Kod İçinde Ölçülmesi
- 2. Özyinelemeli Fonksiyon Nedir
- 3. Faktöriyel ve Stack Overflow
- 4. Durma Koşulu ve Doğru Tasarım
- 5. Basit Üs Alma
- 6. Ne İş Yapıyor? Üç Özyinelemeli Fonksiyon
- 7. Özyineleme Ağacı ile Karmaşıklık Analizi
- 8. Hızlı Üs Alma
- 9. Diğer Özyineleme Ağaçları
- Örnek Sorular
- Dersin Toparlaması

## 1. Karmaşıklığın Kod İçinde Ölçülmesi

Dersin başında bir algoritmanın karmaşıklığının elle değil, kod içinde otomatik olarak nasıl ölçülebileceği konuşuldu. Karmaşıklık analizi temelde iki açıdan yapılır: hız (çalışma zamanı) ve hafıza (bellek gereksinimi).

### 1.1 Çalışma süresinin ölçülmesi

Fikir şudur: algoritma farklı büyüklükteki girdiler için tekrar tekrar çalıştırılır ve her çalışmanın ne kadar sürdüğü kodun kendisi tarafından ölçülür. Örneğin bir dizi sıralama algoritması düşünelim. Dizinin büyüklüğü $n = 1$'den $K$'ya kadar değişsin (tahtada `n=1:K` ve `alg code` yazıyor, ekrandan, 00:25:00). Döngünün her adımında:

- Algoritma çalışmadan önce bilgisayarın o anki zamanı alınır: $t_1$.
- Algoritma bu $n$ değeri için çalıştırılır.
- Algoritma bitince zaman yeniden alınır: $t_2$.
- $t_2 - t_1$, algoritmanın bu $n$ için aldığı süredir; bir süre dizisine kaydedilir.

Bilgisayarın o anki zamanı, rastgele sayı üreteçleri konusunda görülen `time.h` gibi kütüphanelerle alınabilir. Döngü bittiğinde elde bütün $n$ değerleri için süreler vardır ve bu süreler çizdirilir.

Bellek analizi de aynı mantıkla yapılır: zaman yerine, o anda dizinin ya da algoritmanın kullandığı bellek miktarı alınır. Hocaya göre en kolayı süre ölçümüdür.

### 1.2 Sonucu yıldızlarla çizdirmek

Grafik için C'de OpenGL gibi araçlar kullanılabilir, ama şart değildir. Standart komut satırında, her $n$ için satır satır yıldız bastırarak anlaşılır bir bar grafik oluşturulabilir. Tahtadaki örnekte (ekrandan, 00:25:00):

```text
N
1 *
2 ****
3 *********
4 ****************
```

$n = 1$ için 1, $n = 2$ için 4, $n = 3$ için 9, $n = 4$ için 16 birim süre ölçülmüştür. Bu, algoritmanın karmaşıklığının $n^2$ gibi olduğunu gösterir. Böylece elle bulunan karmaşıklık ile grafiğin gösterdiği büyümenin aynı olduğu gösterilebilir.

**Soru:** Analiz yaparken işlemden önce ve sonra saat tutup farkı mı alacağız, yoksa satır mı sayacağız? **Cevap:** Satır sayılmayacak. Algoritmanın gerçek çalışma süresi kodun içinde, işlemden önce ve sonra alınan zamanların farkıyla ölçülecek.

**Soru:** $n$ değerleri kullanıcıdan mı alınacak? **Cevap:** Hayır. $n$ değerlerini programcı kendisi ayarlar; ama karakteristiği gösterebilecek kadar geniş bir aralık seçilmelidir.

## 2. Özyinelemeli Fonksiyon Nedir

Dersin asıl konusu özyinelemeli (recursive) fonksiyonlardır. "Öz yineleme", özünü yineleyen, yani kendini yineleyen demektir. Özyinelemeli fonksiyon, kendini çağıran fonksiyondur.

Daha önce bir fonksiyonun başka bir fonksiyonu çağırdığı görülmüştü. Burada fonksiyonun kendini çağırmasından söz ediliyor. Bunun iki yolu vardır:

- **Doğrudan özyineleme:** `f` isimli fonksiyon yine `f`'i çağırır.
- **Dolaylı özyineleme:** `f` fonksiyonu `g` fonksiyonunu, `g` fonksiyonu da `f` fonksiyonunu çağırır.

## 3. Faktöriyel ve Stack Overflow

### 3.1 Faktöriyelin özyinelemeli tanımı

En klasik özyinelemeli fonksiyon faktöriyeldir:

$$n! = 1 \cdot 2 \cdot 3 \cdots (n-1) \cdot n$$

Buradaki $1 \cdot 2 \cdots (n-1)$ parçası $(n-1)!$'dir. O halde

$$n! = (n-1)! \cdot n$$

yazılabilir. Bu, faktöriyelin faktöriyelle tanımlanmasıdır; kendini çağırma dediğimiz şey budur. Yani $t = \text{faktöriyel}(n)$ ile $t = n \cdot \text{faktöriyel}(n-1)$ aynı sonucu verir.

### 3.2 İlk (hatalı) akış diyagramı

Fonksiyonun adı `fakto`, girdisi `N`, dışarıya verdiği değer `T` olsun. İlk denemede içeride tek bir işlem kutusu vardır (ekrandan, 00:45:00):

```text
fakto(N)  ->  T
   |
T = N * fakto(N-1)
   |
return
```

Ana algoritmada `Başla`, kullanıcıdan `N`'nin okunması ve bir yerde `S = fakto(5)` çağrısı vardır. `fakto(5)` çağrılınca fonksiyon çalışmaya başlar (kısaltmak için `fakto` yerine `f` yazalım):

- $f(5) = 5 \cdot f(4)$; $f(4)$'ü görünce fonksiyon yine başa döner.
- $f(4) = 4 \cdot f(3)$, $f(3) = 3 \cdot f(2)$, $f(2) = 2 \cdot f(1)$, $f(1) = 1 \cdot f(0)$.
- $f(0) = 0 \cdot f(-1)$, $f(-1) = -1 \cdot f(-2)$, ... ve bu sonsuza kadar sürer.

**Soru (hocanın):** Böyle bir fonksiyon yazarsak ne olur? Bir öğrenci "sonuç 0 gelir" dedi; hoca önce sonucun dönüp dönmediğini sordu. **Cevap:** Sonuç hiç dönmez. Bu sonsuz bir döngüdür; bellek tükenene kadar gider ve stack overflow ile sonuçlanır.

### 3.3 Stack nedir, overflow neden olur

İşletim sistemi programın çalışması için bir bellek ayırır. Bu belleğin içinde **stack** adında bir bölüm vardır ve fonksiyon çağrıları burada yönetilir:

- Bir fonksiyon çağrılmadan önce programın o anki hali (değişkenlerin değerleri, kaçıncı satırda kalındığı, program counter gibi bilgiler) stack'e yüklenir.
- Sonra fonksiyona gidilir ve fonksiyon çalıştırılır.
- Fonksiyon bitince gerekli değerler stack'ten geri çekilir ve program kaldığı yerden devam eder.

Bir fonksiyon başka bir fonksiyonu çağırırsa stack'te iki katlı bir birikim olur; çağrılan fonksiyonun bilgileri de üste konur. Sonsuz bir kendini çağırma olursa stack'e sürekli yeni bilgi eklenir, çağırma süreci hiç bitmez ve stack taşar. **Stack overflow** budur.

Stack overflow için sonsuz döngü şart değildir: program çok büyük sayıda iç içe fonksiyon çağrısı yapıyorsa da stack overflow olabilir.

## 4. Durma Koşulu ve Doğru Tasarım

### 4.1 Özyinelemesiz parça eklemek

Sorun belli: fonksiyon her zaman kendini çağırıyor. O halde fonksiyonun içinde hem kendini çağırdığı hem de çağırmadığı bir kısım olmalıdır. Düzeltilmiş akış diyagramı (ekrandan, 00:55:00):

```text
fakto(N)  ->  T
      |
   N == 1 ?
   T /    \ F
T = 1      T = N * fakto(N-1)
     \    /
     return
```

$N = 1$ ise, yani `fakto(1)` çağrıldıysa, $T = 1$ olur ve fonksiyon kendini çağırmaz. $N$ birden büyükse (negatif girilmediği sürece küçük olmayacaktır) $T = N \cdot \text{fakto}(N-1)$ hesaplanır. `while` ya da `for` gibi bir döngü yazmaya gerek yoktur; döngüyü fonksiyonun kendini çağırması oluşturur.

### 4.2 f(3) çağrısının izlenmesi

Tahtada izlenen örnek (ekrandan, 00:55:00):

- $f(3)$ çağrılır. $N = 1$ değil; $3 \cdot f(2)$ hesaplanmalı. $f(3)$ stack'e konur, $f(2)$ çağrılır.
- $f(2)$: $N = 1$ değil; $2 \cdot f(1)$ hesaplanmalı. $f(2)$ de stack'e konur. Stack'te en altta $f(3)$, üstünde $f(2)$ vardır.
- $f(1)$: $N = 1$ olduğu için $T = 1$ döner; kendini çağırmaz.
- $f(2)$ stack'ten çekilir: $2 \cdot 1 = 2$.
- $f(3)$ stack'ten çekilir: $3 \cdot 2 = 6$.

Mekanizma budur: döngü kurmaya gerek kalmadan stack mekanizması ve özyineleme mekanizması işi halleder.

**Soru:** Durma durumundaki $f(1) = 1$ her zaman etkisiz eleman mı oluyor? Toplama olsaydı orada 0 mı olurdu? **Cevap:** Etkisiz değil, oldukça etkilidir; faktöriyelde buraya 1 yerine 0 yazılsaydı fonksiyon yanlış cevap verirdi. Bu tamamen algoritmanın tasarımına bağlıdır. Örneğin 1'den $n$'e kadar sayıların toplamı bu yolla bulunacaksa durma durumu ona göre tasarlanır. Durma kontrolünün illa $n == 1$ olması ya da dönen değerin illa 1 olması gerekmez.

> **Hocanın vurgusu:** Önemli olan, fonksiyonun özyinelemeli olan parçası ile olmayan parçasının birlikte bulunmasıdır. Bunların içinin nasıl olacağı algoritma tasarımına bağlıdır.

### 4.3 Kendini aynı parametreyle çağırmak

İki parçalı yapı stack overflow'u bir ölçüde engeller, ama yetmez. Özyinelemeli kutuya $T = N \cdot \text{fakto}(N-1)$ yerine $T = N \cdot \text{fakto}(N)$ yazılsaydı (ekrandan, 01:00:00) yine stack overflow olurdu: $f(3) = 3 \cdot f(3)$ olur ve $f(3)$ tekrar $f(3)$'ü çağırır.

> **Hocanın vurgusu:** Özyinelemeli bir fonksiyon kendini aynı parametrelerle çağırmamalı. $f(n)$, $f(n)$'i çağırmamalı; parametrede mutlaka bir azalma olmalı ki özyinelemesiz kısma inilebilsin.

### 4.4 C neden uyarmıyor: dil seviyeleri

Programlama dilleri alt, orta ve üst seviyeli diye ayrılır. Bu seviye; derleyicinin, işletim sisteminin ya da dilin kendisinin programcıyı ne kadar denetlediğine, ne kadar özgür bıraktığına ve ne kadar yol gösterdiğine bağlıdır.

- Dil, yazılan programı ne kadar çok denetliyorsa o programı çalıştırmak o kadar güvenlidir; ama aynı sebeple o kadar yavaştır. İşletim sistemine zarar vermemesi, izin verilmeyen bellek bloğuna gitmemesi gibi her kontrol yavaşlamaya yol açar.
- Hız isteniyorsa bu kontrollerin kalkması gerekir. Bu, programcıya büyük bir özgürlük alanı açar, ama programı çalıştırmak tehlikeli hale gelir; programcının her şeye dikkat etmesi gerekir.

C orta seviyeli bir dildir. Stack overflow'a yol açacak bir kodu önceden okuyup uyaran ya da çalışma sırasında uyaran diller vardır, ama C'de böyle bir şey yoktur: kod yazılır, çalıştırılır ve stack overflow hatası alınır.

### 4.5 Negatif girdi

Düzeltilmiş `fakto` iyi görünse de ana algoritmada `M = fakto(-3)` çağrılırsa (ekrandan, 01:00:00) yine stack overflow olur. Çünkü yalnız $N == 1$ kontrol ediliyor: $-3$, $-4$'ü çağırır, $-4$ de $-5$'i ve bu hiç bitmez. Koşulun "sıfırdan büyük mü" ya da "birden büyük mü" gibi bir şekilde tasarlanması gerekir. Bunlar hep düşünülerek tasarlanmalıdır.

Özetle, $f$'in içinde $f(n)$'in çağrılmaması ve $f$'in çağrılmadığı bir bölüm olması iki şarttır; bu iki şart sağlansa bile stack overflow olabilir.

## 5. Basit Üs Alma

İkinci klasik örnek üs almadır. $x^n = x \cdot x \cdots x$, yani $x$ kendisiyle $n$ kez çarpılır. Son çarpandan önceki parça $n-1$ tane $x$'in çarpımıdır, bu yüzden

$$x^n = x^{n-1} \cdot x$$

yazılabilir. Bu, üs almanın özyinelemeli tanımıdır.

Fonksiyonun adı `üs`, iki parametresi `x` ve `n`, dönüş değeri `T` olsun. Durma durumu $x^1 = x$'tir:

```text
üs(x, n)  ->  T
      |
   n == 1 ?
   T /    \ F
 T = x     T = x * üs(x, n-1)
     \    /
     return
```

Fonksiyon kendini birebir aynı parametreyle çağırmıyor: $x^n$, $x^{n-1}$'i çağırıyor ve bulunan sonucu $x$ ile çarpıp $T$'yi buluyor. Bu yüzden ilk bakışta sorun görünmüyor.

<!-- BELİRSİZ: Bu akış diyagramının çizildiği anın karesi yok (01:10:00 karesi ara ekranı); diyagram altyazıdaki anlatımdan kuruldu. -->

**Soru (hocanın):** Bu fonksiyon negatif bir üsle çağrılırsa ne olur? **Cevap:** Stack overflow olur, çünkü $n == 1$ koşulu hiç sağlanmaz. Bu fonksiyon da bir düzeltme ister.

<!-- BELİRSİZ: Hocanın önce sorduğu ve cevabı "16" olan çağrının argümanları altyazıda bozuk. -->

## 6. Ne İş Yapıyor? Üç Özyinelemeli Fonksiyon

Bu bölümde hoca adı ipucu vermesin diye hep `f` olan üç fonksiyon yazdı ve her biri için üç dakika süre verip ne iş yaptıklarını öğrencilere sordu. Öğrencilerden fonksiyonu kafalarında ya da kağıt üzerinde çalıştırmaları istendi.

### 6.1 f(a, b): toplama

Akış diyagramı (ekrandan, 01:15:00):

```text
f(a, b)  ->  T
      |
   b == 0 ?
   T /    \ F
 T = a     T = f(a+1, b-1)
     \    /
     return
```

Çağrı: `M = f(12, 4)`. Çoğu öğrenci "$a + b$" cevabını verdi; doğru cevap budur. Fonksiyon her adımda $b$'den bir alıp $a$'ya ekler:

- $f(12, 4) \to f(13, 3) \to f(14, 2) \to f(15, 1) \to f(16, 0)$
- $b = 0$ olunca $T = a = 16$ döner.

Yani iki sayının toplamı da özyinelemeli olarak yapılabilir.

### 6.2 f(dizi, b): ilk b elemanın toplamı

Akış diyagramı (ekrandan, 01:25:00):

```text
f(dizi, b)  ->  T
      |
   b == 1 ?
   T /    \ F
T = dizi(b)     T = dizi(b) + f(dizi, b-1)
     \    /
     return
```

Cevap: dizinin $b$'inci elemanına kadar olan elemanları, yani ilk $b$ elemanı toplar. Dizi $b$ elemanlıysa bütün elemanları toplar; dizi daha büyükse ilk $b$ elemanı toplar. Öğrencilerin verdiği cevapların hepsi doğruydu.

> **Ek bilgi (derste anlatılmadı):** Akış diyagramlarında indis 1'den başlatılmıştır (durma koşulu $b == 1$). C'de dizi indisleri 0'dan başladığı için bu fonksiyon C'ye aktarılırken durma koşulunun ve indislerin buna göre kaydırılması gerekir.

### 6.3 f(dizi, b, x): arama

Bu fonksiyonun üç parametresi ve birden fazla özyinelemesiz parçası vardır (ekrandan, 01:30:00):

```text
f(dizi, b, x)  ->  T
        |
     b < 1 ?
  T /       \ F
T = -1    dizi[b] == x ?
           T /     \ F
          T = b     T = f(dizi, b-1, x)
        \     |     /
          return
```

- $b < 1$ ise $T = -1$.
- Değilse, dizinin $b$'inci elemanı $x$'e eşitse $T = b$ döner.
- O da değilse fonksiyon $b$ yerine $b-1$ ile kendini çağırır; başka bir şey değişmez.

Cevap: bu bir arama algoritmasıdır. Dizide $x$'i arar; varsa dizideki yerini (indisini), yoksa $-1$ döndürür. Bir öğrencinin "dizinin $b$'inci elemanından $x$'e kadar olanları topluyor" cevabı yanlıştı, çünkü burada toplama yoktur. Cevapların büyük çoğunluğu doğruydu.

## 7. Özyineleme Ağacı ile Karmaşıklık Analizi

### 7.1 Özyineleme bize zaman kazandırıyor mu

Faktöriyel standart olarak bir `for` döngüsüyle de yazılabilir. Onu özyinelemeli yazmak zaman açısından bir şey kazandırır mı? Bunu görmek için özyinelemeli algoritmanın analizi gerekir.

Döngülü algoritmalarda toplamlar ve çarpımlar `for` ve `while` yapıları içinde belliydi; analiz sigmalarla rahatça yapılabiliyordu. Özyinelemeli algoritmalarda böyle bir yapı yoktur, bu yüzden analiz için **özyineleme ağaçları (recursion tree)** çizilir.

### 7.2 Ağacın yapısı

$T(n)$, $f$ fonksiyonu $n$ parametresiyle çağrıldığında yapılan işlem sayısıdır. Ağacın düğümünde **özyinelemesiz kısımda** yapılan işlem sayısı, dallarında **özyinelemeli kısımdaki** çağrılar yer alır. Ağacın tek kolu olabilir, birden fazla kolu da olabilir (ekrandan, 01:35:00):

```text
T(n) ->   1              1
          |            /   \
       T(n-1)      T(n-1)  T(n-1)
```

Faktöriyelde $f(n) = n \cdot f(n-1)$: özyinelemesiz kısımda $n$'e bağlı tek bir işlem (bir çarpma) vardır. Burada çarpma yerine toplama ya da çıkarma olsa da aynıdır, bir işlemdir. Özyinelemeli kısımda ise $f(n-1)$ kadar işlem vardır. Bu yüzden karmaşıklık cinsinden

$$T(n) = 1 + T(n-1)$$

yazılır.

### 7.3 T(n) = 1 + T(n-1) çözümü

Ağaç açılmaya devam eder: $T(n-1)$ açılınca $1$ ve $T(n-2)$, $T(n-2)$ açılınca $1$ ve $T(n-3)$ gelir. Sonunda mutlaka özyinelemesiz kısma ulaşılır ve ağaç yalnız 1'lerden oluşan bir zincir olur.

Ağacın içindeki işlemlerin toplamı algoritmanın karmaşıklığını verir. Parametre her seferinde bir azaldığı için ağacın yüksekliği $h = n$'dir; ağaçta $n$ tane 1 vardır. Dolayısıyla $T(n) = O(n)$.

### 7.4 Sonuç: kazanç yok

Faktöriyelin döngülü hali de $n$ tane çarpma yapar, yani $O(n)$'dir. Özyinelemeli yazmak hiçbir şey kazandırmadı; hatta kaybettirdi. Kayıp fonksiyon çağrılarından gelir: fonksiyon çağrılır, stack'e konur, sonra geri çekilir. Bu yüzden özyinelemesiz yazılsa daha hızlı olur.

Basit üs almada da yapı aynıdır: $x^n = x \cdot x^{n-1}$, yani $T(n) = 1 + T(n-1)$ (ekrandan, 01:40:00). Şimdiye kadar görülen arama gibi örneklerde de parametre birer birer azaltıldı ve özyinelemesiz durumda tek bir işlem yapıldı. Bunların hepsinin karmaşıklığı $O(n)$'dir, özyinelemesiz halleri de $O(n)$'dir. Yani şimdiye kadar görülen özyinelemeli algoritmalar hız kazandırmaz, yalnız özyineleme mantığını öğretir.

## 8. Hızlı Üs Alma

### 8.1 Algoritma

Şimdi işe yarayan, yani bir şey kazandıran özyinelemeli bir algoritma görüldü. Bu da $x^p$'yi bulan bir üs alma algoritmasıdır (ekrandan, 01:45:00):

```text
f(x, p)  ->  T
      |
   p == 0 ?
  T /     \ F
T = 1     k = f(x, floor(p/2))
  |             |
  |       p mod 2 == 1 ?
  |       T /        \ F
  |   T = x*k*k     T = k*k
   \        \        /
          return
```

- $p = 0$ ise $T = 1$; $x$'in sıfırıncı kuvveti zaten 1'dir.
- Değilse $k = f(x, \lfloor p/2 \rfloor)$ hesaplanır, yani üssün yarısının aşağı yuvarlanmış haliyle fonksiyon çağrılır. $p = 8$ ise $k = f(x, 4)$; $p = 9$ ise yine $k = f(x, 4)$.
- Sonra $p$'nin tek mi çift mi olduğuna bakılır: $p \bmod 2 = 1$ (tek) ise $T = x \cdot k \cdot k$, çift ise $T = k \cdot k$.

### 8.2 Neden çalışıyor

Tahtadaki gerekçe (ekrandan, 01:50:00):

- $p = 9$ tek: $k = x^4$, $T = x \cdot x^4 \cdot x^4 = x^9$.
- $p = 16$ çift: $k = x^8$, $T = x^8 \cdot x^8 = x^{16}$.

### 8.3 Çağrıların izlenmesi

**Soru:** $k$ için $f(x, p/2)$ yeniden gönderildiğinde, örneğin 9 için 4 gönderildiğinde, 4 de tekrar aynı süreçten geçmeyecek mi? **Cevap:** Geçecek. $f(x, 16)$ çağrılınca $k = f(x, 8)$ gerekir ve fonksiyon başa döner; $f(x, 8)$'in $k$'sı $f(x, 4)$, onunki $f(x, 2)$, onunki $f(x, 1)$'dir. $1$'in yarısı aşağı yuvarlanınca $0$ olur; $p = 0$ olunca $T = 1$ döner. Sonra değerler yukarı doğru toplanmaya başlar. Diğer özyinelemeli fonksiyonlarda olduğu gibi her çağrı en başa döner, adım adım işlenir; özyinelemesiz kısma kadar inilir, sonra yukarı çıkılır.

Bir öğrenci geri dönüş kısmını tekrar sordu. Hoca önce faktöriyeldeki stack işleyişini hatırlattı: $f(5)$, $f(4)$'ü; $f(4)$, $f(3)$'ü; ... $f(2)$, $f(1)$'i çağırır; $f(1) = 1$ bulununca stack'ten geri çekilmeye başlanır ve her adım bir öncekinin değerini kullanır. Sonra $f(x, 9)$ için aynı izlemeyi yaptı (ekrandan, 01:55:00):

- $f(x, 9)$: $k = f(x, 4)$ gerekir.
- $f(x, 4)$: $k = f(x, 2)$; $f(x, 2)$: $k = f(x, 1)$; $f(x, 1)$: $k = f(x, 0)$.
- $f(x, 0) = 1$ (durma durumu).
- $f(x, 1)$'de $k = 1$; $p = 1$ tek olduğu için $T = x \cdot 1 \cdot 1 = x$ döner.
- $f(x, 2)$'de $k = x$; $p = 2$ çift olduğu için $T = x \cdot x = x^2$ döner.
- $f(x, 4)$'te $k = x^2$; $p$ çift, $T = x^4$ (ara adım eklendi).
- $f(x, 9)$'da $k = x^4$; $p$ tek, $T = x \cdot x^4 \cdot x^4 = x^9$ (ara adım eklendi).

$T$'nin döndüğü yerler `T = 1`, `T = x*k*k` ve `T = k*k` kutularıdır; $k$'nın satırında $T$ dönmez. Önce $f$ çağrıla çağrıla $k$ değerleri hesaplanır, sonra o anki $p$'ye bağlı işlemle $T$ değerleri bulunur.

**Soru:** Bunu `while` ile yapamaz mıyız? **Cevap:** Yapabilirsiniz. Özyinelemeli algoritmaların hepsi değil ama bir kısmı özyinelemesiz şekilde de yazılabilir; ama bazılarını öyle yazmak çok daha zor olabilir.

### 8.4 Karmaşıklık

Özyinelemesiz kısımda $T = 1$ vardır. Özyinelemeli kısımda fonksiyon kendini bu kez $p$ yerine $p/2$ ile ve bir kez çağırır. Ardından gelen işlemler (bir mod, en çok iki çarpma) problemin büyüklüğüyle değişmez; sabit sayıda işlemdir. Bu yüzden oraya 1 de yazılabilir 2 de, anlamı aynıdır: $n$'e (burada $p$'nin ya da $x$'in değerine) bağlı olmayan sabit sayıda işlem. Hoca bunu integraldeki sabit $c$'ye benzetti. Böylece

$$T(n) = 1 + T(n/2)$$

olur. Ağaç açılınca $1 + T(n/2)$, $1 + 1 + T(n/4)$, $1 + 1 + 1 + T(n/8)$, ... gelir. Her seferinde yarıya inildiği için yükseklik $h = \log_2 n$'dir; ağaçta $\log_2 n$ tane 1 vardır:

$$T(n) = O(\log_2 n)$$

Bu, $O(n)$ olan basit üs almaya göre çok daha kısadır. $f(x, 9)$ örneğinde de çağrı zinciri yalnız $9, 4, 2, 1, 0$ değerlerinden geçer.

### 8.5 k'yı iki kez hesaplasaydık

Hoca şunu sordu: $k$ kullanılmadan, `T = x*k*k` yerine $x \cdot f(x, \lfloor p/2 \rfloor) \cdot f(x, \lfloor p/2 \rfloor)$, `T = k*k` yerine $f(x, \lfloor p/2 \rfloor) \cdot f(x, \lfloor p/2 \rfloor)$ yazılsaydı ne olurdu? (ekrandan, 02:25:00)

Bu durumda iki dalda da fonksiyon $n/2$ ile iki kez çağrılır, sabit işlemler yine 1'dir:

$$T(n) = 1 + 2T(n/2)$$

Ağaç bu kez iki kollu olur (ekrandan, 02:00:00):

- 1. satır: bir tane 1 ($2^0$)
- 2. satır: iki tane 1 ($2^1$), altlarında iki tane $T(n/2)$
- 3. satır: dört tane 1 ($2^2$), altlarında dört tane $T(n/4)$
- 4. satır: sekiz tane 1, altlarında sekiz tane $T(n/8)$; sonra 16, 32 tane...
- Son satır: $2^h$ tane 1.

Yükseklik yine $h = \log_2 n$'dir. Toplam:

$$T(n) = \sum_{i=0}^{h} 2^i = 2 \cdot 2^{\log_2 n} - 1 = 2n - 1$$

Bu $O(n)$'dir. Hiçbir kazanç yoktur; basit yöntem $n$ adımda buluyordu, bu ise $2n$'e çıktı, $n$ hala duruyor.

> **Hocanın vurgusu:** Her dalda fonksiyon yalnız bir kez çağrılıp $k$ bulunursa $\log_2 n$ karmaşıklığa erişilir. İşin güzel tarafı burası.

## 9. Diğer Özyineleme Ağaçları

### 9.1 Merge sort ve quick sort: T(n) = 2T(n/2) + n

Merge sort ve quick sort algoritmalarının karmaşıklığı (ekrandan, 02:05:00)

$$T(n) = 2T(n/2) + n$$

bağıntısıyla verilir. Burada özyinelemesiz kısımda 1 değil $n$ adım işlem vardır.

Özyineleme ağacı kullanmanın amacı, özyinelemeli verilmiş bir bağıntıyı özyinelemesiz hale getirmektir. Önceki örneklerde $T(n) = n$, $T(n) = 2n - 1$, $T(n) = \log_2 n$ gibi $T$'ye bağlı olmayan ifadelere ulaşılmıştı. Burada da aynısı yapılır (ekrandan, 02:10:00):

- Kökte $n$, altında iki tane $T(n/2)$.
- Her $T(n/2)$ açılınca düğüme $n/2$ yazılır, altına iki tane $T(n/4)$ gelir.
- Sonraki satırda dört tane $n/4$ ve altlarında $T(n/8)$'ler gelir.

> **Hocanın vurgusu:** Kritik nokta şurası: $T(n/2)$ açılırken düğüme yine $n$ yazılırsa yanlış olur. Açılan kısım $T(n/2)$ olduğu için düğüme $n/2$ yazılır.

Satır toplamları:

- 1. satır: bir tane $n$ → $n$
- 2. satır: iki tane $n/2$ → $n$
- 3. satır: dört tane $n/4$ → $n$
- 4. satır: sekiz tane $n/8$ → $n$

Her satırın toplamı $n$'dir. Her seviyede ikiye bölündüğü için ağacın yüksekliği $h = \log_2 n$, yani $\log_2 n$ tane satır vardır:

$$T(n) = n \log_2 n$$

Bu, quick sort ve merge sort'un karmaşıklığıdır. Şimdiye kadar görülen sıralama algoritmaları genelde $n^2$ mertebesindeydi; $n$'ler ortak olduğundan $n \log n$, $n^2$'ye göre $n / \log n$ gibi bir hızlanma sağlar.

Hoca bu ağaçları farklı katsayılarla (2 yerine 3, $n$ yerine $n/2$ gibi) kendi başına deneyerek el alışkanlığı kazanmayı önerdi.

### 9.2 T(n) = 2T(n/2) + n/2

Hoca öğrencilere yalnız $n$'yi $n/2$ yapıp sonucu sordu (ekrandan, 02:10:00). Çözüm: kökte bu kez $n/2$ vardır; ikinci satırda iki tane $n/4$ (toplam $n/2$), üçüncü satırda dört tane $n/8$ (toplam $n/2$), dördüncü satırda sekiz tane $n/16$ (toplam $n/2$) olur. Her satırın toplamı $n$ yerine $n/2$ olur, yükseklikte değişiklik yoktur:

$$T(n) = \frac{n}{2} \log_2 n$$

Hocaya göre bunun için kural ezberlemeye gerek yoktur; bazı kurallar vardır ama analiz edince ne olup bittiği rahatça görülür.

**Soru:** Ağacın uzunluğunu neye göre belirliyorduk? **Cevap:** Ağaç en sonunda 1'e varana kadar kaç satıra sahip olacaksa yükseklik odur. $T(n) = 1 + T(n/2)$ için 8 ile başlanırsa $8 \to 4 \to 2 \to 1$ diye üç adımda iner; her adımda ikiye bölündüğü için yükseklik $\log_2 n$'dir. $T(n) = 1 + T(n-1)$ olsaydı $8 \to 7 \to 6 \to 5 \dots$ diye gider ve $h = n$ olurdu.

### 9.3 T(n) = T(n/2) + n

Son alıştırma $T(n) = T(n/2) + n$ idi (ekrandan, 02:20:00). İlk adımlar: kökte $n$, altında $T(n/2)$; açılınca $n$, $n/2$ ve $T(n/4)$ gelir, yani $T(n) = n + n/2 + T(n/4)$. Ağaç tek kollu olduğu için her satırın toplamı aynı değildir: $n, n/2, n/4, \dots, 1$.

Toplam $i = 0$'dan başlayan $\frac{n}{2^i}$ terimleridir. Yükseklik $h = \log_2 n$ (belki bir adım fazlası, bu çok kritik değil):

$$T(n) = \sum_{i=0}^{\log_2 n + 1} \frac{n}{2^i}$$

Hoca bu toplamın sonucunu öğrencilerin analizine bıraktı (çözüm Örnek Sorular bölümünde).

### 9.4 En kötü, en iyi ve ortalama durum

**Soru:** $k$ yerine fonksiyonu iki kez yazınca ağaç ikiye ayrıldı; üç kez yazsaydık üçe ayrılacaktı. Peki `if`'in bir tarafında üç, öbür tarafında iki çağrı olsaydı nasıl analiz ederdik? **Cevap:** En kötü durum (worst case) analizi yapılabilir: hep çok çağrı olan taraftan geçildiği varsayılır. En iyi durum (best case) analizinde hep az çağrı olan taraftan geçildiği varsayılır. Ortalama durum analizi için dallara girme olasılığı gerekir; hızlı üs almada bu $p \bmod 2 = 1$ koşuluna, yani $p$'nin tek ya da çift olmasına bağlıdır. Örneğin 0.3 olasılıkla iki kez, 0.7 olasılıkla bir kez çağrılıyor gibi bir bilgi gerekir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:46:33): Durma koşulu olmayan `fakto(N)` (yalnız `T = N * fakto(N-1)` ve `return`) `S = fakto(5)` ile çağrılırsa ne olur?

> **Çözüm:** $f(5) = 5 \cdot f(4)$, ..., $f(1) = 1 \cdot f(0)$, $f(0) = 0 \cdot f(-1)$, ... diye sonsuza gider. Sonuç dönmez; stack dolar ve stack overflow olur.

**Soru 2** (derste sözlü, 00:55:31; ekrandan, 01:00:00): Durma koşulu olan `fakto` fonksiyonunda özyinelemeli kutuya `T = N * fakto(N)` yazılsaydı ne olurdu?

> **Çözüm:** $f(3) = 3 \cdot f(3)$ olur; fonksiyon kendini aynı parametreyle çağırdığı için durma koşuluna hiç inilmez ve stack overflow olur.

**Soru 3** (ekrandan, 01:00:00): Düzeltilmiş `fakto` (`N == 1` ise `T = 1`, değilse `T = N * fakto(N-1)`) `M = fakto(-3)` ile çağrılırsa ne olur?

> **Çözüm:** $-3$, $-4$'ü; $-4$, $-5$'i çağırır; $N == 1$ koşulu hiç sağlanmaz, stack overflow olur. Durma koşulunun negatif girdileri de yakalayacak şekilde tasarlanması gerekir.

**Soru 4** (ekrandan, 01:15:00): Aşağıdaki fonksiyon ne iş yapar? `M = f(12, 4)` sonucu nedir?

```text
f(a, b) -> T
b == 0 ise T = a
değilse    T = f(a+1, b-1)
return
```

> **Çözüm:** $a + b$'yi hesaplar. $f(12,4) \to f(13,3) \to f(14,2) \to f(15,1) \to f(16,0) = 16$.

**Soru 5** (ekrandan, 01:25:00): Aşağıdaki fonksiyon ne iş yapar?

```text
f(dizi, b) -> T
b == 1 ise T = dizi(b)
değilse    T = dizi(b) + f(dizi, b-1)
return
```

> **Çözüm:** Dizinin ilk $b$ elemanını toplar; dizi $b$ elemanlıysa bütün elemanların toplamını verir.

**Soru 6** (ekrandan, 01:30:00): Aşağıdaki fonksiyon ne iş yapar?

```text
f(dizi, b, x) -> T
b < 1 ise              T = -1
değilse dizi[b] == x ise T = b
değilse                T = f(dizi, b-1, x)
return
```

> **Çözüm:** Dizide $x$'i sondan başa doğru arar. Bulursa yerini (indisini) $b$ olarak, bulamazsa $-1$ döndürür. Toplama yapmaz.

**Soru 7** (ekrandan, 02:25:00): Hızlı üs almada $k$ kullanılmadan, her $k$ yerine $f(x, \lfloor p/2 \rfloor)$ yazılsaydı karmaşıklık ne olurdu?

> **Çözüm:** $T(n) = 1 + 2T(n/2)$. Satırlarda $2^i$ tane 1 vardır, $h = \log_2 n$; $\sum_{i=0}^{h} 2^i = 2n - 1$, yani $O(n)$. $k$ bir kez hesaplanırsa $O(\log_2 n)$ olur.

**Soru 8** (ekrandan, 02:10:00): $T(n) = 2T(n/2) + n/2$ bağıntısının karmaşıklığı nedir?

> **Çözüm:** Her satırın toplamı $n/2$, satır sayısı $\log_2 n$ olur: $T(n) = \frac{n}{2} \log_2 n$, yani yine $n \log n$ mertebesi.

**Soru 9** (ekrandan, 02:20:00): $T(n) = T(n/2) + n$ bağıntısının karmaşıklığını özyineleme ağacıyla bulun.

Derste ağaç kuruldu ve toplam $\sum_{i=0}^{\log_2 n + 1} \frac{n}{2^i}$ olarak yazıldı; son adım öğrencilere bırakıldı.

> **Çözüm (derste verilmedi):** $\sum_{i \ge 0} \frac{n}{2^i} = n \left(1 + \frac12 + \frac14 + \cdots\right) < 2n$ olduğundan toplam $2n$'yi geçmez ve en az $n$'dir. Bu yüzden $T(n) = O(n)$. Python ile $n = 1024$ için toplam $2047.5$ çıktı, yani yaklaşık $2n$.

## Dersin Toparlaması

Bu derste özyinelemeli fonksiyonun kendini çağıran fonksiyon olduğu, doğrudan ve dolaylı olabileceği görüldü. Faktöriyel üzerinden her özyinelemeli fonksiyonda kendini çağırmayan bir durma parçasının bulunması, parametrenin her çağrıda bu parçaya doğru küçülmesi ve durma koşulunun bütün girdileri yakalaması gerektiği gösterildi; aksi halde stack taşar. Basit üs alma, toplama, dizi toplamı ve dizide arama akış diyagramlarıyla çalışıldı.

İkinci yarıda özyineleme ağacıyla karmaşıklık analizi başladı. $T(n) = 1 + T(n-1)$ türündeki örneklerin $O(n)$ olduğu ve döngülü hallerine göre bir kazanç sağlamadığı görüldü. Hızlı üs almada $k$ bir kez hesaplanınca $T(n) = 1 + T(n/2)$, yani $O(\log_2 n)$ elde edildi; aynı çağrı iki kez yapılınca kazanç kayboldu. Merge sort ve quick sort'un $T(n) = 2T(n/2) + n$ bağıntısından $n \log_2 n$ sonucu çıkarıldı. Bir sonraki derste özyinelemeli algoritmaların analizine ve özyineleme ağaçlarına daha ayrıntılı devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
