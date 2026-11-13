# Ders 12 Çalışma Özeti

## Genel Konular

- Seminer sunumları
  - Bu ders de öğrenci seminer sunumlarına ayrıldı. Her sunumda bir öğrenci veri sıkıştırmayla ilgili yayımlanmış bir makaleyi anlattı; hoca sunum sırasında ve sonrasında sorular sordu.
  - Beş sunum yapıldı: RNN ile kayıpsız sıkıştırma (DeepZip), metin sınıflandırma modelinin sıkıştırılması (FastText.zip), iki ayrı sunumda aynı makaleden fraktal görüntü sıkıştırma ve RNN'lerle tam çözünürlüklü görüntü sıkıştırma.
- Sunum 1: DeepZip, tekrarlayan sinir ağlarıyla (RNN) kayıpsız sıkıştırma
  - Temel fikir: iyi bir tahmin modeli iyi sıkıştırma demektir. Veriyi daha küçük temsillerle ifade etmek sıkıştırmaya benzer bir işlemdir.
  - Shannon'a göre entropi, sembol başına gereken en az bit sayısını belirler. Aritmetik kodlama, bilinen bir dağılımda bütün diziye tek bir değer atayarak entropiye yakın sıkıştırma yapar.
  - Dağılım bilinmediğinde PPM gibi bağlam (k-gram) tabanlı dinamik modeller kullanılır. $k$ arttıkça hesaplama maliyeti üstel artar; bu yüzden $k$ sınırlanır ve uzun vadeli ilişkiler yakalanamaz. RNN'ler uzun vadeli ilişkileri yakalamada ve sonraki sembolü tahmin etmede başarılıdır.
  - Mimari iki bloktan oluşur: **RNN olasılık tahmin bloğu** (önceki bütün sembollerin gizli bilgisini tutar, sonraki sembolün olasılık dağılımını verir) ve **aritmetik kodlama bloğu** (o anki sembole göre aralığı daraltır). Softmax katmanlı herhangi bir RNN yapısı kullanılabilir: Vanilla RNN, LSTM ya da GRU (ekrandan, 00:10:00).
  - Kodlayıcı ve kod çözücü aynı sembol için aynı dağılımı üretmeli, ağırlıklar iki tarafta aynı biçimde güncellenmelidir (ekrandan, 00:10:00).
  - İlk sembol için RNN henüz bir şey öğrenmediğinden varsayılan (default) bir dağılım kullanılır; bu, PPM'de bilinmeyen sembol için $1/|\text{alfabe}|$ kullanılmasına benzer (ekrandan, 00:13:20).
  - Aritmetik kodlama bir sonlu durum makinesine benzetilir: mevcut aralık durumdur, gelen sembol durumu değiştirir.
  - İki model: DeepZip-ChGRU (GRU tabanlı, karakter girdili) ve DeepZip-Feat (son belirli sayıda elemandan, örneğin son 20 elemandan bağlam sayımlarına dayalı özellik çıkarır).
  - Sentetik veri: i.i.d. kaynaklar (kolay) ve Markov-$k$ kaynakları, $X(n) = X(n-1) + X(n-k) \bmod M$ (ekrandan, 00:14:45). $k$ büyüdükçe bağımlılık uzar, veri zorlaşır. Gerçek veri: PSRN-m-n (sözde rastgele sayılar), Hutter Prize (metin), Enwiki9 (XML), HGP-Chr1 (insan genomu).
  - Klasik RNN karmaşık verilerde kaybolan gradyan sorunuyla erken karşılaşır (altyazıda Markov-35). GRU daha uzun dayanır, DeepZip-Feat ise ancak Markov-140 düzeyinde sıkıştıramaz hale gelir (ekrandan, 00:17:05).
  - Genom veri setinde literatürdeki en iyi sıkıştırıcıdan daha iyi sonuç alındı; metin veri setlerinde en iyi sıkıştırıcı geçilemedi.
- Sunum 2: FastText.zip, metin sınıflandırma modelinin sıkıştırılması
  - FastText, Facebook'un metin sınıflandırma kütüphanesidir. Amaç doğruluğu düşürmeden modelin bellek ve saklama maliyetini düşürmektir; burada sıkıştırılan metin değil, metni sınıflandıran modeldir.
  - **Product quantization:** belgeler ya da cümleler yüksek boyutlu vektörlerle temsil edilir; vektörler kümelere ayrılır ve her küme bir kod kitabı (codebook) merkeziyle temsil edilir (ekrandan, 00:25:20).
  - **Retraining:** model nicemlenir, nicemlenmiş modelle yeniden eğitilir, sonra tekrar nicemlenir.
  - **Pruning (budama):** sözlüğün büyük kısmı bilgi değeri düşük kelimelerdir. Feature selection ile $K$ adet kelime ya da n-gram seçilir ve sözlük küçültülür. Seçim **norm** değerine göre yapılır (ekrandan, 00:30:00).
  - Sorun: seçilen $K$ kelime her belgede bulunmayabilir. Çözüm: belgedeki en yüksek norm değerine sahip kelime sözlüğe eklenir (ekrandan, 00:30:00).
  - Hashing ile ek olarak 1-2 MB kazanç sağlanır.
  - Büyük veri setinde (ekrandan, 00:35:50) sıkıştırılmamış model %45,4 doğruluk ve 12 GiB boyuttadır; yalnız girdi matrisi nicemlendiğinde %45,0 doğruluk ve 1,7 GiB'a inilir; norm ve retraining ile %45,5'e çıkılır; girdi ve çıktı matrisleri birlikte nicemlendiğinde 1,5 GiB'a inilir.
- Sunum 3 ve 4: Fraktal görüntü sıkıştırma (iki öğrenci aynı makaleyi sundu)
  - İlk sunum İngilizce yapıldı ve altyazı büyük ölçüde anlamsız; içerik slaytlardan alındı. İkinci sunum aynı makaleyi Türkçe ayrıntılı anlattı.
  - Fotokopi makinesi benzetmesi: görüntüyü yarıya küçültüp üç kez çoğaltan bir makinenin çıktısı tekrar tekrar girdi olarak verilirse, sonuç başlangıç görüntüsünden bağımsız sabit bir görüntüye yakınsar. Değişen yalnız konum ve yöndür.
  - Dönüşümler düzlemin **afin dönüşümleridir** (ekrandan, 01:24:40):
    $w_i\begin{bmatrix}x\\y\end{bmatrix} = \begin{bmatrix}a_i & b_i\\ c_i & d_i\end{bmatrix}\begin{bmatrix}x\\y\end{bmatrix} + \begin{bmatrix}e_i\\ f_i\end{bmatrix}$. Eğme, uzatma, döndürme, ölçekleme ve öteleme yapabilirler.
  - Her dönüşüm 6 sayıyla tanımlanır. 4 dönüşüm × 6 sayı × 32 bit = 768 bit yeterken aynı görüntüyü piksel olarak saklamak en az 65.536 bit ister (ekrandan, 01:26:25).
  - **Büzücü (contractive) dönüşüm:** $d(w(P_1), w(P_2)) < s\, d(P_1, P_2)$, $s < 1$; dönüşümden sonra iki nokta arasındaki uzaklık azalır (ekrandan, 01:28:30). **Sabit nokta teoremi:** büzücü bir dönüşüm tekrar tekrar uygulanınca tek bir sabit noktaya yakınsar.
  - Kod çözülmüş görüntünün doğal bir boyutu yoktur; her ölçekte çözülebilir. Büyük ölçekte üretilen ayrıntı gerçek değildir, dönüşümlerin ürünüdür.
  - Kodlama: 256 gri seviyeli 128×128 görüntü **range image**; ortalama alınarak (aşağı örnekleme ve alçak geçiren süzme) elde edilen 64×64 görüntü **domain image** olur. İkisi 4×4 bloklara bölünür (ekrandan, 00:45:10). Her domain bloğu $\alpha D_{i,j} + t_0$ ile dönüştürülür, $\alpha \in [0,1]$, $t_0 \in [-255, 255]$ tam sayı (ekrandan, 01:34:50). Her range bloğuna bozulma ölçüsüne göre en yakın dönüştürülmüş domain bloğu atanır; koordinatlar ve $\alpha$, $t_0$ fraktal kod kitabına yazılır.
  - Kod çözme: kod kitabındaki dönüşümler herhangi bir başlangıç görüntüsüne yinelemeli olarak uygulanır.
  - Sonuçlar (ekrandan, 01:37:05): 2×2 blok ile 16.384 bayt kod kitabı, 27 dB SNR, 1 bayt/piksel; 4×4 blok ile 6.144 bayt, 21 dB SNR, 0,375 bayt/piksel. Küçük bloklar yüksek SNR ama düşük sıkıştırma oranı, büyük bloklar yüksek sıkıştırma ama ayrıntı kaybı verir (ekrandan, 00:50:00).
- Sunum 5: RNN'lerle tam çözünürlüklü görüntü sıkıştırma (Google Research)
  - Önceki bir çalışma yalnız 32×32 görüntülerle sınırlıydı; klasik otokodlayıcılarda darboğaz (bottleneck) sabit olduğundan sıkıştırma oranı sabittir. Bu çalışma farklı boyutlarda görüntüleri değişken oranla sıkıştırmayı hedefler.
  - Ağ, kodlayıcı $E$, ikilileştirici (binarizer) $B$ ve kod çözücü $D$'den oluşur; $E$ ve $D$ tekrarlayan bileşenler içerir (ekrandan, 01:45:00).
  - Yinelemeli şema (ekrandan, 01:45:00): $b_t = B(E_t(r_{t-1}))$, $\hat{x}_t = D_t(b_t) + \gamma \hat{x}_{t-1}$, $r_t = x - \hat{x}_t$, $r_0 = x$, $\hat{x}_0 = 0$. $\gamma = 0$ one-shot, $\gamma = 1$ additive yeniden yapılandırmadır.
  - Üçüncü çerçeve **residual scaling**: kazanç faktörü $g_t$ beş katmanlı bir evrişimli ağla tahmin edilir, artık bu kazançla ölçeklenir. ELU'nun aralığı $(-1, \infty)$ olduğundan çıkışa +2 eklenerek $g_t \in (1, \infty)$ elde edilir (ekrandan, 01:50:00).
  - RNN türleri: LSTM, Associative LSTM, GRU ve Residual GRU. 4 mimari × 3 çerçeve = 12 deney; en iyi 8'i raporlandı.
  - Entropi kodlaması için ikili bir RNN mimarisi önerildi: tek yinelemeli (single iteration) ve aşamalı (progressive) entropi kodlayıcı.
  - Eğitim verisi: 32×32 veri seti ve 1280×720 görüntülerin parçalarından PNG'nin en kötü sıkıştırdıkları seçilerek kurulan **yüksek entropili** veri seti.
  - Ölçütler MS-SSIM ve PSNR-HVS; sıralama, bit oranı eğrisi altındaki alanla (AUC) yapıldı. Test Kodak veri setinde (24 görüntü) yapıldı (ekrandan, 01:54:10).
  - 32×32 veri setinde GRU (One Shot) iki ölçütte de birinci oldu. Yüksek entropili veri setinde LSTM (One Shot) MS-SSIM'de birinci, PSNR-HVS'de sekizinci oldu (ekrandan, 01:54:10). Entropi kodlamalı modeller daha iyi sonuç verdi ve seçilen modeller JPEG'den iyi çıktı.

## Hocanın Özellikle Vurguladığı Kısımlar

- RNN'de olasılıklar önceden hazırlanmaz
  - Hoca, DeepZip'te olasılıkların metin ilerledikçe RNN içinde değiştiğini, önceden çıkarılmış bir olasılık tablosu olmadığını özetledi. "Zor veri seti" ile ne kastedildiğini sordu; cevap, ilişkilerin daha uzaktaki elemanlarla kurulduğu, örüntüsü öğrenilmesi zor verilerdi.
  - Çalışma sürelerinin makalede verilip verilmediğini sordu; verilmemişti.
- Kod kitabı bir tür sözlüktür
  - Product quantization'daki codebook için hoca "sözlük" karşılığını önerdi; ancak anlamlı kelimelerden değil kod dizilerinden oluşan bir sözlüktür.
- Entropi ve kelime sıklığı
  - Sık geçen kelimeler (the, and gibi) düşük entropiyle daha az bitle kodlanır; nadir kelimeler daha fazla bit ister. Hoca makalenin entropiyi nasıl hesapladığını sordu; makalede formül yoktu. Tablodaki entropi ve norm sütunları değer değil, sıralama (ranking) idi.
- Fraktal sıkıştırma kayıplıdır
  - Hoca fraktal sıkıştırmanın kayıplı mı kayıpsız mı olduğunu sordu; cevap kayıplı, ancak kayıplar göze batmıyor oldu.
  - "Sözleşmeli dönüşüm" çevirisinin İngilizcesinin contractive (büzücü) olduğu netleştirildi.
- ELU
  - Hoca ELU'nun Exponential Linear Unit olduğunu belirtti.
- Görsel karşılaştırmada insan gözü
  - JPEG ile yöntemin 0,25 ve 1 bit/piksel karşılaştırmasında hoca, yöntemin çıktısında da bozulma gördüğünü söyledi. Yayın yöntemin daha iyi olduğunu iddia etse de görsel değerlendirme kişiden kişiye değişir.

## Kısa Tekrar Notları

- İyi tahmin = iyi sıkıştırma. DeepZip: RNN olasılık tahmini + aritmetik kodlama; kodlayıcı ve çözücü aynı dağılımı üretmeli, ilk sembolde varsayılan dağılım kullanılır.
- PPM gibi k-gram modellerinde $k$ büyüdükçe maliyet üstel artar; RNN uzun vadeli bağımlılıkları yakalar.
- Markov-$k$: $X(n) = X(n-1) + X(n-k) \bmod M$; $k$ büyüdükçe veri zorlaşır.
- FastText.zip: product quantization, retraining, norm tabanlı pruning ve hashing ile model 12 GiB'tan 1,5-1,8 GiB düzeyine iner, doğruluk yaklaşık korunur.
- Fraktal sıkıştırma: afin ve büzücü dönüşümler, sabit nokta teoremi, range/domain blokları, kayıplı ve çözünürlükten bağımsız kod çözme.
- Küçük fraktal bloklar: yüksek SNR, düşük sıkıştırma; büyük bloklar: yüksek sıkıştırma, ayrıntı kaybı.
- RNN görüntü sıkıştırma: $E$, $B$, $D$; artık $r_t = x - \hat{x}_t$ yinelemeli kodlanır; one-shot, additive ve residual scaling çerçeveleri; MS-SSIM ve PSNR-HVS AUC ile değerlendirme.

## Detaylı Açıklamalar

- DeepZip'te kodlama ve kod çözme akışı (ekrandan, 00:13:20)
  - Kodlayıcı tarafında ilk sembol $S_0$ varsayılan dağılımla aritmetik kodlanır. $S_0$ RNN'e verilir; RNN $S_1$ için bir dağılım üretir ve $S_1$ bu dağılımla kodlanır. Böylece her adımda hem RNN'in durumu hem de aritmetik kodlayıcının aralığı güncellenir ve sonunda sıkıştırılmış veri elde edilir.
  - Kod çözücü de varsayılan dağılımla başlar ve $S_0$'ı çözer. Çözülen $S_0$ kod çözücünün RNN'ine verilir; RNN kodlayıcıdakiyle aynı dağılımı üretir, bu dağılımla $S_1$ çözülür. İki tarafın aynı dağılımı üretmesi, ağırlıkların iki tarafta aynı biçimde güncellenmesine bağlıdır.
- DeepZip sonuç tablosu (ekrandan, 00:17:05)
  - 100 MB'lık Markov kaynaklarında DeepZip-ChGRU Markov-20'de 200 KB, Markov-30'da 1 MB, Markov-50'de 30 MB üretir, Markov-80'den itibaren sıkıştıramaz (100 MB). DeepZip-Feat Markov-50'de 500 KB, Markov-80'de 2 MB, Markov-100'de 38 MB üretir, Markov-140'ta sıkıştıramaz. GZIP ve uyarlamalı aritmetik kodlama (CABAC) çok daha erken başarısız olur.
  - Sunan öğrenciye göre sıkıştırmanın kolaylığı verinin öğrenilmesinin kolaylığıyla ilgilidir; bu yüzden iyi sınıflandırıcılar ve iyi tahmin modelleri sıkıştırmada da başarılıdır.
- FastText.zip'te pruning tablosu (ekrandan, 00:30:00)
  - Tablonun solunda entropi sıralamasına göre ilk on kelime (".", ",", "the", "and", "i", "a", "to", "it", "of", "this"), sağında norm sıralamasına göre ilk on kelime (mediocre, disappointing, so-so, lacks, worthless, dreadful, drm, poorly, uninspired, worst) yer alır. Norm sıralamasında öne çıkan kelimeler, büyük olasılıkla bir film yorumu veri setinde, sınıflandırmada en ayırt edici kelimelerdir.
  - Gelecek çalışma önerisi olarak entropi ve norm sıralamalarının birleştirilmesi anılmıştır.
- Fraktal sıkıştırmada sıkıştırma oranının ölçülmesi
  - Görüntü her ölçekte çözülebildiği için oran ölçmek zordur. Lena görüntüsünün 5,7:1 sıkıştırılmış hali, orijinalin 4 katı boyutta çözülürse 16 kat fazla piksel içerir; böylece oran $5{,}7 \times 16 = 91{,}2:1$ gibi görünür. Ancak büyütülmüş görüntüdeki ayrıntı gerçek olmadığı için bu bir tür hiledir.
- Fraktal sıkıştırmanın uygulama alanları
  - Yakınlaştırmada görüntü kalitesinin fazla bozulmaması, tıbbi görüntüleme ya da güvenlik görüntülerinde ayrıntıya odaklanma gibi uygulamalarda avantaj sayıldı. Sabit blok boyutu yöntemin zayıflığıdır; Lena'daki gözler gibi kodlanması zor bölgeler için blok boyutu hataya göre ayarlanmalıdır.
- RNN görüntü sıkıştırmasında kodlayıcı ve kod çözücü yapısı
  - Altyazıya göre girdi önce bir evrişim katmanından, sonra üç RNN katmanından geçer ve ikilileştiriciye gelir. Kod çözücü tarafında bir evrişim, dört RNN katmanı ve son bir evrişim katmanıyla $\hat{x}$ elde edilir. Bu bir yinelemedir; yineleme sayısı (unroll) 16 olarak alınmıştır.
  - Yüksek entropili veri seti, PNG'nin sıkıştırmada zorlandığı parçalardan kurulur; amaç ağı en zor görüntülerle eğitmektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
