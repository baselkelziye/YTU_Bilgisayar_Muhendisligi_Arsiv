# Ders 11 Çalışma Özeti

## Genel Konular

- Bu ders (24 Aralık 2020) öğrenci seminer sunumlarının ilk haftasıdır. Konu anlatımı yoktur.
- Her öğrenci bir makaleyi inceleyip sunar. Hoca sunumların arasına girip sorular sorar ve ek açıklamalar yapar.
- Bu derste 6 sunum yapılır:
  - 1. sunum: Doküman işleme ile anlamsal metin benzerliği analizi (Jaccard ve kosinüs benzerliği).
  - 2. sunum: Boyut indirgeme (SVD, NMF) ve K-means ile metin kümeleme.
  - 3. sunum: 5G teknolojisi hakkında Twitter görüş analizi ve konu modelleme.
  - 4. sunum: Öğretim değerlendirmesi için SMS metinlerinde duygu madenciliği (İngilizce sunum).
  - 5. sunum: Duygu analizinde alaycılık (sarcasm) tespiti yaklaşımları üzerine bir derleme (survey).
  - 6. sunum: Soyutlayıcı (abstractive) metin özetleme için derin pekiştirmeli öğrenme modeli.
- Sunumlardan sonra hoca, bir öğrencinin Türkçe dil modelleri ve konuşmadan metne (speech-to-text) sorusunu yanıtlar.
- Ders sonunda hoca vize sonuçlarını değerlendirir: "Vizeler iyi değildi." Proje ve seminerlerin çok önemli olduğunu vurgular.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Yeni buluş beklenmiyor:** 1. sunumdaki makale bir uygulamayı makaleye çevirmiştir. Hoca "Bunu siz de rahatlıkla yapabilirsiniz" der.
  - Öğrenciler bazı şeyleri gözlerinde çok büyütür. Önemli olan çalışmanın bir amaca hizmet etmesidir.
- **Başlık ve içerik uyumu:** 1. sunumdaki makalenin adında "anlamsal (semantic)" geçer. Ama kullanılan yöntemler (Jaccard, kosinüs) sözcüksel benzerliğe dayanır. Anlamı yakalayan bir yöntem yoktur.
- **Karşılaştırma aynı veri setinde yapılır:** Yeni bir yöntem (örneğin GloVe, BERT) çıktığında eski yöntemle aynı veri seti üzerinde karşılaştırılır. Başarının artıp artmadığı böyle gösterilir.
- **Türkçe kısıtlı kaynaklı bir dildir:** Türkçede etiketli veri seti azdır. Kısıtlı kaynaklı diller (low-resource languages) için ayrı sempozyumlar yapılır. Endonezce, Arapça, Türkçe ve Afrika dilleri bu gruptadır.
- **Kısaltmaları açın:** 3. sunumda hoca "LDA" kısaltmasını sorar. LDA hem Linear Discriminant Analysis hem Latent Dirichlet Allocation olabilir. Sunumda hangisi olduğu belirtilmelidir.
- **Sınıf dengesizliği:** Veri setinde pozitif örnek çok fazlaysa "pozitif" demek kolaydır. Dengeli bir veri setinde (örneğin her sınıftan 5000) sonuçlar daha anlamlı olur.
- **Survey (derleme) çalışmalarının değeri:** Yeni bir konuya başlayınca ilk iş literatür taramasıdır.
  - Literatürü en yeniden en eskiye doğru tarayın.
  - O alanda bir survey olup olmadığına bakın. Survey, bir konudaki çalışmaları belirli başlıklar altında toplar.
  - Son survey eskiyse ve sonrasında çok yayın varsa, onu referans alıp güncelleyerek hem kendi literatürünüzü kurabilir hem yayın çıkarabilirsiniz.
- **Sunumda tablo kullanın:** Hoca 5. sunumda dinleyicinin bir noktadan sonra koptuğunu söyler. Hepsi için geçerli bir uyarı yapar:
  - Çok sayıda çalışmayı anlatırken bir tablo hazırlayın: referansın yılı, kullanılan özellikler, sonuçlar.
  - Böylece soru sorulduğunda slaytlarda ileri geri gitmeden tabloya bakarsınız. Dinleyen de karşılaştırma yapabilir.
  - Doktora izleme toplantısı (TİK) gibi sunumlarda dinleyiciyi yazılı metinlere boğmayın. Dinleyiciyi sunuma bağlamanız gerekir.
- **Raporu aynı gün gönderin:** Seminer raporu sunum günü gönderilmelidir. Hoca çok dersi olduğu için sonradan gelen raporları takip etmekte zorlanır.

## Kısa Tekrar Notları

- Jaccard benzerliği: ortak kelime sayısı / toplam (birleşim) kelime sayısı. Değer 0 ile 1 arasındadır.
- Kosinüs benzerliği: iki vektör arasındaki açıya bakar. Açı küçükse metinler benzerdir.
- Jaccard ve kosinüs sözcüksel (lexical) benzerlik ölçütleridir. Anlamsal (semantic) benzerliği doğrudan yakalamaz.
- TF-IDF'te IDF paydasına eklenen $+1$, hiçbir dokümanda geçmeyen terim için paydanın sıfır olmasını önler.
- SVD ve NMF boyut indirgeme yöntemleridir. K-means ise kümeleme yapar. "NMF, K-means'ten iyi" demek yanlıştır; doğrusu "NMF + K-means, yalnız K-means'ten iyi" demektir.
- Kümeleme ölçütleri: homojenlik (homogeneity), tamlık (completeness), düzeltilmiş Rand indeksi (Adjusted Rand Index, ARI), düzeltilmiş karşılıklı bilgi (Adjusted Mutual Information, AMI).
- Google Cloud Natural Language API duygu için iki değer döndürür: skor (score, $[-1, 1]$) ve büyüklük (magnitude).
- Alaycılık türleri: alay (sarcasm), hiciv (satire), ironi (irony).
- Alaycılık ipuçları: büyük harf, aşırı ünlem ve noktalama, emoji, abartı, düşük yıldız puanı ile olumlu yorumun çelişmesi, olumlu cümleden sonra olumsuz cümle gelmesi.
- Çıkarımsal (extractive) özetleme var olan cümleleri seçer. Soyutlayıcı (abstractive) özetleme yeni cümleler üretir.
- ROUGE, özetlemede kullanılan n-gram örtüşmesine dayalı bir ölçüttür. Bu ölçütte %80-90 gibi değerler görülmez.

## Detaylı Açıklamalar

### 1. Sunum: Anlamsal Metin Benzerliği Analizi için Doküman İşleme Yöntemleri

- **Makale:** "Document Processing Methods for Semantic Text Similarity Analysis" (2020).
- **Motivasyon:** Raylı sistemlerde iki farklı yönetmeliğe ait kural ve prosedür dokümanları vardır (biri Digital Railway UK).
  - Bu dokümanların farklı versiyonları elle karşılaştırılıp birleştiriliyordu (konsolidasyon).
  - Yazarlar bu süreci doğal dil işleme (NLP) ile otomatikleştirmek ister.
- **Araçlar:** CUDA Toolkit (paralel hesaplama), Anaconda ve Jupyter, Python, Gensim (konu modelleme ve doküman benzerliği), NLTK (tokenization), Google News veri seti.
- **Benzerlik ölçütleri:**
  - Sözcüksel benzerlik kelimelerin birebir eşleşmesine bakar.
  - Anlamsal benzerlik anlam yakınlığına bakar. Örnek: "Obama Chicago'da konuştu" ile "Başkan Chicago'da konuştu" anlamca benzerdir.
  - Jaccard benzerliği:

$$J(A,B) = \frac{|A \cap B|}{|A \cup B|}$$

  - Kosinüs benzerliği: Metinler önce word2vec ile vektöre çevrilir. Sonra vektörler arasındaki açı ölçülür.

$$\cos\theta = \frac{\vec{a}\cdot\vec{b}}{\|\vec{a}\|\,\|\vec{b}\|}$$

- **Akış:**
  1. Ön işleme: XML ve Excel formatındaki iki doküman CSV'ye çevrilir ve Jupyter'e aktarılır.
  2. Tokenization: Metin cümlelere veya kelimelere ayrılır. Nokta, soru işareti, ünlem cümle sınırıdır. Boşluk kelime sınırıdır.
  3. Kök bulma (stemming) ve lemmatization: Makale hangi yöntemi kullandığını yazmaz. Sunucu Porter algoritmasını tahmin eder.
  4. Veri temizleme: Aynı madde numarasına sahip satırların aynı prosedürü anlattığı gözle fark edilir. Madde numarası olmayan satırlar düzenli ifadelerle (regex) çıkarılır.
  5. word2vec ile kelimeler vektöre çevrilir.
  6. Önce yalnızca başlıklar karşılaştırılır. Sonuç tutarlı çıkınca sürece devam edilir.
  7. Eşik değeri (threshold) %80 seçilir. Skor 0'a yakınsa benzer değildir, 1'e yakınsa benzerdir.
  8. Dokümanlardaki sorumlu kişiler ve kaç kez geçtikleri bir sayma fonksiyonuyla bulunur ve benzerlikte kullanılır.
- **Sonuçlar:**
  - Jaccard tatmin edici değildir. Hiç alakası olmayan 2.5.2.2 ve 2.2.2.5 prosedürleri %89 benzer çıkar.
  - Kosinüs bu iki prosedür arasında benzerlik bulmaz. Bu doğrudur.
  - Aynı 2.1.1.4 prosedürü için kosinüs benzerliği 1 çıkar.
  - Sonuç: Kosinüs, Jaccard'dan daha başarılıdır.
- **Hocanın sorusu:** Madem madde numaraları benzerliği gösteriyor, neden bir regex ile ilk dört haneye bakılmadı?
  - Yanıt: Amaç maddelerin içeriğinin aynı kalıp kalmadığını kontrol etmektir. Madde numarası sınıf bilgisi gibi kullanılır.
- **Hocanın yorumu:** Hoca derste neden kosinüsü anlattığını hatırlatır. Diğer ölçütlerle uğraşmaya gerek yoktur.
- **Gelecek çalışma:** Yöntemler başka dokümanlarda ve başka donanım platformlarında denenebilir.

### 2. Sunum: Boyut İndirgeme Yöntemleri ve K-means ile Metin Kümeleme

- **Makale:** 2018 tarihli bir metin kümeleme çalışması.
- **Metin kümeleme:** Benzer içerikteki metinler kümelere ayrılır.
  - Kullanım alanları: benzer doküman bulma, arama optimizasyonu, öneri sistemleri, kişisel asistanlar, tekrarlanan içerik tespiti (duplicate content detection).
- **Literatür:**
  - BBC haberlerinde SVD + K-means ile %95 doğruluk.
  - 20 haber grubu verisinde TF-IDF ile bulanık K-means (fuzzy K-means) ve hiyerarşik kümeleme. Bulanık K-means F-skoru 0,88.
  - BBC spor metinlerinde üç boyut indirgeme (Dimension Reduction, DR) tekniği. En yüksek doğruluk InfoGain ile.
- **Veri seti:** Kaggle'dan 20 Newsgroups (yaklaşık 20.000 haber metni, 20 grup).
  - Bazı gruplar birbirine yakındır, bazıları hiç ilişkili değildir (örneğin din ve satılık ilanlar).
  - Gruplar benzerliklerine göre üst bölümlere toplanır: spor, bilim, sağlık, din, politika, otomobil, e-ticaret.
- **Akış:** ön işleme, TF-IDF vektörleştirme, iki boyut indirgeme yöntemi, K-means kümeleme, performans ölçümü.
- **Ön işleme:** Metin token'lara ayrılır. İngilizce durak kelimeler (stop words) çıkarılır.
- **TF-IDF:**

$$\mathrm{tf}(t,d) = \frac{f_{t,d}}{\sum_{t'} f_{t',d}}, \qquad \mathrm{idf}(t) = \log\frac{N}{1 + \mathrm{df}(t)}$$

  - $N$ toplam doküman sayısı, $\mathrm{df}(t)$ terimin geçtiği doküman sayısıdır.
  - Hoca derste IDF'i $\log(N/\mathrm{df})$ olarak göstermiştir. Paydadaki $+1$ terimin hiçbir dokümanda geçmediği durumda sıfıra bölmeyi önler. Hoca bunu sözlü olarak belirtmesi gerektiğini söyler.
- **Neden boyut indirgeme:** TF-IDF matrisi çok seyrektir (sparse). Eğitim hem zaman hem bellek açısından pahalıdır.
- **SVD (Singular Value Decomposition):** Derste LSI konusunda görülmüştür.

$$A = U\,\Sigma\,V^{T}$$

  - $A$: $m \times n$ boyutlu doküman-terim matrisi ($m$ doküman, $n$ terim).
  - $U$: $m \times r$ boyutlu, doküman-konsept benzerliği. Dikgen (orthogonal) bir matristir: $U^T U = I$.
  - $\Sigma$: $r \times r$ köşegen matris. Değerler konseptlerin gücünü gösterir. Büyükten küçüğe sıralıdır.
  - $V$: $n \times r$ boyutlu, terim-konsept benzerliği. $r$ konsept sayısıdır ve terim sayısından küçüktür.
- **NMF (Non-negative Matrix Factorization):** TF-IDF matrisini negatif olmayan iki matrisin çarpımı olarak yazar.

$$A \approx U\,V^{T}, \qquad U \ge 0,\; V \ge 0$$

  - $U$ terimlerin kümelere (konulara) ait olma derecesini, $V$ dokümanların kümelere ait olma derecesini verir.
  - Hoca NMF'nin LSI'daki gibi matris üzerinde işlem yapıp boyut indirgeyen bir yöntem olduğunu belirtir.
- **K-means:** İki aşaması vardır: atama ve güncelleme.
  1. $K$ sayısı belirlenir.
  2. Küme merkezleri rastgele seçilir.
  3. Her örneğin merkezlere Öklid uzaklığı hesaplanır. Örnek en yakın kümeye atanır.
  4. Küme merkezleri güncellenir. Atamalar değişmeyene kadar devam edilir.
- **Ölçütler:**
  - Homojenlik: Her küme yalnızca tek bir sınıfın örneklerini içeriyor mu? Değer 0-1 arasıdır.
  - Tamlık: Aynı sınıfın örnekleri aynı kümede mi?
  - ARI: Tüm örnek çiftlerini sayar. Tahmin edilen ve gerçek kümelemede aynı veya farklı kümeye atanan çiftlere bakarak benzerlik hesaplar.
  - AMI: Karşılıklı bilgiye dayalı düzeltilmiş ölçüt.
- **Sonuç:** NMF + K-means, SVD + K-means ve yalnız TF-IDF + K-means'ten daha iyi sonuç verir.
- **Hocanın düzeltmesi:** Slaytta "NMF, SVD ve K-means'ten daha iyi" yazar. NMF ile SVD aynı işi (boyut indirgeme) yapar. K-means ise kümeleme yapar. Sunucu ifadenin makalede de böyle olduğunu söyler. Doğru karşılaştırma: K-means, SVD + K-means, NMF + K-means.

### 3. Sunum: 5G Teknolojisi Hakkında Twitter Görüş Analizi

- **Motivasyon:** Twitter, insanların gündemdeki konular hakkındaki görüşlerini paylaştığı bir platformdur. NLP için büyük bir veri kaynağıdır.
  - Twitter'da yanlış bilgi de çok dolaşır. Bot hesap tespiti gibi çalışmalar da vardır.
  - Önceki çalışmalar: Black Friday, havalimanı hizmet kalitesi, 2012 ABD başkanlık seçimleri.
- **Yöntem üç aşamalıdır:**
  1. Tweet'ler toplanır ve ön işlemden geçirilir.
  2. Google Cloud Natural Language API ile tweet'ler etiketlenir. Sonra Google AutoML Natural Language ile bir model eğitilir ve test edilir.
  3. LDA (Latent Dirichlet Allocation) ile en çok geçen kelimeler ve konular bulunur.
- **Veri toplama ve temizleme:**
  - "#5G" etiketli 46.559 tweet toplanır.
  - Tweet karakter sınırı 140'tan 280'e çıktığı için kullanılan kütüphanede değişiklik yapılır.
  - Profil ve arka plan resmi olmayan hesaplar elenir.
  - Tekrarlanan (duplicate) tweet'ler ve yanıtlar çıkarılır.
  - Konum bilgisi ülke düzeyine indirgenir (örneğin "California, USA" yerine "USA").
  - Noktalama işaretleri, parantezler ve tırnaklar silinir.
  - Yalnızca İngilizce ve en az 80 karakterlik tweet'ler alınır.
  - Sonuçta 8.102 tweet kalır.
- **Duygu analizi:**
  - Natural Language API iki değer döndürür: skor ($-1$ çok olumsuz, $+1$ çok olumlu) ve büyüklük (metnin ne kadar duygu içerdiği; uzun metinlerde artar).
  - Skorlar $-1$, $0$, $1$ (olumsuz, nötr, olumlu) olarak etiketlenir. Hangi aralığın hangi etikete gittiği makalede yazmaz.
  - Veri %80 eğitim, %10 doğrulama, %10 test olarak bölünür. AutoML'de hangi modelin kullanıldığı belirtilmez.
- **Konu tespiti:** 5'ten az geçen kelimeler ve durak kelimeler çıkarılır. TF-IDF ağırlıklandırması ve LDA'nın çevrim içi (online) sürümü kullanılır. Konular elle ve Natural Language API'nin içerik sınıflandırmasıyla kategorilere yerleştirilir.
- **Sonuçlar:**
  - Veri %64 olumlu, %25 olumsuz, %10 nötr dağılımlıdır (örneğin 5214 olumlu, 905 nötr). Bu dengesizlik başarıyı etkiler.
  - Olumlu sınıfta başarı yüksektir. Nötr sınıfta duyarlılık (recall), kesinliğe (precision) göre çok düşüktür.
  - Hatırlatma: $\text{Precision} = \frac{TP}{TP+FP}$, $\text{Recall} = \frac{TP}{TP+FN}$.
  - Olumlu tweet'lerde teknoloji ilgisi öne çıkar (örneğin Huawei sık geçer). Sağlık kaygılarında "radiation" en sık kelimedir.
  - Sonuç: Kamuoyunda 5G'nin radyasyon kaynaklı kanser gibi hastalıklara yol açacağı korkusu vardır. Firmalar bu kaygıları gidermeye çalışmalıdır.
- **Hocanın yorumları:**
  - LDA'yı açın: Linear Discriminant Analysis mi, Latent Dirichlet Allocation mı?
  - LDA zaten bir konu tespit modelidir. Sunucuya göre LDA kelime grupları verir ama üst kategori adını vermez. Bu yüzden kategoriler sonradan atanır.
  - Makalede yazmayan eşik değerleri üzerine uzun tahmin yürütmek yerine raporlanan sonuçlara odaklanın.
- **Pratik bilgi (sunucu):** Python'daki GetOldTweets kütüphanesi Eylül 2020'den beri çalışmaz. Twitter geliştirici hesabı (developer account) öğrenciler için 1-2 günde onaylanır. Tweepy kütüphanesiyle istenen etiket ve tarih aralığında tweet çekilebilir.

### 4. Sunum: Öğretim Değerlendirmesi için SMS Metinlerinde Duygu Madenciliği

- **Makale:** "Mining Sentiments in SMS Texts for Teaching Evaluation". Yazarlar Singapur'da bir işletme okulundandır (bilgisayar bilimi kökenli değildir).
- Sunum İngilizce yapılır. Altyazının büyük bölümü Whisper döngüsü nedeniyle bozuktur. Aşağıdaki bilgiler altyazının okunabilen kısımlarından ve slaytlardan alınmıştır. Bu kısmın geri kalanı altyazıda anlaşılmıyor.
- **Problem:** Öğrenci geri bildirimi genelde Likert ölçekli değerlendirme formlarıyla alınır (örneğin "kesinlikle katılmıyorum"dan "kesinlikle katılıyorum"a 5 seçenek).
  - Bu çalışmada geri bildirim 160 karakterle sınırlı SMS metinleriyle alınır.
- **Keşifsel veri analizi (exploratory data analysis):** Kavram (concept) veya kategori (category) düzeyinde yapılır.
  - Kavram düzeyi: çıkarılan kavramların listesi, sıklıkları, geçme yüzdeleri ve o kavramı içeren doküman sayısı.
  - Bir kategori birden çok kavram içerebilir. Örneğin "lecture" bir kategoridir.
  - Her SMS bir doküman olarak ele alınır. Seyrek geçen kavramlar gösterilmez.
- **Modelleme ve değerlendirme (slayttan):**
  - Temel model (base model): Tüm SMS derlemi yazım hataları düzeltilmeden analiz edilir.
  - Düzeltilmiş model (corrected model): Yazım hatalı kelimeler aynı kavram altında sınıflandırılır.
  - Duygu modeli (sentiment model): Düzeltilmiş modeli duygu madenciliğiyle genişletir. Kavramlar olumlu veya olumsuz olarak etiketlenir.
- **Metin bağlantı analizi (text link analysis):** Olumlu kavramlarla diğer kavramlar arasındaki ilişkiler bir ağ olarak çizilir. Örneğin "lecture" ve "pace" kavramları birçok olumlu niteleyiciyle bağlantılıdır.
- **Eksiklik (incompleteness) sorunu:** SMS'lerde kısaltmalar ve semboller vardır ("kk", "ok", "okkk" gibi). Bunlar ayrıştırılıp anlamlandırıldıkça çıkarılan kavram sayısı artar ve SMS'lerin yapısı daha iyi anlaşılır. Sunumda 151 ve 164 gibi kavram sayıları verilir. Bu kısımda altyazı güvenilir değildir.
- **Sonuç:** SMS ile öğretim değerlendirmesi, formlara alternatif olabilir. Geliştirilebilir veya başka modüllerle birleştirilebilir.
- **Hocanın yorumları:**
  - Hoca bazı yerlerde koptuğunu söyler. Sunucudan çalışmanın katkısını 2-3 Türkçe cümleyle özetlemesini ister.
  - Katkı: Öğrenciden form yerine serbest metin (SMS) ile geri bildirim alıp olumlu ve olumsuz yanları çıkarmak.
  - Hoca da ders sonunda öğrencilerden e-posta ile yorum ister ve olumlu-olumsuz yanlarını çıkarır.
  - Ağ çizimi için hangi aracın kullanıldığı makalede yazmaz. Makalede matematik azdır.
  - **Proje fikri:** Bölümün bir sosyal medya hesabında her ders için bir etiket (hashtag) açılır. Öğrenciler yorum yazar. Arka plandaki bir uygulama bu yorumların duygu analizini yapar.

### 5. Sunum: Duygu Analizinde Alaycılık Tespiti Üzerine Derleme

- **Makale:** 2018 tarihli, İngilizce metinler üzerine bir derleme. Kendi deneyi yoktur. Birçok çalışmanın yöntemlerini ve sonuçlarını karşılaştırır.
- **Alaycılık nedir:** Söylenen ile kastedilenin çeliştiği, genelde iğneleyici bir ifadedir. Örnekler:
  - Kötü giyinmiş birine "Bugün ne kadar da güzel giyinmişsin."
  - Sıkıcı bir toplantı için "Zevkten dört köşe olduk."
  - Hocanın örnekleri: "Sınava geç kaldım, aferin bana." "Ben böyle uslu bir çocuk görmedim." "Olağanüstü manzaraya bak, her yer çöp dolu."
  - Sevilen bir şeye bazen ters ifadelerle yaklaşılır: "Ay ne kadar çirkin bir bebek, yerim ben bunu."
- **Türler:** alay (sarcasm), hiciv (satire) ve ironi (irony) birbirinden farklıdır.
  - İroni: Beklenenin tersinin olmasını anlatır.
  - Hiciv: Daha çok eleştiri amaçlıdır.
  - Alay: İğneleyici sözdür. Mimiklerden anlamak daha kolaydır.
  - Derste "Kızım sana söylüyorum, gelinim sen anla" atasözünün hangi türe girdiği tartışılır. İğneleme ve ironi yorumları yapılır, net bir sonuca varılmaz.
- **Neden zor:** Yüz yüze konuşmada mimikler, sesli konuşmada ses tonu ipucu verir. Metinde bu ipuçları yoktur.
- **Duygu analizinin genel zorlukları:** varlık tanıma, anafora çözümleme, ayrıştırma (parsing), alaycılık tespiti.
- **İpuçları (özellikler):**
  - Büyük harf kullanımı, aşırı ünlem ve noktalama, emojiler, abartılı ifadeler.
  - Yıldız puanı ile yorum metninin çelişmesi (örneğin 1 yıldız ama övgü dolu yorum).
  - Olumlu bir cümleden sonra olumsuz bir cümle gelmesi veya tersi. Bir cümlede ikilem olması.
  - Argo kelimeler, olumlu ve olumsuz bağlaçlar.
- **Literatürdeki örnekler:**
  - Sırpça WordNet'ten zıt anlamlı kelime çiftleri üretilir.
  - Duygu kelimelerinin oranına göre eşik değerle olumlu-olumsuz-nötr sınıflandırma yapılır.
  - Kelime yoğunluğu 1-5 arasında puanlanır.
  - Bir çalışmada emojiler 8 duygu grubuna ayrılır. word2vec ve K-means kullanılır.
  - 8 temel duygu: sevinç, iğrenme, güven, sürpriz, öfke, beklenti, üzüntü, korku.
  - MapReduce ile büyük veri üzerinde NLP çalıştırılır ve süre kısalır.
- **Veri:** En çok Twitter (#sarcasm etiketi) ve Amazon ürün yorumları kullanılır.
- **Ön işleme:** tokenization, durak kelime çıkarma, kök bulma ve lemmatization, sözcük türü etiketleme (POS tagging).
- **Özellik çıkarımı (feature extraction):** terim sıklığı, özellik varlığı, TF-IDF, ağırlıklı TF-IDF, delta TF-IDF, n-gram, word2vec.
- **Sınıflandırıcılar:** destek vektör makineleri (SVM, doğrusal olmayan SVM dahil), Naive Bayes, AdaBoost, Gradient Boosting, rastgele orman (Random Forest), karar ağacı, maksimum entropi.
  - AdaBoost: Zayıf sınıflandırıcıları birleştirip güçlü bir sınıflandırıcı oluşturan bir meta-algoritmadır.
  - Doğrulama: 5 katlı ve 10 katlı çapraz doğrulama (k-fold cross validation).
  - Emojilerin anlamını çıkarmak için K-means ($K=5$) kullanılır.
- **Kural tabanlı yöntemler:** sözcüksel (lexical), anlamsal (semantic), sözdizimsel (syntactic), edimsel (pragmatic; noktalama), bürünsel (prosodic; ses tonu), deyimsel (idiosyncratic; kalıp ifadeler).
- **Sonuçlardan örnekler:**
  - SVM ile olumsuzluk + ünlem özellik kombinasyonu: %54,1 doğruluk.
  - Önerilen bir yöntem: %86,1 doğruluk.
  - Emoji ile doğruluk 0,78; emojisiz 0,61. Emoji alaycılık tespitinde çok güçlü bir ipucudur.
- **Hocanın geri bildirimi:** Sunum çok fazla metin okumaya dayandığı için hoca bir noktadan sonra takip edemediğini söyler. Çalışmaların yıl, özellik ve sonuç sütunlu bir tabloda özetlenmesini ister. Bu uyarı tüm öğrenciler için geçerlidir.

### 6. Sunum: Soyutlayıcı Özetleme için Derin Pekiştirmeli Model

- **Makale:** Soyutlayıcı özetleme için derin pekiştirmeli (deep reinforced) bir model. 2018'de bir konferansta yayımlanmıştır.
- **Metin özetleme:** Bir belgeyi alıp onun yerine geçen, en önemli içeriği taşıyan daha kısa bir metin üretir. Haber ve rapor özetleme gibi alanlarda kullanılır.
  - Çıkarımsal (extractive): Metindeki önemli cümleler istatistiksel ve dilsel özelliklere göre seçilir. Yeni cümle üretilmez.
  - Soyutlayıcı (abstractive): Kritik bilgi yorumlanır ve yeni cümlelerle özet üretilir.
- **Önceki çalışmaların sorunu:** Dikkat (attention) tabanlı kodlayıcı-kod çözücü (encoder-decoder) modeller kısa girdilerde iyi ROUGE skorları alır. Ama uzun metinlerde tekrar eden ifadelerle dolu, doğal olmayan özetler üretir.
- **Önerilen model:**
  - Kodlayıcı çift yönlü (bidirectional) LSTM, kod çözücü tek yönlü LSTM'dir. Girdi ve çıktı gömme (embedding) matrisleri paylaşılır.
  - Zamansal iç dikkat (intra-temporal attention): Önceki adımlarda yüksek dikkat alan girdi token'ları cezalandırılır. Böylece aynı yerlere tekrar tekrar bakılmaz.
  - Kod çözücü iç dikkati (intra-decoder attention): Kod çözücü daha önce ürettiği çıktıya da bakar. Tekrarlar azalır.
  - Token üretme ve işaretçi (pointer) mekanizması: Model ya sözlükten kelime üretir (softmax) ya da girdideki nadir kelimeleri kopyalar. Bir anahtar (switch) fonksiyonu hangisinin kullanılacağına karar verir.
  - Test sırasında aynı trigram'ın iki kez üretilmesi engellenir.
- **Eğitim:**
  - Öğretmen zorlaması (teacher forcing) ile maksimum olabilirlik (maximum likelihood) kaybı en aza indirilir.
  - Sorun 1: Maruz kalma yanlılığı (exposure bias). Sorun 2: Geçerli olabilecek çok sayıda özet vardır.
  - Çözüm: Kendi kendini eleştiren politika gradyanı (self-critical policy gradient) ile pekiştirmeli öğrenme. ROUGE gibi ayrık bir ölçüt doğrudan en büyüklenir.
  - Yalnız ROUGE'u en büyüklemek okunabilirliği garanti etmez. Bu yüzden maksimum olabilirlik ve pekiştirmeli öğrenme kayıpları birleştirilerek karma (hybrid) bir amaç fonksiyonu kullanılır.
- **Veri setleri:**
  - CNN/Daily Mail: 287.113 eğitim, 13.368 doğrulama, 11.490 test örneği. Girdi 800, çıktı 100 token ile sınırlanır. Ortalama uzunluklar 632 ve 53 token.
  - New York Times: 1996-2007 arası makaleler. Özetleri daha kısa ve daha soyuttur. Bu veri seti soyutlayıcı özetleme için ilk kez kullanılır.
- **Sonuçlar:** İç dikkat ROUGE skorlarını artırır. Yalnız pekiştirmeli öğrenme en yüksek ROUGE'u alır. Beş kişiyle yapılan insan değerlendirmesinde ise karma model en okunabilir ve en ilgili özetleri üretir.
- **Hocanın ek açıklaması:**
  - Derin öğrenmeden önce hep çıkarımsal özetleme yapılıyordu. Hangi cümlelerin seçileceği özellik ve kurallarla belirleniyordu.
  - Çoklu doküman özetlemede (örneğin aynı COVID haberini veren 10 gazete) anlamca benzer cümlelerden yalnızca biri alınır. Bunun için kosinüs benzerliği gibi ölçütler kullanılır.
  - Başarı genelde insanlara okutularak ölçülür: Özet okuyanı ne kadar tatmin ediyor?
  - Soyutlayıcı özetleme klasik makine öğrenmesi ve kural tabanlı yöntemlerle zordu. Derin öğrenme ve attention ile yapılabilir hale geldi.
  - ROUGE hesaplaması F-skoru kadar kolay değildir. ROUGE'da %80-90 gibi başarılar görülmez.
  - Derin öğrenme kısmı ancak bir projenin içinde yer alınca oturur.

### Türkçe Dil Modelleri Üzerine Soru-Cevap

- Bir öğrenci iş yerinde konuşmadan metne (speech-to-text) sistemi üzerinde çalışır. Sistemin akustik model ve dil modeli tarafı vardır.
  - Küçük alanlarda n-gram dil modeli yeterlidir. Genel Türkçe için uçtan uca (end-to-end) yaklaşımlar araştırılır.
  - Öğrenci Türkçe için yeterli çalışma olmadığını söyler.
- **Hocanın önerileri:**
  - Boğaziçi Üniversitesi'nden Murat Saraçlar Türkçe ve ses üzerinde çalışır.
  - İTÜ'den Gülşen Hoca dil modelleri üzerinde çalışır, ses üzerinde değil.
  - Koç Üniversitesi'nden Deniz Yüret son dönemde Türkçe üzerine de çalışmaya başlamıştır.
- **Türkçe yayın yapmanın zorluğu:** Hakemler "Hangi çalışmayla karşılaştırdın?" diye sorar. Türkçede karşılaştırılacak çalışma azdır. İngilizce ile aynı dil ailesinden olmadığımız için İngilizce sonuçlarla da karşılaştırma yapılamaz.
- **Yanlış yazılmış kelimeyi düzeltme fikri:** FastText, kelimenin karakter n-gram'larından gömme çıkarır.
  - Önceden eğitilmiş Türkçe gömmeler kullanılır. Yanlış yazılmış kelimelerin gömmeleri çıkarılır.
  - Bu gömmelerin doğru kelimelere olan uzaklıklarına bakılır. En yakın kelime gerçekten olması gereken kelimeyse yöntem kullanılabilir.
  - Arama motorlarının "Bunu mu demek istediniz?" yaklaşımı da bir seçenektir. Örneğin I/İ gibi Türkçe karakter varyasyonlarıyla arama yapılıp en sık geçen biçim doğru kabul edilebilir.
  - Ama "geliyom" gibi ağızlara dayalı biçimlerde sıklık yaklaşımı tutmaz. Kelime vektörlerinin yakınlığı daha uygundur.

### Duyurular ve Ders İşleyişi

- 17 Aralık 2020'deki vize test usulüydü. Hoca sonuçlara bakıp e-posta ile gönderdiğini söyler. Dosyaların sınıf grubuna iletilmesini ister.
- Hoca vizelerin iyi geçmediğini, ama proje ve seminerlerin çok önemli olduğunu söyler.
- Bir öğrenci COVID-19 nedeniyle vizeye giremez.
- Seminer raporu sunum günü gönderilmelidir. Bir öğrenci raporunu IEEE formatına çevirip aynı gün gönderecektir.
- Sonraki hafta (31 Aralık 2020) sunum yapacak öğrenciler belirlenir.
- Ders ortasında yaklaşık 10 dakikalık ara verilir.

### Ders sonrası notlar

- Altyazıda geçen bazı terimlerin doğru yazımları:
  - "Jakart", "CACAT", "Cakart" → Jaccard.
  - "Kosünüs", "COSUNİS" → kosinüs (cosine).
  - "Judah Toll Kit" → büyük olasılıkla CUDA Toolkit (paralel hesaplama için).
  - "DFLIP kütüphanesi" → büyük olasılıkla Python `difflib` modülü.
  - "RGX kütüphanesi olan R kütüphanesi" → Python'un düzenli ifade modülü `re`.
  - "NLPK" → NLTK.
  - "KMİS", "Kermin's" → K-means.
  - "MNF" → NMF (Non-negative Matrix Factorization).
  - "ARS Studio", "art tweet kütüphanesi" → büyük olasılıkla R Studio ve `rtweet` paketi.
  - "TvP kütüphanesi" → Tweepy.
  - "Latent tricklet allocation" → Latent Dirichlet Allocation.
  - "Rooch", "RUJ", "RUGE" → ROUGE.
  - "Sörvey" → survey (derleme).
- 1. sunumda Google News veri setinin neden kullanıldığı sunucu tarafından anlaşılamamıştır. Bu veri seti büyük olasılıkla önceden eğitilmiş word2vec vektörleri için kullanılmıştır.
- 2. sunumdaki "NMF, SVD ve K-means'ten daha iyi" ifadesi hatalıdır. Doğrusu: NMF + K-means kombinasyonu, SVD + K-means ve yalnız K-means'ten daha iyi sonuç verir.
- 3. sunumda nötr sınıftaki düşük duyarlılığın nedeni olarak etiket eşiklerinin seçimi tahmin edilir. Makale bu eşikleri raporlamadığı için bu yalnızca bir yorumdur.
- 4. sunumun (İngilizce) altyazısının büyük bölümü döngüye girmiştir. Özetteki bilgiler okunabilen kısımlar ve slaytlarla sınırlıdır.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
