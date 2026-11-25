# Ders 6 Çalışma Özeti

## Genel Konular

- Dersin biçimi: öğrenci proje sunumları ve hocanın değerlendirmeleri
  - Bu oturum çevrim içi yapıldı ve tamamen öğrenci proje sunumlarına ayrıldı. Her sunumda bir veri seti seçilip derste görülen derin öğrenme yöntemlerinden biri uygulandı; ardından hoca yöntem, veri ve sonuçlar üzerine sorular sordu.
  - Hocanın genel beklentisi: görüntü, ses, sinyal ya da tablo verisi (tek veya iki boyutlu) üzerinde ders kapsamında öğrenilen yöntemlerin uygulanması ve sonuçların hem nitel (görsel örnekler) hem nicel (sayısal metrikler) olarak verilmesi.
- Araç tespiti (Car Object Detection) ve YOLO
  - Sınırlayıcı kutu (bounding box) çıktı vektörü: $y = (p_c, b_x, b_y, b_h, b_w, c)$. $p_c$ nesnenin kutuda bulunma güveni, $(b_x, b_y)$ kutunun merkez koordinatları, $b_h$ ve $b_w$ yükseklik ve genişlik, $c$ sınıf bilgisidir (ekrandan, 00:10:00).
  - YOLO, görüntüyü ızgaraya böler; nesnenin merkezini içeren ızgara hücresi o nesnenin sınıfını, kutu boyutlarını ve güvenini tahmin eder. Görüntüyü ağdan tek geçişte işlediği için hızlıdır.
  - Kaggle araç veri seti (yaklaşık 1001 eğitim, 175 test görüntüsü, CSV'de `xmin, ymin, xmax, ymax`), Adam optimizasyonu.
  - Hoca, nesne tespitinde nicel başarı ölçütü olarak mAP@0.5 ve mAP@0.5:0.95 değerlerinin ve karışıklık matrisinin verilmesini istedi.
- Şerit algılama (Lane Detection) ve piksel tabanlı ikili segmentasyon
  - CULane veri seti: Pekin'de 6 araca takılı kameralarla toplanmış, 55 saat video, 133.235 kare (1640 × 590), 4 şerit; şerit işaret noktaları ve ikili segmentasyon maskeleri içerir (ekrandan, 00:20:00).
  - Aktivasyon olarak Leaky ReLU (ölü nöron ve kaybolan gradyan sorununa karşı), kayıp olarak sigmoid ile ikili çapraz entropiyi birleştiren `BCEWithLogitsLoss` (sayısal olarak daha kararlı), optimizasyon olarak Adam.
  - İkinci model: 3×3 evrişim + batch normalization + Leaky ReLU blokları, iki 2×2 max pooling ve 1×1 evrişimle tek kanallı çıkış (ekrandan, 00:25:00).
  - Hoca: gri tonlamaya çevirmek (özellikle gece sahnelerinde) bilgi kaybettirir; her pikseli ayrı sınıflandırmak yavaştır; U-Net, örnek tabanlı (instance) segmentasyon ve Mask R-CNN gibi yaklaşımlar daha pratiktir.
- Tablo verisinde regresyon: yengeç yaşı tahmini
  - Kaggle Crab Age veri seti (yaklaşık 10.000 örnek, 8 öznitelik); hedef değişken (yaş) ortalaması 9,94, standart sapması 3,22, en küçük 1, en büyük 27 (ekrandan, 00:35:00).
  - Tek gizli katmanlı sığ modelden iki gizli katmanlı modele geçiş; MSE ve MAE kayıpları, tam yığın (full-batch) gradyan inişi ve Adam karşılaştırması. En iyi sonuç: Adam, MAE kaybı, öğrenme oranı 0,001, 1000 epoch, batch 256.
  - Korelasyon matrisinde en yüksek ilişki ağırlık öznitelikleri arasında (ör. Weight–Shucked Weight 0,97); yaşla en yüksek ilişki Shell Weight (0,66) (ekrandan, 00:35:00).
- Obezite düzeyi sınıflandırması (7 sınıf)
  - Kategorik değişkenlerin one-hot kodlanmasıyla öznitelik sayısı 17'den 30'a çıktı (ekrandan, 00:45:00).
  - Ağ: girişte 30 birim, 8 adet 128 birimli ReLU katmanı, 7 birimli softmax çıkış; toplam 121.385 parametre; kayıp `sparse_categorical_crossentropy`; SGD ve Adam karşılaştırması (ekrandan, 00:55:00).
  - Adam'ın en iyi ayarı: 100 epoch, öğrenme oranı 0,0005, batch 32 (ekrandan, 01:00:00). SGD daha büyük, Adam daha küçük öğrenme oranlarıyla iyi çalıştı.
- Tweet duygu analizi: frekans öznitelikleriyle lojistik regresyon
  - Her kelimenin olumlu ve olumsuz tweetlerdeki frekansından bir sözlük kurulur; cümle vektörü $[1, \sum \text{poz. frek.}, \sum \text{neg. frek.}]$ olur. Örnek: "Senaryo çok iyi!" için $V = [1, 7, 4]$ (ekrandan, 01:05:00).
  - Ön işleme: gürültü ve durak kelimelerin atılması, kök bulma (stemming), parçalama (tokenization), normalizasyon. Log-loss ve gradyan inişi ile %97'nin üzerinde başarı.
- Banka müşteri kaybı (churn) ikili sınıflandırması (PyTorch)
  - Gereksiz sütunların (kayıt no, müşteri kimliği, soyadı) atılması; cinsiyet için 0/1, kart türü için sıralı (ordinal) kodlama (Silver 0, Gold 1, Platinum 2, Diamond 3), ülke için one-hot; `StandardScaler` ile ölçekleme.
  - Sigmoid çıkışlı tek katmanlı model, ikili çapraz entropi, SGD, 1000 epoch; test doğruluğu 0,9975 (ekrandan, 01:20:00). Öğrenme oranı 0,01, 0,1 ve 1 karşılaştırması.
  - Hoca: dengesiz etikette (yaklaşık 7000'e 2000-3000) tabakalı bölme, K-katlı çapraz doğrulama ve katların karışıklık matrislerinin toplanması önerildi.
- Beyin tümörü MR sınıflandırması (BR35H)
  - 1500 tümörlü, 1500 tümörsüz görüntü; %60/%20/%20 dengeli bölme; 128 × 128 gri tonlamalı giriş; iki evrişim katmanı, 128 birimli tam bağlı katman, 2 çıkış.
  - Adam, Adagrad ve SGD karşılaştırması (10 epoch); ReLU ve Leaky ReLU denemesi. Adam en hızlı yakınsadı; SGD çok yavaş kaldı (ekrandan, 01:25:00 ve 01:30:00).
- Sesten öfke (sinirlilik) tanıma
  - CREMA-D veri setinden öfkeli ve nötr kayıtlar; openSMILE ile 988 öznitelik (456 MFCC + 532 MFCC dışı) çıkarıldı; SVM ile sınıflandırma (ekrandan, 01:40:00).
  - Sonuçlar: öfkeli–nötr %93; öfkeli–öfkeli değil %86; yalnız MFCC %89,74; yalnız MFCC dışı %91,28 (ekrandan, 01:50:00).
  - Hoca: pencerelerin özniteliklerini ortalamak zamansal bilgiyi söndürebilir; ders kapsamında bir derin öğrenme modeli (ör. 1B CNN) beklenir.
- Video duvarı arıza tespiti (CNN)
  - Sabit güvenlik kamerası görüntüsünden ekranların kararmasını tespit etme; kırpma (300 × 600), 3 FPS'e alt örnekleme, kareleri dizilere çevirme, 4 filtre (siyah-beyaz, Sobel X, Sobel Y, gradyan büyüklüğü) (ekrandan, 02:00:00).
  - 2512 görüntü (1520 normal, 992 arızalı); 1607/402/503 eğitim/doğrulama/test; Adam, ReLU ve sigmoid çıkış; gradyan büyüklüğü filtresi ve 4 evrişim + 4 yoğun katmanla %100 test başarısı.
  - Hoca: bu problem öğrenme gerektirmeden histogramdaki siyah piksel oranıyla da çözülebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Nitel ve nicel sonuç birlikte verilmeli
  - Örnek çıktı görüntüleri nitel sonuçtur; mAP, doğruluk, MSE/MAE, karışıklık matrisi gibi sayısal metrikler nicel sonuçtur. Raporda ikisi de bulunmalıdır.
- Veri bölme ve değerlendirme
  - Dengesiz sınıflarda bölme etiket dağılımı gözetilerek (tabakalı) yapılmalıdır. Tek bir %80/%20 bölme şanslı bir test kümesi verebilir; K-katlı çapraz doğrulamada her katın karışıklık matrisi toplanarak tüm veri üzerinde bir karışıklık matrisi elde edilir.
- Eğitim eğrilerinin okunması
  - Kayıp grafikleri epoch sayısına karar vermek için incelenir. Kayıp hâlâ düşüyorsa (ör. Adagrad) eğitime devam edilmelidir; eğri yataylaşmışsa (ör. Adam) kesilebilir.
- Öznitelik ve korelasyon analizi
  - Her şeyi doğrudan makine öğrenmesine bırakmadan önce öznitelikler arası ve öznitelik–etiket korelasyonuna bakılmalıdır; bazen tek bir öznitelik sınıflandırmanın çoğunu açıklar.
- Kategorik verinin kodlanması
  - Çok sayıda sıfır içeren ikili sütunların öğrenmeye katkısı ve öznitelik sayısının ağ karmaşıklığını artırması tartışıldı; tek sütunda sayısal etiketleme ile one-hot kodlama karşılaştırıldı.
- Probleme uygun yöntem seçimi
  - Basit bir eşik/histogram yaklaşımıyla çözülebilen problemlerde derin öğrenme gerekmeyebilir. Ders projesinde ise en az bir derin öğrenme ağının kurulup eğitilmesi beklenir.

## Kısa Tekrar Notları

- Bounding box vektörü: $y = (p_c, b_x, b_y, b_h, b_w, c)$.
- YOLO: ızgara tabanlı, tek geçişli, hızlı nesne tespiti; başarı ölçütü mAP@0.5 ve mAP@0.5:0.95.
- Leaky ReLU, negatif girişlerde de küçük gradyan geçirerek ölü nöron sorununu azaltır.
- `BCEWithLogitsLoss` = sigmoid + ikili çapraz entropi; ayrı sigmoid katmanından sayısal olarak daha kararlıdır.
- Gri tonlamaya çevirmek renk bilgisini atar; gece görüntülerinde kayıp büyüktür.
- Piksel piksel sınıflandırma yavaştır; U-Net, Mask R-CNN gibi segmentasyon mimarileri tercih edilir.
- SGD daha büyük, Adam daha küçük öğrenme oranıyla iyi çalışır; Adam genelde daha hızlı yakınsar.
- Sigmoid çıkış 0,5 eşiğiyle iki sınıfa ayrılır.
- Dengesiz veri: tabakalı bölme, K-katlı çapraz doğrulama, toplam karışıklık matrisi.
- Pencere öznitelikleri ortalanırsa zamansal ayrıntı kaybolabilir; segment öznitelikleri yan yana dizilebilir.
- Basit problemlerde (ör. ekranın kararması) histogram analizi yeterli olabilir.

## Detaylı Açıklamalar

- Nesne tespitinde çıktı yalnız bir sınıf etiketi değil, nesnenin konumunu gösteren bir kutudur. Sunumda gösterilen vektörde $p_c$ kutuda nesne bulunma güvenini, $b_x$ ve $b_y$ kutu merkezini, $b_h$ ve $b_w$ boyutları, $c$ ise sınıfı verir; slayttaki örnekte $p_c = 1$, $c = 3$ ("car") (ekrandan, 00:10:00). YOLO görüntüyü ızgaraya böler; nesnenin merkezini içeren hücre o nesneden sorumludur. Hoca, sunumda yalnız görsel sonuç verildiğini belirterek nesne tespiti literatüründe standart olan mAP (mean Average Precision) değerlerinin, eğitim grafiklerinin ve karışıklık matrisinin raporlanmasını istedi.
- Şerit algılamada CULane veri setinin hem şerit işaret noktaları (her satırda bir şeridin $x, y$ koordinat çiftleri) hem de ikili segmentasyon maskeleri vardır (ekrandan, 00:20:00). Sunumdaki ilk model 5×5 çekirdekli basit evrişim–ReLU–max pooling bloklarından oluşuyordu; ikinci model 3×3 evrişim, batch normalization ve Leaky ReLU bloklarıyla $3 \times 320 \times 800$ girişten $1 \times 80 \times 200$ çıkış maskesine iniyordu (ekrandan, 00:25:00). Gece sahnelerinde başarı düşük kaldı. Hoca, gri tonlamanın bilgi kaybettirdiğini ve piksel bazında sınıflandırmanın, U-Net ve örnek tabanlı segmentasyon yöntemlerinden önceki dönemin yavaş bir yaklaşımı olduğunu söyledi; etiketlerdeki koordinat bilgisiyle Mask R-CNN gibi yöntemlerin daha pratik olacağını belirtti.
- Kategorik veri kodlaması tartışmasında obezite veri setindeki one-hot sütunlar (ör. `SMOKE_no`, `SMOKE_yes`, `MTRANS_*`) ele alındı (ekrandan, 00:45:00). Hoca, büyük çoğunluğu sıfır olan bir sütunun ağ derinleştikçe etkisini yitirebileceğini ve öznitelik sayısının artmasının ağ karmaşıklığını artırdığını söyleyerek kategorileri tek sütunda sayısal etiketlerle (1, 2, 3, 4) kodlamayı önerdi. Öğrenci ise tek sütunda 4'ün 1'den "büyük" algılanacağını, kategoriler arasında böyle bir sıralama olmadığını belirtti. Hoca bunun denenerek görülmesi gerektiğini söyledi.
- Obezite modelinde 30 girişli bir giriş katmanı, 8 adet 128 birimli gizli katman ve 7 birimli softmax çıkışı vardır; parametre sayısı $930 + 3968 + 7 \cdot 16512 + 903 = 121.385$ olarak doğrulanır (ekrandan, 00:55:00). Etiketler 0–6 tam sayıları olduğu için `sparse_categorical_crossentropy` kullanıldı.
- Tweet duygu analizinde sözlükteki her kelimenin olumlu (1) ve olumsuz (0) sınıftaki frekansı tutulur. "Senaryo çok iyi!" cümlesi için olumlu frekanslar $1 + 3 + 3 = 7$, olumsuz frekanslar $1 + 3 + 0 = 4$ olduğundan $V = [1, 7, 4]$ olur; ilk bileşen sapma (bias) terimidir (ekrandan, 01:05:00). Bu üç boyutlu vektör sigmoid çıkışlı lojistik regresyona verilir ve 0,5 eşiğiyle sınıf atanır.
- Banka müşteri kaybı çalışmasında eğitim döngüsü ileri geçiş, kayıp hesabı, `loss.backward()`, `optimizer.step()` ve `optimizer.zero_grad()` adımlarından oluşur; testte sigmoid çıkışı `round()` ile 0/1'e çevrilip doğruluk hesaplanır (ekrandan, 01:15:00). 1000 epoch sonunda kayıp, öğrenme oranı 0,01 için yaklaşık 0,109, 0,1 için 0,0146, 1 için 0,0071'e indi (ekrandan, 01:20:00).
- Beyin tümörü çalışmasında üç optimizasyon algoritmasının karışıklık matrisleri karşılaştırıldı (ekrandan, 01:30:00). 600 test görüntüsünde Adam 292 + 288 = 580 doğru (%96,7), Adagrad 256 + 285 = 541 doğru (%90,2), SGD 225 + 195 = 420 doğru (%70) verir. Kayıp grafiklerinde Adam hızla düşüp yataylaştı, Adagrad zikzaklı ilerledi, SGD ise 10 epoch boyunca doğrusal ve yavaş indi (ekrandan, 01:25:00).
- Ses duygu tanımada openSMILE ile güç, ses şiddeti, sıfır geçiş oranı, seslilik olasılığı, MFCC, LPC ve F0 başlıklarında 988 öznitelik çıkarıldı (ekrandan, 01:40:00). Kayıt 100 ms'lik pencerelere bölünüp her öznitelik için ortalama, medyan, standart sapma, üçüncü moment, en küçük ve en büyük gibi istatistikler alındı; böylece kayıt süresinden bağımsız sabit sayıda sütun elde edildi. Hoca, bu ortalamanın vurgulu kelimeler gibi zamansal ayrıntıyı söndürebileceğini; iki sınıflı ve kolay ayrılan bir problemde sorun çıkmasa da çok sınıflı durumda segment özniteliklerinin yan yana dizilmesinin daha iyi olabileceğini söyledi.
- Video duvarı çalışmasında kırpılmış ve 3 FPS'e indirilmiş karelere gradyan büyüklüğü filtresi uygulanınca başarı arttı. Hoca, ekran kararınca siyah piksel sayısının arttığını, bu yüzden histogram eşiğiyle öğrenmesiz bir çözümün de mümkün olduğunu vurguladı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
