# Ders 7 Çalışma Özeti

## Genel Konular

- Klasik bilgisayarla görmeden derin öğrenmeye geçiş
  - Konvolüsyon, filtreler, birinci ve ikinci dereceden türev gibi temel kavramlar, hem klasik yöntemlerin hem de derin öğrenme ile görmenin temelidir.
  - Bu derste klasik öznitelik çıkarma yöntemlerinden HOG ve Harris köşe bulucu işlenir, ardından evrişimli sinir ağlarına (CNN) giriş yapılır.
- HOG (Histogram of Oriented Gradients, yönelimli gradyan histogramı)
  - Dalal ve Triggs tarafından CVPR 2005'te sunulmuştur. İlk amaç görüntüde insan bulmaktır (human detection): kol, bacak ve gövde hatlarını oluşturan kenarların açılarına bakılarak insan olup olmadığına karar verilir.
  - Sonradan genel bir öznitelik çıkarma yöntemi olarak doku sınıflama ve şekil tanıma gibi farklı alanlarda kullanılmıştır.
- HOG'un yedi adımı (ekrandan, 00:20:00)
  - 1: Yumuşatma yapmadan merkezi (centered) yatay ve dikey gradyanları hesapla.
  - 2: Gradyan yönelimini (orientation) ve büyüklüğünü (magnitude) hesapla. Renkli görüntüde her piksel için gradyan büyüklüğü en yüksek renk kanalı seçilir.
  - 3: Örnek olarak $64\times128$ boyutlu bir görüntü alınır.
  - 4: Görüntü %50 örtüşen $16\times16$ bloklara bölünür; toplam $7\times15=105$ blok çıkar.
  - 5: Her blok $8\times8$ boyutlu $2\times2$ hücreden (cell) oluşur.
  - 6: Gradyan yönelimi 9 aralığa (bin) nicemlenir. Oy, gradyan büyüklüğüdür; oylar komşu aralık merkezleri arasında doğrusal olarak paylaştırılır; blok kenarına yakın pikseller Gauss ile daha az ağırlıklandırılabilir.
  - 7: Histogramlar art arda eklenir; öznitelik boyutu $105\times4\times9=3780$ olur.
- Gradyan hesabı (ekrandan, 00:30:00)
  - Merkezi fark: $f'(x) \approx \dfrac{f(x+h)-f(x-h)}{2h}$.
  - $x$ yönü maskesi $[-1\ 0\ 1]$, $y$ yönü maskesi aynı maskenin dikey hâlidir ($[-1\ 0\ 1]^T$).
  - Büyüklük $M=\sqrt{s_x^2+s_y^2}$, yönelim $\theta=\arctan(s_y/s_x)$.
- Yönelim histogramı ve oyların paylaştırılması (ekrandan, 00:35:00 ve 00:45:00)
  - $0$-$180^\circ$ aralığı $20^\circ$'lik 9 aralığa bölünür; aralık merkezleri $10, 30, 50, \dots, 170$ olur.
  - Bir hücrenin 64 pikselinin her biri oy verir; oylar toplanarak hücrenin 9 uzunluklu histogramı oluşur.
  - Örnek: $\theta=85^\circ$ olan pikselin 90 merkezine uzaklığı 5, 70 merkezine uzaklığı 15'tir. Oyun $3/4$'ü 90 merkezine, $1/4$'ü 70 merkezine gider. Gradyan büyüklüğü 100 ise 75 ve 25 oy verilir.
- Blok normalizasyonu ve son öznitelik vektörü
  - Bloklar %50 örtüştüğü için aynı hücre birden fazla blokta yer alır. Her blok içindeki 4 hücrenin $2\times2\times9=36$ histogram değeri kendi içinde normalize edilir (karelerin toplamının karekökü ile, yani L2 normu).
  - Paydaya eklenen sabit, kenar bulunmayan (büyüklüğü sıfır olan) bölgelerde paydanın sıfır olmasını önler. <!-- BELİRSİZ: Formülün tam yazımı (sabitin karekök içinde mi olduğu) slayt karelerde görünmediği için doğrulanamadı. -->
  - Bütün histogramlar art arda eklenerek 3780 uzunluklu tek boyutlu öznitelik vektörü elde edilir (ekrandan, 00:50:00).
  - Görselleştirmede her hücrede baskın yönelim çizgi olarak çizilir; insan silüeti dikey, su yüzeyindeki dalgalar yatay çizgiler olarak görünür.
- scikit-image ile HOG (ekrandan, 00:55:00 ve 01:00:00)
  - `skimage.feature.hog(image, orientations=9, pixels_per_cell=(8, 8), cells_per_block=(3, 3), block_norm='L2-Hys', visualize=False, ...)` imzası incelendi.
  - Derste astronot görüntüsü ($512\times512$) gri seviyeye çevrildi; 9 yönelim, $8\times8$ piksel/hücre, $2\times2$ hücre/blok ve `visualize=True` ile HOG görüntüsü çizdirildi. Hücre $16\times16$ yapılınca çizgiler daha büyük alanlarda çizildi.
- Geleneksel makine öğrenmesi akışı ile derin öğrenme
  - Geleneksel akış: girdi görüntüsü → elle tasarlanmış öznitelik çıkarma (köşe, kenar, HOG) → makine öğrenmesi algoritması → çıktı.
  - Derin öğrenmede öznitelik çıkarma CNN katmanlarında otomatik yapılır ve insanın aklına gelmeyen karmaşık öznitelikler de bulunabilir.
- İlgi noktası (interest point) bulma
  - Köşe ve kenar gibi noktalar bulunur, bu noktaların çevresinden tanımlayıcılar (descriptor) çıkarılır ve iki görüntünün tanımlayıcıları eşleştirilerek aynı nesne ya da sahne olup olmadıkları anlaşılır.
  - Tekrarlanabilirlik (repeatability): aynı sahnenin farklı açı ve ölçekte çekilmiş iki görüntüsünde aynı noktaların (en azından bir kısmının) bulunması gerekir; bulma işlemi her görüntüde bağımsız çalışabilmelidir (ekrandan, 01:20:00).
- Harris köşe bulucu
  - Köşe bir pencere içinde tanınır: pencereyi herhangi bir yönde kaydırmak parlaklıkta büyük değişim yaratmalıdır (ekrandan, 01:25:00).
  - Düz bölge (flat): hiçbir yönde değişim yok. Kenar (edge): kenar doğrultusunda değişim yok. Köşe (corner): her yönde belirgin değişim var.
  - $E(u,v)=\sum_{x,y} w(x,y)\,[I(x+u,y+v)-I(x,y)]^2$; pencere fonksiyonu $w$ dikdörtgen ya da Gauss olabilir.
  - Küçük kaymalar için $E(u,v)\cong[u\ v]\,M\,[u\ v]^T$, burada $M=\sum_{x,y} w(x,y)\begin{bmatrix} I_x^2 & I_xI_y\\ I_xI_y & I_y^2\end{bmatrix}$ (ekrandan, 01:30:00).
  - $M$'nin öz değerleri $\lambda_1,\lambda_2$: ikisi de küçükse düz bölge, biri büyük diğeri küçükse kenar, ikisi de büyükse köşe.
- scikit-image ile Harris (ekrandan, 01:35:00 ve 01:40:00)
  - `skimage.feature` modülünde FAST, Förstner, Harris, Kitchen-Rosenfeld ve Moravec köşe bulucuları vardır.
  - Örnekte satranç tahtası afin dönüşümle bükülür, bir elips ve iki beyaz kare eklenir; `corner_peaks(corner_harris(image), min_distance=5)` ile köşeler bulunur. Dik köşeler bulunurken 120 dereceye yakın geniş açılı bazı köşeler kaçırılır.
- LeNet ve CNN'e giriş (ekrandan, 01:45:00)
  - LeNet (Yann LeCun, 1998): $32\times32$ girdi → C1: $6@28\times28$ → S2: $6@14\times14$ → C3: $16@10\times10$ → S4: $16@5\times5$ → C5: 120 → F6: 84 → çıktı: 10.
  - $32\to28$ küçülmesinden filtrelerin $5\times5$ olduğu çıkarılır (dolgu yok). Alt örnekleme her boyutu yarıya indirir.
  - İki konvolüsyon katmanına kadar olan kısım öznitelik çıkarıcıdır; sonra düzleştirme (flatten) ve tam bağlı katmanlar gelir. Günümüz ağlarında konvolüsyon katmanı sayısı yüzü bulabilir.
- Konvolüsyon katmanında filtreler (ekrandan, 01:50:00 ve 01:55:00)
  - $6\times6$ ikili girdi görüntüsü ve iki $3\times3$ filtre: Filtre 1 ana köşegendeki çizgileri, Filtre 2 dikey çizgileri yakalar. Filtre katsayıları ağın öğrenilecek parametreleridir.
  - $3\times3$ filtre dolgusuz uygulanınca $6\times6$ girdi $4\times4$ çıktı verir. Adım (stride) 1'den büyük seçilebilir.
- Renkli görüntüde konvolüsyon (ekrandan, 02:00:00)
  - RGB girdi $6\times6\times3$ ise filtre $3\times3\times3$ olur. Her konumda $27$ çarpım toplanır ve tek değer çıkar; bir filtrenin çıktısı $4\times4$ tek kanaldır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yöntemlerin içindeki matematik
  - HOG ve Harris'in hazır kodları vardır; ama içlerindeki matematik (özellikle oyların komşu aralıklara uzaklıkla orantılı paylaştırılması) başka problemlerde de çözüm fikri olabilir. Açı hesaplayıp onun üzerinden iş yapılan her durumda bu yöntem akla gelmelidir.
- Konvolüsyon sonucunu elle hesaplama
  - Bir giriş görüntü matrisi ve $3\times3$ filtre verildiğinde bir pikselin konvolüsyon sonucunu ve çıktının boyutunu hesaplayabilmek gerekir; hoca bunun sınavda sorulabileceğini söyledi.
- RGB görüntüde filtre boyutu
  - Renkli görüntüde filtre üç kanallıdır ($3\times3\times3$) ama bir filtre tek bir çıktı kanalı üretir; buna özellikle dikkat edilmelidir.
- Derin ağlarda katman boyutlarını kâğıt üzerinde hesaplama
  - Her konvolüsyon katmanında kaç filtre olduğu, boyutu ve çıktı boyutu hesaplanabilmelidir; bu, filtrenin ne iş yaptığını hayal edebilmeyi sağlar.
- Harris'in temel fikri
  - Köşe bulucu anlatılırken pencerenin düz bölge, kenar ve köşe üzerinde kaydırıldığı şekil üzerinden anlatılmalıdır.

## Kısa Tekrar Notları

- HOG: gradyan → büyüklük ve yönelim → %50 örtüşen $16\times16$ bloklar → bloğu $2\times2$ adet $8\times8$ hücreye ayır → her hücrede 9 aralıklı yönelim histogramı → blok içi normalizasyon → art arda ekle.
- $64\times128$ görüntü: $7\times15=105$ blok, öznitelik boyutu $105\times4\times9=3780$.
- Gradyan maskesi $[-1\ 0\ 1]$; $M=\sqrt{s_x^2+s_y^2}$, $\theta=\arctan(s_y/s_x)$; yönelim $0$-$180^\circ$.
- Oy = gradyan büyüklüğü; iki komşu aralık merkezine uzaklıkla ters orantılı paylaştırılır ($85^\circ$ → 90'a $3/4$, 70'e $1/4$).
- Blok içi L2 normalizasyonu örtüşen bloklarda aynı histogramın aynen tekrarlanmasını önler; paydadaki sabit sıfıra bölmeyi engeller.
- Harris: $M$ matrisi türevlerden kurulur; $\lambda_1,\lambda_2$ küçük → düz, biri büyük → kenar, ikisi büyük → köşe.
- Tekrarlanabilirlik: iki görüntüde aynı ilgi noktaları bulunmalıdır.
- LeNet: $32\to28\to14\to10\to5$; $5\times5$ filtreler, 6 ve 16 filtre.
- Dolgusuz $3\times3$ konvolüsyon: $n\times n \to (n-2)\times(n-2)$. RGB'de filtre $3\times3\times3$, çıktı tek kanal.

## Detaylı Açıklamalar

- HOG yöntemi kenar noktalarının açılarından bir dağılım çıkarır. İlk adımda görüntüye yumuşatma uygulanmadan yatay ve dikey yönde birinci türev alınır. Maske $[-1\ 0\ 1]$ olduğu için merkez pikselin türevi sağdaki pikselden soldaki çıkarılarak bulunur. Önceki derslerde yalnız sağdaki ile kendisi arasındaki fark kullanılmıştı; hocaya göre sıra yalnız işareti değiştirir, büyüklükte kare alındığı için bir fark yaratmaz. Bulunan $s_x$ ve $s_y$ ile büyüklük $\sqrt{s_x^2+s_y^2}$, yönelim $\arctan(s_y/s_x)$ olur (ekrandan, 00:30:00).
- Blok ve hücre yapısı $64\times128$ örnek görüntü üzerinden anlatılır. Blok $16\times16$ pikseldir ve komşu bloklar hem satır hem sütun yönünde %50 örtüşür. Bu yüzden yatayda $64/8-1=7$, dikeyde $128/8-1=15$ blok konumu vardır; toplam 105 blok çıkar. Her blok $2\times2$ hücreye bölünür, her hücre $8\times8=64$ pikseldir (ekrandan, 00:25:00).
- Histogram oluşturulurken hücredeki 64 pikselin her biri yönelimine göre oy verir. $0$-$180^\circ$ aralığı 9'a bölündüğünden aralık genişliği $20^\circ$'dir. Pikselin oyu tek bir aralığa yazılmaz: piksel, içine düştüğü aralığın merkezi ile en yakın komşu merkez arasında paylaştırılır. $85^\circ$ örneğinde merkezlere uzaklıklar 5 ve 15'tir; yakın merkeze $1-5/20=3/4$, uzak merkeze $1-15/20=1/4$ oran düşer. Bu oranlar gradyan büyüklüğüyle çarpılır; büyüklük 100 ise 90 merkezine 75, 70 merkezine 25 oy yazılır (ekrandan, 00:45:00). $95^\circ$ olsaydı oy 90 ve 110 merkezleri arasında paylaştırılırdı.
- Histogramda yüksek çubuklar, hücrede o açılarda çok sayıda ve güçlü kenar bulunduğunu gösterir.
- Blok normalizasyonunda bir bloktaki dört hücrenin 36 değerinin kareleri toplanır, karekök alınır ve bütün değerler buna bölünür. Örtüşmeden dolayı bir hücre birden çok blokta bulunur; normalizasyon her blokta farklı olduğundan aynı değerler aynen tekrarlanmaz. Paydadaki sabit, kenarsız (örneğin simsiyah) bölgede bütün büyüklükler sıfır olduğunda sıfıra bölmeyi önler.
- scikit-image `hog` fonksiyonunda yönelim sayısı, hücre başına piksel, blok başına hücre, blok normu (`L2-Hys` öntanımlı) ve görselleştirme seçilebilir. Küçük doku değişimlerinin önemli olduğu uygulamalarda hücre boyutu küçültülebilir.
- Harris köşe bulucuda bir pencere görüntü üzerinde $u$ ve $v$ kadar kaydırılır; kaydırılmış ve özgün pencere arasındaki farkların kareleri pencere fonksiyonuyla ağırlıklandırılıp toplanarak $E(u,v)$ bulunur. Küçük kaymalarda bu ifade $2\times2$ $M$ matrisiyle yazılır. $M$'nin elemanları $x$ türevinin karesi, $x$ ve $y$ türevlerinin çarpımı ve $y$ türevinin karesidir. $M$'nin iki öz değeri değişimin olduğu eksenleri gösterir; ikisi de büyükse pencere hangi yöne kaydırılırsa kaydırılsın değişim olur ve bu bir köşedir.
- scikit-image Harris örneğinde satranç tahtası bükülerek köşe açıları 90 dereceden uzaklaştırılır, ayrıca merkezi $(310, 175)$ ve yarı eksenleri $10$ ve $100$ olan bir elips ile `image[180:230, 10:60]` ve `image[230:280, 60:110]` beyaz kareleri eklenir (ekrandan, 01:40:00). `min_distance` parametresi `corner_harris`'in değil `corner_peaks`'in parametresidir.
- CNN'de konvolüsyon filtresinin katsayıları elle seçilmez, öğrenilir. Örnek $6\times6$ ikili görüntüde Filtre 1 sol üst köşeye oturtulunca görüntü parçasının köşegenindeki üç 1 filtrenin $+1$ katsayılarıyla çakışır, diğer altı hücre 0 olduğu için sonuç $3$ çıkar; Filtre 2 aynı konumda $-1$ verir. Filtre 2'nin en yüksek çıktısı ($3$) görüntünün sağ alt köşesindeki dikey çizgide oluşur.
- RGB görüntüde aynı işlem üç kanalda birlikte yapılır; filtre her kanal için ayrı katsayılar taşıdığından renk bilgisi kaybolmaz, ama bir filtre tek bir çıktı haritası üretir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
