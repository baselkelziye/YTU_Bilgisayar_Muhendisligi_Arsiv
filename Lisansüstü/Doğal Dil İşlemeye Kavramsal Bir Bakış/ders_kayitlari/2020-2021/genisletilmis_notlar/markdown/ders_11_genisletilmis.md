# Ders 11 Genişletilmiş Notu: Seminer Sunumları: Metin Benzerliği, Metin Kümeleme, Twitter Görüş Analizi, Alaycılık Tespiti ve Soyutlayıcı Özetleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu derste konu anlatımı yoktur. Öğrenciler birer makale inceleyip sunar, Prof. Dr. Banu Diri de sunumların arasına girerek sorular sorar ve ek açıklamalar yapar. Sunumlar sıra numarasıyla anılır, sunan öğrencilerin adları yazılmamıştır. Slaytta kalan bazı adlar ve ayrıntılar altyazıda okunamadığı için aynı dersin kısa notundan alınmıştır (o not yazılırken slaytlara bakılmıştı). Bu ayrıntılar bu notta yeniden kareyle doğrulanmamıştır.

## İçindekiler

- 1. 1. Sunum: Anlamsal Metin Benzerliği Analizi için Doküman İşleme
- 2. 2. Sunum: Boyut İndirgeme ve K-means ile Metin Kümeleme
- 3. 3. Sunum: 5G Hakkında Twitter Görüş Analizi ve Konu Modelleme
- 4. 4. Sunum: Öğretim Değerlendirmesi için SMS Metinlerinde Duygu Madenciliği
- 5. 5. Sunum: Duygu Analizinde Alaycılık Tespiti Üzerine Derleme
- 6. 6. Sunum: Soyutlayıcı Özetleme için Derin Pekiştirmeli Model
- 7. Hocanın Özetleme Üzerine Ek Anlatımı
- 8. Türkçe Dil Modelleri Üzerine Soru-Cevap

## 1. 1. Sunum: Anlamsal Metin Benzerliği Analizi için Doküman İşleme

### 1.1 Makale ve Motivasyon

İncelenen makale 2020 tarihli "Document Processing Methods for Semantic Text Similarity Analysis" çalışmasıdır. Metin benzerliği normalde haber öneri sistemleri gibi bilgi çıkarımı uygulamalarında kullanılır: Okuduğunuz yazıya benzer başka bir yazı önerilir. Bu makalenin amacı ise farklıdır. Aynı konuda birden çok doküman vardır ve bunların versiyonlanıp birleştirilmesi (konsolidasyon) gerekir.

Çalışmanın alanı raylı sistemlerdir. İki farklı yönetmeliğe ait kural ve prosedür dokümanları bulunur (biri Digital Railway UK). Bu dokümanların farklı versiyonları elle karşılaştırılıyordu ve bu çok uzun sürüyordu. Yazarlar süreci doğal dil işleme yöntemleriyle otomatikleştirmek ister.

Kullanılan araçlar şunlardır:

- Paralel hesaplama için bir araç seti (kısa nota göre CUDA Toolkit).
- Anaconda ve Jupyter geliştirme ortamı, programlama dili olarak Python.
- Gensim: konu modelleme ve doküman benzerliği yöntemleri içerir.
- NLTK: tokenization için.
- Google News veri seti. Sunum yapan öğrenci bunun neden kullanıldığını anlayamadığını söyler, çünkü çalışılan veri raylı sistem dokümanlarıdır.

### 1.2 Benzerlik Ölçütleri

Metin benzerliği ölçütleri kabaca ikiye ayrılır. Sözcüksel (lexical) ölçütler kelimelerin birebir eşleşip eşleşmediğine bakar. Anlamsal (semantic) ölçütler ise kelimelerin anlamca yakınlığına bakar. Örneğin "Obama Chicago'da konuşma yaptı" ile "Başkan Chicago'da konuşma yaptı" cümleleri kelime olarak farklı, anlam olarak benzerdir. Benzerlik, ortak olmayan veriden de yakalanabilir: Benzersizlik ölçülüp birden çıkarılır.

**Jaccard benzerliği** iki metnin ortak kelime sayısını, iki metindeki kelimelerin birleşim kümesinin büyüklüğüne böler:

$$J(A,B) = \frac{|A \cap B|}{|A \cup B|}$$

Sonuç 0 ile 1 arasındadır. Sıfıra yaklaştıkça metinler benzer değildir.

**Kosinüs benzerliği** iki vektör arasındaki açıyı ölçer. Bu nedenle önce metinlerin vektöre çevrilmesi gerekir. Bu çalışmada word2vec kullanılır. Açı ne kadar küçükse vektörler o kadar benzerdir:

$$\cos\theta = \frac{\vec{a}\cdot\vec{b}}{\|\vec{a}\|\,\|\vec{b}\|}$$

### 1.3 Çalışmanın Akışı

Süreç bir otomasyon çerçevesi olarak çizilmiştir. Adımlar şöyledir:

1. **Ön işleme:** Dokümanlardan biri XML, diğeri Excel formatındadır. İkisi de CSV'ye çevrilip Jupyter'e aktarılır.
2. **Tokenization:** Metin, seçilen bir karaktere göre parçalara bölünür. Nokta, soru işareti ve ünlem seçilirse cümlelere, boşluk seçilirse kelimelere ayrılır. Amaç, bu parçaları sonradan vektöre çevirmektir. Ardından kök bulma (stemming) ve lemmatization yapılır. Makale hangi yöntemi kullandığını yazmaz. Sunum yapan öğrenci Porter algoritmasını tahmin eder, bunun kendi yorumu olduğunu belirtir.
3. **Veri temizleme:** Dokümanların başında madde numaraları vardır. Aynı madde numarasına sahip satırların aynı prosedürü anlattığı gözle fark edilir. Madde numarası olmayan satırlar düzenli ifadelerle (regex) veri setinden çıkarılır.
4. **word2vec:** Kelimeler vektöre çevrilir.
5. **Başlık kontrolü:** Önce yalnız iki başlık karşılaştırılır. Sonuçlar gözle kontrol edilip tutarlı görülünce sürece devam edilir.
6. **Eşik değeri:** Ölçütler "benzer/benzer değil" demez, bir skor verir. Bu yüzden eşik %80 seçilir.
7. **Sorumlu kişiler:** Dokümanlarda geçen sorumlu kişiler ve kaç kez geçtikleri bir sayma fonksiyonuyla bulunur ve benzerlik ölçümünde kullanılır.

### 1.4 Sonuçlar

Makale az sayıda sonuç paylaşır:

- Jaccard tatmin edici değildir. Birbiriyle hiç alakası olmayan 2.5.2.2 ve 2.2.2.5 prosedürleri %89 benzer çıkar. Bu, %80 eşiğine göre yanlış bir "benzer" kararıdır.
- Kosinüs aynı iki prosedür arasında benzerlik bulmaz. Bu doğrudur.
- Aynı numaralı 2.1.1.4 prosedürü için kosinüs benzerliği 1 çıkar. Kosinüs burada Jaccard'dan daha yüksek skor verir.

Yazarların vardığı sonuç, kosinüsün Jaccard'dan daha başarılı olduğudur. Gelecek çalışma olarak yöntemlerin başka dokümanlarda ve başka donanım platformlarında denenebileceği söylenir.

### 1.5 Hocanın Soruları ve Yorumları

**Soru (hoca):** Benzerlik ölçülürken yalnız madde numaralarına mı bakıldı? Madem madde numaraları benzerliği gösteriyor, neden bir regex ile ilk dört haneye bakılmadı?

**Cevap (sunum yapan öğrenci):** Amaç maddelerin içeriğini kontrol etmektir. Madde numarası sınıf bilgisi gibi kullanılır. Böylece içeriğin aynı kalıp kalmadığı ve yöntemin doğru karar verip vermediği görülür. Hoca bu açıklamayı onaylar.

> **Hocanın vurgusu:** "Yani yapılamayacak hiçbir şey yok. Bazı şeyleri gözünüzde çok büyütüyorsunuz. Yeni bir buluş falan beklenmiyor sizden." Bu makale bir uygulamanın makaleye çevrilmiş halidir ve bu çalışmayı öğrenciler de rahatlıkla yapabilir. Önemli olan çalışmanın bir amaca hizmet etmesidir.

Hoca makalenin adını da eleştirir. Adında "semantic" geçer, ama anlamı yakalayan bir yöntem kullanılmaz. Hoca ayrıca derste neden kosinüsü anlattığını hatırlatır: Diğer ölçütlerle uğraşmaya gerek yoktur.

Sunum yapan öğrenci, yeni bir yöntem çıktığında eskileriyle kıyaslayan makalelerin çok yazıldığını söyler. Hoca buna bir koşul ekler:

> **Hocanın vurgusu:** Karşılaştırma aynı veri seti üzerinde yapılmalıdır. Örneğin GloVe ya da BERT çıktığında, daha önce makine öğrenmesiyle çalışılmış veri seti alınır, yeni yaklaşımla denenir ve başarının artıp artmadığına bakılır.

Türkçe üzerine çalışmalar konuşulurken hoca, Türkçede etiketli veri setinin az olduğunu söyler. Kısıtlı kaynaklı diller (low-resource languages) için ayrı sempozyumlar yapılır. Endonezce, Arapça, Türkçe ve Afrika dilleri bu gruptadır.

## 2. 2. Sunum: Boyut İndirgeme ve K-means ile Metin Kümeleme

### 2.1 Konu ve Literatür

İncelenen makale 2018 tarihlidir. Metin kümeleme, benzer içerikteki metinlerin kümelere ayrılmasıdır. Benzer doküman bulma, arama optimizasyonu, öneri sistemleri, kişisel asistanlar ve tekrarlanan içerik tespiti (duplicate content detection) gibi uygulamalarda kullanılır.

Sunumda aktarılan önceki çalışmalar şunlardır:

- BBC haberleri ve BBC spor haberlerinde SVD ile K-means: %95 doğruluk.
- 20 haber grubu verisinde TF-IDF ile bulanık K-means (fuzzy K-means) ve hiyerarşik kümeleme: Bulanık K-means için F-skoru 0,88.
- BBC spor metinlerinde üç boyut indirgeme (Dimension Reduction, DR) tekniği ve K-means: En yüksek doğruluk InfoGain ile elde edilir.

### 2.2 Veri Seti

Kaggle'dan alınan yaklaşık 20.000 haber metni ve 20 gruptan oluşan veri seti kullanılır. Hoca bu verinin "20 Newsgroups" adıyla aranabileceğini söyler. Bazı gruplar birbirine yakındır, bazıları hiç ilişkili değildir (Hristiyanlık ve satılık ilanlar gibi). Gruplar benzerliklerine göre üst bölümlere toplanır: spor, bilim, sağlık, din, politika, otomobil, e-ticaret.

### 2.3 Akış ve Ön İşleme

Akış şöyledir: ön işleme, TF-IDF vektörleştirme, iki boyut indirgeme yöntemi, K-means ile kümeleme, performans ölçümü.

Ön işlemenin amacı veriden gürültüyü çıkarmaktır. Bu çalışmada iki işlem yapılır. Metin token'lara ayrılır, ardından İngilizce durak kelimeler (stop words) çıkarılır. Durak kelimeler dilde sık geçen ve metnin kümelenmesine katkı vermeyen kelimelerdir.

### 2.4 TF-IDF ve Paydadaki +1

Terim frekansı, kelimenin dokümandaki görülme sayısının dokümandaki toplam kelime sayısına oranıdır. Ters doküman frekansı ise çok sık geçen kelimelerin etkisini azaltır:

$$\mathrm{tf}(t,d) = \frac{f_{t,d}}{\sum_{t'} f_{t',d}}, \qquad \mathrm{idf}(t) = \log\frac{N}{1 + \mathrm{df}(t)}$$

Burada $N$ toplam doküman sayısı, $\mathrm{df}(t)$ terimin geçtiği doküman sayısıdır.

Hoca burada araya girer. Derste IDF'i $\log(N/\mathrm{df})$ olarak göstermiştir ve paydadaki $+1$ orada yoktur. Hiçbir dokümanda geçmeyen bir terim gelebilir ve o zaman payda sıfır olur. Hoca bunu sözlü olarak söylemesi gerektiğini belirtir.

### 2.5 Neden Boyut İndirgeme

TF-IDF matrisi çok seyrektir (sparse). Bu yüzden eğitim hem zaman hem bellek açısından pahalıdır. Çalışmada iki boyut indirgeme yöntemi denenir.

**SVD (Singular Value Decomposition)** derste LSI konusunda görülmüştür. Matris üç matrisin çarpımına ayrılır:

$$A = U\,\Sigma\,V^{T}$$

- $A$: $m \times n$ boyutlu doküman-terim matrisi ($m$ doküman, $n$ terim).
- $U$: $m \times r$ boyutlu. Her dokümanın konseptlerle benzerliğini gösterir. Dikgen (orthogonal) bir matristir, yani $U^T U = I$.
- $\Sigma$: $r \times r$ köşegen matris. Köşegendeki değerler konseptlerin gücünü gösterir, pozitiftir ve büyükten küçüğe sıralıdır.
- $V$: $n \times r$ boyutlu. Terim-konsept benzerliğini gösterir.

$r$ konsept sayısıdır ve terim sayısından küçüktür. Sunumdaki SVD animasyonu için hoca, LSI'da anlatılanla farkı olmadığını söyler.

**NMF (Non-negative Matrix Factorization)**, TF-IDF matrisini negatif olmayan iki matrisin çarpımı olarak yazar:

$$A \approx U\,V^{T}, \qquad U \ge 0,\; V \ge 0$$

$U$, terimlerin kümelere ait olma derecesini; $V$, dokümanların kümelere ait olma derecesini verir. Bir doküman bir kümeye aitse o kümedeki değeri en büyük olur, diğerleri sıfıra yaklaşır. Hoca, NMF'nin LSI'daki gibi bir matris üzerinde işlem yapıp boyut indirgeyen bir yöntem olduğunu belirtir. U ve V'nin hesaplanma adımlarının sunumda sözle anlatılmasını gerekli bulmaz.

### 2.6 K-means

K-means iki aşamadan oluşur: atama ve güncelleme.

1. $K$ sayısı belirlenir.
2. Küme merkezleri rastgele seçilir.
3. Her örneğin merkezlere Öklid uzaklığı hesaplanır ve örnek en yakın kümeye atanır.
4. Küme merkezleri güncellenir. Süreç, atamalar değişmeyene kadar sürer.

### 2.7 Değerlendirme Ölçütleri ve Sonuç

Dört ölçüt kullanılır:

- **Homojenlik (homogeneity):** Her küme yalnız tek bir sınıfın örneklerini içeriyor mu? Değer 0 ile 1 arasındadır, mükemmel kümelemede 1 olur.
- **Tamlık (completeness):** Aynı sınıfın örnekleri aynı kümede mi?
- **Düzeltilmiş Rand indeksi (ARI):** Bütün örnek çiftlerini sayar. Tahmin edilen ve gerçek kümelemede aynı ya da farklı kümeye atanan çiftlere bakarak benzerlik hesaplar.
- **Düzeltilmiş karşılıklı bilgi (AMI):** Karşılıklı bilgiye dayalı düzeltilmiş ölçüttür.

<!-- BELİRSİZ: Homojenlik ve tamlık formülleri ile sayısal sonuç tablosu slaytta kaldı, altyazıda okunmuyor. -->

Slaytta "NMF sonuçları SVD ve K-means'ten daha iyi" yazar. Hoca bu cümleye itiraz eder:

**Soru (hoca):** NMF ile SVD aynı işi (boyut indirgeme) yapar, K-means ise kümeleme yapar. "SVD ve K-means'ten daha iyi" denince ne kastediliyor?

**Cevap (sunum yapan öğrenci):** Karşılaştırılan üç durum vardır: yalnız TF-IDF ile K-means, SVD + K-means ve NMF + K-means. Makaledeki ifade yanlış kurulmuştur. Doğru sonuç, NMF + K-means'in diğer ikisinden daha iyi olduğudur.

## 3. 3. Sunum: 5G Hakkında Twitter Görüş Analizi ve Konu Modelleme

### 3.1 Motivasyon

Twitter, insanların gündemdeki konular hakkındaki görüşlerini paylaştığı bir platformdur. Bu yüzden doğal dil işleme için büyük bir veri kaynağıdır. Öte yandan çok fazla yanlış bilgi de dolaşır ve bot hesap tespiti gibi çalışmalar yapılır. Benzer görüş analizi çalışmaları Black Friday, havalimanı hizmet kalitesi ve 2012 ABD başkanlık seçimleri üzerine yapılmıştır.

### 3.2 Yöntem

Çalışma üç aşamalıdır:

1. Tweet'ler toplanır ve ön işlemden geçirilir.
2. Google Cloud Natural Language API ile tweet'ler etiketlenir. Sonra Google AutoML Natural Language ile bir model eğitilir ve test edilir.
3. LDA ile çok geçen kelimeler ve konular bulunur.

**Soru (hoca):** Buradaki LDA hangisi? Linear Discriminant Analysis mi?

**Cevap (sunum yapan öğrenci):** Latent Dirichlet Allocation.

> **Hocanın vurgusu:** Kısaltmaları açın. LDA hem Linear Discriminant Analysis hem Latent Dirichlet Allocation olabilir, sunumda hangisi olduğu belirtilmelidir.

Hoca, LDA'nın zaten bir konu tespit modeli olduğunu söyler. Öğrenci, LDA'nın kelime grupları verdiğini ama üst kategori adını vermediğini, bu yüzden kategorilerin sonradan atandığını açıklar. Hoca bunu onaylar.

### 3.3 Veri Toplama ve Temizleme

"#5G" etiketli 46.559 tweet toplanır. Çalışma sırasında tweet karakter sınırı 140'tan 280'e çıkmıştır. Kullanılan kütüphane hâlâ 140 gösterdiği için kütüphanede değişiklik yapılır. Temizleme şöyle yapılır:

- Profil resmi ve arka plan resmi olmayan hesaplar elenir.
- Tekrarlanan tweet'ler ve yanıtlar çıkarılır.
- Konum bilgisi ülke düzeyine indirilir ("California, USA" yerine "USA").
- Noktalama işaretleri, parantezler ve tırnaklar silinir.
- Yalnız İngilizce ve 80 karakterden uzun tweet'ler alınır.

Sonuçta 8.102 tweet kalır. Bu, ilk toplanan tweet'lerin yaklaşık %17,4'üdür (ara adım eklendi).

Sunum yapan öğrenci kendi deneyimini de aktarır: Python'daki GetOldTweets kütüphanesi Eylül 2020'den beri çalışmaz. Twitter geliştirici hesabı öğrenciler için 1-2 günde onaylanır. Tweepy kütüphanesiyle istenen etiket ve tarih aralığında tweet çekilebilir.

### 3.4 Duygu Analizi

Natural Language API iki değer döndürür:

- **Skor (score):** $-1$ ile $+1$ arasındadır. $-1$ çok olumsuz, $+1$ çok olumlu demektir.
- **Büyüklük (magnitude):** Metnin ne kadar duygu içerdiğini gösterir. Metin uzadıkça genelde artar.

Skorlar $-1$, $0$ ve $1$ etiketlerine çevrilir. Hangi aralığın hangi etikete gittiği makalede yazmaz. Veri %80 eğitim, %10 doğrulama, %10 test olarak bölünür ve AutoML ile model eğitilir. Makale, modelde hangi yöntemin kullanıldığını da söylemez.

### 3.5 Konu Tespiti

5'ten az geçen kelimeler ve durak kelimeler çıkarılır. Kelime ağırlıkları TF-IDF ile hesaplanır ve LDA'nın çevrim içi (online) sürümüyle çok konuşulan kelimeler çıkarılır. Konular elle ve Natural Language API'nin içerik sınıflandırmasıyla kategorilere yerleştirilir.

### 3.6 Sonuçlar ve Hocanın Yorumları

Veri dengesizdir: yaklaşık %64 olumlu, %25 olumsuz, %10 nötr (örneğin 5214 olumlu, 905 nötr). Olumlu sınıfta başarı yüksektir. Nötr sınıfta ise duyarlılık (recall), kesinliğin (precision) çok altındadır; aradaki fark öğrenciye göre %30-35'tir.

$$\text{Precision} = \frac{TP}{TP+FP}, \qquad \text{Recall} = \frac{TP}{TP+FN}$$

<!-- BELİRSİZ: Sınıf bazlı kesinlik ve duyarlılık tablosu slaytta kaldı. Altyazıdaki "184.3" değeri okunamıyor. -->

Öğrenci, nötr sınıftaki farkın etiketleme eşiklerinden kaynaklanabileceğini düşünür. Hoca sınıf sayılarına dikkat çeker:

> **Hocanın vurgusu:** Pozitif örnek çok fazlaysa "pozitif" demek kolaydır. Dengeli bir veri setinde (örneğin her sınıftan 5000 örnek) sonuçlar daha anlamlı olur.

Öğrenci eşik yorumunu sürdürünce hoca, makalede yazmayan bir konuda tahmin yürütmek yerine raporlanan sonuçlara odaklanılmasını ister: "Adamların yaptığı çalışmayı tartışmayalım."

Konu tarafında olumlu tweet'lerde teknoloji ilgisi öne çıkar ve Huawei sık geçer. Sağlık kaygılarında en sık kelime "radiation"dır. Çalışmanın vardığı sonuç, kamuoyunda 5G'nin radyasyon kaynaklı kanser gibi hastalıklara yol açacağı korkusunun bulunduğu ve firmaların bu kaygıları gidermeye çalışması gerektiğidir. Yöntem, gündemdeki bir konuda kamuoyunun ne düşündüğünü anlamak için kullanılabilir.

## 4. 4. Sunum: Öğretim Değerlendirmesi için SMS Metinlerinde Duygu Madenciliği

### 4.1 Altyazı Hakkında Not

Bu sunum İngilizce yapılmıştır. Altyazının büyük bölümü döngüye girmiş ve bozulmuştur. Aşağıdaki anlatım yalnız okunabilen kısımlardan ve kısa nottaki slayt bilgilerinden kurulmuştur.

<!-- BELİRSİZ: 01:03:58-01:11:40, 01:13:04-01:15:26, 01:16:38-01:18:33, 01:19:26-01:20:38, 01:21:58-01:22:58 ve 01:23:27-01:27:49 aralıklarında altyazı anlaşılmıyor. -->

### 4.2 Problem

İncelenen makale "Mining Sentiments in SMS Texts for Teaching Evaluation" çalışmasıdır. Sunum yapan öğrenci bu makaleyi seçme nedenini, herkesin Twitter ve Facebook üzerine çalışması olarak açıklar. Öğrenci geri bildirimi genelde Likert ölçekli formlarla alınır. Bu çalışmada ise geri bildirim 160 karakterle sınırlı SMS metinleriyle alınır.

### 4.3 Keşifsel Veri Analizi

Analiz kavram (concept) ya da kategori (category) düzeyinde yapılır. Bir kategori birden çok kavram içerebilir. Örneğin "lecture" bir kategoridir ve ders anlatımıyla ilgili farklı kelimeler onun altında toplanır. Her SMS bir doküman olarak ele alınır. Analizde 118 kavram alınır, seyrek geçenler gösterilmez.

<!-- BELİRSİZ: 118 ve 44 sayılarının SMS mi kavram mı olduğu ve "lecture"ın tüm dokümanlarda %100 geçtiği örnek, bozuk altyazı yüzünden net değil. -->

Kavramlar arasındaki birlikte geçme ilişkileri bir ağ olarak çizilir. Çizgi kalınlığı ilişkinin gücünü gösterir.

<!-- BELİRSİZ: Öğrenci en kalın çizgiyi "Examples ve Feedback" için gösterip bunların çoğu zaman birlikte geçmediğini söylüyor. Şekil slaytta kaldığı için bu ifade doğrulanamadı. -->

### 4.4 Modeller

Üç model kullanılır:

- **Temel model (base model):** Tüm SMS derlemi yazım hataları düzeltilmeden analiz edilir.
- **Düzeltilmiş model (corrected model):** Yazım hatalı kelimeler aynı kavram altında toplanır.
- **Duygu modeli (sentiment model):** Düzeltilmiş modele duygu madenciliği eklenir. Kavramlar olumlu ya da olumsuz diye etiketlenir.

Sonra metin bağlantı analizi (text link analysis) ile olumlu kavramlarla diğer kavramlar arasındaki ilişkiler ağ olarak çizilir. Örneğin "lecture" kavramının neredeyse bütün kelimelerle bağlantısı vardır. "Pace" kavramı da olumlu niteleyicilerle bağlantılıdır.

### 4.5 Eksiklik Sorunu

SMS'lerde iki tür eksiklik vardır. Biri 160 karakter sınırından, diğeri kısaltma ve sembollerden ("kk", "ok", "okkk" gibi) kaynaklanır. Semboller ayrıştırılıp anlamlandırıldıkça çıkarılan kavram sayısının arttığı ve SMS'lerin yapısının daha iyi anlaşıldığı söylenir. Sunumda 151 ve 164 kavram sayıları ile 24 tür (type) sayısı verilir.

Sonuç olarak SMS ile öğretim değerlendirmesinin formlara alternatif olabileceği, geliştirilebileceği ya da başka modüllerle birleştirilebileceği söylenir.

### 4.6 Hocanın Yorumları

Hoca bazı yerlerde koptuğunu söyler ve öğrenciden çalışmanın katkısını iki üç Türkçe cümleyle özetlemesini ister. Katkı, öğrenciden form yerine serbest metin (SMS) ile geri bildirim almaktır. Hoca bunu kendi uygulamasına bağlar: Ders sonunda öğrencilerden e-posta ile yorum ister ve olumlu-olumsuz yanlarını çıkarmaya çalışır.

Hoca ağ çiziminin güzel olduğunu söyler. Hangi aracın kullanıldığını sorar, ama makalede yazmaz. Makalede matematik de azdır. Yazarların Singapur'da bir işletme okulundan olduğu, bilgisayar bilimi kökenli olmadığı görülür.

Hoca buradan bir proje fikri çıkarır: Bölümün bir sosyal medya hesabında her ders için bir etiket (hashtag) açılır, öğrenciler yorum yazar, arka plandaki bir uygulama bu yorumların duygu analizini yapar.

## 5. 5. Sunum: Duygu Analizinde Alaycılık Tespiti Üzerine Derleme

### 5.1 Makalenin Niteliği

İncelenen 2018 tarihli makale, İngilizce metinler üzerine bir derlemedir (survey). Kendi deneyi yoktur, çok sayıda çalışmanın yöntemlerini ve sonuçlarını karşılaştırır. Sunum yapan öğrenci makalenin yüzeysel olduğunu da söyler.

### 5.2 Alaycılık Nedir

Alaycılık (sarcasm), söylenenle kastedilenin çeliştiği, genelde iğneleyici bir ifadedir. Sunumdaki örnekler şunlardır: Kötü giyinmiş birine "Bugün ne kadar da güzel giyinmişsin" demek. Hoca, sıkıcı bir toplantı için "Zevkten dört köşe olduk" örneğini ekler: Gerçekte olan durumun tam tersi söylenir.

Hoca sohbet penceresine daha uygun bulduğu örnekler de yazar:

- "Sınava geç kaldım, aferin bana."
- "Ben böyle uslu bir çocuk görmedim." (Aslında çok yaramaz bir çocuktan söz edilir.)
- "Ay ne kadar çirkin bir bebek, yerim ben bunu." (Sevilen bir şeye ters ifadeyle yaklaşılır.)
- "Baya ucuz bir çek etmiş, kredi çekip aldım sonunda."
- "Olağanüstü manzaraya bak, her yer çöp dolu."

Makaleye göre iğneleyici söz üçe ayrılır ve bunlar birbirinden farklıdır:

- **İroni (irony):** Beklenenin tersinin olması durumunu anlatır.
- **Hiciv (satire):** Daha çok eleştiri amaçlıdır.
- **Alay (sarcasm):** İğneleyici sözdür. Mimiklerden anlamak daha kolaydır.

Sohbette "Kızım sana söylüyorum, gelinim sen anla" atasözünün hangi türe girdiği tartışılır. İğneleme ve ironi yorumları yapılır, net bir sonuca varılmaz.

### 5.3 Neden Zor

Duygu analizi, yazarın görüşünü ve konuya tutumunu (olumlu mu, olumsuz mu) belirleme işidir. Bu alanın genel zorlukları varlık tanıma, anafora çözümleme, ayrıştırma ve alaycılık tespitidir. Alaycılıkta söylenen ile bağlam çelişir. Yüz yüze konuşmada mimikler, sesli konuşmada ses tonu ipucu verir. Metinde bu ipuçları yoktur.

### 5.4 Metindeki İpuçları

- Büyük harf kullanımı, aşırı ünlem ve noktalama işaretleri, emojiler, abartılı ifadeler.
- Yıldız puanı ile yorumun çelişmesi: Düşük yıldız verilip övgü dolu yorum yazılması.
- Olumlu bir cümleden sonra olumsuz bir cümle gelmesi ya da tersi. Bir cümlede ikilem olması.
- Kötü ve daha kötü durumlar arasında karşılaştırma yapılması.
- Argo kelimeler, olumlu ve olumsuz bağlaçlar.

**Soru (hoca):** Amazon'daki yorumlarla yıldız puanlarının alaycılıkla nasıl bir ilişkisi var?

**Cevap (sunum yapan öğrenci):** Yorum güzel bir şey söylüyor gibi görünür ama derecelendirmede bir yıldız verilir. Söylenenle kastedilen arasındaki bu zıtlık, tespitte avantaj sağlar. "Olağanüstü manzaraya bak, her yer çöp dolu" örneği de olumlu cümleden sonra olumsuz cümle gelmesi özelliğine uyar.

### 5.5 Literatürden Örnekler

Derlemede anılan çalışmalardan bazıları şunlardır:

- Sırpça WordNet'ten zıt anlamlı kelime çiftleri üretilir.
- Duygu kelimelerinin oranı hesaplanıp bir eşiğe göre olumlu, olumsuz, nötr sınıflandırması yapılır.
- Kelime yoğunluğu 1-5 arasında puanlanır.
- WordNet ile eş anlamlı yapısı kurulur.
- Bir çalışmada metinler word2vec ile vektöre çevrilir, K-means uygulanır ve emojiler yaklaşık 8 duygu grubuna ayrılır.
- Bir çalışmada 8 temel duygu belirtilir: sevinç, iğrenme, güven, sürpriz, öfke, beklenti, üzüntü, korku.
- MapReduce ile büyük veride doğal dil işleme yapılır ve çalışma süresi kısalır.

### 5.6 Veri, Ön İşleme ve Özellikler

En çok kullanılan veri Twitter'dır (#sarcasm etiketi ile), sonra Amazon ürün yorumları gelir. Amazon verisinde ürün açıklaması, resim, marka, fiyat ve yıldız puanları da kullanılır.

Ön işleme adımları derste görülenlerle aynıdır: tokenization, durak kelime çıkarma, kök bulma ve lemmatization, sözcük türü etiketleme (POS tagging). Çok fazla övgü kelimesi geçmesi alaycılığa dair bir ipucu olabilir.

Özellik çıkarımında terim sıklığı, özellik varlığı, TF-IDF, ağırlıklı TF-IDF, delta TF-IDF, n-gram ve word2vec kullanılır.

### 5.7 Sınıflandırıcılar ve Kural Tabanlı Yöntemler

Kullanılan sınıflandırıcılar destek vektör makineleri (doğrusal olmayan SVM dahil), Naive Bayes, AdaBoost, Gradient Boosting, rastgele orman, karar ağacı ve maksimum entropidir. Öğrenci AdaBoost'u zayıf sınıflandırıcıları birleştirip güçlü bir sınıflandırıcı oluşturan bir meta-algoritma olarak tanımlar. Sonuçlar doğruluk, kesinlik, duyarlılık ve F-skoru ile ölçülür. Doğrulamada 5 ve 10 katlı çapraz doğrulama kullanılır. Emojilerin anlamını çıkarmak için K-means ($K=5$) kullanılan bir çalışma da vardır.

Kural tabanlı yöntemler şöyle gruplanır:

- **Sözcüksel:** İsim, fiil, sıfat gibi sözcüksel özellikler ve n-gram'lar.
- **Anlamsal:** Cümlenin ne demek istediğini anlamaya çalışır.
- **Sözdizimsel:** Cümlenin dile uygun olup olmadığını kontrol eder.
- **Edimsel (pragmatic):** Noktalama işaretlerinin aşırı kullanımı.
- **Bürünsel (prosodic):** Konuşmanın üslubu ve tonu.
- **Deyimsel (idiosyncratic):** Deyimsel ifadeler kalıp olarak alınır.

### 5.8 Sonuçlardan Örnekler

| Çalışma | Yöntem | Sonuç |
| :--- | :--- | :--- |
| SVM | Olumsuzluk + ünlem özellikleri | %54,1 doğruluk |
| Rastgele orman ve SVM | Bir makalede karşılaştırma | En iyi doğruluk rastgele ormanda; F1 0,68 SVM'de |
| Önerilen bir yöntem | Ayrıntısı verilmemiş | %86,1 doğruluk, %68 hassasiyet |
| Denetimsiz öğrenme | Kelime kullanarak | %68 doğruluk |
| Denetimsiz öğrenme | Emoji kullanarak | %78 doğruluk |
| Denetimli öğrenme | Belirtilmemiş | %81 doğruluk |
| Naive Bayes | Unigram / bigram | %79 / %64 doğruluk |
| Ayrıştırma tabanlı sözlük | Kesinlik, duyarlılık, F | 0,89; 0,81; 0,84 |
| Ünlem kelimeleri | Kesinlik, duyarlılık, F | 0,85; 0,96; 0,90 |
| Bir makale | Emojili / emojisiz | 0,78 / 0,61 doğruluk |

Bu tablo notta derli toplu olsun diye hazırlanmıştır; değerler sunumda sırayla okunmuştur. Son satır emojinin alaycılık tespitinde güçlü bir ipucu olduğunu gösterir.

### 5.9 Hocanın Geri Bildirimi: Survey Kullanımı ve Sunum Tekniği

> **Hocanın vurgusu:** Yeni bir konuya girince ilk iş literatür çalışmasıdır. Bunu en yeniden en eskiye doğru yapın ve o alanda survey olup olmadığına bakın. Survey, bir konudaki çalışmaları belirli başlıklar altında toplar.

Hoca bunun nasıl yayına dönüşebileceğini de anlatır. Sarkazm konusunda en son survey 2018'de yapılmışsa ve sonraki yıllarda çok yayın çıktıysa, o survey referans alınıp üzerine eklenerek hem kendi literatür taramanız hem de bir yayın çıkabilir.

Sunumun kendisine gelince, hoca öğrencinin sürekli metin okuduğunu ve bir noktadan sonra kendini kapattığını söyler. Bu uyarının yalnız o öğrenci için olmadığını, bütün sınıfa referans olduğunu özellikle belirtir.

> **Hocanın vurgusu:** Çok sayıda çalışma anlatırken tablo yapın: referansın yılı, kullanılan özellikler, sonuçlar. Böylece hem daha rahat anlatırsınız hem karşılaştırma yapabilirsiniz. Soru sorulduğunda slaytlarda ileri geri gitmez, tabloya bakarsınız. "En yüksek başarıyı alanlar hangi özellikleri kullanmış?" sorusu ancak böyle yanıtlanır. Doktora izleme sınavında ya da başka bir yerde dinleyiciyi yazılı metinlere boğmayın. Dinleyiciyi sunuma bağlamanız gerekir.

## 6. 6. Sunum: Soyutlayıcı Özetleme için Derin Pekiştirmeli Model

### 6.1 Metin Özetleme

İncelenen makale 2018'de bir konferansta yayımlanmıştır. Metin özetleme, bir belgeyi alıp onun yerine geçen ve en önemli içeriğini taşıyan daha kısa bir metin üretme sürecidir. Haber ve rapor özetleme gibi alanlarda kullanılır. İki tür vardır:

- **Çıkarımsal (extractive):** Metindeki önemli cümleler istatistiksel ve dilsel özelliklere göre seçilir. Yeni cümle üretilmez. Girdi bir ya da birden çok belge olabilir.
- **Soyutlayıcı (abstractive):** Kritik bilgi alınıp yorumlanır ve özet kendi ürettiği cümlelerle yazılır.

### 6.2 Önceki Çalışmaların Sorunu

Dikkat (attention) tabanlı kodlayıcı-kod çözücü (encoder-decoder) modeller, kısa girdilerde yüksek ROUGE skorlarıyla soyutlayıcı özet üretebilmiştir. Ancak bu sistemler bir iki cümlelik kısa girdileri özetler. CNN/Daily Mail verisinde 800 token'lık girdi ve 100 token'lık çok cümleli özet denendiğinde model, çoğunlukla tekrar eden ifadelerden oluşan doğal olmayan özetler üretmiştir. Bu makale tam olarak bu sorunu çözmeye çalışır. Yazarlar, modelin soyutlayıcı özetleme için ilk uçtan uca model olduğunu ve New York Times verisinin bu iş için ilk kez kullanıldığını öne sürer.

### 6.3 Önerilen Model

Kodlayıcı çift yönlü (bidirectional) LSTM, kod çözücü tek yönlü LSTM'dir. Girdi ve çıktı gömme (embedding) matrisleri ortaktır. Modele eklenen parçalar şunlardır:

- **Zamansal iç dikkat (intra-temporal attention):** Önceki adımlarda yüksek dikkat alan girdi token'ları cezalandırılır. Böylece model aynı yerlere tekrar tekrar bakmaz.
- **Kod çözücü iç dikkati (intra-decoder attention):** Uzun dizilerde kod çözücü yine tekrar üretebilir. Bu yüzden daha önce ürettiği çıktıya da bakar ve her adımda yeni bir bağlam vektörü hesaplar.
- **Token üretme ve işaretçi (pointer):** Model ya sözlükten kelime üretir (softmax) ya da girdideki nadir ve görülmemiş ifadeleri kopyalar. Bir anahtar (switch) fonksiyonu hangisinin kullanılacağına karar verir.
- **Ağırlık paylaşımı:** Gömme matrisi ile token üretme katmanı arasında ağırlık paylaşılır. Böylece üretim katmanı gömmelerdeki sözdizimsel ve anlamsal bilgiyi kullanır.
- **Trigram engeli:** Yazarların gözlemine göre gerçek özetlerde aynı trigram neredeyse hiç iki kez geçmez. Bu yüzden test sırasında kod çözücünün aynı trigramı ikinci kez üretmesi engellenir.

### 6.4 Eğitim

Kod çözücü eğitiminde en yaygın yöntem öğretmen zorlamasıdır (teacher forcing). Bu yöntem her adımda maksimum olabilirlik kaybını en aza indirir. Ancak bu, ROUGE gibi ayrık ölçütlerde her zaman iyi sonuç vermez. Bunun iki nedeni vardır: maruz kalma yanlılığı (exposure bias) ve geçerli olabilecek çok sayıda özet bulunması. ROUGE bu çeşitliliği hesaba katabilir, maksimum olabilirlik kaybı katamaz.

> **Ek bilgi (derste anlatılmadı):** Maruz kalma yanlılığı şu demektir: Eğitimde kod çözücüye her adımda gerçek önceki kelime verilir. Testte ise kendi ürettiği kelime verilir. Model, eğitimde görmediği bu durumda hata yapınca hatalar birikebilir.

Çözüm olarak kendi kendini eleştiren politika gradyanı (self-critical policy gradient) ile pekiştirmeli öğrenme kullanılır ve ayrık bir ölçüt doğrudan en büyüklenir. Her eğitim yinelemesinde iki çıkış dizisi üretilir ve bir ödül fonksiyonuyla referans özetle karşılaştırılır.

<!-- BELİRSİZ: Altyazıda yalnız açgözlü (greedy) aramayla üretilen dizi anlatılıyor, ikinci dizi ve amaç fonksiyonunun formülü slaytta kaldı. -->

Yalnız ROUGE'u en büyüklemek okunabilirliği garanti etmez. ROUGE n-gram örtüşmesini ölçer, okunabilirliği ise dil modeli daha iyi sağlar. Bu yüzden maksimum olabilirlik kaybı ile pekiştirmeli öğrenme kaybı birleştirilerek karma (hybrid) bir amaç fonksiyonu kurulur.

### 6.5 Veri Setleri

- **CNN/Daily Mail:** 287.113 eğitim, 13.368 doğrulama, 11.490 test örneği. Girdi 800, çıktı 100 token ile sınırlanır. Ortalama uzunluklar 632 ve 53 token olur.
- **New York Times:** 1996-2007 arasında yayımlanmış geniş bir makale koleksiyonu. Özetleri daha çeşitli, daha kısa ve daha soyuttur.

### 6.6 Sonuçlar

İç dikkat skorları artırır (37,86'dan yaklaşık 38'e). Pekiştirmeli öğrenme ile iç dikkat birlikte skoru biraz daha yükseltir. New York Times verisinde yalnız pekiştirmeli öğrenme ROUGE-1 ve ROUGE-L'de en yüksek sonucu verir, karma model ise ROUGE-2'de en yükseğe ulaşır.

<!-- BELİRSİZ: Skor tabloları slaytta kaldı. Altyazıdaki 37,86, 38 ve "ROUGE-2 15,82" değerlerinin hangi satıra ait olduğu tam okunamıyor. -->

Yazarlar ölçütlerle yetinmez, 100 örneği beş kişiye de değerlendirtir. Örnek bir kayıtta pekiştirmeli öğrenme en yüksek ROUGE skorunu alır. İnsan değerlendirmesinde ise karma model en okunabilir ve en ilgili özetleri üretir. Maksimum olabilirlik modelinin çıktısında en az tutarsız kelime bulunur. Sonuç olarak ROUGE'un yararlı ama kısıtlı bir ölçüt olduğu, uzun özetleri eniyilemek için tek ölçüt olmak zorunda olmadığı gösterilir.

Sunum yapan öğrenci, makalede kendisinin uygulamak istese eksik kalacak çok boşluk gördüğünü söyler. Çalışmanın bir tezin küçük başlıklarının kısaltılıp konferansa gönderilmesi gibi olduğunu düşündüğünü de ekler.

## 7. Hocanın Özetleme Üzerine Ek Anlatımı

Hoca sunumdan sonra özetleme alanının gelişimini anlatır. Derin öğrenme hayatımıza girene kadar genelde hep çıkarımsal özetleme yapılıyordu. Soru şuydu: Dokümandan hangi cümleleri seçmeliyim ki okuyan kişi dokümanı okumuş gibi olsun? Bunun için özellikler ve kurallar çıkarılıyor, bunlara sahip cümleler seçiliyordu.

Sonra çoklu doküman özetlemeye geçildi. Diyelim ki 10 gazetede COVID ile ilgili aynı haber çıktı ve aralarında ufak farklar var. Cümleler seçilirken aynı anlamı veren cümleler farklı haberlerden gelebilir. Bu yüzden ek bir adımla anlamca benzer cümlelerden yalnız biri alınır. Hoca, ilk sunumda geçen kosinüs benzerliğinin burada kullanıldığını hatırlatır.

Bu sistemlerin başarısı genelde insanlara okutularak ölçülür: Metin bu, özet bu; böyle bir özet okuyunca ne kadar tatmin olursun? Gelen puanlarla sistemin başarısı belirlenir.

Soyutlayıcı özetleme ise çok daha zordur. Cümle seçilmez, örneğin iki cümleden tek bir cümle üretilir. Bunu normal makine öğrenmesi ya da kural tabanlı tekniklerle yapmak zor olduğu için başarılı çalışmalar çıkmıyordu. Derin öğrenme ve özellikle dikkat mekanizmasıyla yapılmaya başlandı. CNN/Daily Mail ve New York Times gibi verilerde özgün metinlerle özetleri birlikte vardır. Bunlar modele verilir ve model, hangi kelimelerin birlikte kullanıldığını ve özetin nasıl kurulduğunu öğrenir.

> **Hocanın vurgusu:** ROUGE, özetlemede kullanılan bir ölçüttür ve hesaplaması F-skoru kadar kolay değildir. Bu ölçütte %80-90 gibi başarılara rastlanmaz. Özellikle derin öğrenme kısmı, bir projenin içinde yer almadan havada kalır.

## 8. Türkçe Dil Modelleri Üzerine Soru-Cevap

Bir öğrenci iş yerinde konuşmadan metne (speech-to-text) sistemi üzerinde çalışmaktadır. Sistemin akustik model ve dil modeli olmak üzere iki tarafı vardır. Küçük alanlarda n-gram dil modeli yeterlidir, çünkü veri azdır ve fazla bellek gerektirmez. Genel Türkçe için ise uçtan uca yaklaşımlar araştırılmaktadır.

**Soru:** Uçtan uca dil modelleri Türkçeye uygun görünüyor, ama çoğu çalışma İngilizce için yapılmış. Türkçe için bu tarz çalışmalar var mı?

**Cevap:** Türkçe çalışmalara fazla kimse girmiyor. Hoca bakılabilecek akademisyenleri sayar:

- Boğaziçi Üniversitesi'nde Murat Saraçlar, ses ve Türkçe üzerine çalışır.
- İTÜ'de Gülşen Hoca dil modelleri üzerine çalışır, sesle pek ilgisi yoktur.
- Koç Üniversitesi'nde Deniz Yüret uzun süre İngilizce üzerine çalışmış, Türkçeye yeni girmiştir.

Türkçe üzerine yayın yapmanın zorluğunu da açıklar. Hakem "Sistemini neyle karşılaştırdın?" diye sorar, ama Türkçede karşılaştırılacak çalışma azdır. İngilizce ile aynı dil ailesinden olmadığımız için İngilizce sonuçlarla da karşılaştırma yapılamaz.

**Soru:** Bir kelime yanlış yazılsa ya da yanlış söylense bile (örneğin konuşma dilindeki bir biçim), önceki cümleden yola çıkarak doğru biçime nasıl çevrilebilir?

**Cevap:** Hoca FastText'i önerir. FastText, kelimenin karakter n-gram'larından gömme çıkarır. Böylece konuşma dilindeki "geliyom" biçiminin gömmesi uzayda "geliyorum" kelimesine yakın düşer ve ikisi eşleştirilebilir. Önerilen deneme şöyledir:

1. Türkçe için önceden eğitilmiş gömmeler alınır.
2. Yanlış yazılmış kelimelerin gömmeleri çıkarılır.
3. Bu gömmelerin doğru kelimelere uzaklıklarına bakılır.
4. En yakın kelime gerçekten olması gereken kelimeyse yöntem kullanılabilir.

Öğrenci şu an bir sözlük kullandığını anlatır: Doğru kelime anahtar, söyleyiş varyasyonları ise o anahtara işaret eden kayıtlardır. Bu yöntem yalnız düzgün metinlerde çalışır.

Hoca bir seçenek daha önerir: Arama motorlarının "Bunu mu demek istediniz?" yaklaşımı. Kelimenin I/İ gibi Türkçe karakter varyasyonlarıyla arama yapılır, en sık çıkan biçim doğru kabul edilir. Ancak bu yalnız Türkçe karakter hatalarında işe yarar. "Geliyom" gibi ağza dayalı biçimlerde tutmaz, onlar için kelime vektörlerinin yakınlığına bakmak daha uygundur.

## Dersin Toparlaması

Bu derste altı makale üzerinden doğal dil işlemenin farklı uygulamaları görüldü: kosinüs ve Jaccard ile doküman benzerliği, boyut indirgeme ve K-means ile kümeleme, Twitter'da duygu analizi ve LDA ile konu tespiti, SMS'lerde duygu madenciliği, alaycılık tespiti ve soyutlayıcı özetleme. Bu çalışmalar önceki derslerde görülen TF-IDF, SVD, LSI, n-gram, word2vec ve başarı ölçütlerinin pratikte nasıl kullanıldığını gösterir.

Hocanın sunumlar boyunca verdiği geri bildirimler ayrıca bir araştırma yöntemi dersi niteliğindedir: Makale adı içerikle uyumlu olmalı, karşılaştırma aynı veri setinde yapılmalı, veri seti dengesi gözetilmeli, kısaltmalar açılmalı, literatür taramasına survey aranarak başlanmalı ve çok sayıda çalışma tabloyla sunulmalıdır.

## Ders Sonrası Notlar

> **Ders sonrası not:** 1. sunumda "açı olarak sıfır, skor olarak sıfır" diye bir ifade geçiyor. Doğrusu: Açı $0°$ iken kosinüs benzerliği 1'dir ve vektörler aynı yöndedir. Skor 0 ise vektörler diktir (açı $90°$).

> **Ders sonrası not:** 1. sunumda ve kısa notta kosinüs "sözcüksel" ölçüt olarak anılıyor. Kosinüs yalnız vektörler arasındaki açıyı ölçer, sözcüksel ya da anlamsal olması vektöre bağlıdır. Kelime sayımı vektörlerinde sözcüksel davranır. word2vec gibi dağılımsal vektörlerde ise anlamca yakın kelimelerin benzerliğini de bir ölçüde yakalar. Hocanın "anlamı yakalayan bir şey yok" yorumu, makalede ayrıca anlamsal bir yöntem denenmediği yönünden okunabilir.

> **Ders sonrası not:** Sunumda Google News veri setinin kullanım nedeni anlaşılamadı. Büyük olasılıkla bu, Google News üzerinde önceden eğitilmiş word2vec vektörlerine işaret eder. Makale bu notta doğrulanmamıştır.

> **Ders sonrası not:** 2. sunumda SVD'nin $A$ matrisinin değerleri "0 veya 1" diye anlatılıyor, oysa bu çalışmada giriş TF-IDF matrisi olduğu için değerler gerçek sayıdır. $V$ matrisi için "sol tekil vektör" denmiş; $U$ sol, $V$ sağ tekil vektörleri tutar. NMF için "negatif değerleri görmezden gelir" denmiş; doğrusu, çarpan matrisler negatif olmayacak biçimde kısıtlanır.

> **Ders sonrası not:** 2. sunumda K-means'in "tüm örnekler bir kümeye dahil olana kadar" sürdüğü söyleniyor. Her örnek zaten ilk adımda bir kümeye atanır. Durma koşulu atamaların (ya da merkezlerin) değişmemesidir.

> **Ders sonrası not:** 2. sunumda bölüm sayısı "6" denip 7 ad sayılıyor. Hangisinin doğru olduğu makaleden doğrulanmadı.

> **Ders sonrası not:** 3. sunumda kesinlik ve duyarlılık sözlü olarak bozuk anlatılıyor. Doğru tanımlar 3.6 bölümündedir. Sayılarla kontrol: $5214/8102 \approx \%64{,}4$ olumlu tutuyor. $905/8102 \approx \%11{,}2$ nötr olur, sunumda "%10" denmiştir. Kalan $1983$ tweet ($\%24{,}5$) olumsuz sınıf için "%25" ile uyumludur.

> **Ders sonrası not:** 4. sunumda "eksiklik giderildikçe kavram sayısı artar" denirken ikisi birden giderilince 151, yalnız ikincisi giderilince 164 kavram söyleniyor. Bu ifadeler birbiriyle tutarlı değil. Altyazı bozuk olduğu için doğru sayılar doğrulanamadı.

> **Ders sonrası not:** 5. sunumda hoca AdaBoost için "meta-heuristik" dedi; öğrencinin slaytındaki "meta-algoritma" ifadesi doğrudur. AdaBoost zayıf öğrenicileri birleştiren bir topluluk (ensemble) yöntemidir, genetik algoritma gibi bir meta-sezgisel değildir.

> **Ders sonrası not:** 5. sunumdaki tabloda ilk çalışma için kesinlik 0,89 ve duyarlılık 0,81'den F-skoru $\approx 0{,}848$ çıkar. Sunumdaki 0,84 değeri yuvarlama farkı olabilir. İkinci çalışmada $0{,}85$ ve $0{,}96$ için $F \approx 0{,}902$ çıkar ve 0,90 ile tutar.

> **Ders sonrası not:** 6. sunumda "intra" ve "inter" attention ifadeleri karışıyor. Makalede kullanılan terimler intra-temporal ve intra-decoder attention'dır. Anlatılan yapı, Paulus, Xiong ve Socher'ın "A Deep Reinforced Model for Abstractive Summarization" çalışmasıyla örtüşüyor; altyazıda makalenin yazarları anılmıyor.

> **Ders sonrası not:** 6. sunumda "kesin ifade özetleri" ve "valsesif kesin ifade" denen yerler ground-truth (gerçek/referans) özet anlamındadır.

> **Ders sonrası not:** Altyazıda bozuk geçen bazı terimlerin doğru yazımları: "Jakart/CACAT" = Jaccard; "KMİS/Kermin's/Kamins" = K-means; "MNF" = NMF; "TvP" = Tweepy; "Latent tricklet" = Latent Dirichlet; "RUJ/Rooch/RUGE/ROG" = ROUGE; "Rooch" = ROUGE; "CVM" = SVM; "Grating Boosting" = Gradient Boosting; "submax" = softmax; "Spice Tutu Text" = speech-to-text; "Sörvey" = survey.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
