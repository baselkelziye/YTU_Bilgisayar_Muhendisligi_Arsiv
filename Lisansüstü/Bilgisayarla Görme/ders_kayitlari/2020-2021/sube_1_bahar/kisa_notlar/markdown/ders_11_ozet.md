# Ders 11 Çalışma Özeti

## Genel Konular

- Dersin yapısı
  - Bu ders iki öğrenci proje sunumundan oluşur. İki sunum da bilgisayarla görmede çekişmeli üretici ağların (GAN) kullanımına dayanan CVPR 2020 bildirilerini anlatır.
  - Birinci sunum: "A U-Net Based Discriminator for Generative Adversarial Networks" (U-Net GAN).
  - İkinci sunum: "RL-CycleGAN: Reinforcement Learning Aware Simulation-to-Real" (pekiştirmeli öğrenme ile CycleGAN'ın birleşimi).
- Veri artırma ve sentetik veri üretimi
  - Derin öğrenmede model mimarisi kadar veri miktarı da önemlidir. Döndürme, ışıkla oynama gibi basit veri artırma (data augmentation) teknikleri istenen başarı için her zaman yeterli olmaz.
  - GAN'lar (Türkçede "çekişmeli üretici ağlar") gerçekçi sentetik görüntü üreterek veri setlerini zenginleştirir; sınıflandırma, bilgisayarla görme ve robotik işlerinde başarıyı artırır.
- Standart GAN yapısı
  - İki sinir ağından oluşur: üretici (generator, $G$) ve ayırıcı (discriminator, $D$).
  - $G$, bir gürültü vektörü $z$'den (örneğin Gauss ya da düzgün dağılımdan) gerçekçi bir görüntü $G(z)$ üretmeye çalışır.
  - $D$, gerçek veri setinden gelen $x$ ile üretilen $G(z)$'yi ayırt etmeye çalışır. $D$'nin geri bildirimi $G$'nin ağırlıklarını günceller; yani $G$'yi aslında $D$ eğitir.
  - İki kayıp vardır: biri en büyüklenmeye, öteki en küçüklenmeye çalışılır. Bu yarış oyun teorisine dayanır; eğitim, $D$'nin gerçek ile sahteyi ancak 0,5 olasılıkla (rastgele) ayırabildiği noktada dengeye ulaşır.
- U-Net tabanlı ayırıcı (U-Net GAN)
  - Ayırıcı, segmentasyonda kullanılan U-Net mimarisine dönüştürülür: kodlayıcı $D^U_{enc}$ ve kod çözücü $D^U_{dec}$ (ekrandan, 00:25:00).
  - $D^U_{enc}$ görüntünün tamamı için global gerçek/sahte kararı verir. $D^U_{dec}$ piksel bazında (lokal) gerçek/sahte haritası üretir.
  - Kodlayıcı ile kod çözücü arasındaki kısa yollar (skip connection) sayesinde çıktı kanalları hem yüksek hem düşük seviyeli bilgi taşır. Haritadaki açık renkler, pikselin gerçek olarak algılanma oranını gösterir.
  - Amaç, global ve lokal gerçekliği birlikte korumaktır. Lokal değerlendirme zayıf olursa asimetrik yüzler ya da bacağı eksik hayvanlar gibi hatalı görüntüler çıkabilir.
- CutMix ile uyum düzenleme (consistency regularization)
  - Gerçek ve sahte görüntüler bir ikili maske $M$ ile karıştırılır; beyaz bölgeler gerçek, siyah bölgeler sahte kısımdır.
  - Mixup (görüntüleri ve etiketleri interpole eder) ve Cutout (dikdörtgen bir bölgeyi sıfırlar) yerine, ikisinin avantajını birleştiren CutMix seçilmiştir.
  - Karışık görüntüler kodlayıcıya sahte (sınıf 0) olarak verilir; kod çözücüden piksel bazında maskeye uygun çıktı beklenir.
- U-Net GAN deneyleri
  - Veri setleri: CelebA ve FFHQ (insan yüzü; koşulsuz üretim), COCO-Animals (COCO ve OpenImages hayvan sınıflarından derlenmiş, sınıf koşullu üretim; az veri ve dengesiz sınıflar nedeniyle zor).
  - Ölçütler: FID (düşük daha iyi) ve IS (yüksek daha iyi). U-Net GAN, temel aldığı BigGAN'dan her iki veri setinde de daha iyi sonuç vermiştir.
- Pekiştirmeli öğrenme (reinforcement learning, RL) temelleri
  - Ajan (agent) bir eylem (action) alır, yeni bir duruma (state) geçer ve bir ödül (reward) alır. Ödül pozitif, negatif ya da sıfır olabilir. Amaç toplam ödülü en büyüklemektir.
  - Markov karar süreci (MDP): bir sonraki adım yalnız o anki duruma ve eyleme bağlıdır.
  - Keşif ve sömürü (exploration/exploitation): ajan hep aynı yolu izlemesin diye belirli bir $\epsilon$ olasılığıyla rastgele eylem seçer.
  - İndirim faktörü $\gamma$: uzaktaki ödül yakındakiyle aynı değerde sayılmaz (ekrandan, 00:50:00).
  - Q-değeri, bir durumda bir eylemin beklenen getirisidir; politika her durumda Q-değeri en yüksek eylemi seçen plandır.
- Simülasyondan gerçeğe aktarım (sim-to-real) sorunu
  - Gerçek robotla eğitim pahalı ve risklidir; bu yüzden ajan simülasyonda eğitilir. Ancak simülasyon görüntüsü ile gerçek görüntü (ışık, kamera açısı) farklı olduğu için simülasyonda başarılı politika gerçekte başarısız olabilir.
- CycleGAN ve RL-CycleGAN
  - CycleGAN, eşleştirilmemiş (unpaired) iki görüntü kümesi arasında çeviri öğrenir: $G: X\to Y$, $F: Y\to X$ ve iki ayırıcı $D_X$, $D_Y$. Bir görüntü çevrilip geri çevrildiğinde başlangıçtaki görüntüye dönmelidir.
  - RL-CycleGAN, simülasyon görüntüsünü gerçeğe benzeyecek şekilde çevirir ve çeviri sırasında Q-değerlerinin değişmemesini isteyen bir "RL-scene consistency" kaybı ekler. Böylece görevle ilgili nesneler (tutulacak çöpler) çeviride silinmez ya da eklenmez.
  - Robot kolu ile kutulardaki nesneleri tutma (grasping) deneylerinde RL-CycleGAN, yalnız gerçek veriyle eğitime ve GraspGAN'a göre daha yüksek başarı vermiştir (ekrandan, 01:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Değerlendirme ölçütlerinin formülasyonu
  - Hoca, GAN performansını ölçen FID ve IS skorlarının neyi ölçtüğünü ve nasıl hesaplandığını sordu. Bir çalışmayı bir bütün olarak değerlendirebilmek için ölçütlerin ne kontrol ettiğini bilmenin önemli olduğunu vurguladı.
- Görsel sonuçların doğru okunması
  - Hoca, sonuç figürlerinde bir satırdaki görüntülerin aynı sürecin ardışık adımları mı yoksa iki örnek arasındaki geçiş mi olduğunu sordu. Figürün neyi gösterdiğini anlamadan sonuç yorumlanamaz.
- Pekiştirmeli öğrenmenin görmedeki yeri
  - Hoca, pekiştirmeli öğrenmenin yalnız oyunlarda değil, nesne takibi (object tracking) gibi farklı görme problemlerinde de uyarlanarak kullanıldığını belirtti.

## Kısa Tekrar Notları

- GAN = üretici $G$ + ayırıcı $D$; $G$ gürültüden görüntü üretir, $D$ gerçek/sahte ayırır, $D$'nin geri bildirimi $G$'yi eğitir.
- Denge noktasında $D$ gerçek ve sahteyi 0,5 olasılıkla ayırır.
- U-Net GAN: ayırıcı U-Net olur; $D^U_{enc}$ global karar, $D^U_{dec}$ piksel bazlı karar verir.
- CutMix karışımı: $\mathrm{mix}(x,G(z),M)=M\odot x+(1-M)\odot G(z)$.
- Toplam ayırıcı kaybı: $\mathcal{L}_{D^U}=\mathcal{L}_{D^U_{enc}}+\mathcal{L}_{D^U_{dec}}+\lambda\mathcal{L}^{cons}_{D^U_{dec}}$.
- FID düşük, IS yüksek olmalı. FID insan değerlendirmesiyle daha uyumlu kabul edilir.
- RL: durum, eylem, ödül; MDP'de gelecek yalnız şimdiki duruma bağlıdır.
- İndirimli getiri: $R_t=\sum_{k=0}^{T}\gamma^k r_{t+k+1}$, $0\le\gamma\le1$.
- $\epsilon$-açgözlü seçim: $\epsilon$ olasılıkla rastgele eylem, aksi hâlde en yüksek Q-değerli eylem.
- CycleGAN eşleştirilmemiş veriyle çalışır; çevrim tutarlılığı ister.
- RL-CycleGAN: çeviri Q-değerlerini korumalıdır; nesne silme/ekleme sorununu azaltır.
- Görüntüleri $[-1,1]$ aralığına normalize etmek: $x/127{,}5-1$.

## Detaylı Açıklamalar

- U-Net GAN'ın fikri
  - Standart GAN'da ayırıcı, bütün görüntü için tek bir gerçek/sahte kararı verir. U-Net GAN'da ayırıcının kodlayıcı kısmı bu global kararı vermeye devam eder, kod çözücü kısmı ise her piksel için ayrı bir karar üretir. Kod çözücü çıktısı, görüntünün hangi bölgelerinin gerçekçi bulunduğunu gösteren bir harita gibidir. Sunumdaki genel bakış figüründe eğitim ilerledikçe bu haritanın beyazlaştığı, yani görüntünün (örneğin alın bölgesinin) daha gerçekçi hâle geldiği gösterildi.
  - Bu yapıda ayırıcı hem sınıflandırıcı (classifier) hem de segmentasyon ağı (segmenter) gibi çalışır. Böylece üreticiye hem global yapı hem de lokal ayrıntı için geri bildirim gider.
- İlgili çalışmalar (ekrandan, 00:30:00)
  - Ayırıcıyı geliştirmeye yönelik önceki yaklaşımlar: birden fazla $D$ kullanma, farklı çözünürlüklerde $D$ kullanma, $D$'nin uzaysal geri bildirim sağlaması, yeniden yapılanma tabanlı geri bildirimle oto-kodlayıcı mimarisi, ciddi unutmalardan kaçınmak için öz-denetim, PatchGAN ve BigGAN.
  - PatchGAN da lokal (yama bazlı) geri bildirim verir; BigGAN ise bu çalışmada temel alınan standart GAN'dır. U-Net GAN, BigGAN'ın paylaşılan kodu üzerine kurulmuştur.
- Uyum düzenleme formülleri (ekrandan, 00:35:00)
  - $\tilde{x}=\mathrm{mix}(x,G(z),M)$, $\mathrm{mix}(x,G(z),M)=M\odot x+(1-M)\odot G(z)$. Burada $x$ gerçek görüntü, $G(z)$ sahte görüntü, $M$ ikili maske, $\odot$ eleman bazlı çarpımdır.
  - $\mathcal{L}^{cons}_{D^U_{dec}}=\left\|D^U_{dec}(\mathrm{mix}(x,G(z),M))-\mathrm{mix}(D^U_{dec}(x),D^U_{dec}(G(z)),M)\right\|^2$. Yani karışık görüntünün piksel haritası, ayrı ayrı hesaplanan haritaların aynı maskeyle karıştırılmasına eşit olmalıdır.
  - $\mathcal{L}_{D^U}=\mathcal{L}_{D^U_{enc}}+\mathcal{L}_{D^U_{dec}}+\lambda\mathcal{L}^{cons}_{D^U_{dec}}$.
  - Karışık görüntüler eğitime aşamalı olarak, artan bir olasılıkla katılır; böylece önce üreticinin biraz gelişmesi beklenir. <!-- BELİRSİZ: Sunumda olasılığın "0 ile 0,25 arasında doğrusal artan" olduğu söylendi; özgün bildirideki üst sınır karelerden doğrulanamadı. -->
- Koşullu GAN
  - Koşullu GAN'da (cGAN) üreticiye gürültüyle birlikte bir koşul (sınıf ya da görüntü) verilir; aynı koşul ayırıcıya da verilir. Böylece hangi tür görüntünün üretileceği kontrol edilir. COCO-Animals deneyi sınıf koşullu üretimdir.
- Sonuç tablosu (ekrandan, 00:45:00)
  - FID ↓ / IS ↑: PG-GAN 7,30 / –; COCO-GAN 5,74 / –; BigGAN 4,54 / 3,23; U-Net GAN 2,95 / 3,43. <!-- BELİRSİZ: Slaytta bu tablonun hangi veri setine ait olduğu yazmıyor; büyük olasılıkla CelebA. -->
  - Bileşenler BigGAN'a aşama aşama eklendiğinde (önce U-Net ayırıcı, sonra CutMix, en son uyum düzenleme kaybı) başarı her adımda artmıştır. <!-- BELİRSİZ: Bu ablasyon tablosunun sayıları karelerde okunamadı. -->
- Sunumu yapan öğrencinin kendi denemesi
  - FFHQ'dan 3000 görüntü $128\times128$'e küçültülerek koşulsuz GAN 100 epoch, 200'lük gruplarla eğitilmiş ve gürültüden yüze benzeyen dağılımın zamanla oluşması gözlenmiştir. Ayrıca görüntülere Canny, Sobel, Hough ve Harris öznitelikleri eklenerek 1000 görüntüyle daha kısa sürede benzer sonuç alınıp alınamayacağı denenmiştir. <!-- BELİRSİZ: Öznitelik adları altyazıda bozuk ("Keynes, Solbel, Hoppe"); Canny, Sobel ve Hough olduğu bağlamdan çıkarıldı. -->
- Q-öğrenme demosu (ekrandan, 00:55:00)
  - Izgara dünyasında (gridworld) ajan elle yürütülür. İlk geçişlerde ödül yoktur ve Q-değerleri sıfırdır. Ajan +1 ve −1 çıkış karelerine ulaştıkça bu değerler belirir ve ajan aynı yollardan tekrar geçtikçe değerler geriye doğru yayılır. Karede çıkış karesinin değeri 0,88, −1 karesinin değeri −0,50, ona komşu karelerde doğu eylemi için 0,45 ve 0,10 görünür.
- RL-CycleGAN deney sonuçları (ekrandan, 01:10:00)
  - Robot 1 tutma başarısı (bölüm sayısı: yalnız gerçek / GraspGAN / RL-CycleGAN): 5.000: %15 / – / %75; 28.000: %16 / – / %86; 580.000: %87 / %89 / %94.
  - Robot 2, tek kutu ortalanmış kamera (Sim+Gerçek / RL-CycleGAN): 3.000: %13 / %72; 5.000: %12 / %76; 10.000: %10 / %84; 80.000: %36 / %95. Çok kutu, rastgele konum, 80.000: %33 / %93.
  - Görsel karşılaştırmada GAN çevirisi nesne ekleyip silebilmiş, CycleGAN nesne silmiş, GraspGAN görüntü kalitesini bozmuş, RL-CycleGAN ise nesneleri koruyarak en iyi çeviriyi vermiştir.
- CycleGAN uygulaması (ekrandan, 01:15:00)
  - TensorFlow'un CycleGAN öğreticisinde `cycle_gan/maps` veri seti (uydu haritası ↔ plan) yüklenir; `BUFFER_SIZE=1000`, `BATCH_SIZE=1`, görüntü boyutu $256\times256$'dır. Veri artırma için rastgele kırpma ve önce $286\times286$'ya büyütüp rastgele kırpma (random jitter) uygulanır; görüntüler $x/127{,}5-1$ ile $[-1,1]$ aralığına normalize edilir.
  - Normalizasyon, farklı aydınlıktaki görüntülerin gizli uzayda (latent space) tutarlı temsil edilmesine yardım eder. Kısa eğitimde çıktı plan haritası kısmen oluşmuş, deniz bölgesi tam ayırt edilememiştir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
