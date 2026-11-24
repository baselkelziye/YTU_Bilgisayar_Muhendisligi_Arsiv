# Ders 14 Genişletilmiş Notu: Yapay Sinir Ağları ve Keras ile Derin Öğrenme Uygulamaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Kaynak
- 2. Yapay Sinir Ağlarına Giriş
- 3. Perceptron: Bir Nöronun Yapısı
- 4. Ağ Topolojileri
- 5. Ağın Öğrenmesi: Hata Fonksiyonu ve Gradient Descent
- 6. Sigmoid Aktivasyon Fonksiyonu
- 7. Çözümlü Örnek: Kara Kutu Modeli
- 8. Keras ile Uygulamaya Giriş
- 9. Ağ Tasarımında Altı Karar
- 10. İkili Sınıflayıcı: IMDB Film Yorumları
- 11. Çok Sınıflı Sınıflayıcı: Reuters Haberleri ve Softmax
- 12. Regresyon Modeli
- 13. Eğitim Geçmişi ve Aşırı Öğrenmeyi Azaltma
- 14. Model Kaydetme, k-Katlı Çapraz Doğrulama ve Hiperparametre Arama
- 15. Konvolüsyon İşlemi
- 16. CNN ile Görüntü Sınıflama: MNIST
- 17. Soru-Cevaptan Akademik Notlar
- Örnek Sorular

## 1. Dersin Amacı ve Kaynak

Dönemin konuları bir önceki derste tamamlandığı için bu derste, veri madenciliğinde görülen sınıflandırma ve regresyon yöntemlerinin yapay sinir ağları ve derin öğrenmeyle nasıl yapıldığı anlatıldı. Hoca, bu konunun bir sınav konusu olmadığını, yalnız öğrenmek isteyenler için hazırlandığını belirtti.

Kaynak olarak *Machine Learning with Python Cookbook: Practical Solutions from Pre-Processing to Deep Learning* kitabı kullanıldı. Kitap, dersteki sıraya benzer biçimde veri ön işleme ve normalizasyonla başlar; sınıflandırma, regresyon ve kümeleme bölümleriyle devam eder ve yapay sinir ağlarıyla model kurmaya kadar gider. Hoca kitabın uygulamaya dönük olduğunu, teorik bilgisi olmayan birinin tek başına kullanabileceği bir kaynak olmadığını, teoriyi bilen birine pratikte yol gösterdiğini söyledi. Dersin ilk yarım saati teoriye (bir nöronun çalışma yapısı ve matematiği), kalan kısmı Jupyter Notebook üzerinde kitabın 20. bölümündeki ("Chapter 20 - Neural Networks") örneklere ayrıldı (ekrandan, 01:15:00).

Uygulama bölümünde dört tür model planlandı: sayısal çıktı için regresyon, iki çıkışlı ikili sınıflama (binary classification), çok sınıflı sınıflama (multi-class classification) ve görüntü üzerinde CNN (Convolutional Neural Network) ile öz nitelik çıkarma ve tam bağlı katmanlarla model kurma.

> **Hocanın vurgusu:** Hazır kütüphaneleri kullanmak kolaydır; ama arkadaki teoriyi ve matematiği biraz anlarsanız bu modelleri daha verimli kullanır ve kendinize göre iyileştirmeler yapabilirsiniz.

## 2. Yapay Sinir Ağlarına Giriş

Derste kullanılan sınıflandırma ve kümeleme yöntemleri aynı zamanda makine öğrenmesinin de konularıdır; iki alan iç içedir. Slaytlar bir makine öğrenmesi kitabının slaytlarından düzenlenmiştir.

Slayttaki tanıma göre yapay sinir ağları **insan beyninden esinlenen hesaplama modelleridir** (ekrandan, 00:20:00):

- Beyni taklit etmeye çalışan algoritmalardır.
- Basit işlem birimlerinden (nöronlardan) oluşan, büyük ölçüde paralel ve dağıtık bir sistemdir.
- Edinilen bilgi, nöronlar arasındaki sinaptik bağlantı güçlerinde saklanır.
- Bilgi, ağ tarafından çevresinden bir öğrenme süreciyle elde edilir.

İnsan beynindeki her nöron çevresindeki nöronlarla iletişim ve etkileşim içindedir; yapay sinir ağı bu düşünceyle kurulmuştur.

Yapay sinir ağları yeni bir konu değildir. 60'lı ve 70'li yıllarda kullanılmaya başlanmış, 1986'da geri yayılım (backpropagation) algoritması kullanılmıştır. Bu modellerin hesaplama karmaşıklığı yüksektir; eski altyapılarla bir modelin sonuç vermesi günler sürebildiği için konu bir dönem bırakılmıştı. Günümüzde çok güçlü hesaplama altyapıları olduğundan modeli çalıştırmak günler almıyor; bu sayede katman sayısı artırılarak daha derin yapılar kurulabiliyor ve daha karmaşık modellerle çok daha başarılı sonuçlar elde ediliyor. Son on yılda yeniden yaygınlaşmalarının nedeni budur.

Kullanım alanları arasında en çok görülenler:

- **Örüntü tanıma (pattern recognition):** nesne tespiti (object detection), nesne tanıma (object recognition) gibi.
- **Fonksiyon yaklaşımı (function approximation):** sayısal bir çıktıya yakınsamak.

## 3. Perceptron: Bir Nöronun Yapısı

Perceptron, yapay sinir ağının en temel birimidir ve bir **doğrusal ayırıcıdır** (linear separator). Slayttaki parçalar şunlardır (ekrandan, 00:25:00):

- $N$ giriş: $x_1, \dots, x_n$
- Her girişin ağırlığı: $w_1, \dots, w_n$
- Sabit bir bias girişi $x_0$ ve ona bağlı ağırlık $w_0$
- Girişlerin ağırlıklı toplamı: $y = w_0x_0 + w_1x_1 + \dots + w_nx_n$
- Bir eşik (threshold) ya da aktivasyon fonksiyonu; örneğin $y > t$ ise $1$, $y \le t$ ise $-1$.

Giriş vektörü, veri madenciliğinde kullandığımız bir örnektir (sample): $n$ boyutlu uzayda bir nokta. $n$, öz nitelik sayısıdır. Asıl girişler $x_1$'den $x_n$'e kadardır; matematiksel yapıda bias'ı da toplama katmak için sabit bir $x_0$ girişi eklenir ve ona bağlı $w_0$ ağırlığı bias değerini oluşturur. Bir başka gösterimde bias ayrı bir $t$ değeri olarak toplamdan çıkarılır:

$$
\sum_{i} w_i x_i - t
$$

Bu toplam bir aktivasyon fonksiyonundan (sigmoid ya da başka bir fonksiyon) geçirilir ve $Y$ çıktısı üretilir. Aktivasyon fonksiyonunun bir diğer adı eşik fonksiyonudur (threshold function).

Hoca bunu üç girişli bir şekil üzerinde de gösterdi: üç giriş düğümü (input nodes), üç öz nitelikli bir veri setinin girişini temsil eder. Her giriş bir $w$ ile ağırlıklandırılır, ağırlıklı toplamdan $t$ çıkarılır ve sonuç bir aktivasyon fonksiyonundan geçirilir.

## 4. Ağ Topolojileri

Bağlantı türlerine göre farklı ağ modelleri vardır.

### 4.1 İleri Beslemeli Ağlar

**Tek katmanlı ileri beslemeli ağda** (single layer feed-forward) giriş katmanı doğrudan çıkış katmanına bağlanır.

**Çok katmanlı ileri beslemeli ağda** (multi-layer feed-forward) bir ya da daha çok gizli katman (hidden layer) vardır ve her katman yalnız önceki katmandan giriş alır (ekrandan, 00:30:00). Gizli katmanların sayısı 2, 3 ya da daha fazla olabilir; ne kadar çok katman eklenirse o kadar derin bir yapı kurulmuş olur. Kaç gizli katman olacağına ve her gizli katmanda kaç nöron bulunacağına modeli kuran kişi karar verir. Gizli katmandaki her nöron bir perceptrondur: girişleri ağırlıklarla çarpıp toplar ve aktivasyon fonksiyonundan geçirir.

Slayttaki ağda bir giriş katmanı, iki nöronlu bir gizli katman ve dört nöronlu bir çıkış katmanı vardır; bu ağa "2 katmanlı" ya da "1 gizli katmanlı tam bağlı ağ" (fully connected network) denir. Hoca, her ağın başında bir giriş ve sonunda bir çıkış katmanı olacağı zaten bilindiği için "1 gizli katmanlı" adlandırmasını daha doğru bulduğunu söyledi.

Çıkış katmanındaki birim sayısı problemin türüne göre belirlenir. Çok sınıflı problemde çıkış birimi sayısı sınıf sayısına eşittir. Örneğin ImageNet kütüphanesindeki 1000 farklı nesneyi tanıyacak bir yapının 1000 çıkışı olur.

Bir başka örnekte üç öz nitelikli bir veri seti için iki gizli katman (ilkinde üç, ikincisinde iki nöron) ve tek çıkışlı bir ağ çizildi. Tek çıkış bir ikili sınıflayıcıya karşılık gelebilir: çıkış 0 ise sınıf 0, 1 ise sınıf 1. Giriş ve çıkış katmanları da sayılırsa dört katman vardır; ama "iki gizli katmanlı ağ" demek daha doğrudur.

### 4.2 Tekrarlayan Ağlar

Tekrarlayan ağlarda (recurrent networks) bir katmandaki düğümün çıkışı, aynı katmandaki başka bir düğümün girişi olabilir.

## 5. Ağın Öğrenmesi: Hata Fonksiyonu ve Gradient Descent

### 5.1 Hata Fonksiyonu

Yapay sinir ağını eğitmekten amaç, ağırlıkları en iyi değerlerine getirmektir. Slayttaki algoritma şöyledir (ekrandan, 00:35:00):

- Ağırlıkları başlat: $(w_0, w_1, \dots, w_k)$. Başlangıçta rastgele seçilirler.
- Ağırlıkları, ağın çıktısı eğitim örneklerinin sınıf etiketleriyle tutarlı olacak şekilde ayarla.
  - Hata fonksiyonu: $E = \sum_i \left[Y_i - f(w_i, X_i)\right]^2$
  - Bu hatayı en küçük yapan $w_i$ ağırlıklarını bul; örneğin gradient descent ya da backpropagation algoritmasıyla.

Burada $Y_i$, $X_i$ örneğinin gerçek değeridir (ground truth); $f(w_i, X_i)$ ise örnek ağa verildiğinde ağın ürettiği çıktıdır. İkisi arasındaki fark hatadır. Veri setinde $m$ örnek varsa her biri için farkın karesi alınıp toplanır. İyi bir modelde bu hatanın en küçük olması beklenir; bunu sağlayan ağırlıklar, eğitim kümesindeki örneklerle sistem tekrar tekrar çalıştırılıp ağırlıklar güncellenerek bulunur. Bu noktadan sonra problem bir optimizasyon problemidir.

### 5.2 Gradient Descent

Slaytta iki ağırlıklı ($w_0$ ve $w_1$; $w_0$ bias'tır) bir problem çizilmiştir: yatay eksenlerde $w_0$ ve $w_1$, dikey eksende kayıp fonksiyonu vardır (ekrandan, 00:40:00). Bu kayıp yüzeyi **konveks** bir yapıdadır: yerel minimumu olmayan, tek bir minimumu olan bir yapı. Böyle bir yapıda minimumu bulmak kolaydır: kayıp fonksiyonunun $w$'ye göre türevi alınarak arama yapılır.

Slayttaki ifadeler:

- Konkav bir fonksiyonun maksimumu, konveks bir fonksiyonun minimumuna denktir. Konkav için **gradient ascent**, konveks için **gradient descent** kullanılır.
- Gradyan: $\nabla_{\mathbf{w}} l(\mathbf{w}) = \left[\dfrac{\partial l(\mathbf{w})}{\partial w_0}, \dots, \dfrac{\partial l(\mathbf{w})}{\partial w_d}\right]'$
- Güncelleme kuralı: $\Delta \mathbf{w} = \eta \nabla_{\mathbf{w}} l(\mathbf{w})$; öğrenme oranı $\eta > 0$.
- Gradient ascent kuralı: $w_i^{(t+1)} \leftarrow w_i^{(t)} + \eta \left.\dfrac{\partial l(\mathbf{w})}{\partial w_i}\right|_t$

Başlangıçta $w$ rastgele seçilir; bu bir başlama noktasıdır. Her iterasyonda $w$, yüzeyin dip noktasına doğru götüren adımlarla güncellenir. Slaytta grafiğin dikey ekseni $-l(\mathbf{w})$ olarak çizildiği için kural $+$ işaretiyle verilmiştir; gradient descent kuralında ise türev terimi çıkarılır:

$$
w_i^{(t+1)} = w_i^{(t)} - \eta \frac{\partial l(\mathbf{w})}{\partial w_i}
$$

Öğrenme oranı $\eta$ oldukça küçük, pozitif bir sayıdır. Hoca, örnekte 0.05 alındığını, ama uygulamada genellikle binde bir, on binde bir gibi değerlerin kullanıldığını söyledi. <!-- BELİRSİZ: 0.05 değerinin görüldüğü slayt karelerde yok; değer altyazıdan alındı. --> Öğrenme oranı adım uzunluğunu ayarlar: çok büyük seçilirse büyük adımlarla gidilir ve minimum ıskalanabilir. Bu yüzden bazı uygulamalarda öğrenme oranı dinamik olarak ayarlanır. Gradient descent bir seçenektir; bunun dışında başka optimizasyon algoritmaları da vardır.

### 5.3 Batch Perceptron Algoritması

Slayttaki batch perceptron algoritmasının adımları şöyle anlatıldı:

- 1. adım: sistemdeki bütün ağırlıklar ($w_1$'den $w_m$'ye) rastgele başlatılır.
- Eğitim kümesindeki örnekler üzerinden döngü kurulur: $i = 1, \dots, R$ örnek numarası (R toplam örnek sayısı), $j = 1, \dots, m$ öz nitelik numarasıdır.
- Her örnek formülde yerine konur ve tanımlı kayıp fonksiyonunu en küçük yapacak ağırlıklar aranır.
- 5. adım: hata belirlenen bir eşik değerine inene kadar (ya da belirlenen döngü sayısına ulaşılana kadar) 3. ve 4. adımlar tekrarlanır.

<!-- BELİRSİZ: Batch perceptron slaytının formülleri karelerde yok; adımlar altyazıdan kuruldu. -->

## 6. Sigmoid Aktivasyon Fonksiyonu

Yapay sinir ağlarında en çok kullanılan aktivasyon fonksiyonlarının başında sigmoid gelir (ekrandan, 00:45:00):

$$
g(h) = \frac{1}{1 + \exp(-h)}
$$

Burada $h$, girişlerin ağırlıklarla çarpılıp toplanmasıyla elde edilen değerdir. Grafikte yatay eksen $h$, dikey eksen $g(h)$'dir. $h = 0$ için $g(0) = 0.5$'tir ve fonksiyon 0 ile 1 arasında değer üretir. Bu yüzden ikili sınıflayıcının çıkışına sigmoid konarak elde edilen çıktı 0-1 aralığına sıkıştırılır: 0'a yakınsa sınıf 0, 1'e yakınsa sınıf 1 denir. Nöronun çıkışı 400 ya da $-100$ gibi bir değer olsa bile sigmoid bunu 0-1 aralığına çevirir.

Slaytta, sigmoid kullanılan bir ağ için seçilecek $w$'nin şu toplamı en küçük yapması gerektiği yazılıdır:

$$
\sum_{i=1}^{R} \left[y_i - \text{Out}(\mathbf{x}_i)\right]^2 = \sum_{i=1}^{R} \left[y_i - g(\mathbf{w}^T \mathbf{x}_i)\right]^2
$$

Nöron şemasında ağırlıklı toplama "net" denir ve çıkış $\dfrac{1}{1 + e^{-\text{net}}}$ olarak yazılır.

> **Ders sonrası not:** Hoca sigmoid için "0'dan küçük bir değer gelirse 0, büyük gelirse 1 üreten bir eşik fonksiyonu" dedi. Sigmoid sert bir eşik değildir; çıkışı 0 ile 1 arasında sürekli değişir ve yalnız büyük negatif girişlerde 0'a, büyük pozitif girişlerde 1'e yaklaşır. Sınıf kararı, bu sürekli çıktıya ayrıca bir eşik (ör. 0.5) uygulanarak verilir; hoca da uygulama kısmında bunu böyle anlattı.

## 7. Çözümlü Örnek: Kara Kutu Modeli

Slayttaki örnekte (ekrandan, 00:50:00) üç öz nitelikli ($X_1, X_2, X_3$), 8 örnekli, iki sınıflı bir veri seti ve tek nöronlu bir model verilmiştir. Üç giriş düğümü giriş katmanını gösterir; bu katmanda ağırlık yoktur. Kırmızı oklar girişlerin nörona hangi ağırlıklarla bağlandığını gösterir: her biri 0.3'tür. Bias burada ayrı çizilmiş $t = 0.4$ değeridir.

| $X_1$ | $X_2$ | $X_3$ | $Y$ |
|---|---|---|---|
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 |
| 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 0 | 0 | 0 | 0 |

Model:

$$
Y = I(0.3X_1 + 0.3X_2 + 0.3X_3 - 0.4 > 0), \qquad I(z) = \begin{cases} 1 & z \text{ doğruysa} \\ 0 & \text{aksi halde} \end{cases}
$$

Girişler ağırlıklarla çarpılıp toplanır, $t$ çıkarılır; içerideki toplam 0'dan büyükse çıkış 1, değilse 0 olur. Satır satır hesap (ara adım eklendi):

- Tek girişi 1 olan satırlar, örneğin $(1,0,0)$: $0.3 - 0.4 = -0.1 \le 0 \Rightarrow Y = 0$.
- İki girişi 1 olan satırlar, örneğin $(1,0,1)$: $0.6 - 0.4 = 0.2 > 0 \Rightarrow Y = 1$.
- Üç girişi 1 olan satır $(1,1,1)$: $0.9 - 0.4 = 0.5 > 0 \Rightarrow Y = 1$.
- Hepsi 0 olan satır: $-0.4 \le 0 \Rightarrow Y = 0$.

Model, en az iki girişi 1 olan örnekler için 1 üretir ve tablodaki 8 etiketin hepsiyle tutarlıdır (ders sonrası python ile kontrol edildi). Hata, ağın çıktısıyla gerçek değer arasındaki farkların kareleri toplamıdır; amaç bu hatayı en küçük yapan parametreleri bulmaktır.

### 7.1 Gizli Katmanın İç Yapısı

Bir başka slaytta $X_1$'den $X_5$'e beş öz nitelikli bir veri seti için giriş katmanı, üç nöronlu bir gizli katman ve tek çıkışlı bir çıkış katmanı (ikili sınıflayıcı) çizilmiştir. Gizli katmandaki bir nöronun iç yapısında ağırlıklı girişler toplanıp bir toplam ($S$) oluşturulur, bu toplam aktivasyon fonksiyonundan geçirilerek çıkış üretilir. Her gizli katmanda aynı işlem tekrarlanır; bir gizli katmanın arkasından gelen başka bir gizli katmanda da aynı yapı vardır. <!-- BELİRSİZ: Bu slayt karelerde yok; anlatım altyazıdan kuruldu. -->

## 8. Keras ile Uygulamaya Giriş

### 8.1 Elle Öz Nitelik Çıkarmadan CNN'e

Notebook'un giriş kısmında farklı ağ modelleri şekillerle tanıtıldı. Hoca, görüntü işlemede eskiden öz nitelik çıkarmanın (feature extraction) elle yapıldığını anlattı: görüntüde kenarlar ve köşeler bulunur, bunların birbirine uzaklığı, daire olup olmadığı, varsa çapı gibi öz nitelikler üretilip sisteme giriş olarak verilirdi. Konvolüsyonel sinir ağlarında (CNN) bu öz nitelikler konvolüsyon katmanında çıkarılır. Böylece insanın öngöremediği, kenar, köşe ve daireden çok daha karmaşık öz nitelikler elde edilir ve daha başarılı modeller kurulur.

Notebook'taki şekilde (ekrandan, 01:10:00) giriş görüntüsü, ardışık konvolüsyon ve alt örnekleme (subsampling) katmanlarıyla öz nitelik haritalarına (feature maps) dönüştürülür ve en sonda tam bağlı (fully connected) katmanlarla çıkışa bağlanır. Her öz nitelik haritası farklı bir filtreyle yapılan konvolüsyonun sonucudur. Öz nitelik haritaları flatten işlemiyle satır satır art arda eklenerek bir vektöre yerleştirilir ve tam bağlı katmana verilir.

Notebook'ta ayrıca şu bilgi yer alır: ağ parametreleri küçük rastgele değerlerle başlatılır; bir örnek (ya da bir grup örnek, batch) ağa verilip çıktı kayıp fonksiyonuyla gerçek değerle karşılaştırılır (forward propagation); sonra ağda geriye doğru gidilerek her parametrenin hataya katkısı bulunur (backpropagation). Bütün eğitim örneklerinin ağdan bir kez geçmesine bir **epoch** denir ve eğitim genellikle birçok epoch'tan oluşur (ekrandan, 01:10:00).

Keras üst düzey bir kütüphanedir; altta TensorFlow ve Theano gibi kütüphaneleri motor olarak kullanır. Derste TensorFlow çözümleri kullanıldı.

### 8.2 Ön İşleme: Standart Ölçekleme

İlk örnekte iki öz nitelikli, beş örnekli sentetik bir veri üretildi ve scikit-learn'ün `preprocessing` modülündeki `StandardScaler` uygulandı. Bu, derste öğrenilen standart sapma normalizasyonudur: veri setinin ortalaması ve standart sapması hesaplanır, her değerden ortalama çıkarılıp standart sapmaya bölünür. Verideki 3000-9000 gibi büyük değerler normalizasyondan sonra yaklaşık $\pm 2$ aralığına sıkışır. Ortalama çıkarıldığı için sonuç sıfır ortalamalıdır; standart sapma yaklaşık 1 olur (çıktıda 0.99 ya da 1). <!-- BELİRSİZ: Bu örneğin kodu ve çıktısı karelerde yok; değerler altyazıdan alındı. -->

### 8.3 Sequential Model

Sequential (ardışık) model kurmak, art arda kullanılacak katmanların tarifini vermek demektir: hangi katman var, özellikleri ne, arkasından gelen katmanın özellikleri ne. Katmanlar arasında uyum olması için bir katmanın çıkış sayısı sonraki katmanın giriş sayısıyla tutarlı olmalıdır. Notebook'taki kod (ekrandan, 01:15:00):

```python
# Load libraries
from keras import models
from keras import layers

# Start neural network
network = models.Sequential()

# Add fully connected layer with a ReLU activation function
network.add(layers.Dense(units=16, activation="relu", input_shape=(10,)))

# Add fully connected layer with a ReLU activation function
network.add(layers.Dense(units=16, activation="relu"))

# Add fully connected layer with a sigmoid activation function
network.add(layers.Dense(units=1, activation="sigmoid"))

# Compile neural network
network.compile(loss="binary_crossentropy", # Cross-entropy
    optimizer="rmsprop", # Root Mean Square Propagation
    metrics=["accuracy"]) # Accuracy performance metric
```

Satırların anlamı:

- `network = models.Sequential()` ağı başlatır; `network.add(...)` her adımda bir katman ekler.
- İlk `Dense` katmanı, giriş katmanının hemen arkasından geldiği için iki şey ister: katmandaki nöron sayısı (`units=16`; hoca bunun 26 gibi başka bir sayı da olabileceğini söyledi) ve giriş boyutu (`input_shape=(10,)`, yani 10 öz nitelik). Aktivasyon `relu`'dur.
- İkinci `Dense` katmanında `input_shape` gerekmez, çünkü girişi bir önceki katmanın 16 çıkışıdır.
- Son katmanda `units=1` ve `activation="sigmoid"` vardır: bu çıkış katmanıdır, tek nörondan oluşur ve sigmoid ile 0-1 aralığında çıktı üretir. Örneğin 0.5'ten küçükse sınıf 0, büyükse sınıf 1 denir.
- `compile` adımında kayıp fonksiyonu (`binary_crossentropy`: iki sınıflı problemler için; evet/hayır, hasta/sağlıklı, churn/non-churn gibi), optimizer (`rmsprop`: Root Mean Square Propagation) ve izlenecek metrik (`accuracy`) seçilir. Optimizer'lar ağırlıkları kaybı en küçük yapacak şekilde günceller; bazıları daha hızlı, bazıları daha yavaş çalışır.

## 9. Ağ Tasarımında Altı Karar

Notebook'taki tartışma metnine göre gizli katmanlardaki her birim birkaç giriş alır, her girişi bir parametreyle ağırlıklandırır, ağırlıklı girişleri bir bias ile birlikte toplar, çoğunlukla bir aktivasyon fonksiyonu uygular ve çıktıyı sonraki katmana gönderir (ekrandan, 01:20:00). İleri beslemeli bir ağ kurarken verilmesi gereken kararlar şunlardır:

**1. Her gizli ve çıkış katmanı için birim sayısı ve aktivasyon fonksiyonu.** Bir katmanda ne kadar çok birim olursa ağ o kadar karmaşık örüntüler öğrenebilir; ama fazla birim eğitim verisine aşırı uyuma (overfitting) yol açabilir. Gizli katmanlar için yaygın aktivasyon fonksiyonu ReLU'dur (ekrandan, 01:20:00):

$$
f(z) = \max(0, z)
$$

Nöronun çıkışı (ağırlıklı toplam) negatifse ReLU'nun çıkışı 0'a kilitlenir; pozitifse değer olduğu gibi geçer (2 ise 2, 1 ise 1). Hoca, derin ağların kullanımıyla birlikte gizli katmanlarda sigmoid yerine ReLU tercih edilmesinin sistem başarısını artırdığını ve yapay sinir ağlarının bugünkü popülerliğinde ReLU'nun payı olduğunu söyledi. ReLU çıktıyı 0-1 aralığına sıkıştırmak için kullanılmaz; ara katmanlarda tercih edilir. Bu yüzden örnekte iki gizli katmanda ReLU, çıkış katmanında sigmoid kullanılmıştır.

**2. Gizli katman sayısı.** Daha çok katman, ağın daha karmaşık ilişkileri öğrenmesini sağlar, ama hesaplama maliyeti artar (ekrandan, 01:25:00).

**3. Çıkış katmanının aktivasyon fonksiyonu.** Bu, ağın amacına göre belirlenir (ekrandan, 01:25:00):

- İkili sınıflandırma: sigmoid aktivasyonlu tek birim.
- Çok sınıflı sınıflandırma: $k$ birim ($k$ hedef sınıf sayısı) ve softmax aktivasyonu.
- Regresyon: aktivasyonsuz tek birim; çünkü sayısal bir çıktı üretilmek istenir.

> **Hocanın vurgusu:** Bu bölüm önemlidir; problemin türüne göre çıkış katmanında hangi aktivasyon fonksiyonunun kullanılacağını söyler.

Çok sınıflı durumda, örneğin 1000 nesneli ImageNet'te 1000 çıkış vardır ve hangisinin olma olasılığının daha yüksek olduğunu söylemek için softmax kullanılır. Softmax çıkış değerlerini, toplamları 1 olacak şekilde normalize eder; böylece her çıkış bir olasılık olarak görülebilir ve olasılığı en büyük olan tahmin edilen sınıf olarak alınır. Hoca bunu naive Bayes'te en büyük olasılıklı sınıfın seçilmesine benzetti.

**4. Kayıp fonksiyonu.** Kayıp fonksiyonu, tahmin edilen değerin gerçek değere ne kadar uyduğunu ölçer ve yine problem türüne bağlıdır:

- İkili sınıflandırma: binary cross-entropy.
- Çok sınıflı sınıflandırma: categorical cross-entropy.
- Regresyon: ortalama kare hata (mean squared error, MSE).

Regresyonun bilinen örneği ev fiyatı tahminidir: evin oda sayısı, metrekaresi gibi özellikleri bilinir ve satış fiyatı tahmin edilir. Eldeki eğitim verisinden yararlanarak bir eğri uydurma problemi gibi düşünülebilir; çıktı sayısal olduğu için kayıp fonksiyonu MSE'dir.

> **Ek bilgi (derste anlatılmadı):** İkili cross-entropy, gerçek etiket $y \in \{0,1\}$ ve tahmin edilen olasılık $\hat{y}$ için $-[y \log \hat{y} + (1-y)\log(1-\hat{y})]$ biçimindedir. Categorical cross-entropy bunun $k$ sınıflı genellemesidir: $-\sum_{c} y_c \log \hat{y}_c$; one-hot kodlu hedefte yalnız doğru sınıfın tahmini olasılığı toplama katılır. MSE ise $\frac{1}{n}\sum (y_i - \hat{y}_i)^2$'dir.

**5. Optimizer.** Ağırlıkların nasıl güncelleneceğine karar verir; amaç kaybı en hızlı şekilde en küçük yapacak parametreleri bulmaktır.

**6. Değerlendirme metrikleri.** Modelin performansını izlemek için bir ya da daha çok metrik seçilir ve ekrana yazdırılarak takip edilir.

Keras'ta ağ kurmanın iki yolu vardır: katmanları üst üste dizen sequential model ve "functional API" denen alternatif yöntem. Notebook'a göre ikincisi uygulayıcılardan çok araştırmacılar içindir.

## 10. İkili Sınıflayıcı: IMDB Film Yorumları

İkili sınıflama örneği için IMDB Large Movie Review veri seti kullanıldı. Veri seti ikili duygu sınıflaması (binary sentiment classification) içindir: insanların filmlerle ilgili yorumları, kullandıkları kelimelere göre olumlu ya da olumsuz diye etiketlenmiştir ("muhteşem bir film, çok beğendim" olumlu; "berbat, sakın izlemeyin" olumsuz). Eğitim için 25.000, test için 25.000 yorum vardır. Veri seti Keras'ın `datasets` modülünde hazırdır.

Notebook'taki kod (ekrandan, 01:35:00):

```python
number_of_features = 1000

# Load data and target vector from movie review data
(data_train, target_train), (data_test, target_test) = imdb.load_data(
    num_words=number_of_features)

# Convert movie review data to one-hot encoded feature matrix
tokenizer = Tokenizer(num_words=number_of_features)
features_train = tokenizer.sequences_to_matrix(data_train, mode="binary")
features_test = tokenizer.sequences_to_matrix(data_test, mode="binary")
print(features_train.shape)
print(features_test.shape)

# Start neural network
network = models.Sequential()

# Add fully connected layer with a ReLU activation function
network.add(layers.Dense(units=16, activation="relu", input_shape=(
    number_of_features,)))

# Add fully connected layer with a ReLU activation function
network.add(layers.Dense(units=16, activation="relu"))

# Add fully connected layer with a sigmoid activation function
network.add(layers.Dense(units=1, activation="sigmoid"))

# Compile neural network
network.compile(loss="binary_crossentropy", # Cross-entropy
    optimizer="rmsprop", # Root Mean Square Propagation
    metrics=["accuracy"]) # Accuracy performance metric
```

Yorumlar art arda yazılmış kelimelerden oluşan cümlelerdir. Farklı yorumlarda geçen her kelime bir öz nitelik (sütun) yapılır; kelime yorumda varsa o göze 1, yoksa 0 yazılır. Bütün kelimeler kullanılırsa öz nitelik sayısı çok büyük olur; bu yüzden en sık geçen kelimelerden alt kümeler alınır. `load_data(num_words=1000)` ile yalnız en sık 1000 kelime alınır. Veri `data_train`, `target_train`, `data_test`, `target_test` olarak bölünür: `data_train` yalnız örnekleri, `target_train` ise sınıf etiketlerini (bir vektör) tutar. `Tokenizer` ile kelime dizileri ikili (binary) öz nitelik matrisine çevrilir. Eğitim ve test matrislerinin boyutu $25000 \times 1000$'dir: 25.000 örnek, 1000 öz nitelik; veri eşit bölünmüştür.

Ağda dikkat edilecek nokta, ilk tam bağlı katmandaki `input_shape`'in öz nitelik sayısı (`number_of_features`) olmasıdır. Amaç olumlu/olumsuz kutupluluğunu (polarity) belirlemek olduğu için çıkışta sigmoid kullanılır. Eğitimde `fit`'e eğitim öz nitelikleri ve hedef vektörü verilir (her adımda kayıp, gerçek değerle karşılaştırılarak hesaplanır), `epochs=3`, `verbose=1` (her epoch sonunda kayıp ve doğruluğu yazdır), `batch_size=100` seçilir ve test verisi doğrulama verisi (`validation_data`) olarak verilir.

> **Ders sonrası not:** Hoca batch size için "bütün örnekleri kullanmak çok zaman aldığı için yalnız belli sayıda örnekle eğitim yapılıyor" dedi. Batch size, ağırlıkların kaç örnekte bir güncelleneceğini belirler; her epoch'ta eğitim kümesinin tamamı, bu büyüklükte gruplar halinde ağdan geçirilir. Örneğin 25.000 örnek ve `batch_size=100` ile bir epoch'ta 250 güncelleme yapılır; örneklerin bir kısmı dışarıda bırakılmaz.

Hocanın aktardığı sonuçlara göre ilk epoch sonunda eğitim kaybı 0.41, eğitim doğruluğu %81, doğrulama doğruluğu %85'tir; ikinci epoch'ta kayıp 0.32'ye düşmüş, eğitim doğruluğu 0.86'ya çıkmıştır; test verisindeki doğrulama doğruluğu daha iyi görünmektedir. <!-- BELİRSİZ: IMDB eğitim çıktısı karelerde yok; değerler altyazıdan alındı. -->

## 11. Çok Sınıflı Sınıflayıcı: Reuters Haberleri ve Softmax

### 11.1 Veri Seti ve Model

Çok sınıflı örnek için Reuters newswire sınıflama veri seti kullanıldı. Keras belgesine göre bu, 46 konu altında etiketlenmiş 11.228 Reuters haberinden oluşan bir veri setidir (ekrandan, 01:40:00). Çözüm, çıkış katmanı softmax aktivasyonlu ve 46 çıkışlı bir ileri beslemeli ağdır.

Bu da bir metin madenciliği işlemidir: her haber metninde geçen kelimeler öz nitelik olarak alınır ve en sık 5000 kelime seçilir (`number_of_features = 5000`). Her örnek bir haber metnidir; sütunlarda kelimeler vardır; kelime metinde varsa 1, yoksa 0 yazılır. Hedefler `to_categorical` ile one-hot kodlanır.

Notebook'taki model (ekrandan, 01:45:00):

```python
# One-hot encode target vector to create a target matrix
target_train = to_categorical(target_vector_train)
target_test = to_categorical(target_vector_test)
print("Target-train size", target_train.shape)
print("Target-test size", target_test.shape)

# Start neural network
network = models.Sequential()

# Add fully connected layer with a ReLU activation function
network.add(layers.Dense(units=100,
    activation="relu",
    input_shape=(number_of_features,)))

# Add fully connected layer with a ReLU activation function
network.add(layers.Dense(units=100, activation="relu"))

# Add fully connected layer with a softmax activation function
network.add(layers.Dense(units=46, activation="softmax"))

# Compile neural network
network.compile(loss="categorical_crossentropy", # Cross-entropy
    optimizer="rmsprop", # Root Mean Square Propagation
    metrics=["accuracy"]) # Accuracy performance metric
```

Giriş boyutu 5000 öz niteliktir; ilk iki tam bağlı katmanda 100'er nöron ve ReLU vardır. Çıkış katmanında birim sayısı sınıf sayısı olan 46'dır ve aktivasyon softmax'tır. Tek önemli fark, kayıp fonksiyonunun `categorical_crossentropy` olmasıdır.

> **Hocanın vurgusu:** Ara katmanlarda ReLU kullanmak sistem başarısını artırır; daha çok tercih edilir.

### 11.2 Softmax

Softmax'ı göstermek için hoca bir web görselindeki örneği kullandı: çıkış katmanında 5 çıkış ve her çıkışın aldığı değerler vardır. En büyüğü 5.1 olan ikinci çıkış olduğu için doğrudan tahmin o sınıftır; ama bunu bir olasılıkla ifade etmek için her çıkışın değerine $z_i$ denir ve

$$
\sigma(z)_i = \frac{e^{z_i}}{\sum_{j} e^{z_j}}
$$

hesaplanır. Sonuçta ikinci sınıfın olasılığı yaklaşık %90, birinci sınıfınki yaklaşık %2, üçüncü sınıfınki yaklaşık %5 gibi değerler elde edilir. <!-- BELİRSİZ: Softmax görselindeki diğer dört z değeri karelerde yok; yalnız en büyük değer (5.1) ve hocanın okuduğu olasılıklar altyazıdan alındı. --> Softmax, nöron çıkışlarındaki sayısal değerleri olasılığa çeviren basit bir matematiksel işlemdir; Reuters örneğinde 46 sınıftan hangisinin olasılığının en yüksek olduğunu söyler.

### 11.3 Sonuçlar ve One-Hot Hedef

Ekrandaki çıktıya göre (ekrandan, 01:50:00) eğitim verisi $(8982, 5000)$, test verisi $(2246, 5000)$ boyutundadır; hedef matrisleri $(8982, 46)$ ve $(2246, 46)$'dır ($8982 + 2246 = 11228$). Dört epoch boyunca:

| Epoch | loss | accuracy | val_loss | val_accuracy |
|---|---|---|---|---|
| 1/4 | 1.7816 | 0.6265 | 1.2796 | 0.7142 |
| 2/4 | 0.9448 | 0.7930 | 1.0120 | 0.7734 |
| 3/4 | 0.6446 | 0.8622 | 0.9397 | 0.7885 |
| 4/4 | 0.4590 | 0.9007 | 0.8863 | 0.8019 |

Kayıp 1.78'den 0.46'ya düşmüş, eğitim doğruluğu 0.63'ten 0.90'a, test doğruluğu 0.71'den 0.80'e yükselmiştir.

Hedef matrisinde her örnek 46 uzunluklu bir vektördür: örnek hangi sınıfa aitse o göz 1, diğerleri 0'dır. Hoca, sıfır numaralı ilk örneğin hedef vektöründe 1'in hangi gözde olduğuna bakarak sınıfını gösterdi.

## 12. Regresyon Modeli

Regresyon örneğinde scikit-learn'ün `datasets` modülündeki `make_regression` ile sentetik veri üretildi: 10.000 örnek, 3 öz nitelik, üçü de bilgilendirici (`n_informative=3`), tek hedef çıktı ve bir miktar gürültü. Veri %33 test, kalan eğitim olacak şekilde bölündü; eğitim kümesi $(6700, 3)$ boyutundadır (ekrandan, 01:55:00).

Notebook'taki model (ekrandan, 01:55:00):

```python
# Start neural network
network = models.Sequential()

# Add fully connected layer with a ReLU activation function
network.add(layers.Dense(units=32,
    activation="relu",
    input_shape=(features_train.shape[1],)))

# Add fully connected layer with a ReLU activation function
network.add(layers.Dense(units=32, activation="relu"))

# Add fully connected layer with no activation function
network.add(layers.Dense(units=1))

# Compile neural network
network.compile(loss="mse", # Mean squared error
    optimizer="RMSprop", # Optimization algorithm
    metrics=["mse"]) # Mean squared error

# Train neural network
history = network.fit(features_train, # Features
    target_train, # Target vector
    epochs=6, # Number of epochs
    verbose=1, # print output
    batch_size=100, # Number of observations per batch
    validation_data=(features_test, target_test)) # Test data

print(network.summary())
print(network.predict(features_test[0:3]))
print(target_test[0:3])
```

İlk katmanda 32 nöron vardır ve giriş boyutu öz nitelik sayısıdır (3). İkinci katmanda da 32 nöron ve ReLU vardır. Çıkış katmanında tek birim vardır ve aktivasyon fonksiyonu yoktur: regresyon problemlerinde çıkış katmanında aktivasyon kullanılmaz. Kayıp fonksiyonu MSE'dir. Regresyonda "doğruluk" denemez; ortalama kare hata izlenir. `network.summary()` ağın katmanlarını ve parametre sayısını yazdırır.

Hocanın aktardığı sonuçlara göre 6 epoch sonunda eğitim kaybı yaklaşık 14.000'den 5.900'e, doğrulama MSE'si 4529'a düşmüştür; daha çok epoch ile düşmeye devam edeceği görülmektedir. İlk üç test örneğinin tahminlerinde birinci örnek 55.25 tahmin edilmiş, gerçek değeri 87.55'tir (yaklaşık 32 fark); ikinci örnekte tahmin ve gerçek değer $-70.69$ ve $-70.97$ olup birbirine çok yakındır. <!-- BELİRSİZ: Regresyon çıktısı karelerde yok; değerler altyazıdan alındı. İkinci örnekte hangi değerin tahmin, hangisinin gerçek değer olduğu altyazıdan net değil. -->

## 13. Eğitim Geçmişi ve Aşırı Öğrenmeyi Azaltma

### 13.1 Eğitim Geçmişini Görselleştirme

IMDB veri setiyle (bu kez 10.000 öz nitelik) aynı ikili sınıflayıcı 15 epoch ve 1000'lik batch ile eğitildi; her epoch'taki eğitim ve test kaybı ile doğruluğu `history` nesnesinden alınıp epoch sayısına göre çizildi. Grafikte (ekrandan, 02:20:00) eğitim doğruluğu (kırmızı) epoch ilerledikçe yaklaşık 0.77'den 0.98'e doğru sürekli yükselirken, test doğruluğu (mavi) ilk epoch'larda 0.88 civarında en yükseğe çıkıp sonra 0.85'e doğru inmektedir.

> **Hocanın vurgusu:** Eğitim ve test doğrulukları arasındaki aralığın açılması, modelin aşırı öğrenmeye (overfitting) gittiğini gösterir.

### 13.2 Ağırlık Düzenlileştirme

Aşırı öğrenmeyi önlemenin ilk yolu kayıp fonksiyonuna bir düzenlileştirme terimi (regularization term) eklemektir. Keras'ta bu, `Dense` katmanına bir `kernel_regularizer` parametresi verilerek yapılır. Terim, bulunan bütün ağırlıkların L2 normuna göre büyüklüklerini 0.01 katsayısıyla kayba ekler. Örnekte her `Dense` katmanına bu terim eklenmiştir. Hoca bunu "sistemi biraz şaşırtarak ezberlemesinin önüne geçmek" diye anlattı.

> **Ek bilgi (derste anlatılmadı):** L2 düzenlileştirmede toplam kayıp $L = L_{\text{veri}} + \lambda \sum_j w_j^2$ biçimindedir (burada $\lambda = 0.01$). Büyük ağırlıklar cezalandırıldığı için model daha küçük ağırlıklı, daha düzgün bir fonksiyon öğrenir ve eğitim verisindeki gürültüye daha az uyar.

### 13.3 Erken Durdurma

Erken durdurmada (early stopping) epoch sayısı 20 tanımlansa bile sistem aşırı öğrenmeye gidiyorsa eğitim kendiliğinden daha önce sonlanır. Notebook'ta "erken durdurmak ve şimdiye kadarki en iyi modeli kaydetmek için callback fonksiyonu tanımla" adımıyla `EarlyStopping` ve `ModelCheckpoint` (`save_best_only`) callback'leri eklenmiştir. Hocanın aktardığı çıktıda kayıp ilk epoch'ta 0.41, ikincide 0.32, üçüncüde 0.31, sonra 0.30, 0.29, 0.28 olmuş; değişim çok küçük kaldığı için 20 yerine 6. epoch sonunda eğitim durmuştur. <!-- BELİRSİZ: Erken durdurma kodu ve çıktısı karelerde yok; değerler altyazıdan alındı. -->

### 13.4 Dropout

Dropout'u anlatmak için notebook'taki şekil kullanıldı (ekrandan, 02:25:00): solda tam bağlı bir ağ, sağda aynı ağın bazı nöronlarının çarpı ile işaretlenip devre dışı bırakıldığı hali vardır. Hoca şekli şöyle açıkladı: giriş katmanında 5 düğüm, her birinde 5 nöron olan iki gizli katman ve tek nöronlu bir çıkış katmanı vardır. Dropout her katmanda belli oranda nöronu sisteme katmaz; böylece aşırı öğrenmenin önüne geçilmeye çalışılır. Oran verilebilir: örneğin "düğümlerin %10'unu bırak (drop), kalan %90'ıyla çalış".

Örnek modelde dropout giriş katmanına da eklenmiştir. Hoca bunu öz nitelik seçimine benzetti: girişte %20 dropout, 10 öz nitelik varsa ikisinin sisteme katılmaması anlamına gelir; hangilerinin bırakılacağı rastgele seçildiği için her farklı modelde farklı sonuç çıkar. Modelde ilk katmandan sonra ReLU'lu bir `Dense` katman, ardından yine dropout, sonra bir `Dense` katman ve %50 oranlı bir dropout gelir; girişte oran %20'dir.

> **Ders sonrası not:** Hoca girişteki dropout için "bazı öz nitelikleri elemiş oluyoruz" dedi. Dropout kalıcı bir öz nitelik eleme değildir: her eğitim adımında (her batch'te) farklı, rastgele bir nöron ya da giriş alt kümesi devre dışı bırakılır; tahmin (test) sırasında bütün nöronlar kullanılır. Bu yüzden bir öz nitelik bir adımda bırakılsa da sonraki adımlarda yine öğrenmeye katılır.

## 14. Model Kaydetme, k-Katlı Çapraz Doğrulama ve Hiperparametre Arama

### 14.1 Eğitim Sürecini Kaydetme

Hesaplama adımları problemin ve verinin büyüklüğüne göre çok uzun sürebildiği için modelin eğitim aşamaları belli noktalarda kaydedilebilir ve gerektiğinde geri dönülebilir (saving model training progress). Bu örnek derste çalıştırılmadı.

### 14.2 k-Katlı Çapraz Doğrulama

Önceki örneklerde verinin %33'ü test, %67'si eğitim için ayrıldığında sabit bir eğitim ve test kümesi oluşur. k-katlı çapraz doğrulamada veri $k$ parçaya bölünür; bir parça test, kalanlar eğitim için kullanılır ve test parçası her seferinde değiştirilir. Veri 5'e bölünmüşse 5 model kurulur, her biri bir parçayla test edilir ve nihai başarı için 5 sonucun ortalaması alınır.

Örnekte iki sınıflı sentetik bir veri üretildi (binary cross-entropy kullanıldı) ve veri 3 parçaya bölündü. Hocanın aktardığı çapraz doğrulama skorları birinci parça için %90, ikinci için %77, üçüncü için %86'dır; modelin başarısı bunların ortalamasıdır: $(90 + 77 + 86)/3 \approx 84.3$ (ara adım eklendi). <!-- BELİRSİZ: Çapraz doğrulama skorları karelerde yok; altyazıdan alındı. -->

### 14.3 Hiperparametre Arama: GridSearchCV

Hoca bu bölümü kendi ilgisini çeken bir bölüm olarak tanıttı. Yapay sinir ağlarında dışarıdan verilen hiperparametreler vardır; hangi değerlerde ağın daha başarılı olduğunu bulmak için modeli her seferinde elle farklı parametrelerle çalıştırmak yerine `GridSearchCV` kullanılır.

Örnekte `make_classification` ile iki sınıflı, dengeli (her sınıftan %50) sentetik veri üretilir (ekrandan, 02:30:00):

```python
# Number of features
number_of_features = 100

# Generate features matrix and target vector
features, target = make_classification(n_samples = 10000,
    n_features = number_of_features,
    n_informative = 3,
    n_redundant = 0,
    n_classes = 2,
    weights = [.5, .5],
    random_state = 0)

# Create function returning a compiled network
def create_network():
    # Start neural network
    network = models.Sequential()
    # Add fully connected layer with a ReLU activation function
    network.add(layers.Dense(units=16, activation="relu", input_shape=(
        number_of_features,)))
    # Add fully connected layer with a ReLU activation function
    network.add(layers.Dense(units=16, activation="relu"))
    # Add fully connected layer with a sigmoid activation function
    network.add(layers.Dense(units=1, activation="sigmoid"))
    # Compile neural network
    network.compile(loss="binary_crossentropy", # Cross-entropy
        optimizer="rmsprop", # Root Mean Square Propagation
        metrics=["accuracy"]) # Accuracy performance metric
    # Return compiled network
    return network
```

<!-- BELİRSİZ: Bu kare k-katlı çapraz doğrulama ile GridSearchCV anlatımlarının geçiş anına denk geliyor; kodun hangi örneğe ait olduğu kesin değil. GridSearchCV örneğinde create_network fonksiyonu optimizer'ı parametre olarak alır. -->

Denenmek istenen seçenekler:

- Epoch sayısı: 5 ve 10
- Batch size: 5, 10 ve 100
- Optimizer: `rmsprop` (Root Mean Square Propagation) ve `adam`

Bu seçenekler bir sözlüğe (dictionary) yazılır; `GridSearchCV` bütün bileşimlerle ağı eğitir ve en iyisini bulur. Bu, işlemleri elle yapmaya göre çok hızlandırır. Örnek uzun süreceği için derste çalıştırılmadı.

> **Ek bilgi (derste anlatılmadı):** Bu ızgarada $2 \times 3 \times 2 = 12$ parametre bileşimi vardır. `GridSearchCV` her bileşimi kendi içinde çapraz doğrulamayla değerlendirdiği için, örneğin 3 katlı doğrulamada toplam $12 \times 3 = 36$ eğitim yapılır; arama süresinin uzun olmasının nedeni budur.

Notebook'ta ayrıca ağların görselleştirilmesi için hazır çözümler yer alır; bu kısım geçildi.

## 15. Konvolüsyon İşlemi

Görüntü sınıflamaya geçmeden önce, konvolüsyonu bilmeyenler olduğu için hoca tablet üzerinde küçük bir örnek gösterdi (ekrandan, 02:40:00).

### 15.1 Görüntü Matrisi ve Çekirdek

Gri seviyeli (grayscale) bir görüntüde her piksel 0-255 arasında bir parlaklık değeri alır: 0 siyah, 255 beyazdır; aradaki değerler gri seviyeleridir. Renkli görüntüye genişletmek mümkündür. Tahtadaki görüntü matrisi (ekrandan, 02:40:00):

$$
I = \begin{bmatrix}
2 & 3 & 15 & 12 & 20 \\
4 & 7 & 2 & 1 & 0 \\
3 & 4 & 1 & 2 & 10 \\
5 & 2 & 55 & 76 & 255
\end{bmatrix}
$$

Çekirdek (kernel) $3 \times 3$ boyutunda ve bütün gözleri 1 olan bir filtredir. Bütün gözleri 1 olan filtreye **ortalama filtresi** (average filter) denir. Çekirdeğin önüne $1/9$ katsayısı yazılır, çünkü 9 gözden oluşur (ekrandan, 02:45:00):

$$
K = \frac{1}{9}\begin{bmatrix} 1 & 1 & 1 \\ 1 & 1 & 1 \\ 1 & 1 & 1 \end{bmatrix}
$$

### 15.2 İşlem Adımları

Konvolüsyonda çekirdek görüntünün üzerine birebir bindirilir, örtüşen gözlerin değerleri çarpılıp toplanır ve sonuç çekirdeğin merkezine karşılık gelen çıkış pikseline yazılır. Ortalama filtresinde bu, dokuz değeri toplayıp 9'a bölmek demektir. Sonra çekirdek bir göz kaydırılır ve aynı işlem yeni bölge için tekrarlanır. Tahtada ilk konum sol üst $3\times3$ bölge, ikinci konum bir sütun sağa kaydırılmış bölge olarak işaretlendi (ekrandan, 02:45:00). Bu iki konumun sayısal sonucu derste hesaplanmadı; hesap Örnek Sorular bölümündedir.

Konvolüsyonun tanımında çekirdeğin $x$ ve $y$ doğrultusunda aynalanması (180 derece döndürülmesi) vardır. Ama kullanılan filtreler genellikle simetrik olduğu için aynalama sonucu değiştirmez; bu yüzden anlatımlarda bu adım çoğunlukla atlanır.

### 15.3 Kenar Pikseller ve Padding

Çıkış, çekirdeğin merkezine yazıldığı için $3\times3$ bir filtre kenar pikseller için sonuç üretemez; çıkış görüntüsü giriş görüntüsünden küçük olur. Bunu önlemek için kenar piksellerin değerleri görüntünün dışına eklenir (padding). Tahtada bu, görüntünün çevresine kenar değerlerin kopyalandığı yeşil bir çerçeve olarak çizildi (ekrandan, 02:45:00). Padding ile giriş görüntüsüyle aynı boyutta çıkış elde edilir.

Filtreler $3\times3$, $5\times5$ gibi bir merkez noktası tanımlanabilecek boyutlarda olmalıdır. Filtre katsayıları değiştirilerek farklı öz nitelikler üretilebilir.

> **Ek bilgi (derste anlatılmadı):** Dolgusuz ve bir adımlı (stride 1) konvolüsyonda $H \times W$ boyutlu bir görüntü ve $k \times k$ çekirdek için çıkış boyutu $(H-k+1) \times (W-k+1)$'dir. Tahtadaki $4 \times 5$ görüntü ve $3 \times 3$ çekirdekte çıkış $2 \times 3$ olur. Her yandan $(k-1)/2$ piksel dolgu eklenirse çıkış girişle aynı boyutta kalır.

## 16. CNN ile Görüntü Sınıflama: MNIST

### 16.1 Veri Seti ve Ön İşleme

MNIST, 0'dan 9'a kadar el yazısı rakamlardan oluşan büyük bir veri setidir. Hoca, rakamların insanların doldurduğu formlardaki küçük kutulara elle yazılmış sayılardan toplandığını anlattı. Amaç, görüntüdeki rakamı tanıyan bir model kurmaktır.

Kodda kullanılan katmanlar: iki boyutlu konvolüsyon (Conv2D), max pooling, dropout, flatten ve dense. **Flatten**, bir matristeki değerleri vektöre çevirir: önce birinci satır vektöre konur, ikinci satır arkasına eklenir (concatenate) ve böyle devam edilerek tek boyutlu hale getirilir.

Ön işleme adımları:

- Görüntü veri biçimi tanımlanır ve görüntüler $28 \times 28$ boyutuna getirilir (`reshape`).
- Gri seviye değerler 0-255 arasında olduğu için 255'e bölünerek 0-1 aralığına normalize edilir: `features_test = data_test / 255` (ekrandan, 02:50:00).
- Rakamlar 10 sınıf demektir; bu bir çok sınıflı sınıflama problemidir. Hedefler one-hot kodlanır: sınıf etiketi 3 ise 10 uzunluklu vektörün 3 numaralı gözü 1, diğerleri 0 yapılır.

> **Ders sonrası not:** Hoca görüntülerin "7'ye 7 ya da 8'e 8" olup $28 \times 28$'e büyütüldüğünü söyledi. Keras'taki MNIST görüntüleri büyük olasılıkla zaten $28 \times 28$ boyutundadır (eğitimde 60.000, testte büyük olasılıkla 10.000 görüntü); koddaki `reshape` yalnız kanal boyutunu ekleyerek Conv2D'nin beklediği biçime getirir. $8 \times 8$ boyutlu el yazısı rakamlar scikit-learn'ün ayrı `digits` veri setine aittir. MNIST büyük olasılıkla ABD Ulusal Standartlar ve Teknoloji Enstitüsü'nün (NIST) formlarından derlenmiştir.

### 16.2 Ağ Yapısı

Notebook'taki ağ (ekrandan, 02:50:00):

```python
# One-hot encode target
target_train = np_utils.to_categorical(target_train)
target_test = np_utils.to_categorical(target_test)
number_of_classes = target_test.shape[1]

# Start neural network
network = Sequential()

# Add convolutional layer with 64 filters, a 5x5 window, and ReLU activation function
network.add(Conv2D(filters=64,
    kernel_size=(5, 5),
    input_shape=(channels, width, height),
    activation='relu'))

# Add max pooling layer with a 2x2 window
network.add(MaxPooling2D(pool_size=(2, 2)))

# Add dropout layer
network.add(Dropout(0.5))

# Add layer to flatten input
network.add(Flatten())

# # Add fully connected layer of 128 units with a ReLU activation function
network.add(Dense(128, activation="relu"))
```

Ardından yine bir dropout ve çıkış katmanı gelir: çıkıştaki nöron sayısı sınıf sayısıdır (10) ve aktivasyon softmax'tır. <!-- BELİRSİZ: İkinci dropout ve çıkış katmanı satırları karelerde görünmüyor; altyazıdan alındı. --> Derleme ve eğitim (ekrandan, 02:55:00):

```python
# Compile neural network
network.compile(loss="categorical_crossentropy", # Cross-entropy
    optimizer="rmsprop", # Root Mean Square Propagation
    metrics=["accuracy"]) # Accuracy performance metric

# Train neural network
network.fit(features_train, # Features
    target_train, # Target
    epochs=2, # Number of epochs
    verbose=0, # Don't print description after each epoch
    batch_size=1000, # Number of observations per batch
    validation_data=(features_test, target_test)) # Data for evaluation
```

Katmanların açıklaması:

- **Conv2D:** 64 farklı filtre kullanılır; her filtre $5 \times 5$ boyutundadır ve katsayıları rastgele başlatılır. `input_shape` giriş görüntüsünün kanal sayısını (gri seviye ya da renkli) ve boyutlarını verir. Aktivasyon ReLU'dur. 64 filtre olduğu için bu katman 64 çıkış (öz nitelik haritası) üretir.
- **MaxPooling2D ($2 \times 2$):** her $2 \times 2$ bölgedeki en büyük sayıyı alıp çıkışa yazar. $2 \times 2$ alan 1 değere indiği için görüntü yarı yarıya küçülür.
- **Flatten:** öz nitelik haritalarını bir vektöre yerleştirir.
- **Dense (128, ReLU):** tam bağlı katman.
- **Çıkış:** sınıf sayısı kadar nöron ve softmax; kayıp `categorical_crossentropy`.

Eğitim tamamlanınca eğitim verisi 60.000 görüntüden, hedef matrisi $60000 \times 10$ boyutundan oluşur. Hoca sıfır numaralı örneğin hedef vektörüne bakarak 3 numaralı gözün 1 olduğunu, yani rakamın 3 olduğunu gösterdi ve görüntüyü büyütülmüş olarak ekrana çizdirdi. Sonrasında ağ eğitilip skoruna, yani ne kadar doğru tahmin ettiğine bakılabilir.

> **Ders sonrası not:** Hoca MNIST eğitiminde de `batch_size=1000` için "1000 örnek eğitimde kullanılacak" dedi. Burada da batch size, ağırlık güncellemesi başına kullanılan örnek sayısıdır; iki epoch'un her birinde 60.000 eğitim görüntüsünün tamamı 1000'lik gruplar halinde ağdan geçer.

### 16.3 Veri Artırma

Notebook'un devamında görüntüleri çeşitlendirmek için veri artırma (image/data augmentation) anlatılır. Veri az olduğunda tercih edilir: örneklere gürültü eklenir, görüntüler örneğin 10 ya da 20 derece döndürülür. Böylece eğri yazılmış rakamlar gibi durumlarda da tanıma başarısı artırılmak istenir.

## 17. Soru-Cevaptan Akademik Notlar

Dersin sonundaki soru-cevapta veri setleriyle ilgili bazı genel akademik noktalar da konuşuldu:

- **Dengesiz veri setleri:** sınıf dağılımı dengesiz (imbalanced) olan veri setlerinde doğruluk (accuracy) yerine precision ve recall önem kazanır; ikisini ayrı ayrı değerlendirmek yerine F1 skoru kullanılabilir.
- **İkili öz nitelikler ve aykırı değer:** öz nitelikler yalnız ikili (binary) değerlerden oluşuyorsa aykırı değer (outlier) hesaplamak pek mümkün değildir.
- **Görüntüyü vektör olarak kullanmak:** görüntüler iki boyutlu matris yerine flatten edilip bir vektör olarak da modele giriş olarak verilebilir.
- **Zaman serisi:** birden çok sensörden gelen zaman serisi verileri art arda eklenerek (concatenate) kullanılabilir; ama hoca bunun çok iyi bir yol olmadığını belirtti, zaman serileriyle çalışmak ayrı bir konudur.

## Örnek Sorular

**Soru 1** (ekrandan, 00:50:00): Girişleri $X_1, X_2, X_3$, ağırlıkları 0.3, bias değeri $t = 0.4$ olan tek nöronlu modelde $Y = I(0.3X_1 + 0.3X_2 + 0.3X_3 - 0.4 > 0)$'dır. Bu model, Bölüm 7'deki 8 örnekli tablonun $Y$ etiketlerini doğru üretir mi?

> **Çözüm (derste verilmedi):** Ağırlıklı toplam $0.3 \times (\text{1 olan giriş sayısı}) - 0.4$'tür. Bir giriş 1 ise $-0.1$, iki giriş 1 ise $0.2$, üç giriş 1 ise $0.5$, hiçbiri 1 değilse $-0.4$ çıkar. Pozitif olanlar (en az iki girişi 1 olan satırlar) $Y = 1$, diğerleri $Y = 0$ verir. Tablodaki 8 satırın hepsinde bu sonuç gerçek etiketle aynıdır (python ile kontrol edildi). Model, "girişlerin en az ikisi 1 ise 1" kuralını öğrenmiştir.

**Soru 2** (derste sözlü, 01:43:29): Reuters haber sınıflama ağının ilk katmanındaki `input_shape` nedir?

**Cevap:** Bir öğrenci 46 dedi; hoca bunun sınıf sayısı olduğunu düzeltti. Öz nitelikler en sık kullanılan 5000 kelimedir, bu yüzden ilk katmanın giriş boyutu `number_of_features`, yani 5000'dir. 46 ise çıkış katmanındaki birim sayısıdır.

**Soru 3** (derste sözlü, 01:53:32): Regresyon ağında giriş boyutundaki öz nitelik sayısı nedir ve ilk `Dense` katmanında kaç düğüm vardır?

**Cevap:** Sentetik veride 3 öz nitelik vardır, dolayısıyla giriş boyutu 3'tür. İlk `Dense` katmanında 32 nöron vardır ve aktivasyon ReLU'dur (ekrandan, 01:55:00).

**Soru 4** (ekrandan, 02:40:00 ve 02:45:00): Tahtadaki $4 \times 5$ görüntü matrisi $I$ ile $3 \times 3$ ortalama filtresi $K$'nin, dolgusuz konvolüsyon sonucunu hesaplayın.

> **Çözüm (derste verilmedi):** Çıkış $(4-3+1) \times (5-3+1) = 2 \times 3$ boyutundadır. Her çıkış, ilgili $3\times3$ bölgedeki dokuz değerin ortalamasıdır.
>
> - Sol üst bölge (tahtada işaretlenen ilk konum): $2+3+15+4+7+2+3+4+1 = 41$, $41/9 \approx 4.56$.
> - Bir sütun sağa kaydırılmış bölge (tahtadaki ikinci konum): $3+15+12+7+2+1+4+1+2 = 47$, $47/9 \approx 5.22$.
> - Üçüncü sütun bölgesi: $15+12+20+2+1+0+1+2+10 = 63$, $63/9 = 7.00$.
> - İkinci satır bölgeleri: $83/9 \approx 9.22$, $150/9 \approx 16.67$, $402/9 \approx 44.67$.
>
> $$
> I * K \approx \begin{bmatrix} 4.56 & 5.22 & 7.00 \\ 9.22 & 16.67 & 44.67 \end{bmatrix}
> $$
>
> (python ile kontrol edildi). Giriş boyutunda çıkış istenirse, kenar değerleri çevreye kopyalanarak padding yapılır.

## Dersin Toparlaması

Bu derste, dönem boyunca görülen sınıflandırma ve regresyon problemlerinin yapay sinir ağlarıyla nasıl çözüldüğü teoriden uygulamaya kadar anlatıldı. Teorik kısımda bir nöronun ağırlıklı toplam ve aktivasyon fonksiyonundan oluşan yapısı, gizli katmanlı ağ topolojileri, kare hatayı en küçük yapan ağırlıkların gradient descent ile bulunması ve sigmoid fonksiyonu işlendi; tek nöronlu bir kara kutu örneğinin tablodaki etiketleri nasıl ürettiği gösterildi.

Uygulama kısmında Keras ile ikili (IMDB), çok sınıflı (Reuters) ve regresyon modelleri kuruldu; problem türüne göre çıkış aktivasyonu (sigmoid, softmax, aktivasyonsuz) ve kayıp fonksiyonu (binary cross-entropy, categorical cross-entropy, MSE) eşleşmesi öne çıkarıldı. Ardından aşırı öğrenmeye karşı L2 düzenlileştirme, erken durdurma ve dropout; model değerlendirmede k-katlı çapraz doğrulama ve GridSearchCV ile hiperparametre arama görüldü. Son olarak konvolüsyon işlemi tablette bir ortalama filtresi örneğiyle anlatıldı ve MNIST üzerinde konvolüsyon, max pooling, flatten ve tam bağlı katmanlardan oluşan bir CNN kuruldu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
