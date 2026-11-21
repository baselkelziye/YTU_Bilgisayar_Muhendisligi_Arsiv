# Ders 11 Genişletilmiş Notu: Konvolüsyonel Ağlarda Korelasyon ve Konvolüsyon İşlemi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. CNN katmanlarının tekrarı
- 2. CNN'in temel dezavantajı: etiketli veri
- 3. Korelasyon ve konvolüsyon: tanımlar
- 4. Sürekli tek boyutlu konvolüsyon ve parçalı fonksiyon örneği
- 5. Impuls fonksiyonu ile konvolüsyon
- 6. Frekans domeni ve konvolüsyon teoremi
- 7. Ayrık konvolüsyon, boyutlar ve sıfırla doldurma
- 8. İki boyutlu konvolüsyon ve doğrusallık
- 9. Görüntüde korelasyon: ortalama filtresi örneği
- 10. Kosinüs benzerliği ve korelasyonun anlamı
- 11. Görüntüde konvolüsyon: maskeyi döndürmek
- 12. Ayrılabilir filtreler ve işlem karmaşıklığı
- 13. Filtre seçimi: kararı kim veriyor?
- 14. Klasik sinir ağı ile CNN ve CIFAR-10 örnek mimarisi
- 15. ReLU'nun sorunları: ölen nöronlar, Leaky ReLU ve Maxout
- 16. Görüntü dışı verilerde CNN
- Örnek Sorular
- Dersin Toparlaması

## 1. CNN Katmanlarının Tekrarı

Önceki derste mevcut derin öğrenme yöntemlerine yüzeysel bir giriş yapılmıştı. Bu derste konvolüsyonel ağlara (CNN), özellikle de konvolüsyon işleminin kendisine daha ayrıntılı bakılır. Rekürent ağlar ve düzenlileştirme (regülerizasyon) sonraki derslere bırakılmıştır.

### 1.1 Konvolüsyon katmanı

Konvolüsyonel ağlarda farklı türde katmanlar vardır; en önemlisi konvolüsyon katmanıdır. Bu katmanda istenen sayıda, farklı özellikli filtre bulunur. Filtrelerin uygulanması konvolüsyon işlemiyle yapıldığı için katmanın adı da buradan gelir.

Çok katmanlı perceptron ya da tam bağlı ağlardan farkı şudur: filtreler istenen sayıda ve girdinin istenen bölgesine yansıyacak biçimde uygulanır. Filtre, verinin filtre boyutu kadar bir bölgesine karşılık gelir. Veri bir görüntüyse, görüntünün belli bir kısmına aynı filtreler tekrar tekrar uygulanır. Konvolüsyon ağlarını uygularken adım (stride) parametresi, filtre boyutu, filtre tipi gibi tanımlar da ortaya çıkar, ama temel mantık budur.

Birden fazla farklı filtre uygulanabilir. Görüntüde ya da veride belirlenmek istenen özellikler kaç çeşitse o kadar çeşit filtre, dolayısıyla o kadar konvolüsyon katmanı kullanılabilir. Slaytta bu fikir "el feneri" benzetmesiyle gösterilir: birden fazla filtrenin fenerleri aynı noktalara paralel olarak ışık tutar ve aynı anda farklı desenler aranır. Slayttaki örnekte her biri farklı bir desen arayan 4 filtre vardır ve bu konvolüsyon katmanı $8 \times 6 \times 4$ boyutlu üç boyutlu bir fener ızgarasıdır. Katmanın ağırlıkları ve biasları konvolüsyon işleminin nasıl yapılacağını belirler (ekrandan, 00:10:00).

Şekilde dört farklı filtre (dört konvolüsyon işlemi) vardır ve bu düğümler görüntüde belli sayıda düğüme bağlıdır. Aynı yapı birebir görüntünün başka bir bölgesine yansıtılır. Slayta göre belirli bir filtredeki nöronlar aynı ağırlık ve bias parametrelerini paylaşır; filtre nerede olursa olsun bir nöron aynı sayıda girdi nöronuna bağlıdır ve aynı ağırlıklara sahiptir. Bu, filtrenin aynı deseni görüntünün farklı kısımlarında aramasını sağlar; nöronların fener ızgarası düzeninde yerleştirilmesi bütün görüntünün taranmasını garanti eder (ekrandan, 00:15:00).

Mimaride dikkat edilmesi gereken tek nokta, mümkünse bölgeler arasında kesişim olmasıdır. Şekildeki üçüncü girdi düğümü hem birinci hem ikinci konvolüsyon işlemine bağlıdır; bölgeler bu şekilde örtüşecek biçimde dağıtılır.

### 1.2 ReLU katmanı

Konvolüsyonun ardından ReLU (Rectified Linear Unit) katmanı gelir. ReLU, sinir ağlarındaki aktivasyon fonksiyonunun yerini alır. Öğrenme yine geri yayılımla yapılır ve ReLU, geri yayılım sırasında gradyanın kaybolması problemini aşmaya yardımcı olduğu için konvolüsyon ağlarında varsayılan fonksiyondur. Konvolüsyon görüntünün belli bölgeleriyle sınırlı olduğundan ReLU da her konvolüsyon katmanı için, o konvolüsyonun bağlı olduğu düğümlere etki edecek biçimde uygulanır; her konvolüsyon katmanının boyutu kadar ReLU işlemi vardır.

Hoca ReLU'yu nöron girdisinin aynen yansıtıldığı doğrusal bir fonksiyon olarak tanıttı. ReLU'nun "sızması" diye bir kavram (Leaky ReLU) ve bunu yönetmek için ek mekanizmalar da vardır; uygulamada burada sayılanlardan daha fazla çeşit görülecektir. Standartta en azından bir ReLU katmanı bulunmalıdır.

> **Ders sonrası not:** Hoca ReLU'nun "belli bir maksimum noktayla sınırlandığını" ve "üst ve alt sınırlarının belirlenmesi gerektiğini" söyledi. Standart ReLU $\max(0, x)$'tir ve üstten sınırlı değildir; dersin ilerisindeki slayt da onu böyle verir (ekrandan, 01:50:00). Üstten sınırlı olanlar büyük olasılıkla ReLU6 gibi türevlerdir.

### 1.3 Pooling katmanı

Pooling katmanı boyut küçültme için kullanılır. Buradaki varsayım şudur: bu kadar konvolüsyon uygulandıktan sonra neyin önemli olduğu ortaya çıkmıştır. Örneğin dört nöronun özeti, yani en ağır basan özelliği, tek bir nöronla ifade edilebilir. Bunu yapmanın nedeni işlem yükünü azaltmaktır: geri yayılım sırasındaki toplamalar, çarpmalar, geri dönüp gradyan hesaplama ve ağırlık ayarlama işlemleri azalır.

### 1.4 Tam bağlı katman ve genel mimari

En sonda, pooling katmanından sonra bir tam bağlı (fully connected) katman oluşturulur. Bu katman tamamen çıktıların etiketlenmesi içindir. Pooling'den sonra bir takım özellikler çıkmıştır; bunlara bakarak girdiye nasıl bir etiket atanacağına ya da kaç sınıfa ayrılacağına karar verilir. Çıktı katmanında sınıf sayısı kadar nöron bulunur ve pooling'den sonraki bağlantılar bütün çıktı nöronlarına tam bağlıdır. Slayta göre bu üç katman birlikte bir dizi karmaşık deseni keşfedebilir ama ağ bu desenlerin ne anlama geldiğini bilmez; tam bağlı katman ağa veri örneklerini sınıflama yeteneği kazandırmak için eklenir (ekrandan, 00:20:00).

Genel görünüş şöyledir: istenen sayıda konvolüsyon, ReLU ve pooling katmanı kullanılabilir. Kesin olan, konvolüsyondan sonra ReLU ve pooling uygulanması ve en sonda bir tam bağlı katman bulunmasıdır.

## 2. CNN'in Temel Dezavantajı: Etiketli Veri

CNN'in en önemli dezavantajı gözetimli (supervised) öğrenme gerektirmesidir. Bu da çok sayıda etiketli veri bulma problemini getirir ve uygulamada en çok zorlayan nokta budur.

> **Hocanın vurgusu:** Problem her ne ise, derin ağla, özellikle CNN ya da CNN'in türevleriyle çözülecekse elde çok sayıda etiketli veri olduğundan emin olunmalıdır. Aksi halde CNN ile çözülebilecek bir problem bile başarılı biçimde çözülemeyebilir.

## 3. Korelasyon ve Konvolüsyon: Tanımlar

Konvolüsyona yakından bakmadan önce korelasyon tanımlanır, çünkü ikisi birbiriyle çok yakından ilişkilidir.

### 3.1 Korelasyon

Korelasyon, iki fonksiyonun ya da ayrık düşünülürse belli boyuttaki iki matrisin noktasal çarpımıyla tanımlanan bir işlemdir ve sonunda tek bir sayı elde edilir. Birden fazla boyutu olan iki matris noktasal olarak çarpılır: görüntünün bir hücresine denk gelen eleman, filtrenin aynı indisli elemanıyla çarpılır. Sırayla bütün karşılıklı aynı indisli hücreler çarpılır, sonra sonuçlar toplanarak tek bir sayıya indirilir. Bu klasik matris çarpımı değildir; yalnız aynı indislere sahip gözler çarpılır.

### 3.2 Konvolüsyon

Konvolüsyon korelasyonla aynı işlemdir; tek fark, maske ya da kernel matrisi denen matrisin hem yatay hem dikey olarak döndürülüp (flip) o şekilde çarpılmasıdır. Korelasyon nokta ile, konvolüsyon yıldız ($*$) ile gösterilir. Slayttaki tanım (ekrandan, 00:25:00):

$$g(x,y) = w(x,y) * f(x,y) = \sum_{s=-K/2}^{K/2} \sum_{t=-K/2}^{K/2} w(s,t)\, f(x-s,\, y-t)$$

### 3.3 Simetrik maskede konvolüsyon = korelasyon

$w(x,y)$ simetrik bir fonksiyonsa, yani $w(x,y) = w(-x,-y)$ ise (değişkenlerin pozitifi de negatifi de aynı sonucu veriyorsa), denklemin sağ tarafı korelasyonla aynı çıkar. Nedeni şudur: $s$ yerine $-s$, $t$ yerine $-t$ yazıldığında $f(x-s, y-t)$ terimi $f(x+s, y+t)$'ye dönüşür, $w$ ise simetri yüzünden değişmez; bu da birebir korelasyon ifadesidir. Hoca bunun başka durumlarda da işe yarayabilecek bir ilişki olduğunu not etti.

### 3.4 Sürekli fonksiyonlarda domen değiştirme

Ayrık durumlarda konvolüsyon matris işlemlerine dönüştüğü için zor değildir. Sürekli fonksiyonlarda ise daha karmaşık olabilir. Bu yüzden zaman domeninden S domenine ya da başka bir domene geçilir; amaç karmaşık çarpımları kolaylaştırmaktır. Fourier dönüşümü de benzer biçimde konvolüsyonlara ve noktasal çarpımlara dayanır; ayrık olarak yapıldığında kolaydır ama sürekli fonksiyonlarda domen değiştirmek gerekir.

## 4. Sürekli Tek Boyutlu Konvolüsyon ve Parçalı Fonksiyon Örneği

### 4.1 Tanım ve yer değiştirme özelliği

Konvolüsyonun boyutu, kullanılan fonksiyonların boyutuna göre belirlenir. Yalnız $x$'e bağlı, sürekli $f$ ve $g$ fonksiyonlarının konvolüsyonu şöyle tanımlanır: bir $a$ noktasında $f$'nin aldığı değer ile $g$'nin ötelenmiş hali $g(x-a)$ çarpılır ve integral alınır:

$$f(x) * g(x) = \int_{-\infty}^{\infty} f(a)\, g(x-a)\, da$$

Yani bu çarpımın altında kalan alan hesaplanır. Konvolüsyonun yer değiştirme (komütatiflik) özelliği vardır: $f * g = g * f$. Yani hangisinin filtre, hangisinin ana veri ya da resim olduğu sonucu değiştirmez.

### 4.2 Görsel sezgi

İki fonksiyonun konvolüsyonunu almak, birini diğerinin üzerinden her noktada geçirip çarpımlarının altındaki alanı hesaplamak demektir. Slayttaki animasyonda iki eşit kare fonksiyon (her biri $-0.5$ ile $0.5$ arasında 1) kullanılır: biri diğerinin üzerinde kaydırılır, noktasal çarpılır, alan hesaplanır ve sonuç olarak tepesi $0$'da, değeri $1$ olan, $-1$ ile $1$ arasında uzanan bir üçgen oluşur (ekrandan, 00:30:00). CNN uygulamalarında çoğunlukla ayrık versiyon karşımıza çıkar, ama konvolüsyon işleminin anlamı budur.

Bu işlem ne yapar? Oluşan üçgen iki fonksiyonun tepe noktasını belirginleştirmiştir. Farklı boyutlarda ve farklı biçimlerde fonksiyonlar çarpılsaydı farklı yönleri belirginleşirdi. Görüntüye uygulanan fonksiyonlar kenar belirleme, kontrast yaratma gibi etkilere sahiptir. Elektrik ve elektronikte çok farklı amaçlarla kullanılan konvolüsyon, bilgisayar mühendisliğinde filtreler ve özellik ortaya çıkarma açısından önem kazanır; ana çıkış yeri diğer mühendislik alanlarıdır.

### 4.3 Parçalı fonksiyon olarak hesaplama

Örnekte $f(a)$, $[0,1]$ aralığında 1; $g(a)$, $[0,1]$ aralığında $1/2$ olan iki basamak (kare) fonksiyondur. Her ikisinin de $x$ eksenindeki genişliği bir birimdir. Önce $g$'nin ötelenmiş hali $g(x-a)$ oluşturulur, sonra $f(a)$ ile örtüştükleri yerde çarpılır. $f$ yalnız pozitif tarafta tanımlıyken $g(x-a)$'nın negatif tarafa düşen bir kısmı vardır; orada $f$ sıfır olduğundan çarpımın bir etkisi olmaz. Dolayısıyla $x$'in değerine göre birkaç durum çıkar:

- **Durum 1, $x < 0$:** fonksiyonlar arasında örtüşme yoktur. Her noktada sıfırla çarpıldığı için integral 0'dır.
- **Durum 2, $0 \le x \le 1$:** taralı alan $0$'dan $x$'e kadardır: $\int_0^x 1 \cdot \tfrac12\, da = \tfrac{x}{2}$.
- **Durum 3, $1 \le x \le 2$:** örtüşme $x-1$'den $1$'e kadardır (ekrandan, 00:35:00):

$$\int_{-\infty}^{\infty} f(a)\, g(x-a)\, da = \int_{x-1}^{1} 1 \cdot \frac12\, da = 1 - \frac{x}{2}$$

- **Durum 4, $x > 2$:** iki fonksiyon artık kesişmez, sonuç yine 0'dır.

Sonuç üç parçalı yazılır:

$$f(x) * g(x) = \begin{cases} x/2, & 0 \le x \le 1 \\ 1 - x/2, & 1 \le x \le 2 \\ 0, & \text{diğer yerlerde} \end{cases}$$

Küçük artımlarla değer verip çizdirilirse animasyondaki üçgen elde edilir (tepe değeri $x=1$'de $1/2$). Değerler python ile sayısal konvolüsyonla kontrol edildi: $x = 0.25$ için $0.125$, $x = 0.5$ için $0.25$, $x = 1$ için $0.5$, $x = 1.5$ için $0.25$.

### 4.4 Sonucun genişliği ve integral sınırları

Konvolüsyon sonucunun genişliği, $f$'nin genişliği ile $g$'nin genişliğinin toplamıdır. Örnekte her ikisi de bir birim olduğu için sonuç iki birim genişliğindedir. Bu tespit integral sınırlarını belirlerken de kullanılır: alt sınır olarak $f(x)$'in en sol değeri ile $g(x-a)$'nın en sol değerinin büyüğü, üst sınır olarak sağ uçlarının küçüğü seçilir. Örnekte bu sınırlar 0 ve 2'dir.

### 4.5 Kare fonksiyon ile testere fonksiyonu

Kare fonksiyonun bir yarım testere fonksiyonuyla konvolüsyonu alındığında, genliği daha düşük ama tam bir testere biçimine benzeyen bir fonksiyon elde edilir. Sayısal olarak hesaplanacaksa bu sonuç da parçalı fonksiyon olarak tanımlanabilir.

## 5. Impuls Fonksiyonu ile Konvolüsyon

Impuls fonksiyonu yalnız tek bir noktada değer alan fonksiyondur. Bir fonksiyonun impulsla konvolüsyonunda, impulsun nerede olduğuna bağlı olarak fonksiyonun yeri değişir ama şekli hiç değişmez. Bu yüzden impuls, konvolüsyonda etkisiz eleman gibi düşünülebilir.

Hoca ardından sınıfa, $[0,t]$ aralığında 1 olan bir kare fonksiyonun $-T$, $0$ ve $T$ noktalarındaki üç impulsla ("impuls treni") konvolüsyonunun neye benzeyeceğini sordu (ekrandan, 00:40:00). Öğrencilerden biri yalnız sağdaki iki atmanın görüneceğini düşündü, bir başkası kare çıkacağını önerdi; sonunda cevap üç ayrı kopya olarak netleşti.

**Soru:** Soldaki ($-T$'deki) impuls sönümlenmez mi?
**Cevap:** Sönümlenmez. Konvolüsyonda kaydırma yapıldığı için kare fonksiyon soldaki impulsun da üzerinden geçer; sonuçta kare fonksiyon üç impulsun bulunduğu yerlere ötelenir ve üç kopya oluşur. Bir $T$ kadar kaydırıp sayısal olarak bakıldığında bu görülür.

## 6. Frekans Domeni ve Konvolüsyon Teoremi

Konvolüsyon frekans domeninde yapılırsa iş kolaylaşır. Uzamsal ya da zaman domeninde, hele sürekli fonksiyonlarda integral gibi karmaşık bir işlem gerektiren konvolüsyon, fonksiyonlar frekans domenine çevrilince çarpmaya eşdeğer olur. Fourier dönüşümünde de aynı şey yapılır. Frekans domenindeki çarpımdan sonra sonucun tekrar uzamsal ya da zaman domenine çevrilmesi unutulmamalıdır.

Tersi de doğrudur: uzamsal ya da zaman domenindeki çarpma, frekans domeninde daha karmaşık olan konvolüsyona karşılık gelir. Dolayısıyla eldeki işlemin karmaşıklığına göre domen değiştirmek mantıklı bir yaklaşımdır.

$f$ ile $g$'nin konvolüsyonunu hesaplama adımları:

1. Her iki fonksiyon frekans domenine çevrilir: $F(u)$ ve $G(u)$.
2. Frekans domeninde çarpılır: $F(u)\,G(u)$.
3. Çarpımın ters dönüşümü alınarak uzamsal ya da zaman domenine dönülür; bu, konvolüsyonun sonucudur.

## 7. Ayrık Konvolüsyon, Boyutlar ve Sıfırla Doldurma

### 7.1 Ayrık tanım

Ayrık konvolüsyonda söylenen her şey geçerlidir; yalnız integralin yerini toplam alır. Slayta göre integral değişkeni bir indise dönüşür ve kaydırmalar ayrık adımlarla yapılır (ekrandan, 00:45:00):

$$f(x) * g(x) = \sum_{m=-\infty}^{\infty} f(m)\, g(x-m), \qquad -\infty < x < \infty$$

Burada fonksiyonlar matris (dizi) biçimindedir; matrisler nokta nokta çarpılıp toplanır ve skaler bir değer elde edilir. Sürekli fonksiyondan belli sayıda örnek alınır; fonksiyonun tamamını her noktada ifade etmeden, örnekler üzerinden çarpım yapılır ve sonuç da ayrık olarak ifade edilir.

### 7.2 Sonucun boyutu

Sürekli durumdaki gibi, $f$ ile $g$'nin konvolüsyonunun genişliği $f$'nin genişliği ile kaydırılan $g$'nin genişliğinin toplamıdır. Hoca şekildeki örnekte 8 nokta saydı ve "5 artı 3, 8" dedi.

<!-- BELİRSİZ: 00:46:19 civarındaki şeklin karesi yok. Ayrık örnek sayısı formülüne göre 5 ve 3 örnekli iki dizinin konvolüsyonu 5+3-1=7 örnek verir; hocanın saydığı 8'in sürekli genişliklerin toplamı mı yoksa nokta sayısı mı olduğu anlaşılamadı. -->

Fonksiyonlar örneklerle ifade edildiğinde: $f$'den $A$ tane örnek ($f_0, f_1, \dots, f_{A-1}$), $g$'den $B$ tane örnek alınmışsa konvolüsyon sonucunun boyutu

$$A + B - 1$$

olur. Python ile 5 ve 3 uzunluklu iki dizinin konvolüsyonunun 7 elemanlı olduğu kontrol edildi.

### 7.3 Padding

Girdi dizileri uzatılabilir. Hoca sınıfa "sıfırlarla padding" kavramını duyup duymadıklarını sordu ve kavramın uygulamada çok sık karşılaşılan bir şey olduğunu, görüntü işlemede ve kriptografide de kullanıldığını söyledi. Padding, veriyi istenen boyuta getirmek için ekstra dolgu eklemektir ve genellikle sıfırlarla yapılır. Görüntülerde ve başka verilerde boyutları istenen hale getirmek için konvolüsyonla birlikte kullanılacaktır.

### 7.4 Ayrık durumda konvolüsyon teoremi

Slayta göre ayrık dizilerde konvolüsyon teoremi yalnız uzatılmış (extended) diziler için geçerlidir (ekrandan, 00:50:00):

$$f_e(x) * g_e(x) \;\longleftrightarrow\; F_e(u)\, G_e(u), \qquad f_e(x) * g_e(x) = \sum_{m=0}^{M-1} f_e(m)\, g_e(x-m)$$

Genelde $M \ge A + B - 1$ seçilir. Sonucun boyutu seçilirken çarpım bir matrise aktarılacağı için padding uygulandığında sonucun sığmaması gibi bir durum olabilir; boyuta dikkat etmek gerekir.

> **Ders sonrası not:** Hoca matris çarpımı için "birinin satır sayısıyla diğerinin sütun sayısı eşit olmalı" dedi. $AB$ çarpımında doğrusu, $A$'nın sütun sayısının $B$'nin satır sayısına eşit olmasıdır.

### 7.5 Periyodiklik

Hoca konvolüsyonun, gerek sürekli gerek ayrık durumda, periyodik bir işlem olduğunu söyledi: aynı fonksiyon periyodik olarak tekrarlandığında çarpımların sonucu da periyodik olarak aynı çıkar (impuls örneğindeki gibi). Ayrık Fourier dönüşümü (DFT) de periyodik bir dönüşümdür. Çıktının boyutu doğru seçilmezse periyodik oluşan sonuçlar birbirinin üzerine biner ve hatalı sonuç üretilir. Boyut, iki dizinin boyutlarının toplamı eksi birden büyük ya da eşit seçilirse periyodik sonuçlar ayrı ayrı görülür.

> **Ek bilgi (derste anlatılmadı):** DFT ile hesaplanan konvolüsyon dairesel (circular) konvolüsyondur, çünkü DFT diziyi periyodik kabul eder. Diziler $A + B - 1$ uzunluğa kadar sıfırla doldurulmazsa dizinin sonundaki değerler başa sarar (wrap-around) ve doğrusal konvolüsyondan farklı bir sonuç çıkar. Slayttaki $M \ge A + B - 1$ koşulunun nedeni budur.

## 8. İki Boyutlu Konvolüsyon ve Doğrusallık

### 8.1 Tanım ve teorem

Fonksiyon iki boyutlu olunca tanım biraz değişir ama özü aynıdır. $g$ fonksiyonu yine kaydırılır, ama bu kez hem $x$ hem $y$ değişkeni için: birinde $a$, diğerinde $b$ kadar. İki değişken olduğu için çift integral alınır (ekrandan, 00:55:00):

$$f(x,y) * g(x,y) = \int_{-\infty}^{\infty}\int_{-\infty}^{\infty} f(a,b)\, g(x-a,\, y-b)\, da\, db$$

Yer değiştirme özelliği yine vardır. İki boyutlu konvolüsyon teoremi:

$$f(x,y) * g(x,y) \longleftrightarrow F(u,v)\, G(u,v), \qquad f(x,y)\, g(x,y) \longleftrightarrow F(u,v) * G(u,v)$$

### 8.2 Ayrık iki boyutlu durumda boyutlar

$f$ ve $g$ görüntü olsun: $f$ $A \times B$ boyutunda, $g$ (filtre) $C \times D$ boyutunda. Konvolüsyon sonucu $N \times M$ boyutunda olsun. Bu durumda

$$N = A + C - 1, \qquad M = B + D - 1$$

olur; tek boyutludakine benzer biçimde. Görüntüler sıfırla doldurularak büyütülmüşse sonuç boyutu ne kadar padding yapıldıysa ona göre değişir. Padding konvolüsyonun özelliklerini değiştirmez; işlem yine frekans domenine çarpma olarak taşınabilir.

### 8.3 Doğrusallık: süperpozisyon ilkesi

Korelasyon ve konvolüsyon doğrusal işlemlerdir. Doğrusal bir işlem iki özelliği sağlamalıdır; ikisine birlikte süperpozisyon ilkesi denir:

- **Toplamsallık:** $x_1 + x_2$'nin $f$ altındaki karşılığı, $x_1$ ve $x_2$'nin ayrı ayrı karşılıklarının toplamına eşittir: $f(x_1 + x_2) = f(x_1) + f(x_2)$.
- **Homojenlik:** değişken bir skalerle çarpılmışsa skaler dışarı alınabilir: $f(c\,x) = c\, f(x)$.

Hoca bu özelliklerin ileride (ayrılabilir filtrelerde) kullanılacağını, bu yüzden önemli olduğunu söyledi.

## 9. Görüntüde Korelasyon: Ortalama Filtresi Örneği

### 9.1 Görüntüde korelasyon işlemi

İki matris vardır: biri maske, kernel ya da filtre denen matris, diğeri görüntü ya da veri. Slayta göre maskenin merkezi giriş görüntüsünün her pikselini dolaştıkça filtrelenmiş görüntü oluşur (ekrandan, 01:15:00):

$$g(i,j) = \sum_{k=-n/2}^{n/2} \sum_{l=-n/2}^{n/2} h(k,l)\, f(i+k,\, j+l)$$

Birebir çarpımlar yapılır, çarpımların sonucu toplanır ("summer") ve oluşan değer ortadaki çıktı pikseline yazılır. Görüntü büyütülmek ya da küçültülmek istenirse bir ölçekleme sabiti $C$ ile de çarpılır.

### 9.2 Kenarlar: sıfırla doldurma ya da aynalama

Görüntünün kenarlarına sıfırlar eklenerek matrisin satır ya da sütun sayısı (ya da ikisi birden) artırılır. Diğer seçenek, köşelerden katlıyormuş gibi üst ve soldaki satır ve sütunları kıvırıp aynalamaktır; böylece kenardaki değerler tekrar kullanılır ve istenen boyuta gelinir. İki seçenek de vardır; sıfırla doldurma yaygın kullanılır.

### 9.3 Animasyonlu örnek

Filtre, birlerden oluşan $3\times3$ bir matristir ve $\tfrac19$ ölçekleme parametresi vardır (ekrandan, 01:20:00). Bu, birlerin yerine doğrudan $\tfrac19$ yazılarak da gösterilebilir; ikisi de uygundur.

$$h = \frac19 \begin{bmatrix} 1 & 1 & 1 \\ 1 & 1 & 1 \\ 1 & 1 & 1 \end{bmatrix}$$

Görüntü $10 \times 10$'luk bir matristir: kenarları sıfırla doldurulmuş, ortasında 90'lardan oluşan $5 \times 5$'lik bir bölge (bölgenin içinde tek bir 0 pikseli) ve sol altta tek başına bir 90 pikseli vardır. Görüntü kare hale getirilmiştir.

Filtre görüntünün üzerinde gezdirilir:

- İlk konumda filtrenin altındaki bütün hücreler 0'dır; her hücre sıfırla çarpılır, korelasyonun sonucu 0 olur.
- Filtre bir kaydırılınca altında bir tane 90 olur: $\tfrac19 \cdot 90 = 10$.
- Bir kaydırma daha: iki tane 90 vardır, çarpımlar toplanır: $10 + 10 = 20$.
- Bir daha: üç tane 90, sonuç $30$.

Bu şekilde devam edilince slayttaki $8 \times 8$'lik sonuç elde edilir:

$$\begin{bmatrix}
0 & 10 & 20 & 30 & 30 & 30 & 20 & 10 \\
0 & 20 & 40 & 60 & 60 & 60 & 40 & 20 \\
0 & 30 & 60 & 90 & 90 & 90 & 60 & 30 \\
0 & 30 & 50 & 80 & 80 & 90 & 60 & 30 \\
0 & 30 & 50 & 80 & 80 & 90 & 60 & 30 \\
0 & 20 & 30 & 50 & 50 & 60 & 40 & 20 \\
10 & 20 & 30 & 30 & 30 & 30 & 20 & 10 \\
10 & 10 & 10 & 0 & 0 & 0 & 0 & 0
\end{bmatrix}$$

Python ile slayttaki girdi matrisinden hesaplanan çıktı bununla birebir aynıdır. Ayrık korelasyon bu kadar basit bir noktasal çarpım işlemidir.

## 10. Kosinüs Benzerliği ve Korelasyonun Anlamı

### 10.1 Noktasal çarpım ve açı

Kosinüs benzerliği bu noktasal çarpımdan gelir. İki vektörün noktasal çarpımı, az önce yapıldığı gibi nokta nokta çarpıp toplamaktır ve elde edilen sonuç korelasyon değeridir. Noktasal çarpımın diğer ifadesi, vektörlerin uzunlukları ile aralarındaki açının kosinüsünün çarpımıdır:

$$x \cdot y = \sum_i x_i\, y_i = \lVert x \rVert\, \lVert y \rVert \cos\theta \quad\Longrightarrow\quad \cos\theta = \frac{x \cdot y}{\lVert x \rVert\, \lVert y \rVert}$$

Geometrik olarak bu açının büyüklüğü iki vektörün ne kadar uzak ya da yakın olduğunu gösterir; açı küçüldükçe vektörler yaklaşır ve benzerlikleri artar. Dolayısıyla korelasyon yapmak, iki vektörün arasındaki açıyla, yani birbirine yakınlığıyla ilişkilidir. Korelasyon sonuçları normalize de edilebilir; hoca bunun çok önemli olmadığını söyledi.

### 10.2 Maske ile şablon arama

Normalize edilmiş korelasyonun uygulaması şöyle düşünülebilir: elde küçük bir maske ve büyük bir görüntü vardır. Maske uygulandığında, maskenin aynısı görüntüde bir yerde varsa orada değer büyür; olmayan yerlerde pikseller uyumlu olmadığı için çarpımlar küçük kalır. Korelasyon sonucunda maskenin uyduğu noktanın merkezi daha parlak ya da keskin görünür. Bu, korelasyonun iki görüntü arasındaki benzerliği ifade ettiğini gösteren görsel bir örnektir. O nesne görüntüde hiç olmasaydı parlaklık oluşmazdı ve görüntünün maskeyle ilişkisiz olduğu söylenebilirdi.

## 11. Görüntüde Konvolüsyon: Maskeyi Döndürmek

Konvolüsyonda korelasyondan tek fark maskenin yatayda ve dikeyde döndürülmesidir. Slayttaki örnekte maske (ekrandan, 01:25:00)

$$\begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 8 & 9 \end{bmatrix} \;\longrightarrow\; \begin{bmatrix} 7 & 8 & 9 \\ 4 & 5 & 6 \\ 1 & 2 & 3 \end{bmatrix}$$

biçiminde ilk döndürmeden geçer; ikinci yöndeki döndürmeyle de $\begin{bmatrix} 9 & 8 & 7 \\ 6 & 5 & 4 \\ 3 & 2 & 1 \end{bmatrix}$ elde edilir (ara adım eklendi). Ardından korelasyondaki gibi bu döndürülmüş maske ile noktasal çarpım yapılır. Slayttaki formül:

$$g(i,j) = \sum_{k=-n/2}^{n/2} \sum_{l=-n/2}^{n/2} h(k,l)\, f(i-k,\, j-l) = \sum_{k=-n/2}^{n/2} \sum_{l=-n/2}^{n/2} h(i-k,\, j-l)\, f(k,l)$$

Simetrik maskelerde ($h(i,j) = h(-i,-j)$) konvolüsyon korelasyona eşittir ve $h * f = f * h$'dir.

> **Hocanın vurgusu:** Örneklerde maske ya önceden döndürülmüş verilir ya da bu kısım ayrıntıya girilmeden geçilip doğrudan noktasal çarpım yapılır. Maskeyi döndürmeyi atlamayın: doğru konvolüsyon sonucu için önce maske hem yatayda hem dikeyde döndürülür, sonra noktasal çarpım yapılır.

## 12. Ayrılabilir Filtreler ve İşlem Karmaşıklığı

### 12.1 Merkez konumda 2B konvolüsyon

Slayttaki örnekte görüntü ve maske aynı boyuttadır ve yalnız merkez konum hesaplanır (ekrandan, 01:30:00):

$$h = \begin{bmatrix} 1 & 2 & 1 \\ 2 & 4 & 2 \\ 1 & 2 & 1 \end{bmatrix}, \qquad f = \begin{bmatrix} 2 & 3 & 3 \\ 3 & 5 & 5 \\ 4 & 4 & 6 \end{bmatrix}$$

Aynı yerdeki pikseller çarpılır: $1 \cdot 2 = 2$, $2 \cdot 3 = 6$, $1 \cdot 3 = 3$ ve satır satır:

- 1. satır: $2 + 6 + 3 = 11$
- 2. satır: $6 + 20 + 10 = 36$
- 3. satır: $4 + 8 + 6 = 18$
- Toplam: $11 + 36 + 18 = 65$

Satır satır yazmak yalnız gösterim içindir; bütün çarpımlar yapılıp hepsi birlikte de toplanabilir. Maske uygulandığında ortadaki hücrenin değeri 65 olur. Filtre simetrik olduğu için döndürme sonucu değiştirmez; python ile hem doğrudan konvolüsyon hem korelasyon 65 verdi.

### 12.2 İşlem sayısı

$3\times3$ matrislerde her göz diğer matrisin ilgili gözüyle çarpılır: 9 çarpma, yani boyutun karesi kadar. Ardından 9 sayı toplanır.

**Soru:** 9 sayısı nasıl bulundu?
**Cevap:** $1 \times 2$ birinci, $2 \times 3$ ikinci, $1 \times 3$ üçüncü çarpmadır; ikinci ve üçüncü satırla dördüncüden dokuzuncuya kadar çarpma yapılır. Bu çarpmalardan 9 sonuç çıkar ve 9 sayı toplanır. Göz ile bakmak yerine bilgisayarda hesap düşünülmelidir: 9 sayının toplanması gerekir.

> **Hocanın vurgusu:** Toplamanın karmaşıklığı çarpmanın yanında önemsizdir. Karmaşıklığı belirleyen çarpma sayısıdır; daha az toplama yapılsa bile karmaşıklık $n^2$, yani çarpma sayısı kadar olurdu.

### 12.3 Filtreyi çarpanlarına ayırmak

Karmaşıklığı azaltmak için, filtre uygunsa boyut küçültülebilir. İki boyutlu filtre iki tek boyutlu vektörün çarpımı olarak yazılabiliyorsa:

$$\begin{bmatrix} 1 & 2 & 1 \\ 2 & 4 & 2 \\ 1 & 2 & 1 \end{bmatrix} = \begin{bmatrix} 1 \\ 2 \\ 1 \end{bmatrix} \times \begin{bmatrix} 1 & 2 & 1 \end{bmatrix}$$

süperpozisyon kurallarından yararlanılarak işlem iki konvolüsyona bölünür:

1. Satırlar boyunca $[1\ 2\ 1]$ ile konvolüsyon: $2 + 6 + 3 = 11$, $3 + 10 + 5 = 18$, $4 + 8 + 6 = 18$; orta sütunda $11, 18, 18$ elde edilir.
2. Kalan sütun boyunca $[1\ 2\ 1]^T$ ile konvolüsyon: $11 + 36 + 18 = 65$.

Sonuç doğrudan yapılan işlemle aynıdır (python ile kontrol edildi). Hoca bu yolda doğrudan 9 elemanla çarpmak yerine önce 6, sonra 3 çarpma saydı; toplamalar da 9 yerine 3 değerin toplamına indi. Kare matrislerde doğrudan konvolüsyon $n^2$ karmaşıklığındadır; ayrılmış konvolüsyonda $2n$ işlem yapılır ve sabit katsayılar atıldığında $O(n)$, yani doğrusal karmaşıklığa inilir.

> **Ders sonrası not:** Tek bir merkez konumda satır adımındaki üç değeri ($11, 18, 18$) hesaplamak da 9 çarpma ister; yani kazanç tek konumda görünmez. Kazanç, filtre bütün görüntüde gezdirildiğinde ortaya çıkar: satır adımının ara sonuçları komşu çıktı piksellerince paylaşılır ve piksel başına $n^2$ yerine $2n$ çarpma gerekir.

Buradaki asıl koşul filtrenin çarpanlarına ayrılabilir olmasıdır. Bir konvolüsyonel ağda filtre yaratırken ya da seçerken, işlem hızı önemliyse çarpanlarına ayrılabilen bir filtre seçmek düşünülebilir. $3\times3$'lük matrislerde önemsiz görünebilir, ama büyük görüntülere büyük filtreler uygulandığında ve tek değil çok sayıda filtre kullanıldığında "nereden kâr ederseniz kârdır".

## 13. Filtre Seçimi: Kararı Kim Veriyor?

### 13.1 Probleme göre filtreler

Seçilen maskeye göre farklı sonuçlar elde edilir. Örneğin yüz tanıma yapan bir derin ağ kurulmak istenirse yüzde öne çıkarılmak istenecek bazı şeyler vardır: keskin kenarlar için kenar belirleyen bir filtre kullanan konvolüsyon katmanı; ten renginin ayırt edici olduğu bir durumda renk belirleme ya da keskinleştirme filtresi. Bariz şekilleri belirleyecek filtreler seçilerek, ortaya çıkarılmak istenen özelliklerin en az sayısı kadar filtre kullanılabilir. Filtrelerin bir kısmı bilinçli seçilebilir; bilinçsiz de seçilse birden fazla farklı filtre belli özellikleri öne çıkaracaktır. Konvolüsyonel ağın "sırrı" buradadır: uygulanan filtreler belli özellikleri öne çıkardığı için, bir görüntüyü sınıflamak için neyin önemli olduğunu ağ kendisi söyler.

Slayttaki keskinleştirme örneğinde fikir, yerel görüntü bölgelerindeki yoğunluk farklarını hesaplamaktır (ekrandan, 01:35:00). Maske:

$$h = \frac19 \begin{bmatrix} -1 & -1 & -1 \\ -1 & 8 & -1 \\ -1 & -1 & -1 \end{bmatrix}$$

Bütün değerleri 10 olan düz bir bölgede $\tfrac19(-10 \cdot 8 + 80) = 0$ çıkar: gri düzeyde değişim yoktur. 10'lardan 80'lere geçişin üzerinde ise $\tfrac19(-10 - 80 - 80 - 10 + 640 - 80 - 10 - 80 - 80) = 210/9 > 0$ çıkar: gri düzeyde değişim vardır (toplam 210, python ile doğrulandı). Hoca bu tür keskinleştirmenin ünlü bir portre fotoğrafına uygulanmış halini gösterdi.

### 13.2 Ağ mı karar veriyor, biz mi?

Hoca herkesin farklı cevaplayabileceği bir soru sordu: filtreleri biz seçiyorsak, klasik görüntü işlemede olduğu gibi ağın ne yapacağına biz mi karar vermiş oluyoruz, yoksa ağ kendisi mi karar veriyor?

**Soru:** Eğitim (training) sırasında filtrelerin değeri değişir mi?
**Cevap:** Hocaya göre eğitimin içinde filtre değiştirilemez. Eğitim iyi gitmiyorsa başka bir filtreyle eğitimi baştan başlatmak gerekir; aksi halde verinin bir kısmında bir filtreyle bazı özellikler, kalan kısmında başka özellikler çıkarılmış olur. Eğitim yeterince başarılı değilse, yani hata yeterince küçülmüyorsa, filtreler ya yetersizdir ya uygun değildir; filtre değiştirmek ya da eklemek düşünülebilir. Filtre sayısı fazla da olabilir. Eğitim başarısına bakarak filtre sayısı ve türü değiştirilebilir.

> **Ders sonrası not:** Standart CNN'lerde filtre katsayıları (aynı filtredeki nöronların paylaştığı ağırlıklar, bkz. Bölüm 1.1) geri yayılımla eğitim sırasında öğrenilir. Hocanın "eğitim sırasında değiştirilemez" cevabı büyük olasılıkla filtre sayısı ve türü gibi mimari seçimler için geçerlidir.

> **Hocanın vurgusu:** Eğitimin mükemmel olması da istenen bir durum değildir; çok fazla ayrıntıya bakılmış ve ağ ezberlemiş olabilir.

Yüz gibi durumlarda karar bizdeymiş gibi görünebilir: iki yüzü ayırt etmek için hatlar, kaş, göz, saç görülmeli, ona göre filtreler uygulanmalı denebilir. Ama derin ağda filtrelerin özellikle düşünülerek, bilinçli seçilmesi gerekmez; yeter ki farklı özellikleri ortaya çıkaracak yeterli sayıda filtre olsun. Hatta bunları bizim düşünmememiz daha doğrudur: insan algısında önemli görünmeyen ama veride ayırt edici olan bir özellik varsa, buna biz karar veremeyiz ama filtrelerin onu yakalama ihtimali yüksektir. Hocanın görüşüne göre kararı aslında ağ verir. Pooling aşamasında zayıf nöronlar azaltılır ve o bölgede ayırt edici görünmeyen özellikler elenir; bunu da ağın uyguladığı filtrelerin hangi değerleri yükselttiği belirler, biz doğrudan belirlemeyiz.

## 14. Klasik Sinir Ağı ile CNN ve CIFAR-10 Örnek Mimarisi

### 14.1 Ölçeklenme sorunu

Klasik sinir ağları iyi ölçeklenmez. CIFAR-10 veri seti küçük görüntüler içerdiği için yöntem denemeye uygun, hızlı eğitilebilen bir veri setidir. Görüntüler $32 \times 32 \times 3$'tür: 3, RGB renk kanallarını; $32\times32$ resim boyutunu gösterir. Birinci gizli katmanda tek bir tam bağlı nöron olsa bile bu nöronun ağırlık sayısı

$$32 \times 32 \times 3 = 3072$$

olur. Daha gerçekçi bir örnekte, $200\times200$'lük ve üç renk kanallı bir resimde hesaplanması gereken ağırlık sayısı

$$200 \times 200 \times 3 = 120\,000$$

olur. Bu 120 bin işlem her ileri besleme adımında, sonra da her geri dönüşte katman katman yapılacaktır; sayı çok büyür. CNN oluşturulurken ortaya çıkan fikirlerden biri, bütün nöronların birbirine bağlı olmasının şart olmadığıdır. Tam bağlantı işlem yükü ve zaman kaybı getirir; CNN işlemsel olarak da klasik ağdan daha hafiftir.

### 14.2 Yapı karşılaştırması

Klasik ağda bir girdi katmanı ve en fazla iki-üç gizli katman vardır. Daha fazlası pek işe yaramaz, çünkü yol uzadıkça geriye dönerken çarpma sayısı artar ve gradyan kaybolur. Konvolüsyonel ağda ise girdi katmanının yanı sıra üç renk kanalı yüzünden derinliği de olan bir konvolüsyon katmanı vardır; ReLU burada uygulanır, çıkan çok boyutlu matris pooling katmanında küçültülür, sonra tam bağlı katmanda etiketleme ya da sınıflama yapılır.

Slayta göre CIFAR-10 sınıflaması için basit bir ConvNet şu mimariye sahip olabilir (ekrandan, 01:45:00):

```text
[INPUT - CONV - RELU - POOL - FC]
```

Katmanlar birer kez kullanılsa bile başarılı bir sonuç elde etmek mümkündür.

### 14.3 Katmanlardan geçerken boyutlar

- **INPUT:** $32 \times 32 \times 3$; ham piksel değerleri alınır. Matris olarak bakıldığında RGB'nin her kanalı için bir tane, toplam üç tane $32\times32$ matris vardır.
- **CONV:** konvolüsyon katmanı, filtre boyutuna bağlı olarak girdi görüntüsünün belli bölgelerine bağlıdır. Örneğin 12 filtre kullanılırsa çıktı $32 \times 32 \times 12$ olur.
- **RELU:** boyut değişmez ($32 \times 32 \times 12$). ReLU yalnız değerleri değiştirir: $\max(0, x)$; nörona gelen toplam değer sıfırdan büyükse olduğu gibi alınır, sıfır ya da negatifse sıfır olarak alınır. ReLU'dan negatif değer çıkmaz. Sıfıra çekmek bazen risk yarattığı için sıfırın biraz altına inmeye izin verilir; Leaky (sızdıran) ReLU kavramı budur.
- **POOL:** asıl boyut azaltma buradadır. En ve boy üzerinden azaltma yapılır; filtre sayısı azaltılmaz. Yarı yarıya küçültülürse $32\times32$ resim $16 \times 16 \times 12$'ye düşer.
- **FC:** her sınıf için bir skor, yani her görüntünün hangi sınıfa ait olduğuna karar verecek bir değer hesaplanır. 10 kategori varsa boyut $1 \times 1 \times 10$ olur, yani 10 nöronluk bir katman. Slayta göre bu katmandaki her nöron önceki hacimdeki bütün sayılara bağlıdır (ekrandan, 01:50:00).

## 15. ReLU'nun Sorunları: Ölen Nöronlar, Leaky ReLU ve Maxout

ReLU'nun hassas olduğu durumlar vardır. Gradyanın çok büyüdüğü durumlarda ReLU'nun "ölmesi" görülür: nöron sıfıra iner ve sürekli sıfır kalır. Ölmekten kasıt, nöronun bir daha aktive olamamasıdır; bir kez sıfıra düştükten sonra yeni bir örnek gösterilse de değeri yükseltilemez. Hoca, bu durumun istatistiksel olarak nöronların yaklaşık %40'ının ölmesiyle sonuçlanabildiğinin gözlemlendiğini söyledi. Buna dikkat etmek için hem izlemek hem de ReLU'nun bu şekilde düşmemesi için geliştirilmiş yöntemleri uygulamak gerekir.

- **Leaky ReLU:** en bilinen çözümdür. $x < 0$ için sıfır yerine sıfırın biraz altında, sabit küçük bir eğim kullanılır. Slayta göre eğim 0.01 civarındadır ve fonksiyon $f(x) = \mathbb{1}(x<0)(\alpha x) + \mathbb{1}(x \ge 0)(x)$ biçimindedir; $\alpha$ küçük bir sabittir. Slayt, negatif bölgedeki eğimin her nöron için bir parametre yapılabileceğini (PReLU, He ve arkadaşları, 2015) ve faydanın görevden göreve tutarlılığının belirsiz olduğunu da not eder (ekrandan, 01:55:00).
- **Maxout:** nörona giren iki doğrusal toplamdan büyüğü alınır: $\max(w_1^T x + b_1,\; w_2^T x + b_2)$. Hoca bunu ölü nöronları temizlemeye benzetti. Slayta göre ReLU ve Leaky ReLU bunun özel durumlarıdır (ReLU için $w_1 = 0$, $b_1 = 0$); Maxout ReLU'nun avantajlarına sahiptir ve ölen ReLU sorunu yoktur, ama nöron başına parametre sayısını iki katına çıkarır.
- **Öğrenme katsayısı:** öğrenme katsayısı ayarlanarak da nöronların elenmesi önlenebilir. Slayttaki özet önerisi: ReLU kullanın, öğrenme katsayısına dikkat edin, ölü birimlerin oranını izleyin; sorun olursa Leaky ReLU ya da Maxout deneyin.

## 16. Görüntü Dışı Verilerde CNN

**Soru:** CNN genelde girdinin büyük olduğu görüntü işleme problemlerinde kullanılıyor. Yalnız $1\times50$ ya da $1\times100$'lük bir girdi olduğunda da CNN kullanmak mantıklı mı?
**Cevap:** Görüntüdeki kadar başarılı olmayacaktır. Görüntüde başarı göstermiş filtreler doğrudan kullanılır; bu filtrelerin keskinleştirdiği ayırt edici noktalar veride de varsa başarılı olur. Başarının azalmasının nedeni, kullanılan filtrelerin görüntü işleme filtreleri olmasıdır. Görüntü filtreleri yerine başka filtreler kullanılabilir, ama bu kadar bilinçli seçilemez; veri incelenip bu görülebilseydi zaten onun için klasik teknikler olurdu. "Asla başarılı olmaz" denemez; ama başarılı olsa bile sonuca güvenmek için çok sıkı test etmek gerekir, biraz macera gibidir. Farklı uygulamalarda deneniyor, ama uygun filtreler bulunmadıkça görüntü kadar iyi sonuç zordur.

Hoca dersin sonunda bu soruya bir ek yaptı: uygulama alanı çeşitlenebilir. Veriler çizdirildiğinde görsel olarak birbirinden farklı dağılımlar çıkıyorsa, örneğin bir yanda bir Gauss eğrisi, öbür yanda doğrusal bir doğru, bu da görüntü gibi düşünülebilir. Veriye ve probleme bağlı olarak görüntüye benzer, ayırt edici durumlar görülebiliyorsa CNN yine işe yarar.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): $f(a)$, $[0,1]$ aralığında 1, $g(a)$, $[0,1]$ aralığında $1/2$, diğer yerlerde 0 olan iki fonksiyondur. $f(x) * g(x)$'i parçalı fonksiyon olarak bulun.

> **Çözüm (derste verildi):** $x < 0$ ve $x > 2$ için örtüşme yoktur, sonuç 0. $0 \le x \le 1$ için $\int_0^x \tfrac12\, da = x/2$; $1 \le x \le 2$ için $\int_{x-1}^{1} \tfrac12\, da = 1 - x/2$. Sonuç, $x = 1$'de $1/2$ tepeli, genişliği $1 + 1 = 2$ olan bir üçgendir. Python ile sayısal konvolüsyon aynı değerleri verdi.

**Soru 2** (ekrandan, 00:40:00; derste sözlü, 00:39:53): $[0,t]$ aralığında 1 olan kare fonksiyon, $-T$, $0$ ve $T$ noktalarındaki üç impulsla konvolüsyona sokulursa sonuç neye benzer?

> **Çözüm (derste verildi):** Impuls konvolüsyonda etkisiz eleman gibidir ve fonksiyonu kendi konumuna öteler. Sonuç, kare fonksiyonun $-T$, $0$ ve $T$'ye ötelenmiş üç kopyasıdır ($[-T, -T+t]$, $[0, t]$, $[T, T+t]$ aralıklarında 1). Soldaki impuls da sönümlenmez, çünkü kaydırma sırasında kare fonksiyon onun üzerinden de geçer. Kopyaların ayrı kalması için $t < T$ olmalıdır; bu koşul derste söylenmedi (ara adım eklendi).

**Soru 3** (ekrandan, 01:20:00): Slayttaki $10\times10$ görüntüye (kenarları 0, ortada içinde bir 0 bulunan $5\times5$'lik 90 bölgesi, sol altta tek bir 90) $\tfrac19$ ölçekli $3\times3$ birler filtresiyle korelasyon uygulayın.

> **Çözüm (derste kısmen verildi):** Derste ilk konumlar gösterildi: altında hiç 90 olmayan konum 0, bir tane 90 olan konum $\tfrac19 \cdot 90 = 10$, iki tane 90 olan 20, üç tane 90 olan 30. Çıktının tamamı Bölüm 9.3'teki $8\times8$ matristir; ilk satır $0, 10, 20, 30, 30, 30, 20, 10$, son satır $10, 10, 10, 0, 0, 0, 0, 0$'dır. Tam çıktı python ile yeniden hesaplandı ve slaytla birebir aynı çıktı.

**Soru 4** (ekrandan, 01:30:00): $h = \begin{bmatrix}1&2&1\\2&4&2\\1&2&1\end{bmatrix}$ ve $f = \begin{bmatrix}2&3&3\\3&5&5\\4&4&6\end{bmatrix}$ için merkez konumdaki konvolüsyon değerini önce doğrudan, sonra filtreyi tek boyutlu filtrelere ayırarak hesaplayın. Doğrudan yolda kaç çarpma gerekir?

> **Çözüm (derste verildi):** Doğrudan: $(2+6+3) + (6+20+10) + (4+8+6) = 11 + 36 + 18 = 65$; 9 çarpma ve 9 toplama. Ayrılmış: $h = [1\ 2\ 1]^T [1\ 2\ 1]$; satırlar boyunca $[1\ 2\ 1]$ ile $11, 18, 18$, ardından sütun boyunca $[1\ 2\ 1]^T$ ile $11 + 36 + 18 = 65$. Python ile doğrulandı. Genel karmaşıklık $n^2$'den $2n$'ye iner.

**Soru 5** (ekrandan, 01:35:00): Keskinleştirme maskesi $\tfrac19\begin{bmatrix}-1&-1&-1\\-1&8&-1\\-1&-1&-1\end{bmatrix}$ bütün değerleri 10 olan bir bölgede ve 10-80 geçişinin üzerinde ne verir?

> **Çözüm (slaytta verildi, derste ayrıca hesaplanmadı):** Düz bölgede $\tfrac19(-10 \cdot 8 + 8 \cdot 10) = 0$: gri düzeyde değişim yoktur. Geçişte $\tfrac19(-10-80-80-10+640-80-10-80-80) = 210/9 > 0$: değişim vardır. Toplam 210 python ile doğrulandı.

**Soru 6** (derste sözlü, 01:41:31): CIFAR-10'daki $32\times32\times3$ görüntülerde birinci gizli katmandaki tek bir tam bağlı nöronun kaç ağırlığı olur? $200\times200\times3$ görüntüde bu sayı kaçtır?

> **Çözüm (derste verildi):** $32 \cdot 32 \cdot 3 = 3072$ ve $200 \cdot 200 \cdot 3 = 120\,000$. Bu sayılar her ileri ve geri geçişte tekrarlanacağı için tam bağlantı işlem yükü getirir; CNN yerel bağlantıyla bu yükü azaltır.

**Soru 7** (ekrandan, 01:50:00): CIFAR-10 için [INPUT - CONV - RELU - POOL - FC] mimarisinde 12 filtre ve yarı yarıya küçülten pooling kullanılırsa her katmanın çıktı boyutu nedir?

> **Çözüm (derste verildi):** INPUT $32\times32\times3$; CONV $32\times32\times12$; RELU boyutu değiştirmez, $32\times32\times12$; POOL $16\times16\times12$; FC 10 sınıf için $1\times1\times10$.

## Dersin Toparlaması

Bu derste konvolüsyonel ağların katmanları (konvolüsyon, ReLU, pooling, tam bağlı) kısaca tekrarlandı ve ardından ağa adını veren konvolüsyon işlemi ayrıntılı ele alındı. Korelasyon, aynı indisli elemanların çarpılıp toplandığı noktasal çarpımdır; konvolüsyon ise maskenin yatay ve dikey döndürülmesiyle yapılan korelasyondur ve simetrik maskelerde ikisi aynıdır. Sürekli durumda konvolüsyon ötelenmiş fonksiyonla çarpımın integralidir; iki kare fonksiyonun konvolüsyonu üçgen verir, impuls etkisiz eleman gibi davranır. Konvolüsyon teoremine göre uzamsal domendeki konvolüsyon frekans domeninde çarpmaya karşılık gelir. Ayrık durumda sonucun boyutu $A + B - 1$ (iki boyutta $(A+C-1)\times(B+D-1)$) olur; teoremin geçerli olması için diziler sıfırla uzatılır. Görüntü üzerinde ortalama filtresi, kosinüs benzerliğiyle korelasyonun anlamı, ayrılabilir filtrelerle karmaşıklığın $n^2$'den $2n$'ye inmesi ve keskinleştirme maskesi örneklerle gösterildi.

Son bölümde klasik ağların ölçeklenme sorunu CIFAR-10 üzerinden sayısal olarak gösterildi, [INPUT - CONV - RELU - POOL - FC] mimarisinde katmanlardan geçerken boyutların nasıl değiştiği izlendi ve ReLU'nun ölen nöron sorunu ile Leaky ReLU ve Maxout çözümleri tanıtıldı. Hoca, filtrelerin özelliklerini öne çıkarmasıyla neyin önemli olduğuna aslında ağın karar verdiğini, CNN'in görüntü dışı verilerde ancak veride görsel olarak ayırt edici biçimler varsa iyi çalışacağını vurguladı. Padding gibi konuların daha görsel anlatımı, rekürent ağlar ve düzenlileştirme sonraki derslere bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
