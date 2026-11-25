# Ders 9 Çalışma Özeti

## Genel Konular

- Seminer sunumu 1: Öneri sistemleri (recommender systems)
  - İnternetteki veri çok fazla olduğu için ihtiyaç duyulan bilgiye erişim sorunu ortaya çıkmıştır. Arama motorları bir dereceye kadar yardımcı olsa da kişiye özel ihtiyacı karşılayamaz; bu yüzden öneri sistemleri ön plana çıkar (ekrandan, 00:20:00).
  - Öneri sistemleri, kullanıcının çaba göstermesine gerek kalmadan ihtiyaç duyabileceği ürünü ya da içeriği doğrudan önerir ve kullanıcının daha önce bilmediği şeyleri keşfetmesini sağlar. Video, müzik ve alışveriş platformlarında yaygın olarak kullanılır.
  - Temelde üç kategori vardır: içerik tabanlı filtreleme, işbirlikçi (collaborative) filtreleme ve hibrit filtreleme.
- İçerik tabanlı filtreleme
  - Kullanıcı ve öğe özellikleri kullanılarak, makine öğrenmesi yöntemleriyle öneri yapılır.
  - Dezavantajları: kullanıcı hakkında yeterli bilgi yoksa öneri zorlaşır, özellik vektörünü oluşturmak zordur ve sistem hep benzer özelliklerden öğrendiği için aşırı uzmanlaşma (over-specialization) sorunu doğar.
- İşbirlikçi filtreleme
  - Kullanıcıların geçmişteki değerlendirmelerinden (puanlarından) birbirlerine benzerlikleri bulunur ve kullanıcının hangi öğeye yüksek puan vereceği tahmin edilir.
  - Bellek tabanlı (kullanıcı tabanlı ve öğe tabanlı), model tabanlı ve hibrit olmak üzere ayrılır.
  - Kullanıcı tabanlı yöntemde önerilecek kullanıcıya benzeyen kullanıcılar bulunur, öğenin özelliklerine bakılmaz. Benzerlik, iki kullanıcının puan vektörleri arasında kosinüs benzerliği ya da Pearson korelasyon katsayısı ile hesaplanır (ekrandan, 00:25:00).
  - Öğe tabanlı yöntemde öğeler arası benzerlik kullanılır. Örneğin milyonlarca kullanıcısı ama on binlerce filmi olan bir platformda öğeler arası benzerlik hesaplamak daha ucuzdur.
  - Model tabanlı yöntemde bütün veri yerine veriden öğrenilen bir model üzerinden tahmin yapılır; tekil değer ayrışımı (SVD), boyut indirgeme ve kümeleme ile veri küçültülür, performans artar.
  - Avantaj: içerik tabanlıya göre genelde daha iyi öneri; bellek tabanlı yöntemler basit ve artımlı olarak güncellenebilir. Dezavantaj: soğuk başlangıç ve büyük veride hesaplama maliyeti.
- Hibrit filtreleme
  - İçerik tabanlı ve işbirlikçi yöntemlerin güçlü yönlerini birleştirir; genelde yöntemler ayrı ayrı uygulanıp çıktıları birleştirilir. Dezavantajı karmaşık ve pahalı olmasıdır.
- Öneri sistemlerinin sorunları (ekrandan, 00:30:00)
  - Soğuk başlangıç (yeni kullanıcı ya da yeni öğe için değerlendirme yoktur), ölçeklenebilirlik, seyreklik (kıtlık, sparsity), gizlilik, aşırı uzmanlık, öngörülebilirlik, kullanıcı tercihlerinin zamanla değişmesi ve eşanlamlılık.
  - Seyreklik: kullanıcıların çoğu öğeleri puanlamadığı için kullanıcı-öğe matrisi büyük ölçüde boş kalır; öneri zorlaşır ve hesaplama artar.
  - Gizlilik: yaş, cinsiyet, konum gibi kişisel bilgiler öneriyi iyileştirir ama mahremiyet sorunu doğurur.
  - Eşanlamlılık: özellikle e-ticarette isim benzerliğine dayalı gruplama alakasız ürünlerin önerilmesine yol açabilir.
- Literatürden örnek çalışmalar
  - Soğuk başlangıca karşı kullanıcıdan açık (anket, ilgi alanı sorma) ve örtük (sosyal medya hesabı, kayıt sırasında girilen yan bilgiler) bilgi toplama; hibrit yaklaşımın daha doğru sonuç verdiği sonucu (2017).
  - Bağlamsal bilgilerin (konum, cinsiyet vb.) k-ortalamalar ile kümelenip işbirlikçi filtrelemede kullanılması (2020).
  - İşbirlikçi filtrelemenin korelasyon faktörleriyle birleştirilmesiyle daha az veriyle daha doğru öneri (2020).
  - Öneri başarısını ölçme: puan tahmini doğruluğu ve kullanım tahmini doğruluğu ölçütleri (2017).
- Seminer sunumu 2: Görüntü manipülasyonu ve manipülasyon tespit yöntemleri
  - Fotoğraf üzerinde yapılan her türlü değişiklik, küçük ya da büyük olması fark etmeksizin manipülasyondur; dijital ortamdakine "fotoşop" denir (ekrandan, 00:45:00).
  - Tarihçe: ilk fotoğraf (Niépce, Le Gras'taki pencereden görünüm), 1860'larda ilk manipülasyon örnekleri, "hayalet fotoğraf"lar, siyasi hiciv amaçlı fotomontajlar, günümüzde deepfake ve sosyal medya örnekleri (ekrandan, 00:50:00).
  - Manipülasyon tipleri: görüntü ekleme (splicing), kopyala-taşı (copy-move; kesme ve silme dahil), rötuş, dönüştürme (morphing, deepfake) ve yeniden renklendirme.
  - Rötuş en zararsız, dönüştürme (deepfake) en tehlikeli tür olarak sınıflandırıldı. Renklendirme, gri tonlamalı görüntüleri RGB ile renklendirmektir ve nesne tanıma algoritmalarını şaşırtmak için kasıtlı da uygulanabilir (ekrandan, 00:55:00).
- Manipülasyon tespit tekniklerinin sınıflandırılması
  - Yönteme göre: aktif yöntemler (filigran, dijital imza ya da kod eklenir) ve pasif yöntemler (görüntüye bir şey eklenmez, istatistiksel analizle tespit edilir).
  - Döneme göre: klasik yöntemler (blok tabanlı, histogram tabanlı, görüntü kalitesi ölçümü) ve güncel yöntemler (yapay sinir ağları, derin öğrenme, transfer öğrenme).
  - Blok tabanlı: görüntü bloklara bölünür (örneğin $4\times4$) ve bloklar karşılaştırılarak kaydırılır; maliyeti görüntü ve blok boyutuyla artar.
  - Histogram tabanlı: renklendirilmiş görüntülerle orijinaller arasında ton, doygunluk, aydınlık ve karanlık kanallarında istatistiksel fark vardır; kanalların histogramları karşılaştırılır.
  - Görüntü kalitesi ölçümü: tam referans, azaltılmış referans ve referanssız değerlendirme; kalite metriğine göre bozulma tespit edilir (ekrandan, 01:00:00).
- Veri kümeleri ve güncel yöntemler
  - Yaygın veri kümeleri: CASIA 1.0, CASIA 2.0, CoMoFoD ve COVERAGE. COVERAGE'da 100 orijinal ve 100 manipüle görüntü vardır; farkı gözle görmek çok zordur (ekrandan, 01:05:00).
  - Güncel yöntemlerin avantajı tek bir manipülasyon tipine değil, genel manipülasyon tespitine yönelebilmeleridir.
  - Tıbbi görüntülerde manipülasyon tespiti çalışmaları genelde aktif yöntemlerle (özellikle filigran) yapılmıştır (ekrandan, 01:10:00).
- Seminer sunumu 3: Çekişmeli üretici ağlar (GAN) ile sentetik görüntü üretme
  - Derin öğrenme çok veri ister; veri seti hazırlamak pahalıdır. Veri çoğullama ve otomatik kodlayıcı (autoencoder, VAE) gibi üretici modellere alternatif olarak GAN önerilmiştir.
  - GAN iki ağdan oluşur: üretici (generator) gürültüden sentetik veri üretir, ayırıcı (discriminator) gerçek ile sahteyi ayırmaya çalışır. İkisi Nash dengesine ulaşana kadar minimax oyunu oynar.
- GAN türleri
  - Vanilla GAN (Goodfellow, 2014): çok katmanlı algılayıcılarla kurulur; amaç fonksiyonu ekrandaki minimax ifadesidir (ekrandan, 01:30:00). Optimumda $D = 1/2$ olur.
  - DCGAN: G ve D evrişimli ağlarla kurulur; havuzlama yerine adımlı evrişim, batch normalizasyon, tam bağlantılı gizli katmanların kaldırılması, G'de ReLU (son katmanda tanh), D'de LeakyReLU (ekrandan, 01:35:00).
  - Conditional GAN: girişe sınıf etiketi gibi bir koşul $y$ hem G'ye hem D'ye verilir; istenen sınıfta görüntü üretilir.
  - AC-GAN: ayırıcı hem gerçek/sahte hem sınıf tahmini yapar; ek bir sınıf kaybı kullanılır. Çeşitlilik için MS-SSIM metriği kullanılmıştır.
  - Residual koşullu GAN (SAR gemi görüntüleri): üretici ResNet blokları ile kurulur; ayırıcı sigmoid (gerçek/sahte) ve softmax (sınıf) çıktısı verir (ekrandan, 01:40:00).
  - InfoGAN: gürültünün bir kısmı yorumlanabilir gizli kod $c$ olur; karşılıklı bilgi $I(c; G(z,c))$ bir alt sınırla yaklaşık hesaplanıp amaç fonksiyonuna eklenir (ekrandan, 01:45:00).
  - Pix2Pix: eşli görüntülerle görüntüden görüntüye çeviri; cGAN kaybına L1 kaybı eklenir (ekrandan, 01:50:00).
  - CycleGAN: eşli veri gerektirmeden döngü tutarlılığı kaybıyla çeviri.
  - Progressive GAN: çözünürlüğü $4\times4$'ten başlayıp katman katman artırır, geçişleri yumuşak yapar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Doktora düzeyinde bir çalışma yalnız uygulamadan ibaret kalmamalı, teorik katkı da içermelidir.
  - Hoca, uygulama ağırlıklı bir öneri sistemi konusunda teorik çalışmaların incelenmesini önerdi; aksi halde konunun sıkışıp kalabileceğini söyledi.
- Bir konuda makale az olsa bile bildirilere ve yarışmalara bakılmalıdır.
  - Deepfake tespiti için hoca, Kaggle'ın düzenlediği yarışmada dereceye giren yöntemlerin alanda yaygın kullanılan yöntemler olduğunu söyledi.
- Bir yöntemin hangi gerçek ihtiyaca hizmet ettiği açıkça söylenebilmelidir.
  - Hoca hem tıbbi görüntülerde manipülasyon tespitinin hem de sentetik kızılötesi görüntü üretiminin amacını sordu.
- Sunumda tabloların neyi gösterdiği yazılmalıdır.
  - Bir katılımcı, aynı slayttaki iki tablonun neyi ölçtüğünün belirtilmediğini sordu.

## Kısa Tekrar Notları

- Öneri sistemi türleri: içerik tabanlı, işbirlikçi (bellek tabanlı: kullanıcı/öğe; model tabanlı), hibrit.
- Kullanıcı ya da öğe benzerliği: kosinüs benzerliği, Pearson korelasyon katsayısı.
- Öneri sistemlerinin 8 sorunu: soğuk başlangıç, ölçeklenebilirlik, seyreklik, gizlilik, aşırı uzmanlık, öngörülebilirlik, tercih değişimi, eşanlamlılık.
- Manipülasyon tipleri: ekleme, kopyala-taşı, rötuş, dönüştürme, renklendirme.
- Tespit: aktif (filigran, imza) ve pasif (istatistiksel); klasik (blok, histogram, kalite ölçümü) ve güncel (derin öğrenme).
- Veri kümeleri: CASIA 1.0/2.0, CoMoFoD, COVERAGE.
- GAN: üretici ve ayırıcı, minimax oyunu, optimumda $D=1/2$.
- DCGAN: evrişim, batch norm, mode collapse'a karşı önlem; cGAN/AC-GAN: koşul ve sınıf kaybı; InfoGAN: karşılıklı bilgi; Pix2Pix: eşli veri + L1; CycleGAN: eşsiz veri + döngü tutarlılığı; Progressive GAN: aşamalı çözünürlük.

## Detaylı Açıklamalar

- **Öneri sistemlerinde benzerlik.** Kullanıcı tabanlı işbirlikçi filtrelemede her kullanıcı, öğelere verdiği puanlardan oluşan bir vektörle temsil edilir. İki kullanıcının benzerliği bu vektörler arasındaki kosinüs benzerliği ya da Pearson korelasyon katsayısıyla hesaplanır. Öğe tabanlı yöntemde aynı hesap öğeler arasında yapılır. Sunumdaki örnekte milyonlarca kullanıcısı olan bir film platformunda, sayıca çok daha az olan filmler arasında benzerlik hesaplamanın daha uygun olduğu anlatıldı.

- **Seyreklik ve ölçeklenebilirlik.** Kullanıcı-öğe matrisinde kullanıcıların çoğu öğelerin çok azını puanlar; matris büyük ölçüde boştur. Bu, benzerlik hesabını hem zorlaştırır hem pahalılaştırır. Model tabanlı yöntemler SVD, boyut indirgeme ve kümeleme ile bu matrisi küçülterek performans kazanır.

> Ders sonrası not: Sunumda içerik tabanlı filtreleme anlatılırken verilen örnek (aynı demografik özelliklere sahip kişilerin tercihlerine göre öneri yapılması), büyük olasılıkla daha çok demografik filtrelemeye ya da kullanıcı benzerliğine dayalı yaklaşıma uyar. İçerik tabanlı filtreleme, büyük olasılıkla öğelerin özellikleri ile kullanıcının daha önce beğendiği öğelerin özelliklerini karşılaştırır.

- **Manipülasyon tespitinde aktif ve pasif yaklaşım.** Aktif yöntemlerde görüntü oluşturulurken içine filigran ya da dijital imza eklenir; sonradan bu işaretin bozulup bozulmadığına bakılır. Pasif yöntemlerde görüntüye bir şey eklenmez; görüntünün istatistikleri (blok benzerlikleri, renk kanalı histogramları, kalite metrikleri) incelenir. Klasik pasif yöntemler çoğunlukla tek bir manipülasyon türüne odaklanır ve araştırmacılar genelde kendi ürettikleri orijinal/manipüle görüntü çiftleriyle çalışmıştır. Derin öğrenme tabanlı güncel yöntemler ise birden çok manipülasyon türünü kapsayan genel bir tespit hedefler.

- **Tıbbi görüntülerde manipülasyon.** Görüntüler bir kurumdan diğerine CD ya da film üzerinde taşındığında üzerinde değişiklik yapılabilir; örneğin bir kırık ya da lezyon eklenerek rapor alınmaya çalışılabilir ya da adli vakalarda delil değiştirilebilir. Görüntülerin merkezi sistemlerde tutulması riski azaltsa da aradaki katmanlarda müdahale olasılığı tamamen ortadan kalkmaz.

- **GAN amaç fonksiyonu** (ekrandan, 01:30:00):

$$\min_G \max_D V(D,G) = \mathbb{E}_{x\sim p_{\text{data}}(x)}[\log D(x)] + \mathbb{E}_{z\sim p_z(z)}[\log(1 - D(G(z)))]$$

  Ayırıcı gerçek veriye 1, üretilmiş veriye 0 demek ister; üretici ise $D(G(z))$'yi büyütmeye çalışır. Eğitim ilerledikçe üretilen dağılım gerçek veri dağılımına oturur ve optimumda ayırıcı her örneğe $1/2$ olasılık verir.

- **DCGAN sonucu** (ekrandan, 01:35:00): MNIST üzerinde en yakın komşu sınıflandırıcısıyla test hatası: GAN 50K örnekte %6,28, 10M örnekte %5,65; DCGAN 50K örnekte %2,98, 10M örnekte %1,48 (gerçek veri 50K örnekte %3,1).

> Ders sonrası not: Sunumda havuzlama yerine "G'de adımlı evrişim, D'de kesirli adımlı evrişim" kullanıldığı söylendi. DCGAN makalesinde büyük olasılıkla tersidir: ayırıcıda adımlı (strided) evrişim, üreticide kesirli adımlı (fractional-strided, transpoze) evrişim kullanılır.

- **InfoGAN** (ekrandan, 01:45:00): Karşılıklı bilgi $I(X;Y) = H(X) - H(X|Y) = H(Y) - H(Y|X)$ olarak tanımlanır. Amaç $\min_G \max_D V_I(D,G) = V(D,G) - \lambda I(c; G(z,c))$'dir. $I(c;G(z,c))$ doğrudan hesaplanamadığı için yardımcı dağılım $Q(c|x)$ ile alt sınır $L_I(G,Q) = \mathbb{E}_{c\sim P(c),\,x\sim G(z,c)}[\log Q(c|x)] + H(c) \le I(c;G(z,c))$ kullanılır ve son amaç $\min_{G,Q}\max_D V_{\text{InfoGAN}}(D,G,Q) = V(D,G) - \lambda L_I(G,Q)$ olur. MNIST'te bir kod rakam sınıfını, biri dönmeyi, biri kalınlığı kontrol eder.

- **Pix2Pix kayıp karşılaştırması** (ekrandan, 01:50:00):

| Kayıp | Piksel doğruluğu | Sınıf doğruluğu | Sınıf IoU |
|---|---|---|---|
| L1 | 0,42 | 0,15 | 0,11 |
| GAN | 0,22 | 0,05 | 0,01 |
| cGAN | 0,57 | 0,22 | 0,16 |
| L1+GAN | 0,64 | 0,20 | 0,15 |
| L1+cGAN | 0,66 | 0,23 | 0,17 |
| Gerçek | 0,80 | 0,26 | 0,21 |

  L1+cGAN en iyi sonucu verir. L2 kaybı daha bulanık çıktı ürettiği için L1 tercih edilmiştir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
