# Ders 4 Çalışma Özeti

## Genel Konular

- Parametrik ve parametrik olmayan (non-parametric) yöntemler arasındaki fark.
- K en yakın komşu (k-Nearest Neighbors, k-NN) sınıflandırması: eğitimde hiçbir şey yapılmaz, sınıflandırma test anında yapılır.
- Mesafe ve benzerlik ölçüleri: Minkowski, Manhattan, Öklid (Euclidean), Hamming ve kosinüs benzerliği (cosine similarity). Mahalanobis yalnız adıyla anıldı.
- Normalizasyon (min-max) ve standartlaştırma (standardization, z-score).
- K değerinin seçimi: doğrulama (validation) kümesiyle deneme.
- Özelliklere ağırlık verme.
- k-NN'in karmaşıklığı ve tembel öğrenme (lazy learning).
- Örnek sayısını azaltma: Voronoi diyagramı fikri, edited instance-based learning (incremental deletion, incremental growth).
- K boyutlu ağaç (k-d tree) ile arama alanını daraltma.

## Hocanın Özellikle Vurguladığı Kısımlar

- k-NN, makine öğrenmesindeki en başarılı yöntemlerden biri olarak anlatıldı.
- k-NN'de iki temel karar var: K kaç olacak ve benzerlik nasıl ölçülecek.
- Mesafe tabanlı yöntemlerde normalizasyon "mutlaka yapmanız gereken bir şey". Yapılmazsa büyük değerli özellikler küçük aralıklı özelliklerdeki önemli farkı yutar.
- Test örneği de aynı normalizasyondan geçirilmelidir (eğitimde bulunan min, max, ortalama ve standart sapma ile).
- Sözlük (vocabulary) eğitim örneklerinden baştan çıkarılır. Test sırasında sözlük çıkarmak "çok sık yapılan bir hata".
- K ezbere seçilmez. Probleme göre değişir. Farklı K değerleri doğrulama kümesinde denenir, en başarılı olan seçilir. Sonra test kümesiyle tarafsız başarı ölçülür.
- K genelde tek sayı seçilir (1, 3, 5, 7). K çok küçükse gürültüye (parazit) duyarlı olur. K 9-11 gibi büyük olunca benzemeyen örnekler işe karışır ve başarı düşer.
- Makine öğrenmesinde model seçimi hep böyledir: parametreler deneyerek, doğrulama kümesiyle belirlenir.
- k-NN, eğitim örneği az olan problemlerde uygundur (ör. az sayıda tıbbi görüntü). Binlerce, on binlerce örnek olunca önerilmez: model yoktur ve test anında işlem yükü çok fazladır.
- Örnekleri rastgele azaltmak iyi bir fikir değildir. Sınırda kalan, işe yarayan örnekler kaybolabilir.
- Hoca bu konuyu slayt yerine yazarak anlattı. Slaytı görüntünün ön planda olduğu konularda kullanacağını söyledi.

## Kısa Tekrar Notları

- **k-NN algoritması:**
  1. Eğitim: etiketli örnekleri sadece sakla.
  2. Test: bilinmeyen örneğin tüm eğitim örneklerine mesafesini hesapla.
  3. Mesafeleri küçükten büyüğe sırala, en yakın K örneği al.
  4. Çoğunluk oylaması (majority voting) yap. En çok oyu alan sınıf, örneğin sınıfıdır.
- **Minkowski:** $d(x, y) = \left(\sum_{i=1}^{D} |x_i - y_i|^p\right)^{1/p}$. $p=1$ Manhattan, $p=2$ Öklid.
- **Manhattan:** farkların mutlak değerlerinin toplamı. Hızlıdır, ızgara (grid) benzeri yapılarda uygundur.
- **Öklid:** farkların karelerinin toplamının karekökü. Daha hassastır, k-NN'de en çok kullanılan ölçüdür.
- **Hamming:** kategorik özellikler için. Özellik değerlerini tek tek karşılaştırır.
- **Kosinüs benzerliği:** iki vektör arasındaki açıya bakar. Doküman sınıflandırmada kullanılır.
- **Min-max normalizasyon:** her özelliği $[0, 1]$ (veya $[-1, 1]$) aralığına çeker.
- **Z-score:** $x' = (x - \mu) / \sigma$. Ortalama 0, standart sapma 1 olur. Veri Gauss dağılımına uyuyorsa daha iyi sonuç verir.
- Dağılımı bilmiyorsanız ikisini de deneyin, başarısı yüksek olanı kullanın.
- **Karmaşıklık:** bir örneğe mesafe $O(D)$. Tüm eğitim kümesine $O(N \cdot D)$. $D$ küçük bir sabitse $O(N)$.
- **Lazy learning:** öğrenme yapılmaz, tüm iş test anındadır.
- **Incremental deletion:** tüm kümeyle başla. Her örneği diğerleriyle sınıflandır. Doğru sınıflanıyorsa sil.
- **Incremental growth:** boş (ya da her sınıftan birkaç örnekle) başla. Eklenen örnek doğru sınıflanıyorsa ekleme, yanlış sınıflanıyorsa ekle.
- **k-d tree:** eğitim örnekleriyle bir ikili ağaç kurulur. Ortalama durumda arama $O(\log N)$, kötü durumda $O(N)$. Özellik sayısı artınca kurmak zorlaşır.

## Detaylı Açıklamalar

### Parametrik ve parametrik olmayan yöntemler

- Bayes ve karar ağacı (decision tree) parametrik yöntemlerdir. Eğitim örneklerinden olasılık veya ağaç gibi bir model kurarlar. Bilinmeyen örnek bu modelle sınıflandırılır.
- k-NN parametrik olmayan bir yöntemdir. Eğitimde model kurulmaz, örnekler sadece biriktirilir.
- Tahmin (test) anında, bilinmeyen örneğin en çok benzediği K örnek bulunur.

### k-NN mantığı

- Hoca iki özellikli ($x_1$, $x_2$) bir uzayda A ve B sınıfı örnekleri çizdi.
- A örneklerine yakın duran bilinmeyen örnek A'ya, B'ye yakın duran B'ye atanır.
- **Neden K > 1?** A grubuna yakın bir bilinmeyen örneğin hemen yanında, kendi grubundan kopmuş tek bir B örneği olabilir. Bu bir gürültü (parazit) olabilir ya da gerçekten sınırda bir örnek olabilir.
  - K = 1 alınırsa örnek B'ye atanır.
  - K = 3 alınırsa çoğunluk A olur ve örnek A'ya atanır. Bu daha mantıklıdır.
- Hoca ikinci bir çizimde iki "kaçmış" B örneği koydu: K = 3 için B kazanıyor, K = 5 için A kazanıyor.
- Amaç, bilinmeyen örneği tek bir örneğe göre değil, sınıfın genel karakteristiğine göre sınıflandırmaktır.

**Örnek 1: K = 3 ile oylama**

- Bilinmeyen $x$ için en yakın üç örnek $x_2$, $x_5$, $x_9$ olsun.
- $x_2$: A, $x_5$: B, $x_9$: A.
- Çoğunluk A olduğu için $x$, A sınıfına atanır.

- k-NN'de sınıf sayısı ikiyle sınırlı değildir. Çok sınıflı (multi-class) problemlerde de aynı yöntem kullanılır.

### Mesafe ölçüleri

**Minkowski mesafesi**

- $D$ özellikli eğitim örneği $x$ ve bilinmeyen örnek $x_{new}$ için:

$$d(x, x_{new}) = \left(\sum_{i=1}^{D} |x_i - x_{new,i}|^p\right)^{1/p}$$

- $p = 1$: Manhattan mesafesi.
- $p = 2$: Öklid mesafesi.

**Manhattan mesafesi**

$$d_{Man}(x, x_{new}) = \sum_{i=1}^{D} |x_i - x_{new,i}|$$

- Mutlak değer alınır, çünkü farkın işareti değil büyüklüğü önemlidir.
- Grid benzeri bir yapı varsa uygundur.

**Öklid mesafesi**

$$d_{Euc}(x, x_{new}) = \sqrt{\sum_{i=1}^{D} (x_i - x_{new,i})^2}$$

- Manhattan'dan daha hassastır. k-NN'de genelde bu kullanılır.
- Kare ve karekök işlemleri yüzünden daha yavaştır. Hız önemliyse ve sınıflar birbirine çok karışık değilse Manhattan tercih edilebilir.

**Örnek 2: Manhattan ve Öklid hesabı**

- $x = (3, 5, 1)$, $x_{new} = (2, 1, 6)$.
- Manhattan: $|3-2| + |5-1| + |1-6| = 1 + 4 + 5 = 10$.
- Öklid: $\sqrt{1^2 + 4^2 + 5^2} = \sqrt{1 + 16 + 25} = \sqrt{42} \approx 6{,}48$.
- Hoca derste önce 6,6 dedi, sonra 6,4 civarı diye düzeltti. Doğru değer yaklaşık 6,48'dir.

**Hamming mesafesi**

- Kategorik özellikler için kullanılır. k-NN'de çok sık kullanılmaz.
- Özellikler tek tek karşılaştırılır.

**Örnek 3: Hamming (derste anlatıldığı haliyle)**

- $x$ = (Ankara, İzmir, İstanbul), $x_{new}$ = (Ankara, Diyarbakır, Muğla).
- Hoca eşit olan özelliğe 1, farklı olana 0 verdi: (1, 0, 0). Toplam 1 dedi.
- Bir öğrencinin sorusuyla ikinci örnek: (Ankara, İzmir, Muğla) için (1, 1, 0), toplam 2.
- Not: bu hesap aslında eşleşen özellik sayısını (benzerliği) verir. Standart Hamming mesafesi tersini sayar (bkz. "Ders sonrası notlar").

**Kosinüs benzerliği**

- Doküman sınıflandırmada kullanılır.
- Neden? Bir kelime A dokümanında 20, daha uzun olan B dokümanında 50 kez geçebilir. Öklid mesafesi büyük çıkar, oysa iki doküman benzerdir.
- Öklid büyüklüğü (magnitude) ölçer. Kosinüs ise iki vektör arasındaki açıya bakar. Bu yüzden doküman uzunluğundan etkilenmez.

$$\cos\theta = \frac{x \cdot x_{new}}{\|x\| \, \|x_{new}\|} = \frac{\sum_{i=1}^{D} x_i \, x_{new,i}}{\sqrt{\sum_{i=1}^{D} x_i^2} \, \sqrt{\sum_{i=1}^{D} x_{new,i}^2}}$$

**Örnek 4: İki doküman parçası**

- Önce eğitim dokümanlarından sözlük çıkarılır. Her doküman, sözlükteki kelimelerin sayılarından oluşan bir vektöre dönüşür.
- Hocanın örneğinde ilk cümle "Data, digital economy is new oil" benzeri bir cümleydi. İkinci dokümanın içeriği altyazıda anlaşılmıyor.
- Derste bulunan değerler:
  - $x \cdot x_{new} = 3$
  - $\|x\| = \sqrt{10}$ (dört tane 1 ve bir tane 2 içeren vektör: $1+1+1+1+4+\ldots$)
  - $\|x_{new}\| = \sqrt{4} = 2$
- $\cos\theta = \dfrac{3}{2\sqrt{10}} \approx 0{,}47$.
- Vektörlerin tam açılımı altyazıda okunamıyor (çarpımlar döngüye girmiş).

- **Mahalanobis mesafesi:** kovaryans bilgisini de kullanır. k-NN'de tercih edilmediği için anlatılmadı.

**Hangi ölçü ne zaman? (hocanın özeti)**

- Varsayılan: Öklid.
- Hız önemli ve sınıflar iyi ayrılmışsa: Manhattan.
- Kategorik özellikler: Hamming.
- Dokümanlar: kosinüs benzerliği.

### Normalizasyon ve standartlaştırma

- Örnek: öğrenci özellikleri GPA (0-4 arası), yaş, kilo, boy.
- GPA'da 0,9'luk bir fark çok büyüktür. Boyda 1 cm fark önemsizdir.
- Normalizasyon yapılmazsa, büyük değerli özelliklerin farkları Öklid toplamına baskın olur. GPA'daki ciddi fark "kaynayıp gider".

**Min-max normalizasyon**

- Her özellik için eğitim örneklerinde minimum ve maksimum bulunur.

$$x_i' = \frac{x_i - \min_i}{\max_i - \min_i} \in [0, 1]$$

- Sıfır merkezli olsun istenirse $[-1, 1]$ aralığına da çekilebilir (genelde $[0, 1]$ kullanılır):

$$x_i' = 2 \cdot \frac{x_i - \min_i}{\max_i - \min_i} - 1$$

**Standartlaştırma (z-score)**

- $N$ eğitim örneği ve $i$. özellik için:

$$\mu_i = \frac{1}{N} \sum_{d=1}^{N} x_{d,i}, \qquad \sigma_i = \sqrt{\frac{1}{N} \sum_{d=1}^{N} (x_{d,i} - \mu_i)^2}$$

$$x_{d,i}' = \frac{x_{d,i} - \mu_i}{\sigma_i}$$

- Ortalama her özellik için ayrı hesaplanır. Örnek: eğitim örnekleri $(1, 3, 5)$ ve $(2, 4, 6)$ ise $\mu = (3/2, 7/2, 11/2)$.
- Gauss (normal) dağılım: çoğunluk ortalamaya yakın, az sayıda örnek uçlarda. Örnek: bir sınıftaki öğrencilerin boyları.
- Veri Gauss dağılımlıysa standartlaştırma, değilse min-max tercih edilir.

**Karışık özellikler (öğrenci sorusu)**

- Bazı özellikler kategorik, bazıları sayısalsa: az sayıda kategorik özellik Hamming mantığıyla 0/1 olarak eklenebilir. Sayısal olanlar normalize edilir.
- Kategorik özellik çoksa, ileriki haftalarda anlatılacak one-hot encoding gibi yöntemlerle sayıya çevrilir.
- Hoca: "Sizin datanız, sizin probleminiz nedir? Buna bakarak karar vermeniz çok önemli."

### K'nin seçimi

- Veri üç parçaya ayrılır: eğitim (training), doğrulama (validation), test.
- Örnek: $D_1$-$D_{14}$ eğitim, $D_{15}$-$D_{20}$ doğrulama.
- Doğrulama kümesindeki tüm örnekler K = 1, 3, 5, 7 (gerekirse 9) için sınıflandırılır, her K için başarı ölçülür.
- En yüksek başarıyı veren K seçilir.
- Sonra test kümesiyle, hiçbir parametre değiştirmeden, önyargısız başarı raporlanır (ör. "K = 5 için accuracy 0,92").
- Veri bölme ayrıntıları ilerideki model seçimi (model selection) dersinde anlatılacak.
- Probleme göre en iyi K değişir. Ör. bir problemde K = 3, kredi kartı sahtekârlığı tespitinde K = 5 en iyi olabilir.

### Özelliklere ağırlık verme

- Bazı özellikler diğerlerinden daha önemliyse ağırlık eklenebilir.
- İki yol:
  1. Farklı ağırlıkları deneyip doğrulama başarısına bakmak.
  2. Ağırlığı doğrudan farkın tersi olarak eklemek: $w_k = \dfrac{1}{(x_k - x_{new,k})^2}$. Fark küçüldükçe ağırlık büyür.
- İkinci formülün tam yazımı altyazıda net değil. Sözlü anlatım "farkın karesinin bir bölüsü" şeklinde.

### Karmaşıklık ve tembel öğrenme

- Bir örneğe mesafe: $O(D)$. $D$ küçük bir sabitse $O(1)$ denebilir. Özellik sayısı on binler, yüz binler mertebesindeyse $D$ olarak bırakılmalıdır.
- $N$ eğitim örneği için 1-NN: $O(N \cdot D)$. $D$ küçükse $O(N)$.
- Hoca K-NN için karmaşıklığı $O(K \cdot N \cdot D)$ olarak verdi (bkz. "Ders sonrası notlar").
- k-NN'e lazy learning denir: eğitimde öğrenme yoktur, tüm karşılaştırma test anında yapılır.
- Eski kaynaklarda k-NN'in 20-40 gibi az örnekte kullanılması önerilirdi. Bugün daha çok örnekle genelleme istendiği için hızlandırma gerekir.
- Bir öğrenci eğitim kümesi için hesaplamayı önceden yapıp saklamayı önerdi. Hoca bunun mümkün olmadığını söyledi: bilinmeyen örnek her seferinde yenidir.
- Hızlanmanın yolu $N$'yi akıllıca azaltmaktır.

### Voronoi diyagramı ve gereksiz örnekler

- Her eğitim örneği için, komşularıyla arasındaki orta çizgilerden bir sınır çizilir. Bu Voronoi diyagramıdır.
- Gündelik örnek: baz istasyonlarının kapsama alanları Voronoi diyagramıyla belirlenir.
- Bir örneğin Voronoi komşularının hepsi kendi sınıfındansa, o örnek silinebilir. Çevresinde başka sınıftan örnek olmadığı için sınıflandırmaya katkısı yoktur.
- Sınıf sınırındaki örnekler ise korunmalıdır.

### Edited instance-based learning

**Incremental deletion (yukarıdan aşağı)**

1. Tüm eğitim kümesiyle başla.
2. Her örneği sırayla test örneği gibi düşün, kalan örneklerle k-NN ile sınıflandır.
3. Doğru sınıflanıyorsa çevresi kendi sınıfıyla doludur, sil.
4. Yanlış sınıflanıyorsa sınırdadır, koru.

- Öğrenci sorusu: K = 5 için komşulardan biri farklı sınıftansa ne olacak? Hoca: oylama doğru sonucu veriyorsa silinir. İstenirse "beş komşunun hepsi aynı sınıftaysa sil" gibi daha sıkı bir kural denenip başarı karşılaştırılabilir.
- Önce K seçilir ve model kurulur. Silme işlemi sonra, seçilen K ile yapılır. K çok küçük seçilmemelidir.

**Incremental growth (aşağıdan yukarı)**

1. Boş kümeyle başla. Başlangıç sorunu olmasın diye her sınıftan K kadar örnekle başlamak gerekir (ör. K = 3 için 3'er örnek).
2. Her eğitim örneğini mevcut kümeyle sınıflandır.
3. Doğru sınıflanıyorsa ekleme.
4. Yanlış sınıflanıyorsa ekle (koru).

- Sorun: başlangıç örnekleri sınırdan uzak bölgelerden seçilirse gereksiz örnekler kümeye girebilir.
- Incremental deletion'da bu sorun yoktur, çünkü tüm kümeyle başlanır.

### K boyutlu ağaç (k-d tree)

- Eğitim örnekleriyle, düğümleri örnek olan bir ikili ağaç kurulur.
- Her düğüm, bir eksen boyunca uzayı ikiye böler. Bilinmeyen örnek, ağaçta ilerleyerek hangi bölgede olduğunu bulur. Diğer bölgelerdeki örneklerle hiç karşılaştırılmaz.

**Örnek 5: Gösterilen k-d tree**

- Kök F: $x_1 > 6$ mı? Bu, uzayı dikey bir çizgiyle ikiye böler.
- $x_1 \le 6$ tarafında C düğümü: $x_2 > 10$ mu? Üstte A ve B, altta D ve E kalır.
- Bilinmeyen örnek $(2, 3)$:
  - $x_1 > 6$? Hayır.
  - $x_2 > 10$? Hayır.
  - $x_2 > 4$? Hayır.
  - Yaprağa ulaşıldı. Bu bölgedeki örneklerin (hocanın anlatımında E ve F) sınıfı atanır.
- I, J, H, G gibi diğer örneklerle mesafe hesaplanmaz.

- **Karar ağacından farkı:** karar ağacında düğümler özelliklerdir (sıcaklık, rüzgâr gibi) ve bilgi kazancı (information gain) ile seçilir. k-d tree'de düğümler örneklerdir ve ilerleme örneklerin konumuna göre yapılır.
- Karmaşıklık: ortalamada $O(\log N)$, ağaç kötü kurulursa $O(N)$.
- Özellik sayısı arttıkça ağacı kurmak çok zorlaşır. Bu yüzden yüksek boyutta tercih edilmez.
- Hoca kavram olarak bilinmesini yeterli buldu. Algoritmanın ayrıntısını istenirse ayrıca anlatabileceğini söyledi.

### Ders sonrası notlar

- **Hamming mesafesi:** derste eşit özelliğe 1, farklı özelliğe 0 verildi. Standart tanımda tersidir: farklı özellik 1, eşit özellik 0 sayılır. Mesafe, farklı olan özellik sayısıdır. Derste hesaplanan değer aslında eşleşen özellik sayısı, yani bir benzerliktir. (Ankara, İzmir, İstanbul) ile (Ankara, Diyarbakır, Muğla) için Hamming mesafesi 2'dir. (Ankara, İzmir, Muğla) ile ise 1'dir.
- **Öklid örneği:** $\sqrt{42} \approx 6{,}48$.
- **k-NN karmaşıklığı:** derste $O(K \cdot N \cdot D)$ dendi. Daha yaygın ifade şudur: mesafe hesabı $O(N \cdot D)$, en yakın K'yı seçmek $O(N \log K)$ (yığın ile) ya da $O(N)$ (seçme algoritmasıyla). Toplam genelde $O(N \cdot D)$ olarak verilir.
- **Incremental deletion anlatımında dil sürçmesi:** hoca bir yerde "doğru sınıflandırmıyorsa silebilirsiniz" dedi. Kuralın doğrusu: doğru sınıflanıyorsa silinir.
- **Incremental growth anlatımında dil sürçmesi:** "doğru sınıflandırılıyorsa koruyorsunuz" cümlesi geçti. Kuralın doğrusu: yanlış sınıflanıyorsa eklenir.
- **k-d tree kurulumu:** hoca kök düğümün branch and bound ile seçildiğini söyledi. Standart k-d tree kurulumunda bölme ekseni sırayla değiştirilir ve genelde medyan noktası düğüm yapılır. Branch and bound, en yakın komşuyu ararken hangi dalların budanacağını belirlemek için kullanılır.
- **Kosinüs benzerliği ve mesafe:** derste "cosine distance" ve "cosine similarity" birlikte kullanıldı. Kosinüs mesafesi genelde $1 - \cos\theta$ olarak tanımlanır.
- **Mahalanobis:** "covariance bilgisini de kullanan" mesafe olarak anıldı: $d = \sqrt{(x - y)^T \Sigma^{-1} (x - y)}$.
- Ders yaklaşık 10:05'te başladı. 10:40 civarında 15 dakika, 11:30'da 5 dakika ara verildi.

Gemini Notebook gibi bir araca altyazı dosyasını yükleyerek bu ders hakkında daha ayrıntılı soru-cevap yapabilirsiniz.
