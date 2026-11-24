# Ders 3 Genişletilmiş Notu: Görüntü Anlama, Yoğunluk Dönüşümleri, Histogram Eşitleme ve Uzamsal Filtreleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çalışma Biçimi ve Konu Başlıkları
- 2. Python ile Görüntü Okuma ve Matris İşlemleri
- 3. İşlenen Görüntüyü Kaydetme ve JPEG Kalite Faktörü
- 4. Renk Kanalları ve Gri Seviyeye Dönüşüm
- 5. Yoğunluk Dönüşümleri ve Gama Düzeltmesi
- 6. Görüntü Histogramı
- 7. Histogram Eşitleme
- 8. Griden Renkliye Dönüş Sorusu
- 9. Eşikleme
- 10. Uzamsal Filtrelemenin Temelleri
- 11. Ortalama Filtreleri, Korelasyon ve Konvolüsyon
- 12. Python'da Ortalama Filtresi
- 13. Gauss Fonksiyonu ve Gauss Filtresi
- 14. Medyan Filtresi ve Tuz-Biber Gürültüsü
- 15. Örnek Sorular

## 1. Dersin Çalışma Biçimi ve Konu Başlıkları

Bu derste konular hem PowerPoint slaytları hem de Jupyter Notebook üzerinden, ikisi arasında geçiş yapılarak işlendi. Hoca, kodların slaytlarda da bulunduğunu, öğrencilerden ders sırasında kendi Jupyter ekranlarını açıp aynı işlemleri paralel olarak denemelerini beklediğini söyledi. Örnekler için derse ait test görüntüleri (rose.tif, balloon.jpg, mm.jpg, washedPolen.tif, coins.png gibi) kullanıldı.

Dersin konu başlıkları: görüntü anlama (image understanding), yoğunluk dönüşümleri (intensity transformation), uzamsal filtreleme (spatial filtering) ve gürültü azaltma (noise reduction).

> **Hocanın vurgusu:** Bu derste uygulamalı ilerlemek çok önemlidir. İşlemler şimdi kolay görünebilir, ama ileriki konularda bu alıştırmaların farkı ortaya çıkar.

## 2. Python ile Görüntü Okuma ve Matris İşlemleri

### 2.1 Görüntüyü okuma ve gösterme

Bir görüntü bir matristir ve matrisin `(0,0)` gözü görüntünün sol üst köşesidir. Python'da görüntüyü okumak için OpenCV de kullanılabilir, ancak derste scikit-image (`skimage`) ve Matplotlib kütüphaneleri kullanıldı. `skimage.io` modülündeki `imread` görüntüyü bir NumPy matrisine okur, `matplotlib.pyplot.imshow` ise ekrana getirir. Ekrana gelen görüntünün kenarlarında satır ve sütun koordinatları (ör. 0-300, 0-250) görünür; sol üst köşe sıfırdır.

Okunan matrisle ilgili temel bilgiler şöyle alınır:

- `image.dtype`: matristeki sayıların türü (tamsayı, ondalıklı).
- `image.shape`: matrisin boyutu.
- `image.min()`, `image.max()`: görüntüdeki en küçük ve en büyük parlaklık değeri.

Örnekte kullanılan rose.tif dosyası TIF biçimindedir. TIF de bir görüntü dosyası biçimidir ve sıkıştırılabilir bir yapıya sahiptir.

### 2.2 Dilimleme ile küçültme, ters çevirme ve kırpma

Ekrandaki kod (ekrandan, 00:15:00):

```python
image2 = io.imread('../New/rose.tif')
print(image2.shape)
plt.imshow(image2, cmap='gray');
image_small = image2[ : : 2,  : : 2 ]

print(image_small.shape)
#
# Write a code to flip the image matrix
Fliped = image2[-1:0:-1, -1:0:-1]
plt.imshow(Fliped, cmap='gray')
```

- **Yarıya küçültme:** `image2[::2, ::2]` bütün satır ve sütunlarda birer birer değil ikişer ikişer ilerler, böylece görüntü yarı yarıya küçülür. Hoca bunun gerçek bir küçültme yöntemi olmadığını, yalnız dilimleme (slicing) alıştırması olduğunu belirtti.
- **Ters çevirme (flip):** son satırdan ilk satıra ve son sütundan ilk sütuna $-1$ adımla gidilerek görüntü ters çevrilir.
- **Kırpma (crop):** 1024x1024 boyutlu görüntüde örneğin 330. satırdan 760. satıra kadar olan bölge alınarak bir bölüm kesilir. Hoca bu sınırların sabit sayı yerine parametrik verilebileceğini de söyledi: satır ve sütun sayısı bilindiği için örneğin boyutun yüzde 30'undan yüzde 60'ına kadar alınabilir.

### 2.3 Hazır yeniden boyutlandırma fonksiyonları

Küçültme için dilimleme yerine scikit-image'teki `rescale` ya da `resize` gibi hazır fonksiyonları kullanmak daha doğrudur. Örnekte görüntü 0.5 ölçek faktörüyle `rescale` edildi ve 1024x1024 boyutlu görüntüden 512x512 boyutlu `image_small` elde edildi.

## 3. İşlenen Görüntüyü Kaydetme ve JPEG Kalite Faktörü

Görüntü `io.imsave` ile diske yazılır. Notebook'taki açıklamaya göre `quality` 0 ile 100 arasında bir tamsayıdır; değer düştükçe JPEG sıkıştırmasından kaynaklanan bozulma artar (ekrandan, 00:20:00). Ekrandaki kod:

```python
%matplotlib inline
from matplotlib import pyplot as plt
from skimage import io

d="TestImages"
image = io.imread(d + "/balloon.jpg")
print(type(image))
plt.imshow(image);
io.imsave('yeni.jpg',image)
io.imsave('yeni20.jpg',image, quality=20)
io.imsave('yeni80.jpg',image, quality=80)
```

JPEG kayıplı bir sıkıştırma biçimidir. Kalite faktörü 100'e yaklaştıkça görüntü kaliteli, 0'a yaklaştıkça kalitesiz olur. Derste elde edilen dosya boyutları:

| Dosya | Kalite | Diskteki boyut |
|---|---|---|
| Özgün balloon.jpg | - | yaklaşık 20 KB |
| yeni.jpg | belirtilmedi | 13 KB |
| yeni20.jpg | 20 | 6 KB |
| yeni80.jpg | 80 | 16 KB |

Kalite 20 ile kaydedilen görüntü belirgin biçimde kötüleşir; kalite 80 ile kaydedilenle karşılaştırıldığında farkı özellikle balonun mavi renk geçişlerinde görülür. Kalite hiç belirtilmediğinde de dosya özgününden küçük çıkar; demek ki fonksiyon kabul edilebilir bir oranda varsayılan bir sıkıştırma uygular. Hoca bu varsayılan değerin 0.75 civarı olabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** scikit-image JPEG yazarken büyük olasılıkla arka planda Pillow kütüphanesini kullanır; Pillow'un varsayılan JPEG kalitesi 75'tir. Bu, kalite belirtilmeyen dosyanın (13 KB) kalite 80 olan dosyadan (16 KB) biraz küçük çıkmasıyla tutarlıdır.

## 4. Renk Kanalları ve Gri Seviyeye Dönüşüm

### 4.1 RGB kanallarını ayrı ayrı gösterme

Renkli görüntü diskte üç boyutlu bir matris olarak tutulur. Örnekte renkli şeker drajelerinden oluşan mm.jpg görüntüsü kullanıldı (ekrandan, 00:25:00):

```python
image = io.imread('TestImages/mm.jpg')

r = image[:,:,0]
g = image[:,:,1]
b = image[:,:,2]
plt.subplot(1, 4, 1)
plt.imshow(r, cmap='gray')

plt.subplot(1, 4, 2)
plt.imshow(g, cmap='gray')

plt.subplot(1, 4, 3)
plt.imshow(b, cmap='gray')

plt.subplot(1, 4, 4)
plt.imshow(image)
```

Bütün satırlar ve bütün sütunlar alınıp yalnız üçüncü boyutta (renk paleti boyutu) 0, 1 ve 2 seçilerek kırmızı, yeşil ve mavi kanallar ayrı iki boyutlu matrislere alınır ve dördü yan yana gösterilir.

**Soru (hocanın sorusu):** Kırmızı kanalın gri seviyeli gösteriminde hangi renkler beyaz çıkar?
**Cevap:** Kırmızılar. Kırmızı kanal, kırmızının en doygun olduğu yerlerde en büyük değeri, hiç kırmızı olmayan yerlerde sıfırı alır. Gri seviyede sıfır siyah, en büyük değer beyazdır. Ölçek 0-1 ise beyaz 1, ölçeklenmemişse beyaz 255'tir. Aynı mantıkla yeşil kanalda yeşil drajeler, mavi kanalda mavi drajeler beyaz görünür.

### 4.2 Gri seviyeye dönüşüm formülü

Renkli bir görüntüyü gri seviyeye çevirmek için farklı denklemler vardır, çünkü katsayılar kullanılan renk uzayına göre değişir. Sonuçta bir parlaklık (intensity) değeri $Y$ elde edilir ve bu değer gri seviyeli görüntünün parlaklığıdır. Derste kullanılan katsayılar (ekrandan, 00:30:00):

$$Y = 0.2126\,R + 0.7152\,G + 0.0722\,B$$

Ekrandaki kod (balloon.jpg üzerinde):

```python
r = image[:,:,0]
g = image[:,:,1]
b = image[:,:,2]

ImageGray1=0.2126*r+0.7152*g+0.0722*b
print(ImageGray1.shape)
plt.subplot(1, 2, 1)
plt.imshow(ImageGray1, cmap='gray')

from skimage.color import rgb2gray
ImageGray2=rgb2gray(image)
print(ImageGray2.min(), ImageGray2.max())

print(ImageGray2.shape)

plt.subplot(1, 2, 2)
plt.imshow(ImageGray2, cmap='gray')

diff=ImageGray1-ImageGray2
print(diff.min(), diff.max())
```

Çıktı: `(300, 225, 3)`, `(300, 225)`, `0.032243529411764706 1.0`, `(300, 225)`, `8.189556470588235 253.99999999999997` (ekrandan, 00:30:00).

Solda katsayılarla elle hesaplanan, sağda `rgb2gray` hazır fonksiyonuyla elde edilen gri görüntü gösterilir; `subplot(1, 2, k)` bir satır iki sütunluk çizim alanının k. gözünü seçer. Hoca iki görüntü arasında çok küçük bir fark bekliyordu, çünkü katsayılar yaklaşık aynı. Ancak fark matrisinin en büyük değeri 253.99 çıktı. Hoca sayıların ondalıklı çıkmasını katsayıların ondalıklı olmasına bağladı ve bunu "bazı piksellerde büyük fark var" diye yorumladı.

> **Ders sonrası not:** Ekrandaki çıktıda `rgb2gray` sonucunun en küçük değeri 0.032, en büyük değeri 1.0'dır; yani hazır fonksiyon görüntüyü 0-1 aralığına ölçekler. Elle hesaplanan `ImageGray1` ise 0-255 aralığında kalır. Farkın 8.19 ile 253.99 arasında çıkmasının asıl nedeni büyük olasılıkla bu ölçek farkıdır, piksellerin gerçekten farklı olması değil. Karşılaştırma için `ImageGray1/255` ile `ImageGray2` karşılaştırılmalıdır.

## 5. Yoğunluk Dönüşümleri ve Gama Düzeltmesi

### 5.1 Dönüşüm eğrileri

Görüntü üzerinde iyileştirme yapmanın bir yolu, bir fonksiyon yardımıyla parlaklık dönüşümü yapmaktır. Önce görüntüdeki sorun analiz edilir, sonra uygun dönüşüm eğrisi seçilir. Eğrilerde yatay eksen giriş parlaklığı (input intensity level, $r$), dikey eksen çıkış parlaklığıdır (output intensity level, $s$).

- **Birim doğru (identity):** girişe $L/2$ verildiğinde çıkış da $L/2$'dir; görüntü değişmez.
- **Ters köşegen:** görüntünün negatifini verir.
- **Birim doğrunun altındaki eğriler:** örneğin girişteki $L/2$ değeri çıkışta yaklaşık $L/4$'e taşınıyorsa, parlaklık sıfıra yaklaştırılıyor demektir; görüntü koyulaşır (darker image). Çok aydınlık görüntüler için kullanılır.
- **Birim doğrunun üstündeki eğriler:** görüntüyü aydınlatır; karanlık görüntüler için kullanılır.

### 5.2 Gama eğrileri

Bu dönüşümler gama eğrileri ile de yapılabilir. Ekrandaki grafikte $\gamma = 0.04,\ 0.10,\ 0.20,\ 0.40,\ 0.67,\ 1,\ 1.5,\ 2.5,\ 5.0,\ 10.0,\ 25.0$ için eğriler çizilidir; eksenler $0$, $L/4$, $L/2$, $3L/4$, $L-1$ ile işaretlenmiştir (ekrandan, 00:45:00).

- $\gamma > 1$ olan eğriler birim doğrunun altında kalır ve görüntüyü koyulaştırır.
- $\gamma < 1$ olan eğriler (0.20, 0.10 gibi) birim doğrunun üstünde kalır ve görüntüyü aydınlatır.
- $\gamma = 1$ birim doğrudur.

### 5.3 `adjust_gamma` fonksiyonu

scikit-image'te bu iş için `skimage.exposure.adjust_gamma` hazır fonksiyonu vardır. Derste washed.tif görüntüsü üzerinde kullanıldı (ekrandan, 00:45:00). Hoca fonksiyonun belgesini scikit-image sitesinde açarak parametreleri gösterdi: varsayılan olarak `gamma=1`, `gain=1`'dir. Fonksiyon "power law" dönüşümü yapar:

$$O = I^{\gamma}$$

Yani giriş görüntüsünün parlaklık değerinin $\gamma$ kuvveti alınır. Bunun için giriş parlaklıklarının önce 0-1 aralığına ölçeklenmiş olması gerekir. Belgede $\gamma = 2$ alınmış örnekler de vardır.

> **Ek bilgi (derste anlatılmadı):** 0-1 aralığındaki bir değerin 1'den büyük bir kuvveti kendisinden küçüktür (ör. $0.5^2 = 0.25$), 1'den küçük bir kuvveti ise kendisinden büyüktür (ör. $0.5^{0.5} \approx 0.71$). Bu yüzden normalize edilmiş görüntüde $\gamma > 1$ koyulaştırır, $\gamma < 1$ aydınlatır; giriş 0-1 aralığına ölçeklenmezse bu ilişki bozulur.

## 6. Görüntü Histogramı

### 6.1 Histogramın okunması

Histogramda yatay eksen görüntüdeki parlaklık değerlerini (0-255), dikey eksen ise bu değerlerin görüntüde bulunma sıklığını gösterir. Notebook'taki dört örnek görüntü ve histogramı (ekrandan, 00:50:00):

- **Karanlık görüntü (dark image):** dağılım 0-255 ölçeğinin sol tarafına yığılır. Sıfıra yakın parlaklıklar sık tekrarlanır, aydınlık değerler hiç yoktur.
- **Aydınlık görüntü (light image):** dağılım 255 tarafında toplanır. Örneğin bütün değerler 128 civarından başlayıp 255'e kadar uzanır, altı hiç yoktur. Işığın çok fazla olduğu, "patlamış" görüntüdür.
- **Düşük kontrastlı görüntü (low contrast):** görüntüde ne beyaz ne siyah vardır; uç parlaklık değerleri hiç yer almaz, görüntü yalnız dar bir aralıktaki gri tonlardan oluşur. Oldukça kötü bir görüntüdür.
- **Yüksek kontrastlı görüntü (high contrast):** bütün parlaklık değerleri az çok görüntüde yer alır; hem siyah hem beyaz belli miktarda bulunur. İdeal görüntüdür.

### 6.2 Python'da histogram

scikit-image'te `skimage.exposure.histogram` görüntüyü ve histogramın kaç aralığa (bin) bölüneceğini alır, histogram değerlerini ve aralık merkezlerini döndürür. Ekrandaki kod (ekrandan, 00:55:00):

```python
image = io.imread('TestImages/washedPolen.tif')

hist , histCenters = histogram(image)

fig, axes = plt.subplots(1, 2, figsize=(8, 3))

axes[0].imshow(image, cmap='gray')
axes[0].axis('off')

axes[1].plot(histCenters, hist)
axes[1].set_title('histogram of gray values')
```

Polen görüntüsünün parlaklık değerleri yaklaşık 90 ile 140 arasındadır; grafik de bu aralıkta çizilir. Grafikteki en yüksek tepe yaklaşık 60 000'dir: o parlaklık değeri (yaklaşık 98) görüntü matrisinde yaklaşık 60 bin kez tekrarlanmıştır. Bu dar aralık görüntünün düşük kontrastlı olduğunu gösterir.

## 7. Histogram Eşitleme

### 7.1 Amaç

Düşük kontrastlı görüntülerde histogramı eşitlemek görüntüyü daha ideal hale getirir. Histogram eşitleme (histogram equalization), dar bir aralıkta yığılmış parlaklık değerlerini bütün parlaklık değerlerine belli oranlarda yayar; bir anlamda mevcut ölçeği 0-255 aralığına açar.

> **Hocanın vurgusu:** Bu işlemler hazır fonksiyonlarla yapılıyor, ama arkada çalışan matematiği bilmek gerekir. Bilerek kullanırsak daha doğru kullanmış oluruz.

### 7.2 Adım adım örnek

Slayttaki tablo (Gonzalez kitabı, Tablo 3.1): 3 bitlik, 64x64 boyutlu bir görüntünün yoğunluk dağılımı (ekrandan, 01:05:00). Hoca hesabı tablet üzerinde tablonun yanına yazarak yaptı (ekrandan, 01:10:00).

**Verilen:** Parlaklık değerleri $r_k$ 0 ile 7 arasındadır ve her değerin tekrar sayısı $n_k$ tabloda verilmiştir.

**Soru (hocanın sorusu):** Değerler 0-7 arasındaysa bir piksel kaç bitle kodlanmıştır?
**Cevap:** 3 bit; 8 farklı değer alabilir.

**Adım 1, olasılıklar:** Her değerin tekrar sayısı toplam piksel sayısına bölünür: $p_r(r_k) = n_k / MN$.

**Soru (hocanın sorusu):** Toplam piksel sayısını nereden buluruz?
**Cevap:** İki yoldan: $n_k$ sütunundaki değerlerin toplamından ya da görüntü matrisinin satır sayısı ile sütun sayısının çarpımından ($M \times N$). Burada $790 + 1023 + \dots + 81 = 4096 = 64 \times 64$'tür (ara adım eklendi).

**Adım 2, birikimli toplam:** Olasılıkların birikimli toplamı alınır: $\sum_{j=0}^{k} p_r(r_j)$.

**Adım 3, ölçeğe taşıma:** Birikimli toplam, görüntünün alabileceği en büyük değerle ($L - 1 = 7$) çarpılır.

**Adım 4, yuvarlama:** Parlaklık tamsayı olmalıdır; sonuç en yakın tamsayıya yuvarlanır.

| $r_k$ | $n_k$ | $p_r(r_k)$ | Birikimli toplam | $\times 7$ | Yeni değer $s_k$ |
|---|---|---|---|---|---|
| 0 | 790 | 0.19 | 0.19 | 1.33 | 1 |
| 1 | 1023 | 0.25 | 0.44 | 3.08 | 3 |
| 2 | 850 | 0.21 | 0.65 | 4.55 | 5 |
| 3 | 656 | 0.16 | 0.81 | 5.67 | 6 |
| 4 | 329 | 0.08 | 0.89 | 6.23 | 6 |
| 5 | 245 | 0.06 | 0.95 | 6.65 | 7 |
| 6 | 122 | 0.03 | 0.98 | 6.86 | 7 |
| 7 | 81 | 0.02 | 1.00 | 7.00 | 7 |

Değerler python ile kontrol edildi. (Altyazıda 3.08 değeri "0.8" olarak geçiyor; tabletteki yazı 3.08'dir.)

**Yorum:** İlk iki parlaklık değeri görüntünün yüzde 44'ünü, ilk üçü (0, 1, 2, yani siyaha en yakın değerler) yüzde 65'ini oluşturur. Bu yüzden bu görüntü oldukça karanlıktır.

**Sonuç:** Son sütun çıkış görüntüsünün parlaklık değerleridir. Girişteki bütün 0 değerli pikseller 1, bütün 1'ler 3, 2'ler 5, 3 ve 4'ler 6, 5, 6 ve 7'ler 7 yapılır.

**Soru (hocanın sorusu):** Girişteki 5 parlaklık değeri çıkışta kaç olur?
**Cevap:** Bir öğrenci önce 6 dedi; hoca tabloda en alttan üç satır sayılınca değerin 7 olduğunu gösterdi.

**Soru (hocanın sorusu):** 3 parlaklık değeri kaça dönüşür?
**Cevap:** 6. (Satırların sıfırdan başladığına dikkat edilmeli.)

**Soru (hocanın sorusu):** Giriş 0-7 aralığında, ama çıkış görüntüsü 4 bit/piksel olacaksa ne değişir?
**Cevap:** Birikimli toplam 7 yerine 15 ($2^4 - 1$) ile çarpılır.

### 7.3 Python'da histogram eşitleme

Hazır fonksiyon `skimage.exposure.equalize_hist`'tir (ekrandan, 01:25:00):

```python
import matplotlib.pyplot as plt
from skimage.exposure import histogram , equalize_hist

image = io.imread('TestImages/washedPolen.tif')

# Global equalize
img_rescale = exposure.equalize_hist(image)
hist , histCenters = histogram(img_rescale)

fig, axes = plt.subplots(1, 2, figsize=(8, 3))

axes[0].imshow(img_rescale, cmap='gray')
axes[0].axis('off')

axes[1].plot(histCenters, hist)
axes[1].set_title('histogram of gray values')
```

Eşitleme sonrası histogram 0-255 yerine 0-1 aralığına normalize edilmiş olarak gösterilir. Önemli olan, yeni görüntüde artık tam siyahın da tam beyazın da belli miktarlarda bulunmasıdır. Histogram bir anlamda gerilmiş (stretch edilmiş) ve daha ideal bir görüntü elde edilmiştir.

## 8. Griden Renkliye Dönüş Sorusu

**Soru (bir öğrenci):** RGB kanallarını katsayılarla çarpıp gri görüntü elde ettik. Bu gri görüntüyü tekrar renkliye çevirmek için ne yapmak gerekir? 0-255 aralığı gri tonlar için geçerliydi, renkler için de böyle bir yol var mı?
**Cevap:** Böyle bir kestirme yol yoktur. Burada büyük bir bilgiden (üç kanal) küçük bir bilgiye (tek kanal) dönüşüm yapıldı; bu dönüşümden sonra veri kaybolmuştur ve birebir aynı renkli görüntüyü elde etmek mümkün değildir. Siyah-beyaz görüntüleri renklendirme üzerine çalışmalar vardır, fakat bunlar bir takım varsayımlarla yapılır (ör. eski siyah-beyaz filmleri renklendirirken bir askeri üniformanın hangi renkte olacağını varsaymak) ve her zaman tutarlı değildir; mavi olması gereken bir üniforma mora çalan bir renkte çıkabilir.

## 9. Eşikleme

### 9.1 Tanım

Eşikleme (thresholding), içinde gri tonlar bulunan gri seviyeli bir görüntüyü siyah-beyaz (ikili) bir görüntüye dönüştürür. Bunun için bir eşik değeri $T$ seçilir. Giriş görüntüsü $f(x,y)$, çıkış görüntüsü $g(x,y)$ ise:

$$g(x,y) = \begin{cases} 1, & f(x,y) > T \\ 0, & f(x,y) \le T \end{cases}$$

Eşikten büyük pikseller ön plan nesnesi (foreground object) kabul edilip 1, diğerleri arka plan (background) kabul edilip 0 yapılır. Hoca bu genellemenin nesnelerin koyu bir zemin üzerinde durduğu durum için geçerli olduğunu belirtti; zemin açıksa durum değişir.

### 9.2 Eşik değerinin seçimi

Notebook'taki örnekte 0-255 aralığındaki koyu zemin üzerinde ahşap parçaların bulunduğu bir görüntüde $T = 95$ "doğru eşik değeri" olarak verilmiştir (ekrandan, 01:30:00). 95'ten küçük olan arka plan tümüyle siyah, ahşap parçalar beyaz olur.

- Eşik çok küçük seçilirse çok büyük bir alan beyaza boyanır ve nesneler arka plana karışarak kaybolur.
- Eşik 95'in çok üstünde, örneğin 225 seçilirse ön planda olması gereken nesnelerin büyük kısmı arka plan sayılıp siyaha dönüşür ve detaylar kaybolur.

> **Hocanın vurgusu:** Eşik değerinin ne seçildiği önemlidir.

### 9.3 Madeni para örneği

coins.png görüntüsünde önce $T = 100$, sonra $T = 150$ ile eşikleme yapılıp iki sonuç `subplot` ile yan yana gösterildi. 100 eşik değeri iyi sonuç verdi; 150 seçildiğinde daha koyu renkli bir madeni para kayboldu ve arka plana karışmaya başladı.

**Soru (hocanın sorusu):** Eşiklemenin amacı nedir?
**Cevap:** Nesneleri bulmaya yarar; ön planı arka plandan ayırır, yani bir çeşit bölütleme (segmentasyon) yapılmış olur. Sonuçta gri seviyeli görüntü ikili (binary), siyah-beyaz bir görüntüye dönüşür; hoca bunun önemli bir fark olduğunu vurguladı.

## 10. Uzamsal Filtrelemenin Temelleri

### 10.1 Uzamsal alan ve frekans

Görüntü işlemede yapılan işlemler görüntü uzayında (spatial domain) yapılır. İşaret işlemede bir işaret frekans alanına taşınıp orada da işlenebilir, ancak bu derste hep uzamsal alanda çalışılacak ve filtreler uzamsal filtreleme olarak gösterilecek.

Notebook'taki "Image filtering" bölümüne göre filtreleme görüntü işlemenin en temel işlemlerinden biridir; gürültüyü gidermek ya da özellikleri belirginleştirmek için kullanılır. "Filtre" adı frekans alanındaki işlemeden gelir; orada filtreleme belli frekans bileşenlerini geçirmek ya da reddetmek demektir (ekrandan, 01:35:00).

- **Yüksek frekans:** görüntüde siyahtan beyaza, beyazdan siyaha keskin kenar geçişlerinin olduğu bölgeler.
- **Düşük frekans:** parlaklığın yavaş değiştiği bölgeler.
- **Alçak geçiren filtre (low pass filter):** düşük frekanslı bileşenleri geçirir, yüksek frekanslı bileşenleri törpüler, bastırır. Görüntüdeki etkisi bulanıklaştırma (blurring, smoothing) olur; keskin kenar geçişleri yumuşar.

### 10.2 Filtre maskesi

Bu yumuşatma uzamsal filtrelerle doğrudan görüntü üzerinde yapılabilir; bu filtrelere uzamsal maske, çekirdek (kernel), şablon ya da pencere de denir. Görüntü matrisinin (orijini sol üst köşe) üzerine 3x3 boyutlu bir filtre maskesi yerleştirilir ve maskenin altındaki pikseller işlenir.

- Maske 3x3, 5x5, 7x7 gibi boyutlarda olabilir, ama genelde tek sayı seçilir. Amaç maskenin bir merkez noktasını işaretleyebilmektir; 2x2 gibi çift boyutlu bir maskenin merkezi olmaz.
- Maskenin içindeki değerlere **filtre katsayıları** (filter coefficients) denir. Hangi katsayıların yazılacağına göre filtre alçak geçiren ya da yüksek geçiren olur.

## 11. Ortalama Filtreleri, Korelasyon ve Konvolüsyon

### 11.1 İki ortalama maskesi

Notebook'taki "3x3 Averaging Mask (Low Pass Filter)" bölümünde iki maske vardır (ekrandan, 01:40:00):

$$\frac{1}{9}\times\begin{bmatrix}1&1&1\\1&1&1\\1&1&1\end{bmatrix} \qquad \frac{1}{16}\times\begin{bmatrix}1&2&1\\2&4&2\\1&2&1\end{bmatrix}$$

Her maskenin önündeki sabit çarpan, ortalama alabilmek için katsayıların toplamına bölmeyi sağlar.

- **Eşit ağırlıklı ortalama:** 9 gözün hepsine 1 yazılır; görüntüdeki 9 değer bu ağırlıklarla çarpılıp toplanır ve 9'a bölünür. Alternatif olarak her göze 1/9 yazılabilir; iki yol aynı sonucu verir, ama önce toplayıp sonra bölmek daha pratiktir.
- **Ağırlıklı ortalama:** Çıkış maskenin ortasındaki göz için üretildiği için ortadaki gözün ağırlığı daha fazla, komşularınki daha az olmalıdır. Merkezin ağırlığı 4, ana yönlerin (kuzey, güney, doğu, batı) ağırlığı bunun yarısı olan 2, daha uzaktaki ara yönlerin (çaprazların) ağırlığı 1'dir. Katsayıların toplamı 16 olduğu için 1/16 ile çarpılır.

### 11.2 Korelasyon ve konvolüsyon

Filtre katsayıları görüntüye iki farklı biçimde uygulanabilir: korelasyon ya da konvolüsyon.

> **Hocanın vurgusu:** Bu ikisi arasındaki fark önemli bir kavramdır ve genelde dikkat edilmez.

Notebook'taki şekil Gonzalez kitabından alınmıştır (ekrandan, 01:45:00). Giriş $f(x,y)$ 5x5 boyutludur, yalnız ortasında bir tane 1 vardır, diğer gözler 0'dır. Filtre $w(x,y)$ katsayıları sırayla 1'den 9'a kadar yazılmıştır:

$$w = \begin{bmatrix}1&2&3\\4&5&6\\7&8&9\end{bmatrix}$$

Filtreleme yapılabilmesi ve çıkışın da 5x5 olabilmesi için görüntünün çevresi sıfırlarla doldurulur (padding).

- **Korelasyon:** $w$ maskesi hiçbir döndürme yapılmadan görüntüye oturtulur. Karşılıklı gelen piksel değerleri ile katsayılar çarpılıp toplanır ve sonuç maskenin merkezindeki piksel için çıkış olur. Maske kaydırıldıkça tek 1 değeri maskenin farklı katsayılarıyla örtüşür. İlk örtüşmede maskenin 9 katsayılı gözüyle çakışır ve 9 üretir; kaydırdıkça 9, 8, 7, sonra 6, 5, 4 ve 3, 2, 1 üretilir. Kırpılmış korelasyon sonucu:

```text
0 0 0 0 0
0 9 8 7 0
0 6 5 4 0
0 3 2 1 0
0 0 0 0 0
```

- **Konvolüsyon:** Filtre matrisi önce x ve y doğrultusunda 180 derece döndürülür. Bunu önce y ekseni etrafında, sonra x ekseni etrafında ayna görüntüsü almak (mirror) gibi düşünebiliriz. Döndürülmüş maske 9, 8, 7 / 6, 5, 4 / 3, 2, 1 olur ve korelasyondaki işlemin aynısı bu maskeyle yapılır. Kırpılmış konvolüsyon sonucu:

```text
0 0 0 0 0
0 1 2 3 0
0 4 5 6 0
0 7 8 9 0
0 0 0 0 0
```

Yani tek bir 1'den oluşan görüntünün (birim dürtü) konvolüsyonu maskenin kendisini verir.

> **Hocanın vurgusu:** Ağırlık matrisi simetrikse, x ve y doğrultusunda 180 derece döndürüldüğünde başlangıçtaki matrisle birebir aynı olur; bu durumda korelasyon ve konvolüsyon sonuçları aynıdır. Bu örnekte katsayılar simetrik olmadığı için sonuçlar farklı çıktı.

### 11.3 Elle konvolüsyon örneği

Hoca simetrik ağırlıklı ortalama maskesiyle tablet üzerinde elle bir örnek çözdü (ekrandan, 01:55:00). $W$ filtre katsayılarıdır:

$$W = \frac{1}{16}\begin{bmatrix}1&2&1\\2&4&2\\1&2&1\end{bmatrix}$$

$W$, y doğrultusunda ve x doğrultusunda aynalandığında aynı kalır; bu yüzden konvolüsyon ile korelasyon arasında fark yoktur.

Giriş görüntüsü $I$, 5x5 boyutlu, 3 bit/pikseldir (değerler 0-7):

```text
1 3 2 5 7
0 1 1 2 6
1 2 2 3 4
1 3 4 5 6
2 5 6 6 7
```

İstenen $I * W$'dir; $*$ işareti konvolüsyon demektir.

**Soru (hocanın sorusu):** Padding uygulanmazsa çıkış görüntüsü kaça kaç olur?
**Cevap:** 3x3. Maske görüntünün içinden başlayarak oturtulur ve yalnız maskenin tamamen sığdığı merkezler için çıkış üretilir.

**Birinci çıkış değeri:** Maske sol üst 3x3 bölgeye oturtulur, karşılıklı değerler çarpılıp toplanır:

$$1\cdot1 + 3\cdot2 + 2\cdot1 + 0\cdot2 + 1\cdot4 + 1\cdot2 + 1\cdot1 + 2\cdot2 + 2\cdot1 = 1+6+2+0+4+2+1+4+2 = 22$$

Çıkış $22/16$'dır.

**İkinci çıkış değeri:** Maske bir piksel sağa kaydırılır. Bölge $[3,2,5;\ 1,1,2;\ 2,2,3]$'tür:

$$3 + 4 + 5 + 2 + 4 + 4 + 2 + 4 + 3 = 31$$

Çıkış $31/16$'dır. (Hoca önce 35 hesapladığını hatırladı; yeniden toplayınca 31 doğrulandı.)

**Üçüncü çıkış değeri:** Bir piksel daha sağa kaydırılır. Bölge $[2,5,7;\ 1,2,6;\ 2,3,4]$'tür:

$$2 + 10 + 7 + 2 + 8 + 12 + 2 + 6 + 4 = 53$$

Çıkış $53/16$'dır.

Sonra maske bir piksel aşağı kaydırılarak aynı işlemler sonraki satırlar için tekrarlanır. Python ile kontrol edilen tam çıkış (derste yalnız ilk satır hesaplandı):

$$I * W = \frac{1}{16}\begin{bmatrix}22&31&53\\28&39&55\\47&64&77\end{bmatrix}$$

> **Hocanın vurgusu:** İşlemi kağıt üzerinde yapabilmek önemlidir. Giriş görüntüsü ve filtre katsayıları verilip konvolüsyon sonucunun bulunması istenebilir.

**Soru (hocanın sorusu):** Aynı soruda konvolüsyon yerine korelasyon sonucu sorulsaydı ne değişirdi?
**Cevap:** Hiçbir şey; maske simetrik olduğu için 180 derece döndürüldüğünde aynı katsayılar elde edilir ve sonuç aynı kalır.

## 12. Python'da Ortalama Filtresi

### 12.1 Sentetik görüntü

İşlemi daha iyi anlamak için önce sentetik bir görüntü oluşturulur (ekrandan, 02:00:00):

```python
%matplotlib inline
import numpy as np
from matplotlib import pyplot as plt

bright_square = np.zeros((7, 7), dtype=float)
bright_square[2:5, 2:5] = 1
```

7x7 boyutlu, bütün pikselleri sıfır olan ve veri türü float olan bir matris oluşturulur; 2. ile 5. satırlar ve 2. ile 5. sütunlar arasındaki gözler 1 yapılır. Sonuç, siyah bir arka plan üzerinde ortada 3x3 boyutlu beyaz bir karedir.

**Soru (hocanın sorusu):** Bu görüntüye alçak geçiren (yumuşatma) filtresi uygulanırsa ne olmasını bekleriz?
**Cevap:** Keskin geçişlerin yerine kademeli bir geçiş oluşmasını.

### 12.2 Ortalama çekirdeği ve konvolüsyon

Ortalama filtresi (mean filter) `np.full` ile içi 1/9 ile doldurulmuş 3x3 bir çekirdek olarak oluşturulur. Konvolüsyon için SciPy'ın `ndimage` modülü `ndi` adıyla içeri alınır ve `ndi.convolve` ile `bright_square` görüntüsüne bu çekirdek uygulanır. Simetrik yapı nedeniyle korelasyon kullanılsa da sonuç değişmez.

Sonuç matrisinde keskin 0-1 geçişleri 0, 0.33, 0.67, 1 biçimine dönüşür. Bu kademeli geçiş, keskin sıfır-bir geçişlerinin nasıl bulanıklaştığını sayısal olarak gösterir; altında görüntü biçimi de verilmiştir.

> **Ek bilgi (derste anlatılmadı):** 0.33 ve 0.67 değerleri, 3x3 pencerenin o konumda kapsadığı 9 pikselden sırasıyla 3'ünün ve 6'sının 1 olmasından gelir ($3/9 \approx 0.33$, $6/9 \approx 0.67$). Karenin merkezinde 9 pikselin hepsi 1 olduğu için değer 1 kalır.

## 13. Gauss Fonksiyonu ve Gauss Filtresi

### 13.1 Bir boyutlu Gauss fonksiyonu

Ortalama filtresinin bir alternatifi Gauss filtresidir. Hoca bu filtrenin ileride çok kullanılacağını, bu yüzden istatistikteki normal dağılımı (Gaussian distribution) iyi tanımak gerektiğini söyledi. Bir boyutlu Gauss fonksiyonunun genel biçimi:

$$G(x) = \frac{1}{\sqrt{2\pi}\,\sigma}\, e^{-\frac{(x-\mu)^2}{2\sigma^2}} = \frac{1}{\sqrt{2\pi\sigma^2}}\, e^{-\frac{(x-\mu)^2}{2\sigma^2}}$$

Katsayı iki biçimde de yazılabilir; ikisi birbirine eşittir. $\mu$ ortalamadır; ortalama sıfır alınırsa üs yalnız $-x^2/2\sigma^2$ olur. Notebook'taki alıştırmada $\sigma = 1$ alınmıştır (ekrandan, 02:05:00):

$$k_i = \frac{1}{\sqrt{2\pi}} \exp\left(-\frac{(x_i - x_0)^2}{2}\right)$$

Burada $x_0$ ortalamadır; $\sigma = 1$ olduğu için paydada $2\sigma^2$ yerine 2 yazılmıştır.

Dağılım çan eğrisidir. Hoca grafikte $\pm 3\sigma$ aralığının gösterildiğini, bu aralığın dağılımın altındaki alanın yaklaşık yüzde 98'ini kapsadığını söyledi. $\sigma$'nın kaç katına kadar alınacağı önemlidir; hoca idealin genelde $\pm 2$ ile $\pm 3\sigma$ civarı olduğunu söyledi.

> **Ders sonrası not:** Hoca $\pm 3\sigma$ aralığının alanın yaklaşık yüzde 98'ini kapsadığını söyledi; doğrusu yaklaşık yüzde 99.7'dir. $\pm 2\sigma$ yaklaşık yüzde 95.4, $\pm 2.5\sigma$ yaklaşık yüzde 98.8 kapsar (python ile hesaplandı).

### 13.2 Gauss eğrisini Python'da çizdirme

Ekrandaki kod (ekrandan, 02:10:00):

```python
import math
import matplotlib.pyplot as plt

x=np.arange(-4, 5, 1.)
kat=1/(math.sqrt(2*math.pi))

k=kat*np.exp(-(x*x)/2)

plt.plot(x,k)
```

$x$ için $-4$'ten 5'e kadar (5 hariç) birer adımlık bir dizi üretilir, önündeki katsayı $\sigma=1$ için $1/\sqrt{2\pi}$ olarak hesaplanır ve fonksiyon çizdirilir. Tepe değeri yaklaşık 0.40'tır. Grafiğin üçgenimsi çıkmasının nedeni örnekleme aralığının çok geniş olmasıdır; daha sık örnek alınırsa grafik yumuşar. Bu yüzden ikinci denemede $x$, $-5$'ten 6'ya kadar 0.1 adımla oluşturulur.

İkinci denemede aynı $x$ ekseni ($-5$ ile 5 arası) için iki Gauss eğrisi çizilir:

- **$\sigma = 1$:** $\pm 5\sigma$'lık bir alan çizilmiş olur. Yaklaşık 2.5 civarında değerler sıfıra çok yaklaşır; uçlardaki bölge neredeyse tamamen sıfırdır. Tepe 0.40'tır.
- **$\sigma = 2$:** aynı aralık $\pm 2.5\sigma$'ya karşılık gelir. Eğri yayılır ve tepe 0.20'ye, yani yarıya düşer.

Eğrinin altındaki alan her zaman 1'dir. $\sigma$ küçükken eğri dik ve yüksek, $\sigma$ büyükken yukarıdan basılmış ve yanlara genişlemiş olur. İkisi üst üste çizilseydi fark daha net görülürdü.

### 13.3 İki boyutlu Gauss fonksiyonu

İki boyutlu, sıfır ortalamalı Gauss fonksiyonu:

$$G(x,y) = \frac{1}{2\pi\sigma^2}\, e^{-\frac{x^2+y^2}{2\sigma^2}}$$

Çizildiğinde $x$ ve $y$ eksenleri üzerinde üç boyutlu bir çan yüzeyi elde edilir. Kendi kodumuzla çizmek için $X$ ve $Y$ dizileri oluşturulur, `np.meshgrid` ile her matris gözündeki $x$ ve $y$ değerlerini tutan iki boyutlu yapı kurulur, formülde yerine yazılır ve `plot_surface` ile yüzey çizdirilir (ekrandan, 02:15:00):

```python
fig = plt.figure()
ax = fig.gca(projection='3d')
# Make data.
X = np.arange(-5, 6, 0.25)
Y = np.arange(-5, 6, 0.25)
X, Y = np.meshgrid(X, Y)
R = (X**2 + Y**2)
Z = 1/(math.sqrt(2*math.pi))*np.exp(-R/2)
# Plot the surface.
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm,
                       linewidth=0, antialiased=False)
```

> **Ders sonrası not:** Koddaki katsayı bir boyutlu fonksiyonunki ($1/\sqrt{2\pi}$) olarak bırakılmıştır. İki boyutlu fonksiyonun $\sigma=1$ için doğru katsayısı $1/(2\pi)$'dir. Bu fark yalnız yüzeyin yüksekliğini ölçekler, biçimini değiştirmez; filtre olarak kullanılırken katsayılar zaten toplamları 1 olacak biçimde normalize edilir (büyük olasılıkla).

Bu çizimler filtre katsayılarını elde etmek için kullanılır: Gauss fonksiyonundan yararlanarak ağırlıklı bir ortalama (yumuşatma) filtresi kurulabilir.

### 13.4 Gerçek görüntüde ortalama ve Gauss filtresi

Görüntü işleme kitaplarında sık kullanılan, scikit-image'in `data` modülünde hazır bulunan kameraman (cameraman) gri seviyeli görüntüsü kullanıldı. Görüntüden her 10 satır ve sütunda bir örnek alınarak 50x50 boyutlu küçük bir görüntü üretilir; bu görüntü büyütülüp gösterildiğinde mozaikli (pixelated) görünür.

- Önce mozaikli görüntüye yukarıda tanımlanan 1/9'luk ortalama çekirdeğiyle konvolüsyon uygulanır.
- Sonra aynı işlem Gauss filtresiyle yapılır: `filters.gaussian(pixelated_float, sigma=2)` (ekrandan, 02:20:00). Görüntü önce `img_as_float` ile ondalıklı türe çevrilir.

Sonuçta mozaiklenme kaybolur, fakat görüntü oldukça bulanıklaşır; keskin kenar geçişleri yumuşar. Ortalama filtresiyle Gauss filtresinin ortak etkisi budur. Notebook'taki açıklamaya göre sonuç ortalama filtresinden çok farklı görünmese de Gauss filtresi uzaklığa bağlı ağırlıklandırması ve keskin geçişleri olmaması nedeniyle genelde tercih edilir (ekrandan, 02:20:00).

## 14. Medyan Filtresi ve Tuz-Biber Gürültüsü

### 14.1 Sıralama istatistiğine dayalı filtreler

Slayttaki tanıma göre (ekrandan, 02:25:00) sıralama istatistiği filtreleri (order-statistic filters), tepkisi görüntü alanındaki piksellerin sıralanmasına dayanan doğrusal olmayan uzamsal filtrelerdir. Bu sınıfın en bilinen filtresi medyan filtresidir: bir pikselin değerini o pikselin komşuluğundaki parlaklık değerlerinin ortancasıyla değiştirir.

Medyan filtresinin görevi görüntüdeki gürültüyü (noise) temizlemektir. Gürültüyü temizlemek yüksek frekanslı bileşenleri atıp düşük frekanslıları geçirmek demektir; bu yüzden medyan filtresi bir çeşit alçak geçiren filtre gibi kullanılır.

Medyan filtresi için bir **yapılandırma elemanına** (structuring element, kernel) ihtiyaç vardır. Bu eleman, sıralama işleminin hangi alanda yapılacağını ve hangi gözlerin kullanılacağını belirler. Kare, disk ya da elmas (diamond) biçiminde olabilir; içinde 1 olan gözler sıralamaya katılır.

### 14.2 Elle medyan filtresi örneği

Konvolüsyon örneğindeki aynı 5x5 görüntü kullanıldı (ekrandan, 02:25:00):

```text
1 3 2 5 7
0 1 1 2 6
1 2 2 3 4
1 3 4 5 6
2 5 6 6 7
```

Yapılandırma elemanı 3x3'tür ama köşe gözleri 0 yapılmıştır:

```text
0 1 0
1 1 1
0 1 0
```

Bu, merkez pikselle kuzey, güney, doğu ve batı komşularının sıralamaya katılacağı anlamına gelir; toplam 5 göz. Padding olmadığından çıkış 3x3'tür.

- **Birinci konum** (merkez 2. satır 2. sütundaki 1): değerler 3 (kuzey), 0 (batı), 1 (merkez), 1 (doğu), 2 (güney). Sıralanınca $0, 1, 1, 2, 3$; ortanca **1**. Merkez zaten 1'di, değeri değişmedi.
- **İkinci konum** (bir sağa kaydırılınca, merkez 1): değerler 2, 1, 1, 2, 2. Sıralanınca $1, 1, 2, 2, 2$; ortanca **2**.
- **Üçüncü konum** (merkez 2): değerler 5, 1, 2, 6, 3. Sıralanınca $1, 2, 3, 5, 6$; ortanca **3**.

> **Hocanın vurgusu:** Medyan filtresinde hangi gözlerin kullanılacağına karar veren bir yapılandırma elemanı vardır.

### 14.3 Python'da medyan filtresi

Notebook'ta komşuluk bir disk yapılandırma elemanıyla tanımlanır; yapılandırma elemanı mantığı daha çok morfolojik işlemlerde kullanılır. Medyan filtresi scikit-image'te sıralama filtrelerinin bulunduğu `filters.rank` altındadır (ekrandan, 02:30:00):

```python
neighborhood = disk(10)
coins = data.coins()
mean_coin = filters.rank.mean(coins, neighborhood)
median_coin = filters.rank.median(coins, neighborhood)

plt.subplot(1,3,1)
plt.imshow(coins, cmap='gray')

plt.subplot(1,3,2)
plt.imshow(mean_coin, cmap='gray')

plt.subplot(1,3, 3)
plt.imshow(median_coin, cmap='gray')
```

Madeni paralar disk biçiminde olduğu için disk yapılandırma elemanı bu problem için daha elverişli kabul edilmiştir. Medyan filtresinin önemli özelliği **kenar koruyan** (edge preserving) bir filtre olmasıdır.

### 14.4 Tuz-biber gürültüsü ve önerilen deneme

Hoca derse ait test görüntülerinden test.tif'i gösterdi: farklı şekiller içerir ve bazı bölgelerine (ör. bir dikdörtgenin içine) gürültü eklenmiştir.

- **Biber gürültüsü (pepper noise):** beyaz bir zemin üzerine siyah noktalar düşmesidir.
- **Tuz gürültüsü (salt noise):** siyah bir zemin üzerine nokta nokta beyazlar atılmasıdır.

Tuz-biber gürültüsünü temizlemede medyan filtresi de ortalama filtresi de başarılıdır. Ancak ortalama filtresi kullanıldığında dikdörtgenlerin köşelerinde ve kenarlarında bozulma başlar. Hoca medyan filtresinin köşeleri bozabildiğini, ama kenarları bozmadığını söyledi.

Hoca bu konuda bir deneme yapılmasını önerdi: filtrelerin gürültüyü ne kadar temizlediğini ve kenarları ne kadar bozduğunu karşılaştırmak. Bunun için yapılandırma elemanı disk yerine kare ya da dikdörtgen seçilebilir, diskin boyutu 10 yerine 20 yapılabilir ve sonuçlar test görüntüsünde karşılaştırılabilir.

## 15. Örnek Sorular

**Soru 1** (ekrandan, 01:05:00): 3 bitlik, 64x64 boyutlu bir görüntüde $r_k = 0, 1, \dots, 7$ değerlerinin tekrar sayıları $n_k$ = 790, 1023, 850, 656, 329, 245, 122, 81'dir. Histogram eşitleme sonrası her parlaklık değerinin yeni değerini bulun. Çıkış 4 bit/piksel olsaydı ne değişirdi?

> **Çözüm (derste verildi, ekrandan, 01:10:00):** $p(r_k) = n_k/4096$ = 0.19, 0.25, 0.21, 0.16, 0.08, 0.06, 0.03, 0.02. Birikimli toplamlar 0.19, 0.44, 0.65, 0.81, 0.89, 0.95, 0.98, 1.00. 7 ile çarpınca 1.33, 3.08, 4.55, 5.67, 6.23, 6.65, 6.86, 7.00; yuvarlayınca $s_k$ = 1, 3, 5, 6, 6, 7, 7, 7. Çıkış 4 bit olsaydı 7 yerine 15 ile çarpılırdı.
>
> **4 bitlik sonuç (derste verilmedi, python ile hesaplandı):** Dörder basamaklı birikimli toplamlar (0.193, 0.443, 0.650, 0.810, 0.891, 0.950, 0.980, 1.000) 15 ile çarpılıp yuvarlanırsa $s_k$ = 3, 7, 10, 12, 13, 14, 15, 15 olur.

**Soru 2** (ekrandan, 01:55:00): Aşağıdaki 5x5 giriş görüntüsü $I$ ile $W = \frac{1}{16}[1\,2\,1;\ 2\,4\,2;\ 1\,2\,1]$ maskesinin padding uygulanmadan konvolüsyonunu ($I * W$) bulun. Korelasyon sonucu farklı olur mu?

```text
1 3 2 5 7
0 1 1 2 6
1 2 2 3 4
1 3 4 5 6
2 5 6 6 7
```

> **Çözüm:** Çıkış 3x3'tür. Derste ilk satır hesaplandı: 22/16, 31/16, 53/16. Kalan satırlar derste hesaplanmadı (python ile kontrol edildi): 28/16, 39/16, 55/16 ve 47/16, 64/16, 77/16. Maske simetrik olduğu için korelasyon sonucu aynıdır.

**Soru 3** (ekrandan, 02:25:00): Aynı $I$ görüntüsüne merkez ile kuzey, güney, doğu, batı komşularını seçen artı biçimli 3x3 yapılandırma elemanıyla medyan filtresi uygulayın (padding yok).

> **Çözüm:** Derste ilk satır hesaplandı: 1, 2, 3.
>
> **Çözüm (derste verilmedi, python ile hesaplandı):** Tam çıkış
>
> ```text
> 1 2 3
> 2 2 3
> 3 4 5
> ```
>
> Örneğin orta göz (merkez 2) için değerler 1, 2, 2, 3, 4 sıralanır ve ortanca 2'dir.

**Soru 4** (derste sözlü, 00:25:00): mm.jpg görüntüsünün kırmızı, yeşil ve mavi kanalları gri seviyede gösterildiğinde her kanalda hangi renkler beyaz, hangileri siyah çıkar?

> **Çözüm (derste verildi):** Her kanalda o rengin en doygun olduğu drajeler beyaz (en büyük değer: 255 ya da 1), o rengi hiç içermeyenler siyah (0) çıkar. Kırmızı kanalda kırmızılar, yeşil kanalda yeşiller, mavi kanalda maviler beyazdır.

**Soru 5** (derste sözlü, 01:34:00): Eşikleme işleminin amacı nedir ve sonuçta nasıl bir görüntü elde edilir?

> **Çözüm (derste verildi):** Ön planı arka plandan ayırarak nesneleri bulmaya yarar, bir çeşit bölütlemedir. Gri seviyeli görüntü ikili (siyah-beyaz) görüntüye dönüşür.

## Dersin Toparlaması

Bu derste uygulamalı olarak, Python ve scikit-image ile görüntü okuma, matris dilimleme, JPEG kalite faktörüyle kaydetme, RGB kanallarını ayırma ve gri seviyeye dönüşüm gibi temel işlemlerden başlandı. Ardından yoğunluk dönüşümleri ve gama eğrileri, histogramın okunması ve histogram eşitlemenin elle hesabı, eşiklemeyle ikili görüntü elde etme konuları işlendi. Dersin ikinci yarısında uzamsal filtreleme ele alındı: ortalama ve ağırlıklı ortalama maskeleri, korelasyon ile konvolüsyonun farkı ve simetrik maskede ikisinin aynı olması, Gauss fonksiyonunun bir ve iki boyutta çizdirilip filtre katsayısı olarak kullanılması, son olarak da kenar koruyan, doğrusal olmayan medyan filtresi ve tuz-biber gürültüsü.

Hocanın genel mesajı, her işlemin hazır fonksiyonu olsa da arkadaki matematiğin bilinmesi gerektiğiydi. Sonraki derste bu derste öğrenilen filtrelerin birinci ve ikinci türevleri kullanılarak gradyan ve Laplace işlemleriyle görüntü keskinleştirme (image sharpening) konusuna geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
