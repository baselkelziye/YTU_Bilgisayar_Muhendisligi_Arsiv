# Ders 5 Çalışma Özeti

## Genel Konular

- Ders 29 Aralık 2021 tarihlidir. Ders tamamen öğrenci seminer sunumlarından oluşur.
- Her sunum en fazla 20 dakikadır. Hoca süre aşımına ve gereksiz ayrıntıya müdahale eder.
- Bu derste beş makale sunulur:
  - 1. sunum: Twitter'da 5G teknolojisine yönelik duygu analizi (sentiment analysis).
  - 2. sunum: Twitter'daki finansal topluluğun tweetlerinden şirket olaylarının tespiti.
  - 3. sunum: Sosyal medya duygu analiziyle hisse senedi hareketi tahmini (stock movement prediction).
  - 4. sunum: Anahtar kelime listeleriyle denetimsiz (unsupervised) metin sınıflandırma.
  - 5. sunum: Çift yönlü LSTM (bidirectional LSTM) ile kelime anlamı belirginleştirme (word sense disambiguation, WSD).
- Ortak temalar: Twitter verisi, ön işleme (pre-processing), sözlük tabanlı duygu araçları, klasik makine öğrenmesi ile derin öğrenmenin karşılaştırılması.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınıfın zaten bildiği yöntemleri (Naive Bayes, SVM vb.) sunumda tek tek anlatmayın. "Bu yöntemler kullanılmıştır" deyip geçin.
- Cümleleri uzatmayın, "ağdalı" anlatmayın. 20 dakikayı aşmayın.
- Naive Bayes denetimli (supervised) bir yöntemdir. Başlığında "unsupervised" geçen bir çalışmada denetimsiz kısmın tam olarak nerede olduğunu açıklayabilmelisiniz.
- Denetimsiz yöntem olarak en azından K-Means'i bilin.
- PCA (Principal Component Analysis) sınıf etiketini kullanmaz. Ama bir kümeleme modeli değil, öznitelik çıkarma (feature extraction) yöntemidir. Kümeleme örnekleri K-Means ve X-Means'tir.
- "Döküman" değil "doküman" yazılır. Hoca bu hatayı kendi doktora tezinde yaptığı için danışmanından uyarı aldığını anlatır.
- Sunumlar Drive'a yüklenmelidir.
- Proje zamanında yetişmezse öğrenci hocaya haber verir ve bütünleme sınavına girer.

## Kısa Tekrar Notları

- TWINT: Twitter'dan anahtar kelime, hesap ve tarih aralığına göre tweet çeken araç.
- TextBlob: Python NLP kütüphanesi. Polarite (polarity) $[-1, 1]$, öznellik (subjectivity) $[0, 1]$ aralığındadır.
- Sözlük tabanlı duygu araçları: Sentiment140, TextBlob, SentiStrength, AFINN.
- SentiStrength: kısa sosyal web metinleri için. Olumlu puan $+1$..$+5$, olumsuz puan $-1$..$-5$.
- AFINN: 2477 kelimelik sözlük. Puanlar $-5$..$+5$.
- Etkin Piyasa Hipotezi (Efficient Market Hypothesis): fiyatlar haberlere bağlıdır ve haberler öngörülemez. Bu yüzden tahmin başarısı %50 civarında kalır.
- Temel analiz (fundamental analysis): şirketin yatırımları, anlaşmaları, büyümesi.
- Teknik analiz (technical analysis): geçmiş fiyat grafiği, destek ve direnç seviyeleri.
- LDA (Latent Dirichlet Allocation): konu modelleme (topic modeling). JST (Joint Sentiment-Topic): konu ve duyguyu birlikte modeller.
- Lemmatization: kelimenin sözlükteki kök biçimini morfolojik analizle bulur. Stemming ekleri kurala göre keser.
- TF-ICF: terim frekansı ile ters kategori frekansının (inverse category frequency) birleşimi.
- WSD: bir kelimenin bağlamda hangi anlamda kullanıldığını bulma problemi. Örnek: "cold" kelimesi duygu anlamında mı, sıcaklık anlamında mı?
- GloVe: denetimsiz öğrenilen kelime vektörleri (word embedding).
- DropWord: sık veya etkisiz kelimeleri silmek yerine tek bir `<dropped>` benzeri etiketle değiştiren düzenlileştirme (regularization) yöntemi.

## Detaylı Açıklamalar

### 1. sunum: 5G Teknolojisinin Twitter'da Duygu Analizi

- Makale: "The Evolution of 5G Technology from Sentiment Analysis Perspective in Twitter". 2020 INISTA konferansında sunulmuş, IEEE'de yayımlanmıştır. Yazarlar Kocaeli Üniversitesi'ndendir.
- Amaç: toplumun 5G'ye bakışını ölçmek. 5G hakkında siber güvenlik, uyumluluk ve radyasyon endişeleri vardır.
- Çalışma "olumlu mu olumsuz mu" sonucuna varmaz. Yalnız sınıflandırıcıların başarısını karşılaştırır.
- Veri:
  - TWINT ile İngilizce, 5G etiketli tweetler çekilmiştir.
  - Tarih aralığı: 01.01.2019 – 30.05.2020.
  - 100.000 tweet toplanmış, nötr tweetler çıkarılınca 58.965 tweet kalmıştır.
- Ön işleme: düzenli ifadelerle (regular expressions) URL, hashtag, emoji ve semboller silinmiştir. Etkisiz kelimeler (stop words) atılmıştır.
- Etiketleme: TextBlob polaritesine göre yapılmıştır. Negatif $= 0$, pozitif $= 1$, nötr $= 2$.
- Vektörleştirme: TF-IDF.
- Yöntemler: Naive Bayes (Gaussian, Bernoulli, Multinomial), SVM (linear, RBF, polynomial kernel), KNN ($k = 3, 5, 7$), RNN.
- Sonuçlar:
  - Naive Bayes içinde en iyisi Bernoulli. Multinomial yaklaşık %1 geride, Gaussian yaklaşık %19-20 geride.
  - SVM içinde en iyisi linear kernel: %75,10.
  - KNN içinde en iyisi $k = 5$: %73,08.
  - Genel sıra: SVM > KNN > Naive Bayes.
  - RNN tüm klasik yöntemlerden iyidir: %78,35 doğruluk.
- Hoca sunum sırasında ayrıntılı yöntem anlatımını kesip özet istemiştir.

### 2. sunum: Twitter'daki Finansal Topluluktan Şirket Olaylarının Tespiti

- Amaç: Dow Jones endeksindeki 30 büyük şirketle ilgili tweetlerden şirketlerin popülerliğini ve olayların etkisini ölçmek.
- Sistem beş bloktan oluşur: finansal topluluk, tweet filtresi, duygu analizi, normalizasyon, olay tespiti.
- Finansal topluluk seçimi:
  - Kullanıcının takipçi sayısı takip ettiği sayıdan fazla olmalıdır.
  - Çok popüler hesaplar alınmaz. Bu hesapların tweetleri genelde nötrdür, zaten Bloomberg ve CNBC gibi kaynaklarda bulunur.
- Tweet filtresi:
  - Şirket adı, borsa kodu ve `$` simgeli kod gibi anahtar kelimeler aranır.
  - Investopedia'ya dayanan 865 kelimelik finans sözlüğü kullanılır. Böylece "Apple" kelimesinin şirket mi meyve mi olduğu ayrılır. Örneğin "Apple juice" geçen tweet alınmaz.
  - Her şirket için ayrı bir dosya oluşturulur, toplam 30 dosya.
- Dört duygu aracı karşılaştırılır:
  - My Sentiment API (Java).
  - Sentiment140: 1,6 milyon tweetle eğitilmiş. Unigram ve bigram puanlarını toplar.
  - TextBlob.
  - SentiStrength: 5 kategori; aşırı negatif ve aşırı pozitif sınıfları da vardır.
  - AFINN de anlatılır. Sunumda "dört araç" dense de beş araç sayılmıştır.
- Normalizasyon: Twitter kullanımı zamanla arttığı için günlük skor, son 3 ayın ortalama tweet hacmine bölünür.
- Veri: 9000'den fazla kullanıcı ve yaklaşık 2 yıllık, 12 milyondan fazla tweet. Filtre sonrası 192.935 tweet kalır.
- Vaka çalışmaları:
  - Apple: zirveler iPhone 6'nın çıkışı ve akıllı saatin tanıtımıyla örtüşür.
  - Microsoft: Nokia'nın satın alınması öne çıkar. 18.000 kişilik işten çıkarma duyurusu negatif tepe olarak görülür.
  - Walmart da incelenmiştir.
- Sonuç: duygu araçları Google Trends ile birleştirilince finansal olaylar başarıyla tespit edilir.
- Hoca sunumu beğenmiştir.

### 3. sunum: Sosyal Medya Duygu Analiziyle Hisse Senedi Hareketi Tahmini

- Makale: "Sentiment Analysis on Social Media for Stock Movement Prediction", 2015, Elsevier.
- Fikir: piyasayı toplumun ruh hali (mood) de etkiler. Duygu bilgisi fiyat verisine öznitelik olarak eklenir.
- Teknik ve temel analiz birleştirilir:
  - Teknik kısım: tarihsel fiyatlar (açılış, kapanış, en yüksek, en düşük).
  - Temel kısım: mesajlardaki duygu bilgisi.
- Veri:
  - 18 büyük şirket (Apple, Amazon, Dell vb.).
  - Yahoo Finance Message Board'dan 23.07.2012 – 19.07.2013 arası mesajlar.
  - Hafta sonları piyasa kapalıdır. Toplam 249 işlem günü vardır.
- Twitter yerine mesaj panosu seçilmiştir. Gerekçe: Twitter verisi dağınık ve yazım hatalıdır.
- Mesajların yalnız %15'inde kullanıcı açık bir duygu etiketi verir: strong buy, buy, sell, strong sell (ve hold).
- Model: SVM. Yüksek boyutlu veride başarılı olduğu için seçilmiş; başka algoritma denenmemiştir.
- Altı öznitelik kümesi karşılaştırılır:
  - Price only: yalnız fiyat. Temel model, hep korunur.
  - Human sentiment: %15'lik etiketli mesajlardaki etiket oranları.
  - Sentiment classification: etiketsiz %85'lik kısım için 5 sınıflı sınıflandırma. Lemmatization için Stanford CoreNLP kullanılır.
  - LDA-based: Gibbs örnekleme (Gibbs sampling), 1000 iterasyon, 50 konu. Her mesajın konu olasılıkları öznitelik olur.
  - JST-based: konu-duygu çiftleri cümle düzeyinde. 3 duygu: up, down, nötr.
  - Aspect-based sentiment: "profit will go up" gibi cümlelerden (konu, duygu) çifti çıkarılır. Örnek: (profit, up).
- Sonuçlar:
  - Ortalama doğrulukta en iyisi aspect-based sentiment. Ortalama yaklaşık %54.
  - Bazı hisselerde %70-71'e çıkar, örneğin Amazon.
  - Human sentiment de en iyi yönteme oldukça yakındır.
  - Çıktı yalnız up ve down'dur. Gelecekte "stabil" gibi sınıflar eklenebilir.
- Hocanın sorusu: Bu çalışma Türkiye koşullarında ne kadar başarılı olur?
  - Öğrencinin yanıtı: Türkiye gibi belirsizliği yüksek bir ülkede haberler daha da öngörülemez. Bu durum Etkin Piyasa Hipotezi'ni destekler.
  - Öğrencinin tez konusu TL tahminidir.

### 4. sunum: Anahtar Kelime Listeleriyle Denetimsiz Metin Sınıflandırma

- Makale yaklaşık 2000 yılına aittir. Yazarlar Korelidir.
- Sorun: denetimli sınıflandırma çok miktarda etiketli veri ister. Haber, web sayfası ve e-posta için bu veriyi elle hazırlamak pahalıdır.
- Önerilen yöntem:
  - Her kategori için yalnız bir anahtar kelime listesi verilir.
  - Belgeler cümlelere bölünür. Cümle benzerliğiyle otomatik eğitim kümesi oluşturulur.
  - Amaç başarıyı artırmak değil, maliyeti düşürüp denetimli yöntemlere yakın başarı almaktır.
- Mimari:
  - Ön işleme: genel kelimeler ve özel karakterler atılır, cümleler ayrılır.
  - Korece'de bazı sıfat ve fiiller isim gibi davrandığı için POS etiketine göre bunlar da alınır.
  - Temsili cümleler TF-ICF ağırlığıyla azalan sırada dizilir. İlk %70'i seçilir; bu oran deneysel olarak belirlenmiştir.
  - Temsili cümleler kelime ve cümle benzerliğiyle genişletilir. Sınıfsız kalan cümleler en yakın sınıfa atanır.
  - Öznitelik seçimi $\chi^2$ ile yapılır. Sınıflandırıcı Naive Bayes'tir; Kullback-Leibler ıraksaması (divergence) ile iyileştirilmiştir.
- Sonuç (2000 kelimelik sözlük):
  - Önerilen yöntem %71,8, denetimli öğrenme %75,6. Fark 3,8 puandır.
  - Sözlük büyüdükçe (örneğin 10.000 kelime) fark açılır. Bu yüzden yöntem küçük sözlükler ve düşük maliyet gereken alanlar için önerilir.
- Hoca ile tartışma:
  - Naive Bayes denetimlidir. Denetimsiz kısım, anahtar kelime listesinden otomatik eğitim kümesinin üretildiği orta aşamadır.
  - Hoca K-Means'i hatırlamasını ister.
  - Bir öğrencinin sorusu üzerine hoca PCA ile kümelemeyi ayırır (bkz. Vurgulananlar).

### 5. sunum: Çift Yönlü LSTM ile Kelime Anlamı Belirginleştirme

- Makale 2016 tarihlidir ve yaklaşık 155 atıf almıştır.
- Kavramlar:
  - LSTM (Long Short-Term Memory): geçmiş kelimeleri hatırlayan bir RNN türü.
  - Çift yönlü LSTM: metni hem soldan sağa hem sağdan sola işler.
  - GloVe ile kelime gömmeleri (embedding) üretilir.
  - DropWord: Word dropout kelimeyi sıfırlar. DropWord ise kelimeyi tek bir ortak etiketle değiştirip modele yine verir.
- Model akışı: one-hot girdi → embedding → iki yönlü LSTM → birleştirme (representation layer) → softmax → çıktı.
- Deney:
  - Veri: Senseval-2 ve Senseval-3.
  - Sayılar tek bir `<number>` etiketiyle değiştirilir.
  - Hedef kelimenin solundan ve sağından 70'er kelime, toplam 140 kelime bağlam alınır. Belgeler kısa olduğu için bu sınır pek belirleyici değildir.
  - Hiperparametreler deneme yanılmayla bulunur. Örnek: embedding boyutu 100-200, gizli katman 50-100.
- Sonuçlar:
  - Yöntem karşılaştırılan üç yöntemden daha iyi ya da onlarla aynıdır. Farklar küçüktür.
  - Ablasyon: DropWord çıkarılınca F1 az değişir; zaman veya bellek sıkıntısında atlanabilir. GloVe ve kelime sırası ise başarıyı belirgin biçimde etkiler.
- Öğrencinin eleştirileri:
  - Yalnız F1 verilmiş; accuracy, precision ve recall verilmemiştir.
  - Model "dilden bağımsız" diye sunulmuş ama yalnız İngilizcede denenmiştir. Urduca üzerine yapılan yeni bir çalışmada F1 yaklaşık %49,2 çıkmıştır. Urducada başka modeller de düşük sonuç verdiği için kesin bir yargı zordur.
- Hocanın soruları:
  - Öğrencinin önceki çalışması: lisans bitirme tezinde WSD üzerine kernel PCA kullanmıştır.
  - Ders projesi: aynı haberi veren farklı kaynaklardaki belgelerin benzerliğini ölçmek.
  - Hoca projeye henüz başlanmamasını eleştirmiştir.

### Ders sonrası notlar

- 1. sunumdaki "Nyer Bayes / Nive-Bias", "TF-IDP", "Dörte data" gibi ifadeler altyazı bozulmasıdır. Doğruları: Naive Bayes, TF-IDF, dirty data.
- 2. sunumdaki "Sentis Strengths", "Affin", "G-POMS" ifadelerinin doğruları: SentiStrength, AFINN, GPOMS (Google Profile of Mood States). GPOMS altı ruh hali boyutu ölçer: calm, alert, sure, vital, kind, happy.
- 2. sunumda Twitter'ın sınırı "140 karakter" denmiştir. Bu çalışmanın yapıldığı dönem için doğrudur; Twitter 2017'de sınırı 280 karaktere çıkarmıştır.
- 3. sunumda "LDA dokümanı regresyona sokuyor" denmiştir. Bu doğru değildir. LDA üretken (generative) bir olasılıksal konu modelidir; regresyon yapmaz.
- 3. sunumdaki "GPT sampling" Gibbs sampling'dir. "Streaming'in benzeri" ifadesindeki kelime de stemming'dir.
- 3. sunumdaki "CST" ve "GST" kısaltmalarının doğrusu JST'dir (Joint Sentiment-Topic).
- 5. sunumda "PCI" ve "K&N" diye geçen ifadeler bağlama göre PCA ve KNN olmalıdır. Bu kısım altyazıda tam anlaşılmıyor.
- 4. sunumdaki "Kulbak-Liber-Divergence" Kullback-Leibler divergence'dır. İki olasılık dağılımı arasındaki farkı ölçer: $D_{KL}(P \| Q) = \sum_x P(x) \log \frac{P(x)}{Q(x)}$.

### Duyurular

- Bir öğrenci beklenmedik bir toplantı nedeniyle sunum yapamamış, sunumu sonraki haftaya kalmıştır.
- Hoca regex ödevine ait düzeltmelerin kendisine ulaşmadığını söyler. İlgili öğrencilerin e-postalarını yeniden göndermelerini ister.
- Projeler finalde teslim edilir. Yetişmezse bütünleme sınavına girilir.
- Bazı öğrenciler derse katılamadığını bildirmiştir. Hoca Zoom katılımcı sınırı olabileceğini düşünüp izin verir.

İsterseniz bu özeti NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
