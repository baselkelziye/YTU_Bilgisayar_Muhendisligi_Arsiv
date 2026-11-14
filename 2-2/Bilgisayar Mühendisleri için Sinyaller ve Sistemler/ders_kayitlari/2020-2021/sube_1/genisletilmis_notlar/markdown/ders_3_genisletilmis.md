# Ders 3 Genişletilmiş Notu: Sinyal İşlemleri, Periyodik Sinyaller, Karmaşık Sayılar, Enerji ve Güç, Temel Sinyaller ve Birim Dürtü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bellek Birimlerinde Büyük B ve Küçük b
- 2. Zamanda Ölçekleme: Germe, Sıkıştırma ve İnterpolasyon
- 3. Yan Örnek: Yaya Işıkları Arasındaki Kablo
- 4. Zamanda Tersleme
- 5. Zamanda Öteleme: Gecikme ve Öne Alma
- 6. İşlemlerin Birleştirilmesi: $x(2t-1)$
- 7. Periyodik Sinyaller
- 8. Karmaşık Sinyaller ve İntegral Dönüşümleri
- 9. Karmaşık Sayılar ve Euler Formülü
- 10. Sinyallerde Enerji ve Güç
- 11. Temel Sinyaller: Sinüzoidler
- 12. Üstel Sinyaller ve Sönümlü Sinüzoidler
- 13. Birim Basamak Fonksiyonu
- 14. Dikdörtgen, Rampa ve Üçgen Sinyalleri
- 15. Temel Sinyallerle Karmaşık Sinyal Kurmak
- 16. Birim Dürtü
- 17. Dürtünün Özellikleri
- 18. Dürtü İçeren İntegraller
- 19. Dürtünün Fiziksel Yorumu
- 20. Dürtü İçeren Bir Sinyalin İntegrali ve Türevi
- 21. Slaytlar Üzerinden Tekrar ve Yeni Kavramlar

## 1. Bellek Birimlerinde Büyük B ve Küçük b

Hoca konuya dönmeden önce bellek birimlerini kısaca hatırlattı. Tahtadaki birimleri sorduğunda sınıftan "megabayt" ve "kilobit" cevapları geldi. Bu birimler bilgisayar bilimlerine giriş ve yapısal programlama derslerinde görülmüştür. Karıştırılan nokta, büyük B ile küçük b arasındaki farktır: MB megabayt, kb kilobittir. Hoca bu farka dikkat edilmesini istedi.

## 2. Zamanda Ölçekleme: Germe, Sıkıştırma ve İnterpolasyon

Bir önceki derste ölçekleme (scale) işleminde kalınmıştı. Genlikte ve zamanda ölçekleme görülmüştü. Bu işlemler hem sürekli hem de ayrık sinyallerde yapılabilir.

Zaman değişkeni 0 ile 1 arasında bir sayıyla, örneğin $1/2$ ile çarpılıyorsa bu işleme **germe** (expansion, stretching) denir. Tersine, sinyal daralıyorsa **sıkıştırma** (compressing) denir.

Germe sırasında yeni örnek noktaları oluşur. Bu nedenle germede upsampling yapılır. Upsampling'in bir yolu da sayısal analizde görülen **interpolasyondur**: iki değerin arasına bir değer kurmak. Birkaç yöntem vardır:

- İki komşu örneğin genlik değerlerinin doğrudan ortalaması alınır.
- Ağırlıklı ortalama alınır.
- Komşu noktalardan kuadratik, kübik gibi bir interpolasyon eğrisi geçirilip aradaki değer tahmin edilir.

Tahmin edilen değer her zaman gerçeği tam yansıtmaz. Daha önce müziği yavaşlattığımızda duyduğumuz değerler de böyleydi. Yine de boş kalan yeri sıfır bırakmak bir kopukluk demektir; interpolasyon bunun yerine yumuşak bir geçiş sağlar.

Hocanın benzetmesi yoldaki çukurdur. Düz giden yolda bir çukur açıldığında teker boşluğa düşer ve bu çok rahatsız edicidir. Bu yüzden çukur bir dolgu malzemesiyle doldurulur. Dolgu orijinal yolun aynısı değildir, ama geçişi düzeltir.

## 3. Yan Örnek: Yaya Işıkları Arasındaki Kablo

Yol örneği hocaya başka bir sinyal örneğini hatırlattı. Caddenin iki yanındaki yaya trafik ışıklarının arasında asfaltta çoğu zaman küçük bir oyuk vardır ve üzeri kapatılmıştır. Oyukta iki ışığı bağlayan bir kablo bulunur. Bu kablo iki ışık arasında haberleşme sağlayabilir, ama ayrıca sinyal de alınır.

Kablodan geçen manyetik alan, üzerinden geçen araçlar nedeniyle bozulur. Manyetik alan bozulduğu sürece sistem trafik akışının sürdüğü sonucunu çıkarır. Manyetik alan giriş olarak alınır. Sistemin elinde bir şimdiki değer $x[n]$, bir de önceki değer $x[n-1]$ vardır. Bu değerler karşılaştırılarak akışın sürüp sürmediği denetlenir.

## 4. Zamanda Tersleme

Zamanda tersleme (time reversal) de sürekli ve ayrık sinyallerde yapılır. Aslında bir ölçekleme işlemidir, fakat ölçek $-1$'dir. Önceki ölçeklemelerde negatif sayı kullanılmamıştı; burada işaret de işin içine girer.

Sinyaldeki her örnek, zamandaki tam ters noktasına gider: $t=5$ noktasındaki değer $t=-5$ noktasına gelir. Ayrık örnekte $-4$'teki örnek $+4$'e, $+4$'teki örnek $-4$'e gider.

**Soru:** Sinyal $-4$ ile $+4$ arasında değil de $-4$ ile $+2$ arasında olsaydı, terslenince indisleri ne olurdu?

**Cevap:** $-2$ ile $+4$ arasında olur. $+2$'deki örnek $-2$'ye, $-4$'teki örnek $+4$'e gider.

Hoca, slaytta ayrık sinyalin yatay ekseninde $t$ yazmaması gerektiğini de belirtti. Ayrık sinyalde yatay eksen $n$'dir. Slaytlar kitabın slaytları olduğu için kitaptaki bir hata slayda da geçebilir.

## 5. Zamanda Öteleme: Gecikme ve Öne Alma

Zamanda öteleme (time shifting) iki biçimdedir: **gecikme** (delay) ve **öne alma** (advance).

**Gecikme:** $x(t-t_1)$, $t_1>0$. Örneğin $x(t-1)$'de sinyal bir birim ötelenir. Parantez içindeki eksi işareti sola değil, pozitif yöne, yani sağa gidişi gösterir.

**Öne alma:** $x(t+t_1)$, $t_1>0$. Hoca "advance" kelimesinin burada "ileri" diye çevrilmesinin yanıltıcı olduğunu, doğru karşılığın "öne almak" olduğunu söyledi. Günlük dildeki "in advance" (önceden) kalıbını hatırlattı. Öne alınmış sinyal, bazı şeyleri önceden bilen, önceden sahip olan bir sinyal veya sistem gibi düşünülecektir. Örneğin $x(t+1)$'de sinyal bir birim sola kayar.

Çizim için pratik bir yöntem vardır: Parantezin içini sıfır yapan değeri bulun. $x(t-1)$ için $t-1=0$, yani $t=1$'dir. Sinyalin $t=0$ noktası artık $t=1$'e taşınmıştır ve çizim oradan yapılır. $x(t+1)$ için çizim $t=-1$ noktasından başlar.

Aynı işlem ayrık sinyalde de vardır, yalnız örnekler birer birer ilerler. Hocanın gösterdiği örnekte sinyal bazı noktalarda 0, sonra 1, 2, 1 değerlerini alıyordu. $x[n-1]$ bir birim sağa, $x[n+1]$ bir birim sola kaymış sinyaldir.

<!-- BELİRSİZ: Ayrık öteleme örneğinin 1, 2, 1 değerlerinin hangi indislerde olduğu altyazıda söylenmiyor. -->

### 5.1 Ok İşaretiyle Verilen Ayrık Sinyal

Ayrık sinyal bazen indis bilgisi olmadan bir dizi olarak verilir ve $n=0$ noktası bir işaretle gösterilir. İşaret alta veya üste konabilir, ok da olabilir. Diğer indisleri kendiniz doldurursunuz.

Hocanın örneği: $x[n]=\{\dots,0,5,\underset{\uparrow}{7},3,\dots\}$. İşaret 7'nin altındadır.

- $x[0]=7$
- $x[1]=3$
- $x[-1]=5$
- $x[-2]=0$

## 6. İşlemlerin Birleştirilmesi: $x(2t-1)$

> **Hocanın vurgusu:** Ölçekleme, öteleme ve terslemenin birleştirilmesi önemlidir. İşlemler herhangi bir sırayla yapılabilir, ama sıraya dikkat edilmezse karışıklık çıkar.

Bir $x(t)$ sinyali verildiğinde onu bir sayıyla çarpıp öteleyebilir, genliğinde de değişiklik yapabiliriz. Hocanın örneği $x(2t-1)$'dir.

**Önce ölçekleme, sonra öteleme.** $x(t)$'den $x(2t)$ elde edilir, yani sinyal 2 ile sıkıştırılır. Ardından öteleme yapılır. Dersin sonunda slayda dönüldüğünde hoca bunun doğru miktarını açıkça verdi: $2t-1$ içinde 1 değil, $1/2$ ötelenir. Çünkü

$$x\left(2\left(t-\tfrac12\right)\right)=x(2t-1).$$

**Önce öteleme, sonra ölçekleme.** $x(t)$ bir birim geciktirilir ve $x(t-1)$ bulunur. Sonra 2 ile sıkıştırılır, yani $t$ yerine $2t$ yazılır: $x(2t-1)$. Hoca kendi tercihinin bu sıra olduğunu söyledi. Genlikte de bir işlem varsa, örneğin başa $A$ veya 5 geliyorsa, o en sona bırakılabilir.

**Yanlış olan yol.** Karışıklık matematikteki parantez önceliği gibi düşünmekten doğar. $x(2t)$ elde edildikten sonra sinyali 1 birim ötelemek $x(2t-1)$ vermez. Çünkü üzerinde çalışılan sinyal artık $x(t)$ değil, $x(2t)$'dir ve öteleme $t$ değişkenine uygulanır:

$$x(2(t-1))=x(2t-2).$$

Hoca bu noktayı $x(2t-2)$ üzerinden de gösterdi: $x(2t-2)$ istiyorsak önce iki birim öteleyip sonra iki ile sıkıştırırız. Sıkıştırmada $t=2$'deki değer $t=1$'e, $t=1$'deki değer $t=0{,}5$'e gelir.

> **Ders sonrası not:** Hoca derste bir yerde "önce öteleme" yolunu yanlışmış gibi anlattı, sonra da kendi tercihinin önce öteleme olduğunu söyledi. Doğrusu şudur: iki sıra da doğrudur, yeter ki her adım $t$ değişkeninin yerine yazılarak yapılsın. Bir test sinyaliyle Python'da $x(t-1)\big|_{t\to2t}$ ile $x(2t)\big|_{t\to t-1/2}$ aynı çıktı. $x(2t)\big|_{t\to t-1}$ ise $x(2t-2)$'ye eşit çıktı.

Hoca alıştırma olarak aynı $x(t)$ üzerinden şu dalga biçimlerinin çizilmesini istedi: $x(-t/2)$, $x(2t+2)$, $x(-t+1)$. Bunlara daha sonra toplu örnek çözümünde dönülecek.

<!-- BELİRSİZ: Slayttaki x(t) şeklinin kırılma noktaları altyazıda tam verilmiyor. Bu yüzden alıştırmaların dalga biçimleri burada çizilmedi. -->

## 7. Periyodik Sinyaller

> **Hocanın vurgusu:** Periyodik sinyaller bu derste çok önemlidir. Frekans analizinde ve Z dönüşümünde periyodik sinyaller için genel yöntemlerden daha özel durumlar konuşulacak. Çünkü sinyalin tamamını $-\infty$ ile $+\infty$ arasında analiz etmek yerine bir periyodunu analiz etmek aynı şeyi ifade eder.

Bir sinyalin periyodik olması için öyle bir $T_0$ bulunmalıdır ki **her** $t$ için

$$x(t)=x(t+T_0)$$

sağlansın. Eşitliği bozan tek bir $t$ bile varsa sinyal o $T_0$ ile periyodik değildir. Ayrık durumda aynı şart bir $N_0$ için ve bütün $n$ değerleri için aranır: $x[n]=x[n+N_0]$.

Bu şartı sağlayan en küçük $T_0$ veya $N_0$ **temel periyottur**. Temel periyottan **temel frekansa** (fundamental frequency) geçilir:

$$f_0=\frac{1}{T_0}\quad\text{veya}\quad f_0=\frac{1}{N_0}.$$

### 7.1 Temel Periyodu Bulmak Neden Zor?

**Soru:** Temel frekansı bulmak neden zor olabilir? Formülde yalnız $1/T_0$ var.

**Cevap:** Sınıftan gelen "genlik" cevabı doğru değildir, formülde genlik yok. Bölme kolaydır, zor olan $T_0$'ı bulmaktır. Elinizde bir dizi vardır. Ayrık uzayı düşünelim. Bir $N_0$ değeri seçer, örneğin 3, 5 veya 7, bütün $n$ değerleri için eşitliğe bakarsınız. Sağlamıyorsa başka değer denersiniz. Periyot negatif olamayacağı için 1'den başlar, 2'yi, 3'ü denersiniz. Sinyal çok uzunsa belki milyon tane deneme gerekir, arama sonsuza kadar da gidebilir. Bunun için algoritma yazmak bayağı uğraştırır.

Bunun yerine frekans düzlemine geçilir. Sinyalin frekans bileşenleri bulunur, doğrudan $f_0$ elde edilir, oradan da $T_0=1/f_0$'a gidilir. Bu, frekans düzlemine geçmenin kolaylıklarından biridir. Hoca bu geçişin maliyetini "en iyi durumda $n\log n$ veya $n^2$" diye verdi.

> **Ders sonrası not:** Bu iki maliyet büyük olasılıkla iki farklı hesap içindir: $n\log n$ hızlı Fourier dönüşümünün (FFT), $n^2$ ise ayrık Fourier dönüşümünün doğrudan hesabının maliyetidir.

### 7.2 Öteleme ve Periyodik Genişletme

Slayttaki periyodik sinyalde herhangi bir noktaya bir periyot eklendiğinde aynı değere ulaşılır. Sinyali ötelediğimizde yalnızca belli bir kayma olur, periyodiklik aynen kalır. En yaygın periyodik sinyaller sinüs ve kosinüstür. Özellikle kosinüsü çok kullanacağız.

Bir periyottan yola çıkarak sinyali **periyodik genişletme** (periodic extension) ile çoğaltabiliriz. Hocanın örneği müziktir: Sevdiğiniz bir parçanın bir kısmının sürekli çalmasını istiyorsanız o kısmın örneklerini alır, uç uca eklersiniz. Biter, tekrar başlar. Bazı müzik çalarlarda bir aralık seçilip sonsuz döngüye alınabilir. Arka planda olan şey budur.

Periyodik olmayan bir sinyal için ise iki yol anıldı:

- Sinyali olabilecek en küçük parçalara bölüp periyodik olabilecek parçaları tespit etmek ve oradan periyotlar oluşturmak.
- Fourier analizinde yapılacağı gibi, sinyalin başından sonuna tamamını tek bir periyotmuş gibi kabul etmek. Bu bir varsayımdır ve analiz onun üzerine kurulur.

## 8. Karmaşık Sinyaller ve İntegral Dönüşümleri

Bu ders asıl olarak sinyallerin sınıflandırılması, sinyal ve sistem kavramları üzerinedir. Karmaşık sinyaller üzerinde işlem yapmak daha çok DSP veya ileri sinyal işleme derslerinin konusudur. Yine de birkaç temel bilgi gerekir.

Karmaşık sinyal, aynı değişkene bağlı iki bileşeni olan bir sinyaldir: gerçel (real) bileşen ve sanal (imaginary) bileşen. İkisi de $t$'ye göre değişir, ama ikinci bileşen sanaldır:

$$x(t)=x_r(t)+jx_i(t).$$

Karmaşık sinyaller radar, sonar, ultrason ve haberleşmede, ayrıca bazı sinüzoidal sinyallerin gösteriminde karşımıza çıkar. Hocanın örneği yoldaki radardır: Radar karmaşık bir sinyal gönderir ve araca çarpıp dönen sinyali alır. Orada iki bileşenli **quadrature sinyal** mantığı kullanılır. Hoca, yaklaşan araçtan sinyalin "daha hızlı, daha şiddetli" döndüğünü söyledi.

> **Ders sonrası not:** Hocanın "daha hızlı" ve "daha şiddetli" dediği etki büyük olasılıkla Doppler kaymasıdır: yaklaşan hedeften dönen dalganın frekansı yükselir. Radar hızı dönen sinyalin şiddetinden değil, bu frekans farkından bulur.

### 8.1 Fourier Dönüşümü Neden Karmaşıktır?

Fourier dönüşümü karmaşık bir dönüşümdür. Sinyali sinüs ve kosinüs bileşenlerine ayırdığımızda gerçel kısmın ve sanal kısmın bileşenlerini elde ederiz. Dönüşüm şöyledir:

$$F(\omega_0)=\int_{-\infty}^{\infty}f(t)\,e^{-j\omega_0t}\,dt,\qquad \omega_0=2\pi f_0.$$

$j$ sabit bir sayıdır, $\sqrt{-1}$'dir. Değişkenler $\omega_0$ (frekansa göre değişir) ve $t$'dir. İntegralin değişkeni $t$'dir. Integrandda $j$ bulunduğu için sonuç da karmaşıktır.

> **Ders sonrası not:** Hoca sonucun "real kısmını kullanıyoruz" dedi. Dönüşümün sonucu genel olarak karmaşıktır, gerçel bir sinyalde bile sanal kısım sıfır olmayabilir (Python'da denendi). Bu yüzden yalnız gerçel kısım yeterli değildir. Büyük olasılıkla pratikte genlik $|F(\omega)|$ ve faz birlikte kullanılır.

### 8.2 İntegral Dönüşümü

Fourier'in amacı sinyali frekanslarına ayırmaktır ve bu bir **integral dönüşümüdür**. Hoca genel biçimi şöyle kurdu: $\varphi$'ye bağlı bir fonksiyon, hem $\alpha$'ya hem $\varphi$'ye bağlı bir $\mu(\alpha,\varphi)$ fonksiyonuyla çarpılıp $\varphi$'ye göre integre edilir:

$$F(\alpha)=\int f(\varphi)\,\mu(\alpha,\varphi)\,d\varphi.$$

$\varphi$ integrasyonda gider, sonuç yanındaki diğer değişken $\alpha$'ya bağlı kalır. Yani $\alpha$ yeni boyutu gösterir. Matematikte integral dönüşümleri adıyla ders ve kitaplar vardır, Fourier bunlardan biridir. Fourier'de fonksiyon $t$'ye bağlıdır, dönüşüm fonksiyonu $e^{-j\omega t}$'dir ve sonuç $\omega$'ya veya $f$'ye göre dönüşmüş bir $F$ olur.

## 9. Karmaşık Sayılar ve Euler Formülü

Karmaşık sayıları burada karmaşık sinyalleri incelemek için değil, asıl olarak sinüzoidal sinyalleri incelemek için öğreniyoruz.

Karmaşık sayı, doğrudan gerçel çözümü bulunamayan durumlarda ortaya çıkan bir sayı türüdür. İki parçası vardır: gerçel kısım $x$ ve önünde $j$ işaretçisi bulunan sanal kısım $y$:

$$z=x+jy.$$

**Soru:** Mühendislikte neden $i$ yerine $j$ kullanıyoruz? İkisi de $\sqrt{-1}$.

**Cevap:** Devre teorisindeki Ohm kanunu $v(t)=i(t)R$'de $i$ akımı gösterir. Akımla karmaşık sayı gösterimi karışmasın diye mühendislikte $j$ kullanılır.

### 9.1 Kartezyen ve Kutupsal Gösterim

Bir karmaşık sayının iki gösterimi vardır: **kartezyen form** ve **kutupsal form** (polar form).

> **Ders sonrası not:** Hoca bir yerde $x+jy$ için "kutupsal form veya kartezyen form" dedi. $x+jy$ kartezyen formdur. Kutupsal form $re^{j\varphi}$'dir.

Düzlemde yatay eksen gerçel, dikey eksen sanal eksendir. Bunlar kosinüs ve sinüs eksenleri diye de düşünülebilir. Gerçel eksene $x$'in sayısal değeri, sanal eksene $y$'nin sayısal değeri işaretlenir. Eksene $j$ yazılmaz.

<!-- BELİRSİZ: Hocanın tahtada gösterdiği sayı altyazıda "3 artı 6i veya 6j" ve "3 artı artı j" diye geçiyor. Sayı kesin okunmadığı için burada hesap yapılmadı. -->

Noktayı orijine birleştiren doğrunun uzunluğu Pisagor bağıntısından, açısı karşının komşuya oranından gelir:

$$r=\sqrt{x^2+y^2},\qquad \tan\varphi=\frac{y}{x},\qquad \varphi=\arctan\frac{y}{x}.$$

Hoca önce açıyı "$y/x$" diye yazmıştı. Bir öğrencinin uyarısı üzerine bunun açının tanjantı olduğunu, açının sayısal değeri için arktanjant gerektiğini söyleyerek düzeltti.

> **Ders sonrası not:** Hoca $r$ için "$x^2+y^2$" dedi; doğrusu kareköklü $\sqrt{x^2+y^2}$'dir. Altyazıda "Psevur bağıntısı" diye geçen ad da Pisagor bağıntısıdır. Ayrıca $\arctan(y/x)$ yalnız birinci ve dördüncü bölgede doğrudur. İkinci ve üçüncü bölgede açı $\pi$ kadar yanlış çıkar (Python'da `arctan` ve `arctan2` karşılaştırıldı). Genel durumda iki argümanlı `atan2(y, x)` kullanılır.

$x=r\cos\varphi$ ve $y=r\sin\varphi$ yerine yazılınca kutupsal form çıkar:

$$z=r\cos\varphi+jr\sin\varphi=re^{j\varphi}=\sqrt{x^2+y^2}\;e^{j\arctan(y/x)}.$$

Toplama, çıkarma gibi işlemler bazı durumlarda kartezyen formda, çarpma ve bölme gibi işlemler kutupsal formda daha kolaydır. Hangisi kolaysa o forma geçilir. Formlar birbirine dönüştürülebilir, uzun ispatlara girmeye gerek yoktur.

### 9.2 Euler Formülü

Bu dönüşümün temeli Euler açılımıdır:

$$e^{jx}=\cos x+j\sin x.$$

Başına bir $A$ gelirse $Ae^{jx}=A\cos x+jA\sin x$ olur. Dersin geri kalanında bu daha çok zamana bağlı biçimiyle kullanılacak:

$$e^{j\omega t}=\cos\omega t+j\sin\omega t.$$

Karmaşık üstel $e^{z}$ için de, $z=x+jy$ ise

$$e^{z}=e^{x+jy}=e^{x}e^{jy}=e^{x}(\cos y+j\sin y).$$

### 9.3 Kosinüs ve Sinüsün Üstel Gösterimi

Hoca bunu "ileriye kalmasın" diyerek hemen türetti. Üsse herhangi bir şey yazılabilir, $\alpha$ diyelim:

$$e^{j\alpha}=\cos\alpha+j\sin\alpha,$$

$$e^{-j\alpha}=\cos\alpha-j\sin\alpha.$$

İki denklem taraf tarafa **toplanırsa** sinüsler birbirini götürür:

$$2\cos\alpha=e^{j\alpha}+e^{-j\alpha}\quad\Longrightarrow\quad\cos\alpha=\frac{e^{j\alpha}+e^{-j\alpha}}{2}.$$

İkinci denklem $-1$ ile çarpılıp toplanırsa, yani denklemler **çıkarılırsa**, kosinüsler gider:

$$2j\sin\alpha=e^{j\alpha}-e^{-j\alpha}\quad\Longrightarrow\quad\sin\alpha=\frac{e^{j\alpha}-e^{-j\alpha}}{2j}.$$

> **Hocanın vurgusu:** Sinyaller ve sistemlerde işinizi çok kolaylaştıracak üç formül budur: Euler formülü ve ondan türeyen kosinüs ve sinüs eşitlikleri. Bunları defterinize not edin, çok kullanacağız.

> **Ders sonrası not:** Hoca sinüs formülündeki $j$ için "sinüs kompleks bir şey gösteriyor" dedi. Formülün paydasında $j$ vardır, ama gerçel $\alpha$ için sonuç gerçeldir. Payda ve paydaki $j$ birbirini götürür. Kosinüs ve sinüs eşitlikleri Python'da rastgele $\alpha$ değerleriyle doğrulandı.

**Neden işe yarar?** Hocanın örneği şu integraldir:

$$\int\cos\alpha\;e^{\alpha}\,d\alpha.$$

Normalde bu çarpım için kısmi integrasyon (integration by parts) yaparsınız. Oysa $\cos\alpha$ yerine üstel gösterimi yazıp üstlü sayılarda çarpma yapınca kısmi integrasyona gerek kalmaz. Hoca sonucu hesaplamadı. Kalan adımlar şöyledir (ara adım eklendi):

$$\int\cos\alpha\;e^{\alpha}\,d\alpha=\frac12\int\left(e^{(1+j)\alpha}+e^{(1-j)\alpha}\right)d\alpha=\frac12\left(\frac{e^{(1+j)\alpha}}{1+j}+\frac{e^{(1-j)\alpha}}{1-j}\right)+C=\frac{e^{\alpha}(\cos\alpha+\sin\alpha)}{2}+C.$$

Bu sonuç Python'da sayısal olarak doğrulandı.

## 10. Sinyallerde Enerji ve Güç

### 10.1 Fiziksel Örnekten Tanıma

Slaytta konu bir akım örneğiyle açılıyor. $i(t)$ bir akım sinyali, $R$ sabit bir direnç ise, açığa çıkan enerji akımın karesi çarpı direncin integralidir:

$$E=\lim_{T\to\infty}\int_{-T}^{T}i^2(t)R\,dt.$$

Akım değişken, $R$ sabittir. Birim jouledür. $T$'yi sonsuza göndermek aslında $-\infty$ ile $+\infty$ arasında integral almak demektir. Direnç 1 ohm alınırsa $R$ formülden çıkar ve $\int i^2(t)\,dt$ kalır.

Hoca hesap mantığını $i(t)=t^2$ üzerinden anlattı. Önce kare alınır: $i^2(t)=t^4$. Sonra integrali alınır: $\int t^4dt=t^5/5$. Sonra sınırlar yerine konur. Hoca sınırları yerine koyup bitirmedi. Kalan adım şöyledir (ara adım eklendi):

$$\int_{-T}^{T}t^4\,dt=\frac{2T^5}{5}\;\xrightarrow{\,T\to\infty\,}\;\infty.$$

Karmaşık sinyalde genliğin karesi alınır. Gerçek uygulamalarda her zaman 1 ohmluk bir direnç kullanılmadığı için bu büyüklük gerçek (actual) enerji değildir. Yine de birçok yerde sinyalin enerjisi olarak şu fonksiyonu kullanacağız:

$$E=\int_{-\infty}^{\infty}|x(t)|^2\,dt.$$

> **Ders sonrası not:** Hoca karmaşık sinyal için "magnitude yani real kısmını" dedi. Bu ikisi aynı değildir. Enerjide gerçel kısmın değil, genliğin karesi kullanılır: $|x(t)|^2=x(t)x^*(t)$.

### 10.2 Güç

Sinyalin zamana göre ortalama enerjisi gücünü verir. Enerjiyi aralığın uzunluğuna böleriz. Aralık $-T$ ile $T$ arasındaysa uzunluk $2T$'dir:

$$P=\lim_{T\to\infty}\frac{1}{2T}\int_{-T}^{T}|x(t)|^2\,dt.$$

Sınırlar $-T/2$ ve $T/2$ yazılırsa önündeki katsayı $1/T$ olur. Hoca bunun hiçbir şey değiştirmediğini söyledi.

**Soru:** Enerji formülünde neden doğrudan $-\infty$, $+\infty$ değil de limitli $-T$, $T$ yazılıyor? Fark eder mi?

**Cevap:** İkisi de aynıdır, enerji hesabında çok sorun olmaz. Limitli yazımın nedeni, sinyalin sonsuz uzunlukta olabilmesi ve içinde kritik nokta (süreksizlik) bulunabilmesidir. Süreksizlik içeren integrallerde de benzer bir limit alınır:

- Süreksizlik $a$ noktasındaysa $a$ integrale dahil edilmez. $a$'dan biraz sonraki nokta alınır: $\displaystyle\lim_{\tau\to0^+}\int_{a+\tau}^{b}$.
- Süreksizlik $b$ noktasındaysa $b$'den biraz önceki nokta alınır: $\displaystyle\lim_{\tau\to0^+}\int_{a}^{b-\tau}$.
- Her iki uçtaysa ikisi birlikte uygulanır: $\displaystyle\lim_{\tau\to0^+}\int_{a+\tau}^{b-\tau}$.

### 10.3 Ayrık Zamanda Enerji ve Güç

Ayrık zamanda integral kullanılamaz, toplam sembolü kullanılır. Buradaki sonsuzluktan kastımız sinyalin nereden başlayıp nerede bittiğidir:

$$E=\sum_{n=-\infty}^{\infty}|x[n]|^2.$$

**Örnek.** Hoca $x[n]$'in $n=1,2,3$ noktalarında $1,2,3$ değerlerini aldığı sinyali verdi.

- Verilen: $x[1]=1$, $x[2]=2$, $x[3]=3$.
- Enerji: $E=\sum_{n=1}^{3}x^2[n]=1^2+2^2+3^2=1+4+9=14$.
- Ortalama enerji: Hoca enerjinin üçe bölünmesini söyledi. $14/3\approx4{,}67$ (ara adım eklendi).

> **Ders sonrası not:** $14/3$, üç örnek üzerindeki ortalamadır. Sinyal yalnız bu üç örnekten ibaretse, limitli güç tanımı $P=\lim_{N\to\infty}14/(2N+1)=0$ verir, yani sinyal bir enerji sinyalidir. $14/3$ ancak bu üç değer periyodik olarak tekrar ediyorsa sinyalin gücüdür (Python ile hesaplandı).

Ayrık zamanda güç için de limit alınır. Burada $N$ periyodun karşılığıdır:

$$P=\lim_{N\to\infty}\frac{1}{2N+1}\sum_{n=-N}^{N}|x[n]|^2.$$

**Soru:** $-N$ ile $+N$ arasında kaç indis vardır?

**Cevap:** $2N+1$ tane. $N$'ler dahildir ve arada 0 da vardır. Bu yüzden $2N$'e değil, $2N+1$'e bölünür.

### 10.4 Enerji Sinyali, Güç Sinyali

> **Hocanın vurgusu:** Bu üç kavramı anahtar kelime gibi bilmelisiniz.

- **Enerji sinyali:** $0<E<\infty$, yani enerji sabit bir sayıdır. Bu durumda $P=0$'dır.
- **Güç sinyali:** $0<P<\infty$. Bu durumda $E=\infty$'dur.
- **Ne enerji ne güç sinyali:** Yukarıdaki iki koşul da sağlanmıyorsa.

Periyodik bir sinyalde bir periyot boyunca inceleme yapmak yeterlidir.

> **Ders sonrası not:** Hoca periyodik sinyal için "enerji sinyali ise gücü sıfırdır, güç sinyali ise enerjisi sonsuzdur" diye genel sınıflandırmayı tekrar etti. Sıfırdan farklı bir periyodik sinyal sonsuz kez tekrar ettiği için toplam enerjisi sonsuzdur, enerji sinyali olamaz. Bir periyodundaki enerji sonluysa sinyal güç sinyalidir. Yukarıdaki $i(t)=t^2$ örneği ise periyodik değildir. Bu örnekte $E=\infty$, ayrıca $P=\lim_{T\to\infty}T^4/5=\infty$ çıkar, yani sinyal ne enerji ne güç sinyalidir (hesaplandı).

## 11. Temel Sinyaller: Sinüzoidler

Buraya kadar sinyallerin özelliklerini gördük, sistemlere daha gelmedik. Şimdi temel sinyal türlerini öğreneceğiz. Herhangi bir sinyali temel sinyaller cinsinden yazabilir hale geleceğiz. Bu da sinyal analizinde ve bilgi çıkarmada çok kolaylık sağlar.

### 11.1 Sürekli Sinüzoid

Adı sinüzoid olsa da bu sinyaller kosinüs üzerinden tanımlanır:

$$x(t)=A\cos(\omega t+\varphi).$$

- $A$: genlik.
- $\omega=2\pi f$: açısal frekans. Birimi radyan/saniyedir.
- $f$: frekans. Birimi hertzdir.
- $\varphi$: faz veya faz açısı. Radyan cinsindendir.
- $T=2\pi/\omega$: periyot. Saniye cinsindendir.

Birimin nereden geldiğini görmek için $f$ yerine $1/T$ yazılır: $\omega=2\pi/T$. $2\pi$ radyana karşılık geldiği için sonuç radyan/saniyedir.

> **Hocanın vurgusu:** Birimleri yazmak önemlidir. Açısal frekans sorulduğunda radyan/saniye, frekans sorulduğunda hertz yazılmazsa cevap eksik sayılır. Neyi yazdığınızı bilmeniz gerekir.

Kaynaklarda $\omega$ da çoğu zaman "frekans" diye anılır. Hocanın deyişiyle sinyalciler için açısal da olsa normal de olsa frekans frekanstır. Yine de $\omega$'yı radyal frekans diye bilmek daha doğrudur.

### 11.2 Faz ve Sinüs ile Kosinüs İlişkisi

Kosinüs sinyali ötelendiğinde, önceki bölümde gördüğümüz gibi $t=0$ anındaki değer kayar. Faz, sinyalin $t=0$ anında nerede olduğunu gösterir. Faz sıfırsa $\cos0=1$'dir ve sinyal 1 değerinden başlar. Hoca bu nedenle kosinüsü sinüse göre daha düzenli bir başlangıç noktası saydı.

<!-- BELİRSİZ: Slaytta faz ile zaman kayması arasındaki ilişki (altyazıda "eksi omega t", "pi artı t") gösteriliyor, ama formülün tam biçimi altyazıdan okunmuyor. -->

Faz açısı $\pm90^\circ$ olursa kosinüs sinüse dönüşür. Bu nedenle sinüs kosinüsten türemiş kabul edilir.

> **Ders sonrası not:** İşaret önemlidir. $\cos(\omega t-\pi/2)=\sin\omega t$, $\cos(\omega t+\pi/2)=-\sin\omega t$ (Python ile doğrulandı).

### 11.3 Ayrık Sinüzoid ve Periyodiklik

Ayrık sinüzoid şöyle yazılır:

$$x[n]=A\cos(\Omega n+\varphi).$$

Yine genlik, frekans ve faz bilgisi vardır, ama $n$ yalnız tam sayı değerleri alır. Bazı kitaplarda frekans ve faz sembolleri farklı yazılır. Önemli olan orada bir faz olduğunu bilmektir.

**Örnek.** Hoca $x(t)=\cos(2500\pi t)$ sinyalini $f=500$ Hz ile örnekledi.

- Örnekleme periyodu $1/500$ s olduğu için $t$ yerine $n\cdot\frac{1}{500}$ yazılır.
- $x[n]=\cos\left(2500\pi\cdot\dfrac{n}{500}\right)=\cos(5\pi n)$. 500'ler sadeleşir.
- Yani $\Omega=5\pi$'dir.
- $2\pi/\Omega=2\pi/(5\pi)=2/5$ (ara adım eklendi). Bu rasyonel bir sayıdır, sinyal periyodiktir.

Rasyonel çıkmayan durumlar da olur, onlara ileride toplu örnekte dönülecek. Yanlış örnekleme sonucunda periyodik bir sinyalin periyodikliği yok edilebilir.

> **Ders sonrası not:** Hoca şartı önce "$2\pi/\Omega$ doğal sayıysa" diye söyledi, örnekte ise rasyonelliğe baktı. Doğrusu rasyonelliktir: $\Omega/2\pi=m/N$ sadeleşmiş kesir ise temel periyot $N$'dir. Burada $\Omega/2\pi=5/2$, yani $N_0=2$'dir. Gerçekten $\cos(5\pi n)=(-1)^n$ dizisi $1,-1,1,-1,\dots$ biçimindedir (Python ile doğrulandı).

> **Ek bilgi (derste anlatılmadı):** Örnekteki sinyalin frekansı $f=2500\pi/(2\pi)=1250$ Hz'dir. Örnekleme frekansı olan 500 Hz bunun altındadır. Bu yüzden $\cos(5\pi n)$ dizisi, 250 Hz'lik $\cos(2\pi\cdot250\,n/500)=\cos(\pi n)$ dizisiyle örnek örnek aynıdır (Python ile doğrulandı). Yani örneklemeden sonra özgün frekans diziden okunamaz.

### 11.4 Karmaşık Sinüzoid

Sinüzoidin sanal bileşen içeren hali de vardır. Bugün çok kullanılmayacağı için yalnız tanımı verildi. Euler formülünden:

$$Ae^{j(\omega t+\varphi)}=A\cos(\omega t+\varphi)+jA\sin(\omega t+\varphi).$$

Çoğu durumda gerçel kısım $A\cos(\omega t+\varphi)$ kullanılır, gerektiğinde sanal kısma geçilir. Slaytta gerçel kısım düz çizgiyle, sanal kısım kesikli çizgiyle çizilmiştir.

## 12. Üstel Sinyaller ve Sönümlü Sinüzoidler

Üstel sinyaller, üstel fonksiyonla tanımlanan sinyallerdir. Üsteki katsayı sinyali ya söndürür ya da sonsuza götürür.

**Soru:** $e^{t}$'nin $t\to\infty$ iken nereye gittiği ve $(-\infty,\infty)$ aralığında integralinin alınıp alınamayacağı soruldu.

**Cevap:** $e^t$ sonsuza gider. Bu ıraksak bir fonksiyondur. İntegral iki nokta arasında eğrinin altında kalan alandır, burada ise alan sürekli büyür. Bu integral alınamaz, sonucu çıkmaz. Fourier dönüşümünün aksadığı yer de budur. Onun yerine başka bir fonksiyon daha kullanılır, buna ileride gelinecek.

Üsteki parametreye göre iki tür ayrılır:

- **Üstel sönüm** (exponential decay): parametre negatiftir, örneğin $e^{-t}$, $e^{-2t}$. Hoca "azalan, bastırılan, yok olan" karşılıklarını saydı ve "sönümlenen" kelimesinin daha doğru olduğunu söyledi.
- **Üstel büyüme** (exponential growth): parametre pozitiftir, sinyal artar.

### 12.1 Sönümlü ve Büyüyen Sinüzoidler

Üstel sinyal ile kosinüs çarpılarak birleştirilir: $e^{at}\cos(\omega t)$. Kosinüs kendi içinde bir dalgadır. Pozitif üstel bileşen dalgayı büyütür. Negatif üstel bileşende ise negatif zamanda dalga büyük, pozitif zamanda sönümlenir ve $t\to\infty$ iken sıfıra gider.

Bunun nedeni $e^{-t}=1/e^{t}$ oluşudur. $t$ sonsuz olunca $1/\infty$ çıkar, ifade sıfıra gider ve çarpılan kosinüs de iyice sönümlenir. Tersine üs pozitifse değer sonsuza gider, alan sürekli artar. Bu durum yakınsak (convergent) değil, ıraksaktır (divergent).

> **Ders sonrası not:** Hoca bu kısımda birkaç kez kendini düzeltti. Doğrusu: $t\to\infty$ iken $e^{-t}\to0$, $e^{t}\to\infty$. Ayrıca $e^{-t}$ de $(-\infty,\infty)$ üzerinde integrallenemez, çünkü $t\to-\infty$ iken büyür. $\int_{-L}^{L}e^{-t}dt=e^{L}-e^{-L}$, $L$ ile ıraksar. Buna karşılık $\int_{0}^{\infty}e^{-t}dt=1$'dir (Python ile hesaplandı). Sönüm integralinin sonlu çıkması için sinyalin $t<0$ kısmı atılmalıdır. Bunun yolu Bölüm 13'teki $u(t)$ ile çarpmaktır.

Sönümlenen dalga devre teorisinde çok kullanılır. RL ve RC devrelerinin karakteristiği böyledir: bir yerden başlar, azalarak gider ve sıfırlanır.

### 12.2 Karmaşık Üstel Sinyaller

Karmaşık üstel, üstel bir sinyalle karmaşık bir sinyalin bir arada kullanılmasıdır:

$$e^{st}=e^{\sigma t}e^{j\omega t},\qquad s=\sigma+j\omega.$$

$e^{j\omega t}$'den kosinüs ve sinüs gelir. $e^{\sigma t}$ ise üstel kısımdır ve $\sigma$'nın değerine göre sinyali büyütür veya küçültür. Yatay ekseni $\sigma$, dikey ekseni $j\omega$ olan karmaşık düzlemde:

- $\sigma<0$ (sol taraf): azalan sinyaller.
- $\sigma>0$ (sağ taraf): artan sinyaller.

Slaytta sinüzoidal, üstel, karmaşık sinüzoidal sinyaller ve bunların üstelle farklı birleşimleri yan yana gösterilmiştir. Bu sinyallerin hepsinin ayrık hali de $n$'e bağlı olarak yazılabilir.

## 13. Birim Basamak Fonksiyonu

Birim basamak (unit step), sinüzoidler gibi temel bir fonksiyondur ve çok daha sık kullanacağız. Sürekli hali $u(t)$, ayrık hali $u[n]$ ile gösterilir:

$$u(t)=\begin{cases}1,&t\ge0\\0,&t<0\end{cases}$$

Ayrık halinde $n=0$'dan itibaren birler, öncesinde sıfırlar vardır.

**Soru:** $u(-t)$ nedir, nasıl çizilir?

**Cevap:** $t$ sıfırdan küçükken 1, sıfırdan büyükken 0'dır. Zamanda terslediğimiz için değer yine 1'dir, $-1$ değildir.

**Soru:** Başına bir eksi koysak ne olur? Bu genlikte yapılan bir işlemdir.

**Cevap:** Sol tarafta $-1$, sağ tarafta 0 olur. Sağ taraf zaten sıfırdır. Yani $-u(-t)$, $t\le0$ için $-1$, $t>0$ için 0'dır.

Hoca aynı çizim üzerinden iki değişiklik daha sordu. Sinyal 3 birim sola kaydırılırsa $-3$'ten sonrası tamamen sıfır olur, $-3$'ün solu $-1$'de kalır. Bu sinyal $-u(-(t+3))$'tür. Değer 1 yerine 5 alınırsa sol taraf $-5$'e iner: $-5u(-(t+3))$.

<!-- BELİRSİZ: Tahtaya yazılan ifade altyazıda okunmuyor ("x3", "x5" diye geçiyor). -u(-(t+3)) ve -5u(-(t+3)) yazımı, hocanın söylediği değerlerden kuruldu ve Python ile bu değerleri verdiği görüldü. -->

### 13.1 Sistemin "Röntgeni"

Birim basamak, birim dürtü ile birlikte sistemleri tanımak için de kullanılır. Elimizde nasıl çalıştığını bilmediğimiz bir sistem vardır, bir kara kutu. Girişine özel bir sinyal verip çıkışına bakarız. Hocanın benzetmesiyle bu, sistemin **röntgenini çekmektir**. Sistemin davranışını buradan çözeriz. Sistemin nasıl çalıştığını öğrendikten sonra yeni gelen bir girişin sonucunu tahmin edebiliriz. Hoca bunu "elimizdeki veriyi önce information, sonra knowledge haline getirdik" diye özetledi. Ayrıntılara ileride gelinecek ve bu işlemin frekans düzleminde daha kolay yapıldığı görülecek.

**Soru:** Girişe $u[n]+u[-n]$ versek bu nedir?

**Cevap:** Sınıftan "tamamen bir" cevabı geldi, hoca da "her noktada bir" diye onayladı. Sistemin kapasitesi kadar, örneğin 500 tane değer verilebilir.

> **Ders sonrası not:** $n=0$'da iki terim de 1'dir. Doğrusu $u[n]+u[-n]=1+\delta[n]$, yani $n=0$'da değer 2'dir (Python ile hesaplandı). Ayrıca sistemin röntgeni, yani birim dürtü cevabı, giriş olarak sabit dizi değil $\delta[n]$ verilince elde edilir. Doğrusal ve zamanla değişmeyen bir sistemde sabit giriş, $h[n]$'nin kendisini değil, yalnız toplamını veren sabit bir çıkış üretir. Python'da seçilen bir $h[n]$ ile bu fark görüldü. Hoca da konuyu Bölüm 16'da $\delta[n]$ üzerinden sürdürdü.

### 13.2 Parçalı Fonksiyondan Kurtulmak

$e^{-t}$ sinyalini yalnız $t\ge0$ için istiyor, $t<0$ için sıfır olmasını istiyorsak parçalı fonksiyon yazmak yerine $u(t)$ ile çarparız:

$$x(t)=e^{-t}u(t).$$

$u(t)$ $t\ge0$ için birler, başka yerde sıfırlar getirir. Basamağın faydalarından biri budur.

### 13.3 Basamaklarla Saat Darbesi

**Soru:** Slayttaki sinyal nereden tanıdık?

**Cevap:** Sınıftan "saat darbesi" (clock pulse) cevabı geldi. Doğru. Lojik devrelerde daha ayrıntılı görülecek.

Saat darbesinin bir birimi basamakların farkıyla kurulur. $u(t)$ sıfırdan başlar. $u(t-1)$ birden başlar. Birbirinden çıkarılınca $t\ge1$ için $1-1=0$ olur ve sinyal orada söner:

$$u(t)-u(t-1)=\begin{cases}0,&t<0\\1,&0\le t<1\\0,&t\ge1\end{cases}$$

Üç şartlı parçalı fonksiyon yerine tek bir ifade yeter.

## 14. Dikdörtgen, Rampa ve Üçgen Sinyalleri

### 14.1 Birim Dikdörtgen

Birim dikdörtgen (unit rectangle), belli bir aralıkta 1, başka yerde 0 olan sinyaldir. Saat darbesi parçasına benzer:

$$\mathrm{rect}(t)=\begin{cases}1,&|t|<\tfrac12\\0,&\text{diğer durumlarda}\end{cases}$$

$1/2$ yalnız örnektir. $T_0$ sabit olmak üzere $\mathrm{rect}(t/T_0)$ yazarak dikdörtgenin boyu büyütülüp küçültülür.

### 14.2 Birim Rampa

Rampa (unit ramp), $t<0$ için 0, $t>0$ için eğimli bir doğrudur:

$$r(t)=t\,u(t).$$

- $r(2t)$: Doğru daha dik olur.
- $r(3t)$: Eğimi 3 olan bir doğrudur.
- $3r(2t)$: İçerideki doğrunun eğimi 2'dir, 3 ile çarpınca bütün genlik değerleri 3 katına çıkar. Eğim 6'dır. Hocanın dediği gibi 3'ü içeri almaktan çok farkı yoktur: $3r(2t)=6t\,u(t)=r(6t)$ (eşitlik Python ile doğrulandı).

$r$ harfi burada rampanın gösterimidir, başka bir şeyle karıştırılmamalıdır.

**Rampa, basamağın integralidir.** Integral alırken önce $\tau$ diye yeni bir eksene geçilir. $-\infty$'dan herhangi bir $t$ noktasına kadar integre edilir. $\tau<0$ bölgesinde $u(\tau)=0$ olduğu için integral iki parçaya ayrılır:

$$\int_{-\infty}^{t}u(\tau)\,d\tau=\int_{-\infty}^{0^-}0\,d\tau+\int_{0}^{t}1\,d\tau=0+\tau\Big|_{0}^{t}=t,\qquad t\ge0.$$

$t<0$ için sonuç sıfırdır. Yani sonuç $r(t)$'dir. Alan düzgün artar: Adım 3 ise değerler 3, 6, 9, 12 diye ilerler. Hoca bunu "sabit ivmeyle artış" diye andı, kastedilen sabit eğimdir. Türevi alınınca da sabit fonksiyon elde edilir.

### 14.3 Birim Üçgen

Birim üçgen, $|t|<1$ bölgesinde bir üçgen, başka yerde 0 olan fonksiyondur. İçeriye $2t$ gibi ifadeler de yazılabilir.

> **Ders sonrası not:** Altyazıda ifade "$1-t$" diye geçiyor. Doğrusu $1-|t|$'dir: $|t|<1$ için $1-|t|$, başka yerde 0. $t=\pm1$'de 0, $t=0$'da 1 verir (Python ile doğrulandı).

## 15. Temel Sinyallerle Karmaşık Sinyal Kurmak

Herhangi bir sinyal, şimdiye kadar gördüğümüz temel sinyaller cinsinden yazılabilir. Bu analizi çok kolaylaştırır.

### 15.1 Doppler Ultrason Dalga Biçimi

Hastanelerde ve bazı yerlerde radarda kullanılan Doppler dalga biçiminde, belli frekanslarda ve mikrosaniye mertebesinde aralıklarla dalgalar gönderilir. Bu dalgalar farklı kosinüsler cinsinden yazılabilir. Hoca, görüntülemede farklı frekanslarda sinyal gönderildiğini, dokuyla uyuşan frekanslarda net bir görüntü oluştuğunu, diğer durumlarda oluşmadığını söyledi ve bunu bir filtreleme mekanizması olarak yorumladı.

### 15.2 Filtreleme ve Korelasyon Örnekleri

Hoca bu filtreleme mantığını görüntü üzerinden anlattı. Yüzünüzün bir fotoğrafından gözünüzün olduğu parçayı kesin. Bu parçayı bir filtre gibi bütün yüzde gezdirin ve her konumda bir benzerlik hesabı, yani **korelasyon** yapın. Gözün olduğu yerde beyaz bir ışık çıkar, buna **pik** denir. Diğer yerler simsiyah kalır. Beyaz noktalar, gezdirilen filtre ile görüntünün o bölgesinin çok benzediğini gösterir.

Aynı fikir gürültü gidermede de kullanılır. Hocanın gösterdiği bir heykel görüntüsünde çizgiler biçiminde periyodik bir gürültü vardı. Önce bu gürültü bileşenleri tespit edilir, sonra bastırılır. Bastırmak, onları doğrudan siyah yapmaktır. Siyah yapılınca periyodik gürültü yok olur.

<!-- BELİRSİZ: Hocanın ekranda gösterdiği görsellerin frekans düzleminde mi olduğu altyazıdan net değil. -->

### 15.3 Dikdörtgenlerle Darbe Dizisi ve Zarf

Bir dikdörtgen sinyalini $A$ ile çarpmak genliği üzerinde işlem yapmaktır. $t/T_0$ ile dikdörtgen ölçeklenir. $t$ yerine $t-nT$ yazmak ise öteleme yapmaktır. $T_0$ sabit kalarak bu ötelenmiş dikdörtgenler toplanırsa darbe dizisi elde edilir:

$$\sum_{n=-2}^{2}A\,\mathrm{rect}\left(\frac{t-nT}{T_0}\right).$$

<!-- BELİRSİZ: Formül altyazıda "t-n, to n bölü t bölü t" diye bozuk geçiyor. Yukarıdaki biçim hocanın ölçekleme, öteleme ve -2'den 2'ye toplama anlatımından kuruldu. -->

Bu dizi sinyalin **zarfıdır** (envelope). Sinyal taşınırken pozitif ve negatif tarafını kapsayan bu yapıya kapsayıcı sinyal denir. Sinyal işleme konularında daha ayrıntılı anlatılır. RF sinyallerinde bir kosinüs taşıyıcı vardır. Darbe dizisi taşıyıcıyla birleştirilince, darbelerin olduğu yerlerde kosinüs görünür, başka yerlerde bastırılır. Yani aralık aralık sinüzoid görülür. Slayttaki Doppler dalga biçimi budur.

> **Ders sonrası not:** Hoca bu birleştirmeye "konvolüsyon" dedi. Anlatılan davranış çarpmadır: $p(t)\cos(\omega_c t)$. Darbenin sıfır olduğu yerde çarpım da sıfırdır. Hocanın kastettiği bağlantı büyük olasılıkla, zamandaki bu çarpmanın frekans düzleminde konvolüsyona karşılık gelmesidir.

## 16. Birim Dürtü

Bir diğer temel sinyal, tepkisel diyebileceğimiz **impulsif sinyallerdir**. Sisteme bir anda bir giriş uygulayıp hemen çekersiniz. Bir RLC devresinde akımı açıp kapatmak böyle anlık bir şeydir. Kondansatörlü bir devreyi açıp kapattığınızda aslında bir impuls sinyali vermiş olursunuz ve kısa bir şarj gerçekleşir.

Bu ideal sinyal, Dirac delta $\delta(t)$ ile gösterilir. Gerçekte impuls hızlıca yükselir, hızlıca söner ve gider. Tam şekli önemli değildir. Hoca bunu çok küçük bir $\varepsilon$ ile anlattı: $\varepsilon$ genişliğinde ve $1/\varepsilon$ yüksekliğinde bir darbe. $\varepsilon$ sıfıra çok yakınsa ideal hale yaklaşılır.

Sayısal işaret işlemede kullanacağımız sinyal ise ayrık birim dürtüdür:

$$\delta[n]=\begin{cases}1,&n=0\\0,&n\ne0\end{cases}$$

Hoca bunu $u[n]+u[-n]$ yerine sistem davranışını çözümlemek için kullanacağımızı söyledi. Sistemin bu girişe verdiği cevap **birim dürtü cevabıdır** (unit impulse response) ve $h[n]$ ile gösterilir. Bu cevap sistemin nasıl çalıştığını, yani röntgenini gösterir. Giriş $x[n]$ ile $h[n]$'nin birlikte kullanıldığı işleme ise **konvolüsyon** diyeceğiz.

> **Ders sonrası not:** Sürekli $\delta(t)$'de $t=0$'daki değer 1 değildir. Hocanın $\varepsilon$ anlatımında yükseklik $1/\varepsilon$, alan ise $\varepsilon\cdot\frac{1}{\varepsilon}=1$'dir. $\delta(t)$ için 1 olan alanıdır. Değeri 1 olan $\delta[n]$'dir.

Slaytta $t+1$ biçiminde bir fonksiyona $\delta(t)$ eklenmiş bir örnek de vardı. Doğrusal parça sürerken sıfır noktasına anlık bir darbe konur. Darbe anlık yükselir ve yok olur. Buna darbe veya tepki fonksiyonu denir.

<!-- BELİRSİZ: Slayttaki bu sinyalin tam ifadesi ve hangi aralıkta tanımlı olduğu altyazıda net değil. -->

### 16.1 Ötelenmiş Dürtülerin Toplamı

Hoca ayrık dürtüden şöyle bir dizi kurdu:

$$t[n]=\sum_{k}\delta[n-k].$$

$\delta[n-k]$, dürtünün $k$ kadar ötelenmesidir. $k=-5$ iken $n=-5$'te, $k=-4$ iken $n=-4$'te, $k=5$ iken $n=5$'te 1 çıkar. $k$ aralığını $-5$ ile $5$ alırsak bu noktaların tamamında, yani 11 noktada 1 olan, başka yerde 0 olan bir dizi elde edilir (Python ile doğrulandı). $k$ aralığı nasıl ayarlanırsa o kadar birim örnek (unit sample) kullanılır.

> **Hocanın vurgusu:** Bu yapı ileride çok kullanılacak.

## 17. Dürtünün Özellikleri

### 17.1 Eleme Özelliği

**Soru:** Bir $f(t)$ sinyalini $\delta(t)$ ile çarpıp integralini alırsak ne buluruz?

**Cevap:** Hoca integrali "çarpıp çarpıp toplamak" diye düşündürdü. $\delta(t)$ sıfır dışında her yerde sıfırdır, dolayısıyla diğer bütün noktalar sıfırlanır. Yalnız $t=0$ noktasındaki değer kalır:

$$\int_{-\infty}^{\infty}f(t)\,\delta(t)\,dt=f(0).$$

Bunun şartı, $f$'in $t=0$'da sürekli olmasıdır. Dürtü ideal alındığı için sonuç $f(0)$'dır; gerçek bir darbeyle bu ancak yaklaşık olarak $f(0)$ demektir.

### 17.2 Ölçekleme ve Öteleme

Dürtü bir $\alpha$ sayısıyla çarpılırsa sonuç $\alpha$ katına çıkar. $\alpha=2$ ise $f(0)$'ın iki katı bulunur.

**Soru:** $\alpha\,\delta(t-2)$ ile $f(t)$'nin çarpımının integrali nedir?

**Cevap:** $\delta(t-2)$ yalnız $t=2$'de pik verir. Bu nedenle sonuç $f$'in 2'deki değerinin $\alpha$ katıdır. Sınıftan gelen $\alpha$ örneği de hoca tarafından onaylandı: $\alpha=5$ ise $5f(2)$ bulunur.

$$\int_{-\infty}^{\infty}\alpha\,\delta(t-2)f(t)\,dt=\alpha f(2).$$

### 17.3 Çarpım Özelliği

Her seferinde integral yazmak yerine daha sade bir ifade kullanılabilir. $\delta(t)$ yalnız sıfır noktasında sıfırdan farklıdır. O halde $f$'in o noktadaki görüntüsünü alıp dürtüyle çarpmak yeter. $f$, $t=0$'da sürekli ise:

$$f(t)\,\delta(t)=f(0)\,\delta(t).$$

Ötelenmiş halde $f(t)\delta(t-t_0)=f(t_0)\delta(t-t_0)$ olur. Örneklemede bu ifade kullanılır.

### 17.4 Öteleme Özelliği ve Konvolüsyon

Asıl kullanacağımız şey öteleme (shifting) özelliğidir. Bir $f$ sinyaline farklı $t$ değerlerinde kayma verip integral almak, $f$'in sonsuz tane dürtüyle çarpılması demektir. Bu şekilde $f$'in davranışını veren bir sonuç, yani $f$'in $t$ noktasındaki değeri elde edilir:

$$\int_{-\infty}^{\infty}f(\tau)\,\delta(t-\tau)\,d\tau=f(t).$$

Konvolüsyonun temeli budur. Sistemin röntgenini çekmek gibi düşünülebilir, daha sonra ayrıca konuşulacak.

<!-- BELİRSİZ: Formülün yazımı altyazıda okunmuyor. Hocanın sözlü anlatımından ve kısa nottaki bağlantıdan kuruldu. -->

## 18. Dürtü İçeren İntegraller

### 18.1 Sınır Kuralları

$\int_a^b\delta(t)\,dt$'nin değeri, dürtünün integral aralığında olup olmadığına bağlıdır:

- $a<0<b$ ise sonuç 1'dir. Aralığın içinde bir dürtü vardır.
- Aralık sıfırı içermiyorsa sonuç 0'dır.
- Sınır tam sıfırsa ($a=0$ veya $b=0$) bir belirsizlik (ambiguity) vardır, bu yazım kullanılmaz. Bunun yerine sıfırın sağı $0^+$ ve solu $0^-$ kullanılır.

> **Ders sonrası not:** Hoca ikinci durumu "$a>0$ ve $b<0$" diye okudu. Doğrusu "$a>0$ veya $b<0$"dir: İki şarttan biri aralığı sıfırın dışında bırakmaya yeter.

Sıfırın sağından başlayınca sıfır dahil değildir, solundan başlayınca dahildir:

$$\int_{0^+}^{1}\delta(t)\,dt=0,\qquad\int_{0^-}^{1}\delta(t)\,dt=1,$$

$$\int_{-1}^{0^-}\delta(t)\,dt=0,\qquad\int_{-1}^{0^+}\delta(t)\,dt=1.$$

Bu dört sonuç, dar bir darbeyle yaklaşık hesapla Python'da doğrulandı. Hoca bu limitlerin aslında sıfır geçişini (zero crossing) gösterdiğini söyledi: Sıfırın solu negatif, sağı pozitiftir. Sınırlar arasında negatiften pozitife geçiş varsa dürtü aralığın içindedir.

### 18.2 Slayttaki İntegral Örneği

Verilen integral:

$$I=\int_{-2}^{3}f(t)\left(2+\delta(t+1)-3\delta(t-1)+2\delta(t+3)\right)dt.$$

**Adım 1.** $f(t)$ parantezin içine dağıtılır ve integral dört parçaya ayrılır.

**Adım 2.** İlk terim: $\displaystyle 2\int_{-2}^{3}f(t)\,dt$. Bu, $f$'in türüne göre hesaplanacak normal bir integraldir.

**Adım 3.** Dürtülü terimler için her dürtünün konumu bulunup $[-2,3]$ aralığında olup olmadığına bakılır:

- $\delta(t+1)$: $t=-1$'de. Aralıkta. Katkısı $f(-1)$.
- $-3\delta(t-1)$: $t=1$'de. Aralıkta. Katkısı $-3f(1)$.
- $2\delta(t+3)$: $t=-3$'te. Aralıkta değil. Katkısı 0.

**Sonuç:**

$$I=2\int_{-2}^{3}f(t)\,dt+f(-1)-3f(1).$$

Hoca önce üçüncü terimi $2f(-3)$ diye ekledi, sonra $t=-3$'ün aralık dışında kaldığını fark edip sildi. Son biçim yukarıdaki gibidir. Bir test fonksiyonuyla dar darbe yaklaşımı Python'da bu sonucu verdi.

## 19. Dürtünün Fiziksel Yorumu

İmpuls fonksiyonları ve sinüzoidler birçok uygulamada karşımıza çıkar. İmpuls fonksiyonları, çok kısa zaman aralıklarında etkili olan, etkisi de sinyalin integraline bağlı olan fiziksel durumları modellemek için kullanılır. Bu derste böyle sistemleri kendimiz modellemeyeceğiz, yalnız örneklerini görüyoruz.

**Çekiç darbesi, sopanın topa vuruşu** (hammer blow, bat hitting ball). Slaytta $t=2$ anında etkiyen bir $F$ kuvveti vardır. Kuvvetin kısa bir aralık boyunca integrali alınırken aslında bir impuls integrali hesaplanır.

**Kondansatörün hızlı şarjı** (rapid charging of a capacitor). Devreyi açıp hemen kapatırsınız. $t=0$ anında kondansatörde gerilim yoktur, $v=0$'dır. Kısa bir an içinde $i(t)$ çok büyük bir değere ulaşır. Bu anlık akım kondansatörü doldurur ve $v(t)$ 1 volta çıkar. $0$'dan $\varepsilon$ anına kadar yüklenen toplam yük şu integraldir:

$$\int_{0}^{\varepsilon}i(t)\,dt=1.$$

Bu yüklemeden sonra gerilim farkı $v(\varepsilon)-v(0)=1$ bulunur. Yani gerilim $t=0$'da yaklaşık olarak 1 büyüklüğünde anlık bir sıçrama yapar.

> **Ek bilgi (derste anlatılmadı):** Toplam yük ile gerilim arasındaki bağ $Q=Cv$'dir. Altyazıda sığa değeri net okunmuyor, "bir far" diye geçiyor. Büyük olasılıkla $C=1$ F'tır. Bu durumda $Q=1$ yükü $v=Q/C=1$ V verir ve hocanın söylediği 1 volt bununla uyuşur.

<!-- BELİRSİZ: Slayttaki devre elemanlarının değerleri ve gerilimin tam formülü altyazıda okunmuyor. -->

## 20. Dürtü İçeren Bir Sinyalin İntegrali ve Türevi

Hocanın "bunlar bize daha çok lazım" dediği örnekte sinyal şöyledir: sabit 1 değerli bir parça, $t=1$'de pozitif yönlü bir dürtü, $t=2$'de ters yönlü bir dürtü.

### 20.1 İntegral

İntegral parçalı alınır.

- **$0\le t<1$:** Sabit 1'in integrali $\int_0^t1\,d\tau=t$'dir. Hoca burada bir an $t/2$ mi diye durdu, sonra $t$ olduğunu söyledi. $t=1$'e gelince değer 1 olur.
- **$t=1$:** Dürtü gelir. Fonksiyonun değeri 1 ile birim dürtü çarpımı 1'dir. İntegral bir birim sıçrar ve 2 olur.
- **$1<t<2$:** İntegral kaldığı yerden yine $t$ gibi artar, 2'den 3'e çıkar.
- **$t=2$:** Ters dürtü gelir. En yüksek noktadan iki birim düşülür ve değer 1 olur.

Bu değerleri veren ifade şudur (ara adım eklendi):

$$x(t)=u(t)+\delta(t-1)-2\delta(t-2),\qquad y(t)=\int_{-\infty}^{t}x(\tau)\,d\tau=t\,u(t)+u(t-1)-2u(t-2).$$

Python'da $y(1^-)=1$, $y(1)=2$, $y(2^-)=3$, $y(2)=1$ çıktı. Bu değerler hocanın söyledikleriyle aynıdır.

<!-- BELİRSİZ: t=2'deki ters dürtünün ağırlığı altyazıda doğrudan söylenmiyor, "iki birim düşüş" anlatımından -2 alındı. Sinyalin t=2 sonrasında nasıl sürdüğü de okunmuyor. Burada 1 olarak sürdüğü varsayıldı. -->

### 20.2 Türev

Aynı mantık türevde de geçerlidir.

- Doğrusal artan parçada değişim sabittir. $t$'nin türevi sabit fonksiyondur.
- Ani sıçramanın olduğu yerde dürtü oluşur. Dürtünün ağırlığı sıçrama miktarıdır. $t=1$'deki artış bir birimdir, bu yüzden orada birim dürtü oluşur.
- Sonraki düzenli artışta türev yine sabittir.
- $t=2$'deki hızlı azalış da ters yönlü dürtü verir.

> **Ders sonrası not:** Hoca doğrusal parçanın türevi için bir yerde "yine $t$ gibi bir fonksiyon" dedi. Doğrusu sabittir. Ayrıca $t=2$'deki düşüş iki birim olduğu için dürtünün ağırlığı $-2$'dir, birim dürtü değildir. $y(t)$'nin türevi $u(t)+\delta(t-1)-2\delta(t-2)$ olur, yani başlangıçtaki $x(t)$'ye döner. Sıçrama miktarları Python'da $+1$ ve $-2$ çıktı.

## 21. Slaytlar Üzerinden Tekrar ve Yeni Kavramlar

Hoca dersin sonunda başka bir slayt setinden konuları hızlıca tekrar etti, birkaç yeni kavram ekledi.

**Değişken dönüşümleri.** Öteleme sağa veya sola, tersleme $-1$ ile, ölçekleme (dilation) ise bir $\alpha$ sayısıyla yapılır. $x(2t)$'de $-1$'deki değer $-0{,}5$'e, $1$'deki değer $0{,}5$'e, $2$'deki değer $1$'e gelir.

**Genlikte öteleme.** Fonksiyona ayrı bir terim eklemektir. Değişken olduğu gibi kalır. $x(t)-2$'de bütün değerlerden 2 çıkar, yani 2 olan değerler 0'a iner.

**Afin fonksiyon.** Genlikte ölçekleme ile öteleme birlikte yapılırsa $A\,x(t)+B$ çıkar. Buna afin fonksiyon denir.

**Sağ taraflı ve sol taraflı sinyaller.** Sinyal belli bir $t_0$ noktasından önce sıfırsa, davranışını yalnız o noktadan sonra gösteriyorsa **sağ taraflıdır** (right-sided). **Sol taraflı** (left-sided) sinyal bunun tam tersidir: belli bir noktadan sonra sıfırdır.

> **Ders sonrası not:** Hoca sol taraflı sinyali tanımlarken sağ taraflının cümlesini tekrar etti, ama önce "tam tersi" dedi. Burada verilen, "tam tersi"nin doğru karşılığıdır.

**Sınırlı sinyal** (bounded). Değerleri belli bir pozitif sayının altında kalan, sonlu sinyaldir. Bu konuya sistemlerde dönülecek.

**İşaret fonksiyonu** (signum). Hoca bu derste çok kullanmadıklarını söyledi:

$$\mathrm{sgn}(t)=\begin{cases}1,&t>0\\0,&t=0\\-1,&t<0\end{cases}$$

**Kardinal sinüs.** Hoca bu derste çok kullanmadıklarını, elektronikçilerin ise çok kullandığını belirtti ve "sinüsün $t$'ye dönüşümü" diye andı.

> **Ek bilgi (derste anlatılmadı):** Kardinal sinüs, büyük olasılıkla sinüsün değişkenine bölünmesiyle tanımlanan $\mathrm{sinc}$ fonksiyonudur: $\sin(t)/t$ veya bazı kaynaklarda $\sin(\pi t)/(\pi t)$.

Hoca, kaçırılan yerler için bu slaytların hocasının YouTube videolarını önerdi. Kanalın çok ayrıntılı anlattığını söyledi.

<!-- BELİRSİZ: Kanal sahibinin adı altyazıda "Mithill Adams" diye geçiyor. Ad doğrulanamadı. -->

## Dersin Toparlaması

Bu derste sinyaller üzerinde yapılan zaman işlemleri tamamlandı: ölçekleme, tersleme, öteleme ve bunların doğru sırayla birleştirilmesi. Ardından periyodik sinyaller, sinüzoidleri anlamak için gereken karmaşık sayılar ve Euler formülü, enerji ve güç tanımları görüldü. Sonra temel sinyaller tanıtıldı: sinüzoid, üstel, basamak, dikdörtgen, rampa, üçgen ve birim dürtü. Bir sinyalin bu temel sinyaller cinsinden yazılabilmesi ile dürtünün eleme özelliği, ileride konvolüsyonun temelini oluşturacak.

Sinyaller konusu burada kapanıyor. Gelecek derste sistemler ve özellikleri anlatılacak. Ardından sinyal ve sistemler üzerinde konvolüsyon işlemleri, zaman ve frekans düzlemi işlemleriyle devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
