# Ders 10 Genişletilmiş Notu: Seminer Sunumları: Çok Kipli Öğrenme, Tavsiye Sistemleri, Manifold Öğrenme, Çok Dilli Kelime Vektörleri ve Yol Planlama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Seminer Sunumlarının Yapısı
- 2. Çok Kipli (Multimodal) Derin Öğrenme ve Duygu Analizi
- 3. Derin Öğrenme Tabanlı Hibrit Tavsiye Sistemleri
- 4. Manifold Öğrenme ve Denetimsiz Boyut İndirgeme
- 5. Çok Dilli (Cross-Lingual) Kelime Vektörleri
- 6. Çoklu Mobil Robot Yol Planlama ve Optimizasyon Algoritmaları
- 7. Literatür Taramasına Dair Değerlendirmeler
- Örnek Sorular
- Dersin Toparlaması

## 1. Seminer Sunumlarının Yapısı

Bu ders, dönemin son seminer oturumuydu ve beş literatür sunumundan oluştu. Her sunum için soru-cevap dahil yaklaşık 30 dakika ayrıldı. Sunumlar ortak bir akışı izledi. Önce konunun motivasyonu ve temel kavramları anlatıldı. Ardından literatürden seçilmiş makalelerin yöntemleri, kullandıkları veri setleri ve sonuçları aktarıldı. En sonda genel bir değerlendirme yapıldı ve alanda yapılabilecek yeni çalışmalar önerildi. Seminer dersinin amacı, tez için gereken literatür taramasının ilk evresini oluşturmaktır. Sunumlardan sonra hem hoca hem de sunumları dinlemeye davet edilen öğretim üyeleri sorular sordu. Bu not, sunumları kişilere bağlamadan yalnız akademik içerikleriyle aktarır.

## 2. Çok Kipli (Multimodal) Derin Öğrenme ve Duygu Analizi

### 2.1 Motivasyon

Çok kipli veri, adından da anlaşıldığı gibi birden çok kaynaktan (kipten) gelen veriden oluşur. Sosyal medya kullanımının artmasıyla görüntü, video ve ses verisi çoğaldı (ekrandan, 00:20:00):

- Video: YouTube, Vimeo, Dailymotion.
- Görüntü: Flickr, Facebook, Instagram, Pinterest.
- Ses: podcast'ler.

Bu üç farklı veri türünü birleştirip tahmin ve analiz yapmak zor bir iştir ve son yıllarda popüler bir araştırma konusu hâline gelmiştir.

### 2.2 Literatürden Örnekler

Görsel-işitsel konuşma tanımada Yuhas ve arkadaşları, görsel girdiden işitsel sinyali tahmin eden bir yapay sinir ağı eğitti. Tahmin edilen sinyali gürültülü işitsel sinyalle birleştirerek iyi bir performans elde ettiler. Çok kipli duygu analizinde ilk çalışmalar daha çok metin tabanlıydı. Ürün ve film incelemelerinde duygu analizi önemli bir yer tutar. Eskiden yalnız yorumlar üzerinden yapılan bu analizler artık çok kipli hâle gelmiştir. Poria ve arkadaşları 2015'te CNN kullanarak çok kipli duygu analizi yaptı.

Genel yapıda sosyal medya kullanıcıları metin, konuşma ve görsel veri üretir. Bu verilerden metin, metin+ses ve metin+ses+yüz öznitelikleri çıkarılır. Analiz sonucunda içeriğin pozitif, nötr ya da negatif olduğu tahmin edilir.

Bir makalede kullanılan veri seti MOSI olarak anıldı. Duygu yoğunluğu $-3$ ile $+3$ arasında doğrusal bir ölçekle, negatiften pozitife doğru etiketlenmiştir. Veri setinde 2199 veri noktası bulunur. <!-- BELİRSİZ: Veri setinin açık adı altyazıda bozuk ("Multimodal Corpus of Centimeter Analizi"); büyük olasılıkla CMU-MOSI (Multimodal Opinion-level Sentiment Intensity) veri setidir. --> Çalışmanın sonucuna göre duygu tahminine en çok metin kipi katkı veriyor (yaklaşık 0,6). Ses ve videonun katkısı birbirine yakın ve metinden düşük (yaklaşık 0,34-0,35). <!-- BELİRSİZ: Bu oranların gösterildiği grafik karelerde yok; değerler altyazıdan alındı. -->

**Soru:** Grafikteki oranlar sesin ve videonun insan üzerindeki etkisini mi, yoksa veri miktarını mı gösteriyor? **Cevap:** Metin, ses ve videonun bir arada olduğu bir girdide, her kipin son duygu tahminine (pozitif, negatif ya da nötr) ne kadar etki ettiğini gösteriyor.

### 2.3 Çok Kipli Veri ve Kip Kavramı

Yaşadığımız dünya çok kiplidir: nesneleri görür, sesleri duyar, dokuyu hisseder, koku ve tat alırız. Kip, bir şeyin meydana gelme ya da deneyimlenme biçimini ifade eder. Bir problem birden çok kip içerdiğinde çok kipli (multimodal) olarak tanımlanır. Yapay zekânın çevremizdeki dünyayı anlamada ilerleyebilmesi için bu sinyalleri birlikte yorumlayabilmesi gerekir. Örneğin görüntüler genellikle etiket ve metin açıklamalarıyla ilişkilendirilir. Metinler de ana fikri daha net ifade etmek için resim içerir. Farklı kipler çok farklı istatistiksel özelliklerle karakterize edilir.

### 2.4 Çok Kipli Öğrenmenin Beş Zorluğu

Sunumda beş temel zorluk sayıldı (ilk üçü ekrandan, 00:25:00):

- **Gösterim (representation):** Veri birden çok kipten gelir. Örneğin dil sembolik olarak, ses ve görüntü ise sinyal olarak temsil edilir.
- **Çeviri (translation):** Bir kipin diğerine nasıl dönüştürüleceğidir. Bir görüntüyü tanımlamanın birden fazla yolu olabilir, ancak tek bir mükemmel çeviri olmayabilir.
- **Hizalama (alignment):** İki ya da daha fazla kipteki (alt) öğeler arasındaki doğrudan ilişkileri belirlemektir. Örneğin bir tarifin adımlarını yemeğin yapılışını gösteren bir videoya hizalamak isteyebiliriz.
- **Birleştirme (fusion):** Birden fazla kipin bilgisini birleştirmektir. Görsel-işitsel konuşma tanımada dudak hareketinin görsel tanımı, konuşulan kelimeyi tahmin etmek için konuşma sinyaliyle birleştirilir. Kiplerden birinde eksik veri olabilir, ya da kiplerin tahmin gücü ve gürültü yapısı farklı olabilir.
- **Ortak öğrenme (co-learning):** Bilginin ve tahmin modellerinin kipler arasında aktarılmasıdır. Bir kipten öğrenilen bilginin başka bir kipte eğitilmiş bir modele nasıl yardım edebileceği araştırılır. Bu, özellikle kiplerden birinin kaynağı sınırlı olduğunda önemlidir.

### 2.5 Kiplerin Ağırlıklandırılması

Genel bir ağ mimarisinde girdiye kelime gömmesi (word embedding) uygulanır ve LSTM gibi ağlarla çıktı üretilir. Görüntü tarafında Inception gibi hazır modeller kullanılır. Farklı kiplerden gelen bilgiyi birleştirmek cazip görünse de pratikte kiplerin gürültü seviyeleri farklıdır ve aralarındaki çelişkileri gidermek zordur. Kiplerin tahmin çıktısına etkisi de farklıdır.

Pratikte en yaygın yöntem, farklı girdilerden gelen yüksek seviyeli gömmeleri birleştirip ardından softmax uygulamaktır. Bu yöntemin temel sorunu, bütün alt ağlara (metin, konuşma, görüntü) eşit önem vermesidir. Oysa her kip çıktıyı farklı ölçüde etkiler. Önerilen yaklaşımda alt ağların ağırlıklı bir kombinasyonu alınır. Kayıp fonksiyonunda her alt ağa bir $\theta$ ağırlığı verilir, böylece her giriş kipi çıktıya öğrenilmiş bir katkıyla girer. <!-- BELİRSİZ: Ağırlıklı kayıp fonksiyonunun açık biçimi slaytta gösterildi, ancak bu anın karesi elde yok. -->

### 2.6 Kısıtlı Boltzmann Makineleri (RBM) ile Çok Kipli Öğrenme

Çok kipli öğrenme, kendi kendine öğretmeli öğrenmenin (self-taught learning) özel bir durumu olarak görülebilir. Bu yaklaşım etiketlenmemiş veriyi kullanarak belirli görevlerde performansı artırmaya çalışır. Derin öğrenme çalışmalarında el yazısı rakamlar ve metinler için yararlı temsiller öğrenmek amacıyla derin sigmoid ağların nasıl eğitileceği incelenmiştir. Temel fikir, kısıtlı Boltzmann makinelerini katman katman açgözlü (greedy layer-wise) eğitmek ve ardından ince ayar (fine-tuning) yapmaktır.

RBM, gizli ve görünür değişkenleri içeren yönsüz bir grafik modeldir. Gizli ve görünür değişkenler arasında simetrik bağlantılar vardır. Ancak gizli değişkenler kendi aralarında, görünür değişkenler de kendi aralarında bağlı değildir. Bu yapı sayesinde görünür değişkenler $v$ sabitken gizli değişkenlerin, gizli değişkenler $h$ sabitken görünür değişkenlerin koşullu dağılımı kolayca hesaplanır. Sunulan formülasyonda görünür değişkenler gerçek değerli, gizli değişkenler ikili (binary) olarak modellendi. <!-- BELİRSİZ: Eşitlik 1 (negatif log olasılık) ve eşitlik 2 (görünür değişkenler verilince gizli değişkenlerin dağılımı) slaytta gösterildi; bu anın karesi elde olmadığı için denklemler nota alınmadı. -->

Sunumda üç RBM mimarisi gösterildi (ekrandan, 00:30:00):

- **(a) Standart RBM:** Ses ve görüntüyü ayrı ayrı eğitmek için kullanılır. RBM öğrenildikten sonra görünür değişkenler verilince gizli değişkenlerin çıktıları veri için yeni bir temsil olarak kullanılabilir. Bu model, çok kipli modellerin sonuçlarını karşılaştırmak ve derin ağları önceden eğitmek için temel olarak kullanılır.
- **(b) Sığ (shallow) RBM:** Birleştirilmiş ses ve video verisi üzerinde tek bir RBM eğitilir. Ses ve video arasındaki korelasyonlar doğrusal olmadığı için tek bir RBM'nin bunları öğrenmesi ve çok kipli bir gösterim oluşturması zordur. Bu yüzden model kısıtlıdır ve kipler arası ilişkileri iyi yakalayamaz.
- **(c) Derin (deep) RBM:** Önce iki ayrı standart RBM açgözlü katman katman eğitilir. Ardından her kip için önceden eğitilmiş bu katmanların üzerine ortak bir RBM eğitilir. Veri, öğrenilmiş birinci katman gösterimleriyle temsil edildiği için kipler arasındaki yüksek dereceli korelasyonları öğrenmek kolaylaşır.

**Soru:** Sığ ve derin model arasındaki fark yalnız araya bir katman eklenmesi mi? **Cevap:** Araya bir katman eklenir, ama bu tek bir katmanla sınırlı değildir; birden fazla katman da eklenebilir. Tıpkı yapay sinir ağlarında olduğu gibi katman sayısı tasarımcıya bağlıdır.

**Soru:** Sığ modelde ortak gösterim katmanındaki bağlantılar, örneğin video girdisinin en sonundaki birimden en baştaki birime de bağlantı olabileceği anlamına mı geliyor? Derin modelde ise kipler birbirinden izole mi? **Cevap:** Evet. Sığ modelde ses ve video arasında ortak katman üzerinden doğrudan bir bağlantı vardır. Derin modelde ise kipler ilk katmanda birbirinden ayrıdır.

### 2.7 Sonuç ve Kaynaklar

Çok kipli veri üzerinde öznitelik öğrenmek ve derin mimarilerle tahmin yapmak zordur. Örneğin yalnız görsel veriyle dudak okuma için hangi özniteliklerin uygun olduğu net değildir. Öznitelikler birden çok veri kaynağıyla ilişkilendirilmek zorunda olduğu için çok kipli veride bu zorluk daha da artar. Dudak okumada "elephant juice" ile "I love you" söylendiğinde dudaklar aynı hareketi yapar. Bu yüzden yalnız görsel kip yetmez, başka kiplere de ihtiyaç vardır. Sunumda çok kipli öznitelikleri öğrenmek ve çapraz kip öğrenmeyle tek kipli öznitelikleri geliştirmek için derin öğrenme mimarileri anlatıldı.

Kaynak listesinde her makalenin atıf sayısı parantez içinde verildi (ekrandan, 00:35:00). Örneğin Ngiam ve arkadaşlarının "Multimodal deep learning" (ICML 2011) makalesi 1669 atıfla, Baltrušaitis, Ahuja ve Morency'nin "Multimodal Machine Learning: A Survey and Taxonomy" (IEEE TPAMI 2019) makalesi 675 atıfla listelenmişti. Yuhas, Goldstein ve Sejnowski'nin 1989 tarihli görsel-işitsel konuşma birleştirme makalesi de listede yer aldı.

## 3. Derin Öğrenme Tabanlı Hibrit Tavsiye Sistemleri

### 3.1 Tarihçe ve Tanım

Tavsiye sistemleri 1990'ların ortasında bağımsız bir araştırma alanı olarak ortaya çıktı, ancak uzun süre büyük bir atılım yapmadı. Netflix'in kendi verisi üzerinde işbirlikçi bir model tasarlamak için düzenlediği 1 milyon dolarlık yarışmayla alan hem akademide hem de iş dünyasında popüler hâle geldi.

> **Ders sonrası not:** Sunumda yarışmanın 2009'da düzenlendiği söylendi. Netflix Prize büyük olasılıkla 2006'da başlatıldı ve 2009'da sonuçlandı.

Sunumdaki tanıma göre öneri sistemleri, kullanıcılar ve öğeler arasındaki gizli bağlantıları keşfeden, büyük veri havuzlarından faydalı içerikleri filtreleyerek kullanıcıya en anlamlı ve doğru ürünleri sunmayı amaçlayan algoritmalardır. Sunumda verilen rakamlara göre Netflix'te izlenen filmlerin %80'i, YouTube tıklamalarının %60'ı ve Amazon satışlarının %35'i önerilerden gelir. Sunumda ayrıca hizmetlerin dijital platformlara taşınmasıyla tavsiye sistemlerinin öneminin artacağı görüşü paylaşıldı.

Sunumun amacı, hibrit tavsiye sistemlerini derin öğrenmeyle birleştiren modellerle ilgili bir literatür incelemesi yapmaktı.

### 3.2 Tavsiye Sistemlerinin Türleri

Tavsiye sistemleri birçok alt türe ayrılsa da üç genel yaklaşımla ifade edilir:

- **İçeriğe dayalı filtreleme:** Kullanıcının geçmişte sevdiklerine benzer öğeleri önerir. Örneğin komedi türünde kitap alan kullanıcıya yine komedi kitapları önerilir. Sınırlılığı şudur: kullanıcı aksiyon kitaplarından hoşlanmaya başladığında elde öneri yapacak veri yoktur.
- **İşbirliğine dayalı filtreleme:** İki ya da daha çok müşteri arasındaki benzerlikten yararlanarak birinin aldığı ürünleri diğerine önerir. Slayttaki örnekte iki benzer kullanıcı aksiyon türünde aynı kitapları almıştır. Birinin okuduğu farklı bir kitap diğerine önerilir (ekrandan, 00:40:00). Hibrit yöntemlerin gelişimi sürdüğü için en sık kullanılan yaklaşım hâlâ budur.
- **Hibrit öneri:** İşbirliğine ve içeriğe dayalı sistemlerin olumlu özelliklerini alıp olumsuzluklarını bir yana bırakan yeni bir model tasarlama sürecidir.

### 3.3 Geleneksel Tavsiye Sistemlerinin Zorlukları

Derin öğrenme kullanmayan geleneksel sistemlerde öne çıkan zorluklar şunlardır:

- **Soğuk başlangıç (cold start):** Yeni gelen bir kullanıcı hakkında öneri yapacak veri yoktur.
- **Ölçeklenebilirlik (scalability):** Veri setleri çok büyük olduğu için sistemi kurmanın maliyeti yüksektir.
- **Seyreklik (sparsity):** Çok sayıda kullanıcı ve ürün vardır, ama aralarındaki etkileşim azdır. Kullanıcılar puan ve yorum sorularına çoğunlukla cevap vermez.
- **Yorumlanabilirlik:** Önerilerin açıklanabilirliği sınırlıdır. İçeriğe dayalı sistemlerde bu daha kolay, işbirlikçi yöntemlerde daha zordur.
- **Sömürü ve keşif (exploitation-exploration):** Sistem bir süre sonra ezberler ve sürekli aynı önerileri sunar. Bu da kullanıcıyı sistemde tutmayı zorlaştırır.

### 3.4 Derin Öğrenmenin Katkıları ve Zorlukları

Derin öğrenmenin tavsiye sistemlerine katkıları şunlardır:

- **Doğrusal olmama:** Geleneksel modeller doğrusal yapıdadır. Derin modeller ReLU, sigmoid ve tanh gibi doğrusal olmayan aktivasyonlarla karmaşık kullanıcı-öğe etkileşimlerini modelleyebilir.
- **Temsil öğrenimi:** Giriş verisinin kaynağı çeşitlendirilebilir. Geleneksel modellerde elle yapılan özellik çıkarımı derin modellerde otomatikleşir ve özellik mühendisliği yükü azalır. Metin, görüntü, ses ve video gibi heterojen içerikler aynı modele katılabilir.
- **Dizi modelleme:** Kullanıcı davranışının ve öğelerin zaman içindeki değişimini incelemek için sıralı sinyallerin modellenmesi önemlidir. Bu yetenek doğal dil işleme, makine çevirisi ve konuşma tanımada zaten yaygın olarak kullanılır.
- **Esneklik:** TensorFlow ve Keras gibi kütüphaneler sayesinde derin tavsiye modelleri kurmak görece kolaylaşmıştır.

Zorlukları slaytta şöyle sıralandı (ekrandan, 00:45:00):

- Başarısına rağmen bir kara kutu gibi davranır.
- Zengin parametreleştirmeyi destekleyebilmek için veriye açtır.
- Kapsamlı hiperparametre ayarına ihtiyaç duyar. Bu da deneme sürecini uzatır.
- Farklı model karmaşıklıklarında çalışır. Örneğin RNN ardışık çalıştığı için daha yavaştır, CNN görece hızlıdır. Bu yüzden amaca uygun model seçimi önemlidir.

### 3.5 Değerlendirme Metrikleri

İncelenen çalışmalarda altı metrik kullanılmıştı. Alanda bir değerlendirme standardı bulunmadığı da vurgulandı.

- **AUC (Area Under Curve):** ROC eğrisinin altındaki alan. 1'e yaklaştıkça sınıflandırma performansı artar.
- **Ortalama kare hatası (MSE):** Tahminlerin gerçek değerlere ne kadar yakın olduğunu ölçer. 0'a yakın olması iyidir. <!-- BELİRSİZ: Altyazıda metrik adı "ortalama karar hatası" diye bozuk geçiyor; sonraki model karşılaştırmasında "ortalama kare hatası" dendiği için MSE olarak yazıldı. -->
- **Recall:** Pozitif olarak tahmin edilmesi gerekenlerin ne kadarının pozitif tahmin edildiğini gösterir. Yüksek olması iyidir.
- **Hit Ratio (HR):** Sunumda, sınıflayıcının gerçek pozitifleri ne kadar doğru tahmin ettiğinin bir ölçüsü olarak tanımlandı. Yüksek olması iyidir.
- **NDCG (Normalized Discounted Cumulative Gain):** Bilgi getiriminde sıralama kalitesini ölçer. 1'e yaklaştıkça sıralama başarısı artar.
- **RMSE (Root Mean Square Error):** Tahmin edilen ve gerçek değerler arasındaki uzaklığın karekök ortalaması. 0'a yakın olması iyidir.

> **Ek bilgi (derste anlatılmadı):** Tavsiye sistemlerinde HR@K, büyük olasılıkla test öğesinin önerilen ilk K öğe arasında çıktığı kullanıcıların oranı olarak hesaplanır. NDCG@K ise doğru öğe listede ne kadar üstteyse o kadar yüksek puan verir; logaritmik bir indirimle ($1/\log_2(\text{sıra}+1)$) sıralamadaki konumu da hesaba katar.

### 3.6 Literatür Taraması Yöntemi

Tarama ScienceDirect, ACM ve IEEE veri tabanlarında "tavsiye sistemi", "derin öğrenme" ve "hibrit öneri" anahtar kelimeleriyle yapıldı. Başlığında ve anahtar kelimelerinde "derin" ve "tavsiye" geçen çalışmalar dikkate alındı. Bu şekilde 17 çalışma incelendi, sunumda bunlardan beşi anlatıldı.

### 3.7 R1: Wide & Deep Learning for Recommender Systems (Google, 2016)

Bu çalışma geniş ve derin modellerin temelini oluşturur. Geniş (wide) kısım tek katmanlı bir algılayıcı (doğrusal model), derin (deep) kısım çok katmanlı bir algılayıcıdır (MLP). Wide & Deep, ikisinin birleştirilmesiyle ortaya çıkar. Çalışmanın amacı, Google Play'deki önerileri iyileştirip kullanıcıların daha fazla uygulama indirmesini sağlamaktı. Tavsiye sistemlerinde ezberlemenin ve genellemenin faydalarından yararlanmak için geniş doğrusal model ve derin sinir ağı ortak eğitilir (ekrandan, 00:50:00).

Sistemin işleyişi slayttaki şemaya göre şöyledir (ekrandan, 00:50:00):

```text
Sorgu (Query) --> Retrieval  <-- Database (bütün öğeler)
                     |
                     v  O(100) öğe
                  Ranking    <-- Model <-- Learner
                     |
                     v
        Sıralanmış O(10) öğe --> kullanıcı
Kullanıcı eylemleri ve gösterilen öğeler --> Logs --> Learner
```

Kullanıcı bir uygulama sorgusu gönderince veritabanından aday öğeler çekilir. Model bunları sıralar ve en iyi on kadar öğe kullanıcıya sunulur. Gösterilen öğeler ve kullanıcı eylemleri loglanır ve modeli yeniden eğitmek için kullanılır. Böylece kendini besleyen bir döngü oluşur.

Model yapısında geniş kısım, kullanıcının uygulamayı kurup kurmadığı gibi bilgilere uygulanan çapraz çarpım (cross-product) dönüşümlerini alır ve lojistik kayba gönderir. Derin kısımda yaş ve demografik bilgiler gibi öznitelikler kullanılır. Kategorik öznitelikler 32 boyutlu gömme vektörlerine dönüştürülür. Gömmeler sürekli özniteliklerle birlikte yaklaşık 1200 boyutlu bir vektörde birleştirilir. Sürekli öznitelikler herhangi bir işlem yapılmadan bu vektöre katılır. Ardından üç ReLU katmanı uygulanır. En sonda derin kısmın çıktısı ile çapraz çarpım öznitelikleri lojistik kayıpta birleştirilir.

> **Ders sonrası not:** Sunumda gömmelerin "32 katmanlı" olduğu söylendi. Doğrusu büyük olasılıkla 32 boyutlu gömme vektörleridir; katman sayısı değil, vektör boyutudur.

Değerlendirmede yalnız geniş modelin kullanıldığı grup kontrol grubu olarak alındı (kullanıcıların %1'i). Yalnız derin model ve Wide & Deep modeli bununla karşılaştırıldı. Geniş ve derin ağları birlikte kullanmanın başarıyı en çok artırdığı raporlandı. Çalışmanın özgün yanlarından biri de modelin çevrimiçi (online) çalıştırılabilmesidir. Bunun için arka planda ciddi bir model küçültme çalışması yapılmıştır.

### 3.8 R2: CARL, Bağlama Duyarlı Kullanıcı-Öğe Temsili (Wu vd., 2018)

Çalışmanın adı "A Context-Aware User-Item Representation Learning for Item Recommendation" (2018, Libing Wu vd.) idi (ekrandan, 00:55:00). Amaç, puan tahmini için belirli bir kullanıcı-öğe çiftine özgü gizli öznitelikleri ve gizli öznitelik etkileşimlerini birlikte kullanan, bağlama duyarlı ortak bir kullanıcı-öğe temsili öğrenmekti. Genelde kullanıcılar için standart bilgiler (demografi, ürünle etkileşim, verilen puanlar) kullanılır. Bağlama duyarlılık ise gizli kalmış bilgilerden yeni öznitelikler çıkararak performansı artırmayı hedefler.

Modelde iki CNN mimarisi vardır. Biri öğe ve kullanıcı dokümanlarından (yorumlardan) yoruma dayalı öznitelik öğrenir. Diğeri kullanıcı kimliği ve öğe kimliğinin etkileşiminden öznitelik çıkarır. İki yapıdan çıkan öznitelikler bir faktorizasyon makinesiyle birleştirilir. Dinamik füzyon adı verilen ve hibrit modellerde kullanılan bir yapının bu çalışmaya özgü bir biçimi de eklenir. Yorum tabanlı ve etkileşim tabanlı çıktılar ayrı ayrı üretilip sonra birleştirilir; bu modelin özgün yanlarından biridir. Model Amazon'un beş veri kümesi ile Beer ve Yelp veri setlerinde ortalama kare hatası (MSE) ile test edildi.

CARL, diğer çalışmalardan sekiz modelle karşılaştırıldı (ekrandan, 00:55:00). Değerler hatadır; küçük olan daha iyidir:

| Yöntem | Musical Instr. | Office Prod. | Digital Music | Video Games | Tools Impr. | Beer | Yelp16-17 |
|---|---|---|---|---|---|---|---|
| PMF | 1.401 | 1.091 | 1.211 | 1.669 | 1.564 | 1.636 | 2.575 |
| CDL | 0.861 | 0.754 | 0.882 | 1.179 | 1.033 | 0.678 | 1.727 |
| RBLT | 0.815 | 0.757 | 0.872 | 1.147 | 0.983 | 0.576 | 1.570 |
| CMLE | 0.818 | 0.761 | 0.883 | 1.254 | 1.023 | 0.607 | 1.592 |
| ConvMF | 0.991 | 0.960 | 1.084 | 1.449 | 1.240 | 0.853 | 1.992 |
| DeepCoNN | 0.814 | 0.860 | 1.060 | 1.238 | 1.063 | 0.617 | 1.592 |
| TransNets | 0.799 | 0.760 | 0.910 | 1.196 | 1.008 | 0.586 | 1.525 |
| D-attn | 0.984 | 0.824 | 0.914 | 1.142 | 1.046 | 0.616 | 1.575 |
| **CARL** | **0.776** | **0.722** | **0.831** | **1.065** | **0.942** | **0.557** | **1.446** |
| İyileşme (%) | 2.89 | 4.24 | 4.70 | 6.74 | 4.17 | 3.30 | 5.18 |

Son satırdaki iyileşme oranı, her veri setinde CARL'ın en iyi karşılaştırma modeline göre hatadaki göreli azalmasıdır. Örneğin Video Games sütununda en iyi karşılaştırma modeli D-attn'dir (1.142):

$$\frac{1.142-1.065}{1.142}\times 100 \approx 6.74\%$$

Python ile yapılan kontrolde öteki sütunlar da tabloyla uyuştu. Yalnız Musical Instruments sütununda hesap %2.88 çıkıyor; tablodaki %2.89, büyük olasılıkla yuvarlanmamış değerlerden hesaplanmıştır.

Sunumda bir gözlem de paylaşıldı: incelenen çalışmalarda yeni model her zaman önceki modellerle karşılaştırılıyor ve hep daha iyi çıkıyor. Örneğin 2017'deki bir model 2018'deki bir çalışmada karşılaştırma modeli oluyor. Bu, alanın hâlâ incelenmeye çok açık olduğunu gösteriyor.

### 3.9 R3: Derin Sinir Ağlı Verimli Bir Hibrit Tavsiye Modeli (Huang vd., 2019)

Çalışmanın adı "An Efficient Hybrid Recommendation Model With Deep Neural Networks" (2019, Zhenhua Huang vd.) idi (ekrandan, 01:00:00). Amaç, kullanıcı-öğe etkileşimini birden çok bakış açısından öğrenen, kullanıcı tercihini daha kapsamlı yansıtan ve genelleme yeteneği güçlü bir derin hibrit model kurmaktı. Model belirli bir alana değil, birçok tavsiye problemine uygulanabilecek biçimde tasarlandı. Önemli bir nokta, kullanıcı verisinin iki ayrı biçimde ele alınmasıdır: temel bilgiler (basic information) ve geçmiş tercihler (historical preference). Kullanıcı özellikleri zamanla değiştiği için bu ayrım başarıyı artırır. <!-- BELİRSİZ: Modelin kısaltması altyazıda "DeepML", "DFML" ve "DFL" diye farklı geçiyor; doğru ad karelerden doğrulanamadı. -->

Model iki aşamalıdır: özellik öğrenme ve tercih oluşturma. Özellik öğrenmede öğe öznitelikleri bir derin sinir ağıyla (MLP) vektöre dönüştürülür. Kullanıcı tarafında temel bilgi ve geçmiş tercih vektörleri hem ayrı ayrı hem de birleştirilerek üretilir; böylece bu ayrımı içermeyen veri setlerinde de karşılaştırma yapılabilir. Tercih oluşturma aşamasında üç modül vardır (ekrandan, 01:00:00):

- **SDAE-FM modülü:** Faktorizasyon makinesi kullanıcılar ve öğeler arasındaki öznitelik etkileşimini öğrenir. Yığınlanmış gürültü giderici otokodlayıcı (Stacked Denoising Autoencoder, SDAE) çok sayıdaki özniteliği azaltarak en iyilerini seçer. Wide & Deep'ten esinlenerek bir tek katmanlı yapı (birinci dereceden öznitelikler) ve bir çok katmanlı yapı (ikinci dereceden öznitelik birleşimleri) kurulur.
- **DNN modülü:** Kullanıcı ve öğelerin gizli özniteliklerini çıkarır ve aralarındaki doğrusal olmayan ilişkiyi keşfeder. Slayttaki yapıda üç ReLU-BN katmanı ve sigmoid çıkış vardır.
- **Metrik öğrenme modülü:** Kullanıcı ile öğe arasındaki ilişkiyi mesafe bakış açısından ölçer. Siamese ağlarla eğitilir: kullanıcı ve öğe ayrı kollarda evrişim, maksimum havuzlama ve tam bağlı katmanlardan geçer, sonra benzerlik hesaplanır.

Üç modülün tahminleri birleştirilerek nihai tercih tahmini üretilir. Değerlendirmede iki MovieLens veri seti ve Book-Crossing veri seti, metrik olarak Recall ve AUC kullanıldı. Model altı parçaya ayrılarak incelendi: yalnız FM modülü, yalnız derin modül, yalnız metrik modülü, bunların ikili etkileşimleri ve üçünün birleşimi. Birleşik model üç veri setinde de alt parçalarından daha başarılı oldu. Daha önceki altı modelle (Wide & Deep dahil) karşılaştırmada da en iyi sonucu verdi. Bir deneyde kullanıcı verisinin %30, %50 ve %100'ü kullanıldı. Kullanıcı sayısı azalsa bile performansın çok etkilenmediği raporlandı.

### 3.10 R4: Kişiselleştirilmiş İş Öneri Sistemi

Türkiye'de bu alanda az çalışma olduğu için bir yerli çalışma da seçildi. Çalışma, karşılıklı tavsiye sistemlerine bir örnek olan iş öneri sistemi tasarlar. Kategorik öznitelikler, sürekli öznitelikler ve kimlik (ID) değişkeni alınır. ID değişkeni, önceki modellerde olduğu gibi hem ayrı ayrı hem de birleşik olarak matris faktorizasyonu ile eğitilir. Matris faktorizasyonu katmanı ve derin sinir ağı katmanından çıkan sonuçlar birleştirilip derin bir hibrit katmana verilir ve tahmin üretilir. Bir iş ilanı platformunun verisi kullanıldı. Metrik olarak Hit Ratio ve NDCG, değerlendirmede ilk N listesi ($N=10$) kullanıldı. Dört çalışmayla karşılaştırmada geliştirilen model en başarılı sonucu verdi.

### 3.11 R5: Puan, Yorum ve Meta Veriyi Birlikte Kullanan Derin Hibrit Model (Khan vd., 2021)

Çalışmanın adı "A Deep Hybrid Model for Recommendation by jointly leveraging ratings, reviews and metadata information" (2021, Zahid Younas Khan vd.) idi (ekrandan, 01:05:00). Farklı bilgi kaynaklarından öğrenilen gizli özniteliklerin korelasyonlarını dikkate alır ve puanları, yorumları ve meta veriyi birlikte kullanır. Meta verinin kullanılması modelin en önemli özelliklerindendir.

Modelde UserNet ve ItemNet adlı iki CNN mimarisi vardır. Her birinin içinde kullanıcı ve öğe yorumlarını işleyen bir ağ (TNet) ve meta veriyi işleyen ayrı bir ağ (MNet) bulunur. Çıkarılan öznitelikler bir füzyon katmanında birleştirilir ve yoğun (dense) katmanlardan geçer. Burada dikkat (attention) mekanizması önemlidir; derin öğrenmenin yorumlanabilirlik sınırını aşmaya yardım eder. En sonda tam bağlı bir katmanla regresyon yapılarak puan tahmin edilir.

Değerlendirmede Amazon Product Review ve Yelp Business Rating Prediction Challenge 2013 veri setleri, metrik olarak RMSE kullanıldı (ekrandan, 01:05:00):

| Veri seti | #users | #items | #reviews | #reviews/user | #reviews/item | Sparsity |
|---|---|---|---|---|---|---|
| Amazon instant video | 5130 | 1685 | 37,126 | 7.24 | 22.03 | 99.57% |
| Musical instruments | 1429 | 900 | 10,261 | 7.18 | 11.40 | 99.20% |
| Office products | 4905 | 2420 | 53,258 | 10.86 | 22.01 | 99.55% |
| Grocery & gourmet food | 14,681 | 8713 | 151,254 | 13.32 | 17.52 | 99.88% |
| Yelp2013-I | 45,981 | 11,537 | 229,906 | 5 | 19.92 | 99.95% |
| Yelp2013-II | 1631 | 1633 | 78,966 | 48.42 | 48.36 | 97.03% |

Seyreklik, $1-\dfrac{\#\text{reviews}}{\#\text{users}\times\#\text{items}}$ oranıdır. Örneğin Amazon instant video için $1-\dfrac{37126}{5130\times1685}\approx 0.9957$, yani %99.57 çıkar.

> **Ders sonrası not:** Tablodaki oranlar python ile kontrol edildi. Grocery & gourmet food satırında verilen sayılardan $151254/14681\approx 10.30$ ve $151254/8713\approx 17.36$ çıkıyor; slaytta ise 13.32 ve 17.52 yazıyor. Bu fark büyük olasılıkla kaynak makaledeki tablodan geliyor (ön işleme öncesi ve sonrası sayıların karışması gibi). Öteki satırlarda yalnız son basamakta yuvarlama farkı var.

Model, daha önce geliştirilmiş yedi modelle (DeepCoNN ve CARL dahil) karşılaştırıldı ve daha iyi performans gösterdi. Yalnız meta veri, yalnız yorum ve ikisinin birlikte kullanıldığı varyantlar karşılaştırıldığında hepsinin birlikte kullanımı en iyi sonucu verdi.

### 3.12 Genel Değerlendirme ve Öneriler

Sunumun genel değerlendirmeleri şunlardı:

- Kullanıcı-öğe ortak temsil modellerinde kullanılan bağlam bilgisi (meta veri, puan dışındaki genel bilgiler), önerileri kullanıcının koşullarına uyarlar. Soğuk başlangıç ve seyreklik gibi problemleri büyük ölçüde hafifletir.
- Gizli bilgi kaynaklarından kullanıcının zamana göre ilgileri ya da niyetleri çıkarılabilir. Derin öğrenme bu ek bilgileri modele katmak için güçlü bir yoldur.
- Geleneksel hibrit modellerde özellik çıkarımı elle yapıldığı için zaman alıcıdır. Derin ağlar otomatik özellik çıkarımıyla kaynak ve zaman kazandırır.
- Dikkat modelleri hem performansı artırır hem de kara kutu problemini hafifletir.
- Son modellerin farklı amaçlı veri setlerinde denenmesi, alan bağımsız çalışabilmeleri açısından önemlidir.
- IoT ile birlikte veri büyüdü. Geleneksel modellerde ölçeklenebilirlik sorunu çıktı. Derin öğrenme ve GPU teknolojisi büyük veride hızlı ve etkin çalışmayı sağladı.
- Alanın büyük sınırlılıklarından biri, değerlendirme için kullanılabilecek veri kümelerinin az olmasıdır. Aynı Amazon ve Yelp veri setlerinin tekrar tekrar kullanılması bunu gösterir.

Yeni çalışma önerileri:

- İncelenen çalışmalarda özellik çıkarımı büyük ölçüde metinden yapılmış. Metin, görüntü, ses ve video gibi heterojen verilerle yeni modeller tasarlanabilir.
- Yorumlanabilirlik sorununa çözüm olarak dikkat tabanlı modeller geliştirilebilir.
- İncelenen derin mimariler çoğunlukla ardışık tasarlanmış. Hiyerarşik derin mimariler denenebilir.
- Makine okuma, akıl yürütme, soru cevaplama ve görsel akıl yürütme gibi görevler tavsiye sistemlerine uyarlanabilir. Bu, özellikle gerçek zamanlı sistemler için önemli olabilir.
- Büyük bir öğretmen modelden bilgi alan daha küçük bir öğrenci model tasarlanarak (bilgi damıtma) gerçek zamanlı ve verimli tavsiye sistemleri kurulabilir.

## 4. Manifold Öğrenme ve Denetimsiz Boyut İndirgeme

### 4.1 Tanım ve Motivasyon

Manifold öğrenme (çok yönlü öğrenme), doğrusal olmayan yüksek boyutlu verinin düşük boyuta dönüştürülmesi işlemi olarak tanımlanır. Doğrusal veri setlerinde temel bileşen analizi (PCA) kullanılabilir ve en çok tercih edilen yöntemdir. Ancak veri doğrusal değilse PCA doğru sonuç vermez. Yüksek boyuttaki veri grafikle gösterilemez ve yeterince analiz edilemez. Örneğin bir ürünün bin özniteliği varsa bu bin boyuta göre analiz yapmak ve görselleştirmek zordur. Bu nedenle iki yol ayrılır: doğrusal veride PCA gibi yöntemler, doğrusal olmayan veride manifold öğrenme. Bütün manifold öğrenme algoritmalarının ortak noktası, veriler arasındaki mesafeleri korumaktır. Her algoritma bu mesafeyi farklı adımlarla korur.

Sunum dört kategoride düzenlenmişti: literatüre giriş makaleleri (2), bu algoritmaları geliştiren yöntem makaleleri (3), örnek dışı (out-of-sample) problemine çözüm makaleleri (4) ve sınıflandırmada kullanım makaleleri (3).

Girişte, üç boyutlu S biçimli bir veri kümesinin 1000 nokta ve 10 komşuyla sekiz manifold yöntemi kullanılarak iki boyuta indirildiği karşılaştırmalı bir şekil gösterildi (ekrandan, 01:20:00). Şekildeki çalışma süreleri şöyleydi:

| Yöntem | Süre (s) |
|---|---|
| LLE | 0.085 |
| LTSA | 0.12 |
| Hessian LLE | 0.3 |
| Modified LLE | 0.22 |
| Isomap | 0.5 |
| MDS | 2 |
| SE (Spectral Embedding) | 0.064 |
| t-SNE | 7.1 |

Şekilde LTSA, Hessian LLE, Modified LLE ve Isomap S yüzeyini düzgün bir dikdörtgene açarken, MDS S biçimini büyük ölçüde korudu. Standart LLE ve SE ise yüzeyi bir yay biçiminde sıkıştırdı.

### 4.2 Isomap (Tenenbaum vd., 2000)

Tenenbaum ve arkadaşları 2000'de doğrusal olmayan boyut indirgeme problemini ortaya koydu. Denedikleri veri setlerinde PCA ve MDS gibi doğrusal yöntemler istenen sonucu vermedi. Bu yöntemler yalnız Öklit uzaklığına baktığı için verinin içsel boyutunu saptayamıyordu. Isomap algoritması, Öklit uzaklıklarını kullanarak içsel yapı boyunca ölçülen jeodezik mesafeyi tahmin etmeye çalışır. Slayttaki şekilde kesikli çizgi iki nokta arasındaki Öklit mesafesini, düz çizgi ise jeodezik mesafeyi gösteriyordu. Elimizde noktalar arasındaki Öklit mesafeleri vardır, ama jeodezik mesafe doğrudan bilinmez.

Algoritmanın adımları:

- Öklit mesafelerine göre bütün noktaların bir komşuluk grafı çıkarılır.
- Bu graf üzerinde bütün nokta çiftleri için en kısa yollar hesaplanır. Böylece jeodezik mesafeler tahmin edilir.
- Bu mesafeler düşük boyutlu bir uzayda korunarak veri görselleştirilir.

### 4.3 Yerel Doğrusal Gömme (LLE, Roweis ve Saul, 2000)

Aynı yıl aynı dergide Roweis ve Saul, yerel doğrusal gömme (Locally Linear Embedding, LLE) algoritmasını yayımladı. Adımlar slaytta şöyleydi (ekrandan, 01:25:00):

- k-en yakın komşu algoritmasıyla yerel komşuluklar hesaplanır.
- En küçük kareler yöntemiyle her nokta komşularının ağırlıklı bir toplamı olarak yeniden kurulur. Ağırlıklar şu hatayı en aza indirir:

$$\varepsilon(W)=\sum_i \Big|\vec X_i-\sum_j W_{ij}\vec X_j\Big|^2 \qquad (1)$$

- Düşük boyutta göstermek için aynı ağırlıklar korunarak koordinatlar hesaplanır:

$$\Phi(Y)=\sum_i \Big|\vec Y_i-\sum_j W_{ij}\vec Y_j\Big|^2 \qquad (2)$$

$$M_{ij}=\delta_{ij}-W_{ij}-W_{ji}+\sum_k W_{ki}W_{kj} \qquad (3)$$

Yani yüksek boyuttaki $\vec X_i$ noktası, aynı komşuluk ağırlıklarını koruyan düşük boyutlu $\vec Y_i$ noktasına dönüştürülür. Isomap bütün noktaların komşuluk yapısıyla ilgilenirken LLE yalnız her noktanın kendi komşularıyla ilgilenir; daha yerel çalışır. Roweis ve Saul, yöntemin denetimli sinir ağlarıyla birlikte kullanılırsa iyi sonuç vereceğini öngörmüştü, ancak sunumda bu yönde sonraki çalışma görülmediği söylendi. LLE'nin Isomap'e göre daha iyi sonuç verdiği ve hesabı daha kısa sürede yaptığı raporlanmıştır. Bu iki makaleyle manifold öğrenme 2000 yılında makine öğrenmesi ve yapay sinir ağları araştırmalarının ilgi alanına girdi.

> **Ek bilgi (derste anlatılmadı):** (3)'teki $M$ matrisi $M=(I-W)^\top(I-W)$ biçiminde yazılabilir. LLE'de düşük boyutlu koordinatlar, büyük olasılıkla bu matrisin en küçük sıfırdan farklı özdeğerlerine ait özvektörlerinden elde edilir; (2)'deki maliyet $\Phi(Y)=\operatorname{tr}(Y^\top M Y)$ olarak yazılır.

### 4.4 Laplacian Eigenmaps ve Hessian Eigenmaps

Isomap ve LLE manifold öğrenmenin temelini oluşturur ve sonraki çalışmalar çoğunlukla bunları değiştirir. Atıf sayılarına göre LLE üzerine yapılan çalışmalar Isomap'tekilerden daha fazladır.

**Laplacian Eigenmaps (Belkin ve Niyogi, 2003):** Yine k-en yakın komşu algoritmasıyla bir komşuluk grafı kurulur. Komşular arasındaki bağlılık ağırlıkları LLE'deki en küçük kareler yerine bir çekirdek (kernel) yöntemiyle belirlenir. Ardından Laplacian özvektörleriyle veri düşük boyutta yeniden temsil edilir. Isomap ve LLE'den daha iyi sonuç verdiği belirtilmiştir. Sunumda yöntemin matematiksel ayrıntısına girilmedi.

**Hessian Eigenmaps (Donoho ve Grimes, 2003):** Laplacian Eigenmaps'in adımlarını izler, yalnız son adımda Hessian özvektörlerini kullanır. Isomap ve Laplacian'dan daha başarılı sonuç verdiği raporlanmıştır. Ancak Hessian ikinci türev hesabı gerektirdiği için süre ve maliyet bakımından diğer iki algoritmadan kötüdür. Bu, beyin nöron verisi ya da görüntü pikselleri gibi çok yüksek boyutlu verilerde belirgin hâle gelir. Atıf sayılarına göre Hessian tabanlı çalışmaların azlığı da büyük olasılıkla bu maliyetten kaynaklanır.

**Denetimli Hessian Eigenmap (Zhang, Tao, Liu, 2015):** Donoho ve Grimes'ın Hessian algoritmasını değiştirir (ekrandan, 01:30:00). Klasik algoritmada komşuluklar etiketsiz k-en yakın komşuyla belirlenir. Bu çalışmada komşuluk bilgileri etiketleri kullanan denetimli bir k-en yakın komşu algoritmasıyla bulunur. Ardından düğümlerin bağlılık ağırlıkları hesaplanır ve Hessian Eigenmaps ile veri düşük uzayda yeniden temsil edilir. Klasik Hessian algoritmasından daha iyi sonuç verdiği raporlanmıştır. Sunumda, konunun denetimli öğrenmeye kaymasına karşın Hessian ile ilişkisi nedeniyle incelendiği ve makalenin az atıf aldığı belirtildi.

### 4.5 Örnek Dışı (Out-of-Sample) Problemi

Bilinen sınıflandırma yöntemlerinde bir eğitim verisi ve bir test verisi vardır. Sistem eğitim verisiyle öğrenildikten sonra test verisine hızla uygulanır. Isomap ve LLE'den türeyen manifold yöntemleri ise açık bir dönüşüm matrisi ya da fonksiyonu üretmez. Bu yüzden eğitimden sonra yeni bir test verisi geldiğinde bütün sistemi en baştan, test verisini de katarak çalıştırmak gerekir. Bu duruma örnek dışı (out-of-sample) problemi denir. Sunumda bu probleme dört çözüm aktarıldı:

- **Bengio vd. (2003):** Beş farklı denetimsiz öğrenme algoritması için ortak bir genişletme formülü önerildi. Bu formül uygulanarak eğitim verisini yeniden çalıştırmadan test verisi gömülebilir.
- **He ve Niyogi (2004), Locality Preserving Projections (LPP):** Eğitim verisinin bir haritası (doğrusal izdüşümü) oluşturulur. Yeni test verisi bu harita üzerinden doğrudan eşlenir.
- **Liu (2005), komşuluk koruyan yaklaşım:** Bütün noktaların k komşusu belirlenir ve alt uzaya dönüşüm yapılır. Her nokta için doğrusal dönüşüm katsayıları elde edilir. Bu noktaya yakın yeni bir test verisi gelirse aynı katsayılarla doğrudan alt uzaya taşınır. Bu iki yöntem parametrik olmadığı için bir ölçüde elle yapılan işlem içerir, ama bütün sistemi yeniden çalıştırmaz. <!-- BELİRSİZ: Yazar adı altyazıda "LiU 2005" diye geçiyor; karelerden doğrulanamadı. -->
- **Gizli değişken modeli (2008):** Eğitim setinden bir eşleme formülü üretilir. Test verisi bu formülle bütün işlemler tekrarlanmadan alt uzaya taşınır. Kolay uygulanabildiği ve hesaplama bakımından verimli olduğu belirtildi. <!-- BELİRSİZ: Yazar adı altyazıda "Perpina Velo" diye geçiyor; büyük olasılıkla Carreira-Perpiñán ve Lu'nun Laplacian Eigenmaps gizli değişken modeli (LELVM) kastediliyor. -->

### 4.6 Sınıflandırmada Manifold Öğrenme

Manifold öğrenme bugüne kadar daha çok görüntü işleme ve görselleştirmede kullanılmıştır. Sınıflandırmada az sayıda çalışma vardır ve bunlarda yöntem çoğunlukla özellik çıkarımı gibi bir ön işleme adımı olarak kullanılmıştır. Sonuçları ve veri setleri net olan üç makale seçildi.

**Ulaşım türü tespiti (Sağbaş, Peker, Ballı, 2017):** "A Novel Approach for Transportation Mode Detection: Combining t-SNE Manifold Learning and SVM" başlıklı çalışmanın amacı, akıllı telefon algılayıcı verilerinden ulaşım türünü (yürüme, otobüs, araba gibi) tespit etmektir (ekrandan, 01:35:00). 14 özniteliğe MDS, t-SNE, Isomap, LLE ve Spectral Embedding uygulandı ve öznitelikler 2'ye indirildi. En iyi sonucu t-SNE verdi. Ardından destek vektör makineleriyle üç çekirdek fonksiyonu kullanılarak sınıflandırma yapıldı:

| Çekirdek fonksiyon | AUC | CA | F1 |
|---|---|---|---|
| Doğrusal | 0.730 | 0.527 | 0.522 |
| Polinom | 0.744 | 0.553 | 0.562 |
| RBF (Radial basis function) | 0.979 | 0.963 | 0.963 |

En iyi sınıflandırmayı RBF çekirdeği verdi. t-SNE ile elde edilen iki boyutlu dağılımda sınıflar iyi ayrışıyordu, ancak araba ve otobüs kullanımının birbirine karıştığı görüldü; bu, iyileştirme alanı olarak yorumlandı.

> **Ders sonrası not:** Slaytta yöntem adı "t-SEN" diye yazılmıştı; sunumda da düzeltildiği gibi doğrusu t-SNE'dir.

**Soru (hoca):** Bu örnekte manifold öğrenme öznitelik sayısını ikiye mi düşürüyor? **Cevap:** Evet. Hoca, bu veri setinin UCI Repository'de bulunduğunu, bir öznitelik seçme algoritmasıyla iki üç özniteliğe inildiğinde de çok başarılı sonuçlar alındığını söyledi ve bu veriyle hızlı denemeler yapılabileceğini önerdi.

**Hiperspektral görüntü haritalama:** Bir yerli çalışmada haritalama için Laplacian Eigenmaps kullanıldı. Veri seti olarak Botswana, Kennedy Space Center ve Indian Pines kullanıldı. <!-- BELİRSİZ: Üçüncü veri setinin adı altyazıda "IDM Pyce" diye geçiyor; büyük olasılıkla Indian Pines. --> Çalışma, manifold öğrenmenin sınıflandırmadaki zorluklarını ve örnek dışı problemini ele alır. Örnek dışı problemini çözen dört yöntem karşılaştırıldı; ön işleme olarak etiketli k-en yakın komşu kullanıldı. Gizli değişken modeli doğruluk bakımından ve farklı veri setlerinde istikrarlı olmak bakımından en iyisi oldu. Hız bakımından OOS ve LPP yöntemlerinden daha yavaştı.

**Epilepsi tespiti (Hou, Liu, Liu, Sun, 2020):** "Epilepsy Detection Using RF Classification Based on Locally Linear Embedding Algorithm" başlıklı çalışma, epilepsi cerrahisinde epileptik odakların yerini belirlemeye yönelik bir araştırmadır (ekrandan, 01:40:00). Adımları şöyledir:

- Veri seti önce LLE ile boyut azaltmaya tabi tutulur.
- Boyutu azaltılmış veriler farklı sınıflandırıcılarla sınıflandırılır ve performanslar karşılaştırılır.
- Boyut azaltma yapılmadan yapılan sınıflandırmayla da karşılaştırılır.

LLE tabanlı Random Forest en yüksek sonuçları verdi. Veri doğrusal olmadığı için F1 ve kesinlik (precision) değerlerinde LLE, PCA'dan daha iyi çalıştı. Manifold öğrenme uygulanmamış dört sınıflandırma çalışmasıyla karşılaştırmada da Random Forest'ın manifold öğrenmeyle daha da iyileştiği görüldü. Yüksek boyutlu verilerde sınıflandırma öncesinde ön işlem olarak manifold öğrenme uygulanmasının başarıyı artırdığı sonucuna varıldı.

### 4.7 Sonuçlar

- Manifold öğrenme ağırlıklı olarak görüntü ön işlemede kullanılmış; yüksek boyutlu veriyi düşük boyuta indirip görselleştirmeye ve yorumlamaya odaklanılmıştır.
- Sınıflandırmada çoğunlukla ön işleme algoritması olarak kullanılmış ve sınıflandırma başarısını artırmıştır. Ancak çalışma sayısı az olduğu için bu kesin bir genelleme değildir; bu yönde daha fazla çalışma gerekir.
- Isomap ve LLE'yi ortaya koyan makaleler, yöntemin yalnız ön işleme değil ana yöntem olarak da kullanılabileceğini öne sürmüştü, ama bu yönde fazla çalışma yapılmamıştır.
- Örnek dışı problemi üzerine çalışmalar vardır, ama arada boşluklar bulunur. Sunumda 2008'den 2014-2015'e kadar az sayıda sonuç veren çalışmaya ulaşıldığı belirtildi. Bu çalışmaların atıf sayıları da düşüktür (örneğin 2005 tarihli komşuluk koruyan çalışmanın 108 atıfı).

Sunum sonunda bir öğretim üyesi, sınıflandırma makalelerinde verilerin hep görüntü olup olmadığını sordu. Sınıflandırma örneklerinin yüz tanıma, haritalama ve konum belirleme ağırlıklı olduğu, temel makalelerde metin üzerinde de denendiği, ancak ayrıntılı çalışma bulunmadığı cevabı verildi. Ardından konunun güçlü bir matematik altyapı gerektirdiği ve destekleyici çalışmaların az olduğu tartışıldı.

### 4.8 Öz Nitelik Azaltma Başarıyı Nasıl Artırır?

Sunumdan sonra kavramsal bir soru tartışıldı. Öznitelik seçme ya da azaltmada amaç genelde başarıdan kayıp yaşamadan veriyi küçültmektir. Ancak 14 öznitelik 2-3'e indirilince her öznitelikten bir miktar bilgi kaybedilir. Bu kayba rağmen başarı nasıl artabilir?

Sunumdaki cevap, manifold öğrenmenin alt uzaya dönüşüm için önemli öznitelikleri çekmeye çalıştığı yönündeydi. Hoca bunu şöyle tamamladı: indirgeme işleminde ilgili (relevant) ve sınıfları ayırt edici öznitelikler seçilir. İlgisiz öznitelikler çıkarılınca sistemin "kafası karışmaz", yani gereksiz verilerle yanlış yönlere gitmesi önlenir. Bu yüzden örneğin 14 öznitelikle %90 başarı elde edilirken 2'ye inince %95 başarı elde edilmesi mümkündür.

> **Hocanın vurgusu:** İlgisiz öznitelikleri çıkarmak sınıflandırıcıyı gereksiz yönlendirmelerden kurtarır; az öznitelikle daha yüksek başarı mümkündür.

Ardından bir takip sorusu soruldu: öznitelik azaltma bir ön işlemdir ve algoritmanın işini kolaylaştırır. Daha çok öznitelikli veri seti daha karmaşık bir modele (örneğin katman sayısı artırılmış bir sinir ağına) verilse, belki aynı başarıya ulaşılır. Bu durumda aynı karmaşıklıktaki bir algoritmayla karşılaştırmak adil midir? Hoca, bunun da mümkün bir yol olduğunu söyledi. Yapay sinir ağlarında öznitelik madenciliği elle yapılmak yerine model tarafından yapılabilir; yani öznitelik seçimi sınıflama modelinin içine entegre edilebilir. Ancak bu durumda daha karmaşık bir model kullanılmış olur. İki yol birbirine alternatiftir ve maliyetleriyle birlikte tartılmalıdır.

## 5. Çok Dilli (Cross-Lingual) Kelime Vektörleri

### 5.1 Problem: Bir Sınıflandırıcıyı Başka Dillere Aktarmak

Sunum gerçek bir metin sınıflandırma ihtiyacıyla başladı. İngilizce bir veri seti üzerinde başarılı bir metin sınıflandırıcı geliştirildikten sonra aynı sistemin birçok dilde çalışması gerekiyordu. İlk akla gelen yöntem, her dil için ayrı veri setleri toplayıp ayrı modeller eğitmektir. Ancak İngilizce veri setini elde etmek bile masraflı olduğu için Türkçe, Rusça, İspanyolca, Fransızca gibi diller için aynı yolu izlemek uygulanabilir değildir. Akademik çalışmalarda kullanılan veri setleri de çoğunlukla gerçek dünya uygulamaları için küçüktür.

"Çok dilli metin sınıflandırma" (multilanguage text classification) anahtar kelimeleriyle yapılan ilk aramalar doyurucu sonuç vermedi. Sonradan aranan kavramın literatürde "çok dilli kelime vektörleri" (cross-lingual word embeddings) olarak geçtiği anlaşıldı. Sunumda bu durum, literatür taramasında doğru anahtar kelimeyi bulmanın önemine bir örnek olarak anlatıldı.

İhtiyaç, bir metin sınıflandırıcının yeteneklerini en az eforla başka bir dile aktarmaktır. En çok efor isteyen iş veri toplamaktır. Temel yaklaşımlardan biri şöyledir: farklı dillerin vektörleri İngilizce vektör uzayına dönüştürülür ve sınıflandırma İngilizce için eğitilmiş model üzerinden yapılır. İngilizce, dünya genelinde kaynak bakımından en zengin dil olduğu için seçilir. İngilizce sınıflandırıcı başarılıysa ve diller arası dönüşüm sağlıklıysa, örneğin Fransızca metinler de bu modelle sınıflandırılabilir.

### 5.2 Tek Dilli Kelime Gömmeleri

Çok dilli kelime vektörleri tek dilli kelime gömmeleri (word embeddings) üzerine kurulur. Hoca, "word embedding" teriminin Türkçede "kelime gömmesi" olarak kullanıldığını hatırlattı. NLP problemlerinde eskiden seyrek (sparse) vektörler çok yaygındı. Kelime gömmeleri ise yoğun (dense) vektörler verir. Geniş bir vektör uzayını daha dar, indirgenmiş bir uzaya taşır ve bu uzayda bazı anlamsal bilgiler kodlanmış olur.

Slayttaki örnekler (ekrandan, 02:00:00):

- **Erkek-kadın:** king → queen ve man → woman vektör farkları paraleldir. King, queen ve man verildiğinde benzerlik skorlarına göre woman bulunabilir.
- **Fiil zamanı:** walking → walked ve swimming → swam ilişkileri benzer yönlerdedir.
- **Ülke-başkent:** Spain-Madrid, Italy-Rome, Germany-Berlin, Turkey-Ankara, Russia-Moscow, Canada-Ottawa, Japan-Tokyo, Vietnam-Hanoi, China-Beijing çiftleri benzer vektör farklarıyla temsil edilir.

Kelime vektörlerinin öğrenilmesi denetimsiz bir makine öğrenmesi problemidir. En bilinen yaklaşımlar CBOW ve Skip-gram'dır; 2014'te GloVe da bunlara eklenmiştir. Bu yaklaşımlarda çok büyük derlemler üzerinde denetimsiz eğitim yapılır. Vektör boyutu bir hiperparametredir: 50, 100 ya da 300 verilebilir. Sunumda açık kaynak paylaşılan gömmelerde 50, 100, 150 ve 300 boyutlarının sık tercih edildiği söylendi. Boyut arttıkça daha fazla anlamsal bilgi kodlanabilir, ama donanım ihtiyacı da artar. Bu yüzden gömme paylaşan çalışmalar 300 boyutlu matrisin yanında 50 gibi daha düşük boyutlu sürümler de paylaşır. <!-- BELİRSİZ: "Sebo" diye geçen yöntem bağlamdan CBOW olarak yazıldı. -->

### 5.3 Ortak Vektör Uzayı

Çok dilli kelime vektörleri, tek dilli kelime vektörlerinin birden fazla dili temsil eden ortak bir uzaya indirgenmiş hâlidir. Slayttaki şekilde (ekrandan, 02:05:00) solda birbirinden bağımsız öğrenilmiş İtalyanca (kırmızı) ve İngilizce (yeşil) kelime gömmeleri t-SNE ile iki boyuta indirilmişti; iki dilin dağılımları tamamen ayrıydı. Sağda aynı gömmeler ortak bir uzaya izdüşürüldükten sonra line-linea, group-gruppo, drink-bevanda, food-cibo, production-produzione gibi karşılık çiftleri birbirine çok yakın konumlanmıştı. Şeklin başlığı "Unaligned monolingual word embeddings (left) and word embeddings projected into a joint cross-lingual embedding space (right). Embeddings are visualized with t-SNE." idi.

> **Ders sonrası not:** Sunumda kırmızı kelimelerin İspanyolca olduğu söylendi. Karedeki kelimeler (linea, gruppo, bevanda, cibo, produzione) İtalyancadır.

Bu dönüşüm yapılabilirse, kelime gömmelerinin kullanıldığı bütün NLP uygulamalarına ortak uzayı paylaşan matris girdi olarak verilebilir. Böylece tek dili işleyen bir uygulama yerine birçok dili işleyen bir uygulama elde edilir.

### 5.4 Veri Türleri

İncelenen büyük bir derlemeye (survey) göre literatürdeki yöntemler, birbirinden farklı görünse de ya da birbirinden habersiz geliştirilmiş olsa da büyük ölçüde aynı amaç fonksiyonunu optimize etmeye çalışır. Başarıyı en çok belirleyen şey kullanılan veridir. Veri iyiyse bir optimizasyon problemiyle ortak vektör uzayı elde edilebilir.

Veriler iki eksende gruplanır: seviye (kelime, cümle, doküman) ve hizalama türü (paralel ya da karşılaştırılabilir):

- **Kelime seviyesi, paralel:** İki dildeki kelime çiftlerinin eşleştirilmesi (iki dilli sözlük).
- **Kelime seviyesi, karşılaştırılabilir:** Kelimelere karşılık görüntülerin bulunduğu veri (örneğin "kedi" kelimesi ve bir kedi görüntüsü).
- **Cümle seviyesi, paralel:** Birebir cümle çevirileri.
- **Cümle seviyesi, karşılaştırılabilir:** Aynı görüntüyü anlatan farklı dillerdeki cümleler (örneğin bir köpeğin kediyi kovaladığı görüntü ile bunu anlatan İngilizce ve İspanyolca cümleler).
- **Doküman seviyesi:** Çok dilli kelime vektörlerinde yaygın kullanılmaz; kullanıldığında da çoğunlukla cümle seviyesinde satır satır paralel bir yapı vardır.

### 5.5 Çok Dilli Kelime Vektörlerinin İki Faydası

Slaytta iki fayda sayıldı (ekrandan, 02:10:00):

- Kelimelerin anlamlarını diller arasında karşılaştırmayı sağlar. Bu, makine çevirisi ve diller arası bilgi aktarımı için önemlidir.
- Kelime vektörleri için ortak bir temsil alanı sağlayarak diller arasındaki veri seti kaynağına dayalı farklılıkları giderir. Örneğin kaynak bakımından zengin dillerde öğrenilen bilgiler kaynak bakımından fakir dillere aktarılabilir.

### 5.6 Yaklaşım Aileleri

- **Eşleme (mapping) tabanlı yaklaşımlar:** Her dilin kendi vektör uzayı vardır. İki uzay arasında bir dönüşüm matrisi öğrenilir. Bir kelime vektörü bu matrisle çarpılınca A uzayından B uzayına geçilir ve ortak bir uzayda çalışılır. Dönüşüm matrisini öğrenmek için regresyon tabanlı, ortogonal, kanonik ve marjin tabanlı yöntemler önerilmiştir.
- **Sözde çok dilli derlem (pseudo-multilingual corpora) yaklaşımları:** Algoritmik bir iyileştirme yerine veri üzerinde bir düzenleme yapılır. Örneğin İngilizce ve İspanyolca büyük derlemler alt alta eklenir. İspanyolca kelimelerin bir kısmı İngilizce karşılıklarıyla, İngilizce kelimelerin bir kısmı da İspanyolca karşılıklarıyla değiştirilir. Bu karma derlem üzerinde tek dilli bir gömme yöntemi çalıştırılınca iki dil için ortak bir uzay elde edilir.
- **Ortak (joint) yöntemler:** Önceki iki yaklaşımın olumlu yanlarını birleştirir. Fark, dönüşüm matrisi yerine bir düzenlileştirme (regularization) fonksiyonunun öğrenilmesidir. A uzayından B uzayına geçiş, matris çarpımı yerine bu fonksiyona girdi verilerek yapılır.

> **Ek bilgi (derste anlatılmadı):** Ortogonal eşlemede dönüşüm matrisi $W$ büyük olasılıkla $\min_W \|XW-Z\|_F$ problemini $W^\top W=I$ kısıtıyla çözer. Bu problemin kapalı çözümü, $X^\top Z=U\Sigma V^\top$ tekil değer ayrışımından $W=UV^\top$ olarak bulunur (Procrustes problemi). Ortogonallik, tek dilli uzaydaki mesafeleri koruduğu için tercih edilir.

### 5.7 Değerlendirme ve Benchmark'lar

Değerlendirme metrikleri ikiye ayrılır:

- **İç değerlendirme (intrinsic evaluation):** Probleme özgü kelime benzerliklerinin doğru çıkıp çıkmadığına bakar. Örneğin öğrenilen uzayda "car" ile "automobile" arasındaki benzerlik yüksek olmalıdır.
- **Dış değerlendirme (extrinsic evaluation):** Kelime hizalama tahmini ve iki dilli sözlük çıkarımı (bilingual lexicon induction) gibi görevlerle yapılır. Sözlük çıkarımında İngilizce bir sözlüğün her kelimesi için İspanyolca karşılığı bulunur ve tek dilli sözlük iki dilli sözlüğe dönüştürülür. Kelime hizalama da benzer biçimde "car" kelimesine karşılık gelen İspanyolca kelimenin ne olduğunu sorar. İki görev temelde aynı fonksiyonu kullanır, ama anlamca farklılaşır.

Değerlendirme için insanların elle oluşturduğu çok sayıda veri seti vardır. Bunlar satır sayısı bakımından küçük, ama çok sayıda makalede yayımlanmış veri setleridir. Değerlendirmeyi kolaylaştırmak için açık kaynak benchmark kütüphaneleri geliştirilmiştir (ekrandan, 02:15:00):

- https://github.com/facebookresearch/MUSE
- https://github.com/artetxem/vecmap
- https://github.com/codogogo/xling-eval

Öğrenilen bir çok dilli vektör bu kütüphanelerle test edilir ve çıktı, makalelerde başarı metriği olarak raporlanabilir. Bu, standart bir benchmark yaklaşımı sağlar.

Uygulama alanları: doküman sınıflandırma, bağımlılık ayrıştırma (dependency parsing), sözcük türü etiketleme (POS tagging), adlandırılmış varlık tanıma (NER) ve anlamsal ayrıştırma (semantic parsing). Böylece tek dil yerine birçok dilde çalışan sistemler elde edilir.

### 5.8 Soru-Cevap

Sunumdan sonra bir öğretim üyesi iki soru sordu.

**Soru:** İngilizce "car" vektöründen yararlanarak İspanyolcada arabanın karşılığı bulunmaya çalışılıyor. Ancak kelimeler eş sesli olabilir, yani yazılışları aynı, anlamları farklı olabilir. Bu bir sorun yaratıyor mu, yayınlarda buna rastlandı mı? **Cevap:** Evet, eş anlamlı ve çok anlamlı kelimelerde sorun çıkıyor. Bu yüzden değerlendirme metrikleri buna göre tasarlanmış. Bir metrik çıktıyı birebir aynı kelimeyle eşleştirmeye dayanırken, başka metrikler çıktının $k$ adet aday kelimeden birine denk gelip gelmediğine bakar. Elle oluşturulan veri setlerinde de bir kelimenin birden fazla karşılığı kodlanmıştır.

**Soru:** Transfer öğrenme ile de arama yapıldı mı? Örneğin Uygurca gibi az kaynaklı bir dil için, çok daha küçük bir veri setiyle ve önceden öğrenilmiş bilgiyi kullanarak kelime vektörleri oluşturulabilir mi? Kökleri aynı olan diller (örneğin İtalyanca ve Portekizce) için bu yardımcı olabilir mi? **Cevap:** Şimdiye kadar yalnız aynı dil içinde transfer öğrenme kullanıldı; örneğin büyük bir derlemde önceden öğrenilmiş İngilizce kelime gömmeleri bir metin sınıflandırma probleminde kullanıldı ve büyük bir derlemde yeniden eğitim yapmak gerekmedi. Diller arası geçiş yapan transfer öğrenme araştırılmadı. Çok dilli kelime vektörleri tam olarak transfer öğrenme sayılmaz; ortak bir vektör uzayına geçip orada çalışmaya dayanır. Bir dil için öğrenilmiş vektörün hiçbir işlem yapmadan başka bir dile geçişiyle ilgili bir çalışmaya rastlanmadı. Öğretim üyesi bu konularda araştırma yapılmasını önerdi.

Sunumda ayrıca Facebook'un 44 dil için hizalanmış (aligned) kelime vektörlerini yayımladığı belirtildi. Böyle hazır bir ortak uzay, bir dilde eğitilmiş sınıflandırıcının etiketli verisi olmayan başka bir dile uygulanmasında doğrudan kullanılabilir. BERT'in Facebook'a mı yoksa Google'a mı ait olduğu sorulunca BERT'in Google'ın olduğu hatırlatıldı.

## 6. Çoklu Mobil Robot Yol Planlama ve Optimizasyon Algoritmaları

### 6.1 Motivasyon ve Problem Tanımı

Robotik, son dönemin en hızlı gelişen alanlarından biridir. Robotik çalışmalar uzun süre endüstriyel alana, yani tekrar eden işlerin yapıldığı, kararlı ve statik ortamlardaki üretim robotlarına odaklandı. Dijitalleşme ile robotlar uzay, savunma, sağlık ve ulaşım gibi alanlara, hatta ev hayatına girdi. Bu yeni dönemde robotların hareketli olması, ortamı algılayıp engellere çarpmadan hareket etmesi ve çevredeki kişilerle etkileşmesi önem kazandı. Bu başlıklardan biri de birden fazla hareketli robotun hedef bulma problemidir.

Sunulan literatürün odak problemi şuydu: birden fazla mobil robotun fiziksel engellerin bulunduğu ortamlarda, belirli kısıtlar altında ve birbirlerinin yollarını kesmeden varış noktalarına giden rotalarının optimize edilerek çıkarılması.

Yol planlama; dağıtım, rotalama, kuruluş yeri belirleme, tedarik planlama ve lojistik gibi alanlarda geniş uygulaması olan, uzun yıllardır çalışılan NP-zor (NP-hard) sınıfında bir problemdir. Mobil yol planlamada amaç, olası yollar arasından en iyi sonucu veren yolu bulmaktır. Ortam statik (sabit engelli) ya da dinamik (hareketli engelli) olabilir. Robotun fiziksel ortamı önceden bilinebilir ya da belirsiz olabilir.

### 6.2 Algoritma Sınıfları

Yol planlama optimizasyon algoritmaları iki ana sınıfa ayrılır (ekrandan, 02:30:00):

```text
Optimizasyon Algoritmaları
|-- Matematik Algoritmaları (klasik, deterministik)
`-- Meta-sezgisel Algoritmalar (stokastik, olasılıksal)
    |-- Evrim Tabanlı
    |-- Fizik Tabanlı
    |-- Sürü Tabanlı
    `-- Davranışsal Tabanlı
```

Matematiksel optimizasyon algoritmaları aynı başlangıç değerleriyle her çalıştırmada aynı sonucu üretir ve bütün çözüm kümesini kapsar. Meta-sezgisel algoritmalar rastgelelik içerdiği için aynı başlangıç değerleriyle çalıştırılsalar bile genellikle birbirine çok yakın ama farklı sonuçlar üretir.

**Klasik matematiksel algoritmalar** şöyle özetlendi:

- Izgara tabanlı algoritmalar: A* (A-yıldız) ve D* (D-yıldız) arama algoritmaları.
- Geometrik algoritmalar: Minkowski toplamı, görünürlük grafı, hücre ayrıştırma. <!-- BELİRSİZ: Altyazıda bu listede "ödül tabanlı" diye bir başlık daha geçiyor; slayt karesi olmadığı için doğrulanamadı. -->
- Örnekleme tabanlı algoritmalar.

Çözüm kümesi geniş olan problemlerde matematiksel algoritmalar süre ve performans bakımından maliyetlidir. Bu tür problemlerde meta-sezgisel algoritmalar daha avantajlıdır. Meta-sezgisellerin tercih nedenleri: basit konsept, kolay uygulama, esneklik, gradyan bilgisi gerektirmemesi ve yerel optimumdan kaçınabilmesi. Bu özellikler sayesinde farklı alanlardaki birçok probleme uyarlanabilirler.

### 6.3 Meta-Sezgisel Algoritma Sınıfları

**Evrim tabanlı algoritmalar:** Doğal sistemlerdeki kalıtım ilkesini temel alır. Seçilim, çaprazlama ve mutasyon işlemleriyle bir sonraki popülasyon üretilir. Geniş problem ve çözüm uzaylarında gerçek duruma yakın sonuçlar üretebilir. Çevreye uyumdan elde edilen bilgiye göre popülasyon her kuşakta en iyiye doğru ilerler. Genetik algoritmalar bu sınıfın temelini oluşturur.

**Fizik tabanlı algoritmalar:** Fizik kanunlarından esinlenerek geliştirilmiştir. Slayttaki tablo (ekrandan, 02:35:00):

| Algoritma | Esinlenme | Öneri yılı |
|---|---|---|
| Benzetimli Tavlama (BT) | Metalürjide tavlama | 1983 |
| Yerçekimsel Yerel Arama (YYA) | Yerçekimi yasası | 2003 |
| Büyük Patlama Büyük Çöküş (BPBÇ) | Büyük Patlama ve Büyük Çöküş teorisi | 2006 |
| Küçük Dünya Optimizasyon Algoritması (KDOA) | Küçük dünya fenomeninin mekanizması | 2006 |
| Merkezi Kuvvet Optimizasyonu (MKO) | Yerçekimi kinematiği | 2007 |
| Yerçekimsel Arama Algoritması (YAA) | Yerçekimi yasası | 2009 |
| Yüklü Sistem Araması (YSA) | Coulomb yasası ve hareket yasaları | 2010 |
| Yapay Kimyasal Reaksiyon Optimizasyon Algoritması (YKROA) | Kimyasal reaksiyon prosesi | 2011 |
| Galaksi Tabanlı Arama Algoritması (GTAA) | Kuyruklu yıldızlar | 2011 |
| Işın Optimizasyonu | Işın geçişi | 2012 |
| Kavisli Uzay Optimizasyonu (KUO) | Genel izafiyet teorisi | 2012 |
| Kara Delik Algoritması (KDA) | Kara deliklerden | 2013 |

**Sürü tabanlı algoritmalar:** Tek tek sınırlı yetenekleri olan, ama bir araya gelince güçlü biçimde organize olup zor problemleri çözebilen canlı topluluklarından esinlenir. İlk örnek, kuş sürülerinden esinlenen parçacık sürü optimizasyonudur. Sunuma göre araştırmalar bu alanda yoğunlaşmıştır.

**Davranışsal tabanlı algoritmalar:** İnsan davranışından esinlenerek geliştirilen daha yeni bir sınıftır ve güncel araştırma konuları arasındadır.

### 6.4 Çıkarımlar ve Yeni Çalışma Alanı Önerisi

Sunumun çıkarımları şunlardı:

- Son yıllardaki robot çalışmalarında robotların çevreyle etkileşimi, çoklu ve ortak hareket, en uygun güzergâhta hareket, robotlar arası iletişim, görev paylaşımı ve doğru konumlama öncelikli araştırma alanlarıdır.
- Klasik matematiksel algoritmaların çoklu mobil robot ortamlarındaki yüksek zaman maliyeti ve karmaşıklığı, meta-sezgisel algoritmaların önemini artırır.
- Zaman maliyetinin düşüklüğü ve yaygın kullanım nedeniyle literatüre sürekli yeni meta-sezgisel algoritmalar eklenmektedir. Bu yüzden yol planlama probleminin türüne ve kapsamına göre meta-sezgisel algoritma seçimi bir çalışma alanı olabilir.

Robotlar gündelik hayatın parçası oldukça algoritmaların zaman kısıtları daha önemli hâle gelir. Bu kısıtı aşmak için önerilen yeni çalışma alanı kuantum robotlardı (ekrandan, 02:40:00):

- Kuantum bilgisayarların matematik problemlerine ve algoritma karmaşıklıklarına getireceği yenilikler yakın dönemin yeni teknolojik alanları arasındadır. Kuantum bilgisayarların bazı önemli klasik problemlerin zaman maliyetini etkili biçimde düşürebildiği, hatta klasik bilgisayarların çözemediği bazı zor problemleri çözebildiği gösterilmiştir.
- 1998'de Benioff'un önerdiği, robotik ile kuantumu birleştiren kuantum robotlar (qubots), kuantum teorisinin güçlü paralel hesaplama, hızlı arama yeteneği ve kuantum algoritmalarının etkinliğini kullanarak öğrenme ve karar alma hızını artırabilir. Araştırma sonuçları, klasik robotlardaki $O(N^2)$ zaman karmaşıklığının kuantum robotlarda Grover algoritmasıyla $O(N\sqrt{N})$'e indirildiğini göstermiştir.
- Çoklu robot yol planlama ve optimizasyon çalışmalarında kuantum hesaplama yöntemlerinin kullanılmasının robotların fonksiyonel özelliklerini ve hızlı karar alma mekanizmasını geliştireceği değerlendirilmiştir.

> **Ek bilgi (derste anlatılmadı):** Grover algoritması, sırasız $N$ öğe arasında aranan öğeyi klasik $O(N)$ sorgu yerine $O(\sqrt{N})$ sorguda bulur. Slayttaki $O(N^2)\to O(N\sqrt{N})$ indirgemesi, büyük olasılıkla $N$ kez tekrarlanan bir arama adımının her birinde bu kazancın elde edilmesinden gelir.

## 7. Literatür Taramasına Dair Değerlendirmeler

Hoca sunumlar boyunca literatür taramasının niteliğine dair geri bildirimler verdi. Bu geri bildirimler seminer dersinin amacı açısından genel kurallar olarak özetlenebilir:

- **Güncellik ve atıf sayısı:** Kaynak listesine bakarken her yayının yılına ve atıf sayısına bakıldı. Örneğin 2011 tarihli ve yaklaşık 1600 atıflı bir temel makalenin yanında 2019 tarihli bir derleme makalesinin bulunması olumlu karşılandı. Eski ve yeni yayınların birlikte bulunması iyi bir taramanın göstergesidir. 2020'de yayımlanmış bir konferans makalesinin atıf sayısının sıfır olması doğal karşılandı.
- **Kaynak listesinde atıf sayısı:** Kaynakların yanına atıf sayısının yazılması, hangi çalışmaların alanda etkili olduğunu göstermesi bakımından yararlıdır.
- **Doğrudan makale okuma:** Hoca, tablolarda yalnız eski yayınların görünmesini ve bilgilerin tek bir derleme makalesinden aktarılmasını literatür taraması için yetersiz buldu. Taramanın doğrudan makale okumaya dayanması ve son çalışmaları kapsaması gerektiğini söyledi. Örneklerin konunun yalnız bir alt başlığında yoğunlaşmasının da konunun tamamını yansıtmadığını belirtti.

> **Hocanın vurgusu:** Tez için yapılacak literatür taraması doğrudan makalelere dayanmalı ve yakın zamanda yapılmış çalışmaları kapsamalıdır. İkincil bir derlemedeki tabloları aktarmak yeterli değildir.

- **Doğru anahtar kelime:** Bir sunumda, ilk aramalarda doyurucu çalışma bulunamamasının nedeninin yanlış anahtar kelime olduğu, doğru terimle (cross-lingual word embeddings) aranınca zengin bir literatüre ulaşıldığı anlatıldı. Bu, literatür taramasında alandaki yerleşik terimi bulmanın önemini gösterir.
- **Alandaki boşlukların fark edilmesi:** Manifold öğrenme sunumunda sınıflandırma ve örnek dışı problemi üzerine az çalışma olduğu tespit edildi. Böyle bir boşluk hem bir araştırma fırsatı hem de destekleyici çalışma azlığı nedeniyle bir risk olarak tartışıldı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:22:35): Çok kipli duygu analizinde metin, ses ve video kiplerinin "duygu analizine etkisi" olarak gösterilen oranlar neyi ifade eder?

> **Cevap (derste verildi):** Metin, ses ve videonun bir arada olduğu bir girdide her kipin son duygu tahminine (pozitif, negatif ya da nötr) katkısını gösterir; veri miktarını değil. Sunulan çalışmada en büyük katkı metin kipinden geliyordu.

**Soru 2** (derste sözlü, 00:32:28): Sığ (shallow) çok kipli RBM ile derin (deep) çok kipli RBM arasındaki fark nedir?

> **Cevap (derste verildi):** Sığ modelde ses ve video girdileri doğrudan tek bir ortak gösterim katmanına bağlanır; kipler arasında bu katman üzerinden doğrudan bağlantı vardır. Derin modelde her kip önce kendi standart RBM'iyle ayrı öğrenilir, ortak katman bu önceden eğitilmiş katmanların üzerine kurulur. Eklenen katman sayısı bir ile sınırlı değildir. Ses ve video arasındaki korelasyon doğrusal olmadığı için sığ model bu ilişkiyi zor öğrenir.

**Soru 3** (derste sözlü, 01:47:47): Manifold öğrenmeyle 14 öznitelik 2'ye indirildiğinde her öznitelikten bir miktar bilgi kaybedilir. Buna rağmen sınıflandırma başarısı nasıl artabilir?

> **Cevap (derste verildi):** İndirgeme, ilgili ve sınıfları ayırt edici öznitelikleri korur. İlgisiz öznitelikler çıkarılınca sınıflandırıcı gereksiz verilerle yanlış yönlere gitmez. Bu nedenle örneğin 14 öznitelikle %90 başarı elde edilirken 2 öznitelikle %95 başarı mümkündür.

**Soru 4** (derste sözlü, 01:50:39): Öznitelik azaltma algoritmanın işini kolaylaştırıyorsa, daha çok öznitelikli bir veri setini daha karmaşık bir modele (örneğin daha çok katmanlı bir sinir ağına) vermek de aynı başarıyı sağlayamaz mı? Bu durumda karşılaştırma adil midir?

> **Cevap (derste verildi):** Bu da mümkün bir yoldur. Yapay sinir ağlarında öznitelik madenciliği elle yapılmak yerine modelin içine entegre edilebilir ve model öznitelikleri kendisi seçer. Ancak bu daha karmaşık bir model demektir. İki yaklaşım birbirine alternatiftir ve maliyetleriyle birlikte tartılmalıdır.

**Soru 5** (derste sözlü, 02:16:34): Çok dilli kelime vektörleriyle bir kelimenin başka dildeki karşılığı aranırken eş sesli ya da çok anlamlı kelimeler sorun yaratır mı?

> **Cevap (derste verildi):** Evet. Bu yüzden değerlendirmede yalnız birebir eşleşmeye bakan metriklerin yanında, çıktının $k$ aday kelimeden birine denk gelip gelmediğine bakan metrikler de kullanılır. Elle hazırlanan değerlendirme veri setlerinde bir kelimenin birden fazla karşılığı kodlanmıştır.

**Soru 6** (derste sözlü, 02:17:28): Az kaynaklı bir dil (örneğin Uygurca) için, transfer öğrenmeyle ve çok daha küçük bir veri setiyle kelime vektörleri oluşturulabilir mi?

> **Cevap (derste kısmen verildi):** Sunumda diller arası transfer öğrenme üzerine bir çalışma incelenmediği, çok dilli kelime vektörlerinin tam olarak transfer öğrenme sayılmadığı, ortak bir vektör uzayına geçip orada çalışmaya dayandığı söylendi. Soru, araştırılması önerilen açık bir konu olarak kaldı.

**Soru 7** (ekrandan, 00:55:00): CARL modeli Video Games veri setinde 1.065 hata değeri elde ediyor. Karşılaştırılan modeller arasında en iyisi D-attn'dir (1.142). Tablodaki %6.74 iyileşme oranı nasıl hesaplanır?

> **Çözüm (derste verilmedi):** İyileşme, en iyi karşılaştırma modeline göre hatadaki göreli azalmadır: $\dfrac{1.142-1.065}{1.142}\times100=\dfrac{0.077}{1.142}\times100\approx 6.74\%$. Aynı hesap python ile öteki sütunlara da uygulandı ve tablodaki değerlerle uyuştu (Musical Instruments'ta yuvarlama nedeniyle %2.88 / %2.89 farkı var).

## Dersin Toparlaması

Bu son seminer oturumunda beş farklı alanda literatür taraması sunuldu. Çok kipli derin öğrenme sunumu, metin, ses ve görüntünün birlikte modellenmesindeki beş temel zorluğu ve RBM tabanlı sığ ve derin çok kipli mimarileri ele aldı. Hibrit tavsiye sistemleri sunumu, geleneksel sistemlerin soğuk başlangıç ve seyreklik gibi sorunlarını, derin öğrenmenin katkılarını ve Wide & Deep'ten 2021 tarihli meta veri tabanlı modele uzanan beş çalışmayı karşılaştırdı. Manifold öğrenme sunumu, Isomap ve LLE'den başlayarak Laplacian ve Hessian Eigenmaps'e, örnek dışı problemine ve sınıflandırmada ön işleme olarak kullanıma uzandı. Çok dilli kelime vektörleri sunumu, bir dilde eğitilmiş modeli ortak bir vektör uzayı üzerinden başka dillere aktarmanın veri türlerini, yöntem ailelerini ve değerlendirme araçlarını özetledi. Son sunum ise çoklu mobil robot yol planlamasında klasik ve meta-sezgisel algoritmaları sınıflandırdı ve kuantum robotları yeni bir araştırma yönü olarak önerdi.

Sunumlara verilen geri bildirimler seminer dersinin asıl amacını hatırlattı: tez için yapılacak literatür taraması doğrudan makalelere dayanmalı, temel çok atıflı çalışmalarla birlikte son yıllardaki çalışmaları da kapsamalı ve alandaki boşlukları ortaya koymalıdır. Dönemin başındaki haftalarda anlatılan araştırma yöntemi, literatür taraması ve sunum teknikleri bu son haftalarda öğrencilerin kendi sunumlarında uygulanmış oldu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
