# Ders 9 Genişletilmiş Notu: Kümeleme: Uzaklık ve Benzerlik Ölçüleri, K-Means ve Beklenti Maksimizasyonu (EM)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kümelemeye Giriş
- 2. Sayısal Öz Nitelikler İçin Uzaklık Ölçüleri
- 3. İkili Öz Nitelikler İçin Benzerlik Ölçüleri
- 4. K-Means Kümeleme Algoritması
- 5. K-Means Sayısal Örneği (K = 2 ve K = 3)
- 6. Gerçek Hayattan Bir Örnek: İlaçların Kümelenmesi
- 7. K-Means'in Zayıf Yönleri ve K Değerinin Seçimi
- 8. Beklenti Maksimizasyonu (EM) Kümeleme
- 9. Çok Boyutlu EM ve Uygulama Alanları
- Örnek Sorular

## 1. Kümelemeye Giriş

Ders, sınıflandırma konularından sonra denetimsiz öğrenmeye (unsupervised learning) geçişle başlar. Bu haftanın konu başlıkları K-Means kümeleme ve beklenti maksimizasyonu (Expectation Maximization, EM) kümelemesidir. Dersin bir bölümü İngilizce anlatılmıştır; EM bölümüne hoca Türkçe devam eder.

Ekrandaki giriş slaytı kümelemeyi şöyle tanımlar (ekrandan, 00:20:00):

- Kümeleme denetimsiz öğrenmedir.
- Veri gerektirir ama etiket (sınıf bilgisi) gerektirmez.
- Verideki örüntüleri bulur; örneğin e-postaları ya da arama sonuçlarını gruplar, müşteri alışveriş örüntülerini çıkarır, görüntülerdeki bölgeleri ayırır.
- Ne aradığımızı bilmediğimiz durumlarda yararlıdır.

Hoca, kümeleme algoritmalarının müşteri alışveriş örüntülerini bulmak, e-postaları içeriklerine göre ayırmak ve görüntü işleme gibi farklı alanlarda uygulanabildiğini söyler. Derste anılan yöntemler bölümlemeli (partitional) kümeleme ve onun en bilinen örneği K-Means, QT kümeleme, kendini düzenleyen özellik haritaları (self-organizing feature maps, SOM) ve EM kümelemesidir. Bu hafta K-Means ve EM ayrıntılı anlatılır.

<!-- BELİRSİZ: 00:17:33-00:19:30 arasında altyazı İngilizce anlatımda tekrar halüsinasyonlarına dönüşüyor; yöntem listesinin slayttaki tam hâli karelerden okunamadı. -->

## 2. Sayısal Öz Nitelikler İçin Uzaklık Ölçüleri

Kümeleme, örnekleri birbirlerine benzerliklerine göre gruplar. Bu yüzden önce iki örneğin ne kadar yakın olduğunu ölçen bir uzaklık (ya da benzerlik) ölçüsü seçilir.

### 2.1 Öklid Uzaklığı

Veri setinde $p$ öz nitelik olduğunu varsayalım. $p$ boyutlu uzayda $x$ ve $y$ örnekleri arasındaki Öklid uzaklığının genel biçimi şudur:

$$d(x,y) = \sqrt{\sum_{i=1}^{p} (x_i - y_i)^2}$$

Her öz nitelik için fark alınır, farkın karesi alınır, kareler toplanır ve toplamın karekökü alınır. Hoca, $P$'nin veri setindeki öz nitelik sayısı olduğuna dikkat çeker. Öklid uzaklığına $L_2$ norm uzaklığı da denir.

### 2.2 Manhattan (Şehir Bloğu) Uzaklığı

Manhattan uzaklığı, şehir bloğu (city block) uzaklığı ya da $L_1$ norm uzaklığı olarak da bilinir. Farkın karesi yerine yalnız farkın mutlak değeri alınır ve farklar toplanır:

$$d(x,y) = \sum_{i=1}^{p} |x_i - y_i|$$

Hoca bunu tahtada iki boyutlu düzlemde gösterir (ekrandan, 00:25:00). Düzlemde $A(x_1, y_1)$ ve $B(x_2, y_2)$ örnekleri vardır. Fikir şudur: arada bir bina (blok) varmış gibi düşünülür; $A$'dan $B$'ye çapraz gidilemez, önce bir eksen boyunca, sonra diğer eksen boyunca yürünür. Bu yüzden:

$$d_{L_1}(A,B) = |x_1 - x_2| + |y_1 - y_2|$$

Öklid uzaklığı ise $A$ ile $B$ arasındaki düz çizgidir.

### 2.3 Minkowski Uzaklığı

Minkowski uzaklığında eksenlerdeki farkların $q$. kuvvetleri alınır, toplanır ve toplamın $q$. dereceden kökü alınır:

$$d(x,y) = \left(\sum_{i=1}^{p} |x_i - y_i|^q\right)^{1/q}$$

$q = 2$ alındığında Öklid uzaklığı elde edilir. Hoca, Minkowski uzaklığının hesap karmaşıklığı yüksek olduğu için hesaplarda pek tercih edilmediğini, çoğunlukla şehir bloğu ya da Öklid uzaklığının kullanıldığını söyler.

> **Ek bilgi (derste anlatılmadı):** $q = 1$ alındığında Minkowski uzaklığı Manhattan uzaklığına dönüşür. Bu yüzden Manhattan ve Öklid, Minkowski ailesinin iki özel durumu olarak görülebilir.

### 2.4 Mesafe Ölçüsünün Özellikleri

Ekrandaki "Mesafe Ölçüsü" slaytı bir mesafe ölçüsünün sağlaması gereken özellikleri sıralar (ekrandan, 00:30:00):

- $d(i,j) \ge 0$: uzaklık negatif olamaz.
- $d(i,i) = 0$: bir örneğin kendisine uzaklığı sıfırdır.
- $d(i,j) = d(j,i)$: örneklerin yeri değiştirildiğinde uzaklık değişmez.
- $d(i,j) \le d(i,k) + d(k,j)$: üçgen eşitsizliği.

## 3. İkili Öz Nitelikler İçin Benzerlik Ölçüleri

Veri setinde sayısal yerine ikili (binary) öz nitelikler, yani evet/hayır ya da 0/1 değerli öz nitelikler varsa farklı benzerlik ölçüleri kullanılır.

### 3.1 Olumsallık Tablosu

İkili öz nitelikleri olan iki örnek ($i$ ve $j$) öz nitelik öz nitelik karşılaştırılır ve eşleşmeler bir olumsallık (contingency) tablosunda sayılır:

| | $j$ = 0 | $j$ = 1 |
|---|---|---|
| $i$ = 0 | $a$ (0-0 eşleşme) | $b$ (0-1) |
| $i$ = 1 | $c$ (1-0) | $d$ (1-1 eşleşme) |

$a$, $b$, $c$ ve $d$ sayılarına göre farklı benzerlik ölçüleri hesaplanır.

### 3.2 Basit Eşleşme Katsayısı ve Jaccard Katsayısı

Basit eşleşme katsayısında (simple matching coefficient, SMC) 0-0 ve 1-1 eşleşmelerin toplamı, toplam öz nitelik sayısına bölünür:

$$\text{Sim}_{SMC}(i,j) = \frac{a + d}{a + b + c + d}$$

Jaccard katsayısında ise 0-0 eşleşmeleri ($a$) kullanılmaz:

$$\text{Sim}_{Jaccard}(i,j) = \frac{d}{b + c + d}$$

Hoca, SMC'de $a$'nın kullanıldığını ama Jaccard'da kullanılmadığını özellikle belirtir.

> **Ek bilgi (derste anlatılmadı):** Jaccard'ın 0-0 eşleşmelerini dışarıda bırakması, "0" değerinin "özellik yok" anlamına geldiği asimetrik ikili öz niteliklerde (ör. bir ürünün sepette olmaması) ortak yokluğun benzerlik sayılmasını önler.

### 3.3 Örnek: İki İkili Örneğin Benzerliği

Ekrandaki örnekte iki örnek ve sekiz ikili öz nitelik vardır (ekrandan, 00:35:00):

- $i = 1\,0\,0\,1\,1\,0\,1\,1$
- $j = 1\,1\,0\,0\,0\,1\,1\,0$

Hoca eşleşmeleri tahtada renkli halkalarla tek tek işaretler (ekrandan, 00:40:00). Öz nitelikler sırayla karşılaştırıldığında:

| Öz nitelik | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|
| $i$ | 1 | 0 | 0 | 1 | 1 | 0 | 1 | 1 |
| $j$ | 1 | 1 | 0 | 0 | 0 | 1 | 1 | 0 |
| Eşleşme | 1-1 | 0-1 | 0-0 | 1-0 | 1-0 | 0-1 | 1-1 | 1-0 |

Buradan $a = 1$, $b = 2$, $c = 3$, $d = 2$ bulunur. Dört sayının toplamı öz nitelik sayısına, yani 8'e eşittir; çünkü veri sekiz boyutludur.

- Basit eşleşme katsayısı: $\text{Sim}_{SMC}(i,j) = \dfrac{1 + 2}{8} = \dfrac{3}{8} = 0.375$
- Jaccard katsayısı: $\text{Sim}_{Jaccard}(i,j) = \dfrac{2}{2 + 3 + 2} = \dfrac{2}{7} \approx 0.286$

> **Ders sonrası not:** Slaytta Jaccard benzerliği $2/8$ yazıyor (ekrandan, 00:35:00). Jaccard tanımında payda $b + c + d = 7$ olduğundan doğru değer, hocanın tahtada hesapladığı $2/7$'dir.

Son olarak hoca, kategorik öz niteliklerde Hamming uzaklığının kullanıldığını hatırlatır. Bunlar kümeleme algoritmalarında kullanılan uzaklık ve benzerlik ölçüleridir.

## 4. K-Means Kümeleme Algoritması

### 4.1 Problem Tanımı

Elimizde $N$ nesneden oluşan bir veri seti vardır. Nesnelerin öz nitelikleri bilinir ama sınıf etiketleri yoktur. Amaç bu veriyi $K$ kümeye bölmektir; küme sayısı $K$, nesne sayısı $N$'den küçük olmalıdır. Hoca, K-Means'in Gauss karışımları için kullanılan beklenti maksimizasyonu algoritmasına benzediğini, bu fikir anlaşılınca EM'in de kolay uygulanacağını söyler.

Ekrandaki tanım şöyledir (ekrandan, 00:45:00): K-Means, $N$ veri noktasını $K$ ayrık (disjoint) alt kümeye ($S_j$) bölen ve kareler toplamı ölçütünü en küçük yapmaya çalışan bir algoritmadır:

$$J = \sum_{j=1}^{K} \sum_{n \in S_j} |x_n - \mu_j|^2$$

Burada $x_n$, $n$. veri noktasını gösteren vektör; $\mu_j$ ise $S_j$ kümesindeki noktaların geometrik merkezidir (centroid). Her örneğin kendi küme merkezine uzaklığının karesi alınır, küme içinde toplanır ve bu işlem bütün kümeler için yapılıp toplanır. $K$ pozitif bir tam sayıdır ve amaç bu maliyet fonksiyonunu en küçük yapmaktır.

### 4.2 Adımlar

Hocanın anlatımına göre algoritma şöyle işler:

1. Küme sayısı $K$ belirlenir; problemde bu değer bize verilmiştir.
2. Başlangıç küme merkezleri (initial centroids) seçilir, örneğin veri setinden $K$ örnek.
3. Her örneğin merkezlere uzaklığı hesaplanır; örnek en yakın merkezin kümesine atanır.
4. Her küme için üyelerin ortalaması alınarak yeni küme merkezi hesaplanır.
5. Yakınsama sağlanana kadar 3. adıma dönülür.

Ekrandaki slaytın 3. ve 4. adımları ayrıca şunu söyler (ekrandan, 00:50:00): her örnek sırayla alınır ve her kümenin merkezine uzaklığı hesaplanır. Örnek en yakın merkezli kümede değilse o kümeye geçirilir; hem örneği kazanan hem de kaybeden kümenin merkezi güncellenir. Bu adım, eğitim örnekleri üzerinden bir geçiş yeni bir atama yapmayana kadar tekrarlanır.

<!-- BELİRSİZ: Slaytın 1. ve 2. adımlarının tam metni karelerde görünmüyor; 00:46:40-00:48:41 arasında altyazı halüsinasyon tekrarlarına dönüşüyor. Adımlar hocanın anlatımından kuruldu. -->

### 4.3 Durma Kuralı

İşlem iteratiftir: yeni merkezlerle uzaklıklar tekrar hesaplanır, en küçük uzaklığa göre üyelik belirlenir, yeni merkezler bulunur. Durma (sonlandırma) kuralı olarak kümeler arasında yer değiştiren nesne kalmaması kullanılabilir. Maliyet fonksiyonu için bir alt sınır vermek de bir durma kuralı olabilir.

## 5. K-Means Sayısal Örneği (K = 2 ve K = 3)

### 5.1 Veri ve Başlangıç

Ekrandaki küçük iki boyutlu veri seti şöyledir (ekrandan, 00:55:00):

| Örnek | Değişken 1 | Değişken 2 |
|---|---|---|
| 1 | 1.0 | 1.0 |
| 2 | 1.5 | 2.0 |
| 3 | 3.0 | 4.0 |
| 4 | 5.0 | 7.0 |
| 5 | 3.5 | 5.0 |
| 6 | 4.5 | 5.0 |
| 7 | 3.5 | 4.5 |

Amaç veriyi iki kümeye bölmektir; K-Means'te küme sayısının baştan bilinmesi gerekir ve burada $K = 2$ verilmiştir. Başlangıç merkezleri rastgele seçilebilir; bu örnekte 1. ve 4. örnekler başlangıç merkezi seçilir. Hoca tabloyu tahtaya yazar ve yedi örneği düzlemde işaretler (ekrandan, 01:15:00). Değişken 1 ve değişken 2, veri setindeki iki öz niteliktir.

### 5.2 Birinci İterasyon

1. örneğin 1. merkeze uzaklığı sıfırdır, çünkü bu örnek merkezin kendisidir. Hesabı göstermek için hoca 1. örneğin 2. merkeze ($(5, 7)$) uzaklığını yazar:

$$d = \sqrt{(1 - 5)^2 + (1 - 7)^2} = \sqrt{16 + 36} = \sqrt{52} \approx 7.21$$

Bütün örnekler için Öklid uzaklıkları tabloya yazılır (ekrandan, 01:20:00); satırlar örnekleri, sütunlar merkezleri gösterir:

| Örnek | Merkez 1 (1.0, 1.0) | Merkez 2 (5.0, 7.0) | Küme |
|---|---|---|---|
| 1 | 0 | 7.21 | 1 |
| 2 | 1.12 | 6.10 | 1 |
| 3 | 3.61 | 3.61 | 1 |
| 4 | 7.21 | 0 | 2 |
| 5 | 4.72 | 2.5 | 2 |
| 6 | 5.31 | 2.06 | 2 |
| 7 | 4.30 | 2.92 | 2 |

3. örneğin iki merkeze uzaklığı eşittir. Hoca, bu durumda hangi kümenin seçildiğinin önemli olmadığını söyler: işlem iteratif olduğundan örnek yanlış kümeye eklense bile algoritma kendini düzeltir. Burada 3. örnek birinci kümeye atanır.

Böylece kümeler {1, 2, 3} ve {4, 5, 6, 7} olur. Yeni merkezler üyelerin ortalamasıdır (ekrandan, 01:20:00):

$$m_1 = \left(\tfrac{1}{3}(1.0 + 1.5 + 3.0),\ \tfrac{1}{3}(1.0 + 2.0 + 4.0)\right) = (1.83,\ 2.33)$$

$$m_2 = \left(\tfrac{1}{4}(5.0 + 3.5 + 4.5 + 3.5),\ \tfrac{1}{4}(7.0 + 5.0 + 5.0 + 4.5)\right) = (4.12,\ 5.38)$$

Hoca, birinci merkezin yerinin değiştiğini tahtada gösterir.

> **Ders sonrası not:** Altyazıda merkezler "1.83, 2.32" ve "4.12, 5.30" diye geçiyor. Slayttaki ve hesaplanan değerler $(1.83, 2.33)$ ve $(4.125, 5.375) \approx (4.12, 5.38)$'dir.

### 5.3 İkinci İterasyon

Yeni merkezlerle uzaklıklar tekrar hesaplanır (ekrandan, 01:25:00):

| Örnek | Merkez 1 (1.83, 2.33) | Merkez 2 (4.12, 5.38) |
|---|---|---|
| 1 | 1.57 | 5.38 |
| 2 | 0.47 | 4.28 |
| 3 | 2.04 | 1.78 |
| 4 | 5.64 | 1.84 |
| 5 | 3.15 | 0.73 |
| 6 | 3.78 | 0.54 |
| 7 | 2.74 | 1.08 |

Tablodaki gri alanlar en yakın merkezi gösterir. 3. örnek artık ikinci merkeze daha yakındır; birinci kümeden çıkar ve ikinci kümeye geçer. Yeni kümeler {1, 2} ve {3, 4, 5, 6, 7}, sonraki merkezler $m_1 = (1.25,\ 1.5)$ ve $m_2 = (3.9,\ 5.1)$ olur.

Bu merkezlerle yapılan üçüncü iterasyonda hiçbir örnek küme değiştirmez; sonuçta birinci kümenin iki, ikinci kümenin beş üyesi vardır.

> **Ders sonrası not:** Tablolardaki değerler python ile yeniden hesaplandı. Küçük farklar (ör. 6. örnekte 5.31 ile 5.32, 3. örnekte 2.04 ile 2.03) slaytta yuvarlanmış merkezlerin ve yuvarlamanın kullanılmasından kaynaklanır; kümeler ve merkezler aynıdır.

### 5.4 Aynı Veri K = 3 ile

Aynı slayt üzerinden $K = 3$ ile çözüm de gösterilir. Bu kez veri setindeki ilk üç örnek (1, 2 ve 3) başlangıç merkezi seçilir (ekrandan, 01:30:00).

Birinci adımın uzaklık tablosu:

| Örnek | $m_1$ = 1 | $m_2$ = 2 | $m_3$ = 3 | Küme |
|---|---|---|---|---|
| 1 | 0 | 1.11 | 3.61 | 1 |
| 2 | 1.12 | 0 | 2.5 | 2 |
| 3 | 3.61 | 2.5 | 0 | 3 |
| 4 | 7.21 | 6.10 | 3.61 | 3 |
| 5 | 4.72 | 3.61 | 1.12 | 3 |
| 6 | 5.31 | 4.24 | 1.80 | 3 |
| 7 | 4.30 | 3.20 | 0.71 | 3 |

4., 5., 6. ve 7. örnekler en yakın olarak üçüncü kümeye düşer. Birinci iterasyonun sonunda birinci ve ikinci kümelerin birer üyesi, üçüncü kümenin beş üyesi vardır. Tek üyeli kümelerin merkezi değişmez, çünkü merkez o tek örneğin kendisidir. Üçüncü kümenin merkezi beş üyenin ortalamasıdır: $m_3 = (3.9,\ 5.1)$.

İkinci adımın tablosu (ekrandan, 01:30:00):

| Örnek | $m_1$ (1.0, 1.0) | $m_2$ (1.5, 2.0) | $m_3$ (3.9, 5.1) | Küme |
|---|---|---|---|---|
| 1 | 0 | 1.11 | 5.02 | 1 |
| 2 | 1.12 | 0 | 3.92 | 2 |
| 3 | 3.61 | 2.5 | 1.42 | 3 |
| 4 | 7.21 | 6.10 | 2.20 | 3 |
| 5 | 4.72 | 3.61 | 0.41 | 3 |
| 6 | 5.31 | 4.24 | 0.61 | 3 |
| 7 | 4.30 | 3.20 | 0.72 | 3 |

Atama değişmez. Nihai durumda veri üç kümeye ayrıldığında kümeler {1}, {2} ve {3, 4, 5, 6, 7} olur.

> **Ders sonrası not:** Tabloda 1. örneğin $m_2$'ye uzaklığı 1.11, 2. örneğin $m_1$'e uzaklığı 1.12 yazıyor. İkisi aynı uzaklıktır ($\sqrt{1.25} \approx 1.118$); fark yalnız yuvarlamadandır.

## 6. Gerçek Hayattan Bir Örnek: İlaçların Kümelenmesi

Hoca, ilaç ve aşı tasarımında makine öğrenmesi yöntemlerinden yararlanıldığını belirterek bir gerçek hayat örneğine geçer. Örnekte A, B, C ve D adlı dört ilaç vardır. Birinci öz nitelik ağırlık indeksi (weight index), ikinci öz nitelik pH değeridir. Veri iki kümeye ayrılmak istenir; küme sayısı yine dışarıdan verilmiştir.

Ekrandaki veri ve uzaklık matrisi şöyledir (ekrandan, 01:35:00):

| İlaç | Ağırlık indeksi (X) | pH (Y) |
|---|---|---|
| A | 1 | 1 |
| B | 2 | 1 |
| C | 4 | 3 |
| D | 5 | 4 |

Başlangıç merkezleri birinci ve ikinci örneklerdir: $c_1 = (1, 1)$ ve $c_2 = (2, 1)$. Örnekler küçük olduğu için düzlemde çizilebilir: yatay eksende ağırlık indeksi, dikey eksende pH vardır. Hoca, yüksek boyutlu veride çizim yapmanın mümkün olmadığını, o zaman yalnız hesapla ilerlendiğini hatırlatır.

Uzaklıklar bir matris biçiminde yazılır. Matrisin birinci satırı her nesnenin birinci merkeze, ikinci satırı ikinci merkeze uzaklığıdır; her sütun bir nesneyi gösterir:

$$D^0 = \begin{bmatrix} 0 & 1 & 3.61 & 5 \\ 1 & 0 & 2.83 & 4.24 \end{bmatrix}$$

Örneğin C = (4, 3) ilacının birinci merkeze uzaklığı $\sqrt{(4-1)^2 + (3-1)^2} = 3.61$, ikinci merkeze uzaklığı $\sqrt{(4-2)^2 + (3-1)^2} = 2.83$'tür. Hoca, bu matris yapısının kod yazarken işi kolaylaştırabileceğini, ama kâğıt üzerinde hesapta gerekli olmadığını söyler.

Her sütunda en küçük değere bakılarak üyelik belirlenir: A birinci kümede, B, C ve D ikinci kümededir. Birinci kümenin tek üyesi olduğu için merkezi yerinde kalır; ikinci kümenin merkezi üç üyenin ortalamasıdır, $\left(\tfrac{11}{3}, \tfrac{8}{3}\right) \approx (3.67,\ 2.67)$ (ara adım eklendi). Bir sonraki iterasyonda B birinci kümeye geçer. Sonuçta her kümede iki ilaç kalır ({A, B} ve {C, D}); merkezler iki üyenin orta noktasıdır, $(1.5,\ 1)$ ve $(4.5,\ 3.5)$ (ara adım eklendi).

> **Ders sonrası not:** Hoca slayttaki ikinci matrisin (grup matrisi) ne gösterdiğini anlayamadığını söyleyip geçti. Bu matris büyük olasılıkla her nesnenin hangi gruba atandığını 1 ve 0 ile gösteren grup matrisidir: ilk iterasyonda birinci satır $[1, 0, 0, 0]$, ikinci satır $[0, 1, 1, 1]$ olur.

## 7. K-Means'in Zayıf Yönleri ve K Değerinin Seçimi

### 7.1 Başlangıç Merkezlerinin Etkisi

> **Hocanın vurgusu:** Başlangıç küme merkezlerinin nerede seçildiği çok önemlidir ve nihai kümeleri değiştirebilir. Bu, K-Means'in en büyük dezavantajıdır.

Hoca bunu tahtada bir örnekle gösterir. Doğasına bakıldığında dört kümeye ayrılması gereken bir veri seti çizer, ama algoritmaya $K = 2$ verir. Başlangıç merkezlerinin yerine göre algoritma veriyi bir biçimde iki kümeye bölebilir; merkezler başka yerden verildiğinde ise veriyi başka bir biçimde iki kümeye bölebilir.

Rastgele seçilen başlangıç merkezlerinin veri setindeki örneklerden seçilmesi zorunlu değildir. Veri incelenip her iki eksendeki değişim aralığına bakılarak düzlemde rastgele bir nokta da seçilebilir. Uygun noktalar seçmek, algoritmanın daha hızlı yakınsamasını sağlar ve işi kolaylaştırır.

### 7.2 Ortak Merkezli Veri

İkinci dezavantaj, bazı veri setlerinde kümelemenin hiç yapılamamasıdır. Hoca tahtaya ortak merkezli (co-centric) bir veri çizer (ekrandan, 01:45:00): ortada birbirine yakın konumlanmış bir grup örnek ($C_1$) ve onu dışarıdan halka biçiminde çevreleyen ikinci bir grup ($C_2$).

İnsan gözü bu veriyi iki kümeye ayır dendiğinde ortadaki grubu bir küme, halka biçimli bölgedeki veriyi ikinci küme sayar. K-Means bu kümeleri ayıramaz; çünkü iki kümenin merkez noktası aynıdır. Algoritma hep küme merkezlerini hesaplayıp merkezlere olan uzaklıktan yola çıktığı için böyle bir veride tıkanır. Hoca, ortak merkezli ve yakınlığa göre gruplanmış bu tür veriler için K-Means yerine DBSCAN yönteminin daha elverişli olduğunu söyler.

### 7.3 K Değerinin Seçimi: Dirsek Yöntemi

Küme sayısı bilinmiyorsa K-Means farklı $K$ değerleriyle (ör. 3, 4, 5, 6) çalıştırılır ve her çözüm için daha önce $J$ ile gösterilen kareler toplamı maliyeti hesaplanır. Maliyetin $K$'ya göre grafiği çizilir. Grafikte maliyet önce belirgin biçimde düşer, belli bir noktadan sonra düşüş düz bir çizgiye döner. Grafiğin dirsek yaptığı bu noktadaki $K$ değeri ideal $K$ kabul edilir.

Bazı uygulamalarda küme sayısı baştan bellidir. Örneğin bir hastalığın üç farklı formu olduğu biliniyorsa hasta verisi hep üç kümeye ayrılır. Küme sayısı bilinmeden başlanıyorsa K-Means'te $K$'nın en uygun değerini bulmak için mutlaka bir analiz yapılmalıdır.

## 8. Beklenti Maksimizasyonu (EM) Kümeleme

Hoca EM yöntemini, öğrencilerle paylaşılan "kmeans_em" adlı dokümanın üzerinde çizip yazarak anlatır. Dokümanın ilk kısmı kümelemenin ne olduğunu ve kareler toplamı cinsinden verilen maliyet fonksiyonunu özetler: her örneğin ait olduğu kümenin merkezine uzaklığının karesi, bütün örnekler ve bütün kümeler için toplanır ve en küçük yapılmaya çalışılır.

> **Hocanın vurgusu:** Çok önemli bir konu; dikkatle dinleyin. Yöntemin farklı uygulama alanlarını da düşünün.

### 8.1 Sert Atama ve Yumuşak Atama

EM yöntemi kendi içinde normal dağılım (Gauss dağılımı) kullanır ve bu dağılımın model parametrelerini bulmak için en çok olabilirlik kestiriminden (maximum likelihood estimates) yararlanır. Dokümana göre EM, K-Means yönteminin doğal bir uzantısıdır (ekrandan, 02:10:00).

- K-Means'te bir nokta yalnız bir kümenin elemanı olabilir. Buna sert atama (hard assignment) denir. Parçalama sonunda birbiriyle örtüşmeyen (disjoint) alt kümeler oluşur; örnek, en yakın merkezin kümesine aittir, diğerlerine ait değildir.
- EM'de her nokta bütün kümelere belli bir olasılıkla üye kabul edilir. Buna yumuşak atama (soft assignment) denir. Örneğin bir örnek %80 A kümesinin, %20 B kümesinin elemanı olabilir.
- Başka bir deyişle K-Means'te bir noktanın bir kümeye ait olma olasılığı $P(x \mid C)$ ya 0 ya 1'dir; EM'de ise $[0, 1]$ aralığında herhangi bir değer alabilir.

### 8.2 Bayes Teoremi

EM yönteminde Bayes teoreminden yararlanılır; bu teorem istatistikte ve naive Bayes sınıflandırmasında görülmüştü. Bir $x_j$ örneğinin $C_i$ kümesine ait olma olasılığı:

$$P(C_i \mid x_j) = \frac{P(x_j \mid C_i)\, P(C_i)}{P(x_j)}, \qquad P(x_j) = \sum_{a=1}^{k} P(x_j \mid C_a)\, P(C_a)$$

Terimlerin adları önemlidir:

- $P(C_i \mid x_j)$: sonsal olasılık (posterior probability), $x_j$ örneğinin $C_i$ kümesine ait olma olasılığı.
- $P(C_i)$: önsel olasılık (prior probability); veri setinden hesaplanabilir.
- $P(x_j \mid C_i)$: olabilirlik (likelihood). Kümenin normal dağılım gösterdiği varsayılarak, normal dağılım denkleminde $x_j$ yerine yazılarak hesaplanır. Naive Bayes uygulamasında da böyle yapılmıştı.
- Paydadaki $P(x_j)$: normalizasyon terimi.

Dokümanın ifadesiyle Bayes teoremi, bilmediğimiz bir şeyi (bir nokta verildiğinde kümenin sonsal olasılığını), küme verildiğinde noktanın olabilirliği cinsinden bulmamızı sağlar. Yaygın varsayım, her kümenin bir normal dağılım izlediği ve verinin $k$ normal dağılımın karışım modelinden (mixture model) üretildiğidir.

### 8.3 Tek Boyutlu EM: Problem

Yöntemin adım adım nasıl çalıştığını anlamak için doküman önce tek boyutlu durumu ele alır (ekrandan, 02:15:00). $K = 2$ seçildiğini, yani verinin iki normal dağılımın karışımından oluştuğunu varsayalım: $f(x \mid \mu_1, \sigma_1^2)$ ve $f(x \mid \mu_2, \sigma_2^2)$. Her dağılımın kendi ortalaması ($\mu$) ve varyansı ($\sigma^2$) vardır.

Hoca tahtada bir boyutlu eksen üzerinde iki Gauss eğrisi çizer: biri daha dar (varyansı küçük), diğeri daha geniş (varyansı büyük). Her eğri bir kümeyi temsil eder; x ekseni veri setindeki tek öz niteliktir. Ancak elimizde yalnız bu karışımdan üretilmiş veri noktaları vardır; iki kümenin parametreleri ($\mu_1, \sigma_1^2, \mu_2, \sigma_2^2$) bilinmez. Amaç bu parametreleri EM yaklaşımıyla kestirmektir. EM üç adımdan oluşur: başlatma, beklenti ve maksimizasyon.

### 8.4 Başlatma Adımı

Her $C_i$ kümesi ($i = 1, 2, \ldots, k$) için $\mu_i$ ve $\sigma_i^2$ rastgele atanır. Küme olasılıkları da başlangıçta eşit alınır (ekrandan, 02:20:00):

$$P(C_i) = \frac{1}{k}$$

İki küme varsa her kümenin başlangıç olasılığı $1/2$'dir.

### 8.5 Beklenti Adımı

$k$ kümenin parametreleri ($\mu_i, \sigma_i^2, P(C_i)$) verildiğinde, bütün $x_j$ noktaları ($j = 1, \ldots, n$) ve bütün $C_i$ kümeleri için olabilirlik normal dağılımdan hesaplanır (ekrandan, 02:20:00):

$$P(x_j \mid C_i) = f(x_j \mid \mu_i, \sigma_i^2) = \frac{1}{\sqrt{2\pi}\,\sigma_i}\, e^{-\frac{(x_j - \mu_i)^2}{2\sigma_i^2}}$$

Hoca bunu çizim üzerinde açıklar: x ekseninde bir değer alınır. Bu değerin $C_1$ kümesine ait olma olabilirliği, dikey çizginin $C_1$ eğrisini kestiği noktadaki değerdir; $C_2$'ye ait olma olabilirliği ise aynı çizginin $C_2$ eğrisini kestiği noktadadır. Yani aynı nokta için her iki küme için ayrı ayrı olabilirlik hesaplanır.

Sonra bu olabilirlikler Bayes teoreminde yerine yazılarak sonsal olasılık bulunur (ekrandan, 02:25:00):

$$P(C_i \mid x_j) = \frac{f(x_j \mid \mu_i, \sigma_i^2) \cdot P(C_i)}{\sum_{a=1}^{k} f(x_j \mid \mu_a, \sigma_a^2) \cdot P(C_a)}$$

Böylece elimizdeki $x_j$ örneğinin $C_1$ ve $C_2$ kümelerine ait olma olasılıkları ayrı ayrı bulunur.

### 8.6 Maksimizasyon Adımı

Bütün sonsal olasılıklar bilindiğinde küme parametreleri yeniden kestirilir. Kolaylık için $w_i(x_j) = P(C_i \mid x_j)$, $x_j$ noktasının $C_i$ kümesi için ağırlığı olarak tanımlanır (ekrandan, 02:25:00).

K-Means'te her örneğin hangi kümeye ait olduğu belirlenip yeni merkez üyelerin düz ortalamasıyla bulunuyordu; bütün üyeler eşit öneme sahipti. EM'de ise artık "üye" tanımı yoktur, her örnek her kümeye belli oranda aittir. Bu yüzden yeni merkez ağırlıklı ortalama (weighted mean) ile bulunur:

$$\mu_i' = \frac{\sum_{j=1}^{n} w_i(x_j)\, x_j}{\sum_{j=1}^{n} w_i(x_j)}$$

Veri setindeki $n$ örneğin her biri, o kümeye ait olma ağırlığıyla çarpılarak merkeze katkı yapar; payda bütün ağırlıkların toplamıdır ve normalizasyon sağlar. Örneğin bir nokta $C_1$'e daha yakınsa ona daha yüksek olasılıkla aittir; ama $C_2$'ye de belli oranda yakın olduğu için $C_2$'nin merkezine de etkisi olur. K-Means ise bu noktayı yalnız $C_1$ için kullanırdı.

Ardından kümenin varyansı yine ağırlıklı olarak hesaplanır (ekrandan, 02:35:00):

$$\sigma_i'^2 = \frac{\sum_{j=1}^{n} w_i(x_j)\,(x_j - \mu_i)^2}{\sum_{j=1}^{n} w_i(x_j)}$$

Normal varyans hesabındaki $(x - \mu)^2$ terimi bu kez ağırlıkla çarpılır ve bütün noktalar katkı yapar. K-Means'te yalnız merkezi hesaplamak yetiyordu; EM'de varyans da gerekir, çünkü bunlar normal dağılımın parametreleridir ve kümeler iteratif olarak yeniden düzenlendikçe güncellenmeleri gerekir.

Son olarak her kümenin olasılığı, o kümeye ait toplam ağırlığın bütün ağırlıklara oranı olarak hesaplanır:

$$P'(C_i) = \frac{\sum_{j=1}^{n} w_i(x_j)}{\sum_{a=1}^{k} \sum_{j=1}^{n} w_a(x_j)}$$

Örneğin $P(C_1)$ hesaplanıyorsa $n$ örneğin birinci kümeye ait olma ağırlıkları ($w_1(x_j)$) toplanır; bütün kümelerin ağırlık toplamına bölünerek küme olasılıklarının toplamının 1'i aşmaması sağlanır. Başlatmada rastgele atanan üç parametre ($\mu_i$, $\sigma_i^2$, $P(C_i)$) böylece artık veriden hesaplanır hâle gelir.

Güncellenmiş parametrelerle beklenti ve maksimizasyon adımları yakınsamaya kadar, örneğin ortalamalar bir iterasyondan diğerine çok az değişene kadar tekrarlanır. Doküman ayrıca normal karışım modeli varsayılmasına rağmen EM yaklaşımının, $P(x_j \mid C_i)$'nin hesaplanma biçimi değiştirilerek başka modellere de uygulanabileceğini belirtir (ekrandan, 02:35:00).

Hoca, birden fazla Gauss dağılımının bulunduğu bu yapıya Gauss karışım modeli (Gaussian Mixture Model) dendiğini ve her örneğin bu dağılımlara belli oranlarda ait olduğu fikrinin buradan çıktığını vurgular.

> **Hocanın vurgusu:** Tek boyutlu bölümü dikkatle okuyun; matematik dili ve problemin formülasyonu çok anlaşılır. Değişkenlere ve altlarındaki indislere dikkat edin.

**Soru:** Bütün noktalar bütün kümelerin merkezine etki ediyor mu? **Cevap:** Evet, bütün noktalar merkezin yeniden hesaplanmasında kullanılır. K-Means'teki sert atamada, ilk örnekte olduğu gibi, birinci kümenin üç üyesi merkezi yüzde yüz etkiliyor ve ortalama yalnız onlarla alınıyordu. EM'de ise bütün noktalar belli bir ağırlıkla etki eder; bu ağırlık noktanın o kümeye ait olma olasılığıdır. Örneğin birinci kümeye %80, ikinci kümeye %10 oranında ait olan bir nokta birinci kümeyi daha çok, ikinciyi daha az etkiler.

**Soru:** Varyans neden hesaplanıyor? **Cevap:** Normal dağılımın iki parametresi vardır: ortalama ve varyans. İkisi bilinirse normal dağılım denkleminde her $x_j$ için olabilirlik hesaplanabilir; bu yüzden her iterasyonda ikisi de yeniden hesaplanır.

**Soru:** Son hesaplama, yani küme olasılığı nasıl bulunuyor? **Cevap:** Amaç her kümenin olma olasılığını hesaplamaktır. Burada da her örneğin etkisi vardır ama bazılarının etkisi ağırlığına göre daha fazladır. $P(C_1)$ için bütün örneklerin $w_1(x_j)$ ağırlıkları toplanır ve bütün kümelerin ağırlık toplamına bölünür.

### 8.7 K-Means, EM'in Özel Bir Durumudur

Dokümandaki bir not, K-Means'in EM'den nasıl elde edildiğini gösterir (ekrandan, 02:45:00). Olabilirlik fonksiyonu şöyle değiştirilir:

$$P(x_j \mid C_i) = \begin{cases} 1 & C_i = \arg\min_a \{\delta(x_j, \mu_a)\} \\ 0 & \text{aksi hâlde} \end{cases}$$

Yani $x_j$ örneğinin her kümenin merkezine uzaklığı hesaplanır; bu uzaklığı en küçük yapan kümenin üyeliği 1, diğerlerininki 0 olur. Bu, K-Means'teki sert atamadır.

## 9. Çok Boyutlu EM ve Uygulama Alanları

### 9.1 d Boyutlu EM

Veri $d$ boyutlu olduğunda ortalama artık tek bir değer değil, $d$ boyutlu bir ortalama vektörüdür (mean vector) (ekrandan, 02:40:00):

$$\boldsymbol{\mu}_i = (\mu_i^1, \mu_i^2, \ldots, \mu_i^d)$$

Tek boyutta varyans hesaplanıyordu; $d$ boyutta ise $d \times d$ boyutlu bir kovaryans matrisi $\boldsymbol{\Sigma}_i$ hesaplanır. Kovaryans matrisinin ana köşegenindeki elemanlar varyansları, diğer elemanlar değişkenlerin birbirleriyle birlikte değişimini gösterir.

Hoca bunu iki boyutta bir çizimle açıklar. Değişken 1 ve değişken 2 eksenli düzlemde iki küme ($C_1$ ve $C_2$) vardır; her birinin bir merkezi ve bir dağılımı bulunur, kümeler belli oranda örtüşür. Çizimdeki sınırlar yalnız dağılımı temsil eder; gerçekte kümelerin kesin sınırları yoktur. Küme merkezleri artık iki boyutlu vektörlerdir. Düzlemde alınan bir nokta, $C_2$'nin merkezine daha yakınsa ona daha yüksek olasılıkla aittir, ama dağılımdan gelen orana bağlı olarak zayıf bir olasılıkla $C_1$'in de elemanıdır. Kümelerin dışında alınan bir nokta için de aynısı geçerlidir.

> **Ek bilgi (derste anlatılmadı):** $d$ boyutta olabilirlik, tek boyutlu normal dağılım yerine çok değişkenli normal dağılım yoğunluğuyla hesaplanır; bu yoğunluk ortalama vektörünü ve kovaryans matrisini birlikte kullanır. Parametre sayısı boyutla hızla arttığı için uygulamada boyutların bağımsız varsayılıp kovaryansların sıfır alındığı sadeleştirmeler de kullanılır.

### 9.2 Uygulama Alanları

Kümeleme yöntemleri görüntü işlemede kullanılabilir. Bir örnek renk kümelemesidir (color clustering): her kanalı 8 bit olan, toplam 24 bitlik (yaklaşık 16 milyon renkli) gerçek renkli (true color, RGB) bir görüntüde renk sayısı, örneğin 16 renge indirilebilir. Bu yapılırken yalnız o görüntüde bulunan renkler kümelenir; yani görüntüye özgü bir kümeleme elde edilir. Hoca, hazır görüntü düzenleme araçlarının ise genelde bütün renk uzayını belli bölgelere ayırarak (bildiği kadarıyla QT kümelemeyle) görüntüden bağımsız genel bir dönüşüm yaptığını söyler. Renk kümelemesi için K-Means'in yanında bulanık c-ortalamalar (fuzzy c-means) ve yapay sinir ağlarındaki SOM yöntemleri de kullanılabilir. K-Means öğrenildikten sonra diğer yöntemleri anlamak kolaylaşır.

**Soru:** Birden çok kümeleme yöntemi aynı anda uygulanabilir mi? **Cevap:** Aynı anda kullanılması çok anlamlı değildir; ama yöntemlerin performansları karşılaştırılıp hangisinin daha iyi çözüm ürettiğine bakılarak biri seçilebilir. Hoca aynı anda kullanılmasına dair bir örnek görmediğini söyler.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): $i = 10011011$ ve $j = 11000110$ örnekleri için verilen ikili özelliklere göre $i$ ve $j$ örneklerinin birbirlerine olan benzerliklerini basit eşleşme katsayısı ve Jaccard katsayısıyla bulun.

> **Çözüm (derste verildi, ekrandan, 00:40:00):** 0-0 eşleşme $a = 1$, 0-1 eşleşme $b = 2$, 1-0 eşleşme $c = 3$, 1-1 eşleşme $d = 2$. $\text{Sim}_{SMC} = (a + d)/(a + b + c + d) = 3/8$. $\text{Sim}_{Jaccard} = d/(b + c + d) = 2/7$. Slayttaki $2/8$ değeri hatalıdır.

**Soru 2** (ekrandan, 00:55:00): Tablodaki yedi örnekli iki boyutlu veriyi ($(1.0, 1.0)$, $(1.5, 2.0)$, $(3.0, 4.0)$, $(5.0, 7.0)$, $(3.5, 5.0)$, $(4.5, 5.0)$, $(3.5, 4.5)$) K-Means ile $K = 2$ kümeye ayırın; başlangıç merkezleri 1. ve 4. örnekler olsun.

> **Çözüm (derste verildi):** Birinci iterasyonda kümeler {1, 2, 3} ve {4, 5, 6, 7}, merkezler $(1.83, 2.33)$ ve $(4.12, 5.38)$. İkinci iterasyonda 3. örnek ikinci kümeye geçer: {1, 2} ve {3, 4, 5, 6, 7}, merkezler $(1.25, 1.5)$ ve $(3.9, 5.1)$. Üçüncü iterasyonda atama değişmez.

**Soru 3** (ekrandan, 01:30:00): Aynı veriyi $K = 3$ ile, başlangıç merkezleri 1., 2. ve 3. örnekler olacak biçimde kümeleyin.

> **Çözüm (derste verildi):** Birinci adımda 4-7. örnekler üçüncü kümeye düşer; merkezler $(1.0, 1.0)$, $(1.5, 2.0)$, $(3.9, 5.1)$. İkinci adımda atama değişmez. Kümeler {1}, {2}, {3, 4, 5, 6, 7}.

**Soru 4** (ekrandan, 01:35:00): A (1, 1), B (2, 1), C (4, 3), D (5, 4) ilaçlarını (ağırlık indeksi, pH) başlangıç merkezleri $c_1 = (1, 1)$ ve $c_2 = (2, 1)$ olacak biçimde K-Means ile iki kümeye ayırın.

> **Çözüm (derste kısmen verildi; ara adımlar python ile doğrulandı):** $D^0$ satırları $[0, 1, 3.61, 5]$ ve $[1, 0, 2.83, 4.24]$; kümeler {A} ve {B, C, D}, yeni $c_2 \approx (3.67, 2.67)$. İkinci iterasyonda B birinci kümeye geçer: {A, B} ve {C, D}, merkezler $(1.5, 1)$ ve $(4.5, 3.5)$. Üçüncü iterasyonda atama değişmez.

**Soru 5** (derste sözlü, 01:07:45): Doğruluk (accuracy) ile doğrulama doğruluğu (validation accuracy) arasında nasıl bir bağlantı var?

> **Cevap (derste verildi):** Eğitim verisi üzerinden hesaplanan bir hata oranı ve sistemin karmaşıklığını da dikkate alan genelleştirme hatası vardır. Doğrulama hatası ise doğrulama veri seti üzerinden ölçülür. Özellikle yapay sinir ağlarında veri önce eğitim ve test olarak ayrılır, sonra eğitim verisi eğitim ve doğrulama olarak ikiye bölünür. Doğrulama verisi parametre (hiperparametre) seçiminde kullanılır; bu seçimin test verisi üzerinde yapılması doğru olmaz. Parametrelere karar verildikten sonra model test verisinde denenir ve ne kadar doğru ya da hatalı sınıflama yaptığı görülür.

**Soru 6** (derste sözlü, 02:03:17): K-Means'te küme sayısı $K$ verilmeden kümeleme yapan bir yöntem var mı?

> **Cevap (derste verildi):** Evet; örneğin hiyerarşik kümeleme küme sayısı bilinmeden çalışır. K-Means'te ise uygun $K$ için farklı $K$ değerleriyle çözüm yapılır, her biri için kareler toplamı maliyeti $J$ hesaplanıp grafiği çizilir ve grafiğin dirsek yaptığı noktadaki $K$ seçilir.

## Dersin Toparlaması

Bu derste denetimsiz öğrenmeye ve kümelemeye giriş yapıldı. Önce sayısal öz nitelikler için Öklid, Manhattan ve Minkowski uzaklıkları ile bir mesafe ölçüsünün özellikleri, ikili öz nitelikler için olumsallık tablosu, basit eşleşme katsayısı ve Jaccard katsayısı görüldü. Ardından K-Means algoritması, kareler toplamı maliyeti, iteratif atama ve merkez güncelleme adımları, $K = 2$ ve $K = 3$ sayısal örnekleri ve ilaç örneğiyle işlendi. Yöntemin başlangıç merkezlerine duyarlılığı, ortak merkezli veride başarısız olması ve uygun $K$'nın dirsek yöntemiyle seçilmesi tartışıldı.

Dersin ikinci yarısında EM kümelemesi Bayes teoremi ve Gauss karışım modeli üzerinden anlatıldı: başlatma, beklenti (olabilirlik ve sonsal olasılık) ve maksimizasyon (ağırlıklı ortalama, ağırlıklı varyans, küme olasılığı) adımları, K-Means'in EM'in sert atamalı özel durumu olması ve çok boyutlu durumda ortalama vektörü ile kovaryans matrisi görüldü. Küme sayısını bilmeden çalışan hiyerarşik kümelemenin sonraki derste anlatılacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
