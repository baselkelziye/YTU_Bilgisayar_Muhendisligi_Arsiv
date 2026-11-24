# Ders 7 Genişletilmiş Notu: İlgi Noktası Bulma, HOG Öznitelikleri, Harris Köşe Bulucu ve Evrişimli Sinir Ağlarına Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri: Klasik Yöntemlerden Derin Öğrenmeye
- 2. HOG Yöntemine Genel Bakış
- 3. Gradyan, Büyüklük ve Yönelim
- 4. Bloklar ve Hücreler
- 5. Yönelim Histogramı ve Oyların Paylaştırılması
- 6. Blok Normalizasyonu ve Son Öznitelik Vektörü
- 7. scikit-image ile HOG Uygulaması
- 8. Geleneksel Makine Öğrenmesi Akışı ve Derin Öğrenme
- 9. İlgi Noktaları ve Tekrarlanabilirlik
- 10. Harris Köşe Bulucu
- 11. scikit-image ile Harris Köşe Bulma
- 12. LeNet ve Evrişimli Sinir Ağlarına Giriş
- 13. Konvolüsyon Katmanında Filtreler
- 14. Renkli Görüntülerde Konvolüsyon
- Örnek Sorular

## 1. Dersin Yeri: Klasik Yöntemlerden Derin Öğrenmeye

Dersin ilk haftalarında klasik bir bilgisayarla görme dersinin temel içeriği işlendi: Python ve NumPy, yoğunluk dönüşümleri ve gamma eğrileri, uzamsal süzgeçler, ortalama süzgeciyle gürültü azaltma, keskinleştirme, birinci ve ikinci türevin kenar bulmada kullanımı, iki boyutlu dönüşümler ve Hough dönüşümüyle doğru ve çember bulma. Çember bulmada kullanılan integro-diferansiyel operatör Daugman tarafından iris bulmak için geliştirilmiştir ve görüntüdeki daire biçimli bölgeleri bulmada elverişlidir.

Bu derste klasik öznitelik çıkarma yöntemlerinden ikisi işlenir: HOG (Histogram of Oriented Gradients) öznitelikleri ve Harris köşe bulucu. Hocaya göre bu yöntemler derin öğrenmeyle birlikte gereksizleşmiş gibi görünse de içlerindeki matematik, başka problemlerde karşılaşılan benzer sorunların çözümünde hâlâ kullanılabilir. Dersin sonunda evrişimli sinir ağlarına (CNN) giriş yapılır; sonraki derslerde konvolüsyon katmanının görevi, max pooling ve softmax gibi işlemler ayrıntılı ele alınacaktır.

> **Hocanın vurgusu:** Konvolüsyon işlemi, filtreler, birinci ve ikinci dereceden türev mutlaka bilinmesi gereken temel kavramlardır.

## 2. HOG Yöntemine Genel Bakış

HOG, Dalal ve Triggs tarafından CVPR 2005'te sunulan ve çok atıf alan bir çalışmadır. İlk amacı görüntüde insan bulmaktır (human detection). Bugün bu iş, etiketli insan görüntüleriyle eğitilmiş bir derin ağla yapılabilir; ama o yıllarda klasik bilgisayarla görme yöntemleriyle çözülüyordu. Fikir şudur: insan vücudunun genel hatlarını oluşturan kollar, bacaklar ve gövde belirli açılarda çizgiler oluşturur. Bu çizgiler kenar bulmayla tespit edilir, açılarına bakılır; görüntü belirli yönelimlerde çizgiler barındırıyorsa orada bir insan olduğuna karar verilir. Zamanla HOG genel bir öznitelik çıkarma yöntemi olarak farklı alanlarda da kullanılmaya başlandı.

Yöntem yedi adımda özetlenir (ekrandan, 00:20:00):

1. Yumuşatma yapmadan merkezi (centered) yatay ve dikey gradyanları hesapla.
2. Gradyan yönelimini ve büyüklüğünü hesapla. Renkli görüntüde her piksel için gradyan büyüklüğü en yüksek olan renk kanalı seçilir.
3. Örnek olarak $64\times128$ boyutlu bir görüntü al.
4. Görüntüyü %50 örtüşen $16\times16$ bloklara böl (toplam $7\times15=105$ blok).
5. Her blok $8\times8$ boyutlu $2\times2$ hücreden (cell) oluşsun.
6. Gradyan yönelimini 9 aralığa (bin) nicemle. Oy, gradyan büyüklüğüdür. Oylar komşu aralık merkezleri arasında doğrusal olarak paylaştırılır. Blok kenarlarına yakın pikseller Gauss ağırlığıyla daha az ağırlıklandırılabilir.
7. Histogramları art arda ekle (öznitelik boyutu: $105\times4\times9=3780$).

Blok ve hücre boyutları uygulamaya göre değiştirilebilir; sayısal sonuç verebilmek için anlatım $64\times128$ görüntü üzerinden yürür.

## 3. Gradyan, Büyüklük ve Yönelim

İlk iki adım türev almadır (ekrandan, 00:30:00). Merkezi türev şu biçimde tanımlanır:

$$f'(x) = \lim_{h\to 0} \frac{f(x+h)-f(x-h)}{2h}$$

> **Ders sonrası not:** Slaytta limit $k\to\infty$ diye yazılmış; doğrusu $h\to 0$'dır.

$x$ yönünde türev için tek boyutlu $[-1\ 0\ 1]$ maskesi, $y$ yönünde ise bunun dikey hâli kullanılır. Bu maskeyle merkez pikselin türevi, sağdaki pikselden soldaki çıkarılarak bulunur. Sonuçlar $s_x$ ve $s_y$ ile gösterilir:

$$M = \sqrt{s_x^2 + s_y^2}, \qquad \theta = \arctan\left(\frac{s_y}{s_x}\right)$$

Slaytta bir kedi görüntüsü, gradyan büyüklüğü görüntüsü ve yönelim görüntüsü yan yana gösterilmiştir.

**Soru:** Önceki derslerde türevi $-1\ 0\ 1$ biçiminde değil, soldaki pikseli sağdakinden çıkararak almıştık; burada fark var mı? **Cevap:** Mantık aynıdır; sağdaki pikselden soldaki çıkarılır. Sıra yalnız işareti değiştirir; büyüklükte kare alındığı için işaret bir sorun yaratmaz.

Yöntemin adı da buradan gelir: gradyan, türev işlemidir; HOG, türev yönelimlerinin histogramını almak demektir.

## 4. Bloklar ve Hücreler

Dördüncü ve beşinci adımlarda görüntü bloklara, bloklar da hücrelere bölünür (ekrandan, 00:25:00). Blok $16\times16$ piksellik bir alandır. Hoca tablette $B_1$ ve $B_2$ adlı iki blok çizerek örtüşmeyi gösterdi: ikinci blok birincinin yarısını kaplayacak biçimde kaydırılır. Aynı %50 örtüşme sütun yönünde de geçerlidir; alt satıra çizilen blok da üsttekiyle yarı yarıya örtüşür.

Her blok $2\times2$ hücreye bölünür; bu da her hücrenin $8\times8=64$ piksel olması demektir. Slayttaki görüntü matrisinde kırmızıyla çizilen alanlar blokları, açık sarı ve yeşille çizilen alanlar hücreleri gösterir.

Blok sayısının hesabı (ara adım eklendi): $64\times128$ görüntüde boyutlar $x,y$ biçiminde verilmiştir; genişlik 64, yükseklik 128'dir. Blok adımı 8 piksel olduğundan genişlikte $64/8=8$ konum varmış gibi görünür, ama son konumda blok görüntüden taşacağı için bir eksiği alınır: $7$. Yükseklikte $128/8=16$, bir eksiği $15$. Toplam blok sayısı $7\times15=105$'tir.

Yönelim histogramı her hücre için, yani 64 piksel üzerinden oluşturulur.

## 5. Yönelim Histogramı ve Oyların Paylaştırılması

### 5.1 Açı aralıkları

Gradyan yönelimi $0$ ile $180^\circ$ arasındadır. Bu aralık 9'a bölününce $180/9=20^\circ$ genişliğinde aralıklar çıkar: $0$-$20$, $20$-$40$, ..., $160$-$180$. Her aralığın bir merkezi vardır: $10, 30, 50, 70, 90, 110, 130, 150, 170$ (ekrandan, 00:35:00).

### 5.2 Oylama ve doğrusal paylaştırma

Hücredeki 64 pikselin her biri için işlem yapılır. Pikselin gradyan yönelimi hangi aralığa düşüyorsa o aralığa oy verir; oyun miktarı gradyan büyüklüğüdür. Ancak oy tek aralığa yazılmaz, komşu aralıkla paylaşılır (ekrandan, 00:40:00 ve 00:45:00).

Örnek: Pikselin yönelimi $\theta=85^\circ$ olsun.

- Verilen: $\theta=85^\circ$; tabletteki örnekte gradyan büyüklüğü 100 alındı.
- $85^\circ$, $80$-$100$ aralığındadır; bu aralığın merkezi 90'dır. Komşu ve daha yakın olan öbür merkez, $60$-$80$ aralığının merkezi 70'tir.
- Uzaklıklar: 90 merkezine $5^\circ$, 70 merkezine $15^\circ$.
- Yakın merkeze daha çok, uzak merkeze daha az oy gitmelidir. Aralık genişliği 20 olduğundan 90 merkezine $1-5/20 = 15/20 = 3/4$, 70 merkezine $1-15/20 = 5/20 = 1/4$ oranında oy verilir.
- Bu oranlar gradyan büyüklüğüyle çarpılır: 90 merkezine $100\times3/4=75$, 70 merkezine $100\times1/4=25$ oy.

Slayttaki "Hence, ratios are 5/20=1/4, 15/20=3/4" satırında $1/4$ oranı uzak merkeze (70), $3/4$ oranı yakın merkeze (90) aittir; slayttaki histogramda da 70 çubuğuna $1/4$, 90 çubuğuna $3/4$ okları çizilmiştir.

> **Hocanın vurgusu:** Yöntem bütün oyu içinde bulunduğu aralığa vermiyor, uzaklıklara göre komşuyla paylaştırıyor. Hoca bu matematiği özellikle beğendiğini ve açı hesaplayıp onun üzerinden iş yapılan başka problemlerde bu fikrin akla gelmesi gerektiğini söyledi. HOG'un hazır kodları internette vardır; ama içerideki matematik bilinirse başka yerlerde de kullanılabilir.

64 pikselin bütün oyları üst üste toplanınca hücrenin 9 çubuklu histogramı oluşur. Bir çubuğun yüksekliği, o açı aralığındaki kenarların toplam gücünü gösterir.

**Soru:** Burada "açı" dediğimiz büyüklük (magnitude) mü? **Cevap:** Hayır, yönelimdir (orientation); $\arctan(s_y/s_x)$ ile hesaplanır. Büyüklük, türev bileşenlerinin kareleri toplamının kareköküdür.

**Soru:** Histogramda merkezi 10 derece ile 130 ve 150 derece olan çubuklar yüksekse, görüntüde bu açılarda kenarlar, çizgiler var diye mi yorumlamalıyım? **Cevap:** Evet; o açılardaki kenarların çubukları yüksek, diğerlerininki düşük çıkar.

**Soru:** Oy her zaman bir önceki komşuya mı, yoksa en yakın komşu merkeze mi paylaştırılıyor? Örneğin $95^\circ$ olsaydı 110 merkezli aralığa mı paylaştırılırdı? **Cevap:** Evet, hangi tarafa yakınsa o taraftaki komşu aralıkla paylaştırılır. $85^\circ$ örneğinde $60$-$80$ aralığı oy aldı; $95^\circ$ olsaydı oy 90 ile 110 merkezleri arasında, yani $100$-$120$ aralığıyla paylaşılırdı.

## 6. Blok Normalizasyonu ve Son Öznitelik Vektörü

### 6.1 Örtüşmenin yarattığı sorun ve normalizasyon

Son adım histogramların art arda eklenmesi ve normalizasyondur. Bir blok dört hücreden oluştuğu için her bloktan dört histogram çıkar. Bloklar %50 örtüştüğünden bir bloğun hücresi, bir sonraki bloğun da hücresidir. Normalizasyon yapılmasaydı aynı hücrenin aynı histogramı bir sonraki blokta aynen tekrar edilirdi.

Bunun için her blok kendi içinde normalize edilir: bloktaki dört hücrenin $k=1,\dots,2\times2\times9=36$ değerinin kareleri toplanır, karekök alınır ve bütün histogram değerleri buna bölünür. Bu bir L2 normalizasyonudur. Hoca paydada bu toplama bir sabitin (1) eklendiğini söyledi. <!-- BELİRSİZ: Normalizasyon formülünün slayttaki tam yazımı karelerde görünmüyor; sabitin karekök içinde mi dışında mı olduğu doğrulanamadı. -->

> **Ek bilgi (derste anlatılmadı):** Dalal ve Triggs'in özgün çalışmasında bu sabit büyük olasılıkla küçük bir $\varepsilon$ olarak yazılır ve L2 normalizasyonu $v/\sqrt{\lVert v\rVert_2^2+\varepsilon^2}$ biçimindedir. scikit-image'daki öntanımlı `L2-Hys` normu da büyük olasılıkla L2 normalizasyonundan sonra değerleri 0,2 ile kırpıp yeniden normalize eder.

**Soru:** Normalizasyonda paydada "+1" vardı; hiç kenar olmayan bölgelerde paydanın sıfır çıkmaması için mi? **Cevap:** Evet. Hücrede kenar yoksa, örneğin simsiyah bir bölgede, türevin büyüklüğü sıfır çıkar; sıfıra bölmenin önüne geçmek için eklenmiştir.

### 6.2 Son öznitelik vektörü

Bütün histogramlar art arda eklenerek (concatenate) tek boyutlu bir vektör yapılır: önce ilk hücrenin 64 pikselden üretilmiş 9 uzunluklu histogramı, sonra bir sonrakininki, ve böyle devam (ekrandan, 00:50:00).

Uzunluk hesabı:

- Blok sayısı: 105.
- Her blokta hücre sayısı: 4.
- Her hücrede aralık sayısı: 9.
- Öznitelik uzunluğu: $105\times4\times9=3780$.

### 6.3 Görselleştirme

HOG, açılar biçiminde görselleştirilebilir. Her hücrede dokuz aralıktan oyu en büyük olanın açısı çizgi olarak çizilir; örneğin bir hücrede baskın açı $90^\circ$ ise o hücreye dikey bir çizgi çizilir. Slayttaki örnekte yürüyen bir adamın silüeti dikey çizgilerle, denizin üstündeki dalgalar ise yatay çizgilerle görünür.

HOG eski bir yöntemdir ama içindeki matematik ilginçtir ve bu teknikle farklı alanlarda öznitelik vektörü oluşturulabilir; örneğin doku sınıflamada alternatif bir fikir olabilir.

## 7. scikit-image ile HOG Uygulaması

Jupyter defterinde scikit-image kütüphanesinin `data` klasöründen astronot görüntüsü alınır ve `rgb2gray` ile gri seviyeye çevrilir. Görüntü $512\times512$ boyutundadır. `skimage.feature.hog` fonksiyonunun belgedeki imzası şöyledir (ekrandan, 00:55:00):

```python
skimage.feature.hog(image, orientations=9, pixels_per_cell=(8, 8),
                    cells_per_block=(3, 3), block_norm='L2-Hys',
                    visualize=False, transform_sqrt=False,
                    feature_vector=True, multichannel=None, *,
                    channel_axis=None)
```

Belgede HOG hesabı beş adımda özetlenir: (isteğe bağlı) genel görüntü normalizasyonu, satır ve sütun yönünde gradyan, gradyan histogramları, bloklar boyunca normalizasyon ve öznitelik vektörüne düzleştirme.

Parametreler:

- `orientations`: $0$-$180^\circ$ aralığının kaç parçaya bölüneceği.
- `pixels_per_cell`: bir hücrenin kaç pikselden oluşacağı. Özgün çalışmada $8\times8$'dir; daha küçük doku değişimleri önemliyse küçültülebilir.
- `cells_per_block`: bir bloktaki hücre sayısı.
- `block_norm`: blok içi normalizasyonun türü; derste anlatılan kareler toplamıyla normalizasyon L2 normudur ve başka türler de seçilebilir.
- `visualize`: HOG görüntüsünün de döndürülüp döndürülmeyeceği.

> **Ders sonrası not:** Hoca hücre boyutunu anlatırken belgede "$3\times3$ örneğini vermiş" dedi; ekrandaki imzada $(3, 3)$ değeri `pixels_per_cell`'in değil, `cells_per_block`'un öntanımlı değeridir. `pixels_per_cell`'in öntanımlı değeri $(8, 8)$'dir.

Hoca kendi örneğinde özgün çalışmadaki gibi 9 yönelim, `pixels_per_cell=(8, 8)`, `cells_per_block=(2, 2)` ve `visualize=True` kullandı. HOG görüntüsü daha iyi görünsün diye `exposure.rescale_intensity(hog_image, in_range=(0, 10))` ile yeniden ölçeklendi ve girdi görüntüsünün yanına çizdirildi (ekrandan, 01:00:00):

```python
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 8), sharex=True, sharey=True)
ax1.axis('off')
ax1.imshow(image, cmap=plt.cm.gray)
ax1.set_title('Input image')

# Rescale histogram for better display
hog_image_rescaled = exposure.rescale_intensity(hog_image, in_range=(0, 10))
ax2.axis('off')
ax2.imshow(hog_image_rescaled, cmap=plt.cm.gray)
ax2.set_title('Histogram of Oriented Gradients')
plt.show()
```

<!-- BELİRSİZ: hog çağrısının bulunduğu satır karede kesik görünüyor; parametreler altyazıdaki anlatımdan alındı. -->

Sağdaki çıktıda her $8\times8$ hücrede baskın yönelim beyaz çizgiyle çizilir. Hücre boyutu $16\times16$ yapılıp yeniden çalıştırılınca çizgiler daha büyük alanlarda çizildi. Böyle bir çıktı, doku sınıflamada ya da şekil tanımada öznitelik olarak kullanılabilir.

## 8. Geleneksel Makine Öğrenmesi Akışı ve Derin Öğrenme

Geleneksel makine öğrenmesi akışında bir girdi görüntüsünden öznitelik çıkarılır (köşe, kenar, HOG gibi), bu öznitelikler bir makine öğrenmesi algoritmasına verilir ve algoritma bir çıktı üretir. Yaklaşık son on yıldır kullanılan derin öğrenme yapısında öznitelik çıkarma, modelin CNN katmanlarında otomatik yapılır: doğrudan girdi görüntüsü verilir, ağ öznitelikleri kendisi çıkarır. Ağ, insanın aklına gelen köşe, kenar ve HOG gibi özniteliklerin ötesinde daha karmaşık öznitelikler bulabilir; derin ağların başarısı büyük ölçüde buradan gelir.

## 9. İlgi Noktaları ve Tekrarlanabilirlik

Klasik bilgisayarla görmede önce köşe ve kenar gibi belirli noktalar bulunur; bunlara ilgi noktası (interest point) denir. Sonra bu noktaların çevresindeki alandan bir tanımlayıcı (descriptor) çıkarılır. Aranan bir nesnenin (kedi, köpek, kamyon, insan gibi) bilinen görüntüsündeki tanımlayıcılarla yeni görüntüdeki tanımlayıcılar eşleştirilir ve iki nesnenin aynı olup olmadığına karar verilir.

Slayttaki örnekte karlı bir dağın iki farklı açıdan çekilmiş görüntüsü vardır. Dağın tepesinden çıkarılan bir öznitelik öbür görüntüde benzer noktayla, küçük tepenin üstündeki noktalar da kendi karşılıklarıyla eşleşir. Eşleşen noktaların sayısına ve geometrisine bakılarak iki görüntünün aynı olup olmadığı anlaşılır.

İlgi noktalarında tekrarlanabilirlik (repeatability) aranır: iki görüntüde aynı noktaların (en azından bir kısmının) bulunması gerekir; üstelik bulma işlemi her görüntüde bağımsız çalışabilmelidir (ekrandan, 01:20:00). Bir görüntüde dağın tepesinde bulunan nokta öbür görüntüde bulunmamışsa tekrarlanabilirlik yoktur. Aynı yerin farklı ölçek ve açıdan çekilmiş iki görüntüsünde bulunan noktalar tamamen farklı yerlerdeyse eşleştirme yapılamaz.

## 10. Harris Köşe Bulucu

### 10.1 Temel fikir

Köşe bulma bilgisayarla görmede çok çalışılmış bir konudur ve onlarca yöntem vardır. Yöntemlerin doğruluğu genellikle iki tür görüntüde sınanır: köşeleri işaretli sentetik bir görüntü ve bir gerçek görüntü (örneğin bir evin pencere ve kapı köşeleri, bir borunun geçtiği köşeler). Harris köşe bulucu bunların en yaygın kullanılan ve başarılı sayılanlarından biridir.

Köşe bir pencere içinde tanınır: pencere herhangi bir yönde kaydırıldığında parlaklıkta büyük değişim olmalıdır. Pencere sağa, sola, yukarı ve aşağı küçük miktarlarda (örneğin iki piksel) kaydırılır ve önceki konumla yeni konum arasındaki değişime bakılır (ekrandan, 01:25:00):

- Düz bölge (flat): hiçbir yönde değişim olmaz; pencere hep aynı arka planı görür.
- Kenar (edge): kenar doğrultusunda kaydırınca kenar sürekli olduğu için değişim olmaz; ona dik yönde kaydırınca değişim olur.
- Köşe (corner): her yönde belirgin değişim olur.

> **Hocanın vurgusu:** Köşe bulucu anlatılırken bu üç pencere şekli çizilmeli ve anlatım onun üzerinden yapılmalıdır.

### 10.2 Matematik

Görüntü $I(x,y)$ ile, $x$ ekseninde $u$, $y$ ekseninde $v$ kadar kaydırılmış görüntü $I(x+u,y+v)$ ile gösterilir. Pencere içinde kaydırılmış ve özgün parlaklıklar arasındaki farkın karesi alınır (fark negatif de olabilir), pencere fonksiyonuyla ağırlıklandırılıp toplanır:

$$E(u,v) = \sum_{x,y} w(x,y)\,\big[I(x+u,y+v) - I(x,y)\big]^2$$

Pencere fonksiyonu $w(x,y)$ dikdörtgen ya da Gauss olabilir; Gauss pencerede merkezdeki katsayı en büyüktür ve kenarlara doğru ağırlık azalır.

Küçük kaymalar için çift doğrusal (bilinear) yaklaşım yazılır (ekrandan, 01:30:00):

$$E(u,v) \cong [u,\ v]\; M \begin{bmatrix} u \\ v \end{bmatrix}, \qquad M = \sum_{x,y} w(x,y) \begin{bmatrix} I_x^2 & I_x I_y \\ I_x I_y & I_y^2 \end{bmatrix}$$

$M$ görüntü türevlerinden hesaplanan $2\times2$ bir matristir. $I_x^2$, $x$ yönündeki türevin karesi; $I_xI_y$, $x$ ve $y$ yönü türev maskelerinin çıktılarının çarpımı; $I_y^2$, $y$ yönündeki türevin karesidir. Her piksel için $W$ penceresiyle ağırlıklandırılmış böyle bir matris oluşturulur.

### 10.3 Öz değerlerle sınıflandırma

$M$'nin iki öz değeri $\lambda_1$ ve $\lambda_2$ bulunur; bunlar değişimin olduğu eksenleri gösterir. Pencere tek yönde değişim gösteriyorsa kenar, iki yönde de değişim gösteriyorsa köşe vardır. Buna dayanarak $\lambda_1$-$\lambda_2$ düzleminde bölgeler tanımlanır:

- $\lambda_1$ ve $\lambda_2$ çok küçük: düz bölge.
- $\lambda_1 \gg \lambda_2$: yalnız bir yönde değişim var, kenar. Hoca bunu bir doğrultudaki kenar olarak yorumladı.
- $\lambda_2 \gg \lambda_1$: yine tek yönde değişim, öbür doğrultudaki kenar.
- $\lambda_1$ ve $\lambda_2$ ikisi de büyük: köşe.

<!-- BELİRSİZ: Öz değer düzlemi slaytı karelerde görünmüyor; bölge sınırları altyazıdaki anlatımdan alındı. -->

> **Ek bilgi (derste anlatılmadı):** Harris yönteminde öz değerleri tek tek hesaplamak yerine büyük olasılıkla $R = \det(M) - k\,(\operatorname{trace} M)^2 = \lambda_1\lambda_2 - k(\lambda_1+\lambda_2)^2$ köşe yanıtı kullanılır. $R$ büyük ve pozitifse köşe, negatifse kenar, mutlak değeri küçükse düz bölge sayılır. scikit-image'daki `corner_harris` fonksiyonunun `k` parametresi bu katsayıdır.

## 11. scikit-image ile Harris Köşe Bulma

Jupyter defterinde aynı konu, düz bölge, kenar ve köşenin pencere hareketine göre nasıl algılandığı anlatılarak tekrar edilir. scikit-image `feature` modülünde birçok köşe bulucu hazırdır (ekrandan, 01:35:00): `corner_fast` (FAST köşeleri), `corner_foerstner` (Förstner), `corner_harris` (Harris), `corner_kitchen_rosenfeld` (Kitchen ve Rosenfeld) ve `corner_moravec` (Harris'ten önce çalışmış Moravec'in yöntemi). `corner_harris` belgesinde köşe bulucunun, türevlerden kurulan otokorelasyon matrisi $A$'yı kullandığı ve çıktı olarak Harris yanıt görüntüsü döndürdüğü yazar.

Parametreler arasında köşeleri kenarlardan ayıran duyarlılık katsayısı `k`, keskin köşeler için kullanılan normalizasyon katsayısı `eps` ve Gauss için `sigma` vardır.

> **Ders sonrası not:** Hoca `k` parametresinin 0 ile 0,02 arasında değer aldığını okudu; scikit-image belgesinde bu aralık büyük olasılıkla $[0, 0.2]$ olarak yazılıdır ve öntanımlı değer $0.05$'tir. Küçük `k` değerleri keskin köşelerin bulunmasını sağlar.

Örnekte satranç tahtası (checkerboard) görüntüsü kullanılır. Satranç tahtasındaki siyah-beyaz geçişler çok belirgin ve $90^\circ$'lik olduğu için yöntemi zorlamak amacıyla görüntü afin dönüşümle bükülür (warp), böylece açılar tam $90^\circ$ görünmez. Ardından görüntüye bir elips ve iki beyaz kare eklenir (ekrandan, 01:40:00):

```python
image = warp(data.checkerboard(), tform.inverse, output_shape=(350, 350))
rr, cc = ellipse(310, 175, 10, 100)
image[rr, cc] = 1
image[180:230, 10:60] = 1
image[230:280, 60:110] = 1
coords = corner_peaks(corner_harris(image), min_distance=5)
coords_subpix = corner_subpix(image, coords, window_size=13)
fig, ax = plt.subplots()
ax.imshow(image, interpolation='nearest', cmap=plt.cm.gray)
ax.plot(coords[:, 1], coords[:, 0], '.b', markersize=3)
ax.plot(coords_subpix[:, 1], coords_subpix[:, 0], '+r', markersize=15)
ax.axis((0, 350, 350, 0))
plt.show()
```

<!-- BELİRSİZ: tform satırı karede kısmen kesik; AffineTransform(scale=(1.3, 1.1), rotation=1, shear=0.7, translation=(210, 50)) olarak okunuyor. -->

Elipsin merkezi $(310, 175)$, iki yöndeki yarı eksenleri $10$ ve $100$'dür. Beyaz kareler $180$-$230$ satır / $10$-$60$ sütun ve $230$-$280$ satır / $60$-$110$ sütun aralıklarındadır. Amaç, hem $90^\circ$'lik köşeleri olan hem de $120^\circ$ civarı geniş açılar içeren sentetik bir görüntü oluşturup yöntemin ne kadarını yakalayabildiğini görmektir. Sonuçta karelerin bütün köşeleri bulundu, ama $120^\circ$ civarı geniş açılı bazı köşeler köşe olarak işaretlenmedi.

`min_distance=5` parametresiyle bunların yakalanması sağlanabilir mi diye bakıldığında, bu parametrenin `corner_harris`'in değil `corner_peaks`'in parametresi olduğu görüldü; `corner_harris` öntanımlı parametreleriyle kullanılmıştır.

## 12. LeNet ve Evrişimli Sinir Ağlarına Giriş

Geleneksel bilgisayarla görmede öznitelik çıkarma, kullanıcının aklına gelen öznitelikler üzerinden yapıldı: kenarlar, köşeler, HOG öznitelikleri bulundu, bir öznitelik vektörü hâline getirildi ve makine öğrenmesi yöntemlerine verildi. Artık bu noktada derin öğrenme yöntemleri kullanılıyor.

Yann LeCun'un 1998'deki LeNet ağının yapısı şöyledir (ekrandan, 01:45:00):

```text
INPUT 32x32
  -> Convolutions      -> C1: feature maps 6@28x28
  -> Subsampling       -> S2: f. maps 6@14x14
  -> Convolutions      -> C3: f. maps 16@10x10
  -> Subsampling       -> S4: f. maps 16@5x5
  -> Full connection   -> C5: layer 120
  -> Full connection   -> F6: layer 84
  -> Gaussian connections -> OUTPUT 10
```

Adım adım (ara adım eklendi):

- Birinci konvolüsyon katmanında 6 farklı filtre kullanılır. $32\times32$ girdi $28\times28$'e düştüğüne göre her kenardan ikişer, toplam dört piksel kaybolmuştur; dolgu (padding) yapılmadığında bu, $5\times5$ filtre demektir: $32-5+1=28$.
- Alt örnekleme (subsampling) her $2\times2$ alanı tek pikselle temsil eder: $28\times28 \to 14\times14$, yine 6 harita.
- İkinci konvolüsyon katmanında 16 filtre vardır; görüntü yine dört piksel küçülür: $14-5+1=10$, yani yine $5\times5$ filtre.
- İkinci alt örnekleme: $10\times10 \to 5\times5$, 16 harita.
- Sonra düzleştirme (flatten) ile haritalar bir vektöre dizilir ve bu öznitelik vektörü tam bağlı (fully connected) katmanlara girdi olarak verilir.

Düzleştirmeye kadar olan kısım öznitelik çıkarma işini yapar; yani klasik bilgisayarla görmede ilgi noktası, HOG ve köşe bulmayla yapılan işin yerine geçen katmandır. LeNet'te iki konvolüsyon katmanı vardır. Günümüz ağlarında konvolüsyon katmanı sayısı yüzü bulabilir. İlk katmanların ne yaptığı az çok tahmin edilebilir (örneğin bir katman ikinci türeve benzer bir şey bulmuş olabilir); ama üst üste uygulanan konvolüsyonlarla insanın aklına gelmeyen karmaşık öznitelikler üretilir ve bu ağlar bu yüzden başarılıdır.

Bir başka slayt örneğinde, görüntüdeki bazı örüntülerin (örneğin bir kuşun gagası) bütün görüntüden çok daha küçük olduğu belirtilir. Konvolüsyon katmanındaki filtrelerden hangisi tanımada daha başarılı çıktı veriyorsa ağ o bölgeye odaklanır ve onun ağırlığını artırır.

## 13. Konvolüsyon Katmanında Filtreler

### 13.1 Konvolüsyonun hatırlatılması

Konvolüsyonda elimizde bir girdi görüntüsü ve bir çekirdek (örneğin $3\times3$ filtre maskesi) vardır. Çekirdek görüntünün sol üst köşesine oturtulur, karşılıklı değerler çarpılıp toplanarak merkez piksel için bir çıktı üretilir; çekirdek kaydırılarak bütün noktalar için çıktı üretilir.

> **Hocanın vurgusu:** Bir giriş görüntü matrisi ve $3\times3$ filtre verildiğinde konvolüsyon sonucunun ne olacağı hesaplanabilmelidir; hoca bunu sınavda sorabileceğini söyledi. İşlemleri ezberlemeden anlayarak yapmak, çıkan sonucu yorumlayabilmeyi sağlar.

### 13.2 Örnek: $6\times6$ ikili görüntü ve iki filtre

Slayttaki girdi görüntüsü kolaylık olsun diye ikilidir (binary); gri seviyeli de olabilirdi (ekrandan, 01:50:00 ve 01:55:00):

$$I = \begin{bmatrix}
1 & 0 & 0 & 0 & 0 & 1\\
0 & 1 & 0 & 0 & 1 & 0\\
0 & 0 & 1 & 1 & 0 & 0\\
1 & 0 & 0 & 0 & 1 & 0\\
0 & 1 & 0 & 0 & 1 & 0\\
0 & 0 & 1 & 0 & 1 & 0
\end{bmatrix}, \quad
F_1 = \begin{bmatrix} 1 & -1 & -1\\ -1 & 1 & -1\\ -1 & -1 & 1 \end{bmatrix}, \quad
F_2 = \begin{bmatrix} -1 & 1 & -1\\ -1 & 1 & -1\\ -1 & 1 & -1 \end{bmatrix}$$

Filtre 1'in görevi ana köşegen doğrultusundaki çizgileri, Filtre 2'nin görevi dikey çizgileri bulmaktır; katsayılar bunu gösterir. Slayttaki kırmızı yazıya göre bu katsayılar ağın öğrenilecek parametreleridir (these are the network parameters to be learned): sistem farklı katsayıları deneyerek hangisinin uygun olduğunu kendisi öğrenir. Her filtre küçük bir ($3\times3$) örüntüyü yakalar.

Filtre 1 sol üst köşede: görüntü parçası $\begin{bmatrix}1&0&0\\0&1&0\\0&0&1\end{bmatrix}$'dir. Köşegendeki üç 1, filtrenin $+1$ katsayılarıyla çarpılır; diğer hücreler 0'dır. Sonuç $3$.

Filtre 2 aynı konumda: orta sütunda $0, 1, 0$ değerleri $+1$ ile çarpılınca $+1$; yan sütunlardaki $1$ ve $1$ değerleri $-1$ ile çarpılınca $-2$. Sonuç $-2+1=-1$. (Hoca önce $1$ dedi, sonra $-1$ katsayılarını unuttuğunu fark edip $-1$ olarak düzeltti.)

Çıktı boyutu: $3\times3$ maskenin merkezinin sağında, solunda, üstünde ve altında birer piksel kalır; dolgu yapılmazsa görüntü her kenardan bir piksel kaybeder ve $6\times6$ girdiden $4\times4$ çıktı çıkar. Bu sorun görüntünün etrafına dolgu (padding) eklenerek giderilebilir; hocaya göre CNN'lerde genellikle küçülmüş çıktı üzerinden çalışılır.

Filtre 2'nin en yüksek çıktıyı üreteceği bölge, dikey çizginin bulunduğu sağ alt köşedir.

Adım (stride) 1 ile Filtre 1'in bütün çıktısı (python ile hesaplandı; slaytta hocanın okuduğu ilk satır $3, -1, -3, -1$ ile uyumlu):

$$F_1 * I = \begin{bmatrix} 3 & -1 & -3 & -1\\ -3 & 1 & 0 & -3\\ -3 & -3 & 0 & 1\\ 3 & -2 & -2 & -1 \end{bmatrix}$$

İki konumda $3$ çıkar; bunlar ana köşegen doğrultusunda çizgi bulunan bölgeleri gösterir. Bu çıktılarla tespit (detection) ya da tanıma (recognition) yapılabilir.

Filtre 2'nin çıktısı (python ile hesaplandı):

$$F_2 * I = \begin{bmatrix} -1 & -1 & -1 & -1\\ -1 & -1 & -2 & 1\\ -1 & -1 & -2 & 1\\ -1 & 0 & -4 & 3 \end{bmatrix}$$

En büyük değer ($3$) sağ alt köşededir; yalnız bu bölgede tepe yapar.

### 13.3 Adım (stride)

Konvolüsyonda filtre her seferinde bir piksel kaydırılıyorsa adım 1'dir. Filtre iki piksel kaydırılırsa adım 2 olur; bu, konvolüsyona eklenen bir başka parametredir. <!-- BELİRSİZ: Adım 2 slaytındaki çıktı karelerde görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** Dolgusuz konvolüsyonda çıktı boyutu $\lfloor (n-f)/s \rfloor + 1$ ile bulunur ($n$ girdi, $f$ filtre boyutu, $s$ adım). Bu örnekte $s=2$ için $\lfloor(6-3)/2\rfloor+1=2$, yani $2\times2$ çıktı çıkar.

### 13.4 Filtre sayısı ve çıktı sayısı

Kaç filtre kullanılıyorsa o kadar çıktı haritası üretilir. LeNet'te birinci konvolüsyon katmanındaki 6 filtre 6 adet $28\times28$ çıktı, ikinci katmandaki 16 filtre 16 çıktı üretir. Hoca filtrelerin $5\times5$ olduğunu görüntü boyutlarından çıkardığını belirtti. Filtre katsayıları rastgele başlatılıp hangilerinin daha uygun olduğu denenerek öğrenilir; kabaca, ağ dikey çizgilere mi yatay çizgilere mi bakacağını kendisi öğrenir, gerçekte ise daha karmaşık öznitelikler oluşur.

## 14. Renkli Görüntülerde Konvolüsyon

Renkli görüntülerde konvolüsyon kırmızı, yeşil ve mavi kanallar üzerinde yapılır; her kanal ayrı bir matristir. Bu yüzden filtre de $3\times3\times3$ olmalıdır: art arda üç tane $3\times3$ katman, her biri bir renk kanalı için. Bu üç katmanın bütününe tek bir filtre denir (ekrandan, 02:00:00 ve 02:05:00).

Girdi $6\times6\times3$ olsun. Filtre 1 ($3\times3\times3$) bütün kanallara birlikte oturtulur. Tek kanalda 9 çarpım yapılıp toplanırken burada $27$ çarpım yapılır ve 27'sinin toplamından tek bir çıktı değeri üretilir. Dolgusuz işlemde her kenardan bir piksel eksildiği için çıktı $4\times4$ olur ve bir filtre tek bir çıktı kanalı verir.

> **Hocanın vurgusu:** RGB görüntülerle çalışırken filtrenin $3\times3\times3$ olduğuna, ama bir filtrenin yalnız bir çıktı ürettiğine dikkat edilmelidir.

**Soru:** İzlediğim bir çalışmada ağ insanlarla heykeli ayıramıyordu. Çıktı bu şekilde tek kanala indiği için, renkler farklı olsa bile değer yüksek çıkınca ikisini de insan sayıyor olabilir mi; filtre gri ile renkliyi ayırt edemez mi? **Cevap:** Hoca böyle düşünmüyor. Görüntü `rgb2gray` ile gri seviyeye çevrilip verilseydi renk bileşenleri ortadan kalkardı; burada ise birinci filtre her renk kanalı için ayrı katsayılar kullandığı için renk bilgisi kullanılır, renk açısından bir kayıp yoktur.

Sonraki derste AlexNet, GoogLeNet ve VGG19 gibi standart CNN yapıları incelenecek; her birinde konvolüsyon katmanında kaç filtre kullanıldığı, boyutu ve çıktısının ne olacağı kâğıt üzerinde hesaplanacaktır. Amaç, kullanılan filtrenin ne iş yaptığını, nasıl bir çıktı üreteceğini ve kaç çıktı üreteceğini hayal edebilmektir.

## Örnek Sorular

### Soru 1 (ekrandan, 00:20:00; derste sözlü, 00:49:02)

$64\times128$ boyutlu bir görüntü %50 örtüşen $16\times16$ bloklara bölünüyor; her blok $8\times8$ boyutlu $2\times2$ hücreden oluşuyor ve yönelim 9 aralığa nicemleniyor. HOG öznitelik vektörünün uzunluğu nedir?

**Çözüm (derste verildi):** Blok sayısı $(64/8-1)\times(128/8-1)=7\times15=105$. Uzunluk $=105 \times 4 \times 9 = 3780$.

### Soru 2 (ekrandan, 00:45:00)

Bir pikselin gradyan yönelimi $\theta=85^\circ$, gradyan büyüklüğü 100'dür. 9 aralıklı ($0$-$180^\circ$) histogramda oy nasıl paylaştırılır?

**Çözüm (derste verildi):** Merkezlere uzaklıklar: 70 merkezine 15, 90 merkezine 5. Oranlar: 90 merkezine $1-5/20=3/4$, 70 merkezine $1-15/20=1/4$. Oylar: 90 merkezine $75$, 70 merkezine $25$.

### Soru 3 (derste sözlü, 00:43:50)

Yönelim $95^\circ$ olsaydı oy hangi aralık merkezleri arasında paylaştırılırdı?

**Çözüm:** Derste cevap: oy 90 merkezi ile 110 merkezi (yani $100$-$120$ aralığı) arasında paylaştırılır.

> **Çözüm (derste verilmedi):** Uzaklıklar 90'a 5, 110'a 15 olduğundan 90 merkezine $3/4$, 110 merkezine $1/4$ oranında oy gider (python ile doğrulandı).

### Soru 4 (ekrandan, 01:55:00; derste sözlü, 01:52:16)

Bölüm 13.2'deki $6\times6$ ikili görüntüye Filtre 1 sol üst köşeye oturtularak uygulanıyor. Bu konum için çıktı nedir? Dolgusuz konvolüsyonun çıktı boyutu ne olur?

**Çözüm (derste verildi):** Köşegendeki üç 1 filtrenin $+1$ katsayılarıyla çakışır, diğer hücreler 0'dır: çıktı $3$. Her kenardan bir piksel kaybolur: çıktı $4\times4$.

### Soru 5 (ekrandan, 01:55:00; derste sözlü, 01:54:37)

Aynı konuma Filtre 2 oturtulursa çıktı ne olur? Filtre 2'nin en yüksek çıktıyı üreteceği bölge neresidir?

**Çözüm (derste verildi):** Orta sütunda $+1$, yan sütunlarda iki adet $1$ ile $-2$: çıktı $-1$. Filtre 2 dikey çizgileri bulduğu için en yüksek çıktı ($3$) dikey çizginin bulunduğu sağ alt köşede oluşur (python ile doğrulandı).

### Soru 6 (derste sözlü, 01:43:28)

LeNet'te $32\times32$ girdi birinci konvolüsyon katmanından sonra $28\times28$ oluyor. Dolgu yapılmadığına göre filtre boyutu nedir?

**Çözüm (derste verildi):** $32-f+1=28 \Rightarrow f=5$; filtreler $5\times5$'tir. İkinci konvolüsyonda da $14-5+1=10$ olur.

### Soru 7 (ekrandan, 02:05:00; derste sözlü, 02:01:57)

$6\times6\times3$ RGB görüntüye $3\times3\times3$ boyutlu tek bir filtre dolgusuz uygulanıyor. Her konumda kaç çarpım yapılır ve çıktının boyutu ne olur?

**Çözüm (derste verildi):** Her konumda $3\times3\times3=27$ çarpım yapılıp toplanır ve tek değer çıkar. Çıktı $4\times4$ boyutunda tek kanallıdır.

## Dersin Toparlaması

Bu derste klasik bilgisayarla görmenin iki öznitelik yöntemi incelendi. HOG, türev yönelimlerinin hücre bazında histogramını çıkarır; $64\times128$ görüntüde %50 örtüşen 105 blok, her blokta dört hücre ve dokuz yönelim aralığıyla 3780 uzunluklu bir vektör üretir. Yöntemin dikkat çeken matematiği, oyların komşu aralık merkezlerine uzaklıkla orantılı paylaştırılması ve örtüşen bloklarda blok içi normalizasyondur. Harris köşe bulucu ise kaydırılan bir pencerenin yarattığı değişimi türevlerden kurulan $2\times2$ $M$ matrisiyle ifade eder; $M$'nin öz değerlerinin büyüklüğü düz bölge, kenar ve köşeyi ayırır. İki yöntem de scikit-image ile Jupyter defterinde uygulandı.

Dersin son kısmında öznitelik çıkarmanın derin öğrenmede CNN katmanlarına geçtiği gösterildi: LeNet'in katman boyutları, konvolüsyon filtrelerinin öğrenilen parametreler olması, dolgusuz konvolüsyonda boyutun küçülmesi, adım parametresi ve renkli görüntüde üç kanallı filtrenin tek çıktı üretmesi işlendi. Sonraki derste AlexNet, GoogLeNet ve VGG19 gibi yapılarda katman boyutlarının kâğıt üzerinde hesaplanmasıyla devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
