# Ders 11 Genişletilmiş Notu: k-En Yakın Komşu, NumPy, Pandas ve scikit-learn ile Sınıflandırma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Örnek Tabanlı Öğrenme (Instance-Based Learning)
- 3. k-En Yakın Komşu (kNN) Sınıflandırması
- 4. Uzaklık Ağırlıklı kNN
- 5. kNN'nin Sorunları ve Hızlandırma
- 6. Python, NumPy ve ndarray
- 7. Pandas: Series
- 8. Pandas: DataFrame
- 9. Eksik Veri, Dosya Okuma-Yazma ve Diğer İşlemler
- 10. Google Colab ile Uygulama
- 11. Iris Verisiyle Pandas Uygulaması
- 12. scikit-learn ile Karar Ağacı Sınıflandırması
- 13. Meyve Sınıflandırma Örneği ve Proje Üzerine Sorular
- Örnek Sorular

## 1. Dersin Planı

Ders üç bölümden oluştu. Önce teorik olarak yeni bir sınıflandırma yöntemi, örnek tabanlı öğrenme (instance-based learning) ve onun en çok kullanılan biçimi k-en yakın komşu (k-nearest neighbor, kNN) anlatıldı. Ardından veri analizinde çok kullanılan NumPy ve Pandas kütüphanelerinin üzerinden geçildi. Son bölümde, daha önce Weka'da yapılan bir sınıflandırma işi Python'da scikit-learn kütüphanesiyle Google Colab üzerinde yapıldı (00:01:11).

## 2. Örnek Tabanlı Öğrenme (Instance-Based Learning)

Instance, verideki tek bir örnektir (sample). Veri bir tablo olarak düşünülürse her satır bir instance'a karşılık gelir (00:02:07).

Örnek tabanlı öğrenmede amaç, eğitim örneklerinden bir model üretmek değildir. Elimizde yine bir eğitim kümesi vardır, ama ondan model kurulmaz; örneklerin kendisi model gibi kullanılır. Test örneğine en çok benzeyen eğitim örneği ya da örnekleri bulunur ve onların sınıfı, test örneğinin sınıfı kabul edilir (00:02:25).

Bu tür yöntemlere genellikle **tembel öğrenme** (lazy learning) yöntemleri denir. Derste daha önce görülen ve model kuran yöntemlere (karar ağacı gibi) ise **hevesli öğrenme** (eager learning) yöntemleri denir (00:04:00).

<!-- BELİRSİZ: 00:04:11'de karar ağacının yanında sayılan eager yöntem altyazıda "AWS" diye bozuk yazılmış; hangi yöntem olduğu anlaşılmıyor. -->

## 3. k-En Yakın Komşu (kNN) Sınıflandırması

### 3.1 Sezgi

Hoca yöntemi iki sınıflı (artılar ve eksiler) bir nokta bulutu üzerinde anlattı. Eğitim verisinde iki sınıf vardır. Yeni, sınıfı bilinmeyen bir nokta geldiğinde ona en yakın eğitim örneklerine bakılır. $k$ bir parametredir; 1, 10 ya da 100 olabilir. $k=1$ ise en yakın tek komşuya bakılır: en yakın nokta eksi ise yeni nokta da eksi, kırmızı ise kırmızı denir. Hiç model oluşturulmaz; algoritma bu kadar basittir (00:05:06).

Avantajı, bir modele ihtiyaç duymamasıdır. Dezavantajı ise zamandır: en yakın komşuyu bulmak için bütün örneklere bakmak gerekir. Dengeli bir ağaçta $n$ örnek arasında arama $\log n$ zamanda yapılırken, burada her örnekle uzaklık hesaplandığı için $n$ zaman gerekir (00:06:50).

### 3.2 Algoritma

Slaytta algoritma şöyle verildi (ekrandan, 00:10:00):

- Bütün eğitim örnekleri $\langle x_i, \text{Class}(x_i)\rangle$ biçiminde saklanır. $x_i$, i'inci satırın bütün özniteliklerini içeren bir vektördür; $\text{Class}(x_i)$ onun sınıfıdır.
- Verilen bir $x_q$ örneği için $\text{Class}(x_q)$, $k$ en yakın komşu kullanılarak hesaplanır.
- **En yakın komşu ($k=1$):** en yakın eğitim örneği $x_n$ bulunur ve $\text{Class}(x_q) = \text{Class}(x_n)$ kabul edilir.
- **k-en yakın komşu:** en yakın $k$ eğitim örneği bulunur ve $\text{Class}(x_q)$, bu komşuların sınıfları arasında **çoğunluk oylaması** (majority vote) ile belirlenir.

Çoğunluk oylaması formülü (ekrandan, 00:10:00):

$$y' = \arg\max_{v} \sum_{(x_i, y_i) \in D_z} I(v = y_i)$$

Burada $v$ bir sınıf etiketi, $y_i$ en yakın komşulardan birinin sınıf etiketi, $D_z$ en yakın $k$ komşunun kümesi, $I(\cdot)$ ise argümanı doğruysa 1, değilse 0 döndüren gösterge fonksiyonudur.

En yakın örnekleri bulmak için uzaklık gerekir; genellikle **Öklid uzaklığı** kullanılır. İki örnek arasındaki uzaklık, her özniteliğin farkının karesi alınıp toplanarak ve toplamın karekökü alınarak bulunur (00:08:10):

$$d(x_i, x_q) = \sqrt{\sum_{j} (x_{ij} - x_{qj})^2}$$

Bütün uzaklıklar hesaplanır, en küçük $k$ tanesi seçilir ve bu komşuların sınıfları oylanır. Örneğin $k=5$ iken en yakın beş örnekten üçü pozitif, ikisi negatif ise sonuç pozitif olur (00:10:33).

$k$ genellikle 3, 5 gibi tek sayı seçilir; böylece iki sınıflı problemde oylamada eşitlik çıkmaz (00:07:28).

> **Ders sonrası not:** Hoca 00:07:28'de "iki derseniz en yakın iki komşunun ortalamasını alacaksınız" dedi. Sınıflandırmada en yakın komşuların sınıfları oylanır, ortalama alınmaz; ortalama, büyük olasılıkla kNN'nin sayısal tahmin (regresyon) sürümü için geçerlidir. Hoca hemen ardından (00:09:01) "ortalama değil de oylamasını yapıp" diye kendini düzeltti.

### 3.3 Örnek: $\langle 3,3\rangle$ için 1-NN ve 3-NN

Slayttaki eğitim verisinde iki öznitelik (A, B) ve iki sınıf (yes, no) vardır (ekrandan, 00:15:00):

| A | B | Class |
|---|---|-------|
| 1 | 1 | no |
| 2 | 1 | no |
| 3 | 2 | yes |
| 7 | 7 | yes |
| 8 | 8 | yes |

Soru: A'sı 3, B'si 3 olan yeni örneğin, yani $\langle 3,3\rangle$'ün sınıfı nedir?

Her eğitim örneğiyle Öklid uzaklığı hesaplanır:

- (1,1): $\sqrt{(3-1)^2 + (3-1)^2} = \sqrt{4+4} = \sqrt{8}$
- (2,1): $\sqrt{(3-2)^2 + (3-1)^2} = \sqrt{1+4} = \sqrt{5}$
- (3,2): $\sqrt{(3-3)^2 + (3-2)^2} = \sqrt{1}$
- (7,7): $\sqrt{16+16} = \sqrt{32}$
- (8,8): $\sqrt{25+25} = \sqrt{50}$

**1-NN:** En küçük uzaklık $\sqrt{1}$, yani üçüncü örnek (3,2). Sınıfı yes olduğu için $\langle 3,3\rangle$ yes olarak sınıflanır (00:13:16).

**3-NN:** En yakın üç örnek $\sqrt{1}$ (yes), $\sqrt{5}$ (no) ve $\sqrt{8}$ (no) uzaklıklı olanlardır; $\sqrt{32}$ ve $\sqrt{50}$ çok daha uzaktır. Oylamada iki no, bir yes vardır; no kazanır ve $\langle 3,3\rangle$ no olarak sınıflanır (00:14:05).

Aynı örnek, $k$'nın seçimine göre farklı sınıf alabilir: en yakın komşu yes derken biraz daha uzaktaki iki komşu no der. Hoca bunun kNN'nin şimdiye kadar görülen en basit yöntem olduğunu, birçok makine öğrenmesi kaynağında ilk örnek olarak verildiğini söyledi (00:15:30).

## 4. Uzaklık Ağırlıklı kNN

### 4.1 Fikir

Önceki örnekte en yakın komşu yes derken, biraz daha uzaktaki iki komşunun oyu sonucu no yaptı. Bunun önüne geçmek için **uzaklık ağırlıklı kNN** (distance weighted kNN) önerilmiştir (00:15:51).

Normal kNN çoğunluk oylaması (majority voting) yapar ve her komşunun oy hakkı eşittir. Uzaklık ağırlıklı kNN'de ise her komşunun oyu uzaklığına göre ağırlıklandırılır. Hoca bunu, yeşil bir sorgu noktasının yakınında bir kırmızı, uzağında iki mavi nokta olan bir çizimle anlattı: 3-NN'de "iki mavi bir kırmızı, mavi kazandı" demek yerine, yakındaki kırmızının oyu daha ağır, uzaktaki mavilerin oyu daha hafif sayılır (00:16:43).

Ağırlık, uzaklığın karesinin tersidir:

$$w_i = \frac{1}{d(x_q, x_i)^2}$$

Oylama formülünde her komşunun oyu $w_i$ ile çarpılır ve toplam ağırlığı en büyük olan sınıf seçilir (00:17:37):

$$y' = \arg\max_{v} \sum_{(x_i, y_i) \in D_z} w_i \times I(v = y_i)$$

<!-- BELİRSİZ: Ağırlıklı oylama formülünün slayttaki tam yazımı karelerde görünmüyor; formül altyazıdaki anlatımdan (oylar $1/d^2$ ile çarpılıp argmax alınır) kuruldu. -->

### 4.2 Örnek: $\langle 3,3\rangle$ için uzaklık ağırlıklı 3-NN

Aynı veri ve aynı uzaklıklar kullanılır (ekrandan, 00:20:00). En yakın üç komşu $\sqrt{8}$ (no), $\sqrt{5}$ (no) ve $\sqrt{1}$ (yes) uzaklıklıdır.

- no ağırlığı: $\dfrac{1}{(\sqrt{8})^2} + \dfrac{1}{(\sqrt{5})^2} = \dfrac{1}{8} + \dfrac{1}{5} = \dfrac{5 + 8}{40} = \dfrac{13}{40}$
- yes ağırlığı: $\dfrac{1}{(\sqrt{1})^2} = 1$

$1 > 13/40$ olduğu için $\langle 3,3\rangle$ yes olarak sınıflanır. Birden fazla yes komşusu olsaydı onların ağırlıkları da toplanacaktı (00:19:17).

### 4.3 Derste çözdürülen alıştırma: $\langle 5,5\rangle$

Hoca öğrencilere yeni bir veri verdi: yine iki öznitelik, sınıfta 3 Y (yes) ve 2 N (no). $\langle 5,5\rangle$ örneği için 3-NN kullanılması istendi (00:21:00).

<!-- BELİRSİZ: Alıştırmanın veri tablosu karelerde görünmüyor. Altyazıdan yalnız şunlar çıkıyor: bir örnekle uzaklık $\sqrt{4^2+4^2}=\sqrt{32}$ (büyük olasılıkla (1,1) noktası), en yakın üç komşu uzaklığı $\sqrt{10}$ ve $\sqrt{5}$ olan iki yes ile (6,5) noktasındaki bir no. -->

Çözüm altyazıdaki anlatıma göre şöyledir:

- En yakın üç komşu: uzaklığı $\sqrt{10}$ olan bir yes, uzaklığı $\sqrt{5}$ olan bir yes ve uzaklığı $\sqrt{(6-5)^2 + (5-5)^2} = \sqrt{1} = 1$ olan bir no.
- **Ağırlıksız 3-NN:** iki yes, bir no; sonuç **yes** (00:22:31).
- **Uzaklık ağırlıklı 3-NN:** yes ağırlığı $\dfrac{1}{10} + \dfrac{1}{5} = \dfrac{3}{10}$, no ağırlığı $\dfrac{1}{1} = 1$. No ağırlığı daha büyük olduğu için sonuç **no** (00:23:54).

Hoca ilk denemede komşuları yanlış okuyup sonra düzeltti; doğru sonuç yukarıdakidir (00:23:35).

> **Ders sonrası not:** Hoca yes ağırlığı için "3 bölü 15 gibi bir şey geliyor" dedi (00:23:54). Doğrusu $\frac{1}{10} + \frac{1}{5} = \frac{1}{10} + \frac{2}{10} = \frac{3}{10}$'dur. Sonuç değişmez, çünkü $1 > 3/10$.

## 5. kNN'nin Sorunları ve Hızlandırma

Slaytta iki sorun başlığı vardı (ekrandan, 00:25:00).

### 5.1 $k$ değerinin seçimi

- **$k$ çok küçükse** (1, 3 gibi) yöntem gürültülü noktalara duyarlı olur. Slayttaki şekilde sorgu noktasının çevresinde birkaç artı vardır; bunlar gürültü olabilir. Karar bir ya da birkaç örneğe takılı kalır ve bu örnekler gürültüyse yanlış sınıflama yapılır (00:24:58).
- **$k$ çok büyükse** komşuluğa başka sınıflardan noktalar girer. Şekilde büyük çember içinde artıların etrafında çok sayıda eksi vardır; gereksiz örnekler de oylamaya katılır (00:25:32).

### 5.2 Ölçekleme sorunu

Uzaklık hesabında öznitelikler doğrudan birbirinden çıkarılır. A özniteliğinin değerleri 0-1 arasında, B'ninkiler −1 milyon ile +1 milyon arasında ise B'deki farklar çok büyük olacağı için uzaklığı B belirler, A'nın hiçbir etkisi kalmaz. Bunu önlemek için kNN çalıştırılmadan önce bütün öznitelikler normalize edilir, örneğin hepsi 0-1 aralığına ölçeklenir (00:25:58).

> **Hocanın vurgusu:** Normalize edilmezse aralığı büyük olan öznitelik uzaklığa hâkim olur ve diğer özniteliklere hiç bakılmamış olur.

### 5.3 Test zamanının maliyeti ve hızlandırma

Model kuran yöntemler (örneğin karar ağacı) zamanı eğitimde harcar, testte hızlıdır. kNN'de model kurulmadığı için eğitimde zaman kaybı yoktur; ama test sırasında her sorgu için bütün örneklere tek tek bakılıp minimum uzaklıklar bulunur. Bu yüzden özellikle büyük veri kümelerinde çok yavaş çalışır (00:27:10).

Hoca öğrencilere bunu nasıl hızlandırabileceklerini sordu, sonra bir fikir anlattı. Veri genellikle iki boyutlu değil çok boyutludur ve veritabanlarında küp biçiminde tutulabilir. Veri uzayı parçalara, örneğin 3×3'lük bir ızgaraya (grid) bölünür ve her ızgara hücresi için özet (ortalama) bilgiler tutulur. Yeni bir örnek sorulduğunda önce bütün örneklere değil bu 9 hücreye bakılır, örneğin hangi hücreye düştüğü bulunur; sonra yalnız o bölgedeki örneklerle karşılaştırma yapılır. Bunun için verinin özniteliklere göre sıralı biçimde veritabanında tutulması gerekir (00:28:19).

> **Ek bilgi (derste anlatılmadı):** Komşu aramasını hızlandırmak için kullanılan yaygın veri yapıları arasında k-d ağacı ve ball tree vardır. scikit-learn'deki `KNeighborsClassifier` bu yapıları `algorithm` parametresiyle seçebilir.

## 6. Python, NumPy ve ndarray

### 6.1 Python hakkında

Hoca Python'un sözdizimi kolay, okunması ve öğrenilmesi kolay olsun diye tasarlanmış bir dil olduğunu, kullanımının hızla arttığını söyledi. Python yorumlanan (interpreted) bir dildir: bütün programı derlemeden satır satır çalıştırılabilir; bu, hatanın nerede olduğunu adım adım bulmayı kolaylaştırır (00:30:34).

Veri analizinde kullanılan iki kütüphaneye bakıldı: Pandas ve onun üzerine kurulduğu NumPy (00:31:33).

Pandas (Python Data Analysis Library) açık kaynaklıdır, BSD lisanslıdır; ticari kullanım, değiştirme, dağıtma ve özel kullanım serbesttir. NumPy üzerine kuruludur ve bilimsel hesaplama araçlarından oluşan SciPy ekosisteminin parçasıdır. Hoca, bilimsel alanda daha önce MATLAB gibi ücretli araçlar kullanılırken artık Python'un alanı domine ettiğini söyledi (00:32:01). Pandas'ın resmî sitesindeki "10 minutes to pandas" öğreticisine bakılmasını önerdi (00:33:10).

Pandas'ın avantajı kullanımının ve öğrenilmesinin kolay olması, veriyi basitçe değiştirmeye izin vermesidir. Alt tarafta C ve Fortran ile yazılmış NumPy çalıştığı için hızlıdır. Ancak binlerce görüntü gibi çok büyük, çok boyutlu verilerle çalışırken Pandas yavaş kalabilir; o durumlarda başka kütüphaneler tercih edilir. Görüntüyle uğraşmayan, tablo biçimindeki veriyle yapılan veri madenciliği için Pandas yeterlidir (00:35:29).

### 6.2 ndarray

NumPy adı "Numerical Python"dan gelir. Çok boyutlu diziler (multidimensional arrays) için `ndarray` adlı bir veri tipi tanımlar; "nd", n-dimensional demektir. Bu, Python'un kendi listesi değil, NumPy'ın nesnesidir (00:36:55). Çok boyutlu dizileri döngülerle çarpmak çok yavaştır (karmaşıklık $n^2$, $n^3$ gibi büyür); NumPy bu vektörel işlemleri alt katmanda hızlı yapar (00:38:03).

`ndarray`'in yapısı C dizisine çok benzer (00:38:50):

- **Boyut sabittir.** C'de diziyi oluştururken boyutunu ve eleman tipini vermek gerekir ki bellekte yer ayrılsın. NumPy dizisi de öyledir. Boyut değiştirilmek istenirse bellekte yeni bir dizi için yer alınır, eski elemanlar kopyalanır ve eski dizi silinir. Örneğin 5 elemanlı dizi 10 elemanlı yapılırsa 10 elemanlık yeni yer alınır, 5 eleman kopyalanır, eski dizi silinir (00:40:06).
- **Bütün elemanlar aynı tiptedir.** Python listesi dinamik büyür ve içine aynı anda integer, float, string konabilir. NumPy dizisinde ise bütün elemanlar ya integer ya float olmak zorundadır (00:40:45).

Neden böyle olduğunu hoca işaretçilerle açıkladı: elemanlar aynı boyutta (örneğin 8 bayt) olunca işaretçi her seferinde sabit adım ilerler. Listelerde elemanların boyutları farklı olduğundan her seferinde bunun da hesaplanması gerekir; bu da çarpma gibi vektörel işlemleri yavaşlatır (00:41:12).

### 6.3 Dizi oluşturma ve indeksleme

Kullanmadan önce kütüphane içe aktarılır. Her seferinde `numpy.` yazmamak için kısaltma verilir; genellikle `np` kullanılır (00:42:12):

```python
import numpy as np
```

Slayttaki örnek (ekrandan, 00:45:00):

```python
a = np.array([[3., 0.], [20., 230.], [21., 275.]])
# array([[  3.,   0.],
#        [ 20., 230.],
#        [ 21., 275.]])

a[2, 0]    # a[2][0] ile aynı sonuç
# 21.0

a[:2, :]   # dizinin bir görünümünü (view) döndürür
# array([[  3.,   0.],
#        [ 20., 230.]])
```

Hoca, NumPy'a yeni başlayanların köşeli parantezlerde zorlandığını söyledi: normal parantez fonksiyonun parantezidir; her satır ayrı köşeli parantez içinde yazılır. Python'da C'deki gibi satır sonunda noktalı virgül yoktur (00:43:16).

İndeksler C'deki gibi 0'dan başlar, Java'daki gibi 1'den değil. Satır yönü **axis 0**, sütun yönü **axis 1**'dir. `a[2,0]`, 2 numaralı satırın 0 numaralı sütunudur, yani 21 (00:44:46).

İki nokta üst üste (`:`) Python'a özgü dilimleme işaretidir. `1:2`, `3:20` gibi aralıklar yazılabilir; başı boşsa baştan, sonu boşsa sona kadar demektir; tek başına `:` hepsi demektir. `a[:2, :]` axis 0'da 0'dan 2'ye kadar (2 hariç) satırları, axis 1'de bütün sütunları alır ve `[[3, 0], [20, 230]]` döndürür. `a[:, :]` bütün tabloyu verir (00:45:32).

### 6.4 Öznitelikler: shape, dtype, itemsize

- `a.shape` boyutu verir: (3, 2). Önce axis 0 yazılır (00:47:01).
- `a.dtype` veri tipini verir. Değerler noktalı (`3.`) yazıldığı için hepsi float olarak oluşturuldu: `float64`. Nokta konmasaydı integer olurdu (00:47:13).
- `a.itemsize` her elemanın kaç bayt olduğunu verir: float64 için 8 (00:47:42).

### 6.5 View davranışı

`b = a[:2, :]` ile ilk iki satır ve bütün sütunlar `b`'ye atandığında aslında dizinin bir görünümü (view) oluşturulur. Ardından `b[0, 0] = 0` yapılıp `a` yazdırılırsa, `a`'nın ilk elemanının da 3 değil 0 olduğu görülür (00:48:08).

> **Hocanın vurgusu:** View üzerinde yapılan bütün değişiklikler asıl diziyi doğrudan etkiler. Normalde bir değişkeni yedekleyip yeni değişken üzerinde çalışırsınız; burada böyle yapamazsınız.

> **Ek bilgi (derste anlatılmadı):** Asıl diziyi etkilemeyen bağımsız bir kopya için `b = a[:2, :].copy()` kullanılır.

### 6.6 reshape ve resize

Slayttaki örnek (ekrandan, 00:50:00): "reshape metodu argümanını değiştirilmiş şekille döndürür, resize ise dizinin kendisini değiştirir."

```python
b = a.reshape(2, 3)
# b: array([[  3.,   0.,  20.],
#           [230.,  21., 275.]])
# a değişmez: [[3., 0.], [20., 230.], [21., 275.]]

a.resize(2, 3)
# a artık: array([[  3.,   0.,  20.],
#                 [230.,  21., 275.]])

np.resize(a, (2, 3))
# array([[  3.,   0.,  20.],
#        [230.,  21., 275.]])
```

`a` 3 satır, 2 sütunluktu. `reshape(2,3)` elemanları sırayla alıp 2 satır, 3 sütun yapar: 3, 0, 20 ilk satır; 230, 21, 275 ikinci satır olur. `reshape`'te şekli değişen yalnız `b`'dir; `resize`'da ise `a`'nın kendisi 2×3 olur (00:49:40).

### 6.7 Hazır fonksiyonlar

NumPy'da çok sayıda matematiksel ve algoritmik fonksiyon vardır: sıralama (sort), lineer cebir yöntemleri, medyan, minimum gibi (00:51:06).

- `a.sum()` bütün elemanları toplar.
- `a.max()` en büyük elemanı verir: 275.
- Bu fonksiyonlar `axis` parametresi alır. `a.sum(axis=0)` sütun sütun toplar: birinci sütun $3 + 20 + 21 = 44$, ikinci sütun $0 + 230 + 275 = 505$ (00:52:06).

### 6.8 Yapılandırılmış diziler (structured arrays)

Normal bir `np.array`'de bütün elemanların tipi aynıdır. Ama dizi tanımlanırken sütunlara ad ve ayrı tip verilirse farklı tipler tutulabilir (ekrandan, 00:55:00):

```python
a = np.array([(3., 0.), (20., 230.), (21., 275.)],
             dtype=np.dtype([('Age', int), ('Weight', float)]))
# array([( 3,   0.), (20, 230.), (21, 275.)],
#       dtype=[('Age', '<i8'), ('Weight', '<f8')])

a['Age']
# array([ 3, 20, 21])

a[0]
# (3, 0.)
```

Burada `a`, elemanları demet (tuple) olan tek boyutlu bir dizidir. `'Age'` sütunu integer, `'Weight'` sütunu float tutulur; artık `a['Age']` ile sütuna adıyla erişilir (00:53:27).

Hoca bunun bellekteki karşılığını şöyle açıkladı: çok boyutlu diziler bellekte satır satır, düz bir şekilde tutulur; yapılandırılmış dizide her satırın int kısmı ve ardından float kısmı art arda yerleşir (00:54:47).

## 7. Pandas: Series

Aradan sonra Pandas'a geçildi. Hoca bu dönemki projelerde NumPy'ı çok kullanmayacaklarını, ama makine öğrenmesi, derin öğrenme ya da simülasyon yaparlarsa mutlaka kullanacaklarını söyledi. Pandas NumPy üzerine kurulu olduğu için veri yapıları da benzerdir (01:10:00).

Pandas'ta iki temel veri yapısı vardır (01:10:29):

- **Series:** tek boyutlu veri. Bir sinyal ya da zaman serisi gibi düşünülebilir.
- **DataFrame:** iki boyutlu veri. Veri madenciliğindeki tabloya karşılık gelir: her sütun bir öznitelik (variable), her satır bir örnek (instance, sample, object).

### 7.1 Series oluşturma

Pandas da kullanılmadan önce içe aktarılır; kısaltması `pd`'dir (01:13:16). Slayttaki örnek (ekrandan, 01:15:00):

```python
import pandas as pd

s = pd.Series([3, 20, 21],
              index=['Bei Bei', 'Mei Xiang', 'Tian Tian'],
              name='Age')
# Bei Bei       3
# Mei Xiang    20
# Tian Tian    21
# Name: Age, dtype: int64

s.array   # numpy.ndarray etrafında kopyasız ince bir sarmalayıcı
# <PandasArray>
# [3, 20, 21]
# Length: 3, dtype: int64
```

Bu seri iki sütunlu bir tablo gibi görünse de tek boyutludur. Soldaki adlar veri değil, indekstir; yani değerlere verilen adlardır. `name='Age'` serinin bütününün adıdır (01:12:06). `s.array` indeksler olmadan yalnız verileri (3, 20, 21) verir (01:14:39).

Diğer öznitelikler: `s.dtype` veri tipini, `s.name` adı ('Age'), `s.index` indeks değerlerini verir. `index` ve `name` parametreleri isteğe bağlıdır (01:15:22).

Bir serinin boyutu tanımlandıktan sonra değiştirilemez; ama daha büyük bir seri oluşturulup içine kopyalanabilir (01:12:32).

C'de olmayan bir kavram **NaN**'dır (not a number). C'deki null'a benzer; içinde değer olmayan hücreleri gösterir. Veri madenciliğindeki eksik veri (missing data) NaN olarak tutulur (01:12:48).

### 7.2 İndeksin işe yaraması

Hoca indeksin yararını bir zaman serisiyle anlattı: 2017 Ocak'tan başlayarak her ay bir değer toplandığını, her yıldan 12 değer geldiğini düşünelim. Bu değerler yalnız bir sütun olarak tutulabilir; ama her değerin tarihi indeks olarak verilirse belirli bir tarihteki değere doğrudan erişilebilir (01:16:08).

Erişim hem numarayla hem indeks adıyla yapılabilir: `s[1]` ile `s['Mei Xiang']` aynı değeri (20) verir. Dilimleme de her ikisiyle yapılabilir (01:17:06).

### 7.3 Series'te view

NumPy'daki view davranışı Series'te de vardır. `t = s[1:3]` ile 20 ve 21 değerleri `t`'ye alınıp `t['Tian Tian'] = 22` yapılırsa, `s` yazdırıldığında `s`'deki değerin de 22 olduğu görülür (01:18:19).

> **Hocanın vurgusu:** Verinin bir kısmını alıp onunla çalışıyorsanız, orada yaptığınız değişikliklerin ana veriyi de değiştireceğini unutmayın.

### 7.4 Otomatik hizalamayla seri toplama

Slayttaki örnek (ekrandan, 01:20:00):

```python
u = pd.Series([230., 275.],
              index=['Mei Xiang', 'Tian Tian'],
              name='Weight')
# Mei Xiang    230.0
# Tian Tian    275.0
# Name: Weight, dtype: float64

s.add(u)   # s + u ile aynı; NumPy'daki varsayılan da budur
# Bei Bei        NaN
# Mei Xiang    250.0
# Tian Tian    296.0
# dtype: float64
```

Toplama indekse göre hizalanarak yapılır: Mei Xiang için $20 + 230 = 250$, Tian Tian için $21 + 275 = 296$. Bei Bei'nin `u`'da karşılığı olmadığı için sonuç NaN olur (01:22:12).

`s.add(u, fill_value=0)` yazılırsa karşılığı olmayan değer 0 kabul edilir: Bei Bei için $3 + 0 = 3$ çıkar, NaN oluşmaz (01:21:09).

## 8. Pandas: DataFrame

### 8.1 Oluşturma

DataFrame iki boyutludur ve tablolara benzer. Satırlara isim vermek zorunlu değildir; büyük verilerde satır adı olmaz, yalnız sütun adları olur. Slaytlardaki satır adları yalnız öğretici amaçlıdır (01:22:56).

DataFrame aslında bir **serilerden oluşan sözlüktür** (dictionary of series): örneğin bir Age serisi ile bir Weight serisinin birleşmiş hali (01:23:27). Python sözlüğü sözdizimiyle oluşturulur: Age sütununa 3, 20, 21; Weight sütununa `np.nan`, 230, 275 konur ve satırlara indeks verilebilir (01:24:01).

<!-- BELİRSİZ: DataFrame oluşturma slaytının tam kodu karelerde görünmüyor; yapı altyazıdan ve 01:25:00 karesindeki tablodan kuruldu. -->

`df.dtypes` her sütunun tipini verir: Age integer, Weight float (01:24:35).

### 8.2 Öznitelikler

Slayttaki örnek (ekrandan, 01:25:00); tablo BB (Bei Bei) için Age 3 ve boş Weight, MX için 20 ve 230, TT için 21 ve 275 içerir:

```python
df.shape     # (3, 2)
df.size      # 6
df.columns   # Index(['Age', 'Weight'], dtype='object')
df.index     # Index(['Bei Bei', 'Mei Xiang', 'Tian Tian'], dtype='object')
```

`df.shape` satır ve sütun sayısını, `df.size` eleman sayısını, `df.columns` sütun adlarını, `df.index` satır adlarını verir (01:25:02).

Sütuna adıyla (`df['Age']`) ya da numarasıyla erişilebilir. Hoca kendisinin daha çok numarayla eriştiğini söyledi (01:25:22).

### 8.3 Rastgele verili DataFrame, head ve tail

Öğreticideki örnekte önce `pd.date_range` ile 2013-01-01'den başlayan 5 periyotluk (5 günlük) bir tarih indeksi oluşturuldu. Ardından 5 satır, 4 sütunluk rastgele değerlerle, indeksi bu tarihler ve sütunları A, B, C, D olan bir DataFrame kuruldu (01:26:18).

> **Ders sonrası not:** Hoca önce "5 aylık" dedi, sonra "5 aylık değil, 5 günlük" diye düzeltti (01:26:56). `pd.date_range`'in varsayılan sıklığı gündür; `periods=5` beş ardışık gün üretir (bu, 01:35:00 karesindeki 2013-01-01 ile 2013-01-05 arasındaki indeksle de uyumludur).

- `df.head(n)`: ilk n satırı gösterir; parametre verilmezse varsayılan 5'tir. Veriyi veritabanından ya da dosyadan okuduktan sonra hızlıca görmek için çok kullanılır (01:28:15).
- `df.tail(n)`: son n satırı gösterir. Örneğin `df.tail(2)` son iki satırı verir (01:28:46).
- `df.index` satır adlarını, `df.columns` sütun adlarını verir; `df.A` ya da `df['A']` A sütununu indeksleriyle birlikte yazar (01:29:13).

<!-- BELİRSİZ: Hoca 01:28:22'de head için "en fazla 50'ye kadar çalışıyor galiba" dedi; bu iddia doğrulanamadı, nota kural olarak alınmadı. -->

### 8.4 to_numpy

`df.to_numpy()` DataFrame'deki sayısal değerleri bir `ndarray` olarak döndürür (ekrandan, 01:30:00). Slayttaki not: veri heterojen ise (farklı tiplerde sütunlar varsa) kopya gerekebilir. Slaytta `a = df.to_numpy()` sonrası `a[0,0] = 0` yapılınca `df['A'][0]` değerinin de `0.0` olduğu gösterilir; yani burada da dönen dizi aynı veriyi paylaşır (ekrandan, 01:30:00).

### 8.5 Mantıksal indeksleme

C'de olmayan ama çok işe yarayan bir özellik koşulla seçmedir (01:30:11):

- `df[df['A'] > 0]` (ya da `df[df.A > 0]`): A sütunu sıfırdan büyük olan satırları getirir. Örnekte 0, 1 ve 3 numaralı satırlarda A pozitifti, bu üç satır geldi (01:30:46).
- `df[df > 0]`: bütün tabloda sıfırdan büyük olan değerler kalır, negatif değerlerin hepsi NaN ile değiştirilir (01:31:51).

> **Ders sonrası not:** Hoca 01:31:30 civarında A'nın pozitif olduğu "3 kolonunu" getireceğini söyledi; koşul satırları süzer, doğrusu "3 satırı" getirmesidir.

C'de bu iş iki iç içe döngü ve `if` ile, $n^2$ zamanda yapılırdı. NumPy'ın vektörel yapısı sayesinde Pandas'ta çok daha hızlı yapılır. Veri temizlemede çok kullanılır: örneğin belirli bir değerden büyük değerleri silmek ya da en büyük değer 10 olsun diye 10'dan büyükleri başka bir değerle değiştirmek (01:32:29).

## 9. Eksik Veri, Dosya Okuma-Yazma ve Diğer İşlemler

### 9.1 Eksik veri

Eksik veriyi silmek ya da değiştirmek için hazır fonksiyonlar vardır (ekrandan, 01:35:00):

- `df.dropna`: eksik değer (NaN) içeren satır ya da sütunları siler.
- `df.fillna`: NaN'ları verilen değerle doldurur (0, 100 gibi).
- `df.isna` ya da `pd.isna(df)`: `df` ile aynı boyutta, her hücrenin NaN olup olmadığını gösteren boolean değerli bir DataFrame döndürür.

Slayttaki `df.fillna(value=0)` sonucu (ekrandan, 01:35:00):

| | A | B | C | D |
|---|---|---|---|---|
| 2013-01-01 | 0.00000 | 1.171513 | 0.000000 | 0.298407 |
| 2013-01-02 | 0.00000 | 0.893041 | 2.136786 | 0.000000 |
| 2013-01-03 | 0.00000 | 0.030041 | 0.131783 | 0.000000 |
| 2013-01-04 | 0.46075 | 0.000000 | 0.000000 | 0.000000 |
| 2013-01-05 | 0.00000 | 0.953238 | 0.778675 | 1.109996 |

Değer 10 verilseydi NaN'lar 10 ile değiştirilecekti (01:34:30).

### 9.2 Dosya okuma ve yazma

- `pd.read_csv(...)`: CSV dosyasını okur ve DataFrame'e koyar. Dosya aynı klasörde değilse tam yolu verilir; CSV bir web adresindeyse `http://...` adresi yazılabilir. `read_` ile başlayan başka dosya türleri için de fonksiyonlar vardır (01:35:08).
- `index_col` parametresi önemlidir: her CSV'de indeks sütunu bulunmaz, veriler doğrudan ilk sütundan başlayabilir. Bu parametre hangi sütunun indeks olacağını söyler (01:35:50).
- `df.to_csv('foo.csv')`: var olan DataFrame'i yeni bir CSV dosyasına yazar (01:36:30).

### 9.3 Diğer işlemler

- `mean`, `sum` gibi istatistiksel fonksiyonlar DataFrame üzerinde de kullanılır (01:36:55).
- `value_counts`: her değerden kaç tane olduğunu sayar; histogram gibi düşünülebilir (01:37:05).
- `concat` iki DataFrame'i birleştirir, `append` sona ekler, `merge` veritabanındaki join gibi tabloları birleştirir (01:37:22).

### 9.4 groupby

Hoca `groupby`'ın kesin kullanılacağını söyledi (01:37:22). Örnekte A sütununda foo, bar, foo, bar değerleri; B ve C sütunlarında rastgele dörder sayı olan bir DataFrame kuruldu. Satırlara indeks verilmediği için indeks 0'dan otomatik ilerler; hoca gerçek verilerde satırlara genellikle indeks verilmediğini, önceki örnekte tarih olduğu için verildiğini söyledi (01:37:46).

`df.groupby('A').sum()` A'daki değerlere göre gruplar: foo olan 0. ve 2. satırlar bir grup, bar olan 1. ve 3. satırlar bir grup olur. Sonra her grup için B ve C sütunları toplanır; örneğin foo grubunun B değeri $-0{,}12 + (-0{,}73)$ gibi iki değerin toplamıdır (01:38:45). `sum` yerine `mean`, `min`, `max` gibi başka fonksiyonlar da kullanılabilir. Hoca bunu Excel'deki pivot tablolara benzetti (01:39:26).

<!-- BELİRSİZ: groupby örneğindeki rastgele B ve C değerleri karelerde görünmüyor; altyazıdaki −0,12 ve −0,73 değerleri doğrulanamadı. -->

### 9.5 Kategorik veri

Veride her zaman sayı olmaz; evet/hayır gibi kategorik değerler de vardır. Hem Series hem DataFrame'de kategorik veri kullanılabilir (01:39:45). Slayttaki örnek (ekrandan, 01:40:00):

```python
s = pd.Series(["a", "b", "c", "a"], dtype="category")
# 0    a
# 1    b
# 2    c
# 3    a
# dtype: category
# Categories (3, object): [a, b, c]
```

Slayta göre kategorik tip istatistikteki kategorik değişkenlere benzer, bellek tasarrufu ve sıralama için pratiktir; örnekleri cinsiyet, sosyal sınıf, kan grubu, ülke, gözlem zamanı ya da Likert ölçeğiyle derecelendirmedir (ekrandan, 01:40:00).

### 9.6 Matplotlib ile çizim

Pandas'tan ayrı bir kütüphane olan Matplotlib çizim yapmayı sağlar. Örnekte `ts` adlı bir zaman serisi `cumsum` ile kümülatif toplamına çevrildi (10. satırdaki değer, baştan 10. satıra kadar olan değerlerin toplamı olur) ve `ts.plot()` ile çizdirildi (01:40:33).

## 10. Google Colab ile Uygulama

### 10.1 Colab ortamı

Proje için Python kullanılabilecek herhangi bir editör kurulabilir. Bilgisayar yavaşsa Google Colab kullanılabilir: kurulum gerekmez, kod Google'ın sunucusunda çalışır. Google Drive'da sağ tıklayıp "Diğer" menüsünden "Google Colaboratory" seçilerek yeni bir defter açılır (01:42:17).

Colab, Jupyter Notebook gibi çalışır: **metin hücrelerine** açıklama yazılır (derlenmez, yorum gibidir), **kod hücrelerine** Python kodu yazılıp anında çalıştırılır. Çıktı hücrenin altında görünür; kullanılan RAM gösterilir. Veri büyükse ayarlardan GPU ya da TPU seçilerek daha hızlı çalıştırılabilir (01:43:35).

### 10.2 Kısaltma neden kullanılır

`import pandas as pd` yerine yalnız `import pandas` yazılırsa `pd.` ile başlayan satırlar hata verir; her seferinde `pandas.` yazmak gerekir. Hoca, `pd` kısaltmasının fiilî standart olduğunu söyledi (01:45:57).

> **Hocanın vurgusu:** Kendiniz başka bir kısaltma uydurmayın; yazdığınız kodu başkası okuyacak.

### 10.3 DataFrame'i CSV'ye yazma ve indirme

Defterdeki kod (ekrandan, 01:45:00):

```python
import pandas as pd
from google.colab import files

df = pd.DataFrame({'name': ['Raphael', 'Donatello'],
                   'mask': ['red', 'purple'],
                   'weapon': ['sai', 'bo staff']})

df.to_csv("dene.csv", index=False)

# bu colab kütüphanesinin kendi bilgisayarınıza dosya indirme komutudur
files.download("dene.csv")
```

`from google.colab import files`, Colab alanındaki dosyalarla çalışmayı sağlar. Colab kodu sunucuda çalıştırdığı için `files.download` dosyayı sunucudan kullanıcının bilgisayarına indirir (01:46:40). Derste dosya adı "VM_dersi.csv" olarak değiştirildi ve `index=False` ile indeks sütunu yazılmadı (01:47:42).

İndirilen dosya Not Defteri'yle açıldığında içeriği şuydu (ekrandan, 01:50:00):

```text
name,mask,weapon
Raphael,red,sai
Donatello,purple,bo staff
```

CSV, "comma separated values" demektir: bir Excel dosyası değil, değerleri virgülle ayrılmış düz metindir. İlk satır sütun adlarıdır (01:49:34).

Asıl kullanım bunun tersidir: proje için bulunan CSV, Drive'daki Colab klasörüne konur ve `pd.read_csv` ile bir DataFrame'e okunur (01:50:28).

### 10.4 Excel yazma ve okuma

Defterdeki kod (ekrandan, 01:45:00):

```python
# Excel oluşturma
pd.DataFrame({'a': [0, 3, 10], 'b': [True, True, False]}).to_excel('./pd_write.xlsx')

# var olan bir excel dosyasını okuma ve data isimli değişkene atama
# data = pd.read_csv('pd_write.xlsx', index_col=0)
data = pd.read_csv('dene.csv', index_col=0)
print(data.head())
```

`to_excel` DataFrame'i CSV yerine Excel dosyası olarak yazar (01:51:05). `read_csv` var olan bir CSV'yi okur. `print` yazmadan yalnız `data.head()` yazılsa da Colab sonucu gösterir; indeksler kalın yazılır. `data.head(1)` yalnız ilk satırı gösterir (01:52:35).

> **Hocanın vurgusu:** Hata alır ve anlamazsanız, hata mesajını kopyalayıp Google'da aratın (01:52:23).

## 11. Iris Verisiyle Pandas Uygulaması

### 11.1 Dosya okuma sorunu ve çözüm

Daha önce Weka'da kullanılan Iris verisi açıldı. Veride 150 satır, dört boyut özniteliği (sepal ve petal uzunluk/genişlikleri) ve üç kategorik sınıf (Setosa, Versicolor, Virginica) vardır (01:53:20).

Drive'daki `iris.csv` dosyası Colab tarafından bulunamadı; hoca birkaç deneme yaptı, sonra arada çözüm aradı (01:54:05). Aradan sonra dosya `files.upload()` ile kendi bilgisayarından yüklendi (02:15:02). Defterdeki kod (ekrandan, 02:15:00):

```python
# varolan dosyayı oku
from google.colab import files
import pandas as pd
from google.colab import drive
uploaded = files.upload()

data = pd.read_csv('iris.csv', index_col=0)

# head komutu ilk beş satırı listeler
data.head()
```

Çıktıda `sepal.length` sütunu indeks gibi kalın yazıldı (5.1, 4.9, 4.7, 4.6, 5.0), diğer sütunlar `sepal.width`, `petal.length`, `petal.width`, `variety` oldu (ekrandan, 02:15:00). Sebep, dosyada indeks sütunu olmadığı halde `index_col=0` verilmesidir: ilk öznitelik indeks sanıldı. `index_col` kaldırılınca 4 öznitelik ve `variety` (sınıf) sütunu doğru okundu, indeksler 0, 1, 2, ... diye otomatik ilerledi (02:15:44).

> **Ek bilgi (derste anlatılmadı):** Colab'de Drive'daki dosyalara erişmenin bir yolu `from google.colab import drive` ve `drive.mount('/content/drive')` ile Drive'ı bağlayıp dosyayı `/content/drive/MyDrive/...` yolundan okumaktır. Bağlanmadan yalnız dosya adıyla okunan dosya, çalışma dizininde (yüklenmiş ya da kodla oluşturulmuş) olmalıdır.

### 11.2 head, tail, describe ve sütun adları

- `data.head(10)` ilk 10 satırı (0-9), `data.tail(10)` son 10 satırı gösterir (02:16:40).
- `data.describe()` veriyle ilgili genel bilgileri verir (02:17:02).
- Sütun adları değiştirilebilir: `data.columns = [...]` ile sepal/petal adları A, B, C, D, sınıf sütunu da `class` yapıldı (02:17:33).

<!-- BELİRSİZ: 02:15:00 karesinde describe hücresi `print(data.describe)` (parantezsiz) yazılmış ve bound method çıktısı vermiş görünüyor; hocanın 02:17:21'deki "150 satır, 5 kolon" açıklaması bu çıktının sonundaki boyut bilgisine dayanıyor olabilir. -->

### 11.3 iloc ve loc ile seçim

Pandas'ta veri seçmenin iki yolu vardır: satır/sütun numarasıyla ve etiketle (02:18:22).

**iloc (numarayla):**

- `data.iloc[0]` ilk satır, `data.iloc[1]` ikinci satır, `data.iloc[-1]` son satırdır. Python'da eksi indeksler sondan sayar (02:18:34).
- `data.iloc[:, 0]` ilk sütunun tamamı, `data.iloc[:, 1]` ikinci sütun, `data.iloc[:, -1]` son sütundur (02:19:02).
- `data.iloc[0, 3]` 0. satırın 3. sütunudur (0'dan sayıldığı için dördüncü sütun) (02:19:20).
- `data.iloc[0:5, 1:3]` 0-4. satırlar ile 1. ve 2. sütunlardır (02:19:44).

**loc (etiketle):** sütun adlarıyla ve koşullarla seçim yapılır (02:20:08).

- `data.loc[data['b'] == 1.4]`: B sütunu 1.4'e eşit olan satırları getirir.
- `data.loc[data['b'] > 1.4, ['b', 'c', 'd']]`: B'si 1.4'ten büyük olan satırların yalnız B, C, D sütunlarını getirir. Sütun listesi verilmezse bütün sütunlar gelir (02:20:56).
- Başka bir örnekte, ID'si 100'den büyük ve 200'den küçük satırların yalnız iki sütununu getiren bileşik bir koşul gösterildi (02:22:30).

<!-- BELİRSİZ: loc ile yazılan kodların tam hali karelerde yalnız kısmen görünüyor (02:20:00 karesinde `data.set_index("d", inplace=True)` ve `data.loc["setosa"]`); yukarıdaki ifadeler altyazıdaki anlatımdan kuruldu. 02:22:03'teki "first name" örneği altyazıda anlaşılmıyor. -->

Veri çok büyük olduğunda Excel'de aşağı kaydırarak bakmak mümkün olmadığı için veriyi analiz ederken bu tür komutlar kullanılır (02:22:53).

## 12. scikit-learn ile Karar Ağacı Sınıflandırması

### 12.1 scikit-learn ve iş akışı

scikit-learn, karar ağaçları, random forest, Naive Bayes gibi derste görülen birçok makine öğrenmesi yöntemini içeren kütüphanedir (02:23:06). İş akışı şöyledir (02:23:35):

- Veri Pandas ile okunur, incelenir ve temizlenir; bir DataFrame'e konur.
- Veri eğitim (train) ve test kümelerine ayrılır.
- scikit-learn'deki seçilen yöntemle model kurulur ve test edilir.

### 12.2 Verinin yüklenmesi

Defterdeki kod (ekrandan, 02:25:00):

```python
# pandas import et
import pandas as pd
# ... iris zaten var olduğu için doğrudan yükleyebiliriz
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split

data = load_iris()

# dataframe oluştur
df = pd.DataFrame(data.data, columns=data.feature_names)
print(df.head())
print("\n\n")
print(df.describe())
print("\n\n")
df['target'] = data.target
# class nameleri bastır
print(data.target)
```

<!-- BELİRSİZ: 02:25:00 karesinde 2-5. satırların bir kısmı açılır pencereyle örtülü; `from sklearn.datasets import load_iris` satırı görünen "_iris" ve "rt train_test_split" parçalarından ve altyazıdan tamamlandı. -->

scikit-learn'de en çok kullanılan veri kümeleri hazır gelir; Iris de `load_iris()` ile yüklenir. Bu zorunlu değildir; `read_csv` ile de okunabilir (02:24:12). DataFrame kurulurken `feature_names` (sepal length, sepal width, petal length, petal width) sütun adı yapıldı. `head()` çıktısındaki ilk satırlar (ekrandan, 02:25:00):

| | sepal length (cm) | sepal width (cm) | petal length (cm) | petal width (cm) |
|---|---|---|---|---|
| 0 | 5.1 | 3.5 | 1.4 | 0.2 |
| 1 | 4.9 | 3.0 | 1.4 | 0.2 |
| 2 | 4.7 | 3.2 | 1.3 | 0.2 |
| 3 | 4.6 | 3.1 | 1.5 | 0.2 |
| 4 | 5.0 | 3.6 | 1.4 | 0.2 |

`describe()` istatistiksel özeti verir: her sütunun sayısı, minimumu, maksimumu ve çeyrekleri (%25, %50, %75; %50 medyandır). Hoca bunun, proje raporundaki "istatistiksel analiz" kısmında istenen türden bilgi olduğunu söyledi (02:25:41). Iris'te sınıflar `target` adıyla tutulur ve 0, 1, 2 olmak üzere üç sınıf vardır (02:26:07).

### 12.3 Eğitim ve test kümelerine ayırma

Veri elle de ayrılabilir: örneğin ilk 120 satır eğitim, 121-150 arası test. Ama scikit-learn'ün `model_selection` modülünde rastgele ayıran hazır bir fonksiyon vardır: `train_test_split` (02:26:32).

```python
X_train, X_test, Y_train, Y_test = train_test_split(
    df[data.feature_names], df['target'], test_size=0.2, random_state=42)
```

<!-- BELİRSİZ: `train_test_split` satırının tam yazımı karelerde görünmüyor; parametreler altyazıdan (öznitelik sütunları, target, test oranı, random_state 42) kuruldu. Değişken adlarının büyük-küçük harfi 02:30:00 ve 02:35:00 karelerindeki `Y_test`, `X_test` yazımına göre seçildi. -->

İlk parametre öznitelikler (`feature_names` sütunları), ikincisi sınıflar (`target`) idi. Önce test oranı %10 verilmişti; hoca bunu %20 yaptı, yani verinin %80'i eğitime, %20'si teste ayrıldı. `random_state`, rastgele seçim için kullanılan tohumdur; 42 ya da başka bir değer verilebilir (02:27:15).

Sonuçların boyutları (02:27:52):

- `X_train.shape` → (120, 4)
- `X_test.shape` → (30, 4)
- `Y_test.shape` → (30,): sondaki boş boyut "1" demektir; bu, 30 elemanlı bir vektördür.

`X_train` ve `X_test` öznitelikleri (sepal length, sepal width vb.), `Y_train` ve `Y_test` sınıf etiketlerini (0, 1, 2) tutar (02:30:12).

`print(Y_test)` çıktısı (ekrandan, 02:30:00); solda asıl verideki satır indeksi, sağda sınıf vardır:

```text
73 1    18 0    118 2   78 1    76 1    31 0
64 1    141 2   68 1    82 1    110 2   12 0
36 0    9 0     19 0    56 1    104 2   69 1
55 1    132 2   29 0    127 2   26 0    128 2
131 2   145 2   108 2   143 2   45 0    30 0
```

Rastgele seçim ilk olarak 73. satırı, sonra 18. satırı test kümesine almıştır. Hoca sınıf dağılımını saydı: 10 tane 0 ve 11 tane 2 vardı; geriye 9 tane 1 kalır. Sınıflar yaklaşık eşit dağılmıştır (02:29:12).

### 12.4 Karar ağacı modeli

```python
from sklearn.tree import DecisionTreeClassifier
clf = DecisionTreeClassifier(max_depth=2, random_state=...)
clf.fit(X_train, Y_train)
```

<!-- BELİRSİZ: Model hücresinin tam kodu karelerde görünmüyor; `max_depth=2` ve `random_state` parametreleri ile `fit` çağrısı altyazıdan (02:30:49-02:32:00) kuruldu, random_state değeri bilinmiyor. -->

Karar ağacının birçok parametresi vardır; örneğin ağacın en büyük derinliği (`max_depth`). Hoca derinliği 2 seçtiğini, çünkü zaten 4 özniteliğin bulunduğunu söyledi (02:30:57).

> **Hocanın vurgusu:** `sklearn.tree`'den karar ağacını seçtiğiniz gibi Naive Bayes, Random Forest, AdaBoost da bu kütüphanededir. Hangi yöntemi seçerseniz seçin, parametrelerinin neler olduğuna mutlaka bakın (02:31:10).

Eğitim fonksiyonu `fit`'tir: model, 120 eğitim örneğinin öznitelikleri (`X_train`) ve sınıflarına (`Y_train`) uydurulur. Model `clf` nesnesinin içinde tutulur (02:31:32).

### 12.5 Tahmin ve doğruluk

- `clf.predict(X_test.iloc[[0]])` gibi bir çağrıyla test kümesinin ilk satırı tahmin edildi. Sonuç `array([1])` çıktı; ilk test örneğinin gerçek sınıfı da 1 idi, tahmin doğru oldu (02:32:23).
- 10 numaralı test satırı için tahmin 2 çıktı (02:33:35).
- `clf.predict(X_test)` bütün 30 test örneğinin tahminini verir (ekrandan, 02:35:00):

```text
array([1, 0, 2, 1, 2, 0, 1, 2, 1, 1, 2, 0, 0, 0, 0, 1, 2, 1, 1, 2, 0, 2,
       0, 2, 2, 2, 2, 2, 0, 0])
```

<!-- BELİRSİZ: 02:32:23-02:33:35 arasındaki tek satır tahmin kodunun tam yazımı karelerde görünmüyor. -->

Doğruluk için hazır `score` fonksiyonu vardır (ekrandan, 02:35:00):

```python
# modelin doğruluğu
# The score method returns the accuracy of the model
score = clf.score(X_test, Y_test)
print(score)
# (ekranda görünen çıktı için aşağıdaki BELİRSİZ notuna bakın)
```

`score`, `X_test` için tahminleri kendisi üretir ve bunların kaçının `Y_test` ile aynı olduğuna bakar. Hoca çalıştırdığında sonucun "0.96 gibi bir şey" çıktığını söyledi (02:35:10). Ekrandaki tahmin dizisi 02:30:00 karesindeki `Y_test` ile karşılaştırılınca yalnız 5. sıradaki örnekte (indeks 76, gerçek sınıf 1, tahmin 2) hata vardır; yani 30 örneğin 29'u doğrudur ve doğruluk $29/30 \approx 0{,}9667$ olur (ara adım eklendi). Bu, hocanın söylediği değerle uyumludur.

<!-- BELİRSİZ: 02:35:00 karesinde score hücresinin altında 0.9333333333333333 (28/30) yazıyor; tahmin dizisiyle uyuşmadığı için bu çıktı büyük olasılıkla hücre yeniden çalıştırılmadan önceki eski bir çıktıdır. Not, tahmin dizisine ve hocanın okuduğu değere göre yazıldı. -->

### 12.6 max_depth'i döngüyle değiştirmek

Bir sonraki hücrede `max_depth` bir döngüyle 1'den 5'e kadar değiştirildi; her değerde ağaç yeniden eğitildi (`clf.fit`) ve doğruluğu yazdırıldı (02:35:18).

- Derinlik 1 (yalnız kök): doğruluk yaklaşık 0.63 (02:35:58).
- Derinlik 4 ve 5: doğruluk %100 (02:36:11).

Ardından tek modelde `max_depth=5` verilip `score` yeniden hesaplandı; gerçekten %100 çıktı (02:36:21).

<!-- BELİRSİZ: Derinlik 2 ve 3 için döngünün yazdırdığı değerler altyazıda okunmuyor ve karelerde görünmüyor. -->

Hoca, işin zor olmadığını, her şeyin kütüphanede hazır bulunduğunu, önemli olanın hangi yöntemin seçileceği olduğunu söyledi. Hata çıktığında Colab'in sunduğu "Search Stack Overflow" düğmesiyle hatanın ne olduğuna bakılabilir (02:36:39).

## 13. Meyve Sınıflandırma Örneği ve Proje Üzerine Sorular

### 13.1 Meyve sınıflandırma örneği

Hoca vakit yetmediği için ayrıntısını göstermediği, ama çok iyi bulduğu bir internet öğreticisini tanıttı (02:37:09). Veri, CSV değil bir tablo olarak verilmiştir: meyvelerin etiketi, adı, kütlesi, boyutları, renk puanı gibi 7 özniteliği vardır ve 59 meyve (satır) bulunur (02:37:20). Öğreticide yapılanlar:

- **Seaborn** ile görselleştirme. Seaborn, Matplotlib'e göre daha estetik şekiller çizmeyi sağlar. Meyve türlerinin (apple, mandarin, orange, lemon) sayılarını gösteren histogram, kutu grafikleri (box plot), histogramdaki bin sayısının etkisi ve öznitelikler arası korelasyonu gösteren dağılım grafikleri (scatter plot) çizilmiştir (02:37:47).
- `describe` ile istatistikler.
- `train_test_split` ile eğitim/test ayrımı ve `MinMaxScaler` ile ölçekleme. Hoca bunun, verinin minimum ve maksimum değerleri arasında ölçeklenmesi olduğunu hatırlattı (02:38:58).
- `DecisionTreeClassifier`, `sklearn.neighbors`'tan kNN, Gaussian Naive Bayes ve destek vektör makinesi (SVM) ile sınıflandırma (02:38:58).
- `confusion_matrix` ve `classification_report`: precision, recall ve F1 skoru (02:39:26).

Ekrandaki kNN sonuçları (ekrandan, 02:40:00):

```python
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix
pred = knn.predict(X_test)
print(confusion_matrix(y_test, pred))
print(classification_report(y_test, pred))
```

```text
[[4 0 0 0]
 [0 1 0 0]
 [0 0 8 0]
 [0 0 0 2]]
             precision    recall  f1-score   support
          1       1.00      1.00      1.00         4
          2       1.00      1.00      1.00         1
          3       1.00      1.00      1.00         8
          4       1.00      1.00      1.00         2
avg / total       1.00      1.00      1.00        15
```

<!-- BELİRSİZ: 02:40:00 karesinde `pred = knn.p...` satırının ortası bir paylaşım düğmesiyle örtülü; `predict(X_test)` biçiminde tamamlandı. -->

Karışıklık matrisi köşegendir: 15 test örneğinin hepsi doğru sınıflanmıştır. Hoca bu örneğin bağlantısını paylaşacağını ve öğrencilerin kendilerinin çalıştırmasını istedi; bunu yapanların proje işinin büyük kısmını halledebilecek seviyeye geleceğini söyledi (02:39:54, 02:44:39).

### 13.2 Proje üzerine akademik sorular

**Soru:** Analiz raporunda "veri madenciliği ile araştırılacak ilişki" ile "kullanılacak yöntem" maddelerinin farkı nedir? (02:03:21)
**Cevap:** Veriye göre sınıflandırma, sürekli bir değerin tahmini (regresyon) ya da kümeleme yapılabilir. İlk maddede hangisinin yapılacağı açıklanır. İkincide kullanılacak üç yöntem söylenir; örneğin Random Forest, AdaBoost ve Naive Bayes.

**Soru:** Raporda "veri setinin istatistiksel analizi" ile ne kastediliyor? (02:13:53)
**Cevap:** Her özniteliğin minimumu, maksimumu, medyanı gibi değerleri; box plot gibi grafikler. Bunlardan gürültü ve verinin dağılımı çıkarılabilir; veri temizliği buna göre planlanır. Raporda "temizleyeceğim" denmez; temizleyebilmek için istatistiksel analiz yapılır.

**Soru:** Projede sayısal değer değil yalnız kelimelerle sınıflandırma varsa istatistikler nasıl gösterilir? (02:40:34)
**Cevap:** Metin verisinde her kelimenin kaç kez geçtiğine bakılır. Temizlemede bağlaçlar ve "ve", "veya" gibi kelimeler atılır; hangi kelimelerin atılacağına karar verilir. Çok az geçen kelimeler için bir eşik (örneğin 3-4) belirlenir ve o eşiğin altındakiler atılır. Raporda sayım yapılmasa bile bunun nasıl yapılacağı yazılmalıdır.

**Soru:** OpenCV'de Haar cascade ile nesne tanıma yapılıyor; doğruluk nasıl artırılabilir? (02:43:08)
**Cevap:** Cascade, iyi çalışmayan aşamaları eleyerek ilerler; eğitim biraz daha uzun yapılabilir (aşama sayısı gibi). Ayrıca nesne tanımada HOG yöntemi vardır; Haar'dan daha yavaş çalışır ama doğruluğu genelde daha iyidir. Hoca kesin bir şey söylemenin probleme bağlı olduğunu belirtti.

<!-- BELİRSİZ: 02:43:08-02:44:17 arasındaki soru-cevabın altyazısı bozuk ("harikas", "harap asker"); Haar cascade ve HOG olarak yorumlandı. -->

## Örnek Sorular

### Soru 1 (ekrandan, 00:15:00)

Eğitim verisi: (A=1, B=1, no), (2, 1, no), (3, 2, yes), (7, 7, yes), (8, 8, yes). $\langle 3,3\rangle$ örneğini 1-NN ve 3-NN ile Öklid uzaklığı kullanarak sınıflandırın.

**Çözüm (derste verildi):** Uzaklıklar sırasıyla $\sqrt{8}$, $\sqrt{5}$, $\sqrt{1}$, $\sqrt{32}$, $\sqrt{50}$. 1-NN: en yakın (3,2) → **yes**. 3-NN: en yakın üç örnek (3,2) yes, (2,1) no, (1,1) no; çoğunluk → **no**.

### Soru 2 (ekrandan, 00:20:00)

Aynı veriyle $\langle 3,3\rangle$ örneğini uzaklık ağırlıklı 3-NN ile ($w = 1/d^2$) sınıflandırın.

**Çözüm (derste verildi):** no ağırlığı $1/8 + 1/5 = 13/40$; yes ağırlığı $1/1 = 1$. $1 > 13/40$ olduğu için sonuç **yes**.

### Soru 3 (derste sözlü, 00:21:00)

İki öznitelikli, 3 yes ve 2 no sınıflı beş örnekli bir veride $\langle 5,5\rangle$ örneğini 3-NN ve uzaklık ağırlıklı 3-NN ile sınıflandırın.

<!-- BELİRSİZ: Veri tablosu karelerde yok; altyazıya göre en yakın üç komşu $\sqrt{10}$ (yes), $\sqrt{5}$ (yes) ve 1 (no, (6,5) noktası) uzaklıklıdır. -->

**Çözüm (derste verildi):** Ağırlıksız 3-NN: iki yes, bir no → **yes**. Ağırlıklı: yes $1/10 + 1/5 = 3/10$, no $1/1 = 1$ → **no**. (Hoca yes ağırlığını "3/15 gibi" diye söyledi; doğrusu $3/10$'dur.)

### Soru 4 (derste sözlü, 00:27:56)

kNN test zamanında büyük veri kümelerinde çok yavaş çalışır. Bunu hızlandırmak için ne yapılabilir?

**Çözüm (derste verildi):** Veri uzayı ızgaralara (örneğin 3×3) bölünür ve her hücre için özet bilgi tutulur. Sorgu geldiğinde önce hangi hücreye düştüğü bulunur, sonra yalnız o bölgedeki örneklerle uzaklık hesaplanır. Bunun için verinin özniteliklere göre sıralı tutulması gerekir.

### Soru 5 (ekrandan, 00:50:00)

`a = np.array([[3., 0.], [20., 230.], [21., 275.]])` için `b = a.reshape(2,3)` ve `a.resize(2,3)` işlemlerinin farkı nedir? `a.sum(axis=0)` ne döndürür?

**Çözüm (derste verildi):** `reshape` yeni şekilli diziyi döndürür (`[[3, 0, 20], [230, 21, 275]]`), `a` 3×2 olarak kalır. `resize` ise `a`'nın kendisini 2×3 yapar. `a.sum(axis=0)` (3×2 halindeyken) sütun toplamlarını verir: $[44, 505]$.

### Soru 6 (ekrandan, 01:20:00)

`s = pd.Series([3, 20, 21], index=['Bei Bei', 'Mei Xiang', 'Tian Tian'])` ve `u = pd.Series([230., 275.], index=['Mei Xiang', 'Tian Tian'])` için `s.add(u)` ve `s.add(u, fill_value=0)` ne verir?

**Çözüm (derste verildi):** `s.add(u)`: Bei Bei NaN, Mei Xiang 250.0, Tian Tian 296.0. `fill_value=0` ile: Bei Bei 3.0, Mei Xiang 250.0, Tian Tian 296.0.

### Soru 7 (ekrandan, 02:30:00 ve 02:35:00)

Iris test kümesinin gerçek sınıfları `[1,0,2,1,1,0,1,2,1,1,2,0,0,0,0,1,2,1,1,2,0,2,0,2,2,2,2,2,0,0]`, derinliği 2 olan karar ağacının tahminleri `[1,0,2,1,2,0,1,2,1,1,2,0,0,0,0,1,2,1,1,2,0,2,0,2,2,2,2,2,0,0]` ise modelin doğruluğu nedir?

**Çözüm (derste verilmedi):** Yalnız 5. örnekte (gerçek 1, tahmin 2) hata vardır. Doğruluk $29/30 \approx 0{,}9667$ (python ile sayıldı). Hoca derste sonucu "0.96 gibi" diye okudu.

## Dersin Toparlaması

Bu derste model kurmadan sınıflandırma yapan örnek tabanlı öğrenme ve onun en bilinen yöntemi kNN görüldü. kNN'de test örneğine Öklid uzaklığıyla en yakın $k$ eğitim örneği bulunur ve sınıfları oylanır. $\langle 3,3\rangle$ örneğinde 1-NN ile 3-NN farklı sonuç verdi. En yakın komşunun daha uzaktakiler tarafından ezilmesini önlemek için oyların $1/d^2$ ile ağırlıklandırıldığı uzaklık ağırlıklı kNN anlatıldı. $k$'nın seçimi, özniteliklerin normalize edilmesi ve test zamanının maliyeti kNN'nin başlıca sorunları olarak vurgulandı.

Dersin ikinci yarısında NumPy'ın `ndarray` yapısı (sabit boyut, tek tip, view davranışı, reshape/resize) ve Pandas'ın Series ve DataFrame yapıları (indeks, NaN, hizalamalı toplama, mantıksal indeksleme, eksik veri fonksiyonları, CSV okuma-yazma, groupby, kategorik veri) incelendi. Son olarak Colab'de Iris verisi Pandas ile okunup `iloc`/`loc` ile seçimler yapıldı, scikit-learn ile veri eğitim ve test kümelerine ayrılıp karar ağacı eğitildi ve doğruluğu ölçüldü; ağaç derinliğinin doğruluğa etkisi gösterildi. Öğrencilerden meyve sınıflandırma öğreticisini kendilerinin çalıştırması istendi. Hoca bir sonraki derste yapay sinir ağlarına geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
