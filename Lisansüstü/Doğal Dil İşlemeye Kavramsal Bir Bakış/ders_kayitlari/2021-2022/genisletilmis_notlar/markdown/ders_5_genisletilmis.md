# Ders 5 Genişletilmiş Notu: Duygu Analizi, Hisse Senedi Tahmini, Denetimsiz Metin Sınıflandırma ve WSD Sunumları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu ders 29 Aralık 2021 tarihlidir ve baştan sona öğrenci seminerlerinden oluşur. Beş öğrenci birer makale sunar; hoca araya girerek soru sorar, açıklama yapar ve sunumları yönlendirir. Slaytlardaki tablo ve grafikler altyazıya geçmediği için yalnız sunum yapanların sözlü olarak söylediği değerler bu notta yer alır.

## İçindekiler

- 1. Sunumlarda Hocanın Beklentileri
- 2. Birinci Sunum: 5G Teknolojisinin Twitter'da Duygu Analizi
- 3. İkinci Sunum: Twitter'daki Finansal Topluluktan Şirket Olaylarının Tespiti
- 4. Üçüncü Sunum: Sosyal Medya Duygu Analiziyle Hisse Senedi Hareketi Tahmini
- 5. Dördüncü Sunum: Anahtar Kelime Listeleriyle Denetimsiz Metin Sınıflandırma
- 6. PCA ve Kümeleme Üzerine Soru-Cevap
- 7. Beşinci Sunum: Çift Yönlü LSTM ile Kelime Anlamı Belirginleştirme
- 8. Dersin Toparlaması
- 9. Ders Sonrası Notlar

## 1. Sunumlarda Hocanın Beklentileri

Hoca ders boyunca sunum anlatımıyla ilgili birkaç noktaya müdahale eder. Sınıf Naive Bayes, destek vektör makinesi (SVM) ve benzeri yöntemleri zaten bildiği için bunların tek tek anlatılmasını istemez. Birinci sunumda araya girerek "bu yöntemler kullanılmıştır diye hızlı geçebiliriz" der. Aynı sunumda TF-IDF konusunda da aynı şeyi söyler: yöntemin kullanıldığını belirtip geçmek yeterlidir, çünkü sınıf bu modeli biliyor. Bir cümleyi birkaç cümleye yayan "ağdalı" anlatımı da eleştirir. Sunum süresi 20 dakikadır.

Beşinci sunumda slaytta "döküman" yazıldığını görünce hoca doğru yazımın "doküman" olduğunu söyler. Bu hatayı kendisinin de doktora tezinde yaptığını ve Türkçe üzerine bir çalışma yürütürken tez danışmanından bu yüzden uyarı aldığını anlatır. O günden beri bu kelimeye dikkat ettiğini ekler.

> **Hocanın vurgusu:** Sınıfın bildiği yöntemleri ayrıntılı anlatmayın. Hangi yöntemin kullanıldığını söyleyip çalışmanın kendine özgü kısmına geçin.

## 2. Birinci Sunum: 5G Teknolojisinin Twitter'da Duygu Analizi

### 2.1 Makale ve Amaç

Bu sunumdaki bildirinin adı "The Evolution of 5G Technology from Sentiment Analysis Perspective in Twitter"dır. Yazarlar Kocaeli Üniversitesi Bilişim Sistemleri Mühendisliği bölümündendir (altyazıda "Tuğkan Seçkin" ve Zeynep Hilal Kilimci). Bildiri 15-17 Ekim 2020'de Innovations in Intelligent Systems and Applications konferansında sunulmuş, 23 Kasım 2020'de IEEE tarafından yayımlanmıştır.

Çalışmanın çıkış noktası, 5G'ye duyulan endişelerdir. Sunuma göre hücresel haberleşme kuşakları önce 1G ile ortaya çıkmış, 1991'de 2G tanıtılmış, ardından 3G, 4G ve 5G gelmiştir. 5G makineleri, nesneleri ve cihazları neredeyse her şeyi birbirine bağlamak üzere tasarlanmış bir sistemdir. Önceki teknolojilerde olduğu gibi burada da kaygılar vardır: siber güvenlik açıkları, mevcut teknolojilerle uyum sorunu ve radyasyon riski. Yazarlar bu kaygılar nedeniyle toplumun teknolojiye yaklaşımını incelemek istemiştir.

Önemli bir ayrıntı şudur: çalışma, toplumun 5G'ye olumlu mu olumsuz mu baktığı sonucuna varmaz. Yalnız kullanılan sınıflandırıcıların başarılarını karşılaştırır.

### 2.2 Veri Toplama ve Ön İşleme

Tweetler TWINT aracıyla çekilmiştir. TWINT, belirli kelimeleri içeren tweetleri, belirli hesapların tweetlerini ve belirli zaman aralıklarındaki tweetleri aramaya olanak tanır. Dil ayarı İngilizce, tarih aralığı 01.01.2019 - 30.05.2020'dir. 5G etiketli 100.000 tweet toplanmış, etiketleme sonrasında nötr tweetler çıkarılınca 58.965 tweet kalmıştır (yani 41.035 tweet elenmiştir; ara adım eklendi). Gerekçe, çalışmanın yalnız olumlu ve olumsuz yorumlarla ilgilenmesidir. Uygulama Python ile Jupyter Notebook üzerinde yapılmıştır.

Kirli verinin (dirty data) sınıflandırmaya olumsuz etkisini azaltmak için şu ön işleme adımları uygulanmıştır:

- Düzenli ifadelerle (regular expressions) URL'ler, hashtag'ler ve emojiler kaldırılmıştır.
- Diğer semboller silinmiştir.
- Etkisiz kelimeler (stop words) atılmıştır.

### 2.3 Etiketleme ve Vektörleştirme

Denetimli öğrenme için etiket gerekir. Etiketleme, metin işleme için bir Python kütüphanesi olan TextBlob ile yapılmıştır. TextBlob sözcük türü etiketleme (part-of-speech tagging), isim öbeği çıkarma (noun phrase extraction), duygu analizi, sınıflandırma ve çeviri gibi işler için basit bir API sunar. Cümlelerin polarite değerine göre etiketler şöyle verilmiştir:

- Negatif polarite: 0
- Pozitif polarite: 1
- Sıfır polarite (nötr): 2

Metinler TF-IDF ile vektörleştirilmiştir. Hoca bu noktada araya girip yöntemin bilindiğini, kullanıldığını söylemenin yeterli olduğunu belirtir.

### 2.4 Yöntemler ve Sonuçlar

Karşılaştırılan yöntemler Naive Bayes (Gaussian, Bernoulli, Multinomial), SVM (linear, RBF, polynomial kernel), K en yakın komşu (KNN) ve tekrarlayan sinir ağıdır (RNN). KNN için 0 ile 10 arasında bir liste oluşturulup döngüyle en iyi K değeri aranmıştır. RNN modelinde çıkış boyutu 50, yoğun (dense) katmanda çıkış birimi 256 olarak ayarlanmıştır. Sonuçlar doğruluk, F ölçütü, kesinlik (precision) ve duyarlılık (recall) ile değerlendirilmiştir.

<!-- BELİRSİZ: Sonuç tablosunun değerleri slaytta. Altyazıda yalnız aşağıdaki değerler sözlü olarak geçiyor. -->

- **Naive Bayes:** En iyisi Bernoulli'dir. Multinomial yaklaşık %1 geridedir. Gaussian yaklaşık %19-20 daha düşüktür. Sıra: Bernoulli, Multinomial, Gaussian.
- **SVM:** En iyisi %75,10 doğrulukla linear kernel'dır. Diğer kernel'lardan yaklaşık %2 iyidir. Sıra: linear, RBF, polynomial.
- **KNN:** En iyi değer $K=5$ ile %73,08'dir. Sıra: $K=5$, $K=7$, $K=3$.
- **Genel sıra (klasik yöntemler):** SVM, KNN, Naive Bayes.
- **RNN:** %78,35 doğrulukla bütün klasik yöntemleri geçer. En iyi SVM'den farkı $78{,}35 - 75{,}10 = 3{,}25$ puandır (ara adım eklendi).

Sunum, RNN'in toplumun 5G algısını tespit etmede klasik yöntemlerden önemli ölçüde iyi olduğu sonucuyla biter.

## 3. İkinci Sunum: Twitter'daki Finansal Topluluktan Şirket Olaylarının Tespiti

### 3.1 Amaç ve Arka Plan

Bu çalışma, Dow Jones endeksindeki 30 büyük şirketle ilgili tweetleri analiz eder. Amaç, şirketlerin o dönemki popülerliğini ve performansını ölçmek, şirket olaylarının tweetlere nasıl yansıdığını görmektir.

Sunumda önce duygu analizinden önceki piyasa analizi kavramları hatırlatılır. Teknik analize göre fiyat, piyasa güçlerinin kapsamlı bir yansımasıdır; fiyatlar tarihsel olarak kendini tekrar eder ve belirlenebilen trendlerde hareket eder. Metin sınıflandırma tarafında ise fikir madenciliği (opinion mining) ve duygu analizi çalışmaları vardır. Bu çalışmalar sözcüksel kaynaklardan yararlanır: OpinionFinder, SentiStrength, WordNet ve Google Profile of Mood States (GPOMS) gibi. GPOMS altı duygu boyutu tanımlar: sakin, uyanık, emin, canlı, nazik, mutlu.

Duygu analizinin buradaki işlevi, tweetin altında yatan örtük duyguyu çıkarmaktır: tweet olumlu mu, olumsuz mu, nötr mü? Olumlu ifadeler yüksek puan alır, olumsuzlar düşük, ve günün sonunda puanlar toplanarak bir sonuca varılır.

### 3.2 Sistem Tasarımı

Sistem beş bloktan oluşur: finansal topluluk, tweet filtreleri, duygu analizi, normalizasyon ve olay tespiti. Tweetler önce topluluktan alınır, sözlüklerle filtrelenir, her şirket için ayrı dosyalara yazılır, skorlar hesaplanır, normalize edilir ve son aşamada olaylar tespit edilir.

**Finansal topluluk.** Kullanıcılar rastgele seçilmez. Benzer ilgi alanına sahip kullanıcı kümesi şu ölçütlerle oluşturulur:

- Kullanıcının takipçi sayısı, takip ettiği kişi sayısından fazla olmalıdır.
- Çok popüler hesaplar alınmaz, çünkü bu hesapların tweetleri genelde nötre yakındır ve bu içerik zaten Bloomberg, CNBC gibi kaynaklarda bulunur.
- Seçilen kişiler, yeterince takipçisi olan ama herkesçe bilinmeyen ve söyledikleri önemli olan kişilerdir. Slaytta örnek olarak Ray Dalio'nun hesabı gösterilir.

**Tweet filtresi.** Önemli olmayan tweetleri ayıklamak için anahtar kelimeler tanımlanır. Apple örneğinde şirket adı, Dow Jones'taki kod ve başında dolar simgesi olan kod aranır. Eşleşen tweetler şirketin dosyasına yazılır. 30 şirket için toplam 30 dosya oluşur.

Filtrede Investopedia'ya dayanan, 865 kelimelik bir finans sözlüğü kullanılır. Sözlükte teknik terimlerden günlük kullanıma kadar finansal kelimeler ve bu kelimelerin çekimli biçimleri (örneğin "buy" kelimesinin çekimleri) yer alır. Bu filtrenin amacı finansal piyasayla ilgisiz tweetleri silmektir. Örneğin "Apple" elma da demektir; "Apple juice" geçen bir tweet dikkate alınmaz.

### 3.3 Duygu Ölçme Araçları

Sunumda metin analiz araçları karşılaştırılır:

- **MySentiment API ve Sentiment140:** Sentiment140, tweetleri kutuplarına göre ayıran bir web uygulamasıdır ve 1,6 milyon tweet örneğiyle çalışır. Tek kelimelik unigram'lar ve iki kelimelik bigram'lar puanlanır, sonra bütün puanlar toplanır. Twitter'da metin kısa olduğu için cümle bölme değil, kelimeye ayırma (tokenization) önemlidir.
- **TextBlob:** Python'da yazılmıştır. Polarite $[-1, 1]$ aralığındadır. Öznellikte (subjectivity) 0 çok nesnel, 1 çok öznel demektir.
- **SentiStrength:** Kısa sosyal web metinleri için uygundur, bu yüzden Twitter analizine yatkındır. Beş kategoriye ayırır: pozitif, nötr, negatif, aşırı pozitif ve aşırı negatif. Olumlu kelimelere $+1$ ile $+5$, olumsuz kelimelere $-1$ ile $-5$ arasında değer verir.
- **AFINN:** ANEW (Affective Norms for English Words) sözlüğüne dayanır. Sözlük 2477 kelimedir. Olumlu kelimeler 1 ile 5, olumsuz kelimeler $-1$ ile $-5$ arasında puanlanır.

<!-- BELİRSİZ: Sunumda "4 araç" deniyor ve TextBlob "ikinci", SentiStrength "üçüncü", AFINN "dördüncü" diye sayılıyor. Bu sayıma göre MySentiment API ile Sentiment140'ın tek bir araç mı iki ayrı araç mı olduğu altyazıdan anlaşılmıyor. -->

Örnek tweet tablosunda aynı metnin araçlara göre puanları gösterilir. Pozitif tweetler yeşille işaretlenir. Bir negatif tweet için $-0{,}5$ ve $-4{,}7$ gibi değerler söylenir; $-4{,}7$ aşırı negatif sayılır. Sıfır, nesnel yani nötr demektir.

<!-- BELİRSİZ: Örnek tweet tablosu slaytta; hangi puanın hangi tweete ve araca ait olduğu altyazıdan tam izlenemiyor. -->

### 3.4 Normalizasyon

Twitter kullanımı zamanla artar. Bu yüzden sonraki aylardaki skorlar daha yüksek çıkar ve grafikte yanıltıcı tepeler oluşur. Tutarlılık için günlük puan, son 3 aydaki ortalama tweet hacmine bölünür. Normalizasyondan sonra değerler birbirine yaklaşır.

<!-- BELİRSİZ: Normalizasyonun matematiksel formülü slaytta, altyazıda okunmuyor. -->

### 3.5 Veri ve Vaka Çalışmaları

9000'den fazla kullanıcı ve yaklaşık 2 yıllık, 12 milyonun üzerinde tweet incelenmiştir. Filtreleme sonrasında 192.935 tweet kalır; bu, yaklaşık %1,6'dır (ara adım eklendi).

Vaka çalışmaları Apple, Microsoft ve Walmart içindir:

- **Apple:** Dört araçta da en fazla öne çıkan tepe, iPhone 6'nın çıkışıdır. Diğer tepeler akıllı saatin piyasaya sürülmesi ve iPhone 6 yükseltmesidir.
- **Microsoft:** CEO'nun bir sunumu ve Nokia'nın satın alınması öne çıkar. Negatif tepe, 18.000 çalışanın işten çıkarılması duyurusudur.
- **Walmart:** Vaka olarak anılır, ayrıntısı anlatılmaz.

Sonuç olarak duygu analizi araçları Google Trends gibi genel arama araçlarıyla birleştirilince şirketlerin dönem performansı ve finansal olaylar başarılı biçimde tespit edilir. Hoca sunumu beğendiğini söyler.

## 4. Üçüncü Sunum: Sosyal Medya Duygu Analiziyle Hisse Senedi Hareketi Tahmini

### 4.1 Makale ve Temel Fikir

Makale "Sentiment Analysis on Social Media for Stock Movement Prediction" başlığını taşır ve 2015'te Elsevier'de yayımlanmıştır. Fikir şudur: Şirketler ve ülkeler iş planı yaparken piyasa fiyatlarına bakar. Fiyatlar birçok faktöre bağlıdır, bunların başında toplumun ruh hali gelir. Toplumun ruh hali sosyal medyadan öğrenilebilir. Çıkarılan duygu bilgisi modele öznitelik olarak eklenir.

### 4.2 Etkin Piyasa Hipotezi, Temel Analiz ve Teknik Analiz

Etkin Piyasa Hipotezi (Efficient Market Hypothesis) der ki piyasa trendleri haberlere ve bilgilere bağlıdır; haberler ve bilgiler ise doğası gereği öngörülemez. Sunum yapan öğrenci bunu 2020 Mart'ında pandeminin başlamasıyla piyasaların düşmesi örneğiyle anlatır. Bu hipoteze göre ne kadar çalışılırsa çalışılsın %50'nin üzerine çıkılamaz. Sonraki çalışmalarda ise %56 gibi sonuçlar elde edilmiştir.

Fiyat hareketi tahmininde iki yaklaşım vardır:

- **Temel analiz (fundamental analysis):** Şirket veya ülke hakkındaki bilgilere bakar: iş birlikleri, yapılan ve alınan yatırımlar, yurt dışına açılma, büyüme oranı, yıllık getiri. TL örneğinde ülkenin yatırımları, anlaşmaları ve prestiji buraya girer.
- **Teknik analiz (technical analysis):** Tarihsel fiyat hareketlerine bakar. Patern, destek ve direnç noktası aranır. Örneğin TL için 9 değeri tarih boyunca geçilmesi zor bir seviyeyse direnç noktası sayılır. Fiyat destek seviyesine gelip tepki alıyorsa ve yukarı dönüyorsa, aynı seviyeye tekrar geldiğinde yine tepki alacağı düşünülerek pozisyon alınabilir.

Bu makale iki yaklaşımı birleştirir: tarihsel fiyat verisi teknik kısmı, duygu bilgisi temel kısmı temsil eder.

### 4.3 Veri

Fiyat verisi Apple, Amazon, Dell gibi 18 büyük şirketin bir yıllık verisidir. Her gün için açılış, kapanış, en yüksek ve en düşük değerler alınır. Bunlar grafikteki mumlarla gösterilir: her mum bir günü temsil eder, gövde açılış ve kapanışı, uçlar günün en yüksek ve en düşük değerini verir. Hafta sonları piyasa kapalıdır, bu yüzden yaklaşık 249 işlem günü vardır.

Duygu verisi 23 Temmuz 2012 - 19 Temmuz 2013 arasında Yahoo Finance Message Board'dan alınır. Twitter tercih edilmemiştir, çünkü Twitter verisi düzensiz, dağınık ve yazım hatalıdır. Mesaj panosunda kullanıcılar şirketler hakkında yorum yazar. Bir kullanıcı, yorumun altına kendi duygusunu da ekleyebilir: strong buy, buy, sell veya strong sell.

Bütün mesajların yalnız %15'inde böyle bir duygu etiketi vardır. Tabloda her şirket için günlük ortalama yorum sayısı gösterilir. Örneğin Apple için günlük ortalama 1678 yorumun yaklaşık 350'sinde duygu etiketi vardır, kalan yaklaşık 1300'ünde yoktur.

### 4.4 Yöntem ve Altı Öznitelik Kümesi

Model SVM'dir. Yüksek boyutlu veride başarılı olduğu için doğrudan seçilmiş, başka algoritma denenmemiştir. Sunumu yapan öğrenci bunu biraz garip bulduğunu söyler. Karşılaştırılan altı öznitelik kümesi şunlardır:

**1. Price only.** Yalnız tarihsel fiyatlar alınır ve bir patern olup olmadığına bakılır. Her gün önceki güne dayanılarak sonraki gün tahmin edilir. Bu öznitelik temel oluşturur ve hep modelde kalır; diğerleri bunun üstüne eklenir.

**2. Human sentiment.** Kullanıcının kendi verdiği duygu etiketleri (%15'lik kısım) kullanılır. Her etiketin oranı hesaplanır (örneğin strong buy sayısı bölü bütün mesajlar) ve modele eklenir.

**3. Sentiment classification.** Etiketi olmayan %85'lik kısım için duygu çıkarılır. Beş sınıf vardır: alış, satış, güçlü alış, güçlü satış ve pozisyonu korumayı anlatan "hold". Lemmatization yapılır ve Stanford CoreNLP kullanılır. Lemmatization, stemming'e benzer ama morfolojik analizle kelimenin sözlükteki kökünü bulmaya çalışır; bu yüzden büyük bir sözcük kaynağına ihtiyaç duyar. Sınıf yüzdeleri hesaplanıp modele verilir.

**4. LDA-based.** Latent Dirichlet Allocation bir konu modellemesi (topic modeling) yöntemidir. Yorumlar lemmatize edilir, kelimeler modele verilir ve kelime temelli konular üretilir. En az çıkan konular elenir. Gibbs örnekleme (Gibbs sampling) ile 1000 iterasyonda 50 konu seçilir. Her yorumun bu konulara ait olma olasılığı hesaplanıp modele eklenir.

> **Ek bilgi (derste anlatılmadı):** LDA üretken (generative) bir olasılıksal modeldir. Her belgenin konuların bir karışımı, her konunun da kelimelerin bir dağılımı olduğunu varsayar. Gibbs örnekleme, bu modelin gizli konu atamalarını tahmin etmek için kullanılan yöntemlerden biridir.

**5. JST-based.** Joint Sentiment-Topic modeli konu ve duyguyu birlikte ele alır. LDA'dan farkı şudur: LDA'da her yorum bir olasılık alır, JST'de her cümle ayrı ele alınır. Beş cümlelik bir yorum beş ayrı birimdir. Üç duygu tanımlıdır: up, down ve nötr. Yine lemmatization yapılır ve olasılıklar cümle düzeyinde hesaplanır, bu yüzden daha fazla hesap gerekir.

**6. Aspect-based sentiment.** Konular ve duygular birlikte çıkarılır. "Profit will go up" cümlesinde konu "profit", duygu "up"tır; yani (profit, up) çifti oluşur. Üç duygu vardır: pozitif, negatif, nötr. Etkisiz kelimeler atıldıktan sonra her kelimenin anlamına bakılır, her cümle için bir duygu ve o duygunun konusu çıkarılır, olasılıklar hesaplanıp modele eklenir.

### 4.5 Sonuçlar

İlk dört yöntem temel model (baseline), son ikisi (JST-based ve aspect-based) makalenin önerdiği modellerdir. Bütün değerler doğruluktur (accuracy) ve 18 şirket için ayrı hesaplanıp ortalaması alınmıştır.

<!-- BELİRSİZ: Şirket bazlı sonuç tablosu slaytta. Altyazıda yalnız aşağıdaki değerler geçiyor; %64 ve %66 gibi değerlerin hangi hisseye ait olduğu tam izlenemiyor. -->

- En iyi ortalama aspect-based sentiment'tedir: yaklaşık %54.
- Human sentiment bu değere çok yakındır. Sunum yapan öğrenci bunu en dikkat çekici sonuç olarak görür, çünkü yalnız %15'lik kullanıcı etiketiyle bile iyi sonuç alınmaktadır. Bazı hisselerde %64-66 gibi değerler görülür.
- Bazı hisselerde başarı %70-71'e çıkar; Amazon bunlardan biridir. Bu oran, piyasa tahmini için çok yüksektir.
- Model tek bir hisse için kullanılabilir: bir yöntem her hissede başarılı değildir, ama belirli bir hissede iyi olabilir.

Piyasa çok faktörlüdür. Yalnız fiyat ve insan duygusuyla tam tahmin edilemez. Gelecek çalışma olarak şirketlerin yatırım ve anlaşma verilerinin eklenmesi önerilir. Çıktı yalnız up ve down'dur; ileride "stabil" gibi sınıflar eklenebilir.

### 4.6 Soru-Cevap

**Soru (hoca):** Böyle bir çalışma ülkemiz koşullarında ne kadar başarılı olur?

**Cevap (öğrenci):** Konu çok faktörlüdür. Türkiye gibi belirsizliği yüksek bir ülkede uzun vadeli yatırım ve büyük anlaşmalar azdır. Bu durum, haberlerin öngörülemez olduğunu söyleyen Etkin Piyasa Hipotezi'ni destekler. Öğrenci, kendi tez konusunun da TL tahmini olduğunu söyler.

## 5. Dördüncü Sunum: Anahtar Kelime Listeleriyle Denetimsiz Metin Sınıflandırma

### 5.1 Çalışmanın Motivasyonu

Sunum yapan öğrenci, makalenin 2000 yılına ait olduğunu ve seçerken tarihine bakmadığını söyler. Hoca, en azından alanın nereden nereye geldiğinin görüleceğini belirtir.

O dönemde metin sınıflandırma denetimli yapılmaktadır ve önceden tanımlı kategori etiketlerini atamak için çok fazla etiketli belge gerekir. Haber, makale, web sayfası ve e-posta gibi alanlarda bu veriyi elle hazırlamak zor ve maliyetlidir. Önerilen yöntem her kategori için yalnız bir anahtar kelime listesi kullanır. Belgeler cümlelere bölünür ve cümle benzerliğiyle otomatik eğitim kümesi oluşturulur.

Çalışmanın iddiası başarımı artırmak değildir. Amaç, maliyeti düşürüp denetimli yöntemlere yakın bir başarım elde etmektir.

### 5.2 Mimari

Sistem üç aşamadan oluşur: ön işleme, eğitim kümesi üretme, öznitelik seçimi ve sınıflandırma. Yaklaşık 2000 kelimeyle eğitim yapılmıştır.

**Ön işleme.** Genel kelimeler çıkarılır, özel karakterler ayrılır, cümleler bölünür ve içerik kümesi oluşturulur. Yazarlar Korelidir. Dillerinde bazı sıfat ve fiiller isim olarak sayılabildiği için sözcük türü etiketine göre bunlar da alınır.

**Eğitim kümesi üretme.** Temsili cümleler çıkarılır, doğrulanır ve genişletilir:

- Terim frekansı ile ters kategori frekansının birleşimi olan TF-ICF değerleri hesaplanır.
- Cümleler ağırlığa göre azalan sırayla dizilir.
- Temsili cümlelerin ilk %70'i seçilir. Yazarlar bu oranı deneysel olarak belirlediklerini söyler. Sunum yapan öğrenci bunun başarımın düşmemesi için yapıldığını düşünür.
- Temsili cümleler kelime ve cümle benzerliğiyle genişletilir. Kelime ağırlıklarında global frekans, log olasılık ve sözcük türü kullanılır.
- Bir kısım cümle sınıfsız kalır. Bunlar ikinci geçişte en yakın oldukları sınıfa atanır.

<!-- BELİRSİZ: TF-ICF, benzerlik ve kelime ağırlığı formülleri slaytta kapatılmış; altyazıda okunmuyor. -->

**Öznitelik seçimi ve sınıflandırma.** Öznitelik seçimi $\chi^2$ ile yapılır. Sınıflandırıcı Naive Bayes'tir ve Kullback-Leibler ıraksaması ile küçük bir iyileştirme yapılarak başarım biraz yükseltilmiştir.

> **Ek bilgi (derste anlatılmadı):** Kullback-Leibler ıraksaması iki olasılık dağılımı arasındaki farkı ölçer: $D_{KL}(P \| Q) = \sum_x P(x) \log \frac{P(x)}{Q(x)}$. İki dağılım aynıysa sonuç sıfırdır.

### 5.3 Sonuçlar

2000 kelimelik sözlükte önerilen yöntem %71,8, denetimli öğrenme %75,6 başarı elde etmiştir. Aradaki fark $75{,}6 - 71{,}8 = 3{,}8$ puandır. Sözlük büyüdükçe fark açılır (örneğin 10.000 kelimede). Yazarlar yöntemi küçük sözlükler ve etiketleme maliyetinin yüksek olduğu, düşük maliyetli metin sınıflandırma gereken alanlar için önerir.

### 5.4 Hocayla Tartışma

**Soru (hoca):** Başlıkta "unsupervised" geçiyor. Peki denetimsiz olan yöntem hangisi? Naive Bayes denetimli bir yöntemdir.

**Cevap (öğrenci):** Önceki çalışmalarda elle etiketleme gerekiyordu. Bu çalışmada yalnız anahtar kelime listesi veriliyor. Otomatikleştirilen ve denetimsiz olan kısım, ortadaki eğitim kümesi oluşturma aşamasıdır. Naive Bayes bu işlenmiş veri üzerinde çalışır.

**Soru (hoca):** Anahtar kelime listesine bakarak dokümandaki kelimelere göre etiket mi veriyor?

**Cevap (öğrenci):** Kategori oluşturuyor. Hoca bunu etiket vermek olarak yorumlar ve 21 sene önceki teknolojiyi hatırlatır.

Hoca öğrenciye bildiği denetimsiz bir yöntem sorar. Öğrenci hemen hatırlayamaz. Hoca K-Means'i hatırlatır. Öğrenci makalede anılan KNN ve SVM'ye değinince hoca bunların denetimli yöntemler olduğunu söyler.

> **Hocanın vurgusu:** Denetimsiz öğrenme konuşuluyorsa en azından K-Means'i bilin. Başlığında "unsupervised" geçen bir çalışmada denetimsiz kısmın nerede olduğunu açıklayabilmelisiniz.

## 6. PCA ve Kümeleme Üzerine Soru-Cevap

**Soru (bir öğrenci):** PCA metodu da denetimsiz bir yöntem olarak geçiyor, doğru mu?

**Cevap (hoca):** Sınıf bilgisini kullanmaz, yani etiket bilgisi kullanmaz. Ama bir özellik çıkarma (feature extraction) yöntemidir. Tam bir kümeleme modelinden söz ediyorsak K-Means ve X-Means bunlardandır.

> **Ders sonrası not:** Hoca burada "supervised sınıf bilgisini kullanmaz" dedi; kastı "unsupervised"tır. Hoca ayrıca PCA'nın "en ayırt edici özellikleri seçtiğini" söyledi. PCA var olan özelliklerden seçim yapmaz, onların doğrusal birleşimlerinden yeni bileşenler üretir. Bu bileşenler en yüksek varyansı taşır; sınıf etiketi kullanılmadığı için sınıfları ayırt etmeleri garanti değildir.

## 7. Beşinci Sunum: Çift Yönlü LSTM ile Kelime Anlamı Belirginleştirme

### 7.1 Problem ve Kavramlar

Makale 2016 tarihlidir ve yaklaşık 155 atıf almıştır. Bilgisayarın bir dokümanı anlayabilmesi için önce kelimelerin hangi anlamda kullanıldığını anlaması gerekir. Bu problem kelime anlamı belirginleştirmedir (word sense disambiguation, WSD). Örneğin "cold" kelimesi duygu anlamında mı, yoksa havanın sıcaklığı anlamında mı kullanılmıştır?

Sunumda şu kavramlar açıklanır:

- **LSTM (Long Short-Term Memory):** Geçmişteki kelimeleri de hesaba katan bir RNN türüdür.
- **Çift yönlü LSTM:** Metni hem soldan sağa hem sağdan sola işler. Makale, iki yönlü işlemenin başarıyı artıracağını savunur.
- **GloVe:** Kelimeleri vektörle gösteren, anlamsal gösterim sağlayan, denetimsiz öğrenilen bir yöntemdir. Eğitim kümesi çok büyük olduğu için özellikle İngilizcede sık tercih edilir.
- **DropWord:** Kelime düzeyinde bir düzenleme (regularization) yöntemidir. Word dropout, atılacak kelimeleri sıfır yapar ve kelime hiç yokmuş gibi işlem görür. DropWord ise bu kelimeleri tek bir ortak etiketle değiştirir. Etkisiz kelimeler ya da çok sık veya çok az geçen kelimeler silinmek yerine tek bir kelimeymiş gibi modele verilir. Makale bunun başarıyı biraz artırdığını söyler.

### 7.2 Model

Her kelimenin one-hot gösterimi ağırlıkla çarpılarak girdi hesaplanır. One-hot gösterim, bir biti 1, geri kalanı 0 olan ve her kelime için farklı olan bir bit grubudur. Akış şöyledir:

```text
one-hot girdi
  -> embedding
  -> soldan sağa LSTM + sağdan sola LSTM
  -> representation layer (birleştirme)
  -> softmax layer
  -> çıktı
```

<!-- BELİRSİZ: Modelin matematiksel gösterimi slaytta, sunum yapan öğrenci de üzerinde durmuyor. -->

### 7.3 Deney

Testler Senseval-2 ve Senseval-3 veri setlerinde yapılmıştır. Öğrenciye göre Senseval-2'de yaklaşık 7000, Senseval-3'te 11-12 bin doküman vardır; bu sayıları "doğru hatırlıyorsam" diye verir. Veri setlerindeki sayılar tek bir "number" etiketiyle değiştirilir; böylece bütün sayılar tek bir kelime gibi işlem görür. Bu işlemden sonra Senseval-2'de 50.000 küsur kelime, Senseval-3'te 378.000 kelime elde edilir.

Bağlam olarak hedef kelimenin solundan ve sağından 70'er kelime, toplam 140 kelime alınır. Veri setlerindeki dokümanlar kısa olduğu için birçok dokümanda zaten bütün kelimelere bakılır. Öğrenci bu yüzden 140 sınırını bu makale için pek belirleyici bulmaz.

Gömme işleminde GloVe kullanılır. Hiperparametreler deneme yanılmayla bulunur: embedding boyutu 100-200 arasında, gizli katman boyutu 50-100 arasında denenir.

### 7.4 Sonuçlar

Makale yalnız F1 skorunu paylaşır. Önerilen model, karşılaştırılan üç yöntemden hem Senseval-2 hem Senseval-3'te daha iyi ya da onlarla aynıdır. Farklar büyük değildir.

<!-- BELİRSİZ: Karşılaştırılan üç yöntemin adları ve F1 tablosu slaytta; öğrenci de "okuyamadığım karışık üç metot" diyor. Altyazıda yalnız 66-73 aralığına değiniliyor. -->

Bileşenlerin etkisini görmek için model bunlar olmadan da denenir:

- DropWord çıkarılınca veya yerine başka bir yöntem konunca F1 fazla değişmez. Zaman veya bellek sıkıntısı varsa DropWord'den vazgeçilebilir.
- GloVe ve kelime sırası başarıyı büyük ölçüde etkiler. Bu ikisi model için çok önemlidir.

### 7.5 Sunum Yapan Öğrencinin Eleştirileri

**Yalnız F1 verilmesi.** Doğruluk, kesinlik ve duyarlılık paylaşılmamıştır. F1 bunların birleşiminden oluşsa da model seçerken bu değerler de işe yarar.

> **Ek bilgi (derste anlatılmadı):** F1, kesinlik ve duyarlılığın harmonik ortalamasıdır: $F_1 = \frac{2 \cdot P \cdot R}{P + R}$. Doğruluk ise bu formülde yer almaz; F1 yalnız kesinlik ve duyarlılıktan hesaplanır.

**Dilden bağımsızlık iddiası.** Makale modeli dilden bağımsız ve kaynağı az olan diller için uygun diye sunar, ama yalnız İngilizcede test eder. Yazar başka dillerde deneme yapılmasını gelecek çalışma olarak bırakır. Öğrenci, iki ay önce yayımlanmış Urduca bir çalışmada F1'in yaklaşık %49,2 çıktığını söyler ("doğru hatırlıyorsam"). Bu, modelin dilden bağımsız olmadığı izlenimini verir. Ama öğrenci, başka modellerin de Urducada düşük sonuç verdiğini fark ettiğini ekler; yani bu Urducaya özgü olabilir. Atıflar arasında başka dilde çalışma bulamadığını da belirtir.

### 7.6 Soru-Cevap

**Soru (hoca):** Senseval veri setlerini çalışmalarında kullandığını söyledin. Ne çalışmıştın?

**Cevap (öğrenci):** Lisans bitirme tezimde WSD üzerine çalıştım. 2004 civarında SVM için önerilen bir kernel'ı PCA için uyguladık. PCA ile KNN kullanınca, KNN normalde SVM'den zayıf bir sınıflandırıcı olmasına rağmen, SVM'den daha iyi sonuç aldık.

Hoca öğrenciye ders projesini sorar. Proje, içerik benzerliklerinin çıkarılmasıdır: aynı olayı anlatan, farklı kaynaklardan gelen haber dokümanlarının birbirine ne kadar benzediğini ölçmek. Örneğin bir olay birçok kaynakta haberleştirildiğinde bu metinlerin benzerlikleri karşılaştırılacaktır.

## 8. Dersin Toparlaması

Bu derste sunulan beş çalışmanın ortak ekseni metinden anlam çıkarmaktır. İlk üç sunum sosyal medyadan duygu çıkarır: 5G algısı, şirket olayları ve hisse senedi hareketi. Bu üç çalışmada TextBlob, SentiStrength ve AFINN gibi sözlük tabanlı araçlar, klasik makine öğrenmesi yöntemleri ve derin öğrenme yan yana görülür. Üçüncü sunum, duygu bilgisinin fiyat verisine eklenince tahmine katkı sağladığını, ama piyasanın çok faktörlü olduğunu gösterir. Dördüncü sunum etiketleme maliyetini düşürmek için anahtar kelime listesinden otomatik eğitim kümesi üretir. Beşinci sunum ise kelime düzeyinde anlam belirginleştirmeye çift yönlü LSTM ile yaklaşır.

Hocanın sunumlar arasında öne çıkardığı noktalar şunlardır: denetimli ve denetimsiz yöntem ayrımı net olmalıdır, en azından K-Means bilinmelidir, PCA bir özellik çıkarma yöntemidir ve kümeleme modeli değildir. Çalışmaların başarı değerleri de bağlamıyla okunmalıdır; aynı yöntem bazı hisselerde veya dillerde çok iyi, bazılarında düşük sonuç verebilir.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.

## 9. Ders Sonrası Notlar

> **Ders sonrası not:** Birinci sunumda bildirinin konferansı "Innovations in Intelligence System and Application" diye okundu; yaygın adı INISTA, yani "Innovations in Intelligent Systems and Applications"tır.

> **Ders sonrası not:** Birinci sunumda 1G için "1970-1979 yılında" denildi. Slayttaki tarih aralığı altyazıdan doğrulanamıyor; bu nedenle notta tarih verilmedi.

> **Ders sonrası not:** Birinci sunumda "yinelenen sinir ağları" ve "tekrarlayan sinir ağları" aynı yöntem için kullanıldı: RNN. "Kernel tricks" için söylenen "çekirdek numarası" da altyazıda bozuk geçiyor.

> **Ders sonrası not:** İkinci sunumda çok popüler olmayan kullanıcıya örnek olarak Ray Dalio gösterildi ve "herkesin bildiği bir kişi değil" denildi. Ray Dalio aslında dünyaca tanınan bir yatırımcıdır. Sunumdaki ifade, makalenin seçim ölçütünü anlatmak için söylenmiş olabilir.

> **Ders sonrası not:** İkinci sunumda Twitter sınırının 140 karakter olduğu söylendi. Bu, çalışmanın yapıldığı dönem için doğrudur; sınır 2017'de 280 karaktere çıkarılmıştır.

> **Ders sonrası not:** İkinci sunumda SentiStrength "Python tabanlı" diye anıldı. Bu aracın yaygın bilinen sürümü büyük olasılıkla Java ve Windows içindir; bu bilgi derste doğrulanmadı. Ayrıca aynı sunumda "1-gram ve 1-gram puanları toplanıyor" diye geçen yerin doğrusu unigram ve bigram'dır.

> **Ders sonrası not:** Üçüncü sunumda yazarlar için "iki Japon akademisyen ve sanırım İngiliz" denildi. Makalenin yazarları büyük olasılıkla Thien Hai Nguyen, Kiyoaki Shirai ve Julien Velcin'dir; son yazar Fransa'da çalışmaktadır. Yazar bilgisi altyazıdan doğrulanamadığı için kesin değildir.

> **Ders sonrası not:** Üçüncü sunumda LDA için "doküman regresyon yapıyor" ve JST için "regresyon tarzı" denildi. LDA bir regresyon yöntemi değil, üretken olasılıksal konu modelidir.

> **Ders sonrası not:** Üçüncü sunumda Etkin Piyasa Hipotezi için "%50'nin üzerine çıkamazsınız" denildi. Hipotez bu rakamı söylemez; piyasanın sürekli yenilemeyeceğini söyler. %50, iki sınıflı (up/down) tahminde rastgele tahminin beklenen başarısıdır. Aynı sunumda ortalama başarı olarak verilen yaklaşık %54 de bu nedenle bu eşiğe göre okunmalıdır.

> **Ders sonrası not:** Üçüncü sunumda Apple için günlük ortalama 1678 yorumun yaklaşık 350'sinde duygu olduğu söylendi. Bu oran $350/1678 \approx \%20{,}9$'dur (ara adım eklendi); "%15" değeri bütün mesajların genel oranıdır, Apple'a ait değildir. Ayrıca kalan yorum sayısı tam olarak $1678 - 350 = 1328$'dir (ara adım eklendi); sunumda yaklaşık olarak 1300 denildi.

> **Ders sonrası not:** Dördüncü sunumda "Kulbak-Liber-Divergence"ın "bu adamın formülü" olduğu söylendi. Ad iki kişiden gelir: Solomon Kullback ve Richard Leibler.

> **Ders sonrası not:** Beşinci sunumda DropWord'ün stop word gibi belirli kelimelere uygulandığı anlatıldı. Özgün yöntem büyük olasılıkla kelimeleri olasılıkla rastgele düşürür ve kelimeyi sıfırlamak yerine tek bir etiketle değiştirir. Bu ayrıntı altyazıdan doğrulanamadığı için kesin değildir.

> **Ders sonrası not:** Beşinci sunumda "SVM'den daha iyi" anlatılırken geçen "PCI" ve "K&N" ifadeleri bağlama göre PCA ve KNN'dir. Öğrenci "WST" dediğinde kastı WSD'dir.

> **Ders sonrası not:** Altyazıda bozuk geçen terimlerin doğruları: "Nive-Bias / Nyer Bayes" Naive Bayes; "TF-IDP / Tf7" TF-IDF; "TextBlock" TextBlob; "Sentis Strengths / Sentisiz renk" SentiStrength; "Affin" AFINN; "G-POMS" GPOMS; "GPT sampling" Gibbs sampling; "CST" JST; "streaming" stemming; "LDR" LDA; "Latent Drill Allocation" Latent Dirichlet Allocation; "NeuBiOS" Naive Bayes; "X kare" $\chi^2$; "Sensable / Sensival / Samseval" Senseval; "Heiden layer" hidden layer; "DropIt" dropped etiketi.
