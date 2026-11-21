# Ders 10 Çalışma Özeti

## Genel Konular

- Yapay sinir ağlarının (YSA) iç dinamikleri ve kolektif öğrenme
  - Eğitim, rastgele bir $w_0$ ağırlığından başlayıp gradient descent, Adam vb. bir yöntemle $w_1, w_2, \dots, w_T$ ağırlıklarına ilerleme sürecidir. Yönü, eğitim kümesindeki tahminlerle gerçek değerler arasındaki fark (loss) belirler (ekrandan, 00:10:00).
  - Geri yayılım (backpropagation): önce ileri yönde çıkış ve loss hesaplanır, sonra çıkış katmanından başlayarak her katman bir öncekine doğru güncellenir. Nöronlar birbirlerinden gelen sinyallerle birlikte öğrenir.
  - Slayttaki ifadeyle her sanal nöron bir temel öğrenicidir; bu yüzden tek bir YSA bile kolektif öğrenme içerir. Ayrıca birden fazla YSA'nın kararları birleştirilerek YSA'lar temel öğrenici olarak da kullanılabilir.
- Temel öğrenici olarak YSA'lar (ekrandan, 00:15:00)
  - Karar ağaçları deterministiktir; farklı karar üretmeleri için içlerine rastgelelik katmak gerekiyordu. YSA'lar deterministik değildir, farklı karar üretmeleri için çok uğraşmaya gerek yoktur.
  - Farklılık kaynakları: farklı başlangıç değerleri ($w_0$), farklı örnek / mini-batch sıralamaları (SGD), farklı hiperparametreler (öğrenme katsayısı, katman sayısı, katmandaki nöron sayısı).
- Veri artırımı (data augmentation) (ekrandan, 00:30:00)
  - Eldeki verilere güvenilir dönüşümler uygulayarak, ek etiketleme maliyeti olmadan yeni örnekler üretmek.
  - Resimlerde döndürme, renklerle oynama, siyah-beyaz yapma, yaklaşık %80'lik kırpılmış parçalarla eğitim. Metinlerde eş anlamlı kelime/ifade dönüşümü ve geri çeviri (back translation: A dili → B dili → yeniden A dili).
  - Dönüşümün sınırı veri kümesine bağlıdır: yıldız resmi istenen açıda döndürülebilir, ama rakam ve harflerde döndürme 8 ile sonsuz işaretini karıştırabilir.
  - Her model farklı dönüşümlerle üretilmiş verilerle eğitilip kararlar birleştirilebilir ya da aynı model her epoch'ta farklı dönüştürülmüş verilerle eğitilebilir.
- Tank sınıflandırma hikâyesi ve açıklanabilirlik
  - Dost/düşman tank resimleriyle eğitilen bir YSA test kümesinde yaklaşık %99 başarı verip gerçek ortamda %50 civarına düşmüştür. Sebep: dost tanklar güneşli, düşman tanklar bulutlu havada çekilmiş; ağ havanın güneşli olup olmadığını öğrenmiştir.
  - Karar ağacında "resmin üst kısmındaki piksellerin aydınlığı şu değerden büyükse dost" gibi bir düğüm görülür ve hata daha çabuk fark edilirdi. YSA'nın neye göre karar verdiğini anlamak daha güçtür (imkânsız değil). Bu, açıklanabilir yapay zekâ (explainable AI) alanının konusudur. CNN çekirdekleri yoğun ağlara göre daha kolay yorumlanabilir.
  - Kırpılmış parçalarla eğitim arka plana (background) karşı oluşabilecek yanlılığı azaltır.
- 2012 ImageNet (ILSVRC-2012) sıçraması (ekrandan, 00:35:00)
  - Top-1 hata: en olası tahmin yanlışsa hata. Top-5 hata: ilk 5 tahminin hiçbiri doğru değilse hata. Top-5 doğruluk her zaman Top-1 doğruluktan yüksek ya da ona eşittir.
  - Top-5 test hatası: ikinci en iyi sistem (SIFT + FVs, kendisi de bir ensemble) %26.2; 5 CNN %16.4; 7 CNN* %15.3. Top-5 doğrulama hatası 1 CNN'de %18.2'den 5 CNN'de %16.4'e iner.
  - Kazanan sistemler de birden fazla CNN'in kararlarını birleştiren ensemble'lardır; bu kolektif öğrenmenin önemini gösterir.
  - Dezavantajlar: $L$ ağ eğitmek yaklaşık $L$ kat hesaplama (elektrik) demektir; paralel makinelerle süre azaltılabilir. Büyük ağlar milyonlarca parametre içerdiği için bellek gereksinimi de artar.
- Kararları mı, parametreleri mi birleştirmeli? (ekrandan, 00:45:00 ve 00:50:00)
  - Aynı eğitim sürecindeki $w_k, w_h, w_g, w_T$ noktalarının hem kararlarını (demokrasi) hem de parametrelerinin ortalamasını almak (yeni bir $w$ üretmek) mümkündür.
  - Farklı başlangıçlardan ($w_0$) varılan $w_{a1}, w_{a2}, w_{a3}$ noktalarının kararlarını birleştirmek mantıklıdır (klasik ensemble). Parametrelerinin ortalamasını almak ise mantıklı değildir: farklı lokal minimumlardadırlar ve iki lokal minimumun ortası minimum olmayabilir, büyük olasılıkla daha yüksek hatalı bir yerdir.
  - Aynı eğitim sürecinin sonundaki noktaların parametre ortalaması mantıklıdır: SGD'nin son kısmında "R bölgesinde kaos" vardır, noktalar bir orta noktanın etrafında salınır; ardışık noktaların ortalaması orta noktaya son noktadan daha yakındır. Başlardaki noktaları almak mantıklı değildir.
- Snapshot Ensembles (ekrandan, 01:05:00)
  - Tek bir eğitim sürecinden, her biri ayrı bir lokal minimumda olan birkaç model çıkarılır ve kararları birleştirilir.
  - Standart öğrenme katsayısı (learning rate) planında katsayı bütün süreç boyunca azalır. Döngüsel planda (cosine annealing with restart) katsayı bir döngüde azalır, model kaydedilir, sonra katsayı tekrar başlangıç değerine yükseltilir. Lokal minimumda türev sıfıra yakın olduğu için oradan çıkmanın yolu büyük öğrenme katsayısıdır.
  - Snapshot'lar farklı lokal minimumlarda olduğu için parametre ortalaması anlamsızdır; kararlar birleştirilir.
- Snapshot sonuçları (ekrandan, 01:00:00)
  - Karar benzerliği (CIFAR100, DenseNet-100): döngüsel planda snapshot'lar arası benzerlik yaklaşık 0.88-0.93, standart planda son snapshot'lar arası 0.99. Birbirinin aynısı karar veren modellerden ensemble kurmak anlamsızdır.
  - Ensemble hatası (CIFAR100, DenseNet-40): tek model yaklaşık %26; snapshot ensemble (model başına 50 epoch) model sayısı arttıkça düşer; true ensemble (her biri 300 epoch, farklı başlangıçlardan) daha da düşüktür.
  - Snapshot ensemble'ın değeri, tek modelle aynı eğitim süresinde (300 epoch) birden fazla model vermesidir.
  - Snapshot'lar arası doğrusal ara değerleme: son model ile önceki snapshot'ları birleştiren doğru üzerindeki test hatası; ilk snapshot'larla arada yüksek bir "dağ" vardır, son snapshot'larla fark küçüktür. Standart planda (NoCycle) bu tepeler çok daha yüksektir.
- Parametre uzayında doğru üzerinde loss
  - Her ağ, parametre sayısı kadar boyutlu bir uzayda bir noktadır. İki nokta arasındaki doğrunun her noktası da bir ağdır; $L = F(b_1, b_2, X, Y)$ ile o noktanın loss'u hesaplanabilir (ekrandan, 01:15:00).
- Bağımsız eğitimlerle erişilen lokal minimumlar bağlıdır (ekrandan, 01:35:00 ve 01:45:00)
  - İki bağımsız minimum $\theta_1, \theta_2$ arasındaki doğrusal ara değerlemede loss yükselir, ama ikisini birleştiren ve üzerinde loss'un neredeyse sabit kaldığı bir yol bulunabilir (DenseNet-40-12, CIFAR10).
  - Yol, en yüksek loss noktasından yeni pivotlar eklenerek adım adım bulunur (ResNet-20, CIFAR10 örneği). Sonraki çalışmalarda Bezier eğrileri ya da tek kırılmalı çizgilerle de yapılabildiği gösterildi.
  - İddia düşük boyutlu uzaylar için değil, çok yüksek boyutlu parametre uzayları için empirik bir gözlemdir; teorem değildir. Derin ağların çok parametreye rağmen iyi çalışmasının bir açıklaması olarak öne sürülür.
  - Slayttaki not: ağırlıklarda ölçeklendirme hatayı değiştirmez.
- Kararları değil, ağırlıkları birleştirmek: SWA (ekrandan, 01:50:00)
  - Ağın eğitiminin sonundaki epoch'lardaki ağırlıkların ortalaması alınır; son epoch'larda sabit yüksek ya da döngüsel öğrenme katsayısı kullanılır. Her modeli ayrı tutmaya gerek yoktur, tek ek model yeterlidir.
  - $w_{SWA}$ çevresinde rastgele yönlerde hata az artar (geniş çözüm), SGD çözümü ise bölgenin kenarına yakındır. Eğitim kümesinde SGD biraz daha iyi, test kümesinde SWA daha iyidir (ResNet, VGG16).
  - Tek eğitimden alınan modeller true ensemble kadar çeşitli (diverse) ve başarılı değildir.
- Hocanın kendi denemeleri: Digits veri kümesi (ekrandan, 01:55:00 ve 02:05:00)
  - İki bağımsız ağın aynı epoch'taki ağırlıklarını birleştiren doğru (iki yana uzatılmış) üzerinde: 4, 7 ve 15. epoch'ta iki nokta arasında bir vadi vardır ve vadi ilerleyen epoch'larda derinleşir.
  - Aynı eğitim içinde $a_x$ ile $a_y$ doğrultusu (1, 3, 5 epoch fark ve en sona kadar): 6. ile 7. epoch arasındaki farkı ekleyerek ilerlemek, gradyan hesaplamadan başarıyı bir süre artırır. Uzak noktalarda ve en başarılı noktadan sonra işe yaramaz. Önerilen fikir: başarı arttığı sürece $y$'ye $(y-x)$ ekleyerek ilerle, artış durunca standart eğitime dön.
- Validasyon kümesi (derste sözlü)
  - Ağırlık güncellemesine katılmaz; eğitimi izlemek, erken durdurma (early stopping), budama ve hiperparametre seçimi için kullanılır. Karar ağacı genişlik öncelikli üretilirse derinliğin yeterliliği validasyonla izlenebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Karar birleştirme ile parametre birleştirme farkı
  - Farklı eğitim süreçlerinin kararları birleştirilir; aynı eğitim sürecinin sonlarındaki ağırlıklar ortalanabilir. Farklı lokal minimumların parametre ortalaması anlamsızdır. Hoca bu farkın anlaşıldığını birkaç kez sordu.
- İki nokta arasındaki doğru üzerinde test performansı
  - Hoca ödevin bu konu üzerine olduğunu söyleyerek konuyu iki boyutlu bir çizimle ayrıntılı anlattı.
- Snapshot ensemble'ın amacı süredir
  - True ensemble daha başarılıdır, ama snapshot ensemble tek model kadar sürede birden fazla model verir.
- Makine öğrenmesinde genel bir ilke
  - Makinelere ne yapmaları gerektiğini söyleyebilirsiniz, nasıl yapmaları gerektiğini söyleyemezsiniz. Yanlış bir şey öğrendiklerini fark etmek için açıklanabilirlik önemlidir.
- Bağlı minimumlar iddiası empiriktir
  - Teorem değildir; birçok mimaride deneysel olarak gösterilmiştir.

## Kısa Tekrar Notları

- YSA'lar deterministik değildir: farklı $w_0$, örnek sırası ve hiperparametre çeşitlilik verir.
- Veri artırımı etiket maliyeti olmadan veri üretir; dönüşümün sınırı veri kümesine bağlıdır.
- ILSVRC-2012 Top-5 test hatası: %26.2 (ikinci) ile %15.3 (7 CNN) arasında yaklaşık 10.9 puanlık fark.
- Ensemble maliyeti: $L$ model ≈ $L$ kat hesaplama ve bellek.
- Farklı başlangıçlar → farklı lokal minimumlar → kararları birleştir.
- Aynı sürecin sonu (R bölgesi) → ağırlıkları ortala (SWA).
- Snapshot ensemble: döngüsel öğrenme katsayısı, her döngü sonunda bir model, kararlar birleştirilir.
- True ensemble > snapshot ensemble > tek model; snapshot'ın süresi tek modelle aynıdır.
- Bağımsız minimumlar arasında düşük loss'lu yollar vardır (yüksek boyutta, empirik).
- SWA geniş bir minimuma varır: eğitimde biraz kötü, testte daha iyi.

## Detaylı Açıklamalar

- YSA eğitimini bir yörünge olarak düşünmek dersin ana fikridir. Rastgele bir $w_0$ ile başlanır, her güncellemede yeni bir $w$ üretilir, en sonunda $w_T$'ye varılır. Bu yörüngenin her noktası tahmin üretebilen bir ağdır; başlangıçtaki rastgele ağ bile bir karar verir, ama bu karar rastgeleye yakındır. Bu bakışla iki soru sorulur: hangi noktalar birleştirilmeli ve ne birleştirilmeli (kararlar mı, parametreler mi)?
- Farklı başlangıçlardan eğitilen ağlar farklı lokal minimumlara varır. Bu ağların kararlarının ortalaması klasik ensemble mantığıdır: birbirinden farklı şeyler söyleyen birçok kişinin aklına güvenmek tek kişiye güvenmekten iyidir. Parametrelerin ortalaması ise iki vadinin ortasındaki tepeye düşebilir; bu yüzden anlamsızdır. Buna karşılık tek bir SGD sürecinin son kısmında ağırlıklar aynı minimumun etrafında gürültülü biçimde salınır. Bu salınan noktaların ortalaması minimumun merkezine son noktadan daha yakındır; SWA bunu kullanır.
- Snapshot Ensembles bu iki fikrin arasındadır. Öğrenme katsayısı döngüsel olarak büyütülüp küçültülür. Küçük katsayıyla bir minimuma yakınsanır, o model kaydedilir; katsayı tekrar büyütülünce ağ o minimumdan çıkar ve başka bir minimuma gider. Böylece tek eğitim süresinde birbirinden farklı birkaç model elde edilir. Bu modeller farklı minimumlarda olduğu için kararları birleştirilir. Sonuçlar (CIFAR, DenseNet) snapshot ensemble'ın tek modelden, true ensemble'ın ise snapshot ensemble'dan daha başarılı olduğunu gösterir; çünkü bağımsız süreçler daha çeşitli kararlar üretir.
- Parametre uzayında iki nokta arasındaki doğru incelenebilir. $w_A$ ve $w_B$ iki ağsa $(1-\lambda) w_A + \lambda w_B$ biçimindeki her nokta da bir ağdır ve test hatası ölçülebilir. Snapshot makalesinde son snapshot ile ilk snapshot arasında yüksek bir hata tepesi, son snapshot'lar arasında ise küçük farklar görülür. "Essentially No Barriers" çalışması ise bağımsız iki minimum arasında doğru boyunca yüksek bir engel olsa da eğri bir yol boyunca loss'un neredeyse sabit kaldığını gösterir.
- Hocanın Digits denemeleri iki gözlem verir. Birincisi, iki bağımsız ağın arasındaki vadi epoch ilerledikçe derinleşir. İkincisi, aynı eğitimde ardışık iki epoch'un ($a_6$, $a_7$) farkı doğrultusunda ilerlemek, gradyan hesaplamadan başarıyı bir süre artırır. Bu, eğitimi hızlandırmak için açık bir araştırma fikri olarak sunuldu: ilerlemenin daha iyi bir noktaya götürüp götürmediği bilinmiyor.
- Tank örneği, test kümesindeki yüksek başarının modelin doğru şeyi öğrendiği anlamına gelmediğini gösterir. Eğitim ve test aynı yanlı koşullarda toplanmışsa (dost tanklar güneşli, düşman tanklar bulutlu), model asıl hedef yerine bu kestirmeyi öğrenebilir. Kırpılmış parçalarla veri artırımı ve açıklanabilir modeller bu tür hataları azaltmaya ya da fark etmeye yardım eder.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
