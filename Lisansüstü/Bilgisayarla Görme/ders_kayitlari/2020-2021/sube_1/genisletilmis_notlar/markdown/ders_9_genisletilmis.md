# Ders 9 Genişletilmiş Notu: Dönüşüm Uydurma (En Küçük Kareler, Hough, RANSAC) ve Yapay Sinir Ağlarına Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kenar Bulma Üzerine Kısa Not
- 2. İmge Dönüşümlerinin Özeti
- 3. Eşleşmiş Noktalardan Öteleme Bulma: En Küçük Kareler
- 4. Hough Dönüşümü ve RANSAC ile Öteleme
- 5. Derin Öğrenmeye Geçiş ve Gözetimli Öğrenme
- 6. Yapay Sinir Ağları: Yapı ve İleri Yayılım
- 7. Aktivasyon Fonksiyonları ve Doğrusal Olmama
- 8. Derinliğin Yorumu ve Ağ Tasarımı
- 9. Eğitim, Doğrulama ve Test Kümeleri
- 10. Ağın Ne Kadar İyi Olduğu: Softmax ve Kayıp Fonksiyonu
- 11. Eğitim: Kaybın En Aza İndirilmesi ve Gradyan İnişi
- 12. Geri Yayılım
- Örnek Sorular

## 1. Kenar Bulma Üzerine Kısa Not

Ders, bir önceki haftada kalınan model uydurma ve RANSAC konusundan devam etti. Bir öğrenci kenar bulma (edge detection) slaytlarının sonunun atlandığını hatırlattı. Hoca zaman kalmadığı için o kısmı atlayacağını söyledi, ama Canny kenar bulucusunun (Canny edge detector) bilinmesinin iyi olacağını, öğrencilerin bunu kendilerinin araştırmasını istedi.

> **Hocanın vurgusu:** Canny kenar bulucusunu bilseniz iyi olur; onu artık kendiniz araştırın.

## 2. İmge Dönüşümlerinin Özeti

Hoca, kaynak slaytlardaki imge dönüşümlerini özetleyen tabloya döndü. Tabloda öteleme (translation) dönüşümü $[I \mid t]$ diye yazılmıştı. Hoca bu gösterimi biraz tuhaf bulduğunu söyledi ve anlamını açıkladı: $I$ birim matristir (identity matrix), $t$ ise öteleme vektörüdür; $[I \mid t]$, bu iki matrisin yan yana konmasıyla oluşan matristir. Aynı tabloda döndürme, benzerlik (similarity), afin (affine) ve projektif (projective) dönüşümler de benzer biçimde özetlenmişti. Tablonun karede görünen son satırında projektif dönüşüm $3 \times 3$ boyutlu $H$ matrisiyle, 8 serbestlik derecesiyle ve "düz çizgileri korur" (straight lines) özelliğiyle verilmişti (ekrandan, 00:15:00).

<!-- BELİRSİZ: Tablonun yalnız projektif satırı karede okunuyor; diğer satırların serbestlik dereceleri ve korunan özellikler karede görünmüyor. -->

## 3. Eşleşmiş Noktalardan Öteleme Bulma: En Küçük Kareler

### 3.1 Problem

Slayttaki örnekte aynı nesnenin iki imgesi vardır (ekrandan, 00:10:00). Birinci imgede $A_1, A_2, A_3$ noktaları, ikinci imgede $B_1, B_2, B_3$ noktaları işaretlenmiştir. Hoca, bu noktaların tanımlayıcıları (descriptor) çok benzer olduğu için eşleşmiş kabul edildiğini söyledi. Amaç, birinci imgedeki noktaların ikinci imgedeki yerlerine hangi dönüşümle geldiğini, burada ötelemeyi $(t_x, t_y)$ bulmaktır. Slayttaki ifade şudur:

$$\begin{bmatrix} x_i^B \\ y_i^B \end{bmatrix} = \begin{bmatrix} x_i^A \\ y_i^A \end{bmatrix} + \begin{bmatrix} t_x \\ t_y \end{bmatrix}$$

Öteleme için iki bilinmeyen vardır: $t_x$ ve $t_y$. Bu yüzden iki denklem yeter. Ama eldeki eşleşme sayısı genelde çok fazladır, yani denklem sayısı bilinmeyen sayısından fazladır. Tam iki denklem varsa doğrudan çözülür; daha fazlası varsa uydurma (fitting) yapılır, örneğin en küçük kareler.

### 3.2 Slayttaki çözüm adımları

Slaytta "Least squares solution" başlığı altında şu adımlar vardı (ekrandan, 00:10:00):

- Amaç fonksiyonunu yaz.
- Türetilmiş çözüm: türevi hesapla, çözümü hesapla.
- Hesaplamalı çözüm: $Ax=b$ biçiminde yaz; sözde ters (pseudo-inverse) ya da özdeğer ayrışımı (eigenvalue decomposition) ile çöz.

Her eşleşme iki denklem verir. $t_x$ ile $t_y$, birinci satırda $1$ ve $0$ ile çarpılınca yalnız $t_x$ kalır ve sağ tarafta $x_1^B - x_1^A$ olur; ikinci satırda $0$ ve $1$ ile çarpılınca yalnız $t_y$ kalır. $n$ nokta için bu denklemler alt alta yazılır (ekrandan, 00:10:00):

$$\begin{bmatrix} 1 & 0 \\ 0 & 1 \\ \vdots & \vdots \\ 1 & 0 \\ 0 & 1 \end{bmatrix} \begin{bmatrix} t_x \\ t_y \end{bmatrix} = \begin{bmatrix} x_1^B - x_1^A \\ y_1^B - y_1^A \\ \vdots \\ x_n^B - x_n^A \\ y_n^B - y_n^A \end{bmatrix}$$

### 3.3 Sözde ters

Hoca bu kısmı tahtada adım adım anlattı. $Ax = b$ denkleminde $A$ ve $b$ bilinir, $x$ aranır. $A$'nın satır sayısı genelde $x$'in satır sayısından çok daha fazladır, çünkü elde çok veri vardır.

Normalde her iki taraf soldan $A^{-1}$ ile çarpılır ve $x = A^{-1}b$ bulunur. Ama burada $A$ kare matris değildir, bu yüzden tersi alınamaz. Bunun yerine şu yol izlenir:

- Her iki taraf soldan $A^T$ ile çarpılır: $A^TAx = A^Tb$.
- $A^TA$ kare bir matristir, dolayısıyla tersi alınabilir.
- Her iki taraf soldan $(A^TA)^{-1}$ ile çarpılır: $(A^TA)^{-1}A^TA\,x = (A^TA)^{-1}A^Tb$.
- Soldaki $(A^TA)^{-1}A^TA$ birim matris olur ve geriye $x = (A^TA)^{-1}A^Tb$ kalır.

$(A^TA)^{-1}A^T$ ifadesine sözde ters denir. Slayta göre aynı problem özdeğer ayrışımıyla da çözülebilir.

> **Hocanın vurgusu:** Bu, sınavda standart olarak sorduğu şeylerden biridir. Birkaç denklem verip bunları $Ax=b$ biçimine getirmenizi ve çözmenizi isteyebilir.

> **Ek bilgi (derste anlatılmadı):** Öteleme örneğinde $A^TA = nI_2$ ve $A^Tb$ farkların toplamı olduğundan sözde ters çözümü $t_x = \frac{1}{n}\sum_i (x_i^B - x_i^A)$, $t_y = \frac{1}{n}\sum_i (y_i^B - y_i^A)$ olur; yani en küçük kareler ötelemesi, farkların ortalamasıdır. Bu eşitlik rastgele verilerle python'da denetlendi.

## 4. Hough Dönüşümü ve RANSAC ile Öteleme

### 4.1 Problem: aykırı değerler

Gerçek eşleşmelerde sorunlar vardır. Slayttaki kırmızı yazıda bunlar "aykırı değerler (outliers), birden çok nesne ve/veya çoktan bire eşleşmeler" diye sıralanmıştı (ekrandan, 00:25:00). Slayta göre aykırı değerlerden kurtulmak için RANSAC uygulanabilir; bir diğer yol Hough dönüşümüdür.

### 4.2 Hough dönüşümü çözümü

Slayttaki adımlar şunlardır (ekrandan, 00:25:00):

- Parametre değerleri için bir ızgara oluştur (initialize a grid of parameter values).
- Her eşleşen çift tutarlı değerlere oy verir.
- En çok oy alan parametreleri bul.
- İç noktalarla (inlier) en küçük kareler çöz.

Hoca bunu öteleme üzerinden açıkladı. Parametreler $t_x$ ve $t_y$'dir. Karede hoca $t_x$ yatay, $t_y$ dikey eksen olan bir düzlem çizmiştir. Bu düzlem ızgaraya bölünür. İstenirse kutupsal koordinatlara geçilebilir, ama imge boyutları sınırlı olduğu için parametreler imge boyutlarıyla sınırlıdır. $A_1$ ile $B_1$ eşleşmişse, bu çiftin çözümünden gelen $(t_x, t_y)$ hücresine bir oy verilir. $A_2$ ile $B_2$ başka bir $(t_x, t_y)$ verir ve o da kendi hücresine oy verir. Bütün oylar biriktirilince Hough uzayı oluşur. Bu uzayda önce bir yumuşatma işlemi, ardından en büyük olmayanı bastırma (non-max suppression) uygulanır ve en çok oyun nereye atıldığı bulunur. Hoca bu yönteme genelleştirilmiş Hough dönüşümü dendiğini söyledi.

Hoca dördüncü adımın, yani iç noktalarla en küçük kareler çözmenin nedenini o an tam çıkaramadığını söyledi. Tahmini şuydu: birbirine yakın birkaç oy bölgesi olabilir; bu yakın bölgeleri birlikte göz önüne almak için en küçük kareler uydurması kullanılıyor olabilir.

> **Ders sonrası not:** Bu adım büyük olasılıkla bir iyileştirme (refinement) adımıdır: ızgaranın hücre genişliği sonucu nicemler (quantize), bu yüzden en çok oy alan hücreye oy veren eşleşmeler iç nokta kabul edilir ve kesin öteleme bu iç noktalarla en küçük kareler çözülerek bulunur.

### 4.3 RANSAC çözümü

RANSAC'ta önce modeli kurmaya yetecek en az sayıda nokta seçilir. Öteleme için bu tek bir noktadır, çünkü tek eşleşme iki denklem verir. Seçilen noktadan $(t_x, t_y)$ hesaplanır. Sonra belirli bir eşik içinde bu ötelemeye uyan, yani iç nokta olan kaç eşleşme olduğu sayılır ve bir kenara yazılır. Ardından başka bir noktadan yeni bir $(t_x, t_y)$ hesaplanır ve yine iç noktalar sayılır. En çok iç noktayı veren öteleme seçilir.

Hoca bu örneğin öteleme için olduğunu, ama aynı mantığın ölçekleme, döndürme, hatta projektif dönüşüm gibi bütün dönüşümlerde kullanılabileceğini söyledi.

### 4.4 Eşleşmiş çift yoksa

Bir sonraki slayt şu soruyu soruyordu: Hizalamak istiyorsunuz ama önceden eşleşmiş çiftleriniz yoksa ne olur? (ekrandan, 00:20:00). Slayta göre bu durumda Hough dönüşümü ve RANSAC uygulanamaz. Önemli uygulamalar olarak tıbbi görüntülemede beyin taramalarını ya da konturları eşleme ve robotikte nokta bulutlarını eşleme gösterilmişti. Hoca nokta bulutlarıyla ilgili bu kısmı atladı; merak edenlerin slaytların kaynağındaki (Derek Hoiem'in ders notları) ilgili bölüme bakabileceğini söyledi.

## 5. Derin Öğrenmeye Geçiş ve Gözetimli Öğrenme

### 5.1 Neden derin öğrenme?

Hoca sinir ağlarına geçerken derin ağların birden çok önemli hale geldiğini, hemen her problemde çok başarılı sonuçlar vermeye başladığını söyledi. Birçok kişi bununla çalıştığı ve uygulamalar geliştirildiği için bilgisayarla görme dersinde de buna bakmak kaçınılmaz olmuştur. Bu kısımda Ranzato'nun derin öğrenme slaytları kullanıldı. Slaytlardaki ana hat şuydu: gözetimli sinir ağları, evrişimli sinir ağları (convolutional neural networks), örnekler ve ipuçları (ekrandan, 00:45:00). Bu derste yalnız ilk kısım işlendi.

### 5.2 Gözetimli öğrenmenin tanımı

Derin öğrenme burada gözetimli (supervised) bir öğrenme yöntemi olarak ele alındı. Gözetimli öğrenmede elde bir veri kümesi vardır. Her örnek bir öznitelik vektörü $x$ ($x_1, x_2, x_3, \ldots$ gibi bileşenlerden oluşan) ve bu vektörün etiketi $y$'den oluşur. Slayttaki gösterim şudur (ekrandan, 00:35:00):

- $\{(x^i, y^i),\ i = 1 \ldots P\}$: eğitim veri kümesi.
- $x^i$: $i$. girdi eğitim örneği.
- $y^i$: $i$. hedef etiket.
- $P$: eğitim örneği sayısı.

Hoca örnek numarasının üst simge olarak yazılmasının nedenini açıkladı: $x_1, x_2$ gibi alt simgeler vektörün bileşenleri için kullanılır, $x^2$ ise kare ile karışabilir. Bu yüzden normalde $x^{(1)}, x^{(2)}$ gibi parantez konur; slaytta parantez kullanılmamıştır.

Slayttaki kutu çiziminde $x$ girer, $y$ çıkar. Amaç, görülmemiş girdilerin hedef etiketini tahmin etmektir (ekrandan, 00:35:00). Yani eğitilen model, etiketini hiç görmediği $x^{P+1}$ verildiğinde $y^{P+1}$'i tahmin edebilmelidir.

"Gözetimli" denmesinin nedeni, eğitim sırasında etiketlerin verilmesidir. Etiket verilmeyen yöntemlere gözetimsiz (unsupervised) öğrenme denir.

### 5.3 Gözetimli öğrenme örnekleri

Slaytta üç örnek vardı (ekrandan, 00:40:00):

- Sınıflama (classification): bir köpek resmi kutuya girer, çıktı "dog" olur. Resimdeki nesnenin ne olduğu söylenir.
- Gürültü giderme (denoising): gürültülü bir resim girer, temiz resim çıkar. Bu bir regresyon örneğidir, çünkü regresyon bir sayıyı tahmin etme işidir. Resim $N \times N$ uzunluğunda bir vektör olarak düşünülürse, model her pikselin gerçek değerini, yani vektörün bileşenlerinin değerlerini tahmin eder.
- OCR: elle yazılmış karakterlerin ne olduğunun anlaşılması. Slaytta buna yapılandırılmış tahmin (structured prediction) denmişti.

Hoca "structured" sözünün nereden geldiğini bilmediğini, belki yapının da tahmin edildiği için böyle dendiğini söyledi. Ayrıca bir resimde tek bir köpek değil birden çok nesne olabileceğini, bütün bu nesnelerin ayırt edilip tanınması gerektiğini örnek verdi.

### 5.4 "Derin" sözü

Birçok öğrenme algoritması vardır: SVM, KNN, Naive Bayes gibi. Bu derste ilgilenilen yapay sinir ağları ve onlardan gelen derin ağlardır. "Derin" sözü yapının çok sayıda katman içerdiğini gösterir. Derinliğin nerede başladığı tartışılabilir; hoca, girdi ve çıktı da sayılırsa dört katmandan sonrasına derin denebileceğini düşündüğünü söyledi. Günümüzde yüzlerce katmanlı ağlar vardır. Bu işi derin ağlara yaptırınca gözetimli derin öğrenme olur.

## 6. Yapay Sinir Ağları: Yapı ve İleri Yayılım

### 6.1 Varsayımlar ve fonksiyon sınıfı

Sonraki birkaç slayt için, yani evrişimli ağlara geçmeden önce, girdi $n \times n$ uzunluğunda bir vektör olarak düşünülür ve hedef ayrık, yani bir sınıflama yapılacaktır. Slayttaki soru şudur: Girdiyi çıktıya eşlemek için hangi fonksiyon sınıfı düşünülmelidir? Fonksiyon girdi vektörünü alıp ayrık bir sonuç döndürmelidir: 0 ya da 1, ya da 1, 2, 3 gibi bir sınıf numarası, ya da $[0, 1, 0, 0, \ldots]$ gibi doğru sınıfın yerinde 1 olan bir vektör.

Sinir ağlarında birçok basit fonksiyonun bileşiminden yararlanılır. $x$ bir fonksiyondan geçer, sonucu başka bir fonksiyona, onun sonucu da başka bir fonksiyona verilir. Bu basit fonksiyonlar son derece karmaşık ilişkileri temsil edebilir. Bu fonksiyonlar doğrusal değil, doğrusal olmayan (non-linear) fonksiyonlar olarak seçilir.

Hoca sinir ağlarının sinirbilimden gelen bir geçmişi olduğunu (nöronlar, aksonlar vb.), ama bugün fonksiyonel ve matematiksel açıklamanın daha önemli hale geldiğini düşündüğünü söyledi. Bu yüzden ağlara doğrudan fonksiyon olarak bakıldı.

### 6.2 Örnek ağ

Slayttaki örnek ağ şudur (ekrandan, 01:05:00):

```text
x --> [ max(0, W1 x) ] --> h1 --> [ max(0, W2 h1) ] --> h2 --> [ W3 h2 ] --> o
```

- $x$: girdi.
- $h^1$: birinci katman gizli birimleri.
- $h^2$: ikinci katman gizli birimleri.
- $o$: çıktı.

Slayta göre bu, iki gizli katmanlı bir sinir ağıdır; girdi ve çıktı da sayılırsa dört katmanlı ağ olur. "Gizli" (hidden) sözü ağı bir kutu olarak düşünmekten gelir: kutunun dışından yalnız girdi ve çıktı katmanları görünür, aradaki katmanlar görünmez. Hoca bu sözün yavaş yavaş modasını kaybettiğini, girdi ve çıktıyı da sayarak "dört katmanlı ağ" denmesinin de yaygın olduğunu söyledi.

### 6.3 Bir katmanın hesabı

Girdi $x = [x_1, x_2, \ldots]^T$ vektörüdür. Birinci katmanda katsayıları içeren bir ağırlık matrisi $W^1$ vardır. Girdi bu matrisle matris çarpımına sokulur: matrisin her satırı girdi vektörüyle çarpılıp toplanır ve yeni bir vektör elde edilir. Hoca bunu tahtada çizdi (ekrandan, 01:10:00). Bu çarpımdan hemen sonra sonuç aktivasyon fonksiyonu $a$'ya verilir. Aktivasyon fonksiyonu doğrusal olmamayı sağlar, çünkü matris çarpımı tek başına doğrusal bir işlemdir. Sonuç $h^1$ katmanıdır.

### 6.4 Boyutlar ve bias

"Forward Propagation" slaytında boyutlar ayrıntılı verilmişti (ekrandan, 01:25:00):

$$x \in \mathbb{R}^D, \quad W^1 \in \mathbb{R}^{N_1 \times D}, \quad b^1 \in \mathbb{R}^{N_1}, \quad h^1 \in \mathbb{R}^{N_1}$$

$$h^1 = \max(0,\ W^1x + b^1)$$

- $W^1$: birinci katman ağırlık matrisi ya da ağırlıklar.
- $b^1$: birinci katman biasları.

$x$, gerçel sayılardan oluşan $D$ boyutlu bir vektördür. Birinci katmandaki değer sayısı $N_1$, girdi sayısıyla aynı olmak zorunda değildir; genelde farklıdır. Bu yüzden $W^1$'in satır sayısı $N_1$, sütun sayısı $D$'dir: matris çarpımı yapılabilmesi için her satırda $D$ eleman olmalıdır. Sonuçta $h^1 = [h_1, \ldots, h_{N_1}]$ elde edilir. Örneğin 800 girdi 400 değere indirilebilir; katmanların boyutu bu şekilde değiştirilebilir.

Çarpımın sonucu, aktivasyona verilmeden önce $b^1$ ile toplanır. Çarpımın sonucuyla toplanabilmesi için $b^1$'in de $N_1$ elemanı olmalıdır.

Hoca biasın işlevini doğru denklemiyle açıkladı. $y = mx + b$ denkleminde $m$ değiştirilince doğrunun eğimi değişir: $m$ büyüdükçe doğru dikleşir, küçüldükçe yatıklaşır. $b$ ise doğrunun yerini değiştirir, doğruyu kaydırır (shift). Sinir ağında da fonksiyonu istenen yere kaydırabilmek için girdiden bağımsız sayılar gerekir; bunlara bias denir (ekrandan, 01:25:00, karede $y = mx + b$ yazısı).

Bias, istenirse $W$'nin içine katılabilir. Bunun için $x$'in sonuna bir 1 eklenir ve $b$'nin elemanları ($b_1, b_2, \ldots, b_{N_1}$) $W$'nin son sütununa konur. Böylece çarpım tek bir matris çarpımıyla yazılır. Hoca bunun en küçük kareler konusunda da yapıldığını hatırlattı ve iki yazım arasında büyük bir fark olmadığını söyledi.

### 6.5 ReLU ve tam bağlı katman

Slayta göre $u = \max(0, v)$ doğrusal olmamasına derin öğrenme literatüründe ReLU denir (ekrandan, 01:25:00). Bu örnekte katman tam bağlıdır (fully connected): $h^1$'deki her elemanı hesaplarken $x$'deki elemanların hepsi kullanılır. Sinirbilim bakışıyla her bileşen bir nöron kabul edilirse, bir çıktı nöronunun değeri hesaplanırken bütün girdi nöronları ona bilgi gönderir. Tam bağlı olmayan ağlar da vardır.

### 6.6 Sonraki katmanlar ve çıktı

İkinci katman hesaplanırken birinci katman girdi gibi davranır: $h^2 = \max(0, W^2h^1 + b^2)$. Slaytta bu katmanın biası kalabalık olmasın diye yazılmamıştı. Farklı katmanlarda farklı aktivasyonlar kullanılabilir. Çıkış katmanı için slayttaki ifade şudur (ekrandan, 01:30:00):

$$h^2 \in \mathbb{R}^{N_2}, \quad W^3 \in \mathbb{R}^{N_3 \times N_2}, \quad b^3 \in \mathbb{R}^{N_3}, \quad o \in \mathbb{R}^{N_3}$$

$$o = \max(0,\ W^3h^2 + b^3)$$

İlk örnek ağın çiziminde son blok $W^3h^2$ diye, yani aktivasyonsuz verilmişti; bu slaytta ise çıkışta da ReLU kullanılmıştır. Her katmanın boyutu $W$ ve $b$'nin boyutuyla ayarlanır. Çıkış katmanındaki değer sayısı problemin gerektirdiği sayıya göre seçilir (sınıflama ya da regresyon, kaç değer gerektiği). Örneğin 800 değer önce 600'e, sonra 400'e, sonunda gereken 100'e indirilebilir; hoca, boyutun bir anda değil yavaş yavaş değiştirilmesinin gördüğü bir uygulama olduğunu söyledi.

Ağ tasarımı bu soruları içerir: kaç katman olacak, çıkış sayısı probleme göre kaç olacak, içeride doğrusal olmama olarak ReLU mu yoksa başka bir şey mi kullanılacak?

### 6.7 İleri yayılım

Ağın hesabının yapılıp sonucunun bulunmasına ileri yayılım (forward propagation) denir. $x$ girer, birinci katman, ikinci katman, üçüncü katman ve en son çıktı elde edilir; hesap ileriye doğru yayılır. Eğitim için bir de geriye doğru hesaplama gerekecektir (Bölüm 12).

### 6.8 Farklı çizim biçimleri

Hoca, aynı ağın farklı yazarlar tarafından farklı biçimlerde çizilebildiğini gösterdi. Bir gösterimde aktivasyon fonksiyonu ayrı bir hesap olarak gösterilir. Bir başkasında katmanlar ve ağırlıklar çizilir, aktivasyon hiç gösterilmez, yalnız metinde belirtilir. Sinirbilimden gelen gösterimde ise bir katmandaki vektörün her bileşeni bir nöronun aktivasyon değeri olarak çizilir. Hoca, bu alanın beyinden esinlenerek başladığını, ama popüler ağların gittikçe beyinden uzaklaşıp matematik ve mühendislik mantığına oturduğunu, yine de bu konuda ciddi çalışan araştırmacılar olduğunu söyledi.

## 7. Aktivasyon Fonksiyonları ve Doğrusal Olmama

### 7.1 Doğrusal ayırıcıların sınırı: XOR örneği

Hoca doğrusal işlemlerin sorununu iki öznitelikli basit bir örnekle gösterdi. Tahtada çizdiği tablo şuydu (ekrandan, 01:10:00 ve 01:20:00):

| $x_1$ | $x_2$ | etiket |
|---|---|---|
| 0 | 0 | 0 |
| 1 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 1 | 0 |

Öğrenme algoritmaları bir karar çizgisi belirliyor gibi düşünülebilir. Doğrusal algoritmalar düz bir çizgi, yani bir doğru oluşturur. Bu örnekte nasıl bir doğru çizilirse çizilsin 1'ler ile 0'lar doğru ayrılamaz: bir doğru bir noktayı yanlış bırakır, başka bir doğru iki noktayı birden yanlış bırakır. Uzay bir doğruyla ayrılabilecek bir uzay değilse doğrusal algoritmalar ve doğrusal fonksiyonlar bu uzayı bölemez.

<!-- BELİRSİZ: Altyazıda tablo değerleri karışık okunuyor (ör. "x1 ve x2 sıfırsa tahmininiz bir olsun. Yani sıfır olsun"); değerler hocanın tahtaya çizdiği şekilden alındı. -->

> **Ek bilgi (derste anlatılmadı):** Bu tablo XOR (dışlayıcı veya) fonksiyonudur. Doğrusal ayrılamadığı, $(w_1, w_2, c)$ için kaba bir ızgara aramasıyla python'da da denetlendi: hiçbir $w_1x_1 + w_2x_2 + c > 0$ kuralı dört noktayı doğru sınıflamadı.

Matris çarpımı doğrusal bir işlemdir. Sonraki katmanlarda da yalnız matris çarpımları kullanılırsa, bunlar yan yana yazılmış gibi düşünülebilir: doğrusal matrislerin çarpımı yine bir matristir ve yine doğrusal bir fonksiyon verir. Bu doğrusallıktan kurtulmak için çarpımın sonucu doğrusal olmayan bir fonksiyona verilir ve olaya bu aşamada doğrusal olmama katılır.

### 7.2 ReLU

Bu örnekteki doğrusal olmama $f(x) = \max(0, x)$'tir: değer sıfırdan büyükse kendisi yazılır, küçükse sıfırla değiştirilir. Buna ReLU (Rectified Linear Unit) denir (ekrandan, 01:20:00). Grafiği, $x$ sıfıra gelinceye kadar sıfır, sıfırdan sonra $f(x) = x$ olan kırık bir çizgidir. Hoca bunun bugün popüler, neredeyse varsayılan aktivasyon fonksiyonu olduğunu söyledi.

ReLU'nun türevi de güzeldir. Fonksiyon parça parça tanımlı olduğundan türevi de parça parça bulunur (ekrandan, 01:20:00):

$$\frac{df(x)}{dx} = \begin{cases} 0, & x < 0 \\ 1, & x > 0 \end{cases}$$

$x < 0$ iken fonksiyon sabit sıfırdır ve türevi sıfırdır; $x > 0$ iken $f(x) = x$ olduğundan türev 1'dir.

### 7.3 Diğer aktivasyonlar

Klasik aktivasyon sigmoid'dir; değerleri 0 ile 1 arasına eşler. Hoca bunun bir sakıncasını şöyle anlattı: 0 ile 1 arasına eşleyince çıktının ortalaması sıfır değil yarım olur, bu yüzden her uygulandığında fonksiyonun ortalaması kayar. Değerleri $-1$ ile $1$ arasına eşleyen versiyonu tanh'tır. ReLU çok popüler olduğu için türevleri de çıkmıştır: negatif tarafta tam sıfır yerine küçük bir eğimle gelen sürüm ve köşesi yumuşatılmış, parça parça tanımlı olmayan sürüm.

Bu ağırlıkların, yani $W$'lerin öğrenilmesi amaçtır: $W$'ler öğrenilince fonksiyon öğrenilmiş olur.

Hoca burada genel bilgi verdiğini, sinir ağlarıyla ciddi çalışmak isteyenlerin sağlam bir kitap okuması gerektiğini söyledi ve Ian Goodfellow ile Yoshua Bengio'nun (bir yazarla birlikte) yazdığı "Deep Learning" kitabını önerdi.

### 7.4 Yorum: neden doğrusal olamaz, ReLU ne yapar?

"Interpretation" slaytında iki soru vardı (ekrandan, 01:35:00):

- Soru: Katmanlar arasındaki eşleme neden doğrusal olamaz? Cevap: Doğrusal fonksiyonların bileşkesi doğrusal bir fonksiyondur; sinir ağı (tek katmanlı) lojistik regresyona indirgenirdi.
- Soru: ReLU katmanları ne sağlar? Cevap: Parça parça doğrusal döşeme (piece-wise linear tiling): eşleme yerel olarak doğrusaldır.

Hoca ReLU'nun yapısının doğrusala çok benzediğini, aslında iki doğrusal parçanın birlikte kullanıldığı parça parça bir fonksiyon olduğunu vurguladı. Bu hoş bir özelliktir, çünkü doğrusallığın da güzel özellikleri vardır: ReLU doğrusallığı içerir ama doğrusal değildir. Böylece birçok küçük doğrusal ayırıcı birlikte kullanılmış olur. XOR gibi ayrılması zor bir fonksiyon, birden fazla çizgi kullanılarak bölünebilir. Eşleme yerelde doğrusal, genelde doğrusal değildir. Slayttaki şekil, dalgalı bir yüzeye kırmızı düzlemsel parçaların oturtulmasını gösteriyordu.

> **Ders sonrası not:** Hoca bu kısımda "Logistic Regression dediğimiz Linear Regression" dedi. Lojistik regresyon ile doğrusal regresyon farklı modellerdir: doğrusal regresyon sürekli bir değer tahmin eder, lojistik regresyon doğrusal bir skorun sigmoid/softmax'tan geçirilmesiyle sınıf olasılığı verir. Slayttaki ifade "(1 katmanlı) lojistik regresyon"dur; aktivasyonsuz bir ağ, çıkışında softmax varsa lojistik regresyona, yoksa tek bir doğrusal eşlemeye indirgenir.

## 8. Derinliğin Yorumu ve Ağ Tasarımı

### 8.1 Neden birden fazla katman?

Slayttaki cevap şuydu: Girdinin hiyerarşik bir yapısı varsa hiyerarşik bir mimari kullanmak büyük olasılıkla daha verimlidir, çünkü ara hesaplamalar yeniden kullanılabilir. Derin mimariler ayrıca sınıflar arasında paylaşılan dağıtık temsiller (distributed representations) kullandığı için de verimlidir.

Hoca bunu slayttaki kamyon örneğiyle anlattı. Bir kamyonun hiyerarşik bir yapısı vardır: tekerlekler, lambalar ve benzer parçalar. Bu parçalar da daireler, kareler ya da çizgiler gibi daha basit yapılardan oluşur. "Interpretation" slaytındaki şekilde girdi imgesinin üzerinde düşük düzey parçalar, orta düzey parçalar ve yüksek düzey parçalar (araba, bisiklet) ve en üstte sınıf tahmini vardı; yanında "dağıtık temsiller, öznitelik paylaşımı, bileşimsellik" yazıyordu (ekrandan, 01:40:00).

- Bir katman alt düzey özellikleri, örneğin basit gradyanları oluşturuyor olabilir.
- Bir üst katman eğriler gibi biraz daha üst düzey özellikleri oluşturur.
- Daha üst katmanlar bunlardan yararlanarak bisiklet, araba gibi nesneleri öğrenebilir.

Buna bileşimsellik denir. Öznitelik paylaşımı da olabilir: bazı yapılarda bir katmanın çıktısı birkaç katman sonraki bir katmana doğrudan verilir ve ara temsil ağın ilerisinde yeniden kullanılır. Ayrıca bir tekerlek bilgisi farklı amaçlar için kullanılabilir: burada da bir tekerlek, orada da bir tekerlek varsa bunun bir araç olduğu anlaşılabilir. Hoca "dağıtık" sözüyle tam olarak ne kastedildiğini o an anlayamadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Dağıtık temsilde bir kavram tek bir birimle değil, birçok birimin birlikte aldığı değerlerle kodlanır; her birim de birçok kavramın temsiline katkı verir. Böylece $N$ birimle $N$'den çok daha fazla kavram ayırt edilebilir ve birimler sınıflar arasında paylaşılır.

### 8.2 Gizli birim ne yapar?

Slayttaki cevaba göre gizli birim bir sınıflayıcı ya da öznitelik bulucu (feature detector) olarak düşünülebilir (ekrandan, 01:45:00). Hoca bunu dersin ilk bölümüyle ilişkilendirdi. Derin öğrenme yaygın değilken bir sınıflama algoritmasına insanların elle tasarladığı öznitelikler verilirdi. SIFT öznitelikleri bunun örneğidir: üzerinde düşünülerek tasarlanmış, David Lowe tarafından ortaya konmuş, çok atıf alan başarılı bir özniteliktir. Derin öğrenme ise öznitelik tasarımını da kendi içine almıştır: kullanılacak filtreleri öğrenir ve filtrelerin öğrenilmesi, çıkarılacak özniteliklerin öğrenilmesi demektir. Bu, evrişimli ağlarda daha ayrıntılı görülecektir.

### 8.3 Kaç katman, kaç birim?

Slayttaki cevap: Çapraz doğrulama (cross-validation) ya da hiperparametre arama yöntemleri. Genel olarak ağ ne kadar geniş ve derin olursa eşleme o kadar karmaşık olur (ekrandan, 01:45:00). Hoca "birim" sözünün, o katmandaki vektörün bir bileşeni anlamına geldiğini söyledi. Kaç katman ve kaç bileşen gerektiği "kara sanat" (black art) diye anılır; tasarımcının kararıdır ve kesin bir şey söylemek zordur.

### 8.4 Ağırlık matrisleri nasıl belirlenir?

Slayttaki cevap: Ağırlık matrisleri ve biaslar öğrenilir. Önce o anki eşlemenin kalitesini ölçen bir ölçü tanımlanmalı, sonra parametreleri ayarlayan bir yöntem tanımlanmalıdır (ekrandan, 01:45:00). Hoca, $W$ ve $b$'nin zaten öğrenildiğini, eğitimin amacının onlara iyi sonuç verecek değerleri atamak olduğunu söyledi.

## 9. Eğitim, Doğrulama ve Test Kümeleri

Hoca çapraz doğrulamayı açıklarken veri bölmeyi anlattı. Normalde veri ikiye bölünür: eğitim verisi ve test verisi. Model eğitim verisiyle eğitilir, test verisiyle başarısı ölçülür. Burada bunun yerine veriyi üçe ayırma fikri vardır: eğitim, doğrulama (validation) ve test.

Hocanın örneğinde 1000 örnek vardır (hoca bunun derin öğrenme için çok küçük olduğunu, milyonlar düzeyinde örnek kullanıldığını söyledi). Bunun 200'ü test için ayrılır; kalan 800'ün 600'ü eğitim, 200'ü doğrulama için kullanılır. Hoca bu oranları rastgele verdiğini belirtti.

> **Hocanın vurgusu:** Test ve eğitim verisini ayırmak şarttır. Yeni başlayanlar modeli eğittikleri veriyle test edebilir; bu son derece hatalıdır. Model gerçek hayatta görmediği verilerle karşılaşacağı için görmediği verideki başarısı ölçülmelidir.

Kümelerin görevleri şöyledir:

- Eğitim kümesi: ağırlıkları ($W$'leri) elde etmek için.
- Test kümesi: en sonda modelin başarısını söylemek için.
- Doğrulama kümesi: farklı modeller arasında seçim yapmak için. Örneğin 10 katmanlı bir ağ ile 11 katmanlı bir ağdan hangisinin daha iyi olduğu doğrulama kümesi üzerinden seçilir.

Hoca literatürde doğrulama kümesinin ikinci bir kullanımını da gördüğünü söyledi: eğitim verisi tekrar bölünür ve ayrılan kısım eğitimin ne zaman durdurulacağına karar vermek için kullanılır. Eğitim, doğrulama kümesindeki başarı artık iyileşmeyinceye kadar sürdürülür; iyileşme durunca eğitim durdurulur.

## 10. Ağın Ne Kadar İyi Olduğu: Softmax ve Kayıp Fonksiyonu

### 10.1 Çıktıyı etiketle karşılaştırmak

Eğitim için ağın verdiği çıktı vektörü gerçek değerle karşılaştırılmalıdır. Eğitim kümesinde etiketler vardır; ağın çıktısı etiketle ne kadar uyuşuyorsa ona göre $W$'ler değiştirilir ki çıktı yavaş yavaş daha iyi uysun. $W$'ler değiştikçe fonksiyon değişir ve örnekleri ürettiği varsayılan gerçek fonksiyona yaklaşır.

"How Good is a Network?" slaytında ağın çıktısı $o$, bir kayıp (loss) bloğuna gider; etiket $y$ de aynı bloğa gelir (ekrandan, 02:10:00). Etiketler şu biçimde verilmiştir: $C$ sınıf varsa

$$y = [0\ 0 \ldots 0\ 1\ 0 \ldots 0]$$

vektöründe $k$. eleman 1, diğerleri 0 ise örnek $k$ numaralı sınıftandır. Çıktı $o$ da $C$ değer içerir.

### 10.2 Softmax

Sinir ağı büyük olasılıkla tam 0 ve 1 değerleri vermez; hocanın karedeki notunda olduğu gibi 0,3 ya da 0,5 gibi değerler verebilir. Bu çıktılardan hangisinin alınacağına karar vermek için softmax fonksiyonu kullanılabilir. Softmax çıktıları olasılığa çevirir ve her sınıfın olasılığını verir. Slayttaki ifade şudur (ekrandan, 02:10:00):

$$p(c_k = 1 \mid x) = \frac{e^{o_k}}{\sum_{j=1}^{C} e^{o_j}}$$

Pay, $k$. çıktının üstelidir; payda bütün çıktıların üstellerinin toplamıdır. Bu toplamla bölündüğü için değer 1'e normalize edilir ve 0 ile 1 arasında çıkar. Hoca karede bunu $[0, 1]$ diye not etti.

**Soru:** Toplam birden büyük olamaz mı? Bölmenin sonucu 0 ile 1 arasında galiba. **Cevap:** Evet, kastedilen buydu: toplamla normalize edildiği için bu değer 0 ile 1 arasına iner.

### 10.3 Kayıp fonksiyonu seçimi

Her örnek (gözlem) için bir kayıp, yani hata değeri hesaplanır (per-sample loss). Birçok farklı kayıp fonksiyonu vardır. Hoca bilinen bir örnek olarak Öklit uzaklığının karesini, yani $\sum_i (x_i - y_i)^2$ toplamını verdi. Değerler birbirine yakınsa küçük, farklıysa büyük çıkan her fonksiyon bir hata fonksiyonu olabilir. Hangi fonksiyonun seçileceği türevinin özelliklerine ve deneysel sonuçlara bağlıdır: uzun yıllardır yapılan çalışmalarda bazı kayıp fonksiyonlarının daha iyi sonuç verdiği gözlenmiş ve bu yüzden seçilmektedir.

### 10.4 Negatif log-olabilirlik

Slaytta anlatılan kayıp, negatif log-olabilirliktir (negative log-likelihood). Slayta göre az sayıda sınıflı sınıflama için iyidir (ekrandan, 02:10:00):

$$L(x, y; \theta) = -\sum_j y_j \log p(c_j \mid x)$$

Hoca ve öğrenciler $\theta$'nın ne olduğunu tartıştı; bir öğrenci eşik olabileceğini önerdi, hoca ağırlıklar olabileceğini düşündü. Bir sonraki slaytta $\theta$'nın bütün parametrelerin listesi olduğu anlaşıldı (Bölüm 11.1).

Formülün işleyişi şöyledir. $j$. bileşenin softmax çıktısının logaritması alınır ve etiketin $j$. elemanı $y_j$ ile çarpılır. Yanlış sınıflar için $y_j = 0$ olduğundan bu terimler toplama girmez; yalnız doğru sınıfın terimi kalır. Hoca baktığı bir web sayfasına dayanarak birden fazla sınıfın doğru kabul edildiği durumlarda onların da toplama girdiğini söyledi. Sonuç negatif işaretle çarpılır.

0 ile 1 arasındaki sayıların logaritması negatiftir. Logaritma grafiği yavaş artan bir eğridir; $\log 1 = 0$'dır ve değer 1'den 0'a doğru düştükçe logaritma hızla eksi sonsuza gider. Bu yüzden:

- Doğru sınıfın olasılığı 0,9 gibi büyük bir değerse logaritma küçük bir negatif sayıdır; başındaki eksiyle küçük pozitif bir kayıp olur.
- Olasılık 0,1 gibi sıfıra yakın bir değerse logaritma büyük bir negatif sayıdır; eksiyle büyük pozitif bir kayıp olur.

Yani olasılık küçüldükçe hata büyür. Etiketi 1 olan sınıfa küçük olasılık verilirse büyük, büyük olasılık verilirse küçük bir hata çıkar; istenen de budur.

Hocanın verdiği iki olasılık için değerler (doğal logaritmayla, ara adım eklendi, python ile hesaplandı): $-\ln 0{,}9 \approx 0{,}105$ ve $-\ln 0{,}1 \approx 2{,}303$.

> **Ders sonrası not:** Hoca açıklamanın başında "olasılık büyükse bu değer büyük çıkacak" dedi, sonra doğrusunu anlattı: olasılık büyükse kayıp küçük, olasılık küçükse kayıp büyüktür. Ayrıca logaritmanın 0'a yaklaşırken "eksponansiyel biçimde" azaldığını söyledi; doğrusu, $\log p$ değeri $p \to 0$ iken sınırsızca $-\infty$'a gider, ama bu büyümenin hızı üstel değil logaritmiktir ($-\log p = \log(1/p)$).

> **Ders sonrası not:** Hoca baktığı kaynakta kayıp fonksiyonunun türevinin "1 bölü $p_k$" çıktığını okudu. $-\log p_k$'nin $p_k$'ye göre türevi $-1/p_k$'dir (işaret negatif). Softmax'ın girdisine göre türev ise Bölüm 12.1'deki $p - y$ ifadesidir.

## 11. Eğitim: Kaybın En Aza İndirilmesi ve Gradyan İnişi

### 11.1 Öğrenmenin tanımı

"Training" slaytına göre öğrenme, kaybın (artı bir düzenlileştirme teriminin) parametrelere göre bütün eğitim kümesi üzerinde en aza indirilmesidir (ekrandan, 02:25:00). Parametreler $W^1, b^1, W^2, b^2, \ldots$, yani bütün ağırlıklar ve biaslardır. Bunlar bir listeye konup $\theta$ diye adlandırılır. Hoca karede şunu yazdı:

$$\theta = [W^{(1)}, b^{(1)}, W^{(2)}, b^{(2)}, \ldots]$$

Bir önceki kayıp bir örneğin vektör bileşenleri üzerinde toplamdı. Burada ayrıca 1'den $P$'ye kadar bütün eğitim kümesinin kayıpları toplanır. Bu toplamı en küçük yapan $\theta$ aranır (ekrandan, 02:25:00):

$$\theta^* = \arg\min_\theta \sum_{n=1}^{P} L(x^n, y^n; \theta)$$

$W^1$ bir matristir, ama satırları yan yana konarak bir vektör gibi düşünülebilir. Böylece bütün parametreler tek, büyük bir vektör olarak ele alınabilir. Kayıp ifadesindeki $\theta$ ise eğitimin o aşamasında eldeki parametre değerleridir. Bu toplamı en aza indiren $\theta$'yı bulmak bir optimizasyon problemidir.

### 11.2 Gradyan inişi

Çok kullanılan bir yöntem stokastik gradyan inişidir (stochastic gradient descent). Hoca önce gradyan inişini hatırlattı. En aza indirilecek toplam fonksiyona $f$ denirse, $i+1$. iterasyonda $j$. parametrenin değeri şöyle bulunur:

$$\theta_j^{(i+1)} = \theta_j^{(i)} - \alpha \left.\frac{\partial f}{\partial \theta_j}\right|_{\theta^{(i)}}$$

Burada $\theta_j^{(i)}$ bilinir, $\alpha$ bir şekilde seçilir ve $f$'nin $\theta_j$'ye göre türevi $i$. iterasyondaki değerlerde hesaplanır. Hoca iterasyon numarasını, bileşen numarasıyla karışmasın diye üst simge olarak yazdı. Yani türevin tersi yönünde bir miktar giderek $\theta$ değiştirilir.

Gradyanın kullanılmasının nedeni şudur: bir noktadaki gradyan, fonksiyonun o noktada en büyük artışının yönünü gösterir. İki boyutlu bir fonksiyon çizilip gradyan yönüne gidilirse fonksiyon en büyük artışı o yönde yapar. Negatif gradyanla toplandığı için en hızlı iniş yönüne gidilir. Gradyan inişinin mantığı budur.

Hoca, optimizasyonda kullanılan klasik gradyan inişinde $\alpha$'nın her adımda bir iç minimizasyonla bulunduğunu, yani iç içe iki minimizasyon olduğunu söyledi. Bu karmaşık bir işlem olduğu için derin öğrenme eğitiminde büyük olasılıkla atlanır; sabit bir adım büyüklüğü seçilir ya da adım büyüklüğü iterasyon sayısına göre değiştirilir.

> **Ders sonrası not:** Her adımda adım büyüklüğünü bir iç minimizasyonla (doğru boyunca arama, line search) bulmak, gradyan inişinin bir türüdür (ör. tam doğru aramalı en dik iniş). Gradyan inişi tanımı gereği bunu gerektirmez; sabit adım büyüklüğüyle de gradyan inişi denir. Derin öğrenmede kullanılan da büyük olasılıkla sabit ya da bir takvime göre azalan adım büyüklüğüdür.

### 11.3 Stokastik, toplu ve mini-toplu gradyan inişi

Hoca stokastik gradyan inişini açıklayan Vikipedi sayfasını açtı. Sayfada problem, $Q_i(w)$ $i$. örnekteki kayıp olmak üzere $Q(w) = \frac{1}{n}\sum_i Q_i(w)$ toplamının en aza indirilmesi olarak yazılmıştı. Standart (toplu, batch) gradyan inişinin iterasyonu şudur (ekrandan, 02:35:00):

$$w := w - \eta \nabla Q(w) = w - \frac{\eta}{n}\sum_{i=1}^{n} \nabla Q_i(w)$$

Burada $\eta$ adım büyüklüğüdür; makine öğrenmesinde öğrenme oranı (learning rate) da denir. Hoca $\alpha$ yerine $\eta$ kullanıldığını, sonuçta bunun bir katsayı olduğunu söyledi.

Hoca öğrencilere gradyan inişi ile stokastik gradyan inişinin farkını sordu.

**Soru (hocanın sorusu):** Gradyan inişi ile stokastik gradyan inişinin farkı nedir? **Cevap:** Bir öğrenci önce slayttaki örnekte öğrenme oranının sabit alınıp iterasyon sayısına bölündüğünü, iterasyon arttıkça katsayının düştüğünü söyledi. Hoca bir de toplu verinin kullanılıp kullanılmamasının fark olabileceğini düşündü: 1000 örneğin hepsinin hatası yerine 15 örneğin hatasıyla bir düzeltme, sonra başka 15 örnekle bir düzeltme daha yapılıyor olabilir. Başka bir öğrenci de makine öğrenmesi dersinden hatırladığını söyleyerek üç türü saydı: her örnekten sonra hesaplanan stokastik gradyan inişi, bütün örneklerin sonucunda hesaplanan toplu gradyan inişi ve örneklerin onar onar ya da biner biner gruplara bölündüğü mini-toplu gradyan inişi. Yani ad, hatanın hesabında kullanılan örnek sayısına göre değişir.

Hoca bunu internette doğruladı. Okuduğu kaynağa göre:

- Gradyan inişi ya da toplu gradyan inişinde her epoch'ta bütün eğitim verisi kullanılır.
- Stokastik gradyan inişinde tek bir eğitim örneği kullanılır.
- Mini-toplu gradyan inişi bu iki uç arasındadır; eğitim verisinin bir mini-topluluğu kullanılır. Mini-toplu boyutu için pratik kural 32, 64 gibi 2'nin kuvvetleridir.

Epoch, verinin üzerinden bir kez geçmektir; aynı veri eğitime tekrar tekrar sokulur ve her geçişe bir epoch denir. Sonuçta formül aynı gradyan inişi formülüdür; güncellemenin kaç gözlemde bir yapıldığına göre ad değişir.

> **Ders sonrası not:** Hocanın okuduğu kaynakta stokastik gradyan inişi için "epoch başına tek örnek" deniyordu. Doğrusu, stokastik gradyan inişinde her güncelleme (iterasyon) tek bir örnekle yapılır; bir epoch boyunca bütün örnekler sırayla kullanılır, yani bir epoch'ta $P$ güncelleme olur. Mini-toplu yöntemde de her güncelleme bir mini-toplulukla yapılır.

Hoca bu konu için Stanford'un CS231n ders notlarına bakılmasını önerdi ve bunun çok güzel bir ders olduğunu söyledi.

### 11.4 Türevin önemi

Temel sonuç şudur: türev gereklidir. Toplam kaybın her bir parametreye, yani her $W$'nin ve her $b$'nin her bileşenine göre türevi lazımdır; bir parametre değiştirilmek isteniyorsa ona göre türev bilinmelidir. Slayttaki soru şuydu: Parametrelerin karmaşık bir fonksiyonu nasıl en aza indirilir? Cevap: Zincir kuralı, diğer adıyla geri yayılım (backpropagation). Bu, çok katmanlı bir sinir ağında kaybın parametrelere göre gradyanlarını hesaplama yöntemidir (ekrandan, 02:30:00).

Basit fonksiyonlardan oluşan karmaşık bir fonksiyonun türevi, basit fonksiyonların türevlerinden yararlanılarak elde edilir. Eğitim şöyle yapılır: türevler geri yayılımla bulunur, sonra stokastik gradyan inişi ya da Adam gibi onun çeşitli versiyonlarıyla parametreler güncellenir. Bu yöntemlerin hemen hepsinde türev gerekir ve türev geri yayılımla alınır.

## 12. Geri Yayılım

### 12.1 Softmax girdisine göre türev

"Derivative w.r.t. Input of Softmax" slaytında softmax ve kayıp birlikte yazılmıştı (ekrandan, 02:45:00):

$$p(c_k = 1 \mid x) = \frac{e^{o_k}}{\sum_j e^{o_j}}, \qquad L(x, y; \theta) = -\sum_j y_j \log p(c_j \mid x), \qquad y = [0\ 0 \ldots 0\ 1\ 0 \ldots 0]$$

Birinci formül ikincisinde yerine konup $o$'ya göre türev alınınca şu bulunur:

$$\frac{\partial L}{\partial o} = p(c \mid x) - y$$

Hoca bunun bir vektör olması gerektiğini açıkladı: $L$ bir skaler, $o$ bir vektördür ve skalerin vektöre göre türevi yine bir vektördür; her vektör bileşenine göre ayrı türev alınır.

Bu sonuç python'da sayısal türevle de denetlendi: bileşen bazında $\partial L/\partial o_k = p_k - y_k$ olur; doğru sınıf için bu değer $p_k - 1 < 0$, diğer sınıflar için $p_k > 0$ çıkar (ara adım eklendi).

### 12.2 Son katmanın ağırlıklarına göre türev ve Jacobian

Sonra $W^3$'e göre türev gerekir ki $W^3$ güncellenebilsin. Kaybın $W^3$'ün her bir elemanına göre türevi lazımdır; $W^3$ örneğin $200 \times 200$ ise 40 bin eleman vardır ve her biri için türev gerekir. Bu türev zincir kuralıyla alınır (ekrandan, 02:50:00):

$$\frac{\partial L}{\partial W^3} = \frac{\partial L}{\partial o}\frac{\partial o}{\partial W^3}, \qquad \frac{\partial L}{\partial h^2} = \frac{\partial L}{\partial o}\frac{\partial o}{\partial h^2}$$

Slayta göre bu, $\partial L/\partial o$ verildiğinde ve her modülün Jacobian'ı kolayca hesaplanabildiğinde geçerlidir. $\partial L/\partial o$ bir önceki adımda bulunmuştu. $\partial o/\partial W^3$'te $o$ bir vektördür, $W^3$ de bir vektör gibi düşünülebilir; vektörün vektöre göre türevi bir matristir. Bu matrisin bir satırı, örneğin $o_1$'in $W^3$'ün bütün elemanlarına göre türevlerinden oluşur. Hoca satır ve sütunların hangi sırayla dizileceğini o an hatırlamadığını, bunun dikkatle ayarlanması gerektiğini söyledi. Türevlerden oluşan bu matrise Jacobian denir. Bir vektör bir matrisle çarpılınca yine bir vektör elde edilir: kaybın bütün $W^3$ elemanlarına göre türevleri.

Türevler ilgili noktadaki değerler yerine konunca analitik ifadeler elde edilir. Böylece her iterasyonda bu formüller kullanılarak türevler doğrudan hesaplanabilir. Hesap geriye doğru ilerlediği için buna geri yayılım (backward propagation) denir.

### 12.3 Daha geriye

Bir sonraki adımda $W^2$'ye göre türev gerekir. Burada $h^2$'ye göre türevin elde olması işe yarar (ekrandan, 02:55:00):

$$\frac{\partial L}{\partial W^2} = \frac{\partial L}{\partial h^2}\frac{\partial h^2}{\partial W^2}, \qquad \frac{\partial L}{\partial h^1} = \frac{\partial L}{\partial h^2}\frac{\partial h^2}{\partial h^1}$$

Önceki adımda bulunan $\partial L/\partial h^2$ doğrudan kullanılır; bu yüzden ara türevler bir kenarda tutulmalı ya da formüllere dönüştürülüp saklanmalıdır. En son $W^1$'e göre türev gerekir; bunun için de $\partial L/\partial h^1$ ve $\partial h^1/\partial W^1$ kullanılır. Böylece bütün parametreler için, yani $W^1$, $W^2$, $W^3$'ün bütün elemanları ve (istenirse $W$'ye katılarak) bütün $b$'ler için türev ifadeleri elde edilir. Geriye bu türevleri kullanarak gradyan inişiyle bütün parametreleri güncellemek kalır.

> **Ek bilgi (derste anlatılmadı):** ReLU'lu bir katmanda $h = \max(0, z)$, $z = Wx + b$ için zincir kuralı somut olarak $\partial L/\partial z = (\partial L/\partial h) \odot \mathbb{1}[z > 0]$, $\partial L/\partial W = (\partial L/\partial z)\, x^T$, $\partial L/\partial b = \partial L/\partial z$ ve $\partial L/\partial x = W^T (\partial L/\partial z)$ biçimini alır. Burada $\odot$ eleman bazında çarpımdır ve $\mathbb{1}[z>0]$ ReLU türevidir (Bölüm 7.2).

### 12.4 Son slaytlar

Slaytların son kısmından hoca şunları aktardı:

- Geri yayılım yalnız ReLU ile mi çalışır? Hayır. Başka aktivasyon fonksiyonları kullanılabilir, ama türev ifadeleri ve onlardan elde edilen formüller ona göre değişir.
- Geri yayılımın hesaplama maliyeti, ileri hesaplamanın yaklaşık iki katıdır.
- İleri yayılım ve geri yayılım birbirinin ikilisidir (dual). İleri yayılımda bilgi girdiden çıktıya doğru yayılır; geri yayılımda ise en sondan geriye doğru gradyanlar, yani hatalar yayılır.
- Stokastik gradyan inişine bazen 0,9 gibi bir momentum katsayısı eklenir. Daha birçok varyant vardır, ama temel mantık gradyan inişinden gelir.
- Newton yöntemi gibi başka optimizasyon algoritmalarının kullanımı da araştırılmaktadır. Hocanın gördüğü kadarıyla en iyi ve en hızlı sonucu genelde gradyan inişinin çeşitli değişiklikleri vermektedir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00; hocanın sınavda sorduğu tür): $\{A\}$ ve $\{B\}$ kümelerinde $n$ eşleşmiş nokta veriliyor ve dönüşümün yalnız öteleme olduğu varsayılıyor: $x_i^B = x_i^A + t_x$, $y_i^B = y_i^A + t_y$. Problemi $Ax=b$ biçiminde yazın ve en küçük kareler çözümünü bulun.

Derste verilen çözüm: $A$, her nokta için $\begin{bmatrix}1&0\\0&1\end{bmatrix}$ bloklarından oluşan $2n \times 2$ matris; $x = [t_x, t_y]^T$; $b$, $x_i^B - x_i^A$ ve $y_i^B - y_i^A$ farklarının vektörü. Çözüm $x = (A^TA)^{-1}A^Tb$.

> **Çözüm (derste verilmedi):** $A^TA = nI_2$ ve $A^Tb = \left[\sum_i (x_i^B - x_i^A),\ \sum_i (y_i^B - y_i^A)\right]^T$ olduğundan $t_x = \frac{1}{n}\sum_i (x_i^B - x_i^A)$ ve $t_y = \frac{1}{n}\sum_i (y_i^B - y_i^A)$ bulunur. Bu, python'da rastgele 5 noktalı bir örnekte sözde ters çözümüyle karşılaştırılarak denetlendi.

**Soru 2** (derste sözlü, 00:23:40): RANSAC ile öteleme bulunurken her denemede en az kaç nokta seçilmelidir?

Cevap (derste verildi): Bir nokta. Tek eşleşme $t_x$ ve $t_y$ için iki denklem verir.

**Soru 3** (ekrandan, 00:20:00): Hizalama yapmak istiyorsunuz ama önceden eşleşmiş nokta çiftleriniz yok. Ne olur?

Cevap (slaytta): Hough dönüşümü ve RANSAC uygulanamaz. Tıbbi görüntülemede beyin taramalarını ya da konturları eşleme ve robotikte nokta bulutlarını eşleme bu durumun önemli uygulamalarıdır.

> **Çözüm (derste verilmedi):** Bu durumda genelde yinelemeli en yakın nokta (Iterative Closest Point, ICP) gibi yöntemler kullanılır: bir başlangıç dönüşümü tahmin edilir, her noktaya diğer kümedeki en yakın nokta eşlenir, bu geçici eşleşmelerle dönüşüm en küçük karelerle yeniden hesaplanır ve yakınsayana kadar tekrarlanır.

**Soru 4** (ekrandan, 01:10:00): $(0,0) \to 0$, $(1,0) \to 1$, $(0,1) \to 1$, $(1,1) \to 0$ verisi tek bir doğruyla ayrılabilir mi? Bu, sinir ağı tasarımı için ne anlama gelir?

Cevap (derste verildi): Hayır. Hangi doğru çizilirse çizilsin en az bir nokta yanlış tarafta kalır. Doğrusal katmanların bileşkesi yine doğrusal olduğundan, böyle bir veriyi ayırmak için katmanlar arasına doğrusal olmayan bir aktivasyon konmalıdır.

**Soru 5** (derste sözlü, 01:13:31): ReLU $f(x) = \max(0,x)$'in türevi nedir?

Cevap (derste verildi): $x < 0$ için 0, $x > 0$ için 1 (ekrandan, 01:20:00).

**Soru 6** (derste sözlü, 01:23:42): $x \in \mathbb{R}^D$ ve $W^1 \in \mathbb{R}^{N_1 \times D}$ ise $b^1$ kaç elemanlı olmalıdır?

Cevap (derste verildi): $W^1x$ çarpımının sonucuyla toplanabilmesi için $b^1 \in \mathbb{R}^{N_1}$, yani $N_1$ elemanlı olmalıdır.

**Soru 7** (ekrandan, 01:35:00): Katmanlar arasındaki eşleme neden doğrusal olamaz? ReLU katmanları ne sağlar?

Cevap (slaytta): Doğrusal fonksiyonların bileşkesi doğrusaldır; ağ tek katmanlı lojistik regresyona indirgenirdi. ReLU katmanları parça parça doğrusal bir döşeme sağlar; eşleme yerel olarak doğrusaldır.

**Soru 8** (ekrandan, 01:45:00): Bir gizli birim ne yapar? Kaç katman ve kaç gizli birim kullanılmalıdır? Ağırlık matrisleri nasıl belirlenir?

Cevap (slaytta): Gizli birim bir sınıflayıcı ya da öznitelik bulucu olarak düşünülebilir. Katman ve birim sayısını çapraz doğrulama ya da hiperparametre arama yöntemleri belirler; ağ ne kadar geniş ve derinse eşleme o kadar karmaşık olur. Ağırlıklar ve biaslar öğrenilir: önce eşlemenin kalitesini ölçen bir ölçü, sonra parametreleri ayarlayan bir yöntem tanımlanır.

**Soru 9** (derste sözlü, 02:21:26): Negatif log-olabilirlik kaybında doğru sınıfa verilen olasılık 0,9 ve 0,1 iken kayıp nasıl değişir?

Cevap (derste verildi): 0,9'da kayıp küçük pozitif, 0,1'de büyük pozitif olur; olasılık küçüldükçe hata büyür.

> **Çözüm (derste verilmedi):** Doğal logaritmayla $-\ln 0{,}9 \approx 0{,}105$ ve $-\ln 0{,}1 \approx 2{,}303$ (python ile hesaplandı). Kayıp yaklaşık 22 kat büyür.

**Soru 10** (derste sözlü, 02:34:21): Gradyan inişi ile stokastik gradyan inişinin farkı nedir?

Cevap (derste verildi): Formül aynıdır; fark, bir güncellemede kullanılan örnek sayısıdır. Toplu gradyan inişi bütün eğitim verisini, stokastik gradyan inişi tek bir örneği, mini-toplu gradyan inişi ise bir mini-topluluğu (genelde 32, 64 gibi 2'nin kuvvetleri) kullanır.

**Soru 11** (ekrandan, 02:30:00): Parametrelerin karmaşık bir fonksiyonu nasıl en aza indirilir?

Cevap (slaytta): Zincir kuralı, diğer adıyla geri yayılım. Bu, çok katmanlı bir sinir ağında kaybın parametrelere göre gradyanlarını hesaplama yöntemidir; gradyanlar sonra gradyan inişiyle kullanılır.

## Dersin Toparlaması

Dersin ilk kısmında dönüşüm uydurma konusu öteleme örneğiyle kapatıldı. Eşleşmiş noktalardan gelen fazla sayıda denklem $Ax=b$ biçiminde yazıldı ve $A$ kare olmadığı için sözde tersle, $x = (A^TA)^{-1}A^Tb$ ile çözüldü. Aykırı eşleşmelere karşı Hough dönüşümü (parametre uzayında oylama) ve RANSAC (en az örnekle model kurup iç noktaları sayma) gösterildi; eşleşmiş çift olmadığında bu iki yöntemin uygulanamadığı belirtildi.

İkinci kısımda derin öğrenmeye giriş yapıldı. Gözetimli öğrenme tanımlandı. Sinir ağı, doğrusal katmanların ve ReLU gibi doğrusal olmayan aktivasyonların art arda bileşimi olarak kuruldu; boyutlar, bias ve tam bağlı katman açıklandı. XOR örneği doğrusal olmayan aktivasyonun gerekliliğini gösterdi. Derinliğin hiyerarşik özniteliklerle yorumu, model seçimi için doğrulama kümesi, softmax ve negatif log-olabilirlik kaybı, kaybın $\theta$'ya göre en aza indirilmesi, toplu, stokastik ve mini-toplu gradyan inişi ve son olarak $\partial L/\partial o = p - y$ ile başlayan geri yayılım işlendi. Hoca bir sonraki derste evrişimli sinir ağlarına (CNN), sonra da GAN'lar gibi başka sinir ağı türlerine bakılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
