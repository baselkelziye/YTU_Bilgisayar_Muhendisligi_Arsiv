# Ders 8 Çalışma Özeti

## Genel Konular

- Biyomedikal veride makine öğrenmesinin amacı
  - Doktorun tecrübeyle öğrendiği ayırt etme becerisini makineye öğretmek amaçlanır. Makine öğrenmesi, örüntü tanıma (pattern recognition) ve veri madenciliği birbirine yakın alanlardır; hepsinin üst çatısı veri bilimidir (istatistik ve matematiksel modelleme de buna dahildir).
  - Hedef, doktora yardımcı bilgisayar destekli teşhis (CAD) ve karar destek sistemleri (Decision Support System, DSS) kurmaktır.
- Biyomedikal veri tipleri
  - Bir boyutlu işaretler: EKG gibi. Sinyal 256 örneklik çerçevelere (QRS kompleksleri) bölünür; veri setinde normal ve taşikardi gibi 6-9 sınıf olabilir.
  - İki boyutlu görüntüler: ultrason, MR, bilgisayarlı tomografi, mikroskop görüntüleri sayısallaştırılır. Gri seviyeli ya da renkli olabilir.
  - Üç boyutlu (hacimsel) veri: MR'da kesitler (slice) üst üste konarak X, Y, Z'de bir veri küpü oluşur.
- Veri matrisi ve etiket vektörü
  - Her örnek (sample) bir satırdır, her öznitelik (feature) bir sütundur. Veri matrisi $X \in \mathbb{R}^{N\times d}$ (N örnek sayısı, d öznitelik sayısı), tek örnek $x \in \mathbb{R}^{d}$ öznitelik vektörüdür, etiketler $y \in \mathbb{R}^{N}$ vektöründedir (ekrandan, 01:20:00).
  - Ham veriyle çalışmada 256 uzunluklu EKG çerçevesinin genlik değerleri doğrudan öznitelik olur.
  - Piksel sınıflamada her pikselin R, G, B değeri 3 öznitelik, etiketi ise hücre (1) ya da arka plan (0) olur (ekrandan, 00:45:00).
- Patoloji görüntüsünde örnek akış
  - Hastadan doku alınır, lamele konur, hücre çekirdeğini ve arka planı farklı renge boyayan boyalarla boyanır (boyama bir ön işlemedir).
  - Yüksek çözünürlüklü tarayıcıda tam slayt (whole slide) görüntüsü elde edilir (ör. 10.000 x 10.000 piksel). Uzman ilgi bölgelerini (patch, Region of Interest) seçer ve normal (0), ara (1), hastalıklı (2) gibi etiketler verir (ekrandan, 01:05:00).
  - Problem sınıflandırma (patch hangi sınıfta) ya da bölütleme (hücreyi arka plandan ayır) olabilir.
- Eğiticili ve eğiticisiz öğrenme
  - Etiket bilgisini kullanan algoritmalar eğiticili (supervised, güdümlü), kullanmayanlar eğiticisizdir (unsupervised). Yarı eğiticili (semi-supervised) ve topluluk öğrenmesi (ensemble learning) ara stratejilerdir.
- Ön işleme ve son işleme
  - Ön işleme (preprocessing): gürültü giderme, filtreleme (ör. medyan filtre), normalizasyon, aykırı değer temizliği.
  - Son işleme (post-processing): bölütleme sonucundaki hücre içi boşlukları doldurma, kenarları düzeltme.
- Öznitelik uzayı ve karar sınırları
  - Her öznitelik vektörü d boyutlu uzayda bir noktadır. Öznitelikler birbirinden bağımsız varsayıldığı için eksenler dik çizilir.
  - Sınıfları ayıran eğriler karar sınırıdır; 3 boyutta karar yüzeyine, daha yüksek boyutta hiperdüzleme (hyperplane) dönüşür. d boyutlu uzayda ayırıcı $d-1$ boyutludur.
  - Hatalar karar sınırlarının yakınında yoğunlaşır. Gerçek veride sınıflar iç içe geçebilir (ekrandan, 01:30:00).
- Örüntü tanıma sisteminin bileşenleri (Polikar, Şekil 4; ekrandan, 01:40:00)
  - Gerçek dünya problemi, veri toplama (data acquisition), ön işleme, öznitelik çıkarımı (feature extraction), öznitelik seçimi (feature selection), model seçimi ve eğitim, değerlendirme (evaluation).
- Öznitelik çıkarımı, seçimi ve boyut azaltma
  - Öznitelik çıkarımı iki yolla yapılır: zaman uzayında ölçümler (süre, eğim, oranlar) ve matematiksel dönüşümler (Fourier, dalgacık, PCA vb.).
  - Öznitelik seçimi, d öznitelikten çok daha az sayıdaki en ayırt edici öznitelikleri seçer. Boyut azaltma hem çıkarım hem seçimle yapılabilir.
  - Boyut laneti (curse of dimensionality) ve Ockham'ın usturası.
- PCA ve LDA
  - PCA etiketsizdir: verinin kovaryans matrisinin özdeğer ve özvektörlerini bulur; en büyük özdeğere ait özvektör en büyük varyans yönü (PC1) olur.
  - LDA etiketlidir: sınıflar arası dağılımın sınıf içi dağılıma oranını en büyük yapan izdüşüm yönünü bulur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Basit görünen karar, makine için zordur
  - Bir çocuk bile hücre sınırlarını kolayca çizer; ama insan yalnız RGB değerine değil çevre piksellerin dağılımına, şekle ve bağlama da bakar. Bunu bilgisayara kurallı komutlarla anlatmak ayrı bir iştir.
- Başarı iki şeye bağlıdır
  - Toplanan örneklerin kalitesi ve ayrıştırılabilirliği; modelin karar sınırlarını iyi çizmesi. Verinin temsil gücü (representativeness) en önemli kavramdır.
- Geleneksel makine öğrenmesinde model başarısı öznitelik çıkarımına çok bağlıdır
  - Geleneksel akış: ön işleme, öznitelik çıkarımı, model. Derin öğrenmede ön işlemeden sonra öznitelik çıkarımı ve model birleşir; evrişimsel ağ öznitelikleri kendi çıkarır (ekrandan, 01:50:00).
- Bilgisayar mühendisinin avantajı frekans uzayıdır
  - İnsan gözü frekans uzayına geçemez; biz Fourier, dalgacık, PCA gibi dönüşümlerle farklı uzaylarda öznitelik çıkarabiliriz.
- Öznitelik çıkarımı sık sık boyut azaltmayla karıştırılır
  - Dönüşümle elde edilen öznitelikler boyutu koruyabilir ya da azaltabilir; boyut azaltma ise çıkarımla da seçimle de yapılabilir.

## Kısa Tekrar Notları

- $X \in \mathbb{R}^{N\times d}$: satırlar örnek, sütunlar öznitelik; $x \in \mathbb{R}^d$ öznitelik vektörü; $y$ etiket vektörü ($N\times 1$).
- Eğitim: train.X ve train.y modele verilir; test.X için tahmin $\hat{y}$ çıkar, gerçek $y$ ile karşılaştırılarak yüzde başarı bulunur.
- Eğiticili: etiket kullanır. Eğiticisiz: etiket kullanmaz.
- Ön işleme: gürültü, filtre, normalizasyon, aykırı değer. Son işleme: boşluk doldurma, kenar düzeltme.
- Z-normalizasyonu: $x_i' = (x_i-\mu_i)/\sigma_i$ (sıfır ortalama, birim varyans). Genliğe göre normalizasyon: $[-1,1]$ aralığı.
- Yüksek boyutta aykırı değer için Mahalanobis uzaklığı kullanılabilir.
- Öklid uzaklığı $\sqrt{\sum_{i=1}^{d}(x_i-y_i)^2}$: d büyüdükçe hesap yükü artar.
- 2 boyutta karar eğrisi, 3 boyutta karar yüzeyi, yüksek boyutta hiperdüzlem.
- 256 örneklik gerçel işaretin FFT'si simetriktir; yarısı (128 katsayı) öznitelik olarak yeterlidir.
- Boyut laneti: öznitelik sayısı arttıkça zaman ve bellek gereksinimi artar.
- Ockham'ın usturası: "Varlıklar gereksiz yere çoğaltılmamalıdır."
- PCA: etiketsiz, kovaryans matrisi, özdeğer/özvektör, en büyük varyans yönü.
- LDA: etiketli, sınıf içi dağılım en küçük, sınıflar arası uzaklık en büyük.
- Diğer çıkarım yöntemleri: ICA, dalgacık ve FFT tabanlı yöntemler, eğricikler (curvelet).

## Detaylı Açıklamalar

- **Veri setinin kurulması.** EKG örneğinde kayıt 256 örneklik parçalara bölünür ve her parça bir satır olarak alt alta yazılır. Herhangi bir öznitelik çıkarılmadığında genlik değerlerinin kendisi özniteliktir; böylece $N\times 256$ boyutlu bir matris ve her satırın hastalık tipini tutan bir etiket vektörü elde edilir. Görüntüde aynı mantık piksel düzeyinde kurulur: hücre içinden seçilen piksellerin R, G, B değerleri 1 etiketiyle, arka plandan seçilenler 0 etiketiyle eğitim matrisine yazılır. Daha iyi ayrım için yalnız merkez pikselin rengi değil çevre piksellerin değerleri de eklenerek öznitelik vektörü büyütülebilir; örneğin mor hücre içinde tek bir pembe piksel, çevresine bakılarak hücre içi sayılabilir.

- **Patoloji akışında problem tanımı.** Tam slayt görüntüsü çok büyük olduğundan tamamıyla eğitim yapılamaz; veri seti uzmanın seçtiği patch'lerden oluşur. Bu patch'ler doğrudan bir derin öğrenme modeliyle sınıflanabilir. Problem "hücreleri bul" olarak değişirse bölütlemeye dönüşür. Hücre sınırları her zaman net değildir: bazı hücre bölgeleri arka plan rengiyle aynıdır, bazıları soluk çıkar. Bu yüzden ön işleme (ör. kenarları koruyarak yumuşatan medyan filtre) ve son işleme (boşluk doldurma, kenar düzeltme) adımları kullanılır.

- **Karar sınırları ve hata.** İki öznitelikli bir uzayda dört sınıf (normal ve üç hastalık tipi) farklı bölgelerde toplanır. Etiketi bilinmeyen yeni örnek hangi sınırın içine düşerse o sınıfa atanır. Örnek karar sınırına yakın düştüğünde hata olasılığı artar. Bu nedenle başarı, eğitim verisinin dağılımı iyi temsil etmesine ve modelin sınırları iyi çizmesine bağlıdır. Gerçekte sensör kaynaklı ya da birbirine çok benzeyen öznitelikler yüzünden sınıflar iç içe geçebilir; doktorlar arasında da ara ve kararsız durumlar oluşur.

- **Örüntü tanıma bileşenleri.** Veri toplamada örnekleme oranı, nicemleme ve bit derinliği, prob tipi ve ne kadar veri toplanacağı belirlenir. Ön işlemede kayıt uygun segmentlere bölünür, 50 Hz şebeke gürültüsü ve sensör kaynaklı istenmeyen bileşenler filtrelenir, veri normalize edilir ve aykırı atımlar temizlenir. Öznitelik çıkarımında uzmanın neye baktığı (derinlik, genişlik, süre gibi zaman uzayı ölçümleri) ve matematiksel dönüşümlerle elde edilen frekans içerikleri kullanılır. Öznitelik seçimi, özellikle DNA ve biyoenformatik verilerinde olduğu gibi çok büyük boyutlu verilerde gereklidir. Değerlendirmede modelin doğruluğu, yeniden eğitilmesi ya da daha fazla veri gerekip gerekmediği ve özniteliklerin yeterli olup olmadığı sorgulanır.

- **PCA ve LDA'nın farkı.** PCA sınıf bilgisi kullanmadan verinin en çok değiştiği yönleri sıralar: kovaryans matrisinin özvektörleri yeni koordinat eksenlerini, özdeğerler ise bu eksenlerdeki değişim miktarını verir. LDA ise sınıf bilgisini kullanır; iyi bir karar yüzeyi için sınıfların kompakt olması (sınıf içi dağılım küçük) ve birbirinden uzak olması (sınıflar arası uzaklık büyük) istenir. LDA bu iki dağılımın oranını en büyük yapan izdüşümü arar. Polikar'ın şeklinde kötü seçilmiş bir izdüşüm yönünde iki sınıfın izdüşümleri üst üste binerken LDA'nın seçtiği yönde ayrışır (ekrandan, 02:00:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
