# Ders 4 Çalışma Özeti

## Genel Konular

- Sıralı örüntü madenciliği (sequential pattern mining): kavramlar, veri formatı, örnek ve GSP algoritması.
- Makine öğrenmesine genel bakış: gözetimli (supervised), gözetimsiz (unsupervised), boyut indirgeme (dimension reduction), sığ (shallow) ve derin (deep) modeller.
- Gözetimli öğrenmenin aşamaları: eğitim (training), test, doğruluk (accuracy) ve diğer ölçütler.
- Sınıflandırıcılar: karar ağacı (decision tree), kural tabanlı sınıflandırma (class association rules), Naive Bayes, k en yakın komşu (k-nearest neighbor, kNN).
- Aşırı öğrenme (overfitting) ve çapraz doğrulama (cross-validation).

## Hocanın Özellikle Vurguladığı Kısımlar

- Birliktelik kuralları işlem içindeki sırayı dikkate almaz. Sıralı örüntü madenciliği zamanı ve sırayı dikkate alır.
- Sıralı örüntü madenciliği web'de log dosyalarındaki popüler sıralı aksiyonları bulmak için çok kullanılıyor.
- Churn analizinde "next best action": terk etmek üzere olan müşteriye uygulanacak en başarılı aksiyon zinciri.
- Bu bölüm bir tekrar (overview). Makine öğrenmesi derinlemesine işlenmeyecek. Amaç web madenciliğindeki kullanımlar.
- Web madenciliğinde makine öğrenmesi çoğunlukla clickstream verisinden çıkarılan öz nitelikler üzerinde çalışır.
- Eğitim ve test verisinin dağılımları benzer olmalı. Aksi halde iyi bir öğrenme bile kötü test sonucu verir.
- Aynı algoritmada bile parametreler değişince sonuç değişir. Parametreleri deneyerek en başarılı kullanım aranmalı.
- Hoca ders sonrası ofis saati yapıyor. Soru için ayrı Zoom toplantısı istenebilir.

## Kısa Tekrar Notları

- Sequence: $s = \langle a_1 a_2 \ldots a_r \rangle$. Her $a_i$ bir eleman (element) ve bir öğe kümesidir (itemset).
- Size: sequence içindeki eleman sayısı.
- Length: sequence içindeki toplam öğe sayısı. $k$-sequence, length değeri $k$ olan sequence.
- Örnek: $\langle \{3\} \{4,5\} \{8\} \rangle$. Size 3, length 4. Bu bir 4-sequence.
- Alt sequence (subsequence): $s_1$'in her elemanı, $s_2$'de sırası korunarak ayrı bir elemanın alt kümesi olmalı.
- Sıralı örüntü: minsup oranında müşterinin sequence'ında bulunan sequence.
- GSP, Apriori'ye benzer: seviye seviye aday üretir, veritabanını tarar, sayar, sık olanları tutar.
- Gözetimli öğrenme: etiketli veriden model öğrenilir, yeni verinin etiketi tahmin edilir.
  - Sınıflandırma: kategorik etiket.
  - Regresyon: sayısal değer.
- Gözetimsiz öğrenme: etiket yok. Kümeleme (clustering), birliktelik kuralları, boyut indirgeme.
- Eğitim ve test oranı genellikle %70-80 ve %30-20.
- Accuracy = doğru sınıflanan test örneği sayısı / toplam test örneği sayısı.
- Karar ağacı: iç düğümler (decision nodes) öznitelik, yapraklar (leaf nodes) sınıf. Böl ve yönet (divide and conquer).
- Öznitelik seçim ölçütleri: bilgi kazancı (information gain), kazanç oranı (gain ratio).
- Naive Bayes: $P(C \mid X) \propto P(X \mid C)\,P(C)$, $P(X \mid C) = \prod_j P(x_j \mid C)$.
- kNN: en yakın $k$ komşunun çoğunluk etiketi. Model kurmaz, her tahminde veriye gider.
- $n$-katlı çapraz doğrulama ($n$-fold cross-validation): veri $n$ parçaya bölünür, her parça bir kez test olur, doğrulukların ortalaması alınır.

## Detaylı Açıklamalar

### Sohbet ve genel tavsiyeler

- Ders başında hoca öğrencilerle online eğitim ve iş yükünü konuştu.
- Hoca, online derste etkileşimin azaldığını söyledi. Öğrencilere ders için WhatsApp grubu kurmalarını ve ofis saati talep etmelerini önerdi.

### Sıralı örüntü madenciliği

- İlk çıkış amacı market sepeti analizini geliştirmek.
- Bir müşteri aynı gün sabah, öğlen ve akşam alışveriş yapabilir. Bunlar ayrı işlemlerdir ve sıralanabilir.
- Çok sayıda müşteri önce A, sonra B, sonra C alıyorsa, A'yı alan bir müşteriye önce B, sonra C önerilebilir.
- Web'deki kullanım:
  - IIS veya Tomcat gibi uygulama sunucularının log dosyaları.
  - Uygulamanın kendi log dosyaları ayrıştırılır (parse) ve kullanıcıların sıralı aktiviteleri bulunur.
- Churn ve retention (müşteriyi tutma) örneği:
  - Bankacılık ve telekomda terk etme davranışını modellemek önemli bir problem.
  - Pazarlama birimi bir aksiyon zinciri uygular: önce telefonla arama ve teklif (örneğin ücretsiz paket yükseltme), sonra ziyaret vb.
  - Başarılı aksiyon zincirleri bulunursa sonraki müşteriler için pazarlama birimine öneri verilebilir.

### Kavramlar ve alt sequence

- Öğeler (items) bir markette ürün veya churn örneğinde aksiyon olabilir.
- Hoca önce $k$ değerini eleman sayısı diye söyledi, sonra düzeltti: $k$ length'i gösterir, eleman sayısı size'dır.
- Alt sequence örneği: $\langle \{3\} \{4,5\} \{8\} \rangle$, $\langle \{6\} \{3,7\} \{9\} \{4,5,8\} \{3,8\} \rangle$ içinde bulunur.
  - $\{3\} \subseteq \{3,7\}$, $\{4,5\} \subseteq \{4,5,8\}$, $\{8\} \subseteq \{3,8\}$ ve sıra korunuyor.
- Bir öğrenci, süper sequence'ta {4,5,8} yerine {4}, {5}, {8} ayrı elemanlar olsaydı kapsamanın sürüp sürmeyeceğini sordu.
  - Hoca: Sürmez. {4,5} elemanını tek başına kapsayan bir eleman olmalı.
- Bir öğrenci length'in tekrarlı mı benzersiz mi sayıldığını sordu. Hoca: Öğeler sayılır. Size ise süslü parantez içindeki eleman sayısıdır.

### Veri formatı ve örnek

- Veritabanı müşteri bazında düzenlenir. Her müşterinin farklı işlem zamanları ve her işlemdeki ürünleri var.
- Örnekte işlem zamanı gün çözünürlüğünde. Aynı gün alınan ürünler bir eleman olarak düşünülür. Anlık zaman olsaydı aynı fişteki ürünlerin sırası kasiyerin okutma sırasıyla belirlenirdi.
- Dönüştürülmüş veri (5 müşteri):
  - Müşteri 1: $\langle \{30\} \{90\} \rangle$
  - Müşteri 2: $\langle \{10, 20\} \{30\} \{40, 60, 70\} \rangle$
  - Müşteri 3: $\langle \{30, 50, 70\} \rangle$
  - Müşteri 4: $\langle \{30\} \{40, 70\} \{90\} \rangle$
  - Müşteri 5: $\langle \{90\} \rangle$
- minsup %25, yani en az 2 müşteri.
- Sıralı örüntüler:
  - 1-sequence: $\langle \{30\} \rangle$, $\langle \{40\} \rangle$, $\langle \{70\} \rangle$, $\langle \{90\} \rangle$.
  - 2-sequence: $\langle \{30\} \{40\} \rangle$, $\langle \{30\} \{70\} \rangle$, $\langle \{30\} \{90\} \rangle$, $\langle \{40, 70\} \rangle$.
  - 3-sequence: $\langle \{30\} \{40, 70\} \rangle$.
- Bir öğrenci 2-sequence'ın size'a mı length'e mi göre seçildiğini sordu. Hoca: Length'e göre. $\langle \{30\} \{40\} \rangle$'ın size'ı 2, $\langle \{40,70\} \rangle$'ın size'ı 1. İkisinin de length'i 2.

### GSP algoritması

- Apriori mantığının aynısı, ama birliktelik yerine sıralı örüntülere bakılır.
- Adımlar:
  1. Veritabanı bir kez okunur, sık 1-sequence'lar bulunur.
  2. Döngüde candidate-gen ile bir üst seviyenin adayları üretilir.
  3. Veritabanı yeniden okunur, adaylar sayılır, minsup'u sağlayanlar tutulur.
  4. Yeni aday kalmayana kadar devam edilir.
- Diğer algoritmalar: Spark ML kütüphanesindeki PrefixSpan ve SPADE. Alan aktif, çok sayıda türev var.

### Makine öğrenmesi sınıflandırması

- Gözetimli öğrenme:
  - Sınıflandırma örneği: Bir e-ticaret sitesinde login ve logout arası hareketlerden müşterinin geri gelip gelmeyeceği veya alım yapıp yapmayacağı.
  - Regresyon örneği: Bir banka, tanımlanan kredi limitinin yüzde kaçının kullanılacağını tahmin etmek ister. Finansal zaman serilerinde de kullanılır.
- Gözetimsiz öğrenme:
  - Kümeleme: birbirine yakın elemanları kümelere ayırma.
  - Birliktelik tabanlı yöntemler: association rule mining, sequential pattern mining.
  - Boyut indirgeme ile genelleme: örnek PCA (temel bileşen analizi). Örneğin 100 öz niteliği ayırt edici gücü yüksek 5 veya 10 sanal öz niteliğe indirir. Çıktı öz nitelik sayısı algoritmanın girdisidir.
- Boyut indirgeme ile kümeleme farkı:
  - Boyut indirgeme verinin yapısını ortaya çıkarmaz. Veriyi sonraki sınıflandırma veya kümeleme için daha öğrenilebilir hale getirir. Genellikle onlardan önce kullanılır.
  - Kümeleme verinin içindeki yapıyı, hangi elemanların birbirine yakın olduğunu gösterir.
- Bir öğrenci, etiketle ilişkisi düşük öz niteliklerin elenmesini otomatik yapan kısmın bu olup olmadığını sordu. Hoca: Evet, PCA bu gruptadır.
- PCA tabanlı anomali tespiti örneği:
  - Oturum (session) verisinden öz nitelikler: son 6 ayda ortalama sayfa görüntüleme (page view), tıklama ve check-out sayıları.
  - İş analistlerinin etiketlediği 1000 kayıt olsun. Hangi öz niteliklerin ayırt edici olduğu bilinmiyor.
  - PCA, ilişkili (correlated) öz nitelikleri birleştirip daha az sayıda ama daha ayırt edici sanal öz nitelikler üretir.
- Sığ modeller: yukarıdaki yöntemler, derin öğrenme kullanmayan ve daha az veriyle beslenen modeller.
- Derin öğrenme: çok katmanlı, çok miktarda ve çeşitli veriyle beslenen modeller. Örnek: tekrarlayan sinir ağları (recurrent neural network, RNN) ve LSTM.
- Derste öncelik gözetimli ve gözetimsiz yöntemlerin web madenciliğindeki uygulamaları. Zaman kalırsa derin öğrenmeye girilecek.

### Gözetimli öğrenme

- Örnek 1: 17 hastalık bir acil serviste yeni gelen hastayı yüksek veya düşük riskli diye etiketlemek. Yatak sayısı sınırlı. Bu bir sınıflandırma problemi.
- Örnek 2: Kredi başvurusu (loan application). 15 örnek, 4 öznitelik (yaş, iş durumu, ev sahipliği, kredi notu) ve bir sınıf (evet veya hayır).
- "Supervised" denmesinin sebebi: etiketli veri modelin eğitimini denetler.
- Eğitim ve test:
  - Etiketli veri ikiye ayrılır. Test verisinin etiketi bilindiği için modelin başarısı ölçülebilir.
  - Ölçütler: accuracy, karışıklık matrisi (confusion matrix), precision, recall, F-skoru (F-score). Accuracy tek ölçüt değildir.
  - Öğrenmenin gerçekleşip gerçekleşmediği mutlaka bir performans ölçütüyle belirlenir.
- Hoca: İki sınıflı bir problemde hiç öğrenmeden tahmin %50 başarı verir. Öğrenmeyle hedef %80-90'lar. Yoksa öğrenmeye harcanan emek anlamsızdır.
- Web madenciliğinde tahmin edilen etiket örnekleri:
  - E-ticarette müşteri ürünü alacak mı?
  - Online dil öğretim oyununda öğrenci sıkıldı mı, oyunu bırakacak mı?
  - Bankacılık veya trading platformunda dolandırıcılık (fraud) veya anomali var mı?

### Karar ağacı

- Kökten başlanır. Tüm veriyi en iyi ayıran öznitelik bir ölçüte göre seçilir. Örnekte yaş (Age) seçildi.
- Veri, özniteliğin değerlerine (young, middle, old) göre dallara dağıtılır.
- Her dalda kalan öznitelikler içinden yine en iyi ayıran seçilir. Örnek: young dalında has_job, middle dalında own_house, old dalında credit_rating.
- Her yaprağa düşen örneklerin çoğunluk etiketi (majority) yaprağın sınıfı olur. Örnekte hiç yanlış sınıflanan eğitim örneği kalmadı.
- Yeni veri, ağaçta yukarıdan aşağı izlenir. Örnek: yaş young, has_job false ise sınıf "no", başvuru reddedilir.
- Aynı veri için farklı ağaçlar kurulabilir. Seçim ölçütü değişirse ağaç, dolayısıyla tahmin başarısı değişir.
- Basit hata sayısı karşılaştırması:
  - Age ile bölünce: young dalında 3 no 2 yes, middle'da 2 no 3 yes, old'da çoğunluk yes. Toplam 5 hata.
  - own_house ile bölünce: true dalında 0 hata, false dalında 3 hata. Toplam 3 hata.
  - Bu bakışla own_house daha iyi ayırıyor.

### Kural tabanlı sınıflandırma

- Bir karar ağacı kurallara çevrilebilir. Örnek: own_house = true ise yes; own_house = false ve has_job = true ise yes; diğer durumda no.
- Ağaç kurmadan class association rule mining ile de kurallar çıkarılabilir. Minsup ve minconf kullanıcı tarafından verilir.
- Model, sıralanmış kural listesidir. Yeni veri için kurallar sırayla denenir. İlk uyan kural etiketi verir. Hiçbiri uymazsa varsayılan (default) sınıf atanır.
- Bir öğrenci, ilk uyan kuralın etiketi vermesinin ezberlemeye yol açıp açmayacağını sordu (örneğin yaş ve maaş uygun ama kredi notu düşük).
  - Hoca: Haklısın. Buna aşırı öğrenme (overfitting) denir. Eğitim verisine çok bağlı öğrenme, sınırlı ve ezbere dayalı tahmin üretir.
  - Minsup ve minconf düşük tutulunca çok sayıda ayrıntılı kural çıkar. Bu ezberlemeye yaklaşır.
  - Karar ağacı veriyi tanımlayan ana kuralları çıkarır. Bu yüzden ezberleme problemi daha azdır.
  - Kural tabanlı yöntemler bu nedenle diğer sınıflandırıcılara göre daha az kullanılıyor.

### Naive Bayes

- Örnek: bilgisayar alıp almama (buys_computer), 4 öznitelik, 14 etiketli örnek. 9 yes, 5 no.
- Yeni örnek $X$ için her sınıfın olasılığı hesaplanır, büyük olan seçilir.
- Bayes teoremi: $P(C \mid X) = \dfrac{P(X \mid C)\,P(C)}{P(X)}$. Payda iki sınıf için aynı olduğu için yalnız paylar karşılaştırılır.
- $P(\text{yes}) = 9/14$, $P(\text{no}) = 5/14$.
- $P(X \mid \text{yes})$, $X$'in her özniteliğinin yes sınıfındaki olasılıklarının çarpımıdır.
  - Örnek: $P(\text{age} \le 30 \mid \text{yes}) = 2/9$, $P(\text{income} = \text{medium} \mid \text{yes}) = 4/9$, diğer öznitelikler de aynı şekilde.
- Örnekte $P(X \mid \text{yes})P(\text{yes})$ daha büyük çıktı. $X$ yes sınıfına atandı.
- Model, hesaplanan olasılık değerleri ve formüllerdir. İstatistiğe dayalı bir sınıflandırıcı.

### k en yakın komşu

- $k$ kullanıcı tarafından verilir. Örnekte $k = 6$.
- Yeni veriyle tüm eğitim verisi arasındaki uzaklık hesaplanır. Örnek ölçüt: Öklid uzaklığı (Euclidean distance).
- En yakın $k$ örneğin çoğunluk etiketi atanır. Örnekte çoğunluk "government" etiketiydi.
- Fark: Diğer yöntemler bir model kurar ve tahminde veriye dönmez. kNN model kurmaz, her tahminde veriye gider.

### Test verisi seçimi ve çapraz doğrulama

- Bir öğrenci, test verisini olabildiğince çeşitli seçmenin bir yöntemi olup olmadığını sordu.
- Hoca'nın cevabı:
  - %70-30 veya %80-20 ayırma.
  - $n$-fold cross-validation: Veri $n$ parçaya bölünür. Her seferinde bir parça test, kalanı eğitim olur. Örnekte 8 parça, 8 doğruluk değeri ve ortalaması.
  - Test örneklerini belli bir noktadan sonrasını almak yerine rastgele (random) seçmek.
  - Eğitim ve test verisinin dağılımına mutlaka bakılmalı. Veri normal veya başka bir dağılımdaysa test verisi de bunu yansıtmalı.
  - Sonuçlar aşırı iyi veya aşırı kötüyse test verisinin çeşitlilik içerip içermediği kontrol edilmeli.

### Sonraki dersler

- Gelecek hafta gözetimsiz öğrenme (kümeleme) hızlıca işlenecek, sonra information retrieval konusuna geçilecek.
- Regresyon ve PCA ayrıntısına girilmeyecek.
- Ardından sırasıyla web içerik madenciliği (web content mining), link analizi ve web yapı madenciliği (web structure mining), web kullanım madenciliği (web usage mining) işlenecek.

### Ders sonrası notlar

- Hoca entropi ve bilgi kazancını açıklarken "yaşın değerleri dengeli dağıldığı için entropisi yüksek, bu yüzden information gain'i yüksek" dedi. Bu yanlış. Information gain, bir özniteliğe göre bölmeden sonra **sınıf etiketinin** entropisindeki azalmadır: $\text{gain}(D, A) = \text{entropy}(D) - \sum_j \frac{|D_j|}{|D|}\,\text{entropy}(D_j)$. En iyi öznitelik, bölmeden sonra dallarda sınıfları en saf hale getirendir. Kitaptaki kredi örneğinde en yüksek kazanç own_house özniteliğindedir. Kök olarak own_house seçilir, Age seçilmez. Hocanın gösterdiği basit hata sayımı da (own_house 3 hata, Age 5 hata) bu sonuçla uyumlu.
- "Hiç öğrenmeden %50 başarı" yalnız iki sınıfın eşit dağıldığı durumda doğru. Asıl karşılaştırma noktası çoğunluk sınıfını tahmin etmektir. Kredi örneğinde 15 kişinin 9'u yes olduğu için hep "yes" demek bile %60 doğruluk verir.
- Hoca RNN ve LSTM'in "görüntü işleme ve görüntüde nesne tanıma" konularında başarılı olduğunu söyledi. Görüntü ve nesne tanımada asıl başarılı model evrişimli sinir ağlarıdır (convolutional neural network, CNN). RNN ve LSTM daha çok dizi verisinde (metin, konuşma, zaman serisi) kullanılır.
- Kural listesinde hoca kuralların support değerine göre sıralandığını söyledi. Kitaptaki CBA yönteminde kurallar önce confidence, eşitse support değerine göre sıralanır.
- Naive Bayes örneğinde öznitelik olasılıklarının yalnız ilk ikisi altyazıdan anlaşılıyor. Diğer çarpanlar ve sonuç değerleri slaytta, altyazıda okunmuyor.
- Altyazıdaki bozuk adlar: "PCI" doğrusu PCA; "GSB" doğrusu GSP; "Prefix Pen" doğrusu PrefixSpan; "Space" doğrusu SPADE; "ISS" doğrusu IIS; "Biasin Teorem" doğrusu Bayes teoremi; "Bias/Vice Computer" doğrusu buys_computer; "K-Fault" doğrusu k-fold; "web 103 mining" doğrusu web usage mining.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
