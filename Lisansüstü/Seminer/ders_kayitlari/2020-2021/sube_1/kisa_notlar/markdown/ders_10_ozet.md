# Ders 10 Çalışma Özeti

## Genel Konular

- Seminer sunumları ve literatür taramasının değerlendirilmesi
  - Bu derste beş seminer sunumu yapıldı. Her sunum bir konudaki literatürü derledi: önce motivasyon ve temel kavramlar, sonra seçilmiş makalelerin yöntemleri ve sonuçları, en sonda genel değerlendirme ve yeni çalışma önerileri.
  - Hoca sunumlardan sonra kaynakların güncelliğine ve atıf sayılarına baktı. Hem çok atıf alan temel makalelerin hem de son yıllardaki çalışmaların listede bulunmasını olumlu buldu.
- Çok kipli (multimodal) derin öğrenme ve duygu analizi
  - Çok kipli veri, aynı olayın birden fazla kipten (metin, ses, görüntü/video) gelen temsilidir. Sosyal medyada görüntü, video ve ses verisinin artmasıyla önem kazandı (ekrandan, 00:20:00).
  - Örnek veri seti MOSI: duygu yoğunluğu $-3$ ile $+3$ arasında doğrusal bir ölçekle etiketlenmiş, 2199 veri noktası içeriyor.
  - Beş temel zorluk: gösterim (representation), çeviri (translation), hizalama (alignment), birleştirme (fusion), ortak öğrenme (co-learning) (ekrandan, 00:25:00).
  - Alt ağların çıktısını eşit önemle birleştirmek yerine her alt ağa öğrenilen bir ağırlık ($\theta$) verilmesi önerildi.
  - Kısıtlı Boltzmann Makinesi (RBM) mimarileri: standart RBM, sığ (shallow) çok kipli RBM ve derin (deep) çok kipli RBM (ekrandan, 00:30:00).
- Derin öğrenme tabanlı hibrit tavsiye sistemleri
  - Üç temel yaklaşım: içeriğe dayalı filtreleme, işbirliğine dayalı filtreleme, hibrit öneri (ekrandan, 00:40:00).
  - Geleneksel sistemlerin zorlukları: soğuk başlangıç (cold start), ölçeklenebilirlik, seyreklik (sparsity), yorumlanabilirlik, sömürü-keşif (exploitation-exploration) dengesi.
  - Derin öğrenmenin katkıları: doğrusal olmama, temsil öğrenimi ve otomatik özellik çıkarımı, dizi modelleme, esneklik. Zorlukları: kara kutu davranışı, veriye açlık, kapsamlı hiperparametre ayarı, farklı model karmaşıklıkları (ekrandan, 00:45:00).
  - Değerlendirme metrikleri: AUC, ortalama kare hatası (MSE), Recall, Hit Ratio, NDCG, RMSE.
  - İncelenen modeller: Wide & Deep (2016), CARL (2018), derin sinir ağlı verimli bir hibrit model (2019), bir iş öneri modeli ve puan, yorum ve meta veriyi birlikte kullanan derin hibrit model (2021).
- Manifold öğrenme (çok yönlü öğrenme) ve sınıflandırmada kullanımı
  - Manifold öğrenme, doğrusal olmayan yüksek boyutlu veriyi düşük boyuta indirger. Doğrusal veride PCA/MDS yeterlidir, doğrusal olmayan veride yetersiz kalır.
  - Temel algoritmalar: Isomap (jeodezik mesafe) ve LLE (yerel doğrusal yeniden kurma, 2000). Bunların üzerine Laplacian Eigenmaps (2003), Hessian Eigenmaps (2003) ve denetimli Hessian Eigenmap (2015) geliştirildi.
  - Örnek dışı (out-of-sample) problemi: yöntem bir dönüşüm fonksiyonu üretmediği için yeni test verisi gelince bütün sistemin yeniden çalıştırılması gerekir. Çözüm önerileri: Bengio vd. (2003), LPP (2004), komşuluk koruyan dönüşüm (2005), gizli değişken modeli (2008).
  - Sınıflandırmada manifold öğrenme çoğunlukla ön işleme (boyut indirgeme) adımı olarak kullanılmış: t-SNE + SVM ile ulaşım türü tespiti, hiperspektral görüntü haritalama, LLE + Random Forest ile epilepsi tespiti.
- Çok dilli (cross-lingual) kelime vektörleri
  - Amaç, bir dilde eğitilmiş bir modeli (örneğin İngilizce metin sınıflandırıcı) başka dillere, o dillerde büyük etiketli veri toplamadan aktarmaktır.
  - Tek dilli kelime gömmeleri (CBOW, Skip-gram, GloVe) yoğun vektörlerde anlamsal ilişkileri kodlar (king - man + woman ≈ queen) (ekrandan, 02:00:00).
  - Çok dilli kelime vektörleri, birden fazla dilin vektörlerini ortak bir uzaya taşır. Bu uzayda anlamca benzer kelimeler birbirine yakın olur (ekrandan, 02:05:00).
  - Veri türleri kelime, cümle ve doküman seviyesindedir. Her seviyede paralel ya da karşılaştırılabilir (comparable) veri bulunur.
  - Üç yaklaşım ailesi var: eşleme (mapping) tabanlı, sözde çok dilli derlem (pseudo-multilingual corpora) ve ortak (joint) yöntemler.
  - Değerlendirme iç (intrinsic) ve dış (extrinsic) olmak üzere ikiye ayrılır. Açık kaynak benchmark kütüphaneleri: MUSE, vecmap, xling-eval (ekrandan, 02:15:00).
- Çoklu mobil robot yol planlama ve optimizasyon algoritmaları
  - Yol planlama NP-zor bir problemdir. Dağıtım, rotalama, tedarik ve lojistik gibi alanlarda geniş uygulaması vardır.
  - Algoritmalar klasik matematiksel (deterministik) ve meta-sezgisel (stokastik) olarak ikiye ayrılır. Meta-sezgiseller evrim tabanlı, fizik tabanlı, sürü tabanlı ve davranışsal tabanlı diye dört sınıfta toplanır (ekrandan, 02:30:00).
  - Yeni çalışma alanı önerisi: kuantum robotlar (qubots). Klasik robotlardaki $O(N^2)$ karmaşıklığın Grover algoritmasıyla $O(N\sqrt{N})$'e indirildiği raporlanmış (ekrandan, 02:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Literatür taramasında kaynakların güncelliği ve atıf sayısı
  - Hoca listelenen her kaynağın yayın yılına ve atıf sayısına baktı. Eski ama çok atıf alan temel makalelerin yanında son yıllardan yayınlar da bulunmalıdır. Yeni yayınların atıf sayısının düşük olmasını doğal karşıladı.
  - Tablolarda yalnız eski yayınlar görünen bir sunumda, ikincil bir derlemedeki tabloları aktarmak yerine doğrudan makale okumaya dayalı ve güncel çalışmaları kapsayan bir literatür taramasının gerektiğini söyledi.
- Öz nitelik azaltma başarıyı neden artırabilir?
  - Manifold öğrenme ilgili ve sınıfları ayırt edici öz nitelikleri korur. İlgisiz öz nitelikler atılınca sınıflandırıcı gereksiz verilerle yanlış yönlere gitmez. Bu yüzden 14 öz nitelikten 2'ye inince başarının artması mümkündür.
  - Alternatif olarak daha karmaşık bir model (örneğin derin ağ) öz nitelik seçimini kendi içinde yapabilir. Bu iki yol birbirine alternatiftir ve tartılması gerekir.
- Çok kipli veride kiplerin katkısı
  - Grafikteki oranlar, metin, ses ve videonun bir arada olduğu bir girdide her kipin duygu tahminine etkisini gösterir. Veri miktarını göstermez.
- Sığ ve derin RBM farkı
  - Derin modelde araya bir ya da daha fazla katman eklenebilir. Sığ modelde ses ve video girdileri ortak gösterim katmanına doğrudan bağlıdır. Derin modelde her kip önce kendi katmanında ayrı öğrenilir.

## Kısa Tekrar Notları

- Çok kipli öğrenmenin beş zorluğu: gösterim, çeviri, hizalama, birleştirme, ortak öğrenme.
- Dudak okumada "elephant juice" ile "I love you" aynı dudak hareketini verir; tek kip (görüntü) yetmez.
- Standart RBM tek kipi modeller. Sığ RBM birleştirilmiş ses ve video üzerinde eğitilir ve doğrusal olmayan kipler arası korelasyonu zor öğrenir. Derin RBM kip başına önceden eğitilmiş katmanların üzerine greedy layer-wise eğitilir.
- Tavsiye sistemlerinin zorlukları: cold start, ölçeklenebilirlik, sparsity, yorumlanabilirlik, sömürü-keşif.
- Wide & Deep: geniş kısım (tek katmanlı doğrusal model, ezberleme) ve derin kısım (MLP, genelleme) ortak eğitilir. Aday kümesinde O(100) öğe çekilir, sıralanıp O(10) öğe sunulur.
- CARL, sekiz modelle karşılaştırıldığı yedi veri setinin hepsinde en düşük hatayı verdi (ekrandan, 00:55:00).
- Dikkat (attention) mekanizması hem performansı artırır hem de derin modellerin yorumlanabilirlik sorununu hafifletir.
- Isomap: k-komşuluk grafı, en kısa yollar (jeodezik mesafe tahmini), düşük boyutta gömme.
- LLE: k-komşuluk, her noktayı komşularının ağırlıklı toplamıyla yeniden kurma, aynı ağırlıklarla düşük boyutlu koordinatlar.
- Hessian Eigenmaps daha iyi sonuç verir, ancak ikinci türev hesabı nedeniyle süre ve maliyeti yüksektir.
- Out-of-sample: manifold yöntemleri açık bir dönüşüm fonksiyonu üretmez, yeni veri için yeniden hesap gerekir.
- Çok dilli kelime vektörlerinin iki faydası: kelime anlamlarını diller arasında karşılaştırma ve kaynak bakımından zengin dillerden fakir dillere bilgi aktarımı.
- Eşleme tabanlı yöntemler bir dönüşüm matrisi öğrenir. Ortak yöntemler matris yerine bir düzenlileştirme (regularization) fonksiyonu kullanır.
- Meta-sezgiseller gradyan gerektirmez, yerel optimumdan kaçabilir, aynı başlangıçla farklı (ama yakın) sonuçlar üretebilir.

## Detaylı Açıklamalar

- **Çok kipli derin öğrenme.** Gerçek dünya çok kiplidir: nesneleri görür, sesleri duyar, dokuyu hisseder, koku ve tat alırız. Bir problem birden çok kip içerdiğinde çok kipli (multimodal) olarak tanımlanır. Literatürde Yuhas ve arkadaşlarının (1989) görsel girdiden işitsel sinyali tahmin eden bir sinir ağı eğitip bunu gürültülü sesle birleştirdiği, Poria ve arkadaşlarının (2015) CNN ile çok kipli duygu analizi yaptığı aktarıldı. Tipik bir mimaride kullanıcının ürettiği metin, ses ve görüntüden öznitelikler çıkarılır ve sonuç pozitif, nötr ya da negatif olarak tahmin edilir. Yaygın yöntem, farklı girdilerden gelen yüksek seviyeli gömmeleri birleştirip softmax uygulamaktır. Ancak bu yöntem bütün alt ağlara eşit önem verir. Önerilen yaklaşımda alt ağların ağırlıklı bir kombinasyonu alınır, böylece her kip çıktıya öğrenilmiş bir katkıyla girer. RBM, gizli ve görünür değişkenler arasında simetrik bağlantıları olan, aynı türdeki değişkenler arasında bağlantı bulunmayan yönsüz bir grafik modeldir. Bu yapı, bir taraf sabitken diğerinin koşullu dağılımının kolay hesaplanmasını sağlar. Sunulan formülasyonda görünür değişkenler gerçek değerli, gizli değişkenler ikili modellenir. <!-- BELİRSİZ: RBM'nin negatif log olasılık (eşitlik 1) ve koşullu dağılım (eşitlik 2) denklemleri sözlü anıldı, ancak elde bu slaytın karesi yok; denklemler nota alınmadı. -->

- **Hibrit tavsiye sistemleri.** Tavsiye sistemleri 1990'ların ortasında bağımsız bir araştırma alanı olarak ortaya çıktı ve Netflix'in işbirlikçi filtreleme yarışmasıyla popülerleşti. Sunumda Netflix'te izlenen filmlerin %80'inin, YouTube tıklamalarının %60'ının ve Amazon satışlarının %35'inin önerilerden geldiği aktarıldı. İçeriğe dayalı filtreleme kullanıcının geçmişte sevdiklerine benzer öğeler önerir. Kullanıcının ilgisi yeni bir türe kayınca öneri yapacak veri yoktur. İşbirliğine dayalı filtreleme benzer kullanıcıların aldıklarını önerir. Hibrit yaklaşım ikisinin olumlu yanlarını birleştirir. Wide & Deep modelinde (Google, 2016) Google Play'de sorgu gelince veritabanından aday öğeler çekilir (retrieval). Model bunları sıralar (ranking) ve en iyi öğeler sunulur. Kullanıcı eylemleri loglanır ve modeli yeniden eğitmek için kullanılır (ekrandan, 00:50:00). Derin kısımda kategorik öznitelikler gömme vektörlerine dönüştürülür, sürekli özniteliklerle birleştirilip üç ReLU katmanından geçirilir. Geniş kısımda çapraz çarpım (cross-product) dönüşümleri bulunur. İkisi lojistik kayıpla ortak eğitilir. CARL modeli (Wu vd., 2018) bağlama duyarlı ortak bir kullanıcı-öğe temsili öğrenir. Bir CNN yorumlardan (review), diğeri kullanıcı ve öğe kimliklerinin etkileşiminden öznitelik çıkarır. Sonuçlar faktorizasyon makinesi ve dinamik füzyonla birleştirilir. 2019 tarihli verimli hibrit modelde (Huang vd.) SDAE-FM, DNN ve Siamese yapıda metrik öğrenme modülleri birleştirilir. Kullanıcı temel bilgi ve geçmiş tercih olarak iki ayrı biçimde temsil edilir (ekrandan, 01:00:00). 2021 tarihli modelde (Khan vd.) UserNet ve ItemNet adlı iki CNN, yorum ve meta veri ağlarını ayrı eğitir. Füzyon ve dikkat katmanlarından sonra tam bağlı katmanla regresyon yapılır. Model Amazon ve Yelp veri setlerinde RMSE ile değerlendirilir (ekrandan, 01:05:00).

- **Manifold öğrenme.** Yüksek boyutlu veri doğrudan görselleştirilemez ve yeterince analiz edilemez. Örneğin bin özniteliği olan bir ürünü bu boyutta incelemek zordur. Doğrusal veride PCA iyi çalışır, doğrusal olmayan veride ise manifold öğrenme gerekir. Tenenbaum ve arkadaşları (2000), PCA ve MDS'nin yalnız Öklit uzaklığına dayandığı için içsel boyutu yakalayamadığını gördü ve Isomap'i önerdi. Isomap önce bir komşuluk grafı kurar, sonra bütün noktalar için en kısa yolları hesaplayarak jeodezik mesafeyi tahmin eder, en sonda düşük boyutta gösterir. Aynı yıl Roweis ve Saul LLE'yi önerdi. LLE her noktayı komşularının ağırlıklı toplamıyla yeniden kurar ve aynı ağırlıkları düşük boyutta korur (ekrandan, 01:25:00):

  $$\varepsilon(W)=\sum_i \Big|\vec X_i-\sum_j W_{ij}\vec X_j\Big|^2,\qquad \Phi(Y)=\sum_i \Big|\vec Y_i-\sum_j W_{ij}\vec Y_j\Big|^2,\qquad M_{ij}=\delta_{ij}-W_{ij}-W_{ji}+\sum_k W_{ki}W_{kj}$$

  LLE yalnız yerel komşuluklarla çalışır ve Isomap'ten daha kısa sürede daha iyi sonuç verdiği raporlanmıştır. Laplacian Eigenmaps (Belkin ve Niyogi, 2003) komşuluk ağırlıklarını en küçük kareler yerine bir çekirdekle belirler. Hessian Eigenmaps (Donoho ve Grimes, 2003) son adımda Hessian kullanır. Daha başarılıdır ama yüksek boyutlu veride maliyetlidir. Sınıflandırma örneklerinde ulaşım türü tespiti çalışmasında (2017) 14 öznitelik MDS, t-SNE, Isomap, LLE ve Spectral Embedding ile 2 boyuta indirildi. En iyi sonucu t-SNE verdi. SVM çekirdekleri arasında en iyi sonuç RBF ile alındı: AUC 0,979, CA 0,963, F1 0,963 (ekrandan, 01:35:00).

- **Çok dilli kelime vektörleri.** Tek dilli kelime gömmeleri seyrek vektörler yerine yoğun ve daha düşük boyutlu vektörler verir. Bu vektörlerde erkek-kadın, fiil zamanı ve ülke-başkent gibi anlamsal ilişkiler kodlanır. Vektör boyutu bir hiperparametredir. Paylaşılan gömmelerde 50, 100 ve 300 gibi boyutlar yaygındır. Boyut arttıkça daha çok anlam kodlanır, ama donanım ihtiyacı da artar. Çok dilli kelime vektörleri, ayrı ayrı öğrenilmiş uzayları ortak bir uzaya taşır. Sunulan bir derlemeye göre literatürdeki yöntemler farklı görünse de büyük ölçüde aynı amaç fonksiyonunu optimize eder. Başarıyı en çok belirleyen şey kullanılan veridir. Eşleme tabanlı yöntemler bir dönüşüm matrisi öğrenir (regresyon, ortogonal, kanonik ve marjin tabanlı yöntemler). Sözde çok dilli derlem yaklaşımı iki dilin derlemini birleştirip bazı kelimeleri karşılıklarıyla değiştirir ve tek dilli bir gömme yöntemini bu karma derlemde çalıştırır. Ortak yöntemler bu iki yaklaşımın olumlu yanlarını birleştirir. İç değerlendirme, kelime benzerliklerinin doğru çıkıp çıkmadığına bakar (örneğin "car" ile "automobile" yakın olmalıdır). Dış değerlendirmede kelime hizalama tahmini ve iki dilli sözlük çıkarımı (bilingual lexicon induction) kullanılır. Uygulama alanları: doküman sınıflandırma, bağımlılık ayrıştırma, sözcük türü etiketleme, adlandırılmış varlık tanıma, anlamsal ayrıştırma.

- **Çoklu robot yol planlama.** Robotlar endüstriyel üretimden sağlık, ulaşım, savunma ve gündelik hayata yayıldı. Bu yüzden çevreyi algılama, engellerden kaçınma ve çevredeki kişilerle etkileşim önem kazandı. Yol planlamada ortam statik ya da dinamik, bilinen ya da belirsiz olabilir. Klasik algoritmalar ızgara tabanlı (A*, D*), geometrik (Minkowski toplamı, görünürlük grafı, hücre ayrıştırma) ve örnekleme tabanlı olarak sınıflandırıldı. Klasik matematiksel algoritmalar aynı başlangıç değerleriyle hep aynı sonucu verir. Çözüm kümesi büyük problemlerde ise maliyetlidir. Meta-sezgisel algoritmalar rastgelelik içerir. Basit, esnek ve gradyansızdırlar, yerel optimumdan kaçabilirler. Evrim tabanlılar seçilim, çaprazlama ve mutasyonla yeni popülasyon üretir (genetik algoritma). Fizik tabanlılar fizik yasalarından esinlenir: benzetimli tavlama (1983) ile kara delik algoritması (2013) arasında yerçekimsel arama, merkezi kuvvet optimizasyonu, yüklü sistem araması ve galaksi tabanlı arama gibi yöntemler yer alır (ekrandan, 02:35:00). Sürü tabanlılar parçacık sürü optimizasyonuyla başladı. Davranışsal tabanlılar insan davranışından esinlenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
