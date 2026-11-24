# Ders 3 Çalışma Özeti

## Genel Konular

- Python ile görüntü okuma, gösterme ve temel matris işlemleri
  - Görüntü `skimage.io.imread` ile bir NumPy matrisine okunur, `matplotlib.pyplot.imshow` ile gösterilir. Matrisin `(0,0)` gözü görüntünün sol üst köşesidir.
  - `dtype` matristeki sayıların türünü (tamsayı, ondalıklı), `shape` matrisin boyutunu verir; `min()` ve `max()` ile parlaklık aralığı görülür.
  - Dilimleme (slicing) ile küçültme (`image[::2, ::2]`), ters çevirme (`image[-1:0:-1, -1:0:-1]`) ve kırpma (belli satır ve sütun aralığını alma) yapılabilir. Bunlar yalnız matris alıştırmasıdır; gerçek yeniden boyutlandırma için `rescale` ve `resize` gibi hazır fonksiyonlar kullanılmalıdır (ekrandan, 00:15:00).
- Görüntüyü kaydetme ve JPEG kalite faktörü
  - `io.imsave` ile görüntü diske yazılır. JPEG kayıplı sıkıştırmadır; `quality` parametresi 0 ile 100 arasında verilir. Değer düştükçe dosya küçülür, bozulma artar (ekrandan, 00:20:00).
  - Derste kalite 20 ile kaydedilen dosya yaklaşık 6 KB, 80 ile kaydedilen yaklaşık 16 KB, kalite verilmeden kaydedilen yaklaşık 13 KB çıktı; özgün dosya yaklaşık 20 KB idi.
- Renkli görüntünün kanalları ve gri seviyeye dönüşüm
  - Renkli görüntü üç boyutlu bir matristir; `image[:,:,0]`, `image[:,:,1]`, `image[:,:,2]` sırasıyla kırmızı, yeşil ve mavi kanallardır (ekrandan, 00:25:00).
  - Bir kanal gri seviyede gösterildiğinde o rengin en doygun olduğu bölgeler beyaz, o rengi hiç içermeyen bölgeler siyah görünür.
  - Gri seviyeye dönüşüm katsayılı toplamla yapılır: $Y = 0.2126R + 0.7152G + 0.0722B$ (ekrandan, 00:30:00). Aynı iş `skimage.color.rgb2gray` ile de yapılır.
- Yoğunluk dönüşümleri ve gama düzeltmesi
  - Dönüşüm eğrilerinde yatay eksen giriş, dikey eksen çıkış parlaklığıdır. Birim doğru (identity) görüntüyü değiştirmez; ters köşegen negatif görüntü verir.
  - Birim doğrunun altında kalan eğriler görüntüyü koyulaştırır, üstünde kalanlar aydınlatır.
  - Gama dönüşümünde $\gamma > 1$ görüntüyü koyulaştırır, $\gamma < 1$ aydınlatır. `skimage.exposure.adjust_gamma` hazır fonksiyonu $O = I^{\gamma}$ dönüşümünü, 0-1 aralığına ölçeklenmiş görüntü üzerinde uygular.
- Histogram ve histogram eşitleme
  - Histogramda yatay eksen parlaklık değeri, dikey eksen o değerin görüntüdeki tekrar sayısıdır.
  - Karanlık görüntüde histogram sola, aydınlık görüntüde sağa yığılır. Düşük kontrastlı görüntüde ne tam siyah ne tam beyaz vardır, değerler dar bir aralıktadır. Yüksek kontrastlı görüntüde bütün parlaklık değerleri az çok bulunur.
  - Histogram eşitleme dar aralıkta yığılmış değerleri bütün ölçeğe yayar. Adımlar: tekrar sayısı $n_k$, olasılık $p(r_k) = n_k / MN$, birikimli toplam, en büyük düzey değeriyle ($L-1$) çarpma ve en yakın tamsayıya yuvarlama.
  - Hazır fonksiyonlar `skimage.exposure.histogram` ve `skimage.exposure.equalize_hist`'tir.
- Eşikleme (thresholding)
  - Gri seviyeli görüntü bir eşik değeriyle ikili (siyah-beyaz) görüntüye çevrilir: eşikten büyük pikseller 1 (ön plan), diğerleri 0 (arka plan) olur.
  - Eşik değerinin seçimi kritiktir: çok düşük eşik arka planı da beyaza boyar, çok yüksek eşik ön plandaki nesneleri kaybettirir.
  - Eşikleme ön planı arka plandan ayırdığı için basit bir bölütleme (segmentasyon) işlemidir.
- Uzamsal filtreleme
  - Filtreleme görüntü uzayında (spatial domain) yapılır. Alçak geçiren filtre düşük frekansları geçirir, keskin kenar geçişlerini (yüksek frekans) bastırır; görüntüyü bulanıklaştırır (blurring/smoothing).
  - Filtre maskesi (kernel) genelde 3x3, 5x5, 7x7 gibi tek boyutlu seçilir ki bir merkez pikseli olsun. Maskedeki değerlere filtre katsayıları denir.
  - Ortalama filtresi: $\frac{1}{9}$ ile çarpılmış birlerden oluşan 3x3 maske (eşit ağırlıklı). Ağırlıklı ortalama filtresi: $\frac{1}{16}[1\,2\,1;\,2\,4\,2;\,1\,2\,1]$ (ekrandan, 01:40:00).
  - Korelasyonda maske olduğu gibi görüntüye oturtulur; konvolüsyonda maske önce 180 derece döndürülür. Simetrik maskede ikisinin sonucu aynıdır.
  - Dolgu (padding) yapılmazsa 5x5 girişe 3x3 maske uygulanınca çıkış 3x3 olur.
- Gauss filtresi
  - Bir boyutlu Gauss fonksiyonu $G(x) = \frac{1}{\sqrt{2\pi}\,\sigma} e^{-\frac{(x-\mu)^2}{2\sigma^2}}$; iki boyutlusu $G(x,y) = \frac{1}{2\pi\sigma^2} e^{-\frac{x^2+y^2}{2\sigma^2}}$.
  - $\sigma$ büyüdükçe eğri yayılır ve tepesi alçalır ($\sigma=1$ için tepe yaklaşık 0.40, $\sigma=2$ için yaklaşık 0.20); eğrinin altındaki alan hep 1'dir.
  - Gauss fonksiyonundan filtre katsayıları üretilir; `skimage.filters.gaussian` ile görüntü yumuşatılır.
- Medyan filtresi ve tuz-biber gürültüsü
  - Sıralama istatistiğine dayalı doğrusal olmayan bir filtredir: yapılandırma elemanının seçtiği pikseller sıralanır, ortanca değer merkez piksele yazılır.
  - Gürültü temizlemede kullanılır ve kenarları korur (edge preserving).
  - Beyaz zemin üzerinde siyah noktalar biber, siyah zemin üzerinde beyaz noktalar tuz gürültüsüdür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hazır fonksiyonların arkasındaki matematiği bilmek
  - Her işlem hazır fonksiyonla yapılabilir, ama hoca önce arkadaki hesabın (histogram eşitleme, konvolüsyon, Gauss eğrisi) elle bilinmesini istedi. Kod parçalarının ders sırasında paralel olarak denenmesini önerdi.
- Korelasyon ile konvolüsyon farkı
  - Hoca bunun genelde dikkat edilmeyen önemli bir kavram olduğunu söyledi. Konvolüsyonda maske x ve y doğrultusunda 180 derece döndürülür; maske simetrikse sonuç korelasyonla aynıdır.
- Konvolüsyonun kağıt üzerinde hesabı
  - Giriş görüntüsü ve filtre katsayıları verilip konvolüsyon sonucunun elle bulunmasının istenebileceğini belirtti.
- Eşik değerinin seçimi
  - Eşik değeri yanlış seçilirse ya arka plan nesnelere karışır ya da nesnelerin bir kısmı kaybolur.
- Gauss dağılımını iyi tanımak
  - Gauss fonksiyonu ileriki konularda çok kullanılacağı için hoca dağılımın biçimini ve $\sigma$'nın etkisini kendi kodlarıyla çizdirdi.
- Gri seviyeden renkliye dönüş
  - Renkliden griye geçişte bilgi kaybolur; griden özgün renklere birebir dönmenin kestirme yolu yoktur.

## Kısa Tekrar Notları

- `(0,0)` sol üst köşedir; `shape` boyut, `dtype` veri türüdür.
- `image[::2, ::2]` yarıya küçültür, `image[-1:0:-1, -1:0:-1]` ters çevirir; doğru yöntem `rescale`/`resize`'dır.
- JPEG `quality` 0-100: düşük kalite küçük dosya, çok bozulma.
- Kanal gösteriminde beyaz bölge o rengin en doygun olduğu yerdir.
- $Y = 0.2126R + 0.7152G + 0.0722B$.
- $\gamma > 1$ koyulaştırır, $\gamma < 1$ aydınlatır.
- Düşük kontrast: ne tam siyah ne tam beyaz var, histogram dar.
- Histogram eşitleme: $p(r_k) = n_k/MN$ → birikimli toplam → $(L-1)$ ile çarp → yuvarla.
- 3 bit/piksel için $L-1 = 7$; 4 bit/piksel için $L-1 = 15$.
- Eşikleme gri görüntüyü ikili görüntüye çevirir; eşik seçimi önemlidir.
- Alçak geçiren filtre bulanıklaştırır; maske boyutu tek sayıdır.
- Konvolüsyon = maskeyi 180 derece döndürüp korelasyon; simetrik maskede fark yok.
- Dolgu yoksa 5x5 giriş, 3x3 maske → 3x3 çıkış.
- Gauss'ta $\sigma$ büyürse eğri yayılır, tepe alçalır.
- Medyan filtresi doğrusal değildir, kenarları korur, tuz-biber gürültüsüne iyi gelir.

## Detaylı Açıklamalar

- **Histogram eşitleme örneği (ekrandan, 01:10:00).** 3 bitlik (değerler 0-7), 64x64 boyutlu (4096 piksel) bir görüntünün tekrar sayıları sırasıyla 790, 1023, 850, 656, 329, 245, 122, 81'dir. Olasılıklar 0.19, 0.25, 0.21, 0.16, 0.08, 0.06, 0.03, 0.02 olur. Birikimli toplamlar 0.19, 0.44, 0.65, 0.81, 0.89, 0.95, 0.98, 1.00'dir. Bunlar 7 ile çarpılınca 1.33, 3.08, 4.55, 5.67, 6.23, 6.65, 6.86, 7.00 bulunur; yuvarlanınca yeni değerler 1, 3, 5, 6, 6, 7, 7, 7 olur. Yani girişteki 0'lar 1'e, 1'ler 3'e, 2'ler 5'e, 3 ve 4'ler 6'ya, 5, 6 ve 7'ler 7'ye taşınır. İlk üç düzeyin görüntünün yüzde 65'ini oluşturması görüntünün karanlık olduğunu gösterir. Çıkış 4 bit olacaksa 7 yerine 15 ile çarpılır.
- **Konvolüsyon örneği (ekrandan, 01:55:00).** Giriş görüntüsü 5x5 ve 3 bitliktir:

  ```text
  1 3 2 5 7
  0 1 1 2 6
  1 2 2 3 4
  1 3 4 5 6
  2 5 6 6 7
  ```

  Maske $\frac{1}{16}[1\,2\,1;\,2\,4\,2;\,1\,2\,1]$ simetrik olduğu için konvolüsyon ile korelasyon aynı sonucu verir. Dolgu olmadığından çıkış 3x3'tür. İlk satırın üç değeri derste elle hesaplandı: 22/16, 31/16, 53/16. Örneğin ilk değer $1\cdot1 + 3\cdot2 + 2\cdot1 + 0\cdot2 + 1\cdot4 + 1\cdot2 + 1\cdot1 + 2\cdot2 + 2\cdot1 = 22$'dir. Kalan satırlar derste hesaplanmadı (python ile kontrol: 28/16, 39/16, 55/16 ve 47/16, 64/16, 77/16).
- **Medyan filtresi örneği (ekrandan, 02:25:00).** Aynı giriş görüntüsünde yapılandırma elemanı yalnız merkez ile kuzey, güney, doğu ve batı komşularını seçen artı biçimli bir 3x3 maskedir. İlk konumda değerler sıralanınca 0, 1, 1, 2, 3 olur ve ortanca 1'dir. İkinci konumda 1, 1, 2, 2, 2 ve ortanca 2; üçüncü konumda 1, 2, 3, 5, 6 ve ortanca 3'tür.
- **Ortalama filtresinin yumuşatma etkisi (ekrandan, 02:00:00).** 7x7 sıfır matrisin ortasındaki 3x3 bölge 1 yapılır ve 1/9'lardan oluşan maskeyle `scipy.ndimage.convolve` uygulanır. Keskin 0-1 geçişleri 0, 0.33, 0.67, 1 biçiminde kademeli geçişlere dönüşür; bu bulanıklaşmanın sayısal görünümüdür.
- **Gauss filtresinin gerçek görüntüye etkisi (ekrandan, 02:20:00).** Kameraman görüntüsü her 10 pikselden bir örnek alınarak mozaik (pixelated) hale getirilir. Ortalama filtresi ya da $\sigma=2$ olan Gauss filtresi uygulanınca mozaik görünüm kaybolur, fakat görüntü bulanıklaşır.
- **Medyan ile ortalama filtresinin karşılaştırılması (ekrandan, 02:30:00).** Madeni para görüntüsüne `disk(10)` yapılandırma elemanıyla `filters.rank.mean` ve `filters.rank.median` uygulanır. Hoca tuz-biber gürültüsü eklenmiş bir test görüntüsünde iki filtrenin gürültüyü ne kadar temizlediğini ve kenarları ne kadar bozduğunu, farklı yapılandırma elemanlarıyla (kare, dikdörtgen, farklı disk boyutları) denemeyi önerdi.
- **Ders sonrası notlar.**
  - Hoca $\pm 3\sigma$ aralığının alanın yaklaşık yüzde 98'ini kapsadığını söyledi; doğrusu yaklaşık yüzde 99.7'dir (yüzde 98 civarı $\pm 2.5\sigma$'ya karşılık gelir).
  - Elle hesaplanan gri görüntü ile `rgb2gray` sonucu arasındaki farkın en büyük değeri 253.99 çıktı. Hoca bunu ondalıklı katsayılarla çarpmaya bağladı. Ekranda `rgb2gray` çıktısının 0-1 aralığında (en büyük 1.0) olduğu görülüyor; elle hesaplanan ise 0-255 aralığında kaldı. Farkın asıl nedeni büyük olasılıkla bu ölçek farkıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
