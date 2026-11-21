# Ders 13 Çalışma Özeti

## Genel Konular

- Dönem projelerinin ilerleme raporları
  - Bu ders, öğrencilerin kolektif öğrenme projelerindeki ilerlemeyi ekran paylaşarak gösterdiği ve hocanın her projeye akademik geri bildirim verdiği bir oturumdur. Yeni konu anlatılmadı; tartışmalar daha önceki derslerde işlenen yöntemlerin (karar ağaçları, bagging, AdaBoost, random forest, Improved Space Forest, yapay sinir ağlarıyla kolektif öğrenme) uygulanması üzerine yoğunlaştı.
- Soft etiketlerle karar ağacı eğitimi (output smoothing)
  - Birinci aşamada bir ağaç ya da bir topluluk eğitilir, eğitim kümesi bu modele test gibi verilir ve her eğitim örneği için sınıf olasılıkları bulunur. Olasılık, örneğin düştüğü yaprak düğümdeki sınıf dağılımından ya da topluluktaki ağaçların oylarından (kaç ağaç A, kaç ağaç B dedi) elde edilir.
  - Böylece one-hot etiketler yerine "yumuşak" (soft) etiketler oluşur. Örneğin bir örnek "%80 Elma, %20 Muz, %0 Limon" olarak etiketlenir (ekrandan, 02:00:00).
  - İkinci aşamada yeni bir ağaç eğitilir. Tek fark, her düğümde özellik ve eşik ikilisi seçilirken hard etiketler yerine soft etiketlere göre optimizasyon yapılmasıdır. Ağacın geri kalanı normal karar ağacıyla aynıdır: bir örnek bir düğümde ya sağa ya sola gider, olasılıklar alt düğümlere "paslanmaz", etiketler değiştirilmez.
  - Motivasyon: etiketleyen kişi hem elmaya hem armuta benzeyen bir nesneye yalnızca "elma" der ve benzerlik bilgisini siler. Soft etiket, etiketleme sürecinde kaybolan bu bilgiyi geri kazanır. Hoca bunu K-means (hard atama) ile Expectation-Maximization (her örneğin her kümeye ait olma olasılığı) arasındaki farka benzetti.
- Improved Space Forest'ın Python uygulaması
  - Improved Space her ağaç için orijinal özelliklerin yanına farklı rastgele yeni özellikler ekler. Bu yüzden yeni uzay bir kez değil, her ağaç için ayrı oluşturulmalıdır.
  - Eğitim ve test aynı anda verilmemeli: eğitim fonksiyonu oluşturduğu uzayları (hangi özellik ikilileri alındı, nelerle çarpıldı) çıktı olarak vermeli, test fonksiyonu bunları alıp test kümesine uygulamalıdır.
  - Random Forest ve Bagging paralel çalıştığı için, her biri tek ağaçlı ve kendi uzayına sahip topluluklar kurup sonuçlarını çoğunluk oylamasıyla birleştirmek geçerlidir. AdaBoost ve XGBoost ardışık çalıştığı için bu hile geçerli değildir; algoritmanın içinde her turdaki ağacın kendi genişletilmiş eğitim kümesine sahip olması sağlanmalıdır.
- Yapay örnek üretimi (SMOTE, ADASYN, BorderlineSMOTE)
  - Veri kümeleri en küçük ve en büyük sınıf oranına göre dengeli, kısmen dengeli, kısmen dengesiz ve dengesiz diye ayrıldı (ekrandan, 00:25:00). Yapay örnekler yalnız eğitim kümesine eklendi; 10 katlı çapraz doğrulama kullanıldı.
  - BorderlineSMOTE: k en yakın komşunun hepsi çoğunluk sınıfındansa örnek gürültü sayılır ve ondan üretim yapılmaz; komşuların çoğunluğu çoğunluk sınıfındansa sınır örneği sayılır ve ondan üretilir. ADASYN: bir örnekten üretilecek yapay örnek sayısı, komşuları arasındaki çoğunluk sınıfı örneklerinin sayısıyla doğru orantılıdır.
  - Hocanın önerisi: 20 aşama yerine 4-5 aşama yeterlidir; her aşamada sabit 100 örnek yerine eğitim kümesinin boyutuna oranlı sayıda örnek eklenmeli ve son eğitim kümesi, dengeleme sonrası boyutun yaklaşık iki katını geçmemelidir.
- Online ağaçlardan topluluk
  - Hoeffding ağacı (scikit-multiflow) örnekleri tek tek alır; her yeni örnek önce o anki ağaçla tahmin edilir, sonra `partial_fit` ile ağaca öğretilir (ekrandan, 00:45:00). Bu döngüde çıkan doğruluk eğitim akışı üzerindedir; ayrı bir test kümesi gerekir.
  - Topluluk, aynı eğitim kümesinin farklı sıralarla verildiği ağaçlardan kurulur. Her ağaç bütün veriyi görür ama sıra farkı yüzünden farklı ağaçlar oluşur. Sonuç tek ağaçla karşılaştırılır.
- Yapay sinir ağı çözümlerini birleştirmek
  - İki bağımsız eğitilmiş ağın son noktaları (Q0 ve Q10) arasındaki doğru üzerinde 9 ara nokta alındı; bu noktalarda kayıp yüksekti. Her noktadan 20 epok daha eğitim yapılınca kayıplar düştü. Ara modellerle kurulan topluluk 0.85'e çıktı, iki uç modelin topluluğu 0.845'te kaldı (ekrandan, 00:55:00).
  - Hoca adil karşılaştırma istedi: toplam eğitim süresi (epok bütçesi) eşit tutulmalıdır.
  - Projenin amacı sıradan topluluklar değil, iki ağın bitiş noktalarını birleştiren çizgiler üzerindeki ya da çevresindeki noktalardan topluluk kurmaktır. Bu, 5 farklı veri kümesi-mimari ikilisinde denenecek.
- Metropolis/MCMC ile hata-parametre yüzeyi keşfi
  - Eğitilmiş bir ağdan başlayıp ağırlıklara ortalaması sıfır olan normal dağılımdan küçük adımlar eklenerek rastgele yürüyüş yapılır. Bazı başlangıç noktalarında doğruluğu biraz artıran ağırlıklar bulundu. Sonucun sigma ile doğru ya da ters orantılı bir ilişkisi görülmedi (ekrandan, 01:15:00).
  - Ağırlıkların sonsuza gitmesi bir hatadan kaynaklanıyordu: adım, ortalaması sıfır olan dağılım yerine ortalaması önceki değer olan dağılımdan seçilip yine önceki değere eklenmişti. Bu yüzden değer her adımda yaklaşık ikiye katlanıyordu.
- Kappa-hata diyagramları ve maksimum derinlik analizi
  - Random Forest ve Bagging için tekil öğrenici sayısına göre (renkler 10-100) kappa-hata grafikleri çizildi (ekrandan, 01:20:00). Sol alt köşe (düşük hata, düşük kappa yani yüksek çeşitlilik) iyi bölgedir.
  - Hoca grafiklerin yanına topluluğun eğitim ve test başarısının da yazılmasını istedi; yalnız eğitim üzerinden yorum yapılmaz.
  - scikit-learn AdaBoost'u mükemmel uyumda erken durur; tam derinlikli ağaçla kullanıldığında tek tahminciyle kalır (ekrandan, 01:25:00).
- Topluluk içinde topluluk (ensemble-in-ensemble)
  - Bagging, Random Forest, AdaBoost, GBM ve XGBoost karşılaştırıldı; en zayıflar çıkarılıp kalan RF, GBM ve XGB'den oylamayla "Deep Ensemble" kuruldu (ekrandan, 01:30:00 ve 01:35:00).
  - Hocanın eleştirisi: 300 ağaçlı bir yapı 100 ağaçlı RF ile kıyaslanırsa karşılaştırma adil olmaz. Ağaç sayısı eşit tutulmalıdır, çünkü topluluklarda ağaç sayısı arttıkça başarı zaten artar. İki seçenekli kazanma oranı için pasta grafiği yerine tek bir sayı yeterlidir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Adil karşılaştırma
  - Topluluk yöntemleri karşılaştırılırken ağaç sayısı ya da toplam eğitim süresi eşit tutulmalıdır. Aksi hâlde "şunu yendi" demek anlamsızdır.
- Test kümesi
  - Başarı yalnız eğitim kümesinde değil, test kümesinde ölçülmelidir. Eğitim başarısı tek başına önemli değildir; yorum test sonuçlarıyla yapılır.
- Önce AdaBoost, sonra XGBoost
  - XGBoost da AdaBoost gibi ardışık (paralel olmayan), ama daha karmaşık bir algoritmadır. AdaBoost'a bir değişiklik uygulanamıyorsa XGBoost'a geçmenin anlamı yoktur.
- Soft etiket yalnız bölme ölçütünü değiştirir
  - Soft etiketler yalnız düğümlerde özellik ve eşik seçimini etkiler. Ağacın yapısı ve örneklerin sağa-sola gidişi deterministik kalır.
- Araştırmacı tutumu
  - Hoca öğrencilerin inisiyatif almasını, yalnız son sonucu değil denenen bütün yolları ve karşılaştırmalarını göstermesini istedi.

## Kısa Tekrar Notları

- Soft etiket: eğitim kümesi birinci modele test gibi verilir; sınıf olasılıkları yaprak dağılımından ya da topluluk oylarından alınır.
- Soft etiketli ağaç: yalnız özellik ve eşik seçiminde soft etiketlere göre en az kayıp aranır; ağaç algoritmasının geri kalanı aynıdır.
- Improved Space: her ağaç için yeni rastgele özellikler; eğitimde üretilen uzay test fonksiyonuna aktarılır.
- RF ve Bagging paraleldir, tek ağaçlı toplulukları birleştirmek geçerlidir; AdaBoost ve XGBoost ardışıktır, geçerli değildir.
- BorderlineSMOTE: komşuların hepsi çoğunluk sınıfındansa gürültü, çoğunluğu çoğunluk sınıfındansa sınır örneği. ADASYN: üretim sayısı çoğunluk komşu sayısıyla orantılı.
- Yapay örnek sayısı veri boyutuna oranlanmalı, eğitim kümesi en fazla yaklaşık iki katına çıkmalı.
- Online ağaçlar: farklı veriliş sıraları farklı ağaçlar üretir; topluluk buradan kurulur; test ayrı kümede yapılır.
- YSA uç noktaları arasındaki yol üzerindeki modellerle topluluk; karşılaştırmada epok bütçesi eşitlenmeli.
- MCMC rastgele yürüyüşü: adım $\mathcal{N}(0,\sigma^2)$'den seçilip önceki değere eklenir.
- Kappa-hata diyagramında sol alt köşe iyidir.

## Detaylı Açıklamalar

- **Soft etiketli karar ağacı.** Ekrandaki örnek tabloda Renk, Boyut ve Tat özellikleriyle Meyve sınıfı vardır (ör. Kırmızı, 3, Tatlı, Elma) (ekrandan, 00:05:00). Birinci aşamada 100 ağaçlık bir topluluğun kararlarına bakılarak her örneğe olasılıklı bir etiket verilir: Kırmızı-3-Tatlı-Elma için "%80 Elma, %20 Muz, %0 Limon", Sarı-2-Ekşi-Limon için "%80 Limon, %10 Muz, %10 Elma" (ekrandan, 02:00:00). İkinci aşamada her düğümde aday özellik-eşik ikilileri bu soft etiketlere göre değerlendirilir. Hocanın sezgisi: %100 elma olan bir örneğe "armut" denirse 1 birim kaybedilir; %80 elma, %20 armut olan bir örneğe "armut" denirse 0.8, "elma" denirse 0.2 kaybedilir. Düğümde en az toplam kaybı veren özellik ve eşik seçilir. Bu işlem kökte değil, bütün düğümlerde yapılır.
- **Improved Space ve boosting.** Hoca, AdaBoost'ta örneklerin seçilme dağılımının önceki ağaçların doğru ve yanlışlarına göre güncellendiğini, bu kısma dokunulmayacağını söyledi. Değiştirilecek tek yer, her turda üretilen ağaca orijinal özelliklerin yanına o ağaca özgü ek özellikler eklenmiş bir veri kümesi vermektir. Tahminci sayısı 1 yapılırsa boosting olmaz: AdaBoost ya da XGBoost önce bir ağaç üretir, sonra onu kullanarak ikinciyi, onu kullanarak üçüncüyü üretir. Topluluk boyutu 10, 20 gibi değerler olmalıdır.
- **Yapay örnek üretimi sonuçları.** Hepatitis (155 örnek, 2 sınıf, dengesiz) için algoritma kararlılığı (başarıların varyansı) SMOTE 0.01566, BorderlineSMOTE 0.01261, ADASYN 0.01237 bulundu. Başlangıç başarısına göre galibiyet-beraberlik-mağlubiyet sayıları 1-1-18, 0-2-18 ve 0-0-20'dir (ekrandan, 00:30:00). Vowel (990 örnek, 11 sınıf, dengeli) kümesinde üç algoritma da 20 adımın hepsinde başlangıcı geçti (20-0-0). Doğruluk yaklaşık 0.76'dan 0.95'e çıktı (ekrandan, 00:35:00). Hoca, vowel'in yapay örnek eklemeye daha uygun bir veri kümesi gibi göründüğünü söyledi.
- **Online ağaç döngüsü.** Ekrandaki kodda her örnek için `y_pred = ht.predict(X)`, doğruysa sayaç artırımı ve ardından `ht = ht.partial_fit(X, y)` yapılıyordu (ekrandan, 00:45:00). Hoca, bu döngü bittiğinde tek bir ağacın büyüdüğünü, bunun eğitim olduğunu, ağacın sonra test kümesine verilmesi gerektiğini söyledi. Adaptive Random Forest'ı ise projeden çıkarmasını istedi; Hoeffding ağacı yeterlidir.
- **YSA çözümleri arasındaki yol.** Hoca, Figür 2'deki orta noktadaki farklı davranışı ilginç buldu. A'dan B'ye giden yolda orta noktanın bir tür kırılma noktası olabileceğini, bunu düzeltmeye çalışmanın bir araştırma yönü olabileceğini söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
