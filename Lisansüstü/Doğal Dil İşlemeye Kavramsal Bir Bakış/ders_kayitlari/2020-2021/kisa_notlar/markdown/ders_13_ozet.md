# Ders 13 Çalışma Özeti

## Genel Konular

- Bu ders (7 Ocak 2021) dönemin son dersidir. Öğrenci seminer sunumlarının üçüncü ve son haftasıdır. Konu anlatımı yoktur.
- Hoca kalabalık olunduğu için her sunumun 20 dakikayı geçmemesini ister.
- Bu derste 6 sunum yapılır (programdaki iki öğrenci derse katılmaz):
  - 1. sunum: Metinden duygu tespiti yaklaşımları üzerine bir derleme.
  - 2. sunum: Konu bölümleme (topic segmentation) algoritmalarının İngilizce ve Arapça için karşılaştırılması.
  - 3. sunum: Haber makalelerinde sözlük tabanlı duygu analizi.
  - 4. sunum: Türkçe metin sınıflandırma için kelime bölümleme (word segmentation) yöntemlerinin karşılaştırılması.
  - 5. sunum: Cümle tamamlama için bağımlılık tabanlı yinelemeli sinir ağı dil modelleri.
  - 6. sunum: Haber makalelerinde doküman düzeyinde duygu analizi.
- Ders sonunda hoca final günü yapılacak proje değerlendirmesini ve final tarihini konuşur.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Süreye uyun:** Sunumu uzatmak için ağırdan almayın. Dinleyicinin dikkati bir noktadan sonra dağılır.
- **Birlikte çalışmanın değeri:** 1. sunumda Aralık ayında olumlu paylaşımların arttığı sonucu tartışılır.
  - Hoca verinin hangi yarımküreden geldiğinin önemli olduğunu söyler. Aralık kuzeyde soğuk ve kasvetli, güneyde yazdır.
  - Sunucu ise yılbaşının etkisini düşünmüştür. Hoca "Birlikte iş yapmak böyle olur. Birinin düşünmediğini diğeri düşünür" der.
- **Duygu sözlükleri genişletilebilir:** NRC duygu sözlüğünün Türkçe sürümü de vardır. Sözlükte olmayan bir duygu kelimesi, derecesiyle birlikte eklenebilir. Sözlük sonuçta bir Excel dosyası gibidir.
- **Emoji tabanlı otomatik etiketlemenin sınırı:** Emoji puanlarını toplayarak etiketlemek basittir. Ama kırık kalp ile ağlayan yüz yan yana gelirse puanlar birbirini götürüp nötr çıkabilir. Oysa metin üzgün bir durumu anlatır. Emoji içermeyen tweet'ler de büyük olasılıkla elenmiştir.
- **Veri seti oluşturmak atıf getirir:** Etiketli veri seti eksikliği öne çıkan bir sorundur. İyi bir veri seti oluşturan çok atıf alabilir.
- **Türkçe çalışmaların zorluğu:** Türkçede çoğu konuda etiketli bir veri seti bile yoktur.
  - Türkçe bir çalışma yayına gönderildiğinde hakem "Başarını neye göre kıyasladın?" diye sorar. Karşılaştırılacak Türkçe çalışma azdır. Başka bir dille de kıyaslanamaz.
- **Kaynak gösterilmeyen sözlük:** 6. sunumdaki makalede kullanılan sözlüğe atıf yapılmamıştır. Hoca buna tepki gösterir.
- **Olumsuz sonuç da sonuçtur:** 6. sunumdaki makale, yöntemin polariteyi kesin olarak belirleyemediği sonucuna varır. Hoca "Bir şeyin olmayacağını da gösterirsin" der. Gelecek çalışmanın yapılıp yapılmadığının araştırılmasını ister.
- **Basit fikirler büyük katkılardır:** Hoca Kruskal algoritması gibi çok basit fikirlerin başkaları tarafından bulunduğunu hatırlatır. Bir öğrenci her şeyin bulunduğu ön yargısını, hoca ise tembelliği neden olarak gösterir.

## Kısa Tekrar Notları

- Duygu modelleri:
  - Kategorik model: Ekman'ın 6 temel duygusu (öfke, korku, mutluluk, şaşkınlık vb.). Başka bir model 8 duyguyu zıt çiftler (örneğin sevinç-üzüntü) olarak alır.
  - Boyutsal model: Circumplex modeli duyguyu iki boyutta tanımlar: hoşluk (hoş-nahoş) ve uyarılma (sakin-heyecanlı).
- Metinden duygu tespiti yaklaşımları: anahtar kelime tabanlı, derlem (corpus) tabanlı, öğrenme tabanlı (denetimli, denetimsiz), karma (hybrid).
- İçsel (intrinsic) konu bölümleme yalnızca dokümanın kendisini kullanır. Dışsal (extrinsic) bölümleme dış kaynakları da kullanır. Dışsal yöntemler daha başarılıdır.
- Konu bölümlemede İngilizce için word2vec, Arapça için GloVe en iyi sonucu verir. LSA iki dilde de en kötüdür.
- Türkçe metin sınıflandırmada kelime bölümleme yöntemi alan (domain) ve sinir ağı mimarisiyle uyumlu seçilmelidir.
- Bağımlılık RNN'i (dependency RNN), bir kelimenin olasılığını cümledeki önceki kelimelere göre değil, bağımlılık ağacındaki ata (ancestor) kelimelere göre hesaplar.
- Duygu analizi üç düzeyde yapılır: doküman, cümle, varlık ve görünüm (entity/aspect).
- Final: 14 Ocak 2021 Perşembe öğleden sonra. Proje raporu sınav evrakı olarak PDF yüklenir. Projeler ayrı bir toplantı oturumunda gösterilir.

## Detaylı Açıklamalar

### 1. Sunum: Metinden Duygu Tespiti Yaklaşımları Üzerine Derleme

- Sunucuya verilen makale 2000 yılına aitti ve çok eski olduğu için sunucu 2018 tarihli bir derlemeyi (survey) temel alır. Derleme 2014-2017 arasındaki yaklaşık 50 yöntemi tablolarla verir.
- **Neden zor:** İnsanlar duygularını yalnızca kelimelerle değil, ses tonu, mimikler ve el hareketleriyle de ifade eder. Yalnız metinle duygu analizi bu yüzden kısıtlıdır.
- **Veri setleri:**
  - ISEAR: Farklı kültürlerden katılımcıların etiketlediği 7666 cümle, 7 duygu. En eski ve güvenilir etiketli veri setlerindendir. Kaggle'dan indirilebilir.
  - Fairy Tales: 185 çocuk öyküsünden yaklaşık 15.000 cümle, 8 duygu.
  - SemEval haber başlıkları (Google News, BBC, CNN): 6 duygu. Her cümleye tek duygu yerine birden çok duygu farklı derecelerle atanır (örneğin 0,7 öfke, 0,5 korku).
- **Ön işleme:** tokenization, lemmatization, kök bulma, işlevsel kelimelerin (stop words) çıkarılması, bağlantılar gibi gürültünün temizlenmesi, kısaltmaların açılması.
- **Yaklaşımlar:**
  - Anahtar kelime tabanlı: Duygu ifade eden kelimelerin varlığına ve sıklığına bakar. Kelimeler arası ilişkiye bakmadığı için genelde yetersizdir.
  - Derlem tabanlı: Anahtar kelime yaklaşımının genişletilmiş hâlidir. Kelimelere olasılık veya ağırlık verilir. Sonunda yine bir sınıflandırıcı gerekir (örneğin J48).
  - Öğrenme tabanlı: Denetimli ve denetimsiz yöntemler.
  - Karma: Yukarıdakilerin birleşimi.
- **Örnek 1 (derlem tabanlı):** myPersonality projesi.
  - Yaklaşık 5865 kullanıcının yaklaşık 1 milyon Facebook durum güncellemesi. Yaş, cinsiyet ve kişilik özellikleri kullanılır.
  - Kişilik puanları (1-5) eşik değerlerle 5 kategoriye ayrılır (örneğin deneyime açıklık, nevrotiklik).
  - Sözlük: NRC duygu sözlüğü. 10 boyutlu, 14.177 İngilizce kelime. Her boyut bir duyguyu veya polariteyi tutar.
  - Bulgular: Kadınlar daha çok güncelleme yapar. En çok ve en olumlu paylaşım 41-50 yaş aralığındadır. Nevrotik kişiler daha az ve daha az olumlu paylaşım yapar. Deneyime açık kişiler en çok paylaşımı yapar.
  - En çok olumlu paylaşım Aralık ayındadır. Pazartesi-Perşembe arası öfke ve şaşkınlık daha çok görülür.
  - Anlamlılık için Pearson ki-kare testi kullanılır. $p < 0{,}01$ olan sonuçlar anlamlı kabul edilir.
- **Örnek 2 (denetimli):** Arapça tweet'lerde emoji tabanlı sınıflandırma.
  - 134.000 tweet. Bir kısmı elle (yaklaşık 2.000), bir kısmı otomatik (yaklaşık 22.000) etiketlenir.
  - Otomatik etiketleme için her emojiye $-5$ ile $+5$ arasında puan veren bir emoji sözlüğü kullanılır. Cümledeki emoji puanları toplanır ve sonuca göre kategori atanır.
  - %80 eğitim, %20 test. SVM ve Naive Bayes kullanılır. Otomatik etiketli veri daha başarılı sonuç verir.
  - Sunucunun yorumu: Elle etiketli veri az olduğu için aşırı öğrenme (overfitting) olmuş olabilir.
- **Örnek 3 (denetimsiz):** YouTube yorumlarından bir derlem.
  - Her duygu için noktasal karşılıklı bilgi (Pointwise Mutual Information, PMI) hesaplanır. En yüksek PMI'lı duygu cümleye atanır.
  - Değer 0,25 veya altındaysa cümle nötr sayılır.
  - Başarıyı göstermek için etiketli bir alt küme ile kesinlik, duyarlılık ve doğruluk hesaplanır.
- **Örnek 4 (konu düzeyinde):** Biterm Konu Modeli (Biterm Topic Model, BTM).
  - Derlem düzeyinde çalışır. Kelimeleri önce konulara kümeler.
  - Avantaj: Ortak kelimesi olmayan iki cümle (biri benzin fiyatından, biri bir araba markasından bahseden) aynı "otomobil" konusunda yakalanabilir.
- **Örnek 5 (karma):** Topluluk (ensemble) sınıflandırıcı.
  - Temel öğrenici: Kelime torbası (Bag of Words), TF-IDF ağırlıkları ve SVM.
  - Kelime gömme tabanlı sınıflandırıcı: CBOW vektörleri farklı ağırlıklarla birleştirilir (tüm ağırlıklar 1, TF-IDF, kelimelerin ortalama ve standart sapmasına dayalı bir önem değeri).
  - Kendi ağırlıklandırmalarını kullanan topluluk yöntemi en başarılıdır.
- **Sonuç:** Makine öğrenmesi yöntemleri yaygındır. Derin öğrenme ve topluluk yöntemleri umut vericidir. Veri seti eksikliği öne çıkar.

### 2. Sunum: Konu Bölümleme Algoritmalarının Karşılaştırılması

- **Makale:** 2017'de bir konferansta yayımlanmış. Yazarlar Tunus'taki bir laboratuvardandır. Hem İngilizce hem Arapça için çalışır.
- **Konu bölümleme:** Bir dokümanı anlamlı bölümlere ayırma işlemidir.
  - İçsel yaklaşımlar yalnızca bölümlenecek dokümanı kullanır: TextTiling, C99, LCseg, F06, TopicTiling.
    - LCseg sözcük tekrarlarını kullanır. F06 ve TopicTiling, TextTiling'i temel alır. F06 benzerlik için kosinüs yerine Dice ölçütünü kullanır.
  - Dışsal yaklaşımlar dış kaynakları da kullanır: LSI/LSA, birlikte geçme ağları (co-occurrence networks), üretici Bayes modelleri.
- **Amaç:** Kelime anlamlarını analiz etmede en iyi kelime vektörü temsilini bulmak. LSA, word2vec ve GloVe karşılaştırılır.
- **LSA:** Terim-doküman matrisi oluşturulur. Matris SVD ile üç matrise ayrılır. Sonuç sıklık eşikleri, ağırlıklandırma fonksiyonu ve anlamsal uzay boyutuna bağlıdır.
  - Yazarların önceki bir çalışmasına göre: yerel sıklık 3, küresel sıklık 1, yerel ağırlık TF, küresel ağırlık IDF.
- **word2vec (Mikolov, 2013):** Sinir ağı tabanlıdır. Girdi, gizli ve çıktı katmanı vardır.
  - CBOW: Bağlamdan kelimeyi tahmin eder. Skip-gram: Kelimeden bağlamı tahmin eder.
  - Mikolov'a göre skip-gram küçük eğitim verisinde iyi çalışır. CBOW daha hızlıdır ve sık geçen kelimelerde daha iyidir.
- **GloVe (Pennington vd., 2014):** Önce birlikte geçme matrisi $X$ oluşturulur. $X_{ij}$, $j$ kelimesiyle birlikte geçen $i$ kelimesinin sıklığıdır. Sonra kelime vektörleri bir hata fonksiyonu en aza indirilerek öğrenilir:

$$J = \sum_{i,j} f(X_{ij})\left(w_i^{T}\tilde{w}_j + b_i + \tilde{b}_j - \log X_{ij}\right)^2$$

- **Önerilen bölümleme algoritması (5 adım):**
  1. Ön işleme: dil tespiti, durak kelimelerin çıkarılması, kök bulma.
  2. Sıklık sözlüğü: Her cümle bir vektörle ilişkilendirilir. Anlamsal uzayda olmayan terim boş vektörle gösterilir.
  3. Benzerlik matrisi: Tüm cümle çiftleri arasında benzerlik hesaplanır.
  4. Sıralama (rank) matrisi oluşturulur.
  5. Konu sınırları Reynar algoritmasıyla belirlenir.
- **Veri:** İngilizce için yalnızca bilgisayar bilimi makalelerinden oluşan bir derlem. Arapça için ekonomi, politika, sağlık gibi çeşitli konulardan bir derlem. Eğitim seti anlamsal uzayı kurmak, test seti algoritmaları değerlendirmek için kullanılır.
- **Ölçüt:** WindowDiff (hata yüzdesi; düşük olan iyidir).
- **Sonuçlar:**
  - word2vec ayarları: İngilizcede CBOW için negatif örnekleme (negative sampling), skip-gram için hiyerarşik softmax daha iyidir. Arapçada ikisinde de negatif örnekleme daha iyidir.
  - İngilizcede CBOW daha düşük hata verir. Derlem tek alandan olduğu için kelime tekrarı çoktur ve CBOW sık kelimelerde iyidir. Arapçada skip-gram daha iyidir.
  - İngilizce: LSA en yüksek hatayı verir. word2vec ve GloVe yakındır. word2vec daha küçük anlamsal uzayla en düşük hatayı verir.
  - Arapça: Ortalamada GloVe en iyisidir. LSA'nın anlamsal uzayı çok büyük, hatası da yüksektir.
  - Yazarlara göre GloVe'un anlamsal uzayı daha büyüktür ve kelime anlamını öğrenmek için daha çok bilgiye ihtiyaç duyar. Arapça biçimbilimsel olarak karmaşık olduğu için bu Arapçada avantaj olur.
  - Örnek: Arapçada aynı kökten gelen "scientist" ve çoğulu arasındaki kosinüs benzerliği LSA ile 0,3, word2vec ile 0,05, GloVe ile 0,2 çıkar. Aynı konudaki "medicine" ve "diagnosis" için en iyi değer GloVe ile 0,26'dır.
  - Dışsal yöntemler içsellerden daha iyidir. Dış bilgi eklemek başarıyı artırır.
  - İngilizcede en fazla %8 hata varken Arapçada hata %30'a kadar çıkar.
- Derste, 2017 tarihli bu çalışmaya BERT eklenseydi sonuçların değişebileceği yorumu yapılır.

### 3. Sunum: Haber Makalelerinde Sözlük Tabanlı Duygu Analizi

- **Makale:** "Sentiment Analysis of News Articles: A Lexicon Based Approach" (iCoMET 2019).
- **Motivasyon:** Basılı gazete ve dergiler yerini çevrim içi platformlara bırakmıştır. Sosyal medyadaki büyük veri, duygu analizini popüler yapmıştır.
- **Duygu analizinde iki yaklaşım:** sözlük (lexicon) tabanlı ve denetimli/denetimsiz öğrenme tabanlı.
- **Literatür:**
  - New York Times, BBC, Reuters ve Daily Mail'den 69.907 manşet incelenir. Olumlu ve olumsuz başlıkların daha çok ilgi gördüğü bulunur.
  - Cümle düzeyinde, dinamik bir sözlükle haber sınıflandırma.
  - Finansal haberlerde sözlük tabanlı duygu analizi.
  - Python paketleri ve SentiWordNet 3.0 ile görüş madenciliği.
- **Veri:** BBC haber veri seti (2004-2005), 2225 doküman, 5 kategori: iş, eğlence, politika, spor, teknoloji.
- **Yöntem:**
  1. Ön işleme: Gürültü ve yazım hataları temizlenir. RapidMiner ile tokenization yapılır. Noktalama silinir. Harf büyüklüğü tek tipe çevrilir. Durak kelimeler çıkarılır. Kök bulunur.
  2. Kelimeler TF-IDF ile ağırlıklandırılır.
  3. Duygu puanları WordNet ve SentiWordNet ile atanır.
  4. Toplam duygu puanı hesaplanır: negatifse olumsuz, pozitifse olumlu, sıfırsa nötr.
- **Sonuç:** Örneğin iş kategorisindeki 510 makaleden 274'ü olumlu, 205'i olumsuz, 31'i nötr çıkar. İş ve spor kategorileri daha olumlu, eğlence ve teknoloji daha olumsuz makalelerden oluşur.
- **Hocanın yorumu:** Konu bu derste çok dinlendiği için sıkıcı gelmiştir. Bu sunucuyla ilgili değildir.
- **Sunucunun ek notu:** Duygu analizi İngilizce ve Çincede popülerdir. Arapça ve İtalyancada duygu sözlükleri kısıtlıdır. Hoca Türkçede durumun benzer olduğunu ekler.

### 4. Sunum: Türkçe Metin Sınıflandırma için Kelime Bölümleme

- **Problem:** Türkçe gibi biçimbilimsel açıdan zengin ve sondan eklemeli dillerde sözlük çok büyür. Sinir ağlarını eğitmek zor ve pahalıdır. Sözlük dışı (yabancı, nadir) kelime sorunu da vardır.
  - Literatürde kelimeleri alt kelime (subword) birimlerine ayırmak için Byte Pair Encoding (BPE) önerilmiştir. Bu hem sözlüğü hem test süresini küçültür.
- **Amaç:** Türkçe doküman sınıflandırmada kelime bölümleme yöntemi seçiminin sınıflandırıcı performansına etkisini araştırmak. Önceki bir çalışma 4 yöntemi incelemişti. Bu çalışma farklı alanlarda daha modern yöntemleri dener.
- **16 bölümleme yöntemi:**
  - Kelime tabanlı: Boşluklara göre bölme.
  - Karakter tabanlı: Metni karakterlere bölme.
  - Karakter n-gram tabanlı: $n = 2, 3, 4, 5, 6, 7$.
  - Gövde (stem) tabanlı: Snowball kök bulucu.
  - Lemma tabanlı: Zemberek ile.
  - Biçimbilimsel (morphological): Her kelime dilbilgisi kurallarına göre biçimbirimlerine ayrılır.
  - Morfessor: Kelimeleri biçimbirim benzeri parçalara bölen denetimsiz bir algoritma.
  - BPE: Aslında bayt dizilerini birleştiren bir veri sıkıştırma algoritmasıdır. Burada bayt yerine karakter dizileri birleştirilir (iki BPE türü kullanılır).
  - WordPiece: Korece ve Japonca gibi boşlukla ayrılmayan diller için geliştirilmiş, sonra İngilizcede de kullanılmıştır.
  - Unigram dil modeli tabanlı: Bir tür alt kelime bölümleme algoritmasıdır.
- **Veri setleri:**
  - Twitter duygu analizi: Olumlu, olumsuz, nötr. YTÜ Kemik NLP grubu tarafından toplanıp etiketlenmiştir.
  - Film yorumları: 4,5 puan üzeri olumlu, 1,5 puan altı olumsuz.
  - Haber: YTÜ Kemik NLP grubu tarafından oluşturulmuştur.
  - Ürün yorumları: Kaggle'daki Türkçe veri seti. 5 puan olumlu, 1-2 puan olumsuz.
- **Mimariler:** doğrusal model, CNN (100 çekirdek), iki katmanlı çift yönlü LSTM. Aşırı öğrenmeye karşı dropout, optimizasyon için Adam. Donanım sınırı nedeniyle her girdi 256 token'la sınırlanır.
- **Ön işleme:** bağlantıları silme, küçük harfe çevirme, alfabetik karakterleri noktalamadan ayırma, birden çok boşluğu teke indirme, art arda tekrarlanan karakterleri teke indirme.
- **Deney:** Her deney 5 kez tekrarlanır. Ortalama F1 skoru ve standart sapma raporlanır.
- **Sonuçlar:**
  - Bölümleme yöntemi alan ve mimariyle uyumlu seçilmelidir.
  - Mimari dizileri modelleyebiliyorsa (LSTM): Normalize edilmiş metinde en iyisi biçimbilimsel analize dayalı bölümlemedir. Tweet gibi normalize edilmemiş metinde en iyisi Morfessor'dur.
  - Mimari dizileri modelleyemiyorsa: Normalize metinde BPE, WordPiece, unigram gibi yöntemler benzer sonuç verir. Normalize edilmemiş metinde en iyisi karakter n-gram, özellikle $n=5$'tir.
- **Hocanın sorusu:** Morfessor'un örnek cümleyi neye göre böldüğü anlaşılmaz. Bölmeler çekim eki veya yapım eki sınırına uymaz, heceyi bile bölebilir. Hoca bunun incelenmesi gerektiğini söyler.
- Sunucunun bağlantısı zayıf olduğu için sunumun bazı kısımlarında ses ve ekran kesilir.

### 5. Sunum: Cümle Tamamlama için Bağımlılık Tabanlı RNN Dil Modelleri

- **Makale:** "Dependency Recurrent Neural Language Models for Sentence Completion". Yazarlar Piotr Mirowski ve Andreas Vlachos. ACL, 2015.
- **Amaç:** RNN'in cümle tamamlama başarısını, bağımlılık ayrıştırmasının (dependency parsing) ürettiği ağaç ve etiketleri kullanarak artırmak.
- **Dil modelleri:** Doğal dildeki kelime ve cümlelerin olasılık dağılımını hesaplar. Makine çevirisi, konuşma tanıma ve dilbilgisi düzeltmede kullanılır.
  - Sayıma dayalı (count-based) modeller n-gram kullanır.
  - Sinirsel dil modelleri her kelimeyi bir vektöre yerleştirir ve derin öğrenme kullanır.
- **RNN:** Veri dizi biçimindeyse (hava durumu, cümle) önceki çıktı sonrakini etkiler. Bu yüzden önceki gizli durum her adımda ek girdi olarak kullanılır.

$$s(t) = f\big(U\,w(t) + W\,s(t-1)\big), \qquad y(t) = g\big(V\,s(t)\big)$$

  - $f$ sigmoid, $g$ softmax fonksiyonudur. $U$ girdi kelime gömme matrisi, $V$ çıktı gömme matrisidir.
- **RNN + maksimum entropi (Mikolov, 2011):** RNN'in kelime olasılıklarına n-gram özellikleri eklenir. Büyük derlemde n-gram bağlamlarını tekrar tekrar hesaplamamak için bir özet (hash) fonksiyonu kullanılır.
- **Bağımlılık RNN'i (dependency RNN):**
  - Normal RNN kelimeleri sıralı bir dizi gibi işler. Bağımlılık RNN'i ise her cümlenin bağımlılık ağacını kullanır.
  - Bir kelimenin ataları (ancestors), köke (root) başlayıp o kelimeye ulaşırken uğranan kelimelerdir.
  - Cümlenin olasılığı, her kelimenin atalarına koşullu olasılıklarının çarpımıdır:

$$P(\text{cümle}) = \prod_{i} P\big(w_i \mid A(w_i)\big)$$

- **Etiketli bağımlılık RNN'i (labeled dependency RNN):** Bağımlılık etiketleri (özne, nesne, yüklem gibi dilbilgisi ilişkileri) de modele eklenir. Etiketleri kelime olasılıklarına bağlayan bir $G$ matrisi kullanılır.
- **Veri:** 19. yüzyılda yazılmış 522 romandan cümleler. Sözlükte 72.846 kelime. 1040 cümle test için kullanılır (Microsoft Research Sentence Completion Challenge). Cümle bölme, POS etiketleme ve ayrıştırma için Stanford CoreNLP kullanılır.
- **Sonuç:** 2-gram, 3-gram ve 4-gram düzeylerinde karşılaştırma yapılır. Bağımlılık RNN'i normal RNN'e göre yaklaşık %10 iyileşme sağlar. Kod GitHub'da açık kaynak olarak paylaşılmıştır.
- **Hocanın açıklaması:** "Ata kelime" ifadesi Türkçe söylenince anlaşılmaz. Kastedilen, ağaçta o düğümün üstünde kalan, ona ulaşırken geçilen düğümlerdir. Bir kelimenin olasılığı, ağaçta onun üstündeki kelimelerle birlikte kullanım olasılığıyla hesaplanır.

### 6. Sunum: Haber Makalelerinde Doküman Düzeyinde Duygu Analizi

- **Makale:** 2017 tarihli bir konferans bildirisi. BBC haber veri seti üzerinde haberlerin olumlu veya olumsuz olduğunu belirlemeye çalışır.
- **Duygu analizi yöntemleri:** makine öğrenmesi, sözlük tabanlı ve dilbilimsel analiz.
- **Duygu analizi düzeyleri:**
  - Doküman düzeyi: Tüm doküman tek bir olumlu-olumsuz sonuç alır. Birden çok ürüne ait yorumları içeren bir metinde iyi çalışmaz.
  - Cümle düzeyi: Her cümle olumlu, olumsuz veya nötr olarak etiketlenir. Nötr cümleler görüş bildirmez.
  - Varlık ve görünüm (entity/aspect) düzeyi: Özellik tabanlı duygu analizidir. Bir görüş, bir duygu ve bir hedeften oluşur.
- **Önerilen sistem:** temizleme (durak kelimeler), küçük harfe çevirme, kök bulma, terim-doküman matrisi oluşturma, bir duygu sözlüğüyle karşılaştırıp doküman puanı hesaplama, puana göre olumlu-olumsuz-nötr kararı.
- **Veri:** BBC veri seti, 5 kategori (iş, eğlence, politika, spor, teknoloji). Her kategoride yüzlerce makale vardır.
- **Sözlük:** Sunumda adı "Binkliyor" diye geçen bir olumlu-olumsuz kelime sözlüğü. Makalede bu sözlüğe atıf yoktur.
- **Sonuçlar:** Örneğin iş kategorisindeki 510 makalenin 262'si olumlu, 214'ü olumsuz bulunur. 34'ü hakkında karar verilemez. Bazı kategorilerde olumlu ve olumsuz sayılar birbirine çok yakındır.
- **Yazarların vardığı sonuç:** Bu yöntem bir makalenin olumlu veya olumsuz olduğu hakkında kesin bilgi vermez. Gelecekte cümle puanlarına dayalı makine öğrenmesi teknikleri uygulanacaktır.
- **Hocanın yorumu:** "Ben boş bir çalışma yaptım mı demek istiyor?" Hoca sonucu ilginç bulur. Sunucudan gelecek çalışmanın yapılıp yapılmadığını araştırıp e-posta ile bildirmesini ister.

### Final ve Proje Duyuruları

- Hoca projeler hakkında ilk fırsatta e-posta atacaktır.
- Final, 14 Ocak 2021 Perşembe öğleden sonradır (bölüm sayfasında ilan edilmiştir).
- Final günü sorulacak sorunun cevabı öğrencinin kendi projesi olacaktır. Proje raporu ad-soyad dahil PDF olarak sisteme sınav evrakı olarak yüklenir.
- Aynı gün bir toplantı oturumu açılıp projelere bakılacaktır. Bu çok zaman aldığı için projesini önceden bitiren hocaya e-posta atmalıdır. Hoca örneğin bir akşam saatinde 2-3 kişinin projesine önceden bakabilir.
- Projesini bitiremeyecek olanlar da hocaya bilgi vermelidir.
- Bir öğrencinin seminer raporu eksiktir ve tamamlanacaktır.

### Ders sonrası notlar

- Altyazıda geçen bazı terimlerin doğru yazımları:
  - "International Server on Emotion" → ISEAR (International Survey on Emotion Antecedents and Reactions).
  - "Sam Ivali" → büyük olasılıkla SemEval.
  - "Afin Leksikon" → AFINN benzeri bir emoji puan sözlüğü.
  - "B-Term Topic model" → Biterm Topic Model.
  - "Seabov", "Sibov", "C-Ball" → CBOW. "Sıkık gram", "Scriptgram", "Skit krem" → skip-gram.
  - "World2Vac", "Word to Back" → word2vec. "Glob", "Glover" → GloVe. "LSE", "LST" → LSA.
  - "IcomED 2019" → iCoMET 2019.
  - "Morfesör", "morfolosur" → Morfessor. "White-Pair-Encoding" → Byte Pair Encoding. "Word PIS" → WordPiece.
  - "kemik NLP grup" → YTÜ Kemik Doğal Dil İşleme Grubu.
  - "Sentence Complulation" → Sentence Completion. "Piotr Mirovski" → Piotr Mirowski.
  - "Anchester kelime" → ancestor (ata) kelime.
  - "Binkliyor" → büyük olasılıkla Bing Liu'nun görüş sözlüğü (opinion lexicon). Altyazıdan kesin değildir.
- 6. sunumda veri setinin 225 doküman içerdiği söylenir. 3. sunumdaki aynı BBC veri seti 2225 dokümandır. Doğrusu büyük olasılıkla 2225'tir.
- 3. ve 6. sunumlar aynı BBC veri seti ve benzer sözlük tabanlı yöntemle çalışır. İş kategorisi için verilen sayılar (274/205/31 ve 262/214/34) farklı çalışmalara aittir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
