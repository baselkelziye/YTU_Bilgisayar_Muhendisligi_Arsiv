# Ders 4 Genişletilmiş Notu: Insertion Sort'un Durum Analizi ve Büyüme Hızlarının Karşılaştırılması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Insertion Sort'un En Kötü Durumu
- 2. Insertion Sort'un En İyi Durumu
- 3. Insertion Sort'un Ortalama Durumu
- 4. Algoritmanın Tamamı İçin O, Θ ve Ω Gösterimi
- 5. Karmaşıklık Sınıflarının Büyüme Hızları
- Örnek Sorular
- Dersin Toparlaması

## 1. Insertion Sort'un En Kötü Durumu

Kayıt, insertion sort analizinin ortasından başlıyor. Insertion sort her adımda bir elemanı alır ve onu solundaki, zaten sıralanmış kısımda doğru yerine yerleştirir. Bu yerleştirme işi iç döngüde yapılır; dış döngü ise ikinci elemandan son elemana kadar bu işi tekrarlar.

En kötü durum (worst case), dizinin tersten sıralı olduğu durumdur. Tahtadaki örnek 9 8 7 5 dizisidir (ekrandan, 00:05:00). Böyle bir dizide yeni gelen her eleman sıralı kısmın bütün elemanlarından küçüktür. Bu yüzden her elemanı doğru yere yerleştirmek için dizinin en başına kadar gitmek gerekir: $i$. eleman için $i$ karşılaştırma yapılır. Toplam karşılaştırma sayısı

$$C_{worst} = \sum_{i=1}^{n-1} i$$

olur. Bu toplam $n^2$ mertebesindedir. Bu yüzden insertion sort'un en kötü durumu için $C_{worst} \in O(n^2)$ yazılır. Tersten sıralı bir dizide karşılaştırma sayısı her zaman aynı olduğundan, en kötü durum için $C_{worst} \in \Theta(n^2)$ demek de doğrudur; hoca ikisinin de uygun olduğunu söyledi (ekrandan, 00:05:00).

> **Ders sonrası not:** Tahtada $\sum_{i=1}^{n-1} i = \frac{n(n+1)}{2}$ yazıldı (ekrandan, 00:05:00); doğrusu $\frac{n(n-1)}{2}$'dir. 9 8 7 5 dizisinde karşılaştırma sayıları 1, 2, 3 ve toplam $6 = \frac{4 \cdot 3}{2}$ olur (python ile doğrulandı). Mertebe sonucu ($n^2$) değişmez.

## 2. Insertion Sort'un En İyi Durumu

En iyi durum (best case), dizinin zaten küçükten büyüğe sıralı olduğu durumdur. Tahtadaki örnek 5 7 8 9 dizisidir (ekrandan, 00:05:00). 7'yi yerleştirmek için yalnız 5 ile bir karşılaştırma yapılır; 7 yerinde olduğu için ona dokunulmaz. 8 için de, 9 için de aynı şekilde tek karşılaştırma yapılır. Elemanın yeri değişmediği için iç döngü daha fazla devam etmez. Toplam:

$$C_{best} = \sum_{i=1}^{n-1} 1 = n-1$$

Bu durumda $C_{best} \in O(n)$, $C_{best} \in \Theta(n)$ ve $C_{best} \in \Omega(n)$ yazılabilir. Hoca, burada $\Theta(n)$'in rahatlıkla söylenebileceğini vurguladı ve tahtada $C_{best} \in \Theta(n)$ ifadesini işaretledi (ekrandan, 00:05:00).

**Soru:** En iyi durum karmaşıklığının $n$'den düşük olma ihtimali var mı?
**Cevap:** Yok. En iyi durumda bile dizinin bir kez baştan sona gezilmesi ve her elemanın yerinde olup olmadığının kontrol edilmesi gerekir (bir öğrencinin cevabı, hoca onayladı). Bu yüzden en iyi duruma $\Theta(n)$ denebilir.

Hoca burada bir ayrıma dikkat çekti: Hangi gösterimin kullanılacağı, hangisinin daha anlaşılır olduğuna ve gerçekten sağlanıp sağlanmadığına bakılarak seçilir. Örneğin bir dizinin en büyük elemanını bulma işlemine $\Theta(n)$ denebilir, çünkü bu işlemde en iyi, en kötü ve ortalama durumlar birbirine eşittir; bazı girdilerde bir kez, bazı girdilerde $n$ kez çalışma gibi bir durum yoktur. Insertion sort'ta ise durum farklıdır.

**Soru:** Insertion sort'un karmaşıklığına $\Theta(n)$ diyebilir misiniz? (ekrandan, 00:05:00)
**Cevap:** Diyemezsiniz. Karmaşıklık her zaman $n$ olmadığı için, en kötü durumda $n^2$'ye çıktığı için $\Theta(n)$ yanlıştır.

## 3. Insertion Sort'un Ortalama Durumu

### 3.1 Ortalama durum ne demek?

Ortalama durumda (average case) dizi ne küçükten büyüğe ne büyükten küçüğe sıralıdır; elemanlar rastgele yerlerdedir. Hoca bunu bir örnek diziyle gösterdi: bazı elemanlar için bir, bazıları için iki, bazıları için üç karşılaştırma yapılır. Sözlü anlatıma göre 2'yi yerleştirmek için bir karşılaştırma, 7'yi yerleştirmek için iki karşılaştırma (hem 9 hem 2 ile), 11'i yerleştirmek için bir karşılaştırma ve 5'i yerleştirmek için üç karşılaştırma yapılıyor. Amaç, rastgele elemanlardan oluşan bir dizi verildiğinde ortalama karşılaştırma sayısını hesaplamaktır.

<!-- BELİRSİZ: Örnek dizi karelerde görünmüyor; altyazıdan 9 2 7 11 5 gibi bir dizi olduğu anlaşılıyor. Bu diziyle 5 için karşılaştırma sayısı (11, 9, 7, 2 ile) 4 çıkar, hoca sözlü olarak 3 dedi. Dizinin tam hali doğrulanamadı. -->

### 3.2 İç döngü: bir elemanı yerleştirmenin ortalama maliyeti

Hesap iç döngünün koşulu üzerinden yapılır. Tahtada akış diyagramında bu koşul şöyle yazılı (ekrandan, 00:10:00):

```c
while (j > 0 && tmp < a[j-1])
```

Koşul doğru olduğu sürece (T kolu) eleman bir sağa kaydırılır ve döngü tekrar eder. Hoca hesapları basit tutmak için dizi indislerini 0'dan değil 1'den başlattı.

Tahtada İngilizce olarak şu tanım yazılı (ekrandan, 00:10:00): eleman "at the $K^{th}$ position" başlıyor ve "it winds up at position $J$", yani $k$. pozisyondaki eleman sonunda $j$. pozisyona yerleşiyor ($1 \dots j \dots k$). Bu durumda yapılan karşılaştırma sayısı:

$$k - j + 1$$

Birinci örnek: 3 5 7 4 2 6 dizisinde 3, 5 ve 7 yerleşmiş, şimdi $k$. eleman olan 4 yerleştirilecek (ekrandan, 00:10:00). 4 önce 7 ile, sonra 5 ile, sonra 3 ile karşılaştırılır. 7 ve 5 sağa kayar, 4 ikinci pozisyona ($j=2$) gelir. $k=4$ olduğundan karşılaştırma sayısı $4 - 2 + 1 = 3$'tür (ara adım eklendi).

İkinci örnek: 1 2 3 7 0 dizisinde $k$. eleman 0'dır ve en başa ($j=1$) gelmesi gerekir (ekrandan, 00:10:00). 0, 7 ile, 3 ile, 2 ile, 1 ile karşılaştırılır; yani sıralı kısmın bütün elemanlarıyla karşılaştırma yapılır.

> **Ek bilgi (derste anlatılmadı):** $k-j+1$ formülü, elemanın durduğu yerde de bir "başarısız" karşılaştırma yapıldığını sayar. Eleman en başa ($j=1$) geliyorsa yukarıdaki kodda `j > 0` koşulu bozulduğu için son eleman karşılaştırması yapılmaz; 1 2 3 7 0 örneğinde kod 4 karşılaştırma yapar, formül 5 verir. Bu fark yalnız bir sabit kadardır ve mertebe sonucunu değiştirmez.

Ortalamayı bulmak için $j$'nin nerede olabileceğine bakılır. Eleman 1., 2., 3., …, $k$. pozisyona yerleşebilir. Tahtada 1 2 3 7 0 örneğinin altına $j=1$, $j=2$, $j=3$, $j=4$ yazıldı (ekrandan, 00:15:00). Her pozisyonun eşit olasılıklı olduğu kabul edilirse ortalama karşılaştırma sayısı, $k-j+1$'in $j=1$'den $k$'ya kadar ortalamasıdır (ekrandan, 00:15:00):

$$\frac{1}{k}\sum_{j=1}^{k}(k-j+1) = \frac{1}{k}\left(k^2 - \frac{k(k+1)}{2} + k\right) = \frac{k+1}{2}$$

Ara adımlarda ilk derste görülen üç toplam kullanıldı:

- $\sum_{j=1}^{k} k = k^2$ (toplanan terim $j$'ye bağlı değildir, $k$ tane $k$ toplanır),
- $\sum_{j=1}^{k} j = \frac{k(k+1)}{2}$,
- $\sum_{j=1}^{k} 1 = k$.

Parantez açılıp terimler sadeleştirilince $\frac{k+1}{2}$ kalır. Tahtada bu sonuç "inner loop" diye işaretlendi: iç döngünün ortalama maliyeti (ekrandan, 00:15:00).

### 3.3 Dış döngü: $n$ elemanın ortalama maliyeti

$\frac{k+1}{2}$ yalnız bir elemanı doğru yere yerleştirmenin ortalama maliyetidir; tahtada "inner loop: $\frac{K+1}{2}$ ⟹ for 1 element" yazıyor (ekrandan, 00:20:00). Dizide $n$ eleman var ve dış döngü ikinci elemandan $n$. elemana kadar, yani $n-1$ kez bu işi yapar. Dizi 1'den başladığı için toplam $k=2$'den $n$'e kadardır. "Average cost for $N$ element" (ekrandan, 00:20:00):

$$\sum_{k=2}^{n}\frac{k+1}{2} = \sum_{k=1}^{n-1}\frac{k+2}{2}$$

İndis kaydırılırken $k$ yerine $k+1$ yazıldı, böylece toplam $k=1$'den $n-1$'e kadar giden ve terimi $\frac{k+2}{2}$ olan bir toplama dönüştü. Bu toplam açılınca sonuç

$$\frac{1}{4}n^2 + \frac{3}{4}n - 1$$

olur. Buradan en yüksek dereceli terim alınarak

$$C_{average} \in O(n^2)$$

yazıldı; altına $\Theta(n^2)$ da eklendi (ekrandan, 00:20:00).

> **Ders sonrası not:** Tahtadaki ara adımda toplam $\frac{1}{2}\cdot\frac{(n+1)(n+2)}{2}$ olarak yazıldı ve son ifade $\frac{1}{4}n^2 + \frac{3}{n} - 1$ biçiminde görünüyor (ekrandan, 00:20:00). Doğru açılım şöyledir: $\sum_{k=1}^{n-1}\frac{k+2}{2} = \frac{1}{2}\left(\frac{(n-1)n}{2} + 2(n-1)\right) = \frac{(n-1)(n+4)}{4} = \frac{n^2}{4} + \frac{3n}{4} - 1$. Bu sonuç $n = 2, \dots, 11$ için python ile doğrulandı. Hoca sözlü olarak da "1 bölü 4 n kare artı 3 n eksi 1" mertebesinde bir sonuç okudu; mertebe sonucu ($n^2$) değişmez.

Hoca hesabı kısaca şöyle özetledi: Önce iç döngü, yani tek bir elemanı $k$. pozisyondan $j$. pozisyona taşımanın ortalama maliyeti hesaplandı. $k-j+1$ karşılaştırma $j=1$'den $k$'ya kadar toplanıp $k$'ya bölündü ve $\frac{k+1}{2}$ bulundu. Sonra bu iş dış döngüde $n-1$ kez tekrarlandığı için $\frac{k+1}{2}$, $k=2$'den $n$'e kadar toplandı ve $n^2$ mertebesinde bir sonuç çıktı.

## 4. Algoritmanın Tamamı İçin O, Θ ve Ω Gösterimi

### 4.1 Insertion sort'un tamamı

Biri size insertion sort'un zaman karmaşıklığını sorarsa bunu söylemenin en anlaşılır yolu $O(n^2)$'dir. Çünkü en iyi durumda karmaşıklık $n$, en kötü ve ortalama durumda $n^2$'dir; $O(n^2)$ üst sınırı bunların hepsini kapsar. Böylece best, worst ve average ayırt etmeden algoritmanın tamamı için tek bir ifade kullanılmış olur.

Insertion sort'un karmaşıklığına $\Omega(n)$ da denebilir. Bu ifade algoritmanın en iyi ihtimalle $n$ karmaşıklıkta çalışabileceğini, alt sınırın $n$ olduğunu söyler.

Bu sırada bir öğrenci tahtada $O(n)^2$ yazıldığını fark etti; hoca bunun dalgınlıkla yapıldığını söyleyip $O(n^2)$ olarak düzeltti.

**Soru:** Ortalama durum için $O(n^2)$ dedik; aynı zamanda $\Theta(n^2)$ da diyebilir miydik?
**Cevap:** Hoca $\Theta(n^2)$ da denebileceğini söyledi, ama kitaplarda ortalama durum için genelde $\Theta$ kullanılmadığını belirtti. Ortalama hesapta sonuç $n^2$ çıksa da, gerçek girdilere göre karmaşıklık her zaman $n^2$ olmayabilir; bazı girdilerde $n$ türünden bir değer kalabilir. Ortalama durumun en kötü ihtimalle $n^2$ olacağından emin olunduğu için güvenli ifade $O(n^2)$'dir.

<!-- BELİRSİZ: Bu cevabın altyazısı dağınık; hocanın ortalama durumda Θ kullanılmamasının gerekçesini hangi sözcüklerle verdiği tam çıkmıyor. -->

### 4.2 Θ ne zaman kullanılır?

Hoca konuyu bir kez daha üzerinde durarak açıkladı. 1'den $n$'e kadar sayıları toplayan bir algoritma tasarlanırsa, best, worst ve average her durumda karmaşıklık $n$'dir: $n$ elemanlık bir döngü vardır ve ne olursa olsun her zaman $n$ kez dolaşılır. Bu algoritmaya $\Theta(n)$ demek çok doğrudur, çünkü başka yolu yoktur.

Aynı şekilde klasik algoritmayla iki matris çarpılırsa, girdiler ne olursa olsun karmaşıklık $n^3$ çıkar; buna $\Theta(n^3)$ denebilir. Matris çarpımı için $n^3$'ten daha az işlem yapan yöntemler de vardır, ama klasik algoritma her zaman $n^3$'tür.

Tersine, bazı girdilerde karmaşıklık daha az ya da daha çok oluyorsa, yani mertebe bozuluyorsa $\Theta$ dememek gerekir.

> **Hocanın vurgusu:** Kitaplarda genelde best case Big Omega ile, average case Big Theta ile, worst case Big O ile gösteriliyor. Bu doğru bir gösterim şekli değil. Dikkat etmeniz gereken şey, gösterimin gerçekten sağlanıp sağlanmadığıdır. Örneğin en kötü durumda karmaşıklık her zaman $n^2$ oluyorsa en kötü duruma $\Theta(n^2)$ diyebilirsiniz.

**Soru:** Siz worst, best ve average case için sırasıyla Big O, Omega ve Theta kullanmanın yanlış olabileceğini söylediniz; demek ki bazen olur, bazen olmaz, kesin bir ifade değil mi?
**Cevap:** Evet; "yanlış olur" değil, "yanlış olabilir" deniyor. O kalıbı garantili gibi kullanmak doğru değildir. Örneğin sıralı aramada (sequential search) aranan eleman dizide yoksa dizinin sonuna kadar bakmak zorunludur, bakmamak gibi bir şans yoktur. En kötü durum elemanın dizide bulunmadığı durum olduğu için sıralı aramanın en kötü durumuna $\Theta(n)$ denebilir.

> **Hocanın vurgusu:** Bu ayrım başta karışık gelir, bir süre sonra alışılır. Yanlış yapacağınızı düşündüğünüz anda kendinizi garantiye alın ve Big O kullanın.

### 4.3 En büyük elemanı bulma

**Soru:** Bir dizideki en büyük elemanı bulan algoritmanın karmaşıklığına $\Theta(n)$ diyebilir miyim?
**Cevap:** Kesinlikle. findMax'te en kötü durumda $n$, en iyi durumda $n$, ortalama durumda da $n$ adım yapılır (tahtada "findMax: worst case = N" yazılmaya başlandı, ekrandan, 00:25:00). Üçü de tuttuğu için findMax'in zaman karmaşıklığını genel olarak ifade etmek için $\Theta(n)$ denebilir.

### 4.4 Θ'yi algoritmaya bakarak seçmek

**Soru:** O zaman koşullu bir durum yoksa, yalnız iterasyona bakıyorsak $\Theta$ üzerinden gidebilir miyiz? İnsanın aklına "`if` varsa olasılık vardır" gibi geliyor.
**Cevap:** Tam böyle genellememek gerekir; uymadığı bir durumla karşılaşılabilir. Kural şudur: Karmaşıklığın ne alta indiğini ne üste çıktığını kesin biliyorsanız $\Theta$ diyebilirsiniz. Insertion sort'un zaman karmaşıklığına $\Theta(n^2)$ diyemezsiniz, çünkü en iyi durumda $n$'e iniyor, en kötü durumda $n^2$'ye çıkıyor. Belirleyici olan `if` değil, `while`'dır: döngüye girdikten sonra `if` zaten döngü kadar çalışır; önemli olan döngünün kaç kez döneceği ve bunun girdiye göre değişip değişmediğidir. En doğru yol, algoritmaya bakıp best, worst ve average durumlarının ne olduğunu çıkarmak, gösterimi ondan sonra seçmektir.

## 5. Karmaşıklık Sınıflarının Büyüme Hızları

Hoca dersi, bütün dönem boyunca akılda tutulması gereken bir tabloyla bitirdi. Bir algoritmanın karmaşıklığının $\lg n$, $n$ ya da $n^2$ olması, $n$ sonsuza giderken çalışma süresini çok büyük ölçüde etkiler. Tablonun başlığı "Growth rate of … in nanoseconds", yani her adımın 1 nanosaniye sürdüğü varsayımıyla çalışma süreleri (ekrandan, 00:30:00 ve 00:35:00):

| $n$ | $\lg n$ | $n$ | $n \lg_2 n$ | $n^2$ | $2^n$ | $n!$ |
|---|---|---|---|---|---|---|
| 10 | 0,003 µs | 0,01 µs | 0,033 µs | 0,1 µs | 1 µs | 3,66 ms |
| 100 milyon | 0,027 µs | 0,1 s | 2,66 s | 115,7 gün | — | — |

Tabloya ayrıca iki değer eklendi (ekrandan, 00:35:00; ikincisi altyazıdan):

- $n = 100$ için $2^n$ → $4 \times 10^{13}$ yıl,
- $n = 20$ için $n!$ → 77,1 yıl.

> **Ders sonrası not:** Değerler adım başına 1 ns ile python'da hesaplandı: $\lg 10 \approx 3{,}32$ ns, $10 \lg 10 \approx 33$ ns, $2^{10} = 1024$ ns $\approx 1$ µs, $10! = 3.628.800$ ns $\approx 3{,}63$ ms (tahtada 3,66 ms), $\lg 10^8 \approx 26{,}6$ ns, $10^8 \lg 10^8$ ns $\approx 2{,}66$ s, $10^{16}$ ns $\approx 115{,}7$ gün, $2^{100}$ ns $\approx 4{,}0 \times 10^{13}$ yıl, $20!$ ns $\approx 77{,}1$ yıl. Hoca anlatırken bazı değerleri "milisaniye" diye okudu ve $n \lg n$ için "1,66 saniye" dedi; tahtadaki birimler mikrosaniye ve değer 2,66 saniyedir.

Tablonun yorumu:

- **$\lg n$:** $n=10$ ile $n=10^8$ arasında çalışma süresi açısından ciddi bir fark yoktur (0,003 µs ile 0,027 µs). Logaritmik karmaşıklıklı bir algoritma iyi bir algoritmadır.
- **$n$:** $10^8$ eleman için saniye mertebesine yaklaşır (0,1 s).
- **$n \lg n$:** Quicksort, mergesort, heapsort gibi algoritmalar bu sınıftadır. $10^8$ eleman için yaklaşık 2,66 saniye sürer.
- **$n^2$:** Örneğin selection sort. $10^8$ eleman için yaklaşık 115,7 gün sürer.
- **$2^n$ ve $n!$:** Polinomsal değildir. $10^8$'i bırakın, $n=100$ iken bile $2^n$ karmaşıklıklı bir algoritma $4 \times 10^{13}$ yıl çalışır; böyle bir algoritmanın cevabını almak mümkün değildir. $n!$ için durum daha da kötüdür: $n=20$ iken bile 77 yıl gerekir.

$x^2$ ya da $x^4$ gibi karmaşıklıklar polinomsaldır, $2^n$ polinomsal değildir. Hoca bu yüzden derste önce polinom zamanda çözülebilen algoritmalarla ilgilenileceğini, son derslerde de polinom zamanda çözülemeyen problemlerin neler olduğunu ve bunlar hakkında nasıl fikir yürütülebileceğini anlatacağını söyledi.

> **Ders sonrası not:** Hoca $2^n$ ve $n!$ karmaşıklıklı algoritmalar için "non-deterministik polinomsal" ve "çözümü olmayan" ifadelerini kullandı. Doğrusu: NP (nondeterministic polynomial), "polinomsal olmayan" demek değildir; çözümü polinom zamanda doğrulanabilen problemlerin sınıfıdır. Üstel zamanlı bir algoritma problemin çözümsüz olduğunu göstermez, yalnız büyük girdilerde sonucun pratikte alınamayacağını gösterir.

> **Hocanın vurgusu:** Özellikle sıralama algoritmalarında $n \lg n$ karmaşıklıklı bir algoritma ile $n^2$ karmaşıklıklı bir algoritma arasındaki farkı, $n$ 100 milyona çıktığında çok net görebilirsiniz. Bundan sonra algoritma tasarlarken bir algoritmanın diğerine göre ne kadar iyi olduğunu bu hesaplarla anlamak önemlidir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:03:17): Insertion sort'un en iyi durum karmaşıklığının $n$'den düşük olma ihtimali var mı?

> **Çözüm:** Yok. Dizi sıralı olsa bile her elemanın yerinde olup olmadığı en az bir karşılaştırmayla kontrol edilmeli, dizi bir kez baştan sona gezilmelidir. Bu yüzden $C_{best} = n-1$ ve $C_{best} \in \Theta(n)$.

**Soru 2** (ekrandan, 00:05:00): Insertion sort'un karmaşıklığı için $C_{insertion} \in \Theta(n)$ diyebilir misiniz?

> **Çözüm:** Hayır. Karmaşıklık her zaman $n$ değildir; en kötü ve ortalama durumda $n^2$'dir. Algoritmanın tamamı için $O(n^2)$ ya da $\Omega(n)$ denebilir.

**Soru 3** (ekrandan, 00:15:00): $k$. pozisyondaki bir eleman, $1$ ile $k$ arasındaki her pozisyona eşit olasılıkla yerleşebiliyorsa insertion sort'un iç döngüsünde ortalama kaç karşılaştırma yapılır?

> **Çözüm:** $j$. pozisyona yerleşmek $k-j+1$ karşılaştırmadır. Ortalama $\frac{1}{k}\sum_{j=1}^{k}(k-j+1) = \frac{1}{k}\left(k^2 - \frac{k(k+1)}{2} + k\right) = \frac{k+1}{2}$.

**Soru 4** (ekrandan, 00:20:00): $n$ elemanlı bir dizi için insertion sort'un ortalama karşılaştırma sayısı nedir?

> **Çözüm:** $\sum_{k=2}^{n}\frac{k+1}{2} = \sum_{k=1}^{n-1}\frac{k+2}{2} = \frac{n^2}{4} + \frac{3n}{4} - 1$, dolayısıyla $C_{average} \in O(n^2)$ (python ile doğrulandı; tahtadaki ara adımdaki yazım hatası için Bölüm 3.3'teki nota bakın).

**Soru 5** (derste sözlü, 00:20:12): İki matrisin çarpımının karmaşıklığı nedir?

> **Çözüm:** Klasik algoritmayla $n^3$'tür ve girdiye göre değişmediği için $\Theta(n^3)$ denebilir (bir öğrenci "$n^3$" diye cevap verdi, hoca onayladı).

**Soru 6** (derste sözlü, 00:24:28): Bir dizideki en büyük elemanı bulan algoritmanın karmaşıklığına $\Theta(n)$ denebilir mi?

> **Çözüm:** Evet. En iyi, en kötü ve ortalama durumların üçünde de $n$ adım yapılır; bu yüzden $\Theta(n)$.

## Dersin Toparlaması

Bu derste insertion sort'un üç durumu ayrıntılı olarak analiz edildi. Tersten sıralı dizide (en kötü durum) her eleman dizinin başına kadar taşındığı için karmaşıklık $n^2$, sıralı dizide (en iyi durum) her eleman tek karşılaştırmayla yerinde kaldığı için $n$ oldu. Ortalama durum için iç döngünün koşulundan yola çıkıldı: bir elemanı $k$. pozisyondan $j$. pozisyona taşımak $k-j+1$ karşılaştırmadır, bunun ortalaması $\frac{k+1}{2}$'dir ve dış döngüyle toplanınca $\frac{n^2}{4} + \frac{3n}{4} - 1$, yani $n^2$ mertebesi elde edilir.

Ardından gösterim seçimi tartışıldı: $\Theta$ yalnız karmaşıklık girdiden bağımsız olarak aynı mertebede kaldığında (findMax, sayıları toplama, klasik matris çarpımı, sıralı aramanın en kötü durumu) kullanılır; insertion sort'un tamamı için $O(n^2)$ ve $\Omega(n)$ doğru, $\Theta$ ise yanlıştır. "Best = Ω, average = Θ, worst = O" kalıbı ezberlenmemelidir. Son olarak $\lg n$'den $n!$'e kadar büyüme hızları tablosuyla, $n \lg n$ ile $n^2$ arasındaki farkın ve üstel algoritmaların pratikte kullanılamazlığının büyük $n$ değerlerinde ne kadar belirgin olduğu gösterildi; polinom zamanda çözülemeyen problemlerin dönemin son derslerinde ele alınacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
