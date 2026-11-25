# Ders 8 Genişletilmiş Notu: Seminer Sunumları: Hata Yüzeyi Analizi ve Tek Hücre RNA Dizileme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu derste iki öğrenci seminer sunumu yaptı. İlk sunum yapay sinir ağlarının hata (loss) parametre yüzeylerinin analizi üzerine, ikinci sunum tek hücre RNA dizileme (single-cell RNA sequencing) verilerinin hesaplamalı analizi üzerine bir literatür taramasıydı. Hoca sunumlar sırasında ve sonunda sorular sordu. Aşağıda sunumların teknik içeriği, dersteki sırayla verilmiştir.

## İçindekiler

- 1. Hata parametre yüzeylerine giriş
- 2. Literatür: doğrusal yol deneyinden mod bağlantılılığına
- 3. Sunucunun deneyleri: ara noktalardan topluluk modeli
- 4. Sunucunun deneyleri: Monte Carlo ile yerel minimum topolojisi
- 5. Tek hücre RNA dizileme: temel kavramlar ve analiz akışı
- 6. İncelenen makaleler
- 7. Ek yöntemler: deconvolution ve bulk veriyle çalışmalar
- Örnek Sorular

## 1. Hata parametre yüzeylerine giriş

Sunum, giriş, literatür taraması, sunucunun kendi deneyleri ve sonuç/gelecek çalışmalar bölümlerinden oluşuyordu.

Bir sinir ağını eğitmek, çok boyutlu ve konveks olmayan (non-convex) bir fonksiyon üzerinde optimizasyon problemi çözmek demektir (ekrandan, 00:10:00). Bu problemi çözmek için Gradient Descent, Stochastic Gradient Descent (SGD) ve Adam gibi algoritmalar kullanılır. Parametrelerin her değeri için kayıp fonksiyonunun aldığı değer bir yüzey oluşturur; buna hata parametre yüzeyi (loss landscape) denir.

Gerçek yüzey çok boyutludur ve doğrudan çizilemez, ancak iki ve üç boyutlu temsilleri gösterilebilir. Slayttaki örnek görsel Snapshot Ensembles makalesinden alınmıştı: mavi nokta, parametrelerin ilk değerleriyle bulunan başlangıç noktasıdır; eğitim ilerledikçe model bir yerel minimuma doğru ilerler. Eğitimin amacı bu yerel minimumlardan herhangi birine yakınsamaktır.

Slaytta vurgulanan bir nokta, yerel minimum ve eyer (saddle) noktalarının sayısının parametre sayısıyla üstel biçimde artmasıdır (ekrandan, 00:10:00; slaytta bu iddia için tek nöronlarda üstel sayıda yerel minimum olduğunu gösteren 1996 tarihli bir çalışmaya atıf vardı). Hata yüzeyi analizinin amacı hem eğitim sürecini iyileştirmek hem de optimizasyon algoritmalarının nasıl iyileştirilebileceğini anlamaktır.

## 2. Literatür: doğrusal yol deneyinden mod bağlantılılığına

### 2.1 Doğrusal yol deneyi (2014)

Sunucunun incelediği çalışmaların neredeyse hepsi, Goodfellow ve arkadaşlarının 2014'te yaptığı bir çalışmaya atıf veriyordu. Bu çalışma iki soruya cevap arar:

- Sinir ağı eğitilirken model yalnız bir yerel minimuma mı gider, yoksa başka yerel minimumlara da girip çıkar mı?
- Model eğitim sırasında eyer noktalarından geçer mi, bu noktalara yaklaşınca hızı değişir mi?

Bunun için çok basit bir yöntem kullanılmıştır: linear path experiment (doğrusal yol deneyi). İki bilinen nokta, yani başlangıç parametreleri $\theta_0$ ve eğitim sonunda varılan parametreler $\theta_1$ arasındaki yol doğrusal interpolasyonla incelenir:

$$J\big((1-\alpha)\,\theta_0 + \alpha\,\theta_1\big), \qquad \alpha \in [0, 1]$$

<!-- BELİRSİZ: formülün slaytı karelerde görülmedi; altyazıda yalnız kayıp fonksiyonu J, parametreler Q0 ve Q1 ve 0-1 arasında değişen alfa geçiyor. Yazılan biçim yöntemin standart gösterimidir. -->

Burada $J$ kayıp fonksiyonu, $\theta$ parametrelerdir. $\alpha = 0$ başlangıç noktasını, $\alpha = 1$ yakınsanan noktayı verir; aradaki değerler iki nokta arasındaki yolu çizer.

Deneyde yazarlar kendi Multi-Prediction Deep Boltzmann Machine modellerini MNIST üzerinde eğitmiştir. Üç boyutlu çizimde başlangıçtan minimuma kadar modelin izlediği yol görülür. Yüzeyde ayrı bir yerel minimum ya da eyer noktası gibi duran bir anomali vardır; sorulara cevap "evet" olsaydı yolun bu anomaliye girmesi gerekirdi. Oysa yol anomalinin yanından geçerek doğrudan minimuma yakınsar. Böylece iki soruya deneysel olarak "hayır" cevabı verilmiştir.

### 2.2 Farklı optimizasyon algoritmaları ve batch normalizasyon (2016)

2016'daki bir çalışma (D. J. Im, M. Tao, K. Branson, "An empirical analysis of the optimization of deep network loss surfaces", ekrandan, 00:15:00) bu yöntemi farklı optimizasyon algoritmaları ve farklı başlangıç noktalarıyla denemiştir. Ayrıca batch normalizasyonun yerel minimumlar arasındaki hata yüzeyini nasıl etkilediğini araştırmıştır. CIFAR ve MNIST veri setleri ile VGG, LSTM ve NIN modelleri kullanılmıştır.

Bulgular:

- Aynı başlangıç noktasından farklı optimizasyon yöntemleriyle (örneğin Adam, SGD, RMSprop, ADAM&RK2) eğitilen modeller farklı yerel minimumlara yakınsar.
- Farklı başlangıç noktalarından aynı optimizasyon yöntemiyle eğitilen modeller de farklı noktalara yakınsar.
- Slayttaki özet (ekrandan, 00:15:00): batch normalizasyon yapılmayan modellerde başarı başlangıç noktasına daha bağımlıdır; batch normalizasyonlu modeller arasında daha keskin unimodal sıçramalar, batch normalizasyonsuz modeller arasında ise unimodal olmayan tümsek yapılar görülür.

Slayttaki tablo, üst satırda "With Batch Normalization", alt satırda "Without Batch Normalization" olmak üzere üç minimum arasındaki yüzeyleri gösteriyordu. Üçgenlerin köşelerinde hangi optimizasyon algoritmasıyla bulunan minimum olduğu (Adam, RMSprop, SGD, SGDM, Adadelta, ADAM&RK2) ve modelin adı (VGG, NIN) yazıyordu.

### 2.3 Mode connectivity ve Fast Geometric Ensembling (2018)

2018'deki çalışma (sunumda Garipov tarafından yapılan çalışma olarak anıldı) şu soruyu sordu: bulunan yerel minimumlar arasında, aynı doğruluk derecesini koruyarak onları birleştiren yollar bulunabilir mi? Buna mode connectivity (mod bağlantılılığı) denir. İkinci soru, bu yollar üzerindeki noktalarla Snapshot Ensemble'daki gibi bir topluluk (ensemble) modeli kurulup kurulamayacağıdır.

Temel fikir şudur: iki minimum arasındaki doğrusal yol yüksek kayıplı bir bölgeden geçer. Ancak yol üzerindeki kayıp SGD ile optimize edilirse, aynı doğruluğu koruyan yeni (eğri) yollar keşfedilir. Bu yol üzerindeki noktalarla kurulan topluluk yöntemine Fast Geometric Ensembling (FGE) adı verilmiştir.

Deneylerde epoch sayısı karşılaştırılan modellerde eşit tutulmuştur; grafikteki 1B, 2B, 3B gösterimi epoch bütçesini ifade eder ($B$ yaklaşık 150 epoch). Üç yöntem karşılaştırılmıştır: herhangi bir topluluk kullanmayan bireysel model, Snapshot Ensemble ve FGE. Grafikte çarpılar bireysel modelleri, kareler bunların topluluk sonuçlarını gösterir. FGE'nin daha başarılı olduğu görülmüştür.

### 2.4 Hiperparametre değişikliklerinde mod bağlantılılığı

Sunucunun aktardığı bir başka çalışmada, bir referans model alınıp hiperparametreleri tek tek değiştirilmiştir: örneğin yalnız batch boyutu 4000 yapılmış, başka bir modelde optimizasyon yöntemi değiştirilmiş, bir diğerinde veri çoğullama (data augmentation) kaldırılmıştır. Bu modeller arasında doğrusal yol deneyi ve mode connectivity yöntemiyle yollar 20, 40, 60 ve 80 epoch'ta incelenmiştir. Sonuç, mode connectivity yönteminin esnek olduğu ve farklı hiperparametrelerle eğitilmiş modeller arasında da yol bulunabildiğidir.

<!-- BELİRSİZ: bu çalışmanın künyesi altyazıda ve karelerde geçmiyor. -->

### 2.5 Mode connecting volumes (2021)

Sunucu, bu yöntemlerin özetini veren 2021 tarihli bir çalışmayı da anlattı (G. W. Benton, W. J. Maddox, S. Lotfi, A. G. Wilson, "Loss surface simplexes for mode connecting volumes and fast ensembling", ekrandan, 00:20:00). Slayttaki üç kontur görseli üç bakış açısını karşılaştırıyordu:

- Doğrusal yol deneyi görüşü: farklı başlangıçlardan ($w_0, w_1, w_2, w_3$) eğitilen her model ayrı bir minimuma yakınsar.
- Mod bağlantılılığı görüşü: bu minimumlar düşük kayıplı yollarla birbirine bağlıdır.
- Mod bağlantılı hacim görüşü: minimumlar arasında yalnız yollar değil, düşük kayıplı hacimler de vardır.

İki nokta arasında birden fazla yol bulunabilir. Bu yollardaki $\theta_0$, $\theta_1$, $\theta_2$ modları birleştirilerek bir hacim (simpleks) elde edilir. Slayttaki ısı haritalarında (renk ölçeği cross entropy loss, 0,00 ile 1,05 arası) $w_0$, $w_1$ uç noktaları ve $\theta$ köşeleriyle kurulan üçgenler gösteriliyordu (ekrandan, 00:20:00). Bu hacmin içinden hangi nokta alınırsa alınsın, doğruluk aynıdır.

### 2.6 Literatürden çıkarılanlar

- Sinir ağı modelleri aynı noktadan başlasa bile farklı yerel minimumlara ulaşabilir.
- Bu yerel minimumlar arasında düşük kayıplı yollar, hatta hacimler olabilir.
- İncelenen hemen her çalışma, batch normalizasyonun hata yüzeyini nasıl etkilediğini araştırmıştır.

## 3. Sunucunun deneyleri: ara noktalardan topluluk modeli

Sunucu iki soru üzerinde çalıştığını anlattı: yerel minimumlar arasında doğrusal interpolasyonla topluluk modeli kurulabilir mi, ve varılan yerel minimumun çevresindeki topoloji Monte Carlo yöntemiyle keşfedilebilir mi?

### 3.1 Deney düzeni

DenseNet169, DenseNet201 ve EfficientNet modelleri kullanıldı. Farklı başlangıç noktalarından eğitilen 5 model, bir indirgeme çiziminde turuncu noktalarla, aralarından seçilen noktalar mavi noktalarla gösterildi; bu çizimin amacı noktaların gerçekten farklı olduğunu göstermekti.

İki minimum $Q_0$ ve $Q_1$ arasındaki doğrusal yol 10 parçaya bölündü, yani uçlar dışında 9 ara nokta alındı (ekrandan, 00:25:00). Karedeki iki grafik "Lokal Minimum Noktalar Arası Lineer İnterpolasyon ve Topluluk Öğrenme Modeli" başlığını taşıyordu:

- Mavi eğri, "eğitimden önce ara noktalar": uçlarda kayıp yaklaşık 0,5 iken ara noktalarda hızla yükseliyor, 3. noktada yaklaşık 3,6 ile tepe yapıyor, 9. noktada yaklaşık 1,6'ya iniyor.
- Yeşil eğri, "eğitimden sonra ara noktalar": bütün ara noktalar yaklaşık 0,5 düzeyinde; yalnız 5. noktada hafif bir çıkıntı var.
- Soldaki grafikte 2. ve 8. noktalar, sağdaki grafikte 5. nokta "seçilen nokta" olarak işaretli.

Ara noktalar eşit bir bütçeyle eğitildi. Toplam bütçe model başına 50 epoch idi; ara noktalar asıl eğitimin onda biri kadar eğitildi (örneğin asıl model 10 epoch ise ara nokta 1 epoch). Sunucu, ara noktadan başlayıp 1 epoch eğitince asıl noktayla aynı doğruluğa ulaşılabildiğini gözlemledi. Ardından her iki minimum arasından ikişer nokta seçilip bir topluluk modeli kuruldu.

### 3.2 Sonuçlar

Karşılaştırmada 1-5 numaralı orijinal modeller, ara noktalardan alınan modeller, orijinal modellerle kurulan topluluk (sarı) ve ara noktalarla kurulan topluluk (kırmızı) yer aldı. Karşılaştırmanın adil olması için beşinci orijinal model, ara noktaların alındığı dört modelin topluluğuna dışarıdan eklendi. DenseNet169'da topluluklar arasında büyük fark yoktu ama ara noktalardan alınan bireysel modeller orijinal modellerden daha iyiydi. DenseNet201 ve EfficientNet'te aynı sonuç görülmedi.

### 3.3 Eyer noktasından ve üç modelin ortasından nokta alma

Topluluk modellerinde üyeler arasındaki varyans (çeşitlilik) arttıkça başarı artar. Bu yüzden sunucu, iki ara nokta yerine doğrudan eyer noktasından (tam ortadaki 5. noktadan) nokta almayı denedi; amaç farklı sorulara cevap veren daha çeşitli modeller elde etmekti.

Burada bir sınırlama çıktı: dört modelin her ikilisinden yalnız bir orta nokta alınınca alınabilecek başka nokta kalmıyordu. Bu yüzden literatürdeki hacim fikri kullanıldı: iki model yerine üç model birleştirilip tam ortasındaki model alındı. Karşılaştırmada orijinal modeller (1-5), ikili ara noktalar (1-2, 1-3, 1-4, ...) ve üçlü ara noktalar (1-2-3, 1-2-4, 1-3-4, 2-3-4) yer aldı. Belirgin bir iyileşme görülmedi; DenseNet201'de orijinal modeller ara noktalardan daha iyi çıktı. Sunucu bu deney hattının bu sonuçla bırakıldığını söyledi.

## 4. Sunucunun deneyleri: Monte Carlo ile yerel minimum topolojisi

### 4.1 Yöntem

İkinci soru, varılan yerel minimumun çevresindeki topolojinin, yani dağılımın keşfedilip keşfedilemeyeceğiydi. Bunun için stokastik bir yöntem olan Monte Carlo kullanıldı (sunumda sözde kodu gösterildi).

- Varılan son noktanın parametrelerine küçük rastgele gürültü değerleri eklenir.
- Yeni nokta, eski noktadan daha iyiyse ya da aradaki fark çok küçükse (0,001) kabul edilir.
- Ayrıca sabit bir doğruluk eşiği (0,70) kullanılır. Bunun nedeni, küçük farklara izin verildiğinde zincirin zamanla giderek daha kötü noktalara kayabilmesidir.

<!-- BELİRSİZ: gürültü aralığı altyazıda "0.001 ve 0.001 arasında" diye geçiyor; büyük olasılıkla -0,001 ile 0,001 arası kastediliyor. Sözde kodun bulunduğu slayt karelerde görülmedi. -->

Her kabul edilen nokta yeni başlangıç kabul edilerek devam edilince bulunan noktaların çevreyi kaplamak yerine tek bir yöne gittiği görüldü. Bu yüzden zincir dallandırıldı: minimumdan 5 farklı nokta bulunur, her birinden yine 5 farklı nokta, onların her birinden yine 5 nokta; böylece ağaç gibi dallanan bir yapı kurulur. Bulunan her nokta istenen özellikte olmaz, çünkü topolojide yer yer daha yüksek bölgeler vardır; bu noktalar otomatik olarak elenir.

### 4.2 Görselleştirme

Noktalar PCA ile indirgenip çizildiğinde, artık tek bir yol değil, topolojiye göre dağılmış bir yapı görüldü. Aynı başlangıçtan iki farklı minimuma yakınsamış iki model için yöntem çalıştırılıp t-SNE ile 3B ve 2B çizildiğinde (ekrandan, 00:30:00; "3D Tsne-DogrulukDegeri" ve "2D Tsne" başlıklı grafikler, lejantta "Weight1 yeni nokta" ve "Weight2 yeni nokta"), iki minimumun ve çevrelerinde bulunan noktaların ayrı kümeler oluşturduğu görüldü. Kırmızı ve mavi noktalar iki yerel minimumu ve onların modellerini, siyah noktalar ise hiçbir eğitim yapılmadan tamamen rastgele bulunan ve minimumla aynı doğruluğa sahip noktaları gösteriyordu.

### 4.3 Batch normalizasyonun etkisi

Yalnız batch normalizasyon açısından farklı iki model karşılaştırıldı. Minimum noktası kırmızı yıldızla işaretliydi.

- Batch normalizasyonsuz modelde 5 dallanmayla 909 nokta bulundu.
- Aynı ayarlarla batch normalizasyonlu modelde 5 dallanmayla yalnız 2 nokta bulunabildi. Adım sayısı eşitlik için değiştirilmeden dallanma sayısı 10, 20 diye artırıldı; 100 dallanmada ancak 130 nokta bulunabildi.

Bulunan noktaların gerçekten minimum çevresinde olup olmadığını sınamak için her iki modelden 100'er nokta alındı ve minimumdan her birine doğrusal yol çizildi. Parametre uzayı 122.570 boyutluydu; çizim için 2B'ye indirgendi. Beklenti kırmızı minimumun ortada, mavi noktaların çevresinde olmasıydı. 2B çizimde bu tam görülmedi, 3B çizimde ise Monte Carlo daha uzun çalıştırılırsa minimumun diğer noktaların ortasında kalacağı görüldü. Batch normalizasyonlu modelde çevre daha dar ve keskin, batch normalizasyonsuz modelde daha düzdü.

Daha ayrıntılı analiz için minimumdan bulunan noktalara çizilen doğrusal yollar boyunca kayıp değerleri arka arkaya çizildi (ekrandan, 00:35:00). Her 10 noktalık parça bir yolun kayıp profilini gösterir (örneğin 240-250 aralığı). Kare şu görünümü veriyordu:

- Üst satır, "BatchNormalization": kayıp yaklaşık 1,03 ile 1,10 arasında düzensiz sıçramalar yapıyor; büyütülmüş bölümde (yaklaşık 230-290 aralığı) yollar dalgalı.
- Alt satır, "Normal" (batch normalizasyonsuz): kayıp yaklaşık 1,19 ile 1,22 arasında; büyütülmüş bölümde (yaklaşık 260-310) her yol yüksek bir noktadan düzgün biçimde aşağı iniyor, testere dişi gibi bir desen var.
- Sağda karşılaştırma için Rastrigin fonksiyonu ("Global minimum at [0 0]") ve Sphere fonksiyonu yüzeyleri.

Sunucu, daha önce optimizasyon yöntemlerini çok boyutlu Rastrigin ve Sphere fonksiyonları üzerinde incelediğini, batch normalizasyonlu modelin minimum çevresinin Rastrigin gibi dalgalı, batch normalizasyonsuz modelin ise daha düz olduğunu söyledi. Düz bir çevrede aynı adım büyüklüğüyle hareket etmek kolay olduğu için 909 nokta rahatça bulunurken, dalgalı çevrede aynı adım sayısıyla hareket etmek çok daha zordur.

> **Ek bilgi (derste anlatılmadı):** Rastrigin fonksiyonu $f(x) = 10n + \sum_{i=1}^{n}\left[x_i^2 - 10\cos(2\pi x_i)\right]$ biçiminde tanımlanan, çok sayıda düzenli yerel minimumu olan bir test fonksiyonudur; global minimumu $x = 0$ noktasındadır. Sphere fonksiyonu $f(x) = \sum_i x_i^2$ ise tek minimumlu, düzgün bir kâse biçimindedir. Optimizasyon algoritmaları bu iki uç durumda sık sınanır.

### 4.4 Sonuçlar ve gelecek çalışmalar

- Aynı modelle farklı minimum noktalarına ulaşılabilir.
- Hata yüzeyinin topolojisi batch normalizasyonla değişir.
- Monte Carlo yöntemiyle yerel minimum çevresinin topolojisi keşfedilebilir.
- Planlanan çalışmalar: bu yöntemle farklı minimumlar arasında hacim bulunup bulunamayacağı, ve yerel minimumlara daha hızlı ulaşan optimizasyon yöntemleri geliştirilip geliştirilemeyeceği.

Sunucu, sonuçların 122 bin boyuttan 2-3 boyuta indirgenmiş çizimlere dayandığı için kesin değil empirik olduğunu, incelediği diğer çalışmaların da bulgularını bu şekilde ifade ettiğini vurguladı.

## 5. Tek hücre RNA dizileme: temel kavramlar ve analiz akışı

İkinci sunum, tek hücre RNA dizileme verilerinin hesaplamalı analizine yönelik bir literatür taramasıydı. Makaleler kronolojik sırayla değil, genelden (laboratuvar ve tıp ağırlıklı geniş çaplı makaleler) özele (hesaplamalı yöntem makaleleri) doğru sıralanmıştı.

### 5.1 RNA dizileme

Bir dokudaki, yani bir örnekteki mRNA'ların (transkriptlerin) miktarına transkriptom denir. RNA dizileme teknolojisi, transkriptlerin miktarını gen düzeyinde belirleyen bir teknolojidir. İki türü vardır (ekrandan, 00:40:00):

- **Bulk RNA-seq:** Örnek tabanlıdır. Heterojen olarak bir arada bulunan hücre popülasyonundaki transkript seviyelerini ölçer ve popülasyonun ortalama transkript seviyesini verir.
- **Single-cell RNA-seq:** En küçük birim olarak hücreyi seçer; her hücre üzerinde ayrı ayrı ölçüm yapılır. Heterojen hücre popülasyonlarının transkriptom durumunu tam anlamak için bu teknik gerekir.

Slayttaki şema iki akışı gösteriyordu: single-cell için tümör dokusu, tek hücreler, dizileme, scRNA-seq veri tabanı; bulk için tümör dokusu, doku bulk RNA, dizileme, bulk RNA-seq (TCGA) veri tabanı.

Tek hücre analizleri 2014'ten beri yaygınlaşmaktadır, ancak çok maliyetli olduğu ve ciddi laboratuvar yükü gerektirdiği için sınırlı uygulanır. Biyoloji ve tıpta önemlidir: tek hücre düzeyinde gen ifadesi profili çıkarmayı, erken embriyonik gelişimin incelenmesini, hastalıkların önceden teşhisini ve hastalıklarda rol oynayan hücrelerin ortaya çıkarılmasını sağlar.

### 5.2 Veri ve temel problem

Bir örnekten çok sayıda hücre alınır ve bu hücreler farklı popülasyonlara (bağışıklık hücreleri, tümör hücreleri vb.) aittir. En önemli adım, hücrelerin hangi popülasyona ait olduğunu bulmaktır. Laboratuvarda RNA izolasyonu ve ardından DNA sentezi yapılıp dizileme yapılır. Sonuçta satırlarında genler, sütunlarında bütün örneklerin hücreleri bulunan çok büyük bir matris elde edilir.

Bu verileri işlemek için Python ve R'da geliştirilmiş çeşitli platformlar vardır; iş akışları birbirine çok benzer. Bilgisayar mühendisinin rolü bu analiz adımlarındadır.

### 5.3 Analiz akışı

- **Kalite kontrol (QC):** Sonraki analizleri yanıltmaması için düşük kaliteli hücreler ve genler elenir.
  - Doublet hücreler tek bir hücreyi değil, iki hücrenin birleşimini temsil eder; bu yüzden beklenmedik derecede yüksek ifade seviyesine sahiptir. Bir eşik değeri belirlenerek çok yüksek ifadeli hücreler elenir.
  - Çok az gen ifade eden hücreler de yetersiz kabul edilip elenir.
  - Mitokondriyal ve ribozomal genlerin biyolojik sinyalinin düşük olduğu, yani yanıltıcı olabileceği varsayımıyla bu genler elenir.
- **Batch düzeltme:** Farklı veri setleri birleştirildiğinde ya da örnekler farklı zamanlarda, farklı teknolojilerle elde edildiğinde gerekir. Literatürde bunun için hazır araçlar vardır.
- **Özellik seçimi:** Genler özellik olarak kullanılır. Korelasyon analizi ya da çeşitli metriklerle skor hesaplanır ve en yüksek skorlu genlerle çalışılır.
- **Boyut indirgeme:** Görselleştirme için kullanılır; genelde bilinen yöntemler (PCA, t-SNE, UMAP) uygulanır.
- **Alt analizler (downstream):** Popülasyonları ayırmak için kümeleme (örneğin K-means) ve sınıflandırma (örneğin KNN) yöntemleri kullanılır.
- **Küme etiketleme (cluster annotation):** Kümelerin hangi hücre tipine ait olduğu, literatürdeki marker genlerden ya da veri tabanlarına bağlı otomatik etiketleme araçlarından yararlanılarak belirlenir.
- **Diğer analizler:** Trajektori analizi, birbiriyle ilişkili genleri bulmak için pathway analizi, belirli bir hastalığı etkileyen marker genlerin bulunması.

<!-- BELİRSİZ: kalite kontrol bölümünde altyazıda "tabletler" geçiyor; bağlamdan büyük olasılıkla "doublet" kastediliyor. -->

## 6. İncelenen makaleler

### 6.1 Pankreas kanserinde birincil tümör ve metastatik lezyonlar

İlk makale (slayt başlığı: "Single-cell transcriptome analysis ... primary tumors and metastatic lesions", ekrandan, 00:45:00) pankreatik duktal adenokarsinom (PDAC) hastalarından elde edilen birincil tümör ve metastatik biyopsilerdeki bireysel hücrelerin transkriptomlarını profillemeyi amaçlar. Metastatik tümör, örneğin pankreastaki bir tümörün akciğer ya da karaciğer gibi başka bir dokuya yayılarak orada tümör oluşturmasıdır.

Yöntem:

- Hücre tiplerini tanımlamak için denetimsiz kümeleme analizi yapılmıştır.
- Literatürdeki marker genlerle elle hücre tipi belirlemesi yapılmış, ardından literatürde olmayan yeni hücre grupları için yaklaşık 200 bin hücreyle eğitilmiş, yeni bir denetimli sınıflandırma algoritması olan SuperCT kullanılmıştır.
- Görselleştirme için t-SNE benzeri bir yöntemle haritalar çıkarılmıştır.
- Aynı makalede public bulk veri setleri ile genlerin sağkalım analizi de yapılmıştır.
- Veri seti görece küçüktür: yaklaşık 22.000 gen ve 7800 hücre.

Sağkalım analizi, hastalığın seyrini incelemek ya da risk faktörlerini belirlemek için yapılır. Tek hücre analiziyle her hücre tipi için genler belirlenir, bu genler arasında korelasyon analizi yapılır, en yüksek korelasyonlu genlerin ifade seviyelerine göre örnekler yüksek (kırmızı eğri) ve düşük (mavi eğri) olarak iki gruba ayrılır ve sağkalım eğrileri karşılaştırılır.

Sonuçlar (ekrandan, 00:45:00): hücre tipleri tümör hücreleri, endotel hücreleri, kanserle ilişkili fibroblastlar (CAF'ler) ve bağışıklık hücreleri olarak bulunmuştur. Tümörün hücresel bileşimi önemli bir faktördür; EMT+ kanser hücrelerinin CAF'ları aktive ettiği ve endotel hücrelerinin (kan damarlarındaki hücreler) sağkalım analiziyle önemli ölçüde ilişkili olduğu bulunmuştur.

### 6.2 Tümör ve kontrol dokularıyla daha büyük veri seti

İkinci makalede pankreas tümör hücreleri ve normal hücreler kullanılmış, yaklaşık 57.000 hücrelik bir veri seti laboratuvarda üretilmiştir. Önceki makaleden farkı trajektori analizidir: birbiriyle ilişkili genleri ve bir yörüngeyi (path) ortaya çıkarır. Bunun sonucunda bağışıklık hücre tipleri için literatürde bulunmayan yeni marker genler tespit edilmiştir; yeni marker genler yeni tedavi önerileri açısından önemlidir.

Kalite kontrolden sonra, bütün hücre grupları belirlenince yeni marker genler bulmak için Differential Expression Gene (DEG) analizi denen istatistiksel analiz kullanılmıştır. Slayttaki gösterimler (ekrandan, 00:50:00):

- Belirli marker genlerin ifade değerlerine göre heatmap: hücre grupları Ductal 1, Ductal 2, Acinar, Endocrine, Endothelial, Fibroblast, Stellate, Macrophage, T cell, B cell; her gruba ait genler (örneğin KRT19, PRSS1, CHGB, CDH5, LUM, RGS5, AIF1, CD3D, MS4A1) kendi grubunda kırmızı, yani yüksek ifadeli görünür.
- Aynı bilgiyi veren violin plot gösterimi.
- DEG ve trajektori analizlerinin ardından normal dokularda belirlenen anahtar düzenleyici (key regulator) genlerin abnormal (P1-P4) ve malign (P5-P8) olarak kümelenmesi. Anahtar düzenleyici genler, başka genleri etkileyen ve kontrol eden genlerdir.

### 6.3 Hücre tipi belirleme yöntemlerinin karşılaştırılması

Bu metodolojik makalede hücre tipi belirleme (cell identification) için 22 farklı yöntem, 27 farklı public veri setinde karşılaştırılmıştır. Veri setleri farklı boyut, teknoloji, tür (insan, fare) ve karmaşıklıktadır (ekrandan, 00:55:00): organizma fare ve insan; doku beyin, pankreas ve kan (PBMC).

Ölçütler:

- F-skoru,
- etiketlenemeyen hücre oranı,
- hesaplama süresi,
- özellik sayısı ve hücre sayısı arttıkça ve karmaşık veri setlerinde yöntemlerin nasıl tepki verdiği.

Bulgular (ekrandan, 00:55:00):

- Zheng 68K (11 popülasyon) yüksek karmaşıklıklı ve az popülasyonlu olduğu için yöntemler düşük performans göstermiştir.
- TM (55 popülasyon) ve AMB92 (92 popülasyon) yeterince farklı popülasyon içerdiği için yüksek performans alınmıştır.
- CellBench 10X ve CEL-Seq2 kolay sınıflanabilir veri setleridir. En yaygın teknoloji olan 10X Genomics ile üretilen verilerin daha kolay işlendiği görülmüştür.

Yöntemler Random Forest, Linear Discriminant Analysis, SVM, KNN gibi farklı sınıflandırıcılar kullanır; ön bilgi gerektirenler ve gerektirmeyenler olarak da ayrılmıştır. Başarı tablosunda maviye gidildikçe başarı düşer; etiketlenemeyen hücre tablosunda mavi, etiketlenemeyen oranının az olduğunu gösterir. Hücre benzerliğine bakan CellBlast ve KNN düşük performans göstermiş, SVM'in bir türevi ve iki yöntem daha yüksek başarı göstermiştir. İki tablo birlikte değerlendirildiğinde en iyi performansı SVM vermiştir. Hesaplama süresinde de SVM öne çıkmış, en yavaş yöntem bir başka yöntem olmuştur.

<!-- BELİRSİZ: altyazıda en yavaş yöntem "Singular", yüksek başarılı yöntemler "single mapsel, single prediction" diye geçiyor; yöntem adları karelerden doğrulanamadı. -->

### 6.4 Tümör mikroçevresi

Henüz hakemli yayın olarak çıkmamış, bioRxiv'de yayınlanmış bir makale de anlatıldı. Aynı iş akışını uygular, ama ek olarak tümörün bulunduğu ortamı (tümör mikroçevresi) inceler; bu ortam bozuldukça tümör büyür, farklılaşır ve kötüleşir. Ortam üç sınıfa ayrılmış ve bu ayrımın pankreas kanserinin ilerlemesinde etkili olduğu gösterilmiştir. 10 hastanın verisi ile neredeyse her kanser türü için verisi bulunan public TCGA veri seti kullanılmıştır.

Genler 72'ye kadar azaltılıp sağkalım analizi yapılmıştır. Alt gruplara tek tek bakıldığında sağkalım analizi anlamlı çıkmamıştır (genelde p-değeri 0,05'in altındaysa anlamlı fark var denir). Örneklerin tek bir alt gruba mı ait olduğuna yoksa birden fazla alt grup mu içerdiğine (heterojenlik) göre bakıldığında ise hem 10 hastanın verisinde hem TCGA verisinde anlamlı sonuç çıkmıştır.

### 6.5 Pankreas kanseri alt tipleri

Bu çalışmada (slayt başlığı: "Subtypes of pancreatic ductal adenocarcinoma and their differing responses to therapy", ekrandan, 01:00:00) dokular, yani hastalar sınıflandırılmıştır. Pankreas kanseri üç moleküler alt tipe ayrılmıştır:

- Classical,
- Quasimesenchymal (QM),
- Exocrine-like.

Veri seti olarak hücre kültürü (cell lines) kullanılmıştır: hayvan ya da insandan alınan hücreler uygun besi ortamında çoğaltılır. Farklı çalışmalardan elde edilen örnekler birleştirilmiş, organizma olarak fare ve insan kullanılmıştır.

Yöntem olarak Nearest Template Prediction algoritması kullanılmıştır. Bu denetimli algoritma, ifade matrisini ve kansere ait imza (signature) genleri alarak sınıflama yapar. Alt tipler için yüksek değerli genler heatmap ile gösterilmiştir; örneğin klasik alt tipte hücre büyümesini ve değişimini etkileyen genler fazla çıkmıştır. Alt tipler arasında sağkalım farkı anlamlı bulunmuştur. Cox regresyon analizi (bağımsız değişkenlerin ilişkili olup olmadığını inceleyen analiz) ile alt tiplerin tümör boyutu ve derecesiyle ilişkili olmadığı görülmüştür.

Sonuçlar (ekrandan, 01:00:00): veriler PDA alt tiplerinin varlığını klinik olarak desteklemektedir; insan ve fare alt tipe özgü modellerin kullanımı, tedavi için fonksiyonel ve düzenleyici süreçlerin tanımlanmasını hızlandırır; QM-PDA alt tipi yüksek tümör derecesi ve kötü sağkalımla (poor prognosis) ilişkilidir.

### 6.6 Boyut indirgeme yöntemlerinin karşılaştırılması

Görselleştirme için kullanılan boyut indirgeme yöntemlerinden hangisinin daha iyi olduğu araştırılmıştır. t-SNE'nin çalışma süresini azaltmak için geliştirilen çeşitli türevleri, PCA ve UMAP karşılaştırılmıştır. UMAP en iyi yöntem olarak öne çıkmıştır:

- Hücre tipi haritalarında UMAP ve t-SNE benzer, başarılı haritalar üretmiştir; ancak yoğunluk ve dağılım açısından UMAP daha yoğun ve daha düzgün (üniform) kümeler vermiştir.
- Hesaplama süresi karşılaştırılmış; t-SNE'yi hızlandırmak için eklenen bir parametrenin pek işe yaramadığı görülmüştür.
- Hücre popülasyonlarını ayırmada Random Forest kullanıldığında PCA en başarısız yöntem çıkmıştır. Sunucu, genelde PCA ve UMAP'in birlikte kullanıldığını belirterek bu sonuca şaşırdığını söyledi.
- K-means ile kümeleme yapıldığında kümelerin tutarlılığı Normalized Mutual Information (NMI) ile ölçülmüştür; kümeler ne kadar yoğun ve bilgi taşıyorsa NMI o kadar yüksektir. Bu ölçütte de UMAP daha başarılıdır.

<!-- BELİRSİZ: t-SNE'yi hızlandıran parametrenin adı altyazıda "Latent Exegregation" diye bozuk geçiyor; sunucu da adından emin olmadığını söyledi. Büyük olasılıkla "early exaggeration" kastediliyor. -->

## 7. Ek yöntemler: deconvolution ve bulk veriyle çalışmalar

### 7.1 Deconvolution

Bulk veri setlerinde hücre tipleri bilinmez. Deconvolution ile tek tek hücreler gruplanamasa da hücre gruplarının oranları bulunabilir. Yöntem bir tek hücre veri setini referans olarak kullanır; bulk matris verildiğinde sonuç olarak hücre tipi oranlarını döndürür. Dezavantajı, her zaman bir tek hücre referansına ihtiyaç duyulmasıdır; referans yetersiz olduğunda ve yeni hücre grupları aranırken avantajlı değildir, çünkü zaten bilinen kullanılır. Başka bir çalışmada birden fazla referans veri setiyle topluluk (ensemble) yaklaşımıyla deconvolution yapılmıştır.

### 7.2 Yalnız bulk veriyle bir çalışma

Her çalışma bu kadar çok analiz içermez; yalnız bulk veriyle de çalışma yapılabilir. Bunu göstermek için bir konferans bildirisi anlatıldı (slayt başlığı: "Drug compound prediction-based analysis of cigarette smoking to Pancreatic Cancer patients: A Bioinformatics study", ekrandan, 01:05:00). Amaç, bulk veri setleriyle pankreas kanseri ile sigara kullanımı arasındaki ilişkiyi aramak ve ilaç tahmini yapmaktır. 2 microarray veri seti kullanılmıştır.

İş akışı:

- Differentially expressed genes (DEG) analiziyle iki veri setinde marker genlerin belirlenmesi,
- ortak genlerle protein-protein etkileşim (PPI) ağının kurulması,
- ağda birbiriyle en çok ilişkili hub genlerin belirlenmesi,
- en çok ilişkili ilaçların önerilmesi.

Sonuçlar (ekrandan, 01:05:00): DEG analiziyle 40 ortak gen bulunmuş, PPI ağıyla 10 hub gen belirlenmiş, RPA1 ve RPA2 genleri etkili bulunmuş, 5 ilaç bileşeni önerilmiştir.

> **Ek bilgi (derste anlatılmadı):** Hub gen, bir protein-protein etkileşim ağında çok sayıda bağlantıya sahip düğümdür. Ağ merkezliği yüksek olan bu genler, hastalıkla ilişkili biyolojik süreçlerde anahtar rol oynama olasılığı yüksek adaylar olarak değerlendirilir.

Hoca sunumun sonunda, bu tür disiplinler arası bir konuda üniversitedeki biyomühendislik programıyla etkileşimin ve işbirliğinin yararlı olabileceğini önerdi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:23:40): Grafikte "eğitimden önce ara noktalar" ve "eğitimden sonra ara noktalar" deniyor. Bu ne demek?

> **Cevap (derste verildi):** "Eğitimden önce", doğrusal yol deneyindeki gibi iki minimum arasına doğrusal bir yol çekilip ara noktaların kaybının hiç eğitim yapmadan hesaplanmasıdır; bu durumda iki nokta aynı doğrulukla birleştirilemez ve kayıp yükselir. "Eğitimden sonra", mode connectivity yöntemindeki gibi ara noktanın bu noktadan başlayarak kayba göre eğitilmesidir. Örneğin 1. ara noktanın kaybı eğitimle yaklaşık 1,5'ten yaklaşık 0,5'e iner.

**Soru 2** (derste sözlü, 00:24:36): Diğer ara noktalar için de durum benzer mi?

> **Cevap (derste verildi):** Bütün ara noktalar için benzerdir. Yalnız tam ortadaki 5. noktada hafif bir çıkıntı kalır. Bunun nedeni bu noktanın bir eyer noktası olması ve bu yüzden daha zor eğitilmesidir: eyer noktasının iki yanı minimuma, diğer yönleri yerel maksimuma doğru gider; gradyan yöntemi buradan çıkmakta zorlanır. Eyer noktalarından kaçınma, güncel ve çok çalışılan bir araştırma konusudur.

**Soru 3** (derste sözlü, 00:35:09): Batch normalizasyon kullanılmadığında daha fazla örnekle iş yapılmış olur; işlem karmaşıklığı daha fazla olmaz mı?

> **Cevap (derste verildi):** Normalde öyledir; örnek sayısı arttığı için durum farklılaşır ve bu, sonuçları etkileyen bir faktör olabilir. Ayrıca sonuçlar yaklaşık 122 bin boyuttan 2 ve 3 boyuta indirgenmiş çizimlere dayandığı için kesin değil, empirik bulgulardır.

**Soru 4** (derste sözlü, 00:36:08): Boyut indirgeme yalnız görselleştirme için mi yapılıyor, yoksa işlemler de düşük boyutta mı?

> **Cevap (derste verildi):** Boyut indirgeme yalnız görselleştirme içindir; Monte Carlo araması ve kayıp hesapları dahil bütün işlemler yüksek boyutlu parametre uzayında yapılır.

## Dersin Toparlaması

İlk sunum, derin ağların hata yüzeyinin yapısına dair literatürü doğrusal yol deneyinden (2014) mod bağlantılılığı ve FGE'ye (2018), oradan mod bağlantılı hacimlere (2021) kadar izledi. Ortak sonuç, aynı başlangıçtan bile farklı minimumlara ulaşılabildiği, bu minimumların düşük kayıplı yollar ve hacimlerle bağlı olabildiği ve batch normalizasyonun yüzeyin şeklini değiştirdiğidir. Sunucunun deneyleri, ara noktalardan topluluk kurmanın her modelde kazanç sağlamadığını, Monte Carlo ile minimum çevresinin keşfedilebildiğini ve batch normalizasyonlu modelde minimum çevresinin daha dalgalı olduğunu gösterdi; bu bulguların indirgenmiş çizimlere dayandığı için empirik olduğu vurgulandı.

İkinci sunum, tek hücre RNA dizileme verilerinin analiz akışını (kalite kontrol, batch düzeltme, özellik seçimi, boyut indirgeme, kümeleme ve etiketleme) ve pankreas kanseri odaklı makalelerde kullanılan yöntemleri (SuperCT, DEG, trajektori, sağkalım ve Cox analizleri, Nearest Template Prediction, deconvolution, PPI ağı) tanıttı. Yöntem karşılaştırmalarında hücre tipi belirlemede SVM'in, boyut indirgemede UMAP'in öne çıktığı aktarıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
