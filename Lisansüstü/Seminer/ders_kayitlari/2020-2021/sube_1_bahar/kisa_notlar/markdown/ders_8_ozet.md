# Ders 8 Çalışma Özeti

## Genel Konular

- Seminer sunumu 1: Yapay sinir ağlarında hata (loss) parametre yüzeylerinin analizi
  - Sinir ağı eğitimi, çok boyutlu ve konveks olmayan (non-convex) bir fonksiyon üzerinde optimizasyon problemi çözmektir. Kullanılan yaygın algoritmalar Gradient Descent, SGD ve Adam'dır (ekrandan, 00:10:00).
  - Yerel minimum ve eyer (saddle) noktalarının sayısı parametre sayısıyla üstel biçimde artar. Hata yüzeyi analizinin amacı eğitim sürecini ve optimizasyon algoritmalarını iyileştirmektir.
  - Gerçek hata yüzeyi çok boyutludur; ancak iki ve üç boyutlu temsilleri çizilebilir.
- Linear path experiment (doğrusal yol deneyi, 2014)
  - Başlangıç parametreleri $\theta_0$ ile eğitim sonunda varılan parametreler $\theta_1$ arasındaki doğru üzerinde kayıp incelenir: $J\big((1-\alpha)\,\theta_0 + \alpha\,\theta_1\big)$, $\alpha \in [0,1]$. <!-- BELİRSİZ: formülün slaytı karelerde görülmedi; altyazıda yalnız J, Q0, Q1 ve 0-1 arasındaki alfa geçiyor, yazılan biçim yöntemin standart gösterimidir. -->
  - Sorulan iki soru: eğitim sırasında model birden fazla yerel minimuma girip çıkıyor mu, eyer noktalarından geçiyor mu ve bu noktalarda hızı değişiyor mu? MNIST üzerindeki deneyde yolun bir anomalinin yanından geçip doğrudan minimuma ulaştığı, yani cevabın deneysel olarak "hayır" olduğu gösterilmiştir.
- Farklı optimizasyon yöntemleri ve batch normalizasyonun etkisi (2016, ekrandan, 00:15:00)
  - Aynı başlangıçtan farklı optimizasyon algoritmalarıyla (Adam, SGD, RMSprop, ADAM&RK2 vb.) eğitilen modeller farklı yerel minimumlara ulaşır; farklı başlangıçlardan aynı algoritmayla da farklı minimumlar bulunur.
  - Batch normalizasyon yapılmayan modellerde başarı başlangıç noktasına daha bağımlıdır. BN ile daha keskin unimodal sıçramalar, BN olmadan unimodal olmayan tümsek yapılar görülür.
- Mode connectivity ve Fast Geometric Ensembling (2018)
  - Bulunan yerel minimumlar arasında, aynı doğruluk düzeyini koruyan yollar aranır (mode connectivity). Yol üzerindeki kayıp SGD ile optimize edilerek doğrusal olmayan yeni yollar keşfedilir.
  - Yol üzerindeki noktalarla kurulan topluluk modeline Fast Geometric Ensembling (FGE) denir. Bireysel model, Snapshot Ensemble ve FGE karşılaştırılmış; FGE daha başarılı bulunmuştur.
  - Batch boyutu, optimizasyon yöntemi, veri çoğullama gibi hiperparametreler değiştiğinde de yolların bulunabildiği, yani yöntemin esnek olduğu gösterilmiştir.
- Mode connecting volumes (2021, ekrandan, 00:20:00)
  - İki minimum arasında birden fazla yol bulunabilir; üç modu ($\theta_0, \theta_1, \theta_2$) birleştirerek bir hacim (simpleks) elde edilir. Bu hacmin içinden alınan her noktanın doğruluğu aynıdır.
- Sunucunun deneysel çalışmaları
  - Lineer interpolasyonla topluluk modeli: DenseNet169, DenseNet201 ve EfficientNet ile farklı başlangıçlardan 5 model eğitilmiş, iki minimum arasındaki doğru 10 parçaya bölünmüştür (ekrandan, 00:25:00). Eğitimden önce ara noktaların kaybı yüksektir (yaklaşık 1,5 ile 3,5 arası); kısa bir eğitimden sonra hepsi yaklaşık 0,5 düzeyine iner. Ortadaki nokta (eyer noktası) daha zor eğitilir.
  - Ara noktalardan kurulan topluluk DenseNet169'da bireysel olarak iyi sonuç vermiş, diğer modellerde vermemiştir. Eyer noktasından ve üç modelin ortasından nokta alma denemeleri de belirgin iyileşme sağlamamıştır.
  - Monte Carlo ile yerel minimum topolojisinin keşfi: minimumdaki parametrelere küçük rastgele gürültü eklenir; yeni nokta eskisinden iyi ya da çok yakınsa ve sabit bir doğruluk eşiğinin üstündeyse kabul edilir. Tek yol yerine her noktadan 5 dallanan ağaç yapısı kullanılmış, sonuçlar t-SNE/PCA ile 2B ve 3B'ye indirgenerek çizilmiştir (ekrandan, 00:30:00).
  - Batch normalizasyonlu modelde minimum çevresi dalgalı (Rastrigin fonksiyonuna benzer), BN'siz modelde daha düzdür (Sphere fonksiyonuna benzer) (ekrandan, 00:35:00). Aynı adım sayısıyla BN'siz modelde 909 nokta bulunurken BN'li modelde 100 dallanmayla ancak 130 nokta bulunabilmiştir.
- Seminer sunumu 2: Tek hücre RNA dizileme (scRNA-seq) veri analizi literatürü
  - RNA dizileme, bir örnekteki mRNA'ların (transkriptom) miktarını gen düzeyinde ölçer. Bulk RNA-seq hücre popülasyonunun ortalama transkript seviyesini verir; single-cell RNA-seq her hücreyi ayrı ölçer (ekrandan, 00:40:00).
  - Sonuç, satırlarında genler, sütunlarında hücreler olan çok büyük bir matristir. Temel amaç hücrelerin hangi popülasyona (bağışıklık hücresi, tümör hücresi vb.) ait olduğunu bulmaktır.
  - Analiz akışı: kalite kontrol, normalizasyon, batch düzeltme, özellik (gen) seçimi, boyut indirgeme, kümeleme/sınıflandırma, küme etiketleme (annotation), ardından trajektori, pathway, marker gen gibi alt analizler.
- İncelenen makaleler
  - Pankreas kanserinde birincil tümör ve metastatik lezyonların tek hücre analizi: denetimsiz kümeleme ve denetimli SuperCT ile hücre tipi belirleme, sağkalım analizi (ekrandan, 00:45:00).
  - Tümör ve kontrol dokularıyla daha büyük bir veri seti: trajektori analizi, Differential Expression Gene (DEG) analizi, heatmap ve violin plot ile marker gen gösterimi, anahtar düzenleyici (key regulator) genler (ekrandan, 00:50:00).
  - Hücre tipi belirlemede 22 yöntemin 27 açık veri setinde karşılaştırılması: F-skoru, etiketlenemeyen hücre oranı ve hesaplama süresi ölçütleri; en iyi sonuç SVM ile alınmıştır (ekrandan, 00:55:00).
  - Pankreas kanseri moleküler alt tipleri: Classical, Quasimesenchymal (QM), Exocrine-like; QM alt tipi yüksek tümör derecesi ve kötü sağkalımla ilişkilidir (ekrandan, 01:00:00).
  - Boyut indirgeme karşılaştırması: UMAP, t-SNE türevlerine göre daha yoğun ve düzgün kümeler vermiş, PCA en başarısız çıkmıştır.
  - Deconvolution: bulk veride tek tek hücreler gruplanamasa da tek hücre referansıyla hücre tipi oranları bulunabilir.
  - Bulk veriyle sigara kullanımı ve pankreas kanseri ilişkisi: DEG, protein-protein etkileşim ağı, hub genler ve ilaç önerisi (ekrandan, 01:05:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Grafikteki her etiketin anlamı dinleyiciye açıklanmalıdır.
  - Hoca "eğitimden önce/sonra ara noktalar" ifadesinin ne demek olduğunu sordu; sunucu bunun lineer yol deneyi ile mode connectivity eğitimi arasındaki fark olduğunu açıkladı.
- Batch normalizasyon kullanılmadığında hesaplama karmaşıklığı artmaz mı sorusu soruldu; sunucu bunun sonuçları etkileyen bir faktör olabileceğini kabul etti.
- Boyut indirgeme yalnız görselleştirme içindir; bütün işlemler yüksek boyutta yapılır.
- Disiplinler arası bir konuda çalışırken ilgili mühendislik ve tıp birimleriyle işbirliği yapmak yararlıdır.

## Kısa Tekrar Notları

- Hata yüzeyinde yerel minimum ve eyer noktası sayısı parametre sayısıyla üstel artar.
- Linear path experiment: $J((1-\alpha)\theta_0 + \alpha\theta_1)$ ile iki nokta arasındaki kayıp çizilir.
- Mode connectivity: minimumlar arasında düşük kayıplı eğri yollar vardır; FGE bu yollardan topluluk kurar.
- Mode connecting volumes: üç ya da daha çok mod arasında düşük kayıplı hacimler (simpleksler) bulunabilir.
- Aynı başlangıçtan farklı optimizasyon algoritmaları farklı minimumlara götürür.
- Batch normalizasyon hata yüzeyinin minimum çevresini daha dalgalı ve keskin yapabilir (sunucunun deneysel gözlemi).
- 2B/3B çizimler (PCA, t-SNE) empiriktir; kesin kanıt değildir.
- scRNA-seq: hücre bazında, bulk: örnek bazında ortalama ölçüm.
- scRNA-seq akışı: QC, normalizasyon, batch düzeltme, özellik seçimi, boyut indirgeme, kümeleme, annotation.
- Hücre tipi belirleme karşılaştırmasında SVM öne çıkmış; boyut indirgemede UMAP öne çıkmıştır.
- Deconvolution bulk veriden hücre tipi oranlarını tahmin eder, ancak tek hücre referansına ihtiyaç duyar.

## Detaylı Açıklamalar

- **Hata yüzeyleri ve eğitim.** Bir sinir ağının parametreleri $\theta$ ile kayıp fonksiyonu $J(\theta)$ arasındaki ilişki yüksek boyutlu bir yüzey oluşturur. Eğitim, rastgele bir başlangıç noktasından bu yüzeyde bir yerel minimuma yakınsamaktır. İlk sunum, bu yüzeyin yapısını anlamaya çalışan literatürü kronolojik sırayla ele aldı. 2014'teki doğrusal yol deneyinde başlangıç ve son parametre arasındaki doğru üzerindeki kayıp $\alpha$ değiştirilerek çizildi; model yolda bir anomaliye uğramadan doğrudan minimuma inmektedir. 2016 çalışması bu deneyi farklı optimizasyon algoritmaları, farklı başlangıç noktaları ve batch normalizasyonlu/normalizasyonsuz modeller için tekrarladı; CIFAR ve MNIST üzerinde VGG, LSTM ve NIN modelleri kullanıldı.
- **Mode connectivity ve FGE.** 2018 çalışmasında, ayrı ayrı bulunan iki minimumun doğrusal yolla birleştirilince arada yüksek kayıplı bir bölge çıktığı, ancak yolun kendisi SGD ile optimize edilirse aynı doğrulukta eğri bir yol bulunabileceği gösterildi. Bu yol üzerindeki noktalardan kurulan topluluk (FGE), aynı epoch bütçesinde bireysel modelden ve Snapshot Ensemble'dan daha iyi sonuç verdi. Daha sonraki bir çalışmada batch boyutu, optimizasyon yöntemi ve veri çoğullama değiştirilerek de yolların bulunabildiği gösterildi. 2021 çalışması ise yolları genelleyerek birden fazla mod arasında düşük kayıplı hacimler (simpleksler) tanımladı; bu hacmin içinden alınan her nokta aynı doğruluktadır (ekrandan, 00:20:00).
- **Ara noktalardan topluluk deneyi.** Sunucu, farklı başlangıçlardan eğitilmiş 5 model arasında doğrusal yolları 10 parçaya bölüp ara noktaları kısa süre (asıl eğitimin onda biri kadar) eğitti. Eğitimden önce ara noktaların kaybı 1,5 ile 3,5 arasında iken eğitimden sonra hepsi yaklaşık 0,5'e indi (ekrandan, 00:25:00). Ortadaki nokta bir eyer noktası olduğundan daha zor eğitildi. Topluluk modellerinde üyeler arasındaki çeşitlilik (varyans) arttıkça başarının artması beklendiği için eyer noktasından ve üç modelin ortasından noktalar da denendi; belirgin bir kazanç elde edilmedi.
- **Monte Carlo ile topoloji keşfi.** Bulunan minimumun parametrelerine küçük rastgele gürültü eklenip yeni noktalar arandı. Tek bir zincir bir yöne kaydığı için her noktadan 5 dallanan bir ağaç yapısı kullanıldı. Yaklaşık 122.570 boyutlu parametre uzayı yalnız çizim için 2B ve 3B'ye indirgendi. İki farklı minimuma yakınsamış modeller için bulunan noktalar t-SNE çiziminde ayrı bölgeler oluşturdu (ekrandan, 00:30:00). Minimumdan bulunan noktalara çizilen doğrusal yolların kayıp grafikleri BN'li modelde dalgalı (Rastrigin benzeri), BN'siz modelde daha düz ve düzenli (Sphere benzeri) çıktı (ekrandan, 00:35:00). Bu, BN'siz modelde aynı adım büyüklüğüyle çok daha fazla nokta bulunabilmesini açıklar.
- **Tek hücre RNA dizileme.** İkinci sunum biyoinformatik bir literatür taramasıydı. scRNA-seq, 2014'ten beri yaygınlaşan ancak maliyetli bir yöntemdir; tek hücre düzeyinde gen ifadesi profili çıkarır ve hastalıklarda rol oynayan hücre gruplarının bulunmasını sağlar. Bilgisayar mühendisliğinin rolü, gen × hücre matrisinin işlenmesindedir: kalite kontrolde doublet (iki hücrenin birleşimini temsil eden aykırı) hücreler ve çok az gen ifade eden hücreler eşik değerlerle elenir, mitokondriyal ve ribozomal genler elenir; farklı zaman ya da teknolojilerden gelen veriler batch düzeltmeyle birleştirilir; ardından gen seçimi, boyut indirgeme, kümeleme ve marker genlerle küme etiketleme yapılır.
- **Makalelerden yöntemler.** Sağkalım analizinde marker genlerin ifade seviyesine göre hastalar yüksek ve düşük iki gruba ayrılır ve aralarındaki fark anlamlılık açısından (genelde $p < 0{,}05$) sınanır. Cox regresyonu bağımsız değişkenlerle ilişkinin incelenmesinde kullanılır. Nearest Template Prediction, ifade matrisini ve kansere ait imza genleri alarak örnekleri denetimli biçimde sınıflar. Normalized Mutual Information kümelerin tutarlılığını ölçen bir metriktir. Hücre tipi belirleme karşılaştırmasında karmaşık ve az popülasyonlu veri setlerinde (Zheng 68K) yöntemlerin düşük, çok popülasyonlu veri setlerinde (TM, AMB92) yüksek performans gösterdiği, 10X teknolojisiyle üretilen verilerin daha kolay sınıflandığı görüldü (ekrandan, 00:55:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
