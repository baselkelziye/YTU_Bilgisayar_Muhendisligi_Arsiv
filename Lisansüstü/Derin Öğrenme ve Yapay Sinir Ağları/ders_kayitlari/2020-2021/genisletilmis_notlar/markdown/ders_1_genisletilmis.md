# Ders 1 Genişletilmiş Notu: Yapay Sinir Ağlarına Giriş, McCulloch-Pitts Nöronu ve Perceptron

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı ve Kaynaklar
- 2. Neden Yapay Sinir Ağları?
- 3. YSA Nedir ve Nerelerde Kullanılır?
- 4. YSA'nın Özellikleri
- 5. Tarihçe: Yükselişler ve Duraklamalar
- 6. YSA Öğrenmesi ve Öğrenme Türleri
- 7. Biyolojik Sinir Sistemi ile Karşılaştırma
- 8. McCulloch-Pitts Nöronu
- 9. Vektör Notasyonu
- 10. Aktivasyon Fonksiyonları
- 11. Eşik ve Bias
- 12. Perceptron
- 13. "Kara Kutu" Meselesi
- 14. McCulloch-Pitts Nöronlarıyla Mantık Kapıları
- Örnek Sorular

## 1. Dersin Kapsamı ve Kaynaklar

Dersin adı "Derin Öğrenme ve Yapay Sinir Ağları" olsa da hoca bunların ayrı alanlar olmadığını, aynı köklerden geldiğini vurguladı. Bu nedenle ders önce yapay sinir ağlarının (YSA) temelleriyle başlayacak, ardından derin öğrenmeye özgü konulara geçecek. Dönem içinde proje niteliğinde ödevler ve küçük alıştırmalar olacağını, öğrencilerin mümkünse kendi ilgi alanlarına yakın uygulama konuları seçmelerinin faydalı olacağını söyledi.

Hocanın önerdiği kaynaklar:

- **Laurene Fausett, *Fundamentals of Neural Networks*:** Dili çok sade, içinde güzel örnekler olan, biraz eski bir kitap. Derin öğrenmeye kadar gitmez, ama dersin YSA kısmı bu kitapla örtüşür.
- **Martin Hagan'ın YSA kitabı:** Konuya daha çok matematik tarafından bakar.
- **MIT Press'in *Deep Learning* kitabı:** Güncel temel kaynak; Türkçe çevirisi de çıktı. Konuyu tezinde kullanmayı düşünenlerin edinmesi önerildi.
- **İnternetteki çevrimiçi bir kitap.** <!-- BELİRSİZ: yazar adı altyazıda "Michael Wilson" geçiyor; büyük olasılıkla Michael Nielsen'in "Neural Networks and Deep Learning" adlı çevrimiçi kitabı. Kaynak slaydı karelere girmedi. -->

Hoca ayrıca çevrimiçi kurs olarak Coursera'daki derin öğrenme kurslarını önerdi; üniversitelerin ve güvenilir kurumların kurslarının tercih edilmesini, kalitesi belirsiz platformlardaki kurslara temkinli yaklaşılmasını tavsiye etti.

## 2. Neden Yapay Sinir Ağları?

Slayttaki tanıma göre (ekrandan, 00:10:00):

- Geleneksel, ardışık, mantık bazlı dijital hesaplamaların başarısız kaldığı konularda kullanılmak üzere, beynin yapısını anlamak ve güçlü özelliklerini taklit etmek için 70 yıl kadar önce geliştirilmeye başlandı.
- Veri işlemenin temel matematiksel modelidir.
- İlişkileri gösterme yöntemleri oldukça farklıdır.

Hoca slayttaki "70 yıl" ifadesinin biraz eski kaldığını, geçmişin artık 75 yıla yaklaştığını belirtti. YSA, klasik yöntemlerin ve insana benzetemediğimiz diğer öğrenme yöntemlerinin yetersiz kaldığı yerde insan beynini taklit etme girişiminin sonucudur. İlişkileri gösterme biçimi insan beynine benzetilmiştir.

Hoca burada önemli bir uyarı yaptı: YSA bazı uygulamalarda çok başarılı ve artık çok yaygın, ama insan beynini o kadar iyi bilmiyoruz. Bildiğimiz ayrıntıları bile henüz YSA modellerine aktarabilmiş değiliz. "İnsanın yerini alacak mı?" tartışması hocaya göre o kadar yakın görünmüyor. Yine de YSA, beyindeki modelin en önemli kısmını izlediği için belli bir aşamada başarılıdır; özellikle görüntü üzerinde, genelleme gerektiren mantık problemlerinde ve zamana bağlı değişen verilerde.

> **Hocanın vurgusu:** YSA ve derin öğrenme bütün dertlerin devası değildir. Zayıf ve güçlü yönleri bilinerek kullanılmalıdır.

## 3. YSA Nedir ve Nerelerde Kullanılır?

### 3.1 Tanım

Slayttaki tanım şöyleydi (ekrandan, 00:50:00):

- **Yapay nöronlar** beyinde bulunan nöronların basit benzerleridir. Fiziksel aygıtlar, salt matematiksel yapılar olabilirler ya da bilgisayarlarda benzetilebilirler.
- **YSA'lar** yapay nöronlardan oluşan ağlardır ve gerçek beyin yapısına basit yaklaşımlar oluştururlar.
- Pratik bir bakış açısına göre YSA, belirli bir görevi gerçekleştirmek için belirli bir şekilde birbirine bağlanan birçok basit işlem öğesinden oluşan paralel bir hesaplama sistemidir.
- YSA'ların gerçek beyinlerle karşılaştırıldığında ne kadar **basitleştirilmiş** olduğu göz ardı edilmemelidir.

Hoca bu basitleştirmeyi şöyle açıkladı: Beynimizde pek çok hormon ve salgı olduğunu, bunların insanın psikolojik durumunda ve kararlarında ne kadar etkili olduğunu biliyoruz. Ama bunları YSA'ya aktarmış değiliz; beynin kimyasını da çözebilmiş değiliz. Belki bu kimyasal etkilerin bir kısmının, her model ve her problemde farklı biçimde, modelin içine kendiliğinden yansıdığı düşünülebilir; ama sonuçta yapay bir şey yapıyor, genelliyor ve bazı şeyleri varsayıyoruz.

Paralellik önemli bir noktadır: İşlemlerin paralel yapılması daha büyük veriyi ve daha karmaşık problemleri modellemeye olanak verir. YSA bu yönüyle de klasik yapay zekâ uygulamalarından ayrılır.

### 3.2 Uygulama türleri

Hoca YSA'nın en çok işe yaradığı problem türlerini şöyle sıraladı:

- **Örüntü sınıflandırma:** Her türlü görüntü verisi ya da başka örüntüler.
- **Fonksiyon yaklaştırma:** Regresyon tarzı problemler.
- **Tahmin ve optimizasyon:** Hocaya göre YSA'nın en başarılı olduğu alanlar.
- **Hata ve gürültü toleransı:** Verilerde gürültü, eksik ya da hata varsa YSA bunları klasik modellerden çok daha iyi tolere eder.
- **Bellek olarak kullanım:** İçerik adreslenebilir belleklere benzeyen uygulamalar. Hoca bunlara derste değinileceğini söyledi.
- **Kontrol uygulamaları.**

### 3.3 İki amaç

YSA yapay zekânın bir dalı olduğu için iki amacı vardır (ekrandan, 00:55:00):

- **Beyin modelleme:** Bilimsel olarak biyolojik beynin gerçeklenmesine çalışmak. Bu, insan zekâsının doğasını anlamamıza, daha iyi öğretim stratejileri oluşturmamıza ya da beyin hasarlı hastalar için iyileştirici önlemler almamıza yardımcı olabilir.
- **Yapay sistemler geliştirme:** Mühendislik olarak gerçek dünya için verimli sistemler oluşturmak. Bu, makineleri daha güçlü hale getirebilir, insanları sıkıcı işlerden kurtarabilir ve insan performansını iyileştirebilir.

Hoca, mühendislik tarafındaki gelişmelerin tıbbı, tıptaki gelişmelerin de mühendisliği etkileyebildiğini söyledi. YSA modellerinin başarısı, beyne o gözle bakıp insan beyninin işleyişini anlamada da faydalı olabiliyor.

### 3.4 Uygulama alanları

Beyin modelleme tarafında: insan gelişim modelleri, gelişim problemi olan çocuklara yardım, beynin nasıl çalıştığını anlama, yetişkin performansının benzetimi, nöropsikolojik modeller, beyin hasarlı hastalar ve yaşlılıkla gelen hastalıkların izlenmesi, öngörü ve tedavi yöntemleri.

Gerçek dünya tarafında:

- **Ekonomi ve finans:** Hisse senedi ve döviz kuru tahmini. Bunlar zaman serisi verisidir. Hoca zaman serisini kabaca zamana bağlı değişen her türlü veri diye tanımladı: iklim, hava durumu, bir havayolunun pazarlama verileri, kullanım oranlarının zaman içindeki değişimi gibi.
- **Oyunlar ve akıllı ajanlar:** Tavla, FPS gibi oyunlar.
- **Kontrol sistemleri:** Kontrol teorisi çözülmemiş bir alan değildir, ama parametre sayısı çok ve sistem karmaşıksa büyük matematik denklemler kurmak yerine YSA ile model oluşturmak mümkün olabilir.
- **Sinyal işleme ve tanıma:** El yazısı tanıma, konuşma tanıma, görüntü, sonar ve aklınıza gelebilecek her türlü sinyal; ayrıca veri analizi, veri sıkıştırma ve veri madenciliği.
- **Gürültü azaltma:** Örneğin tıbbi verilerde, kardiyografi verilerinde gürültüyü temizleyerek iyi tahmin yapan yapılar.

Tanışma sırasındaki bir konuşmada hoca, YSA'nın hataları tolere etme ve genelleme yeteneğinin bazı hata türlerinde klasik yöntemlere üstünlük sağlayabileceğini, ama derin öğrenmede verinin miktarı ve çeşitliliğinin de sonucu çok etkilediğini söyledi.

## 4. YSA'nın Özellikleri

Slayttaki özellikler (ekrandan, 01:00:00):

- Son derece güçlü bir hesaplama aracı.
- Paralelizm ile çok daha verimli olmaya elverişlilik.
- Eğitim verilerinden öğrenme ve öğrendiğini genelleştirebilme yeteneği.
- Hata toleranslı.
- Gürültü toleranslı.
- Temel olarak sembolik/mantık sisteminin yapabileceğini ve daha fazlasını yapabilir.

## 5. Tarihçe: Yükselişler ve Duraklamalar

Slayttaki tarih çizelgesi (ekrandan, 01:05:00):

- **1943:** McCulloch ve Pitts, McCulloch-Pitts nöron modelini önerdi.
- **1949:** Hebb, Hebbian öğrenme kuralının önerildiği "Davranış Örgütü" adlı kitabını yayınladı.
- **1958:** Rosenblatt, perceptron adı verilen basit tek katmanlı ağları tanıttı.
- **1969:** Minsky ve Papert'in *Perceptrons* kitabı tek katmanlı perceptronların kısıtlarını gösterdi ve hemen hemen tüm alan duraklama devresine girdi.
- **1982:** Hopfield, Hopfield ağları hakkında bir dizi bildiri yayınladı.
- **1982:** Kohonen, kendi adını taşıyan Kendini Düzenleyen Haritaları geliştirdi.
- **1986:** Çok katmanlı perceptronlar için geri yayılım (back-propagation) öğrenme algoritması keşfedildi ve tüm alan tekrar dirildi.
- **1990'lar:** Radyal esaslı fonksiyon ağlarının alt alanı geliştirildi.
- **2000'ler:** YSA ve destek vektör makinesi topluluklarının gücü belirginleşti.

Hoca bu çizelgeyi bir hikâye gibi anlattı. McCulloch ve Pitts'in tanımladığı şey yalnız bir nöron modelidir: girdileri toplayıp bir fonksiyon uygulayan, bugün derin öğrenmede hâlâ kullandığımız basit model. Fikir o dönem için son derece yeniydi, ama tek bir nöronun yapabildikleri kısıtlıydı. Nöronların birlikte kullanılmasını sağlayan öğrenme algoritmaları ve mimariler çıkmadan uygulamalar sınırlı kaldı.

Hebb kuralı McCulloch-Pitts nöronlarının işe yaradığını göstererek uygulama alanını genişletti. 1958'e kadar bir duraklama oldu. Rosenblatt'ın tek katmanlı perceptronu çok ses getirdi; özellikle mantık devreleri ve mantık kapılarının modellenmesinde faydalıydı. Minsky ve Papert tek katmanlı perceptronların kısıtlarını, özellikle XOR'un çözülemediğini gösterince, XOR oldukça temel bir problem olduğu için sanki yöntem hiç işe yaramayacakmış gibi bir kanı oluştu ve ilgi azaldı. Yine de bazı araştırmacılar çalışmaya devam etti: 1982'de Hopfield ve Kohonen'in çalışmalarıyla canlanma başladı, 1986'da çok katmanlı perceptronlar ve geri yayılımla tüm alan yeniden canlandı.

Hoca 1986'dan 2000'lerin ilk yarısına kadar YSA'nın çok popüler olduğunu, bugün derin öğrenmede olduğu gibi herkesin elindeki veriyi ilgili ilgisiz bir YSA modeliyle denediğini anlattı. Bu aşırı ilgi, iyi açıklanmadığında yöntemin işe yaramadığı noktaları da öne çıkardı ve bir sessizlik dönemi başladı.

Derin öğrenme yalnız bir moda değildir; iki temel yenilik getirmiştir:

- **Kaybolan gradyan sorununun aşılması:** 2000'lere kadar geri yayılımın en önemli eksikliği, gradyan inişinde türevin değerinin çok küçülmesiyle ortaya çıkan kaybolan gradyan (vanishing gradient) sorunuydu. Veri artırıldığında bu sorun ağı tamamen işe yaramaz hale getirebiliyordu ve karmaşık problemlerin çözülemediği kanısı oluşmuştu. Derin ağlarla bu sorun çözüldü; ayrıntısı ileriki derslerde konuşulacak.
- **Büyük veri ve hesaplama gücü:** Kullanılmak istenen veri miktarı çok arttı, daha karmaşık ağlar kuruldu ve klasik CPU'lar yetersiz kaldı. GPU'larla bu darboğaz aşıldı. Hoca, verinin artmaya devam ettiğini ve bir sonraki tıkanmanın ne zaman olacağını birlikte göreceğimizi söyledi.

## 6. YSA Öğrenmesi ve Öğrenme Türleri

### 6.1 Mimari ve öğrenme

YSA'nın bir mimarisi vardır: nöronlar, bağlantılar ve katmanlar. Ama mimari yalnız yapıyı gösterir; asıl önemli olan bu mimarinin eğitilmesidir. Slayttaki ifade şöyleydi (ekrandan, 01:10:00):

- Sinir ağlarının birçok biçimi vardır. Birçoğu bağlı nöronlar ağı vasıtasıyla sinirsel aktivasyonları ileterek çalışır.
- Sinir ağlarının en güçlü özelliklerinden biri, bir takım eğitim verilerinden öğrenme ve genelleme becerisidir. Nöronlar arasındaki bağlantıların kuvvetlerini/ağırlıklarını değiştirirler, böylece nihai doğru çıktılara ulaşırlar.

Hoca süreci şöyle anlattı: Girdiler ilk girdikleri nöronda bir uyarı oluşturur. Nöronda kullanılan fonksiyon bu uyarının bağlı olduğu diğer nöronlara iletilip iletilmeyeceğine ya da ne kadar güçlü iletileceğine karar verir. Nöronlar, gelen uyarıların değerine göre bu kararı vermeyi öğrenir. Öğrenme, bağlantıların kuvvetlendirilmesi ya da zayıflatılmasıdır; bu kuvvete bundan sonra **ağırlık** denecektir.

### 6.2 Üç öğrenme türü

- **Öğretmenli öğrenme (supervised learning):** En yaygın kullanılan yöntemdir. Örnekten öğrenme gerçekleşir. Verilen örneklerin beklenen sonuçları üretip üretmediğine göre bir hata fonksiyonu oluşturulur; algoritma bu hata miktarına göre bağlantı ağırlıklarını ayarlayarak ağı yeni örnekler için daha iyi sonuç verecek şekilde eğitir. Zayıf yanı çok fazla veri gerektirmesidir.
- **Pekiştirmeli öğrenme (reinforcement learning):** Sisteme az sayıda örnek verilir, sistem denemeler yaparak bir çıktı üretir. Öğrenme kısıtlı bir geri beslemeyle sağlanır.
- **Öğretmensiz öğrenme (unsupervised learning):** Tamamen kendi kendine öğrenme diye tanımlanabilir. Çok az etiketli veri kullanılabilir, ama çoğunlukla veri etiketsizdir; sistem kendi kendine düzenlenerek veriyi anlar ve benzerlikleri bulur.

Hoca öğretmensiz öğrenmenin önemli bir yanına dikkat çekti: Verileri kendimiz etiketlediğimizde ya da hazır etiketli veri kullandığımızda neyin doğru neyin yanlış olduğunu biz söyleriz. Bu kararlarda insan faktörü devreye girer ve herkesin fikri aynı olmayabilir; dolayısıyla veri etiketlenirken hata içerebilir. Öğretmensiz öğrenmede sistem verinin özelliklerine bakarak benzerliğe karar verir; bir açıdan veriyi insandan daha nesnel biçimde gruplar. Bu yüzden öğretmenli öğrenme daha çok kullanılsa da öğretmensiz öğrenmenin tercih edilmesi gereken durumlar vardır.

## 7. Biyolojik Sinir Sistemi ile Karşılaştırma

### 7.1 Blok diyagram

Slayttaki tanıma göre (ekrandan, 01:15:00) insan sinir sistemi blok diyagram şeklinde üç aşamaya bölünebilir:

- Reseptörler çevreye ait bilgileri toplar (örneğin retinadaki fotonlar).
- Efektörler çevre ile etkileşim yaratır (örneğin kasları harekete geçirmek).

```text
Stimulus -> Receptors <-> Neural Network/Brain <-> Effectors -> Response
```

Diyagramda reseptörler ile beyin ve beyin ile efektörler arasında ileri yönlü okların yanında geri yönlü oklar da vardır (ekrandan, 01:15:00).

Hoca bunu bir koku örneğiyle açıkladı: Bir şey kokladık ve koku hoşumuza gitti; o yere doğru yöneliyoruz. Burundaki algılayıcılar reseptördür. Beyin kokunun hoş olduğuna daha önceki deneyimlerimize ve öğrendiklerimize göre karar verir. Kimine kötü gelen bir koku, kimine bir şeyler hatırlatan, içini ısıtan bir koku olabilir. Kilit nokta, aldığımız uyaran karşısında nöronlarımızın verdiği karardır ve bu karar tamamen kişiseldir. YSA'nın temel mantığı da budur: Deneyimlerin kararlara etkisini YSA'ya örnekler göstererek aktarırız. Bu blok diyagramın bir benzeri YSA'da mimari olarak kullanılır.

### 7.2 Modellenmeyen bileşenler

Beyinde moleküller, iyonlar, sinapslar, nöronal mikro devreler, dendrit ağaçları (uçlarında sinapsların bulunduğu kalın bağlantılar), bölgeler arası devreler ve merkezi sinir sistemi gibi bileşenler vardır. YSA'da bunların çoğu dikkate alınmaz; yalnız nöronlar ve nöronların oluşturduğu yerel devre modellenir. Hoca, bilgimizdeki sekiz ana bileşenden yalnız ikisinin dikkate alındığını ve ortaya çıkan yapının beyne kabaca, tahminen dörtte biri kadar benzediğini söyledi. Sinapslar, aksonlar ve dendritler içinden yalnız ortadaki merkez nöron modellenir; çevresindeki kimyasal ortam modellere aktarılmaz.

Beyin lobları da kabaca şöyle eşleştirildi: arkadaki paryetal ve oksipital loblar (ve işitme ile hafızayla ilgili temporal lob) veri girişine, sensörlerin bulunduğu kısma benzetilebilir; planlama ve akıl yürütmenin yapıldığı frontal lob ise karar verici, yani ağın çıktısının üretildiği yer gibi düşünülebilir.

### 7.3 Beyin ve bilgisayar

Beyni anlasak bile bunu insan yapımı işlemcilerle gerçekleyeceğiz. Bu işlemcilerden beyinle aynı performansı bekleyebilir miyiz? Slayttaki karşılaştırma (ekrandan, 01:20:00):

- İnsan korteksinde yaklaşık 10 milyar nöron vardır; buna karşın en güçlü paralel bilgisayarlarda on binlerce işlemci vardır.
- Her bir biyolojik nöron, güçlü paralel bilgisayarlardaki bağlantıya benzer şekilde binlerce başka nörona bağlanır.
- Biyolojik nöronların tipik çalışma hızları milisaniye ($10^{-3}$ s) ölçeğindeyken bir silikon çip nanosaniye ($10^{-9}$ s) ölçeğinde çalışabilir.
- İnsan beyni enerji açısından son derece verimlidir: saniyede yaklaşık $10^{-16}$ joule kullanırken en iyi bilgisayarlar bugün saniyede yaklaşık $10^{-6}$ joule kullanır.

Hoca sayıların biraz eski olduğunu ama büyüklük derecelerinin doğru olduğunu söyledi. İşlemci sayısında arada bir uçurum vardır (milyarlara karşı on binler). Hız bakımından silikon daha hızlıdır. Enerji bakımından ise bilgisayarlar beyinden çok daha az verimlidir. Bu yüzden, beyne benzer bir şey yapılmak isteniyorsa donanım tarafında da alınacak çok yol vardır.

> **Ders sonrası not:** Hoca enerji tüketimindeki farkı "neredeyse $10^3$" diye söyledi; slayttaki değerlere göre oran $10^{-6}/10^{-16}=10^{10}$'dur (python ile hesaplandı). Hız oranı ise $10^{-3}/10^{-9}=10^{6}$'dır. Slayttaki "saniyede joule" ifadesi büyük olasılıkla kaynak kitaptaki "işlem başına, saniyede joule" ölçüsünün kısaltılmış halidir; beynin toplam güç tüketimi bu kadar küçük değildir.

## 8. McCulloch-Pitts Nöronu

Aradan sonra hoca ilk nöron modeline geçti. Slayttaki tanım (ekrandan, 01:35:00):

- Gerçek nöronların çok basitleştirilmiş bir modelidir, aynı zamanda **Threshold Logic Birimi** olarak bilinir:
  - Bir dizi sinaps (diğer bir deyişle bağlantı), girdi katmanı, diğer nöronlardan aktivasyonları alır.
  - Bir işlem ünitesi girdileri toplar ve daha sonra lineer olmayan bir aktivasyon fonksiyonu uygular (yani sıkıştırma/aktarma/eşik fonksiyonu).
  - Bir çıktı hattı, sonucu diğer nöronlara iletir.

Şekilde $in_1, in_2, \ldots, in_n$ girdileri bir toplama kutusuna ($\Sigma$) girer, toplamın sonucu bir basamak (step) fonksiyonundan geçer ve $out$ çıktısı üretilir (ekrandan, 01:35:00). Hâlâ kullandığımız nöron aşağı yukarı bu yapıdadır: bir toplama işlemi ve bir eşik.

Eşik fonksiyonunun söylediği şey şudur: Elde ettiğin toplam eşik değerinin üstündeyse olumlu, altındaysa olumsuz bir sonuç üret. İlk McCulloch-Pitts nöronunun yapabileceği bununla sınırlıdır; lineer olmayan başka aktivasyon fonksiyonlarının kullanımı daha sonra gelecektir.

Birden fazla nöron peş peşe bağlanarak basit bir ağ oluşturulabilir. Bu durumda nöron yine girdileri toplar ve aktivasyon fonksiyonunu uygular; çıktısını sonraki nörona aktaran bağlantının bir ağırlığı vardır. Hesap şöyle yürür: Girdiler toplanır, eşik $\theta$ çıkarılır; fark negatifse olumsuz, pozitifse olumlu bir çıkış elde edilir. Bu çıkış bağlantı ağırlığıyla çarpılarak sonraki nörona girdi olarak verilir; o nöron da kendi girdilerini toplar, fonksiyonu uygular ve devam eder. 1940'lardaki uygulamalar genellikle McCulloch-Pitts nöronlarının bu şekilde birbirine bağlanmasıyla sınırlıydı. <!-- BELİRSİZ: hocanın bu hesabı anlattığı slayttaki denklemler (toplam, eşik farkı ve ağırlıklı çıkış) karelere girmedi. -->

Hoca daha sonra McCulloch-Pitts nöronunun matematiksel ifadesini tek denklemde topladı: Girdilerin toplamı $\theta$'dan büyükse çıktı 1, küçükse 0'dır. Bunu, toplamdan $\theta$ çıkarılıp bir işaret fonksiyonu uygulanmış gibi yazabiliriz:

$$out = \operatorname{sgn}\left(\sum_{i=1}^{n} in_i - \theta\right)$$

İçerideki değer pozitifse sonuç 1, negatifse 0 olur (burada işaret fonksiyonu 0/1 çıktılı basamak fonksiyonu anlamında kullanılıyor).

## 9. Vektör Notasyonu

Hoca vektör çarpımının derste çok sık kullanılacağını söyleyerek lineer cebir bilgisini tekrar etmeyi istedi. Slayttaki notasyon (ekrandan, 01:40:00):

- **Vektör:** İlgili sayıların sıralı gruplarıdır: $\mathbf{x} = (x_1, x_2, x_3, \ldots, x_n)$, $\mathbf{y} = (y_1, y_2, y_3, \ldots, y_m)$.
- **Vektörün bileşenleri toplamı skaler bir sayıdır:** $s = x_1 + x_2 + x_3 + \cdots + x_n = \mathrm{SUM}(i, n, x_i)$.
- **Aynı uzunlukta iki vektörün toplamı başka bir vektörü verir:** $\mathbf{z} = \mathbf{x} + \mathbf{y} = (x_1 + y_1, x_2 + y_2, \ldots, x_n + y_n)$.
- **Aynı uzunlukta iki vektörün çarpımı skaler bir sayıyı verir:** $p = \mathbf{x}\cdot\mathbf{y} = x_1 y_1 + x_2 y_2 + \cdots + x_n y_n = \mathrm{SUM}(i, N, x_i y_i)$.

Vektörün bileşenleri birer skalerdir; vektör ise bunlara ek olarak bir yön bilgisi taşır. İki vektörün toplamında her bileşen karşılık gelen bileşenle toplanır, sonuç yine bileşenleri olan bir vektördür. Çarpımda ise bileşenler çarpılıp toplandığı için sonuç tek bir sayıdır.

> **Hocanın vurgusu:** İki vektörün çarpımı skaler, toplamı vektördür. İşlemlerde çok hata yapılan bir yer olduğu için bunu aklınızdan çıkarmayın. Satır ve sütun vektörlerin çarpılabilirliğiyle ilgili boyut kısıtlarını da tekrar edin.

> **Ek bilgi (derste anlatılmadı):** Burada kastedilen çarpım iç çarpımdır (nokta çarpım, dot product). Satır vektörü $1\times n$, sütun vektörü $n\times 1$ boyutundaysa $\mathbf{x}^T\mathbf{y}$ çarpımı $1\times 1$, yani skaler olur. Aynı vektörlerin ters sırayla çarpımı $\mathbf{x}\mathbf{y}^T$ ise $n\times n$ boyutunda bir matris (dış çarpım) verir.

## 10. Aktivasyon Fonksiyonları

### 10.1 Neden "aktivasyon"?

Nöronun içinde toplamanın ardından uygulanan fonksiyona aktivasyon fonksiyonu denir; çünkü bu fonksiyonun sonucu, bağlı olduğu bir sonraki nöronun uyarılıp uyarılmayacağını (aktive olup olmayacağını) belirler. McCulloch-Pitts'in tanımladığı basamak fonksiyonu dışında başka fonksiyonlar da kullanılabilir.

### 10.2 Temel fonksiyonlar

İlk önerilen fonksiyonlar şunlardır:

- **Birim (identity) fonksiyon:** $f(x) = x$.
- **İkili basamak (binary step) ya da eşik fonksiyonu:**

$$f(x) = \begin{cases} 1 & x \ge \theta \\ 0 & x < \theta \end{cases}$$

### 10.3 Sigmoid fonksiyonları

Slayttaki "Genel Fonksiyonlar" (ekrandan, 01:45:00):

- **İkili (binary) sigmoid:**

$$f(x) = \frac{1}{1 + e^{-\sigma x}}$$

- **Bipolar sigmoid:**

$$g(x) = 2f(x) - 1 = \frac{2}{1 + e^{-\sigma x}} - 1$$

İkili sigmoid, parametre 1 alındığında 0 ile 1 arasında ara değer üretir. Parametreyle oynandığında fonksiyonun eğiminin ve temsil ettiği aralığın değiştiği görülür; hoca bunu çizdirerek denemeyi önerdi. <!-- BELİRSİZ: hoca parametreye sözlü olarak "gamma" diyor; slaytta sigma (σ) benzeri bir sembol var. -->

> **Ek bilgi (derste anlatılmadı):** Bipolar sigmoid $(-1, 1)$ aralığında değer üretir ve $g(x) = \tanh(\sigma x / 2)$ eşitliğini sağlar. Örneğin $\sigma=1$ için $g(0.5)$ ile $\tanh(0.25)$ ikisi de yaklaşık $0.2449$'dur (python ile kontrol edildi).

Hoca ReLU'nun kaybolan gradyan sorununun çözülmesindeki rolüne değindi: Bu sorun farklı aktivasyon fonksiyonlarıyla aşılmaya çalışılmış, çözüm ReLU'larla gelmiştir. Bu yüzden ReLU bugün yaygındır; Softsign kısmen, sigmoid ise çok kullanılır.

> **Ders sonrası not:** Hoca kaybolan gradyan sorununun ReLU ile çözümünü "2000'lerin ortası" olarak tarihlendi. ReLU'nun derin ağlarda yaygınlaşması büyük olasılıkla 2010-2012 yıllarına denk gelir.

### 10.4 Bipolar temsil

Hoca öğrencilere "bipolar" kelimesinden ne anladıklarını sordu (bkz. Örnek Sorular). Ardından şöyle açıkladı: İkili (binary) temsilde değerler yalnız 0 ve 1'dir; bir şeye ya doğru ya yanlış deriz. Ama bir şey tam kesin doğru ya da tam kesin yanlış olmayabilir; ara değerlere ihtiyaç olabilir. Bipolar temsilde, en azından ayrık versiyonunda, üç değer kullanılır:

- $-1$: yanlış (ikili temsildeki 0'ın yerine),
- $1$: doğru,
- $0$: belirsizlik, yani girdinin doğru mu yanlış mı olduğunu bilmediğimiz durum.

Girdiler de çıktılar da bu şekilde temsil edilebilir. Bu temsil özellikle mantık problemlerini çözerken ihtiyaç duyulmuş, perceptronlarda ve çok katmanlı perceptronlarda kullanılmaya başlanmıştır. YSA'nın genelleme ve hata toleransı yeteneklerini artırır. Hoca örneklerde görüleceğini söyleyerek şunu ekledi: Veriler ikili yerine bipolar temsil edildiğinde eğitim daha kısa sürer ve sonuçlar daha başarılı olur, özellikle veriler hatalı ya da gürültülüyse. Bir öğrencinin sohbet üzerinden yazdığı yorum da bipolar fonksiyonun negatif değerler de alabilmesine işaret ediyordu; hoca bunu doğruladı.

### 10.5 Aktivasyon fonksiyonu tablosu

Hoca yaygın kullanılan fonksiyonları, türevlerini ve değer aralıklarını gösteren bir tablo gösterdi (ekrandan, 01:50:00):

| Ad | Denklem | Türev | Aralık |
|---|---|---|---|
| ArcTan | $f(x)=\tan^{-1}(x)$ | $f'(x)=\frac{1}{x^2+1}$ | $(-\frac{\pi}{2}, \frac{\pi}{2})$ |
| Softsign | $f(x)=\frac{x}{1+\lvert x\rvert}$ | $f'(x)=\frac{1}{(1+\lvert x\rvert)^2}$ | $(-1, 1)$ |
| SoftPlus | $f(x)=\log_e(1+e^x)$ | $f'(x)=\frac{1}{1+e^{-x}}$ | $(0, \infty)$ |
| Bent identity | $f(x)=\frac{\sqrt{x^2+1}-1}{2}+x$ | $f'(x)=\frac{x}{2\sqrt{x^2+1}}+1$ | $(-\infty, \infty)$ |
| ReLU | $0$ ($x<0$), $x$ ($x\ge 0$) | $0$ ($x<0$), $1$ ($x\ge 0$) | $[0, \infty)$ |
| Sinc | $1$ ($x=0$), $\frac{\sin x}{x}$ ($x\ne 0$) | $0$ ($x=0$), $\frac{\cos x}{x}-\frac{\sin x}{x^2}$ ($x\ne 0$) | $[\approx -0.217234, 1]$ |
| Binary step | $0$ ($x<0$), $1$ ($x\ge 0$) | $0$ ($x\ne 0$), $?$ ($x=0$) | $\{0, 1\}$ |

Hoca bu kadar çok çeşidin hepsinin kullanılmadığını, yaygın olanların sigmoid (lojistik), hiperbolik tanjant, identity ve ReLU olduğunu söyledi.

### 10.6 Fonksiyon seçerken iki ölçüt

**Türevlenebilirlik.** Geri yayılım algoritmasında aktivasyon fonksiyonunun türevi alınır. Teorik olarak istediğimiz fonksiyonu seçebiliriz, ama türevlenebilir bir fonksiyon seçmezsek öğrenme algoritmasında sorun yaşarız.

**Çıktı aralığı.** Uygulamada fonksiyonları sırayla deneyip en iyi sonucu vereni seçmek yerine bilinçli bir seçim yapılmalıdır. Belirleyici olan, aktivasyon fonksiyonunun temsil ettiği aralıktır. Çıkışta elde etmek istenen verilerin alt ve üst sınırı neyse, o aralıkta değer üreten bir fonksiyon seçilmelidir; aksi halde ne yapılırsa yapılsın yeterince başarılı sonuç alınamaz. Hocanın örneği: Çıkış kesinlikle pozitif ama büyüklüğü sınırsız olmalıysa SoftPlus uygun olabilir, çünkü $(0, \infty)$ aralığında değer üretir. Softsign seçilirse negatif değerler de üretilir; elinizde hiç negatif sonuçlu örnek yoksa negatif üreten bir fonksiyonun anlamı yoktur. İkinci seçenek, örneklerin kullanılan fonksiyonun aralığına göre ölçeklenmesidir.

> **Hocanın vurgusu:** Aktivasyon fonksiyonunun çıktı aralığı genellikle dikkatten kaçan, ama çok önemli, basit bir konudur.

## 11. Eşik ve Bias

### 11.1 Net girdi

Bir nöronun girdisi şimdiye kadar değişmemiş, evrensel bir tanımdır: girdilerin bağlantı ağırlıklarıyla çarpımlarının toplamı. Slayttaki tanım (ekrandan, 01:55:00):

$$net = y\_in_j = \sum_{i=1}^{n} x_i\, w_{ij}$$

Bu net girdiye bir aktivasyon fonksiyonu uygulanarak sonraki nöron için çıktı üretilir.

### 11.2 Bias ve eşikli aktivasyon

Aynı slayta göre (ekrandan, 01:55:00):

- Bias kullanılmışsa aktivasyon fonksiyonu:

$$f(net) = \begin{cases} 1 & net \ge 0 \\ 0 & net < 0 \end{cases}$$

- Eşik kullanılmışsa aktivasyon fonksiyonu:

$$f(net) = \begin{cases} 1 & net \ge \theta \\ 0 & net < \theta \end{cases}$$

- Bias aktivasyonu her zaman 1 olan bir nörondan gelen bağlantının ağırlığı gibidir.
- Eşik ve bias aynı işlevi görür ve $\theta = -b$ olarak düşünülebilir.

Hoca eşiğin sıfır olmasının aslında hiç eşik kullanmamak anlamına geldiğini söyledi. Bias fikrinin çıkış noktası şudur: $\sum x_i w_i - \theta$ ifadesinde toplamdan $\theta$ kadar bir değer çıkarılıyor; yani toplama yeni bir değer ekleniyor. O halde $-\theta$'yı da bir girdi gibi kabul edip yalnız toplama yaparsak aynı sonuca varırız. Eşikli bir aktivasyon uygulamakla nörona ek bir bias girdisi $b$ vermek aynı işi görür.

### 11.3 Bias neden önemli?

Eşik fonksiyonu dışında bir aktivasyon fonksiyonu kullanılsa bile bias faydalıdır. İstenen sonuca şekil olarak benzeyen bir eğri elde edilmiş ama tam istenen aralığa oturmuyorsa, çıktıyı kaydırmak için oynanabilecek bir parametre bias'tır. Hocanın benzetmesiyle: Doğrusal bir fonksiyonda $x + 5$ dediğimizde $+5$ değeri fonksiyonu 5 birim kaydırır; bias da böyle bir kaydırma (shift) parametresidir. Bu yüzden her nöronun ya da her katmanın girişinde mutlaka bir bias değeri bulunur.

## 12. Perceptron

Slayttaki tanım (ekrandan, 02:00:00):

- McCulloch-Pitts nöronlarını istediğimiz şekilde, istediğimiz sayıda bağlayabiliriz.
- Bir McCulloch-Pitts nöron girdi katmanının başka bir McCulloch-Pitts nöronu çıktı katmanını besliyor olarak düzenlenmesi **perceptron** olarak adlandırılır.

Şekilde $i = 1, \ldots, n$ girdi nöronları, eşikleri $\theta_1, \ldots, \theta_m$ olan $j = 1, \ldots, m$ çıktı nöronlarına $w_{ij}$ ağırlıklı bağlantılarla bağlıdır. Çıktı:

$$out_j = \operatorname{sgn}\left(\sum_{i=1}^{n} out_i\, w_{ij} - \theta_j\right)$$

Hoca McCulloch ve Pitts'in nöronları birbirine bağladığını, ama perceptrondaki gibi yapısal bir bağlamanın daha sonra Rosenblatt tarafından önerildiğini söyledi. Perceptronda her girdi, bir sonraki katmandaki nöronların her birine bağlıdır. Girdi sayısıyla katmandaki nöron sayısı eşit olmak zorunda değildir; şekilde $n$ girdiye karşılık $m$ nöron vardır.

"Tek katman" ifadesi paralel işleyen nöronları anlatır: Bu nöronların hepsine girdiler aynı anda geldiği için toplama ve aktivasyon işlemleri aynı anda yapılabilir, nöronları sırayla hesaplamak gerekmez. Paralel işlenebilen her nöron dizisine bir katman denir. Girdilerin ve bir nöron katmanının bulunduğu bu mimariye tek katmanlı perceptron ya da kısaca perceptron denir.

Hesap şöyle yapılır: Her girdi, nörona giden bağlantısının ağırlığıyla çarpılır; nörona gelen bütün çarpımlar toplanır; McCulloch-Pitts nöronu kullanılıyorsa eşik değeri çıkarılır ve sonucun pozitif ya da negatif olmasına göre çıktı hesaplanır.

## 13. "Kara Kutu" Meselesi

YSA ve derin öğrenmeden bahsedilirken "kara kutu" (black box) terimi çok kullanılır: İçeride ne olduğunu bilmiyoruz. Hocaya göre bu bilmemenin nedeni içerideki işlemlerin tanımsız olması değildir. İçeride çok fazla nöron vardır; binlerce nöron binlerce kez aynı işlemi yapar ve sonuçlar sonraki katmana giderken başka ağırlıklarla çarpılır. Denklemler yazıldığında çok uzun olur, ama işlemlerin kendisi toplama, çarpma ve çoğu zaman çok karmaşık olmayan bir aktivasyon fonksiyonundan ibarettir. Matematiksel olarak içeride ne olduğunu çok iyi biliriz ve istersek bu uzun denklemleri yazabiliriz. Zor olan, ağın bir sonuca nasıl vardığını bir bakışta, akıl yürütmeyle takip etmektir.

## 14. McCulloch-Pitts Nöronlarıyla Mantık Kapıları

### 14.1 Neden mantık kapıları?

Perceptronların o dönem için en önemli uygulamalarının başında mantık kapıları gelir. Mantık kapılarında girdilerin ne olabileceği ve beklenen çıktı bellidir. Veri üretmek kolaydır ve veri sınırlıdır: İki girişli bir kapı için dört giriş kombinasyonu ve dört çıktı vardır. Yani bir kapı için kurulan nöron yapısı dört örnekle eğitilir; hatta dördünün birden eğitimde kullanılması tercih edilmeyebilir, üç örnekle eğitilip sonuç kontrol edilebilir. Kapıların birleşimiyle daha karmaşık devreler kurulabilir. Hocaya göre tek McCulloch-Pitts nöronuyla yapılabilenler, özellikle donanım seviyesinde kapı ve devre gerçeklemede kullanıldığında, o zamanki haliyle bile önemlidir.

### 14.2 OR kapısı

OR kapısında girdilerden biri bile 1 ise çıktı 1 olur; yalnız $(0,0)$ girdisinde çıktı 0'dır. Slayttaki tablo ve ağ (ekrandan, 02:10:00):

| $x_1$ | $x_2$ | $y$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

Ağ: $x_1$ ve $x_2$ girdi nöronları, ağırlıkları $2$ ve $2$ olan bağlantılarla $y$ çıktı nöronuna bağlıdır; $\theta = 2$.

Tasarımın mantığı: İki girdi olduğu için her girdiye bir nöron konur; tek çıktı olduğu için bir çıktı nöronu konur. Hoca, daha uzun çıktılarda da mümkün olduğunca az nöronla temsil edip nöron sayısını sınırlı tutmak gerektiğini söyledi. Böyle basit bir problemde eğitim algoritmasına gerek yoktur. Eşik $\theta = 2$ seçilir; toplam eşiğe ulaşırsa $y = 1$, ulaşmazsa $y = 0$ olur.

Adım adım kontrol ($net = 2x_1 + 2x_2$, $y = 1$ eğer $net \ge 2$):

- $(0,0)$: $net = 0 < 2$, $y = 0$.
- $(0,1)$: $net = 2 \ge 2$, $y = 1$.
- $(1,0)$: $net = 2 \ge 2$, $y = 1$.
- $(1,1)$: $net = 4 \ge 2$, $y = 1$.

Dört satırın hepsi tabloyla uyuşur (ajan tarafından python ile doğrulandı).

> **Ders sonrası not:** Hoca sözlü anlatımda "2'den büyük çıktığı zaman $y=1$" dedi. $(0,1)$ ve $(1,0)$ girdilerinde toplam tam 2 olduğu için kuralın, 01:55:00'daki slayttaki gibi "büyük eşit" ($net \ge \theta$) olması gerekir.

Ağırlıkları bulmanın iki yolu vardır. Birincisi deneme: $\theta=2$ iken ağırlıklara birkaç değer verip her örneğin istenen sonucu verip vermediğine bakmak. İkincisi, az nöron olduğu için denklemleri yazmak: Her örnek için "girdi çarpı ağırlıkların toplamı eksi $\theta$" ifadesinin işareti istenen çıktıyı vermelidir. Dört örnekten dört denklem çıkar, bilinmeyen ise yalnız iki ağırlıktır; bu sistem rahatça çözülebilir. Bulunan değerler tek çözüm değildir; kapıya ve $\theta$ değerine göre başka çözümler de olabilir.

> **Hocanın vurgusu:** Öğrenme dediğimiz şey bağlantı ağırlıklarını bulmaktan ibarettir. Öğrenme algoritmaları, çok sayıda nöron ve bağlantı olduğunda gerekli hale gelir; çünkü bu basit yapıda bile bir ağırlık diğerinden bağımsız düşünülemez, hepsi birlikte ayarlanmalıdır.

### 14.3 AND kapısı

AND kapısında yalnız iki girdi de 1 ise çıktı 1'dir. Slayttaki tablo ve ağ (ekrandan, 02:15:00):

| $x_1$ | $x_2$ | $y$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Ağ: ağırlıklar $1$ ve $1$, $\theta = 2$. Mimari yine iki girişli ve tek çıkışlıdır.

Adım adım kontrol ($net = x_1 + x_2$, $y = 1$ eğer $net \ge 2$):

- $(0,0)$: $net = 0$, $y = 0$.
- $(0,1)$: $net = 1 < 2$, $y = 0$.
- $(1,0)$: $net = 1 < 2$, $y = 0$.
- $(1,1)$: $net = 2 \ge 2$, $y = 1$.

Hoca küçük bir alıştırma olarak dört denklemin yazılıp $w_1$, $w_2$ için çözülmesini önerdi (bkz. Örnek Sorular).

### 14.4 NOT kapısı ve bias ihtiyacı

NOT kapısının bir girdisi ve bir çıktısı vardır; girdinin tersini üretmesi beklenir. Burada önemli bir durum ortaya çıkar: İkili veriyle çalışırken girdi 0 olduğunda bağlantı ağırlığının bir anlamı kalmaz; ağırlık ne olursa olsun çarpım 0'dır. Tek bağlantı olduğu için hiçbir ağırlık değeri 0 girdisinde istenen 1 çıktısını sağlayamaz. Bu yüzden ince ayarı yapacak bir bias tanımlanır ve ikinci bir girdi olarak verilir. Bias, $\theta$ ile aynı büyüklükte ya da onun negatifi olarak seçilebilir. Girdi 0 olduğunda bile bias bağlantısından bir değer geleceği için diğer ağırlığı ayarlama şansı doğar. Hoca, NOT kapısının bias'ın önemini açıkça gösterdiğini söyledi. <!-- BELİRSİZ: NOT kapısı slaydındaki ağırlık ve bias değerleri karelere girmedi; altyazıda ağırlığın -1, bias değerinin 2 olabileceği geçiyor. -->

### 14.5 NAND kapısı

NAND kapısı da iki ağırlıkla benzer biçimde tanımlanır. Mantık aynıdır: Dört denklemle ya da gözle kontrol ederek uygun bağlantı ağırlıkları bulunur. <!-- BELİRSİZ: NAND slaydındaki değerler karelere girmedi ve altyazıda söylenmedi. -->

### 14.6 XOR kapısı

XOR kapısında iki girdi aynıysa çıktı 0, farklıysa 1'dir. Slayttaki tablo ve ağ (ekrandan, 02:20:00):

| $x_1$ | $x_2$ | $y$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Ağda ağırlıkların yerinde soru işaretleri vardır. Hoca bunu ilk haftanın küçük ödevi olarak verdi: Girdiler ve çıktılar kullanılarak dört doğrusal denklem kurulacak, iki ağırlık $w_1$, $w_2$ sembolik bırakılacak ve bu "4 denklem, 2 bilinmeyen" sistemi çözülmeye çalışılacak. Amaç çözüm bulmak değil, çözümün neden bulunamadığını görmektir: Kurulan denklemler birbiriyle çelişen şeyler söyler; seçilecek $\theta$ değeri aynı anda birbiriyle çelişen iki kuralı sağlamak zorunda kalır ve böyle bir $\theta$ bulunamaz.

Bir öğrenci, XOR'un tek nöronla ifade edilemediğini bildiğini söyledi. Hoca bunun matematiksel nedenini sordu; öğrenci tek nöronun tek bir doğru çizebildiğini, iki doğru gerektiğini ve ikinci bir nöronla ikinci doğrunun çizilebileceğini söyledi. Hoca ödevde aynı sonuca bu kez denklemler yoluyla, matematiksel olarak varılacağını belirtti.

> **Ek bilgi (derste anlatılmadı):** Bir eşik nöronunun karar sınırı $w_1 x_1 + w_2 x_2 = \theta$ doğrusudur. Bu doğru düzlemi iki yarıya böler; bu yüzden tek nöron yalnız doğrusal ayrılabilir problemleri çözebilir. XOR'un 1 çıktılı noktaları $(0,1)$ ve $(1,0)$ ile 0 çıktılı noktaları $(0,0)$ ve $(1,1)$ tek bir doğruyla ayrılamaz.

Hoca dersi, ileride tek katmanlı perceptronla ilgili söylenecek başka şeyler olduğunu, yakında çok katmanlı perceptronlara ve öğrenme kurallarına geçileceğini, temel mimarilerden biri olan yinelemeli (recurrent) ağlara da değinileceğini ve derin öğrenme kısmında çok katmanlı, geri beslemeli ağlar üzerindeki algoritmaların konuşulacağını söyleyerek kapattı.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:44:35): Binary ile bipolar arasındaki ilişki ya da fark nedir? "Bipolar" kelimesini hangi anlamda duydunuz?

> **Cevap (derste verildi):** İkili temsilde değerler 0 ve 1'dir (yanlış/doğru). Bipolar temsilde $-1$ yanlışı, $1$ doğruyu, $0$ belirsizliği gösterir. Bipolar sigmoid $g(x) = 2f(x) - 1$ ile tanımlanır ve $(-1, 1)$ aralığında değer üretir; negatif değer de alabilir. Bipolar temsil eğitimi kısaltır, hatalı ya da gürültülü verilerde sonucu iyileştirir.

**Soru 2** (ekrandan, 02:15:00): AND kapısı için $\theta = 2$ alarak dört doğrusal denklemi yazın ve iki ağırlığı ($w_1$, $w_2$) bulun.

> **Çözüm (derste verilmedi):** Kural $y = 1 \iff w_1 x_1 + w_2 x_2 \ge 2$. Dört örnekten: $(0,0)$ için $0 < 2$ (her zaman sağlanır); $(0,1)$ için $w_2 < 2$; $(1,0)$ için $w_1 < 2$; $(1,1)$ için $w_1 + w_2 \ge 2$. Slayttaki $w_1 = w_2 = 1$ bu koşulların hepsini sağlar: $1 < 2$, $1 < 2$, $1 + 1 = 2 \ge 2$. Tek çözüm değildir; örneğin $w_1 = w_2 = 1.5$ da koşulları sağlar ($1.5 < 2$, $3 \ge 2$). Değerler python ile kontrol edildi.

**Soru 3** (ekrandan, 02:20:00; ilk hafta ödevi): XOR kapısı için girdiler ve çıktılarla dört doğrusal denklem kurun; ağırlıkları $w_1$, $w_2$ diye sembolik bırakarak sistemi çözmeye çalışın. Çözemiyorsanız nedenini açıklayın.

> **Çözüm (derste verilmedi):** Kural $y = 1 \iff w_1 x_1 + w_2 x_2 \ge \theta$ olsun.
>
> - $(0,0) \to 0$: $0 < \theta$, yani $\theta > 0$.
> - $(0,1) \to 1$: $w_2 \ge \theta$.
> - $(1,0) \to 1$: $w_1 \ge \theta$.
> - $(1,1) \to 0$: $w_1 + w_2 < \theta$.
>
> İkinci ve üçüncü koşul toplanırsa $w_1 + w_2 \ge 2\theta$ olur. Birinci koşuldan $\theta > 0$ olduğu için $2\theta > \theta$, yani $w_1 + w_2 > \theta$. Bu, dördüncü koşul $w_1 + w_2 < \theta$ ile çelişir. Dolayısıyla hiçbir $w_1$, $w_2$, $\theta$ üçlüsü dört koşulu birlikte sağlayamaz; XOR tek bir McCulloch-Pitts nöronuyla gerçeklenemez. Ajan, $[-5, 5]$ aralığında $0.25$ adımlı bir ızgarada ağırlık ve eşik değerlerini python ile tarayarak hiçbir çözüm bulunmadığını doğruladı.

**Soru 4** (derste sözlü, 02:19:59): Bir öğrenci XOR'un tek nöronla ifade edilemediğini söyleyince hoca sordu: Bunun matematiksel nedeni nedir? Tek doğru ile iki doğru arasındaki fark neden ayırmayı imkânsız kılar?

> **Cevap (derste verildi):** Öğrencinin cevabı: Tek nöron tek bir doğru çizer; XOR'u ayırmak için iki doğru gerekir ve ikinci bir nöronla ikinci doğru çizilebilir. Hoca, ödevdeki denklemlerin birbiriyle çelişmesinin aynı sonucu matematiksel olarak göstereceğini ekledi (çözüm için bkz. Soru 3).

## Dersin Toparlaması

Bu ilk derste yapay sinir ağlarının neden ortaya çıktığı, ne olduğu, hangi problemlerde güçlü olduğu ve gerçek beyne göre ne kadar basitleştirilmiş bir model olduğu konuşuldu. 1943'teki McCulloch-Pitts nöronundan 1986'daki geri yayılıma, oradan GPU'larla güçlenen derin öğrenmeye kadar alanın yükseliş ve duraklama dönemleri izlendi. Derin öğrenmenin asıl yeniliklerinin kaybolan gradyan sorununun aşılması ve büyük verinin işlenebilmesi olduğu vurgulandı. Öğrenmenin bağlantı ağırlıklarını ayarlamak olduğu ve üç öğrenme türü (öğretmenli, pekiştirmeli, öğretmensiz) tanıtıldı.

Teknik tarafta McCulloch-Pitts nöronu (toplama + eşik), net girdi, aktivasyon fonksiyonları (türevlenebilirlik ve çıktı aralığı ölçütleriyle), bipolar temsil, eşik ile bias arasındaki $\theta = -b$ ilişkisi ve tek katmanlı perceptron mimarisi görüldü. Mantık kapıları örneğinde OR ve AND'in tek nöronla kolayca gerçeklendiği, NOT kapısında bias'ın zorunlu hale geldiği ve XOR'un tek nöronla çözülemediği gösterildi. Hoca sonraki derslerde tek katmanlı perceptronun eksik kalan kısımlarına, çok katmanlı perceptronlara ve öğrenme kurallarına, yinelemeli ağlara ve derin öğrenme algoritmalarına geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
