# Ders 3 Genişletilmiş Notu: Zamana Bağlı Veri, Aykırı Değer Analizi ve Veri İndirgemeye Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Geçen Dersin Hatırlatması
- 2. Zamana Bağlı Veri (Time-Dependent Data)
- 3. Aykırı Değer Analizine Giriş
- 4. Yöntem 1: Boxplot Analizi
- 5. Yöntem 2: Mesafeye Dayalı Çözüm
- 6. Yöntem 3: Ortalama Değere Dayalı Çözüm
- 7. Aykırı Değer Analizi Üzerine Tartışma
- 8. Veri İndirgemeye (Data Reduction) Giriş
- 9. Ortalama ve Varyansa Dayalı Öz Nitelik Seçimi
- Örnek Sorular

## 1. Geçen Dersin Hatırlatması

Geçen hafta veri ön işleme (data preprocessing) konusuna başlanmıştı. Ham veri üzerinde dönüşüm işlemleri (transformation of raw data) konuşulmuş; önce normalizasyonun nasıl yapıldığı, ardından veri yumuşatma (data smoothing) ve eksik verinin giderilmesi (missing value elimination) görülmüştü. Bu hafta aynı slayt setinin ("Data Mining: Preparing the Data") kalan iki konusu, zamana bağlı veri ve aykırı değer analizi işlendi. Dersin son bölümünde yeni bir slayt setine, veri indirgemeye geçildi.

## 2. Zamana Bağlı Veri (Time-Dependent Data)

### 2.1 Zaman serisi nedir

Hoca, zaman serilerinin bu dersin ana konusu olmadığını, bu tür verinin başlı başına bir ders olarak anlatılabilecek kadar ayrıntısı olduğunu söyleyerek başladı. Burada amaç yalnızca zamana bağlı verinin veri madenciliği sürecine nasıl hazırlanacağını görmektir.

Zaman serisinde tek bir öz nitelik (single feature) vardır. Bu öz niteliğin değerleri belli zaman aralıklarıyla ölçülür ve bu aralıkların sabit olması gerekir. Slayttaki örnek hava sıcaklığıdır: sıcaklığın her saat, yani birer saat arayla ölçülüp kaydedilmesi zamana bağlı bir veri üretir.

Ölçümler bir küme ya da sayı dizisi olarak yazılır:

$$X = \{t(1), t(2), t(3), \dots, t(n)\}$$

Burada $t(1)$ ilk ölçümü, $t(n)$ ise en yakın zamanda kaydedilmiş değeri (most recent value) gösterir.

### 2.2 Amaç ve pencere (window) kavramı

Slayta göre pek çok zaman serisi probleminde amaç, öz niteliğin önceki değerlerinden $t(n+1)$ değerini tahmin etmektir; önceki değerler tahmin edilecek değerle doğrudan ilişkilidir (ekrandan, 00:15:30). Bu problem "time series problem" olarak adlandırılır.

Ham zamana bağlı verinin ön işlemesindeki en önemli adımlardan biri bir pencere (window) ya da zaman gecikmesi (time lag) belirlemektir. Pencere, tahmini etkileyen önceki değerlerin sayısıdır. Her pencere ileriki analiz için bir örnek (sample) oluşturur (ekrandan, 00:15:30).

### 2.3 Pencere 5 ile örnek üretme

Slayttaki örnekte 11 ölçüm vardır (ekrandan, 00:15:30):

$$X = \{t(0), t(1), t(2), \dots, t(10)\}$$

Pencere boyu 5 alınır ve 6. değer tahmin edilecek değer olacak biçimde veri yeniden düzenlenir. İşlem şöyledir:

- Birinci satırda ilk beş değer $t(0), t(1), t(2), t(3), t(4)$ pencereyi oluşturur. "Next value" sütununa $t(5)$ yazılır.
- Pencere bir adım kaydırılır. İkinci satır $t(1)$'den başlar, $t(1) \dots t(5)$ değerlerini alır ve next value olarak $t(6)$ yazılır.
- Bu kaydırma sürdürülür. Son satır $t(5) \dots t(9)$ girişleri ve $t(10)$ çıkışıdır.

Sonuçta 11 ölçümden, veri madenciliğinde kullandığımız biçimde 6 satırlık, yani 6 örnekli bir tablo elde edilir. Slayt bu tablonun veri madenciliği teknikleri için daha uygun (standartlaştırılmış) bir biçim olduğunu söyler.

Next value değerleri nümerik olduğu için yapılan işlem regresyon gerektirir: nümerik bir çıkış tahmin edilmeye çalışılır. Bu 6 örneğin hepsinin next value değeri bilindiği için bu tablo bir eğitim (train) verisidir. Sonraki aşamada $t(11)$ tahmin edilmek istenirse son pencere $t(6), t(7), t(8), t(9), t(10)$ giriş olarak verilir ve $t(11)$ tahmin edilecek değer olur. Veri böylece veri madenciliği süreci için hazır hâle gelir.

### 2.4 Birkaç adım ilerisini tahmin etmek

Next value her zaman serinin bir sonraki değeri olmak zorunda değildir. Slayta göre bazı uygulamalarda amaç birkaç zaman birimi ilerideki değeri tahmin etmek olabilir. Biçimsel olarak $t(n-i), \dots, t(n)$ değerleri verildiğinde $t(n+j)$ tahmin edilir. Önceki örnekte $j = 3$ alınınca oluşan tablo şudur (ekrandan, 00:18:40):

| Örnek | M1 | M2 | M3 | M4 | M5 | Next Value |
|---|---|---|---|---|---|---|
| 1 | $t(0)$ | $t(1)$ | $t(2)$ | $t(3)$ | $t(4)$ | $t(7)$ |
| 2 | $t(1)$ | $t(2)$ | $t(3)$ | $t(4)$ | $t(5)$ | $t(8)$ |
| 3 | $t(2)$ | $t(3)$ | $t(4)$ | $t(5)$ | $t(6)$ | $t(9)$ |
| 4 | $t(3)$ | $t(4)$ | $t(5)$ | $t(6)$ | $t(7)$ | $t(10)$ |

Slayttaki tablo başlığı "Time-series samples in standard tabular form (window = 5) with postponed predictions (j = 3)" şeklindedir. Aynı 11 ölçümden bu kez 4 örnek çıkar, çünkü son pencerenin çıkışı $t(10)$ olmalıdır.

Hoca bunu günlük bir örnekle açıkladı: son 5 saatin sıcaklık ölçümlerini biliyoruz ama 3 saat sonraki sıcaklığı söylemek istiyoruz. Ya da son 5 günün en yüksek sıcaklıklarını kaydettik ve 3 gün sonraki en yüksek sıcaklığı tahmin etmek istiyoruz.

Slayta göre genel olarak tahmin ne kadar ileriye yapılırsa o kadar zor ve güvenilmez olur (ekrandan, 00:20:00). Hoca da zaman aralığı arttıkça başarının düşeceğini, bir sonraki adımı tahmin etmeye göre hata olasılığının artacağını söyledi.

### 2.5 Zaman serisini sınıflandırma problemine çevirmek

Next value nümerik bir değer yerine kategorik bir değer olarak da planlanabilir. Bu durumda problem bir sınıflandırma (classification) problemine dönüşür. Örneğin sıcaklığın belli değer aralıklarına low, medium, high gibi kategoriler atanabilir ya da daha fazla aralık tanımlanabilir.

Slayttaki örnekte tahmin edilen $t(i+1)$ çıkışı yerine ikili bir sınıf kullanılır (ekrandan, 00:20:00):

- $t(i+1) \geq$ eşik değer ise $T$,
- $t(i+1) <$ eşik değer ise $F$.

Slayta göre veri hazırlama açısından bu değişiklik önemli bir fark yaratmaz.

Hoca, bu temel başlangıç noktası kavrandığında zaman serileriyle çalışmanın çok zor bir problem olmadığını ekledi. Borsadaki hisse senedi fiyatlarının ya da BIST 100 endeksinin yükselişte mi düşüşte mi olacağının tahmini hep zaman serileri üzerinde çalışılır. Yatırım uzmanlarının alım-satım kararları için kullandığı robotlar da bu serilerle çalışır. Hoca bunu ileride çalışmak isteyenler için ilginç bir alan olarak önerdi.

## 3. Aykırı Değer Analizine Giriş

### 3.1 Aykırı değer nedir

Büyük veri setlerinde, verinin kendi karakteristiğine uymayan bazı değerler bulunabilir. Bu değerlere aykırı değer (outlier) denir. Aykırı değerler yanlış ölçme sonucunda oluşabileceği gibi, zaman zaman verinin kendi doğasında da beklenen değerin dışında değerler üretilebilir.

Buradaki amaç şudur:

- Aykırı değer bir ölçme hatasından ya da yanlış yazılmış bir değerden kaynaklanıyorsa veri içinde bulunmamalıdır.
- Aykırı değer verinin kendi doğasında varsa değerlendirilmelidir, çünkü test aşamasında da bu tür değerlerle karşılaşılacak demektir.

Slayttaki örnekler:

- Bir kişinin yaşı veri tabanında $-1$ olarak girilmiş olabilir. Bunun gerçek bir değer olmadığı açıktır; muhtemelen kaydedilmemiş boş bir alanı temsil etmek için kullanılmıştır.
- Bir kişinin çocuk sayısı yanlış kaydedilmiş olabilir: 2 yazılacakken 25 yazılmış olabilir. Bu tür tipografik hatalar aykırı değerin sık nedenlerindendir.

### 3.2 Aykırı değeri bulmak ve kullanmak

Aykırı değer analizinde aykırı değerler otomatik olarak bulunur. Bazı çalışmalarda bulunan aykırı değerler tespit edildikten sonra veriden temizlenir.

Bazı uygulamalarda ise aranan şeyin kendisi aykırı değerdir. Slayttaki örnek kredi kartı işlemlerinde sahteciliktir: veri içinde çok az miktarda da olsa verinin doğasına uymayan hareketleri bulmak başlı başına bir problemdir ve bunu tespit etmek kart kullanımındaki sahteciliği tespit etmek anlamına gelir. Bu yüzden verinin doğasına aykırı değerleri tespit etmek, veri madenciliğinde üzerinde çok çalışılan konulardan biridir.

### 3.3 Boyut sayısı ve görselleştirme

Aykırı değerleri tespit etmek özellikle çok boyutlu veride önemli ve zor bir problemdir. Tek boyutlu veriye göre çok boyutlu veride bu analizi yapmak çok daha güçtür.

Bir alternatif, veriyi görselleştirip (data visualization methods) aykırı değerleri gözle tespit etmektir. Veri bir, iki ya da üç boyutluysa bu bir dereceye kadar mümkündür. Öz nitelik sayısı üçten fazlaysa görselleştirmeyle aykırı değer tespiti pek mümkün görünmez.

Slayttaki örnek iki boyutlu bir veri setidir (ekrandan, 00:30:00). X ve Y eksenlerinin her biri bir öz niteliği temsil eder. Düzlemde 7 örnek ($s_1 \dots s_7$) gösterilmiştir. Birbirine yakın örneklerin oluşturduğu bölge, normal kabul edilen verinin dağılımını gösterir. Bu bölgeden uzaklaştıkça görülen örnekler aykırı değer olarak adlandırılabilir. Şekilde $s_3$ ve $s_5$ genel dağılım bölgesinden uzakta kaldıkları için üzerlerine ok konarak aykırı değer olarak işaretlenmiştir.

**Soru:** X ekseninde bakınca $s_5$ ile $s_3$'ün diğer noktalara uzaklığı yaklaşık bir birim; Y ekseninde de $s_3$'ün $s_2$ ve $s_7$'ye uzaklığı 1, $s_5$'in $s_1$'e uzaklığı 2. Ama bütün noktalarla olan uzaklıklarına birlikte bakınca 3 ve 5 çok uzak çıkıyor. Bu yüzden mi aykırı diyoruz?

**Cevap:** Evet. Hoca bunu şöyle genişletti: bütün örneklerden yararlanarak verinin bir merkez noktası bulunabilir. Bunun için X koordinatlarının ortalaması ve Y koordinatlarının ortalaması alınır. Sonra her örneğin bu merkeze uzaklığına bakılır; merkeze en uzak örnekler aykırı değer sayılabilir. Bu inceleme çok boyutludur (multivariate): her ekseni ayrı ayrı değil, bütün öz nitelikleri bir arada değerlendirir.

Hoca derste aykırı değer tespiti için üç yöntem anlatacağını söyledi: boxplot analizi, mesafeye dayalı çözüm ve ortalama değere dayalı çözüm.

## 4. Yöntem 1: Boxplot Analizi

### 4.1 Çeyrekler ve beş sayılı özet

Boxplot analizinde çeyrekler (quartiles) kullanılır. Hoca baştan şu uyarıyı yaptı: boxplot analizi tek değişkenli (univariate) bir çözümdür, her öz niteliği kendi içinde inceler. Bu bir dezavantaj, bir eksiklik olarak görülebilir.

Slayttaki tanımlar (ekrandan, 00:33:30):

- **Çeyrekler:** $Q_1$ (25. yüzdelik), $Q_3$ (75. yüzdelik).
- **Çeyrekler arası açıklık (inter-quartile range):** $IQR = Q_3 - Q_1$.
- **Beş sayılı özet (five number summary):** min, $Q_1$, $M$ (medyan), $Q_3$, max.
- **Boxplot:** kutunun uçları çeyreklerdir, medyan işaretlenir, bıyıklar (whiskers) çizilir ve aykırı değerler tek tek gösterilir.
- **Aykırı değer:** genellikle $1.5 \times IQR$'den daha yüksek ya da daha düşük olan değer.
- Aykırı olduğundan şüphelenilen değerleri bulmak için yaygın kural, üçüncü çeyreğin en az $1.5 \times IQR$ üstünde ya da birinci çeyreğin en az $1.5 \times IQR$ altında kalan değerleri ayırmaktır.

Yani önce veri sıraya dizilir, minimum ve maksimum bulunur. Sıralı dizide $Q_1$ yaklaşık %25'teki, $Q_3$ yaklaşık %75'teki elemandır. $Q_1$'den aşağı ve $Q_3$'ten yukarı $1.5 \times IQR$ kadar gidilerek normal kabul edilebilir bölge tanımlanır; bunun dışındaki değerler aykırı olarak işaretlenir. Hoca katsayının uygulamaya ve verinin türüne göre değiştirilebileceğini, derste 1.5 kullanılacağını söyledi.

Boxplot çiziminde ortadaki çizgi medyanı, kutunun alt kenarı $Q_1$'i, üst kenarı $Q_3$'ü gösterir.

### 4.2 Boxplot örneği: yaş öz niteliği

Slayttaki örnek (ekrandan, 00:40:00): Analiz edilecek veride yaş öz niteliği vardır ve yaş değerleri artan sırayla şöyledir:

13, 15, 16, 16, 19, 20, 20, 21, 22, 22, 25, 25, 25, 25, 30, 33, 33, 35, 35, 35, 35, 36, 40, 45, 46, 52, 70

Sorular: (a) ortalama nedir, (b) medyan nedir, (c) $Q_1$ ve $Q_3$ nedir, (d) boxplot çizin.

**Örnek sayısı.** Derste önce kaç örnek olduğu soruldu: 27 örnek vardır.

**(a) Ortalama.** 27 değer toplanıp 27'ye bölünür. Toplam 809'dur (ara adım eklendi), ortalama $809 / 27 \approx 29.96$ olur. Derste bu değer öğrenci tarafından 29.96 olarak verildi.

**(b) Medyan.** Eleman sayısı tek (27) olduğu için medyan ortadaki, yani 14. elemandır. Sayarak 14. elemanın 25 olduğu görülür: $M = 25$.

**(c) Çeyrekler.** Dizi medyana göre iki parçaya bölünür. Medyanın her iki yanında 13'er eleman kalır. 13 elemanlı bir dizinin ortası 7. elemandır:

- Alt yarının 7. elemanı: $Q_1 = 20$.
- Üst yarının 7. elemanı: $Q_3 = 35$.

**(d) Boxplot çizimi** (ekrandan, 00:50:00):

- $IQR = Q_3 - Q_1 = 35 - 20 = 15$.
- $1.5 \times IQR = 22.5$.
- Alt sınır: $Q_1 - 22.5 = 20 - 22.5 = -2.5$. Verideki en küçük değer 13'tür ve bu sınırın içindedir. $-2.5$'e kadar olan bölgenin tamamı normal kabul edilirdi, ama veri zaten 13'te bitiyor. Bu yüzden alt bıyık 13'te (min = 13) kapalı çizilir. Kapalı uç, bunun altında başka değer olmadığını, alt bölgede aykırı değer bulunmadığını gösterir.
- Üst sınır: $Q_3 + 22.5 = 35 + 22.5 = 57.5$. Bu değerin üstünde bir değer vardır: maksimum değer 70. Bu yüzden üst uç kapatılmaz, açık bırakılır; 70 ayrıca işaretlenir ve "1 outlier detected" yazılır.

Sonuç: Bu veride tek bir aykırı değer vardır, o da 70'tir.

> **Hocanın vurgusu:** Boxplot çizerken bıyık uçlarının ne zaman kapalı, ne zaman açık çizildiğine dikkat edin. Kabul edilebilir aralığın dışında değer yoksa uç kapatılır; dışarıda değer varsa uç açık bırakılır ve aykırı değer ayrıca gösterilir.

> **Ek bilgi (derste anlatılmadı):** Yaygın boxplot çizim geleneğinde bıyık, sınırın kendisine değil, sınırın içinde kalan en uç veri değerine kadar çizilir. Bu örnekte üst bıyık büyük olasılıkla $57.5$'e değil, sınırın altındaki en büyük değer olan 52'ye kadar uzanır; 70 ise ayrı bir nokta olarak gösterilir. Aykırı değerin hangisi olduğu sonucu her iki çizimde de aynıdır.

### 4.3 Katsayının seçimi üzerine sorular

**Soru:** Aykırı değeri attıktan sonra ortalama, medyan ve çeyrekleri baştan yeniden hesaplıyor muyuz?

**Cevap:** Hayır, tekrar yapmaya gerek yok. Ancak katsayı üzerinde düşünmek gerekir. Diyelim ki $1.5 \times IQR$ ile çalıştınız ve verinin neredeyse %25'i aykırı çıktı. Verinin %25'ini atmak çok büyük bir veri kaybıdır. Bu durumda katsayıyı 2 alıp daha geniş bir aralığı kabul edilebilir saymak düşünülebilir. Tersi de olabilir: hiç aykırı değer çıkmadı ama veride belirgin düzensizlikler var. O zaman katsayı 1 alınabilir. Katsayı 1, 1.5 ya da 2 gibi değerlerle ihtiyaca göre değiştirilir; değiştirildiğinde sonuca bakılıp karar verilir.

**Soru:** Katsayının veri setine göre optimizasyonu için bir şey yapılmıyor mu?

**Cevap:** Bunun için denemek gerekir. Örneğin 1.5 seçince kaç aykırı değer tespit edildiğine, yani miktarına bakılır. Hoca kendi çalışmalarında aykırı değer miktarının en fazla yaklaşık %5 olabileceğini söylediğini belirtti. %5'ten fazla veriyi atmak çok büyük bir kayıptır ve bunlar aykırı değer kabul edilmemelidir. Nerede durulacağına karar vermek analizi yapana kalır ve bu, eldeki verinin miktarıyla da ilişkilidir: örnek sayısı azsa çok fazla veri kaybetmek istenmez.

Aynı öğrenci kümelemeyle çalışan "local outlier factor" yönteminin daha düşük bir oranla aykırı değer çıkardığını, boxplot'un ise yüksek oranla çıkardığını söyledi. Hoca burada da belirleyici olanın katsayı olduğunu, katsayıyı değiştirerek aykırı değer miktarının değiştirilebileceğini söyledi. İdeal oran sorulduğunda hoca, bunu normal dağılım gibi düşünmeyi önerdi: kabul edilen aralığın dışında kalan kısım %5 kadar, hatta daha azdır; dolayısıyla aykırı denebilecek en fazla miktar %5'tir.

> **Hocanın vurgusu:** Aykırı değer oranı en fazla yaklaşık %5 olmalıdır. Daha fazlasını atmak veri kaybı demektir.

> **Ek bilgi (derste anlatılmadı):** Local Outlier Factor (LOF), bir örneğin yerel yoğunluğunu komşularının yerel yoğunluğuyla karşılaştıran, yoğunluğa dayalı bir aykırı değer yöntemidir. Komşularına göre belirgin biçimde seyrek bir bölgede kalan örnek yüksek bir LOF skoru alır. Boxplot'tan farklı olarak bütün öz nitelikleri birlikte kullanır, yani çok değişkenlidir.

## 5. Yöntem 2: Mesafeye Dayalı Çözüm

### 5.1 Problem ve yöntem

İkinci yöntem mesafeye dayalı (distance-based) çözümdür ve slaytta çok değişkenli çözüm (multi-variate solution) olarak geçer. Hoca, merkez noktasına uzaklık fikrinin de bir mesafe çözümü olduğunu, burada ise mesafenin farklı bir biçimde kullanıldığını belirtti.

Slayttaki problem (ekrandan, 01:12:30): İki boyutlu örneklerden oluşan veri seti

$$X = \{(2,3), (3,2), (1,1), (4,3), (1,6), (5,3), (4,2)\}$$

(a) Aykırı değerleri mesafeye dayalı teknikle bulun. Eşik mesafesi 3'tür ($d \geq 3$) ve komşu olmayan örnekler için eşik sayısı $p$ 4'tür ($p \geq 4$).

İpucu: Bir $x_i$ örneği, uzaydaki örneklerin en az $p$ kadarı ondan $d$'den daha büyük bir mesafedeyse aykırı değerdir.

Yöntemin iki parametresi vardır:

- **Eşik mesafesi $d$:** Önce her örneğin diğer örneklere uzaklığı ölçülür. İki örnek arasındaki uzaklık eşiğe eşit ya da büyükse bu örnekler birbirinin komşusu değildir (non-neighbor samples). Yakında olanlara komşu, uzakta olanlara komşu değil etiketi verilir.
- **Eşik sayısı $p$:** Bir örneğin komşu olmayan örneklerinin sayısı 4 ya da daha fazlaysa bu örnek aykırı değer olarak adlandırılır.

Hoca, verilen değerleri okurken birinci örneği yanlış yazdığını söyleyip düzeltti: birinci örnek $(2,4)$ olacak. Slayttaki şekilde de $s_1$ bu noktadadır (ekrandan, 00:30:00). Çözümde kullanılan örnekler:

| Örnek | $x$ | $y$ |
|---|---|---|
| $s_1$ | 2 | 4 |
| $s_2$ | 3 | 2 |
| $s_3$ | 1 | 1 |
| $s_4$ | 4 | 3 |
| $s_5$ | 1 | 6 |
| $s_6$ | 5 | 3 |
| $s_7$ | 4 | 2 |

<!-- BELİRSİZ: Slayt metninde birinci örnek (2,3) yazıyor (ekrandan, 01:12:30); hoca bunu (2,4) olarak düzeltti ve çözümü (2,4) ile yaptı. Kitaptaki asıl değerin hangisi olduğu derste netleşmedi. -->

Örnekler önce koordinat düzlemine yerleştirildi. Birinci öz nitelik en fazla 5, ikinci öz nitelik en fazla 6 değerini alır.

### 5.2 Öklid mesafesi

İki örnek arasındaki mesafe Öklid mesafesiyle hesaplanır. Düzlemde iki nokta arasındaki uzaklık, iki noktayı birleştiren dik üçgenin dik kenarlarının kareleri toplamının karekökü olarak bulunur (ekrandan, 01:20:00):

$$d(s_i, s_j) = \sqrt{\Delta x^2 + \Delta y^2}$$

Örneğin $s_1 = (2,4)$ ile $s_2 = (3,2)$ arasında $\Delta x = 1$, $\Delta y = 2$, kareler toplamı $1 + 4 = 5$, mesafe $\sqrt{5}$'tir.

**Soru:** Öklid yerine Manhattan gibi başka bir mesafe kullansak daha hızlı ilerlemez miyiz?

**Cevap:** Kullanılabilir, ama Öklid en çok kullanılan mesafe olduğu için ilk öğrenilen o olsun diye örnek Öklid ile çözüldü.

### 5.3 Mesafe matrisi

Örneklerin birbirine uzaklıklarını gösteren bir mesafe matrisi $D$ (distance between samples) kurulur. 7 örnek olduğu için matris $7 \times 7$'dir. Ana köşegen her örneğin kendisine uzaklığıdır ve sıfırdır. Matris simetriktir; bu yüzden yalnız üst üçgeni hesaplamak yeterlidir. Örneğin 2'nin 1'e uzaklığı, 1'in 2'ye uzaklığıyla aynıdır.

Değerler derste öğrencilerle birlikte satır satır hesaplandı. Tahtadaki matris (ekrandan, 01:30:00):

```text
      s1   s2    s3    s4    s5    s6    s7
s1    0   √5   √10    √5    √5   √10    √8
s2         0    √5    √2   √20    √5     1
s3               0   √13     5   √20   √10
s4                     0   √18     1     1
s5                           0     5     5
s6                                 0    √2
s7                                       0
```

Örnek hesaplar (ara adım eklendi):

- $d(s_1, s_3)$: $(2,4)$ ile $(1,1)$; $1^2 + 3^2 = 10 \Rightarrow \sqrt{10}$.
- $d(s_3, s_5)$: $(1,1)$ ile $(1,6)$; $0^2 + 5^2 = 25 \Rightarrow 5$.
- $d(s_5, s_6)$: $(1,6)$ ile $(5,3)$; $4^2 + 3^2 = 25 \Rightarrow 5$.
- $d(s_4, s_5)$: $(4,3)$ ile $(1,6)$; $3^2 + 3^2 = 18 \Rightarrow \sqrt{18}$.

Bütün matris python ile kontrol edildi; tahtadaki değerlerle aynıdır.

> **Ders sonrası not:** Altyazıda $s_6$ ile $s_7$ arasındaki uzaklık "2" olarak geçiyor; tahtada doğru biçimde $\sqrt{2}$ yazılmıştır ($(5,3)$ ile $(4,2)$ arasında $1^2 + 1^2 = 2$).

### 5.4 Komşu olmayanları saymak

Her satırda mesafesi 3 ya da daha büyük olan, yani komşu olmayan örnekler sayılır. Satırın boş kalan sol tarafı simetriden okunur (tahtada sütun boyunca yeşil ve sarıyla işaretlendi). $\sqrt{8} \approx 2.83$ eşiğin altında, $\sqrt{10} \approx 3.16$ eşiğin üstündedir (ara adım eklendi).

| Örnek | $d \geq 3$ olan örnekler | $p$ | Aykırı mı ($p \geq 4$) |
|---|---|---|---|
| $s_1$ | $s_3$, $s_6$ | 2 | Hayır |
| $s_2$ | $s_5$ | 1 | Hayır |
| $s_3$ | $s_1$, $s_4$, $s_5$, $s_6$, $s_7$ | 5 | Evet |
| $s_4$ | $s_3$, $s_5$ | 2 | Hayır |
| $s_5$ | $s_2$, $s_3$, $s_4$, $s_6$, $s_7$ | 5 | Evet |
| $s_6$ | $s_1$, $s_3$, $s_5$ | 3 | Hayır |
| $s_7$ | $s_3$, $s_5$ | 2 | Hayır |

Hoca $p$ değerinin anlamını şöyle açıkladı: elde 7 örnek var. Bunların 5'i bir örneğin uzak komşusuysa, o örneğin yakınında çok az örnek var demektir. Tahtaya "$S_3$ is an outlier!" yazıldı.

Sonuç: Bu yöntemle iki aykırı değer bulunur: $s_3$ ve $s_5$.

> **Ders sonrası not:** Hoca sonucu toparlarken "3 ve 7. örneklerin birer aykırı değer olduğunu söyledik" dedi (01:31:44). Doğrusu, kendi saydığı $p$ değerlerine göre de $s_3$ ve $s_5$'tir; $s_7$ için $p = 2$'dir.

Bu çözüm çok değişkenlidir: her örneğin bütün boyutları, burada iki boyutu, mesafe hesabına katılmıştır.

## 6. Yöntem 3: Ortalama Değere Dayalı Çözüm

### 6.1 Problem

Slayttaki (b) şıkkı aynı veri seti üzerindedir (ekrandan, 01:34:00): "Her boyut için ayrı ayrı ortalama ve varyansa dayalı aykırı değer tespitinin işlemlerini anlatın ve sonuçlarını yorumlayın." İpucu: Eşik = Ortalama $\pm$ (2 $\times$ Standart Sapma). Slaytta bu çözüm "Solution by mean value (Uni-variate solution)" olarak geçer.

Değerler ortalama $\pm$ 2 standart sapma aralığının içindeyse normal kabul edilir; dışındaysa aykırı değer olarak işaretlenir. Bunun için iki boyutlu veri setinin her öz niteliğinin ortalaması ve standart sapması ayrı ayrı bulunur.

### 6.2 Ortalama ve standart sapma

Tahtadaki tablo (ekrandan, 01:40:00):

| Örnek | $x_1$ | $x_2$ |
|---|---|---|
| $s_1$ | 2 | 4 |
| $s_2$ | 3 | 2 |
| $s_3$ | 1 | 1 |
| $s_4$ | 4 | 3 |
| $s_5$ | 1 | 6 |
| $s_6$ | 5 | 3 |
| $s_7$ | 4 | 2 |

Sütun doğrultusunda ortalamalar:

- $m_1 = 20/7 \approx 2.857$; tahtada $m_1 = 2.85$ yazıldı.
- $m_2 = 21/7 = 3$.

Standart sapma geçen hafta konuşulmuştu. Her $x_i$'nin ortalamadan farkının karesi toplanır ve $n - 1$'e bölünür; 7 örnek olduğu için 6'ya bölünür, sonra karekök alınır:

$$s_1 = \sqrt{\frac{\sum_{i=1}^{7}(x_i - m)^2}{6}}$$

Sonuçlar: $s_1 \approx 1.57$, $s_2 \approx 1.63$ (python ile doğrulandı: 1.5736 ve 1.6330).

### 6.3 Sınırlar ve yorum

Hoca bunu bir normal dağılım gibi düşünmeyi önerdi: ortalaması $m$ olan ve $s$ kadar sapma gösteren bir dağılımda $-2\sigma$ ile $+2\sigma$ arasındaki bölge normal kabul edilebilir aralıktır, bunun dışı aykırıdır.

$x_1$ için:

- Alt sınır: $m_1 - 2 s_1 = 2.85 - 2 \times 1.57 = -0.29$.
- Üst sınır: $m_1 + 2 s_1 = 2.85 + 2 \times 1.57 = 5.99$.

$x_1$'in $-0.29$'dan küçük ya da $5.99$'dan büyük bir değeri yoktur. Bu öz nitelikte sapma görülmez.

$x_2$ için:

- Alt sınır: $3 - 2 \times 1.63 = -0.26$.
- Üst sınır: $3 + 2 \times 1.63 = 6.26$.

$x_2$'nin de bu sınırların dışında değeri yoktur. Sonuç: bu yöntemle veri setinde aykırı değer yoktur (no outlier).

Kesin değerlerle üst sınır $x_1$ için $6.004$ çıkar; tahtadaki $5.99$ yuvarlanmış ara değerlerden gelir ve sonuç değişmez.

Daha hassas bir araştırma isteniyorsa 2 yerine 1.5 katsayısı kullanılabilir. Bu, dağılımı daha içeriden keser ve dışarıda kalan bölge büyür. Uygulamada katsayı bazen 2, bazen 3 alınır, duruma göre daha küçük de seçilebilir. Bu da deneyerek karar verilecek bir konudur.

Dikkat edilirse aynı veri setinde mesafeye dayalı yöntem iki aykırı değer ($s_3$ ve $s_5$) bulurken, her boyutu ayrı inceleyen bu yöntem hiç aykırı değer bulmamıştır.

## 7. Aykırı Değer Analizi Üzerine Tartışma

### 7.1 Sınıf etiketli veride çok değişkenli çözüm

Hoca öğrencilere şu soruyu sordu: Her öz niteliği ayrı ayrı değerlendiren tek değişkenli çözüm yerine çok değişkenli bir çözüm isteniyor. Veri setinde bir de sınıf etiketi olduğu varsayılıyor. Nasıl bir çözüm bulunur?

Gelen öneriler ve hocanın yorumları:

- **Her sınıf için ayrı ayrı ortalama $\pm$ 2 standart sapma uygulamak.** Hoca bunun hâlâ tek değişkenli bir çözüm olduğunu, her öz niteliği ayrı incelediğini hatırlattı ve mesafeye dayalı bir çözüm düşünülmesini istedi.
- **Temel bileşen analizi (PCA) kullanmak.** Hoca PCA'nın sınıf etiketine ihtiyaç duymadığını, ayrıca aykırı değer bulmak için değil daha çok öz nitelik azaltmak için kullanılan bir teknik olduğunu söyledi. Sınıf bilgisi bu durumda yok sayılmış olur.
- **Sınıf bazında mesafe hesaplayıp sınıf içindeki aykırı değerleri bulmak.** Hoca planlanan çözümün bu olduğunu söyledi.

Hocanın tarif ettiği çözüm: Düzlemdeki noktalardan soldaki üç örnek hasta grubu, sağdaki dört örnek sağlıklı grubu temsil etsin. Dersin başında konuşulduğu gibi her sınıfın sınıf içi ortalaması alınır; böylece her sınıfı temsil eden bir merkez noktası bulunur. Örneklerin birbirine uzaklığını hesaplamak yerine, her örneğin kendi sınıf merkezine uzaklığına bakılır. Merkeze en uzak olan bir iki örnek, yine bir mesafe eşiği üzerinden aykırı değer olarak adlandırılabilir.

Bir öğrenci bunun aslında aykırılığı sınıfa göre "lokalleştirmek" olduğunu söyledi; hoca sınıf için bu yorumun doğru olduğunu kabul etti. Sınıf etiketi olmasaydı bütün veri için tek bir ortalama hesaplanıp aynı yol izlenebilirdi.

**Soru:** Kümedeki bütün değerler aykırı çıkarsa ne olur?

**Cevap:** O zaman verinin tamamı çöp demektir; böyle bir şey olamaz.

> **Hocanın vurgusu:** Öz nitelikleri bir arada kullanan mesafe tabanlı çözümler daha doğrudur. Yine de tek değişkenli çözümler (boxplot, ortalama ve varyansa dayalı çözüm) de kullanılır.

### 7.2 Hibrit çözüm

**Soru:** İki yöntemi birlikte kullanan hibrit bir çözüm yapılabilir mi? Örneğin hem uzaklığa hem diğer yönteme bakmak.

**Cevap:** Hoca bunu kesişim kümesine bakmak olarak yorumladı ve mantıklı buldu: birden fazla çözümü bir arada kullanıp ortak sonuca göre karar verilebilir.

### 7.3 Tek değişkenli yöntemde bütün örnek silinir

Hoca şuna dikkat çekti: ortalama ve varyansa dayalı çözümde $s_5$'in $x_2$ değeri 6 değil de 6.90 gibi bir değer olsaydı, yalnızca $x_2$ öz niteliği sınırın dışında kaldığı için bu örneğin tamamı silinmek zorunda kalınırdı. Tek değişkenli analizde (boxplot ya da ortalama ve varyans) boyutlardan biri için bir değer sınırın dışında yakalanırsa ilgili örneğin tamamı veri setinden çıkarılır. Aykırı değer eleme (elimination of outlier) böyle işler: aykırılık tek bir boyutta tespit edilir ama örnek bütünüyle kaldırılır.

**Soru:** Aykırı değerleri çıkardıktan sonra parametreleri yeniden hesaplayıp bir daha aykırı değer arasak başka noktalar aykırı görünebilir mi?

**Cevap:** Bu, veriyi gitgide aşındırır ve sürekli veri kaybedilir. Hangi aralığın normal kabul edileceğine, eşik değerinin ne olacağına başta gelen veri üzerinden bir kez karar verilir.

## 8. Veri İndirgemeye (Data Reduction) Giriş

### 8.1 Bölümün hedefleri

Aradan sonra yeni bir slayt setine, "Data Mining: Data Reduction" başlıklı bölüme geçildi. Slayttaki bölüm hedefleri (Chapter Objectives) şunlardır (ekrandan, 02:05:00):

- Öz nitelikler, örnekler (cases) ve değerlerin indirgenmesi tekniklerine göre boyutluluk farkını tanımlamak.
- Veri madenciliği sürecinin ön işleme aşamasında veri indirgemenin avantajlarını açıklamak.
- Öz nitelik seçimi (feature selection) ve öz nitelik birleştirme (feature composition) görevlerinin temel ilkelerini ilgili istatistiksel yöntemlerle anlamak.
- Öz nitelik sıralaması için entropiye dayalı tekniği ve temel bileşen analizini (PCA) uygulamak ve karşılaştırmak.
- Ayrık değerlerin indirgenmesi için ChiMerge ve bin tabanlı tekniklerin temel ilkelerini anlamak ve uygulamak.
- İndirgemenin artımlı (incremental) ve ortalama örneklere dayandığı durumlardaki yaklaşımları ayırt etmek.

### 8.2 Öz nitelik çıkarma (feature extraction)

Hoca bu kavramı ayrıca açıkladı ve sohbet bölümüne yazdı. Veri tabanından çekilen her parametre elbette bir öz nitelik olabilir; ama bunlardan türetilmiş yeni öz nitelikler de oluşturulabilir. Buna öz nitelik çıkarma (feature extraction) denir.

Hocanın örneği bireysel emeklilikle ilgiliydi. Bireysel emeklilik yatırımı yapan kişilerin aylık ödemeleri, birikimleri gibi pek çok değer veri tabanında tutulur. Sistemden ayrılma ihtimali olan kişileri önceden tespit etmek için şöyle bir öz nitelik eklendi: kişinin birikiminin aylık kazancı ile diğer yatırım araçlarının (örneğin altın, döviz) aylık kazancı arasındaki fark. Bu, kişinin "kârda mıyım, zararda mıyım" diye kendi yatırımını kontrol etmesine benzer. Her kişinin yatırım portföyü farklı olabileceği için bu karşılaştırmanın ayrılma kararına etkisi incelenebilir.

Slaytta da daha önce görülen beden kitle indeksi (body mass index) örneği tekrar verilmiştir: boy ve kilo varsa bunlardan yeni bir öz nitelik üretilip veri setine eklenebilir ve bu, önceki iki öz nitelikten daha iyi bir gösterge olabilir.

### 8.3 Öz nitelik indirgeme ve verinin üç boyutu

Bazen öz nitelik sayısı 3, 5, 10, 20 değil, her örnek için 100, 200, hatta 250 olabilir. Doğal dil işlemede bu sayı binlere çıkar. Bu durumda öz nitelik indirgeme (feature reduction) ya da öz nitelik seçimi (feature selection) yöntemlerine ihtiyaç duyulur. Hoca, öz nitelik çıkarmanın ayrı, öz nitelik indirgeme ve seçiminin ayrı şeyler olduğunu vurguladı.

Slayta göre pratikte öz nitelik sayısı birkaç yüze çıkabilir. Analiz için yalnızca birkaç yüz örnek varsa, güvenilir ya da pratikte kullanılabilir bir model çıkarmak için boyut indirgeme gerekir. Ayrıca yüksek boyutluluk yüzünden oluşan veri yükü bazı algoritmaları uygulanamaz hâle getirebilir; tek çözüm yine veri boyutlarını azaltmaktır (ekrandan, 02:10:00).

Düz dosya (flat file) biçimindeki ön işlenmiş veri setlerinin üç ana boyutu vardır (ekrandan, 02:10:00):

- **Sütunlar (öz nitelikler):** Öz nitelik sayısı çok fazlaysa sütun sayısı azaltılır. Yalnızca değerli, anlamlı olan veri sette kalmalıdır.
- **Satırlar (örnekler, cases):** Örnek indirgeme (sample reduction) ile satır sayısı azaltılabilir.
- **Öz nitelik değerleri:** Matristeki değerlerin indirgenmesi. Burada veri ayrıklaştırma (data discretization) teknikleri devreye girer.

### 8.4 Veri indirgemenin avantajları

- **Hesaplama süresi (computing time):** Veri sadeleşir ve yalnız gerçekten gerekli alanlar kalırsa hesaplama süresinden kazanılır. Gereksiz öz nitelikler işlemi uzatır.
- **Tahmin ve betimleme doğruluğu (predictive and descriptive accuracy):** Gereksiz alanların atılması bazen tahmin başarısını artırır; gereksiz veri sonucun doğruluğunu olumsuz etkileyebilir. Hoca bunun her zaman böyle olmadığını, ama olduğu durumlar bulunduğunu söyledi.
- **Temsil ve görselleştirme:** Öz nitelik sayısı ne kadar azsa veriyi temsil etmek ve görselleştirme yöntemlerini uygulamak o kadar kolaylaşır.

Bu yüzden veri indirgeme, veri madenciliği süreçlerine başlamadan önce mutlaka ele alınması gereken bir adımdır.

### 8.5 Veri indirgeme yöntemlerinin şeması

Hoca bölümün yapısını bir ağaç olarak çizdi (ekrandan, 02:20:00):

```text
Data Reduction
├── Feature Reduction
│   ├── Feature Selection
│   │   ├── Supervised Feature Selection   (sınıf içi ortalama ve varyansa dayalı)
│   │   └── Unsupervised Feature Selection (entropiye dayalı)
│   └── Feature Composition                (PCA - Principal Component Analysis)
├── Sample Reduction                       (derste yöntem verilmedi)
└── Value Reduction                        (ChiMerge ile veri ayrıklaştırma)
```

- **Feature selection**, mevcut öz niteliklerden hangilerinin daha değerli olduğunu ve sınıfları ayırt etmede etkili olduğunu belirleyip seçmeyi sağlar. İşe yaramayan öz nitelikler veri setinden silinir.
  - Eğiticili (supervised) öz nitelik seçiminde sınıf bilgisi vardır. Her sınıf için sınıf içi ortalama ve varyans hesaplanarak öz nitelikler karşılaştırılır ve hangisinin sınıfları ayırt etmede daha etkin olduğuna karar verilir.
  - Eğiticisiz (unsupervised) teknikte entropiye dayalı bir yöntem anlatılacak.
- **Feature composition**, öz nitelikleri birleştirerek yeni bir öz nitelik uzayı yaratır. Bu yeni uzayda etkin öz nitelikleri belirlemek daha kolaydır. Burada PCA kullanılacak.
- **Sample reduction** pek uygulanan bir yöntem değildir. Veri setlerinde genelde az sayıda örnek olduğu için örnek atma yoluna çoğunlukla gidilmez; bu yüzden derste bunun için yöntem verilmedi.
- **Value reduction** için ChiMerge tekniği, veri ayrıklaştırma yöntemi olarak verilecek.

En çok başvurulan yöntemler öz nitelik indirgeme yöntemleridir.

**Soru:** Value derken doğrudan tablonun içindeki değerler mi kastediliyor?

**Cevap:** Evet, değerlerin doğrudan indirgenmesi. Bu, veri yumuşatmada (data smoothing) görülen fikre benzer: veri setinde birbirinden farklı çok sayıda değer (many distinct values) olması istenmez. Bunun yerine belli sayı aralıklarını temsil eden tek bir değer olsun istenir. Bu açıdan bakınca bu da bir indirgeme işlemidir.

## 9. Ortalama ve Varyansa Dayalı Öz Nitelik Seçimi

### 9.1 Fikir

Öz nitelik azaltırken ilk başvurulacak yöntemler öz nitelik seçimi yöntemleridir; ilk yöntem eğiticilidir. Veri setinde başlangıçta sınıf etiketlerinin verildiği varsayılır. Sınıf içi ortalama ve varyans hesaplanarak her öz niteliğin sınıfları ayırt etmedeki etkinliği belirlenir.

A ve B sınıf etiketleri olsun. Her öz nitelik için A sınıfı örneklerin ve B sınıfı örneklerin ortalaması alınır. A'nın sınıf içi ortalaması ile B'nin sınıf içi ortalaması birbirinden ne kadar uzaksa, o öz nitelik veriyi ayırt etmede o kadar etkindir.

Ama yalnızca ortalamalar arasındaki açıklığın büyük olması yetmez; sınıfların dağılımına da bakmak gerekir. Bir sınıfın standart sapması çok büyükse, o öz nitelik için sınıfların verisi birbirinin içine geçmiş demektir.

### 9.2 Test eşitliği

Slayttaki test (ekrandan, 02:23:10): A ve B, iki farklı sınıf için ölçülen öz nitelik değerlerinin kümeleri, $n_1$ ve $n_2$ ise karşılık gelen örnek sayılarıdır.

$$SE(A - B) = \sqrt{\frac{\mathrm{var}(A)}{n_1} + \frac{\mathrm{var}(B)}{n_2}}$$

$$\text{TEST:}\quad \frac{|\mathrm{mean}(A) - \mathrm{mean}(B)|}{SE(A - B)} > \text{eşik değer}$$

Pay, ortalamalar arasındaki uzaklıktır. Payda, her sınıfın varyansının kendi örnek sayısına oranlarının toplamının kareköküdür. Test sonucu ne kadar büyükse öz nitelik o kadar değerlidir. "Büyük" göreli bir kavram olduğu için bir eşik değer tanımlanabilir: test eşikten büyükse öz nitelik değerlidir.

> **Ek bilgi (derste anlatılmadı):** Bu test istatistiği, iki grup ortalamasını varyansları eşit saymadan karşılaştıran Welch t istatistiğiyle aynı biçimdedir. Pay iki ortalamanın farkı, payda bu farkın standart hatasıdır (SE, standard error). Bu yüzden test, farkın kendi belirsizliğine göre ne kadar büyük olduğunu ölçer.

**Soru:** Değerleri büyükten küçüğe sıralayıp ilk onu alabilir miyiz?

**Cevap:** Kesinlikle. Ya da şöyle yapılabilir: test skorları büyükten küçüğe sıralanır ve bir yerde değerler birdenbire çok küçük bir değere atlar. O noktadan kesilip altındaki öz nitelikler hiç kullanılmayabilir.

### 9.3 Örnek: X ve Y öz nitelikleri

Slayttaki veri (Table 3.1: Dataset with three features) (ekrandan, 02:25:10):

| X | Y | C |
|---|---|---|
| 0.3 | 0.7 | A |
| 0.2 | 0.9 | B |
| 0.6 | 0.6 | A |
| 0.5 | 0.5 | A |
| 0.7 | 0.7 | B |
| 0.4 | 0.9 | B |

Slayttaki açıklama: İki giriş öz niteliği X ve Y ile örnekleri A ve B sınıflarına ayıran ek bir C öz niteliği vardır. X ve Y'nin indirgeme adayı olup olmadığına karar verilmelidir. Uygulanan testin eşik değeri 0.5'tir.

Altı örnekten üçü A, üçü B sınıfındadır. Önce örnekler sınıflarına göre gruplanır (ekrandan, 02:30:00):

- A sınıfı: $(0.3, 0.7)$, $(0.6, 0.6)$, $(0.5, 0.5)$.
- B sınıfı: $(0.2, 0.9)$, $(0.7, 0.7)$, $(0.4, 0.9)$.

**X öz niteliği.** A sınıfında X değerleri 0.3 ile 0.6 arasındadır, ortalama $\approx 0.4667$. B sınıfında ortalama $\approx 0.4333$'tür. Ortalamalar birbirine çok yakındır. Ayrıca B sınıfının değerleri 0.2 ile 0.7 arasına yayılır, varyansı çok daha büyüktür. Hoca çizdiği dağılımlarda A ve B'nin X ekseninde birbirinin içine geçtiğini gösterdi.

**Y öz niteliği.** A sınıfında Y değerleri 0.5 ile 0.7 arasındadır, ortalama 0.6. B sınıfında ortalama $\approx 0.8333$'tür ve değişim aralığı dardır. Ortalamalar birbirinden uzak, varyanslar küçüktür; dağılımlar iç içe geçmez.

Testin sonucunun büyük çıkması için kesrin üstü büyük, altı küçük olmalıdır. Altın küçük olması, varyansların küçük olmasıyla mümkündür. Dağılımların varyansları ne kadar küçükse payda o kadar küçük olur ve öz nitelik sınıfları ayırt etmede o kadar etkili olur.

> **Hocanın vurgusu:** Bu yorumu yapabilmeniz çok önemli, çünkü hiçbir şeyi ezbere yapmıyoruz; her şeyi anlayarak yapmamız gerekiyor. Ortalamalar arası uzaklık ne kadar büyük ve varyanslar ne kadar küçükse öz nitelik o kadar iyidir.

Slayttaki hesap (ekrandan, 02:37:20):

$$SE(X_A - X_B) = \sqrt{0.0233/3 + 0.6333/3} = 0.4678$$

$$SE(Y_A - Y_B) = \sqrt{0.01/3 + 0.0133/3} = 0.0875$$

$$|\mathrm{mean}(X_A) - \mathrm{mean}(X_B)| \,/\, SE(X_A - X_B) = |0.4667 - 0.4333| \,/\, 0.4678 = 0.0735 < 0.5$$

$$|\mathrm{mean}(Y_A) - \mathrm{mean}(Y_B)| \,/\, SE(Y_A - Y_B) = |0.6 - 0.8333| \,/\, 0.0875 = 2.6667 > 0.5$$

Slayttaki yorum: X indirgeme adayıdır, çünkü ortalama değerleri yakındır ve test eşiğin altındadır. Y için test eşiğin belirgin biçimde üstündedir; Y iki sınıfı ayırt etme potansiyeli taşıdığı için indirgeme adayı değildir.

> **Ders sonrası not:** Slayttaki $\mathrm{var}(X_B) = 0.6333$ değeri hatalıdır. B sınıfının X değerleri $0.2, 0.7, 0.4$ için örneklem varyansı $0.0633$'tür. Buna göre $SE(X_A - X_B) = \sqrt{0.0233/3 + 0.0633/3} \approx 0.1700$ ve X için test $0.0333 / 0.1700 \approx 0.196$ olur. Y için kesin değerler $SE \approx 0.0882$ ve test $\approx 2.646$'dır (slayt $0.0875$ ve $2.6667$ veriyor). Bu düzeltmeler sonucu değiştirmez: X eşiğin altında, Y eşiğin üstündedir. Hesaplar python ile doğrulandı.

### 9.4 LDA ile ilişkisi

**Soru:** Bu yöntem doğrusal ayırtaç analizine (LDA) çok mu benziyor?

**Cevap:** Evet, LDA'da da sınıf içi varyans ve sınıflar arası varyans kavramları kullanılır. Ama burada öz nitelik bazında bir karşılaştırma yapılıyor; amaç öz nitelik seçimidir. Bu yöntemin uygulanabilmesi için mutlaka sınıf etiketli veri (class labeled data) gerekir.

### 9.5 Ders sonu sorusu: Bu örnekte neyi indirgedik?

**Soru:** Son örnekte hangi veriyi indirgemiş olduk, neyi tespit ettik?

**Cevap:** Amaç öz nitelik seçimiydi. İki öz nitelik var, X ve Y. Soru, A ve B sınıflarını birbirinden ayırt etmede hangisinin daha etkili olduğuydu. Test parametresi Y için X'e göre daha büyük çıktı. Bu yüzden Y'nin sınıfları ayırt etmede daha etkin olduğu görüldü. İkisi arasında seçim yapmak gerekirse Y seçilir; X veri setinden silinebilir.

Hoca örneğin kolay çözülsün diye sığ tutulduğunu söyledi. Gerçek veri setlerinde belki 50, belki 100 öz nitelik için bu test yapılır, test skorları büyükten küçüğe sıralanır. Skoru en büyük olanlar en değerli öz niteliklerdir; skoru küçük olanlar veri setinden silinerek öz nitelik sayısı azaltılır.

### 9.6 Kalabalık bir aykırı grup üzerine soru

Ders sonunda bir öğrenci, etiketsiz bir veride ana gruptan ayrı duran ve verinin yaklaşık %25–30'unu oluşturan bir bölüm olduğunda ne yapılması gerektiğini sordu; kendisi bu bölümü ayrı bir veri seti olarak incelemişti.

Hocanın cevabı: %25–30 çok büyük bir miktardır; bu kadar veriyi aykırı değer diye etiketlemek kolay değildir. Sınıf etiketi olsaydı sınıf içi değerlendirme yapılabilirdi, ama etiket yoksa bu mümkün değildir. Bu bölümü ayrı incelemek yapılabilir; ama ikisini bir arada değerlendiren bir çalışma da yapılabilir. Veri bölünürse aslında kümeler birbirinden ayrılıp işlem yapılmış gibi olur; kümeleme sonucunda kümelerin dengeli dağılmamış olabileceği de düşünülmelidir. Bu işlerde tek bir doğru yoktur; denenmeli ve sonuçlar karşılaştırılmalıdır. Veri madenciliği süreci zaten böyledir: akıştaki geri beslemelerle sonuca gidilir, sonra geri dönülüp bir şeyler değiştirilir, yeniden sonuç alınır ve karşılaştırılır.

## Örnek Sorular

### Soru 1: Zaman serisini tabloya dönüştürme

(ekrandan, 00:15:30 ve 00:18:40)

11 ölçümden oluşan $X = \{t(0), t(1), \dots, t(10)\}$ zaman serisi için pencere boyu 5'tir. (a) Bir sonraki değeri tahmin etmek için, (b) 3 adım ilerisini ($j = 3$) tahmin etmek için veriyi standart tablo biçimine getirin.

**Çözüm (derste verildi):**

- (a) Pencere birer kaydırılır: $t(0) \dots t(4) \rightarrow t(5)$, $t(1) \dots t(5) \rightarrow t(6)$, ..., $t(5) \dots t(9) \rightarrow t(10)$. Toplam 6 örnek.
- (b) $t(0) \dots t(4) \rightarrow t(7)$, $t(1) \dots t(5) \rightarrow t(8)$, $t(2) \dots t(6) \rightarrow t(9)$, $t(3) \dots t(7) \rightarrow t(10)$. Toplam 4 örnek.

### Soru 2: Boxplot ile aykırı değer

(ekrandan, 00:40:00)

Analiz edilecek veride yaş öz niteliği vardır. Değerler artan sırayla: 13, 15, 16, 16, 19, 20, 20, 21, 22, 22, 25, 25, 25, 25, 30, 33, 33, 35, 35, 35, 35, 36, 40, 45, 46, 52, 70.

- a) Ortalama nedir?
- b) Medyan nedir?
- c) Birinci çeyrek ($Q_1$) ve üçüncü çeyrek ($Q_3$) nedir?
- d) Veri için bir boxplot çizin.

**Çözüm (derste verildi):** $n = 27$; ortalama $809/27 \approx 29.96$; medyan 14. eleman, $M = 25$; $Q_1 = 20$, $Q_3 = 35$; $IQR = 15$; sınırlar $20 - 22.5 = -2.5$ ve $35 + 22.5 = 57.5$. Altta aykırı değer yok, alt bıyık 13'te kapalı. Üstte 70 sınırı aşar; tek aykırı değer 70'tir.

### Soru 3: Mesafeye dayalı aykırı değer tespiti

(ekrandan, 01:12:30)

İki boyutlu örneklerden oluşan $X = \{(2,3), (3,2), (1,1), (4,3), (1,6), (5,3), (4,2)\}$ veri seti için mesafeye dayalı teknikle aykırı değerleri bulun. Eşik mesafesi 3 ($d \geq 3$), komşu olmayan örnekler için eşik $p = 4$ ($p \geq 4$). İpucu: Bir $x_i$ örneği, uzaydaki örneklerin en az $p$ kadarı ondan $d$'den büyük mesafedeyse aykırıdır.

**Çözüm (derste verildi, birinci örnek hoca tarafından $(2,4)$ olarak düzeltildi):** Öklid mesafe matrisi kurulur (bkz. Bölüm 5.3). Komşu olmayan sayıları: $p = 2, 1, 5, 2, 5, 3, 2$. $p \geq 4$ olan $s_3$ ve $s_5$ aykırıdır.

> **Çözüm (derste verilmedi):** Slayttaki yazımla birinci örnek $(2,3)$ alınırsa mesafeler $d(s_1,s_3) = \sqrt{5}$, $d(s_1,s_5) = \sqrt{10}$, $d(s_1,s_6) = 3$ olur ve $p$ değerleri $2, 1, 4, 2, 6, 3, 2$ çıkar. Aykırı örnekler yine $s_3$ ($p = 4$) ve $s_5$ ($p = 6$)'dır. Hesap python ile yapıldı.

### Soru 4: Ortalama ve varyansa dayalı aykırı değer tespiti

(ekrandan, 01:34:00)

Aynı veri seti için her boyutu ayrı ayrı ele alan, ortalama ve varyansa dayalı aykırı değer tespitinin işlemlerini anlatın ve sonucu yorumlayın. İpucu: Eşik = Ortalama $\pm$ (2 $\times$ Standart Sapma).

**Çözüm (derste verildi):** $m_1 \approx 2.85$, $s_1 \approx 1.57$, aralık $[-0.29, 5.99]$; $m_2 = 3$, $s_2 \approx 1.63$, aralık $[-0.26, 6.26]$. Hiçbir değer aralık dışında değildir; aykırı değer yoktur.

### Soru 5: Sınıf etiketli veride çok değişkenli aykırı değer

(derste sözlü, 01:45:14)

Her öz niteliği ayrı ayrı değerlendiren tek değişkenli çözüm yerine çok değişkenli bir çözüm isteniyor ve veri setinde sınıf etiketi var. Nasıl bir çözüm önerirsiniz?

**Çözüm (derste verildi):** Her sınıfın sınıf içi ortalaması, yani merkez noktası bulunur. Her örneğin kendi sınıf merkezine Öklid uzaklığı hesaplanır. Bir mesafe eşiğine göre merkeze en uzak örnekler aykırı değer olarak işaretlenir. Sınıf etiketi yoksa bütün veri için tek bir merkez kullanılabilir.

### Soru 6: Öz nitelik seçimi

(ekrandan, 02:25:10)

Tablo 3.1'deki veri setinde X ve Y giriş öz nitelikleri, C ise örnekleri A ve B sınıflarına ayıran öz niteliktir: $(0.3, 0.7, A)$, $(0.2, 0.9, B)$, $(0.6, 0.6, A)$, $(0.5, 0.5, A)$, $(0.7, 0.7, B)$, $(0.4, 0.9, B)$. Testin eşik değeri 0.5'tir. X ve Y öz niteliklerinin indirgeme adayı olup olmadığına karar verin.

**Çözüm (derste verildi):** Slayta göre X için test $0.0735 < 0.5$, Y için $2.6667 > 0.5$. X indirgeme adayıdır, Y tutulur. Doğru varyansla X için test $\approx 0.196$, Y için $\approx 2.646$ çıkar; karar değişmez (bkz. Bölüm 9.3).

## Dersin Toparlaması

Bu derste veri ön işleme bölümü iki konuyla tamamlandı. Zamana bağlı veride tek bir öz niteliğin sabit aralıklı ölçümleri, bir pencere kaydırılarak örnek ve öz nitelik tablosuna dönüştürüldü. Çıkış bir sonraki değer ya da birkaç adım sonraki değer olabilir; çıkış nümerik ise problem regresyon, eşikle sınıflara bölünürse sınıflandırma olur. Aykırı değer analizinde üç yöntem görüldü: çeyreklere dayanan tek değişkenli boxplot, örnekler arası Öklid mesafesine dayanan çok değişkenli çözüm ve ortalama $\pm$ 2 standart sapmaya dayanan tek değişkenli çözüm. Aynı veride mesafe tabanlı yöntem iki aykırı örnek bulurken ortalama tabanlı yöntem hiç bulmadı. Katsayıların veriye göre denenerek seçilmesi, atılan verinin yaklaşık %5'i geçmemesi ve tek değişkenli yöntemlerde bütün örneğin silindiği hatırlatıldı.

Ardından veri indirgeme bölümüne geçildi. Verinin üç boyutu (öz nitelikler, örnekler, değerler) için indirgeme yapılabileceği, bunun hesaplama süresi, doğruluk ve görselleştirme açısından avantaj sağladığı anlatıldı. Öz nitelik indirgeme; seçim (eğiticili: ortalama ve varyans, eğiticisiz: entropi) ve birleştirme (PCA) olarak ikiye ayrıldı; değer indirgeme için ChiMerge anlatılacak. Eğiticili seçimde ortalamalar arası farkı standart hatayla oranlayan test ile Y'nin X'ten daha ayırt edici olduğu gösterildi. Hoca öz nitelik birleştirme (feature composition) yöntemlerine gelecek derste geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
