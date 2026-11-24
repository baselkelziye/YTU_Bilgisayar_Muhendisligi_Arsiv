# Ders 12 Çalışma Özeti

## Genel Konular

- Dersin biçimi: öğrenci makale sunumları
  - Bu derste altı öğrenci, CVPR ve benzeri konferanslarda yayımlanmış birer bilgisayarla görme makalesini yaklaşık 20 dakikalık sunumlarla anlattı. Her sunumun ardından hoca ve öğrenciler soru sordu.
  - Konular: ince ayrıntılı insan eylemi tanıma için yeni bir veri seti, çok kameralı MEVA etkinlik tespiti veri seti, üretken model ters çevirme saldırısı (GMI), metin tanımada öğrenilebilir veri artırma, statik kameralar için Bağlam R-CNN (Context R-CNN) ve ortak belirgin nesne tespiti (CoSOD).
- İnce ayrıntılı (subtle) insan eylemi tanıma
  - Action (eylem) insanın tek başına yaptığı harekettir (el sallamak, koşmak). Activity (aktivite) bir nesneyle ya da başka insanlarla etkileşim içeren eylemdir. Literatürde bu iki terim net ayrılmadan kullanılır. İnsan pozu kestirimi (human pose estimation) ikisinin de temelidir.
  - UCF-101 gibi mevcut veri setlerinde eylem çoğu zaman arka plandan ya da sahnedeki bir nesneden (gitar, bowling lobutu, gökyüzü) tahmin edilebilir (ekrandan, 00:20:00). Makalenin amacı nesne ve duruş aynı kalırken eylemin yapılıp yapılmadığını ayırt etmektir: kitap elde ama okunmuyor, bardak elde ama içilmiyor, oturmaya yakın ama oturulmuyor.
  - Veri setinde yanlılık (bias) ve alan kayması (domain shift): eğitim ve test görüntüleri farklı dağılımlardan gelirse (yaz/kış kıyafeti, MNIST'te eğitilip başka el yazısı setinde test) başarı düşer. Çözüm önerileri: ince ayar (fine-tuning), normalleştirme, veri artırma, sözde etiketleme (pseudo-labeling), alan uyarlaması (domain adaptation).
  - Anahtar noktalar (keypoints): kullanılan veri setinde 17 vücut noktası vardır (burun, gözler, kulaklar, omuzlar, dirsekler, bilekler, kalçalar, dizler, ayak bilekleri) (ekrandan, 00:25:00). Yüz, el, ayak için ayrı özel anahtar noktalar tanımlanabilir.
  - Araçlar: Detectron (Facebook'un açık kaynak nesne tespiti kütüphanesi; RPN, Mask R-CNN, Fast R-CNN; ResNet, FPN, VGG-16 omurgaları), Amazon Mechanical Turk (ücretli katılımcılarla etiketleme ve insan testi), ImageNet ve COCO veri setleri.
  - Veri seti üç ikili alt kümeden oluşur: içme, okuma, oturma (her biri evet/hayır). Bir görüntü, üç etiketleyicinin tamamı aynı etiketi verirse alınmıştır (ekrandan, 00:30:00). Ardından AlexNet gibi modellerin kolayca doğru sınıfladığı görüntüler yinelemeli olarak atılmış ve modellerin başarısı şans düzeyine (%50) indirilmiştir.
  - Psikofizik değerlendirme: görüntü katılımcılara 50, 150, 400 ve 800 ms gösterilmiş, sonra katılımcı süresiz yanıt vermiştir. İnsanlar 50 ms'de bile şans düzeyinin çok üstündedir; içme için yaklaşık %72'den 800 ms'de yaklaşık %90'a çıkar (ekrandan, 00:35:00).
  - Mevcut CNN'ler (son katmanı iki sınıflı yapılarak ince ayarlanmış) ve önerilen modeller (Detectron ile anahtar nokta ve nesne öznitelikleri + SVM/YSA) insan başarısının çok altında kalmıştır (ekrandan, 00:40:00).
- MEVA veri seti (çok görüşlü, çok kipli etkinlik tespiti)
  - 9300 saatten fazla yer kamerası videosu, 42 saat İHA videosu, üç milyondan fazla GPS iz noktası; senaryolu ve senaryosuz etkinlikler; görüş açısı ve sensör çeşitliliği (ekrandan, 00:45:00).
  - Karşılaştırma tablosuna göre MEVA'da 37 etkinlik türü, 28 görüş alanı (FOV), 5 sensör kipi, en yüksek çözünürlük 1920x1080, 5 dakikalık klipler vardır; görüş alanları örtüşür, iç ve dış mekân birliktedir (ekrandan, 00:50:00).
  - Kameralar: sabit, sabit konumlu ama yakınlaşıp uzaklaşabilen (PTZ) ve devriye (patrol) gibi dönen kameralar; güvenlik kamerası, kızılötesi, giyilebilir aksiyon kamerası, İHA.
  - Senaryo: her kişiye ayrı senaryo vermek yapay davranış doğurdu. Bunun yerine her grubun başına senaryoyu izleyen bir oyuncu kondu, gruptaki diğer kişiler doğal davrandı (ekrandan, 00:55:00).
  - Etiketleme çok adımlıdır: etkinliklerin zaman sınırlarının işaretlenmesi, uzman denetimi, kitle kaynaklı sınırlayıcı kutu izleri, köşe durumları (corner cases) için uzman arayüzü (ekrandan, 01:00:00). Zorluklar kameralar arası iz takibi, tutarlılık ve ölçek değişimidir.
- Üretken model ters çevirme saldırısı (Generative Model Inversion, GMI)
  - Model ters çevirme saldırısı, eğitilmiş bir hedef modelden ve varsa yardımcı bilgiden (bulanık ya da maskelenmiş görüntü) yararlanarak eğitim verisinin hassas özelliklerini geri elde etmeyi amaçlar (ekrandan, 01:20:00).
  - İlk örnek: kişiye özel ilaç dozu veren doğrusal regresyon modelinden hastanın genetik belirteçlerinin tahmin edilmesi. Diferansiyel gizlilik ve mahremiyet bütçesi saldırıyı önlerken klinik etkinliği düşürmüştür.
  - Derin ağlarda klasik ters çevirme yerel minimuma takılır, yüksek boyutta anlamsız görüntü üretir. GMI, açık veriyle eğitilmiş bir GAN'ın üreteç uzayında arama yapar.
  - GAN: üreteç (generator) gerçeğe benzeyen veri üretir, ayırt edici (discriminator) gerçeği sahteden ayırır. Kayıplar (ekrandan, 01:30:00): $\min_G \max_D L_{wgan}(G,D) = E_x[D(x)] - E_z[D(G(z))]$; çeşitlilik kaybı $\max_G L_{div}(G) = E_{z_1,z_2}\left[\frac{\lVert F(G(z_1)) - F(G(z_2))\rVert}{\lVert z_1 - z_2\rVert}\right]$; saldırı hedefi $\hat{z} = \arg\min_z L_{prior}(z) + \lambda_i L_{id}(z)$, $L_{prior}(z) = -D(G(z))$, $L_{id}(z) = -\log C(G(z))$.
  - Sonuçlar: GMI, klasik ters çevirme (EMI) ve görüntü içi boyama (PII) yöntemlerinden açıkça daha başarılıdır. Örneğin VGG16'da merkez maskeli görüntüde saldırı doğruluğu EMI %14, PII %34, GMI %78'dir (ekrandan, 01:35:00).
- Metin tanımada öğrenilebilir veri artırma (Learn to Augment)
  - Sahne metni (synthetic/scene text) ve el yazısı metin; düzenli (regular) ve düzensiz (irregular, kavisli, farklı boyutlu harfli) metin.
  - Görüntü $N$ parçaya bölünür, kontrol noktaları $R$ yarıçapı içinde rastgele kaydırılarak metin bükülür (ekranda $N = 3$, $R = 10$) (ekrandan, 01:50:00). Bükme, germe (stretch) ve perspektif dönüşümleri kullanılır.
  - Bir ajan ağı, tanıyıcının kaybını artıran daha zor artırmaları öğrenir; tanıyıcı ve ajan birlikte eğitilir.
  - Düzensiz metin kelime doğruluğu: temel model (ASTER) SVT-P 77.7, CT80 79.9, IC15 75.8; önerilen yöntemle 79.2, 84.4, 76.1 (ekrandan, 01:45:00). El yazısında WER (kelime hata oranı) ve CER (karakter hata oranı) düşmüştür.
- Bağlam R-CNN (Context R-CNN)
  - Statik izleme kameraları (kamera tuzakları, trafik kameraları): düzensiz örnekleme, çok sayıda boş kare, ortalanmamış ve kötü aydınlatılmış nesneler, tekrar eden sahneler ve arka plana aşırı uyum zorlukları vardır.
  - Fikir: aynı kameranın günler, haftalar önceki karelerinden gelen bağlam, tek karede görülemeyen nesneyi (sisli karedeki antilop) ortaya çıkarır (ekrandan, 02:00:00).
  - Mimari: Faster R-CNN'in birinci aşaması (RPN) ile ikinci aşaması arasına kısa süreli ($M^{short}$) ve uzun süreli ($M^{long}$) bellekten beslenen iki dikkat modülü eklenir (ekrandan, 02:05:00). Uzun süreli bellek COCO ile eğitilmiş bir dedektörün öznitelikleriyle kurulur, 8500'e kadar öznitelik ve yaklaşık bir aylık bağlam tutar.
  - Dikkat: sorgu ile anahtarın iç çarpımı, softmax, değerlerin ağırlıklı toplamı. Çıkış $F^{context}$ boyutu kutu sayısı $\times$ 2048'dir.
  - Snapshot Serengeti sonuçları (mAP / AR): tek çerçeve 37.9 / 46.5, ST+LT dikkat 55.9 / 58.3 (ekrandan, 02:15:00).
- Ortak belirgin nesne tespiti (Co-Salient Object Detection, CoSOD)
  - Belirgin nesne tespitinin (SOD) alt dalıdır: bir grup görüntüde ortak olan belirgin nesneyi bulup bölütler (ekrandan, 02:25:00).
  - CoSOD3k veri seti: 160 grup, 3316 görüntü, 13 üst sınıf; hem sınırlayıcı kutu hem nesne/örnek düzeyinde piksel maskeleri (ekrandan, 02:30:00).
  - Derin öğrenme tabanlı modeller geleneksel yaklaşımlardan daha iyidir; uç (kenar) özellikleri iyi sınırlar elde etmeye yardım eder (ekrandan, 02:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- İkili sınıflandırmada şans düzeyi
  - İki seçenekli bir problemde rastgele tahmin (yazı tura) zaten %50 başarı verir. Grafikte %50'nin altında kalan yöntemler çok kötüdür; bir yöntemin en az bu düzeyi geçmesi beklenir.
- Alan uzmanı (domain expert)
  - Disiplinler arası bir çalışmada bir alan uzmanına ihtiyaç duyulabilir; makalenin biyoloji ve sinir bilimi kökenli yazarı bunun örneği olabilir.
- Etiketlemenin maliyeti
  - Büyük video veri setlerini etiketlemek çok uzun saatler ve ciddi emek ister. Büyük veri setleri büyük ekipler ve finansal kaynaklarla hazırlanır.
- Problemi tanımlamak
  - Beğenilen çalışmaların ortak yanı, yazarların yeni bir problemi kendilerinin ortaya koyması ve ardından çözümünü önermesidir (Bağlam R-CNN, CoSOD, öğrenilebilir veri artırma).

## Kısa Tekrar Notları

- Action tek kişinin hareketi, activity nesne ya da insanlarla etkileşimdir.
- İnce eylem veri setinde amaç nesne ve duruş aynıyken eylemin gerçekten yapılıp yapılmadığını ayırmaktır; modellerin başarısı bilerek şans düzeyine indirilmiştir.
- İnsanlar 50 ms gösterimde bile şans düzeyinin üstündedir; CNN'ler insan düzeyine ulaşamamıştır.
- MEVA: 9300+ saat, 37 etkinlik, 28 görüş alanı, 5 sensör kipi; grup başına tek oyunculu senaryo.
- GMI: GAN önbilgisi + kimlik kaybı ile hedef modelden yüz görüntüsü geri kazanır; EMI ve PII'den çok daha başarılıdır.
- Learn to Augment: $N$ parça, $R$ yarıçaplı kontrol noktası kaydırma; ajan zor artırmaları öğrenir.
- Bağlam R-CNN: Faster R-CNN'in iki aşaması arasına kısa ve uzun süreli bellekli dikkat; Snapshot Serengeti'de mAP 37.9'dan 55.9'a.
- CoSOD: grup görüntülerinde ortak belirgin nesne; CoSOD3k: 160 grup, 3316 görüntü, 13 üst sınıf.
- IoU (intersection over union): tahmin kutusu ile gerçek kutunun örtüşme oranı; bu çalışmada eşik 0.5.

## Detaylı Açıklamalar

- **İnce eylem tanıma veri setinin kurulması:** Görüntülerin bir kısmı internetten toplanmış, bir kısmı kontrollü olarak çekilmiştir. Her görüntü için üç katılımcı süresiz olarak etiket vermiş, yalnız üçünün de aynı etiketi verdiği görüntüler alınmıştır. Sonra veri seti %80 eğitim, %20 test olarak ayrılıp ince ayarlanmış AlexNet ile sınıflandırılmış; en kolay sınıflanan görüntüler (her turda yaklaşık en başarılı %10'luk dilim) atılmış ve bu işlem modelin başarısı şans düzeyine (%50) inene kadar birkaç tur tekrarlanmıştır. Böylece arka plan ya da nesne ipucuyla çözülemeyen zor bir veri seti elde edilmiştir. Bir görüntünün "içiyor" sayılması için bardağın ağızda olması, "okuyor" sayılması için kitabın elde olması ve bakışın kitaba yönelmesi gerekir. <!-- BELİRSİZ: Yinelemeli eleme turlarının sayısı ve yüzdeleri altyazıda karışık anlatıldı. -->
- **Önerilen model:** İki kol vardır. Birinci kol insanın anahtar noktalarını (kulak, göz gibi birkaç nokta), ikinci kol ilgili nesneye (örneğin kitap) ait sınırlayıcı kutuyu ve o kutudaki öznitelikleri Detectron/Mask R-CNN ile çıkarır. Bu öznitelikler SVM ve yapay sinir ağı ile sınıflandırılmıştır. Ekrandaki grafiğe göre okuma ve oturmada anahtar nokta + öznitelik birleşimi bazı mimarilere göre iyileşme sağlasa da hiçbir model insan düzeyine ulaşamamıştır (ekrandan, 00:40:00). Isı haritalarıyla görselleştirme, modellerin çoğu zaman doğru bölgeye odaklandığını ama yine de yanlış karar verdiğini göstermiştir.
- **MEVA'nın etiketleme süreci:** Videolar beşer dakikalık parçalara bölünür, önce etkinliklerin zaman sınırları ve ilgili nesneler işaretlenir, sonra uzmanlar etiketlerin eksiksiz ve doğru olup olmadığını denetler, ardından kitle kaynaklı yöntemle nesneler için sınırlayıcı kutu izleri oluşturulur. Ekrandaki örneklerde aynı kişi farklı kameralarda 301, 118, 176 ve 89 piksel boyunda görünür (ekrandan, 01:00:00); bu ölçek farkı ve kameralar arası iz takibi etiketlemenin en zor yanıdır. Araçtan inen bir kişinin daha inmeden işaretlenmesi gibi ayrıntılar da etiketlenmiştir. Veri setinin yer kamerası kısmı herkese açılmış, İHA kısmı açılmamıştır.
- **GAN kayıplarının sezgisi:** Ayırt edici gerçek görüntüye 1, sahteye 0 vermelidir. Gerçek bir görüntüye 0.7 verirse hata $1 - 0.7 = 0.3$, sahte bir görüntüye 0.7 verirse hata $0.7 - 0 = 0.7$ olur. Üreteç ise ürettiği görüntüye 1 verilmesini ister; ayırt edici 0.6 verdiyse üretecin hatası $1 - 0.6 = 0.4$'tür (ara adım eklendi). Her yinelemede bu hatalar sıfıra yaklaştırılır.
- **GMI'nin iki aşaması:** Birinci aşamada açık veriyle (hedef kişileri içermeyen yüz görüntüleri) bir GAN, GAN kaybı ve çeşitlilik kaybıyla eğitilir; bu GAN "bir yüz nasıl görünür" önbilgisini sağlar (ekrandan, 01:25:00). İkinci aşamada üreteç ve ayırt edici sabit tutulur, yalnız gizli vektör $z$ güncellenir: $L_{prior}$ gerçekçi olmayan görüntüyü engeller, $L_{id}$ üretilen görüntünün hedef ağda hedef sınıfa yüksek olasılıkla atanmasını sağlar. Hassas özelliğin tahmin gücü $U_f(x_{ns}, y) = E_{X_s \sim p(X_s|y,x_{ns})}[\log p_f(y|X_s, x_{ns}) - \log p_f(y|x_{ns})]$ ile ölçülür (ekrandan, 01:30:00). Veri setleri MNIST, ChestX-ray8 ve CelebA'dır; metrikler PSNR, saldırı doğruluğu, öznitelik uzaklığı ve KNN uzaklığıdır.
- **Learn to Augment'ın çalışması:** Rastgele bir artırma uygulanır, artırılmış görüntü tanıyıcıya verilir ve kayıp kaydedilir. Ajan, kaybı artıran (tanıyıcı için daha zor) kontrol noktası hareket dağılımlarını öğrenir ve bunları üretir; tanıyıcı bu zor örneklerle eğitilerek daha sağlam hale gelir. Parça sayısı $N$ parametriktir, uzun metinlerde artırılabilir. <!-- BELİRSİZ: Sunumda ajan ağının yapısı "RNN" diye anlatıldı ve sentetik veri setlerinde başarının 63'ten 66.5'e çıktığı söylendi; bu tablonun karesi yok. -->
- **Bağlam R-CNN'de dikkat:** Ana karedeki RPN kutularının öznitelikleri sorgu (query) olur. Bellekteki öznitelikler anahtar (key) ve değer (value) olarak kullanılır. Sorgu ile anahtarların iç çarpımı alınır, softmax ile olasılığa çevrilir ve bu ağırlıklarla değerler toplanarak $F^{context}$ bulunur. Ekrandaki örnekte sisli karedeki nesne, bağlam karelerine 0.03-0.04 civarı ağırlıklar verilerek "antilop, skor 0.942" diye tespit edilmiştir (ekrandan, 02:10:00). Bellek modülleri birbirinden bağımsız kullanılabilir. Tabloda yalnız tek çerçeveye dikkat eklemek bile mAP'yi 37.9'dan 44.9'a çıkarır; yalnız uzun süreli bellek 55.6, ikisi birlikte 55.9 verir (ekrandan, 02:15:00).
- **CoSOD3k'nın kurulması:** Görüntüler ILSVRC kategorilerinden ve Flickr'dan toplanmış, 160 kategori orta düzey sınıflar üzerinden 13 üst sınıfa (araç, top, alet, meyve, hayvan vb.) bağlanmıştır (ekrandan, 02:30:00). Ortalama grup başına yaklaşık 21 görüntü düşer, ancak grup büyüklükleri dengesizdir. Değerlendirmede SOD metriklerinin CoSOD için yetersiz olduğu, çünkü görüntüler arası ilişkiyi hesaba katmadığı vurgulanmıştır. Olası kullanım alanları tıbbi görüntülerde ortak yapıların bulunması ve kısmen örtülmüş nesnelerin bölütlenmesidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
