# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin konu akışı (ekrandan, 00:50:00)
  - Bilgisayarla görmeye giriş; Python ve NumPy'a hızlı bir giriş; görüntü oluşumu ve görüntü dosyası biçimleri.
  - Görüntüyü anlama, parlaklık dönüşümü (intensity transformation), uzamsal filtreleme ve gürültü azaltma (ortalama yerine medyan filtresi gibi filtreler).
  - Uzamsal filtrelerle keskinleştirme; görüntünün birinci türevi (gradyan) ve ikinci türevi (Laplace operatörü); filtre ile görüntü arasındaki konvolüsyon işlemi.
  - Global eşikleme (thresholding), bağlantılı bileşen etiketleme (connected component labeling), matematiksel morfoloji, doğru ve çember bulmak için Hough dönüşümü, iris bölgesini bulmakta kullanılan integro-diferansiyel operatör.
  - 2B dönüşümler, sınır takibi (boundary following), bölge özellikleri (region properties).
  - İlgi noktası bulma (Harris köşe dedektörü, HOG öznitelikleri).
  - Evrişimli sinir ağları (CNN), derin ağlar ve max pooling; aktivasyon fonksiyonları, tam bağlantılı (fully connected) katman ve softmax.
  - Derin öğrenmede optimizasyon, düzenlileştirme (regularization), dropout, veri artırma (data augmentation) ve transfer öğrenme.
- Çalışma ortamı
  - Uygulamalar Python ile, Jupyter Notebook üzerinde yapılır. Anaconda kurulması önerildi; TensorFlow ve Keras bu dağıtımda içe aktarılarak kullanılabilir.
  - Hoca TensorFlow (Keras üzerinden) kullanır; başka çerçeveler de denenebilir.
- Bilgisayarla görme sisteminin bileşenleri (ekrandan, 01:20:00)
  - Aydınlatma (lighting), sahne (scene), kamera ve bilgisayar. Sahne önce aydınlatılır, kamerayla görüntüsü alınır, bilgisayara aktarılır ve bilgisayarda yorumlanır (scene interpretation).
- Dijital görüntü: örnekleme ve nicemleme (ekrandan, 01:25:00)
  - Örnekleme (sampling): 2B uzayın düzenli bir ızgara üzerinde örneklenmesi; bilgisayardaki karşılığı çözünürlüktür (kaç satır, kaç sütun).
  - Nicemleme (quantization): her örneğin en yakın tam sayıya yuvarlanması; her pikselin kaç bitle ifade edildiği. 8 bit, $2^8 = 256$ parlaklık seviyesi demektir.
  - Örnekler $\Delta$ aralıklıysa: $f[i,j] = \text{Quantize}\{ f(i\Delta, j\Delta) \}$. Görüntü artık tam sayılardan oluşan bir matristir; $i$ satır, $j$ sütun indeksidir.
  - Gri seviyeli görüntüde 0 siyahı, 255 beyazı gösterir.
- Görüntü işlemenin adımları (ekrandan, 01:30:00)
  - Görüntü edinme, iyileştirme (enhancement), renkli görüntü işleme, onarma (restoration), sıkıştırma, bölütleme (segmentation), temsil ve betimleme, sınıflandırma ve tanıma. Hepsi ortadaki bir bilgi tabanıyla (knowledge base) etkileşir.
- Parlaklık dönüşümü örnekleri
  - Negatif görüntü: $s = 255 - r$.
  - Gamma düzeltmesi: $s = c\,r^{\gamma}$ (ekrandan, 01:35:00). $\gamma > 1$ görüntüyü koyulaştırır, $\gamma < 1$ aydınlatır, $\gamma = 1$ doğrusaldır.
  - Kontrast germe (contrast stretching): $(r_1, s_1)$ ve $(r_2, s_2)$ noktalarından geçen parçalı doğrusal $T(r)$ fonksiyonu; en uç hali eşiklemedir (ekrandan, 01:40:00).
- Histogram ile görüntü tanılama
  - Karanlık görüntünün histogramı sola (0'a yakın), aydınlık görüntününki sağa yığılır; düşük kontrastlı görüntü yalnız orta bölgedeki dar bir aralığı kullanır; iyi bir görüntüde hem siyah hem beyaz tarafta piksel vardır.
- Uygulama alanları
  - Akıllı belge tanıma (karakter tanıma, alan çıkarma, robotik süreç otomasyonu).
  - Biyometri: parmak izi, iris, ses, yüz, el şekli, imza (ekrandan, 01:50:00). Kimliklendirme (identification, 1'e N) ile doğrulama (authentication, 1'e 1) farkı.
  - Hava fotoğraflarının yorumlanması, trafik izleme (ekrandan, 01:55:00), spor ve eğlence, derinlik kamerası (Kinect, RGB-D), yüz bulma (Viola-Jones, 2001), yüz tanıma (PCA, eigenfaces), yüz ifadesi tanıma (ekrandan, 02:00:00), el duruşu ve el hareketi (işaret dili) tanıma, insan aktivitesi tanıma (ekrandan, 02:05:00), tıbbi görüntü analizi.
- Nesne tanımanın tarihçesi
  - SIFT (Scale Invariant Feature Transform), HOG (Dalal ve Triggs, CVPR 2005) (ekrandan, 02:10:00), Pascal VOC yarışması (20 nesne sınıfı), ImageNet yarışması (1000 sınıf, 1.431.167 görüntü) (ekrandan, 02:15:00).
  - CNN yapısı: giriş, art arda konvolüsyon + ReLU ve pooling, düzleştirme (flatten), tam bağlantılı katmanlar ve softmax (ekrandan, 02:20:00).
  - Görüntü altyazılama (image captioning).

## Hocanın Özellikle Vurguladığı Kısımlar

- Klasik yöntemde öznitelik mühendisliği, derin öğrenmede otomatik öznitelik
  - Klasik nesne tanımada öznitelikler (Harris köşeleri, HOG gibi) özel algoritmalarla elle tasarlanırdı. CNN'de art arda onlarca konvolüsyon işlemi öznitelikleri otomatik üretir, hatta insanın düşünemeyeceği kadar karmaşık öznitelikleri bulabilir. CNN'lerin nesne tanımada bu kadar başarılı olmasının bir nedeni de öznitelik çıkarmanın sistemin içinde olmasıdır.
- Gamma eğrilerinin okunması
  - Yatay eksende giriş parlaklığı $r$, dikey eksende çıkış parlaklığı $s$ vardır. $L/2$'den bir dikme çıkılır, eğri kesilir ve dikey eksende nereye düşüldüğüne bakılır. $L/2$'nin altına düşülüyorsa eğri görüntüyü koyulaştırır ($\gamma > 1$), üstüne çıkılıyorsa aydınlatır ($\gamma < 1$).
- Düşük kontrastın teknik tanımı
  - Düşük kontrastlı görüntüde tam siyah da tam beyaz da yoktur; parlaklıklar 0-255 aralığının dar bir bölgesine sıkışmıştır. Bir görüntüye bakınca problemi tarif edebilmek, sisteme de bunu histogramla anlatabilmek gerekir.
- Kimliklendirme ve doğrulama ayrı kavramlardır
  - Kimliklendirmede giriş örneği veri tabanındaki N kişinin hepsiyle karşılaştırılır ve bir kimlik döndürülür (1'e N, maliyetli). Doğrulamada kişi kim olduğunu beyan eder, yalnız o kişinin kayıtlarıyla karşılaştırma yapılır (1'e 1) ve bir eşiğe göre evet/hayır döner; daha hızlıdır.
- CNN bir gecede keşfedilmedi
  - Konvolüsyon sinyal işlemede zaten kullanılıyordu; 1989-1999 arasında el yazısı rakam okuma çalışmalarında da kullanıldı. 2012 sonrasındaki sıçramayı GPU'lar, güçlü hesaplama altyapısı ve eğitim örneği sayısının artması sağladı.

## Kısa Tekrar Notları

- Bilgisayarla görme sistemi: aydınlatma, sahne, kamera, bilgisayar.
- Örnekleme = çözünürlük; nicemleme = piksel başına bit sayısı; 8 bit = 256 seviye. Tıbbi DICOM görüntülerinde gri seviye 16 bitle tutulabilir.
- $f[i,j]$: $i$ satır, $j$ sütun; değer pikselin parlaklığıdır.
- Negatif: $s = 255 - r$. Gamma: $s = c\,r^{\gamma}$; $\gamma>1$ koyulaştırır, $\gamma<1$ aydınlatır.
- Histogram sola yığılı: karanlık; sağa yığılı: aydınlık; ortada dar: düşük kontrast.
- İyileştirme (enhancement) ile onarma (restoration) farklıdır: onarma bozulmuş görüntüyü tamamlamaya çalışır.
- JPEG kayıplı sıkıştırmadır; gözle fark edilmeyecek kadar kalite kaybıyla yer kazandırır.
- Identification: 1'e N; authentication: 1'e 1 + eşik.
- SIFT ölçekten bağımsız öznitelik çıkarır. HOG: pencere 8x8 piksellik hücrelere bölünür, her hücre bir yönelim histogramıyla temsil edilir; $16 \times 8 \times 8 = 1024$ boyutlu öznitelik vektörü (ekrandan, 02:10:00).
- ImageNet sınıflandırma yarışmasında hata oranları (%): 2010'da 28,2, AlexNet (2012) 16,4, VGG (2014) 7,3, GoogLeNet (2014) 6,7, ResNet (2015) 3,57; insan hatası 5,1 (ekrandan, 02:15:00).
- CNN: [konvolüsyon + ReLU → pooling] tekrarı → flatten → tam bağlantılı katmanlar → softmax.

## Detaylı Açıklamalar

- Görüntünün oluşumu ve sayısallaştırılması
  - Bir sahnenin görüntülenmesi için önce sahnenin aydınlatılması gerekir. Kamera aydınlatılmış sahnenin görüntüsünü alır ve bilgisayara aktarır; bilgisayar da bu görüntüyü yorumlar. Bilgisayarda görüntü, parlaklık değerlerinden oluşan bir matris olarak tutulur. Analog bir işaretin sayısal hale gelmesi iki adımlıdır: örnekleme ve nicemleme. Örnekleme iki boyutlu düzlemde düzenli bir ızgara üzerinde yapılır ve görüntünün kaç satır ve kaç sütunlu bir matrisle tutulacağını, yani çözünürlüğü belirler. Çözünürlük ne kadar yüksekse görüntü o kadar ayrıntılıdır. Nicemlemede her örnek en yakın tanımlı seviyeye yuvarlanır; bu yuvarlama nicemleme hatasına yol açar. Bir piksel 8 bitle ifade ediliyorsa 256 farklı parlaklık seviyesi vardır. Tıbbi görüntülerde (tomografi, MR) kullanılan DICOM dosyalarında bir piksel 16 bit gri seviyeyle tutulabilir, bu da daha yüksek hassasiyet sağlar. Renkli görüntüde bir piksel 3 ya da 4 bayt ile ifade edilir.
  - > **Ders sonrası not:** Hoca bitmap dosyalarında bir piksel için 4 bayt kullanıldığını söyledi. Büyük olasılıkla BMP biçiminde 24 bit (3 bayt) ve 32 bit (4 bayt, ek bir kanal ya da dolgu ile) seçeneklerinin ikisi de vardır; 4 bayt her zaman geçerli değildir.
- Görüntü işlemenin adımları
  - Görüntü edinme aşamasında sahneden görüntü toplanır; örneğin yüz tanımada bir kişinin farklı açılardan ve farklı ışık koşullarında yüz görüntüleri alınarak tanımanın ne kadar başarılı olduğu ölçülür. İyileştirme, ideal olmayan koşullarda (sisli, bulutlu hava fotoğrafları gibi) alınmış görüntüleri düzeltir. Renkli görüntü işleme RGB gibi renk paletleriyle çalışır; görüntü bazen gri seviyeye çevrilir, bazen doğrudan renkli olarak işlenir. Onarma, aşınmış eski el yazması belgelerin sayısal kopyalarındaki bozulmuş harflerin tamamlanması gibi işlerde kullanılır. Sıkıştırma görüntünün diskte daha az yer tutmasını sağlar. Bölütleme, nesneyi arka plandan ya da başka bir dokudan ayırır; örneğin iris tanımada iris bölgesinin göz fotoğrafından ayrılması. Sınıflandırma ve tanıma bu dersin ana konusudur.
- Gamma düzeltmesi
  - $s = c\,r^{\gamma}$ ifadesinde $r$ giriş parlaklığı, $s$ çıkış parlaklığıdır; slayttaki eğrilerde $c = 1$'dir ve eğriler gösterilen aralığa ölçeklenmiştir (ekrandan, 01:35:00). Çok aydınlık, "patlamış" bir hava fotoğrafı $\gamma$ = 3, 4 ve 5 seçilerek koyulaştırılır ve ayrıntılar görünür hale gelir. $\gamma = 0{,}2$ gibi küçük değerler ise karanlık görüntüleri aydınlatır.
  - > **Ders sonrası not:** Hoca, $c = 1$ ve $\gamma = 1{,}5$ için parlaklığı 10 olan pikselin çıkışını $10^{1{,}5}$ olarak verdi ($\approx 31{,}6$). Büyük olasılıkla uygulamada $r$ önce $[0,1]$ aralığına normalleştirilir ($r/(L-1)$), sonuç yeniden $L-1$ ile çarpılır; aksi halde büyük $r$ ve $\gamma > 1$ için çıkış 255'i aşar. Normalleştirilmiş durumda $r = L/2$ için $\gamma = 2{,}5$ çıkışı yaklaşık $0{,}18(L-1)$, $\gamma = 0{,}2$ çıkışı yaklaşık $0{,}87(L-1)$ olur; bu, eğrilerdeki koyulaştırma ve aydınlatma yorumuyla uyumludur.
- Kontrast ve histogram
  - Histogram, görüntüdeki her parlaklık değerinin kaç kez tekrarlandığını gösterir; yatay eksen 0-255 parlaklık değerleridir. Karanlık görüntüde çubuklar sola, aydınlık görüntüde sağa yığılır; düşük kontrastlı görüntüde yalnız orta bölgedeki dar bir aralık kullanılır. İyileştirilmiş ideal görüntüde hem siyah hem beyaz tarafta piksel bulunur. Kontrast germe, $(r_1,s_1)$ ve $(r_2,s_2)$ noktalarıyla tanımlı parçalı doğrusal bir dönüşümle dar aralığı tüm aralığa yayar (ekrandan, 01:40:00).
- Uygulama alanları
  - Belge tanımada karakterler tanınır, belgenin hangi bölgesinde tarih, sayı ya da kelime olduğu analiz edilir; belge yapısı biliniyorsa bir tarihin "sipariş tarihi" olduğu anlaşılıp çıkarılabilir. Biyometrik tanıma, kopyalanabilir şifrelerin yanına kişinin üzerinde taşıdığı bir özelliği ekleyerek sistemi güçlendirir; yüz tanımada makyaj, sakal, bıyık, saç şekli ve gözlük gibi değişiklikler başarıyı sınırlar. Hava fotoğraflarıyla yapılaşma ve kaçak bina tespiti, tarım arazilerinde ekili ürünün belirlenmesi yapılabilir. Trafik izlemede araç hızı, şerit ihlali, kırmızı ışık ihlali ve trafik yoğunluğu ölçülebilir. Futbolda oyuncuların topu ne kadar tuttuğu ve sahadaki konumları videodan izlenebilir. Kinect kamerası kızılötesi ışık kaynağıyla derinlik bilgisini, ayrıca RGB kamerayla renk bilgisini verir (RGB-D).
  - Yüz ifadesi tanımada slayttaki sekiz ifade: tiksinme, şaşkınlık, üzüntü, öfke, korku, mutluluk, küçümseme ve nötr (ekrandan, 02:00:00). İşaret dilinde parmak heceleme (finger spelling) her harfin sabit bir el duruşuyla (posture) gösterilmesidir ve özel adlar için kullanılır; kelimeler ise hareket (gesture) tabanlıdır ve tanınması daha zordur. Tek tek kelimeler tanınabilse de bunları cümleye dönüştürmek hâlâ zordur. Aktivite tanıma, örneğin havalimanında yerde yatan ya da zıplayan birini anormal durum olarak işaretleyebilir. Tıpta cilt ve meme kanseri dokusunun işaretlenmesi, akciğer tomografisinde buzlu cam ve bal peteği dokusunun hacminin tüm akciğere oranının ölçülmesi gibi çalışmalar vardır.
- HOG, yarışmalar ve CNN
  - HOG yaya tespiti için önerildi: pencere 8x8 piksellik hücrelere bölünür, her hücredeki kenarların yönelimlerinden bir histogram çıkarılır. İnsan kol ve bacakları dikey kenarlar ürettiği için insan figürü arka plandan ayrılabilir. Pascal VOC 20 nesne sınıflı bir yarışmaydı; ImageNet yarışması 1000 sınıfa çıktı. ImageNet'te değerlendirme, modelin tahmin ettiği ilk 1 ya da ilk 5 sınıfın içinde doğru nesnenin olup olmamasına göre yapılır. Hata oranı 2015'te ResNet ile insan hatasının altına indi; ama farklı görüntülerle yapılan sonraki testler bu sistemlerin zaman zaman başarısız olduğunu gösterdi. CNN'de konvolüsyon + ReLU ve max pooling katmanları öznitelikleri üretir, flatten ile matris vektöre çevrilir, tam bağlantılı katmanlar ve softmax sınıflandırmayı yapar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
