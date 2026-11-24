# Ders 10 Genişletilmiş Notu: SVM Kaybı ve Optimizasyon, Düzenlileştirme, Transfer Öğrenme ve Nesne Tespiti

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersten Kalanlar ve Haftanın Konuları
- 2. Derin Öğrenmede Eğitim Döngüsü
- 3. Doğrusal Skor Fonksiyonu
- 4. Kayıp Fonksiyonu: Çok Sınıflı SVM Kaybı
- 5. Optimizasyon: Stokastik Gradyan İnişi
- 6. Aşırı Öğrenme
- 7. Düzenlileştirme Terimi: L2, L1 ve Elastic Net
- 8. Dropout
- 9. Veri Artırma
- 10. Transfer Öğrenme
- 11. Sınıflamanın Ötesindeki Görme Görevleri
- 12. Anlamsal Bölütleme
- 13. Sınıflama ve Konumlandırma
- 14. Nesne Tespiti: R-CNN Ailesi, YOLO ve SSD
- 15. Terimlerin Türkçe Karşılıkları
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersten Kalanlar ve Haftanın Konuları

Ders, bir önceki derste nerede kalındığının hatırlanmasıyla başladı. Evrişimsel sinir ağlarında havuzlama (max pooling) anlatılmış, ardından AlexNet, VGGNet, GoogLeNet ve ResNet mimarilerinin gelişimi özetlenmiş ve sağdaki doğruluk karşılaştırma (accuracy comparison) grafiği üzerinden bu mimariler kıyaslanmıştı.

Bu haftanın konuları derin öğrenmede optimizasyon, düzenlileştirme (regularization), dropout, veri artırma (data augmentation) ve transfer öğrenmedir (transfer learning). Dersin sonunda bölütleme, konumlandırma ve nesne tespitine de geçildi.

Hoca, dersin derin öğrenme bölümlerinde Stanford Üniversitesi'nin CS231n kodlu dersinin notlarından yararlandığını hatırlattı. Bu dersin 2017 yılına ait 14-15 haftalık kayıtları YouTube'da bulunuyor; slaytları, kodları ve ödevleri de erişilebilir. Konuyu daha ayrıntılı öğrenmek isteyenlere bu kursu, ödevleriyle birlikte takip etmelerini önerdi.

## 2. Derin Öğrenmede Eğitim Döngüsü

Bir derin öğrenme modelini eğitmek dört adımlı bir döngüdür (ekrandan, 00:20:00):

1. Etiketli veriden küçük bir parça (batch) örneklenir.
2. Bu parça ağdan ileri doğru geçirilir ve tahminler alınır. İlk anda ağın parametreleri rastgele seçilmiş değerlerdir.
3. Tahmin ile gerçek değer arasındaki farka bakılarak hata hesaplanır ve geri yayılır (backpropagation).
4. Ağın ağırlıkları güncellenir. Amaç hatayı en küçüklemektir.

Bu güncelleme bir optimizasyon problemidir. Bir amaç fonksiyonu (objective function), maliyet fonksiyonu (cost function) ya da kayıp fonksiyonu (loss function) tanımlanır; kaybı en küçüklemek ya da amaç fonksiyonunu en büyüklemek hedeflenir. Slayttaki ifadeyle, tahmin ile hedef değer arasındaki farkı ölçen bir hata sinyali üretilir ve bu sinyal ağırlıkları değiştirip daha doğru tahmin elde etmek için kullanılır. Gradyanın bir kesrini çıkarmak, maliyet fonksiyonunun (yerel) minimumuna doğru ilerletir (ekrandan, 00:20:00).

Optimizasyonda stokastik gradyan inişi (stochastic gradient descent, SGD), momentum ve uyarlanır moment kestirimi (Adam) gibi yöntemler kullanılır. Slayttaki yüzey grafiğinde SGD, Momentum, NAG, Adagrad, Adadelta ve RMSprop yöntemlerinin aynı yüzey üzerindeki ilerleyişi karşılaştırılmaktadır (ekrandan, 00:20:00). Bu yöntemlerin amacı işlemi olabildiğince hızlı yapmaktır, çünkü optimizasyon zaman alan, maliyetli bir işlemdir.

## 3. Doğrusal Skor Fonksiyonu

### 3.1 Boyutlar

Yapı bir örnek üzerinden özetlendi (ekrandan, 00:25:00). Giriş görüntüsü CIFAR-10 kümesinden bir kedi görüntüsüdür ve $32\times32\times3$ boyutundadır (0 ile 1 arasında sayılardan oluşan bir dizi). Bu görüntü düzleştirilerek (flatten) $x$ vektörüne çevrilir.

Skor fonksiyonu

$$f(x, W) = Wx$$

biçimindedir (bias eklenince $Wx + b$). Boyutlar:

- $x$: $32 \cdot 32 \cdot 3 = 3072$ olduğundan $3072\times1$.
- $f(x, W)$: 10 sınıf için 10 skor, yani $10\times1$.
- $W$: bu çarpımın mümkün olması için $10\times3072$. 10 satır, 3072 sütun.

$W$'nin her satırı $x$ ile çarpıldığında bir sayı elde edilir; birinci satır birinci sınıfın, ikinci satır ikinci sınıfın skorunu verir. Skoru en yüksek olan sınıf, modelin tahminidir. $W$'deki değerlere parametreler ya da ağırlıklar (weights) denir.

Hoca lineer cebirdeki gösterim alışkanlığını hatırlattı: matrisler büyük harfle, vektörler küçük harfle gösterilir. Bu sayede bir ifadeye bakarak hangi terimin matris, hangisinin vektör olduğu anlaşılabilir.

### 3.2 Giriş vektörünün oluşturulması

$x$ vektörü iki biçimde oluşturulabilir. Birincisinde giriş görüntüsünün bütün satırları art arda eklenir (concatenate). İkincisinde art arda yerleştirilmiş evrişim katmanlarıyla öznitelik çıkarılır ve elde edilen öznitelik haritası düzleştirilerek vektöre çevrilir.

CIFAR-10, kedi, köpek, uçak, kurbağa, araba gibi 10 farklı sınıftan oluşan bir veri kümesidir. Çıkış vektörünün 10 uzunluklu olması bu yüzdendir.

### 3.3 Üç sınıflı basit örnek

Slayttaki basitleştirilmiş örnekte 3 satır ve 4 sütundan oluşan bir ağırlık matrisi vardır; yani 3 sınıflı bir sınıflayıcı söz konusudur. Ağırlık matrisinin birinci satırı $x_i$ vektörüyle çarpılır, bias eklenir ve birinci sınıfın skoru bulunur; aynı işlem öbür satırlar için tekrarlanır. Örnekte en büyük skor köpek sınıfı için çıkmıştır, oysa giriş görüntüsü bir kedidir. Sınıflama yanlıştır ve bu çıktı için hata yüksek olacaktır. <!-- BELİRSİZ: üç sınıflı örneğin ağırlık, bias ve skor değerleri karede yok; altyazıda da okunmuyor. -->

Ağırlık matrisindeki değerler ve bias değerleri, iyileştirilebilir (öğrenilebilir) parametrelerdir. Eğitimin amacı bu değerleri güncelleyerek daha doğru sınıflama yapan bir sınıflayıcı elde etmektir.

## 4. Kayıp Fonksiyonu: Çok Sınıflı SVM Kaybı

### 4.1 Neden kayıp fonksiyonu?

Sonraki slaytta üç giriş görüntüsü (kedi, araba, kurbağa) için CIFAR-10'un 10 sınıfına ait skorlar verilmiştir (ekrandan, 00:30:00). Bu skorlar bir $W$ ile hesaplanmıştır:

| Sınıf | Kedi | Araba | Kurbağa |
|---|---|---|---|
| airplane | -3.45 | -0.51 | 3.42 |
| automobile | -8.87 | **6.04** | 4.64 |
| bird | 0.09 | 5.31 | 2.65 |
| cat | **2.9** | -4.22 | 5.1 |
| deer | 4.48 | -4.19 | 2.64 |
| dog | 8.02 | 3.58 | 5.55 |
| frog | 3.78 | 4.49 | **-4.34** |
| horse | 1.06 | -4.37 | -1.5 |
| ship | -0.36 | -2.09 | -4.79 |
| truck | -0.72 | -2.93 | 6.14 |

Kedi görüntüsünde en yüksek skor köpek (8.02), sonra geyik (4.48) için çıkmış; kedi skoru ancak sıralamada geride. Burada bir hata dönmelidir. Araba görüntüsünde en yüksek skor otomobil sınıfındadır (6.04); tahmin doğrudur. Kurbağa görüntüsünde en yüksek skor kamyon (6.14) için çıkmış, kurbağanın skoru ise -4.34'tür.

Slaydın sağındaki "TODO" iki işi tanımlar: (1) eğitim verisindeki skorlardan ne kadar memnun olmadığımızı ölçen bir kayıp fonksiyonu tanımlamak, (2) bu kaybı en küçükleyen parametreleri verimli biçimde bulmanın yolunu bulmak (optimizasyon). Önce hata hesaplanacak, sonra bu hata üzerinden $W$ güncellenecektir.

### 4.2 SVM kaybının tanımı

Daha basit bir örneğe geçildi: üç eğitim örneği ve üç sınıf (ekrandan, 00:35:00). Bir $W$ ile hesaplanan skorlar şunlardır:

| Sınıf | Kedi görüntüsü | Araba görüntüsü | Kurbağa görüntüsü |
|---|---|---|---|
| cat | **3.2** | 1.3 | 2.2 |
| car | 5.1 | **4.9** | 2.5 |
| frog | -1.7 | 2.0 | **-3.1** |

Bir örnek $(x_i, y_i)$ ile gösterilir. $x_i$ görüntüdür (örneğin $32\times32\times3$'lük görüntünün 3072 uzunluklu düzleştirilmiş hali), $y_i$ ise tamsayı etikettir. Sınıflar cat, car, frog ise etiketler 0, 1, 2 (ya da 1, 2, 3) olabilir; etikete bakarak sınıfın hangisi olduğu söylenebilir. Skor vektörü kısaca $s = f(x_i, W)$ ile gösterilir.

SVM kaybı şöyle tanımlanır:

$$L_i = \sum_{j \ne y_i} \max\left(0,\; s_j - s_{y_i} + 1\right)$$

Doğru sınıf $y_i$ dışarıda tutulur. Geriye kalan her $j$ sınıfı için, o sınıfın skoru $s_j$ ile doğru sınıfın skoru $s_{y_i}$ arasındaki farka 1 eklenir, sonuç 0 ile karşılaştırılır ve büyük olan alınır. Bu değerler bütün yanlış sınıflar için toplanarak $i$. örneğin kaybı bulunur.

### 4.3 Sayısal hesap

**Kedi görüntüsü** (ekrandan, 00:40:00). Doğru sınıf cat, $s_{y_i} = 3.2$.

$$L_1 = \max(0,\; 5.1 - 3.2 + 1) + \max(0,\; -1.7 - 3.2 + 1) = \max(0, 2.9) + \max(0, -3.9) = 2.9 + 0 = 2.9$$

Kedi görüntüsü verildiği halde car sınıfına 5.1 skor verilmiştir; bu fark kayba 2.9 olarak yansır. Frog skoru (-1.7) doğru sınıfın skorundan yeterince düşük olduğu için 0 katkı yapar.

**Araba görüntüsü.** Doğru sınıf car, $s_{y_i} = 4.9$. Karşılaştırma hep doğru sınıfın skoruyla yapılır.

$$L_2 = \max(0,\; 1.3 - 4.9 + 1) + \max(0,\; 2.0 - 4.9 + 1) = \max(0, -2.6) + \max(0, -1.9) = 0$$

Otomobil görüntüsü verilmiş ve en yüksek skor otomobile çıkmıştır; üstelik öbür skorlardan en az 1 büyüktür. Kayıp 0'dır.

**Kurbağa görüntüsü** (ekrandan, 00:45:00). Hoca bu örneği öğrencilere yaptırdı. Doğru sınıf frog, $s_{y_i} = -3.1$.

$$L_3 = \max(0,\; 2.2 - (-3.1) + 1) + \max(0,\; 2.5 - (-3.1) + 1) = 6.3 + 6.6 = 12.9$$

Eksi ile eksinin çarpımı artı olur: $2.2 + 3.1 + 1 = 6.3$ ve $2.5 + 3.1 + 1 = 6.6$.

> **Ders sonrası not:** Slaytta bu satırlar $\max(0, 5.3) + \max(0, 5.6) = 10.9$ olarak yazılmıştı (ekrandan, 00:45:00). Hoca doğrusunun 6.3 + 6.6 = 12.9 olduğunu söyledi ve hatayı öğrencilerin yakalaması için bilerek düzeltmediğini belirtti. Değerler python ile doğrulandı.

### 4.4 Toplam kayıp

Her örneğin kaybı bulunduktan sonra bütün eğitim kümesi için kayıp, kayıpların ortalamasıdır:

$$L = \frac{1}{N}\sum_{i=1}^{N} L_i = \frac{2.9 + 0 + 12.9}{3} \approx 5.27$$

> **Ders sonrası not:** Hoca slayttaki ortalama hesabında da hata olduğunu, göz ardı edilmesini söyledi. Slayttaki ortalama büyük olasılıkla hatalı 10.9 değeriyle hesaplanmıştı ($(2.9 + 0 + 10.9)/3 = 4.6$). Doğru değer yaklaşık 5.27'dir (python ile doğrulandı). <!-- BELİRSİZ: ortalama kaybın yazılı olduğu slaydın karesi yok. -->

### 4.5 Vektörel NumPy kodu

Slaytta kaybın NumPy ile vektörel (vectorized) biçimde nasıl hesaplanacağını gösteren bir fonksiyon vardı. Fonksiyon $x$ giriş vektörünü, $y$ etiketini ve $W$ ağırlık matrisini alır. Önce matris-vektör çarpımıyla skorları hesaplar. Sonra bütün skorlardan doğru sınıfın skorunu (`scores[y]`) çıkarıp 1 ekleyerek ve 0 ile karşılaştırarak `margins` dizisini üretir. Doğru sınıfın gözünü (`margins[y]`) sıfırlar ki toplamı etkilemesin. En son `margins` dizisini toplayarak kaybı bulur. <!-- BELİRSİZ: kodun birebir metni karede yok; aşağıdaki kod derste gösterilen kodun birebir kopyası değildir. -->

Altyazıdaki anlatıma göre ajan tarafından yazılmış ve yukarıdaki tabloyla test edilmiş (çıktı 2.9, 0, 12.9) bir karşılığı:

```python
import numpy as np

def L_i_vectorized(x, y, W):
    scores = W.dot(x)
    margins = np.maximum(0, scores - scores[y] + 1)
    margins[y] = 0
    loss_i = np.sum(margins)
    return loss_i
```

Hoca bu çözümü çok beğendiğini söyledi: aynı işlem iç içe for döngüleriyle de yazılabilir, ama vektörel yazım hem kodu kolaylaştırır hem de daha hızlı çalışır.

## 5. Optimizasyon: Stokastik Gradyan İnişi

### 5.1 Fikir

Toplam kayıp, $i = 1$'den $N$'e kadar her görüntü için $x_i$, $y_i$ ve $W$ ile hesaplanan $L_i$ değerlerinin ortalamasıdır. Kayıp, $W$ matrisindeki parametrelere bağlı olduğundan bu parametrelere göre türev alınarak kaybı en küçükleyen ağırlıklar aranır. Bunun için stokastik gradyan inişi kullanılabilir.

### 5.2 Doğru uydurma örneği

Slayttaki örnek (Wikipedia'daki SGD maddesinden alınmıştır) iki parametreli bir problemdir (ekrandan, 00:50:00). $(x_1, \dots, x_n)$ gözlemlerine ve bunlara karşılık gelen $(\hat{y}_1, \dots, \hat{y}_n)$ kestirilmiş yanıtlarına en küçük kareler yöntemiyle

$$\hat{y} = w_1 + w_2 x$$

doğrusu uydurulmak istenir. Bu, $\hat{y} = ax + b$ biçiminde bir doğru denklemi bulmaya benzer; burada $a$ ve $b$ yerine $w_1$ ve $w_2$ yazılmıştır. Gerçek değeri ve kestirilen değeri biliyoruz; aralarındaki fark hatayı verir. En küçüklenecek amaç fonksiyonu hata karelerinin toplamıdır:

$$Q(w) = \sum_{i=1}^{n} Q_i(w) = \sum_{i=1}^{n}(\hat{y}_i - y_i)^2 = \sum_{i=1}^{n}(w_1 + w_2 x_i - y_i)^2$$

Güncelleme adımı matris biçiminde şöyle yazılır (ekrandan, 00:55:00):

$$\begin{bmatrix} w_1 \\ w_2 \end{bmatrix} := \begin{bmatrix} w_1 \\ w_2 \end{bmatrix} - \eta \begin{bmatrix} \frac{\partial}{\partial w_1}(w_1 + w_2 x_i - y_i)^2 \\ \frac{\partial}{\partial w_2}(w_1 + w_2 x_i - y_i)^2 \end{bmatrix} = \begin{bmatrix} w_1 \\ w_2 \end{bmatrix} - \eta \begin{bmatrix} 2(w_1 + w_2 x_i - y_i) \\ 2x_i(w_1 + w_2 x_i - y_i) \end{bmatrix}$$

$w_1$'e göre türev alındığında karenin üssü 2 katsayı olarak öne gelir ve parantez içi aynen kalır. $w_2$'ye göre türevde ise ayrıca $w_2$'nin katsayısı olan $x_i$ öne gelir: $2x_i(\dots)$. $\eta$ öğrenme oranıdır (learning rate). Her parametre, mevcut değerinden türev ile öğrenme oranının çarpımı çıkarılarak bir sonraki iterasyon için güncellenir; türevin işaretine göre bu adım artı ya da eksi yönde olabilir.

Slayttaki not: her iterasyonda (güncellemede) gradyan, bütün örnekler kümesi yerine tek bir $x_i$ noktasında hesaplanır. Standart (batch) gradyan inişinden temel farkı budur: adımı hesaplamak için veri kümesinden yalnız bir parça kullanılır ve bu parça her adımda rastgele seçilir (ekrandan, 00:50:00).

### 5.3 SGD'nin geliştirilmiş biçimleri

SGD daha hızlı yakınsayan çözümler bulmak için çeşitli biçimlerde geliştirilmiştir. Momentum eklenmiş, ardından uyarlanır moment kestirimi (Adaptive Moment Estimation, Adam) önerilmiştir. Adam bugün en yaygın ve en başarılı kullanılan optimizasyon yöntemlerinden biridir. Hepsinin amacı aynıdır: ağırlık matrisindeki parametreleri kayıp fonksiyonunu en küçükleyecek biçimde güncellemek.

## 6. Aşırı Öğrenme

Eğitim sırasında iterasyon sayısına bağlı olarak eğitim kaybı (train loss) çizilir ve iterasyon ilerledikçe kaybın düşmesi beklenir. Aynı şekilde eğitim örnekleri için doğruluğun (accuracy) artması hedeflenir. Bir başka amaç da doğrulama (validation) verisinde, yani modelin daha önce hiç görmediği örneklerde, doğruluğun aynı paralelde artmasıdır. Eğitim doğruluğu ile doğrulama doğruluğu arasında büyük bir açıklık olmamalıdır; slayttaki soru "bu açıklığı nasıl azaltırız?" biçimindedir.

Hoca bu açıklığın nedenini sordu; bir öğrenci aşırı öğrenme (overfitting) cevabını verdi. Hoca bunu onayladı: model eğitim verisini ezberlemektedir. Aşırı öğrenmenin önüne geçmek için yalnız iterasyon sayısını azaltmak ya da eğitim örneği sayısını artırmak değil, derin öğrenmeye özgü başka çözümler de önerilmiştir. Bunların ortak adı düzenlileştirmedir (regularization) ve birden çok biçimi vardır.

## 7. Düzenlileştirme Terimi: L2, L1 ve Elastic Net

SVM kaybı, $j \ne y_i$ olan bütün sınıflar için $\max(0, s_j - s_{y_i} + 1)$ terimlerinin toplanması ve örnekler üzerinden ortalama alınmasıyla bulunuyordu. Bu kayıp fonksiyonuna bir düzenlileştirme terimi eklenir:

$$L(W) = \frac{1}{N}\sum_{i=1}^{N}\sum_{j \ne y_i}\max\left(0,\; f(x_i;W)_j - f(x_i;W)_{y_i} + 1\right) + \lambda R(W)$$

Bu terimin eklenmesiyle aşırı öğrenme büyük ölçüde önlenir. <!-- BELİRSİZ: düzenlileştirme slaydının karesi yok; formül altyazıdaki anlatıma ve SVM kaybının yukarıdaki tanımına göre yazıldı. --> Düzenlileştirme teriminin biçimleri:

- **L2 düzenlileştirme:** $R(W) = \sum_k\sum_l W_{k,l}^2$. $W$ matrisindeki bütün değerlerin karelerinin toplamıdır. Karekökü alınsaydı tam L2 norm olurdu. Bu değer $\lambda$ katsayısıyla çarpılıp kayba eklenir.
- **L1 düzenlileştirme:** $R(W) = \sum_k\sum_l |W_{k,l}|$. Her parametrenin mutlak değeri alınıp toplanır.
- **Elastic net (L1 + L2):** iki terimin belli bir katsayıyla birleştirilmesidir.

Hoca, özgün fikrin bu düzenlileştirme terimini kayba eklemek olduğunu, sonraki çalışmaların bu fikrin paralelinde geliştirildiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** CS231n notlarında Elastic net büyük olasılıkla $R(W) = \sum_k\sum_l \left(\beta W_{k,l}^2 + |W_{k,l}|\right)$ biçiminde verilir. L2 düzenlileştirme büyük ağırlıkları cezalandırarak ağırlıkların küçük ve dağılmış olmasını teşvik eder; L1 ise birçok ağırlığın tam sıfır olmasına (seyrekliğe) yol açma eğilimindedir.

## 8. Dropout

### 8.1 Tanım

Düzenlileştirmenin ikinci biçimi dropout'tur. İlk olarak 2014'te önerilmiştir (Srivastava ve ark., "Dropout: A simple way to prevent neural networks from overfitting", JMLR 2014; ekrandan, 01:20:00). Slayttaki tanım: her ileri geçişte bazı nöronlar rastgele sıfırlanır; bırakma olasılığı bir hiperparametredir ve 0.5 yaygın bir değerdir.

Slayttaki ağda gizli katmanlar H1, H2 gibi adlandırılmıştır; her birinde dört nöron vardır. Başlangıçta bir oran belirlenir, örneğin nöronların %50'si. Sağdaki şekilde H1'de dört nörondan ikisi, H2'de de dört nörondan ikisi silinmiştir. "Silme" aslında o nöronların çıktısını sıfıra eşitlemektir.

### 8.2 Kod

Slayttaki kod üç katmanlı bir ağ için dropout'lu ileri geçişi gösterir (ekrandan, 01:25:00):

```python
p = 0.5  # probability of keeping a unit active. higher = less dropout

def train_step(X):
    """ X contains the data """

    # forward pass for example 3-layer neural network
    H1 = np.maximum(0, np.dot(W1, X) + b1)
    U1 = np.random.rand(*H1.shape) < p  # first dropout mask
    H1 *= U1  # drop!
    H2 = np.maximum(0, np.dot(W2, H1) + b2)
    U2 = np.random.rand(*H2.shape) < p  # second dropout mask
    H2 *= U2  # drop!
    out = np.dot(W3, H2) + b3

    # backward pass: compute gradients... (not shown)
    # perform parameter update... (not shown)
```

(Kod, rastgele ağırlıklarla küçük bir girdi üzerinde python ile çalıştırılarak denendi.)

Kodun adımları:

- `p`, bir nöronun etkin tutulma olasılığıdır. $p = 0.5$ ise nöronların %50'si tutulur, %50'si silinir. $p = 0.8$ seçilirse %80'i tutulur, %20'si silinir. Slayttaki ifadeyle: daha yüksek $p$, daha az dropout.
- `H1`: $W_1$ ile $X$ çarpılır, $b_1$ eklenir ve `np.maximum(0, ...)` ile sıfırla karşılaştırılıp büyük olan alınır. Bu, ReLU aktivasyonu uygulamaktır.
- `U1`: `H1` ile aynı biçimde (`H1.shape`) rastgele bir dizi üretilir. `np.random.rand` 0 ile 1 arasında değerler üretir. Bu değerler $p$'den küçükse `True` (1), büyükse `False` (0) olur. Böylece ikili bir maske (binary mask) elde edilir.
- `H1 *= U1`: katman çıktısı maskeyle çarpılır; maskede 0 olan nöronlar silinmiş olur.
- İkinci katmanda aynı işlem tekrarlanır: `H2` üretilir, aynı biçimde `U2` maskesi oluşturulur, `H2` maskeyle çarpılır.
- Son katman çıktısı `out` hesaplanır.

Hoca, ikili maskenin bu biçimde tek satırda üretilmesini çok beğendiğini, kodlamada böyle şık çözümlerin görülmesinin yapıyı anlamayı kolaylaştırdığını söyledi.

**Soru:** Dropout işlemi eğitimden önce mi yapılıyor, yoksa bütün ağırlıklar güncellendikten sonra mı uygulanıyor? **Cevap:** Her eğitim adımının (train step) içinde bir kez yapılır. Fonksiyonun adı da `train_step`'tir: önce $WX$ çarpımı yapılır, maske uygulanır, bir sonraki adımda yeni bir maske üretilerek işlem tekrarlanır.

Bir öğrenci de `np.random.rand(*H1.shape)` ifadesindeki yıldızın ne anlama geldiğini sordu; hoca bunu derste cevaplamadı (bkz. Örnek Sorular).

### 8.3 Dropout neden işe yarar?

Slayt "Bu nasıl iyi bir fikir olabilir?" diye sorar ve cevaplar: dropout ağı yedekli bir temsil (redundant representation) öğrenmeye zorlar ve özniteliklerin birbirine uyum sağlayarak aşırı bağımlı hale gelmesini (co-adaptation) engeller (ekrandan, 01:30:00).

Hocanın aktardığı yoruma göre her düğüm tanınmak istenen nesnenin belli bir özelliğine odaklanmıştır: "kulağı var", "kuyruğu var", "tüylü", "pençeleri var", "yaramaz bakışlı" gibi. Bu düğümlerin çıktıları birleşerek "kedi skoru"nu oluşturur. Bazı düğümler rastgele kapatıldığında ağ, kedi kararını tek bir özelliğe dayandıramaz. Bu bir anlamda rastgele bir öznitelik seçimi (feature selection) gibidir. En büyük yararı ise ezberlemenin, yani aşırı öğrenmenin önüne geçmesidir.

Slaytta bir başka yorum olarak, hangi nöronların bırakılacağının rastgele seçilmesi yerine bunun öğrenilecek bir parametre olarak modele katılıp katılamayacağı da tartışılmaktadır. <!-- BELİRSİZ: "Another interpretation" slaydının içeriği karede yok; altyazıda anlatım kopuk. -->

### 8.4 Test aşaması

Dropout yalnız eğitimde uygulanır. Testte (prediction) rastgele silme yapılmaz; bütün nöronlar her zaman etkindir. Bunun yerine katman çıktısı $p$ ile ölçeklenir. Slayttaki ifade: test zamanında bütün nöronlar etkin olduğundan aktivasyonlar, her nöron için test çıktısı eğitimdeki beklenen çıktıya eşit olacak biçimde ölçeklenmelidir. Tahmin fonksiyonunda her gizli katman şu biçimde hesaplanır:

$$H = p \cdot \max(0,\; Wx + b)$$

Dropout özeti: ileri geçişte bırak (drop in forward pass), test zamanında ölçekle (scale at test time). $p$ testte yalnız ölçekleme için kullanılır.

> **Ek bilgi (derste anlatılmadı):** Uygulamada sık kullanılan "inverted dropout" yönteminde ölçekleme eğitim sırasında yapılır: maske `(np.random.rand(*H1.shape) < p) / p` biçiminde üretilir. Böylece test zamanındaki tahmin fonksiyonuna dokunmak gerekmez.

## 9. Veri Artırma

Düzenlileştirmenin üçüncü biçimi veri artırmadır (data augmentation). Normal eğitimde bir giriş görüntüsü ve onun etiketi ağa verilir, çıktı üretilir ve kayıp hesaplanır. Veri artırmada giriş görüntüsü, etiketi değişmeyecek biçimde dönüştürülerek çoğaltılır. Slaytta gösterilen dönüşümler:

- **Yatay çevirme (horizontal flip):** görüntünün aynadaki görüntüsü alınır.
- **Rastgele kırpma ve ölçekleme (random crops and scales):** görüntüden rastgele parçalar kesilip girdi olarak verilir.
- **Renk titretme (color jitter):** parlaklık ve kontrast ile oynanır.

Slayt "probleminiz için yaratıcı olun" der: üzerinde çalışılan işin türüne göre başka dönüşümler de düşünülebilir. Örneğin şunların rastgele karışımları ya da birleşimleri kullanılabilir (ekrandan, 01:35:00):

- öteleme (translation),
- döndürme (rotation),
- germe (stretching),
- kesme (shearing),
- lens bozulmaları vb.

## 10. Transfer Öğrenme

### 10.1 Neden gerekli?

Derin öğrenmede bir modelin başarılı olması için çok sayıda eğitim örneği gerekir. ImageNet gibi bir görüntü kütüphanesiyle çalışıldığında milyonlarca eğitim örneği vardır ve başarılı bir model eğitmek mümkündür. Ama elimizdeki problemde eğitim için az örnek varsa transfer öğrenme kullanılır: ImageNet gibi geniş bir kütüphaneyle eğitilmiş bir model ön eğitimli (pre-trained) model olarak alınır ve kendi verimizle ek bir eğitim (iyileştirme) yapılır.

### 10.2 Üç durum

Slayttaki "Transfer Learning with CNNs" şemasında üç sütun vardır (ekrandan, 01:40:00). Ağ, alttan yukarıya Image, iki Conv-64 + MaxPool, iki Conv-128 + MaxPool, iki Conv-256 + MaxPool, iki Conv-512 + MaxPool, iki Conv-512 + MaxPool, FC-4096, FC-4096 ve en üstte çıkış katmanından oluşur.

1. **ImageNet'te eğitim.** Evrişim ve havuzlama katmanları öznitelik çıkarır, tam bağlantılı (fully connected) katmanlar sınıflar. ImageNet'te 1000 sınıf olduğu için son katman FC-1000'dir. Her sınıftan çok sayıda örnekle bu ağ eğitilebilir.
2. **Küçük veri kümesi (C sınıf).** Ön eğitimli modelin öznitelik çıkarım katmanları ve tam bağlantılı katmanları dondurulur (freeze); bunların parametreleri değiştirilmez. Yalnız çıkış katmanı, 1000 çıkış yerine sınıf sayısı kadar çıkışı olan FC-C katmanıyla değiştirilir, yeniden başlatılır ve eldeki küçük veriyle eğitilir.
3. **Daha büyük veri kümesi.** Öznitelik çıkarım katmanları yine dondurulur; son iki FC-4096 katmanı ve FC-C çıkış katmanı eğitilir. Slayttaki notlar: daha büyük veri kümesiyle daha çok katman eğitilir; ince ayar (fine-tuning) yaparken öğrenme oranı düşürülür, asıl öğrenme oranının 1/10'u iyi bir başlangıç noktasıdır.

Bu seçenekler, özellikle küçük veri kümeleriyle çalışırken esneklik ve avantaj sağlar.

Sonraki slaytlarda daha önce konuşulan AlexNet örneğine dönülür: 4096 düğümlü iki tam bağlantılı katman ve çıkışta 1000 sınıf için çıktı üreten bir softmax katmanı. Burada yeni bir bilgi yoktur.

**Soru:** Derste kullanılan kodlar nereden alınıyor? **Cevap:** Bu mimarilerle ilgili kodlar pek çok yerde bulunur. Derste kullanılan malzeme Stanford'un CS231n dersindendir; o derse ait kodlar GitHub'da bulunabilir.

## 11. Sınıflamanın Ötesindeki Görme Görevleri

Yeni bir slayt destesine (CS231n, "Segmentation, Localization and Detection") geçildi. Şimdiye kadar sınıflama öğrenildi: girişe bir görüntü verilir, örneğin AlexNet ile öznitelik çıkarılır, tam bağlantılı katmanla sınıf skorları elde edilir ve softmax katmanı toplamı 1 olan olasılıklar üretir; örneğin görüntünün %90 olasılıkla kedi olduğu söylenir.

Bilgisayarla görmedeki diğer görevler şunlardır (ekrandan, 01:45:00):

- **Anlamsal bölütleme (semantic segmentation):** "Nesne yok, yalnız pikseller." Her pikselin hangi sınıfa ait olduğu söylenir. Örnekte yeşil bölge çimen, sarı bölge kedi, ayrıca ağaç ve gökyüzü etiketlenmiştir.
- **Sınıflama + konumlandırma (classification + localization):** Tek nesne. Nesnenin sınıfı (kedi) bulunur ve sınırlarını gösteren kırmızı bir sınırlayıcı kutu (bounding box) çizilir.
- **Nesne tespiti (object detection):** Birden çok nesne. Aynı görüntüdeki iki köpek ve bir kedi ayrı ayrı bulunur ve her birinin kutusu çizilir.
- **Örnek bölütleme (instance segmentation):** Birden çok nesne piksel düzeyinde işaretlenir: kırmızı alan bir köpek, yeşil alan başka bir köpek, mavi alan kedi, geri kalan arka plandır.

## 12. Anlamsal Bölütleme

### 12.1 Tanım ve eksik yanı

Anlamsal bölütlemede görüntüdeki her piksel bir kategori etiketiyle etiketlenir: gökyüzü, ağaç, kedi, çimen ayrı ayrı işaretlenir. Önemli nokta, yöntemin nesne örneklerini (instance) ayırt etmemesi, yalnız piksellerle ilgilenmesidir. Slayttaki ikinci örnekte gövdeleri kısmen örtüşen iki inek vardır; anlamsal bölütleme çıktısı bu iki ineği ayrı ayrı işaretlemez, bütün bölgeyi aynı renge (kahverengi) boyar. İki ayrı nesneyi birbirinden ayırt edememek, yöntemin bir eksiği olarak gösterilir.

### 12.2 Yama yaklaşımı ve tam evrişimli ağ

Anlamsal bölütleme için piksel düzeyinde etiketlenmiş eğitim örnekleri gerekir. Bir yaklaşımda görüntüden yamalar (patch) kesilir ve yamanın merkezindeki pikselin sınıfı tahmin edilir; eğitim verisi bu biçimde verilir.

Daha yaygın yaklaşım, ağı bir dizi evrişim katmanı olarak tasarlayıp bütün piksellerin tahminini tek seferde yapmaktır (fully convolutional; ekrandan, 01:50:00):

- Girdi: $3\times H\times W$ (yükseklik × genişlik, üç renk kanalı).
- Evrişimler: $D\times H\times W$.
- Skorlar: $C\times H\times W$ (her piksel için $C$ sınıfın skoru).
- `argmax` ile tahmin: $H\times W$ boyutlu, her pikselin sınıfını gösteren çıktı görüntüsü.

Hoca bu amaçla yaygın kullanılan U-Net mimarisinden söz etti. Kabaca bir kodlama (encoding) ve bir kod çözme (decoding) kısmından oluşur. Girişe $H\times W\times3$ boyutlu bir görüntü verilir; çıkışta aynı genişlik ve yükseklikte, her pikselin hangi sınıfa ait olduğunu gösteren etiketli bir görüntü elde edilir. U-Net ayrıntılı bir mimari olduğu için derste ayrıntısına girilmedi; özellikle tıbbi görüntülerde çok kullanılan bir yapıdır.

## 13. Sınıflama ve Konumlandırma

### 13.1 İki görev, iki kayıp

Görüntüde tek bir nesne vardır; hem nesnenin ne olduğu hem de onu saran sınırlayıcı kutunun yeri tahmin edilmelidir. Bu problem iki görevi birden barındırır (ekrandan, 01:55:00):

- **Görev 1, sınıflama:** Ortak 4096 boyutlu öznitelik vektöründen tam bağlantılı bir katman (4096'dan 1000'e) sınıf skorlarını üretir (örnekte kedi 0.9, köpek 0.05, araba 0.01). Doğru etiket kedidir; softmax kaybı hesaplanır.
- **Görev 2, kutu koordinatları:** Aynı vektörden ikinci bir tam bağlantılı katman (4096'dan 4'e) kutunun koordinatlarını $(x, y, w, h)$ üretir. Bunlar kutunun sol üst köşesinin $x$ ve $y$ koordinatı ile genişliği ve yüksekliğidir. Doğru kutu $(x', y', w', h')$ ile karşılaştırılarak L2 kaybı hesaplanır.

Bazı uygulamalarda kutu farklı gösterilir: sol üst köşe ile en-boy yerine sol üst ve sağ alt köşelerin koordinatları ($x_1, y_1, x_2, y_2$) verilebilir. Birinci görev bir sınıflama, ikinci görev ise bir sayı bulma işi olduğundan regresyondur; slayttaki ifadeyle "konumlandırmayı bir regresyon problemi olarak ele alın". İkinci görevin kaybı ortalama karesel hata türünden bir hatadır. İki görevden gelen kayıplar toplanarak bütün görev için tek bir kayıp hesaplanır. Bunun için elle işaretlenmiş görüntüler, yani yer gerçeği (ground truth) gerekir; tahmin edilen değerlerle yer gerçeği arasındaki hata kaybı verir.

### 13.2 İnsan pozu kestirimi

Aynı fikrin bir uygulaması insan pozu kestirimidir (human pose estimation). Sol ayak, sağ ayak, başın tepesi gibi eklem noktalarının koordinatları tahmin edilir. Hoca bu tür problemlerin her biri için elle etiketlenmiş binlerce veriye ihtiyaç olduğunu ve bunun büyük bir iş yükü getirdiğini vurguladı.

## 14. Nesne Tespiti: R-CNN Ailesi, YOLO ve SSD

### 14.1 Birden çok nesne

Görüntüde birden fazla nesne varsa çoklu nesne tespiti yapılır. Örnekteki görüntüde üç nesne vardır; her biri için kutuyu tanımlayan dört parametre ve nesnenin hangi sınıfa ait olduğu bilgisi bulunmalıdır.

> **Ders sonrası not:** Altyazıda hesaplanması gereken değer sayısı "16" olarak geçiyor. Üç nesne için kutu koordinatlarının sayısı $3 \times 4 = 12$'dir; slayttaki değer büyük olasılıkla 12'dir. <!-- BELİRSİZ: bu slaydın karesi yok. -->

### 14.2 Kayan pencere ve bölge önerisi

İlk kullanılan yöntemlerden biri kayan penceredir (sliding window). Sabit ya da değişken büyüklükte bir pencere görüntü üzerinde gezdirilir ve pencerenin örttüğü alanda önceden eğitilmiş sınıflardan (köpek, kedi vb.) biri ya da arka plan (background) sınıfı olup olmadığı denetlenir. Bu yöntem çok maliyetlidir.

Bölge önerisi (region proposal) yönteminde görüntü üzerinde farklı büyüklükte ve farklı yerlerden alınmış pencereler (blob benzeri görüntü bölgeleri) önerilir. Pencere içindeki renk yoğunluğu gibi ölçütlere bakılarak, bölgenin aranan sınıftan bir nesne içerip içermediğine dair bir ön eleme yapılır. Önce bölgeler önerilir, sonra bu bölgeler elenir ve modele gönderilip gönderilmeyeceğine karar verilir.

### 14.3 R-CNN

R-CNN (Regional Convolutional Neural Network), çoklu nesne tespitinde kullanılan ilk yöntemlerdendir (Girshick ve ark., "Rich feature hierarchies for accurate object detection and semantic segmentation", CVPR 2014; ekrandan, 02:00:00). Giriş görüntüsü üzerinde bir öneri yöntemiyle ilgi bölgeleri (region of interest) bulunur; 2000 civarında bölge önerilir. Her bölge ayrı ayrı evrişimsel ağdan geçirilerek öznitelik çıkarılır. Ağın sonunda çıkan özniteliklerle SVM ya da tam bağlantılı katmanlar kullanılarak sınıf etiketi tahmin edilir. Ayrıca sınırlayıcı kutu regresyonu yapılır ve kutu yer gerçeğiyle karşılaştırılarak konumlandırmanın doğruluğu değerlendirilir.

R-CNN'in sorunları:

- Birbiriyle örtüşen yüzlerce, binlerce bölgenin her biri için ayrı ayrı öznitelik çıkarıldığından çok yavaştır.
- Eğitim amaçları geçicidir (ad hoc): sınıflama için doğrusal SVM ile hinge kaybı, sonradan (post hoc) kutu regresyonu için en küçük kareler ayrı ayrı eğitilir.
- Eğitim yavaştır (84 saat) ve çok disk alanı kaplar.

### 14.4 Fast R-CNN

Bir sonraki yıl Fast R-CNN önerildi (Girshick, "Fast R-CNN", ICCV 2015; ekrandan, 02:05:00). Önemli fark şudur: bölge önerisi doğrudan giriş görüntüsü üzerinde kullanılmaz. Önce bütün görüntü bir kez ConvNet'ten geçirilerek "conv5" öznitelik haritası çıkarılır, önerilen ilgi bölgeleri bu öznitelik haritası üzerinde kullanılır. Böylece örtüşen bölgeler için her defasında evrişim yapma maliyetinden kurtulunur. Geri kalan yapı benzerdir: bir dal sınıflama, bir dal kutu konumlandırması yapar.

Eğitim süresi karşılaştırmasında R-CNN 84 saatte eğitilirken Fast R-CNN'de bu süre 8.75 saate düşer; yani yaklaşık onda birine ($84 / 8.75 \approx 9.6$). Test süresi grafiğinde, bölge önerisi süresi dahil edilerek ve edilmeyerek iki ayrı ölçüm verilmiştir; Fast R-CNN testte de R-CNN'den belirgin biçimde hızlıdır. <!-- BELİRSİZ: test süresi grafiğindeki sayısal değerler karede yok. -->

### 14.5 Faster R-CNN

Faster R-CNN (2015) bölge önerisi kısmında iyileştirme yapar. Bölgeler yine öznitelik haritası üzerinden önerilir, ama önerilen bütün bölgeler sınıflayıcıya verilmez; bunların ön elemesi ağın içinde yapılır. Bu bir avantaj sağlar ve Faster R-CNN'in test hızı Fast R-CNN'inkinin yaklaşık onda biri kadar bir süreye iner.

> **Ders sonrası not:** Altyazıda Fast R-CNN ve Faster R-CNN adları birbirine karışıyor (Whisper bozmaları ve konuşma akışı). Sıralama R-CNN (2014) → Fast R-CNN (2015) → Faster R-CNN (2015) biçimindedir; yukarıdaki anlatım bu sıraya göre düzenlendi.

Hoca, yöntemlerdeki iyileşmelerin yanında makine gücünün de önemli olduğunu ve bu işlemlerin tamamının CPU yerine grafik işlemcisi (GPU) üzerinde, çok daha hızlı yürütüldüğünü hatırlattı.

### 14.6 Öneri kullanmayan tespit: YOLO ve SSD

Çoklu nesne tespitinde bir başka seçenek, bölge önerisi kullanmayan YOLO ve SSD yöntemleridir (ekrandan, 02:10:00):

- Girdi $3\times H\times W$ boyutlu görüntüdür.
- Görüntü $7\times7$'lik bir ızgaraya bölünür.
- Her ızgara hücresinin merkezine bir temel kutular (base boxes) kümesi yerleştirilir; örnekte $B = 3$.
- Her hücrede, $B$ temel kutunun her birinden 5 sayıyla son kutuya regresyon yapılır: $(dx, dy, dh, dw, \text{güven})$.
- Her hücre için $C$ sınıfın (arka plan da bir sınıf olarak) skorları tahmin edilir.
- Çıktı: $7\times7\times(5B + C)$.

> **Ders sonrası not:** Hoca YOLO ve SSD'den "YOLO SSD" diye tek bir yöntem gibi söz etti. Slayt başlığı "YOLO / SSD"dir ve bunlar iki ayrı yöntemdir: YOLO (Redmon ve ark., CVPR 2016) ve SSD (Liu ve ark., ECCV 2016) (ekrandan, 02:10:00).

Hoca, tespit yöntemlerinin başarısının çalışılan alana göre değiştiğini, bu yüzden birkaç yöntemi karşılaştırmalı denemekte fayda olduğunu söyledi.

### 14.7 EfficientNet

Alan çok hızlı gelişmektedir. Yeni ağlardan biri EfficientNet'tir. Hocanın aktardığına göre burada dinamik bir mimari tasarlanır: ağın derinliği, genişliği ve çözünürlüğü değiştirilerek en uygun çözüm aranır.

> **Ek bilgi (derste anlatılmadı):** EfficientNet (Tan ve Le, 2019) büyük olasılıkla temelde bir görüntü sınıflama omurgasıdır; derinlik, genişlik ve çözünürlüğü tek bir bileşik katsayıyla birlikte ölçekler (compound scaling). Nesne tespiti için bu omurgayı kullanan sürümü EfficientDet adını taşır.

## 15. Terimlerin Türkçe Karşılıkları

Dersin sonunda bir öğrenci, raporda sık karşılaştığı terimlerin Türkçe karşılıklarını nereden bulabileceğini sordu. Konuşulan karşılıklar:

| İngilizce | Türkçe |
|---|---|
| segmentation | bölütleme (segmentasyon da yerleşmiş durumda) |
| semantic | anlamsal |
| classification | sınıflama |
| clustering | kümeleme (öbekleme, topaklama da kullanılıyor) |
| parity bit | eşlenik biti |

Hoca, bilgisayar bilimleri için hazırlanmış Türkçe terim sözlüklerinin aranabileceğini söyledi; bir öğrenci de yapay zeka terimlerini Türkçeleştirmeye yönelik bir topluluk çalışmasının bağlantısını paylaştı. Hoca, aynı kavram için birden çok Türkçe kelime türetildiği ve bunun karışıklık yarattığı için genelde İngilizce terimleri kullandığını, ama Türkçe bir bildiri yazarken karşılık bulmak gerektiğini belirtti.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00; 00:45:00). Üç eğitim örneği (kedi, araba, kurbağa) ve üç sınıf (cat, car, frog) için skorlar aşağıdaki gibidir. Her örneğin SVM kaybını ve toplam kaybı hesaplayın.

| Sınıf | Kedi | Araba | Kurbağa |
|---|---|---|---|
| cat | 3.2 | 1.3 | 2.2 |
| car | 5.1 | 4.9 | 2.5 |
| frog | -1.7 | 2.0 | -3.1 |

> **Çözüm (derste verildi):** $L_i = \sum_{j\ne y_i}\max(0, s_j - s_{y_i} + 1)$.
> Kedi: $\max(0, 5.1 - 3.2 + 1) + \max(0, -1.7 - 3.2 + 1) = 2.9 + 0 = 2.9$.
> Araba: $\max(0, 1.3 - 4.9 + 1) + \max(0, 2.0 - 4.9 + 1) = 0 + 0 = 0$.
> Kurbağa: $\max(0, 2.2 + 3.1 + 1) + \max(0, 2.5 + 3.1 + 1) = 6.3 + 6.6 = 12.9$ (slayttaki 10.9 yanlıştır; hoca öğrencilerin bu hatayı bulmasını istedi).
> Toplam kayıp: $L = (2.9 + 0 + 12.9)/3 \approx 5.27$ (ortalama derste sayısal olarak söylenmedi; python ile hesaplandı).

**Soru 2** (derste sözlü, 00:58:54). Eğitim doğruluğu iterasyonla artarken doğrulama doğruluğu aynı paralelde artmıyor ve aradaki açıklık büyüyor. Bunun nedeni nedir?

> **Cevap (derste verildi):** Aşırı öğrenme (overfitting). Model eğitim verisini ezberliyor. Çözüm olarak düzenlileştirme yöntemleri (düzenlileştirme terimi, dropout, veri artırma) kullanılır.

**Soru 3** (derste sözlü, 01:27:09). Dropout kodundaki `np.random.rand(*H1.shape)` ifadesinde `H1.shape`'in önündeki yıldız ne anlama gelir?

> **Çözüm (derste verilmedi):** Yıldız Python'un argüman açma (argument unpacking) işlecidir; işaretçiyle ilgisi yoktur. `H1.shape` bir demettir (tuple), örneğin `(4, 5)`. `np.random.rand` boyutları ayrı ayrı argümanlar olarak bekler: `np.random.rand(4, 5)`. `np.random.rand(*H1.shape)` çağrısı demeti açarak `np.random.rand(4, 5)` çağrısına dönüşür ve `H1` ile aynı biçimde bir dizi üretir. Yıldız olmadan `np.random.rand((4, 5))` yazılırsa hata verir (python ile denendi: `TypeError`). Aynı işi `np.random.random(H1.shape)` da yapar.

**Soru 4** (derste sözlü, 01:27:49). Dropout işlemi eğitimden önce mi, yoksa bütün ağırlıklar güncellendikten sonra mı uygulanır?

> **Cevap (derste verildi):** Her eğitim adımının (`train_step`) içinde, ileri geçiş sırasında bir kez uygulanır. Her adımda yeni bir rastgele maske üretilir. Testte dropout uygulanmaz; aktivasyonlar $p$ ile ölçeklenir.

## Dersin Toparlaması

Bu derste derin öğrenme modelinin nasıl eğitildiği adım adım ele alındı. Doğrusal skor fonksiyonu $f(x,W) = Wx + b$ ile her sınıf için bir skor üretiliyor; çok sınıflı SVM kaybı, doğru sınıfın skorunun öbür sınıfların skorlarından en az 1 fazla olmasını istiyor ve bu koşul sağlanmadığında kayıp üretiyor. Kayıp, parametrelere göre türev alınarak stokastik gradyan inişi ve onun momentum, Adam gibi geliştirilmiş biçimleriyle en küçükleniyor. Eğitim ve doğrulama doğruluğu arasındaki açıklık aşırı öğrenmeyi gösteriyor; buna karşı kayba L2/L1 düzenlileştirme terimi eklemek, dropout ve veri artırma kullanılıyor. Az veri varsa ImageNet'te eğitilmiş bir modelin katmanları dondurulup yalnız son katmanları eğitilerek transfer öğrenme yapılıyor.

Dersin son bölümünde sınıflamanın ötesindeki görme görevlerine geçildi: anlamsal bölütleme, sınıflama ve konumlandırma, nesne tespiti ve örnek bölütleme. Konumlandırmanın sınıflama ile kutu regresyonunun birleşimi olduğu, nesne tespitinin R-CNN'den Fast R-CNN ve Faster R-CNN'e doğru, paylaşılan öznitelik haritası ve ağ içi bölge önerisiyle hızlandığı, YOLO ve SSD'nin ise öneri adımı olmadan ızgara tabanlı doğrudan regresyon yaptığı görüldü. Konuyu daha ayrıntılı öğrenmek isteyenlere Stanford CS231n dersinin videoları, slaytları ve ödevleri önerildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
