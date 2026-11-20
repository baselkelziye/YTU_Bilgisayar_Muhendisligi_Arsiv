# Ders 5 Genişletilmiş Notu: Harris Değişmezlikleri, DoG ile Ölçek Seçimi, SIFT ve Yerel Tanımlayıcılarla Eşleştirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Harris Köşe Bulucusu Ödevinin İncelenmesi
- 2. Harris Bulucusunun Değişmezlik ve Eşdeğişkenlik Özellikleri
- 3. Anahtar Nokta Eşleştirmeye Genel Bakış
- 4. Ölçek Seçimi ve Difference of Gaussian
- 5. DoG'nin Gauss Piramidinde Verimli Hesaplanması
- 6. Konum-Ölçek Uzayında Yerel Maksimum
- 7. Yönelim Normalizasyonu ve SIFT'in İki Yüzü
- 8. Watershed, MSER ve Bulucuların Karşılaştırması
- 9. İmge Gösterimi: Şablonlar ve Histogramlar
- 10. SIFT Tanımlayıcısı
- 11. Diğer Yerel Tanımlayıcılar
- 12. Yerel Özelliklerin Eşleştirilmesi

## 1. Harris Köşe Bulucusu Ödevinin İncelenmesi

Ders, bir önceki hafta verilen Harris köşe bulucusu ödevinin bir öğrencinin Jupyter defteri üzerinden incelenmesiyle başladı. Hoca, ödevlerin üst üste binerek bu noktaya getirdiğini söyledi: önceki ödevlerde yazılan türev ve Gauss filtresi kodları burada fonksiyon hâline getirilip yeniden kullanılmıştı.

### 1.1 Türevler ve Gauss pencere fonksiyonu

Öğrenci türevleri OpenCV'nin `filter2D` fonksiyonuyla aldı, Gauss filtresini kendisi oluşturdu ve türevleri ayrılabilir konvolüsyonla Gauss'tan geçirdi (ekrandan, 00:10:00):

```python
derIX = applySeparateConvolution(derIX, gaussianFilter1D)
derIY = applySeparateConvolution(derIY, gaussianFilter1D)
```

Defterde ikinci moment matrisi yatay ve dikey gradyanlarla şöyle tanımlanmıştı (ekrandan, 00:10:00):

$$M=\nabla I(\nabla I)^T=\begin{bmatrix}I_x\\I_y\end{bmatrix}[I_x\;I_y]$$

### 1.2 Dört boyutlu dizilerle ikinci moment matrisi

Öğrencinin kodu ekranda şöyleydi (ekrandan, 00:10:00):

```python
gradientI = np.array([[derIX, derIY]])
gradientI = np.transpose(gradientI, axes=(2,3,1,0))
gradientIT = np.transpose(gradientI, axes=(0,1,3,2))

M = np.matmul(gradientI, gradientIT).astype(np.float32)
```

Hoca önce "burada dört değere ihtiyacın yok mu?" diye sordu. Öğrenci $2\times1$ bir vektörle $1\times2$ bir vektörü çarptığı için yine $2\times2$, yani dört değerli bir matris oluştuğunu açıkladı. Hoca bunu doğrulamak için `print` ile şekilleri yazdırdı. $256\times256$ boyutlu bir imgede şekiller şöyle değişir (python ile doğrulandı):

- `np.array([[derIX, derIY]])`: $(1,2,256,256)$
- `transpose(..., axes=(2,3,1,0))`: $(256,256,2,1)$, yani her piksel için bir sütun vektörü
- `transpose(..., axes=(0,1,3,2))`: $(256,256,1,2)$, yani her piksel için bir satır vektörü
- `np.matmul`: $(256,256,2,2)$, yani her piksel için bir $2\times2$ ikinci moment matrisi

`np.matmul` çok boyutlu dizilerde son iki ekseni matris olarak çarpar, öndeki eksenleri "yığın" sayar. `transpose` ise eksenleri yeniden sıralar: verilen demette $i$. konumdaki sayı, yeni dizinin $i$. ekseninin eski dizideki hangi eksen olduğunu söyler. Örneğin `(2,3,1,0)` ile eskiden 2. indekste olan eksen yeni dizinin 0. ekseni olur. Hoca dört boyutlu diziler söz konusu olunca hangi eksenin hangisi olduğunu zihinde canlandırmanın zor olduğunu, kendisi olsa $I_x^2$, $I_xI_y$ ve $I_y^2$ için dört ayrı imge tutup her pikselde çarpma ve toplama yapacağını söyledi. Sonuçta elde $256\times256$ tane ikinci moment matrisi olur.

### 1.3 Özdeğerler

Özdeğerler `np.linalg.eigvals` ile hesaplanmıştı (ekrandan, 00:10:00):

```python
eigM = np.linalg.eigvals(M)
eigMax = np.max(eigM, axis=-1)
eigMin = np.min(eigM, axis=-1)
```

Defterde $\lambda_{max}$'ın en hızlı değişimin yönüne, $\lambda_{min}$'in en yavaş değişimin yönüne karşılık geldiği not edilmişti (ekrandan, 00:10:00). Öğrenci her iki özdeğeri imge olarak gösterdi. Hoca, $\lambda_{max}$'ın büyük olduğu yerlerin kenarlara denk geldiğini belirtti.

> **Ek bilgi (derste anlatılmadı):** Önceki dersin sınıflamasına göre yalnız bir özdeğerin büyük olduğu yerler kenar, ikisinin de büyük olduğu yerler köşe, ikisinin de küçük olduğu yerler düz bölgedir. Bu yüzden $\lambda_{max}$ imgesi kenarları ve köşeleri birlikte gösterir; köşeyi ayırmak için $\lambda_{min}$'e ya da köşe cevabına bakmak gerekir.

### 1.4 Değişim elipslerinin çizimi

Öğrencinin elips kodu şöyleydi (ekrandan, 00:15:00):

```python
from matplotlib.patches import Ellipse

# showing ellipses in windows not to overlap too many ellipses
window = 7

# direction of fastest change
ellipse_height = eigMax**(1/2)

# direction of slowest change
ellipse_width = (np.abs(eigMin))**(1/2)

ellipses = [Ellipse((_j*window + window//2, _i*window + window//2), # place
                    np.sum(ellipse_width[i*window:(i+1)*window, j*window:(j+1)*window]) / window**2,  # width
                    np.sum(ellipse_height[i*window:(i+1)*window, j*window:(j+1)*window]) / window**2, # height
                    np.sum(IMAGE[i*window:(i+1)*window, j*window:(j+1)*window]) / window**2, # angle
                    edgecolor="yellow", fill=False)
            for _i,i in enumerate(range(0, WIDTH//window))
            for _j,j in enumerate(range(0, HEIGHT//window))]
```

Her piksele bir elips çizilince resim karıştığı için öğrenci imgeyi $7\times7$ pencerelere bölmüş, her penceredeki 49 özdeğerin ortalamasıyla tek bir elips çizmişti. Hoca bunun yalnız gösterim amaçlı olduğunu, Harris bulucusunun kendisinin piksel tabanlı çalıştığını vurguladı.

Hoca slayttaki formülü açtı (ekrandan, 00:20:00). İkinci moment matrisinin köşegenleştirilmesi

$$M=R^{-1}\begin{bmatrix}\lambda_1&0\\0&\lambda_2\end{bmatrix}R$$

biçimindedir. Elipsin eksen uzunluklarını özdeğerler, yönünü $R$ belirler. En hızlı değişim yönündeki yarı eksen $(\lambda_{max})^{-1/2}$, en yavaş değişim yönündeki yarı eksen $(\lambda_{min})^{-1/2}$ uzunluğundadır.

**Soru:** Üs $-1/2$ değil miydi? **Cevap:** Öğrenci $-1/2$ ile denediğinde garip sonuçlar aldığını, $+1/2$ ile sonucun daha anlamlı göründüğünü söyledi. Hoca, ekrandaki bazı elipslerin olması gerekene göre 90 derece dönük göründüğünü, maksimum renk değişiminin elipsin öbür ekseninde olduğunu belirtti ve eksiyi koymak gerektiğini söyledi.

Mantık şudur: özdeğer o yöndeki değişim miktarını verir. Elipsin uzun tarafında değişim azdır. $\lambda$ büyüdükçe $1/\sqrt{\lambda}$ küçülür, böylece büyük özdeğerin yönündeki eksen kısa olur.

**Soru:** Elipsin yönü özdeğerlerden mi, özvektörlerden mi tanımlanır? **Cevap:** Özvektörlerden. Özvektörler elipsin eksenlerinin yönünü, özdeğerler o yöndeki eksenin boyunu verir. Hoca, verilen eksen vektörleriyle elips çizmenin ayrıntısını kendisinin de tam bilmediğini, internetten araştırılabileceğini söyledi ve kullanılan kütüphanenin özvektörleri hangi düzende (satır mı sütun mu) verdiğine dikkat edilmesi gerektiğini ekledi.

`Ellipse` fonksiyonuna konum $(x,y)$, genişlik, yükseklik ve açı verilir. İncelenen başka bir çözümde açı, penceredeki imge parlaklığının ortalamasından verilmişti. Hoca bunun yaklaşık bir sonuç verse de doğru olmadığını, açının özvektörlerden (ör. bir tanjant ilişkisiyle) hesaplanması gerektiğini söyledi. Derste elipsi özvektörlerle doğru çizen bir çözüm çıkmadı.

> **Ek bilgi (derste anlatılmadı):** $\lambda_{min}$'e karşılık gelen özvektör $(v_x,v_y)$ ise elipsin uzun ekseninin açısı $\theta=\operatorname{atan2}(v_y,v_x)$ ile bulunur; `Ellipse` bu açıyı derece cinsinden bekler. Genişlik ve yükseklik yarı eksen değil tam eksen uzunluğu olduğu için yarı eksenlerin iki katı verilir.

### 1.5 Köşe cevabı ve maksimum olmayanı bastırma

Öğrenci köşe cevap fonksiyonu için determinant ve izi (trace) hesapladı, belirli bir eşiğin altındaki değerleri sıfırladı ve ardından maksimum olmayanı bastırma (non-maximum suppression) uyguladı. Sonuçta kameramanlı test imgesi üzerinde köşeler işaretlendi (ekrandan, 00:25:00). Son olarak bütün adımlar tek bir fonksiyonda toplanıp imgenin afin dönüşümleriyle bulucunun davranışı incelenmişti. <!-- BELİRSİZ: köşe cevabındaki sabit altyazıda "Alfayı 0.4 aldım" (00:24:08) diye geçiyor; Harris'te bu sabit genelde 0.04-0.06 aralığındadır, değer büyük olasılıkla 0.04'tür. Kodun bu kısmı karede görünmüyor. -->

## 2. Harris Bulucusunun Değişmezlik ve Eşdeğişkenlik Özellikleri

Hoca, ödev incelemesinden sonra geçen haftanın Harris konusunu tamamladı. İyi bir bulucu, resimdeki küçük değişikliklerden etkilenmemeli (değişmezlik, invariance) ya da mantıklı bir biçimde birlikte değişmelidir (eşdeğişkenlik, covariance).

### 2.1 Parlaklık değişimleri

Yalnız türevler kullanıldığı için parlaklık kayması $I\to I+b$ türevleri değiştirmez; bulucu buna değişmezdir. Parlaklık ölçeklemesi $I\to aI$ ise köşe cevabının büyüklüğünü değiştirir. Slayttaki grafikte aynı eşik altında, ölçekleme sonrası önceden eşiğin altında kalan bir tepe eşiği aşıp yeni nokta olarak bulunur (ekrandan, 00:35:00). Bu yüzden Harris afin parlaklık değişimine **kısmen değişmezdir**. Hoca bunu "noktalar parlaklığa biraz bağlı ama bulunan noktalar çok değişmiyor" diye özetledi.

### 2.2 Öteleme ve dönme

Türev kayma değişmezdir: imgedeki nesne yer değiştirince türevlerin verdiği cevap değişmez. Pencere fonksiyonu olan Gauss da kayma değişmezdir. Dolayısıyla nesne başka bir yere taşınsa da aynı noktalar bulunur.

Nesne döndürüldüğünde özdeğerler aynı kalır, yalnız elipsin kendisi döner. Köşe konumu dönmeyle birlikte değişir; slayt bunu "eşdeğişken" diye adlandırır.

### 2.3 Ölçekleme

Küçük bir yapı uzaktan bakıldığında köşe olarak algılanır. Aynı yapı yakından (zoom yapılarak) çekildiğinde pencere içinde yalnız eğrinin bir parçası görünür ve yapı köşe değil kenar olarak sınıflanır. Bu yüzden Harris ölçeklemeye eşdeğişken değildir. Hoca ölçeği şöyle tanımladı: büyük ölçekte sahneye uzaktan, küçük ölçekte yakından bakıyorsunuz. Harris'in temel sorunu, bize ölçek bilgisini vermemesi ve farklı ölçeklerde çalışmamasıdır. Harris'i temel alan ama ölçekten bağımsız çalışan geliştirilmiş bulucular vardır. Hoca bu konu için Szeliski'nin ilgili bölümünün okunabileceğini söyledi.

## 3. Anahtar Nokta Eşleştirmeye Genel Bakış

Yeni slayt setinde önce önceki dersin özeti yer aldı (ekrandan, 00:40:00): Harris ayırt ediciliği yerel öz-ilinti (auto-correlation) ile, öz-ilintiyi ikinci moment matrisiyle yaklaşık olarak ölçer; köşeliği ikinci moment matrisinin özdeğerlerinin bir fonksiyonu olarak sayısallaştırır; ama özdeğerleri hesaplamaya gerek yoktur, determinant ve iz yeterlidir.

Anahtar nokta eşleştirme beş adımdan oluşur (ekrandan, 00:40:00):

1. Ayırt edici anahtar noktalar kümesini bul.
2. Her anahtar noktanın çevresinde bir bölge tanımla.
3. Bölge içeriğini çıkar ve normalize et.
4. Normalize bölgeden yerel bir tanımlayıcı (descriptor) hesapla.
5. Yerel tanımlayıcıları eşleştir: iki bölgenin tanımlayıcıları $f_A$ ve $f_B$ için $d(f_A,f_B)<T$ ise eşleşme kabul edilir.

Hoca, şimdiye kadar noktayı $x,y$'de yerelleştirebildiğimizi ama ölçekte yerelleştiremediğimizi söyledi. Ölçekte yerelleştirmek, doğru bölgenin ne büyüklükte olduğunu belirlemek demektir. Aynı sahnenin biri yakından (büyük ölçekli), biri uzaktan çekilmiş iki imgesinde sadece karşılık gelen noktayı değil, karşılık gelen bölgeyi bulmak isteriz.

## 4. Ölçek Seçimi ve Difference of Gaussian

### 4.1 İmza fonksiyonu fikri

Aranan şey öyle bir fonksiyondur ki imgeyi verdiğimizde şu pikseldeki şu büyüklükteki bölge ile öbür imgedeki karşılık gelen bölge için aynı değeri versin. Bölge bir pencere fonksiyonuyla tanımlanabilir. Fonksiyon her imgenin farklı ölçeklerinde hesaplanır; istenen özellik, iki imgede de maksimumun karşılık gelen ölçekte, yani karşılık gelen bölgelere denk düşen komşuluk büyüklüğünde ortaya çıkmasıdır.

### 4.2 DoG: blob bulucu

Böyle bir fonksiyon Gauss'ların farkı (Difference of Gaussian, DoG) olabilir (ekrandan, 00:45:00). İki Gauss birbirinden çıkarıldığında "Meksika şapkası" biçiminde bir filtre oluşur. Bu filtre köşelere değil lekelere (blob) cevap verir; hoca "blob" kelimesinin Türkçe karşılığını sordu. Slayttaki çizimde küçük bir DoG küçük daireye, büyük bir DoG büyük daireye en güçlü cevabı verir; her daire için cevap ölçeğe göre çizildiğinde tepe farklı ölçekte oluşur (ekrandan, 00:45:00).

Hesaplama şöyledir: imge bir Gauss'tan, ayrıca daha büyük ölçekli ikinci bir Gauss'tan geçirilir ve ikisinin farkı alınır. Ölçeğe şimdilik Gauss filtresinin varyansı olarak bakılabilir; "büyük ölçekli imge", büyük varyanslı Gauss filtresinden geçmiş imge demektir. Oluşan filtre önceki ödevlerdeki gibi üç boyutlu çizilirse Gauss'a benzer ama kenarlarda sıfırın altına iner.

## 5. DoG'nin Gauss Piramidinde Verimli Hesaplanması

Hoca DoG'nin hızlı hesaplanma yolunu slayt üzerinde çizerek anlattı (ekrandan, 00:50:00 ve 00:55:00).

### 5.1 Bir oktav içinde katmanlar

Orijinal imgeden başlanır. İmge bir Gauss filtresinden geçirilir, elde edilen imge tekrar Gauss'tan geçirilir, bu birkaç kez tekrarlanır. Her filtrelemede oluşan imgenin ölçeği, yani eşdeğer Gauss'un varyansı artar. Örneğin orijinal imge ve dört filtrelemeyle beş katman elde edilir. Ardışık katmanlar birbirinden çıkarılarak dört DoG katmanı bulunur. Her katmanın varyansı bilindiği için her DoG'nin hangi ölçeğe karşılık geldiği de bilinir. Slaytta ölçek her adımda $\sigma$ çarpanıyla artar ve $\sigma=2^{1/4}$'tür (ekrandan, 00:50:00).

### 5.2 Örnekleme ve oktavlar

Gauss ile filtreledikçe imge gittikçe bulanıklaşır. Bulanık bir imgede tüm piksel sayısıyla çalışmak gereksizdir. Bu yüzden satırların biri alınıp biri atılır, sütunların da biri alınıp biri atılır; boyutlar yarıya düşer. Slaytta bu "adım $\sigma^4=2$ ile örnekleme" olarak yazılıdır (ekrandan, 00:50:00). Dört adımda ölçek $(2^{1/4})^4=2$ katına çıktığı için imgeyi iki kat seyreltmek bilgi kaybettirmez (python ile doğrulandı: $(2^{1/4})^4=2$). Küçülen imgede aynı işlem tekrarlanır: yine beş katman, dört DoG, sonra yine yarıya indirme.

Her yarıya indirmeden sonra elde edilen, aynı büyüklükteki imgelerin topluluğuna **oktav** denir. İmgenin büyüklüğüne göre 4, 5, 6 oktav gidilebilir. Hoca bunu, gittikçe küçülen imgeler ürettiği için dalgacık (wavelet) dönüşümüne benzetti. Sonuçta DoG bölge bulucusuna aynı imgenin farklı varyanslardaki, yani farklı ölçeklerdeki sürümleri verilmiş olur.

## 6. Konum-Ölçek Uzayında Yerel Maksimum

Sonraki adım DoG cevabının maksimum olduğu yerleri bulmaktır (ekrandan, 01:00:00). Maksimum yalnız $x,y$ konumunda değil ölçekte de aranır; sonuç bir $(x,y,s)$ listesidir. Slaytta bir konum, aynı katmandaki komşularıyla ve alt ve üst ölçek katmanlarındaki komşularıyla karşılaştırılır. Slayt bu fonksiyonu $L_{xx}(\sigma)+L_{yy}(\sigma)$ olarak ve $\sigma,\sigma^2,\dots,\sigma^5$ ölçeklerinde gösterir (ekrandan, 01:00:00).

Bulunan konumlar piksel olmak zorunda değildir; 3.8 gibi piksellerden daha ayrıntılı değerler çıkabilir. Bunun nedeni şudur: küçük bir oktavda bir piksel orijinal imgede daha büyük bir alanı kaplar. Örneğin bir kenarda 100 piksel varken bir sonraki oktavda 50 piksel kalır; bir pikselin kapladığı alan iki kere ikiden dört katına çıkar. Bu yüzden $x,y$'lere piksel değil konum olarak bakmak gerekir.

Ölçekte de benzer biçimde davranılır. Fonksiyon ölçek arttıkça önce artar, bir yerden sonra azalmaya başlar. Maksimumun iki katman arasında nerede olduğu enterpolasyonla tahmin edilir. Hoca bunun David Lowe'un makalesinde anlatıldığını söyledi.

### 6.1 Ölçek: standart sapma mı, varyans mı?

Normalde ölçek $\sigma$, yani standart sapmayla ifade edilir; $\sigma^2$ varyanstır. Bazı yazarlar doğrudan varyans üzerinden düşünür ve varyansa $t$ der. Hoca, okunan makalenin hangi gösterimi kullandığını anlamak gerektiğini vurguladı.

> **Ders sonrası not:** Hoca Lowe'un ölçeği varyansla ($t$) ifade ettiğini sandığını söyledi. Lowe'un SIFT makalesi büyük olasılıkla ölçeği $\sigma$ ile verir; $t=\sigma^2$ gösterimi büyük olasılıkla Lindeberg'in ölçek uzayı çalışmalarında yaygındır.

## 7. Yönelim Normalizasyonu ve SIFT'in İki Yüzü

### 7.1 Yönelim histogramı

Bir bölge bulunduğunu varsayalım. Bu nokta Harris ile bulunup çevresinde bölge aranabilir, ya da Harris hiç kullanılmadan doğrudan DoG'nin maksimum olduğu yerler alınabilir; iki olasılık da vardır. Lowe ayrıca bölgenin yönelimini standartlaştırmayı, yani normalize etmeyi önerir (ekrandan, 01:05:00):

- Yönelim histogramını hesapla.
- Baskın yönelimi seç.
- Normalize et: bölgeyi sabit bir yönelime döndür.

Gradyanlar yön verir: $x$ ve $y$ yönünde türev alındığı için ikisi birlikte bir yön tanımlar. Hoca derste açıları sekize bölerek anlattı: her gradyan sekiz yönden birine sayılır, bir histogram çıkar ve en çok gradyanın düştüğü yön bölgenin yönelimi kabul edilir. Slaytta histogram $0$ ile $2\pi$ arasındadır ve tepe ok ile işaretlidir (ekrandan, 01:05:00).

> **Ders sonrası not:** Hoca yönelim histogramını 8 kutulu anlattı. Lowe'un 2004 makalesinde yönelim ataması için büyük olasılıkla 36 kutulu (10 derecelik) histogram kullanılır; 8 kutu tanımlayıcı aşamasındaki hücre histogramlarına aittir (Bölüm 10).

### 7.2 SIFT: bulucu mu, tanımlayıcı mı?

David Lowe'un geliştirdiği SIFT hem bir nokta (bölge) bulucusu hem de o noktadan özellik çıkaran bir tanımlayıcı içerir. İkisine birden SIFT denilip öyle yayımlandığı için SIFT'in bölge bulucu mu, özellik çıkarıcı mı olduğu karışır. Makaledeki bölge bulucu DoG temellidir; bu yüzden bu şekilde bulunan bölgelere DoG bölgeleri de denir. Aynı makalede bir de özellik çıkarma yöntemi verilir. Hoca bunun çok önemli, çığır açıcı (seminal) bir makale olduğunu söyledi.

## 8. Watershed, MSER ve Bulucuların Karşılaştırması

### 8.1 Watershed

Watershed bir bölütleme algoritmasıdır. İmgenin parlaklığı, Gauss'u üç boyutlu çizdirdiğimiz gibi çizilirse ($x$, $y$ ve parlaklık eksenleriyle) imge üç boyutlu bir yüzey gibi görünür. Bu yüzeye su döküldüğünü düşünün: su önce derin vadilere dolar. Sulu ve susuz bölgeler ayrılınca imge farklı bölgelere bölünmüş olur. Bir bakıma aynı renkteki bölgeleri birleştiren bir algoritmadır.

### 8.2 MSER

Matas'ın algoritması (MSER) watershed'e dayanır. Su seviyesi uzunca bir süre artırılmasına rağmen değişmeden kalan bölgeleri bulur: bir bölgeye biraz su dökülür, biraz daha, biraz daha, ama bölge hep oradadır. Bu kararlı (stable) bölgeler seçilir. MSER bölgeleri elips olmak zorunda değildir; parlaklığa dayalı bir bölütleme gibi serbest biçimli bölgeler verir. Hoca, DoG'nin ise her zaman daire verdiğini söyledi.

### 8.3 Karşılaştırma

Slaytta dört bulucunun aynı imge üzerindeki çıktısı karşılaştırılır (ekrandan, 01:10:00): Harris noktaları, Hessian noktaları, LoG (Laplacian of Gaussian) daireleri ve MSER bölgeleri. Her biri farklı bölgeler verir. Slaytta bu bulucuların çoğunu çalıştıran programların bulunduğu bir adres de verilmişti. Hoca, derin öğrenme çıkmadan önce imgelerde şekil tanıma ile ilgili en önemli yaklaşımın bu olduğunu söyledi.

## 9. İmge Gösterimi: Şablonlar ve Histogramlar

Hoca üç aşamayı ayırdı: bölgeleri bulmak, bölgeden bilgi çıkarmak ve çıkarılan bilgileri birbiriyle eşleştirmek. Şimdi ikinci aşamaya geçildi.

### 9.1 Şablonlar

İmgeyi temsil etmenin bir yolu şablondur (template): imgenin kendisi, yani orijinal parlaklık değerleri ya da hesaplanan türevler doğrudan kullanılır. İkinci yol histogram temelli gösterimlerdir; dokular ve SIFT tanımlayıcıları bu türdendir.

### 9.2 Histogram

Histogram, belirli bir fonksiyon değerinin bölgede kaç kez görüldüğünü veren listedir. Slayttaki martı imgesinin global histogramında koyu renkler, özellikle 50 civarındaki değerler çok fazladır; tepe yaklaşık 5000-5500 adettir, beyazların sayısı ise nispeten azdır (ekrandan, 01:15:00). Bu tüm resimden çıkarılmış global bir histogramdır ve nesne bulmak için iyi bir fikir değildir. Ama histogram yerel alınırsa, örneğin yalnız gagadan ya da yalnız gözden, birden faydalı hâle gelir.

Histogram bir olasılık dağılımı olarak da görülebilir. Yalnız sayıldığında histogram denir; değerler toplamı 1 olacak biçimde eleman sayısına bölünürse olasılık dağılımına dönüşür. Slaytta ayrıca marjinal ve ortak (joint) histogramlar geçer: marjinal histogramda yalnız satırlar ya da yalnız sütunlar boyunca, ortak histogramda ızgara hücreleri hâlinde sayılır. Histogram alındıktan sonra sınıflama için de kullanılabilir.

### 9.3 Neyin histogramı?

Renklerin, dokuların ve gradyan yönelimlerinin histogramı alınabilir. Doku çıkarmak için filtre dizileri (filter banks), Gabor filtreleri ve başka yöntemler vardır. <!-- BELİRSİZ: altyazıda "Hop diye çeşitli tekstur çıkartma yöntemleri var" (01:16:29) geçiyor; büyük olasılıkla HOG kastediliyor. --> Bunların hepsi her piksel için bir değer veren birer fonksiyondur; imge bölgelere ayrılıp fonksiyonun her bölgedeki histogramı çıkarılabilir.

## 10. SIFT Tanımlayıcısı

### 10.1 Yönelimli gradyan histogramları

SIFT gradyan yönelimlerinin histogramını özel bir biçimde çıkarır (ekrandan, 01:20:00; slayt kaynağı "SIFT – Lowe IJCV 2004"). Önce orijinal imgede gradyanlar bulunur; her gradyanın yönü ve büyüklüğü farklıdır. İlgilenilen nokta için bir pencere fonksiyonu, yani Gauss uygulanır. Sonra bölge hücrelere bölünür. Slaytta gösterim kolaylığı için $2\times2$ hücre çizilmiştir, ama normalde bölge $4\times4=16$ hücreye bölünür. Her hücrede gradyanlar sekiz yöne gruplanır, yani 45 derecelik dilimler; kuzey, güney, doğu, batı, kuzeydoğu, güneydoğu gibi düşünülebilir. Her hücreden 8 değer gelir.

Hoca sınıfa sordu: 128'i 16'ya bölerseniz kaç çıkar? Cevap 8'dir. Buradan $16\times8=128$ elde edilir: bölge 16 hücreye bölünür, her hücreden 8 değer gelir ve toplam 128 değerlik bir tanımlayıcı oluşur. Slayttaki gibi 4 hücre olsaydı $4\times8=32$ değer olurdu.

Bu şekilde bölgeyi tanımlayan bir dizi çıkarılmış olur. Makine öğrenmesinde buna özellik çıkarma (feature extraction) denir.

### 10.2 Neden histogram?

Gauss ile çarpıldığı için merkeze yakın değerler daha önemli olur, uzaktakiler söndürülür. Bu mantıklıdır: özellik çıkardığımız pikselin yakınındaki pikseller daha önemli olmalıdır.

Tanımlayıcı uzamsal (spatial, $xy$ uzayındaki) yerleşime duyarlı olmalı ama aşırı duyarlı olmamalıdır. Aynı cisim farklı fotoğraf makineleriyle, farklı uzaklıklardan, farklı aydınlatmalarla çekildiğinde nesneler hemen hemen aynı yerde olur ama tam aynı piksele düşmez; yandaki ya da hemen üstteki piksele kayabilir. Doğrudan değerler yerine hücre histogramları kullanılınca bu bir piksellik ayrıntı atılır. Böylece tanımlayıcı yerel bilgiyi korurken fazla hassas olmaz.

### 10.3 Pürüzsüzlük: Gauss ağırlığı ve enterpolasyon

Slayt "pürüzsüzlüğü sağla" başlığı altında iki madde verir (ekrandan, 01:25:00): Gauss ağırlığı ve enterpolasyon. Enterpolasyonda verilen bir gradyan 8 kutuya katkıda bulunur: uzayda 4 çarpı yönelimde 2. Hoca bu ayrıntıyı bilmediğini, merak edenlerin makaleye bakması gerektiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu, üç doğrusal (trilinear) enterpolasyondur. Bir gradyan, hücre sınırına yakınsa en yakın $2\times2=4$ uzamsal hücreye, yönü iki yön kutusunun arasındaysa bu iki yön kutusuna, uzaklığıyla orantılı ağırlıklarla dağıtılır; $4\times2=8$ kutu böyle çıkar. Böylece gradyan bir kutudan ötekine geçerken tanımlayıcı sıçrama yapmaz.

### 10.4 Normalizasyon ve kırpma

128 değer normalize edilir. Ardından gradyan büyüklükleri bir eşikten geçirilir: yüksek gradyanların aşırı etkisini önlemek için 0.2'den büyük değerler 0.2'ye indirilir (clamp). Sonra vektör yeniden normalize edilir. Bütün bu adımların sonunda anahtar nokta tanımlayıcısı (keypoint descriptor) denen 128 değer elde edilir. Bu değerler bölgeyi tarif eder ve özellikle bölgeleri birbiriyle eşleştirmek için kullanılır.

> **Ders sonrası not:** Hoca normalizasyonu "toplamı 1 olacak şekilde" diye anlattı. Lowe'un makalesinde vektör büyük olasılıkla birim uzunluğa (L2 normu 1 olacak biçimde) normalize edilir; 0.2 kırpma da bu birim vektörün bileşenlerine uygulanır.

## 11. Diğer Yerel Tanımlayıcılar

### 11.1 SURF

SURF, SIFT fikrinin hızlı bir yaklaşığı olarak geliştirilmiştir (ekrandan, 01:30:00). İki boyutlu kutu filtreleri ve integral imgelerle verimli hesaplanır; SIFT'ten 6 kat hızlıdır ve nesne tanımada eşdeğer kalite verir. Slaytta GPU gerçeklemesiyle $640\times480$ imgede bulucu ve tanımlayıcının birlikte 200 Hz hızında çalıştığı yazılıdır. Hoca ayrıntıya girmedi; bu derste yön gösterdiğini, öğrencilerin gidip araştırabilmesi gerektiğini söyledi.

### 11.2 Shape Context

Shape Context de kutulara ayırır ama farklı biçimde: 360 dereceyi 30 derecelik açılara böler (SIFT 45 derecelik dilimler kullanır) ve merkezden uzaklaştıkça yarıçapı gittikçe artan halkalar tanımlar. Örneğin önce Harris noktaları bulunur, sonra her kutuya düşen noktaların sayısı hesaplanır; bir kutuda 4, başka bir kutuda 10 nokta olabilir. Buna log-polar kutulama (log-polar binning) denir: açılara bölündüğü için polar, mesafe her halkada iki katına çıktığı için, yani yarıçap logaritmik arttığı için log. Böylece yakın noktalarda daha fazla kesinlik, uzak noktalarda daha fazla esneklik sağlanır. Histogram çizilirken bir eksende açı, öbür eksende yarıçapın logaritması kullanılır.

### 11.3 Öz-benzerlik tanımlayıcısı

Shechtman ve Irani'nin 2007 makalesindeki tanımlayıcı şu gözleme dayanır (ekrandan, 01:35:00): aynı nesnenin (bir kalp) imgeleri ortak renk, doku ya da kenar paylaşmaz ama yerel iç öz-benzerliklerin benzer geometrik yerleşimini paylaşır. Örneğin kumdaki bir kalp, kahve köpüğündeki bir kalp, duvardaki bir kalp ve şekillerden oluşmuş bir kalp. İmge bölgesi kendine benzer: şu kısım şuraya, bu kısım buraya benzer. Yöntem küçük bir kare yama (patch) alır, yamanın çevresiyle korelasyonundan bir korelasyon yüzeyi elde eder ve bu yüzeye log-polar tanımlayıcıyı uygular. Hoca bu makaleyi ayrıntılı bilmediğini ama fikri ilginç bulduğunu söyledi.

### 11.4 Başka tanımlayıcılar ve ideal tanımlayıcı

Slaytta Winder ve Brown'ın 2007 çalışması ve SIFT'ten türetilen başka tanımlayıcılar da geçti. <!-- BELİRSİZ: altyazıda "Glove'tan bahsediyor" (01:38:38) geçiyor; büyük olasılıkla GLOH (Gradient Location and Orientation Histogram) kastediliyor, kare yok. --> Çıkarılacak ders şudur: birçok farklı tanımlayıcı vardır ve hepsinin amacı küçük bir yamayı tanımlayan, sonra eşleştirme ve sınıflandırmada kullanılabilecek değerler çıkarmaktır.

Slayttaki özet (ekrandan, 01:40:00):

- Çoğu özellik şablon, histogram (sayımlar) ya da ikisinin karışımı olarak düşünülebilir.
- İdeal tanımlayıcı sağlam (robust: küçük yerleşim farklarından etkilenmez), ayırt edici (distinctive), kompakt (aşırı sayıda değer vermez) ve verimli (efficient) olmalıdır.
- Mevcut tanımlayıcıların çoğu kenar/gradyan bilgisine odaklanır ve doku bilgisini yakalar.
- Renk nadiren kullanılır.

Hoca rengin neden nadiren kullanıldığını kendi kamera görüntüsü üzerinden açıkladı: kameraya ve ışığa göre ekranda görünen renk doğal renkten farklı olabilir, renk çok yanıltıcıdır. Bu yüzden tanımlayıcılar daha çok renklerin değişimine, yani gradyana dayanır.

## 12. Yerel Özelliklerin Eşleştirilmesi

Noktaların bulunması ve tarif edilmesi tamamlandıktan sonra üçüncü aşama eşleştirmedir (matching). İki imgede bölgeler ve bu bölgelerden çıkarılmış tanımlayıcılar vardır; hangi bölgenin hangisine eş olduğu belirlenmelidir.

### 12.1 En yakın komşu

İlk yol en yakın komşudur: tanımlayıcılar arasındaki Öklid uzaklığına göre en yakın olan seçilir (ekrandan, 01:45:00). Örneğin iki tanımlayıcının 128 değeri birbirinden çıkarılarak uzaklık hesaplanabilir. Sorun şudur: birçok fotoğrafta kendine benzerlik vardır, yani tekrarlayan benzer yapılar bulunur. Slayttaki örnekte bir bölgenin üç aday bölgeye uzaklıkları birbirine çok yakındı. <!-- BELİRSİZ: altyazıda uzaklıklar 0.34, 0.30, 0.40 ve 0.61 olarak geçiyor (01:43:20); bu slayt karede yok, değerler doğrulanamadı. --> Böyle bir durumda hangisine eşleştirileceği belirsizdir.

### 12.2 En yakın komşu uzaklık oranı

İkinci yol en yakın komşu uzaklık oranıdır (nearest neighbor distance ratio): en yakın uzaklık, ikinci en yakın uzaklığa bölünür. Eşleşmeler bu orana göre sıralanırsa belirli bir güvene göre sıralanmış olur. Slayttaki Lowe (IJCV 2004) grafiği bu oranın (en yakın / bir sonraki en yakın) doğru ve yanlış eşleşmeler için olasılık yoğunluklarını gösterir (ekrandan, 01:45:00). Doğru eşleşmelerin yoğunluğu yaklaşık 0.45'te 0.3 civarında tepe yapar; yanlış eşleşmelerin yoğunluğu 0.75'e kadar çok düşükken 0.85'te yaklaşık 0.16'ya, 0.95'te yaklaşık 0.74'e çıkar. Hoca oran 1'e yaklaştıkça yanlış eşleşmelerin arttığını, 0.4-0.5 arasında yanlış eşleşmelerin az, doğru eşleşmelerin yüksek olduğunu okudu. Lowe, doğrudan Öklid uzaklığı yerine en yakın ile ikinci en yakın uzaklığın oranını kullanan ölçümün daha iyi sonuç verdiğini göstermiştir.

> **Ek bilgi (derste anlatılmadı):** Lowe'un makalesinde pratik kural olarak oranı 0.8'den büyük olan eşleşmeler büyük olasılıkla reddedilir. Grafikte de 0.8 civarı, yanlış eşleşme yoğunluğunun doğru eşleşme yoğunluğunu geçtiği noktadır.

Ders bu noktada kaldı; kalan birkaç slayt bir sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00; derste sözlü, 00:09:44)
$256\times256$ bir imgenin türevleri `derIX` ve `derIY` için aşağıdaki kodda her satırdan sonra dizinin şekli nedir ve `M` neyi temsil eder?

```python
gradientI = np.array([[derIX, derIY]])
gradientI = np.transpose(gradientI, axes=(2,3,1,0))
gradientIT = np.transpose(gradientI, axes=(0,1,3,2))
M = np.matmul(gradientI, gradientIT)
```

> **Çözüm:** Derste şekiller `print` ile gösterildi. `gradientI` ilk satırda $(1,2,256,256)$, ilk `transpose` sonrası $(256,256,2,1)$; `gradientIT` $(256,256,1,2)$; `M` $(256,256,2,2)$ olur. `M`, her piksel için $\nabla I(\nabla I)^T$ ikinci moment matrisidir (Gauss ile yumuşatılmış türevlerden). Şekiller python ile doğrulandı.

**Soru 2** (ekrandan, 00:15:00 ve 00:20:00; derste sözlü, 00:14:55)
Değişim elipsi çizilirken kod `ellipse_height = eigMax**(1/2)` ve `ellipse_width = (np.abs(eigMin))**(1/2)` kullanıyor. Bu doğru mudur? Elipsin yönü neyle belirlenmelidir?

> **Çözüm:** Derste verildi: doğru değildir. Slayta göre en hızlı değişim yönündeki yarı eksen $(\lambda_{max})^{-1/2}$, en yavaş değişim yönündeki $(\lambda_{min})^{-1/2}$'dir; üs $-1/2$ olmalıdır. $+1/2$ ile elipsler 90 derece ters görünür. Yön $R$'den, yani özvektörlerden gelir; açıyı imge parlaklığından vermek yanlıştır.

**Soru 3** (ekrandan, 00:35:00)
Harris bulucusu $I\to I+b$ ve $I\to aI$ parlaklık değişimlerine karşı nasıl davranır?

> **Çözüm:** Derste verildi: yalnız türev kullanıldığı için $I\to I+b$ kaymasına değişmezdir. $I\to aI$ ölçeklemesinde cevap $R$ büyür; sabit eşikle önceden eşiğin altında kalan tepeler nokta olarak bulunabilir. Bu yüzden afin parlaklık değişimine kısmen değişmezdir.

**Soru 4** (ekrandan, 00:50:00)
Gauss ölçek piramidinde bir oktav içinde ölçek her adımda $\sigma=2^{1/4}$ çarpanıyla artıyor ve örnekleme adımı $\sigma^4=2$ olarak veriliyor. İmge neden dört adım sonra yarıya indirilir?

> **Çözüm (derste verilmedi):** Dört adım sonra ölçek $(2^{1/4})^4=2$ katına çıkar (python ile doğrulandı). Ölçek iki katına çıktığında imge iki kat daha bulanıktır; satır ve sütunların birini alıp birini atmak (boyutu yarıya indirmek) bilgi kaybettirmeden hesap yükünü azaltır. Derste hoca yarıya indirmenin nedenini "imge bulanıklaştıkça tüm pikselleri tutmak gereksiz" diye açıkladı.

**Soru 5** (derste sözlü, 01:17:55; ekrandan, 01:20:00)
SIFT tanımlayıcısı 128 boyutludur. Bölge 16 hücreye bölünüyorsa her hücreden kaç değer gelir, bu değerler neyi temsil eder?

> **Çözüm:** Derste verildi: $128/16=8$. Bölge $4\times4=16$ hücreye bölünür ve her hücrede gradyan yönleri 8 kutulu (45 derecelik) bir yönelim histogramında toplanır; $16\times8=128$.

**Soru 6** (ekrandan, 01:45:00)
Lowe'un grafiğine göre en yakın / ikinci en yakın uzaklık oranı 1'e yaklaştıkça eşleşmeler hakkında ne söylenebilir?

> **Çözüm:** Derste verildi: oran 1'e yaklaştıkça yanlış eşleşmelerin olasılığı hızla artar. Oran 0.4-0.5 civarındayken doğru eşleşmelerin yoğunluğu yüksek, yanlışlarınki düşüktür. Bu yüzden doğrudan Öklid uzaklığı yerine bu oranı eşiklemek daha güvenilirdir.

## Dersin Toparlaması

Ders, Harris köşe bulucusu ödevinin incelenmesiyle başladı: ikinci moment matrisinin NumPy ile toplu hesaplanması, özdeğerlerin anlamı ve değişim elipslerinde üssün $-1/2$, yönün ise özvektörlerden alınması gerektiği tartışıldı. Ardından Harris'in parlaklık kaymasına değişmez, parlaklık ölçeklemesine kısmen değişmez, öteleme ve dönmeye eşdeğişken ama ölçeğe eşdeğişken olmadığı gösterildi. Ölçek sorununu çözmek için DoG tabanlı blob bulucu, Gauss ölçek piramidi ve oktavlar, konum-ölçek uzayında $(x,y,s)$ maksimumu ve yönelim normalizasyonu anlatıldı; bunların Lowe'un SIFT çalışmasının bölge bulucu kısmını oluşturduğu belirtildi. MSER ve diğer bulucularla karşılaştırma yapıldı.

İkinci yarıda bölgeden bilgi çıkarmaya geçildi. Şablon ve histogram gösterimleri, 128 boyutlu SIFT tanımlayıcısı (16 hücre, 8 yön, Gauss ağırlığı, enterpolasyon, normalizasyon ve 0.2 kırpma), SURF, Shape Context ve öz-benzerlik tanımlayıcısı ele alındı. Son olarak eşleştirmede en yakın komşu yerine en yakın ile ikinci en yakın uzaklığın oranının daha güvenilir olduğu görüldü. Eşleştirme konusunun kalan kısmı bir sonraki derse bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
