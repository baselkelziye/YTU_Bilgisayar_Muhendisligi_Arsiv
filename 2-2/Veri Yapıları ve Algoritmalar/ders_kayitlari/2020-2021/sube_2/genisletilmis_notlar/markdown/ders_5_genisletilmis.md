# Ders 5 Genişletilmiş Notu: Algoritma Analizi Temelleri, Büyüme Oranları ve Büyük O Gösterimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Haftaların Özeti ve Bu Haftanın Yeri
- 2. Algoritma Analizi Nedir, Neden Gerekir?
- 3. Empirik Analiz ve Sınırları
- 4. Teorik Algoritma Analizi
- 5. Algoritmaların İşletim Süresi: Maliyet Hesabı
- 6. Büyüme Oranı Kavramı
- 7. Yaygın Büyüme Oranları
- 8. Döngülerin Büyüme Oranları
- 9. Büyük O Gösterimi
- 10. Algoritma Seviyesi: O, Omega ve Teta
- 11. Büyük O'nun Özellikleri ve Örnekler
- 12. Özyinelemeli Algoritmalarda Büyük O: Fibonacci
- 13. En Kötü, En İyi ve Ortalama Durum Analizi
- 14. Sıralı Arama ve İkili Arama
- 15. Zaman ve Bellek Karmaşıklığı
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Haftaların Özeti ve Bu Haftanın Yeri

Ders, ilk iki haftanın kısa bir özetiyle açıldı. Önceki haftalarda algoritmanın, verinin ve veri yapısının ne olduğu, veri yapısı ile algoritmanın birlikte nasıl çözüm ürettiği konuşulmuştu. Akış diyagramı çizme ve sözde kod (pseudocode) yazma pratik yapılmış, dersin temel algoritmalarının C ile kodlanacağı ve C'de nelere dikkat edileceği hatırlatılmıştı. Ayrıca örnek problemler üzerinden algoritmik çözüm geliştirmeye çalışılmıştı.

Hoca algoritma hazırlama sürecini hatırlattı: önce tasarım, sonra doğrulama (validasyon), sonra analiz. Bu haftanın konusu bu zincirin üçüncü halkası, yani bir algoritmanın nasıl analiz edileceğidir. Hoca bu konunun ileriki dönemde ayrı bir derste ayrıntılı işleneceğini, burada temellerin olabildiğince basit anlatılacağını söyledi. Slayt kapağı "Algoritma Analizi Temelleri" başlığını taşıyordu (ekrandan, 00:10:00).

## 2. Algoritma Analizi Nedir, Neden Gerekir?

Algoritma analizi, farklı çözüm yöntemlerinin başarımını analiz etmeyi sağlayan araçlar sunan bir çalışma alanıdır. Bilgisayar bilimlerinin (computer science) özel bir alanı sayılır. "Başarım" burada performans anlamındadır.

Algoritma analizine üç sebeple ihtiyaç duyulur:

- Tek bir algoritmanın performansını ölçmek.
- Aynı problemi çözen farklı algoritmaları (farklı akışları, yaklaşımları) aynı ölçütle karşılaştırmak.
- Geliştirilen çözümün, verilen şartlar altında olabileceklerin en iyisi olup olmadığını, daha iyisinin mümkün olup olmadığını araştırmak.

Aynı problemi (örneğin sıralama ya da arama) çözen iki algoritma olsun: A ve B. Bunların performansını karşılaştırmanın iki temel yolu vardır: **teorik analiz** ve **empirik analiz**. Hoca teknik ve "çetrefilli" olan teorik analizi sona bıraktı ve önce daha basit olan empirik yöntemi anlattı.

## 3. Empirik Analiz ve Sınırları

Empirik yöntemde algoritmalar belirli bir programlama diliyle gerçeklenir (implement edilir), aynı ortamda çalıştırılır ve işletim süreleri karşılaştırılır. Hoca bunu kimyadaki "normal şartlar altında" benzetmesiyle anlattı: aynı şartlarda iki gerçeklemeyi kronometreyle çalıştırırsınız, hangisi önce biterse o daha performanslıdır.

Bu yöntem basittir ama aslında algoritmanın değil, **programın** performansını ölçer. Sakıncaları şunlardır:

- **Kodlama biçimi:** Aynı algoritma farklı biçimlerde kodlanabilir. Önceki haftalardaki asal sayı örneğinde olduğu gibi, döngüyü `while` ile mi `for` ile mi yazdığınız, kontrolü başta mı içeride mi yaptığınız işlem sayısını değiştirir.
- **Programcının stili:** A'yı bir kişi, B'yi başka biri kodladıysa ölçüm adil olmayabilir.
- **Bilgisayar ve anlık durumu:** Aynı bilgisayarda bile o an çalışan süreç sayısı, tuşa basma ya da fare hareketinin yarattığı kesmeler (interrupt), ağ trafiği ya da arka planda çalışan bir işletim sistemi güncellemesi işlemcinin bir kısmını meşgul eder. Daha iyi bir algoritma bu yüzden daha yavaş ölçülebilir.

Hoca bu yöntemin kabaca fikir vermek için yine de kullanılabileceğini söyledi. Ama asıl istenen, başarımı şunlardan **bağımsız** hesaplamaktır:

- Bilgisayarın özellikleri.
- Verinin özellikleri (tamsayı mı, kayan noktalı mı, 32 bit mi, 64 bit mi).
- Programlama dilinin sunduğu optimizasyonlar, avantajlar ve dezavantajlar.

## 4. Teorik Algoritma Analizi

Slayttaki tanım şöyledir (ekrandan, 00:20:00): Algoritma analizi sırasında, algoritmanın başarımını gerçekleştirim, bilgisayar ya da veriden bağımsız değerlendirmeye olanak sağlayan matematiksel yöntemler kullanılabilmesi gereklidir. Algoritma analizinde:

- Belirli bir çözümün etkinliğini belirlemek için öncelikle önemli işlemlerin sayısı belirlenir.
- Ardından büyüme fonksiyonları (growth function) kullanılarak algoritma etkinliği ifade edilir.

Yani önce işlemciyi yoran her şey (atamalar, karşılaştırmalar, aritmetik işlemler, çağrılar) sayılır. Sonra bu sayının veri boyutuyla nasıl değiştiği bir fonksiyonla ifade edilir. Büyüme fonksiyonu kullanılmasının sebebi, çalışma süresinin veri boyutuna bağlı olmasıdır: 10 elemanlı bir dizide arama yapmakla 10 milyar elemanlı bir dizide arama yapmak aynı sürede bitmez. Temel amaç, performansı veri boyutuyla orantılı biçimde ifade edebilmektir.

## 5. Algoritmaların İşletim Süresi: Maliyet Hesabı

### 5.1 Sabit Maliyetli İşlemler

Her işlemin bir maliyeti vardır. Bir atama ya da aritmetik işlem, derleyici tarafından sonunda toplama, çıkarma, karşılaştırma, taşıma gibi temel makine komutlarına çevrilir. Belirli bir mimaride (hoca 64 bitlik Intel, Apple M1 ve ARM gibi RISC mimarilerini örnek verdi) bu komutların kaç saat çevrimi (clock cycle) sürdüğü bellidir. Bu yüzden bir komutun işletilmesi sabit bir süre, yani sabit bir maliyet (cost) yaratır. Maliyetler, "cost" kelimesinin baş harfiyle $c_1, c_2, \dots$ diye adlandırılır.

- `count = count + 1;` satırı bir toplama ve bir atama yapar; maliyeti $c_1$ olsun.
- `sum = sum + count;` satırında `count` ve `sum` okunur, toplanır ve `sum`'a yazılır; maliyeti $c_2$ olsun.

Bu iki satırdan oluşan akışın toplam maliyeti $c_1 + c_2$'dir. Ardışık komutlarda maliyetler toplanır.

### 5.2 Karar Yapısı (if-else)

Bir `if` karşılaştırması da sabit maliyetli bir işlemdir ($c_1$) ve bu örnekte bir kez çalışır. Koşul doğruysa bir değişkene $-n$ atanır ($c_2$), yanlışsa `else` kolundaki başka bir atama çalışır ($c_3$). İki kol aynı anda çalışamaz. Bu yüzden toplam maliyet $c_1 + c_2 + c_3$ değil, şudur:

$$T = c_1 + \max(c_2, c_3)$$

Koşulun maliyetine iki koldan maliyetli olanı eklenir, çünkü karşılaşılabilecek en yüksek maliyet budur.

<!-- BELİRSİZ: if-else ve count/sum örneklerinin bulunduğu slaytın karesi okunmadı; kod satırları altyazıdan aktarıldı. -->

### 5.3 Basit Döngü Maliyeti

Slayttaki örnek (ekrandan, 00:25:00):

```text
                              Maliyet   Tekrar
i = 1;                        c1        1
sum = 0;                      c2        1
while (i <= n) {              c3        n+1
        i = i + 1;            c4        n
        sum = sum + i;        c5        n
}
Toplam Maliyet = c1 + c2 + (n+1)*c3 + n*c4 + n*c5
```

`while` koşulu $n+1$ kez denetlenir, çünkü koşul "küçük eşit" olduğu için döngüden çıkarken bir denetim daha yapılır. Döngü gövdesindeki iki satır $n$ kez çalışır. Hoca sabitlerin önemli olmadığını, hepsinin büyük bir $C$ altında toplanabileceğini söyledi:

$$T(n) = (c_3 + c_4 + c_5)\,n + (c_1 + c_2 + c_3) = C_1 n + C_2$$

Bu algoritma için gereken süre $n$ ile doğru orantılıdır. $n = 100$ için 100 kat, $n = 10.000$ için 10.000 kat işlem yapılır; çalışma süresi doğrusal artar.

### 5.4 İç İçe Döngü Maliyeti

Slayttaki örnek (ekrandan, 00:30:00):

```text
                                  Maliyet   Tekrar
i=1;                              c1        1
sum = 0;                          c2        1
while (i <= n) {                  c3        n+1
        j=1;                      c4        n
        while (j <= n) {          c5        n*(n+1)
                sum = sum + i;    c6        n*n
                j = j + 1;        c7        n*n
        }
        i = i + 1;                c8        n
}
Total Cost = c1 + c2 + (n+1)*c3 + n*c4 + n*(n+1)*c5 + n*n*c6 + n*n*c7 + n*c8
```

Hoca dış döngünün gövdesini (slaytta kırmızı çerçeve) işaretleyerek bu bloktaki her satırın mutlaka $n$ çarpanını taşıdığını gösterdi. İç döngünün koşulu her dış turda $n+1$ kez denetlenir; toplam $n(n+1)$ kez. İç gövdedeki iki satır $n \cdot n$ kez çalışır. Terimler gruplanınca şu elde edilir:

$$T(n) = (c_5 + c_6 + c_7)\,n^2 + (c_3 + c_4 + c_5 + c_8)\,n + (c_1 + c_2 + c_3)$$

Bu algoritma için gereken süre $n^2$ ile doğru orantılıdır. 10 elemanlı dizi için 100, 100 elemanlı dizi için 10.000, 1000 elemanlı dizi için 1 milyon kez maliyete katlanılır. Yalnız 1000 eleman üzerinde çalışıldığı hâlde 1 milyon işlem yapılır.

### 5.5 Genel Kurallar

Hoca maliyet kalemlerini şöyle topladı:

- **Döngüler:** İşletim süresi en fazla, yineleme sayısı ile döngü içindeki komutların toplam işletim süresinin çarpımıdır.
- **İç içe döngüler:** En içteki bloğun komutlarının toplam süresi, bütün döngülerin yineleme sayılarının çarpımıyla çarpılır. Üç iç içe döngü küp mertebesine çıkar: 10 eleman için 1000 işlem.
- **Ardışık komutlar:** Her komutun işletim süresi toplanır.
- **if-else:** Koşulun süresine iki koldan maliyetli olanın süresi eklenir.

Maliyet girdi boyutuyla orantılıdır. Girdi boyutu genellikle $n$ ile gösterilir. Bazen iki farklı girdi boyutuyla aynı anda çalışılır; o zaman $n \cdot m$ gibi ifadeler ortaya çıkar.

## 6. Büyüme Oranı Kavramı

Maliyetin girdi boyutuyla belirli katsayılarla arttığı görüldü: $n$, $n^2$ gibi. Algoritmanın girdiye göre ne oranda büyüdüğüne **büyüme oranı** denir. Şu an odak zaman ihtiyacıdır; bellek (uzay) ihtiyacı da bir performans ölçütü olabilir. Zaman gereksinimi, problem boyutunun bir fonksiyonu olarak ölçülür. Problem boyutu uygulamaya bağlıdır: kaç eleman sıralanacak, kaç kullanıcılı bir listede arama yapılacak gibi.

### 6.1 A ve B Algoritmaları

$n$ boyutlu bir problem için iki çözüm olsun:

- A algoritması $n^2/5$ birim zaman ister.
- B algoritması $5n$ birim zaman ister.

A'nın zaman ihtiyacı $n^2$ ile, B'ninki $n$ ile orantılıdır. İkisinin eşit olduğu bir nokta vardır ve o noktadan sonra B her zaman daha hızlı çalışır. Algoritmaların bu oransal zaman gereksinimine büyüme oranı denir. **Ne kadar hızlı büyüyorsa o kadar kötü, ne kadar yavaş büyüyorsa o kadar iyidir.** Algoritmalar doğrudan büyüme oranlarına bakılarak karşılaştırılabilir.

> **Ek bilgi (derste anlatılmadı):** $n^2/5 = 5n$ eşitliği $n = 25$'te sağlanır. $n < 25$ için A, $n > 25$ için B daha az zaman ister.

### 6.2 Grafikle Karşılaştırma

Slayttaki grafikte (ekrandan, 00:45:00) yatay eksen giriş verisi $N$, dikey eksen çalışma zamanı $T(N)$'dir. Algoritma 1 doğrusal (kesikli çizgi), Algoritma 2 eğri biçiminde artar ve iki eğri $N = 1000$ civarında kesişir. Küçük $N$'de Algoritma 2 daha hızlıdır. $N$ büyüdükçe Algoritma 2 "zamana aç" hale gelir; 1 milyon, 1 milyar mertebelerinde ihtiyaç duyduğu süre mantık sınırlarının dışına çıkar.

Hoca şu sonucu vurguladı: küçük girdilerdeki milisaniyelik kazançlar önemsizdir. $n$'nin ne olacağı hiçbir zaman tam bilinemediği için toplamda çok daha kârlı olan, büyüme oranı küçük algoritma tercih edilir. Hoca ayrıca elle logaritmik bir eğri çizerek "Algoritma 3" adını verdi: başta daha yüksek maliyetli görünse de çok yavaş arttığı için büyük $n$'de üçünün en iyisidir.

### 6.3 Sayısal Tablo

Hoca $n < 1000$ bölgesi için bir tablo üzerinden iki algoritmayı karşılaştırdı. Altyazıya göre $n = 10$ için birinci algoritma $10^{-2}$, ikinci algoritma $10^{-4}$ saniye sürer; $n = 100$ için $10^{-1}$ ve $10^{-2}$ saniye; $n = 1000$ için ikisi aynı sürede biter. $n = 10.000$ için birinci 10 saniye, ikinci 100 saniye sürer. Sonrasında birincisi doğrusal artarken (her 10 katta süre 10 kat), ikincisi çok daha hızlı artar. Küçük $n$ bölgesi ihmal edilebilir; teorik analizde önemli olan büyük $n$ bölgesidir.

<!-- BELİRSİZ: Bu tablonun karesi okunmadı; değerler yalnız altyazıdan alındı. -->

> **Ders sonrası not:** Hoca $10^{-2}$ ile $10^{-4}$ saniye için "iki kat daha hızlı" dedi; aradaki fark büyük olasılıkla iki kat değil, iki büyüklük mertebesidir (100 kat). Aynı şekilde $10^{-1}$ ile $10^{-2}$ arasındaki fark 10 kattır.

## 7. Yaygın Büyüme Oranları

Slayttaki tablo (ekrandan, 00:55:00):

| Fonksiyon | Büyüme oranı ismi |
|---|---|
| $C$ | Sabit |
| $\log N$ | Logaritmik |
| $\log^2 N$ | Logaritmik kare |
| $N$ | Doğrusal |
| $N \log N$ | Doğrusal logaritmik |
| $N^2$ | İkinci derece (kare) |
| $N^3$ | Kübik |
| $2^N$ | Üstel |
| $N!$ | Faktöriyel |

Hoca bunları en iyiden en kötüye şöyle anlattı:

- **Sabit ($C$):** Girdi kaç olursa olsun algoritma hep sabit zamanda çalışır. Olabilecek en iyi durumdur ama bu durumu sağlayan algoritma azdır. Hoca hash tablolarındaki atamaları örnek verdi.
- **Logaritmik ($\log n$):** Çok yavaş artar. $\log n$ büyüme oranlı bir çözüm bulmak çok iyidir.
- **Logaritmik kare ($\log^2 n$):** Biraz daha hızlı artar ama doğrusaldan iyidir.
- **Doğrusal ($n$):** "Ne kadar ekmek, o kadar köfte": 1000 girdi için 1000 saniye, 10.000 girdi için 10.000 saniye. İyi kabul edilir.
- **Doğrusal logaritmik ($n \log n$):** Yabancı kaynaklarda "linearithmic" de denir. Doğrusaldan biraz yüksektir ama kabul edilebilir.
- **Kare ($n^2$):** $n = 1000$ için 1 milyon, $n = 10.000$ için 100 milyon işlem. Bundan sonrası kabul edilemez noktalara gider.
- **Kübik ($n^3$):** Her 10 kat artışta 3 sıfır eklenir. İç içe 4 döngü $n^4$ demektir; 1 milyon elemanlı dizide 24 sıfırlı bir işlem sayısı.
- **Üstel ($2^n$):** Çok kötüdür ama bu derste bazı durumlarda kaçınılmaz olarak karşılaşılacaktır. Hoca satranç tahtasına pirinç yerleştirme hikâyesini hatırlattı: $2^{64}$ tane pirinç bulunamaz.
- **Faktöriyel ($n!$):** Hocaya göre "olabilecek en kötü şey"dir; pratikte çözümsüzlük demektir. Böyle bir karmaşıklık çıkıyorsa büyük olasılıkla doğru bir çözüm bulunamamıştır ve farklı bir yaklaşım gerekir.

Karşılaştırma grafiğinde (ara sonrası tekrar edildi) $\log n$ ve $\log^2 n$ çok yavaş artar; $n \log n$ ve $n$ kabul edilebilir bölgededir; $n$ 45 derece eğimle artar; $n^2$ ve $n^3$ dikleşir; $2^n$, $n!$ ve $n^n$ "roket gibi" dimdik yükselir. Hoca $n$ 10'dan 20'ye çıktığında bile bunların neredeyse çözülemeyeceğini söyledi.

> **Hocanın vurgusu:** Döngü sayısını azaltarak $n^2$ mertebesini düşürmeye çalışmak gerekir; $2^n$ ve $n!$ kabul edilemeyecek kadar yüksek büyüme oranlarıdır.

## 8. Döngülerin Büyüme Oranları

### 8.1 Tek Döngüler

Slayttaki üç örnek (ekrandan, 01:15:00):

```c
for(i=0; i<1000; i++)      // f(n)=n (Doğrusal)
for(i=0; i<1000; i+=2)     // f(n)=n/2 (Doğrusal)
for(i=1; i<=1000; i*=2)    // f(n)=log n (Logaritmik)
```

- `i++`: Döngü gövdesi 1000 kez, genel olarak $n$ kez çalışır. Doğrusal.
- `i+=2`: $i$ şu değerleri alır: $0, 2, 4, 6, \dots, 998$. Gövde 500 kez çalışır, yani $n/2$. Katsayı yarıya indi ama büyüme yine $n$ ile orantılıdır, bu yüzden doğrusal. `i+=3` olsaydı yaklaşık 333 kez, yani $n/3$ olurdu.
- `i*=2`: $i$ şu değerleri alır: $1, 2, 4, 8, 16, 32, 64, 128, 256, 512$. 1024, `i<=1000` koşulunu sağlamadığı için çalışmaz. 1000 boyutlu girdi için gövde yalnız 10 kez çalışır. Bu logaritmik büyümedir.

Döngünün 1'den başlatılmasının sebebi: 0 ile başlasaydı çarpma hep 0 verir ve döngü sonsuz olurdu.

> **Hocanın vurgusu:** Bu derste geçen bütün logaritmalar 2 tabanındadır. Taban çoğunlukla yazılmaz; $\log n$ ya da $\lg n$ yazılınca $\log_2 n$ kastedilir.

> **Ders sonrası not:** Hoca bir yerde "10 tabanında, yani iki tabanında" dedi; kastedilen 2 tabanıdır.

### 8.2 İç İçe Döngüler

Slayttaki üç örnek (ekrandan, 01:20:00):

```c
for(i=0; i<1000; i++)
    for(j=0; j<1000; j++)      // f(n)=n^2 (Quadratik)

for(i=0; i<1000; i++)
    for(j=0; j<i; j++)         // f(n)=n((n+1)/2) (Bağımlı Quadratik)

for(i=0; i<1000; i++)
    for(j=1; j<=1000; j*=2)    // f(n)=n logN (Doğrusal Logaritmik)
```

- **Bağımsız iki döngü:** Dış döngü 1000, iç döngü her seferinde 1000 kez döner: $1000 \times 1000$, yani $n \cdot n = n^2$. Buna karesel ya da kuadratik büyüme denir.
- **Bağımlı iç döngü:** İç döngünün bitiş şartı dış sayaca bağlanınca iç döngü önce 0, sonra 1, 2, ... kez döner. Hoca bunu bir üçgen çizerek gösterdi. Ortalama tekrar yaklaşık $(n+1)/2$, yani kabaca 500'dür; toplam $n(n+1)/2 = (n^2 + n)/2$, yani yaklaşık 500.000 işlem. Hâlâ $n^2$ mertebesindedir ama $1/2$ katsayısıyla daha yavaş büyür. Buna bağımlı kuadratik denir.
- **İçte çarparak ilerleyen döngü:** Dış döngü $n$ kez, iç döngü $\log n$ kez (1, 2, 4, ..., 512: 10 adım) döner. Toplam $n \log n$. $n^2$ eğrisi biraz "yatırılmış" olur.

> **Ders sonrası not:** `for(j=0; j<i; j++)` döngüsünde $i = 0, \dots, n-1$ için iç döngü toplam tam olarak $n(n-1)/2$ kez çalışır ($n = 1000$ için 499.500). Slayttaki $n(n+1)/2$ değeri iç döngü `j<=i` olsaydı doğru olurdu. Sonuç iki durumda da $O(n^2)$'dir.

Bu noktada hoca şunu özetledi: her adımın bir maliyeti vardır, çalışma zamanı atılan bütün adımların toplamıdır ve bu toplam girdi boyutuyla orantılı olarak büyür.

## 9. Büyük O Gösterimi

Büyüme oranı fonksiyonu bu bölümde $g(n)$ ile gösterildi. Bir algoritmanın büyüme oranı $g(n)$ ise, yani $g(n)$ ile doğru orantılı zaman gerektiriyorsa, algoritma $g(n)$ seviyesinde (mertebesinde) bir çözümdür ve karmaşıklığı $O(g(n))$ diye gösterilir. Buradaki $O$ sıfır değil, büyük O harfidir. Bu gösterime **büyük O gösterimi** (Big O notation) denir.

- A algoritmasının zamanı $n^2$ ile orantılıysa (örneğin $n^2 + n + \dots$), karmaşıklığı $O(n^2)$'dir.
- B algoritmasının zamanı $n$ ile orantılıysa, karmaşıklığı $O(n)$'dir.

### 9.1 Büyüme Oranı Fonksiyonlarının Anlamı

Slayttaki tanımlar (ekrandan, 01:35:00):

- $O(1)$: Zaman gereksinimi sabittir ve problem boyutundan bağımsızdır.
- $O(\log_2 n)$: Logaritmik algoritmaların zaman gereksinimi, boyut artışından daha yavaş artar.
- $O(n)$: Doğrusal algoritmanın zaman gereksinimi, boyut artışına paralel artar.
- $O(n \log_2 n)$: Zaman gereksinimi doğrusal algoritmadan çok daha hızlı artar.
- $O(n^2)$: İkinci dereceden bir algoritmanın zaman gereksinimi, problem boyutuna göre süratle artar.
- $O(n^3)$: Üçüncü dereceden bir algoritmanın zaman gereksinimi, ikinci dereceden bir algoritmanınkinden çok daha yüksek süratle artar.
- $O(2^n)$: Üssel bir algoritmanın zaman gereksinimi, algoritmanın kullanışlı olmasının önüne geçecek şekilde aşırı yüksek süratle artar.

$O(1)$ için hoca şu örnekleri verdi: ne gelirse gelsin hep aynı sonucu döndüren, herkese "evet" diyen ya da verilen bir sayıyı 5 ile çarpıp söyleyen bir algoritma. $n$'ye bağlı döngü yoktur, hep sabit sayıda işlem yapılır. Her zaman $O(1)$ algoritma bulmak çok zordur; ama algoritmanın alt parçalarında bu tür işlemler kullanmak genel karmaşıklığı azaltabilir.

### 9.2 Birden Fazla Girdi Boyutu

Bir öğrenci sohbetten $n \cdot m^2$ gibi ifadelerin mümkün olup olmadığını sordu.

**Soru:** $n \cdot m^2$ gibi bir karmaşıklık söz konusu olabilir mi?

**Cevap:** Evet. $n$ ve $m$ boyutunda iki ayrı dizi girdisi alınıyorsa karmaşıklık iki girdi cinsinden yazılır: örneğin $O(n \log n \cdot m^2)$ ya da $O(m \log n)$. Hoca ileride çizgelerle (graf) çalışırken boyutun düğüm (vertex) ve kenar (edge) sayılarıyla ifade edileceğini, örneğin $V \log E$ gibi ifadeler kullanılacağını söyledi. Ama genellikle tek bir dizi sıralandığı ya da arandığı için girdi boyutu $n$ olur.

### 9.3 Sayısal Karşılaştırma

Hoca $n = 10.000$ için büyüme oranlarının kaba karşılığını verdi:

| Büyüme | Yineleme sayısı | Tahmini süre |
|---|---|---|
| $\log n$ | yaklaşık 13 | mikrosaniyeler |
| $n$ | 10.000 | saniyeler |
| $n \log n$ | yaklaşık 140.000 | saniyeler |
| $n^2$ | $10^8$ | dakikalar |
| $n^k$ ($k > 2$) | milyarlar, trilyonlar | saatler |
| $2^n$ | $2^{10.000}$ | "felaket" |
| $n!$ | $10.000!$ | "ölümcül" |

<!-- BELİRSİZ: Bu tablonun (N=10.000 için yineleme ve süre) karesi okunmadı; değerler hocanın sözlü anlatımından alındı. -->

Hoca faktöriyel için "bizi ve çocuklarımızı gömer, sonucu üçüncü kuşak alır" dedi.

Ardından kitaptan alınmış bir tablo gösterildi (ekrandan, 01:40:00):

| Fonksiyon | 10 | 100 | 1.000 | 10.000 | 100.000 | 1.000.000 |
|---|---|---|---|---|---|---|
| $1$ | 1 | 1 | 1 | 1 | 1 | 1 |
| $\log_2 n$ | 3 | 6 | 9 | 13 | 16 | 19 |
| $n$ | 10 | $10^2$ | $10^3$ | $10^4$ | $10^5$ | $10^6$ |
| $n \log_2 n$ | 30 | 664 | 9.965 | $10^5$ | $10^6$ | $10^7$ |
| $n^2$ | $10^2$ | $10^4$ | $10^6$ | $10^8$ | $10^{10}$ | $10^{12}$ |
| $n^3$ | $10^3$ | $10^6$ | $10^9$ | $10^{12}$ | $10^{15}$ | $10^{18}$ |
| $2^n$ | $10^3$ | $10^{30}$ | $10^{301}$ | $10^{3.010}$ | $10^{30.103}$ | $10^{301.030}$ |

Hoca 1 milyon girdi için $\log n$'nin yalnız 19 işlem gerektirdiğini, $2^n$'nin ise $10^{301.030}$ işlem gerektirdiğini vurguladı. Tabloya $n!$ satırı konmamıştır.

> **Ders sonrası not:** Hoca $10^{18}$ için "$10^{10}$ Google sayısı mıydı, onun neredeyse iki katı" dedi. Kastedilen büyük olasılıkla googol sayısıdır; googol $10^{100}$'dür ve $10^{18}$ bundan çok küçüktür.

## 10. Algoritma Seviyesi: O, Omega ve Teta

### 10.1 Büyük O'nun Tanımı ve Örnek

Bir algoritmanın maliyet fonksiyonu $f(n) = n^2 - 3n + 10$ olsun. Her $n \ge n_0$ için

$$k \cdot n^2 \ge n^2 - 3n + 10$$

olacak şekilde $k$ ve $n_0$ sabitleri bulunabiliyorsa algoritma $n^2$ seviyesindedir. Hoca $k = 3$ ve $n_0 = 2$ seçti: $n \ge 2$ olan her $n$ için $3n^2 \ge n^2 - 3n + 10$ olduğu garanti edilir.

Slayttaki grafikte (ekrandan, 01:45:00) $3n^2$ eğrisi $n^2 - 3n + 10$ eğrisini 1 ile 2 arasında bir yerde keser; hoca bu kesişimi daire içine aldı ve $n_0 = 2$'nin altını çizdi. $n_0$'dan sonra $3n^2$ eğrisi hep üstte kalır, yani üst sınırdır. $n$'nin 1 ya da 2 gibi çok küçük değerleri göz ardı edilir. Böylece gerçek maliyet $n^2 - 3n + 10$ olsa da algoritmanın karmaşıklığı sadeleştirilmiş biçimde $O(n^2)$ diye yazılır.

> **Ek bilgi (derste anlatılmadı):** $3n^2 \ge n^2 - 3n + 10$ eşitsizliği $2n^2 + 3n - 10 \ge 0$ demektir. Pozitif kök $(-3 + \sqrt{89})/4 \approx 1{,}61$ olduğundan eşitsizlik her $n \ge 2$ için sağlanır.

### 10.2 Omega ve Teta

- **Büyük Omega:** $n \ge n_0$ boyutundaki problemi çözmek için en az $k \cdot g(n)$ birim zaman gerekecek şekilde $k$ ve $n_0$ bulunabiliyorsa algoritma $\Omega(g(n))$ seviyesindedir: $f(n) \ge k \cdot g(n)$. "İnebileceğim en alt seviye budur" demektir.
- **Büyük Teta:** En az $k_1 g(n)$, en fazla $k_2 g(n)$ birim zaman gerekecek şekilde $k_1$, $k_2$ ve $n_0$ bulunabiliyorsa algoritma $\Theta(g(n))$ seviyesindedir. "En fazla bu kadar, en az bu kadar, ben aradayım" demektir.

Slayttaki üç grafik (ekrandan, 01:50:00):

- (a) $f(n) = \Theta(g(n))$: $n_0$'dan sonra $f(n)$, $c_1 g(n)$ ile $c_2 g(n)$ arasında kalır.
- (b) $f(n) = O(g(n))$: $n_0$'dan sonra $f(n)$, $c\,g(n)$'nin altında kalır.
- (c) $f(n) = \Omega(g(n))$: $n_0$'dan sonra $f(n)$, $c\,g(n)$'nin üstünde kalır.

Slayttaki özet: $O$ fonksiyonu üstten, $\Omega$ alttan bağlarken $\Theta$ hem alttan hem üstten bağlar. Başka açıdan, $\Theta(n)$ için $O(n) \ge f(n) \ge \Omega(n)$ olur. $\ge$ yerine $>$ konursa sırasıyla küçük $o$ ve küçük $\omega$ gösterimleri elde edilir.

Hoca $n_0$'dan önce fonksiyonun dalgalı bir seyir izleyebileceğini, daha hızlı ya da yavaş çalışabileceğini; önemli olanın $n_0$'dan sonraki davranış olduğunu söyledi. Hoca büyük O'yu en kötü durumla, büyük Omega'yı en iyi durumla, büyük Teta'yı ortalama durumla eşleştirdi.

> **Hocanın vurgusu:** Bu derste üç ayrı analiz yerine yalnız en kötü duruma, yani büyük O'ya odaklanılacaktır. "Olası en kötü durumda karmaşıklığım en fazla şu kadardır" demek yeterli olacaktır.

> **Ders sonrası not:** Hoca $\Theta$'yı "ortalama durum karmaşıklığı" diye adlandırdı. $\Theta$ büyük olasılıkla daha doğru biçimde "sıkı sınır" olarak düşünülmelidir: bir fonksiyonu hem alttan hem üstten aynı mertebede sınırlar. En kötü, en iyi ve ortalama durum ise ayrı kavramlardır; her birinin süresi $O$, $\Omega$ ya da $\Theta$ ile ifade edilebilir.

## 11. Büyük O'nun Özellikleri ve Örnekler

### 11.1 Özellikler

Slayttaki özellikler (ekrandan, 01:55:00):

1. **Düşük seviyeli terimler göz ardı edilebilir.** Bir algoritma $O(n^3 + 4n^2 + 3n)$ ise aynı zamanda $O(n^3)$'tür. Büyüme oranı fonksiyonu olarak sadece en yüksek seviyeli terim kullanılır.
2. **Sabit bir çarpan göz ardı edilebilir.** Bir algoritma $O(5n^3)$ ise aynı zamanda $O(n^3)$'tür.
3. **Büyüme oranı fonksiyonları birleştirilebilir.** $O(f(n)) + O(g(n)) = O(f(n) + g(n))$. Bir algoritma $O(n^3) + O(4n^2)$ ise aynı zamanda $O(n^3 + 4n^2)$ olur, bu da $O(n^3)$'tür. Çarpma için de aynı kural geçerlidir.

Hoca bunu şöyle açıkladı: zaten $n^3$'e çıkılmışsa, 10 eleman için 1000 işlemin yanında 400 işlemin "lafı mı olur". Farklı boyutlu iki girdi varsa ikisi birlikte yazılabilir, örneğin $O(n^3 m^2)$.

### 11.2 Örnek 1: Basit Döngü

Bölüm 5.3'teki maliyet:

$$T(n) = c_1 + c_2 + (n+1)c_3 + n c_4 + n c_5 = (c_3 + c_4 + c_5)\,n + (c_1 + c_2 + c_3) = an + b$$

Sabit terim $b$ atılır, kalan $an$'deki katsayı $a$ da atılır. En yüksek mertebeli terim $n$'dir. Karmaşıklık $O(n)$'dir: 10 girdi 10 kat, 100 girdi 100 kat çalışma.

### 11.3 Örnek 2: İç İçe Döngü

Bölüm 5.4'teki maliyet:

$$T(n) = (c_5 + c_6 + c_7)\,n^2 + (c_3 + c_4 + c_5 + c_8)\,n + (c_1 + c_2 + c_3) = an^2 + bn + c$$

Önce sabit atılır, $n^2$ varken $n$ terimi de atılır, son olarak katsayı atılır. Karmaşıklık $O(n^2)$'dir. Hoca "$n^2$'nin yanında $n$'nin esamesi okunmaz" dedi.

### 11.4 Örnek 3: Üç Bağımlı İç İçe Döngü

Hocanın anlattığı örnek:

```text
for i = 1 to n
    for j = 1 to i
        for k = 1 to j
            x = x + 1
```

İç döngüler dış sayaçlara bağlıdır ve içte tek bir sabit maliyetli atama vardır. Hoca toplamı kabaca $n \cdot \frac{n}{2} \cdot \frac{n}{4} = \frac{n^3}{8}$ diye hesapladı. Katsayılar büyük O'da önemli olmadığı için karmaşıklık $O(n^3)$'tür: $n^3$'ten 8 kat az işlem yapılsa da mertebe $n^3$'tür.

<!-- BELİRSİZ: Bu örneğin slaytının karesi okunmadı; kod altyazıdan kuruldu. -->

> **Ders sonrası not:** Bu üçlü döngüde iç atamanın tam çalışma sayısı $\sum_{i=1}^{n}\sum_{j=1}^{i} j = \frac{n(n+1)(n+2)}{6}$'dır, yani yaklaşık $n^3/6$ (python ile $n = 100$ için 171.700 bulundu; $n^3/8$ ise 125.000 verir). Hocanın $n^3/8$ değeri kaba bir tahmindir; sonuç olan $O(n^3)$ değişmez.

## 12. Özyinelemeli Algoritmalarda Büyük O: Fibonacci

### 12.1 Yineleme Denklemi

Düz akışlarda her maliyet kalemi sayılır; iç içe yapılarda çarpılır ve en yüksek mertebe alınır. Özyinelemeli (rekürsif) algoritmalarda bu kadar kolay değildir, çünkü fonksiyon belirli bir şarta kadar kendini tekrar tekrar çağırır. Her adım bir önceki adıma bağlıdır. Bu yüzden çalışma zamanı fonksiyonu $T(n)$ kendisi cinsinden yazılmak zorundadır.

Slayttaki tanım (ekrandan, 02:15:00): Özyineli fonksiyonların zaman karmaşıklık fonksiyonu $T(n)$, kendisi cinsinden ifade edilir ve $T(n)$ yineleme denklemi (recurrence equation) olarak adlandırılır. Özyineli bir fonksiyonun büyüme oranı fonksiyonunu çözebilmek için yineleme ilişkisini çözmek gerekir.

### 12.2 Fibonacci Kodu

Slayttaki örnek (ekrandan, 02:15:00):

```c
int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n - 1) + fib(n - 2);
}
```

Fibonacci dizisinde her sayı kendinden önceki iki sayının toplamıdır: $0, 1, 1, 2, 3, 5, 8, 13, 21, 34, \dots$ Hoca dizinin 0'dan ya da 1'den başlatılabileceğini, farkın önemli olmadığını söyledi. Özyineleme $n \le 1$ olduğunda kesilir ve $n$ döndürülür. $n = 4$ için önce `fib(3) + fib(2)` çağrılır; `fib(3)` kendi içinde `fib(2) + fib(1)` çağırır ve bu, tabana inene kadar sürer. Sonra sonuçlar geriye doğru toplanır.

> **Ek bilgi (derste anlatılmadı):** Slayttaki kod `fib(0)` ... `fib(10)` için `0 1 1 2 3 5 8 13 21 34 55` verir (gcc ile derlenip çalıştırıldı).

### 12.3 Yineleme Denkleminin Çözümü

$n = 0$ ve $n = 1$ için yalnız `return n` çalışır; maliyetler sabittir: $T(0) = c_1$, $T(1) = c_2$. $n > 1$ için iki özyinelemeli çağrı ve sabit iş vardır:

$$T(n) = T(n-1) + T(n-2) + c$$

Bu denklemi çözmek için bir kabul yapılır: $T(n-1) \ge T(n-2)$ olduğundan $T(n-1) \approx T(n-2)$ alınabilir. $T(n-2)$ yerine $T(n-1)$ yazmak üstten sınırlamadır, yani "bundan kötü olamaz" demektir. Slayttaki çözüm (ekrandan, 02:25:00):

$$\begin{aligned}
T(n) &= T(n-1) + T(n-2) + c \\
     &= 2T(n-1) + c \qquad \text{// } T(n-1) \sim T(n-2) \text{ yaklaşımı ile} \\
     &= 2\,(2T(n-2) + c) + c \\
     &= 4T(n-2) + 3c \\
     &= 8T(n-3) + 7c \\
     &= 2^k \, T(n-k) + (2^k - 1)\,c
\end{aligned}$$

Hoca deseni şöyle gösterdi: $n-1$'de 2 ile çarpılıp $c$ eklenir, $n-2$'de 4 ile çarpılıp $3c$, $n-3$'te 8 ile çarpılıp $7c$ eklenir. $n-k = 0$, yani $k = n$ alınınca:

$$T(n) = 2^n \, T(0) + (2^n - 1)\,c = 2^n (1 + c) - c$$

$$T(n) \sim 2^n \quad \Rightarrow \quad O(2^n)$$

Sabitler atılınca algoritmanın büyüme oranı fonksiyonu $O(2^n)$ olur. Hoca bunu denemenizi önerdi: kodu yazıp 1'den yukarı doğru her $n$ için süreyi `time` fonksiyonuyla yazdırırsanız, $n$ arttıkça sürenin hızla patladığını görürsünüz.

> **Ders sonrası not:** Slayttaki son satırda $T(0) = 1$ alınmıştır. Hoca $T(0)$'ı sabit bir $c_1$ olarak andı; hangi sabit alınırsa alınsın sonuç $O(2^n)$'dir. Hoca bir yerde sabit sayısını "$2^{k-1}$ tane" diye söyledi; slayttaki doğru ifade $(2^k - 1)c$'dir.

### 12.4 Çağrı Ağacı

Slayttaki ağaç (ekrandan, 02:30:00) `fib(6)` çağrısının dallanmasını gösterir. Ağacın yapısı şöyledir:

```text
fib(6)
├── fib(4)
│   ├── fib(2) -> 1
│   └── fib(3)
│       ├── fib(1) -> 0
│       └── fib(2) -> 1
└── fib(5)
    ├── fib(3)
    │   ├── fib(1) -> 0
    │   └── fib(2) -> 1
    └── fib(4)
        ├── fib(2) -> 1
        └── fib(3)
            ├── fib(1) -> 0
            └── fib(2) -> 1
```

Hoca kesikli çizgiyle gösterilen gezintiyi adım adım izledi: önce sol alt ağaç (`fib(4)`) tamamen hesaplanır, sonuçlar toplanarak yukarı çıkılır, sonra sağ alt ağaca (`fib(5)`) geçilir. `fib(5)` içinde `fib(3)` ve `fib(4)` daha önce hesaplanmış olsa da maalesef yeniden hesaplanır. Toplam 15 çağrı yapılır:

- `fib(2)` 5 kez,
- `fib(3)` 3 kez,
- `fib(1)` 3 kez,
- `fib(4)` 2 kez hesaplanır.

Aynı hesabın tekrar tekrar yapılması ve çağrı derinliği yüzünden karmaşıklık $2^n$ mertebesine çıkar. Hoca bu ağacın, yineleme denklemini açmadan karmaşıklığı seviye seviye görmenin daha görsel bir yolu olduğunu söyledi.

> **Ders sonrası not:** Slayttaki ağaçta `fib(2)` yaprak olarak 1, `fib(1)` yaprak olarak 0 değerini alır; bu, diziyi 1'den başlatan ($F_1 = 0$, $F_2 = 1$) bir gösterimdir. Slayttaki koda (`n <= 1` ise `n` döndür) birebir uyulsaydı `fib(2)` da `fib(1)` ve `fib(0)`'ı çağırır ve `fib(6)` için toplam 25 çağrı olurdu (python ile sayıldı). İki durumda da büyüme üsteldir.

### 12.5 Yinelemeli Çözüm

Yazması çok kolay, iki satırlık bu özyinelemeli çözüm $O(2^n)$ olduğu için karşılaştırma tablosuna göre felaket bir yöntemdir. Bir öğrencinin önerisi üzerine hoca doğru yolu anlattı: önceki iki değer bir yerde tutulursa her yeni değer tek bir toplamayla bulunur.

```text
1 1 2
  1 2 3
    2 3 5
      3 5 8
        5 8 13
          8 13 21
            13 21 34
               21 34 55
```

Her adımda üç değerlik bir pencere tutulur ve kaydırılır: bir toplama ve iki atama, yani sabit sayıda işlem. Bu adım $n$ kez tekrarlanır. Katsayılar atılınca karmaşıklık $O(n)$ olur. $O(n)$'de çözmek varken $O(2^n)$'de çözmek için bir sebep yoktur; özyinelemeli yazmak zorunluysa $O(2^n)$ maliyetine katlanmak gerekir.

**Soru:** Bu problem dinamik programlama ile mi çözülüyor?

**Cevap:** Hoca dinamik programlamanın algoritma analizi dersinde görüleceğini, hepsinin bir döneme yetişmediğini söyledi.

**Soru:** Özyinelemeli çözümde daha önce hesaplanan değerler bir dizide tutulup çağrıdan önce `if` ile kontrol edilirse karmaşıklık ne olur?

**Cevap:** Hoca, öğrencinin yineleme bağıntısının nasıl çözüleceğini artık bildiğini, önceki adımdaki çalışma süresini yazarak bunu kendisinin hesaplamasını istedi. Ders sonunda soru yeniden sorulduğunda hoca bunun dinamik programlama alanına girdiğini, şimdilik oraya girmek istemediği için örneği bu şekilde vermediğini söyledi ve yine yineleme bağıntısını yazarak denemeyi önerdi.

> **Ek bilgi (derste anlatılmadı):** Hesaplanan değerleri bir dizide saklayıp tekrar hesaplamamaya "memoization" denir. Bu yöntemle her `fib(k)` bir kez hesaplandığı için özyinelemeli Fibonacci büyük olasılıkla $O(n)$ zamana iner; karşılığında $O(n)$ ek bellek kullanılır.

## 13. En Kötü, En İyi ve Ortalama Durum Analizi

Slayttaki özet (ekrandan, 02:40:00): Bir algoritma aynı boyuttaki farklı sorunları çözmek için farklı sürelere gereksinim duyabilir. Örneğin $n$ elemanlı bir dizide sıradan arama yapmanın maliyeti $1, 2, \dots, n$ olabilir.

- **En kötü durum (worst-case) analizi:** Algoritmanın $n$ boyutundaki problemi çözmesi için gereken azami süre. Algoritma karmaşıklığı için üst sınır verir. Genel olarak algoritmaların en kötü durum davranışı incelenir.
- **En iyi durum (best-case) analizi:** Algoritmanın $n$ boyutundaki problemi çözmesi için gereken asgari süre. Çok kullanışlı değildir.
- **Ortalama durum (average-case) analizi:** Algoritmanın $n$ boyutundaki problemi çözmesi için gereken ortalama süre. Çoğunlukla belirlenmesi zordur. Olası veri durumu değerlendirilip dağılımına bakılır. En kötü durum analizi, ortalama durum analizinden daha çok kullanılır.

Hoca en kötü durum için eklemeli sıralamayı (insertion sort) örnek verdi: büyükten küçüğe sıralı (ters sıralı) bir dizi küçükten büyüğe sıralanmak istenirse olabilecek her karşılaştırma ve yer değiştirme yapılır; bu yüzden insertion sort'un karmaşıklığı $n^2$'dir. En iyi durumda dizi zaten sıralıdır ve algoritma hiçbir yer değiştirme yapmadan geçer. Ortalama durum için verilerin genellikle nasıl geldiğine (çoğunlukla sıralı mı, ters sıralı mı) bakılır.

> **Ders sonrası not:** Hoca sıralı dizide insertion sort'un en iyi durumu için "$O(1)$ diyebilirsiniz" dedi. Algoritma hiç yer değiştirme yapmasa da her elemanı bir kez karşılaştırmak zorunda olduğundan en iyi durum büyük olasılıkla $O(n)$'dir.

## 14. Sıralı Arama ve İkili Arama

### 14.1 Sıralı Arama

$n$ elemanlı bir dizide bir değer aranır ve ilk bulunan yerde çıkılır. İlk akla gelen temel (baseline) çözüm elemanlara sırayla bakmaktır. Slayttaki kod (ekrandan, 02:45:00):

```c
int sequentialSearch(int a[], int size, int x) {
   int i;

   for (i=0; i<size && a[i]!=x; i++);

   if (i==size)
      return -1;

   return i;
}
```

`for` döngüsü iki şartı birlikte denetler ve gövdesi boştur: eleman bulunana ya da dizi bitene kadar $i$ artırılır. $i$ dizi boyutuna ulaştıysa eleman yoktur ve $-1$ döner; değilse bulunduğu konum döner.

**Örnek (ekrandan, 02:45:00):** Dizi `1 1 2 3 5 8 13 21 34`, aranan $x = 25$.

- Her adımda eleman 25 ile karşılaştırılır: 1, 1, 2, 3, 5, 8, 13, 21, 34. Hiçbiri eşit değildir.
- $i$ = `size` olunca döngüden çıkılır ve $-1$ döner.
- Bulunamadığı hâlde 9 kez ilerlenmiştir; $n = 9$. Yani $n$ tane (sabitlerle $n+1$) işlem yapılmıştır.

$x = 1$ aranırsa ilk adımda bulunur ve çıkılır: en iyi durum.

Slayttaki özet:

- Bulunamazsa $O(n)$.
- Bulunursa en iyi durum: aranan değer ilk eleman, $O(1)$.
- En kötü durum: aranan değer son elemandır, $O(n)$.
- Ortalama durum: karşılaştırma sayısı $1, 2, \dots, n$ olabilir; $\left(\sum_{i=1}^{n} i\right)/n$, yani $O(n)$.

> **Ders sonrası not:** Slaytta ortalama için $\left(\sum_{i=1}^{n} n\right)/n$ yazılıdır; kastedilen büyük olasılıkla $\left(\sum_{i=1}^{n} i\right)/n = (n+1)/2$'dir. Sonuç yine $O(n)$'dir.

Hoca 80 milyonluk sıralı bir kimlik numarası listesinde arama örneğini verdi: sıralı aramada 80 milyon karşılaştırma gerekebilir. Dizi sıralıysa bu çok iyileştirilebilir.

### 14.2 İkili Arama

Dizi sıralıysa her karşılaştırmada arama uzayı yarıya indirilebilir. Slayttaki özet (ekrandan, 02:50:00):

- Dizi sıralı ise ikili arama kullanılabilir.
- Aranılan eleman dizide yoksa döngü içerisindeki yineleme sayısı $\lfloor \log_2 n \rfloor + 1$, yani $O(\log_2 n)$.
- Başarılı aramada en iyi durum: aranan değer dizinin bakılan ilk elemanıdır, $O(1)$.
- En kötü durum: aranan değer son bakılacak konumdadır, $\lfloor \log_2 n \rfloor + 1$, yani $O(\log_2 n)$.
- Ortalama durum: karşılaştırma sayısı $< \log_2 n$, yani $O(\log_2 n)$.

**Örnek 1 (ekrandan, 02:50:00):** Aynı dizide `1 1 2 3 5 8 13 21 34`, $x = 25$.

- Ortadaki (5.) eleman 5'tir. 25 > 5 olduğu için sol taraftaki 5 elemana hiç bakılmaz; dizinin yarısı atılır.
- Kalan `8 13 21 34`'ün ortası (alta yuvarlayınca) 13'tür. 25 > 13, bu taraf da atılır.
- Sonra 21'e, sonra 34'e bakılır; eşleşme yoktur.
- Toplam 4 karşılaştırmayla "yok" denir.

**Örnek 2:** Aynı dizide $x = 1$.

- Ortadaki 5 > 1 olduğu için sağ taraf atılır; 4 elemanlık karşılaştırmadan kâr edilir.
- Hoca kalan `1 1 2 3` içinde 2'ye baktı; 2 > 1 olduğu için 3'e bakma ihtiyacı kalktı.
- Kalan iki elemandan 1'e baktı ve buldu.
- 3 karşılaştırmayla, 6 değere hiç dokunmadan bulundu.

> **Ders sonrası not:** Slayttaki `binarySearch` koduyla (`mid = (low + high)/2`, alta yuvarlama) ikinci adımda `low = 0`, `high = 3` için `mid = 1` olur ve `a[1] = 1` hemen bulunur; yani kod 2 karşılaştırmada sonuç verir. Hocanın elle seçtiği orta eleman (2) üst ortadır. Bu fark sonucu, yani $O(\log n)$'yi değiştirmez (kod gcc ile derlenip bu girdiyle denendi).

En iyi durumda (örneğin 5 aranırken) ilk bakılan orta eleman aranan değerdir: $O(1)$. En kötü durumda son bakılan konumda bulunur ya da hiç bulunamaz: $\lfloor \log_2 n \rfloor + 1$ karşılaştırma, yani $O(\log n)$.

**Örnek 3: Ortalama yineleme sayısı (ekrandan, 02:50:00).** 7 elemanlı bir dizi (indisler 0-6) için her konumdaki elemanı bulmak için gereken yineleme sayısı:

| İndis | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|---|
| Yineleme sayısı | 3 | 2 | 3 | 1 | 3 | 2 | 3 |

- 3. indisteki eleman ilk bakışta bulunur (1 yineleme).
- 1. ve 5. indisler ikinci bakışta bulunur (2 yineleme).
- Diğerleri üçüncü bakışta bulunur (3 yineleme).
- Toplam $3 + 2 + 3 + 1 + 3 + 2 + 3 = 17$; ortalama $17/7 = 2{,}4285 < \log_2 7$.

En kötü durumda üst sınır $\log_2 n$ mertebesidir; eleman bulunamazsa bile dördüncü karşılaştırmayla iş biter. Kod ile bu değerler yeniden üretildi (gcc ile derlenip çalıştırıldı; toplam 17).

### 14.3 O(log N) Performansı

Slayttaki tablo (ekrandan, 02:55:00):

| $n$ | $O(\log_2 n)$ |
|---|---|
| 16 | 4 |
| 64 | 6 |
| 256 | 8 |
| 1.024 | 10 |
| 16.384 | 14 |
| 131.072 | 17 |
| 262.144 | 18 |
| 524.288 | 19 |
| 1.048.576 | 20 |
| 1.073.741.824 | 30 |

Girdi 4 katına çıktığında karşılaştırma sayısı yalnız 2 artar. Hoca öğrencilere 80 milyon kayıt için kaç karşılaştırma gerektiğini sordu ve birlikte yaklaşık 27 sonucuna ulaşıldı. Yani sıralı 80 milyon kimlik numarası içinde aranan değer yaklaşık 27 karşılaştırmayla bulunur ya da bulunamaz.

> **Ders sonrası not:** Hoca "1 milyon sayıda sadece 30 karşılaştırma" dedi; tabloya göre yaklaşık 1 milyon ($2^{20}$) için 20, yaklaşık 1 milyar ($2^{30}$) için 30 karşılaştırma gerekir. 80 milyon için $\log_2(8 \times 10^7) \approx 26{,}25$, yani $\lfloor 26{,}25 \rfloor + 1 = 27$ (python ile doğrulandı).

### 14.4 Binary Search Kodu

Hoca algoritmayı öğrencilerin kendisinin tasarlamasını isteyip yalnız kodu paylaştı (ekrandan, 03:00:00):

```c
int binarySearch(int a[], int size, int x) {
   int low =0;
   int high = size -1;
   int mid; // aranan değer bulunursa mid konumu tutar.

   while (low <= high) {
    mid = (low + high)/2;

    if (a[mid] < x)
       low = mid + 1;
    else if (a[mid] > x)
       high = mid - 1;
    else
        return mid;
   }
   return -1;
}
```

`low` ve `high` arama aralığının alt ve üst sınırlarıdır; başta `0` ve `size - 1`'dir. `mid` her turda aralığın ortasıdır. Aranan değer ortadakinden büyükse alt sınır `mid + 1`'e, küçükse üst sınır `mid - 1`'e taşınır; eşitse `mid` döner. Her turda aralığın ikiye bölünmesi $\log n$'yi yaratan kısımdır.

**Soru:** Eleman dizide yoksa `while` döngüsünden çıkılamaz mı?

**Cevap:** Çıkılır. Bölündükçe `low` ve `high` birbirine yaklaşır ve sonunda `low <= high` şartı bozulur. Bu, bakılacak parça kalmadığı, yani elemanın bulunamadığı anlamına gelir ve `return -1` çalışır. Hoca kodu yazıp denemeyi önerdi.

## 15. Zaman ve Bellek Karmaşıklığı

Hoca bu hafta yalnız toplam çalışma sürelerinin karşılaştırıldığını hatırlattı. Karmaşıklık bellekte tutulması gereken yer açısından da değerlendirilebilir. Örneğin $n$ elemanlı bir dizi üzerinde çalışırken "var ya da yok" bilgisini tutan $n$ elemanlı yedek bir dizi kullanılıyorsa bellekte de $O(n)$'lik bir ek karmaşıklık yaratılmış olur.

**Soru:** Bu derste bellek karmaşıklığını da görecek miyiz?

**Cevap:** Evet, konuşulacak; ama genellikle karmaşıklıklar çalışma zamanı üzerinden ifade edilecek. Gerçek hayatta zaman ve uzay (bellek) karmaşıklığı birlikte değerlendirilir. Bazen $n^2$'lik bir algoritma, $n \log n$'lik bir algoritmaya tercih edilebilir; çünkü $n \log n$'lik olan belki $n^3$'lük yer kaplarken öbürü yalnız $n$'lik yer kaplar. Bellek ihtiyacı da büyük O ile gösterilebilir.

Hoca ilerleyen haftalarda bunun birleştirmeli sıralamada (merge sort) tartışılacağını söyledi: işler daha hızlı yapılabilir ama karşılığında bellekte $n$'lik ek yer harcanır. Bu ödünleşime **space-time trade-off** denir. Hangisinden ne kadar ödün verileceğine probleme, ortama ve duruma göre karar verilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): Aşağıdaki kod parçasının toplam maliyetini satır maliyetleri ve tekrar sayılarıyla yazın ve büyüme oranını belirleyin.

```c
i = 1;
sum = 0;
while (i <= n) {
        i = i + 1;
        sum = sum + i;
}
```

> **Çözüm:** Tekrar sayıları 1, 1, $n+1$, $n$, $n$'dir. Toplam maliyet $c_1 + c_2 + (n+1)c_3 + n c_4 + n c_5 = an + b$. Gereken süre $n$ ile doğru orantılıdır: $O(n)$.

**Soru 2** (ekrandan, 00:30:00): İç içe iki `while` döngüsünden oluşan Bölüm 5.4'teki kodun toplam maliyetini ve mertebesini bulun.

> **Çözüm:** Total Cost $= c_1 + c_2 + (n+1)c_3 + n c_4 + n(n+1)c_5 + n^2 c_6 + n^2 c_7 + n c_8 = an^2 + bn + c$. Düşük terimler ve katsayılar atılınca $O(n^2)$.

**Soru 3** (ekrandan, 01:15:00 ve 01:20:00): Aşağıdaki döngülerin büyüme oranlarını bulun: (a) `for(i=0; i<1000; i+=2)`, (b) `for(i=1; i<=1000; i*=2)`, (c) `for(i=0; i<1000; i++)` içinde `for(j=0; j<i; j++)`, (d) `for(i=0; i<1000; i++)` içinde `for(j=1; j<=1000; j*=2)`.

> **Çözüm:** (a) 500 tur, $f(n) = n/2$, doğrusal. (b) 10 tur ($1, 2, \dots, 512$), $f(n) = \log n$, logaritmik. (c) Bağımlı kuadratik, yaklaşık $n^2/2$ işlem, $O(n^2)$. (d) $n \cdot \log n$, doğrusal logaritmik.

**Soru 4** (ekrandan, 01:45:00): $f(n) = n^2 - 3n + 10$ fonksiyonunun $O(n^2)$ olduğunu $k$ ve $n_0$ sabitleri bularak gösterin.

> **Çözüm:** $k = 3$, $n_0 = 2$ seçilir. Her $n \ge 2$ için $3n^2 \ge n^2 - 3n + 10$ olur. Bu yüzden $f(n) = O(n^2)$.

**Soru 5** (derste sözlü, 02:12:44): `for i = 1 to n`, `for j = 1 to i`, `for k = 1 to j` içinde `x = x + 1` yapan üçlü döngünün büyük O karmaşıklığı nedir?

> **Çözüm:** Hoca toplamı kabaca $n^3/8$ diye verdi; tam değer $n(n+1)(n+2)/6$'dır. Her iki durumda da sonuç $O(n^3)$'tür.

**Soru 6** (ekrandan, 02:25:00): Özyinelemeli Fibonacci için $T(n) = T(n-1) + T(n-2) + c$ yineleme denklemini çözerek büyük O karmaşıklığını bulun.

> **Çözüm:** $T(n-1) \approx T(n-2)$ kabulüyle $T(n) = 2T(n-1) + c = 4T(n-2) + 3c = 8T(n-3) + 7c = 2^k T(n-k) + (2^k - 1)c$. $k = n$ için $T(n) = 2^n(1 + c) - c$, yani $O(2^n)$.

**Soru 7** (ekrandan, 02:30:00): `fib(6)` hesaplanırken toplam kaç çağrı yapılır ve `fib(2)` kaç kez hesaplanır?

> **Çözüm:** Slayttaki ağaca göre toplam 15 çağrı yapılır; `fib(2)` 5 kez, `fib(3)` 3 kez, `fib(1)` 3 kez, `fib(4)` 2 kez hesaplanır.

**Soru 8** (ekrandan, 02:45:00 ve 02:50:00): `1 1 2 3 5 8 13 21 34` dizisinde 25 değeri (a) sıralı aramayla, (b) ikili aramayla aranırsa kaç karşılaştırma yapılır?

> **Çözüm:** (a) Bütün 9 elemana bakılır, $-1$ döner. (b) Sırasıyla 5, 13, 21, 34 elemanlarına bakılır; 4 karşılaştırmada "yok" sonucu çıkar ($\lfloor \log_2 9 \rfloor + 1 = 4$).

**Soru 9** (ekrandan, 02:50:00): 7 elemanlı sıralı bir dizide ikili arama ile başarılı aramanın ortalama yineleme sayısı nedir?

> **Çözüm:** Konum başına yineleme sayıları `3 2 3 1 3 2 3`; toplam 17. Ortalama $17/7 \approx 2{,}43 < \log_2 7 \approx 2{,}81$.

**Soru 10** (derste sözlü, 02:54:39): Sıralı 80 milyon kimlik numarası içinde ikili aramayla bir numara aranırsa en kötü durumda yaklaşık kaç karşılaştırma gerekir?

> **Çözüm:** Derste yaklaşık 27 bulundu. $\log_2(8 \times 10^7) \approx 26{,}25$; $\lfloor 26{,}25 \rfloor + 1 = 27$.

## Dersin Toparlaması

Bu derste bir algoritmanın nasıl analiz edileceğinin temelleri işlendi. Empirik ölçümün algoritmayı değil gerçeklemeyi ölçtüğü, bu yüzden makineden, veriden ve dilden bağımsız teorik bir analize ihtiyaç olduğu gösterildi. Teorik analizde her işleme sabit bir maliyet verilir, satırların kaç kez çalıştığı sayılır ve toplam maliyet girdi boyutu $n$'nin fonksiyonu olarak yazılır. Bu fonksiyonun büyüme oranı algoritmaları karşılaştırmanın ölçütüdür: sabit, logaritmik, doğrusal ve doğrusal logaritmik iyi; kare ve küp giderek kötü; üstel ve faktöriyel kabul edilemezdir. Döngünün artım biçimi (toplayarak ya da çarparak) ve iç içe yapı büyüme oranını doğrudan belirler.

Büyük O gösterimi, $n_0$'dan sonra fonksiyonu üstten sınırlayan en yüksek mertebeyi verir. Düşük terimler ve katsayılar atılır. $\Omega$ alttan, $\Theta$ iki taraftan sınırlar; ama bu derste en kötü durum analizi, yani büyük O kullanılacaktır. Özyinelemeli algoritmalarda süre bir yineleme denklemiyle yazılır; özyinelemeli Fibonacci'nin $O(2^n)$, yinelemeli çözümün $O(n)$ olduğu görüldü. Son olarak sıralı aramanın $O(n)$, sıralı dizide ikili aramanın $O(\log n)$ olduğu gösterildi ve zaman ile bellek arasındaki ödünleşime (space-time trade-off) değinildi. Hoca bu ödünleşimin ilerleyen haftalarda merge sort ile yeniden tartışılacağını, dinamik programlamanın ise algoritma analizi dersinde görüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
