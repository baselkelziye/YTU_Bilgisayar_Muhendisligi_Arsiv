# Ders 25 Genişletilmiş Notu: P ve NP Problemleri, Deterministik Olmayan Algoritmalar, NP-Tam ve NP-Zor

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. P ve NP Kavramlarına Giriş
- 2. Efektif ve Efektif Olmayan Algoritmalar
- 3. Deterministik ve Deterministik Olmayan Algoritmalar
- 4. Deterministik Olmayan Algoritmanın Yapısı: Tahmin ve Doğrulama
- 5. Optimizasyon ve Karar Problemleri
- 6. P ve NP Sınıfları
- 7. NP-Tam ve NP-Zor Problemler
- Örnek Sorular
- Dersin Toparlaması

## 1. P ve NP Kavramlarına Giriş

Bu ders, dönemin son akademik konusudur. Hoca bu kez yeni bir algoritma anlatmayacağını, algoritma analizi yaparken bilinmesi gereken kavramlardan, yani polinomsal ve deterministik olmayan polinomsal algoritmalardan söz edeceğini belirtti.

Tahtaya "P, NP algorithm" yazıldı ve P'nin "polynomial" kısaltması olduğu gösterildi (ekrandan, 00:05:00). Hoca sınıfa NP'nin açılımını sordu; bir öğrenci "non-deterministic polynomial" diye cevap verdi. Hoca burada yaygın bir yanlışa dikkat çekti: NP çoğu zaman "non-polynomial" diye açılır, oysa doğrusu deterministik olmayan polinomsal (non-deterministic polynomial) algoritmadır.

> **Hocanın vurgusu:** NP, "non-polynomial" değil, "non-deterministic polynomial" demektir.

Dersin sorusu şudur: bir algoritma ne zaman polinomsal, ne zaman deterministik olmayan polinomsal olur; ve bir algoritmaya ne zaman "kullanılabilir, efektif" denir?

## 2. Efektif ve Efektif Olmayan Algoritmalar

### 2.1 Polinomsal zamanlı algoritmalar

Bir algoritmanın karmaşıklığı hesaplandığında $n$, $n^2$, $n^3$ ya da $n \log n$ gibi polinomsal bir ifade çıkıyorsa bu algoritma efektif bir algoritmadır. Bilinen örnekler merge sort, Huffman kodlama ve ikili aramadır (binary search).

Çalışma zamanı polinomsal olmayan algoritmalar ise efektif değildir (inefficient). $n!$, $2^n$, $3^n$ gibi üstel karmaşıklıklar bu gruptadır. Hoca iyi bilinen örnek olarak gezgin satıcı problemini (traveling salesman) ve bir önceki haftada backtracking ile görülen Hamilton devresini (Hamiltonian circuit) verdi. Bunlar polinomsal zamanda çözülemeyen problemlerdir.

### 2.2 Çalışma süresi tablosu

Üstel algoritmaların neden efektif sayılmadığını göstermek için hoca, aynı donanımda $n$, $n^2$, $n^3$ ve $2^n$ karmaşıklıklı dört algoritmanın $n = 10, 20, 50$ için ne kadar süreceğini gösteren bir tablo yazdı (ekrandan, 00:10:00). Süreler ölçülmüş değil hesaplanmıştır; bir değer bilinince diğerleri hesaplanabilir. Tahtadaki değerler şunlardır:

| Karmaşıklık | $n = 10$ | $n = 20$ | $n = 50$ |
|---|---|---|---|
| $n$ | 0,00001 s | 0,00002 s | 0,00005 s |
| $n^2$ | 0,0001 s | 0,0004 s | <!-- BELİRSİZ: karede yok --> |
| $n^3$ | 0,001 s | 0,008 s | <!-- BELİRSİZ: karede yok --> |
| $2^n$ | 0,001 s | 1,0 s | yaklaşık 35,7 yıl |

Tablodaki değerler her temel işlemin 1 mikrosaniye sürdüğü varsayımıyla tutarlıdır: $10 \cdot 10^{-6} = 0{,}00001$ s, $10^2 \cdot 10^{-6} = 0{,}0001$ s, $10^3 \cdot 10^{-6} = 0{,}001$ s, $2^{10} \cdot 10^{-6} = 0{,}001024 \approx 0{,}001$ s ve $2^{20} \cdot 10^{-6} = 1{,}048576 \approx 1{,}0$ s.

$n = 50$ sütununda $2^n$ değeri altyazıda "35,7" diye geçer. $2^{50} \cdot 10^{-6}$ s yaklaşık $1{,}126 \times 10^9$ s eder, bu da yaklaşık 35,7 yıldır (ara adım eklendi). Aynı varsayımla $n = 50$ için $n^2$ satırı $0{,}0025$ s, $n^3$ satırı $0{,}125$ s olur (ara adım eklendi). Polinomsal satırlar $n = 50$'de bile saniyenin altında kalır.

Hoca "daha da korkuncunu" göstermek için $n = 60$ durumunu da hesapladı ve bunun yüzyıllar sürdüğünü söyledi. $2^{60}$ μs büyük olasılıkla yaklaşık 365 yüzyıl eder (ara adım eklendi). <!-- BELİRSİZ: n=60 değeri karede görünmüyor, altyazıda yalnız "yüzyıl" geçiyor -->

Bu tablonun söylediği şudur: bütün durumları deneyen üstel bir algoritma $n = 10$ ya da $20$ için sorunsuz çalışır, ama $n$ biraz büyüyünce, $50$ gibi küçük bir değerde bile, makul bir sürede bitmez.

### 2.3 Tractable ve intractable problemler

Polinomsal zamanda çözülebilen problemlere **tractable** (gerçekte çözülebilir) problemler denir. Polinomsal zamanda çözülemeyen problemlere ise **intractable** (ya da çözülemez) problemler denir, çünkü $n$ büyüdükçe çözüme erişmek mümkün olmaz. Tahtada bu kısım "Intractable problems: NP → Non deterministic Polynomial" diye özetlendi (ekrandan, 00:15:00). Hoca gezgin satıcı probleminin karmaşıklığını $O(n^2 \cdot 2^n)$ olarak verdi; bu yüzden bu problem makul zamanda çözülebilir değildir.

Hoca bir uyarı da ekledi: $n^{100000}$ gibi bir karmaşıklık teknik olarak polinomsaldır, yani tractable sayılır; ama gerçekte böyle bir algoritma da çalıştırılabilir değildir.

> **Ek bilgi (derste anlatılmadı):** Tahtadaki "Intractable problems: NP" yazımı NP sınıfının tamamen çözülemez problemlerden oluştuğu anlamına gelmez. P'deki her problem de NP'dedir; NP içinde polinomsal çözümü bilinmeyen problemler intractable diye anılır.

## 3. Deterministik ve Deterministik Olmayan Algoritmalar

### 3.1 Tanımlar

**Deterministik algoritma**, verilen bir giriş için her zaman aynı sonucu üreten algoritmadır. On elemanlı bir dizi merge sort ile sıralandığında dizi her seferinde aynı biçimde sıralanır. İkili arama da her seferinde, eleman varsa onu bulur, yoksa bulamaz. Bunlar deterministik makinelerde çalışan deterministik algoritmalardır.

**Deterministik olmayan (non-deterministic) algoritma** ise aynı giriş için bile farklı çalıştırmalarda farklı sonuçlar verebilen algoritmadır.

### 3.2 Deterministik olmayan arama

Hoca önce deterministik olmayan bir arama algoritması yazdı. Elimizde $n$ elemanlı bir $A$ dizisi ve aranan bir $x$ sayısı vardır. Algoritma şöyle çalışır:

```text
j = choice(1..n)        // 1 ile n arasında rastgele bir indis seç
if A[j] == x then
    print j             // elemanın yerini yazdır
    success
else
    failure
```

<!-- BELİRSİZ: bu algoritmanın tahtadaki yazımı karelerde yok; satırlar altyazıdaki anlatımdan kuruldu -->

Rastgele seçilen $j$ adresinde aranan eleman varsa algoritma onu bulur; şans yaver gitmezse bulamaz. Algoritmada döngü yoktur, yalnızca "şansını deneme" vardır; bu yüzden karmaşıklığı $O(1)$'dir. Bir seçim yapılır, sonra seçimin sonucuna göre başarı ya da başarısızlık döner. Yani bir tahmin süreci ve bir doğrulama süreci vardır.

### 3.3 Deterministik olmayan sıralama: NSORT

İkinci örnek, sırasız bir $A$ dizisini sıralı olarak bir $B$ dizisine yerleştirmeye çalışan NSORT algoritmasıdır (ekrandan, 00:20:00 ve 00:25:00). Tahtadaki hali şöyledir:

```text
NSORT(A, B)   /* sort the Array A[1..n] into Array B[1..n] */
for i = 1 to n do
    B[i] = 0
for i = 1 to n do
    j = choice(1..n)
    if B[j] != 0 then failure
    B[j] = A[i]
end for
for i = 1 to n-1 do
    if B[i] < B[i+1] then failure
end for
print B
SUCCESS
```

Önce $B$ dizisi sıfırlanır. Sonra $n$ kez dönülür; her turda 1 ile $n$ arasında rastgele bir $j$ adresi seçilir. $B[j]$ sıfırdan farklıysa, yani o göze daha önce bir eleman yerleşmişse, algoritma failure ile biter. Boşsa $A[i]$ o göze yerleştirilir. Son döngü dizinin sıralı olup olmadığını kontrol eder: dizinin bütün komşu çiftleri için $B[i] < B[i+1]$ ise dizi küçükten büyüğe sıralıdır.

Hoca rastgele sayı üretecinin iyi olduğunu, yani aynı adresin arka arkaya sürekli gelmediğini varsaydı; ama aynı adres az sayıda da olsa tekrar gelebilir ve o zaman algoritma başarısız olur.

> **Ders sonrası not:** Tahtada son döngünün satırı "if B[i] < B[i+1] then failure" diye yazıldı. Hocanın anlatımına göre $B[i] < B[i+1]$ dizinin sıralı olduğu durumdur; aşağıdaki örnekte de algoritma $3 > 2$ karşılaştırmasında başarısız olur. Bu yüzden başarısızlık koşulu $B[i] > B[i+1]$ olmalıdır.

#### Birinci senaryo: çakışma yok, sonuç sırasız

Tahtadaki örnek (ekrandan, 00:25:00): $A = [2, 3, 1, 4]$, başlangıçta $B = [0, 0, 0, 0]$. Bu turda çakışma olmadığı varsayılıyor.

- $i = 1$: rastgele $j = 2$ geldi, $B[2] = A[1] = 2$.
- $i = 2$: $j = 1$ geldi, $B[1] = A[2] = 3$.
- $i = 3$: $j = 4$ geldi, $B[4] = A[3] = 1$.
- $i = 4$: geriye kalan $j = 3$ geldi, $B[3] = A[4] = 4$.

Sonuç $B = [3, 2, 4, 1]$ olur. Algoritma yerleştirme sırasında "sıralı olacak" diye bir iddiada bulunmaz; sonra kontrol eder. İlk karşılaştırmada $B[1] = 3$, $B[2] = 2$'den küçük olmadığı için doğrulama başarısız olur. Bu turda dizi sıralanamadı (python ile kontrol edildi).

#### İkinci senaryo: çakışma

Yine $B$ sıfırlanır. İlk seçimde $j = 3$ gelir ve $A[1] = 2$ üçüncü göze yerleşir. İkinci seçimde rastgele üreteç yine $j = 3$ verir. Üçüncü göz sıfır değil, dolu olduğu için algoritma o noktada failure ile biter. "Bir daha dene" gibi bir adım yoktur; algoritma orada başarısız olmuş olur.

#### Üçüncü senaryo: şans yaver gider

Bu durumda bütün elemanlar doğru sırayla yerleşir ve $B$ sıralı bir dizi olur; doğrulama geçer, $B$ yazdırılır ve SUCCESS döner.

#### Karmaşıklık

Hoca karmaşıklığı sınıfa sordu; bir öğrenci $O(n)$ dedi ve hoca onayladı. Tahtaya "Complexity: O(n)" yazıldı (ekrandan, 00:25:00). Normalde karşılaştırmaya dayalı sıralama algoritmalarının en az $n \log n$ karmaşıklıkta olduğu söylenir; bu algoritma ise her zaman çalışmaz, ama çalıştığı şanslı durumlarda diziyi $O(n)$ karmaşıklıkla sıralamış olur.

## 4. Deterministik Olmayan Algoritmanın Yapısı: Tahmin ve Doğrulama

Hoca iki örnekten genel yapıyı çıkardı. Deterministik olmayan algoritmalar üç temel öğe kullanır:

- $\text{choice}$: bir seçim yapar ve seçimin sonucunu döndürür. Arama ve sıralamada 1 ile $n$ arasında bir sayı seçildi.
- $\text{success}$: işlemler başarıyla bittiğinde dönülür.
- $\text{failure}$: işlem başarısız olduğunda dönülür.

İşlem adımları da iki aşamaya ayrılır:

- **Tahmin aşaması (guessing stage):** rastgele bir sayı atılır, elemanlar rastgele adreslere yerleştirilir. Bu aşama deterministik değildir.
- **Doğrulama aşaması (verification stage):** elde edilen sonucun doğru olup olmadığı değerlendirilir; aramada $A[j] = x$ mi, sıralamada dizi sıralı mı diye bakılır. Bu aşama deterministiktir. Çıkışta sonucun doğru ya da yanlış olduğu söylenir.

Deterministik olmayan polinomsal (NP) algoritma, doğrulama aşaması polinomsal olan algoritmadır. Böyle algoritmalar deterministik olmayan bir makinede polinomsal zamanda çözülebilir hale gelir. Bunun sebebi, problemi çözmek için gerçek bir çözümle uğraşılmaması, yalnızca doğrulama yapılmasıdır: NSORT'ta diziyi sıralamak için ciddi bir iş yapılmaz, yalnız tahmin yürütülür ve sonra dizinin sıralı olup olmadığına deterministik olarak bakılır. Sadece doğrulama için polinomsal iş yapılır; şans varsa problem polinomsal zamanda çözülmüş olur.

## 5. Optimizasyon ve Karar Problemleri

Doğrulamanın polinomsal olmasının ne anlama geldiğini açmak için hoca problemleri ikiye ayırdı (ekrandan, 00:30:00):

1. Optimizasyon problemleri (optimization problems)
2. Karar problemleri (decision problems)

### 5.1 Graf boyama örneği

Graf boyama probleminde komşu düğümler aynı renge boyanamaz. "Bu çizge en az kaç renge boyanabilir?" diye sorulursa bu bir optimizasyon problemidir. "Bu çizge iki renge boyanabilir mi?" diye sorulursa bu bir karar problemidir.

Hoca karar sorusunun polinomsal zamanda cevaplanabileceğini, "en az kaç renk" sorusunun ise derste NP diye anılan türden olduğunu söyledi. Buradaki zorluk optimizasyondur: en iyi sonucu bulmak için olasılıkları denemek gerekir. İki renge boyanabiliyor mu, hayırsa üç renge mi, hayırsa dört renge mi diye bütün seçeneklere bakılır. Küçük bir çizgede bu yapılabilir, ama büyük bir çizgede polinomsal zamanda yapılamaz.

Hoca tahtaya bir çizge çizip boyamayı denedi. Bir düğümü siyaha, komşusunu maviye boyadı ve önce iki rengin yettiğini düşündü. Bir öğrenci iki düğümün aynı renge kaldığını hatırlattı. Hoca bunun üzerine bir düğümün hem siyah hem mavi komşusu olduğunu, bu yüzden üçüncü bir renk gerektiğini gösterdi; bu çizge en az üç renkle boyanabilir. <!-- BELİRSİZ: çizgenin düğüm ve kenarları karelerde görünmüyor -->

### 5.2 Diğer örnekler

Gezgin satıcı probleminde şehirler ve şehirler arasındaki mesafeler verilir; her şehre bir kez uğrayarak bütün şehirleri en kısa yoldan nasıl gezebileceğimiz sorulur. Bu da bir optimizasyon problemidir; en iyisini bulmak istenir ve polinomsal zamanda çözümü yoktur.

Hamilton devresinde ise bir başlangıç düğümünden çıkıp her düğümden bir kez geçerek başa dönülüp dönülemeyeceği sorulur; bunun da polinomsal zamanda bilinen bir çözümü yoktur.

> **Ek bilgi (derste anlatılmadı):** Karar ve optimizasyon sürümleri genellikle birbirine bağlıdır. Örneğin "k renkle boyanabilir mi?" sorusu her k için cevaplanabilirse en küçük renk sayısı da bulunur. İki renk için karar problemi polinomsaldır (çizgenin iki parçalı olup olmadığına bakılır), ama üç ve daha fazla renk için karar problemi NP-tamdır.

## 6. P ve NP Sınıfları

Tahtaya "Class P and Class NP" başlığı yazıldı (ekrandan, 00:35:00). Hoca iki sınıfı şöyle ayırdı:

- Bir problemin çözümü polinomsal zamanda **bulunabiliyorsa** problem polinomsaldır (P).
- Bir problemin çözümü polinomsal zamanda **doğrulanabiliyorsa** problem deterministik olmayan polinomsaldır (NP).

Bu mantıkla polinomsal algoritmalar, deterministik olmayan polinomsal algoritmaların bir alt kümesidir: $P \subseteq NP$. Bu kanıtlanabilen bir şeydir. Ama P'nin NP'ye eşit olup olmadığı, yani $P = NP$ olup olmadığı kanıtlanamamıştır. Clay vakfı (Clay Foundation) bu problemin çözümü için 1 milyon dolar ödül koymuştur. Bütün P problemleri NP'nin alt başlığıdır, ama bütün NP problemlerinin P olduğu diye bir kural yoktur.

**Soru:** Zaman geçtikçe ve yeni algoritmalar bulundukça P kümesi büyümüyor mu? Bugün polinomsal zamanda çözülemediğini düşündüğümüz bir problem, başka birinin bulacağı bir yöntemle polinomsal zamanda çözülürse P'ye dahil olmaz mı?

**Cevap:** Evet, böyle bir şey olabilir. Şimdiye kadar NP olduğu bilinen problemlerin çoğunda yalnızca doğrulama yapılabiliyor; NP'den P'ye geçen pek problem yok, ama zaman içinde bu mümkündür.

> **Ders sonrası not:** Hoca bu cevapta minimum kapsayan ağacın (minimum spanning tree) NP bir problem olduğunu, bulunan çözümün en iyi olup olmadığının bilinmediğini söyledi. Doğrusu, minimum kapsayan ağaç Prim ve Kruskal gibi açgözlü algoritmalarla polinomsal zamanda ve en iyi (optimal) olarak bulunur; problem P sınıfındadır. Hoca büyük olasılıkla açgözlü yaklaşımın en iyi sonucu garanti etmediği başka bir örneği kastetmiştir.

## 7. NP-Tam ve NP-Zor Problemler

### 7.1 Problem uzayı şeması

Hoca problem uzayını bir küme şemasıyla çizdi (ekrandan, 00:40:00 ve 00:45:00). Şemadaki yapı şöyledir:

- En dışta bütün problemler kümesi ("All problems").
- Onun içinde NP kümesi; NP'nin içinde P kümesi.
- NP ile kısmen kesişen ayrı bir NP-hard kümesi.
- NP ile NP-hard kümelerinin kesişim bölgesi NP-complete olarak işaretlendi.

Tahtadaki tanımlar şöyledir:

- **NP-complete:** "solution NP, verification P". Çözümü bulmak NP'dir, ama doğrulaması polinomsal zamanda yapılabilir.
- **NP-hard:** "solution NP, can not verified in P". Çözümü NP'dir ve doğrulaması bile polinomsal zamanda yapılamaz.

### 7.2 Gezgin satıcı: NP-zor örneği

Gezgin satıcı probleminde bir çizge verilir; düğümler şehirleri, kenar ağırlıkları şehirler arası süreleri gösterir. Bütün düğümlere uğrayan en kısa tur sorulur. Tahtada dört düğümlü, kenarlarında 5, 3, 4 ve 2 ağırlıkları olan bir çizge üzerinde bir tur işaretlendi (ekrandan, 00:45:00).

Bu problemde doğrulama "önerdiğim bu tur en kısa tur mu?" sorusudur. Biri "şuradan çıktım, buraya gittim, oradan şuraya gittim; bu en kısa tur mu?" dediğinde bunun en kısa olup olmadığını polinomsal zamanda doğrulamanın bir yolu yoktur. Bu yüzden hoca gezgin satıcı problemini NP-zor (NP-hard) bir problem olarak sınıflandırdı.

### 7.3 Hamilton devresi: NP-tam örneği

Hamilton devresinde soru şudur: bir düğümden çıkıp bütün düğümleri gezerek başlangıç düğümüne dönebilir miyim? Tahtadaki dört düğümlü çizgede (ekrandan, 00:45:00) hoca bir düğümden çıkıp ilerledi ve bir noktada tıkanıp kaldığını, yani Hamilton devresi oluşturulamadığını gösterdi. <!-- BELİRSİZ: sol alttaki çizgenin kenarlarının tamamı karede net okunmuyor -->

Verilen bir çizgede Hamilton devresi olup olmadığını bulmak deterministik olmayan polinomsal bir problemdir. Ama biri "buradan çıktım, buraya gittim; bu bir Hamilton devresi mi?" diye sorduğunda bunu doğrulamak polinomsaldır: yapılması gereken tek şey söylenen yolu izlemektir. Doğrulaması polinomsal zamanda yapılabildiği için hoca bu problemi NP-tam (NP-complete) olarak sınıflandırdı.

### 7.4 Özet tablo

Hoca konuyu bir tabloyla özetledi. Anlatımına göre yalnızca P problemleri polinomsal zamanda çözülebilir; P, NP ve NP-tam problemler polinomsal zamanda doğrulanabilir (verify edilebilir); NP-zor problemlerin böyle bir özelliği yoktur, doğrulamaları bile polinomsal zamanda yapılamaz. <!-- BELİRSİZ: özet tablonun kendisi karelerde yok; içerik altyazıdan kuruldu -->

| Sınıf | Polinomsal zamanda çözülebilir mi? | Polinomsal zamanda doğrulanabilir mi? |
|---|---|---|
| P | Evet | Evet |
| NP | Bilinmiyor (genel olarak) | Evet |
| NP-tam | Bilinen yöntem yok | Evet |
| NP-zor (derste verilen tanım) | Bilinen yöntem yok | Hayır |

Hoca bu kavramların gerçekte bu kadar basit olmadığını, indirgeme (reduction) gibi daha pek çok ayrıntı içerdiğini, ama bu ders için bu temel düzeyin yeterli olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Standart tanımda bir problem, NP'deki her problem ona polinomsal zamanda indirgenebiliyorsa NP-zordur; NP-zor olup aynı zamanda NP'de bulunan problemler NP-tamdır. Bu yüzden bazı NP-zor problemlerin doğrulaması polinomsal olabilir; derste verilen "doğrulama bile polinomsal değil" tanımı, şemadaki NP dışında kalan NP-zor bölgeyi anlatan basitleştirilmiş bir tanımdır.

> **Ek bilgi (derste anlatılmadı):** Gezgin satıcının karar sürümü ("uzunluğu en fazla k olan bir tur var mı?") NP-tamdır, çünkü önerilen turun uzunluğu kolayca toplanıp k ile karşılaştırılabilir. Derste NP-zor diye anılan, "bu tur en kısa tur mu?" diye soran optimizasyon sürümüdür.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:04:48): NP kısaltmasının açılımı nedir?

> **Çözüm:** Non-deterministic polynomial, yani deterministik olmayan polinomsal. "Non-polynomial" değildir.

**Soru 2** (derste sözlü, 00:17:01): Deterministik olmayan arama algoritmasının ($j = \text{choice}(1..n)$, $A[j] = x$ ise success, değilse failure) karmaşıklığı nedir?

> **Çözüm:** Döngü yoktur, yalnızca bir seçim ve bir karşılaştırma yapılır; karmaşıklık $O(1)$'dir.

**Soru 3** (ekrandan, 00:25:00): NSORT algoritmasında $A = [2, 3, 1, 4]$ için rastgele seçilen indisler sırasıyla $2, 1, 4, 3$ olursa $B$ dizisi ne olur ve algoritma başarılı olur mu? Algoritmanın karmaşıklığı nedir?

> **Çözüm:** $B[2] = 2$, $B[1] = 3$, $B[4] = 1$, $B[3] = 4$; yani $B = [3, 2, 4, 1]$. Dizi sıralı olmadığı için doğrulama ilk karşılaştırmada başarısız olur. Karmaşıklık $O(n)$'dir.

**Soru 4** (derste sözlü, 00:31:28): Tahtadaki çizge, komşu düğümler aynı renge boyanmayacak şekilde en az kaç renge boyanabilir? <!-- BELİRSİZ: çizge karelerde görünmüyor -->

> **Çözüm:** Bir düğümün hem birinci hem ikinci renkte komşusu olduğu için iki renk yetmez; çizge en az üç renkle boyanabilir.

**Soru 5** (derste sözlü, 00:37:30): Yeni algoritmalar bulundukça P kümesi büyür mü?

> **Çözüm:** Evet, bugün polinomsal çözümü bilinmeyen bir problem için polinomsal bir algoritma bulunursa problem P'ye geçer. Ama şimdiye kadar NP'den P'ye geçen pek problem yoktur ve $P = NP$ sorusu açıktır.

## Dersin Toparlaması

Bu derste algoritma analizinin son kavramsal konusu işlendi. Polinomsal zamanlı algoritmaların efektif (tractable), üstel zamanlı algoritmaların ise $n$ biraz büyüyünce bile pratikte çalıştırılamaz (intractable) olduğu bir süre tablosuyla gösterildi. Ardından deterministik olmayan algoritmalar arama ve NSORT örnekleriyle tanıtıldı: bu algoritmalar bir tahmin aşaması ve deterministik bir doğrulama aşamasından oluşur; NP algoritma, doğrulaması polinomsal olan algoritmadır.

Son olarak optimizasyon ve karar problemleri ayrıldı, P'nin NP'nin alt kümesi olduğu ve $P = NP$ sorusunun hâlâ açık olduğu anlatıldı. Problem uzayı şemasında NP-tam problemler (çözümü zor, doğrulaması polinomsal; örnek Hamilton devresi) ve NP-zor problemler (derste verilen tanımla doğrulaması bile polinomsal olmayan; örnek gezgin satıcının en kısa turu) yerleştirildi. Hoca bu konuyla birlikte dersin akademik konularının tamamlandığını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
