# Ders 7 Genişletilmiş Notu: Görüntü İşleme Temelleri: Nokta ve Komşuluk İşlemleri, Renk, Frekans Uzayı ve Morfoloji

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sayısal İmgede Çözünürlük ve İmge Dosyaları
- 2. Işıklılık ve Renk Bileşenleri
- 3. Temel Geometrik İşlemler ve Ara Değerleme
- 4. İmge Pekiştirme: Nokta İşlemleri
- 5. Histogram ve Histogram Eşitleme
- 6. Piksel Komşuluk İşlemleri ve Konvolüsyon
- 7. Uzamsal Frekans, Alçak ve Yüksek Geçiren Süzgeçler
- 8. Kenar Bulma
- 9. Korelasyon ve Şablon Eşleme
- 10. Ortanca (Medyan) Süzgeci
- 11. Renk
- 12. Görüntülerin Frekans Uzayında İşlenmesi
- 13. Morfolojik İmge İşleme
- Örnek Sorular
- Dersin Toparlaması

## 1. Sayısal İmgede Çözünürlük ve İmge Dosyaları

### 1.1 İki tür çözünürlük

Önceki derste sayısal imgede iki çözünürlük tanımlanmıştı. Birincisi uzamsal çözünürlüktür: birim alana düşen piksel sayısı. İkincisi nicemleme (quantization) ile ilgilidir: her pikselin kaç bitle gösterildiği, yani bit derinliği. Kullanılan bit sayısı gösterilebilen gri seviye sayısını belirlediği için nicemleme de imgenin ayrıntısını etkiler. Bir imgenin bellekte kapladığı alanı da bu iki büyüklük birlikte belirler.

### 1.2 Bellek hesabı örneği

Slaytta şu örnek verildi (ekrandan, 00:20:00): 8 bit/piksel bit derinliğinde, 200x200 piksellik gri tonlu bir imge bellekte ne kadar yer kaplar?

- Piksel sayısı: $200\times200=40000$.
- Her piksel 8 bit $=1$ bayt ile gösterilir; toplam $40000$ bayt.
- $40000/1024\approx39$ KB.
- Renkli (RGB) imgede R, G, B için ayrı birer matris tutulduğundan sonuç 3 ile çarpılır: $3\times39$ KB (yaklaşık 117 KB).

Bu hesap, herhangi bir sıkıştırma algoritması kullanılmadığında geçerlidir. Dosyalar kayıplı ya da kayıpsız sıkıştırılarak da saklanabilir.

### 1.3 RAW ve BMP

En temel dosya tipi RAW'dır. Burada sıkıştırma yoktur; nicemlenmiş piksel değerlerinin bitleri arka arkaya dizilir. Farklı RAW çeşitleri vardır: pikseller dosyaya yukarıdan aşağı mı, soldan sağa mı dizilecek; renkli imgede her piksel için R, G, B arka arkaya mı yazılacak, yoksa önce bütün R düzlemi, sonra G, sonra B mi yazılacak? Bazı dosya tipleri RGB yerine önce ışıklılık bilgisini, sonra renk bileşenlerini dönüştürüp saklar (YUV).

BMP (ekrandan, 00:30:00) yaygın kullanılan, sıkıştırılmamış bir biçimdir. Genellikle her renk bileşeninin 8 bit/piksel olduğu 24 bitlik format kullanılır; gri tonlu imgeler 8 bit/piksel ile saklanır. RAW'dan farkı, piksel boyutu ve bit derinliği gibi bilgileri tutan bir başlık (header) kısmının bulunmasıdır. Hoca başlıkta dosya tipinin, boyutların, piksel derinliğinin, dpi değerlerinin ve sağlama (checksum) bilgilerinin bulunabileceğini; asıl veri kısmının başlıktan sonra başladığını anlattı.

Slayttaki MATLAB kodu (ekrandan, 00:30:00):

```matlab
clear all; close all; clc;   % değişkenleri temizle, pencereleri kapat, ekranı sil
Im=imread('cm.bmp');         % cm.bmp adlı dosyayı oku, ışıklılık (ve varsa renk)
                             % değerlerini Im değişkenine yükle
figure;imshow(Im)            % İmgeyi göster
```

Gri tonlu imgeler 2 boyutlu, renkli imgeler 3 boyutlu matris oluşturur. MATLAB'de `imread` TIFF, JPEG, GIF, PNG, PCX gibi pek çok biçimi açabilir; firmaların kendilerine özgü biçimleri de vardır.

## 2. Işıklılık ve Renk Bileşenleri

Hoca beyaz tahtada R, G, B eksenli bir koordinat sistemi çizdi (ekrandan, 00:25:00). Bir renk bu uzayda bir noktadır: R, G ve B eksenlerinde aldığı değerlerle (Kartezyen koordinatlar) tanımlanır. Aynı nokta başka bir yolla da tanımlanabilir:

- Noktanın merkeze uzaklığı: parlaklık seviyesi (Y).
- Alt düzlemdeki (B-G) izdüşümünün açısı: $\varphi$.
- Bir açı daha: $\theta$.

Böylece renk "iki açı ve bir parlaklık" olarak, yani kutupsal benzeri koordinatlarla gösterilir. Yalnız merkeze uzaklık bilinirse sadece parlaklık bilinir; rengi bulmak için açılara ihtiyaç vardır. Bu yüzden açılara renk bileşenleri denir. YUV uzayında Y parlaklık, U ve V renk bileşenidir. LAB uzayında L ışıklılık (luminance), A ve B renklilik (krominans) bileşenleridir.

Hoca merkeze uzaklığı $Y=R^2+G^2+B^2$ diye yazdı.

> **Ders sonrası not:** Merkeze olan Öklid uzaklığı büyük olasılıkla $\sqrt{R^2+G^2+B^2}$ olmalıdır. Ayrıca standart YUV'deki Y büyük olasılıkla bileşenlerin ağırlıklı toplamıdır ($Y=0{,}299R+0{,}587G+0{,}114B$). Derste anlatılan geometrik bir sezgidir.

## 3. Temel Geometrik İşlemler ve Ara Değerleme

### 3.1 Ters çevirme ve aynalama

İmge bir matristir. Ters çevirmek için aynı boyutta ikinci bir matris hazırlanır ve pikseller yer değiştirilerek yazılır: ilk satır sona, son satır başa gelir. Aynalamada ise sütunların yeri değiştirilir.

### 3.2 Döndürme

Bazı biyomedikal imgelerde (göğüs kafesi, MR) görüntü kaymış olabilir ve önce döndürülmesi gerekir. Döndürmede yeni piksel konumları eski piksellerle tam örtüşmez; bazı yerler ara değerlerde kalır. Bu boşluklara değer atamaya ara değerleme (interpolasyon) denir. Örneğin bir pikselin değeri $A$, sonrakinin $B$ ise aradaki boşluğa ortalama $(A+B)/2$ atanabilir; ya da bilineer, kübik gibi polinom tabanlı yöntemler kullanılır.

### 3.3 Öteleme

İmge ötelendiğinde açılan yere ne konacağına karar vermek gerekir: eski değerler bırakılabilir ya da sıfırla doldurulabilir.

### 3.4 Boyut değişikliği (yakınlaştırma)

Slaytta 3x3'lük bir imgenin 6x6'ya büyütülmesi gösterildi (ekrandan, 00:35:00). Her piksel değeri iki satır ve iki sütuna kopyalanır:

```text
A B C        A A B B C C
D E F   ->   A A B B C C
G H I        D D E E F F
             D D E E F F
             G G H H I I
             G G H H I I
```

Buna en yakın komşu ara değerlemesi (nearest neighbor interpolation) denir. Büyütme çok olursa kareselleşme etkisi göze batar. Daha iyi bir yol, A ile B arasındaki piksele iki komşunun ortalamasını, çaprazdaki piksele de dört komşunun ortalamasını yazmaktır; böylece parlaklık geçişleri yumuşar. Yazılımsal (dijital) yakınlaştırma kaliteyi düşürür, optik yakınlaştırma düşürmez (slayt metni). Küçültmede dört pikselin ortalaması alınıp tek piksele dönüştürülür. MATLAB'de `imresize` ve `reshape` kullanılabilir; hangi yöntemlerin bulunduğu için yardım belgelerine bakılmalıdır.

## 4. İmge Pekiştirme: Nokta İşlemleri

İmge pekiştirme (image enhancement, görüntü zenginleştirme), çeşitli nedenlerle kullanışsız olan bir imgeyi işleyerek görsel ve işlevsel olarak daha iyi hale getirmektir. Örneğin pozlama süresi yüzünden parlaklıkları düşük değerlerde toplanmış bir imge, parlaklıklar yeniden ayarlanınca daha anlaşılır olur. Hoca "image" yerine genelde "görüntü" dediğini, bazı hocaların "görüntü"nün videoyu da kapsadığını düşünüp "imge" dediğini belirtti.

### 4.1 Parlaklık ayarı

Slayttaki formül (ekrandan, 00:40:00):

$$g(x,y)=f(x,y)+b$$

$f$ giriş (orijinal) imge, $g$ çıkış imgesidir. Matrisin bütün elemanlarına $b$ eklenir. $b>0$ ise parlaklık artar, $b<0$ ise azalır; slaytta $b=-50$ ve $b=+50$ sonuçları gösterildi.

Dikkat edilmesi gereken nokta doymadır. 8 bitlik imgede değerler 0 ile 255 arasındadır. Değeri 240-255 arasındaki piksellere 20 eklenirse hepsi 255'i aşar ve 255'e kırpılır; parlak yerlerin hepsi aynı beyazlığa gelir ("renk patlaması"). Aynı durum karanlıkta da geçerlidir: 0-15 arasındaki piksellerden 20 çıkarılırsa hepsi 0 olur.

### 4.2 Karşıtlık ayarı

$$g(x,y)=a\,f(x,y)$$

$a>1$ ise karşıtlık artar, $a<1$ ise azalır. Neden? Yan yana değeri 1 ve 2 olan iki piksel düşünelim. $a=3$ ile çarpılınca $1\cdot3=3$ ve $2\cdot3=6$ olur. Aradaki fark 1'den 3'e çıkar; piksellerin parlaklıkları arasındaki ayrım büyür. Karşıtlığın azalması, gri tonların bir yere sıkışıp tüm aralığın kullanılmaması demektir. Aşırı karşıtlık da zararlıdır; amaç kullanışlı bir değere getirmektir.

### 4.3 Dönüşüm eğrileri

Parlaklık ve karşıtlık birlikte ayarlanarak düşük karşıtlıklı, karanlık bir uydu görüntüsü netleştirilebilir. Bunun için bir giriş-çıkış dönüşüm eğrisi tanımlanır. Hocanın sözlü örneğinde 0-15 arası giriş değerleri 0'da kalır; 16 → 0, 17 → 1, 18 → 2, 19 → 3 diye doğrusal artar; belli bir değerden sonra (ör. 240) çıkış sabitlenir. Slayttaki eğride (ekrandan, 00:45:00) 50'nin altı 0'a, 100'ün üstü 255'e gider; 50-100 arası doğrusal olmayan biçimde, 100'e yaklaştıkça hızla artar. MATLAB'de `imadjust` komutuyla parlaklık ve karşıtlık ayarlanır.

### 4.4 Eşikleme ve ikili imge

Eşik $T$ (ör. 25) seçilir. $T$'nin altındaki pikseller 0'a, üstündekiler 255'e atanırsa yeni imgede yalnız iki değer kalır. Buna eşikleme (thresholding), sonuca ikili (binary) imge denir. Değerler 255'e bölünerek normalize edilirse ikili imge 0 ve 1 değerlerini alır: 0 tamamen karanlık, 1 tam parlaklıktır.

### 4.5 Negatifleme

0 değeri 255'e, 255 değeri 0'a gider; düşük parlaklıklar yüksek, yüksekler düşük olur. Tıbbi görüntülerde damar ve doku yapılarını daha iyi görmek için kullanılabilir.

## 5. Histogram ve Histogram Eşitleme

### 5.1 Tanım

Histogram, her piksel seviyesinin imgede kaç kez bulunduğunu (frekansını) gösterir, $h(i)$ (ekrandan, 00:50:00). Örneğin 0 seviyesinde 1200, 1 seviyesinde 1300 piksel varsa bunlar 0-255 sırasıyla dizilir ve bir eğri çıkar. Cameraman imgesinde siyaha yakın palto yaklaşık 20 seviyesinde bir tepe oluşturur; arka plandaki parlak gökyüzü de 150-200 civarında bir tepe verir. Bir bölgede ne kadar çok piksel varsa tepe o kadar belirgin olur.

**Soru (hoca sordu):** Histogramın altında kalan alan neyi verir? **Cevap:** Bir öğrenci normalizasyonla 1 olacağını söyledi; hoca normalize edilmemiş histogramda toplamın 1 olmadığını belirtti. Doğru cevap: imgedeki toplam piksel sayısıdır, çünkü her seviyedeki piksel sayıları toplanmaktadır. Normalize edilmiş histogram ve birikimli dağılım (CDF) bu sorunun konusu değildi.

### 5.2 Histogramla imge değerlendirme

Histogram imge hakkında ön bilgi verir. Bütün pikseller 0-40 arasında toplanmışsa parlak piksel yoktur, imge karanlıktır ve karşıtlığı düşüktür. Tersine bütün değerler parlak bölgeye sıkışmışsa düşük seviyeli piksel yoktur. Slaytta (ekrandan, 00:55:00) iki polen imgesi karşılaştırıldı: histogramı ortada küçük bir alan kaplayan imgenin karşıtlığı düşük; histogramı geniş bir alanı kaplayan imgenin karşıtlığı yüksektir. Biyomedikal görüntülerde de değerlerin bütün aralığa yayılması istenir.

### 5.3 Histogram eşitleme ve germe

Temel fikir dar bir aralığı genişletmektir (stretch). Örneğin değerler 40 ile 120 arasındaysa 40 → 0, 120 → 255 yapılır, aradaki değerler aralığa dağıtılır. Doğrusal ya da doğrusal olmayan yöntemler vardır.

Doğrusal olmayan bir yaklaşım da şudur: çok pikselin bulunduğu aralığa daha geniş, az pikselin bulunduğu aralığa daha dar yer ayrılır. Slaytta (ekrandan, 01:00:00) bir yüzey imgesinin histogramı dar bir tepede toplanmıştı; eşitlemeden sonra histogram 0-255 aralığına yayıldı ve ayrıntılar belirginleşti. Hoca tahtadaki örnekte az piksel bulunan 0-80 aralığının 0-10 aralığına sıkıştırıldığını anlattı: 80 → 10, 0 → 0, 40 → 5. Bir lastik izleri ve uzaktan algılama imgesi örneklerinde de yoğun gri seviye aralığı (ör. 100-140) daha geniş bir aralığa çekildi.

### 5.4 Karşıtlık germe formülü

Hocanın sözlü anlattığı en basit yöntem: piksel değerinden imgedeki en küçük değer çıkarılır, en büyük ile en küçük değerin farkına bölünür ve en büyük gri ton değeriyle çarpılır:

$$g=\frac{f-f_{min}}{f_{max}-f_{min}}\cdot255$$

<!-- BELİRSİZ: formül altyazıdan kuruldu; o anın karesi (01:00:10) yok. -->

Böylece histogramdaki boş kısımlar da kullanılır. Buraya kadarki bütün işlemlere nokta işlemleri (point operations) denir: yalnız pikselin kendi değeri değiştirilir, komşulara bakılmaz.

## 6. Piksel Komşuluk İşlemleri ve Konvolüsyon

### 6.1 Komşuluk işlemi nedir

Slayttaki tanım (ekrandan, 01:15:00): parlaklık, karşıtlık gibi noktasal işlemlerde pikselin değeri yalnız kendisine bağlı değişir. Komşuluk işlemlerinde yeni değer komşu piksellerin değerleri de dikkate alınarak hesaplanır. Tek başına pek anlam taşımayan bir piksel, komşularıyla birlikte daha fazla bilgi içerir (ör. kenar bilgisi). Komşuluk işlemlerinin hesap yükü noktasal işlemlerden fazladır.

### 6.2 Konvolüsyon

Bir konvolüsyon kerneli seçilir (3x3, 5x5, 7x7...). Kernelin merkezi (hotspot) sırayla her pikselin üzerine getirilir; kernel değerleri altındaki piksellerle çarpılır, çarpımlar toplanır ve sonuç yeni imgede merkez pikselin yerine yazılır. Merkezden bir komşuluk 3x3, iki komşuluk 5x5, üç komşuluk 7x7 kernel verir.

Konvolüsyonda kernel hem x hem y yönünde ters çevrilerek çarpılır: kernelin sol üst elemanı imge parçasının sağ alt elemanıyla çarpılır. Kernel baştan ters çevrilirse birebir çarpım yapılabilir.

Slayttaki örnek (ekrandan, 01:20:00):

$$k=\begin{bmatrix}-1&-1&-1\\-2&10&-2\\-1&-1&-1\end{bmatrix},\qquad f=\begin{bmatrix}50&75&77\\48&70&83\\51&68&85\end{bmatrix}$$

Değeri değiştirilecek piksel ortadaki 70'tir. Genel ifade:

$$g(x,y)=\sum_{i=-1}^{1}\sum_{j=-1}^{1}k(i,j)\,f(x-i,y-j)$$

Slayttaki açık hesap:

$$g=(-1\cdot85)+(-1\cdot68)+(-1\cdot51)+(-2\cdot83)+(10\cdot70)+(-2\cdot48)+(-1\cdot77)+(-1\cdot75)+(-1\cdot50)$$

Ara adımlar (ara adım eklendi): negatif terimlerin toplamı $85+68+51+166+96+77+75+50=668$; pozitif terim $700$; sonuç $700-668=32$. Kernel simetrik olduğundan ters çevrilse de aynı sonuç çıkar (python ile doğrulandı). MATLAB'de iki boyutlu konvolüsyon `conv2` ile yapılır.

### 6.3 Kenar pikselleri sorunu

Kernel imgenin köşesine geldiğinde bir kısmı imgenin dışında kalır. Çözümler:

- Dışarıyı sıfır kabul etmek (sıfır doldurma).
- Aynalama: kenardaki piksel değerleri dışarıya yansıtılarak imge genişletilir; süreklilik sağlanır. Büyük kernelde daha uzak pikseller de yansıtılır.
- Yalnız iç kısımlarda çalışmak.

### 6.4 Düşey kenar bulan kernel

Slayttaki kernel (ekrandan, 01:25:00):

$$\begin{bmatrix}-1&0&1\\-2&0&2\\-1&0&1\end{bmatrix}$$

Merkezin solundaki pikseller negatif, sağındakiler pozitif değerle çarpılır. Hoca yalnız orta satırı $[-2\;0\;2]$ kullanarak tahtada hesapladı (ekrandan, 01:25:00):

- Komşular 2 ve 3: $-2\cdot2+2\cdot3=-4+6=2$.
- Komşular 2 ve 2 (hepsi aynı): $-4+4=0$.
- Komşular 2 ve 5: $-4+0+10=6$.

> **Ders sonrası not:** Hoca son durum için sonucu 4 dedi ve tahtaya da 4 yazdı; doğrusu $-4+0+10=6$'dır (python ile doğrulandı). Sonuç değişmez: sol ve sağ komşular ne kadar farklıysa çıktı o kadar büyür.

Sol tarafın sağ taraftan farklı olduğu yerler yatayda değişim gösteren, yani düşey kenarlardır. Ev örneğinde pencere ve duvar kenarları gibi düşey çizgiler parlak çıktı. Demek ki bu kernel düşey kenar bulucudur. Kernelin değerleri, işlemin amacını belirler.

### 6.5 Diğer kernel örnekleri ve hesap yükü

- Merkezi 1, gerisi 0 olan kernel imgeyi değiştirmez; impuls (delta) fonksiyonu gibidir.
- 1 ve −1 içeren kaydırıp çıkaran kernel komşu farkını alır; hocanın anlatımına göre çapraz kenarları bulur.
- Merkezi 1, komşuları $-1/8$ olan kernel pikselden çevresinin ortalamasını çıkarır; bütün yönlerdeki kenarlarda yüksek değer verir. Hoca bir $k$ katsayısı artırıldıkça kenarların daha çok belirginleştiğini, buna kenar pekiştirme kerneli dendiğini söyledi. <!-- BELİRSİZ: k katsayısının kernelde nerede durduğu altyazıdan çıkmıyor, o anın karesi yok. -->

Her piksel için çarpma-toplama yapıldığından imge büyüdükçe hesap zorlaşır. Bazı büyük kerneller ayrılabilir hale getirilebilir: bir kez yatayda, bir kez düşeyde çalışan iki tek boyutlu kernele bölünür ve hesap kolaylaşır.

> **Ek bilgi (derste anlatılmadı):** Ayrılabilir bir $N\times N$ kernel, bir sütun vektörü ile bir satır vektörünün çarpımı olarak yazılabilir. Bu durumda piksel başına $N^2$ yerine yaklaşık $2N$ çarpma gerekir. Örneğin $[1\;2\;1]^T[1\;2\;1]$ çarpımı $\begin{bmatrix}1&2&1\\2&4&2\\1&2&1\end{bmatrix}$ Gauss kernelini verir.

## 7. Uzamsal Frekans, Alçak ve Yüksek Geçiren Süzgeçler

### 7.1 Uzamsal frekans

Slayttaki tanımlar (ekrandan, 01:30:00): imgede pikseller arasındaki yumuşak geçiş uzamsal düşük frekanslara, sert geçiş (kenarlar, nesne sınırları) uzamsal yüksek frekanslara karşılık gelir. Hoca tahtada bir satırdaki 2, 2, 3, 2, 2 gibi az değişen değerleri gösterdi; bu satır analog olarak çizilse yavaş değişen bir eğri olur. Birden artan değerler ise bir kenardır; böyle keskin bir geçişi oluşturmak için çok sayıda yüksek frekanslı sinüs gerekir. Bir işaretin frekansı DFT/FFT ile nasıl bulunuyorsa, imgenin bir satırının FFT'si de bu bileşenleri gösterir.

### 7.2 Alçak geçiren (yumuşatma) süzgeçleri

Merkez pikselin yeni değeri olarak çevredeki piksellerin ortalaması yazılırsa kenar geçişlerine ara değerler girer ve imge bulanıklaşır. 3x3 komşulukta 9 piksel olduğundan her biri $1/9$ ile çarpılır; 5x5'te $1/25$ ile. Bunlara ortalama alan süzgeçler denir. Kernel büyüdükçe daha uzak ve merkezle daha az ilişkili pikseller ortalamaya katıldığı için yumuşatma artar.

Farklı biçimler de mümkündür:

- Yalnız kuzey, güney, doğu ve batı komşularını almak.
- Merkez pikselin kendisini katmayıp yalnız çevrenin ortalamasını almak.
- Merkezin ağırlığını artırıp çevrenin katkısını azaltmak: Gauss kernelleri.

Slayttaki Gauss kernelleri (ekrandan, 01:35:00):

$$\begin{bmatrix}0&1&0\\1&2&1\\0&1&0\end{bmatrix},\quad\begin{bmatrix}1&4&1\\4&16&4\\1&4&1\end{bmatrix},\quad\begin{bmatrix}1&2&1\\2&4&2\\1&2&1\end{bmatrix},\quad\begin{bmatrix}1&2&4&2&1\\2&4&8&4&2\\4&8&16&8&4\\2&4&8&4&2\\1&2&4&2&1\end{bmatrix}$$

Bu kernellerde merkezden uzaklaştıkça ağırlık azalır (hoca tahtaya çan eğrisi çizdi); ilişkisiz uzak pikseller daha az hesaba katılır.

> **Ek bilgi (derste anlatılmadı):** Yumuşatma kernelleri genellikle elemanlarının toplamına bölünerek normalize edilir (ör. $1\;4\;1/4\;16\;4/1\;4\;1$ kerneli için 36). Böylece düz bölgelerde imgenin ortalama parlaklığı değişmez.

### 7.3 Yüksek geçiren süzgeçler

Merkez 8 ile, sekiz komşu −1 ile çarpılır. Hocanın sayısal örneği:

- Merkez 3, komşular 1: $3\cdot8-8\cdot1=24-8=16$.
- Her yer 3 (düz bölge): $3\cdot8-8\cdot3=24-24=0$.

Değişim olmayan bölgelerde sonuç 0, çevreden farklı olan yerlerde büyük değer çıkar. Yatay ve düşey kenarları ayrı ayrı bulan süzgeçler de tasarlanabilir. Yüksek frekans kenar geçişlerinde olduğu için bu süzgeçler kenar piksellerini ortaya çıkarır.

## 8. Kenar Bulma

Kenar bulmanın en büyük sorunu gürültüdür: gürültülü bir piksel çevresinden farklı parlaklıkta olduğundan kenar gibi algılanır. Bu yüzden adımlar şöyledir:

- Önce gürültü azaltılır (alçak geçiren süzgeç).
- Sonra kenarlarda yüksek tepki veren bir süzgeçle (maske, kernel; burada eş anlamlı) kenarlar pekiştirilir.
- En son kenar tespit algoritması çalıştırılır.

Slayttaki karşılaştırmada (ekrandan, 01:40:00) bir yol görüntüsüne doğrudan kenar bulma uygulanınca gürültülü her yerde değerler arttı; önce alçak geçiren süzgeç (AGS) uygulanınca kenarlar daha temiz çıktı.

Hazır kenar kernellerinden Prewitt kerneli komşuların farkını alır: kuzey-güney yönünde eksi ve artı değerler varsa bir üst ve bir alt pikselleri karşılaştırarak yatay geçişleri bulur; kernel döndürülürse sol-sağ farkıyla düşey kenarları bulur. Sobel kernelinde merkeze en yakın komşuların fark ağırlığı artırılmıştır. En bilinen kenar bulma yöntemleri: Prewitt, Sobel, Laplacian of Gaussian, Roberts, Zero Cross ve Canny. Hocaya göre en iyi sonucu veren ve en çok kullanılan Canny'dir.

> **Ek bilgi (derste anlatılmadı):** Sobel'in yatay türev kerneli derste düşey kenar örneği olarak gösterilen $\begin{bmatrix}-1&0&1\\-2&0&2\\-1&0&1\end{bmatrix}$ kernelidir; Prewitt'te orta satır da $[-1\;0\;1]$'dir. Canny yöntemi Gauss yumuşatma, gradyan hesabı, maksimum olmayanları bastırma ve iki eşikle histerezis adımlarından oluşur.

## 9. Korelasyon ve Şablon Eşleme

Korelasyonda orijinal imgenin üzerinde bir filtre ya da imge parçası (şablon) gezdirilir. Konvolüsyondan farkı, kernel elemanlarının ters çevrilmeden doğrudan kendi konumlarındaki piksellerle çarpılmasıdır. Şablon imgenin bir bölgesine ne kadar benziyorsa korelasyon o kadar yüksek, ne kadar alakasızsa o kadar düşük çıkar.

Hocanın örnekleri:

- Harflerden oluşan bir imgede "M" şablonu gezdirilir; korelasyon değerleri M harflerinin bulunduğu yerlerde tepe yapar.
- Matkap uçları arasında sağlam olanı bulmak: sağlam ucun üçgen biçimli şablonu en çok benzediği yerde en parlak sonucu verir; aşınmış uçlarda daha düşük değer çıkar. Bir eşik değeriyle sağlam uç bulunur.

## 10. Ortanca (Medyan) Süzgeci

KxK (ör. 3x3) penceredeki bütün piksel değerleri alınır, sıralanır ve ortadaki değer yeni piksel değeri olarak yazılır.

Slayttaki deney (ekrandan, 01:45:00): madeni para imgesine tuz-biber gürültüsü eklendi. Alçak geçiren süzgeç yumuşatma yaptı ama gürültüyü yok edemedi, çünkü gürültülü pikseller de ortalamaya katılıyordu. Ortanca süzgeci çok daha iyi sonuç verdi.

**Soru (hoca sordu):** Ortanca süzgeci neden daha iyi? **Cevap:** Bir öğrenci Gauss benzeri bir işlev olup olmadığını sordu; hoca hayır dedi. Tuz-biber gürültüsü uç değerlerde (0 ya da 255) oluşur ve imgenin az bir kısmını kaplar. Sıralamada bu değerler uçlarda kalır; 3x3 pencerede çoğunluk olan değer (genellikle arka plan) ortada kalır. Böylece gürültü ayıklanır ve kenarlar da korunur.

## 11. Renk

### 11.1 Işık bir elektromanyetik dalgadır

Işık, radyo dalgaları, elektrik hatlarındaki dalgalar, TV, mikrodalgalar, kızılötesi, gama ve kozmik ışınlar elektrik alan ile ona dik manyetik alandan oluşan elektromanyetik dalgalardır. Gözümüz bunların yalnız dar bir bölgesini, yaklaşık 400-700 nm dalga boyunu görür (ekrandan, 01:50:00). Kabaca 400-500 nm mavi, 500-600 nm yeşil, 600-700 nm kırmızı olarak adlandırılır; daha dar bantlar da tanımlanabilir. Hoca tahtada periyodun $T=1/f$ olduğunu, $T$ küçülünce frekansın arttığını çizdi; dalga boyu için de aynı ilişki geçerlidir.

**Soru (hoca sordu):** 400 nm mi, 700 nm mi daha büyük dalga boyudur; büyük dalga boyu yüksek mi düşük mü frekansa işaret eder? **Cevap:** 700 nm daha büyüktür; dalga boyu büyükse frekans düşüktür.

**Soru (hoca sordu):** Görünür ışıkta mavi mi kırmızı mı daha yüksek frekanslıdır? **Cevap:** Mavi; dalga boyu daha kısa olduğu için.

> **Ders sonrası not:** Hoca bir yerde kızılötesi bantlarda dalga boyunun küçüldüğünü söyledi. Doğrusu: kızılötesine doğru dalga boyu büyür (frekans düşer), morötesine doğru dalga boyu küçülür (frekans artar).

Cep telefonlarını çalıştıran dalgalarla ışık arasında fiziksel bir fark yoktur; gözümüz yalnız 400-700 nm'yi görmeye özelleşmiştir. Hoca, mikrodalga fırının içini görebilseydik beynimizin ona da bir renk atayacağını söyledi. Gözün arkasındaki koni ve çubuk hücreleri renk ve parlaklığı ayırır; algı beyinde, analog ve çok karmaşık biçimde oluşur.

### 11.2 RGB ve CMY

Her piksel üç değerle (R, G, B) gösterilir. Tahtadaki örnekler (ekrandan, 01:55:00):

- (255, 255, 255): beyaz; (0, 0, 0): siyah.
- (255, 0, 0): en parlak kırmızı; (128, 0, 0): daha düşük parlaklıkta kırmızı; (5, 0, 0): çok karanlık kırmızı.
- (128, 128, 0): kırmızı ve yeşil karışımı, sarı.

Slayttaki ilişkiler: RGB'de Magenta = Red + Blue, Cyan = Blue + Green, Yellow = Green + Red. CMY'de ara renkler ana renk yapılır: Magenta = White − Green, Cyan = White − Red, Yellow = White − Blue. Koordinat sistemi istenildiği gibi seçilebileceği için RGB yerine CMY de kullanılabilir.

### 11.3 Renkli imgenin düzlemleri

Kırmızı bir elmayı kırmızı görmemizin nedeni, elmanın uzun dalga boylu kırmızı ışığı yansıtıp mavi ve yeşili yutmasıdır; kamera ya da göz yalnız yansıyanı algılar. Renkli imge R, G, B olmak üzere üç düzlemden (matristen) oluşur. Elmaya karşılık gelen pikseller R düzleminde parlak, B düzleminde karanlık (siyah) çıkar; mavi bileşenin olduğu yerlerde B düzlemi parlaklaşır.

### 11.4 Renk modelleri

Renk üzerine ciddi çalışmalar ve CIE (Commission Internationale de l'Éclairage) standartları vardır. Bilinen modeller: RGB, CMY (cyan, magenta, yellow) ve ışıklılık ile renkliliği ayıran HSI/HSV (Hue, Saturation, Intensity/Value). Normalize RGB küpünde bütün bileşenleri eşit olan noktalar küpün köşegenindeki gri hattı oluşturur.

## 12. Görüntülerin Frekans Uzayında İşlenmesi

### 12.1 Fourier dönüşümünün hatırlatılması

Bir işaret onu oluşturan pek çok sinüsün toplamı olarak yazılabilir. Hoca ayrık Fourier dönüşümünü hatırlattı:

$$X[k]=\sum_{n} x[n]\,e^{-j\frac{2\pi}{N}nk}$$

Sürekli halde $X(\omega)=\int_{-\infty}^{\infty}x(t)\,e^{-j\omega t}\,dt$. Her ikisi de işaretin farklı frekanslardaki temel fonksiyonlarla çarpımıdır. Sayısal halde frekans $[-\pi,\pi]$ (ya da $[0,2\pi]$) aralığında incelenir ve en yüksek frekanslar $\pi$'ye yakındır. Fourier katsayıları karmaşıktır; genlik $\sqrt{\mathrm{Re}^2+\mathrm{Im}^2}$, faz $\theta=\arctan(\mathrm{Im}/\mathrm{Re})$ ile bulunur.

İmgede yatay ya da düşey doğrultudaki parlaklık değişimleri tek boyutlu diziler gibi düşünülebilir. Kenar geçişlerinin yoğun olduğu yerler yüksek frekanslı bileşenlere, yumuşak geçişler düşük frekanslara karşılık gelir.

### 12.2 Frekans uzayında işlem akışı

Slayttaki şema (ekrandan, 02:15:00):

```text
I(x,y)  --Fourier dönüşümü F-->  F(u,v)
   |                               |
 uzamsal işlem               frekans işlemi
   v                               v
I'(x,y) <--ters dönüşüm F^-1--  F'(u,v)
```

Frekans uzayına geçmenin faydası, uzamsal uzayda görülmeyen bilgiler üzerinde daha basit işlemler yapıp geri dönebilmektir.

### 12.3 Örnekler

- Gürültü eklenince iki boyutlu Fourier genlik görüntüsünde merkezden uzak (yüksek frekans) bölgeler parlaklaşır. Merkezdeki yüksek değerler alçak frekans bileşenleridir.
- Yumuşatma süzgecinden sonra spektrum merkezde daha dar bir alana toplanır.
- Hocanın örneği: ortası beyaz bir kare, arka planı koyu, her ikisi de gürültülü bir imge (parlaklıklar yükseklik olarak çizilince bir küp gibi görünür). DFT'de alçak frekanslar ortada, küçük yüksek frekans bileşenleri çevrede görülür. Belli bir merkez alandaki katsayılar korunup gerisi sıfırlanırsa (alçak geçiren süzgeç) ters dönüşümden sonra gürültüler kaybolur, karenin kenarları eğimli yükselir. Bu, kernelle yapılan yumuşatmanın frekans uzayındaki daha basit karşılığıdır.
- Merkez sıfırlanıp yalnız yüksek frekanslar bırakılırsa (yüksek geçiren süzgeç) sonuç yalnız geçişlerde, yani kenarlarda yüksek değer alır; içeride ve dışarıda düşük değerler kalır.

## 13. Morfolojik İmge İşleme

### 13.1 Tanım ve kullanım alanı

Morfoloji "şekil bilim" demektir; nesnelerin şekilleriyle ilgilenilir. Slayta göre (ekrandan, 02:20:00) morfolojik işlemler ikili (binary) imgelerin analizinde, kenar bulma, gürültü giderme, pekiştirme ve bölütleme gibi uygulamalarda kullanılır; morfolojik filtreleme, inceltme (thinning) ve budama (pruning) gibi ön/son işlemlerde de sıkça başvurulur. İki temel işlem yayma (dilation, $\oplus$) ve aşındırma (erosion, $\ominus$)'dır. Bunların arka arkaya uygulanmasıyla açma (opening) ve kapama (closing) tanımlanır.

### 13.2 Yayma

İki imge vardır: orijinal imge ve yapı elemanı (structuring element). Yapı elemanı kernel gibidir; kare, yuvarlak ya da başka şekillerde olabilir. Yapı elemanı imge üzerinde gezdirilir; altında en az bir tane 1 varsa merkez piksel 1 yapılır. Nesneler genişler, birbirine yakın nesneler birleşir, küçük boşluklar kapanır. Gürültü sayılabilecek küçük deliklerin kapatılmasında kullanılır.

Slayttaki tek boyutlu örnek (ekrandan, 02:25:00), yapı elemanı `1 1 1`:

```text
Giriş  :  1 0 0 0 1 1 1 0 1 1
Çıkış  :  _ 1 0 1 1 1 1 1 1 _
```

Adım adım: ikinci konumda pencere `1 0 0` içinde bir 1 vardır, sonuç 1. Üçüncü konumda pencere `0 0 0`, sonuç 0. Dördüncü konumda `0 0 1`, sonuç 1. Sonraki konumlarda pencerede hep en az bir 1 bulunur; sekizinci konumdaki tek 0 (`1 0 1`) da 1 olur, yani aradaki boşluk kapanır. Uçlardaki konumlar pencere dışarı taştığı için boş bırakılmıştır (python ile doğrulandı).

### 13.3 Aşındırma

Yapı elemanının altında bir tane bile 0 varsa merkez 0 yapılır; merkez yalnız pencerenin tamamı 1 ise 1 kalır. Böylece yalnız yapı elemanının tamamen içine sığan kısımlar korunur, nesneler daralır (erozyon). Hocanın örneğinde geniş nesne bölümünün yalnız ortasındaki pikseller 1 kaldı, küçük nesneler tamamen silindi.

### 13.4 Açma ve kapama

- Açma: önce aşındırma, sonra yayma. Önce nesnelerin kenarlarındaki fazlalıklar ve küçük parçacıklar yok edilir, sonra kalanlar yeniden genişletilir. Önce daralttığı sonra açtığı için bu adı alır. Kenar çıkıntıları gider, nesneler daha düzgün ve yuvarlağımsı olur. Belli büyüklükteki parçacıkların kalması istendiğinde kullanılır.
- Kapama: önce yayma, sonra aşındırma. Önce boşluklar dolar, sonra nesne eski boyutuna inceltilir. Nesnelerdeki küçük delikleri ve kopuklukları gidermek için kullanılır.

MATLAB'de `imopen` ve `imclose` komutlarıyla yapılır.

Slayttaki parmak izi örneği (ekrandan, 02:30:00): gürültülü arka planlı ikili parmak izi imgesine önce aşındırma, sonra yayma uygulanarak açma yapılır; arka plan gürültüsü gider. Ardından kapama ile çizgilerdeki kopukluklar birleştirilir. Slayttaki ifadeler:

$$(A\ominus B)\oplus B=A\circ B,\qquad [(A\circ B)\oplus B]\ominus B=(A\circ B)\bullet B$$

Hoca görüntü sıkıştırma, video sıkıştırma biçimleri ve hareket kestirme slaytlarını dersin kapsamı dışında bıraktı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): 8 bit/piksel bit derinliğinde, 200x200 piksellik gri tonlu bir imge bellekte ne kadar yer kaplar? Renkli olsaydı ne olurdu?

> **Çözüm:** $200\times200=40000$ piksel, her biri 1 bayt; $40000$ bayt $=40000/1024\approx39$ KB. RGB'de üç düzlem olduğu için $3\times39\approx117$ KB. Sıkıştırma olmadığı varsayılır.

**Soru 2** (ekrandan, 01:20:00): Kernel $\begin{bmatrix}-1&-1&-1\\-2&10&-2\\-1&-1&-1\end{bmatrix}$ imge parçası $\begin{bmatrix}50&75&77\\48&70&83\\51&68&85\end{bmatrix}$'ye uygulanırsa merkezdeki 70 pikselinin yeni değeri nedir?

> **Çözüm:** $700-(85+68+51+2\cdot83+2\cdot48+77+75+50)=700-668=32$.

**Soru 3** (ekrandan, 01:25:00): $[-2\;0\;2]$ satırı, komşu değerleri (2, 2), (2, 3) ve (2, 5) olan piksellere uygulanırsa hangi değerler çıkar? Kernel ne işe yarar?

> **Çözüm:** $0$, $2$ ve $6$. Sol ve sağ komşu farkı büyüdükçe çıktı büyür; tam kernel düşey kenarları bulur. (Hoca son değeri 4 dedi; doğrusu 6.)

**Soru 4** (derste sözlü, 00:50:04): Histogramın altında kalan alan neyi verir?

> **Çözüm (derste verildi):** İmgedeki toplam piksel sayısını.

**Soru 5** (derste sözlü, 01:45:05): Tuz-biber gürültüsünde ortanca süzgeci neden alçak geçiren süzgeçten daha iyi sonuç verir?

> **Çözüm (derste verildi):** Gürültü uç değerlerde (0/255) ve seyrektir; sıralamada uçlarda kalır, ortanca değer çoğunluğu (arka planı) temsil eder. Ortalama ise gürültüyü de hesaba katar.

**Soru 6** (derste sözlü, 01:49:12 ve 01:50:28): 400 nm ile 700 nm'den hangisinin dalga boyu büyüktür? Görünür ışıkta mavi mi kırmızı mı daha yüksek frekanslıdır?

> **Çözüm (derste verildi):** 700 nm; dalga boyu büyük olduğundan frekansı düşüktür. Mavinin dalga boyu daha kısa olduğu için frekansı daha yüksektir.

**Soru 7** (ekrandan, 01:55:00): (128, 128, 0) RGB değerli piksel hangi renktir?

> **Çözüm (derste verildi):** Kırmızı ve yeşil karışımı olduğundan sarı (orta parlaklıkta).

**Soru 8** (ekrandan, 02:25:00): Giriş `1 0 0 0 1 1 1 0 1 1`, yapı elemanı `1 1 1` ise yayma sonucu nedir?

> **Çözüm:** İç konumlar için `1 0 1 1 1 1 1 1` (uçlar boş). Sekizinci konumdaki 0 kapanır, üç sıfırlık boşluk tek sıfıra iner.

## Dersin Toparlaması

Bu derste görüntü işlemenin temel araçları bir arada görüldü. İmgenin bellek boyutunu uzamsal çözünürlük ve bit derinliği belirler; BMP ve RAW gibi biçimler pikselleri farklı düzenlerle saklar. Nokta işlemleri (parlaklık, karşıtlık, dönüşüm eğrileri, eşikleme, negatifleme, histogram eşitleme) yalnız pikselin kendi değerini değiştirir. Histogram, imgenin karşıtlığı hakkında ön bilgi verir. Komşuluk işlemlerinin temeli konvolüsyondur ve kernelin değerleri onun yumuşatma, kenar bulma ya da kenar pekiştirme yapacağını belirler. Kenar bulmadan önce gürültü giderilmeli; tuz-biber gürültüsünde ortanca süzgeci en iyi sonucu verir. Korelasyon şablon aramada kullanılır.

Renk bölümünde ışığın elektromanyetik bir dalga olduğu, RGB/CMY modelleri ve renkli imgenin üç düzlemi anlatıldı. Ardından aynı süzgeçleme fikrinin frekans uzayında, Fourier katsayılarının bir kısmı sıfırlanarak nasıl yapılacağı gösterildi. Son olarak ikili imgelerde yayma, aşındırma, açma ve kapama işlemleri görüldü. Hoca bir sonraki derste görüntü işleme ile makine öğrenmesini birlikte ele alacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
