# Ders 8 Çalışma Özeti

## Genel Konular

- Ayrıklaştırma (discretization)
  - Sürekli (sayısal) bir özelliğin değer aralığı bölgelere ayrılır ve değerin kendisi yerine bölgenin etiketi özellik olarak kullanılır. Slayttaki örnekte yaş değerleri $[5,15]$, $[16,24]$ ve $[25,67]$ aralıklarına ayrılmıştır (ekrandan, 00:15:00).
  - Slayta göre ayrıklaştırma, birliktelik kuralları ve yalnız ayrık veri kabul eden bazı sınıflandırma algoritmaları için zorunludur.
  - İşlem adımları: özelliği sıralama, aday kesme noktası ya da komşu aralıkları seçme, uygun bir ölçütle değerlendirme ve ölçüt sağlanana kadar tekrar (ekrandan, 00:15:00).
  - Gözetimsiz yöntemler: eşit genişlik (equal width) ve eşit frekans (equal frequency).
  - Ayrıklaştırma bir veri ön işleme adımıdır ve başarıyı olumlu yönde etkilemesi gözetilir.
- Makine öğrenmesinin beş ana başlığı (mind map, ekrandan, 00:25:00)
  - Gözetimli öğrenme: sınıflandırma (k-NN, Naive Bayes, lojistik regresyon, SVM, karar ağaçları) ve regresyon (doğrusal, polinomsal, Ridge/Lasso).
  - Gözetimsiz öğrenme: kümeleme (K-Means, DBSCAN, agglomerative, mean shift, fuzzy C-means), birliktelik kuralı öğrenme (Apriori, FP Growth, Eclat), boyut indirgeme (PCA, LDA, t-SNE, SVD, LSA).
  - Pekiştirmeli öğrenme: Q-Learning, SARSA, DQN, A3C, genetik algoritma.
  - Topluluk (ensemble) öğrenme: bagging (Random Forest), boosting (AdaBoost, XGBoost, LightGBM, CatBoost), stacking.
  - Yapay sinir ağları ve derin öğrenme: algılayıcılar, CNN, RNN (LSTM, GRU), GAN, otokodlayıcılar.
- Sınıf sayısı ve başarı
  - Sınıf sayısı arttıkça birbirine benzeyen sınıflar ortaya çıkar, ayırt edicilik zorlaşır ve başarı genelde düşer.
  - Zamanla yeni sınıflar türeyebilir (örneğin yeni bir ağ saldırısı türü). Bilinen sınıfların yanına "diğerleri" sınıfı konur, yeni sınıf netleşince etiketlenip sisteme öğretilir.
- Sınıflandırıcıların karar verme hızı
  - Karar ağacında test süresini belirleyen en kritik etken ağacın derinliğidir.
  - Naive Bayes olasılıksal bir sınıflandırıcıdır: eğitim verisinden dağılım parametrelerini çıkarır, yeni örnek için her sınıfa ait olma olasılığını hesaplar.
  - SVM ikili sınıflandırıcıdır; çok sınıflı problemde bire-karşı-hepsi ya da ikili karşılaştırma (turnuva) yaklaşımı kullanılır.
  - k-NN'de eğitim yoktur, test karmaşıklığını örnek sayısı ve özellik sayısı belirler; k genelde tek sayı (1, 3, 5, 7) seçilir.
- Akıllı SMS kutusu örneği
  - Spam tespiti için içerik (kelimeler, düzenli ifadeler), beyaz liste/kara liste ve gönderen numarası birlikte kullanılabilir.
  - Mesajlar spam/değil yerine birden çok kategoriye ayrılabilir (tek kullanımlık şifreler, kargo bildirimleri, reklamlar, puan bildirimleri, kamu kurumu mesajları).
- ROC eğrisi
  - X ekseni yanlış pozitif oranı, Y ekseni doğru pozitif oranıdır. Eğrinin altındaki alan ne kadar büyükse o kadar iyidir.
  - Parametre seçiminde (k-NN'de k, düşme tespitinde eşik) eğrinin düzleşmeye başladığı nokta seçilir.
- Dengesiz veri ve accuracy
  - Dengesiz veride accuracy yanıltıcıdır; precision, recall ve F-ölçütü kullanılmalıdır.
- Regresyon ve metrikleri
  - Polinom derecesi yüksekse aşırı öğrenme riski artar.
  - Metrikler: MSE, RMSE, MAE, MAPE. Trafik akış hızı tahmininde MAE ile MAPE birlikte kullanılmalıdır.
- Kümeleme
  - K-Means'te küme sayısı dirsek (elbow) yöntemiyle seçilir; başlangıç merkezleri sonucu etkiler; birbirine çok yakın kümeler birleştirilebilir.
  - Gauss karışım modeli ortalamanın yanında standart sapmayı da kullanır ve her örnek için kümeye ait olma olasılığı verir.
  - Hiyerarşik kümeleme: bölücü (yukarıdan aşağı) ve birleştirici (agglomerative, aşağıdan yukarı).
- Pekiştirmeli öğrenme, topluluk öğrenme, yarı gözetimli öğrenme, anomali tespiti
- Yapay sinir ağları ve derin öğrenme
  - CNN uzamsal, RNN (LSTM, GRU) zamansal ilişki kurar; otokodlayıcı boyut indirgeme ve öznitelik öğrenme için, GAN sentetik veri üretimi için kullanılır.
  - Hiperparametreler: dropout, öğrenme oranı, optimize edici, aktivasyon fonksiyonu, batch boyutu, epoch sayısı, nöron ve katman sayısı, bağlantı biçimi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınıf uzayı geniş problemler
  - Az sınıflı problemlerde başarı belli bir noktaya gelmiştir. Karmaşık aktivite tanıma gibi çok sınıflı problemlerde başarıyı artırmak için ek çözümler gerekir.
- Karar ağacının en kötü durum derinliği
  - Hocaya göre en kötü durumda ağaç tek tarafa yığılır ve derinlik özellik sayısı $d$ kadar olur. Bu yüzden karar ağacı karar verme hızı bakımından avantajlıdır.
- Mobil cihazda hibrit yaklaşım
  - Beyaz liste/kara liste gibi basit kurallar makine öğrenmesiyle birleştirilince karar süreci hızlanır, başarı artar. Telefon ve akıllı saatte hibrit yaklaşımlar daha az karmaşık ve daha az enerji tüketir.
- ROC eğrisi ve yanlış pozitifler
  - Doğru pozitif ile yanlış pozitif arasındaki ödünleşimi gösterir. Sahtekârlık tespitinde günde yaklaşık 15 milyon işlemde %1 yanlış pozitif bile 150 bin hatalı alarm demektir.
- Dengesiz veride accuracy kullanmamak
  - 1 milyon normal işlemi doğru bilip 100 sahte işlemin 50'sini bilen bir sistemin accuracy değeri %99,9'un üzerindedir, ama sahtekârlık başarısı yalnızca %50'dir.
- MAE ve MAPE'yi birlikte kullanmak
  - Aynı 6 km/sa sapma 30 km/sa hızda %20, 60 km/sa hızda %10 hata eder.
- Varsayılan parametrelerle yetinmemek
  - Algoritmaların hiperparametreleri denenmelidir. Mobil teknolojilerde iş yükünü azaltan en küçük parametre seçilmelidir (örneğin Random Forest'ta başarıyı düşürmeyen en az ağaç sayısı).
- Sınav öncesi bakılması önerilen kavramlar
  - Hoca karışıklık matrisini, TP/TN/FP/FN'yi, precision/recall'u ve regresyon metriklerini önerdi. K-Means'te başlangıç merkezlerinin akıllıca nasıl seçildiğine de bakılmasını istedi.

## Kısa Tekrar Notları

- Ayrıklaştırma: sürekli değer → aralık etiketi. Yöntemler: eşit genişlik, eşit frekans, yüzdelikler.
- Özellik seçiminde $2^M-1$ alt küme vardır. Hepsini denemek pahalı olduğu için filter ve wrapper yöntemleri kullanılır.
- Makine öğrenmesinin beş başlığı: gözetimli, gözetimsiz, pekiştirmeli, topluluk, sinir ağları/derin öğrenme.
- Sınıflandırma ayrık, regresyon sürekli çıktı tahmin eder.
- İki sınıfta tek olasılık ve 0,5 eşiği yeter. Çok sınıfta en yüksek olasılıklı sınıf seçilir.
- SVM çok sınıflı: bire-karşı-hepsi ya da ikili karşılaştırma.
- k-NN: k = 1 en yakın komşudur; genelde 3, 5 ya da 7 seçilir.
- ROC: X = FP oranı, Y = TP oranı. İdeal nokta TP = 1, FP = 0'dır. 45 derece çizgisinin üstündeki eğriler istenir.
- Dengesiz veri → accuracy yerine precision, recall, F-ölçütü.
- Regresyon metrikleri: MSE, RMSE, MAE, MAPE.
- Dirsek yöntemi: X ekseni k, Y ekseni toplam uzaklık (hata). k örnek sayısına eşitse hata sıfırdır.
- GMM: ortalama + standart sapma, olasılıklı (yumuşak) üyelik.
- Yarı gözetimli: verinin bir kısmı etiketlidir, çoğu zaman yalnız tek sınıf (örneğin yalnız sağlıklılar) bilinir. Buradan anomali tespiti yapılır.
- GAN: üretici ve ayırıcı ağ dengeli olmalıdır. Az örnekli sınıflar için veri artırımında kullanılır.
- Dropout ve düzenlileştirme aşırı öğrenmeyi önler. Öğrenme oranı adım büyüklüğüdür.
- Batch boyutu çoğu zaman 64, 128 ya da 256 seçilir; büyük batch bellek sorunu çıkarabilir.
- Epoch sayısı için doğrulama doğruluğuna bakılır. Eğitim doğruluğu yüksek ama doğrulama kötüyse aşırı öğrenme vardır. İkisi de kötüyse özellik kümesi yetersizdir.

## Detaylı Açıklamalar

- **Ayrıklaştırma neden yapılır?** Özellik uzayı büyük olduğunda ayrıntı bilgi dağılır ve etkisini kaybeder. Değerleri anlamlı aralıklara toplamak modelin bu aralıkların etkisini öğrenmesini kolaylaştırır. Hoca COVID örneğini verdi: 43 ile 63 yaş arasındaki tek tek değerlerin değil, yaş aralıklarının belirgin etkisi vardır. Aynı işlem kategorik veride de yapılabilir: sokak yerine ilçe, ilçe yerine il kullanmak ya da yaşı bebek/çocuk/genç gibi gruplara ayırmak. Aralık sınırları verinin yayılımına, gereken grup sayısına ve alandaki ön bilgiye göre seçilir. Eşit genişlikte aralıklar aynı uzunluktadır (hoca 64-67, 67-70, 70-73 gibi bir slayt gösterdi). Eşit frekansta her aralığa yaklaşık aynı sayıda örnek (örneğin dörder) düşer; son aralık tam denk gelmeyebilir. <!-- BELİRSİZ: Eşit genişlik/eşit frekans slaytı karelere düşmedi; aralık değerleri altyazıdan alındı. -->
- **Karar ağacı, Naive Bayes ve hız:** Karar ağacında test sırasında kökten yaprağa kadar her düğümde bir karşılaştırma yapılır, bu yüzden süreyi derinlik belirler. Hoca en kötü durumda derinliğin özellik sayısı $d$ olduğunu ve bunun sevilmeyen dengesiz ağaç olduğunu söyledi. Pratikte daha dengeli ağaçlar oluşur. Yaygın kullanılan C4.5'tir, Weka'da adı J48'dir. Naive Bayes iki sınıflı problemde tek olasılık hesaplar ve 0,5 eşiğiyle karar verir. Çok sınıflı problemde olasılıklar dağılır (0,4, 0,3 gibi) ve en yükseği seçilir.
- **Akıllı SMS kutusu:** SMS'te içerik analizi (büyük harf sıklığı, belli kelimeler, düzenli ifadeyle mesaj sonundaki "B" ile başlayan kodlar) yanında daha katı kurallar da kullanılabilir: kişinin rehberinde olmak, beyaz liste, kara liste, numaranın bir servis üzerinden sorgulanması. Hocanın bir çalışmasında mesajlar 5-6 kategoriye ayrıldı. Naive Bayes ve karar ağacı beyaz/kara liste ile birleştirildi ve hibrit bir model ortaya çıktı.
- **ROC ile parametre seçimi:** k-NN'de k = 1, 3, 5, 7, 9, 11 için elde edilen (FP, TP) noktaları eğri üzerine yerleştirilir. 5'ten 7'ye geçerken TP oranı az, FP oranı çok arttığı için k = 5 seçmek akıllıcadır. k = 11 en yüksek TP oranını verse de FP oranı çok kötüdür. Düşme tespitinde eğri üzerindeki noktalar eşik değerleridir (1,3; 1,5; 1,7; 2,1; 2,5) ve hoca 1,7 ya da 2,1'i aday gösterdi (ekrandan, 01:25:00).
- **Dirsek yöntemi ve GMM:** Dirsek grafiğinde X ekseni küme sayısı k, Y ekseni her örneğin kendi küme merkezine uzaklıklarının toplamıdır (hata). k = 1'de hata en büyüktür, k örnek sayısına eşit olunca sıfırdır (ekrandan, 01:30:00). Hatanın hızlı düşüşünün bittiği nokta optimum k'dır. Dirsek keskin değilse karar zorlaşır. K-Means yalnız ortalamayı kullanır: {1, 5}, {2, 4} ve {3, 3} gruplarının üçünün de merkezi 3'tür. GMM standart sapmayı da kullandığı için bu grupları ayırt eder ve örneğin bir kümeye 0,8, diğerine 0,2 olasılıkla ait olduğunu söyler.
- **Otokodlayıcı:** Girdi ile çıktı aynı tutulur. Ara katmanlar daraltılır (örneğin 100 → 50 → 25) ve ağ girdiyi en az hatayla yeniden üretmeyi öğrenir. Böylece daha az boyutlu, elle üretilemeyecek öznitelikler elde edilir. Hocanın deneyimine göre tekrarlı sensör verisinde (aktivite tanıma) çok başarılı olmadı, daha kategorik/ayrık verili ağ saldırısı sınıflandırmasında daha iyi sonuç verdi.
- **Derin öğrenme hiperparametreleri:** Öğrenme oranı çok büyükse global minimum kaçırılabilir. Çok küçükse hedefe çok geç ulaşılır ve lokal minimuma takılma riski artar. Adam, AdaDelta gibi optimize ediciler kullanılır. ReLU son dönemde en çok tercih edilen aktivasyondur ve sigmoid'deki kaybolan gradyan sorununu genelde yaşamaz. GRU'da 2, LSTM'de 3 kapı vardır.
- **Mobilde kullanım:** Eğitim maliyetli olsa da bulutta yapılır. Model parametreleri telefona aktarılır ve telefonda yalnız çıkarım çalıştırılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
