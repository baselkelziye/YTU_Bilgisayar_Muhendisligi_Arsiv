# Ders 9 Genişletilmiş Notu: Derin Öğrenmeye Giriş: Gradyan Kaybolması, RBM, DBN ve CNN

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Derin Öğrenmeye Geçiş
- 2. Doğrusal Olmama ve Derin Öğrenmenin Yeri
- 3. Sinir Ağları ile Derin Ağların Farkı
- 4. Sınıflandırma ve Terminoloji
- 5. Derin Öğrenme Ne Zaman Kullanılmalı?
- 6. Karmaşık Örüntülerin Katman Katman İşlenmesi
- 7. Probleme Göre Model Seçimi
- 8. Gradyan Kaybolması ve Gradyan Patlaması
- 9. Kısıtlı Boltzmann Makineleri (RBM)
- 10. Kullback-Leibler Iraksaması
- 11. Derin İnanç Ağları (DBN)
- 12. Konvolüsyonel Sinir Ağları (CNN)
- Örnek Sorular

## 1. Derin Öğrenmeye Geçiş

Önceki derste çok katmanlı ağlar ve geri yayılım (backpropagation) algoritması özetlenmişti. Bu derste derin öğrenmeye giriş yapılır; geri yayılıma ilerleyen derslerde yeniden dönülecektir.

Derin öğrenme özünde yapay sinir ağlarıyla ilgilidir. Şimdiye kadar konuşulan her şey burada daha gelişmiş biçimleriyle karşımıza çıkar. Geri yayılım yine en önemli algoritmalardan biridir. Öğrenmenin temel mantığı aynı kalır; değişen, kullanılan aktivasyon fonksiyonudur. Konvolüsyonel ağlarda ise aktivasyon fonksiyonunun yanında filtreler kullanılarak işlem yapılır.

Derin ağlara geçişin arkasında iki gelişme vardır:

- Geri yayılımdaki bir iki problemin çözülmesi. Bu problemler de yine kullanılan aktivasyon fonksiyonuyla ilgilidir.
- GPU'ların ortaya çıkması. Çok fazla hesaplama gerektiği için CPU'larla çok sayıda ara katman kullanmak mümkün değildi; GPU'lar daha fazla ara katman kullanmayı olanaklı kıldı.

Bu yüzden derin öğrenme düşünce olarak çok yeni bir şey değildir. Elimizdeki araçların, başta hesaplama gücünün, artmasıyla yeniden popüler olmuş bir kavramdır ve çok geniş bir uygulama alanı bulmuştur.

Slayttaki terim bulutunda derste sık duyulacak terimler yer alır: Deep Belief Nets, Convolutional Nets, Backpropagation, non-linearity ve Image recognition (ekrandan, 00:05:00).

## 2. Doğrusal Olmama ve Derin Öğrenmenin Yeri

Hoca bu terimlerden özellikle doğrusal olmamayı (non-linearity) vurgular. Genel olarak yapay sinir ağlarını, çok katmanlı perceptronları ve derin öğrenmeyi kullanmamızın sebebi, elimizdeki problemlerin doğrusal olmamasıdır.

Doğrusal olmama şu anlama gelir: çok sayıda parametreyi aynı anda, problemi çözecek en uygun değerlere getirmemiz gerekir. Parametrelerin birbirleriyle ilişkisi doğrusal olmadığı için bu değerleri doğrusal denklem sistemleriyle ya da bilinen doğrusal cebir işlemleriyle ifade edip çözerek bulamayız. Üstelik problemler bir, iki ya da üç boyutlu değil, çok daha yüksek boyutludur. Elinizde çok boyutlu ve doğrusal olmayan bir problem varsa derin öğrenme iyi bir araçtır.

### 2.1 Alanın öncü isimleri

Derin öğrenme araştırmacıları arasında adı sık geçen isimler Andrew Ng, Geoffrey Hinton, Yann LeCun, Yoshua Bengio ve Andrej Karpathy'dir. Hoca, Andrew Ng'nin Coursera'daki makine öğrenmesi ve derin öğrenme kurslarını (YouTube'da da açık), Hinton ve LeCun'un konuşmalarını ve Karpathy'nin dokümanlarını incelemeyi önerir.

### 2.2 Büyük firmaların ilgisi

Derin öğrenme kısa sürede büyük ilgi gördü ve büyük firmalar yatırım yapmaya başladı. Slayttaki rakamlar (hocaya göre birkaç yıl önceki rakamlar) şöyledir (ekrandan, 00:10:00):

- Google: 400 milyon dolar.
- Apple: sürücüsüz araç (self-driving car) projesi.
- NVIDIA: GPU'lar. Hoca, NVIDIA'nın bugün bu pazarı tamamen domine ettiğini ve bu işlemcilerin derin öğrenmede çok kullanıldığını söyler.
- Toyota: 1 milyar dolarlık yapay zekâ araştırma yatırımı.

Bu firmaların sayısı sonradan çok arttı; bugün herkes yapay zekâ ve derin öğrenme kullanıyor.

### 2.3 Derin öğrenme basitçe nedir?

Elimizde doğrusal olmayan bir problem vardır. Aslında oturup yazmaya kalksanız matematiksel olarak ifade edebilirsiniz. Yapay sinir ağında olduğu gibi tasarlarken yapılan işlemleri biliriz; daha da indirgersek bunlar toplama, çarpma ve matris işlemleridir. Fakat değişken sayısı çok olduğu için denklemler gittikçe büyür ve karmaşıklaşır; sonuçta uzun kodlar ve çok sayıda işlem ortaya çıkar. Temelde basit, ama çok sayıda işlemin oluşturduğu yapılardır. Beynin basitleştirilmiş bir modelini kurma fikrinden yola çıkmışlardır.

> **Hocanın vurgusu:** Her şeye derin öğrenme ya da çok katmanlı bir çözüm uygulanmamalı; önce başka bir çözüm yolu var mı diye bakmak gerekir. Çok fazla parametreniz ya da veriniz yoksa derin öğrenme sizin için iyi bir fikir olmayabilir.

### 2.4 Kütüphaneler ve mimariyi anlamak

Bu kadar çok matematiksel işlem için tekrar tekrar kod yazmak zor olduğundan bugün pek çok kütüphane vardır ve herkes bunlardan yararlanır. Kimse sıfırdan yazmaz; böyle bir beklenti ya da gerek de yoktur.

> **Hocanın vurgusu:** Kütüphane kullanmak ayrı bir şeydir. Arkadaki mantığı anlamadan bir mimariyi kullanırsanız yenilikçi bir şey yapmış olmazsınız. Mimariyi bilinçli seçmek, hazır eğitilmiş modelleri ya da başka bir problemde işe yaramış modelleri değiştirebilmek için arkadaki mekanizmayı anlamak gerekir.

## 3. Sinir Ağları ile Derin Ağların Farkı

Slayt, sinir ağlarını birbirine bağlı nöronlar ve onları birleştiren kenarlardan oluşan bir ağ olarak tanımlar. Ana işlevi bir grup girdiyi almak, giderek karmaşıklaşan hesaplamalar yapmak ve çıktıyı bir problemi çözmek için kullanmaktır (ekrandan, 00:15:00). Hoca, buradaki "karmaşık" sözcüğünün işlemlerin içeriğini değil, sayısını anlattığını belirtir: toplamalar, çarpmalar ve fonksiyon uygulanarak yapılan hesaplamalar çok sayıdadır. Ağ test edilip belli bir hata oranına indirildiğinde artık problemle ilgili başka veriler verildiğinde de çözüm üretebilen bir ağ elde edilmiş olur.

Derin öğrenmede durum farklı değildir. Farklar şunlardır:

- Fonksiyon olarak kullanılan şeyler değişebilir; özellikle görüntü tarafında CNN'de filtreler kullanılır.
- Nöronların, başta kurulan mimarideki gibi kalması gerekmez; nöron sayısını azaltmak için başka teknikler uygulanabilir.
- Sinir ağında her nöron bir sonraki katmandaki her nörona bağlıydı. Derin ağlarda, özellikle filtre kullanılan CNN'de, böyle bir zorunluluk yoktur.

Bunların dışında temeldeki fonksiyonlar aynıdır.

## 4. Sınıflandırma ve Terminoloji

Slayta göre sinir ağları, bir nesnenin en az iki farklı kategoriden birine düşebildiği sınıflandırma işlerinde kullanılır. Şekilde bir giriş katmanı, iki gizli katman ve "Class 1", "Class 2" çıktılarını veren bir çıkış katmanı görülür (ekrandan, 00:20:00). Birbirinden ayıran özellikleri olan kümeleri ayırmak ve gruplamak için derin ağlar çok yaygın ve başarılı biçimde kullanılır.

Girdiler, sınıflandırılmak istenen şeyin özellikleri olarak düşünülmelidir. Örneğin bir kişinin boyu, kilosu ve ateşi gibi üç özelliğinden yola çıkılarak "hasta" ya da "değil" sınıflarından birine karar verilebilir.

Terminolojide iki fark vardır. Sinir ağlarında "hata" denen şeye derin öğrenmede çoğunlukla "skor" denir. Ayrıca "maliyet" (cost) terimi sık kullanılır; hata bizim açımızdan bir maliyettir, kastedilen şey aynıdır.

Temel bileşenler yine aynıdır: girdiler, beklenen çıktılar (sınıf ya da başka bir şey), ara katmanlar (bunlar mimariyle ilgilidir) ve öğrenme algoritması. Öğrenme algoritması eğitimin nasıl yapılacağını söyler; eğitim aşaması belli bir mimariye bir öğrenme algoritmasının uygulanmasıdır. Eğitimde yapılan şey bağlantı ağırlıklarını ayarlamaktır. Doğru ağırlık kombinasyonu bulunduğunda ağın başka girdiler için de doğru sonuç verme olasılığı artar.

Sınıflandırma için kullanılan diğer yaygın yöntemler lojistik regresyon (hocaya göre regresyonun özel bir hâli), <!-- BELİRSİZ: altyazıda "Esliyan" geçiyor; büyük olasılıkla SVM (destek vektör makinesi) --> SVM ve Naive Bayes'tir. Hoca bunları şunun için anar: problem çok karmaşık değilse, çok fazla özellik ve sınıf yoksa ve bu yöntemlerle çözülebiliyorsa doğrudan bunlar da kullanılabilir. Derin öğrenmenin var olan her şeyi silmesi gerekmez. Ödevdeki farklı fontlardan gelen harfleri ayırma problemi de bir çok katmanlı perceptronla çözülebilirdi; problem daha karmaşıksa daha fazla katman ekleyerek derin öğrenmeyle benzer problemler çözülebilir.

## 5. Derin Öğrenme Ne Zaman Kullanılmalı?

Hoca problemin karmaşıklığına göre üç durum ayırır:

- **Basit problem:** az sayıda parametre, az sayıda sınıf ve az örnek varsa klasik yöntemler iş görür; derin ağlarla uğraşmaya gerek yoktur.
- **Orta karmaşıklık:** biraz daha fazla özellik ve ikiden-üçten fazla sınıf varsa derin ağlarla başarı daha yüksek olur. Problemin önemi ve hesaplama kaynaklarına göre SVM ile de iş yapılabilir.
- **Karmaşık problem:** SVM gibi yöntemlerle sonuca gidilemez; derin ağlar en mantıklı, hatta tek seçenektir.

Derin ağların yarattığı etkinin en önemli sebebi, daha önce çözülemeyen problemlerin çözülebilir hâle gelmesidir. Doğada ve günlük hayatta karmaşık problemler vardı ama yöntem yoktu ya da mevcut yöntemler yetersizdi. Bu problemler çözülmeye başlayınca yeni alanlar açıldı.

Derin ağların bir dezavantajı eğitimin çok uzun sürmesidir. Çok katman ve çok hesaplama olduğu için GPU kullanımı neredeyse zorunludur; bugün problemler o kadar büyümüştür ki GPU olmadan derin ağ eğitmek neredeyse mümkün değildir. Fiyat da bir parametredir. Zaman açısından ise GPU'nun bir haftanın altında bitirdiği büyük bir eğitimi CPU haftalar ya da aylar içinde yapabilir; aradaki aksilikler buna dahil değildir.

## 6. Karmaşık Örüntülerin Katman Katman İşlenmesi

Bu bölüm neden fazla katman kullanıldığını ve bunun ne fayda sağladığını açıklar. Bir örüntü çok karmaşıksa içinde birden fazla ayırt edici özellik vardır. Örüntüyü parçalarına ayırmak ve bu özellikleri ayrıştırmak için farklı yöntemler kullanmak isteyebiliriz.

### 6.1 Yüz tanıma örneği

Slayttaki şekil yüz tanıyan bir derin ağın katmanlarını gösterir (ekrandan, 00:25:00 ve 00:30:00):

- **1. katman:** bilgisayar piksellerin açık ve koyu olduğunu belirler. Hoca bunu ten rengiyle ilgili, pikselleri koyu-açık diye sınıflandıran bir işlem olarak anlatır.
- **2. katman:** bilgisayar kenarları ve basit şekilleri tanımayı öğrenir.
- **3. katman:** daha karmaşık şekilleri ve nesneleri (dudak, burun, göz, kulak, kaş) tanımayı öğrenir.
- **4. katman:** hangi şekil ve nesnelerin bir insan yüzünü tanımlamak için kullanılabileceğini öğrenir; sonuçlar birleştirilerek yüzün bütünü oluşturulur.

Slaytın vardığı sonuç: basit örüntüleri yapı taşı olarak kullanıp karmaşık örüntüleri bulmak derin ağlara gücünü verir.

Hocaya göre bu katmanlardaki işlemler aktivasyon fonksiyonlarıdır: birinci katmanın aktivasyon fonksiyonu renk ve piksel koyuluğunu öne çıkarmalı, ikincisi kenar belirlemeye yönelik olmalıdır. Son katmanda tespit edilen özellikler bir bütün hâline getirilir ve elimizdeki örneklerden en çok hangisine benzediğine bakılarak kişi ya da yüz tanıma yapılır.

### 6.2 Konvolüsyonel ağların doğal çıkışı

Problemi böyle düşününce konvolüsyonel ağların ortaya çıkışı da doğal gelir. Her katman belli özellikleri (açık, koyu, kenar, daha karmaşık şekiller) tespit edecekse, görüntü işlemede kullanılan renk filtreleri ve kenar belirleme filtreleri gibi filtreleri kullanmak çok mantıklıdır. Klasik çok katmanlı perceptron gibi çok sayıda katman ekleyerek de belli bir başarıya ulaşılabilirdi. Ama her katmana daha belirli bir görev verip daha belirli filtreler kullanmak hem başarıyı artırır hem de işlemleri hızlandırır. Konvolüsyonel ağlar bu mantıkla ortaya çıkmıştır.

### 6.3 Filtreleri kim seçer?

Hoca, sık sorulan bir soruyu baştan cevaplar: filtreler bu kadar tasarlanarak mı seçilir?

- İş yüz tanıma gibi çok tanımlıysa, her yüzde bulunan özellikleri (ten rengi, keskin çizgiler, kaş, göz) ortaya çıkaracak filtreleri baştan düşünerek ve tasarlayarak seçmek çok doğaldır.
- Problem bu kadar ayırt edici değilse, örneğin görsellerin arka planları ya da büyük bölümleri birbirinden çok farklıysa, filtreleri sizin tasarlamanız pek anlamlı değildir. Temel filtreler katmanlara dağıtılır ve bununla başa çıkmak ağa bırakılır. Ağ ihtiyacı olmayan filtreleri kullanmayacak, o bağlantılar zayıflayacaktır.

Kararı derin ağ verir; biz yalnızca gereken araçları, görüntü işleme durumunda filtreleri, sağlarız. Hangisinin işe yaradığına ve ne kadar kullanılacağına ağ kendisi karar verir.

## 7. Probleme Göre Model Seçimi

Hangi derin ağ modelinin uygun olduğuna karar verirken önce elimizdeki veriye bakılır: verinin tipi nedir ve etiketli mi?

### 7.1 Etiketsiz veri

Veri etiketsizse seçenekler oldukça kısıtlıdır: otokodlayıcılar (autoencoder) ve Kısıtlı Boltzmann Makineleri (Restricted Boltzmann Machine, RBM). Otokodlayıcılarda veriyi verip bir etiketle eşleştirme işini ağa bırakırsınız. Birbirine benzeyen örüntüleri aynı etiketle, kalanları farklı etiketlerle eşleştirerek ağ sizin için otomatik etiketleme yapar. Bu yüzden RBM'ler ve otokodlayıcılar genellikle özellik çıkarma (feature extraction) ve örüntü tanıma problemlerinde kullanılır. Veri etiketsiz olduğu için öğrenme de gözetimsizdir (unsupervised). Benzer özellikleri olanları aynı gruba koymak bir tür özellik çıkarmadır.

### 7.2 Etiketli veri

Veri etiketliyse seçenekler daha fazladır ve problemin türüne göre seçim yapılır (ekrandan, 00:35:00):

| Problem | Önerilen ağ |
|---|---|
| Metin işleme (Text Processing) | RNTN (Recurrent Neural Tensor Network), tekrarlayan ağ |
| Görüntü tanıma (Image Recognition) | DBN, konvolüsyonel ağ |
| Nesne tanıma (Object Recognition) | RNTN, konvolüsyonel ağ |
| Konuşma tanıma (Speech Recognition) | Tekrarlayan ağ |

Hocanın açıklamaları:

- **Geçmişle ilişkili veri:** ses işleme, video işleme ya da zaman serisi gibi problemlerde şu andaki veri bir önceki, iki önceki veriden etkileniyorsa tekrarlayan (recurrent) ağlar kullanılır. "Geçmiş" yalnız zaman anlamında değildir; sıradaki önceki verilerle ilişki kastedilir. Konuşmanın içinde bir bütünlük vardır; lafa nereden başladığınız nasıl bitireceğinize dair ipucu taşır.
- **Metin işleme:** duygu analizi (sentiment analysis), ayrıştırma (parsing), isimlendirilmiş varlık tanıma ve karakter seviyesinde çalışan dil modelleri üzerindeki işlemler RNTN ya da tekrarlayan ağlarla yapılabilir. Harf bazında önceki harfler, kelime bazında önceki kelimeler sonrakini etkilediği için tekrarlayan yapılar tercih edilir.
- **Görüntü tanıma:** görüntüden bir nesneyi tanımak ya da görüntüyü "manzara", "futbol" gibi bir etiketle eşleştirmek için konvolüsyonel ağlar ve DBN kullanılır. Konvolüsyonel ağların artık pek çok çeşidi vardır.
- **Nesne tanıma:** RNTN tekrarlayan bir yapı olduğu için akan bir sahnede sahneler arasındaki ilişkiyi de kullanabilir. Örneğin önceki sahnede yaya yokken bir araba gelir; burası araba yolu, şurası yaya geçidi, bir de dur işareti var. Yaya geçidinin üzerinde yeni bir nesne görüldüğünde önceki bilgiler seçenekleri azaltır ve bunun bir yaya olduğu anlaşılır. Konvolüsyonel ağda ise doğrudan anlık sahneye bakılıp her nesnenin özelliği çıkarılarak ayrı ayrı etiketlenir. Hangisinin seçileceği, işleme bakış açınıza bağlıdır.
- **Konuşma tanıma:** vurgular, vurgunun konuşmanın neresinde yapıldığı, kişiden kişiye değişen ses tonu, uzatma ve kısaltma gibi özellikler ancak belli bir süre boyunca incelenirse doğru ayrılabilir. Bu yüzden tekrarlayan ağlar doğru seçenektir.

### 7.3 Genel durumlar

Slaytın genel tablosu iki satırdır (ekrandan, 00:40:00):

| Problem | Önerilen ağ |
|---|---|
| Sınıflandırma (Classification) | MLP/ReLU (Rectified Linear Units), Deep Belief Net |
| Zaman serisi analizi (Time Series Analysis) | Tekrarlayan ağ |

Sınıflandırma için çok katmanlı perceptron kullanılabilir. Hocaya göre sinir ağlarındaki çok katmanlı ağa "derin ağ" demeye başladığımız noktada değişen tek şey, aktivasyon fonksiyonunun ReLU (Rectified Linear Unit) olarak seçilmesidir. Zaman serisi analizinde, ardışık durumların birbiriyle ilişkili olduğu durumlarda tekrarlayan ağlar kullanılır. Zaman serileri genellikle yıllara bağlı değişen istatistiksel verilerdir; en çok finans alanında, zamana bağlı değişimin geleceğe dair tahmini kolaylaştırdığı verilerde karşımıza çıkar.

## 8. Gradyan Kaybolması ve Gradyan Patlaması

### 8.1 Neden bu kadar uzun sürdü?

Çok katmanlı perceptrondan derin ağlara geçiş yaklaşık 20 yıl sürmüştür; sinir ağlarının geçmişi sayılırsa 50 yılı aşkın bir geçmiş vardır. Fikirler ortadayken neden bu kadar sürdüğünün nedeni eğitimin zorluğu ve hesaplamaların karmaşıklığıdır. Doğrusal olmayan problemleri çözebilen çok katmanlı perceptron ve geri yayılım algoritmasının çıkışından bu yana bile onlarca yıl geçmiştir.

Geri yayılımı çok katmanlı ağlarda bugünkü gibi kullanamamamızın temel nedeni gradyan kaybolması (vanishing gradient) problemidir. Bu problemin çözülmesi ve GPU'ların sahneye çıkmasıyla derin ağlar kullanılabilir hâle geldi.

Slayt şunları söyler (ekrandan, 00:45:00): eğitim sırasında sürekli bir maliyet değeri hesaplanır; gradyan maliyetin değişim hızını ölçer. Şekildeki ifadeye göre gradyan, maliyetin bir ağırlığa ya da bias'a göre değişim hızıdır. Slayta göre 2006'ya kadar derin ağlar temel bir problem yüzünden doğru eğitilemiyordu: gradyan kaybolması ya da patlaması.

### 8.2 Mekanizma

Hesaplamalar sinir ağında da, DBN'de de, derin ağda da aynı şekilde yapılır. Bir nörona giren toplam değer, önceki nöronların çıktılarının bağlantı ağırlıklarıyla çarpılıp toplanmasıdır. Orada bir fonksiyon uygulanır ve hesap ileri doğru yürür. Geri yayılımda çıkışta bir hata hesaplanır: beklenen değer ile hesaplanan değer arasındaki farkın karesi. Bu hataya etki eden ağırlıkları ayarlamak için hata geriye yayılır. Sorun bu geriye yayma kısmındadır.

Geri yayılım, her ağırlığın hataya ne kadar etki ettiğini bulmayı ve hata fonksiyonunu küçültmek için gradyanın tersi yönünde gitmeyi söyler. Bunun için hatanın kısmi türevi hesaplanır. Geriye yayarken bu türev küçük bağlantı ağırlıklarıyla çarpılır. Gradyanların açılımında zincir kuralı kullanıldığı için en az üç-dört kısmi türev yan yana çarpılır. Katman sayısı arttıkça bu çarpmaların sayısı artar ve elimizdeki değer küçülür. Giriş katmanına yaklaşıldığında gradyan sıfıra yakın bir değere düşer. Buna gradyan kaybolması denir.

> **Ders sonrası not:** Hoca, hatayı bir değişkene göre türevlemenin değeri tek başına küçülttüğünü söyler ("hata 3 birimdiyse türevini aldım, küçülttüm"). Türev almak tek başına değeri küçültmek zorunda değildir. Kaybolmanın asıl nedeni, slaytta da yazdığı gibi, mutlak değeri 1'den küçük çok sayıda çarpanın (aktivasyon türevleri ve ağırlıklar) zincir kuralıyla art arda çarpılmasıdır.

Bunun zararı şudur: ağırlıklar gradyanlar oranında değiştiriliyordu. Gradyan sıfıra yakınsa o ağırlıklardaki ayarlama oranı da sıfıra yakın olur. Sona yakın katmanlardaki ağırlıklar görece büyük ölçüde değişirken, başa yakın katmanlardaki ağırlıklar gittikçe daha az değişir.

### 8.3 Yokuştan yuvarlanan top benzetmesi

Gradyan geometrik olarak eğimi gösterir. Algoritmayı, gradyanın gösterdiği yokuştan yuvarlanan bir top olarak düşünebilirsiniz. Yokuş dikse top hızlı yuvarlanır; bu hızlı bir eğitim demektir. Eğim küçüldükçe yüzey düz bir zemine benzer ve top kendi kuvvetiyle neredeyse kıpırdamaz. Öğrenme de ya hiç olmaz ya da çok yavaş olur.

### 8.4 Çelişki: en önemli katmanlar en yavaş öğrenir

Slayttaki "Conflict" başlıklı şekil, gradyanın erken katmanlarda potansiyel olarak daha küçük olduğunu, yani ağın erken katmanlarının en yavaş eğitildiğini gösterir. Oysa erken katmanlar yapı taşlarındaki basit örüntüleri bulmaktan sorumludur (ekrandan, 00:50:00). Yüz örneğinde ilk katmanlar tespit edilecek şeyin en temel özelliklerini veriyordu. Bu katmanlarda öğrenme yavaş kalırsa ağ çok ayrıntıyı tespit edebilir ama ana yapı taşlarını tespit edemez. Bu da bizi oldukça yanlış sonuçlara, örneğin yanlış sınıflara atamaya götürebilir.

Aradan sonra hoca bunu görsel bir yüz tanıma örneğiyle gösterir: kaş, göz, hatta burun oldukça düzgün tespit edilmiştir, ama yüzün şeklini veren ana bloğun tespitinde ciddi bir sorun vardır. İlk katmanlardaki problemler sonucu dramatik biçimde etkileyip yanlış tespite yol açabilir. <!-- BELİRSİZ: bu görsel örneğin karesi yok; anlatım altyazıdan alındı -->

### 8.5 Gradyanların katlanarak çarpılması

Hoca geri yayılım adımına biraz daha yakından bakar. İki çıktı varsa iki çıktının bireysel hataları hesaplanıp toplanıyordu; türevde de iki hatanın gradyanı alınır. İki gradyan, iki küçük değer bir düğüme gelir; sonra önceki düğümlere dağılır. Görece basit bir yapıda bile dört gradyan hesaplanır ve bunlar katlanarak önceki katmana gelir. Karmaşık bir yapıda çok sayıda bağlantı ve çok sayıda çarpma vardır.

Slayttaki açıklama şöyledir (ekrandan, 01:10:00): ağın her ağırlığı, eğitimin her yinelemesinde hata fonksiyonunun o ağırlığa göre gradyanıyla orantılı bir güncelleme alır. Hiperbolik tanjant gibi geleneksel aktivasyon fonksiyonlarının gradyanları $(-1, 1)$ ya da $[0, 1)$ aralığındadır ve geri yayılım gradyanları zincir kuralıyla hesaplar. Bunun sonucu, $n$ katmanlı bir ağda ön katmanların gradyanını hesaplamak için bu küçük sayılardan $n$ tanesinin çarpılmasıdır; gradyan (hata sinyali) $n$ ile üstel olarak azalır ve ön katmanlar çok yavaş eğitilir. Şekildeki ifade: bir katmandaki gradyan, önceki katmanlardaki gradyanların çarpımıdır.

Hoca bunu önceki dersteki ağırlık güncelleme kuralıyla bağlar: ağırlık değişimi "hatanın gradyanı × öğrenme katsayısı × girdi" biçimindeydi. Bu çarpanlardan biri sıfıra yakınsa ağırlığın değişimi de sıfıra yakın olur. Eğitim ağırlıkların ayarlanması olduğuna göre, ağırlıkları değiştiremiyorsak o katmanı eğitemiyoruz demektir. Son katmanlar hatayı çok daha iyi düzeltirken ilk katmanlar düzgün eğitilmemiş olur.

### 8.6 Gradyan patlaması

Akla şu soru gelir: aktivasyon fonksiyonlarının türevini alıyoruz; farklı bir fonksiyon kullanıp bu aralıkları biraz büyütsek olmaz mı? Bu denenmiştir. Ama bu kez büyütülmüş sayılar çarpılmaya başlar; ilk katmandaki eğitim çok hızlanır ve ağırlık değişimleri çok büyük olur. Buna gradyan patlaması (exploding gradient) denir. Slayt da türevleri büyük değerler alabilen aktivasyon fonksiyonları kullanıldığında gradyan patlaması riskinin doğduğunu söyler (ekrandan, 01:10:00).

Böylece geri yayılımda gradyanla ilgili iki problem vardır: gradyan kaybolması ve gradyan patlaması. Bu problem uzun süre devam etmiştir.

### 8.7 Çözüm: ReLU

Hocaya göre çözüm bir doktora tezinde yapılan çalışmadan gelmiştir ve çok zor bir çözüm değildir: daha önce de bahsedilen doğrultulmuş doğrusal birim (Rectified Linear Unit, ReLU). ReLU ile değerin büyümesine bir ölçüde izin verilir, sıfırın altına düşmesine ya da çok küçülmesine izin verilmez. Böylece gradyanın patlaması ya da kaybolması önlenir. Derin ağlarda artık aktivasyon fonksiyonu olarak ReLU kullanılır; konvolüsyonel ağlardaki ReLU katmanı da bu aktivasyon fonksiyonudur. <!-- BELİRSİZ: 01:10:58-01:11:12 arası altyazıda boşluk var; ReLU'nun tanımının ekranda gösterildiği bu anın karesi yok -->

Hoca ayrıca Leaky ReLU'dan söz eder ve "ReLU'nun sızdırması" diye bir durum olduğunu, değerin sıfırın altına düşebilmesiyle ilgili olduğunu söyler; bu konuya ileride değinileceğini belirtir. Bu tür sorunlara karşı önlemler alınabildiği için geri yayılım istenildiği kadar çok katmanlı bir derin ağda uygulanabilir hâle gelmiştir. Teorik taraf böyledir; pratikte işlem yükü CPU ile başa çıkılamayacak kadar büyüktür ve bu da GPU'larla çözülmüştür.

> **Ek bilgi (derste anlatılmadı):** ReLU genellikle $f(x) = \max(0, x)$ olarak tanımlanır; türevi $x > 0$ için 1, $x < 0$ için 0'dır. Pozitif bölgede türev 1 olduğu için zincir kuralındaki çarpanlar küçülmez. Negatif girdilerde türev 0 olduğundan bazı nöronlar hiç güncellenmeyebilir ("ölü ReLU"). Leaky ReLU bu yüzden negatif bölgede küçük bir eğim bırakır, örneğin $f(x) = \max(\alpha x, x)$ ve $\alpha$ küçük bir sabittir.

> **Hocanın vurgusu:** Özellikle tez aşamasında derin ağ kullanmayı düşünenler, Hinton, LeCun ve Bengio'nun 2006-2007 arasında yayımladığı ve önemli gelişmeleri başlatan ilk makalelerine mutlaka bakmalıdır.

Derin ağ kullanıldığında eğitim uzun sürer, ama iyi bir güvenilirlik ve doğrulukla tahmin yapılabilir. Geri yayılım ve GPU varsa ideal bir çözüme ulaşılmış olur.

### 8.8 Diğer önerilen çözümler

Ders sonundaki özet slaytında hoca başka çözümlerden de söz eder:

- 1992'de çok seviyeli hiyerarşi (multi-level hierarchy) kullanmayı öneren bir yayın vardır; ama her durumda uygulanamadığı için fazla etkisi olmamıştır.
- Belirli problemlerde kullanılabilen, genele yayılamayan başka bir çözüm de önerilmiştir.
- Gradyanın yalnız işaretinden yararlanmak: değer çok küçük olacağı için büyüklüğü kullanılmaz; gradyanın tersi yönünde gidileceği için yalnız işarete bakılır. Gradyan eksiyse ağırlık bir birim azaltılır, artıysa bir birim artırılır.

Bunların hepsi kullanılabilir, ama modern derin ağlarda ReLU yeterli çözümü sağlıyor gibidir. Literatürde ek mekanizmaların kullanıldığı çalışmalara da rastlanabilir.

> **Ek bilgi (derste anlatılmadı):** 1992 yayını büyük olasılıkla Jürgen Schmidhuber'in her seviyesi ayrı ayrı eğitilen çok seviyeli ağ hiyerarşisi çalışmasıdır. Yalnız gradyanın işaretini kullanan yöntem büyük olasılıkla Rprop (resilient backpropagation) ailesidir. Rprop'ta her ağırlığın kendi adım büyüklüğü vardır ve bu adım, gradyanın işareti değişip değişmemesine göre büyütülür ya da küçültülür.

## 9. Kısıtlı Boltzmann Makineleri (RBM)

### 9.1 Yapı

Slayta göre RBM, Geoffrey Hinton'ın Toronto Üniversitesi'nde ortaya koyduğu bir yapıdır (ekrandan, 01:15:00). Boltzmann makinesi yeni bir kavram değildir; Boltzmann'ın fizikte (hocanın deyişiyle mekanik ve dinamikte) çok kullanılan teorisine dayanır. Hinton'ın rolü bunu buraya uyarlamaktır.

RBM iki katmanlı bir yapıdır. Yalnız iki katman olduğu için adlandırma farklıdır: görünür katman (visible layer) ve gizli katman (hidden layer). "Kısıtlı" (restricted) olması, aynı katmandaki nöronlar arasında bağlantı olmamasıdır. Tekrarlayan ağlar gibi bazı özel durumlar dışında ileri beslemeli ağlarda zaten böyle bağlantılar yoktu, ama burada bir kısıt olarak açıkça belirtilir.

RBM bir tür çift yönlü çeviri gibi düşünülebilir. Birinci katmandaki girdiler ikinci katmanı oluşturur; ikinci katmanda oluşanların da kendisini oluşturan birinci katman girdilerini yeniden oluşturması beklenir. A'nın karşılığı B ise B'nin karşılığı da A olmalıdır; bir tür çift yönlü çağrışım. İyi eğitildiğinde RBM bu çift yönlü dönüşümü yapabilir. Bu da etiketsiz bir veriyi bir çeşit kod çözme (decode) ya da etiketleme işlemine sokabilmek demektir.

### 9.2 Eğitim

Eğitim biraz geri yayılıma benzer, ama sondaki hatayı belirlemek için kullanılan yapı farklıdır. Slayta göre eğitim süreci boyunca üç adım tekrar tekrar uygulanır (ekrandan, 01:20:00):

- **A. İleri geçiş (forward pass):** her girdi kendi ağırlığı ve ortak bir bias ile birleştirilir; sonuç gizli katmana aktarılır ve gizli nöron etkinleşebilir ya da etkinleşmeyebilir.
- **B. Geri geçiş (backward pass):** her aktivasyon kendi ağırlığı ve ortak bir bias ile birleştirilir; sonuç yeniden oluşturma (reconstruction) için görünür katmana aktarılır.
- **C. Karşılaştırma:** görünür katmanda yeniden oluşturulan değer, sonucun kalitesini belirlemek için asıl girdiyle karşılaştırılır.

Şeklin başlığı "girdiyi yeniden oluştur" (recreate input), alt yazısı "KL ıraksaması = asıl girdiyi yeniden oluşturulanla karşılaştır" şeklindedir. Hoca, oklar artık çift yönlüymüş gibi düşünülebileceğini söyler. İleri adımda bir nöronu besleyen bağlantılar hangileriyse, geri adımda o nöronun değeri aynı bağlantılar üzerinden dağılır.

Burada kıyaslanacak bir etiket yoktur; girdiye karşı ne beklendiği bilinmez. Ama şu beklenir: girdilerden ne üretildiyse, o çıktılar aynı girdileri geri üretebilmelidir. Yani ağ kendisiyle kıyaslanır; ürettiği sonuç kendisini geri üretebiliyor mu diye bakılır. Bu karşılaştırmaya göre bağlantı ağırlıkları değiştirilir. Eğitim kuralında kullanılan ölçüt Kullback-Leibler (KL) ıraksamasıdır.

> **Ek bilgi (derste anlatılmadı):** RBM'ler pratikte büyük olasılıkla Hinton'ın önerdiği karşıtsal ıraksama (contrastive divergence, CD-k) ile eğitilir. Bu yöntem, veri dağılımı ile modelin dağılımı arasındaki KL ıraksamasını azaltmaya yaklaşık olarak karşılık gelir. Güncelleme, verideki görünür-gizli birlikte etkinleşme ile kısa bir yeniden oluşturma zincirinden sonraki birlikte etkinleşme arasındaki farkla yapılır.

### 9.3 Etiketsiz veri ve özellik çıkarma

Slayta göre RBM'in ilginç bir yanı verinin etiketlenmesine gerek olmamasıdır (ekrandan, 01:25:00). Veriyi elle etiketleyip hata katmak yerine RBM veriyi otomatik olarak tarar; ağırlıkları ve bias'ları uygun biçimde ayarlayarak önemli özellikleri çıkarır ve girdiyi yeniden oluşturur. RBM aslında hangi girdi özelliklerinin önemli olduğuna ve örüntü oluşturmak için bunların nasıl birleştirileceğine karar verir. RBM, verideki içkin örüntüleri tanımak için tasarlanmış özellik çıkarıcı sinir ağları ailesinin bir üyesidir. Şekilde RBM "örüntü tanıyıcı" (pattern recognizer) ve "otokodlayıcı" diye etiketlenmiştir.

Hoca RBM'i bir tür otokodlayıcı olarak görür: girdiler belli bir çıktı üretir ve bu çıktı girdinin etiketi gibi düşünülebilir. Aynı gruptaki örneklerin birbirine yakın çıktılar ürettiği düşünülürse RBM bir etiketleme aracı olarak da kullanılabilir. Bu sırada verinin özellikleri çıkarılmış olur. Elle etiketlerken ya da gözle bakarken göremeyeceğimiz özellikleri böyle bir yapının bulması daha kolay ve daha sağlıklı olabilir.

Bu bazen daha doğru etiketlere de yol açar, çünkü insanın görüntü etiketlerken bir miktar ön yargısının olmaması imkânsızdır. Hocanın örneği: çimenlerin üzerinde top oynanan bir görüntüde futbol meraklısı biri topu ya da futbolu görür; doğaya meraklı biri yeşilliği ya da manzarayı görür. RBM gibi bir yapıya bırakılırsa görüntüde oransal olarak hangisinin ağır bastığını bulması büyük olasılıkla daha doğru ve sağlıklı olur.

### 9.4 RBM her zaman kullanılmalı mı?

RBM çok cazip görünse de her zaman kullanılmaz. Girdi sayısı çoksa ve fazla katman kullanılırsa çok ayrıntılı özellikler de ele alınır; bu kadar ayrıntı istenmeyen durumlar olabilir. Boşuna hesaplama yapıp gereğinden ince ayrıntılar ve çok sayıda sınıf ya da etiket yaratmak istemeyebilirsiniz. Veriniz zaten etiketliyse bu hesaplamalara hiç girmek istemeyebilirsiniz. Duruma göre karar vermek gerekir. Ama hakkında hiç fikriniz olmayan, sağlıklı etiketleyemeyeceğinizi düşündüğünüz veriler için RBM çok güçlü bir araçtır.

## 10. Kullback-Leibler Iraksaması

KL ıraksaması bir ölçüt, bir kıyaslama parametresidir ve daha çok dağılımların kıyaslanmasında kullanılır. Hoca bunu olasılık teorisindeki bir durumla anlatır. Gerçek hayattan gelen ve bilinen, formülü olan dağılımlara tam benzemeyen bir dağılımınız olsun; örneğin Gauss'a benziyor ama tam oturmuyor, bazı sapmalar var. Bunu Gauss dağılımıyla temsil ettiğinizde yaptığınız hatayı, yani modelinizle gerçek veri arasındaki farkı ölçen ölçüttür. Dağılımlar kesikli ya da sürekli olabilir; ölçülen şey iki dağılım arasında ne kadar sapma olduğudur. Bilgi kuramından (information theory) gelir.

RBM'de de durum budur: girdilerin gösterdiği değerler ve çıktıların bu girdileri yeniden ürettiği değerler iki grafik gibi düşünülür. Bunlar üst üste konduğunda aradaki farkı ya da mesafeyi ölçen ölçüt KL ıraksamasıdır. RBM bunu başarı ölçütü olarak kullanır.

Slayttaki açıklamanın ana noktaları şunlardır (ekrandan, 01:40:00):

- Olasılık kuramı ve bilgi kuramında KL ıraksaması; ayrım bilgisi (discrimination information), bilgi ıraksaması, bilgi kazancı (information gain), göreli entropi (relative entropy), KLIC ya da KL ıraksaması diye de anılır. İki olasılık dağılımı $P$ ile $Q$ arasındaki farkın bir ölçüsüdür ve $P$ ile $Q$'ya göre simetrik değildir. Uygulamalarda $P$ genellikle verinin "gerçek" dağılımını, $Q$ ise bir kuramı, modeli ya da $P$'nin bir yaklaşığını temsil eder.
- $Q$'dan $P$'ye KL ıraksaması $D_{KL}(P \| Q)$ diye gösterilir. Önsel dağılım $Q$'dan sonsal dağılım $P$'ye geçildiğinde kazanılan bilgidir; başka bir deyişle $P$'ye yaklaşmak için $Q$ kullanıldığında kaybedilen bilgi miktarıdır. $P$'den gelen örnekleri $P$ için değil de $Q$ için optimize edilmiş bir kodla kodlamak için gereken beklenen fazladan bit sayısını da ölçer.
- Sezgisel olarak dağılımlar arası uzaklık gibi düşünülse de gerçek bir metrik değildir: üçgen eşitsizliğine uymaz ve genelde $D_{KL}(P \| Q) \neq D_{KL}(Q \| P)$'dir. Sonsuz küçük biçiminin Hessian'ı ise Fisher bilgi metriği denen bir metrik tensör verir.
- f-ıraksamaları ve Bregman ıraksamaları sınıflarının özel bir hâlidir; olasılıklar üzerinde her iki sınıfa da üye olan tek ıraksamadır.
- 1951'de Solomon Kullback ve Richard Leibler tarafından iki dağılım arasındaki yönlü ıraksama olarak tanıtılmıştır.

> **Ek bilgi (derste anlatılmadı):** Kesikli dağılımlar için tanım $D_{KL}(P \| Q) = \sum_x P(x) \log \dfrac{P(x)}{Q(x)}$, sürekli dağılımlar için $D_{KL}(P \| Q) = \int p(x) \log \dfrac{p(x)}{q(x)} \, dx$ biçimindedir. Değer her zaman sıfır ya da pozitiftir ve yalnız iki dağılım aynıysa sıfır olur. Logaritma 2 tabanında alınırsa birim bittir.

## 11. Derin İnanç Ağları (DBN)

### 11.1 Yapı

Derin inanç ağı (Deep Belief Network, DBN) yapısal olarak klasik MLP'nin çok katmanlı hâline benzer: çok sayıda gizli katmanı olan, her şeyin birbirine bağlı olduğu (fully connected) bir çok katmanlı perceptron. Görüntüde konvolüsyonel ağlar öne çıksa da başka sayısal veri ve problemlerde, problem çözülebilir bir problemse DBN büyük olasılıkla doğru sonuca götürür. Çok katmanlı perceptron için söylendiği gibi, optimum parametreler bulunabiliyorsa onları bulacak yapı budur.

DBN bir bütün olarak giriş katmanı, çıkış katmanı ve gizli katmanlar diye adlandırılır. Ama eğitim sırasında katman çiftleri görünür ve gizli katman olarak ele alınır ve RBM gibi eğitilir.

### 11.2 Eğitim: ön eğitim

DBN'nin eğitimi geri yayılımdaki sorunlar nedeniyle farklılaşır ve bir açıdan işlem yükünü de azaltır. DBN arka arkaya dizilmiş çok sayıda RBM gibi düşünülebilir. Eğitim MLP gibi değil RBM gibi yapılır: katmanlar kendi aralarında eğitilir. Önce birinci ve ikinci katman RBM gibi birbirini eğitir. Sonra birinci katman geride bırakılır; ikinci ve üçüncü katman kendi arasında eğitilir ve bu böyle sürer.

Bunun mantığı şudur: birinci ve ikinci katman birlikte eğitildiğinde ikinci katman, birinci katmanda önemli olan özellikleri barındıran bir sonuç üretir; yani birinci katmanı da temsil eder. Bu yüzden birinci katmanı artık dikkate almak gerekmez. MLP'deki geri yayılım gibi hatayı en sondan en başa kadar dağıtıp ayarlama yapmaya gerek kalmaz. Bilgi ve özellikler toplana toplana sona doğru giden bir yapı ortaya çıkar. Son katmana gelindiğinde, her işlem sırasında girdilerden farklı özelliklerin çıkarıldığı ve bütün bilginin taşındığı bir yapı elde edilir.

Slayt şunları söyler (ekrandan, 01:30:00): bu işlem ağdaki her katman eğitilene kadar tekrarlanır ve her RBM katmanı girdinin tamamını öğrenir. CNN gibi diğer ağlarda erken katmanlar basit örüntüleri bulur, sonraki katmanlar bunları yeniden birleştirir (yüz tanıma örneğindeki gibi). DBN ise model iyileştikçe girdinin tamamını art arda ince ayarlayarak bütünsel çalışır; slayttaki benzetmeyle, resme yavaş yavaş odaklanan bir kamera merceği gibi.

Hoca bu farkı şöyle anlatır: CNN örneğinde ilk katman yüzün ana bloğunu, sonrası kenarları, sonra kaşı ve gözü temsil ediyordu. DBN'de ise girdinin tamamı adım adım işlenir ve diğer özellikler de yanında taşınır. İlk başta bulanık bir görüntü ve birkaç temel özellik alınır; odaklandıkça ayrıntılar toplanır ve sonunda bütün resim oluşur.

**Soru:** Bu yapıda da veri etiketlenmemiş mi, RBM'deki gibi?
**Cevap:** Etiket gerekmez. En sonunda bir çıktı oluşur ve bu çıktıya sonradan bir etiket atanabilir. Güzel yanı şudur: etikete ne ad verilirse verilsin, çıktının sayısal olarak temsil ettiği şey doğrudur, çünkü özelliklerden gelir. Etiket verilmemiş olsa da elde edilen çıktı sayısal olarak özgün olduğu için bilgiyi, bir anlamda etiketini, üzerinde taşır.

### 11.3 İnce ayar

Slayta göre bu ilk eğitimden sonra RBM'ler verideki içkin örüntüleri bulabilen bir model oluşturmuştur, ama örüntülerin ne diye adlandırıldığı hâlâ bilinmez. Eğitimi bitirmek için örüntülere etiketler verilir ve ağ gözetimli öğrenmeyle ince ayardan (fine tuning) geçirilir (ekrandan, 01:35:00).

Hoca bunu az önceki etiket meselesinin karşılığı olarak görür. Verinin bir kısmı etiketlenebiliyorsa ve bu etiketli örnekler eğitime katılırsa, ağın oluşturduğu etiketler desteklenmiş ve sınırlanmış olur. DBN'yi bu şekilde kullanmak daha etkilidir; hem ağın bütününün güvenilirliği artar hem de etiketleme işi sınırlanır. Az miktarda etiketli veriyle ağa son bir iyileştirme uygulanabilir.

Faydaları şöyle özetlenir:

- Az miktarda etiketli veri yeterlidir.
- Katmanlar ikişer ikişer eğitildiği için hesaplamalar uzun bir yolu geri dönmez; eğitim süresi makul kalır.
- Güvenilirlik artar.
- GPU kullanıldığında eğitim makul bir sürede biter.

## 12. Konvolüsyonel Sinir Ağları (CNN)

### 12.1 Tarihçe

Konvolüsyonel ağların çıkışı için Yann LeCun'un yayınlarına bakılabilir. Hocanın slaytları birkaç yıl öncesine ait olduğu için emin değildir, ama LeCun Facebook'un yapay zekâ direktörüydü ve Facebook'taki yüz tanıma gibi derin öğrenme algoritmalarının arkasındaki kişiydi.

Hoca konvolüsyonel ağların 2015'lerin başında çıktığını söyler; Microsoft ve Google'ın çalışmaları vardır. Bunun yanında ImageNet yarışması vardır ve konvolüsyonel ağların faydaları ilk orada görülmeye başlanır. 2012'de Geoffrey Hinton'ın takımı, bir görüntü işleme yarışması olan ImageNet'te konvolüsyonel ağlara benzer bir yapı, yani derin bir CNN kullanarak 2012'nin en başarılı sonucunu elde eder. Bunun üzerine diğer takımlar da derin ağları yoğun olarak kullanmaya başlar. Hocaya göre önceden derin öğrenme kullanan takımların oranı yüzde 10-20 civarındayken 2014'te ImageNet'te neredeyse herkes derin öğrenme kullanır hâle gelir. 2015'te Microsoft ve Google'ın başarılarından sonra derin ağlar, özellikle konvolüsyonel ağlar, gittikçe popülerleşir. <!-- BELİRSİZ: hocanın gösterdiği 2012 ImageNet sonuç tablosunun karesi yok; oranlar altyazıdan alındı -->

> **Ders sonrası not:** Hoca konvolüsyonel ağların 2015'lerin başında çıktığını söyler. Konvolüsyonel ağlar büyük olasılıkla daha eskidir: LeCun'un CNN çalışmaları 1989'a, LeNet-5 1998'e uzanır. 2012 (AlexNet) ve 2015 (Microsoft'un ResNet'i, Google'ın Inception ağları), CNN'lerin ortaya çıktığı değil, ImageNet'teki başarılarıyla yaygınlaştığı yıllardır.

### 12.2 Fener benzetmesi

Hoca konvolüsyonel ağı bir benzetmeyle anlatır; bu benzetme CNN'in özellikle görüntüde neden başarılı olduğunu da canlandırır. Diğer veri tiplerinde CNN her zaman o kadar başarılı olmaz. Slayttaki maddeler şöyledir (ekrandan, 01:45:00):

- Bir duvar dijital bir görüntüyü temsil eder.
- Duvara bir dizi el feneri tutulur ve birbiriyle kesişen ışık daireleri oluşur.
- Fenerlerin amacı görüntüde kenar ya da renk karşıtlığı gibi belirli bir örüntüyü aramaktır.
- Her fener aynı örüntüyü arar, ama her biri görüntünün farklı bir bölümünde (ışık dairesinin belirlediği sabit bölgede) arar.
- Fenerler birlikte bir filtre oluşturur: bu filtre belirli bir örüntünün görüntüde olup olmadığını ve hangi bölgelerde olduğunu belirler.

Slayttaki ızgarada 8 sütun ve 6 satırdan oluşan kesişen daireler görülür. Hoca bunu 8 × 6'lık bir lamba ızgarası olarak anlatır; lambaların hepsi birlikte bir filtreyi temsil eder. Kesişim bölgeleri, filtrelerin her biri bir grup nöron gibi düşünülürse, ana görüntüde ortak baktıkları yerler ya da ortak bağlandıkları nöronlardır.

Sonra bir katman daha lamba eklenir; bu başka bir filtredir. Filtre 2, filtre 3, filtre 4 diye istenildiği kadar filtre eklenebilir. Dört filtre kullanan ve her filtrede 8 × 6 lamba bulunan bu ağ 8 × 6 × 4'lük bir konvolüsyonel ağ olarak adlandırılabilir. Her filtre farklı bir örüntü arar: kenar belirleme, renk ya da daha belirli şekiller. <!-- BELİRSİZ: 8 × 6 × 4 boyutunu ve bağlantıları gösteren slaytın karesi yok; boyut altyazıdan alındı -->

### 12.3 Bağlantılar ve ağırlık paylaşımı

Her nöron, aydınlattığı bölgedeki nöronlara bağlıdır. Arkadan gelen filtre de benzer şekilde öndekine bağlanır. Aynı filtrenin bulunduğu katmandaki bağlantı ağırlıkları birbirinin aynısı olarak ayarlanır. Hocanın gösterdiği şekilde iki nöron aynı filtrenin parçasıdır ve her biri ana örüntüde dört nöronluk bir bölgeye bağlıdır; bu yüzden ağırlıkları birbirinin aynısıdır. Hocaya göre başlangıç değerleri de bu şekilde ayarlanır.

### 12.4 Katmanlar

Filtrelerin bulunduğu katmanlara konvolüsyon katmanı denir; filtre sayısı ve dolayısıyla katman sayısı değişebilir. Ardından ReLU katmanı ve havuzlama (pooling) katmanı gelir.

- **ReLU katmanı:** aktivasyon fonksiyonu ReLU'dur. Slayta göre CNN'ler geri yayılımla eğitildiği için gradyan kaybolması hâlâ olası bir sorundur. ReLU kullanımı gradyanın ağın her katmanında aşağı yukarı sabit kalmasına yardım eder. ReLU aktivasyonu, ağın kritik erken katmanlarda zararlı yavaşlamalar olmadan düzgün eğitilmesini sağlar (ekrandan, 01:50:00).
- **Havuzlama katmanı:** boyut azaltma için, ReLU'nun çıktısını küçültmek için kullanılır. Filtrelerle önemli özellikler bulunur; ReLU ile bunların bir kısmı önemsizleşir ya da birbirine benzer çıktılar üretir. Havuzlama gelen çok sayıdaki girdiyi azaltıp boyutu küçültür. Kullanılan bellek ve işlem gücünü sınırladığı için hesaplama açısından faydalıdır.
- **Tam bağlı katman (fully connected layer):** havuzlamanın çıkışındaki bütün nöronlar bu katmana bağlanır; bütün bağlantılar tamdır. Bu katmanın çıktısı bir etiketle, yani bir sınıfla ya da adlandırmayla ilişkilendirilir.

Bu katmanlardan yalnız birer tane olmak zorunda değildir. Farklı sayıda filtre içeren çok sayıda konvolüsyon katmanı, farklı sayıda ReLU ve havuzlama katmanı kullanılabilir. Ama CNN'de bulunması gereken temel katmanlar bunlardır.

Hoca, bu katmanların farklı sıralamalarla dizildiği ve sınıflandırma için önerilen bir mimari örneği gösterir: ağ verilen resmin ait olduğu sınıfı belirlemeye çalışır; tam bağlı katmanın çıktısı beş sınıfla ilişkilendirilmiştir ve buna göre bir etiketleme yapılır. <!-- BELİRSİZ: bu mimari örneğin karesi yok; katman sıralaması okunamadı -->

### 12.5 Dezavantajlar

- Gözetimli öğrenme kullanıldığı için etiketli veriye ve bu veriden çok sayıda örneğe ihtiyaç vardır; iyi bir eğitim ve başarılı bir mimari için bu gerekir.
- CNN bir görüntüyü tanır ya da sınıflar, ama bu sonuçla ne yapılacağı ayrı bir sorudur. Elde edilen sınıflama ya da tespit tek başına pek kullanılabilir değildir; mutlaka bir uygulama alanıyla ilişkilendirilmesi gerekir. Hoca bunun bir dezavantaj sayılmayabileceğini de ekler.

Ders sonunda "Recurrent Nets" başlıklı slayt açıktır: "Veriniz zamanla değişiyorsa ne yaparsınız?" (ekrandan, 01:55:00). Tekrarlayan ağlara bir sonraki derste devam edileceği söylenir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:18:34): Bayes ile Naive Bayes arasındaki ayrım nedir?

> **Çözüm (derste verilmedi):** Bayes teoremi $P(C \mid x) = \dfrac{P(x \mid C)\,P(C)}{P(x)}$ ilişkisidir ve bir sınıflandırıcı bunu kullanarak en yüksek sonsal olasılıklı sınıfı seçer. Çok özellikli bir girdide $P(x_1, \dots, x_d \mid C)$ ortak olasılığını kestirmek çok veri ister. Naive Bayes, sınıf bilindiğinde özelliklerin birbirinden koşullu bağımsız olduğunu varsayar ve $P(x_1, \dots, x_d \mid C) = \prod_i P(x_i \mid C)$ yazar. "Naive" (saf) sözcüğü bu basitleştirici bağımsızlık varsayımından gelir.

**Soru 2** (derste sözlü, 00:28:08): Derin bir ağda katmanlarda kullanılacak filtreleri tasarlayarak mı seçeriz?

> **Çözüm (derste verildi):** Duruma göre değişir. Yüz tanıma gibi çok tanımlı bir işte, her yüzde bulunan ten rengi, keskin çizgiler, kaş ve göz gibi özellikleri ortaya çıkaracak filtreleri baştan tasarlayarak seçmek doğaldır. Görsellerin arka planı ya da büyük bölümleri birbirinden çok farklıysa filtreleri tasarlamak anlamlı değildir. Temel filtreler katmanlara dağıtılır ve hangisinin kullanılacağına ağ karar verir; gereksiz filtrelerin bağlantıları zayıflar.

**Soru 3** (derste sözlü, 01:10:01): Gradyan kaybolmasını önlemek için türevleri daha büyük aralıkta değer alan bir aktivasyon fonksiyonu kullansak olmaz mı?

> **Çözüm (derste verildi):** Bu denenmiştir, ama bu kez büyük sayılar zincir kuralıyla art arda çarpılır; ilk katmanlardaki ağırlık değişimleri çok büyür. Bu da gradyan patlaması problemidir. İki sorunu birlikte büyük ölçüde çözen yaklaşım ReLU kullanmaktır.

**Soru 4** (derste sözlü, 01:31:17): DBN'de de veri etiketlenmemiş mi olur?

> **Çözüm (derste verildi):** Etiket gerekmez. Ağın sonunda oluşan çıktıya sonradan istenen etiket atanabilir; çıktı özelliklerden geldiği için sayısal olarak özgündür ve bilgiyi zaten taşır. Biraz etiketli veri varsa ince ayar adımında gözetimli öğrenmeyle kullanılarak etiketler desteklenir ve sınırlanır.

**Soru 5** (derste sözlü, 01:32:25): Nesne tespitinde ağ hem nesnenin konumunu hem de sınıfını vermelidir. Bu tek bir ağda mümkün mü, yoksa farklı ağlar mı gerekir?

> **Çözüm (derste verildi):** Bunun için neredeyse her gün yeni mimariler çıkıyor; tek bir doğru yol yoktur. Konuma dair ek girdiler (başka bir yerden bakan ikinci bir kamera, konum sensörleri gibi) varsa bunlar RGB bilgisiyle birlikte tek bir girdi olarak tek ağa verilebilir. Ya da iki ayrı ağ kullanılabilir: bir ağ konum girdilerini, diğeri RGB bilgisini işler ve sonuçlar son çıkarımı yapan bir ağda birleştirilir. Ya da biri önce, diğeri sonra işlenir. Hoca birkaç farklı mimariyi denemeyi önerir.

**Soru 6** (ekrandan, 01:55:00): Veriniz zamanla değişiyorsa ne yaparsınız?

> **Çözüm (derste bu slaytta verilmedi; cevap dersin önceki bölümünden):** Ardışık durumların birbiriyle ilişkili olduğu zaman serisi, konuşma ve metin gibi verilerde tekrarlayan ağlar kullanılır. Bu ağlar, şu andaki verinin önceki verilerle ilişkisini hesaba katabilir. Konu bir sonraki derste ayrıntılı işlenecektir.

## Dersin Toparlaması

Bu derste sinir ağlarından derin öğrenmeye geçildi. Derin öğrenme, temelde aynı hesaplamaları yapan ama çok daha fazla katman kullanan, ReLU aktivasyonu ve görüntüde filtreler kullanan sinir ağlarıdır. Çok boyutlu ve doğrusal olmayan karmaşık problemlerde derin ağlar en mantıklı seçenektir; basit problemlerde ise klasik yöntemler yeterlidir. Derin ağlar karmaşık örüntüleri katman katman ayrıştırır: ilk katmanlar basit yapı taşlarını, sonraki katmanlar bunların birleşimlerini öğrenir. Model seçiminde verinin etiketli olup olmadığı ve problemin türü belirleyicidir. Etiketsiz veri için RBM ve otokodlayıcılar, sıralı veri için tekrarlayan ağlar, görüntü için CNN ve DBN kullanılır.

Derin ağların uzun süre kullanılamamasının nedeni geri yayılımdaki gradyan kaybolması ve patlaması problemleriydi. Zincir kuralıyla küçük sayıların art arda çarpılması, en önemli işi yapan ilk katmanların eğitilememesine yol açıyordu. ReLU bu problemi büyük ölçüde çözdü, GPU'lar da hesaplama yükünü taşıdı. Ardından girdiyi yeniden oluşturup KL ıraksamasıyla kıyaslayarak etiketsiz veriden özellik çıkaran RBM, RBM'lerin üst üste dizilip ikişer ikişer ön eğitildiği ve az etiketli veriyle ince ayar yapılan DBN, ve konvolüsyon, ReLU, havuzlama ve tam bağlı katmanlardan oluşan CNN tanıtıldı. Bir sonraki derste tekrarlayan ağlara geçilecek ve konular daha ayrıntılı ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
