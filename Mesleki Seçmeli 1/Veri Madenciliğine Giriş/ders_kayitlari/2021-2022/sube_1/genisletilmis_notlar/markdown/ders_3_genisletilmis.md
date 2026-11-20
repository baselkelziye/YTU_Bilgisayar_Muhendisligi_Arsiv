# Ders 3 Genişletilmiş Notu: Veri Görselleştirme, Benzerlik ve Uzaklık Ölçüleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Görselleştirme Tekrarı: Kutu Grafiği, Çubuk Grafik ve Histogram
- 2. Saçılım Grafiği ve Öznitelikler Arası Korelasyon
- 3. Benzerlik ve Farklılık Kavramı
- 4. Tek Öznitelik İçin Benzerlik ve Farklılık
- 5. Öklid, Minkowski ve Manhattan Uzaklıkları
- 6. Metrik Olma Koşulları ve Benzerliklerin Özellikleri
- 7. İkili Veride Benzerlik: SMC ve Jaccard
- 8. Kosinüs Benzerliği
- 9. Pearson Korelasyonu
- 10. Ölçü Seçimi, Farklı Tipleri Birleştirme ve Entropi
- Örnek Sorular

## 1. Görselleştirme Tekrarı: Kutu Grafiği, Çubuk Grafik ve Histogram

Ders, bir önceki derste başlanan veri görselleştirme slaytlarının hızlı bir tekrarıyla açıldı.

### 1.1 Kutu grafiği (boxplot)

Kutu grafiği verinin istatistiksel özetini tek bir çizimde verir. Kutunun içindeki çizgi medyandır; kutunun alt ve üst kenarları birinci çeyrek (Q1) ve üçüncü çeyrektir (Q3). Hoca burada bir noktaya dikkat çekti: bıyıkların ucundaki değer verinin maksimumu değildir. Veride bir aykırı değer (outlier) varsa maksimum o olurdu; kutu grafiği ise uç değerleri ayrıca nokta olarak gösterir, bıyık ucunu aykırı olmayan değerlere göre çizer.

Slaytlardaki örnek kodlar R ile verilmiştir. Hoca, R'nin veri madenciliğinde en popüler dillerden biri olduğunu, özellikle matematik ve istatistik ağırlıklı çalışanlar arasında yaygın olduğunu söyledi. Python başka yönlere de (arayüz vb.) yayıldı; scikit-learn gibi kütüphanelerdeki ve MATLAB'deki karşılıklar R koduna çok benzer. Derste bu kodlar uygulanmayacak; slayttaki kodun ne yaptığı sorulmayacak, yalnız aşinalık için gösteriliyor. R'deki özet fonksiyonu minimum, çeyrekler, medyan gibi değerleri verir.

### 1.2 Çubuk grafik ve histogram

Hoca sınıfa "Bar chart ile histogramın farkı ne?" diye sordu. Çubuk grafikte (bar chart) değer eksenden doğrudan okunur: örneğin mayıs ayındaki satış miktarı x ekseninde ay, y ekseninde satış olarak görülür.

Histogram da çubuklarla gösterilir, ama dikey eksende frekans vardır. Örneğin 35-40 aralığındaki çubuğun yüksekliği 1 ise o aralığa bir örnek düşmüş demektir. Yani histogram her aralığa (bin) kaç örnek düştüğünü gösterir. Bin sayısı programda parametre olarak kendiniz verilebilir; verilmezse araç bir varsayılanla otomatik böler. <!-- BELİRSİZ: Altyazıda varsayılan bin sayısı ("10'a böler") net değil. -->

Saçılım grafiklerinin R ile nasıl çizildiği, hocanın deyişiyle, R anlatılırken ayrıca gösterilecek.

## 2. Saçılım Grafiği ve Öznitelikler Arası Korelasyon

Saçılım grafiğinde (scatter plot) öznitelikler ikişer ikişer çizilir ve birbirleriyle ilişkileri görülür: pozitif korelasyon mu var, negatif korelasyon mu, yoksa hiç korelasyon yok mu? Slaytta dört panel vardı (ekrandan, 00:05:00): noktaların sağa doğru yükseldiği "Positively Correlated", sağa doğru alçaldığı "Negatively Correlated" ve noktaların dağınık olduğu iki "Uncorrelated" paneli.

> **Hocanın vurgusu:** Öznitelikler arasında çok fazla korelasyon olmasın. Bütün öznitelikleriniz birbiriyle pozitif korelasyonlu çıkarsa hepsi aynı şeyi söylüyor demektir. Yani pozitif korelasyon her zaman iyi değildir.

## 3. Benzerlik ve Farklılık Kavramı

Dersin üçüncü ana konusu verinin benzerliğini ölçmekti. Hoca önce "Neyin benzerliğini ölçeceğiz?" diye sordu. Elimizde bir tablo var; iki satırın, yani iki örneğin (instance), iki nesnenin, iki vektörün birbirine ne kadar benzediğini ölçebiliriz. Aynı şekilde iki sütunun (iki özniteliğin) benzerliği de ölçülebilir.

**Soru:** İki vektörün benzerliğini nasıl ölçersiniz? **Cevap (sınıftan ve hocadan):** Farklarını alırsınız; fark sıfıra yakınsa benzerdirler. Ama farklardan eksi değerler de çıkar ve toplarken birbirini götürür. O zaman farkların karesi alınıp toplanır, sonra karekökü alınır (Öklid uzaklığı). Sınıftan gelen bir başka öneri vektörleri çarpmak, yani iç çarpım (dot product) almaktı; bu da kosinüs benzerliğine götürür.

Öznitelikler her zaman sayısal değildir. Kategorik (nominal) ya da sıralı (ordinal) olabilirler; bunları kullanmak için çoğu zaman sayıya çevirmek gerekir.

Benzerliğin karşıtı farklılıktır (dissimilarity) ve çoğu zaman bir uzaklık (distance) olarak ifade edilir; "Öklid uzaklığı" dememizin nedeni budur. Benzerlik genelde $0$-$1$ aralığında çıkar ama çıkmak zorunda değildir; farklılık ise $0$'dan sonsuza kadar büyük değerler alabilir.

## 4. Tek Öznitelik İçin Benzerlik ve Farklılık

Slayttaki tablo (ekrandan, 00:10:00), tek bir öznitelik için benzerlik ve farklılığı öznitelik tipine göre verir. $p$ ve $q$ iki nesnenin o öznitelikteki değerleridir. Çok öznitelikli nesnelerin yakınlığı, tek tek özniteliklerin yakınlıkları birleştirilerek tanımlanır.

| Öznitelik tipi | Farklılık | Benzerlik |
|---|---|---|
| Nominal | $d=0$ ($p=q$), $d=1$ ($p\neq q$) | $s=1$ ($p=q$), $s=0$ ($p\neq q$) |
| Ordinal | $d=\frac{\lvert p-q\rvert}{n-1}$ | $s=1-\frac{\lvert p-q\rvert}{n-1}$ |
| Aralık ya da oran | $d=\lvert p-q\rvert$ | $s=-d$, $s=\frac{1}{1+d}$ ya da $s=1-\frac{d-\min_d}{\max_d-\min_d}$ |

Ordinal satırında değerler $0$'dan $n-1$'e tam sayılara eşlenir; $n$ değer sayısıdır.

### 4.1 Aralık ve oran tipindeki öznitelikler

Sayısal (interval ya da ratio) özniteliklerde en basit yol iki değerin farkının mutlak değerini almaktır: $d=|p-q|$.

### 4.2 Ordinal öznitelikler

Sıranın önemli olduğu durumda (küçük, orta, büyük gibi) değerler numaralandırılır. Hoca sıfırdan başladı: küçük $0$, orta $1$, büyük $2$; $n=3$. Aradaki fark bulunur ve en büyük değere ($n-1$) bölünür; böylece aslında bir oran elde edilir. Benzerlik için bu oran $1$'den çıkarılır.

Örnek: büyük ($2$) ile küçük ($0$) arasında
$d=\frac{|2-0|}{3-1}=\frac{2}{2}=1$, $s=1-1=0$.
Hoca bu formülün tek yol olmadığını, illa bunun kullanılmak zorunda olmadığını da belirtti.

### 4.3 Nominal öznitelikler

Nominal değerler arasında sıra yoktur; yalnız aynı olup olmadıklarına bakılır. İki değer aynıysa farklılık $0$, aynı değilse $1$'dir. Benzerlik bunun tersidir.

## 5. Öklid, Minkowski ve Manhattan Uzaklıkları

### 5.1 Öklid uzaklığı

En çok bilinen uzaklık Öklid uzaklığıdır. Satırlar karşılaştırılırken (örneğin beş öznitelik varsa) birinci sütunda iki satırın farkı alınıp karesi alınır, ikinci sütundakine eklenir ve böyle devam edilir; en sonunda toplamın karekökü alınır:

$$d(x,y)=\sqrt{\sum_{k=1}^{n}(x_k-y_k)^2}$$

**Soru:** Bu değer $0$-$1$ arasında mı çıkar? **Cevap:** Hayır, $0$-$1$ arasında çıkacak diye bir şey yok.

Slaytta dört nokta ($p_1, \dots, p_4$) bir tabloya yazılmış ve aralarındaki Öklid uzaklıkları bir uzaklık matrisi olarak verilmişti. Hoca, bu değerlerin formülle elde edilebileceğini, örneğin $(2-0)^2+(2-0)^2$'nin karekökü alınarak bulunabileceğini söyledi: $\sqrt{4+4}=\sqrt{8}\approx 2.828$. <!-- BELİRSİZ: Nokta koordinatlarının ve uzaklık matrisinin karesi yok (yaklaşık 00:11:00); tablodaki değerler doğrulanamadı, yalnız sözlü hesap aktarıldı. -->

### 5.2 Minkowski uzaklığı

Minkowski uzaklığı Öklid'in genelleştirilmiş halidir. Öklid'de farkların karesi (üs $2$) alınıp sonra karekök alınıyordu. Üs $3$, $4$ ya da herhangi bir $r$ olabilir:

$$d(x,y)=\left(\sum_{k=1}^{n}|x_k-y_k|^r\right)^{1/r}$$

<!-- BELİRSİZ: Minkowski formülünün slayt karesi yok; formül hocanın sözlü anlatımından ve standart tanımdan yazıldı. -->

- $r=2$: Öklid uzaklığı ($L_2$ normu).
- $r=1$: Manhattan uzaklığı ($L_1$ normu). Burada kare yerine mutlak değer vardır. Aynı değerlerde katkı $0$, farklı değerlerde daha büyük bir değer gelir.
- $r\to\infty$: Minkowski'nin limit durumu ($L_\infty$).

> **Ek bilgi (derste anlatılmadı):** $r\to\infty$ limitinde Minkowski uzaklığı, öznitelikler arasındaki en büyük mutlak farka eşit olur: $d(x,y)=\max_k |x_k-y_k|$. Bu uzaklık "supremum" ya da Chebyshev uzaklığı diye de anılır.

## 6. Metrik Olma Koşulları ve Benzerliklerin Özellikleri

### 6.1 Uzaklığın metrik olması

Hoca önemli bir tanım verdi: bir uzaklık şu üç özelliği sağlıyorsa bir metriktir.

1. **Pozitiflik:** her $x, y$ için $d(x,y)\ge 0$; ve $d(x,y)=0$ yalnız $x=y$ iken.
2. **Simetri:** $d(x,y)=d(y,x)$. Uzaklık hesaplanırken değerler birbirinden çıkarılıyor ya da başka işlemler yapılıyor; sıranın sonucu değiştirmemesi gerekir.
3. **Üçgen eşitsizliği:** $d(x,z)\le d(x,y)+d(y,z)$. Üçgende bir kenarın uzunluğu diğer iki kenarın toplamından büyük olamaz; bu koşul onun benzeridir.

**Soru:** Öklid uzaklığı her zaman pozitif mi? **Cevap:** Evet. **Soru:** Simetrik mi? **Cevap:** Evet, çıkarma sırası değişse de kareler aynı kalır. **Soru:** Üçgen eşitsizliğini sağlar mı? **Cevap:** Evet; üçgenden bildiğimiz gibi kenar uzunluklarıyla aynı mantık. Dolayısıyla Öklid uzaklığı bir metriktir.

### 6.2 Benzerliklerin özellikleri

Benzerlikler için de tipik özellikler vardır (ekrandan, 00:15:00). Benzerliklerde üçgen eşitsizliği genelde sağlanmaz, ama simetri ve pozitiflik genelde sağlanır. $s(x,y)$, $x$ ve $y$ noktaları arasındaki benzerlikse:

1. **Pozitiflik:** $s(x,y)=1$ yalnız $x=y$ iken ($0\le s(x,y)\le 1$).
2. **Simetri:** her $x$ ve $y$ için $s(x,y)=s(y,x)$.

## 7. İkili Veride Benzerlik: SMC ve Jaccard

### 7.1 Neden ayrı bir ölçü?

Öznitelikler ikili (binary, $0$-$1$) olduğunda da uzaklık ölçülmek istenir. Aslında yine değerler birbirinden çıkarılıp toplanabilir. Ancak $1$'lerin taşıdığı anlam çıkarma işleminde kaybolabilir; bu yüzden ikili veri için özel formüller kullanılır.

İkili değişkenler simetrik ya da asimetrik olabilir. Simetrik ikili değişkende $0$ ile $1$ eşit önemdedir; hocanın örneği cinsiyettir (kız/erkek), burada $1$'in $0$'dan daha önemli olduğu bir durum yoktur. Asimetrik ikili değişkende ise $1$ daha önemlidir.

### 7.2 Sayımlar

İki ikili vektör $p$ ve $q$ eleman eleman karşılaştırılır. İlk indis $p$'deki, ikinci indis $q$'daki değeri gösterir (ekrandan, 00:20:00):

- $f_{01}$: $p$'nin $0$, $q$'nun $1$ olduğu öznitelik sayısı.
- $f_{10}$: $p$'nin $1$, $q$'nun $0$ olduğu öznitelik sayısı.
- $f_{00}$: ikisinin de $0$ olduğu öznitelik sayısı.
- $f_{11}$: ikisinin de $1$ olduğu öznitelik sayısı.

### 7.3 SMC ve Jaccard

Basit eşleşme katsayısı (Simple Matching Coefficient, SMC) aynı olan bütün konumları (hem 1-1 hem 0-0) sayar ve toplam sayıya böler:

$$\text{SMC}=\frac{f_{11}+f_{00}}{f_{01}+f_{10}+f_{11}+f_{00}}$$

Hoca anlatırken önce farklı olan konumlara (bir tanesi $1$ iken diğeri $0$ olanlara) baktı ve bunların toplam sayıya bölündüğünü söyledi; bu oran SMC'nin $1$'e tümleyeni, yani bir farklılık ölçüsüdür (ara adım eklendi).

Jaccard katsayısı asimetrik ikili veri içindir. Tek farkı 0-0 eşleşmelerini hesaba katmamasıdır; $1$ sanki $0$'dan daha önemliymiş gibi davranır:

$$J=\frac{f_{11}}{f_{01}+f_{10}+f_{11}}$$

### 7.4 Jaccard katsayısının görüntü işlemede kullanımı

Hoca, Jaccard katsayısının nerede çok kullanıldığını sordu ve görüntü bölütlemeden bir örnek verdi. Bir görüntüde bir araba var ve bunun gerçek (elle işaretlenmiş) bir maskesi var: arabanın olduğu pikseller $1$, araba olmayan pikseller $0$. Algoritmanız da arabanın olduğu yeri bulup bir maske çıkarıyor (örneğin kırmızıya boyuyor). Yönteminizin ne kadar doğru çalıştığını anlamak için iki maskenin ne kadar örtüştüğüne bakmanız gerekir.

Hatalı pikseller iki türlüdür: gerçekte araba olup sizin araba değil ($0$) dediğiniz pikseller ve gerçekte araba olmayıp sizin araba ($1$) dediğiniz pikseller. Doğru bulunan araba pikselleri kesişimdir. Jaccard katsayısı kesişimi, kesişim ile iki tür hatalı piksel toplamına böler. Arabanın dışında kalan, iki maskede de $0$ olan büyük arka plan hesaba hiç katılmaz.

> **Ek bilgi (derste anlatılmadı):** Görüntü bölütlemede bu ölçü genellikle "Intersection over Union" (IoU) adıyla anılır: kesişimin birleşime oranı, ikili maskelerde Jaccard katsayısının ta kendisidir.

### 7.5 Slayttaki örnek

Slayttaki örnek (ekrandan, 00:20:00):

```text
p = 1 0 0 0 0 0 0 0 0 0
q = 0 0 0 0 0 0 1 0 0 1
```

Sayımlar: $f_{01}=2$ (7. ve 10. konum), $f_{10}=1$ (1. konum), $f_{00}=7$, $f_{11}=0$.

$$\text{SMC}=\frac{0+7}{2+1+0+7}=\frac{7}{10}=0.7$$

$$J=\frac{0}{2+1+0}=0$$

Hoca SMC hesabını şöyle gösterdi: iki vektörde aynı olan konumlar tek tek sayılır; 1-1 eşleşmesi yok, 0-0 eşleşmesi $7$ tane; $7$ toplam $10$ konuma bölünür. Jaccard'da ise 0-0'lar alınmadığı için pay $0$'dır ve benzerlik $0$ çıkar. Bu örnek, seyrek ve asimetrik veride SMC'nin yapay olarak yüksek çıkabileceğini gösterir. Sayımlar ve iki sonuç python ile doğrulandı.

## 8. Kosinüs Benzerliği

İki vektör $x$ ve $y$ düşünelim; aralarındaki benzerliğe iki vektör arasındaki açının kosinüsü ile bakılabilir:

$$\cos(x,y)=\frac{x\cdot y}{\|x\|\,\|y\|}$$

Pay iki vektörün iç çarpımıdır. Paydada iki vektörün $L_2$ normları vardır; $L_2$ normu bütün elemanların kareleri toplanıp karekökü alınarak bulunur. Bu ölçüye kosinüs benzerliği (cosine similarity) denir. <!-- BELİRSİZ: Kosinüs formülünün slayt karesi yok (yaklaşık 00:21:00); formül sözlü anlatımdan ve standart tanımdan yazıldı. -->

**Soru:** Bu değer hangi aralıkta çıkar? **Cevap:** $-1$ ile $1$ arasında. **Soru:** Pay ne zaman eksi çıkar? **Cevap:** Vektörlerin elemanlarından bazıları negatif, karşılık gelenleri pozitifse çarpımlar negatif olur ve iç çarpım eksi çıkabilir. Kosinüs olduğu için değer $-1$ ile $1$ arasında gidip gelir.

**Soru:** $x$ ve $y$ birbirine çok benziyorsa sonuç $0$'a mı, $1$'e mi yakın çıkar? **Cevap:** $1$'e. İki vektör aynı yöndeyse aralarındaki açı $0$'dır ve $\cos 0=1$'dir. Değer $1$'e ne kadar yakınsa vektörler o kadar benzerdir.

Hoca ayrıca bu işlemin, vektörleri önce kendi uzunluklarına bölerek birim vektöre çevirmek ve sonra iç çarpım almak anlamına geldiğini belirtti.

## 9. Pearson Korelasyonu

> **Hocanın vurgusu:** Korelasyon önemli.

Korelasyon istatistikten bilinen bir kavramdır: iki değişken arasındaki ilişkiyi söyler. Biri artarken diğeri de artıyor mu, azalıyor mu, yoksa ikisi birbirinden bağımsız mı? Slayttaki tanım (ekrandan, 00:25:00): korelasyon nesneler arasındaki doğrusal ilişkiyi ölçer. İki veri nesnesi $x$ ve $y$ arasındaki Pearson korelasyon katsayısı:

$$\text{corr}(x,y)=\frac{\text{covariance}(x,y)}{\text{standard\_deviation}(x)\cdot\text{standard\_deviation}(y)}=\frac{s_{xy}}{s_x\,s_y}$$

Burada:

$$s_{xy}=\frac{1}{n-1}\sum_{k=1}^{n}(x_k-\bar x)(y_k-\bar y)$$

$$s_x=\sqrt{\frac{1}{n-1}\sum_{k=1}^{n}(x_k-\bar x)^2},\qquad s_y=\sqrt{\frac{1}{n-1}\sum_{k=1}^{n}(y_k-\bar y)^2}$$

$$\bar x=\frac{1}{n}\sum_{k=1}^{n}x_k,\qquad \bar y=\frac{1}{n}\sum_{k=1}^{n}y_k$$

Hoca, kovaryansın hesaplanıp standart sapmaların çarpımına bölündüğünü özetledi. Pratikte bu değerler elle hesaplanmaz; araçlar ve kütüphaneler öznitelikler arası korelasyonu gösteren hazır çıktılar verir.

Değerlerin yorumu:

- $+1$: aralarında pozitif doğrusal korelasyon var; biri artarken diğeri de artar.
- $-1$: aralarında negatif doğrusal korelasyon var; biri artarken diğeri azalır.
- $0$: aralarında (doğrusal) korelasyon yok.

Slaytta farklı korelasyon değerlerine karşılık gelen saçılım grafikleri de gösterildi.

### 9.1 Korelasyonun sınırı

Korelasyonun sıkıntısı yalnız doğrusal ilişkileri göstermesidir; doğrusal olmayan ilişkileri size göstermez. Hocanın gösterdiği örnekte bir değişken diğerine göre önce azalıyor, sonra artıyor. Bu durumda korelasyon hesaplanırsa aralarında korelasyon yok sonucu çıkabilir; oysa aslında yarıya kadar negatif, sonrasında pozitif bir ilişki vardır. <!-- BELİRSİZ: Doğrusal olmayan örneğin slayt karesi yok (yaklaşık 00:27:00); verilerin tam biçimi doğrulanamadı. -->

> **Ek bilgi (derste anlatılmadı):** Klasik örnek $y=x^2$ ilişkisidir: $x$ değerleri sıfırın etrafında simetrik seçilirse $y$, $x$ tarafından tamamen belirlendiği halde Pearson korelasyonu $0$ çıkar.

## 10. Ölçü Seçimi, Farklı Tipleri Birleştirme ve Entropi

### 10.1 Hangi ölçüyü kullanmalı?

Hoca bir senaryo kurdu: bir yerde çalışmaya başladınız ve elinizdeki veriyi analiz edeceksiniz. Önce veriye tipleri ve istatistikleri açısından bakarsınız, aykırı değerler varsa onları temizlersiniz. Sonra öznitelikler (sütunlar, feature'lar) arasındaki ve örnekler arasındaki benzerliğe bakarsınız. Birçok farklı ölçü var; hangisini kullanacağınıza nasıl karar vereceksiniz?

Cevap genelde veriye bağlıdır. En çok kullanılan Öklid uzaklığıdır. Veri pozitifse kosinüs benzerliği kullanılır; örneğin metin madenciliği gibi uygulamalarda. Görüntü işleme ve metin madenciliği için başka bir ölçüden de söz edildi. <!-- BELİRSİZ: Altyazıda "ya kart uzaklık" ve "istatistikteki kareler ... uzaklık olarak kullanılır" geçiyor; Jaccard ve bir istatistiksel ölçü kastediliyor olabilir, doğrulanamadı. -->

### 10.2 Farklı tipteki öznitelikleri birleştirme

Bazen öznitelikler çok farklı tiplerde olur (nominal, ordinal, sayısal, asimetrik ikili...) ama iki nesne için tek bir genel benzerlik gerekir. Hoca, örneğin asimetrik bir öznitelikte iki değer de sıfırsa bunun farklı sayılması gerektiğini söyledi. Slayttaki algoritma (ekrandan, 00:30:00), farklı tipte özniteliklere sahip iki heterojen nesne $x$ ve $y$ için şöyledir:

1. $k$. öznitelik için $[0,1]$ aralığında bir benzerlik $s_k(x,y)$ hesaplanır.
2. $k$. öznitelik için bir gösterge değişkeni $\delta_k$ tanımlanır:
   - $\delta_k=0$: $k$. öznitelik asimetrikse ve iki nesnenin değeri de $0$ ise, ya da nesnelerden birinde $k$. öznitelik eksikse.
   - $\delta_k=1$: diğer durumlarda.
3. Genel benzerlik şu formülle hesaplanır:

$$\text{similarity}(x,y)=\frac{\sum_{k=1}^{n}\delta_k\,s_k(x,y)}{\sum_{k=1}^{n}\delta_k}$$

Böylece asimetrik özniteliklerin 0-0 eşleşmeleri ve eksik değerler hem paydan hem paydadan düşer.

### 10.3 Entropi

Entropi biraz farklı bir kavramdır: verinin size ne kadar bilgi verdiğini gösterir. Hoca, karar ağaçlarının entropi üzerine kurulacağını söyledi. Ayrıca iki vektörün içerdiği bilgiye göre, aralarındaki ortak bilgiyi ölçen bir yaklaşımdan da kısaca söz etti ve hangi ölçünün kullanılacağının yine uygulamaya göre değiştiğini vurguladı. <!-- BELİRSİZ: 00:29:42-00:30:01 arası anlatım bozuk; karşılıklı bilgi (mutual information) kastediliyor olabilir. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:02:40): Çubuk grafik (bar chart) ile histogram arasındaki fark nedir?

> **Cevap (derste verildi):** Çubuk grafikte değer eksenden doğrudan okunur (ör. bir aydaki satış). Histogramda dikey eksen frekanstır; her çubuk bir aralığa (bin) düşen örnek sayısını gösterir.

**Soru 2** (derste sözlü, 00:09:33): Küçük, orta, büyük değerlerini alan bir ordinal öznitelikte küçük ile büyük arasındaki farklılık ve benzerlik nedir?

> **Cevap (derste verildi):** Değerler $0, 1, 2$ diye eşlenir, $n=3$. $d=\frac{|2-0|}{3-1}=1$, $s=1-d=0$.

**Soru 3** (derste sözlü, 00:10:45): Öklid uzaklığı $0$-$1$ aralığında mı çıkar?

> **Cevap (derste verildi):** Hayır; Öklid uzaklığının üst sınırı yoktur. Örneğin $\sqrt{(2-0)^2+(2-0)^2}=\sqrt 8\approx 2.828$.

**Soru 4** (derste sözlü, 00:14:31): Öklid uzaklığı bir metrik midir?

> **Cevap (derste verildi):** Evet. Her zaman pozitiftir (ve yalnız $x=y$ iken $0$'dır), simetriktir ve üçgen eşitsizliğini sağlar.

**Soru 5** (ekrandan, 00:20:00): $p = 1\,0\,0\,0\,0\,0\,0\,0\,0\,0$ ve $q = 0\,0\,0\,0\,0\,0\,1\,0\,0\,1$ için SMC ve Jaccard katsayılarını hesaplayın.

> **Cevap (derste verildi):** $f_{01}=2$, $f_{10}=1$, $f_{00}=7$, $f_{11}=0$. $\text{SMC}=\frac{0+7}{2+1+0+7}=0.7$, $J=\frac{0}{2+1+0}=0$.

**Soru 6** (derste sözlü, 00:21:53): Kosinüs benzerliği hangi aralıkta değer alır, ne zaman negatif çıkar?

> **Cevap (derste verildi):** $[-1,1]$ aralığında. Vektörlerde negatif elemanlar varsa iç çarpım negatif çıkabilir.

**Soru 7** (derste sözlü, 00:23:27): $x$ ve $y$ birbirine çok benziyorsa kosinüs benzerliği $0$'a mı, $1$'e mi yakındır?

> **Cevap (derste verildi):** $1$'e. Aynı yöndeki vektörler arasındaki açı $0$'dır ve $\cos 0=1$'dir.

**Soru 8** (derste sözlü, 00:30:10): Kosinüs uzaklığı ($1-\cos(x,y)$) bir metrik midir?

> **Çözüm (derste verilmedi):** Genel olarak hayır. Pozitiflik koşulu bozulur: $x=(1,2)$ ve $y=(2,4)$ farklı vektörler olduğu halde aynı yöndedir, $1-\cos(x,y)=0$ olur. Üçgen eşitsizliği de bozulabilir: $x=(1,0)$, $y=(1,1)$, $z=(0,1)$ için $d(x,z)=1$, $d(x,y)=d(y,z)=1-\frac{1}{\sqrt 2}\approx 0.293$; $0.293+0.293\approx 0.586<1$. Simetri ise sağlanır. Değerler python ile doğrulandı.

## Dersin Toparlaması

Bu derste önce görselleştirme araçları tekrar edildi: kutu grafiği medyanı ve çeyrekleri gösterir, aykırı değerleri ayrı işaretler; histogram çubuk grafikten farklı olarak aralık başına frekans gösterir; saçılım grafiği öznitelik çiftleri arasındaki korelasyonu görünür kılar. Ardından dersin ana konusu olan benzerlik ve farklılık ölçülerine geçildi. Nominal, ordinal ve sayısal öznitelikler için tek öznitelik formülleri, çok boyutlu sayısal veri için Öklid, Manhattan ve genel Minkowski uzaklıkları, bir uzaklığın metrik olmasının üç koşulu, ikili veride SMC ve Jaccard katsayıları (görüntü bölütlemedeki kullanımıyla), kosinüs benzerliği ve Pearson korelasyonu işlendi.

Son bölümde ölçü seçiminin veriye ve uygulamaya bağlı olduğu, farklı tipteki özniteliklerin gösterge değişkenleriyle tek bir benzerlikte birleştirilebileceği anlatıldı. Entropinin verinin taşıdığı bilgiyi ölçtüğü ve ileride karar ağaçlarının entropi üzerine kurulacağı söylendi. Ders, kosinüs uzaklığının metrik olup olmadığı sorusuyla kapandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
