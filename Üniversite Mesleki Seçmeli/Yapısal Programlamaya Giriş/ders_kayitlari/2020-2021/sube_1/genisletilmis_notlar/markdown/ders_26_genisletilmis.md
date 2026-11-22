# Ders 26 Genişletilmiş Notu: Kumarbaz Simülasyonu, Matris Çarpım Sırası, Harici Birleştirmeli Sıralama ve Sezgisel Algoritmalar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Monte Carlo benzetimi: kumarbaz problemi
- 2. Tek bir oyunun benzetimi
- 3. K oyunun benzetimi ve kazanma oranı
- 4. Sonuçlar ve "kasa her zaman kazanır"
- 5. Matris çarpımı ve karmaşıklığı
- 6. Matris çarpım sırası
- 7. Harici birleştirmeli sıralama (external merge sort)
- 8. Yüksek karmaşıklıklı problemler
- 9. Sezgisel algoritmalar ve gezgin satıcı
- Örnek Sorular
- Dersin Toparlaması

Bu kayıt dönemin son dersidir. Hoca dersi birkaç farklı problemin analizine ve çözümüne ayırdı: bir olasılık probleminin programla benzetimi, matris çarpımının maliyeti, RAM'e sığmayan verinin sıralanması ve çok yüksek karmaşıklıklı problemlerde sezgisel yaklaşımlar. Bütün anlatım çevrim içi beyaz tahtada el yazısı ve akış diyagramlarıyla yapıldı.

## 1. Monte Carlo benzetimi: kumarbaz problemi

Hoca ilk konuyu "Monte Carlo, kumar şehrine gidiyoruz" diye açtı. Problemde bir kumarbaz vardır. Her oyunda kumarbaz $p$ olasılıkla 1 TL kazanır, $1-p$ olasılıkla 1 TL kaybeder (ekrandan, 00:10:00). Tek bir oyun yalnız 1 lira kazandıran ya da kaybettiren basit bir oyundur.

Ancak oyun bir kez oynanıp bitmez. Kumarbaz oyuna $n$ lira ile girer. Çıkışta iki olasılık vardır: ya parası $m+n$ lira olur ve evine gider, ya da parası 0 olur ve öyle gider. Bu iki durumdan biri gerçekleşene kadar oynamaya devam eder. Başta $n$ lirası varken bir oyundan sonra $n+1$ ya da $n-1$ lirası olur; bir oyun daha oynayınca olasılıklar dallanarak ilerler. Burada $m$, kumarbazın parasını ne kadar artırmak istediğidir.

Sorulan şey kumarbazın $m+n$ lira ile evine gitme olasılığıdır. Hoca bu olasılığın $p$'ye, $n$'ye ve $m$'ye bağlı olabileceğini söyledi. Amaç formülü bulmak değil, süreci programla tekrar tekrar çalıştırıp kazanma oranını bulmaktır. Örneğin "$n$ ile gir, ya 0 ya $m+n$ ile çık" süreci 10.000 kez tekrar edilir; bunların kaçının $m+n$ ile bittiği sayılır ve oran ekrana yazdırılır. $m+n$ ile biten süreç bir kazanç, 0 ile biten bir kayıp sayılır. Hoca öğrencilere beş dakika düşünme süresi verdi ve "çok karmaşık bir şey değil, sadece küçük bir trik var" dedi.

## 2. Tek bir oyunun benzetimi

Hoca problemi bütün hâlinde çözmeden önce bir parçasını çözdü: tek bir oyunun, yani $n$ lira ile başlayıp $m+n$ ya da 0 ile biten tek bir sürecin benzetimi.

### 2.1 Girdiler ve değişkenler

Akış diyagramı START ile başlar ve kullanıcıdan $m$, $N$ ve $p$ okunur (ekrandan, 00:15:00). Tahtadaki açıklamalara göre $N$ girişteki para, $m$ ise artırılmak istenen değerdir.

Süreci görmek isteyebiliriz: oyunun başından sonuna kadar kumarbazın her adımda elinde kaç lira vardı? Bunun için `R` adlı bir dizi tutulur. Dizinin ilk elemanı $N$'dir. İkinci eleman $N+1$ ya da $N-1$ olabilir. Üçüncü eleman için hoca öğrencilere sordu: $N+1$'e varıldıysa oradan $N+2$'ye çıkılabilir ya da yeniden $N$'e inilebilir; $N-1$'deyken bir artarsa $N$, bir azalırsa $N-2$ olur (ekrandan, 00:20:00). Son eleman ise ya $m+N$ ya da 0'dır. Sürecin kaç adım süreceği baştan bilinemediği için dizi en büyük boyutla (`Rmax`) açılır. Dizinin indisi `t` ile tutulur ve $t = 0$ ile başlanır.

### 2.2 Döngü koşulu ve `h` değişkeni

Oyunun sürdüğünü ifade eden bir `while` döngüsü kurulur. Döngüden önce $h = m + N$ tanımlanır (ekrandan, 00:20:00). Döngü koşulu şudur: elimizdeki para $N$, $h$'den küçük olduğu ve $N$ sıfırdan büyük olduğu sürece oyun devam eder (`N < h && N > 0`).

Hoca $h$'yi neden ayrı bir değişken yaptığını açıkladı: eldeki parayı $N$ üzerinde değiştireceğiz. Koşulda doğrudan $m + N$ yazsaydık, $N$ her adımda güncellendiği için hedef de kayardı. Bu yüzden başlangıçtaki $m+N$ değeri bir kez $h$'ye atanır. Döngünün dışına çıkıldığı anda oyun bitmiştir: $N = 0$ ise kumarbaz 0 ile, $N = h$ ise $h$ ile çıkmıştır.

### 2.3 Rastgele sayı ile kazanma ve kaybetmenin benzetimi

Döngünün içinde oyun oynanır. Bunun için 0 ile 1 arasında rastgele değer üreten bir `rand` fonksiyonu kullanılır (ekrandan, 00:20:00). Hoca örnek olarak $p = 0.6$ aldı: kumarbaz 0.6 olasılıkla kazansın.

Karar kutusuna `rand() > p` yazılır. Hoca sordu: rastgele bir sayının $p$'den büyük olması hangi olasılıkla gerçekleşir? Öğrencilerin cevabı $1-p$ idi. Bu yüzden karar kutusunun doğru (T) tarafı kaybı temsil eder ve orada $N = N - 1$ yapılır; yanlış (F) tarafında ise $N = N + 1$ yapılır. Karar tamamlandıktan sonra $t = t + 1$ yapılır ve `R[t] = N` ile o anki para diziye yazılır. Ardından döngünün başına dönülür.

### 2.4 Sürecin görünümü ve bitmeme olasılığı

Döngüden çıkıldığında oyun ya kazanılmış ya kaybedilmiştir ve elimizde $1$'den $t$'ye kadar `R` dizisi vardır. Bu dizi çizdirilirse $N$'den başlayıp inip çıkan bir eğri görülür; bir oyunda eğri $m+N$'ye, başka bir oyunda 0'a varabilir. Oyunlar farklı adım sayılarında bitebilir.

Hoca kuramsal olarak oyunun hiç bitmeyebileceğini de sordu ve cevapladı: kumarbaz bir kazanıp bir kaybederse süreç sonsuza kadar sürebilir. Pratikte büyük olasılıkla sürmez, ama ihtimal dahilindedir.

## 3. K oyunun benzetimi ve kazanma oranı

Asıl soru, kumarbaz bu oyunu $K$ kez oynarsa kaçını kazanacağıdır; buradan bir oran ve olasılık çıkarılır. Bunun için kod biraz değiştirilir.

### 3.1 Akış diyagramı

Yeni diyagram BAŞLA ile başlar ve kullanıcıdan $m$, $n$, $p$ ve $K$ okunur; $K$ deneme sayısıdır (ekrandan, 00:25:00). Kaç kez kazanıldığını tutmak için `kaz` adlı bir değişken 0'a eşitlenir. Ardından $i = 1$'den $K$'ye birer artan bir `for` döngüsü açılır.

Döngünün içinde önceki tek oyun sürecinin tamamı tekrarlanır. Problemin "küçük triki" buradadır: her oyunun başında eldeki para yeniden başlangıç değerine çekilmelidir. $m$ zaten sabittir, ama eldeki para oyunda değişir ve bir oyun bittiğinde ya 0 ya da $m+n$ olur. Bu yüzden eldeki parayı tutan ayrı bir değişken kullanılır ve her oyunun başında $n$'ye eşitlenir; $n$ kendisi yedekte bekler.

<!-- BELİRSİZ: Eldeki parayı tutan değişkenin adı altyazıda net değil; tahtada "en" yazısı görülüyor, notta bu ad kullanıldı. -->

Sonra yine $h = m + n$ ile `while (en < h && en > 0)` döngüsü kurulur; içeride `rand() > p` doğruysa para bir azalır, yanlışsa bir artar. Bu sürümde süreci (`R` dizisini) tutmaya gerek yoktur. `while` bittiğinde sorulacak soru basittir: oyun kazanıldı mı? Eldeki para $h$'ye eşitse kazanılmıştır ve `kaz = kaz + 1` yapılır. `for` döngüsü bittiğinde `kaz / K` ekrana yazdırılır ve program biter.

### 3.2 C ile örnek uygulama

Aşağıdaki C kodu derste yazılmadı; tahtadaki akış diyagramından ajan tarafından çevrildi. Kod `gcc -Wall` ile uyarısız derlendi. `10 100 0.473 100000` girdisiyle (m, n, p, K) yaklaşık 0.340, `20 100 0.473 100000` girdisiyle yaklaşık 0.117 sonucu verdi; bunlar derste verilen 0.339 ve 0.115 değerleriyle uyumludur. `rand()` C'de 0 ile `RAND_MAX` arasında tamsayı döndürdüğü için 0-1 aralığına bölerek ölçeklendi.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int m, n, K, i, en, h, kaz;
    double p, r;

    srand((unsigned) time(NULL));
    printf("m, n, p, K: ");
    scanf("%d %d %lf %d", &m, &n, &p, &K);

    kaz = 0;
    h = m + n;
    for (i = 1; i <= K; i++) {
        en = n;                       /* her oyuna n lira ile girilir */
        while (en < h && en > 0) {
            r = (double) rand() / ((double) RAND_MAX + 1.0); /* [0,1) */
            if (r > p) {
                en = en - 1;          /* 1-p olasilikla kaybeder */
            } else {
                en = en + 1;          /* p olasilikla kazanir */
            }
        }
        if (en == h) {
            kaz = kaz + 1;
        }
    }
    printf("Kazanma orani: %f\n", (double) kaz / K);
    return 0;
}
```

### 3.3 $p$'nin etkisi

Hoca sordu: $p$ büyüdükçe `kaz / K` oranı ne olur? Öğrenciler oranın büyüyeceğini söyledi; hoca da kazanma olasılığı arttığı için oranın artacağını onayladı.

## 4. Sonuçlar ve "kasa her zaman kazanır"

### 4.1 $p = 0.473$ seçimi

Hoca deneyleri daha önce çalıştırmıştı ve $p$'yi sabit $0.473$ aldı (ekrandan, 00:30:00). Bu değerin kötü olup olmadığını sordu: bir şeyin iyi ya da kötü olduğu ancak bir referansa göre söylenebilir. $p = 0.1$'e göre $0.473$ oldukça iyidir, çünkü yarı yarıya yakındır; kumarhanelerdeki şans oyunları da buna benzer olasılıklarla çalışır. Hoca ayrıca, kazanılan ve kaybedilen paralar farklı olsaydı kazanç çarpı kazanma olasılığı ile kayıp çarpı kaybetme olasılığını oranlayarak normalleştirmek gerekeceğini, bu problemde ise iki tutar eşit (1 TL) olduğu için $p$'nin doğrudan kullanılabileceğini söyledi.

### 4.2 Deney tablosu

Tahtadaki tablo şöyledir (ekrandan, 00:50:00):

| $n$ | $m$ | kaz / K |
|---|---|---|
| 100 | 10 | 0.339 |
| 1000 | 10 | 0.341 |
| 100 | 20 | 0.115 |
| 200 | 20 | 0.114 |
| 1000 | 20 | 0.115 |
| 100 | 100 | 0.000018 |
| 1.000.000 | 100 | 0.0000201 |

<!-- BELİRSİZ: n=200, m=20 satırındaki değer tahtada 0.113 ya da 0.114 okunabiliyor; altyazıda 114 deniyor. -->

Örneğin ilk satırda kumarbazın 100 lirası vardır; oyundan ya 110 lira ya da 0 lira ile çıkacaktır ve 110 lira ile çıkma olasılığı 0.339 bulunmuştur. $n = 1000$, $m = 10$ için kumarbaz ya 1010 ya da 0 lira ile çıkar ve olasılık 0.341'dir, yani çok yakındır. $m = 100$ olduğunda, 100 lirası olan biri için 200 liraya çıkma olasılığı yalnız 0.000018'dir; 1 milyon lirası olan biri için 1 milyon 100 liraya çıkma olasılığı da 0.0000201'dir.

### 4.3 Yorum

Hoca sonuçlara bakarak ne söylenebileceğini sordu. Bir öğrenci, oyuna ne kadar parayla girildiğinin sonucu pek etkilemediğini söyledi. Hoca bu yorumu onayladı: 1 milyon liran olsa da 100 liran olsa da 100 lira kazanma olasılığın aynıdır. Önemli olan iki şey vardır: $m$ ve $p$. $p$'nin etkisi derste gösterilmedi, ama öğrencilerin programı kendileri çalıştırarak görebileceği söylendi.

Hoca matematiksel sonucu şöyle yazdı (ekrandan, 00:50:00):

$$\text{sonuç} \le \left(\frac{p}{1-p}\right)^m$$

Sonuç bu değerden küçük ya da ona yaklaşık eşittir. $m$ arttıkça bu ifade üstel olarak düşer. Hoca konuyu "Gambler's Dilemma" (kumarbazın ikilemi) adıyla aratmayı önerdi.

> **Hocanın vurgusu:** Kasa her zaman kazanır. Oyuna kaç parayla girdiğinizin hiçbir önemi yoktur. Aşırı şanslı ya da şanssız durumlar ayrıdır, ama ortalama durumda bu tür oyunları oynamanın matematiksel olarak hiçbir anlamı yoktur.

> **Ders sonrası not:** Bu problem literatürde büyük olasılıkla "Gambler's ruin" (kumarbazın iflası) adıyla bilinir. $r = (1-p)/p$ olmak üzere kesin olasılık $\dfrac{r^n - 1}{r^{n+m} - 1}$'dir. Python ile hesaplanan değerler $(100,10) \to 0.3392$, $(100,20) \to 0.1151$, $(200,20) \to 0.1151$, $(100,100) \to 0.0000202$'dir; tablodaki farklar (örneğin 0.000018) benzetimin rastlantı hatasından gelir. Üst sınır $(p/(1-p))^m$ yalnız $p < 0.5$ iken anlamlıdır; $p > 0.5$ olunca bu ifade 1'i geçer.

## 5. Matris çarpımı ve karmaşıklığı

Hoca bir önceki derste matris çarpımından söz edildiğini ama nasıl yapıldığının doğrudan gösterilmediğini söyledi ve kısaca kodunu kurdu. Asıl amaç buradan başka bir probleme geçmekti.

### 5.1 Algoritma

$A$ matrisi $n \times m$, $B$ matrisi $m \times p$ olsun. İki matrisin çarpılabilmesi için $A$'nın sütun sayısı ile $B$'nin satır sayısı eşit olmalıdır; sonuç $C$ matrisi $n \times p$ olur.

Akış diyagramında önce $A$ ve $B$ okunur. Sonra $i$ 1'den $n$'ye, onun içinde $j$ 1'den $p$'ye birer artan döngüler açılır. İçeride `sum = 0` yapılır ve $k$ 1'den $m$'ye değişen üçüncü döngüde `sum = sum + A[i][k] * B[k][j]` hesaplanır. $k$ döngüsü bitince `C[i][j] = sum` yazılır.

<!-- BELİRSİZ: Matris çarpımı akış diyagramının çizildiği an karelerde yok; algoritma yalnız sözlü anlatımdan aktarıldı. -->

### 5.2 Karmaşıklık

Üç iç içe döngü olduğu için en içteki satırdan $n \cdot p \cdot m$ kez geçilir; karmaşıklık $O(n \cdot m \cdot p)$'dir. İki matris de $n \times n$ kare matris olsaydı karmaşıklık $O(n^3)$ olurdu.

Hoca kare matrislerin çarpımı için daha iyi ama çok daha karmaşık algoritmalar olduğunu söyledi. Bunların karmaşıklığı $n^{2.xx}$ düzeyine, hocanın hatırladığı kadarıyla yaklaşık $n^{2.3}$'e kadar inmiştir. $n^2$'lik bir algoritma henüz yoktur; mevcut algoritmalar $n^2$'nin biraz üstünde, $n^3$'ün altındadır. Sonuç olarak matris çarpmak pahalı bir iştir.

> **Ek bilgi (derste anlatılmadı):** Bu alanda bilinen ilk algoritma büyük olasılıkla Strassen algoritmasıdır ve karmaşıklığı yaklaşık $O(n^{2.81})$'dir. Sonraki çalışmalar üst sınırı büyük olasılıkla $O(n^{2.37})$ civarına indirmiştir. Bu algoritmalar sabit çarpanları büyük olduğu için pratikte çoğunlukla yalnız çok büyük matrislerde kullanılır.

## 6. Matris çarpım sırası

### 6.1 Üç matris örneği

Elimizde çarpılacak üç matris olsun: $A(10, 30)$, $B(30, 5)$, $C(5, 60)$ (ekrandan, 01:00:00). Bunlar iki sırada çarpılabilir: önce $A$ ile $B$, sonra sonuç ile $C$, yani $(AB)C$; ya da önce $B$ ile $C$, sonra $A$ ile sonuç, yani $A(BC)$. İki sırada da sonuç aynıdır. Hoca sonucun dışında maliyetin nasıl değiştiğini incelemeyi önerdi.

$(AB)C$ sırası:

- $AB$: $10 \cdot 30 \cdot 5 = 1500$ işlem; sonuç $10 \times 5$ boyutludur.
- $(AB)C$: $10 \times 5$ ile $5 \times 60$ çarpılır, $10 \cdot 5 \cdot 60 = 3000$ işlem.
- Toplam: $1500 + 3000 = 4500$ işlem.

$A(BC)$ sırası:

- $BC$: $30 \cdot 5 \cdot 60 = 9000$ işlem; sonuç $30 \times 60$ boyutludur.
- $A(BC)$: $10 \times 30$ ile $30 \times 60$ çarpılır, $10 \cdot 30 \cdot 60 = 18000$ işlem.
- Toplam: $9000 + 18000 = 27000$ işlem.

Sıra değiştiğinde sonuç değişmez ama maliyet arasında çok büyük bir fark oluşabilir: burada altı kata yakın.

### 6.2 Daha çok matris

Üç matriste yalnız iki olası sıra vardı. $A, B, C, D$ gibi dört matris olduğunda daha çok sıra oluşur (ekrandan, 01:00:00): $((AB)C)D$, yani önce $A$ ile $B$, sonuç ile $C$, sonuç ile $D$; $(A(BC))D$, yani önce $B$ ile $C$, sonuç ile $A$, sonra $D$; $(AB)(CD)$, yani önce $A$ ile $B$, sonra $C$ ile $D$, sonra iki sonuç. Bunların her birinin maliyeti farklı olabilir. Bütün matrisler aynı boyutlu kare matrisler olsaydı her çarpım $n^3$ olacağı için sıranın maliyete etkisi olmazdı. Kare olmayan matrislerde ise sıra önemli maliyet farkları yaratır.

Hoca, boyutları verilen $k$ matrisin hangi sırada çarpılırsa en düşük maliyetin elde edileceğini bulmanın güzel bir problem olduğunu söyledi ve bunu çalışma sorusu olarak bıraktı.

> **Ek bilgi (derste anlatılmadı):** Bu problem büyük olasılıkla "matris zinciri çarpımı" (matrix chain multiplication) adıyla bilinir. Olası parantezleme sayısı matris sayısıyla çok hızlı büyür; dört matris için beş farklı parantezleme vardır. Problem genellikle dinamik programlama ile $O(k^3)$ zamanda çözülür.

## 7. Harici birleştirmeli sıralama (external merge sort)

### 7.1 Problem: dizi RAM'e sığmıyor

Hoca sıralama konusuna döndü ama yeni bir kısıtla: dizi RAM'e sığmıyor (ekrandan, 01:05:00). Programın RAM'de kullanabileceği alan 1 GB, sıralanacak veri ise 9 GB olsun. Bu 9 GB sabit diskte (ya da SSD'de) durur. 9 GB'ı RAM'e çekip üzerinde sıralama yapmak mümkün değildir. Burada kullanılan algoritma external merge sort, yani harici birleştirmeli sıralamadır.

Hedef, diskteki 9 GB'lık veriyi yine diskte 9 GB'lık sıralı veri hâline getirmektir. RAM'de hiçbir zaman 1 GB'tan fazla veri bulunmamalıdır.

### 7.2 Neden önce RAM'e almak gerekir

Hoca diskte doğrudan sıralama yapılamayacağını açıkladı: RAM'e çekilmeyen bir veri işlenemez, işlemciye gönderilemez. Diskten ya da SSD'den işlemciye doğrudan yol yoktur; önce diskten RAM'e, sonra RAM'den işlemciye yol vardır. Bu, giriş/çıkış (I/O) hızlarıyla ilgilidir. İşlemcinin hızı çok yüksektir, RAM'inki ondan biraz düşüktür; SSD sabit diskten iyidir ama RAM'den kötüdür. Kapasite, hız ve I/O açısından çok farklı birimleri doğrudan birbirine bağlamak verimli bir çözüm değildir.

### 7.3 Birinci aşama: parçaları sıralama

İlk adımda 9 GB'lık veri 9'a bölünür. Amaç her parçanın RAM'e sığacak büyüklükte olmasıdır; RAM ya da veri boyutu değişirse bölme sayısı da buna göre değişir (ekrandan, 01:05:00). Her parça diskten RAM'e çekilir, sıralanır ve diske geri yazılır.

1 GB'lık parça RAM'de kendi üzerinde (yerinde) sıralanmalıdır. Hoca bunun için birleştirmeli sıralama yerine quicksort gibi bir yöntemin gerektiğini söyledi. Bu işlem dokuz parça için tekrarlandığında veri sıralı olmaz: her blok kendi içinde küçükten büyüğe sıralıdır ama bloklar birbirine göre sıralı değildir.

### 7.4 İkinci aşama: çok yollu birleştirme

Hoca dönemin başında görülen "iki sıralı diziyi birleştirerek tek sıralı dizi oluşturma" konusunu hatırlattı. O yöntemde her dizi için bir indis tutulur; indis dizinin o ana kadar işlenmiş bölgesini gösterir. Hangi dizinin sıradaki elemanı küçükse ondan alınır ve o dizinin indisi bir artar; iki dizinin de sonuna kadar gidilir. Burada aynı fikir iki dizi yerine dokuz dizi için uygulanır.

Dokuz parçanın her birinin ilk %10'luk kısmı, yani 100 MB'ı RAM'e çekilir (ekrandan, 01:10:00). Hoca sordu: RAM'in ne kadarı doludur? Öğrencilerin cevabı %90 idi. Geriye 100 MB boş alan kalır; bu alan çıkış tamponu (buffer) olarak kullanılır. Böylece RAM'de kendi içinde sıralı dokuz adet 100 MB'lık dizi ve bir de 100 MB'lık tampon vardır.

Birleştirme şöyle ilerler:

- Dokuz dizinin işlenmemiş ilk elemanları arasından en küçüğü bulunur ve tamponun birinci sırasına yazılır; sonra bir sonraki en küçük ikinci sıraya yazılır ve böyle devam edilir.
- Tampon dolunca içine yeni bir şey eklenemez. Hoca ne yapılacağını sordu; bir öğrenci diske yazılması gerektiğini söyledi. 100 MB'lık tampon diskte yeni bir bölgeye yazılır. Bu 100 MB kendi içinde sıralıdır.
- Tampon yeniden dolar ve bir öncekinin hemen arkasına yazılır.
- Her dizi için o dizinin ne kadarının tampona aktarıldığını tutan bir işaretçi vardır. İşaretçi dizinin sonuna dayandığında o 100 MB'lık kısım RAM'den kaldırılır ve aynı parçanın ikinci %10'luk kısmı diskten getirilir.

Böylece RAM'de her zaman 1 GB alan kullanılır ve sonunda 9 GB'lık veri sıralanmış olur. Diskte 9 GB'lık yeni bir alan tanımlamak gerekir: quicksort bir diziyi kendi üzerinde sıralayabilir, ama external merge sort'ta veri kendi üzerinde sıralanamaz; kendisi kadar büyüklükte başka bir yer açılmalıdır. Hoca bu algoritmanın sabit disk ile RAM'in güzel bir birlikteliğini gösterdiğini söyledi.

**Soru:** Bir parçadan çekilen kısımlar bitince aynı parçadan 100 MB daha getiriliyor. O parçanın 1 GB'ının tamamı bittiğinde boşalan yere başka bir parçanın 100 MB'ı mı gelir, yoksa o alan boş mu kalır?

**Cevap:** Bu uygulamaya bağlıdır. Biten parçadan yeni bir şey getirilemeyeceğine göre, işi hızlandırmak için boşalan yere başka bir parçanın kaldığı yerden devamı aktarılabilir. Bu daha iyi olur.

## 8. Yüksek karmaşıklıklı problemler

### 8.1 Alt küme toplamı

Hoca yeni bir soru yazdı: "Verilen $n$ sayı içinde toplamı $K$ olan bir alt küme var mı?" (ekrandan, 01:15:00). Örnek dizi $-6, 12, -3, 9, 42$'dir. Toplamı 0 olan bir alt küme var mı diye sorulduğunda cevap evettir: $\{-6, -3, 9\}$ kümesinin toplamı 0'dır.

Hoca bu problemi genel olarak çözmenin karmaşıklığını sordu ve $K$ ile ilgili olmadığını belirtti. Bir öğrenci $n!$ dedi; hoca bunu onaylayıp yüksek bir değer olduğunu söyledi (ekrandan, 01:20:00).

> **Ders sonrası not:** Derste karmaşıklık $n!$ diye onaylandı. Kaba kuvvetle tüm alt kümeleri denemek için $n$ elemanlı kümenin $2^n$ alt kümesine bakmak yeterlidir; bu yüzden doğru sınır büyük olasılıkla $O(2^n)$ ya da toplamların hesabıyla birlikte $O(n \cdot 2^n)$'dir. Bu da üstel ve çok yüksek bir karmaşıklıktır, ama $n!$'den küçüktür.

### 8.2 Gezgin satıcı problemi

Bir satıcı gezerek satış yapar. Gideceği $n$ şehir bellidir (ekrandan, 01:20:00). Bütün şehirlere uğrayan bir yola rota denir. Amaç bu rotalar arasında en kısa olanı bulmaktır; yani şehirlere hangi sırada gidileceğine karar vermek.

Hoca karmaşıklığı sordu. Öğrencilerden gelen tahminlerden birine karşı hoca, $n \log n$ ile bu problemin nasıl çözülebileceğini sorarak itiraz etti ve şöyle düşünmeyi önerdi: 5 şehir varsa olası sıralama sayısı kaçtır? Cevap $5!$'dir. Optimum çözüm bulunmak isteniyorsa $n!$'lik bir arama yapmak gerekir. $n!$ çok yüksek bir karmaşıklıktır.

## 9. Sezgisel algoritmalar ve gezgin satıcı

### 9.1 Sezgisel algoritma nedir

$n!$'lik bir algoritma çalıştırmak yerine farklı bir yol izlenir: sezgisel (heuristic) algoritmalar. Arama uzayı çok büyük olduğunda, bütün uzayı aramak yerine o uzayın bir parçası üzerinde arama yapmanın kuralları tanımlanır; yani arama uzayı daraltılır. Hoca "ama" diye ekledi ve bunun bir bedeli olduğunu sonra gösterdi.

### 9.2 En yakın komşu sezgiseli

Gezgin satıcı için sezgisel kural şudur: rastgele bir şehirden başla, o şehre en yakın şehre git (ekrandan, 01:20:00). Sonra gidilen şehre, geri kalanlar arasında en yakın olana git ve bütün şehirler bitene kadar böyle devam et.

Hoca bu algoritmanın bütün rotayı oluşturma karmaşıklığını adım adım kurdu:

- Rastgele bir şehir seçmenin maliyeti 1'dir.
- O şehre en yakın şehri bulmak için geride kalan $n-1$ şehirle karşılaştırma yapılır.
- Sonraki adımda $n-2$, sonra $n-3$ karşılaştırma yapılır ve en sonda tek şehir kalır.
- Toplam $(n-1) + (n-2) + \dots + 1$'dir. Hoca kolaylık için bunu $n$'den 1'e kadar olan toplam gibi alıp $n(n+1)/2$ yazdı ve $O(n^2)$ dedi.

Bir algoritma $n!$, diğeri $n^2$'dir. Hoca 100 şehri örnek verdi: $100!$ akıl almaz bir sayıdır, $100 \cdot 100 = 10.000$ ise çok iyi bir sayıdır. Karmaşıklık korkunç derecede düşmüştür.

> **Ders sonrası not:** Tam toplam $(n-1) + (n-2) + \dots + 1 = n(n-1)/2$'dir. Hocanın yazdığı $n(n+1)/2$ ile arasında yalnız doğrusal bir fark vardır; iki ifade de $O(n^2)$'dir.

**Soru:** Bu Prim algoritması mı?

**Cevap:** Hayır. Hoca, sözü geçen algoritmanın noktalar arasındaki en yakın yollarla ilgili olduğunu, burada ise bir noktadan diğerine giden bir yol değil, bütün şehirlerden geçen tek bir rota arandığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Prim algoritması bir graftaki en küçük kapsayan ağacı (minimum spanning tree) bulur; bütün düğümleri en az toplam ağırlıkla bağlayan bir ağaç üretir, bir rota üretmez. Bir noktadan diğer noktalara en kısa yolları bulan algoritma ise büyük olasılıkla Dijkstra algoritmasıdır.

### 9.3 Sezgiselin bedeli: örnek graf

Hoca sezgiselin "aması"nı sordu. Bir öğrenci en doğru yolu bulmayacağını söyledi; hoca bunu, bulunan yolun en kısa yol olduğunun garantisi olmadığı şeklinde netleştirdi ve bir örnek çizdi (ekrandan, 01:25:00). Grafta A, B, C, D, E, F şehirleri ve şu yollar vardır: A-B: 2, B-C: 1, C-D: 1, D-E: 1, E-F: 1, A-F: 6.

Algoritma rastgele B'den başlasın. B'ye en yakın şehir C'dir (1). C'den sonra D, D'den sonra E, E'den sonra F seçilir; F'den sonra geriye yalnız A kalır ve mecburen A'ya gidilir. Rota B-C-D-E-F-A'dır (ekrandan, 01:25:00):

$$1 + 1 + 1 + 1 + 6 = 10$$

Öğrencilerden önce 12 ve 11 gibi cevaplar geldi, sonra 10'da uzlaşıldı. Hoca B'den başlayan ve bundan daha kısa bir rota olup olmadığını sordu. Önce yok gibi görüldü; hoca B'den A'ya gidip geri dönmeyi gösterdi: B-A-B-C-D-E-F (ekrandan, 01:30:00):

$$2 + 2 + 1 + 1 + 1 + 1 = 8$$

Yani aynı şehirden başlayarak sezgisel çözümden daha iyisi vardır. Başka iyi çözümler de olabilir. A'dan başlayan A-B-C-D-E-F rotasının uzunluğu ise $2 + 1 + 1 + 1 + 1 = 6$'dır ve öteki rotalara göre çok daha iyidir (ekrandan, 01:30:00). Bu örnekte rota başlangıca dönmek zorunda olmayan, bütün şehirlerden geçen bir yol olarak ele alınmıştır.

### 9.4 Optimallikten ödün ve "değer mi" sorusu

Sezgisel algoritmalar en iyi (optimum) sonucu garanti etmez. Bazı problem türlerinde belli kısıtlar altında optimum çözümü veren sezgisel yöntemler vardır; orada zaten kaba kuvvet yerine onlar kullanılır. Ama genel olarak sezgiseller arama süresini çok kısaltır, karşılığında optimallikten ödün verir.

Optimumu bulmanın şart olmadığı durumlarda çok uzun beklemek yerine hızlı bulunan, optimal olmayan çözümler geliştirilir. Hoca gezgin satıcı örneğini verdi: satıcıya "beş yıl bekle, sana optimal rotayı söyleyeyim" demenin bir anlamı yoktur. Hoca "attığın taş ürküttüğün kurbağaya değmeli" sözünü hatırlattı ve abartılı bir örnek verdi: 10 dakikada 100 kilometrelik bir çözüm bulunuyor, 10 yıl çalıştırınca 90 kilometrelik bir çözüm bulunuyor. Bu kadar beklemeye değmez. Oranlar problemden probleme değişir; kritik olan, optimum yol için harcanan $n!$'lik zamanın ve kaynağın sezgisel yolu gerçekten çok büyük oranda iyileştirip iyileştirmediğidir.

Bazen ne kadar iyileştirilebileceği de bilinemez. Bu küçük grafta optimum çözüm gözle görülebilir; ama gerçek dünya problemlerinde 5 değil 5000 nokta olabilir ve optimumu bulmak çok güçtür. Bu tür yüksek karmaşıklıklı problemlerden kaçılmaz; sezgisel olarak arama uzayı daraltılır ve en iyi olmasa da yeterince iyi çözümler bulunmaya çalışılır.

Hoca ileride alınacak derslerde de bunun görüleceğini söyledi: derin öğrenme algoritmaları da arama uzayının tamamını taramaz, belli bir parçası üzerinde çalışıp yeterince iyi bir çözümle yola devam eder. Oradaki uzaylar süreklidir; örneğin 1 milyon parametrenin her birinin en iyi değerini aramak korkunç bir hesap yüküdür. Gradyan kullanmak gibi sezgisel yollarla arama uzayı daraltılır.

> **Hocanın vurgusu:** İyi sezgisel algoritmalar ve iyi sezgisel kurallar geliştirmek, farklı problem türleri için oldukça kıymetlidir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00; derste sözlü, 00:09:09): Bir kumarbaz her oyunda $p$ olasılıkla 1 TL kazanıyor, $1-p$ olasılıkla 1 TL kaybediyor. Oyuna $n$ lira ile giriyor ve parası $m+n$ ya da 0 olana kadar oynuyor. Bu süreci örneğin 10.000 kez tekrarlayıp kaç tanesinin $m+n$ ile bittiğini bulan ve oranı ekrana yazdıran programı yazın.

> **Çözüm (derste verildi):** $m$, $n$, $p$, $K$ okunur; `kaz = 0`, $h = m+n$. $i = 1..K$ için eldeki para $n$ yapılır; para $h$'den küçük ve 0'dan büyük olduğu sürece `rand() > p` ise para 1 azalır, değilse 1 artar. Döngü bitince para $h$'ye eşitse `kaz` 1 artar. Sonunda `kaz / K` yazdırılır. C karşılığı 3.2'dedir.

**Soru 2** (derste sözlü, 00:20:05): 0 ile 1 arasında düzgün dağılımlı rastgele bir sayının $p$'den büyük olma olasılığı nedir? `rand() > p` koşulunun doğru tarafında kumarbaz kazanır mı kaybeder mi?

> **Çözüm (derste verildi):** Olasılık $1-p$'dir. Bu yüzden doğru tarafı kaybı temsil eder ($N = N - 1$), yanlış tarafı kazancı ($N = N + 1$).

**Soru 3** (derste sözlü, 00:28:10): $p$ büyüdükçe `kaz / K` oranı büyür mü, küçülür mü?

> **Çözüm (derste verildi):** Büyür, çünkü her oyunda kazanma olasılığı artar.

**Soru 4** (ekrandan, 00:50:00; derste sözlü, 00:47:22): $p = 0.473$ için tablodaki sonuçlara bakarak ne söylenebilir? Oyuna girilen para $n$ sonucu nasıl etkiler?

> **Çözüm (derste verildi):** $n$'nin etkisi yok denecek kadar azdır; sonucu $m$ ve $p$ belirler. Sonuç yaklaşık $(p/(1-p))^m$ ile sınırlıdır ve $m$ arttıkça üstel olarak düşer; kasa her zaman kazanır.

**Soru 5** (ekrandan, 01:00:00): $A(10,30)$, $B(30,5)$, $C(5,60)$ matrisleri için $(AB)C$ ve $A(BC)$ sıralarının çarpma maliyetlerini hesaplayın.

> **Çözüm (derste verildi):** $(AB)C$: $10 \cdot 30 \cdot 5 + 10 \cdot 5 \cdot 60 = 1500 + 3000 = 4500$. $A(BC)$: $30 \cdot 5 \cdot 60 + 10 \cdot 30 \cdot 60 = 9000 + 18000 = 27000$. Sonuç aynı, maliyet çok farklıdır.

**Soru 6** (derste sözlü, 01:00:23; çalışma sorusu): Boyutları verilen $k$ matrisin hangi sırada çarpılırsa en düşük maliyetin elde edileceğini bulan bir yöntem geliştirin.

> **Çözüm (derste verilmedi):** Derste çalışma sorusu olarak bırakıldı. Bir yaklaşım, $i$'den $j$'ye kadar olan matrislerin en düşük maliyetini $M[i][j]$ ile tutup her olası bölme noktası $s$ için $M[i][s] + M[s+1][j] + d_{i-1} d_s d_j$ değerlerinin en küçüğünü almaktır ($d$ boyut dizisi). $A, B, C$ örneğinde ($d = 10, 30, 5, 60$) bu yöntem en düşük maliyeti 4500 ve sırayı $(AB)C$ olarak verir.

**Soru 7** (derste sözlü, 01:08:07): 1 GB RAM'de dokuz parçanın her birinin ilk %10'u (100 MB) RAM'e çekildiğinde RAM'in ne kadarı doludur? Çıkış tamponu dolunca ne yapılır?

> **Çözüm (derste verildi):** RAM'in %90'ı doludur; kalan 100 MB çıkış tamponudur. Tampon dolunca diske, yeni bir bölgeye yazılır; yazılan 100 MB kendi içinde sıralıdır.

**Soru 8** (ekrandan, 01:15:00): $\{-6, 12, -3, 9, 42\}$ içinde toplamı 0 olan bir alt küme var mı? Genel olarak $n$ sayı içinde toplamı $K$ olan alt küme olup olmadığını kaba kuvvetle bulmanın karmaşıklığı nedir?

> **Çözüm (derste verildi):** Vardır: $\{-6, -3, 9\}$, toplamı 0. Derste karmaşıklık için $n!$ cevabı onaylandı. Tüm alt kümeleri denemek $2^n$ alt küme gerektirir; bkz. 8.1'deki ders sonrası not.

**Soru 9** (derste sözlü, 01:17:44): 5 şehrin olası sıralama sayısı kaçtır? Gezgin satıcı probleminin kaba kuvvet karmaşıklığı nedir?

> **Çözüm (derste verildi):** $5! = 120$ sıralama vardır; genel olarak kaba kuvvet $n!$'dir.

**Soru 10** (derste sözlü, 01:20:26): "Rastgele bir şehirden başla, her adımda en yakın gidilmemiş şehre git" sezgiselinin karmaşıklığı nedir?

> **Çözüm (derste verildi):** $(n-1) + (n-2) + \dots + 1$ karşılaştırma, yani $O(n^2)$.

**Soru 11** (ekrandan, 01:25:00 ve 01:30:00): A-B: 2, B-C: 1, C-D: 1, D-E: 1, E-F: 1, A-F: 6 yollarından oluşan grafta en yakın komşu sezgiseli B'den başlarsa hangi rotayı bulur ve uzunluğu nedir? B'den başlayan daha kısa bir rota var mıdır?

> **Çözüm (derste verildi):** Sezgisel rota B-C-D-E-F-A, uzunluk $1+1+1+1+6 = 10$. Daha kısası B-A-B-C-D-E-F, uzunluk $2+2+1+1+1+1 = 8$. A'dan başlayan A-B-C-D-E-F rotası ise $2+1+1+1+1 = 6$'dır.

## Dersin Toparlaması

Son derste dört farklı problem üzerinden algoritmik düşünce pekiştirildi. Kumarbaz probleminde, formülü bilinmese bile bir olasılığın rastgele sayı üreteciyle süreci çok kez tekrarlayarak (Monte Carlo) tahmin edilebileceği görüldü; sonuçlar kazanma şansının oyuna girilen paraya değil, hedeflenen kazanca ve tek oyundaki kazanma olasılığına bağlı olduğunu, yani kasanın her zaman kazandığını gösterdi. Matris çarpımında algoritmanın $O(nmp)$ maliyeti ve çarpım sırasının bu maliyeti çok büyük ölçüde değiştirebildiği gösterildi.

External merge sort, RAM'e sığmayan verinin parçalara bölünüp ayrı ayrı sıralandıktan sonra iki sıralı diziyi birleştirme fikrinin çok yollu genelleştirmesiyle birleştirildiğini ve RAM ile diskin birlikte nasıl kullanıldığını gösterdi. Son olarak alt küme toplamı ve gezgin satıcı gibi çok yüksek karmaşıklıklı problemlerde arama uzayını daraltan sezgisel algoritmaların hız kazandırdığı ama optimum çözümü garanti etmediği bir örnek grafla gösterildi. Hoca dersin amacının öğrencileri algoritmik düşünceye ısındırmak ve onlara bir bakış açısı kazandırmak olduğunu söyleyerek dönemi kapattı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
