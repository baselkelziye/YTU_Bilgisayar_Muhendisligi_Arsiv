# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin uygulama ortamı: Python, NumPy, Matplotlib ve scikit-image
  - Dersin bütün uygulamaları Python'da, NumPy kütüphanesi üzerinden yapılır. Görüntü okuma ve işleme için scikit-image (`skimage`), çizim için Matplotlib (`pyplot`) kullanılır.
  - Kaynak olarak Stanford CS231n (Convolutional Neural Networks for Visual Recognition) dersinin "Python Numpy Tutorial (with Jupyter and Colab)" sayfası izlenir (ekrandan, 00:20:00).
  - Çalışma ortamı olarak Anaconda altında Jupyter Notebook ya da Spyder önerilir. Kurulum yoksa Google Colab kullanılabilir. Jupyter, metin ile kodu aynı belgede birleştirdiği için ders notu ve rapor hazırlamaya uygundur.
  - Görüntü matrisinin düşük seviyedeki yapısını bilmek, hazır çerçevelerle (framework) çalışırken yanlış fonksiyon ve veri tipi seçimlerini önler.
- Python'un temel veri tipleri
  - Tam sayı (int), ondalıklı sayı (float), mantıksal (bool) ve metin (str). Değişkenin tipi atanan değerden otomatik belirlenir; `type()` ile görülür.
  - Mantıksal işlemler `and`, `or`, `not` gibi sözcüklerle yazılır.
  - Metin işlemleri: `len`, birleştirme (`+`), `capitalize`, `center`, `replace`, `strip` (ekrandan, 00:25:00; 00:30:00).
- Python kapları (container): liste, sözlük, küme, demet
  - Liste boyutu değişebilen ve farklı tipte eleman tutabilen bir dizidir. İndeks 0'dan başlar, `-1` son elemandır. `append`, `pop` ve dilimleme (slicing) desteklenir.
  - Liste üreteci (list comprehension) ile kısa döngüler ve koşullu süzme yapılabilir (ekrandan, 00:40:00).
  - Sözlük (dictionary) anahtar-değer çiftleri tutar; ekleme, silme (`del`), üyelik denetimi (`in`) ve döngü ile gezinme yapılır (ekrandan, 00:45:00).
  - Küme (set) sırasız ve tekrarsız elemanlardan oluşur.
  - Fonksiyon `def` ile, sınıf `class` ile tanımlanır.
- NumPy dizileri
  - NumPy dizisi aynı tipte elemanlardan oluşan bir ızgaradır ve negatif olmayan tam sayılardan oluşan bir demetle indekslenir.
  - `shape` ile boyut görülür: `np.array([1,2,3,4])` için `(4,)`, `np.array([[1,2,3,4]])` için `(1, 4)` (ekrandan, 00:50:00).
  - Hazır dizi oluşturucular: `np.zeros`, `np.ones`, `np.eye`, `np.full` (ekrandan, 00:55:00).
  - Dizi dilimleme alt dizi (subarray) verir; alt dizide yapılan değişiklik ana diziyi de değiştirir.
  - Veri tipi NumPy tarafından tahmin edilir ya da `dtype` ile zorlanır (ekrandan, 01:10:00).
  - Dizi matematiği eleman eleman işler: `+`, `-`, `*`, `/`, `np.sqrt`. Gerçek matris çarpımı `dot` ile yapılır (ekrandan, 01:15:00).
  - `np.sum` ile toplam, `axis=0` ile sütun toplamı, `axis=1` ile satır toplamı alınır; `.T` devriktir.
  - Yayma (broadcasting): farklı boyutlu diziler arasında aritmetik işlem (ekrandan, 01:20:00).
- Matplotlib ve scikit-image ile görüntü okuma, gösterme ve çizim
  - `io.imread` ile okunan görüntü bir NumPy dizisidir; örnek kedi görüntüsü `uint8 (400, 248, 3)` (ekrandan, 01:25:00).
  - `plt.plot` ile 2B veri çizimi, eksen etiketi, başlık, açıklama (legend) ve `plt.subplot` ile alt çizimler (ekrandan, 01:30:00; 01:35:00).
  - `color.rgb2gray` ile renkli görüntü griye çevrilir, gri görüntü `cmap='gray'` ile gösterilir.
- Görüntü dosyası türleri
  - Siyah-beyaz (binary) görüntü: piksel başına 1 bit; 0 siyah, 1 beyaz (ekrandan, 01:55:00).
  - Gri tonlu görüntü: piksel başına 8 bit (`uint8`); 0 siyah, 255 beyaz.
  - Renkli görüntü: kırmızı, yeşil, mavi (RGB) olmak üzere üç kanal; piksel başına 3 bayt (24 bit). BMP sıkıştırmasız saklar ve hocanın anlatımıyla bir ayrılmış bayt ile piksel başına 4 bayt kullanır.
  - Ders sonrası not: Hoca BMP'nin her pikseli 4 bayt (32 bit) ile sakladığını söyledi. Büyük olasılıkla bu yalnız 32 bitlik BMP türü için doğrudur; yaygın 24 bitlik BMP pikseli 3 bayt tutar, ayrılmış bayt ise renk tablosu girdilerinde (mavi, yeşil, kırmızı, ayrılmış) bulunur ve satırlar 4 baytın katına tamamlanır.
  - Dizinli renkli görüntü (indexed color): dosya başlığı + 256 satırlı renk tablosu + veri. Her piksel renk tablosunun 8 bitlik indeksini tutar (ekrandan, 02:00:00).
  - JPEG kayıplı sıkıştırmadır (ekrandan, 02:05:00). Tıbbi görüntülerde TIFF ve piksel başına 16 bit kullanan DICOM tercih edilir.
- Görüntü üzerinde temel işlemler
  - Okuma, gösterme, yeniden boyutlandırma, çevirme (flip), kırpma (crop), kaydetme (`io.imsave`, JPEG için `quality`) (ekrandan, 02:10:00; 02:15:00).
  - RGB kanallarını ayrı ayrı gri görüntü gibi gösterme; RGB'den griye ağırlıklı dönüşüm.
  - Pikselin komşuluğu: 8 komşu ile 3x3'lük bölge, uzamsal alan (spatial domain).
- Yoğunluk dönüşümleri (intensity transformation)
  - $g(x,y)=T[f(x,y)]$, basit biçimiyle $s=T(r)$ (ekrandan, 02:20:00).
  - Kontrast germe ve eşikleme fonksiyonları; negatif, özdeşlik, log, ters log, n'inci kök ve n'inci kuvvet eğrileri (ekrandan, 02:25:00).
  - Gama dönüşümü $s=c\,r^{\gamma}$: $\gamma<1$ aydınlatır, $\gamma>1$ karartır.
  - Bit düzlemi dilimleme (bit plane slicing) (ekrandan, 02:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Görüntü matrisinin yapısını bilmek
  - Bir görüntüyü hiç açıp okumadan, RGB ile gri görüntü farkını bilmeden derin öğrenme çerçevesiyle işlem yapmak sağlıklı değildir. Yapıyı bilen kişi doğru fonksiyon ve veri tipini seçer.
- `uint8` veri tipi
  - Görüntü dosyalarında her piksel işaretsiz 8 bitlik tam sayıdır, 0 ile 255 arasında değer alır. Hoca bunun unutulmamasını özellikle istedi.
- `shape` farkı: dizi, satır vektörü ve matris
  - Tek köşeli parantezle kurulan dizi `(4,)`, iki köşeli parantezle kurulan `(1, 4)` biçimindedir. İçerik aynı olsa da şekil farklıdır.
  - `a[1, :]` dört elemanlı dizi `(4,)`, `a[1:2, :]` bir satır dört sütunlu matris `(1, 4)` verir.
- Dilimlemenin ana diziyi etkilemesi
  - Dilimle alınan alt dizi ana dizinin bir görünümüdür; alt dizide yapılan değişiklik ana dizide de görülür.
- `*` matris çarpımı değildir
  - `*` eleman eleman çarpımdır; matris-matris ve matris-vektör çarpımı `dot` ile yapılır.
- Gri görüntüyü gösterirken `cmap='gray'`
  - Renk haritası verilmezse gri görüntü gri tonlarda görünmez.
- Görüntü formatları arasındaki fark
  - Siyah-beyaz, gri, renkli ve dizinli renkli görüntü arasındaki fark ve görüntü veri tabanının formatı hakkında konuşabilmek gerekir.
  - JPEG kayıplıdır; orijinale geri dönüş yoktur. Tıbbi görüntülerde hassasiyet için 16 bit kullanılır.
- Dönüşüm eğrisini yorumlayabilmek
  - Bir yoğunluk dönüşüm eğrisinin etkisi, giriş ekseninin ortasındaki $L/2$ değerinin çıkışta nereye taşındığına bakılarak söylenebilmelidir.
- Uygulamaları kendi elinizle yazmak
  - Hoca örneklerin Jupyter ya da Spyder'da adım adım yeniden yazılmasını, kırpma ve çevirmenin yalnız dilimlemeyle denenmesini istedi.

## Kısa Tekrar Notları

- Python'da değişken tipi atamadan belirlenir; `type()` ile görülür.
- Liste: farklı tipte eleman tutabilir, `append` ile büyür, indeks 0'dan başlar, `-1` son eleman.
- Dilim `a[başlangıç:bitiş]` bitişi içermez (exclusive).
- Sözlük anahtar-değer tutar; küme sırasız ve tekrarsızdır.
- NumPy dizisi tek tiplidir; `shape`, `dtype` önemlidir.
- `np.zeros`, `np.ones`, `np.eye`, `np.full` hazır dizi oluşturur.
- Alt dizide yapılan değişiklik ana diziyi değiştirir.
- `*` eleman eleman çarpım, `dot` matris çarpımı.
- `axis=0` sütun boyunca, `axis=1` satır boyunca işlem yapar.
- Yayma (broadcasting) farklı boyutlu dizilerle işlem yapmayı sağlar; Python döngüsü büyük matrislerde yavaştır.
- Görüntü pikseli `uint8`: 0-255. Renkli görüntünün `shape` değeri (satır, sütun, 3).
- Görüntünün (0,0) noktası sol üst köşedir.
- Siyah-beyaz 1 bit/piksel, gri 8 bit/piksel, renkli 24 bit/piksel, DICOM 16 bit gri.
- Dizinli renkli görüntü: 256 renklik tablo, piksel başına 8 bitlik indeks.
- JPEG kayıplı sıkıştırmadır.
- $s=T(r)$; eşikleme $k$'nın altını 0, üstünü 1 yapar.
- Log eğrisi aydınlatır; gama $\gamma<1$ aydınlatır, $\gamma>1$ karartır.
- En anlamlı bit düzlemi en çok bilgiyi, en anlamsız bit düzlemi en çok gürültüyü taşır.

## Detaylı Açıklamalar

Bu ders, dönemin geri kalanında kullanılacak Python araçlarını tanıtarak başlar. Hoca, CS231n dersinin NumPy eğitimini Jupyter Notebook'a aktarmış ve hücre hücre çalıştırarak anlatmıştır. Önce temel tipler gösterilir: `x = 3` bir tam sayı, `y = 3.7` bir ondalıklı sayıdır; tip MATLAB'da olduğu gibi atamadan anlaşılır. Mantıksal değişkenlerde `t and f` sonucu `False` olur. Metinlerde `'merhaba'.center(11)` yedi harfli sözcüğü on bir karakterlik alanın ortasına koyar ve iki yanda ikişer boşluk kalır; `'merhaba'.replace('h','aaaah')` sonucu `meraaaahaba` olur; `strip()` baştaki ve sondaki boşlukları siler (ekrandan, 00:25:00; 00:30:00).

Listelerde hoca indekslemenin 0'dan başladığını ve listenin farklı tipte eleman tutabildiğini vurgular: `xs = [3, 1, 2]` listesinin `xs[2]` gözüne `'yeni'` atanınca liste `[3, 1, 'yeni']` olur, `append('bar')` ile dört elemana çıkar. `nums = list(range(5))` için `nums[2:4]` → `[2, 3]`, `nums[2:]` → `[2, 3, 4]`, `nums[:2]` → `[0, 1]`, `nums[:-1]` → `[0, 1, 2, 3]`; `nums[2:4] = [8, 9]` ataması ile liste `[0, 1, 8, 9, 4]` olur (ekrandan, 00:35:00). Liste üreteciyle `[x ** 2 for x in nums if x % 2 == 0]` yalnız çift sayıların karelerini, `[0, 4, 16]`, verir (ekrandan, 00:40:00).

NumPy bölümünde hoca dizi, satır vektörü ve matris arasındaki farkı öne çıkarır. `np.array([[1,2,3,4],[5,6,7,8],[9,10,11,12]])` matrisinden `a[:2, 1:3]` ile 0. ve 1. satırların 1. ve 2. sütunları, yani `[[2, 3], [6, 7]]`, alınır. Bu alt dizinin `[0, 0]` gözüne 77 atanınca ana matrisin `a[0, 1]` gözü de 77 olur. Dizi matematiğinde `x = [[1,2],[3,4]]`, `y = [[5,6],[7,8]]` için `x * y` eleman eleman çarpımla `[[5, 12], [21, 32]]` verir; `x.dot(y)` gerçek matris çarpımıyla `[[19, 22], [43, 50]]` verir. `v = [9, 10]` ile `w = [11, 12]` iç çarpımı $9\cdot 11 + 10\cdot 12 = 219$, `x.dot(v)` ise `[29, 67]` olur (ekrandan, 01:15:00). Yayma örneğinde 4x3'lük `x` matrisinin her satırına `v = [1, 0, 1]` eklenir; açık döngüyle ya da `v`'yi `np.tile` ile dört kez kopyalayıp toplayarak aynı sonuç `[[2,2,4],[5,5,7],[8,8,10],[11,11,13]]` elde edilir (ekrandan, 01:20:00).

Görüntü kısmında `io.imread('cat.jpg')` ile okunan görüntünün tipi `uint8`, şekli `(400, 248, 3)` olarak yazdırılır (ekrandan, 01:25:00). Matrisin `[0, 0]` gözü görüntünün sol üst köşesidir; her piksel R, G, B için üç bayt tutar. İkinci örnekte okunan balon görüntüsü 300 satır, 225 sütun ve 3 kanallıdır; en küçük değeri 0, en büyüğü 255'tir. Çizim için `np.arange(0, 3*np.pi, 0.1)` ile üretilen noktalarda sinüs ve kosinüs çizilir; `plt.subplot(2, 1, 1)` ve `plt.subplot(2, 1, 2)` iki satır bir sütunluk alt çizim düzenini kurar. Hoca ayrıca `plt.subplot(1, 2, ...)` ile renkli görüntüyü ve `rgb2gray` ile elde edilen gri halini yan yana göstermiştir.

İkinci yarıda hoca tahtada görüntü dosyası türlerini anlatır. Siyah-beyaz görüntüde piksel başına 1 bit vardır (faks makinelerinde kullanılır), gri görüntüde 8 bit vardır. Renkli görüntü üç kanaldan oluşur ve piksel başına 24 bit kullanır; bu yaklaşık 16 milyon renk demektir. İnsan gözü bu kadar rengi ayırt edemediği için dizinli renkli görüntüde en çok kullanılan 256 renk bir renk tablosuna yazılır, piksel yalnız tablonun indeksini tutar. Örneğin piksel değeri 25 ise renk tablosunun 25. satırındaki RGB değerleri kullanılır. JPEG de renk nicemleme yapan ama kayıplı bir sıkıştırmadır; tıbbi görüntülerde TIFF ya da 16 bit DICOM tercih edilir.

Son bölümde yoğunluk dönüşümleri anlatılır. Dönüşüm $s=T(r)$ ile gösterilir; $r$ giriş, $s$ çıkış parlaklığıdır ve ikisi de $0$ ile $L-1$ arasındadır. Eşikleme fonksiyonu $k$'ya kadar olan değerleri 0'a, üstündekileri en yüksek değere çevirerek gri görüntüden ikili görüntü üretir. Log eğrisi $L/2$ değerini $L-1$'e yakın bir yere taşıdığı için görüntüyü aydınlatır. Gama eğrilerinde $s=c\,r^{\gamma}$ kullanılır ve $r$ 1'e normalize edilir. Karanlık bir omurga MR görüntüsü $\gamma = 0.6,\ 0.4,\ 0.3$ ile aydınlatılmış, fazla aydınlık bir hava fotoğrafı $\gamma = 3,\ 4,\ 5$ ile karartılmıştır. Bit düzlemi dilimlemede 8 bitlik gri görüntünün her biti ayrı bir ikili görüntü olarak gösterilir; en anlamlı bit düzlemi orijinale en çok benzer.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
