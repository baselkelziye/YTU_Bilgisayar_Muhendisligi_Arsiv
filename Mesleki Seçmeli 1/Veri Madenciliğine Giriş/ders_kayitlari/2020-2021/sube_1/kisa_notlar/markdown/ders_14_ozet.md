# Ders 14 Çalışma Özeti

## Genel Konular

- Yapay sinir ağlarına giriş
  - Yapay sinir ağları insan beyninden esinlenen hesaplama modelleridir: basit işlem birimlerinden (nöronlar) oluşan, büyük ölçüde paralel ve dağıtık bir sistemdir; öğrenilen bilgi nöronlar arasındaki bağlantı güçlerinde (ağırlıklarda) saklanır ve bir öğrenme süreciyle elde edilir (ekrandan, 00:20:00).
  - Teori eskidir (60'lı, 70'li yıllar; 1986'da geri yayılım/backpropagation algoritması), ancak güçlü hesaplama altyapıları sayesinde katman sayısı artırılarak daha derin yapılar kurulabildiği için son yıllarda yeniden yaygınlaşmıştır.
  - Başlıca kullanım alanları örüntü tanıma (nesne tespiti, nesne tanıma) ve fonksiyon yaklaşımıdır (sayısal bir çıktıya yakınsamak).
- Perceptron (tek nöron)
  - Sinir ağının temel birimidir ve doğrusal bir ayırıcıdır (ekrandan, 00:25:00).
  - Parçaları: $n$ giriş $x_1 \dots x_n$, her girişin ağırlığı $w_1 \dots w_n$, sabit bir bias girişi $x_0$ ve ona bağlı $w_0$ ağırlığı, ağırlıklı toplam $y = w_0x_0 + w_1x_1 + \dots + w_nx_n$ ve bir eşik (aktivasyon) fonksiyonu.
  - Giriş vektörü veri madenciliğindeki bir örneği (sample) temsil eder; $n$ öz nitelik sayısıdır. Bias ayrı bir $t$ değeri olarak toplamdan da çıkarılabilir: $\sum_i w_i x_i - t$.
- Ağ topolojileri
  - Tek katmanlı ileri beslemeli ağ: giriş katmanı doğrudan çıkış katmanına bağlanır.
  - Çok katmanlı ileri beslemeli ağ: bir ya da daha çok gizli katman vardır; her katman yalnız önceki katmandan giriş alır. Bir gizli katmanlı ağa "2 katmanlı" ya da "1 gizli katmanlı tam bağlı (fully connected) ağ" denir (ekrandan, 00:30:00).
  - Gizli katman sayısı ve her katmandaki nöron sayısı modeli kuran kişi tarafından seçilir. Çok sınıflı problemde çıkış birimi sayısı sınıf sayısına eşittir (ör. 1000 nesneli ImageNet için 1000 çıkış).
  - Tekrarlayan (recurrent) ağlarda bir katmandaki düğümün çıkışı aynı katmandaki başka bir düğüme giriş olabilir.
- Ağın öğrenmesi
  - Ağırlıklar rastgele başlatılır, sonra ağın çıktısı eğitim örneklerinin sınıf etiketleriyle tutarlı olacak şekilde ayarlanır (ekrandan, 00:35:00).
  - Hata fonksiyonu: $E = \sum_i [Y_i - f(w_i, X_i)]^2$. Amaç bu hatayı en küçük yapan $w_i$ ağırlıklarını bulmaktır (ör. gradient descent, backpropagation).
  - Gradyan: $\nabla_{\mathbf{w}} l(\mathbf{w}) = [\partial l/\partial w_0, \dots, \partial l/\partial w_d]$. Güncelleme: $\Delta \mathbf{w} = \eta \nabla_{\mathbf{w}} l(\mathbf{w})$, $\eta > 0$ öğrenme oranı. Konkav fonksiyonun maksimumu konveks fonksiyonun minimumuna denktir: konkav için gradient ascent ($+$), konveks için gradient descent ($-$) (ekrandan, 00:40:00).
  - Batch perceptron algoritması: ağırlıkları rastgele başlat, eğitim örnekleri ($i = 1..R$) ve öz nitelikler ($j = 1..m$) üzerinden hatayı hesapla, ağırlıkları güncelle; hata bir eşiğe inene ya da belirlenen döngü sayısına ulaşılana kadar tekrarla.
- Aktivasyon fonksiyonları
  - Sigmoid: $g(h) = \dfrac{1}{1 + e^{-h}}$; $h = 0$ için $0.5$ verir, çıkışı $(0,1)$ aralığına sıkıştırır (ekrandan, 00:45:00). İkili sınıflayıcının çıkışında kullanılır.
  - ReLU (Rectified Linear Unit): $f(z) = \max(0, z)$; negatif değerleri 0'a kilitler, pozitif değerleri olduğu gibi geçirir (ekrandan, 01:20:00). Gizli katmanlarda tercih edilir.
  - Softmax: çok sınıflı çıkışta her çıkışı $e^{z_i} / \sum_j e^{z_j}$ ile olasılığa çevirir; olasılıkların toplamı 1'dir.
- Çözümlü kara kutu örneği (ekrandan, 00:50:00)
  - Üç ikili girişli, 8 örnekli veri seti ve $Y = I(0.3X_1 + 0.3X_2 + 0.3X_3 - 0.4 > 0)$ modeli; $I(z)$, $z$ doğruysa 1, değilse 0'dır. Model tablodaki 8 etiketin hepsini doğru üretir (ders sonrası python ile kontrol edildi).
- Keras ile uygulama (Machine Learning with Python Cookbook, 20. bölüm, Jupyter Notebook)
  - Ön işleme: `StandardScaler` ile standart sapma normalizasyonu; sonuç sıfır ortalamalı, standart sapması yaklaşık 1 olan veridir.
  - `models.Sequential()` ile katmanlar art arda eklenir; ilk `Dense` katmanında `input_shape` öz nitelik sayısıdır, sonraki katmanlarda gerekmez (ekrandan, 01:15:00).
  - `compile` adımında kayıp fonksiyonu, optimizer (ör. `rmsprop`, `adam`) ve izlenecek metrik seçilir; `fit` adımında epoch sayısı, batch size ve doğrulama verisi verilir.
- Problem türüne göre çıkış katmanı ve kayıp fonksiyonu (ekrandan, 01:25:00)
  - İkili sınıflandırma: tek birim, sigmoid; kayıp binary cross-entropy.
  - Çok sınıflı sınıflandırma: $k$ birim (sınıf sayısı), softmax; kayıp categorical cross-entropy.
  - Regresyon: tek birim, aktivasyon yok; kayıp ortalama kare hata (MSE).
- Dört örnek model
  - İkili: IMDB film yorumları (olumlu/olumsuz), en sık 1000 kelime ikili öz nitelik, 16-16-1 birimli ağ (ekrandan, 01:35:00).
  - Çok sınıflı: Reuters haberleri (11.228 haber, 46 konu), 5000 kelime öz nitelik, 100-100-46 birimli ağ, softmax (ekrandan, 01:40:00, 01:45:00).
  - Regresyon: `make_regression` ile 10.000 örnek ve 3 öz nitelikli sentetik veri, 32-32-1 birimli ağ, MSE (ekrandan, 01:55:00).
  - Görüntü: MNIST el yazısı rakamlar, Conv2D + MaxPooling + Dropout + Flatten + Dense + softmax (ekrandan, 02:50:00).
- Aşırı öğrenmeyi (overfitting) azaltma
  - Eğitim geçmişini görselleştirme: eğitim doğruluğu artarken test doğruluğunun düşmesi ve aradaki açıklığın büyümesi aşırı öğrenmeyi gösterir (ekrandan, 02:20:00).
  - Ağırlık düzenlileştirme (weight regularization): kayıp fonksiyonuna ağırlıkların L2 normuna bağlı, 0.01 katsayılı bir terim eklenir.
  - Erken durdurma (early stopping): kayıp artık anlamlı azalmıyorsa eğitim belirlenen epoch sayısından önce durdurulur ve en iyi model kaydedilir.
  - Dropout: her katmanda belli oranda nöron devre dışı bırakılır (ekrandan, 02:25:00).
- Diğer konular
  - Eğitim sürecinin kaydedilmesi (checkpoint), k-katlı çapraz doğrulama, `GridSearchCV` ile hiperparametre ayarı, veri artırma (data augmentation).
- Konvolüsyon ve CNN
  - Konvolüsyon: çekirdek (kernel) görüntü üzerine bindirilir, karşılıklı değerler çarpılıp toplanır, sonuç çekirdeğin merkezine karşılık gelen çıkış pikseline yazılır; çekirdek kaydırılarak işlem tekrarlanır (ekrandan, 02:40:00, 02:45:00).
  - Tüm elemanları 1 olan $3\times3$ çekirdek ($1/9$ katsayılı) ortalama filtresidir.
  - Kenar piksellerde çıkış üretilemediği için çıkış görüntüsü küçülür; padding ile giriş boyutunda çıkış elde edilir.
  - Max pooling ($2\times2$) her bölgedeki en büyük değeri alır ve görüntüyü yarıya küçültür. Flatten matrisi satır satır art arda ekleyerek vektöre çevirir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Çıkış katmanındaki aktivasyon problem türüne göre seçilir
  - İkili sınıflamada sigmoid, çok sınıflıda softmax, regresyonda aktivasyonsuz tek birim; hoca bu bölümün önemli olduğunu ayrıca belirtti.
- Kayıp fonksiyonu da problem türüne bağlıdır
  - Binary cross-entropy, categorical cross-entropy ve MSE eşleşmesi doğru kurulmalıdır.
- İlk katmandaki `input_shape` öz nitelik sayısıdır
  - Hoca Reuters örneğinde bunu sordu: girişin boyutu sınıf sayısı (46) değil, öz nitelik (kelime) sayısıdır (5000).
- ReLU'nun önemi
  - Gizli katmanlarda sigmoid yerine ReLU kullanılması başarıyı artırmıştır ve derin ağların yaygınlaşmasının nedenlerinden biridir.
- Katmanlar arası uyum
  - Ardışık modelde bir katmanın çıkış sayısı sonraki katmanın giriş sayısıyla tutarlı olmalıdır.
- Teoriyi bilmek
  - Hazır kütüphaneleri kullanırken arkadaki matematiği bilmek, modelde iyileştirme yapabilmeyi sağlar.

## Kısa Tekrar Notları

- Nöron: $\text{çıkış} = g\left(\sum_{i=0}^{n} w_i x_i\right)$; $x_0$ sabit bias girişi, $w_0$ bias ağırlığı.
- Hata: $E = \sum_i [Y_i - f(w_i, X_i)]^2$; ağırlıklar gradient descent ile güncellenir, $\eta$ küçük pozitif öğrenme oranıdır.
- Öğrenme oranı çok büyükse minimum ıskalanabilir.
- Sigmoid $(0,1)$ aralığı; ReLU $\max(0,z)$; softmax olasılık dağılımı.
- İkili: sigmoid + binary cross-entropy. Çok sınıflı: softmax + categorical cross-entropy. Regresyon: aktivasyonsuz + MSE.
- Çok sınıflı hedefler one-hot kodlanır: doğru sınıfın gözü 1, diğerleri 0.
- Aşırı öğrenmeye karşı: L2 düzenlileştirme, erken durdurma, dropout.
- k-katlı çapraz doğrulamada başarı, $k$ test parçasının ortalamasıdır.
- `GridSearchCV` epoch, batch size ve optimizer seçeneklerinin bütün bileşimlerini otomatik dener.
- CNN'de öz nitelikler konvolüsyon filtreleriyle otomatik çıkarılır; ardından flatten ve tam bağlı katmanlar gelir.
- Dengesiz veri setlerinde doğruluk yerine precision, recall ya da F1 skoru daha anlamlıdır.

## Detaylı Açıklamalar

Dersin ilk bölümünde yapay sinir ağlarının teorik temeli slaytlarla anlatıldı. Bir nöron (perceptron), bir örneğin öz niteliklerini giriş olarak alır, her girişi bir ağırlıkla çarpar, bunları toplar ve sonucu bir aktivasyon fonksiyonundan geçirir. Bias, sabit bir $x_0$ girişi ve ona bağlı $w_0$ ağırlığı olarak toplamın içine alınabilir ya da ayrı bir $t$ eşiği olarak toplamdan çıkarılabilir. Slayttaki kara kutu örneğinde (ekrandan, 00:50:00) üç girişin her biri 0.3 ağırlıkla bağlanmış, eşik $t = 0.4$ alınmıştır. Örneğin $(X_1, X_2, X_3) = (1, 0, 1)$ için toplam $0.6 - 0.4 = 0.2 > 0$ olduğundan $Y = 1$; $(1, 0, 0)$ için $0.3 - 0.4 = -0.1$ olduğundan $Y = 0$ olur. Model, en az iki girişi 1 olan örneklerde 1 üretir ve tablodaki bütün etiketlerle tutarlıdır.

Ağın öğrenmesi bir optimizasyon problemidir. Gerçek etiket $Y_i$ ile ağın ürettiği $f(w, X_i)$ arasındaki farkların kareleri toplamı hata fonksiyonudur. Bu fonksiyon konveks (tek minimumlu) ise türev yönünde adımlarla minimuma ulaşmak kolaydır. Ağırlık her iterasyonda $w_i^{(t+1)} = w_i^{(t)} - \eta \, \partial l / \partial w_i$ biçiminde güncellenir; slaytta gösterilen $+$ işaretli kural, konkav fonksiyonun maksimumunu arayan gradient ascent kuralıdır (ekrandan, 00:40:00). Öğrenme oranı küçük seçilir; hoca uygulamada binde bir, on binde bir gibi değerlerin kullanıldığını, büyük seçilirse minimumun ıskalanabileceğini ve bazen dinamik ayarlandığını söyledi.

Uygulama bölümünde Keras ile dört model kuruldu. Her modelde ortak adımlar şunlardır: `Sequential` model başlatılır, `Dense` katmanlar `add` ile eklenir, `compile` ile kayıp, optimizer ve metrik seçilir, `fit` ile eğitim yapılır. İkili sınıflama (IMDB) için çıkışta sigmoid ve binary cross-entropy, çok sınıflı sınıflama (Reuters, 46 sınıf) için softmax ve categorical cross-entropy, regresyon için aktivasyonsuz tek birim ve MSE kullanıldı. Reuters örneğinde 4 epoch sonunda eğitim kaybı 1.7816'dan 0.4590'a inmiş, eğitim doğruluğu 0.6265'ten 0.9007'ye, doğrulama doğruluğu 0.7142'den 0.8019'a çıkmıştır (ekrandan, 01:50:00). Regresyonda doğruluk değil ortalama kare hata izlenir.

Dersin son kısmında aşırı öğrenmeye karşı yöntemler ve CNN anlatıldı. Eğitim doğruluğu yükselirken test doğruluğunun düşmesi aşırı öğrenmenin işaretidir; L2 düzenlileştirme, erken durdurma ve dropout bunu azaltır. Konvolüsyon, tablet üzerinde $3\times3$ ortalama filtresiyle gösterildi: çekirdek görüntünün sol üst köşesine bindirilir, dokuz değer toplanıp 9'a bölünür ve sonuç merkez piksele yazılır; sonra çekirdek bir sütun kaydırılır. CNN'de birçok farklı filtrenin çıkardığı öz nitelik haritaları, insanın elle tasarlayacağı kenar ve köşe öz niteliklerinin yerini alır; bu haritalar flatten ile vektöre çevrilip tam bağlı katmanlara verilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
