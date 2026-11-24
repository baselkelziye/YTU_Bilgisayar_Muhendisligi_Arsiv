# Ders 2 Genişletilmiş Notu: Python ve NumPy'a Giriş, Görüntü Dosyası Yapıları ve Yoğunluk Dönüşümleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Neden Python ve Neden Düşük Seviyeden Başlıyoruz?
- 2. Çalışma Ortamı: CS231n NumPy Eğitimi, Jupyter, Spyder ve Colab
- 3. Python'un Temel Veri Tipleri
- 4. Kaplar: Liste, Sözlük, Küme; Fonksiyon ve Sınıf
- 5. NumPy Dizileri
- 6. Veri Tipleri ve Dizi Matematiği
- 7. Yayma (Broadcasting)
- 8. Matplotlib ve scikit-image ile Görüntü Okuma, Gösterme ve Çizim
- 9. Görüntü Dosyası Türleri
- 10. Görüntü Üzerinde Temel İşlemler
- 11. Yoğunluk Dönüşümleri
- 12. Bit Düzlemi Dilimleme
- Örnek Sorular

## 1. Neden Python ve Neden Düşük Seviyeden Başlıyoruz?

Hoca dersin bütün uygulamalarının Python'da, NumPy kütüphanesi kullanılarak yapılacağını söyleyerek başladı. Bu haftanın amacı platformu tanımak: NumPy, Matplotlib ve scikit-image kütüphaneleriyle görüntü üzerinde işlem yapmayı görmek. Sonraki haftalarda da her konu anlatılırken o konunun Python'da nasıl yapıldığı kod parçalarıyla gösterilecek; hoca öğrencilerden anlatılanları kendi bilgisayarlarında aynı anda denemelerini, yani dersin biraz laboratuvar havasında ilerlemesini istedi.

Bu yaklaşımın gerekçesi şudur: Bir görüntü matrisinin ya da görüntü dosyasının yapısını düşük seviyede bilmek, onu işlerken nelere dikkat etmek gerektiği konusunda farkındalık yaratır. Metin, gri, renkli gibi farklı görüntü biçimlerinin dosyada nasıl tutulduğunu ve aralarındaki farkı bilen biri, ileride kullandığı çerçevelerde (framework) yanlış fonksiyon ya da veri tipi seçmez. Bu yüzden ders en temelden, adım adım ilerleyecek.

## 2. Çalışma Ortamı: CS231n NumPy Eğitimi, Jupyter, Spyder ve Colab

Kaynak olarak Stanford'un CS231n (Convolutional Neural Networks for Visual Recognition) dersinin "Python Numpy Tutorial (with Jupyter and Colab)" sayfası kullanıldı (ekrandan, 00:20:00). Hoca bu dersin YouTube videolarını da faydalı bir kaynak olarak önerdi.

Bu eğitim Jupyter Notebook ile ya da Google Colab ile çalıştırılabilir. Hoca bilgisayarına Anaconda kurmuştu; Anaconda altında hem Spyder hem Jupyter gelir. Jupyter'in avantajı, metinsel açıklamayı ve hemen altına kod parçasını aynı belgede tutabilmesidir; bu yüzden rapor ve ders notu hazırlamaya çok uygundur. Kurulumu olmayanlar Colab'i kullanabilir. Hoca eğitimdeki kodları "Numpy Giris" adlı bir Jupyter defterine aktarmış ve hücre hücre çalıştırarak anlattı.

Jupyter'de her hücre bağımsız çalıştırılabilir; hücre içindeyken Ctrl+Enter yeterlidir. Hoca bir hücreyi çalıştırırken `NameError: d is not defined` hatası aldı, çünkü `d` sözlüğünü tanımlayan hücre daha önce çalıştırılmamıştı. Önce tanımlayan hücreyi çalıştırınca sorun çözüldü. Bu, defterde hücrelerin çalıştırılma sırasının önemli olduğunu gösterir.

## 3. Python'un Temel Veri Tipleri

### 3.1 Sayılar

Python'da değişkenin tipi bildirilmez; atanan değere göre belirlenir. Bu MATLAB'a benzer. `x = 3` bir tam sayı (int), `y = 3.7` bir ondalıklı sayıdır (float); `print(type(y))` ile tip görülür. Değişken artırılabilir (`x += 1` gibi), 2 ile çarpılabilir, karesi alınabilir (`x ** 2`).

### 3.2 Mantıksal tipler

Mantıksal (Boolean) değişkenler `True` ve `False` değerini alır. C gibi dillerde VE, VEYA işlemleri `&&`, `||` gibi sembollerle yazılırken Python'da `and`, `or`, `not` sözcükleri kullanılır. Örnekte `t = True`, `f = False` tanımlanmış ve `t and f` işleminin sonucu `False` olarak yazdırılmıştır.

### 3.3 Metinler

Python metin (string) işlemleri için çok sayıda hazır fonksiyon sunar (ekrandan, 00:25:00):

```python
hello = 'hello'
print((hello), type(hello), (len(hello)))   # hello <class 'str'> 5

w = 'world'
h = hello + ' ' + w
print(h)                                    # hello world

s = 'merhaba'
print(s.capitalize())                       # Merhaba
print(s.center(11))                         # '  merhaba  '
print(s.replace('h', 'aaaah'))              # meraaaahaba
print('     merhaba   '.strip())            # merhaba
```

`center(11)` on bir karakterlik bir alan hazırlar ve yedi harfli `merhaba` sözcüğünü ortaya yerleştirir; başta ve sonda ikişer boşluk kalır. Hoca bunu, çıktıyı fareyle seçip iki yandaki boşlukları göstererek açıkladı. `replace` metindeki `h` harfini başka bir metinle değiştirir. `strip` baştaki ve sondaki boşlukları temizler (ekrandan, 00:30:00).

## 4. Kaplar: Liste, Sözlük, Küme; Fonksiyon ve Sınıf

Python'da hazır kap (container) tipleri vardır: liste (list), sözlük (dictionary), küme (set) ve demet (tuple).

### 4.1 Listeler

Liste, Python'daki dizi karşılığıdır, ama iki önemli farkı vardır: boyutu değiştirilebilir ve farklı tipte eleman tutabilir (ekrandan, 00:30:00). Yani bunu bir tam sayı dizisi ya da ondalıklı sayı dizisi gibi düşünmemek gerekir; içinde hem tam sayı hem metin olabilir.

```python
xs = [3, 1, 2]
print(xs, xs[2])   # [3, 1, 2] 2
print(xs[-1])      # 2
xs[2] = 'yeni'
print(xs)          # [3, 1, 'yeni']
```

İndeksleme 0'dan başlar: ilk elemanın indeksi 0, ikincisinin 1, üçüncüsünün 2'dir. `xs[-1]` son elemanı verir. Tam sayılarla kurulan listenin 2. gözüne `'yeni'` metni atanabilir; liste iki tam sayı ve bir metinden oluşur. `xs.append('bar')` listenin sonuna yeni eleman ekler ve liste `[3, 1, 'yeni', 'bar']` olur. `pop` ise son elemanı çıkarır.

### 4.2 Dilimleme (slicing)

Dilimleme bir listenin belli elemanlarını kısa yoldan seçmeyi sağlar; MATLAB'da da çok kullanılır (ekrandan, 00:35:00):

```python
nums = list(range(5))  # [0, 1, 2, 3, 4]
print(nums[2:4])       # [2, 3]
print(nums[2:])        # [2, 3, 4]
print(nums[:2])        # [0, 1]
print(nums[:])         # [0, 1, 2, 3, 4]
print(nums[:-1])       # [0, 1, 2, 3]
nums[2:4] = [8, 9]
print(nums)            # [0, 1, 8, 9, 4]
```

`range(5)` 0'dan başlar ve 5'i içermez. Dilimdeki bitiş indeksi de dışarıda kalır (exclusive): `nums[2:4]` 2. ve 3. gözleri verir. `nums[2:]` ikinci gözden sona kadar, `nums[:2]` baştan ikinci göze kadar (2 hariç), `nums[:]` bütün elemanlar, `nums[:-1]` son eleman hariç hepsidir. Dilime atama da yapılabilir: `nums[2:4] = [8, 9]` 2. ve 3. gözlere 8 ve 9 yazar. Hoca bunun büyük matrislerde çok işe yaradığını vurguladı: döngüye girmeden matrisin belli bölgeleri alınıp üzerinde çalışılabilir.

### 4.3 Döngüler ve liste üreteci

`animals = ['cat', 'dog', 'monkey']` listesindeki her eleman `for x in animals:` döngüsüyle yazdırılır. `enumerate` ile hem indeks hem eleman alınır:

```python
for idx, x in enumerate(animals):
    print('#%d: %s' % (idx + 1, x))
```

Burada `%d` ilk değerin onluk tam sayı, `%s` ikincinin metin olarak yazılacağını belirten biçim ifadeleridir; indeks 0'dan başladığı için ekrana `idx + 1` yazılır.

Bir listedeki sayıların karelerini almanın uzun ve kısa yolu (ekrandan, 00:40:00):

```python
nums = [0, 1, 2, 3, 4]
squares = []
for x in nums:
    squares.append(x ** 2)
print(squares)          # [0, 1, 4, 9, 16]

kareler = [x ** 2 for x in nums]
print(kareler)          # [0, 1, 4, 9, 16]

kareler_cift = [x ** 2 for x in nums if x % 2 == 0]
print(kareler_cift)     # [0, 4, 16]
```

Son örnekte `x % 2 == 0` koşulu sayının 2'ye bölümünden kalanın sıfır, yani sayının çift olduğunu denetler; yalnız çift sayıların kareleri listeye girer. Hoca, belli bir programlama dili alışkanlığından gelenlere ilk yol daha kolay gelebileceğini, kısa yazımlara alışmanın zaman alacağını söyledi.

### 4.4 Sözlükler

Sözlük anahtar-değer (key-value) çiftleri tutar; Java'daki Map yapısına benzer (ekrandan, 00:40:00; 00:45:00):

```python
d = {'cat': 'cute', 'dog': 'furry'}
print(d['cat'])        # cute
print('cat' in d)      # True
d['fish'] = 'wet'
print(d)               # {'cat': 'cute', 'dog': 'furry', 'fish': 'wet'}
del d['cat']
print(d)               # {'dog': 'furry', 'fish': 'wet'}

d = {'person': 2, 'cat': 4, 'spider': 8}
for x in d:
    legs = d[x]
    print('A %s has %d legs' % (x, legs))
```

Anahtar yazılınca karşılığındaki değer gelir; `in` ile bir anahtarın sözlükte olup olmadığı denetlenir; yeni giriş eklenebilir ve `del` ile bir çift silinebilir. Son örnek bir sözlük üzerinde döngüyle gezinmeyi gösterir: insanın, kedinin ve örümceğin kaç bacağı olduğu yazdırılır.

### 4.5 Kümeler, fonksiyonlar ve sınıflar

Küme (set) sırasız ve birbirinden farklı elemanlardan oluşan bir topluluktur. Sözlük gibi süslü parantezle tanımlanır: `animals = {'cat', 'dog'}`. `'cat' in animals` ifadesi eleman kümedeyse `True` döndürür; kümeye eleman eklenebilir.

Fonksiyon `def` anahtar sözcüğüyle tanımlanır. Örnekte bir işaret (sign) fonksiyonu tanımlanmıştır: girdi pozitifse `'positive'`, negatifse `'negative'`, sıfırsa `'zero'` döndürür. Fonksiyon bir döngü içinde `-1, 0, 1` için çağrılınca sırasıyla negatif, sıfır ve pozitif sonuç döner. Hoca bu söz dizimine biraz yazarak alışmak gerektiğini söyledi. Sınıfın `class` ile nasıl tanımlandığı da eğitimde gösterilmiştir.

## 5. NumPy Dizileri

Buraya kadar Python'un genel özellikleri anlatıldı. NumPy ise bilimsel hesaplama için oluşturulmuş bir kütüphanedir; yüksek performanslı çok boyutlu dizi nesnesi ve bunlarla çalışmak için hazır fonksiyonlar sunar.

### 5.1 Dizi tanımı ve şekil (shape)

NumPy dizisi aynı tipte değerlerden oluşan bir ızgaradır ve negatif olmayan tam sayılardan oluşan bir demetle indekslenir. Boyut sayısı dizinin rankıdır, şekli (shape) her boyuttaki uzunluğu veren bir demettir. Diziler iç içe Python listelerinden kurulur, elemanlara köşeli parantezle erişilir (ekrandan, 00:50:00).

```python
import numpy as np
a = np.array([1, 2, 3, 4])
print(type(a))           # <class 'numpy.ndarray'>
print(a.shape)           # (4,)
print(a[0], a[1], a[2])  # 1 2 3
a[3] = 15
print(a)                 # [ 1  2  3 15]

a = np.array([[1, 2, 3, 4]])
print(a.shape)           # (1, 4)

b = np.array([[1, 2, 3], [4, 5, 6]])
print(b.shape)           # (2, 3)
```

> **Hocanın vurgusu:** Tek köşeli parantezle kurulan dizinin şekli `(4,)`, yani yalnız dört elemanlı bir dizidir. İki köşeli parantezle kurulan dizinin şekli `(1, 4)`, yani bir satır dört sütunlu bir matristir. Matris, vektör ve dizi arasındaki bu farka dikkat edilmelidir.

İki boyutlu matriste dıştaki köşeli parantez matrisin tanımını, içteki köşeli parantezlerin her biri bir satırı tanımlar; `b` iki satır üç sütundan oluşur.

### 5.2 Hazır dizi oluşturucular

NumPy dizi oluşturmak için hazır fonksiyonlar sunar (ekrandan, 00:55:00):

```python
a = np.zeros((2, 2))     # 2x2, bütün elemanları 0
b = np.ones((2, 2))      # 2x2, bütün elemanları 1
d = np.eye(4)            # 4x4 birim matris
c = np.full((3, 3), 5)   # 3x3, bütün elemanları 5
```

Birim matris kare olmak zorunda olduğu için `np.eye` tek bir boyut alır; ana köşegendeki elemanlar 1, diğerleri 0'dır. Karede `np.eye(4)` çıktısı ana köşegeni 1 olan 4x4 matris, `np.full((3,3),5)` çıktısı da bütün gözleri 5 olan 3x3 matristir.

### 5.3 Dizi dilimleme ve alt dizi

NumPy dizileri de listeler gibi dilimlenebilir; dizi çok boyutlu olduğu için her boyut için ayrı dilim verilir. Hoca bu örneğin kendisinin çok hoşuna gittiğini söyledi (ekrandan, 00:55:00):

```python
a = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])
b = a[:2, 1:3]
# b = [[2 3]
#      [6 7]]
print(a[0, 1])   # 2
b[0, 0] = 77
print(a[0, 1])   # 77
```

Matrisin satırları 1-2-3-4, 5-6-7-8 ve 9-10-11-12'dir. `a[:2, 1:3]` 0. ve 1. satırları, 1. ve 2. sütunları alır; sonuç 2, 3, 6, 7 elemanlarından oluşan `b` alt dizisidir (subarray). `b`'nin `[0, 0]` gözüne 77 atanınca ana matrisin bu göze karşılık gelen `a[0, 1]` gözü de 77 olur. Çünkü dilimle elde edilen alt dizi, ana dizinin aynı verisine bakar; alt dizide yapılan değişiklik ana diziyi de değiştirir.

> **Ek bilgi (derste anlatılmadı):** NumPy'da dilimleme verinin kopyasını değil, aynı belleğe bakan bir görünümünü (view) üretir. Ana diziyi etkilemeden çalışmak gerekiyorsa `b = a[:2, 1:3].copy()` ile açık bir kopya alınır.

Hoca ikinci bir inceliğe daha dikkat çekti:

```python
row_r1 = a[1, :]     # [5 6 7 8], shape (4,)
row_r2 = a[1:2, :]   # [[5 6 7 8]], shape (1, 4)
```

İkisinde de içerik aynı, 5-6-7-8'dir. Ama tam sayı indeksle alınan `row_r1` dört elemanlı bir dizi olarak, dilimle alınan `row_r2` ise bir satır dört sütunlu bir matris olarak tanımlanır ve ekrana iç içe iki köşeli parantezle yazılır.

> **Hocanın vurgusu:** Bu incelikler Python kullanırken önemlidir; şekil farkı ileride işlem sonuçlarını etkiler.

## 6. Veri Tipleri ve Dizi Matematiği

### 6.1 Veri tipleri

Her NumPy dizisi aynı tipte elemanlardan oluşur. NumPy dizi oluşturulurken içine konan sayılara bakarak veri tipini tahmin eder; istenirse tip `dtype` ile açıkça verilir (ekrandan, 01:10:00):

```python
x = np.array([1, 2])
print(x.dtype)       # tam sayı
x = np.array([1.0, 2.0])
print(x.dtype)       # float64
x = np.array([1, 2], dtype=np.int64)
print(x.dtype)       # int64
```

Tam sayılarla kurulan dizi tam sayı, `1.0, 2.0` gibi yazılan dizi ondalıklı sayı tipinde olur. Hoca, hangi tipte tanımlandığına dikkat edip sonucu da ona uygun beklemek gerektiğini söyledi.

> **Ders sonrası not:** Defterdeki yorum ilk satır için `int64` yazdığı hâlde hocanın ekranındaki çıktı `int32` idi (ekrandan, 01:10:00). Büyük olasılıkla bunun nedeni, eski NumPy sürümlerinde Windows'ta varsayılan tam sayı tipinin 32 bit olmasıdır. Tipin önemli olduğu yerde `dtype` açıkça verilmelidir.

### 6.2 Eleman eleman işlemler

Temel matematik fonksiyonları diziler üzerinde eleman eleman çalışır; hem operatör olarak hem NumPy fonksiyonu olarak kullanılabilir:

```python
x = np.array([[1, 2], [3, 4]], dtype=np.float64)
y = np.array([[5, 6], [7, 8]], dtype=np.float64)

print(x + y)          # np.add(x, y)       -> [[ 6.  8.] [10. 12.]]
print(x - y)          # np.subtract(x, y)  -> [[-4. -4.] [-4. -4.]]
print(x * y)          # np.multiply(x, y)  -> [[ 5. 12.] [21. 32.]]
print(x / y)          # np.divide(x, y)    -> [[0.2 0.33333333] [0.42857143 0.5]]
print(np.sqrt(x))     # [[1. 1.41421356] [1.73205081 2.]]
```

Eleman eleman çarpımda (elementwise product) karşılıklı gözler çarpılır: $1\cdot 5 = 5$, $2\cdot 6 = 12$, $3\cdot 7 = 21$, $4\cdot 8 = 32$. Bölme ve karekök de eleman eleman yapılır (ekrandan, 01:15:00).

### 6.3 İç çarpım ve matris çarpımı

> **Hocanın vurgusu:** MATLAB'ın aksine `*` matris çarpımı değil, eleman eleman çarpımdır. Vektörlerin iç çarpımı, matris-vektör ve matris-matris çarpımı `dot` ile yapılır.

```python
v = np.array([9, 10])
w = np.array([11, 12])

print(v.dot(w))       # 219
print(np.dot(v, w))   # 219

print(x.dot(v))       # [29 67]
print(np.dot(x, v))   # [29 67]

print(x.dot(y))       # [[19 22] [43 50]]
print(np.dot(x, y))
```

Hesaplar (ekrandan, 01:15:00):

- İç çarpım: $v\cdot w = 9\cdot 11 + 10\cdot 12 = 99 + 120 = 219$.
- Matris-vektör: $x\,v = [1\cdot 9 + 2\cdot 10,\ 3\cdot 9 + 4\cdot 10] = [29,\ 67]$.
- Matris-matris: birinci satır ile birinci sütun $1\cdot 5 + 2\cdot 7 = 19$, birinci satır ile ikinci sütun $1\cdot 6 + 2\cdot 8 = 22$, ikinci satır ile birinci sütun $3\cdot 5 + 4\cdot 7 = 43$, ikinci satır ile ikinci sütun $3\cdot 6 + 4\cdot 8 = 50$ (ara adım eklendi).

Hoca vektör elemanlarını "9, 10, 11, 12" diye art arda okudu; karede görüldüğü gibi bunlar `v = [9, 10]` ve `w = [11, 12]` olmak üzere iki ayrı vektördür.

### 6.4 Eksen boyunca hesaplama ve devrik

NumPy diziler üzerinde hızlı hesaplama için hazır fonksiyonlar sunar:

```python
x = np.array([[1, 2], [3, 4]])
print(np.sum(x))           # 10
print(np.sum(x, axis=0))   # [4 6]  her sütunun toplamı
print(np.sum(x, axis=1))   # [3 7]  her satırın toplamı
print(x.T)                 # [[1 3] [2 4]]
```

`axis=0` sütun doğrultusunda işlem yapar: birinci sütunda $1+3=4$, ikincide $2+4=6$. `axis=1` satır doğrultusunda işlem yapar. Hoca bunun toplamla sınırlı olmadığını, satır ya da sütun doğrultusunda ortalama gibi işlemlerin de aynı yolla yapıldığını söyledi. `.T` devrik (transpose) alır.

## 7. Yayma (Broadcasting)

Yayma, NumPy'ın aritmetik işlemlerde farklı şekildeki dizilerle çalışmasını sağlayan güçlü bir mekanizmadır. Hoca bunu bir matris ile bir vektör arasında işlem yapmak gibi düşünmeyi önerdi. Örnekte 4x3'lük bir `x` matrisinin her satırına `v` vektörü eklenir (ekrandan, 01:20:00):

```python
x = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]])
v = np.array([1, 0, 1])
y = np.empty_like(x)        # x ile aynı şekilde boş matris

for i in range(4):
    y[i, :] = x[i, :] + v

print(y)
# [[ 2  2  4]
#  [ 5  5  7]
#  [ 8  8 10]
#  [11 11 13]]
```

Hoca burada öğrencilere `x`'in boyutunu sordu (bkz. Örnek Sorular): `x` 4 satır 3 sütunludur, `v`'nin 3 elemanı vardır. Döngü dört satırın her biri için `y`'nin o satırını `x`'in o satırı ile `v`'nin toplamı yapar.

Hoca bu çözümün Python'da yavaş çalıştığını, `x` çok büyükse açık döngünün yavaş olacağını belirtti. Daha hızlı yol, `v`'yi dört kez alt alta kopyalayıp `x` ile aynı boyutta bir `vv` matrisi kurmak ve iki matrisi doğrudan toplamaktır:

```python
vv = np.tile(v, (4, 1))   # v'nin 4 satır boyunca kopyası
# [[1 0 1]
#  [1 0 1]
#  [1 0 1]
#  [1 0 1]]
y = x + vv
```

`vv` 4 satır 3 sütunlu, yani `x` ile aynı boyutlu bir matris olduğu için toplama eleman eleman yapılır ve sonuç döngüdekiyle aynıdır.

> **Ek bilgi (derste anlatılmadı):** Yayma kuralları sayesinde `vv` matrisini kurmaya da gerek yoktur: `y = x + v` yazıldığında NumPy `(3,)` şekilli `v`'yi `x`'in her satırına kendiliğinden uygular. Bu, hem bellek hem hız açısından en verimli yoldur.

## 8. Matplotlib ve scikit-image ile Görüntü Okuma, Gösterme ve Çizim

Matplotlib bir çizim kütüphanesidir; bu derste en çok `matplotlib.pyplot` modülü kullanılacak.

### 8.1 Görüntü okuma ve gösterme

```python
import matplotlib.pyplot as plt
import numpy as np
from skimage import io

# Read an JPEG image into a numpy array
image = io.imread('cat.jpg')
plt.imshow(image)

print(image.dtype, image.shape)   # uint8 (400, 248, 3)
```

Python kodunun bulunduğu klasördeki `cat.jpg` görüntüsü `io.imread` ile okunur ve `image` değişkenine bir matris olarak aktarılır; `plt.imshow` ile ekranda gösterilir (ekrandan, 01:25:00).

> **Hocanın vurgusu:** Veri tipi `uint8`, yani işaretsiz 8 bitlik tam sayıdır ve 0 ile 255 arasında değer alır. Bütün görüntü dosyalarında kullandığımız veri tipi budur; unutulmamalıdır.

Şekil `(400, 248, 3)`'tür: 400 satır, 248 sütun ve 3 renk kanalı. `imshow` çıktısındaki eksenlerde görüldüğü gibi matrisin `[0, 0]` gözü görüntünün sol üst köşesidir; sütunlar sağa, satırlar aşağı doğru artar. Görüntülenen her piksel üç baytla kodlanır; bu üç bayt kırmızı (R), yeşil (G) ve mavi (B) kanallarının değerlerini tutar.

Hoca ikinci örnekte farklı bir klasörden görüntü okumayı gösterdi: defterin bulunduğu klasörün bir üstündeki bir test görüntüleri klasöründen `balloon.jpg` okunmuştur (ekrandan, 02:10:00):

```python
%matplotlib inline
import matplotlib.pyplot as plt
import numpy as np
from skimage import io

image = io.imread('../images/balloon.jpg')
plt.imshow(image);
```

Bu görüntü için tip `numpy.ndarray`, veri tipi `uint8`, şekil 300 satır, 225 sütun ve 3 kanal olarak yazdırıldı. En küçük değer 0, en büyük değer 255'tir; yani işaretsiz 8 bitlik tam sayının alabileceği en küçük ve en büyük değerlerin ikisi de görüntüde vardır.

### 8.2 Çizim (plotting)

Matplotlib'in en önemli fonksiyonu `plot`'tur ve 2B veri çizmeyi sağlar (ekrandan, 01:30:00):

```python
x = np.arange(0, 3 * np.pi, 0.1)
y = np.sin(x)
plt.plot(x, y)
plt.show()
```

`np.pi` NumPy'da tanımlı $\pi$ sayısıdır. `np.arange(0, 3*np.pi, 0.1)` 0'dan $3\pi$'ye kadar 0.1 aralıklarla bir sayı dizisi üretir; `np.sin` bu dizinin sinüsünü alır. Yatay eksene örnekleme noktaları, dikey eksene sinüs değerleri konur. Sinüsün tam periyodu $2\pi$ olduğu için grafik bir buçuk periyot gösterir.

Aynı grafiğe kosinüs de eklenebilir. `plt.xlabel`, `plt.ylabel` ile eksen etiketleri, `plt.title` ile başlık, `plt.legend` ile hangi eğrinin hangi işarete ait olduğu yazılır. Hocanın çıktısında mavi eğri sinüsü, turuncu eğri kosinüsü gösteriyordu.

### 8.3 Alt çizimler (subplot)

Aynı şeklin içinde birden fazla pencere açmak için `subplot` kullanılır (ekrandan, 01:35:00):

```python
x = np.arange(0, 3 * np.pi, 0.1)
y_sin = np.sin(x)
y_cos = np.cos(x)

plt.subplot(2, 1, 1)     # 2 satır, 1 sütun; birinci çizim etkin
plt.plot(x, y_sin)
plt.title('Sine')

plt.subplot(2, 1, 2)     # ikinci çizim etkin
plt.plot(x, y_cos)
plt.title('Cosine')

plt.show()
```

`subplot(2, 1, 1)` iki satır bir sütunluk bir düzen kurar ve birinci pencereyi etkin yapar; ardından yapılan `plot` üstteki pencereye çizilir. `subplot(2, 1, 2)` ile ikinci pencereye geçilir.

Hoca deftere kendi eklediği bir örnekte, okunan balon görüntüsünü ve onun gri halini yan yana gösterdi. `plt.subplot(1, 2, 1)` ile bir satır iki sütunluk düzenin ilk gözüne renkli görüntü, `plt.subplot(1, 2, 2)` ile ikinci gözüne scikit-image'in hazır `rgb2gray` fonksiyonuyla griye çevrilmiş görüntü konur.

> **Hocanın vurgusu:** Gri tonlu bir görüntü `imshow` ile gösterilirken `cmap='gray'` parametresi, yani bir renk haritası verilmelidir. Ancak o zaman görüntü gri tonlarda görülür.

## 9. Görüntü Dosyası Türleri

Hoca bu bölümü tablet üzerinde çevrim içi bir beyaz tahta uygulamasıyla anlattı. Gerekçesi şuydu: Derin öğrenme çerçevesiyle görüntü üzerinde çok çeşitli işlemler yapabilen ama bir görüntü matrisini hiç açıp okumamış, RGB ya da gri görüntünün ne olduğunu bilmeyen biri sağlıklı bir yolda değildir. Görüntü dosyasının yapısını bilmek gerekir.

### 9.1 Siyah-beyaz görüntü

Siyah-beyaz (black and white, ikili) görüntüde her piksel 1 bit ile kodlanır (ekrandan, 01:55:00). Piksel ya 0 ya 1'dir: 0 siyah, 1 beyazdır. Ara gri ton yoktur. Bu piksel bir mantıksal değişken gibi de tutulabilir. Bu biçim faks makinesi gibi cihazlarda kullanılır.

### 9.2 Gri tonlu görüntü

Gri tonlu (grayscale) görüntüde her piksel 8 bit ile kodlanır. 0 siyahı, 255 beyazı gösterir; aradaki değerler gri tonlardır. Her pikseli kodlamak için `uint8` yapısı kullanılır.

### 9.3 Renkli görüntü

Renkli görüntü aslında üç matristen oluşur: kırmızı, yeşil ve mavi kanallar. Her kanal için 8 bit kullanıldığından bir piksel 3 bayt, yani piksel başına 24 bittir ($3 \times 8$). Bitmap (BMP) dosyalarında sıkıştırma yoktur, görüntü ham haliyle saklanır. Hoca BMP'nin bir de ayrılmış (reserved) bayt kullandığını ve bu yüzden bir pikseli saklamak için 4 bayt (32 bit) harcadığını söyledi.

> **Ders sonrası not:** Hoca BMP'nin her pikseli 4 bayt ile sakladığını söyledi. Büyük olasılıkla bu yalnız 32 bitlik BMP türü için doğrudur. Yaygın 24 bitlik BMP'de piksel 3 bayttır; ayrılmış bayt renk tablosu girdilerinde (mavi, yeşil, kırmızı, ayrılmış) bulunur ve her satır 4 baytın katına tamamlanır.

### 9.4 Dizinli renkli görüntü

24 bit ile $2^{24} = 16\,777\,216$, yani yaklaşık 16 milyon farklı renk oluşturulabilir. İnsan gözünün bu kadar rengi ve renk farkını algılama kapasitesi yoktur; o zaman bu kadar rengi tutmaya gerek yoktur. Dizinli renkli görüntüde (indexed color image) yalnız görüntüde en çok kullanılan renkler saklanır (ekrandan, 02:00:00).

Dosya yapısı üç bölümden oluşur:

```text
+-------------+---------------------------+---------------------------+
| Dosya       | Renk tablosu              | Veri                      |
| başlığı     | 256 satır (0..255)        | piksel başına 8 bit       |
|             | her satır R, G, B (24 bit)| (renk tablosu indeksi)    |
+-------------+---------------------------+---------------------------+
```

- **Dosya başlığı (file header):** Bütün görüntü dosyalarında bulunur; görüntünün çözünürlüğü (kaç satır, kaç sütun), renkli mi gri mi olduğu gibi bilgiler burada tutulur.
- **Renk tablosu (color table):** 0'dan 255'e 256 satırdır. Her satırda görüntüde en çok kullanılan renklerden birinin kırmızı, yeşil ve mavi değerleri, yani 3 bayt (24 bit) tutulur.
- **Veri:** Her piksel için 8 bit kullanılır, ama bu 8 bit doğrudan renk değil, renk tablosunun indeksidir.

Örneğin bir pikselin rengi renk tablosunun 25. satırındaki renk ise o piksele yalnız 25 yazılır; görüntülenirken 25. satırdaki kırmızı-yeşil-mavi değerleri alınır ve pikselin rengi bunlarla oluşturulur. İndeks 0 ile 255 arasında olduğu için 8 bitle kodlanabilir. Böylece 16 milyon renkten 256 renge inilir; hoca 256 rengin bir renkli görüntüyü ifade etmeye yettiğini, bu yüzden bu biçimin bir tür sıkıştırılmış dosya biçimi sayılabileceğini söyledi.

### 9.5 JPEG, TIFF ve DICOM

JPEG de sıkıştırılmış bir biçimdir: Bir renk nicemleme (color quantization) yapılır ve en çok kullanılan renklere daha kısa kod verilir. JPEG kayıplı (lossy) bir sıkıştırmadır (ekrandan, 02:05:00). Orijinal renkler mutlaka bozulur ve sıkıştırılmış bileşenlerden orijinale geri dönülemez; JPEG ile sıkıştırılan bir dosyanın kalitesi kalıcı olarak düşer.

Bu yüzden tıbbi görüntülerle çalışırken fazla sıkıştırma yapılmaz; TIFF uzantılı dosyalar daha çok kullanılır. Tomografi ve MR görüntülerinde DICOM dosya biçimi kullanılır ve bir piksel 16 bitte tutulur: `uint8` yerine `uint16`. Bunun nedeni gri tonlamada daha yüksek hassasiyet gerekmesidir; her gri ton hastalıkla ilgili bir bilgi taşıyor olabilir.

> **Hocanın vurgusu:** Temelde bu dört biçimi (siyah-beyaz, gri, renkli, dizinli renkli) ve aralarındaki farkı bilmek gerekir. Bu konuda proje yapan herkes çalıştığı görüntü veri tabanının biçimi hakkında bir iki şey söyleyebilmelidir.

**Soru:** Bazı monitörler aynı rengi yüzde yüz doğru gösteremiyor ve farklı fiyatlara satılıyor; tasarımcılar bu yüzden belli monitörleri tercih ediyor. Bu, anlatılan konuyla mı ilgili?

**Cevap:** Orada ekran çözünürlüğü ve görüntüleme teknolojisi daha çok önem kazanıyor olabilir; bu bambaşka bir teknolojidir. Burada anlatılan konu, görüntünün diskte nasıl saklandığıdır. Saklama biçimi çalışılan alana göre seçilir: tıbbi görüntülerde hassasiyet daha yüksek tutulur, sıradan bir nesne tanıma işleminde JPEG kullanılabilir ama başka bir alanda JPEG tercih edilmeyebilir. Buna karşılık JPEG'in sıkıştırma başarımı çok yüksektir; BMP ile JPEG arasındaki fark ve sıkıştırma kalitesinin etkisi ileride uygulamalarla gösterilecektir.

## 10. Görüntü Üzerinde Temel İşlemler

Bu bölüm ve sonrası, gelecek hafta devam edilecek bir sunumun başıdır; konu görüntüyü anlamaya (image understanding) giriştir.

### 10.1 Yeniden boyutlandırma, çevirme ve kırpma

Görüntü farklı kütüphanelerle açılıp okunabilir; derste scikit-image'in `io` modülü kullanıldı. Bu modül standart görüntü biçimlerini okur. Okunan görüntü matrisi üzerinde yeniden boyutlandırma (resize), çevirme (flip) ve kırpma (crop) yapılabilir. Hoca bir gül görüntüsünden belli bir bölgeyi kırpıp sonra çevirerek ekranda göstermişti. Bu işlemler basit matris dilimleme ile yapılabilir; aynı işler için `rescale` gibi hazır fonksiyonlar da vardır.

Hoca öğrencilerden kırpma ve çevirmeyi yalnız dilimleme ile denemelerini istedi:

- **Çevirme:** Matris son gözden ilk göze doğru $-1$ adımlarla taranabilir (örneğin satırlar için `img[::-1, :]`).
- **Kırpma:** Görüntünün boyutu bilindiği için sayısal değer vermeden yalnız oranla bir bölge kesilebilir; örneğin her iki eksende boyutun üçte birinden başlayıp üçte ikisine kadar olan bölge.

### 10.2 İşlenmiş görüntüyü kaydetme

İşlenen görüntü `io.imsave` ile kaydedilir (ekrandan, 02:15:00):

```python
%matplotlib inline
from matplotlib import pyplot as plt
from skimage import io

d = "..\\..\\TestImages"
image = io.imread(d + "/balloon.jpg")
print(type(image))
plt.imshow(image);
io.imsave('yeni.jpg', image)
io.imsave('yeni.jpg20', image, quality=20)
```

JPEG olarak kaydederken bir kalite çarpanı (`quality`) verilebilir; 0 ile 100 arasında değer alır. Hoca 20, 40, 60, 80 gibi değerlerle kaydedip hem elde edilen görüntüyü hem de dosyanın diskte ne kadar yer tuttuğunu karşılaştırmayı önerdi.

### 10.3 Renk kanallarını ayrı inceleme

Renkli görüntünün `shape`'inde üç boyut vardır; üçüncü boyut renk kanalını gösterir: 0 kırmızı, 1 yeşil, 2 mavi. Her kanal ayrı bir gri görüntü gibi alınıp `plt.subplot(1, 4, ...)` ile bir satır dört sütunluk bir alanda (renkli görüntü ve üç kanal) yan yana gösterilebilir.

### 10.4 RGB'den gri tona dönüşüm

Renkli bir görüntüyü yalnız parlaklık değerine, yani gri tona dönüştürmek için bir ağırlıklı toplam kullanılır. Hoca katsayıları kırmızı için 0.21, yeşil için 0.71, mavi için 0.07 olarak verdi:

$$
I \approx 0.21\,R + 0.71\,G + 0.07\,B
$$

Bu katsayılar insan gözünün hangi renge daha duyarlı olduğunu gösterir. Toplamları yaklaşık 1'dir, yani bir normalizasyon gibi düşünülebilir. Göz en çok yeşile duyarlı olduğu için yeşilin ağırlığı en büyüktür, en az maviye duyarlı olduğu için mavinin ağırlığı en küçüktür. Dönüşüm her piksel için elle yapılabilir; scikit-image'in hazır `rgb2gray` fonksiyonu da aynı işi yapar.

<!-- BELİRSİZ: Katsayıların gösterildiği slaytın karesi yok; değerler altyazıdan alındı. -->

> **Ders sonrası not:** Hoca yeşilin katsayısını 0.71 söyledi; bu durumda toplam 0.99 olur. Büyük olasılıkla doğrusu 0.72'dir: yaygın kullanılan ITU-R BT.709 katsayıları $0.2126\,R + 0.7152\,G + 0.0722\,B$'dir ve scikit-image'in `rgb2gray` fonksiyonu $0.2125\,R + 0.7154\,G + 0.0721\,B$ kullanır; bu katsayıların toplamı 1'dir.

### 10.5 Pikselin komşuluğu

Görüntü matrisinin orijini sol üst köşe olduğuna göre her pikselin komşuları bellidir. Komşular kuzey, güney, kuzeydoğu, kuzeybatı gibi yönlerle de tarif edilir. Bir piksel 8 komşusuyla birlikte 3x3'lük bir matris oluşturur. Bu tür konum bilgisine dayanan işlemlere uzamsal alan (spatial domain) işlemleri denir.

## 11. Yoğunluk Dönüşümleri

### 11.1 Tanım

Görüntünün parlaklık değerlerini dönüştürmeye yoğunluk dönüşümü (intensity transformation) denir. Slayttaki genel ifade şudur (ekrandan, 02:20:00):

$$
g(x,y) = T[f(x,y)]
$$

Burada $f(x,y)$ giriş görüntüsü, $g(x,y)$ işlenmiş çıkış görüntüsü, $T$ ise $(x,y)$ noktasının belli bir komşuluğu üzerinde tanımlı bir operatördür. Yoğunluk dönüşüm fonksiyonları çoğu zaman basitleştirilmiş biçimde yazılır:

$$
s = T(r)
$$

$r$, $f$'nin; $s$, $g$'nin aynı noktadaki parlaklık değeridir. Grafiklerde yatay eksen giriş parlaklığı $r$, dikey eksen çıkış parlaklığı $s$'dir. Eksende sola gidildikçe piksel koyulaşır (dark, siyaha yakın), sağa gidildikçe aydınlanır (light, beyaza yakın). Dönüşüm fonksiyonu bilinirse her giriş değeri için çıkış değeri hesaplanabilir.

Slayttaki şekilde iki fonksiyon vardır: (a) kontrast germe (contrast-stretching) fonksiyonu, S biçimli bir eğri; (b) eşikleme (thresholding) fonksiyonu, $k$ noktasında basamak yapan bir fonksiyon.

### 11.2 Eşikleme

Girişte 0 ile 255 arasında bütün gri tonları içeren bir görüntü olsun. Eşikleme fonksiyonu $k$'ya kadar olan bütün değerleri 0'a (siyaha), $k$'dan büyük bütün değerleri en yüksek değere (beyaza) çevirir. Böylece gri tonlu görüntüden siyah-beyaz, yani ikili (binary) görüntü elde edilir. Hoca bunu yoğunluk dönüşümü için güzel bir örnek olarak verdi (bkz. Örnek Sorular).

### 11.3 Temel dönüşüm eğrileri

Slayttaki şekilde temel yoğunluk dönüşüm eğrileri birlikte çizilmiştir (ekrandan, 02:25:00). İki eksen de $0$ ile $L-1$ arasındadır. Bu ölçek 0-255 olarak ya da normalize edilmişse 0-1 olarak düşünülebilir. Şekildeki eğriler:

- **Negatif:** $(0, L-1)$'den $(L-1, 0)$'a inen doğru; görüntünün negatifini verir.
- **Özdeşlik (identity):** Köşegen doğru; çıkış girişin aynısıdır.
- **Log ve n'inci kök:** Köşegenin üstünde kalan eğriler.
- **Ters log ve n'inci kuvvet:** Köşegenin altında kalan eğriler.

Hoca bir eğrinin etkisini okumanın yolunu şöyle anlattı: giriş ekseninin tam ortasındaki $L/2$ değeri alınır, eğriyle kesiştiği noktaya çıkılır ve bu değerin çıkışta ortalamanın üstüne mi altına mı taşındığına bakılır. Log eğrisi $L/2$'yi $L-1$'e yakın bir noktaya taşır; bu yüzden görüntüyü aydınlatır.

> **Hocanın vurgusu:** Her eğrinin görüntü üzerinde farklı bir etkisi vardır. Eğriye bakarak nasıl bir etki yaptığını söyleyebilmek beklenmektedir.

### 11.4 Gama eğrileri

Gama (kuvvet yasası) dönüşümü şöyle yazılır:

$$
s = c\, r^{\gamma}
$$

Burada $r$ 1'e normalize edilmiş giriş değeridir; hoca buna dikkat çekti. Slaytta $\gamma > 1$ ve $\gamma < 1$ durumlarının eğrileri ayrı ayrı verilmiştir. $\gamma < 1$ olan eğriler köşegenin üstünde kalır ve aydınlatır; $\gamma > 1$ olanlar köşegenin altında kalır ve karartır. Seçilen gamaya göre görüntüde aydınlatma ya da karartma etkisi elde edilir.

> **Ek bilgi (derste anlatılmadı):** Normalize edilmiş $r \in [0,1]$ için $r^{\gamma}$, $\gamma<1$ iken $r$'den büyük, $\gamma>1$ iken $r$'den küçüktür ($r=0$ ve $r=1$ uç noktaları değişmez). Etkinin yönü bu yüzden yalnız $\gamma$'nın 1'den büyük ya da küçük olmasına bağlıdır.

### 11.5 Gama ile iki örnek

Slayttaki ilk örnekte (a)-(d) olmak üzere dört görüntü vardır. (a) omurgadan alınmış bir MR görüntüsüdür; oldukça karanlıktır ve arka taraftaki karanlık bölgedeki ayrıntılar görülemez. Aydınlatma etkisi olan eğriler $\gamma < 1$ olanlardır. Görüntü sırasıyla $\gamma = 0.6$, $0.4$ ve $0.3$ ile dönüştürülmüş; omurganın arka bölümündeki görünmeyen ayrıntılar giderek daha görünür hale gelmiştir.

İkinci örnekte sorun tersinedir: Bir uçaktan çekilmiş bir hava fotoğrafı (aerial image) fazla aydınlık, "patlamış" bir görüntüdür. Karartmak için $\gamma > 1$ olan değerler, $\gamma = 3$, $4$ ve $5$ ile dönüşüm uygulanmıştır.

## 12. Bit Düzlemi Dilimleme

Bit düzlemi dilimleme (bit plane slicing) basit bir işlemdir; hoca öneminin tartışılabileceğini, ama görüntü matrisleriyle oynayabilmek için anlatacağını söyledi.

Pikseller bitlerden oluşan sayılardır. Örneğin 256 seviyeli gri bir görüntüde her pikselin parlaklığı 8 bitten, yani bir bayttan oluşur (ekrandan, 02:30:00). Bütün piksellerin aynı sıradaki biti bir araya getirilince bir bit düzlemi oluşur; en düşük anlamlı bitten (bit düzlemi 1) en yüksek anlamlı bite (bit düzlemi 8) kadar sekiz düzlem vardır. Parlaklık aralıklarını vurgulamak yerine, belli bitlerin görüntünün toplam görünümüne katkısı vurgulanabilir.

- **En düşük anlamlı bit (LSB):** İçinde en fazla gürültü olan bittir.
- **En yüksek anlamlı bit (MSB):** En fazla bilgiyi taşır; orijinal görüntüye en çok benzeyen düzlemdir.

Slayttaki örnekte bir 100 dolarlık banknotun görüntüsü için bit düzlemleri en düşük anlamlı bitten başlayarak gösterilmiştir. Görüntü 500 x 1192 pikselden oluşan 8 bitlik gri bir görüntüdür.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:20:18): Yayma örneğindeki `x = np.array([[1,2,3],[4,5,6],[7,8,9],[10,11,12]])` matrisi kaça kaçtır?

> **Cevap (derste verildi):** 4x3'tür: 4 satır, 3 sütun. `v = [1, 0, 1]` vektörünün 3 elemanı vardır; bu yüzden `v`, `x`'in her satırına eklenebilir.

**Soru 2** (derste sözlü, 02:21:36; ekrandan, 02:20:00): Slayttaki sağdaki dönüşüm fonksiyonu ne iş yapar? $k$'ya kadar olan bütün giriş değerlerini çıkışta neye dönüştürür?

> **Cevap (derste verildi):** Bu bir eşikleme fonksiyonudur. $k$'ya kadar olan bütün değerleri 0'a, yani siyaha; $k$'dan büyük bütün değerleri en yüksek değere, yani beyaza çevirir. Sonuçta gri tonlu görüntüden siyah-beyaz (ikili) bir görüntü elde edilir. Derste bir öğrenci eğriyi sınıflandırmada kullanılan sigmoid fonksiyonuna benzetti; bu benzetme soldaki S biçimli kontrast germe eğrisine uyar. Hoca kontrast ile ilgili bir soruya da bu fonksiyonun tek yaptığı işin ikili görüntü üretmek olduğunu söyledi.

**Soru 3** (derste sözlü, 02:24:25; ekrandan, 02:25:00): Log dönüşüm eğrisinin görüntü üzerindeki etkisi nedir? Görüntüyü aydınlatır mı, karartır mı?

> **Cevap (derste verildi):** Aydınlatır. Giriş ekseninin ortasındaki $L/2$ değerinden eğriye çıkılınca ulaşılan çıkış değeri $L-1$'e (255'e) yakındır; orta parlaklık ortalamanın üstüne taşındığı için görüntü daha aydınlık olur.

**Soru 4** (derste sözlü, 02:31:30; ekrandan, 02:30:00): 500 x 1192 piksellik, 8 bitlik gri 100 dolar görüntüsünün sekiz bit düzlemini ayrı ayrı oluşturup gösterin.

> **Çözüm (derste verilmedi):** Her bit düzlemi, piksel değerinin ilgili bit kadar sağa kaydırılıp 1 ile maskelenmesiyle bulunur. Aşağıdaki kod, rastgele bir `uint8` matris üzerinde sekiz düzlemin bitlerinden orijinal görüntünün yeniden kurulabildiği denetlenerek ajan tarafından test edildi; görüntü dosyasının adı örnektir.
>
> ```python
> import matplotlib.pyplot as plt
> from skimage import io
>
> img = io.imread('dolar.tif')          # 8 bitlik gri görüntü (uint8)
> planes = [(img >> k) & 1 for k in range(8)]   # k=0: LSB, k=7: MSB
>
> for k in range(8):
>     plt.subplot(2, 4, k + 1)
>     plt.imshow(planes[k], cmap='gray')
>     plt.title('Bit düzlemi %d' % (k + 1))
>     plt.axis('off')
> plt.show()
> ```

**Soru 5** (derste sözlü, 02:12:28): Bir görüntüyü hazır fonksiyon kullanmadan, yalnız dilimleme ile ters çevirin ve boyutun üçte birinden üçte ikisine kadar olan bölgeyi kırpın.

> **Çözüm (derste verilmedi):** Ters çevirmede $-1$ adımlı dilim kullanılır; kırpmada sınırlar boyuttan oranla hesaplanır. Kod küçük bir `uint8` matris üzerinde ajan tarafından denendi.
>
> ```python
> h, w = img.shape[:2]
> ters_dikey = img[::-1, :]      # satırları tersten (baş aşağı)
> ters_yatay = img[:, ::-1]      # sütunları tersten (ayna)
> kirpik = img[h // 3: 2 * h // 3, w // 3: 2 * w // 3]
> ```

## Dersin Toparlaması

Bu derste önce dönem boyunca kullanılacak araçlar tanıtıldı: Python'un temel tipleri ve kapları, NumPy dizileri, şekil ve veri tipi kavramları, eleman eleman işlemler ile `dot` arasındaki fark, eksen boyunca hesaplama, yayma, Matplotlib ile çizim ve scikit-image ile görüntü okuma. Bir görüntünün NumPy'da `(satır, sütun, kanal)` şekilli, `uint8` tipli bir dizi olduğu ve $(0,0)$ noktasının sol üst köşe olduğu vurgulandı. Ardından siyah-beyaz, gri, renkli ve dizinli renkli görüntülerin dosyada nasıl tutulduğu, JPEG'in kayıplı olduğu ve tıbbi görüntülerde 16 bitlik biçimlerin neden tercih edildiği anlatıldı.

Son bölümde uzamsal alanda yoğunluk dönüşümlerine geçildi: $s=T(r)$ gösterimi, eşikleme, negatif, log ve gama eğrileri ile bit düzlemi dilimleme. Hoca bir sonraki derste basit filtrelerle görüntü üzerinde filtreleme işlemlerine, yani konvolüsyon filtrelerine ve etkilerine geçileceğini; önce konvolüsyonun tahtada basit örneklerle nasıl çalıştığının, sonra Python'da nasıl yapıldığının gösterileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
