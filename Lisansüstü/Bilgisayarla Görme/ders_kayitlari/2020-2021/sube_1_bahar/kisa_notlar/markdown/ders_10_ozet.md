# Ders 10 Çalışma Özeti

## Genel Konular

- Derin öğrenmede eğitim döngüsü
  - Etiketli veriden küçük bir parça (batch) alınır, ağdan ileri geçirilip tahmin üretilir, hata geri yayılır (backpropagation) ve ağ ağırlıkları güncellenir; döngü tekrarlanır (ekrandan, 00:20:00).
  - Amaç bir amaç/maliyet fonksiyonunu ($J(\theta)$) en küçüklemek (ya da en büyüklemek) ve tahmin ile hedef arasındaki farkı ölçen hata sinyalini azaltmaktır. Gradyanın bir kesri çıkarılarak maliyet fonksiyonunun (yerel) minimumuna doğru ilerlenir.
  - Kullanılan optimizasyon yöntemleri: stokastik gradyan inişi (SGD), momentum, Adam (Adaptive Moment Estimation) vb. Slayttaki grafikte SGD, Momentum, NAG, Adagrad, Adadelta ve RMSprop karşılaştırılıyor (ekrandan, 00:20:00).
- Doğrusal skor fonksiyonu $f(x, W) = Wx + b$
  - CIFAR-10 görüntüsü $32\times32\times3$ boyutundadır; düzleştirilince $x$ vektörü $3072\times1$ olur (ekrandan, 00:25:00).
  - 10 sınıf için skor vektörü $10\times1$ olacağından ağırlık matrisi $W$ $10\times3072$ boyutundadır. $W$'nin her satırı $x$ ile çarpılıp bias eklenerek bir sınıfın skoru bulunur.
  - Ağırlık matrisindeki değerler ve bias değerleri öğrenilebilir parametrelerdir.
  - $x$ vektörü ham görüntünün satırları art arda eklenerek ya da evrişim katmanlarıyla çıkarılan öznitelik haritasının düzleştirilmesiyle elde edilebilir.
- Çok sınıflı SVM kaybı (hinge loss)
  - $L_i = \sum_{j \ne y_i} \max(0,\; s_j - s_{y_i} + 1)$ (ekrandan, 00:35:00). $s_j$ yanlış sınıfın skoru, $s_{y_i}$ doğru sınıfın skorudur.
  - Toplam kayıp bütün örneklerin ortalamasıdır: $L = \frac{1}{N}\sum_{i=1}^{N} L_i$.
  - Üç örnekli, üç sınıflı örnekte kayıplar kedi için 2.9, araba için 0, kurbağa için 12.9'dur (slaytta yanlışlıkla 10.9 yazıyor; ayrıntı aşağıda).
  - NumPy ile vektörel biçimde hesaplanabilir: skorlardan doğru sınıfın skoru çıkarılır, 1 eklenir, sıfırla karşılaştırılır, doğru sınıfın gözü sıfırlanır ve toplanır.
- Stokastik gradyan inişi örneği (doğru uydurma)
  - $\hat{y} = w_1 + w_2 x$ doğrusu en küçük kareler ile uydurulur; amaç fonksiyonu $Q(w) = \sum_{i=1}^{n}(w_1 + w_2 x_i - y_i)^2$ (ekrandan, 00:50:00).
  - Güncelleme: $w_1 := w_1 - \eta\, 2(w_1 + w_2 x_i - y_i)$, $w_2 := w_2 - \eta\, 2x_i(w_1 + w_2 x_i - y_i)$. $\eta$ öğrenme oranıdır.
  - SGD'de her adımda tüm örnekler yerine rastgele seçilen tek bir örnekteki gradyan kullanılır.
- Aşırı öğrenme ve düzenlileştirme (regularization)
  - Eğitim doğruluğu artarken doğrulama (validation) doğruluğu aynı paralelde artmıyorsa aradaki açıklık aşırı öğrenmeyi (overfitting) gösterir.
  - Düzenlileştirme terimi: kayba $\lambda R(W)$ eklenir. L2: $R(W) = \sum_k\sum_l W_{k,l}^2$; L1: $R(W) = \sum_k\sum_l |W_{k,l}|$; Elastic net: ikisinin ağırlıklı toplamı.
  - Dropout: her ileri geçişte bazı nöronlar rastgele sıfırlanır; bırakma oranı bir hiperparametredir, 0.5 yaygındır (ekrandan, 01:20:00).
  - Veri artırma (data augmentation): yatay çevirme, rastgele kırpma ve ölçekleme, renk titretme (parlaklık, kontrast), öteleme, döndürme, germe, kesme (shearing), lens bozulması ve bunların rastgele birleşimleri (ekrandan, 01:35:00).
- Transfer öğrenme (transfer learning)
  - ImageNet gibi büyük bir veri kümesiyle eğitilmiş ön eğitimli (pre-trained) model alınır, kendi verimizle yeniden eğitilir.
  - Küçük veri kümesinde yalnız son katman (FC-C) yeniden başlatılıp eğitilir, geri kalanı dondurulur; daha büyük veri kümesinde son birkaç tam bağlantılı katman eğitilir (ekrandan, 01:40:00).
- Görüntü sınıflamanın ötesindeki görevler
  - Anlamsal bölütleme (semantic segmentation): her piksel bir sınıfla etiketlenir; nesne örnekleri ayrılmaz (ekrandan, 01:45:00).
  - Sınıflama + konumlandırma (classification + localization): tek nesnenin sınıfı ve sınırlayıcı kutusu bulunur.
  - Nesne tespiti (object detection): birden çok nesnenin sınıfları ve kutuları bulunur.
  - Örnek bölütleme (instance segmentation): birden çok nesne piksel düzeyinde ve birbirinden ayrı işaretlenir.
- Anlamsal bölütleme ağları
  - Kayan yama (patch) yaklaşımında yamanın merkez pikselinin sınıfı tahmin edilir.
  - Tam evrişimli (fully convolutional) ağ: girdi $3\times H\times W$, evrişimler $D\times H\times W$, skorlar $C\times H\times W$, argmax ile $H\times W$ tahmin (ekrandan, 01:50:00). Kodlayıcı-kod çözücü yapısındaki U-Net bu amaçla yaygın kullanılır.
- Sınıflama + konumlandırma
  - Ortak öznitelik vektöründen (4096) iki dal çıkar: sınıf skorları (softmax kaybı) ve kutu koordinatları $(x, y, w, h)$ (L2 kaybı). Konumlandırma bir regresyon problemidir; iki kayıp toplanır (ekrandan, 01:55:00).
  - İnsan pozu kestirimi (human pose estimation) aynı fikirle eklem noktalarının koordinatlarını tahmin eder.
- Nesne tespiti yöntemleri
  - Kayan pencere (sliding window): her pencere için nesne/arka plan sınıflaması; çok maliyetli.
  - Bölge önerisi (region proposal): nesne içerme olasılığı yüksek bölgeler önceden seçilir.
  - R-CNN (CVPR 2014): yaklaşık 2000 önerilen bölgenin her biri ayrı ayrı CNN'den geçirilir, SVM ile sınıflanır, kutu regresyonu yapılır; eğitim 84 saat sürer ve çok disk kullanır.
  - Fast R-CNN (2015): tüm görüntü bir kez ConvNet'ten geçirilir, bölge önerileri "conv5" öznitelik haritası üzerinde kullanılır (ekrandan, 02:05:00); eğitim 8.75 saate iner.
  - Faster R-CNN: bölge önerisini de ağ içinde yapar; test süresi daha da kısalır.
  - Öneri kullanmayan YOLO ve SSD: görüntü $7\times7$ ızgaraya bölünür, her hücrede $B$ temel kutu için 5 sayı ($dx, dy, dh, dw$, güven) ve $C$ sınıf skoru üretilir; çıktı $7\times7\times(5B + C)$ (ekrandan, 02:10:00).
  - EfficientNet: ağın derinliği, genişliği ve çözünürlüğü birlikte ölçeklenerek en uygun mimari aranır.

## Hocanın Özellikle Vurguladığı Kısımlar

- SVM kaybı örneğindeki slayt hatası
  - Kurbağa örneğinde $2.2 - (-3.1) + 1 = 6.3$ ve $2.5 - (-3.1) + 1 = 6.6$, toplam 12.9'dur. Slayttaki 5.3, 5.6 ve 10.9 yanlıştır; hoca hatayı bilerek düzeltmeden bıraktığını, öğrencilerin yakalamasını istediğini söyledi.
- Vektörel (vectorized) NumPy kodunun gücü
  - İç içe for döngüleri yerine vektörel işlemler hem kodu kısaltır hem hızlandırır. Hoca SVM kaybı ve dropout maskesi kodlarını bu açıdan beğendiğini özellikle belirtti.
- Dropout'taki $p$ değeri tutma olasılığıdır
  - $p = 0.5$ ise nöronların %50'si tutulur; $p = 0.8$ ise %80'i tutulur, %20'si silinir. Yüksek $p$ daha az dropout demektir.
- Dropout yalnız eğitimde uygulanır
  - Testte bütün nöronlar etkindir; aktivasyonlar $p$ ile ölçeklenir ki test çıktısı eğitimdeki beklenen çıktıya eşit olsun.
- Transfer öğrenme az veriyle çalışırken önemlidir
  - Derin öğrenme çok sayıda eğitim örneği ister; az veri varsa ön eğitimli model kullanılır.
- Konumlandırma ve tespit için etiketli veri maliyeti
  - Her nesne ya da eklem için elle işaretlenmiş binlerce örnek gerekir; bu büyük bir iş yüküdür.
- Yöntemleri karşılaştırmalı denemek gerekir
  - Tespit yöntemlerinin başarısı uygulama alanına göre değişir; birkaç yöntemi karşılaştırarak denemekte fayda vardır.
- Kaynak önerisi
  - Konuyu ayrıntılı öğrenmek isteyenlere Stanford CS231n dersinin videoları, slaytları ve ödevleri önerildi.

## Kısa Tekrar Notları

- Eğitim döngüsü: batch al → ileri geçiş → kayıp → geri yayılım → ağırlık güncelle.
- $f(x,W) = Wx + b$; CIFAR-10 için $x$: $3072\times1$, $W$: $10\times3072$, skor: $10\times1$.
- SVM kaybı: $L_i = \sum_{j\ne y_i}\max(0, s_j - s_{y_i} + 1)$; $L = \frac{1}{N}\sum L_i$.
- Örnek kayıplar: 2.9, 0, 12.9; ortalama $\approx 5.27$.
- SGD: $w := w - \eta \nabla Q_i(w)$, her adımda tek (rastgele) örnek.
- Momentum ve Adam SGD'yi hızlandırır.
- Eğitim-doğrulama doğruluk farkı → aşırı öğrenme.
- Düzenlileştirme: L2, L1, Elastic net, dropout, veri artırma.
- Dropout: eğitimde rastgele maske, testte $p$ ile ölçekleme.
- Transfer öğrenme: küçük veride yalnız son katman, büyük veride son birkaç katman eğitilir.
- Anlamsal bölütleme: piksel etiketi, örnek ayrımı yok. Örnek bölütleme: piksel + örnek ayrımı.
- Konumlandırma = sınıflama (softmax) + kutu regresyonu (L2).
- R-CNN → Fast R-CNN → Faster R-CNN: önce paylaşılan öznitelik haritası, sonra ağ içi bölge önerisi.
- YOLO/SSD: öneri yok, ızgara ve temel kutular; çıktı $7\times7\times(5B+C)$.

## Detaylı Açıklamalar

- **Skor fonksiyonu ve parametreler.** Derin öğrenmeli sınıflamanın en basit hali doğrusal bir skor fonksiyonudur. CIFAR-10 kümesindeki bir görüntü $32\times32\times3$ sayıdan oluşur ve düzleştirildiğinde 3072 uzunluklu $x$ vektörü elde edilir. 10 sınıfın her biri için bir skor üretmek istendiğinden ağırlık matrisi 10 satır ve 3072 sütundur; her satır bir sınıfa ait bir şablon gibi davranır ve $x$ ile iç çarpımı o sınıfın skorunu verir. Buna bias eklenir. Eğitimin amacı, doğru sınıfın skoru en büyük çıkacak biçimde $W$ ve $b$'yi ayarlamaktır. Hoca, lineer cebirdeki gösterim alışkanlığını da hatırlattı: büyük harf matrisi, küçük harf vektörü gösterir.

- **SVM kaybının hesaplanışı.** Üç eğitim örneği (kedi, araba, kurbağa) ve üç sınıf için skor tablosu verilir (ekrandan, 00:35:00):

  | Sınıf | Kedi görüntüsü | Araba görüntüsü | Kurbağa görüntüsü |
  |---|---|---|---|
  | cat | **3.2** | 1.3 | 2.2 |
  | car | 5.1 | **4.9** | 2.5 |
  | frog | -1.7 | 2.0 | **-3.1** |

  Kedi görüntüsü için doğru sınıfın skoru 3.2'dir. $\max(0, 5.1 - 3.2 + 1) + \max(0, -1.7 - 3.2 + 1) = \max(0, 2.9) + \max(0, -3.9) = 2.9$ (ekrandan, 00:40:00). Araba görüntüsünde doğru sınıf skoru 4.9 öbür skorlardan en az 1 büyük olduğu için $\max(0, 1.3-4.9+1) + \max(0, 2.0-4.9+1) = 0 + 0 = 0$. Kurbağa görüntüsünde $\max(0, 2.2+3.1+1) + \max(0, 2.5+3.1+1) = 6.3 + 6.6 = 12.9$. Toplam kayıp ortalamadır: $(2.9 + 0 + 12.9)/3 \approx 5.27$ (python ile doğrulandı).

  > **Ders sonrası not:** Slaytta kurbağa örneği 5.3 + 5.6 = 10.9 olarak hesaplanmıştı (ekrandan, 00:45:00); hoca derste doğrusunun 6.3 + 6.6 = 12.9 olduğunu söyledi. Ortalama kayıp slayttaki değerlerle büyük olasılıkla 4.6 olarak verilmişti; hoca ortalama işleminde de hata olduğunu belirtti. Doğru ortalama yaklaşık 5.27'dir.

- **Gradyan inişi.** Kayıp, $W$'nin parametrelerine göre türevlenebilir bir fonksiyondur. Türev (gradyan) kaybın en hızlı arttığı yönü gösterir; parametreler bu yönün tersine, öğrenme oranı $\eta$ kadar bir adımla güncellenir. Derste gösterilen doğru uydurma örneğinde iki parametre ($w_1$, $w_2$) vardır; amaç fonksiyonu hata karelerinin toplamıdır ve her parametreye göre türev alınarak güncelleme yazılır (ekrandan, 00:55:00). Stokastik gradyan inişinin standart (batch) gradyan inişinden farkı, adımı hesaplarken tek bir rastgele örneği kullanmasıdır. Momentum ve Adam gibi yöntemler yakınsamayı hızlandırmak için önerilmiştir; Adam bugün en yaygın kullanılanlardan biridir.

- **Aşırı öğrenme ve düzenlileştirme.** Eğitim sürerken eğitim kaybı düşer, eğitim doğruluğu artar. Doğrulama verisinde de doğruluğun benzer biçimde artması beklenir; ikisi arasında büyük açıklık varsa model eğitim verisini ezberliyordur. Bunu azaltmanın yolları yalnız iterasyon sayısını azaltmak ya da veri çoğaltmak değildir. Kayba bir düzenlileştirme terimi eklemek ilk ve temel fikirdir: L2 düzenlileştirmede $W$'deki bütün değerlerin karelerinin toplamı, L1'de mutlak değerlerinin toplamı $\lambda$ katsayısıyla kayba eklenir; Elastic net ikisini birleştirir.

- **Dropout.** Her ileri geçişte gizli katmanlardaki nöronların bir kısmı rastgele sıfırlanır (ekrandan, 01:20:00). Kod örneğinde her katman için çıktıyla aynı boyutta $[0,1)$ aralığında rastgele sayılardan oluşan bir dizi üretilir ve $p$'den küçük olanlar `True` sayılarak ikili maske elde edilir; katman çıktısı bu maskeyle çarpılır (ekrandan, 01:25:00):

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

  `np.maximum(0, ...)` ReLU aktivasyonudur. Maske her eğitim adımında yeniden üretilir. Sezgisel yorum: her nöron nesnenin bir özelliğine ("kulağı var", "kuyruğu var", "tüylü" gibi) odaklanır; bazılarını rastgele kapatmak ağı yedekli bir temsil öğrenmeye zorlar ve özniteliklerin birbirine aşırı bağımlı olmasını engeller (ekrandan, 01:30:00). Rastgele bir öznitelik seçimi gibi düşünülebilir. Testte dropout uygulanmaz; bütün nöronlar etkindir ve aktivasyonlar $p$ ile ölçeklenir.

- **Veri artırma.** Giriş görüntüsü sınıf etiketi korunarak dönüştürülür ve eğitim kümesi çoğaltılır: yatay çevirme, rastgele kırpma ve ölçekleme, renk titretme (parlaklık ve kontrast). Slayt "probleminize göre yaratıcı olun" der: öteleme, döndürme, germe, kesme, lens bozulması ve bunların rastgele birleşimleri kullanılabilir (ekrandan, 01:35:00).

- **Transfer öğrenme.** ImageNet'te (1000 sınıf, sınıf başına çok sayıda örnek) evrişim ve havuzlama katmanlarıyla öznitelik çıkaran, ardından FC-4096, FC-4096 ve FC-1000 katmanlarıyla sınıflayan bir ağ eğitilir. Küçük bir veri kümesinde (C sınıf) son katman FC-C olarak yeniden başlatılıp eğitilir, öbür katmanlar dondurulur. Daha büyük bir veri kümesinde son iki FC-4096 ve FC-C katmanları eğitilir, öznitelik çıkarım katmanları yine dondurulur. Slayt, ince ayarda öğrenme oranının asıl öğrenme oranının 1/10'u ile başlatılmasını önerir (ekrandan, 01:40:00).

- **Bölütleme ve tespit görevleri.** Anlamsal bölütlemede her pikselin sınıfı bulunur, ama üst üste binen iki inek gibi aynı sınıftan nesneler birbirinden ayrılmaz; bu yöntemin bir eksiği olarak gösterilir. Eğitim için piksel düzeyinde etiketlenmiş veri gerekir. Tam evrişimli ağ bütün pikseller için tahmini tek seferde üretir (ekrandan, 01:50:00). Sınıflama + konumlandırmada ağ hem sınıf skorunu hem kutunun sol üst köşe koordinatı ile genişlik ve yüksekliğini (ya da iki köşe koordinatını) üretir; sınıf için softmax, kutu için L2 kaybı hesaplanıp toplanır (ekrandan, 01:55:00). Birden çok nesne olduğunda her nesne için dört koordinat ve bir sınıf gerekir; kayan pencere çok maliyetli olduğundan bölge önerisi yöntemleri geliştirilmiştir. R-CNN binlerce bölgeyi tek tek ağdan geçirdiği için yavaştır; Fast R-CNN evrişimleri bir kez yapıp önerileri öznitelik haritasında kullanarak eğitimi 84 saatten 8.75 saate indirir; Faster R-CNN bölge önerisini ağın içine alarak test süresini yeniden kısaltır. YOLO ve SSD öneri adımı kullanmadan, ızgara hücrelerindeki temel kutulardan doğrudan regresyon yapar (ekrandan, 02:10:00).

  > **Ders sonrası not:** Hoca YOLO ve SSD'den tek yöntem gibi ("YOLO SSD") söz etti; slayt başlığı "YOLO / SSD" olup bunlar iki ayrı yöntemdir (YOLO: Redmon ve ark., CVPR 2016; SSD: Liu ve ark., ECCV 2016; ekrandan, 02:10:00).

- **Terimlerin Türkçe karşılıkları.** Derste sorulan bir soru üzerine bazı karşılıklar konuşuldu: segmentation için bölütleme, classification için sınıflama, clustering için kümeleme (öbekleme ve topaklama da kullanılıyor), parity bit için eşlenik biti. Hoca, aynı kavram için birden çok Türkçe kelime türetildiğinden genelde İngilizce terimleri kullandığını, Türkçe bildiri yazarken ise karşılık bulmak gerektiğini söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
