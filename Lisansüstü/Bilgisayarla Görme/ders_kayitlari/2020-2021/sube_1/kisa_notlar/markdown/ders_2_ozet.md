# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin kaynakları ve yönelimi
  - Ana kitap Richard Szeliski'nin *Computer Vision: Algorithms and Applications* kitabıdır. Yazarın sitesinde (szeliski.org/Book) ikinci baskının taslakları ücretsiz PDF olarak bulunur; okumalarda bölüm numaraları değişmişse bölüm adından bulunur (ekrandan, 00:10:00).
  - Slaytların temeli James Hays'in bilgisayarla görme ders slaytlarıdır; bunlar da başka hocaların (ör. Brown Üniversitesi) slaytlarından derlenmiştir.
  - Derin öğrenme kısmı için Stanford'daki Fei-Fei Li grubunun *CS231n: Convolutional Neural Networks for Visual Recognition* dersi (slayt ve videolar) ve Justin Johnson'ın University of Michigan'daki *Deep Learning for Computer Vision* dersi önerildi (ekrandan, 00:20:00).
  - Derin öğrenmeye giriş için Yoshua Bengio'nun *Deep Learning* kitabı önerildi; kitap internette ücretsiz okunabilir (ekrandan, 00:25:00).
  - Bu yıl klasik konuların bir kısmı kısaltılıp yerine yapay sinir ağları ve derin öğrenme eklenecek; üretici modeller (GAN'lar gibi) de ilgi alanı olarak anıldı.
- Bilgisayarla görme nedir?
  - Makine öğrenmesinin görsel veriye uygulanmış hâli olarak tanımlandı: bilgisayarın imgeleri ve diğer görsel verileri "anlaması".
  - Bir imgede hangi sahnenin olduğu, hangi nesnelerin nerede olduğu, nesnenin kameradan uzaklığı gibi bilgileri insan bir bakışta toparlar; bunu bilgisayara yaptırmak kolay değildir.
  - Makak maymununda görsel korteks beynin yaklaşık %50'sini kaplar; bir imgedeki bilgi miktarı çok büyüktür, videoda daha da büyüktür.
- Uygulama alanları
  - Plaka tanıma, posta servislerinde karakter tanıma, yüz algılama, gülümseme algılayan fotoğraf makineleri.
  - Biyometri: iris tanıma (yıllar sonra aynı kişiyi gözünden tanıma örneği), parmak izi ve yüz tanımayla giriş.
  - Mobil görsel arama, tek bir resimden üç boyutlu model çıkarma, hareket yakalama (motion capture) ve film efektleri.
  - Sporda karar destek (tenis topunun kort içinde olup olmadığı), boş alana otomatik reklam yerleştirme.
  - Medikal görüntüleme (tümörlü hücre ve hastalık tespiti), sürücüsüz araçlar, hareket algılayan oyunlar (Kinect), artırılmış ve sanal gerçeklik (Pokémon Go).
  - Endüstriyel robotlar ve banttaki ürünlerin kamerayla denetimi (ekrandan, 00:40:00), uzay araçları.
- Güncel durum ve derin öğrenme
  - Eğitim verisi verildiğinde bilgisayarla görme insan görüsüne yaklaşmıştır; alan büyük ölçüde derin öğrenmeye dönmüştür.
  - Klasik imge işleme işleri de (ör. imge büyütme) artık derin öğrenmeyle yapılabilmektedir.
  - Geoffrey Hinton ve Yann LeCun gibi derin öğrenme araştırmacıları popüler listelere girmiştir (ekrandan, 00:45:00); AlphaGo ve AlphaZero gibi pekiştirmeli öğrenme uygulamaları anıldı.
  - Bilgisayarla görme disiplinlerarasıdır: imge işleme, geometri, tanıma, derin öğrenme, robotik, insan-bilgisayar etkileşimi, medikal görüntüleme, sinirbilim, optik, fotoğrafçılık, bilgisayar grafiği, makine öğrenmesi.
- Önkoşullar
  - Lineer cebir, kalkülüs ve olasılık.
  - İmge işleme: Gonzalez'in *Digital Image Processing* kitabı, makalelerdeki matematiği anlamak için önerildi.
  - Python ve benzeri bir dille çalışabilmek.
- İmgelerle çalışma: gri seviye ve renkli imgeler
  - Gri seviye imge iki boyutlu bir dizi (matris) olarak tutulur; her elemana piksel denir.
  - Değerler ışık miktarı gibi düşünülür: 0 siyah, 255 beyaz, aradaki değerler grinin tonlarıdır.
  - Python'da (NumPy'da) indeksleme 0'dan başlar; önce satır, sonra sütun yazılır: `A[0,0]`, `A[0,1]`.
  - Renkli imgede her piksel üç sayıyla gösterilir. En yaygın renk uzayı RGB'dir; HSI, HSV, YCrCb gibi başka renk uzayları da vardır (konuyu öğrencilerin kendisinin okuması istendi).
  - Üç bileşen ayrı matrislerde tutulur; her birine kanal (channel) ya da düzlem (plane) denir. Kanallar üst üste konunca küp gibi üç boyutlu bir yapı oluşur.
  - Dördüncü kanal olarak alfa (saydamlık) kanalı eklenebilir: 0 tam saydam, en büyük değer opaktır.
- Değer aralıkları ve normalizasyon
  - 8 bit ile $2^8 = 256$ değer gösterilebilir; bu yüzden imgeler okunurken genelde 0-255 aralığında, `uint8` türünde gelir.
  - İşlem yaparken (toplama, çarpma, konvolüsyon) ondalıklı değerler oluştuğu için değerler 0-1 aralığına normalize edilip gerçel sayıya çevrilir; kaydederken ya da gösterirken tekrar 0-255 aralığına dönülür.
- Python ile imge okuma, gösterme, yazma
  - Okuma: OpenCV'de `cv2.imread`, ayrıca Pillow (eski PIL'in sürdürülen sürümü). `scipy.misc.imread` kullanımdan kaldırılmıştır.
  - Hangi kütüphaneyle okunursa okunsun sonuç bir NumPy dizisidir; boyutlar `f.shape` ile öğrenilir.
  - Gösterme: OpenCV'de `cv2.imshow`, `cv2.waitKey(0)`, `cv2.destroyAllWindows()`; Matplotlib'de `plt.imshow`, renk haritası (`cmap='hot'`), `plt.colorbar()`, `plt.show()` (ekrandan, 01:30:00).
  - Yazma: OpenCV'de `cv2.imwrite`. JPEG kayıplı sıkıştırır ve kalite 0-100 arasında ayarlanır; bilgisayarla görmede PNG gibi kayıpsız formatlar tercih edilir.
  - Veri türü `astype` ile değiştirilir (`x = x.astype(float)`).
- NumPy özeti (DataCamp NumPy cheat sheet üzerinden)
  - Eksenler, dizi oluşturma (`np.array`, `zeros`, `ones`, `arange`, `linspace`, `full`, `eye`, `random.random`, `empty`), veri türleri.
  - Eleman eleman aritmetik, matris çarpımı (`dot`), karşılaştırma ve Boole maskesi, toplu fonksiyonlar.
  - Kopya ve görünüm (view), indeksleme, dilimleme, Boole ve fancy indeksleme.
  - Dizi işlemleri: `transpose`, `ravel`, `reshape`, `resize`, `append`, `insert`, `delete`, `concatenate`, `vstack`, `hstack`.
- Uygulama: Spyder'da imge açma
  - `cv2.imread('LennaTrue.bmp')` ile okunan imgenin boyutu `(480, 512, 3)` çıktı: 480 satır, 512 sütun, 3 kanal (ekrandan, 02:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Gonzalez'in kitabını okumak
  - Bilgisayarla görmede araştırmacı olmak isteyenlerin bu kitabı okuması gerektiği söylendi; aksi hâlde makalelerdeki matematik anlaşılamaz. İmge işleme bilgisayarla görmenin temelidir.
- Python ve NumPy'ı iyi bilmek
  - Python'ı bilmeyenlerin hemen öğrenmesi istendi. NumPy ve Matplotlib Python bilim dünyasında standarttır.
- Döngüden kaçınmak
  - Python'da döngüler pahalıdır. `A[A < 2] = 0` gibi vektörel yazım hem daha okunaklı hem çok daha hızlıdır.
- Normalizasyon
  - 256 tamsayı değer işlem doğruluğu için yetmez; 0-1 aralığında gerçel sayılarla çalışmak gerekir.
- Kayıpsız format
  - Bilgisayarla görmede bilgi kaybedilmek istenmez; JPEG yerine PNG gibi kayıpsız formatlar tercih edilir.
- Yeniden boyutlandırmadan kaçınmak
  - NumPy dizileri bellekte tek bir bitişik blokta durur. Satır eklemek ya da `append` yapmak kopyalama gerektirir ve pahalıdır. Gereken boyut baştan hesaplanıp dizi bir kerede oluşturulmalıdır.
- Atama ve kopya farkı
  - `b = a` yalnızca yeni bir referans oluşturur; gerçek kopya için `np.copy(a)` ya da `a.copy()` kullanılır.
- Kanal sırasına dikkat
  - Kütüphaneler kanalları her zaman RGB sırasıyla döndürmeyebilir; belgelere bakmak gerekir.

## Kısa Tekrar Notları

- Bilgisayarla görme: makine öğrenmesinin görsel veriye uygulanması.
- Gri imge = 2B matris; piksel değeri 0 (siyah) ile 255 (beyaz) arası.
- NumPy'da indeksleme 0'dan başlar: `A[satır, sütun]`.
- Renkli imge: 3 kanal (R, G, B); isteğe bağlı 4. kanal alfa (0 saydam, en büyük değer opak).
- Renk uzayları: RGB, HSI, HSV, YCrCb.
- 8 bit → 256 değer → 0-255; işlem için 0-1 aralığına normalize et, `float` kullan.
- Okuma: `cv2.imread`, Pillow; sonuç her zaman NumPy dizisi; `f.shape` → (satır, sütun, kanal).
- Gösterme: `cv2.imshow` + `cv2.waitKey(0)` + `cv2.destroyAllWindows()`, ya da `plt.imshow` + `cmap` + `colorbar` + `show`.
- Yazma: `cv2.imwrite`; JPEG kayıplı (kalite 0-100), PNG kayıpsız.
- `*` eleman eleman çarpım (Hadamard), `dot` matris çarpımı.
- Dilimlemede son indis dahil değildir: `a[0:2]` → 0. ve 1. elemanlar.
- `b = a` referans, `a.copy()` kopya, `a.view()` aynı veriye yeni görünüm.
- Döngü yerine vektörel işlem ve Boole maskesi kullan.

## Detaylı Açıklamalar

- Gri seviye imge ve indeksleme
  - Derste tahtaya 3×4'lük bir matris yazıldı. İlk satırın ilk elemanı 0, en büyük değer 255 yapılarak siyah ve beyaz örneklendi (ekrandan, 01:10:00):
    $$A = \begin{bmatrix} 0 & 3 & 8 & 6 \\ 7 & 12 & 200 & 255 \\ 1 & 8 & 12 & 5 \end{bmatrix}$$
  - `A[0,0]` sıfırıncı satır ve sıfırıncı sütundaki elemandır, değeri 0'dır. `A[0,1]` sıfırıncı satır ve birinci sütundadır, değeri 3'tür. MATLAB'da indeksleme 1'den başlar, Python'da 0'dan.
  - Ekranda her değer bir pikselin kapladığı küçük kare alana boyanır. Pikseller çok küçük olduğu için uzaktan fark edilmez; imge yeterince büyütülünce görünür.
- Renkli imge, kanallar ve alfa
  - Bir renk üç sayıyla tanımlanır. Bu sayıların anlamı renk uzayına bağlıdır. Aynı renk RGB'de bir üçlüyle, HSI'da başka bir üçlüyle ifade edilir.
  - R, G ve B değerleri ayrı matrislerde (kanallarda) tutulur. Bunlar üst üste konunca piksel başına üç değer tutan küp benzeri bir yapı elde edilir (ekrandan, 01:15:00). Alfa kanalı eklenirse dört kanal olur. Alfa, bilgisayar grafiğinde bir resmin altındakini ne kadar gösterdiğini belirler.
- Neden 0-1 aralığı?
  - Gri seviyede 8 bit kullanılır: $2^8 = 256$ değer, yani 0-255 (ekrandan, 01:20:00).
  - İşlemler sırasında 1,3 gibi ondalıklı değerler ve aralık dışı değerler oluşur. Tamsayıda kalınırsa sonuç doğruluğu düşer. Bu yüzden önce gerçel sayıya ve 0-1 aralığına geçilir, işlemler yapılır, kaydederken ya da gösterirken tekrar 0-255'e dönülür. İşlem sırasında değerler aralık dışına taşarsa yeniden normalize etmek gerekebilir.
- Okuma kütüphaneleri
  - Farklı kütüphanelerin olmasının bir nedeni, her kütüphanenin her imge formatını (PNG, JPEG, GIF, TIFF vb.) açamamasıdır. Hepsi sonunda NumPy dizisi döndürdüğü için okumadan sonraki iş aynıdır.
  - Derste denenen `scipy.misc` içindeki `imread` kullanımdan kaldırılmış çıktı. PIL güncellenmediği için yerine Pillow çıkmıştır.
- Gösterme ve renk haritaları
  - Slayttaki Matplotlib kodu (ekrandan, 01:30:00):

    ```python
    import matplotlib.pyplot as plt
    import cv2

    f = cv2.imread('airplane.png')
    plt.imshow(f)

    # get the first channel to demonstrate colorbar
    l = f[:,:,0]
    plt.imshow(l, cmap='hot')
    plt.colorbar()
    plt.show()
    ```

  - `f[:,:,0]` bütün satırları, bütün sütunları ve 0 numaralı kanalı alır. Sonuç tek kanallı (gri seviye) bir imgedir.
  - Renk haritası (colormap) hangi sayının ekranda hangi renkle gösterileceğini belirler. `hot` haritası küçük değerleri siyaha, büyük değerleri beyaza yakın gösterir, aradakileri kırmızı-sarı tonlarına dağıtır. Matplotlib'de viridis, plasma, inferno, magma, cividis, gri tonlu ve döngüsel (HSV) haritalar vardır. Değerleri birbirinden ayırt etmek önemliyse çok renkli bir harita daha işe yarar.
  - `cv2.imshow` OpenCV'nin kendi penceresini açar. `cv2.waitKey(0)` olmadan pencere hemen kapanır. Bir tuşa basılınca `cv2.destroyAllWindows()` pencereleri kapatır.
- Yazma ve dosya formatları
  - JPEG sıkıştırmada bir kısım veriyi atar; kalite değeri düştükçe dosya küçülür ama kalite de düşer. PNG kayıpsız sıkıştırır. BMP genelde sıkıştırılmaz ve çok yer kaplar.
  <!-- BELİRSİZ: "Writing images" slaytındaki imwrite ve JPEG kalite parametresinin tam kodu karelerde görünmüyor. -->
- NumPy temel işlemleri (ekrandan, 02:05:00-02:35:00)
  - Örnek diziler: `a = np.array([1,2,3])`, `b = np.array([(1.5,2,3), (4,5,6)], dtype=float)`.
  - Eksenler: 2B dizide axis 0 satırlar boyunca aşağı doğru ilerler. `b.min(axis=0)` her sütunun en küçüğünü verir: `[1.5, 2, 3]`. `b.min(axis=1)` her satırın en küçüğünü verir: `[1.5, 4]`.
  - Aritmetik eleman eleman yapılır: `a - b` → `[[-0.5, 0, 0], [-3, -3, -3]]`, `a * b` → `[[1.5, 4, 9], [4, 10, 18]]`. Boyutlar farklıysa (ya da biri skalersa) küçük olan uygun boyuta genişletilir. Matris çarpımı `e.dot(f)` ile yapılır. Üs alma `a**2` ile yapılır.
  - Karşılaştırma eleman eleman Boole dizisi verir: `a < 2` → `[True, False, False]`. Bu dizi maske olarak kullanılır: `a[a < 2] = 0`.
  - Atama referans kopyalar. `a.view()` aynı veriye yeni bir görünüm verir, bellek kopyalamaz. Transpoz da bir görünümdür: NumPy yalnızca adım (stride) gibi erişim bilgilerini değiştirir.
  - Dilimleme: `a[0:2]` → `[1, 2]`, `b[0:2, 1]` → `[2, 5]`, `b[:1]` → `[[1.5, 2, 3]]`, `a[::-1]` → `[3, 2, 1]`. Baştaki indis yazılmazsa 0, sondaki yazılmazsa sona kadar demektir. `c[1, ...]` "1 numaralı eleman ve geri kalan bütün boyutlar" anlamına gelir.
  - Fancy indeksleme: `b[[1,0,1,0],[0,1,2,0]]` (1,0), (0,1), (1,2), (0,0) elemanlarını tek boyutlu dizi olarak verir: `[4, 2, 6, 1.5]`. `b[[1,0,1,0]][:,[0,1,2,0]]` ise önce satırları, sonra sütunları seçer ve 4×4'lük bir matris döndürür.
  - NumPy dizisi C dizisi gibi bellekte bitişiktir ve içindeki bütün elemanlar aynı türdendir. Python listesi ise farklı türde nesnelere referans tutabilir. Bu tasarım hız içindir; NumPy arka planda C kütüphaneleri çalıştırır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
