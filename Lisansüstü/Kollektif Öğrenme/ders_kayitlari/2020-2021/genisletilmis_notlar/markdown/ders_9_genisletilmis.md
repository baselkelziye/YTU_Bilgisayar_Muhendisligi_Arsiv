# Ders 9 Genişletilmiş Notu: AdaBoost Algoritmasının Analizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Konunun Hatırlatması: Regresyon ve Kümelemede Kollektif Öğrenme
- 2. AdaBoost'un Orijinal Yayındaki Hâli
- 3. Teorem 6 ve Neyi İspatladığı
- 4. Tanımlar ve Lemma 1
- 5. İspat, Birinci Kısım: Ağırlık Toplamına Üst Sınır
- 6. İspat, İkinci Kısım: Hatalı Örnekler İçin Eşitsizlik
- 7. İspat, Üçüncü Kısım: Ağırlık Toplamına Alt Sınır ve Birleştirme
- 8. Üst Sınırı En Küçük Yapan β ve Teoremin Sonucu
- 9. Teorem Bize Ne Söylüyor?
- 10. Açık Bırakılan Sorular
- 11. Teori, Beklenti ve Deney
- 12. Ders Sonundaki Soru-Cevaplar
- Örnek Sorular

## 1. Önceki Konunun Hatırlatması: Regresyon ve Kümelemede Kollektif Öğrenme

Ders, bir önceki haftanın konusunun kısa bir hatırlatmasıyla açıldı. Regresyonda kollektif öğrenme kullanmanın sınıflandırmadan çok farklı olmadığı söylenmişti. Farklı olan kümelemeydi: kümelemede her temel öğrenici aynı kümeleri oluştursa bile küme etiketleri birbirinden farklı olabilir. Bir öğrenicinin "1. küme" dediği grup, diğerinin "3. küme" dediği grup olabilir.

Bunun çözümü olarak örneklerin kaç çözümde birlikte aynı kümede yer aldığı sayılmıştı. Bu birlikte bulunma sayılarından bir benzerlik matrisi oluşturulur, bu matris üzerinde hiyerarşik kümeleme uygulanarak sonuç kümeleme bulunur. Bu haftanın konusu bundan tamamen farklıdır: AdaBoost algoritmasının teorik analizi.

## 2. AdaBoost'un Orijinal Yayındaki Hâli

Dersin ana kaynağı, AdaBoost'un önerildiği 1997 tarihli makaledir; derste bu makaledeki Teorem 6'nın ispatı adım adım incelendi. Makalenin bir miktar açıklaması bir tezde de bulunduğu belirtildi. Hoca, kendi hazırladığı "AdaBoost Algoritmasının Analizi" başlıklı ders notunu ekranda paylaşarak ilerledi (ekrandan, 00:10:00).

> **Ek bilgi (derste anlatılmadı):** Altyazıda bozuk geçen yazar adları büyük olasılıkla Yoav Freund ve Robert Schapire'dır. Makale, "A decision-theoretic generalization of on-line learning and an application to boosting" başlığıyla 1997'de Journal of Computer and System Sciences dergisinde yayımlanmıştır.

### 2.1 Algoritma

Ekrandaki algoritma şöyledir (ekrandan, 00:10:00 ve 00:15:00):

```text
Algorithm AdaBoost
Input: sequence of N labeled examples <(x1, y1), ..., (xN, yN)>
       distribution D over the N examples
       weak learning algorithm WeakLearn
       integer T specifying number of iterations
Initialize the weight vector: w_i^1 = D(i) for i = 1, ..., N.
Do for t = 1, 2, ..., T
  1. Set p^t = w^t / sum_{i=1}^{N} w_i^t
  2. Call WeakLearn, providing it with the distribution p^t;
     get back a hypothesis h_t : X -> [0, 1].
  3. Calculate the error of h_t: eps_t = sum_{i=1}^{N} p_i^t |h_t(x_i) - y_i|.
  4. Set beta_t = eps_t / (1 - eps_t).
  5. Set the new weights vector to be
       w_i^{t+1} = w_i^t * beta_t^(1 - |h_t(x_i) - y_i|)
Output the hypothesis
  h_f(x) = 1  if sum_{t=1}^{T} (log 1/beta_t) h_t(x) >= (1/2) sum_{t=1}^{T} log 1/beta_t
           0  otherwise.
```

Aynı ifadeler matematik gösterimiyle:

$$\mathbf{p}^t = \frac{\mathbf{w}^t}{\sum_{i=1}^N w_i^t},\qquad \varepsilon_t = \sum_{i=1}^N p_i^t\,|h_t(x_i)-y_i|,\qquad \beta_t = \frac{\varepsilon_t}{1-\varepsilon_t}$$

$$w_i^{t+1} = w_i^t\,\beta_t^{\,1-|h_t(x_i)-y_i|}$$

$$h_f(x) = \begin{cases} 1 & \sum_{t=1}^T (\log 1/\beta_t)\, h_t(x) \ge \frac12\sum_{t=1}^T \log 1/\beta_t \\ 0 & \text{aksi hâlde} \end{cases}$$

### 2.2 Adımların Anlamı

Elimizde $N$ tane etiketli örnek vardır. $D$, bu $N$ örnek üzerinde bir dağılımdır; her örneğin seçilme olasılığını verir. Genelde tekdüze (uniform) seçilir ki bütün örneklerin sisteme katkısı eşit olsun. $T$ iterasyon sayısıdır, yani topluluktaki temel öğrenici sayısı. Ağırlık vektörü ilk adımda doğrudan $D$'ye eşitlenir; $D$ her örnek için $1/N$ ise bu tekdüze bir dağılımdır. $w$'nin üst indisi iterasyonu, alt indisi örneği gösterir.

Hoca AdaBoost'un genel mantığını hatırlattı: örnekler arasından bir dağılıma göre seçim yapılır, bu seçimle bir eğitim kümesi oluşur, temel öğrenici eğitilir, hangi örnekleri doğru hangilerini yanlış sınıfladığı bulunur. Yanlış sınıflananların ağırlığı göreli olarak artırılır; böylece o ana kadarki öğrenicilerin zorlandığı örnekler sonraki öğreniciye aktarılır ve en sonda zor örnekler kalır.

- **1. adım:** $\mathbf{w}^t$ kendi toplamına bölünür. $\mathbf{w}^t$ içinde hangi değerler olursa olsun, sonuçta bütün örneklerin seçilme olasılıklarının toplamı 1 olur.
- **2. adım:** WeakLearn bu $\mathbf{p}^t$ dağılımıyla çağrılır ve bir $h_t$ hipotezi döner. Hipotez bir karar ağacı ya da başka bir model olabilir; sonuçta $X$ girdilerinden $[0,1]$ aralığına bir eşlemedir.
- **3. adım:** $h_t(x_i)$ ve $y_i$ ikisi de 1 ya da ikisi de 0 ise $|h_t(x_i)-y_i| = 0$; farklılarsa 1 olur. Bu yüzden $\varepsilon_t$, $h_t$'nin hata yaptığı örneklerin seçilme olasılıklarının toplamıdır.
- **4. adım:** $\varepsilon_t$'den $\beta_t$ elde edilir.
- **5. adım:** Örnek doğru tahmin edildiyse üs $1-0 = 1$ olur ve ağırlık $\beta_t$ ile çarpılır. Örnek yanlış tahmin edildiyse üs $1-1=0$ olur, $\beta_t^0 = 1$ ve ağırlık değişmez.

**Soru:** $|h_t(x_i)-y_i|$ içindeki $y_i$ gerçek değer mi, nereden buluyoruz? **Cevap:** Evet, $y_i$ gerçek etikettir ve bize verilir; $x_i$'ler ve $y_i$'ler bilinir.

Algoritma bittiğinde elde $T$ tane hipotez olur. Sonuç hipotezi $h_f$, çıktı kuralındaki koşul sağlanıyorsa 1, sağlanmıyorsa 0 verir. İspatta $h_f$'nin ne zaman 1 ne zaman 0 dediği tam olarak bu kurala göre kullanılacaktır.

## 3. Teorem 6 ve Neyi İspatladığı

### 3.1 Teoremin İfadesi

Yazarlar algoritmayı tanımlamakla kalmamış, şu iddiada bulunmuşlardır (ekrandan, 00:20:00):

> **Teorem 6:** WeakLearn algoritması AdaBoost tarafından $T$ kez çağrılsın ve hataları $\varepsilon_1, \varepsilon_2, \dots, \varepsilon_T$ olan hipotezler üretsin. Bu durumda AdaBoost'un sonuç hipotezi $h_f$'nin hatası $\varepsilon = \sum_{i=1}^N D(i)\,1\{h_f(x_i)\ne y_i\}$ aşağıdaki şekilde üstten sınırlıdır:
> $$\varepsilon \le 2^T \prod_{t=1}^T \sqrt{\varepsilon_t(1-\varepsilon_t)}$$

Buradaki $1\{\cdot\}$ fonksiyonu, içi doğruysa 1, yanlışsa 0 döndürür. Dolayısıyla $h_f$'nin hatası, $h_f$'nin yanlış yaptığı örneklerin $D(i)$ değerlerinin toplamıdır.

"Üstten sınırlı" ne demektir? Hoca bunu sınıfa sordu; bir öğrencinin cevabı ile birlikte şöyle toparlandı: $\varepsilon$ sağdaki değerden daha büyük olamaz, yani algoritma en fazla bu kadar hata yapabilir.

### 3.2 Üst Sınır Neden Önemli?

Bir algoritma için ne kadar küçük bir üst sınır gösterilirse o algoritma o kadar iyidir. Başka bir algoritma önerip onun üst sınırının bundan daha küçük olduğunu gösterirseniz, algoritmanızın daha iyi olduğunu teorik olarak ispatlamış olursunuz. Bu, veri kümeleri üzerinde deney yapmaktan (empirik yaklaşımdan) farklı bir ispattır.

Hoca burada sınıfa "Buradaki hata neyin üzerindeki hata?" diye sordu. Bir öğrenci önce "topluluğun hatası" dedi; hoca topluluğun hangi küme üzerindeki hatası olduğunu sordu ve cevap "eğitim kümesi" oldu.

> **Hocanın vurgusu:** Teoremdeki hata eğitim kümesi üzerinde tanımlıdır; girdi etiketleri bilinen örneklerdir. Teorem, eğitim kümesindeki hatanın nasıl ve ne hızla yakınsadığını (converge ettiğini) gösterir. Daha küçük bir üst sınır, algoritmanın eğitim hatasını daha hızlı düşürdüğünü ispatlar; test kümesinde daha başarılı olduğunu ispatlamaz. Test başarısıyla ilgili teoremler de vardır ama burada incelenen o değildir.

## 4. Tanımlar ve Lemma 1

İspata geçmeden önce kullanılan semboller tanımlandı (ekrandan, 00:20:00 ve 00:25:00):

- $N$: örnek sayısı.
- $x_i, y_i$: $i$. örnek ve etiketi, $y_i\in\{0,1\}$. Etiket bir aralıktan değil, ya 0 ya 1'dir; iki sınıflı bir problem söz konusudur.
- $\varepsilon = \sum_{i=1}^N D(i)\,1\{h_f(x_i)\ne y_i\}$: $h_f$'nin hatası, hatalı örneklerin $D$ değerlerinin toplamı. $D(i)$ bütün örnekler için $1/N$ ise bu, hatalı örnek sayısının $N$'ye oranıdır ve 0 ile 1 arasındadır.
- $\mathbf{w}^t$: $N$ elemanlı vektör, örneklerin seçilme olasılıklarının hesabında kullanılır. Başlangıçta elemanları birbirine ve $1/N$'ye eşittir.
- $w_i^t$: $i$. örneğin seçilme olasılığının hesabında kullanılır.
- $\mathbf{p}^t$: $N$ elemanlı vektör, örneklerin seçilme olasılıklarını tutar.
- $h_t(x_i)$: $t$. adımda üretilen hipotezin $i$. örnek için tahmini (0 ya da 1). $h_t(x_i)=y_i$ ise tahmin doğrudur, değilse yanlıştır.

$D$'nin tekdüze olması zorunlu değildir. Hoca şu örneği verdi: veri kümesindeki etiketlerin bir kısmını konuyu çok iyi bilen, bir kısmını o kadar iyi bilmeyen kişiler vermiş olabilir. Güvenilen etiketli örneklerin ağırlığı daha büyük, güvenilmeyenlerinki daha küçük tutulabilir. Bu durumda $D$ her örnek için $1/N$ olmaz, ama teorem değişmez; en sonda elde edilen $h_f$ hatası başlangıçta atanan $D$'ye göre tanımlanmış olur.

İspat için bir yardımcı teorem (lemma) gerekir. Lemmanın ispatı derste gösterilmedi, araştırılması öğrencilere bırakıldı (ekrandan, 00:25:00):

$$\text{Lemma 1: } \alpha\ge 0 \text{ ve } r\in[0,1] \text{ için } \quad \alpha^r \le 1-(1-\alpha)r$$

> **Ek bilgi (derste anlatılmadı):** $\alpha>0$ için $f(r) = \alpha^r$ fonksiyonu $r$'ye göre dışbükeydir (konvekstir). Dışbükey bir fonksiyon, uç noktalarını birleştiren doğrunun altında kalır. $r=0$'da $f=1$, $r=1$'de $f=\alpha$ olduğundan bu doğru $1-(1-\alpha)r$'dir; lemma buradan çıkar.

Hoca, ispatın uzun olduğunu ve tek seferde kavranamayabileceğini, arada geri dönülebileceğini söyleyerek ("önce derin bir nefes alalım") ispata başladı.

## 5. İspat, Birinci Kısım: Ağırlık Toplamına Üst Sınır

### 5.1 Güncelleme Kuralının Yorumu

Algoritmanın 5. adımı (Eşitlik 1):

$$w_i^{t+1} = w_i^t\,\beta_t^{\,1-|h_t(x_i)-y_i|} \tag{1}$$

$h_t(x_i) = y_i$ ise (örnek doğru tahmin edildiyse) $|h_t(x_i)-y_i| = 0$ olur; üs 1'dir ve $w_i^t$, 0 ile 1 arasındaki $\beta_t$ ile çarpılır. 0 ile 1 arasında bir sayıyla çarpmak küçültür, dolayısıyla $w_i^{t+1} < w_i^t$ olur: doğru tahmin edilen örneğin ağırlığı düşürülür. Farklılarsa $|h_t(x_i)-y_i|=1$, üs 0 olur ve $w_i^{t+1} = w_i^t$ olur (ekrandan, 00:25:00).

### 5.2 Toplama ve Lemma

Eşitlik 1 bütün örnekler için yazılıp toplanırsa:

$$\sum_{i=1}^N w_i^{t+1} = \sum_{i=1}^N w_i^t\,\beta_t^{\,1-|h_t(x_i)-y_i|} \tag{2}$$

Lemma 1'de $\alpha$ yerine $\beta_t$ (0 ile 1 arasında), $r$ yerine $1-|h_t(x_i)-y_i|$ konur. $|h_t(x_i)-y_i|$ ya 0 ya 1 olduğu için $r$ de $[0,1]$ aralığındadır, lemma uygulanabilir. $\beta_t^{1-|\cdot|}$ teriminin yerine ondan büyük olan ifade yazılır (ekrandan, 00:30:00):

$$\sum_{i=1}^N w_i^t\,\beta_t^{\,1-|h_t(x_i)-y_i|} \le \sum_{i=1}^N w_i^t\left(1-(1-\beta_t)(1-|h_t(x_i)-y_i|)\right) \tag{3}$$

Hoca bu geçişi şöyle gösterdi: üs kısmı lemmadaki $r$'ye, $\beta_t$ lemmadaki $\alpha$'ya karşılık gelir; $\alpha^r$ yerine $1-(1-\alpha)r$ yazılır, $w_i^t$ olduğu gibi kalır.

$|h_t(x_i)-y_i|$ terimi $i$. örnekteki hatayı gösterir; ağırlıklarla toplandığında $\varepsilon_t$'yi verir. Böylece (ekrandan, 00:35:00):

$$\sum_{i=1}^N w_i^{t+1} \le \left(1-(1-\beta_t)(1-\varepsilon_t)\right)\sum_{i=1}^N w_i^t \tag{4}$$

**Soru:** Burada $\varepsilon$'un üstünde $i$ olması gerekmiyor mu, toplam hata mı yoksa $i$. örnekteki hata mı? **Cevap:** $|h_t(x_i)-y_i|$, $i$. örnekteki hatadır; ağırlıklı toplamı $t$. adımın hatası $\varepsilon_t$'yi verir.

> **Ek bilgi (derste anlatılmadı):** Eşitlik 4'e geçerken kullanılan ilişki, ağırlıklar normalize edilmiş olasılıklar ($p_i^t = w_i^t/\sum_j w_j^t$) üzerinden kurulur: $\sum_i w_i^t|h_t(x_i)-y_i| = \varepsilon_t\sum_i w_i^t$. Ekrandaki notta bu kısaca "$|h_t(x_i)-y_i| = \varepsilon_t$ olduğundan" diye yazılmıştır.

### 5.3 Adımları Zincirleme

Eşitlik 4, $t+1$. adım ile $t$. adım arasındaki ağırlık ilişkisini verir. Son adım ($T$) için yazılırsa (ekrandan, 00:35:00):

$$\sum_{i=1}^N w_i^{T+1} \le \left(1-(1-\beta_T)(1-\varepsilon_T)\right)\sum_{i=1}^N w_i^T \tag{5}$$

Sondan bir önceki adım için:

$$\sum_{i=1}^N w_i^{T} \le \left(1-(1-\beta_{T-1})(1-\varepsilon_{T-1})\right)\sum_{i=1}^N w_i^{T-1} \tag{6}$$

Eşitlik 5'teki $\sum_i w_i^T$ yerine Eşitlik 6'daki ondan büyük olan ifade konursa eşitsizlik bozulmaz:

$$\sum_{i=1}^N w_i^{T+1} \le \left(1-(1-\beta_T)(1-\varepsilon_T)\right)\left(1-(1-\beta_{T-1})(1-\varepsilon_{T-1})\right)\sum_{i=1}^N w_i^{T-1} \tag{7}$$

Böylece $T+1$ ile $T-1$ arasındaki ilişki bulunur. Bu işlem $T-2$, $T-3$, ... diye 1'e kadar sürdürülür. En sonda sağdaki toplam $\sum_i w_i^1$ olur ve başlangıçta ağırlıkların toplamının 1 olduğu bilindiğinden:

$$\sum_{i=1}^N w_i^{T+1} \le \prod_{t=1}^T \left(1-(1-\beta_t)(1-\varepsilon_t)\right) \tag{10}$$

<!-- BELİRSİZ: Eşitlik 8 ve 9'un ekrandaki tam biçimi karelerde görünmedi; zincirin ara adımları olduğu anlatımdan anlaşılıyor. -->

Bu, son adımdan bir sonraki ağırlıkların toplamı için $\beta$'lar ve $\varepsilon$'lardan oluşan bir üst sınırdır. Hoca bunu "bir kenarda dursun, kullanacağız" diyerek ikinci kısma geçti.

## 6. İspat, İkinci Kısım: Hatalı Örnekler İçin Eşitsizlik

Sonuç hipotezi iki şekilde hata yapabilir: $y_i = 0$ iken $h_f(x_i)=1$ demesi ya da $y_i=1$ iken $h_f(x_i)=0$ demesi.

### 6.1 Birinci Hata Türü: $y_i=0$, $h_f(x_i)=1$

$h_f(x_i)=1$ ise çıktı kuralındaki koşul doğrudur:

$$\sum_{t=1}^T (\log 1/\beta_t)\,h_t(x_i) \ge \frac12\sum_{t=1}^T\log 1/\beta_t$$

$\log a^b = b\log a$ olduğundan $1/\beta_t = \beta_t^{-1}$ yazılır ve $-1$ logaritmanın önüne geçer; böylece kesirlerden kurtulunur (ekrandan, 00:45:00):

$$-\sum_{t=1}^T \log(\beta_t)\,h_t(x_i) \ge -\frac12\sum_{t=1}^T\log\beta_t \tag{11}$$

Şimdi $\prod_{t=1}^T\beta_t^{-|h_t(x_i)-y_i|}$ değeri düşünülür. $y_i=0$ olduğundan $|h_t(x_i)-0|$ olur; $h_t(x_i)\ge 0$ olduğundan mutlak değerin içi olduğu gibi çıkar ve ifade $\prod_t\beta_t^{-h_t(x_i)}$ hâline gelir. Bu çarpıma $K$ denir: $K = \beta_1^{-h_1(x_i)}\cdot\beta_2^{-h_2(x_i)}\cdots$. İki tarafın logaritması alınırsa çarpım toplama dönüşür:

$$\log K = \log\left(\beta_1^{-h_1(x_i)}\right) + \log\left(\beta_2^{-h_2(x_i)}\right) + \dots + \log\left(\beta_T^{-h_T(x_i)}\right)$$

İki tarafın üstelini (exp) alınca, $e$ ve $\log$ birbirini götürür (ekrandan, 00:45:00):

$$\exp(\log K) = K = e^{\log(\beta_1^{-h_1(x_i)})+\dots+\log(\beta_T^{-h_T(x_i)})} = e^{-\sum_{t=1}^T\log(\beta_t)\,h_t(x_i)}$$

Yani:

$$\prod_{t=1}^T\beta_t^{-h_t(x_i)} = e^{-\sum_{t=1}^T\log(\beta_t)\,h_t(x_i)} \tag{12}$$

Eşitlik 11'in iki tarafının üsteli alınırsa (üstel fonksiyon artan olduğu için yön korunur):

$$e^{-\sum_{t=1}^T\log(\beta_t)\,h_t(x_i)} \ge e^{-\frac12\sum_{t=1}^T\log\beta_t}$$

Sağ taraf açılır (ekrandan, 00:45:00):

$$e^{-\frac12\sum_t\log\beta_t} = e^{-\frac12(\log\beta_1+\dots+\log\beta_T)} = e^{\log(\beta_1^{-1/2})}\cdots e^{\log(\beta_T^{-1/2})} = \prod_{t=1}^T\beta_t^{-1/2} = \left(\prod_{t=1}^T\beta_t\right)^{-1/2}$$

O hâlde $y_i=0$, $h_f(x_i)=1$ durumu için:

$$\prod_{t=1}^T\beta_t^{-|h_t(x_i)-y_i|} \ge \left(\prod_{t=1}^T\beta_t\right)^{-1/2} \tag{13}$$

### 6.2 İkinci Hata Türü: $y_i=1$, $h_f(x_i)=0$

$h_f(x_i)=0$ ise çıktı kuralındaki koşul sağlanmaz; eşitsizlik ters döner. Kesirlerden yine aynı şekilde kurtulunur, sonra iki taraf $-1$ ile çarpılır ve eşitsizliğin yönü değişir:

$$\sum_{t=1}^T\log(\beta_t)\,h_t(x_i) > \frac12\sum_{t=1}^T\log\beta_t \tag{14}$$

<!-- BELİRSİZ: Eşitlik 14'ün ekrandaki tam biçimi karelerde görünmedi; yukarıdaki biçim çıktı kuralından türetildi ve 00:50:00 karesindeki sonraki satırla tutarlıdır. -->

$y_i=1$ ve $h_t(x_i)\in[0,1]$ olduğundan $|h_t(x_i)-1| = 1-h_t(x_i)$ olur. Bu durumda (ara adım eklendi):

$$\prod_{t=1}^T\beta_t^{-|h_t(x_i)-y_i|} = \prod_{t=1}^T\beta_t^{-(1-h_t(x_i))} = \prod_{t=1}^T\beta_t^{h_t(x_i)}\cdot\prod_{s=1}^T\beta_s^{-1}$$

Burada ikinci çarpımda $s$ indisi kullanılmıştır; iki çarpım birbirinden bağımsızdır, iç içe değildir. Birinci çarpım, Eşitlik 12'deki gibi $e^{\sum_t\log(\beta_t)h_t(x_i)}$ olarak yazılır ve Eşitlik 14 kullanılır (ekrandan, 00:50:00):

$$e^{\sum_t\log(\beta_t)h_t(x_i)}\cdot\prod_{s=1}^T\beta_s^{-1} > e^{\frac12\sum_t\log\beta_t}\cdot\prod_{s=1}^T\beta_s^{-1} = \prod_{t=1}^T e^{\log(\beta_t^{1/2})}\cdot\prod_{s=1}^T\beta_s^{-1} = \left(\prod_{t=1}^T\beta_t\right)^{-1/2}$$

Son eşitlikte $\beta_t^{1/2}$ ile $\beta_t^{-1}$ çarpılınca $\beta_t^{-1/2}$ çıkar. O hâlde $y_i=1$, $h_f(x_i)=0$ durumu için:

$$\prod_{t=1}^T\beta_t^{-|h_t(x_i)-y_i|} \ge \left(\prod_{t=1}^T\beta_t\right)^{-1/2} \tag{15}$$

### 6.3 İki Durumun Karşılaştırılması

Hoca Eşitlik 13 ile 15'i yan yana koyup "Ne görüyorsunuz?" diye sordu; cevap "aynılar" oldu. Bunun anlamı, algoritma yanlış yaptığında hatanın türünden bağımsız olarak aynı eşitsizliğin geçerli olmasıdır. Yani AdaBoost $i$. örnek için hata yapmışsa ($h_f(x_i)\ne y_i$) (ekrandan, 00:50:00):

$$\prod_{t=1}^T\beta_t^{-|h_t(x_i)-y_i|} \ge \left(\prod_{t=1}^T\beta_t\right)^{-1/2}$$

Buraya kadarki işlemlerin hepsi bu ifadeyi elde etmek içindi; asıl ispatta $\varepsilon$'un bir değerden küçük olduğunu göstermekte kullanılacaktır. Bu noktada derse ara verildi.

## 7. İspat, Üçüncü Kısım: Ağırlık Toplamına Alt Sınır ve Birleştirme

### 7.1 Son Ağırlıkların Kapalı Biçimi

Algoritmanın 5. adımında $w_i^T$ yerine onun $T-1$'li ifadesi, onun yerine $T-2$'li ifadesi yazılarak sona kadar gidilir (ekrandan, 00:50:00 ve 01:05:00):

$$w_i^{T+1} = w_i^T\beta_T^{1-|h_T(x_i)-y_i|} = w_i^{T-1}\beta_T^{1-|h_T(x_i)-y_i|}\beta_{T-1}^{1-|h_{T-1}(x_i)-y_i|} = \dots = w_i^1\prod_{t=1}^T\beta_t^{1-|h_t(x_i)-y_i|} = D(i)\prod_{t=1}^T\beta_t^{1-|h_t(x_i)-y_i|} \tag{16}$$

Eşitlik 16'daki $D(i)$, $i$. örneğin en baştaki seçilme olasılığını ($w_i^1$); $w_i^{T+1}$ ise algoritma bittiğinde $i$. örneğin ağırlığını gösterir.

### 7.2 Hatalı Örneklerle Alt Sınır

Bütün $i\in\{1,2,\dots,N\}$ için $w_i^{T+1}\ge 0$'dır. O hâlde (ekrandan, 01:05:00):

$$\sum_{i=1}^N w_i^{T+1} \ge \sum_{i:\,h_f(x_i)\ne y_i} w_i^{T+1}$$

Sağdaki toplam bütün örnekler üzerinden değil, yalnız $h_f$'nin hata yaptığı örnekler üzerindendir. Ağırlıkların hepsi pozitif olduğundan ve doğru yapılan örneklerin de ağırlıkları bulunduğundan, tüm ağırlıkların toplamı hatalı örneklerin ağırlık toplamından büyüktür.

Şimdi Eşitlik 16 kullanılır ve üs $1-|\cdot|$ iki çarpıma ayrılır (ekrandan, 01:05:00):

$$\sum_{i:\,h_f(x_i)\ne y_i} w_i^{T+1} = \sum_{i:\,h_f(x_i)\ne y_i} D(i)\prod_{t=1}^T\beta_t^{1-|h_t(x_i)-y_i|} = \sum_{i:\,h_f(x_i)\ne y_i} D(i)\prod_{t=1}^T\beta_t\prod_{t=1}^T\beta_t^{-|h_t(x_i)-y_i|}$$

Bu toplam yalnız hatalı örnekler üzerinde olduğundan, Eşitlik 13/15 kullanılabilir; $\prod_t\beta_t^{-|\cdot|}$ yerine ondan küçük olan $(\prod_t\beta_t)^{-1/2}$ yazılır. $\prod_t\beta_t\cdot(\prod_t\beta_t)^{-1/2} = (\prod_t\beta_t)^{1/2}$ olur. Bu çarpan $i$'ye bağlı olmadığı için toplamın dışına çıkar; içeride kalan $\sum_{i:\,h_f(x_i)\ne y_i}D(i)$ ise tanım gereği $\varepsilon$'dur (ekrandan, 01:10:00):

$$\sum_{i:\,h_f(x_i)\ne y_i} D(i)\left(\prod_{t=1}^T\beta_t\right)^{1/2} = \varepsilon\left(\prod_{t=1}^T\beta_t\right)^{1/2}$$

O hâlde:

$$\sum_{i=1}^N w_i^{T+1} \ge \varepsilon\left(\prod_{t=1}^T\beta_t\right)^{1/2} \tag{17}$$

### 7.3 İki Sınırı Birleştirmek

$\prod_t\beta_t\ge 0$ olduğundan Eşitlik 17'nin iki tarafı $(\prod_t\beta_t)^{1/2}$'ye bölünür (ekrandan, 01:10:00):

$$\varepsilon \le \left(\sum_{i=1}^N w_i^{T+1}\right)\left(\prod_{t=1}^T\beta_t\right)^{-1/2}$$

Şimdi Eşitlik 10 kullanılır: $\sum_i w_i^{T+1}$ yerine ondan büyük olan $\prod_t(1-(1-\beta_t)(1-\varepsilon_t))$ yazılırsa eşitsizlik bozulmaz. $(\prod_t\beta_t)^{-1/2}$ çarpanı da çarpımın içine alınır:

$$\varepsilon \le \left(\prod_{t=1}^T\left(1-(1-\beta_t)(1-\varepsilon_t)\right)\right)\left(\prod_{t=1}^T\beta_t\right)^{-1/2} = \prod_{t=1}^T\frac{1-(1-\beta_t)(1-\varepsilon_t)}{\sqrt{\beta_t}} \tag{18}$$

Böylece $\varepsilon$ için bir üst sınır elde edildi. Bu sınır iki şeye bağlıdır: $\beta_t$ ve $\varepsilon_t$.

## 8. Üst Sınırı En Küçük Yapan β ve Teoremin Sonucu

### 8.1 Neden Minimize Ediyoruz?

Algoritmanın hatasının üst sınırının mümkün olduğunca küçük olmasını isteriz; üst sınırı yüksek bir algoritma kötüdür. Elimizde algoritmanın üst sınırını ifade eden bir fonksiyon vardır ve amaç bu fonksiyonun minimumunu bulmaktır. Bir fonksiyonun minimumu için türev alınıp sıfıra eşitlenir.

Fonksiyonda iki değişken vardır. $\varepsilon_t$ örneklerden gelir, bizim belirleyebileceğimiz bir şey değildir. $\beta_t$ hakkında ise algoritmayı bir kenara bırakırsak henüz hiçbir şey tanımlanmamıştır; onu biz seçebiliriz. Bu yüzden türev $\beta_t$'ye göre alınır (ekrandan, 01:10:00).

Büyük $T$ tane çarpan vardır ve hepsi pozitiftir. Çarpanlar birbirinden bağımsız olduğu için her birini minimum yapan değer bulunursa çarpım da minimum olur. Bu yüzden yalnız çarpımın içine odaklanılır.

### 8.2 Türev

Tek bir çarpan $\beta_t^{-1/2}\left(1-(1-\beta_t)(1-\varepsilon_t)\right)$ biçiminde, $\beta_t$'ye bağlı iki fonksiyonun çarpımı olarak yazılır. İki fonksiyonun çarpımının türevi "birincinin türevi çarpı ikincinin kendisi artı ikincinin türevi çarpı birincinin kendisi"dir. Türev sıfıra eşitlenip düzenlenince ekrandaki adımlar şöyledir (ekrandan, 01:15:00):

$$\beta_t^{-1/2}(1-\varepsilon_t) = \frac12\beta_t^{-3/2}\left(1-(1-\beta_t)(1-\varepsilon_t)\right)$$

$$(1-\varepsilon_t) = \frac12\beta_t^{-3/2}\beta_t^{1/2}\left(1-(1-\beta_t)(1-\varepsilon_t)\right)$$

$$(1-\varepsilon_t) = \frac12\beta_t^{-1}\left(1-(1-\beta_t)(1-\varepsilon_t)\right)$$

$$2\beta_t(1-\varepsilon_t) = 1-(1-\beta_t)(1-\varepsilon_t)$$

$$2\beta_t-2\beta_t\varepsilon_t-1 = (\beta_t-1)(1-\varepsilon_t)$$

$$2\beta_t-2\beta_t\varepsilon_t-1 = \beta_t-\beta_t\varepsilon_t-1+\varepsilon_t$$

$$\beta_t-\beta_t\varepsilon_t = \varepsilon_t \quad\Rightarrow\quad \beta_t(1-\varepsilon_t) = \varepsilon_t \quad\Rightarrow\quad \beta_t = \frac{\varepsilon_t}{1-\varepsilon_t}$$

<!-- BELİRSİZ: Türevin sıfıra eşitlendiği ilk satır karenin üstünde kısmen kesik; yukarıdaki ilk satır 01:15:00 karesinde görünen kısımla ve çarpım kuralıyla tutarlıdır. -->

Python ile kontrol: $\varepsilon_t = 0.3$ için $\beta\in(0,1)$ aralığında sayısal tarama yapıldığında minimum $\beta \approx 0.4286$'da bulunur; bu, $0.3/0.7 = 0.428571\ldots$ ile aynıdır.

### 8.3 Analiz ile Algoritmanın Buluşması

Üst sınırı minimum yapmak için $\beta_t = \varepsilon_t/(1-\varepsilon_t)$ seçilmelidir. Hoca bunun algoritmanın içinde nerede geçtiğini sordu: 4. adımda aynısı yazmaktadır.

> **Hocanın vurgusu:** Algoritma sıfırdan, kafadan "şunu şöyle atayayım" diye oluşturulmamıştır. $\beta_t$ değeri, demin yapılan analizin sonucunda ortaya çıkan bir seçimdir. Analizler yapıla yapıla algoritma oluşturulmuştur.

### 8.4 Değeri Yerine Koymak

$\beta_t = \varepsilon_t/(1-\varepsilon_t)$ üst sınırda (Eşitlik 18) yerine konur (ekrandan, 01:15:00):

$$\varepsilon \le \prod_{t=1}^T\frac{1-\left(1-\frac{\varepsilon_t}{1-\varepsilon_t}\right)(1-\varepsilon_t)}{\sqrt{\frac{\varepsilon_t}{1-\varepsilon_t}}}$$

Biraz aritmetikle: $1-\frac{\varepsilon_t}{1-\varepsilon_t} = \frac{1-2\varepsilon_t}{1-\varepsilon_t}$, bu $(1-\varepsilon_t)$ ile çarpılınca $1-2\varepsilon_t$ olur; pay $1-(1-2\varepsilon_t) = 2\varepsilon_t$'ye iner (ara adım eklendi). Ekranda devamı şöyledir (ekrandan, 01:20:00):

$$= \prod_{t=1}^T\left(\frac{\sqrt{1-\varepsilon_t}\,(1-(1-2\varepsilon_t))}{\sqrt{\varepsilon_t}}\right) = \prod_{t=1}^T\left(\frac{\sqrt{1-\varepsilon_t}\,(2\varepsilon_t)}{\sqrt{\varepsilon_t}}\right) = 2^T\prod_{t=1}^T\sqrt{1-\varepsilon_t}\sqrt{\varepsilon_t} = 2^T\prod_{t=1}^T\sqrt{(1-\varepsilon_t)\varepsilon_t}$$

Ve nihayet:

$$\varepsilon \le 2^T\prod_{t=1}^T\sqrt{(1-\varepsilon_t)\,\varepsilon_t} \tag{20}$$

Bu, Teorem 6'da gösterilmek istenen eşitsizliktir.

Hoca, bu hızla anlatılan bir ispatın her adımının hemen kavranamayacağını, defalarca okunarak zamanla oturacağını söyledi. Önemli olan genel hattır: algoritmanın hatası için bir üst sınır fonksiyonu tanımlandı, bu fonksiyonu en küçük yapan değer bulundu ve üst sınırın ne olduğu gösterildi. Algoritmaların üst sınırı, onların yakınsama hızını (convergence rate), yani hatayı ve kaybı ne kadar hızlı indirebildiklerini gösterir. Bu makale, makine öğrenmesi teorisinde bir kilometre taşı olarak anıldı.

> **Hocanın vurgusu:** Algoritma tek seferde oluşturulmamıştır. Algoritmanın hatasının minimum olması için teoriden faydalanılmış, teori algoritmaya yol göstermiştir. Teori ve algoritma birlikte geliştirilmiştir; şimdilerde yaygın olan deneme yanılma yoluyla değil (ekrandan, 01:20:00).

## 9. Teorem Bize Ne Söylüyor?

### 9.1 Son Hata Bütün Tekil Hatalara Bağlıdır

Sınırdaki çarpım $t=1$'den $T$'ye kadar gider; içinde $\varepsilon_1$, $\varepsilon_2$, ... hepsi vardır. Topluluğa yeni bir temel öğrenici ($T+1$.) eklendiğinde ve onun hatası $\varepsilon_{T+1}$ olduğunda, üst sınır $2\sqrt{\varepsilon_{T+1}(1-\varepsilon_{T+1})}$ ile çarpılır.

Eşitlikteki $2^T$ terimi çok büyüktür; 100 temel öğrenici için $2^{100}$ gibi bir sayıdır. Ancak yanındaki çarpım oldukça küçüktür ve ifadeyi korkunç bir hâle getirmez.

### 9.2 Bütün Hatalar 1/2 İse

Hoca bunu sınıfa sordu. $\varepsilon_t = 1/2$ ise $1-\varepsilon_t = 1/2$, çarpımları $1/4$, karekökü $1/2$ olur. Çarpım $(1/2)^T$, yanında $2^T$ vardır; sonuç $1$ çıkar. Üst sınırın 1 olması, her şeyi yanlış yapmaya izin vermesi demektir. Yani bireysel hatalar $1/2$ ise teorem, algoritmanın bir şey yapamayacağını söyler. Anlamlı bir şey yapılabilmesi için $\varepsilon_t < 1/2$ olmalıdır.

$\varepsilon_t > 1/2$ ne demektir? Örneğin $0.6$: öğrenici örneklerin %60'ında, yani yarısından fazlasında yanlış yapmıştır. İki sınıflı bir problemde bu anlamsızdır; bütün tahminlerin işareti ters çevrilirse hata %40'a iner. $\varepsilon_t$ $1/2$'ye yaklaştıkça üst sınır büyür, $1/2$'den uzaklaşıp sıfıra yaklaştıkça küçülür.

Ders notlarında da (önceki dersler) $\varepsilon_t$ $1/2$'ye ulaşınca algoritmanın sonlandığı hatırlatıldı. $k$. adımda üretilen öğrenicinin hatası $1/2$ ya da daha büyük çıkarsa, o adımın öğrenicisi topluluğa eklenmez; o ana kadar üretilmiş $k-1$ öğrenici kullanılır. Çünkü $1/2$ ve üstü hatalar üst sınırın aşağı inişini durdurur, hatta kötüleştirir.

### 9.3 Bütün Hatalar 1/2'den Küçükse: Üstel Düşüş

Ekrandaki grafikte (Şekil 1) üst sınır, temel öğrenici sayısına (0-100) göre farklı bireysel hata değerleri için çizilmiştir (ekrandan, 01:25:00). Bireysel hataların hepsi $1/3$ ($0.333\ldots$) ve hepsi $1/4$ iken eğriler hızla düşer; düşüş doğrusal değil üsteldir. Bu, algoritmanın eğitim kümesinde çok hızlı olduğunu gösterir. Ekrandaki notta "Şekil 1'den görüldüğü üzere üst sınır üstel biçimde düşmektedir" yazmaktadır.

<!-- BELİRSİZ: Grafikte üç eğri var; altyazıda hoca 1/3 ve 1/4'ü sayıyor, üçüncü eğrinin değeri ("hepsi 1/2'den küçük eşit olursa") net değil ve karede lejant görünmüyor. -->

Python ile hesaplanan adım başına çarpan $2\sqrt{\varepsilon_t(1-\varepsilon_t)}$ ve üst sınır değerleri:

| $\varepsilon_t$ | Adım başına çarpan | $T=10$ | $T=20$ | $T=40$ | $T=100$ |
|---|---|---|---|---|---|
| $1/2$ | $1.0000$ | $1$ | $1$ | $1$ | $1$ |
| $1/3$ | $0.9428$ | $0.5549$ | $0.3080$ | $0.0948$ | $0.0028$ |
| $1/4$ | $0.8660$ | $0.2373$ | $0.0563$ | $0.0032$ | $\approx 0$ |

## 10. Açık Bırakılan Sorular

Hoca notun sonunda üç soru bırakıp incelenmesini istedi (ekrandan, 01:25:00 ve 01:30:00):

1. **Örneklerin ağırlıklarını güncellemeyi çarpımsal değil de toplamsal yapabilir miydik?** Gradyan inişinde parametreler $w^{t+1} = w^t - \eta\,\frac{d(\text{loss})}{dw}$ gibi bir şey eklenerek ya da çıkarılarak güncellenir (ekranda `wt+1=wt-eps*d(loss)` yazılmıştır). AdaBoost'ta ise $w_i^{T+1} = w_i^T\beta_T^{1-|h_T(x_i)-y_i|}$, yani çarpılarak güncellenir. Toplamsal bir mekanizma kurulabilir miydi ve etkisi ne olurdu?
2. **Belli bir hata değerine ulaşmak için sisteme eklememiz gereken temel öğrenici sayısını ($T$) bulabilir miyiz?** Üst sınır bilindiği için bu mümkün görünmektedir.
3. **AdaBoost dışında başka boosting algoritmaları var mı?**

## 11. Teori, Beklenti ve Deney

Dersin son bölümü, notun "Yorum" kısmına dayanan genel bir değerlendirmeydi (ekrandan, 01:30:00).

Algoritma tasarlarken ya da yeni bir yöntem/mimari geliştirirken "şunu şöyle yapsak nasıl olur?" diye sorulur. Elde çok sağlam bir teori varsa cevap deney yapmadan bulunabilir. Örneğin bu teoreme bakarak, AdaBoost'a temel öğrenici eklendikçe eğitim kümesindeki başarının artacağı, hiçbir zaman kötüleşmeye gitmeyeceği söylenebilir; bunun için deney gerekmez. "Bireysel hatalar $1/2$'den büyük olursa ne olur?" sorusu da kolayca cevaplanır.

Ama genelde elimizde çok sağlam bir teori olmaz. Yine de yapılan değişikliğin etkisi hakkında en azından bir beklentiye ve bu beklentinin bir açıklamasına sahip olunmalıdır. Bu beklenti matematiksel değil, sezgisel olabilir; yanlış bile olabilir.

- Beklenti gerçekleşirse doğru yolda olunduğu anlaşılır.
- Gerçekleşmezse, neyin (hangi varsayımın, hangi açıklamanın) yanlış düşünüldüğü öğrenilir ve sonraki beklenti ve deney buna göre şekillendirilir.

> **Hocanın vurgusu:** Beklenti ve açıklama olmadan yapılan deneyin (deneme yanılma ile kör arama) sonucundan, sonrası için hiçbir ipucu elde edilemez. Kör arama çok yorucu ve az bilgilendiricidir; aralarındaki ilişki bilinmeyen noktasal bilgiler verir ve genelleştirmeye imkân vermez. Öngörü, tahmin ya da hipotez ise yanlış bile çıksa noktaların arasını ve sonrasını tahmin etmeyi, sonraki değişiklikleri ve deney tasarımlarını planlamayı sağlar.

Hoca, yapay zekâdaki kör arama ve sezgisel arama algoritmaları benzetmesini kullandı: kör aramada hedefe yaklaşıp yaklaşmadığınızı bilmezsiniz; sezgisel arama süreci hızlandırır ve daha az yorucu yapar. Buradaki "sezgi" de bu anlamdadır.

Fizikte teorinin, beklentinin ve öngörünün yeri çok daha büyüktür, çünkü deneyler çok pahalıdır. Teorik fizikçiler ve uygulamalı fizikçiler birbirine yol gösterir; bir deney için milyonlar harcamak gerekebileceğinden kör aramayla ilerlemek mümkün değildir. Makine öğrenmesinde bir algoritmayı bir veri kümesinde çalıştırmanın maliyeti genelde düşüktür; ancak büyük veri kümelerinde büyük mimariler çalıştırmak artık ucuz değildir, birkaç gün süren eğitimler nadir değildir.

> **Hocanın vurgusu:** Deney yapmadan önce bir önceki deneye göre neyi değiştirdiğinizi, çok emin olmasanız da ne beklediğinizi ve bunu neden beklediğinizi mutlaka yazın. Yazmak düşünceleri düzenlemeye yardım eder; beklenti yanlış da çıkabilir, ama nelerden geçtiğinizin kaydı gelecek için yol gösterici olur.

## 12. Ders Sonundaki Soru-Cevaplar

**Soru:** Boosting algoritmasında tekil öğrenici sayısı arttığında algoritma zaman olarak daha mı uzun sürer, daha mı kısa? **Cevap:** 100 tekil öğrenici, 10 tekil öğreniciden tabii ki daha uzun sürer. "Hızlı yakınsama" çalışma süresi anlamına gelmez; grafikteki gibi, temel öğrenici sayısı arttıkça topluluk hatasının üst sınırının doğrusal değil üstel olarak düşmesi kastedilmektedir.

**Soru:** Regresyon için model kurarken normalizasyon yapmak gerekir mi? **Cevap:** Kullanılan algoritmaya bağlıdır. SVM ya da yapay sinir ağları gibi algoritmalarda gerekir; karar ağacı ya da 1-NN (en yakın komşu) gibi algoritmalarda gerekmez. Yapay sinir ağında normalizasyon süreci hızlandırır.

**Soru:** Çıkış ($y$) değerleri de normalize edilirse, örneğin 100 beklerken 0.8 gibi bir değer gelmez mi? **Cevap:** Normalizasyon yapıldıysa denormalizasyon bilgisi de saklanmalıdır; modelin verdiği değer tekrar orijinal uzaya geri dönüştürülür.

**Soru:** Boosting'in paralel (dağıtık) çalıştırılabileceği söylenmişti, doğru mu? **Cevap:** Hayır. Bagging, Random Forest ve Random Subspace gibi algoritmalar paralelleştirilebilir; her ağaç tamamen farklı makinelerde üretilebilir. Boosting'de ise her öğrenici bir öncekinin kararını beklediğinden ağaçlar eş zamanlı üretilemez. Önceki derste sorulan soru, boosting'in bazı kısımlarının paralelleştirilip paralelleştirilemeyeceğiydi; karar ağacının kendi iç parçalarından bazıları belki paralelleştirilebilir.

**Soru:** Regresyonda yapay sinir ağıyla kurulan bir modelin başarısı nasıl ölçülür? Doğru/yanlış sayısı söylenemiyor, yalnız gerçek değerle tahmin arasında bir fark var. **Cevap:** Ortalama karesel hata (mean squared error, MSE) kullanılır.

**Soru:** MSE 0.15 çıkarsa bu %15 başarı mı demektir? **Cevap:** Hayır, oransal bir değer değildir; sonucun yorumu $y$'lerin normalize edilip edilmediğine bağlıdır. MSE hataların karelerinin ortalamasıdır; 0.15 kabaca 0.4'ün karesi olduğundan, yaklaşık 0.4 büyüklüğünde bir ortalama hata yapılmış demektir.

> **Ders sonrası not:** $\sqrt{0.15} \approx 0.387$'dir; hocanın "yaklaşık 0.4" demesi bununla uyumludur. Ancak bu değer kök ortalama karesel hatadır (RMSE); ortalama mutlak hatayla (MAE) tam olarak aynı şey değildir, yalnız hata büyüklüğü hakkında kabaca fikir verir.

**Soru:** Tahminlerle gerçek değerlerin grafiğini çizip ne kadar yakın olduklarına bakmak daha kullanışlı mı? **Cevap:** MSE ile bu zaten görülebilir; ama evet, tahminlerle gerçek değerler arasındaki ilişkiyi görmek, aralarındaki korelasyonu ölçmek de yararlıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 01:25:00): Örneklerin ağırlıklarını güncellemeyi çarpımsal değil de toplamsal yapabilir miydik? (Gradyan inişindeki $w^{t+1} = w^t - \eta\, d(\text{loss})$ ile AdaBoost'taki $w_i^{T+1} = w_i^T\beta_T^{1-|h_T(x_i)-y_i|}$ karşılaştırılarak.)

> **Çözüm (derste verilmedi):** Derste cevap verilmedi, öğrencilere bırakıldı. İspat açısından bakılırsa, Eşitlik 10 ve 16 çarpımsal güncellemeye dayanır: $w_i^{T+1} = D(i)\prod_t\beta_t^{1-|\cdot|}$ kapalı biçimi ve Lemma 1 ile kurulan $\prod_t(1-(1-\beta_t)(1-\varepsilon_t))$ sınırı, adımların birbirine çarpılarak zincirlenmesinden gelir. Toplamsal bir güncellemede bu zincir kurulamaz; Teorem 6'daki üstel sınır bu ispatla elde edilemez. Üstelik toplamsal güncellemede ağırlıkların negatif olmaması ayrıca garanti edilmelidir.

**Soru 2** (ekrandan, 01:25:00): Belli bir hata değerine ulaşmak için sisteme eklememiz gereken temel öğrenici sayısını ($T$) bulabilir miyiz?

> **Çözüm (derste verilmedi):** Bütün bireysel hatalar $\varepsilon_t\le\gamma<1/2$ ise her adımın çarpanı en fazla $c = 2\sqrt{\gamma(1-\gamma)} < 1$ olur ve $\varepsilon\le c^T$. Hedef hata $\varepsilon^\ast$ için $c^T\le\varepsilon^\ast$ yeterlidir, yani $T \ge \dfrac{\ln\varepsilon^\ast}{\ln c}$. Örneğin $\gamma = 1/4$ için $c\approx 0.866$ ve $\varepsilon^\ast = 0.01$ hedefi için python ile $T\ge 33$ bulunur. Bu, eğitim hatasının üst sınırı için bir yeterli koşuldur.

**Soru 3** (ekrandan, 01:30:00): AdaBoost haricinde başka boosting algoritmaları var mı?

> **Çözüm (derste verilmedi):** Derste cevap verilmedi. Evet vardır; örneğin dersin konu listesinde de yer alan gradient boosting bunlardan biridir.

**Soru 4** (derste sözlü, 01:19:07): Bütün bireysel hatalar $\varepsilon_t = 1/2$ olursa Teorem 6'daki üst sınır ne olur?

Çözüm (derste verildi): $\sqrt{\frac12\cdot\frac12} = \frac12$, çarpım $(1/2)^T$, $2^T$ ile çarpılınca $1$ çıkar. Üst sınır 1'dir; yani teorem algoritmanın bir şey öğrenebileceğine dair hiçbir garanti vermez.

**Soru 5** (derste sözlü, 00:26:14): Teorem 6'daki hata, eğitim kümesi üzerindeki hata mı yoksa test kümesi üzerindeki hata mı?

Çözüm (derste verildi): Eğitim kümesi; girdi olarak etiketleri bilinen örnekler verilmektedir. Teorem eğitim hatasının yakınsama hızını gösterir, test başarısı hakkında bir şey söylemez.

## Dersin Toparlaması

Bu derste AdaBoost'un orijinal makalesindeki Teorem 6'nın ispatı baştan sona izlendi. Önce ağırlıkların toplamı için Lemma 1 yardımıyla bir üst sınır kuruldu (Eşitlik 10). Sonra sonuç hipotezinin iki hata türünde de aynı eşitsizliğin geçerli olduğu gösterildi (Eşitlik 13 ve 15) ve bununla ağırlık toplamı için hatayı içeren bir alt sınır elde edildi (Eşitlik 17). İki sınır birleştirilerek hata için $\beta_t$ ve $\varepsilon_t$'ye bağlı bir üst sınır bulundu (Eşitlik 18); bu sınırı en küçük yapan $\beta_t = \varepsilon_t/(1-\varepsilon_t)$ değerinin algoritmanın 4. adımıyla aynı olduğu görüldü ve sonuçta $\varepsilon \le 2^T\prod_t\sqrt{\varepsilon_t(1-\varepsilon_t)}$ elde edildi.

Teoremin yorumu, eğitim hatasının bireysel hatalar $1/2$'nin altında kaldıkça temel öğrenici sayısıyla üstel olarak düştüğü, $1/2$'de ise hiçbir garanti kalmadığıdır. Dersin genel dersi de, AdaBoost'ta olduğu gibi teorinin algoritmaya yol gösterebileceği ve sağlam bir teori olmadığında bile her deneyden önce bir beklenti ve açıklama yazmanın kör aramadan çok daha verimli olduğudur. Sonraki derste yapay sinir ağlarıyla kollektif öğrenmeye geçileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
