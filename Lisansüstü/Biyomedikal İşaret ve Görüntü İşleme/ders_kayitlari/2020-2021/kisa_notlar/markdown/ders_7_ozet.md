# Ders 7 Çalışma Özeti

## Genel Konular

- İmge dosyaları ve bellek hesabı
  - Bir imgenin boyutunu uzamsal çözünürlük (piksel sayısı) ve nicemleme (bit derinliği) belirler. Bit derinliği, gri seviye sayısını belirlediği için çözünürlüğü de etkiler.
  - Slayttaki örnek (ekrandan, 00:20:00): 8 bit/piksel, 200x200 piksellik gri tonlu imgede $200\times200=40000$ piksel vardır; her piksel 1 bayt olduğundan $40000$ bayt $\approx 39$ KB bellek gerekir. Renkli (RGB) imgede bu sayı 3 ile çarpılır. Hesap sıkıştırma kullanılmadığında geçerlidir.
  - RAW tipi: sıkıştırma olmadan bitlerin arka arkaya dizilmesidir. Piksellerin dizilme yönü ya da R, G, B düzlemlerinin sırası gibi farklı RAW çeşitleri vardır.
  - Bazı dosya tipleri RGB yerine önce ışıklılık (Y), sonra renk bileşenlerini (U, V) saklar.
  - BMP (ekrandan, 00:30:00): yaygın, sıkıştırılmamış biçimdir; genellikle her renk bileşeni 8 bit olan 24 bitlik format kullanılır. RAW'dan farkı, piksel boyutu ve bit derinliği gibi bilgileri tutan bir başlık (header) kısmının bulunmasıdır. MATLAB'de `imread` ile okunur; gri tonlu imge 2, renkli imge 3 boyutlu matris oluşturur.
- Işıklılık ve renk bileşenleri
  - R, G, B eksenli bir koordinat sisteminde bir rengin merkeze uzaklığı parlaklığı, iki açı ($\varphi$, $\theta$) ise renk bilgisini verir. YUV'de Y parlaklık, U ve V renk bileşenidir; LAB'da L ışıklılık, A ve B krominanstır.
- Temel geometrik işlemler
  - Ters çevirme ve aynalama: piksellerin yeni bir matriste yer değiştirmesiyle yapılır.
  - Döndürme: tıbbi imgelerde (göğüs, MR) kaymış görüntüyü düzeltmek için kullanılır. Yeni piksel konumları tam oturmadığından ara değerleme (interpolasyon) gerekir: ör. iki komşunun ortalaması $(A+B)/2$, ya da bilineer, kübik yöntemler.
  - Öteleme: boşalan yerlere ne konacağına (sıfır vb.) karar verilir.
  - Boyut değişikliği (ekrandan, 00:35:00): 3x3 imgeyi 6x6'ya büyütürken her pikselin kopyalanması en yakın komşu ara değerlemesidir (nearest neighbor). Kareselleşmeyi azaltmak için aradaki piksellere komşuların (çaprazda dört komşunun) ortalaması yazılabilir. Küçültmede dört pikselin ortalaması tek piksel olur. MATLAB'de `imresize`, `reshape`.
- Nokta işlemleri (point operations)
  - Parlaklık (ekrandan, 00:40:00): $g(x,y)=f(x,y)+b$. $b>0$ parlaklığı artırır, $b<0$ azaltır. 8 bitte değerler 0-255 aralığında kırpıldığından, ör. 240-255 arasındaki piksellere 20 eklenirse hepsi 255 olur ve parlak bölgeler aynı beyazlığa düşer (doyma); karanlıkta da benzer.
  - Karşıtlık: $g(x,y)=a\,f(x,y)$. $a>1$ karşıtlığı artırır; ör. 1 ve 2 değerli komşu pikseller $a=3$ ile 3 ve 6 olur, fark 1'den 3'e çıkar.
  - Dönüşüm eğrileri: girişten çıkışa doğrusal ya da doğrusal olmayan eşleme. Slaytta 50'nin altı 0, 50-100 arası hızla artan bir eğri, 100'ün üstü 255 (ekrandan, 00:45:00). MATLAB'de `imadjust`.
  - Eşikleme: $T$ eşiğinin altı 0, üstü 255 yapılırsa ikili (binary) imge elde edilir; normalize edilirse 0-1 değerleri alır.
  - Negatifleme: 0 → 255, 255 → 0. Tıbbi imgelerde damar ve doku yapılarını görmeye yardım eder.
- Histogram
  - Her gri seviyede kaç piksel bulunduğunu gösterir, $h(i)$ (ekrandan, 00:50:00). Cameraman imgesinde siyaha yakın palto yaklaşık 20 seviyesinde bir tepe oluşturur, gökyüzü parlak bölgede tepe verir.
  - Histogramın altındaki alan toplam piksel sayısıdır.
  - Histogram dar bir alanda toplanmışsa karşıtlık düşüktür; geniş alana yayılmışsa yüksektir (ekrandan, 00:55:00).
  - Histogram eşitleme/germe: dar aralık (ör. 40-120) 0-255'e yayılır. Çok pikselin bulunduğu aralığa daha geniş, az pikselin bulunduğu aralığa daha dar yer verilebilir (ekrandan, 01:00:00).
  - Karşıtlık germe: piksel değerinden en küçük değer çıkarılır, (en büyük − en küçük) farkına bölünür ve en büyük gri ton değeriyle çarpılır.
- Piksel komşuluk işlemleri ve konvolüsyon
  - Komşuluk işlemlerinde yeni değer komşu piksellerle birlikte hesaplanır; hesap yükü nokta işlemlerinden fazladır (ekrandan, 01:15:00).
  - Konvolüsyon: 3x3, 5x5, 7x7 gibi bir kernel her pikselin üzerinde gezdirilir, karşılıklı değerler çarpılıp toplanır. Slayttaki örnek (ekrandan, 01:20:00): kernel $\begin{bmatrix}-1&-1&-1\\-2&10&-2\\-1&-1&-1\end{bmatrix}$, imge parçası $\begin{bmatrix}50&75&77\\48&70&83\\51&68&85\end{bmatrix}$; merkezdeki 70'in yeni değeri 32 olur. MATLAB'de `conv2`.
  - Kenar sorunu: dışarıda kalan yerler sıfırla doldurulur ya da aynalama ile genişletilir.
  - $\begin{bmatrix}-1&0&1\\-2&0&2\\-1&0&1\end{bmatrix}$ kerneli sol ve sağ komşuların farkını alır, düşey kenarları bulur (ekrandan, 01:25:00).
  - Merkezde 1, gerisi 0 olan kernel (delta) imgeyi değiştirmez. Ayrılabilir kerneller hesabı kolaylaştırır.
- Uzamsal frekans, alçak ve yüksek geçiren süzgeçler
  - Yumuşak geçişler uzamsal düşük frekanslara, kenarlar ve nesne sınırları uzamsal yüksek frekanslara karşılık gelir (ekrandan, 01:30:00).
  - Ortalama süzgeci: 3x3'te her eleman $1/9$, 5x5'te $1/25$. Kernel büyüdükçe yumuşatma artar.
  - Gauss kernelleri (ekrandan, 01:35:00): merkez ağırlığı yüksek, uzak piksellerin katkısı az; ör. $\begin{bmatrix}1&4&1\\4&16&4\\1&4&1\end{bmatrix}$.
  - Yüksek geçiren süzgeç: merkez 8, komşular −1. Düz bölgede sonuç 0, kenarda büyük değer.
- Kenar bulma
  - Gürültü de kenar gibi algılandığı için önce gürültü giderilir (alçak geçiren süzgeç), sonra kenar pekiştirilir, sonra kenar tespit edilir (ekrandan, 01:40:00).
  - Prewitt, Sobel (merkeze yakın komşuların ağırlığı artırılmış), Laplacian of Gaussian, Roberts, Zero Cross ve Canny. En çok Canny kullanılır.
- Korelasyon ve şablon eşleme
  - Kernel ters çevrilmeden doğrudan karşılık gelen piksellerle çarpılır. Şablona en çok benzeyen yerde en yüksek değer çıkar (harfler içinde "M" arama, sağlam matkap ucu bulma).
- Ortanca (medyan) süzgeci
  - KxK penceredeki değerler sıralanır, ortadaki değer yazılır. Tuz-biber gürültüsünde ortalama süzgecinden daha iyidir, kenarları korur (ekrandan, 01:45:00).
- Renk
  - Işık bir elektromanyetik dalgadır; göz yaklaşık 400-700 nm arasını görür. Mavi 400-500, yeşil 500-600, kırmızı 600-700 nm (ekrandan, 01:50:00). Dalga boyu kısaldıkça frekans artar, yani mavi kırmızıdan yüksek frekanslıdır.
  - RGB: (255,255,255) beyaz, (0,0,0) siyah, (255,0,0) en parlak kırmızı, (128,0,0) daha koyu kırmızı, (128,128,0) sarı (ekrandan, 01:55:00). CMY'de ara renkler ana renk olur (Magenta = Beyaz − Yeşil vb.).
  - Kırmızı elma kırmızı dalga boylarını yansıtır, mavi ve yeşili yutar; bu yüzden R düzleminde parlak, B düzleminde karanlık görünür.
  - Renk modelleri: RGB, CMY, HSI (Hue, Saturation, Intensity); renk standartları CIE.
- Frekans uzayında görüntü işleme
  - $I(x,y)$ → Fourier dönüşümü → $F(u,v)$ → frekans işlemi → $F'(u,v)$ → ters dönüşüm → $I'(x,y)$ (ekrandan, 02:15:00).
  - Gürültü yüksek frekans bileşenlerini artırır. Merkezdeki katsayılar korunup gerisi sıfırlanırsa alçak geçiren, merkez sıfırlanırsa yüksek geçiren süzgeç elde edilir.
- Morfolojik işlemler
  - İkili imgelerde kenar bulma, gürültü giderme, pekiştirme ve bölütlemede; inceltme ve budama gibi son işlemlerde kullanılır (ekrandan, 02:20:00).
  - Yayma (dilation): yapı elemanının altında en az bir 1 varsa merkez 1 olur. Slayttaki örnek (ekrandan, 02:25:00): giriş `1 0 0 0 1 1 1 0 1 1`, yapı elemanı `1 1 1`, çıkış `_ 1 0 1 1 1 1 1 1 _`.
  - Aşındırma (erosion): yapı elemanının altında bir tane bile 0 varsa merkez 0 olur; nesneler daralır.
  - Açma = önce aşındırma, sonra yayma: $A\circ B=(A\ominus B)\oplus B$. Kapama = önce yayma, sonra aşındırma (ekrandan, 02:30:00). MATLAB'de `imopen`, `imclose`.

## Hocanın Özellikle Vurguladığı Kısımlar

- Parlaklık eklerken doyma
  - 0-255 sınırı aşıldığında değerler kırpılır; parlak ya da karanlık bölgelerdeki ayrıntı kaybolur.
- Histogram imge hakkında ön bilgi verir
  - Histogramın bir bölgeye sıkışması düşük karşıtlık demektir. Biyomedikal görüntülerde değerlerin bütün aralığa yayılması istenir.
- Kernelin değerleri işlevini belirler
  - Aynı konvolüsyon işlemi, kernel değerlerine göre yumuşatma, kenar bulma ya da kenar pekiştirme yapar. Komşu farkı alan kernel düz bölgede 0, kenarda büyük değer üretir.
- Kenar bulmadan önce gürültü giderilmeli
  - Gürültülü pikseller kenar gibi algılanır.
- Ortanca süzgecinin üstünlüğü
  - Tuz-biber gürültüsü uç değerlerde (0 ya da 255) olduğu için sıralamada uçlarda kalır; ortadaki değer çoğunluğu (arka planı) temsil eder.

## Kısa Tekrar Notları

- Bellek = piksel sayısı × bit derinliği: 200x200, 8 bit → 40000 bayt ≈ 39 KB; RGB → 3 katı.
- BMP = sıkıştırılmamış + başlık; RAW = başlıksız ham bit dizisi.
- Döndürme ve büyütmede ara değerleme: en yakın komşu, ortalama, bilineer, kübik.
- $g=f+b$ parlaklık, $g=af$ karşıtlık; eşikleme → ikili imge; negatif: $255-f$.
- Histogram altındaki alan = toplam piksel sayısı.
- Konvolüsyon kerneli örneği: 70 → 32.
- `[-1 0 1; -2 0 2; -1 0 1]` → düşey kenarlar.
- Ortalama süzgeci $1/9$, Gauss `[1 4 1; 4 16 4; 1 4 1]`, yüksek geçiren merkez 8 / komşular −1.
- Kenar algoritmaları: Prewitt, Sobel, LoG, Roberts, Zero Cross, Canny.
- Korelasyonda kernel ters çevrilmez; konvolüsyonda çevrilir.
- Medyan süzgeci tuz-biber gürültüsünde en iyisi.
- Görünür ışık 400-700 nm; mavi en yüksek frekans.
- Açma: aşındır + yay; kapama: yay + aşındır.

## Detaylı Açıklamalar

- Konvolüsyon örneği (ekrandan, 01:20:00): kernel simetrik olduğundan ters çevrilse de aynı kalır. Hesap: $(-1\cdot85)+(-1\cdot68)+(-1\cdot51)+(-2\cdot83)+(10\cdot70)+(-2\cdot48)+(-1\cdot77)+(-1\cdot75)+(-1\cdot50)=700-668=32$. Python ile doğrulandı.
- Kenar kernelinin tek satır davranışı (ekrandan, 01:25:00): orta satır $[-2\;0\;2]$ düşünülürse, komşular 2 ve 3 iken $-4+6=2$; komşular eşitken (2, 2) $-4+4=0$; komşular 2 ve 5 iken $-4+0+10=6$. Sol ve sağ komşular birbirinden ne kadar farklıysa çıktı o kadar büyür.
  - Ders sonrası not: Hoca son durumda sonucu 4 dedi ve tahtaya da 4 yazdı; doğrusu $-4+0+10=6$'dır.
- Yüksek geçiren süzgeç örneği: merkez 3, komşular 1 ise $3\cdot8-8\cdot1=16$; her yer 3 ise $24-24=0$.
- Işıklılık formülü: hoca merkeze uzaklık olarak $Y=R^2+G^2+B^2$ yazdı.
  - Ders sonrası not: Merkeze uzaklık büyük olasılıkla $\sqrt{R^2+G^2+B^2}$ olmalıdır. Ayrıca YUV standardındaki Y büyük olasılıkla ağırlıklı bir toplamdır ($Y=0{,}299R+0{,}587G+0{,}114B$); derste geometrik bir sezgi olarak anlatıldı.
- Kızılötesi ve morötesi: hoca bir yerde kızılötesine doğru dalga boyunun küçüldüğünü söyledi.
  - Ders sonrası not: Kızılötesine doğru dalga boyu büyür (frekans düşer), morötesine doğru dalga boyu küçülür (frekans artar).
- Açma ve kapama uygulaması (ekrandan, 02:30:00): gürültülü parmak izi imgesine önce açma uygulanarak arka plandaki küçük gürültüler silinir, sonra kapama ile çizgilerdeki kopukluklar birleştirilir. Slayttaki ifadeler: $(A\ominus B)\oplus B=A\circ B$ ve $[(A\circ B)\oplus B]\ominus B=(A\circ B)\bullet B$.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
