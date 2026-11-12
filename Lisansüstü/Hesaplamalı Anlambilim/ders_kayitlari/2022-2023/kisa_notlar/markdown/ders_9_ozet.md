# Ders 9 Çalışma Özeti

## Genel Konular

- Bölüm 6'ya giriş: Uygulamalar
  - Bu derste ders notlarının "Uygulamalar" başlıklı Bölüm 6'sına başlandı (ekrandan, 00:10:00). Slayttaki içerik listesi: metin sınıflandırma, duygu durum analizi, varlık ismi tanıma, paragraf anlama, soru cevaplama, metinlerde çıkarım, CNN ve RNN hakkında, metin/haber/hikâye/şiir üretimi, sohbet ve sanal asistan uygulamaları.
  - Bu derste ilk üç uygulama (metin sınıflandırma, duygu durum analizi, varlık ismi tanıma) kısaca anlatıldı. Dersin ikinci ve daha uzun kısmında öğrenciler, sıfır çekimli (zero-shot) sınıflandırmada prompt etkisini inceleyen çalışmalarını sundu.
- Metin sınıflandırma (ekrandan, 00:10:00)
  - Tanım: elimizdeki bir metni önceden tanımlanmış kategorilerden birine atamak. Uygulamalar: e-postanın spam olup olmadığı, son dakika haberlerinin kategorisi vb.
  - Çok etiketli (multi-label) sınıflandırma: bir metin birden fazla kategoriye ait olabilir; örneğin bir haber hem siyaset hem ekonomi ile ilgili olabilir. İki temel yaklaşım anlatıldı:
    - Tek sınıflandırıcı ve eşik: sınıflandırıcı her sınıf için bir olasılık verir; eşiğin (örneğin %30) üstündeki bütün sınıflar etiket kabul edilir. Eğitim kümesinde hedef one-hot değil, örneğin ait olduğu bütün sınıflar 1, diğerleri 0 olan bir vektördür.
    - Sınıf başına ikili sınıflandırıcı: $K$ kategori için $K$ ayrı ikili (binary) sınıflandırıcı eğitilir ("ekonomi haberi mi, değil mi?" gibi). Bir metin birden fazlasından "evet" alabilir.
  - Slayttaki deney (ekrandan, 00:10:00): 13 sınıflı haber metinleri LSI ile $13 \cdot 5 = 65$ boyuta indirgenmiş; test örnekleri sabit ve her sınıf için 250 tane; eğitim örneği sayısı arttırılmış. Grafikte test başarısı, sınıf başına yaklaşık 10 eğitim örneğinde %20 civarından 250 örnekte %50 civarına yükselir. Aynı iş tf, binary, tf-idf, kelime n-gram temsilleriyle de yapılabilir (kodlar: `text_classify_lsi.m`, `text_classify_tfidf.m`).
- Eğitim kümesi büyüdükçe test başarısı neden artar? (00:15:22)
  - Eğitim kümesi büyüdükçe test kümesine benzeyen örneklere sahip olma ihtimali artar; eğitim dağılımı test dağılımına yaklaşır. Uç durumda test kümesiyle eğitim yapılsaydı test başarısı %100'e yaklaşırdı.
  - Hocaya göre kaliteli (iyi etiketlenmiş) veriyle eğitim kümesini büyütmek, performansı arttırmanın bilinen en garantili yoludur.
- Duygu durum analizi (ekrandan, 00:20:00 ve 00:36:00)
  - Bir firma, kişi, parti, kurum ya da olay hakkında kamuoyu algısını ölçmektir. Sosyal medya verisi anketlere göre çok daha ucuzdur; güvenilirlik açısından olumlu ve olumsuz yanları vardır.
  - Algı operatörü botlar: slayta göre tahminen %20 civarındadır (hoca bu rakamın 2020 civarına ait olduğunu, sonrasını bilmediğini söyledi). Tek kişinin yönettiği binlerce bot, toplu görünen hareketler yaratabilir; sıradan kullanıcı bunu fark edemeyebilir.
  - Eğitim kümesi eskir: yeni jargonlar ortaya çıkar. Örneğin 2015 verisiyle eğitilen model 2016'da çalışır, ama eğitim ile test arasındaki zaman farkı arttıkça performans düşer. Çözüm, eğitim kümesini sürekli güncellemektir; bu spam dedektörleri için de geçerlidir.
  - Metin temsili: klasik yaklaşımlar (kelime, kelime kökü, n-gram) ve yeni yaklaşımlar (semantik uzaylar, LSTM, CNN; son dönemde Transformer'lar).
- Duygu durum analizi deneyi: CNN ile metin sınıflandırma (ekrandan, 00:30:00)
  - Veri kümesi: bir GSM operatörü hakkındaki tweet'lerin elle etiketlenmesiyle oluşturulmuş. Eğitim: olumlu 3663, olumsuz 5511, nötr 4658 (toplam 13832); test: 916, 1377, 1164 (toplam 3457); genel toplam 17289.
  - Slayttaki tarif: M matrisi bir metindir; $n_m$ satır, $d_m$ sütun. $d_m$ kelimelerin temsil edildiği vektörlerin boyutu, $n_m$ maksimum metin uzunluğudur. Kelimelerin vektörleri metindeki sırayla satırlara yazılır, kısa metinlerde kalan satırlar 0 ile doldurulur. M üzerinde $t$ adet $k_m \times d_m$ boyutlu filtre gezdirilir, sonuçlar F'de tutulur. F'nin her sütununun maksimumu B vektörüne yazılır. B ile S çıkış vektörü arasında tam bağlı bir katman vardır.
  - Resimlerden farkı: filtre iki boyutta değil, yalnız satırlar boyunca kaydırılır; filtre genişliği kelime vektörünün boyutudur (örneğin $2 \times 300$). 2 satırlık filtre kelime ikililerini, 3 satırlık filtre kelime üçlülerini yakalar.
  - Token kelime ya da karakter olabilir. Slayttaki örnek "Allah cezanı versin XXX tüm müşterilerini kaybedersin inşallah." için kelime tabanlı M matrisi 100 boyutlu kelime vektörleriyle (9 dolu satır, gerisi 0), karakter tabanlı M matrisi ise one-hot karakterlerle (yaklaşık 84 karakter) kurulmuştur. Karakter tabanlıda filtreler karakter n-gramlarına karşılık gelir; daha büyük filtreler makul olabilir.
- Karşılaştırma sonuçları (ekrandan, 00:36:00)
  - Kelime torbası %66,28; karakter 3gram torbası %66,92; kelime vektörü ortalamaları %66,33; kelime bazlı LSTM %65,35; kelime bazlı CNN %67,14; karakter bazlı CNN %69,25. Slayt notu: son 3 yaklaşımın çok fazla hiperparametresi var.
  - Hocaya göre bu veri kümesinde Transformer modelleriyle (BERTurk gibi) %75 civarına erişilmiştir. Fark, bu modellerin büyük bir ön derlemden gelen harici bilgiyi kullanmasıdır; tablodaki yöntemler yalnız veri kümesini görür.
- Duygu durum analizi zordur (ekrandan, 00:40:00)
  - "Yemeğimi 5 dakikada getirdiniz çok teşekkürler." olumlu, "Yemeğimi 55 dakikada getirdiniz çok teşekkürler" ise iğnelemeli ve olumsuzdur; aralarında tek karakter farkı vardır. "2500 tl lik fatura için çok teşekkürler" da benzerdir.
  - Bunu yalnız sözdizimine bakarak anlamak mümkün değildir; sistemin yemek getirmenin normalde ne kadar sürdüğü gibi dünya bilgisine ihtiyacı vardır.
- Varlık ismi tanıma (Named Entity Recognition) (ekrandan, 00:40:00 küçük resim; anlatım 00:41:29)
  - Bir metnin içindeki önceden tanımlanmış varlıkları ve türlerini bulmaktır. Örnek: "Akbank 8. Caz Festivali ..." metninde kurum (Akbank), yer (İstanbul, Ankara, Adana), kişi adları ve tarihler.
  - Sekanstan sekansa (seq2seq) bir problemdir: giriş metin, çıkış her token için bir sınıf etiketidir. Varlık olmayan tokenlar için de "hiçbiri" (O/null) etiketi gerekir.
  - Slayttaki yaklaşım: klasik yaklaşım CRF; burada karakter tabanlı LSTM; giriş karakter one-hot vektörleri, çıkış karakterin sınıfı. 3 sınıflı (kurum, yer, kişi) ve 7 sınıflı (ek olarak tarih, yüzde, para, zaman) problemlerde denenmiş; varlık olmayan kısımlar çok yüksek başarıyla bulunur, varlık türlerinde başarı eşit değildir.
  - Makine çevirisinden farkı: varlık ismi tanımada giriş ve çıkıştaki token sayısı eşittir, sınıf sayısı az (3-7) dir. Makine çevirisinde uzunluklar farklı olabilir ve sınıf sayısı hedef dilin sözlük boyutu (örneğin 32 bin) kadardır. Yine de ikisi de özünde sınıflandırmadır.
- Öğrenci sunumları: sıfır çekimli sınıflandırmada prompt analizi (01:06:01 sonrası)
  - Ortak düzen: her sınıf için birkaç prompt yazılır; prompt ve test metni bir dil modeliyle vektöre çevrilir; metin, temsili en benzer (genelde kosinüs benzerliği) prompt'un sınıfına atanır; eğitim yapılmaz. Bir veri kümesi haber/konu sınıflandırma (BBC News, AG News, 20 Newsgroups, Türkçe haber), diğeri duygu analizi (IMDB, Rotten Tomatoes, Yelp, restoran yorumları, Türkçe tweet'ler, EMO2019).
  - Kullanılan modeller: BERT, RoBERTa, ALBERT, ELECTRA, GPT-2, XLNet, MPNet ve T5 tabanlı cümle modelleri, fastText, word2vec, NLI modelleri (BART, DeBERTa, Türkçe BERT tabanlı NLI, çok dilli mDeBERTa).
  - Prompt üretme yolları: yalnız sınıf adı; "text is about ..." gibi önek; sözlük tanımı; anahtar kelime API'si; terim frekansı ve TF-IDF ile sınıfa özgü kelimeler (bütün sınıflarda ortak sık kelimeler elenerek); POS etiketiyle filtre; word2vec ile sınıf adına en yakın kelimeler; WordCloud; n-gram'lar; elle yazılmış cümleler; GPT'ye cümle ürettirme; genetik algoritmayla prompt arama (yakınsamadı).
  - Öne çıkan bulgular: cümle benzerliği için kontrastif öğrenmeyle ince ayarlanmış cümle modelleri ham BERT'ten iyi sonuç verdi; tek kelimelik ya da anlamsız kelime yığını prompt'lar, anlamlı cümle prompt'lardan genelde kötü temsil edildi; veri kümesine özgü kelimeler (örneğin BBC için İngiliz futboluna özgü adlar) konu sınıflandırmada başarıyı arttırdı, ama duygu analizinde konuya özgü prompt'lar başarıyı düşürdü; TF-IDF ile seçilen kelimeler word2vec'e göre daha iyi çalıştı, çünkü word2vec veri kümesine bakmaz.
  - NLI tabanlı yaklaşım: öncül (metin) ve hipotez (prompt) modele verilir; çıktı çelişki (contradiction), gerektirme (entailment) ve nötr olasılıklarıdır; gerektirme olasılığı sınıflandırmada kullanılır.
  - Maskeli dil modeli yaklaşımı: prompt'taki sınıf kelimesi [MASK] ile değiştirilir; her sınıf için seçilmiş kelimelerin (örneğin good/positive ve bad/negative) skorları toplanır, yüksek olan sınıf seçilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Eğitim kümesini büyütmek
  - Kaliteli verinin miktarını arttırmak test performansını arttırmanın en sağlam yoludur; çünkü eğitim kümesi test kümesine giderek benzer hale gelir.
- Eğitim kümesinin eskimesi
  - Test verisi zamanla değişirken eğitim kümesi sabit kalırsa ikisi birbirinden uzaklaşır. Duygu analizinde ve spam tespitinde eğitim kümesi sürekli güncellenmelidir.
- Harici bilgi
  - Yalnız veri kümesine bakan modeller ile büyük bir ön derlemde ön eğitilmiş modelleri (BERTurk gibi) karşılaştırırken, ikincisinin harici bilgi kullandığını unutmamak gerekir.
- Duygu analizinin zorluğu
  - Tek karakter farkıyla anlam tersine dönebilir (5 dakika / 55 dakika); bunu çözmek için dünya bilgisi gerekir.
- Seq2seq problemleri birer sınıflandırmadır
  - Makine çevirisi de, varlık ismi tanıma da her adımda bir vektörü bir sınıfa atar; fark sınıf sayısındadır (birkaç sınıf ya da 32-64 bin kelimelik sözlük).
- Sıfır çekimli değerlendirmede ölçüt
  - Sunumlardaki soru-cevaplarda hoca, sonucun ortalama benzerlik değeri olarak değil, sınıflandırma başarısı (doğru/yanlış sınıflandırılan örnek oranı) olarak verilmesi gerektiğini vurguladı. Dengeli iki sınıflı bir veride %50'nin altında bir başarı, yöntemde bir hata olduğunu gösterir.

## Kısa Tekrar Notları

- Bölüm 6: Uygulamalar. Bu ders: metin sınıflandırma, duygu durum analizi, varlık ismi tanıma.
- Çok etiketli sınıflandırma: tek sınıflandırıcı + olasılık eşiği ya da sınıf başına ikili sınıflandırıcı.
- LSI deneyi: 13 sınıf, 65 boyut, test sınıf başına 250; eğitim örneği arttıkça test başarısı artar.
- Duygu analizi: kamuoyu algısı; botlar (tahminen %20); eğitim kümesi eskir.
- CNN ile metin: $n_m \times d_m$ M matrisi, $k_m \times d_m$ filtreler yalnız satır boyunca, sütun maksimumu (B), tam bağlı katman (S).
- Sonuçlar: karakter bazlı CNN %69,25 en iyisi; BERTurk gibi ön eğitimli modellerle %75 civarı.
- 5 dakika / 55 dakika: duygu analizi için dünya bilgisi gerekir.
- Varlık ismi tanıma: her token için sınıf; "varlık değil" etiketi gerekir; karakter tabanlı LSTM; klasik yaklaşım CRF.
- NER ve çeviri: NER'de giriş-çıkış uzunlukları eşit ve sınıf az; çeviride uzunluklar farklı ve sınıf sayısı sözlük boyutu.
- Zero-shot prompt analizi: prompt ve metin temsillerinin benzerliği; cümle modelleri ham BERT'ten iyi; anlamlı cümle prompt'lar kelime yığınından iyi.
- NLI ile zero-shot: öncül = metin, hipotez = prompt; gerektirme olasılığı kullanılır.

## Detaylı Açıklamalar

- Çok etiketli sınıflandırmanın iki yolu
  - Birinci yolda tek bir model, çıkışta her sınıf için bir olasılık verir. Eğitim hedefi, örneğin ait olduğu bütün sınıfların 1 olduğu bir vektördür. Tahminde bir eşik seçilir ve eşiğin üstündeki her sınıf etiket olarak atanır. İkinci yolda her kategori için ayrı bir ikili model eğitilir; ekonomi, siyaset ve spor için üç model "bu haber ekonomi haberi mi?" gibi soruları bağımsız olarak cevaplar. Bir metin birden fazla modelden olumlu cevap alabilir.
- Eğitim kümesi büyüklüğü ile test başarısı
  - Hoca soruyu sınıfa sorduktan sonra şu sezgiyi verdi: başarı test kümesi üzerinden ölçülür. Test kümesiyle eğitim yapılsaydı başarı çok yüksek olurdu. Eğitim kümesi büyüdükçe test örneklerine benzeyen eğitim örneklerinin bulunma ihtimali artar, yani eğitim kümesi test kümesine "yakınsar". Bu yüzden eğitim kümesini büyütmek, başka bir modele geçmek ya da gürültüyle uğraşmak gibi yollardan önce gelen en güvenli yöntemdir.
- CNN'in metne uygulanması
  - Resimde $3 \times 3$ ya da $5 \times 5$ filtre iki boyutta kaydırılır. Metinde ise her satır bir tokenın vektörü olduğu için filtre bütün sütunları kaplar ve yalnız aşağı doğru kaydırılır. $k_m = 2$ olan bir filtre ardışık kelime ikililerinin (ya da benzerlerinin) metinde olup olmadığını gösterir. Her filtrenin bütün konumlardaki sonuçlarının maksimumu alınarak sabit boyutlu B vektörü elde edilir; bu da tam bağlı katmanla sınıf çıkışına (S) bağlanır. Token karakter olunca filtreler karakter n-gramlarını yakalar.
- Ön eğitimli modellerin avantajı
  - Tablodaki en iyi sonuç %69,25 (karakter bazlı CNN) iken BERTurk gibi modellerle %75 civarına çıkılmıştır. Hoca bunun nedenini mimariden çok, bu modellerin büyük bir derlemde ön eğitilmesine, yani harici bilgi taşımasına bağladı.
- Varlık ismi tanımanın kodlanması
  - Giriş olarak metnin karakterleri sırayla one-hot vektör olarak verilir; çıkışta her karaktere o karakterin ait olduğu varlık sınıfı (örneğin "Akbank" kelimesi boyunca kurum sınıfı) one-hot olarak verilir. Varlık olmayan karakterler için ayrı bir etiket kullanılır. Böylece problem, giriş ve çıkış uzunluğu eşit bir sekanstan sekansa sınıflandırma problemine dönüşür.
- Sıfır çekimli prompt analizinde gözlenen sorunlar
  - Kelime yığını prompt'lar (birbiriyle cümle oluşturmayan kelimeler) dil modelleri tarafından iyi temsil edilmez; hocaya göre bu modeller eğitimde böyle girdiler görmemiştir. Benzerlik değerlerinin hepsi 0,99'un üstünde ve birbirine çok yakın çıkıyorsa, bu gürültüyü aşan bir sinyal olmadığını, büyük olasılıkla hesaplamada bir hata bulunduğunu gösterir. Dengeli iki sınıflı veride %32 başarı, tahminler ters çevrilince %68 başarı demektir; bu da yöntemde bir hata işaretidir. Birbirini tamamlayan modeller (örneğin BART ve DeBERTa) bir topluluk (ensemble) içinde birlikte kullanılırsa daha iyi sonuç alınabilir.
  - Ders sonrası not: slayttaki veri tablosunda olumsuz sütununun toplamı 6887 yazıyor; $5511 + 1377 = 6888$'dir. Satır toplamları (13832 + 3457 = 17289) tutarlıdır (python ile hesaplandı).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
