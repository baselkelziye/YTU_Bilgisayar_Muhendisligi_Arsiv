# Ders 13 Genişletilmiş Notu: Dönem Projesi İlerleme Raporları ve Akademik Geri Bildirimler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı
- 2. Soft Etiketlerle Karar Ağacı Eğitimi
- 3. Improved Space Forest'ın Python Uygulaması
- 4. Yapay Örnek Üretimi: SMOTE, ADASYN ve BorderlineSMOTE
- 5. Online Ağaçlardan Topluluk
- 6. Yapay Sinir Ağı Çözümleri Arasındaki Yol Üzerinden Topluluk
- 7. Metropolis/MCMC ile Hata-Parametre Yüzeyi Keşfi
- 8. Kappa-Hata Diyagramları ve Maksimum Derinlik Analizi
- 9. Topluluk İçinde Topluluk (Ensemble-in-Ensemble)
- 10. Improved Space ve Ardışık Topluluklar: AdaBoost ve XGBoost
- 11. MCMC Rastgele Yürüyüşünde Ağırlıkların Sonsuza Gitmesi
- 12. Soft Etiketlerin Motivasyonu ve Düğümde Kullanımı
- Örnek Sorular

## 1. Dersin Yapısı

Bu derste yeni bir konu anlatılmadı. Öğrenciler dönem projelerindeki ilerlemeyi ekran paylaşarak gösterdi, hoca da her projeye geri bildirim verdi. Projeler daha önceki haftalarda işlenen yöntemlerin üzerine kuruludur: karar ağaçları, bagging, AdaBoost, random forest, Improved Space Forest ve yapay sinir ağlarıyla kolektif öğrenme. Bu not, sunumları kişisel bilgilerden arındırarak yalnız akademik noktalarıyla aktarır. Sunum yapan öğrenciler "bir öğrenci" diye anılır.

Tartışmaların çoğunda tekrar eden üç ilke vardır. Birincisi, başarı test kümesinde ölçülür; eğitim başarısı tek başına önemli değildir. İkincisi, topluluklar karşılaştırılırken ağaç sayısı ya da toplam eğitim süresi eşit tutulmalıdır. Üçüncüsü, bir algoritmayı değiştirirken algoritmanın paralel mi ardışık mı çalıştığı önemlidir.

## 2. Soft Etiketlerle Karar Ağacı Eğitimi

### 2.1 Öğrencinin ilk yaklaşımı

İlk sunumu yapan öğrenci, soft (yumuşak) etiketli ağaçlar üzerine literatür taramıştı. Literatürde iki yaklaşım öne çıkıyordu. Birincisi yapay sinir ağlarının kararlarını kullanarak etiketleri yumuşatmak, ikincisi CART'taki gibi Gini indeksini kullanmaktır. Gini indeksi, bir düğümün örnekleri ne kadar başarılı grupladığını, yani bölmenin saflığını ölçer.

Öğrenci, soft etiketli bir ağaçta düğümlerin olasılıksal çıktılar verip bunları bir sonraki düğüme aktaracağını düşünmüştü. Ekrandaki çizimde "Multiple Split, not just a one correct way. If there is a possibility, it goes for it." notu ve kök düğüm için "Input: A data row with exact decision. Example: C1: %100 / A Rule, Output C1:%30, C2:%60, C3:%10" açıklaması vardı. Alt düğüm için de "Input: Results of upper node, with their probabilities. A Rule, Output C1:%70, C2:%15, C3:%15" yazıyordu (ekrandan, 00:05:00). Hoca, kastettiği şeyin bu olmadığını söyledi.

### 2.2 Doğru yöntem: output smoothing

Hocanın anlattığı işlemin adı output smoothing'dir. Normalde eğitim ve test örneklerinin etiketleri one-hot kodludur: bir sınıf 1 (yüzde yüz), diğerleri 0'dır. Yöntem yalnız eğitim kümesinin etiketlerini değiştirir.

```text
Birinci aşama:
  1. Eğitim kümesiyle bir ağaç (ya da bir topluluk) eğitilir.
  2. Eğitim kümesi bu modele test gibi verilir.
  3. Her eğitim örneği için her sınıfa ait olma olasılığı bulunur:
     - tek ağaçta: örneğin düştüğü yaprak düğümdeki sınıf dağılımı,
     - toplulukta: kaç ağacın A, kaç ağacın B dediği.
  4. Etiketler one-hot yerine olasılık vektörü olur (ör. %60, %30, %10).
İkinci aşama:
  5. Bu soft etiketlerle yeni bir ağaç eğitilir.
```

Öğrencinin "elma olan bütün örneklerin nerelerde sonlandığına bakarak mı olasılık çıkaracağız" sorusuna hoca hayır dedi. Her örnek için yalnız o örneğin düştüğü yaprağa bakılır ve oradaki sınıf dağılımı alınır. Birinci aşamada ağacın eğitiminde hiçbir farklılık yoktur.

### 2.3 İkinci aşamada ne değişir?

Hocaya göre tek değişen nokta, herhangi bir düğümde özellik ve eşik ikilisini bulma kısmıdır. Normal karar ağacı Gini indeksine ya da entropiye one-hot etiketler üzerinden bakar. Burada ise bölme, soft etiketlere göre optimum olan özellik ve eşikten yapılır. Bunun dışında karar ağacının bütün algoritması aynıdır.

**Soru:** Test aşamasında bir örnek olasılıklı olduğu için iki alt düğüme de gitmek zorunda değil mi?
**Cevap:** Hayır. Düğüm, örneğin "F1 özelliği 3'ten büyük mü" gibi bir kural bulur. Bu kural ister one-hot etiketlerle ister soft etiketlerle bulunsun, örnek kurala göre ya sağa ya sola gider. Olasılıklı bir sağa-sola gitme yoktur. Düğümdeki bölmeler sınıf değildir, yalnız yön belirtir.

Hoca, öğrencinin ayrıca rapor göndermesine gerek olmadığını, toplantıda gösterilenleri rapor olarak alacağını söyledi. Bu konu dersin sonunda aynı öğrencinin sorularıyla yeniden açıldı (Bölüm 12).

## 3. Improved Space Forest'ın Python Uygulaması

### 3.1 Öğrencinin yaptığı

İkinci öğrencinin konusu Improved Space Forest'tı. Öğrenci, hocanın MATLAB kodunu Python'a çevirmişti. Ekrandaki tabloda 41 veri kümesi için Imp_RF, RF, Imp_RF_2, RF_2, Imp_Adaboost ve Adaboost sütunları vardı (ekrandan, 00:15:00). Bazı satırlar:

| Veri kümesi | Imp_RF | RF | Imp_RF_2 | RF_2 | Imp_Adaboost | Adaboost |
|---|---|---|---|---|---|---|
| ionosphere | 0.8636 | 0.8636 | 0.9375 | 0.9261 | 0.9205 | 0.8807 |
| diabetes | 0.7188 | 0.6979 | 0.7682 | 0.7526 | 0.7031 | 0.6693 |
| hepatitis | 0.8333 | 0.7949 | 0.8205 | 0.8333 | 0.8462 | 0.7692 |
| vowel | 0.6747 | 0.6424 | 0.8202 | 0.8727 | 0.7232 | 0.7010 |
| hillValley | 0.8845 | 0.5050 | 0.9703 | 0.4917 | 0.9076 | 0.5281 |

RF sütunlarında öğrenci bootstrap, karar ağaçları ve oylamayı kendisi yazmıştı. RF_2 sütunlarında ise scikit-learn'ün hazır `RandomForestClassifier`'ını kullanmıştı. Hazır fonksiyonun sonuçları daha yüksek çıkmıştı. Öğrenci bir veri kümesini okuyamamıştı, kalan 40 kümede sorun yoktu. Improved RF daha iyiydi, ama fark büyük değildi.

**Soru (hocadan):** Kendi yazdığın RF'te ağaçlar gerçekten rastgele mi, yani her bölmede bütün özellikler kullanılmıyor mu?
**Cevap:** Öğrenci, her ağaç için eğitim kümesini ayrı ayrı oluşturduğunu ve hocanın kodunun aynısını yaptığını söyledi.

### 3.2 Uzay her ağaç için ayrı oluşturulmalı

Öğrenci önce veri kümesini bir kez genişletip Random Forest'a 10 ağaç kurdurmuştu. Sonra hocanın kodunda yeni uzayın her ağaç için yeniden oluşturulduğunu fark edip düzeltmişti. Improved Space'in özü budur: her ağaç orijinal özelliklerin yanına farklı ek özellikler alır.

### 3.3 Eğitim ve testin ayrılması

Hoca kendi kodundaki bir kullanım sorununa dikkat çekti. Kodda eğitim ve test kümesi yönteme birlikte veriliyor, yeni özellikler eğitim kümesi üzerinde oluşturuluyordu. Bu, adillik açısından sorun değildir, ama kullanım açısından sorundur. Doğrusu önce algoritmayı eğitmek, sonra "bunu al, şununla test et" diyebilmektir. Bunun için eğitim fonksiyonu oluşturduğu uzayları çıktı olarak vermelidir: hangi özellik ikilileri alındı, onlar nelerle çarpıldı. Test fonksiyonu bunları girdi olarak alıp test kümesine aynı dönüşümü uygulamalıdır.

### 3.4 AdaBoost ve XGBoost

Öğrenci scikit-learn AdaBoost'una dışarıdan, önceden oluşturulmuş ağaçları veremediğini söyledi. AdaBoost yalnız veri kümesini alıyor, ağaçları kendi içinde oluşturuyordu. Hoca, bunun için AdaBoost'u ya baştan yazmak ya da mevcut implementasyonun içine girip değiştirmek gerektiğini söyledi. Öğrenciye MATLAB'daki AdaBoost implementasyonunu gönderebileceğini belirtti. Bagging'in daha kolay olacağını, çünkü Random Forest'tan farkının yalnız seçim kısmında olduğunu öğrenci de not etti.

> **Hocanın vurgusu:** XGBoost da temelde AdaBoost gibi artımlı (incremental) ilerleyen, paralel gidemeyen bir algoritmadır ve içinde birkaç yapı daha vardır. AdaBoost yapılamıyorsa XGBoost hiç olmaz. Önce eğitim-test ayrımını düzelt, sonra AdaBoost'a, onu çözersen XGBoost'a bak.

Hoca ayrıca çapraz doğrulama (cross-validation) yapılmasını ve iki metin veri kümesinin de kullanılmasını hatırlattı.

## 4. Yapay Örnek Üretimi: SMOTE, ADASYN ve BorderlineSMOTE

### 4.1 Deney düzeni

Üçüncü öğrencinin konusu yapay örnek üretimiydi. Üç algoritma kullanmıştı: SMOTE, ADASYN ve BorderlineSMOTE. Bu algoritmalar dengesiz veri kümelerinde azınlık sınıfı için sentetik örnek üretmek amacıyla önerilmiştir.

Öğrenci, literatürde dengelilik için ortak bir tanım olmadığını, bazı çalışmaların 0.5'e 0.5'i dengeli saydığını söyledi. Buna dayanarak en küçük ve en büyük sınıf oranına göre bir sınıflandırma yaptı (ekrandan, 00:25:00):

| Veri kümesinin dengeliliği | Min-Max örnek oranı |
|---|---|
| Dengeli | $Min \ge 0.45$ ve $Max \le 0.55$ |
| Kısmen dengeli | $0.40 \le Min < 0.45$ ve $0.55 < Max \le 0.6$ |
| Kısmen dengesiz | $0.25 \le Min < 0.4$ ve $0.4 < Max \le 0.75$ |
| Dengesiz | $Min < 0.25$ ve $Max > 0.75$ |

Seçilen üç küme şunlardı: vowel (990 örnek, 11 sınıf, oran 0.0909-0.0909, dengeli), credit-g (1000 örnek, 2 sınıf, 0.3-0.7, kısmen dengesiz) ve hepatitis (155 örnek, 2 sınıf, 0.2064-0.7935, dengesiz) (ekrandan, 00:25:00).

> **Ders sonrası not:** Tablodaki eşikler iki sınıflı kümeler için yazılmıştır. Vowel'de 11 sınıfın hepsi eşit büyüklükte olduğu için en küçük ve en büyük oran aynıdır (0.0909 = 1/11), yani küme tam dengelidir. Ama oranlar tablodaki "Dengeli" eşiklerine uymaz. Çok sınıflı kümelerde oranları $1/K$'ye göre ölçeklemek büyük olasılıkla daha tutarlı olur.

Deneylerde 10 katlı çapraz doğrulama kullanıldı. Yapay örnekler yalnız eğitim kümesine eklendi, test kümesinde üretim yapılmadı. Üretim 20 aşamada yapılıyordu. İlk aşamada sınıflar eşitlenip veri dengeli hâle getiriliyor, sonraki her aşamada her sınıfa 100'er örnek ekleniyordu. Sınıflandırıcı olarak önce karar ağacı, sonra yapay sinir ağı kullanılmıştı. 10 kat ve 20 aşama, tek bir veri kümesi için 200 eğitim süreci demekti; bu yüzden deneyler çok uzun sürüyordu.

### 4.2 Hocanın önerisi: aşama sayısı ve örnek sayısı

Hoca 20 aşamaya gerek olmadığını, 4-5 aşamanın da ilerlemeyi göstereceğini söyledi. Ayrıca her aşamada sabit 100 örnek eklemek yerine eklenecek sayının veri kümesinin boyutuna bağlı olmasını önerdi. Örneğin eğitim kümesinde 1000 örnek varsa her aşamada 200'er, 100 örnek varsa 20'şer örnek eklenebilir.

> **Hocanın vurgusu:** Eğitim kümesini son adımda iki katının çok üstüne çıkarmanın bir anlamı yoktur. Birinci aşamadaki dengeleme sonrasında oluşan boyut en fazla iki katına çıkacak şekilde oranlanmalıdır.

### 4.3 Sonuçlar

Öğrenci algoritmanın kararlılığını, aşamalar arasındaki başarı değişimlerinin varyansıyla ölçtü. GBM sütunu, yapay örnek eklenmemiş orijinal veriyle 10 katlı başarıya göre galibiyet-beraberlik-mağlubiyet (G-B-M) sayısını verir. Hepatitis için (ekrandan, 00:30:00):

| Yapay örnek üretim algoritması | Algoritma kararlılığı | G-B-M |
|---|---|---|
| SMOTE | 0.01566 | 1-1-18 |
| BorderlineSMOTE | 0.01261 | 0-2-18 |
| ADASYN | 0.01237 | 0-0-20 |

Algoritmaların birbirine göre üstünlükleri de verildi (satırdaki algoritmanın sütundakine göre G/B/M sayısı):

| | SMOTE | BorderlineSMOTE | ADASYN |
|---|---|---|---|
| SMOTE | - | 10/2/8 | 11/2/7 |
| BorderlineSMOTE | 8/2/10 | - | 9/0/11 |
| ADASYN | 7/2/11 | 11/0/9 | - |

Her satırın toplamı 20 aşamaya eşittir ve tablo simetriktir (python ile kontrol edildi). Hepatitis'te yapay örnek eklemek başlangıç başarısını neredeyse hiç geçememiştir. Öğrenciye göre SMOTE diğer ikisinden daha kararsızdı. Dengesizden dengeliye geçildikçe SMOTE'un başarısını kaybettiğini, ADASYN'in öne çıktığını gözlemledi.

Vowel kümesinde tablo tamamen farklıydı: SMOTE 0.04177, BorderlineSMOTE 0.04011 ve ADASYN 0.03870 kararlılık değerleriyle 20 aşamanın hepsinde başlangıcı geçti (20-0-0). Doğruluk-veri boyutu grafiğinde başarı yaklaşık 0.76'dan 0.95'e yükseliyordu (ekrandan, 00:35:00). Hoca, burada başarının artarken kararlı da kaldığını, bu kümenin yapay örnek eklemeye daha uygun göründüğünü söyledi.

### 4.4 t-SNE görselleştirmesi

Öğrenci, orijinal kümeyi ve belli bir aşamadan sonra üretilen yapay örnekleri t-SNE ile iki boyutta gösterdi. Hepatitis için grafiklerin başlığında "Training Size: 3600" yazıyordu (ekrandan, 00:35:00). Hoca, üretilen örneklerde iki sınıfın dengeli görünmediğini, mavilerin fazla göründüğünü fark etti.

**Soru (hocadan):** Yeni oluşan veri kümesinde birinci ve ikinci sınıftan kaç örnek olduğuna t-SNE uygulamadan baktın mı?
**Cevap:** Öğrenci baktığını, sayıların eşit çıktığını, noktaların birbirine çok yakın olduğu için t-SNE'de üst üste binmiş olabileceğini söyledi. Hoca bir kez daha kontrol etmesini istedi.

### 4.5 BorderlineSMOTE ile ADASYN'in benzerliği

Öğrenci iki algoritmanın mantığını şöyle açıkladı. BorderlineSMOTE her azınlık örneğinin $k$ en yakın komşusuna bakar. Komşuların hepsi çoğunluk sınıfındansa örneği gürültü sayar ve ondan örnek üretmez. Komşuların çoğunluğu çoğunluk sınıfındansa örneği sınır örneği (border example) sayar ve ondan üretim yapar. ADASYN de komşulara bakar, ama bir örnekten üretilecek yapay örnek sayısını, komşuları arasındaki çoğunluk sınıfı örneklerinin sayısıyla doğru orantılı belirler. Örneğin beş komşunun beşi de çoğunluk sınıfındansa beşle, üçü çoğunluk sınıfındansa üçle orantılı üretim yapılır. Bu benzerlik yüzünden öğrenci iki algoritmanın G-B-M sonuçlarının yakın çıkmasını beklemişti, ama bu her veri kümesinde gerçekleşmedi.

> **Ek bilgi (derste anlatılmadı):** SMOTE'ta yeni örnek, bir azınlık örneği $x_i$ ile azınlık sınıfındaki rastgele bir komşusu $x_{nn}$ arasındaki doğru parçası üzerinde üretilir: $x_{yeni} = x_i + \lambda (x_{nn} - x_i)$, burada $\lambda \in [0,1]$ rastgeledir. BorderlineSMOTE ve ADASYN aynı ara değerleme adımını kullanır; farkları hangi örneklerden ve kaçar tane üretileceğini seçmeleridir.

Öğrencinin ADASYN makalesinin beş veri kümesinin sınıf dağılımları birbirine yakındı. Buradan ADASYN'in dengeli kümelerde daha iyi çalışıp çalışmadığı sorusu doğdu. Karar ağaçlarıyla yapılan deneylerde sonuçlar YSA'dakinden biraz farklıydı, ama genel olarak SMOTE ve ADASYN daha iyi, BorderlineSMOTE daha zayıf çıktı.

## 5. Online Ağaçlardan Topluluk

### 5.1 Hoeffding ağacı ve kütüphane

Dördüncü öğrencinin konusu online ağaçlardan topluluk kurmaktı. Öğrenci, slaytlarda da yer alan 2000 yılındaki bilinen çalışmayı okumuştu. Bu çalışma Hoeffding ağacını tanımlar: veri akış (stream) hâlinde gelirken bir düğümün kaç örnekle oluşturulacağına karar veren bir yöntemdir. Öğrenci ayrıca 2017'de yayımlanan Adaptive Random Forest çalışmasını ve 2018'de yayımlanan scikit-multiflow kütüphanesini incelemişti.

Ekrandaki kod şöyleydi (ekrandan, 00:45:00):

```python
arf = AdaptiveRandomForestClassifier(n_estimators=200)
n_samples = 0
correct_cnt_ht = 0
correct_cnt_arf = 0
max_samples = dataArr.shape[0]

# Train the estimator with the samples provided by the data stream
while n_samples < max_samples and stream.has_more_samples():
    X, y = stream.next_sample()
    y_pred = ht.predict(X)
    yPred = arf.predict(X)
    if y[0] == y_pred[0]:
        correct_cnt_ht += 1
    if y[0] == yPred[0]:
        correct_cnt_arf += 1
    ht = ht.partial_fit(X, y)
    arf = arf.partial_fit(X, y)
    n_samples += 1
```

Terminalde iris için (150 örnek) "Hoeffding Tree accuracy: 0.9133..." ve "ARF accuracy: 0.9266..." gibi çıktılar görünüyordu (ekrandan, 00:45:00).

### 5.2 Bu döngü eğitimdir

Öğrenci, her yeni örneğin önceki ağaç için test verisi gibi olduğunu, bu yüzden ayrıca test yapıp yapmayacağını sordu.

**Soru:** Akıştaki her yeni örnek önce tahmin edildiğine göre bu bir doğrulama (validation) sayılır mı?
**Cevap:** Hayır, bu kısım tamamen eğitimdir. Ağaç zaman içinde değişir, bütün örnekler bittiğinde ağaç bitmiş olur. Veri kümesi önce eğitim ve test diye ikiye ayrılmalı, biten ağaç test kümesine verilip sonuçlar oradan alınmalıdır. Şu anki sayılar yalnız eğitim kümesi üzerinde olduğu için çok anlamlı değildir.

Hoca ayrıca bu döngüde tek bir ağacın küçük bir yerden başlayıp giderek büyüdüğünü, farklı ağaçlar üretilmediğini vurguladı. Adaptive Random Forest'ın projeyle ilgisi olmadığını, Hoeffding ağacının yeterli olduğunu söyledi.

### 5.3 Topluluk farklı sıralarla kurulur

Projede amaç şudur: aynı algoritma veriyi farklı sıralarda aldığında farklı ağaçlar oluşur. Her ağaç bütün eğitim kümesini kullanır, ama sıra farkı yüzünden ağaçlar farklı sonuçlar üretebilir. Bu ağaçlar topluluk hâline getirilir ve test kümesinde tek ağaçla karşılaştırılır.

Öğrenci, numpy'ın shuffle fonksiyonuyla satırları karıştırdığında sonucun hep daha kötü çıktığını, orijinal sırayla %95 olan başarıya hiç ulaşamadığını söyledi. Hoca, karıştırmanın yalnız eğitim verisinde yapılması gerektiğini belirtti.

> **Ek bilgi (derste anlatılmadı):** UCI'daki iris dosyası sınıflara göre sıralıdır (önce 50 setosa, sonra 50 versicolor, sonra 50 virginica). Önce tahmin edip sonra öğreten bu tür akış doğruluğunda ardışık örnekler büyük olasılıkla aynı sınıftan geldiği için tahmin kolaylaşır. Bu yüzden sıralı veriyle görülen yüksek akış doğruluğu, karıştırılmış veriye göre yanıltıcı biçimde iyimser olabilir. Ayrı test kümesi bu sorunu ortadan kaldırır.

## 6. Yapay Sinir Ağı Çözümleri Arasındaki Yol Üzerinden Topluluk

### 6.1 Makale ve deney

Beşinci öğrencinin konusu YSA çözümlerini birleştirmekti. Öğrenci derste verilen "Essentially No Barriers in Neural Network Energy Landscape" makalesine odaklanmıştı. Makaledeki yolu bulma yöntemini Python'da (Keras) kodlayamamıştı. Bunun yerine şu deneyi yaptı:

```text
1. İki ağ bağımsız eğitilir: uç noktalar Q0 ve Q10 (her biri 200 epok).
2. İki uç noktanın ağırlıklarını birleştiren doğru üzerinde 9 ara nokta (Q1..Q9) alınır.
   Bu noktalarda kayıp yüksektir (Fig. 1: kayıp uçlarda ~0.5, ortada ~3.5'e çıkar).
3. Her ara noktadan başlayarak ağ 20 epok daha gradyan inişiyle eğitilir.
   Kayıplar ~0.5'e iner (Fig. 2, yeşil eğri).
4. Yeni noktalar ve Q0, Q10 boyut indirgemeyle 3 boyutta gösterilir (Fig. 3).
5. Ara modellerle ve uç modellerle topluluklar kurulur, test başarıları karşılaştırılır (Fig. 4).
```

(ekrandan, 00:55:00 ve 01:00:00)

3 boyutlu gösterimde yeni noktalar makaledeki gibi düzgün bir yol oluşturmadı, daha çok bir bölgede toplandı. Öğrenci bunun seçilen 9 noktadan kaynaklanıp kaynaklanmadığını merak etti.

Fig. 4'te ara modellerin tekil doğrulukları çoğunlukla 0.825-0.836 arasındaydı, biri yaklaşık 0.79'du. Ara modellerle kademeli kurulan topluluğun doğruluğu yaklaşık 0.835'ten başlayıp 9 modelde 0.85'e çıktı (öğrenciye göre 0.851). Q0 ve Q10'un topluluğu ise 0.845 civarındaydı (ekrandan, 00:55:00). Yani ara noktalar toplulukta az bir artış sağladı.

### 6.2 Adil karşılaştırma: eğitim bütçesi

> **Hocanın vurgusu:** Karşılaştırma toplam eğitim süresi açısından adil olmalıdır.

Hoca hesabı şöyle kurdu: Q0 ve Q10 200'er epok, toplam 400 epok. Ara modelleri elde etmek için bunun üstüne her biri 20 epokluk 9 eğitim daha gerekir. Hoca kabaca 10 nokta alarak toplamı 600 epok diye söyledi. Doğru karşılaştırma için öbür tarafta da aynı bütçeyle, örneğin 200'er epokluk 3 bağımsız modelle bir topluluk kurulmalıdır. İki topluluğun eğitim süresi eşitse ve yol üzerinden kurulanın başarısı yüksekse, yöntem işe yarıyor denebilir. Şu durumda biri 600, biri 400 epok olduğu için bilinmez; uçlara bir model daha eklenince 0.85'in üstüne çıkabilir.

> **Ders sonrası not:** 9 nokta ile hesap $2 \times 200 + 9 \times 20 = 580$ epoktur. Hoca 10 nokta alarak 600 dedi. Ara eğitim 10 epoka indirilirse $400 + 9 \times 10 = 490$ epok olur; hocanın "500 olur" dediği değer budur (python ile kontrol edildi).

Hoca ayrıca ara noktalardaki 20 epokluk eğitimin azaltılabileceğini söyledi. Öğrenci 10 epokla da denediğini, beşinci noktanın kaybının biraz yüksek kaldığını (yaklaşık 0.65) söyledi.

### 6.3 Orta noktadaki kırılma

Hoca, Fig. 2'de 4 ile 6 arasındaki orta noktadaki farklı davranışı ilginç buldu. Başka bir makalede de A'dan B'ye giden yolda tam orta noktanın bir tür kırılma noktası gibi davrandığını hatırladı. Bu sapmayı düzeltmeye çalışmak bir araştırma yönü olabilir. Öğrenci, makaledeki DenseNet ve ResNet deneylerini CIFAR-100 üzerinde tekrarlamayı planladığını söyledi; hoca bu şekilde devam edebileceğini belirtti.

> **Ek bilgi (derste anlatılmadı):** "Essentially No Barriers in Neural Network Energy Landscape" (Draxler ve arkadaşları, 2018) iki minimumu düz bir doğru yerine kayıp yüzeyinde bükülen bir yolla birleştirir. Yolu bulmak için büyük olasılıkla AutoNEB (nudged elastic band) adlı, yol üzerindeki noktaları yayla birbirine bağlıymış gibi birlikte optimize eden bir yöntem kullanır. Doğru üzerindeki noktaları ayrı ayrı eğitmek ise noktaları yoldan bağımsız yerel minimumlara kaydırabilir; öğrencinin 3 boyutlu grafikteki gözlemi bununla açıklanabilir.

### 6.4 Doğru yaklaşım: sıradan topluluk değil, yol üzerindeki noktalar

Aynı konuyu çalışan bir başka öğrenci farklı bir yol izlemişti. CIFAR-10 üzerinde iki gizli katmanlı (128 nöron, ReLU) bir ağı farklı ilk ağırlıklarla 5 kez eğitmişti (ekrandan, 01:05:00):

| Model | Loss | Accuracy |
|---|---|---|
| Model 1 | 1.5255 | 0.4708 |
| Model 2 | 1.6604 | 0.4344 |
| Model 3 | 1.6959 | 0.3948 |
| Model 4 | 1.6676 | 0.4131 |
| Model 5 | 1.7897 | 0.3649 |

Bu modellerin son noktalarını birleştirdiğinde şu sonuçları almıştı:

| | Eşit oy hakkı | Test başarılarına orantılı oy hakkı |
|---|---|---|
| Tüm modeller | 0.4829 | 0.4852 |
| En başarılı üç model | 0.4871 | 0.4880 |

En iyi tekil model 0.4708 olduğundan, eşit oylu topluluk yaklaşık 1.2 puanlık artış sağlıyor.

Hoca, bu öğrencinin öbür öğrencinin yolunda ilerlemesi gerektiğini söyledi. Projede topluluk düz topluluklar üzerinden kurulmayacak. Her veri kümesi-mimari ikilisinde (ör. CIFAR, CIFAR-100; toplam 5 ikili) iki model eğitilecek ve iki son nokta olacak. Topluluk, bu iki noktayı birleştiren çizgi ya da çevresindeki noktalardan kurulacak. Yani $K$ ayrı model üretip birleştirmek bu projenin konusu değildir.

## 7. Metropolis/MCMC ile Hata-Parametre Yüzeyi Keşfi

Altıncı öğrencinin konusu Metropolis-MCMC ile hata-parametre yüzeyini keşfetmekti. Öğrenci farklı başlangıç noktalarından bir yere kadar eğitip sonra aramaya başlamış, Waveform veri kümesinde farklı sigma değerlerini denemişti. Ayrıca kabul oranı $\alpha < 1$ olduğunda $\alpha$'nın üstelini alarak bu durumlarda seçilme olasılığını düşüren bir ekleme yapmıştı.

Raporda iki figür vardı (ekrandan, 01:10:00 ve 01:15:00):

- Figure 1, Waveform, $\sigma = 0.001$, $n = 1000$ adım: 1. denemede skor yaklaşık 0.875'ten 0.880'e çıkıyor. 2. denemede (başlangıç yaklaşık 0.69) ve 3. denemede (başlangıç yaklaşık 0.735) bulunan noktalar başlangıçtan daha kötü.
- Figure 2, Waveform, $\sigma = 1$, aynı başlangıçlar: 1. denemede skorlar 0.8789-0.8792 arasında dalgalanıyor. 2. ve 3. denemelerde de küçük dalgalanmalar var.

Hoca, sol üstteki ve sol alttaki grafiklerin aynı başlangıçtan farklı sigmalarla başladığını teyit etti. Öğrenci şu sonuçları çıkardı:

- Minimize edilmiş parametre uzayından daha başarılı parametre değerleri elde edilebilir; yani model daha da başarılı olabilir.
- Farklı sigma değerleri için daha başarılı model elde etme durumları farklıdır. Başarı sigma ile doğru ya da ters orantılı değil, deneme yanılmayla bulunuyor.
- 1000 adımın çoğunda (öğrenciye göre yaklaşık 990'ında) başarı aynı, ama parametreler farklıdır. Yani yüzeyde aynı başarıyı veren geniş bölgeler vardır.

<!-- BELİRSİZ: Öğrencinin sigma=1 ikinci denemede başarının "940'dan 956'ya" yükseldiğini söylediği değerler karelerdeki eksenlerle eşleştirilemedi. -->

Hoca, bir veri kümesiyle yorum yapılamayacağını, daha fazla veri kümesinde ve daha büyük mimarilerde denemeler yapıldıkça yorumlanacak şeylerin ortaya çıkacağını söyledi. Bilgisayar büyük modelleri kaldırmıyorsa mimari küçültülerek CIFAR'da denenebilir.

> **Hocanın vurgusu:** Benim söylediklerimi harfiyen uygulamanız beklenmiyor. Kendiniz inisiyatif alın; sizler araştırmacı olacaksınız.

## 8. Kappa-Hata Diyagramları ve Maksimum Derinlik Analizi

### 8.1 Kappa-hata grafikleri

Yedinci öğrenci, Random Forest ve Bagging için kappa-hata diyagramları çizmişti. Topluluktaki tekil öğrenicilerin ikili kombinasyonları için kappa değerlerini bulup ortalamasını almıştı. Grafikte dikey eksen kappa, yatay eksen hatadır. Renkler mor-maviden kırmızıya doğru tekil öğrenici sayısını (10, 20, ..., 100) gösterir. Ekranda "Random Forest Full Ağaç Tekil Öğrenici Sayısına Göre Kappa - Error" ve "Bagging Full Ağaç ..." başlıklı grafikler iris ve hepatitis için yer alıyordu (ekrandan, 01:20:00).

Sol alt köşe en iyi bölgedir: hata düşük ve kappa düşüktür, yani öğreniciler hem başarılı hem birbirinden farklıdır. Öğrencinin gözlemine göre veri kümeleri ortak bir örüntü izlemiyordu.

**Soru:** Şu anda test kümesi yok; kappa ve hatalar eğitim kümesinden hesaplandı. Testle mi yapmalıyım?
**Cevap:** Teste bakmalıyız. Eğitim ve test grafikleri yan yana konmalı; aynı veri kümesinin iki hâlini birlikte görmek iyi olur. İki grafik yerine dört grafik yan yana görülebilir.

Hoca ayrıca her renk grubunun (10, 20, 30, ... öğrenici) yanına topluluğun başarısının yazılmasını istedi: eğitim grafiğinde eğitim başarısı, test grafiğinde test başarısı. Random Forest'ta noktalar sol alt köşeye uzaklığı pek değiştirmeden paralel gidiyordu. Bagging'de ise oraya yaklaşan durumlar vardı. Topluluk başarıları yazılmadan hangisinin en iyi olduğu anlaşılamaz.

### 8.2 Maksimum derinlik analizi

Projede tekil öğrenicilerin maksimum derinliği 50'ye kadar artırılıyor, ayrıca "None" (sınırsız derinlik) da deneniyordu. Random Forest'ta 36 veri kümesinin yaklaşık 30'unda düz bir çizgi çıktı. Bagging'de ise V şeklinde ve aşağı inen örüntüler de vardı.

### 8.3 scikit-learn AdaBoost'un erken durması

Öğrenci, scikit-learn AdaBoost dokümantasyonunda "In case of perfect fit, the learning procedure is stopped early" yazdığını gösterdi (ekrandan, 01:25:00). Varsayılan temel öğrenici `max_depth=1` olan bir `DecisionTreeClassifier`'dır. Tam derinlikli ağaç verildiğinde eğitim kümesinde %100 başarıya ulaşıldığı için `n_estimators` ne verilirse verilsin tek tahminciyle kalınır. Bu yüzden AdaBoost projeye eklenemedi. Hoca yerine XGBoost gibi başka bir yöntem konabileceğini söyledi. Ayrıca iki metin veri kümesinin de denenmesini, kappa ölçüsü olarak mevcut kappayla devam edilebileceğini belirtti.

## 9. Topluluk İçinde Topluluk (Ensemble-in-Ensemble)

### 9.1 Deep Ensemble

Sekizinci öğrencinin konusu topluluk içinde topluluktu. Hoca fikri şöyle netleştirdi: 100 ağacı birlikte birleştirmek yerine 10'arlı gruplar birleştirilip sonra bu 10 sonuç yeniden birleştirilebilir. Öğrencinin yaptığı ise beş farklı yöntemin 100'er ağaçlı topluluklarını alıp kararlarını yeniden birleştirmekti.

36 veri kümesinde yöntemler karşılaştırıldı. Eşit değere sahip yöntemlerin ikisi de kazanan sayıldı. Kazanma oranları: RF %30.0, XGB %23.3, GBM %21.7, BG %16.7, AB %8.3. En zayıf AdaBoost çıkarılınca: RF %32.2, XGB %27.1, GBM %23.7, BG %16.9 (ekrandan, 01:30:00). Sonra Bagging de çıkarıldı. Öğrenci, tekil öğrenicilerin başarısı yükseldikçe topluluk başarısının arttığı mantığıyla en iyi üç yöntemi (RF, GBM, XGB) aldı ve önce çoğunluk oylamasıyla (hard voting) bir "Deep Ensemble" kurdu.

Deep Ensemble-2'de RF, GBM ve XGB kararları soft voting ile birleştirildi. RF > XGB > GBM sıralaması bütün denemelerde aynı olduğu için RF'in kararına daha çok ağırlık verildi; diğerlerinin ağırlığı RF'inkinin yarısıydı. Sonuçlar (ekrandan, 01:35:00):

| Karşılaştırma | Tekil yöntem | Deep Ensemble-2 |
|---|---|---|
| RF x Deep Ensemble-2 | %40.0 | %60.0 |
| GBM x Deep Ensemble-2 | %28.6 | %71.4 |
| XGB x Deep Ensemble-2 | %31.8 | %68.2 |

Rapora göre kazanma oranı RF yönteminde %54.3'ten %60'a, XGB'de %60.9'dan %68.2'ye, GBM'de %69.2'den %71.4'e yükseldi.

### 9.2 Hocanın eleştirileri

İki seçenekli bir kazanma oranında iki yüzdenin toplamı zaten %100'dür. Bu yüzden pasta grafiği yerine tek bir sayı yazmak yeterlidir.

Asıl eleştiri karşılaştırmanın adilliğidir. RF'te 100 ağaç vardır, Deep Ensemble-2'nin içinde ise üç yöntemle toplam 300 ağaç vardır.

> **Hocanın vurgusu:** Karşılaştırılan yöntemlerin ağaç sayıları eşit tutulmalıdır. Topluluklarda ağaç sayısı arttıkça başarı zaten artar. 300 ağaçlı Deep Ensemble-2, 300 ağaçlı Random Forest ile karşılaştırılmalıdır; aksi hâlde "yendi" demek anlamlı olmaz.

Hoca ayrıca alt toplulukların hepsi farklı yöntemlerden olduğunda ve hepsi aynı yöntemden (ör. 10'ar ağaçlık RF grupları) olduğunda ne olduğunun görülmesini istedi. Mevcut sonuçlarda Random Forest diğerlerine göre daha başarılı görünüyordu. Öğrenci sahte haber ve spam mesaj metin kümelerini seçmişti, henüz eklememişti. Hoca, sonucun başarısız da çıkabileceğini, ama denenen bütün yolların ve birbirlerine göre karşılaştırmalarının raporda gösterilmesi gerektiğini söyledi.

## 10. Improved Space ve Ardışık Topluluklar: AdaBoost ve XGBoost

### 10.1 İkinci Improved Space uygulaması

Dokuzuncu öğrenci de Improved Space'i çalışmıştı. Önce orijinal verinin PCA ile iki boyuta indirilmiş hâllerini, sonra Improved Space'te özellikler eklendikten sonraki hâllerini gösterdi. Hoca, her ağaçta farklı özellikler eklendiğini, gösterilen görüntünün bunlardan yalnız birine ait olduğunu hatırlattı. Algoritma bazı veri kümelerinde (ör. colic ve diabetes) sınıfları daha ayrılabilir hâle getiriyor, bazılarında (ör. vowel) pek değiştirmiyordu.

Bagging sonuçlarında dört çubuk vardı: orijinal eğitim, Improved eğitim, orijinal test ve Improved test doğruluğu (ekrandan, 01:40:00). Örneğin balance-scale'de test doğruluğu 0.79'dan 0.89'a çıkarken audiology'de 0.89'dan 0.84'e düştü.

**Soru (hocadan):** Audiology'de başarı düşmüş, doğru mu anlıyorum?
**Cevap:** Öğrenci eğitimde yükseldiğini, testte düştüğünü söyledi. Hoca, eğitimin önemli olmadığını, testin önemli olduğunu söyledi. Kazanma-kaybetme sayımının çapraz doğrulamayla yapılacağını hatırlattı.

Aynı slaytta Bagging (BG) ile IS-f2-k1-BG, IS-f4-k1-BG, IS-f2-k2-BG ve IS-f4-k2-BG sütunlarından oluşan bir tablo da vardı. Örneğin 5 numaralı veri kümesinde BG 55.83 iken Improved Space sürümleri 97.52, 98.99, 95.41 ve 98.15 değerlerine ulaşıyordu (ekrandan, 01:40:00).

XGBoost sonuçlarında da artan ve eşit kalan yerler vardı. Örneğin test doğruluğu balance-scale'de 0.79'dan 0.9'a, iris'te 0.96'dan 1.0'a, vowel'de 0.65'ten 0.67'ye çıkarken colic'te 0.84'ten 0.82'ye düştü (ekrandan, 01:45:00).

### 10.2 Her ağaca ayrı uzay nasıl verildi?

Hoca, XGBoost'ta ve Random Forest'ta her ağaç için farklı özellik üretmenin nasıl yapıldığını sordu. Öğrenci hazır scikit-learn sınıflarını kullanmış, her biri tek ağaçlı (`n_estimators = 1`) 10 topluluk tanımlamıştı. Her topluluk için Improved Space üretme kodu ayrı çalışıyor, 10 topluluğun sonuçları birleştiriliyordu. Hoca bunu bir "hile" olarak niteledi ve hangi yöntemler için geçerli olduğunu açıkladı.

> **Hocanın vurgusu:** Random Forest ve Bagging için bu yaklaşım sorun değildir. AdaBoost ve XGBoost için geçerli değildir. Bu toplulukların sonuçları çoğunluk oylamasıyla birleştirilemez. AdaBoost'u ya da XGBoost'u tek ağaçla çalıştırmak, önceki ağacın eksik kaldığı noktaları tamamlamaya çalışan ardışık yapıyı ortadan kaldırır.

### 10.3 AdaBoost'ta neresi değişmeli?

Bir öğrenci AdaBoost'ta tam olarak neyin değişeceğini yeniden sordu. Hoca şöyle açıkladı. AdaBoost veri kümesinden örnekler seçer ve örneklerin seçilme dağılımını önceki ağaçların yanlış ve doğru yaptığı örneklere göre değiştirir. Bu kısma dokunulmaz. Değiştirilecek tek yer, her ağaç için veri kümesinde orijinal özelliklerin yanına ek özellikler eklemektir.

**Soru:** Eğitim ve test verisine yeni özellikleri zaten ekliyorum. Yeni özellik daha iyi bölüyorsa algoritma onu kendisi seçmez mi?
**Cevap:** Şu anda AdaBoost'a ya da XGBoost'a tek bir ağaç ürettiriyorsun; bu aslında topluluk değildir. Topluluk boyutu 5 olsa önce bir ağaç üretilir, sonra onu kullanarak ikinci, onu kullanarak üçüncü ağaç üretilir. Sürecin içinde her ağacın farklı eğitim kümesine (kendi ek özellikleriyle) sahip olması sağlanmalıdır. Topluluk boyutu 1 değil, 10, 20 gibi olmalıdır.

Hoca, hazır bir AdaBoost implementasyonu alınabileceğini, scikit-learn içindekinin biraz karışık olabileceğini, isteyene MATLAB implementasyonunu gönderebileceğini söyledi. Rotation Forest'ın projede şart olmadığını da ekledi.

## 11. MCMC Rastgele Yürüyüşünde Ağırlıkların Sonsuza Gitmesi

MCMC projesini yapan öğrenci bir soru daha sordu: normal dağılımdan alınan değeri önceki değere ekleyerek ilerlediğinde ağırlıklar belli bir adımdan sonra (öğrenciye göre yaklaşık 500. adımdan sonra) sonsuza gidiyordu. Örneğin başlangıçtaki 0.5, sonra 0.7, 1, 5, 10, 200 olup en sonunda $4 \times 10^{37}$ mertebesine çıkıyordu.

Hoca önce bunun olamayacağını söyledi. Bir noktada durulur, o noktanın etrafında ortalaması sıfır olan bir dağılımdan değer seçilip eklenir, gidilen yerde aynı hareket tekrarlanır. Bu bir rastgele yürüyüştür (random walk) ve sonsuza gitmez. Örneğin eğitim sonunda ağırlıklar $\pm 2$ arasındaysa ve $\sigma = 0.01$ ise her adımda eklenen değer çok küçüktür.

Sonunda hata bulundu: öğrenci normal dağılımın ortalamasını sıfır değil, önceki adımın değeri seçmiş, sonra bu değeri yine önceki değere eklemişti. Doğrusu ortalaması sıfır olan dağılımdan seçip önceki değere eklemektir:

$$w_{t+1} = w_t + \varepsilon_t, \quad \varepsilon_t \sim \mathcal{N}(0, \sigma^2)$$

Öğrencinin hatalı hâli ise $w_{t+1} = w_t + \mathcal{N}(w_t, \sigma^2) \approx 2 w_t$'dir; değer her adımda katlanarak büyür. Öğrenci daha önce `randn` ile aldığı değeri sigma ile çarpıp eklediğinde de sonsuza gittiğini söyledi; hoca orada da kesinlikle bir sorun olduğunu, kodun kontrol edilmesi gerektiğini söyledi.

> **Ders sonrası not:** Hatalı güncelleme python ile denendi. 0.5'ten başlayan değer her adımda yaklaşık ikiye katlandığı için float32 ile yaklaşık 129. adımda, float64 ile yaklaşık 1026. adımda sonsuza taşıyor. Öğrencinin söylediği "yaklaşık 500. adım" büyük olasılıkla kullandığı veri tipine ve başlangıç değerlerine bağlıdır. Doğru rastgele yürüyüşte ise 1000 adım sonra beklenen sapma yalnız $\sigma\sqrt{1000} \approx 0.32$ olur ($\sigma = 0.01$ için).

## 12. Soft Etiketlerin Motivasyonu ve Düğümde Kullanımı

Dersin sonunda ilk sunumu yapan öğrenci, soft etiketlerle ilgili sorularını hazırladığı bir sayfayla yeniden sordu (ekrandan, 02:00:00). Sayfada birinci aşamanın sonucu şöyleydi: "Kollektif yaklaşım ile (100 ağacın ne kararlar verdiğine bakarak) üretilen kararlar: Kırmızı, 3, Tatlı, Elma: %80 Elma, %20 Muz, %0 Limon; Sarı, 2, Ekşi, Limon: %80 Limon, %10 Muz, %10 Elma".

### 12.1 Neden soft etiket?

**Soru:** Her ağaca gerçek etiketleri vermek varken neden başka bir ağacın çıktısını yeni ağaçlara veriyoruz? Gerçek etiketi yüzde yüz biliyoruz; belli olasılıklarla hatalı bilgi vermiş olmuyor muyuz?
**Cevap:** Bir örnek hem elmaya hem armuta benzeyebilir. Ama etiketleyen kişi ona yalnız "elma" der ve diğer benzerlik bilgisini siler. Çok boyutlu bir uzayda bir nesne birden fazla şeye benzeyebilir. Onun hem elma hem armuta benzeyen bir şey olduğunu söyleyebilirsek, örneği çok daha iyi temsil etmiş oluruz.

Hoca bunu K-means ile Expectation-Maximization arasındaki farka benzetti. K-means her örneği kesin (hard) olarak bir kümeye atar. EM ise her örneğin her kümeye ait olma olasılığını bulur; yani her örnek belli olasılıklarla farklı kümelere aittir. Buradaki kazanım, etiketleme sürecinde kaybolmuş olan bilginin yeniden ortaya çıkarılmasıdır.

> **Ders sonrası not:** Hoca benzetmede EM'i "Expectation Minimization" diye adlandırdı; algoritmanın doğru adı Expectation-Maximization'dır.

### 12.2 Düğüm soft etiketleri nasıl kullanır?

**Soru:** Gini indeksi her kuralı uygulayıp sonuçların saflığını hesaplar ve kazancı en yüksek kuralı seçer. Burada "doğru sınıflandırıldı" demek mümkün olmayacak. Bir alt dala "doğru sınıflandırılanlar" ve "diğerleri" diye aktarım yapılamayacak. Yeni düğüme akan veriler hâlâ olasılık mı içerecek?
**Cevap:** Karar düğümünün özellik ve eşik değerini belirlemek için soft etiketler kullanılır, başka hiçbir yerde kullanılmaz. Bu kökte değil, bütün düğümlerde yapılır. Örneklerin etiketleri 0-1 yerine, örneğin %80 şu, %10 şu, %10 şu olur. Etiketler aşağı inerken değiştirilmez; olduğu gibi kalır. Etiketlerle oynanmaz, etiketlere göre optimizasyon yapılır. Ağaç deterministiktir.

Hocanın sezgisel kayıp örneği şuydu: %100 elma olan bir örneğe "armut" dersen 1 birimin hepsini kaybedersin. %80 elma, %20 armut olan bir örnekte ise verdiğin karara göre kaybın değişir. Optimizasyon, en az kaybı hangi özellik ve hangi eşikle oluşturabileceğimizi bulur.

> **Ders sonrası not:** Hoca "%80 elma, %20 armut olan bir şeye armut desen, pardon elma desen %80 kaybedersin" dedi. Doğrusu: "armut" denirse 0.8, "elma" denirse 0.2 kaybedilir (python ile kontrol edildi). Hocanın ilk söylediği ("armut desen") doğruydu, düzeltmesi yanlıştı.

> **Ek bilgi (derste anlatılmadı):** Soft etiketlerle Gini indeksi doğal biçimde genelleştirilebilir. Bir düğümdeki sınıf oranları, o düğüme düşen örneklerin olasılık vektörlerinin toplanıp normalize edilmesiyle bulunur; Gini $= 1 - \sum_c p_c^2$ bu oranlarla hesaplanır. Hard etiketlerde bu ifade olağan Gini indeksine indirgenir. Bölmenin değerlendirilmesi dışında ağaç algoritmasında bir değişiklik gerekmez.

## Örnek Sorular

**Soru 1** (ekrandan, 02:00:00): İkinci aşamada her ağaca gerçek etiketleri vermek varken neden başka bir ağacın (topluluğun) çıktısı olan soft etiketleri veriyoruz? Motivasyon nedir?

> **Çözüm (derste verildi):** Etiketleyen kişi birden fazla sınıfa benzeyen bir örneğe tek bir sınıf atayarak benzerlik bilgisini siler. Soft etiketler bu kaybolan bilgiyi geri kazanır ve örneği daha iyi temsil eder. Benzetme: K-means hard atama yapar; Expectation-Maximization her örneğin her kümeye ait olma olasılığını verir.

**Soru 2** (ekrandan, 02:00:00): Soft etiketleri girdi olarak alan bir düğüm olasılıkları nasıl kullanacak? Bir kural seçildikten sonra yeni düğüme akan veriler hâlâ olasılık içerecek mi?

> **Çözüm (derste verildi):** Soft etiketler yalnız her düğümde özellik ve eşik değerini seçerken kullanılır. Bu, bütün düğümlerde yapılır. Örnekler kurala göre deterministik olarak sağa ya da sola gider. Etiketler alt düğümlere değiştirilmeden aynen geçer; olasılıklar "paslanmaz", yalnız optimizasyonun ölçütü olurlar.

**Soru 3** (derste sözlü, 01:59:45): Bir örnek %100 elma ise ona "armut" demenin kaybı nedir? %80 elma, %20 armut olan bir örneğe "armut" ya da "elma" demenin kaybı nedir?

> **Çözüm (derste kısmen verildi, düzeltildi):** %100 elma örneğe "armut" demenin kaybı 1'dir (yüzde yüz). %80 elma, %20 armut örneğe "armut" demenin kaybı $1 - 0.2 = 0.8$, "elma" demenin kaybı $1 - 0.8 = 0.2$'dir. Hoca derste ikinci durumu "elma desen %80 kaybedersin" diye düzeltmişti; doğrusu yukarıdaki gibidir.

**Soru 4** (derste sözlü, 01:44:25): Improved Space'te her ağaca farklı özellik vermek için her biri tek ağaçlı 10 topluluk kurup sonuçlarını birleştirmek hangi topluluk yöntemleri için geçerlidir?

> **Çözüm (derste verildi):** Random Forest ve Bagging için geçerlidir, çünkü bu yöntemlerde ağaçlar birbirinden bağımsız (paralel) üretilir ve çoğunluk oylamasıyla birleştirilir. AdaBoost ve XGBoost için geçerli değildir. Bunlar ardışıktır: her yeni ağaç önceki ağaçların hatalarına göre üretilir. Tek ağaçlı AdaBoost ya da XGBoost bu ardışıklığı yok eder. Bu yöntemlerde algoritmanın içinde her turdaki ağaca kendi genişletilmiş eğitim kümesi verilmelidir; örnek ağırlıklarının güncellenmesine dokunulmaz.

**Soru 5** (derste sözlü, 01:50:11): Metropolis rastgele yürüyüşünde normal dağılımdan alınan değer önceki değere eklendiğinde ağırlıklar birkaç yüz adım sonra sonsuza gidiyor. Neden?

> **Çözüm (derste verildi):** Adım, ortalaması sıfır olan $\mathcal{N}(0, \sigma^2)$ dağılımından seçilip önceki değere eklenmelidir: $w_{t+1} = w_t + \varepsilon_t$. Öğrenci ortalaması önceki değer olan $\mathcal{N}(w_t, \sigma^2)$'den seçip yine $w_t$'ye eklemişti. Bu durumda $w_{t+1} \approx 2 w_t$ olur ve değer katlanarak büyür. Python denemesinde float32 ile yaklaşık 129, float64 ile yaklaşık 1026 adımda sonsuza ulaştı. Doğru yürüyüşte $\sigma = 0.01$ ile 1000 adımdaki beklenen sapma yalnız yaklaşık 0.32'dir.

**Soru 6** (derste sözlü, 00:57:14): İki uç model (Q0, Q10) 200'er epok eğitildi; aralarındaki 9 noktanın her biri 20 epok daha eğitildi. Ara modellerle kurulan topluluk, iki uç modelin topluluğuyla adil karşılaştırılabilir mi?

> **Çözüm (derste verildi, hesap python ile kontrol edildi):** Hayır. İki uç model $2 \times 200 = 400$ epok tutar. Ara modeller için $9 \times 20 = 180$ epok daha gerekir, toplam 580 epok (hoca kabaca 10 noktayla 600 dedi). Ara eğitim 10 epok olursa toplam $400 + 90 = 490$ epoktur. Adil karşılaştırma için öbür tarafta da aynı bütçeyle, örneğin 200'er epokluk 3 bağımsız modelden bir topluluk kurulmalıdır.

**Soru 7** (derste sözlü, 00:44:25): Online ağaçta her yeni örnek önce o anki ağaçla tahmin edilip sonra `partial_fit` ile öğretiliyor. Bu döngüden çıkan doğruluk bir doğrulama ya da test sonucu sayılır mı?

> **Çözüm (derste verildi):** Hayır, bu tamamen eğitimdir. Döngü bittiğinde tek bir ağaç büyütülmüş olur. Veri kümesi önceden eğitim ve test diye ayrılmalı, biten ağaç (ve farklı sıralarla eğitilmiş ağaçlardan kurulan topluluk) test kümesinde değerlendirilmelidir.

**Soru 8** (derste sözlü, 01:34:16): 100 ağaçlı Random Forest ile, RF, GBM ve XGB'nin 100'er ağaçlı topluluklarının birleştirilmesiyle kurulan Deep Ensemble-2 karşılaştırılıyor. Bu karşılaştırma adil midir?

> **Çözüm (derste verildi):** Hayır. Deep Ensemble-2'de toplam 300 ağaç vardır. Topluluklarda ağaç sayısı arttıkça başarı zaten arttığı için Deep Ensemble-2, 300 ağaçlı bir Random Forest ile karşılaştırılmalıdır.

## Dersin Toparlaması

Bu ders, dönem projelerinin ara değerlendirmesiydi. Tartışmalar, önceki haftalarda öğrenilen yöntemlerin uygulamada nasıl doğru kurulacağı üzerine yoğunlaştı. Soft etiketli ağaçlarda yalnız bölme ölçütünün değiştiği, Improved Space'te uzayın her ağaç için ayrı üretilip testte aynen kullanılması gerektiği, paralel ve ardışık toplulukların farklı ele alınması gerektiği görüldü. Yapay örnek üretiminde örnek sayısının veri boyutuna oranlanması, online ağaçlarda eğitim akışı ile test kümesinin ayrılması, YSA uç noktaları arasındaki yol üzerinden topluluk kurulması ve MCMC rastgele yürüyüşünün doğru tanımı da ele alındı.

Bütün projeler için ortak mesaj şudur: sonuçlar test kümesinde, çapraz doğrulamayla ve kazanma-kaybetme sayılarıyla raporlanmalı; topluluklar eşit ağaç sayısı ya da eşit eğitim süresiyle karşılaştırılmalıdır. Hoca, ilginç sonuç çıkan projelerin bir yayına dönüştürülebileceğini, raporların bu yüzden makale formatında istendiğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
