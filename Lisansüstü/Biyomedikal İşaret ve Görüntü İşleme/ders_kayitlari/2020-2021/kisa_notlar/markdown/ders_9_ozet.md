# Ders 9 Çalışma Özeti

## Genel Konular

- Biyomedikal veride makine öğrenmesi süreci
  - Süreç tahtada adım adım çizildi (ekrandan, 00:25:00 ve 00:45:00): veri elde etme (acquisition) → ham veri (raw data) → ön işleme (preprocessing) → veri setinin eğitim/doğrulama/test diye ayrılması → öznitelik çıkarma ve seçme → model (eğiticili ya da eğiticisiz) → son işleme (post-processing) → değerlendirme (evaluation).
  - Ham veri biyomedikal sensörlerden ya da cihazlardan gelir: MR, mikroskop görüntüsü, tek boyutlu işaret olarak EKG, EEG gibi.
  - Ön işleme: EKG'nin teşhiste kullanılacak parçalara bölünmesi, gürültünün süzgeçle giderilmesi, görüntüdeki beneklerin ve çekim hatalarının temizlenmesi, verinin belli bir aralığa (ör. $[-1,1]$) getirilmesi (normalizasyon), histogram eşitleme, aykırı değerlerin (anomali) giderilmesi.
- Eğitim, doğrulama ve test verisi
  - Veri seti genelde eğitim (training), doğrulama (validation) ve test olarak üçe, bazen yalnız eğitim ve test olarak ikiye ayrılır; eğitimin küçük bir kısmı doğrulama için kullanılabilir.
  - Test verisi her zaman verilmez. Verilmezse etiketli verinin bir kısmı performans ölçümü için ayrılmalıdır.
  - Eğitim verisine uygulanan bütün ön işleme adımları test verisine de aynen uygulanmalıdır.
- Öznitelik çıkarma (feature extraction): iki yaklaşım (ekrandan, 00:35:00)
  - 1) Zaman (uzamsal) domeninde, elle ya da otomatik ölçümler: EKG'de P dalgası, QRS kompleksi, ST ve PT aralıklarının uzunlukları, eğimler. Bu yaklaşım uzmanın (doktorun) gözle baktığı özellikleri taklit eder.
  - 2) Dönüşüm tabanlı yöntemler: PCA, DFT, dalgacık (wavelet), ICA. Veri başka bir uzaya taşınır, katsayılar öznitelik olarak kullanılır. Bu dönüşümleri insan beyninin yapması mümkün değildir.
  - Dönüşüm yöntemleri boyut azaltmaya (dimension reduction) da imkân verir: PCA'da özdeğeri küçük eksenler atılır (ör. 100 eksenden ilk 10'u yeterli, kalan 90'ı atılır); DFT'de sıfıra yakın yüksek frekans katsayıları kullanılmaz.
- Boyut azaltmanın önemi
  - Hesap karmaşıklığı (computational complexity) azalır: eğitim matrisi $N\times d$ ise ($N$ örnek, $d$ öznitelik) ve karmaşıklık $d$'ye bağlıysa (tahtada $O(d^2)$ yazıldı, ekrandan, 00:35:00) $d$'yi azaltmak hesap yükünü azaltır.
  - Dönüşümün asıl yararı verinin daha iyi ayrışabildiği bir uzaya geçmektir.
- Öznitelik seçme (feature selection)
  - Çok sayıda ve birbiriyle ilişkili sütun (öznitelik) varsa bir kısmı seçilir, gerisi atılır.
  - İleri arama (forward search): öznitelikler teker teker eklenir, başarıma bakılır. Geri arama (backward search): öznitelikler teker teker çıkarılır.
  - Bilgi miktarı ve entropiye dayalı ölçütler; genetik algoritma ve sürü (swarm) tabanlı optimizasyonla en iyi alt kümenin aranması.
- Model türleri
  - Eğiticili (supervised), eğiticisiz (unsupervised); bazı kaynaklar pekiştirmeli öğrenmeyi (reinforcement learning) üçüncü sınıf sayar. Topluluk öğrenme (ensemble) ve yarı eğiticili (semi-supervised) gibi karışık yaklaşımlar vardır.
  - Etiket (label) aynı zamanda yer gerçekliği (ground truth) diye anılır. Piksel seviyesinde etiket (hücrelerin 0/1 maskesi) ya da görüntü seviyesinde etiket (görüntü normal, 1., 2. ya da 3. tip hastalık) olabilir.
  - Eğiticisiz yöntemlerde etiket yoktur; verinin dağılımına bakılarak kümeler (cluster) oluşturulur. Eğiticili yöntemdeki gruplara sınıf (class), eğiticisizdekilere küme (cluster) denir.
  - Derin öğrenme (deep learning): öznitelik çıkarma adımını kendi yapısı içinde yapar; çok katmanlı sinir ağlarının artan işlem gücüyle uygulanabilir hâlidir.
- Son işleme (post-processing)
  - Modelin bulamadığı ya da eksik bulduğu yerler düzeltilir: hücre içinde kalan delikler, kopukluklar, yanlışlıkla hücre denen küçük parçalar.
  - Morfolojik işlemler kullanılır: aşındırma (erosion) ile küçük parçalar silinir, genişletme (dilation), açma (opening) ve kapama (closing) ile delikler kapatılır.
- Değerlendirme
  - K katlı çapraz doğrulama (k-fold cross-validation): veri $k$ parçaya bölünür (ör. $k=5$), $k-1$ parçayla eğitilir, kalan parçayla test edilir; test parçası her turda değişir, işlem $k$ kez yapılır, ortalama performans alınır.
  - Ölçütler: genel doğruluk (overall accuracy), F-ölçütü (F-measure), kappa. Etiket yoksa küme içi değişintinin az, kümeler arası uzaklığın çok olması aranır. Bölütlemede kesişim/birleşim (intersection over union, IoU) ve Dice ölçütü.
- Sınıflandırıcılar (kaynak: Robi Polikar, "Pattern Recognition", ekrandan, 00:55:00)
  - Bayes ve naif Bayes: sınıf olasılıklarını kullanır. Slayttaki naif Bayes ayırt edici fonksiyonu: $g_i(\mathbf{x})=P(\omega_i)\prod_{j=1}^{d}P(x^{(j)}\mid\omega_i)$, en büyük $g_i$'yi veren sınıf seçilir.
  - k-NN: yeni örneğe en yakın $k$ eğitim örneği bulunur, çoğunluğun etiketi atanır (slayttaki şekilde $k=11$). Her yeni örnek için bütün eğitim örneklerine uzaklık hesaplamak gerektiğinden işlem yükü yüksektir.
- Yapay sinir ağları (ekrandan, 01:10:00 ve 01:15:00)
  - Nöron modeli: girişler $x_i$ ağırlıklarla $w_i$ çarpılıp toplanır, $x_0=1$ girişinin ağırlığı $w_0$ yanlılık (bias) görevini görür; toplam (net) bir aktivasyon fonksiyonundan $f$ geçer.
  - Aktivasyon fonksiyonları: eşik (threshold) $f(net)=1$ ($net\ge 0$), aksi hâlde $0$ ya da $-1$ (bu durumda düğüme perseptron denir); doğrusal $f(net)=net$; lojistik (sigmoid); hiperbolik tanjant.
  - Çok katmanlı perseptron (MLP): giriş, gizli ve çıkış katmanı. Ağırlıklar hatanın geriye yayılmasıyla güncellenir; gizli katman sayısı arttıkça geriye yayılım zorlaşır. Öğrenme oranı ve momentum gibi parametreler yerel minimuma düşmeyi önlemeye yardım eder.
  - Radyal tabanlı fonksiyon (RBF) ağları (ekrandan, 01:20:00): gizli katman Gauss çekirdekleri kullanır, $y_j=\varphi(\lVert\mathbf{x}-\mathbf{u}_j\rVert)=e^{-(\lVert\mathbf{x}-\mathbf{u}_j\rVert/\sigma)^2}$; gizli katmana alıcı alan (receptive field) katmanı denir.
  - Derin öğrenme: genelde iki boyutlu girişler; ara katmanlarda konvolüsyonla öznitelik çıkarılır; max pooling ve dropout kullanılır. Mimarilere örnek: AlexNet, GoogLeNet.
- Verinin karar yüzeyine etkisi, SVM, çekirdek, topluluk ve kümeleme
  - Eğitim verisi sınıfları iyi temsil etmezse karar sınırı kayar ve yeni bir örnek yanlış sınıfa atanabilir (ekrandan, 01:25:00). Aktif öğrenme (active learning) temsil gücü yüksek örnekleri seçerek karar yüzeyini iyileştirmeye çalışır.
  - Destek vektör makineleri (SVM): sınıflar arasındaki marjı en büyük yapan karar yüzeyini bulur (ekrandan, 01:30:00). Çekirdek (kernel) yöntemleri veriyi daha yüksek boyutlu bir uzaya taşıyarak iç içe geçmiş sınıfları ayrılabilir yapar.
  - Topluluk öğrenme (ensemble learning): birçok sınıflandırıcının kararı birleştirilir; hoca bunu bir vakayı birlikte değerlendiren doktorlar kuruluna benzetti.
  - Kümeleme: k-means (rastgele merkezlerle başlar, merkezler (centroid) kümenin ortasına çekilir; başlangıç merkezlerinin seçimi önemlidir), bulanık c-means (fuzzy c-means), yoğunluk tabanlı ve optimizasyon tabanlı kümeleme.
- Örnek proje: histopatolojik görüntüde hücre bölütleme
  - Veri: 58 görüntülük meme kanseri (breast cancer) histopatoloji veri seti; yer gerçekliği görüntünün yalnız bir bölgesinde işaretli. Önce bu bölge hem görüntüden hem yer gerçekliğinden kesilir (crop).
  - Zorluk: üst üste binen hücreler, aynı renkte bitişik hücreler, iç kısmı arka planla aynı renkte olan (epitel gibi) hücreler; yalnız RGB'ye bakan bölütleme delikli sonuç verir.
  - Eğiticisiz yaklaşım: RGB değerleriyle k-means, $k=4$ (beyaz, pembe, koyu, daha koyu tonlar). Etiket kullanılmadığından delikler kalır, son işleme gerekir.
  - Eğiticili yaklaşım: yer gerçekliğine göre hücre piksellerine 1, arka plan piksellerine 0 etiketi verilir; SVM ya da Random Forest ile piksel piksel sınıflandırma yapılır.
  - Uzamsal bilgi: tek pikselin RGB değeri yetersizdir; pikselin çevresinden 3×3, 5×5, 7×7, 9×9 pencereler alınır ve GLCM (gri seviye eş oluşum matrisi), SIFT, SURF, HOG <!-- BELİRSİZ: altyazıda "Fog" (01:51:28), HOG olduğu düşünüldü --> ile basıklık (kurtosis), çarpıklık (skewness), varyans gibi istatistikler öznitelik olarak çıkarılır (ekrandan, 02:10:00).
  - MATLAB'de veri yapısı (ekrandan, 02:15:00): `traintestMat` 1×58 hücre dizisi; her elemanda `IorgCrop` (205×227×3 uint8), `ILabCrop`, `GtCrop` (205×227 uint8), `xData` (46535×3), `xLabel` (46535×1), `minX=138`, `maxX=342`, `minY=156`, `maxY=382`. $205\times 227=46535$, yani kesilen bölgenin her pikseli bir örnektir.
  - SVM uygulaması (libsvm, ekrandan, 02:20:00 ve 02:25:00): `traindata.X` 5000×6, `traindata.y` 5000×1; `svmtrain(traindata.y, traindata.X, '-c 1 -g 0.01')`. 2000 örneklik testte doğruluk %91,40; `cerror` ile hata 0,0860, `1-cerror(YhatSVM,testdata.y)` = 0,9140, yani 2000 örneğin 1828'i doğru.
- Proje geliştirme ve akademik yazım
  - Adımlar (ekrandan, 01:55:00): 1) veri seti iyice anlaşılacak; 2) problem tanımı oturtulacak (sınıflandırma, bölütleme, tespit); 3) sağlam literatür araştırması (Google, Google Scholar, ResearchGate, GitHub).
  - Bildiri Overleaf'te LaTeX ile, IEEE konferans şablonuyla yazılır. Kaynaklar `references.bib` dosyasına BibTeX biçiminde eklenir, metinde `\cite{anahtar}` ile anılır; BibTeX kaydı Google Scholar'daki "alıntı yap" bölümünden alınabilir (ekrandan, 02:30:00).
  - Anılan veri setleri: TIA Lab veri setleri (CRC doku fenotipleme, PanNuke, kanser derecelendirme), Kaggle Histopathologic Cancer Detection, ISIC deri lezyonu (melanom), BreakHis, serviks için Herlev, çekirdek ve epitel bölütleme, tübül bölütleme, lenfoma alt tip sınıflandırma, mitoz tespiti veri setleri.
  - Anılan yöntem alanları (ekrandan, 02:45:00): topluluk öğrenme, transfer öğrenme, aktif öğrenme, manifold öğrenme, seyrek (sparse) öğrenme, sözlük tabanlı öğrenme, işbirlikçi (collaborative) öğrenme, uzamsal bilgi çıkarma, optimizasyon tabanlı bölütleme, derin öğrenmeyle sınıflandırma ve bölütleme, çizge (graph) tabanlı yöntemler ve Graph CNN.

## Hocanın Özellikle Vurguladığı Kısımlar

- Eğitime uygulanan ön işleme teste de uygulanmalı
  - Model katsayıları ve karar yüzeyleri eğitim verisinin özelliklerine göre oluşur. Eğitimde medyan süzgeç ya da normalizasyon uygulanıp testte uygulanmazsa test örneği öznitelik uzayında başka bir yere düşer ve yanlış sınıfa atanabilir.
- Dönüşüm tabanlı öznitelikler insanın yapamadığı bir şeydir
  - Uzman gözü zaman domeninde bakar (yoğunlaşma, mitotik hücre, açı). PCA, DFT, dalgacık ve ICA ise veriyi farklı bir uzaya taşır; asıl kazanç verinin daha iyi ayrışmasıdır, boyut azaltma bunun yan ürünüdür.
- Gözle kolay görünen işin altında hesap zorluğu olabilir
  - k-NN'de en yakın komşuyu şekilde görmek kolaydır, ama bin örnekli bir veri setinde her yeni örnek için bütün uzaklıkları hesaplamak gerekir.
- Eğitim verisinin kalitesi karar sınırını belirler
  - Tek tip veri basit, çeşitli veri karmaşık karar yüzeyi üretir. K katlı çapraz doğrulama bu bağımlılığı ortalama alarak azaltır.
- Yalnız piksel rengi bölütleme için yetmez
  - Hücrenin içi arka planla aynı renkte olabilir. Pikselin çevresindeki doku (uzamsal öznitelik) karara katılmalıdır.
- Araştırma projesi adım adım ilerler
  - Önce veri seti ve problem anlaşılır, sonra literatür taranır; okunan çalışmalar (hangi veri seti, hangi yöntem) not edilir ve daha sonra bildirinin giriş bölümüne dönüşür.

## Kısa Tekrar Notları

- Süreç: elde etme → ham veri → ön işleme → bölme → öznitelik çıkarma/seçme → model → son işleme → değerlendirme.
- Test verisine eğitimdeki ön işlemenin aynısı uygulanır.
- Öznitelik çıkarma: zaman domeni ölçümleri (P, QRS, ST) ya da dönüşüm (PCA, DFT, wavelet, ICA).
- Boyut azaltma hesap yükünü düşürür; öznitelik seçme ilişkili sütunları atar (ileri/geri arama, entropi, GA, sürü).
- Eğiticili: etiket = yer gerçekliği; piksel ya da görüntü seviyesinde. Eğiticisiz: kümeler.
- Son işleme: erosion, dilation, opening, closing ile delik ve küçük parçaların temizlenmesi.
- Değerlendirme: k-fold, overall accuracy, F-measure, kappa, IoU, Dice; kümelemede küme içi az, kümeler arası çok değişinti.
- Naif Bayes: $g_i(\mathbf{x})=P(\omega_i)\prod_j P(x^{(j)}\mid\omega_i)$. k-NN: $k$ komşunun çoğunluğu.
- Nöron: $net=\sum_i w_i x_i$ ($x_0=1$ bias), $y=f(net)$; eşik, doğrusal, sigmoid, tanh.
- RBF: Gauss çekirdekli gizli katman. CNN: konvolüsyon, max pooling, dropout.
- SVM: en büyük marj; kernel: yüksek boyuta taşıma. Ensemble: sınıflandırıcılar kurulu.
- Hücre bölütleme örneği: k-means ($k=4$) ya da SVM; 3×3...9×9 pencere, GLCM, SIFT, SURF, istatistikler; test doğruluğu %91,40 (1828/2000).

## Detaylı Açıklamalar

- Biyomedikal bir makine öğrenmesi probleminde ilk iş ham veriyi elde etmek ve onu modele uygun hâle getirmektir. Ham veri sensörden geldiği gibidir: gürültülü, farklı aralıklarda, bazen aykırı değerli. Ön işlemede işaret ya da görüntü süzgeçten geçirilir, normalizasyon yapılır, gerekirse histogram eşitlenir. Hocanın özellikle üzerinde durduğu nokta, ön işlemenin eğitim ve test için aynı olmasıdır. Örneğin eğitim görüntülerine medyan süzgeç uygulanmış, test görüntüsüne uygulanmamışsa model gürültüsüz veriyle eğitildiği hâlde gürültülü bir veriyle karşılaşır; tahtadaki çizimde normalizasyonsuz bir test örneğinin karar sınırının öbür tarafına düşüp yanlış sınıfa atanabileceği gösterildi.

- Öznitelik çıkarmanın ilk yorumu, verinin "görünen" özelliklerini ölçmektir. EKG'de P dalgasının, QRS kompleksinin, ST aralığının uzunlukları ve eğimleri bir vektöre yazılır. Bu, bir doktorun tecrübesiyle baktığı özellikleri sayıya dökmektir. İkinci yorum dönüşüm tabanlıdır: PCA veriyi en iyi ayrışacağı yeni eksenlere döndürür, DFT frekans katsayılarını verir, dalgacık dönüşümü farklı ölçeklerdeki yaklaşık ve ayrıntı katsayılarını verir. Bu katsayılar arka arkaya dizilerek öznitelik vektörü yapılır. Dönüşümler aynı zamanda boyut azaltmaya imkân verir: PCA'da özdeğeri büyük ilk birkaç eksen tutulur, DFT'de sıfıra yakın yüksek frekans katsayıları atılır.

- Öznitelik seçme, elde hazır $N\times d$ bir matris varken bazı sütunları seçip bazılarını atmaktır. Birbiriyle çok ilişkili iki öznitelikten birini kullanmak yeterlidir. En basit yollar ileri arama (öznitelikleri teker teker ekleyip başarıma bakmak) ve geri aramadır (teker teker çıkarmak). Daha gelişmiş yollar özniteliklerin taşıdığı bilgi miktarını ya da entropisini ölçer veya genetik algoritma, sürü optimizasyonu gibi yöntemlerle en iyi alt kümeyi arar.

- Eğiticili öğrenmede eğitim matrisinin yanında etiketler (yer gerçekliği) vardır. Hücre görüntüsünde bu, hücre olan piksellere 1, olmayanlara 0 diyen bir maske olabilir; ya da her görüntüye tek bir etiket (normal, 1., 2., 3. tip hastalık) verilebilir. Model kurmak, etiketler yardımıyla öznitelik uzayında sınıfları ayıran karar yüzeylerini bulmaktır; yeni bir test örneği bu yüzeylere göre bir sınıfa atanır. Eğiticisiz öğrenmede etiket yoktur, yalnız verinin uzaydaki dağılımına bakılarak kümeler kurulur. Derin öğrenme ise "öznitelik çıkarmayı bana bırak" der; özniteliği kendi katmanlarında öğrenir.

- Model sonucu her zaman temiz değildir. Hücre bölütlemede hücrenin içinde siyah noktalar (delikler), sınırda kopukluklar ya da arka planda tek tük "hücre" denmiş küçük parçalar kalabilir. Son işlemede morfolojik işlemler kullanılır: aşındırma etrafı boş küçük parçaları siler, ardından genişletme, açma ve kapama ile delikler kapatılır.

- Değerlendirmede test etiketleri verildiyse doğrudan karşılaştırma yapılır. Verilmediyse k katlı çapraz doğrulama kullanılır: veri $k$ parçaya bölünür, her turda bir parça test, kalanı eğitim olur ve test parçası her turda yer değiştirir. Böylece model farklı eğitim ve test kümeleriyle denenir, ortalama performans bulunur. Ölçüt olarak genel doğruluk, F-ölçütü ve kappa; bölütlemede IoU ve Dice; kümelemede ise küme içi dağılımın küçük, kümeler arası uzaklığın büyük olması kullanılır.

- Sinir ağlarında temel birim nörondur. Polikar'ın makalesindeki modelde (ekrandan, 01:15:00) $d$ boyutlu öznitelik vektörü için $d+1$ giriş vardır; $x_0=1$ girişinin ağırlığı $w_0$ yanlılıktır. Ağırlıklı toplam $net$ bir aktivasyon fonksiyonundan geçer. Eşik fonksiyonu $net\ge 0$ için 1, aksi hâlde 0 (ya da $-1$) verir ve bu durumda düğüm perseptron adını alır. Doğrusal fonksiyon $f(net)=net$'tir; sigmoid ve tanh doğrusal olmayan karar yüzeyleri için kullanılır. Nöronlar katmanlar hâlinde dizildiğinde MLP oluşur. RBF ağlarında gizli katman Gauss çekirdekleriyle çalışır; çekirdek merkezleri $\mathbf{u}_j$ ve yayılımı $\sigma$ ile tanımlanır. Derin öğrenmede ara katmanlar konvolüsyon süzgeçleriyle öznitelik çıkarır; max pooling ve dropout ara katmanlarda kullanılır.

- SVM, sınıfların sınırındaki örnekleri (destek vektörleri) bulup aradaki marjı en büyük yapan yüzeyi çizer. İç içe geçmiş iki sınıf, düzlemden bakınca ayrılamaz görünse de bir boyut eklenip daha yüksek boyutlu bir uzaya taşındığında bir düzlemle ayrılabilir; çekirdekleştirme (kernelization) budur. Hoca, çekirdek yöntemlerinin derin öğrenmeden önce en aktif çalışma alanlarından biri olduğunu, hâlâ temel sınıflandırıcılardan sayıldığını söyledi.

- Örnek projede amaç, 58 görüntülük meme kanseri histopatoloji veri setinde hücreleri arka plandan ayırmaktı. Yer gerçekliği görüntünün yalnız bir bölgesinde olduğundan önce bu bölge kesildi. Eğiticisiz yolda RGB değerleri alt alta dizilip $k=4$ ile k-means uygulandı; ama hücre içi ile arka plan aynı renkte olduğundan sonuç delikli çıktı. Eğiticili yolda yer gerçekliğine göre 1 ve 0 etiketli pikseller seçildi ve SVM ya da Random Forest ile her piksel sınıflandırıldı. Literatür, yalnız RGB'nin yetmediğini, pikselin çevresindeki dokunun da kullanılması gerektiğini gösteriyordu. Bu yüzden her pikselin çevresinden 3×3 ile 9×9 arası pencereler alındı ve GLCM, SIFT, SURF ve istatistiksel değerler çıkarıldı. MATLAB'deki `traintestMat` yapısında kesilen bölge 205×227 piksel, dolayısıyla 46535 örnekti. 5000 örnek ve 6 öznitelikle eğitilen libsvm modeli 2000 test örneğinde %91,40 doğruluk verdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
