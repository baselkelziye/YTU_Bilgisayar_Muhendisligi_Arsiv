# Ders 4 Genişletilmiş Notu: Öznitelik Birleştirme: Temel Bileşen Analizi (PCA)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veri İndirgeme Haritası ve Bu Dersin Yeri
- 2. İstatistik Hatırlatması: Ortalama ve Standart Sapma
- 3. Varyans ve Kovaryans
- 4. Çalışma Saati ve Puan Örneği
- 5. Kovaryans Matrisi
- 6. Lineer Cebir Hatırlatması: Özdeğer ve Özvektör
- 7. Özdeğer ve Özvektör Hesabı: Adım Adım Örnek
- 8. Temel Bileşen Analizinin Adımları
- 9. Özvektörlerin Grafik Üzerinde Yorumu
- 10. İzdüşüm ve Boyut Azaltma
- 11. Çok Boyutlu Veride Bileşen Sayısının Seçimi
- Örnek Sorular

## 1. Veri İndirgeme Haritası ve Bu Dersin Yeri

Hoca derse, önceki derste çıkarılan genel haritayı hatırlatarak başladı. Veri indirgeme işlemi üç başlıkta toplanmıştı:

- **Öznitelik indirgeme (feature reduction):** Sütun (öznitelik) sayısını azaltmak.
- **Örnek indirgeme (sample reduction):** Satır (örnek) sayısını azaltmak.
- **Değer indirgeme (value reduction):** Özniteliklerin aldığı değerlerin sayısını azaltmak.

Öznitelik indirgeme tarafı da ikiye ayrılıyordu. Birincisi **öznitelik seçme (feature selection)**: var olan özniteliklerden bir alt küme seçmek. Bununla ilgili örnekler ve çözüm yöntemleri önceki derste tartışılmıştı. İkincisi **öznitelik birleştirme (feature composition)**: var olan öznitelikleri birleştirerek yeni öznitelikler üretmek. Bu derste öznitelik birleştirme tarafında eğitmensiz (unsupervised) bir yöntem olan **Temel Bileşen Analizi (Principal Component Analysis, PCA)** anlatıldı.

Anlatım, hocanın internette bulduğu ve çok faydalandığını söylediği bir eğitim belgesi üzerinden yürüdü: "A tutorial on Principal Components Analysis", Lindsay I. Smith, 2002 (ekrandan, 00:10:00). Hoca bu belgeyi, adımları madde madde ve tek bir örnek üzerinden götürdüğü için beğendiğini söyledi.

PCA'nın ne yaptığını hoca şöyle özetledi: XYZ gibi üç boyutlu bir uzayda olduğumuzu düşünelim. PCA, öznitelikleri birleştirerek bize farklı bir eksen sistemi verir ve veriyi iki boyutlu ya da yine üç boyutlu yeni bir uzaya dönüştürmemizi sağlar. Bu dönüşüm, veriyi daha iyi algılamamıza yardımcı olan bir dönüşümdür.

Dönüşümü anlamak için iki matematik konusunun hatırlanması gerekiyordu: istatistik (standart sapma, varyans, kovaryans) ve lineer cebir (özdeğer, özvektör). Dersin yaklaşık ilk bir saati bu hatırlatmaya ayrıldı.

## 2. İstatistik Hatırlatması: Ortalama ve Standart Sapma

Hoca, bir veriyi tarif etmek için en iyi istatistiksel parametrenin ne olduğunu sordu. Ortalama değer gereklidir ama yetmez; bir de standart sapmaya ihtiyaç vardır.

### 2.1 Ortalama

$n$ elemanlı bir $X$ dizisinin ortalaması bütün elemanların toplanıp eleman sayısına bölünmesiyle bulunur (ekrandan, 00:15:00):

$$\bar{X} = \frac{\sum_{i=1}^{n} X_i}{n}$$

Belgedeki örnekte iki dört elemanlı dizi verildi (ekrandan, 00:15:00):

$$[0,\ 8,\ 12,\ 20] \quad \text{ve} \quad [8,\ 9,\ 11,\ 12]$$

- Birinci dizi: $0 + 8 + 12 + 20 = 40$, $40/4 = 10$.
- İkinci dizi: $8 + 9 + 11 + 12 = 40$, $40/4 = 10$.

İkisinin de ortalaması 10'dur. Oysa birinci dizinin değişim aralığı çok geniştir (0-20), ikincisi ise dar bir aralıkta (8-12) değişir. Demek ki ortalama tek başına dizi hakkında yeterli ipucu vermez.

### 2.2 Standart sapma

Standart sapma, verinin ne kadar yayıldığının ölçüsüdür (ekrandan, 00:15:00):

$$s = \sqrt{\frac{\sum_{i=1}^{n}(X_i - \bar{X})^2}{n-1}}$$

Dizinin her elemanından ortalama çıkarılır, farkların kareleri toplanır, toplam $n-1$'e bölünür (bu varyanstır) ve karekök alınır.

İki dizi için hesap (ara adım eklendi):

- Birinci dizi: farklar $-10, -2, 2, 10$; kareler toplamı $100 + 4 + 4 + 100 = 208$; $208/3 \approx 69{,}33$; $s \approx 8{,}33$.
- İkinci dizi: farklar $-2, -1, 1, 2$; kareler toplamı $4 + 1 + 1 + 4 = 10$; $10/3 \approx 3{,}33$; $s \approx 1{,}83$.

Hoca, değerlere bakmadan da birinci dizinin standart sapmasının daha büyük çıkacağını öngörebileceğimizi vurguladı; çünkü onun değişim aralığı daha geniştir.

### 2.3 Standart sapmanın yorumu

Standart sapma, dizideki sayıların ortalamaya göre ne kadar sapma gösterdiğini anlatır. Değerler kabaca $\bar{X} \pm s$ aralığında yer alır:

- Birinci dizi: $10 \pm 8{,}33$, yani yaklaşık $1{,}7$ ile $18{,}3$ arası.
- İkinci dizi: $10 \pm 1{,}83$, yani yaklaşık $8{,}2$ ile $11{,}8$ arası. Dizi gerçekten 8 ile 12 arasında değer alıyordu ve standart sapma bize bunu söylüyor.

> **Ders sonrası not:** Hoca $10 - 8{,}32$ için "1,7 gibi bir değer" dedi; tam sonuç $1{,}68$'dir. Derste okunan standart sapmalar 8,32 ve 1,82'dir; python ile 8,3267 ve 1,8257 bulunur, yorum değişmez.

> **Hocanın vurgusu:** Bu istatistiksel parametreleri yalnız bir formül gibi görmeyin. Formülle hesap yapacağız ama sonucun bize ne anlattığını, yorumunu da düşünürsek hem aklımızda daha çok kalır hem konuyu daha iyi kavrarız.

## 3. Varyans ve Kovaryans

### 3.1 Varyans

Varyans, standart sapmanın karesidir; standart sapma hesabında karekök almadan bırakılan değerdir. Belgede varyans formülü, kare terimi açılarak şöyle yazılır (ekrandan, 00:20:00):

$$\mathrm{var}(X) = \frac{\sum_{i=1}^{n}(X_i - \bar{X})(X_i - \bar{X})}{n-1}$$

### 3.2 Kovaryans

Standart sapma ve varyans tek bir boyut (tek değişken) üzerinde çalışır. Veri iki boyutluysa, yani iki değişken varsa, değişkenlerden birinin diğeriyle ilişkisini görmek için **kovaryans** kullanılır. Veri madenciliği açısından her değişken bir özniteliktir; dolayısıyla kovaryans, veri setindeki iki özniteliğin birbiriyle ilişkisini anlamamıza yarar.

$X$ ve $Y$ iki değişken, veri setinde $n$ örnek olsun (ekrandan, 00:20:00):

$$\mathrm{cov}(X,Y) = \frac{\sum_{i=1}^{n}(X_i - \bar{X})(Y_i - \bar{Y})}{n-1}$$

Her örnek için birinci değişkenin kendi ortalamasından farkı ile ikinci değişkenin kendi ortalamasından farkı çarpılır, bu çarpımlar toplanır ve $n-1$'e bölünür. Varyans formülünde aynı fark iki kez çarpılıyordu; kovaryansta bir $X$ farkı ile bir $Y$ farkı çarpılır. Buradan bir değişkenin kendisiyle kovaryansının varyans olduğu görülür: $\mathrm{cov}(X,X) = \mathrm{var}(X)$.

## 4. Çalışma Saati ve Puan Örneği

Hoca, konunun akılda kalması için çok sevdiği bir örneği paylaştı. Günlük hayatta farklı yorumladığımız bir veriyi hem veri madenciliği hem istatistik açısından yorumlayacağız.

Veri seti, bir okulda 12 öğrencinin bir derse kaç saat çalıştığını (H) ve o dersten kaç puan aldığını (M) gösterir. Her satır bir örnektir (12 örnek), iki sütun iki özniteliktir (ekrandan, 00:25:00).

### 4.1 Ortalamalarla karşılaştırma

- Ortalama çalışma süresi: $167 / 12 \approx 13{,}92$ saat.
- Ortalama puan: yaklaşık 62 (tam değer $749/12 \approx 62{,}42$; ara adım eklendi).

Bu iki ortalama elimizde olunca her öğrenciyi onlarla kıyaslayabiliriz. Örneğin birinci öğrenci, sınıf ortalaması yaklaşık 14 saatken 9 saat çalışmış, yani az çalışmış; sınıfın ortalama puanı 62 iken 39 almış, yani beklendiği gibi daha düşük puan almış. Kovaryans da buna benzer bir analiz yapar.

### 4.2 Kovaryans tablosu

Her öğrenci için çalışma süresinin ortalamadan farkı, puanın ortalamadan farkı ve bu iki farkın çarpımı hesaplanır (ekrandan, 00:25:00):

| H | M | $H_i - \bar{H}$ | $M_i - \bar{M}$ | $(H_i - \bar{H})(M_i - \bar{M})$ |
|---|---|---|---|---|
| 9 | 39 | -4,92 | -23,42 | 115,23 |
| 15 | 56 | 1,08 | -6,42 | -6,93 |
| 25 | 93 | 11,08 | 30,58 | 338,83 |
| 14 | 61 | 0,08 | -1,42 | -0,11 |
| 10 | 50 | -3,92 | -12,42 | 48,69 |
| 18 | 75 | 4,08 | 12,58 | 51,33 |
| 0 | 32 | -13,92 | -30,42 | 423,45 |
| 16 | 85 | 2,08 | 22,58 | 46,97 |
| 5 | 42 | -8,92 | -20,42 | 182,15 |
| 19 | 70 | 5,08 | 7,58 | 38,51 |
| 16 | 66 | 2,08 | 3,58 | 7,45 |
| 20 | 80 | 6,08 | 17,58 | 106,89 |

Birinci öğrenci ortalamadan yaklaşık 4,92 saat az çalışmış (fark negatif) ve ortalamanın 23,42 puan altında kalmış (fark yine negatif). İki negatif farkın çarpımı pozitiftir.

Hoca işaretlere dikkat çekti: Ortalamadan az çalışan bir öğrencinin ortalamanın altında puan alması beklenir; iki fark da negatif olur, çarpım pozitif çıkar. Ortalamadan çok çalışıp ortalamanın üstünde puan alan öğrencide iki fark da pozitiftir, çarpım yine pozitiftir. Kurala uymayan öğrenciler de vardır: 15 saat çalışan bir öğrenci ortalamadan fazla çalışmış ama 56 puanla ortalamanın altında kalmış; saat farkı pozitif, puan farkı negatif, çarpım negatif çıkmış. Hoca, 12 kişinin içinde bir iki istisna çıkabileceğini, bu istisnaların hem sayıca az hem de farklarının küçük olduğunu, bu yüzden kümenin genel yapısını pek etkilemediğini söyledi.

### 4.3 Sonuç ve yorum

Çarpımlar toplanıp $n-1 = 11$'e bölünür. Belgede sonuç yaklaşık 104,53 olarak verildi (hoca 104,52 diye okudu). Bu, çalışma süresi ile puan arasındaki kovaryanstır.

> **Ders sonrası not:** Belgedeki "Total = 1149,89" satırı hatalıdır. Tablodaki çarpımların toplamı $1352{,}46$'dır (python ile kontrol edildi); kovaryans $1352{,}46 / 11 \approx 122{,}95$ olmalıdır. Sonucun pozitif olması ve yorumu değişmez.

Sonucun pozitif olması, iki değişkenin aynı yönde değiştiğini gösterir: biri artarken öbürü de artar, biri azalırken öbürü de azalır. Negatif kovaryans ise biri artarken öbürünün azaldığı bir ilişkiyi gösterir.

> **Hocanın vurgusu:** Kovaryansın iki değişken arasında bir ölçü olduğunu, ne zaman pozitif ve ne zaman negatif olduğunu lütfen unutmayın. Bu gerçekten önemli.

## 5. Kovaryans Matrisi

İki değişken için tek bir kovaryans değeri yeterlidir. Değişken sayısı arttığında ikili kovaryansları tek tek yazmak konuyu dağıtır; bu yüzden hepsi bir **kovaryans matrisinde** toplanır. Matrisin boyutu değişken sayısı kadardır. Üç değişken $(x, y, z)$ için $3 \times 3$ bir matris oluşur:

$$C = \begin{pmatrix}
\mathrm{cov}(x,x) & \mathrm{cov}(x,y) & \mathrm{cov}(x,z)\\
\mathrm{cov}(y,x) & \mathrm{cov}(y,y) & \mathrm{cov}(y,z)\\
\mathrm{cov}(z,x) & \mathrm{cov}(z,y) & \mathrm{cov}(z,z)
\end{pmatrix}$$

İki önemli özellik vardır:

- **Ana köşegen varyanslardır.** Matrisin ilk gözü $\mathrm{cov}(x,x)$, yani $x$'in varyansıdır; ana köşegendeki her eleman bir özniteliğin kendi varyansıdır.
- **Matris simetriktir.** $\mathrm{cov}(a,b) = \mathrm{cov}(b,a)$ olduğu için matris ana köşegene göre simetriktir.

## 6. Lineer Cebir Hatırlatması: Özdeğer ve Özvektör

PCA'da veri setinden oluşturulan kovaryans matrisinin özdeğer (eigenvalue) ve özvektörleri (eigenvector) hesaplanır. Hoca bu kavramları belgedeki örnekle hatırlattı (ekrandan, 00:35:00):

$$\begin{pmatrix}2 & 3\\ 2 & 1\end{pmatrix} \times \begin{pmatrix}1\\ 3\end{pmatrix} = \begin{pmatrix}11\\ 5\end{pmatrix}$$

$$\begin{pmatrix}2 & 3\\ 2 & 1\end{pmatrix} \times \begin{pmatrix}3\\ 2\end{pmatrix} = \begin{pmatrix}12\\ 8\end{pmatrix} = 4 \times \begin{pmatrix}3\\ 2\end{pmatrix}$$

Matris-vektör çarpımında matrisin her satırı vektörle eleman eleman çarpılıp toplanır. İkinci çarpımda birinci satır $2 \cdot 3 + 3 \cdot 2 = 12$, ikinci satır $2 \cdot 3 + 1 \cdot 2 = 8$ verir. Çıkan $(12, 8)$ vektörü, $(3, 2)$ vektörünün 4 katıdır. Yani matrisi bu vektörle çarpmanın sonucu, bir katsayı ile aynı vektörün çarpımı olarak yazılabilmiştir. Bu özel vektöre **özvektör**, katsayıya (4) **özdeğer** denir. Birinci çarpımda ise $(11, 5)$, $(1, 3)$'ün bir katı değildir; dolayısıyla $(1,3)$ bir özvektör değildir.

Belgede ayrıca özvektörün bir katının da özvektör olduğu gösterilir (ekrandan, 00:35:00): $2 \times (3, 2) = (6, 4)$ ve

$$\begin{pmatrix}2 & 3\\ 2 & 1\end{pmatrix} \times \begin{pmatrix}6\\ 4\end{pmatrix} = \begin{pmatrix}24\\ 16\end{pmatrix} = 4 \times \begin{pmatrix}6\\ 4\end{pmatrix}$$

Genel olarak bir $A$ matrisi için amaç

$$A\mathbf{u} = \lambda\mathbf{u}$$

eşitliğini sağlayan $\mathbf{u}$ vektörlerini ve $\lambda$ katsayılarını bulmaktır. Hoca, büyük harflerin matrisi, küçük harflerin vektörü gösterdiğini hatırlattı.

## 7. Özdeğer ve Özvektör Hesabı: Adım Adım Örnek

Belgede özvektörlerin nasıl bulunduğu anlatılmadığı için hoca kendi el yazısı notlarının fotoğrafını çekip ekranda paylaştı ve bunun üzerinden anlattı.

### 7.1 Karakteristik denklem

$A\mathbf{u} = \lambda\mathbf{u}$ eşitliğinde sağ taraf sola alınır. Her iki terimde de matris olsun diye $\lambda$, birim matris $I$ ile çarpılır:

$$A\mathbf{u} - \lambda I\mathbf{u} = 0$$

İki terimde ortak olan $\mathbf{u}$ paranteze alınır:

$$(A - \lambda I)\mathbf{u} = 0$$

$A - \lambda I$ tekil (singular) olmalıdır; eşdeğer olarak determinantı sıfıra eşitlenir (ekrandan, 00:55:00):

$$\det(A - \lambda I) = 0$$

Bu ilişkiden önce her $A$ matrisi için $\lambda$ değerleri, sonra her $\lambda$ için ona ait $\mathbf{u}$ vektörü hesaplanır.

### 7.2 Örnek: özdeğerler

Notlardaki örnek (ekrandan, 00:55:00):

$$A = \begin{pmatrix}2 & 1\\ 1 & 2\end{pmatrix}$$

Birim matrisin ana köşegeni 1, diğer gözleri 0'dır. Bu yüzden $A - \lambda I$ yazmak, yalnız $A$'nın ana köşegenindeki elemanlardan $\lambda$ çıkarmak demektir; köşegen dışındaki değerler değişmez:

$$\det\begin{pmatrix}2-\lambda & 1\\ 1 & 2-\lambda\end{pmatrix} = (2-\lambda)^2 - 1 = 0$$

Açılınca ikinci dereceden bir denklem çıkar:

$$4 - 4\lambda + \lambda^2 - 1 = 0 \quad\Rightarrow\quad \lambda^2 - 4\lambda + 3 = 0$$

Kökleri $\lambda = 1$ ve $\lambda = 3$'tür.

> **Ders sonrası not:** Hoca denklemi sözlü olarak "$\lambda^2 - 4\lambda + 4 = 0$" diye okudu; doğrusu $\lambda^2 - 4\lambda + 3 = 0$'dır. Hocanın verdiği kökler (1 ve 3) bu doğru denklemin kökleridir.

### 7.3 Örnek: özvektörler

Her $\lambda$ değeri $A\mathbf{u} = \lambda\mathbf{u}$ eşitliğine yazılır; bilinmeyen vektör $\mathbf{u} = (x, y)$ alınır (ekrandan, 01:00:00).

$\lambda = 3$ için:

$$\begin{pmatrix}2 & 1\\ 1 & 2\end{pmatrix}\begin{pmatrix}x\\ y\end{pmatrix} = 3\begin{pmatrix}x\\ y\end{pmatrix}$$

- Birinci satır: $2x + y = 3x \Rightarrow x = y$.
- İkinci satır: $x + 2y = 3y \Rightarrow x = y$.

İki bilinmeyen ve iki denklem var ama ikisi de aynı bilgiyi, $x = y$'yi veriyor. Hoca bunun kayda değer olduğunu söyledi: Burada önemli olan $x$ ve $y$'nin tek tek değerleri değil, vektörün yönelimidir. $x = 1$ seçilip $y = x$ alınırsa özvektör $(1, 1)$ olur; düzlemde bu, $x = y$ doğrusudur ve yeni eksenlerden birini oluşturur.

$\lambda = 1$ için benzer işlem $x = -y$ denklemini verir ve özvektör $(1, -1)$ bulunur. $x$'in her değerine karşılık $y$ onun negatifini alır; $x$ pozitifken $y$ negatif olan, koordinat düzleminin ikinci ve dördüncü bölgelerinden geçen bir doğrudur.

> **Ek bilgi (derste anlatılmadı):** Simetrik bir matrisin farklı özdeğerlere ait özvektörleri birbirine diktir. Bu örnekte $(1,1)$ ile $(1,-1)$'in iç çarpımı sıfırdır. Kovaryans matrisi de simetrik olduğu için PCA'da bulunan yeni eksenler her zaman birbirine diktir.

## 8. Temel Bileşen Analizinin Adımları

Matematik hatırlatmasından sonra hoca belgedeki yönteme (Method) döndü ve adımları sırayla izledi.

### 8.1 Adım 1: Veri setini al

Örnek olabildiğince basit tutulmuştur ki hem çizimi hem yorumu kolay olsun: iki boyutlu, 10 örnekli bir veri seti. Matrisin adı "Data"dır ve iki öznitelikten $(x, y)$ oluşur (ekrandan, 01:05:00; ilk satır sözlü, 01:03:39).

### 8.2 Adım 2: Ortalamayı çıkar

Her boyut için ortalama hesaplanır ve o boyuttaki her değerden çıkarılır (subtract the mean). Ortaya çıkan 10 satır 2 sütunluk yeni tabloya "DataAdjust" denir (ekrandan, 01:05:00):

| x | y | DataAdjust x | DataAdjust y |
|---|---|---|---|
| 2,5 | 2,4 | 0,69 | 0,49 |
| 0,5 | 0,7 | -1,31 | -1,21 |
| 2,2 | 2,9 | 0,39 | 0,99 |
| 1,9 | 2,2 | 0,09 | 0,29 |
| 3,1 | 3,0 | 1,29 | 1,09 |
| 2,3 | 2,7 | 0,49 | 0,79 |
| 2,0 | 1,6 | 0,19 | -0,31 |
| 1,0 | 1,1 | -0,81 | -0,81 |
| 1,5 | 1,6 | -0,31 | -0,31 |
| 1,1 | 0,9 | -0,71 | -1,01 |

Ortalamalar $\bar{x} = 1{,}81$ ve $\bar{y} = 1{,}91$'dir (python ile kontrol edildi; ilk satırın DataAdjust değerleri de python ile hesaplandı).

Hoca bu adımın geometrik anlamını vurguladı: Orijinal veri $xy$ düzleminin birinci bölgesinde dağılmıştır. Ortalamayı çıkarmak, bu dağılımın orta noktasını bulup onu koordinat düzleminin orijinine taşımak, yani bütün veriyi olduğu gibi kaydırmak demektir. Ortalaması çıkarılmış verinin grafiğinde noktalar orijin çevresinde dağılır.

### 8.3 Adım 3: Kovaryans matrisini hesapla

İki öznitelik olduğu için $2 \times 2$ bir kovaryans matrisi oluşturulur. Köşegendeki elemanlar her özniteliğin kendi varyansıdır; köşegen dışında $x$ ile $y$ arasındaki kovaryans bulunur. Hoca bu değeri "0,6154 diye gidiyor" diye okudu ve matris simetrik olduğu için sol alttaki değerin de aynı olduğunu hatırlattı.

Python ile hesaplanan matris (ekran görüntüsü karelerde yok):

$$C \approx \begin{pmatrix}0{,}6166 & 0{,}6154\\ 0{,}6154 & 0{,}7166\end{pmatrix}$$

### 8.4 Adım 4: Kovaryans matrisinin özdeğer ve özvektörlerini hesapla

Bulunan $2 \times 2$ matrisin özdeğerleri:

- $\lambda_1 \approx 0{,}049$
- $\lambda_2 \approx 1{,}28$

Hoca, özdeğerlerden birinin çok küçük, öbürünün çok büyük olduğuna dikkat çekti; bu fark ileride hangi eksenin tutulacağının göstergesidir.

Belgede özvektörler bir matrisin sütunları olarak verilir. Hoca birinci sütuna $\mathbf{u}_1$, ikinci sütuna $\mathbf{u}_2$ dedi:

- $\mathbf{u}_1 \approx (-0{,}735;\ 0{,}677)$, $\lambda_1 = 0{,}049$'a aittir.
- $\mathbf{u}_2 \approx (-0{,}677;\ -0{,}735)$, $\lambda_2 = 1{,}28$'e aittir.

<!-- BELİRSİZ: Kovaryans matrisi, özdeğerler ve özvektör matrisi ekranda gösterildi ama karelerde yok. u1'in ilk bileşeni altyazıda duyulmuyor; değerler python ile (0,0491; 1,2840; 0,6779; 0,7352) doğrulandı ve kaynak belgedeki işaretlerle yazıldı. -->

## 9. Özvektörlerin Grafik Üzerinde Yorumu

Hoca, tablet şarjı bittiği için PDF okuyucunun çizim araçlarını kullanarak grafiğin üzerine çizdi (ekrandan, 01:10:00 ve 01:20:00). Grafik, ortalaması çıkarılmış veriyi ve kovaryans matrisinin özvektörlerini birlikte gösterir ("Mean adjusted data with eigenvectors overlayed").

Önce veri bulutunu çevreleyen bir çizgi çizdi: noktalar sol alttan sağ üste uzanan dar bir bölgede dağılmıştır. Grafikte noktalı çizgilerle iki doğru vardır; bunlardan biri tam da verinin yönelimi üzerinde uzanır. Bu iki doğru kovaryans matrisinin özvektörleridir.

- **$\mathbf{u}_2$ (büyük özdeğer):** Hoca bunu, $x$ ekseninde yaklaşık 0,67 ve $y$ ekseninde yaklaşık 0,735 değerlerinin kesiştiği noktadan ve orijinden geçen doğru olarak çizdi. Bu doğru, veri bulutunun uzandığı köşegen doğrultusundadır (birinci ve üçüncü bölgelerden geçer).
- **$\mathbf{u}_1$ (küçük özdeğer):** Bileşenleri 0,735 ve 0,677 büyüklüğündedir; işaretleri zıt olduğu için ikinci ve dördüncü bölgelerden geçen, $\mathbf{u}_2$'ye dik olan öbür köşegendir.

Böylece başta çizdiğimiz $xy$ düzlemi dışında, $\mathbf{u}_1$-$\mathbf{u}_2$ yeni bir koordinat düzlemi olur. Ekranda artı işaretiyle gösterilen 10 nokta bu yeni koordinat düzlemine taşınır; noktaların yeri artık bu yeni eksenlere göre verilir. Bu bir dönüşüm işlemidir.

> **Ek bilgi (derste anlatılmadı):** Özvektörün işaretini tersine çevirmek aynı doğruyu verir. Bu yüzden $(-0{,}677;\ -0{,}735)$ ile hocanın çizdiği $(0{,}67;\ 0{,}735)$ noktası aynı ekseni tanımlar. Belgedeki grafik açıklamasında doğrular biraz farklı sayılarla (0,7407 ve 0,6719) etiketlenmiştir; kovaryans matrisinden hesaplanan değerler 0,6779 ve 0,7352'dir.

## 10. İzdüşüm ve Boyut Azaltma

Hoca şu soruyu sordu: Bu dönüşümü neden yapıyoruz, elimize ne geçecek?

### 10.1 Adım 5: Bileşen seçme ve öznitelik vektörü oluşturma

Belgenin beşinci adımı "choosing components and forming a feature vector" (bileşenleri seçme ve öznitelik vektörü oluşturma) adını taşır. Yeni $\mathbf{u}_1$-$\mathbf{u}_2$ düzleminde her örneğin bu eksenlere **izdüşümü** (projeksiyonu) alınır.

Hoca birkaç noktanın $\mathbf{u}_2$ üzerine izdüşümünü çizdi. Örneklerin $\mathbf{u}_2$ ekseni üzerindeki izdüşümleri çok geniş bir aralıkta değişir. Aynı noktaların $\mathbf{u}_1$ üzerine izdüşümleri ise çok daha dar bir aralıkta kalır.

### 10.2 Değişimin az olduğu ekseni atmak

Amacımız veri indirgemektir. Değişimin çok olduğu eksen hangisiyse onun üzerine izdüşüm alınır; değişimin az olduğu eksen ($\mathbf{u}_1$) veri setine hiç taşınmaz, o eksendeki değerler kullanılmaz. Böylece iki boyuttan bir boyuta inilir.

Yani bu yöntemde veri indirgeme boyut azaltma ile gerçekleşir: Veri yeni bir koordinat düzlemine geçirilir, değişimin en fazla olduğu eksenler seçilir, değişimin az olduğu eksenler atılır. Hoca, iki boyutlu düzlemde bunu görmenin ve yorumlamanın oldukça kolay olduğunu, konunun biraz karmaşık görünse de ilginç olduğunu söyledi.

> **Ders sonrası not:** Bu örnekte büyük özdeğerin payı $1{,}284 / (1{,}284 + 0{,}049) \approx \%96{,}3$'tür (python ile hesaplandı). Bölüm 11'deki %95 kuralına göre tek bileşen ($\mathbf{u}_2$) yeterlidir.

## 11. Çok Boyutlu Veride Bileşen Sayısının Seçimi

Bir öğrencinin sorusu üzerine hoca, boyut sayısı arttığında ne yapılacağını anlattı.

**Soru:** İki boyutta bu şekilde ilerleyebiliyoruz. Daha fazla boyut olduğunda bu yöntemi kullanmak hem bizim açımızdan hem model açısından zor olacaktır; orada nasıl bir yol izlemeliyiz?

**Cevap:** İki boyutlu düzlemde indirgeme yapacaksak ancak iki boyuttan bir boyuta düşebiliriz. Veri setinde 10 öznitelik (10 sütun) olduğunu düşünelim. Bu durumda kovaryans matrisi $10 \times 10$ olur; ondan 10 özdeğer ($\lambda$) ve 10 özvektör ($\mathbf{u}$) hesaplanır. Daha önce büyük özdeğerin önemli olduğunu söylemiştik; o hâlde bulunan özdeğerler büyükten küçüğe sıralanır (ekrandan, 01:30:00):

$$L_1 > L_2 > L_3 > \dots > L_{10}$$

(Hoca ekrana yazarken $\lambda$ yerine $L$ kullandı.) Sonra sırayla şu oranlara bakılır (ekrandan, 01:30:00):

$$\frac{L_1}{L_1 + L_2 + L_3 + \dots + L_{10}} \overset{?}{\geq} \%95$$

$$\frac{L_1 + L_2}{L_1 + L_2 + L_3 + \dots + L_{10}} \overset{?}{\geq} \%95$$

- İlk oran, 10 öznitelik yerine tek bir bileşen kullanmanın yetip yetmediğini kontrol eder.
- %95 sağlanmazsa $L_2$ eklenir: 10 öznitelik 2'ye düşürülebilir mi diye bakılır.
- O da sağlanmazsa $L_3$ eklenir ve eşik geçilene kadar böyle devam edilir.

Eşik %95 olmak zorunda değildir; örneğin %90 da seçilebilir. Bu aşama aşama yapılan bir işlemdir ve sonunda bir veri indirgeme (data reduction) gerçekleştirilmiş olur.

Sohbetten gelen bir soru da varyansın neden öznitelik önemini ölçmekte kullanıldığıydı.

**Soru:** Varyansı öznitelik önemini ölçmede kullanmamızın nedeni nedir?

**Cevap:** Varyansı yüksek olan ekseni kullanırız. Çizimde gördüğümüz gibi geniş bir aralıkta dağılım gösteren eksen, örnekleri ince ayrıntısıyla görebileceğimiz bir eksen sunar. Dar bir aralıkta değişim gösteren eksende örnekler birbiri üzerine geçer ve onları birbirinden ayırt etmek zorlaşır. Bu yüzden varyansın yüksek olduğu eksen daha değerli bir öznitelik olur.

> **Hocanın vurgusu:** Lambda değerinin büyük olmasına dikkat edin. Özdeğerler büyükten küçüğe sıralanır ve bileşenler bu sırayla eklenir.

> **Ek bilgi (derste anlatılmadı):** Bir özdeğer, verinin o özvektör doğrultusundaki varyansına eşittir; özdeğerlerin toplamı da kovaryans matrisinin köşegen toplamına (toplam varyansa) eşittir. Bu yüzden yukarıdaki oranlar "açıklanan varyans oranı" olarak da bilinir.

Hoca ayrıca, yeni koordinat düzleminde noktaların yerini (izdüşümünü) nasıl hesaplayacağımız gibi soruların, hazır araç kullanmadan yazılacak küçük bir Python uygulamasıyla daha net anlaşılacağını belirtti.

## Örnek Sorular

**1. Aynı ortalama, farklı yayılım** (ekrandan, 00:15:00)

$[0, 8, 12, 20]$ ve $[8, 9, 11, 12]$ dizilerinin ortalamalarını ve standart sapmalarını hesaplayın. Hangisinin standart sapması daha büyüktür, neden?

> **Çözüm (derste verildi):** İki dizinin de ortalaması 10'dur. Standart sapmalar ($n-1$ ile) birinci dizi için yaklaşık 8,33, ikinci dizi için yaklaşık 1,83'tür. Birinci dizinin değişim aralığı (0-20) daha geniş olduğu için standart sapması daha büyüktür.

**2. Çalışma saati ve puan kovaryansı** (ekrandan, 00:25:00)

Bölüm 4.2'deki 12 öğrencinin çalışma saati (H) ve puanı (M) için kovaryansı hesaplayın ve işaretini yorumlayın.

> **Çözüm:** Derste belgedeki sonuç (yaklaşık 104,53) okundu ve pozitif olduğu için iki değişkenin aynı yönde değiştiği söylendi. Python ile kontrol: $\bar{H} = 13{,}92$, $\bar{M} = 62{,}42$, çarpımlar toplamı yaklaşık $1352{,}4$, $\mathrm{cov}(H,M) \approx 1352{,}4 / 11 \approx 122{,}95$. Sonuç pozitiftir; daha çok çalışan öğrenciler genelde daha yüksek puan almıştır.

**3. Özvektör mü?** (ekrandan, 00:35:00)

$A = \begin{pmatrix}2 & 3\\ 2 & 1\end{pmatrix}$ için $(1,3)$ ve $(3,2)$ vektörlerinden hangisi özvektördür? Özdeğeri nedir?

> **Çözüm (derste verildi):** $A(1,3)^T = (11,5)^T$, $(1,3)$'ün katı değildir. $A(3,2)^T = (12,8)^T = 4(3,2)^T$; $(3,2)$ özvektördür, özdeğeri 4'tür.

**4. 2×2 matrisin özdeğer ve özvektörleri** (ekrandan, 00:55:00)

$A = \begin{pmatrix}2 & 1\\ 1 & 2\end{pmatrix}$ matrisinin özdeğerlerini ve özvektörlerini bulun.

> **Çözüm (derste verildi):** $\det(A - \lambda I) = (2-\lambda)^2 - 1 = \lambda^2 - 4\lambda + 3 = 0$, $\lambda = 1$ ve $\lambda = 3$. $\lambda = 3$ için $x = y$, özvektör $(1,1)$; $\lambda = 1$ için $x = -y$, özvektör $(1,-1)$.

**5. Daha fazla boyutta PCA** (derste sözlü, 01:23:40)

İki boyutlu veride değişimin az olduğu ekseni atarak bir boyuta iniyoruz. Daha fazla boyutlu veride kaç bileşen tutulacağına nasıl karar verilir?

> **Çözüm (derste verildi):** Kovaryans matrisinin özdeğerleri büyükten küçüğe sıralanır. Önce $L_1 / \sum L_i$, sonra $(L_1 + L_2) / \sum L_i$ hesaplanır ve oran seçilen eşiği (ör. %95) geçene kadar bileşen eklenir.

## Dersin Toparlaması

Bu derste veri indirgemenin öznitelik birleştirme tarafında Temel Bileşen Analizi işlendi. Önce yöntemin dayandığı matematik hatırlatıldı: ortalamanın tek başına yetmediği, standart sapmanın yayılımı ölçtüğü, kovaryansın iki özniteliğin birlikte nasıl değiştiğini gösterdiği ve kovaryans matrisinin köşegeninde varyanslar bulunan simetrik bir matris olduğu görüldü. Ardından $A\mathbf{u} = \lambda\mathbf{u}$ tanımı ve $\det(A - \lambda I) = 0$ karakteristik denklemiyle özdeğer ve özvektör hesabı örnek üzerinde yapıldı.

PCA adımlarında veri ortalaması çıkarılarak orijine taşındı, kovaryans matrisi kuruldu, özdeğer ve özvektörler hesaplandı. Özvektörler verinin yönelimini gösteren yeni eksenler oldu; büyük özdeğerli eksende izdüşümler geniş aralıkta, küçük özdeğerli eksende dar aralıkta kaldı. Değişimin az olduğu eksenler atılarak boyut azaltıldı. Çok boyutlu veride ise özdeğerler sıralanıp birikimli oran %95 gibi bir eşiği geçene kadar bileşen eklendi. Hoca, yeni düzlemde izdüşüm hesabının küçük bir Python uygulamasıyla daha iyi anlaşılacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
