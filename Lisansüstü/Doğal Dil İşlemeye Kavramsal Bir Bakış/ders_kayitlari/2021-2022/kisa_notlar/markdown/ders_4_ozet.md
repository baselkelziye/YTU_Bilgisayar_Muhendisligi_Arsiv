# Ders 4 Çalışma Özeti

## Genel Konular

- Bu ders (22 Aralık 2021) tamamen öğrencilerin makale sunumlarına (seminer) ayrılmıştır. Toplam altı sunum vardır.
- 1. sunum: Mikroblog verisinde çok etiketli (multi-label) duygu sınıflandırması (sentiment classification).
- 2. sunum: Sosyal medya içeriklerinde gerçek zamanlı olay tespiti, duygu analizi ve duygu tahmini sistemi (Polaris).
- 3. sunum: Emojiler için gözetimsiz (unsupervised) yöntemle duygu sözlüğü (sentiment lexicon) oluşturma.
- 4. sunum: Türkçe doküman sınıflandırmada kelime bölütleme (word segmentation) yöntemlerinin sinir ağı sınıflandırıcılarına etkisi.
- 5. sunum: Demiryolu güvenliği belgelerinde anlamsal metin benzerliği (semantic text similarity): Jaccard ve kosinüs benzerliği.
- 6. sunum: Hisse senedi trend tahmininde teknik analiz ile haberlerden çıkarılan duygu gömmelerinin (sentiment embedding) birleştirilmesi.
- Ders sonunda hoca akademik yayın süreci üzerine deneyimlerini paylaşmıştır: dergi seçimi, hakem süreci, ücretli dergiler ve fikrin korunması.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sunuma veri setiyle değil, çalışmanın amacıyla başlanmalıdır. Önce "bu çalışma ne yapıyor?" sorusu bir iki cümleyle cevaplanmalıdır.
- Her sunumda makalenin hangi yıl ve nerede (dergi veya konferans) yayınlandığı söylenmelidir. Hoca bunu her sunucuya sormuştur.
- Makale okunmadan sunum yapılmamalıdır. Yazarların kim olduğu ve veri setinin nereden geldiği bilinmelidir.
- Çok etiketli (multi-label) ile çok sınıflı (multi-class) sınıflandırma arasındaki fark net anlatılmalıdır.
- Çok az veriyle ve dengesiz etiket dağılımıyla yapılan çalışmaların iddiaları sorgulanmalıdır.
- Seminer için seçilen çalışmanın benzerini proje olarak yapmak çok faydalıdır. Veri seti değişebilir ama yöntem tanıdık olur. Hoca bunu bu dönem için geç kalmış bir öneri olarak söylemiştir.
- Q1 dergi olmak her zaman çok yüksek kalite demek değildir. Yılda çok sayı çıkaran ve her sayıda çok makale yayınlayan dergilerin etki faktörü (impact factor) atıflarla daha kolay artar.
- IEEE Access ücretlidir ama iyi bir dergidir. Ücret süreci hızlandırmak içindir. "Paranı ver, makalen basılsın" türü dergilerden uzak durulmalıdır. Bu tür dergiler akademik yükseltmelerde fark edilir.
- Bir sonuç elde edilince beklemeden yayına dönüştürülmelidir. Aynı konuda başkası da çalışıyor olabilir.
- Fikrin önceliğini korumak için sempozyum bildirisi veya arXiv gibi ön baskı (preprint) siteleri kullanılabilir.
- Hakemin değerlendirdiği makaleden fikir alması etik değildir.

## Kısa Tekrar Notları

- Multi-class: bir örneğe tek bir sınıf atanır. Multi-label: bir örneğe birden fazla etiketten oluşan bir küme (set of labels) atanır. Örnek: bir tweet aynı anda hem "endişe" hem "korku" etiketi taşıyabilir.
- Çok etiketli sınıflandırma iki ana yaklaşımla yapılır:
  - Problem dönüştürme (problem transformation): Binary Relevance, Label Powerset, Classifier Chain. Problem birden çok tek etiketli probleme çevrilir.
  - Algoritma uyarlama (algorithm adaptation): kNN, karar ağacı, Random Forest gibi sınıflandırıcılar çok etiketli veriye uyarlanır (ML-kNN gibi).
- Duygu analizinde üç yaklaşım vardır: sözlük tabanlı (lexicon-based), makine öğrenmesi tabanlı ve hibrit.
- Jaccard benzerliği: $J(A,B) = \dfrac{|A \cap B|}{|A \cup B|}$. Sayıma dayanır, anlam bilgisi taşımaz.
- Kosinüs benzerliği: $\cos\theta = \dfrac{\mathbf{a}\cdot\mathbf{b}}{\|\mathbf{a}\|\,\|\mathbf{b}\|}$. Açı küçüldükçe benzerlik artar.
- Word2vec gibi gömmelerle hesaplanan kosinüs benzerliği bağlamı (context) ve anlamı yansıtır. One-hot gösterim bağlamdan bağımsızdır.
- Türkçe için kelime bölütleme yöntemleri: kelime, karakter, karakter n-gram, kök (stem), lemma, morfoloji, Morfessor, Byte Pair Encoding (BPE), byte düzeyinde BPE, WordPiece, unigram dil modeli.
- Etkin Piyasa Hipotezi (Efficient Market Hypothesis, EMH) ve Uyarlanabilir Piyasa Hipotezi (Adaptive Market Hypothesis, AMH) piyasa davranışını açıklamaya çalışan iki teoridir.
- Zaman serisi verisinde örnekler birbirine bağımlıdır. Bu yüzden veri rastgele karıştırılıp çapraz doğrulama (cross-validation) yapılamaz. Genişleyen pencereli (increasing window) çapraz doğrulama kullanılır.

## Detaylı Açıklamalar

### 1. sunum: Çok Etiketli Duygu Sınıflandırması

- **Konu:** "Multilabel Classification Based Approach for Sentiment Classification". 2015 yılında yayınlanmıştır. Yazarlar bunun çok etiketli duygu sınıflandırması yapan ilk çalışma olduğunu iddia eder.
- **Amaç:** Mikroblog (Twitter benzeri, Çince) metinlerinde bir metne birden fazla duygu etiketi atamak. Literatürdeki yöntemleri karşılaştıran bir kıyaslama (benchmark) oluşturmak.
- **Veri seti:** Yazarlar iki Çince mikroblog veri setini kendileri toplayıp etiketlemiştir. İkisi de ulusal gündem olaylarından derlenmiştir.
  - HR: bir nehirde ölü domuzların bulunması olayı. 385 mikroblogdan 365'i tek etiketli, yalnız 20'si çok etiketlidir.
  - IA: influenza A salgınıyla ilgili 762 mikroblog. Burada da etiket dağılımı dengeli (uniform) değildir.
  - İki veri setinde de birkaç duygu etiketi (sunumda üzüntü ve öfke gibi) çok baskındır.
- **Yöntem:**
  - Metin bölütleme için Jieba Python paketi kullanılmıştır. Paketin tanımadığı kelimelerde gizli Markov modeli (Hidden Markov Model) ve Viterbi algoritması devreye girer. Çince kelimeler boşlukla ayrılmadığı için bu adım gereklidir.
  - Üç farklı Çince duygu sözlüğü öznitelik çıkarma için kullanılmıştır.
  - On bir çok etiketli sınıflandırıcı denenmiştir: Binary Relevance, Classifier Chain, RAkEL, CLR, HOMER, Random Forest, Predictive Clustering Tree, kNN uzantıları (ML-kNN gibi) vb.
  - Problem dönüştürme yöntemlerinde taban sınıflandırıcı (base classifier) olarak RBF çekirdekli SVM, kNN uzantılarında kNN kullanılmıştır.
  - Sekiz değerlendirme metriği vardır:
    - Örnek tabanlı (example-based): Hamming loss, subset accuracy, örnek tabanlı F1.
    - Etiket tabanlı (label-based): mikro F1 ve makro F1.
    - Sıralama tabanlı (ranking-based): coverage, one-error, average precision.
- **Sonuç:**
  - HR veri setinde RAkEL ve Classifier Chain, sözlük kullanılmayan ham bölütlenmiş kelimelerle en iyi sonucu vermiştir.
  - IA veri setinde CLR ve HOMER öne çıkmıştır. Metriğe göre birinci olan yöntem değişmektedir.
  - kNN uzantıları iki veri setinde de kötü sonuç vermiştir.
  - Daha çok duygu anahtar kelimesi ve duygu gücü (sentiment strength) bilgisi içeren sözlük daha iyi sonuç vermiştir.
  - İki veri setinde de tek başına öne çıkan bir yöntem yoktur.
- **Sunucunun ve hocanın değerlendirmesi:**
  - Veri seti çok küçüktür. "Ulusal duygu" iddiasına rağmen yalnız birkaç yüz tweet toplanmıştır.
  - Çok etiketli örnek sayısı çok azdır. Bu yüzden "çok etiketli" iddiası zayıftır.
  - Sunucu, döviz kurunun hızla değiştiği bir günde on binlerce tweet atıldığını örnek vererek daha iyi bir veri seti kurulabileceğini söylemiştir.

### 2. sunum: Sosyal Medyada Olay, Duygu ve Duygu Yolu Tahmini (Polaris)

- **Konu:** "Social Media Contents Sentiment Analysis and Prediction System". 2018'de yayınlanmıştır.
- **Amaç:** Büyük miktarda sosyal medya içeriğinden gerçek zamanlı olarak olayları tespit etmek, olaylara ilişkin duyguları sınıflandırmak ve duyguların zamana ve yere göre izlediği yolu (trajectory) tahmin etmek.
- **Katkılar:**
  - Elle etiketleme maliyetlidir. Bunun yerine ifade (emoticon) tabanlı olumlu ve olumsuz etiketleme önerilir.
  - Önceki çalışmalarda yol analizi ve duygu analizi ayrı yapılırken burada birlikte yapılır.
  - Veri yönetimi için MongoDB yerine AsterixDB seçilmiştir. Gerekçe: MongoDB'de join sorgularının yavaş olması. AsterixDB, University of California (Irvine) tarafından geliştirilmiş, JSON'u genişleten bir veri modeli kullanan, dağıtık çalışabilen ve B+ ağacı, R-ağacı gibi indeksleri destekleyen bir büyük veri yönetim sistemidir. Gerçek zamanlı veri almak için besleme (feed) mekanizması vardır.
- **Yöntem:**
  - Olay tespiti: Open Directory Project (ODP) tabanlı sınıflandırma ve sürekli güncellenen tohum kelimeler (seed words). Örnek tohum kelimeler: kar (snow), kasırga (hurricane), kaza (accident).
  - İlgili tweetler önce konuma, sonra zaman dilimine göre gruplanır. Böylece olayın yolu çıkarılır.
  - Duygu analizi: cümle sınıflandırma için CNN modeli (TensorFlow ile). Kelimeler word2vec ile vektöre çevrilir.
  - Duygu tahmini: Önce 7 günlük zaman penceresinde ortalama alan bir yöntem denenmiştir. Ani duygu değişimlerini yakalayamadığı için LSTM'e geçilmiştir.
- **Veri seti:**
  - Bir aylık yaklaşık 40 milyon tweet toplanmış, aykırı değerler (outlier) temizlendikten sonra yaklaşık 10 milyon tweet kalmıştır.
  - Duygu modeli Sentiment140 veri setinin 800.000 olumlu ve 800.000 olumsuz tweetiyle eğitilmiştir.
  - Görselleştirmede Google Maps animasyonları kullanılmıştır. Mavi olumlu, kırmızı olumsuz duyguyu gösterir. Düğüm büyüklüğü bir bölgedeki bahsedilme sayısını gösterir.
- **Sonuç:**
  - Duygu analizinde yaklaşık %84 F1 elde edilmiştir. Karşılaştırma Naive Bayes, SVM ve Random Forest gibi klasik yöntemlerle yapılmıştır.
  - Kasırga (tornado) olayında duyguların %81,8'i olumsuzdur. Tornado verisi çok az (yaklaşık 20) olduğu için tahmin hatası yüksektir.
  - LSTM, pencere ortalaması yönteminden daha düşük RMSE vermiştir. 4500 iterasyon sonrası iyileşme olmamıştır.
  - Olası kullanım alanları: deprem ve kasırga uyarı sistemleri, trafik kazası bildirimi, pazarlama.
- **Hocanın soruları ve geri bildirimi:**
  - Hoca "olay analizi" adımını bir örnekle netleştirmiştir: önce tweetin bir olayla ilgili olup olmadığı belirlenir.
  - Hoca neden hashtag'lerin kullanılmadığını sormuştur. Makalede bu açıklanmamıştır.
  - Hoca, bir felaketten sonra yapılan yardımlarla duyguların olumsuzdan olumluya dönebileceğini örnek vermiştir. Ortalama tabanlı pencere yöntemi bu dönüşü yakalayamadığı için başarısız olmuştur.
  - Sunucu, derin öğrenme tabanlı başka yöntemlerle karşılaştırma yapılmamasını eksiklik olarak görmüştür.

### 3. sunum: Emojiler İçin Gözetimsiz Duygu Sözlüğü

- **Konu:** 2017'de Elsevier'de yayınlanmış bir makale. Yazarların İspanyolca ve İngilizce verilerle çalıştığı belirtilmiştir.
- **Amaç:** Kelimeler için olduğu gibi (ör. "iyi" +3, "kötü" −3) emojiler için de bir duygu sözlüğü oluşturmak. Bunu elle etiketleme yerine gözetimsiz bir yöntemle yapmak.
- **Arka plan:**
  - Emojiler yaklaşık 30 yıl önce Japonya'da ortaya çıkmıştır. 2009'da yüzlerce emoji Unicode karakteri olarak derlenmiştir.
  - 2015'te Instagram gönderilerinin yaklaşık yarısında emoji kullanılmıştır.
  - Bazı emojilerin anlamı kişiye, bağlama, kültüre, cinsiyete ve platforma (iOS ve Android) göre değişir. Örnek: gülümseyen yüz bazen ironi veya tehdit anlamı taşıyabilir.
  - Elle etiketlemede emojilerin yaklaşık %25'inde etiketleyiciler arasında fikir ayrılığı çıkmıştır.
  - Ön işlemede emojileri silmek metnin duygusunu belirleyen en önemli ipucunu kaybettirebilir. Örnek: "I still have Christmas shopping to do" cümlesi emojiyle olumsuz anlam kazanır.
- **Yöntem:**
  - Her emojinin Emojipedia'daki açıklaması (description) alınır ve duygu analizi yapılır.
  - Emojinin geçtiği tweetlerin emojisiz metin kısmının duygu analizi ayrıca yapılır.
  - İki sonuç aynı yöndeyse emojiye o puan atanır. Emoji açıklaması olumlu ama kullanıldığı cümleler çoğunlukla olumsuzsa puan olumsuz yöne çekilir.
  - Kelime duygusu için iki sözlüğün birleşimi kullanılmıştır.
- **Veri seti:** Daha önceki bir çalışmada etiketlenmiş 1,6 milyon tweetin İngilizce ve İspanyolca kısmı. Yaklaşık 103.000 tweet vardır. İngilizce tweetlerde 624, İspanyolca tweetlerde 613, toplamda 704 farklı emoji geçmektedir.
- **Sonuç:** Emojisiz metnin duygusu ile emojinin duygusu arasındaki uyum %59,82'dir. Sunucuya göre önceki çalışmalarda bu oran %45-50 civarındadır.
- **Hocanın soruları ve geri bildirimi:**
  - Hoca yeni bir emojinin nasıl kabul edildiğini sormuştur. Bir öğrenci önerilerin gönderilebildiğini, başka bir öğrenci merkezi bir otorite olmadığını söylemiştir (bkz. ders sonrası notlar).
  - Hoca, emojilerin anlamının kadın ve erkek bakış açısına göre de değişebileceğini vurgulamıştır.

### 4. sunum: Türkçe Doküman Sınıflandırmada Kelime Bölütleme

- **Konu:** 2020'de IEEE INISTA (Innovations in Intelligent Systems and Applications) konferansında (Sırbistan) yayınlanmış dört sayfalık bir bildiri.
- **Amaç:** Türkçe doküman sınıflandırmada kelime bölütleme yöntemi seçiminin sinir ağı sınıflandırıcılarının performansına etkisini araştırmak.
- **Problem:** Türkçe morfolojik açıdan zengin (eklemeli) bir dildir ve çok yabancı kelime içerir. Bu durum sinir ağlarının eğitimini zorlaştırır.
- **Bölütleme yöntemleri:**
  - Kelime tabanlı: boşluklara göre bölme.
  - Karakter tabanlı ve karakter n-gram ($n$ = 2-7). Standartlaştırılmamış metinde daha verimlidir.
  - Kök (stem) tabanlı: Snowball kütüphanesi.
  - Lemma tabanlı: Zemberek kütüphanesi.
  - Morfoloji tabanlı: kelime gramer kurallarına göre biçim birimlerine (morfem) ayrılır.
  - Morfessor: morfemleri veriden gözetimsiz öğrenen bir bölütleme aracı.
  - Byte Pair Encoding (BPE): en sık yan yana gelen birimleri birleştiren, sıkıştırma algoritmasından türetilmiş bir alt kelime (subword) yöntemi. Sözlük boyutunu küçültür, yabancı kelimelerde başarılıdır.
  - Byte düzeyinde BPE, WordPiece ve unigram dil modeli tabanlı bölütleme.
- **Veri setleri (dört tane):**
  - YTÜ Kemik NLP grubunun topladığı yaklaşık 17.000 tweet.
  - Puanlı yorumlardan oluşan bir veri seti. 4,5 ve üzeri olumlu, 1,5 ve altı olumsuz kabul edilmiş, aradakiler çıkarılmıştır.
  - Yine Kemik grubunun hazırladığı haber veri seti.
  - Kaggle'dan alınan Türkçe ürün yorumları. 5 puan olumlu, 1-2 puan olumsuz.
- **Sınıflandırıcılar:** Doğrusal model, CNN tabanlı ve LSTM tabanlı sınıflandırıcı. Aşırı öğrenmeye (overfitting) karşı dropout, optimizasyon için Adam kullanılmıştır. Donanım sınırı nedeniyle her girdi 256 token ile sınırlanmıştır. Her deney beş kez tekrarlanmıştır.
- **Ön işleme:** Bağlantılar kaldırılmış, harfler küçültülmüş, noktalama işaretleri ayrılmış, çoklu boşluklar ve tekrarlanan karakterler teke indirilmiştir.
- **Sonuç:**
  - Alan (domain) ile sinir ağı mimarisi arasında uyum olmalıdır. Bölütleme yöntemi buna göre seçilmelidir.
  - Mimari dizileri modelleyebiliyorsa (CNN, LSTM) Morfessor tabanlı bölütleme en iyi sonucu vermiştir.
  - Mimari dizileri modelleyemiyorsa unigram, lemma ve kök tabanlı yöntemler benzer sonuç vermiştir.
  - Normalize edilmemiş verilerde (tweetler) karakter n-gram, özellikle $n=5$, en iyi sonucu vermiştir.
- **Hocanın geri bildirimi:**
  - Sunucu çalışmayı özetlerken yine veri setiyle başlamıştır. Hoca, önce çalışmanın amacının söylenmesi gerektiğini vurgulamıştır.
  - Hoca "Morfessor" terimini ilk kez duyduğunu söylemiş ve makaleyi e-postayla istemiştir.
  - Hoca, makaleyi okuyup yazarların kim olduğuna bakılmasını istemiştir.

### 5. sunum: Belge İşleme ve Anlamsal Metin Benzerliği

- **Konu:** "Document Processing Methods for Semantic Text Similarity Analysis". 2020'de yine INISTA konferansında (Sırbistan) yayınlanmıştır. Yazarlar İngiltere'deki bir üniversitedendir.
- **Amaç:** Demiryolu güvenliği alanındaki kılavuz, yönetmelik ve rehberlerin, kurumsal mimari (Enterprise Architecture) modelindeki (UML formatında) kurallarla tutarlı olup olmadığını otomatik olarak kontrol etmek. Bunun için Jaccard ve kosinüs benzerliğini karşılaştırmak.
- **Araçlar:** CUDA, Anaconda Navigator, Jupyter Notebook, Python, Gensim, NLTK. Kelime vektörleri Google News üzerinde önceden eğitilmiş word2vec modelinden alınmıştır. Model kendi korpusunu oluşturmaz.
- **Veri:**
  - Üniversitenin demiryolu araştırma enstitüsünden alınmıştır.
  - İki formattadır: CSV formatında eşleme dosyası ve UML formatında kurumsal mimari modeli. İkisi de CSV'ye dönüştürülmüştür.
- **Yöntem:**
  - Kelime tokenizasyonu benzerlik hesabı için, cümle tokenizasyonu sorumlu aktörlerin karşılaştırılması için kullanılmıştır.
  - Temizleme: stop word'ler silinmiş, "2.1.1" gibi madde numarasıyla başlamayan paragraflar düzenli ifade (regular expression) ile atılmıştır. Çünkü kurallar madde numarasıyla ilerler.
  - Tekrarlanan sorumlu kişi ve aktörler silinmiştir.
  - Eşik değeri deneme yanılmayla 0,80 seçilmiştir.
  - Sorumlu aktörlerin karşılaştırması ("match difference list") ayrı bir görev olarak yapılmıştır. Bu görev benzerlik skorlarına katılmamıştır.
- **Sonuç:** Kosinüs benzerliği (word2vec ile) anlam bilgisini yakaladığı için Jaccard'dan daha iyi sonuç vermiştir. Uzun ve parantezli cümlelerde Jaccard skoru düşmektedir. Alakasız cümlelerde kosinüs benzerliği, birkaç ortak kelime olsa bile yüksek skor üretmemiştir.
- **Tablodaki tutarsızlık tartışması:**
  - Sunucu Jaccard değerlerini kendisi hesaplamış ve tablodaki bazı değerlerle uyuşmadığını görmüştür.
  - Tabloda yanlış eşleşmeler eksi işaretiyle gösterilmiştir (ör. −0,86).
  - Hoca formüle göre bu iki kısa-uzun cümle için 0,86 çıkamayacağını söylemiştir. Sunucu da değerin aslında $1 - 0{,}86 = 0{,}14$ benzerlik anlamına geldiğini düşündüğünü belirtmiştir. Makalede bu gösterim açık değildir.
- **Hocanın gözlemi:** Bu sunucu ve 4. sunucu slaytlarını Türkçe hazırlamıştır. Diğer sunumların çoğu İngilizcedir.

### 6. sunum: Teknik Analiz ve Duygu Gömmeleriyle Hisse Senedi Tahmini

- **Konu:** 2019'da Elsevier'in Expert Systems with Applications dergisinde yayınlanmıştır. Dergi Q1'dir.
- **Amaç:** Teknik analizi (fiyata dayalı matematiksel göstergeler) ve temel analizi (haberlerden çıkarılan duygu) birleştirerek hisse senedi portföyünün trendini tahmin eden bir model geliştirmek.
- **Arka plan:**
  - EMH'ye göre fiyat yeni bilgi ve haberlerle değişir. Haber öngörülemez olduğu için mevcut veri üzerinden hareket edilir.
  - AMH, EMH ile davranışsal finansı birleştirir ve piyasadaki anormallikleri psikoloji temelli teorilerle açıklar.
  - Önceki çalışmalarda ARIMA ve sinir ağı tabanlı hibrit modeller kullanılmıştır.
- **Yöntem:**
  - Problem sınıflandırma problemi olarak ele alınmıştır. Trendin boyutunu sabitleyen bir hiperparametre ve min-max normalizasyonu kullanılmıştır.
  - Öznitelikler iki kaynaktan gelir: metinsel (haber özetleri) ve sayısal (fiyat ve teknik göstergeler).
  - Duygu çıkarmak için iki sözlük kullanılmıştır:
    - Loughran-McDonald: finans alanına özel sözlük. Her haber için olumlu, olumsuz, kısıtlayıcı, davalı vb. kelime sayıları çıkarılır.
    - AffectiveSpace: alana özel değildir ama kavram düzeyinde duygu çıkarabilir.
  - Aynı çeyrek saatte (15 dakika) yayınlanan haber gömmelerinin ortalaması alınmıştır.
  - Fiyatlar 15 dakikalık aralıklarla Google Finance API'den alınmış, teknik göstergelerle birlikte 11 boyutlu bir vektör oluşturulmuştur.
  - Sınıf dengesizliği için SMOTE, örnekler arası bağımlılık için genişleyen pencereli çapraz doğrulama kullanılmıştır.
  - Sınıflandırıcılar: Random Forest, SVM ve yapay sinir ağı.
- **Veri seti:** NASDAQ 100 endeksinin en büyük 20 hissesinden oluşan portföy. Yüksek frekanslı alım-satım (high-frequency trading) simülasyonu yapılmıştır.
- **Sonuç:**
  - Duygu gömmeleri ile teknik göstergelerin birleşimi, yalnız fiyat kullanımından daha iyi sonuç vermiştir.
  - AffectiveSpace sınıflandırma başarımında daha yüksek sonuç vermiştir.
  - Yıllık getiri açısından Loughran-McDonald öznitelikleri daha iyi sonuç vermiştir.
- **Hocanın yorumu:**
  - Hoca hakemlik için gelen makaleleri bir klasörde topladığını ve seminer konularını oradan dağıttığını söylemiştir. Bu yüzden birçok makale aynı dergidendir.
  - Hoca güncel döviz kuru konusunu sunumlara referans yapmamalarını, her konunun kendine özel olduğunu söylemiştir.

### Akademik Yayın Süreci Üzerine Sohbet

- Bir öğrenci derginin yayın süresinin bir buçuk hafta olduğunu söylemiştir. Hoca bu dergide kendi yayını olduğunu ve bu kadar hızlı dönüş almadığını belirtmiştir. Bu süre büyük olasılıkla ilk geri dönüş veya hakem atama süresidir.
- Hakem süreci hakeme bağlıdır. Bazı hakemler hemen değerlendirir, bazıları uzun süre bekletir.
- Hoca bir dergide 8 ay bekledikten sonra "sayfa sayısı fazla" gerekçesiyle ret aldığını anlatmıştır. O süreçte dergi sayfa sınırını değiştirmiştir. Hocaya göre makale gönderildiği tarihteki kurallara göre değerlendirilmelidir.
- Bir öğrenci IEEE Access'e ücret ödeyip süreci iki ayda tamamladığını söylemiştir.
- Makale gönderildikten sonra fikrin çalınması riski için hoca şunları söylemiştir:
  - Önce sempozyumda veya ulusal dergide yayın yaparak çalışmanın başlangıç tarihi kanıtlanabilir.
  - Hakemin fikri kullanması etik değildir ve eninde sonunda anlaşılır.
  - Dünyanın başka yerinde biri aynı konuda bağımsız olarak çalışıyor olabilir. Bu yüzden hızlı olmak gerekir.
  - Bir öğrenci arXiv gibi ön baskı sitelerini hatırlatmıştır. Hoca bunu onaylamıştır.

### Ders sonrası notlar

- 1. sunumda sunucu bir ara "Japonca" demiş, hoca düzeltmiştir. Veri seti Çincedir.
- 1. sunumda altyazıda "J-body" diye geçen paket Jieba'dır. "Viter-Balgout Mus" Viterbi algoritmasıdır. "Heming" Hamming loss'tur. "Raker" RAkEL'dir. Sözlük adları altyazıda bozuk geçmektedir ("DUTSE", "NTSD"). Bunlar büyük olasılıkla DUTSD ve NTUSD Çince duygu sözlükleridir.
- 2. sunumda sunucu AsterixDB'yi "Neste tabanlı" diye anlatmıştır; bu kısım altyazıda anlaşılmıyor. AsterixDB'nin veri modeli JSON'un üst kümesi olan ADM'dir (Asterix Data Model).
- 2. sunumda "Centimet 140" Sentiment140 veri setidir. "Polaris" sistemin adıdır.
- 3. sunumda emojiler için "merkezi bir otorite yok" denmiştir. Bu doğru değildir. Emojiler Unicode Konsorsiyumu (Unicode Consortium) tarafından standartlaştırılır. Yeni emoji önerileri bu kuruma gönderilir ve kurum tarafından kabul edilir.
- 3. sunumda 2009 derlemesini yapan kurumun adı altyazıda anlaşılmıyor.
- 4. sunumda "zembere" Zemberek, "morfesör" Morfessor'dur. Morfessor, Japonca gibi dillere özel değildir. Kelimeleri morfem benzeri birimlere gözetimsiz olarak ayıran genel bir araçtır. Türkçe gibi eklemeli dillerde sık kullanılır.
- 4. sunumda byte düzeyinde BPE "diziler yerine karakterleri birleştirir" diye anlatılmıştır. Doğrusu: byte düzeyinde BPE, Unicode karakterleri yerine byte'lar üzerinde çalışır. Böylece sözlük dışı (out-of-vocabulary) karakter kalmaz.
- 4. sunumda WordPiece önce Japonca ve Korece için geliştirilmiştir. Daha sonra BERT ile İngilizce ve diğer dillerde yaygınlaşmıştır.
- 4. sunumda puanlı yorum veri setinin adı altyazıda anlaşılmıyor. 01:09:38 ile 01:10:07 arasında altyazı boşluğu vardır.
- 4. sunumda sonuçlar anlatılırken sunucu önce "normalize edilmemiş tweetlerde Morfessor en iyi" demiş, hemen ardından "normalize edilmemiş verilerde karakter n-gram en iyi" demiştir. Tutarlı okuma şudur: dizileri modelleyen mimarilerde Morfessor, normalize edilmemiş verilerde karakter 5-gram en iyidir.
- 5. sunumda Google News word2vec modeli için "300 milyon" ve "1 milyar kelime" denmiştir. Doğrusu: model yaklaşık 100 milyar kelimelik Google News korpusunda eğitilmiştir. Yaklaşık 3 milyon kelime ve öbek için 300 boyutlu vektör içerir. "300" vektör boyutudur.
- 5. sunumda kosinüs benzerliğinin "0-1 arası" olduğu söylenmiştir. Bu yalnız negatif olmayan vektörler (TF-IDF, sayım) için doğrudur. Word2vec vektörlerinde kosinüs benzerliği $[-1, 1]$ aralığındadır.
- 5. sunumda CUDA için "NVIDIA'dan bir GPU" denmiştir. CUDA bir GPU değil, NVIDIA'nın paralel hesaplama platformu ve programlama arayüzüdür.
- 5. sunumda Gensim "generate similarity" diye açıklanmıştır. Gensim'in adı "generate similar" ifadesinden gelir. Konu modelleme ve kelime gömmeleri için bir Python kütüphanesidir.
- 6. sunumda "Logran-McDonough" Loughran-McDonald, "Effective Space" AffectiveSpace, "smotiviren" büyük olasılıkla SMOTE'tur.
- 6. sunumda Random Forest için "regülasyon" denmiştir. Doğrusu regresyondur (regression).

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
