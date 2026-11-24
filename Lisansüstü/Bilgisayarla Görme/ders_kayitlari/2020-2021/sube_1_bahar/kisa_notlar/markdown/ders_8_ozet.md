# Ders 8 Çalışma Özeti

## Genel Konular

- Derin öğrenmede kullanılan temel veri kümeleri
  - CIFAR-10: 10 sınıflı, renkli (RGB) görüntülerden oluşan, küçük denemeler için yaygın kullanılan bir veri kümesi. 50 000 eğitim ve 10 000 test örneği vardır; her görüntü $32 \times 32 \times 3$ boyutundadır. Sınıf numaraları uçaktan (airplane, 0) başlar; derste 7 numaralı sınıfın at (horse) olduğu gösterildi.
  - MNIST: "makine öğrenmesinin hello world'ü" olarak anılan el yazısı rakam veri kümesi (Modified National Institute of Standards and Technology database). Gri seviyeli, $28 \times 28$ boyutlu görüntülerdir; sınıf etiketleri 0-9 rakamlarıdır (ekrandan, 00:15:00).
  - MNIST'te 60 000 eğitim ve 10 000 test örneği vardır. `x_train` boyutu (60000, 28, 28), `y_train` boyutu (60000,), `x_test` boyutu (10000, 28, 28), `y_test` boyutu (10000,) olarak ekrana yazdırıldı (ekrandan, 00:20:00).
  - Bir $28 \times 28$ görüntü düzleştirilerek (flatten) $28 \cdot 28 = 784$ uzunluklu bir vektöre çevrilebilir: birinci satırın arkasına ikinci satır eklenir, böyle devam edilir.
  - Keras ile MNIST hazır yüklenir: `(x_train, y_train), (x_test, y_test) = mnist.load_data()`. CIFAR-10 ise derste ayrı bir klasöre konup `load_CIFAR10(cifar10_dir)` ile okundu (ekrandan, 00:20:00 ve 00:25:00).
- Evrişim (konvolüsyon) katmanı
  - Evrişim katmanı görüntüden öznitelik (feature) çıkarmak için kullanılır.
  - $32 \times 32 \times 3$ bir CIFAR görüntüsüne dolgu (padding) yapmadan $5 \times 5 \times 3$ bir filtre uygulanırsa her kenardan 2 piksel kaybolur ve $28 \times 28 \times 1$ boyutlu bir aktivasyon haritası elde edilir. 6 filtre kullanılırsa çıktı $28 \times 28 \times 6$ olur; derinliği filtre sayısı belirler (ekrandan, 00:30:00).
  - Filtre katsayıları görüntüde ne arandığını gösterir: ana köşegeni 1, diğer gözleri $-1$ olan filtre köşegen çizgileri, orta sütunu 1, diğer gözleri $-1$ olan filtre dikey çizgileri bulur (ekrandan, 00:40:00).
  - Kaydırma adımı (stride) filtrenin her adımda kaç piksel kaydırılacağını belirler; stride büyüdükçe çıktı küçülür.
  - Renkli görüntüde filtrenin de derinliği vardır ($3 \times 3 \times 3$). Bir çıkış değeri için $27$ çarpım toplanır ve derinlik tek bir sayıya iner.
- Ardışık evrişim katmanları
  - $32 \times 32 \times 3$ girdiye 6 tane $5 \times 5 \times 3$ filtre: $28 \times 28 \times 6$ (alt düzey öznitelikler). Ardından 10 tane $5 \times 5 \times 6$ filtre: $24 \times 24 \times 10$ (orta düzey öznitelikler). Daha ileri katmanlar üst düzey öznitelikler üretir (ekrandan, 00:45:00).
  - İkinci katmandaki filtrenin derinliği (6), girdinin derinliğine eşit olmak zorundadır.
  - Katman sayısı arttıkça ağ "derinleşir"; derin ağ adı buradan gelir.
- Çıktı boyutu, sıfır dolgu ve parametre sayısı
  - Dolgusuz çıktı boyutu: $\dfrac{N - F}{S} + 1$ ($N$: girdi boyutu, $F$: filtre boyutu, $S$: stride) (ekrandan, 00:50:00).
  - $N = 7$, $F = 3$ için: $S = 1 \Rightarrow 5$, $S = 2 \Rightarrow 3$, $S = 3 \Rightarrow 2{,}33$ (uymaz, "does not fit") (ekrandan, 00:50:00).
  - Sıfır dolgu (zero padding) görüntünün çevresine sıfırlar ekler. $F \times F$ filtre ve $P = (F-1)/2$ dolgu ile ($S = 1$) çıktı girdiyle aynı boyutta kalır: $F = 3 \Rightarrow P = 1$, $F = 5 \Rightarrow P = 2$.
  - Genel formül (CS231n özeti): girdi $W_1 \times H_1 \times D_1$; hiperparametreler $K$ (filtre sayısı), $F$, $S$, $P$; çıktı $W_2 = (W_1 - F + 2P)/S + 1$, $H_2 = (H_1 - F + 2P)/S + 1$, $D_2 = K$. Filtre başına $F \cdot F \cdot D_1$ ağırlık, toplam $(F \cdot F \cdot D_1) \cdot K$ ağırlık ve $K$ sapma (bias) vardır (ekrandan, 01:00:00).
  - Parametre sayısı ağın karmaşıklığını gösterir; her katman için hesaplanabilmelidir.
- 1×1 evrişim ve öznitelik hiyerarşisi
  - $56 \times 56 \times 64$ girdiye 32 tane $1 \times 1$ (aslında $1 \times 1 \times 64$) filtre uygulanınca çıktı $56 \times 56 \times 32$ olur. Yeni mimarilerde küçük filtreler tercih edilir.
  - VGG-16'nın ilk katman filtreleri (Conv1_1) yatay, dikey, nokta gibi alt düzey öznitelikleri; Conv3_2 orta düzey, Conv5_3 belirli bir yönelimi olmayan üst düzey öznitelikleri yakalar (ekrandan, 01:25:00).
  - CNN öznitelik çıkarımını otomatik yapar; elle kenar ve köşe bulma gerekmez. Ardından sınıflandırma kısmı (tam bağlantılı katmanlar ya da SVM gibi klasik sınıflandırıcılar) gelir.
- Maksimum havuzlama (max pooling)
  - Gösterimi küçültür, hesaplamayı kolaylaştırır; her aktivasyon haritasına ayrı ayrı uygulanır (ekrandan, 01:30:00).
  - Genelde $2 \times 2$ pencere ve stride 2 ile kullanılır: her pencerenin en büyük değeri alınır, $4 \times 4$ harita $2 \times 2$'ye iner.
  - Nesneyi değiştirmeden alt örnekleme (subsampling) yapmak amaçlanır; genelde evrişim katmanının arkasından gelir.
- Aktivasyon fonksiyonları (ekrandan, 01:35:00)
  - Sigmoid $\sigma(x) = \dfrac{1}{1 + e^{-x}}$: girdiyi $(0,1)$ aralığına sıkıştırır, $\sigma(0) = 0{,}5$. Doyma (saturation) yaparak değerleri "öldürür".
  - $\tanh(x)$: girdiyi $(-1, 1)$ aralığına sıkıştırır, $0$'ı $0$'a götürür; benzer doyma sorunu vardır.
  - ReLU $f(x) = \max(0, x)$: negatif girdiler için 0, pozitif girdiler için $x$. Derin ağların başarısının en önemli anahtarlarından biri olarak gösterilir; daha hızlı eğitir, işlemi ucuzdur (ekrandan, 01:40:00).
  - Slaytta Leaky ReLU $\max(0{,}1x, x)$, Maxout ve ELU da listelenir.
- Düzleştirme ve tam bağlantılı katman
  - Düzleştirme (flattening) öznitelik matrisini (2 ya da 3 boyutlu) tek boyutlu vektöre çevirir.
  - $32 \times 32 \times 3$ girdi $3072 \times 1$ vektöre açılır; $10 \times 3072$ ağırlık matrisi $W$ ile çarpılınca 10 sınıf için 10 değer üretilir (ekrandan, 01:45:00).
- Yapay sinir ağına giriş
  - $h = \sigma(W_1 x + b_1)$, $y = \sigma(W_2 h + b_2)$. Girdi katmanı öznitelik vektörü boyutundadır (ekrandan, 01:50:00).
  - 3 girdi, 4 gizli, 2 çıkış nöronlu ağ: $4 + 2 = 6$ nöron, $[3 \times 4] + [4 \times 2] = 20$ ağırlık, $6$ sapma, toplam $26$ öğrenilebilir parametre (ekrandan, 01:50:00).
  - Eğitim: eğitim kümesinin bir alt kümesi (batch) ağdan ileri geçirilir, tahmin ile gerçek etiket (ground truth) arasındaki hata hesaplanır, geri yayılım (backpropagation) ile ağırlıklar güncellenir.
  - Gradyan iniş: $\theta_{yeni} = \theta_{eski} - \alpha \nabla_\theta J(\theta)$; amaç kayıp fonksiyonunu en aza indirmektir.
- Tek ileri geçiş örneği ve softmax
  - $4 \times 3$ ağırlık matrisi, $3 \times 1$ girdi ve sapma ile dört sınıf (çok olumlu, olumlu, olumsuz, çok olumsuz) için skorlar $0{,}95$; $3{,}89$; $0{,}15$; $0{,}37$ bulunur, en büyük skor "olumlu" sınıfıdır (ekrandan, 02:00:00).
  - Softmax skorları $(0,1)$ aralığına çeker ve toplamlarını 1 yapar: $P(Y = k \mid X = x_i) = \dfrac{e^{s_k}}{\sum_j e^{s_j}}$ (ekrandan, 02:25:00).
  - Örnek: skorlar $3{,}2$; $5{,}1$; $-1{,}7$ → üstel değerler $24{,}5$; $164{,}0$; $0{,}18$ → olasılıklar $0{,}13$; $0{,}87$; $0{,}001$.
- CNN mimarileri ve ILSVRC yarışması
  - ImageNet: 1000 nesne sınıfına ait milyonlarca görüntü. ILSVRC'de ilk beş tahmin (top-5) içinde doğru sınıf varsa doğru sayılır.
  - AlexNet (2012): 5 evrişim + 3 tam bağlantılı = 8 katman; ilk katman 96 tane $11 \times 11$ filtre, stride 4; top-5 hata yaklaşık %16. Ardından gelen en iyi yöntemin hatası yaklaşık %26 idi (ekrandan, 02:35:00).
  - VGGNet (2014 ikincisi): yalnız $3 \times 3$ evrişim (stride 1, pad 1) ve $2 \times 2$ max pool (stride 2); 16-19 katman; top-5 hata %7,3 (ekrandan, 02:40:00).
  - GoogLeNet (2014 birincisi): AlexNet'ten 12 kat az parametre, hesaplama verimliliği, Inception modülü, tam bağlantılı katman yok, toplam yaklaşık 5 milyon parametre (ekrandan, 02:45:00).
  - ResNet (2015): 152 katman, artık blok (residual block) $H(x) = F(x) + x$; top-5 hata %3,57, insan hatasının (%5-10) altında (ekrandan, 02:50:00).
- Keras ile MNIST örneği
  - Sıralı model: `Flatten(28,28)` → `Dense(512, relu)` → `Dropout(0.2)` → `Dense(10, softmax)`; `adam` eniyileyici, `sparse_categorical_crossentropy` kaybı; 5 epok (ekrandan, 03:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Evrişim işlemini elle yapabilmek
  - Küçük bir görüntü matrisi (0-255 parlaklık değerleriyle) ve bir filtre verildiğinde, verilen stride ile evrişim çıktısını kâğıt üzerinde hesaplayabilmek gerekir.
- Çıktı boyutu ve parametre sayısı hesabı
  - $(N - F + 2P)/S + 1$ formülü ve parametre sayısı hesabı "basit ama yapıyı çözmek için çok önemli"; hoca bu hesapların akılda kalmasını istedi.
  - Çıkış derinliğini filtre sayısı belirler; filtrenin derinliği girdinin derinliğine eşittir.
- ReLU'nun önemi
  - Çok sayıda örnek ve güçlü donanımın yanında, çok sayıda katman ve katmanlar arasına konan ReLU, derin ağların başarısının en önemli anahtarı olarak anlatıldı.
- Softmax
  - Hoca softmax'ı anlatılanlar içindeki en önemli kısımlardan biri olarak niteledi: skorları olasılık gibi yorumlanabilir hale getirir.
- Hazır mimarileri anlamak
  - Hazır mimarileri kullanmak yetmez; katmanlarını incelemek ve anlamak gerekir. Bir bağlantıyı değiştirerek yeni bir mimari üretmek mümkündür.

## Kısa Tekrar Notları

- CIFAR-10: 10 sınıf, $32 \times 32 \times 3$, 50 000 eğitim / 10 000 test.
- MNIST: 10 rakam, $28 \times 28$ gri, 60 000 eğitim / 10 000 test; düzleştirilince 784 boyut.
- Çıktı boyutu: $(N - F + 2P)/S + 1$; çıktı derinliği = filtre sayısı $K$.
- Aynı boyutu korumak için ($S=1$): $P = (F-1)/2$.
- Bir evrişim katmanının parametre sayısı: $(F \cdot F \cdot D_1 + 1) \cdot K$ (sapma dahil).
- $32 \times 32 \times 3$, 10 filtre $5 \times 5 \times 3$, $S=1$, $P=2$ → çıktı $32 \times 32 \times 10$, parametre $76 \cdot 10 = 760$.
- Max pooling $2 \times 2$, stride 2: boyutu yarıya indirir, parametresi yoktur.
- Sigmoid $(0,1)$, tanh $(-1,1)$, ReLU $\max(0,x)$.
- Softmax: $e^{s_k} / \sum_j e^{s_j}$; çıktılar $(0,1)$ aralığında ve toplamı 1.
- AlexNet 8 katman (2012), VGG 16/19 katman (%7,3), GoogLeNet Inception (2014), ResNet 152 katman (%3,57).

## Detaylı Açıklamalar

- Evrişim örneği (ekrandan, 00:35:00): $6 \times 6$ ikili görüntü ve ana köşegeni 1, diğer gözleri $-1$ olan $3 \times 3$ Filtre 1 kullanılır. Filtre sol üst köşeye oturtulur, dokuz çarpım toplanır: köşegendeki üç 1 ile filtrenin üç 1'i çarpılır, diğer gözler 0 olduğundan sonuç $3$ olur. Stride 1 ile çıktı $4 \times 4$ olur:

  ```text
  Filtre 1, stride 1:      Filtre 2 (dikey), stride 1:
   3  -1  -3  -1           -1  -1  -1  -1
  -3   1   0  -3           -1  -1  -2   1
  -3  -3   0   1           -1  -1  -2   1
   3  -2  -2  -1           -1   0  -4   3
  ```

  Filtre 1 iki yerde en büyük değeri (3) verir; bunlar görüntüdeki iki köşegen çizginin yerleridir. Stride 2 seçildiğinde pencere her adımda iki piksel kayar; ikinci pencerede üç tane 1 değeri $-1$ katsayılarıyla çarpıldığı için sonuç $-3$ olur (ekrandan, 00:35:00). Değerler python ile doğrulandı.
- Max pooling örneği (ekrandan, 01:30:00): Filtre 1'in $4 \times 4$ çıktısı dört $2 \times 2$ bloğa ayrılır, her bloğun en büyüğü alınır. Sonuç Filtre 1 için $\begin{bmatrix} 3 & 0 \\ 3 & 1 \end{bmatrix}$, Filtre 2 için $\begin{bmatrix} -1 & 1 \\ 0 & 3 \end{bmatrix}$ olur (python ile hesaplandı).
- Çıktı boyutu formülündeki "+1", filtrenin merkez pikselini hesaba katmak içindir: filtre boyutları tek sayıdır. Bölme tam çıkmıyorsa filtre görüntü üzerinde tam adımlarla kaydırılamaz.
- Formülün kontrolü: $N = 7$, $F = 5$, $P = 2$, $S = 1$ için $(7 - 5 + 4)/1 + 1 = 7$; çıktı girdiyle aynı boyuttadır.
- Parametre sayısı (ekrandan, 00:55:00): $5 \times 5 \times 3$ bir filtrenin $75$ ağırlığı ve $1$ sapması vardır, toplam $76$; 10 filtre için $760$ parametre.
- Tam bağlantılı katman ileri geçiş örneği (ekrandan, 02:00:00):

  $$W = \begin{bmatrix} 0{,}2 & -0{,}5 & 0{,}1 \\ 2{,}0 & 1{,}5 & 1{,}3 \\ 0{,}5 & 0{,}0 & 0{,}25 \\ -0{,}3 & 2{,}0 & 0{,}0 \end{bmatrix},\quad x = \begin{bmatrix} 0{,}1 \\ 0{,}2 \\ 0{,}3 \end{bmatrix},\quad b = \begin{bmatrix} 1{,}0 \\ 3{,}0 \\ 0{,}025 \\ 0{,}0 \end{bmatrix}$$

  Birinci satır: $0{,}2 \cdot 0{,}1 - 0{,}5 \cdot 0{,}2 + 0{,}1 \cdot 0{,}3 = -0{,}05$; sapmayla $0{,}95$. Diğerleri $3{,}89$; $0{,}15$; $0{,}37$. En büyük skor $3{,}89$ olduğundan tahmin "olumlu" (positive) sınıfıdır.
  - **Ders sonrası not:** Hoca son skoru sözlü olarak $0{,}037$ dedi; slaytta ve hesapta doğrusu $0{,}37$'dir ($-0{,}03 + 0{,}4 + 0 = 0{,}37$).
- Softmax örneği (ekrandan, 02:25:00): $e^{3{,}2} \approx 24{,}5$, $e^{5{,}1} \approx 164{,}0$, $e^{-1{,}7} \approx 0{,}18$; toplam yaklaşık $188{,}68$ (yuvarlanmış değerlerle). Olasılıklar $24{,}5/188{,}68 \approx 0{,}13$, $0{,}87$ ve $0{,}001$. İkinci sınıfın olasılığı yaklaşık %87'dir.
  - **Ders sonrası not:** Hoca üçüncü değeri "e üzeri 1,7" diye okudu; doğrusu $e^{-1{,}7} \approx 0{,}18$'dir.
- AlexNet boyut hesabı (ekrandan, 02:35:00): $227 \times 227 \times 3$ girdiye ($224 \times 224$'ten dolguyla) 96 tane $11 \times 11$ filtre, $S = 4$, $P = 0$: $(227 - 11)/4 + 1 = 55$, çıktı $55 \times 55 \times 96$. İlk katmanın ağırlık sayısı $11 \cdot 11 \cdot 3 \cdot 96 = 34\,848 \approx 35$ bin. Ardından $3 \times 3$, $S = 2$ max pool: $(55 - 3)/2 + 1 = 27$, çıktı $27 \times 27 \times 96$; havuzlama derinliği değiştirmez ve parametresi yoktur. Sonra 256 tane $5 \times 5 \times 96$ filtre ($S=1$, $P=2$) ile $27 \times 27 \times 256$; beş evrişim katmanının sonunda $6 \times 6 \times 256$ öznitelik elde edilir. Ardından 4096 düğümlü iki tam bağlantılı katman ve softmax çıkış katmanı gelir. AlexNet filtreleri ikiye bölüp (ör. 48 + 48) iki işlemciye dağıtmıştır.
- VGG-16'nın ilk katmanı: $224 \times 224 \times 3$ girdiye 64 tane $3 \times 3 \times 3$ filtre, $3 \cdot 3 \cdot 3 \cdot 64 = 1728$ ağırlık.
  - **Ders sonrası not:** Hoca toplam parametre sayısını 128 milyon dedi; slaytta 140 milyon yazıyor. VGG-16'nın parametre sayısı büyük olasılıkla yaklaşık 138 milyondur.
- Inception modülü: önceki katmanın çıktısı paralel dallara ayrılır. Derste anlatıldığı kadarıyla bir dalda $1 \times 1$ evrişim filtreleri vardır, bir dalda çıktı araya başka evrişim konmadan üstteki evrişim modülüne aktarılır, bir dalda ise önce max pooling uygulanıp sonra evrişime girilir. Dalların çıktıları art arda eklenerek (concatenation) birleştirilir. <!-- BELİRSİZ: modül şemasındaki dalların tam listesi (3x3, 5x5 dalları) karede görülmedi -->. $1 \times 1$ filtre uzamsal olarak $1 \times 1$'dir ama girdi derinliği kadar (ör. $1 \times 1 \times 128$) derinliği vardır.
- ResNet artık bloğu (ekrandan, 02:50:00): düz katmanlarda $x$ evrişim-ReLU-evrişimden geçip $H(x)$ olur. Artık blokta bu çıktı $F(x)$ girdiye eklenir: $H(x) = F(x) + x$. Mimarideki atlamalar (skip connection) bu toplamayı gösterir.
- Keras MNIST örneği (ekrandan, 03:00:00): görüntüler 255'e bölünerek $[0,1]$ aralığına normalleştirilir. Model 5 epok eğitildiğinde kayıp $0{,}2214 \to 0{,}0984 \to 0{,}0689 \to 0{,}0535 \to \dots$ diye azalır, eğitim doğruluğu $0{,}9347$'den $0{,}98$'in üzerine çıkar. Test kümesinde doğruluk yaklaşık $0{,}979$, kayıp yaklaşık $0{,}07$ bulundu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
