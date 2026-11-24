# Ders 13 Çalışma Özeti

## Genel Konular

- Proje sunumları (dönemin son dersi)
  - Bu derste üç öğrenci, bilgisayarla görme alanındaki güncel birer konferans makalesini sundu: DeepEMD ile az örnekli (few-shot) sınıflandırma, kuş bakışı görüntülerden dinamik trafik modelleme ve tek görüntüden derinlik kestirimi (Semantic Divide-and-Conquer Network).
  - Projeler, farklı problem türlerini, kullanılan veri setlerini ve uygulama alanlarını görmek açısından faydalı bulundu.
- Az örnekli sınıflandırma (few-shot classification)
  - Derin öğrenme çok veri ister; az veriyle öğrenme, insanın daha önce gördüklerinden yararlanıp yeni bir nesneyi birkaç örnekle tanımasından esinlenir.
  - Terimler: "N-way K-shot" görevinde N ayrılacak sınıf sayısı, K her sınıftaki eğitim örneği sayısıdır (örneğin 5-way 2-shot: 5 sınıf, sınıf başına 2 örnek). Eğitim örneklerine destek kümesi (support set), test örneklerine sorgu kümesi (query set) denir.
  - Dört ana yaklaşım (ekrandan, 00:15:00): Matching Network, Prototypical Network, Relation Network, Model-Agnostic Meta-Learning (MAML).
    - Matching Network: resimler öznitelik vektörüne çevrilir, kosinüs, Öklid ya da EMD gibi bir ölçüyle karşılaştırılır; en az farklı destek resminin sınıfı seçilir.
    - Prototypical Network: her sınıfın destek vektörlerinin ortalaması (prototip) alınır, test resmi en yakın prototipin sınıfına atanır.
    - Relation Network: destek ve test öznitelikleri birleştirilip (concatenate) bir ilişki modülünden geçirilir; slayttaki $r_{i,j} = g_\phi(\mathcal{C}(f_\varphi(x_i), f_\varphi(x_j)))$ değeri sigmoid ile $(0,1)$ aralığına sınırlanır (ekrandan, 00:15:00).
- DeepEMD (Differentiable Earth Mover's Distance)
  - Metrik tabanlı bir yöntemdir: önceden eğitilip dondurulmuş bir CNN (ResNet-12 omurga) öznitelik çıkarır, iki resmin farkı EMD ile ölçülür.
  - Sezgi: iki köpek resmi bloklara bölünüp baş başla, bacak bacakla eşleştirilirse küresel bir karşılaştırmadan daha iyi sonuç alınır. EMD yerel öznitelikler arasında bu eşleştirmeyi yapar.
  - EMD, bir dağılımı diğerine en az maliyetle taşıma problemidir ve doğrusal programlama ile çözülür; makalede OpenCV'nin çözücüsü kullanılmış.
  - Çapraz referans (cross-reference) mekanizması: ortalama öznitelikle karşılaştırılan, yüksek varyanslı arka plan bölgelerine düşük ağırlık, nesnenin ayırt edici bölgelerine yüksek ağırlık verir.
  - Yapılandırılmış tam bağlantılı katman (Structured FC): destek kümesinde birden çok resim varsa her sınıf için bir ortalama yapı öğrenilir; test resmi her sınıfla EMD üzerinden karşılaştırılır, en düşük EMD'li sınıf seçilir.
- Kuş bakışı görüntülerden dinamik trafik modelleme
  - Amaç: uydu/havadan görüntülerden yolu, yol üzerindeki akış yönünü ve gün içindeki saate göre trafik hızını tahmin etmek; az ya da gürültülü verili bölgelerde de çalışmak ve şehir geneline genelleştirmek (ekrandan, 00:40:00).
  - Benzer çalışmalar: şehirlerarası bölütleme (her şehir kendi test setinde yüksek, başka şehirde düşük, tüm şehirlerle yaklaşık %50 doğruluk; ekrandan, 00:35:00), yol özelliklerinden ortalama hız kestirimi, optik akış ile araç hızı kestirimi.
  - Veri: New York için açık Uber verisi (GPS noktası, hız, yön, zaman) ve OpenStreetMap yol eşlemesi; altyazıya göre yaklaşık 292 milyon kayıt, 22 GB.
  - Mimari: CNN tabanlı çok görevli ağ. Yol tespiti piksel başına ikili sınıflandırma (sigmoid), yön tespiti $K$ yön kutusu üzerinde softmax, hız tespiti softplus aktivasyonu ile; görüntüye konum ve zaman girdileri de eklenir.
- Tek görüntüden derinlik kestirimi (SDC-Depth)
  - Tek görüntüden derinlik kötü tanımlanmış (ill-posed) bir problemdir; nesnenin görüntüdeki boyutu bağlama ve perspektife bağlıdır. Stereo görüntüde iki görüntünün farkından derinlik bulunabilir.
  - Önceki yaklaşımlar: Markov Random Fields ve Conditional Random Fields (ekrandan, 00:55:00), tam evrişimli residual ağlar, stereo çiftlerle gözetimsiz eğitim, sentetik veriyle eğitip GAN ile gerçek görüntülere aktarım.
  - Model dört parçadır (ekrandan, 01:00:00): omurga (Feature Pyramid Network), bölütleme modülü (anlamsal + örnek bölütleme), kategori ve örnek bazında derinlik kestirimi, derinlik birleştirme.
  - Her kategori ve her örnek için önce $[0,1]$ aralığında normalize "kanonik" derinlik bulunur; ikinci bir dal (GAP + FC ya da RoIAlign + FC) bunu gerçek ölçeğe çeviren ölçek ve kayma katsayılarını öğrenir.
  - Kayıp $L = \alpha_I L_I + \alpha_S L_S + \alpha_D L_D$ (ekrandan, 01:10:00).
  - Veri setleri: Cityscapes, Depth in the Wild (göreli derinlik notları), NYU Depth (iç mekan, stereo/derinlik algılayıcı).

## Hocanın Özellikle Vurguladığı Kısımlar

- RMSE yüzde değildir
  - Kök ortalama kare hata, tahmin edilen büyüklükle aynı birimdedir. Trafik hızı tahmininde 10.66 RMSE, büyük olasılıkla ortalama yaklaşık 10 km/sa sapma demektir ve şehir içi trafik için yüksek bir hatadır.
- Sonuç tablolarını dikkatle okumak
  - DeepEMD grafiğinde en iyi eğrinin (EMD+SFC) yanında EMD+Fusion eğrisinin diğerlerinin altında kalması dikkat çekici bulundu.
  - Farklı veri setlerindeki başarı farklarının sebebi (sınıf sayısı, veri setinin zorluğu) sorgulanmalıdır.
- Tek kamerayla derinlik
  - Tek kamerayla derinlik bulmak zor bir problemdir; bu tür çalışmalarda genelde stereo kamera kullanılır, stereo görmenin de kendine göre zorlukları vardır.

## Kısa Tekrar Notları

- N-way K-shot: N sınıf, sınıf başına K destek örneği; support set eğitim, query set test içindir.
- Prototypical Network sınıf ortalamasını prototip olarak kullanır; Matching Network tek tek resimleri karşılaştırır.
- EMD: bir dağılımı diğerine en az "iş" ile taşımanın maliyeti; doğrusal programlama ile çözülür; iş = akış × uzaklık toplamı, EMD = en küçük iş / toplam akış.
- DeepEMD = EMD + çapraz referans ağırlıkları + yapılandırılmış FC; miniImageNet 5-way 1-shot %65.91, 5-shot %82.41 (ekrandan, 00:30:00).
- Trafik modelleme: yol (sigmoid), yön (softmax), hız (softplus) çok görevli CNN; görüntü + konum + zaman birlikte en iyi sonucu verir.
- SDC-Depth: FPN omurga, anlamsal ve örnek bölütleme, kanonik derinlik + ölçek/kayma dönüşümü, birleştirme.
- smooth L1: $|x|<1$ için $0.5x^2$, diğer durumda $|x|-0.5$.
- Transpoze evrişim (convolution transpose) küçük öznitelik haritasını büyütür (örneğin $2\times2 \rightarrow 4\times4$).
- Ablation çalışması: modelin parçaları tek tek çıkarılarak her parçanın katkısı ölçülür.

## Detaylı Açıklamalar

- **Az örnekli sınıflandırmanın mantığı.** Çocuk konuşmayı binlerce kelime duyarak öğrenir, ama sonra yeni bir kelimeyi iki üç kez duyarak öğrenir. Görmede de bebeklikte milyonlarca görüntü görülür, sonra yeni bir nesne birkaç örnekle tanınır. Few-shot yöntemler de köpek, fil, maymun gibi çok örnekli sınıflarla eğitilmiş bir modeli, eğitimde olmayan lemur, tavşan gibi sınıflara birkaç örnekle genişletir. Metrik tabanlı yöntemlerde öznitelik çıkaran CNN binlerce resimle önceden eğitilip dondurulur; sınıflandırma öznitelikler arası bir uzaklıkla yapılır.

- **Earth Mover's Distance örneği (ekrandan, 00:20:00).** İki dağılım düşünülür: $x$ tarafında ağırlıklar $w_1 = 0.74$, $w_2 = 0.26$; $y$ tarafında $u_1 = 0.23$, $u_2 = 0.51$ (toplam 0.74).
  - En iyi olmayan akış: $f_{21} = 0.23$ ($d_{21} = 292.9$), $f_{12} = 0.51$ ($d_{12} = 252.3$). İş $= 0.23 \cdot 292.9 + 0.51 \cdot 252.3 \approx 196$.
  - En iyi akış: $f_{22} = 0.26$ ($d_{22} = 198.2$), $f_{11} = 0.23$ ($d_{11} = 155.7$), $f_{12} = 0.25$ ($d_{12} = 252.3$). İş $= 0.26 \cdot 198.2 + 0.23 \cdot 155.7 + 0.25 \cdot 252.3 \approx 150.4$.
  - Hafif dağılımın toplam ağırlığı 0.74 olduğundan $\mathrm{EMD}(x,y) = 150.4 / 0.74 \approx 203.3$. (Değerler python ile doğrulandı.)
  - Sunumdaki benzetme: Edirne ile İstanbul arası mesafe genelde iki nokta arası mesafe olarak söylenir; oysa iki şehir de alana yayılmış birer dağılımdır. "İstanbul'daki bütün toprağı Edirne'ye en az maliyetle nasıl taşırım?" sorusunun cevabı EMD'dir.

- **DeepEMD sonuçları (ekrandan, 00:25:00 ve 00:30:00).** 5-way k-shot grafiğinde EMD+SFC (kırmızı) bütün shot sayılarında en üstte, yaklaşık %73'ten %90'ın üstüne çıkıyor; EMD+Fusion (mavi) 10 shot'tan sonra en altta kalıyor. Tablolarda ResNet-12 omurgayla: miniImageNet 1-shot $65.91 \pm 0.82$, 5-shot $82.41 \pm 0.56$; tieredImageNet $71.16 \pm 0.87$ ve $86.03 \pm 0.58$; Fewshot-CIFAR100 $46.47 \pm 0.78$ ve $63.22 \pm 0.71$; Caltech-UCSD Birds-200-2011 $75.65 \pm 0.83$ ve $88.69 \pm 0.50$.
  - Makalede EMD, yapılandırılmış sınıflandırıcı ve çapraz referans ayrı ayrı denenmiş; her biri başarımı artırıyor, üçü birlikte en yüksek sonucu veriyor.

- **Trafik modellemede kayıplar ve sonuçlar.** Yol için piksel başına ikili sınıflandırma kaybı; görüntülerdeki örtüşmeler (overlap) de kayba katılıyor. Yön için her piksel $K$ yön açısına softmax olasılığı verir; en olası açı akış yönüdür. Çift yönlü yollarda her yön için ayrı hız gerekir. Hız tek piksel yerine yol bölümü üzerinden bölgesel ortalama ile hesaplanır. Hız tahmini tablosunda (ekrandan, 00:45:00) yol ve yön görevlerinin ikisi de kullanıldığında RMSE 10.66, MAE 8.10, $R^2 = 0.464$ en iyi sonuçtur (hiçbiri yokken 10.87 / 8.35 / 0.442). Isı haritalarında sabah saatlerinde trafiğin şehre yayıldığı, öğlen merkezde kaldığı görülüyor.

- **SDC-Depth ayrıntıları.** Omurga 50 katmanlı ResNet üzerine FPN'dir: derin, düşük çözünürlüklü katman büyütülür, alttaki katman $1\times1$ evrişimden geçirilip toplanır, ardından bir evrişim daha uygulanır; çıkışların derinliği 256 seçilmiş. Kategori dalında yerel dal her kategori için $[0,1]$ derinlik verir; GAP + FC dalı bir ölçek ($w_c$) ve kayma ($b_c$) bularak bunu gerçek ölçeğe çevirir. Örnek dalında Mask R-CNN ve RoIAlign kullanılır (ekrandan, 01:05:00). Birleştirmede her örnek haritası maskesi ve kategori olasılığıyla ağırlıklanıp kategori haritasına eklenir, normalize edilir, kategoriler olasılıklarıyla birleştirilerek son derinlik bulunur. <!-- BELİRSİZ: birleştirme formülünün tam biçimi karede görülmedi -->
  - Örnek kaybı $L_I = L_{class}(p,u) + \lambda[u \ge 1] L_{loc}$; $L_{class} = -\log p_u$; $L_{loc} = \sum_{i \in \{x,y,w,h\}} \mathrm{smooth}_{L_1}(t_i^u - v_i)$ (ekrandan, 01:10:00). Anlamsal kayıp piksel başına sınıf sayısı derinliğinde bir çıkış üzerinde logaritmik kayıptır; derinlik kaybı doğrudan farka bakar. Katsayıların eşit (yaklaşık 0.33) seçilebileceği söylendi.
  - Değerlendirme ölçütleri: RMSE ve kare göreli hata (squared relative error). Depth in the Wild'da 495 000 görüntü, iki nokta arasında hangisinin daha yakın olduğu notlanmış (ekrandan, 01:15:00); semantik bölütleme için COCO kullanılmış.

- **Öğrencinin kendi denemesi (ekrandan, 01:20:00).** NYU Depth verisi ve önceden eğitilmiş ResNet50 ile FPN benzeri bir kod çözücü kurulmuş: $640\times480$ girişte ara bloklardan gelen öznitelikler büyütülüp (upsample) evrişimden geçirilerek toplanmış, sonda transpoze evrişimle tam çözünürlüğe çıkılmış. ResNet50'nin son blok çıkışı $20\times15$'tir ($640/32$, $480/32$). Eğitim kaybı düşerken doğrulama kaybı 5-6. epoktan sonra değişmemiş; FPN yapısı eklenince çıktı daha az bloklu olmuş, ama gerçek derinlik haritasından hâlâ uzak. Model yaklaşık 3 milyon, makaledeki model yaklaşık 50 milyon parametreli.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
