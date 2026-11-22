# Ders 1 Genişletilmiş Notu: Sayısal Analize Giriş, Sayıların Gösterimi ve Hata Kavramı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve İşleyişi
- 2. Dersin Konularına Genel Bakış
- 3. Analitik Çözüm ve Sayısal Çözüm
- 4. Sayıların Gösterimi
- 5. Anlamlı Basamak, Kayan Nokta, Kesme ve Yuvarlama
- 6. Doğruluk ve Hassasiyet
- 7. Hata ve Yanlış
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Amacı ve İşleyişi

Sayısal analiz, adı biraz değişerek hemen her bölümde okutulan bir derstir: makine ve inşaat mühendisliğinde, işletme, iktisat ve finans gibi bölümlerde, hatta bazı sosyal bölümlerde vardır. İngilizce kaynaklarda *numerical methods* ya da *numerical analysis*, Türkçede sayısal yöntemler ya da sayısal analiz diye geçer.

Bu ders, yapısal programlamaya giriş dersini destekleyecek biçimde tasarlanmıştır. İki amacı vardır: C programlamada daha fazla pratik yapmak ve algoritmalara matematiksel bir bakış açısı kazanmak. Derste konular üzerinden sürekli soru çözülür ve örnek yapılır. Dönem projesinde de derste görülen yöntemlerin kodları yazılır.

Hoca dersi şöyle tarif etti: lise seviyesindeki matematiği kullanarak üniversite seviyesindeki matematik problemlerine çözüm arayan bir ders. Gerekenler biraz lineer cebir, basit türev ve integral, bazen limit, trigonometri ve logaritmanın temel kurallarıdır. İş zorlaştığında da kendimizi yormadan döngüler, `if` yapıları ve iterasyonlarla, yani yaklaşım yöntemleriyle problemi yaklaşık olarak çözmeye çalışırız.

### 1.1 Kaynaklar

Slayttaki kaynaklar (ekrandan, 00:05:00):

- John H. Mathews, *Numerical Methods for Mathematics, Science and Engineering*, Prentice Hall.
- John R. Rice, *Numerical Methods, Software and Analysis*, McGraw Hill.

Kitapların elektronik hallerine kolayca ulaşılabilir. Hoca, her konu anlatımının sonundaki örnek soruların çalışılmasını önerdi. Farklı üniversitelerin "numerical analysis", "numerical methods" ya da Türkçe adlarıyla paylaştığı örnek sorular da kaynak olarak kullanılabilir. Bu dersin kaynağı boldur ve örnekleri anlaşılırdır.

### 1.2 Derslerin işlenişi

Slaytlar bütün bölümleri içerecek biçimde öğrencilerle paylaşılmıştır. Hoca, bu dersin yalnız slayttan öğrenilecek bir ders olmadığını söyledi. Slayt bazı kavramları hızlı aktarmak için kullanılır. Algoritmalar ise grafik tablette tahtaya yazar gibi adım adım izlenir (trace edilir): "$x = 0$ ile başlayalım, birinci adımda şu oldu, ikinci adımda bu oldu" gibi. Kodlama derste yapılmaz, kodlayacak olan öğrencilerdir. Anlaşılmayan yerde soru sorulması istendi.

Hoca, öğrencilerin sorumluluklarını (derse gelmek, işleri zamanında ve kendisi yapmak, intihal yapmamak) ve haklarını (anlamadığı bir şeyi sormak, bir sorunun çözümünü talep etmek) hatırlattı. Her öğrencinin durumunun farklı olduğunu, bu yüzden ikinci elden duyulan bilgiye güvenmeden soruların doğrudan hocaya sorulmasını tavsiye etti.

## 2. Dersin Konularına Genel Bakış

### 2.1 Hata kavramı

Sayısal yöntemler yaklaşık sonuç verir; gerçek çözüme ulaşamıyorsak yaklaşık çözüme ulaşırız. Bu yüzden mutlaka hatadan söz edilir. Hata ve hata türleri dersin ilk konularıdır.

### 2.2 Doğrusal olmayan denklemlerin çözümü

Doğrusal olmayan bir fonksiyonun "çözümü", grafiğinin sıfırı (x eksenini) kestiği noktaları, yani kökleri bulmaktır. Hoca slaytta bu bölüm için altı algoritma listelendiğini ve hepsinin tek tek anlatılacağını söyledi.

### 2.3 Sayısal integral

Belirli integral $\int_a^b f(x)\,dx$, $a$ ile $b$ arasındaki alandır. Basit fonksiyonların integralini almak kolaydır. Ama $f(x)$ integrali alınamayacak kadar karmaşıksa (hocanın örnekleri: $e^{x^2}$ ile sinüsün çarpımı ya da $x^3 \cdot 3^x$ gibi), alan belli aralıklarla yaklaşık hesaplanır. Hassasiyet artırıldıkça gerçek değere çok yakın sonuçlar elde edilir.

Hoca aynı mantığı köklerle de örnekledi: $\sqrt{2} \approx 1{,}4$ değeri belki ezberlenmiştir, ama $\sqrt{3}$ ya da $\sqrt{17}$'nin yaklaşık değeri bilinmez ($\sqrt{8} = 2\sqrt{2}$ olarak yazılabilir). Bu yaklaşık değerleri bulmanın da farklı algoritmaları vardır.

### 2.4 Sayısal türev

Integrali zor olan bir fonksiyonun türevi de zor olabilir. Örneğin bir $f$ fonksiyonunun türevinin $x = 0{,}8$ noktasındaki değeri isteniyor. Normalde türev alınıp $0{,}8$ yerine konur. Türev alınamıyorsa sayısal türev yöntemleri kullanılır.

### 2.5 Optimizasyon

Yerel (lokal) minimum ve maksimum, global minimum ve maksimum gibi fonksiyon değerlerinin bulunması.

### 2.6 Matrisler ve doğrusal denklem sistemleri

Slayttaki başlıklar (ekrandan, 00:15:00):

- Matrisler: matris tanımı, alt/üst üçgen matrisler, birim, köşegen ve bant matris; matris transpozesi, determinant, ters (inverse) alma.
- Doğrusal sistemlerin çözümü
  - Dolaysız (direct) yöntemler: Cramer, Gauss eliminasyon yöntemi, Gauss-Jordan eliminasyon yöntemi, yoğunlaştırılmış yok etme (compact elimination): Cholesky yöntemi.
  - Dolaylı (indirect) yöntemler: Jacobi iterasyonu, Gauss-Seidel.

Slayttaki el çizimi şekilde iki doğrunun kesişim noktası "çözüm" olarak işaretlenmiştir; verilen $a$'lar ve $c$'ler için

$$a_{11}x_1 + a_{12}x_2 = c_1, \qquad a_{21}x_1 + a_{22}x_2 = c_2$$

sisteminden $x_1$ ve $x_2$ çözülür. Hoca örnek olarak $2x + 3y = 18$, $3x + 2y = 36$ sistemini yazdı (ekrandan, 00:15:00). İki bilinmeyenli iki denklem kolayca çözülür; ama 20 bilinmeyen olduğunda analitik çözüm zorlaşır ve algoritmik çözümlere ihtiyaç duyulur. Dolaysız yöntemler (genelde lineer cebirde anlatılır) tam çözümü verir; Jacobi ve Gauss-Seidel ise yaklaşık çözüm verir.

**Soru (hocanın kendi sorduğu):** Yaklaşık çözüm iyi bir şey midir? **Cevap:** Gerçek çözüme ulaşmak imkânsızsa, tahmin yapıp tahmini güncelleyerek elde edilen yaklaşık çözümler çoğu durumda iş görür. Finansta geleceğe yönelik tahminler ve deprem bilimcilerin olasılıklı tahminleri sayısal yöntemleri kullanır.

> **Hocanın vurgusu:** Bu derste yöntemlere bilgisayar mühendisi gözüyle bakmak gerekir. Başka alanlardaki kişiler yöntemin hazır kodlanmış araçlarını kullanır; bizim derdimiz ise "bu yöntemi algoritmik olarak nasıl iyi kodlarım?" sorusudur.

### 2.7 Fonksiyonların bilgisayarda modellenmesi

Hoca $\sin(x^2) \cdot e^x$ gibi bir fonksiyonun C'de nasıl modelleneceğini sordu. Sinüs trigonometrik, $e^x$ üstel, $x^3$ polinom bir fonksiyondur ve her birinin kendi karakteristiği vardır. Matematik düşünceyi soyutlayıp programlama düşüncesine çevirmek gerekir. Örneğin bir polinom terimi bir katsayı ve bir dereceden oluşur; $n$ terim bir araya gelince polinomun kendisi oluşur. Bu yapı diziler, matrisler ya da `struct`'larla saklanabilir. Sinüs, üstel ve logaritma fonksiyonları da benzer biçimde modellenir. Sonra problemin türüne göre kök bulma, integral ya da türev algoritmasıyla hesap yapılır.

### 2.8 Doğrusal olmayan denklem takımları, sonlu farklar, enterpolasyon ve regresyon

Doğrusal olmayan denklem takımlarının çözümü için bazı yaklaşımlar ve sayısal türevde de kullanılan sonlu farklar ele alınacaktır. Sonlu farklar asıl olarak tahmin için kullanılan enterpolasyonda işe yarar.

Slayttaki başlıklar (ekrandan, 00:20:00):

- Enterpolasyon: Gregory-Newton enterpolasyon formülleri, Lagrange enterpolasyon formülleri.
- Regresyon (sayısal yaklaşım yöntemleri): en küçük kareler yaklaşımı; en küçük karelerde polinom yaklaşımı; en küçük karelerde lineer olmayan fonksiyonların kullanımı (üstel modeller); en küçük karelerde trigonometrik fonksiyonların kullanımı.

Slayttaki tanım: "Enterpolasyon: Hatasız veri noktalarının arasında kalan ara noktaları belirlemek için kullanılır. Tablo halinde verilen bilgiler için geçerlidir. Veri noktalarından doğrudan geçen bir eğri uydurmak ve bu eğriyi kullanarak ara değerleri tahmin etmektir." (ekrandan, 00:20:00)

Hoca bunu okuldaki örüntü sorularına benzetti: 2'ye 8, 4'e 9, 5'e 12 karşılık geliyorsa 18'e ya da arada kalan 4,5'e ne karşılık gelir? Enterpolasyon (ara değer uydurma) eldeki noktaların üzerinden geçen bir eğriyle aradaki değeri tahmin eder. Regresyon ise elimizdeki $x$ ve $y$'leri en iyi temsil eden bir doğru ya da eğri çizer. Bu eğri noktaların üzerinden geçmek zorunda değildir; gerçek noktalara uzaklığı, yani hatası en küçük olacak biçimde seçilir ve daha çok geleceğe yönelik tahminde kullanılır. Slayttaki çizimde solda noktaların arasından geçen bir regresyon doğrusu, sağda noktaların hepsinden geçen bir enterpolasyon eğrisi vardır.

#### Resim büyütme örneği

Hoca enterpolasyonun günlük hayattaki karşılığını bir resim düzenleme programında gösterdi. Ekran görüntüsünden alınmış yaklaşık 822'ye 500 piksellik bir resmi 2500 piksele büyüttü. Büyütülen resimde bozulma oluştu, çünkü program yeni piksellerin değerlerini ya iki komşu pikselin ortalamasını alarak ya da aralarında bir doğru/eğri üreterek, değişimin hızına göre uyduruyor. Küçük bir parçayı seçip daha da büyütünce detayların kaybolduğu ve görüntünün çirkinleştiği görüldü.

> **Hocanın vurgusu:** Enterpolasyon fonksiyonu ne kadar kaliteli olursa büyütülen resim de o kadar kaliteli olur.

### 2.9 Adi diferansiyel denklemler

Bu konu önceki yıllarda anlatılıyordu; öğrenciler diferansiyel denklemler dersini henüz almadığı için kapsamdan çıkarıldı, zaman kalırsa kısaca değinilecek.

Basit bir diferansiyel denklem örneği (ekrandan, 00:25:00):

$$y' + 2x = 0 \;\Rightarrow\; y' = -2x \;\Rightarrow\; y = -\frac{2x^2}{2} + C = -x^2 + C$$

Burada bir değişkenin türevi ve ona bağlı bir değişken vardır; iki tarafın integrali alınarak türevden kurtulunur.

> **Ders sonrası not:** Altyazıda sonuç "$x^2 + c$" diye geçiyor; tahtada doğru olarak işaret eksiyle, $y = -x^2 + C$ yazılmıştır.

Ama $y'' + (y')^2 + 2x^2 = 0$ gibi bir denklemde ne $y'$ ne de $y''$ bilinir. Bilinmeyen iki şey, denklem tek tanedir. Ortaokuldaki "bilinenler bir tarafa, bilinmeyenler bir tarafa" kuralı burada işlemez. Bu tür denklemlerin analitik çözüm teknikleri diferansiyel denklemler dersinde anlatılır; sayısal yöntemlerle ise yaklaşık çözüm üretilebilir.

Slayttaki el çizimi şekilde (ekrandan, 00:25:00) eğrinin bir noktasındaki eğim $f(t_i, y_i)$ olarak gösterilmiştir. Verilen

$$\frac{dy}{dt} \approx \frac{\Delta y}{\Delta t} = f(t, y)$$

denklemi $t$'nin fonksiyonu olarak $y$ için çözülür:

$$y_{i+1} = y_i + f(t_i, y_i)\,\Delta t$$

En çok kullanılan yöntem Runge-Kutta'dır. 1, 2, 3 ve 4. mertebe sürümleri vardır; genellikle 4. sürüm, algoritmik olarak biraz karmaşık olsa da en az hatayla çözüme ulaşır. Hoca bu konuyla ileride, örneğin robotik çalışmalarında karşılaşılabileceğini söyledi.

## 3. Analitik Çözüm ve Sayısal Çözüm

### 3.1 Bilgisayar neden önemli?

İnsan için $2^2$'yi hesaplamak çok kolaydır; $2^{200}$ ya da $2^{2000}$'i hesaplamak ise uzun sürer. Bilgisayar ikisini de yaklaşık aynı, makul sürede hesaplar. Bilgisayarın hızı ve kapasitesi birçok mühendislik problemini çözülebilir hale getirir.

Fiziksel bir sistem (bir köprünün davranış denklemi, bir makinenin giriş-çıkış ilişkisi) matematiksel bir eşitlikle ifade edilir. Bu eşitlik bir denklem, diferansiyel denklem, enterpolasyon/regresyon problemi ya da integral olabilir. Ara adımlardan birinde, örneğin bir türevin analitik çözümü mümkün değilse ($y = x^2$'nin türevi $2x$ diye elle bulunur ama her fonksiyon böyle değildir), sayısal yöntemler imkânsız olan çözümü yaklaşık olarak mümkün kılar.

Eskiden hazır programlar denklemi kullanıcıdan girdi olarak alamıyor, sembolik işlem yapamıyordu. Günümüzde bazı programlama dilleri denklemi sembolik olarak alabiliyor: $x^2$ verilince türevi $2x$ olarak, karmaşık bir ifade verilince de analitik çözümü hesaplanabiliyor. Sayısal yöntemler yüksek matematiksel işlemleri basit matematiksel işlemlere indirger; üniversite seviyesindeki problemler lise ve ortaokul matematiğiyle, cebirsel işlemlerle halledilir.

### 3.2 İki yolun karşılaştırılması

Slayttaki tablo (ekrandan, 00:40:00): "Mühendislik problemlerinin çözümünde iki yol kullanılır. Analitik (Teori) – Sonuçlar süreklidir. Sayısal (Deneysel) – Sonuçlar kesiklidir."

| Analitik | Sayısal |
|---|---|
| Matematiksel fonksiyonlar olarak çözüm üretirler, daha sonra bu çözümler bazı veriler için sayısal değere dönüştürülür | Analitik çözümü olmayan (karışık) problemlerin çözümünde kullanılır |
| Karışık olmayan problemlerin çözümünde kullanılır | Sonuçlar daima sayısaldır |
| Tek ve kesin bir sonuç elde edilir | Yaklaşık çözüme ulaşmak için iteratif bir çözüm kullanılır |
| | Yaklaşık bir çözüm üretirler, bu yaklaşık çözümlerin hassasiyeti adım sayısı artırılarak sağlanır |
| | Problemin çözümü yaklaşık olarak bulunduğunda hata analizi yapılır |

Süreklilik şu demektir: 0 ile 1 arasında sonsuz tane sayı vardır ve bunu ifade etmek için bir matematiksel fonksiyon kullanılır. $x^2$'nin türevi $2x$ sürekli bir sonuçtur. Sayısal çözüm ise kesikli, ayrıktır: "$x^2$'nin türevinin $0{,}8$ noktasındaki değeri" gibi tek bir sayı. Bir $P(x)$ polinomunun analitik integrali yine bir polinomdur; sayısal integralin sonucu ise bir sayıdır.

Karışık olmayan problemlerde analitik yöntem yeterlidir; basit bir fonksiyonun türevi için algoritma yazmaya gerek yoktur. Karışık problemlerde iteratif yaklaşık çözüm kullanılır. İteratiften kasıt genellikle bir `for` ya da `while` döngüsüdür:

- 100 iterasyon boyunca çözüme yaklaşmak istiyorsak tepede bir `for` döngüsü, içeride işlemin türüne göre basit matematiksel işlemler olur.
- Çözüme ne zaman ulaşılacağı belli değilse, hassasiyet denen bir kriterle `while` döngüsü kullanılır. Çözüm yaklaşık bulunduğunda hata analizi yapılır; kabul edilebilir bir hataya ulaşılmışsa durulur.

Analitik yöntemde tek ve kesin sonuç (gerçek, *true* değer) bulunur; sayısal yöntemde bulunan değer bir yaklaşımdır (*approximation*). Hoca bilimin tanımlarından birinin de "approximation to the truth", yani gerçeğe yaklaşma olduğunu hatırlattı: belli bir hatayla gerçeğe yaklaşılır, yeni bilgiler geldikçe sonuç güncellenir.

### 3.3 Analitik çözüm örneği: tepe noktası

$f(x) = x^2 - 3x + 2$ için türev "üssü indir, dereceyi bir azalt" kuralıyla alınır:

$$f'(x) = 2x - 3$$

Minimum/maksimum noktası için türev sıfıra eşitlenir: $2x - 3 = 0 \Rightarrow x = 1{,}5$. Bu noktadaki değer $f(1{,}5) = 2{,}25 - 4{,}5 + 2 = -0{,}25$ (ara adım eklendi). Fonksiyonun tepe noktası $(1{,}5;\,-0{,}25)$'tir. Bu, analitik olarak kolayca çözülen bir problemdir.

Ama elimizde fonksiyon değil de yalnız bir tablo olsaydı ($x = 1{,}0$ iken $y = \ldots$, $x = 1{,}2$ iken $y = \ldots$ gibi) ve "$x = 1{,}5$ iken $y$ nedir?" ya da "$y = 0{,}8$ hangi $x$ değerine karşılık gelir?" diye sorulsaydı, doğrudan yerine koyacağımız bir fonksiyon olmazdı. Önce ara işlemlerle $x$ ve $y$'ye bağlı bir fonksiyon üretilir, sonra $1{,}5$ yerine konur. Bu bir enterpolasyon, yani ara değer tahmini problemidir.
<!-- BELİRSİZ: Hocanın gösterdiği tablonun değerleri karelerde görünmüyor. -->

### 3.4 Sayısal analizin tanımı

Slayttaki tanım (ekrandan, 00:45:00):

> "Analitik çözümü mümkün olmayan denklemlerin sayısal denemeler ile yaklaşık çözümlerinin bulunması işlemlerine Sayısal Analiz denir."

Slayttaki iki örnek:

- $x^2 - 3x + 2 = 0 \Rightarrow (x-2)(x-1) = 0 \Rightarrow x = 2,\; x = 1$. Analitik çözümü mevcut. Diskriminantla ya da ikinci derece denklem çözüm yöntemleriyle bulunur.
- $x^2 - 5x\cos x + e^x = 0$. Denklem çözmede bildiğimiz iki kural (bilinenler bir tarafa, bilinmeyenler bir tarafa; gerekirse sadeleştirme) burada işe yaramaz. Bu eşitliği sıfır yapacak kökler analitik olarak bulunamaz. Ama fonksiyon çizdirildiğinde x eksenini kestiği noktalara yaklaşacak bir çözüm üretebilirsek yaklaşık kökleri buluruz.

### 3.5 Desmos ile kökleri görmek ve işaret değişimi

Hoca hem hesaplama hem çizim yapılabilen Desmos aracını tanıttı ve üstel terimli bir fonksiyon çizdirdi. Grafikte fonksiyonun x eksenini kestiği yerler, yani yaklaşık kökler görülüyordu. Hoca, köklerden biri için örneğin $-6$'dan başlayıp köke yaklaşılabileceğini, başka bir başlangıçtan $-2$'ye ya da $-4$'e doğru gidilebileceğini, toplam dört kök olduğunu söyledi. Bazen fonksiyonun reel kökü olmaz; bu durumda "reel kökü yoktur" denir.
<!-- BELİRSİZ: Desmos'ta çizilen fonksiyonun tam ifadesi karede görülmüyor; dört kök bilgisi slayttaki x^2 - 5x cos x + e^x ile uyumlu. -->

Bir şeyin reel kökü olması için grafiğin sıfır noktasına ulaşması gerekir:

- $x^2$'nin kökü 0'dır; grafik tam sıfır noktasına değer.
- $x^2 + 2$'nin grafiği $+2$ seviyesinden başlar, x eksenini hiç kesmez. Reel kökü yoktur, yalnız sanal (imajiner) kökü vardır.

Hoca sonra yaklaşım yöntemlerinin temel fikrini anlattı. Fonksiyon $x = 0$'da $1$ değerini alıyor. Bir noktada fonksiyon negatif, diğer noktada pozitifse arada sıfırdan geçiş olmuştur, yani arada bir kök vardır. Sonra aralığın ortasına bakılır: ortadaki değerin işaretine göre kökün hangi yarıda olduğu belirlenir ve bu yarıda devam edilir. Böylece her adımda köke biraz daha yaklaşılır. Bu, ikiye bölme (bisection) yöntemidir; programlamada aranan bir veriyi bulmak için kullanılan ikili arama (binary search) algoritmasına benzer.

> **Ders sonrası not:** Hoca $x = 1$'de değerin negatif, $x = 0{,}5$'te yaklaşık $-0{,}6$ olduğunu söyleyip sonraki adımda $0{,}75$'e bakılacağını söyledi. Fonksiyon büyük olasılıkla slayttaki $f(x) = x^2 - 5x\cos x + e^x$'tir. Python ile hesaplanan değerler: $f(0) = 1$, $f(0{,}5) \approx -0{,}295$, $f(1) \approx 1{,}017$ (pozitif). Yani $[0;\,0{,}5]$ ve $[0{,}5;\,1]$ aralıklarının ikisinde de işaret değişir ve iki kök vardır. Kökün $0$ ile $0{,}5$ arasında arandığı adımda bir sonraki orta nokta $0{,}75$ değil $0{,}25$'tir; $f(0{,}25) \approx 0{,}135 > 0$ olduğundan kök $[0{,}25;\,0{,}5]$ aralığındadır. Bu fonksiyonun python ile ikiye bölmeyle bulunan dört kökü yaklaşık $-3{,}836$, $-1{,}996$, $0{,}303$ ve $0{,}774$'tür.

Hoca, kök bulma yöntemlerinde karşımıza gelecek denklemlerin içinde $\ln$, $x^3$, $\tan$ gibi terimlerin birlikte bulunduğunu, hiçbir terimin diğer tarafa atılarak yalnız bırakılamadığını söyledi.

## 4. Sayıların Gösterimi

### 4.1 Tabanlar

Matematikte ve bilgisayar bilimlerinde en çok kullanılan tabanlar (ekrandan, 00:50:00): Base 10 (Decimal), Base 2 (Binary), Base 8 (Octal), Base 16 (Hexadecimal).

İkilik sistem işlemcinin ve bellek birimlerinin çalışma mantığıyla doğrudan ilgili olduğu için kullanılır; yalnız 0 ve 1'den oluşur. Sekizlik ve onaltılık sistemler, ikilik sistemde uzun yazılan ifadeleri kısaltmak için kullanılır.

### 4.2 İkilikten onluğa

Hoca $01000001$ sayısını yazdı; bu, büyük A harfinin ikilik karşılığıdır (ekrandan, 00:55:00). Basamak ağırlıkları sağdan sola $2^0, 2^1, \ldots, 2^7$'dir:

$$0\cdot 2^7 + 1\cdot 2^6 + 0 + \cdots + 0 + 1\cdot 2^0 = 64 + 1 = 65$$

Sıfır olan terimleri yazmaya gerek yoktur.

### 4.3 İkilikten onaltılığa ve tersi

Uzun açılımı yazmak yerine sayıyı önce onaltılığa ya da sekizliğe çevirip onluğa geçmek daha hızlıdır. Onaltılık sistemde 0-9'dan sonra yeni semboller gelir: A=10, B=11, C=12, D=13, E=14, F=15 (ekrandan, 00:55:00).

İkilikten onaltılığa geçerken bitler, en düşük anlamlı bitten (LSB, *least significant bit*) yani sağdan başlanarak dörderli gruplanır. Nedeni: $2^0, 2^1, 2^2, 2^3$'ten sonra $2^4 = 16$ gelir; dört bit tam bir onaltılık basamağa karşılık gelir. Sekizliğe geçerken üçerli gruplanır ($2^3 = 8$).

Tahtadaki örnek (ekrandan, 00:55:00):

$$1110\;0001$$

- Sağdaki grup $0001 = 1$.
- Soldaki grup $1110 = 8 + 4 + 2 = 14 = E$.
- Sonuç: $(E1)_{16}$.

Ters yön de aynı mantıkla yapılır; her onaltılık basamak ayrı ayrı dört bite açılır (ekrandan, 01:10:00):

$$(C8)_{16}: \quad 8 = 1000,\; C = 1100 \;\Rightarrow\; (1100\;1000)_2$$

Hoca sekizlik sistemi çok kullanmadığını, istenirse dörtlük tabanın da kullanılabileceğini söyledi.

### 4.4 Neden daha büyük taban kullanmıyoruz?

**Soru (hocanın sorusu):** Neden sürekli onaltılık kullanmıyoruz da bazen ikiliğe ihtiyaç duyuyoruz? 256'lık sistem kullansak sembolleri çok daha kısa yazmaz mıyız?

**Cevap (bir öğrenci):** 256 farklı sembol kullanmak gerekir.

Hoca cevabı onayladı: bu durumda yazı Çince gibi olur. İki sembol yerine belki bir sembolle yazılır, ama 256 sembolü ezberlemek gerekir. Çincede harf yerine kavram karakterleri vardır ve kırk bine yakın karakter dili zorlaştırır. Taban arttıkça yazım kısalır ama dil ve anlaşılırlık zorlaşır.

### 4.5 Onaltılık toplama ve çıkarma

Hoca iki işlem sordu (derste sözlü, 01:11:36 ve 01:11:46): $4AF + 322$ ve $522 - 4AF$. İlkokuldaki toplama ve çıkarma mantığı aynen kullanılır; yalnız onluk yerine on altılık düşünülür.

Toplama $4AF + 322$ (sağdan sola):

- $F + 2 = 15 + 2 = 17$. $17 - 16 = 1$ yazılır, elde 1.
- $A + 2 + 1 = 10 + 2 + 1 = 13 = D$ yazılır.
- $4 + 3 = 7$ yazılır.
- Sonuç: $7D1$.

Çıkarma $522 - 4AF$ (sağdan sola):

- $2$'den $F$ çıkmaz; komşudan bir onaltılık alınır. Komşu $2$, $1$ olur; bu basamak $16 + 2 = 18$ olur. $18 - 15 = 3$.
- $1$'den $A$ çıkmaz; yine komşudan bir onaltılık alınır. Komşu $5$, $4$ olur; bu basamak $16 + 1 = 17$ olur. $17 - 10 = 7$.
- $4 - 4 = 0$.
- Sonuç: $73$ (onaltılık).

İki sonuç da python ile doğrulandı: $0x4AF + 0x322 = 0x7D1$ ($1199 + 802 = 2001$) ve $0x522 - 0x4AF = 0x73$ ($1314 - 1199 = 115$).

## 5. Anlamlı Basamak, Kayan Nokta, Kesme ve Yuvarlama

### 5.1 Anlamlı basamak

Anlamlı rakam (*significant digit*), bir sayının kaç basamağını kullandığımızı söyler. Örneğin $2/3 = 0{,}6666\ldots$ beş anlamlı rakamla yazılırken yuvarlama yapılır: $0{,}66667$ (python ile kontrol edildi). Başta duran sıfırların anlamı yoktur; sıfırdan farklı ilk rakamdan itibaren sayılır.
<!-- BELİRSİZ: Hocanın anlamlı rakam için gösterdiği ikinci sayı karelerde yok; altyazıdan virgülden önce ve sonra rakam bulunan bir örnek olduğu anlaşılıyor. -->

Hoca diğer dönüşümleri (sekizlikten onluğa, onluktan ikiliğe; bölerek ya da çarparak; ikilikten onaltılığa geçip onluğa dönme) bilinen konular olduğu için ayrıntılı göstermedi.

### 5.2 Kayan nokta gösterimi

Slayttaki başlık (ekrandan, 01:15:00): "Floating Point (significant = mantissa) (exponent)". Kayan noktalı bir sayının işaret, işaretli üs ve mantis alanları vardır. Genel biçim:

$$m \cdot b^e$$

Burada $m$ mantis, $b$ kullanılan sayı sisteminin tabanı (ikilik, onaltılık vb.), $e$ üstür. Hoca bu derste bu notasyonun çok kullanılmayacağını, bilgi olsun diye konduğunu söyledi.

Sayılar bilimsel notasyona göre yazılır. Hoca Avogadro sayısını hatırlattı: $6{,}02 \times 10^{23}$, $602 \times 10^{21}$ diye de yazılabilir, ama bilimsel notasyonda virgülden önce bir basamak bulunur, geri kalanı üs olarak yazılır. Slayttaki ve derste geçen kayan nokta örnekleri ise virgülden önce sıfır olacak biçimde normalize edilmiştir:

- $156{,}78 \rightarrow 0{,}15678 \times 10^3$ (ekrandan, 01:15:00)
- $67{,}42 \rightarrow 0{,}6742 \times 10^2$
- $12{,}35 \rightarrow 0{,}1235 \times 10^2$

<!-- BELİRSİZ: Hocanın okuduğu diğer örnekler (0,080059 ve "519 ... 10 üzeri eksi 2" gibi) karelerde yok, altyazıdan tam çıkarılamıyor. -->

Bu biçime çevirmek, sayıdaki gereksiz (anlamsız) sıfırları atmayı da sağlar.

### 5.3 Kesme ve yuvarlama

İki işlem vardır:

- Kesme (*truncation*, *chopping*): sayı istenen basamaktan koparılır, sonraki basamağa bakılmaz.
- Yuvarlama (*rounding*): atılan ilk basamağa bakılır; 5 ve üstüyse son basamak bir artırılır.

Ondalık basamak (*decimal place*) virgülden sonraki basamak sayısını, anlamlı basamak ise toplam anlamlı rakam sayısını belirtir. Örneğin $\pi = 3{,}14159\ldots$ dört ondalık basamakla:

- Kesme: $3{,}1415$ (sonraki 9'a bakılmaz).
- Yuvarlama: $3{,}1416$ (9 dikkate alınır).

Bu sayılar beş anlamlı rakam içerir. Python ile kontrol edildi.

Hoca slayttaki bir örneği de anlattı: $34{,}782\ldots$ ile başlayan bir sayı üç anlamlı basamakla kesilince $34{,}7$, üç ondalık basamakla kesilince $34{,}782$ olur. Üç anlamlı basamakla yuvarlanınca $34{,}8$ olur, çünkü atılan ilk basamak (8) 5'ten büyüktür. Üç ondalık basamakla yuvarlanınca $34{,}782$ olarak kalır, çünkü sonraki basamak 5'ten küçüktür.
<!-- BELİRSİZ: Bu örnek sayının dördüncü ondalık basamağı karelerde görülmüyor; altyazıdan yalnız 5'ten küçük olduğu anlaşılıyor. -->

Hoca, kesme sonucu ile yuvarlama sonucu arasındaki farka "round-off error" dedi.

> **Ders sonrası not:** Hoca "round-off error"ı "kesme hatası gibi" diye karşıladı. Yaygın terminolojide round-off error yuvarlama hatasıdır; kesme hatası (truncation error) ise büyük olasılıkla bir sonraki derste anlatılacak ayrı bir hata türüdür.

### 5.4 Hız göstergesi örneği

Slayttaki başlık "Anlamlı Basamaklar" (ekrandan, 01:20:00): "Bir hesapta sayı ile çalışıyorsak, bunun güvenle kullanılabileceğine dair garantimiz olmalıdır. Arabanın hız göstergesini örnek olarak verelim." Göstergeye uzaktan bakınca ibre 40 ile 60 arasında, 50'ye yakın görünür; 48 de olabilir, 49 da. Yakından bakınca 49 okunur (slaytta "Cevap 49"). 49'dan sonrası, yani noktadan sonraki basamaklar bu göstergeden okunamaz ("Noktadan sonrası ???"). Anlamlı basamaklar hassasiyeti artıran ifadelerdir.

### 5.5 Yaklaşım yöntemlerinde basamak sayısı

Yaklaşım yöntemlerinde şöyle denecek: başlangıç noktası $x_0 = 1{,}225$ olsun ve hesaplarda virgülden sonraki 3 basamak dikkate alınsın. $x_1$, $x_0$'dan türetilirken sonuç örneğin $2{,}878654$ çıkarsa:

- Üç basamağa yuvarlama: $2{,}879$ (atılan ilk basamak 6, 5'ten büyük).
- Üç basamağa kesme: $2{,}878$.

Basamak sayısının baştan belirlenmesi sonuçlara güveni artırır.

## 6. Doğruluk ve Hassasiyet

Doğruluk (*accuracy*) ve hassasiyet (*precision*) birbirine yakın görünse de farklı kavramlardır.

- **Doğruluk:** Hesaplanan ya da ölçülen değerin gerçek değere ne kadar uyduğudur.
- **Hassasiyet:** Ölçümlerin birbirine ne kadar uyduğu, yani bir değerin etrafında kümelenip kümelenmediğidir.

Hoca hedef tahtası benzeri bir şekil üzerinden anlattı:

- A durumu: atışlar hem merkezden uzak hem dağınık; yanlışlık ve belirsizlik çok.
- B durumu: atışlar merkeze daha yakın ama belirsizlik hâlâ fazla.
- Bir başka durumda atışlar birbirine çok yakın ama yanlış bir noktanın etrafında kümelenmiş; hassasiyet var, yanlışlık fazla.
- İdeal durum: hem doğru hem hassas.

Hoca hassasiyeti, salgın döneminde konuşulan "testin hassasiyeti" örneğiyle de açıkladı: 1000 kişiye hasta etiketi verilip bunların 900'ü gerçekten hastaysa hassasiyet yaklaşık %90 ölçülür.
<!-- BELİRSİZ: Doğruluk-hassasiyet şeklinin karesi yok; A ve B durumlarının ayrıntısı altyazıdan kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** Tıbbi testlerde "hassasiyet" (sensitivity), gerçekte hasta olanların ne kadarının pozitif bulunduğunu ölçer. Hocanın tarif ettiği oran, yani pozitif etiketlenenlerin ne kadarının gerçekten hasta olduğu, sınıflandırmada "precision" (kesinlik) diye adlandırılır. Ölçüm bağlamındaki precision ise tekrarlanan ölçümlerin birbirine yakınlığıdır.

## 7. Hata ve Yanlış

### 7.1 Hata

Hata, gerçek (*actual*) değer ile hesaplanan (*predicted*) değer arasındaki farktır. Slayttaki tanım (ekrandan, 01:25:00):

$$\text{error} = |X_g - X_h|$$

Burada $X_g$ gerçek, $X_h$ hesaplanan değerdir. Hata genellikle pozitif bir değerle, mutlak değerle ifade edilir. Tahtadaki örnek:

- 2 beklenirken 8 geldi: $|2 - 8| = 6$.
- 8 beklenirken 2 geldi: $|8 - 2| = 6$.

Mutlak değerin nedeni: iki durumda işaretli farklar $2 - 8 = -6$ ve $8 - 5 = 3$ ise bunlar toplanınca $-3$ çıkar, oysa gerçek toplam sapma daha büyüktür. Mutlak değerlerle $|-6| + |3| = 9$ birimlik bir sapma olduğu doğru biçimde görülür (ekrandan, 01:25:00).

> **Ders sonrası not:** Altyazıda işaretli toplam "3" diye geçiyor; $-6 + 3 = -3$'tür (mutlak değeri 3).

### 7.2 Yanlış

Hata ile yanlış (*mistake*) farklıdır. Slayttaki yanlış örnekleri (ekrandan, 01:25:00):

- $62238$ yerine $62328$: dijitlerin yer değiştirmesi.
- $62238$ yerine $62338$: tekrar eden dijitlerin yanlış okunması.
- Tabloların satır ve sütunlarının yanlış okunması.
- Ondalık noktanın (decimal point) yanlış okunması.

Bunlar hata değil, yanlış ya da kusurdur.

### 7.3 Bilgisayar hata yapar mı?

**Soru (hocanın sorusu):** Bilgisayar hata yapar mı?

**Cevap (bir öğrenci):** Yapar; örneğin $\pi$'nin bütün basamaklarını alamayacağı için arada mutlaka bir fark olur.

Hoca önce "bilgisayarın hata yapması"nın ne demek olduğunu tanımladı. Kodda `a + b` ya da `a * 3` yazıldığında, verilen veriler aynıysa sonuç da her zaman aynıdır. Bilgisayar arıza yapabilir (bir sistem sorunu yüzünden çarpma yapılamayabilir), ama hata yapmaz. Günümüzdeki kişisel bilgisayarlar deterministik makinelerdir; rastgelelik yoksa bir kod sonsuz kez çalıştırılsa da hep aynı sonucu verir. Hatalı sonuç genellikle programcının dikkat etmediği bir şeyden kaynaklanır.

### 7.4 Kayan noktalı sayıların karşılaştırılması

Hoca şu durumu sordu: `a` bir `float` değişken. Bir döngüde `a` üzerinde işlemler yapılıyor ve döngü `a == 0.01` olana kadar çalışıyor. Ekrana `a` yazdırılınca 0.01 görünüyor. Bu `if` koşulu doğru olur mu?

Cevap: Doğru da olabilir, yanlış da. İki taraf da reel sayıdır ve kayan nokta notasyonuyla 0 ve 1'lerden oluşan bit dizileri olarak saklanır. `==` operatörü bu bitleri tek tek karşılaştırır. 32 bitlik bir `float`'ta 32 bitin hepsi aynıysa sonuç doğru olur, ama aynı olmama olasılığı çok yüksektir. Yapılan işlemlerden sonra ekranda 0.01 görünse bile sayının devamı vardır ve bit dizisi koddaki 0.01 sabitinden belki tek bir bit farklıdır. Bu tek bit yüzünden sonuç yanlış (false) çıkar. Bu bilgisayarın değil programcının hatasıdır; böyle bir karşılaştırma yapılmaz.

Doğrusu, farkın çok küçük bir sayıdan küçük olup olmadığına bakmaktır. Hocanın tahtada anlattığı fikir C ile şöyle yazılabilir (ders sonrası eklendi, derste kod yazılmadı; parça koddur, derlenmedi):

```c
if (fabs(a - 0.01) <= 0.001) {
    /* a, 0.01'e yeterince yakın kabul edilir */
}
```

Eşik değerin sıfırları artırılarak karşılaştırma daha sıkı yapılabilir. Fark sıfıra ne kadar yakınsa `a`'nın 0.01'e eşit olduğu o kadar güvenle kabul edilir.

> **Hocanın vurgusu:** Bu sorunla durdurma kriterlerinde çok karşılaşılacak. "Kodum `while` döngüsüne ya da `if`'in içine girmiyor" diye sorulduğunda bu konu hatırlanmalıdır.

> **Ek bilgi (derste anlatılmadı):** Mutlak değer için `fabs` fonksiyonu `math.h` başlığındadır. Benzer bir örnek olarak python'da `0.1 + 0.2 == 0.3` ifadesi `False` döndürür; çünkü 0.1 ve 0.2 ikilik tabanda tam olarak gösterilemez.

### 7.5 Hata kaynakları

Hata kayan noktalı işlemlerden (toplama, çarpma vb.) kaynaklanabilir. Ayrıca bir değerin virgülü ya da hassasiyeti bir basamak eksik ya da fazla yazılırsa bu fark sonraki adımlara yayılarak farklı sonuçlara yol açar.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): $2x + 3y = 18$ ve $3x + 2y = 36$ sisteminden $x$ ve $y$'yi bulun.

> **Çözüm (derste verilmedi):** Birinci denklem 2 ile, ikinci denklem 3 ile çarpılıp ikincisinden birincisi çıkarılırsa $9x - 4x = 108 - 36$, yani $5x = 72$, $x = 14{,}4$. Birinci denklemden $3y = 18 - 28{,}8 = -10{,}8$, $y = -3{,}6$. Python (`numpy.linalg.solve`) ile doğrulandı.

**Soru 2** (derste sözlü, 00:42:10; ekrandan, 00:45:00): $f(x) = x^2 - 3x + 2$ fonksiyonunun tepe noktasını ve köklerini bulun.

Çözüm (derste verildi): $f'(x) = 2x - 3 = 0 \Rightarrow x = 1{,}5$, $f(1{,}5) = -0{,}25$. Kökler: $(x-2)(x-1) = 0 \Rightarrow x = 2,\; x = 1$.

**Soru 3** (derste sözlü, 00:50:43; ekrandan, 00:55:00): $(01000001)_2$ onluk sistemde kaçtır?

Çözüm (derste verildi): $2^6 + 2^0 = 64 + 1 = 65$ (büyük A harfinin kodu).

**Soru 4** (derste sözlü, 00:51:38; ekrandan, 00:55:00): $(1110\,0001)_2$ sayısını onaltılık tabana çevirin.

Çözüm (derste verildi): LSB'den dörderli gruplama: $0001 = 1$, $1110 = 14 = E$; sonuç $(E1)_{16}$.

**Soru 5** (derste sözlü, 01:07:58; ekrandan, 01:10:00): $(C8)_{16}$ sayısını ikilik tabana çevirin.

Çözüm (derste verildi): $C = 1100$, $8 = 1000$; sonuç $(1100\,1000)_2$.

**Soru 6** (derste sözlü, 01:08:45): Onaltılık yerine 256'lık bir sistem kullansak sayıları çok daha kısa yazmaz mıyız? Neden kullanmıyoruz?

Çözüm (derste verildi): 256 farklı sembolün ezberlenmesi gerekir; yazım kısalır ama anlaşılırlık ve kullanım çok zorlaşır.

**Soru 7** (derste sözlü, 01:11:36): Onaltılık tabanda $4AF + 322$ kaçtır?

Çözüm (derste verildi): $F + 2 = 17 \rightarrow 1$, elde 1; $A + 2 + 1 = 13 \rightarrow D$; $4 + 3 = 7$. Sonuç $7D1$.

**Soru 8** (derste sözlü, 01:11:46): Onaltılık tabanda $522 - 4AF$ kaçtır?

Çözüm (derste verildi): $18 - 15 = 3$; $17 - 10 = 7$; $4 - 4 = 0$. Sonuç $73$.

**Soru 9** (derste sözlü, 01:23:57): Bilgisayar hata yapar mı?

Çözüm (derste verildi): Bilgisayar deterministiktir; arıza yapabilir ama aynı veriyle hep aynı sonucu ürettiği için hata yapmaz. Hatalı sonuçlar programcının dikkat etmediği durumlardan kaynaklanır.

**Soru 10** (derste sözlü, 01:26:19): `float a` üzerinde işlemler yapıldıktan sonra ekrana 0.01 yazdırılıyor. `if (a == 0.01)` koşulu doğru olur mu?

Çözüm (derste verildi): Doğru da olabilir yanlış da; bit dizileri tek bir bit bile farklıysa koşul yanlış çıkar. Bunun yerine `fabs(a - 0.01) <= 0.001` gibi küçük bir eşikle karşılaştırma yapılmalıdır.

## Dersin Toparlaması

Bu ilk derste sayısal analizin ne olduğu ve dönem boyunca hangi konuların işleneceği görüldü: hata, doğrusal olmayan denklemlerin kökleri, sayısal integral ve türev, optimizasyon, matrisler ve doğrusal sistemler, enterpolasyon ve regresyon, ve kısaca diferansiyel denklemler. Analitik çözüm sürekli ve kesin, sayısal çözüm kesikli, iteratif ve yaklaşıktır. Sayısal yöntemlerde çözümün hassasiyeti adım sayısıyla artar ve sonunda mutlaka hata analizi yapılır. İşaret değişimine dayanan kök arama fikri, sonraki derslerde anlatılacak ikiye bölme yönteminin temelidir.

Dersin ikinci yarısında temel kavramlar ele alındı: sayı tabanları ve dönüşümler, onaltılık aritmetik, anlamlı basamak, kayan nokta gösterimi, kesme ve yuvarlama, doğruluk ve hassasiyet, hata ile yanlışın farkı. Kayan noktalı sayıların `==` ile karşılaştırılmaması gerektiği, ileride yazılacak durdurma kriterleri için özellikle hatırlanmalıdır. Hoca bir sonraki derste hata türlerinin anlatılacağını, ardından doğrusal olmayan denklemlerin çözüm algoritmalarına geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
