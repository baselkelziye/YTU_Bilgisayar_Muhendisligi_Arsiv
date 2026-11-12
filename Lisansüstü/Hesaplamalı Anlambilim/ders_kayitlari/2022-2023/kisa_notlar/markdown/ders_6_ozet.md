# Ders 6 Çalışma Özeti

## Genel Konular

- Bölüm 4'ün amacı ve kaldığımız yer
  - Bölüm 4 ("makine öğrenmesi versiyon 2"), son dönemde ortaya çıkan problem ve yaklaşım türlerini anlatır. Hoca bu konuların yalnız NLP'ye değil her tür veriye ve uygulamaya uygulanabildiğini, araştırmalara yeni boyut katabileceğini söyledi.
  - Kısa tekrar: aktif öğrenmede algoritma, etiketi bilinmeyen örneklerden hangilerinin etiketini isteyeceğini seçer; amaç etiketleme maliyetini düşürmektir. Yarı eğiticili öğrenmede etiket satın alacak bütçe yoktur; etiketli verilerle kurulan model etiketsiz verilere tahmini etiket (pseudo-label) üretir, bu etiketler gerçek etiketlerle birleştirilip model yeniden eğitilir, süreç iteratif de olabilir.
  - Yarı eğiticili öğrenme bulguları (ekrandan, 00:10:00): tahmini etiketleri hiç kullanmamanın da, tek seferde tahmin etmenin de, iteratif tahminin de diğerlerinden iyi olduğu sonuçlar vardır; iteratif tahminde nerede durulacağı sonucu etkiler.
- Öğrenmenin transferi (transfer learning)
  - Tanım: bir problemi çözdükten sonra benzer başka bir problemi sıfırdan çözmek yerine önceki verileri, modelleri, parametreleri (gerekirse dönüştürerek) kullanmak. Amaç: yeni problemi sıfırdan çözmeye göre daha az maliyetle ya da daha iyi bir çözüm bulmak.
  - En yaygın kullanım: çok büyük veriyle eğitilmiş ve araştırmacıların erişimine açık bir önceden eğitilmiş (pre-trained) model alınır, kendi küçük verimizle ince ayar (fine-tune) yapılır. İnce ayar da bir eğitimdir; farkı, rastgele başlangıç yerine büyük veride optimize edilmiş parametrelerden başlamasıdır. Hiç ince ayar yapmadan kullanma (zero-shot) da mümkündür.
  - Neler transfer edilebilir (ekrandan, 00:14:30): veriler (aynen ya da değiştirilerek), tüm model, metinler için kelime vektörleri (sabit ya da adaptif), resimler için CNN filtreleri (sabit ya da adaptif).
  - CNN'de ilk katmanlar yön ve gradyan gibi veri kümesinden veri kümesine az değişen temel özellikleri öğrenir; son katmanlar sınıfa ve veri kümesine özgüdür. Bu yüzden ilk katmanlar kolay transfer edilir, son katmanlar ince ayarla uyarlanır.
  - Ne zaman işe yarar (ekrandan, 00:16:10): eldeki yeni problem için yeterli veri yoksa ve eski ile yeni problem ilgiliyse. Slayttaki grafikte transfer performansı görev ilişkisine (task relatedness) göre çizilir: "aggressive" transfer çok fazla bilgi aktarır, "safe" daha temkinlidir; benzer bir karakteristik yarı eğiticili öğrenme için de söylenebilir. Resim için öğrenilen özellikleri doğrudan metinde kullanmak gibi ilgisiz problemler arasında transfer uygun değildir.
- Çok görevli eğitim (multi-task learning)
  - Aynı anda birden fazla şeyi öğrenmek, çok sayıda veri kümesini aynı yapı içinde modellemek; "hem satranç hem dama oynayabilen tek bir sistem" (ekrandan, 00:17:45). Transfer öğrenmede kaynak görevden hedef göreve tek yönlü bir aktarım vardır; çok görevli öğrenmede birçok görev birbirini karşılıklı etkiler.
  - Görüntü örneği (ekrandan, 00:20:00): giriş görüntüsü ortak bir kodlayıcıdan (encoder) geçer; anlamsal bölütleme, örnek (instance) bölütleme ve derinlik kestirimi için üç ayrı kod çözücü (decoder) vardır. Üç görevin belirsizlikleri birleştirilerek tek bir çok görevli kayıp (multi-task loss) oluşturulur. Ortak kodlayıcı sayesinde bir görevde öğrenilen (örneğin nesneleri tanımak) diğerine (derinlik bulmak) yarayabilir.
  - NLP Decathlon (ekrandan, 00:24:20): makine çevirisi, özetleme, duygu analizi, soru cevaplama, gerektirme (entailment) gibi farklı girdi-çıktı yapılı görevler tek bir "soru, bağlam, cevap" (question, context, answer) biçimine dönüştürülür. Örnek: soru "İngilizceden Almancaya çevirisi nedir?", bağlam İngilizce cümle, cevap Almancası. Hoca bunu bugünkü istem (prompt) tabanlı sistemlere bir geçiş olarak da değerlendirdi.
- Birbiriyle ilgisiz veri kümelerinde çok görevli eğitim deneyi (kod multi_task_learning.m)
  - 2 boyutlu, 2 sınıflı, birbiriyle hiç ilgisi olmayan 5 veri kümesi; 10 gizli nöronlu tek gizli katmanlı yapay sinir ağı, eşit eğitim süresi, 3 deneme (ekrandan, 00:30:00). "Single": her veri kümesi ayrı eğitilir; "multi": beş veri kümesi tek veri kümesine dönüştürülüp birlikte eğitilir.
  - Birlikte eğitimde ağa örneğin hangi veri kümesinden geldiği (veri kümesi kimliği gibi ek bir giriş) söylenmelidir; aksi halde bağımsız veri kümeleri anlamlı biçimde kodlanamaz.
  - Sonuç: bazı veri kümelerinde başarı düşmüş, bazılarında değişmemiş, bazılarında artmıştır; korkunç bir kötüleşme yoktur. Bulgu-yorum (ekrandan, 00:35:20): iyileşmenin olduğu veri kümeleri var; genel bir şey söylemek için çok daha fazla denemeye ihtiyaç var; bir ağ kaç problemi kapsayabilir, ağın karmaşıklığı artarsa ne olur soruları açıktır.
- Çok görevli eğitim ile çok kipli (multimodal) modellerin farkı (derste sözlü soru)
  - Multimodal modellerde girdi farklı biçimlerdedir (görüntü, ses, metin, video); bunlar girdinin farklı özellikleri gibi gelir ve birleştirilmesinin farklı yolları vardır. Görevler genelde ilişkilidir. Çok görevli eğitimde ise asıl nokta birden fazla görevin (çıktının) birlikte öğrenilmesidir.
- Hiperparametre optimizasyonu
  - Hiperparametre: modelin veriye bakarak kendi öğrenemediği, kullanıcıdan beklediği parametreler. Seçimi deneme yanılmaya dayanır; bir deneme bir gün sürüyorsa 10 konfigürasyon 10 gün sürer. Derin öğrenmede hiperparametrelerin büyük kısmı (örneğin %90-95'i) önceki araştırmacıların önerdiği varsayılan değerlerde bırakılır, yalnız birkaçı optimize edilir.
  - Hiperparametre optimizasyonu, bir optimizasyon problemini çözmek için çözülen ikinci bir optimizasyon problemidir.
  - Yöntemler (ekrandan, 00:40:00): ızgara (grid) arama, rastgele arama, Bayesian optimizasyon. Izgara aramada tek hiperparametre için aralık eşit parçalara bölünür (slaytta 0:0.1:1); rastgele aramada aralıktan rastgele değerler seçilir.
  - Bayesian optimizasyon, eldeki deneme sonuçlarına göre en fazla iyileşme sağlayabilecek değeri tahmin eder ve bir sonraki denemeyi oradan yapar. Hoca ekranda üç rastgele denemenin ardından dördüncünün en makul olarak, aralarında düşüş görülen ve daha geniş olan iki nokta arasından seçildiğini gösterdi. Daha az denemeyle iyi sonuç sağlayabilir, ama kesin ya da optimal bir süreç değildir.
- Aktif örnekleme (active sampling)
  - Bayesian optimizasyondan esinlenir (ekrandan, 00:50:00). Aktif öğrenmede etiketsiz verilerin hangilerinin çıkışlarının kullanıcıdan isteneceği belirlenir; aktif örneklemede ise örneklerin kendileri (girdi ve çıkış birlikte) istenir: "girdi uzayının şu bölgesinden bana yeni bir örnek üret ve etiketle."
  - Model kendi eğitim kümesinin oluşturulmasında söz sahibidir; kullanıcıdan aktif öğrenmeden de yarı eğiticili öğrenmeden de daha fazlasını talep eder. Duygu analizinde karşılığı: "içinde şu kelime ve şu kelime geçen yorumları bul, etiketle, bana ver."
  - Hangi bölgeden (ekrandan, 00:51:00): model varyansının en yüksek olduğu yerler tahminlere en az güvenebileceğimiz yerlerdir. Modelin bir noktadaki varyansı, farklı eğitim kümeleriyle o noktada yapılan tahminlerin standart sapmasıdır. Yeni örnek buralardan istenmelidir; slayttaki örnekte örneklerin seyrek olduğu bölgede farklı modellerin tahminleri en çok ayrışır.
- Ödev sunumları: metin sınıflandırmada anlamsal uzayların karşılaştırılması
  - Ödevde öğrenciler en az biri konu sınıflandırma, diğerleri konu dışı sınıflandırma olan üç veri kümesinde klasik yöntemleri (TF ve TF-IDF, 2-6 karakter n-gram), LSA, LDA, birlikte geçme matrisi, word2vec, GloVe, FastText ve BERT, GPT-2, RoBERTa gibi sinirsel dil modellerini karşılaştırdı, temsilleri birleştirmeyi denedi. Değerlendirme genelde 5 katlı çapraz geçerleme ile ortalama ve standart sapma üzerinden yapıldı.
  - Birleştirme yolları: vektörleri uç uca ekleme (concatenation), iki modelin vektörlerinin yarılarını ya da dört modelin çeyreklerini alıp 768 boyutta tutma, eleman eleman toplama, ortalama alma.
  - Ortak gözlemler: sinirsel dil modelleri çoğu zaman TF ve TF-IDF'ten iyidir, ama veri, ön işleme ve sınıflandırıcı seçimine göre bu tersine dönebilir. Google News ile eğitilmiş hazır word2vec, haber veri kümesinde BERT ve GPT-2'yi geçmiştir (alana yakınlık). 2-6 karakter n-gramları çok fazla özellik ürettiği için birkaç sunumda örnek sayısı azaltılmak zorunda kalınmıştır. İstatistiksel yöntemler deterministik olduğundan tekrarlar arasında standart sapmaları sıfıra yakındır; sinirsel modeller başlangıç değerlerine göre değişir.

## Hocanın Özellikle Vurguladığı Kısımlar

- BERT gibi modellere ön işlenmiş metin verilmez
  - BERT'in kendi tokenizer'ı vardır; stop word temizliği, sayı ve noktalama silme, lemmatizasyon gibi işlemler BERT'e vermeden önce yapılmamalıdır. Bu işlemler bağlamı bozar ve BERT'in başarısını düşürür. Hoca bu hatayı yapan sunumlarda düşük BERT sonuçlarının sebebinin bu olduğunu söyledi.
- Karşılaştırma adil olmalı
  - FastText'i kendi sınıflandırıcısıyla, diğer temsilleri Random Forest ile sınıflandırmak temsil açısından karşılaştırılabilir sonuç vermez. FastText vektörleri çekilip aynı sınıflandırıcıya verilmelidir; aksi halde FastText karşılaştırmanın dışında tutulmalıdır.
- Birleştirilen temsiller birbirini tamamlamalı
  - TF ile TF-IDF gibi birbirine çok benzeyen temsilleri birleştirmek pek bir şey katmaz. Başarıyı yukarı çekmek için en iyi temsil (örneğin FastText) BERT gibi tamamlayıcı bir temsille birleştirilmelidir.
- Dengesiz veri kümelerinde doğruluk yerine F1
  - Başarılar %96-98 bandında yığıldığında ve sınıflar dengesizken doğruluk (accuracy) farkları göstermez; F1 skoru daha dengeli bir ölçüdür.
- Aktif örnekleme günümüzdeki birçok problem için önemlidir
  - Model, eğitim kümesinin oluşturulmasına doğrudan müdahale eder.
- Öğrenmenin transferi için iki koşul
  - Yeni problem için yeterli veri olmaması ve iki problemin ilgili olması.

## Kısa Tekrar Notları

- Transfer öğrenme: önceden eğitilmiş modelden başla, küçük veriyle ince ayar yap. İnce ayar da eğitimdir; farkı başlangıç noktasıdır.
- CNN'de ilk katmanlar genel (yön, gradyan), son katmanlar sınıfa özgüdür.
- Çok görevli eğitim: ortak kodlayıcı, göreve özgü çözücüler, birleşik kayıp. NLP Decathlon: her görevi soru-bağlam-cevap biçimine çevirme.
- İlgisiz 5 veri kümesini tek ağda eğitmek mümkündür; veri kümesi kimliği girdiye eklenmelidir. Sonuçlar veri kümesine göre iyileşir ya da kötüleşir.
- Multimodal: girdi farklı kiplerde; çok görevli: birden fazla görev ve çıktı.
- Hiperparametre arama: ızgara, rastgele, Bayesian. Bayesian, önceki sonuçlara bakarak sıradaki denemeyi seçer.
- Aktif öğrenme etiket ister; aktif örnekleme girdi ve çıkışı birlikte ister. Yeni örnek, model varyansının yüksek olduğu bölgeden istenir.
- Sunumlardan: BERT'e ön işlenmiş metin verme; karşılaştırmada aynı sınıflandırıcıyı kullan; tamamlayıcı temsilleri birleştir; dengesiz veride F1 kullan.

## Detaylı Açıklamalar

- Öğrenmenin transferinde önceden eğitilmiş ve ince ayar ayrımı
  - Büyük bir model, örneğin bir milyon veriyle on günde eğitilir; ince ayar ise belki beş yüz veriyle on dakika sürer. Bu yüzden ikincisine "eğitim" değil "ince ayar" denir; ama ikisi de parametre optimizasyonudur. Önceden eğitimde model genelde rastgele bir başlangıçtan eğitilir; ince ayarda başlangıç değerleri büyük veride optimize edilmiş parametrelerdir. Az veriyle sıfırdan eğitilen model başarılı olamazken büyük veriyle eğitilmiş modelden başlanınca daha başarılı sonuç alınabilir.
- Çok görevli eğitimin mantığı
  - Standart yaklaşımda her görev kendi girdi-çıktı çiftleriyle ayrı eğitilir. Çok görevli eğitimde aynı girdiye karşı birden fazla çıktı vardır ve hepsi birlikte eğitilir. Görüntü işlemede çıktıların hepsi aynı tiptendir (görüntü); NLP'de görevlerin girdi ve çıktı yapıları farklı olduğu için (çeviride cümle-cümle, soru cevaplamada paragraf-soru-cevap üçlüsü, duygu analizinde metin-sınıf) NLP Decathlon bunları ortak bir biçime getirir. Böylece özetlemede öğrenilen bir şey gerektirme görevinde de işe yarayabilir.
- İlgisiz veri kümeleri deneyinin sayıları (ekrandan, 00:30:00)
  - İlk denemede test başarıları ayrı eğitimde 0.9067, 0.5017, 0.6923, 0.9771, 0.7554; birlikte eğitimde 0.8667, 0.4785, 0.7343, 0.9656, 0.7935'tir. Birinci veri kümesinde test başarısı yaklaşık 4 puan düşmüş, üçüncü ve beşinci veri kümelerinde artmıştır. Üç denemenin hepsinde üçüncü veri kümesinin test başarısı birlikte eğitimde yaklaşık 3.5-4 puan yükselmiştir (0.6923 → 0.7343, 0.7063 → 0.7413, 0.6783 → 0.7203).
- Bayesian optimizasyonun sezgisi
  - Elimizde yalnız denenen noktalar ve onların başarıları vardır; aralarındaki eğri bilinmez. Ardışık iki nokta arasında başarı düşmüşse ve aralık genişse, arada önce yükselip sonra düşen bir tepe olma olasılığı daha yüksektir. Yöntem bu aralıktan yeni bir deneme yapar, sonuca göre yeniden tahmin eder. Izgara ve rastgele aramadan temel farkı, bir sonraki denemenin yerini eldeki sonuçlara bakarak seçmesidir.
- Aktif öğrenme, yarı eğiticili öğrenme ve aktif örnekleme
  - Aktif öğrenmede örnekler bellidir, model "şu örneğin etiketini ver" der. Yarı eğiticili öğrenmede etiketi bilinmeyen örnekler olduğu gibi kullanılır. Aktif örneklemede model "şu bölgeden yeni bir örnek bul, etiketle, ver" der. Bir kelimeyi içeren eğitim örneklerinin yarısı pozitif, yarısı negatifse o kelimenin etkisini anlamak için o kelimeyi içeren yeni örneklere ihtiyaç vardır. Örneğin az olduğu bölgede tahminlerin varyansı yüksektir; yeni örnek oradan istenir.
- Ödev sunumlarından öne çıkan teknik sonuçlar
  - Dengesiz bir e-posta spam veri kümesinde (ekrandan, 02:00:00) 5 katlı çapraz geçerlemede GPT-2 %98.62, BERT %96.98, word2vec %96.91, birlikte geçme matrisi %96.14; BERT+word2vec %97.51, GPT-2+word2vec %98.58, BERT+GPT-2 %98.53 vermiştir. TF %91.00 ve TF-IDF %92.00 sonuçları yalnız 200 örnekle alınmıştır. Sunan öğrenci, sonuçların yüksek bantta yığıldığı bu veri kümesinde karşılaştırmanın güvenilir olmadığını, dengeli ve başarıların yığılmadığı veri kümelerinde farkların daha net görüldüğünü söyledi.
  - 26 sınıflı bir film türü veri kümesinde (ekrandan, 01:30:00) FastText 68, BERT 63, LDA 61, LSA 59, TF-IDF 55, TF 53 ortalama doğruluk vermiş; LSA-LDA 60, LDA-TF/IDF 58, LSA-TF/IDF 57 ile sinirsel olmayan yöntemleri birleştirmek sinirsel modellere yetişememiştir. Çok sayıda sınıf ve dengesiz dağılım başarıyı düşürmüştür.
  - Ortalama alma: 100 boyutlu GloVe ve word2vec vektörlerini uç uca eklemek 200 boyut verir; eleman eleman toplamak ya da ortalamak 100 boyutta kalır. Bir sunumda en kararlı sonuç ortalamada alınmıştır. FastText ile BERT vektörlerini toplamak kötü sonuç vermiş; sunan öğrenci toplamadan önce vektörleri normalize etmesi gerektiğini düşündü.
  - BERT üzerine çift yönlü LSTM eklemek, özellikle varlık ismi tanıma gibi kelime (token) düzeyindeki sınıflandırmada tam bağlantılı sınıflandırıcıya göre belirgin iyileşme sağlamıştır. Katman dondurma (layer freezing) (ekrandan, 02:20:00): geri yayılımda temel modelin güncellenmemesi eğitimi çok hızlandırır; yalnız eğitilen katmanları (LSTM için yaklaşık 8 MB, tam bağlantılı sınıflandırıcı için KB düzeyinde) kaydetmek yeter; dezavantajı daha düşük doğruluktur. RoBERTa, BERT'ten farklı olarak token type id parametresi almaz.
  - LDA konu sınıflandırmada iyi çalışırken duygu analizi gibi konu dışı görevlerde LSA kadar iyi olmamıştır. 4 sınıflı dengeli bir haber veri kümesinde hiç öğrenme yapılmasa (Zero Rule) doğruluk %25'tir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
