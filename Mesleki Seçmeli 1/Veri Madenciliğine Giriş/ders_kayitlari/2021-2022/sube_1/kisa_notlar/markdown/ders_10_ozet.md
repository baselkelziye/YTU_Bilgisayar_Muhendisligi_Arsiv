# Ders 10 Çalışma Özeti


## Genel Konular

- Önceki dersin tekrarı: model değerlendirme
  - Doğruluk (accuracy) dışında sensitivity/recall, precision ve F1 skoru gibi ölçüler, özellikle sınıflar arasında büyük fark olan dengesiz (imbalanced) verilerde modeli farklı açılardan değerlendirmeye yarar.
  - Karışıklık matrisinde (confusion matrix) köşegen doğru sınıflananları gösterir; çok sınıflı durumda ölçüler mikro ve makro ortalama ile bulunur.
  - Regresyonda (sürekli değer tahmini) sınıf olmadığı için ortalama mutlak hata (MAE) ve ortalama karesel hata (MSE) kullanılır.
  - Holdout: veri rastgele iki bağımsız kümeye ayrılır; slaytta eğitim için 2/3, test için 1/3 örneği verilir (ekrandan, 00:05:18). Random sampling, holdout'u k kez tekrarlayıp doğrulukların ortalamasını almaktır.
  - k-katlı çapraz doğrulama (k-fold cross-validation): veri k parçaya (fold) bölünür, her seferinde bir parça test, kalanlar eğitim için kullanılır. Leave-one-out'ta k, örnek sayısına eşittir; stratified çapraz doğrulamada her parçadaki sınıf dağılımı ilk veriye yakın tutulur (ekrandan, 01:26:03).
  - İki modelin hata oranları arasındaki farkın istatistiksel olarak anlamlı olup olmadığı t-testi ile sınanır; bu kısım derste anlatılmadı.
- ROC eğrisinin kurulması (ekrandan, 00:10:18)
  - Model çıktısı farklı eşiklerden (threshold) kesilir; eşiğe eşit ya da büyük olanlara pozitif, küçüklere negatif denir. Her eşik için $TPR = TP/(TP+FN)$ ve $FPR = FP/(FP+TN)$ hesaplanıp grafiğe işaretlenir.
  - Derste çözülen eşik $0.76$: $TP=3$, $FP=4$, $TN=1$, $FN=2$; $TPR = 3/5 = 0.6$, $FPR = 4/5 = 0.8$.
  - Küçük veride elle çizilen ROC eğrisi basamaklı çıkar; araçlar eğriyi genelde yumuşatarak çizer.
- Topluluk (ensemble) yöntemleri (ekrandan, 00:15:18 ve 00:20:18)
  - Amaç doğruluğu artırmaktır. $M_1, \dots, M_k$ modelleri öğrenilir, yeni örnek için oyları birleştirilerek geliştirilmiş bir $M^*$ modeli elde edilir.
  - Adımlar: orijinal eğitim verisi $D$'den $D_1, \dots, D_t$ veri kümeleri üretilir, her birinden bir sınıflandırıcı $C_i$ eğitilir, sınıflandırıcılar $C^*$ olarak birleştirilir.
  - En basit birleştirme çoğunluk oylamasıdır (majority voting).
  - Slayttaki üç tür: bagging (tahminlerin ortalaması), boosting (ağırlıklı oylama), ensemble (heterojen sınıflandırıcıları birleştirme).
- Topluluğun neden işe yaradığı: 25 sınıflandırıcı örneği
  - Her biri $\varepsilon = 0.35$ hata oranlı 25 bağımsız sınıflandırıcının çoğunluk oylaması, en az 13'ü yanılırsa yanılır: $\sum_{i=13}^{25} \binom{25}{i} \varepsilon^i (1-\varepsilon)^{25-i} \approx 0.06$.
  - Gerçekte sınıflandırıcılar aynı veriden türediği için bağımsız değildir, benzer örneklerde yanılırlar; hata bu kadar düşmez. Sınıflandırıcı sayısının optimumu deneyerek bulunur.
- Topluluk sınıflandırıcı kurmanın iki yolu (ekrandan, 00:25:18)
  - Eğitim kümesini değiştirmek: orijinal veriden yeniden örnekleme (resampling) ile çok sayıda eğitim kümesi (satır alt kümeleri) üretilir. Örnekler: bagging ve boosting.
  - Girdi özniteliklerini değiştirmek: satırlar aynı kalır, her eğitim kümesi için özniteliklerin (sütunların) bir alt kümesi seçilir. Birbirine çok bağlı (gereksiz, redundant) öznitelik içeren verilerde iyi çalışır. Örnek: random forest.
- Bagging (bootstrap aggregation)
  - Her turda veriden tekrar seçmeye izin vererek (bootstrap) aynı boyutta bir örneklem çekilir, ondan bir model öğrenilir; test örneği tüm modellere sorulur ve oylanır.
  - Modeller matematiksel olarak birleştirilmez ve ağırlıklandırılmaz; her modelin oyu eşittir.
  - Genelde daha yüksek doğruluk verir; dezavantajı model sayısı kadar fazla iş yüküdür. Alt kümelere gürültü gelmeyebildiği için gürültüye karşı daha dayanıklıdır.
- Bagging örneği (ekrandan, 01:00:00, 01:05:00, 00:45:18)
  - Veri: $x = 0.1, 0.2, \dots, 1.0$; $y = 1, 1, 1, -1, -1, -1, -1, 1, 1, 1$. Taban sınıflandırıcı tek iç düğümlü karar ağacıdır (decision stump).
  - Tek bir stump en fazla %70 doğruluk verir ($x \le 0.35$ ya da $x \le 0.75$ eşiği).
  - 10 bootstrap turunun stump'larının tahminleri toplanır, toplamın işareti sınıf olur; bütün noktalar doğru sınıflanır (%70'ten %100'e).
- Boosting ve AdaBoost (ekrandan, 01:15:00, 01:20:00, 01:05:18)
  - Her eğitim örneğine bir ağırlık verilir; $k$ sınıflandırıcı sırayla öğrenilir. $M_i$ öğrenildikten sonra ağırlıklar, $M_{i+1}$'in $M_i$'nin yanlış sınıfladığı örneklere daha çok dikkat etmesi için güncellenir.
  - Son model oyları birleştirir; her sınıflandırıcının oyunun ağırlığı doğruluğunun fonksiyonudur. Bagging'den farkı budur.
  - AdaBoost: ağırlıklar $w_i = 1/N$ ile başlar; her turda $err_m = \sum w_i(\text{yanlışlar}) / \sum w_i$, $\alpha_m = \frac{1}{2}\ln\frac{1-err_m}{err_m}$; doğru sınıflananlar $w_i e^{-\alpha_m}$, yanlışlar $w_i e^{\alpha_m}$ ile çarpılır ve ağırlıklar toplamı 1 olacak şekilde normalize edilir.
  - Oyuncak örnekte $\varepsilon_1 = 0.30 \Rightarrow \alpha_1 \approx 0.42$; $\varepsilon_2 = 0.21$, $\alpha_2 \approx 0.65$; $\varepsilon_3 = 0.14$, $\alpha_3 = 0.92$.
  - Hata oranı 0.5'ten kötü olan sınıflandırıcı kullanılmaz; iterasyon sayısı $M$ ile ya da daha iyi sınıflandırıcı bulunamayınca durulur.
- AdaBoost örneği (ekrandan, 01:11:03)
  - Bagging örneğindeki aynı veride ağırlıklar ilk turda hepsi 0.1'dir. İlk turda yanlış sınıflanan $x = 0.1, 0.2, 0.3$'ün ağırlığı 0.311'e çıkar, diğerleri 0.01'e iner. İkinci tur örneklemi bu ağırlıklı noktalara yoğunlaşır.
- Random forest (ekrandan, 01:16:03)
  - Topluluktaki her sınıflandırıcı bir karar ağacıdır; sınıflandırmada her ağaç oy verir, en çok oy alan sınıf döner.
  - Forest-RI (random input selection): her düğümde bölme için aday olarak rastgele $F$ öznitelik seçilir.
  - Forest-RC (random linear combinations): var olan özniteliklerin doğrusal birleşimi olan yeni öznitelikler üretilir.
  - Slayta göre doğruluğu AdaBoost'a yakındır, hatalara ve aykırı değerlere karşı daha dayanıklıdır, bagging ve boosting'den hızlıdır.
- Topluluk yöntemlerinin deneysel karşılaştırması (ekrandan, 01:21:03)
  - UCI veri kümelerinde tek karar ağacı ile 50 karar ağaçlı bagging, boosting ve random forest 10-katlı çapraz doğrulamayla karşılaştırılır; topluluk yöntemleri çoğu veri kümesinde daha başarılıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bagging ile boosting arasındaki temel fark
  - Bagging'de her sınıflandırıcının oyu eşittir. Boosting'de her sınıflandırıcının hata oranından bir $\alpha$ hesaplanır ve oylar bu ağırlıkla birleştirilir.
- Boosting'in mantığı
  - Doğru sınıflananların ağırlığı azaltılır, yanlış sınıflananlarınki artırılır. Böylece bir sonraki sınıflandırıcı önceki sınıflandırıcının bulamadıklarına yoğunlaşır, "zor bulunanları bulmaya zorlanır".
- Teorik hata düşüşü gerçekte görülmez
  - 25 sınıflandırıcıyla hata 0.35'ten 0.06'ya iner gibi görünür; ama sınıflandırıcılar bağımsız olmadığından gerçekte bu kadar düşmez. Çok az ya da çok fazla sınıflandırıcı birleştirmek de fayda etmez.
- Topluluk yöntemleri ne zaman denenir?
  - Veri dengesizse, gürültü çoksa ya da tek sınıflandırıcının doğruluğu (eğitim verisinde bile) düşük kalıyorsa (örneğin %70 civarı).
- Random forest gürültülü veride iyi ve hızlı çalışır
  - Ağaçlar küçük tutulur, öznitelik alt kümeleri kullanılır; gürültünün seçilen alt kümelere girme ihtimali düşüktür.
- Veri madenciliği algoritmaları deterministik ve optimal değildir
  - Karar ağacı optimal ağacı bulmaz, naive Bayes veriye çok bağımlıdır; algoritmalar deneyerek, optimizasyonla ilerler.

## Kısa Tekrar Notları

- ROC: her eşik için $TPR = TP/(TP+FN)$, $FPR = FP/(FP+TN)$; eşik 0.76'da $(FPR, TPR) = (0.8, 0.6)$.
- Ensemble = birden fazla modelin oylarını birleştirerek doğruluğu artırmak.
- Eğitim kümesini değiştiren yöntemler: bagging, boosting (satır seçimi). Öznitelikleri değiştiren: random forest (sütun seçimi).
- Bagging = bootstrap (tekrarlı seçim) + eşit oylu çoğunluk oylaması.
- Boosting = örnek ağırlıkları + sınıflandırıcı ağırlığı $\alpha$ + ağırlıklı oylama. En yaygını AdaBoost.
- $\alpha_m = \frac{1}{2}\ln\frac{1-err_m}{err_m}$: hata küçüldükçe $\alpha$ büyür.
- Doğru sınıflananlar $e^{-\alpha}$, yanlışlar $e^{\alpha}$ ile çarpılır, sonra normalize edilir.
- Decision stump: tek iç düğümlü karar ağacı; örnek veride tek başına en fazla %70, bagging ile %100.
- Random forest: Forest-RI (her düğümde rastgele $F$ öznitelik) ve Forest-RC (özniteliklerin doğrusal birleşimi).
- 25 bağımsız sınıflandırıcı, $\varepsilon = 0.35$: topluluk hatası $\approx 0.06$ (yalnız bağımsızlık varsayımıyla).

## Detaylı Açıklamalar

- **ROC örneği.** Sınıflar sırasıyla $+, -, +, -, -, -, +, -, +, +$, skorlar $0.25, 0.43, 0.53, 0.76, 0.85, 0.85, 0.85, 0.87, 0.93, 0.95$'tir (ekrandan, 00:10:18). Eşik 0.76 seçilince ilk üç kayıt negatif, kalan yedi kayıt pozitif tahmin edilir. İlk üçten negatif olan bir tane (TN = 1), pozitif olan iki tane (FN = 2) vardır; son yedide üç pozitif (TP = 3), dört negatif (FP = 4) vardır. Toplam pozitif 5, toplam negatif 5 olduğundan $TPR = 0.6$, $FPR = 0.8$. Her eşik için bu nokta işaretlenip birleştirilince ROC eğrisi çıkar.
- **Ensemble'ın geometrik sezgisi.** Hoca uzayı mavi ve kırmızı noktalarla çizdi. Her sınıflandırıcı verinin rastgele bir alt kümesini görür ve o alt kümeyi en iyi ayıran sınırı bulur. Test noktası her sınıflandırıcıya sorulur, en çok oy alan sınıf seçilir. Uzay tek bir sınırla bölünmek yerine farklı alt kümelerden farklı biçimlerde bölünür; küçük alt kümelere gürültü gelmezse daha iyi sınırlar bulunur.
- **Öznitelik seçimiyle topluluk.** Hoca hava sıcaklığı ile yağış gibi birbiriyle ilişkili özniteliklere örnek verdi. Birbirine bağlı çok sayıda öznitelik varsa sınıflandırıcı onlardan fazla etkilenir ve tek başına etkili olan bir özniteliği gözden kaçırabilir. Her seferinde farklı öznitelik alt kümesi seçilince bu etki azalır. 500 satır ve 100 öznitelikli bir veride her seferinde 10 öznitelik seçilirse her eğitim kümesi 500 satır ve 10 sütun olur.
- **Bagging örneğinin turları** (ekrandan, 00:40:18). Tur 1 örneklemi $0.1, 0.2, 0.2, 0.3, 0.4, 0.4, 0.5, 0.6, 0.9, 0.9$'dur; kural $x \le 0.35 \Rightarrow 1$, $x > 0.35 \Rightarrow -1$ ve bu örneklemde %80 doğruluk verir. Tur 2 örnekleminde $0.6$ ve $0.7$ yoktur, $1.0$ üç kez seçilmiştir; on örnekten sekizi $+1$ olduğu için slayttaki kural iki tarafa da $1$ der (%80). Tur 1, 3, 4, 5'te sınır 0.3-0.35, tur 6-9'da 0.75'tir ($x \le 0.75 \Rightarrow -1$), tur 2 ve 10 her şeye $1$ der. Tahminlerin toplamı $2, 2, 2, -6, -6, -6, -6, 2, 2, 2$, işaretleri gerçek sınıflarla aynıdır (ekrandan, 00:45:18).
- **AdaBoost'ta ağırlığın etkisi.** Oyuncak örnekte ikinci sınıflandırıcı da üç örneği yanlış sınıflar, ama bu örneklerin ağırlığı düşük olduğundan ağırlıklı hatası (0.21) birincininkinden (0.30) küçüktür. Eşit ağırlıklı veride kötü görünen bir sınıflandırıcı, önceki sınıflandırıcıların bulamadıklarını bulduğu için ağırlıklı veride önemli hale gelir.
- **Doğrusal sınırlar.** Şimdiye kadar görülen sınıflandırıcılar (karar ağacı gibi) "büyüktür/küçüktür" ile eksenlere paralel, doğrusal sınırlar çizer. Çok dereceli polinom sınırlar mümkündür, ama çok sütunlu veride katsayılarını bulmak algoritmayı ağırlaştırır. SVM ve yapay sinir ağları ileride görülecek.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
