# Ders 3 Genişletilmiş Notu: Zamana Bağlı Veri, Aykırı Değer Analizi ve Veri İndirgeme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı ve Ham Verinin Özellikleri
- 2. Zamana Bağlı Veri
- 3. Aykırı Değer Analizine Giriş
- 4. Kutu Grafiği (Box Plot) Analizi
- 5. Uzaklık Tabanlı Aykırı Değer Analizi
- 6. Ortalama ve Standart Sapma ile Aykırı Değer Analizi
- 7. Veri İndirgeme
- 8. Ortalama ve Varyans ile Öz Nitelik Seçimi
- Örnek Sorular

## 1. Önceki Dersin Tekrarı ve Ham Verinin Özellikleri

Ders, veri ön işleme (data preprocessing) konusunun devamıdır. Önceki derste veri tipleri (sayısal ve kategorik veri) ve özellikleri, ardından ham verinin dönüşümü ele alınmıştı. Dönüşüm başlığı altında veri normalizasyonu ve veri düzleştirme (data smoothing) işlemleri, düzleştirme için de iki farklı çözüm anlatılmıştı.

Ekrandaki "Characteristics of Raw Data" slaytı ham verinin genel özelliklerini özetler (ekrandan, 00:15:00):

- Veri madenciliği için hazırlanan ham veri setleri genelde büyüktür; birçoğu insanlarla ilgilidir ve dağınık olma potansiyeli taşır.
- Baştan eksik değerler, bozulmalar, hatalı kayıtlar ve yetersiz örnekleme beklenmelidir.
- Bu sorunların hiçbirini göstermeyen ham veri hemen şüphe uyandırmalıdır.
- Verinin bu kadar kaliteli olmasının tek gerçek nedeni, analist görmeden önce temizlenmiş ve ön işlenmiş olmasıdır; doğru tasarlanmış bir veri ambarındaki veri gibi.

## 2. Zamana Bağlı Veri

### 2.1 Tanım ve amaç

Zamana bağlı veride (time-dependent data) tek bir öz nitelik sabit bir zaman birimiyle ölçülüp kaydedilir. Hocanın örnekleri: her saat, her gün ya da her hafta ölçülen hava sıcaklığı, her günün en yüksek sıcaklığı ve borsadaki günlük ya da saatlik fiyatlar.

Böyle bir seri $X = \{t(1), t(2), t(3), \dots, t(n)\}$ biçiminde yazılır; $t(n)$ en güncel ölçümdür. Zaman serisinde amaç genelde öngörüdür (forecast): öz niteliğin önceki değerlerinden $t(n+1)$ değerini tahmin etmek. Bunun için seriye bazı ön işleme adımları uygulanıp veri yeniden yapılandırılır.

### 2.2 Pencere ile tabloya dönüştürme

Hoca 11 ölçümden oluşan bir seri ($t(0)$ ile $t(10)$ arası) üzerinden anlattı. Seriyi analiz etmek için bir pencere (window) tanımlanır; örnekte pencere boyutu 5'tir. İlk beş değer girdi değişkenleri, hemen ardından gelen değer çıktı değişkeni (next value) olur. Pencere bir adım kaydırılarak ikinci örnek elde edilir: sonraki beş değer girdi, ondan sonraki değer çıktı.

Slayttaki "Table 2.1: Transformation of Time Series to standard tabular form (window = 5)" tablosu (ekrandan, 00:20:00):

| Örnek | M1 | M2 | M3 | M4 | M5 | Next Value |
|---|---|---|---|---|---|---|
| 1 | t(0) | t(1) | t(2) | t(3) | t(4) | t(5) |
| 2 | t(1) | t(2) | t(3) | t(4) | t(5) | t(6) |
| 3 | t(2) | t(3) | t(4) | t(5) | t(6) | t(7) |
| 4 | t(3) | t(4) | t(5) | t(6) | t(7) | t(8) |
| 5 | t(4) | t(5) | t(6) | t(7) | t(8) | t(9) |
| 6 | t(5) | t(6) | t(7) | t(8) | t(9) | t(10) |

> **Ders sonrası not:** Slaytta 4. satırın çıktısı $t(7)$ yazılmıştır; pencerenin kayma düzenine göre doğrusu $t(8)$'dir. Tabloya düzeltilmiş hali konmuştur.

Altı örneğin hepsinin çıktısı bilindiği için bu tablo bir eğitim veri setidir ve bir model kurmak için kullanılır. Model kurulduktan sonra $t(6), t(7), t(8), t(9), t(10)$ girdi olarak verilir ve $t(11)$ bir sonraki değer olarak tahmin edilir.

### 2.3 Daha uzak geleceği tahmin etme

Bazen $t(n+1)$ yerine $t(n+3)$ ya da $t(n+5)$ gibi daha uzak bir değer tahmin edilmek istenir; örneğin önümüzdeki üç günün hava sıcaklığı. Genel olarak çıktı $t(n+j)$ olarak seçilir. Pencere boyutu yine 5 iken $t(n+3)$ tahmin ediliyorsa ilk beş değerin karşısına çıktı olarak $t(7)$ yazılır. Elde edilen veri etiketlidir, ama çıktı sayısal olduğu için bu bir tahmin (prediction) problemidir ve sonraki değerler regresyon yöntemleriyle kestirilir.

Ekrandaki slayt bu konuyu şöyle tamamlar (ekrandan, 00:25:00):

- Genel olarak gelecek ne kadar uzaksa tahmin o kadar zor ve o kadar az güvenilirdir.
- Zaman serisindeki hedef, bir sonraki değeri tahmin etmekten önceden tanımlı kategorilerden birine sınıflandırmaya kolayca çevrilebilir.
- Veri hazırlama açısından önemli bir değişiklik olmaz.
- Örneğin $t(i+1)$ tahmini yerine çıktı ikili olur: $t(i+1) \ge$ eşik ise T, $t(i+1) <$ eşik ise F.

Hoca, zamana bağlı veri için birçok farklı yöntem bulunduğunu, bu derste yalnız verinin yapısını ve veri madenciliğine hazırlanmasını verdiğini belirtti.

## 3. Aykırı Değer Analizine Giriş

### 3.1 Aykırı değer nedir

Hoca bu bölümü veri ön işlemenin en önemli kısmı olarak tanıttı. Yanlış ölçüm, ölçüm hatası ya da verinin yapısındaki değişkenlik nedeniyle bir veri setinde verinin genelinden belirgin biçimde farklı ya da tutarsız örnekler olabilir. Bunlara aykırı değer (outlier) denir. Bir değer yazım hatasıyla da aykırı hale gelebilir: hoca bir rakamın yanlış yazılmasıyla oluşan bir değeri örnek verdi. <!-- BELİRSİZ: 00:26:31-00:26:50 arasında slayttaki örneğin hangi öz nitelik olduğu ve hangi rakamın yerine hangisinin yazıldığı altyazıdan tam anlaşılmıyor; ilgili kare yok. -->

Verinin yapısı incelenip belirgin farklı değerler bulunmalı ve veri setinden çıkarılmalıdır. Bu bölümde aykırı değerlerin otomatik olarak bulunup elenmesi işlenir. Öte yandan bazı uygulamalarda aranan şey aykırı değerin kendisidir: bankalarda sahte (fraudulent) kredi kartı işlemlerini tespit etmek için ayrı birimler bulunur.

Çok boyutlu veri setinde aykırı değer bulmak zor olabilir. Tek değişkenli (univariate) çözümler her öz nitelik için aykırı değerleri ayrı ayrı bulur. Veriyi bir, iki ya da üç boyutta görselleştirmek de aykırı değer bulmaya yardımcı olur: iki ya da üç boyutlu veri çizilip aykırı değerler gözle belirlenebilir.

### 3.2 Görsel örnek ve sınıf tartışması

Slayttaki grafikte yatay eksen bir öz niteliği, dikey eksen başka bir öz niteliği gösterir ve yedi örnek düzleme yerleştirilmiştir (ekrandan, 00:30:00). Grafiğe göre örneklerin konumları: $s_1 = (2,4)$, $s_2 = (3,2)$, $s_3 = (1,1)$, $s_4 = (4,3)$, $s_5 = (1,6)$, $s_6 = (5,3)$, $s_7 = (4,2)$. Örneklerin çoğu ortada toplanmıştır; $s_3$ ve $s_5$ bu bölgeden uzaktadır ve aykırı değer olarak işaretlenmiştir.

Hoca, gözle verilen bu kararın matematiksel olarak nasıl verilebileceğini sordu. Verinin sınıf etiketi yoktur, yani pozitif/negatif sınıf ayrımı yapılamaz.

**Soru:** Bir öğrenci noktaları ayıran bir vektör (destek vektörü benzeri bir sınır) çizmeyi ya da örneklerin çoğunu içine alan bir daire çizmeyi önerdi. **Cevap:** Hoca fikri bir merkez noktasına yönlendirdi: tüm örneklerin ortalaması alınarak verinin dağıldığı bir merkez noktası bulunabilir.

**Soru:** Merkez bulunduktan sonra ne yapılır? **Cevap (bir öğrenci):** Her noktanın merkeze uzaklığı hesaplanır ve en uzaktakiler aykırı değer olarak işaretlenir. Hoca bunu doğru bir çözüm olarak kabul etti.

**Soru:** Veri sınıf etiketli olsaydı ne yapılırdı? **Cevap:** Aynı çözüm sınıf bazında uygulanır: her sınıfın kendi ortalaması (sınıf içi ortalama) bulunur ve örneklerin bu sınıf merkezine uzaklığına göre aykırı değerler belirlenir. Hoca bunun bütün öz nitelikleri işin içine katan çok boyutlu bir çözüm olduğunu vurguladı.

Derste aykırı değer analizi için üç çözüm işlendi: kutu grafiği analizi, uzaklık tabanlı çözüm ve ortalama-standart sapma çözümü.

## 4. Kutu Grafiği (Box Plot) Analizi

### 4.1 Tanımlar

Kutu grafiğinde önce verinin en küçük ve en büyük değeri bulunur ve medyan belirlenir. Medyan veriyi iki parçaya böler. Alt parçanın medyanı $Q_1$ (25. yüzdelik), üst parçanın medyanı $Q_3$ (75. yüzdelik) olur. Veri bu beş sayıyla temsil edilir: beş sayı özeti.

Slayttaki tanımlar (ekrandan, 00:40:00):

- Çeyrekler: $Q_1$ (25. yüzdelik), $Q_3$ (75. yüzdelik).
- Çeyrekler açıklığı: $IQR = Q_3 - Q_1$.
- Beş sayı özeti: min, $Q_1$, $M$, $Q_3$, max.
- Kutu grafiği: kutunun uçları çeyreklerdir, medyan işaretlenir, bıyıklar çizilir ve aykırı değerler tek tek gösterilir.
- Aykırı değer: genelde $1.5 \times IQR$'den daha yüksek ya da daha düşük olan değer.
- Yaygın kural: üçüncü çeyreğin en az $1.5 \times IQR$ üstünde ya da birinci çeyreğin en az $1.5 \times IQR$ altında kalan değerler şüpheli aykırı değer olarak ayrılır.

### 4.2 Yaş örneği

Slaytta artan sırada dizilmiş bir yaş öz niteliği verildi; değerler 13 ile 70 arasındadır. <!-- BELİRSİZ: yaş değerlerinin tam listesi slayttaydı, ama o anın karesi yok ve altyazıda değerler okunmuyor; aşağıdaki çözüm tahtadaki sonuçlardan kuruldu. --> Sorular: veri setinde kaç örnek var, ortalama nedir, medyan nedir, $Q_1$ ve $Q_3$ nedir? Çözüm tahtada yapıldı (ekrandan, 00:55:00).

- **Örnek sayısı:** 27.
- **Medyan:** 27 örnekte ortadaki eleman 14. sıradadır. Değeri $M = 25$'tir.
- **$Q_1$ ve $Q_3$:** Medyanın solunda 13, sağında 13 örnek kalır. 13 örneğin ortası 7. sıradır. Alt yarının 7. elemanı $Q_1 = 20$, üst yarının 7. elemanı $Q_3 = 35$'tir.
- **IQR:** $IQR = Q_3 - Q_1 = 35 - 20 = 15$.
- **Eşik:** $1.5 \times IQR = 1.5 \times 15 = 22.5$.
- **Alt sınır:** $Q_1 - 22.5 = 20 - 22.5 = -2.5$. Verideki en küçük değer 13'tür ve bu sınırın içindedir. Bu yüzden alt sınırın altında örnek yoktur ve alt bıyık en küçük değer olan 13'te kapatılır.
- **Üst sınır:** $Q_3 + 22.5 = 35 + 22.5 = 57.5$. Verideki en büyük değer 70 bu sınırın dışındadır.
- **Sonuç:** 70 bir aykırı değerdir. Veri setinde 57.5'ten büyük başka değerler (örneğin 60 ya da 65) olsaydı onlar da aykırı olurdu.

Tahtadaki son çizimde kutu $Q_1 = 20$ ile $Q_3 = 35$ arasındadır, $M = 25$ kutunun içinde işaretlidir, alt bıyık 13'te kapatılmıştır, üst sınır 57.5'te kesikli çizgiyle gösterilmiş ve 70 "outlier" olarak ayrıca işaretlenmiştir; $-2.5$'in altı da aykırı bölge olarak gösterilmiştir (ekrandan, 00:55:00).

> **Hocanın vurgusu:** Sınırın dışında değer yoksa kutu grafiğinin ucu en küçük ya da en büyük gerçek değerde kapatılır. Sınırın dışında bir değer varsa uç bu şekilde kapatılmaz; kapatmak "dışarıda değer yok" anlamına gelir. Bu örnekte üst uç açık bırakıldı, çünkü 70 dışarıdadır.

Hoca, kutu grafiğinin veriyi tarif ederken sık kullanılan bir grafik olduğunu ve bitirme tezi, proje ya da makale gibi çalışmalarda kullanılırsa veriyi iyi analiz ettiğinizi gösterdiğini söyleyerek kullanılmasını tavsiye etti.

### 4.3 Katsayının değiştirilmesi

$1.5 \times IQR$ sabit bir değer değildir. Derste kural olarak 1.5 kabul edilir. Ancak uygulamada çok fazla aykırı değer çıkıyorsa katsayı artırılır (örneğin $2 \times IQR$) ve aykırı sayısı azalır. Gerekirse katsayı düşürülerek $1 \times IQR$ de kullanılabilir.

Hoca ayrıca verilen veri setinin ortalamasını hesaplamayı sordu; bu soru derste sonuçlandırılmadı.

## 5. Uzaklık Tabanlı Aykırı Değer Analizi

### 5.1 Problem

Slayt başlığı "Outlier Analysis (Distance-based solution) (Multi-variate solution)" (ekrandan, 01:15:00):

- İki boyutlu örneklerden oluşan veri seti: $X = \{(2,4), (3,2), (1,1), (4,3), (1,6), (5,3), (4,2)\}$.
- a) Uzaklık tabanlı teknikle aykırı değerleri bulun.
- Eşik uzaklık 3'tür ($d \ge 3$); komşu olmayan örnekler için eşik sayı $p$ 4'tür ($p \ge 4$).
- İpucu: Bir $x_i$ örneği, uzaydaki örneklerin en az $p$ kadarı kendisine $d$'den daha uzaktaysa aykırı değerdir.

Bir örneğe uzaklığı eşik uzaklık 3'ten büyük ya da eşit olan örneklere o örneğin "komşu olmayanları" (non-neighbors) denir. Bir örneğin komşu olmayan sayısı 4 ya da daha fazlaysa örnek aykırıdır.

### 5.2 Uzaklık matrisi

Yatay eksen $x_1$, dikey eksen $x_2$ öz niteliğidir; örnekler $s_1 = (2,4)$, $s_2 = (3,2)$, $s_3 = (1,1)$, $s_4 = (4,3)$, $s_5 = (1,6)$, $s_6 = (5,3)$, $s_7 = (4,2)$ olarak tahtaya yerleştirildi (ekrandan, 01:20:00). Uzaklıklar Öklid uzaklığı ile hesaplanır:

$$d(s_i, s_j) = \sqrt{(\Delta x_1)^2 + (\Delta x_2)^2}$$

Örneğin $d(s_1, s_2) = \sqrt{(3-2)^2 + (2-4)^2} = \sqrt{5}$.

Bu uzaklıklarla 7x7 boyutlu bir uzaklık matrisi kurulur. Ana köşegen bir örneğin kendisine uzaklığıdır ve sıfırdır. $d(s_1, s_2) = d(s_2, s_1)$ olduğu için matris simetriktir; yalnız üst üçgeni hesaplamak yeter. Değerler sınıfla birlikte tek tek bulundu (ekrandan, 01:35:00):

```text
         s1    s2    s3    s4    s5    s6    s7
  s1     0    √5   √10    √5    √5   √10    √8
  s2           0    √5    √2   √20    √5     1
  s3                 0   √13     5   √20   √10
  s4                       0   √18     1     1
  s5                             0     5     5
  s6                                   0    √2
  s7                                         0
```

### 5.3 Her örnek için komşu olmayan sayısı

Bir örneğin satırına ve (simetri nedeniyle) sütununa bakılarak 3'ten büyük uzaklıklar sayılır. $\sqrt{10} \approx 3.16$, $\sqrt{13}$, $\sqrt{18}$, $\sqrt{20}$ ve 5 eşiğin üstündedir; $\sqrt{8} \approx 2.83$, $\sqrt{5}$, $\sqrt{2}$ ve 1 altındadır.

- $s_1$: $\sqrt{10}$ ($s_3$) ve $\sqrt{10}$ ($s_6$); $p = 2$. Altı örnekten yalnız ikisi uzakta, dördü yakındadır; aykırı değil.
- $s_2$: yalnız $\sqrt{20}$ ($s_5$); $p = 1$; aykırı değil.
- $s_3$: $\sqrt{10}$, $\sqrt{13}$, 5, $\sqrt{20}$, $\sqrt{10}$; $p = 5 \ge 4$; **$s_3$ aykırıdır.**
- $s_4$: $\sqrt{13}$ ($s_3$) ve $\sqrt{18}$ ($s_5$); $p = 2$; aykırı değil.
- $s_5$: $\sqrt{20}$, 5, $\sqrt{18}$, 5, 5; $p = 5 \ge 4$; **$s_5$ aykırıdır.**
- $s_6$: $\sqrt{10}$, $\sqrt{20}$, 5; $p = 3$; aykırı değil.
- $s_7$: $\sqrt{10}$ ($s_3$) ve 5 ($s_5$); $s_1$'e uzaklık $\sqrt{8}$ eşiğin altındadır; $p = 2$; aykırı değil.

Tahtadaki sonuç: "S3 is an outlier!", "S5 is an outlier!" (ekrandan, 01:45:00). Verilen eşik uzaklık ve komşu olmayan sayısı kuralına göre iki örnek aykırı değer olarak seçildi; bu, grafikte gözle seçilen örneklerle aynıdır. Komşu olmayan sayıları python ile de doğrulandı.

Hoca, kutu grafiği analizinin ise tek değişkenli olduğunu hatırlattı: çok öz nitelikli veride her sütuna ayrı ayrı kutu grafiği analizi uygulanır ve karar bu sonuçlara göre verilir.

## 6. Ortalama ve Standart Sapma ile Aykırı Değer Analizi

### 6.1 Fikir

Üçüncü çözüm ortalama ve standart sapmayı kullanır. Normal dağılımda ortalama $m$ ve standart sapma $s$ ise $m - 2s$ ile $m + 2s$ dağılımın sınırlarını belirler; bu aralığın dışında kalan bölgeler aykırı bölgedir. Her öz nitelik (sütun) için ortalama ve standart sapma hesaplanır, eşik olarak $m \pm 2s$ kullanılır ve dışarıda kalan değerler aykırı sayılır.

### 6.2 Aynı veri üzerinde çözüm

Tahtadaki tablo (ekrandan, 01:55:00):

| Örnek | $x_1$ | $x_2$ |
|---|---|---|
| $s_1$ | 2 | 4 |
| $s_2$ | 3 | 2 |
| $s_3$ | 1 | 1 |
| $s_4$ | 4 | 3 |
| $s_5$ | 1 | 6 |
| $s_6$ | 5 | 3 |
| $s_7$ | 4 | 2 |

- Ortalamalar: $m(x_1) = 20/7 \approx 2.85$ (tahtada 2.85; tam değer 2.857), $m(x_2) = 21/7 = 3$.
- Standart sapmalar: $s(x_1) \approx 1.57$, $s(x_2) \approx 1.63$.
- $x_1$ sınırları: $m(x_1) - 2s(x_1) = 2.85 - 2 \times 1.57 \approx -0.29$ ve $m(x_1) + 2s(x_1) = 2.85 + 3.14 = 5.99$.
- $x_1$ değerleri (2, 3, 1, 4, 1, 5, 4) içinde $-0.29$'dan küçük ya da $5.99$'dan büyük değer yoktur; $x_1$'e göre aykırı değer yoktur.
- $x_2$ sınırları: $3 - 2 \times 1.63 = -0.26$ ve $3 + 2 \times 1.63 = 6.26$.
- $x_2$ değerleri (4, 2, 1, 3, 6, 3, 2) içinde de sınır dışında değer yoktur.
- Sonuç: bu eşikle veri setinde aykırı değer yoktur.

> **Ders sonrası not:** Tahtada $x_2$ üst sınırı 6.29 yazıldı; $3 + 2 \times 1.63 = 6.26$ olmalıdır. Sonuç değişmez. Tahtadaki standart sapmalar örneklem standart sapmasıdır ($n - 1$ ile); değerler python ile doğrulandı.

> **Ek bilgi (derste anlatılmadı):** Aynı veride uzaklık tabanlı yöntem $s_3$ ve $s_5$'i aykırı bulurken bu tek değişkenli yöntem hiçbir aykırı değer bulmaz. $s_5$'in $x_2$ değeri (6) üst sınıra yakındır ama içindedir. Bu fark, örneklerin konumunu öz nitelikleri birlikte değerlendirerek inceleyen yöntemlerin tek değişkenli yöntemlerden farklı sonuç verebileceğini gösterir.

### 6.3 Katsayının seçimi

Standart sapmanın önündeki 2 katsayısı da sabit değildir; uygulamaya göre değiştirilebilir.

**Soru (hocanın sorusu):** Bir uygulamada $m \pm 2s$ eşiğiyle örneklerin %20'si aykırı olarak etiketlendi ve veriden atılacak. Bu kadar veriyi atmak istemiyoruz. Standart sapmanın katsayısını 2 yerine ne seçmek iyi olur? **Cevap:** Katsayı artırılmalıdır; öğrencilerden 4 gibi değerler geldi, hoca 3'ü denemeyi önerdi. Katsayı artınca normal kabul edilen bölge dışa doğru genişler, aykırı bölge küçülür. 3, 3.5 gibi değerler kademeli olarak denenebilir; gerektiğinde 1.5 ya da 2.5 gibi oranlar da seçilebilir.

> **Hocanın vurgusu:** Normal şartlarda bir veri setinde çok büyük miktarda aykırı değer çıkmaz; aykırı değer oranı genelde %5 civarındadır. Verinin %20-25'ini bu yolla atmak acımasızlık olur. Çok büyük bozulmaların olduğu veri setlerinde belki böyle bir yola gidilebilir, ama tercih edilen bir şey değildir.

### 6.4 Tek değişkenli yöntemin sonucu: örnek tümüyle silinir

**Soru:** Bir verinin $x_1$ değeri eşiğin dışında çıkarsa bu veri (örnek) komple mi silinir? **Cevap:** Evet. Örneğin $x_2$ için üst sınır 6.29 (doğrusu 6.26) iken $s_5$'in $x_2$ değeri 6 değil 6.5 olsaydı, $x_2$'ye bakılarak $s_5$ aykırı kabul edilir ve $s_5$ örneği, $x_1$ değeri normal olsa bile, veri setinden tümüyle silinirdi. Tek değişkenli yöntemde her öz nitelik kendi içinde kontrol edilir; bu açıdan çok iyi bir çözüm değildir.

> **Hocanın vurgusu:** İdeal olan, veri setine bir bütün olarak bakan uzaklık tabanlı yaklaşımlardır. $p$ ve $d$ eşiklerini belirlemek zordur; bu yüzden dersin başında konuşulan çözüm (tüm verinin merkezini bulup örneklerin bu merkeze uzaklığına göre en uzaktakileri belirlemek) hocaya daha anlamlı gelmektedir.

## 7. Veri İndirgeme

### 7.1 Bölümün hedefleri

"Data Reduction, Chapter Objectives" slaytındaki hedefler (ekrandan, 02:20:00):

- Öz nitelikler, örnekler (cases) ve değer indirgeme teknikleri açısından boyutluluk farkını tanımlamak.
- Veri madenciliği sürecinin ön işleme aşamasında veri indirgemenin avantajlarını açıklamak.
- Öz nitelik seçimi ve öz nitelik birleştirme görevlerinin temel ilkelerini ilgili istatistiksel yöntemlerle anlamak.
- Öz nitelik sıralaması için entropi tabanlı tekniği ve temel bileşen analizini (PCA) uygulamak ve karşılaştırmak.
- Ayrık değerlerin indirgenmesi için ChiMerge ve kutu (bin) tabanlı teknikleri anlamak ve uygulamak.
- İndirgemenin artımlı (incremental) ve ortalama örneklere dayandığı yaklaşımları ayırt etmek.

Hoca, normalizasyon, eksik veri eleme ve aykırı değer analizinden sonra veri miktarını azaltmak gerektiğini, indirgemenin öz niteliklere, örneklere ve değerlere uygulanacağını söyledi. Sınıf etiketi yoksa öz nitelik sıralaması için entropi tabanlı teknik ve PCA kullanılır.

### 7.2 Neden veri indirgeme

Veri setlerinde çok sayıda öz nitelik olabilir; bazı uygulamalarda 200-300, hatta yüzlerce öz nitelik bulunur. Yüksek boyutluluk nedeniyle oluşan veri yükü bazı veri madenciliği algoritmalarını uygulanamaz kılabilir ve sonuca ulaşmak çok uzun sürer.

Hoca önceki derslerdeki beden kitle indeksi örneğini hatırlattı: beden kitle indeksi kişinin boyu ve kilosu kullanılarak hesaplanır. Daha değerli bir öz nitelik üretilebildiği için boy ve kilo öz nitelikleri veriden çıkarılabilir.

Veri indirgemenin son hali sonuçların kalitesini düşürmemelidir; bazı uygulamalarda veri madenciliği sonuçları indirgemeden sonra iyileşir, çünkü gereksiz öz nitelikler sonuçların başarımını düşürebilir.

Veri indirgemenin avantajları:

- **Hesaplama süresi:** Daha sade veriyle gereken işlem süresi azalır.
- **Tahmin ve betimleme doğruluğu:** Gereksiz öz nitelikler elenirse veri madenciliği sonunda doğruluk artabilir.
- **Sade gösterim:** Model daha basit temsil edilir.

Slayta göre boyut indirgemeyle kısalan süre, artan doğruluk ve sade gösterimin hepsine aynı anda ulaşmak idealdir; ancak çoğu zaman birinde kazanılıp diğerinde kaybedilir ve eldeki uygulamaya göre bunlar arasında denge kurulur (ekrandan, 02:35:00).

### 7.3 Veri indirgeme şeması

Hocanın tahtada çizdiği şema (ekrandan, 02:30:00):

```text
Data Reduction (Veri indirgeme)
├── Feature Reduction (Öz nitelik indirgeme)
│   ├── Feature Selection (Öz nitelik seçimi)
│   │   ├── Supervised (Denetimli)
│   │   └── Unsupervised (Denetimsiz)
│   └── Feature Composition (Öz nitelik birleştirme)
├── Sample Reduction (Örnek indirgeme)
└── Value Reduction (Değer indirgeme)
```

- Öz nitelik seçiminin denetimli tarafında ortalama ve varyans ile yapılan test, denetimsiz tarafında entropi tabanlı öz nitelik sıralaması kullanılır.
- Öz nitelik birleştirme için temel bileşen analizi (PCA) kullanılır; hoca bunun büyük olasılıkla sonraki derste anlatılacağını söyledi.
- Değer indirgemede veri ayrıklaştırma için ChiMerge tekniği verilecektir.

### 7.4 Öz nitelik seçimi ile öz nitelik birleştirme

Öz nitelik seçiminde, örneğin 10 öz nitelikli bir veride öz nitelikler ayırt edicilik güçlerine göre sıralanır, ilk beş ya da altısı seçilir ve kalanlar veri setinden silinir. Başlangıçtaki veri setinden öz niteliklerin bir alt kümesi seçilmiş olur.

Öz nitelik birleştirmede ise veri yeni bir öz nitelik uzayına dönüştürülür. Örneğin veride yaş ve gelir öz nitelikleri varsa, dönüşümden sonra tüm öz nitelikler değişir ve yorumlamak kolay olmaz.

**Soru:** Öz nitelik birleştirmede tüm öz nitelikler mi değişiyor, yoksa seçilen $k$ tanesi mi değiştirilebilir? **Cevap:** Hepsi değişir. Mevcut öz nitelik uzayından başka bir öz nitelik uzayına dönüşüm yapılır. Yeni uzaydaki her eksen önceki öz niteliklerin karmasıdır; örneğin %60 yaş, %40 gelir öz niteliği kullanılarak yeni bir eksen üretilir, başka bir eksende başka öz nitelikler birleştirilir. Öz nitelikler artık eski adlarıyla anılamaz. Bir müşterinin yaşı ya da geliri gibi bilgileri doğrudan görerek yorum yapmak daha kolaydır; birleştirme işleminden sonra bu öz nitelikler kaybedilir. Bu, yöntemin bir dezavantajıdır.

## 8. Ortalama ve Varyans ile Öz Nitelik Seçimi

### 8.1 Test denklemi

Bu yöntem iki sınıflı (A ve B) etiketli veride bir öz niteliğin sınıfları ayırmadaki etkisini ölçer. Test denklemi iki sınıfın ortalamaları arasındaki uzaklığı ölçer ve bunu sınıfların varyanslarına böler:

$$\text{Test} = \frac{|\bar{x}_A - \bar{x}_B|}{SE(X_A - X_B)}, \qquad SE(X_A - X_B) = \sqrt{\frac{\mathrm{var}(X_A)}{n_1} + \frac{\mathrm{var}(X_B)}{n_2}}$$

Burada $n_1$ A sınıfındaki, $n_2$ B sınıfındaki örnek sayısıdır. Test sonuçları bir eşik değeriyle karşılaştırılır.

Sonucun büyük çıkması için kesrin payı (ortalamalar arasındaki açıklık) büyük, paydası (varyanslar) küçük olmalıdır. Dağılımların varyansları büyükse iki sınıfın dağılımları birbiri içine geçer ve o bölgedeki örneklerde A-B ayrımı yapılamaz. Bu yüzden ayırt edicilik kararında varyansı küçük ve ortalamaları arasındaki açıklığı büyük olan, yani test sonucu büyük çıkan öz nitelikler seçilir.

### 8.2 Örnek

Slayttaki "Table 3.1: Dataset with three features" (ekrandan, 02:40:00):

| X | Y | C |
|---|---|---|
| 0.3 | 0.7 | A |
| 0.2 | 0.9 | B |
| 0.6 | 0.6 | A |
| 0.5 | 0.5 | A |
| 0.7 | 0.7 | B |
| 0.4 | 0.9 | B |

İki girdi öz niteliği ($X$, $Y$) ve örnekleri A ve B sınıflarına ayıran ek bir öz nitelik $C$ vardır. $X$ ve $Y$'nin indirgeme adayı olup olmadığına karar verilmesi gerekir; uygulanan testin eşik değeri 0.5'tir.

Hoca sınıfa sorular sordu: veri setinde 6 örnek ve 2 öz nitelik vardır; örneklerin üçü A, üçü B sınıfındadır. Amaç, A ve B sınıfını ayırmada hangi öz niteliğin daha bilgilendirici olduğunu bulmak ve diğerini veriden çıkarmaktır. Örnek bilerek küçük tutulmuştur; gerçek problemlerde 100 gibi çok sayıda öz nitelik olur.

Tahtada veriler sınıflara göre gruplandı (ekrandan, 02:50:00):

- A sınıfı: $X_A = \{0.3, 0.6, 0.5\}$, $Y_A = \{0.7, 0.6, 0.5\}$.
- B sınıfı: $X_B = \{0.2, 0.7, 0.4\}$, $Y_B = \{0.9, 0.7, 0.9\}$.

Her öz nitelik için iki sınıfın dağılımları çizildi:

- $X$ öz niteliğinde A sınıfı 0.3 ile 0.6 arasında, B sınıfı 0.2 ile 0.7 arasında değişir. B'nin dağılımı geniştir ve A'nın dağılımını içine alır; iki dağılım iç içedir. (Tahtada önce A için 0.3-0.5 aralığı yazıldı; bir öğrencinin uyarısıyla 0.3-0.6 olarak düzeltildi.)
- $Y$ öz niteliğinde A sınıfı 0.5 ile 0.7 arasında, B sınıfı 0.7 ile 0.9 arasında değişir. Dağılımlar ayrıktır.

Hoca üç örnekle gerçek bir dağılım çizilemeyeceğini, daha fazla örnek gerektiğini, ama örneğin çözülebilir olması için dağılım varsayıldığını belirtti. Görsel olarak $Y$'nin A'yı B'den ayırmakta daha etkili olduğu bellidir; test bunu sayısal olarak gösterir (ekrandan, 03:00:00).

Slayttaki çözüm (ekrandan, 02:55:00):

- $SE(X_A - X_B) = \sqrt{0.0233/3 + 0.6333/3} = 0.4678$
- $SE(Y_A - Y_B) = \sqrt{0.01/3 + 0.0133/3} = 0.0875$
- $|\bar{X}_A - \bar{X}_B| / SE = |0.4667 - 0.4333| / 0.4678 = 0.0735 < 0.5$
- $|\bar{Y}_A - \bar{Y}_B| / SE = |0.6 - 0.8333| / 0.0875 = 2.6667 > 0.5$

Slayttaki yorum: $X$ indirgeme adayıdır, çünkü ortalamaları birbirine yakındır ve test eşiğin altındadır. $Y$ için test eşiğin belirgin biçimde üstündedir; iki sınıfı ayırt edebilecek bir öz nitelik olduğundan indirgeme adayı değildir. Derste de $X$ yerine $Y$ kullanılmasına karar verildi.

> **Ders sonrası not:** Slaytta $\mathrm{var}(X_B) = 0.6333$ yazılmıştır. $\{0.2, 0.7, 0.4\}$ için örneklem varyansı $0.0633$'tür. Doğru değerle $SE(X_A - X_B) = \sqrt{0.0233/3 + 0.0633/3} \approx 0.170$ ve $X$ için test $\approx 0.0333 / 0.170 \approx 0.196$ olur; yine 0.5'in altında kaldığı için karar değişmez. $Y$ için kesin hesapta $SE \approx 0.0882$ ve test $\approx 2.65$'tir; slayttaki 2.6667, SE'nin 0.0875'e yuvarlanmasından gelir. Değerler python ile doğrulandı.

### 8.3 Eşik mi, sıralama mı

Bu örnekte yalnız iki öz nitelik ve iki test sonucu vardır. 50 gibi çok sayıda öz nitelik olduğunda test sonuçları sıralanıp değerlerine bakılarak hangi kısmın tutulacağına karar verilebilir, ya da sonuçlar bir eşik değeriyle (örnekte 0.5) karşılaştırılabilir.

**Soru:** Slaytta formülden çıkan değerler 0.5 ile karşılaştırılıyor; bu, öz niteliği seçmek için eşik değeri mi? **Cevap:** Evet, iki çeşit çözüm kullanılabilir: sonuçları büyükten küçüğe sıralamak ya da bir eşikle karşılaştırmak. Eşik değerini sonuçları görmeden seçmek kolay değildir. Hocanın tavsiyesi, test sonuçlarını büyükten küçüğe sıralayıp yazmak ve skorun ani düşüş yaptığı (büyük değerlerden birden bire çok küçük değerlere geçtiği) bölgeden kesmektir.

**Soru:** Test formülünde varyanslar neye bölündü? **Cevap:** Her sınıftaki eleman sayısına: $\mathrm{var}_A / n_1$, burada $n_1$ A sınıfındaki örnek sayısıdır; $n_2$ de B sınıfı için aynı anlamdadır.

**Soru:** Bu formülleri uygulayarak hangi öz niteliğin daha ayırt edici olduğunu mu bulduk? **Cevap:** Evet. Her öz nitelik için ayrı inceleme yapıldı; A sınıfı ortalaması ($m_A$) ile B sınıfı ortalaması ($m_B$) arasındaki açıklık ne kadar büyük ve varyanslar ne kadar küçükse öz nitelik A sınıfı örnekleri B sınıfı örneklerden ayırt etmede o kadar etkilidir.

> **Hocanın vurgusu:** Bu analiz uygulamalarda kullanılması tavsiye edilen güzel bir çözümdür, ama sınıf etiketli veri gerektirir. Sınıf etiketi olmayan veriyle yapılamaz; bu yüzden denetimli (supervised) bir tekniktir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:32:44): Yedi örnekten oluşan, sınıf etiketi olmayan iki boyutlu bir veri setinde $s_3$ ve $s_5$ gözle aykırı değer olarak seçildi. Bu karar matematiksel olarak nasıl verilebilir? Veri sınıf etiketli olsaydı ne yapılırdı?

> **Çözüm (derste verilen):** Tüm örneklerin ortalaması alınarak verinin merkez noktası bulunur, her örneğin bu merkeze uzaklığı hesaplanır ve en uzaktaki örnekler aykırı işaretlenir. Sınıf etiketli veride her sınıfın kendi ortalaması bulunur ve örneklerin kendi sınıf merkezine uzaklığına bakılır.

**Soru 2** (derste sözlü, 00:43:03; veri slaytta): Artan sırada verilen 27 değerli yaş verisi (en küçük 13, en büyük 70) için örnek sayısını, ortalamayı, medyanı, $Q_1$ ve $Q_3$'ü bulun; kutu grafiğini çizip aykırı değerleri belirleyin. <!-- BELİRSİZ: yaş değerlerinin tam listesi slayttaydı, o anın karesi yok. -->

> **Çözüm (derste verilen, ekrandan, 00:55:00):** 27 örnek; medyan 14. eleman, $M = 25$; $Q_1 = 20$ (alt 13 elemanın 7.'si), $Q_3 = 35$; $IQR = 15$; $1.5 \times IQR = 22.5$; sınırlar $-2.5$ ve $57.5$. Alt bıyık 13'te kapanır; 70 aykırıdır. Ortalama derste hesaplanmadı; veri listesi karede görünmediği için burada da verilmedi.

**Soru 3** (ekrandan, 01:15:00): $X = \{(2,4), (3,2), (1,1), (4,3), (1,6), (5,3), (4,2)\}$ veri setinde eşik uzaklık 3 ($d \ge 3$) ve komşu olmayan örnek eşiği 4 ($p \ge 4$) iken uzaklık tabanlı teknikle aykırı değerleri bulun.

> **Çözüm (derste verilen):** Öklid uzaklık matrisi kurulur (Bölüm 5.2). Komşu olmayan sayıları: $s_1$: 2, $s_2$: 1, $s_3$: 5, $s_4$: 2, $s_5$: 5, $s_6$: 3, $s_7$: 2. Aykırı değerler $s_3$ ve $s_5$'tir.

**Soru 4** (derste sözlü, 01:43:42; tahta ekrandan, 01:55:00): Aynı veri setinde $m \pm 2s$ eşiğiyle aykırı değerleri bulun.

> **Çözüm (derste verilen):** $x_1$: $m = 2.85$, $s = 1.57$, sınırlar $[-0.29,\ 5.99]$. $x_2$: $m = 3$, $s = 1.63$, sınırlar $[-0.26,\ 6.26]$ (tahtada 6.29). Sınır dışında değer yoktur; bu yöntemle aykırı değer bulunmaz.

**Soru 5** (derste sözlü, 01:58:05): $m \pm 2s$ eşiği uygulandığında örneklerin %20'si aykırı olarak etiketlendi. Aykırı değer miktarını azaltmak için standart sapmanın önündeki katsayı 2 yerine ne seçilmelidir?

> **Çözüm (derste verilen):** Katsayı artırılmalıdır (örneğin 3, gerekirse 3.5). Normal bölge genişler, aykırı bölge küçülür. Aykırı değer oranı normalde yaklaşık %5'tir.

**Soru 6** (ekrandan, 02:40:00): Tablo 3.1'deki veri setinde ($X$, $Y$ girdi öz nitelikleri, $C \in \{A, B\}$ sınıf) eşik 0.5 iken $X$ ve $Y$'nin indirgeme adayı olup olmadığına ortalama-varyans testiyle karar verin.

> **Çözüm (derste verilen, ekrandan, 02:55:00):** $X$ için test $\approx 0.07 < 0.5$, $X$ indirgeme adayıdır. $Y$ için test $\approx 2.67 > 0.5$, $Y$ tutulur. (Slayttaki $\mathrm{var}(X_B)$ yazım hatası düzeltilince $X$ testi $\approx 0.196$ olur; karar aynıdır.)

## Dersin Toparlaması

Bu derste veri ön işlemenin üç konusu işlendi. Zamana bağlı veride seri kayan bir pencereyle girdi-çıktı tablosuna dönüştürüldü; çıktı bir sonraki ya da daha uzak bir değer olabilir ve sayısal çıktı nedeniyle problem regresyonla çözülür. Aykırı değer analizinde üç yöntem karşılaştırıldı: tek değişkenli kutu grafiği ($1.5 \times IQR$ kuralı), örnekler arası Öklid uzaklıklarına dayanan çok değişkenli uzaklık tabanlı yöntem ve tek değişkenli $m \pm 2s$ yöntemi. Aynı veri setinde uzaklık tabanlı yöntem $s_3$ ve $s_5$'i aykırı bulurken $m \pm 2s$ yöntemi hiç aykırı değer bulmadı. Katsayıların uygulamaya göre ayarlanabileceği ve aykırı oranının tipik olarak %5 civarında olduğu vurgulandı.

Son bölümde veri indirgemeye geçildi: indirgeme öz nitelik, örnek ve değer boyutlarında yapılır; öz nitelik indirgeme seçim ve birleştirme olarak ikiye ayrılır. Denetimli öz nitelik seçimi için ortalamalar arası farkı varyanslarla karşılaştıran test bir örnekle uygulandı. Denetimsiz tarafta entropi tabanlı sıralama, öz nitelik birleştirmede PCA ve değer indirgemede ChiMerge, bu bölümün devamında işlenecek konular olarak anıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
