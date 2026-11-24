# Ders 5 Çalışma Özeti

## Genel Konular

- Güncel araştırma örneği: kişi yeniden kimliklendirme
  - Kişi yeniden kimliklendirme (person re-identification), örneğin bir kampüsteki çok sayıda kameradan alınan görüntülerde aynı kişiyi yeniden bulma problemidir.
  - Klasik yaklaşımlar kişiyi büyük ölçüde üzerindeki kıyafetlerden yakalar. Kıyafet değiştiren kişileri içeren veri kümeleri (Clothes Changing Person dataset) problemi zorlaştırır.
- Eşikleme (thresholding) ve bölütleme
  - Eşikleme gri seviyeli görüntüyü bir $T$ eşik değeriyle ikili (siyah-beyaz) görüntüye çevirir. Ön plandaki nesneler arka plandan ayrılabiliyorsa bu işlem en basit bölütleme (segmentation) işlemi olur.
  - Eşikleme hızlı ve az maliyetlidir; özel donanımla gerçek zamanda yapılabilir (ekrandan, 00:25:00).
  - Görüntü birbiriyle kesişmeyen bölgelere ayrılır: $R = \bigcup_{i=1}^{S} R_i$, $R_i \cap R_j = \emptyset$, $i \neq j$ (ekrandan, 00:25:00).
  - Eşikleme kuralı: $g(i,j) = 1$, eğer $f(i,j) \geq T$; $g(i,j) = 0$, eğer $f(i,j) < T$ (ekrandan, 00:25:00).
  - Genelde iki bölgeye ayrılır; ikiden fazla bölgeye ayırmak da mümkündür.
- Eşik değerinin seçimi
  - Derste ahşap nesneler görüntüsünde $T = 95$ iyi sonuç verdi: nesnelerin hiçbiri kaybolmadı. Yine de nesnelerin gölgeli yan yüzleri kısmen arka plana karıştı, köşeler yuvarlandı.
  - $T = 25$ aşırı bölütleme (over segmentation) verir: arka planın büyük kısmı beyaz olur. $T = 225$ eksik bölütleme (under segmentation) verir: nesneler kaybolur (ekrandan, 00:30:00).
  - Kural arka planın rengine bağlıdır. Arka plan siyah, nesneler beyazsa büyük değerler ön plandır; tersi durumda kural da ters çevrilir.
- Gonzalez ve Woods küresel eşikleme algoritması (ekrandan, 00:35:00)
  - 1: Başlangıç $T$ seç; önerilen değer görüntüdeki en küçük ve en büyük parlaklığın orta noktasıdır.
  - 2: Görüntüyü $T$ ile iki gruba ayır: $G_1$ ($\geq T$) ve $G_2$ ($< T$).
  - 3: Grupların ortalama parlaklıkları $\mu_1$ ve $\mu_2$'yi hesapla.
  - 4: Yeni eşik $T = (\mu_1 + \mu_2)/2$.
  - 5: Ardışık $T$ değerleri arasındaki fark önceden belirlenen $T_0$'dan küçük olana kadar 2-4 adımlarını tekrarla. Genelde birkaç iterasyonda yakınsar.
- Hazır eşikleme yöntemleri (scikit-image)
  - `skimage.filters.try_all_threshold` bir görüntüye Isodata, Li, Mean, Minimum, Otsu, Triangle ve Yen yöntemlerini birlikte uygular (ekrandan, 00:45:00 ve 00:50:00). Örnek, sol tarafı gölgeli taranmış bir belge sayfasıdır; gölgeli bölge siyaha dönünce yazı okunmaz olur.
  - Ortalama (mean) eşiği, piksel ortalamasını eşik alan basit bir tahmindir.
  - Minimum yöntemi iki tepeli (bimodal) histogramı yalnız iki tepe kalana dek tekrar tekrar düzleştirir ve eşiği iki tepe arasından seçer.
  - Otsu yöntemi derste hızlı çalışan, başarımı diğerlerinden çok farklı olmayan bir yöntem olarak anıldı.
- Bağlantılı bileşen etiketleme (connected component labeling)
  - İkili görüntüde aynı değerde ve birbirine komşu pikseller aynı bölgeye aittir ve aynı etiketi alır.
  - Derste 8×8 ikili görüntüde beyaz (1) piksellerden oluşan beş bölge 1-5 diye etiketlendi; etiketler renklerle de gösterilebilir (ekrandan, 01:10:00).
  - Özyinelemeli (recursive) etiketleme algoritması: görüntünün negatifi alınır (1'ler $-1$ olur), her $-1$ gözünde etiket bir artırılır ve `search` yordamı komşulara yayılarak aynı etiketi verir (ekrandan, 01:15:00).
  - Komşuluk 4'lü (kuzey, güney, doğu, batı) ya da 8'li (çaprazlar dahil) olabilir.
  - Hazır fonksiyon: `skimage.measure.label`.
- Matematiksel morfoloji
  - Küme teorisine dayanan işlemler topluluğudur; kenar bulma, gürültü giderme, görüntü iyileştirme ve bölütlemede kullanılır (ekrandan, 01:25:00).
  - Girdiler ikili görüntü ve yapılandırma elemanıdır (structuring element, $S$). $S$ küçük bir ikili görüntüdür; kutu, disk, halka, artı, elmas gibi biçimleri olabilir ve bir merkez (origin) pikseli vardır.
  - Aşındırma (erosion, $A \ominus B$): nesneyi inceltir, küçültür.
  - Yayma (dilation, $A \oplus B$): nesneyi kalınlaştırır, büyütür; kopuk parçaları birleştirebilir.
  - Açma (opening): $B \circ S = (B \ominus S) \oplus S$. Sınırları yumuşatır, dar boyunları koparır, ince çıkıntıları temizler.
  - Kapama (closing): $B \bullet S = (B \oplus S) \ominus S$. Dar kopuklukları ve boşlukları kapatır.
  - Uygulamalar: dişli çarklarda kırık diş tespiti, tıbbi görüntüde eşikleme sonrası organları belirginleştirme, sınır çıkarma (boundary extraction).

## Hocanın Özellikle Vurguladığı Kısımlar

- Eşik kuralı ezberlenmemeli
  - "Büyük olan 1" kuralı yalnız arka planı siyah olan görüntüler için geçerlidir. Arka plan beyazsa kural ters çevrilir; problem her durumda ayrıca değerlendirilmelidir.
- Küçük örnekler elle çözülebilmeli
  - Küresel eşikleme algoritmasının bir iterasyonunu, verilen küçük gri seviye matris üzerinde elle hesaplayabilmek gerekir.
  - Verilen ikili görüntüye bir yapılandırma elemanıyla arka arkaya aşındırma ve yayma (açma, kapama) uygulandığında sonucu adım adım elle oluşturabilmek gerekir.
- Eşikleme tanımı
  - Eşiklemenin ne olduğu tarif edilebilmelidir.
- Özyinelemeli etiketlemede sınır kontrolü
  - Komşu kümesi kurulurken görüntü dışına taşan indeksler kontrol edilmelidir.
  - Özyinelemeli algoritma hızlıdır ama özyineleme nedeniyle bellek ister.
- Yapılandırma elemanının seçimi
  - Elemanın biçimi görüntüde aranan ya da temizlenmek istenen bölgenin biçimine uygun seçilir: disk aranıyorsa disk biçimli eleman kullanılır.

## Kısa Tekrar Notları

- Eşikleme = gri görüntüden ikili görüntü = en basit bölütleme.
- $g = 1$ ($f \geq T$), $g = 0$ ($f < T$); arka plan beyazsa tersi.
- Düşük $T$: aşırı bölütleme; yüksek $T$: nesne kaybı.
- Küresel eşikleme: $T_0 = (\min + \max)/2$, grupla, $\mu_1, \mu_2$, $T = (\mu_1+\mu_2)/2$, fark küçülene kadar tekrarla.
- `try_all_threshold`: Isodata, Li, Mean, Minimum, Otsu, Triangle, Yen.
- Bağlantılı bileşen: komşu ve aynı değerli pikseller aynı etiketi alır; 4'lü ya da 8'li komşuluk.
- Özyinelemeli etiketleme: negatif al, tara, $-1$ bulunca etiket++, komşulara özyinelemeli yay.
- Aşındırma $\ominus$ inceltir; yayma $\oplus$ kalınlaştırır.
- $d \times d$ kareyi $d/4 \times d/4$ kareyle aşındırmak her kenardan $d/8$ yer; yaymak her kenara $d/8$ ekler.
- Açma = aşındır sonra yay; kapama = yay sonra aşındır.
- Yapılandırma elemanı aranan şekle göre seçilir.

## Detaylı Açıklamalar

- Eşikleme ve eşik seçimi
  - Eşikleme, her pikselin parlaklığını tek bir $T$ değeriyle karşılaştırıp 0 ya da 1 atamaktır. Ön plan ile arka plan arasında belirgin parlaklık farkı varsa sonuç doğrudan bir bölütleme olur. Ahşap nesneler örneğinde $T=95$ ile koyu gri arka plan tamamen siyah, nesneler beyaz oldu; ama gölgeli yan yüzler ve yuvarlanmış köşeler eşiklemenin zayıf yanlarını gösterdi. $T=25$ seçildiğinde 25'ten büyük her şey beyaz olduğu için arka planın büyük kısmı da ön plan sayıldı; $T=225$ seçildiğinde ise nesnelerin neredeyse tamamı arka plana gitti.
- Küresel eşikleme örneği (derste sınav sorusu olarak)
  - 5×5 boyutlu gri seviye görüntüde en küçük değer 76, en büyük değer 203 bulundu. Başlangıç eşiği $T_0 = (76+203)/2 = 139{,}5$ oldu. $G_1$ ($\geq T_0$) ve $G_2$ ($< T_0$) grupları ayrıldı; ortalamalar derste yaklaşık $\mu_1 \approx 188{,}1$ ve $\mu_2 \approx 92{,}8$ bulundu. Yeni eşik $T = (188{,}1 + 92{,}8)/2 = 140{,}45$ oldu. Soru yalnız birinci iterasyon sonundaki eşiği istiyordu. Hocaya göre 140 eşiği grupları değiştirmediği için algoritma ikinci iterasyonda durur.
  - <!-- BELİRSİZ: 5×5 matrisin tüm değerleri karelerde görünmüyor; altyazıda yalnız bir kısmı (76, 90, 82, 80, 101, 113, 103, 120 gibi) okunuyor. -->
- Taranmış belge örneği
  - Sayfanın sol tarafı gölgeli, sağ tarafı aydınlık olduğu için tek bir küresel eşik gölgeli bölgeyi siyaha çevirip yazıyı okunmaz yapar. Bu tür görüntülerde gölge etkisini en az bırakan yöntem tercih edilir. Bir öğrencinin keskinleştirme (sharpening) ile harf kenarlarını belirginleştirip sonra eşiklemenin işe yarayıp yaramayacağı sorusuna hoca, denenebileceğini ama problemin gerçekten zor olduğunu söyledi.
  - <!-- BELİRSİZ: Hoca bu bölümde "region-based segmentation biraz daha başarılı" dedi; "Region-based segmentation" ekrandaki belgenin başlığıdır. Ekranda gölgeyi en iyi taşıyan çıktı büyük olasılıkla Yen yöntemininkidir. -->
- Özyinelemeli bağlantılı bileşen etiketleme
  - Ekrandaki yordam (01:15:00) üç parçadır: `recursive_connected_components(B, LB)` önce `LB := negate(B)` ile 1'leri $-1$ yapar, `label := 0` atar ve `find_components(LB, label)` çağırır. `find_components` bütün satır ($L$) ve sütunları ($P$) tarar; `LB[L,P] == -1` ise `label := label + 1` yapıp `search(LB, label, L, P)` çağırır. `search` gözüne etiketi yazar, komşu kümesini (`Nset := neighbors(L,P)`) kurar ve komşulardan $-1$ olanlar için kendini çağırır. Derste bir öğrencinin sorusu üzerine, ilk satır ya da sütun gibi kenar gözlerde komşu kümesi kurulurken görüntü dışı indekslerin elenmesi gerektiği vurgulandı.
  - Ekrandaki 8×8 örnek (01:10:00) python ile denendi: algoritma 4'lü ve 8'li komşulukta aynı beş bölgeyi ve ekrandaki etiketleri verdi.
- Morfolojik işlemlerin mantığı
  - Aşındırmada yapılandırma elemanının merkezi görüntüdeki her 1 pikseline konur; elemanın kapladığı bütün gözler 1 ise piksel korunur, biri bile 0 ise piksel 0 olur. Artı biçimli elemanla aşındırılan halter (dumbbell) şekli inceldi.
  - Yaymada elemanın merkezi her 1 pikseline konur ve elemanın kapladığı bütün gözler 1 yapılır. 3×3 kare elemanla her nesne her yönde bir piksel büyür.
  - $d \times d$ kare $d/4 \times d/4$ kareyle aşındırıldığında her kenardan elemanın yarısı kadar ($d/8$) aşınır ve $3d/4$ kenarlı kare kalır (ekrandan, 01:35:00). Eleman $d$ yüksekliğinde ve $d/4$ genişliğinde ise yükseklik tamamen aşınır ve ortada yatay bir çizgi kalır. Yaymada aynı elemanlar kareyi her kenardan $d/8$, ya da yukarı ve aşağı $d/2$, yanlara $d/8$ büyütür.
  - Baskılı devre kartı görüntüsü 11×11, 15×15 ve 45×45 kare elemanlarla aşındırıldı; 45×45'te yalnız ortadaki büyük bölgenin aşınmış hali kaldı.
  - Düşük çözünürlüklü taranmış metinde kopuk harf parçaları artı biçimli 3×3 elemanla yayılarak birleştirildi (ekrandan, 01:40:00).
- Dişli çark uygulaması
  - Banttaki dişli çarkların kırık dişleri arka arkaya morfolojik işlemlerle bulunur. Önce vida delikleri bulunup delik maskesiyle kapatılır, sonra dişlerin bulunduğu halka (B7) çıkarılır. $B8 = B \text{ AND } B7$ dişlerin aralıklı noktalarını verir; $B9 = B8 \oplus \text{tip\_spacing}$ dişleri birleştirir; $\text{RESULT} = ((B7 - B9) \oplus \text{defect\_cue}) \text{ OR } B9$ kırık dişin yerini işaretler (ekrandan, 01:55:00).
- Python ile morfoloji
  - 5×5 sentetik görüntünün ortasında 3×3 beyaz kare (`bright_square`) vardır. `skimage.morphology.binary_erosion` ve 3×3 `square` elemanla aşındırınca yalnız merkez piksel 1 kalır (ekrandan, 01:50:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
