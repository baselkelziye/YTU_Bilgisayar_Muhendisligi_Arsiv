# Ders 14 Genişletilmiş Notu: Genel Tekrar: Temel Kavramlar, Dizi Hizalama, Filogenetik ve İstatistik

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

<!-- BELİRSİZ: Kayıt dönemin son dersidir ve yeni konu içermez; hoca slaytları hızlıca açarak genel tekrar yaptı. Altyazının bazı yerleri Whisper tarafından bozulmuştur; bozuk yerler işaretlendi. -->

## İçindekiler

- 1. Temel Kavramlar ve Bilgisayar Temelleri
- 2. Biyoenformatik Veri Türleri
- 3. Biyoenformatikte Programlama
- 4. İkili Dizi Hizalama ve Nokta Matrisi
- 5. Uzaklık Ölçüleri ve Boşluklar
- 6. Dinamik Programlama ile Hizalama
- 7. Çoklu Dizi Hizalama
- 8. Filogenetik
- 9. İstatistik ve Sinyal Filtreleri
- 10. Görselleştirme
- 11. Örnek Sorular
- 12. Dersin Toparlaması

## 1. Temel Kavramlar ve Bilgisayar Temelleri

Dönemin son dersinde yeni bir konu işlenmedi. Hoca konuları bitirdiklerini söyleyip dönemin genel tekrarını yaptı; slaytları sunum moduna geçmeden hızlıca açtı ve her konunun ana fikrini hatırlattı.

İlk konu dersin girişiydi. Burada biyoenformatiğin tanımı ve gen ifadesi gibi temel kavramların tanımları vardı. Hoca bunların çok genel tanımlar olduğunu, ama temel kavramlar olarak önemli olduğunu söyledi.

> **Hocanın vurgusu:** Biyoenformatiğin tanımı ve temel gen ifadesi tanımları gibi genel kavramlar bilinmelidir.

Sonraki bölüm bilgisayarla ilgili temel kavramlardı: bilgi, veri ve sistemin ne olduğu, özel olarak bilgi sistemlerinin ne olduğu ve ne olmadığı. Bilgi sistemini oluşturan temel elemanlardan biri bilgisayardır. Ekranda açılan "A Digital Computer Example" slaytında bir sayısal bilgisayarın blok şeması vardı (ekrandan, 00:15:00):

- CPU iki parçadan oluşur: denetim birimi (control unit) ve veri yolu (datapath).
- CPU bellekle (memory) ve giriş/çıkış birimiyle (input/output) çift yönlü bağlantılıdır.
- Girişlere örnek: klavye, fare, modem, mikrofon.
- Çıkışlara örnek: CRT, LCD, modem, hoparlör.
- Slaytın altındaki soru: "Synchronous or Asynchronous?" Slayt notunda, bir PC'nin MHz cinsinden belirtilen özelliğinin, eş zamanlı (synchronous) bir sistemde durumun güncellendiği ayrık zamanları belirleyen saati (clock) gösterdiği, ama bilgisayarın her parçasının eş zamanlı olmayabileceği yazıyordu.

Bilgisayardaki temel veri tipleri de tekrar edildi: işaretli (signed) ve işaretsiz (unsigned) tamsayılar (integer) ile kayan noktalı sayılar (float). Diğer veri tipleri bu temel tipler kullanılarak kurulur. Hoca burada asıl önemli olanın, sayısal (nümerik) değerlerin ve sayısal olmayan kategorik bilgilerin bilgisayarda nasıl temsil edildiği olduğunu belirtti. Bu konu, sonraki konu olan biyoenformatik veri türleriyle bağlantılıdır.

## 2. Biyoenformatik Veri Türleri

Biyoenformatik veri türleri DNA, amino asitler ve diğer biyolojik verilerdir. Hoca bu konunun, istatistiksel veri analizi ya da veri madenciliği gibi derslerde görülen veri tipleri bağlamında düşünülmesi gerektiğini söyledi.

Veri genel olarak iki türe ayrılır:

- **Numerik (sayısal) veri.**
- **Numerik olmayan, kategorik veri.** Bunun da nominal ve ordinal alt türleri vardır.

Bir verinin hangi türe girdiğini belirleyebilmek beklenir. Biyoenformatik veri tabanlarında hem kategorik hem numerik veri bulunur. DNA harflerle temsil edilir, dolayısıyla kategorik veridir. Amino asitler de harflerle temsil edilir.

Kategorik veriler sayısal yöntemlerle analiz edilecekse doğrudan sayısal işlem yapılamaz. İstatistikte bunun için olasılık tabloları (contingency tables) kullanılır; veri oranlara ve frekanslara dönüştürülür. Ancak bu dönüşümden sonra sayısal yöntemleri uygulamak mümkün olur.

> **Hocanın vurgusu:** DNA ve amino asit dizilerinin kategorik veri olduğu, kategorik verinin sayısal analizinde frekans ve oranlara dönüştürme yaklaşımının kullanıldığı gibi ayrıntılar bilinmelidir.

## 3. Biyoenformatikte Programlama

Sonraki konu, biyoenformatikte kullanılan programlama dili bağlamındaki konulardı. Hoca bunların öğrencilerin zaten iyi bildiği konular olduğunu söyledi. Bu kısımdan beklenen, verilen bir kodun ne yaptığını söyleyebilmek ya da belli bir işi hangi kodla çözeceğini bilmektir.

## 4. İkili Dizi Hizalama ve Nokta Matrisi

> **Hocanın vurgusu:** İkili dizi hizalama (pairwise sequence alignment), kullanılan temel algoritmalarla birlikte dersin en önemli konularından biridir.

İkili dizi hizalama, iki DNA ya da amino asit dizisini alıp hizalamak için kullanılan yöntemleri kapsar. Hoca üç dört yöntemden bahsettiklerini hatırlattı. Bunlardan biri nitel (kalitatif, görsel) yöntemdir; diğerleri hizalamayı nesnel (objektif) olarak yapan yöntemlerdir.

### 4.1 Nokta matrisi (dot matrix)

Nitel yöntem nokta matrisidir. İki dizi olsun: birinci dizi $M$ elemanlı, ikinci dizi $K$ elemanlı. Başlangıçta $M \times K$ boyutunda bir matris oluşturulur. Dizilerden biri satırlara, diğeri sütunlara yazılır ve harfler birer birer karşılaştırılır.

- Karşılaştırma sonucu eşleşme (match) ise, yani harfler aynıysa, o hücreye bir işaret konur. Elle çizerken çarpı konabilir; yazılımda hücre siyah ya da başka bir renkle boyanır.
- Harfler farklıysa (mismatch) hücre boş (beyaz) bırakılır ya da farklı bir sembol konur.

Böylece matriste bir benzerlik örüntüsü (pattern) oluşur. Bu en basit yöntemdir.

Hoca bu yöntemi ekrandaki alıştırma üzerinde gösterdi (ekrandan, 00:25:00). Satırlarda `F K H M E D P L E`, sütunlarda `F M D T P L N E` dizisi vardı. İlk satırdaki F için yalnız F sütunu eşleşir, oraya çarpı konur. K ve H için hiç eşleşme yoktur. M, E, D, P, L ve son E harflerinin her biri sütun dizisinde bir harfle eşleşir. Matrisin tamamı "Örnek Sorular" bölümünde verildi.

### 4.2 Nokta grafiğinde gürültü ve kayan pencere

Nokta matrisinde satır ve sütundaki diziler aynı olsa bile, rastgele birbirine uyan harfler yüzünden gürültü oluşur. Bu gürültüyü elemek için kayan pencere (sliding window) tekniği kullanılır.

Ekrandaki "Noise in Dot Plots" slaytı bu fikri özetliyordu (ekrandan, 00:35:00):

- Nükleik asitlerde (DNA, RNA) dört bazdan biri rastgele eşleşir.
- Rastgele eşleşmeleri süzmek için kayan pencereler kullanılır; pencerede eşleşen bazların yüzdesi eşik olarak belirlenir. Bir nokta ancak en az belli sayıda eşleşme varsa basılır.
- Pratik kural: DNA için daha büyük pencereler kullanılır (yalnız 4 baz olduğu için rastgele eşleşme daha çoktur). Tipik pencere boyu 15, eşik (stringency) 10'dur.

Alıştırmanın ikinci şıkkı "üç boyutlu kayan pencere ve iki benzerlik eşiğiyle" nokta grafiğini yeniden çizmeyi istiyordu. Hoca bunu şöyle açıkladı: bir hücrenin eşleşme olup olmadığına karar vermek için tek harf yerine üçlü gruplar karşılaştırılır. Satır dizisinden bir üçlü alınır ve sütun dizisinin üçlüleriyle sırayla karşılaştırılır; üçlünün en az ikisi aynıysa hücreye benzerlik işareti konur, değilse konmaz. Sonra satırdaki pencere bir kaydırılır (örneğin `FKH`) ve yine sütun dizisinin üçlüleriyle (`FMD`, `MDT`, `DTP`, ...) dizi bitene kadar karşılaştırılır. Böylece tek harfte eşleşme gibi görünen bazı durumlar elenir ve daha temiz bir nokta grafiği elde edilir.

<!-- BELİRSİZ: Hoca pencereyi dizinin başında boşluk (tire) ekleyerek başlattığını söylüyor ("-F", "-FK" gibi); pencerenin hücreye göre ortalanıp ortalanmadığı ve kenarlarda tirenin eşleşme sayılıp sayılmadığı altyazıdan net değil. -->

Çok daha uzun dizilerde daha uzun pencereler alınır. Örneğin 10 elemanlı bir pencere alıp bunun 5'i eşleşiyorsa nokta koymak gibi farklı ölçütlerle farklı düzeylerde filtreleme yapılabilir.

### 4.3 Nokta grafiğini yorumlamak

Hoca nokta grafiğinden çıkarılabilecek yorumları da hatırlattı. Örneğin bir dizi bölümü bir süre sonra kaymış olarak tekrar ediyorsa grafikte bunu gösteren bir örüntü oluşur; benzer şekilde bir ekleme ya da silme (indel) de görsel bir örüntü olarak görünür.

> **Hocanın vurgusu:** Nokta grafiğindeki örüntüleri yorumlayabilmek gerekir; bu slaytlara bakmakta fayda var.

## 5. Uzaklık Ölçüleri ve Boşluklar

İkili hizalama algoritmalarından biri kaba kuvvet (brute force) yöntemidir. Bu algoritmaları gerçekleştirmek için temel ölçütler gerekir; bunlardan biri uzaklık (distance) kavramıdır.

DNA ve amino asit dizileri kategorik veri olduğu için, sayısal verilerde kullanılan Öklid uzaklığı gibi ölçüler yerine kategorik veriye uygun ölçüler kullanılır: Hamming uzaklığı, düzenleme (edit) uzaklığı ve Levenshtein uzaklığı. Hizalamalar için ise özel olarak geliştirilmiş skor matrisleri vardır; bunlar sonraki konularda incelenmişti.

Hizalamada çizgiyle gösterilen boşluklar (gap) dizilerin boyunu denkleştirmek için kullanılır. Hoca şu durumu düşünmeyi önerdi: karşılaştırılan iki DNA dizisi aslında aynı diziydi, ama mutasyonlar gibi çeşitli nedenlerle farklılaştı. Problem, bunların benzerliğinin ölçüsünü anlamaktır. Bunun için diziler hizalanır ve uzunlukları eşitlenir; bu eşitleme boşluklarla sağlanır. Biyolojik olarak boşluklar ekleme (insertion) ya da silmeyi (deletion), yani orijinalde olmayan bir kimyasal bileşenin eklenmesini ya da var olanın çıkmasını temsil eder.

Ekranda bu fikri gösteren slayt açıktı (ekrandan, 00:30:00). Atasal dizi `ABCD` olsun. Bir kolda B, C'ye dönüşür (mutasyon) ve `ACCD` oluşur; diğer kolda C silinir ve `ABD` oluşur. Bu iki dizinin ikili hizalaması için iki aday vardır:

```text
ACCD        ACCD
AB-D   ya da  A-BD
```

Soldaki, evrim sürecine uyan gerçek hizalamadır (true alignment).

## 6. Dinamik Programlama ile Hizalama

Bir hizalamayı nesnel olarak bulmak için dinamik programlama kullanılır. Dinamik programlama, bilgisayar bilimlerinde ve hemen her alanda yaygın olarak kullanılan bir optimizasyon tekniğidir; biyoenformatikte hizalamada kullanılır.

**Soru (hocanın sorusu):** Dinamik programlamanın kaç türü vardı? **Cevap:** Hoca, literatürde üç dört farklı adla karşılaşılabileceğini söyleyip derste işlenen türleri sıraladı: global hizalama, yerel hizalama ve örtüşme hizalaması için dinamik programlama.

### 6.1 Dinamik programlamanın iki temel unsuru

Dinamik programlamada da nokta matrisindeki gibi bir matris kurulur; satıra ve sütuna iki dizi yazılır. İki önemli unsur vardır:

1. **Başlangıç problemi:** İlk satır ve ilk sütunun nasıl doldurulacağı. Bu, hizalama türüne göre değişir.
2. **Özyineleme (recursion):** Matrisin her hücresinin skorunun nasıl belirleneceği. Bu da uygulamadan uygulamaya değişebilir.

### 6.2 Global hizalama

Global hizalamada başlangıç değerleri, matrisi hesaplamada kullanılan parametrelerden biri olan boşluk cezası (gap penalty) ile belirlenir. Boşluk cezası, hizalamada bir boşluk varsa ona verilen skordur. İlk satır ve sütun, satır ya da sütun indeksi çarpı boşluk cezası olarak doldurulur: $S_{i,0} = w \cdot i$, $S_{0,j} = w \cdot j$. Hocanın örneğiyle, boşluk cezası $-1$ ise ilk satır ve ilk sütun $0, -1, -2, -3, -4, -5, -6$ diye gider.

Diğer hücreler şu özyinelemeyle doldurulur (ekrandan, 00:40:00):

$$
S_{i,j} = \max
\begin{cases}
S_{i-1,j-1} + s(a_i, b_j) & \text{(çaprazda eşleşme/eşleşmeme)}\\
S_{i,j-1} + w & \text{(1. dizide boşluk)}\\
S_{i-1,j} + w & \text{(2. dizide boşluk)}
\end{cases}
$$

Hocanın sözel anlatımıyla: değeri belirlenecek hücre için üç aday vardır. Çapraz komşunun değeri artı o harf çiftinin eşleşme ya da eşleşmeme skoru; soldaki hücrenin değeri artı boşluk cezası; üstteki hücrenin değeri artı boşluk cezası. Bu üç değerden hangisi büyükse hücrenin değeri o olur.

Matris dolduktan sonraki aşama geri izlemedir (traceback). Her hücrenin değerinin hangi hücreden geldiği saklanır; sondan geriye doğru giderken bu bilgi kullanılarak bir yol çıkarılır ve hizalama bu yoldan elde edilir.

### 6.3 Yerel hizalama: Smith-Waterman

Yerel hizalama için dinamik programlama Smith-Waterman algoritmasıdır. Global hizalamayla aynı mantıktadır, ama iki farkı vardır:

1. İlk satır ve ilk sütun 0 ile doldurularak başlanır.
2. Özyinelemedeki maksimum ifadesine dördüncü seçenek olarak 0 eklenir.

İkinci farkın anlamı şudur: yerel hizalamada negatif değerlere yer verilmez; en küçük değer 0 olur ve matris yalnız sıfır ve pozitif değerlerden oluşur. Hangi hücrenin değerinin hangi hücreden geldiği bilgisi saklandığı için geri izleme kolayca yapılır.

Ekrandaki "Trace Back (Local Alignment)" slaytına göre geri izleme şöyle yapılır (ekrandan, 00:45:00):

- Geri izleme en yüksek değerli hücreden başlar.
- Her hücrede işaretçilere bakılarak bir sonraki adımın nereye gideceği belirlenir.
- Önceki bir hücreye işaretçisi olmayan bir hücreye varılınca hizalamanın başına gelinmiş olur.

### 6.4 Örtüşme hizalaması (overlap alignment)

Üçüncü tür örtüşme hizalaması için dinamik programlamadır. Normalde aynı dizinin parçaları olan iki farklı diziyi birleştirmek için kullanılır. Global ve yerel hizalamanın bir karışımıdır:

- Yerel hizalama gibi başlar: ilk satır ve ilk sütun sıfırla doldurulur.
- Global hizalama gibi doldurulur: özyinelemeye 0 eklenmez.

Bu yüzden örtüşme hizalamasında negatif değerlere izin verilir; ilk satır ve sütun sıfır olduğu halde matrisin diğer elemanları negatif olabilir.

### 6.5 Skor matrisleri ve anlamlılık

Dinamik programlamada basit eşleşme/eşleşmeme skoru yerine skor matrisleri de kullanılabilir. Bunlar DNA ya da amino asit dizilerinin özellikleri kullanılarak oluşturulmuş benzerlik matrisleridir. Ayrıca elde edilen hizalamanın gerçekten anlamlı (significant) bir hizalama olup olmadığı test edilir; bunun için istatistiksel yaklaşımlar kullanılır.

## 7. Çoklu Dizi Hizalama

Hizalanacak dizi sayısı ikiden fazlaysa problem çoklu dizi hizalaması (multiple sequence alignment, MSA) problemine dönüşür. MSA'nın da global ve yerel olmak üzere iki türü vardır ve her biri için üç dört algoritmadan bahsedilmişti.

Bu algoritmaların hepsi sezgiseldir (heuristic), yani optimal değildir. Dizi sayısı arttıkça hesaplama maliyeti (karmaşıklığı) çok artar. Bunu azaltmak için bazı yaklaşımlar kullanılır; bu yaklaşımlar kullanıldığında elde edilen sonuç artık optimum olmaktan çıkar. Teorik olarak optimum sonucu dinamik programlamayla elde etmek mümkündür, ama hesaplaması çok karmaşık hale gelir.

Ekrandaki MSA slaytları da bunu özetliyordu (ekrandan, 00:50:00). Çoklu hizalamanın zorluğu, birkaç farklı dizi incelenirken hesaba katılması gereken çok sayıda eşleşme, ekleme ve silme kombinasyonudur. En yüksek skorlu hizalamayı garanti eden yöntemler uygulanabilir değildir; bu yüzden MSA'da yaklaşık yöntemler kullanılır. Slayt sunumunun ana hatlarında yöntemler aşamalı (progressive) global hizalama, yinelemeli (iterative) yöntemler ve yerel olarak korunmuş örüntülere dayalı hizalamalar olarak listelenmişti.

Sezgisel uygulamaların çoğunda filogenetik ağaç kullanılır. Hoca bunu MSA anlatılırken sık sık söylediklerini, filogenetik ağaç konusunun da sonra ayrıca işlendiğini hatırlattı.

<!-- BELİRSİZ: 00:49:36 civarında hocanın andığı sezgisel yöntem adı altyazıda bozuk ("D-Wisekümseraymen"); büyük olasılıkla bir aşamalı hizalama yöntemidir, kesin değildir. -->

## 8. Filogenetik

Filogenetik konusu ayrıntılı işlenmişti: ağaç oluşturmanın ne olduğu, nasıl yapıldığı ve hangi yöntemlerin kullanıldığı. Hoca yaygın olarak kullanılan bir teknik olduğunu ve bu konudan da tekrar yapılması gerektiğini söyledi.

<!-- BELİRSİZ: 00:51:05'teki ağaç oluşturma yöntemlerinin adları altyazıda bozuk; hangi yöntemlerin sayıldığı anlaşılmıyor. -->

## 9. İstatistik ve Sinyal Filtreleri

Hoca istatistiği ayrıca andı, çünkü istatistik biyoenformatiğin hemen her adımında kullanılan yöntemlerden biridir.

### 9.1 Betimsel ve çıkarımsal istatistik

İki tür istatistikten bahsedilmişti: betimsel (descriptive) ve çıkarımsal (inferential). Hangisinin ne zaman kullanıldığı ve betimsel istatistiğin temel yöntemleri tekrar edildi. Betimsel istatistikte özellikle merkezi eğilim (central tendency) ile ifade edilen ortalamalar ve varyans işlenmişti.

Kullanılacak yöntem verinin türüne bağlıdır:

- Kategorik veri varsa daha çok frekanslar ve frekanslardan elde edilen olasılık değerleri kullanılır.
- Numerik veri varsa dağılımını görmek için histogram kullanılır.

### 9.2 Farklı ortalamalar

Ortalama basit görünse de çok farklı ortalamalar vardır ve verinin dağılımına göre hangisinin kullanılacağı değişir. Ekranda açık slaytlarda bu ortalamalardan örnekler vardı (ekrandan, 00:55:00):

- **Ağırlıklı aritmetik ortalama:** aynı popülasyondan, farklı örnek büyüklüklerine sahip örneklerden gelen ortalamaları birleştirmek için kullanılır: $\bar{x} = \dfrac{\sum_i w_i x_i}{\sum_i w_i}$.
- **Kuvvet ortalaması (power mean):** $M_p = \left(\dfrac{1}{n}\sum_{k=1}^{n} x_k^{p}\right)^{1/p}$. Özel durumları: $M_{-\infty}$ en küçük değer, $M_{-1}$ harmonik ortalama, $M_0$ geometrik ortalama, $M_1$ aritmetik ortalama, $M_2$ karesel ortalama (root-mean-square), $M_{\infty}$ en büyük değer.

<!-- BELİRSİZ: Ortalama slaytları karede küçük önizleme olarak görünüyor; formüller önizlemeden okundu. -->

### 9.3 Hareketli ortalama filtresi

Ortalamalar çok farklı alanlarda kullanılır; bunlardan biri bir işareti ya da görüntüyü filtrelemektir. Görüntüdeki gürültüyü azaltmak için kullanılan yöntemlerden biri yumuşatma (smoothing) filtresidir. Yumuşatma filtresi aslında bir hareketli ortalama (moving average) filtresidir: nokta matrisindeki gibi bir pencere belirlenir ve pencere boyunca ortalama hesaplanır. Bu işlem alçak geçiren filtreye denk düşer ve görüntüyü daha pürüzsüz hale getirir. Çok hızlı değişen bir eğrideki trendi görmek için de aynı yaklaşım kullanılır; buna trend gösteren filtre (trending filter) denir.

### 9.4 Hareketli fark filtresi

Hareketli ortalamanın tersi hareketli fark (moving difference) filtresidir. Yine pencereler alınır, ama pencere boyunca fark (türev) hesaplanır. Görüntü işlemede keskinleştirme (sharpening) filtresi, ya da trend giderme (trend removal) filtresi olarak bilinir. Trendi, yani sinyalin DC değerini yok eder; yalnız hızlı değişen bileşenleri görmeyi sağlar. Finansal verilerde de biyoenformatikte de kullanılan yöntemlerdir.

Ekrandaki slayttaki tanımlar (ekrandan, 00:55:00):

- Birinci dereceden fark: $Dy_t = y_t - y_{t-1}$.
- İkinci dereceden fark: $D^2 y_t = D(Dy_t) = Dy_t - Dy_{t-1} = y_t - 2y_{t-1} + y_{t-2}$.
- Örnek (birinci dereceden hareketli fark filtresi): $x = (x_1, x_2, x_3, \dots)$ için $y = (x_2 - x_1,\ x_3 - x_2,\ x_4 - x_3,\ \dots)$.

İkinci dereceden farkın açılımı: $Dy_t - Dy_{t-1} = (y_t - y_{t-1}) - (y_{t-1} - y_{t-2}) = y_t - 2y_{t-1} + y_{t-2}$ (ara adım eklendi).

### 9.5 Medyan, mod ve diğer ölçüler

Veri simetrik dağılmıyorsa ortalama (mean) yerine medyan kullanılabilir. Benzer şekilde hareketli medyan (moving median) filtresi de kurulabilir. Özellikle doğrusal olmayan gürültü varsa medyan filtresi bu gürültüyü bastırmakta etkilidir. Bazı durumlarda merkezi eğilim için mod daha iyi bir ölçü olabilir.

Varyans ve standart sapma, genelde ortalamayla birlikte, bir veri kümesinden öznitelik çıkarmak istendiğinde öznitelik olarak kullanılabilecek parametrelerdir. Yüzdelikler (percentile) ve çeyrekler (quartile) de işlenmişti. Veride belirsizlik ya da hata söz konusuysa olasılık devreye girer; bu konudan da bahsedilmişti.

> **Ek bilgi (derste anlatılmadı):** Medyan filtresinin dürtü (impulse, "tuz-biber") gürültüsünde başarılı olmasının nedeni, penceredeki tek bir aşırı değerin ortalamayı kaydırması ama sıralanmış değerlerin ortasını değiştirmemesidir. Bu yüzden medyan filtresi kenarları da hareketli ortalamaya göre daha iyi korur.

## 10. Görselleştirme

Son konu görselleştirmeydi. Hoca görselleştirmenin bilgisayar bilimlerinin önemli bir konusu olduğunu, hem işin teorik tarafından hem de pratik görselleştirme yöntemlerinden bahsettiklerini hatırlattı.

## 11. Örnek Sorular

### Soru 1 (ekrandan, 00:25:00)

`F K H M E D P L E` ve `F M D T P L N E` dizileri veriliyor.

a. Dizilerin nokta grafiğini (dot plot) bulun.

b. Nokta grafiğini üç boyutlu kayan pencere ve iki benzerlik eşiğiyle (sliding window size of three, similarity cutoff of two) tekrarlayın.

c. Aşağıdaki skorlama kurallarıyla global hizalama için dinamik programlama matrisini doldurun: eşleşme skoru $+1$, eşleşmeme skoru $-2$, boşluk cezası $-2$.

d. En iyi global hizalamayı belirleyin.

**a şıkkı (derste sözlü olarak çözüldü, 00:24:29).** Satırlar birinci dizi, sütunlar ikinci dizidir; aynı harfli hücreye `x` konur. Hoca F için tek eşleşmeyi, K ve H için eşleşme olmadığını, sonra M, E, D, P, L ve E için birer eşleşme olduğunu söyledi. Python ile doğrulanan matris:

```text
    F  M  D  T  P  L  N  E
F   x  .  .  .  .  .  .  .
K   .  .  .  .  .  .  .  .
H   .  .  .  .  .  .  .  .
M   .  x  .  .  .  .  .  .
E   .  .  .  .  .  .  .  x
D   .  .  x  .  .  .  .  .
P   .  .  .  .  x  .  .  .
L   .  .  .  .  .  x  .  .
E   .  .  .  .  .  .  .  x
```

**b şıkkı.** Hoca yöntemi anlattı (üçlüler karşılaştırılır, en az ikisi aynıysa işaret konur), ama matrisi derste tamamlamadı.

> **Çözüm (derste verilmedi):** Pencerenin hücreye göre ortalandığı ve dizi dışına taşan pencere konumlarının eşleşme sayılmadığı varsayımıyla (python ile hesaplandı), $(i-1,j-1)$, $(i,j)$, $(i+1,j+1)$ çapraz üçlüsünde en az iki eşleşme olan hücreler yalnız (P, P) ve (L, L) hücreleridir. (P, P) için `DPL`–`TPL` üçlüsünde 2 eşleşme, (L, L) için `PLE`–`PLN` üçlüsünde 2 eşleşme vardır. Tek başına kalan F–F, M–M, D–D ve E–E eşleşmeleri elenir. Kenarlarda tire eşleşme sayılırsa ya da pencere hücreden başlatılırsa sonuç değişebilir.

**c şıkkı.**

> **Çözüm (derste verilmedi):** İlk satır ve sütun $0, -2, -4, \dots$ diye boşluk cezasının katlarıyla başlar; diğer hücreler 6.2'deki özyinelemeyle doldurulur. Python ile hesaplanan matris:

```text
       -    F    M    D    T    P    L    N    E
  -    0   -2   -4   -6   -8  -10  -12  -14  -16
  F   -2    1   -1   -3   -5   -7   -9  -11  -13
  K   -4   -1   -1   -3   -5   -7   -9  -11  -13
  H   -6   -3   -3   -3   -5   -7   -9  -11  -13
  M   -8   -5   -2   -4   -5   -7   -9  -11  -13
  E  -10   -7   -4   -4   -6   -7   -9  -11  -10
  D  -12   -9   -6   -3   -5   -7   -9  -11  -12
  P  -14  -11   -8   -5   -5   -4   -6   -8  -10
  L  -16  -13  -10   -7   -7   -6   -3   -5   -7
  E  -18  -15  -12   -9   -9   -8   -5   -5   -4
```

Örnek bir hücre: (F, F) hücresi $\max\{0 + 1,\ -2 + (-2),\ -2 + (-2)\} = \max\{1, -4, -4\} = 1$.

**d şıkkı.**

> **Çözüm (derste verilmedi):** Sağ alt köşedeki skor $-4$'tür. Geri izleme bu hücreden başlar; python ile bütün optimal yollar çıkarıldığında tek bir en iyi global hizalama vardır:

```text
F K H M E D - P L - E
F - - M - D T P L N E
```

Skor kontrolü: 6 eşleşme ($6 \times (+1) = +6$) ve 5 boşluk ($5 \times (-2) = -10$), toplam $-4$; eşleşmeme yoktur.

### Soru 2 (derste sözlü, 00:33:03)

Dinamik programlamanın derste işlenen türleri nelerdir?

**Cevap (derste verildi):** Global hizalama (ilk satır/sütun boşluk cezasının katları, negatif değer olabilir), yerel hizalama ya da Smith-Waterman (ilk satır/sütun 0, özyinelemeye 0 eklenir, negatif değer yok) ve örtüşme hizalaması (sıfırla başlar, global gibi doldurulur, negatif değer olabilir).

## 12. Dersin Toparlaması

Bu son ders, dönem boyunca anlatılanların kısa bir haritasıdır. Temelde veri kavramı vardır: bilgisayar sayısal ve kategorik bilgiyi temsil eder, biyolojik diziler ise harflerle temsil edilen kategorik verilerdir. Bu yüzden diziler karşılaştırılırken Öklid yerine Hamming, edit ve Levenshtein gibi uzaklıklar, sayısal analiz için de frekans ve oranlar kullanılır.

Dersin merkezindeki konu dizi hizalamadır. Nokta matrisi görsel bir ilk bakış verir ve kayan pencereyle gürültüden arındırılır. Dinamik programlama ise hizalamayı nesnel olarak bulur; global, yerel (Smith-Waterman) ve örtüşme türleri yalnız başlangıç ve özyineleme kurallarıyla ayrılır. İkiden fazla dizide çoklu hizalama sezgisel algoritmalarla ve çoğu zaman filogenetik bir yol gösterici ağaçla yapılır. İstatistik bütün bu adımların arkasında durur: ortalamalar, varyans, medyan ve bunlardan türeyen hareketli ortalama, hareketli fark ve medyan filtreleri biyoenformatik verilerin de işlenmesinde kullanılır. Ders, görselleştirmenin hatırlatılmasıyla kapandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
