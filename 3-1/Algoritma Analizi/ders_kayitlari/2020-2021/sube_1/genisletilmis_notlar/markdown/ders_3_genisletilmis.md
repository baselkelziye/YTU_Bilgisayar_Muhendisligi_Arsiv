# Ders 3 Genişletilmiş Notu: Asimptotik Notasyonlar ve Özyinelemeli Olmayan Algoritmaların Analizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Asimptotik analiz: neden ve nasıl sadeleştiririz?
- 2. Big-O notasyonu: asimptotik üst sınır
- 3. Big-Omega notasyonu: asimptotik alt sınır
- 4. Big-Theta notasyonu: sıkı sınır
- 5. Best, worst ve average case; sık kullanılan toplamlar
- 6. Özyinelemeli olmayan algoritmaların analizi: findMax
- 7. Sıralı arama (sequential search)
- 8. Insertion sort ve worst case analizi
- Örnek Sorular

## 1. Asimptotik analiz: neden ve nasıl sadeleştiririz?

Bir önceki derste bir algoritmanın karmaşıklığı satır satır sayılarak hesaplanmıştı. Bu derste hoca, bir algoritmayı analiz edebilmek için önce karmaşıklığının nasıl ölçüleceğini ve gösterileceğini ele aldı. Bu konuların bir kısmı Veri Yapıları ve Algoritmalar dersinde kısaca görülmüştü; burada ayrıntılı işlendi.

### 1.1 İki tasarımın karşılaştırılması

Hoca şu soruyla başladı: Siz bir algoritma yazıp karmaşıklığını satır satır saydınız ve $2n^2 + 5n + 9$ buldunuz. Bir arkadaşınız aynı işi yapan başka bir kod yazdı ve onunki $2n^2 + 4n + 12$ çıktı. Hangi tasarım daha iyidir? (ekrandan, 00:05:00)

Karmaşıklık her zaman girişteki eleman sayısı $n$'e bağlı hesaplanır. $n$ küçükse, örneğin $n = 10$ için:

- Birinci tasarım: $2 \cdot 100 + 5 \cdot 10 + 9 = 200 + 50 + 9 = 259$ adım.
- İkinci tasarım: $2 \cdot 100 + 4 \cdot 10 + 12 = 200 + 40 + 12 = 252$ adım.

Burada ikinci tasarım "kıl payı" kazanır ve belki $n = 20$, $n = 30$ için de bir süre kazanmaya devam eder. Ama $n$ büyüdükçe katsayıların ve sabit terimlerin anlamı kalmaz. Algoritmayı kimi küçük, kimi büyük $n$ değerleri için çalıştıracağından genel bir yargı için şu sorulmalıdır: $n$ sonsuza giderken durum nasıldır?

### 1.2 Asimptotik analiz ve sadeleştirme kuralları

Programın karmaşıklığını kullanılan bilgisayar, derleyici gibi değişebilen etkenlerden bağımsız olarak yalnız girişteki eleman sayısına bağlı olarak incelemeye **asimptotik analiz** denir. $n \to \infty$ iken bir ifadeyle şunlar yapılır:

- **Sabitler atılır.** Sonsuza giden bir değere 9 eklemenin hiçbir etkisi yoktur.
- **Katsayılar atılır.** $n \to \infty$ iken $2n^2$ ile $n^2$ arasındaki fark bir şey ifade etmez. Böylece $2n^2 + 5n$ ifadesi $n^2 + n$ olur.
- **En yüksek üslü terim bırakılır.** $n^2$ varken $n$'in de bir anlamı kalmaz; sonuç $n^2$'dir.

Böylece $2n^2 + 5n + 9$ de $2n^2 + 4n + 12$ de $n^2$ olur ve iki program karmaşıklık açısından eşdeğerdir.

### 1.3 Dikkat edilecek iki durum

Hoca sadeleştirirken dikkat edilmesi gereken iki ek durumu sıraladı (ekrandan, 00:10:00):

1. **Büyük sabitler.** $2n^2 + c \cdot n$ ifadesini $n^2$ diye değerlendiririz. Peki $c$, $10^7$ ya da $10^8$ gibi bir sayıysa? Bu durumda $c \cdot n$ terimi kolayca atılamaz; hoca, böyle bir sabitin ifadeyi $n^2$'nin üstüne çıkarabileceğini söyledi. Bunlar uç durumlardır; atılan sabitlerden kastedilen 3, 5, 1000 gibi makul sabitlerdir.
2. **İki değişkenli karmaşıklık ($m \times n$).** Hoca buna özellikle dikkat edilmesini istedi. Bir algoritmanın karmaşıklığı $m \times n$ çıktıysa (ör. $m \times n$ boyutlu bir matris üzerinde işlem), $m$'yi sabit sayıp karmaşıklığa $n$ diyemezsiniz. $m$'nin değeri $n$'e yakın olabiliyorsa karmaşıklık $n^2$ gibi değerlendirilmelidir.

> **Hocanın vurgusu:** Sabiti ve katsayıyı atarken bu iki noktaya dikkat edin; özellikle $m \times n$ karmaşıklığını $n$'e indirgemeyin.

## 2. Big-O notasyonu: asimptotik üst sınır

"$2n^2 + 5n + 9$'a $n^2$ derim" dedik; gerçekten diyebilir miyiz? Bunu doğrulamak ve giriş büyüdükçe çalışma süresinin nasıl değiştiğini ölçmek için üç asimptotik notasyon kullanılır (ekrandan, 00:15:00):

- $O(\,)$: Big-O
- $\Theta(\,)$: Big-Theta
- $\Omega(\,)$: Big-Omega

Üçünün kullanım yerleri ve şekilleri farklıdır.

### 2.1 Tanım

Big-O notasyonu, algoritmanın karmaşıklığının **en fazla** ne ile gösterilebileceğini, yani bir **üst sınırı (upper bound)** verir. Ekranda yazılan tanım (ekrandan, 00:15:00):

$$f(n) \in O(g(n)) \iff \exists\, c > 0,\ n_0 > 0 :\quad 0 \le f(n) \le c \cdot g(n) \quad \text{her } n \ge n_0 \text{ için}$$

Burada $c$ bir sabittir. Bu şart sağlanıyorsa $g(n)$, $f(n)$ için bir asimptotik üst sınırdır ve $f(n)$ yerine $g(n)$ kullanılabilir. Gösterim "elemanıdır" ($\in$) biçimindedir; örneğin $n^2 + n \in O(n^3)$ diye yazılır.

Hoca bunu bir grafikle anlattı: yatay eksen $n$, dikey eksen çalışma süresi (execution time). Siyah eğri $f(n)$, kırmızı eğri $c \cdot g(n)$'dir. Bir $n_0$ noktasından itibaren kırmızı eğri siyahın üstünde kalır ve bir daha hiç altına düşmez. Eğrilerin düz olması gerekmez.

### 2.2 Örnek: $10n + 30 \in O(n)$

$f(n) = 10n + 30$ için sabit ve katsayı atılınca $n$ kalır; $g(n) = n$ ile $O(n)$ diyebilir miyiz? (ekrandan, 00:20:00)

- Gereken: $10n + 30 \le c \cdot n$, yani $30 \le (c - 10)\,n$.
- $n_0 = 1$, $c = 40$ seçilsin: $30 \le 30$, sağlanır.
- $n = 2$: $30 \le 60$. $n$ büyüdükçe sağ taraf artar, eşitsizlik hep sağlanır.

Sonuç: $10n + 30 \in O(n)$. Böylece "sabiti ve katsayıyı at" kuralı bu örnekte doğrulanmış olur.

### 2.3 Örnek: $n^2 + 2n + 1 \in O(n^2)$

Sabit (1), katsayı (2) ve düşük üslü terim ($n$) atılınca $n^2$ beklenir. Kontrol: $n^2 + 2n + 1 \le c \cdot n^2$. $n_0 = 1$ için $1 + 2 + 1 \le c \cdot 1$; $c = 4$ alınınca $4 \le 4$ sağlanır. Demek ki $n^2 + 2n + 1$ yerine $n^2$ yazılabilir.

### 2.4 Soru: $n^2 + n \in O(n^3)$ mü?

Hoca sınıfa sordu (ekrandan, 00:25:00). Bir öğrenci $n_0 = 1$ ve $c = 2$ (ya da 1) ile $n^2 + n \le c \cdot n^3$ eşitsizliğinin sağlandığını söyledi; hoca doğruladı. $g(n)$ bir üst sınır olduğundan $n^2 + n$'yi $n^3$ ile, hatta $n^5$ ya da $n^7$ ile de gösterebilirsiniz; bunların hiçbiri yanlış değildir.

Ama bu mantıklı mı? Günlerce uğraşıp $n^2$ karmaşıklıklı verimli bir algoritma yazdıysanız onu $O(n^3)$ diye göstermek istemezsiniz.

> **Hocanın vurgusu:** Asimptotik üst sınırdan kastedilen, olabilecek **en yakın (en düşük)** üst sınırdır.

### 2.5 Soru: $n^2 + n \in O(n)$ mü?

Bir öğrenci "diyemeyiz, fonksiyonda $n^2$ olduğu için" dedi. Hoca bunu matematiksel olarak gösterdi (ekrandan, 00:30:00). $n^2 + n \le c \cdot n$ için $n_0 = 1$, $c = 5$ seçilsin:

| $n$ | $n^2 + n$ | $5n$ | Sağlanıyor mu? |
|---|---|---|---|
| 1 | 2 | 5 | Evet |
| 2 | 6 | 10 | Evet |
| 3 | 12 | 15 | Evet |
| 4 | 20 | 20 | Evet |
| 5 | 30 | 25 | Hayır |

Hoca önce $n = 2$'de bozulduğunu söyledi; bir öğrenci sağ tarafın $10$ olduğunu hatırlattı, hoca düzeltti ve tablo yukarıdaki gibi ilerledi. Eşitsizlik $n = 5$'te bozulur. Bir ifade bazı $n$ değerlerinde sağlanabilir, ama $n_0$'dan itibaren **bütün** $n$ değerleri için sağlanması gerekir. Bu yüzden $n^2 + n \notin O(n)$.

### 2.6 $c$ ve $n_0$ seçimi üzerine soru-cevap

**Soru:** Bütün $n$ değerlerini herhangi bir $c$ değeri için mi sağlaması gerekiyor? $c$ değiştirilip yeniden sağlatılabilir mi?

**Cevap:** Şartı sağlayan tek bir $c$ bulmak yeterlidir; örneğin 3 için sağlamıyor ama 40 için sağlıyor olabilir. Ama bir kez seçtikten sonra durmadan değiştirmezsiniz. Mantıklı bir $c$ seçmek çok iterasyon yapmamanızı sağlar; $10n^2 + n$'nin $n^2$ olması eninde sonunda sağlanır, $c$'yi makul bir değerden başlatırsanız hemen sağlarsınız.

**Soru:** $c$'yi büyük alıp daha fazla iterasyondan sonra bulsak da doğru bulmuş oluyor muyuz?

**Cevap:** Evet. Önemli olan, bir $n_0$ noktasından itibaren $f(n) \le c \cdot g(n)$ eşitsizliğinin artık hiç bozulmamasıdır. $n_0 = 3$ alıp bir süre iyi gidip sonra $n$ büyüyünce bozulması kabul edilmez. Hoca bunu bir çizimle de gösterdi: $c \cdot g(n)$ eğrisi bir yerde $f(n)$'nin üstünde, sonra altında, sonra yine üstünde olamaz; bir noktadan sonra bir daha hiçbir zaman $f(n)$'nin altına düşmemelidir.

## 3. Big-Omega notasyonu: asimptotik alt sınır

### 3.1 Tanım

Big-Omega, **asimptotik alt sınırı (lower bound)** verir (ekrandan, 00:35:00):

$$f(n) \in \Omega(g(n)) \iff \exists\, c > 0,\ n_0 > 0 :\quad f(n) \ge c \cdot g(n) \quad \text{her } n \ge n_0 \text{ için}$$

Grafikte bir $n_0$ noktasından itibaren $c \cdot g(n)$ eğrisi hep $f(n)$'nin altında kalır. Böyle bir $g$ bulunursa $g(n)$, $f(n)$'nin asimptotik alt sınırıdır.

### 3.2 Örnek: $5n^2 \in \Omega(n^2)$

$5n^2 \ge c \cdot n^2$ sağlanıyor mu? Bu, $(5 - c)\,n^2 \ge 0$ demektir. $n_0 = 1$ ve $c = 1$ alınınca $4 \ge 0$ olur. Demek ki $5n^2 \in \Omega(n^2)$.

### 3.3 Örnek: $5n^2 \in \Omega(n)$ mi?

Hoca sınıfa sordu: $5n^2 \ge c \cdot n$ ($c > 0$, $n_0 > 0$) diyebilir miyiz? $n_0 = 1$ alınınca $5 \ge c$ olur; $c = 3$ seçilince şart sağlanır. Zaten bir noktadan sonra $n^2$'nin $n$'den büyük olacağı gözle de görülür. Yani karmaşıklığı $5n^2$ olan bir şeyin asimptotik alt sınırı $n$ de olabilir. Hoca bunun mantıksız görünebileceğini, nerede kullanılacağının dersin ilerleyen kısmında anlaşılacağını söyledi.

## 4. Big-Theta notasyonu: sıkı sınır

### 4.1 Tanım

Big-Theta **sıkı sınır (tight bound)** demektir. Üst sınırda $n^2$'yi $n^3$ ile, alt sınırda $n^2$'yi $n$ ile gösterebiliyorduk; Theta'da böyle bir esneklik yoktur, $n^2$ ise $n^2$ ile gösterilmek zorundadır.

$$f(n) \in \Theta(g(n)) \iff \exists\, c_1, c_2 > 0,\ c_1 \le c_2,\ n_0 :\quad 0 \le c_1\, g(n) \le f(n) \le c_2\, g(n) \quad \text{her } n \ge n_0 \text{ için}$$

Grafikte $n_0$ noktasından itibaren $c_2\,g(n)$ eğrisi $f(n)$'nin üstünde, $c_1\,g(n)$ eğrisi altında kalır. Bu durumda $f(n)$ ile $g(n)$ asimptotik olarak eşittir.

### 4.2 Örnek: $2n + 5 \in \Theta(n)$

$f(n) = 2n + 5$, $\Theta(n)$ ile gösterilebilir mi? (ekrandan, 01:00:00 ve 01:05:00) Bunun için iki şey birden kontrol edilir: asimptotik üst sınır ve asimptotik alt sınır.

**a) $f(n) \in O(n)$ mi?**

- $2n + 5 \le c_1 \cdot n$, yani $(c_1 - 2)\,n \ge 5$.
- Hoca $n_0 = 1$ vermenin işi baştan kolaylaştırdığını söyledi. $n_0 = 1$, $c_1 = 7$: $5 \ge 5$, sağlanır ve $n$ büyüdükçe sol taraf artar.
- Sonuç: $f(n) \in O(n)$.

**b) $f(n) \in \Omega(n)$ mi?**

- $2n + 5 \ge c_2 \cdot n$, yani $(2 - c_2)\,n \ge -5$.
- $c_2 = 1$ alınırsa $n \ge -5$ olur; her $n \ge 1$ için sağlanır.
- Sonuç: $f(n) \in \Omega(n)$.

Her iki şart sağlandığından $f(n) \in \Theta(n)$: $2n + 5$, polinom olarak aynı dereceden bir ifadeyle, derece farkı olmadan gösterilmiş olur.

> **Ders sonrası not:** Alt sınır kısmında hoca eşitsizliği birkaç kez yeniden düzenledi (bir öğrencinin eşitsizliği $-1$ ile çarpınca yönün değişmesi gerektiğini hatırlatması üzerine) ve sonunda $5 \ge (c_2 - 2)\,n$ yazıp $c_2 = 4$ önerdi; $n = 1$ için $5 \ge 2$ sağlandığını söyledi. Ancak $2n + 5 \ge 4n$ yalnız $n \le 2$ için doğrudur; $n = 3$'te $11 \ge 12$ bozulur. Doğrusu: $(2 - c_2)\,n \ge -5$ eşitsizliği bütün $n \ge 1$ için $0 < c_2 \le 2$ ile sağlanır. Derste ilk seçilen $c_2 = 1$ doğru bir seçimdir.

**Soru:** $c$'leri aynı seçmek zorunda mıydık?

**Cevap:** Hayır. İki ayrı sabit vardır; sağlanması gereken tek şart, alt sınırdaki sabitin üst sınırdaki sabitten küçük ya da ona eşit olmasıdır ($c_1 \le c_2$ tanımında). Alt sınır sabiti büyük seçilirse eşitsizlik bozulur.

## 5. Best, worst ve average case; sık kullanılan toplamlar

### 5.1 Üç durum

Bir algoritmanın karmaşıklığı hesaplanırken genellikle üç durum incelenir (Veri Yapıları ve Algoritmalar dersinde basitçe görülmüştü):

- **Best case:** olabilecek en iyi durum.
- **Worst case:** olabilecek en kötü durum.
- **Average case:** algoritmanın karmaşıklığının genel durumda ne olacağı. Buradaki "average" aritmetik ortalama almaktan gelmez; rastgele girişler verildiğinde, uç durumlarda değil de genelde ne olacağını ölçmeye çalışan yaklaşımdır.

Average case'i ölçmek zor olduğundan çoğunlukla best ve worst case'e bakılır.

### 5.2 Sık kullanılan toplamlar

Tekrar eden işlerde ($n$ kez, $n^2$ kez vb.) en çok kullanılan bağıntılar:

- $\sum_{i=1}^{n} 1 = n$
- $\sum_{i=1}^{n} i = \dfrac{n(n+1)}{2}$
- $\sum_{i=1}^{n} i^2$ <!-- BELİRSİZ: hoca bu toplamı da yazdı ama formülü altyazıda okunmuyor, o ana ait kare yok -->

> **Ek bilgi (derste anlatılmadı):** Kareler toplamının bilinen kapalı biçimi büyük olasılıkla tahtada yazılan $\sum_{i=1}^{n} i^2 = \dfrac{n(n+1)(2n+1)}{6}$ formülüdür; asimptotik olarak $\Theta(n^3)$'tür.

## 6. Özyinelemeli olmayan algoritmaların analizi: findMax

Hoca bu bölüme "Mathematical Analysis of Nonrecursive Algorithms" başlığını verdi (ekrandan, 01:10:00). Best, worst ve average case kavramlarını görmek için özyinelemeli olmayan basit algoritmalarla başlandı.

### 6.1 Algoritma

Verilen $n$ sayı içinden en büyüğünü bulan fonksiyon (ekrandan, 01:15:00):

```c
int findMax(int n, int A[])
{
    int i, max;
    max = A[0];
    for (i = 1; i < n; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}
```

### 6.2 Temel işlem ve karşılaştırma sayısı

Komutlar tek tek sayılmaz. Bakılacak yer, girişteki eleman sayısı $n$'e bağlı değişen kısım, yani döngüdür; döngü içinde de en çok yapılan işe odaklanılır. Burada her turda mutlaka yapılan `A[i] > max` karşılaştırması **temel işlemdir (basic operation)**. `max = A[i]` ataması ise yalnız koşul doğruysa yapılır.

Karşılaştırma sayısı:

$$C(n) = \sum_{i=1}^{n-1} 1 = n - 1 \;\Rightarrow\; O(n)$$

### 6.3 Best = worst = average

Hoca sordu: dizinin en büyük elemanını bulmanın best case'i nedir? Öğrenciler "$n$" dedi. Worst case de $n$'dir. En büyük eleman dizinin başında, 9. ya da 23. gözünde olsa da durum değişmez; bütün diziye bakmadan en büyüğe karar verilemez. Yani bu algoritmada best, worst ve average case birbirine eşittir.

> **Hocanın vurgusu:** Bu durumda karmaşıklık $\Theta(n)$ diye gösterilmelidir; bu çok önemli. Karmaşıklık asimptotik olarak hiçbir zaman $n$'in altına düşmez, üstüne de çıkmaz. $O(n)$ demek de doğrudur, ama her durumda tam $n$ adım süreceğini bakar bakmaz anlatan, daha anlaşılır gösterim $\Theta(n)$'dir.

## 7. Sıralı arama (sequential search)

### 7.1 Algoritma

İkinci basit algoritma sıralı aramadır (ekrandan, 01:20:00). $n$ eleman sayısı, $a$ dizi, $x$ aranan elemandır:

```c
int sequentialSearch(int n, int a[], int x)
{
    int i = 0;
    while ((i < n) && (a[i] != x))
        i++;
    if (i < n) return i;
    else return -1;
}
```

<!-- BELİRSİZ: el yazısında "return i" satırındaki harf "1" gibi de okunabiliyor; bulunduğunda konumu döndürmesi anlamca i'dir -->

findMax'tan farkı, dizinin sonuna kadar gitmenin gerekmemesidir; eleman bulununca döngü biter.

### 7.2 Worst ve best case

- **Worst case:** dizinin sonuna kadar gidilir, karmaşıklık $n$'dir. Worst case'te karmaşıklık $n$'in altına da inmez, üstüne de çıkmaz; bu yüzden $C_{worst}(n) \in \Theta(n)$ denebilir.
- **Best case:** eleman ilk bakılan gözdedir, tek karşılaştırma yapılır: $\Theta(1)$. Big-O ile de gösterilebilir, ama worst case'in hep $n$, best case'in hep 1 çıkacağı garanti olduğundan Theta kullanılabilir.

### 7.3 Average case

Hoca ortalama durumu şöyle kurdu (ekrandan, 01:25:00):

- Aranan elemanın dizide bulunma (successful search) olasılığı $p$, $0 \le p \le 1$.
- Bütün konumlar eşit olasılıklı olduğundan elemanın $i$. konumda olma olasılığı $\dfrac{p}{n}$.
- Eleman $i$. konumdaysa $i$ karşılaştırma yapılır.
- Eleman dizide yoksa (unsuccessful search) $n$ karşılaştırma yapılır; bunun olasılığı $1 - p$.

$$C_{avg}(n) = \left[1 \cdot \frac{p}{n} + 2 \cdot \frac{p}{n} + \dots + i \cdot \frac{p}{n} + \dots + n \cdot \frac{p}{n}\right] + n\,(1-p)$$

$\dfrac{p}{n}$ paranteze alınır ve $1 + 2 + \dots + n = \dfrac{n(n+1)}{2}$ kullanılır; paydaki $n$ ile paydadaki $n$ sadeleşir:

$$C_{avg}(n) = \frac{p}{n}\left[1 + 2 + \dots + n\right] + n(1-p) = p \cdot \frac{n+1}{2} + n\,(1-p)$$

İki uç durum:

- $p = 1$ (eleman kesin dizide): $C_{avg}(n) = \dfrac{n+1}{2}$.
- $p = 0$ (eleman dizide yok): $C_{avg}(n) = n$.

Hoca average case için $O(n)$ demenin doğru olduğunu söyledi: average case en kötü durumda $n$ olur, ama bazen daha küçük değerler alır.

**Soru:** Average case'e $O(n)$ dememizin sebebi, başarısız arama ihtimalini de hesaba katıp büyük olan değeri almamız mı?

**Cevap:** Evet. Başarısız aramada $n$ olur, başarılı aramada $n$'den küçük değerler de çıkabilir; dolayısıyla average case'in gösterimi $O(n)$ olmalıdır.

Hoca ayrıca bu konularda kitaplarda açıklama bulmanın zor olduğunu, kaynakların çoğu zaman bunları gelişigüzel yazdığını belirtti.

## 8. Insertion sort ve worst case analizi

### 8.1 Mantık ve örnek

Özyinelemeli olmayan bir algoritmanın analizine insertion sort üzerinden devam edildi. Ekrandaki dizi (ekrandan, 01:45:00):

| 3 | 2 | 1 | 7 | 4 | 5 |
|---|---|---|---|---|---|

Hoca dizinin 5 elemanlı olduğunu söyledi, ama ekrandaki dizi 6 elemanlıdır. Adımlar:

1. 2, 3'ten küçük: yer değiştirir → 2, 3, 1, 7, 4, 5.
2. 1, 3'ten küçük: 3 sağa kayar; 1, 2'den küçük: 2 sağa kayar; 1 başa yerleşir → 1, 2, 3, 7, 4, 5.
3. 7, 3'ten küçük değil: yerinde kalır.
4. 4, 7'den küçük: yer değiştirir; 4, 3'ten küçük değil: durur → 1, 2, 3, 4, 7, 5.
5. 5, 7'den küçük: yer değiştirir; 5, 4'ten küçük değil: durur → 1, 2, 3, 4, 5, 7.

Insertion sort'ta her eleman, sırayı bozmayacağı uygun yere gelene kadar kendisinden önceki elemanlarla karşılaştırılır.

### 8.2 Algoritmanın tasarımı (akış diyagramı)

Hoca algoritmayı sınıfla birlikte akış diyagramı olarak tasarladı (ekrandan, 01:50:00 ve 01:55:00):

```text
Giriş: n, a[n]
i = 1'den n-1'e kadar (adım +1):
    tmp = a[i]
    j = i
    (j > 0) && (tmp < a[j-1]) doğru olduğu sürece:
        a[j] = a[j-1]
        j = j - 1
    a[j] = tmp
Çıkış: a[n]
```

`tmp`, kendinden önceki elemandan küçük olduğu sürece geriye doğru gidilir; küçük değilse eleman yerleşmiş demektir, daha geriye gitmeye gerek yoktur.

### 8.3 İz sürme: 3, 1, 2, 4 ve 3, 1, 2, 0

Hoca önce 3, 1, 2, 4 dizisi üzerinde akışı izledi (ekrandan, 01:50:00):

- $i = 1$: `tmp = 1`. 1 < 3 olduğundan 3, $j$. göze kayar, $j = 0$ olur ve bakılacak eleman kalmaz; 1, 0. göze yazılır → 1, 3, 2, 4.
- $i = 2$: `tmp = 2`. 2 < 3: 3 sağa kayar, $j = 1$. 2 < 1 değil, döngüden çıkılır; 2, 1. göze yazılır → 1, 2, 3, 4.

Sonra son elemanı 4 yerine 0 yaparak gözlemi `tmp` ve `j` değerleriyle takip etti (ekrandan, 01:55:00):

- İlk iki adımdan sonra dizi 1, 2, 3, 0'dır. $i = 3$: `tmp = 0`, $j = 3$.
- $j = 3$: 0 < 3, 3 sağa kayar, $j = 2$.
- $j = 2$: 0 < 2, 2 sağa kayar, $j = 1$.
- $j = 1$: 0 < 1, 1 sağa kayar, $j = 0$.
- $j > 0$ sağlanmaz, döngüden çıkılır; 0, 0. göze yazılır → 0, 1, 2, 3.

| tmp | j |
|---|---|
| 0 | 3 |
|  | 2 |
|  | 1 |
|  | 0 |

### 8.4 Insertion sort'un kullanım yerleri

Hoca, karmaşıklığı $n^2$ olmasına rağmen insertion sort'un tercih edilen iyi bir algoritma olduğunu söyledi:

- **Yarı sıralı diziler:** Daha önce sıralanmış, ama zamanla çok hareket olduğu için yer yer bozulmuş dizilerde elemanların en başa kadar taşınması gerekmez; bozulan elemanlar kolayca yerine yerleştirilir.
- **Az elemanlı diziler:** Quicksort, merge sort gibi algoritmaların özyinelemeli fonksiyon çağırma yüküne göre daha basit olduğu için tercih edilebilir.

### 8.5 Worst case analizi

Dış döngü $n$ kez dönmeye yakın çalışır (ekranda "n iteration, outer loop" notu; döngü sınırı $n-1$ olarak düzeltildi). Asıl soru iç döngüye worst case'te kaç kez girildiğidir.

Hoca önce worst case'in dizinin küçükten büyüğe sıralı olduğu durum olduğunu söyledi, sonra düzeltti: worst case, dizinin **ters (büyükten küçüğe) sıralı** olduğu durumdur. Örneğin 9, 8, 7, 6, ... dizisinde 8, 9 ile karşılaştırılır; 7 için 9 ve 8 kaydırılır; 6 için 9, 8, 7 kaydırılır. Her eleman en başa kadar gitmek zorundadır, yani iç döngüye $i$ kez girilir. Toplam:

$$C_{worst}(n) = \sum i = \frac{n(n+1)}{2} \approx \frac{n^2}{2} \;\Rightarrow\; n^2$$

> **Ders sonrası not:** Hoca toplamı $i = 1$'den $n$'e kadar yazdı. Döngü $i = 1$'den $n-1$'e kadar döndüğünden tam karşılaştırma (kaydırma) sayısı $\sum_{i=1}^{n-1} i = \dfrac{n(n-1)}{2}$'dir; örneğin 10 elemanlı ters sıralı dizide 45 kaydırma yapılır. İki ifade de $\dfrac{n^2}{2}$ mertebesindedir, asimptotik sonuç ($n^2$) değişmez.

Best case analizine geçilmeden kayıt sona erdi; derse başka bir oturumda devam edildi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00): Aynı işi yapan iki algoritmanın karmaşıklıkları $2n^2 + 5n + 9$ ve $2n^2 + 4n + 12$'dir. Hangisi daha iyidir?

> **Çözüm:** $n = 10$ için birincisi 259, ikincisi 252 adım yapar; küçük $n$'de ikincisi biraz önde görünür. Asimptotik analizde sabitler ve katsayılar atılıp en yüksek üslü terim bırakılınca ikisi de $n^2$ olur; karmaşıklıkları eşdeğerdir.

**Soru 2** (ekrandan, 00:20:00): $f(n) = 10n + 30$ için $f(n) \in O(n)$ olduğunu gösterin.

> **Çözüm:** $10n + 30 \le c\,n \iff 30 \le (c-10)\,n$. $n_0 = 1$, $c = 40$ ile $30 \le 30$ sağlanır ve $n$ büyüdükçe sağ taraf artar. Dolayısıyla $10n + 30 \in O(n)$.

**Soru 3** (ekrandan, 00:25:00): $n^2 + n \in O(n^3)$ midir?

> **Çözüm:** Evet. $n_0 = 1$, $c = 2$ ile $n^2 + n \le 2n^3$ her $n \ge 1$ için sağlanır. Ama en yakın üst sınır $n^2$'dir; $O(n^3)$ yanlış değil, yalnız gereğinden gevşektir.

**Soru 4** (ekrandan, 00:30:00): $n^2 + n \in O(n)$ midir?

> **Çözüm:** Hayır. $c = 5$, $n_0 = 1$ ile $n = 1, 2, 3, 4$ için eşitsizlik sağlanır ($2 \le 5$, $6 \le 10$, $12 \le 15$, $20 \le 20$), ama $n = 5$'te $30 \le 25$ bozulur. Herhangi bir sabit $c$ için $n^2 + n \le c\,n \iff n + 1 \le c$ olduğundan eşitsizlik $n \ge c$ olunca hep bozulur.

**Soru 5** (derste sözlü, 00:36:05 ve 00:37:46): $5n^2 \in \Omega(n^2)$ midir? $5n^2 \in \Omega(n)$ midir?

> **Çözüm:** İkisi de evet. $5n^2 \ge 1 \cdot n^2$ her $n \ge 1$ için sağlanır ($c = 1$). $5n^2 \ge 3n$ de $n_0 = 1$, $c = 3$ ile sağlanır.

**Soru 6** (ekrandan, 01:00:00): $f(n) = 2n + 5$ için $f(n) \in \Theta(n)$ olduğunu gösterin.

> **Çözüm:** Üst sınır: $(c_1 - 2)\,n \ge 5$; $n_0 = 1$, $c_1 = 7$ ile sağlanır, $f(n) \in O(n)$. Alt sınır: $(2 - c_2)\,n \ge -5$; $c_2 = 1$ ile her $n \ge 1$ için sağlanır, $f(n) \in \Omega(n)$. İkisi birlikte $f(n) \in \Theta(n)$ verir.

**Soru 7** (derste sözlü, 01:13:43): Bir dizinin en büyük elemanını bulmanın best, worst ve average case'i nedir?

> **Çözüm:** Üçü de $n$'dir (tam olarak $n-1$ karşılaştırma); bütün diziye bakmadan en büyüğe karar verilemez. Bu yüzden karmaşıklık $\Theta(n)$ diye gösterilir.

**Soru 8** (ekrandan, 01:25:00): Sıralı aramada başarılı arama olasılığı $p$ ise ortalama karşılaştırma sayısı nedir?

> **Çözüm:** $C_{avg}(n) = \dfrac{p}{n}(1 + 2 + \dots + n) + n(1-p) = p\,\dfrac{n+1}{2} + n(1-p)$. $p = 1$ için $\dfrac{n+1}{2}$, $p = 0$ için $n$; average case $O(n)$'dir.

**Soru 9** (derste sözlü, 01:54:41): Insertion sort'ta worst case'te iç döngüye kaç kez girilir?

> **Çözüm:** Worst case, dizinin ters sıralı olduğu durumdur. $i$. eleman için iç döngüye $i$ kez girilir; toplam $\sum_{i=1}^{n-1} i = \dfrac{n(n-1)}{2}$, yani $n^2$ mertebesinde.

## Dersin Toparlaması

Bu derste karmaşıklığın girişteki eleman sayısına bağlı, asimptotik olarak nasıl ifade edileceği işlendi: sabitler ve katsayılar atılır, en yüksek üslü terim bırakılır; ama çok büyük sabitlerde ve $m \times n$ türü karmaşıklıklarda dikkatli olunur. Ardından üç asimptotik notasyon tanımlandı ve örneklerle sınandı: Big-O üst sınırı (en yakın üst sınır tercih edilir), Big-Omega alt sınırı, Big-Theta ise ikisini birlikte sağlayan sıkı sınırı verir. Her tanımda eşitsizliğin bir $n_0$'dan sonra bütün $n$ değerleri için sağlanması gerektiği vurgulandı.

İkinci yarıda best, worst ve average case kavramları özyinelemeli olmayan algoritmalar üzerinde uygulandı: findMax'ta üç durum eşit olduğundan karmaşıklık $\Theta(n)$; sıralı aramada worst case $\Theta(n)$, best case $\Theta(1)$, average case $p\frac{n+1}{2} + n(1-p)$ yani $O(n)$ bulundu. Son olarak insertion sort'un algoritması kuruldu ve worst case karmaşıklığının $n^2$ mertebesinde olduğu gösterildi; best case analizine sonraki oturumda devam edildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
