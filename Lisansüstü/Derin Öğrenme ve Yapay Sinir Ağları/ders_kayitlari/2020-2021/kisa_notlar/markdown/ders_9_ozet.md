# Ders 9 Çalışma Özeti

## Genel Konular

- Derin öğrenmeye giriş ve yapay sinir ağlarıyla ilişkisi
  - Derin öğrenme yapay sinir ağlarının daha gelişmiş bir biçimidir. Nöronlar, onları bağlayan ağırlıklı bağlantılar, bir grup girdi, giderek karmaşıklaşan hesaplamalar ve problemi çözen bir çıktı burada da vardır (ekrandan, 00:15:00).
  - Öğrenmenin mantığı aynıdır; değişen başlıca şey aktivasyon fonksiyonudur (ReLU). Konvolüsyonel ağlarda aktivasyonun yanında filtreler kullanılır.
  - Derin ağlarda her nöronun bir sonraki katmandaki her nörona bağlı olması gerekmez (özellikle CNN'de) ve nöron sayısını azaltan teknikler uygulanabilir.
  - Derin ağlara geçişi sağlayan iki gelişme: geri yayılımdaki gradyan kaybolması probleminin çözülmesi ve GPU'ların ortaya çıkması.
- Doğrusal olmama (non-linearity) ve problem türü
  - Elimizdeki problemler çok boyutlu ve doğrusal olmayan problemlerdir. Parametreler arasındaki ilişki doğrusal olmadığı için doğrusal denklem sistemleriyle çözülemez; bütün parametrelerin aynı anda optimize edilmesi gerekir.
  - Slaytta öne çıkan terimler: Deep Belief Nets, Convolutional Nets, Backpropagation, non-linearity, Image recognition (ekrandan, 00:05:00).
- Derin öğrenmenin uygulama alanı ve tarihçesi
  - Alanın öncü isimleri: Andrew Ng, Geoffrey Hinton, Yann LeCun, Yoshua Bengio, Andrej Karpathy.
  - Büyük firmalar yatırım yaptı: Google 400 milyon dolar, Apple sürücüsüz araç, NVIDIA GPU, Toyota 1 milyar dolar yapay zekâ araştırma yatırımı (ekrandan, 00:10:00).
- Sınıflandırma ve terminoloji
  - Sinir ağları, bir nesnenin en az iki farklı kategoriden birine düşebildiği sınıflandırma işlerinde kullanılır (ekrandan, 00:20:00).
  - Girdiler, sınıflandırılacak nesnenin özellikleridir (ör. boy, kilo, ateş ile hasta/sağlıklı ayrımı).
  - Derin öğrenmede hata yerine sıklıkla "skor" ve "maliyet (cost)" terimleri kullanılır.
  - Eğitim, doğru bağlantı ağırlıkları kombinasyonunu bulma işidir.
- Derin öğrenme ne zaman kullanılmalı?
  - Basit problem (az parametre, az sınıf, az örnek): lojistik regresyon, SVM, Naive Bayes gibi klasik yöntemler yeterlidir.
  - Orta karmaşıklık (daha çok özellik, ikiden fazla sınıf): derin ağlar daha başarılıdır, ama kaynaklara göre SVM de düşünülebilir.
  - Karmaşık problem: derin ağlar en mantıklı, çoğu zaman tek seçenektir.
- Karmaşık örüntülerin katman katman işlenmesi (yüz tanıma örneği)
  - 1. katman piksellerin açık/koyu durumunu, 2. katman kenarları ve basit şekilleri, 3. katman daha karmaşık şekil ve nesneleri (göz, burun, dudak), 4. katman bunların yüzü tanımlamak için nasıl birleştiğini öğrenir (ekrandan, 00:25:00 ve 00:30:00).
  - Basit örüntüleri yapı taşı olarak kullanıp karmaşık örüntüleri bulmak derin ağlara gücünü verir.
  - Bu bakış, görüntü işleme filtrelerini kullanan konvolüsyonel ağların çıkış noktasıdır.
- Model seçimi: veri etiketli mi?
  - Etiketsiz veri (gözetimsiz öğrenme): otokodlayıcılar ve Kısıtlı Boltzmann Makineleri (RBM). Özellik çıkarma ve örüntü tanımada kullanılır.
  - Etiketli veri (gözetimli öğrenme) (ekrandan, 00:35:00): metin işleme için RNTN ve tekrarlayan ağlar; görüntü tanıma için DBN ve konvolüsyonel ağ; nesne tanıma için RNTN ve konvolüsyonel ağ; konuşma tanıma için tekrarlayan ağ.
  - Genel (ekrandan, 00:40:00): sınıflandırma için MLP/ReLU ve Deep Belief Net; zaman serisi analizi için tekrarlayan ağ.
- Gradyan kaybolması ve patlaması (vanishing/exploding gradient)
  - Eğitim sırasında sürekli bir maliyet değeri hesaplanır; gradyan, maliyetin ağırlık ya da bias'a göre değişim hızıdır (ekrandan, 00:45:00).
  - Slayta göre 2006'ya kadar derin ağlar bu temel problem nedeniyle doğru eğitilemiyordu.
  - Zincir kuralıyla $n$ katmanlı ağda ön katmanların gradyanı $n$ tane küçük sayının çarpımıyla hesaplanır; gradyan $n$ ile üstel olarak azalır, ön katmanlar çok yavaş öğrenir (ekrandan, 01:10:00).
  - Tanh gibi geleneksel aktivasyonların gradyanları $(-1, 1)$ ya da $[0, 1)$ aralığındadır. Türevi büyük değer alabilen fonksiyonlar kullanılırsa bu kez gradyan patlaması ortaya çıkar.
  - ReLU kullanımı iki problemi büyük ölçüde çözer.
- Kısıtlı Boltzmann Makinesi (RBM)
  - Geoffrey Hinton'ın (Toronto Üniversitesi) önerdiği iki katmanlı yapı: görünür katman ve gizli katman (ekrandan, 01:15:00).
  - "Kısıtlı" olması, aynı katmandaki nöronlar arasında bağlantı olmamasıdır.
  - Eğitim üç adımlıdır: ileri geçiş, geri geçiş (yeniden oluşturma) ve karşılaştırma. Karşılaştırma KL ıraksaması ile yapılır (ekrandan, 01:20:00).
  - Veri etiketlenmek zorunda değildir; RBM önemli özellikleri kendisi çıkarır, bir tür otokodlayıcı ve özellik çıkarıcıdır (ekrandan, 01:25:00).
- Kullback-Leibler (KL) ıraksaması
  - İki olasılık dağılımı arasındaki farkı ölçer; simetrik değildir ve gerçek bir uzaklık ölçüsü (metrik) değildir (ekrandan, 01:40:00).
- Derin İnanç Ağı (DBN)
  - Çok sayıda gizli katmanı olan, tam bağlı bir MLP'ye benzer; arka arkaya dizilmiş RBM'ler gibi düşünülür.
  - Ön eğitim: katmanlar ikişer ikişer RBM gibi eğitilir (1-2, sonra 2-3, ...). Her RBM katmanı girdinin tamamını öğrenir (ekrandan, 01:30:00).
  - İnce ayar: az miktarda etiketli veriyle gözetimli öğrenme yapılır (ekrandan, 01:35:00).
- Konvolüsyonel sinir ağları (CNN)
  - Fener benzetmesi: duvar dijital görüntüdür; her fener aynı örüntüyü görüntünün farklı bölgesinde arar; fenerler birlikte bir filtre oluşturur (ekrandan, 01:45:00).
  - Aynı filtredeki nöronların ağırlıkları birbirinin aynısıdır.
  - Temel katmanlar: konvolüsyon katmanı, ReLU katmanı, havuzlama (pooling) katmanı ve tam bağlı (fully connected) katman.
  - CNN geri yayılımla eğitildiği için gradyan kaybolması hâlâ olası bir sorundur; ReLU gradyanı her katmanda aşağı yukarı sabit tutar (ekrandan, 01:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Her probleme derin öğrenme uygulanmamalı
  - Parametre ve veri azsa derin öğrenme iyi bir seçim olmayabilir; klasik yöntemler yeterliyse onlar kullanılmalıdır.
- Kütüphaneleri kullanmak ile mimariyi anlamak farklıdır
  - Kimse sıfırdan yazmıyor, ama bir mimariyi bilinçli seçmek ve hazır eğitilmiş modelleri değiştirebilmek için arkadaki mekanizmayı anlamak gerekir.
- Gradyan kaybolması derin ağların önündeki asıl engeldi
  - İlk katmanlar temel yapı taşlarını (yüzün ana şekli gibi) bulur. Bu katmanlar eğitilemezse sonuç dramatik biçimde bozulur: göz, kaş, burun doğru bulunsa da yüzün ana bloğu yanlış çıkabilir.
- Filtre seçimi
  - İş çok tanımlıysa (yüz tanıma gibi) filtreler tasarlanarak seçilebilir. Değilse temel filtreler katmanlara dağıtılır ve hangisinin kullanılacağına ağın kendisi karar verir; işe yaramayan filtrelerin bağlantıları zayıflar.
- GPU zorunluluğu
  - GPU'nun bir haftada bitirdiği büyük bir eğitimi CPU haftalar ya da aylar içinde yapabilir.
- Okuma önerisi
  - Derin ağ kullanmayı düşünenler Hinton, LeCun ve Bengio'nun 2006-2007 arasındaki ilk makalelerini okumalıdır.

## Kısa Tekrar Notları

- Derin öğrenme = daha çok katmanlı sinir ağı + ReLU + (görüntüde) filtreler.
- Derin ağları mümkün kılan iki şey: gradyan kaybolmasının çözülmesi ve GPU.
- Gradyan = maliyetin ağırlığa ya da bias'a göre değişim hızı.
- Zincir kuralı: $n$ katmanlı ağda ön katman gradyanı $n$ küçük sayının çarpımıdır, üstel olarak küçülür.
- Büyük türevli aktivasyon → gradyan patlaması; ReLU → iki sorun büyük ölçüde çözülür.
- Etiketsiz veri: otokodlayıcı, RBM. Zaman/sıra ilişkisi: tekrarlayan ağ. Görüntü: CNN, DBN. Metin: RNTN, tekrarlayan ağ.
- RBM: iki katman (görünür, gizli), katman içi bağlantı yok; ileri geçiş, geri geçiş, karşılaştırma (KL ıraksaması).
- KL ıraksaması simetrik değildir, metrik değildir.
- DBN: RBM yığını; katmanlar ikişer ikişer ön eğitilir, sonra az etiketli veriyle ince ayar yapılır.
- CNN katmanları: konvolüsyon, ReLU, havuzlama, tam bağlı. Aynı filtrenin nöronları aynı ağırlıkları paylaşır.

## Detaylı Açıklamalar

- Derin öğrenmenin temeli
  - Derin öğrenme yeni bir fikir değildir; sinir ağlarının geçmişi 50 yılı aşar. Uzun süre sahneye çıkamamasının nedeni eğitimin zorluğu ve hesaplama gücünün yetersizliğiydi. Geri yayılım algoritması çok katmanlı ağlarda doğrusal olmayan problemleri çözebiliyordu, ama katman sayısı arttıkça gradyan kaybolması eğitimi engelliyordu. Bu problem ReLU ile aşılıp GPU'lar hesaplama yükünü taşıyabilir hâle gelince derin ağlar yaygınlaştı.
  - Hesaplamaların özü değişmez: bir nörona gelen değer, önceki nöronların çıktılarının bağlantı ağırlıklarıyla çarpılıp toplanmasıdır; bu toplama bir fonksiyon uygulanır ve hesap ileri doğru sürer. Hata, beklenen ile hesaplanan değer arasındaki farkın karesiyle bulunur ve geriye yayılır.
- Gradyan kaybolmasının mekanizması
  - Hatanın her ağırlığa göre kısmi türevi zincir kuralıyla yazılır. Bu açılımda birden çok kısmi türev ve küçük bağlantı ağırlıkları yan yana çarpılır. Geri yayılımda giriş katmanına yaklaştıkça çarpım sayısı artar ve gradyan sıfıra yaklaşır.
  - Ağırlık değişimi "hatanın gradyanı × öğrenme katsayısı × girdi" biçimindeydi. Çarpanlardan biri sıfıra yakınsa ağırlık neredeyse hiç değişmez; o katman eğitilemez. Son katmanlar hatayı düzeltirken ilk katmanlar öğrenemez.
  - Topun yokuştan yuvarlanması benzetmesi: gradyan eğimdir. Eğim dikse top hızlı yuvarlanır (eğitim hızlıdır); eğim küçüldükçe yüzey düzleşir ve top neredeyse kıpırdamaz (öğrenme durur).
  - İki çıktılı bir ağda iki hatanın gradyanı bir düğümde birleşir, önceki katmana katlanarak dağılır; karmaşık bir ağda çok sayıda çarpma işlemi oluşur.
- RBM ve DBN'nin etiketsiz veriyle çalışması
  - RBM'de ileri geçişte girdiler ağırlıklarla çarpılıp gizli katmana aktarılır. Geri geçişte gizli katmandaki aktivasyonlar aynı bağlantılar üzerinden görünür katmana geri gönderilir ve girdi yeniden oluşturulur. Etiket olmadığı için ağ kendi ürettiğiyle kıyaslanır: üretilen gizli değerler aynı girdiyi geri üretebiliyor mu? Bu, çift yönlü bir çağrışım gibidir.
  - İnsan etiketlemesi ön yargı taşır: çimende top oynanan bir görüntüye futbol meraklısı "futbol", doğaya meraklı biri "manzara" diyebilir. RBM gibi bir yapı görüntüde oransal olarak neyin ağır bastığını daha sağlıklı bulabilir.
  - DBN'de 1. ve 2. katman RBM gibi eğitildiğinde 2. katman 1. katmanın önemli özelliklerini taşır; artık 1. katmanı dikkate almak gerekmez. Bu yüzden hata en sondan en başa kadar yayılmaz ve hesap yükü azalır. Sonuç, yavaş yavaş odaklanan bir kamera gibidir: önce bulanık, temel özellikler; sonra ayrıntılar.
  - DBN'nin çıktısına sonradan istenen etiket atanabilir; çıktı özelliklerden geldiği için sayısal olarak özgündür ve bilgiyi zaten taşır.
- CNN'in yapısı
  - Fener benzetmesinde 8 × 6'lık bir fener ızgarası bir filtreyi temsil eder. Filtre 2, filtre 3, filtre 4 eklenince 8 × 6 × 4'lük bir konvolüsyonel katman elde edilir. Her filtre farklı bir örüntüyü (kenar, renk, belirli şekiller) arar; ışık dairelerinin kesişimleri ortak bağlanılan nöronlardır.
  - ReLU katmanı gradyan kaybolmasını azaltır. Havuzlama katmanı ReLU çıktısını küçültür, bellek ve işlem yükünü sınırlar. Tam bağlı katman çıktıyı bir sınıf etiketiyle ilişkilendirir. Bu katmanlar farklı sayı ve sıralarda tekrarlanabilir.
  - CNN'in dezavantajları: gözetimli öğrenme olduğu için çok sayıda etiketli veri gerekir; tek başına bir sınıflama sonucu verir ve mutlaka bir uygulama alanına bağlanması gerekir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
