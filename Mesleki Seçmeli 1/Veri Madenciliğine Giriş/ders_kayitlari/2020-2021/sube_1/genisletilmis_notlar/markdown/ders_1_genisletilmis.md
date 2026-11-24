# Ders 1 Genişletilmiş Notu: Veri Madenciliğine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veri madenciliği neden gerekli?
- 2. Veritabanı teknolojisi ve veri madenciliğinin tanımı
- 3. Uygulama alanları
- 4. Veri madenciliği stratejileri
- 5. Gözetimli öğrenme: karar ağacı örneği
- 6. Gözetimsiz kümeleme
- 7. Sınıflama, kestirim ve öngörü
- 8. Üretim kuralları: kural doğruluğu ve kural kapsamı
- 9. Bilgi keşfi (KDD) süreci ve iş zekâsı
- Örnek Sorular

## 1. Veri madenciliği neden gerekli?

Veri madenciliği dersinin amacı, veriden öğrenebilen, bu veriden bir model oluşturabilen ve sonra bu modelle karar verebilen sistemler geliştirmektir. Günümüz bir veri dünyasıdır; ama veri kendi başına bilgi değildir. Bu veriyi anlamlı bir bilgiye dönüştürmek için geliştirilen yöntemler gündelik hayatı da kolaylaştırır.

Slaytın başlığı "Why Data Mining?" sorusudur (ekrandan, 01:05:00). Verinin miktarı terabaytlardan petabaytlara patlarcasına büyümektedir. Bu büyümenin arkasında veri toplama ve verinin erişilebilir olması vardır: otomatik veri toplama araçları, veritabanı sistemleri, web ve bilgisayarlaşmış toplum. Bol veri üreten başlıca kaynaklar üç alanda toplanır:

- İş dünyası (business): web, e-ticaret, işlemler (transactions), borsa. Banka ve borsa platformlarındaki işlem kayıtları bu gruptadır.
- Bilim (science): uzaktan algılama (remote sensing), biyoenformatik, bilimsel simülasyon. Uzaktan algılama platformları sürekli veri toplar; biyoenformatik çalışmalarında da çok farklı türde veri bulunur.
- Toplum ve herkes (society and everyone): haberler, dijital kameralar, sosyal medya ve bloglar. Bu verilerden bilgi üretmek için doğal dil işleme (Natural Language Processing) uygulamaları kullanılır. Örneğin bir e-ticaret sitesindeki yorumlara duygu analizi (sentiment analysis) uygulanabilir.

Slayttaki iki cümle durumu özetler: "We are drowning in data, but starving for knowledge!" (Veride boğuluyoruz ama bilgiye açız.) ve "Necessity is the mother of invention" — veri madenciliği, devasa veri kümelerinin otomatik analizidir.

## 2. Veritabanı teknolojisi ve veri madenciliğinin tanımı

Veri madenciliği yapılandırılmış (structured) veriye ihtiyaç duyar. Yapılandırılmış veriyi elde etmek için de veritabanı teknolojilerine gerek vardır. Veritabanlarının tarihine bakıldığında, veritabanı yönetim sistemleri sayesinde verinin yapılandırılmış biçimde toplanabildiği görülür. Veri madenciliği bu birikimin üzerine kuruludur.

Elimizde çok büyük miktarda veri vardır. Veri madenciliğinin amacı, bu büyük veriden ilginç örüntüleri (interesting patterns) ya da bilgiyi çıkarmaktır. Veri madenciliğinin başka adları da vardır; bunlar arasında veritabanlarında bilgi keşfi (Knowledge Discovery in Databases, KDD) en sık kullanılanıdır. Ders tanıtım formunda da veri madenciliğiyle eş anlamlı kullanılan terimler olarak veritabanlarında bilgi madenciliği (knowledge mining from databases), bilgi çıkarımı (knowledge extraction), veri ve örüntü analizi (data/pattern analysis) ve veri arkeolojisi sayılmıştır (ekrandan, 00:35:00).

Veri madenciliğinin uzandığı başka alanlar da vardır: metin madenciliği (text mining), web madenciliği (web mining) ve akan veri madenciliği (stream data mining).

<!-- BELİRSİZ: Bu bölümdeki diğer ad listesi ve veritabanı tarihçesi slaydı altyazıda büyük ölçüde bozuk; bu slaytların karesi yok. -->

## 3. Uygulama alanları

### 3.1 Pazar analizi ve yönetim

Pazar analizi ve yönetiminde verilen ilk örnek hedef pazarlamadır (target marketing): müşteri verisinden hangi müşteri grubuna hangi ürün ya da kampanyanın yöneltileceği belirlenir. Risk analizi de veri madenciliğinin uygulama alanlarından biri olarak geçti.

<!-- BELİRSİZ: Pazar analizi ve risk analizi slaytlarının ayrıntıları altyazıda okunamıyor. -->

### 3.2 Dolandırıcılık tespiti ve olağandışı örüntüler

Slayt "Ex. 3: Fraud Detection & Mining Unusual Patterns" başlığını taşır (ekrandan, 01:10:00).

- Yaklaşımlar: kümeleme ve dolandırıcılıklar için model kurma, aykırı değer (outlier) analizi.
- Uygulamalar: sağlık, perakende, kredi kartı hizmetleri, telekomünikasyon.
  - Araç sigortası: çarpışma halkaları (ring of collisions), yani düzenlenmiş kazalar.
  - Kara para aklama (money laundering): şüpheli parasal işlemler.
  - Sağlık sigortası: profesyonel hastalar, doktor halkaları ve sevk halkaları; gereksiz ya da birbiriyle ilişkili tarama testleri.
  - Telekomünikasyon, telefon dolandırıcılığı: arama modeli (aramanın hedefi, süresi, günün ya da haftanın zamanı) kurulur ve beklenen normdan sapan örüntüler incelenir.
  - Perakende: analistlerin tahminine göre perakendedeki fire kaybının %38'i dürüst olmayan çalışanlardan kaynaklanır.
  - Terörle mücadele.

Hoca kredi kartı kullanımında dolandırıcılık faaliyetlerinin tespitini öne çıkardı ve öğrencilerden örnek istedi. Bir öğrenci sanal kart ile ödeme örneğini verdi.

**Soru:** Sanal kartla ödeme bir dolandırıcılık faaliyeti midir? **Cevap:** Hayır; sanal kart dolandırıcılık işlemlerine karşı bir koruma yöntemidir, dolandırıcılık tespiti örneği değildir.

## 4. Veri madenciliği stratejileri

> **Hocanın vurgusu:** Bu slayt çok önemlidir; not alın, sonraki slaytlarda bu şemaya sürekli dönülecek.

Veri madenciliğinin üç ana stratejisi vardır:

```text
Veri madenciliği stratejileri
├── Gözetimli öğrenme (supervised learning)
│   ├── Sınıflama (classification)
│   ├── Kestirim (estimation)
│   └── Öngörü (prediction)
├── Gözetimsiz kümeleme (unsupervised clustering)
└── Pazar sepeti analizi (market basket analysis)
```

<!-- BELİRSİZ: Strateji şemasının slayt karesi yok; yapı hocanın sözlü anlatımından (01:14:04-01:14:34) kuruldu. -->

## 5. Gözetimli öğrenme: karar ağacı örneği

### 5.1 İki adım

Gözetimli öğrenme iki adımdan oluşur (ekrandan, 01:15:00):

1. Kökeni bilinen veri örnekleriyle (data instances of known origin) öğrenen bir model kurulur. "Kökeni bilinen", toplanan verinin bir sınıf etiketine sahip olduğu anlamına gelir.
2. Kurulan model, kökeni bilinmeyen yeni örneklerin sonucunu (sınıf etiketini) belirlemek için kullanılır.

### 5.2 Hastalık teşhisi eğitim verisi

Örnek veri kümesi "Table 1.1 Hypothetical Training Data for Disease Diagnosis" adını taşır (ekrandan, 01:20:00). 10 hastaya beş soru sorulmuştur:

| Patient ID# | Sore Throat | Fever | Swollen Glands | Congestion | Headache | Diagnosis |
|---|---|---|---|---|---|---|
| 1 | Yes | Yes | Yes | Yes | Yes | Strep throat |
| 2 | No | No | No | Yes | Yes | Allergy |
| 3 | Yes | Yes | No | Yes | No | Cold |
| 4 | Yes | No | Yes | No | No | Strep throat |
| 5 | No | Yes | No | Yes | No | Cold |
| 6 | No | No | No | Yes | No | Allergy |
| 7 | No | No | Yes | No | No | Strep throat |
| 8 | Yes | No | No | Yes | Yes | Allergy |
| 9 | No | Yes | No | Yes | Yes | Cold |
| 10 | Yes | Yes | No | Yes | Yes | Cold |

Beş soru (boğaz ağrısı, ateş, şişmiş bezeler, burun tıkanıklığı, baş ağrısı) veri kümesinin özellikleridir (features); her sütun bir özelliği temsil eder. Son sütun Diagnosis bir özellik değil, sınıf etiketidir.

> **Hocanın vurgusu:** Son sütun üç farklı adla anılabilir: sınıf etiketi (class label), çıkış değişkeni (output variable) ve bağımlı değişken (dependent variable). Veri kümesinde sınıf etiketi sütunu bulunduğu için bu bir eğitim veri kümesidir (training dataset).

### 5.3 Karar ağacı modeli

Karar ağacı algoritması bu veriden şu modeli üretir:

```text
Swollen Glands?
├── Yes → Diagnosis = Strep throat
└── No  → Fever?
          ├── Yes → Diagnosis = Cold
          └── No  → Diagnosis = Allergy
```

Kök düğüm (root node) Swollen Glands'tir. Veri kümesinde beş özellik olduğu hâlde modelde yalnız iki test düğümü vardır: Swollen Glands ve Fever. Algoritma, sınıfları ayırmak için yeterli olan özellikleri seçmiştir.

Model eğitim verisi üzerinde tek tek denenir. Örneğin 1. hastada Swollen Glands = Yes olduğu için teşhis Strep throat çıkar; bu doğrudur. Hoca diğer hastaları da sırayla kontrol etti. Ağaç on hastanın hepsini doğru sınıflar (ara adım eklendi: on satırın kontrolü ajan tarafından python ile yapıldı).

### 5.4 Modeli yeni örneklerde kullanma

İkinci adımda test örnekleri vardır: hastaların sorulara verdiği cevaplar bilinir ama teşhisleri bilinmez. Bunlar sınıf etiketi bilinmeyen veri örnekleridir (ID 11 ve sonrası). Teşhis modelle belirlenir.

Derste ID 11 için cevap sohbetten istendi: Swollen Glands = No, Fever = No olduğu için model sonucu Allergy'dir.

<!-- BELİRSİZ: Test hastaları tablosunun (ID 11 ve sonrası) karesi yok; diğer test hastalarının değerleri altyazıdan okunamadı. -->

Özetle gözetimli öğrenmede sınıf etiketli veri ile öğrenen model kurulur, sonra bu modelle yeni örnekler sınıflandırılır.

## 6. Gözetimsiz kümeleme

### 6.1 Tanım ve terim uyarısı

Kümeleme (clustering) gruplamak demektir; Türkçede eğiticisiz kümeleme denir. Gözetimsiz kümelemede veri vardır ama sınıf etiketi yoktur. Örnekler birbirlerine olan benzerliklerine göre gruplanır.

> **Hocanın vurgusu:** Gözetimli ve gözetimsiz yöntemleri ayırırken dikkat edin. Gözetimli (eğiticili) yöntemde bir eğitim veri kümesi vardır ve sınıflama yapılır. Gözetimsiz yöntemde sınıf etiketi yoktur, örnekler benzerliklerine göre gruplanır ve bu işleme kümeleme denir. "Unsupervised classification" diye bir şey yoktur, bu ifade yanlıştır. Gözetimsiz yapılan bütün işlemler kümelemedir: "supervised classification" ve "unsupervised clustering" denir.

### 6.2 Acme yatırımcılar veri kümesi

Örnek "Table 1.3 Acme Investors Incorporated" tablosudur (ekrandan, 01:30:00):

| Customer ID | Account Type | Margin Account | Transaction Method | Trades/Month | Sex | Age | Favorite Recreation | Annual Income |
|---|---|---|---|---|---|---|---|---|
| 1005 | Joint | No | Online | 12.5 | F | 30–39 | Tennis | 40–59K |
| 1013 | Custodial | No | Broker | 0.5 | F | 50–59 | Skiing | 80–99K |
| 1245 | Joint | No | Online | 3.6 | M | 20–29 | Golf | 20–39K |
| 2110 | Individual | Yes | Broker | 22.3 | M | 30–39 | Fishing | 40–59K |
| 1001 | Individual | Yes | Online | 5.0 | M | 40–49 | Golf | 60–79K |

Beş örnek ve birçok öznitelik vardır: hesap türü, margin hesabı olup olmadığı (Yes/No), işlem yöntemi (Online ya da Broker) vb. Bu veride bir sınıf etiketi yoktur; müşteriler benzerliklerine göre kümelenebilir.

Aynı veri gözetimli öğrenme için de kullanılabilir. Transaction Method sütunu çıkış değişkeni seçilirse Account Type, Margin Account, Trades/Month, Sex, Age, Favorite Recreation ve Annual Income özellik olur; böylece sınıf etiketli veri elde edilir ve müşterilerin işlem yöntemini belirlemek için gözetimli sınıflama teknikleri uygulanabilir.

**Soru:** Bir sütunu sınıf etiketi olarak düşünebiliriz dedik; bunu neye göre belirliyoruz? **Cevap:** Cevaplamak istediğimiz soruya göre. Sonraki slayttaki ilk soru "Çevrim içi bir yatırımcının genel profilini çıkarabilir miyim?" sorusudur. Bunun için gözetimli öğrenme kullanılır ve Transaction Method sınıf etiketi seçilir; kurulan model çevrim içi yatırımcının genel profilini tanımlar. Örneğin yaşlı müşterilerin yalnız aracı kurumu (broker), genç müşterilerin çevrim içi işlemi tercih ettiği gibi bir sonuç çıkabilir.

<!-- BELİRSİZ: Yatırımcı veri kümesine dair slayttaki diğer sorular (yeni bir müşteriye margin hesabı önerme, kümeleme ile hangi grupların bulunacağı vb.) altyazıda bozuk. -->

Ders planında gözetimsiz kümeleme teknikleri (k-means kümeleme ve hiyerarşik kümeleme) ara sınavdan sonra işlenecektir.

## 7. Sınıflama, kestirim ve öngörü

Gözetimli öğrenmenin üç alternatifi sınıflama, kestirim ve öngörüdür. Üçü de gözetimli öğrenme kullanır; aralarındaki farklar slaytlarda maddelenmiştir.

### 7.1 Sınıflama

Slayt (ekrandan, 01:40:00):

- Learning is supervised (öğrenme gözetimlidir).
- The dependent variable is categorical (bağımlı değişken kategoriktir).
- Well-defined classes (sınıflar iyi tanımlıdır).
- Current rather than future behavior (gelecekten çok mevcut davranış).

Hastalık teşhisi veri kümesi sınıflama örneğidir: hastaların cevaplarına göre hastalıkları belirlenir. Bu, gelecek hakkında değil, mevcut durum hakkında bilgi verir. Sınıf etiketinin kategorik olması gerekir.

### 7.2 Kestirim

Slayt (ekrandan, 01:45:00):

- Learning is supervised.
- The dependent variable is numeric (bağımlı değişken sayısaldır).
- Well-defined classes.
- Current rather than future behavior.

Sınıflamadan tek farkı bağımlı değişkenin sayısal olmasıdır; kestirim de mevcut durumu tanımlar.

**Soru (hoca):** Kestirim için bir örnek verebilir misiniz? **Cevap (bir öğrenci):** Ev fiyatı tahmini. Hoca bu örneği doğru buldu. Makinenin kalan ömrü de sayısal çıkışlı bir örnek olarak sohbete yazıldı.

### 7.3 Öngörü

Slayt (ekrandan, 01:50:00):

- The emphasis is on predicting future rather than current outcomes (vurgu, mevcut sonuçlardan çok geleceği tahmin etmektir).
- The output attribute may be categorical or numeric (çıkış özniteliği kategorik ya da sayısal olabilir).

Bir öğrenci kestirim için hava durumu tahminini önerdi. Hoca bunun kestirim için iyi bir örnek olmadığını, geleceğe dönük olduğu için öngörü örneği olduğunu söyledi:

- "Yarın hava 25 derece olacak" → geleceğe dönük tahmin, çıkış sayısal.
- "Yarın hava güneşli ya da yağmurlu olacak" → geleceğe dönük tahmin, çıkış kategorik.

Her iki durumda da gelecek tahmin edildiği için bu iyi bir öngörü örneğidir ve kestirimle farkını gösterir.

**Soru:** Kestirim ile öngörü arasındaki fark tam olarak nedir? **Cevap:** Öngörüde geleceğe dair bir tahminde bulunulur. Kestirimde ise mevcut duruma ilişkin bir tahmin yapılır. Fark küçüktür, ikisi de tahmin yapar. Ev fiyatı örneğinde evin konumu, kaçıncı katta olduğu, kaç odası olduğu ve o bölgedeki diğer ev fiyatları (yani elde bir eğitim veri kümesi) kullanılarak evin bugünkü fiyatı söylenir; bu kestirimdir. Evin üç yıl sonraki fiyatı sorulsaydı bu öngörü olurdu; bunun için de üç yıl sonrasına ait fiyatları içeren uygun bir veri kümesi gerekirdi.

## 8. Üretim kuralları: kural doğruluğu ve kural kapsamı

### 8.1 Kredi kartı promosyon veri kümesi

Pazar sepeti analizi kısaca tanıtıldıktan sonra (FP-Growth algoritmasının adı geçti) yeni bir veri kümesine geçildi: "Table 2.3 The Credit Card Promotion Database" (ekrandan, 02:05:00).

<!-- BELİRSİZ: Pazar sepeti analizinin anlatımı (02:02:42-02:05:00) altyazıda büyük ölçüde bozuk ve bu anın karesi yok. -->

| # | Income Range ($) | Magazine Promotion | Watch Promotion | Life Insurance Promotion | Credit Card Insurance | Sex | Age |
|---|---|---|---|---|---|---|---|
| 1 | 40–50K | Yes | No | No | No | Male | 45 |
| 2 | 30–40K | Yes | Yes | Yes | No | Female | 40 |
| 3 | 40–50K | No | No | No | No | Male | 42 |
| 4 | 30–40K | Yes | Yes | Yes | Yes | Male | 43 |
| 5 | 50–60K | Yes | No | Yes | No | Female | 38 |
| 6 | 20–30K | No | No | No | No | Female | 55 |
| 7 | 30–40K | Yes | No | Yes | Yes | Male | 35 |
| 8 | 20–30K | No | Yes | No | No | Male | 27 |
| 9 | 30–40K | Yes | No | No | No | Male | 43 |
| 10 | 30–40K | Yes | Yes | Yes | No | Female | 41 |
| 11 | 40–50K | No | Yes | Yes | No | Female | 43 |
| 12 | 20–30K | No | Yes | Yes | No | Male | 29 |
| 13 | 50–60K | Yes | Yes | Yes | No | Female | 39 |
| 14 | 40–50K | No | Yes | No | No | Male | 55 |
| 15 | 20–30K | No | No | Yes | Yes | Female | 19 |

(Sıra numarası sütunu okumayı kolaylaştırmak için eklendi; slaytta yoktur.)

Bu veri kümesinde çıkış değişkeni Life Insurance Promotion'dır. Kalan öznitelikler (Income Range, Magazine Promotion, Watch Promotion, Credit Card Insurance, Sex, Age) giriş değişkenleri, yani özelliklerdir.

**Soru (hoca):** Bu veri kümesinde kaç sayısal özellik vardır? **Cevap:** Yalnız bir tane: Age. Income Range bir aralık verdiği için sayısal değildir. Aralıklar sıralanabilir ama aralıklar arasındaki uzaklık ölçülemez; bu yüzden gelir aralığı kategoriktir.

### 8.2 Kural 1: kadın ve 19-43 yaş

Veriden bir karar ağacı kurulur ve bu ağaca göre üretim kuralları (production rules) yazılır. Yazılan her üretim kuralı için kural doğruluğu (rule accuracy) ve kural kapsamı (rule coverage) ölçülür. Slayttaki kural (ekrandan, 02:10:00):

```text
IF Sex = Female & 19 <= Age <= 43
THEN Life Insurance Promotion = Yes

Rule Accuracy: 100.00%
Rule Coverage: 66.67%
```

Hesap adım adım şöyledir:

- Veri kümesinde 7 kadın kart sahibi vardır (satır 2, 5, 6, 10, 11, 13, 15).
- Bunlardan yaşı 19 ile 43 arasında olanlar 6 kişidir (satır 6'daki 55 yaşındaki kadın dışarıda kalır).
- Bu 6 kişinin hepsi Life Insurance Promotion için "Yes" demiştir. Kural doğruluğu: $\dfrac{6}{6} = \%100$.
- Kapsam için sonuç sınıfına bakılır: Life Insurance Promotion = Yes diyen toplam 9 kart sahibi vardır (satır 2, 4, 5, 7, 10, 11, 12, 13, 15).
- Kural bu 9 kişiden yalnız 6'sını doğru tanımlar. Kural kapsamı: $\dfrac{6}{9} \approx \%66{,}67$.

### 8.3 Kural 2: erkek ve 40-50K gelir

Hoca ikinci kuralı öğrencilere hesaplattı:

```text
IF Sex = Male & Income Range = 40-50K
THEN Life Insurance Promotion = No
```

- Veri kümesinde 8 erkek kart sahibi vardır.
- Bunlardan gelir aralığı 40–50K olanlar 3 kişidir (satır 1, 3, 14) ve üçü de "No" demiştir. Kural doğruluğu: $\dfrac{3}{3} = \%100$.
- Life Insurance Promotion = No diyen toplam 6 kişi vardır (satır 1, 3, 6, 8, 9, 14). Kural bunların 3'ünü tanımlar. Kural kapsamı: $\dfrac{3}{6} = \%50$.

İki kuralın sonuçları ajan tarafından python ile doğrulandı.

### 8.4 Sınıflar arası ve sınıf içi ölçü

Slaytta şu iki cümle vardır (ekrandan, 02:10:00):

- Rule accuracy is a between-class measure (kural doğruluğu sınıflar arası bir ölçüdür).
- Rule coverage is a within-class measure (kural kapsamı sınıf içi bir ölçüdür).

Kapsam hesaplanırken yalnız ilgili sınıfa ait kayıtlar sayılır: birinci kuralda "Yes" diyen 9 kişi, ikinci kuralda "No" diyen 6 kişi. Kural, o sınıfın ne kadarını yakaladığını ölçer; bu yüzden sınıf içi bir ölçüdür. Doğrulukta ise kuralın koşulunu sağlayan kayıtların hangi sınıflara düştüğüne bakılır.

> **Ders sonrası not:** Hoca kapsamı anlatırken bir yerde "bu yüzden sınıflar arası bir ölçüdür" dedi (02:16:59 civarı); slayta ve kendi sonraki açıklamasına göre doğrusu, kural kapsamının sınıf içi (within-class), kural doğruluğunun sınıflar arası (between-class) ölçü olmasıdır.

## 9. Bilgi keşfi (KDD) süreci ve iş zekâsı

### 9.1 KDD süreci

Slayt başlığı "Knowledge Discovery (KDD) Process"tir ve veri madenciliğinin bilgi keşfi sürecinin çekirdeği olduğunu söyler (ekrandan, 02:25:00). Şemadaki akış:

```text
Databases
  → Data Cleaning + Data Integration
  → Data Warehouse
  → Selection
  → Task-relevant Data
  → Data Mining
  → Pattern Evaluation
  → Knowledge
(Örüntü değerlendirmeden önceki adımlara geri dönüş okları vardır.)
```

Süreç bir veritabanıyla başlar; veriler farklı kaynaklardan gelir ve temizlenip bütünleştirilir. Alan bilgisi (domain knowledge) varsa görev için gerekli özellikler belirlenir ve veriden pek çok farklı özellik üretilir. Seçim adımıyla göreve uygun veri (task-relevant data) elde edilir.

Görev bilindiğinde veri madenciliği tekniği seçilebilir:

- Sınıf etiketli veri varsa ve çıkış değişkeni kategorikse sınıflama algoritması seçilir.
- Çıkış sayısalsa regresyon yöntemi seçilir.
- Sınıf etiketi olmayan bir veri kümesi varsa kümeleme teknikleri kullanılır.

Veri madenciliği algoritmaları uygulandığında bir sonuç elde edilir; bu sonucun incelendiği adım örüntü değerlendirmedir (pattern evaluation). Sonuç tatmin edici değilse önceki adımlara dönülür.

> **Hocanın vurgusu:** Ön işleme kısmı, yani özellik çıkarma, veri temizleme ve ön işleme, emeğin yaklaşık %60'ını alır. Bu aşama çok önemlidir ve çok zaman alır; çünkü özellikleri çıkarmak için veritabanı yöneticileriyle birlikte çalışmak gerekir.

### 9.2 Veri madenciliği ve iş zekâsı

"Data Mining and Business Intelligence" slaytındaki piramit aşağıdan yukarı şöyledir (ekrandan, 02:30:00):

| Katman | Açıklama | İlgili rol |
|---|---|---|
| Decision Making | Karar verme | End User (son kullanıcı) |
| Data Presentation | Görselleştirme teknikleri | Business Analyst (iş analisti) |
| Data Mining | Bilgi keşfi | Data Analyst (veri analisti) |
| Data Exploration | İstatistiksel özet, sorgulama ve raporlama | Data Analyst |
| Data Preprocessing/Integration, Data Warehouses | Ön işleme, bütünleştirme, veri ambarları | DBA |
| Data Sources | Kâğıt, dosyalar, web belgeleri, bilimsel deneyler, veritabanı sistemleri | DBA |

Piramitte yukarı çıkıldıkça iş kararlarını destekleme potansiyeli artar.

Çalışmanın başında verinin analiz edilmesi ve yapısının anlaşılması gerekir. Bu yüzden veri keşfi (data exploration) de çok önemlidir. Ortalama, standart sapma, korelasyon ve kovaryans gibi istatistiksel özetler kontrol edilir; ardından veri madenciliği teknikleri seçilir.

<!-- BELİRSİZ: Piramitteki rol sütununda Data Exploration katmanının hangi role eşlendiği karede tam net değil; tablo slayttaki konumlara göre kuruldu. -->

Ders planına göre sonraki dört hafta veri ön işleme konularına ayrılmıştır.

## Örnek Sorular

**Soru 1** (ekrandan, 01:20:00; derste sözlü, 01:25:49): Hastalık teşhisi verisinden elde edilen karar ağacına (kök Swollen Glands; Yes → Strep throat; No ise Fever: Yes → Cold, No → Allergy) göre ID 11 numaralı hastanın teşhisi nedir?

> **Çözüm (derste verildi):** ID 11 için Swollen Glands = No, Fever = No olduğundan teşhis Allergy'dir.

<!-- BELİRSİZ: ID 11 hastasının diğer özellik değerleri karede yok. -->

**Soru 2** (derste sözlü, 01:41:04): Kestirim (estimation) için bir örnek veriniz.

> **Çözüm (derste verildi):** Ev fiyatı tahmini; evin konumu, katı, oda sayısı ve bölgedeki ev fiyatlarından evin bugünkü fiyatı tahmin edilir. Bağımlı değişken sayısaldır ve mevcut durum tahmin edilir.

**Soru 3** (derste sözlü, 01:44:38): Hava durumu tahmini kestirim için iyi bir örnek midir?

> **Çözüm (derste verildi):** Hayır. Hava durumu tahmini geleceğe dönüktür, bu yüzden öngörü (prediction) örneğidir. "Yarın 25 derece" sayısal, "yarın yağmurlu" kategorik çıkışlı öngörüdür.

**Soru 4** (ekrandan, 02:05:00; derste sözlü, 02:07:31): Kredi kartı promosyon veri kümesinde kaç sayısal öznitelik vardır?

> **Çözüm (derste verildi):** Bir tane, Age. Income Range aralık verdiği için kategoriktir; aralıklar sıralanabilir ama aralarındaki uzaklık ölçülemez.

**Soru 5** (ekrandan, 02:10:00): `IF Sex = Female & 19 <= Age <= 43 THEN Life Insurance Promotion = Yes` kuralının doğruluğunu ve kapsamını hesaplayınız.

> **Çözüm (derste verildi):** Koşulu sağlayan 6 kişinin 6'sı "Yes" → doğruluk $6/6 = \%100$. "Yes" diyen 9 kişinin 6'sı yakalanır → kapsam $6/9 \approx \%66{,}67$.

**Soru 6** (derste sözlü, 02:17:29): `IF Sex = Male & Income Range = 40-50K THEN Life Insurance Promotion = No` kuralının doğruluğunu ve kapsamını hesaplayınız.

> **Çözüm (derste verildi):** Koşulu sağlayan 3 erkeğin 3'ü "No" → doğruluk $3/3 = \%100$. "No" diyen 6 kişinin 3'ü yakalanır → kapsam $3/6 = \%50$.

## Dersin Toparlaması

Bu giriş dersinde veri madenciliğinin neden gerekli olduğu, büyük veri kaynakları ve veritabanı teknolojisiyle ilişkisi anlatıldı; veri madenciliği, büyük veriden ilginç örüntü ve bilgi çıkarma işi olarak tanımlandı. Dolandırıcılık tespiti gibi uygulama alanlarından sonra dersin bel kemiği olan üç strateji tanıtıldı: gözetimli öğrenme (sınıflama, kestirim, öngörü), gözetimsiz kümeleme ve pazar sepeti analizi. Hastalık teşhisi karar ağacı gözetimli öğrenmenin iki adımını, Acme yatırımcılar verisi aynı verinin hem kümeleme hem sınıflama için kullanılabileceğini gösterdi. Sınıflama, kestirim ve öngörü; çıkış değişkeninin türü ve mevcut durum/gelecek ayrımıyla birbirinden ayrıldı. Kredi kartı promosyon veri kümesinde üretim kurallarının doğruluğu ve kapsamı hesaplandı.

Son olarak KDD süreci ve iş zekâsı piramidiyle veri madenciliğinin daha büyük bir sürecin parçası olduğu, emeğin büyük kısmının ön işlemeye gittiği vurgulandı. Sonraki haftalarda veri madenciliği kavramları ve veri ön işleme teknikleriyle devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
