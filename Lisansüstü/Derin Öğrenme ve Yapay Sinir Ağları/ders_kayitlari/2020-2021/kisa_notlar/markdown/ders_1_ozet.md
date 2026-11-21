# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve kaynaklar
  - Ders, yapay sinir ağları (YSA) temelleriyle başlar, ardından derin öğrenmeye özgü konulara geçer. Hocaya göre ikisi ayrı alanlar değildir, aynı köklere sahiptir.
  - Önerilen kaynaklar: Laurene Fausett, *Fundamentals of Neural Networks* (dili sade, örnekleri bol, derin öğrenmeye kadar gitmiyor); Martin Hagan'ın matematik ağırlıklı YSA kitabı; MIT Press'in *Deep Learning* kitabı (Goodfellow ve diğerleri; Türkçe çevirisi de var); internetteki çevrimiçi bir kitap. <!-- BELİRSİZ: çevrimiçi kitabın yazarı altyazıda "Michael Wilson" geçiyor; büyük olasılıkla Michael Nielsen'in "Neural Networks and Deep Learning" kitabı. Kaynak slaydı karelere girmedi. -->
- Neden YSA? (ekrandan, 00:10:00)
  - Geleneksel, ardışık, mantık bazlı dijital hesaplamaların başarısız kaldığı konularda kullanılmak üzere, beynin yapısını anlamak ve güçlü özelliklerini taklit etmek için yaklaşık 70 yıl önce geliştirilmeye başlandı.
  - Veri işlemenin temel matematiksel modelidir; ilişkileri gösterme biçimi klasik yapay zekâ yöntemlerinden oldukça farklıdır.
- YSA nedir? (ekrandan, 00:50:00)
  - Yapay nöronlar beyindeki nöronların basit benzerleridir; fiziksel aygıt, salt matematiksel yapı ya da bilgisayarda benzetim olabilirler.
  - YSA, belirli bir görevi gerçekleştirmek için birbirine bağlanan çok sayıda basit işlem öğesinden oluşan paralel bir hesaplama sistemidir.
  - Gerçek beyne göre ne kadar basitleştirilmiş olduğu göz ardı edilmemelidir.
- Uygulama alanları
  - Örüntü sınıflandırma (görüntü ve diğer örüntüler), fonksiyon yaklaştırma (regresyon), tahmin, optimizasyon, içerik adreslenebilir bellek benzeri kullanım, kontrol.
  - İki amaç (ekrandan, 00:55:00): beyin modelleme (insan zekâsını anlama, öğretim stratejileri, beyin hasarlı hastalar için önlemler) ve yapay sistem geliştirme (makineleri güçlendirme, insanı sıkıcı işlerden kurtarma, insan performansını iyileştirme).
  - Gerçek dünya örnekleri: hisse senedi ve döviz kuru gibi zaman serisi tahminleri, iklim ve hava durumu verileri, oyunlarda akıllı ajanlar (tavla, FPS), karmaşık kontrol sistemleri, el yazısı ve konuşma tanıma, sonar ve diğer sinyallerin işlenmesi, veri sıkıştırma, veri madenciliği, gürültü azaltma (örneğin kardiyografi verileri).
- YSA'nın özellikleri (ekrandan, 01:00:00)
  - Güçlü bir hesaplama aracıdır; paralellik sayesinde verimlidir.
  - Eğitim verilerinden öğrenir ve öğrendiğini genelleştirir.
  - Hataya ve gürültüye dayanıklıdır.
  - Sembolik/mantık sistemlerinin yapabildiğini ve daha fazlasını yapabilir.
- Tarihçe (ekrandan, 01:05:00)
  - 1943 McCulloch ve Pitts nöron modeli; 1949 Hebb öğrenme kuralı ("Davranış Örgütü" kitabı); 1958 Rosenblatt'ın perceptronu (tek katmanlı ağ).
  - 1969 Minsky ve Papert'in *Perceptrons* kitabı tek katmanlı perceptronun kısıtlarını (XOR) gösterdi ve alan duraklama dönemine girdi.
  - 1982 Hopfield ağları ve Kohonen'in kendini düzenleyen haritaları; 1986 çok katmanlı perceptronlar için geri yayılım (backpropagation) ile alan yeniden canlandı; 1990'larda radyal tabanlı fonksiyon ağları; 2000'lerde YSA ve destek vektör makinesi toplulukları.
  - 2000'lerin ortasındaki durgunluğun nedenleri: kaybolan gradyan (vanishing gradient) sorunu, artan veri miktarı ve CPU'ların yetersizliği. GPU'lar ve derin ağlarla alan yeniden hızlandı.
- YSA öğrenmesi (ekrandan, 01:10:00)
  - Nöronlar aktivasyonları bağlantılar üzerinden iletir. Öğrenme, nöronlar arasındaki bağlantıların kuvvetini (ağırlığını) değiştirerek doğru çıktılara ulaşmaktır.
  - Üç öğrenme türü: öğretmenli (supervised), pekiştirmeli (reinforcement), öğretmensiz (unsupervised).
- Biyolojik sinir sistemi ile karşılaştırma
  - Blok diyagram (ekrandan, 01:15:00): Uyaran (stimulus) → Reseptörler → Sinir ağı/Beyin → Efektörler → Tepki (response); ara bloklar arasında geri besleme okları da vardır.
  - Beyin ve bilgisayar (ekrandan, 01:20:00): korteks yaklaşık 10 milyar nöron, en güçlü paralel bilgisayarlar on binlerce işlemci; nöron hızı ms ($10^{-3}$ s), silikon çip ns ($10^{-9}$ s); beyin enerji kullanımı yaklaşık $10^{-16}$ J, en iyi bilgisayarlar yaklaşık $10^{-6}$ J (slayttaki ifadeyle "saniyede").
  - Modellerde yalnız nöron ve nöronların oluşturduğu yerel devre alınır; moleküller, iyonlar, sinapslar, dendrit ağaçları, bölgeler arası devreler ve beynin kimyası modellenmez.
- McCulloch-Pitts nöronu (ekrandan, 01:35:00)
  - "Threshold Logic Birimi" olarak da bilinir: bağlantılardan girdileri alır, toplar, eşik (step) fonksiyonu uygular, sonucu çıkış hattından iletir.
  - Çıkış: $out = \operatorname{sgn}\left(\sum_{i=1}^{n} in_i - \theta\right)$; toplam eşiğin üstündeyse olumlu, altındaysa olumsuz sonuç.
- Vektör notasyonu (ekrandan, 01:40:00)
  - Vektör: $\mathbf{x} = (x_1, \ldots, x_n)$. Bileşenlerin toplamı skalerdir: $s = \sum_i x_i$.
  - Aynı uzunlukta iki vektörün toplamı vektördür: $\mathbf{z} = (x_1+y_1, \ldots, x_n+y_n)$.
  - Aynı uzunlukta iki vektörün çarpımı (iç çarpım) skalerdir: $p = \mathbf{x}\cdot\mathbf{y} = \sum_i x_i y_i$.
- Aktivasyon fonksiyonları
  - Birim (identity) fonksiyon $f(x)=x$; ikili adım (binary step) $f(x)=1$ ($x \ge \theta$), $0$ ($x<\theta$).
  - İkili sigmoid ve bipolar sigmoid (ekrandan, 01:45:00): $f(x)=\dfrac{1}{1+e^{-\sigma x}}$, $g(x)=2f(x)-1=\dfrac{2}{1+e^{-\sigma x}}-1$.
  - Fonksiyon tablosu (ekrandan, 01:50:00): ArcTan, Softsign, SoftPlus, Bent identity, ReLU, Sinc, Binary step; denklemleri, türevleri ve değer aralıkları.
  - Yaygın kullanılanlar: sigmoid, hiperbolik tanjant, identity ve ReLU.
- Eşik ve bias (ekrandan, 01:55:00)
  - Net girdi: $net = y\_in_j = \sum_{i=1}^{n} x_i w_{ij}$.
  - Bias varsa $f(net)=1$ ($net \ge 0$), $0$ ($net<0$); eşik varsa $f(net)=1$ ($net \ge \theta$), $0$ ($net<\theta$).
  - Bias, aktivasyonu her zaman 1 olan bir nörondan gelen bağlantının ağırlığı gibidir; eşik ile bias aynı işlevi görür ve $\theta=-b$ alınabilir.
- Perceptron (ekrandan, 02:00:00)
  - McCulloch-Pitts nöronlarından oluşan bir girdi katmanının bir çıktı katmanını beslemesidir. Her girdi her çıktı nöronuna bağlıdır; girdi ve çıktı nöron sayıları eşit olmak zorunda değildir.
  - $out_j = \operatorname{sgn}\left(\sum_{i=1}^{n} out_i\, w_{ij} - \theta_j\right)$.
- Mantık kapıları
  - OR (ekrandan, 02:10:00): $w_1=w_2=2$, $\theta=2$.
  - AND (ekrandan, 02:15:00): $w_1=w_2=1$, $\theta=2$.
  - NOT: tek girdili; girdi 0 iken ağırlık işe yaramadığı için bias girdisi gerekir. <!-- BELİRSİZ: NOT ve NAND slaytlarındaki ağırlık/bias değerleri karelere girmedi; altyazıda NOT için ağırlık -1 ve bias 2 geçiyor gibi. -->
  - XOR (ekrandan, 02:20:00): tek nöronla çözülemez; dört denklemin birbiriyle çelişir.

## Hocanın Özellikle Vurguladığı Kısımlar

- YSA ve derin öğrenme her derde deva değildir
  - İnsan beynine benzetiliyor ama beyni yeterince bilmiyoruz; bildiğimiz ayrıntıların bile çoğu modellere aktarılmış değil. Hormonlar ve beynin kimyası modellerde yoktur. Güçlü ve zayıf yönleri bilinerek kullanılmalıdır.
- Öğrenme = bağlantı ağırlıklarını bulmak
  - Mimari yalnız nöronları ve bağlantıları gösterir; asıl iş bu mimarinin eğitilmesi, yani ağırlıkların ayarlanmasıdır.
- İki vektörün çarpımı skaler, toplamı vektördür
  - İşlemlerde çok hata yapılan yer olduğu için hoca bunu akılda tutmayı istedi. Satır/sütun boyut kısıtları ve lineer cebir tekrar edilmeli.
- Aktivasyon fonksiyonu seçimi
  - Fonksiyon türevlenebilir olmalıdır, çünkü geri yayılım öğrenmesi türev kullanır.
  - Fonksiyonun çıktı aralığı istenen çıktıların aralığına uymalıdır. Örneğin çıktı kesin pozitif ve üstten sınırsızsa SoftPlus uygun olabilir; Softsign negatif değer de üretir. Alternatif olarak veriler fonksiyonun aralığına ölçeklenmelidir. Hocaya göre bu dikkatten kaçan ama çok önemli bir konudur.
- Bipolar temsil
  - İkili temsilde yalnız 0 ve 1 vardır. Bipolar temsilde $-1$ yanlış, $1$ doğru, $0$ belirsizlik anlamına gelir. Bipolar temsil eğitimi kısaltır ve özellikle hatalı ya da gürültülü verilerde sonucu iyileştirir.
- Bias'ın önemi
  - Bias bir kaydırma (shift) parametresidir: $x+5$'teki $+5$ gibi çıktıyı istenen yere oturtur. Her nöronun ya da katmanın girişinde bir bias bulunur.
- "Kara kutu" ifadesi
  - YSA içindeki işlemler tanımsız değildir; yalnız toplama, çarpma ve aktivasyon fonksiyonudur. Kara kutu denmesinin nedeni işlem sayısının çok fazla olması ve insan gözüyle takip edilememesidir.
- Öğretmensiz öğrenmenin değeri
  - Etiketleme insan eliyle yapıldığında öznel hatalar içerebilir; öğretmensiz öğrenme benzerliği verinin özelliklerinden bulduğu için daha nesnel olabilir.

## Kısa Tekrar Notları

- YSA: yapay nöronlardan oluşan, paralel çalışan, örnekten öğrenen ve genelleyen, hataya ve gürültüye dayanıklı bir modeldir.
- Başlıca uygulamalar: sınıflandırma, regresyon, tahmin, optimizasyon, bellek, kontrol.
- Tarih: 1943 McCulloch-Pitts, 1949 Hebb, 1958 Rosenblatt, 1969 Minsky-Papert, 1982 Hopfield ve Kohonen, 1986 geri yayılım.
- Derin öğrenmenin iki temel yeniliği: kaybolan gradyan sorununun aşılması (ReLU) ve büyük veriyi işleyebilen GPU hesaplaması.
- Öğrenme türleri: öğretmenli (çok veri ister), pekiştirmeli (sınırlı geri besleme), öğretmensiz (etiketsiz veri).
- McCulloch-Pitts nöronu: toplama + eşik fonksiyonu.
- Net girdi $\sum x_i w_{ij}$; eşik ile bias arasında $\theta=-b$.
- Sigmoid $\frac{1}{1+e^{-\sigma x}}$, aralık $(0,1)$; bipolar sigmoid $2f(x)-1$, aralık $(-1,1)$.
- Aktivasyon fonksiyonu türevlenebilir olmalı ve çıktı aralığı hedef aralığa uymalı.
- OR: $w=(2,2)$, $\theta=2$. AND: $w=(1,1)$, $\theta=2$. XOR tek katmanla çözülemez.

## Detaylı Açıklamalar

- **YSA'nın konumu.** Hoca YSA'yı, mantık tabanlı klasik yöntemlerin yetersiz kaldığı yerde beynin işleyişini taklit eden bir girişim olarak tanıttı. YSA özellikle görüntü verisinde, genelleme gerektiren mantık problemlerinde ve zamana bağlı değişen verilerde (zaman serileri) başarılıdır. Zaman serisi, zaman içinde değişen her türlü veri olarak tanımlandı: döviz kuru, hisse senedi, hava durumu, kullanım oranları gibi. Bunun yanında YSA ile mühendislik ve tıp birbirini besler: mühendislik için geliştirilen modellerin başarısı beynin işleyişini anlamaya da ışık tutar.
- **Tarihsel dalgalanma.** McCulloch-Pitts nöronu tek başına çok az şey yapabildiği için ilk uygulamalar kısıtlıydı. Hebb kuralı bu nöronların işe yaradığını gösterdi. Rosenblatt'ın perceptronu özellikle mantık kapılarının modellenmesinde ses getirdi. Minsky ve Papert XOR gibi temel bir problemin tek katmanla çözülemediğini gösterince ilgi azaldı. Hopfield ve Kohonen ile canlanma başladı, 1986'da geri yayılımla alan yeniden çok popüler oldu ve bu ilgi 2000'lerin ortasına kadar sürdü. Hocaya göre bu dönemde her veriye düşünmeden YSA uygulanması, yöntemin yetersiz kaldığı durumları da öne çıkardı. Asıl teknik sorun, geri yayılımdaki gradyan inişinde türevin çok küçülmesiyle ortaya çıkan kaybolan gradyan sorunuydu; veri arttıkça ağ işe yaramaz hale geliyordu. Derin öğrenme bu sorunu çözdü ve GPU'larla büyük veriyi işleyebilir hale geldi.
- **Öğrenme türleri.** Öğretmenli öğrenmede verilen örneklerin beklenen sonucu üretip üretmediğine göre bir hata fonksiyonu kurulur ve algoritma ağırlıkları bu hataya göre ayarlar; en yaygın yöntemdir ama çok veri ister. Pekiştirmeli öğrenmede az sayıda örnek ve denemelerle, sınırlı bir geri beslemeyle öğrenilir. Öğretmensiz öğrenmede veri çoğunlukla etiketsizdir; sistem kendi kendine düzenlenerek benzerlikleri bulur.
- **Biyolojik benzetme.** Uyaranlar (ör. bir koku) reseptörlerle algılanır, beyindeki nöron ağında daha önceki deneyimlere göre bir karar oluşur ve efektörlerle (el, kol, dil gibi) bir tepki üretilir. Aynı uyarana herkesin farklı tepki vermesi, deneyimlerin karara etkisini gösterir; YSA'da bu etki örneklerle eğitim yoluyla aktarılır. Hoca, beyin bileşenlerinden yalnız birkaçının modellendiğini, oluşturulan yapının beyne ancak çok kaba biçimde benzediğini söyledi.
- **McCulloch-Pitts nöronu ve perceptron.** Nöron, girdilerin toplamını alır ve bir eşik değeri $\theta$ ile karşılaştırır. Toplamdan $\theta$ çıkarıldığında sonuç pozitifse çıktı 1, negatifse 0 olur. Birden fazla nöron peş peşe bağlandığında, bir nöronun çıktısı bağlantı ağırlığıyla çarpılarak sonraki nörona girdi olur. Perceptronda bir girdi katmanı bir çıktı katmanına tam bağlıdır; aynı katmandaki nöronlar paralel hesaplanır, bu yüzden "katman" paralel işleyen nöron dizisi anlamına gelir.
- **Eşik yerine bias.** $\sum x_i w_i - \theta$ ifadesinde $-\theta$'yı, değeri sürekli 1 olan ek bir girdinin ağırlığı gibi düşünürsek eşik fonksiyonu yerine yalnız toplama yaparak aynı sonuca ulaşırız. Böylece $\theta=-b$ olur. Bias, eşik fonksiyonu dışındaki aktivasyon fonksiyonlarında da çıktıyı kaydırmaya yarayan bir ayar parametresidir.
- **Mantık kapıları.** İki girişli bir kapının dört giriş kombinasyonu vardır, yani dört eğitim örneği. Her girdi için bir nöron, tek çıktı için bir nöron konur. $\theta=2$ seçilirse OR için ağırlıklar $(2,2)$, AND için $(1,1)$ olur (ekrandan, 02:10:00 ve 02:15:00). Ağırlıklar dört doğrusal denklem kurularak ya da deneme yoluyla bulunabilir; başka değerler de çözüm olabilir. Mimari bu kadar basitken özel bir öğrenme algoritması gerekmez; algoritmalar, çok sayıda ağırlığın birlikte ayarlanması gerektiğinde önem kazanır. NOT kapısında tek girdi 0 olduğunda ağırlık ne olursa olsun toplam 0 çıkar; bu yüzden ek bir bias girdisi gerekir. XOR için yazılan dört denklem birbiriyle çelişir, bu nedenle tek nöronla gerçeklenemez. Ağırlıklar ve eşik bir ızgarada taranarak bu durum ajan tarafından python ile doğrulanmıştır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
