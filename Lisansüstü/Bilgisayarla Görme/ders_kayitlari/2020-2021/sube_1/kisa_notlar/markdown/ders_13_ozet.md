# Ders 13 Çalışma Özeti

## Genel Konular

- Bu ders öğrenci proje sunumlarından oluşur. Her sunumda bilgisayarla görme ya da ilgili bir yöntem anlatılmış, hoca sorularla anlatımı derinleştirmiştir.
- Çember için Hough dönüşümü
  - Doğru için Hough dönüşümünde eğim-kesim parametrelemesi dik doğrularda sonsuz eğim verir. Bu yüzden doğru $r = x\cos\theta + y\sin\theta$ biçiminde $(r,\theta)$ ile temsil edilir.
  - Çember, merkezi $(a,b)$ ve yarıçapı $r$ ile tanımlanır: $(x_1-a)^2 + (x_2-b)^2 = r^2$ (ekrandan, 00:10:00). Pratikte parametrik biçim $x = a + r\cos\theta$, $y = b + r\sin\theta$ kullanılır; $\cos\theta$ ve $\sin\theta$ değerleri önceden tabloya alınarak hız kazanılır.
  - Parametre uzayı üç boyutludur $(a,b,r)$. Doğruya göre en büyük dezavantaj budur: biriktirici (accumulator) iki değil üç boyutludur.
  - Önce kenar bulucu (Sobel, Canny, morfolojik işlemler ya da frekans uzayında yüksek geçiren süzgeç) uygulanır. Sunumda Canny'nin Sobel'den daha temiz kenar verdiği gözlenmiştir.
  - Sabit bir $r$ için her kenar noktasının çevresine $r$ yarıçaplı çember çizilir ve biriktiricide oylar toplanır. Oyların yoğunlaştığı, eşiği geçen nokta çemberin merkezidir. İşlem aranan yarıçap aralığı boyunca tekrarlanır.
  - Örnek: iç içe geçmiş, yarıçapları 20 ve 25 olan iki çemberde $r=20$ aramasında yalnız ilk çemberin merkezinde, $r=25$ aramasında yalnız ikincisinin merkezinde parlak nokta oluşur (ekrandan, 00:15:00).
  - Eşik düşükse kesik çemberler de bulunur ama yanlış çemberler artar; eşik yüksekse tam olmayan çemberler kaçırılır. Yarıçap aralığı genişledikçe süre uzar. Küçük yarıçaplarda (sunumdaki gözleme göre yaklaşık 15 pikselin altında) hata artar.
  - Kullanım alanları: iris/retina tespiti (biyometri), astronomide yıldız ve gezegen tespiti, rakam ve harf tanıma, uzaktan algılamada insan yapımı yapılar. Parametre sayısı arttıkça (4'ün üstü) yöntem çok yavaşlar.
- pSp (pixel2style2pixel) çerçevesi: StyleGAN ile görüntüden görüntüye çeviri
  - Önceden eğitilmiş bir StyleGAN üreticisi sabit tutulur. Kodlayıcı (encoder), girdi görüntüsünü doğrudan genişletilmiş gizli uzay $\mathcal{W}+$'ya, yani $18 \times 512$ boyutlu stil vektörlerine eşler.
  - Kodlayıcı ResNet tabanlı bir özellik piramidi kullanır. Her `map2style` bloğu adımlı evrişimlerle $8\times8\times512$ öznitelik haritasını $1\times1\times512$ vektöre indirir (ekrandan, 00:40:00). Çıktı $1024 \times 1024$ boyutundadır.
  - Kimlik benzerliği kaybı (identity loss) kullanılır. Uygulamalar: StyleGAN tersine çevirme, yan profili önden görünüme çevirme, segmentasyon haritasından yüz üretme, süper çözünürlük, yüz interpolasyonu.
- GAN ile hızlı ve keyfi stil aktarımı (adversarial training for fast arbitrary style transfer)
  - Stil aktarımında içerik görüntüsünün içeriği korunurken doku ve karakteristik stil görüntüsüne benzetilir. Tarihsel gelişme: optimizasyon tabanlı yöntemler (yavaş, hiperparametreye duyarlı), ileri beslemeli ağlar (hızlı ama tek stil), koşullu GAN'lar (çok stil).
  - Üretici kodlayıcı-kod çözücüdür (U-Net benzeri); kodlayıcı ImageNet üzerinde önceden eğitilmiş VGG16'dır. Ayırt edici koşullu bir patch discriminator'dır; gerçek/sahte kaybının yanında stil gömmesini (embedding) de öğrenir.
  - AdaIN: $\mathcal{A}(x,y) = \sigma_{nc}(y)\left(\frac{x_{nchw}-\mu_{nc}(x)}{\sigma_{nc}(x)}\right) + \mu_{nc}(y)$ (ekrandan, 01:05:00). İçerik özniteliklerini standartlaştırıp stilin ortalama ve standart sapmasına taşır.
  - Maske modülü stilizasyon düzeyini denetler: $z_1 = \mathcal{M}(x,y_1)\,x + (1-\mathcal{M}(x,y_1))\,\mathcal{A}(x,y_1)$. İki stil $z = \beta z_1 + (1-\beta) z_2$ ile karıştırılır; $\beta$ skaler ya da bölgesel olabilir. Yumuşak maske, önemli küçük bölgelerde mod çöküşünü (mode collapse) azaltır.
  - Üretici kaybı: $\min_G \mathcal{L}_G = \mathcal{L}_{GA} + \lambda_{GS}\mathcal{L}_{GS} + \lambda_c\mathcal{L}_c + \lambda_s\mathcal{L}_s$. İçerik kaybı yalnız 4. kodlayıcı bloğunun çıktısıyla, stil kaybı dört bloğun Gram matrisleriyle hesaplanır (ekrandan, 01:10:00).
- İnsansız hava aracı görüntülerinde gerçek zamanlı anlamsal bölütleme
  - Anlamsal bölütlemede (semantic segmentation) nesne kutusu yerine her piksele bir sınıf atanır. Otonom sürüşte yaygındır.
  - Veri seti: yaklaşık 400 adet 4K görüntü, 8 sınıf (yapı, yol, durağan araç, hareketli araç, düşük bitki örtüsü, ağaç, insan, arka plan). Ek olarak dron görüntüleri etiketleme araçlarıyla (CVAT, LabelMe) elle etiketlenmiştir; 4K bir görüntünün etiketlenmesi 5-6 saat sürebilir. Parlaklık değişimi ve çevirme ile veri artırma yapılmıştır.
  - Modeller: EfficientNet kodlayıcılı U-Net, U-Net ve PSPNet. U-Net simetrik kodlayıcı-kod çözücüdür: her seviyede iki $3\times3$ evrişim ve $2\times2$ max pooling, kod çözücüde yukarı evrişim ve atlama bağlantılarıyla birleştirme (ekrandan, 02:00:00). PSPNet piramit havuzlama modülüyle farklı ölçeklerdeki bağlamı birleştirir.
  - Başarım ölçütü kesişim/birleşim (intersection over union, IoU). U-Net için eğitim/doğrulama/test doğruluğu %80,55 / %84,12 / %84,93 (ekrandan, 02:05:00). PSPNet ile yaklaşık 16 FPS elde edilmiştir.
- Dijital patolojide genellenebilir bir derin öğrenme uygulaması için stil aktarımı
  - Büyük, açık bir yumurtalık kanseri veri setinde Inception V3 sınıflandırıcısı transfer öğrenme ile eğitilir. CycleGAN ile yerel bir veri setinin görüntüleri bu veri setinin stiline aktarılır; böylece renk ve boyama farklılıklarından kaynaklanan genelleme sorunu azaltılır.
  - Inception V3: Inception modülleri ($1\times1$, $3\times3$ evrişimler, büyük süzgeçlerin $1\times n$ ve $n\times1$ çarpanlarına ayrılması), batch normalizasyon, yardımcı sınıflandırıcı; girdi $299\times299\times3$, çıktı 2048 boyutlu (ekrandan, 02:15:00).
  - Eğitim: öğrenme oranı $2\times10^{-5}$, ikili çapraz entropi kaybı, RMSprop.
  - Görüntüden görüntüye çeviri ve CycleGAN: iki üretici ($G: X\to Y$, $F: Y\to X$) ve iki ayırt edici; eşleşmemiş (unpaired) veriyle döngü tutarlılığı kaybı kullanılır (ekrandan, 02:25:00).
  - Değerlendirme: $\text{Precision} = \frac{TP}{TP+FP}$, $\text{Recall} = \frac{TP}{TP+FN}$, $F_1 = \frac{2\,\text{Prec}\,\text{Rec}}{\text{Prec}+\text{Rec}}$; AUROC ve AUPRC (ekrandan, 02:30:00). Macenko ve Vahadane renk normalizasyonlarına göre CycleGAN tabanlı stil aktarımı daha iyi sonuç vermiştir.
- Gürbüz en küçük kareler (robust least squares)
  - Doğrusal regresyonda en küçük kareler çözümü $p = (A^T A)^{-1} A^T y$'dir; $A$, $x$ değerlerinin yanına birlerden oluşan sütun eklenerek kurulur, $p = [m, b]^T$. Tek bir aykırı nokta doğruyu kendine doğru çeker.
  - Winsorized LS: artıklar sıralanır, baştan ve sondan $g = kn$ tanesi ($0 < g < n/2$) kendisine en yakın değerle değiştirilir, sonra LS yeniden uygulanır (ekrandan, 02:55:00).
  - Trimmed LS: aynı uçlardaki örnekler değiştirilmez, veri setinden silinir.
  - Ağırlıklı LS: $\hat\beta_{WLS} = (X^T W X)^{-1} X^T W Y$, $W$ köşegen ağırlık matrisidir; büyük hatalı noktaya küçük ağırlık verilir (ekrandan, 03:00:00).
  - M-kestirimi: $\hat\beta_M = \arg\min_\beta \sum_i \rho\left(\frac{\epsilon_i(\beta)}{\hat\tau}\right)$, $\hat\tau = \frac{\mathrm{med}_i|r_i - \tilde r|}{0.6745}$, $\tilde r$ artıkların medyanı; böylece ölçekten bağımsız olur (ekrandan, 03:10:00). Ağırlık fonksiyonları: Andrews sinüs ($c \approx 1.339$), Huber ($c \approx 1.345$), Tukey biweight.
- Stereo görmeye dayalı anlamsal 3B nesne ve ego-hareket izleme (otonom sürüş)
  - 3B kutular doğrudan 3B regresyonla değil, kolay etiketlenen 2B algılama ve bakış açısı sınıflandırmasından çıkarılır. Sistem üç modüldür: 2B nesne algılama ve bakış açısı sınıflandırma, özellik çıkarma ve eşleştirme, tüm ölçümleri birleştiren optimizasyon (bundle adjustment).
  - SLAM (simultaneous localization and mapping): bilinmeyen bir ortamda robotun aynı anda kendi konumunu bulması ve ortamın haritasını çıkarması. Anlamsal SLAM buna tanımayı ekler.
  - Faster R-CNN, R-CNN'e göre görüntü başına süreyi 49 s'den 0,2 s'ye indirdiği için seçilmiştir (ekrandan, 03:25:00).
  - Nesneler için ORB öznitelikleri çıkarılır, stereo eşleştirme epipolar hat üzerinde yapılır, aykırı eşleşmeler RANSAC ile ayıklanır (ekrandan, 03:30:00).
  - Araç modelinde dingil mesafesi sabit alındığı için sistem yalnız binek araçlarını izler; otobüs, kamyon gibi araçları etiketlemez.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hough çember dönüşümünde parametre uzayının nasıl ızgaraya bölündüğü
  - Hoca, $(x-a)^2+(y-b)^2=r^2$ formülünde parametrelerin sınırının ne olduğunu ve uzayın ızgaralara bölünüp bölünmediğini sordu. Cevap: $a,b$ görüntü koordinatlarıyla orantılı bir ızgarada tutulur, her $r$ için bir katman oluşur ve üç boyutlu bir yoğunluk matrisi elde edilir.
- Olasılık gösterimine dikkat
  - Hoca stil aktarımı sunumundaki $\mathcal{L}_{GS} = \mathbb{E}[\log(s\,|\,D(\hat x))]$ gösteriminde dikey çizginin koşullu olasılık anlamına gelip gelmediğini sordu; ayırt edicinin öğrendiği stil gömmesine uzaklık ölçüldüğü açıklandı.
- Winsorized LS'de neyin değiştirildiği
  - Hoca, değiştirilen değerlerin artıklar (gerçek $y$ eksi model tahmini) olduğunu ve en büyük ile en küçük değerlerin kendine en yakın komşusuyla değiştirildiğini netleştirdi.
- 0.6745 sabiti
  - Hoca bu sayının nereden geldiğini sordu. Sunumda formülün kaynağa göre böyle olduğu söylendi (açıklama için Örnek Sorular bölümüne bakın).
- Aykırı değer için başka yollar
  - Hoca aykırı değerleri bulup atmak gibi başka yöntemlerin de uygulanabileceğini belirtti; bu, trimmed LS'nin mantığıdır.
- SLAM ve 2B'den 3B elde etme
  - Hoca SLAM'in robotikte çok kullanıldığını ve konumu bulmanın aslında kameranın konumunu bulmak demek olduğunu vurguladı.
  - İki boyutlu görüntülerden üç boyutlu yapı elde etmenin önemli ve zor, ağır matematiğe dayanan bir problem olduğunu, bu konunun ayrıntılı anlatımının iki haftalık ders gerektirdiğini söyledi.

## Kısa Tekrar Notları

- Doğru için Hough: $r = x\cos\theta + y\sin\theta$. Çember için Hough: $(a,b,r)$ üç boyutlu parametre uzayı.
- Hough çember adımları: kenar bulma (Canny), her $r$ için kenar noktalarının çevresine çember çizip oy toplama, eşikleme, merkez ve yarıçapı görüntüye geri aktarma.
- pSp: kodlayıcı görüntüyü $\mathcal{W}+$ uzayına ($18\times512$) eşler, sabit StyleGAN üreticisi görüntüyü üretir.
- AdaIN: içerik özniteliğini standartlaştır, stilin $\sigma$'sıyla çarp, $\mu$'süyle topla.
- Maske modülü: stilizasyon miktarını denetler, iki stil $\beta$ ile karıştırılır, mod çöküşünü azaltır.
- Stil kaybı Gram matrisiyle, içerik kaybı kodlayıcı ara katman çıktısıyla hesaplanır.
- Anlamsal bölütleme: piksel düzeyinde sınıflandırma; ölçüt IoU; mimariler U-Net, PSPNet, EfficientNet kodlayıcı.
- CycleGAN: eşleşmemiş veriyle iki üretici, iki ayırt edici ve döngü tutarlılığı kaybı.
- Precision $= TP/(TP+FP)$, Recall $= TP/(TP+FN)$, $F_1$ ikisinin harmonik ortalaması.
- Gürbüz LS: winsorized (uçları komşuyla değiştir), trimmed (uçları sil), ağırlıklı ($W$ köşegen), M-kestirimi ($\rho$ ve ölçek $\hat\tau$).
- SLAM: eş zamanlı konum belirleme ve haritalama. ORB = FAST anahtar noktası + BRIEF tanımlayıcı; RANSAC ile aykırı eşleşme ayıklama.

## Detaylı Açıklamalar

- **Hough çember dönüşümünün işleyişi.** Doğru için kullanılan oylama fikri çembere de uygulanır. Kenar noktası çevresine sabit $r$ yarıçaplı çember çizildiğinde, gerçek bir çembere ait bütün kenar noktalarının çizdiği çemberler o çemberin merkezinde kesişir. Biriktiricide bu noktada yoğunluk birikir; eşiği geçen yoğunluk merkez olarak kabul edilir. Yarıçap bilinmiyorsa aralık taranır ve her yarıçap biriktiricinin bir katmanı olur; bu yüzden $(a,b,r)$ uzayı bir koni yüzeyi gibi düşünülebilir (ekrandan, 00:30:00). Aranan nesnenin piksel cinsinden yarıçapı biliniyorsa yalnız o yarıçap aranarak yöntem çok hızlandırılabilir. Sunumda kendi yazılan kodun Python'daki hazır Hough çember fonksiyonuna göre daha yavaş çalıştığı, parmak izi görüntülerinde düşük eşikle dairesel ve kapalı bölgelerin öznitelik olarak kullanılabildiği gösterildi.
- **Stil aktarımında ayırt edici ve kayıplar.** Patch discriminator görüntünün tamamına tek bir gerçek/sahte kararı vermek yerine görüntünün bölgeleri için ayrı kararlar üretir (ekrandan, 01:00:00). Bu çalışmada ayırt edici ayrıca stil gömmesi öğrenir, böylece üreticiye hem "gerçekçi değil" hem "doğru stilde değil" geri bildirimi verir. İçerik kaybı için ayrı bir öznitelik çıkarıcı kullanılmaz; kodlayıcının ara blok çıktıları kullanılır. Gram matrisi bir kovaryans matrisine benzer ve stilin baskın dokusal özelliklerini öne çıkarır; mini-batch eğitimi nedeniyle Gram matrisinin ortalaması alınır.
- **Gürbüz en küçük kareler ve M-kestirimi.** Sıradan en küçük karelerde her artık karesiyle cezalandırıldığı için büyük bir aykırı değer çözümü kendine çeker. Ağırlıklı LS'de büyük artıklı noktalara küçük ağırlık verilir. M-kestiriminde önce artıklar $\hat\tau$ ile ölçeklenir ($z = \epsilon/\hat\tau$), sonra seçilen ağırlık fonksiyonu (Andrews, Huber, Tukey) her nokta için ağırlık üretir ve bu ağırlıklar köşegen $W$ matrisine yazılarak ağırlıklı LS formülü uygulanır. Sunumda kendi veri setinde sıradan LS doğrusu tek aykırı noktaya doğru yatarken ağırlıklı yöntemlerin doğruyu veri yığınına geri getirdiği, en iyi sonucu Tukey biweight'in verdiği gösterildi (ekrandan, 03:15:00).
- **Stereo 3B nesne izleme.** Önce sol görüntüde 2B nesne kutusu ve bakış açısı sınıfı (8 yatay × 2 dikey = 16 sınıf) bulunur. 2B kutunun nesneye sıkıca oturduğu varsayılır; her kenar, yeniden izdüşürülen bir 3B köşeyle kesişir. Bu ilişkiler her 2B kutu için dört seçim matrisiyle ifade edilir (ekrandan, 03:35:00). Sonra ORB öznitelikleri stereo ve zamansal olarak eşleştirilir; kamera pozu ve nesne pozları birlikte optimize edilir. Hoca, özellik çıkarma ve eşleştirmenin klasik yöntemlerle (ORB, epipolar geometri, RANSAC) yapıldığına dikkat çekti; sunumda eğitilmiş bileşenler için hazır veri setlerinin (KITTI, Cityscapes) kullanıldığı söylendi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
