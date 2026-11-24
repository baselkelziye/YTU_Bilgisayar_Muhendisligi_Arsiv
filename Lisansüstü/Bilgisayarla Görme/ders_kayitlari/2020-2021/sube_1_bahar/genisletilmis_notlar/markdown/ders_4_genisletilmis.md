# Ders 4 Genişletilmiş Notu: Görüntü Keskinleştirme, Gradyan Operatörleri ve Kenar Bulma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Keskinleştirmenin Amacı ve Dersin Akışı
- 2. Bir Boyutlu İşarette Birinci ve İkinci Türev
- 3. Laplace Operatörü ve Maskelerin Türetilmesi
- 4. Laplace ile Görüntü Keskinleştirme
- 5. Keskinsizleştirme Maskesi ve Yüksek Artırımlı Süzgeç
- 6. Gradyan Operatörü
- 7. Roberts, Prewitt ve Sobel Maskeleri
- 8. Python'da Prewitt Çekirdekleriyle Kenar Bulma
- 9. LoG Süzgeci (Marr-Hildreth Kenar Bulucu)
- 10. Gradyan Büyüklüğü, Gauss Yumuşatma ve Sobel Uygulaması
- 11. Canny Kenar Bulucu ve Diğer Seçenekler
- 12. Sigma ve Çekirdek Boyutu İlişkisi
- Örnek Sorular

## 1. Keskinleştirmenin Amacı ve Dersin Akışı

Bu derste görüntüyü keskinleştirme (image sharpening) ve bunun doğal devamı olan kenar bulma (edge detection) işlendi. Ders içeriği slaytlardan Jupyter Notebook'a aktarılmış biçimde anlatıldı; böylece konu ve kod iç içe gösterildi. Haftalık programdaki başlıklar şunlardı: uzamsal süzgeçlerle keskinleştirme, görüntünün birinci türevi (gradyan işlemi) ve ikinci türevi (Laplace operatörü). Hoca bu operatörlerin matematiğini göstermenin önemli olduğunu, bunun için önce bir boyutlu işaret üzerinde nasıl çalıştıklarının anlaşılması gerektiğini söyledi.

Defterin giriş hücresinde keskinleştirmenin temel amacı "parlaklıktaki geçişleri öne çıkarmak" olarak tanımlanır. Önceki derste bulanıklaştırmanın bir komşuluktaki piksellerin ortalamasıyla yapıldığı görülmüştü. Ortalama alma integrale benzer; bu yüzden keskinleştirmenin onun tersi olan uzamsal türevle (differentiation) yapılabileceği sonucuna varılır (ekrandan, 00:20:00).

## 2. Bir Boyutlu İşarette Birinci ve İkinci Türev

### 2.1 Örnek işaret

Ekrandaki grafikte dikey eksen parlaklığı (intensity), yatay eksen arka arkaya gelen pikselleri gösterir; yatay ekseni zaman gibi de düşünmek mümkündür. Tarama satırı (scan line) şu değerlerden oluşur (ekrandan, 00:25:00):

```text
Tarama satırı : 6 6 6 6 5 4 3 2 1 1 1 1 1 1 6 6 6 6 6
1. türev      :   0 0 -1 -1 -1 -1 -1 0 0 0 0 0 5 0 0 0 0
2. türev      :   0 0 -1 0 0 0 0 1 0 0 0 0 5 -5 0 0 0
```

İşaretin parçaları şöyledir:

- İlk dört gözde sabit parlaklık (constant intensity), değeri 6.
- Sonra bir parlaklık geçişi (intensity transition): değer 5, 4, 3, 2, 1 diye yavaşça iner. Bu yavaş eğimli inişe rampa (ramp) denir.
- Sonra yine sabit bir bölge (değer 1).
- En sonda keskin bir geçiş, yani basamak (step): parlaklık tek adımda 1'den 6'ya çıkar.

Hoca bu tür bir işaretin görüntüde ne anlama geldiğini de açıkladı: 3 bitle kodlanmış bir görüntüde değerler 0-7 arasındadır, 7 beyazdır ve 6 beyaza en yakın tondur. Değerin 6'dan 1'e kademeli inmesi, beyazdan siyaha kademeli bir geçiş, yani bir kenar demektir.

### 2.2 Birinci türev

Türev fark almak demektir. Bir boyutlu işarette birinci türev, sağdaki gözün değerinden bulunduğumuz gözün değerini çıkarıp sonucu o gözün altına yazmaktır:

$$\frac{\partial f}{\partial x} = f(x+1) - f(x)$$

Sabit bölgede $6-6=0$ çıkar. Rampanın başladığı yerde $5-6=-1$ olur ve rampa boyunca her adımda $-1$ elde edilir. Sabit bölgede yine $0$, basamakta ise $6-1=5$ bulunur. Python ile yapılan kontrol ekrandaki diziyle aynı sonucu verdi.

### 2.3 İkinci türev

İkinci türev, birinci türev dizisine aynı fark işleminin bir kez daha uygulanmasıdır:

$$\frac{\partial^2 f}{\partial x^2} = f(x+1) + f(x-1) - 2f(x)$$

Bu işlem rampanın başladığı yerde $-1$, bittiği yerde $1$ verir. Rampa boyunca birinci türev hep $-1$ olduğu için farkı $0$ olur. Basamakta önce $5$, hemen ardından $-5$ çıkar.

### 2.4 Türevlerin özellikleri

Defterde iki türevin özellikleri karşılaştırmalı verilir:

- Birinci türev:
  - Sabit parlaklıklı bölgede sıfır olmalıdır.
  - Basamağın ya da rampanın başında sıfırdan farklı olmalıdır.
  - Rampa boyunca sıfırdan farklı olmalıdır.
- İkinci türev:
  - Sabit bölgelerde sıfır olmalıdır.
  - Basamağın ya da rampanın başında ve sonunda sıfırdan farklı olmalıdır.
  - Sabit eğimli rampa boyunca sıfır olmalıdır.

Sabit eğim, rampadaki ardışık farkların hep birbirine eşit olması demektir. İkinci türevin en önemli özelliği, kenarın ya da değişimin başladığı ve bittiği noktada sıfırdan farklı sonuç vermesidir. Basamakta $5$'ten $-5$'e geçişte işaret değiştirir; bu, grafikte "zero crossing" (sıfır geçişi) olarak işaretlenmiştir (ekrandan, 00:25:00).

### 2.5 Sayısal görüntülerdeki kenarlar

Sayısal görüntülerdeki kenarlar çoğunlukla rampa biçimindeki geçişlerdir; tek bir keskin adım biçiminde olmazlar. Bu yüzden birinci türev kalın bir kenar çizgisi üretir. İkinci türev ise değişimin başladığı ve bittiği yerlerde, araları sıfırlarla ayrılmış bir çift kenar (double edge) oluşturur. Biri değişimin başladığı, öbürü bittiği bölgeyi gösterir. Bu nedenle keskinleştirme işleminde ikinci türev daha elverişlidir ve bir sonraki konu ikinci türevin kullanılmasıdır.

## 3. Laplace Operatörü ve Maskelerin Türetilmesi

### 3.1 Kavramlar

Birinci türev işlemine gradyan operatörü (gradient operator), ikinci türev işlemine Laplace operatörü (Laplacian operator) denir. Hedef, ikinci türevden bir süzgeç üretmektir. Defterde bu süzgecin izotropik olduğu belirtilir: izotropik süzgeçler dönmeden bağımsızdır, yani görüntüyü döndürüp süzgeci uygulamak ile süzgeci uygulayıp sonucu döndürmek aynı sonucu verir. İki değişkenli bir $f(x,y)$ fonksiyonu için en basit izotropik türev operatörü Laplace operatörüdür (ekrandan, 00:35:00):

$$\nabla^2 f = \frac{\partial^2 f}{\partial x^2} + \frac{\partial^2 f}{\partial y^2}$$

Görüntü iki boyutlu bir işaret olduğu için önce $x$ doğrultusunda, sonra $y$ doğrultusunda ikinci kısmi türev alınır ve ikisi toplanır. $\nabla^2$ sembolü (üzerinde 2 olan ters üçgen) Laplace operatörünü gösterir.

> **Hocanın vurgusu:** Bu matematik özellikle doktora öğrencileri için çok önemlidir. Yüksek lisans öğrencileri de artık bir şeyi ezbere kullanmak yerine nereden ve nasıl üretildiğini bilerek kullanmalıdır.

### 3.2 Tahtada türetme

Hoca türetmeyi tahtada gösterdi (ekrandan, 00:40:00). Yalnız $x$ doğrultusunda arka arkaya üç piksel düşünülür: $f(x-1)$, $f(x)$, $f(x+1)$. Birinci türev için iki fark yazılır:

$$f(x) - f(x-1) \qquad \text{ve} \qquad f(x+1) - f(x)$$

İkinci türev, sağdaki farktan soldaki farkın çıkarılmasıdır:

$$[f(x+1) - f(x)] - [f(x) - f(x-1)] = f(x+1) + f(x-1) - 2f(x)$$

Tahtada ilk yazımda bir işaret hatası oldu; bir öğrencinin düzeltmesiyle son terimin $+f(x-1)$ olduğu ve sonucun $f(x+1) - 2f(x) + f(x-1)$ olduğu netleşti.

Bu işlemde $y$ sabit tutulmuştur; aynı işlem $x$ sabit tutulup $y-1$, $y$, $y+1$ pikselleri üzerinden yapılınca $y$ doğrultusundaki ifade bulunur (ekrandan, 00:35:00):

$$\frac{\partial^2 f}{\partial x^2} = f(x+1,y) + f(x-1,y) - 2f(x,y)$$

$$\frac{\partial^2 f}{\partial y^2} = f(x,y+1) + f(x,y-1) - 2f(x,y)$$

İkisi toplanınca iki tane $-2f(x,y)$ terimi $-4f(x,y)$ olur:

$$\nabla^2 f(x,y) = f(x+1,y) + f(x-1,y) + f(x,y+1) + f(x,y-1) - 4f(x,y)$$

### 3.3 Maskeler

Bu ifade doğrudan bir filtre maskesidir: merkez pikselin katsayısı $-4$, solundaki ve sağındaki ($x-1$, $x+1$) piksellerin katsayısı $1$, üstündeki ve altındaki ($y-1$, $y+1$, yani kuzey-güney) piksellerin katsayısı $1$, köşelerin katsayısı $0$ olur.

Bu maske yalnız kuzey, güney, doğu ve batı yönlerine bakar. Ara yönler (kuzeydoğu, güneybatı gibi) de hesaba katılınca maske iyileştirilir: köşelere de $1$ yazılır ve merkez $-8$ olur. Merkez değer, katsayıların toplamı sıfır olacak biçimde seçilir. Defterdeki dört maske şunlardır (ekrandan, 00:45:00):

$$\begin{bmatrix} 0 & 1 & 0 \\ 1 & -4 & 1 \\ 0 & 1 & 0 \end{bmatrix} \quad \begin{bmatrix} 1 & 1 & 1 \\ 1 & -8 & 1 \\ 1 & 1 & 1 \end{bmatrix} \quad \begin{bmatrix} 0 & -1 & 0 \\ -1 & 4 & -1 \\ 0 & -1 & 0 \end{bmatrix} \quad \begin{bmatrix} -1 & -1 & -1 \\ -1 & 8 & -1 \\ -1 & -1 & -1 \end{bmatrix}$$

Alttaki iki maske, üsttekilerin katsayı işaretleri ters çevrilerek elde edilmiştir. Yaygın kullanım merkezi negatif olanlardır; iki biçim de kullanılabilir, yalnız hangisinin kullanıldığına dikkat edilmelidir. Dört maskenin katsayıları toplamı sıfırdır (Python ile kontrol edildi).

## 4. Laplace ile Görüntü Keskinleştirme

### 4.1 Formül

Laplace bir türev operatörü olduğu için görüntüdeki parlaklık süreksizliklerini öne çıkarır, yavaş değişen bölgeleri bastırır. Tek başına uygulandığında karanlık, özelliksiz bir arka plan üzerinde grimsi kenar çizgileri olan bir görüntü üretir. Keskinleştirme etkisi, Laplace görüntüsünün özgün görüntüye eklenmesiyle elde edilir (ekrandan, 00:50:00):

$$g(x,y) = f(x,y) + c\,[\nabla^2 f(x,y)]$$

Burada $f(x,y)$ giriş, $g(x,y)$ keskinleştirilmiş görüntüdür. Laplace maskesinin merkezi negatifse $c = -1$, pozitifse $c = 1$ alınır. Merkezi negatif maskede $-1$ ile çarpmanın amacı, kenar geçişlerinin pozitif yönde artırılmasıdır.

Yapılan şey şudur: Laplace çıktısı yalnız giriş görüntüsündeki kenar geçişlerini içerir. Bu çıktı belli bir katsayıyla ağırlıklandırılıp görüntüye eklenince görüntünün kendisi korunur, kenar geçişleri kuvvetlenir. Yani işlem, görüntüye yalnızca Laplace operatörünü uygulamak değildir; ikinci türev çıktısı giriş görüntüsüyle üst üste toplanarak keskinleştirilmiş görüntü üretilir.

### 4.2 Ay görüntüsü örneği

Örnekte ayın kuzey kutbunun bulanık bir görüntüsü kullanıldı. Defterdeki görüntüler şunlardır (ekrandan, 00:50:00):

- Ayın kuzey kutbunun bulanık görüntüsü.
- Ölçeklenmeden gösterilen Laplace çıktısı.
- Ölçeklenerek gösterilen Laplace çıktısı.
- Merkezi $-4$ olan Laplace maskesiyle keskinleştirilmiş görüntü.
- Merkezi $-8$ olan maskeyle keskinleştirilmiş görüntü.

İki keskinleştirilmiş görüntü karşılaştırıldığında, merkezi $-8$ olan maskenin sonucunda ayın yüzeyindeki çukurların, eski kabartma haritalardaki gibi daha belirgin hale geldiği görülür. Bu operatör keskinleştirmeyi kenar geçişlerinin olduğu noktalarda yapar.

**Soru:** Ölçekli ve ölçeksiz Laplace görüntüleri arasındaki fark nedir?
**Cevap:** Çıktı bir katsayıyla çarpılır; bu katsayı örneğin 1 ya da 5 seçilebilir. Ölçekleme, bu katsayının derecesini gösterir.

## 5. Keskinsizleştirme Maskesi ve Yüksek Artırımlı Süzgeç

### 5.1 Bir boyutlu işaretle sezgi

İkinci keskinleştirme yöntemi keskinsizleştirme maskesi (unsharp masking) ve yüksek artırımlı süzgeçtir (highboost filtering). Hoca, bu yapının işaret işleme üzerinden çok güzel açıklandığını ve dikkat edilmesi gerektiğini söyledi. Defterde dört grafik alt alta verilir (ekrandan, 00:55:00):

- Özgün işaret (original signal): yatay bir bölgeden eğimle yükselip yine yatay devam eden bir geçiş.
- Bulanık işaret (blurred signal): özgün işaret kesikli çizgiyle referans olarak gösterilir; bulanık işarette köşeler yumuşamıştır. Bulanıklaştırma, önceki derste görülen ortalama süzgeci gibi bir süzgeçle, özellikle süzgeç boyutu büyütülerek yapılır.
- Keskinsizleştirme maskesi (unsharp mask): özgün işaretten bulanık işaret çıkarılınca yalnız geçişlerdeki farklar kalır; geçişin altında küçük bir çukur, üstünde küçük bir tepe görülür.
- Keskinleştirilmiş işaret (sharpened signal): maske özgün işarete eklenince geçişin başında aşağı, sonunda yukarı bir taşma oluşur.

### 5.2 İşlem adımları

1. Özgün görüntüyü bulanıklaştır.
2. Bulanık görüntüyü özgün görüntüden çıkararak maskeyi elde et.
3. Maskeyi bir $k$ katsayısıyla çarpıp özgün görüntüye ekle.

$\bar f(x,y)$ bulanık görüntüyü göstermek üzere:

$$g_{mask}(x,y) = f(x,y) - \bar f(x,y)$$

$$g(x,y) = f(x,y) + k \cdot g_{mask}(x,y)$$

<!-- BELİRSİZ: Formüller altyazıdaki sözlü anlatımdan (00:53:46) yazıldı; bu formüllerin gösterildiği anın karesi yok. -->

$k$ katsayısının etkisi:

- $k = 1$: keskinsizleştirme maskesi (unsharp masking).
- $k > 1$: yüksek artırımlı süzgeç (highboost filtering).
- $k < 1$: maskenin katkısı azaltılır (de-emphasize); kenar kuvvetlendirilmez.

Hoca son grafiğin keskinleştirmeyi çok iyi anlattığını söyledi: keskinleştirme, kenar geçişinde bir sıçrama yapıp sonra normale dönen bir etki oluşturarak vurguyu artırmaktır.

## 6. Gradyan Operatörü

### 6.1 Tanım

İkinci türevden bir maske üretip keskinleştirme yapıldıktan sonra birinci türeve, yani gradyan operatörüne geçildi. Laplace sembolünden farkı, $\nabla$'nın üzerinde kare olmamasıdır. $f(x,y)$'nin gradyanı iki boyutlu bir sütun vektörüdür (ekrandan, 01:15:00):

$$\nabla f \equiv \text{grad}(f) = \begin{bmatrix} g_x \\ g_y \end{bmatrix} = \begin{bmatrix} \dfrac{\partial f}{\partial x} \\[2mm] \dfrac{\partial f}{\partial y} \end{bmatrix}$$

### 6.2 Büyüklük ve yön

Vektörün büyüklüğü (uzunluğu) $M(x,y)$, yönü $\alpha(x,y)$ açısıyla verilir:

$$M(x,y) = \text{mag}(\nabla f) = \sqrt{g_x^2 + g_y^2}$$

$$\alpha(x,y) = \tan^{-1}\left(\frac{g_y}{g_x}\right)$$

Açı, $y$'ye göre kısmi türevin $x$'e göre kısmi türeve oranından bulunur ve değişimin yönü hakkında bilgi verir. Bazı uygulamalarda bu açıya ihtiyaç duyulur.

> **Hocanın vurgusu:** Türev operatörünün büyüklüğünün ve gradyan vektörünün açısının nasıl hesaplandığının bilinmesi beklenir.

> **Ders sonrası not:** Hoca açının yüzey normaliyle arasındaki açıyı gösterdiğini söyledi. Ekrandaki tanıma göre $\alpha(x,y)$ gradyan vektörünün yönüdür ve büyük olasılıkla $x$ eksenine göre ölçülür; kenarın kendisi gradyan yönüne diktir.

### 6.3 Bir boyutlu gradyan maskesi

Bir boyutlu türev, $y$ doğrultusunda alttaki pikselden üsttekini ya da $x$ doğrultusunda sağdaki pikselden soldakini çıkaran iki elemanlı maskelerle ifade edilebilir. Ama genelde $3\times 3$ süzgeç kullanılmak istenir; bu yüzden gradyan için $3\times 3$ maskelerin nasıl kurulduğuna bakıldı.

## 7. Roberts, Prewitt ve Sobel Maskeleri

### 7.1 Roberts

Görüntünün $3\times 3$'lük bölgesindeki parlaklık değerleri $z_1, \dots, z_9$ ile gösterilir. Roberts çapraz gradyan operatörleri $2\times 2$ maskelerdir ve yatay ya da düşey değil, çapraz komşular arasında fark alır. Hoca, maskelerin $3\times 3$, $5\times 5$ gibi tek boyutlu olmasının tercih edildiğini, çünkü ancak böyle bir merkez noktası olduğunu hatırlattı; $2\times 2$ olduğu için Roberts pek tercih edilmez.

### 7.2 Prewitt

Prewitt operatörü $3\times 3$'tür ve $\pm 1$'lerden oluşur (ekrandan, 01:25:00):

$$\begin{bmatrix} -1 & -1 & -1 \\ 0 & 0 & 0 \\ 1 & 1 & 1 \end{bmatrix} \qquad \begin{bmatrix} -1 & 0 & 1 \\ -1 & 0 & 1 \\ -1 & 0 & 1 \end{bmatrix}$$

Hoca soldaki maskenin çalışmasını tahtada bir örnekle gösterdi (ekrandan, 01:20:00). Bir görüntünün üst bölgesi tamamen siyah (parlaklık 0), altı beyaz (parlaklık 255) olsun. Maske siyah-beyaz sınırına, ilk satırı siyah bölgede, son satırı beyaz bölgede kalacak biçimde oturtulursa:

$$(-1\times 0) + (-1\times 0) + (-1\times 0) + (1\times 255) + (1\times 255) + (1\times 255) = 3\times 255 = 765$$

Orta satır sıfırlardan oluştuğu için katkı vermez. Sonuç büyük bir değerdir; türev geçiş bölgelerinde bir tepe yakalar. Maske tamamen beyaz bir bölgeye oturtulursa $-1$'ler ile $+1$'ler birbirini götürür ve çıktı $0$ olur. Yani maske sabit parlaklıklı bölgede sıfır, geçişte çok büyük çıktı üretir. Bu yüzden bir eşik değeri (threshold) kullanılarak maske kolayca bir kenar bulucu olarak kullanılabilir.

Soldaki maske yatay doğrultudaki çizgileri (yukarıdan aşağıya parlaklık değişimini), sağdaki dikey doğrultudaki çizgileri (soldan sağa değişimi) bulur. Hoca dikey durumu da tahtada çizdi: sol bölge siyah (0), sağ bölge beyaz (255) olduğunda dikey yapıdaki maske geçişte yine $3\times 255$ gibi yüksek bir çıktı verir. Bir maskenin bulduğu bileşen $g_x$, öbürünün bulduğu $g_y$ olarak adlandırılır.

### 7.3 Sobel

Sobel maskesi Prewitt'ten tek bir farkla ayrılır: merkez piksele daha yakın olan kuzey-güney ya da doğu-batı komşularının katsayısı $2$ yapılır (ekrandan, 01:25:00):

$$\begin{bmatrix} -1 & -2 & -1 \\ 0 & 0 & 0 \\ 1 & 2 & 1 \end{bmatrix} \qquad \begin{bmatrix} -1 & 0 & 1 \\ -2 & 0 & 2 \\ -1 & 0 & 1 \end{bmatrix}$$

Ana yönlere ağırlık verdiği için Sobel daha etkili ve başarılı oldu. Hoca, basit bir eklemenin çalışmayı çok daha iyi hale getirdiğini ve bugün yalnız Sobel'in adının bilindiğini anlattı.

> **Ders sonrası not:** Hoca, Prewitt maskesinin önce yayımlandığını ve Sobel'in birkaç ay sonra bunu iyileştirdiğini anlattı. Bu tarih bilgisi altyazıdan doğrulanamaz; yaygın kaynaklara göre Sobel operatörü büyük olasılıkla 1968'de bir sunumla tanıtılmış, Prewitt'in çalışması ise 1970'te yayımlanmıştır.

Defterde ayrıca bütün maske katsayılarının toplamının sıfır olduğu, türev operatöründen beklenenin de bu olduğu yazar (ekrandan, 01:25:00).

> **Hocanın vurgusu:** Prewitt ve Sobel maskeleri sorulduğunda bu dersi alan ve bu konuda çalışan biri onları gözü kapalı yazabilmeli ve ne yaptıklarını açıklayabilmelidir: siyah-beyaz geçişinde nasıl tepki verdiklerini, sabit parlaklıklı bölgede nasıl çıktı ürettiklerini iyice sindirmiş olmalıdır.

## 8. Python'da Prewitt Çekirdekleriyle Kenar Bulma

Uygulamada `matplotlib.pyplot` ve scikit-image kullanıldı. Test görüntüleri arasındaki bir bina görüntüsü `skimage.io.imread` ile bir görüntü matrisine okundu ve `imshow` ile gösterildi; görüntü gri seviyeli olduğu için renk haritasının (colormap) gri olarak verilmesi gerekir.

Bu işlemler scikit-image içinde hazır olsa da adım adım nasıl çalıştığını görmek için çekirdekler elle yazıldı:

- Önce yatay çizgileri bulan çekirdek NumPy dizisi olarak tanımlandı.
- `scipy.ndimage.convolve` ile giriş görüntüsü ve çekirdek verilerek konvolüsyon uygulandı ve sonuç gösterildi.
- Aynı işlem dikey çekirdekle tekrarlandı.

<!-- BELİRSİZ: Kod hücresinin tam metni karelerde görünmüyor; altyazıda çekirdek katsayıları bozuk okunmuş. Çekirdeğin Prewitt katsayılarıyla (-1,-1,-1 / 0,0,0 / 1,1,1) tanımlandığı bağlamdan anlaşılıyor. -->

Bina görüntüsünün yüzeyinde tuğlalar, pencere kenarları ve duvar çizgileri vardır. Yatay çekirdeğin çıktısında pencerelerin yatay çizgileri ve duvarlardaki yatay bileşenler, dikey çekirdeğin çıktısında ise pencere ve duvarlardaki dikey çizgiler öne çıktı (ekrandan, 01:30:00). Ana yönlerdeki katsayılar $2$ yapılarak (yani Sobel'e geçilerek) vurgunun arttığı ve daha etkili bir sonuç alındığı da gösterildi.

> **Hocanın vurgusu:** Kodda `convolve` yazmak sonucu verir, ama işin arkasında bir matematik vardır. Yazılı bir sınavda konvolüsyon işleminin elle yapılabilmesi gerekir.

Hoca, kullanılan süzgeçlerin simetrik olduğu için konvolüsyon ile korelasyon arasında burada büyük bir fark olmadığını, ikisinin farkının önceki derste konuşulduğunu hatırlattı.

## 9. LoG Süzgeci (Marr-Hildreth Kenar Bulucu)

### 9.1 Mantık

LoG, Laplacian of Gaussian'ın kısaltmasıdır ve Marr ile Hildreth tarafından geliştirilmiş bir kenar bulucudur. Defterde dayandığı iki gözlem verilir (ekrandan, 01:35:00):

1. Parlaklık değişimleri görüntünün ölçeğinden bağımsız değildir; bu yüzden onları bulmak farklı boyutlarda operatörler gerektirir.
2. Ani bir parlaklık değişimi birinci türevde bir tepe ya da çukur, buna denk olarak ikinci türevde bir sıfır geçişi oluşturur.

Görüntü farklı ölçeklerde olabileceği için kenar bulmadan önce genelde bir yumuşatma (smoothing), yani Gauss süzgeci uygulanır; arkasından birinci ya da ikinci türev alınır. Bu iki işlemi bütün görüntüye arka arkaya konvolüsyonla uygulamak yerine LoG şunu yapar: Gauss fonksiyonu matematiksel olarak bilindiği için önce onun ikinci türevi alınır; bu fonksiyondan süzgeç katsayıları üretilir ve görüntüye yalnız bir kez konvolüsyon uygulanır.

### 9.2 Türetme

İki boyutlu Gauss fonksiyonu, önündeki katsayı ihmal edilerek şöyle yazılır (ekrandan, 01:35:00):

$$G(x,y) = e^{-\frac{x^2+y^2}{2\sigma^2}}$$

Üç boyutta bir çan biçimi olarak düşünülebilir. Laplace'ı, $x$ ve $y$'ye göre ikinci kısmi türevlerin toplamıdır:

$$\nabla^2 G(x,y) = \frac{\partial^2 G(x,y)}{\partial x^2} + \frac{\partial^2 G(x,y)}{\partial y^2}$$

$x$'e göre kısmi türev alınırken $y$ sabit kabul edilir. Üsteki ifadenin $x$'e göre türevi $-2x/(2\sigma^2)$ olduğundan ikiler sadeleşir ve $-x/\sigma^2$ katsayısı öne gelir; $y$ için de aynısı geçerlidir:

$$\nabla^2 G(x,y) = \frac{\partial}{\partial x}\left(\frac{-x}{\sigma^2} e^{-\frac{x^2+y^2}{2\sigma^2}}\right) + \frac{\partial}{\partial y}\left(\frac{-y}{\sigma^2} e^{-\frac{x^2+y^2}{2\sigma^2}}\right)$$

Parantez içindeki ifadeler iki fonksiyonun çarpımıdır; ikinci türev için çarpımın türevi kuralı (birincinin türevi çarpı ikinci artı birinci çarpı ikincinin türevi) kullanılır:

$$\nabla^2 G(x,y) = \left(\frac{x^2}{\sigma^4} - \frac{1}{\sigma^2}\right) e^{-\frac{x^2+y^2}{2\sigma^2}} + \left(\frac{y^2}{\sigma^4} - \frac{1}{\sigma^2}\right) e^{-\frac{x^2+y^2}{2\sigma^2}}$$

Katsayılar düzenlenince (ara adım eklendi):

$$\nabla^2 G(x,y) = \left(\frac{x^2+y^2-2\sigma^2}{\sigma^4}\right) e^{-\frac{x^2+y^2}{2\sigma^2}}$$

Bu ifadeye Laplacian of a Gaussian (LoG) denir. Son biçim, sonlu farklarla hesaplanan Laplace ile Python'da sayısal olarak karşılaştırıldı ve uyumlu bulundu.

### 9.3 Meksika şapkası ve maske

Fonksiyonun $x$-$y$ düzleminden kesiti incelendiğinde, ortadaki tepenin çevresinde sıfırın altına inen bir halka (lob) vardır. Bu şekle Meksika şapkası (Mexican hat) denir. Defterdeki çizimde tepenin iki yanında sıfır geçişleri (zero crossing) işaretlenmiştir (ekrandan, 01:40:00).

Maske katsayılarının gri seviyeli görüntüsünde merkezdeki büyük katsayı beyaz, en küçük katsayılar siyah görünür. Ekrandaki $5\times 5$ örnek maske şudur (ekrandan, 01:40:00):

$$\begin{bmatrix} 0 & 0 & -1 & 0 & 0 \\ 0 & -1 & -2 & -1 & 0 \\ -1 & -2 & 16 & -2 & -1 \\ 0 & -1 & -2 & -1 & 0 \\ 0 & 0 & -1 & 0 & 0 \end{bmatrix}$$

<!-- BELİRSİZ: Maskenin son satırı karede kesik; simetriden 0 0 -1 0 0 olarak yazıldı. -->

Merkezde $16$ gibi büyük bir katsayı, en düşük değer olarak $-2$ vardır; katsayıların toplamı sıfırdır (Python ile kontrol edildi). Giriş görüntüsü LoG süzgeciyle konvolüsyona sokulup sıfır geçiş noktalarına bakılarak kenarlar bulunur; ikinci türevde sıfır geçiş noktaları kenarları temsil eder.

Hoca, ekrandaki şeklin formülden çizdirilmesini bir alıştırma olarak istedi (bkz. Örnek Sorular). Amaç, LoG süzgeci için gerekli katsayıları matematiksel denklemden üretebilmek ve Python'da bu işlemlere ısınmaktır.

## 10. Gradyan Büyüklüğü, Gauss Yumuşatma ve Sobel Uygulaması

### 10.1 Gradyan büyüklüğü

Kenar bulma defterinde gradyan tanımı tekrar edildi (ekrandan, 02:00:00): $x$ ve $y$ doğrultusundaki kısmi türevlerin kareleri toplamının karekökü büyüklüğü verir; bu büyüklük üzerinden yatay ve dikey doğrultudaki bütün kenarlar bulunabilir.

Örnekte kameraman görüntüsü önce pikselli (pixelated) hale getirildi: yatay ve dikey doğrultuda her 10 piksel bir pikselle temsil edilerek görüntü küçültüldü. Bu bozulmuş görüntüye önce yatay doğrultudaki çizgileri bulan Prewitt çekirdeği uygulandı; çıktıda beyaz bölgeler yatay çizgilerin olduğu yerleri gösterdi. Sonra dikey çekirdek uygulandı. Görüntünün gradyan büyüklüğü hesaplanırken iki doğrultudaki türev çıktılarının kareleri toplanıp karekökü alındı. Sonuçlar `subplot(1,2,1)` ve `subplot(1,2,2)` ile yan yana gösterildi: solda tek doğrultudaki türev, sağda gradyan büyüklüğü.

Gradyan büyüklüğünün kenar geçişlerinde tepe yapması, sabit parlaklıklı bölgelerde sıfır vermesi beklenir. Kameraman görüntüsünde dış kenarlar beyaz, sabit bölgeler siyah göründü; beyaz pikseller kenar pikselleridir.

### 10.2 Yumuşatma ön işlemi

Görüntüde çok gürültü varsa türev operatörleri gürültüyü de kenar olarak algılar; çıktıda kenar varmış gibi görünen bölgeler oluşur. Bu yüzden önce bir yumuşatma ön işlemi ile gürültüyü temizleyip sonra kenar bulmak daha doğru bir işlem sırasıdır. Defterdeki hücre (ekrandan, 02:05:00):

```python
from skimage import filters

sigma = 1
smooth = filters.gaussian(image, sigma)

gradient = filters.sobel(smooth)

# Scale smoothed gradient up so they're of comparable brightness.
plt.imshow(gradient*1.8, cmap='gray')
```

`filters.gaussian` Gauss maskesini hazırlayıp görüntüye uygular. Gauss süzgecinde $\sigma$ (standart sapma) önemli bir parametredir: $\sigma$ büyüdükçe daha geniş bir alanda ortalama alınır ve görüntü daha çok bulanıklaşır; küçükken bulanıklık azdır. Hoca $\sigma$'yı 2 yapıp hücreyi yeniden çalıştırdı; bulanıklık artınca kenar görüntüsünde daha kaba hatların kaldığı görüldü. `imshow` içinde gradyanın $1.8$ ile çarpılması yalnızca görüntüyü parlaklık açısından karşılaştırılabilir hale getiren bir ölçeklemedir.

Başka bir örnekte Sobel'in yalnız yatay bileşeni çizdirildi (büyük olasılıkla `sobel_h`; altyazıda "haş" diye geçiyor); bileşenler ayrı ayrı da kullanılabilir. scikit-image'ın kenar operatörleri arasında Roberts, Sobel ve Prewitt hazır bulunur; defterde Roberts ve Sobel kenar bulma sonuçları kameraman görüntüsünde yan yana gösterildi (ekrandan, 02:20:00). Farklı süzgeç türlerinin sonuçları denenerek karşılaştırılabilir.

## 11. Canny Kenar Bulucu ve Diğer Seçenekler

Hocaya göre kenar bulma algoritmaları içinde en başarılısı Canny kenar bulucudur. Küçük küçük parçalar yerine sürekli kenarlar ortaya çıkardığı için daha çok tercih edilir.

Defterdeki açıklamaya göre Canny çok aşamalı bir kenar bulucudur (ekrandan, 02:10:00):

- Gradyan şiddetini hesaplamak için Gauss'un türevine dayanan bir süzgeç kullanır; Gauss görüntüdeki gürültünün etkisini azaltır.
- Gradyan büyüklüğünde en büyük olmayan pikseller kaldırılarak olası kenarlar 1 piksel kalınlığında eğrilere inceltilir.
- Kenar pikselleri, gradyan büyüklüğü üzerinde histerezis eşiklemesiyle tutulur ya da atılır.
- Ayarlanabilir üç parametresi vardır: Gauss'un genişliği (görüntü ne kadar gürültülüyse genişlik o kadar büyük) ve histerezis eşiklemesinin alt ve üst eşikleri.

> **Ders sonrası not:** Hoca Canny'nin içinde LoG süzgeci kullandığını söyledi. Ekrandaki açıklamaya göre Canny, LoG değil, Gauss'un birinci türevine dayanan bir süzgeçle gradyan hesaplar.

Örnekte siyah arka plan üzerinde bir kare içeren sentetik, gürültülü bir görüntü (`np.zeros((128, 128))` ile başlayan) kullanıldı; arka planda gürültü olarak beyaz pikseller vardır. İçinde yumuşatma olmayan standart bir kenar bulucu bu gürültüleri kenar sayar ve kenar bulmayı zorlaştırır. Canny iki farklı $\sigma$ ile çalıştırıldı:

- $\sigma = 1$: Gauss penceresi dar olduğu için küçük bir bölgede ortalama alınır, gürültü yeterince temizlenmez ve arka planda küçük kenarlar çıkar.
- $\sigma = 3$: daha büyük bir pencerede ortalama alındığı için gürültü daha iyi bastırılır ve bulunan kenar görüntüsü gürültüden arınır.

Kenar bulmada kullanılabilecek diğer süzgeçler LoG (Laplacian of Gaussian) ve DoG'dur (Difference of Gaussian, Gauss farkı).

> **Ek bilgi (derste anlatılmadı):** DoG, farklı $\sigma$ değerli iki Gauss ile bulanıklaştırılmış görüntünün farkıdır ve LoG'a yakın bir yaklaşım verir. Bu yüzden LoG'a göre daha ucuz hesaplanabilen bir seçenek olarak kullanılır.

## 12. Sigma ve Çekirdek Boyutu İlişkisi

**Soru:** $3\times 3$ ya da $5\times 5$ çekirdek kullanılıyordu. Çekirdek boyutu yalnız görüntünün boyutuyla mı ilgili, yoksa hesaplamada başka şeyleri de etkiliyor mu? Denendiğinde çok değişim görülmedi.

**Cevap:** Kenar bulmada Prewitt ve Sobel süzgeçleri hep $3\times 3$'tür; yalnız dikey ve yatay doğrultuda pikseller arasında fark aldıkları için boyutları değiştirilmez. Gauss süzgecinde ise çekirdeğin boyutu, Gauss fonksiyonunun standart sapmasına göre büyümelidir; bu yüzden $5\times 5$, $7\times 7$, $9\times 9$ gibi farklı boyutlar kullanılır.

Hoca bunu tahtada aynı ortalamalı iki Gauss eğrisiyle açıkladı (ekrandan, 02:15:00). Birinci eğrinin standart sapması küçük, ikincininki onun yaklaşık iki katı olsun. Birinci eğriden çekirdek kurarken birkaç noktadan örnek almak yeter; örneğin $5\times 5$ bir süzgeç onu temsil edebilir. İkinci eğri daha geniş olduğu için daha uzaktaki noktalardan da örnek almak gerekir; onu temsil etmek için belki $9\times 9$ bir çekirdek gerekir. Gauss dağılımının iyi modellenebilmesi için en az $\pm 2\sigma$ kadar örnek alınmalıdır.

$9\times 9$'luk çekirdek görüntü üzerinde $5\times 5$'likten daha büyük bir alanı örter ve daha geniş bir alandaki piksellerin ortalamasını alır. Bu yüzden $\sigma$ büyüdükçe:

- maskenin boyutu büyür,
- görüntüdeki bulanıklık artar,
- gürültü daha iyi bastırılır; gürültü azaltma (noise reduction) açısından daha başarılı olur.

> **Hocanın vurgusu:** Herkes Python'da hazır kodları bir araya getirerek bu işleri yapabilir. Ama arkadaki matematiği iyi bilmek ve neyin niçin yapıldığının farkında olmak gerekir; yalnız hazır çerçeveleri kullanmak yetmez.

## Örnek Sorular

### Soru 1: Tarama satırının türevleri

(ekrandan, 00:25:00) `6 6 6 6 5 4 3 2 1 1 1 1 1 1 6 6 6 6 6` tarama satırının birinci ve ikinci türevini hesaplayın ve iki türevin sabit bölge, rampa ve basamakta nasıl davrandığını yorumlayın.

> **Çözüm (derste verildi):** $f(x+1)-f(x)$ ile birinci türev `0 0 -1 -1 -1 -1 -1 0 0 0 0 0 5 0 0 0 0`, $f(x+1)+f(x-1)-2f(x)$ ile ikinci türev `0 0 -1 0 0 0 0 1 0 0 0 0 5 -5 0 0 0` bulunur. Sabit bölgede ikisi de sıfırdır. Rampa boyunca birinci türev $-1$, ikinci türev $0$'dır; ikinci türev yalnız rampanın başında ($-1$) ve sonunda ($1$) sıfırdan farklıdır. Basamakta birinci türev $5$, ikinci türev $5$ ve $-5$ verir; aradaki işaret değişimi sıfır geçişidir. Değerler Python ile doğrulandı.

### Soru 2: Laplace maskesini türetin

(derste sözlü ve tahtada, 00:38:24) Üç ardışık piksel $f(x-1)$, $f(x)$, $f(x+1)$ üzerinden ikinci türevin ayrık ifadesini çıkarın ve $3\times 3$ Laplace maskesini elde edin.

> **Çözüm (derste verildi):** $[f(x+1)-f(x)] - [f(x)-f(x-1)] = f(x+1)+f(x-1)-2f(x)$. $y$ doğrultusundaki benzer ifadeyle toplanınca $\nabla^2 f = f(x+1,y)+f(x-1,y)+f(x,y+1)+f(x,y-1)-4f(x,y)$ bulunur. Maske: merkez $-4$, dört ana komşu $1$, köşeler $0$. Çapraz komşular da katılırsa merkez $-8$, bütün komşular $1$ olur.

### Soru 3: Prewitt maskesinin siyah-beyaz sınırındaki çıktısı

(ekrandan, 01:20:00) Üstü siyah (0), altı beyaz (255) olan bir görüntüde $[-1,-1,-1; 0,0,0; 1,1,1]$ maskesi, ilk satırı siyah bölgede, son satırı beyaz bölgede kalacak biçimde oturtuluyor. Çıktı nedir? Maske tamamen beyaz bir bölgeye oturtulursa çıktı ne olur?

> **Çözüm (derste verildi):** $(-1\times 0)\cdot 3 + (0)\cdot 3 + (1\times 255)\cdot 3 = 765$. Tamamen beyaz bölgede $-3\times 255 + 3\times 255 = 0$. Geçişte büyük, sabit bölgede sıfır çıktı verdiği için eşikleme ile kenar bulucu olarak kullanılabilir. Değerler Python ile doğrulandı.

### Soru 4: LoG fonksiyonunu çizdirme

(derste sözlü, 01:39:30) Gauss fonksiyonunun ikinci türevi olan $\nabla^2 G$ ifadesini kullanarak, `meshgrid` ile ekrandaki Meksika şapkası şeklini çizdirin. Çizim ilk anda ters (tepesi aşağı) çıkacaktır; bütün ifadeyi $-1$ ile çarparak tepesi yukarı bakan biçime getirin.

> **Çözüm (derste verilmedi):** Aşağıdaki kod ders sonrasında hazırlandı. Sayısal kısmı Python ile çalıştırıldı: $\sigma=1$ için şapkanın tepesi merkezde $2$, en derin noktası merkezden $2\sigma$ uzaklıkta yaklaşık $-0.27$ çıktı; formül sonlu farklarla hesaplanan Laplace ile de uyumlu bulundu. Çizim satırları ortamda matplotlib olmadığı için çalıştırılmadı.

```python
import numpy as np
import matplotlib.pyplot as plt

sigma = 1.0
x = np.linspace(-4, 4, 81)
y = np.linspace(-4, 4, 81)
X, Y = np.meshgrid(x, y)
R2 = X**2 + Y**2

LoG = (R2 - 2*sigma**2) / sigma**4 * np.exp(-R2 / (2*sigma**2))
mexican_hat = -LoG          # tepe yukarı baksın diye -1 ile çarp

fig = plt.figure(figsize=(10, 4))
ax = fig.add_subplot(1, 2, 1, projection="3d")
ax.plot_surface(X, Y, mexican_hat, cmap="gray")
ax2 = fig.add_subplot(1, 2, 2)
ax2.imshow(mexican_hat, cmap="gray")
plt.show()
```

### Soru 5: Gauss çekirdeğinin boyutu

(derste sözlü, 02:13:31) $3\times 3$ ya da $5\times 5$ çekirdek seçimi neye bağlıdır?

> **Çözüm (derste verildi):** Prewitt ve Sobel her zaman $3\times 3$'tür. Gauss çekirdeğinin boyutu $\sigma$ ile birlikte büyümelidir; Gauss'u iyi örneklemek için en az $\pm 2\sigma$ aralığı kapsanmalıdır. Büyük çekirdek daha geniş alanda ortalama alır, bulanıklığı artırır ve gürültüyü daha iyi bastırır.

## Dersin Toparlaması

Bu derste keskinleştirmenin, bulanıklaştırmanın tersi olarak türev üzerine kurulduğu görüldü. Bir boyutlu bir işaret üzerinden birinci türevin değişim boyunca, ikinci türevin ise değişimin başında ve sonunda tepki verdiği gösterildi; ikinci türevin ayrık ifadesinden Laplace maskeleri türetildi. Laplace çıktısını görüntüye ekleyerek ve keskinsizleştirme maskesi ile yüksek artırımlı süzgeç kullanarak keskinleştirme yapıldı. Ardından birinci türev, yani gradyan; büyüklüğü, yönü ve Roberts, Prewitt, Sobel maskeleri anlatıldı ve Python'da bina ile kameraman görüntülerine uygulandı.

Dersin son bölümü kenar bulmaya ayrıldı: gürültünün kenar sanılmasını önlemek için Gauss ile yumuşatma, iki işlemi tek maskede birleştiren LoG (Marr-Hildreth) süzgeci ve en başarılı kenar bulucu olarak Canny ele alındı. Gauss'un $\sigma$ parametresinin bulanıklığı, gürültü bastırmayı ve çekirdek boyutunu nasıl belirlediği açıklandı. Hoca, hazır kütüphane fonksiyonlarını kullanmanın yanında bu işlemlerin arkasındaki matematiği bilmenin önemini vurguladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
