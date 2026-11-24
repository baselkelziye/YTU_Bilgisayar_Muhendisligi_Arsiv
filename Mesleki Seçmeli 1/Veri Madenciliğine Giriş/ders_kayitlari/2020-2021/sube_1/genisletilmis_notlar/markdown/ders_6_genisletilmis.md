# Ders 6 Genişletilmiş Notu: Karar Ağaçları, Bilgi Kazancı ve Aşırı Öğrenme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Naive Bayes Üzerine Bir Soru: Normalizasyon Gerekli mi?
- 2. Sınıflandırma Modeli Kurmanın Genel Yaklaşımı
- 3. Karar Ağacının Yapısı ve Kısmi Ağaç Örnekleri
- 4. Bölme Senaryoları ve Karar Ağacı Algoritması
- 5. Entropi ve Bilgi Kazancı
- 6. Çözümlü Örnek: Bilgisayar Satın Alma Veri Seti
- 7. Pozitif Sınıfın Seçimi
- 8. İkiden Fazla Sınıf: Hafta Sonu Örneği
- 9. Sayısal Öz Nitelik için Bölme Noktası Seçimi
- 10. Model Aşırı Öğrenmesi (Overfitting)
- 11. Genelleme Hatasının Kestirimi
- Örnek Sorular

## 1. Naive Bayes Üzerine Bir Soru: Normalizasyon Gerekli mi?

Önceki derste ilk sınıflandırma algoritması olarak Naive Bayes sınıflandırıcısı görülmüştü. Bu derste yeni bir sınıflandırma yöntemi olarak karar ağaçlarına geçilir. Konuya geçmeden önce Naive Bayes uygulamasıyla ilgili iki akademik nokta konuşuldu.

Birincisi, hazır örnek kodda bütün öz nitelikler sayısal kabul edilmiş ve olasılıklar normal dağılımla hesaplanmıştı. Oysa bazı sütunlar aslında kategorik bir değeri temsil eden sayısal kodlardır. Bu kodları sayı gibi işleyip normal dağılımdan olasılık hesaplamak yanlış bir modellemedir. Doğru yaklaşım, yalnız gerçekten sayısal olan öz nitelikler için normal dağılımı kullanmak, kategorik öz nitelikler içinse olasılıkları sayarak (frekansla) hesaplamak ve ikisini aynı Naive Bayes hesabında birleştirmektir. Öz nitelik sayısı azaltılırsa sınıflandırma başarısının düşmesi beklenen bir durumdur.

**Soru:** Bu veride neden normalizasyon yapıyoruz?
**Cevap:** Naive Bayes için normalizasyon gerekli değildir. Yöntem istatistikseldir, uzaklık tabanlı değildir. Kodda normalizasyon yalnız ön işleme adımında neler yapılabileceğini göstermek için yer alır. k-en yakın komşu (k-NN) ya da k-means gibi kümeleme yöntemlerinde ise normalizasyon olmazsa olmazdır.

> **Hocanın vurgusu:** Uzaklık tabanlı yöntemlerde (k-NN, k-means) mutlaka normalizasyon yapılmalıdır; Naive Bayes'te şart değildir.

## 2. Sınıflandırma Modeli Kurmanın Genel Yaklaşımı

Gözetimli (supervised) sınıflandırma yöntemlerinde bir eğitim veri kümesine ve bir test veri kümesine ihtiyaç vardır. Ekrandaki şekil süreci şöyle gösterir (ekrandan, 00:30:00):

- Eğitim kümesi (Training Set): Tid, Attrib1, Attrib2, Attrib3 ve Class sütunlarından oluşan, sınıfı bilinen 10 kayıt.
- Öğrenme algoritması (Learning Algorithm) eğitim kümesinden modeli öğrenir (Learn Model). Bu adıma tümevarım (induction) denir.
- Öğrenilen model (Model), sınıfı "?" olan test kümesine (Test Set, kayıt 11-15) uygulanır (Apply Model). Bu adıma tümdengelim (deduction) denir.

Test kümesinde de aslında gerçek sınıf etiketi (ground truth) vardır. Model test örneklerinin sınıfını tahmin eder, tahminler gerçek etiketlerle karşılaştırılarak modelin başarısı ölçülür.

<!-- BELİRSİZ: 00:30-00:32 arasında altyazı tekrar halüsinasyonuyla bozuk; eğitim/test ayrımıyla ilgili ek açıklamalar okunamadı. -->

## 3. Karar Ağacının Yapısı ve Kısmi Ağaç Örnekleri

### 3.1 Tanım

Karar ağacı gözetimli bir sınıflandırma algoritmasıdır ve sınıf etiketli eğitim örneklerine ihtiyaç duyar. Görünüşü bir akış şemasına (flowchart) benzer:

- İç düğümler (internal nodes) bir öz niteliğin test edildiği düğümlerdir.
- Dallar testin sonuçlarını gösterir.
- Yaprak düğümler (leaf nodes) sınıf etiketlerini taşır.
- Ağacın en üstteki düğümüne kök düğüm (root node) denir.

### 3.2 Kredi kartı promosyon veri seti

Karar ağacını anlatmak için "The Credit Card Promotion Database" tablosu kullanıldı (ekrandan, 00:35:00). Çıktı değişkeni "Life Insurance Promotion" (hayat sigortası promosyonu) sütunudur. Diğer sütunlar girdi öz nitelikleridir: Income Range (gelir aralığı), Credit Card Insurance (kredi kartı sigortası), Sex (cinsiyet) ve Age (yaş).

| Income Range | Life Ins. Promo | Credit Card Ins. | Sex | Age |
|---|---|---|---|---|
| 40-50K | No | No | Male | 45 |
| 30-40K | Yes | No | Female | 40 |
| 40-50K | No | No | Male | 42 |
| 30-40K | Yes | Yes | Male | 43 |
| 50-60K | Yes | No | Female | 38 |
| 20-30K | No | No | Female | 55 |
| 30-40K | Yes | Yes | Male | 35 |
| 20-30K | No | No | Male | 27 |
| 30-40K | No | No | Male | 43 |
| 30-40K | Yes | No | Female | 41 |
| 40-50K | Yes | No | Female | 43 |
| 20-30K | Yes | No | Male | 29 |
| 50-60K | Yes | No | Female | 39 |
| 40-50K | No | No | Male | 55 |
| 20-30K | Yes | Yes | Female | 19 |

### 3.3 Kök düğüm: gelir aralığı

Gelir aralığı kök düğüm yapıldığında her dala o aralıktaki örnekler düşer (ekrandan, 00:45:00):

| Dal | Yes | No | Yaprak etiketi | Yanlış sınıflanan |
|---|---|---|---|---|
| 20-30K | 2 | 2 | çoğunluk yok | - |
| 30-40K | 4 | 1 | Yes | 1 |
| 40-50K | 1 | 3 | No | 1 |
| 50-60K | 2 | 0 | Yes | 0 |

Bu bir kısmi (partial) karar ağacıdır. Bir dal yaprak kabul edilirse ona bir sınıf etiketi verilmelidir. Etiket çoğunluk sınıfıdır: 30-40K dalına "Yes" konursa bir örnek yanlış sınıflanır; 40-50K dalına "No" konursa yine bir örnek yanlış sınıflanır. 50-60K dalındaki örneklerin hepsi Yes'tir, hata yoktur. 20-30K dalında ise sınıflar eşit olduğundan çoğunluk yoktur.

### 3.4 Kök düğüm: kredi kartı sigortası

Kredi kartı sigortası kök yapılırsa iki dal (No ve Yes) oluşur. "No" dalına 12 örnek düşer ve bunların yarısı Yes, yarısı No sınıfındadır. Her sınıfta eşit sayıda örnek olduğunda çoğunluk yoktur ve yaprak için sınıf etiketi seçmek zordur. Amaç, saflığı (purity) yüksek alt kümeler elde etmektir.

### 3.5 Kök düğüm: yaş (sayısal öz nitelik)

Yaş sayısal bir öz niteliktir. Sayısal değerler için bir bölme noktası (split point) gerekir. Örnekte bölme noktası 43 seçilmiştir (ekrandan, 00:50:00):

- $\text{Age} \le 43$ (sol dal): 9 Yes, 3 No.
- $\text{Age} > 43$ (sağ dal): 0 Yes, 3 No.

Sol dalda sınıflar eşit dağılmadığı için etiket seçmek kolaydır: "Yes". Sağ dal tamamen saftır; etiket "No" olur ve hiç yanlış sınıflanan örnek yoktur.

> **Hocanın vurgusu:** Bölme değerine eşit ve küçük olan değerler her zaman sol tarafa, büyük olanlar sağ tarafa yazılır. Bu standart kullanımdır.

Karar ağaçlarında saflığı ölçmek için entropi kullanılır; entropi önceki derslerde de görülmüştü.

## 4. Bölme Senaryoları ve Karar Ağacı Algoritması

### 4.1 Algoritmaların kökeni

Karar ağaçları 1970'lerde geliştirilmiştir; ilk algoritma ID3'tür. Ardından C4.5 gelmiştir. C4.5, yeni gözetimli öğrenme algoritmaları için bir karşılaştırma ölçütü (benchmark) olarak kullanılır ve veri madenciliğinde temel öğrenici olarak anılır.

<!-- BELİRSİZ: 00:50-00:52 arası altyazı tek kelimelik parçalar ve tekrar halüsinasyonu içeriyor; slaytta geçen algoritma adları ve tarihler karede yok. -->

### 4.2 Üç bölme senaryosu

Test öz niteliğinin türüne göre üç bölme durumu vardır (ekrandan, 00:55:00):

| Senaryo | Test | Dallar | Örnek |
|---|---|---|---|
| a) A ayrık değerli | A? | her değer için bir dal ($a_1, a_2, \dots, a_v$) | color? → red, green, blue, purple, orange; income? → low, medium, high |
| b) A sürekli değerli | A? | iki dal: $A \le$ split_point, $A >$ split_point | income? → $\le 42{,}000$, $> 42{,}000$ |
| c) A ayrık değerli ve ikili ağaç isteniyor | $A \in S_A$? | iki dal: yes, no | color ∈ {red, green}? |

Örneğin veri setinde beş farklı renk varsa renk düğümünden beş dal çıkar. Sürekli değerli öz nitelikte bir bölme noktası seçilir ve öz nitelik bu noktayla karşılaştırılır; küçük eşit olanlar sola, büyük olanlar sağa gider. İkili ayrık değerlerde (0/1, evet/hayır) de düğümden iki dal çıkar.

### 4.3 Algoritmanın adımları

Altyazıdan çıkarılabilen akış şöyledir:

```text
1. Eğitim verisi T ile başla.
2. T'deki örnekleri (sınıfları) en iyi ayıran öz niteliği seç.
3. Bu öz niteliği test düğümü (ilk adımda kök düğüm) yap; T'yi
   öz niteliğin değerlerine göre alt kümelere böl.
4. Her alt küme için: alt küme yaprak olabiliyorsa sınıf etiketini ver;
   olmuyorsa kalan öz niteliklerle 2. adımdan itibaren tekrarla.
5. Veriyi bölecek başka öz nitelik kalmadığında dur.
```

<!-- BELİRSİZ: algoritma slaytının tam metni karelerde yok; 00:55-00:57 arası altyazı büyük ölçüde bozuk. Adımlar okunabilen parçalardan kuruldu. -->

En iyi ayıran öz niteliği bulmak için entropi kullanılır. Örneğin veri setinde üç öz nitelik varsa ağaç en fazla üç seviye derinleşebilir; bölünecek başka öz nitelik kalmayınca işlem durur.

## 5. Entropi ve Bilgi Kazancı

### 5.1 İki sınıf için entropi

Pozitif ve negatif örneklerden oluşan bir veri seti düşünelim. Pozitif ve negatif sınıfın olasılıkları $p_+$ ve $p_-$ hesaplanabilir. Entropi:

$$Info = -\left(p_+ \log_2 p_+ + p_- \log_2 p_-\right)$$

### 5.2 Genel formüller

Kök düğümü seçmek için bir öz nitelik seçim ölçüsü gerekir; burada bilgi kazancı (information gain) kullanılır (ekrandan, 01:00:00):

- En yüksek bilgi kazancına sahip öz nitelik seçilir.
- $p_i$, D'deki rastgele bir örneğin $C_i$ sınıfına ait olma olasılığıdır: $p_i = |C_{i,D}| / |D|$. Burada $|\cdot|$ kümenin eleman sayısını (kardinalitesini) gösterir; $|D|$ veri setindeki örnek sayısı, $|C_{i,D}|$ ise D'de $C_i$ sınıfındaki örnek sayısıdır.
- D'deki bir örneği sınıflandırmak için gereken beklenen bilgi (entropi):

$$Info(D) = -\sum_{i=1}^{m} p_i \log_2 (p_i)$$

- A öz niteliğiyle D, $v$ parçaya bölündükten sonra gereken bilgi:

$$Info_A(D) = \sum_{j=1}^{v} \frac{|D_j|}{|D|} \times I(D_j)$$

- A üzerinden dallanmayla kazanılan bilgi:

$$Gain(A) = Info(D) - Info_A(D)$$

**Soru:** Ortadaki formülde çarpımın yanındaki $I$ nedir?
**Cevap:** Gelir aralığı örneğinde düğümden dört dal çıkıyordu (20-30 bin, 30-40 bin, 40-50 bin, 50-60 bin). $|D_j|/|D|$, $j$. dala düşen örnek sayısının toplam örnek sayısına oranıdır; yani ağacın o kolunun olma olasılığıdır. $I(D_j)$ ise o kola düşen alt kümenin entropisidir. Örneğin alt kümede iki Yes, iki No örneği varsa bu dört örnek için entropi yeniden hesaplanır. $j = 1$'den $v$'ye kadar her kol için bu çarpım bulunup toplanır; sonuç A öz niteliğinin entropisi $Info_A(D)$ olur. Bilgi kazancı, bütün verinin entropisinden bu değerin çıkarılmasıyla bulunur. İşlem her öz nitelik için tekrarlanır ve en büyük kazancı veren öz nitelik kök düğüm olarak ağacın en üstüne yerleştirilir.

Arada sorulan bir başka soruya göre $Info(D)$ bilgi kazancı hesabında kullanılır: her öz nitelik için kazanç, bütün verinin entropisinden o öz niteliğin entropisi çıkarılarak bulunur.

## 6. Çözümlü Örnek: Bilgisayar Satın Alma Veri Seti

### 6.1 Veri seti

Veri setinde dört öz nitelik vardır: age (yaş), income (gelir), student (öğrenci mi) ve credit_rating (kredi notu). Hepsi kategoriktir. Sınıf sütunu buys_computer'dır. Veri setinde 14 örnek vardır.

- age: $\le 30$, 31...40, $> 40$
- income: low, medium, high
- student: yes, no
- credit_rating: fair, excellent

<!-- BELİRSİZ: veri setinin 14 satırlık tablosu slaytta gösterildi ama karelerde yok. Aşağıdaki alt küme satırları derste sözlü okunan ve tahtaya yazılan değerlerdir. -->

### 6.2 Veri setinin entropisi

Tahtada şu yazılır (ekrandan, 02:05:00):

- D: veri seti, 14 örnek.
- buys_computer = YES (pozitif): 9 örnek.
- buys_computer = NO (negatif): 5 örnek.

$$Info(D) = I(9,5) = -\left(\frac{9}{14}\log_2\frac{9}{14} + \frac{5}{14}\log_2\frac{5}{14}\right) = 0.940$$

### 6.3 Yaş öz niteliğinin kazancı

Yaş dallarına düşen örnekler (ekrandan, 01:30:00):

| Dal | Yes | No | Toplam |
|---|---|---|---|
| $\le 30$ | 2 | 3 | 5 |
| 31...40 | 4 | 0 | 4 |
| $> 40$ | 3 | 2 | 5 |

$$Info_{age}(D) = \frac{5}{14} I(2,3) + \frac{4}{14} I(4,0) + \frac{5}{14} I(3,2)$$

Hoca tahtada sırayı $I(3,2)$, $I(4,0)$, $I(2,3)$ diye yazdı, sonra sıranın önemli olmadığını belirtti; çünkü entropi yalnız oranlara bağlıdır, $I(3,2) = I(2,3)$ olur (ekrandan, 01:35:00).

Alt küme entropileri:

- $I(3,2) = -\left(\frac{3}{5}\log_2\frac{3}{5} + \frac{2}{5}\log_2\frac{2}{5}\right) \approx 0.971$ (ara adım eklendi: sayısal değer)
- $I(4,0) = -\left(\frac{4}{4}\log_2\frac{4}{4} + 0\right) = 0$; olasılık 1 olduğunda $\log_2 1 = 0$, diğer terim de sıfırdır.

Sonuç:

$$Info_{age}(D) = 0.694, \qquad Gain(age) = Info(D) - Info_{age}(D) = 0.940 - 0.694 = 0.246$$

(ekrandan, 02:20:00)

### 6.4 Gelir öz niteliğinin kazancı

Öğrencilerin istekleri üzerine bir öz nitelik daha birlikte çözüldü. Gelir dallarına düşen örnekler öğrencilerle birlikte sayıldı (ekrandan, 01:45:00):

| Dal | Yes | No | Toplam |
|---|---|---|---|
| low | 3 | 1 | 4 |
| medium | 4 | 2 | 6 |
| high | 2 | 2 | 4 |

$$Info_{income}(D) = \frac{4}{14} I(3,1) + \frac{6}{14} I(4,2) + \frac{4}{14} I(2,2)$$

High dalında örnekler sınıflara eşit dağılmıştır. Böyle bir duruma düzensiz konfigürasyon (disordered configuration) denir ve entropi en büyük değerini alır; iki sınıfta bu değer 1'dir. Entropinin birimi bittir.

> **Hocanın vurgusu:** Örnekler iki sınıfa eşit dağılmışsa entropi 1'dir; bunu hatırlayın.

Kalan olasılıklar hesaplanınca kazanç:

$$Gain(income) = Info(D) - Info_{income}(D) = 0.029$$

Diğer öz niteliklerin kazançları da aynı yolla hesaplanır. En büyük kazanç yaş öz niteliğindedir; bu yüzden karar ağacının kökü yaştır.

### 6.5 Ağacın kurulması

Kök yaş olduktan sonra her dalın alt kümesi yazılır. Sütun kısaltmaları I = income, S = student, C = credit_rating (ekrandan, 01:55:00 ve 02:00:00).

$\le 30$ dalı:

| I | S | C | Sınıf |
|---|---|---|---|
| high | no | fair | no |
| high | no | excellent | no |
| medium | no | fair | no |
| low | yes | fair | yes |
| medium | yes | excellent | yes |

Bu dalda amaç yes ve no sınıflarını ayırmaktır. Öğrenci sütununa bakınca öğrenci olmayanların hepsi "no", öğrenci olanların hepsi "yes" sınıfındadır. Bu yüzden bu dala yeni test düğümü olarak "student" gelir: student = no ise sınıf negatif, student = yes ise sınıf pozitif olur.

31...40 dalı: dört örneğin hepsi pozitiftir; dal "Class = Positive" yaprağı olur.

$> 40$ dalı:

| I | S | C | Sınıf |
|---|---|---|---|
| medium | no | fair | yes |
| low | yes | fair | yes |
| low | yes | excellent | no |
| medium | yes | fair | yes |
| medium | no | excellent | no |

Burada öğrenci öz niteliği uygun değildir; örneğin student = yes için sınıflar yes, no, yes karışıktır. Kredi notuna bakınca "excellent" olanların hepsi "no", "fair" olanların hepsi "yes" sınıfındadır. Bu yüzden bu dala test öz niteliği olarak "credit_rating" seçilir: fair ise pozitif, excellent ise negatif.

Sonuç ağacı:

```text
age?
├── <= 30   → student?
│             ├── no  → negatif
│             └── yes → pozitif
├── 31..40  → pozitif
└── > 40    → credit_rating?
              ├── fair      → pozitif (3 örnek)
              └── excellent → negatif (2 örnek)
```

Karar ağacında her dala o daldaki örnek sayısı da yazılmalıdır. Örneğin credit_rating = fair dalında üç örnek vardır ve hepsi "yes" sınıfındadır.

## 7. Pozitif Sınıfın Seçimi

Neden buys_computer = yes pozitif, buys_computer = no negatif sınıf seçildi? Bir elektronik şirketiniz ve sınıf etiketli müşteri veriniz varsa amacınız hangi müşterilerin bilgisayar aldığını anlamaktır. Bu yüzden ilgilenilen grup "bilgisayar alanlar"dır ve bu sınıfa pozitif denir.

Benzer şekilde churn (müşteri kaybı) analizi yapıyorsanız şirketten ayrılmak isteyen müşterileri anlamanız gerekir; ana ilginiz churn sınıfıdır ve churn sınıfı pozitif sınıf olur. Salgın günlerinde bir kişide virüs varsa bu sınıf "pozitif" diye adlandırılır. Kısacası asıl odaklanılan grup pozitif gruptur.

> **Hocanın vurgusu:** İlgi alanınız ve incelemek istediğiniz grup hangisiyse ona pozitif isim verin. Pozitif sınıf gelişigüzel seçilmez; dikkatli kullanılmalıdır.

## 8. İkiden Fazla Sınıf: Hafta Sonu Örneği

### 8.1 Veri seti

İkinci örnekte 10 hafta sonu vardır. Her hafta sonu için hava durumu (weather), ebeveynlerin yanınızda olup olmadığı (parents) ve para durumu (money) öz nitelikleri, karar sütununda da hafta sonu etkinliği vardır. Kararlar sinemaya gitmek (cinema), tenis oynamak (tennis), evde kalmak (stay in) ve alışverişe gitmek (shopping) olabilir. Bu örneğin farkı dört sınıf olmasıdır. Sorunun tamamı çözülmedi, çözümlü örneğin üzerinden geçildi.

<!-- BELİRSİZ: hafta sonu veri tablosu slaytta gösterildi ama karelerde yok; tahtadaki çözüm karesi (02:25:00) yalnız başlığı gösteriyor. -->

### 8.2 Entropi

Sınıflardaki örnek sayıları öğrencilerle birlikte sayıldı: sinema 6, tenis 2. Evde kalma ve alışveriş sınıflarının her birinde 1 örnek kalır (ara adım eklendi: altyazıda bu iki sayı okunmuyor; toplam 10 ve hocanın verdiği 1.571 sonucu ile tutarlıdır).

$$Info(T) = -\left(\frac{6}{10}\log_2\frac{6}{10} + \frac{2}{10}\log_2\frac{2}{10} + \frac{1}{10}\log_2\frac{1}{10} + \frac{1}{10}\log_2\frac{1}{10}\right) = 1.571$$

Bilgi kuramına göre entropi kodlamayla ilgilidir. Dört farklı sınıfı sabit uzunluklu kodla göstermek için 2 bit gerekir. Bu yüzden dört sınıflı bir veri setinde entropi en fazla 2 olabilir.

> **Hocanın vurgusu:** Dört sınıf için hesapladığınız entropi 2'den büyük çıkarsa hesapta bir hata vardır; hesaplarınızı kontrol edin.

> **Ek bilgi (derste anlatılmadı):** Genel olarak $m$ sınıflı bir veri setinde entropi en fazla $\log_2 m$ bittir ve bu değere sınıflar eşit dağıldığında ulaşılır. İki sınıfta $\log_2 2 = 1$, dört sınıfta $\log_2 4 = 2$ olur.

### 8.3 Kök düğüm

Slayttaki kazançlar (ekrandan, 02:30:00):

- $Gain(T, \text{weather}) = 0.70$
- $Gain(T, \text{parents}) = 0.61$
- $Gain(T, \text{money}) = 0.2816$

En büyük kazanç hava durumundadır; seçilen öz nitelik değerini taşıyan bir ağaç düğümü oluşturulur. Kökten Sunny, Windy ve Rainy dalları çıkar. Sunny dalında bir sonraki test öz niteliği parents olur; diğer dallarda farklı öz nitelikler gelebilir.

## 9. Sayısal Öz Nitelik için Bölme Noktası Seçimi

### 9.1 Veri seti

Üçüncü örnekte küçük bir veri seti vardır: üç öz nitelik ve son sütunda sınıf etiketi (Class 1 ve Class 2). 14 örneğin 9'u Class 1, 5'i Class 2'dir. Bu yüzden veri setinin entropisi 0.94'tür.

İki öz nitelik (A1 ve A3) kategoriktir; bunların kazancı bilinen yolla hesaplanır:

- $Gain(A1) = 0.246$
- $Gain(A3) = 0.048$

A2 ise sayısal bir öz niteliktir (yaş) ve bunun için bir bölme noktası bulmak gerekir.

### 9.2 Sıralama ve aday noktalar

Önce sayısal öz nitelik küçükten büyüğe sıralanır ve sınıf etiketleri yanına yazılır (ekrandan, 02:35:00):

| Age | 65 | 70 | 70 | 70 | 75 | 78 | 80 | 80 | 80 | 85 | 90 | 90 | 95 | 96 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Sınıf | C1 | C1 | C1 | C2 | C1 | C1 | C2 | C1 | C1 | C2 | C2 | C1 | C2 | C1 |

Sıralamadan sonra aday bölme noktaları {65, 70, 75, 78, 80, 85, 90, 95} olur. En büyük değer (96) aday olamaz: 96'dan bölünürse bütün değerler sol tarafta kalır, sağ dal boş olur. Kalan sekiz değerden en uygun bölme noktası seçilmelidir.

### 9.3 Bölme noktası 80 için hesap

Test $A2 \le 80$ ve $A2 > 80$ olur:

- Sol dal ($\le 80$): 9 örnek, 7'si C1, 2'si C2. Dalın olasılığı $9/14$.
- Sağ dal ($> 80$): 5 örnek, 2'si C1, 3'ü C2. Dalın olasılığı $5/14$.

$$Info_{A2}(T) = \frac{9}{14}\left(-\frac{7}{9}\log_2\frac{7}{9} - \frac{2}{9}\log_2\frac{2}{9}\right) + \frac{5}{14}\left(-\frac{2}{5}\log_2\frac{2}{5} - \frac{3}{5}\log_2\frac{3}{5}\right) = 0.837$$

$$Gain(A2) = 0.940 - 0.837 = 0.103 \text{ bit}$$

(ekrandan, 02:35:00)

> **Ders sonrası not:** Slayttaki $Info_{A2}(T) = 0.837$ ve $Gain(A2) = 0.103$ yuvarlanmış değerlerdir. Python ile tam hesapta $Info_{A2}(T) \approx 0.838$ ve $Gain(A2) \approx 0.102$ çıkar. Sonuç değişmez: kazanç A1'inkinden küçüktür.

Aynı hesap 78, 75, 90 gibi diğer adaylar için de yapılır ve en büyük kazancı veren aday seçilir. Bu örnekte 0.103, önceki kazançlarla karşılaştırılır; en büyük kazanç A1'de olduğu için karar ağacının kökü A1 olur.

### 9.4 Sınavda bölme noktası seçimi

Sınavda her aday için bilgi kazancı hesaplamak mümkün değildir. Bu durumda hangi noktanın veriyi daha iyi ayırdığına bakarak karar verilmelidir:

- 65'ten bölünürse solda tek örnek, sağda geri kalan bütün örnekler olur. İyi bir seçim değildir.
- 70'ten bölünürse sağ tarafta büyük bir düzensizlik (karışıklık) kalır, saflık yoktur. İyi bir ayrım değildir.
- 78 gibi bir noktadan bölmek de değerlendirilebilir. <!-- BELİRSİZ: 78 için yapılan değerlendirme altyazıda tekrar halüsinasyonuyla bozuk. -->

Hangi değerin uygun olduğuna kendiniz karar veremiyorsanız her aday için kazancı hesaplamalısınız.

## 10. Model Aşırı Öğrenmesi (Overfitting)

Bu bölümün slaytları veri madenciliğinde iyi bilinen "Introduction to Data Mining" (2. baskı) ders kitabının sunumundan alınmıştır.

### 10.1 Hata türleri

Bir sınıflandırma probleminde eğitim ve test veri kümeleri vardır. Eğitim kümesinde bir eğitim hatası (training error) elde edilir. Geliştirilen model test verisine uygulandığında test hatası (test error) bulunur. Asıl ilgilenilen ise genelleme hatasıdır (generalization error): aynı dağılımdan rastgele seçilen kayıtlar üzerinde modelin beklenen hatası.

### 10.2 Örnek veri seti

İki sınıflı bir problem vardır (ekrandan, 02:50:00):

- "+" sınıfı (mavi): 5200 örnek. 5000'i (10,10) merkezli bir Gauss dağılımından üretilmiş, 200 gürültülü örnek eklenmiştir.
- "o" sınıfı (kırmızı): 5200 örnek, düzgün (uniform) dağılımdan üretilmiştir.

Veri iki boyutludur: yatay eksen $x_1$, dikey eksen $x_2$; her iki boyut da 0 ile 20 arasındadır. Gauss dağılımının merkezi (10,10) noktasıdır; mavi örnekler bu merkez çevresinde yoğunlaşır, kırmızı örnekler ise bütün düzleme düzgün dağılmıştır. Amaç mavi ve kırmızı sınıfları ayırmaktır. Verinin %10'u eğitim (modeli üretmek için), %90'ı test için kullanılır.

### 10.3 Dört düğümlü karar ağacı

Grafikte yatay eksen karar ağacındaki düğüm sayısını, dikey eksen eğitim hatasını gösterir. Düğüm sayısı yerine ağacın seviye sayısı da düşünülebilir. Düğüm sayısı arttıkça eğitim hatası başta çok hızlı düşer, sonra eğim azalır (ekrandan, 02:55:00).

4 düğümlü ağacın testleri şöyledir (ekrandan, 02:55:00):

```text
x1 < 6.45956 ?
├── doğru  → o (kırmızı)
└── yanlış → x1 < 13.1086 ?
             ├── yanlış → o (kırmızı)
             └── doğru  → x2 < 7.03548 ?
                          ├── doğru  → o (kırmızı)
                          └── yanlış → x2 < 14.3129 ?
                                       ├── doğru  → + (mavi)
                                       └── yanlış → o (kırmızı)
```

<!-- BELİRSİZ: karedeki ağaç çiziminde dalların doğru/yanlış yönleri yazılı değil; yönler hocanın anlatımından ve karar sınırları şeklinden kuruldu. -->

Bu ağaç, eğitim verisi üzerinde merkezdeki dikdörtgen bölgeyi mavi sınıf, çevresindeki dört bölgeyi kırmızı sınıf olarak tanımlar.

### 10.4 Karmaşık ağaç ve aşırı öğrenme

Ağacın seviye sayısı artırılırsa, örneğin 40-50 düğümlü karmaşık bir ağaç kurulursa, model eğitim hatasını azaltmak için gürültülü örneklerin bulunduğu küçük bölgeleri de ayrı sınıf bölgeleri olarak tanımlar. Bu durum aşırı öğrenmeye (overfitting) yol açar: eğitim hatası düşer ama karmaşık model daha büyük test hatası üretir.

Eğitim ve test hatası grafiklerinde (ekrandan, 03:00:00) düğüm sayısı arttıkça eğitim hatası sıfıra doğru inerken test hatası yaklaşık 4 düğümden sonra yeniden yükselir.

- **Yetersiz öğrenme (underfitting):** model çok basittir; hem eğitim hem test hatası büyüktür.
- **Aşırı öğrenme (overfitting):** model çok karmaşıktır; eğitim hatası küçük ama test hatası büyüktür.

Aşırı öğrenmede düğüm sayısı artırılarak daha karmaşık bir model oluşturulur; eğitim hatası azalır ama test hatası büyür. Karmaşık model yerine daha basit bir model seçerek test hatasını azaltmak mümkündür. Bu, aşırı öğrenmeden kaçınmanın bir yoludur.

### 10.5 Eğitim verisini artırmak

Aşırı öğrenmeden kaçınmanın bir başka yolu eğitim kümesindeki örnek sayısını artırmaktır. Veri örneği sayısı iki katına çıkarıldığında eğitim hatası ile test hatası birbirine çok yaklaşır. 50 düğümlü ağaçta bile eğitim örneği çok olduğunda aşırı öğrenme sorunu önlenebilir.

<!-- BELİRSİZ: "iki kat veri" slaytı ve sonrasındaki açıklamalar karelerde yok; 03:01-03:03 arası altyazı bozuk. -->

## 11. Genelleme Hatasının Kestirimi

### 11.1 Doğrulama kümesi

Genelleme hatasını kestirmek için veri iki yerine üç parçaya ayrılabilir. Önce veri eğitim ve test kümelerine ayrılır, sonra eğitim kümesi de eğitim ve doğrulama (validation) kümelerine ayrılır. Böylece eğitim, doğrulama ve test olmak üzere üç ayrı küme elde edilir. Doğrulama kümesi genelleme hatasını kestirmek için kullanılır. Genelleme hatası düşük olan model seçildikten sonra model test örnekleriyle sınanır.

Bu çözümün bir sakıncası vardır: veri setinde az örnek varsa eğitim için daha az veri kalır.

### 11.2 Karmaşıklık cezası: kötümser hata kestirimi

Genelleme hatası, eğitim hatasına model karmaşıklığıyla orantılı bir ceza eklenerek de hesaplanabilir: eğitim hatası artı $\alpha$ çarpı modelin karmaşıklığı. Karar ağaçları için $k$ yapraklı bir $T$ ağacının kötümser hata kestirimi (pessimistic error estimate) şöyledir (ekrandan, 03:05:00):

$$err_{gen}(T) = err(T) + \Omega \times \frac{k}{N_{train}}$$

- $err(T)$: bütün eğitim kayıtları üzerindeki hata oranı.
- $\Omega$: $\alpha$'ya benzer bir ödünleşim (trade-off) hiperparametresi; bir yaprak düğüm eklemenin göreli maliyeti.
- $k$: yaprak düğüm sayısı.
- $N_{train}$: toplam eğitim kaydı sayısı.

### 11.3 Örnek: iki ağacın karşılaştırılması

İki karar ağacı verilmiştir: soldaki $T_L$ ve sağdaki $T_R$. Yapraklardaki pozitif (+) ve negatif (-) örnek sayıları (ekrandan, 03:10:00):

| Ağaç | Yapraklar (+, -) | Yaprak sayısı | Hatalı |
|---|---|---|---|
| $T_L$ | (3,1), (2,1), (0,2), (1,2), (3,0), (3,1), (0,5) | 7 | 4 |
| $T_R$ | (5,2), (1,4), (3,0), (3,6) | 4 | 6 |

Yanlış sınıflanan örnek sayısı şöyle bulunur: her yaprağa çoğunluk sınıfının etiketi verilir ve azınlıktaki örnekler hata sayılır. $T_L$'de (3,1) yaprağı pozitif etiket alır, 1 hata; (2,1) yaprağı pozitif, 1 hata; (0,2) negatif, hata yok; (1,2) negatif, 1 hata; (3,0) pozitif, hata yok; (3,1) pozitif, 1 hata; (0,5) negatif, hata yok. Toplam 4 hata vardır. $T_R$'de (5,2) yaprağında 2, (1,4) yaprağında 1, (3,0) yaprağında 0, (3,6) yaprağında 3 hata vardır; toplam 6.

Toplam eğitim kaydı 24, $\Omega = 1$:

- $e(T_L) = 4/24$, $e(T_R) = 6/24$
- $e_{gen}(T_L) = \dfrac{4}{24} + 1 \times \dfrac{7}{24} = \dfrac{11}{24} = 0.458$
- $e_{gen}(T_R) = \dfrac{6}{24} + 1 \times \dfrac{4}{24} = \dfrac{10}{24} = 0.417$

Sağdaki ağacın eğitim hatası daha büyük olsa da genelleme hatası daha küçüktür; bu yüzden $T_R$ tercih edilir.

> **Ders sonrası not:** Hoca anlatırken sağdaki ağaç için "daha karmaşık model" dedi. Yaprak sayısına göre daha karmaşık olan 7 yapraklı soldaki ağaçtır ($T_L$); sağdaki ağaç 4 yapraklı ve daha basittir. Karmaşıklık cezası bu yüzden $T_L$'yi daha çok cezalandırır.

**Soru:** Yanlış sınıflandırmayı nasıl anladık?
**Cevap:** Ağaçlara başka seviye eklenmeyecekse, yani ağacın son şekli buysa, her yaprağa bir sınıf etiketi atanmak zorundadır. Etiket o yaprakta çoğunlukta olan sınıftır. Örneğin bir yaprakta üç pozitif, bir negatif örnek varsa etiket pozitif olur ve negatif örnek yanlış sınıflanmış sayılır. Hiç pozitif örnek olmayan bir yaprağa negatif etiket verilince hata olmaz. Bu mantıkla hangi etiket atanırsa en az hata yapılacağı düşünülerek her yapraktaki hatalar toplanır: soldaki ağaçta 4, sağdakinde 6 hata, yani sağdaki ağaç 24 örneğin 6'sını yanlış sınıflar.

> **Hocanın vurgusu:** Genelleme hatasının nasıl hesaplandığını öğrenmeniz gerekiyor.

## Örnek Sorular

### Soru 1

(derste sözlü, 01:31:22) buys_computer veri setinde kaç pozitif örnek var ve veri setinin entropisi nedir?

> **Çözüm (derste verildi):** 9 pozitif, 5 negatif örnek vardır. $Info(D) = -\left(\frac{9}{14}\log_2\frac{9}{14} + \frac{5}{14}\log_2\frac{5}{14}\right) = 0.940$ (ekrandan, 02:05:00).

### Soru 2

(derste sözlü, 01:39:15) buys_computer veri setinde yaş dışındaki öz nitelikler (income, student, credit_rating) için bilgi kazancını hesaplayın.

> **Çözüm (income derste verildi):** low (3 Yes, 1 No), medium (4 Yes, 2 No), high (2 Yes, 2 No) dallarıyla $Info_{income}(D) = \frac{4}{14}I(3,1) + \frac{6}{14}I(4,2) + \frac{4}{14}I(2,2) \approx 0.911$ ve $Gain(income) = 0.029$.

> **Çözüm (derste verilmedi):** Standart buys_computer veri setinde student = yes dalında 6 Yes, 1 No; student = no dalında 3 Yes, 4 No vardır. Python ile $Gain(student) \approx 0.151$ bulunur. credit_rating = fair dalında 6 Yes, 2 No; excellent dalında 3 Yes, 3 No vardır ve $Gain(credit\_rating) \approx 0.048$ olur. Dal sayıları derste gösterilen tablodan değil, büyük olasılıkla aynı olan standart veri setinden alınmıştır. En büyük kazanç yine yaştadır (0.246), bu yüzden kök yaştır.

### Soru 3

(derste sözlü, 01:55:45 ve 02:00:07) Yaş kök olduktan sonra $\le 30$ ve $> 40$ dallarında yes ve no sınıflarını hangi öz nitelik ayırır?

> **Çözüm (derste verildi):** $\le 30$ dalında student: öğrenci olmayanlar no, öğrenci olanlar yes. $> 40$ dalında credit_rating: fair olanlar yes, excellent olanlar no (ekrandan, 02:00:00).

### Soru 4

(ekrandan, 03:10:00) Şekildeki $T_L$ ve $T_R$ ağaçlarında kaç örnek yanlış sınıflanmıştır? $\Omega = 1$ için hangi ağacın genelleme hatası daha küçüktür?

> **Çözüm (derste verildi):** $T_L$'de 4, $T_R$'de 6 örnek yanlış sınıflanır. $e_{gen}(T_L) = 4/24 + 7/24 = 0.458$, $e_{gen}(T_R) = 6/24 + 4/24 = 0.417$. Genelleme hatası küçük olan $T_R$ tercih edilir.

## Dersin Toparlaması

Bu derste karar ağaçlarıyla sınıflandırma ele alındı. Karar ağacı, iç düğümlerinde öz nitelik testleri, yapraklarında sınıf etiketleri olan akış şeması benzeri bir modeldir. Hangi öz niteliğin köke yerleşeceği entropi ve bilgi kazancıyla belirlenir: önce bütün verinin entropisi, sonra her öz nitelik için dalların ağırlıklı entropisi bulunur ve farkı en büyük olan öz nitelik seçilir. İşlem her dalın alt kümesinde kalan öz niteliklerle sürer. buys_computer örneğinde kök yaş, alt düğümler student ve credit_rating olarak bulundu. Dört sınıflı hafta sonu örneği entropinin üst sınırının sınıf sayısına bağlı olduğunu, sayısal öz nitelik örneği de bölme noktasının sıralı veride aday noktalar denenerek seçildiğini gösterdi.

Dersin son bölümünde karar ağaçlarıyla ilişkili olarak aşırı öğrenme incelendi. Ağaç büyüdükçe eğitim hatası düşer ama bir noktadan sonra test hatası artar. Bunu önlemek için daha basit model seçilebilir, eğitim verisi artırılabilir, doğrulama kümesi kullanılabilir ya da yaprak sayısını cezalandıran kötümser hata kestirimiyle genelleme hatası hesaplanabilir. Konuyla ilgili diğer ayrıntılar slaytlarda yer almaktadır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
