# Ders 12 Çalışma Özeti

## Genel Konular

- Makine öğrenmesinde yeni problemler
  - Ders, klasik "etiketli eğitim kümesi + test kümesi" kalıbının dışına çıkan güncel araştırma alanlarını tanıttı: aktif öğrenme, yarı eğiticili öğrenme, öğrenmenin transferi, çok görevli eğitim, hiperparametre optimizasyonu, aktif örnekleme, insan-makine işbirliği, az sayıda örnekle eğitim (one-shot, zero-shot), veri zenginleştirme, makine öğrenmesini kandırma, planlı öğrenme ve hayat boyu öğrenme.
  - Bu konuların bir kısmı için MATLAB kodları (ör. `semi_supervised_learning.m`, `multi_task_learning.m`, `active_sampling.m`) ders sayfasında paylaşıldı.
- Aktif öğrenme (active learning)
  - Eğitim örneklerinin özellikleri bellidir, etiketleri başta bilinmez; algoritma etiketini istediği örnekleri kendisi seçer.
  - Amaç veri etiketleme maliyetini azaltmaktır: tüm eğitim kümesi yerine akıllıca seçilmiş bir kısmıyla benzer, kabul edilebilir derecede düşük ya da daha yüksek test başarısı elde etmek.
  - Adımlar (ekrandan, 00:20:00):
    - A: Küçük bir eğitim setiyle (E) başla; eğitim kümesinin az bir kısmının etiketlerini iste.
    - B: Bir model üret; bu modele göre etiketsiz eğitim örneklerine (EE) dair tahminler üret.
    - C: Bu tahminlere göre (tahmin varyasyonuna göre) örneklerden bir kısmını seç, etiketlerini iste; EE'den çıkar, E'ye ekle.
    - B ve C adımlarını tekrar et.
  - Sınıflandırmada tahmin varyasyonu, sınıf olasılıklarının birbirine ne kadar yakın olduğuyla ölçülür. %51/%49 gibi kararsız bir tahmin, modelin karar sınırına yakın bir örneği gösterir.
- Yarı eğiticili öğrenme (semi-supervised learning)
  - Model oluşturulurken etiketli verilerin yanında etiketsiz veriler de kullanılır; etiketsizlerin etiketi kullanıcıdan alınmaz, model tarafından tahmin edilir.
  - Etiketsiz verinin dağılımı, karar sınırını sadece etiketli iki noktaya bakarak çizilen sınırdan daha iyi bir yere taşıyabilir.
  - Etiket tahmini tek seferde (batch) ya da iteratif yapılabilir; iteratif yöntemde nerede durulacağı kritiktir.
- Öğrenmenin transferi ve çok görevli eğitim
  - Transfer: bir problemi çözdükten sonra veri, model veya parametreleri benzer bir başka probleme aktarmak. Yeni problem için yeterli veri yoksa ve problemler ilgiliyse işe yarar.
  - Çok görevli (multitask) eğitim: birden çok görev aynı yapıda, ortak bir kayıpla eş zamanlı öğrenilir; görevler birbirinin öğrenmesine yardım edebilir.
- Hiperparametre optimizasyonu ve aktif örnekleme
  - Izgara arama, rastgele arama ve Bayesçi optimizasyon karşılaştırıldı.
  - Aktif örnekleme, Bayesçi optimizasyondan esinlenir: kullanıcıdan input uzayında yeni örnek (input ve çıkış) istenir; veri toplama sürecini optimize eder.
- İnsan-makine işbirliği (human-in-the-loop, weak supervision)
  - İnsanlar yavaş ama doğru, makineler hızlı ama daha az doğrudur; ikisinin güçlü yanları birlikte kullanılır.
- Az sayıda örnekle eğitim
  - One-shot: eğitim kümesinde her sınıf için tek örnek vardır.
  - Zero-shot: test örneğinin sınıfı eğitim kümesinde hiç yoktur; çok modlu (multimodal) yapılar ve ortak temsil uzayları kullanılır. Zero-shot makine çevirisi örneği verildi.
- Veri zenginleştirme (data augmentation)
  - Görüntülerde kırpma, ayna yansıması, renk değişimi, elastik deformasyonlar; metinde eş anlamlı dönüşümler ve geri çeviri (back translation); tablo verisinde sınıf dağılımı tahmin edip örnek üretmek ve SMOTE.
- Makine öğrenmesi algoritmalarını kandırmak (adversarial attacks)
  - Özel hazırlanmış küçük bir gürültüyle bir görüntünün sınıfı yüksek güvenle yanlış tahmin ettirilebilir.
- Planlı öğrenme (curriculum learning) ve hayat boyu öğrenme (lifelong learning)
  - Planlı öğrenme: örnekleri rastgele değil, belirli bir sırayla (ör. kolaydan zora) vermek.
  - Hayat boyu öğrenme: öğrenme süreci bitmez; veriler zaman içinde gelir, test örnekleri yeni sınıflardan gelebilir (open world).
- Ders sonundaki proje soru-cevapları (akademik noktalar)
  - Dengesiz veride yapay örnek üretimi ile örnek azaltımının birlikte denenmesi; yapay sinir ağı çözümleri arasındaki yollardan ensemble kurulması; ağırlık uzayında MCMC benzeri gezinme; ensemble'ların kappa-hata diyagramında nokta bulutu olarak gösterilmesi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu konuların lisansüstü çalışmalar için önemi
  - Bu alanlar doğrudan tez konusu olmasa bile, tez probleminin içinde kullanılabilir (ör. bir tezde aktif öğrenmeyi kullanmak).
- Aktif öğrenmede önce zor örnekler
  - UCI veri kümelerindeki denemelerde önce kolay (emin olunan) örnekleri eklemek, rastgele eklemekten bile kötü çıktı. Önce zor (sınırda) örnekleri eklemek bazı veri kümelerinde rastgeleyi geçti ve aynı başarıya daha az etiketle ulaştı.
  - Bazı veri kümelerinde tüm eğitim örnekleri yerine daha az örnekle daha yüksek test başarısına erişildi; bunun olası nedeni gürültülü örneklerdir.
- Başlangıç noktasının önemi
  - Aktif öğrenme global bir optimizasyon olmadığı için ilk eğitim setinin seçimi varılan yeri etkiler. Rastgele seçim yerine kümeleme yapıp her kümeden bir örnek almak da düşünülebilir.
- İteratif yöntemlerde durma noktası
  - Yarı eğiticili öğrenmede en sona kadar gitmek yerine bir yerde durmak daha yüksek başarı verebilir.
- Transfer edilen katmanlar
  - Görüntü ağlarının ilk katmanları (çizgi, köşe gibi) alana bağlı olmayan özellikler öğrenir ve kolayca transfer edilir. Son (sınıf olasılıklarını veren) katmanı almanın anlamı yoktur; softmax öncesi katmanlar sık kullanılır.
- Adversarial örneklere karşı kesin savunma yok
  - Eğitim kümesini büyütmek, hatta adversarial örnekleri eğitime katmak bile yeni saldırı örneklerinin üretilmesini engellemiyor. Sorun yalnız derin ağların değil, doğrusal olmayan birçok yapının sorunudur.
- Etiketlemenin pahalılığı
  - İlaç geliştirme gibi alanlarda bir etiket çok yüksek maliyetlidir; etiketsiz veriden yararlanabilmek bu yüzden çok değerlidir.

## Kısa Tekrar Notları

- Aktif öğrenme etiketleme sürecini, aktif örnekleme veri toplama sürecini optimize eder.
- Aktif öğrenmede hiperparametreler: ilk eğitim seti, varyasyon ölçüsü, kolay/zor seçimi, her adımda eklenecek örnek sayısı, durma ölçütü (ör. etiketleme bütçesi).
- Yarı eğiticili öğrenmede etiketsiz örneklerin etiketi model tarafından tahmin edilir; en yakın etiketli komşuya tek seferde atama genelde işe yaramaz, iteratif yayılma daha etkilidir.
- Transfer öğrenme: yeni problemde veri azsa ve eski problemle ilgiliyse faydalı.
- Çok görevli eğitim: tek model, birden çok görev, ortak kayıp (multitask loss). Farklı veri kümeleri tek ağda eğitilecekse her örneğe hangi veri kümesinden geldiğini belirten bir kod eklenir.
- Hiperparametre arama: ızgara (sistematik), rastgele, Bayesçi (eldeki denemelere göre en çok iyileşme beklenen noktayı tahmin eder).
- Aktif örneklemede yeni örnek, farklı modellerin tahminlerinin standart sapmasının en yüksek olduğu bölgeden istenir.
- İnsanlar veri etiketleyebilir, tahmin düzeltebilir, en olası 5 sınıf arasından seçim yapabilir, genel kural verebilir ("kedilerin kuyruğu vardır").
- One-shot: sınıf başına tek örnek; zero-shot: eğitimde hiç görülmeyen sınıflar.
- Zero-shot makine çevirisi: A→B ve B→C paralel derlemi varken A→C çevirisi, ortak temsil katmanı sayesinde yapılabilir.
- SMOTE: az örnekli sınıftan bir örneğin k en yakın aynı sınıf komşusundan birini seç, ikisini birleştiren doğru üzerinde yeni örnek üret.
- Adversarial örnek: Inception v3'e göre %97 olasılıkla "papağan" olan resim, özel gürültü eklenince %99 olasılıkla "kitaplık" olarak sınıflandırıldı.
- Planlı öğrenmede örneklerin kolaylığı insan tarafından, bir algoritmanın sınıf olasılıklarıyla ya da geometrik ölçülerle belirlenebilir; öğrenme sırasında da değişebilir (self-paced learning).
- Hayat boyu öğrenme endüstride daha yaygındır, çünkü gerçek dünyada veri ve kavramlar zamanla değişir.

## Detaylı Açıklamalar

- Aktif öğrenmenin sezgisi
  - Bir örnek için model %90 A, %10 B; başka bir örnek için %51 A, %49 B diyorsa, modeli iyileştirmek için ikinci örneğin etiketini öğrenmek daha yararlıdır. Birinci örnekte model zaten emindir; ikincisi modelin karar sınırına yakındır ve etiketi sınırı belirginleştirir.
  - Iris veri kümesi üzerindeki görselde, birbirine çok yakın iki sınıfın arasındaki bölgeden örnekler seçildiği, diğer sınıftan uzak bölgeden ise örnek seçilmediği gösterildi.
  - Deney grafiklerinde x ekseni etiketli eğitim kümesinin büyüklüğüdür. Son noktada iki yöntem de bütün eğitim kümesini kullandığı için başarılar aynıdır; farklar ara noktalarda görülür.
  - Regresyon problemlerinde tahmin varyasyonunun nasıl ölçüleceği düşünmek üzere açık bırakıldı.
- Yarı eğiticili öğrenme
  - Klasik örnekte iki etiketli nokta arasına düz bir sınır çizilir; etiketsiz noktaların iki ayrı kıvrımlı küme oluşturduğu görülünce sınırın bu kümelerin arasından geçmesi daha mantıklıdır. Bunun için etiketsizlerin etiketleri tahmin edilmelidir.
  - Her etiketsiz noktayı en yakın etiketli noktaya atamak, iki etiketli noktanın ortasından düz bir çizgi çizmekle aynı sonucu verir ve işe yaramaz. Bunun yerine önce etiketli noktalara en yakın olanlar etiketlenir, sonra yeni etiketlenenlere en yakın olanlar; bu iteratif yayılma kıvrımlı kümelerin tamamını doğru etiketleyebilir.
  - `semi_supervised_learning.m` deneylerinde batch ve iteratif yöntemler karşılaştırıldı (ekrandan, 00:40:00). Bazı veri kümelerinde iteratif, bazılarında tek seferlik tahmin daha iyi çıktı; tahmini etiketleri hiç kullanmamanın daha iyi olduğu durumlar da var.
- Çok görevli eğitim deneyi
  - `multi_task_learning.m`: 2 boyutlu, 2 sınıflı 5 veri kümesi, 10 gizli nöronlu tek bir yapay sinir ağı, eşit eğitim süresi, 3 deneme (ekrandan, 00:50:00).
  - Birbiriyle hiç ilgisi olmayan UCI veri kümelerinde bile bazı veri kümelerinde test başarısı tek başına eğitime göre arttı (ör. 3. veri kümesinde üç denemenin üçünde de).
  - Açık sorular: bir ağ kaç problemi kapsayabilir, ağın karmaşıklığı artınca ne olur, boyut sayıları farklı veri kümeleri aynı ağa nasıl konur.
- Bayesçi optimizasyon
  - Denenmiş hiperparametre değerleri ve sonuçlarından, bir sonraki denemenin en çok iyileşme beklenen noktada yapılması tahmin edilir. Yaklaşım, iki denenmiş nokta arasında fonksiyonun düz bir çizgi gibi değil, bir miktar yukarı çıkıp inebileceğini varsayar. 10 hiperparametre varsa arama 10 boyutlu uzayda yapılır.
- İnsan-makine işbirliği örnekleri
  - Video etiketlemede insan yalnız ilk ve son kareyi etiketler, ara kareleri makine tahmin eder, insan da bu tahminleri düzeltir.
  - Snorkel (Stanford) ile "içinde dolar geçen haberler büyük olasılıkla ekonomi sınıfındandır" gibi kurallarla tek seferde çok sayıda örnek için tam doğru olmayan ama olası etiketler üretilir.
- Az örnekle eğitim
  - François Chollet'nin sözü: eğitim verisi problem uzayını yoğun örnekliyorsa her problem örüntü tanıma problemi olarak çözülebilir; seyrek örneklemede genelleme (extrapolation) için zekâ gerekir.
  - Zero-shot öğrenmede eğitim sırasında örneklerin hem resmi hem tanımı vardır; çıkarımda yeni sınıfların yalnız tanımları vardır.
  - Google'ın sinir ağı tabanlı makine çevirisinde girişler ortak bir katmana, çıkışlar ortak katmandan gider. 100 dil için 10.000 ayrı model yerine tek model kullanılır; aynı anlamdaki farklı dillerdeki cümlelerin temsilleri birbirine yakın çıkar.
- Adversarial örneklerin kaynağı
  - Hocanın kaba açıklamasına göre doğrusal olmayan karar sınırları, eğitim verisi olmayan bölgelerde de bir sınıfa ait bölgeler oluşturur. Gürültü, resmi bu bölgelerden birine doğru iter. Doğal resimlerin, yani eğitim verisinin bulunduğu bölgelerin etrafında böyle bir sorun görülmez.
  - Tek bir pikselin değiştirilmesiyle bile kandırma mümkün olabiliyor; ancak her resim için ayrı uğraşmak gerekir.
- Planlı öğrenme
  - İnsanlar ilköğretim, lise, üniversite sırasıyla, kabaca kolaydan zora eğitilir. Makinede de örnekler belirli bir sırayla verilebilir.
  - Pekiştirmeli öğrenmede yaygındır: robot eliyle Rubik küpü çözme örneğinde denemelerin çoğu kısıtlı simülasyon ortamında yapılır, sonra öğrenilenler gerçek dünyaya aktarılır.
  - Zordan kolaya (anti-curriculum) sıralamanın da başarılı olduğu sonuçlar var.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
