# Ders 7 Çalışma Özeti

## Genel Konular

- Diferansiyel denklemlerin sinir ağlarıyla çözümü: PINN, Deep Galerkin ve Extreme Learning Machine (ELM)
  - Evrensel yaklaşım teoremi: En az bir gizli katmanı, yeterli sayıda nöronu ve uygun aktivasyon fonksiyonu olan bir ağ her sürekli fonksiyona istenen doğrulukta yaklaşabilir (ekrandan, 00:05:00).
  - PINN ve Deep Galerkin yönteminde (DGM) ağın girdisi bağımsız değişkenler ($x$, $t$), çıktısı çözüm fonksiyonu $u$'dur. Ağın çıktısının türevleri denkleme konur; denklemin sıfırdan sapması (artık) kayıp fonksiyonu olur ve ağırlıklar geri yayılımla güncellenir.
  - PINN, DGM'den farklı olarak denklemin parametrelerini (örneğin $\varepsilon$), sınır ve başlangıç koşullarını da modele verir. "Fizikle bilgilendirilmiş" ifadesi buradan gelir.
  - ELM'de genellikle tek gizli katman vardır. Giriş ağırlıkları ve gizli katman yanlılıkları belli bir aralıkta rastgele seçilip sabit tutulur. Yalnız çıkış ağırlıkları $w$ öğrenilir: $u(x)=\sum_{i=1}^{M} V_i(x_m)\,w_i$ (ODE), $u(x,t)=\sum_{i=1}^{M} V_j(x_m,t_n)\,w_i$ (PDE) (ekrandan, 00:15:00).
  - Türevler alınıp denkleme konunca $w$'ye göre doğrusal bir denklem sistemi oluşur. Sistem en küçük kareler yöntemiyle bir kerede çözülür; geri yayılım ve epok yoktur. Sınır koşulları da sisteme eklenir.
  - Örnek ODE: $-\varepsilon u''(x)+u'(x)+u(x)=g(x)$, $u(0)=u(1)=0$, $\Omega=[0,1]$ (ekrandan, 00:10:00). $\varepsilon$ küçüldükçe çözüm $x=1$ yakınında dikleşir ve problem zorlaşır. Hatalar: $\varepsilon=1$ için $7.5274\times10^{-17}$, $\varepsilon=0.2$ için $2.3182\times10^{-14}$, $\varepsilon=0.03$ için $2.2023\times10^{-6}$ (ekrandan, 00:20:00).
  - Gizli nöron sayısı belli bir değeri aşınca hata düşmüyor. En küçük kareler matrisi büyüdükçe çözümü zorlaşıyor; bir optimum nöron sayısı var.
  - Advection-diffusion (PDE) ve Poisson denklemi de çözüldü. Rastgele ağırlıkların seçildiği aralık ve dağılım (uniform, normal) sonucu etkiliyor; aralığın çok dar ya da çok geniş olması iyi sonuç vermiyor.
- Hibrit CNN-LSTM ile insan aktivitesi tanıma (HAR)
  - Veri seti: Serbest yaşam ortamında yaklaşık 2 saat kayıt; sağ uyluğa ve arkaya yerleştirilmiş iki adet üç eksenli ivmeölçer; etiketleme göğüse takılan kamerayla yapılmış. Yaklaşık 12 aktivite var, inaktif olanlar çıkarılıp 10 sınıf kullanılmış.
  - Öznitelik mühendisliği: İki sensör arasındaki eksen bazlı mesafe, ortalamalar, en büyük ile en küçük farkı yeni öznitelik olarak eklenmiş; min-max ölçekleme yapılmış.
  - Model: Konvolüsyon (128 filtre, kernel 2) → max pooling → konvolüsyon → LSTM (64 birim) → dropout → LSTM → Dense (64, 32) → çıkış (10, softmax) (ekrandan, 00:50:00). Dropout 0.1, en çok 80 epok, early stopping (val loss, patience 5), categorical cross entropy.
  - Dört pencere boyutunda veri setleri kuruldu. En iyi yapılandırma Adam + tanh oldu. Doğruluk pencere büyüdükçe yaklaşık 0.62'den 0.73'e çıktı (ekrandan, 00:55:00).
- EEG ile Alzheimer, frontotemporal demans ve sağlıklı birey ayrımı
  - 88 katılımcı (36 AD, 23 FTD, 29 sağlıklı), 19 kanallı EEG, gözler kapalı ve oturur pozisyonda kayıt (ekrandan, 01:05:00).
  - Literatürde PSD ile delta, teta, alfa, beta, gama bantlarına ayrılan öznitelikler ve klasik makine öğrenmesi kullanılmış.
  - Sunumda ham 19 kanal doğrudan DNN'e ve LSTM'e verilmiş, PCA ile kanal sayısı 5'e indirilmiş, sonunda Random Forest denenmiş. Etiketleme ve karmaşıklık matrisi hatalı çıkmış.
- Güneş ışınımı (GHI) tahmini (regresyon)
  - Veri bir ulusal güneş radyasyonu veri tabanından API ile alınmış (ekrandan, 01:30:00). DNI doğrudan ışınım, DHI dağınık (yayılı) ışınım, GHI bunlardan hesaplanan toplam yatay ışınımdır.
  - 14 öznitelik, iki gizli katman (32'şer nöron), ReLU, L2 düzenlileştirme, MSE kaybı, Adadelta, 50 epok (ekrandan, 01:40:00).
- Melanom (deri kanseri) sınıflandırma
  - Önceden eğitilmiş VGG16 üzerine max pooling, flatten, dense, batch normalization, dropout katmanları eklenmiş. Early stopping, model checkpoint ve ReduceLROnPlateau (3 adımda iyileşme yoksa öğrenme oranını 0.1 ile çarp) kullanılmış. Kayıp: binary cross entropy.
  - Test doğruluğu 0.8480, test kaybı 0.3489 (15 epok) (ekrandan, 01:55:00).
- URL tabanlı oltalama (phishing) tespiti
  - URL uzunluğu ve özel karakter sayıları (nokta, tire, alt çizgi, eğik çizgi, soru işareti, eşittir, & vb.) öznitelik. Hedefle en yüksek korelasyon `n_slash` (0.61) ve `url_length` (0.43) (ekrandan, 02:05:00).
  - 3 gizli katman (128), dropout 0.2, sigmoid, binary cross entropy, Adam, 100 epok; doğruluk yaklaşık %89.
- Web sitesi metin sınıflandırma (16 kategori)
  - TextVectorization → Embedding → GlobalAveragePooling1D → Dense katmanları (ekrandan, 02:20:00). PyTorch ile CountVectorizer ve embedding tabanlı modeller de denenmiş.
- Kardiyovasküler hastalık tahmini
  - 70 bin örnek, 11 girdi. Doğrusal ve doğrusal olmayan SVM, Random Forest, MLP ile LSTM ve GRU karşılaştırılmış. En iyi sonuç yaklaşık %74 ile LSTM/GRU.
- Walmart haftalık satış tahmini
  - 6435 örnek, 45 mağaza, tatil bayrağı, sıcaklık, yakıt fiyatı, TÜFE, işsizlik. StandardScaler, 6-16-8-4-1 ağ, MSE, Adam. Öğrenme oranı taraması, batch 32. CatBoost karşılaştırması.
- Sperm morfolojisi sınıflandırma
  - Üç alt veri seti, 18 sınıf, dengesiz veri. AlexNet, ShuffleNet, ResNet, DenseNet ile softmax, SVM, SVM+PCA senaryoları (ekrandan, 03:05:00).
- Meyve tazelik sınıflandırma
  - 6 sınıf (taze ve çürük meyveler), 1655 eğitim, 456 test görüntüsü. MobileNetV2 ile transfer öğrenme ve sıfırdan kurulan bir CNN karşılaştırılmış (ekrandan, 03:15:00).
- Ötegezegen sisteminin uzaklık tahmini (regresyon)
  - Girdiler: sistemin görünür parlaklığı (`sy_vmag`) ve yıldız yarıçapı (`st_rad`); hedef: sistem uzaklığı (`sy_dist`). Uzaklıkla korelasyon 0.54 ve 0.00 (ekrandan, 03:25:00). Hiperparametreler tek tek deneme yanılmayla seçilmiş.

## Hocanın Özellikle Vurguladığı Kısımlar

- Test kümesine veri artırma (augmentation) yapılmaz
  - Artırma yalnız eğitim kümesine yapılır, doğrulamaya yapılması bile tartışmalıdır. Test kümesine artırma yapan yayınlar şişirilmiş sonuçlar verir.
- Doğruluk, karmaşıklık matrisi ve precision/recall birbiriyle tutarlı olmalı
  - Karmaşıklık matrisinde gerçek etiket satırlarının boş olması, doğrulama kaybının sıfırda sabit kalması verinin ya da etiketlerin modele yanlış verildiğini gösterir.
  - Raporlanan doğruluk ile karmaşıklık matrisinden hesaplanan değer uyuşmuyorsa hesapta hata vardır.
- Early stopping'i checkpoint için kullanmak
  - Eğitimi tam epok sayısına kadar sürdürüp en iyi doğrulama değerinin görüldüğü noktadaki modeli kaydetmek ve tahminde o modeli kullanmak daha mantıklıdır.
- Öğrenme oranı ve zamanlama (scheduling)
  - RMSprop genelde düşük, Adam biraz daha yüksek öğrenme oranlarında iyi çalışır. Belli epok aralıklarıyla öğrenme oranını bir $\gamma$ katsayısıyla küçültmek aktivite tanıma gibi problemlerde öğrenmeyi iyileştirir.
- Zaman serisinde gün, ay, yıl, saat sütunları
  - Zaman serisinde zaman bilgisi zaten sıranın içindedir; ayrıca gün, ay, yıl sütunu eklemek anlamsız ve yanıltıcı öznitelik olur.
- Sıfır değerli büyük yığın için iki aşamalı model
  - GHI'de gece verileri sıfırda büyük bir tepe oluşturur. Önce ikili sınıflandırmayla sıfır olanları ayırıp yalnız sıfır olmayanları regresyona vermek gerekir.
- Hazır kodu çalıştırmak katkı sayılmaz
  - Bir notebook'un sonuna bir dense katman eklemek ya da epok sayısını artırmak yenilik değildir; mimariyi gerekçeli değiştirmek, farklı kaynakları birleştirmek beklenir.
- Belirleyici öznitelik kullanmamak
  - Tanıyı doğrudan belli eden bir test skoru (örneğin MMSE) öznitelik olarak kullanılırsa sınıflandırma anlamsızlaşır.

## Kısa Tekrar Notları

- PINN/DGM: Girdi $x,t$; çıktı $u$; kayıp = denklem artığı + sınır koşulları; geri yayılımla eğitim.
- ELM: Rastgele ve sabit giriş ağırlıkları; yalnız çıkış ağırlıkları en küçük kareler ile bir kerede bulunur.
- Tekil pertürbe problemde $\varepsilon$ küçüldükçe sınır tabakası dikleşir, çözüm zorlaşır.
- HAR'da yürüme ile merdiven çıkma/inme en çok karışan sınıflardır; iki sensör arasındaki mesafe ayırt edici olabilir.
- Zaman damgası (timestamp) doğrudan öznitelik olarak kullanılmaz.
- Test kümesine augmentation yapılmaz.
- Dengesiz veride doğruluk tek başına yeterli değildir; precision, recall, F1 ve karmaşıklık matrisi birlikte incelenir.
- Early stopping + checkpoint: En iyi doğrulama noktasındaki model saklanır.
- Regresyonda doğruluk (accuracy) değil MSE, MAE, $R^2$ gibi hata ölçüleri raporlanır.
- MobileNetV2: Depthwise separable konvolüsyon, inverted residual ve linear bottleneck.
- GRU, LSTM'e göre daha az parametreli ve daha basittir.

## Detaylı Açıklamalar

- **PINN, DGM ve ELM.** Diferansiyel denklemlerin analitik çözümü az sayıda denklem için vardır. Sayısal yöntemlerin de kararlılık, doğruluk ve hesap maliyeti sorunları olabilir. Sinir ağı tabanlı yöntemlerde ağ, çözüm fonksiyonunun kendisini modeller. Etiket olarak gerçek çözüm kullanılmaz. Ağın çıktısının türevleri alınıp denklemin sol tarafı hesaplanır, sağ tarafa (sıfır ya da kaynak terimi) eşitlenmeye çalışılır. Artık kayıp fonksiyonu olur. PINN bunun yanında denklemin parametrelerini ve sınır/başlangıç koşullarını da ağa verir; böylece farklı parametre değerleri için genel bir çözüm öğrenilebilir. ELM'de gizli katmanın çıktıları $V_i$ sabit rastgele ağırlıklarla hesaplanır, çözüm bunların doğrusal birleşimidir. Türev operatörü $V_i$'lere uygulanınca bilinmeyenleri $w_i$ olan doğrusal bir sistem elde edilir. Bu sistem toplanan noktalar ve sınır koşullarıyla birlikte en küçük kareler yöntemiyle çözülür; eğitim tek adımda biter. Sunumdaki ODE'de gerçek çözüm $u(x)=\sin(x)\left(1-e^{-(1-x)/\varepsilon}\right)$'dir; $\varepsilon=0.03$ için çözüm $x\approx0.89$'da yaklaşık 0.76'ya çıkıp $x=1$'de hızla sıfıra iner.
  - Ders sonrası not: Slaytta üs $e^{-(1-x)\varepsilon}$ diye yazılmış (ekrandan, 00:10:00). Ekrandaki grafiğe (tepe değerleri yaklaşık 0.19, 0.50, 0.76) uyan ifade $e^{-(1-x)/\varepsilon}$'dir; python ile kontrol edildi. Çarpım biçimiyle küçük $\varepsilon$'da çözüm neredeyse sıfır olur, dikleşme görülmez.
  - Ders sonrası not: Hoca soru sırasında ELM'nin ağırlıkları "ileri beslemeli olarak tekrar tekrar" güncellediğini söyledi. Sunumda anlatılan yöntemde çıkış ağırlıkları yinelemeli güncellenmez, en küçük kareler ile bir kerede hesaplanır.
  - Ders sonrası not: Tartışmada "derin öğrenme gözetimli öğrenmedir, çıktının etiketi olmalı" denildi. PINN ve benzeri yöntemlerde kayıp, büyük olasılıkla denklemin artığından ve sınır koşullarından kurulur; çözümün etiketli örneklerine gerek yoktur. Gerçek çözüm yalnız sonucu karşılaştırmak için kullanılır.
- **Hibrit CNN-LSTM.** CNN, az sayıdaki ham öznitelikten yeni öznitelik haritaları çıkarır; LSTM ise sıralı sensör verisindeki zamansal bağımlılıkları modeller. Overfitting'i azaltmak için dropout ve early stopping kullanıldı. Eğitim ve doğrulama eğrilerinin birlikte hareket etmesi öğrenmenin sürdüğünü, ayrılmaya başlaması öğrenmenin bittiğini ve aşırı öğrenmeye geçildiğini gösterir. Veri setinde katılımcı kimliği olmadığı için kişi bazlı ayırma (leave-one-subject-out) yapılamadı; hoca kişiye özgü bilginin sonucu iyileştirebileceğini söyledi.
- **EEG sunumundaki hatalar.** Veri uzunlukları sıfır ekleme ya da kendi kendini tekrar ederek eşitlenmiş; her zaman adımına ayrı etiket verilmiş. Sonuçta karmaşıklık matrisinde yalnız bir gerçek sınıfın satırı dolu, doğrulama kaybı sıfırda sabit çıkmış. Hoca bunun verinin modele yanlış verildiğini gösterdiğini söyledi. PCA'nın işlevi de netleştirildi: PCA, 19 kanalı daha az boyutlu bir uzaya taşır; elde edilen bileşenler alfa, beta gibi frekans bantları değildir. Frekans bantları PSD gibi spektral yöntemlerle elde edilir.
- **GHI regresyonu.** Gün, ay, yıl gibi zaman sütunları dakikalık veride binlerce satır boyunca sabit kalır ve anlamlı bilgi taşımaz. Gece saatlerinde ışınım sıfır olduğundan hedefin dağılımında sıfırda büyük bir tepe vardır. Hocanın önerisi, önce sıfır/sıfır değil ikili sınıflandırması, sonra yalnız sıfır olmayan örneklerde regresyondur. Regresyonda "doğruluk" yerine hata ölçüleri raporlanmalıdır.
  - Ders sonrası not: Sunumda L2 düzenlileştirmenin aykırı değerlere fazla ağırlık verdiği söylendi. Aykırı değerlere duyarlılık büyük olasılıkla kayıp fonksiyonunun (MSE) özelliğidir; L2 düzenlileştirme ise büyük ağırlıkları cezalandırır.
- **Melanom ve test kümesi.** Kullanılan Kaggle veri seti, yayının yazarlarınca artırılmış (augmented) hâliydi. Hoca, yayında test kümesine de artırma yapıldığını ve bunun yanlış olduğunu vurguladı. Ayrıca raporlanan doğruluk ile karmaşıklık matrisi ve precision/recall değerlerinin tutarlılığı sorgulandı.
  - Ders sonrası not: Dengesiz ikili veride yüksek doğruluk ile düşük precision/recall birlikte görülebilir. Örneğin pozitif sınıf verinin yaklaşık %15'i ise precision ve recall %51 iken doğruluk yaklaşık %85 olabilir (python ile hesaplandı). Bu yüzden tutarlılık her zaman karmaşıklık matrisinin kendisinden kontrol edilmelidir.
- **Metin sınıflandırma.** TextVectorization her metni 1660 uzunlukta bir diziye çevirir, Embedding her kelimeyi 128 boyutlu vektöre taşır, GlobalAveragePooling1D dizi boyunca ortalama alarak 128 boyutlu bir vektör üretir. Dense(64) katmanının parametre sayısı $128\cdot64+64=8256$, Dense(16) katmanınınki $64\cdot16+16=1040$'tır (ekrandan, 02:20:00; python ile doğrulandı).
- **Ötegezegen uzaklığı.** Görünür parlaklık Dünya'dan ölçüldüğü için uzaklıkla ilişkilidir; ancak bu ilişki doğrudan değildir. İki öznitelikle kurulan model yüksek MSE verdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
