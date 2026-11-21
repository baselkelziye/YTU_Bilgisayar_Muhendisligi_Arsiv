# Ders 8 Genişletilmiş Notu: Çok Katmanlı Ağlar ve Geri Yayılım Algoritması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Çok katmanlı ağlar ve geri yayılımın tanımı
- 2. Geri yayılımın üç aşaması
- 3. Çok katmanlı ağın mimarisi
- 4. Aktivasyon fonksiyonu seçimi ve sigmoid türevleri
- 5. Hebb kuralından delta kuralına ve hatanın türevi
- 6. Başlatma, durma koşulu ve ezberleme
- 7. Eğitim deseni sayısı: Baum ve Haussler ilişkisi
- 8. Çok boyutlu gradyan düşümü olarak eğitim
- 9. Adım adım sayısal geri yayılım örneği
- 10. Uygulamaya dönük iki kilit nokta
- Örnek Sorular
- Dersin Toparlaması

## 1. Çok Katmanlı Ağlar ve Geri Yayılımın Tanımı

Bu derste çok katmanlı algılayıcılar (multilayer perceptron) ve geri yayılım (backpropagation) algoritması işlenir. Hoca konunun önemini başta vurgular: dersin bundan sonraki bölümünde derin öğrenmeye geçilecektir ve derin ağlarda da her zaman geri yayılım kullanılacaktır. Bu yüzden bu bölüm, ileride en aktif kullanılacak bilgidir.

Çok katmanlı ağlar tek katmanlı ağlardan daha geniş problemlere çözüm üretebilir. Ancak doğru ağırlık kombinasyonunu bulmak için çok fazla parametre ayarlamak gerekir, bu da işlemleri karmaşıklaştırır. Bu nedenle öğrenme için daha özel bir yönteme ihtiyaç vardır. Önceki derslerde optimizasyon algoritmaları, gradyan düşümü ve Hessian'a bakarak minimum bulan Newton yöntemi görülmüştü. Geri yayılım da gradyan düşümüne dayanan bir yöntemdir: amaç hatayı en aza indirmektir.

Slayttaki tanım şöyledir (ekrandan, 00:10:00):

- 1969'da Bryson ve Ho, geri yayılımı çok katmanlı ağ için bir eğitim metodu olarak geliştirdi ("hatalardan öğrenme").
- Genelleştirilmiş delta kuralı da denir.
- Ağın çıktısının toplam hatasını en aza indirmek için kullanılan bir gradyan düşümü (gradient descent) metodudur.
- Amaç: doğru yanıt ile ağın yanıt verme yeteneği arasında bir denge kurmak için ağa eğitim vermektir. Eğitimde kullanılan kalıplara benzer ama onlarla özdeş olmayan girdiler için de makul (iyi) yanıt verme becerisi ağa kazandırılır.

> **Ders sonrası not:** Slaytta "Broyson & Ho" yazıyor; doğru yazım "Bryson & Ho"dur.

Hoca "denge" kelimesini şöyle açıklar: Ne kadar çok nöronlu bir ağ kurulursa kurulsun, ağ bütün örnekleri genellemeyi başaramayabilir. Her ağın belli bir yeteneği vardır ve problem için belli ölçüde uygundur. Hedef, kurulan ağın bu yeteneği içinde en iyi sonucu vermesini sağlayacak en uygun ağırlıkları bulmaktır. Ağın çıktısı ya da hatası bir fonksiyon gibi düşünülürse, aranan şey hata fonksiyonunun minimumudur; gradyan düşümü de bu iş için uygun bir yöntemdir.

## 2. Geri Yayılımın Üç Aşaması

Geri yayılım algoritması üç aşamada gerçekleşir:

1. **İleri besleme (feedforward):** Başlangıç ağırlıkları seçilir. Bir eğitim örneği alınır; girdiler ağırlıklarla çarpılıp toplanarak bir nöronun girdisi hesaplanır, nörondaki aktivasyon fonksiyonu uygulanır. Bu işlem bütün bağlantılar üzerinden çıktıya kadar sürer.
2. **Hatanın hesaplanması ve geriye yayılması:** Beklenen değer ile hesaplanan değer arasındaki fark, yani hata bulunur. Bu hata geriye doğru yayılır. Gradyan düşümünden yararlanıldığı için hatanın türevi alınır.
3. **Ağırlıkların ayarlanması:** Her bağlantı ağırlığının hatadaki etkisi ne kadarsa, ağırlık o oranda yeniden ayarlanır.

Bu yöntemin önemli farkı, ağırlıkları farklı oranlarda ayarlamaya olanak vermesidir. Artık bütün ağırlıklar sabit ve aynı biçimde değiştirilmez; her ağırlık hata fonksiyonuna olan katkısı oranında değişir.

Eğitim bitip ağırlıklar ayarlandıktan sonra yeni bir örnek test edilirken yalnız ileri besleme aşaması uygulanır. Ağırlıklarla artık oynanmaz. Bu, tek katmanlı perceptronda test sırasında yapılan işle aynıdır.

Hoca ana fikri şöyle özetler: gizli katmanlar arasında gözlenen hatalar çıktıya yansıtılarak hata fonksiyonu hesaplanır; geri yönde yayılım sırasında katmanların ağırlıkları doğru biçimde güncellenir. Hatanın en iyi ve en hızlı biçimde azalması için türevden, yani gradyandan yararlanılır.

## 3. Çok Katmanlı Ağın Mimarisi

Slayttaki mimari şekli şöyledir (ekrandan, 00:15:00):

- Girdi katmanı: $X_1, \dots, X_i, \dots, X_n$ ve değeri 1 olan bir bias birimi.
- Gizli katman: $Z_1, \dots, Z_j, \dots, Z_p$ ve değeri 1 olan bir bias birimi.
- Çıktı katmanı: $Y_1, \dots, Y_k, \dots, Y_m$.
- Girdiden gizli katmana ağırlıklar $v_{ij}$, bias ağırlıkları $v_{0j}$; gizli katmandan çıktıya ağırlıklar $w_{jk}$, bias ağırlıkları $w_{0k}$.

Girdi ve çıktı katmanı da sayılırsa bu, tek gizli katmanı olan üç katmanlı bir ağdır. Bütün nöronlar bir sonraki katmandaki bütün nöronlara ileri yönde bağlıdır. Hoca, biasların genellikle ortak kullanılabildiğini, tek bir bias değerinin yeterli olduğunu söyler.

İleri besleme aşamasında $X$'lerden gelen değerlere ve bağlantı ağırlıklarına göre bütün $Z$'lerin girdileri hesaplanır, aktivasyon fonksiyonu uygulanır, çıkan değerler yine ağırlıklarla çarpılarak $Y$'lere aktarılır ve çıkış hesaplanır. Çıkış, eğitim kümesinde beklenen değerlerle kıyaslanarak karesel hata fonksiyonu oluşturulur. Bu fonksiyonun türevi geriye doğru yayılarak her ağırlık tek tek ayarlanır. Örnekler, çıktıdaki hata belli bir seviyeye düşene kadar tekrar tekrar gösterilir; epok sayısı da bir durma kriteri olabilir.

### 3.1 Gizli katman ve nöron sayısı

Hocaya göre birden fazla gizli katman kullanılabilir, ama çoğunlukla bir ya da iki gizli katmanın üzerine çıkılmaz. Çok fazla gizli katman ağın başarısını pek artırmaz, aksine hesaplamaları karmaşıklaştırır. Ağ başarısız olduğunda "nöronları çok artırayım, bir gizli katman daha ekleyeyim" yolu sonucu çok fazla değiştirmez.

Gizli katmandaki nöron sayısı için hoca gözleme dayalı bir çıkarım verir: $n$ girdi varsa gizli katmana yaklaşık $\log n$ kadar nöron koymak yeterli olacaktır. Çıktı katmanında ise problemdeki $m$ çıkışı temsil eden $m$ nöron bulunur.

> **Ek bilgi (derste anlatılmadı):** Gizli nöron sayısı için literatürde tek bir kesin kural yoktur; farklı kaynaklarda farklı pratik kurallar önerilir ve sayı genellikle deneme ve doğrulama verisiyle belirlenir. Hocanın "girdi sayısının logaritması" önerisi de kendi ifadesiyle gözleme dayalı bir başlangıç noktasıdır.

## 4. Aktivasyon Fonksiyonu Seçimi ve Sigmoid Türevleri

Aktivasyon fonksiyonu seçilirken dikkat edilmesi gereken, olmazsa olmaz özellikler şunlardır:

- Fonksiyon sürekli olmalıdır.
- Türevlenebilir olmalıdır.
- Monoton azalmayan olmalıdır.

Hoca bu koşulların, türev alındığında ortaya çıkabilecek gradyanın kaybolması gibi sorunların önüne geçmek için istendiğini söyler. Ağ başarısızsa aktivasyon fonksiyonunun yanlış seçilmiş olabileceği, sık karşılaşılan bir durumdur. Bunlara ek olarak, fonksiyon bu üç koşulu sağlasa bile çıkışta beklenen değerleri üretemiyorsa yine sorun vardır. Bu yüzden beklenen çıktı değerlerinin aralığıyla seçilen fonksiyonun çıktı aralığının uyumuna da bakılmalıdır.

Yaygın kullanılan aktivasyon fonksiyonları sigmoid fonksiyonlarıdır. Binary sigmoid 0 ile 1 arasında, bipolar sigmoid $-1$ ile $1$ arasında değer üretir. Hoca, üsteldeki $x$'in önüne bir katsayı konarak fonksiyonun bu aralığının değiştirilebileceğini de belirtir.

> **Ek bilgi (derste anlatılmadı):** Bu iki fonksiyonun yaygın biçimi şudur: binary sigmoid $f(x) = \dfrac{1}{1 + e^{-x}}$, bipolar sigmoid $f(x) = \dfrac{2}{1 + e^{-x}} - 1$. Eğimi belirleyen bir $\sigma$ katsayısıyla $e^{-\sigma x}$ biçiminde de yazılırlar. Formüller slaytta gösterildi ama derste okunmadı ve elimizdeki karelerde görünmüyor.

Fonksiyonların türevi geri yayılımda gereklidir, çünkü hata bu fonksiyonlara bağlı olarak oluşur ve hatanın türevi alınırken bu türevler kullanılır. Hoca türevleri şöyle hatırlatır:

- Binary sigmoid: $f'(x) = f(x)\,\big(1 - f(x)\big)$.
- Bipolar sigmoid: $f'(x) = \dfrac{1}{2}\,\big(1 + f(x)\big)\big(1 - f(x)\big)$.

Bu türevler, fonksiyonun kendisi cinsinden yazıldığı için hesaplamada çok pratiktir: ileri beslemede bulunan çıktı değeri doğrudan türevde kullanılabilir.

## 5. Hebb Kuralından Delta Kuralına ve Hatanın Türevi

### 5.1 Öğrenme kurallarının gelişimi

Hoca önceki kuralları sırayla hatırlatır:

- **Hebb öğrenmesi:** Yalnız girdi ile çıktı çarpılarak ağırlığın yeni değeri ya da ağırlıktaki değişim hesaplanıyordu.
- **Perceptron öğrenmesi:** Hedef değer ile girdi çarpılıyordu. Ayrıca öğrenme katsayısı eklenerek ağırlık değişiminin daha yavaş, kontrollü ve anlamlı olması sağlanıyordu.
- **Adaline ve delta kuralı:** Hedef değer ile hesaplanan değerin farkı dikkate alınmaya başlandı. Çıkışta beklenen ve hesaplanan değer farkı girdiyle çarpılıp öğrenme katsayısıyla ölçeklenerek ağırlık değişimi belirleniyordu.

### 5.2 Delta kuralının türetilmesi

Slayttaki türetme şöyledir (ekrandan, 00:25:00). Delta kuralı:

$$w_{ij}(new) = w_{ij}(old) + \eta\,(targ_j - out_j)\,x_i$$

Nöronun girdisi ve karesel hata:

$$y_{in} = \sum_{i=1}^{n} x_i w_i, \qquad E = \sum_{j=1}^{m} \big(t_j - y\_in_j\big)^2$$

Hatanın $w_1$'e göre türevi:

$$\frac{\partial E}{\partial w_1} = -2\,(target - y\_in)\,\frac{\partial y\_in}{\partial w_1} = -2\,(t - y_{in})\,x_1$$

Hocanın açıklaması şöyledir: Dış türevden 2 ve $(t - y_{in})$ gelir. Sonra içinin türevi alınır. $y_{in}$ ifadesinde birçok $x_i w_i$ terimi vardır, ama $w_1$'e göre türev alınınca $w_1$ içermeyen terimler gider, yalnız $x_1 w_1$ kalır. Onun türevi $x_1$'dir. Parantez içinde $y_{in}$'in önünde eksi işareti bulunduğu için bu eksi de dışarı çıkar ve sonuç $-2(t - y_{in})x_1$ olur.

Sabit $-2$ çarpanı öğrenme katsayısının içine katılabilir; sonuçta sabit bir çarpandır. Ağırlık gradyanın tersi yönünde değiştirileceği için güncelleme şu olur:

$$\Delta w_1 = \mu\,(t - y_{in})\,x_1$$

> **Ders sonrası not:** Slaytta türev payda kısmında "$\partial x w_1$" yazıyor; kastedilen $\partial w_1$'dir. Ayrıca slaytta öğrenme katsayısı bir yerde $\eta$, bir yerde $\mu$ ile gösterilmiştir; ikisi aynı şeydir.

Aktivasyon fonksiyonu işin içine girdiğinde, nörona giren toplam önce aktivasyon fonksiyonundan geçer ve türev alınırken fonksiyonun türevi de zincirde bir çarpan olarak yer alır. Hoca, delta kuralındaki girdinin türevini alma adımının aslında aktivasyon fonksiyonunun türevini alma hikâyesine benzediğini söyler. Binary sigmoid için bu türev $f(x)(1 - f(x))$'tir.

### 5.3 Türevin anlamı

Hoca $\partial E / \partial w_1$ ifadesini sözel olarak yorumlar: Türev değişimdir. Bu ifade, hatanın $w_1$'e göre değişimidir. Aynı zamanda $w_1$'in hataya olan etkisi, yani hatanın değişiminde $w_1$'in payıdır. $w_1$ bu miktar kadar güncellenirse daha doğru bir ayarlama yapılmış olur. Gradyan kadar değişim yapılınca parametreler hatayı daha hızlı ve daha istikrarlı biçimde en aza indirecek şekilde ayarlanır. $w_2$ için de hatanın $w_2$'ye göre türevine bakılır ve böyle devam edilir.

**Soru:** $-2$'deki eksi nereden geldi? **Cevap:** İçinin türevi alınırken $(t - y_{in})$ içindeki $y_{in}$'in, dolayısıyla $x_1 w_1$ teriminin önünde eksi vardır. Türev alınınca bu eksi dışarı çıkar; 2 ise karenin türevinden gelir. Elle türev alınırsa görülür.

## 6. Başlatma, Durma Koşulu ve Ezberleme

Slayttaki algoritma ayrıntıları şöyledir (ekrandan, 00:30:00):

- Yaygın prosedür, ağırlık ve biasları $-0.5$ ile $0.5$ arasında (veya $-1$ ile $1$ arasında) rastgele değerlere başlatmaktır.
- Eğitim durma zamanı: Yaygın prosedür, ağın eğitim desenleri için doğru ve test desenleri için iyi cevaplar vermesi arasındaki dengeyi bulmaktır. Ağ çok eğitilirse ezberlemeye ve genelleme yeteneğini kaybetmeye başlar; az eğitilirse eğitim desenine bile doğru cevabı veremeyebilir.

Başlangıç ağırlıkları belirlendikten sonra "ileri besle, hatayı hesapla, hatayı geri yay" biçiminde üç adımlı eğitim yapılır. Eğitimin nereye kadar süreceği için belli bir epok sayısı ya da hata oranı belirlenir.

Hoca ezberleme konusunu ayrıntılı açıklar. Hata istenen kadar düşmüyor diye algoritmayı yüz binlerce epok zorlamak, ağı ezberleme eğilimine sokar. Hata belki biraz daha düşer, ama ağ yalnız gösterilen örnekleri bilir hale gelir ve yeni bir örnekte başarılı olamayabilir. Buna ezberleme denir. Genelleme yeteneğinin kaybolmaması için eğitim süresi gereğinden fazla uzatılmamalıdır.

Öte yandan geri yayılım ağlarının eğitim süreleri kısa değildir. Normalde 5-10 epokla değil, binlerce epokla eğitilir; ama hatanın gidişatı izlenmelidir. Gradyan düşümünde de görüldüğü gibi bir noktada hatanın düşüşü yavaşlar. Düşüş çok yavaşladığında, hatada önemli bir değişim olmuyorsa, eğitime boşuna devam etmek ağı ezberletir.

> **Hocanın vurgusu:** Hatanın değişimi kritiktir; hata grafiği (hedef ile hesaplanan değer arasındaki fark) her zaman çizdirilip izlenmelidir. Hata birkaç epok düştükten sonra uzun süre düzlükte kalıyor ve kayda değer bir değişim olmuyorsa, ağ ezberlemeye doğru gidiyor demektir.

**Soru:** Basit bir karakter tanıma probleminde tek katmanlı perceptronla 12 epokta %100 başarı elde ediliyor. Bu ezberleme midir? **Cevap:** Hayır. 12 epok çok fazla bir eğitim miktarı değildir; hata grafiği çizilirse bu süre boyunca sürekli düşen bir eğri görülür. Problemdeki harfler birbirinden görece kolay ayrılabilen örneklerdir ve problem gerçekten %100 çözülebilir olduğu için bu başarıya zorlamadan ulaşılmıştır. Örnekler kötü ya da yetersiz olsaydı %100'e ulaşılamazdı. 12 epokla yetinmeyip 5 bin, 10 bin, 100 bin epok zorlansaydı o zaman ezberleme söz konusu olurdu.

## 7. Eğitim Deseni Sayısı: Baum ve Haussler İlişkisi

Slayta göre (ekrandan, 00:30:00): $P$ desen sayısı, $W$ ağırlık sayısı, $e$ istenen doğruluk olmak üzere

$$P = \frac{W}{e}$$

ilişkisi 1989'da Baum ve Haussler tarafından ispatlanmıştır.

Hoca bu ilişkiyi şöyle yorumlar: Ulaşılabilecek doğruluk, elde bulunan desen sayısı ile bağlantı sayısının oranıyla ilişkilidir. $e$ yalnız bırakılırsa $e = W/P$ olur; bağlantı ağırlığı sayısı arttıkça hatanın düşük olması için daha çok örnek gerekir. Örnek sayısı arttıkça hata sıfıra yaklaşır. Derin ağlarda çok daha fazla bağlantı bulunduğu için hep daha fazla örneğe ihtiyaç duyulur.

> **Hocanın vurgusu:** Bu formül sayısal olarak birebir tutacak bir sonuç vermez. Bağlantı ağırlığı sayısı arttıkça daha çok örneğe ihtiyaç olduğunu gösteren, yaklaşık bir ilişkidir; "bana kabaca ne kadar örnek lazım" sorusuna fikir verir.

Hoca bunu sınıfın karakter tanıma problemine uygular: 63 girdi (piksel) ve 7 çıktı olduğundan yaklaşık $63 \times 7$ bağlantı vardır, farklı harf sayısı (örnek sayısı) ise 21'dir. Bu değerlerle $e = W/P$ oranından ulaşılabilecek doğruluk kabaca görülebilir. Hoca, buna rağmen o problemde örneklerin birbirine karışmayacak kadar iyi olduğunu ekler.

> **Ders sonrası not:** Bu değerlerle $W = 63 \times 7 = 441$ ve $W/P = 441/21 = 21$ çıkar. $e$ bir hata oranı olarak düşünülürse bu değer 1'den çok büyüktür; yani Baum-Haussler ilişkisi bu küçük örnek kümesi için büyük olasılıkla anlamlı bir doğruluk garantisi vermez. Problemin yine de çözülebilmesi, hocanın dediği gibi harflerin kolay ayrılabilir olmasıyla açıklanır.

## 8. Çok Boyutlu Gradyan Düşümü Olarak Eğitim

Önceki derste gradyan düşümü ikinci dereceden bir fonksiyon üzerinde gösterilmişti. Gradyan düşümü çok boyutlu problemlerde de kullanılabilir ve yapay sinir ağında durum tam olarak budur: problem çok boyutlu ve doğrusal değildir. Belirlenmesi gereken her ağırlık, hata fonksiyonunun bir boyutunu oluşturur. 10 ağırlık varsa fonksiyon 10 boyutlu uzayda, $n$ ağırlık varsa $n$ boyutlu uzayda en aza indirilmeye çalışılır. Aranan, bütün ağırlıklar (bütün boyutlar) için fonksiyonun minimum olduğu noktadır. Hoca, bu kadar yüksek boyutların doğrudan çizilemeyeceğini, gradyan düşümü konusunda bunların derinlik haritası (kontur) ile gösterildiğini hatırlatır.

### 8.1 Algoritmanın akış şeması

Slayttaki akış şeması şöyledir (ekrandan, 00:20:00). Ağırlıklar küçük değerlerle başlatılır; durma koşulu sağlanmadığı sürece bütün eğitim ikilileri için şu adımlar tekrarlanır:

```text
start
  -> Ağırlıkları küçük değerlerle başlat
  -> durma koşulu = false ?  (hayır -> end)
  -> bütün eğitim ikilileri için:
       FeedForward:
         her x_i girdi birimi girdi sinyalini alır, gizli birimlere iletir
         her z_j gizli birimi gelen sinyalleri toplar, aktivasyonu uygular,
           sonucu çıktı birimlerine gönderir
         her y_k çıktı birimi gelen sinyalleri toplar, aktivasyonu uygular
       BackProp:
         her y_k çıktı birimi hedef değeri alır, hatayı, ağırlık ve bias
           düzeltmesini hesaplar, sonucu alt birime gönderir
         her z_j gizli birimi gelen hataları toplar, aktivasyonun türeviyle
           çarpar, ağırlık ve bias düzeltmesini hesaplar
       Update:
         her çıktı ve gizli birim ağırlık ve biaslarını günceller
```

Formüller (ekrandan, 00:20:00):

- İleri besleme: $z\_in_j = v_{0j} + \sum_{i=1}^{n} x_i v_{ij}$, $z_j = f(z\_in_j)$; $y\_in_k = w_{0k} + \sum_{j=1}^{p} z_j w_{jk}$, $y_k = f(y\_in_k)$.
- Çıktı birimi hatası: $\delta_k = (t_k - y_k)\, f'(y\_in_k)$; ağırlık düzeltmesi $\Delta w_{jk} = \alpha\,\delta_k\,z_j$; bias düzeltmesi $\Delta w_{0k} = \alpha\,\delta_k$.
- Gizli birim: hataların toplamı $\delta\_in_j = \sum_{k=1}^{m} \delta_k w_{jk}$; aktivasyonun türevi çarpı toplam hata $\delta_j = \delta\_in_j\, f'(z\_in_j)$; ağırlık düzeltmesi $\Delta v_{ij} = \alpha\,\delta_j\,x_i$; bias düzeltmesi $\Delta v_{0j} = \alpha\,\delta_j$.
- Güncelleme: $w_{jk}(new) = w_{jk}(old) + \Delta w_{jk}$, $v_{ij}(new) = v_{ij}(old) + \Delta v_{ij}$.

Hoca slayttaki gösterimi yeterince okunur bulmadığı ve notasyon farklılıklarından memnun olmadığı için bu kısmı ayrıntılı anlatmadan geçer ve aynı fikri adım adım bir sayısal örnek üzerinden göstermeyi tercih eder.

## 9. Adım Adım Sayısal Geri Yayılım Örneği

### 9.1 Ağın yapısı ve başlangıç değerleri

Örnek, "A Step by Step Backpropagation" başlıklı bir doküman üzerinden anlatılır (ekrandan, 00:40:00). Ağda 2 girdi nöronu ($i_1$, $i_2$), tek gizli katmanda 2 nöron ($h_1$, $h_2$) ve 2 çıktı nöronu ($o_1$, $o_2$) vardır. Aralarındaki bağlantılar 8 ağırlık oluşturur; biaslarla birlikte hesaplanacak ağırlık sayısı 10'dur. Bağlantılar şöyledir: $w_1$: $i_1 \to h_1$, $w_2$: $i_2 \to h_1$, $w_3$: $i_1 \to h_2$, $w_4$: $i_2 \to h_2$, $w_5$: $h_1 \to o_1$, $w_6$: $h_2 \to o_1$, $w_7$: $h_1 \to o_2$, $w_8$: $h_2 \to o_2$.

Değerler (ekrandan, 00:45:00):

| Büyüklük | Değer |
|---|---|
| Girdiler $i_1$, $i_2$ | $0.05$, $0.10$ |
| Hedefler $o_1$, $o_2$ | $0.01$, $0.99$ |
| $w_1$, $w_2$, $w_3$, $w_4$ | $0.15$, $0.20$, $0.25$, $0.30$ |
| $w_5$, $w_6$, $w_7$, $w_8$ | $0.40$, $0.45$, $0.50$, $0.55$ |
| Biaslar $b_1$, $b_2$ | $0.35$, $0.60$ |

Hoca şunu vurgular: ağırlıklar ve bias ağırlıkları rastgele atanmıştır, ama $0.05$, $0.10$ girdisi ve $0.01$, $0.99$ hedefi rastgele değildir; elde ölçülmüş bir eğitim örneğidir. Amaç ağırlıkları, hem bu örnek hem de diğer örnekler için çıkışta olması gereken değere en yakın sonucu verecek biçimde ayarlamaktır.

### 9.2 İleri besleme

$h_1$ nöronunun girdisi $i_1 w_1 + i_2 w_2 + b_1$, $h_2$'nin girdisi $i_1 w_3 + i_2 w_4 + b_1$'dir. Aktivasyon fonksiyonu olarak sigmoid'in özel bir hali olan lojistik fonksiyon kullanılır:

$$f(x) = \frac{1}{1 + e^{-x}}$$

Hoca şunu hatırlatır: gizli katman için fonksiyonun girdisi $i_1$, $i_2$'den gelen toplamdır; çıktı katmanı için ise girdi $h_1$ ve $h_2$'nin çıktılarından gelen toplamdır. Yani aktivasyon fonksiyonuna giren değer, o düğüme giren toplamdır ($net_{h1}$ gibi).

Adımlar (ara değerler python ile hesaplanıp doğrulandı):

- $net_{h1} = 0.15 \cdot 0.05 + 0.20 \cdot 0.10 + 0.35 = 0.3775$
- $out_{h1} = f(0.3775) = 0.593269992$
- $net_{h2} = 0.25 \cdot 0.05 + 0.30 \cdot 0.10 + 0.35 = 0.3925$
- $out_{h2} = f(0.3925) = 0.596884378$
- $net_{o1} = 0.40 \cdot 0.593269992 + 0.45 \cdot 0.596884378 + 0.60 = 1.105905967$ (hoca "1,105" dedi)
- $out_{o1} = f(1.105905967) = 0.751365070$
- $net_{o2} = 0.50 \cdot 0.593269992 + 0.55 \cdot 0.596884378 + 0.60 = 1.224921404$
- $out_{o2} = f(1.224921404) = 0.772928465$

Çıktılar yaklaşık $0.75$ ve $0.77$'dir. Beklenen değerler $0.01$ ve $0.99$'dur. $0.77$, $0.99$'a görece yakındır; ama $0.01$ beklenirken $0.75$ bulunması ciddi bir hatadır.

### 9.3 Hatanın hesaplanması

Her çıkış nöronu için karesel hata ayrı ayrı hesaplanır, sonra toplanarak toplam hata bulunur:

- $E_{o1} = \tfrac12 (0.01 - 0.751365070)^2 = 0.274811083$
- $E_{o2} = \tfrac12 (0.99 - 0.772928465)^2 = 0.023560026$
- $E_{total} = E_{o1} + E_{o2} = 0.298371109$

Beklendiği gibi $o_2$'nin hatası, çıktısı hedefe daha yakın olduğu için daha düşüktür.

> **Ders sonrası not:** Hoca hatayı "hedef ile hesaplanan değerin farkının karesi" diye anlattı ve sonuçları $0.27$, $0.023$, toplamı $0.29$ olarak söyledi. Farkın karesi doğrudan alınırsa $E_{o1} = 0.5496$ olur; söylenen $0.27$ değeri ancak $E = \tfrac12 (target - out)^2$ tanımıyla çıkar. Yani örnekte $\tfrac12$ katsayılı karesel hata kullanılmıştır. Toplam hatanın doğru değeri $0.298$'dir ($0.29$ değil, yuvarlanırsa $0.30$).

### 9.4 Çıktı katmanı ağırlığının güncellenmesi: $w_5$

$w_5$, $h_1$ ile $o_1$ arasındaki bağlantıdır ve değeri $0.40$'tır. Çıkışlarda hata oluştuğu için eğitimde $w_5$ güncellenmelidir. Bunun için $w_5$'in toplam hatadaki payı, yani $\partial E_{total} / \partial w_5$ hesaplanır.

Hoca burada bir sorunu gösterir: $E_{total}$ ifadesine bakıldığında içinde doğrudan $w_5$ diye bir değişken yoktur. Ama $w_5$'e dolaylı olarak bağlı ifadeler vardır. Bu yüzden türev zincir kuralıyla alınır: $E_{total}$, $out_{o1}$'e bağlıdır; $out_{o1}$, $net_{o1}$'e bağlıdır; $net_{o1}$ ise $w_5$'e bağlıdır.

$$\frac{\partial E_{total}}{\partial w_5} = \frac{\partial E_{total}}{\partial out_{o1}} \cdot \frac{\partial out_{o1}}{\partial net_{o1}} \cdot \frac{\partial net_{o1}}{\partial w_5}$$

Üç türev ayrı ayrı alınır (ara adımların açılımı eklendi):

- $\dfrac{\partial E_{total}}{\partial out_{o1}} = -(target_{o1} - out_{o1}) = -(0.01 - 0.751365070) = 0.741365070$
- $\dfrac{\partial out_{o1}}{\partial net_{o1}} = out_{o1}(1 - out_{o1}) = 0.751365070 \cdot 0.248634930 = 0.186815602$
- $\dfrac{\partial net_{o1}}{\partial w_5} = out_{h1} = 0.593269992$

Çarpım (ekrandan, 01:00:00):

$$\frac{\partial E_{total}}{\partial w_5} = 0.74136507 \cdot 0.186815602 \cdot 0.593269992 = 0.082167041$$

Hoca, ikinci türevin aktivasyon fonksiyonunun (lojistik fonksiyon) türevinden geldiğine dikkat çeker. Dokümanda bu hesap delta kuralı biçiminde birleştirilir (ekrandan, 01:00:00):

$$\frac{\partial E_{total}}{\partial w_5} = -(target_{o1} - out_{o1}) \cdot out_{o1}(1 - out_{o1}) \cdot out_{h1}$$

İlk iki çarpan birlikte düğüm deltası (node delta) olarak adlandırılır:

$$\delta_{o1} = \frac{\partial E_{total}}{\partial net_{o1}} = -(target_{o1} - out_{o1}) \cdot out_{o1}(1 - out_{o1}), \qquad \frac{\partial E_{total}}{\partial w_5} = \delta_{o1}\, out_{h1}$$

Güncelleme, öğrenme oranı $\eta = 0.5$ ile yapılır (ekrandan, 00:55:00):

$$w_5^{+} = w_5 - \eta \cdot \frac{\partial E_{total}}{\partial w_5} = 0.4 - 0.5 \cdot 0.082167041 = 0.35891648$$

Dokümanda, bazı kaynakların öğrenme oranı için $\alpha$, bazılarının $\eta$, bazılarının $\epsilon$ kullandığı da belirtilir. Aynı işlem tekrarlanarak $w_6^{+} = 0.408666186$ bulunur (ekrandan, 00:55:00).

> **Ders sonrası not:** Hoca yeni $w_5$ değerini "0,35" diye söyledi; doğru değer $0.35891648$, yani yaklaşık $0.359$'dur.

> **Hocanın vurgusu:** Güncellemedeki eksi işaretini bir çıkarma işlemi olarak değil, yön olarak düşünün: gradyanın tersi yönü. "Yeni $w_5$'i ayarlarken eski $w_5$'i, $w_5$'in hataya etkisi kadar ve gradyanın tersi yönünde değiştir" diye düşünülürse formülü ezberlemeye gerek kalmaz. Öğrenme katsayısı da bu değişimin hızını ayarlayan parametredir.

### 9.5 Gizli katman ve döngünün sürmesi

Gizli katmandan girdiye doğru olan $w_1$, $w_2$, $w_3$, $w_4$ ağırlıkları da aynı biçimde, zincir kuralıyla ne kadar değiştirileceği belirlenerek güncellenir. Bu ağırlıkların sayısal hesabı sonraki derse bırakılmıştır. Bir tur geri yayılım bittiğinde bütün ağırlıkların yeni değerleri hatayla ilişkili olarak, gradyanın tersi yönünde hesaplanmış olur. Ardından yeni bir örnek gösterilir, yeniden ileri hesaplama yapılır, hata belirlenir, karesel hatanın türevi alınıp geriye yansıtılır. Bu döngü hata belli bir orana düşene kadar ya da belli bir epok sayısı kadar sürer. Ağın eğitildiğine, ağırlıkların artık pek değişmediğine ya da hatanın belli bir değere düştüğüne ikna olunduğunda ağırlıklar son değerleriyle sabitlenir ve ağ yeni test örnekleri için kullanıma hazır olur.

> **Ek bilgi (derste anlatılmadı):** Örnekte biasların güncellenmesi gösterilmedi. Bölüm 8.1'deki formüllere göre bias ağırlıkları da $\Delta w_{0k} = \alpha \delta_k$ ve $\Delta v_{0j} = \alpha \delta_j$ ile güncellenir; bias birimi girdisi her zaman 1 olan bir nöron gibi davranır.

> **Hocanın vurgusu:** Zincir kuralı gibi işlemleri elinizle uygulamanız gerekir. Sadece izleyerek bu iş olmaz; örnekleri elle yazarak çözün.

## 10. Uygulamaya Dönük İki Kilit Nokta

### 10.1 Matris biçiminde, sistematik hesap

Derste her ağırlık için işlem tek tek yapıldı, ama $w_5$ ve $w_6$'ya göre türev alınırken formüllerdeki parametreler ortaktır. Bu ortak kısım bir katsayı (düğüm deltası) olarak ifade edilebilir. Bilgisayarda kodlarken her ağırlığı tek tek hesaplamak yerine işlemler matris biçiminde, sistematik olarak yapılır. Derste tek tek gitmenin nedeni yalnız konunun anlaşılmasıdır.

> **Ek bilgi (derste anlatılmadı):** Matris biçiminde çıktı katmanı için $\boldsymbol{\delta}^{(o)} = -(\mathbf{t} - \mathbf{o}) \odot f'(\mathbf{net}^{(o)})$ ve ağırlık gradyanı $\boldsymbol{\delta}^{(o)} \mathbf{h}^{\top}$ biçiminde yazılır; gizli katman deltası da $\boldsymbol{\delta}^{(h)} = (W^{\top} \boldsymbol{\delta}^{(o)}) \odot f'(\mathbf{net}^{(h)})$ olur. Bu, Bölüm 8.1'deki $\delta\_in_j = \sum_k \delta_k w_{jk}$ ifadesinin vektör halidir.

### 10.2 Türev aktivasyon fonksiyonuna bağlıdır

İkinci kilit nokta türevdir. Örnekte aktivasyon fonksiyonu lojistik fonksiyon olduğu için türevi $out(1 - out)$ biçimindedir ve genelleştirme yapılırken bu ifade ortak bir katsayı olarak kullanılır. Fonksiyon farklı olsaydı türev ifadesi de farklı olacaktı ve güncelleme denklemindeki bu terim, kullanılan fonksiyonun türeviyle değişecekti.

> **Hocanın vurgusu:** Delta kuralı yazılırken $f(x)(1 - f(x))$ gibi bir terim kullanılır, ama bu, fonksiyonun lojistik fonksiyon olduğu varsayımından gelir. Kullandığınız aktivasyon fonksiyonunun ne olduğunu gözden kaçırmayın. Ağırlık güncelleme denkleminiz ona göre değişir; bu ifadeyi her problemde aynen kullanabileceğinizi varsaymayın.

## Örnek Sorular

**Soru 1** (ekrandan, 00:45:00): Girdileri $i_1 = 0.05$, $i_2 = 0.10$, hedefleri $0.01$ ve $0.99$ olan 2-2-2 yapısındaki ağda ağırlıklar $w_1 = 0.15$, $w_2 = 0.20$, $w_3 = 0.25$, $w_4 = 0.30$, $w_5 = 0.40$, $w_6 = 0.45$, $w_7 = 0.50$, $w_8 = 0.55$, biaslar $b_1 = 0.35$, $b_2 = 0.60$'tır. Aktivasyon lojistik fonksiyondur. İleri besleme yaparak çıktıları ve toplam hatayı bulun; $\eta = 0.5$ ile $w_5$'in yeni değerini hesaplayın.

> **Çözüm (derste verildi):** $out_{h1} = 0.593269992$, $out_{h2} = 0.596884378$; $net_{o1} = 1.105905967$, $out_{o1} = 0.751365$, $out_{o2} = 0.772928$. $E_{o1} = 0.274811$, $E_{o2} = 0.023560$, $E_{total} = 0.298371$ ($\tfrac12$ katsayılı karesel hata ile). $\partial E_{total} / \partial w_5 = 0.74136507 \cdot 0.186815602 \cdot 0.593269992 = 0.082167041$; $w_5^{+} = 0.4 - 0.5 \cdot 0.082167041 = 0.35891648$. Değerler python ile doğrulandı.

**Soru 2** (ekrandan, 00:55:00): Aynı örnekte $w_6$, $w_7$ ve $w_8$'in yeni değerleri nedir?

> **Çözüm (derste yalnız $w_6$ ekranda verildi):** $w_6$ için zincirin son çarpanı $out_{h2}$ olur: $w_6^{+} = 0.45 - 0.5 \cdot (0.741365 \cdot 0.186816 \cdot 0.596884) = 0.408666186$. $w_7$ ve $w_8$ için $o_2$'nin düğüm deltası kullanılır: $\delta_{o2} = -(0.99 - 0.772928) \cdot 0.772928 \cdot (1 - 0.772928) = -0.038098$; $w_7^{+} = 0.50 - 0.5 \cdot \delta_{o2} \cdot out_{h1} = 0.511301270$, $w_8^{+} = 0.55 - 0.5 \cdot \delta_{o2} \cdot out_{h2} = 0.561370121$. $w_7$ ve $w_8$ derste hesaplanmadı; değerler python ile hesaplandı.

**Soru 3** (derste sözlü, 00:25:18): Delta kuralının türetilmesinde $\partial E / \partial w_1 = -2(t - y_{in})x_1$ ifadesindeki eksi işareti nereden gelir?

> **Çözüm (derste verildi):** $E = (t - y_{in})^2$'nin türevinde dış türevden $2(t - y_{in})$ gelir. İç türev $\partial (t - y_{in}) / \partial w_1$'dir; $y_{in} = \sum x_i w_i$ içinde yalnız $x_1 w_1$ terimi $w_1$'e bağlıdır ve önünde eksi vardır. Bu yüzden iç türev $-x_1$ olur ve sonuç $-2(t - y_{in})x_1$ çıkar.

**Soru 4** (derste sözlü, 00:30:28): Basit bir karakter tanıma probleminde tek katmanlı perceptron 12 epokta %100 eğitim başarısına ulaşıyor. Bu ağ ezberlemiş midir?

> **Çözüm (derste verildi):** Hayır. 12 epok az bir eğitim miktarıdır ve bu süre boyunca hata eğrisi sürekli düşer. Harfler kolay ayrılabilir olduğu için problem gerçekten %100 çözülebilirdir. Ezberleme, hata düzlüğe girmişken eğitimi binlerce epok zorlamakla ortaya çıkar; bunu anlamak için hata grafiği çizdirilmelidir.

**Soru 5** (derste sözlü, 00:34:06): 63 girdili, 7 çıktılı tek katmanlı bir ağ 21 örnekle eğitiliyor. Baum ve Haussler'in $P = W/e$ ilişkisine göre durum nasıl yorumlanır?

> **Çözüm (derste kısmen verildi):** Hoca bağlantı sayısını $63 \times 7$ alıp $e$'nin bağlantı sayısının örnek sayısına oranından kabaca görülebileceğini söyledi. Hesap: $W = 441$, $e = W/P = 441/21 = 21$. Bu değer bir hata oranı olarak 1'den çok büyük olduğundan ilişki büyük olasılıkla bu kadar az örnekle bir doğruluk garantisi vermez; ağırlık sayısı arttıkça daha çok örnek gerekir. Problemin yine de çözülmesi, örneklerin kolay ayrılabilir olmasındandır.

## Dersin Toparlaması

Bu derste tek katmanlı ağlardan çok katmanlı ağlara geçildi ve bu ağları eğitmek için kullanılan geri yayılım algoritması tanıtıldı. Geri yayılım, ağın toplam karesel hatasını gradyan düşümüyle en aza indiren, genelleştirilmiş delta kuralı olarak da bilinen bir yöntemdir. Algoritma ileri besleme, hatanın hesaplanıp geriye yayılması ve ağırlık güncelleme aşamalarından oluşur. Her ağırlık, hatanın o ağırlığa göre türevi, yani hatadaki payı kadar ve gradyanın tersi yönünde değiştirilir. Aktivasyon fonksiyonunun sürekli, türevlenebilir, monoton azalmayan ve çıktı aralığına uygun olması gerekir; sigmoid fonksiyonlarının türevleri fonksiyonun kendisi cinsinden yazıldığı için hesap kolaylaşır. Eğitimde başlangıç ağırlıkları küçük rastgele değerlerden seçilir, hata grafiği izlenir ve aşırı eğitimin yol açtığı ezberlemeden kaçınılır. Ağırlık sayısı arttıkça daha fazla örneğe ihtiyaç duyulur.

Sayısal örnekte 2-2-2 yapısındaki bir ağda ileri besleme yapıldı, toplam hata bulundu ve çıktı katmanındaki $w_5$ ağırlığı zincir kuralıyla güncellendi. Gizli katman ağırlıklarının ($w_1 \dots w_4$) sayısal güncellemesinin bir sonraki derste yeniden ele alınacağı söylendi. Bundan sonraki derslerde derin öğrenmeye geçilecek ve geri yayılım orada da temel eğitim yöntemi olarak kullanılacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
