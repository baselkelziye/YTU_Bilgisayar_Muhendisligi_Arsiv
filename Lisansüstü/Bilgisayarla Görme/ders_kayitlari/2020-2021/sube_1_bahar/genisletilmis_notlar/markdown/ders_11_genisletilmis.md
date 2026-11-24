# Ders 11 Genişletilmiş Notu: Proje Sunumları: U-Net Tabanlı GAN Ayırıcısı ve RL-CycleGAN ile Simülasyondan Gerçeğe Aktarım

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı
- 2. Veri Artırma ve Çekişmeli Üretici Ağlar
- 3. U-Net Tabanlı Ayırıcı (U-Net GAN)
- 4. CutMix ile Uyum Düzenleme
- 5. U-Net GAN Deneyleri ve Sonuçları
- 6. Birinci Sunumun Soru-Cevapları
- 7. Pekiştirmeli Öğrenmenin Temelleri
- 8. Q-Değerleri, Politika ve Izgara Dünyası Örneği
- 9. Simülasyondan Gerçeğe Aktarım Sorunu
- 10. GAN, Gizli Uzay ve KL Iraksaması
- 11. CycleGAN ve RL-CycleGAN
- 12. RL-CycleGAN Deneyleri
- 13. CycleGAN Uygulaması
- 14. İkinci Sunumun Soru-Cevapları
- Örnek Sorular

## 1. Dersin Yapısı

Bu ders, dönem projelerinin sunulduğu oturumlardan biridir. Derste iki öğrenci sunum yapar. İki sunum da bilgisayarla görmede çekişmeli üretici ağların (Generative Adversarial Networks, GAN) kullanımını ele alan CVPR 2020 bildirilerine dayanır:

- "A U-Net Based Discriminator for Generative Adversarial Networks": GAN'ın ayırıcısını U-Net mimarisine dönüştüren çalışma.
- "RL-CycleGAN: Reinforcement Learning Aware Simulation-to-Real": pekiştirmeli öğrenme ile CycleGAN'ı birleştirerek simülasyonda eğitilen robotun gerçek dünyada çalışmasını sağlayan çalışma.

İkinci sunumu yapan öğrenci, ilk sunumda GAN anlatıldığı için kendi sunumunun da bunun devamı gibi olacağını belirtti; hoca da son çalışmaların giderek bu yöne kaydığını söyledi.

## 2. Veri Artırma ve Çekişmeli Üretici Ağlar

### 2.1 Neden sentetik veri?

Derin öğrenmede kullanılan algoritmalar ve model mimarileri kadar veri miktarı da önemlidir. Veri sayısını artırmak için veri artırma (data augmentation) teknikleri kullanılır: görüntüyü döndürmek, dönüştürmek, ışıkla oynamak gibi. Bunlar basit yollardır ve çoğu zaman istenen başarıyı yakalamaya yetmez. Daha gerçekçi görüntüler üretmek için GAN'lar geliştirilmiştir. Türkçede "çekişmeli üretici ağlar" diye çevrilir. GAN'larla üretilen sentetik verilerle veri setleri zenginleştirilir ve sınıflandırma gibi bilgisayarla görme işlerinde ya da robotikte daha başarılı sonuçlar elde edilir.

### 2.2 Standart GAN

Standart GAN, birbiriyle yarışan iki sinir ağından oluşur (ekrandan, 00:25:00):

- **Üretici (generator, $G$):** Girişi bir gürültü vektörü $z$'dir (örneğin Gauss dağılımından). $G$, bu gürültüden inandırıcı, gerçekçi bir görüntü $G(z)$ üretmeye çalışır.
- **Ayırıcı (discriminator, $D$):** Girişine gerçek veri setinden gelen görüntüler $x$ ile üretilen görüntüler $G(z)$ gelir. $D$, üretilenlerin sahte, diğerlerinin gerçek olduğunu ayırt etmeye çalışır.

Üreticinin elinde ona doğrudan "doğru görüntü budur" diyen bir gözetimci yoktur. Onu ayırıcı eğitir: $D$'nin verdiği karar $G$'ye geri beslenir ve $G$'nin ağırlıkları bu geri bildirimle güncellenir. Bu yüzden iki ağ "birbiriyle yarışıyor" denir ama aslında $D$ sayesinde $G$ daha kaliteli, daha gerçekçi görüntüler üretmeyi öğrenir. Üreticinin içindeki yapı, ayırıcıdaki kod çözücü gibi bir büyütme (upsampling) işlemidir.

Çalışma prensibi oyun teorisine dayanır. Üretici, ayırıcıyı kandıracak kadar iyi görüntü üretmeye; ayırıcı da sahteyi gerçekten ayıracak kadar iyi çalışmaya gayret eder. Bu durumda iki kayıp (loss) vardır: biri en büyüklenmeye, öteki en küçüklenmeye çalışılır. "Çekişmeli" adı bu yarıştan gelir.

> **Ders sonrası not:** Sunumda bu yarış "hiç kaybedeni olmayan, zero-sum game denilen bir denge" diye anlatıldı. Sıfır toplamlı oyunda bir tarafın kazancı tam olarak öbürünün kaybıdır; GAN'da aranan, iki oyuncunun da stratejisini tek başına değiştirerek kazanç sağlayamadığı denge noktasıdır (büyük olasılıkla Nash dengesi kastedilmiştir).

> **Ek bilgi (derste anlatılmadı):** Özgün GAN amaç fonksiyonu $\min_G \max_D \; \mathbb{E}_{x}[\log D(x)] + \mathbb{E}_{z}[\log(1-D(G(z)))]$ biçimindedir. $D$ bu ifadeyi büyütmeye, $G$ küçültmeye çalışır. Sunumdaki "iki loss, biri artırılıyor biri azaltılıyor" anlatımı bu yapıya karşılık gelir.

## 3. U-Net Tabanlı Ayırıcı (U-Net GAN)

### 3.1 Genel bakış

GAN mimarisini geliştirmek için çok sayıda çalışma yapılmıştır. İlk dönemlerde daha çok üretici, sonra ayırıcı, sonra yine üretici geliştirilmiştir. Bu bildiri ayırıcıyı geliştirir: segmentasyonda yaygın kullanılan U-Net mimarisini ayırıcıya uyarlar.

Sunumun giriş slaydında mimari şöyleydi (ekrandan, 00:25:00):

```text
z -> G -> G(z) --+
                 +--> D^U_enc --> [global gerçek/sahte] --> D^U_dec --> [piksel bazlı gerçek/sahte haritası]
x ---------------+        \_______ kısa yol (skip connection) ______/
```

Slayttaki açıklamalar:

- U-Net ayırıcı, giriş görüntüsünü hem global hem lokal olarak, piksel bazlı seviyede sınıflar.
- Kodlayıcı ile kod çözücü arasındaki kısa yollar (şekildeki kesikli çizgi) sayesinde çıktı katmanındaki kanallar hem yüksek hem düşük seviyeli bilgi içerir.
- Çıktı haritasındaki açık renkler, $D$'nin o pikseli gerçek olarak algılama oranını yansıtır.

Sunumun başında gösterilen figürde, eğitim boyunca üretilen bir sentetik yüzün nasıl geliştiği ve yanında kod çözücünün piksel haritası görülür. Haritada siyah bölgeler sahte, beyaz bölgeler gerçek bulunan kısımlardır. Eğitim ilerledikçe örneğin alın bölgesinde iyileşme olur ve harita beyazlaşır. Standart GAN'da resmin tamamı için tek bir gerçek/sahte kararı verilirken burada karar piksel bazında, yani lokal olarak verilir.

### 3.2 Neden lokal değerlendirme?

Ayırıcının kodlayıcı kısmı $D^U_{enc}$ ve kod çözücü kısmı $D^U_{dec}$ birlikte hem global hem lokal değerlendirme yapar. Lokal alanda yeterince iyi değerlendirme yapılamazsa asimetrik yüzler ya da bacağı eksik köpek resmi gibi hatalı görüntüler üretilebilir. U-Net ayırıcı bunun önüne geçmek için önerilmiştir.

### 3.3 İlgili çalışmalar

Ayırıcıyı geliştirmeye yönelik önceki çalışmalar slaytta şöyle listelendi (ekrandan, 00:30:00):

- Birden fazla $D$ kullanma
- Farklı çözünürlüklerde $D$ kullanma
- $D$'nin uzaysal geri bildirim sağlaması
- Yeniden yapılanma tabanlı geri bildirim ile oto-kodlayıcı mimarisi kullanma
- Ciddi unutmalardan kaçınmak için öz-denetim kullanma
- PatchGAN
- BigGAN

Bu çalışmada iki mimari referans alınmıştır. PatchGAN'da ayırıcı lokal alanlardan geri bildirim verir; bu çalışmaya benzer ama birebir aynı değildir. BigGAN ise standart GAN olarak alınmış ve öneriler onun üzerine kurulmuştur.

### 3.4 Formülasyon

Ayırıcıya yeni bir bileşen eklendiği için ayırıcı kaybı, kodlayıcı ve kod çözücü kayıplarının toplamına dönüşür. Kodlayıcı kaybı standart ayırıcı kaybının uyarlanmasıdır. Kod çözücü kaybında $i,j$ indisleri pikselleri gösterir; yani değerlendirme bütün pikseller üzerinden yapılır. Bu değişiklik ayırıcıyla beslenen üreticinin kaybına da yansır ve üretici kaybına da kod çözücüden gelen bir terim eklenir. <!-- BELİRSİZ: Kodlayıcı, kod çözücü ve üretici kayıplarının açık formülleri gösterildi ama hiçbir karede görünmüyor. -->

Uygulamada BigGAN'ın paylaşılan kodu temel alınmış ve U-Net mimarisi onun üzerine eklenmiştir. Bildiride her katmanda toplu normalizasyona (batch norm) aynı giriş vektörünün verildiği belirtilmiştir.

## 4. CutMix ile Uyum Düzenleme

### 4.1 Neden CutMix?

Daha gerçekçi görüntüler için yalnız mimari değiştirilmemiş, ayırıcı bir de veri artırma tekniği olan CutMix ile üretilen karışık görüntülerle beslenmiştir. Gerçek ve sahte görüntüler belirli oranlarla birbirine karıştırılır. Bir maske ile hangi bölgenin gerçek (beyaz), hangisinin sahte (siyah) olduğu gösterilir.

Benzer teknikler şunlardır:

- **Mixup:** Giriş görüntüleri ve etiketleri doğrusal olarak interpole edilir.
- **Cutout:** Görüntüde dikdörtgen bir maske ile bir bölge sıfırlanır.
- **CutMix:** Bir görüntünün dikdörtgen bölgesi başka bir görüntüden alınan parçayla değiştirilir; özgün görüntüler bozulmadan birleştirilir.

CutMix, önceki ikisinin avantajlı yönlerini birleştirdiği için seçilmiştir.

Karışık görüntüler kodlayıcıya sahte olarak, yani sınıfı 0 olarak verilir. Böylece kodlayıcı global anlamda bunları sahte sayar ve üreticiye geri bildirim gittiğinde üretici bu tür parçalı görüntüler üretmeye yönelmez. Kod çözücü ise piksel bazında maskeye uygun bir çıktı vermeye zorlanır.

### 4.2 Uyum düzenleme formülleri

Slayttaki formüller (ekrandan, 00:35:00):

$$\tilde{x}=\mathrm{mix}(x,G(z),M),\qquad \mathrm{mix}(x,G(z),M)=M\odot x+(1-M)\odot G(z) \tag{6}$$

$$\mathcal{L}^{cons}_{D^U_{dec}}=\left\|D^U_{dec}\big(\mathrm{mix}(x,G(z),M)\big)-\mathrm{mix}\big(D^U_{dec}(x),D^U_{dec}(G(z)),M\big)\right\|^2 \tag{7}$$

$$\mathcal{L}_{D^U}=\mathcal{L}_{D^U_{enc}}+\mathcal{L}_{D^U_{dec}}+\lambda\,\mathcal{L}^{cons}_{D^U_{dec}} \tag{8}$$

Burada $x$ gerçek görüntü, $G(z)$ üretilen sahte görüntü, $M$ ikili maske, $\odot$ eleman bazlı çarpım, $\tilde{x}$ CutMix görüntüsüdür. Denklem (7)'nin anlamı şudur: karışık görüntünün kod çözücü haritası, gerçek ve sahte görüntülerin haritalarının aynı maskeyle karıştırılmış hâline eşit olmalıdır. Bu uyum düzenleme (consistency regularization) kaybı, $\lambda$ katsayısıyla ayırıcı kaybına eklenir.

Aynı slayttaki örnek tabloda dört görüntü için şu değerler görünür (ekrandan, 00:35:00):

| | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
| Gerçek/sahte oranı $r$ | 0,28 | 0,68 | 0,31 | 0,51 |
| $D^U_{enc}$ sınıf skoru | 0,31 | 0,60 | 0,36 | 0,43 |

Tabloda her CutMix görüntüsünün altında kod çözücünün segmentasyon haritası vardır; haritada maskenin gerçek ve sahte bölgeleri seçilebilir. Kodlayıcının sınıf skoru, karışımdaki gerçek oranı arttıkça büyüme eğilimindedir.

### 4.3 Eğitime aşamalı dahil etme

CutMix görüntüleri eğitime baştan katılmaz; doğrusal artan bir olasılıkla üretilir. Önce üreticinin bir süre gelişip daha gerçekçi görüntüler üretmesi, sonra karışık görüntülerin eklenmesi düşünülmüştür. Maskeler 0 ve 1 değerlerinden oluşur ve CutMix'in PyTorch uygulaması temel alınarak örneklenmiştir. <!-- BELİRSİZ: Sunumda olasılığın 0 ile 0,25 arasında doğrusal arttığı söylendi; özgün bildirideki değer karelerden doğrulanamadı. -->

### 4.4 Koşullu ve koşulsuz üretim

Koşullu GAN (conditional GAN, cGAN) literatürde ayrı bir türdür. Üreticiye gürültüden başka bir koşul (bir görüntü ya da bir sınıf) da verilir; aynı koşul ayırıcıya da verilir. Böylece görüntüler kontrollü biçimde üretilir. Koşulsuz üretimde yalnız gürültü verilir.

## 5. U-Net GAN Deneyleri ve Sonuçları

### 5.1 Veri setleri ve ölçütler

Çalışmada dört veri seti kullanılmıştır:

- **CelebA ve FFHQ:** İnsan yüzlerinden oluşur. FFHQ, CelebA'ya göre daha kaliteli, daha çeşitli bakış açılı ve daha yüksek çözünürlüklü görüntüler içerir. Bu ikisi koşulsuz görüntü üretiminde kullanılmıştır.
- **COCO-Animals:** Yazarların COCO ve OpenImages'ın hayvan sınıflarından derlediği veri setidir; sınıf koşullu üretimde kullanılmıştır. Az veri içerdiği ve sınıf dağılımı dengesiz olduğu için zor bir veri seti olarak sunulmuştur. <!-- BELİRSİZ: Sunumda "dört veri seti" dendi ama yalnız üçü adıyla sayıldı. -->

Değerlendirme ölçütleri FID ve IS'dir. Sunumda FID'nin insan değerlendirmesiyle daha uyumlu olduğu için tercih edildiği söylendi.

> **Ders sonrası not:** Sunumda IS'nin "eğitim verisine bağlı değerlendirme yaptığı" söylendi. IS aslında gerçek veriyle karşılaştırma yapmaz; yalnız üretilen görüntülerin önceden eğitilmiş bir Inception sınıflandırıcısındaki çıktılarına bakar. FID ise gerçek ve üretilen görüntülerin Inception öznitelik istatistiklerini karşılaştırır. FID'nin tercih edilmesinin nedeni büyük olasılıkla budur.

### 5.2 Görsel sonuçlar

FFHQ üzerinde gürültüden üretilen yüzler oldukça gerçekçidir; bunda veri setinin çok kaliteli görüntüler içermesinin de payı vardır. Veri setinde pembe saçlı insanlar gibi çok çeşitli görüntüler olduğu için pembe sakal gibi sonuçlar da üretilmiştir. Bildirinin vurguladığı nokta yumuşak geçişlerdir: bir satırda sakallı bir yüzden başka bir yüze, ağzın yavaş yavaş açılmasına, saç ve sakalın yavaş yavaş değişmesine doğru düzgün bir ilerleme görülür. Bu satırlar iki sentetik örnek arasındaki geçişi gösterir (bkz. Bölüm 6).

COCO-Animals üzerinde U-Net GAN'ın ürettiği görüntüler (koyun, inek, zürafa, kedi, kuş, maymun, köpek, fil, at, zebra vb.), zorlu bir veri seti olmasına rağmen gerçeğe çok yakındır (ekrandan, 00:40:00).

### 5.3 Sayısal sonuçlar

FFHQ ve COCO-Animals'ta, referans alınan BigGAN'a göre her ikisinde de FID düşmüş, IS yükselmiştir; yani U-Net GAN her durumda daha başarılıdır. <!-- BELİRSİZ: Bu tablonun değerleri karelerde okunamadı. -->

Ablasyon deneyinde önerilen bileşenler BigGAN'a aşama aşama eklenmiştir: önce yalnız U-Net tabanlı ayırıcı (başarı bir miktar artmış), sonra CutMix artırması (biraz daha artmış), en son uyum düzenleme kaybı (en yüksek başarı).

Diğer yöntemlerle karşılaştırma tablosu (ekrandan, 00:45:00):

| Yöntem | FID ↓ | IS ↑ |
|---|---|---|
| PG-GAN | 7,30 | – |
| COCO-GAN | 5,74 | – |
| BigGAN | 4,54 | 3,23 |
| U-Net GAN | 2,95 | 3,43 |

<!-- BELİRSİZ: Slaytta tablonun hangi veri setine ait olduğu yazmıyor; büyük olasılıkla CelebA. -->

### 5.4 Sunumu yapan öğrencinin denemesi

Öğrenci, sınırlı donanımda modeli çalıştırıp gürültünün zamanla insan yüzüne benzeyen bir dağılıma nasıl dönüştüğünü görmek için FFHQ'dan 3000 görüntü kullandı. Görüntüleri $256\times256$'dan $128\times128$'e indirdi ve koşulsuz GAN'ı 100 epoch, 200'lük veri gruplarıyla eğitti. Eğitim sırasında belirli aralıklarla (örneğin her 10 adımda bir) üretilen görüntüler kaydedildi. Ayrıca temel yöntemleri denemek için görüntülere Canny, Sobel, Hough ve Harris özniteliklerini ekleyerek 1000 görüntüyle daha kısa sürede benzer sonuç alınıp alınamayacağını denedi. Kod sıfırdan yazılmamış, mevcut bir çalışma referans alınarak geliştirilmiştir. <!-- BELİRSİZ: Öznitelik adları altyazıda "Keynes, Solbel, Hoppe" diye bozuk; Canny, Sobel ve Hough olduğu bağlamdan çıkarıldı. -->

### 5.5 Sonuç

Bu çalışma, GAN üzerinde yapılan mimari geliştirmelere bir örnektir: ayırıcının mimarisi değiştirilerek daha başarılı sonuç alınmıştır. Asıl vurgu, görüntüyü hem global hem lokal anlamda değerlendirerek iki gerçekliği birlikte korumaktır. Ayırıcı hem sınıflandırıcı hem segmentasyon ağı gibi çalışır.

## 6. Birinci Sunumun Soru-Cevapları

**Soru (hoca):** Yumuşak geçiş figüründe bir satır aynı sürecin başlangıcını ve sonunu mu gösteriyor?
**Cevap:** Bildiride net bir açıklama yok; figürün iki sentetik örnek arasındaki geçişi gösterdiği anlaşılıyor. Hoca, görüntülerin ikişer ikişer birbirinden türetilmiş gibi göründüğünü belirtti; öğrenci "iki sentetik örnek" ifadesinin bunu anlattığını kabul etti. Öğrencinin kendi deneme slaydındaki satırlar ise ikili değildir; eğitim sırasında belirli aralıklarla çizilen ara sonuçlardır.

**Soru (hoca):** Sistemin performansını ölçen FID ve IS skorları neyi kontrol ediyor, formülasyonları nedir?
**Cevap:** Formülasyon sunulan dokümanda yoktu ve öğrenci araştıramadığını söyledi. Hoca bunun araştırılmasını istedi (çözüm için bkz. Örnek Sorular).

> **Hocanın vurgusu:** Bir çalışmayı bir bütün olarak değerlendirebilmek için kullanılan başarı ölçütlerinin neyi ölçtüğü üzerinde de kafa yormak gerekir.

## 7. Pekiştirmeli Öğrenmenin Temelleri

İkinci sunum önce pekiştirmeli öğrenmeyi (reinforcement learning, RL) ve oradaki sorunu anlatır, sonra bu sorunu gidermek için yapılan çalışmaya geçer.

### 7.1 Ajan, durum, eylem, ödül

RL'de ajan (agent) kendi kendine öğrenir. Her hareketi bir eylemdir (action) ve her eylemden sonra yeni bir durum (state) oluşur; görme problemlerinde her yeni durum yeni bir görüntüdür. Ajan sayısal bir ödül puanını en büyüklemeye çalışır. Yaptığı hareketler her zaman en büyük ödüle götürmez. Ödüller sezgisel olarak tasarımcı tarafından verilir ve genelde deneme yanılma ile belirlenir. Ödül sıfır, eksi ya da artı olabilir.

Basit bir RL döngüsünde ajan bir eylem alır, yeni bir gözlem ve bir kazanç elde eder. Görüntü işlemeyle birleştirilen RL, birçok video oyununda yüksek performans göstermiştir.

### 7.2 Markov karar süreci

RL'nin temel koşullarından biri problemin bir Markov karar süreci (Markov Decision Process, MDP) olmasıdır: bir sonraki adım yalnız o anki adıma bağlıdır.

Sunumdaki örnekte ajan bir tavşandır ve iki eylemi vardır: sağa ya da sola gitmek. Sağa giderse daha sevdiği havuca ulaşır ama bir tehlikeye (yırtıcı hayvana) daha yakın olur. Notasyonda $S_0$ başlangıç durumu, $A_0$ alınan eylem, $R_1$ kazanılan ödüldür; sonraki adımlar aynı notasyonla devam eder.

### 7.3 Keşif ve sömürü

Ajan ayarlanmazsa hep aynı rotayı izleyebilir. Bu yüzden arada bir rastgele hareket yapması gerekir ki başka yolları da keşfetsin (exploration); bildiği en iyi yolu kullanmaya sömürü (exploitation) denir. Örnekteki fare yakında küçük bir peynir bulduğunda sonsuza kadar oraya gidebilir; rastgele bir hareket yapmadan uzaktaki büyük ödüle ulaşamaz. Ama büyük ödüle giderken ölme riski de vardır.

### 7.4 İndirim faktörü

Uzaktaki ödülle yakındaki ödül aynı değerde olmamalıdır; uzaktaki ödül bir indirim faktörüyle çarpılır. Slayttaki formüller (ekrandan, 00:50:00):

$$R_t=r_{t+1}+r_{t+2}+\dots+r_T=\sum_{x=t+1}^{T} r_x$$

$$R_t=\sum_{k=0}^{T}\gamma^k\, r_{t+k+1},\qquad 0\le\gamma\le1$$

Aynı slaytta bir elmas görseliyle sezgi verilir: hemen alınan ödülün değeri 1, bir adım sonra alınanınki $\gamma$, iki adım sonra alınanınki $\gamma^2$'dir; elmas her adımda biraz daha "ufalanır". Yanındaki ağaç çizimi, her durumdan birçok eylem dalının çıktığını ve seçilen yolun bunların biri olduğunu gösterir.

## 8. Q-Değerleri, Politika ve Izgara Dünyası Örneği

### 8.1 Q-değeri ve politika

Örnek, bir üniversitenin yapay zeka dersi için hazırlanmış, kodundaki boşlukları doldurmaya dayalı açık bir projeden alınmıştır. Ajan, alabileceği eylemleri ve gidebileceği sonraki durumları alır. Q-değeri (Q-value) bu çalışmada da merkezi önemdedir: bir durumda bir eylemin beklenen değeridir. Q-değeri, olası tüm sonuçlar üzerinden beklenen değer hesaplanarak bulunur; bir sonraki durumda da en yüksek değerli eylem alınmak zorundadır.

Politika (policy), gidilen yolda alınacak en yüksek değeri veren plandır: olası tüm sonuçları al, eylem değerlerini hesapla ve en yüksek olanı politika olarak seç. Kodda en büyük Q-değeri aranırken başlangıç değeri eksi sonsuzdur; hiç geçerli eylem yoksa değer sıfır alınır.

Rastgele hareket bir $\epsilon$ olasılığıyla yapılır: kodda `random choice` ile her adımda belirli bir olasılıkla rastgele bir eylem seçilir, aksi hâlde en yüksek Q-değerli eylem alınır.

> **Ek bilgi (derste anlatılmadı):** Q-öğrenmede her geçişten sonra güncelleme $Q(s,a)\leftarrow(1-\alpha)Q(s,a)+\alpha\,[\,r+\gamma\max_{a'}Q(s',a')\,]$ biçimindedir. Burada $\alpha$ öğrenme oranıdır. Aşağıdaki ızgara dünyası değerleri bu kuralla oluşur.

### 8.2 Izgara dünyası demosu

Demoda $4\times3$'lük bir ızgara dünyası (gridworld) vardır; ajan elle yürütülür (ekrandan, 00:55:00). Ajan her adımda sıfır ödül alır, çünkü ara karelerde ödül yoktur. Sağ sütunda iki çıkış karesi vardır: biri +1, biri −1 ödüllüdür. Ajan bunu başta bilmez; yalnız oraya gidip ödülü aldığında öğrenir. Q-değerleri ilk geçişte hesaplanmaz; ajan bir sonraki geçişinde değer bir önceki kareye taşınır ve ajan hareket ettikçe değerler sürekli güncellenir.

Karede birkaç bölümden sonraki Q-değerleri şöyledir:

- +1 çıkış karesi: 0,88
- −1 çıkış karesi: −0,50
- +1 karesinin solundaki karede "doğu" eylemi: 0,45
- Onun solundaki karede "doğu" eylemi: 0,10
- Diğer bütün eylemler: 0,00

> **Ek bilgi (derste anlatılmadı):** Bu değerler büyük olasılıkla $\alpha=0{,}5$ ve $\gamma=0{,}9$ ile oluşmuştur. Çıkış karesi üç kez ziyaret edilince $0\to0{,}5\to0{,}75\to0{,}875\approx0{,}88$ olur; −1 karesi bir kez ziyaret edilince $0{,}5\cdot(-1)=-0{,}50$ olur. Komşu kare iki güncellemeyle $0{,}5\cdot0{,}9\cdot0{,}5=0{,}225$ ve $0{,}225+0{,}5\,(0{,}9\cdot0{,}75-0{,}225)=0{,}45$ olur; bir soldaki kare $0{,}5\cdot0{,}9\cdot0{,}225\approx0{,}10$ olur (python ile doğrulandı).

## 9. Simülasyondan Gerçeğe Aktarım Sorunu

RL'de ajanı gerçek hayatta eğitmek çok maliyetlidir. Sürekli hareket eden ve hatalarından ders çıkaran bir robot düşünün: simülasyonda çukura düşerse bir şey olmaz, sıfırdan tekrar başlar; ama gerçek robot çukura düşerse bu çok pahalıya mal olur. Bu yüzden Q-değerleri simülasyonda hesaplanır ve ajan sonra gerçek hayata çıkarılır.

Ancak simülasyonun gerçeklik düzeyi sınırlıdır. Ne kadar iyi grafiklerle yapılsa da o anki güneş ışığı, kamera açısı gibi etkenler gerçek dünyada çok farklıdır. Sanal ortamda eğitilen ajanlar, gerçek dünyanın yetersiz ya da yanlış modellenmesi yüzünden gerçek hayatta başarısız olur. Bildirinin amacı bu sorunu çözmektir.

## 10. GAN, Gizli Uzay ve KL Iraksaması

### 10.1 GAN'a ikinci bakış

İkinci sunum GAN'ı bir benzetmeyle anlatır: üretici rastgele sahte resimler üreten biri, ayırıcı ise resmin gerçek mi sahte mi olduğunu anlamaya çalışan bir uzman (ya da polis) gibidir. Ayırıcı doğru karar verirse kayıp farkı sıfırdır; yanlış karar verirse bu hata üreticiye ve ayırıcıya geri bildirilir.

### 10.2 Gizli uzay

Üretici, gizli uzay (latent space) üzerine rastgele gürültü atarak bir resim oluşturur. Başta bu gürültü düzgün (uniform) dağılımdan, yani her değer eşit olasılıkla atılır; eğitimle gürültüyü nasıl atacağını öğrenir. Gizli uzay, gerçek görüntülerin küçültülmüş bir özeti gibidir.

Örneğin $512\times512$'lik üç kanallı (RGB) bir görüntü $512\times512\times3$ değişkenlik bir settir; böyle iki görüntünün birbirine benzeyip benzemediğini doğrudan ölçmek çok zordur. Kodlayıcı (encoder) ile görüntünün gizli uzaydaki temsili, yani öznitelikleri çıkarılır ve karşılaştırma orada yapılır. Kod çözücü (decoder) bu temsilden resmi geri oluşturur.

### 10.3 KL ıraksaması

İki dağılımın farklı olduğunu anlamanın birçok olasılıksal yolu vardır; bildiride Kullback-Leibler (KL) ıraksaması kullanılmıştır. $P$, gerçek verilerden oluşan gizli uzayın olasılık dağılımı; $Q$, üretilen yeni resimlerin dağılımıdır. İki dağılım birbirine eşit olduğunda $D_{KL}$ sıfıra ulaşır; yani fark anlaşılamaz.

Eğitim, ayırıcının gerçeği sahteden ayıramadığı, kararını 0,5 olasılıkla rastgele verdiği noktada durur.

> **Ek bilgi (derste anlatılmadı):** $D_{KL}(P\|Q)=\sum_x P(x)\log\dfrac{P(x)}{Q(x)}$ biçimindedir; her zaman sıfır ya da pozitiftir ve yalnız $P=Q$ iken sıfırdır. Özgün GAN'ın en iyi ayırıcı altında aslında Jensen-Shannon ıraksamasını küçülttüğü gösterilmiştir; JS, KL'nin simetrik bir türevidir.

### 10.4 Kayıp fonksiyonu

Amaç kayıp fonksiyonunu en küçüklemektir: üreticinin ürettiği resim gerçeğe benzemeli ve ayırıcı bunu anlayamamalıdır. Sunumdaki formülde bu yüzden eksi işaretli bir terim ve toplam alınan terimler vardır. <!-- BELİRSİZ: Sunumdaki kayıp formülü hiçbir karede görünmüyor. -->

## 11. CycleGAN ve RL-CycleGAN

### 11.1 Eşleştirilmiş ve eşleştirilmemiş veri

Görüntüden görüntüye çeviri, giriş görüntüsü ile ona karşılık gelen çıktı görüntüsü arasındaki eşlemeyi öğrenmeye çalışan bir görüntü işleme problemidir. Ancak çoğu durumda eşleştirilmiş görüntüler yoktur ve bunları hazırlamak büyük bir iş yüküdür. Eşleştirilmiş örneklerin yokluğunda (unpaired image-to-image) bir görüntünün kaynak alanı $X$'ten hedef alanı $Y$'ye dönüştürülmesini öğrenen bir yaklaşım CycleGAN'dır (ekrandan, 01:00:00).

Sunumda gösterilen şekilde iki tür veri karşılaştırılır:

- **Eşleştirilmiş (paired):** Her ayakkabı çizimi $x_i$'nin karşısında aynı ayakkabının fotoğrafı $y_i$ vardır.
- **Eşleştirilmemiş (unpaired):** $X$ kümesinde manzara fotoğrafları, $Y$ kümesinde resim tabloları vardır; aralarında birebir eşleşme yoktur.

> **Ders sonrası not:** Sunumda "GAN'da X ve Y değerleri, bir hedef değer olması lazım, CycleGAN'da bu gerekmiyor" dendi. Eşleştirilmiş giriş-çıktı çifti isteyen yöntem genel GAN değil, koşullu GAN'a dayalı görüntüden görüntüye çeviri yöntemleridir (büyük olasılıkla pix2pix kastedilmiştir). Standart GAN zaten yalnız gürültüden üretir. CycleGAN'ın farkı, çeviriyi eşleştirilmemiş iki küme arasında öğrenmesidir.

### 11.2 CycleGAN'ın çalışması

CycleGAN iki GAN içerir. Çevrilecek iki alanın birbirine benzer olması gerekir: zebrayı dönüştürmek için ona benzeyen bir nesne (at), elmayı dönüştürmek için portakal gibi. Model belirli noktaları eşleştirerek kendince bir dönüşüm öğrenir.

Bir görüntü çevrilir ve sonra geri çevrilir; geri çevrilen görüntü başlangıçtakine benzemelidir. Bu çift yönlü doğrulama sürekli güncellenerek yapılır. Harita örneğinde $X$ harita (uydu görüntüsü), $Y$ dönüştürülmek istenen plandır: $G$ haritayı plana, $F$ planı haritaya çevirir. $D_X$ haritanın, $D_Y$ planın gerçek olup olmadığını anlamaya çalışır. Böylece iki ekstra görüntü (geri çevrilmiş olanlar) üretilmiş olur.

> **Ek bilgi (derste anlatılmadı):** CycleGAN'ın çevrim tutarlılığı kaybı $\mathcal{L}_{cyc}=\mathbb{E}_x\|F(G(x))-x\|_1+\mathbb{E}_y\|G(F(y))-y\|_1$ biçimindedir ve iki çekişmeli kayba bir katsayıyla eklenir.

### 11.3 RL-CycleGAN'ın fikri

RL-CycleGAN, simülasyon görüntüsünü gerçeğe çevirmeye, gerçeği de simülasyona çevirmeye çalışır; çevrilen görüntüler tekrar geri çevrilir. CycleGAN önce eğitilir, sonra bu işlemlere dahil edilir.

Sunumda anlatılan yapıda altı görüntü vardır: üstte simülasyon tarafındaki üç görüntü (simülasyon, gerçeğe çevrilmiş, geri çevrilmiş), altta gerçek taraftaki üç görüntü. Her görüntü için Q-değeri hesaplanır ve bunların tutarlılığına bakılır: simülasyon ile ondan çevrilen gerçekçi görüntü, gerçek ile ondan çevrilen simülasyon görüntüsü ve geri çevrilen görüntüler arasındaki Q-değeri farkları küçük olmalıdır. Kayıp fonksiyonu bu farklara bakar; fark, karelerin farkının karekökü gibi basit bir uzaklıkla hesaplanır. <!-- BELİRSİZ: RL-scene consistency kaybının açık formülü hiçbir karede görünmüyor. -->

Bunun amacı, çevirinin görevle ilgili sahne bilgisini (örneğin tutulacak nesneleri) korumasıdır. Q-değerleri değişmiyorsa çeviri, robotun kararını etkileyen bir şeyi silmemiş ya da eklememiştir. Yazarlar yöntemin yalnız bu çalışmaya değil başka işlere de yarayacağını göstermek için iki farklı düzen kurmuştur.

## 12. RL-CycleGAN Deneyleri

### 12.1 Düzen

Simülasyon ve gerçek bir robot vardır. Görev, ortadaki kutudaki çöpleri robot koluyla alıp sağdaki ya da soldaki kutuya bırakmaktır. Ödül, tutma başarılıysa artı, başarısızsa eksidir ve sürekli güncellenir. Q-değeri yukarıda anlatıldığı gibi hesaplanır. Simülasyonda başarı %90'a ulaşır ama gerçek hayatta aynı başarı elde edilemez.

- Kamera tek gözlü (monoküler) bir RGB kameradır.
- Robotun eylemleri dört boyutludur. <!-- BELİRSİZ: Altyazıda "sağa sola yukarı aşağı, X Y Z eksenlerinde ... ayrıca rotasyonu yapamıyor, yani dört boyutta" deniyor; dördüncü boyutun ne olduğu net değil. -->
- Simülasyon, Bullet fizik simülasyonudur (altyazıda "balık" diye bozulmuş).
- **Birinci robot grubu** basittir: sahne tek bir kamera açısından görülür. <!-- BELİRSİZ: Altyazıda bu düzenin ayrıntısı bozuk. -->
- **İkinci robot grubunda** farklı açılardan görüntüler alınır: kamera kutuların ortasına, sağına ve soluna yerleştirilir (ekrandan, 01:05:00). Şekildeki çevrelerde kutular şişe, bardak, kâse gibi farklı nesnelerle doludur.

### 12.2 Birinci robot grubu

Sunumda söylenen değerler: simülasyonda eğitilen model gerçek hayata çıkarıldığında başarı %21'dir. Rastgeleleştirilmiş simülasyonda (nesneler kutunun sağına, soluna ya da ortasına rastgele yerleştirildiğinde) başarı %37'dir. Karşılaştırılan yöntemler GAN, CycleGAN, GraspGAN ve RL-CycleGAN'dır; ilk üçü RL'ye özel bir kayıp kullanmadan yalnız simülasyon görüntüsünü değiştirir. RL-CycleGAN en yüksek değeri alır ama tek başına simülasyonla hâlâ yeterli değildir. <!-- BELİRSİZ: %21 ve %37 değerlerinin geçtiği tablo hiçbir karede görünmüyor. -->

Görsel karşılaştırmada üst satırda simülasyon görüntüleri, alt satırda yöntemlerin bunları gerçeğe çevirmiş hâli vardır:

- **GAN:** Bazen sahnedeki nesneleri ekler ya da çıkarır; gerçek görüntüyü vermez.
- **CycleGAN:** Ekleme yapmaz ama nesne çıkarır; üst görüntüde olan nesne altta yoktur.
- **GraspGAN:** Nesne eklemez ya da çıkarmaz ama görüntü kalitesi çok bozulur.
- **RL-CycleGAN:** Nesneleri koruyarak en iyi çeviriyi verir.

Gerçek robotla tutma başarısı tablosu (ekrandan, 01:10:00):

| Bölüm sayısı | Yalnız gerçek | GraspGAN | RL-CycleGAN |
|---|---|---|---|
| 5.000 | %15 | – | %75 |
| 28.000 | %16 | – | %86 |
| 580.000 | %87 | %89 | %94 |

RL'de bir deneyin başlayıp bitmesine bir bölüm (episode) denir. Yalnız gerçek veriyle 5.000 bölümde %15 başarı alınırken RL-CycleGAN ile %75 alınır. 580.000 bölümde de RL-CycleGAN öndedir.

### 12.3 İkinci robot grubu

Burada tek bir nesneyi alıp başka yere bırakma ve birden fazla nesneyi alıp bırakma senaryoları vardır (ekrandan, 01:10:00):

| Bölüm sayısı | Sim+Gerçek | RL-CycleGAN |
|---|---|---|
| Tek kutu, ortalanmış kamera: 3.000 | %13 | %72 |
| Tek kutu, ortalanmış kamera: 5.000 | %12 | %76 |
| Tek kutu, ortalanmış kamera: 10.000 | %10 | %84 |
| Tek kutu, ortalanmış kamera: 80.000 | %36 | %95 |
| Çok kutu, rastgele konum: 80.000 | %33 | %93 |

Simülasyon ve gerçek veri birlikte kullanıldığında az bölümde %10-13 civarında kalan başarı, RL-CycleGAN ile çok daha yüksektir.

### 12.4 On-policy ve off-policy yöntemlerle karşılaştırma

Sunumda RL-CycleGAN, RCAN adlı başka bir yöntemle de karşılaştırıldı. RCAN farklı kamera açılarıyla, yani alan rastgeleleştirmesi (domain randomization) ile eğitilir. Sunumda söylenen değerler: 5.000 denemede RCAN %91, RL-CycleGAN alan rastgeleleştirmesi olmadan, tek kamera açısıyla %90 başarı alır; aradaki fark yalnız %1'dir. 28.000 denemede ikisi de %94'e ulaşır, ama RL-CycleGAN bunu daha kısıtlı koşullarda yapar. <!-- BELİRSİZ: Bu karşılaştırmanın tablosu hiçbir karede görünmüyor; değerler yalnız altyazıdan alındı. -->

Sunumda on-policy yöntemin robotun nasıl hareket edeceğini önceden bildiği, off-policy yöntemin ise sıfırdan öğrendiği ve daha çok iterasyon gerektirdiği söylendi.

> **Ders sonrası not:** Sunumdaki on-policy/off-policy tanımı standart tanım değildir. On-policy yöntemler, o anda izlenen politikanın ürettiği verilerle aynı politikayı öğrenir. Off-policy yöntemler (örneğin Q-öğrenme) başka bir politikanın, örneğin daha önce toplanmış verinin ürettiği deneyimden öğrenebilir. Sunumdaki "on-policy yöntem önceden nasıl hareket edeceğini biliyor" ifadesi büyük olasılıkla bildirideki on-policy ince ayarın (fine-tuning) yanlış yorumlanmasıdır.

## 13. CycleGAN Uygulaması

Bildirinin kodları paylaşılmadığı için öğrenci Q-öğrenme ve CycleGAN'ın örneklerini ayrı ayrı denedi. CycleGAN örneği için TensorFlow'un Colab üzerindeki CycleGAN öğreticisi kullanıldı ve harita veri setiyle çalışıldı.

Öğreticinin veri hazırlama kodu (ekrandan, 01:15:00):

```python
dataset, metadata = tfds.load('cycle_gan/maps',
                              with_info=True, as_supervised=True)

train_maps, train_plans = dataset['trainA'], dataset['trainB']
test_maps, test_plans = dataset['testA'], dataset['testB']

BUFFER_SIZE = 1000
BATCH_SIZE = 1
IMG_WIDTH = 256
IMG_HEIGHT = 256

def random_crop(image):
  cropped_image = tf.image.random_crop(
      image, size=[IMG_HEIGHT, IMG_WIDTH, 3])

  return cropped_image

# normalizing the images to [-1, 1]
def normalize(image):
  image = tf.cast(image, tf.float32)
  image = (image / 127.5) - 1
  return image

def random_jitter(image):
  # resizing to 286 x 286 x 3
  image = tf.image.resize(image, [286, 286],
                          method=tf.image.ResizeMethod.NEAREST_NEIGHBOR)
  ...
```

Bu bir kod parçasıdır ve bu not için çalıştırılmadı; `random_jitter` fonksiyonunun devamı karede görünmüyor.

Adımların anlamı:

- **Rastgele kırpma (random crop):** Veriyi çoğaltmak içindir. Önce görüntü $286\times286$'ya büyütülüp sonra rastgele $256\times256$'lık bir parça kırpılır.
- **Normalizasyon:** $[0,255]$ aralığındaki piksel değerleri $x/127{,}5-1$ ile $[-1,1]$ aralığına taşınır ($0\to-1$, $255\to1$). Normalize edilmezse bazı görüntüler çok aydınlık, bazıları çok karanlık olur ve gizli uzay bunları iyi temsil edemez. Ortalamayı çıkarıp standart sapmaya bölmek de aynı amaca hizmet eder.

Eğitim başında üretici, düzgün dağılımdan bir gürültü üreterek görüntünün üzerine atar; ayırıcı da başta görüntüyü bu gürültülü hâliyle görür. Kısa bir eğitimden sonra çıktı planda hangi bölgenin nereye karşılık geldiği seçilebilir hâle gelmiştir, ama yeterli iterasyon olmadığı için ortadaki deniz algılanamamış ve gerçek karşılığı olmayan ekstra yollar üretilmiştir. Hoca, çıktıda biraz mavilik oluştuğunu ve iterasyon arttıkça bu bölgenin büyüyebileceğini belirtti.

CycleGAN proje sayfasındaki örneklerde fotoğraflar Monet, Van Gogh, Cézanne ve Ukiyo-e üsluplarına çevrilir; at-zebra, ayı-panda, kuş renklerinin değiştirilmesi, krokinin haritaya çevrilmesi gibi dönüşümler de gösterilir (ekrandan, 01:20:00). Eğitilen model videoya da uygulanabilir: videodan tek tek kareler alınır, her kare çevrilir ve kareler yeniden birleştirilir (örneğin koşan bir atın zebraya çevrilmesi). Modelin sınırı da vardır: ata binen bir insan da zebra desenine çevrilir, çünkü model eğitimde at üzerinde insan görmemiştir ve onu atın bir parçası sanır.

## 14. İkinci Sunumun Soru-Cevapları

**Soru (hoca):** RL-CycleGAN'ın nasıl işe yaradığını, karşılaştırma figüründe diğer yöntemlerle farkını tekrar açıklar mısın?
**Cevap:** Figürde üst satırlar simülasyon görüntüsünü, alt satırlar ilgili algoritmayla çevrilmiş görüntüyü gösterir. Diğer yöntemlerde işaretlenen yerlerde nesne silme ya da ekleme olmuştur; RL-CycleGAN'da bu olmamış, görüntü sorunsuz oluşmuştur.

**Soru (hoca):** Görüntülerdeki sarı ve yeşil görünen şeyler nedir? İkinci resimde yoklar mı?
**Cevap:** Bunlar robotun kaldırıp başka kutuya atmaya çalıştığı çöp nesneleridir. Evet, bazı yöntemlerin çevirisinde kaybolurlar; sorun tam olarak budur.

Hoca kapanışta pekiştirmeli öğrenmenin ayrı ve çok güzel bir konu olduğunu, çok farklı alanlara uyarlanabildiğini belirtti. Daha önce nesne takibi (object tracking) problemine uygulanmış bir RL yöntemi görüldüğünü ve algoritmanın bir takım değişikliklerle farklı görme problemlerine uyarlanabildiğini söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:39:55): U-Net GAN bildirisindeki yumuşak geçiş figüründe bir satırdaki görüntüler neyi gösterir?

Derste verilen cevap: Bildiride ayrıntılı açıklama yoktur; satırlar iki sentetik örnek arasında yapılan geçişi gösterir. Uçlardaki iki görüntü iki ayrı gürültü vektöründen üretilen örneklerdir, aradakiler bu ikisi arasında kademeli geçiştir.

**Soru 2** (derste sözlü, 00:44:22): GAN performansını ölçen FID ve IS skorları neyi kontrol eder, formülleri nedir?

> **Çözüm (derste verilmedi):** İkisi de önceden eğitilmiş Inception ağını kullanır.
>
> - **IS (Inception Score):** $\mathrm{IS}=\exp\big(\mathbb{E}_{x\sim p_g}\,D_{KL}(p(y\mid x)\,\|\,p(y))\big)$. Her üretilen görüntünün sınıf dağılımı $p(y\mid x)$ keskin olmalı (görüntü net bir nesne içermeli), bütün görüntülerin ortalama sınıf dağılımı $p(y)$ ise geniş olmalıdır (çeşitlilik). Gerçek veriyle karşılaştırma yapmaz; yüksek olması iyidir. Örneğin iki görüntü iki farklı sınıfa tam güvenle atanıyorsa $\mathrm{IS}=2$ olur.
> - **FID (Fréchet Inception Distance):** Gerçek ve üretilen görüntülerin Inception özniteliklerine birer çok değişkenli Gauss uydurulur: $(\mu_r,\Sigma_r)$ ve $(\mu_g,\Sigma_g)$. $\mathrm{FID}=\|\mu_r-\mu_g\|^2+\mathrm{Tr}\big(\Sigma_r+\Sigma_g-2(\Sigma_r\Sigma_g)^{1/2}\big)$. İki dağılım aynıysa sıfırdır; düşük olması iyidir. Örneğin tek boyutta $\mathcal{N}(0,1)$ ile $\mathcal{N}(1,4)$ için $\mathrm{FID}=1+1+4-2\cdot2=2$ olur.
>
> İki örnek değer python ile doğrulandı. FID gerçek veri dağılımını hesaba kattığı için insan değerlendirmesiyle daha uyumlu kabul edilir.

**Soru 3** (derste sözlü, 01:07:42): RL-CycleGAN, simülasyondan gerçeğe çeviride GAN, CycleGAN ve GraspGAN'dan neden daha iyi sonuç verir?

Derste verilen cevap: Diğer yöntemler çeviri sırasında sahneye nesne ekleyebilir ya da sahneden nesne silebilir (GAN ve CycleGAN) veya görüntü kalitesini bozabilir (GraspGAN). RL-CycleGAN, simülasyon ve çevrilmiş görüntülerin Q-değerlerinin tutarlı olmasını isteyen ek kayıp sayesinde robotun kararını etkileyen nesneleri korur.

**Soru 4** (derste sözlü, 01:08:37): RL-CycleGAN karşılaştırma figüründeki sarı ve yeşil nesneler nedir ve bazı çevrilmiş görüntülerde neden yoktur?

Derste verilen cevap: Bunlar robotun tutup başka kutuya taşıyacağı çöp nesneleridir. Görev bilgisini korumayan çeviri yöntemleri bu nesneleri silebilir; bu da simülasyonda eğitilen politikanın gerçekte yanlış karar vermesine yol açar.

## Dersin Toparlaması

Bu derste iki proje sunumu üzerinden GAN'ların bilgisayarla görmedeki iki farklı kullanımı görüldü. Birinci sunumda ayırıcıyı U-Net'e dönüştüren U-Net GAN anlatıldı: ayırıcının kodlayıcı kısmı global, kod çözücü kısmı piksel bazlı gerçek/sahte kararı verir ve CutMix ile üretilen karışık görüntülerle uyum düzenleme kaybı eklenir. Bu sayede hem global yapı hem lokal ayrıntı korunur ve FID/IS ölçütlerinde BigGAN'dan daha iyi sonuç alınır. Hoca, bu tür çalışmaları değerlendirirken kullanılan ölçütlerin ne ölçtüğünün bilinmesi gerektiğini vurguladı.

İkinci sunumda pekiştirmeli öğrenmenin temelleri (MDP, ödül, indirim faktörü, keşif-sömürü, Q-değeri ve politika) ile simülasyondan gerçeğe aktarım sorunu anlatıldı. RL-CycleGAN, simülasyon görüntülerini CycleGAN ile gerçeğe çevirirken Q-değerlerinin korunmasını isteyerek görev için önemli nesnelerin kaybolmasını önler ve gerçek robotla tutma başarısını belirgin biçimde artırır. Hoca, pekiştirmeli öğrenmenin nesne takibi gibi farklı görme problemlerine de uyarlanabildiğini hatırlattı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
