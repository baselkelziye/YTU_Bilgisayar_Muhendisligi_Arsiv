# Ders 6 Genişletilmiş Notu: Ödev Sunumları (Kelime Vektörleriyle Uygulamalar), Aktif Öğrenme, Yarı Eğiticili Öğrenme ve Öğrenmenin Transferi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ödev Sunumları: Farklı Derlemlerle Eğitilen Kelime Vektörleri
- 2. Sunumlarda Öne Çıkan Kavramsal Düzeltmeler
- 3. Makine Öğrenmesinde Yeni Problemler: Genel Bakış
- 4. Aktif Öğrenme (Active Learning)
- 5. Yarı Eğiticili Öğrenme (Semi-supervised Learning)
- 6. Öğrenmenin Transferi (Transfer Learning) ve Self-supervised Öğrenme
- Örnek Sorular
- Dersin Toparlaması

## 1. Ödev Sunumları: Farklı Derlemlerle Eğitilen Kelime Vektörleri

Dersin ilk yarısı ödev sunumlarına ayrıldı. Ödevde öğrencilerden, geçen derslerde görülen anlamsal uzay yöntemlerinden (word2vec, FastText, GloVe vb.) en az üçünü farklı derlemlerle eğitip bir uygulamada karşılaştırmaları isteniyordu. Sunumların çoğu Türkçe duygu analizi (sentiment analysis) üzerineydi; biri metin üretimi, biri de kelime benzerliğine dayalı bir öneri sistemi denemesiydi. Sunanlar burada adsız olarak "bir grup" ya da "bir öğrenci" diye anılır; yalnız akademik içerik aktarılmıştır.

### 1.1 Birinci grup: BERT, FastText ve word2vec ile duygu analizi

Grup, e-ticaret sitelerindeki kullanıcı yorumlarından oluşan, pozitif/negatif etiketli iki kümeyle çalıştı. Kümelerden biri hocanın paylaştığı derlem havuzundaki yorum kümesiydi, öteki internetten bulunmuştu; birinde 373.187, ötekinde 19.022 örnek vardı. Ön işlemede Türkçe karakterler dönüştürüldü, noktalama işaretleri ve Türkçe durma kelimeleri (stop words) çıkarıldı, iki dosya tek dosyada birleştirilip etiketlendi. Eğitim uzun sürdüğü için büyük kümeden 12.500 örnek alındı: 10.000'i eğitim, 2.500'ü test için.

Sunumda BERT'in cümleyi hem soldan sağa hem sağdan sola değerlendirdiği, FastText'in metin sınıflandırma amacıyla geliştirilmiş bir kütüphane olduğu ve word2vec'te skip-gram yönteminin kullanıldığı anlatıldı. Sonuç tablosu şöyleydi (ekrandan, 00:13:26):

| Yöntem | Dataset1 doğruluk | Dataset2 doğruluk |
|---|---|---|
| BERT | %90 | %91 |
| FastText | %89 | %93 |
| word2vec + karar ağacı (DT) | %86 | %82 |
| word2vec + Naive Bayes (NB) | %14 | %80 |

Slayta göre BERT 1 epoch eğitilmiş, FastText'te en iyi sonuç n-gram = 2 ile alınmıştı. Grup, Gaussian Naive Bayes'in %14'lük sonucunun büyük olasılıkla bir hatadan kaynaklandığını, ama çözemediklerini söyledi. Hata analizinde "Bu fırsat kaçmaz arkadaşlar" cümlesi Dataset2 ile eğitilen modelde negatif, Dataset1 ile eğitilende pozitif çıkmıştı; grup bunu veri kümeleri arasındaki farka bağladı. Modelin "etmiyorum"u negatif olarak ayırabildiğini, ama "edemiyorum", "yapamıyorum" gibi fiilleri daha çok pozitif saydığını da gözlemlediler.

Hoca bu sunumda iki ayrımı netleştirdi (bkz. Bölüm 2): derlem ile veri kümesi farkı ve hazır model kullanmak ile modeli derlemle eğitmek farkı. Grubun BERT'te ve FastText'te hazır, önceden eğitilmiş modelleri alıp yalnız ince ayar (fine-tune) yaptığı anlaşıldı. Grup, araştırmalarına göre BERT'te 4-5 epoch'tan sonra başarının düşmeye başladığını, 1-2 epoch'un yeterli olduğunu aktardı. Hoca burada iki ayrı eğitim olduğunu hatırlattı: biri derlemle önceden eğitim (pretrain), öteki etiketli veriyle ince ayar. BERT bir yapay sinir ağıdır; rastgele ağırlıklarla başlar, derlemle eğitildikten sonra belli bir hâle gelir.

### 1.2 İkinci grup: word2vec, Doc2Vec ve FastText ile hiperparametre denemeleri

Grup iki veri kümesi kullandı: üç sınıflı (olumlu, olumsuz, nötr) bir Türkçe Twitter kümesi ve Türkçe film yorumları. Film yorumlarında her yorumun bir puanı vardı; 3.5'ten büyük puanlar olumlu, küçükler olumsuz sayılarak dengeli bir küme kuruldu (toplam 83.183 satır). Araç olarak Gensim (word2vec, Doc2Vec, FastText eğitimi), scikit-learn, NLTK, regex, NumPy, pandas ve arayüz için Streamlit kullanıldı.

Ön işleme adımları: küçük harfe çevirme, emojilerin duygu etiketine dönüştürülmesi (ör. ":)" pozitif, ":/" negatif; tweet'lerde sık görülüyor), Türkçe karakter dönüşümü, bağlantıların, rakamların, noktalama ve özel karakterlerin kaldırılması. Kelimeler arasındaki anlamsal ilişki korunsun diye kök bulma (stemmer) uygulanmadı. Twitter kümesinde neredeyse bütün sınıflarda operatör adları (Turkcell, Superonline, Avea, Vodafone gibi) en sık geçen kelimelerdi; sınıflar arasında yapay benzerlik kurmasınlar diye çıkarıldılar. Olumlu sınıfın kelime bulutunda pozitif emoji etiketi (EMOPOS), "teşekkürler", "güzel", "canım" gibi kelimeler öne çıkıyordu (ekrandan, 00:20:00).

Hoca, emoji etiketlerinin kural tabanlı (regex ile) üretildiğini teyit ettikten sonra derlemin ne olduğunu sordu. Grup, eğitim ve test dosyalarını etiketlerinden ayırıp birleştirerek derlem yaptıklarını söyledi. Hoca bunun bir sorun olduğunu belirtti: test kümesindeki örnekler etiketsiz de olsa derleme girmemelidir (bkz. Bölüm 2.3).

word2vec hiperparametreleri: vektör uzunluğu (her kelimenin ifade edileceği boyut sayısı), pencere (window) boyutu, skip-gram/CBOW seçimi, başlangıç öğrenme oranı (alpha) ve epoch sayısı. Öğrenme oranı dört farklı değerde denendi; pencere 3, 5, 7; vektör boyutu da değiştirildi. Cümle vektörü, cümledeki kelime vektörlerinin ortalamasıyla elde edildi ve sınıflandırıcı olarak varsayılan parametreli lojistik regresyon ve random forest kullanıldı. Gözlemler:

- Öğrenme oranı 0.05 ve 0.1 civarında en iyi sonuçlar alındı.
- Pencere boyutu ve vektör boyutu arttıkça başarı genelde arttı.
- Doc2Vec, kelime değil doküman (cümle) düzeyinde vektör üretir; word2vec ile benzer davranış gösterdi.
- FastText'te iki ek hiperparametre vardı: karakter n-gram'ı için en küçük (minn) ve en büyük (maxn) uzunluk. (2, 4), (3, 6) ve (4, 8) aralıkları denendi. Twitter kümesinde (3, 6), film yorumlarında (4, 8) daha iyiydi. FastText'te pencere küçükken daha iyi sonuç alındı. Film yorumlarında FastText ile vektör boyutu 25'ten 50'ye çıkınca lojistik regresyon doğruluğu 0.722'den 0.741'e çıktı; 75'te 0.741, 100'de 0.738 oldu (ekrandan, 00:30:00).
- En iyi sonuçlar FastText ile alındı, ama eğitim süresi düşünüldüğünde kazanç büyük değildi (yaklaşık 2-3 puan).

Hoca, Twitter kümesinde random forest'ın, film yorumlarında lojistik regresyonun biraz daha iyi göründüğünü not etti. Grubun arayüz demosunda ön işleme adımlarının sırayla, birinin çıktısı ötekinin girdisi olacak şekilde uygulandığı gösterildi.

### 1.3 Üçüncü çalışma: FastText, CountVectorizer ve TF-IDF

Bir öğrenci Twitter yarışma kümesinin etiketli eğitim dosyasını kullandı, 3000 örneği test için ayırdı. Üç yöntem karşılaştırıldı: FastText'in Python kütüphanesi, CountVectorizer + yapay sinir ağı (YSA) ve TF-IDF + SVM. Sonuç tablosu (ekrandan, 00:40:00):

| Yöntem | Accuracy | Precision | Recall | F-score |
|---|---|---|---|---|
| fastText | .625 | .625 | .625 | .625 |
| CountVector + YSA | .57 | .57 | .57 | .57 |
| TF-IDF + SVM | .60 | .64 | .60 | .60 |

Hoca, son iki temsilin anlamsal uzay olmadığını hatırlattı. FastText'in nasıl eğitildiği sorulunca öğrenci, kütüphanenin "etiket + metin" biçimli dosyasıyla etiketli verilerden eğittiğini söyledi; bu, FastText'in denetimli (supervised) sınıflandırma modudur. Öğrencinin aktardığına göre bu mod kelime vektörlerinin ortalamasını alarak üç sınıftan birini seçiyordu. Hoca ayrıca CountVectorizer için YSA, TF-IDF için SVM seçilmesinin gerekçesini sordu; öğrenci her temsil için en iyi çıkan sınıflandırıcıyı yazdığını söyledi. Hoca, bütün denemelerin (karar ağacı, SVM, YSA vb.) sonuçlarının birlikte raporlanması gerektiğini, yoksa sonuçların yorumlanamayacağını belirtti.

### 1.4 Dördüncü çalışma: büyük-ilgisiz derlem mi, küçük-ilgili derlem mi?

Bir öğrenci FastText, word2vec ve GloVe'u iki derlemle eğitti: hocanın verdiği 42 bin haber derlemi (bir milyondan fazla token) ve yorum (comments) derlemi (yaklaşık 300 bin token, haber derleminin üçte biri kadar). Soru şuydu: duygu analizi için büyük ve konuyla ilgisiz bir derlem mi, küçük ve ilgili bir derlem mi daha iyi? ELMo da denenmek istendi, ama sıfırdan eğitimin öğrencinin GPU'lu makinesinde iki haftadan uzun süreceği hesaplandığı için bırakıldı.

Öğrenci, word2vec ile FastText arasındaki en büyük farkın FastText'in sözlükte bulunmama (out-of-vocabulary) sorununa getirdiği çözüm olduğunu; GloVe'un ise istatistiksel (birlikte geçme) bir model, word2vec'in yapay sinir ağı tabanlı olduğunu belirtti. Veri, Twitter yarışma eğitim kümesinin %80-%20 bölünmesiydi. Standart ön işlemeden sonra her cümlenin vektörü kelime vektörlerinin aritmetik ortalaması alınarak bulundu ve girdi sayısı vektör boyuna, çıktı sayısı etiket sayısına eşit 3 katmanlı bir yapay sinir ağına (softmax çıkışlı) verildi (ekrandan, 00:44:38). Sonuçlar:

| Derlem | FastText | word2vec | GloVe |
|---|---|---|---|
| 42 bin haber | %71.5 | %66.4 | %65.4 |
| Comments | %70.4 | %64.8 | %66.3 |

Vektör boyutu bütün modellerde 100'dü. İki çıkarım yapıldı: FastText her iki derlemde de en iyisiydi, yani sözlük dışı kelime sorunu büyük bir sorundur; büyük ve ilgisiz derlem, küçük ve ilgili derlemden biraz daha iyi sonuç verdi (öğrenci bunu beklemiyordu).

> **Ders sonrası not:** Öğrenci sözlü anlatımda yorum derlemindeki FastText sonucunu "%74" diye söyledi; ekrandaki raporda bu değer %70.4'tür.

Hoca, iki derlemi birleştirip üçüncü bir derlemle de denenebileceğini önerdi ve eğitim sürelerini sordu; süreler ölçülmemişti. Öğrenci, ELMo'nun bağlama göre vektör üretebildiğini (ör. "elma"nın meyve mi şirket mi olduğunu ayırabildiğini) ilginç bulduğunu söyledi; hoca, BERT'i eğitmenin büyük olasılıkla daha kısa süreceğini belirtti.

### 1.5 Beşinci grup: yorum ve film yorumu derlemleri, Word Embedding katmanı

Grup, hocanın paylaştığı yorum derlemini (yaklaşık 340 bin pozitif, 50 bine yakın negatif yorum) ve bir film yorumu kümesini (57 bine yakın pozitif, 25 bine yakın negatif) kullandı. Ön işlemede büyük-küçük harf dönüşümü, bağlantı ve etiketlerin, noktalama ve özel karakterlerin, fazla boşlukların, film yorumlarındaki satır sonu karakterlerinin silinmesi yapıldı. Film yorumları puana göre etiketlendi. Yorum derleminde 0-100 arası bir puan da vardı; puanı 50'den büyük olduğu hâlde negatif etiketli satırlar (ör. "Küçük çocuğu olan herkese öneririm" yorumu yüksek puanlı ama 0 etiketli) yanlış etiketli sayılıp çıkarıldı, bu da sonuçları iyileştirdi. Sınıflar dengesiz olduğu için alt örnekleme (undersampling) yapıldı: negatif sayısı kadar (yaklaşık 50 bin) pozitif alındı.

word2vec vektörleriyle önce karar ağacı denendi; SVM 6 saatte bitmedi; LSTM %50'ye yakın kaldı; random forest'ta en büyük derinlik (max depth) artınca bir kümede başarı artarken öbüründe yarıya düştü; sonunda lojistik regresyon kullanıldı. Üçüncü yöntem olarak Keras'ın Embedding katmanı (Word Embedding Layer) one-hot girdilerle eğitilip üstüne yoğun (dense) katmanlar eklendi. BERT'te önceden eğitilmiş Hugging Face modelleri denenmiş, ama hazır model kullanılmaması gerektiği için bırakılmıştı; GloVe'un benzer kelime sonuçları beğenilmediği için o da çıkarılmıştı.

Karşılaştırma tablosu (ekrandan, 01:09:15):

| Yöntem | Comments P | Comments R | Comments Acc | Movie P | Movie R | Movie Acc |
|---|---|---|---|---|---|---|
| FastText | %90 | %90 | %90 | %78 | %78 | %78 |
| Word2Vec | %60 | %70 | %62 | %80 | %92 | %79 |
| Word Embedding Layer | %49 | %46 | %48 | %79 | %83 | %74 |

FastText'te sonuçlar, kütüphanenin denetimli (supervised) API'siyle alındı. Alt örneklemeden önce FastText varsayılan parametrelerle her girdiye aynı sınıfı veriyordu; alt örneklemeden sonra %49'a çıktı. Öğrenme oranı azaltılıp epoch sayısı artırıldıkça başarı arttı, ama artış hızı bir süre sonra düştü; yanlış etiketli satırlar silinince %90'a ulaşıldı. Grup, yorum derleminde yaklaşık 100 bin, film yorumlarında yaklaşık 300 bin farklı kelime olduğunu ve sonuç farkının buna bağlı olabileceğini düşündü. word2vec sonuçları lojistik regresyonla alınmıştı.

Hoca, Embedding katmanının başlangıç ağırlıklarını sordu ve FastText ya da word2vec ile öğrenilmiş kelime vektörlerinin bu katmana başlangıç değeri olarak verilebileceğini önerdi; grup bunu denememişti.

### 1.6 Altıncı çalışma: word2vec ve FastText ile metin üretimi

Bir öğrenci metin üretimi (text generation) yaptı. Python, Keras, TensorFlow, NLTK ve Gensim kullanıldı. Derlem olarak 42 bin haber derleminden her kategoriden 730 haber (en küçük kategorinin büyüklüğü) ve 30 köşe yazısı alındı. word2vec ve FastText, skip-gram ve CBOW seçenekleriyle eğitildi.

Uzayları karşılaştırmak için "Türkiye" ve "Yunanistan" kelimeleri seçildi ve bu kelimelere en yakın 10 ve 20 nokta, en uzak 10 nokta ile dışarıdan verilen sekiz kelime (Avrupa, başbakan, terör, savaş, saldırı, erkek, kadın vb.) iki boyutlu grafiklerde gösterildi (ekrandan, 01:20:00). word2vec'te daha anlamlı yakın kelimeler gelirken FastText'te, özellikle skip-gram ile, harf düzeyindeki benzerlik öne çıktı: "Türkiye"ye "Suriye", "ikiye" gibi kelimeler, "Yunanistan"a "Macaristan", "Özbekistan", "Ermenistan" gibi "-istan" ile biten kelimeler yakın çıktı.

Bu vektörler, bir LSTM'in katmanına önceden eğitilmiş vektörler olarak verildi ve 20 kelimelik cümleler üretilmeye çalışıldı. Eğitim verisi şöyle kuruldu: metin en fazla 10 kelimelik parçalara bölündü, her parçanın son kelimesi etiket, öncekiler girdi oldu. Bu Markov modeline benzer, ama olasılıksal değildir. Üretilen cümleler pek ilgili çıkmadı; öğrenci, parça uzunluğunun 3 ya da 4 seçilmesinin daha iyi olacağını sonradan fark ettiğini söyledi. Hoca, daha kısa parçalarla çok daha fazla eğitim örneği elde edileceğini ekledi.

### 1.7 Yedinci çalışma: güncel ve eski derlemle benzer kelimeler

Son sunumda bir öğrenci, ürün önerme sistemi kurma hedefiyle FastText, word2vec ve GloVe'u iki derlemle sıfırdan eğitti: 42 bin haber derlemi ve daha güncel bir haber sitesinden 2014-2020 arası toplanan, yaklaşık 40 MB'lık (42 bin haber derlemine denk) bir derlem. Skip-gram açık (S1) ve kapalı (S0, yani CBOW) iki seçenekle toplam 10 model çıktı. Arayüzde bir kelimeye en yakın kelimeler listelendi. Örneğin "youtube" için 42 bin haber derlemiyle eğitilen FastText modelleri çoğunlukla aynı kelimenin ekli ya da harfçe benzer biçimlerini ("youtube'a", "young", "yougov" gibi) getirirken, güncel derlemle eğitilen modeller "video", "kullanıcılar", "facebook", "whatsapp", "mesajlaşma" gibi anlamca ilgili kelimeleri getirdi (ekrandan, 01:30:00).

Hoca, hangi modelin daha iyi olduğunun nasıl anlaşılacağını sordu. Öğrenci, öneri sistemi bitmediği için sayısal bir karşılaştırma yapmadığını, yalnız gözle bakılabildiğini söyledi.

## 2. Sunumlarda Öne Çıkan Kavramsal Düzeltmeler

### 2.1 Derlem ile veri kümesi aynı şey değildir

Hoca, ilk sunumda derlem ile veri kümesinin birbirine karıştığını gördü ve ayrımı şöyle açıkladı. Derlem temelde etiketsizdir. Etiketli bir veri kümesinin etiketleri atılarak da derlem elde edilebilir. Sistem önce derlemle önceden eğitilir (pretrain); sonra önceden eğitilmiş model etiketli verilerle ince ayar (fine-tune) yapılır.

Ödevin kurgusu da bu ayrıma dayanıyordu. Elde örneğin 1 milyon etiketsiz yorum (içinde pozitif de negatif de var ama hangisinin ne olduğu bilinmiyor) ve 10 bin pozitif, 10 bin negatif etiketli örnek olabilir. Önce 1 milyonluk derlemle vektörler eğitilir; sonra model 10 ya da 20 binlik etiketli veriyle ince ayar yapılıp test başarısı ölçülür. Derlem olarak yorumlar yerine haberler alınırsa, duygu analizi için büyük olasılıkla daha kötü sonuç çıkar. Ödevde merak edilen, farklı derlemlerin bu süreçteki etkisiydi.

### 2.2 Hazır model kullanmak ile modeli derlemle eğitmek

BERT'in boş hâli yalnız bir mimaridir. Büyük derlemlerle eğitilip her dil için yayımlanır; Türkçe için BERTurk gibi. FastText için de 150 kadar dil için hazır vektörler vardır. Hoca, ödevin amacının hazır vektörleri kullanmak değil, bu vektörleri oluştururken farklı derlemler kullanmanın etkisini görmek olduğunu vurguladı. Hazır vektörleri alıp yalnız ince ayar yapan çalışmalar bu soruyu cevaplamaz.

### 2.3 Test örnekleri derleme girmemeli

Bir grup derlemi, eğitim ve test dosyalarını etiketsiz hâle getirip birleştirerek kurmuştu. Hoca, test örneklerinin etiketsiz de olsa derleme konmamasının daha doğru olacağını söyledi. Gerekçe gerçek bir problemdir: test zamanında derlemde ya da eğitim kümesinde hiç görülmemiş kelimeler (unknown) gelir. Test örnekleri derlemdeyse bu durum yaşanmaz ve sonuç gerçeğe göre iyimser çıkar.

### 2.4 Derlemde etiket temizliği ve dengeleme gerekmez

Bir grup, yanlış etiketli yorumları silmiş ve dengelemek için örnek sayısını azaltmıştı. Hoca, derlemde pozitiflik ya da negatifliğin hiçbir önemi olmadığını, derlemin etiketsiz olarak toplanabildiği kadar çok veriden oluştuğunu hatırlattı. Yanlış etiketler uygulamanın (sınıflandırıcının) performansını etkileyebilir, ama derlemden bir şey çıkarmaya gerek yoktur; dengeleme de yalnız sınıflandırıcıyı eğitirken anlamlıdır.

### 2.5 Raporlama ve değerlendirme

- CountVectorizer ve TF-IDF birer anlamsal uzay değildir; kelime vektörü yöntemleriyle aynı kefeye konmamalıdır.
- Her temsil için yalnız en iyi çıkan sınıflandırıcıyı yazmak sonucu yorumlanamaz kılar; denenen bütün sınıflandırıcıların sonuçları birlikte raporlanmalıdır.
- Kelime vektörleriyle cümle vektörü elde etmenin bir yolu, cümledeki kelime vektörlerinin ortalamasıdır; hoca sunumlarda bunu sordu ve gruplar bu yolu kullanmıştı.
- Önceden öğrenilmiş vektörler bir Embedding katmanına başlangıç değeri olarak verilebilir.
- Yakın kelimelere gözle bakmak, hangi modelin daha iyi olduğunu söylemeye yetmez; sayısal bir değerlendirme gerekir.

## 3. Makine Öğrenmesinde Yeni Problemler: Genel Bakış

Sunumlardan sonra hoca "Makine öğrenmesi versiyon 2" adlı slaytlara geçti. Bunlar çok yeni olmasa da son zamanlarda öne çıkan problem türleri ve yaklaşımlardır; bazılarının kodları dersin sayfasında paylaşılmıştır. İçerik slaytındaki konular (ekrandan, 01:31:50):

- Aktif öğrenme (Active Learning)
- Yarı eğiticili öğrenme (Semi-supervised Learning)
- Öğrenmenin transferi (Transfer Learning)
- Çok görevli eğitim (Multi-task Learning)
- Aktif örnekleme (Active Sampling)
- İnsan ve makine işbirliği (Human in loop)
- Az sayıda örnekle eğitim (zero / one shot Learning)
- Veri zenginleştirme (data augmentation)
- ML algoritmalarını kandırmak (Adversarial Attacks)
- Planlı öğrenme (Curriculum Learning)
- Hayat boyu öğrenme (Lifelong learning)

Bu derste ilk üç konu işlendi; çok görevli eğitimde kalındı.

## 4. Aktif Öğrenme (Active Learning)

### 4.1 Tanım, amaç ve yöntem

Slayttaki tanım (ekrandan, 01:32:05): aktif öğrenme, eğitim örneklerinin etiketlerinin başta belli olmadığı, algoritmanın etiketini istediği örnekleri seçmesidir. Amaç veri etiketleme maliyetini azaltmaktır. Yöntem, tüm eğitim seti yerine bir kısmını kullanmaktır: belirli bir test seti üzerinde, tüm eğitim setini kullanmış olmamıza göre benzer, kabul edilebilir derecede düşük ya da daha yüksek başarı elde etmek.

### 4.2 Etiketleme maliyeti neden önemli?

Duygu analizi için çok veri gerekir, ama tek bir örneği etiketletmek ucuzdur; hoca, bin dolar civarında bir bütçeyle insanlara yeterli bir küme etiketletilebileceğini söyledi. Bu yüzden duygu analizinde etiketleme maliyeti kritik görünmeyebilir.

İlaç ve aşı tasarımında durum farklıdır. Bir hastalık için aday moleküller vardır ve bunlar, insanda yan etki oluşturup oluşturmamalarına göre etiketlenecektir. Bunu öğrenmenin yolu molekülü insanlara verip yan etki oluşup oluşmadığına bakmaktır. Bu kadar basit söylenen işin maliyeti çok yüksektir: deneklere büyük paralar ödenir, sonuç insan hayatına bile mal olabilir. Tek bir örneğin etiketi binlerce, belki on binlerce dolara çıkabilir.

Buradan fikir doğar: elde etiketsiz veriler vardır; hangilerinin etiketini isteyeyim? Etiketini zaten iyi tahmin edebileceğim örneklere para harcamak istemem. O hâlde her örnek için "bu örneğin etiketini ne kadar doğru tahmin edebilirim?" sorusuna odaklanmak gerekir.

### 4.3 Aktif öğrenme adımları

Slayttaki adımlar (ekrandan, 01:40:00):

```text
A: Küçük bir eğitim setiyle (E) başla.
   (eğitim kümesinin az bir kısmının etiketlerini iste)
B: Bir model üret. Bu modele göre etiketsiz eğitim
   örneklerine (EE) dair tahminlerini üret.
C: Bu tahminlere göre bu örneklerden bir kısmını seç
   (tahmin varyasyonuna göre) ve etiketlerini iste.
   (EE'den çıkar, E'ye ekle)
B ve C adımlarını tekrar et.
```

Hocanın sayısal akışı şöyleydi. Elde 1000 örnek var ve hiçbirinin etiketi bilinmiyor. Başlangıçta rastgele 10 örnek seçilir; hoca, istenirse en küçük kapsayan ağaç (minimum spanning tree) gibi bir yöntemle birbirinden uzak noktaların da seçilebileceğini söyledi. Bu 10 örneğin etiketi istenir (10 etiketleme maliyeti) ve bir model eğitilir. Model, 10 örnekle eğitildiği için kötüdür ama tahmin yapabilir. Kalan 990 örnek modele verilir ve tahminler alınır; gerçek etiketler bilinmez. Tahminlere bakılarak 10 örnek daha seçilip etiketletilir. Artık 20 etiketli örnek, 980 etiketsiz örnek vardır. 20 örnekle yeni model eğitilir, 980 örnek tahmin edilir, yine sıralanır ve seçilir. Ümit edilen, örneğin 1000 örneğin hepsi yerine 500 tanesiyle benzer başarıya ulaşmaktır.

Gerçek dünyada 1000 örneğin tamamı etiketlenseydi başarının ne olacağı bilinemez. Akademik deneylerde eğitim kümesi bilindiği için bu üst sınır görülebilir. Gerçek uygulamada "performans yeterince iyileşti" ya da "bütçe bitti" denip durulur; örneğin belli bir bütçeyle %80'e çıkılmıştır, daha çok para harcansa belki daha yükseğe çıkılırdı, ama en fazla nereye çıkılabileceği bilinmez.

### 4.4 Tahmin varyasyonu: sınıflandırmada

Yapay sinir ağlarının son katmanının softmax olduğunu düşünelim. Softmax'in çıkışı sınıf olasılıklarıdır. Hoca üç sınıflı bir problemde üç örnek verdi:

| Örnek | A | B | C |
|---|---|---|---|
| 1 | 0.60 | 0.30 | 0.10 |
| 2 | 0.05 | 0.90 | 0.05 |
| 3 | 0.30 | 0.30 | 0.40 |

İkinci örnekte model B sınıfına çok yüksek olasılık vermiştir. Üçüncüde sınıflar arasında çok küçük farklar vardır. Hangisinin etiketini öğrenmek daha iyidir? Derste verilen cevap: eş olasılıklı olanın, yani üçüncünün. Sınıf olasılıkları birbirine yakınsa örnek muhtemelen sınıfların birbirine yakın olduğu bir bölgededir. Belirsizliği ölçmek için olasılıkların varyasyonu ya da entropisi kullanılabilir; örnekler tahmin edilebilirliği az olandan çok olana doğru sıralanıp seçilir.

> **Ek bilgi (derste anlatılmadı):** Entropi $H = -\sum_k p_k \log_2 p_k$ ile hesaplanır ve olasılıklar eşitlendikçe büyür. Bu üç örnek için değerler sırasıyla yaklaşık 1.295, 0.569 ve 1.571 bittir (python ile hesaplandı). En büyük entropi üçüncü örnektedir; bu, derste verilen cevapla örtüşür.

Slayttaki şekilde (ekrandan, 01:42:50) tüm eğitim kümesi yıldızlarla, mevcut eğitim kümesi üçgenlerle, seçilen örnekler yuvarlaklarla gösterilmişti. Mavi sınıf ayrı bir bölgedeyken kırmızı ve sarı sınıflar iç içe geçmişti; seçilen yuvarlakların çoğu bu iki sınıfın karıştığı bölgedeydi.

Hoca, kolektif öğrenme dersini alanlara karar ağaçlarında sınıf olasılığının nasıl hesaplanabileceğini sordu. Cevap: örneğin en son düştüğü yaprağa düşen diğer eğitim örneklerinin sınıf dağılımına bakılabilir.

### 4.5 Tahmin varyasyonu: regresyonda

Regresyonda sistem sınıf değil bir sayı tahmin eder, örneğin 3.42. Burada sınıf dağılımı yoktur; bu tahminin güvenini nasıl ölçeriz? Öğrencilerden gelen öneriler ve hocanın cevapları:

- "Eğriye olan uzaklık": eğri bilinmiyor.
- "Bir eşik belirleyip üstünü bir sınıfa, altını öbürüne atamak": gerçek değeri bilmiyoruz, hangi örneğin etiketini isteyeceğimize karar vermeye çalışıyoruz; eşik neye göre belirlenecek?
- "Önceki tahminlerin ortalamasından uzaklık" (ör. tahminlerin ortalaması 75'ken bir tahmin 200 gelirse etiketini iste): bütün örnekler üzerinden ortalama almak iyi olmaz; ama aynı örnek için farklı tahminler üretilebilirse işe yarar.

Hocanın vardığı yöntem şudur: aynı örnek için birden fazla tahmin üretilir ve bu tahminlerin varyansına bakılır. Farklı tahminler farklı epoch'larla, farklı başlangıç ağırlıklarıyla, farklı mimarilerle ya da farklı algoritmalarla üretilebilir. Varyans büyükse örnek tahmin edilemez demektir; hepsi benzer şey söylüyorsa etiketini öğrenmeye gerek yok sayılabilir.

### 4.6 Hangi örnekler seçilmeli ve ne zaman durulmalı?

Mantıken tahmin varyasyonu çok olan örnekler seçilmelidir. B ve C adımları ya önceden belirlenen etiketli örnek sayısına (bütçeye) ulaşılana kadar sürdürülür ya da akademik deneylerde sonuna kadar götürülür. En sonda bütün örnekler alınmış olur ve başarı tüm eğitim kümesinin başarısına eşitlenir. Önemli olan, bu son noktadan önceki kısımdır.

### 4.7 `active_learning.m` deneyleri

Kodda iki seçim stratejisi rastgele seçimle karşılaştırıldı: "önce kolay örnekler" (varyasyonu az olanlar) ve "önce zor örnekler" (varyasyonu çok olanlar). Kolay örnek, sınıf olasılıkları (0.90, 0.05, 0.05) gibi olan örnektir; zor örnek, olasılıkları birbirine yakın olan. Grafiklerde x ekseni B ve C adımlarının kaç kez tekrarlandığı, yani etiketli veri sayısının artışıdır; son nokta (20) bütün verinin elde olduğu durumdur. Veri kümeleri: segment, vehicle, autos, iris, hillValley, audiology.

"Önce kolay örnekler" grafiklerinde (ekrandan, 01:50:00) segment kümesinde tüm verinin başarısı yaklaşık 0.76'ydı. Rastgele seçim bu değere hızlı bir yükselişle yaklaşırken önce-kolay seçimi uzun süre çok daha aşağıda kaldı; yani kolayları önce almak rastgeleden kötüydü. Mavi çizginin (önce kolay) belirgin biçimde yukarıda olduğu bir veri kümesi görülmedi.

"Önce zor örnekler" grafiklerinde (ekrandan, 01:51:05):

- iris kümesinde iki yöntem de 20 adımın yaklaşık 6'sında, yani verinin %30 civarıyla tüm verinin doğruluğuna (yaklaşık 0.93-0.95) ulaştı. Ama rastgele seçim de aynı yere ulaştığı için bunun özel bir anlamı yoktur; iris kolay bir kümedir, rastgele bir parçası da yeter.
- segment kümesinde önce-zor seçimi rastgeleden daha yukarıdan giden bir öğrenme eğrisi çizdi; verinin yaklaşık yarısıyla tüm verinin başarısına ulaşılabildi.
- audiology kümesinde önce-zor seçimi ara adımlarda yaklaşık 0.60'a çıktı; bu, tüm verinin başarısından (yaklaşık 0.53) yüksektir. Sona doğru eklenen örnekler başarıyı düşürmüştür; verideki gürültü gibi nedenlerle daha az veriyle daha yüksek başarı mümkündür.

> **Ders sonrası not:** Hoca segment grafiğini anlatırken bir yerde "önce kolayları seçtiğimde oldukça iyi bir sonuç" dedi (01:53:26); bağlam ve ekrandaki grafik, kastedilenin "önce zor" seçimi olduğunu büyük olasılıkla gösteriyor.

İstenen yapı, tüm verinin başarısını gösteren yatay çizgiye mümkün olduğunca hızlı ve rastgeleden daha yukarıdan varmaktır. Rastgele seçim kabaca doğrusal, adım adım yükselir. Rastgele seçim zaten aynı işi yapıyorsa önce kolay ya da önce zor seçmenin anlamı yoktur.

**Soru:** audiology kümesinde önce zorlar veriliyor, sonra kolaylar; daha doğru tahmin edildiğini varsaydığımız kolay örnekler eklenince doğruluğun düşmesi garip değil mi? Zorluk-kolaylık kararında bir hata olmuş olabilir mi? **Cevap:** Olabilir. Burada veri kümesi giderek büyür (10, 20, 30 ... örnek); başta zor örnekler, sonlara doğru daha kolaylar eklenir. Zorluk, o anki eldeki veriyle eğitilmiş modelin tahminlerine göre belirlenir; bu tahminler çok iyi de çok kötü de olabilir. Düşüş bununla ilgili olabilir.

Hocanın özeti: önce kolay örnekleri vermek iyileştirmiyor; önce zor örnekleri vermenin rastgeleye göre yararlı olduğu veri kümeleri var; bazı veri kümelerinde tüm eğitim örnekleri yerine daha az örnekle daha yüksek test başarısına erişilebiliyor.

## 5. Yarı Eğiticili Öğrenme (Semi-supervised Learning)

### 5.1 Tanım ve temel fikir

Slayttaki tanım (ekrandan, 02:00:00): modelin oluşturulmasında etiketli verilerin yanında etiketsiz verilerin de kullanıldığı problemlerdir. Temel fikir: elde hem etiketli hem de etiketsiz veriler vardır; belirli bir test seti üzerinde, yalnız etiketli verileri kullanmak yerine etiketsizleri de kullanmak daha iyi olur.

Örneğin elde 1000 etiketli ve 100.000 etiketsiz örnek vardır. Test kümesi sabittir. Yalnız 1000 etiketli örnekle bir başarı elde edilir; 100.000 etiketsiz örnek bu başarıyı artırabilir mi? Aktif öğrenmeden farkı, burada etiketsiz örneklerin etiketi istenmez; modelin kendi tahminleri kullanılır.

Slayttaki klasik şekilde üstte yalnız iki etiketli nokta (biri beyaz, biri siyah) ve aralarından geçen düz bir ayırıcı vardır. Altta aynı iki noktanın yanında çok sayıda gri (etiketsiz) nokta vardır; iki yay biçimli yığın oluştururlar ve ayırıcı bu yığınların arasından kıvrılarak geçer. Gri noktaların etiketi bilinmese de onları hesaba katan ayırıcı muhtemelen daha iyidir.

### 5.2 Etiketsiz örneklerin tahmini sınıfları

Model eğitiminde etiketli veriler doğrudan kullanılabilir, etiketsizler kullanılamaz. Bu yüzden etiketsiz örneklerin tahmini sınıflarını hesaplamak gerekir.

**Soru:** Elde az miktarda etiketli veri varken gri noktaların sınıfları nasıl hesaplanır? k-NN gibi bir şey yapılabilir mi? **Cevap:** Yapılabilir, ama şekildeki gibi iki etiketli nokta varken bu 1-NN olur. 1-NN'de iki nokta arasındaki orta çizginin bir tarafındakilerin hepsi beyaz, öbür tarafındakiler siyah olur; yani tek seferde uygulanınca düz ayırıcıdan farksızdır ve çok işe yaramaz. Regresyon problemlerinde de bir regresyon modeliyle etiketsizlerin çıkışları doğrudan tahmin edilebilir.

### 5.3 Tek seferde mi, iteratif mi?

Kritik soru, etiket tahminlerinin tek seferde mi iteratif mi yapılacağıdır. Tek seferde (batch) yapmak bütün etiketsizlere aynı anda etiket tahmin etmektir ve çok fazla şey kazandırmaz. İteratif yöntemde önce eldeki etiketli noktalara en yakın noktalar için tahmin üretilir; sonra bu tahminler kullanılarak onlara yakın noktalar tahmin edilir. Böyle ilerlenirse ilk modelden farklı modeller oluşturmak mümkün olur; şekildeki kıvrımlı ayırıcı bu yolla bulunabilir. Bir iterasyonda etiketsizlerin ne kadarının tahmin edilip ekleneceği ayrıca düşünülmesi gereken bir sorudur. Regresyonda da tek seferde tahmin yerine iteratif ilerlemek muhtemelen daha iyidir.

### 5.4 `semi_supervised_learning.m` örneği

Örnek şekilde (ekrandan, 02:04:30) yıldızlar etiketli eğitim örnekleri, yuvarlaklar etiketi tahmin edilen eğitim örnekleriydi. Üç sınıflı (mavi, kırmızı, sarı) veride yalnız 10 etiketli örnek vardı. Alt sırada üç grafik karşılaştırıldı: orijinal (gerçek) etiketler, orijinal + batch yarı eğiticili tahmin, orijinal + iteratif yarı eğiticili tahmin. Hocanın anlatımına göre batch tahminde kırmızı ile sarının yakın olduğu bir bölgede noktalar tek bir sınıfa kayarken, iteratif tahminde bazı kırmızı noktalar gerçek sınıflarında kaldı. Elde yalnız 10 yıldız olduğu, öbür noktaların etiketlerinin tahmin edildiği unutulmamalıdır.

### 5.5 Deney sonuçları: supervised, batch ve iteratif

Slayttaki grafiklerde (ekrandan, 02:10:00) x ekseni iterasyon (1-10), y ekseni test doğruluğudur. "Supervised" çizgisini hoca, verilerin hepsi etiketliymiş gibi eğitilen model olarak tarif etti ve bunu geçmenin kolay olmayacağını söyledi. Batch yöntem tek adımda sonuca vardığı için supervised ile birlikte düz birer çizgi olarak görünür; iteratif yöntem adım adım ilerlediği için dalgalanır.

Ekrandaki değerler ve hocanın yorumları:

- segment: supervised ve batch yaklaşık 0.70'te; iteratif 0.68-0.69 civarında dalgalanıp 9-10. iterasyonlarda 0.66'ya indi. Batch iyi bir sonuç verdi.
- vehicle: supervised yaklaşık 0.484, batch yaklaşık 0.459. İteratif çoğu iterasyonda batch'ten yukarıdaydı (7-8. iterasyonlarda düştü).
- autos: supervised yaklaşık 0.371, batch yaklaşık 0.378. İteratif 5. iterasyonda yaklaşık 0.42'ye çıkarak supervised'ı geçti, sonra dalgalanarak düştü.
- iris: supervised ve batch yaklaşık 0.928'de üst üste; iteratif 0.92'den başlayıp düştü.
- hillValley: supervised yaklaşık 0.50, batch yaklaşık 0.489; iteratif ilk iterasyonda yaklaşık 0.52 ile supervised'ı geçti, iterasyonlar sürünce düştü.
- audiology: supervised yaklaşık 0.293, batch yaklaşık 0.31; iteratif sona doğru yaklaşık 0.38'e çıktı.

<!-- BELİRSİZ: Hoca 02:10:47 civarında "balans skele baktığımızda %68'lerden ..." diyor; ekrandaki altı grafikte balance-scale kümesi yok, hangi grafiğe atıf yaptığı altyazıdan çıkmıyor. -->

Aktif öğrenme grafiklerinde eğriler sona doğru tüm verinin başarısına varıyordu, çünkü etiketli örnek sayısı gerçekten artıyordu. Burada durum farklıdır: sağa gidildikçe eğitim kümesindeki gerçek olmayan, tahmini etiketli verilerin oranı artar. Başta 10 gerçek etiketli örnek varken her iterasyonda 10'ar örnek eklenir, ama bunların hepsi tahmini etiketlidir. Bu yüzden dalgalanmalar normaldir ve eğrinin sona doğru en tepeye varması beklenmez; sona varmak, bütün etiketsizlerin etiketlerini tahmin edip kullanmak demektir.

Yukarıdan başlayıp aşağı inen bir eğri şunu söyler: modelin ilk tahminlerinden üretilenleri, yani emin olunanları kullan; tahminlerden tahmin, onlardan da tahmin üreterek fazla ilerlersen işi bozarsın. Öte yandan hepsini kullanmanın iyi sonuç verdiği örnekler de vardır. Hiç tahmini etiket kullanmamanın, tek seferde tahminin ve iteratif tahminin her birinin en iyi olduğu durumlar görülmüştür; genel bir şey söylemek zordur. İteratif tahminde nerede durulacağının çok büyük etkisi vardır ve çok fazla salınım vardır. Bu salınım iyi değildir, kararsız modeller üretir. Bu yüzden mümkün olduğunca çok sayıda model eğitip tekrarlı denemelerle sonuçlardan emin olmak gerekir; tek bir denemeye bakarak karar vermek yanıltıcı olabilir.

## 6. Öğrenmenin Transferi (Transfer Learning) ve Self-supervised Öğrenme

### 6.1 Tanım ve amaç

Slayttaki tanım (ekrandan, 02:12:40): bir problemi çözdükten sonra, benzeri başka bir problemi sıfırdan çözmek yerine önceki verileri, modelleri, parametreleri (gerekiyorsa dönüştürerek) kullanmak. Amaç, yeni problemi sıfırdan çözmeye göre daha az maliyetli ya da daha iyi bir çözüm bulmaktır.

### 6.2 Neler transfer edilebilir?

- Veriler: bir veri kümesindeki veriler, uygunsa ve gerekirse üzerinde değişiklik yapılarak başka bir probleme aktarılabilir.
- Modelin tamamı: eğitilmiş model gönderilir, onun üzerinden devam edilir.
- Metinler için kelime vektörleri, resimler için CNN filtreleri.

### 6.3 Self-supervised önceden eğitim

Elde milyonlarca etiketsiz veri varsa, bir model bu verilerle self-supervised (kendi kendine eğiticili) bir yaklaşımla önceden eğitilip sonra hedef probleme aktarılabilir. Self-supervised yaklaşımda girdi ve çıktılar üretilir, yani eğitim etiketli gibi yürür, ama bunun için insan müdahalesi gerekmez. Örnekler:

- Bir metinde sonraki kelimeyi tahmin etmek. Elde sıralı metinlerden oluşan bir derlem varsa bu görev için eğitim kümesi hazırlamak çok kolaydır. Buradaki etiket, insanın vermesi gereken bir sınıf ya da konu değildir.
- Bir cümlede bazı kelimeleri kapatıp kapatılan kelimeleri tahmin etmek.
- Bir resimdeki bir bölgeyi kapatıp orayı tahmin etmek. Etiketsiz resimlerden rastgele bir yer kapatılır; girdi kapatılmış resim, çıktı resmin tamamı ya da yalnız kapalı bölgenin içidir.
- Resmi örneğin 16 kareye ayırıp karıştırmak ve modelden doğru sıralamayı bulmasını istemek.

Bunlar insan etiketlemesine ihtiyaç duymadığı için aslında eğiticisiz (unsupervised) sayılabilir; ama girdi ve çıktılar veriden kendiliğinden üretildiği için self-supervised diye adlandırılır. Görüntü ve metin verileri üzerindeki önceden eğitilmiş modellerin hepsi bu tarz yaklaşımlarla eğitilir. Çünkü çok büyük veriyle eğitilmeleri gerekir ve bu kadar veriyi etiketlemek anlamlı değildir; etiketsiz, self-supervised yapılarla da başarılı sonuçlar alındığı görüldükten sonra bu alan büyük önem kazanmıştır.

### 6.4 Transfer ne zaman işe yarar?

Slayta göre (ekrandan, 02:17:10) iki koşul vardır:

- Eldeki yeni problem için yeterli veri yoksa. Yeterli veri varsa o verilerle eğitim yapılır, transfere gerek kalmaz.
- Eski ve yeni problem ilgili ise.

Hocanın örneği: resimdeki kişinin kadın mı erkek mi olduğunu bulan bir model eğitilecek. Daha önce resimdeki nesnenin kedi mi köpek mi olduğunu öğrenmiş bir modeli alıp buraya aktarmanın ve üzerine ince ayar yapmanın pek anlamı yoktur. Ama self-supervised biçimde, örneğin kapalı parçayı tahmin ederek, göreve ya da sınıfa özgü olmayan bir şeyle eğitilmiş bir modelin ağırlıklarını kullanmak anlamlıdır. Yani bir sınıflandırma problemini başka bir sınıflandırma problemine aktaracaksanız ikisi birbiriyle ilgili olmalıdır. Self-supervised modeller için bu koşul geçerli değildir; onlar belli bir sınıflandırma problemi değildir, oldukça geneldir. Farklı NLP uygulamalarında, o uygulamalarla hiç ilgisi olmayan self-supervised önceden eğitimler oldukça başarılı sonuçlar verir.

Slayttaki grafikte yatay eksen görev ilgisi (task relatedness), dikey eksen transfer başarısıdır (transfer performance). "Aggressive" çizgisi (slayta göre: çok fazla bilgi transferi) dik bir doğrudur: görevler ilgiliyse çok kazandırır, ilgisizse başarıyı sıfırın altına indirir. "Safe" çizgisi daha az eğimlidir. Slayttaki nota göre benzer bir karakteristik yarı eğiticili öğrenme için de söylenebilir.

> **Ek bilgi (derste anlatılmadı):** Transferin hedef problemdeki başarıyı sıfırdan eğitime göre düşürmesine literatürde negatif transfer (negative transfer) denir. Grafikteki aggressive çizgisinin ilgisiz görevlerde sıfırın altına inen kısmı bu durumu gösterir. Yarı eğiticili öğrenmede çok iterasyonla tahminlerden tahmin üretmenin başarıyı düşürmesi de benzer bir risktir.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:39:03): Üç sınıflı bir problemde softmax çıkışı üç örnek için şöyledir: (0.60, 0.30, 0.10), (0.05, 0.90, 0.05), (0.30, 0.30, 0.40). Aktif öğrenmede bu örneklerden hangisinin etiketini istemek daha iyidir?

> **Çözüm (derste verildi):** Sınıf olasılıkları birbirine en yakın olan üçüncü örnek (0.30, 0.30, 0.40). Model bu örnek için en belirsizdir; örnek büyük olasılıkla sınıfların birbirine yakın olduğu bir bölgededir. Entropiyle doğrulama (python ile hesaplandı): $H_1 \approx 1.295$, $H_2 \approx 0.569$, $H_3 \approx 1.571$ bit; en büyük entropi üçüncü örnektedir.

**Soru 2** (derste sözlü, 01:43:15): Aktif öğrenmede karar ağaçlarıyla bir örneğin sınıf olasılıkları (tahmin varyasyonu) nasıl hesaplanabilir?

> **Çözüm (derste verildi):** Örneğin ağaçta en son düştüğü yaprağa düşen diğer eğitim örneklerinin sınıf dağılımına bakılır; bu dağılım sınıf olasılıkları gibi kullanılır.

**Soru 3** (derste sözlü, 01:43:52): Regresyon problemlerinde tahmin varyasyonu nasıl ölçülebilir? Sistem bir örnek için yalnız bir sayı (ör. 3.42) tahmin ediyor.

> **Çözüm (derste verildi):** Aynı örnek için birden fazla tahmin üretilir (farklı epoch, farklı başlangıç ağırlıkları, farklı mimari ya da farklı algoritma) ve bu tahminlerin varyansına bakılır. Varyans büyükse örnek tahmin edilemez sayılır ve etiketi istenir; tahminler benzerse etiketi istemeye gerek yoktur. Bütün örneklerin tahminlerinin ortalamasından uzaklığa bakmak iyi bir ölçü değildir.

**Soru 4** (derste sözlü, 01:46:48): Aktif öğrenmede tahmin varyasyonu çok mu, az mı olan örneklerin etiketleri istenmeli? B ve C adımları ne zaman durmalı?

> **Çözüm (derste verildi):** Varyasyonu çok olanların. Adımlar önceden belirlenmiş etiketli örnek sayısına (bütçeye) ulaşılınca durdurulur; akademik deneylerde sonuna kadar götürülebilir, en sonda bütün örnekler alınmış olur.

**Soru 5** (derste sözlü, 02:01:50): Yarı eğiticili öğrenmede elde az sayıda etiketli veri varken etiketsiz (gri) örneklerin sınıfları nasıl hesaplanabilir? k-NN kullanılabilir mi?

> **Çözüm (derste verildi):** k-NN kullanılabilir, ama şekildeki gibi iki etiketli nokta varken bu 1-NN'dir ve tek seferde uygulanırsa iki nokta arasındaki orta çizgiye göre bölme yapar; düz ayırıcıdan farkı olmaz. Tahminleri iteratif yapmak daha makuldür: önce etiketli noktalara en yakın etiketsiz noktalar etiketlenir, sonra bu yeni etiketlerle onlara yakın noktalar, böylece veri yığınlarını izleyen bir ayırıcı bulunabilir.

**Soru 6** (derste sözlü, 02:17:27): Resimdeki kişinin kadın mı erkek mi olduğunu bulan bir model için, kedi/köpek ayıran bir sınıflandırıcıdan transfer yapmak mantıklı mıdır? Self-supervised bir modelden transfer için ne söylenebilir?

> **Çözüm (derste verildi):** Kedi/köpek sınıflandırıcısından aktarıp ince ayar yapmanın pek anlamı yoktur, çünkü iki sınıflandırma problemi ilgili değildir. Kapalı parçayı tahmin etmek gibi göreve özgü olmayan self-supervised bir görevle eğitilmiş modelin ağırlıklarını kullanmak ise anlamlıdır; self-supervised modeller geneldir.

## Dersin Toparlaması

Dersin ilk yarısında öğrenciler kelime vektörü yöntemlerini (word2vec, FastText, GloVe, Doc2Vec, BERT) duygu analizi, metin üretimi ve benzer kelime bulma gibi uygulamalarda karşılaştırdı. Çalışmaların çoğunda FastText, alt parça (n-gram) bilgisiyle sözlük dışı kelime sorununu çözdüğü için öne çıktı; bir çalışmada büyük ve konu dışı bir derlem, küçük ve ilgili bir derlemden biraz daha iyi sonuç verdi. Hocanın düzeltmeleri dersin kalıcı kısmıdır: derlem etiketsizdir ve önceden eğitim içindir, etiketli veri kümesi ise ince ayar ve test içindir; hazır vektör kullanmak derlem etkisini ölçmez; test örnekleri derleme konmamalıdır; sonuçlar bütün sınıflandırıcılarla ve sayısal ölçütlerle raporlanmalıdır.

İkinci yarıda makine öğrenmesinde etiketli veri azlığına karşı geliştirilen üç yaklaşım işlendi. Aktif öğrenme, modelin en belirsiz bulduğu örneklerin etiketini isteyerek etiketleme maliyetini düşürür; deneylerde önce zor örnekleri seçmek bazı veri kümelerinde rastgele seçimden hızlı yükseldi, önce kolayları seçmek işe yaramadı. Yarı eğiticili öğrenme, etiketsiz örneklere modelin tahmin ettiği etiketleri vererek onları da eğitime katar; tek seferde ya da iteratif yapılabilir, ama tahminlerden tahmin üretmek hataları biriktirir ve sonuçlar kararsızdır. Öğrenmenin transferi, önceki problemin verilerini, modelini ya da parametrelerini yeni probleme taşır; yeni problemde yeterli veri yoksa ve problemler ilgiliyse işe yarar. Görevden bağımsız self-supervised önceden eğitim ise ilgisiz uygulamalarda da başarılıdır. Konu listesinde sıradaki başlık çok görevli eğitimdir (multi-task learning).

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
