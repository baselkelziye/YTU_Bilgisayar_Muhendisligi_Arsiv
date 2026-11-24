# Ders 11 Genişletilmiş Notu: Öğrenci Makale Sunumları: Veri Madenciliği Uygulamaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi
- 2. Sentinel-2 Görüntülerinde Bulut Giderme: DSen2-CR
- 3. Çevrim İçi Pazar Yerlerinde Organize Suç ve Dolandırıcı Tespiti
- 4. Fotoğraflardan Vücut Kitle İndeksi Tahmini
- 5. Katar Yıldızlar Ligi'nde Maç Sonucu Tahmini
- 6. Makine Öğrenmesiyle Biyolojik Dizi Hizalama
- 7. Medikal Görüntülerde Derin Öğrenme
- 8. Kalp Hastalığı Teşhisinde Makine Öğrenmesi
- 9. EEG ile Zihinsel Yorgunluk Tanımada Denekler Arası Transfer Öğrenme
- 10. Örnek Sorular

## 1. Dersin Biçimi

Bu ders, öğrencilerin seçtikleri bir makaleyi sunduğu bir oturumdu. Hoca sunuculardan önce makalenin başlığını göstermelerini ve konuyu neden seçtiklerini açıklamalarını, ardından çalışmayı özetlemelerini istedi. Toplam sekiz sunum dinlendi. Her sunumdan sonra hoca ve öğrenciler soru sordu.

Sunumlar farklı uygulama alanlarından gelse de hepsi dönem boyunca görülen veri madenciliği sürecinin adımlarını izliyordu: verinin nereden ve nasıl toplandığı, temizleme, eksik ve aykırı değer işlemleri, öznitelik seçimi ve çıkarımı, dengesiz veriyle başa çıkma, model seçimi, çapraz doğrulama ve değerlendirme ölçütleri. Bu not her sunumu bu adımlar üzerinden aktarır.

## 2. Sentinel-2 Görüntülerinde Bulut Giderme: DSen2-CR

### 2.1 Problem: Bulut Örtüsü

Uydu görüntüleri doğal afet tespiti, tarımsal izleme ve yüzeydeki değişimlerin takibi gibi işlerde kullanılır. Ancak optik görüntülerde bulutlar ve bulut gölgeleri yüzeyi gizler. Sunumda aktarılan bir bulguya göre son 12 yılda kara parçalarının yaklaşık %55'i bulutla kaplı görünmüştür. Uydu aynı bölgeden belirli bir sıklıkta görüntü aldığı için bulutlu bir görüntü, o tarih için verinin kaybı anlamına gelir. Bu yüzden bulutların altındaki görüntünün yeniden oluşturulması faydalı görülmüştür.

### 2.2 Optik ve SAR Görüntüleri

Optik görüntüler multispektraldir, yani birden fazla dalga boyu bandı içerir. Günlük hayatta yalnız kırmızı, yeşil ve mavi (RGB) bantları kullanırız; uydu görüntülerinde bunlara ek olarak yakın kızılötesi ve kısa dalga kızılötesi bantlar vardır. Optik görüntülerin kullanım alanları bitki örtüsü analizi, kentsel planlama ve doğal afet tespitidir. Multispektral görüntüleme uydularına Sentinel-2, Landsat serisi ve MODIS örnektir (ekrandan, 00:15:00).

SAR (sentetik açıklıklı radar) görüntüleri ise elektromanyetik dalgalarla çalışır ve buluttan etkilenmez. Bu yüzden bulutsuz bilgi verir. Ancak aynı bölgenin optik ve SAR görüntüleri karşılaştırıldığında SAR görüntüsünde, özellikle şehir alanlarında, optik görüntüdeki ayrıntılar görünmez.

Sentinel-2'de görünür, yakın kızılötesi ve kızılötesi olarak bölünmüş 13 spektral bant vardır. Sentinel-1 SAR görüntülerinde VV ve VH polarizasyonları bulunur. Sunucuya göre SAR görüntüleri aynı bölgeden 12 günde bir, Sentinel-2 optik görüntüleri 5 günde bir alınabilir. Yer çözünürlüğü multispektral görüntülerde banda göre 10 ile 60 metre, SAR görüntülerinde 5 ile 25 metre arasındadır.

### 2.3 Veri Seti

Çalışmadaki veri seti bulut giderme için hazırlanmıştır. Farklı kıtalardaki ve farklı mevsimlerdeki 169 bölgeden alınmış, her biri $256 \times 256$ piksel olan toplam 157.521 örnek içerir. Bir görüntü yaklaşık $2{,}5 \times 2{,}5$ km'lik bir alana karşılık gelir. Bölgelerin 149'u eğitim, 10'u doğrulama, 10'u test için ayrılmıştır.

Sunucu, uzaktan algılama çalışmalarında bölgelere göre bölmenin mantıklı olduğunu vurguladı: yer şekli, yer örtüsü ve hatta bulutların oluşma biçimi bölgeye bağlıdır. Aynı bölgeden görüntüler hem eğitimde hem testte olursa model o bölgeyi ezberleyebilir.

Her örnek üç görüntüden oluşur: bulutlu optik görüntü, aynı bölgenin SAR görüntüsü ve hedef olan bulutsuz optik görüntü. Hedef görüntü, bulutlu görüntüden farklı bir tarihte alınmıştır.

### 2.4 Model: ResNet Yaklaşımıyla Bulut Giderme

Önerilen model DSen2-CR'dir ve ResNet yaklaşımına dayanır. ResNet bazı katmanları atlayan bağlantılarla (skip connection) bilgiyi doğrudan geçirir ve bilgi kaybını azaltır. Ağ, girdinin kendisini değil girdiye eklenecek artığı (residual) öğrenir; yani girdiye bir düzeltme ekleyerek çıktıyı üretir. Bu sayede bulut olmayan bölgelerin yüzey bilgisi çıktıya doğrudan ve değişmeden aktarılabilir (ekrandan, 00:20:00).

Model diyagramı (ekrandan, 00:20:00) şu akışı gösterir:

```text
SAR girdi (2, m, m)      Optik girdi (13, m, m) ──────────────┐
          └──────────┬──────────┘                            │
              Concat (15, m, m)                              │
              Conv   (F, m, m)                               │
              ReLU   (F, m, m)                               │
              ResBlock (F, m, m)   } B kez                   │
              ...                                            │
              ResBlock (F, m, m)                             │
              Conv   (13, m, m)  ── çıktı (artık) ──> (+) <──┘
                                                       │
                                            Bulutsuz tahmin (13, m, m)
```

İki polarizasyonlu SAR görüntüsü ile 13 bantlı optik görüntü birleştirilir, evrişim ve ReLU'dan sonra ResBlock'lar tekrarlanır. Son evrişim kanal sayısını tekrar 13'e indirir ve bu çıktı optik girdiye eklenir.

### 2.5 CARL Kayıp Fonksiyonu

Çalışma ek olarak CARL (cloud-adaptive regularized loss) adlı bir kayıp fonksiyonu önerir. Amaç, ağın bulut olmayan kısımları gereksiz yere değiştirmesini önlemek ve bulutlu kısımlara odaklanmasını sağlamaktır. Ortalama mutlak hatanın (MAE) yanında bir bulut maskesi kullanılır: bulutlu ve gölgeli bölgelerde tahmin ile hedef görüntü arasındaki hata, temiz bölgelerde ise tahmin ile girdi görüntüsü arasındaki fark ölçülür.

Bunu göstermek için yazarlar bulutsuz bir girdi ve bulutsuz bir hedef görüntü üzerinde deneme yapmıştır. İki görüntü arasında mevsimsel farklar vardır. Yalnız MAE ile eğitilen model girdiyi bütünüyle hedefe benzetmeye çalışırken CARL ile eğitilen model bulut olmayan bölgeleri değiştirmemiştir.

> **Ek bilgi (derste anlatılmadı):** Özgün makalede CARL büyük olasılıkla şu biçimdedir: $\mathcal{L}_{CARL} = \frac{1}{N}\sum \left[ M \odot |P - T| + (1 - M) \odot |P - I| \right] + \lambda \frac{1}{N}\sum |P - T|$. Burada $P$ tahmin, $T$ hedef, $I$ girdi optik görüntü, $M$ bulut ve gölge maskesidir. Son terim, tahminin genel olarak hedeften uzaklaşmasını küçük bir ağırlıkla cezalandıran düzenlileştirmedir.

### 2.6 Ön İşleme ve Model Parametreleri

Ekrandaki slayta göre (ekrandan, 00:25:00):

- Giriş ve ön işleme: Görüntüler piksel hatalarından arındırılmak için kırpılır. Sentinel-2 bantları için kırpma aralığı $[0, 10000]$, Sentinel-1 VV ve VH polarizasyonları için $[-25, 0]$ ve $[-32{,}5, 0]$'dır.
- Normalizasyon: Sentinel-2 bant pikselleri 2000'e bölünür. Sentinel-1 değerleri pozitif alana kaydırıldıktan sonra $[0, 2]$ aralığına getirilir.
- Veri artırma: Rastgele döndürme ve yatay-dikey yansıtma.
- Eğitim: Ağırlıklar He uniform dağılımıyla başlatılır, Nesterov momentumlu Adam kullanılır, öğrenme oranı $7 \times 10^{-5}$, batch boyutu 16'dır.

Sunucu SAR görüntülerinde kırpmanın önemli olduğunu belirtti: alınabilecek çok fazla bilgi vardır ve ilgilenilen aralığa odaklanmak gürültüyü azaltır. Sentinel-2'nin 2000'e bölünmesi büyük olasılıkla iki kaynağı benzer ölçeğe getirmek içindir.

### 2.7 Sonuçlar

Örnek çıktılarda model, büyük bir bulutun altını oldukça iyi tahmin etmiş, parçalı bulutlu görüntülerde kısmen başarılı olmuştur. Şehir alanlarında ise yeniden kurma zayıftır, çünkü binalardaki ayrıntılar SAR görüntüsünden elde edilemez ve gürültü gibi algılanabilir. Yazarlar SAR kullanımının tarım alanları gibi yapılarda önemli olduğunu, şehir gibi karmaşık alanlarda ise iki kaynağın birleştirilmesinin zorlaştığını söyler. Yalnız optik görüntü kullanmak genel olarak iyi sonuç vermemiştir.

Sayısal değerlendirmede üç ölçü kullanılmıştır:

- target: üretilen görüntü ile hedef görüntü arasındaki hata.
- repro: bulutsuz kısımların ne kadar bozulduğu.
- recon: bulutlu ve gölgeli bölgeler ile hedef görüntü arasındaki yeniden üretme hatası.

CARL ile recon değerinde iyileşme görülmüştür. SAR kullanılmadığında bulutsuz kısımlarda daha başarılı, bulutlu kısımlarda daha başarısız sonuç alınmıştır; yani SAR'ın hem avantajı hem dezavantajı vardır. pix2pix modeliyle karşılaştırıldığında bütün kayıp ölçütlerinde iyileşme raporlanmıştır. Görsel karşılaştırmada (ekrandan, 00:30:00) sütunlar sırasıyla girdi optik, girdi SAR, hedef optik, DSen2-CR çıktısı ve pix2pix çıktısıdır; pix2pix'in bulut yapısını ve gölgeleri tam gideremediği görülür.

## 3. Çevrim İçi Pazar Yerlerinde Organize Suç ve Dolandırıcı Tespiti

### 3.1 Problemin Önemi

İkinci sunum, çevrim içi pazar yerlerinde organize perakende suçu yapan satıcıların makine öğrenmesiyle tespitini ele alan, 2023'te yayımlanmış bir çalışmaydı. Kredi kartı dolandırıcılığı gibi konularda çok çalışma olsa da organize suç odaklı çalışma azdır. Makale kamuyla yeterli veri paylaşılmadığını eleştirir, ama bazı bilgilerin açıklanmaması gerektiğini de kabul eder; çünkü dolandırıcılar kendilerini yayımlanan yöntemlere göre geliştirir.

İnternet suçları şikâyet merkezi bu dolandırıcılığı altı kategoriye ayırmıştır: ürünün teslim edilmemesi, eksik ürün teslimi, üçgenleme ya da kara para aklama amaçlı satış, toplu satış miktarı, fiyat belirleme gibi. Ekrandaki slayta göre perakendeciler 2020'de her 1 milyar dolarlık satışta ortalama 719.548 dolar kaybetmiştir; bu değer 2019'da 703.320, 2015'te 453.940 dolardır (ekrandan, 00:35:00). Pandemiyle e-ticaretin artması ve koruyucu yasaların yetersizliği dolandırıcıları çevrim içi ortama yöneltmiştir.

### 3.2 Çalışmanın Akışı

Veri, organize suç uzmanları tarafından etiketlenmiştir ve dengesizdir (dolandırıcı satıcılar azınlıktır). Verideki öznitelikler sayısal, kategorik ve metindir. Yazarlar metin özniteliklerinin yeterli katkı sağlamayacağını düşünerek onları çıkarmış, sayısal ve kategorik özniteliklerle devam etmiştir.

- Deney 1: Herhangi bir dengeleme tekniği uygulanmadan 7 sınıflandırıcı seçilir ve $k$ katlı çapraz doğrulamayla test edilir.
- Deney 2: Tek bir sınıflandırıcı yerine birden fazla sınıflandırıcının birleşiminin daha iyi sonuç verip vermeyeceği araştırılır.
- Deney 3: Ön işleme ve dengeleme eklenir; çıkan model satıcıları "dolandırıcı" ya da "değil" diye etiketler.

### 3.3 Veri ve Ön İşleme

Veriler dünya çapında bilinen bir perakende platformundan alınmıştır ve 3606 ABD'li satıcıya dayanır. Veri çok büyük olduğu için son 90 gündeki satışlar alınmıştır. Eksik değerler için şu kural uygulanmıştır: bir öznitelik sütununda eksik değer oranı %20'nin altındaysa eksik değerli örnekler, %20'nin üstündeyse o sütun atılır. Sonunda yaklaşık 50 bin kayıtla çalışılmıştır. Öznitelikler ürüne ve kullanıcıya bağlı olanlar diye gruplanmıştır.

Ön işleme adımları (ekrandan, 00:40:00):

- Veri temizleme: tekrarlanan ilanların silinmesi, eksik değer işlemi, aykırı değer işlemi.
- Öznitelik mühendisliği: one-hot kodlama, yeni öznitelik üretme, normalleştirme ve ölçekleme.

Aykırı değer için fiyat örneği verildi: bir ürünün fiyatı aykırı olabilir. Standart sapma ölçütü kullanılmış, ortalamadan 3 standart sapmadan fazla uzaklaşan değerler aykırı sayılmıştır.

### 3.4 Dengesiz Veriyle Başa Çıkma

Azınlık sınıfının verisi artırılırsa başarının artacağı düşünülmüştür. Bunun için SMOTE kullanılmıştır. SMOTE, Öklid uzaklığıyla bulunan komşular arasında sentetik örnekler üretir; bu sayısal veri için uygundur. Çalışmada kategorik öznitelikler de olduğu için onun kategorik verilerle çalışabilen sürümü SMOTE-NC tercih edilmiştir.

Yalnız çoğaltmanın da dezavantajları olduğu için iki alt örnekleme tekniği eklenmiştir: Tomek bağları (Tomek links) ve Edited Nearest Neighbors (ENN). Bunlar sınıf sınırına yakın, karşı sınıfa çok benzeyen örnekleri silerek iki sınıf arasındaki mesafeyi artırmaya çalışır.

> **Ek bilgi (derste anlatılmadı):** SMOTE, bir azınlık örneği $x$ ile ona en yakın azınlık komşularından biri $x_{nn}$ arasında $x_{yeni} = x + \delta (x_{nn} - x)$, $\delta \in [0,1]$ biçiminde yeni bir nokta üretir. Tomek bağı, birbirinin en yakın komşusu olan ve farklı sınıflara ait iki örnektir; çoğunluk sınıfındaki üye silinir. ENN ise komşularının çoğunluğuyla aynı sınıfta olmayan örnekleri siler.

### 3.5 Doğrulama ve Sonuçlar

Doğrulama için $k = 5$ katlı çapraz doğrulama kullanılmıştır; yazarlar literatür taramasında 5'in uygun olduğunu görmüştür. Eğitim verisi %80 eğitim, %20 doğrulama olarak ayrılmış, test için bu örneklerin dışından ayrı örnekler kullanılmıştır. Veri SQL ile çekilmiş, çalışma Python ile yapılmıştır.

Dengelemeden önceki sonuçlarda test ve doğrulama başarısı iyi görünmüş, ama model gerçek test ortamına konulduğunda başarı belirgin biçimde düşmüştür. Bu yüzden dengelenmiş verideki sonuçlara bakılmış ve en iyi modelin Balanced Random Forest olduğu görülmüştür. Dengesiz veride doğruluk (accuracy) güvenilir olmadığı için ROC eğrisi de hesaplanmıştır.

Özniteliklerin etkisini ölçmek için SHAP değerleri kullanılmıştır. SHAP oyun teorisinden gelir: bir oyuncunun oyunun sonucuna ne kadar katkı yaptığını ölçer gibi, her özniteliğin tahmine katkısını ölçer. Böylece en önemli 10 öznitelik seçilmiştir.

Yazarlar gelecekte metin ve görsel verilerin de kullanılmasını, uzman etiketlemesine bağımlılığın azaltılmasını önermiştir. Dolandırıcılar da kendilerini geliştirdiği için bu sistemlerin sürekli güncellenmesi gerekir.

## 4. Fotoğraflardan Vücut Kitle İndeksi Tahmini

### 4.1 Motivasyon ve Önceki Çalışmalar

Üçüncü sunum, kişilerin fotoğraflarından vücut kitle indeksini (VKİ, BMI) tahmin eden bir çalışmaydı. Pandemi sonrasında obezite ve aşırı zayıflığın arttığı belirtilir. VKİ, kilonun boyun karesine bölünmesiyle bulunan basit bir ölçüdür:

$$\text{VKİ} = \frac{\text{kilo (kg)}}{\text{boy (m)}^2}$$

Ancak toplu ölçüm yapmak maliyetli ve zaman alıcıdır. Önceki çalışmalarda vücuttaki kas ve yağ dağılımı, kemik yoğunluğu ölçümü için tıpta kullanılan X ışınlı DEXA yöntemiyle ya da oyun konsollarında kullanılan, vücut parçalarını uzaktan algılayan sistemlerle tahmin edilmiştir. Bu çalışma ise CNN ile fotoğraftan tahmin yapar.

### 4.2 Veri Seti ve Ön İşleme

Çalışma 161 kişiyle yapılmıştır ve yazarlar veri setinin küçüklüğünden yakınır. <!-- BELİRSİZ: altyazıda "79'lik adın toplamda 161 kişinin" deniyor; 79 sayısının neyi gösterdiği (ör. bir alt grup) anlaşılmıyor. --> Katılımcılar mümkün olduğunca farklı fenotiplerden seçilmiştir. Fotoğraflar filtrelerden geçirilerek silüete dönüştürülür; böylece arka plandaki gereksiz bilgi azaltılır.

Veri az olduğu için ön işlemede kayıp vermemeye çalışılmıştır. Yazarlar aykırı değerleri bilerek atmamıştır: hem veri seti küçüktür hem de görülmek istenen şey zaten uç değerlerdir. Veri %60 eğitim, %20 doğrulama, %20 test olarak bölünmüştür. Standartlaştırma sonrası VKİ ortalaması yaklaşık 26,4, yayılım değeri 5,75 olarak verilmiştir.

### 4.3 Modeller

CNN'den önce öznitelik çıkarımı için iki filtre seçilmiştir: Gabor filtresi ve yönlü gradyan histogramı (HOG). Bunlar üç regresyon modeliyle (Random Forest, XGBoost, SVM) birleştirilerek altı varyasyon oluşturulmuş, ayrıca bir CNN denenmiştir. Her model için optimizasyon sürecinde 40 iterasyonlu iki tur çapraz doğrulama yapılmış, her turda parametre arama alanı daraltılmıştır. Çalışma Python, Keras ve TensorFlow ile yapılmıştır.

CNN, VGGNet (Oxford Visual Geometry Group) tabanlı bir mimaridir. Ekrandaki mimari şekli (ekrandan, 00:55:00) şu katman sırasını gösterir:

```text
Girdi (silüet)
→ Conv2D → Activation → Batch Normalization → Max Pooling 2D
→ Conv2D → Activation → Batch Normalization → Max Pooling 2D
→ Flatten → Dense → Activation → Batch Normalization → Dropout
→ Dense → Activation → Dense → Dense (tek çıktı: VKİ)
```

Ekrandaki ödev metnine göre hiperparametreler GridSearch ile seçilmiş; en iyi değerler 0,01 öğrenme oranı ve $1 \times 10^{-5}$ azalma oranıyla Adam olarak bulunmuştur. Kayıp fonksiyonu ortalama kare hatadır (MSE). Eğitim 80'lik batch, epok başına eğitim kümesi uzunluğunun 0,25 katı kadar adım ve en fazla 200 epokla yapılmış, performans değişmeyince erken durdurulmuştur (ekrandan, 00:55:00). Her iterasyonda veri artırma uygulanmıştır.

### 4.4 Sonuçlar

Çapraz doğrulama sonuçları (ekrandan, 00:55:00), ortalama hata:

| Model | 5 katlı | 10 katlı |
|---|---|---|
| Gabor-RF | 0,29 | 0,26 |
| HOG-RF | 0,38 | 0,37 |
| Gabor-XGB | 19,78 | 10,27 |
| HOG-XGB | 7,56 | 0,66 |
| Gabor-SVM | 0,20 | 0,26 |
| HOG-SVM | 0,29 | 0,32 |
| CNN | 0,017 | 0,021 |

CNN her iki çapraz doğrulamada da en düşük hatayı vermiştir ve çalışmanın devamında CNN kullanılmıştır.

> **Ders sonrası not:** Sunucu CNN'in diğerlerinden "yaklaşık 3 katı daha iyi" sonuç verdiğini söyledi; tabloya göre CNN'in 5 katlı hatası (0,017), en iyi klasik model olan Gabor-SVM'in hatasından (0,20) yaklaşık 12 kat küçüktür.

Sonuçlar iki grafikle incelenmiştir. Birincisi tahmin ile gerçek VKİ arasındaki farkları gösteren sapma grafiğidir; noktalar homojen dağılmıştır. İkincisi gerçek ve tahmin edilen VKİ değerlerinin regresyon grafiğidir. Bu grafikte iki doğru vardır: tahminin gerçeğe tam eşit olduğu ideal durumu gösteren özdeşlik doğrusu (identity line) ve hataların hem $x$ hem $y$ ekseninde olduğunu kabul eden Deming regresyon doğrusu. İki doğru birbirine çok yakındır.

Son modelin başarımı (ekrandan, 01:00:00):

| Ölçüt | Ortalama | En iyi |
|---|---|---|
| Doğrulama kaybı | 0,124 | 0,0625 |
| Pearson korelasyon katsayısı | 0,928 | 0,976 |
| Ortalama mutlak hata (MAE) | 1,66 | 1,20 |
| Kök ortalama kare hata (RMSE) | 2,16 | 1,52 |

> **Ders sonrası not:** Altyazıda doğrulama kaybı ortalaması 0,114 ve en iyi değer 0,062 olarak geçiyor; ekrandaki tabloda 0,124 ve 0,0625 yazıyor.

VKİ kategorileri (ekrandan, 01:00:00): $\text{VKİ} < 18{,}5$ zayıf; $18{,}5 \le \text{VKİ} < 25$ normal; $25 \le \text{VKİ} < 30$ fazla kilolu; $30 \le \text{VKİ} < 35$ 1. sınıf obez; $35 \le \text{VKİ} < 40$ 2. sınıf obez; $\text{VKİ} \ge 40$ 3. sınıf obez.

Sunucu, VKİ'yi genel vücut üzerinden tahmin etmek yerine vücudu parça parça analiz ederek kas ve yağ dağılımını bulmanın daha verimli olabileceğini, kaynakçasında bu şekilde yapılmış bir çalışma da bulunduğunu söyledi.

**Soru (hoca):** Sapma grafiğinde dikey eksen $-2, -4$ diye mi, $-0{,}2, -0{,}4$ diye mi gidiyor? **Cevap:** $-4, -2$ diye gidiyor; sapmalar çoğunlukla $-2$ ile $2$ arasında. Hoca bunun VKİ için küçük bir sapma olup olmadığını sordu; ortalama VKİ 25-30 civarında olduğu için yaklaşık %10'luk bir sapma olduğu, %50 gibi büyük bir hata olmadığı konuşuldu.

**Soru (hoca):** Böyle bir çalışma nerede kullanılır? **Cevap:** Bir bölgedeki topluluğun beslenme alışkanlıklarını, obezite ya da aşırı zayıflık durumunu inceleyen geniş çaplı çalışmalarda VKİ'yi elle hesaplamak yerine kullanılabilir; diyetisyenlerin ya da spor salonlarının kullanabileceği bir uygulamaya dönüştürülebilir. Hoca kışın kalın giyinmiş insanlarda kıyafet yüzünden tahminin zorlaşacağını, spor salonu gibi ortamların daha uygun olabileceğini ekledi.

## 5. Katar Yıldızlar Ligi'nde Maç Sonucu Tahmini

### 5.1 Amaç ve Arka Plan

Dördüncü sunumda, futbolda video yardımcı hakem, gelişmiş kamera sistemleri, giyilebilir teknolojiler ve büyük veri sağlayıcılarıyla birlikte hiç olmadığı kadar veri bulunduğu, bunun makine öğrenmesi projeleri için önemli olduğu anlatıldı. Rakip analizi ve genç yetenek keşfi bu verilerin kullanıldığı başlıca alanlardır.

Çalışmanın amaçları (ekrandan, 01:15:00): Katar Yıldızlar Ligi'nde (QSL) maçların kazananını tahmin eden ML modelleri geliştirmek, maç kazanmaya yönelik en etkili performans metriklerini belirlemek, oyunculara performans önerileri ve antrenör ekiplerine stratejik planlama katkısı sunmak.

Benzer çalışmalar: İngiltere Premier Ligi'nde %60, deplasman ve iç saha bilgisi eklenen başka bir çalışmada %68, Çin Süper Ligi'nde şut odaklı bir çalışmada %72, Türkiye Süper Ligi'nde derbi gibi ek bilgiler katılan bir çalışmada %71 başarı bildirilmiştir.

### 5.2 Veri ve Öznitelikler

Veri seti 1121 maç içerir, 6-7 sezonu kapsar ve 2419 futbolcunun verisi incelenmiştir. Devre, maç günü, stadyum ve maç skoru gibi işe yaramadığı düşünülen veriler çıkarılmıştır. Futbolcu bazında dripling, korner, şut ve pas gibi teknik özellikler ile hızlı koşu mesafeleri (ör. 25 km/sa üstü, 20-25 km/sa arası) gibi fiziksel performans metrikleri kullanılmıştır.

Oyuncular kaleci, defans, orta saha ve forvet olarak dört mevkiye ayrılmış, kaleci çok farklı bir mevki olduğu için kaleci metrikleri çıkarılmıştır. Oyuncu bazında 22 öznitelik üç mevki için ayrı hesaplanarak 66 öznitelik elde edilmiş, 3 takım özniteliği eklenerek toplam 69 öznitelik oluşmuştur. <!-- BELİRSİZ: takım öznitelikleri altyazıda "takımın adı, diziliş ve kazanma durumu" olarak geçiyor; kazanma durumu hedef değişken olduğu için üçüncü özniteliğin ne olduğu net değil. -->

### 5.3 Öznitelik Seçimi

Öznitelik seçimi için üç istatistiksel test kullanılmıştır (ekrandan, 01:20:00):

- Anderson-Darling (AD) testi: genel örneklerin izlediği dağılıma uymayan örneklerin tespiti.
- Student t testi: örnekler arasında anlamlı bir fark olup olmadığının tespiti.
- Mann-Whitney (MW) testi: kazanan/kaybeden sınıflarında hep benzer sonuç almış örneklerin tespiti.

Bu testler sonucunda 69 öznitelikten 47'sinin anlamlı olduğuna karar verilmiştir.

### 5.4 Modeller ve Sonuçlar

K en yakın komşu, Random Forest, XGBoost, karar ağacı ve lojistik regresyon gibi algoritmalar denenmiştir. En yüksek başarıyı %80 doğruluk ve 0,91 AUC ile lojistik regresyon vermiştir. Sunucu bunu problemin ikili sınıflandırma olmasıyla açıkladı: yalnız kazanan ve kaybeden sınıfları vardır ve lojistik regresyon ikili sınıflandırmada iyi çalışır.

Mevkilere göre maç kazanmada en etkili özellikler:

- Forvet: isabetli şut, başarılı pas, yüksek hızda kat edilen mesafe.
- Orta saha: başarılı pas, başarılı uzun pas, yüksek hızda kat edilen mesafe.
- Defans: başarılı pas, yüksek hızda kat edilen mesafe, başarılı şut bloklama.

Maç sonucunu tahmin etmek için geçmiş sezon verileri kullanılmış ve kaç sezonluk geçmişin en uygun olduğu araştırılmıştır. 1'den 6'ya kadar sezon kullanıldığında doğruluk değerleri yaklaşık 71, 73, 76, 76, 79 ve 79 olmuştur. 6 sezonda doğrulukta belirgin bir artış olmamış, duyarlılık gibi değerler düşmeye başlamıştır. Bu yüzden son 5 sezon optimal kabul edilmiştir. Ayrıntılı tabloda tek sezonla bir sonraki sezon tahmin edildiğinde 75 civarında doğruluk, 5 sezonla en yüksek 81 civarında doğruluk görülmüştür; ortalama 76 civarındadır.

Çıkarımlar: forvetlerin isabetli şutları maç kazanmada en önemli istatistiktir; pres gücü ve koşu mesafesi bütün mevkiler için ortaktır, yani fiziksel kondisyon her zamankinden önemlidir. Takımlar transfer ve altyapı politikalarında bu bilgileri kullanabilir.

### 5.5 Sınırlılıklar ve Eleştiri

Sınırlılıklar (ekrandan, 01:25:00):

- Yalnız QSL verileri kullanıldığı için model diğer liglere genelleştirilemez.
- Katar küçük bir ülke olduğu için takımlar arası deplasman kavramı Türkiye ya da İngiltere'deki gibi anlam taşımaz. Diğer liglerde deplasman kaybetme oranını artıran önemli bir etkendir.
- Model berabere biten maçları tahmin edememektedir; beraberlikler tamamen çıkarılmıştır.

Sunucu çalışmayı eleştirdi: QSL'de iyi takımlar çok yüksek oranda kazanır. "İlk 6 takım kazanır, son 6 takım kaybeder" gibi basit bir kural bile yaklaşık %70 başarı verir. Aynı kural Türkiye Süper Ligi'nde yaklaşık %60, İngiltere Premier Ligi'nde yaklaşık %58'de kalır. Bu yüzden %80'lik doğruluğun gerçekte ne kadar iyi olduğundan emin olunamaz; problem diğer liglere göre daha kolaydır. Bu, bir modelin başarısının basit bir referans modele (baseline) göre yorumlanması gerektiğini gösteren iyi bir örnektir.

**Soru (hoca):** Model maç skorunu tahmin ederken aradaki farkı mı buluyor, yani 3-2 ya da 5-1 gibi skorlar mı tahmin ediliyor? **Cevap:** Hayır, skorlar kullanılmıyor. Oyuncu bazındaki maç istatistikleri (isabetli şut, isabetli pas, blok sayısı gibi) toplanıp takıma aktarılıyor ve bunlardan maçın kazanılıp kazanılmayacağı tahmin ediliyor.

## 6. Makine Öğrenmesiyle Biyolojik Dizi Hizalama

### 6.1 Dizi Hizalama ve Biyoinformatik

Beşinci sunum, makine öğrenmesiyle ikili dizi hizalama yapan bir çalışmayı inceledi. Biyoinformatik, biyoloji ile matematik, mühendislik ve bilgisayar bilimlerinin birleşiminden doğmuştur; biyolojik verinin boyutu arttıkça problemler elle çözülemez hâle gelmiş ve otomatik sistemlere ihtiyaç duyulmuştur. Çalışma alanları arasında genom montajı, dizi hizalama, ilaç tasarımı ve gen bulma vardır.

Dizi hizalama, biyoinformatiğin en temel görevlerinden biridir ve ikili (pairwise) ve çoklu (multiple) hizalama olarak ikiye ayrılır. Amaç iki dizideki ortak bölgeleri bulmak, yani eşleşme sayısını en büyük yapmaktır. Üç işlem vardır: eşleşme (match), eşleşmeme (mismatch) ve dizileri aynı hizaya getirmek için eklenen boşluk (gap). Sunucu, makalede olmayan küçük bir örnekle bu kavramları gösterdi.

### 6.2 Dinamik Programlama ve Problem

Çalışmanın temelinde Needleman-Wunsch (NW) algoritması vardır. Bu, dinamik programlamaya dayalı bir algoritmadır ve ikili hizalamada en iyi (optimal) çözümü verir. Ancak dizilerin uzunluğu ve sayısı arttıkça bellek kullanımı ve çalışma süresi de artar. Bu yüzden uygulamada sezgisel algoritmalara da başvurulur. İlgili çalışmalarda hizalamayı hızlandırmak için genel amaçlı grafik işlemciler (GPU) kullanılmıştır.

> **Ek bilgi (derste anlatılmadı):** NW algoritması, uzunlukları $n$ ve $m$ olan iki dizi için $(n+1) \times (m+1)$ boyutlu bir skor matrisi doldurur: $F(i,j) = \max\{F(i-1,j-1) + s(a_i, b_j),\ F(i-1,j) + d,\ F(i,j-1) + d\}$. Burada $s$ eşleşme/eşleşmeme skoru, $d$ boşluk cezasıdır. Zaman ve bellek karmaşıklığı $O(nm)$'dir; dizi uzunluğu arttıkça maliyetin hızla büyümesi buradan gelir.

Ekrandaki şekil iki akışı karşılaştırır (ekrandan, 01:35:00):

- (a) Önerilen paralel akış: Girdi dizileri → ML modeli → Etiket çözme (label decoding) → Sonuç.
- (b) Klasik NW sıralı akışı: Girdi dizileri → Matris başlatma → Skor matrisini doldurma → Geri izleme (traceback) → Sonuç üretme.

Önerilen yöntem, DNA ve RNA dizileri için NW algoritmasının makine öğrenmesiyle paralelleştirilmesine dayanır. Amaç hizalamayı hızlandırırken doğruluğu yüksek tutmaktır.

### 6.3 Verinin Kodlanması

DNA ve RNA dizileri dört nükleotitten oluşur. Dinamik programlama kısmı MATLAB'da kodlanmıştır. Nükleotitler modele harf olarak (adenin, sitozin, guanin, ...) değil, ikilik ya da onluk tabanda sayılar olarak verilir.

Hizalama sonucu tek bir satırda gösterilir: iki dizi alt alta yazılmak yerine yan yana getirilir ve ortadaki hizalama bilgisi kullanılır. Dikey çizgi eşleşmeyi, iki nokta eşleşmemeyi, alt çizgi boşluğu gösterir. Daha sonra her nükleotit yıldız ile gösterilerek yalnız hizalama deseni bırakılır ve her desen bir sınıf kabul edilir. Veri indirgeme olarak 10'dan az örneği olan sınıflar elenmiştir.

### 6.4 Önerilen Algoritma ve Sonuçlar

Önerilen algoritmanın adımları (ekrandan, 01:40:00):

```text
Veri temizleme (önerilmez)
→ Öznitelik seçimi (önerilmez)
→ Sınıflandırıcı doğruluğuna göre en iyi veri setlerini arama (eğitim), en iyi sınıflandırıcıyı seçme
→ En iyi modelin değerlendirilmesi (test)
→ Aşırı öğrenmenin önlenmesi
→ Tahmin çalışma süresinin değerlendirilmesi
```

Veri temizleme uygulanmamıştır, çünkü veri kümesinde eksik değer yoktur. Öznitelik seçimi de uygulanmamıştır, çünkü her nükleotit konumu bir özniteliktir ve hepsi önemlidir; aralarında eleme yapılamaz. Veri dönüştürme de yapılmamıştır.

Dinamik programlamayla elde edilen veriler 15 farklı ML modeline verilmiştir (çok katmanlı algılayıcı, destek vektör makinesi, k en yakın komşu, Naive Bayes gibi). 6 veri seti üzerinde, eğitim verisinde çapraz doğrulamayla yapılan karşılaştırmada en iyi sonucu çok katmanlı algılayıcı (MLP, yapay sinir ağı) 3. ve 6. veri setlerinde vermiştir. Ardından MLP farklı optimize edicilerle denenmiş, en iyi sonucu Adam vermiştir ve test Adam ile yapılmıştır. Aşırı öğrenmeyi önlemek için L2 düzenlileştirmenin alfa katsayısı değiştirilmiştir. Son olarak veri setleri karıştırılarak tek bir veri seti oluşturulmuş ve bunun üzerinde yaklaşık %99 başarı elde edilmiştir.

Yazarlar yöntemin protein dizilerine de uygulanabileceğini söyler. Sunucu buna katılmadı: protein dizileri daha uzundur ve veri tabanını oluşturmak zor olacaktır; makaledeki DNA örnekleri de çok uzun değildir. Hoca da dizilerin daha uzun alınmasıyla bir çalışma yapılıp yapılamayacağını merak ettiğini, ama makine öğrenmesinin uygulanma biçimini görmek açısından ilginç bir örnek olduğunu söyledi.

## 7. Medikal Görüntülerde Derin Öğrenme

### 7.1 Giriş

Altıncı sunum, medikal görüntülerde derin öğrenme uygulamalarına genel bir bakış sunan bir derlemeydi. Makine öğrenmesi ilaç keşfinden klinik uygulamalara kadar pek çok alanda kullanılmaktadır ve medikal görüntü analizinde radyologlar için önemli bir destek aracıdır; tanıyı hızlandırır ve insan kaynaklı yanlış tanı ihtimalini azaltır. Görüntüleme yöntemleri arasında BT (CT), MR, PET, ultrason, X ışını, retina taraması, histoloji ve dermoskopi vardır.

Bu alan uzun süredir araştırılsa da GPU'ların artan performansıyla hız kazanmış, 2015-2017 yıllarında CNN'lerin yükselişiyle önemli başarılar elde edilmiştir. CNN'ler sınıflandırma, lokalizasyon, tespit, segmentasyon ve kayıt (registration) işlerinde kullanılır. Denetimli öğrenmede CNN ve RNN, denetimsiz öğrenmede GAN ve otokodlayıcılar yaygındır.

### 7.2 CNN Katmanları

CNN'ler filtreleme yaparken mekânsal ilişkileri korur; bu radyoloji görüntüleri için önemlidir. Bir CNN şu katmanlardan oluşur:

- Evrişim katmanı: girdi değerleri ile bir filtre arasındaki nokta çarpımını hesaplayarak öznitelik haritası oluşturur.
- ReLU: negatif girdileri sıfıra eşitleyen aktivasyon fonksiyonudur; hesaplamayı hızlandırır ve kaybolan gradyan sorununu azaltır.
- Havuzlama (pooling) katmanı: hesaplanacak parametre sayısını ve görüntü boyutunu azaltır; en yaygını max pooling'dir.
- Tam bağlantılı katman: önceki katmandaki tüm birimleri sonraki katmandaki tüm birimlere bağlar; her bağlantıya bir ağırlık atanır.

### 7.3 Transfer Öğrenme ve RNN

Medikal görüntü analizi genellikle etiketli veriyle yapılır, ama etiketli veri her zaman yeterli değildir; radyologlarla veri etiketlemek zor ve zaman alıcıdır. Transfer öğrenmede önceden eğitilmiş bir CNN'in belirli katmanları dondurulur ve model kendi verimizle yeniden eğitilerek yeni göreve uyarlanır. Bu işleme ince ayar (fine tuning) da denir.

RNN'ler sıralı verileri analiz etmek için kullanılır ve genelde dil modellerinde görülür. Bir adımın çıktısı sonraki adıma girdi olarak verilir; bu bağlamsal bellek sağlar. Medikal görüntü analizinde RNN'ler daha çok segmentasyon görevlerinde kullanılır.

### 7.4 Denetimsiz Öğrenme

Ekrandaki slayta göre (ekrandan, 01:50:00), medikal görüntülemede veri sayısındaki dengesiz dağılım ve yetersizlik nedeniyle denetimsiz teknikler de kullanılır:

- Otokodlayıcılar (autoencoder): girdi verisinin öznitelik temsilini (kodlamalarını) öğrenerek çıktıyı yeniden oluşturur; az sayıda etiketli veri olduğunda avantajlıdır. Veri sıkıştırmada da kullanılır.
- RBM'ler: Boltzmann makinelerinden türetilen, görünür ve gizli katmanlardan oluşan üretici modellerdir. Evrişimli RBM'ler akciğer dokusunu sınıflandırmak için kullanılmıştır.
- GAN'lar: biri üretici, diğeri ayırt edici iki modelden oluşur ve bu modeller sıfır toplamlı bir oyunda yarışır. Üretici yapay görüntüler üretir, ayırt edici gerçek ve üretilmiş görüntüleri ayırmaya çalışır. Eğitim, ayırt edicinin ikisini ayıramayacağı duruma gelinceye kadar sürer. Sunucu GAN'lar anlatılırken genelde hırsız-polis benzetmesinin kullanıldığını hatırlattı.

### 7.5 Uygulamalar

- Sınıflandırma: CNN'ler özellikle göğüs röntgenlerinde akciğer nodüllerini tespit etmek için kullanılmıştır; beyin tümörü ve zatürre tespiti de örneklerdir. Bir çalışmada veri artırmayla röntgenlerin ön ya da yan görünüm olarak sınıflandırılması yaklaşık %100 doğrulukla yapılmıştır. CheXNet, 121 katmanlı, değiştirilmiş bir DenseNet'tir ve göğüs röntgenlerinde 14 farklı hastalığın sınıflandırılmasında üstün başarım göstermiştir.
- Lokalizasyon: görüntülerin insan müdahalesi olmadan analiz edilip raporlandığı uçtan uca sistemlerde kullanılabilir. Bir çalışmada BT kesitleri üzerinde iki aşamalı bir CNN kurulmuş; birinci aşamada yerel yamalar belirlenmiş, ikinci aşamada bu yamalar vücut organlarına göre ayırt edilmiş ve standart bir CNN'den daha iyi sonuç alınmıştır.
- Tespit (bilgisayar destekli tespit): 2017 Kaggle Veri Bilimi yarışmasında BT akciğer taramalarındaki kanserli nodüllerin tespiti hedeflenmiştir. Bir çözümde 3B U-Net'ten esinlenen bir 3B CNN ile nodül için yerel yamalar ayrılmış, ikinci aşamada yamalar kanser olasılığına göre sınıflandırılmıştır.
- Segmentasyon: birçok organda çalışılsa da en çok beyin üzerine yoğunlaşılmıştır. Bir çalışmada beyin MR görüntülerini farklı doku sınıflarına ayırmak için farklı giriş yaması büyüklüklerine sahip, paralel çalışan üç 2B CNN kullanılmıştır.
- Kayıt (registration): beyin ve omurga cerrahisinde tümörün ya da omurga kemiğindeki bir işaretin konumunu bulmak için yapılır. Bir referans görüntü ikinci bir görüntüye hizalanır ve aradaki fark incelenir.

Sonuç olarak en büyük engel veri yetersizliğidir. Bunu aşmak için medikal alanda çalışanlarla yapay zekâ modeli eğitenler arasındaki temasın artması gerekir. Toplumun yapay zekâya mesafeli tavrının, modeller kendini kanıtladıkça azalacağı öngörülür.

Hoca, sağlık alanında yapılacak çok iş olduğunu ve bunların gerçek hayatta karşılığı bulunduğunu, bu alanlara girilmesini önerdiğini söyledi.

## 8. Kalp Hastalığı Teşhisinde Makine Öğrenmesi

### 8.1 Problem ve Yöntem

Yedinci sunum, kardiyovasküler hastalıkların erken teşhisi için ileri makine öğrenmesi tekniklerini ele alan bir çalışmaydı. Dünya Sağlık Örgütü'ne göre kardiyovasküler hastalıklar erken ölümlerin önde gelen nedenidir. Risk faktörleri değiştirilemeyenler (yaş, kalıtım) ve değiştirilebilenler (kan şekeri, kan basıncı, kolesterol, sigara, beslenme, obezite, fiziksel aktivite) olarak ikiye ayrılır. Çalışma, hastalığın varlığını tahmin etmek ve en öngörücü değişkenleri belirlemek için gradyan artırma (Gradient Boosting) tabanlı bir model önerir.

Yöntemin akışı: veri ön işleme, eğitim ve sınıflandırma. Ön işlemede eksik verilerin doldurulması amaçlanmıştır; örneğin kolesterol değerlerinde eksikler vardır. Kayıtlar türlerine göre gruplanmış, her grubun ortalaması hesaplanmış ve eksik değerler bu grup ortalamalarıyla doldurulmuştur. Veri %70 eğitim, %30 test olarak ayrılmıştır. Sınıflandırma ikilidir: kalp hastası (1) ya da değil (0).

Kullanılan algoritmalar arasında SVC, Naive Bayes, K en yakın komşu, SGD, Random Forest, karar ağacı ile XGBoost ve AdaBoost gibi artırma algoritmaları vardır. SVC'nin büyük veri kümeleriyle uyumlu çalıştığı, Naive Bayes'in eşit ağırlıklar atayarak basit ve etkili bir sınıflandırma sunduğu belirtilmiştir.

### 8.2 Veri Seti ve Analiz

Veri seti, UCI makine öğrenmesi deposundaki beş veri setinin birleşimidir. Son veri setinde 918 kayıt vardır: 725 erkek, 193 kadın; 508 kişi hasta, 410 kişi sağlıklıdır. Sayısal öznitelikler yaş, dinlenme anındaki kan basıncı (RestingBP), kolesterol, açlık kan şekeri (FastingBS), maksimum kalp hızı (MaxHR) ve Oldpeak'tir. Kategorik öznitelikler cinsiyet, göğüs ağrısı tipi, dinlenme EKG'si, egzersize bağlı göğüs ağrısı (anjina) ve ST eğimidir.

Hastaların yaş ortalaması 57, sağlıklıların 51'dir. Erkeklerin yaklaşık %63'ünde, kadınların yaklaşık %25,9'unda hastalık teşhis edilmiştir.

> **Ders sonrası not:** Sunucu "erkeklerde oran %90, kadınlarda %9,8" dedi. Bu oranlar büyük olasılıkla hastaların cinsiyet dağılımıdır: erkeklerin %63'ü (yaklaşık 458 kişi) ve kadınların %25,9'u (yaklaşık 50 kişi) hasta ise 508 hastanın yaklaşık %90'ı erkek, %9,8'i kadındır.

Korelasyon matrisi (ekrandan, 02:05:00), HeartDisease satırı: Age 0,28; RestingBP 0,11; Cholesterol -0,23; FastingBS 0,27; MaxHR -0,4; Oldpeak 0,4. Kalp hastalığıyla en güçlü pozitif ilişki Oldpeak, en güçlü negatif ilişki MaxHR ile görülür. Ayrıca MaxHR ile yaş arasında -0,38 korelasyon vardır; kalp atış hızı yaş arttıkça azalma eğilimindedir. Kolesterol ile kalp hastalığı arasındaki ilişki bu veride negatiftir; sunucu bunun beklenenin tersi olduğunu vurguladı.

Kategorik değişkenlerle ilişki: şeker hastası bireylerin yaklaşık %80'inde kalp rahatsızlığı vardır. Egzersize bağlı anjinası olanlarda hastalık oranı %85'in üzerindedir. Dinlenme EKG'si sonuçları daha dengeli bir dağılım gösterir. ST eğimi "down" olanlarda hastalık oranı yaklaşık %77, "up" olanlarda yaklaşık %20'dir. Göğüs ağrısı tiplerinde, belirgin göğüs ağrısı olmaması (asemptomatik), hastalarda en sık görülen durumdur (%77); yani belirgin göğüs ağrısı olmayan bir kişi de kalp hastası olabilir.

### 8.3 Değerlendirme

Başarım yalnız doğrulukla değil, F1 skoru, duyarlılık (recall) ve kesinlik (precision) ile de ölçülmüştür. ROC eğrisinde dikey eksen doğru pozitif oranı (duyarlılık), yatay eksen yanlış pozitif oranıdır; en yüksek alanı 0,92 ile Gradient Boosting vermiştir.

Doğrulama setindeki karşılaştırmalı sonuçlar (ekrandan, 02:10:00):

| Sınıflandırıcı | Doğruluk | Kesinlik | Duyarlılık | F1 |
|---|---|---|---|---|
| XGBoost | 0,8297 | 0,8980 | 0,8049 | 0,8489 |
| AdaBoost | 0,8659 | 0,9262 | 0,8415 | 0,8818 |
| LinearDiscriminant | 0,8696 | 0,9156 | 0,8598 | 0,8868 |
| LightGBM | 0,8732 | 0,9057 | 0,8780 | 0,8916 |
| GradientBoosting | 0,8768 | 0,9276 | 0,8598 | 0,8924 |
| CatBoost | 0,8804 | 0,9226 | 0,8720 | 0,8966 |
| ExtraTree | 0,8804 | 0,9281 | 0,8659 | 0,8959 |
| KNeighbors | 0,8841 | 0,9074 | 0,8963 | 0,9018 |
| SVM | 0,8841 | 0,8976 | 0,9085 | 0,9030 |
| LogisticRegression | 0,8841 | 0,9231 | 0,8780 | 0,9000 |
| RandomForest | 0,8877 | 0,9236 | 0,8841 | 0,9034 |
| CatBoost (ayarlanmış) | 0,9094 | 0,9317 | 0,9146 | 0,9231 |

En düşük sonuçları XGBoost ve AdaBoost vermiştir. Çalışmada önerilen ve en yüksek değerleri veren model ayarlanmış CatBoost'tur. Sunucu ayrıca Gradient Boosting için F1 %90,3 ve doğruluk %88,5 değerlerini aktardı. <!-- BELİRSİZ: Gradient Boosting için söylenen %90,3 F1 ve %88,5 doğruluk değerleri bu tablodaki değerlerle (0,8924 ve 0,8768) uyuşmuyor; büyük olasılıkla başka bir tablodan (ör. ortanca değerler) alınmıştır. --> Extra Trees, Random Forest, AdaBoost ve Gradient Boosting için karışıklık matrisleri de verilmiştir.

Çalışmanın sınırlılıkları: veriler yalnız kardiyoloji ve iç hastalıkları bölümlerinden geldiği için bazı değişkenler eksiktir; kesitsel tasarım yüzünden risk faktörlerinin uzun vadeli etkileri incelenememiştir.

### 8.4 Sunucunun Kendi Denemesi

Sunucu, aynı veri setinin yalnız Cleveland parçasını kullanarak küçük bir sinir ağı denedi. Aynı öznitelikler alındı, veri eğitim ve test olarak bölündü, normalleştirildi. Ağ tek gizli katmanlıydı; son katmanda softmax aktivasyonu, kayıp olarak kategorik çapraz entropi (categorical cross-entropy), optimize edici olarak RMSprop kullanıldı. Eğitim 50 epok ve 10'luk batch ile yapıldı (ekrandan, 02:15:00). Bu parçada hedef değişken ikiden fazla sınıf içerdiği için önce çok sınıflı, sonra ikili sınıflandırmaya çevrilmiş hâliyle denendi; ikili hâlde kesinlik, duyarlılık ve F1 değerlerinde küçük bir artış gözlendi. <!-- BELİRSİZ: eğitim/test bölme oranı altyazıda "%20'ye %70" diye bozuk geçiyor. -->

Hoca, veriye dokunmanın güzel olduğunu, örnek sayısı az olsa da yöntemin uygulamalı olarak görüldüğünü söyledi.

**Soru (hoca):** Kaç sınıf var? **Cevap:** Bu veri parçasında ikiden fazla (dört) sınıf vardı; bu yüzden ikili sınıflandırmaya da çevrilip karşılaştırıldı.

**Soru (bir öğrenci):** Tabloda iki CatBoost satırı var; ayarlanmış CatBoost'ta ne yapıldığını biliyor muyuz? **Cevap:** Sunucu, farkın veri ön işleme ve eksik verilerin doldurulması aşamalarından sonra modelin yeniden ayarlanmasından geldiğini düşündüğünü, daha ayrıntılı bilgisi olmadığını söyledi.

## 9. EEG ile Zihinsel Yorgunluk Tanımada Denekler Arası Transfer Öğrenme

### 9.1 Motivasyon

Son sunum, 2020'de yayımlanmış, EEG tabanlı zihinsel yorgunluk tanıma için denekler arası transfer öğrenme öneren bir çalışmaydı. Zihinsel yorgunluk uzun süreli bilişsel aktivite sonucu ortaya çıkar; odaklanma güçlüğü, hafıza sorunları ve motivasyon kaybıyla kendini gösterir. Pilotlar ve sürücüler gibi meslek gruplarında yorgunluğun izlenmesi kazaları önleyebilir. Anketlerle yorgunluk değerlendirmesi yapılabilse de giyilebilir cihazlarla (EEG, EKG) ölçmenin daha sağlam olduğu düşünülür. EEG sinyalleri kişiden kişiye çok değiştiği için her kullanıcı için kalibrasyon zordur; bu yüzden denekler arası transfer öğrenme önerilmiştir.

### 9.2 EEG Bantları ve Kanallar

EEG, kafaya takılan elektrotlarla beynin elektriksel aktivitesini izleyen bir tekniktir. Bilişsel becerilerle ilgili bilinen frekans bantları delta, teta, alfa, beta ve gamadır. Delta 0-4 Hz, teta 4-8 Hz aralığındadır; 30 Hz üstü gama olarak adlandırılır. Önceki çalışmalarda gece vardiyasının alfa güç yoğunluğunu artırdığı, uyku yoksunluğunun üst alfa ve beta bantlarının gücünü artırdığı, gece sürüşünde delta, teta ve alfa güçlerinin arttığı gözlenmiştir. Derin uykuda delta baskındır; sürüş sırasında delta'ya geçiş tehlikeli bir işarettir.

Elektrotlar beynin loblarına göre adlandırılan bölgelere yerleştirilir; kafanın arkası oksipital, alın hizası frontal bölgedir. Çalışmalarda frontal bölgede gama, oksipital bölgede teta dalgalarının yorgunlukla daha yoğun ilişkili olduğu gösterilmiştir.

Çok sayıda kanal çok fazla veri demektir: hesaplama karmaşıklaşır, aynı bölgelerden benzer veri geldiği için aşırı öğrenme riski artar ve elektrotların yerleştirilmesi zaman alır. Bu yüzden kanal azaltma yapılır. Kanal seçimi filtre, sarmalayıcı (wrapper), gömülü (embedded) ya da hem filtre hem sarmalayıcıyı birleştiren hibrit yöntemlerle yapılabilir. Filtre yöntemlerinde kanallar arası mesafe, bilgi, bağımlılık ve tutarlılık hesaplanıp bir eşiğin üstündeki kanallar seçilir.

Makine öğrenmesi tarafında en çok denetimli yöntemler, özellikle Random Forest kullanılmış; son zamanlarda geri yayılım (backpropagation) ile eğitilen sinir ağları ve CNN tabanlı yaklaşımlar denenmiştir. Yazarlar, bu çalışmaların hepsinin denek içi düzeyde kaldığını görmüş ve denekler arası bir yaklaşım önermiştir.

### 9.3 Veri Seti ve Etiketleme

Veri seti başka bir çalışmadan alınmıştır. Bir sürüş simülatöründe her deneğe 90 dakikalık bir dikkat görevi verilir: ekrandaki sarı şeridi ortalayarak aracı sürmek. Şerit sürekli sağa sola kayar ve denek onu takip etmek zorundadır. Yaşları 22-28 arasında olan 27 kişiden 62 oturum veri alınmış, 32 kanallı bir EEG cihazı kullanılmıştır. Veri setinin ham ve ön işlenmiş iki sürümü vardır; yazarlar ön işlenmiş sürümü kullanmıştır.

Etiketleme adımları (ekrandan, 02:30:00):

- Şeritten ayrılma olaylarından önceki 3 saniyelik EEG epokları çıkarılır ve yorgunluk reaksiyon süresine (RT) göre tahmin edilir.
- Her olayda yerel RT kullanılır; global RT, tüm epoklardaki yerel RT'lerin ortalamasıdır.
- Uyarı (alert) RT'si, tüm oturumdaki yerel RT'lerin 5. yüzdelik dilimi olarak belirlenir.
- Hem yerel RT hem global RT, uyarı RT'sinin 1,5 katından küçükse epok "yorgun değil"; yerel ve global RT uyarı RT'sinin 2,5 katından büyükse "yorgun" olarak etiketlenir.
- Eğitim ve test için yeterli epok olması amacıyla, her iki durum için de en az 50 epoku olan denekler seçilmiştir.
- 11 katılımcıdan toplam 837 yorgun olmayan ve 837 yorgun epok çıkarılmıştır; böylece veri dengelidir.
- 16 denek yetersiz epok nedeniyle dışarıda bırakılmıştır.

### 9.4 Önerilen Yöntem

Her EEG epoku için hızlı Fourier dönüşümü (FFT) uygulanır ve dört spektral bandın gücü hesaplanır. Bu dört bant ile tüm kanallardan gelen değerler birleştirilerek öznitelik vektörü oluşturulur. Ardından Random Forest ile öznitelik önemi hesaplanır ve yorgunluğu en iyi ayıran EEG kanalı seçilir; bu kanal oksipital bölgeden gelmiştir.

Transfer öğrenme için iki teknik kullanılmıştır:

- TCA (Transfer Component Analysis): kaynak ve hedef alanlar arasında benzer öznitelik dağılımları elde ederek öğrenilen temsilin aktarılmasını amaçlar.
- MIDA (Maximum Independence Domain Adaptation): benzer öznitelik dağılımlarına ek olarak öznitelik uzayının alandan bağımsızlığını en yüksek düzeyde korumaya çalışır.

> **Ek bilgi (derste anlatılmadı):** TCA, kaynak ve hedef verileri ortak bir alt uzaya izdüşürür ve bu alt uzayda iki dağılım arasındaki farkı büyük olasılıkla maksimum ortalama tutarsızlık (MMD) ölçüsüyle küçültür. MIDA ise öznitelikler ile "hangi alandan (hangi denekten) geldiği" bilgisi arasındaki bağımlılığı (HSIC ile) en aza indiren bir dönüşüm arar. İkisi de etiketsiz hedef verisiyle çalışabildiği için yeni bir denek için kalibrasyon gerektirmez.

### 9.5 Deney Düzeni ve Sonuçlar

Değerlendirme bir-denek-dışarıda düzeniyle yapılmıştır: 11 denekten biri test, kalan 10'u eğitim için kullanılır ve süreç her denek bir kez test olana kadar, yani 11 tur tekrarlanır. Karşılaştırma için lojistik regresyon (temel model), EEGNet-8,2 ve EEGNet-4,2 modelleri kullanılmıştır.

Tek kanallı (oksipital) deneylerde denek bazlı sonuçlar (ekrandan, 02:35:00), ortalama değerler:

| Yöntem | Doğruluk | Duyarlılık (doğru yorgun-değil oranı) | Özgüllük (doğru yorgun oranı) |
|---|---|---|---|
| TCA | %68,00 | %68,20 | %70,57 |
| MIDA | %67,89 | %64,05 | %74,57 |

Standart sapmalar TCA için %14,47 / %17,65 / %28,91, MIDA için %14,38 / %14,41 / %18,31'dir. Denekler arasındaki büyük fark (ör. TCA'da bir denekte %40,15, bir başkasında %86,81 doğruluk) denekler arası genellemenin zorluğunu gösterir.

Sunucu MIDA'nın 73,01 ortalamayla en yüksek sonucu verdiğini, TCA'nın onu izlediğini, EEGNet modellerinin daha düşük kaldığını aktardı. <!-- BELİRSİZ: 73,01 değeri ve EEGNet doğrulukları (altyazıda "63" ve "159" diye bozuk) ekrandaki tabloda görülmüyor; büyük olasılıkla başka bir karşılaştırma tablosundan alınmıştır. --> Her deney ortamında önerilen transfer öğrenme tekniklerinin temel modellerden daha iyi sonuç verdiği raporlanmıştır.

ROC eğrileri tek kanal ve 30 kanal için karşılaştırılmıştır. Tek kanalla eğriler ideal noktaya daha yakın ve TCA ile MIDA birbirine daha tutarlıdır. 30 kanalla durum değişmiş, MIDA ideal noktaya daha yakın kalmıştır.

Ana bulgular: denekler arası transfer öğrenmeyle önerilen algoritmalar kalibrasyona ihtiyaç duymaz; bu, EEG ile veri toplayanların işini çok kolaylaştırır. Çalışma kanal sayısının doğruluğa etkisini de incelemiştir ve farklı yöntemler ve kanal sayılarıyla yüksek doğruluk elde edilebilmiştir.

**Soru (hoca):** Test edilen denek dışındaki diğer denekler eğitim verisi olarak mı kullanılıyor? **Cevap:** Evet. 11 denekten birinin verisi test için tutuluyor, eğitim diğer 10 deneğin verisiyle yapılıyor.

> **Hocanın vurgusu:** Test edilen deneğin kendi verisini eğitimden tümüyle dışarıda bırakmak gerçekten daha doğru bir yaklaşımdır.

## 10. Örnek Sorular

Aşağıdaki sorular derste sözlü olarak soruldu.

**Soru 1** (derste sözlü, 00:57:06): VKİ tahmin çalışmasındaki sapma grafiğinde sapmalar yaklaşık $-2$ ile $2$ arasında dağılıyor. Ortalama VKİ 25-30 civarındayken bu sapma büyük müdür?

> **Çözüm:** Derste, ortalama VKİ 25-30 civarında olduğu için bunun yaklaşık %10'luk bir sapma olduğu, %50 gibi büyük bir hata sayılmayacağı konuşuldu. Sayısal olarak, veri setindeki ortalama VKİ 26,4 alınırsa $2/26{,}4 \approx 0{,}076$, yani yaklaşık %7,6; $3/26{,}4 \approx 0{,}114$, yani yaklaşık %11,4 bağıl sapma eder (ara adım eklendi). Ancak bu sapma, bir kişiyi komşu VKİ kategorisine (ör. normalden fazla kiloluya) kaydırmaya yetebilir.

**Soru 2** (derste sözlü, 01:02:10): Fotoğraftan VKİ tahmini gibi bir çalışma nerede kullanılır?

> **Çözüm:** Derste verilen cevaplar: bir topluluğun beslenme alışkanlıklarını ve obezite/aşırı zayıflık durumunu inceleyen geniş çaplı taramalarda VKİ'yi tek tek ölçmek yerine; diyetisyenlerin ya da sporcuların kullanabileceği bir uygulamada; spor salonlarında. Kalın kıyafetler tahmini zorlaştıracağı için kontrollü ortamlar daha uygundur.

**Soru 3** (derste sözlü, 01:28:02): Futbol çalışmasında model maç skorunu ya da skor farkını mı tahmin ediyor?

> **Çözüm:** Hayır. Model yalnız kazanma/kaybetme sınıfını tahmin eder (beraberlikler çıkarılmıştır). Girdi, oyuncu bazlı maç istatistiklerinin takıma toplanmış hâlidir.

**Soru 4** (derste sözlü, 02:14:57): Kalp hastalığı veri setinin Cleveland parçasıyla kurulan sinir ağında kaç sınıf var?

> **Çözüm:** Bu parçada hedef değişken ikiden fazla sınıf (dört) içeriyordu. Sunucu modeli hem bu hâliyle hem de ikili sınıflandırmaya (hasta/değil) çevrilmiş hâliyle denedi; ikili hâlde başarım biraz arttı.

**Soru 5** (derste sözlü, 02:16:28): Model karşılaştırma tablosunda "CatBoost" ve "CatBoost (ayarlanmış)" diye iki satır var. Aradaki fark nedir?

> **Çözüm:** Derste sunucu, farkın ön işleme ve eksik veri doldurma sonrasında modelin yeniden ayarlanmasından geldiğini düşündüğünü söyledi. Tabloya göre ayarlama doğruluğu 0,8804'ten 0,9094'e, F1'i 0,8966'dan 0,9231'e çıkarmıştır.

**Soru 6** (derste sözlü, 02:37:00): EEG çalışmasında bir denek test edilirken eğitim verisi olarak diğer denekler mi kullanılıyor?

> **Çözüm:** Evet. Bir-denek-dışarıda düzeninde 11 denekten biri test, 10'u eğitim için kullanılır ve bu 11 kez tekrarlanır. Böylece model, verisini hiç görmediği yeni bir deneğe genellemeye zorlanır.

## Dersin Toparlaması

Bu derste sekiz öğrenci sunumu üzerinden veri madenciliği sürecinin gerçek çalışmalarda nasıl uygulandığı görüldü. Uzaktan algılamada bölge bazlı veri bölme ve iki farklı veri kaynağının (SAR ve optik) birleştirilmesi; dolandırıcılık tespitinde dengesiz veri ve SMOTE-NC, Tomek bağları, ENN gibi dengeleme teknikleri; VKİ tahmininde küçük veri setinde aykırı değerleri koruma kararı ve klasik öznitelik çıkarımı ile CNN karşılaştırması; futbolda istatistiksel testlerle öznitelik seçimi ve basit bir referans modelin önemi; dizi hizalamada dinamik programlamanın maliyeti ve ML ile hızlandırma; medikal görüntülerde CNN, transfer öğrenme ve denetimsiz modeller; kalp hastalığında eksik değer doldurma, korelasyon analizi ve çoklu ölçütle model karşılaştırma; EEG'de kanal seçimi ve denekler arası transfer öğrenme ele alındı.

Ortak ders, bir modelin başarısının yalnız doğrulukla değil, verinin nasıl bölündüğü, dengesizliğin nasıl ele alındığı ve basit bir referans modele göre ne kadar iyi olduğu ile birlikte değerlendirilmesi gerektiğidir. Hocanın sorularında da görüldüğü gibi, grafiklerin doğru okunması, neyin tahmin edildiğinin açıkça tanımlanması ve test verisinin eğitimden tümüyle ayrı tutulması güvenilir bir çalışmanın temel şartlarıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
