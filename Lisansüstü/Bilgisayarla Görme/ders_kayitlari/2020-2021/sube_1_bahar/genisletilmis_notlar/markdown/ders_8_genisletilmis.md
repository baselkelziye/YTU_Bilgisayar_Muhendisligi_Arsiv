# Ders 8 Genişletilmiş Notu: Evrişimli Sinir Ağları, Havuzlama, Aktivasyon Fonksiyonları, Softmax ve CNN Mimarileri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Derin Öğrenmede Kullanılan Veri Kümeleri: CIFAR-10 ve MNIST
- 3. Veri Kümelerinin Python ile Okunması
- 4. Evrişim Katmanına Dönüş
- 5. Evrişim İşleminin Elle Hesaplanması
- 6. Renkli Görüntüde Evrişim
- 7. Ardışık Evrişim Katmanları ve Öznitelik Düzeyleri
- 8. Çıktı Boyutu Formülü
- 9. Sıfır Dolgu (Zero Padding)
- 10. Evrişim Katmanının Parametre Sayısı
- 11. Evrişim Katmanının Genel Özeti
- 12. 1×1 Evrişim ve Öznitelik Hiyerarşisi
- 13. Öznitelik Çıkarımından Sınıflandırmaya
- 14. Maksimum Havuzlama (Max Pooling)
- 15. Aktivasyon Fonksiyonları
- 16. Düzleştirme ve Tam Bağlantılı Katman
- 17. Yapay Sinir Ağına Giriş ve Eğitimin Akışı
- 18. Tek İleri Geçiş Örneği
- 19. Softmax Çıkışı
- 20. CNN Mimarileri ve ImageNet Yarışması
- 21. Keras ile MNIST Sınıflandırma Örneği
- Örnek Sorular

## 1. Dersin Planı

Bu derste derin öğrenmeyle iş yapmaya başlanır. Ders hem slaytlar hem de Jupyter defteri üzerinden paralel yürütülür; hesaplar tablet üzerinde elle çizilerek gösterilir. Konu sırası şöyledir: önce derin öğrenmenin "ABC'sinde" kullanılan iki veri kümesi (CIFAR-10 ve MNIST) tanıtılır, sonra önceki hafta başlanan evrişim katmanı (convolution layer) ayrıntılı işlenir. Ardından evrişimli sinir ağlarında (Convolutional Neural Network, CNN) sıkça kullanılan maksimum havuzlama (max pooling), aktivasyon fonksiyonları ve softmax çıkış katmanı anlatılır. Ders, bilinen CNN mimarilerinin (AlexNet, VGGNet, GoogLeNet, ResNet) tanıtımı ve Keras ile küçük bir örnekle biter. Eniyileme (optimization), düzenlileştirme (regularization) ve dropout gibi ince ayar konuları sonraki derse bırakılır.

Slaytların büyük kısmı Stanford Üniversitesi'nin CS231n dersinden (evrişimli sinir ağlarıyla görsel tanıma) yararlanılarak hazırlanmıştır (ekrandan, 01:00:00). Hoca, konuyu daha ayrıntılı öğrenmek isteyenlere bu dersin YouTube'daki video kayıtlarını ve ders notlarını önerdi; kayıtlar 2017 tarihli olduğu için biraz eski olsa da temel kavramlar için çok iyi bir kaynaktır.

## 2. Derin Öğrenmede Kullanılan Veri Kümeleri: CIFAR-10 ve MNIST

Uygulamaların çoğunda bu iki veri kümesiyle karşılaşılır. Bu yüzden hangi veri kümesinin ne olduğu, kaç sınıfı olduğu ve kaç örnek içerdiği hakkında fikir sahibi olmak gerekir.

### 2.1 CIFAR-10

CIFAR-10 çok yaygın kullanılan, kolay iş yapılabilen ve genelde küçük denemeler için seçilen bir veri kümesidir. Adındaki 10, sınıf sayısıdır; on sınıf on ayrı etiket (label) demektir. Veri kümesinde 50 000 eğitim ve 10 000 test örneği vardır. Her görüntü $32 \times 32 \times 3$ boyutundadır: $32 \times 32$ kare bir görüntü ve renkli olduğu için üç renk kanalı (RGB). Basit testler için kullanılan çok temel bir veri kümesidir.

### 2.2 MNIST

Programlamaya yeni başlayan biri ekrana "hello world" yazdırarak başlar; makine öğrenmesinin "hello world"ü de MNIST'tir. Adı Modified National Institute of Standards and Technology database'den gelir (ekrandan, 00:15:00). Veriler, ABD'de nüfus idaresine (Census Bureau) verilen formlardaki el yazısı rakamlardan toplanmıştır: insanlar formdaki kutucuklara örneğin kimlik numaralarını yazar. İnsanların rakam yazma biçimleri çok farklı olduğu için aynı rakamın pek çok farklı görünümü vardır; slaytta 5, 0, 4 ve 1 rakamlarının el yazısı örnekleri gösterilir.

MNIST görüntüleri gri seviyelidir (grayscale); RGB renk kanalı yoktur. Her görüntü $28 \times 28$ boyutlu bir matristir ve bu matris görüntünün öznitelikleri (features) olarak kullanılabilir. Bütün eğitim kümesi üç boyutlu bir matriste tutulabilir. İstenirse her görüntü düzleştirilir (flatten): birinci satırdaki parlaklık değerlerinin arkasına ikinci satırdakiler eklenir ve böyle devam edilerek iki boyutlu matris bir boyutlu vektöre çevrilir. $28 \times 28$ bir görüntüden $28 \cdot 28 = 784$ uzunluklu bir vektör elde edilir (ekrandan, 00:15:00).

> **Ders sonrası not:** Hoca önce eğitim örneği sayısını 55 bin diye okudu, ardından kendisi düzeltti: MNIST'in Keras sürümünde 60 000 eğitim ve 10 000 test örneği vardır.

## 3. Veri Kümelerinin Python ile Okunması

### 3.1 MNIST

MNIST veri kümesi TensorFlow içinde, Keras'ın altında hazır olarak bulunur. `import tensorflow` ile kütüphane yüklendikten sonra veri şöyle okunur ve eğitim-test kümeleri baştan ayrılmış olarak gelir (ekrandan, 00:20:00):

```python
import numpy as np
import matplotlib.pyplot as plt
%matplotlib inline

(x_train, y_train), (x_test, y_test) = mnist.load_data()

print('X_train:', x_train.shape)
print('y_train:', y_train.shape)
print('X_test:', x_test.shape)
print('y_test:', y_test.shape)

img = x_train[25000, :, :]
plt.imshow(img, cmap='gray')
print(y_train[25000])
print(img.shape)
print(img.max(), img.min())
```

Çıktı şöyledir (ekrandan, 00:20:00):

```text
X_train: (60000, 28, 28)
y_train: (60000,)
X_test: (10000, 28, 28)
y_test: (10000,)
3
(28, 28)
254 0
```

Burada `x_train`, 60 000 tane $28 \times 28$ matrisi tutan üç boyutlu bir yapıdır. `y_train` ise 60 000 uzunluklu bir vektördür; her gözünde ilgili örneğin sınıf etiketi (0-9 arasında hangi rakam olduğu) bulunur. `x_test` $10000 \times 28 \times 28$, `y_test` 10 000 uzunlukludur.

Örnek olarak 25 000. eğitim örneği seçilip `imshow` ile gösterildiğinde el yazısıyla bir 3 rakamı görünür ve `y_train[25000]` değeri 3'tür. Görüntü $28 \times 28$'dir; en büyük parlaklık 254, en küçük 0'dır. 30 000. örnek de 3 çıkar ama farklı biçimde yazılmıştır. Bir sonraki örnekte ise ortası çizilmeden yazılmış bir 7 görülür; bu 7 bire de benzer. El yazısı olduğu için tanıma aslında zordur.

Defterdeki bir not, her kullanımdan sonra belleğin temizlenmesini önerir: `x_train`, `y_train`, `x_test`, `y_test` matrisleri (özellikle `x_train`) çok büyüktür ve yeni bir veri kümesi yüklenecekse bunları silmek belleği boş yere işgal etmemelerini sağlar.

### 3.2 CIFAR-10

CIFAR-10 da 10 sınıflı ve renklidir. Derste bu veri kümesi elle bir klasöre konup okundu (hoca bunun hazır gelmediğini hatırladığını söyledi) (ekrandan, 00:25:00):

```python
X_train, y_train, X_test, y_test = load_CIFAR10(cifar10_dir)

# As a sanity check, we print out the size of the training and test data.
print('Training data shape: ', X_train.shape)
print('Training labels shape: ', y_train.shape)
print('Test data shape: ', X_test.shape)
print('Test labels shape: ', y_test.shape)
```

Çıktı: eğitim verisi `(50000, 32, 32, 3)`, eğitim etiketleri `(50000,)`, test verisi `(10000, 32, 32, 3)`, test etiketleri `(10000,)`.

Ardından rastgele seçilen 2000. eğitim örneğinin bütün satırları, sütunları ve renk kanalları `img = X_train[2000,:,:,:]` ile okunur, boyutu `(32, 32, 3)` olarak yazdırılır ve `plt.imshow(img.astype(np.uint8))` ile gösterilir. `y_train[2000]` değeri 7'dir. Büyütülmüş, mozaikli görünen görüntüde bir at vardır. Sınıf listesi uçaktan (airplane) başlayarak 0, 1, ..., 7 diye sayıldığında 7 numaralı sınıfın at (horse) olduğu görülür.

## 4. Evrişim Katmanına Dönüş

Evrişim işlemleri dersin ilk haftalarından beri anlatılıyor; burada derin öğrenme başlığı altında yeniden ele alınır. Evrişim katmanı, verilen görüntüden öznitelik (feature) çıkarmak için kullanılır.

Bir CIFAR görüntüsünü, yani $32 \times 32 \times 3$ bir girdi matrisini düşünelim. Amaç bu matrise art arda farklı evrişim filtreleri uygulayarak öznitelik çıkarmaktır. İlk aşamada $5 \times 5 \times 3$ boyutlu bir filtre seçildiğini varsayalım (ekrandan, 00:30:00).

Dolgu (padding) yapılmazsa, $5 \times 5$ filtre görüntünün köşesine oturtulduğunda yalnız filtrenin merkezine karşılık gelen piksel için çıktı üretilebilir. Bu yüzden üstten, alttan, soldan ve sağdan ikişer piksel kaybolur; her boyutta toplam 4 piksel kayıp olur ve $32 \times 32$ olan boyut $28 \times 28$'e düşer. Filtre $5 \times 5 \times 3$ olduğu, yani girdinin bütün derinliğini kapsadığı için tek filtrenin çıktısının derinliği 1'dir: $28 \times 28 \times 1$ bir aktivasyon haritası (activation map) oluşur.

6 tane $5 \times 5$ filtre uygulanırsa 6 ayrı aktivasyon haritası elde edilir. Bunlar üst üste konunca $28 \times 28 \times 6$ boyutlu yeni bir "görüntü" oluşur (ekrandan, 00:30:00). Buradaki 6 kullanılan filtre sayısından (number of filters) gelir: çıktının derinliğini filtre sayısı belirler.

## 5. Evrişim İşleminin Elle Hesaplanması

### 5.1 Filtreler ve görüntü

Önceki haftadan hatırlanan slaytta farklı katsayılı iki filtre vardır (ekrandan, 00:40:00):

```text
Filtre 1            Filtre 2
 1  -1  -1          -1   1  -1
-1   1  -1          -1   1  -1
-1  -1   1          -1   1  -1
```

Filtre 1'in ana köşegeni 1, diğer gözleri $-1$'dir; görüntüde sol üstten sağ alta inen köşegen bir çizgi varsa onu yakalar. Filtre 2'nin orta sütunu 1'dir; dikey doğrultudaki çizgilerin olduğu bölgede baskın (büyük) bir sonuç üretir. Filtrenin katsayıları aslında görüntüde ne aradığımızı gösterir.

Girdi $6 \times 6$ boyutlu ikili bir görüntüdür (ekrandan, 00:35:00):

```text
1 0 0 0 0 1
0 1 0 0 1 0
0 0 1 1 0 0
1 0 0 0 1 0
0 1 0 0 1 0
0 0 1 0 1 0
```

### 5.2 Stride 1 ile evrişim

İşlem $I * F_1$ diye yazılır; yıldız genelde evrişim işlemi için kullanılır. Kaydırma adımı (stride) 1'dir, yani filtre görüntü üzerinde her seferinde bir piksel kaydırılır.

Filtre katsayı matrisi görüntünün sol üst köşesine oturtulur. Filtre katsayıları görüntüdeki parlaklık (intensity) değerleriyle tek tek çarpılır; dokuz çarpımın toplamı, merkez noktası için çıktıyı verir. Sol üst $3 \times 3$ bölgede yalnız ana köşegende 1 vardır, diğer gözler 0'dır. Filtrenin köşegeni de 1 olduğundan toplam $1+1+1 = 3$ olur. Sonra filtre bir piksel sağa kaydırılır ve aynı işlem tekrarlanır; çıktı sağ taraftaki matrise yazılır.

Bütün konumlar için hesaplanınca $4 \times 4$ çıktı elde edilir (sonuçlar python ile doğrulandı):

```text
Filtre 1, stride 1        Filtre 2, stride 1
 3  -1  -3  -1            -1  -1  -1  -1
-3   1   0  -3            -1  -1  -2   1
-3  -3   0   1            -1  -1  -2   1
 3  -2  -2  -1            -1   0  -4   3
```

Filtre 1 iki gözde en büyük değeri (3) üretir. Bunlar görüntüde köşegen çizgilerin bulunduğu iki bölgedir. Filtre 2'nin çıktısı da benzer biçimde dikey çizgilerin olduğu yerde büyük değer verir. Bu çıktıya öznitelik haritası (feature map) denir: sistem öznitelikleri otomatik olarak üretmiş olur.

> **Hocanın vurgusu:** Bu işlemi elle yapabilmek gerekir. Sınavda küçük görüntü matrisleri verilebilir; içinde yalnız 0 ve 1 değil, 0-255 arasında parlaklık değerleri olacaktır. Verilen stride ile evrişim çıktısını buradaki gibi oluşturabilmek beklenir.

### 5.3 Stride 2 ile evrişim

Stride 2 alındığında pencere her adımda iki piksel kaydırılır (ekrandan, 00:35:00). İlk pencere sol üst köşedir ve sonuç yine 3'tür. İkinci pencere iki piksel sağdadır (sütun 3-5); bu bölgede üç gözde 1 vardır ve üçü de filtrenin $-1$ katsayılarıyla çarpılır, bu yüzden sonuç $-3$ olur. Bir piksel atlanarak çıktı üretildiği için stride, çıktı görüntüsünü küçültmek için de kullanılan bir parametredir.

Kaydırma yalnız soldan sağa değil, yukarıdan aşağıya ilerlerken de uygulanır: bir satır bitince pencere iki satır aşağı kaydırılır. $6 \times 6$ görüntüde Filtre 1 ile stride 2 sonucu $\begin{bmatrix} 3 & -3 \\ -3 & 0 \end{bmatrix}$ olur (ara adım eklendi; python ile hesaplandı).

## 6. Renkli Görüntüde Evrişim

**Soru:** Bu örneklerde tek kanallı bir filtre geçirdik; renkli görüntüde filtre üç boyutlu oluyor. O zaman aynı derinlikteki değerleri toplayıp tekrar tek boyutlu hale mi getiriyoruz? **Cevap:** Tek kanallı durumda filtre görüntüye oturtulup 9 çarpma yapılıyordu. Derinlik de varsa $3 \times 9 = 27$ çarpma yapılır ve 27 çarpımın toplamı tek bir çıktı verir. Renkli görüntünün boyutu $6 \times 6 \times 3$'tür; son boyut renk kanalını (color channel) gösterir. Böyle bir uygulamada filtre de $3 \times 3 \times 3$ olur ve çarpmalar derinlik boyunca bütün katmanlarda yapılır.

Slaytta da renkli görüntü için kırmızı, yeşil ve mavi kanallara karşılık filtrelerin derinlik kazandığı, yani $3 \times 3 \times 3$ olduğu gösterilir (ekrandan, 00:40:00).

Hoca ardından şu soruyu sordu: $6 \times 6 \times 3$ bir görüntü Filtre 1 ($3 \times 3 \times 3$) ile, dolgu yapılmadan ve stride 1 ile evrişime alınırsa çıktı boyutu ne olur? Bir öğrenci önce derinliği de taşıyarak cevap verdi. Doğru cevap $4 \times 4 \times 1$'dir: filtre bütün derinliği çarpıp topladığı için derinlik "biter" ve tek filtreden tek kanallı bir çıktı oluşur.

## 7. Ardışık Evrişim Katmanları ve Öznitelik Düzeyleri

Derin sinir ağlarında görüntüye art arda evrişim işlemleri uygulanır: birinci evrişimin ürettiği çıktıya başka filtre katsayılarıyla yeniden evrişim uygulanır. Bu yöntem, kenar bulma (edge detection) ya da köşe bulma (corner detection) gibi algoritmalarla görülemeyecek kadar karmaşık özniteliklerin elde edilmesini sağlar.

Slayttaki akış şöyledir (ekrandan, 00:45:00):

- Girdi: $32 \times 32 \times 3$ (örneğin CIFAR görüntüsü).
- Evrişim + ReLU: 6 tane $5 \times 5 \times 3$ filtre, dolgu yok, stride 1. Her kenardan 2 piksel gider, çıktı $28 \times 28 \times 6$ olur. Bu katman alt düzey öznitelikleri (low level features) üretir.
- Evrişim + ReLU: 10 tane $5 \times 5 \times 6$ filtre. Filtrenin derinliği 6'dır, çünkü girdinin derinliği 6'dır. Boyut yine 4 küçülür: $28 \to 24$; derinlik filtre sayısı kadar, yani 10 olur. $24 \times 24 \times 10$ matris orta düzey öznitelikleri (mid-level features) tutar.
- Daha ileri evrişim katmanları üst düzey, daha karmaşık öznitelikler (high level features) oluşturur.

ReLU (Rectified Linear Unit) bir aktivasyon fonksiyonudur ve aşağıda anlatılır. Derin ağ kavramı buradan gelir: art arda uygulanan her işlem bir katmandır (layer) ve katman sayısı ne kadar çoksa ağ o kadar derindir.

## 8. Çıktı Boyutu Formülü

Girdi boyutu, stride ve filtre boyutu verildiğinde çıktı boyutu bir formülle hemen bulunabilmelidir. Girdi görüntüsü $N \times N$, filtre $F \times F$ olsun. Örnek: $N = 7$, $F = 3$ (ekrandan, 00:50:00).

- Stride 1: $3 \times 3$ filtre her kenardan 1 piksel küçültür; çıktı $5 \times 5$'tir. Formülle $\dfrac{7-3}{1} + 1 = 5$.
- Stride 2: pencere her seferinde iki piksel kayar; yatayda ve dikeyde üçer konum vardır, çıktı $3 \times 3$'tür. Formülle $\dfrac{7-3}{2} + 1 = 3$.
- Stride 3: $\dfrac{7-3}{3} + 1 = 2{,}33$. Sonuç tam sayı değildir; slayttaki ifadeyle "uymaz" (does not fit). Bu, filtrenin görüntü üzerinde tam adımlarla kaydırılamayacağı anlamına gelir.

Genel formül:

$$\text{Çıktı boyutu} = \frac{N - F}{S} + 1$$

Buradaki $+1$'in nedeni şudur: filtre boyutları hep tek sayıdır; $N - F$ ile sağdan ve soldan çıkarılan pikseller hesaplanırken merkez piksel de çıkarılmış olur, $+1$ onu geri ekler.

## 9. Sıfır Dolgu (Zero Padding)

Şimdiye kadar hiç kullanılmayan bir işlem sıfır dolgudur: giriş görüntüsünün çevresine sıfırlar eklenir. $7 \times 7$ görüntünün dışına bir sıra sıfır eklendiğinde ($P = 1$), $3 \times 3$ filtre görüntünün ilk gözünü merkez alacak biçimde oturtulabilir ve o göz için de çıktı üretilebilir. Böylece $7 \times 7$ girdi için yine $7 \times 7$, yani girdiyle aynı boyutta (same size) bir çıktı elde edilir.

**Soru (hoca):** Filtre $3 \times 3$ değil de $5 \times 5$ olsaydı, çıktının girdiyle aynı boyutta kalması için ne kadar dolgu gerekirdi? **Cevap:** 2.

Genel kural (stride 1 için): $F \times F$ filtre ve $\dfrac{F-1}{2}$ sıfır dolgu çıktı boyutunu korur. $F = 3$ ise bir piksellik, $F = 5$ ise soldan, sağdan, alttan, üstten ikişer sıra dolgu yeterlidir.

### 9.1 Alıştırma

Girdi hacmi $32 \times 32 \times 3$ (CIFAR-10 görüntüsü); 10 tane $5 \times 5 \times 3$ filtre, stride 1, dolgu 2 (ekrandan, 00:55:00). Çıktı hacmi ne olur?

Bir öğrenci önce dolguyu hesaba katmadan $28 \times 28 \times 10$ dedi. Dolgu 2 olduğu ve $F = 5$ için $(F-1)/2 = 2$ boyutu koruduğu için en ve boy değişmez: $\dfrac{32 - 5 + 2 \cdot 2}{1} + 1 = 32$. Derinliği filtre sayısı belirler, 10 olur. Sonuç $32 \times 32 \times 10$'dur.

> **Hocanın vurgusu:** Bu hesaplamalar basit ama yapıyı çözmek açısından çok önemli.

**Soru:** Stride'ın 2 olması neyi, nasıl değiştirirdi? **Cevap:** Buna adım adım gelinecek; aşağıdaki genel formülde stride paydada yer alır.

## 10. Evrişim Katmanının Parametre Sayısı

Aynı alıştırmada ikinci soru: bu katmandaki parametre sayısı nedir? (ekrandan, 00:55:00). Derin öğrenmede ağın karmaşıklığını gösteren şey parametre sayısıdır, bu yüzden hesaplanabilmelidir. Parametre, filtrenin gözlerinin alacağı değerlerdir.

Tek bir $5 \times 5 \times 3$ filtrenin $75$ parametresi vardır. Slaytta buna bir de sapma (bias) eklenir ve $76$ olur. 10 filtre olduğu için $10 \cdot 76 = 760$ parametre bulunur; bu yalnız bu evrişim katmanı içindir. Art arda beş evrişim katmanı varsa ve her birinde filtre boyutları farklıysa toplam parametre bunlara bağlı olarak hesaplanır.

> **Ders sonrası not:** Hoca sapmanın evrişim katmanında olmadığını bildiğini ama slaytta hesaba katıldığını söyledi. Standart evrişim katmanlarında her filtre için bir sapma terimi büyük olasılıkla bulunur; CS231n özetinde de $K$ filtre için $K$ sapma sayılır (ekrandan, 01:00:00).

## 11. Evrişim Katmanının Genel Özeti

CS231n'deki özet slayt bütün hesabı tek yerde toplar (ekrandan, 01:00:00):

- Girdi hacmi $W_1 \times H_1 \times D_1$ (genişlik, yükseklik, derinlik).
- Dört hiperparametre gerekir:
  - Filtre sayısı $K$,
  - Filtre boyutu (spatial extent) $F$,
  - Stride $S$,
  - Sıfır dolgu miktarı $P$.
- Çıktı hacmi $W_2 \times H_2 \times D_2$:
  - $W_2 = (W_1 - F + 2P)/S + 1$
  - $H_2 = (H_1 - F + 2P)/S + 1$ (genişlik ve yükseklik simetri gereği aynı hesaplanır)
  - $D_2 = K$
- Parametre paylaşımıyla filtre başına $F \cdot F \cdot D_1$ ağırlık, toplam $(F \cdot F \cdot D_1) \cdot K$ ağırlık ve $K$ sapma vardır.
- Çıktının $d$. derinlik dilimi, $d$. filtrenin girdi üzerinde stride $S$ ile geçerli (valid) evrişiminin sonucuna $d$. sapmanın eklenmesiyle elde edilir.

Önceki formül $\frac{N-F}{S}+1$'e yalnız $2P$ eklenmiştir: $\frac{N - F + 2P}{S} + 1$.

### 11.1 Formülün kontrolü

$5 \times 5$ filtre, $P = 2$, $S = 1$ ile çıktı boyutu değişmemelidir. $N = 7$ alalım: $7 - 5 = 2$; $2P = 4$ eklenince $6$; $6/1 + 1 = 7$. Çıktı yine $7 \times 7$'dir, beklendiği gibi aynı boyut (same size) korunur (ekrandan, 01:05:00). Derste hoca hesapta bir an takıldı, öğrencilerle birlikte adım adım yeniden yapınca sonucun 7 olduğu görüldü.

> **Hocanın vurgusu:** Bu hesaplama aklın bir kenarında kalmalı; çok pratiklik kazandırır.

## 12. 1×1 Evrişim ve Öznitelik Hiyerarşisi

### 12.1 Küçük filtreler ve 1×1 evrişim

Derin sinir ağlarında, özellikle yeni yapılarda, büyük filtreler yerine hep daha küçük filtreler seçilmiştir; $1 \times 1$ evrişim filtresi bile kullanılır. Artık girdi bir ara katman da olabilir: bir evrişimin çıktısı bir sonrakinin girdisidir. Örnek: $56 \times 56 \times 64$ girdi matrisine 32 tane $1 \times 1$ evrişim filtresi uygulanır. Filtre aslında $1 \times 1 \times 64$'tür. Çıktı $56 \times 56 \times 32$ olur, çünkü filtre sayısı 32'dir. Bazı çalışmalar, özellikle son yıllardakiler, küçük filtre boyutlarının daha iyi sonuç verdiğini öne sürer.

### 12.2 Elle öznitelik çıkarımından otomatik öğrenmeye

Evrişim işlemlerinin amacı öznitelik çıkarmaktır. Derin ağlar 2012 civarında kullanılmaya başlandı. O döneme kadar öznitelik çıkarma (feature extraction) elle yapılırdı: kenar bulunur, öznitelikler toplanır, köşe bulunur, öznitelikler toplanırdı. Derin sinir ağında ise giriş görüntüsü verilir ve sistem bütün öznitelikleri kendisi üretir.

Slaytta 16 katmanlı VGG ağının farklı katmanlarındaki filtre çıktıları gösterilir (ekrandan, 01:25:00):

- VGG-16 Conv1_1 (birinci paketin birinci katmanı): 64 filtrenin her biri farklı bir şeye odaklanır; biri dikey, biri yatay çizgilere, biri merkezde bir noktaya. İlk katman olduğu için bunlar alt düzey özniteliklerdir.
- VGG-16 Conv3_2 (üçüncü paketin ikinci katmanı): önceki katmanın çıktısını girdi olarak alır ve orta düzey öznitelikler üretir. Şekillerde karmaşa vardır: köşegen, yatay, dikey her türden yapı bir arada görünür.
- VGG-16 Conv5_3 (beşinci paketin üçüncü katmanı): bulunan çıktıların belirli bir yönelimi (orientation) yoktur; yatay ya da dikey çizgi değildir. Bunlar daha karmaşık, üst düzey özniteliklerdir.

Akış: görüntü → alt düzey öznitelikler → orta düzey öznitelikler → üst düzey öznitelikler → doğrusal olarak ayrılabilir sınıflandırıcı.

## 13. Öznitelik Çıkarımından Sınıflandırmaya

CNN'in görevi öznitelik çıkarmaktır. Örneğin 16 katmanın sonunda öznitelik çıkarımı tamamlanır; ardından sınıflandırma (classification) kısmı gelir. Bu kısımda gizli katman sayısı artırılarak yine derin bir yapı kurulabilir. Ya da elde edilen öznitelikler SVM gibi klasik makine öğrenmesi sınıflandırıcılarıyla kullanılabilir. Bu seçeneklerin hepsi denenir ve karşılaştırmalı sonuçlar yayımlanır.

**Soru:** Sınıflandırma kısmında SVM kullanılsa da yapı derin sinir ağı mı sayılır? **Cevap:** Evet. Öznitelik çıkarımında çok katmanlı bir CNN kullanıldığı için yapı derin sinir ağı olarak geçer. Sınıflandırıcı olarak farklı yöntemleri ve klasik tam bağlantılı katmanı deneyip karşılaştıran çalışmalar vardır.

Slayttaki örnek ağda girdiye 10 filtreli bir evrişim, ardından ReLU, tekrar evrişim, ReLU ve max pooling, sonra üçüncü, dördüncü, beşinci ve altıncı evrişim katmanları uygulanır. En sonda tam bağlantılı katman (fully connected layer) sınıflandırmayı yapar. Çıktı sınıf olasılıklarıdır: örneğin görüntünün araba olma olasılığı en yüksek, kamyon olma olasılığı bunun belki beşte biri, uçak olma olasılığı onda biri gibi.

## 14. Maksimum Havuzlama (Max Pooling)

Giriş görüntüsünün tamamında $3 \times 3$ ya da $5 \times 5$ bir filtreyi gezdirmek, yani evrişim almak oldukça maliyetlidir. Bu yüzden girdiyi olabildiğince küçültmeye çalışırız; stride parametresinin görevi de budur (stride 2 alındığında çıktı yarı yarıya küçülür). Max pooling'in görevi de görüntüyü küçültmektir. Slayttaki ifadeyle gösterimi daha küçük ve daha kolay yönetilir hale getirir; her aktivasyon haritası üzerinde bağımsız çalışır (ekrandan, 01:30:00).

Max pooling genelde $2 \times 2$ pencere ve stride 2 ile kullanılır. $4 \times 4$ evrişim çıktısının üzerine $2 \times 2$ bir pencere oturtulur, penceredeki dört gözün en büyüğü alınıp çıktıya taşınır. Sonra pencere iki piksel sağa, satır bitince iki piksel aşağı kaydırılır. Böylece $4 \times 4$ harita $2 \times 2$'ye iner; en ve boy yarıya düşer.

Önceki bölümdeki evrişim çıktılarına uygulanınca (ekrandan, 01:30:00; python ile hesaplandı):

```text
Filtre 1 çıktısı      Max pool        Filtre 2 çıktısı      Max pool
 3  -1 | -3  -1                       -1  -1 | -1  -1
-3   1 |  0  -3       3   0           -1  -1 | -2   1      -1   1
-------+-------                       -------+-------
-3  -3 |  0   1       3   1           -1  -1 | -2   1       0   3
 3  -2 | -2  -1                       -1   0 | -4   3
```

**Soru:** Min pooling de var mı, yani minimumları almak? **Cevap:** Hoca görmediğini söyledi. Burada maksimum önemlidir; kenar bulmada da türevin maksimumu alınıyordu, mantık benzerdir.

Max pooling'in amacı, nesneyi değiştirmeden pikselleri alt örneklemektir (subsampling). Genelde bir evrişim katmanının arkasından uygulanır. Pencere boyutu ve stride ($2 \times 2$, stride 2) değiştirilebilir. Basit bir işlemdir ve öğrenilen parametresi yoktur.

## 15. Aktivasyon Fonksiyonları

Yapay sinir ağlarında çıktı üretilirken girdi ağırlıklarla (weights) çarpılır, sonra bu çıktı bir aktivasyon fonksiyonundan geçirilir. Klasik yapay sinir ağlarında yaygın aktivasyon fonksiyonları sigmoid ve hiperbolik tanjanttır. Derin öğrenmeyle bunlara ReLU eklenmiştir. Slaytta ayrıca Leaky ReLU $\max(0{,}1x, x)$, Maxout $\max(w_1^T x + b_1, w_2^T x + b_2)$ ve ELU ($x \geq 0$ için $x$, $x < 0$ için $\alpha(e^x - 1)$) da listelenir (ekrandan, 01:35:00).

### 15.1 Sigmoid

$$\sigma(x) = \frac{1}{1 + e^{-x}}$$

Yatay eksen girdiyi, dikey eksen aktivasyon sonucunu gösterir. Girdi herhangi bir gerçel sayı olabilir: $-6$ ile $+6$ arasında ya da $-1000$ ile $+1000$ arasında. Amaç bu girdiyi $(0, 1)$ aralığına sıkıştırmaktır. Sigmoid $0$'ı $0{,}5$'e götürür; belli bir seviyenin altındaki negatif değerleri sıfıra, belli bir seviyenin üstündekileri bire kilitler. Slayttaki ifadeyle gerçel değerli bir sayıyı alır ve $0$ ile $1$ arasına sıkıştırır (squash). Bunu bir tür normalleştirme gibi düşünebiliriz: ağdaki her düğümün ürettiği $-\infty$ ile $+\infty$ arasındaki çıktı $0$-$1$ arasına çekilir.

Dezavantajı doymadır (saturation): değer ya bire kilitlenir ya da sıfıra indirilip "öldürülür" (kill). Bu yüzden sigmoid bu açıdan kötü bir aktivasyon fonksiyonu olarak değerlendirilir.

> **Ek bilgi (derste anlatılmadı):** Doyma bölgelerinde sigmoidin türevi sıfıra çok yakındır. Geri yayılımda gradyanlar bu türevlerle çarpıldığı için katmanlar boyunca küçülür ve erken katmanların ağırlıkları neredeyse güncellenmez. Bu soruna kaybolan gradyan (vanishing gradient) denir.

### 15.2 Hiperbolik tanjant

$\tanh(x)$ girdiyi $(-1, 1)$ aralığına sıkıştırır. $0$'ı yine orta noktaya, yani $0$'a götürür; negatif değerleri sonunda $-1$'e, pozitif değerleri $+1$'e götürür. Sigmoidde görülen sorunun benzeri burada da vardır.

### 15.3 ReLU

$$f(x) = \begin{cases} 0, & x < 0 \\ x, & x \geq 0 \end{cases} \qquad \text{yani} \qquad f(x) = \max(0, x)$$

Girdi sıfırdan küçükse çıktı sıfıra kilitlenir; sıfırdan büyükse çıktı girdinin kendisidir: 2 ise 2, 4 ise 4, 1000 ise 1000. "Doğrusal" (linear) adı pozitif bölgedeki bu davranıştan gelir. Slayttaki ifadeyle gerçel değerli sayıyı alır ve sıfırda eşikler (ekrandan, 01:40:00). Slayta göre günümüzde çoğu derin ağ ReLU kullanır; çok daha hızlı eğitir (doğrusal, doymayan biçimi nedeniyle stokastik gradyan inişinin yakınsamasını hızlandırır) ve sigmoid ya da tanh'a göre daha ucuz işlemler gerektirir.

> **Hocanın vurgusu:** Çok sayıda örnek ve güçlü makineler yeni teknolojinin sunduğu nimetlerdir. Ama çok sayıda katman ve bu katmanların arasına yerleştirilen ReLU, derin ağların bu kadar yüksek başarı göstermesinin en önemli anahtarı olarak gösterilir.

## 16. Düzleştirme ve Tam Bağlantılı Katman

### 16.1 Düzleştirme (flattening)

"Flat" düz demektir; düzleştirme bir matrisi vektöre dönüştürmektir. Öznitelik çıkarımı bittiğinde elde edilen iki ya da üç boyutlu öznitelik matrisi tek boyutlu bir vektöre çevrilmelidir. Slayttaki örnekte üç boyutlu bir yapının arkadaki $2 \times 2$ dilimi ile öndeki $2 \times 2$ dilimi sırayla art arda dizilerek bir boyutlu vektör elde edilir. <!-- BELİRSİZ: düzleştirme örneğindeki değerlerin tam sırası karede görülmedi; altyazıda "-1, 1, 0, 3" gibi değerler okunuyor -->

### 16.2 Tam bağlantılı katman

Evrişim katmanlarının sonunda örneğin $32 \times 32 \times 3$ bir çıktı olduğunu varsayalım. Düzleştirilince $3072 \times 1$ vektör olur (ekrandan, 01:45:00). Bu 3072 düğümün her biri belli ağırlıklarla çarpılarak çıkıştaki her düğüme bağlanır; slayttaki çıkışta 10 düğüm vardır. Bu tek katmanda gizli katman gösterilmemiştir, ama işin nasıl yapıldığını görmek için yeterlidir.

İşlem $W x$ çarpımıdır. $W$ ağırlık matrisi $10 \times 3072$ boyutundadır: 10 satır, her satırda 3072 eleman. $x$ vektörünün devriği (transpozu) $3072 \times 1$ bir sütun vektörüdür. $W$'nin birinci satırı $x$ ile çarpılınca birinci çıktı, ikinci satırı ile çarpılınca ikinci çıktı üretilir; böylece $10 \times 1$ bir çıktı elde edilir. Bu 10 değer, CIFAR-10'daki her bir sınıfı gösterebilir. Slayttaki gösterim $W_{(10 \times 3072)} \cdot x_{(1 \times 3072)} = \text{Activation}_{(1 \times 10)}$ biçimindedir. Tam bağlantılı katman, sıradan sinir ağlarındaki gibi bütün girdi hacmine bağlanan nöronlar içerir. Tam bağlantılı katmanda yapılan işlem $Wx$ çarpımı ve ardından çıkışa uygulanan aktivasyondur.

## 17. Yapay Sinir Ağına Giriş ve Eğitimin Akışı

### 17.1 Ağın yapısı ve parametre sayısı

Slayttaki ağda $x$ girdi katmanı, $h$ gizli katman (hidden layer) ve $y$ çıkış katmanıdır (ekrandan, 01:50:00). Girdi katmanında 3, gizli katmanda 4, çıkış katmanında 2 nöron vardır. Girdi katmanının boyutu öznitelik vektörünün boyutu kadar olmalıdır; burada öznitelik vektörü 3 öznitelikten oluşur.

$$h = \sigma(W_1 x + b_1), \qquad y = \sigma(W_2 h + b_2)$$

$W_1$ ağırlık matrisi $x$ ile çarpılır, $b_1$ sapması eklenir, sonuca aktivasyon fonksiyonu uygulanarak gizli katmanın çıktısı $h$ bulunur. Sonra $h$, $W_2$ ile çarpılır, ayrı bir parametre olan $b_2$ eklenir ve aktivasyondan geçirilerek $y_1, y_2$ çıktıları üretilir. Veri kümeleri tanıtılırken kullanılan `x_train`, `y_train` adlandırması da buradan gelir: $x$ öznitelik vektörünü ya da girdi görüntüsünü, $y$ etiketi gösterir.

Öğrenilebilir parametre sayısı (ekrandan, 01:50:00):

- Nöron sayısı (girdiler sayılmaz): $4 + 2 = 6$.
- Ağırlıklar: $W_1$ aslında $4 \times 3$'tür (slaytta $3 \times 4$ yazılmıştır), $12$ ağırlık; $W_2$ $2 \times 4$'tür, $8$ ağırlık. Toplam $[3 \times 4] + [4 \times 2] = 20$.
- Sapmalar: her nöron için bir tane, $4 + 2 = 6$.
- Toplam: $20 + 6 = 26$ öğrenilebilir parametre.

### 17.2 Eğitim nasıl yapılır?

Ayrıntılar sonraki derse bırakıldı, burada yalnız akış görüldü. MNIST ve CIFAR'da çok sayıda eğitim örneği vardır; hepsi birden kullanılmaz, eğitim kümesinin bir alt kümesi (batch) alınır. Bu etiketli alt küme ağdan ileri geçirilir ve tahminler ($y_1, y_2$) hesaplanır. Ardından bilinen gerçek değer (ground truth) ile elde edilen çıktılar arasındaki farktan hata hesaplanır. Hata geri yayılım (backpropagation) yöntemiyle geriye yayılarak ağırlıklar güncellenir.

Güncellemede bir maliyet fonksiyonu (cost function, objective function) vardır; kayıp fonksiyonu (loss function) ise en aza indirilmeye çalışılır. Bu bir eniyileme problemidir. Slaytta gradyan iniş (gradient descent) yöntemi gösterilir: önceki ağırlıkların türevi öğrenme hızı (learning rate) parametresiyle çarpılıp eski ağırlıklardan çıkarılır ve yeni ağırlıklar $\theta_{yeni}$ elde edilir.

$$\theta_{yeni} = \theta_{eski} - \alpha \, \nabla_{\theta} J(\theta)$$

Bu güncelleme her iterasyonda tekrarlanır; amaç kayıp fonksiyonunu en küçük yapan $\theta$ değerlerini bulmaktır.

## 18. Tek İleri Geçiş Örneği

Slayttaki sayısal örnek bir metin sınıflandırma problemidir (ekrandan, 02:00:00). Metin, TF-IDF ya da kelime gömmeleri (word embeddings) ile üretilmiş öznitelik vektörüyle temsil edilir. Ağırlık matrisi başlangıçta rastgele oluşturulur. İşlem $\sigma(W x_i + b)$'dir; $W$ $4 \times 3$, $x_i$ $3 \times 1$'dir. Matrisler büyük harfle ($W$), vektörler küçük harfle ($x$) gösterilir.

$$W = \begin{bmatrix} 0{,}2 & -0{,}5 & 0{,}1 \\ 2{,}0 & 1{,}5 & 1{,}3 \\ 0{,}5 & 0{,}0 & 0{,}25 \\ -0{,}3 & 2{,}0 & 0{,}0 \end{bmatrix}, \quad x_i = \begin{bmatrix} 0{,}1 \\ 0{,}2 \\ 0{,}3 \end{bmatrix}, \quad b = \begin{bmatrix} 1{,}0 \\ 3{,}0 \\ 0{,}025 \\ 0{,}0 \end{bmatrix}$$

Adım adım:

- 1. satır: $0{,}2 \cdot 0{,}1 + (-0{,}5) \cdot 0{,}2 + 0{,}1 \cdot 0{,}3 = 0{,}02 - 0{,}1 + 0{,}03 = -0{,}05$; sapmayla $-0{,}05 + 1{,}0 = 0{,}95$.
- 2. satır: $2{,}0 \cdot 0{,}1 + 1{,}5 \cdot 0{,}2 + 1{,}3 \cdot 0{,}3 = 0{,}2 + 0{,}3 + 0{,}39 = 0{,}89$; sapmayla $3{,}89$.
- 3. satır: $0{,}05 + 0 + 0{,}075 = 0{,}125$; sapmayla $0{,}15$ (ara adım eklendi).
- 4. satır: $-0{,}03 + 0{,}4 + 0 = 0{,}37$; sapmayla $0{,}37$ (ara adım eklendi).

Sonuç vektörü $[0{,}95;\ 3{,}89;\ 0{,}15;\ 0{,}37]$'dir (python ile doğrulandı).

> **Ders sonrası not:** Hoca dördüncü değeri sözlü olarak $0{,}037$ dedi; slaytta ve hesapta doğrusu $0{,}37$'dir.

Bu dört çıktı, duygu analizi (sentiment analysis) gibi bir problemde dört sınıfın skorları olabilir: çok olumlu (very positive), olumlu (positive), olumsuz (negative), çok olumsuz (very negative). En büyük değer $3{,}89$ olduğundan tahmin edilen sınıf "olumlu"dur. Bu yalnız bir ileri geçiştir (one forward pass). Gerçek etiketle aradaki farktan hata hesaplanıp geri yayılımla ağırlıkların güncellenmesi ayrı bir aşamadır.

## 19. Softmax Çıkışı

> **Hocanın vurgusu:** Softmax, anlatılanlar içindeki en önemli kısımlardan biridir.

$x$ vektörü $W$ ile işleme alınıp bir skor hesaplanır: $s = f(x, W)$. Önceki örnekteki $0{,}95$, $3{,}89$ gibi değerler skordur (ekrandan, 02:25:00). Softmax uygulanmadan önce skor bileşenleri negatif ya da birden büyük olabilir ve toplamları 1 etmeyebilir. Softmax'tan sonra her bileşen $(0, 1)$ aralığında olur ve bileşenlerin toplamı 1 olur; böylece olasılık gibi yorumlanabilir:

$$P(Y = k \mid X = x_i) = \frac{e^{s_k}}{\sum_j e^{s_j}}$$

Pay, ilgili sınıfın skorunun üstelidir; payda bütün sınıfların (1'den sınıf sayısına kadar) skorlarının üstellerinin toplamıdır.

Sayısal örnek (ekrandan, 02:25:00): üç sınıfın skorları $3{,}2$; $5{,}1$; $-1{,}7$ olsun. Softmax olmadan en büyük değerin $5{,}1$ olduğuna bakıp sınıfı seçebiliriz, ama bu bir olasılık ifade etmez.

- Üstel değerler: $e^{3{,}2} \approx 24{,}5$, $e^{5{,}1} \approx 164{,}0$, $e^{-1{,}7} \approx 0{,}18$.
- Toplam: $24{,}5 + 164{,}0 + 0{,}18 = 188{,}68$.
- Normalleştirme: $24{,}5 / 188{,}68 \approx 0{,}13$; $164{,}0 / 188{,}68 \approx 0{,}87$; $0{,}18 / 188{,}68 \approx 0{,}001$.

Yani ikinci sınıf olma olasılığı yaklaşık %87, birinci sınıf olma olasılığı %13, üçüncüsü binde birdir. Python ile kesin değerlerle hesaplanınca toplam $188{,}74$, olasılıklar $0{,}130$; $0{,}869$; $0{,}00097$ çıkar; yuvarlanmış değerlerle aynı sonuç elde edilir.

> **Ders sonrası not:** Hoca üçüncü değeri "e üzeri 1,7" diye okudu; slayttaki gibi doğrusu $e^{-1{,}7} \approx 0{,}18$'dir ($e^{1{,}7} \approx 5{,}47$ olurdu).

## 20. CNN Mimarileri ve ImageNet Yarışması

Slaytlarda AlexNet, VGGNet, GoogLeNet, ResNet ve Inception ağları ele alınır. Slaytlar hazırlandığından beri Attention ve EfficientNet gibi yeni ağlar da eklenmiştir.

### 20.1 ImageNet ve ILSVRC

Derin öğrenme çalışmaları 2012'de bir yarışmayla büyük hız kazandı. ImageNet, bin farklı nesneye ait milyonlarca görüntü içeren bir veri tabanıdır. Bu veri tabanı üzerinde ImageNet Large Scale Visual Recognition Challenge (ILSVRC) yarışması düzenlenir ve her yıl kazananlar ilan edilir. Yarışmada ağın verdiği tahminlerin ilk beşine bakılır: doğru sınıf ilk beşin içindeyse doğru sınıflama yapılmış kabul edilir (top-5).

2012'de ilk kez bir CNN kullanıldı ve top-5 test hatası yaklaşık %15 oldu; bu, bin sınıf arasında yaklaşık %85 doğruluk demektir. İkinci sıradaki en iyi yöntemin hatası %26 idi; aradaki fark %10'dan fazladır. 2010-2011'deki sığ yapılarla (belki iki-üç katmanlı yapay sinir ağlarıyla) karşılaştırıldığında, ilk CNN'in kullanıldığı yılda hata yaklaşık %10 düştü.

### 20.2 AlexNet (2012)

AlexNet 8 katmandır. Burada katman olarak yalnız evrişim katmanları ve tam bağlantılı katmanlar sayılır; max pooling ya da aktivasyon katman sayılmaz: 5 evrişim + 3 tam bağlantılı = 8. 2012 yarışmasını bu yapı kazandı; top-5 hatası %16 civarındadır.

Boyutlar ve parametreler (ekrandan, 02:35:00):

- Girdi $227 \times 227 \times 3$ (dolgudan önce $224 \times 224$). İlk katmanda 96 tane $11 \times 11$ filtre, $S = 4$, $P = 0$. İlk mimarilerde filtre boyutları büyük tutulmuştu.
- Çıktı: $(227 - 11)/4 + 1 = 55$, yani $55 \times 55 \times 96$ (96 filtre olduğu için).
- İlk katmanın parametreleri: her filtrede $11 \cdot 11 \cdot 3$ ağırlık, 96 filtre; $11 \cdot 11 \cdot 3 \cdot 96 = 34\,848$, yaklaşık 35 bin.
- Ardından $3 \times 3$, $S = 2$ max pooling: 9 değer içinden en büyüğü alınır. $(55 - 3)/2 + 1 = 52/2 + 1 = 27$; çıktı $27 \times 27 \times 96$. Aynı formül burada da işe yarar. Max pooling her derinlik diliminde ayrı yapılır, derinliği değiştirmez ve parametresi yoktur.
- Sonra $5 \times 5$, $S = 1$, $P = 2$ evrişim; 256 filtre, aslında her biri $5 \times 5 \times 96$: $27 \times 27 \times 256$.
- Sonra $3 \times 3$, $S = 2$ max pool ($13 \times 13 \times 256$); üç tane $3 \times 3$, $S = 1$, $P = 1$ evrişim ($13 \times 13 \times 384$, $13 \times 13 \times 384$, $13 \times 13 \times 256$); son olarak $3 \times 3$, $S = 2$ max pool ile $6 \times 6 \times 256$.
- Beş evrişim katmanının sonunda öznitelik boyutu $6 \times 6 \times 256$'dır. Ardından 4096 düğümlü iki tam bağlantılı katman (FC1, FC2) ve softmax'lı çıkış katmanı (FC3) gelir.

AlexNet ayrıca filtreleri ikiye bölmüştür: ilk katmandaki 96 filtre 48 + 48 olarak iki parçada uygulanır; bunu iki işlemciye dağıtılmış gibi düşünebiliriz. Yapı hep böyle ikili işlem yapar. Hoca top-1 hatasının %46, top-5 hatasının %16 civarında olduğunu söyledi.

### 20.3 VGGNet (2014)

VGGNet, ILSVRC 2014'ün ikincisidir (runner-up) (ekrandan, 02:40:00). 16 ve 19 katmanlı iki türü vardır. AlexNet $11 \times 11$ ve $5 \times 5$ gibi filtreler kullanırken VGG yalnız $3 \times 3$ evrişim (stride 1, pad 1) ve $2 \times 2$ max pool (stride 2) kullanır. Slayttaki VGG-16 katman listesi:

```text
Girdi
3x3 conv, 64   x2   -> Pool 1/2
3x3 conv, 128  x2   -> Pool 1/2
3x3 conv, 256  x2   -> Pool 1/2
3x3 conv, 512  x3   -> Pool 1/2
3x3 conv, 512  x3   -> Pool 1/2
FC 4096, FC 4096, FC 1000, Softmax
```

<!-- BELİRSİZ: slayttaki listede 256'lık blokta iki evrişim görünüyor; standart VGG-16'da bu blokta üç evrişim vardır. Karedeki liste olduğu gibi aktarıldı. -->

İlk katmanın parametreleri: $224 \times 224 \times 3$ girdiye 64 tane $3 \times 3 \times 3$ filtre; $3 \cdot 3 \cdot 3 \cdot 64 = 1728$ ağırlık. VGGNet'in top-5 hatası %7,3'tür. Hoca VGG-16 ve VGG-19'un hantal, yavaş çalışan modeller olduğunu belirtti.

> **Ders sonrası not:** Hoca toplam parametre sayısını 128 milyon dedi; slaytta 140 milyon yazıyor. VGG-16'nın parametre sayısı büyük olasılıkla yaklaşık 138 milyondur.

### 20.4 GoogLeNet ve Inception modülü (2014)

GoogLeNet ILSVRC 2014'ün birincisidir (ekrandan, 02:45:00). AlexNet'ten çok daha derindir ama AlexNet'ten 12 kat daha az parametre kullanır; hesaplama verimliliğine odaklanır. Daha az parametre, daha hızlı bir mimari demektir. Bu mimari ilk kez Inception modülünü kullanır. İlginç bir özelliği de hiç tam bağlantılı katmanının olmaması ve toplamda yalnız yaklaşık 5 milyon parametresinin bulunmasıdır.

Inception modülünde önceki katmanın çıktısı birkaç dala ayrılır. Derste anlatıldığı kadarıyla bir dalda $1 \times 1$ evrişim filtreleri vardır; bir dalda çıktı araya başka evrişim konmadan doğrudan üstteki evrişim modülüne aktarılır; bir dalda da önce yalnız max pooling uygulanıp sonra evrişime girilir. Her dalın evrişim çıktısı art arda eklenerek (concatenation) bir öznitelik vektörü oluşturulur. Normalde bir evrişim katmanının çıktısı bir sonrakine verilir; burada bir üst katmana doğrudan aktarım vardır. <!-- BELİRSİZ: modül şemasındaki dalların tam listesi karede görülmedi -->

Sonraki mimarilerde filtre boyutları hep küçülmüştür: $1 \times 1$ ya da $3 \times 3$. $1 \times 1$ evrişim $xy$ düzleminde $1 \times 1$'dir ama bir derinliği vardır. Önceki katmandan gelen girdinin derinliği örneğin 128 ise filtre aslında $1 \times 1 \times 128$'dir; derinlik boyunca işlem yapıp tek bir çıktı üretir.

### 20.5 ResNet (2015)

2015'te ResNet ile katman sayısı 22'den 152'ye çıktı. Bu boyutlardaki ağları kişisel bir dizüstü bilgisayarda eğitmek mümkün değildir; bu kadar katman ve parametre güçlü hesaplama platformları gerektirir.

ResNet, derin artık öğrenme (deep residual learning) kullanır (ekrandan, 02:50:00):

- Düz katmanlarda (plain layers) girdi $x$ evrişim, ReLU ve tekrar evrişimden geçer ve $H(x)$ elde edilir.
- Artık blokta (residual block) girdi $x$ yine evrişim-ReLU-evrişimden geçer ve $F(x)$ verir. Bu sonuç, iki evrişimden önceki girdiyle toplanır: $H(x) = F(x) + x$. Toplamın ardından ReLU uygulanır. Girdiyi taşıyan yola özdeşlik (identity) bağlantısı denir.
- Geleneksel CNN'lerde $H(x)$ doğrudan $F(x)$'e eşittir. ResNet'te $x$'ten $F(x)$'e doğrudan dönüşüm yerine, girdiye eklenmesi gereken terim $F(x)$ hesaplanır.

Mimarideki atlamalar, girdinin evrişim çıktısıyla toplandığını gösterir. Hocanın yorumuyla, insanlar akıllarına gelen pek çok şeyi deneyerek iyi sonuç almaya çalışmıştır.

ResNet 2015'te top-5 hatasını %3,57'ye indirdi. Yarışmada insanlar da bilgisayar başına oturtulup gördükleri nesneyi sınıflamaya çalıştı; insanların hatası (slayttaki ifadeyle genelde %5-10) makinenin hatasından büyük çıktı. ResNet ImageNet'in yanında COCO veri kümesinde de denenip başarılı sonuçlar vermiştir. Hoca yarışmanın bundan sonra tekrarlanmadığını, insanın ötesinde başarı gösteren bir mimari bulunduğu için sona erdiğini söyledi.

> **Ders sonrası not:** ILSVRC yarışması büyük olasılıkla 2017'ye kadar sürdü; 2015'ten sonra da birkaç yıl düzenlendi.

### 20.6 Mimarilerin karşılaştırılması

Bir karşılaştırma grafiği AlexNet'ten Inception ve ResNet'e kadar olan ağları kıyaslar. Dikey eksen top-1 doğruluktur: AlexNet yaklaşık %50, Inception-v4 yaklaşık %80'dir. Yatay eksen işlem sayısını (giga işlem, G-Ops) gösterir; sağa gidildikçe daha çok işlem yapan, daha yavaş ağlar vardır. Her modelin etrafındaki dairenin büyüklüğü ihtiyaç duyduğu belleği gösterir. VGG-16 ve VGG-19 bu açıdan hantaldır. Sola yakın ve yukarıda olanlar (ResNet, Inception) daha başarılıdır. Doğruluk açısından en iyisi Inception-v4'tür; doğruluğu yüksek, bellek ihtiyacı da daha düşüktür.

## 21. Keras ile MNIST Sınıflandırma Örneği

Derste TensorFlow, Keras'ın altında kullanılır. Keras bir Python derin öğrenme kütüphanesidir; slayttaki tanıma göre Python ile yazılmış, TensorFlow, CNTK ya da Theano üzerinde çalışabilen üst düzey bir sinir ağı API'sidir. Fikirden sonuca en kısa sürede gidebilmek için hızlı deneme yapmaya odaklanır (ekrandan, 02:55:00).

TensorFlow'da sinir ağı modülünün altında iki boyutlu evrişim (conv2d) ve iki boyutlu max pooling işlemleri hazırdır. AlexNet defterinde evrişim katmanının ağırlıkları ve sapması (`wc1`, `bc1`) tanımlanır, görüntü matrisi üzerinde evrişim ve max pooling art arda uygulanarak bir evrişim katmanının çıktısı elde edilir. AlexNet defteri derste ayrıntılı anlatılmadı.

MNIST ile basit bir örnek (ekrandan, 03:00:00):

```python
model = tf.keras.models.Sequential([
  tf.keras.layers.Flatten(input_shape=(28, 28)),
  tf.keras.layers.Dense(512, activation=tf.nn.relu),
  tf.keras.layers.Dropout(0.2),
  tf.keras.layers.Dense(10, activation=tf.nn.softmax)
])
model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

model.fit(x_train, y_train, epochs=5)
model.evaluate(x_test, y_test)
```

Adımlar:

- Görüntüler gri seviyelidir; `x_train` ve `x_test` 255'e bölünerek bütün parlaklık değerleri $[0, 1]$ aralığına normalleştirilir.
- Model sıralı (sequential) olarak tanımlanır. Önce girdi düzleştirilir, ardından 512 düğümlü bir tam bağlantılı (dense) katman ve ReLU aktivasyonu gelir. Arkasından %20 dropout uygulanır. Son katman 10 düğümlü bir dense katmandır: çok sınıflı bir problemde çıkış katmanında sınıf sayısı kadar düğüm olmak zorundadır. Aktivasyonu softmax'tır, böylece skorlar olasılık olarak okunur.
- `model.compile` ile eniyileyici (`adam`), kayıp fonksiyonu ve izlenecek metrik (doğruluk) verilir. Görüntü sınıflandırmada kayıp olarak genelde çapraz entropi (cross-entropy) kullanılır.
- `model.fit` ile eğitim kümesi üzerinde 5 epok eğitim yapılır, `model.evaluate` ile test kümesinde değerlendirilir.

Çıktıda her epokta kayıp ve doğruluk yazdırılır (ekrandan, 03:00:00):

```text
Epoch 1/5  loss: 0.2214 - acc: 0.9347
Epoch 2/5  loss: 0.0984 - acc: 0.9700
Epoch 3/5  loss: 0.0689 - acc: 0.9781
Epoch 4/5  loss: 0.0535 - acc: 0.9831
```

Kayıp her epokta azalır; 10 ya da 20 epok çalıştırılsa daha da düşer. Eğitim doğruluğu %93'ten %97'ye, sonra %98'in üzerine çıkar. Test kümesinde doğruluk yaklaşık %97,9, kayıp yaklaşık 0,07 bulunmuştur. <!-- BELİRSİZ: 5. epok satırı ve test sonucunun tam değerleri karede görülmedi; altyazıda doğruluk "0,9791", kayıp "0,07" diye okunuyor -->

Ders, hazır mimarilerin çalışmalarda rahatça kullanılabileceği, ama katmanlarının incelenip anlaşılması gerektiği vurgusuyla bitti. Lisansüstü çalışmalarda, özellikle doktorada, bu mimarilerde basit bir bağlantıyı değiştirerek yeni bir mimari oluşturmak mümkündür.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): Aşağıdaki $6 \times 6$ görüntü, Filtre 1 ($\begin{bmatrix} 1 & -1 & -1 \\ -1 & 1 & -1 \\ -1 & -1 & 1 \end{bmatrix}$) ile stride 1 ve stride 2 için evrişime alınırsa çıktı ne olur?

```text
1 0 0 0 0 1
0 1 0 0 1 0
0 0 1 1 0 0
1 0 0 0 1 0
0 1 0 0 1 0
0 0 1 0 1 0
```

> **Çözüm:** Stride 1 için çıktı $4 \times 4$'tür: ilk satır $3, -1, -3, -1$; tamamı $\begin{bmatrix} 3 & -1 & -3 & -1 \\ -3 & 1 & 0 & -3 \\ -3 & -3 & 0 & 1 \\ 3 & -2 & -2 & -1 \end{bmatrix}$. Stride 2 için derste ilk iki değer $3$ ve $-3$ olarak gösterildi; tam çıktı $\begin{bmatrix} 3 & -3 \\ -3 & 0 \end{bmatrix}$'dır (tamamı python ile doğrulandı).

**Soru 2** (derste sözlü, 00:41:05): $6 \times 6 \times 3$ renkli bir görüntü $3 \times 3 \times 3$ bir filtreyle, dolgu yapılmadan ve stride 1 ile evrişime alınırsa çıktı boyutu ne olur?

> **Çözüm:** $(6-3)/1 + 1 = 4$; filtre bütün derinliği çarpıp topladığı için çıktı $4 \times 4 \times 1$'dir. Her çıkış değeri için $3 \cdot 3 \cdot 3 = 27$ çarpım toplanır.

**Soru 3** (ekrandan, 00:50:00): $N = 7$, $F = 3$ için stride 1, 2 ve 3'te çıktı boyutu nedir?

> **Çözüm:** $(7-3)/1+1 = 5$; $(7-3)/2+1 = 3$; $(7-3)/3+1 = 2{,}33$, yani stride 3 bu boyuta uymaz.

**Soru 4** (derste sözlü, 00:53:16): $5 \times 5$ filtrede çıktının girdiyle aynı boyutta kalması için ne kadar sıfır dolgu gerekir?

> **Çözüm:** $P = (F-1)/2 = (5-1)/2 = 2$.

**Soru 5** (ekrandan, 00:55:00): Girdi hacmi $32 \times 32 \times 3$; 10 tane $5 \times 5 \times 3$ filtre, stride 1, dolgu 2. Çıktı hacmi nedir? Bu katmandaki parametre sayısı nedir?

> **Çözüm:** Çıktı: $(32 - 5 + 2 \cdot 2)/1 + 1 = 32$, yani $32 \times 32 \times 10$. Parametre: her filtre $5 \cdot 5 \cdot 3 = 75$ ağırlık + 1 sapma = 76; toplam $76 \cdot 10 = 760$.

**Soru 6** (derste sözlü, 01:03:35): $N = 7$, $F = 5$, $P = 2$, $S = 1$ için genel formül çıktı boyutunu koruyor mu?

> **Çözüm:** $(7 - 5 + 2 \cdot 2)/1 + 1 = 7$; evet, çıktı girdiyle aynı boyuttadır.

**Soru 7** (ekrandan, 01:30:00): Filtre 1'in $4 \times 4$ evrişim çıktısına $2 \times 2$, stride 2 max pooling uygulanırsa sonuç ne olur?

> **Çözüm (derste verilmedi):** Dört $2 \times 2$ bloğun en büyükleri alınır: $\begin{bmatrix} 3 & 0 \\ 3 & 1 \end{bmatrix}$. Filtre 2'nin çıktısı için sonuç $\begin{bmatrix} -1 & 1 \\ 0 & 3 \end{bmatrix}$'tür (python ile hesaplandı).

**Soru 8** (ekrandan, 01:50:00): 3 girdi, 4 gizli, 2 çıkış nöronlu tam bağlantılı ağın kaç öğrenilebilir parametresi vardır?

> **Çözüm:** Ağırlıklar $3 \cdot 4 + 4 \cdot 2 = 20$, sapmalar $4 + 2 = 6$; toplam $26$.

**Soru 9** (ekrandan, 02:25:00): Skorlar $3{,}2$; $5{,}1$; $-1{,}7$ ise softmax çıktıları nedir?

> **Çözüm:** $e^{3{,}2} \approx 24{,}5$, $e^{5{,}1} \approx 164{,}0$, $e^{-1{,}7} \approx 0{,}18$; toplam $\approx 188{,}68$. Olasılıklar $\approx 0{,}13$; $0{,}87$; $0{,}001$.

**Soru 10** (ekrandan, 02:35:00): AlexNet'te $227 \times 227 \times 3$ girdiye 96 tane $11 \times 11$ filtre ($S = 4$, $P = 0$) uygulanıyor, ardından $3 \times 3$, $S = 2$ max pooling geliyor. Her adımın çıktı boyutu ve ilk katmanın ağırlık sayısı nedir?

> **Çözüm:** $(227-11)/4+1 = 55$, yani $55 \times 55 \times 96$; ağırlık $11 \cdot 11 \cdot 3 \cdot 96 = 34\,848$. Havuzlama: $(55-3)/2+1 = 27$, yani $27 \times 27 \times 96$.

## Dersin Toparlaması

Bu derste CNN'in yapı taşları uçtan uca kuruldu. CIFAR-10 ve MNIST veri kümelerinin yapısı ve Python ile okunuşu görüldü. Ardından evrişim katmanının nasıl çalıştığı ayrıntılı işlendi: filtrenin görüntü üzerinde kaydırılması, stride, renkli görüntüde derinlik, çıktı boyutu formülü $(N - F + 2P)/S + 1$, aynı boyutu koruyan sıfır dolgu ve parametre sayısının hesabı. Art arda evrişim katmanlarının alt, orta ve üst düzey öznitelikleri otomatik çıkardığı, max pooling'in gösterimi küçülttüğü, ReLU'nun derin ağların başarısındaki kilit rolü, düzleştirme ve tam bağlantılı katmanla sınıflandırma, softmax'ın skorları olasılığa çevirmesi anlatıldı.

Dersin son bölümünde ImageNet yarışması üzerinden AlexNet, VGGNet, GoogLeNet (Inception) ve ResNet mimarilerinin gelişimi ve hata oranlarının %16'dan %3,57'ye inişi incelendi; Keras ile basit bir MNIST sınıflandırıcısı eğitildi. Sonraki derste eniyileme, düzenlileştirme ve dropout gibi ince ayar konuları ile eğitimin ayrıntıları ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
