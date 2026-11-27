# Ders 3 Genişletilmiş Notu: Algoritma Tasarım Teknikleri, OBEB, Eratosthenes'in Eleği ve Basit Sıralama Algoritmaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Uygulamadan Kalan İki C Örneği
- 2. Neden Algoritma Tasarlarız?
- 3. Algoritmanın Özellikleri ve Hazırlanma Süreci
- 4. Algoritma Tasarım Teknikleri
- 5. OBEB Bulma: Ortaokul Yöntemi ve Öklid Algoritması
- 6. Asal Sayı Bulma ve Eratosthenes'in Eleği
- 7. Sıralama Problemi
- 8. Selection Sort (Seçmeli Sıralama)
- 9. Bubble Sort (Kabarcık Sıralama) ve Shell Sort
- 10. Insertion Sort (Eklemeli Sıralama)
- 11. Soru-Cevap: Derlenen ve Yorumlanan Diller
- 12. Derse Çalışma Önerileri
- Örnek Sorular

## 1. Önceki Uygulamadan Kalan İki C Örneği

Hoca derse, önceki uygulama saatinde yetişmeyen iki kodlama örneğine hızlıca bakarak başladı. Amaç, birkaç satırlık kodlarla sık kullanılan C özelliklerini hatırlatmaktı: komut satırından argüman almak, tip tanımlamak, harici bir kütüphane (matematik kütüphanesi) kullanmak ve değişkenleri birbirine atamak.

### 1.1 Ortalama ve Standart Sapma

Programda $N$ sayısı kullanıcıdan komut satırı parametresi olarak alınır. Bunun için `main` fonksiyonu iki argümanla tanımlanır: argüman sayısını tutan `int argc` ve argümanları karakter dizisi olarak tutan `char *argv[]`. `argv[0]` programın kendi adıdır. Bu yüzden $N$, `argv[1]` içindeki karakter dizisinin `atoi` ile tamsayıya çevrilmesiyle elde edilir. Hoca, gerçek bir programda sayı dışında bir şey girilirse uyarı veren bir kontrol eklenmesi gerektiğini, bu basit örnekte bunun yapılmadığını belirtti.

`Number` C'de hazır bir tip değildir. Kodun başında `typedef float Number;` ile tanımlanmıştır: "Number adında bir tip tanımlıyorum ve bu aslında bir float'tur." Hoca bu kısa yolu, birkaç hafta sonra bağlı listeler ve yığıtlarla (stack) birlikte struct'larda sık kullanacaklarını söyledi. Böylece her seferinde uzun struct adını yazmak gerekmeyecek.

Kod (ekrandan, 00:10:00):

```c
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef float Number;

Number randNum (){
   return 1.0*rand()/RAND_MAX;
}

int main(int argc, char *argv[]){
   int i, N = atoi(argv[1]);
   float m1 = 0.0, m2 = 0.0;
   Number x;

   for (i = 0; i < N; i++){
      x = randNum();
      m1 += ((float) x)/N;
      m2 += ((float) x*x)/N;
   }

   printf(" Average: %f\n", m1);
   printf("Std.Dev.: %f\n", sqrt(m2-m1*m1));
}
```

Döngü $N$ kez rastgele bir sayı üretir. `m1`, her $x$ değerinin $N$'ye bölünüp toplanmasıyla doğrudan ortalamayı verir. `m2` aynı şekilde $x^2$'lerin ortalamasını tutar. Standart sapma için karelerin ortalamasından ortalamanın karesi çıkarılır ve karekök alınır:

$$\sigma = \sqrt{\overline{x^2} - \bar{x}^2}$$

> **Ders sonrası not:** Kod `gcc -Wall` ve `-lm` ile uyarısız derlendi, `N = 100000` ile çalıştırıldı. Çıktı yaklaşık `Average: 0.4999`, `Std.Dev.: 0.2886` oldu. Bu değerler 0-1 arası düzgün dağılımın kuramsal ortalaması $0{,}5$ ve standart sapması $1/\sqrt{12} \approx 0{,}2887$ ile uyumludur.

### 1.2 Yazı-Tura Simülasyonu

İkinci örnek bir simülasyondu. Elimizde hilesiz bir bozuk para olsun. Bu parayı $N$ kez atarsak $k$ kez tura görme olasılığı nedir? Sıfır tura, bir tura, iki tura... $N$ tura. Beklenti, en yüksek olasılığın yarı yarıya, yani $N/2$ turada olmasıdır. Olasılık şu formülle verilir ve büyük $N$ için normal dağılım yaklaşımıyla ifade edilebilir:

$$P(k) = \binom{N}{k}\frac{1}{2^N} \approx \frac{e^{-(k-N/2)^2/N}}{\sqrt{\pi N/2}}$$

Hoca ayrıntısına girmedi, bunun Bernoulli deneyi ya da binom dağılımı olarak bilindiğini söyledi.

> **Ders sonrası not:** Hoca üstel terimdeki paydayı sözlü olarak $N$ diye okudu. Normal yaklaşımda varyans $N/4$ olduğu için üs büyük olasılıkla $-2(k-N/2)^2/N$ olmalıdır. Python ile $N=32$, $k=20$ için kesin değer yaklaşık 0,0526; $-2(k-N/2)^2/N$ üssüyle yaklaşık 0,0519, $-(k-N/2)^2/N$ üssüyle yaklaşık 0,0855 çıkar.

<!-- BELİRSİZ: yazı-tura kodunun ve formülün slaydı karelerde yok; formül altyazıdaki sözlü okumadan kuruldu, kod yapısı aşağıda yalnız anlatımla verildi. -->

Programın yapısı altyazıya göre şöyledir:

- `heads()` adında tek satırlık bir fonksiyon, `rand()` değeri `RAND_MAX/2`'den küçükse 1 (tura), değilse 0 döndürür. Bu bir boolean karşılaştırmanın sonucudur.
- Komut satırından iki değer okunur: birinci argüman $N$ (atış sayısı), ikinci argüman $M$ (deney sayısı).
- $(N+1) \cdot$ `sizeof(int)` boyutunda bir sayaç dizisi için yer ayrılır ve bütün gözler sıfırlanır.
- $M$ deneyin her birinde para $N$ kez atılır, tura gelince sayaç artırılır. Deney sonunda o tura sayısının gözü bir artırılır.
- Sonuçlar ekrana yazdırılırken okunabilirlik için her 10 deneye bir yıldız basılır.

Ekrandaki çıktılar (ekrandan, 00:15:00):

- $N=32$, $M=1000$: 0-7 arası tura sayıları için hiç yıldız yok. En uzun satır 16'da; 15, 17 ve 18 biraz daha kısa, uçlara doğru giderek azalıyor. 25 için yıldız yok, 26 için bir yıldız var.
- $N=16$, $M=1000$: en uzun satırlar 8 ve 9 civarında; dağılım daha geniş yayılmış görünüyor.

Hoca, $N$ ya da $M$ küçüldükçe sonuçların normal dağılımdan sapabileceğini, dalgalanmaların artacağını söyledi. $M$'yi 10, 100, 1000 yaparak deneme sayısı arttıkça dağılıma daha çok yaklaşıldığı gözlenebilir.

## 2. Neden Algoritma Tasarlarız?

Hoca önceki haftadaki girişi hatırlattı: algoritmalar, bir problemi verilen şartlar altında beklentileri karşılayacak biçimde, yani hızlı çalışan ya da az yer kaplayan biçimde çözmek için tasarlanır. Bunu günlük hayattan bir örnekle somutlaştırdı (ekrandan, 00:20:00):

- Her satırında 10 kelime olan 20 satırlık 3000 mektup (e-posta) olsun. Toplam $3000 \times 20 \times 10 = 600.000$ kelime eder.
- Bu kelimeler arasında belirli bir adla eşleşen bütün kelimeleri bulmak (ya da kaç kez geçtiğini saymak) istiyoruz.
- Her karşılaştırma 1 saniye sürsün.
- Kelimeler sözlük gibi A'dan Z'ye sıralı tutuluyor olsun.

### 2.1 Temel Çözüm: Sırayla Arama

İlk akla gelen çözüm (baseline) baştan sona sırayla bakmaktır. A ile başlayan kelimelerden başlanır; B, C, D, E gezilir. Aranan ad G harfiyle başlıyorsa, eşleşmeler G bölümünde art arda gelir (hocanın örneğinde 62 eşleşme). Ama yöntem bir yerde kesilmez, Z'ye kadar boşuna da olsa devam eder. Dizinin her gözüne bir kez bakılır: 600.000 karşılaştırma, yani 600.000 saniye. Bu yaklaşık 166 saattir.

> **Ders sonrası not:** Hoca 166 saati "bir haftadan fazla, 7-8 gün" diye yorumladı. $600.000 / 86.400 \approx 6{,}9$ gün eder; yani bir haftaya yakın ama bir haftadan biraz azdır.

### 2.2 Daha Akıllı Çözüm: İkili Arama

Aranacak kelime kullanıcıdan gelir; harfi önceden bilinmez. Hoca "karpuzu ortasından keser gibi" diye anlattı: sıralı dizinin tam ortasına bakılır. Ortada örneğin K harfi varsa ve aranan kelime B ile başlıyorsa, dizinin sağ yarısına hiç bakmaya gerek yoktur, çünkü oradaki bütün kelimeler K'den Z'ye kadar olan harflerle başlar. Tek hamlede arama uzayı yarıya iner. Sonra kalan sol yarının ortasına bakılır (örneğin F) ve B daha küçük olduğu için yarının yarısı da atılır. Böyle böyle aranan kelimelerin bulunduğu bölgeye varılır. Oradan sonra birkaç komşu kelimeye sağa sola bakılır; bu son kısım da istenirse yine ikili aramayla yapılabilir.

Her adımda dizi boyutu yarıya indiği için karşılaştırma sayısı $\log_2$ ile büyür:

$$\log_2 600.000 \approx 19{,}2 \approx 20 \text{ saniye}$$

Hoca sondaki birkaç komşu kontrolüyle birlikte yaklaşık 20-25 saniye dedi. Aynı veri üzerinde bir yöntem bir haftaya yakın, diğeri yarım dakika sürüyor.

### 2.3 Donanım mı, Algoritma mı?

İlk yöntem için 10 kat güçlü bir bilgisayar alınsa süre 166 saatten yaklaşık 16 saate iner. Ama bunun için 10 kat fazla işlem gücüne, yani 10 kat fazla yatırıma ihtiyaç vardır. Hoca bu yüzden algoritma tasarladığımızı vurguladı: gerektiğinde hızlı, gerektiğinde az yer kaplayan, gerektiğinde ikisini dengeleyen ya da birinden biraz feragat edip diğerinde ciddi kazanç sağlayan çözümler üretmek için.

## 3. Algoritmanın Özellikleri ve Hazırlanma Süreci

Algoritmik program tasarımında bir problem bilgisayar ortamında adım adım ortaya konur, sonra bir programlama diliyle kodlanır. Adımlar hiçbir alternatif yoruma ya da muğlak ifadeye izin vermeyen, kesin, tekil işlemler olmalıdır. Hoca burada "yorumsuz" sözünün kodun yorum satırlarıyla karıştırılmaması gerektiğini ekledi. Bazen işlemlerin önceliklendirilmesi gerekir; örneğin yazı-tura simülasyonunda önce atış fonksiyonunu tanımlamak gerekti. Komutlar kodlanabilir ve uygulanabilir olmalıdır.

Algoritmanın mutlaka bir sonu olmalıdır; sonsuz sayıda komut çalıştıran bir algoritma olmaz. Tek istisna sürekli akan veri üzerinde çalışan yöntemlerdir: veri aktığı sürece teorik olarak sonsuz çalışırlar. Belirli bir veri kümesi üzerinde çalışan algoritmanın ise sonlu sayıda komutla bitmesi ve bir çözüm üretmesi beklenir.

Hazırlanma süreci (önceki dersten hatırlatma):

- Tasarım: algoritma önce düşünülür ve tasarlanır.
- Doğruluğun ispatı (validasyon): doğru girdi verildiğinde doğru sonuç ürettiği gösterilir.
- Analiz: beklenen performansı sergileyip sergilemediği incelenir.
- Kodlama ve test.
- Kullanıma alma (devreye alma).

## 4. Algoritma Tasarım Teknikleri

Hoca yaygın tasarım stratejilerini ayrıntıya girmeden tanıttı (ekrandan, 00:30:00):

- **Kaba kuvvet (Brute-Force):** "Körlemesine" ya da "bodoslama" çalışan yöntemler. En bilinen örneği şifre kırmadır: milyonlarca anahtar birinciden sonuncuya kadar tek tek kilide sokulur, biri açar umuduyla. Selection Sort da tam bir kaba kuvvet yöntemidir: sıraladığı veri hakkında hiçbir ön fikri yoktur, "bunları zaten yapmıştım" ya da "bunlar artık bundan küçük olamaz" gibi bir çıkarım yapmadan robot gibi alır, koyar.
- **Açgözlü (Greedy):** Algoritma adım adım ilerlerken her adımda o anda mevcut olan en iyi şeyi yapar; geçmişi ya da sonraki adımları birlikte düşünmez. Bir karar noktasında o an en çok kazanç getiren dal seçilir. İki üç adımı birlikte düşünseydi belki daha iyisini yapabilirdi, ama algoritmayı yinelemeli olarak tasarlayabilmek için her adımda yerel en iyi seçilir. Slayttaki örnekler Prim (minimum kapsayan ağaç) ve Dijkstra (en kısa yol). Hoca Prim algoritmasına dönemin sonlarında çizgelerle birlikte bakacaklarını söyledi.
- **Böl ve yönet (Divide and Conquer):** Problemi küçük parçalara böler, küçük problemleri çözer, sonra çözümleri birleştirerek nihai çözümü üretir. Hocaya göre en bilinen örneği Merge Sort'tur ve üzerinde yaklaşık iki hafta durulacak.
  - **Azalt ve yönet (Decrease and Conquer):** Problemi her adımda biraz azaltarak ilerler. Bazı kaynaklar bunu böl ve yönetten ayırır, bazıları ayırmaz. Örneği Insertion Sort (bu derste).
  - **Değiştir ve yönet (Transform and Conquer):** Bakış açısını değiştirir; problemi başka bir veri yapısına aktarıp o yapının sağladığı kolaylıklarla daha kolay çözer. Örneği Heap Sort.
- **Dinamik Programlama:** Örneğin Fibonacci sayıları özyinelemeli (rekürsif) çözülebilir ya da dinamik programlamayla doğrusal karmaşıklıkta hesaplanabilir.
- **Artımlı İyileştirme (Iterative Improvement):** Sayısal analizdeki Newton-Raphson gibi, her yinelemede çözümü biraz daha iyileştirerek denklemin köküne yaklaşan yöntemler.
- **Geri Takip (Backtracking):** Açgözlü yöntemlerin aksine geçmişi de düşünür: birkaç adım atar, sonra "üç adım geride başka bir seçim yapsaydım daha iyi olurdu" deyip geri döner ve başka bir seçimle devam eder. Her probleme uygun değildir, çünkü her zaman geri dönme şansı olmayabilir. Bilinen sudoku çözme algoritmaları böyle çalışır: birkaç sayı yerleştirilir, kilitlenince bir yere kadar geri gelinip değiştirilerek devam edilir.

> **Hocanın vurgusu:** Dinamik programlama, artımlı iyileştirme ve geri takip bu dönemin kapsamında olmayacak.

## 5. OBEB Bulma: Ortaokul Yöntemi ve Öklid Algoritması

### 5.1 Ortaokul Yöntemi Algoritma mıdır?

OBEB (ortak bölenlerin en büyüğü, greatest common divisor, gcd): verilen iki doğal sayı $m$ ve $n$'nin ikisini de bölen en büyük sayı. Ortaokulda öğretilen yöntem:

- Birinci sayıyı asal çarpanlarına ayır.
- İkinci sayıyı asal çarpanlarına ayır.
- İki çarpan kümesinde ortak olanları bul.
- Ortakların hepsini çarp ve sonucu OBEB olarak ver.

Hoca bunun bir algoritma olup olmadığını sordu. Öğrencilerden gelen cevaplar: asal çarpanların nasıl bulunacağı söylenmiyor; ifadeler net değil. Hoca bunları onayladı. "Asal çarpanları bul" denir ama nasıl bulunacağı tanımlı değildir. "Ortak çarpanları bul" adımı kendi başına bir algoritmik problemdir (iki kümenin kesişimini bulmak). Çarpma adımı sorunsuzdur. Bir insan bu adımları deneyerek yapabilir, ama ifadeler muğlak olduğu için bu bir algoritma değildir.

### 5.2 Öklid Algoritması

Öklid'in MÖ 300 civarında *Elements* kitabında tanımladığı yöntem (ekrandan, 00:40:00):

$$\gcd(m, n) = \gcd(n,\ m \bmod n), \quad n = 0 \text{ olana kadar}$$

Fonksiyon kendini yeni değerlerle çağırır. Her adımda tek bir aritmetik işlem yapılır: $m \bmod n$. $n$ sıfır olduğunda elde kalan $m$ sayısı OBEB'dir.

**Örnek 1: $\gcd(60, 24)$.** Ortaokul yöntemiyle $60 = 2 \cdot 2 \cdot 3 \cdot 5$ ve $24 = 2 \cdot 2 \cdot 2 \cdot 3$ olarak ayrılırdı. Öklid ile:

- $60 \bmod 24 = 12$ (çünkü $2 \cdot 24 = 48$, kalan 12). Yani $\gcd(60,24) = \gcd(24,12)$.
- $24 \bmod 12 = 0$. Yani $\gcd(24,12) = \gcd(12,0)$.
- $n = 0$ olduğu için durulur. Sonuç: 12. Gerçekten $24 = 2 \cdot 12$ ve $60 = 5 \cdot 12$.

**Örnek 2: $\gcd(1785, 546)$.** Bu sayıları gözle asal çarpanlarına ayırmak zordur (biri 5'in, diğeri 2'nin katı görünüyor, ama gerisi kağıt üzerinde uzun iş). Öklid ile:

| Adım | $m$ | $n$ | $m \bmod n$ |
|---|---|---|---|
| 1 | 1785 | 546 | 147 |
| 2 | 546 | 147 | 105 |
| 3 | 147 | 105 | 42 |
| 4 | 105 | 42 | 21 |
| 5 | 42 | 21 | 0 |

Beşinci adımda kalan 0 olunca durulur ve OBEB 21'dir (python ile doğrulandı). Yalnız 5 mod işlemiyle sonuca varıldı. Hoca, asal çarpanlara ayırmanın bambaşka bir problem olduğunu, burada derdin yalnız OBEB olduğunu belirtti.

### 5.3 Sözde Kod ve Akış Diyagramı

Slayttaki adımlar (ekrandan, 00:45:00):

```text
Step 1  If n = 0, return m and stop
Step 2  Divide m by n and assign the value of the remainder to r
Step 3  Assign the value of n to m.
        Assign the value of r to n.
        Go to Step 1.
```

Akış diyagramı:

```text
Başla
  -> m, n oku
  -> [n ≠ 0 ?]
       evet: r ← m mod n
             m ← n
             n ← r
             -> tekrar [n ≠ 0 ?]
       hayır: m yaz
  -> Bitir
```

Durma şartı $n$'nin sıfır olmasıdır. Her adımda mod alındığı için $n$ küçülür ve sıfıra ulaşacağı garanti edilir; algoritma sonlu adımda biter. Hoca, bu yöntemin tek bir döngü içinde bölme ile azaltarak ilerlediğini, ortaokul yönteminin (çarpanlara ayırma, kesişim bulma, çarpma) ise çok daha yüksek karmaşıklıkla aynı sonuca vardığını söyledi. Mod işlemi aslında problemi yinelemeli olarak küçültmekten başka bir şey değildir: 1785 ve 546'dan başlayıp 147, 105, 42 gibi giderek küçülen sayılara inilir.

## 6. Asal Sayı Bulma ve Eratosthenes'in Eleği

### 6.1 Problem ve Temel Yöntem

Asal sayılara özellikle şifrelemede ihtiyaç duyulur: bölenleri olmadığı için anahtar oluşturmada değerlidir ve çok büyük asal sayıların bulunması gerekir. Daha basit bir problemle başlanır: $N$'e kadar olan bütün asal sayıları "efektif olarak" nasıl bulabiliriz (ekrandan, 00:50:00)? Örneğin $N = 100$.

Temel yöntem: 1'den 100'e kadar sırayla bak; her sayıyı o ana kadar bulunan asallara bölmeyi dene. Bölünüyorsa asal değil, bölünmüyorsa asaldır. 2 asal; 3, 2'ye bölünmüyor, asal; 4, 2'ye bölünüyor, asal değil; 5, 2 ve 3'e bölünmüyor, asal; 6 hem 2'ye hem 3'e bölünüyor... Her yeni sayı giderek artan sayıda asalla karşılaştırılır. $N = 1000$ olduğunda örneğin 999 için o ana kadar bulunan bütün asallarla deneme yapmak gerekir. Sayı büyüdükçe karşılaştırma sayısı da artar.

### 6.2 Öğrenci Önerileri

Teneffüsten önce hoca öğrencilerin düşünmesini istedi. Gelen öneriler:

- **"Her sayıda 5'e kadar baksak yeterli."** Hoca bunun yalnız 100'e kadar olan sayılar için doğru olduğunu, $N$ bir milyon olduğunda geçerli olmadığını söyledi.
- **"Kareköke kadar olan asallara bakmak yeterli."** Hoca bunu bir ilerleme olarak kabul etti: bir sayının karekökünden büyük bir çarpanı varsa, karekökünden küçük bir çarpanı da vardır. Ama yine de her sayıya geriye dönük bakılır; 50-60 basamaklı sayılar düşünüldüğünde bu da yeterince verimli değildir.

### 6.3 İleriye Doğru Süpürme Fikri

Hoca şunu sordu: bu iş hep ileri doğru giderek, dizi üzerinde bir "süpürme" ile yapılamaz mı? 2 asal ise, 2'ye bölünebilen hiçbir sayı asal olamaz. Yani 4, 6, 8, 10, ... bütün çift sayılar bir kerede silinebilir. Sonra 3'ün katları, sonra 5'in katları silinir. Her yeni asal bulunduğunda katları "asal olamaz" diye işaretlenirse, geriye dönük kontrol yerine dizinin ilerideki gözleri temizlenmiş olur. Bu yöntemin adı Eratosthenes'in eleğidir (Sieve of Eratosthenes) (ekrandan, 01:10:00). Hoca Eratosthenes'in bir matematikçi ve filozof olduğunu, algoritmanın da yaklaşık 2300 yıllık olduğunu söyledi.

### 6.4 100'e Kadar Elek Örneği

Hoca slayttaki 1-100 tablosu üzerinde kalemle işaretleyerek gösterdi:

- **2:** 2'nin bütün katları (4, 6, 8, ..., 100) tek geçişte silinir. Hoca yanlışlıkla 2'yi de boyadığını, normalde 2'nin kendisinin işaretlenmemesi gerektiğini belirtti.
- **3:** Silinmemiş ilk sayı 3, asaldır. 3'ün henüz silinmemiş katları silinir: 9, 15, 21, 27, 33, 39, 45, 51, 57, 63, 69, 75, 81, 87, 93, 99.
- **5:** Sıradaki silinmemiş sayı 5. Katlarından henüz silinmemiş olanlar: 25, 35, 55, 65, 85, 95. Bazı katları zaten silindiği için onlara bakmaya gerek kalmaz; 10'un katları 2 yüzünden zaten gitmiştir.
- **7:** Kalan katlar: 49, 77, 91. (Hoca öğrencilere sordu; 77 ve 91'i öğrenciler hatırlattı.)
- **11:** 11'in silinmemiş ilk katı $11 \times 11 = 121$'dir ve 100'ün dışındadır. Bu yüzden burada durulur ve kalanların hepsi asal olarak işaretlenir.

Elekte kalan asallar: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 (25 sayı; python ile doğrulandı).

> **Ders sonrası not:** Hoca 2'nin katlarını silince "100 sayının 50 tanesini, pardon 48 tanesini" elediğini söyledi. 2 hariç 4'ten 100'e kadar 49 çift sayı vardır; hocanın yanlışlıkla 2'yi de boyamasıyla 50 olur.

**Soru:** 11'den sonra neden durduk, 11'in katlarına neden bakmadık?
**Cevap:** 11 ile oluşan, henüz silinmemiş olabilecek en küçük sayı $11 \times 11 = 121$'dir. 11'in daha küçük katları zaten önceki asallar tarafından silinmiştir: $11 \times 2 = 22$ 2 yüzünden, $11 \times 3 = 33$ 3 yüzünden, $11 \times 5 = 55$ 5 yüzünden silinmiştir. 121 ise 100 sınırının dışındadır. Bu yüzden 100'ün kareköküne, yani 10'a kadar gitmek yeterlidir; gereksiz yere tekrar tekrar karşılaştırma yapmaya gerek yoktur.

### 6.5 Sözde Kod

Slayttaki sözde kod (ekrandan, 01:15:00):

```text
Input: Integer n ≥ 2
Output: n'den küçük eşit asal sayılar

for p ← 2 to n do  A[p] ← p

for p ← 2 to ⌊√n⌋ do
   if A[p] ≠ 0   //p önceden listeden silinmediyse
      j ← p * p
      while j ≤ n  do
         A[j] ← 0   // asal değil olarak işaretle
         j ← j + p
```

Önce bir ilkleme yapılır: 2'den $n$'e kadar bir dizinin her gözüne kendi değeri atanır (1 zaten asal kabul edilmez). Hoca tablonun ekrana sığsın diye kare matris gibi çizildiğini, aslında tek boyutlu bir dizi olduğunu belirtti. Sonra $p$, 2'den $\lfloor\sqrt{n}\rfloor$'e kadar döner. $A[p]$ sıfır değilse (yani $p$ daha önce silinmediyse) $p \cdot p$'den başlanır ve $n$'e kadar $p$'şer artarak bütün katlar sıfırlanır. 100 için dış döngü yalnız 10 değer alır.

Hocanın vurguladığı iki fikir: (1) geriye dönük bölme kontrolü yerine ileriye doğru katları silmek, (2) bunu yalnız kareköke kadar yapmanın yeterli olması, çünkü ötesindekiler önceki asal çarpanlar yüzünden zaten silinmiştir.

Karmaşıklık konusunda hoca, analizin bir sonraki hafta öğretileceğini söyleyerek ayrıntıya girmedi. Maliyetin döngülerden, karşılaştırmalardan ve atamalardan geldiğini; burada $n$ mertebesinde işlem yapıldığını ve karekök nedeniyle logaritmik bir çarpan oluştuğunu söyledi ve kabaca "$n \log n$" dedi. Geriye dönük bölme kontrolü yapan yöntemde ise karmaşıklık $n^2$ ya da $n^3$ mertebesine çıkar.

> **Ders sonrası not:** Eratosthenes'in eleğinin bilinen zaman karmaşıklığı büyük olasılıkla $O(n \log \log n)$'dir; bu, hocanın kabaca söylediği $n \log n$'den daha iyidir.

### 6.6 Aynı Algoritmanın İki Farklı Akışı

Hoca elle çizdiği iki akış diyagramını gösterdi (ekrandan, 01:25:00):

```text
Sol akış                              Sağ akış
START                                 START
N oku                                 N oku
p ← 2 .. N (adım 1):                  i ← 2 .. N (adım 1):
    A(p) ← p                              A(i) ← 1
p ← 2 .. √N (adım 1):                 i ← 2 .. N (adım 1):
    A(p) ≠ 0 ise:                         A(i) = 1 ise:
        J ← P*P                               J ← i .. (i*J < N) (adım 1):
        J < N olduğu sürece:                      A(i*J) ← 0
            A(J) ← 0
            J ← J+P
A yaz                                 A yaz
STOP                                  STOP
```

Sol akış sözde kodun birebir karşılığıdır. Sağ akışta ise dizinin gözlerine sayının kendisi yerine 1 (doğru, "asaldır") yazılır, çünkü indis zaten sayının kendisidir. İç döngü $i \cdot j < N$ olduğu sürece $A(i \cdot j)$'yi sıfırlar; bu da dolaylı olarak karekökle sınırlıdır. Hoca, gözlerde yalnız doğru/yanlış tutulduğu için bunun bit operatörleriyle gerçeklenebileceğini ve böylece her göz için bir tamsayı yerine bir bit kullanılarak 8-16 kat daha az yer kaplanabileceğini söyledi. Sayı tutan sürüm ise gözle takip etmek ve anlamak için daha kolaydır.

> **Hocanın vurgusu:** Aynı çözüm yöntemi için birden fazla akış ve gerçekleme tasarlanabilir. Biri anlatması ve anlaması daha kolay olur, diğeri daha hızlı ya da daha az yer kaplayan biçimde kurgulanır. Bazen çalışılan ortama özel iyileştirmeler bile yapılabilir.

### 6.7 Ara Toparlama

Hoca o ana kadarki kısmı şöyle bağladı: bir problemi önce okulda öğrendiğimiz ya da ilk aklımıza gelen yöntemle çözdük, sonra adımlarda ne yapacağımızı biraz daha düşünerek algoritmik çözümler ürettik. OBEB'de ortaokul yöntemi yerine Öklid'in yaklaşık 2300 yıllık yöntemini, asal sayılarda geriye dönük bölme yerine ileriye doğru eleme yapan Eratosthenes'in eleğini kullandık. Algoritmanın doğruluğu matematiksel olarak da gösterilmelidir: OBEB'de sayılar mod ile küçülerek sıfıra iner, yani problem yakınsar ve sonlu bir sonucu vardır. Bu gösterilemiyorsa yöntem bir algoritma değildir.

## 7. Sıralama Problemi

Hoca, öğrencilerin daha önce gördüğü sıralama algoritmalarına bu kez "her adımda nasıl bir küçük işlem yapıyor, sonuca nasıl yakınsıyor" gözüyle bakmak istediğini söyledi.

Önce problem formal olarak tanımlanır, yani girdi, çıktı ve her adımda yapılacak işlemler belirlenir (ekrandan, 01:30:00):

- **Girdi:** $\{a_1, a_2, \dots, a_n\}$ sayı dizisi.
- **Çıktı:** Girdinin öyle bir $\{a'_1, a'_2, \dots, a'_n\}$ permütasyonu ki $a'_1 \le a'_2 \le \dots \le a'_n$ olsun.

Bu tanım her elemanın kendinden sonra gelenlerin hepsinden küçük ya da onlara eşit olmasını garanti eder.

**Örnek:** Girdi `8 2 4 4 4 9 3 6`. Üç 4'ü ayırt etmek için renklendirelim: birincisi siyah, ikincisi kırmızı, üçüncüsü turuncu (hoca sözlü olarak "sarı" dedi). Beklenen sıralı çıktı `2 3 4 4 4 6 8 9`'dur. Slaytta üç çıktı gösterildi:

- `2 3 4(siyah) 4(kırmızı) 4(turuncu) 6 8 9`: 4'ler girdideki sırasını korur.
- `2 3 4(kırmızı) 4(turuncu) 4(siyah) 6 8 9`
- `2 3 4(kırmızı) 4(siyah) 4(turuncu) 6 8 9`

Tanım "sıra önemlidir" demediği için üç çıktı da doğrudur; hepsi küçük-eşit şartını sağlar. Eşit değerlerin girdideki sırasının çıktıda korunması önemliyse, bu probleme eklenen yeni bir kısıttır. Hoca, bu durumda bazı sıralama algoritmalarının kullanılamaz hale geleceğini söyledi: sıra önemli değilse örneğin quicksort kullanılabilir, sıranın korunması isteniyorsa quicksort kullanılamaz ve başka algoritmalara bakmak gerekir.

> **Hocanın vurgusu:** Sıralama gibi basit görünen bir problem bile kendi içinde varyasyonlar taşır ve bu varyasyonlar algoritmik çözümü doğrudan etkiler. Çözüm, verilen kısıt kümesine göre seçilmelidir.

> **Ek bilgi (derste anlatılmadı):** Eşit anahtarlı elemanların göreli sırasını koruyan sıralama algoritmalarına kararlı (stable) sıralama denir. Insertion Sort ve Merge Sort kararlıdır; Selection Sort'un ve Quicksort'un yaygın gerçeklemeleri kararlı değildir.

## 8. Selection Sort (Seçmeli Sıralama)

### 8.1 Mantık

Selection Sort bir kaba kuvvet yöntemidir (ekrandan, 01:35:00):

- Her iterasyonda en küçük (ya da büyükten küçüğe sıralanıyorsa en büyük) eleman seçilir ve baştan başlayarak yerleştirilir.
- Kalan elemanların en küçüğü seçilir ve takip eden sıraya yerleştirilir.

10 elemanlı bir dizide önce 10 elemanın hepsine sırayla bakılır ve en küçüğü bulunur (örneğin 6. gözde). Bu eleman 0. göze taşınır; 0. gözdeki eleman kaybolmasın diye onun yerine konur (yer değiştirme). Artık en küçük elemanın yeri garantilidir. Kalan 9 elemanda yine minimum aranır ve 1. göze konur; sonra 8 eleman, 7 eleman... Tek eleman kalınca onun da yerinde olduğu bilinir, çünkü diğer hepsiyle karşılaştırılmış ve onlar daha önce yerlerine atanmıştır. Arama uzayı her adımda küçüldüğü için algoritmanın sonlanacağı ve sıralamayı garanti edeceği bellidir.

### 8.2 Sözde Kod ve Maliyet

Slayttaki sözde kod (ekrandan, 01:40:00):

```text
for i ← 0 to n-1 do
   min ← i
   for j ← (i + 1) to n do
      if A[j] < A[min]
         min ← j
   tmp ← A[i]
   A[i] ← A[min]
   A[min] ← tmp
```

- **Kaç karşılaştırma?** $N^2/2$. Dış döngü 0'dan $n$'e, iç döngü $i+1$'den $n$'e gittiği için arama uzayı sürekli daralır; ortalama olarak yarısı kadar düşünülebilir. Dizi hangi halde olursa olsun bu sayıda `if` karşılaştırması yapılır.
- **Kaç yer değiştirme?** $N$. Yer değiştirme yalnız dış döngüye bağlıdır; her biri üç atama demektir, yani toplam $3N$ atama.

> **Ders sonrası not:** Slayttaki iç döngü `for j ← (i + 1) to n` biçimindedir. 0 tabanlı bir dizide son indis $n-1$ olduğu için doğrusu büyük olasılıkla `to n-1`'dir. Hoca örnekte dış döngünün $n-2$'ye ($i = 8$) kadar gitmesinin yeterli olduğunu da söyledi. Tam karşılaştırma sayısı $n(n-1)/2$'dir; $n = 10$ için 45.

Hoca burada maliyet türlerine dikkat çekti. Yer değiştirme, bellek ya da disk erişimi anlamına gelir ve $n$ çok büyükse önemli hale gelir. Toplamda daha performanslı görünen ama $n^2$ mertebesinde yer değiştirme yapan bir algoritma, sürekli disk erişimi gerektiren bir ortamda Selection Sort'tan daha kötü sonuç verebilir. O zaman yalnız $N$ yer değiştirme yapan Selection Sort daha kârlı olur.

> **Hocanın vurgusu:** Hangi algoritmanın nerede kullanılacağına, ortama ve veri boyutuna, hangi maliyetin daha kısıtlayıcı olduğuna göre karar vermek gerekir.

### 8.3 Örnek: `8 5 2 6 9 3 1 4 0 7`

Hoca 10 elemanlı, tekrarsız bir dizi üzerinde adım adım gösterdi (ekrandan, 01:45:00). Her satırda $i$, o turda bulunan minimumun indisi ve takastan önceki dizi verilmiştir:

| $i$ | min indisi | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| | | 8 | 5 | 2 | 6 | 9 | 3 | 1 | 4 | 0 | 7 |
| 0 | 8 | 8 | 5 | 2 | 6 | 9 | 3 | 1 | 4 | **0** | 7 |
| 1 | 6 | 0 | 5 | 2 | 6 | 9 | 3 | **1** | 4 | 8 | 7 |
| 2 | 2 | 0 | 1 | **2** | 6 | 9 | 3 | 5 | 4 | 8 | 7 |
| 3 | 5 | 0 | 1 | 2 | 6 | 9 | **3** | 5 | 4 | 8 | 7 |

- $i = 0$: Minimum önce 8, sonra 5, sonra 2, sonra 1, en son 0 olarak güncellenir. Minimum 8. indisteki 0'dır. 0 ile 8 yer değiştirir. 0 artık global minimumdur, ona bir daha bakılmaz.
- $i = 1$: 5 ile başlanır; 2, sonra 1 bulunur. Minimum 6. gözdeki 1'dir; 1 ile 5 yer değiştirir. Hoca, karşılaştırma sayısının 10, 9, 8, ... diye azaldığını ve $N^2/2$'nin buradan da görülebileceğini söyledi.
- $i = 2$: 2'den küçük eleman yoktur; 2 kendisiyle yer değiştirir. Hoca, "ne kadar ilginç, ama yine de bu swap'ı yapmak gerekti" diyerek $N$ yer değiştirmenin nedenini gösterdi.
- $i = 3$: Minimum 5. gözdeki 3; 3. ve 5. gözler yer değiştirir.
- $i = 4$: Minimum 7. gözdeki 4; 4. ve 7. gözler yer değiştirir.
- $i = 5$: Minimum 6. gözdeki 5; 5. ve 6. gözler yer değiştirir.
- $i = 6$: Minimum 6. gözdeki 6; kendisiyle yer değiştirir. Hoca burada "aynıysa değiştirme" diye bir iyileştirme yapılabileceğini, ama bunun da bir kontrol maliyeti getireceğini söyledi.
- $i = 7$: Kalan 9, 8, 7 içinde minimum 7 (9. indis); 7. ve 9. indisler yer değiştirir.
- $i = 8$: Kalan iki elemanın minimumu 8; kendi gözüne atanır.

Son eleman (9) kalanların minimumu, yani global maksimumdur ve yerindedir. Sonuç: `0 1 2 3 4 5 6 7 8 9` (python ile doğrulandı). Karşılaştırma sayısı üçgen biçiminde azaldığı için $N^2/2$, yer değiştirme sayısı $N$'dir.

## 9. Bubble Sort (Kabarcık Sıralama) ve Shell Sort

### 9.1 Mantık ve Sözde Kod

Hoca Selection Sort'un "körlemesine" işleyişini biraz daha hareketlendirmek, her adımda diziyi biraz daha sıralı hale getirmek ve yer değiştirmelerden kâr etmek için Bubble Sort'u tanıttı (ekrandan, 01:50:00):

- Dizi elemanlarını baştan sona iki iki karşılaştır, büyük olanı sona taşı.
- En büyük eleman kabarcık gibi dizinin en sonuna doğru taşınır.

Hoca bunu gazlı içecekteki kabarcıkların alttan yukarı çıkmasına benzetti: en büyük eleman "fokur fokur" dizinin sonuna doğru ilerler.

```text
for i ← 0 to n − 2 do
   for j ← 0 to n − 2 − i do
      if A[j + 1] < A[j]
         tmp ← A[j]
         A[j] ← A[j + 1]
         A[j + 1] ← tmp
```

İkişer ikişer bakıldığı için dış döngü $n-2$'ye kadar gider. İç döngünün üst sınırı $n-2-i$ olduğu için karşılaştırmalar sona doğru azalır. İki iç içe döngü ve bir `if` olduğu için karmaşıklık $O(n^2)$'dir. Hoca, Selection Sort'un da $n^2$ mertebesinde karşılaştırma yaptığı için $O(n^2)$ olduğunu ekledi.

### 9.2 Örnek: `8 5 2 6 9 3 1 4 0 7`

**$i = 0$:** 8 ile 5 karşılaştırılır; 8 büyük olduğu için yer değiştirirler. Hoca, bu aşamada 5'in en küçük eleman olduğunun garanti edilmediğini, yalnız 5 ve 8'in kendi aralarında sıralandığını vurguladı. Sonra 8 ile 2, 8 ile 6 yer değiştirir. 8 ile 9 karşılaştırılınca yer değiştirme olmaz: 8 taşınabildiği kadar taşınmıştır, "bayrağı" artık 9 devralır. 9 sırayla 3, 1, 4, 0 ve 7 ile yer değiştirerek sona gider. Tur sonu: `5 2 6 8 3 1 4 0 7 9`. 8 de daha ilk turda 0. gözden 3. göze kadar taşınmıştır.

**$i = 1$:** Son eleman (9) artık hariç tutulur. 5 ile 2 yer değiştirir; 5 ile 6, 6 ile 8 yer değiştirmez; 8 sırayla 3, 1, 4, 0, 7 ile yer değiştirir. Tur sonu: `2 5 6 3 1 4 0 7 8 9`.

**$i = 2$:** Son iki eleman hariç (ekrandan, 02:10:00). 2-5 ve 5-6 yer değiştirmez; hoca, ilerleyen turlarda yer değiştirmeden kâr edilmeye başlandığını gösterdi. 6 sırayla 3, 1, 4, 0 ile yer değiştirir; 6 ile 7 yer değiştirmez. Tur sonu: `2 5 3 1 4 0 6 7 8 9`.

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|
| **2** | **5** | 6 | 3 | 1 | 4 | 0 | 7 | 8 | 9 |
| 2 | **5** | **6** | 3 | 1 | 4 | 0 | 7 | 8 | 9 |
| 2 | 5 | **6** | **3** | 1 | 4 | 0 | 7 | 8 | 9 |
| 2 | 5 | 3 | **6** | **1** | 4 | 0 | 7 | 8 | 9 |
| 2 | 5 | 3 | 1 | **6** | **4** | 0 | 7 | 8 | 9 |
| 2 | 5 | 3 | 1 | 4 | **6** | **0** | 7 | 8 | 9 |
| 2 | 5 | 3 | 1 | 4 | 0 | **6** | **7** | 8 | 9 |

(Kalın: o adımda karşılaştırılan çift. 8 ve 9 bu turda artık hariç tutulan, yeri garantili elemanlardır.)

Hoca burada bir optimizasyon fikri de verdi: bir turun son karşılaştırmasında yer değiştirme olmadıysa dış döngü bir adım daha ileri alınabilir. Kendisi örnekte adım adım ilerlemeyi sürdürdü.

**$i = 3$:** `2 3 1 4 0 5 6 7 8 9`. 5 sağa kayarak yerini bulur.
**$i = 4$:** `2 1 3 0 4 5 6 7 8 9`. 3-4 karşılaştırmasında yer değiştirme olmaz.
**$i = 5$:** `1 2 0 3 4 5 6 7 8 9`.
**$i = 6$:** `1 0 2 3 4 5 6 7 8 9`.
**$i = 7$:** `0 1 2 3 4 5 6 7 8 9`.
**$i = 8$:** 0 ile 1 karşılaştırılır, yer değiştirmez (ekrandan, 02:15:00). Tek eleman kalır; o, sola doğru itilmiş olan en küçük elemandır.

Tur sonları python ile doğrulandı; bu örnekte toplam 28 yer değiştirme yapılır. Her dış turda kalanların en büyüğü sona itilir ve iç döngünün $n-2-i$'ye kadar gitmesi bunu garanti eder.

Hoca, karşılaştırma sayısının sabit olduğunu ($N^2/2$ mertebesi), yer değiştirme sayısının ise girdiye, "biraz şansa" bağlı olduğunu söyledi. Selection Sort'ta garantili $N$ yer değiştirme vardı; Bubble Sort'ta küçükleri sola, büyükleri sağa mümkün olduğunca taşıyarak sona doğru daha az yer değiştirme yapılması amaçlanır.

> **Ek bilgi (derste anlatılmadı):** Bubble Sort'un yaygın iyileştirmesi, bir dış turda hiç yer değiştirme olmazsa dizinin sıralı olduğunu anlayıp algoritmayı erken bitirmektir. Bu sürümde zaten sıralı bir dizi için tek turda $n-1$ karşılaştırmayla bitirilir.

### 9.3 Shell Sort (Yalnız Sözlü)

Hoca Bubble Sort'un bir ilerlemesi olarak Shell Sort'tan (kabuk sıralama) sözlü olarak bahsetti. Bubble Sort hep komşu elemanları (0-1, 1-2, 2-3) karşılaştırır. Shell Sort ise farklı aralıklar (interval) tanımlayarak daha uzaktaki elemanları karşılaştırır. Böylece her dış turda tek bir küçük-büyük ayrımı yapmak yerine mümkün olduğunca çok küçük sayıyı başa, çok büyük sayıyı sona taşır; bu iş parçalara (partition) bölünerek yapılır. Amaç, sonlarda daha az değişiklik yapma şansını artırmaktır. Hoca öğrencilerin algoritmayı incelemesini, akış diyagramını ya da sözde kodunu yazıp bir dizi üzerinde atama ve karşılaştırma sayılarını analiz etmesini önerdi.

## 10. Insertion Sort (Eklemeli Sıralama)

### 10.1 Mantık

Insertion Sort, azalt ve yönet yapısında çalışır. Hoca bunu iskambil kağıtlarını elde sıralamaya benzetti (ekrandan, 02:20:00):

- Eklemeli Sıralama (Insertion Sort).
- İskambil kağıtlarını elimizde sıralar gibi bir algoritma.
- Sıradan bir yeni eleman al, önceki sıralı kısım ile karşılaştırarak olması gereken yere taşı.

Desteden her adımda bir kart kaldırılır ve elde daha önce sıralanmış kısımla karşılaştırılır. Karşılaştırma baştan sona değil, sondan başa doğru yapılır. Kartın yeri bulununca ondan küçük olan soldaki kartlarla daha fazla karşılaştırma yapılmaz. Slayttaki örnekte elde 2, 4, 5 sıralıdır. Sıradaki 7 alınınca 5'in hemen sağına konur; 7'yi 4 ve 2 ile karşılaştırmaya gerek kalmaz. Sonra gelen 8, 7'nin yanına; 9, 10'un yanına konur. Böylece daha soldaki kartlarla karşılaştırmalardan kâr edilir.

Hoca, Insertion Sort'un yaklaşık $N^2/2$ karşılaştırma ve yaklaşık $N^2/2$ yer değiştirme yaptığını, ama dizi kısmen sıralıysa bu sayıların azaldığını söyledi. Özellikle küçük dizilerde çok verimli çalıştığı bilinir.

### 10.2 Sözde Kod

<!-- BELİRSİZ: Insertion Sort sözde kodunun slaydı karelerde yok. Aşağıdaki yapı altyazıdaki sözlü anlatıma ve adım tablosuna göre kuruldu; slayttaki yazım farklı olabilir. -->

Hoca sözde kodu akış diyagramına çevirmedi, öğrencilerin bunu kolayca yapabileceğini söyledi. Anlatıma göre yapı şöyledir:

- $i$, 1'den $n-1$'e kadar gider; $i$. göz anahtar (key) olarak alınır. Bu, desteden bir kartı ele almak demektir.
- $j$, $i-1$'den başlar. $j \ge 0$ olduğu ve $A[j]$ anahtardan büyük olduğu sürece $A[j]$ bir sağa kaydırılır ve $j$ bir azaltılır.
- Döngü bitince anahtar $A[j+1]$'e yazılır; kart araya sokulmuş olur.

### 10.3 Örnek: `8 5 2 6 9 3 1 4 0 7`

Slayttaki adım tablosu (ekrandan, 02:35:00). Her satır, o $(i, j)$ adımından sonraki diziyi gösterir:

| $i$ | $j$ | Key | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| | | | 8 | 5 | 2 | 6 | 9 | 3 | 1 | 4 | 0 | 7 |
| 1 | 0 | 5 | 8 | 5 | 2 | 6 | 9 | 3 | 1 | 4 | 0 | 7 |
| 1 | -1 | 5 | 5 | 8 | 2 | 6 | 9 | 3 | 1 | 4 | 0 | 7 |
| 2 | 1 | 2 | 5 | 8 | 2 | 6 | 9 | 3 | 1 | 4 | 0 | 7 |
| 2 | 0 | 2 | 5 | 2 | 8 | 6 | 9 | 3 | 1 | 4 | 0 | 7 |
| 2 | -1 | 2 | 2 | 5 | 8 | 6 | 9 | 3 | 1 | 4 | 0 | 7 |
| 3 | 2 | 6 | 2 | 5 | 8 | 6 | 9 | 3 | 1 | 4 | 0 | 7 |
| 3 | 1 | 6 | 2 | 5 | 6 | 8 | 9 | 3 | 1 | 4 | 0 | 7 |
| 4 | | 9 | 2 | 5 | 6 | 8 | 9 | 3 | 1 | 4 | 0 | 7 |
| 5 | | 3 | 2 | 3 | 5 | 6 | 8 | 9 | 1 | 4 | 0 | 7 |
| 6 | | 1 | 1 | 2 | 3 | 5 | 6 | 8 | 9 | 4 | 0 | 7 |
| 7 | | 4 | 1 | 2 | 3 | 4 | 5 | 6 | 8 | 9 | 0 | 7 |
| 8 | | 0 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 8 | 9 | 7 |
| 9 | | 7 | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |

Adımların anlatımı:

- **$i = 1$, key = 5:** Elde tek kart (8) var ve tek eleman olduğu için sıralıdır. 5 ile 8 karşılaştırılır; 8 sağa kayar, 5 başa konur. $j$, $-1$'e düşer ve `while` şartı ($j \ge 0$) bozulduğu için döngüden çıkılır. `5 8` sıralıdır.
- **$i = 2$, key = 2:** 2, 8'den küçük, 8 sağa kayar; 2, 5'ten de küçük, 5 sağa kayar. $j = -1$ olunca durulur. `2 5 8` sıralıdır.
- **$i = 3$, key = 6:** 6, 8'den küçük, 8 kayar. 6 ile 5 karşılaştırılınca 5 daha küçük olduğu için durulur. Hoca, burada 2 ile karşılaştırmaktan kurtulduğumuzu vurguladı. `2 5 6 8`.
- **$i = 4$, key = 9:** 9, 8'den büyük; tek karşılaştırmayla yerinde olduğu anlaşılır. 6, 5 ve 2 ile karşılaştırmaktan kurtulunur (3 karşılaştırma kâr). `2 5 6 8 9`.
- **$i = 5$, key = 3:** 9, 8, 6, 5 ile karşılaştırılıp her biri kaydırılır; 2 ile karşılaştırılınca durulur. 4 kaydırma, 5 karşılaştırma; maliyet bu kez yüksektir.
- **$i = 6$, key = 1:** Hepsinden küçük olduğu için 9, 8, 6, 5, 3, 2 ile karşılaştırılıp her biri kaydırılır ve 1 en başa gelir. Hoca bunu "talihsiz durum" diye niteledi: küçük bir değer dizinin sonlarındaydı.
- **$i = 7$, key = 4:** 9, 8, 6, 5 kaydırılır; 3 ile karşılaştırılınca durulur. 3, 2 ve 1 ile karşılaştırmaktan kurtulunur.
- **$i = 8$, key = 0:** En kötü durum: en küçük değer sona yakındır. 9, 8, 6, 5, 4, 3, 2, 1 hepsiyle karşılaştırılıp kaydırılır. Bu adımda hiç kâr yoktur.
- **$i = 9$, key = 7:** Yalnız 9 ve 8 kaydırılır; 6 ile karşılaştırılınca durulur. Soldaki 7 değerle karşılaştırmaktan kurtulunur.

Bu örnekte toplam 33 karşılaştırma ve 28 kaydırma yapılır (python ile sayıldı). Hoca, tablonun sol tarafındaki üçgene bakarak toplam atama ve yer değiştirme sayılarının hesaplanabileceğini söyledi.

### 10.4 Ne Zaman İyi, Ne Zaman Kötü?

Dizi kendi içinde ters sıralıysa Insertion Sort her elemanı en başa kadar kaydırmak zorunda kalır; yaklaşık $N^2/2$ karşılaştırma ve yer değiştirme yapılır. Dizi ne kadar küçük sıralı parçalar içeriyorsa o kadar çok karşılaştırmadan kurtulunur.

> **Hocanın vurgusu:** Bir yere kadar başka bir sıralama algoritması kullanıp az eleman kalınca Insertion Sort'u devreye sokmak, toplam sıralama performansını artırır; bu bilinen bir gerçektir.

Hoca bunu günlük bir örnekle bağladı: sıralı bir kitap listesi yere düşüp karıştıysa, ama hâlâ küçük sıralı parçalar içeriyorsa, Insertion Sort burada iyi çalışır. Çözümler her problemin kendi doğasına ve veri uzayına göre kurgulanmalıdır.

### 10.5 Dört Algoritmanın Toparlaması

Hoca Selection, Bubble, Shell (sözlü) ve Insertion Sort'u şu sorularla bağladı: karşılaştırma mı daha önemli, yer değiştirme mi? Her adımda yer değiştirmeler nasıl azaltılabilir? Dizi kısmen sıralıysa bundan nasıl yararlanılabilir? Selection Sort her durumda $N^2/2$ karşılaştırma ve $N$ yer değiştirme yapar. Bubble Sort'ta karşılaştırma sayısı sabit, yer değiştirme girdiye bağlıdır. Insertion Sort kısmen sıralı dizilerde hem karşılaştırmadan hem kaydırmadan tasarruf eder.

## 11. Soru-Cevap: Derlenen ve Yorumlanan Diller

**Soru:** Geçen hafta C'nin yorumlanan değil derlenen bir dil olduğunu söylemiştiniz. Derleme ve yorumlamadan kastınız nedir?

**Cevap:** Programlama dilleri genel olarak ikiye ayrılır: derlenen diller ve yorumlanan diller.

- **Derlenen dillerde** bir derleyici vardır. Derleyici, yazılan kaynak kod dosyasını ve kullanılan kütüphaneleri (örneğin `stdio.h`, `stdlib.h` başlıklarıyla eklenen) ve onların kullandığı başka fonksiyonları alır, bütün kaynak kodu bir ara koda çevirir. Sonra bağlayıcı (linker) bunları birleştirir: fonksiyon çağrıları, bağlantılar, bellekte tutulacak yapılar ve adres tablosu hazırlanır. Sonuç, hedef işlemcinin çalıştırabileceği komut setinde, yani makine dilinde tek bir çalıştırılabilir (executable) dosyadır; Windows'ta `.exe` uzantılıdır. Fonksiyon çağrıları ve atamalarla ilgili birçok hata en baştan kontrol edildiği için, düzeltildikten sonra doğru çalışacağı garanti edilmiş bir ürün elde edilir.
- **Yorumlanan dillerde** derleme zamanında (compile time) böyle bir makine diline çevirme yapılmaz. Kod çalışma anında satır satır işletilir. Örneğin bir değer okunduktan sonra karekök fonksiyonu çağrılacaksa, yorumlayıcı o satıra geldiğinde kütüphaneyi ve fonksiyonu bulur, çalıştırır ve sonucu döndürür. Bir hata varsa ancak o satıra gelince fark edilir.

Hoca, bir öğrencinin sohbette paylaştığı makalenin C dosyalarının GCC ile nasıl nesne dosyalarına çevrildiğini, nasıl bağlandığını ve işlemci mimarisine uygun makine koduna nasıl dönüştürüldüğünü ayrıntılı anlattığını belirtti.

## 12. Derse Çalışma Önerileri

Hoca derse çalışma yöntemi olarak şunları önerdi:

- Derste anlatılan algoritmaların ve kodların üzerinden mutlaka geçin; kendiniz yazın, kodlayın, değiştirin.
- Farklı girdilerle nasıl davrandığını analiz edin; her adımda ara durumları yazdırarak algoritmanın nasıl çalıştığını gözlemleyin.
- Kaynak kitapların (hoca Sedgewick, Cormen ve Levitin'i andı) bölüm sonu sorularını çözün. Önce kendiniz deneyin, yapamazsanız internetteki hazır çözümlere bakıp anlamaya çalışın.
- Yarışma ve işe alım sitelerindeki algoritma sorularıyla algoritmik düşünme becerinizi geliştirin.

> **Hocanın vurgusu:** Hep körlemesine arama ya da hep Selection Sort yazılabilir; önemli olan bir mühendis olarak duruma göre en uygun çözümü önerebilmektir. Karşılaştırma mı yoksa bellek erişimi mi daha maliyetli, buna göre ince ayar yapmak gerekir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:37:39): Ortaokulda öğretilen OBEB yöntemi (iki sayıyı asal çarpanlarına ayır, ortak çarpanları bul, çarp) bir algoritma mıdır? Neden?

> **Cevap (derste verildi):** Hayır. "Asal çarpanları bul" adımının nasıl yapılacağı tanımlanmamıştır; "ortak çarpanları bul" adımı kendi başına bir algoritmik problemdir (kümelerin kesişimi). Adımlar kesin ve net olmadığı için bu bir algoritma sayılmaz.

**Soru 2** (ekrandan, 00:40:00): $\gcd(m,n) = \gcd(n, m \bmod n)$ kuralıyla $\gcd(60, 24)$ ve $\gcd(1785, 546)$ değerlerini bulunuz.

> **Çözüm (derste verildi):** $60 \bmod 24 = 12$, $24 \bmod 12 = 0$, sonuç 12. $1785 \bmod 546 = 147$, $546 \bmod 147 = 105$, $147 \bmod 105 = 42$, $105 \bmod 42 = 21$, $42 \bmod 21 = 0$, sonuç 21.

**Soru 3** (ekrandan, 00:50:00): $N$'e kadar olan tüm asal sayıları "efektif olarak" nasıl bulabiliriz?

> **Cevap (derste verildi):** Her sayıyı önceki asallara bölmeye çalışmak yerine Eratosthenes'in eleği kullanılır: her asalın katları $p^2$'den başlayarak ileriye doğru silinir ve bu yalnız $\lfloor\sqrt{N}\rfloor$'e kadar olan $p$'ler için yapılır. Silinmeden kalan sayılar asaldır.

**Soru 4** (derste sözlü, 01:10:08): 100'e kadar elekte 2, 3 ve 5'in katları silindikten sonra 7'nin henüz silinmemiş hangi katları kalmıştır?

> **Cevap (derste verildi):** 49, 77 ve 91.

**Soru 5** (derste sözlü, 01:13:17): 100'e kadar elekte 11'e gelince neden durduk, 11'in katlarına neden bakmadık?

> **Cevap (derste verildi):** 11'in 121'den küçük katları ($22, 33, 55, \dots$) daha küçük asalların katı olduğu için zaten silinmiştir. Silinmemiş olabilecek ilk kat $11^2 = 121$'dir ve 100'ün dışındadır. Bu yüzden $\sqrt{100} = 10$'a kadar gitmek yeterlidir.

**Soru 6** (ekrandan, 01:40:00): Selection Sort $N$ elemanlı bir dizide kaç karşılaştırma ve kaç yer değiştirme yapar?

> **Cevap (derste verildi):** Yaklaşık $N^2/2$ karşılaştırma (dizinin durumundan bağımsız) ve $N$ yer değiştirme. Tam karşılaştırma sayısı $N(N-1)/2$'dir (ara adım eklendi).

**Soru 7** (ekrandan, 01:45:00, 02:10:00, 02:35:00): `8 5 2 6 9 3 1 4 0 7` dizisini Selection Sort, Bubble Sort ve Insertion Sort ile adım adım sıralayınız.

> **Çözüm (derste verildi):** Ayrıntılı adımlar 8.3, 9.2 ve 10.3 bölümlerindeki tablolardadır. Python ile sayıldığında Bubble Sort bu dizide 28 yer değiştirme, Insertion Sort 33 karşılaştırma ve 28 kaydırma yapar.

## Dersin Toparlaması

Bu derste algoritmik problem çözmenin ne olduğu örneklerle gösterildi. Sıralı bir kelime kümesinde sırayla arama ile ikili arama arasındaki fark (yaklaşık bir hafta ile yarım dakika), algoritma tasarımının neden donanım yatırımından daha etkili olabileceğini gösterdi. Ardından kaba kuvvet, açgözlü, böl ve yönet, azalt ve yönet, değiştir ve yönet gibi tasarım teknikleri tanıtıldı. OBEB probleminde muğlak adımlı ortaokul yöntemi ile kesin ve sonlu Öklid algoritması, asal sayı probleminde geriye dönük bölme denemesi ile ileriye doğru eleme yapan Eratosthenes'in eleği karşılaştırıldı. Aynı algoritmanın farklı akışlarla, hatta bit düzeyinde yer tasarrufu yapacak biçimde gerçeklenebileceği görüldü.

Son bölümde sıralama problemi formal olarak tanımlandı ve eşit elemanların sırasının korunması gibi kısıtların algoritma seçimini etkilediği vurgulandı. Selection, Bubble ve Insertion Sort aynı dizi üzerinde adım adım izlenerek karşılaştırma ve yer değiştirme sayıları açısından değerlendirildi; Shell Sort sözlü olarak tanıtıldı. Hoca, algoritmaların karmaşıklığını nasıl analiz edeceklerini bir sonraki hafta göreceklerini, Eratosthenes'in eleği gibi algoritmaların analizine o zaman döneceklerini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
