# Ders 13 Genişletilmiş Notu: Proje Sunumları: Hough Çemberleri, Stil Aktarımı, Bölütleme, Gürbüz En Küçük Kareler ve Stereo SLAM

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Çember İçin Hough Dönüşümü
- 2. pSp: StyleGAN Kodlayıcısıyla Görüntüden Görüntüye Çeviri
- 3. GAN ile Hızlı ve Keyfi Stil Aktarımı
- 4. İnsansız Hava Aracı Görüntülerinde Gerçek Zamanlı Anlamsal Bölütleme
- 5. Dijital Patolojide Stil Aktarımıyla Genelleme
- 6. Gürbüz En Küçük Kareler Yöntemleri
- 7. Stereo Görmeye Dayalı Anlamsal 3B Nesne ve Ego-Hareket İzleme
- Örnek Sorular
- Dersin Toparlaması

Bu ders dönemin son kaydıdır ve öğrencilerin proje sunumlarından oluşur. Her öğrenci (ya da grup) bir makaleyi ya da yöntemi anlatmış, bazıları kendi yazdığı kodu göstermiştir. Hoca sunumlar sırasında sorular sorarak kavramları netleştirmiştir. Aşağıda sunumların akademik içeriği ders sırasıyla verilmiştir.

## 1. Çember İçin Hough Dönüşümü

### 1.1 Doğru için Hough dönüşümünü hatırlama

Sunum, derste görülen doğru için Hough dönüşümünü hatırlatarak başladı. Hough dönüşümü, $x$-$y$ düzlemindeki bir noktanın bir parametre uzayına dönüştürülmesidir. Parametre uzayı aranan nesnenin şekline göre tanımlanır. Doğru $y = ax + b$ biçiminde yazılırsa $x$ eksenine dik doğrularda eğim $a$ sonsuza gider ve parametre uzayı sonsuz büyüklükte olur. Bu yüzden doğru bir $\theta$ açısı ve $r$ uzaklığı ile temsil edilir:

$$r = x\cos\theta + y\sin\theta$$

> **Ders sonrası not:** Altyazıda formül "r eşittir x kosinüs teta artı y kosinüs teta" diye geçiyor. Doğru gösterim yukarıdaki gibidir: ikinci terim $y\sin\theta$'dır.

### 1.2 Çemberin parametre uzayı

Çemberin parametreleri doğrudan parametre uzayına aktarılabildiği için, çemberin parametre uzayında gösterilmesi doğruya göre aslında daha basittir. Bir çember sabit bir $r$ yarıçapı ve merkezinin bulunduğu $(a,b)$ konumuyla tanımlanır (ekrandan, 00:10:00):

$$(x_1 - a)^2 + (x_2 - b)^2 = r^2$$

Sunumda, pratikte çoğu uygulamanın $a$ ve $b$'yi ayrı bir dönüşümle bulmaya uğraşmadığı, bunları doğrudan görüntü koordinatlarıyla eşleştirdiği anlatıldı. Hızlı çalışan uygulamalar parametrik biçimi kullanır:

$$x = a + r\cos\theta, \qquad y = b + r\sin\theta$$

Burada $\theta$ değerleri 360 derecenin tamamı yerine belirli aralıklarla önceden belirlenir ve kosinüs/sinüs değerleri bir tabloda tutulur. Böylece her seferinde trigonometrik hesap yapılmadan noktalar doğrudan parametre uzayına aktarılır.

Doğruya göre en büyük dezavantaj, parametre uzayının iki değil üç boyutlu olmasıdır: $(a, b, r)$. Sunumda bu "parametre uzayı $R^2$ değil $R^3$ olur" diye ifade edildi.

### 1.3 Ön işlem: kenar bulma

Hough dönüşümünden önce görüntüye bir kenar bulucu uygulanır. Yaygın seçenekler Sobel, Canny ve morfolojik işlemlerdir. Frekans uzayında da çalışılabilir: görüntünün Fourier dönüşümü alınır, kenarlar yüksek frekanslı bileşenler olduğu için yüksek geçiren süzgeç uygulanır, sonra ters Fourier dönüşümüyle görüntüye dönülür. Bu yolun formülü ve kodu basittir ama algoritmayı yavaşlatır.

Sunumdaki deneyime göre Sobel karmaşık görüntülerde çok gürültü üretir ve gürültüye duyarlı olan Hough dönüşümü bu yüzden çok sayıda yanlış sonuç verir; yalnız çok yalın nesnelerde iş görür. Canny ise kenarları daha net ve düzgün çıkarır; sunumdaki örneklerde Canny kullanıldı.

### 1.4 Oylama ve merkez bulma

Doğru için kullanılan toplama (biriktirme) mantığı burada da geçerlidir. Belirlenen bir $r$ için her kenar noktasının çevresine $r$ yarıçaplı bir çember çizilir. Bu çemberlerin geçtiği her biriktirici hücresinin değeri artırılır. Tüm kenar noktaları işlendikten sonra biriktiriciye bir eşik uygulanır. Eşiğin üzerinde kalan, yoğunluğun en fazla olduğu nokta çemberin merkezidir. $r$ zaten bilindiği için merkez bulununca çember de bulunmuş olur.

Bu işlem aranan yarıçap aralığının başından sonuna kadar uygulanır. Aranan nesnenin görüntüde kapladığı yarıçap biliniyorsa yalnız o yarıçap aranarak yöntem çok hızlandırılabilir. Aralık geniş tutulursa çizilecek çember ve hesaplanacak yoğunluk sayısı artar, işlem çok uzar.

**Örnek: iç içe iki çember (ekrandan, 00:15:00).** Slaytta yarıçapları 20 ve 25 olan, iç içe geçmiş iki çember vardır. $r=20$ aramasında her kenar noktasının çevresine 20 yarıçaplı çember çizilir. Birinci çemberin kenar noktalarından çizilen çemberler onun merkezinde üst üste biner ve orada parlak bir nokta oluşur. İkinci çemberin noktalarından çizilen çemberler ise tek noktada buluşmaz, hale benzeri dağınık bir yoğunluk bırakır ve eşiği geçmez. $r=25$ aramasında durum tersine döner: ikinci çemberin merkezinde parlak nokta oluşur. Yarıçap genellikle atlamalı olarak (20, 21, 22, ..., 25) taranır.

### 1.5 Algoritmanın akışı ve parametre uzayının yapısı

Algoritma şöyle özetlendi:

- Görüntüye kenar bulucu (Canny) uygulanır.
- Her yarıçap için her kenar noktasının çevresine çember çizilir ve biriktiricide yoğunluklar toplanır.
- Bir sonraki yarıçapa geçilip işlem tekrarlanır.
- Elde edilen toplamlar bir eşikten geçirilir; eşiği geçen noktalar çember merkezleri, ait oldukları katman da yarıçaplarıdır.
- Bulunan çemberler parametre uzayından orijinal görüntüdeki konumlarına aktarılır.

Gizli bir slaytta parametre uzayı bir koni olarak gösterildi (ekrandan, 00:30:00): eksenler $a$, $b$ ve $r$'dir. Sabit bir görüntü noktasından geçen bütün çemberlerin merkezleri, $r$ büyüdükçe genişleyen bir koni yüzeyi oluşturur.

**Soru:** Hoca parametre uzayının yeni bir uzaya geçirilip geçirilmediğini sordu: formül $(x-a)^2 + (y-b)^2 = r^2$ idi; parametreler sıfırdan sonsuza mı gider? **Cevap:** Parametre aralığı mümkün olduğunca dar tutulur. $a$ ve $b$ görüntü koordinatlarıyla orantılı olduğu için ayrıca dönüştürülmez; hızlı algoritmalar kenar noktalarının çevresine sabit $r$ ile çember çizip oyları toplar. $\theta$ değerleri bir tablodan alınır.

**Soru:** Hoca uzayın bir ızgaraya (grid) bölünüp bölünmediğini sordu. **Cevap:** Evet. $a$ ve $b$ için görüntüyle orantılı normal bir ızgara oluşturulur. Her $(a,b)$ noktasından $r$ yarıçaplı çember çizilir ve yoğunluk toplamları o yarıçapın katmanına yazılır. Örneğin $r=5$'ten $r=50$'ye kadar gidildiğinde katman katman üç boyutlu bir yoğunluk matrisi oluşur. Her katmandaki en yoğun nokta ya da eşiği geçen noktalar çember merkezlerini verir.

### 1.6 Deneyler ve gözlemler

Sunumda internetten alınan görüntülerde şu gözlemler aktarıldı:

- Eşik düşük ve yarıçap aralığı geniş tutulduğunda bütün çemberler bulundu, ama yanlış çemberler de arttı.
- Canny çıktısında bazı çemberler tam değil kesikliydi. Eşik yükseltildiğinde tam daire olmayan şekiller bulunamadı. Sunumda eşik genelde 30 ile 55 arasında tutuldu.
- Kontrastı düşük ve kenarı çıkarılamayan çemberler bulunamaz.
- Küçük yarıçaplarda hata oranı artar; sunumdaki gözleme göre yarıçapı yaklaşık 15 pikselin üzerinde olan çemberlerde yöntem başarılıdır.
- Kendi yazılan kod, Python'daki hazır Hough çember fonksiyonuna göre daha yavaş çalıştı; hazır fonksiyonun daha iyi sonuç verdiği belirtildi.

Sunumda yöntemin parmak izi görüntülerinde öznitelik çıkarmak için de kullanılabildiği gösterildi. Görüntü bulanıklaştırıldıktan sonra doğru için Hough dönüşümü uygulanınca baskın çizgi yönleri, düşük eşikle çember dönüşümü uygulanınca dairesel ve kapalı bölgeler bulundu. Köşe noktaları için derste görülen Harris köşe bulucusu kullanıldı. Bu öznitelikler hızlı sınıflandırma için bir makine öğrenmesi aracına (altyazıda "VK"; büyük olasılıkla WEKA) verilebilir.

### 1.7 Kullanım alanları, avantajlar ve dezavantajlar

Kullanım alanları:

- Biyometride gözdeki iki iç içe çemberin bulunup aradaki bölgenin tanıma için çıkarılması. Altyazıda "retina" geçiyor; iç içe iki çember arasındaki bölge büyük olasılıkla iristir.
- Astronomik gözlemlerde yıldız ve gezegenlerin bulunması.
- Rakam ve harf tanıma, dairesel nesnelerin tespiti.
- Uzaktan algılamada insan yapımı bölgelerin tespiti.

Formül değiştirilerek parabol gibi başka geometrik şekiller de bulunabilir. Kısıt, parametre sayısının en fazla 4 civarında kalmasıdır; daha fazlasında algoritma çok yavaşlar.

Avantajlar: kesik çemberler eşik düşürülerek bulunabilir, iç içe çemberler ayrılabilir, geniş bir yarıçap aralığında arama yapılabilir. Dezavantajlar: büyük görüntülerde geniş yarıçap aralığı birkaç dakika sürebilir, ön işlem gerekir ve yöntem özellikle küçük yarıçaplarda gürültüye duyarlıdır. Kaynak olarak Gonzalez ve Woods'un sayısal görüntü işleme kitabının hem doğru hem çember için Hough dönüşümünü anlattığı belirtildi.

## 2. pSp: StyleGAN Kodlayıcısıyla Görüntüden Görüntüye Çeviri

### 2.1 Amaç ve katkılar

İkinci sunum, "Encoding in Style: a StyleGAN Encoder for Image-to-Image Translation" makalesini (pixel2style2pixel, kısaca pSp) anlattı. Çalışma genel bir görüntüden görüntüye çeviri çerçevesi önerir. Önceden eğitilmiş bir StyleGAN üreticisi sabit tutulur. Bir kodlayıcı (encoder) ağı, girdi görüntüsünden doğrudan gizli uzaydaki stil vektörlerini üretir.

GAN'lar özellikle yüz görüntülerinde çok gelişmiş görüntü üretebilir. StyleGAN, stil tabanlı bir üretici mimarisidir ve yüksek çözünürlükte çok iyi görsel kalite sağlar. Çalışmanın katkıları şunlardır:

- Gerçek yüz görüntülerini ek bir optimizasyon yapmadan doğrudan genişletilmiş gizli uzay $\mathcal{W}+$'ya kodlayan bir StyleGAN kodlayıcısı.
- Kodlayıcının yeniden kurulumunu iyileştiren özel bir kimlik kaybı (identity loss).
- Görüntüden görüntüye çeviri için uçtan uca bir çerçeve.

Gizli uzay (latent space), verinin sıkıştırılmış bir gösterimidir. Amacı verinin özniteliklerini öğrenmek ve örüntü bulmak için gösterimi basitleştirmektir.

### 2.2 Uygulamalar

Çerçevenin modları arasında şunlar gösterildi: StyleGAN tersine çevirme (inversion), yandan çekilmiş bir yüzü önden görünüme çevirme (frontalization), eksik bölgeleri tamamlama (inpainting), segmentasyon haritasından yüz üretme, bulanık ya da düşük çözünürlüklü görüntüden yüksek çözünürlüklü görüntü üretme (super resolution) ve iki yüz arasında ara yüzler üretme (face interpolation).

**Soru:** Hoca segmentasyon örneğindeki birden fazla çıktının ne anlama geldiğini sordu: model birkaç resimden hangisi olduğunu mu tahmin ediyor? **Cevap:** Hayır. Girdi bir segmentasyon haritasıdır ve model bu haritaya uyabilecek birden fazla yüz üretir; yani çok kipli (multimodal) bir üretim yapar.

### 2.3 Mimari

Kodlayıcı ResNet tabanlıdır ve bir öznitelik piramidi kurar (ekrandan, 00:40:00). Piramidin kaba, orta ve ince seviyelerinden alınan öznitelik haritaları `map2style` adlı küçük ağlara verilir. Her `map2style` bloğu, sızıntılı ReLU (LeakyReLU) aktivasyonlarıyla birlikte adımı 2 olan evrişimler kullanarak boyutu kademeli küçültür: $8\times8\times512 \rightarrow 4\times4\times512 \rightarrow 2\times2\times512 \rightarrow 1\times1\times512$. Böylece 18 tane 512 boyutlu stil vektörü ($w_1, \ldots, w_{18}$) elde edilir. Bu vektörler afin dönüşüm blokları (A) üzerinden StyleGAN üreticisinin katmanlarına verilir. Üretici $4\times4$ sabit bir girdiden başlayıp $1024\times1024$ çıktı üretir. 18 stil vektörü kaba, orta ve ince olmak üzere üç ayrıntı seviyesine karşılık gelir.

Çok kipli üretimde kodlayıcıdan gelen vektörler bazı katmanlarda rastgele gizli vektörlerle karıştırılır (style mixing); sunumda 8. ile 18. katmanlar arasının gizli uzaydan beslendiği söylendi. Böylece aynı girdiden farklı görüntüler üretilir.

### 2.4 Eğitim ve sonuçlar

Sunumda aktarılan ayrıntılar: StyleGAN üreticisi FFHQ veri setiyle eğitilmiştir (70.000 görüntü). Kodlayıcıya $256\times256$ görüntüler verilir, çıktı $1024\times1024$'tür. Öğrenme oranı 0,001'dir. Optimizasyon için Ranger kullanılmıştır; sunumda bunun RAdam ile Lookahead yöntemlerinin birleşimi olduğu söylendi. Yaklaşık 30.000 görüntülük yüksek kaliteli bir ünlü yüzleri veri setinin (CelebA-HQ) yaklaşık 24.000 görüntüsü eğitimde kullanılmıştır. Sonuçlarda pSp'nin girdiyle çıktı arasındaki benzerliğinin (kimlik benzerliği ve LPIPS) yüksek olduğu, yalnız çalışma süresinin diğer yöntemlere göre biraz uzun olduğu belirtildi.

Grup, yazarların yayımladığı Colab defterini çalıştırarak gösterdi. Defterde deney türü (FFHQ kodlama, önden görünüme çevirme, eskizden yüze, segmentasyondan yüze, süper çözünürlük, çizgi film karakterine çevirme) seçilir, önceden eğitilmiş model indirilir, çıkarım parametreleri belirlenir ve sonuçlar görselleştirilir. Çok kipli sentezde gizli maske (latent mask), karıştırma oranı (mix alpha) ve üretilecek çıktı sayısı parametreleri ayarlanır.

Hoca, önceden eğitilmiş modellerin sınıflandırmada çok kullanıldığını bildiğini, bu çalışmanın GAN'lar için de önceden eğitilmiş modellerin kullanılabildiğini gösterdiğini belirtti.

## 3. GAN ile Hızlı ve Keyfi Stil Aktarımı

### 3.1 Problem ve önceki yaklaşımlar

Üçüncü sunum "Adversarial Training for Fast Arbitrary Style Transfer" makalesini anlattı. Stil aktarımı da bir görüntüden görüntüye çeviri problemidir ama kolay değildir: orijinal görüntü deforme edilmeli, öyle ki yeni görüntünün dokusu ve karakteristiği stil görüntüsüne benzesin, ama içeriği korunsun. Yeni görüntüye bakınca orijinal görüntü tanınmalı, dokusu ise değişmiş olmalıdır.

Önceki yaklaşımlar:

- **Optimizasyon tabanlı yöntemler** (sunumda 2015 dolaylarında yayımlandığı söylendi): görüntü, stil görüntüsünün istatistiklerine uyacak biçimde doğrudan optimize edilir. Yavaştır ve hiperparametrelere çok duyarlıdır; bazı stillerde aktarımı yeterince yapamaz.
- **İleri beslemeli ağlar:** U-Net benzeri yapıların gelişmesi ve GPU kullanımıyla hızlı sonuç verir, ama genelde tek bir stili destekler.
- **Koşullu GAN'lar:** birden fazla stili destekler. Sunumda daha önceki bir derste sunulan yüz yaşlandırma çalışmasının da koşullu GAN kullandığı hatırlatıldı.

Bu çalışmanın hedefi tek bir ağla birden fazla stil ve birden fazla içerik türü (insan yüzü, kuş, araba, bina) için hızlı çıkarım yapmak ve stilizasyon miktarını elle denetlemeyi sağlayan bir maske modülü sunmaktır.

### 3.2 Çekişmeli eğitim ve ayırt edici

Yöntem çekişmeli (adversarial) eğitim kullanır. Üretici bir görüntü üretir ve ayırt ediciyi kandırmaya çalışır. Ayırt edici üretilen görüntünün gerçek olup olmadığını ve doğru stilde olup olmadığını öğrenerek üreticiye olumsuz geri bildirim verir; bu, "şunları düzeltmelisin" demek gibidir.

Ayırt edici koşullu bir patch discriminator'dır (ekrandan, 01:00:00). Patch discriminator görüntünün tamamı için tek karar vermek yerine görüntüyü küçülterek ilerleyen evrişim katmanlarından geçirir ve her bölge (patch) için gerçek/sahte tahmini üretir. Sunumda bu yapının farklı ölçeklerde görüntüyü küçültmesi bakımından Gauss farkına (difference of Gaussians) biraz benzediği, ama çıkarma yerine ağırlıklarla evrişim yapıldığı söylendi.

Ayırt edicide önemli nokta gömme (embedding) kullanılmasıdır. Gömme, doğal dil işlemede bir kelimeyi ya da belgeyi temsil etmek için kullanılan vektörlerdir. Burada bir stil için bir gömme vektörü öğrenilir; yeni bir girdi geldiğinde bu vektöre uzaklığına bakılır. Ayırt edici böylece ikili gerçek/sahte kaybının yanında stil sınıfını da öğrenir ve üreticiye buna göre geri bildirim verir.

### 3.3 Üretici ve maske modülü

Üretici bir kodlayıcı-kod çözücü ağdır. Kodlayıcı görüntüyü küçülterek (downsample) öznitelik çıkarır, kod çözücü bu öznitelikleri büyüterek (upsample) görüntü üretir. U şekline benzediği için bu yapıya U-Net de denir. Kodlayıcı, ImageNet üzerinde önceden eğitilmiş bir VGG16'dır. İçerik kaybı için ayrı bir öznitelik çıkarıcı kullanılmaz; kodlayıcının blok çıktıları kayıp hesabında kullanılır.

Kodlayıcıdan çıkan öznitelikler maske modülüne, maske modülünün çıktısı kod çözücüye verilir. Maske modülü ne kadar uyarlamalı örnek normalizasyonu (Adaptive Instance Normalization, AdaIN) uygulanacağını belirler. AdaIN stil aktarımında en iyi yöntemlerden biridir ve şöyle tanımlanır (ekrandan, 01:05:00):

$$\mathcal{A}(x,y) = \sigma_{nc}(y)\left(\frac{x_{nchw} - \mu_{nc}(x)}{\sigma_{nc}(x)}\right) + \mu_{nc}(y)$$

Yani $x$'ten ortalaması çıkarılıp standart sapmasına bölünür (standartlaştırma), sonra $y$'nin standart sapmasıyla çarpılıp ortalamasıyla toplanır. Sezgisel olarak $x$'in dağılımı $y$'ninkine kaydırılır. Maske modülü bu kaydırmanın ne kadar yapılacağını öğrenir. Mimari olarak çok küçüktür: alt alta bağlı iki evrişim katmanı. Optimize ettiği ifade şudur:

$$z_1 = \mathcal{M}(x,y_1)\times x + \left(1-\mathcal{M}(x,y_1)\right)\times \mathcal{A}(x,y_1)$$

$$z_2 = \mathcal{M}(x,y_2)\times x + \left(1-\mathcal{M}(x,y_2)\right)\times \mathcal{A}(x,y_2)$$

İki stil aynı anda aktarılabilir:

$$z = \beta z_1 + (1-\beta) z_2, \qquad \beta \in [0,1] \;\text{ ya da }\; \beta \in [0,1]^{N\times C\times W\times H}$$

$\beta$ skaler olduğunda örneğin "%80 birinci stil, %20 ikinci stil" denebilir. $\beta$ bölgesel (her piksel için ayrı) olduğunda yüzün bir yarısı birinci, diğer yarısı ikinci stilde üretilebilir.

### 3.4 Mod çöküşü ve maske modülü

Maske modülünün önemli bir yararı, GAN eğitiminde karşılaşılan mod çöküşü (mode collapse) sorununu azaltmasıdır. Üretici ayırt ediciyi kandırmaya odaklandığı için, ağızla burun arasındaki alan ya da iki göz arası gibi küçük ama önemli (salient) bölgeler görüntünün genelinde çok az yer kapladığından bu bölgelerden gelen kayıp küçük kalır. Üretici bu bölgeleri atlayabilir ya da birleştirebilir; sunumdaki örnekte iki gözün arası birleşmişti. Maske modülü 0 ile 1 arasında yumuşak bir maske ürettiği için bir tür dikkat (attention) gibi davranır ve bu bölgelerin daha iyi öğrenilmesini sağlar.

### 3.5 Kayıp fonksiyonları

Ayırt edici için her GAN eğitiminde olduğu gibi çekişmeli kayıp kullanılır: üreticinin çıktısı "sahte", gerçek görüntü "gerçek" olarak etiketlenir. Bu çalışmada ayırt ediciye ayrıca bir stil kaybı verilir.

Üretici için toplam kayıp şudur (ekrandan, 01:10:00):

$$\min_G \mathcal{L}_G = \mathcal{L}_{GA} + \lambda_{GS}\mathcal{L}_{GS} + \lambda_c\mathcal{L}_c + \lambda_s\mathcal{L}_s$$

$$\mathcal{L}_{GA} = \mathbb{E}\left[\log(\text{Real}\,|\,D(\hat x))\right], \qquad \mathcal{L}_{GS} = \mathbb{E}\left[\log(s\,|\,D(\hat x))\right]$$

$$\mathcal{L}_c = \mathbb{E}\left[\left\|x^{(4)} - \hat x^{(4)}\right\|_1\right], \qquad \mathcal{L}_s = \mathbb{E}\left[\sum_{i=1}^{4}\left\|\mathrm{Gram}(y^{(i)}) - \mathrm{Gram}(\hat x^{(i)})\right\|_1\right]$$

$$\mathrm{Gram}(f) = \mathrm{mean}(f\cdot f^{T})$$

İçerik kaybı yalnız dördüncü kodlayıcı bloğunun çıktısıyla, stil kaybı ise tüm blokların Gram matrisleriyle hesaplanır. Gram matrisi bir kovaryans matrisine benzer ve stilin baskın, karakteristik özelliklerini öne çıkarır. Eğitim mini-batch'lerle yapıldığı için sunumda Gram matrisine ortalama (mean) eklendiği söylendi.

**Soru:** Hoca $\mathcal{L}_{GS}$ ifadesindeki dikey çizgiyi sordu: bu gösterim genelde koşullu olasılıkta "$D(x)$ verildiğinde $s$'nin olasılığı" anlamında kullanılır; burada $P$ neden yok, başka bir anlamı var mı? **Cevap:** Aynı anlamdadır; ayırt edicinin öğrendiği stil gömmesine olan uzaklık ölçülmektedir.

### 3.6 Veri setleri ve sonuçlar

Makalede 4 içerik ve 7 stil türüyle çalışılmıştır. İçerik için yaklaşık 122.000 insan yüzü (CelebA), 35.000 kuş, 36.000 araba ve 34.000 bina görüntüsü kullanılmış; stil görüntüleri Behance veri setinden alınmıştır. Stiller vektör sanatından karikatüre, yağlı boyadan suluboyaya uzanır.

Nicel değerlendirme için Amazon Mechanical Turk'te bir kullanıcı anketi yapılmış; katılımcılara üç modelin çıktısı gösterilip en iyisi sorulmuştur. Karşılaştırılan yöntemler AdaIN ve WCT (whitening and coloring transform) gibi en iyi yöntemlerdir. Yazarlar genel toplamda yaklaşık %48 oranla kazandıklarını, binalarda zayıf kaldıklarını ve binalar için ayrı bir anket yaptıklarını bildirmiştir.

Nitel sonuçlarda optimizasyon tabanlı yöntemin bazı stilleri yeterince aktaramadığı, AdaIN ve WCT'de stil görüntüsünden gelen gölge ve beyaz çizgi gibi yapay izler (artifact) oluştuğu, önerilen yöntemde ise ön plan ile arka planın iyi ayrıştığı gösterildi. Kuşlarda başarı düşüktür; neden olarak veri setinde çok farklı kuş türü bulunması ve her tür için yeterli örnek olmaması gösterildi. Stilizasyon miktarı (%20'den %100'e) ve iki stil arasındaki oran denetlenebilir; ağın ağırlıkları yaklaşık 100 MB'tır ve hızlı çıkarım sayesinde gerçek uygulamalara uyarlanabilir. Yazarlar ayrıca yüz ifadelerinin ne kadar korunduğunu ölçmüş; belirgin ifadelerde başarılı, az belirgin ifadelerde daha zayıf sonuç almışlardır.

### 3.7 Sunumdaki uygulama

Sunumu yapan öğrenci, portrelerin farklı sanat akımlarında (dışavurumculuk, izlenimcilik, gerçekçilik, romantizm, Rönesans) çizilmiş olsaydı nasıl görüneceğini araştırdı. Yüzler için CelebA, stil için WikiArt veri setinin portre görüntüleri kullanıldı. Yazarların eski kodu PyTorch 1.7'ye uyarlandı. Görüntüler $128\times128$'e küçültüldü; GPU belleği sınırı nedeniyle her oturumda 6000 yüz ve 6000 stil görüntüsü verildi.

Eğitim ilerledikçe sonuçlar şöyle değişti: 800 dönemde (epoch) yüz yeni oluşmaya başladı, 2500 dönemde burun ve ağız ayırt edilebilir hale geldi, 3500 dönemde arka plan özellikleri ve gölgelendirme aktarılmaya, gözlük gibi aksesuarlar doğru işlenmeye başladı. Köşeli stillerde sonuçların köşeli, gerçekçi stillerde yumuşak olduğu görüldü. İki stil %50-%50 karıştırıldığında ve yüzün iki yarısına farklı stil verildiğinde fark açıkça izlenebildi.

## 4. İnsansız Hava Aracı Görüntülerinde Gerçek Zamanlı Anlamsal Bölütleme

### 4.1 Anlamsal bölütleme

Dördüncü sunum, bir dronun çevresindeki nesneleri ve ortamı bir insan gibi algılaması amacıyla gerçek zamanlı anlamsal bölütleme (real-time semantic segmentation) üzerineydi. Nesne algılamada nesnenin çevresindeki kutu koordinatları verilir. Anlamsal bölütlemede ise her piksele bir sınıf atanır: çim, ağaç ya da belirlenen başka bir sınıfa ait bütün pikseller etiketlenir. Slaytta kırsal ve şehir içi görüntü bölütleme örnekleri gösterildi (ekrandan, 01:50:00). Bu sistemler otonom araçlarda da çok kullanılır.

### 4.2 Veri seti ve etiketleme

Kullanılan açık veri seti İHA görüntülerinden oluşur: 400'den fazla 4K çözünürlüklü fotoğraf ve 8 sınıf. Sınıflar: yapı (bina, apartman), yol, durağan araç (park halinde), hareketli araç (yolda), düşük bitki örtüsü (toprak, çim), ağaç, insan ve arka plan. Her sınıf belirli bir RGB değeriyle etiketlenir. Piksellerin çoğu yapı ve ağaç sınıfındadır; görüntüler yüksekten çekildiği için insanlar küçük görünür ve az piksel kaplar.

Grup ayrıca kendi dron uçuşlarından yaklaşık 2 saatlik görüntü topladı, bunlardan uygun 100 kare seçip etiketledi. Etiketleme için CVAT (Computer Vision Annotation Tool) ve LabelMe kullanıldı. 4K bir görüntünün elle etiketlenmesi 5-6 saat sürebilir. Hoca, bu işin zor ve zaman alıcı olduğunu, para karşılığı etiketleme hizmeti veren kişiler de bulunduğunu belirtti. Modelin gürültüye karşı gürbüz olması için parlaklık değiştirme ve çevirme (flip) ile veri artırma yapıldı.

### 4.3 Modeller

Üç model kullanıldı: EfficientNet kodlayıcılı bir U-Net, U-Net ve PSPNet. Bölütleme modellerinde genellikle bir kodlama (encoder) ve bir kod çözme (decoder) kısmı vardır. Normal evrişimli ağlar yalnız sınıflandırma yaparken bölütleme modelleri girdiyle aynı boyda bir çıktı haritası üretir.

- **EfficientNet:** genişlik, derinlik ve çözünürlüğü birlikte ölçekleyen bileşik ölçekleme (compound scaling) özelliğine sahiptir. Burada yalnız kodlayıcı olarak kullanıldı, kod çözücü U-Net biçimindedir.
- **U-Net** (2015): simetrik bir mimaridir (ekrandan, 02:00:00). Kodlayıcıda her seviyede iki $3\times3$ evrişim (ReLU) ve bir $2\times2$ max pooling vardır; isteğe bağlı olarak düzenlileştirme (regularization) için dropout eklenebilir. Bu yapı dört kez tekrarlanır ve öznitelik kanal sayısı 64, 128, 256, 512, 1024 diye artar. Kod çözücüde $2\times2$ yukarı evrişim (transposed convolution) yapılır ve kodlayıcının aynı seviyesindeki öznitelik haritası kopyalanıp kırpılarak birleştirilir (concatenate). En sonda $1\times1$ evrişimle bölütleme haritası üretilir.
- **PSPNet:** piramit havuzlama modülü (pyramid pooling module) kullanır. Öznitelik haritası farklı boyutlarda havuzlanır, her biri evrişimden geçirilip özgün boyuta büyütülür ve birleştirilir. Böylece küçük ve büyük ölçekteki bağlam bilgisi bir araya getirilir. Sunumda bu birleştirmenin teknik ayrıntısı verilmedi.

### 4.4 Ölçüt ve sonuçlar

Başarım ölçütü kesişim/birleşim (intersection over union, IoU) idi: tahmin edilen bölütleme ile gerçek etiket (ground truth) piksel piksel karşılaştırılır; iki kümenin kesişimi birleşimine oranlanır.

EfficientNet ile yapılan denemede eğitim ve doğrulama doğruluklarının birbirine yakın çıktığı, bunun modelin iyi genellediğini gösterdiği söylendi. <!-- BELİRSİZ: EfficientNet sonuç değerleri altyazıda "%175" ve "176" diye bozuk geçiyor; bu anın karesi yok. -->

U-Net sonuçları (ekrandan, 02:05:00):

| Model | Eğitim doğruluğu | Doğrulama doğruluğu | Test doğruluğu |
|---|---|---|---|
| U-Net | %80,55 | %84,12 | %84,93 |

Sunumu yapan, grafikte "test" yazan eğrinin aslında doğrulama eğrisi olduğunu, hiperparametre optimizasyonu yapılmadığı için sonuçların daha da iyileştirilebileceğini belirtti. İlk iki model gerçek zamanlı değildir; veri setinin doğruluğunu sınamak için kullanılmıştır. Gerçek zamanlı model PSPNet'tir; yaklaşık 16 FPS elde edildi (sunumda bir yerde 17-18 FPS de söylendi; değer donanıma göre değişir). Eğitim ve doğrulama kaybı 10 dönem boyunca yaklaşık 0,14'ten 0,08 civarına indi (ekrandan, 02:10:00). Bellek sınırları nedeniyle görüntüler küçültüldü.

**Soru:** Hoca hangi donanımın kullanıldığını sordu. **Cevap:** Yerelde tek bir 8 GB'lık RTX 2060 vardır; çoğu zaman bulutta saatlik ücretle GPU kiralanır. Kaggle'ın da kullanıcılara haftalık sınırlı GPU ve TPU sağladığı gösterildi.

**Soru:** Hoca GPU ile TPU arasında hız farkı gözlenip gözlenmediğini sordu. **Cevap:** Sunumu yapan TPU'yu henüz kullanmamıştı; TPU'nun TensorFlow ile tam uyumlu çalışmadığını, PyTorch desteğinin de yeni olduğunu söyledi. Hoca TPU'nun Google'a özgü bir donanım olduğunu belirtti. Mobil robotlara ve hava araçlarına takılabilen küçük TPU geliştirme kartlarının da bulunduğu konuşuldu.

İleride ICNet gibi daha yeni gerçek zamanlı ağların da uygulanması, beğenilen kodlayıcı ve kod çözücü kısımlarının birleştirilip optimize edilmesi planlandığı söylendi.

## 5. Dijital Patolojide Stil Aktarımıyla Genelleme

### 5.1 Çalışmanın amacı

Beşinci sunum "Style Transfer Strategy for Developing a Generalizable Deep Learning Application in Digital Pathology" makalesini anlattı. Amaç, patolojide kötü huylu yapıların tespiti için farklı ve yetersiz veri setlerine genellenebilen bir sınıflandırıcı kurmaktır. Önce büyük, açık bir veri setinde öğrenme yapılır. Sonra küçük, yerel bir üniversite veri setinin görüntüleri stil aktarımıyla büyük veri setinin stiline çevrilerek genelleme sağlanmaya çalışılır. Yumurtalık kanseri patoloji görüntüleri kullanılmıştır. Yöntem farklı renk normalizasyonu yöntemleriyle karşılaştırılmıştır.

### 5.2 Inception V3

Inception V3, Google tarafından geliştirilmiş ve 2015'teki ImageNet Büyük Ölçekli Görsel Tanıma Yarışması'nda (ILSVRC) kullanılmıştır (ekrandan, 02:15:00). Inception V1 (GoogLeNet) yaklaşık 7 milyon parametreyle çalışarak hesaplama verimliliğini artırmıştır. Batch normalizasyon eklenince Inception V2, ek çarpanlara ayırma (factorization) fikirleriyle Inception V3 elde edilmiştir.

> **Ders sonrası not:** Slaytta "VGGNet (60 milyon parametre), AlexNet (180 M)" yazıyor. Yaygın bilinen değerler AlexNet için yaklaşık 60 milyon, VGG-16 için yaklaşık 138 milyon parametredir; slayttaki değerler karışmış olabilir.

Slayttaki modüller şöyledir:

- **Modül A:** GoogLeNet'teki $5\times5$ evrişim iki ardışık $3\times3$ evrişimle değiştirilmiştir.
- **Modül B:** $7\times7$ evrişim yerine $1\times7$ ve $7\times1$ evrişimler kullanılır (uygulamada $n=7$).
- **Modül C:** yüksek boyutlu gösterimleri desteklemek için $1\times3$ ve $3\times1$ evrişimler paralel dallarda kullanılır.
- **Yardımcı sınıflandırıcı (auxiliary classifier):** $17\times17\times768$ öznitelikten $5\times5$ ortalama havuzlama (adım 3), $1\times1$ evrişim ve tam bağlı katmanla ek bir çıktı verir.

$1\times1$ evrişimler derinliği azaltarak parametre sayısını düşürür. Sunumdaki örnek, 60 derinlikli bir öznitelik haritasının 20 tane $1\times1$ evrişimle 20 derinliğe indirilmesiydi. <!-- BELİRSİZ: örnekteki uzamsal boyut altyazıda "%100" ve "%120" diye bozuk geçiyor; büyük olasılıkla 100×100×60'tan 100×100×20'ye. --> Aktivasyon olarak ReLU kullanılır. Inception V3 $299\times299\times3$ boyutlu görüntüleri işler ve sonunda 2048 boyutlu bir öznitelik vektörü verir. Transfer öğrenme yapıldığı için veri setinin bu boyut ve kanal sayısına uydurulması gerekir.

### 5.3 Eğitim ayrıntıları ve RMSprop

Makalede TensorFlow 2 kullanılmıştır. Önceden eğitilmiş Inception V3 ImageNet ağırlıklarıyla transfer öğrenme yapılmış; öğrenme oranı $2\times10^{-5}$, kayıp ikili çapraz entropi (binary cross entropy), optimizasyon RMSprop, batch boyutu 10'dur.

RMSprop'ta her ağırlık için gradyanların karelerinin (üstel) ortalaması tutulur ve gradyan bu ortalamanın kareköküne bölünür; adı kök ortalama kare (root mean square) işleminden gelir. Özetle öğrenme oranını her ağırlık için ölçekleyerek minimuma daha hızlı ulaşmayı sağlar.

> **Ek bilgi (derste anlatılmadı):** RMSprop güncellemesi genellikle $v_t = \gamma v_{t-1} + (1-\gamma)g_t^2$, $w_{t+1} = w_t - \frac{\eta}{\sqrt{v_t}+\epsilon}\,g_t$ biçiminde yazılır. Burada $g_t$ gradyan, $\gamma$ (çoğu zaman 0,9) çürüme katsayısı, $\eta$ öğrenme oranıdır.

### 5.4 Görüntüden görüntüye çeviri, GAN ve CycleGAN

Görüntüden görüntüye çeviri, var olan bir görüntünün üzerinde oynanarak farklı ve yapay bir versiyonunun üretilmesidir (ekrandan, 02:20:00). Klasik örnek at ve zebra görüntüleri arasındaki dönüşümdür; kış manzarasını yaza, yağlı boya tabloyu fotoğrafa çevirmek de örneklerdir. Zorlukları veri setinin kıtlığı ve istenen çıktının tarifinin karmaşıklığıdır.

GAN'lar 2014'te Ian Goodfellow ve arkadaşlarınca önerilmiştir. Sezgi için kalpazan ve polis örneği verildi: biri sahte para basar, diğeri sahteyi yakalamaya çalışır; ikisi de birbirini geliştirir. GAN bir üretici (generator) ve bir ayırt edici (discriminator) modelden oluşur. Üretici, $p_z$ dağılımından çekilen rastgele $z$ örneğinden bir örnek üretir. Ayırt edici bu örneğin gerçek mi sahte mi olduğuna karar verir. Amaç, üreticinin dağılımını gerçek verinin dağılımı $p_x$'e yaklaştırmaktır. GAN'ların başlıca kullanım alanları çözünürlük artırma, sanatsal görüntü üretme ve görüntüden görüntüye çeviridir. Tıbbi uygulamalarda pix2pix gibi yöntemler ve göz görüntülerinden damar yapısını çıkaran çalışmalar örnek verildi.

CycleGAN, görüntüden görüntüye çevirideki temel sorun olan eşleştirilmiş veri gerekliliğini kaldırmak için geliştirilmiştir (ekrandan, 02:25:00). İki üretici ve iki ayırt edici eşzamanlı eğitilir ve birbirleriyle yarıştırılır. $G: X \to Y$ eşlemesi ve ters eşleme $F: Y \to X$ öğrenilir. Bir görüntü $X$'ten $Y$'ye, sonra geri $X$'e çevrildiğinde başlangıçtaki görüntüye dönmelidir; bu döngü tutarlılığı (cycle consistency) kaybıyla denetlenir. Slayttaki kodda toplam üretici kaybı çekişmeli kayıp, döngü kaybı ve kimlik kaybının toplamıdır:

```python
fake_y = generator_g(real_x, training=True)
cycled_x = generator_f(fake_y, training=True)
fake_x = generator_f(real_y, training=True)
cycled_y = generator_g(fake_x, training=True)

# same_x and same_y are used for identity loss.
same_x = generator_f(real_x, training=True)
same_y = generator_g(real_y, training=True)

total_cycle_loss = calc_cycle_loss(real_x, cycled_x) + \
                   calc_cycle_loss(real_y, cycled_y)

# Total generator loss = adversarial loss + cycle loss
total_gen_g_loss = gen_g_loss + total_cycle_loss + identity_loss(real_y, same_y)
total_gen_f_loss = gen_f_loss + total_cycle_loss + identity_loss(real_x, same_x)
```

(ekrandan, 02:25:00; kodun bir kısmı alınmıştır.) CycleGAN'lar genelde U-Net ve ResNet gibi hazır mimarilerle birlikte kullanılır. Sunumda başka bir çalışmadan alınan örnekte CT ve CBCT görüntüleri arasında iki üretici ve iki ayırt ediciyle çeviri yapıldığı gösterildi.

### 5.5 Yöntemin akışı ve değerlendirme ölçütleri

Açık veri setinin %80'i eğitime, %20'si doğrulamaya ayrılır. Inception V3 bu veriyle transfer öğrenmeyle eğitilir. CycleGAN, açık veri seti ile yerel üniversite veri setiyle eğitilir ve yerel görüntüler açık veri setinin stiline aktarılır. Stili aktarılmış ve aktarılmamış görüntüler sınıflandırıcıya verilerek başarımlar karşılaştırılır. Karşılaştırmada Macenko ve Vahadane renk normalizasyonu yöntemleri de kullanılır.

Değerlendirme ölçütleri (ekrandan, 02:30:00):

- **AUC:** ayırt etme ölçütüdür; ne kadar yüksekse model 0'ları 0, 1'leri 1 olarak o kadar iyi tahmin eder.
- **ROC eğrisi:** doğru pozitif oranının (TPR) yanlış pozitif oranına (FPR) karşı çizimidir. **AUROC** bu eğrinin altındaki alandır ve sınıflar arası ayırt ediciliği ölçer.
- **AUPRC:** kesinlik-duyarlılık (precision-recall) eğrisinin altındaki alandır; doğru negatifleri kullanmaz.
- Kesinlik, duyarlılık ve $F_1$:

$$\text{Precision} = \frac{TP}{TP+FP}, \qquad \text{Recall} = \frac{TP}{TP+FN}, \qquad F_1 = \frac{2\cdot\text{Prec}\cdot\text{Rec}}{\text{Prec}+\text{Rec}}$$

> **Ders sonrası not:** Sunumda $F_1$ skoru için "yaygın bir aktivasyon fonksiyonu" dendi. $F_1$ bir aktivasyon fonksiyonu değil, kesinlik ve duyarlılığın harmonik ortalaması olan bir değerlendirme ölçütüdür.

### 5.6 Sonuçlar

Yalnız Inception V3'ün sınıflandırma doğruluğu yaklaşık %50 ile %70 arasında değişmiştir. Macenko renk normalizasyonu bu oranı biraz yükseltmiş, Vahadane de fena olmayan sonuç vermiştir. En iyi sonucu CycleGAN tabanlı stil aktarımı vermiştir; sunumda bu yöntemle elde edilen skorların 0,833 ve 0,898 olduğu söylendi. <!-- BELİRSİZ: bu iki değerin hangi ölçüte (AUROC/AUPRC) ait olduğu ve "gerçek skoru 0.99 olan veri seti" ifadesi altyazıda net değil; sonuç tablosunun karesi yok. --> Tahmin skorunun 1'e yakın olması kanserli, 0'a yakın olması sağlıklı bölgeyi gösterir. Isı haritalarında stil aktarımıyla birlikte kullanılan sınıflandırıcının kanserli ve kanserli olmayan bölgeleri daha ayırt edici biçimde ayırdığı, başka bir kanser türünün veri setine genellemede de daha iyi sonuç verdiği gösterildi. Stil aktarımı, yapısal bir fark olmamasına rağmen RGB renk dağılımındaki farklılıkların yarattığı etkiyi ortadan kaldırarak gürbüzlüğü artırmıştır.

## 6. Gürbüz En Küçük Kareler Yöntemleri

### 6.1 En küçük kareler ve aykırı değer sorunu

Altıncı sunum gürbüz en küçük kareler (robust least squares) yöntemlerini anlattı. Doğrusal regresyonda en küçük kareler (least squares, LS) hata fonksiyonunu en küçükleyen $m$ ve $b$ değerlerini bulur. Hata fonksiyonu gerçek değerlerle model tahminleri arasındaki farkların kareleri toplamıdır. Matris biçiminde hata $\|Ap - y\|^2$'dir ve çözüm:

$$p = \begin{bmatrix} m \\ b \end{bmatrix} = (A^T A)^{-1} A^T y$$

$A$ matrisi, $x$ değerlerinin yanına birlerden oluşan bir sütun eklenerek kurulur. Bu modelin sorunu aykırı noktalardır (outlier): sunumdaki grafikte sağ altta tek bir aykırı nokta, doğruyu kendine doğru belirgin biçimde çekiyordu. Gürbüz yöntemler, hata terimlerinin büyüklüklerinde önemli farklar olduğunda kullanılır ve aykırı değerlerin tahmine etkisini azaltmayı amaçlar.

### 6.2 Winsorized en küçük kareler

Adımlar (ekrandan, 02:55:00):

- LS ile hata terimleri (artıklar) hesaplanır.
- Hata terimleri küçükten büyüğe sıralanır.
- $n$ hata terimi sayısı olmak üzere $g = kn$ ve $0 < g < n/2$ olacak biçimde, baştan ve sondan $g$ tane hata değeri kendisine en yakın hata değeriyle değiştirilir.
- Yeni değerlerle veri setine yeniden LS uygulanır.

**Örnek (ekrandan, 02:55:00).** Veri: $\{92, 19, 101, 58, 1053, 91, 26, 78, 10, 13, -40, 101, 86, 85, 15, 89, 89, 28, -5, 41\}$, $N = 20$, ortalama $101{,}5$.

Sıralanınca: $-40, -5, 10, 13, 15, 19, 26, 28, 41, 58, 78, 85, 86, 89, 89, 91, 92, 101, 101, 1053$. Baştan ve sondan birer değer değiştirilecektir ($g = 0{,}05 \times 20 = 1$). En büyük değer 1053, kendisine en yakın değer olan 101 ile; en küçük değer $-40$, kendisine en yakın değer olan $-5$ ile değiştirilir:

$\{92, 19, 101, 58, 101, 91, 26, 78, 10, 13, -5, 101, 86, 85, 15, 89, 89, 28, -5, 41\}$, $N = 20$, ortalama $55{,}65$.

Ortalamanın 101,5'ten 55,65'e inmesi değerlerin birbirine yaklaştığını gösterir. Bu iki ortalama python ile doğrulandı.

> **Ders sonrası not:** Sunumu yapan oranı sözlü olarak "0,5" diye söyledi. Slayttaki ve hesaptaki değer $k = 0{,}05$'tir: $0{,}05 \times 20 = 1$ değer baştan, 1 değer sondan değişir. Sunumdaki "$k = 0{,}1$ olursa baştan ve sondan iki değer değişir" açıklaması da $k=0{,}05$ ile tutarlıdır.

**Soru:** Hoca bu değerlerin ne olduğunu sordu: ortalamadan farkın karesi mi? **Cevap:** Önce LS ile $m$ ve $b$ bulunur. Bu modelle her $x_i$ için $y$ tahmin edilir; gerçek $y_i$ ile tahmin arasındaki fark o noktanın hata terimidir. Burada karesi alınmamıştır. Hoca bunun üzerine yöntemi "en büyük ve en küçük değerleri kendilerine en yakın komşularıyla değiştirmek" diye özetledi; sunumu yapan da doğruladı. Python'da hazır bir `winsorize` fonksiyonu bulunduğu söylendi.

### 6.3 Trimmed en küçük kareler

Benzer işlemler yapılır, ama sıralanan hata terimlerinin uçlarındaki $k$ tane örnek en yakın değerle değiştirilmek yerine veri setinden silinir. Sonra LS ile $m$ ve $b$ yeniden hesaplanır.

### 6.4 Ağırlıklı en küçük kareler

Ağırlıklı LS'de (weighted least squares) model $Y = X\beta + \epsilon^*$'dır; $\epsilon^*$'ın ortalama vektörü 0 ve sabit olmayan, köşegen bir varyans-kovaryans matrisi ($\sigma_1^2, \ldots, \sigma_n^2$) olan normal dağılımlı olduğu varsayılır (ekrandan, 03:00:00). Her varyansın tersi ağırlık olarak alınır, $w_i = 1/\sigma_i^2$, ve bu ağırlıklar köşegen $W$ matrisine yazılır. Kestirim:

$$\hat\beta_{WLS} = \arg\min_\beta \sum_{i=1}^{n} \epsilon_i^{*2} = (X^T W X)^{-1} X^T W Y$$

Sıradan LS formülüne göre fark, iki yere $W$ eklenmesidir. Sunumdaki uygulamada önce sıradan LS (OLS) ile tahminler bulundu, her noktada gerçek $y$ ile OLS tahmini arasındaki fark $\epsilon$ hesaplandı, ağırlık $w_i = 1/\epsilon_i$ diye alındı ve köşegen $W$ kuruldu. Fark ne kadar büyükse o noktanın modeli o kadar az etkilemesi istenir. Sonuçta doğru aykırı noktadan uzaklaşıp veri yığınına yaklaştı.

> **Ders sonrası not:** Artık negatif ya da sıfır olabileceği için ağırlık olarak $1/\epsilon_i$ doğrudan kullanılamaz. Uygulamada genellikle $1/|\epsilon_i|$ ya da $1/\epsilon_i^2$ gibi pozitif bir ifade (sıfıra bölmeyi önleyen küçük bir sabitle) kullanılır.

Slayttaki kodda sıradan LS şöyle hesaplanmıştı (ekrandan, 03:05:00):

```python
# y = mx+b fonksiyonu için en iyi m ve b değerlerini bul
A = np.concatenate((X,I), axis=1)
# (X.T*X)^(-1)*X.T*y formulu ile m ve b parametreleri hesaplama
p = np.dot(np.dot(np.linalg.inv(np.dot(A.T, A)), A.T),y)
m = p[0]
b = p[1]
# model parametrelerini hesapladıktan sonra y_predict hesapla
y_ols = m*X+b
```

Burada `I` birlerden oluşan sütundur. Hoca, $p_0$'ın eğim ($m$), $p_1$'in kayma ($b$) olduğunu ve bunun standart en küçük kareler olduğunu doğruladı.

### 6.5 M-kestirimi

M-kestiriminde amaç, hata değeri için seçilen bir $\rho(\cdot)$ fonksiyonunun toplamını en küçüklemektir (ekrandan, 03:10:00):

$$\hat\beta_M = \arg\min_\beta \sum_{i=1}^{n} \rho\left(\epsilon_i(\beta)\right)$$

Bazı M-kestiricileri ölçeklemeden etkilenir. Bundan kaçınmak için artıklar bir ölçek kestirimine bölünür:

$$\hat\beta_M = \arg\min_\beta \sum_{i=1}^{n} \rho\left(\frac{\epsilon_i(\beta)}{\hat\tau}\right), \qquad \hat\tau = \frac{\mathrm{med}_i\,|r_i - \tilde r|}{0.6745}, \qquad r_i = \epsilon_i(\beta), \quad \tilde r = \mathrm{median}(r_i)$$

Böylece kestirim ölçekten bağımsız (scale-invariant) olur. Uygulamada adımlar şöyledir:

- OLS ile artıklar $\epsilon$ bulunur.
- Artıkların medyanı bulunur; her artıktan bu medyan çıkarılıp mutlak değeri alınır ve bunların medyanı alınır (iki kez medyan).
- Bu değer 0,6745'e bölünerek $\hat\tau$ bulunur.
- $z_i = \epsilon_i / \hat\tau$ hesaplanır.
- Seçilen ağırlık fonksiyonuyla her nokta için $w(z_i)$ bulunur ve köşegen $W$ matrisine yazılır.
- Ağırlıklı LS formülü $(X^T W X)^{-1} X^T W Y$ ile $m$ ve $b$ bulunur.

> **Ders sonrası not:** Sunumu yapan bir yerde "hata farklarının ortalamasını alıyoruz" dedi. Slayttaki formülde ve koddaki uygulamada kullanılan ortalama değil medyandır ($\tilde r$).

Kullanılan ağırlık fonksiyonları:

- **Andrews sinüs:** $w(z) = \dfrac{\sin(z/c)}{z/c}$, $c \approx 1.339$.
- **Huber:** $|z| \le c$ ise $w(z) = 1$; $c$ olarak 1.345 alındı. <!-- BELİRSİZ: Huber ağırlığının |z| > c durumundaki ifadesi altyazıda tamamlanmıyor. -->
- **Tukey biweight:** sunumda adı geçti ve kodda uygulandı; formülü sözlü verilmedi.

> **Ek bilgi (derste anlatılmadı):** Huber ağırlığı $|z| > c$ için genellikle $w(z) = c/|z|$'dir. Tukey biweight için $|z| \le c$ ise $w(z) = \left(1 - (z/c)^2\right)^2$, aksi halde $w(z) = 0$ alınır ve $c$ genellikle 4.685 seçilir. Andrews fonksiyonunda da $|z| > c\pi$ için ağırlık 0 alınır.

**Soru:** Hoca 0,6745'in "sihirli bir sayı" olup olmadığını, neden bu değerin kullanıldığını sordu. **Cevap:** Sunumu yapan, formülün M-kestirimi kaynaklarında böyle verildiğini söyledi (açıklama Örnek Sorular bölümündedir).

**Soru:** Hoca bunların hepsinin gürbüz en küçük karelerin alt yöntemleri olarak mı geçtiğini sordu. **Cevap:** Evet; Andrews, Huber ve Tukey yöntemleri M-kestirimi altında geçer. Aralarındaki fark yalnız ağırlık fonksiyonudur; ağırlık $1/\epsilon$ yerine ölçeklenmiş $z$'nin bir fonksiyonu olarak hesaplanır.

### 6.6 Karşılaştırma

Kendi oluşturduğu veri setinde (tek bir aykırı noktayla) sunumu yapan bütün yöntemleri karşılaştırdı (ekrandan, 03:15:00). Siyah OLS doğrusu aykırı noktaya doğru yatarak neredeyse yataylaşmıştı. Sarı (Huber) biraz daha iyi, mavi (ağırlıklı LS) daha iyi, kırmızı (Tukey biweight) bu veri seti için en iyi sonucu verdi. Yeşil (Andrews sinüs) doğrusu kırmızıyla neredeyse çakışıyordu.

```python
plt.plot(X,y_ols, color='black',label="OLS")
plt.plot(X,y_pred_weighted, color='blue',label="WLS")
plt.plot(X,y_andrews, color='green',label="Andrews' Sine")
plt.plot(X,y_hubers, color='yellow',label="Huber's Method")
plt.plot(X,y_tukeys, color='red',label="Tukey's Biweight")
```

Hoca aykırı değerleri bulup atmak gibi başka yöntemlerin de uygulanabileceğini belirtti. Sunumu yapan bunun trimmed LS'nin mantığı olduğunu, ama bu yöntemi uygulamadığını, M-kestirimi ve ağırlıklı LS'yi uyguladığını söyledi.

## 7. Stereo Görmeye Dayalı Anlamsal 3B Nesne ve Ego-Hareket İzleme

### 7.1 Genel bakış

Son sunum otonom sürüş için stereo görmeye dayalı anlamsal 3B nesne ve ego-hareket izleme bildirisini anlattı. Bildiride 3B nesne algılama, 3B kutuların doğrudan regresyonuyla değil, etiketlenmesi kolay 2B nesnelerin algılanıp sınıflandırılması ve çıkarımsal yöntemlerle yapılmıştır. Kamera yardımıyla belirlenen nesnelerin pozları demet ayarı (bundle adjustment) yaklaşımıyla doğru ve zamansal olarak tutarlı biçimde elde edilmiştir.

3B nesne algılamada iki ana sorun belirlenmiştir: 3B regresyon yaklaşımları çok sayıda eğitim verisi ister ve 3B kutuların tam etiketlenmesi ağır bir iş yüküdür. Ayrıca gecikmenin çok az olması gereken yüksek hızlı araçlarda sorunlar yaşanır. Bunun için hafif bir anlamsal 3B kutu çıkarımı önerilmiştir.

### 7.2 SLAM ve anlamsal SLAM

**Soru:** Hoca SLAM'in ne olduğunu sözlü açıklamasını istedi. **Cevap:** SLAM (simultaneous localization and mapping), eş zamanlı konum belirleme ve haritalamadır. Hiç bilinmeyen bir ortama bırakılan bir robot aynı anda hem kendi konumunu bulur hem de çevrenin haritasını çıkarır. Hoca bunun robotikte çok kullanıldığını ve konumu bulmanın aslında kameranın konumunu bulmak demek olduğunu vurguladı.

Anlamsal SLAM buna tanımayı (recognition) ekler (ekrandan, 03:20:00):

- Anlamsal bilgi destekli konum belirleme.
- SLAM destekli nesne algılama ve yeniden yapılandırma.
- Hem kamera hem nesne pozları için ortak tahmin.

Ego-hareket (egomotion), kameranın sahneye göre hareketinin tahminidir. Bu çalışmada iki kamera bulunduğu için her iki kameranın konumu da hesaba girer; geleneksel yaklaşımdan farkı buradadır.

### 7.3 Üç modül

Çalışma üç modüle ayrılır:

- **2B nesne algılama ve bakış açısı sınıflandırma:** nesne pozları, 2B kutu kenarları ile 3B kutu arasındaki kısıtlara dayanarak kabaca çıkarılır.
- **Özellik çıkarma ve eşleştirme.**
- **Optimizasyon:** tüm anlamsal bilgi ve öznitelik ölçümleri bir optimizasyon çerçevesinde birleştirilir.

Algılayıcı olarak Faster R-CNN seçilmiştir; küçük nesnelerde iyi başarım gösterir. Slayttaki grafiğe göre görüntü başına test süresi R-CNN'de 49 s, SPP-Net'te 4,3 s, Fast R-CNN'de 2,3 s, Faster R-CNN'de 0,2 s'dir (ekrandan, 03:25:00). Gerçek zamanlı gereksinim nedeniyle nesne algılama yalnız sol görüntüde yapılır.

**Soru:** Hoca YOLO'nun özellikle ticari uygulamalarda çok duyulduğunu belirtip sordu. **Cevap:** Sunumu yapan kendi denemesinde YOLO kullandığını, daha az nesne sınıfı tanısa da entegrasyonunun ve kullanımının daha kolay olduğunu söyledi. Hocanın eğitiminin de daha kolay olup olmadığı sorusuna evet cevabını verdi.

### 7.4 Bakış açısı sınıflandırması ve 3B kutu

Nesneye bakış açısı için 8 yatay ve 2 dikey sınıf tanımlanmıştır; toplam 16 kombinasyon vardır. 2B sınırlayıcı kutunun nesne sınırına sıkıca oturduğu varsayılır; ardından her kenar, yeniden izdüşürülen bir 3B köşeyle kesişir. Bakış açısı bilindiğinde 2B kutunun kenarları ile 3B kutunun tepe noktaları arasındaki ilişkiler bilinir; bu ilişkiler her 2B kutu için dört seçim matrisi olarak belirlenir (ekrandan, 03:35:00). Testlerde iyi geliştirilmiş bir 2B algılama ve sınıflandırmanın doğrudan 3B regresyondan çok daha iyi sonuç verdiği görülmüştür.

Formülasyonda dört kısıt, 2B kutunun dört kenarına ($u_{min}, u_{max}, v_{min}, v_{max}$) karşılık gelir. Sunumda $D$ matrisinin nesne boyutlarını (bir önceki kareden alınan boyutlar diye açıklandı), $C$ matrisinin bakış açısına göre nesne merkezi ile seçilen dört köşe arasındaki ilişkiyi tanımlayan seçim matrisini, $R$'nin $\theta$ yatay yönelimine karşılık gelen dönme matrisini, $p$'nin nesne merkezinin kamera çerçevesindeki konumunu gösterdiği söylendi. Kodlar açık değildir ve bildiride formüllerin yalnız tanımları verilmiştir.

### 7.5 Özellik çıkarma ve eşleştirme

Adımlar (ekrandan, 03:30:00):

- 2D kontur oluşturmak için çıkarılan 3B nesne kutuları stereo görüntülere yansıtılır.
- Nesnenin görünür kısmını temsil etmek için farklı renk maskeleri kullanılır.
- Nesneler ve arka plan için sol ve sağ görüntülerde ORB öznitelikleri çıkarılır.
- Stereo eşleştirme epipolar hat üzerinde arama ile yapılır.
- Aykırı eşleşmeler RANSAC ile ayıklanır.

ORB (Oriented FAST and Rotated BRIEF) hızlı ve sağlam bir yerel öznitelik bulucudur. Anahtar nokta bulmak için FAST algoritmasını, tanımlayıcı olarak BRIEF'i kullanır; noktaları sıralamak için Harris köşe ölçüsünden yararlanır. SIFT ve SURF'e alternatif olarak ortaya çıkmıştır. Epipolar geometri, iki kameranın aynı 3B sahneyi farklı konumlardan görüntülediği durumda 3B noktalar ile 2B görüntü izdüşümleri arasındaki ilişkiyi tanımlar. RANSAC (random sample consensus), veriyi en iyi açıklayan parametreleri rastgele örneklemeyle seçen ve aykırı değerleri ayıklayan bir yöntemdir.

**Soru:** Hoca burada klasik özelliklerin çıkarıldığını, yani yaklaşımın klasik olduğunu söyledi. **Cevap:** Sunumu yapan klasik yaklaşımların kullanıldığını, eğitilmiş bileşenler için hazır veri setlerinin kullanıldığını onayladı. Bildirinin katkısı, nesneyi doğrudan 3B algılamak yerine 2B algılayıp 3B'ye dönüştürerek hızlanmak ve hareket vektörlerini daha kolay çıkarmaktır.

### 7.6 Nesne takibi, ego-hareket ve araç modeli

$t$ anında $k$. nesnenin anlamsal ölçümü, 2B kutunun sol üst ve sağ alt köşe koordinatlarını, nesnenin sınıf etiketini, bakış açısını ve seçim matrisini içerir. Nesneye ya da arka plana bağlı öznitelik ölçümleri, stereo görüntülerdeki sol ve sağ koordinatlarla gösterilir. Durumlar $x$ ile gösterilir: $w$ dünya (genel çevre), $c$ kamera, $o$ nesne durumunu belirtir.

Ego-hareket en büyük olabilirlik (maximum likelihood) kestirimiyle çözülür; kamera pozu ve arka plan nokta bulutu SLAM ve hareketten yapı (structure from motion) yaklaşımıyla tahmin edilir. Hareketten yapı, sıralı çekilmiş 2B görüntülerden 3B model oluşturan bir fotogrametri tekniğidir. Aykırı değerlerin tespiti için Mahalanobis uzaklığı kullanılır. Hizalama (alignment) en büyük sonsal olasılık (maximum a posteriori) kestirimiyle yapılır.

Araç hareket modelindeki durum vektöründe $L$ ile gösterilen değer, tespit edilen aracın dingil mesafesidir. Bu değer gerçek zamanda değiştirilmez ve binek araçlar için sabitlenmiştir. Bu yüzden sistem yalnız binek araçlarını izler; karavan, otobüs ya da kamyon gibi araçları etiketlemez. Sunumu yapan bu gözlemi tanıtım videosunda da gösterdi.

### 7.7 Sonuçlar ve sunumdaki deneme

Sistem KITTI ve Cityscapes veri setleriyle ve dinamik araçlar içeren yaklaşık 700 metrelik bir güzergâhta test edilmiştir; kamera 10 FPS'tir. Nicel değerlendirmede göreli poz hatası ve mutlak yörünge hatasının kök ortalama karesi kullanılmış, ORB-SLAM2 ile karşılaştırılmıştır. Sonuç olarak sistem dinamik nesnelerden etkilenmeden dış ortamda kamera pozunu sağlam biçimde tahmin edebilmekte ve çevredeki nesnelerin hareketini sürekli izleyebilmektedir. LiDAR yalnız referans için kullanılmıştır.

Sunumu yapan, iki kameradan (dizüstü bilgisayarın kamerası ve harici bir kamera) gelen görüntüleri birleştirip (stitching) YOLO ile nesne tespiti yapan bir demo gösterdi. Hareket bilgisini katmak ve tam benzetim yapmak için gereken matematik hesapları yapılamadığı için deneme bununla sınırlı kaldı.

**Soru:** Hoca öğrenciye bu makaleyi neden seçtiğini sordu. **Cevap:** Stereo görüntüleme hakkında bilgisi az olduğu için öğrenmek amacıyla seçtiğini söyledi.

> **Hocanın vurgusu:** İki boyutlu görüntülerden üç boyutlu yapı elde etmek önemli ve zor bir problemdir ve ağır bir matematiğe dayanır. Bu konunun matrisleri ve matematiğini ayrıntılı açıklayan kitaplar vardır. Denklemlerin çıkarılıp anlatılması iki haftalık bir ders gerektirir; hoca önceki yıl bu konuyu işlediğini, bu yıl sinir ağlarına ağırlık verdiğini söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:27:00)
Çember için Hough dönüşümünde parametre uzayı nedir, sınırları nasıl belirlenir ve uzay ızgaraya nasıl bölünür?

> **Cevap (derste verildi):** Çember $(x-a)^2 + (y-b)^2 = r^2$ ile tanımlandığı için parametre uzayı $(a, b, r)$ üç boyutludur. $a$ ve $b$ görüntü koordinatlarıyla orantılı bir ızgarada tutulur. Aranacak yarıçap aralığı (örneğin 5'ten 50'ye) önceden seçilir ve her $r$ biriktiricinin bir katmanı olur. Her katmanda kenar noktalarının çevresine $r$ yarıçaplı çemberler çizilip oylar toplanır. Eşiği geçen noktalar çember merkezleridir.

**Soru 2** (ekrandan, 02:55:00)
$\{92, 19, 101, 58, 1053, 91, 26, 78, 10, 13, -40, 101, 86, 85, 15, 89, 89, 28, -5, 41\}$ veri kümesinde ($N = 20$, ortalama 101,5) baştan ve sondan %5 oranında winsorizing uygulayın. Yeni küme ve ortalaması nedir?

> **Cevap (derste verildi):** $g = 0{,}05 \times 20 = 1$. Sıralı kümenin en küçüğü $-40$, kendisine en yakın değer $-5$ ile; en büyüğü 1053, kendisine en yakın değer 101 ile değiştirilir. Yeni küme $\{92, 19, 101, 58, 101, 91, 26, 78, 10, 13, -5, 101, 86, 85, 15, 89, 89, 28, -5, 41\}$, ortalama $1113/20 = 55{,}65$ (python ile doğrulandı).

**Soru 3** (derste sözlü, 03:08:31)
M-kestiriminde ölçek kestirimi $\hat\tau = \mathrm{med}_i|r_i - \tilde r| / 0.6745$ formülündeki 0,6745 nereden gelir?

> **Çözüm (derste verilmedi):** 0,6745, standart normal dağılımın 0,75 kantilidir: $\Phi^{-1}(0{,}75) \approx 0{,}67449$ (python ile doğrulandı). Normal dağılımlı veride medyandan mutlak sapmaların medyanı (MAD) yaklaşık $0{,}6745\,\sigma$'dır. Bu yüzden MAD 0,6745'e bölünerek standart sapmanın aykırı değerlerden etkilenmeyen bir kestirimi elde edilir.

**Soru 4** (derste sözlü, 03:20:20)
SLAM nedir? Anlamsal SLAM ona ne ekler?

> **Cevap (derste verildi):** SLAM (simultaneous localization and mapping), bilinmeyen bir ortamdaki robotun aynı anda kendi konumunu (yani kamerasının konumunu) belirlemesi ve ortamın haritasını çıkarmasıdır. Anlamsal SLAM buna nesne tanımayı ekler: anlamsal bilgi destekli konum belirleme, SLAM destekli nesne algılama ve yeniden yapılandırma, kamera ve nesne pozlarının ortak tahmini.

**Soru 5** (derste sözlü, 01:09:19)
Stil aktarımı sunumundaki $\mathcal{L}_{GS} = \mathbb{E}[\log(s\,|\,D(\hat x))]$ ifadesinde dikey çizgi ne anlama gelir?

> **Cevap (derste verildi):** Koşullu olasılık gösterimidir: ayırt edicinin $\hat x$ için verdiği çıktıya göre görüntünün $s$ stilinde olma olasılığı. Ayırt edici her stil için bir gömme öğrendiğinden bu terim, üretilen görüntünün hedef stil gömmesine yakınlığını ölçer.

**Soru 6** (derste sözlü, 02:08:18)
GPU ile TPU arasında hız farkı var mıdır; TPU kullanımının kısıtları nelerdir?

> **Cevap (derste verildi):** Sunumu yapan TPU'yu henüz kullanmadığını, TPU'nun TensorFlow ile tam uyumlu çalışmadığını ve PyTorch desteğinin yeni olduğunu söyledi. Hoca TPU'nun Google'a özgü bir donanım olduğunu belirtti. Kaggle ve Colab gibi platformlar sınırlı süreli GPU ve TPU erişimi sağlar.

## Dersin Toparlaması

Bu son derste öğrenci sunumları dönem boyunca işlenen konuların uygulamalarını gösterdi. Klasik bilgisayarla görme tarafında çember için Hough dönüşümü (kenar bulma, oylama, üç boyutlu parametre uzayı), stereo görmede ORB öznitelikleri, epipolar eşleştirme ve RANSAC ile aykırı ayıklama, regresyonda aykırı değerlere dayanıklı gürbüz en küçük kareler yöntemleri (winsorized, trimmed, ağırlıklı LS ve M-kestirimi) ele alındı. Derin öğrenme tarafında ise evrişimli ağların bölütleme (U-Net, PSPNet, EfficientNet), sınıflandırma (Inception V3) ve üretici modellerde (StyleGAN, pSp, AdaIN tabanlı stil aktarımı, CycleGAN) nasıl kullanıldığı görüldü.

Hoca sunumlar sırasında parametre uzayının yapısını, olasılık gösterimini, gürbüz kestirimdeki ölçek sabitini ve SLAM kavramını sorgulayarak temel kavramlara dikkat çekti. Son olarak iki boyutlu görüntülerden üç boyutlu yapı elde etmenin ağır matematik gerektiren, ayrıntılı ele alınması gereken önemli bir problem olduğunu vurguladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
