# Ders 4 Genişletilmiş Notu: Kenar Bulma Tekrarı, İlgi Noktaları ve Harris Köşe Bulucusu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ödev Çözümleri Üzerinden Gauss Çekirdeği ve Ayrılabilir Filtreleme
- 2. Kenar Bulma Tekrarı: Türev ve Sobel Bulucusu
- 3. Canny Kenar Bulucusu
- 4. İlgi Noktaları ve İmgeler Arası Karşılık
- 5. İyi Özelliklerin Nitelikleri ve Özellik Bulucular
- 6. Harris Köşe Bulucusunun Temel Fikri
- 7. Görünüş Değişimi Fonksiyonu ve Taylor Açılımı
- 8. İkinci Moment Matrisi
- 9. İkinci Moment Matrisinin Yorumu: Elipsler, Özdeğerler ve Özvektörler
- 10. Köşe Cevap Fonksiyonu
- 11. Harris Algoritması ve Maksimum Olmayanların Bastırılması
- 12. Değişmezlik ve Eşdeğişkenlik
- Örnek Sorular
- Dersin Toparlaması

## 1. Ödev Çözümleri Üzerinden Gauss Çekirdeği ve Ayrılabilir Filtreleme

Ders, bir önceki haftanın Gauss filtresi ödevinin birkaç çözümüne birlikte bakılarak başladı. Bu bölümde yalnız akademik açıdan öğretici olan noktalar aktarılıyor.

### 1.1 İki boyutlu Gauss çekirdeğini kurmak

Bir çözümde iki boyutlu Gauss çekirdeği hazır bir Gauss filtresi kullanılmadan, `np.mgrid` ile kurulan koordinat ızgarası üzerinde doğrudan Gauss formülü hesaplanarak oluşturulmuştu. `mgrid`, koordinatları birer birer artırarak $x$ ve $y$ değerlerini matris biçiminde üretir; böylece formül bütün ızgaraya tek seferde uygulanır. Öğrenci formülde standart sapmanın karesi yerine doğrudan varyansı kullandığını söyledi; ikisi aynı şeydir.

Hoca, oluşturulan büyük çekirdeğin kenarlarında sıfıra çok yakın değerler olduğunu, bunlar atılarak örneğin $7\times7$ gibi daha küçük ve neredeyse aynı etkiyi veren bir filtre elde edilebileceğini belirtti.

Başka bir çözümde çekirdek iç içe iki döngüyle kurulmuştu. Hoca bunun çalıştığını ama istemediği bir yöntem olduğunu söyledi: bu tür işlemler `mgrid` gibi NumPy imkânlarıyla yapılmalı ki bu tarz (vektörel) programlamaya alışılsın.

> **Hocanın vurgusu:** Matris ve filtre işlemlerinde iki boyutlu döngü yazmayın, NumPy'ın vektörel imkânlarını kullanın.

### 1.2 Ayrılabilirlik ve delta imgesi

Çözümlerde şu deneyler yapılmıştı:

- Yatay bir boyutlu Gauss uygulanıp çıktısının üzerine dikey bir boyutlu Gauss uygulandığında, sonuç iki boyutlu Gauss uygulamakla aynı çıkar. İki bir boyutlu çekirdeğin matris (dış) çarpımı iki boyutlu çekirdeği verir; öğrenci farkı sıfır bulduğunu söyledi.
- $41\times41$ boyutunda, yalnız ortasında tek bir 1 bulunan bir imgeye (delta imgesi) filtre uygulanınca sonuç filtrenin kendisidir. Çünkü imge tek bir noktadan oluşur ve çıktı o noktaya yerleştirilmiş çekirdeğe dönüşür.
- Bir çözümde, kendi kurulan iki boyutlu çekirdekle önce bir Gauss, sonra ikinci bir Gauss art arda uygulanmış ve bu sonuç tek bir Gauss ile elde edilen sonuçla karşılaştırılmıştı. Sonuçlar yaklaşık %99 aynı çıktı; küçük fark büyük olasılıkla iki kütüphanenin arka plandaki farklı gerçekleştirmelerinden kaynaklanıyordu.

Hoca bu deneyden şu sonucu çıkardı: art arda uygulanan iki Gauss filtresinin varyansları toplanır.

<!-- BELİRSİZ: Öğrencinin bonus deneyindeki sigma değerleri altyazıda "3 sigma ve 5 sigma" ile "8 sigma" diye geçiyor; varyans toplamı kuralına göre bu değerlerin sigma değil varyans olması gerekir. Kodun karesi görülmedi. -->

### 1.3 Kitap okuma üzerine

Hoca, ders kitabı olarak kullanılan Szeliski'nin dünyada çok popüler ve bilgisayarla görme derslerinde yaygın olduğunu, ama yoğun, bol denklemli, çok hikâyeye girmeden kuralları veren, yüksek lisans ve doktora seviyesinde bir kitap olduğunu söyledi. Zor ama faydalı bir kaynak olarak nitelendirdi.

## 2. Kenar Bulma Tekrarı: Türev ve Sobel Bulucusu

Hoca, frekans alanında düşünme (Fourier dönüşümü) ve kenar bulma konularını ayrıntılı anlatmadı; bu konuların Szeliski'de Fourier dönüşümü (Bölüm 3.4) ve kenar bulma (Bölüm 7.2) kısımlarında okunabileceğini belirtti (ekrandan, 02:50:00). Ardından kenar bulmayı tablet üzerinde kısaca tekrar etti.

### 2.1 Kenar nedir?

Bir resimde bir nesne düşünelim. Kenarlar nesnenin sınırlarıdır. Hoca öğrencilere kenarların ne olduğunu sordu; cevap "büyük renk değişimlerinin olduğu yerler" oldu. Türev de değişimin miktarı olduğu için kenar bulma esasen bir türev operatörünün imge üzerinde çalıştırılmasıdır.

İmgede $x$ yönündeki birim değişim bir pikseldir, daha küçük bir değişim yoktur. Bir piksel ilerleyince rengin ne kadar değiştiğini döndüren bir işlem yaptığınızda kenar bulucu yapmış olursunuz.

### 2.2 Sobel kenar bulucusu

Geçen hafta görülen Sobel kenar bulucusu tahtaya şöyle yazıldı (ekrandan, 00:40:00):

$$
\begin{bmatrix}1&-1\\2&-2\\1&-1\end{bmatrix}
$$

Hoca bunu iki parçanın birleşimi olarak açıkladı: $[1\;-1]$ asıl türevi alan kısım, $[1\;2\;1]^T$ ise yumuşatan kısımdır. $[1\;2\;1]$'e dikkatle bakılırsa çok basitleşmiş bir Gauss gibi düşünülebilir. Yani Sobel, yumuşatıp türev alan bir operatördür.

> **Ders sonrası not:** Hoca Sobel'i tahtada $3\times2$ bir matris olarak yazdı. Literatürde yaygın Sobel çekirdeği büyük olasılıkla merkez farkı $[1\;0\;-1]$ ile kurulan $3\times3$ biçimdir: $\begin{bmatrix}1&0&-1\\2&0&-2\\1&0&-1\end{bmatrix}=[1\;2\;1]^T[1\;0\;-1]$ (dış çarpım python ile kontrol edildi). Hoca dersin ilerisinde $x$ türevi için $[+1\;0\;-1]$'i kullandı.

Sobel'in $x$ yönündeki bu versiyonu gibi $y$ yönündeki versiyonu da vardır: satırlar $1,2,1$ ve $-1,-2,-1$ olacak biçimde, yani yukarıdakinin transpozu. İki çekirdek de çalıştırılınca elde iki türev olur: $x$ yönündeki türev $d_x$, $y$ yönündeki türev $d_y$.

### 2.3 Türevin büyüklüğü ve yönü

$d_x$ ve $d_y$ birlikte düşünülürse o noktadaki asıl türev vektörü bulunur; hoca buna $d_t$ dedi. $d_x$ ve $d_y$ bu vektörün bileşenleridir. Hoca vektör büyüklüğünün nasıl hesaplandığını sordu: bileşenlerin kareleri alınıp toplanır ve karekök alınır.

$$
|d_t|=\sqrt{d_x^2+d_y^2}
$$

$d_x$ ve $d_y$ tek boyutlu olduğu için kendi büyüklükleri kendileridir. Büyüklüğün yanında ek bir bilgi daha vardır: vektörün yönü. $d_x$ ve $d_y$'nin miktarlarına göre $d_t$'nin yönü değişir. Vektörün $x$ ekseniyle yaptığı açı (oryantasyon, $\theta$) da kenar hakkında bilgi taşır. Canny bu bilgileri daha akıllıca nasıl kullanabileceğini düşünmüştür.

## 3. Canny Kenar Bulucusu

Canny çok popüler ve iyi çalışan bir kenar bulucudur. Bir kenar bulma uygulamanız varsa doğrudan Canny'i çalıştırabilirsiniz; MATLAB'da `edge(image, 'canny')` yazmak yeterlidir, Python'da da hazır gerçekleştirmeleri bulunur. Slayttaki adımlar (ekrandan, 00:45:00):

1. İmgeyi Gauss'un $x$ ve $y$ türevleriyle filtrele. Hocaya göre bu esasen az önceki Sobel ile türevleri bulmak demektir.
2. Gradyanın büyüklüğünü ve yönünü (oryantasyon) bul.
3. Maksimum olmayanları bastır (non-maximum suppression): birkaç piksel genişliğindeki kenar "sırtlarını" tek piksel genişliğe indir.
4. Eşikleme ve bağlama (histerezis): bir alçak, bir yüksek eşik tanımla; kenar eğrilerini başlatmak için yüksek eşiği, sürdürmek için alçak eşiği kullan.

### 3.1 Maksimum olmayanların bastırılması

Türevler alındığında kenarlar çoğu zaman yan yana bitişik, birkaç piksel genişliğinde alanlar olarak çıkar. Canny bunları önce tek piksele indirir. Bir komşulukta her pikselin büyüklüğü farklıdır; en büyük olan tutulur, diğerleri atılır.

Hoca bir örnek kurdu. Bitişikliği kaybetmemek için işlem yalnız $x$ yönünde, üçlü komşuluklarda yapılabilir. Bir satırda büyüklükler $5, 60, 8$ ise en büyük değer 60 olduğu için yalnız 60 kalır. Alttaki satırda $5, 10, 3$ varsa yalnız 10 kalır. Bu şekilde satır satır ilerleyerek Canny kenarları inceltir.

### 3.2 Histerezis eşiklemesi

Son adımda bir eşikleme yapılır, ama doğrudan "eşiğin altındakileri çöpe at" biçiminde değil. Hoca derste ayrıntısını tam hatırlayamadığını, zekice bir eşik sistemi olduğunu ve öğrencilerin bakmasını söyledi. Slaytta yazan (ekrandan, 00:50:00): gradyanın maksimum değerinin yeterince büyük olduğu kontrol edilir; kenarda kopmalar (drop-out) olmaması için histerezis kullanılır, yani kenar eğrileri yüksek eşikle başlatılır ve alçak eşikle sürdürülür. Slayttaki çizimde kalın gösterilen kısımlar yüksek eşiği geçen yerlerdir; ince kısımlar alçak eşiğin üstünde kaldıkları için kenara bağlanır.

## 4. İlgi Noktaları ve İmgeler Arası Karşılık

Arayı izleyen bölümde günün asıl konusu olan ilgi noktaları ve köşeler (interest points and corners) anlatıldı. Konu Szeliski'nin 4.1. bölümünde (kitabın yeni taslağında 7.1) yer alır.

### 4.1 Amaç: karşılık bulma

Bilgisayarla görmedeki amaçlardan biri farklı açılardan çekilmiş, hatta farklı resimlerde bulunan benzer şeyleri eşleyebilmektir. Slayttaki örnekte (ekrandan, 01:05:00) iki farklı stop levhası fotoğrafındaki "TO" bölgeleri birbirine çok benzer: karşılık (correspondence), imgeler arasında noktaları, yamaları (patch), kenarları ya da bölgeleri eşlemektir. Bu tür eşlemelerle:

- Aynı sahnenin farklı açılardan çekilmiş iki resmini birbirine dönüştüren dönüşüm bulunabilir.
- Aynı nesnenin farklı açılardan fotoğrafları birleştirilerek üç boyutlu bir nesne elde edilebilir.

Bu işlerde özellik noktaları (feature points) kullanılır. Bunlara bazen ilgi noktası (interest point), bazen anahtar nokta (keypoint), bazen yalnız özellik (feature) denir. Bu derste noktalar, bir sonraki derste ise küçük özellik alanları, yani ilgi bölgeleri (interest regions) anlatılacak.

### 4.2 İlgi noktası nedir?

İlgi noktasının kesin bir matematiksel tanımı yoktur. İmgeyi biraz döndürdüğünüzde, biraz küçülttüğünüzde, hafif bir perspektif dönüşümünden geçirdiğinizde hâlâ kolaylıkla bulunabilen, hâlâ dikkat çeken noktalara ilgi noktası denir. Hoca bir resim üzerinde böyle olduğunu düşündüğü noktaları gösterdi: belirgin, çevresinden kendini fark ettiren noktalar.

### 4.3 Anahtar nokta eşlemenin genel akışı

Slayttaki akış (ekrandan, 01:10:00):

1. Ayırt edici (distinctive) anahtar noktalardan bir küme bul.
2. Her anahtar noktanın çevresinde bir bölge tanımla.
3. Normalize edilmiş bölgeden yerel bir tanımlayıcı (local descriptor) hesapla.

Slaytta orijinal ve dönmüş iki imgede $A_1, A_2, A_3$ ve $B_1, B_2, B_3$ noktaları, bu noktaların çevresindeki bölgelerden çıkarılan $f_A$ ve $f_B$ histogramları gösteriliyor. Mantık şudur: bu özellik şu özelliğe benziyorsa, bu bölge de o bölgeye benziyordur, dolayısıyla burası orası olabilir.

Anahtar noktaların tekrarlanabilir (başka bir imgede de bulunabilen) ve ayırt edici (gözle görülebilen, çevresinden ayrışan) olması gerekir. Değişmez yerel özellikler (invariant local features) yaklaşımında ise noktaların çevresindeki bölgeler belirli normalizasyonlardan geçirilerek standart sayılabilecek bir biçime çevrilir. Başka imgelerdeki bölgeler de aynı biçime çevrilince kolayca eşlenebilir.

### 4.4 Örnek uygulama: panorama birleştirme

Aynı yerin iki resmi olsun ve bir kısmı ortak olsun. İki imgeyi birleştirmek için önce iki imgede ilgi noktaları bulunur. Sonra her noktanın çevresini tarif eden bir özellik çıkarılır; buna özellik tanımlayıcı (feature descriptor) denir ve nokta çevresinden bir dizi (vektör) elde edilir. En son iki imge arasında bu tanımlayıcılar eşlenir.

İki imge arasında birbiriyle eşlenebilecek binlerce nokta çıkar. Bu yüzden iki imge binlerce farklı biçimde birbirine oturtulabilir ve bunların hangisinin daha iyi olduğuna karar vermek gerekir. Sorun, çok fazla özellik olmasıdır. Kalitesiz, bir resimde olup diğerinde olmayan noktalar seçilirse bunlar gereksiz yere eşlenir ve karşılık hipotezlerinin çoğu yanlış olur. Bu nedenle rastgele her noktayı seçmek yerine iyi noktaları seçmek daha mantıklıdır.

## 5. İyi Özelliklerin Nitelikleri ve Özellik Bulucular

### 5.1 İyi özelliklerin nitelikleri

Slayttaki ilk iki nitelik (ekrandan, 01:15:00):

- **Tekrarlanabilirlik (repeatability):** Aynı özellik, geometrik ve fotometrik dönüşümlere rağmen birkaç imgede bulunabilmelidir. Gözle görebiliyor olmamız yetmez; algoritmanın aynı noktayı yine çıkarabilmesi gerekir.
- **Ayırt edicilik (saliency):** Her özellik ayırt edici olmalıdır.

Hoca bunlara ek olarak şunları anlattı:

- **Az sayıda olma, verimlilik (compactness and efficiency):** Algoritma imgedeki piksel sayısından çok daha az özellik çıkarmalı ki sonraki aşamalardaki algoritmalar hızlı sonuç verebilsin.
- **Yerellik (locality):** Özellik küçük bir alanı temsil etmeli. Böylece örtüşmeden (occlusion), yani imgedeki nesnelerin birbirini örtmesinden kurtulunur; nesnenin bir kısmı örtülse bile küçük alanlardan çıkarılan noktalarla büyük nesneler hâlâ tanımlanabilir.

Hoca iki kötü ve iyi örneği karşılaştırdı: az sayıda ve tamamen alakasız noktalar çıkarsa, yani bir imgede bulunan nokta diğerinde bulunamazsa, düzgün bir eşleme yapma şansı yoktur. Aynı nokta iki imgede de çıkarsa en azından bir şans vardır. Küçük geometrik değişikliklere ya da ışıklandırmayla ilgili (fotometrik) küçük değişikliklere rağmen kendini koruyan özelliklere ihtiyaç vardır; buna değişmezlik (invariance) denir.

### 5.2 Özellik bulucular

Bu özellikleri bulan algoritmalara özellik bulucu (feature detector) denir ve çok sayıda bulucu vardır. Hoca şunları saydı:

- Harris bulucusu: temel bir bulucudur, bu derste görülecek.
- Hessian bulucusu: o da temeldir.
- Bunları temel alan Harris-Laplace, Hessian-Laplace, Harris-Affine, Hessian-Affine gibi bulucular.
- MSER (Maximally Stable Extremal Regions).

Hoca bugün çok daha fazla bulucu bulunduğunu söyledi. Her bulucunun bulduğu bölge tipi farklıdır: Harris bir köşe bulucusudur, Hessian ise blob türü bölgeleri bulabilir.

<!-- BELİRSİZ: Altyazıda "Hesseyan boş bölgeleri bulabiliyor" geçiyor; bağlama göre "blob" olarak düzeltildi. -->

## 6. Harris Köşe Bulucusunun Temel Fikri

Slayttaki temel fikir (ekrandan, 01:20:00):

- Noktayı küçük bir pencereden bakarak kolayca tanıyabilmeliyiz.
- Pencereyi herhangi bir yönde kaydırmak parlaklıkta büyük bir değişime yol açmalı.

Hoca bunu türevle ilişkilendirdi: bölgeyi azıcık kaydırınca bile parlaklığın çok değişmesi, o noktada hem $x$ hem $y$ yönündeki türevin büyük olması demektir. Üç durum karşılaştırıldı:

- **Düz bölge:** pencere hangi yöne kaydırılırsa kaydırılsın altındaki piksel değerleri pek değişmez.
- **Kenar:** değişim yalnız bir yönde olur (yalnız $x$ ya da yalnız $y$ yönünde).
- **Köşe:** hangi yöne kaydırılırsa kaydırılsın büyük değişim olur.

Bu yaklaşım Harris ve Stephens'ın "A Combined Corner and Edge Detector" adlı oldukça eski, temel kabul edilen makalesine dayanır (ekrandan, 02:35:00; Proceedings of the 4th Alvey Vision Conference, s. 147-151, 1988). Makalenin gözlemi şudur: bir köşe etrafında imge gradyanı iki ya da daha fazla baskın yöne sahiptir. Hoca terimi de hatırlattı: tek boyutta türeve derivative, çok boyutta gradyan denir.

## 7. Görünüş Değişimi Fonksiyonu ve Taylor Açılımı

### 7.1 $E(u,v)$ fonksiyonu

$(x,y)$ noktası etrafındaki pencereye $w(x,y)$ diyelim. Bu pencere $(u,v)$ kadar kaydırılsın; örneğin $u=2$, $v=1$ ise pencere iki birim bir yönde, bir birim diğer yönde kayar. Pencerenin görünüşündeki değişim (buna enerji ya da görsel değişim de denebilir) şöyledir (ekrandan, 01:25:00):

$$
E(u,v)=\sum_{x,y} w(x,y)\,\big[I(x+u,y+v)-I(x,y)\big]^2
$$

Burada $I(x,y)$ parlaklık, $I(x+u,y+v)$ kaydırılmış parlaklıktır. İki boyutlu bir toplama vardır: kaydırılmış değerden mevcut değer çıkarılır, karesi alınır ve pencere fonksiyonuyla çarpılır. Hoca önce $w$'nin bir filtre gibi davrandığını fark etti; slaytta da $w$'nin pencere fonksiyonu olduğu, bir Gauss ya da kutu filtresi (box filter) olabileceği yazıyordu.

Merak edilen, bu fonksiyonun küçük $(u,v)$ kaymalarında nasıl davrandığıdır. Doğrudan hesaplamak çok yavaştır. Hoca slayttaki hesabı aktardı: $600\times600$'lük bir imge için $11\times11$'lik bir Gauss penceresi ve $11\times11$'lik bir kayma aralığı kullanılırsa yaklaşık 5 milyar hesaplama gerekir.

$$
600\cdot600\cdot(11\cdot11)\cdot(11\cdot11)=5\,270\,760\,000\approx 5\times10^{9}
$$

(çarpım python ile kontrol edildi).

### 7.2 Taylor serisi hatırlatması

Hızlandırmak için Taylor serilerine başvurulur (ekrandan, 01:30:00):

$$
f(x)=f(a)+\frac{f'(a)}{1!}(x-a)+\frac{f''(a)}{2!}(x-a)^2+\frac{f'''(a)}{3!}(x-a)^3+\cdots
$$

Bir noktadaki ($a$) fonksiyon değerini ve türevlerini biliyorsanız, hemen yakınındaki bir noktanın ($x$) değerini tahmin edebilirsiniz. Hoca, pratikte çoğu uygulamada birinci ya da ikinci türeve kadar gidildiğini, 3., 4., 5. türevlere kadar açılıma pek gerek duyulmadığını söyledi. Optimizasyon dersinde de Taylor serileri çok kullanılır ve orada da en fazla ikinci türeve kadar gidildiğini görmüştür.

$f(x)$'i doğrudan hesaplayamamanın çeşitli nedenleri olabilir. Optimizasyonda $x$ zaten tahmin edilir; bir $x$ tahmin edildikten sonra küçük adımlarla bir sonraki tahmine gidilir. Ya da buradaki gibi $f(x)$'i çok sayıda noktada doğrudan hesaplamak çok pahalıdır ve tahmin hız açısından yeterlidir.

Slayttaki örnek $e^x$'in $0$ civarındaki açılımıdır. $e^0=1$ bilinir. $e^x$'in türevi kendisi olduğu için birinci ve ikinci türevler de $0$'da 1'dir. Böylece hemen yakındaki bir değer tahmin edilebilir. Hoca "gerçek hayatta $e^{0{,}01}$'i nasıl bulacaksınız?" diye sordu; Taylor serisi bu soruya cevap verir (ara adım eklendi):

$$
e^{0{,}01}\approx 1+0{,}01+\frac{0{,}01^2}{2}=1{,}01005
$$

Gerçek değer $1{,}0100501\ldots$'dir (python ile kontrol edildi); ikinci dereceden açılım yedinci basamağa kadar doğrudur.

### 7.3 İki boyutlu açılım

$E(u,v)$ iki değişkenli olduğu için iki boyutlu Taylor açılımı gerekir. $(0,0)$ noktası etrafında, yani şu an düşünülen piksele $(0,0)$ diyerek, ikinci dereceden açılım şöyledir (ekrandan, 01:35:00):

$$
E(u,v)\approx E(0,0)+[u\;\;v]\begin{bmatrix}E_u(0,0)\\E_v(0,0)\end{bmatrix}+\frac12\,[u\;\;v]\begin{bmatrix}E_{uu}(0,0)&E_{uv}(0,0)\\E_{uv}(0,0)&E_{vv}(0,0)\end{bmatrix}\begin{bmatrix}u\\v\end{bmatrix}
$$

Bir boyutlu açılımla karşılaştırınca:

- $a$ burada $(0,0)$ alınmıştır; $x-a$ yerine $[u\;v]$ gelir.
- Birinci türevin yerini gradyan ($\nabla E$) alır: $u$ yönündeki türev ve $v$ yönündeki türevden oluşan vektör.
- İkinci türevin yerini Hessian ($\nabla^2 E$) alır. İki kere türev alındığında iki yönden ikişer değer gelir, dört değer bir matris oluşturur. $\tfrac12$ çarpanı bir boyutlu açılımdaki $2!$'den gelir.

Bu çarpımlar yapılırsa $u^2$, $v^2$ ve $uv$ içeren bir polinom çıkar; ama matris biçimi hem daha kolay anlaşılır hem de ileride matris özellikleri kullanılacaktır.

Hessian'ın köşegeninde $u$ yönünde ikinci türev ve $v$ yönünde ikinci türev vardır. Köşegen dışında önce $u$'ya sonra $v$'ye göre ve önce $v$'ye sonra $u$'ya göre türevler bulunur. Türev alma sırası sonucu değiştirmediği için bu ikisi eşittir; dolayısıyla Hessian simetriktir, transpozu kendisine eşittir.

### 7.4 Neden yalnız ikinci dereceden terim kalır?

Slayt şunu söylüyor (ekrandan, 01:40:00): $E(0,0)$ her zaman 0'dır ve birinci türev de 0'dır. İlki açıktır: kayma yoksa fark yoktur. Hoca birinci türevin neden sıfır olduğunu öğrencilere sordu ve sonra kendisi açıkladı: $E_u$ hesaplandığında ifadede $I(x+u,y+v)-I(x,y)$ farkı çarpan olarak kalır; $u=v=0$ konunca bu fark sıfır olur, dolayısıyla $E_u(0,0)=E_v(0,0)=0$ olur. İkinci türev ifadelerinde ise bu farkı içeren terim yine sıfıra giderken yanında sıfıra gitmeyen bir terim daha vardır; slayt yalnız geride kalan kısımları yazmıştır.

> **Ek bilgi (derste anlatılmadı):** Slayttaki ara türevler büyük olasılıkla şu biçimdedir: $E_u(u,v)=\sum 2w(x,y)\,[I(x+u,y+v)-I(x,y)]\,I_x(x+u,y+v)$ ve $E_{uu}(u,v)=\sum 2w\,I_x(x+u,y+v)^2+\sum 2w\,[I(x+u,y+v)-I(x,y)]\,I_{xx}(x+u,y+v)$. $(0,0)$'da köşeli parantezli fark sıfır olduğundan $E_u(0,0)=0$ ve $E_{uu}(0,0)=\sum 2w\,I_x^2$ kalır; benzer biçimde $E_{vv}(0,0)=\sum 2w\,I_y^2$, $E_{uv}(0,0)=\sum 2w\,I_xI_y$ olur.

<!-- BELİRSİZ: Ara türevlerin gösterildiği slaytın karesi elde yok (kareler 5 dakikada bir alınmış); yukarıdaki ek bilgi bloğu altyazıdaki anlatımdan kurulmuştur. -->

Sonra $\tfrac12$ ile ikinci türevlerdeki 2 sadeleşir ve yalnız Hessian'lı kısım kalır. Kalan ifadede $I_x$ $x$ yönündeki türev, $I_y$ $y$ yönündeki türev, $w$ ise yerel komşuluk fonksiyonu (Gauss) olur.

## 8. İkinci Moment Matrisi

Böylece ikinci dereceden yaklaşım şuna sadeleşir (ekrandan, 01:45:00):

$$
E(u,v)\approx[u\;\;v]\;M\begin{bmatrix}u\\v\end{bmatrix},\qquad
M=\sum_{x,y} w(x,y)\begin{bmatrix}I_x^2&I_xI_y\\I_xI_y&I_y^2\end{bmatrix}
$$

$M$ Hessian'dan yola çıkarak elde edilen bir matristir ve ikinci moment matrisi (second moment matrix) adını alır. Hoca bu matrise başka yerlerde de rastladığını söyledi.

### 8.1 Bütün imge için hesaplama

Matris her piksel için hesaplanmalıdır, ama bu oldukça kolaydır:

1. İmgeyi $[+1\;\;0\;\;-1]$ ile konvolüsyona sokmak bütün imge için $x$ yönündeki türevleri hızlıca verir.
2. Bu çekirdeğin transpozuyla konvolüsyon $y$ yönündeki türevleri verir.
3. Bu iki sonuç bileşen bileşen (eleman eleman) çarpılarak $I_x^2$, $I_y^2$ ve $I_xI_y$ elde edilir. Bunların her birine birer imge gibi bakılabilir.
4. Bu imgelerin üzerinde bir Gauss gezdirilir (pencere fonksiyonu $w$).

Hoca, Gauss'u ayrıca gezdirmek yerine Sobel'in içindeki yumuşatmanın ($1,2,1$) da kullanılabileceğini, bunun $3\times3$'lük bir komşuluk demek olduğunu, daha büyük komşuluklar için farklı bir şey yapmak gerektiğini ama mantığın aynı olduğunu söyledi.

### 8.2 Gradyan ile yazılış

Literatürde $M$'nin ayrılabildiği fark edilmiştir. $I_x$ ve $I_y$ bir sütun vektörü olarak düzenlenirse (ekrandan, 02:05:00):

$$
M=\begin{bmatrix}\sum I_xI_x&\sum I_xI_y\\\sum I_xI_y&\sum I_yI_y\end{bmatrix}=\sum\begin{bmatrix}I_x\\I_y\end{bmatrix}[I_x\;\;I_y]=\sum\nabla I\,(\nabla I)^T
$$

$[I_x\;I_y]$ yerel gradyandır. İmgenin yerel gradyanı transpozuyla çarpılıp (dış çarpım) yerel olarak toplanırsa $M$ elde edilir.

### 8.3 Örnek imgeler

Slayttaki örnekte orijinal bir resim, $x$ yönündeki türevi, $y$ yönündeki türevi ve ikisinin çarpımı gösterildi. Hoca $I_y$ imgesinde yatay yapıların, $I_xI_y$ imgesinde ise çaprazların öne çıktığını belirtti. Her piksel için elde dört değer (matrisin dört elemanı) olur; soru, bunlardan yararlanarak köşeye nasıl karar verileceğidir.

## 9. İkinci Moment Matrisinin Yorumu: Elipsler, Özdeğerler ve Özvektörler

### 9.1 Elips olarak yorum

$[u\;v]M[u\;v]^T$ işlemi $u$ ve $v$'ye değer verildiğinde tek bir sayı üretir. Bu ifade Taylor yaklaşımından gelir. Hoca bunu sezgisel olarak şöyle açıkladı: tek boyutta ikinci dereceden Taylor yaklaşımı, fonksiyonun o noktasına bir parabol değdirmek gibidir. İki boyutta ise o noktaya bir yüzey (simetrik bir elipsoid biçimli yüzey) uydurulur.

Bu yüzey yatay olarak kesilirse elipsler elde edilir (ekrandan, 02:10:00): haritalardaki eş yükseklik çizgileri gibi. Yatay kesit şu denklemle verilir:

$$
[u\;\;v]\;M\begin{bmatrix}u\\v\end{bmatrix}=\text{sabit}
$$

Slayt bunun bir elips denklemi olduğunu söyler. Farklı sabitler için farklı elipsler çıkar. Dolayısıyla ikinci moment matrisi bize elipsler tanımlar.

### 9.2 Özdeğer ayrışımı

Matematikte matrisleri farklı matrislere bölen çeşitli ayrışımlar (bozunumlar) vardır; hoca SVD'yi hatırlattı. Slaytta $M$ köşegenleştirilerek $R^{-1}$, köşegende özdeğerler ve $R$ biçiminde yazılmıştı. Hoca öğrencilere özdeğer ve özvektörlerin nerede karşılarına çıktığını sordu; bir cevap PCA (temel bileşen analizi) oldu. Hoca buradaki işlemin PCA ile çok ilişkili olduğunu, PCA'da da özdeğer ve özvektörlerin bulunduğunu söyledi.

Hoca Szeliski'nin ekindeki (Appendix A, Linear Algebra and Numerical Techniques, A.1.2) özdeğer ayrışımı bölümünü gösterdi (ekrandan, 02:15:00 ve 02:20:00). Özdeğer ayrışımı simetrik matrislere uygulanır ve matrisi üç parçaya böler:

$$
C=U\Lambda U^T
$$

$\Lambda$ yalnız köşegen değerlere sahip bir matristir; köşegendeki $\lambda$'lara özdeğer (eigenvalue) denir. $U$ vektörlerden oluşan bir matristir; her özdeğere karşılık gelen bir vektör, yani özvektör (eigenvector) vardır. Üç matris çarpılınca orijinal matris elde edilir. Kitaptaki tanım denklemi (ekrandan, 02:20:00):

$$
\lambda_i u_i=Cu_i\quad\text{ya da}\quad(\lambda_i I-C)\,u_i=0,\qquad |\lambda I-C|=0
$$

Bu denklem homojendir; sıfırdan farklı çözümü ancak sistem rank eksikse, yani determinant sıfırsa vardır. Determinantın açılımı $\lambda$ cinsinden karakteristik bir polinom verir; $2\times2$ ya da $3\times3$ gibi küçük matrisler için kapalı biçimde çözülebilir. Hoca hesaplama ayrıntılarına girmedi: MATLAB'da ve Python'un bilimsel kütüphanelerinde ilgili fonksiyonlar vardır.

> **Hocanın vurgusu:** Önemli olan özdeğerlerin nasıl hesaplandığı değil, ne anlama geldikleri ve çeşitli uygulamalarda nasıl kullanılabilecekleridir.

### 9.3 Özdeğer ve özvektörlerin anlamı

Özdeğerler ve özvektörler, bahsedilen elipsin yönünü ve büyüklüğünü verir:

- Sabit belirli bir değere sabitlendiğinde, bir özdeğerin büyüklüğü elipsin karşılık gelen özvektör yönündeki yarı çapını belirler. Örneğin minimum özdeğer için $\left(\lambda_{\min}\right)^{-1/2}$, o özvektör yönündeki yarı çapı verir; benzer biçimde $\left(\lambda_{\max}\right)^{-1/2}$ diğer yöndeki yarı çaptır.
- Özvektörler eksenlerin yönünü verir. İki özvektör çıkar ve birbirine diktir.

Hoca bağlantıyı PCA ile kurdu: PCA'da özvektörler yeni bir koordinat sisteminin eksenlerini belirler ve eski koordinat sisteminden bu yeni sisteme izdüşüm yapılır. Burada da her özvektör elips için bir eksen verir. Bu eksenler ileride bir bölgeyi "doğru" yöne çevirmek için kullanılabilir.

> **Ders sonrası not:** Hoca özvektörlerin genel olarak birbirine dik olduğunu söyledi. Bu, büyük olasılıkla yalnız simetrik matrisler için geçerlidir (ikinci moment matrisi ve PCA'daki kovaryans matrisi simetriktir); genel bir kare matrisin özvektörleri dik olmak zorunda değildir.

### 9.4 Her piksel için bir elips

Slaytta bir imgenin her pikselinde ikinci moment matrisi bulunup aynı sabite eşitlenerek elipsler çizdirilmişti (ekrandan, 02:25:00). Rengin pek değişmediği sabit yerlerde elipsler küçük; bazı yerlerde daireye yakın, bazı yerlerde iyice uzamış çıkar. Yani her piksel için bir elips, dolayısıyla bir bölge tanımlanabilir; sabit büyütülüp küçültülerek daha büyük ya da daha küçük bölgeler elde edilir.

### 9.5 Özdeğerlere göre sınıflama

Harris ve Stephens pikselleri iki özdeğere bakarak sınıflamıştır:

- Özdeğerlerden biri diğerinden çok büyükse nokta genelde bir **kenardır**.
- Özdeğerler benzer boyutta ama küçükse orası **düz bölgedir** (küçük bir daire).
- Özdeğerler benzer boyutta ve büyükse orası bir **köşedir**.

## 10. Köşe Cevap Fonksiyonu

Özdeğer temelli bir köşe bulucu kurulabilir, ama iş orada bitmez: özdeğer hesaplaması pahalıdır. $600\times600$'lük bir imgedeki her pikselde özdeğer hesaplamak gerekir. Bu yüzden Harris ve Stephens özdeğerlere benzer davranan, hesaplaması basit bir fonksiyon önermiştir: köşe cevap fonksiyonu (corner response function), $R$ (ekrandan, 02:30:00):

$$
R=\det(M)-\alpha\,\mathrm{trace}(M)^2=\lambda_1\lambda_2-\alpha(\lambda_1+\lambda_2)^2
$$

$\alpha$, 0,04 ile 0,06 arasında bir sabittir. Slayttaki $(\lambda_1,\lambda_2)$ düzlemi diyagramına göre:

- **Kenar:** $R<0$ (bir özdeğer diğerinden çok büyük).
- **Düz bölge:** $|R|$ küçük (iki özdeğer de küçük).
- **Köşe:** $R>0$ ve büyük (iki özdeğer de büyük).

Determinant ve iz özdeğerler bulunmadan doğrudan matris elemanlarından hesaplanır. Hoca hatırlattı: $\begin{bmatrix}a&b\\c&d\end{bmatrix}$ için determinant köşegen çarpımlarının farkı $ad-bc$, iz ise köşegen elemanlarının toplamı $a+d$'dir. Bu yüzden $R$ çok hızlı hesaplanır. Özdeğerlerin çarpımının determinanta, toplamının ize eşit olması bu kısayolu mümkün kılar.

> **Ek bilgi (derste anlatılmadı):** $\det(M)=\lambda_1\lambda_2$ ve $\mathrm{trace}(M)=\lambda_1+\lambda_2$ eşitlikleri her kare matris için geçerlidir; bu yüzden $R$ özdeğerleri açıkça hesaplamadan aynı bilgiyi verir.

## 11. Harris Algoritması ve Maksimum Olmayanların Bastırılması

### 11.1 Adımlar

Slayttaki özet (ekrandan, 02:35:00):

1. Her imge penceresi için $M$ matrisini hesapla ve köşelik (cornerness) puanını bul.
2. Çevresindeki pencere büyük köşe cevabı veren ($R>$ eşik) noktaları bul.
3. Yerel maksimum noktalarını al, yani maksimum olmayanları bastır (non-maximum suppression).

### 11.2 Non-maximum suppression örneği

Eşikten geçen pikseller çoğu zaman yan yana çıkar: birbirine bitişik birçok pikselin köşe cevabı yüksektir. Hoca öğrencilere bu durumda ne yapılacağını sordu: yan yana olan bu piksellerden en yüksek değerli olan seçilir, bitişik olanlar atılır.

Hoca tablete sayılarla bir ızgara yazdı ve $3\times3$ komşulukla tek tek değerlendirdi:

- Köşede duran 32 değerini, ızgaranın kenar pikseli olduğu için (tam bir komşuluğu olmadığından) seçmemeyi tercih etti; hangisinin daha doğru olduğundan emin olmadığını da söyledi.
- 32'nin komşuluğundaki değerlerden hiçbiri 32'den büyük olmadığı için bunlar seçilmez, atılır.
- Bir 6 değerine baktı: kendi komşuluğunda en büyük olmadığı için seçilmedi. Bir alt satırdaki 7 ve 12 de kendi komşuluklarında en büyük değildi.
- 16 ise kendi komşuluğundaki en büyük piksel olduğu için seçildi; komşuluğundaki diğerleri atıldı.

<!-- BELİRSİZ: Izgaranın tam değerleri altyazıda "13, 8, 6, 7, 5, 4, 2, 16, 20, 32, 1, 8, 6, 2, 7, 3, 5, 6, 2, 1, 0, 12" diye okunuyor; tabletteki el yazısı karede (02:35:00) seçilemiyor, satır-sütun düzeni kurulamadı. -->

Sonuçta elde yalnız "kendi komşuluğunda kral olan", yani komşuluğunun en büyüğü olan pikseller kalır. Komşuluk $3\times3$ seçilebileceği gibi $5\times5$ de seçilebilir; farklı uygulamalar için farklı komşuluklar uygundur.

### 11.3 Orijinal makaledeki adım adım örnek

Hoca makaledeki resimler üzerinden adımları izledi: orijinal resim, $I_x$, $I_x^2$; ardından $g(I_x^2)$, yani Gauss ile yumuşatılmış hâli; yumuşatılmış hâllerden ikinci moment matrisi; sonra determinant ve iz ile köşe cevabı $R$; $R$'nin eşikten büyük olduğu noktalar; en son non-maximum suppression ile her bölgeden yalnız bir noktanın kaldığı sonuç (ekrandan, 02:40:00).

## 12. Değişmezlik ve Eşdeğişkenlik

Makaledeki iki başlangıç resmi birbirinin aynısı değildir. Hoca aradaki farkları sordu ve kendisi sıraladı (ekrandan, 02:40:00):

- Fotometrik fark: farklı ışıklandırma durumları.
- Dönme: nesne düzlem içinde biraz dönmüş.
- Bakış açısı farkı: kamera bir kez düz, bir kez biraz açılı çekmiş.

Bu küçük farklılıklara rağmen birçok köşe iki imgede de uygun yerlerde bulunur. Bazı noktalar ise bakış açısından dolayı bir imgede varken diğerinde kaybolur ya da bulunamaz.

Burada iki kavram vardır:

- **Değişmezlik (invariance):** İmgeye bir dönüşüm uygulandığında köşelerin yeri değişmiyorsa buna değişmezlik denir.
- **Eşdeğişkenlik (covariance):** İmge dönüştürüldüğünde noktalar dönüşmüş imgede karşılık gelen yerlerde hâlâ bulunabiliyorsa buna eşdeğişkenlik denir.

Köşelerin hem değişmez hem eşdeğişken olması istenir. Hocaya göre Harris köşeleri bu bakımdan oldukça iyidir. Slaytta bir sonraki konu olarak parlaklıktaki afin değişime (affine intensity change) karşı davranış vardı; hoca bu kısmı geçti.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:40:50): Bir imgede kenar nedir ve kenar bulma neden türevle yapılır?

> **Cevap (derste verildi):** Kenarlar büyük renk/parlaklık değişimlerinin olduğu yerlerdir. Türev değişimin miktarıdır; imgede birim adım bir piksel olduğundan, bir piksel ilerleyince parlaklığın ne kadar değiştiğini veren bir türev operatörü kenarları ortaya çıkarır.

**Soru 2** (derste sözlü, 00:42:50): $x$ ve $y$ yönündeki türevler $d_x$ ve $d_y$ ise o noktadaki türev vektörünün büyüklüğü nasıl hesaplanır?

> **Cevap (derste verildi):** Bileşenlerin kareleri toplanıp karekök alınır: $|d_t|=\sqrt{d_x^2+d_y^2}$. Yön, vektörün $x$ ekseniyle yaptığı açıdır. Örneğin $d_x=3$, $d_y=4$ için büyüklük 5'tir (python ile kontrol edildi).

**Soru 3** (derste sözlü, 01:31:43): $e^{0{,}01}$ değeri Taylor serisiyle nasıl yaklaşık bulunur?

> **Cevap (derste kısmen verildi, sayısal sonuç eklendi):** $e^x$'in $0$ civarında açılımı kullanılır; $e^0=1$ ve bütün türevler $0$'da 1'dir: $e^{0{,}01}\approx1+0{,}01+0{,}01^2/2=1{,}01005$. Gerçek değer $1{,}0100501\ldots$ (python ile kontrol edildi).

**Soru 4** (derste sözlü, 01:38:20; ekrandan, 01:40:00): $E(u,v)$'nin $(0,0)$ etrafındaki ikinci dereceden Taylor açılımında birinci türev terimi neden sıfırdır?

> **Cevap (derste verildi):** $E_u$ ve $E_v$ ifadelerinde $I(x+u,y+v)-I(x,y)$ farkı çarpan olarak bulunur. $u=v=0$'da bu fark sıfırdır, dolayısıyla birinci türevler sıfırdır. $E(0,0)$ da kayma olmadığından sıfırdır. Geriye yalnız Hessian'lı (ikinci dereceden) terim kalır ve bu $[u\;v]M[u\;v]^T$'yi verir.

**Soru 5** (derste sözlü, 02:31:33): $2\times2$ bir matrisin determinantı ve izi nedir, köşe cevap fonksiyonunda neden kullanılır?

> **Cevap (derste verildi):** $\begin{bmatrix}a&b\\c&d\end{bmatrix}$ için $\det=ad-bc$, $\mathrm{trace}=a+d$. Bunlar özdeğerlerin çarpımına ve toplamına eşittir; özdeğer hesaplamadan $R=\det(M)-\alpha\,\mathrm{trace}(M)^2$ hızlıca bulunur. Örneğin $M=\begin{bmatrix}4&1\\1&2\end{bmatrix}$ için özdeğerler $3\pm\sqrt2\approx4{,}414$ ve $1{,}586$; çarpımları $7=\det M$, toplamları $6=\mathrm{trace}\,M$ (python ile kontrol edildi).

**Soru 6** (derste sözlü, 02:34:04): Köşe cevabı eşikten geçen ve yan yana duran pikseller için non-maximum suppression yapılınca hangileri kalır?

> **Cevap (derste verildi):** Her piksel kendi komşuluğuyla ($3\times3$ ya da $5\times5$) karşılaştırılır; yalnız komşuluğunun en büyüğü olan pikseller kalır, diğerleri atılır. Derste 16 değeri komşuluğunun en büyüğü olduğu için tutuldu, 6, 7, 12 gibi değerler atıldı. Canny'deki örnekte de $5, 60, 8$ üçlüsünden 60, $5, 10, 3$ üçlüsünden 10 kalır.

**Soru 7** (derste sözlü, 02:38:30): Harris makalesindeki iki örnek imge arasında hangi farklar vardır ve Harris köşeleri bunlara karşı nasıl davranır?

> **Cevap (derste verildi):** Işıklandırma (fotometrik) farkı, düzlem içi dönme ve bakış açısı farkı vardır. Birçok köşe iki imgede de karşılık gelen yerlerde bulunur; bazıları bakış açısı yüzünden kaybolur. Harris köşeleri değişmezlik ve eşdeğişkenlik bakımından oldukça iyidir.

**Soru 8** (ekrandan, 02:50:00): Harris köşe bulucusunu yazın. Bir imgeye uygulayın. Bulunan köşeleri gösterin. İkinci moment matrisinin özvektörleri kullanılarak tanımlanan elipsleri gösterin. (Derste belirtilen kısıtlar: Harris'i doğrudan veren bir kütüphane kullanılmaz; ikinci moment matrisi ve türev filtrelemeleri kendiniz hesaplanır; matris işlemleri iki boyutlu döngü yerine NumPy ile yapılır; yalnız filtreleme için hazır fonksiyon kullanılabilir.)

> **Çözüm (derste verilmedi):** Aşağıdaki NumPy taslağı ajan tarafından yazıldı ve python ile test edildi; derste yazılmadı. $60\times60$'lık siyah bir zemin üzerinde $20\times20$'lik beyaz bir kare için tam olarak dört köşe $(20,20)$, $(20,39)$, $(39,20)$, $(39,39)$ bulundu; kenar üzerinde $R<0$, düz iç bölgede $R=0$ çıktı.

```python
import numpy as np
from numpy.lib.stride_tricks import sliding_window_view

def filtrele(img, k):
    """Kenarı kopyalayarak doldurup çekirdekle ilinti (korelasyon) uygular."""
    ky, kx = k.shape
    p = np.pad(img, ((ky // 2, ky // 2), (kx // 2, kx // 2)), mode="edge")
    pencereler = sliding_window_view(p, k.shape)
    return np.einsum("ijkl,kl->ij", pencereler, k)

def gauss(sigma):
    r = int(3 * sigma)
    x, y = np.mgrid[-r:r + 1, -r:r + 1]
    g = np.exp(-(x**2 + y**2) / (2 * sigma**2))
    return g / g.sum()

def harris(img, alpha=0.05, sigma=1.5, esik_orani=0.01):
    img = img.astype(np.float64)
    kx = np.array([[1.0, 0.0, -1.0]])          # x yönünde türev
    Ix, Iy = filtrele(img, kx), filtrele(img, kx.T)
    g = gauss(sigma)                            # pencere fonksiyonu w(x, y)
    Sxx, Syy, Sxy = filtrele(Ix * Ix, g), filtrele(Iy * Iy, g), filtrele(Ix * Iy, g)
    R = (Sxx * Syy - Sxy**2) - alpha * (Sxx + Syy)**2   # det(M) - alpha trace(M)^2
    komsu_max = sliding_window_view(np.pad(R, 1, mode="constant", constant_values=-np.inf), (3, 3)).max(axis=(2, 3))
    kose = (R > esik_orani * R.max()) & (R == komsu_max)  # eşik + 3x3 non-max suppression
    return R, np.argwhere(kose), (Sxx, Sxy, Syy)
```

> Elips için bulunan her köşede $M=\begin{bmatrix}S_{xx}&S_{xy}\\S_{xy}&S_{yy}\end{bmatrix}$ kurulur ve `np.linalg.eigh(M)` ile özdeğer ve özvektörler alınır. Elipsin yarı eksenleri $\sqrt{c/\lambda_i}$ (seçilen sabit $c$), yönleri ise özvektörlerdir; $c$ büyütülerek daha büyük elipsler çizilebilir.

## Dersin Toparlaması

Ders, kenar bulmanın bir türev işlemi olduğunu hatırlatarak başladı: Sobel türevi bir yumuşatmayla birleştirir, $d_x$ ve $d_y$'den kenarın büyüklüğü ve yönü elde edilir; Canny ise bu bilgiyi non-maximum suppression ile tek piksel genişliğe indirir ve histerezis eşiklemesiyle kopmaları azaltır. Ardından imgeler arası karşılık bulma problemi ve bunun için gereken iyi özelliklerin nitelikleri (tekrarlanabilirlik, ayırt edicilik, az sayıda olma, yerellik) ele alındı.

Dersin ağırlığı Harris köşe bulucusundaydı. Pencere kaydırıldığında görünüşün ne kadar değiştiğini ölçen $E(u,v)$, Taylor açılımıyla $[u\;v]M[u\;v]^T$ biçimine indirildi. İkinci moment matrisi $M$ her piksel için bir elips tanımlar; özvektörler elipsin yönünü, özdeğerler büyüklüğünü verir. İki büyük özdeğer köşeyi, tek büyük özdeğer kenarı, iki küçük özdeğer düz bölgeyi gösterir. Özdeğer hesaplamanın maliyetinden kaçınmak için $R=\det M-\alpha\,(\mathrm{trace}\,M)^2$ kullanılır; eşikleme ve non-maximum suppression ile köşeler seçilir. Bir sonraki derste noktalar yerine küçük ilgi bölgelerinin (interest regions) ve yerel tanımlayıcıların ele alınacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
