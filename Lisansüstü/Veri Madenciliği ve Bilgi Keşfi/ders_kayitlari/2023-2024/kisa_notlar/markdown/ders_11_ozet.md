# Ders 11 Çalışma Özeti

## Genel Konular

- Dersin yapısı: öğrenci makale sunumları
  - Bu derste öğrenciler seçtikleri bir makaleyi (ya da bir derleme çalışmasını) sundu. Her sunumda önce makalenin konusu ve önemi, sonra veri seti, ön işleme, kullanılan yöntemler, deney sonuçları ve sınırlılıklar anlatıldı.
  - Toplam sekiz sunum dinlendi. Konular uzaktan algılama, e-ticaret dolandırıcılığı, görüntüden vücut kitle indeksi tahmini, futbol maç sonucu tahmini, biyolojik dizi hizalama, medikal görüntülerde derin öğrenme, kalp hastalığı teşhisi ve EEG ile zihinsel yorgunluk tanıma idi.
  - Sunumların ortak noktası veri madenciliği sürecinin adımlarıydı: veri toplama, temizleme, eksik ve aykırı değer işlemleri, öznitelik seçimi/çıkarımı, dengesiz veri ile başa çıkma, model seçimi, çapraz doğrulama ve değerlendirme ölçütleri.
- Sunum 1: Sentinel-2 görüntülerinde bulut giderme (DSen2-CR)
  - Optik (multispektral) uydu görüntüleri bulut ve bulut gölgesi yüzünden bilgi kaybeder. Sentinel-2'de 13 spektral bant vardır (görünür, yakın kızılötesi, kısa dalga kızılötesi).
  - SAR (sentetik açıklıklı radar, Sentinel-1) görüntüleri VV ve VH polarizasyonludur ve buluttan etkilenmez; ama özellikle şehir alanlarında optik görüntüdeki ayrıntıyı vermez.
  - Veri seti 169 bölgeden alınmış, $256 \times 256$ piksellik 157.521 örnek içerir. Bölgelerin 149'u eğitim, 10'u doğrulama, 10'u test için ayrılmıştır. Bölge bazlı bölme, yer şekli ve bulut yapısının bölgeye bağlı olması yüzünden mantıklıdır.
  - Model, ResNet yaklaşımlı DSen2-CR'dir: 2 kanallı SAR ve 13 kanallı optik girdi birleştirilir (Concat $(15,m,m)$), Conv, ReLU ve $B$ kez tekrarlanan ResBlock katmanlarından geçer, son Conv $(13,m,m)$ çıktısı uzun bir atlama bağlantısıyla optik girdiye eklenir (ekrandan, 00:20:00).
  - Kayıp fonksiyonu CARL (cloud-adaptive regularized loss): ortalama mutlak hataya ek olarak bulut maskesi kullanılır. Bulutlu ve gölgeli bölgelerde tahmin hedef görüntüye, temiz bölgelerde tahmin girdi görüntüsüne yaklaştırılır.
  - Ön işleme ve parametreler (ekrandan, 00:25:00): Sentinel-2 bantları $[0, 10000]$ aralığına, Sentinel-1 VV ve VH $[-25, 0]$ ve $[-32{,}5, 0]$ aralıklarına kırpılır. Sentinel-2 pikselleri 2000'e bölünür, Sentinel-1 değerleri pozitif alana kaydırılıp $[0, 2]$ aralığına getirilir. Rastgele döndürme ve yatay-dikey yansıtma ile veri artırılır. Ağırlıklar He uniform dağılımıyla başlatılır, Nesterov momentumlu Adam kullanılır, öğrenme oranı $7 \times 10^{-5}$, batch boyutu 16'dır.
  - Sonuçlar: model büyük bulutların altını iyi kurar, şehir alanlarında zorlanır. SAR kullanılmadığında temiz bölgeler daha iyi korunur ama bulutlu bölgelerin yeniden kurulumu kötüleşir. pix2pix modeline göre bütün kayıp ölçütlerinde iyileşme raporlanmıştır (ekrandan, 00:30:00).
- Sunum 2: Çevrim içi pazar yerlerinde organize perakende suçu ve dolandırıcı tespiti
  - Literatürde organize suç odaklı çalışma az, kamuya açık veri de sınırlıdır. Perakendeciler 2020'de her 1 milyar dolarlık satışta ortalama 719.548 dolar kaybetmiştir; bu değer 2019'da 703.320, 2015'te 453.940 dolardır (ekrandan, 00:35:00).
  - Veri uzmanlar tarafından etiketlenmiş ve dengesizdir. Sayısal, kategorik ve metin öznitelikler vardır; metin öznitelikleri çıkarılmıştır.
  - Deney 1'de dengeleme yapılmadan 7 sınıflandırıcı $k$ katlı çapraz doğrulamayla denenir. Deney 2'de sınıflandırıcıların birleşimleri denenir. Deney 3'te dengeleme ve ön işleme eklenir.
  - Veri, büyük bir perakende platformundaki 3606 ABD'li satıcının son 90 gündeki ilanlarından gelir. Bir sütunda eksik değer oranı %20'nin altındaysa o örnekler, üstündeyse o sütun atılır.
  - Ön işleme (ekrandan, 00:40:00): veri temizleme (tekrarlanan ilanların silinmesi, eksik değer işlemi, aykırı değer işlemi) ve öznitelik mühendisliği (one-hot kodlama, yeni öznitelik üretme, normalleştirme ve ölçekleme). Aykırı değer için 3 standart sapma ölçütü kullanılır.
  - Dengesiz veri için azınlık sınıfı SMOTE ile çoğaltılır; kategorik öznitelikler olduğu için SMOTE-NC tercih edilir. Ardından Tomek bağları ve Edited Nearest Neighbors ile alt örnekleme yapılır.
  - $k = 5$ katlı çapraz doğrulama, %80 eğitim / %20 doğrulama ve ayrı bir test kümesi kullanılır. Dengelemeden önce doğrulama sonuçları iyi görünse de gerçek test ortamında başarı düşer. En iyi model Balanced Random Forest'tır; dengesiz veride doğruluk yanıltıcı olduğu için ROC eğrisi de hesaplanır. SHAP ile en önemli 10 öznitelik belirlenir.
- Sunum 3: Fotoğraflardan vücut kitle indeksi (VKİ) tahmini
  - VKİ, kilonun boyun karesine bölünmesiyle bulunur. Toplu ölçüm pahalı ve zaman alıcı olduğu için fotoğraftan tahmin önerilir.
  - Veri seti 161 kişiliktir ve küçüktür. Görüntüler siluete dönüştürülür. Aykırı değerler bilerek atılmaz, çünkü amaç zaten uç VKİ değerlerini görmektir. Veri %60 eğitim, %20 doğrulama, %20 test olarak bölünür.
  - Gabor filtresi ve yönlü gradyan histogramı (HOG) öznitelikleri üç regresyon modeliyle (RF, XGB, SVM) birleştirilerek altı varyasyon kurulur ve CNN ile karşılaştırılır. CNN, VGG tarzı bir mimaridir (ekrandan, 00:55:00).
  - 5 ve 10 katlı çapraz doğrulamada ortalama hata CNN için 0,017 ve 0,021'dir; en yakın klasik model Gabor-SVM'in 5 katlı hatası 0,20'dir (ekrandan, 00:55:00).
  - CNN'in başarımı (ekrandan, 01:00:00): doğrulama kaybı ortalama 0,124 (en iyi 0,0625), Pearson korelasyonu 0,928 (0,976), MAE 1,66 (1,20), RMSE 2,16 (1,52).
- Sunum 4: Katar Yıldızlar Ligi'nde maç sonucu tahmini ve kritik oyuncu metrikleri
  - Veri 1121 maç, 6-7 sezon ve 2419 oyuncu içerir. Kaleci metrikleri çıkarılır. Defans, orta saha ve forvet için 22'şer metrik (66) ile 3 takım özniteliği birlikte 69 öznitelik oluşturur.
  - Öznitelik seçimi için Anderson-Darling, Student t ve Mann-Whitney testleri kullanılır; 69 öznitelikten 47'si anlamlı bulunur (ekrandan, 01:20:00).
  - KNN, Random Forest, XGBoost, karar ağacı ve lojistik regresyon denenir. En iyi model %80 doğruluk ve 0,91 AUC ile lojistik regresyondur; problemin ikili (kazanma/kaybetme) olması bunu açıklar.
  - Geçmiş sezon sayısı 1'den 6'ya artırıldığında doğruluk sırasıyla yaklaşık 71, 73, 76, 76, 79, 79 olur; son 5 sezon en uygun geçmiş uzunluğu olarak seçilir.
  - Sınırlılıklar (ekrandan, 01:25:00): yalnız bir ligin verisi, deplasman kavramının küçük ülkede anlamsızlaşması ve beraberliklerin tahmin edilmemesi.
- Sunum 5: Makine öğrenmesiyle biyolojik dizi hizalama
  - İkili dizi hizalamada eşleşme (match), eşleşmeme (mismatch) ve boşluk (gap) işlemleri vardır. Needleman-Wunsch dinamik programlama algoritması en iyi hizalamayı verir ama dizi uzadıkça bellek ve süre gereksinimi artar.
  - Önerilen paralel akışta girdi dizileri doğrudan bir ML modeline verilir, çıkan etiket çözülerek sonuç üretilir. Klasik NW akışı ise matris başlatma, skor matrisini doldurma, geri izleme ve sonuç üretme adımlarından oluşur (ekrandan, 01:35:00).
  - Nükleotitler ikilik ya da onluk tabanda kodlanır. Hizalama tek satırda gösterilir: dikey çizgi eşleşme, iki nokta eşleşmeme, alt çizgi boşluk. Her hizalama deseni bir sınıftır; 10'dan az örneği olan sınıflar atılır.
  - Veri temizleme ve öznitelik seçimi önerilmez, çünkü her nükleotit konumu önemli bir özniteliktir (ekrandan, 01:40:00). 15 model denenir; en iyisi çok katmanlı algılayıcı (MLP), en iyi optimize edici Adam'dır. Aşırı öğrenmeye karşı L2 düzenlileştirme katsayısı ayarlanır.
- Sunum 6: Medikal görüntülerde derin öğrenme (derleme)
  - CNN katmanları: evrişim (filtreyle nokta çarpımı, öznitelik haritası), ReLU (negatifleri sıfırlar, kaybolan gradyanı azaltır), havuzlama (boyutu ve parametre sayısını azaltır, en yaygını max pooling), tam bağlantılı katman.
  - Etiketli medikal veri az olduğu için transfer öğrenme (ince ayar) yaygındır. Denetimsiz yöntemler: otokodlayıcı, RBM ve GAN (ekrandan, 01:50:00).
  - Uygulamalar: sınıflandırma (göğüs röntgeninde nodül, 121 katmanlı DenseNet tabanlı CheXNet ile 14 hastalık), lokalizasyon, tespit, segmentasyon (özellikle beyin MR) ve kayıt (registration).
- Sunum 7: Kalp hastalığı teşhisinde makine öğrenmesi
  - 5 veri setinin birleşiminden oluşan 918 kayıtlık bir veri seti kullanılır (725 erkek, 193 kadın; 508 hasta, 410 sağlıklı). Eksik kolesterol değerleri grup ortalamalarıyla doldurulur. Veri %70 eğitim, %30 test olarak ayrılır.
  - Korelasyon matrisinde kalp hastalığıyla en güçlü pozitif ilişki Oldpeak (0,4), en güçlü negatif ilişki MaxHR (-0,4) ile görülür; kolesterolle ilişki bu veride negatiftir (-0,23) (ekrandan, 02:05:00).
  - Doğrulama tablosunda en iyi sonuç ayarlanmış CatBoost'tadır: doğruluk 0,9094, kesinlik 0,9317, duyarlılık 0,9146, F1 0,9231; en düşükler XGBoost ve AdaBoost'tur (ekrandan, 02:10:00).
  - Sunumu yapan öğrenci aynı veri setinin bir parçasıyla tek gizli katmanlı küçük bir sinir ağı da denedi (ekrandan, 02:15:00).
- Sunum 8: EEG tabanlı zihinsel yorgunluk tanıma için denekler arası transfer öğrenme
  - EEG frekans bantları: delta (0-4 Hz), teta (4-8 Hz), alfa, beta, gama (30 Hz üstü). Çok kanal hesaplama yükü ve aşırı öğrenme riski getirdiği için kanal azaltma (filtre, sarmalayıcı, gömülü, hibrit) yapılır.
  - Veri: sürüş simülatöründe 90 dakikalık şerit takip görevi, 27 kişi, 62 oturum, 32 kanallı EEG.
  - Etiketleme (ekrandan, 02:30:00): şeritten sapmadan önceki 3 saniyelik epoklar alınır. Uyarı RT'si tüm yerel RT'lerin 5. yüzdelik dilimidir. Yerel ve global RT, uyarı RT'sinin 1,5 katından küçükse epok "yorgun değil", 2,5 katından büyükse "yorgun" etiketi alır. 11 katılımcıdan 837 + 837 epok seçilir.
  - FFT ile spektral bant öznitelikleri çıkarılır, Random Forest öznitelik önemiyle en iyi kanal (oksipital) seçilir. Transfer öğrenme için TCA ve MIDA kullanılır; bir denek test, kalan 10 denek eğitim olacak şekilde 11 tur yapılır.
  - TCA ortalaması: doğruluk %68,00, duyarlılık %68,20, özgüllük %70,57. MIDA ortalaması: %67,89, %64,05, %74,57 (ekrandan, 02:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Konunun neden seçildiği ve uygulama alanı
  - Hoca her sunumdan önce makalenin neden seçildiğinin açıklanmasını istedi ve sunumlardan sonra çalışmanın gerçek hayatta nerede kullanılabileceğini sordu (ör. VKİ tahmini için spor salonları ve diyetisyenler).
- Grafik eksenlerinin doğru okunması
  - VKİ sunumundaki sapma grafiğinde eksen değerlerinin $\pm 2$ mi $\pm 0{,}2$ mi olduğunu sordu. Sapmaların yaklaşık $-2$ ile $2$ arasında olduğu, ortalama VKİ 25-30 civarında olduğu için bunun yaklaşık %10'luk bir hata anlamına geldiği tartışıldı.
- Neyin tahmin edildiğinin net olması
  - Futbol çalışmasında modelin skoru mu, skor farkını mı, yoksa yalnız kazanma/kaybetmeyi mi tahmin ettiğini sordu. Cevap: oyuncu bazlı maç istatistiklerinden yalnız kazanma/kaybetme tahmin ediliyor.
- Test verisinin tamamen dışarıda tutulması
  - EEG çalışmasında bir deneğin verisinin tümüyle test için ayrılıp eğitimin diğer deneklerle yapılmasının doğru bir yaklaşım olduğunu söyledi.
- Veriye dokunmak
  - Makaledeki veri setiyle kendi küçük denemesini yapan sunum için, örnek sayısı az olsa da yöntemi uygulamalı görmenin değerli olduğunu belirtti.
- Sağlık alanı
  - Sağlık alanında makine öğrenmesiyle yapılacak çok iş olduğunu ve bu alanların gerçek hayatta karşılığı olduğunu vurguladı.

## Kısa Tekrar Notları

- Uzaktan algılamada veri bölgelere göre bölünür; aynı bölgenin hem eğitimde hem testte olması başarıyı olduğundan iyi gösterir.
- DSen2-CR: SAR + optik girdi, ResBlock'lar ve girdiye eklenen uzun atlama bağlantısı; CARL kaybı temiz bölgeleri korur, bulutlu bölgelere odaklanır.
- Dengesiz veri: SMOTE / SMOTE-NC ile çoğaltma, Tomek bağları ve ENN ile alt örnekleme; değerlendirmede doğruluk yerine ROC/AUC, F1, duyarlılık ve kesinlik.
- Eksik değer kuralı örneği: sütunda %20'den az eksik varsa satırı, fazla varsa sütunu at.
- Aykırı değer her zaman atılmaz: amaç uç değerleri yakalamaksa (VKİ çalışması) korunur.
- Öznitelik seçimi için istatistiksel testler: Anderson-Darling, Student t, Mann-Whitney.
- Basit bir referans model (ör. "ilk 6 takım kazanır") yüksek doğruluk verebilir; bir modelin %80 doğruluğu böyle bir tabana göre yorumlanmalıdır.
- Dinamik programlama en iyi hizalamayı verir ama bellek/süre maliyeti yüksektir; ML yaklaşımı hız için önerilir.
- Kalp hastalığı verisinde en iyi model ayarlanmış CatBoost (F1 0,9231).
- Denekler arası transfer öğrenme (TCA, MIDA) kalibrasyon gerektirmeyen EEG modelleri sağlar; değerlendirme bir-denek-dışarıda yapılır.

## Detaylı Açıklamalar

- Bulut giderme çalışmasında temel fikir, buluttan etkilenmeyen SAR görüntüsünü optik görüntüye yardımcı bilgi olarak vermektir. İki görüntü kanal ekseninde birleştirildikten sonra ağ, girdi optik görüntüye eklenecek bir "düzeltme" (artık, residual) öğrenir. Bu yüzden bulutsuz bölgeler neredeyse değişmeden çıktıya taşınır. CARL kaybı bunu destekler: bulut maskesinin olduğu yerde hata hedef görüntüye göre, maskenin olmadığı yerde girdiye göre hesaplanır. Değerlendirmede üç ölçü kullanılmıştır: target (çıktı ile hedef görüntü arasındaki hata), repro (bulutsuz kısımların ne kadar bozulduğu) ve recon (bulutlu ve gölgeli bölgelerdeki yeniden kurma hatası).
- Dolandırıcılık çalışması, dengesiz verinin değerlendirmeyi nasıl yanıltabileceğini gösterir. Dengeleme yapılmadan eğitilen modeller doğrulamada iyi görünmüş, ama örneklem dışı gerçek testte başarıları düşmüştür. Dengeleme için önce azınlık sınıfında Öklid uzaklığına dayalı sentetik örnekler üretilmiş (SMOTE; kategorik öznitelikler için SMOTE-NC), sonra sınıflar arasındaki sınırı netleştirmek için sınırdaki çoğunluk örnekleri Tomek bağları ve ENN ile silinmiştir. Model açıklanabilirliği için oyun teorisinden gelen SHAP değerleri kullanılarak her özniteliğin tahmine katkısı ölçülmüştür. Yazarlar, ileride metin ve görsel verilerin eklenmesini, uzman etiketine bağımlılığın azaltılmasını ve dolandırıcılar da yöntem değiştirdiği için modellerin sürekli güncellenmesini önermiştir.
- VKİ çalışmasında küçük veri seti birkaç tasarım kararını belirlemiştir: aykırı değerler atılmamış, veri artırma her iterasyonda uygulanmış ve hiperparametreler GridSearch ile seçilmiştir (öğrenme oranı 0,01, azalma $1 \times 10^{-5}$, Adam) (ekrandan, 00:55:00). Eğitimde 80'lik batch, epok başına eğitim kümesinin 0,25 katı kadar adım ve en fazla 200 epok kullanılmış, erken durdurma devreye girmiştir. Sonuçlar bir sapma grafiği (tahmin ile gerçek değer farkı) ve regresyon grafiğiyle incelenmiştir. Regresyon grafiğinde ideal durumu gösteren özdeşlik doğrusu ile her iki eksende de hata olduğunu kabul eden Deming regresyon doğrusu birbirine yakındır. VKİ sınıfları (ekrandan, 01:00:00): $<18{,}5$ zayıf, $18{,}5$-$25$ normal, $25$-$30$ fazla kilolu, $30$-$35$ 1. sınıf obez, $35$-$40$ 2. sınıf obez, $\ge 40$ 3. sınıf obez.
- Futbol çalışmasında forvetler için isabetli şut, başarılı pas ve yüksek hızda koşulan mesafe; orta saha için başarılı pas, başarılı uzun pas ve yüksek hızda koşulan mesafe; defans için başarılı pas, yüksek hızda koşulan mesafe ve başarılı şut bloklama en etkili metrikler bulunmuştur. Sunumu yapan öğrenci, Katar liginde güçlü takımların çok sık kazandığını, bu yüzden "ilk 6 takım kazanır" gibi basit bir kuralın bile yaklaşık %70 doğruluk verdiğini, aynı kuralın Türkiye liginde yaklaşık %60, İngiltere'de yaklaşık %58 verdiğini söyleyerek %80'lik sonucun değerini sorguladı.
- Dizi hizalama çalışmasında ML modelleri, dinamik programlamayla üretilmiş hizalamalardan öğrenir. Sonuçlar 6 veri setinde çapraz doğrulamayla karşılaştırılmış, MLP 3. ve 6. veri setlerinde en iyi sonucu vermiş, birleştirilmiş veri setinde yaklaşık %99 başarı bildirilmiştir. Sunumu yapan öğrenci, örnek dizilerin kısa olduğunu ve uzun DNA ya da protein dizilerinde yöntemin uygulanabilirliğinin şüpheli olduğunu belirtti.
- Kalp hastalığı çalışmasında hastaların yaş ortalaması 57, sağlıklıların 51'dir. Hastaların yaklaşık %90'ı erkektir; erkeklerin yaklaşık %63'ünde, kadınların yaklaşık %25,9'unda hastalık vardır. Göğüs ağrısı olmayan (asemptomatik) tip, hastalarda en sık görülen tiptir (%77). ROC eğrisinde Gradient Boosting 0,92 ile en yüksek alanı vermiştir. Doğrulama tablosunda ayarlanmamış CatBoost ile ayarlanmış CatBoost arasındaki farkın ne olduğu soruldu; sunucu, farkın ön işleme ve eksik veri doldurma sonrasındaki ayarlamadan geldiğini düşündüğünü, ayrıntıyı bilmediğini söyledi.
- EEG çalışmasında öznitelik vektörü, her epok için FFT ile hesaplanan dört spektral bandın bütün kanallardan birleştirilmesiyle kurulur. TCA kaynak ve hedef alanların öznitelik dağılımlarını yakınlaştırır; MIDA buna ek olarak alanlardan bağımsız bir öznitelik uzayı korumayı hedefler. Tek kanalla (oksipital) yapılan deneylerde ROC eğrileri ideal noktaya daha yakın ve iki yöntem birbiriyle daha tutarlıdır; 30 kanalda MIDA öne çıkar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
