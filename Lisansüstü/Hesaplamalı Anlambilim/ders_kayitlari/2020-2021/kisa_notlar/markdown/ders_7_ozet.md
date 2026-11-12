# Ders 7 Çalışma Özeti

## Genel Konular

- Önceki dersin tekrarı: aktif öğrenme, yarı eğiticili öğrenme, öğrenmenin transferi
  - Aktif öğrenmede örnekler elde vardır, pahalı olan etiketlerdir. Algoritma etiketini istediği örnekleri seçer; amaç etiketleme maliyetini düşürmektir.
  - Yarı eğiticili öğrenmede etiketli verilerle etiketsizlerin etiketleri tahmin edilir ve tahmini etiketler de eğitime katılır (ekrandan, 00:10:00). Tek seferde (batch) tahmin, iki etiketli noktanın ortasından düz bir ayırıcı çizer; iteratif tahminde önce etiketli noktalara en yakın etiketsizler etiketlenir, sonra onlara yakın olanlar. Bütün etiketsiz verileri etiketlemek şart değildir; bazıları modeli bozabilir.
  - Önceden eğitilmiş (pretrained) modellerde transferi kolaylaştırmak için önceden eğitim mümkün olduğunca genel veriyle yapılır: metin modelleri (BERT gibi) her konudan metinle, görüntü modelleri her türlü nesneyi içeren resimlerle eğitilir.
  - Önceden eğitimde gerçekte var olmayan, veriden kurulan yapay görevler kullanılır: metinde bir kelimeyi kapatıp tahmin etmek, görüntüde iki parçanın aynı resimden olup olmadığını bulmak (karşıtlıklı, contrastive önceden eğitim). <!-- BELİRSİZ: altyazıda "Poseidon tasklar"; büyük olasılıkla "pretext task" ya da "pseudo task" -->
- Çok görevli eğitim (Multi-task Learning)
  - Aynı anda birden fazla görevi tek bir sistemle öğrenmek (ör. hem satranç hem dama oynayan tek sistem). Transfer öğrenmede kaynak görevden hedef göreve tek yönlü aktarım vardır; çok görevli öğrenmede görevler birlikte eğitilip birbirine fayda sağlar.
  - Görüntü örneği (ekrandan, 00:16:30): tek bir Encoder'ın ardından Semantic Decoder (anlamsal bölütleme), Instance Decoder (nesne örneklerini ayırma) ve Depth Decoder (derinlik haritası) gelir; her birinin görev belirsizliği (task uncertainty) toplanarak Multi-Task Loss oluşur. Derinlik bilgisi bölütlemeye yardım ettiği için bu görevlerin birlikte öğrenilmesi anlamlıdır.
  - NLP Decathlon (ekrandan, 00:20:00): soru cevaplama, çeviri, özetleme, doğal dil çıkarımı (entailment), duygu analizi, SQL'e çeviri vb. görevlerin hepsi "soru, bağlam, cevap" biçimine çevrilmiştir. Örn. duygu analizi: soru "Is this sentence positive or negative?", cevap "positive". Aynı biçim sayesinde bütün görevler tek mimariyle birlikte eğitilebilir; soru cevaplamanın diğer görevlerle birlikte öğrenildiğinde daha iyi sonuç verdiği raporlanmıştır.
  - Hocanın `multi_task_learning.m` deneyi (ekrandan, 00:22:40): iki boyutlu, iki sınıflı, birbiriyle ilgisiz 5 veri kümesi; 10 gizli nöronlu tek bir YSA, eşit eğitim süresi, 3 deneme. Çok görevli eğitimde girişe X1, X2'nin yanında görev (veri kümesi) kimliği de verilir.
  - Test doğrulukları (ekrandan, 00:22:40):

    | Deneme | Tür | VK1 | VK2 | VK3 | VK4 | VK5 |
    |---|---|---|---|---|---|---|
    | 1 | single_acc | 0.9067 | 0.5017 | 0.6923 | 0.9771 | 0.7554 |
    | 1 | multi_acc | 0.8667 | 0.4785 | 0.7343 | 0.9656 | 0.7935 |
    | 2 | single_acc | 0.9467 | 0.5050 | 0.7063 | 0.9656 | 0.7228 |
    | 2 | multi_acc | 0.7200 | 0.4983 | 0.7413 | 0.9656 | 0.7446 |
    | 3 | single_acc | 0.9200 | 0.4521 | 0.6783 | 0.9656 | 0.7772 |
    | 3 | multi_acc | 0.9600 | 0.4884 | 0.7203 | 0.9570 | 0.7772 |

  - Sonuç: tek tek ve birlikte eğitim birbirinden çok farklı değil; bazen biri, bazen öteki iyi. Ortalamalar (python ile hesaplandı): deneme 1'de 0.767 / 0.768, deneme 2'de 0.769 / 0.734, deneme 3'te 0.759 / 0.781 (single / multi). İlgisiz görevler bile tek ağda öğrenilebiliyor. Açık sorular: genel bir şey söylemek için daha çok deneme gerekir; bir ağ kaç problemi kapsayabilir (5 yerine 50)?
- Hiperparametre optimizasyonu (ekrandan, 00:30:00)
  - Hiperparametre: algoritmanın kendisinin öğrenemediği, dışarıdan verilen parametre (k-NN'de k, öğrenme katsayısı, optimizasyon yöntemi vb.).
  - Çok hiperparametre algoritmayı esnek yapar, ama denenecek olasılık sayısını büyütür. 5 hiperparametre, her biri 10 değer: $10^5 = 100\,000$ deneme; her eğitim bir saat sürerse bu çok uzun zaman demektir.
  - Hiperparametreler ayrık (k-NN'de k = 1, 2, 3, ...) ya da sürekli (öğrenme katsayısı 0.01 gibi) olabilir. Sürekli olanlar için de sonlu sayıda değer seçmek gerekir.
  - Izgara (grid) arama: her boyutta belirli değerler, sistematik tarama. Rastgele arama: ızgara üzerinde rastgele dolaşma (random walk), toplam deneme sayısı sabit.
  - Bayesian optimizasyon: eldeki deneme sonuçlarına bir eğri uydurur (interpolasyon) ve en fazla iyileşmeyi sağlayacağı tahmin edilen değeri sonraki deneme noktası seçer. Slayttaki grafikte x ekseni hiperparametre değeri, y ekseni modelin başarısıdır.
- Aktif örnekleme (Active Sampling) (ekrandan, 00:40:00)
  - Aktif öğrenmede örneklerin yalnız etiketleri istenir. Aktif örneklemede ise kullanıcıdan girdi uzayının belli bölgelerinden yeni örneklerin kendisi (girdi ve çıktısıyla) istenir. Bayesian optimizasyondan esinlenmiştir.
  - `active_sampling.m` (ekrandan, 00:40:00): bir regresyon probleminde farklı eğitim kümeleriyle eğitilmiş modellerin tahminleri x ≈ 0.2 civarında çok farklıdır. Slayt: "Model varyansının en yüksek olduğu yerler = tahminlere en az güvenebileceğimiz yerler. Modelin bir noktadaki varyansı, farklı eğitim kümeleri için o noktanın tahminlerinin std'si. Buralardan yeni örnek istemeliyiz." Varyansın yüksek olduğu bölge, eğitim verisinin az olduğu bölgedir.
  - Metin örneği: duygu analizinde hem pozitif hem negatif örneklerde az sayıda geçen bir kelime güvenilmezdir; "içinde şu kelime geçen tweetleri topla ve etiketle" diye yeni örnek istenebilir.
  - Deney tasarımına benzer; bilimsel araştırmalara yardımcı (yazılımsal) robotlarda kullanılabilir.
- İnsan-makine işbirliği (Human in the Loop / Weak Supervision) (ekrandan, 00:41:40)
  - İnsanlar yavaş ama doğrudur: veri etiketleyebilir, tahminleri düzeltebilir, tahminler arasından seçim yapabilir (100 sınıftan en olası 5'inden doğru olanı seçmek), örneklerin ortak bir özelliği için kural verebilir ("içinde şu ifade geçenler negatiftir", "kedilerin kuyruğu vardır"). Makineler hızlıdır, çok sayıda bilgiyle başa çıkar, ama daha az doğrudur.
  - Video etiketleme: 30 fps'lik bir kayıtta 30 saniyelik bir araç hareketi 900 kare demektir. İnsan birkaç anahtar karede aracı işaretler, aradaki kareleri makine öğrenmesiyle eğitilmiş sistem doldurur.
  - Çeviride bugün otomatik çeviri + insan düzeltmesi yaygındır.
  - Zayıf denetim (weak supervision) (ekrandan, 00:50:00): her örneğe tek tek etiket vermek yerine kural yazılır. Kural1: metnin içinde «çekmiyor» varsa negatiftir; Kural2: "harikasın" varsa pozitiftir gibi. Tek bir kural çok sayıda örneği birden etiketler.
  - Sorun: kurallar birbiriyle çelişebilir ve örtüşebilir. Snorkel benzeri yaklaşımda örnekler × kurallar tablosu kurulur (ekrandan, 00:53:30); her hücre +, − ya da boş (kural o örnek için bir şey söylemiyor, çekimser) olabilir. Son satırda bir birleştirme kuralıyla (ör. çoğunluk oyu: 5 kural "+", 3 kural "−" diyorsa "+") örneğin etiketi belirlenir. Çelişkili örnekler eğitime alınmayabilir.
- Az sayıda örnekle eğitim (ekrandan, 01:10:00)
  - Keras'ın geliştiricisi François Chollet'nin sözü (slayt): eğitim verisi problem uzayını yoğun kaplıyorsa her problem örüntü tanıma problemi gibi ele alınabilir; ilginç olan, veri seyrek olduğunda ekstrapolasyon yapmaktır ve bunun için zekâ gerekir.
  - One-shot (tek çekimle) öğrenme: eğitim kümesinde her sınıf için tek ya da çok az örnek vardır (ör. tek bir zürafa resmi).
  - Zero-shot (sıfır çekimle) öğrenme (ekrandan, 01:11:40): test örneklerini eğitim kümesinde hiç örneği bulunmayan sınıflara atamak; eğitim ve test sınıfları ayrıktır. Çok kipli (multimodal) yaklaşımlar kullanılır. Eğitimde her örneğin tanımları (attribute), sınıfı ve resmi vardır; çıkarımda (inference) tanım-yeni sınıflar matrisi ve test örneğinin tanımları vardır.
  - Google'ın zero-shot makine çevirisi (ekrandan, 01:14:00): her dil ikilisi için ayrı model (100 dilden 100 dile) yerine girişler ortak bir katmana, çıkışlar ortak bir katmandan bağlanır. A→B ve B→C paralel derlemi varken A→C olmasa da çeviri yapılabilir. Aynı anlamlı farklı dillerdeki cümleler ortak uzayda yakın bölgelere düşer. Aralarında etkileşim olmayan diller arasında paralel derlem oluşmadığı için bu önemlidir.
- Veri zenginleştirme (Data Augmentation)
  - Amaç elde olan etiketli veriden "bedavaya" yeni etiketli veri üretmektir.
  - Görüntüler (ekrandan, 01:16:15): MNIST örneklerinde A satırı orijinal, B yatay eksende eğme (horizontal shearing), C 35 derece döndürme, D ve E farklı derecelerde elastik deformasyon (Simard ve ark., 2003). Ayrıca rastgele kırpma, ayna yansıması, renk bilgisinde değişim (ekrandan, 01:20:00). Krizhevsky ve ark. 2012 ImageNet makalesinde resimden 224×224'lük rastgele kırpmalar alınmıştır.
  - Kırpma kutusu küçüldükçe sınıfa ait olmayan parça üretme şansı artar; kırpma yeterince büyük olmalıdır. Tek nesneli resimlerde (kedi, kelebek) iyi çalışır; çok nesneli resimlerde (çocuk parkı) kırpma başka bir nesneye denk gelebilir.
  - ImageNet, WordNet'teki kavramların resimlerle zenginleştirilmesi için başlatılmış bir çalışmadır.
  - Üretici çekişmeli ağlar (GAN): sınıflandırıcı ve regresörler karar sınırı ya da yüzey öğrenir; üretici modeller ise verilen kümeden yeni örnek üretmeyi öğrenir. Üretici ağ rastgele gürültüden eğitim kümesine benzer örnek üretmeye, ayırt edici ağ gerçek ile yapay örnekleri ayırmaya çalışır. Ayırt edici çok başarılıysa üretici iyi örnek üretememiştir; ayırt edici ayıramıyorsa üretici başarılıdır. GAN'lar görüntüde çok gerçekçi sonuç verir; metinde henüz aynı başarı yoktur. Veri zenginleştirme için GAN kullanmak pahalı olabilir.
  - Metinler (ekrandan, 01:30:00): eş anlamlı kelime ve deyişler ("Bizim oğlan komşu kızına abayı yakmış" → "Bizim oğlan komşu kızına âşık olmuş"); bu bir yeniden ifade etme (paraphrasing) işidir ve kolay değildir. Çeviri (geri çeviri, back-translation): orijinal örnek → başka bir dildeki karşılığı → yeni örnek ("Sinema salonunda kırmızı ayakkabıları olan bir kadın gördüm" → "Sinema salonunda kırmızı ayakkabılı bir kadın gördüm"). A→B→A yerine A→B→C→D→A gibi daha uzun zincirde sonuç orijinale daha az benzer (kulaktan kulağa oyunu gibi).
  - Genel amaçlı (UCI vb.) veriler (ekrandan, 01:40:00): görüntü ve metinde etiketi değiştirmeyen dönüşümler kullanıldı; genel veride bunları tanımlamak zordur. Seçenekler: her sınıf için bir olasılık yoğunluk fonksiyonu (pdf) tahmin edip ondan yeni örnek üretmek (çok boyutta pdf tahmini zor) ya da SMOTE.
  - SMOTE (ekrandan, 01:40:00 ve 01:40:50): dengesiz veri kümelerinde az örnekli sınıf (minority) için önerildi. Az örnekli sınıftan bir örneğe en yakın k komşusunu bul, bunlardan onunla aynı sınıfta olan birini seç, ikisini birleştiren çizgi üzerinde yeni bir örnek üret. Her veri kümesine uygulanabilir; resimlerde de (100×100 resim 10 000 boyutlu uzayda bir noktadır) kullanılabilir.
  - SMOTE karar sınırına yakın yapay örnek ürettiğinde sınıf geçişleri sertleşebilir; SMOTE-IPF önce SMOTE ile örnek üretir, sonra veriyi k parçaya bölüp her parçayla model eğitir, tahminleri tutarsız olan örnekleri eler (ekrandan, 01:40:50).
- ML algoritmalarını kandırmak (Adversarial Attacks) (ekrandan, 01:45:20)
  - Kararlar makinelere bırakıldığı anda onları kandırma çalışmaları da başlar (spam filtreleri gibi).
  - Inception v3'e göre %97 olasılıkla "papağan" olan resme özel hazırlanmış bir gürültü eklenince aynı mimari %99 olasılıkla "kitaplık" der. İnsan için resim hâlâ papağandır. Derin modeller çok küçük, minimal desenlere dayanarak karar verir; saldırı bu desenleri hedef sınıfa doğru çeker.
  - Yalnız derin öğrenme değil bütün sistemler tehdit altındadır. Kaggle yarışması (NIPS 2017, 3 görev): hedef belli atak ("şu resme şunu dedirt"), hedef belirsiz atak ("kandır"), savunma (ekrandan, 01:50:00). Tek bir piksel değişimiyle bile kandırmak mümkündür.
  - Önemi: kendi kendine giden araçlarda trafik levhalarına yapıştırılan desenler, yüz tanıma sistemlerini atlatmak için özel desenli tişörtler.
- Planlı öğrenme (Curriculum Learning) (ekrandan, 01:55:20)
  - Örneklerin öğreniciye veriliş sırası önemli midir? İnsanlar bir müfredatla (çizgiden harfe, heceye, kelimeye; ilköğretim, lise, üniversite) öğrenir. Kolaydan zora sırası; ama "kime göre kolay" sorusu vardır.
  - Bütün verilerin müfredata katılması şart değildir; aktif öğrenme de müfredatı kısıtlamak gibi düşünülebilir.
  - Kolaylık ölçütü: önceden belirlenip sabit kalabilir (insan belirler; bir algoritmanın sınıflara atama olasılıkları; minimum yayılan ağaç gibi geometrik yaklaşımlar) ya da öğrenme sırasında değişebilir (self-paced learning).
  - İnsan belirlemesine örnek: şekil sınıflandırmada ilk satır kolay (eşkenar üçgen, daire, kare; ön plan ile arka plan rengi çok farklı), ikinci satır zor (çeşitkenar üçgen, elips, dikdörtgen). Metinde çok geçen kelimeler ya da kısa cümleler kolay sayılabilir.
  - Zorluğu ensemble belirleyebilir: 10 modelin hepsi aynı şeyi diyorsa örnek kolay, 5'e 5 bölünüyorsa zordur. Grafikte (ekrandan, 02:00:00) mavi klasik (rastgele sıra), kırmızı curriculum (önce kolay), pembe anti-curriculum (önce zor); bazen curriculum, bazen anti-curriculum daha iyi. Hocanın aktardığına göre UCI veri kümelerinde curriculum genelde daha başarılı.
- Hayat boyu öğrenme (Lifelong Learning) (ekrandan, 02:10:00)
  - Öğrenme süreci bitmez; tüm eğitim verisi baştan elde değildir, zamanla erişilir. Dil yaşadığı için duygu analizi ya da çeviri modeli bir kez eğitilip yıllarca kullanılamaz; yeni jargonlar, kampanya sloganları çıkar.
  - Test örnekleri yalnız eğitimdeki sınıflardan gelmez (open world): gezen bir robot hiç öğretilmemiş sınıftan nesnelerle karşılaşır.
  - Önceden öğrenilenler neyin ve nasıl öğrenileceğini etkiler. Akademide tek veri kümesiyle çalışılıp bitirilir; endüstride ürünün yaşam döngüsü boyunca bakım ve yeniden eğitim gerekir.
- Ders sonu soru: çok sınıflı ve çok dengesiz metin verisinde aşırı örnekleme (oversampling) işe yarar mı?
  - Hoca: geri çeviri gibi zenginleştirme yöntemleri ya da eşit sayıda sınıf örneğiyle eğitime başlayıp süreci sonra tamamlamak denenebilir; hangisinin daha iyi olacağı veri kümesine bağlıdır, deneyip görmek gerekir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Etiketleme maliyeti
  - Örnekleri (noktaları) elde etmek genelde kolay, etiketlerini elde etmek pahalıdır. Aktif öğrenme, yarı eğiticili öğrenme ve zayıf denetim bu maliyeti düşürmeye çalışır.
- Çok görevli eğitimde görev ilgisi
  - Birbirine fayda sağlayabilecek görevlerin birlikte öğrenilmesi anlamlıdır. Hocanın deneyinde ilgisiz görevler bile tek ağda öğrenilebildi; ama "birlikte öğrenmek her zaman daha iyi" ya da "daha kötü" denemez.
- Aktif öğrenme ile aktif örnekleme farkı
  - Aktif öğrenme etiket ister; aktif örnekleme hangi girdi bölgesinden örnek (girdi ve çıktı) isteneceğini de belirler. Model varyansının yüksek olduğu yer, verinin az olduğu yerdir.
- Zayıf denetimde kural tasarımı
  - Kural, uygulandığında ne olmadığını da tanımlamalıdır: "çekmiyor" yoksa pozitif mi, negatif mi, çekimser mi? Bu tamamen tasarımcının kararıdır; genelde çekimser kalan bir tarafı olur.
- Veri zenginleştirme "bedava etiketli veri"dir
  - Bir etiketli örnekten çok sayıda etiketli örnek üretilir; ama etiketi değiştirmeyen dönüşüm seçilmelidir (kırpma çok küçükse kedi resminden kedi olmayan parça çıkar).
- Derin modeller insan gibi görmez
  - Gaga, renk gibi parçalara değil çok küçük desenlere bakar; bu yüzden insanın fark etmediği gürültüyle kandırılabilir. Kritik kararlar makinelere bırakılırken bu düşünülmelidir.
- Dil modelleri zamana bağlıdır
  - Basit sanılan duygu analizi bile zamana bağlıdır; eğitim kümesinin toplandığı zamandan uzaklaştıkça başarı düşer.

## Kısa Tekrar Notları

- Pretrained modellerde genellik için önceden eğitim her konudan metin / her tür nesne içeren resimle yapılır.
- Çok görevli eğitim: aynı anda birden çok görev; transferde tek yönlü aktarım, çok görevlide karşılıklı fayda.
- NLP Decathlon: bütün NLP görevleri soru-bağlam-cevap biçimine çevrilip tek mimariyle eğitilir.
- Çok görevli eğitimde girişe görev kimliği eklenir.
- Hiperparametre: algoritmanın öğrenemediği, dışarıdan verilen parametre. 5 hiperparametre × 10 değer = $10^5$ deneme.
- Grid arama sistematik, rastgele arama rastgele dolaşma; Bayesian optimizasyon en fazla iyileşme beklenen noktayı tahmin eder.
- Aktif örnekleme: model varyansı en yüksek bölgeden yeni örnek iste.
- Human in the loop: insan yavaş ama doğru, makine hızlı ama az doğru. Video etiketlemede insan anahtar kareleri, makine aradaki kareleri doldurur.
- Weak supervision: tek tek etiket yerine kural; kurallar çelişebilir, çoğunluk oyu gibi birleştirme kuralı gerekir (Snorkel).
- One-shot: sınıf başına tek/az örnek. Zero-shot: test sınıfları eğitimde hiç yok; tanımlar (attribute) ve çok kipli yaklaşımlar.
- Google zero-shot çeviri: ortak giriş/çıkış katmanı; A→B ve B→C ile A→C.
- Görüntü zenginleştirme: eğme, döndürme, elastik deformasyon, rastgele kırpma, ayna, renk değişimi.
- Metin zenginleştirme: eş anlamlı ifadeler (paraphrasing), geri çeviri; zincir uzadıkça benzerlik azalır.
- Genel veri: sınıf başına pdf tahmini ya da SMOTE (komşuyla birleştiren çizgi üzerinde yeni örnek); SMOTE-IPF gürültülü örnekleri eler.
- GAN: üretici rastgele gürültüden örnek üretir, ayırt edici gerçek/yapay ayırır; görüntüde başarılı, metinde henüz değil.
- Adversarial: Inception v3 papağan %97 → gürültüyle kitaplık %99; tek piksel değişimi bile yetebilir; hedef belli / hedef belirsiz atak, savunma.
- Curriculum: kolaydan zora sıra; kolaylığı insan, algoritma olasılıkları, geometrik yöntemler ya da ensemble belirler; self-paced learning.
- Lifelong learning: öğrenme bitmez, veri zamanla gelir, open world, endüstride daha yaygın.

## Detaylı Açıklamalar

- Yarı eğiticili öğrenmede iteratif yaklaşımın gerekçesi
  - Slayttaki şekilde yalnız iki etiketli nokta (biri beyaz, biri siyah) ve çok sayıda gri (etiketsiz) nokta vardır. Yalnız etiketli verilerle model kurulursa ayırıcı iki noktanın ortasından geçen düz bir çizgi olur; tek adımda bu modelle bütün etiketsizler tahmin edilirse çizginin solu beyaz, sağı siyah olur ve ayırıcı değişmez. İteratif yöntemde önce etiketli noktalara en yakın etiketsiz noktalar etiketlenir, sonra yeni etiketlilere yakın olanlar; böylece veri yığınlarını izleyen kıvrımlı bir ayırıcı elde edilebilir. Ancak bu tahmini etiketler gerçek etiket değildir; iteratif yöntemin grafiklerdeki dalgalanması bundan kaynaklanır. Bazı veri kümelerinde (autos) az sayıda etiketsizi katmak iyi, bazılarında (audiology) hepsini katmak iyi görünmüştür.
- Önceden eğitimde yapay görevler
  - Hoca, önceden eğitimde gerçekte var olmayan, araştırmacının kurduğu görevlerden söz etti. Bir kelimeyi kapatıp tahmin etmek gerçek bir uygulama değildir, ama modeli eğitmeye yarar. Görüntüde iki parçanın aynı resimden gelip gelmediğini bulmak da böyle bir görevdir; bu tür görevler karşıtlıklı (contrastive) modellerin önceden eğitiminde kullanılır. Böyle bir görevin çözümü başka görevlerin çözümüne de yardımcı olur.
- Çok görevli eğitim deneyinin okunması
  - Tablodaki single_acc her veri kümesi kendi ağıyla ayrı eğitildiğinde, multi_acc beş veri kümesi tek ağda birlikte eğitildiğinde elde edilen test doğruluğudur. Eğitim doğrulukları (single_tr_acc, multi_tr_acc) da slaytta vardır; ilk denemede tek eğitimde birinci veri kümesinin eğitim doğruluğu 1.0000'dır. Görev kimliği verilmeden ağ hangi veri kümesindeki noktaya bakıldığını ayırt edemez, çünkü girdiler aynı iki boyutlu uzaydadır. Üç denemede tek tek ve birlikte eğitimin ortalama test doğrulukları birbirine yakındır; veri kümesi bazında da kazanan değişmektedir. <!-- BELİRSİZ: hocanın tabloyu yorumlarken söylediği sayılar (00:23:42-00:24:09) altyazıda bozuk; değerler slayttan alındı -->
- Bayesian optimizasyon sezgisi
  - Hoca bir hiperparametrenin 1, 2 ve 4 değerlerinde deneme yapıldığını düşündürdü: 1'den 2'ye başarı artmış, 4'te düşmüştür. Bu durumda 2 ile 4 arasında daha yüksek bir yer olabilir. 3 de denenip hâlâ artış görülürse (1→2→3 artıyor) ve artışın biraz daha sürüp sonra düşeceğine inanılırsa sonraki deneme 3.5 civarında yapılabilir. Kesinlik değil olasılık söz konusudur; aralarda çok dar bir tepe olabilir, ama bu tür dar tepeler pek istenen şeyler değildir. Bayesian optimizasyon bu akıl yürütmeyi verilere interpolasyon uygulayıp interpolasyonun maksimumunu sonraki nokta seçerek yapar.
- Zayıf denetimde kuralların birleştirilmesi
  - Klasik denetimli öğrenmede her örnek tek tek incelenip etiketlenir; bu yüzden çelişki oluşmaz. Kuralla etiketlemede bir metin hem pozitif hem negatif kurala uyabilir. Örnek × kural tablosunda her hücre +, − ya da boş olabilir; son satır birleştirme sonucudur. En basit birleştirme çoğunluk oyudur. Bir öğrencinin "Kural1 «çekmiyor» yoksa örnek pozitif mi olur?" sorusuna hoca, kuralın uygulanmadığında ne diyeceğinin tasarımcıya bağlı olduğunu söyledi: "varsa pozitif, yoksa negatif" de olabilir, ama genelde kural uygulanmadığında çekimser kalır.
- Zero-shot çevirinin mantığı
  - İngilizce'den Japonca'ya çeviri için birebir eşlenmiş paralel derlem gerekir. Paralel derlemler insanlar arasında ticaret, hukuk gibi bir etkileşim olduğunda oluşur; aralarında bağlantı olmayan iki dil arasında oluşmaz. Ortak giriş ve çıkış katmanlı tek model, örneğin İngilizce-Fransızca ve Fransızca-Türkçe verisiyle eğitilip İngilizce-Türkçe çeviri yapabilir. Slayttaki görselleştirmede her nokta bir cümledir; kümelerden biri büyütüldüğünde aynı anlamlı İngilizce, Korece ve Japonca cümlelerin uzayda yakın yerlerde olduğu görülür.
- GAN'da çekişme
  - Üretici ağ iyi örnek üretmeye, ayırt edici ağ ayırt etmeye çalışır; biri başarılıysa öteki doğal olarak başarısızdır. Slayttaki insan yüzü örneğinde üretilen yüzlerin yanında eğitim kümesindeki en benzer gerçek yüzler gösterilmiştir; üretilen yüzler bu yüzlerin birleştirilmesiyle elde edilmez. Yine de üretilen resimler dikkatli bakıldığında ayırt edilebilir: arka plan genelde bulanık (blurry), ön plan daha ayrıntılıdır.
- SMOTE ile genel veride zenginleştirme
  - Slayttaki şekilde (ekrandan, 01:40:50) taralı kareler çoğunluk sınıfı, siyah noktalar azınlık sınıfı, kırmızı noktalar sentetik örneklerdir. Bir azınlık örneği (x1) ile komşuları (x2, x3, x4, x5, x6) arasındaki çizgiler üzerinde a, b, c, d, e gibi yeni örnekler üretilir. İki köpek resmi 10 000 boyutlu uzayda iki nokta olduğu için aralarındaki çizgiden de yeni resimler üretilebilir.
- Planlı öğrenmede "kime göre kolay"
  - Üniversitedeki biri için ilköğretim müfredatı kolaydır, ama ilköğretim öğrencisi için kendi müfredatı zordur. Yine de genel bir bakışla bir sıralama yapılabilir. Makinede kolaylık, aktif öğrenmedeki belirsizlik ölçüsüne benzer biçimde ölçülebilir: sınıf olasılıkları birbirine yakın (ör. %33, %33, %33) olan örnek zordur. Minimum yayılan ağaçta çok bağlantısı olan örnek kolay, uzakta ve benzeri az olan örnek zor sayılabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
