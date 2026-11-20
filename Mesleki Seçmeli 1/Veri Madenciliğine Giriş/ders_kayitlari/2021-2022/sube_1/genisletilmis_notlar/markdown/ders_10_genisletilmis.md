# Ders 10 Genişletilmiş Notu: Topluluk Öğrenme: Bagging, Boosting (AdaBoost) ve Random Forest

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın. Kayıtta dersin ikinci saati (00:00:00-00:25:09) birinci saatinden (00:25:36-01:30:39) önce yer alır; video parçaları ters sırada birleştirilmiş görünüyor. Not, dersin anlatım sırasını izler; saat damgaları kaydın kendisine göredir.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Model Değerlendirme
- 2. Topluluk (Ensemble) Yöntemlerine Giriş
- 3. Topluluğun Geometrik Sezgisi
- 4. Topluluk Neden İşe Yarar? 25 Sınıflandırıcı Örneği
- 5. Topluluk Sınıflandırıcı Kurmanın Yolları
- 6. Bagging (Bootstrap Aggregation)
- 7. Bagging Örneği: Decision Stump
- 8. Boosting
- 9. AdaBoost Algoritması
- 10. AdaBoost Oyuncak Örneği: Hata ve Alfa Değerleri
- 11. Doğrusal Sınırlar ve Veri Madenciliği Algoritmalarının Doğası
- 12. AdaBoost Örneği: Ağırlıkların Turdan Tura Değişimi
- 13. Random Forest
- 14. Topluluk Yöntemlerinin Deneysel Karşılaştırması
- 15. Bölümün Toparlaması
- Örnek Sorular

## 1. Önceki Dersin Tekrarı: Model Değerlendirme

### 1.1 Değerlendirme ölçüleri

Ders, önceki haftanın tekrarıyla başladı (00:27:56). Bir modelin ne kadar iyi çalıştığını ölçmek için şimdiye kadar bilinen ölçü doğruluktu (accuracy). Geçen hafta bunun dışında duyarlılık (sensitivity, recall da denir), kesinlik (precision) ve F1 skoru gibi ölçüler tanımlandı. Bu ölçüler özellikle verinin dengesiz (imbalanced) olduğu, yani iki sınıf arasında çok büyük fark olduğu durumlarda modelin ne kadar iyi çalıştığını farklı açılardan değerlendirmeyi sağlar.

Karışıklık matrisinde (confusion matrix) köşegende doğru bulunan sınıflar yer alır. Çok sınıflı durumda doğruluk ve kesinlik gibi ölçüler iki yolla bulunur: mikro ortalama (micro averaging) ve makro ortalama (macro averaging).

Model sınıflandırma yerine regresyon yapıyorsa, yani sürekli bir değer (örneğin bir kişinin boyu) tahmin ediyorsa, elde sınıf yoktur. Bu durumda ortalama mutlak hata (mean absolute error) ya da ortalama karesel hata (mean squared error) gibi hata ölçüleri kullanılır (00:29:15).

### 1.2 Holdout ve çapraz doğrulama

Holdout yönteminde veri bölünür; hoca örnek olarak verinin %80'inin eğitim, %20'sinin test için kullanılmasını verdi (00:29:50). Slaytta veri rastgele iki bağımsız kümeye ayrılır: modeli kurmak için eğitim kümesi (örneğin 2/3) ve doğruluğu tahmin etmek için test kümesi (örneğin 1/3). Random sampling, holdout'un bir çeşididir: holdout $k$ kez tekrarlanır ve doğruluk, elde edilen doğrulukların ortalaması olarak alınır (ekrandan, 00:30:00).

Çapraz doğrulamada (cross-validation) veri katlara (fold) bölünür; her katı bir küme gibi düşünmek mümkündür. $k$ kat varsa model $k$ kez, her seferinde bir kat dışarıda bırakılarak eğitilir ve dışarıda bırakılan kat test için kullanılır (00:29:50). Kaydın ikinci saatinde ekranda açık kalan slaytta çapraz doğrulamanın iki çeşidi yer alır (ekrandan, 00:20:00):

- Leave-one-out: $k$, kayıt (tuple) sayısına eşittir; küçük veriler için kullanılır. $n$ kayıtlı veride her iterasyonda bir kayıt test, kalan $n-1$ kayıt eğitim verisi olur.
- Stratified çapraz doğrulama: katlar, her kattaki sınıf dağılımı ilk verideki dağılıma yaklaşık eşit olacak şekilde oluşturulur. Slayttaki örnekte 3000 kaydın 600'ü pozitif, 2400'ü negatiftir; 3 katlı çapraz doğrulamada her alt küme rastgele 200 pozitif ve 800 negatif kayıt alır.

### 1.3 İki modelin karşılaştırılması

Hoca, iki model $M_1$ ve $M_2$'nin hata oranları arasındaki farkın istatistiksel olarak anlamlı olup olmadığının t-testi ile sınandığını söyledi, ama slaytların bu kısmını derste anlatmadığını belirtti (00:30:22). Bu kısım öğrencinin kendi çalışmasına bırakıldı.

### 1.4 ROC eğrisinin kurulması

ROC (Receiver Operating Characteristic) eğrisi, doğru pozitif oranı (TPR) ile yanlış pozitif oranının (FPR) birbirine göre nasıl değiştiğini gösterir (00:31:12). Model farklı eşiklerden (threshold) kesilir: eşiğe eşit ya da ondan büyük skorlu kayıtlara pozitif, küçüklere negatif denir. Eşik değiştirilerek her eşik için TPR ve FPR hesaplanır ve grafiğe işaretlenir.

Slayttaki on kaydın sınıfları ve skorları şöyledir (ekrandan, 00:35:00):

| Sınıf | + | - | + | - | - | - | + | - | + | + |
|---|---|---|---|---|---|---|---|---|---|---|
| Skor | 0.25 | 0.43 | 0.53 | 0.76 | 0.85 | 0.85 | 0.85 | 0.87 | 0.93 | 0.95 |

Hoca eşik olarak 0.76'yı seçip adım adım çözdü (00:32:25):

- Sınıflandırıcı: skoru $\ge 0.76$ olanlar pozitif, küçük olanlar negatif.
- Eşikten önceki üç kayıt ($+, -, +$) negatif tahmin edilir. Gerçekten negatif olan bir tanedir: $TN = 1$. Gerçekte pozitif olup negatif denen iki tanedir: $FN = 2$.
- Eşikten sonraki yedi kayıt ($-, -, -, +, -, +, +$) pozitif tahmin edilir. Gerçekten pozitif olan üç tanedir: $TP = 3$. Gerçekte negatif olup pozitif denen dört tanedir: $FP = 4$.
- $TPR = \dfrac{TP}{TP+FN} = \dfrac{3}{3+2} = 0.6$. Payda aslında toplam pozitif sayısıdır (5).
- $FPR = \dfrac{FP}{FP+TN} = \dfrac{4}{4+1} = 0.8$.

Böylece grafikte $(FPR, TPR) = (0.8, 0.6)$ noktası işaretlenir. Her eşik için bu noktalar işaretlenince ROC eğrisi çizilir. Kendi yazdığınız kodla küçük bir veride çizilen eğri basamak basamak çıkar; hazır araçlar eğriyi genelde yumuşatarak (smooth) çizer (00:36:24).

## 2. Topluluk (Ensemble) Yöntemlerine Giriş

Günün konusu topluluk (ensemble) yöntemleridir (00:36:44). Amaç genellikle doğruluğu artırmaktır. Hoca, gerçek dünyadaki verinin genellikle dengesiz olduğunu, bu yöntemlere bu yüzden ihtiyaç duyulduğunu söyledi.

Slayttaki tanıma göre topluluk yöntemleri doğruluğu artırmak için modellerin bir birleşimini kullanır: öğrenilmiş $k$ model $M_1, M_2, \dots, M_k$ birleştirilerek geliştirilmiş bir $M^*$ modeli oluşturulur. Yeni bir veri örneği geldiğinde modellerin oyları birleştirilir ve tahmin üretilir (ekrandan, 00:40:00).

Hoca bunu şöyle anlattı (00:38:02): veri üzerinde ilk model $M_1$ oluşturulur. Sonra parametreler değiştirilir ya da farklı bir sınıflandırıcı (örneğin Bayes) kullanılır; bu, aynı modelin farklı parametrelerle çalışmış hali de olabilir. Sonuçlar bir araya getirilir. En basit yol oylamadır: bir test örneği için $M_1$ "A sınıfı", $M_2$ "A sınıfı", $M_3$ "B sınıfı" derse çoğunluk A'dır. Buna çoğunluk oylaması (majority voting) denir.

Slayttaki üç popüler yöntem:

- Bagging: bir sınıflandırıcı topluluğunun tahminlerinin ortalaması alınır.
- Boosting: sınıflandırıcı topluluğu ile ağırlıklı oylama yapılır. Sınıflandırıcının doğru sınıflandıramadığı örnekler daha önemliymiş gibi ağırlıklandırılır ve bulunamayanlar iteratif olarak bulunmaya zorlanır.
- Ensemble: farklı türden (heterojen) sınıflandırıcılar birleştirilir.

Genel şemada (ekrandan, 00:45:00) üç adım vardır:

1. Orijinal eğitim verisi $D$'den birden fazla veri kümesi $D_1, D_2, \dots, D_t$ oluşturulur. Bu kümeler orijinal veriyle aynı boyutta da olabilir, daha küçük de. Geçen hafta görülen bootstrap örneklemede aynı kayıt birden fazla kez seçilebiliyordu; böyle çalışan yöntemler vardır. Örneğin bin kayıtlık veriden yüzer ya da iki yüzer kayıtlık daha küçük kümeler oluşturan yöntemler de vardır (00:40:52).
2. Her veri kümesinden bir sınıflandırıcı kurulur: $C_1$ yalnız $D_1$'i görür, $C_2$ yalnız $D_2$'den oluşur.
3. Sınıflandırıcılar $C^*$ olarak birleştirilir.

## 3. Topluluğun Geometrik Sezgisi

Hoca bir uzay çizdi: içinde kırmızı ve mavi iki sınıfın örnekleri var (00:41:34). Rastgele seçim yapıldığında sınıflandırıcı verinin yalnız bir kısmını görür ve o kısmı en iyi ayıran sınırı bulur. İkinci seçimde başka noktalar gelir ve başka bir sınır bulunur; üçüncüde bir başkası.

Test zamanında sınıfı bilinmeyen bir nokta gelir. Sınıflandırıcı 1'e sorulur: onun sınırına göre çizginin altı mavi, üstü kırmızıdır; nokta üstte kaldığı için "kırmızı" der. Sınıflandırıcı 2'ye sorulur, o da "kırmızı" der. Sonra oylama yapılır ve en çok söylenen sınıf seçilir (00:43:35).

Bu yaklaşım uzayı tek bir sınıflandırıcıyla tek bir biçimde bölmek yerine farklı alt kümelerden farklı biçimlerde bölmeye çalışır. Daha küçük bir küme üzerinde çalışıldığı için o kümeye gürültü (noise) gelmeyebilir ya da veri daha yoğunlaşmış olabilir; sınıflandırıcı o verinin özelliğini analiz ederek oluşturulur. Sonunda bunların toplamından temel sınıflandırıcı elde edilir (00:45:01).

## 4. Topluluk Neden İşe Yarar? 25 Sınıflandırıcı Örneği

Hoca bunu bir hesapla gösterdi (00:45:40). 25 taban sınıflandırıcı (base classifier) olsun; her biri daha küçük bir veride çalışsın ve her birinin hata oranı $\varepsilon = 0.35$ olsun, yani her biri 0.65 doğrulukla çalışsın. Sınıflandırıcıların bağımsız olduğu varsayılsın.

Tek sınıflandırıcı kullanılsa hata yapma ihtimali 0.35'tir. 25 sınıflandırıcı iki sınıflı bir problemde oylama yapıyorsa topluluğun yanlış karar vermesi için en az 13'ünün yanlış sınıf vermesi gerekir. Bu yüzden topluluğun hata olasılığı, olasılık-istatistikteki sayma yöntemleriyle şöyle bulunur:

$$e_{\text{topluluk}} = \sum_{i=13}^{25} \binom{25}{i} \varepsilon^{i} (1-\varepsilon)^{25-i} \approx 0.06$$

Yani hata teorik olarak 0.35'ten yaklaşık 0.06'ya iner (python ile kontrol edildi: 0.0604).

> **Hocanın vurgusu:** Bu düşüş teoriktir; gerçek hayatta böyle değildir, yoksa herkes topluluk yöntemi kullanırdı. Sınıflandırıcılar aynı veriden türediği için bağımsız değildir. Gerçekte her sınıflandırıcının bulamadığı ya da hatalı bulduğu örnekler genellikle aynı ya da benzerdir; bu yüzden hata bu kadar düşmez (00:47:54).

Hoca, sınıflandırıcı sayısının da bir optimal dengesi olduğunu söyledi: iki üç taneyi birleştirmek doğruluğu pek artırmaz, yüzlercesini birleştirmek de pek bir şey ifade etmez; belli bir yerden sonra hata artmaya başlar. Optimum sayı gerçek hayatta genellikle deneyerek bulunur (00:48:42).

## 5. Topluluk Sınıflandırıcı Kurmanın Yolları

Slayta göre topluluk birçok yolla kurulabilir; derste ikisi anlatıldı (ekrandan, 00:50:00).

### 5.1 Eğitim kümesini değiştirmek (manipulating the training set)

Elde tek bir eğitim kümesi vardır. Bir rastgele fonksiyonla, genellikle aynı kaydın birden fazla kez seçilmesine izin verilerek, orijinal veriden yeniden örnekleme (resampling) yapılır ve birden fazla eğitim kümesi oluşturulur. $K$ küme varsa algoritma $K$ kez çalıştırılır ve $K$ farklı sınıflandırıcı ortaya çıkar (00:49:23). Bagging ve boosting bu gruba girer.

Hoca, bu sınıflandırıcıların sonradan matematiksel olarak birleştirilmediğini vurguladı (00:50:09). Test aşamasında veri geldiğinde $C_1$'e, $C_2$'ye, $C_3$'e "sen buna ne dedin?" diye sorulur ve en sonunda oylamayla en çok hangi sınıf dendiyse o seçilir. "$C_1$ daha iyi çalışıyor, ağırlıklı ortalama alalım" ya da "bunun hatası yüksek, çıkaralım" gibi bir işlem yoktur; sonuç doğrudan oylamayla alınır. (Bu açıklama bagging içindir; boosting'deki ağırlıklı oylama Bölüm 8'de anlatılır.)

Hoca bu yöntemin ne seçtiğini bir tabloyla gösterdi: eğitim kümesinde her satır bir nesne, yani bir örnektir (sample); her sütun bir öznitelik (feature, attribute). Eğitim kümesini değiştiren yöntemler farklı rastgele satırlar seçer: bin satır varsa rastgele yüz tane seçer, sonra yine yüz tane; her yüzlük grup için ayrı bir eğitim kümesi oluşturulur (00:52:30).

### 5.2 Girdi özniteliklerini değiştirmek (manipulating the input features)

Bu yöntem satırları değil öznitelikleri seçer (00:52:57). Örneğin 100 öznitelik (kolon) varsa bunlardan bir parametreyle belirlenen sayıda (15-20 gibi) öznitelik seçilir ve sınıflandırıcı onlarla kurulur; her seferinde farklı öznitelikler seçilir. Slayta göre bu yaklaşım çok sayıda gereksiz (highly redundant) öznitelik içeren verilerde iyi çalışır.

Neden işe yaradığını hoca şöyle açıkladı (00:53:41): bazı veri kümelerinde öznitelikler birbirine çok bağımlıdır, birbirinden çok etkilenir ve bunlar çok sayıdadır. Örneğin hava sıcaklığı ile yağış arasında bir korelasyon vardır. Sınıflandırıcı bu birbirine bağlı özniteliklerden daha fazla etkilenebilir; tek başına etkili olan başka bir öznitelik varsa onu kaçırabilir, o boyutu daha az göz önüne alabilir. Farklı öznitelik alt kümeleri seçilince bu etki azalır. Bu yöntemin örneği random forest'tır.

**Soru:** Bu yöntem satır mı seçiyor? **Cevap:** Seçtiği özniteliğin bütün satırlarını alır. Eğitim verisinde 500 satır ve 100 öznitelik varsa ve her seferinde 10 öznitelik seçiliyorsa her eğitim kümesi 500 satır ve 10 öznitelikten oluşur. Satır sayısı aynı kalır, öznitelikler azalır; her seferinde farklı 10 öznitelik seçildiği için örneğin 30 farklı küme oluşturulabilir (00:54:56).

## 6. Bagging (Bootstrap Aggregation)

Bagging, "bootstrap aggregation" ifadesinin kısaltmasıdır (00:55:32). Kitap bunu bir hasta örneğiyle anlatır: bir hastalık için önce bir doktora gidersin, bulamazsa başka bir doktora gidersin; sonunda en çok doktor ne dediyse ona karar verirsin. Hoca, dersin başından beri anlatılan örneğin tamamen bagging'e girdiğini, bunun en temel topluluk yöntemi olduğunu söyledi (00:57:24).

Algoritma (00:56:43):

- Veri kümesi $D$'dir; iterasyon iterasyon gidilir.
- Her iterasyonda rastgele sayılar üretilerek, verilen parametre kadar büyüklükte bir eğitim kümesi oluşturulur; bir örnek birden fazla kez seçilebilir.
- Her küme için bir model $M_i$ öğrenilir.
- Sınıflandırmada bir test örneği geldiğinde her modele tek tek sorulur ve oylama yapılır.

Bagging, eğitim kümesini değiştiren yöntemler grubuna girer: sütunlardan değil satırlardan seçim yapılır ve satırlardan daha küçük veri kümeleri oluşturulur (00:57:43).

Genellikle daha yüksek sonuç verir. Dezavantajı daha uzun sürmesidir: kaç sınıflandırıcı kullanılırsa o kadar kat ekstra iş yükü gelir. Bu yüzden içinde yavaş çalışan yöntemler kullanılmaz (00:58:00). Neden daha iyi çalıştığını hoca şöyle açıkladı: aslında gürültülü veriyi atmaya çalışır; alt kümeler oluşturulurken o alt kümelere gürültü gelmezse daha iyi sınıflandırıcılar bulunabilir (00:58:26).

## 7. Bagging Örneği: Decision Stump

### 7.1 Veri ve tek sınıflandırıcının sınırı

Elde tek öznitelikli ($x$) bir veri kümesi vardır (ekrandan, 01:00:00):

| $x$ | 0.1 | 0.2 | 0.3 | 0.4 | 0.5 | 0.6 | 0.7 | 0.8 | 0.9 | 1.0 |
|---|---|---|---|---|---|---|---|---|---|---|
| $y$ | 1 | 1 | 1 | -1 | -1 | -1 | -1 | 1 | 1 | 1 |

Altı pozitif ve dört negatif sınıf vardır. Slaytta bu veri için tek iç düğümlü karar ağacı sınıflandırıcıları oluşturulur; böyle bir ağaca decision stump denir.

Tek bir sınıflandırıcı bir eşik (threshold) gibi çalışır (00:59:35):

- 0.35'te bölünürse: 0.35'ten küçükler $+1$, büyükler $-1$ denir. 0.8, 0.9 ve 1.0 yanlış sınıflanır; 10'da 3 hata, %70 doğruluk.
- 0.75'te bölünürse: 0.75'ten küçükler $-1$, büyükler $+1$ denir. 0.1, 0.2, 0.3 yanlış sınıflanır; yine %30 hata, %70 doğruluk.
- 0.55 gibi bir yerden bölünürse yaklaşık %50 doğruluk elde edilir.

Slayta göre tek iç düğümlü herhangi bir karar ağacı bu eğitim kümesinde en fazla %70 doğruluk verebilir (python ile kontrol edildi: 0.35 ve 0.75 eşikleri %70, 0.55 eşiği %50 verir).

> **Ders sonrası not:** Slaytta eşikler "Attribute >35" ve "Attribute >75" diye yazılmış; değerler $x$ ölçeğinde 0.35 ve 0.75'tir. Hoca bir yerde (01:01:31) 0.35 kökü için yönleri ters söyledi ("küçükse eksi bir"); slayttaki kurala göre $x \le 0.35$ ise $y = 1$'dir.

Taban sınıflandırıcı olarak karar ağacı kullanılır. Tek öznitelik olduğu için ağaçta tek bir düğüm vardır: kök $x$'e bakar ve doğrudan yapraklara bağlanır. Kökte "$x > 0.35$ mi?" testi vardır; ağaç yalnız kök ve yapraklardan oluşur (01:01:09).

### 7.2 Bootstrap turları

Her bootstrap örneklemi orijinal veriyle aynı boyuttadır ve orijinal veriden rastgele, tekrarlı seçimle oluşturulur. Slayttaki turlar (ekrandan, 01:05:00):

| Tur | Seçilen $x$ değerleri | Kural |
|---|---|---|
| 1 | 0.1, 0.2, 0.2, 0.3, 0.4, 0.4, 0.5, 0.6, 0.9, 0.9 | $x \le 0.35 \Rightarrow 1$, $x > 0.35 \Rightarrow -1$ |
| 2 | 0.1, 0.2, 0.3, 0.4, 0.5, 0.8, 0.9, 1, 1, 1 | $x \le 0.65 \Rightarrow 1$, $x > 0.65 \Rightarrow 1$ |
| 3 | 0.1, 0.2, 0.3, 0.4, 0.4, 0.5, 0.7, 0.7, 0.8, 0.9 | $x \le 0.35 \Rightarrow 1$, $x > 0.35 \Rightarrow -1$ |
| 4 | 0.1, 0.1, 0.2, 0.4, 0.4, 0.5, 0.5, 0.7, 0.8, 0.9 | $x \le 0.3 \Rightarrow 1$, $x > 0.3 \Rightarrow -1$ |
| 5 | 0.1, 0.1, 0.2, 0.5, 0.6, 0.6, 0.6, 1, 1, 1 | $x \le 0.35 \Rightarrow 1$, $x > 0.35 \Rightarrow -1$ |
| 6 | 0.2, 0.4, 0.5, 0.6, 0.7, 0.7, 0.7, 0.8, 0.9, 1 | $x \le 0.75 \Rightarrow -1$, $x > 0.75 \Rightarrow 1$ |

<!-- BELİRSİZ: 7-10. turların örneklemleri karelerde görünmüyor; bu turların kuralları yalnız 01:10:00 karesindeki oylama tablosundan anlaşılıyor (tur 7-9 0.75 eşiği, tur 10 her şeye 1). -->

Hoca turları şöyle anlattı (01:02:39):

- **Tur 1:** 0.1 bir kez, 0.2 iki kez, 0.3 bir kez, 0.4 iki kez, 0.5 ve 0.6 birer kez, 0.9 iki kez seçilmiş; 0.7 ve 0.8 hiç yok. Bulunan sınıflandırıcı 0.35'ten böler: küçüklere $+1$, büyüklere $-1$. Bu örneklemde yalnız iki 0.9 yanlış bulunur; %80 doğruluk.
- **Tur 2:** 0.6 ve 0.7 yok, 1.0 üç kez seçilmiş. Solda 3, sağda 5 pozitif kalır; hoca 0.5 ile 0.8'in orta noktası 0.65'ten bölmeyi gösterdi. Bir yanı $-1$, öbür yanı $+1$ derseniz %70 doğruluk çıkar; ama hepsine $+1$ derseniz %80 doğruluk çıkar. Bu yüzden algoritma hepsine $+1$ der, yani ağacın iki yaprağına da $+1$ gider.

**Soru:** Bir öğrenci hepsine $+1$ denirse daha iyi olacağını söyledi. **Cevap:** Hoca doğruladı; hangi biçimin seçileceği algoritmaya bağlıdır, örneğin doğrudan "sıfırdan büyükse $+1$" demek de olur (01:05:44, 01:06:35).

- **Tur 3:** 0.4 iki kez seçilmiş, 0.6 ve 1.0 hiç seçilmemiş. En iyi sınıflandırıcı yine 0.35'ten ayırır.

Böylece ilk turda 0.35'ten, ikincide 0.65'ten, üçüncüde yine 0.35'ten bir sınıflandırıcı bulunur. 10 tur için 10 farklı sınıflandırıcı elde edilir (01:06:55).

Aynı boyutta örneklem almanın bir sonucu da şudur: her sınıflandırıcı yalnız kendi örnekleminde bulunan değerleri görmüştür. Örneğin tur 1'de 0.7 ve 0.8 hiç yoktur (01:03:48).

<!-- BELİRSİZ: 01:03:16-01:04:43 arasında hoca, test girdisinin her alt sınıflandırıcıya yalnız o sınıflandırıcının örnekleminde bulunan değerlerle verileceğini söylüyor gibi; açıklama altyazıda net değil, nota kesin bilgi olarak alınmadı. -->

### 7.3 Oylama

Slayttaki tablo her turun sınıflandırıcısının her $x$ değeri için ne tahmin ettiğini gösterir (ekrandan, 01:10:00):

| Tur | 0.1 | 0.2 | 0.3 | 0.4 | 0.5 | 0.6 | 0.7 | 0.8 | 0.9 | 1.0 |
|---|---|---|---|---|---|---|---|---|---|---|
| 1 | 1 | 1 | 1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 |
| 2 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 3 | 1 | 1 | 1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 |
| 4 | 1 | 1 | 1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 |
| 5 | 1 | 1 | 1 | -1 | -1 | -1 | -1 | -1 | -1 | -1 |
| 6 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | 1 | 1 | 1 |
| 7 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | 1 | 1 | 1 |
| 8 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | 1 | 1 | 1 |
| 9 | -1 | -1 | -1 | -1 | -1 | -1 | -1 | 1 | 1 | 1 |
| 10 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| Toplam | 2 | 2 | 2 | -6 | -6 | -6 | -6 | 2 | 2 | 2 |
| İşaret | 1 | 1 | 1 | -1 | -1 | -1 | -1 | 1 | 1 | 1 |
| Gerçek sınıf | 1 | 1 | 1 | -1 | -1 | -1 | -1 | 1 | 1 | 1 |

Hoca tabloyu bir test aşaması gibi okudu (01:07:57): $x = 0.1$ gelse tur 1'in sınıflandırıcısı "0.35'ten küçükse $+1$" dediği için $+1$ verir; tur 2'ninki, tur 3'ünkü ne verirse tabloda o yazar. Sınıflar $+1$ ve $-1$ olduğu için oylama, tahminleri toplayıp toplamın işaretine bakmakla yapılır: toplam pozitifse pozitif sınıf, negatifse negatif sınıf. Sayı doğrusundaki her nokta için test yapılmış gibi düşünülebilir.

Sonuç satırı gerçek sınıflarla tamamen aynıdır: doğruluk %70'ten %100'e çıkar. Slayt bunu "bagging yaklaşımıyla performans arttı" diye özetler (python ile kontrol edildi). Hoca bunun nedenini şöyle açıkladı (01:10:38): aslında iki sınıflandırıcı çok akıllıca yerlerden, 0.35 ve 0.75'ten bölse ve oylansa %100 çalışırdı. Topluluk alt kümeler oluşturarak aralara daha fazla sınıflandırıcı koyar; bazı noktalar bir örneklemde seçilmemiş olsa bile oylamada çoğunluğa uyulduğu için doğru sınıflanır.

**Soru:** Burada on ayrı karar ağacı mı var? **Cevap:** Evet. Tur 1'deki sınıflandırıcı tek başına bir karar ağacıdır; tek düğümlü ve yalnız yaprakları olan bir ağaç. Sonunda bunların sonuçları oylamayla birleştirilir; kocaman tek bir karar ağacı yoktur (01:11:18).

**Soru:** Alt kümeler nasıl oluşturuluyor? **Cevap:** Buna bootstrap (bootstrapping) denir. Bir rastgele fonksiyon çağrılır; bir kez seçilen tekrar seçilebilir. Fonksiyon on kez çalışıp 1 ile 10 arasında sayı üretir ve hangi sayı üretildiyse o kayıt yeni veriye konur. Tur 1'de üretilen sıra numaraları 1, 2, 2, 3, 4, 4, 5, 6, 9, 9'dur; bu ilk alt kümedir ve ilk sınıflandırıcı bundan üretilir. Sonra yöntem tekrar çalışır ve yeni bir alt küme oluşur (01:12:27).

**Soru:** Seçimde bütün satır mı alınıyor? **Cevap:** Evet, yöntem bütün kaydı (tuple) seçer. Bu örnekte tek öznitelik olduğu için kayıtta yalnız $x$ değeri görünür (01:14:33).

Hoca, bu alt kümelere gürültüler ve uç değerlerin hiç ya da az gelebileceğini, birkaç sınıflandırıcıyı birleştirmenin bu yüzden daha doğru sonuç verdiğini söyledi. Veri gerçekten çok iyi, ikili olarak ayrılabilir olsa tek sınıflandırıcı işi çözerdi; bu örnekte de daha büyük bir karar ağacı kurulsa %100 çözülürdü. Ama gerçek veri çok daha büyük ve gürültülü olduğunda topluluk öğrenme yöntemleri daha iyi çalışabilir (01:13:29).

## 8. Boosting

"Boost" İngilizcede artırmak demektir; boosting de bir topluluk yöntemidir (01:15:01). Kitap yine doktor örneğini verir: farklı doktorlara gidersin, ama bazı doktorların kararlarını daha çok önemsersin.

Hoca bunu bir oyuncak örnekle gösterdi (ekrandan, 01:30:00). Uzayda 5 artı ve 5 eksi örnek vardır ve sınıflandırıcılarla ayrılacaktır:

- İlk sınıflandırıcı (hipotez) $h_1$ dikey bir çizgidir: solundakilere artı, sağındakilere eksi der. Üç artıyı yanlış bulur, kalanları doğru bulur.
- Bir sonraki iterasyon için veri kümesinin kendisi değişmez, ama hesaplamada doğru bulunanların ağırlıkları azaltılır, yanlış bulunanlarınki artırılır. Slaytta doğru bulunan artılar ve eksiler küçük, yanlış bulunan üç artı büyük çizilmiştir (01:16:47).
- Neden? Bir sonraki iterasyonda sınıflandırıcı bulunurken yanlış hesaplanan örneklerin hata hesabına etkisi daha büyük olsun ve önceki iterasyonlarda yanlış sınıflananlar daha doğru sınıflansın diye.
- İkinci sınıflandırıcı $h_2$ yine dikey bir çizgidir: soluna artı, sağına eksi der ve bu kez solda kalan üç eksiyi yanlış bulur. Bu üçünün ağırlığı artırılır, diğerlerininki azaltılır (01:18:01).
- Üçüncü sınıflandırıcı $h_3$ yatay bir çizgidir: üstüne artı, altına eksi der. Hesaplanırken ağırlığı yüksek olanlardan daha çok etkilenir ve onları ayırmaya çalışır; küçük ağırlıklı örneklerin de hatada payı vardır, ama daha azdır (01:18:26).

Sonunda üç sınıflandırıcı birleştirilir. Birleştirirken her sınıflandırıcı, bulduğu hata oranından hesaplanan bir ağırlıkla (0.42, 0.65 gibi) çarpılır; bu üç sınıflandırıcının birleşimi eğitim verisini tek tek her birinden daha iyi ayırır (01:18:52).

Slayttaki özet (ekrandan, 01:15:00):

- Her eğitim kaydına bir ağırlık verilir.
- $k$ sınıflandırıcıdan oluşan bir dizi iteratif olarak öğrenilir.
- $M_i$ öğrenildikten sonra ağırlıklar, sonraki sınıflandırıcı $M_{i+1}$'in $M_i$'nin yanlış sınıfladığı eğitim kayıtlarına daha çok dikkat etmesi için güncellenir.
- Son model $M^*$ her sınıflandırıcının oylarını birleştirir; her sınıflandırıcının oyunun ağırlığı doğruluğunun bir fonksiyonudur.
- Boosting algoritması sayısal tahmine de genişletilebilir.
- Bagging ile karşılaştırınca boosting daha yüksek doğruluğa ulaşma eğilimindedir, ama yanlış sınıflanan veriye aşırı uyum (overfitting) riski vardır.

## 9. AdaBoost Algoritması

Boosting'in birçok türü ve farklı uygulamaları vardır; hoca AdaBoost'un yanında LogitBoost gibi başka çeşitler de olduğunu söyledi. En çok kullanılanı AdaBoost'tur (01:19:54). Algoritma slaytta şöyledir (ekrandan, 01:20:00 ve 01:25:00):

1. Örnek ağırlıklarını başlat: $w_i = 1/N$, $(i = 1..N)$.
2. $m = 1$'den $M$'ye kadar ($M$ iterasyon sayısı):
   - a) Mevcut örnek ağırlıklarını kullanarak bir sınıflandırıcı $C_m$ öğren.
   - b) Ağırlıklı hata tahminini hesapla: $err_m = \dfrac{\sum w_i \text{ (yanlış sınıflanan tüm } e_i)}{\sum_{i=1}^{N} w_i}$. Ağırlıklar normalize edildiği için payda 1'dir.
   - c) Sınıflandırıcı ağırlığını hesapla: $\alpha_m = \dfrac{1}{2}\ln\left(\dfrac{1-err_m}{err_m}\right)$.
   - d) Doğru sınıflanan tüm örnekler için: $w_i \leftarrow w_i e^{-\alpha_m}$.
   - e) Yanlış sınıflanan tüm örnekler için: $w_i \leftarrow w_i e^{\alpha_m}$.
   - f) Ağırlıkları toplamları 1 olacak şekilde normalize et.
3. Her test örneği için tüm sınıflandırıcılar $C_m$ denenir.

<!-- BELİRSİZ: Algoritmanın 3. adımının devamı (oyların nasıl birleştirildiği) karelerde görünmüyor; hoca birleştirmenin $\alpha$ ağırlıklarıyla yapıldığını söylüyor (00:01:35, 01:21:55). -->

Slayttaki kutuya göre d ve e adımları, doğru sınıflanan örneklerin ağırlık toplamı yanlış sınıflananlarınkine eşit olacak şekilde ağırlıkları günceller.

Hoca adımları şöyle açıkladı (01:20:20):

- Başta her örneğe, yani veri kümesindeki her satıra eşit ağırlık verilir: $n$ örnek varsa her birine $1/n$.
- Bu ağırlıklara göre bir sınıflandırıcı öğrenilir. Karar ağacı, naive Bayes ya da başka bir sınıflandırıcı kullanılabilir; seçim size kalmıştır.
- Sınıflandırıcının ne kadar iyi çalıştığını görmek için ağırlıklı hata hesaplanır: hatalı sınıflananların ağırlıkları toplamı, tüm ağırlıkların toplamına bölünür. Hepsi doğru sınıflanmışsa hata çok küçük çıkar.
- Sonra sınıflandırıcı için bir ağırlık $\alpha$ hesaplanır. En sonda sınıflandırıcılar birleştirilirken çarpılan katsayılar bunlardır. Sınıflandırıcının hatası ne kadar azsa $\alpha$ o kadar yüksek olur.
- Örnek ağırlıkları güncellenir: doğru sınıflananlar $e^{-\alpha_m}$ ile çarpılıp azalır, yanlış sınıflananlar $e^{\alpha_m}$ ile çarpılıp artar. Sonra tüm ağırlıklar toplanıp normalize edilir.

**Soru:** Bu ne kadar sürer? **Cevap:** Veriye göre çok sürebilir. Slayttaki algoritmada olmasa da gerçek algoritmada, sınıflandırıcının hata oranı 0.5'ten kötüyse o sınıflandırıcıyı hiç kullanmama gibi adımlar da vardır; bulunan her sınıflandırıcı kullanılmaz. İterasyon $M$ kez sürer ya da 0.5'ten daha iyi çalışan bir sınıflandırıcı bulunamadığında durur (01:23:24, 01:26:01).

Hoca, mantığının çok güzel olduğunu ve AdaBoost'un çoğu zaman çok verimli çalışan bir yöntem olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** AdaBoost'un standart biçiminde son sınıflandırıcı $C^*(x) = \operatorname{sign}\left(\sum_m \alpha_m C_m(x)\right)$ biçimindedir: her sınıflandırıcının $+1$/$-1$ tahmini kendi $\alpha_m$ değeriyle çarpılıp toplanır. $\alpha_m$ formülü, $err_m = 0.5$ olduğunda sıfır olur; bu yüzden rastgele tahminden iyi olmayan bir sınıflandırıcının oyu büyük olasılıkla hiç etkili olmaz.

## 10. AdaBoost Oyuncak Örneği: Hata ve Alfa Değerleri

Hoca oyuncak örneğe geri döndü (01:23:56). Gerçek veride örnekler yalnız artı ve eksi değildir; örneğin önceki slaytlardaki "öğrenci bilgisayar alır mı almaz mı" verisinde olduğu gibi her örneğe sanki yeni bir değer atanıyormuş gibi düşünülebilir.

İlk başta hepsinin ağırlığı eşittir: $1/10$. İlk sınıflandırıcı $h_1$, iki boyutlu uzayda örneğin "$x < 0.2$ ise artı, büyükse eksi" gibi basit bir sınırdır (01:25:11). Üç örneği yanlış sınıflar. Ağırlıklar eşit olduğu için:

- $\varepsilon_1 = 3 \times \dfrac{1}{10} = 0.30$
- $\alpha_1 = \dfrac{1}{2}\ln\dfrac{1-0.30}{0.30} = \dfrac{1}{2}\ln(2.33) \approx 0.42$ (ara adım eklendi; python ile kontrol edildi: 0.4236)

İkinci sınıflandırıcı da üç örneği yanlış bulur, ama hata oranı $\varepsilon_2 = 0.21$ çıkar ve $\alpha_2 \approx 0.65$ olur. Hata oranı daha düşüktür, çünkü yanlış bulduğu üç örneğin ağırlıkları azdır (01:26:42). Üçüncü sınıflandırıcı için slaytta $\varepsilon_3 = 0.14$ ve $\alpha_3 = 0.92$ yazılıdır (ekrandan, 01:30:00).

> **Ders sonrası not:** $\varepsilon_2 = 0.21$ ve $\varepsilon_3 = 0.14$ ile formülden $\alpha_2 \approx 0.66$ ve $\alpha_3 \approx 0.91$ çıkar (python ile kontrol edildi). Slayttaki 0.65 ve 0.92, büyük olasılıkla yuvarlanmamış hata oranlarından hesaplanmıştır.

Ağırlığı artırmanın anlamını hoca şöyle açıkladı (01:27:18): bir sonraki iterasyonda hata hesaplanırken, yüksek ağırlıklı örnekleri daha iyi bulan bir sınıflandırıcı varsa öne çıkar. Bir sınıflandırıcı bütün ağırlıkların eşit olduğu veride çok kötü çalışıyor gibi görünebilir. Ama ağırlıkların farklı olduğu bir veriye konduğunda, ağırlıklar hatayı etkilediği için, normal sınıflandırıcının bulamadıklarını bulabilen bu sınıflandırıcı daha önemli hale gelir.

> **Hocanın vurgusu:** Boosting'de hatalı bulunanları, zor bulunanları bulmaya sınıflandırıcıyı zorluyoruz (01:27:59).

## 11. Doğrusal Sınırlar ve Veri Madenciliği Algoritmalarının Doğası

Oyuncak örnekte sınırlar hep düz çizgilerdir. Hoca bunun nedenini açıkladı (01:28:04): şimdiye kadar görülen sınıflandırıcılar doğrusaldır. Örneğin karar ağacı "büyüktür, küçüktür" diye gider. Sınıflandırıcı ikinci, üçüncü ya da daha yüksek dereceden bir fonksiyon olsa sınır eğri biçiminde de gidebilirdi. SVM doğrusaldır; doğrusal olmayan hale getirmek için içine ek yapılar konur. Ama uzay çok büyüktür: burada yalnız $x$ ve $y$ var, gerçek veride ise çok fazla sütun vardır. Veri zaten büyükken bir de çok dereceli bir polinomun katsayılarını bulmak algoritmaları ağırlaştırır.

Hoca, algoritmaların optimizasyon yaparak çalıştığını vurguladı. Veri madenciliğinde "şunu yap, kesin çalışacak" diyen deterministik bir algoritma yoktur; algoritmalar deneye deneye, "bundan küçükse aramaya devam et" gibi ilerler (01:29:08). Karar ağacı optimal karar ağacını bulmaz. Naive Bayes tamamen veriye bağımlıdır; veri biraz değişse sonuçlar tamamen değişir. SVM'de de doğrusal ayırma mantığıyla gidilir. Yapay sinir ağlarında katman artırmak aslında denkleme bir derece eklemek gibidir; avantajları biraz da buradan gelir. Bunlar ileride görülecektir. Dijkstra algoritması gibi optimal sonucu garanti eden ya da dinamik programlamayla çözülen problemlerden farklı olarak burada böyle bir garanti yoktur.

## 12. AdaBoost Örneği: Ağırlıkların Turdan Tura Değişimi

Aradan sonra hoca eski slaytlara döndü ve boosting'i özetledi (00:00:23). Boosting'in genel mantığı, her örneğe bir ağırlık atayıp doğru sınıflandırılamayanların ağırlığını artırmak, doğru sınıflandırılanlarınkini azaltmaktır. Böylece bir sonraki sınıflandırıcı doğru sınıflandırılamayanlara daha çok yoğunlaşır ve onların hatalarını gidermeye çalışır.

> **Hocanın vurgusu:** Bagging ile boosting arasındaki en temel fark birleştirmededir. Bagging'de sınıflandırıcılar doğrudan oylamayla birleştirilir ve her sınıflandırıcının oyu eşittir. Boosting'de her sınıflandırıcının hata oranı $\varepsilon$'dan bir $\alpha$ çıkarılır ve birleştirirken bu $\alpha$ her sınıflandırıcının önemini verir; sınıflandırıcılar eşit değildir (00:01:27).

Slayttaki örnek, bagging örneğindeki aynı veriyi AdaBoost ile işler (ekrandan, 00:05:00):

| $x$ | 0.1 | 0.2 | 0.3 | 0.4 | 0.5 | 0.6 | 0.7 | 0.8 | 0.9 | 1.0 |
|---|---|---|---|---|---|---|---|---|---|---|
| $y$ | 1 | 1 | 1 | -1 | -1 | -1 | -1 | 1 | 1 | 1 |

Boosting sırasında seçilen kayıtlar:

| Tur | Seçilen $x$ değerleri | Seçilen $y$ değerleri |
|---|---|---|
| 1 | 0.1, 0.4, 0.5, 0.6, 0.6, 0.7, 0.7, 0.7, 0.8, 1 | 1, -1, -1, -1, -1, -1, -1, -1, 1, 1 |
| 2 | 0.1, 0.1, 0.2, 0.2, 0.2, 0.2, 0.3, 0.3, 0.3, 0.3 | hepsi 1 |
| 3 | 0.2, 0.2, 0.4, 0.4, 0.4, 0.4, 0.5, 0.6, 0.6, 0.7 | 1, 1, -1, -1, -1, -1, -1, -1, -1, -1 |

Eğitim kayıtlarının ağırlıkları:

| Tur | 0.1 | 0.2 | 0.3 | 0.4 | 0.5 | 0.6 | 0.7 | 0.8 | 0.9 | 1.0 |
|---|---|---|---|---|---|---|---|---|---|---|
| 1 | 0.1 | 0.1 | 0.1 | 0.1 | 0.1 | 0.1 | 0.1 | 0.1 | 0.1 | 0.1 |
| 2 | 0.311 | 0.311 | 0.311 | 0.01 | 0.01 | 0.01 | 0.01 | 0.01 | 0.01 | 0.01 |
| 3 | 0.029 | 0.029 | 0.029 | 0.228 | 0.228 | 0.228 | 0.228 | 0.009 | 0.009 | 0.009 |

Hoca, kitaptaki örneğin boosting'de tüm örnekleri almadığını, bagging'deki gibi bir alt küme alarak gittiğini belirtti; örneğin 1. turda 0.6 iki kez seçilmiştir. Bunun bütün boosting algoritmalarında böyle olmak zorunda olmadığını da ekledi (00:03:02). İlk turda bütün ağırlıklar eşittir: $1/10 = 0.1$.

Slaytta hangi sınıflandırıcıların bulunduğu yazmıyor; hoca bunları kendisi tahmin ederek anlattı (00:03:28):

- **Tur 1:** Sınıflandırıcı büyük olasılıkla 0.75'ten böler: 0.75'ten küçüklere $-1$, büyüklere $+1$ der. Bu örneklemde yalnız 0.1 yanlış bulunur. Ama tüm veride 0.75'ten küçük olup gerçekte $+1$ olan 0.1, 0.2 ve 0.3 yanlış sınıflanır; bu yüzden bir sonraki tur için bu üçünün ağırlığı 0.311'e çıkar, diğerleri 0.01'e iner (00:05:10).
- **Tur 2:** Ağırlıkları yüksek olan 0.1, 0.2, 0.3 seçilmiştir; tur yalnız bunlara odaklanır. Hoca burada "0.3'ten küçükse sınıf 1'dir" gibi bir sınıflandırıcı kurulabileceğini söyledi; 0.3'ten küçük olup eksi olan yoktur, bunlar doğru sınıflanır (00:05:53). Sonra ağırlıklar yeniden güncellenir.

Böylece biri 0.75'te, biri 0.3 ya da 0.35 civarında (hangisi olduğu algoritmaya göre değişir) iki sınıflandırıcıyla boosting algoritması çalıştırılmış olur. Hoca bu örneğin kitabın klasik örneği olduğunu, ama çok iyi bir örnek olmadığını söyledi (00:06:36).

> **Ders sonrası not:** Tablodaki 3. tur ağırlıklarına göre (0.4-0.7 artmış, 0.8-1.0 azalmış), 2. turun sınıflandırıcısı büyük olasılıkla her $x$ için $+1$ demiştir; 0.8-1.0'a da $+1$ dediği için onlar doğru, 0.4-0.7 yanlış sınıflanmıştır. Slayttaki ağırlıklar, 9. bölümdeki algoritmadan değil, hatanın ayrıca $1/N$ ile çarpıldığı bir varyanttan ($\varepsilon = \frac{1}{N}\sum w_j \cdot \text{yanlış}_j$) büyük olasılıkla elde edilmiştir: bu varyantla 1. tur için $\varepsilon = 0.03$, $\alpha \approx 1.74$ ve yeni ağırlıklar 0.311 ve 0.0096 çıkar (python ile kontrol edildi). 9. bölümdeki algoritmayla ise ağırlıklar 0.167 ve 0.071 olurdu. Aynı varyantla 3. tur ağırlıkları 0.0285, 0.228 ve 0.0009 çıkar; slayttaki 0.009 büyük olasılıkla yazım hatasıdır.

## 13. Random Forest

Topluluk öğrenmenin üçüncü yöntemi random forest'tır (00:06:58). Orman ağaçlardan oluşur. Hoca, kocaman ağaçlar oluşturabilen bir algoritma zaten varken random forest'a neden ihtiyaç olduğunu sordu ve şöyle cevapladı: veri çok büyük olduğunda, çok fazla sütun ve satır varsa, ağaçlar bölerek bölerek gittiği için bir yerden sonra iyi çalışmayabilir (00:07:18).

Random forest'ta çok sayıda karar ağacı oluşturulur. Ama bu ağaçlar çok büyük ve mükemmel çalışan ağaçlar olmaz ve bütün veri üzerinde çalışmaz (00:07:43). Örneğin bin sütun varsa her seferinde içinden rastgele bir kısmı seçilir; kaç tane seçileceği tamamen parametredir. "Verinin bu kısmı için bir ağaç oluştur" denir, sonra yeniden seçilir ve bir ağaç daha oluşturulur; diyelim yüz ağaç oluşturuldu. Test örneği geldiğinde birinci ağaca, ikinci ağaca, yüz ağacın hepsine hangi sınıf olduğu sorulur; en çok oyu alan sınıf seçilir (00:08:19).

Slayttaki tanım (ekrandan, 00:10:00):

- Topluluktaki her sınıflandırıcı bir karar ağacıdır ve bölmeyi belirlemek için her düğümde özniteliklerin rastgele seçilmesiyle oluşturulur.
- Sınıflandırma sırasında her ağaç oy verir ve en popüler sınıf döndürülür.

Random forest özellikle gürültülü veride çok iyi çalışır (00:08:33). Nedeni, gürültünün seçilen alt kümelerde bulunma ihtimalinin düşük olmasıdır. Ayrıca ağaçların yüksekliği parametreyle sınırlanır, örneğin "yüksekliği dörtten fazla olmasın" denir. Hoca, gürültüsü az olan özniteliklerin ağaçta yukarıda kalacağını, ağaç çok fazla seviyeye inmeyeceği için gürültünün iyi tolere edildiğini söyledi. Random forest çok hızlı da çalışır; hoca bunu kendi görüşüyle çok iyi bir yöntem olarak niteledi (00:09:10).

<!-- BELİRSİZ: 00:08:44'te hoca "lineer olarak ayrılabiliyorsa, datanızda noise çok varsa random forest iyi çalışır" diyor; doğrusal ayrılabilirlikle ilgili kısım altyazıda net değil. -->

**Soru:** Gürültü veri temizlemede (data cleaning) atılmıyor mu? **Cevap:** Veri temizlemede dağılıma bakılır ve en uç değerlerde kalanların gürültü olduğu söylenir; çok bariz gürültüler temizlenir. Ama verinin içinde de gürültü olabilir; gerçek dünyada bir değerin gürültü olup olmadığı bile bilinmez. Temizlikten sonra normal görünen verinin içinde de hâlâ çok sayıda gürültü olabilir (00:09:47).

**Soru:** Topluluk yöntemleri ne zaman kullanılır? **Cevap:** Genellikle veri dengesiz olduğunda. Ayrıca ilk çalıştırılan karar ağacı %95-96 doğrulukla çalışıyorsa sorun yoktur. Ama doğruluk düşükse, örneğin %70'in üstüne çıkmıyorsa ve eğitim verisinde bile %70 civarında kalıyorsa, verinin gürültülü olduğu düşünülebilir; o zaman topluluk yöntemlerinin nasıl çalıştığına bakılır (00:10:40).

### 13.1 Random forest oluşturmanın iki yöntemi

Slayta göre iki yöntem vardır (ekrandan, 00:10:00):

- **Forest-RI (random input selection):** Her düğümde, o düğümdeki bölme için aday olarak rastgele $F$ öznitelik seçilir. Ağaçlar CART yöntemiyle büyütülür. Hoca bunu şöyle anlattı (00:11:26): $F$ bir parametredir; o kadar öznitelik alınır ve düğüme bunlardan hangisinin konacağına bakılır. Ağaç tüm özniteliklerle oluşturulmaz, özniteliklerin bir alt kümesiyle oluşturulur. Ağaçlar da çok büyük olmaz; yüksekliği en fazla bir parametre kadar olsun denir.
- **Forest-RC (random linear combinations):** Var olan özniteliklerin doğrusal birleşimi olan yeni öznitelikler oluşturulur. Slayta göre bu, tek tek sınıflandırıcılar arasındaki korelasyonu azaltır. Hoca bunu şöyle anlattı (00:12:40): var olan öznitelikler birleştirilerek yeni bir öznitelik oluşturulur; örneğin üç öznitelik sanki tek bir öznitelikmiş gibi birleştirilebilir.

Hoca en çok birinci yöntemin kullanıldığını söyledi (00:12:52).

> **Ders sonrası not:** Hoca ikinci yöntemin adını "Random Binary Combination" diye söyledi; slayttaki adı "random linear combinations"tır (Forest-RC). Ayrıca slaytta Forest-RI'da ağaçların CART ile en büyük boyuta kadar büyütüldüğü yazar; hocanın söylediği yükseklik sınırı, pratikte verilebilen bir parametre olarak anlaşılmalıdır. Slayta göre de rastgele öznitelik seçimi ağacın tamamı için bir kez değil, her düğümde yapılır.

<!-- BELİRSİZ: 00:12:08-00:12:32 arasında hoca Forest-RC'yi bagging'deki satır seçimiyle karşılaştırıyor ("satırın yerini de karıştırmış oluyor"); bu açıklama altyazıda net değil. -->

Slayttaki diğer özellikler:

- Doğruluğu AdaBoost ile karşılaştırılabilir düzeydedir, ama hatalara ve aykırı değerlere (outlier) karşı daha dayanıklıdır.
- Her bölmede değerlendirilmek üzere seçilen öznitelik sayısına duyarsızdır ve bagging ya da boosting'den daha hızlıdır.

## 14. Topluluk Yöntemlerinin Deneysel Karşılaştırması

Slayttaki tablo, UCI'deki açık veri kümelerinde tek bir karar ağacını bagging, boosting ve random forest ile karşılaştırır (ekrandan, 00:15:00). Hoca, daha önce Iris veri kümesinin kullanıldığını ve proje için de bu tür veri kümeleri seçilebileceğini hatırlattı (00:13:07). Tabloda her veri kümesi için öznitelik, sınıf ve kayıt sayısı verilir.

Tablodan bazı satırlar (doğruluk, %):

| Veri kümesi | (Öznitelik, Sınıf, Kayıt) | Karar ağacı | Bagging | Boosting | RF |
|---|---|---|---|---|---|
| Anneal | (39, 6, 898) | 92.09 | 94.43 | 95.43 | 95.43 |
| Australia | (15, 2, 690) | 85.51 | 87.10 | 85.22 | 85.80 |
| Glass | (10, 7, 214) | 67.29 | 76.17 | 77.57 | 78.04 |
| Iris | (5, 3, 150) | 94.67 | 94.67 | 94.00 | 93.33 |
| Labor | (17, 2, 57) | 78.95 | 84.21 | 89.47 | 84.21 |
| Lymphography | (19, 4, 148) | 77.03 | 79.05 | 85.14 | 82.43 |
| Tic-tac-toe | (10, 2, 958) | 83.72 | 93.84 | 98.54 | 95.82 |
| Waveform | (22, 3, 5000) | 76.44 | 83.30 | 83.90 | 84.04 |

Slayta göre topluluk yöntemlerinin her birinde taban sınıflandırıcılar elli karar ağacından oluşur ve doğruluklar 10-katlı çapraz doğrulamayla elde edilmiştir. Topluluk sınıflandırıcıları birçok veri kümesinde tek karar ağacından genellikle daha başarılıdır.

Hoca tabloyu şöyle yorumladı (00:13:37): 15 öznitelikli küçük bir veride (Australia) random forest ile karar ağacı arasında pek fark yoktur. Bazılarında ise doğruluk 92'den 95'e çıkmıştır (Anneal). Lymphography'de karar ağacı 77 iken boosting ile 85'e, Tic-tac-toe'da 83'ten 90'ların üstüne çıkmıştır. Bunlar deneysel (empirical) sonuçlardır; genel olarak topluluk yöntemleri bir tık daha iyidir (00:14:36).

## 15. Bölümün Toparlaması

Hoca bölümün (chapter) sınıflandırma konusunu özetledi (00:15:04): önce sınıflandırma ölçüleri (metrikler) görüldü. Sonra veri, %70-%30 gibi oranlarla holdout yöntemiyle, rastgele örneklemeyle ya da çapraz doğrulama yöntemleriyle (k-fold cross-validation) eğitim ve test için ayrıldı. Ardından modelin performansına bakıldı. Performansı artırmak için de bu derste topluluk öğrenme yöntemleri görüldü.

## Örnek Sorular

### Soru 1 (ekrandan, 00:35:00)

Sınıfları $+, -, +, -, -, -, +, -, +, +$ ve skorları $0.25, 0.43, 0.53, 0.76, 0.85, 0.85, 0.85, 0.87, 0.93, 0.95$ olan on kayıt için eşik 0.76 alınırsa ($\ge 0.76$ pozitif) ROC eğrisinde işaretlenecek nokta nedir?

**Çözüm (derste verildi, 00:32:25):** $TP = 3$, $FP = 4$, $TN = 1$, $FN = 2$. $TPR = 3/(3+2) = 0.6$, $FPR = 4/(4+1) = 0.8$. İşaretlenen nokta $(FPR, TPR) = (0.8, 0.6)$'dır. Slayttaki tablonun bu sütunu da aynı değerleri verir.

### Soru 2 (derste sözlü, 00:45:40)

Her birinin hata oranı $\varepsilon = 0.35$ olan 25 bağımsız taban sınıflandırıcı çoğunluk oylamasıyla birleştirilirse, iki sınıflı bir problemde topluluğun hata olasılığı nedir?

**Çözüm (derste verildi):** Topluluğun yanılması için en az 13 sınıflandırıcının yanılması gerekir: $\sum_{i=13}^{25}\binom{25}{i}(0.35)^i(0.65)^{25-i} \approx 0.06$ (python ile: 0.0604). Bu yalnız bağımsızlık varsayımıyla geçerlidir; gerçekte sınıflandırıcılar bağımsız olmadığı için hata bu kadar düşmez.

### Soru 3 (ekrandan, 01:00:00)

$x = 0.1, \dots, 1.0$ ve $y = 1, 1, 1, -1, -1, -1, -1, 1, 1, 1$ verisinde tek iç düğümlü bir karar ağacı (decision stump) en fazla hangi doğruluğa ulaşabilir? Hangi eşikler bu doğruluğu verir?

**Çözüm (derste verildi, 00:59:35):** En fazla %70. $x \le 0.35 \Rightarrow 1$ kuralı 0.8, 0.9 ve 1.0'ı; $x \le 0.75 \Rightarrow -1$ kuralı 0.1, 0.2 ve 0.3'ü yanlış sınıflar. Her ikisinde 10 kayıtta 3 hata vardır.

### Soru 4 (ekrandan, 01:05:00)

Bagging'in 2. turunda örneklem $x = 0.1, 0.2, 0.3, 0.4, 0.5, 0.8, 0.9, 1, 1, 1$, sınıfları $1, 1, 1, -1, -1, 1, 1, 1, 1, 1$'dir. 0.65'ten bölen bir stump hangi kuralı seçmelidir?

**Çözüm (derste verildi, 01:05:08):** Bir yana $-1$, öbür yana $+1$ denirse en iyi durumda %70 doğruluk elde edilir. İki yaprağa da $+1$ denirse yalnız iki $-1$ yanlış olur ve doğruluk %80'e çıkar. Bu yüzden slayttaki kural $x \le 0.65 \Rightarrow 1$, $x > 0.65 \Rightarrow 1$'dir.

### Soru 5 (ekrandan, 01:10:00)

On bagging turunun tahminleri $x = 0.1$ için $1, 1, 1, 1, 1, -1, -1, -1, -1, 1$; $x = 0.4$ için $-1, 1, -1, -1, -1, -1, -1, -1, -1, 1$'dir. Bu noktalar hangi sınıfa atanır?

**Çözüm (derste verildi, 01:08:26):** Tahminler toplanır ve toplamın işaretine bakılır. $x = 0.1$ için toplam $6 - 4 = 2$, işaret $+1$. $x = 0.4$ için toplam $2 - 8 = -6$, işaret $-1$. İkisi de gerçek sınıfla aynıdır.

### Soru 6 (derste sözlü, 01:26:20)

AdaBoost'ta ağırlıkları eşit ($1/10$) on örnekten üçü yanlış sınıflanırsa sınıflandırıcının ağırlıklı hatası ve $\alpha$ değeri nedir?

**Çözüm (derste verildi):** $err_1 = 3/10 = 0.30$; $\alpha_1 = \frac{1}{2}\ln\frac{0.70}{0.30} \approx 0.42$ (python ile: 0.4236).

### Soru 7 (ekrandan, 00:05:00)

AdaBoost örneğinde 1. turdan sonra 0.1, 0.2 ve 0.3'ün ağırlıkları 0.311'e çıkmış, diğerleri 0.01'e inmiştir. Bu güncellemeyi hangi hata ve $\alpha$ değerleri verir?

> **Çözüm (derste verilmedi):** 1. turda 0.1, 0.2, 0.3 yanlış sınıflanır. Slayttaki değerler, hatanın $1/N$ ile çarpıldığı varyantla tutar: $\varepsilon = \frac{1}{10}(3 \times 0.1) = 0.03$, $\alpha = \frac{1}{2}\ln\frac{0.97}{0.03} \approx 1.738$. Yanlışlar $0.1 e^{1.738} \approx 0.569$, doğrular $0.1 e^{-1.738} \approx 0.0176$ olur; toplam $3(0.569) + 7(0.0176) \approx 1.829$ ile normalize edilince $0.311$ ve $0.0096 \approx 0.01$ çıkar (python ile kontrol edildi). 9. bölümdeki algoritmayla ($\varepsilon = 0.30$) ise ağırlıklar $0.167$ ve $0.071$ olurdu.

## Dersin Toparlaması

Ders, önceki haftanın model değerlendirme konularının (değerlendirme ölçüleri, holdout, çapraz doğrulama, ROC eğrisi) tekrarıyla başladı ve sınıflandırmada doğruluğu artırmanın yolu olan topluluk öğrenme yöntemleriyle devam etti. Topluluk yöntemleri birden fazla sınıflandırıcının oylarını birleştirir. Eğitim kümesinin satırlarını değiştiren yöntemlerden bagging, bootstrap örneklemlerinden eğitilen sınıflandırıcıları eşit oyla birleştirir; boosting ise örneklere ağırlık verir, yanlış sınıflananların ağırlığını artırarak sonraki sınıflandırıcıyı zor örneklere yönlendirir ve sınıflandırıcıları hata oranından hesaplanan $\alpha$ ağırlıklarıyla birleştirir. Öznitelikleri değiştiren random forest ise rastgele öznitelik alt kümeleriyle kurulan küçük karar ağaçlarını oylar ve gürültülü veride iyi, hızlı çalışır. Decision stump örneği, tek başına en fazla %70 doğruluk veren basit sınıflandırıcıların birleşince %100'e ulaşabildiğini gösterdi. Deneysel tablo da topluluk yöntemlerinin çoğu veri kümesinde tek karar ağacından daha iyi olduğunu gösterdi; ancak sınıflandırıcılar bağımsız olmadığından teorik kazanç gerçekte tam görülmez.

Hoca, sonraki derslerde Python'da pandas ile veri okuma (CSV, DataFrame), öznitelik atma ve temizleme, kutu grafiği (boxplot) gibi çizimler ile scikit-learn kullanarak naive Bayes, karar ağacı ve random forest uygulamalarının gösterileceğini söyledi (00:21:22, 00:23:09). İleride SVM ve yapay sinir ağları da görülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
