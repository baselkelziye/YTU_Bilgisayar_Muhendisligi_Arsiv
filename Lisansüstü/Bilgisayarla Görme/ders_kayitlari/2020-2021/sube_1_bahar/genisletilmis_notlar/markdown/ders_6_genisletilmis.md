# Ders 6 Genişletilmiş Notu: Hough Dönüşümü, Daugman'ın İntegro-Diferansiyel Operatörü ve İki Boyutlu Dönüşümler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. LoG Filtresinde Sıfır Geçişi ve Katsayıların Normalizasyonu
- 2. Dersin Yeri: Klasik Algoritmalardan Derin Öğrenmeye
- 3. Hough Dönüşümüne Giriş
- 4. Hesse Normal Formu
- 5. Hough Uzayı ve Akümülatör Matrisi
- 6. Hough ile Çember Bulma
- 7. Daugman'ın İntegro-Diferansiyel Operatörü
- 8. İris Bölütlemede Uygulama Ayrıntıları
- 9. İki Boyutlu Dönüşümler ve Eşleştirme
- 10. Bir Nokta Etrafında Döndürme Örneği
- 11. Görüntü Düzleminden Dünya Düzlemine Dönüşüm
- Örnek Sorular
- Dersin Toparlaması

## 1. LoG Filtresinde Sıfır Geçişi ve Katsayıların Normalizasyonu

Ders, önceki haftalarda görülen Laplacian of Gaussian (LoG) filtresiyle ilgili sorularla başladı. Hoca, birinci ve ikinci türevin, konvolüsyon ve korelasyonun anlatıldığı derse geri dönerek sıfır geçişi (zero crossing) kavramını hatırlattı.

Bir görüntüde kenar, parlaklığın ani bir basamakla ya da bir rampa biçiminde değiştiği yerdir. Bu geçişin ikinci türevi alındığında, kenarın bir yanında negatif, öbür yanında pozitif değerler oluşur. Negatiften pozitife (ya da pozitiften negatife) geçiş sıfır geçişi diye adlandırılır. Her kenar aslında geçişin başladığı ve bittiği noktalarda iki ayrı tepe üretir; sıfır geçişi bu ikisinin arasındadır ve kenarın tam yerini gösterir.

Uygulamada görüntü LoG maskesiyle konvolüsyona sokulur. Konvolüsyonun çıktısına bir sıfır geçişi işlemi uygulanır ve işaretin değiştiği pikseller kenar olarak işaretlenir. Sonuç, kenarların beyaz, arka planın siyah olduğu ikili (binary) bir görüntüdür. Sıfır geçişini bulmak için hazır fonksiyonlar kullanılabilir.

Bir öğrenci, farklı $\sigma$ değerleri için LoG fonksiyonundan maske ürettiğinde katsayıların derste gösterilen tamsayı maskelerdeki gibi çıkmadığını sordu.

**Soru:** $\sigma$ değerlerine göre formülden hesaplanan LoG katsayıları tamsayı çıkmıyor; bu normal mi? **Cevap:** Katsayıların birebir aynı ya da tamsayı çıkması beklenmez. Katsayılar toplamları 1 olacak biçimde normalize edilebilir; sayılar çok küçük kalıyorsa toplam 100 olacak biçimde ölçeklenip yuvarlanabilir. Asıl önemli olan, katsayılardan oluşan şekli çizdirip derste görülen biçime benzediğini görmektir. Şekil benziyorsa değerlerin farklı olması sorun değildir; fark büyük olasılıkla normalizasyondan gelir.

Histogram ve histogram eşitleme için de hoca şu ilkeyi vurguladı: temel işlemlerin kodunu ilk seferde kendiniz yazarsanız işlemin nasıl yapıldığını en iyi o zaman anlarsınız; ondan sonra hazır fonksiyonlar kullanılabilir.

## 2. Dersin Yeri: Klasik Algoritmalardan Derin Öğrenmeye

Bu hafta Hough dönüşümü ve iki boyutlu dönüşümler işlenecek, bir sonraki hafta köşe bulma (corner detection) ve HOG (Histogram of Oriented Gradients) gibi öznitelik çıkarma (feature extraction) algoritmaları gelecektir. Bu iki haftayla klasik bilgisayarla görmenin temel algoritmaları tamamlanmış olur. Sonraki haftalarda yapay sinir ağları ve derin öğrenme ile bilgisayarla görmeye geçilecektir.

> **Hocanın vurgusu:** Klasik algoritmalar çok önemlidir. Belli bir algoritma yapısı içinde ileride işe yarayacak fikirleri kazandırır. Bu yüzden bu bölümden vazgeçilmez ve klasik algoritmalara beş altı hafta ayrılır.

## 3. Hough Dönüşümüne Giriş

Dersin ilk slaydı konu başlıklarını veriyor (ekrandan, 00:25:00):

- Hough dönüşümünün üstünlükleri (Advantages of Hough Transform)
- Doğru bulmada Hough dönüşümü (Hough Transform for Straight Line Detection)
- Çember bulmada Hough dönüşümü (Hough Transform for Circle Detection)
- İntegro-diferansiyel operatör (Integro Differential Operation)

Daha önce kenar bulma (edge detection) yapıldı ve kenar noktaları elde edildi. Şimdi sorulan soru şudur: bu kenar noktaları bir doğru, bir eğri ya da bir çember oluşturuyor mu, oluşturuyorsa bu şeklin denklemi nedir? Hough dönüşümü bu soruya cevap verir.

### 3.1 Ön koşul: kenar görüntüsü

Hough dönüşümü doğrudan gri seviyeli görüntüye uygulanmaz. Önce bir kenar bulma algoritması çalıştırılır ve kenar noktalarının işaretlendiği ikili bir görüntü elde edilir. Hough dönüşümü bu ikili görüntü üzerinde çalışır (slayttaki ifadeyle "performed after edge detection").

Yöntem bir görüntüdeki belli bir biçimdeki eğrileri ayırmaya yarar. İki şekilde kullanılabilir: verilmiş bir şeklin kenarlarını bulmak ya da görüntüde verilen bir şekli aramak. Doğru, çember, parabol ya da elips biçimli şekiller bulunabilir. Daha genel biçimi Genelleştirilmiş Hough Dönüşümü (Generalized Hough Transform) adını alır.

### 3.2 Üstünlükler

Slaytta üç üstünlük sayılıyor (ekrandan, 00:30:00):

- **Kenardaki boşluklara dayanıklıdır (tolerant of gaps in the edges).** Kenar bulma sonrasında kenar üzerinde kopukluklar olabilir: bazı noktalar çıkmamış, arada bir iki nokta var, devamı yok. Bu durumda bile, var olan noktalar bir doğru üzerindeyse yöntem o doğrunun denklemini verir.
- **Gürültüden görece az etkilenir (relatively unaffected by noise).** Doğrunun çevresinde rastgele birkaç gürültü noktası bulunabilir. Bunlar az sayıda olduğu için doğrunun bulunmasına zarar vermez.
- **Örtülmeden etkilenmez (unaffected by occlusion).** Görüntüde doğrunun bir parçasının önüne başka bir cisim gelmiş ve o parça görünmüyor olabilir. Yöntem buna karşı da dayanıklıdır.

## 4. Hesse Normal Formu

### 4.1 Neden yeni bir gösterim?

Doğru denklemi genelde $y = mx + c$ biçiminde yazılır. Ancak bu gösterim dikey doğrular için çalışmaz; dikey doğrunun eğimi tanımsızdır (ekrandan, 00:45:00). Hough dönüşümüyle doğru bulunurken bu yüzden Hesse normal formu (Hesse Normal Form) denen bir gösterim kullanılır:

$$x\cos\theta + y\sin\theta = r$$

Burada $r$ (bazı kaynaklarda $\rho$ ya da $p$) doğruya orijinden çizilen dikmenin uzunluğu, $\theta$ ise bu dikmenin yatay eksenle yaptığı açıdır.

### 4.2 Türetme

Hoca formülü kalemle çizerek türetti (ekrandan, 00:40:00). xy düzleminde bir $l_1$ doğrusu çizilir. Doğru x eksenini $A$, y eksenini $B$ noktasında kessin. Orijin $O$'dan doğruya bir dikme indirilir; dikmenin doğruyu kestiği nokta $L$, dikmenin uzunluğu $p$, dikmenin x ekseniyle yaptığı açı $\alpha$ olsun.

**$OLA$ üçgeni.** $L$'deki açı 90°'dir. $\alpha$ açısının kosinüsü komşu dik kenarın hipotenüse oranıdır:

$$\cos\alpha = \frac{p}{OA} \quad\Rightarrow\quad OA = \frac{p}{\cos\alpha}$$

**$OLB$ üçgeni.** $B$ köşesindeki açı $90° - \alpha$'dır. $L$'deki açı 90° olduğundan $O$'daki açı yine $\alpha$'dır (derste öğrencilere soruldu, cevap "alfa" oldu). Bu açının sinüsü:

$$\sin\alpha = \frac{p}{OB} \quad\Rightarrow\quad OB = \frac{p}{\sin\alpha}$$

**Doğru denklemi.** x eksenini $a$'da, y eksenini $b$'de kesen doğrunun denklemi $\frac{x}{a} + \frac{y}{b} = 1$'dir. $a = OA$, $b = OB$ yazılırsa:

$$\frac{x}{p/\cos\alpha} + \frac{y}{p/\sin\alpha} = 1 \quad\Rightarrow\quad \frac{x\cos\alpha + y\sin\alpha}{p} = 1 \quad\Rightarrow\quad x\cos\alpha + y\sin\alpha = p$$

Böylece doğru, üzerindeki her $(x, y)$ noktası için aynı kalan iki parametreyle, $\alpha$ (ya da $\theta$) açısı ve $p$ (ya da $r$) uzaklığıyla tanımlanmış olur. Slayttaki çizimde doğru üzerindeki 1, 2 ve 3 numaralı noktaların hepsi aynı $r$ ve $\theta$ değeriyle ifade edilir.

Hoca, alıştırma olarak $\theta = 45°$ ve $\rho = 2$ gibi değerler seçip doğruyu çizmeyi ve x ile y eksenlerini kestiği noktaları bulmayı önerdi (bkz. Örnek Sorular).

## 5. Hough Uzayı ve Akümülatör Matrisi

### 5.1 Oylama fikri

Slaytın sol tarafında özgün koordinat düzlemi (original coordinate plane), sağ tarafında Hough düzlemi (Hough plane) var (ekrandan, 00:45:00). Hough düzleminde eksenler $\theta$ ve $\rho$'dur.

Kenar bulmadan sonra elimizde kenar noktaları vardır ve amaç bu noktaların oluşturduğu doğru parçalarının denklemini bulmaktır. Bunun için şu yapılır (ekrandan, 00:50:00):

1. Doğru üzerindeki her noktadan (örneğin 1, 2, 3 numaralı noktalardan) her yönde doğru geçebileceği düşünülür.
2. 1 numaralı noktadan geçen her doğrunun farklı bir $\theta$ ve $\rho$ değeri vardır. Bu değerler Hough düzleminde bir eğri çizer.
3. 2 ve 3 numaralı noktalar için de onlarca, yüzlerce doğru geçirilir; her biri Hough düzleminde kendi eğrisini oluşturur.
4. Bu değerler akümülatör matrisi (accumulator matrix) denen iki boyutlu bir matriste toplanır: geçirilen her doğru, $(\theta, \rho)$ değerine karşılık gelen göze bir oy (vote) atar.
5. Üç nokta aynı doğru üzerinde olduğu için, o doğrunun $(\theta, \rho)$ değerinde üç eğri kesişir. Bu göz üç oy alır.
6. Sonunda akümülatördeki en büyük değerli göz aranır. Bu gözün $\theta$ ve $\rho$ değerleri çizilecek doğrunun parametreleridir.

### 5.2 Parametrelerin sınırlı olması

Yöntemin bir üstünlüğü $\rho$ ve $\theta$'nın sınırlı (bounded) olmasıdır:

- $\theta$ 0° ile 180° arasında değişir. Birer derecelik adımlarla taranırsa akümülatörde $\theta$ için 180 farklı değer olur.
- Görüntünün eni ve boyu bilindiği için, orijinden bir doğruya olan uzaklık en fazla görüntünün ana köşegeni kadar olabilir. En kötü durum için $\rho$'nun üst sınırı köşegen uzunluğu alınır.

### 5.3 Sakınca

Görüntüdeki her noktadan yüzlerce doğru geçirip bu analizi yapmak yüksek işlem yükü demektir. Yöntem çok yavaş çalışır; doğru ya da çember bulmada hızlı bir yöntem olduğu söylenemez.

### 5.4 Wikipedia örneği

Hoca bu örneği Wikipedia'daki Hough dönüşümü sayfasından aldığını ve çok sevdiğini söyledi (ekrandan, 00:55:00). Slayttaki ifade: "Consider three data points, shown here as black dots." Pembe bir doğru üzerinde üç siyah nokta vardır. Akümülatörde $\theta$ 30°'lik adımlarla taranır: 0, 30, 60, 90, 120, 150, yani altı açı değeri vardır. Her nokta ve her açı için doğrunun uzaklığı (distance, yani $\rho$) $\rho = x\cos\theta + y\sin\theta$ ile hesaplanır.

| Açı (°) | 1. nokta | 2. nokta | 3. nokta |
|---|---|---|---|
| 0 | 40 | 57.1 | 74.6 |
| 30 | 69.6 | 79.5 | 89.6 |
| 60 | 81.2 | 80.5 | 80.6 |
| 90 | 70 | 60 | 50 |
| 120 | 40.6 | 23.4 | 6.0 |
| 150 | 0.4 | −19.5 | −39.6 |

Örneğin birinci noktadan $\theta = 0°$ ile geçen doğrunun dikmesi yatay eksen üzerindedir ve uzaklığı 40'tır; $\theta = 30°$ için 69.6, $\theta = 60°$ için 81.2 bulunur. Diğer iki nokta için de aynı hesaplar yapılır.

Dikkat edilecek nokta, 60° satırında üç noktanın uzaklıklarının hep 80 dolayında çıkmasıdır (yuvarlama hataları nedeniyle tam eşit değil). Sonraki slaytta yatay eksende açı, dikey eksende uzaklık olan bir grafik çizilmiştir (ekrandan, 01:00:00). Üç eğri $\theta = 60°$, $\rho \approx 80$ noktasında kesişir. Slayttaki açıklamaya göre eğrilerin kesiştiği nokta, test edilen noktalardan geçen doğrunun uzaklığını ve açısını verir; bu nokta üç noktadan da geçen pembe doğruya karşılık gelir. Akümülatörde bu gözde biriken değer en büyük olur.

> **Ders sonrası not:** Birinci noktanın tablosundan $x = 40$ ($\theta = 0°$ satırı) ve $y = 70$ ($\theta = 90°$ satırı) okunur. Bu değerlerle python ile hesaplanan 60° uzaklığı $40 \cdot 0.5 + 70 \cdot 0.866 \approx 80.6$'dır. Slayttaki 81.2 büyük olasılıkla kaynak çizimdeki bir yuvarlama ya da yazım hatasıdır. Tablodaki diğer değerlerin hepsi hesapla uyuşur (ikinci nokta $x = 57.1$, $y = 60$; üçüncü nokta $x = 74.6$, $y = 50$).

### 5.5 Algoritmanın adımları

Hoca algoritmayı şöyle özetledi:

1. Hough uzayını nicemle (quantize the Hough transform space): $\theta$ için 0-180° aralığı istenen hassasiyette bölünür; $\rho$ için sıfırdan ana köşegen uzunluğuna kadar olan aralık alınır.
2. Bu boyutlarda bir akümülatör matrisi oluştur.
3. Her kenar noktası ve her $\theta$ için $\rho$'yu hesapla, ilgili göze oy ver.
4. En çok oy alan gözden doğrunun $(\theta, \rho)$ parametrelerini oku.

## 6. Hough ile Çember Bulma

### 6.1 Çember denklemi ve üç boyutlu akümülatör

Hough dönüşümü çember bulmada da kullanılır. Bunun için çember denklemi kullanılır:

$$(x - a)^2 + (y - b)^2 = r^2$$

$(a, b)$ çemberin merkezi, $r$ yarıçapıdır. Doğruda iki parametre ($\theta$, $\rho$) vardı; çemberde üç parametre olduğu için akümülatör matrisi üç boyutlu olmak zorundadır. Çember üzerindeki her $(x, y)$ noktası bu denklemi sağlar.

Slayttaki örnekte solda özgün bir görüntü, sağda bu görüntüye Canny kenar bulucunun uygulanmasıyla elde edilmiş ikili görüntü var: arka plan siyah (sıfırlar), kenarlar beyaz. Bu ikili görüntüdeki bütün çemberlerin merkezleri ve yarıçapları Hough dönüşümüyle hesaplanabilir.

### 6.2 Python örneği

Python'da `skimage.transform` altında `hough_circle` hazır fonksiyonu vardır. Slayttaki kod (ekrandan, 01:05:00):

```python
from skimage.transform import hough_circle
from skimage.draw import circle_perimeter
import matplotlib.pyplot as plt
import numpy as np

img = np.zeros((100, 100), dtype=np.bool_)
rr, cc = circle_perimeter(25, 35, 23)
img[rr, cc] = 1
print(img.dtype)
print(img.shape)

plt.imshow(img, cmap='gray')
try_radii = np.arange(5, 50)
res = hough_circle(img, try_radii)
ridx, r, c = np.unravel_index(np.argmax(res), res.shape)
r, c, try_radii[ridx]
```

Kodda önce 100×100'lük, sıfırlardan oluşan sentetik bir ikili görüntü tanımlanır. `circle_perimeter(25, 35, 23)` merkezi satır 25, sütun 35 olan ve yarıçapı 23 olan çemberin çevre piksellerini verir; bu pikseller 1 yapılır. `try_radii` Hough dönüşümünün deneyeceği yarıçap aralığıdır: 5'ten 50'ye kadar birer birer. Gerçek yarıçap 23 bu aralığın içindedir. Aralık daraltılırsa yöntem daha hızlı çalışır. `hough_circle` her yarıçap için bir akümülatör katmanı üretir; `np.argmax` en büyük değerli gözü, `np.unravel_index` bu gözün (yarıçap indisi, satır, sütun) indislerini verir.

> **Ek bilgi (derste anlatılmadı):** Kodun son satırı beklenen olarak (25, 35, 23) değerlerini verir. Bu ortamda scikit-image kurulu olmadığı için kod doğrudan çalıştırılamadı; aynı oylama fikriyle numpy'da yazılan basit bir çember Hough uygulaması, bu sentetik görüntüde en büyük oyu merkez (25, 35) ve yarıçap 23'te verdi.

### 6.3 Soru-cevap

**Soru:** Doğrudaki mantık burada da geçerliyse, $a$ ve $b$ değerlerini verip en uygun $r$'yi bulmasını mı bekliyoruz? **Cevap:** Hayır. Akümülatör üç boyutludur ve $a$, $b$, $r$ üçü birden değişir, çünkü çemberin merkezi de bilinmemektedir. $a$ ve $b$ için görüntü boyutlarına göre bir aralık, $r$ için de (örnekte 5 ile 50 arası) bir aralık belirlenir. Görüntüdeki her kenar noktasının $x$ ve $y$ değeri bilinir; "merkezi $(a, b)$ olan, $r$ yarıçaplı bir çember bu noktadan geçer mi" sorusuna göre üç boyutlu matristeki ilgili göze oy atılır. Örnek kodda $a$ ve $b$ açıkça görünmez ama `hough_circle` bunları kendi içinde tarar.

> **Ders sonrası not:** Hoca cevapta $a$ değerinin sıfırdan $100\sqrt{2}$'ye kadar bir aralıkta değişebileceğini söyledi. Merkez koordinatları büyük olasılıkla görüntü sınırları içinde, yani 100×100'lük görüntüde 0 ile 99 arasında taranır; köşegen uzunluğu ($100\sqrt{2} \approx 141.4$) doğru bulmadaki $\rho$ için üst sınırdır.

## 7. Daugman'ın İntegro-Diferansiyel Operatörü

### 7.1 Amaç

Daugman adlı araştırmacının geliştirdiği integro-diferansiyel operatör (Integro-differential Operator, DIO), çembersel Hough dönüşümüne benzer bir yapı kullanır. Biyometrik tanımada kullanılan göz görüntülerinde irisi ve göz bebeğini çevreleyen çemberleri ve üst ile alt göz kapaklarının yaylarını bulmak için geliştirilmiştir (ekrandan, 01:30:00).

Operatör şu formülle verilir:

$$\max_{(r, x_0, y_0)} \left| G_\sigma(r) * \frac{\partial}{\partial r} \oint_{r, x_0, y_0} \frac{I(x,y)}{2\pi r}\, ds \right|$$

Burada $I(x, y)$ göz görüntüsü, $r$ yarıçap, $G_\sigma(r)$ Gauss yumuşatma fonksiyonu, $s$ çemberin çevresidir (ekrandan, 01:35:00).

Formül ilk bakışta bir şey anlatmasa da Hough dönüşümünden sonra adım adım okunabilir.

### 7.2 İçteki integral: çember üzerindeki ortalama parlaklık

Formülün en sağındaki parça bir çevre integralidir. Merkezi $(x_0, y_0)$, yarıçapı $r$ olan bir çember düşünülür. Bu üç parametreyle çemberin üzerinde gezilir ve çember üzerindeki piksellerin parlaklık (intensity) değerleri toplanır; integral burada piksellerin toplamı anlamına gelir. Toplam $2\pi r$'ye, yani çemberin çevre uzunluğuna bölünür. Böylece toplam, çevre uzunluğuna göre normalize edilmiş olur; bu çember üzerindeki ortalama parlaklıktır.

Gözün merkezi ve iris yarıçapı bilinmez. Bu yüzden giriş görüntüsünde her nokta olası bir merkez kabul edilir: merkez bir piksel sağda, bir piksel yukarıda olsaydı diye bütün olası merkezler denenir ve her biri için belli bir yarıçap aralığındaki çemberler üzerinde bu toplam alınır.

Hoca, görüntünün önce bir kenar bulma algoritmasından (örneğin Canny) geçirilip ikili görüntüye dönüştürüldüğü durumu da anlattı. İkili görüntüde arka plan siyah, irisi çevreleyen çember ve kirpikler beyazdır. Çember tam iris sınırına denk gelirse üzerindeki pikseller 255 değerindedir ve toplam çok büyük çıkar.

### 7.3 Yarıçapa göre türev

$\partial/\partial r$ türevi, ardışık yarıçaplardaki toplamların farkıdır. Aynı merkez için $r$ yarıçaplı çemberde bir toplam ($\Sigma_1$), yarıçap bir artırılınca ikinci bir toplam ($\Sigma_2$), bir daha artırılınca üçüncü bir toplam ($\Sigma_3$) alınır. Sonra farklar hesaplanır: $\Sigma_1 - \Sigma_2$, $\Sigma_2 - \Sigma_3$, ...

Bunun neden işe yaradığını görmek için gri seviyeli bir göz görüntüsü düşünülür. İrisin içi koyudur. Çember iris içindeyken toplam küçüktür; yarıçap bir artırılıp çember göz akına (beyaz bölgeye) geçtiğinde toplam birden büyür. Bu yüzden iris sınırında ardışık toplamların farkı en büyük olur. İkili kenar görüntüsünde de durum benzerdir: çember kenarın üzerindeyken toplam çok büyük, yarıçap bir artırılıp siyah arka plana geçildiğinde çok küçüktür.

### 7.4 Gauss yumuşatma ve en büyük değer

Farklar belli yerlerde ani tepeler ya da küçük sıçramalar yapabilir. Bu yüzden farklar $G_\sigma(r)$ Gauss fonksiyonuyla yumuşatılır (smoothing). Bu bir boyutlu bir Gauss maskesidir; ağırlıklı ortalama filtresi gibi düşünülebilir. Örneğin üç katsayılı bir Gauss maskesi farklar dizisi üzerinde gezdirilir ve her fark, bir önceki ve bir sonraki farkla birlikte yumuşatılır. <!-- BELİRSİZ: Hoca örnek maske katsayılarını söyledi; altyazıda "1, 1, 3" geçiyor, bu büyük olasılıkla Whisper bozmasıdır (simetrik bir maske, örneğin 1, 2, 1 beklenir). -->

Son adımda formülün dışındaki $\max$ işlemi, yumuşatılmış farkın mutlak değerinin en büyük olduğu $(r, x_0, y_0)$ üçlüsünü seçer. Bu üçlüyle çizilen çember gözün irisi ile beyazı arasındaki geçişi gösterir (slayttaki sağdaki göz görüntüsü).

İşlem bununla bitmez. İris ile göz bebeğini birbirinden ayırmak için göz bebeği çevresinde ikinci bir çember çizilmesi gerekir; aynı işlem göz bebeği için de yapılır. Biyometrik tanımada önce kullanılacak alanın böyle belirlenmesi gerekir.

## 8. İris Bölütlemede Uygulama Ayrıntıları

### 8.1 UBIRIS veritabanı

Yöntemi denemek için UBIRIS iris veritabanı gösterildi. Veritabanının birkaç sürümü vardır (v1, v2). Hoca bu çalışmanın büyük olasılıkla Portekiz'de yapıldığını söyledi. Ekrandaki belgeye göre UBIRIS.v1'de 241 göz için toplam 1877 iris görüntüsü vardır; görüntüler 200×150 boyutunda ve gri seviyelidir (ekrandan, 01:45:00). Görüntüler 2004'te, iki ayrı oturumda (two distinct sessions), yani aynı kişilerden iki ayrı tarihte toplanmıştır. Her gözün birkaç fotoğrafı vardır; bunların bir kısmı sistemde kayıtlı tutulup bir başka fotoğrafla doğrulama (verification, authentication) yapılabilir: "bu kişi gerçekten o kişi midir?"

Ekrandaki belgede ayrıca şu ifade yer alıyor: tümleşik-türev (integro-differential) operatörü, görüntülerin birinci türevini kullanarak istenen geometrik parametrelerin bulunmasını sağlar ve aslında Hough dönüşümünün bir başka şeklidir. Göz bebeği ve iris bölgesini bulmak için operatör ayrı ayrı uygulanmalıdır.

### 8.2 Arama uzayını küçültme

Algoritma bütün olası merkez ve yarıçapları denediği için çok uzun sürebilir. Hoca arama uzayını şöyle küçültmeyi önerdi (ekrandan, 01:50:00):

- **Merkez:** Görüntü yatayda ve dikeyde üçe bölünür (3×3 ızgara). Merkez yalnız ortadaki bölgede aranır; göz bebeğinin merkezi görüntünün köşelerinde olamaz.
- **İris yarıçapı:** piksel cinsinden 50 ile 120 arasında aranabilir.
- **Göz bebeği yarıçapı:** iris yarıçapının 0.1 ile 0.8 katı arasında değiştiği kabul edilir. Önce irisin merkezi ve yarıçapı bulunur, sonra göz bebeği çemberi bu aralıkta aranır.
- Göz bebeğinin merkezi ile irisin merkezi aynı olmayabilir, birkaç piksel kayık olabilir.

### 8.3 Ön işleme: parlama sorunu

Fotoğraflarda göz bebeğinin içinde, büyük olasılıkla flaştan gelen beyaz bir parlama vardır. Göz bebeğinin içi siyah olması gerekirken bu parlak nokta göz bebeğini çevreleyen çemberin bulunmasını zorlaştırır. Bu yüzden önce bir ön işlemle bu bölgenin karartılması gerekir.

### 8.4 Hazır kod ve anlamak

İnternette bu algoritmanın MATLAB çözümleri vardır, Python çözümleri de büyük olasılıkla vardır. Koddan esinlenilebilir.

> **Hocanın vurgusu:** Çalıştırdığınız kodun her satırının ne yaptığını bilmelisiniz: burada ne yapılıyor, bu matris kaç boyutlu, neden böyle bir matris oluşturuluyor, çıktısı ne, kaça kaçlık bir dizi ya da matriste tutuluyor. Sonuçları iyileştirmek için daha ne yapılabileceğini de düşünün.

Hoca ayrıca bu algoritmanın yalnız iris için değil, tıbbi görüntülerde çember biçimli yapıları (örneğin yuvarlak kemik uçlarını) arka plandan ayırmak için de kullanılabileceğini, başka problemlere de uyarlanabileceğini söyledi.

## 9. İki Boyutlu Dönüşümler ve Eşleştirme

### 9.1 Neden dönüşüm?

Yeni konu "2D Transformations: Scaling, Rotation, Translation and Warping" başlığını taşır. Bu dönüşümler eşleştirme (matching) için kullanıldığından slaytta "2D Transformations for Matching" diye adlandırılır. Dönüşüm türleri ölçekleme (scaling), döndürme (rotation), öteleme (translation) ve bükmedir (warping).

Eşleştirmede elimizde bir görüntü ve bir harita ya da model olabilir. Örneğin bir parçanın üç boyutlu çizimi ve kayan bant üzerinde üretilmiş parçanın kameradan alınmış görüntüsü vardır. Model ile görüntü arasında eşleştirme yaparak görüntüde nesnenin belli bir noktasına odaklanmak istenebilir. Ya da kameradan alınmış iki görüntü arasında eşleştirme yapılabilir, birbiriyle ilişkili noktaların (correspondence) yerleri bulunabilir. Bu bölümdeki bütün işlemler iki boyutludur; üç boyuta genişletmek için işlemlerin üç boyutlu hallerini düşünmek gerekir.

Model uzayındaki (model space) bir noktanın görüntü düzlemindeki (image plane) bir noktayla eşleştirilmesinde şu farklar olabilir:

- İki düzlem arasında ölçek farkı: ölçekleme gerekir.
- İki düzlem arasında bir dönme açısı: döndürme gerekir.
- Belli bir yerden başka bir yere kaydırma: öteleme gerekir.

### 9.2 Homojen koordinatlar

İki boyutlu bir nokta satır vektörü $P = [x, y]$ ya da sütun vektörü $P = [x, y]^t$ olarak gösterilir (ekrandan, 02:10:00). Özellikle afin dönüşümlerde, bilgisayarda işlem kolaylığı için homojen koordinatlar (homogeneous coordinates) kullanılır. $P = [x, y]^t$ noktasının homojen koordinatları $[sx, sy, s]^t$'dir; $s$ bir ölçek çarpanıdır ve genelde 1.0 alınır. Uygulamada ölçek çarpanı 1 alınarak nokta gerçek ölçüsünde $[x, y, 1]^t$ biçiminde yazılır.

Ölçekleme, döndürme ve kaydırma gibi işlemler afin eşleme fonksiyonu (affine mapping function) olarak matris biçiminde gösterilir.

### 9.3 Ölçekleme

Slayttaki örnekte $P(1, 2)$ noktası 2 çarpanıyla ölçeklenince yeni nokta $P'(2, 4)$ olur. Ölçekleme doğrusal (linear) bir dönüşümdür: her koordinat ekseninde aynı sayıyla çarpılır.

Python'da kayıtlı "cameraman" görüntüsü üzerinde `rescale` fonksiyonuyla 0.1, 0.5 gibi ölçek çarpanları denenip ölçeklenmiş görüntüler özgün görüntüyle birlikte çizdirilebilir. Bu kodlar slaytlarda yer alıyor.

### 9.4 Döndürme

Slayttaki soru şudur: $P = [x, y]$ noktası orijin etrafında saatin tersi yönünde $\theta$ kadar döndürülünce yeni nokta $P' = [x', y']$'nün koordinatları nedir (ekrandan, 02:15:00)? Döndürmede noktanın orijine uzaklığı değişmez.

Döndürme matrisini bulmak için slaytın sağ tarafındaki gibi eksen üzerindeki birim noktalar döndürülür (rotation of basis vectors):

- **$(1, 0)$ noktası:** $\theta$ kadar döndürülünce, hipotenüs 1 olduğundan $\cos\theta = x'/1$, yani $x' = \cos\theta$; benzer biçimde $y' = \sin\theta$. Yeni nokta $[\cos\theta, \sin\theta]$.
- **$(0, 1)$ noktası:** $\theta$ kadar döndürülünce sola, x ekseninin eksi tarafına geçer. x yönündeki uzaklık $\sin\theta$ kadardır ama işareti eksidir, y yönündeki uzaklık $\cos\theta$'dır. Yeni nokta $[-\sin\theta, \cos\theta]$. (Hoca önce yanlış eşleştirdi, sonra düzeltti.)

Bu iki sonuç döndürme matrisinin sütunlarıdır (ekrandan, 02:20:00):

$$\begin{bmatrix} x' \\ y' \end{bmatrix} = \begin{bmatrix} \cos\theta & -\sin\theta \\ \sin\theta & \cos\theta \end{bmatrix} \begin{bmatrix} x \\ y \end{bmatrix}$$

Matrisin birinci satırıyla vektör çarpılınca $x' = x\cos\theta - y\sin\theta$, ikinci satırıyla çarpılınca $y' = x\sin\theta + y\cos\theta$ elde edilir. Bu matrise $R_\theta$ denir.

Python'da `skimage.transform.rotate` hazır fonksiyonuyla görüntü döndürülebilir.

### 9.5 Öteleme

Yukarıdaki matrislerde homojen koordinat kullanılmadı; ama öteleme için homojen koordinat şarttır. $P$ noktası x ekseninde $x_0$, y ekseninde $y_0$ kadar kaydırılırsa öteleme matrisi kullanılır:

$$\begin{bmatrix} x' \\ y' \\ 1 \end{bmatrix} = \begin{bmatrix} 1 & 0 & x_0 \\ 0 & 1 & y_0 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} x \\ y \\ 1 \end{bmatrix}$$

Matrisin birinci satırıyla vektör çarpılınca $x + x_0$, ikinci satırıyla çarpılınca $y + y_0$ çıkar. Homojen koordinatlar nedeniyle son satır $[0, 0, 1]$'dir. Bu matrise $D_{x_0, y_0}$ denir.

Böylece üç işlem görülmüş oldu: ölçekleme, döndürme ve öteleme.

## 10. Bir Nokta Etrafında Döndürme Örneği

### 10.1 Problem

Slayttaki alıştırma (ekrandan, 02:25:00):

- Düzlemin $[5, 8]$ noktası etrafında $\pi/2$ döndürülmesini temsil eden 3×3 matrisi verin.
- İpucu: önce $[5, 8]$ noktasını yeni bir koordinat sisteminin orijinine taşıyan $D_{-5,-8}$ matrisini bulun. İstenen matris $D_{5,8} R_{\pi/2} D_{-5,-8}$ birleşimidir.
- Matrisinizin $[5, 8]$, $[6, 8]$ ve $[5, 9]$ noktalarını doğru dönüştürdüğünü kontrol edin.

### 10.2 Önce sezgiyle

Matris kullanmadan, noktaların düzlemdeki yerlerine bakarak sonuç tahmin edilebilir (ekrandan, 02:30:00). Noktalar $A(5, 8)$, $B(6, 8)$, $C(5, 9)$ olsun.

- $A$ dönme merkezi olduğu için yerinde kalır: $A' = (5, 8)$.
- $B$, $A$'nın bir birim sağındadır. Saatin tersi yönünde 90° dönünce $A$'nın bir birim üstüne, yani $C$'nin bulunduğu yere gider: $B' = (5, 9)$.
- $C$, $A$'nın bir birim üstündedir. 90° dönünce $A$'nın bir birim soluna gider: $C' = (4, 8)$.

### 10.3 Matrisle çözüm

$P' = D_{5,8}\, R_{\pi/2}\, D_{-5,-8}\, P$ yazılır (ekrandan, 02:35:00):

$$D_{5,8} = \begin{bmatrix} 1 & 0 & 5 \\ 0 & 1 & 8 \\ 0 & 0 & 1 \end{bmatrix}, \quad R_{\pi/2} = \begin{bmatrix} \cos\frac{\pi}{2} & -\sin\frac{\pi}{2} & 0 \\ \sin\frac{\pi}{2} & \cos\frac{\pi}{2} & 0 \\ 0 & 0 & 1 \end{bmatrix}, \quad D_{-5,-8} = \begin{bmatrix} 1 & 0 & -5 \\ 0 & 1 & -8 \\ 0 & 0 & 1 \end{bmatrix}$$

Hoca döndürme matrisini önce 2×2 yazdı, homojen koordinat nedeniyle 3×3 olması gerektiğini fark edip düzeltti. $\cos\frac{\pi}{2} = 0$, $\sin\frac{\pi}{2} = 1$ olduğundan:

$$R_{\pi/2} = \begin{bmatrix} 0 & -1 & 0 \\ 1 & 0 & 0 \\ 0 & 0 & 1 \end{bmatrix}$$

Çarpım adımları (ara adım eklendi):

$$R_{\pi/2} D_{-5,-8} = \begin{bmatrix} 0 & -1 & 8 \\ 1 & 0 & -5 \\ 0 & 0 & 1 \end{bmatrix}, \qquad D_{5,8}\,(R_{\pi/2} D_{-5,-8}) = \begin{bmatrix} 0 & -1 & 13 \\ 1 & 0 & 3 \\ 0 & 0 & 1 \end{bmatrix}$$

Sonuç matrisi öğrencilerle birlikte eleman eleman bulundu: birinci satır 0, −1, 13; ikinci satır 1, 0, 3; üçüncü satır 0, 0, 1 (ekrandan, 02:40:00; python ile doğrulandı).

Kontrol:

- $A(5, 8)$: $x' = 0\cdot5 - 1\cdot8 + 13 = 5$, $y' = 1\cdot5 + 0\cdot8 + 3 = 8$. $A' = (5, 8)$, değişmedi.
- $B(6, 8)$: $x' = -8 + 13 = 5$, $y' = 6 + 3 = 9$. $B' = (5, 9)$.
- $C(5, 9)$: $x' = -9 + 13 = 4$, $y' = 5 + 3 = 8$. $C' = (4, 8)$.

Sonuçlar sezgiyle bulunanlarla aynıdır.

> **Ders sonrası not:** Hoca testte önce $A$ noktasını yanlışlıkla $(5, 3)$ diye yazdı ve sonuç $(10, 8)$ çıktı; sonra $A$'nın $(5, 8)$ olduğunu söyleyerek düzeltti. Doğru test noktası $(5, 8)$'dir ve dönüşüm sonrasında yerinde kalır.

Üç boyutta her eksen etrafındaki döndürme matrisleri farklıdır; yapı daha karmaşıktır. Burada yalnız düzlemdeki durum görüldü.

## 11. Görüntü Düzleminden Dünya Düzlemine Dönüşüm

### 11.1 Problem

Bu dönüşümler bir eşleştirme için öğrenildi: bir tarafta model uzayı ya da gerçek dünya, öbür tarafta kameradan alınmış görüntü vardır. Slayttaki durum şudur: $I[r, c]$ görüntüsü, düz bir çalışma alanına $W[x, y]$ dik olarak bakan, kare pikselli bir kamerayla alınmıştır (ekrandan, 02:45:00). Dünya koordinat düzleminin (world coordinate) eksenleri $X_w$, $Y_w$; görüntü düzleminin (image plane) eksenleri $X_i$ (satır), $Y_i$ (sütun)'dur. Biri görüntü düzlemidir, öbürü nesnenin gerçek ölçekteki konumunu gösteren dünya düzlemidir.

Dönüşüm bir döndürme $R$, bir ölçekleme $S$ ve bir öteleme $D$ birleşimiyle yapılır:

$${}^{w}P_j = D_{x_0, y_0}\, S_s\, R_\theta\, {}^{i}P_j$$

Görüntü düzlemindeki ${}^{i}P_j$ noktası bu üç matrisle çarpılınca dünya düzlemindeki ${}^{w}P_j$ konumu bulunur. Matrislerde dört bilinmeyen vardır: $x_0$, $y_0$, $s$ ve $\theta$. Bunları bulmak için iki noktanın her iki düzlemdeki yeri bilinmelidir. Slayttaki çizimde bu iki nokta $P_1$ ve $P_2$'dir.

### 11.2 Kontrol noktaları ve açı

Slayttaki örnek (ekrandan, 02:50:00):

- ${}^{i}P_1 = [100, 60]$ ve ${}^{w}P_1 = [200, 100]$
- ${}^{i}P_2 = [380, 120]$ ve ${}^{w}P_2 = [300, 200]$

Kontrol noktaları (control points), farklı koordinat uzayları arasında bilinen karşılıklar kurmak için kolay ayırt edilen ve kolay ölçülen noktalardır.

$\theta$ diğer parametrelerden bağımsız olarak bulunur. $P_1$ ve $P_2$'den geçen doğru çizilir. Bu doğrunun görüntü düzleminde kendi x ekseniyle yaptığı açı $\theta_i$, dünya düzleminde kendi x ekseniyle yaptığı açı $\theta_w$'dir. Her ikisi $\arctan(\Delta y / \Delta x)$ ile hesaplanır (ekrandan, 02:55:00):

$$\theta_i = \arctan\frac{{}^{i}y_2 - {}^{i}y_1}{{}^{i}x_2 - {}^{i}x_1} = \arctan\frac{60}{280} = 12.09°$$

$$\theta_w = \arctan\frac{{}^{w}y_2 - {}^{w}y_1}{{}^{w}x_2 - {}^{w}x_1} = \arctan\frac{100}{100} = 45°$$

$$\theta = \theta_w - \theta_i = 32.91°$$

Bu fark, iki koordinat düzleminin x eksenleri arasındaki açıdır (python ile doğrulandı). $\theta$ bulununca bütün $\sin$ ve $\cos$ elemanları bilinir; geriye üç bilinmeyen ($s$, $x_0$, $y_0$) ve üç denklem kalır, bunlar da çözülür.

### 11.3 Soru-cevap: gerçek dünyada bu noktalar nereden bilinir?

**Soru:** İki noktanın iki düzlemdeki yeri bilinirse öteleme, ölçek ve döndürme hesaplanabiliyor. Ama gerçek bir problemde, örneğin iki görüntünün eşleşip eşleşmediğini ararken, bu noktaları nasıl bilebiliriz? **Cevap:** Örnek olarak bir odaya yerleştirilmiş bir kamera düşünülebilir. Odaya giren bir kişinin kamera görüntüsündeki koordinatı ile odanın gerçek ölçekli düzlemindeki konumu eşleştirilmek istenir. Odanın eni ve boyu bilindiği için birkaç kontrol noktasının iki düzlemdeki yeri ölçülebilir. Bu iki nokta üzerinden eşleştirme bir kez kurulunca, görüntü düzlemindeki her noktanın dünya düzlemindeki yeri söylenebilir. Buna kamera kalibrasyonu da denir. Amaç iki görüntünün tümüyle eşleşmesinden çok, belli parçalarının eşleşmesini yakalamaktır. Bir tarafta piksel cinsinden bir ölçek, öbür tarafta metre cinsinden (örneğin duvara kaç metre uzakta) bir ölçek vardır; kameranın yerleştirildiği konuma göre iki düzlem arasında bir dönme açısı da bulunur.

## Örnek Sorular

**Soru 1** (ekrandan, 02:25:00): Düzlemin $[5, 8]$ noktası etrafında $\pi/2$ döndürülmesini temsil eden 3×3 matrisi verin. İpucu: istenen matris $D_{5,8} R_{\pi/2} D_{-5,-8}$'dir. Matrisinizin $[5, 8]$, $[6, 8]$ ve $[5, 9]$ noktalarını doğru dönüştürdüğünü kontrol edin.

> **Çözüm:** $D_{5,8} R_{\pi/2} D_{-5,-8} = \begin{bmatrix} 0 & -1 & 13 \\ 1 & 0 & 3 \\ 0 & 0 & 1 \end{bmatrix}$ (ekrandan, 02:40:00). $[5, 8] \to [5, 8]$, $[6, 8] \to [5, 9]$, $[5, 9] \to [4, 8]$. Ayrıntılı çözüm Bölüm 10'dadır.

**Soru 2** (derste sözlü, 02:29:22): $B(6, 8)$ noktası $A(5, 8)$ merkezli olarak saatin tersi yönünde 90° döndürülürse nereye gider? $C(5, 9)$ noktası nereye gider?

> **Çözüm:** $B$, $A$'nın bir birim sağındadır; 90° dönünce bir birim üstüne gider: $(5, 9)$. $C$, $A$'nın bir birim üstündedir; 90° dönünce bir birim soluna gider: $(4, 8)$. Derste öğrencilerle birlikte bu cevaplar bulundu.

**Soru 3** (derste sözlü, 00:40:16): Hesse normal formu türetilirken $OLB$ üçgeninde $B$ köşesindeki açı $90° - \alpha$ ise $O$ köşesindeki açı kaç derecedir ve bu açının sinüsü nedir?

> **Çözüm:** $L$'deki açı 90° olduğundan $O$'daki açı $180° - 90° - (90° - \alpha) = \alpha$'dır. $\sin\alpha = p / OB$. Derste cevap öğrencilerden alındı.

**Soru 4** (ekrandan, 00:55:00): Üç veri noktası için 0°, 30°, 60°, 90°, 120°, 150° açılarıyla geçen doğruların uzaklıkları tablolarda verilmiştir. Üç noktadan da geçen doğrunun Hough parametreleri nedir?

> **Çözüm:** 60° satırında üç noktanın uzaklıkları (81.2, 80.5, 80.6) birbirine en yakın değerlerdir; Hough düzlemindeki üç eğri $\theta = 60°$, $\rho \approx 80$ noktasında kesişir (ekrandan, 01:00:00). Doğrunun parametreleri $\theta = 60°$, $\rho \approx 80$'dir.

**Soru 5** (derste sözlü, 00:46:03): Hesse normal formunda $\theta = 45°$ ve $\rho = 2$ seçilirse doğru x ve y eksenlerini nerede keser?

> **Çözüm (derste verilmedi):** $x\cos 45° + y\sin 45° = 2$. $y = 0$ için $x = 2 / \cos 45° = 2\sqrt{2} \approx 2.83$; $x = 0$ için $y = 2 / \sin 45° = 2\sqrt{2} \approx 2.83$. Doğru eksenleri $(2.83, 0)$ ve $(0, 2.83)$ noktalarında keser; denklemi $x + y = 2\sqrt{2}$'dir (python ile doğrulandı).

**Soru 6** (ekrandan, 02:50:00): ${}^{i}P_1 = [100, 60]$, ${}^{w}P_1 = [200, 100]$, ${}^{i}P_2 = [380, 120]$, ${}^{w}P_2 = [300, 200]$ verildiğinde ${}^{w}P = D_{x_0,y_0} S_s R_\theta\, {}^{i}P$ dönüşümünün $\theta$, $s$, $x_0$, $y_0$ parametrelerini bulun.

> **Çözüm:** Derste verilen kısım: $\theta_i = \arctan(60/280) = 12.09°$, $\theta_w = \arctan(100/100) = 45°$, $\theta = 32.91°$ (ekrandan, 02:50:00).

> **Çözüm (derste verilmedi):** Ölçek, iki noktanın arasındaki uzaklıkların oranıdır: $|{}^{w}P_2 - {}^{w}P_1| = \sqrt{100^2 + 100^2} \approx 141.42$, $|{}^{i}P_2 - {}^{i}P_1| = \sqrt{280^2 + 60^2} \approx 286.36$, $s \approx 141.42 / 286.36 \approx 0.494$. Öteleme ${}^{w}P_1 - s R_\theta\, {}^{i}P_1$ ile bulunur: $x_0 \approx 174.63$, $y_0 \approx 48.29$. Bu değerlerle ${}^{i}P_2$ dönüştürülünce $[300, 200]$ elde edilir (python ile doğrulandı).

## Dersin Toparlaması

Bu derste klasik bilgisayarla görmenin iki önemli aracı işlendi. İlki Hough dönüşümüdür: kenar bulmadan sonra elde edilen kenar noktaları, Hesse normal formundaki $(\theta, \rho)$ parametre uzayında oylanır ve akümülatörde en çok oy alan göz aranan doğruyu verir. Aynı fikir çember için üç boyutlu bir akümülatörle uygulanır. Daugman'ın integro-diferansiyel operatörü bu fikri iris bölütlemeye taşır: çember üzerindeki ortalama parlaklığın yarıçapa göre türevi Gauss ile yumuşatılır ve en büyük değeri veren merkez ile yarıçap iris (ve ardından göz bebeği) sınırını verir. Arama uzayını daraltmak ve parlama gibi sorunları ön işlemle gidermek uygulamada önemlidir.

İkinci kısımda iki boyutlu dönüşümler (ölçekleme, döndürme, öteleme) homojen koordinatlarla matris biçiminde yazıldı. Bir nokta etrafında döndürme, öteleme-döndürme-öteleme çarpımıyla elde edildi. Son olarak iki kontrol noktası yardımıyla görüntü düzleminden dünya düzlemine dönüşümün parametrelerinin nasıl bulunduğu görüldü; bu, kamera kalibrasyonu gibi eşleştirme problemlerinin temelidir. Bir sonraki derste köşe bulma ve HOG gibi öznitelik çıkarma algoritmalarına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
