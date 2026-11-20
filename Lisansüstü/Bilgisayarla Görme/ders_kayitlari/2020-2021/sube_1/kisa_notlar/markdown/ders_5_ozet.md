# Ders 5 Çalışma Özeti

## Genel Konular

- Harris köşe bulucusunun Python ile gerçeklenmesi (bir ödev çözümü üzerinden)
  - Türevler (ör. Sobel ya da `filter2D` ile) alınır, sonra Gauss pencere fonksiyonuyla yumuşatılır. Gauss filtresi ayrılabilir olduğu için iki tek boyutlu konvolüsyonla uygulanabilir (ekrandan, 00:10:00).
  - İkinci moment matrisi her piksel için $M=\nabla I(\nabla I)^T=\begin{bmatrix}I_x\\I_y\end{bmatrix}[I_x\;I_y]$ biçimindedir (ekrandan, 00:10:00).
  - NumPy'da $256\times256$ bir imge için `np.array([[derIX, derIY]])` dizisinin şekli $(1,2,256,256)$ olur. `np.transpose(..., axes=(2,3,1,0))` ile $(256,256,2,1)$, ikinci bir `transpose(..., axes=(0,1,3,2))` ile $(256,256,1,2)$ elde edilir. `np.matmul` bunları çarpınca her piksel için bir $2\times2$ matris, yani $(256,256,2,2)$ boyutlu bir dizi çıkar (ekrandan, 00:10:00; şekiller python ile doğrulandı).
  - `transpose` eksenleri yeniden sıralar. Verilen demetin $i$. elemanı, yeni dizinin $i$. ekseninin eski dizide hangi eksen olduğunu söyler.
  - Hoca daha basit bir yol önerdi: $I_x^2$, $I_xI_y$ ve $I_y^2$ için ayrı imgeler tutup her pikselde çarpma ve toplama yapmak.
  - Özdeğerler `np.linalg.eigvals(M)` ile bulunur. $\lambda_{max}$ en hızlı değişimin, $\lambda_{min}$ en yavaş değişimin yönüne karşılık gelir (ekrandan, 00:10:00).
  - Köşe cevabı (corner response) determinant ve iz (trace) ile hesaplanır, bir eşiğin altındaki değerler sıfırlanır, sonra maksimum olmayanı bastırma (non-maximum suppression) uygulanır.
- Değişim elipslerinin çizimi
  - $M=R^{-1}\begin{bmatrix}\lambda_1&0\\0&\lambda_2\end{bmatrix}R$ köşegenleştirmesinde elipsin eksen uzunluklarını özdeğerler, yönünü $R$ (özvektörler) belirler (ekrandan, 00:20:00).
  - En hızlı değişim yönündeki yarı eksen $(\lambda_{max})^{-1/2}$, en yavaş değişim yönündeki yarı eksen $(\lambda_{min})^{-1/2}$ uzunluğundadır (ekrandan, 00:20:00). Yani elipsin uzun ekseni değişimin en az olduğu yöndedir.
  - Ödevde üs $+1/2$ alınmıştı (`eigMax**(1/2)`) (ekrandan, 00:15:00). Hoca bunun elipsleri 90 derece ters gösterdiğini, üssün $-1/2$ olması gerektiğini söyledi.
  - Elipsler her pikselde değil, $7\times7$ pencerelerin ortalamasıyla çizildi; bu yalnız gösterim içindir, Harris bulucusu piksel tabanlıdır. Çizim `matplotlib.patches.Ellipse` ile yapılır; konum, genişlik, yükseklik ve açı verilir (ekrandan, 00:15:00).
  - Elipsin açısı özvektörlerden hesaplanmalıdır. Açıyı imge parlaklığından vermek doğru değildir.
- Harris bulucusunun değişmezlik ve eşdeğişkenlik özellikleri
  - Yalnız türev kullanıldığı için parlaklık kaymasına ($I\to I+b$) değişmezdir. Parlaklık ölçeklemesinde ($I\to aI$) cevaplar büyür, eşiği aşan noktalar değişebilir. Sonuç: afin parlaklık değişimine kısmen değişmezdir (ekrandan, 00:35:00).
  - Türev ve Gauss pencere fonksiyonu kayma değişmezdir. Nesne yer değiştirince aynı noktalar bulunur (öteleme eşdeğişkenliği).
  - Dönmede özdeğerler aynı kalır, yalnız elips döner. Köşe konumu dönmeye göre eşdeğişkendir (covariant).
  - Ölçeklemede eşdeğişken değildir. Uzaktan köşe görünen yapı yakından çekilince kenar gibi sınıflanır. Harris ölçek bilgisi vermez.
- Anahtar nokta eşleştirmenin beş adımı (ekrandan, 00:40:00)
  - Ayırt edici anahtar noktaları bul, her noktanın çevresinde bir bölge tanımla, bölge içeriğini çıkar ve normalize et, normalize bölgeden yerel tanımlayıcı hesapla, tanımlayıcıları eşleştir: $d(f_A,f_B)<T$.
- Ölçek seçimi ve Difference of Gaussian (DoG)
  - Amaç, iki imgede karşılık gelen bölgeleri doğru ölçekte bulmaktır. Bunun için öyle bir "imza fonksiyonu" aranır ki farklı ölçeklerde hesaplandığında maksimumu iki imgede de karşılık gelen ölçekte olsun.
  - DoG, iki Gauss filtresinin farkıdır; "Meksika şapkası" biçimindedir ve bir blob (leke) bulucudur (ekrandan, 00:45:00). Küçük DoG küçük bölgelere, büyük DoG büyük bölgelere cevap verir.
  - Ölçeğe şimdilik Gauss filtresinin varyansı (ya da standart sapması) olarak bakılabilir.
- DoG'nin verimli hesaplanması: Gauss ölçek piramidi (ekrandan, 00:50:00)
  - İmge art arda Gauss ile filtrelenir; her filtrelemede ölçek $\sigma$ çarpanıyla artar (slaytta $\sigma=2^{1/4}$). Ardışık katmanlar çıkarılarak DoG katmanları elde edilir.
  - İmge yeterince bulanıklaşınca satır ve sütunların biri alınıp biri atılır (adım $\sigma^4=2$), boyut yarıya iner. Her yarıya indirmede elde edilen imge topluluğuna oktav denir.
  - Hoca bu yapıyı dalgacık (wavelet) dönüşümündeki gittikçe küçülen imgelere benzetti.
- Konum-ölçek uzayında yerel maksimum
  - DoG cevabının maksimumu yalnız $x,y$'de değil ölçek ekseninde de aranır. Sonuç bir $(x,y,s)$ listesidir (ekrandan, 01:00:00).
  - Konum ve ölçek enterpolasyonla piksel altı duyarlıkta (ör. 3.8 gibi) bulunur. Küçük oktavlarda bir piksel orijinal imgede daha büyük bir alana karşılık gelir.
  - Bazı yazarlar ölçeği $\sigma$ yerine varyansla ($t=\sigma^2$) ifade eder; okunan makalenin hangi gösterimi kullandığına dikkat etmek gerekir.
- Yönelim normalizasyonu (ekrandan, 01:05:00)
  - Bölgedeki gradyan yönlerinin histogramı çıkarılır, baskın yönelim seçilir, bölge sabit bir yönelime döndürülür. Hoca derste yön aralığını 8 parçaya bölerek anlattı.
  - Bölge Harris noktasının çevresinden ya da doğrudan DoG maksimumlarından alınabilir.
- SIFT ve DoG bölgeleri
  - David Lowe'un SIFT çalışması hem DoG temelli bir bölge bulucu hem de bir özellik çıkarıcı içerir; ikisine birden SIFT denildiği için karışıklık olur. Bu yolla bulunan bölgelere DoG bölgeleri de denir.
- MSER ve watershed
  - Watershed: imge parlaklığı üç boyutlu bir yüzey gibi düşünülür, su döküldükçe vadiler dolar; sulu ve susuz bölgeler ayrılarak imge bölütlenir.
  - MSER (Matas): su seviyesi değiştikçe uzun süre sabit kalan (kararlı) bölgeleri seçer. Bölgeler elips ya da daire olmak zorunda değildir.
- Bulucuların karşılaştırması (ekrandan, 01:10:00)
  - Aynı imgede Harris, Hessian, LoG (Laplacian of Gaussian) ve MSER farklı nokta ve bölgeler verir. Hoca, derin öğrenmeden önce şekil tanımada en önemli yaklaşımın bu olduğunu söyledi.
- İmge gösterimi: şablonlar ve histogramlar
  - Şablon (template): imgenin parlaklık değerleri ya da türevleri doğrudan kullanılır.
  - Histogram: bir fonksiyon değerinin bölgede kaç kez görüldüğünü verir. Global histogram nesne bulmak için uygun değildir, yerel histogram (ör. yalnız gagadan) faydalıdır (ekrandan, 01:15:00).
  - Histogram eleman sayısına bölünerek toplamı 1 olan bir olasılık dağılımına dönüşür. Marjinal histogram yalnız satır ya da sütun boyunca, ortak (joint) histogram ızgara hücrelerinde sayar.
  - Renk, doku (filtre dizileri, Gabor filtreleri) ve gradyan yönelimi histogramları alınabilir.
- SIFT tanımlayıcısı (ekrandan, 01:20:00 ve 01:25:00)
  - Gradyanlar bulunur, Gauss ağırlığı uygulanır (merkeze yakın gradyanlar daha önemli), bölge $4\times4=16$ hücreye bölünür, her hücrede 8 yönlü yönelim histogramı çıkarılır: $16\times8=128$ değer.
  - Histogram kullanmak küçük yerleşim farklarına karşı tanımlayıcıyı aşırı hassas olmaktan kurtarır; uzamsal bilgi kabaca korunur.
  - Enterpolasyon: bir gradyan 8 kutuya katkıda bulunur, uzayda 4 çarpı yönelimde 2 (ekrandan, 01:25:00).
  - Vektör normalize edilir, 0.2'den büyük değerler 0.2'ye kırpılır (yüksek gradyanların aşırı etkisini önlemek için), sonra yeniden normalize edilir.
- Diğer tanımlayıcılar
  - SURF: SIFT fikrinin hızlı yaklaşığı; 2B kutu filtreleri ve integral imgelerle SIFT'ten 6 kat hızlı, nesne tanımada eşdeğer kalite (ekrandan, 01:30:00).
  - Shape Context: açılar 30 derecelik dilimlere, yarıçap logaritmik artan halkalara bölünür (log-polar kutulama). Yakın noktalarda daha kesin, uzak noktalarda daha esnek davranır.
  - Öz-benzerlik tanımlayıcısı (Shechtman ve Irani, 2007): renk, doku, kenar ortak olmasa da yerel öz-benzerliklerin geometrik yerleşimi ortak olabilir (ekrandan, 01:35:00). Küçük yamanın çevresiyle korelasyon yüzeyi çıkarılır, üzerine log-polar tanımlayıcı uygulanır.
  - İdeal tanımlayıcı sağlam (robust), ayırt edici, kompakt ve verimli olmalıdır. Çoğu tanımlayıcı kenar/gradyan bilgisine dayanır, renk nadiren kullanılır (ekrandan, 01:40:00).
- Yerel özelliklerin eşleştirilmesi (ekrandan, 01:45:00)
  - En yakın komşu (Öklid uzaklığı) kullanılabilir, ama imgelerde tekrarlayan benzer yapılar yanlış eşleşmelere yol açar.
  - En yakın komşu uzaklık oranı (NNDR): en yakın uzaklık ikinci en yakın uzaklığa bölünür. Oran 1'e yaklaştıkça yanlış eşleşmeler artar; Lowe'un grafiğinde doğru eşleşmelerin dağılımı 0.4-0.5 civarında tepe yapar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Elips ekseninde üs $-1/2$ olmalıdır
  - Büyük özdeğer hızlı değişim demektir; bu yönde elips kısa olmalıdır. $+1/2$ alınırsa elipsler 90 derece ters görünür.
- Elipsin yönü özvektörlerden gelir
  - Özdeğerler yalnız boyu verir. Açıyı özvektörlerden hesaplamayan çözümler tam doğru değildir.
- Harris ölçeğe eşdeğişken değildir
  - Dönme ve ötelemeye karşı iyi davranır, parlaklığa kısmen değişmezdir; ama ölçek bilgisi vermez. Ölçek için DoG gibi yöntemler gerekir.
- SIFT adı iki şeyi birden kapsar
  - DoG temelli bölge bulucu ve 128 boyutlu tanımlayıcı aynı makalede verildi; ikisini karıştırmamak gerekir.
- Makaledeki gösterimi doğru okuyun
  - Ölçek bazen $\sigma$, bazen varyans ($t=\sigma^2$) ile verilir.
- Araştırma alışkanlığı
  - Hoca derste yön gösterdiğini, ayrıntıları (SURF, elips çizimi gibi) öğrencinin kendisinin araştırması gerektiğini söyledi.

## Kısa Tekrar Notları

- $M=\sum w\,\nabla I\nabla I^T$; özdeğerler: $\lambda_{max}$ hızlı değişim, $\lambda_{min}$ yavaş değişim.
- Elips yarı eksenleri $(\lambda_{max})^{-1/2}$ ve $(\lambda_{min})^{-1/2}$; yön $R$'den (özvektörler).
- Harris: $I\to I+b$ değişmez, $I\to aI$ kısmen; öteleme ve dönmede eşdeğişken; ölçekte değil.
- Eşleştirme adımları: nokta bul, bölge tanımla, normalize et, tanımlayıcı hesapla, eşleştir.
- DoG = iki Gauss'un farkı = blob bulucu; ölçek piramidi, oktav = yarıya indirilmiş imge grubu.
- Maksimum $(x,y,s)$ uzayında aranır; enterpolasyonla piksel altı konum ve ölçek.
- Yönelim normalizasyonu: yön histogramı, baskın yön, sabit yöne döndürme.
- SIFT tanımlayıcısı: $4\times4$ hücre $\times$ 8 yön $=128$; Gauss ağırlığı; enterpolasyon (8 kutu); normalize, 0.2 kırp, yeniden normalize.
- SURF: kutu filtresi + integral imge, SIFT'ten 6 kat hızlı.
- Shape Context: log-polar kutular, 30 derece açılar.
- MSER: su seviyesine göre kararlı bölgeler; serbest biçimli.
- Eşleştirme: en yakın komşu yerine en yakın / ikinci en yakın uzaklık oranı daha güvenilir.

## Detaylı Açıklamalar

- **Harris ödevinin NumPy ile kurulması.** İkinci moment matrisini her piksel için ayrı ayrı döngüyle hesaplamak yerine, gradyan vektörünü dört boyutlu bir diziye koyup `np.matmul` ile toplu çarpmak mümkündür. $(1,2,256,256)$ boyutlu dizi önce $(256,256,2,1)$ biçimine (her piksel için bir sütun vektörü), sonra devriği $(256,256,1,2)$ biçimine getirilir. `matmul` son iki ekseni matris olarak çarptığı için sonuç her piksel için $2\times2$ bir matristir. Hoca dört boyutlu eksen düzenini zihinde canlandırmanın zor olduğunu söyledi ve alternatif olarak $I_x^2$, $I_xI_y$, $I_y^2$ imgelerini ayrı tutmayı önerdi. Özdeğerler `np.linalg.eigvals` ile bulunabilir, ama köşe cevabı için özdeğer hesaplamak gerekmez; determinant ve iz yeterlidir (ekrandan, 00:40:00, önceki dersin özet slaytı). <!-- BELİRSİZ: köşe cevabındaki sabit altyazıda "Alfayı 0.4 aldım" diye geçiyor (00:24:08); Harris'te bu sabit genelde 0.04-0.06 arasındadır, değer büyük olasılıkla 0.04'tür, kare yok. -->
- **Elips neden ters çıktı?** İkinci moment matrisinin köşegenleştirilmesinde $\lambda_{max}$ en hızlı parlaklık değişiminin yönüne karşılık gelir. Elips, $[u\;v]M[u\;v]^T=1$ eğrisi olarak düşünülürse büyük özdeğerin yönünde yarı eksen $\lambda_{max}^{-1/2}$, yani kısadır. Ödevde $\lambda^{+1/2}$ kullanıldığı için uzun eksen hızlı değişim yönüne düştü ve elipsler olması gerekenden 90 derece dönük göründü. Elipsin açısı ise özvektörlerden hesaplanmalıdır.
- **Ölçek sorunu ve DoG.** Harris köşesi bir piksel konumu verir ama "ne büyüklükte bir bölge" sorusuna cevap vermez. Aynı sahne yakından ve uzaktan çekildiğinde karşılık gelen bölgeyi bulmak için ölçek de belirlenmelidir. Fikir, ölçek arttıkça değeri önce artan sonra azalan bir fonksiyon bulmak ve maksimumun olduğu ölçeği bölgenin ölçeği saymaktır. DoG bu iş için kullanılır: küçük bir DoG küçük lekeye, büyük bir DoG büyük lekeye en güçlü cevabı verir (ekrandan, 00:45:00). Üç boyutlu çizildiğinde Gauss'a benzer ama kenarlarda sıfırın altına iner.
- **Gauss piramidi ve oktavlar.** İmge art arda Gauss ile filtrelenince her yeni katmanın toplam varyansı büyür. Örneğin orijinal imge ve dört filtreleme ile beş katman, ardışık farklarla dört DoG katmanı oluşur. Görüntü bulanıklaştıkça tüm pikselleri tutmak gereksizdir; bu yüzden imge her oktav sonunda yarıya indirilir. Slayttaki değerlerle $\sigma=2^{1/4}$ ve dört adım sonra $\sigma^4=2$ olur; ölçek iki katına çıktığında imge iki kat seyreltilir (ekrandan, 00:50:00; $(2^{1/4})^4=2$ python ile doğrulandı).
- **Yönelim ve tanımlayıcı.** Bölge bulunduktan sonra yönelim normalize edilir: bölgedeki gradyan yönlerinin histogramından baskın yön seçilir ve bölge bu yöne göre döndürülür. Ardından SIFT tanımlayıcısı çıkarılır: bölge $4\times4$ hücreye bölünür, her hücrede 8 yönlü histogram alınır ve 128 boyutlu vektör oluşur. Gauss ağırlığı merkeze yakın pikselleri öne çıkarır. Histogram kullanmanın amacı uzamsal bilgiyi korurken bir pikselik kaymalara karşı aşırı hassasiyeti ortadan kaldırmaktır. Son adımda vektör normalize edilir, 0.2'den büyük bileşenler 0.2'ye indirilir ve vektör yeniden normalize edilir.
- **Eşleştirme.** İki imgeden çıkarılan tanımlayıcılar Öklid uzaklığıyla karşılaştırılır. Tekrarlayan yapılar yüzünden en yakın komşu tek başına yanıltıcı olabilir; bu nedenle en yakın uzaklığın ikinci en yakına oranı kullanılır. Oran küçükse eşleşme ayırt edicidir, 1'e yakınsa belirsizdir. Lowe'un grafiğinde oran 0.8'in üstüne çıkınca yanlış eşleşmelerin olasılık yoğunluğu hızla artar (ekrandan, 01:45:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
