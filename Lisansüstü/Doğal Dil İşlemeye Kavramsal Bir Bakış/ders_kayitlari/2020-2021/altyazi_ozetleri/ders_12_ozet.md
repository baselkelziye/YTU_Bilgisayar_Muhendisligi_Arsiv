# Ders 12 Çalışma Özeti

## Genel Konular

- Bu ders (31 Aralık 2020) öğrenci seminer sunumlarının ikinci haftasıdır. Yılın son günüdür. Konu anlatımı yoktur.
- Bu derste 5 sunum yapılır:
  - 1. sunum: Duygu analizi için kelime gömmelerinin (word embedding) iyileştirilmesi.
  - 2. sunum: NLP ve makine öğrenmesi ile sosyal mühendislik saldırılarının tespiti (SEADer++ v2).
  - 3. sunum: Derin öğrenme ile çok kipli (multimodal) duygu analizi.
  - 4. sunum: Sosyal medya içeriğine dayalı duygu analizi ve duygu tahmini sistemi (Polaris).
  - 5. sunum: ÖSYM sözel sorularını NLP teknikleriyle çözmeye çalışan bir yüksek lisans tezi.
- Ders sonunda hoca final günü yapılacak proje değerlendirmesini anlatır.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Küçük katkılar da değerlidir:** 1. sunumdaki çalışma bilinen bir problemi ele alır. Bilinen yöntemlere küçük bir iyileştirme ekleyerek başarıyı artırmaya çalışır. Hoca bunun da geçerli bir araştırma yolu olduğunu söyler.
- **Sosyal mühendislikten kimse muaf değildir:** Hoca kendi başına gelen bir olayı anlatır. Bir yakınının hesabından gelen sahte bir yardım mesajına inanıp para göndermiştir.
  - "Ben bilirim" havasına girmeyin. Bu saldırılar insanın boş bir anına denk gelir.
- **Görüntüden duygu çıkarmak zordur:** Metinden duygu çıkarmak anlaşılırdır. Görüntüde ise yüz ifadesi dışında duyguyu belirlemek ve etiketlemek bile zordur.
  - Örneğin yağmurlu bir manzara biri için olumlu, başkası için kasvetlidir.
- **Zamanla değişen duygu:** 4. sunumdaki kar örneği güzeldir. Kar ilk başta insanların hoşuna gider. Kar uzun sürdükçe moraller bozulur ve duygu olumsuza döner.
- **Referans ve kaynak aynı şeydir:** Slaytta ikisini ayrı başlık olarak koymayın. Birini kullanın.
- **Seminer raporu:** Rapor sunum günü e-posta ile gönderilmelidir. Hoca bunu bir sınav evrakı gibi kullanacaktır.
- **Haber verin:** Sunum gününe gelmeyip haber vermemek kabul edilemez. Hoca herkese kolaylık gösterdiğini, ama haber verilmemesini anlayamadığını söyler.

## Kısa Tekrar Notları

- word2vec iki yöntemle çalışır:
  - CBOW: Bağlamdaki kelimelerden ortadaki kelimeyi tahmin eder. Daha hızlıdır.
  - Skip-gram: Ortadaki kelimeden bağlamdaki kelimeleri tahmin eder. Daha çok işlem gerektirir.
- Pencere boyutu (window size): Ortadaki kelimenin sağında ve solunda kaç kelimeye bakılacağını belirler.
- GloVe (Global Vectors): word2vec yerel bağlama bakar. GloVe ise tüm derlemdeki birlikte geçme (co-occurrence) istatistiklerini kullanır.
- "good" ve "bad" aynı bağlamlarda geçtiği için vektörleri birbirine yakın çıkabilir. Duygu analizinde bu bir sorundur.
- Sosyal mühendislik saldırısı, teknik bilgi gerektirmeden insanın zaaflarını kullanarak bilgi elde etmeye dayanır.
- Çok kipli birleştirmenin iki stratejisi vardır: özellik düzeyinde (feature-level) ve karar düzeyinde (decision-level) birleştirme.
- Metin benzerlik ölçütleri: q-gram, Manhattan (blok) uzaklığı, Levenshtein uzaklığı, Jaccard benzerliği, örtüşme katsayısı (overlap coefficient).
- Final günü her öğrenci projesini ekran paylaşarak gösterir ve 1-2 sayfalık proje raporunu sınav evrakı olarak yükler.

## Detaylı Açıklamalar

### 1. Sunum: Duygu Analizi için Kelime Gömmelerinin İyileştirilmesi

- **Makale:** "Refining Word Embeddings for Sentiment Analysis" (2017, EMNLP).
- **Problem:** Kelime gömmeleri anlamsal bilgiyi yakalar ama duyguyu tam yakalayamaz. Zıt duygulu kelimeler benzer vektörlere sahip olabilir.
  - Önceki çalışmalar iyileştirme için tüm veriyi etiketlemek zorundaydı. Bu çalışma iyileştirmeyi otomatik yapar.
  - Amaç: Aynı duyguya sahip kelimelerin vektörlerinin birbirine yakın olması.
- **Veri seti:** Stanford Sentiment Treebank (SST).
  - İkili sınıflandırma: olumlu, olumsuz.
  - Ayrıntılı (fine-grained) sınıflandırma: çok olumlu, olumlu, nötr, olumsuz, çok olumsuz.
- **word2vec (makalede anlatılmaz, sunucu ekler):** Denetimsiz (unsupervised), tahmin tabanlı bir yöntemdir.
  - Örnek: Pencere boyutu 1 iken cümle kelime kelime kaydırılır. Her adımda ortadaki kelime ve komşuları eşleştirilir.
  - CBOW'da komşular girdi, ortadaki kelime çıktıdır. Skip-gram'da tersidir.
  - Bu makalede skip-gram kullanılır. CBOW daha küçük veride, skip-gram daha büyük veride tercih edilir (sunucunun ifadesi).
- **GloVe:** Pennington ve arkadaşları (2014).
  - Birlikte geçme matrisi, hangi kelimenin hangi kelimeyle yan yana geçtiğini sayar.
  - Örnek: "solid" kelimesi "ice" ile çok, "steam" ile az geçer. "water" ikisiyle de geçer. Olasılıkların oranı anlamı yakalar: buz katıdır.
- **Yöntem:**
  1. Hedef kelime (örneğin "good") için kosinüs benzerliğiyle en yakın $k=10$ kelime bulunur. Listede "bad" gibi zıt duygulu kelimeler de vardır.
  2. Kelimeler bir duygu sözlüğüyle puanlanır. Puanlar 1 (en olumsuz) ile 9 (en olumlu) arasındadır.
  3. Komşular duygu puanına göre yeniden sıralanır. Zıt duygulu kelimeler listenin sonuna düşer.
  4. Hedef vektör, zıt duygulu komşulardan uzaklaştırılır ve aynı duygulu komşulara yaklaştırılır.
  5. İlk denklem farklı kelimeler için birbirine çok benzer yeni vektörler üretmeye başlar. Bu yüzden vektörün bir sonraki konumunu ($v_i^{t+1}$) hesaplayan yinelemeli bir güncelleme eklenir.
  6. $\alpha$ ve $\beta$ parametreleri eklenir. Bu çalışmada ikisi de $0{,}1$ alınır. Bu parametreler güncellemeyi açıp kapatmaya yarar.
- **Karşılaştırma:** Klasik word2vec ile iyileştirilmiş word2vec, klasik GloVe ile iyileştirilmiş GloVe karşılaştırılır. Sınıflandırıcılar CNN, çift yönlü LSTM (Bi-LSTM) ve "Tri-LSTM" diye geçen bir LSTM türüdür.
- **Sonuçlar:**
  - İyileştirilmiş modeller her zaman daha iyi sonuç verir. Artış ikili sınıflandırmada ortalama yaklaşık %1,7, beşli sınıflandırmada yaklaşık %1,6'dır. Fark küçüktür.
  - Gürültü: En yakın 10 kelimenin kaçının zıt duygulu olduğudur. word2vec'te %24 olan gürültü iyileştirilmiş modelde %14'e düşer.
  - Sunucuya göre başarı artışının en büyük nedeni bu gürültü azalmasıdır.
- **Hocanın açıklaması:** "good" ve "bad" aynı cümle yapılarında geçtiği için vektörleri yakındır. Duygu sözlüğü ile sıralama ve vektör güncellemesi bu yakınlığı azaltır.

### 2. Sunum: Sosyal Mühendislik Saldırılarının Tespiti (SEADer++ v2)

- **Makale:** 2020'de IEEE'de yayımlanmış. Uygulamanın adı SEADer++ v2 (Social Engineering Attack Detection). Aynı ekip daha önce SEADer++ (ilk sürüm) ve benzer çalışmalar yayımlamıştır.
- **Sosyal mühendislik saldırısı:** Bir siber saldırının ön aşamasıdır. Hedef kişiden işe yarar bilgiler insan zaafları kullanılarak toplanır. Teknik bilgi gerektirmediği için sık başvurulur.
  - Örnek: "Savcılıktan arıyoruz" yalanıyla insanlardan para veya bilgi istenmesi.
- **Veri seti:** Hedef kişilere kurumsal e-posta veya çevrim içi yazışma gibi görünen konuşma metinleri. Verinin yarısı gerçek, yarısı sentetiktir (yazarlar üretmiştir). Etiketler: saldırı 1, saldırı değil 0.
- **İlgili çalışmalar:** Sosyolojik bakış açısı (2005), fiil-isim çiftleriyle özel bilgi isteyen soruları bulma, durum makineleriyle saldırıyı hafifletme, diyalog anlamını geliştirme, insanın en zayıf halka olduğunu gösteren çalışmalar.
- **Ön işleme (14 adım; ilk 12'si önceki çalışmayla aynı):**
  - **Bağlantı skoru ($S_L$):** Metinden regex ile URL çekilir. URL, Web of Trust API'ye gönderilir.
    - API 0-100 arası bir itibar değeri (reputation value) ve 17 kategoriden birini döndürür.
    - 1xx olumsuz: 101 kötü amaçlı yazılım (malware), 103 oltalama (phishing), 104 dolandırıcılık (scam).
    - 2xx şüpheli: 201 yanıltıcı bilgi, 205 spam, 207 reklam açılır pencereleri.
    - 3xx nötr (çevrim içi izleme, tartışmalı içerik). 5xx olumlu (sorunsuz site).
    - Kategori 1 veya 2 ile başlıyorsa $S_L = 1$ olur. Kategori 3 veya 5 ise $S_L = 1 - \frac{\text{itibar}}{100}$ olur.
  - **Yazım skoru ($S_{SP}$):** SymSpellPy kütüphanesiyle metindeki yanlış yazılmış kelime sayısı $x$ bulunur. Kötü yazılmış metin saldırı belirtisi sayılır.

$$S_{SP} = 1 - e^{-\alpha x}, \qquad \alpha = 0{,}5$$

  - **Niyet skoru ($S_I$):** Metin, 48 kelimelik bir güvenlik politikası sözlüğünden türetilen bir kara listeyle eşleştirilir (password, credentials, database gibi). Eşleşme sayısı $M_B$ ile tutulur.
    - Kişiyi aceleye veya paniğe sevk eden kelimelerle (must, need, urgent gibi) eşleşmeler $M_O$ ile tutulur.
    - İki değer ağırlıklarla birleştirilir. Aynı üstel fonksiyonla 0-1 arasına ölçeklenir. Burada en iyi $\alpha = 0{,}4$ bulunur.
  - **Yeni adım:** LDA (Latent Dirichlet Allocation) ile 3 konulu konu modellemesi yapılır. Üç konu olasılığı veri setine öznitelik olarak eklenir.
- **Son veri seti sütunları:** niyet skoru, yazım skoru, bağlantı skoru, 3 konu olasılığı, etiket.
- **Model seçimi:** Rastgele orman (Random Forest), çok katmanlı algılayıcı (Multilayer Perceptron) ve K en yakın komşu (KNN) denenir. 5 katlı çapraz doğrulama kullanılır. En iyi sonucu Random Forest verir.
  - 10 ağaçlı ve 100 ağaçlı Random Forest karşılaştırılır. 100 ağaçlı model biraz daha iyidir.
- **Sonuçlar (önceki çalışmayla karşılaştırma):**
  - Doğruluk (accuracy): %80,1 (yeni) ve %78,4 (eski).
  - Kesinlik (precision): %79,7 (yeni) ve %80,1 (eski). Eskisi biraz daha iyidir.
  - ROC eğrisi altındaki alan (AUC): yeni yöntemde yaklaşık 0,9.
  - Sonuç: LDA ile konu modellemesi eklemek performansı artırır.
- **Gelecek çalışma:** Bulanık mantık (fuzzy logic) teknikleriyle tespit kalitesinin artırılması. Sunucu bunun LDA'nın olasılık dağılımı yerine bulanık küme üyeliği olarak kullanılabileceğini düşünür.

### 3. Sunum: Derin Öğrenme ile Çok Kipli Duygu Analizi

- **Makale:** 2018, IEEE International Conference on Machine Learning and Applications (ICMLA).
- **Motivasyon:** Duygu analizi çoğunlukla metin üzerinde yapılır. Sosyal medyada görüntü, video ve ses paylaşımı çok artmıştır. Farklı kiplerden (modality) görüş çıkarmak önem kazanmıştır.
- **Literatür:**
  - Çok kipli duygu analizi iki adımda incelenir: her kipten ayrı özellik çıkarımı ve bu özelliklerin birleştirilmesi.
  - Özellik düzeyinde birleştirme: Her kanaldan çıkarılan özellikler sınıflandırmadan önce ortak bir vektörde birleştirilir. Farklı özellikleri entegre etmek zordur.
  - Karar düzeyinde birleştirme: Her kip bağımsız olarak modellenir ve sınıflandırılır. Sonuçlar istatistiksel ağırlıklandırmayla birleştirilir. Bir çalışmada karar düzeyinde birleştirme daha başarılı bulunmuştur.
- **Zorluklar:**
  - Tweet gibi kısa metinler az bağlam içerir. Blog ve makale gibi uzun metinlerde çelişen görüşler olabilir.
  - Görüntülerde anlamlı belirteçler azdır. Piksel grupları ile duygu kavramı arasında anlamsal bir boşluk (semantic gap) vardır.
- **Veri setleri:**
  - Large Movie Review: İkili duygu sınıflandırması için film yorumları (sunumda eğitim için 20.000, test için 5.000 denildi).
  - Twitter görüntü veri seti: 1269 görüntü (969 eğitim, 300 test), olumlu veya olumsuz.
  - MOSI (Multimodal Corpus of Sentiment Intensity): 2.199 video klip, her biri $-3$ ile $+3$ arasında duygu puanlı.
- **Uygulama 1 (metin):**
  - Önceden eğitilmiş gömme kullanmayan LSTM: 512 gizli birim, en fazla 250 token, öğrenme oranı 0,001, ortalama kare hata (MSE) kaybı.
  - Önceden eğitilmiş GloVe (300 boyut, 840 milyar token) kullanan CNN: en fazla 200 token, ikili çapraz entropi kaybı, Adadelta.
  - CNN biraz daha iyi doğruluk verir (yaklaşık %88,53). Önceden eğitilmiş gömmeler avantaj sağlar.
- **Uygulama 2 (görüntü):** 3 evrişim katmanı ve maksimum havuzlama (max pooling). MSE kaybı ve Adam. Başarı metinden çok daha düşüktür (sunumda yaklaşık %67 olduğu anlaşılıyor; altyazıda sayı net değil).
- **Gelecek çalışma:** Metin ve görüntüyü birleştiren çok kipli bir modelin tek kipli modellerden iyi olup olmadığını görmek.
- **Hocanın sorusu:** Görüntüden duygu nasıl çıkarılır? Yüz ifadesi dışında ne yapılabilir?
  - Bir öğrenci etiketlemenin insan tarafından yapıldığını, olumlu veya olumsuz etkisi açık görüntülerin seçilmiş olabileceğini söyler (gülen insanlar, hastanede yatan hasta gibi).
  - Hoca etiketlemenin bile öznel olduğunu belirtir.

### 4. Sunum: Sosyal Medya İçeriğine Dayalı Duygu Analizi ve Tahmin Sistemi (Polaris)

- **Makale:** 2018'de yayımlanmış.
- **Motivasyon:** Sosyal medya olaylar ve doğal afetler hakkında ilk elden bilgi sağlar. Olayların yer ve zamana göre analizi ve duyguların önceden tahmini önemlidir.
  - İçerik gerçek zamanlı ve büyük hacimli olduğu için verimli bir veri yönetim sistemi gerekir. Bu çalışmada AsterixDB kullanılır.
- **Polaris sistemi:** Olayları gerçek zamanlı algılar, duygusal yörüngeyi (sentiment trajectory) analiz eder ve sonraki duyguyu tahmin eder.
  - Harita üzerinde olumlu duygular mavi, olumsuz duygular kırmızı gösterilir. Düğüm boyutu, anahtar kelimenin o bölgede kaç kez geçtiğini gösterir.
- **Olay tespiti:**
  - Başlangıç anahtar kelimeleri seçilir (suç, af, kaza gibi). Anahtar kelimeler ODP sınıflandırmasıyla ve 2015 sonrası makalelerle genişletilir.
  - Anahtar kelimeyi içeren içerikler önce bölgeye, sonra zamana göre sınıflandırılır. Böylece olayın yolu (yörüngesi) çıkar.
- **Duygu sınıflandırma:** Cümle sınıflandırma için CNN kullanılır. Kelimeler word2vec ile vektörleştirilir. Cümle, görüntü gibi iki boyutlu bir girdi olur.
  - Eğitim verisi: Sentiment140 (800.000 olumlu, 800.000 olumsuz tweet).
- **Duygu tahmini:** 7 günlük bir zaman penceresi gözlenir. LSTM ile bir sonraki dönemin duygusu tahmin edilir.
- **Deney:** Nisan 2016'ya ait bir aylık tweet verisi. Yaklaşık 30-40 milyon tweet içinden anlamlı yaklaşık 10 milyon tweet kullanılır. Görselleştirme Google Haritalar animasyonlarıyla yapılır.
  - Örnek: ABD'nin kuzeyinde Nisan başında kar ve bir bölgede kasırga ile ilgili duygu yörüngeleri.
  - Test: 100.000 olumlu ve 100.000 olumsuz tweet. Duygu modeli yaklaşık %84 doğruluk verir. CNN geleneksel tekniklerden daha iyidir.
  - Yetersiz veriye sahip anahtar kelimelerde hata oranı daha yüksektir. Artan iterasyon her zaman hatayı azaltmaz (1500 ve 4500 iterasyon karşılaştırması).
- **Sonuç:** Veri miktarı artırılırsa sonuçlar iyileşebilir. Sistem deprem, tsunami gibi durumlarda iletişim kanalı ve kaza bilgilendirme servisi olarak, ayrıca pazarlamada kullanılabilir.
- **Bir öğrencinin önerisi:** Aynı etiketin (hashtag) günler içinde nasıl değiştiğini izleyerek benzer bir proje yapılabilir.

### 5. Sunum: ÖSYM Sözel Sorularının NLP ile Çözülmesi (Yüksek Lisans Tezi)

- **Kaynak:** Işık Üniversitesi'nde hazırlanmış bir yüksek lisans tezi ve tezden çıkan bir bildiri. Danışman Olcay Taner Yıldız'dır (hoca, kendisinin artık Özyeğin Üniversitesi'nde olduğunu belirtir). Danışmanın Zemberek benzeri bir NLP kütüphanesi vardır (altyazıda "Starlink" diye geçer; büyük olasılıkla StarLang).
- **Amaç:** ÖSYM'nin çoktan seçmeli sınavlarından 4 sözel soru tipi seçilir. Sorulardan bilgisayarın işleyebileceği bir derlem (corpus) oluşturulur. Sorular NLP teknikleriyle çözülmeye çalışılır.
- **Soru tipleri:**
  1. Anlam bütünlüğünü bozan cümleyi bulma.
  2. Cümle parçalarının doğru sıralamasını bulma.
  3. Paragrafı özetleyen cümleyi bulma.
  4. Verilen cümleyle aynı anlamı taşıyan cümleyi bulma.
- **Derlem:** 973 soru. Sorular OCR ile metne çevrilir (motor belirtilmez). Apache POI ile Excel'e, oradan XML'e aktarılır. XML'e cümlelerin biçimbilimsel (morphological) analizleri de eklenir.
- **Bölümleme (segmentation):** kelime, hece, karakter ve kök düzeyinde.
- **Benzerlik ölçütleri:**
  - q-gram benzerliği: Kelime veya cümle belirli uzunlukta karakter parçalarına bölünür. Ortak parça oranına bakılır.
  - Manhattan (blok) uzaklığı: Koordinat farklarının mutlak değerleri toplamı, $d = \sum_i |x_i - y_i|$.
  - Levenshtein uzaklığı: Bir dizgiyi diğerine çevirmek için gereken en az ekleme, silme ve değiştirme sayısı.
  - Jaccard benzerliği: Kesişim / birleşim. Tezdeki örnekte 22 token'dan yalnızca 1'i ortaktır: $1/22 \approx 0{,}045$.
  - Örtüşme katsayısı (overlap coefficient): Kesişim / küçük kümenin boyutu.

$$\mathrm{overlap}(A,B) = \frac{|A \cap B|}{\min(|A|,|B|)}$$

- **Çözüm yapısı:**
  - "Aynı anlamı taşıyan cümle" sorusunda soru cümlesi ile her şık karşılaştırılır. Her şık için bir benzerlik değeri çıkar. En yüksek değerli şık seçilir.
  - 4 bölümleme × 5 benzerlik ölçütü = 20 farklı benzerlik dizisi elde edilir.
  - "Paragrafı özetleyen cümle" sorusunda paragrafın her cümlesi her şıkla karşılaştırılır. Sonuç bir matristir.
- **Bütünsel (holistic) indirgeme yöntemleri:** Matrisi şık başına tek bir değere indirger.
  - max-max: Matristeki en büyük değerin bulunduğu şık seçilir.
  - Çarpım: Her satırdaki değerler çarpılır. En büyük çarpımın şıkkı seçilir.
  - Ortalama: Her satırın ortalaması alınır. En büyük ortalamanın şıkkı seçilir.
  - max-min: Her satırın en küçük değeri alınır. Bunların en büyüğünün şıkkı seçilir.
- **Sonuç:** En iyi başarı kök bölümleme + q-gram benzerliği + max-max ile yaklaşık %28'dir.
- **Sunucunun eleştirileri:**
  - Rastgele seçimle (5 şıkta yaklaşık %20) karşılaştırma yapılmamıştır. Yöntemin rastgeleye göre ne kadar iyi olduğu belli değildir.
  - Bu sorular anlam karşılaştırması gerektirir. Harf ve karakter düzeyinde karşılaştırma ile başarı alınması zordur.
  - Tezde "overlap coefficient" ile "overlapping coefficient" karıştırılmıştır.
- **Hocanın yorumu:** "Adama derler ki o zaman otur, sen daha iyisini yap." Hoca tezden çıkan bildirinin bir sempozyumda hakem olarak kendisine geldiğini hatırlar.

### Final Proje Değerlendirmesi

- Final günü projeler ekran paylaşılarak gösterilir. Ayrı bir PowerPoint sunumu hazırlanmaz.
- Hoca kodu satır satır incelemeyecektir. Ama sorduğu bir yeri öğrenci kod üzerinde rahatça gösterebilmelidir.
- Sınav sisteminde klasik bir sınav açılacaktır. Soru: "Doğal dil işlemenin uygulama alanı olan bir konu belirleyip bunu çözün."
- Öğrenci projesinde ne yaptığını anlatan 1-2 sayfalık raporu sınav evrakı olarak yükler.
- Projeler için ayrı bir toplantı oturumu açılacaktır. Sınav günü yaklaşık 3 saat ayrılacaktır.
- Projesini önceden bitiren olursa ayrı bir zaman diliminde gösterebilir.

### Duyurular ve Ders İşleyişi

- Seminer takvimi 20 Kasım 2020'de e-posta ile gönderilmiştir.
- Raporunu göndermeyenler aynı gün göndermelidir.
- Sonraki hafta (7 Ocak 2021) 8 sunum olacaktır.
- Derste yaklaşık 10 dakikalık bir ara verilir.

### Ders sonrası notlar

- Altyazıda geçen bazı terimlerin doğru yazımları:
  - "Refining for the Embedding for the Sentiment Analyze" → "Refining Word Embeddings for Sentiment Analysis".
  - "Stanford Sentinel Treebank" → Stanford Sentiment Treebank.
  - "SIBO", "Sibov" → CBOW. "Skip-crumb", "SkipCrab", "Zikip Krab" → skip-gram.
  - "Glow", "GLOV" → GloVe. "Penington" → Pennington.
  - "Seader Plus Plus" → SEADer++.
  - "simspell PY" → SymSpellPy.
  - "MOSSİ" → MOSI.
  - "Föntüvek" → büyük olasılıkla word2vec.
  - "Asterix database" → AsterixDB.
  - "sentiment 141" → Sentiment140.
  - "Eczema" → XML. "Apache Point" → Apache POI.
  - "tecelere" → hecelere. "Mehnatın uzaklığı" → Manhattan uzaklığı. "Levinstein" → Levenshtein.
  - "holistik sahileleştirme" → bütünsel (holistic) indirgeme.
- 1. sunumdaki makalenin yayımlandığı yer sunumda "ACL'in ampirik yöntemler konferansı" diye geçer. Bu, EMNLP'dir (Empirical Methods in Natural Language Processing).
- 1. sunumda "Tri-LSTM" diye geçen modeli hoca ve sunucu tanımaz. Bu adın büyük olasılıkla ağaç yapılı LSTM (Tree-LSTM) olduğu düşünülebilir. Altyazıdan kesin değildir.
- 1. sunumda "CBOW daha az veride, skip-gram daha çok veride" denir. 13. derste aktarılan Mikolov'un ifadesine göre ise skip-gram küçük eğitim verisinde iyi çalışır. CBOW daha hızlıdır ve sık geçen kelimelerde daha iyidir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
