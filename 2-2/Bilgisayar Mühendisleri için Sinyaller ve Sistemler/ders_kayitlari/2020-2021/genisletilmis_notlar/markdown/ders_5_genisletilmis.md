# Ders 5 Genişletilmiş Notu: Birim Dürtü Cevabı, Konvolüsyon İntegrali ve Toplamı, Sistem Modelleme ve Diferansiyel Denklemler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Bölümün Tekrarı: Sistemler ve Özellikleri
- 2. Bir Sistemi Nasıl Çözeriz?
- 3. Birim Dürtü Cevabı: Sistemin Röntgeni
- 4. Konvolüsyonun İki Dayanağı: Zamanla Değişmezlik ve Genişletilmiş Doğrusallık
- 5. Süperpozisyon İntegrali
- 6. Birim Dürtü Cevabının Diğer Düzlemlerdeki Karşılıkları
- 7. Konvolüsyon İntegrali
- 8. Animasyonlarla Konvolüsyon: Bir Benzerlik Ölçüsü
- 9. Neden Değişken Dönüşümü, Ters Çevirme ve Kaydırma?
- 10. Asıl Zorluk: İntegralin Sınırları
- 11. Nedensellik ve Konvolüsyonun Özellikleri
- 12. Basamak Cevabı
- 13. Sürekli Zamanda Konvolüsyonun Adımları
- 14. Örnek: İki Dikdörtgen İşaretin Konvolüsyonu
- 15. Konvolüsyon Toplamı
- 16. Örnek: $\{2, 2, 1\}$ ile Beş Elemanlı Bir Dizinin Konvolüsyonu
- 17. Neden Ters Çeviriyoruz?
- 18. Konvolüsyonun Uygulamaları: Görüntü İşleme ve CNN
- 19. Konvolüsyonun Algoritmik Maliyeti
- 20. Fourier ve Laplace Dönüşümleriyle İlişki
- 21. Dersin Bundan Sonraki Akışı
- 22. Sistem Modelleme
- 23. Deterministik ve Olasılıksal Sistemler
- 24. Model Örneği: İki Bilgisayar Arasındaki Kablo
- 25. Model Örneği: Araç Süspansiyon Sistemi
- 26. Diferansiyel Denklemlerin Özellikleri
- 27. Doğrusal Sabit Katsayılı Denklemlerin Çözüm Yapısı
- 28. Sıfır Giriş Çözümü Örnekleri
- 29. Sıfır Noktası Başta Olmayan İşaretlerin Konvolüsyonu

## 1. Önceki Bölümün Tekrarı: Sistemler ve Özellikleri

Bir öğrencinin isteği üzerine hoca, yeni konuya geçmeden önce dördüncü bölümü hızlıca özetledi. Şimdiye kadar sinyalin ve sistemin ne olduğunu, analog ile sayısalın farkını, sinyallerin özelliklerini ve türlerini, sistemlerin özelliklerini konuşmuştuk.

Sinyaller üzerinde yapılan temel işlemlerin (toplama, fark, çarpma, türev, integral, zamanda öteleme, konvolüsyon) her biri bir denklemle ifade edilir ve bu denklemlerin her biri aslında bir sistemdir. Zamanda öteleme, normal bir sinyalde gecikme (delay) ya da öne alma (predictor) anlamına gelir. Bunu yapan sisteme ayrıca zamanda öteleme sistemi (time shift system) denir.

Sistemler arası bağlantıların üç türü vardı:

- **Seri (kaskad, cascade) bağlantı:** Birinin çıkışı diğerine giriş olarak verilir. Hoca burada bir çarpma işlemi olduğunu hatırlattı.
- **Paralel bağlantı:** Sistemlerin çıkışları toplanır.
- **Geri beslemeli (feedback) bağlantı:** Sistemin çıkışı girişe fark olarak geri yansıtılır. Bu yapı özellikle öğrenme sistemlerinde çok kullanılır. Hatalar sürekli toplanacaksa integratör ile geri besleme birlikte kullanılır.

> **Ders sonrası not:** Seri bağlantıdaki "çarpma" dönüşüm düzlemi için geçerlidir. Zaman düzleminde seri bağlı iki sistemin bileşimi, bölüm 11'deki birleşme özelliğinde görüleceği gibi konvolüsyondur: $h_1 * h_2$.

### 1.1 Doğrusallık

Doğrusallık (linearity) iki şartın birlikte sağlanmasıdır:

- **Çarpımsallık (homojenlik):** Giriş yerine $ax$ verildiğinde çıkış $a\,f(x)$ oluyorsa bu özellik sağlanır.
- **Toplamsallık (süperpozisyon):** Giriş yerine $x_1 + x_2$ verildiğinde çıkış $f(x_1) + f(x_2)$ oluyorsa bu özellik sağlanır.

İkisinden biri sağlanmıyorsa doğrusallık yoktur. Hoca örnek olarak modülatörü verdi: $x(t)$ işareti $\cos(2\pi f t)$ ile çarpılır. Bir ses işareti bu modülasyon sayesinde taşınabilir hale gelir ve bu sistem doğrusaldır. Buna karşılık $y = x^2$ doğrusal olmayan bir sistemdir.

> **Hocanın vurgusu:** $y = x^2$ yazıldığında $x$, $t$'ye göre değişen bir sinyaldir, yani aslında bir vektördür. Bunu doğrudan matematikteki fonksiyonlarla karıştırmayın.

### 1.2 Diğer Özellikler

- **Bellekli ve belleksiz sistem:** Sistem yalnız şu anki değerleri kullanıyorsa belleksizdir. Geçmişe veya geleceğe ait değerler kullanıyorsa bellekli (hafızalı) sistemdir.
- **Zamanla değişmezlik:** Girişe uygulanan öteleme çıkışa aynen yansıyorsa bu özellik vardır. Sınaması basittir. Önce girişi $t_0$ kadar öteleyip sisteme sokarız. Sonra girişi sisteme sokup çıkışı $t_0$ kadar öteleriz. İki sonuç eşitse sistem zamanla değişmezdir.
- **Kararlılık (BIBO):** Sınırlı girişe karşı sınırlı çıkış (bounded input, bounded output) elde ediliyorsa sistem kararlıdır. Çıkış sonsuza gidiyorsa kararlılık yoktur. Bunu zaman düzleminde analiz etmek zordur. İleride Laplace ve Z dönüşümleriyle daha kolay yapılacaktır. Slayttaki örnek bir hız sabitleme (cruise control) sistemiydi.
- **Tersinirlik (invertibility):** Bir sistemin çıkışı yeniden girişe dönüştürülebiliyorsa sistem terslenebilirdir.

### 1.3 Diferansiyel ve Fark Denklemleri

Günlük hayattaki birçok sürekli zamanlı sistem diferansiyel denklemlerle, ayrık zamanlı sistemler de fark denklemleriyle (difference equation) ifade edilir. Bir diferansiyel denklemin mertebesi ve katsayıları vardır. Çözüm teknikleri normal denklemlerden çok farklıdır. Katsayılar sabitse ve bütün başlangıç koşulları sıfırsa, yani $t=0$ anında birinci, üçüncü, dördüncü türevlerin değerleri sıfırsa bu özel durumda sisteme doğrusal diyoruz. Bunlara doğrusal sabit katsayılı adi diferansiyel denklemler (ordinary differential equation) diye ifade edebiliriz.

Örneğin bir RLC devresinin analizi ikinci mertebeden türev içeren bir denkleme götürür. $L$ (indüktans), $R$ (direnç) ve $C$ (kapasite) burada sabit değerlerdir. Devrenin hangi zaman aralığında ne kadar akım veya gerilim bilgisine sahip olduğunu anlamak için bu denklemi çözmek gerekir. Mekanik bir sistem örneği de yine ikinci mertebeden bir diferansiyel denklemle ifade ediliyordu.

> **Hocanın vurgusu:** Bu derste diferansiyel denklem çözmeyeceğiz. Bu denklemleri dönüşüm yöntemleriyle bildiğimiz cebirsel denklemlere çevirip sistemleri onların üzerinden analiz edeceğiz. Bu çok ciddi bir kolaylık sağlıyor. Sistem tasarımı da bu dersin konusu değil: Denklemi kabul edip sistemi analiz edeceğiz, tasarımı bir makineci ya da elektronikçi yapar.

## 2. Bir Sistemi Nasıl Çözeriz?

Şimdiye kadar birim dürtü gibi temel sinyallerle çalıştık. Oysa günlük hayatta üzerinde çalıştığımız sinyaller ve sistemler daha karmaşıktır. Soru şudur: Bir giriş verildiğinde bir çıkış üreten sistemin nasıl davrandığını nasıl tespit ederiz?

Hoca bunu daha önce konuşulan veri, enformasyon ve bilgi (data, information, knowledge) ayrımına bağladı. Elimizde giriş bilgisi ve çıkış bilgisi var. Aradaki sistemi bulursak ileriye yönelik tahmin yapabiliriz. Sistemin nasıl çalıştığını biliyorsak, başka bir giriş verildiğinde çıkışı rahatça hesaplayabiliriz. Bu işi yapan birçok teknik vardır. Bunlardan biri birim dürtü cevabıdır (impulse response).

## 3. Birim Dürtü Cevabı: Sistemin Röntgeni

Önce sistemin doğrusal çalıştığını kabul ederiz. Birim dürtü sinyali, hocanın tarifiyle sıfır anında bir değerini üreten, diğer anlarda sıfır üreten bir sinyaldir. Bir sistemin **birim dürtü cevabı**, ona girdi olarak birim dürtü verildiğinde elde edilen çıktıdır:

$$\delta(t) \;\rightarrow\; \boxed{\text{Sistem}} \;\rightarrow\; h(t)$$

> **Ders sonrası not:** "Sıfır anında bir değeri" tarifi ayrık zamandaki $\delta[n]$ için doğrudur. Ders 3'te anlatıldığı gibi sürekli zamandaki $\delta(t)$, $\varepsilon$ genişliğinde ve $1/\varepsilon$ yüksekliğinde bir darbenin $\varepsilon$ çok küçülürkenki idealleştirmesidir. Yani değeri değil, alanı 1'dir.

Girişi belli bir miktar ötelersek çıkışta da ona karşılık gelen bir cevap buluruz. Birbirini izleyen pek çok dürtüyü sisteme vermeyi düşünelim. Bunlar ayrık zamanlı olabilir. Aralarını çok küçük tutarsak sürekli zaman gibi düşünürüz. Sürekli zamanda çalışıyorsak sonsuz tane dürtü içeren bir girdi söz konusudur.

Bu girdiye karşılık alınan çıktı, sistemin nasıl davrandığını gösterir. Hoca bunu **sistemin röntgeni** diye tanıttı. Mantığı şudur: Dürtü, bulunduğu noktada bir değerini taşır. Sistemin içinde yapılan işlem sonuçta bir çarpmadır. 1 etkisiz eleman olduğu için, 1 ile çarpınca sistemin ne yaptığını doğrudan görürüz.

Birim dürtü cevabı $h(t)$ ile, ileride $h$ harfini kullanan diğer gösterimlerle (örneğin $H(z)$) ifade edilecektir. Size sistem denildiğinde aslında bu cevap, yani sistemin nasıl çalıştığını gösteren bir denklem verilecektir: Girişe dürtü uygulanmış ve sonucu size getirilmiştir.

> **Ders sonrası not:** Hoca burada bir örnek olarak sistemin "$x^2(t) + x(t-1)$ gibi" bir sonuç verebileceğini söyledi. Bu ifade girişe bağlı bir sistem denklemidir, zamana bağlı bir $h(t)$ değildir. Üstelik $x^2$ terimi yüzünden sistem, bölüm 1.1'deki ölçüte göre doğrusal değildir. Birim dürtü cevabı zamanın fonksiyonudur ve konvolüsyon $y(t) = x(t) * h(t)$ biçiminde yazılır.

<!-- BELİRSİZ: 00:20:43-00:21:23 arasındaki gösterim altyazıda karışık ("HT eşittir XT konvolüsyon ... F, T"). Slayttaki yazım okunmuyor. -->

### 3.1 Gösterimde Karıştırılan Nokta

Denklemin iki tarafındaki $t$ aynı şey değildir. Sol taraftaki $h(t)$, belli bir $t$ anındaki sonuçtur. Örneğin "$t=10$ anında bu sistemden hangi cevabı alırım?" sorusunun cevabıdır. Sağ taraftaki $\delta(t)$ ise bütün zaman boyunca değişen giriş değerleridir. Hoca orayı bir vektör gibi düşünmemizi söyledi: Birim dürtü içeren bir giriş sinyali uygulanır, sistemden geçirilir ve istediğimiz zaman değeri hesaplanır. Gösterimlerde bu ikisi karıştırılabilir.

Hoca slayttaki örnekle gösterdi. $t=0$ anındaki birim dürtü giriş olsun. Sisteme $\delta(0)$ uyguladığımızda $h(0)$ ya da kısaca $h$ diye bir sonuç elde ederiz. Şimdi $t=2$ anındaki cevabı bulmak istediğimizi düşünelim. Bu, girişi $t=2$'ye ayarlamak anlamına **gelmez**. Çünkü $\delta(2) = 0$'dır, yani girişe sıfır vermiş oluruz ve sonuç sıfıra gider. Bu yüzden elde edilen şey $h(2)$'ye eşit değildir. Slaytta bu yol yanlış olarak işaretlenmişti.

$h(2)$ yalnız $t=2$ anına değil, giriş dalgasının tamamına bağlıdır. $\delta(t)$ sinyalini bütünüyle verdiğimizde elde ettiğimiz dalga formu sistemin çalışma şeklini gösterir.

> **Ders sonrası not:** Hoca bu noktayı anlatırken bir yerde "aslında $h(0)$'ı bulacağız" dedi, sonra sonucun sıfıra gideceğini söyledi. Doğrusu ikincisidir. $\delta(2)=0$ girişi sıfır giriş demektir ve doğrusal bir sistemde çıkış da sıfırdır.

## 4. Konvolüsyonun İki Dayanağı: Zamanla Değişmezlik ve Genişletilmiş Doğrusallık

Konvolüsyon için sistemin iki özelliğe sahip olması gerekir: Zamanla değişmez olacak ve doğrusal olacak.

**Zamanla değişmezlik.** Sistem zamanla değişmiyorsa girişteki gecikme çıkışa aynen yansır:

$$\delta(t) \rightarrow h(t) \quad\Longrightarrow\quad \delta(t-t_0) \rightarrow h(t-t_0)$$

Çıkışta aynı sinyalin yalnız geciktirilmiş halini elde ederiz.

**Doğrusallık.** Çarpımsallık ve toplamsallığı birlikte yazarsak:

$$a\,x_1 + b\,x_2 \;\rightarrow\; a\,y_1 + b\,y_2$$

Terim sayısını artırırsak buna **genişletilmiş doğrusallık** (extended linearity) denir ve toplam formülüyle yazılır:

$$\sum_{n} a_n\, x_n \;\rightarrow\; \sum_{n} a_n\, y_n$$

Bu toplam ayrık zaman içindir. Sürekli zamanda aynı şey $\tau$ üzerinden bir integral olur. $a(\tau)$ katsayısı ile $\tau$ kadar ötelenmiş bileşenler eksi sonsuzdan artı sonsuza integre edilir:

$$\int_{-\infty}^{\infty} a(\tau)\, x(t-\tau)\, d\tau \;\rightarrow\; \int_{-\infty}^{\infty} a(\tau)\, y(t-\tau)\, d\tau$$

Bu, toplamın birebir sürekli zamandaki karşılığıdır. Yalnız terim sayısı artmıştır. Bu terimlerle bir anlamda ayrıştırma (decomposition) yapıyoruz, yani sinyalin hangi bileşenlerden oluştuğunu tespit ediyoruz.

<!-- BELİRSİZ: Genişletilmiş doğrusallığın sürekli zaman formülü slaytta; altyazıda yalnız "A to katsayısı" ve "Y t eksi to" sözlü olarak geçiyor. Giriş tarafının yazımı buna göre kuruldu. -->

Hem doğrusal hem zamanla değişmeyen bu sistemlere **LTI** (linear time invariant), Türkçesiyle doğrusal zamanla değişmeyen sistemler denir. Konvolüsyon işlemini bu sistemler üzerinde tanımlayacağız.

## 5. Süperpozisyon İntegrali

Soru şudur: Elimizde $h$ bilgisi ve $x$ girişi varken çıkışı nasıl buluruz?

Daha önce konuştuğumuz gibi herhangi bir işaret dürtüler cinsinden şöyle yazılabilir:

$$x(t) = \int_{-\infty}^{\infty} x(\tau)\, \delta(t-\tau)\, d\tau$$

Burada zaman düzleminde bir değişken değişimi yaptık. $\tau$ üzerinden integre ederken $\delta(t-\tau)$ yalnız $\tau = t$ anında etkilidir, diğer anlarda sıfırdır. Böylece $x(t)$ değerini buluruz. Yani $x(\tau)$ işaretini olası bütün dürtülerle çarpmış oluyoruz.

Çıkış, girişin sisteme verilmesiyle elde edilir. Sistemi temsil eden $H$ işlemini bu integralin içine alırız. Bunu yapabilmemizi sağlayan genişletilmiş doğrusallıktır. Sistem yalnız dürtüleri görür, $x(\tau)$ değerleri ise katsayı gibi kalır:

$$y(t) = H\{x(t)\} = \int_{-\infty}^{\infty} x(\tau)\, H\{\delta(t-\tau)\}\, d\tau = \int_{-\infty}^{\infty} x(\tau)\, h(t, \tau)\, d\tau$$

Buna **süperpozisyon integrali** denir. $h(t,\tau)$, $\tau$ anında uygulanan dürtüye $t$ anında verilen cevaptır. Sistem zamanla değişmez kabul edildiğinde $h(t,\tau) = h(t-\tau)$ olur.

Hoca bunu görsel olarak şöyle özetledi: Girişe bir dürtü verdik, bir cevap bulduk. Dürtüyü biraz geciktirdik, geciktirilmiş bir cevap bulduk. Biraz daha geciktirdik, yine bulduk. Şu küçük çizgilerin her birini topladığınızda, yani integre ettiğinizde, çıkışı elde edersiniz. Bu integralde $t$ sabittir ve değişkenimiz $\tau$'dur. $x(\tau)$'nun her $\tau$ anında bir değeri vardır.

> **Hocanın vurgusu:** $h(t)$ elde edildikten sonra geleceğe yönelik tahminde bulunabiliriz. Ama sistem LTI olmalıdır. Öyle değilse bu kabulden bahsedemeyiz.

Hoca formüllerin karışık görünmesinin yanıltmaması gerektiğini de ekledi: Ayrık zamanlı halini görünce "bu muymuş" diyeceksiniz.

## 6. Birim Dürtü Cevabının Diğer Düzlemlerdeki Karşılıkları

Slaytta diğer düzlemlere geçiş de özetlenmişti, ayrıntıları ileride görülecektir. $h(t)$ için kullanılan farklı anahtar kelimeler vardır: birim dürtü cevabı, sistemin modeli. $h(t)$ elimizdeyse iki yöne de gidebiliriz:

- $H(s)$ biliniyorsa ters Laplace dönüşümüyle $h(t)$ bulunur. Slaytta bu, $\delta(t)$'nin Laplace dönüşümü ile $H(s)$'nin çarpılıp ters Laplace dönüşümü alınması olarak yazılmıştı.
- Frekans cevabı $H(\omega)$ biliniyorsa ters Fourier dönüşümüyle $h(t)$ bulunur.

Sürekli zamanlı $x(t)$ işaretinin Fourier dönüşümü $X(\omega)$, Laplace dönüşümü $X(s)$'tir. Aynı şekilde:

- $h(t)$ verilip **frekans cevabı** (frequency response) istenirse Fourier dönüşümü uygulanır: $H(\omega)$.
- $h(t)$ verilip **transfer fonksiyonu** (transfer function) istenirse Laplace dönüşümü uygulanır: $H(s)$.

> **Ders sonrası not:** Hoca $h(t)$'yi ilk anarken "transfer fonksiyonu" kelimesini de kullandı. Kendi sonraki tanımına göre transfer fonksiyonu $h(t)$'nin kendisi değil, Laplace dönüşümü olan $H(s)$'dir.

Sistemi yalnız zaman düzleminde değil, frekans ve diğer düzlemlerde de hesaplamak mümkündür. Kararlılık gibi özellikleri $s$ veya $\omega$ düzleminde analiz etmek daha kolaydır: Orada bir kural verilecek, sistem bu kuralı sağlıyorsa kararlıdır denecektir.

## 7. Konvolüsyon İntegrali

Sürekli zamanda bu işlemin adı **konvolüsyon integrali**, ayrık zamandaki karşılığının adı **konvolüsyon toplamıdır**. Sürekli zamanda tanım şudur:

$$y(t) = x(t) * h(t) = \int_{-\infty}^{\infty} x(\tau)\, h(t-\tau)\, d\tau$$

Normalde çarpma için kullandığımız yıldız (asterisk) sembolü, iki sinyal arasında konvolüsyon demektir. Buna dikkat edelim. $x(t)$, $x(\tau)$ haline gelir, onda hiçbir değişiklik olmaz. $h$ ise sistemin nasıl çalıştığını gösterir. Sonsuz tane $\tau$ değeri için çarpıp çarpıp toplarız ve $y(t)$'yi buluruz.

> **Hocanın vurgusu:** Bu integral bilmeniz gereken integrallerden biridir.

### 7.1 Dönüşüm Düzleminde Konvolüsyon Çarpma Olur

$X$ ve $H$'nin diğer düzlemlerdeki karşılıkları elimizdeyse integral almak yerine doğrudan çarparız:

$$Y(\omega) = X(\omega)\,H(\omega), \qquad Y(s) = X(s)\,H(s)$$

Bu çarpım, iki vektörün veya iki denklemin karşılıklı, yani eleman eleman çarpılmasıdır. Dönüşümlerin sağladığı kolaylık budur. Hoca sınıfa şunu sordu:

**Soru:** İntegral almak mı daha zordur, çarpma yapmak mı?

Sınıftan önce "çarpma" ve "integral sonuçta toplamadır" cevapları geldi.

**Cevap:** İntegral almak için zaten çarpma yapıyorsunuz: Bir işareti diğeriyle, bir de $d\tau$ ile çarpıp topluyorsunuz. Çarpıp toplamak demek integraldir, yani integral hem çarpmayı hem toplamayı içerir. Dönüşüm düzleminde ise yalnız karşılıklı çarpma vardır.

### 7.2 Konvolüsyon ve Korelasyon

Hoca, konvolüsyon yapmanın aslında bir korelasyon olduğunu söyledi. Korelasyon iki şey arasındaki ilişkiyi gösterir: zayıf ilişki, güçlü ilişki. Değişken dönüşümünün neden gerektiğini de şöyle açıkladı: Tek bir $t$ değişkeniyle bunu çözmek mümkün değildir, çünkü sistemin davranışını görmek için girişi sisteme baştan sona geçirmek, bütün durumları göstermek gerekir.

> **Ders sonrası not:** "Korelasyon" sözü burada bir benzetmedir. Konvolüsyonda işaretlerden biri ters çevrilir, çapraz korelasyonda ise büyük olasılıkla ters çevrilmez. Simetrik olmayan işaretlerde iki hesabın sonuçları farklı çıkar; bu `numpy` ile denendi.

## 8. Animasyonlarla Konvolüsyon: Bir Benzerlik Ölçüsü

Hoca derin öğrenmedeki konvolüsyonel sinir ağlarından söz ederek bir konvolüsyon animasyonu açtı. İlk örnekte $h(t)$ birim basamak, $x(t)$ üstel bir işaretti. İkisi konvol edildiğinde çıkışta belli bir dalga formu elde edilir. Bu dalga formundan örneğin üçüncü saniyedeki değer okunabilir.

Animasyonun anlattığı şudur. İki işaret örtüşmeden önce çarpımları her yerde sıfırdır, çünkü birinin sıfır olduğu yerde diğerinde değer vardır. Örtüşme başlayınca sıfırdan farklı değerler oluşur. Kayan işaret ilerledikçe çarpımın altında kalan alan artar ve bu artış çıkış grafiğinde görülür. Alan bir noktada en yüksek değerine ulaşır. Bu nokta, giriş sinyaliyle $h$ sinyalinin **birbirine en çok benzediği** noktadır. Sonra benzerlik azalır, alan da azalır.

Hoca daha önce andığı filtre örneğini hatırlattı: İnsan yüzünde göz arıyorsak, seçtiğimiz göz parçasını yüzün üzerinde gezdiririz. Tam gözün üzerine geldiğimizde pik değeri görürüz, aradığımız yeri bulmuş oluruz.

İkinci animasyonda iki işaret birbirine çok benziyordu. Hoca sordu: Bu ikisi en çok hangi zaman aralığında örtüşür? Yeşil işaret yavaş yavaş gelir, alan artar. En fazla alan, işaretlerin orta noktaları çakıştığında, yani kayan işaretin ortası sıfıra geldiğinde oluşur. Çıkışta alan artar, tam örtüşme noktasında pik yapar, sonra yavaş yavaş azalır.

<!-- BELİRSİZ: Animasyondaki işaretlerin tam biçimleri ve değerleri ekranda; altyazıda yalnız sözlü tarif var ("üçgenimsi", "konik gibi"). -->

## 9. Neden Değişken Dönüşümü, Ters Çevirme ve Kaydırma?

İntegrali yeniden yazalım:

$$y(t) = \int_{-\infty}^{\infty} x(\tau)\, h(t-\tau)\, d\tau$$

$h(t)$'yi bildiğimizi, örneğin $h(t) = 3t + 1$ olduğunu düşünelim. Bunu $\tau$ düzlemine taşımak yalnız bir değişken dönüşümüdür, hiçbir şey değişmez:

$$h(\tau) = 3\tau + 1$$

Sonra $\tau$ yerine $-\tau$ yazılır, yani işaret zaman düzleminde terslenir. Bu, animasyonda gördüğümüz şeydir: İşaretin tam tersi alınır, öbür tarafa çekilir. Son olarak $t$ kadar öteleme uygulanır:

$$h(t-\tau) = 3(t-\tau) + 1 \quad \text{(ara adım eklendi)}$$

Bu iki işlemin gayesi şudur: Ters çevirme, işareti eksi sonsuz tarafından başlatmak içindir. $t$ ötelemesi ise onu oradan hocanın deyimiyle "gıdım gıdım" getirmek içindir. İntegral bu işlemi sonsuz defa yapıp biriktirir.

Sıra şöyledir: Önce $t$'den $\tau$'ya geçilir, bu tek başına hiçbir şey ifade etmez. Sonra $\tau$, $-\tau$ yapılır. Sonra $t$ kadar ötelenerek işaret eksi sonsuzdan artı sonsuza kaydırılır. Elde edilen $y(t)$ ile artık 3 anında, 5 anında ya da istediğimiz anda sistemden çıkacak sonucu hesaplayabiliriz.

Değişme özelliği olduğu için ters çevirme işlemi iki işaretten herhangi birine uygulanabilir. Slayttaki $f_1(t)$, $f_2(t)$ animasyonunda $f_2$ sistemin modeli olarak alındı. Önce $\tau$ düzlemine taşındı, sonra terslendi. Artı taraftaki değerler eksi tarafa geçti. Sonra eksi sonsuzdan kaydırılarak çarpılmaya başlandı. Alan oluşmaya başlayınca sıfırdan farklı değerler bulunur ve çıkış dalga formu elde edilir.

## 10. Asıl Zorluk: İntegralin Sınırları

Sinyallerimiz sonsuz değildir. Bu yüzden integrali eksi sonsuzdan artı sonsuza değil, belli bir aralıkta ($-K$ ile $+L$ arasında) hesaplarız:

$$y(t) = \int_{-K}^{L} x(\tau)\, h(t-\tau)\, d\tau$$

Bu integral çoğu zaman parçalanır. Çünkü işaretin girdiği andan tam örtüşmeye kadar alan sürekli artar, çıkış anında ise azalır. Davranış farklı olan her aralık ayrı integre edilir. Animasyondaki örnekte aralıklar eksi sonsuzdan $-0{,}5$'e, $-0{,}5$'ten $+0{,}5$'e ve $+0{,}5$'ten artı sonsuza kadardı.

> **Hocanın vurgusu:** Konvolüsyonun en zor tarafı burasıdır. Hem sınırlar sıkıntılıdır, integrali $-K$'dan $C$'ye, $C$'den $t$'ye, $t$'den $L$'ye gibi parçalara bölmek gerekir, hem de kullanılan fonksiyonların karmaşıklığı zorluk çıkarabilir. Yine de bu derste amaç integral kabiliyetini ölçmek değildir. İki sinüzoidal dalganın konvolüsyonu gibi zor integraller derdimiz değil. Amaç, konvolüsyonu uygulayıp doğru sonucu bulabilmektir.

## 11. Nedensellik ve Konvolüsyonun Özellikleri

Genel bir LTI sistem için integral eksi sonsuzdan artı sonsuza yazılır. Özel durumlarda sınırlar daralır:

- **Genel LTI sistem:** $y(t) = \int_{-\infty}^{\infty} x(\tau)\,h(t-\tau)\,d\tau$
- **Nedensel (causal) sistem:** Yalnız geriye dönük değerler vardır, $t$ anından sonraki değerler yoktur: $y(t) = \int_{-\infty}^{t} x(\tau)\,h(t-\tau)\,d\tau$
- **Nedensel giriş:** Giriş sıfırdan sonsuza kadardır: $y(t) = \int_{0}^{\infty} x(\tau)\,h(t-\tau)\,d\tau$
- **İkisi de nedensel:** $y(t) = \int_{0}^{t} x(\tau)\,h(t-\tau)\,d\tau$

Son durumda sıfırdan $t$ anına kadar integral almak yeterlidir, yani en genel integralden daha basit bir integrale geliriz.

Konvolüsyonun özellikleri şunlardır:

- **Değişme:** $x * h = h * x$. $\tau$ dönüşümünden sonra ister birinin ister diğerinin $-\tau$'sunu alın, sonuç değişmez.
- **Birleşme (associativity):** $(x * h_1) * h_2 = x * (h_1 * h_2)$. Hangi sırada yaptığınız önemli değildir.
- **Dağılma:** $x * (h_1 + h_2) = x * h_1 + x * h_2$. İki sistem paralel bağlıysa, işlem kolaylığı sağlıyorsa önce konvolüsyonları ayrı ayrı yapıp sonra toplayabilirsiniz.
- **Türev:** $\dfrac{d}{dt}\big(x * h\big) = \dfrac{dx}{dt} * h = x * \dfrac{dh}{dt}$.
- **İntegral:** $\int_{-\infty}^{t} y(\lambda)\,d\lambda = \Big(\int_{-\infty}^{t} x\Big) * h = x * \Big(\int_{-\infty}^{t} h\Big)$. Değişken adı $\lambda$ burada eklendi.

Bu özelliklerin hepsi `numpy` ile sayısal olarak denendi ve sağlandı. Hoca en çok değişme, birleşme ve dağılma özelliklerini kullanacağımızı, doğrusallıktan dolayı bunların zaten bilinen şeyler olduğunu söyledi.

## 12. Basamak Cevabı

Sürekli zamanda sonsuz tane dürtüyle konvolüsyon yapmak yerine, daha kolay olarak birim basamak işareti $u(t)$ de kullanılabilir. $u(t)$ sıfırdan sonraki bütün değerlerde 1 verir. Sisteme dürtü verildiğinde elde edilene dürtü cevabı $h(t)$ diyorduk. Basamak verildiğinde elde edilene **basamak cevabı** (step response) $s(t)$ denir:

$$s(t) = u(t) * h(t)$$

Slayttaki grafikler farklı görünse de bu yalnız görsel bir farktır, çünkü bunlar farklı sistemlere aittir. Basamak cevabı alternatif bir yoldur, matematik olarak hiçbir şey değişmez.

$\delta(t)$'nin $u(t)$'nin türevi olduğunu daha önce konuşmuştuk. Bunu konvolüsyonun türev özelliğiyle birleştirirsek iki yön de elde edilir:

$$h(t) = \frac{ds(t)}{dt}, \qquad s(t) = \int_{-\infty}^{t} h(\lambda)\,d\lambda$$

Bu ilişkiler de sayısal olarak doğrulandı.

## 13. Sürekli Zamanda Konvolüsyonun Adımları

Size iki işaret verildiğinde işlem şu adımlarla yapılır:

1. **Değişken dönüşümü:** $t$'ye bağlı işaretler olduğu gibi $\tau$ eksenine taşınır. $x(t) \to x(\tau)$, $h(t) \to h(\tau)$. Burada hiçbir şey değişmez.
2. **Ters çevirme (flip):** İşaretlerden biri zaman düzleminde ters çevrilir: $h(\tau) \to h(-\tau)$. Hangisini çevirdiğiniz sonucu değiştirmez, ama **daha kısa süreli olanı çevirmek daha kolaydır.**
3. **Kenarları bulma (edge):** Ters çevrilen işaretin sol ve sağ kenarı bulunur. Çünkü örtüşmenin nerede ve ne kadar olduğu bizim için önemlidir. İntegral parçalı olacağı için doğrudan hesaplanamaz, belki 2-3 alt integrale bölünür.
4. **Kaydırma (shift):** İşaret eksi sonsuzdan artı sonsuza kaydırılır. Örtüşme (overlap) durumları tespit edilir.
5. **Bölge bölge integral:** Her örtüşme durumu için belirli integral hesaplanır. Sonuçlar birleştirilir (assemble) ve çıkış elde edilir.

Önemli olan integralin sınırlarının doğru belirlenmesidir. $a$'dan $b$'ye parçalı fonksiyonun bir parçası, $b$'den $c$'ye başka bir parçası yazılır.

## 14. Örnek: İki Dikdörtgen İşaretin Konvolüsyonu

**Verilen.** İki dikdörtgen işaret:

$$x(t) = \begin{cases} 2, & 0 \le t \le 2 \\ 0, & \text{diğer} \end{cases} \qquad h(t) = \begin{cases} 3, & 0 \le t \le 1 \\ 0, & \text{diğer} \end{cases}$$

### 14.1 Hazırlık

**Birinci adım.** İki işaret de $\tau$ düzlemine geçirilir. Değerlerinde bir değişiklik olmaz.

**İkinci adım.** Kısa olan işaret ters çevrilir. Burada kısa olan $h$'dir. Bu bir tavsiyedir, diğerini çevirseniz belki biraz daha fazla işlem yaparsınız. $h(\tau)$'dan $h(-\tau)$ elde edilir: 1'deki kenar $-1$'e gelir, yani işaret $[-1, 0]$ aralığına oturur.

**Üçüncü adım.** Kenarlar bulunur. Ters çevrilmiş işaretin temel kenarları solda $-1$, sağda $0$'dır. $t$ kadar ötelenince:

$$\text{sol kenar} = t - 1, \qquad \text{sağ kenar} = t$$

Kenarlar şu yüzden lazımdır: İşareti kaydırırken altta kalan alan bir noktaya kadar artacak, bir yerden sonra sabit kalacak, bir yerden sonra azalacaktır.

**Dördüncü adım.** Kaydırma. Hoca iki değer denedi. $t = -2$ alınırsa kenarlar $-3$ ve $-2$ olur, $x$ ile örtüşme yoktur ve çarpım her yerde sıfırdır. $t = 2$ alınırsa kenarlar $1$ ve $2$ olur, kayan işaret $x$'in içindedir ve örtüşme vardır.

### 14.2 Bölgeler

İntegrand, örtüşme olan her yerde $x(\tau)\,h(t-\tau) = 2 \cdot 3 = 6$'dır. Beş bölge vardır:

| Bölge | Aralık | Durum | İntegral sınırları |
|---|---|---|---|
| 1 | $t < 0$ | Örtüşme yok | Yok |
| 2 | $0 \le t \le 1$ | Kısmi örtüşme, alan artıyor | $0$'dan $t$'ye |
| 3 | $1 < t \le 2$ | Tam örtüşme, alan sabit | $t-1$'den $t$'ye |
| 4 | $2 < t \le 3$ | Kısmi örtüşme, alan azalıyor | $t-1$'den $2$'ye |
| 5 | $t > 3$ | Örtüşme yok | Yok |

### 14.3 İntegrallerin Hesabı

**Bölge 1 ($t<0$).** Kayan işaretin kapsadığı $[t-1, t]$ aralığında $x(\tau)$ sıfırdır:

$$y(t) = 0$$

**Bölge 2 ($0 \le t \le 1$).** Örtüşme sıfır noktasını geçince başlar. $t-1$ ile $0$ arasında $x$ sıfır olduğu için bu parça etkisizdir. İntegralin sınırı sıfırdan başlar, $t$'ye kadar gider:

$$y(t) = \int_{t-1}^{0} 0\,d\tau + \int_{0}^{t} 6\,d\tau = 6t$$

Sınırın doğrudan 1 yazılmaması gerekir, çünkü işaret henüz belli bir $t$ noktasındadır. Sonuç da $t$'ye bağlıdır.

> **Ders sonrası not:** Hoca bu integrali önce $\int 6\tau\,d\tau = 3\tau^2$ diye alıp $3t^2$ sonucunu ve parabolik bir artış söyledi. Bu yanlıştır, integrand sabittir. Hoca sonra "6 $d\tau$ olacak" diyerek kendisi düzeltti. Doğrusu $\int_0^t 6\,d\tau = 6t$'dir, yani artış doğrusaldır.

**Bölge 3 ($1 < t \le 2$).** İşaret tamamen $x$'in içindedir. $t-1$ ile $t$ arasında $x$ hep 2, $h$ hep 3'tür:

$$y(t) = \int_{t-1}^{t} 6\,d\tau = 6\big[t - (t-1)\big] = 6$$

Grafik bu bölgede durağan hale gelir, çünkü alan sabittir.

> **Ders sonrası not:** Hoca önce yanlış integrandla devam ederek bu bölgede $3\big[t^2 - (t-1)^2\big]$ yazdı ve "$2t+1$ gibi" bir doğru denklemi bulunacağını söyledi. Bu ifade de yanlıştır. Yanlış integrandla bile sonuç $6t-3$ olurdu. Hoca düzelttikten sonra doğru sonuç olan sabit 6'yı buldu.

**Bölge 4 ($2 < t \le 3$).** İşaret $x$'in sağ kenarını geçmeye başlar ve örtüşme azalır. 2'den sonrası sıfır olduğu için integral $t-1$'den $2$'ye alınır:

$$y(t) = \int_{t-1}^{2} 6\,d\tau = 6\big[2 - (t-1)\big] = 18 - 6t$$

Bu azalma $t=3$'e ulaşınca biter, orada örtüşme sıfıra iner.

**Soru:** Bu bölgede integrali neden 2'den 3'e yazmadık?

**Cevap:** Mesele 2'den 3'e yazmak değildir. O sınırlar $t$'nin değil, $\tau$'nun sınırlarıdır. Örtüşme, herhangi bir $t$ anında $t-1$ noktasından 2 noktasına kadardır. Bu yüzden $t-1$'den 2'ye integre etmemiz gerekir. Sonuç $18-6t$'dir.

**Bölge 5 ($t>3$).** Hiçbir örtüşme yoktur, $x$'in sıfır olduğu yerde $h$ değeri 3 olsa da çarpım sıfırdır:

$$y(t) = 0$$

### 14.4 Sonuç

Parçalar birleştirilir:

$$y(t) = \begin{cases} 0, & t < 0 \\ 6t, & 0 \le t \le 1 \\ 6, & 1 < t \le 2 \\ 18 - 6t, & 2 < t \le 3 \\ 0, & t > 3 \end{cases}$$

Sonuç bir yamuktur: 0'dan 1'e doğrusal artar, 1 ile 2 arasında 6'da sabit kalır, 2'den 3'e doğrusal azalır. Hoca örnek olarak $y(1{,}5) = 6$ değerini okudu.

Sayısal konvolüsyon, adımı $10^{-3}$ alınarak bu sonucu doğruladı: En büyük fark $0{,}006$ çıktı, yani adım boyutu kadar bir ayrıklaştırma farkı. Örneğin $y(0{,}5) \approx 3$, $y(2{,}5) \approx 3$, $y(3{,}5) = 0$.

**Soru:** Bölge 2'yi tam anlamadım. Alan bana 3 gibi geliyor, maksimumun 6 olması olmaz gibi geliyor.

**Cevap:** Hoca integralin sınırlarını adım adım tekrar kurdu. $t<0$ iken $x$ sıfır olduğu için sonuç sıfırdır. İşaret kaydırılıp sıfır noktası geçilince örtüşme başlar. Örtüşme 1 noktasına varana kadar artar, orada artış durur ve sabit bölgeye girilir. Sıfırdan itibaren $x$'in değeri 2, $h$'nin değeri 3 olduğu için integrandın içi 6'dır. Bu yüzden sonuç $6t$'dir ve $t=1$'de 6 olur (ara adım eklendi).

<!-- BELİRSİZ: 01:21:07-01:21:16 arasındaki öğrenci sorusu altyazıda kısmen bozuk ("orada 3C hocam"). Sorunun tam kastı okunmuyor. -->

Bu sonucun pratikteki anlamı şudur: Bir R, RC, RL veya RLC devresinin $h(t)$'si biliniyorsa ve girişe bir $v(t)$ ya da $x(t)$ uygulanırsa, çıkışta nasıl bir dalga formu elde edileceği bulunur. Örneğin devrenin 10. saniyedeki gerilim veya akım değeri okunabilir.

> **Ders sonrası not:** Hoca bölgeleri anlatırken bir yerde integrandı $x(\tau)\,h(\tau-t)$ diye okudu. Doğrusu tanımdaki $x(\tau)\,h(t-\tau)$'dur.

## 15. Konvolüsyon Toplamı

Aynı işlemin ayrık zamandaki karşılığı daha kolaydır. İntegral yerine toplam gelir, $\tau$ yerine $k$ kullanılır:

$$y[n] = x[n] * h[n] = \sum_{k=-\infty}^{\infty} x[k]\, h[n-k]$$

Slaytta $k$ yerine başka harflerin de kullanıldığı yerler vardı, bunun önemi yoktur. Mantık aynıdır: Sisteme $\delta[n]$ uygulandığında $h[n]$ bulunur. Sistem zamanla değişmez olduğu için $k$ kadar öteleyince $h[n-k]$ bulunur. Bunu $x[k]$ ile ağırlıklandırıp işaretin bütün bileşenleri üzerinden toplarsak **konvolüsyon toplamını** (convolution sum) elde ederiz. Bu işlem algoritmik olarak daha rahat uygulanabilir.

### 15.1 Ayrık Zamanda Diğer Düzlemler

Sürekli zamandaki $s$ ve $\omega$ düzlemlerinin yerini burada $z$ ve büyük $\Omega$ alır. Z dönüşümünden ve ayrık zamanlı Fourier dönüşümünden (discrete time Fourier transform) faydalanacağız:

- $h[n]$ biliniyorsa $H(z)$ hesaplanabilir. $H(z)$ biliniyorsa ters Z dönüşümüyle $h[n]$ bulunur.
- $H(\Omega)$ biliniyorsa ters Fourier dönüşümüyle $h[n]$ bulunur.
- $x[n]$'in ayrık zamanlı Fourier dönüşümü $X(\Omega)$, Z dönüşümü $X(z)$'dir.
- Frekans cevabı $H(\Omega)$, transfer fonksiyonu $H(z)$'dir. Sürekli zamanda $H(s)$ demiştik, gösterimler böyle değişir.

Burada da konvolüsyon yerine diğer düzlemlerde çarpma yapabiliriz:

$$Y(\Omega) = X(\Omega)\,H(\Omega), \qquad Y(z) = X(z)\,H(z)$$

Sonra ters dönüşümle $y[n]$'e ulaşılır. Bu eşitlikler, bölüm 16'daki diziler ve sürekli örnek üzerinde $z$, $s$ ve $\omega$ düzlemlerinde birer noktada sayısal olarak denendi ve sağlandı.

> **Ders sonrası not:** Hoca buradaki $H(\Omega)$ için "transfer fonksiyonu veya frekans cevabı" dedi. Kendi kullandığı adlandırmaya göre $H(\Omega)$ frekans cevabı, $H(z)$ transfer fonksiyonudur.

### 15.2 Nedensel Durumlar ve Özellikler

Sınırlar sürekli zamandakiyle aynı mantıkla daralır:

- **Genel LTI sistem:** $y[n] = \sum_{k=-\infty}^{\infty} x[k]\,h[n-k]$
- **Nedensel sistem:** $y[n] = \sum_{k=-\infty}^{n} x[k]\,h[n-k]$
- **Nedensel giriş:** $y[n] = \sum_{k=0}^{\infty} x[k]\,h[n-k]$
- **İkisi de nedensel:** $y[n] = \sum_{k=0}^{n} x[k]\,h[n-k]$

Bir yerden sonra her şey sıfırsa bütün değerleri toplamak zorunda değiliz. Değişme, birleşme ve dağılma özellikleri de aynen geçerlidir. Kaskad ve paralel sistemlerin özellikleri değişmez.

### 15.3 Adımlar

1. İki işaret $i$ (veya $k$) cinsinden yazılır: $x[i]$, $h[i]$.
2. Biri ters çevrilir: $h[-i]$ ya da $x[-i]$.
3. Her $n$ için ötelenir, örtüşen bütün değerler çarpılıp toplanır.

$x[i]$ bir dizi, $h$ bir dizi, sonuç $y[n]$ de bir dizidir. Her çarpıp toplama adımı $y[n]$'in bir elemanını verir.

## 16. Örnek: $\{2, 2, 1\}$ ile Beş Elemanlı Bir Dizinin Konvolüsyonu

**Verilen.** Slayttaki işaret $x[n] = \{\underline{2}, 2, 1\}$. Alt çizgi $n=0$ noktasını gösterir. Diğer yerlerde işaret sıfırdır.

Hoca önce $h[n]$'nin beş tane 1'den oluştuğunu düşünerek çözdü. Sonra slayta bakınca değerlerin 3 olduğunu fark etti ve yeniden çözdü. İki çözüm de öğreticidir.

### 16.1 Önce Beş Tane 1 ile

$h[n] = \{\underline{1}, 1, 1, 1, 1\}$, $n = 0..4$ alalım. $h[-i]$ dizisi $i = 0, -1, -2, -3, -4$ noktalarında 1'lerden oluşur.

Hoca bunu önce bir adım geriye alıp başladı. O konumda hiçbir örtüşme yoktur ve sonuç sıfırdır. Sonra birer birim kaydırdı:

| $n$ | Örtüşen çarpımlar | $y[n]$ |
|---|---|---|
| $-1$ | yok | $0$ |
| $0$ | $2 \cdot 1$ | $2$ |
| $1$ | $2 \cdot 1 + 2 \cdot 1$ | $4$ |
| $2$ | $2 \cdot 1 + 2 \cdot 1 + 1 \cdot 1$ | $5$ |
| $3$ | $2 \cdot 1 + 2 \cdot 1 + 1 \cdot 1$ | $5$ |
| $4$ | $2 \cdot 1 + 2 \cdot 1 + 1 \cdot 1$ | $5$ |
| $5$ | $2 \cdot 1 + 1 \cdot 1$ | $3$ |
| $6$ | $1 \cdot 1$ | $1$ |
| $7$ | yok | $0$ |

Sonuç: $y[n] = \{\underline{2}, 4, 5, 5, 5, 3, 1\}$, $n = 0..6$. `numpy.convolve` ile de aynı çıktı.

> **Ders sonrası not:** Hoca başlangıç konumunu "$h[-i+1]$" diye yazdı. Anlattığı örtüşmesiz konum ise $n=-1$'e, yani $h[-1-i]$'ye karşılık gelir. $h[1-i]$ yazılsaydı $n=1$ konumu olurdu ve orada $y[1]=4$ olduğu için sonuç sıfır çıkmazdı.

Hoca sıfırdan farklı değerlerin nerede başlayacağının önceden görülebileceğini söyledi. İki işaretin de ilk değeri sıfır noktasındadır, demek ki sıfırdan itibaren örtüşme vardır. Değerler negatif olsaydı sonuçta negatif değerler de görülebilirdi. Son nokta ise üst sınırlardan bulunur (bkz. bölüm 16.3).

### 16.2 Slayttaki Gerçek Değerlerle: Beş Tane 3

Slayta bakıldığında $h[n] = \{\underline{3}, 3, 3, 3, 3\}$ olduğu görülür. Hoca burada kısa olan $x$'i ters çevirdi. Ters çevirme şöyle işler: $x[0]=2$ yerinde kalır, $x[1]=2$ eksi 1 noktasına, $x[2]=1$ eksi 2 noktasına gider. Yani $x[-i]$ dizisi $i = -2, -1, 0$ noktalarında $\{1, 2, 2\}$ olur.

Hoca işlemi önce tahtada, sonra slayttaki adımlardan iki kez yaptı. Aynı sonuç çıktı:

| $n$ | Örtüşen çarpımlar | $y[n]$ |
|---|---|---|
| $n<0$ | yok | $0$ |
| $0$ | $3 \cdot 2$ | $6$ |
| $1$ | $3 \cdot 2 + 3 \cdot 2$ | $12$ |
| $2$ | $3 \cdot 2 + 3 \cdot 2 + 3 \cdot 1$ | $15$ |
| $3$ | $3 \cdot 2 + 3 \cdot 2 + 3 \cdot 1$ | $15$ |
| $4$ | $3 \cdot 2 + 3 \cdot 2 + 3 \cdot 1$ | $15$ |
| $5$ | $3 \cdot 2 + 3 \cdot 1$ | $9$ |
| $6$ | $3 \cdot 1$ | $3$ |
| $n>6$ | yok | $0$ |

Sonuç:

$$y[n] = \{\underline{6}, 12, 15, 15, 15, 9, 3\}, \quad n = 0..6$$

`numpy.convolve`, yazdığımız çift döngü ve eleman eleman frekans çarpımı (7 noktalı DFT) aynı diziyi verdi.

> **Ders sonrası not:** Hoca sonucu iki kez sözlü okurken "15"i dört kez saydı ("6, 12, 15, 15, 15, 15, 9, 3"). Doğru dizide üç tane 15 vardır ve dizi 7 elemanlıdır. Kendi adım adım hesabı da bunu verir.

Sürekli zamandaki gibi burada da sola, yani $n<0$'a doğru bakmaya gerek yoktur, sonuçlar hep sıfırdır.

### 16.3 Sonucun Aralığı

$x[n]$ sıfırdan ikiye, $h[n]$ sıfırdan dörde kadar tanımlıdır. $y[n]$ sıfırdan başlar ve üst sınırların toplamına kadar gider: $2 + 4 = 6$. Bunun dışında bütün değerler sıfırdır.

> **Ders sonrası not:** Hoca önce üst sınır için iki kez "$2 + 4 - 1$" dedi, ikincisinde kendi düzeltti. Doğrusu son indisin $n_2 + m_2$ olmasıdır. "Eksi bir" uzunluk hesabında kullanılır: Eleman sayısı $L_x + L_h - 1 = 3 + 5 - 1 = 7$'dir.

Hoca bu işlemin algoritmik yazımını da anlattı. $y[n]$ girişleri gibi bir vektördür ve iki toplam sembolü, yani iki döngü döner. Dıştaki döngü $n$ üzerinden gider. Bu örnekte iki işaret de sıfırdan başladığı için $n$ sıfırdan başlar, $4 + 2 = 6$'ya kadar gider. İçteki döngü $i$ üzerinden, $y$'nin o $n$'deki değerini hesaplar. Aralık negatif değerler de içerebilir, örneğin eksi birden dörde gidebilir. Bunda bir sakınca yoktur.

> **Hocanın vurgusu:** Konvolüsyon bizim için çok temel bir işlemdir, diğer işlemler de bundan türer. Ters çevir, kaydır, çarp ve topla adımlarını kağıt üzerinde hem ayrık hem sürekli zamanda yapabilmek gerekir. Ayrık zaman kolaydır, sürekli zamanda biraz daha zor olan integralin çarpımları ya da sınırlarıdır. Burada niyet işi zorlaştırmak değil, parçalı integralleri toplayıp sonuca gitmenizi görmektir.

## 17. Neden Ters Çeviriyoruz?

**Soru:** Püf nokta $x$ işaretini en başta ters çevirmek, yani y eksenine göre simetriğini almak, sonra bunları birbiriyle çarpılacak şekilde sıra sıra kaydırmak değil mi?

**Cevap:** Aynen. Hem ayrık zamanda hem sürekli zamanda tersini alıyoruz. Burada aslında bütün durumlar deneniyor: Bir işaretin bütün değerleri ile diğerinin bütün değerleri birbiriyle çarpılıp sonuca dahil ediliyor. Görüntü işlemede de aynısı vardır. Bir kişinin iris bölgesini bulmak için, resmin başından başlanıp bütün resim taranır, en iyi örtüşmenin görüldüğü yerde pik değer alınır. Bunun için bütün noktaları gezmek gerekir.

**Soru:** Yine de neden simetrik alıyoruz? Örneğin $\{2,2,1\}$'i neden $\{1,2,2\}$ yapıyoruz?

**Cevap:** İşaretlerden biri $\{1,2,3\}$ olsun. Önce bu işaretin ilk değeriyle diğerinin ilk değerini çarpmak istiyorum. Bunun için onu ters çevirip $\{3,2,1\}$ yapıyorum. Böylece 1, diğer işaretin ilk değeriyle karşılaşır. Sonra kaydırıp 1 ile ikinci değeri, 2 ile ilk değeri çarpıp topluyorum, böyle devam ediyor. Yani ilk değerler ilk başta çarpılır.

Bu tek yol da değildir. Hoca dairesel konvolüsyon gibi farklı yöntemlerin olduğunu, onlarda işlemin sondan başlatılıp geriye dönebildiğini söyledi. Ama bu dersteki normal konvolüsyon tanımı gösterdiğimiz tanımdır.

> **Ders sonrası not:** Hocanın bu kısa dökümde 3. adım için andığı "1 ile 2, 2 ile 2, 3 ile 2" çarpımları tam değildir. İşaretler $\{1,2,3\}$ ve $\{2,2,1\}$ ise üçüncü değer $1 \cdot 1 + 2 \cdot 2 + 3 \cdot 2 = 11$'dir (`numpy.convolve` sonucu: $\{2, 6, 11, 8, 3\}$).

## 18. Konvolüsyonun Uygulamaları: Görüntü İşleme ve CNN

Molanın ardından hoca, gördüklerimizin ne işe yaradığından söz etti. Derin öğrenmenin en çok kullandığı ağlardan biri **konvolüsyonel sinir ağıdır** (CNN). Burada konvolüsyon iki boyutludur: Bir resim vardır ve genelde $3 \times 3$'lük iki boyutlu bir filtre vardır. Filtre resmin başına uygulanır, birer piksel sağa kaydırılır, satır bitince aşağı kaydırılır ve bütün resim dolaşılır. Filtrenin karakteristiğine göre bir sonuç elde edilir.

Bu sonuç örneğin bir resmin kenarlarının bulunması (edge detection) olabilir. Slaytta aynı resme Canny, Gauss farkı (difference of Gaussian) ve Laplace yöntemlerinin uygulanmış halleri gösterildi.

- **Laplace filtresi:**

$$\begin{bmatrix} 0 & 1 & 0 \\ 1 & -4 & 1 \\ 0 & 1 & 0 \end{bmatrix}$$

Negatifi alınırsa ortadaki değer pozitif, diğerleri negatif olur.

- **Prewitt filtresi:** Dikey kenarları bulmak için ortadaki değerler sabit tutulur. Filtre, bir yanda çarptığı piksellerden öbür yanda çarptığı piksellerin farkını alır. Sonuçta konvolüsyon çarpıp toplayacağı için bu fark dikey çizgileri ortaya çıkarır. Diğer yöndeki filtre aynı farkı öbür yönde alır ve yatay çizgileri bulur.
- **Sobel filtresi:** Prewitt'in biraz farklısıdır. Prewitt'te 1, 1, 1 olan değerler burada 1, 2, 1 olur ve sonuç biraz daha iyidir.

> **Ders sonrası not:** Hoca Laplace filtresinin son satırını bir yerde "0, 1, 4" diye okudu (altyazıdaki biçim). Doğrusu "0, 1, 0"dır: İlk iki satır ve hocanın simetri tarifi bunu gösterir. Filtrenin katsayı toplamı 0 çıkar, "0, 1, 4" olsaydı 4 olurdu. Hoca yatay ve dikey sonuçları anlatırken de kelimeleri bir ara karıştırdı. Doğrusu dikey filtrenin dikey, yatay filtrenin yatay kenarları bulmasıdır.

> **Ek bilgi (derste anlatılmadı):** Dikey kenar için Prewitt ve Sobel filtrelerinin yaygın biçimi büyük olasılıkla sırasıyla $\begin{bmatrix} -1 & 0 & 1 \\ -1 & 0 & 1 \\ -1 & 0 & 1 \end{bmatrix}$ ve $\begin{bmatrix} -1 & 0 & 1 \\ -2 & 0 & 2 \\ -1 & 0 & 1 \end{bmatrix}$'dir. Bu matrisler, altyazıdaki "ortadakiler sabit", "1, 1, 1" ve "1, 2" tarifleriyle uyumludur. Yatay kenar için transpozları kullanılır.

<!-- BELİRSİZ: Prewitt ve Sobel matrisleri slaytta veya web sayfasında gösterildi, altyazıda değerleri tam okunmuyor. -->

Derin öğrenme çıkmadan önce resimden veya videodan özellik çıkarmak için farklı teknikler kullanılıyordu. Derin öğrenmeyle özellik çıkarımı konvolüsyon işlemiyle yapılıyor. Hocaya göre böylece resmin içindeki bilgi daha az kayboluyor, veri madenciliği ve örüntü tanıma uygulamaları daha başarılı oluyor. Bunun arkasındaki iş konvolüsyondur.

Konvolüsyonun üç, dört boyutlusu da olur, örneğin video üzerinde konvolüsyon yapılır. Bugün iki ve üç boyutlu konvolüsyon yapacak özel çipler geliştiriliyor, FPGA ile tasarımlar yapılıyor. Bilgisayara bir kamera bağlayıp anlık görüntüyü alarak arka planda paralel programlamayla konvolüsyon uygulayabilir, bir filtre yapabilirsiniz.

<!-- BELİRSİZ: 02:08:51 civarındaki bağlantı örneği altyazıda "USB", "DCP portu" diye geçiyor; bağlantı türü net değil. -->

## 19. Konvolüsyonun Algoritmik Maliyeti

Konvolüsyon toplamı iki iç içe döngüyle hesaplanır, biri $n$, biri $i$ üzerinden. Hoca bunun karmaşıklığını sordu, sınıftan doğru cevap geldi: Bu iki döngü $n^2$ defa döner. Bu yüzden konvolüsyon biraz maliyetlidir.

Elimizde $h(t)$ yerine $H(\omega)$ veya $H(s)$ varsa doğrudan çarpma yapabiliriz. Bunlar birer dizi olacağı için, karşılıklı çarpmanın maliyeti $n$'dir. Ayrık zamanda da $h[n]$'den $H(\Omega)$ veya $H(z)$'yi bularak yine $n$'lik bir işlem yapılabilir. Bu, algoritmayı iyileştirir.

> **Ders sonrası not:** $n$'lik maliyet yalnız karşılıklı çarpma adımı içindir. Dönüşümlerin kendisi de hesaplanmalıdır. Hoca bir sonraki bölümde dönüşüm integralinin de $n^2$'lik olduğunu söylüyor. Bu yüzden toplam kazanç, büyük olasılıkla ancak hızlı Fourier dönüşümüyle ($n \log n$) ortaya çıkar. Uzunlukları farklı dizilerde doğrudan yöntemin çarpma sayısı da tam $n^2$ değil, uzunlukların çarpımıdır: Bölüm 16'daki örnekte $3 \times 5 = 15$ çarpma sayıldı. Hoca bu paragrafta "sürekli zamanda" dedi ama andığı $h[n]$, ayrık zamandadır.

## 20. Fourier ve Laplace Dönüşümleriyle İlişki

Hocaya göre Fourier, Laplace ve Z dönüşümlerinin hepsi konvolüsyondan geliyor. Fourier dönüşümü:

$$X(\omega_0) = \int_{-\infty}^{\infty} x(t)\, e^{-j\omega_0 t}\, dt$$

Burada $x(t)$ sabit tutulur ve $h(t)$ yerine karmaşık sinüzoidal bir işaret gelir. Böylece işaretin bu sinüzoidle korelasyonuna bakıyoruz. Laplace dönüşümü de hemen hemen aynıdır, $s$ yerine $j\omega$ geldiğinde Fourier formu elde edilir:

$$X(s) = \int_{-\infty}^{\infty} x(t)\, e^{-st}\, dt$$

> **Ders sonrası not:** Bu ifade "konvolüsyon" olarak değil, hocanın da dediği gibi bir benzerlik (korelasyon) hesabı olarak anlaşılmalıdır. Konvolüsyonda $t$'ye bağlı bir kaydırma vardır ve sonuç zamanın fonksiyonudur. Dönüşümde ise kaydırma yoktur, sonuç $\omega$ veya $s$'nin fonksiyonudur.

Hoca bu integralin karmaşıklığını da sordu. Böyle bir integral kodlanabilir. $x$ ve üstel terimin ikisi de $t$'ye göre değiştiği için iç içe iki döngü ve yine $n^2$'lik bir maliyet vardır. Bu, bir bakıma iki vektörün kartezyen çarpımına benzer. Bu vektörlerin bütün çarpımlarını toplayıp yeni bir vektör elde ederiz. Hartley dönüşümü gibi diğer integral dönüşümleri de aynı mantıkla çalışır, yalnız kullanım alanları farklıdır.

> **Ders sonrası not:** Hoca çift döngüyü iki ayrı zaman değişkeniyle ($t_1$, $t_2$) anlattı. İntegralde $x(t)$ ile üstel terim aynı $t$'yi kullanır. Çift döngü büyük olasılıkla şöyle oluşur: Dıştaki döngü frekans değerleri ($\omega$ veya $s$), içteki döngü zaman örnekleri üzerindendir.

## 21. Dersin Bundan Sonraki Akışı

Hoca dersin akış şemasını gösterdi. Sinyaller, sistemler, özellikleri ve temel işlemlerden konvolüsyona kadar geldik. Buradan sonra konular ayrık zamanlı ve sürekli zamanlı sistemler olmak üzere ikiye ayrılacak:

- **Sürekli zaman tarafı:** Diferansiyel denklemler, sıfır durum cevabı (zero state response), sıfır giriş cevabı (zero input response) ve karakteristik denklem. Bunlar sürekli zaman konvolüsyonuyla da ilgilidir. Laplace dönüşümü de burada yer alır.
- **Ayrık zaman tarafı:** Ayrık zamanlı Fourier dönüşümü, hızlı Fourier dönüşümü ve ayrık Fourier dönüşümü gibi bilgisayar temelli analiz yöntemleri ile Z dönüşümü. Bunların bir kısmı bu derste, bir kısmı sayısal işaret işleme dersinde anlatılır. Burada lazım olduğu kadar görülecektir.

## 22. Sistem Modelleme

Hoca önce bu dersin nerede kullanıldığını konuştu. Birçok programda okutulan bir konu olan sistem modellemede, bir mühendislik tasarımı yaparken herhangi bir sistemin modelini ortaya koymak zorundayız. Model, elimizdeki enformasyondan bilgiye gitmemizi ve geleceğe yönelik tahmin yapmamızı sağlar. Konvolüsyonel sinir ağları ve örüntü tanıma da aslında bir model tahmin eder: Verinin karakteristiğini geçmiş örneklerden öğrenip geleceğe yönelik tahmin yapar. Böyle bir imkan yoksa, elimizdeki bilgiyle bir fonksiyon veya denklem üretiriz. Buna matematiksel modelleme denir.

Örnekler:

- **Devreler:** RLC devresinde direnç için $V = I \cdot R$ vardır. $L$ işin içine girince akımın türevi, $C$ girince gerilimin türevi işe karışır. Kirchhoff'un gerilim ve akım kanunları, gerilim bölücüler hep diferansiyel denklemlerle modellenen yapılardır.
- **Mekanik:** Kütle, yay, sönüm (damping) ve Newton kanunları yine diferansiyel denklemler verir.
- **Diğer alanlar:** İnşaat, hidrolik, kimya gibi bütün mühendislik alanlarında bir sistem modeli ortaya koymak gerekir. Kontrol mühendisliği de aslında daha çok bununla uğraşır.

Hoca bir de sera örneği verdi. Bir derste, bir seranın sıcaklığının uzaktan kontrol edilmesi proje olarak verilmişti. Uzaktan bağlantı işin kolay tarafıdır. Asıl iş, seranın hacmi, kapladığı alan, dış ve iç sıcaklık gibi sıcaklığı etkileyen parametreleri belirlemek ve onlardan bir denklem kurmaktır.

RLC devresinde parametreleri biliyoruz ($R$, $L$, $C$, akım, gerilim). Ama aralarındaki ilişkiyi yazmak alan bilgisi gerektirir. Bizden bir mekanik sistemi modellememiz beklenmiyor. Model, alan bilgisiyle ortaya konur ve normal bir denklem de olabilir, diferansiyel denklem de. Sonra sistemin kararlı çalışıp çalışmayacağı, sıfır ve kutup noktaları, yani "sistem nerede patlıyor, nerede çalışıyor" analizi bu dersin ya da sayısal işaret işlemenin konusudur.

## 23. Deterministik ve Olasılıksal Sistemler

Parametreler doğru belirlenemiyorsa, yani bir RLC devresi gibi hazır bir denklem yoksa ne olur? Gözlemler ve deneyler yapıp veri toplarız. Hoca bunu Covid teşhisi üzerinden sordu:

**Soru:** Covid neye göre teşhis ediliyor?

**Cevap:** Sınıftan gelen cevaba göre PCR testi yapılır. Teste gerek duyulması için de ateş, nefes darlığı, öksürük gibi belirtilere bakılır.

**Soru:** Peki burada yüzde 100 başarı var mı?

**Cevap:** Hayır, PCR testinde bile yoktur. Çünkü burada bir tahmin vardır. Bir sürü parametreye bakılır, belli bir süreç çalışır ve bu fonksiyonun sonucu yüzde 100 doğru değildir.

Buna karşılık RLC devresine $R$, $L$, $C$ ve diğer parametreleri girdiğinizde, ısı ve enerji kaybı dışında devre hep aynı çalışır. Bu **deterministik** bir sistemdir. Tahmin sistemleri ve yapay zeka ile ilgili sistemler ise **olasılıksal (probabilistic, stokastik)** sistemlerdir. Aynı mantıkla bir model oluşturulur ama model yüzde 100 çalışmaz.

Yine de modelin olması hiç olmamasından iyidir. Belki on yıl sonra veri daha çok toplanmış ve karakteristik daha çok ortaya çıkmış olacak, "Covid'in asıl belirtileri şunlarmış" diyeceğiz. Bütün bu sistemlerin ortak yanı şudur: Sistemi kontrol eden parametreler tespit edilir, bir araya getirilerek model kurulur ve model geleceğe yönelik çıkarım için kullanılır.

## 24. Model Örneği: İki Bilgisayar Arasındaki Kablo

İki bilgisayar arasında kablo ile veri göndermek istediğimizi düşünelim. İki iletken kullanılır ve bunlar bir yalıtkanla ayrılır. Hatlar arasında girişim oluşur. Bu bozucu etkiyi azaltmak için kablolar birbirine dolandırılır, buna bükümlü çift (twisted pair) kablo denir. Koaksiyel (coaxial) kablo ise eski televizyonların anten kablosudur. İletken bir yalıtkanla bu şekilde yalıtılmıştır.

Uzunlukla beraber direncin arttığını biliyoruz: Uzunluk $L$ artarsa direnç artar, kesit $A$ artarsa direnç azalır.

> **Ders sonrası not:** Hoca bağıntıyı emin olmadan "$R$, $L$ bölü $A$ mıydı?" diye andı. Tam bağıntı büyük olasılıkla $R = \rho L / A$'dır. Burada $\rho$ malzemenin özdirencidir. Söylediği artma ve azalma yönü doğrudur.

Bu bilgiden yola çıkarak model kurulur. Kaynak tarafındaki devre Thevenin eşdeğeriyle, yani bir kaynak ve bir dirençle en sade biçimde yazılır. Buna kablo modeli eklenir. Karşı tarafın da Thevenin modeli vardır. Bu modellerin toplamı yapacağımız işin toplamını verir. Girişe $x(t)$ verildiğinde karşıda oluşan $y(t)$ test edilir.

Model kurulunca $y(t)$ ile $x(t)$ arasında bir bağıntı yazmak gerekir. Burada Kirchhoff, Ohm gibi uzmanlık bilgisi kullanılır. Slayttaki yol şöyleydi:

$$x(t) = v_R(t) + y(t), \qquad v_R(t) = R\, i(t)$$

Akım yerine yazılınca birinci mertebeden türevli bir denklem ortaya çıkar. Akımın kondansatör üzerinden $i(t) = C\, dy/dt$ olarak yazıldığı kabul edilirse (ara adım eklendi):

$$RC\,\frac{dy(t)}{dt} + y(t) = x(t)$$

<!-- BELİRSİZ: Slayttaki model şeması ve denklemin tam katsayıları altyazıda okunmuyor. Yukarıdaki son denklem, altyazıdaki adımlardan ve "birinci dereceden türevli denklem" sözünden kuruldu. -->

Hoca burada bir soru sordu: $y$ ile $x$ arasındaki ilişkiyi bulmamızı engelleyen terim hangisidir?

**Cevap:** $x(t)$'yi biliyoruz, bu bizim girişimizdir. Örneğin $A\sin(500\pi t)$ gibi bir gerilim kaynağıdır. $y(t)$ aradığımız şeydir. Engel, $y$'nin türevidir. O türevden kurtulmadan sistemin nasıl davranacağını çözemeyiz. Diferansiyel denklem çözmenin amacı budur: $y(t)$ ile $x(t)$ arasında **türevsiz** bir ilişki kurmak.

Devrede RLC bileşenleri sabit sayılar olduğu için sistem doğrusaldır. Toplamsallık ve çarpımsallık uygulanıp doğrusallık kontrol edilebilir. Ancak asıl iş denklemi çözüp çıktıyı bileşenlerden bir bağıntı olarak yazmaktır. Sıra şudur: Önce düşünce, sonra şema, sonra matematik, sonra çözüm. Analitik çözüm yapılamıyorsa diferansiyel denklemlerin sayısal çözüm teknikleri de vardır.

## 25. Model Örneği: Araç Süspansiyon Sistemi

Arabalarda kullanılan süspansiyon sisteminde bir yay, ani durumlarda sönümleyen bir emici (absorber) ve teker vardır. Yolun da bir yapısı vardır. Bu şemadan, girişe karşılık çıkışı veren sistemin modeli dördüncü mertebeden bir diferansiyel denklem olarak çıkar.

Bu denklemde bilinen $x(t)$ ve aranan $y(t)$ dışında dört tane türevli terim vardır: birinci, ikinci, üçüncü ve dördüncü türev. Hepsinden kurtulup $y(t)$ ile $x(t)$ arasındaki ilişkiye bakmamız gerekir. Bunun için örneğin karakteristik denklem tekniği kullanılır:

$$a_4 r^4 + a_3 r^3 + a_2 r^2 + a_1 r + a_0 = 0$$

Bu çözümler özel çözüm ve genel çözüm olmak üzere iki parçadan oluşur ve diferansiyel denklemler dersinde uzun uzun anlatılır. Aynı yöntemin özyinelemeli (recursive) algoritmalarda da karşımıza çıkacağını hoca belirtti.

<!-- BELİRSİZ: Süspansiyon denkleminin slayttaki katsayıları altyazıda geçmiyor; yalnız dördüncü mertebe olduğu ve karakteristik denklem biçimi söyleniyor. -->

Özetle bir çıktı bulmak için sürekli zamanda diferansiyel denklem (differential equation), ayrık zamanda ise ona çok benzeyen fark denklemi çözülür. Bu modelle tahmin yapılır: Yolun eğimi şu olduğunda, yayın katsayıları bu olduğunda araç nasıl bir konum verir, parametreler yerine konularak test edilir. En iyi sistemi bulmak bir optimizasyondur. Hocaya göre markalar arasındaki farkı yaratan da parametrelerin doğru tespit edilmesidir: Önce prototip inşa edilir, sonra diferansiyel denklem kullanılarak parametreler optimize edilir.

> **Hocanın vurgusu:** Bu dersin amacı diferansiyel denklemleri çözmek değil, ne işe yaradıklarını ve nerede kullanıldıklarını söylemektir. Makineci ya da kontrolcü olsaydınız çözmek gerekirdi.

## 26. Diferansiyel Denklemlerin Özellikleri

Sinyallerin ve sistemlerin özellikleri olduğu gibi diferansiyel denklemlerin de özellikleri vardır.

> **Hocanın vurgusu:** Bu kavramları genel kültür olarak bilmek gerekir. Doğru-yanlış tarzında sorulabilecek şeylerdir.

- **Doğrusallık:** Katsayılar sabitse, yani hiçbiri $t$'ye bağlı değilse ve doğrusal olmayan terim yoksa denklem doğrusaldır. Doğrusal olmayan terim örnekleri: $y^5$ gibi bir kuvvet, ya da $k$. türevin $p$. türevle çarpıldığı $y^{(k)} \cdot y^{(p)}$ gibi bir çarpım.
- **Mertebe (order):** Denklemdeki en yüksek türevin derecesidir. En yüksek türev üçüncü türevse denklem üçüncü mertebedendir.
- **Derece (degree):** En yüksek türevin kuvvetidir. Örneğin en yüksek türevin karesi varsa "üçüncü mertebeden ikinci dereceden" denir. Hoca ikisinin de bazen "order" diye söylendiğini, ama birincisinin order, öbürünün degree olduğunu belirtti.
- **Değişkenler:** $x$ bağımsız, $y$ bağımlı değişkendir. Hedefimiz $y = f(x)$'i bulmak, yani türevlerden kurtulmaktır.

> **Ders sonrası not:** Hoca doğrusallık tanımında katsayıların sabit olmasını şart koydu. Bu tanım derste kullanılan sabit katsayılı denklemler içindir. Katsayıları $t$'ye bağlı olup yine de doğrusal sayılan denklemler büyük olasılıkla vardır, onlar değişken katsayılı doğrusal denklemlerdir. Hoca bir yerde $y$ için de "independent" dedi. Hemen sonraki özetinde söylediği gibi $y$ bağımlı değişkendir.

<!-- BELİRSİZ: Doğrusal olmayan örneklerin slayttaki yazımı altyazıda net değil ("y üzeri 5", "k. dereceden türevi p. dereceden türevle çarpıyor"). Slaytta türev mi kuvvet mi olduğu okunmuyor. -->

Hoca bir şema üzerinden denklemlerin ne kadar çeşitli olduğunu da gösterdi: Birinci, ikinci, $n$. mertebeden; doğrusal, doğrusal olmayan; homojen, homojen olmayan; adi ve özel denklemler. Her birinin çözüm yöntemi çok farklıdır. Bu yüzden konu koskoca bir ders olarak okutulur.

**Homojen denklem.** Bütün terimler $y$'nin türevlerini ve $y$'nin kendisini içerir. Sağ taraf sıfırdır, $x$'in kendisine ait bir terim yoktur. Hocanın örneği:

$$y^{(4)} + 3y^{(3)} + 4y^{(2)} + y' + y = 0$$

**Adi diferansiyel denklem (ordinary differential equation, ODE).** Tek bir bağımsız değişken vardır. $y$ yalnız $x$'e göre değişir, bütün türevler $x$'e göredir. Oysa bir RLC devresinde olduğu gibi $y$, birden fazla değişkene de bağlı olabilir. MATLAB'de de ODE çözücü bir paket vardır. Denklemi ona yazarsınız, otomatik çözer.

> **Ders sonrası not:** Altyazıda "ODE Sol" diye geçen ve hocanın analitik çözüm ürettiğini söylediği paket büyük olasılıkla MATLAB'in ODE çözücüleridir. Bu çözücülerin bir kısmı (örneğin `ode45`) büyük olasılıkla sayısal çözüm üretir. Analitik çözüm için `dsolve` kullanılır.

## 27. Doğrusal Sabit Katsayılı Denklemlerin Çözüm Yapısı

Hoca dersin kalanında, doğrusal sabit katsayılı denklemlerin homojen şartlar altındaki çözümlerinden bahsetti. Bunları genel kültür olarak verdiğini yineledi.

Genel denklem, sol tarafta $y$'ye, sağ tarafta giriş olan $f$'ye bağlı terimlerden oluşur. Çıkış tarafındaki en yüksek mertebe $n$, giriş tarafındaki en yüksek mertebe $m$ olsun ve $n > m$ kabul edilsin. Operatör gösteriminde $k$. türev $D^k$ ile yazılır:

$$\sum_{k=0}^{n} a_k D^k y(t) = \sum_{k=0}^{m} b_k D^k f(t)$$

<!-- BELİRSİZ: Genel denklemin slayttaki yazımı altyazıda okunmuyor; katsayı adları ($a_k$, $b_k$) ve toplam biçimi "operasyonel notasyon" anlatımından kuruldu. -->

Doğrusallık sayesinde denklem iki parçada çözülür:

- **Sıfır giriş cevabı (zero input response):** Giriş sıfır kabul edilir, $f(t) = 0$. Yani sağ taraf sıfırdır. Homojen şart budur, sağ taraftaki terime zorlama fonksiyonu (forcing function) denir.
- **Sıfır durum cevabı (zero state response):** Sağ taraf sıfır alınmadan bulunan ikinci çözümdür.

İki çözüm doğrusal kombinasyon olarak birleştirilir ve genel çözüm elde edilir.

> **Ders sonrası not:** Hoca sıfır durum çözümünü "independent komponentin sıfır olduğu durum" diye tarif etti. Dersin başındaki tekrarda söylediği şeyle uyumlu olarak burada sıfır olan şey büyük olasılıkla başlangıç koşullarıdır. Yani sıfır durum cevabı, başlangıç koşulları sıfırken girişin oluşturduğu çıktıdır.

Çözümde karmaşık sayılar da devreye girer, çünkü iş dördüncü dereceden bir denklemin bile köklerini bulmaya varabilir.

## 28. Sıfır Giriş Çözümü Örnekleri

Burada izlenen yol hep aynıdır: Sağ tarafı sıfır kabul et, karakteristik denklemi yaz, kökleri bul, katsayıları başlangıç koşullarından çek.

### 28.1 Farklı Reel Kökler

**Verilen.**

$$\frac{d^2y}{dt^2} + 3\frac{dy}{dt} + 2y = \frac{df}{dt}, \qquad y(0) = 0, \quad y'(0) = -5$$

İkinci mertebeden bir türev, birinci mertebeden bir türev ve $y$'nin kendisi var. Sağ tarafta $f$'nin birinci mertebeden türevi var.

**Adım 1.** Sağ taraf sıfır kabul edilir ve karakteristik denklem yazılır:

$$\lambda^2 + 3\lambda + 2 = 0$$

**Adım 2.** Kökler bulunur. İkinci dereceden olduğu için kolaydır:

$$(\lambda+1)(\lambda+2) = 0 \;\Rightarrow\; \lambda_1 = -1, \quad \lambda_2 = -2$$

**Adım 3.** Üstel çözüm yazılır:

$$y(t) = c_1 e^{-t} + c_2 e^{-2t}$$

**Adım 4.** Başlangıç koşulları yerine yazılır:

$$y(0) = c_1 + c_2 = 0$$

$$y'(0) = -c_1 - 2c_2 = -5 \;\Rightarrow\; c_1 + 2c_2 = 5 \quad \text{(ara adım eklendi)}$$

Birinci denklemden $c_1 = -c_2$ yazılırsa $c_2 = 5$, $c_1 = -5$ bulunur.

**Sonuç.**

$$y(t) = -5e^{-t} + 5e^{-2t}$$

`numpy` ile kökler ve katsayılar yeniden hesaplandı, aynı çıktı. Denklem dördüncü mertebeden Runge-Kutta ile sayısal olarak da çözüldü: $t=2$'de sayısal değer $-0{,}58510$, formül değeri $-0{,}58510$.

Hoca bir noktaya dikkat çekti. Normal bir denklem çözerken, örneğin $2x + 3 = 8$'de önce sağ tarafı sıfır kabul edip sonra çözmek gibi bir şey yapmayız. Diferansiyel denklemde ise farklı bir yol izlenir: Önce sağ taraf sıfır kabul edilir. Slaytta çözümün grafiği de çizilmişti.

> **Ders sonrası not:** Hoca bu çözüme "özel çözüm (particular)" dedi. Sağ taraf sıfır alınarak bulunan bu çözüm, kendi anlattığı adlandırmaya göre homojen çözümdür, yani sıfır giriş cevabıdır. Özel çözüm büyük olasılıkla sağ tarafın, yani girişin etkisinden gelen parçadır. Aynı düzeltme aşağıdaki iki örnek için de geçerlidir.

### 28.2 Çakışık Kök

Hoca bir sonraki örnekte de önce sağ tarafı sıfır aldı. Karakteristik denklemden çakışık kök çıktı. Bu durumda çözümün biçimi değişir: $c_2$'li terime bir de $t$ çarpanı eklenir.

$$y(t) = (c_1 + c_2 t)\,e^{\lambda t}$$

Başlangıç koşulları yerine yazıldığında $c_1 = 3$, $c_2 = 2$ bulundu. Yani çözüm $y(t) = (3 + 2t)\,e^{\lambda t}$ biçimindedir. Yine eşitliğin sağ tarafı dahil değildir, onu da dahil etmek istersek ekstra çözüm gerekir. Bu biçimin, çakışık köklü homojen denklemi sağladığı iki farklı negatif $\lambda$ için sayısal olarak denendi.

<!-- BELİRSİZ: Bu örneğin denklemi, çakışık kök $\lambda$ ve başlangıç koşulları slaytta; altyazıda geçmiyor. Yalnız $c_1=3$ ve $c_2=2$ söyleniyor. Kısa notta da yok, kare de bulunmuyor. -->

### 28.3 Karmaşık Kökler

Karakteristik denklemin bazı kökleri karmaşık çıkabilir. Hocanın gösterdiği örnekte çözüm modelinin terimleri $e^{-2t}$ ve $e^{j6t}$ çarpanlarını içeriyordu. Yani kökler $\lambda_{1,2} = -2 \pm j6$ biçimindedir (ara adım eklendi):

$$y(t) = c_1 e^{(-2+j6)t} + c_2 e^{(-2-j6)t}$$

Euler formülüyle $e^{\pm j6t} = \cos 6t \pm j \sin 6t$ olduğu için bu ifade kosinüs artı sinüslü terimlerden oluşur. Kosinüs değerleri yerine konup $c_1$, $c_2$ çekilir. Burada da eşitliğin sağ tarafı yoktur. O da gelirse ayrıca bir çözüm ekleyip genel çözümü bulmak gerekir.

> **Ders sonrası not:** Hoca çözüm kompleks olduğu için doğrudan çizilemeyeceğini söyledi. Katsayılar birbirinin eşleniği olduğunda iki terimin toplamı gerçeldir ve doğrudan çizilebilir. Sayısal denemede sanal kısım sıfır çıktı.

<!-- BELİRSİZ: Bu örneğin denklemi, başlangıç koşulları ve $c_1$, $c_2$ değerleri slaytta; altyazıda yok. Üstel terim altyazıda "E üzeri C6T" diye geçiyor, $e^{j6t}$ olarak okundu. -->

Hocanın özeti şudur: Diferansiyel denklem yapısı birçok sistemin modellenmesinde karşımıza çıkar, fark denklemleri de onun ayrık zamanlı karşılığıdır. Ama bu derste ayrıntısına girilmeyecektir.

## 29. Sıfır Noktası Başta Olmayan İşaretlerin Konvolüsyonu

Hoca dersin sonunda ayrık zamanlı konvolüsyon üzerine bir örnek daha çözdü. Bu örneğin farkı, işaretlerden birinin sıfır noktasından başlamamasıdır.

Metinlerde ve makalelerde ayrık bir sinyal verildiğinde, altı çizili ya da altında veya üstünde ok işareti olan değer **sıfır noktasını** gösterir.

**Verilen.**

$$x[n] = \{1, \underline{2}, 3\}, \quad n = -1..1 \qquad\qquad h[n] = \{\underline{1}, 2, 3\}, \quad n = 0..2$$

Hoca birini ters çevirip kaydırdı. İlk örtüşme $n=-1$'de olur. Çünkü $x$'in başlangıcı $-1$, $h$'nin başlangıcı $0$'dır.

| $n$ | Örtüşen çarpımlar | $y[n]$ |
|---|---|---|
| $-1$ | $1 \cdot 1$ | $1$ |
| $0$ | $1 \cdot 2 + 2 \cdot 1$ | $4$ |
| $1$ | $1 \cdot 3 + 2 \cdot 2 + 3 \cdot 1$ | $10$ |
| $2$ | $2 \cdot 3 + 3 \cdot 2$ | $12$ |
| $3$ | $3 \cdot 3$ | $9$ |

Sonuç:

$$y[n] = \{1, \underline{4}, 10, 12, 9\}, \quad n = -1..3$$

`numpy.convolve` aynı diziyi verdi, indisler de aşağıdaki kuralla bulundu. Sonuç eksi birden başlar ve üst sınırların toplamına, yani $1 + 2 = 3$'e kadar gider. Genel kural:

$$x[n]:\; n_1..n_2, \quad h[n]:\; m_1..m_2 \quad\Longrightarrow\quad y[n]:\; n_1+m_1 \,..\, n_2+m_2$$

Bir işaret daha geriden, örneğin $-3$'ten başlasaydı sonuç da daha geriden başlardı.

> **Hocanın vurgusu:** Sınırlara dikkat edin. İndisler doğru değilse sonuç kabul edilmez.

**Soru:** Daha önce hep sıfır noktasını ilk indis olarak aldık. Burada neden eksi bir var? Altı çizili değer girişte nasıl ifade edilecek?

**Cevap:** İşaretin değerleriyle birlikte indis bilgisi de alınmalıdır. Sinyaller illa sıfır noktasından başlamaz. Bir önceki örnekle hiçbir fark yoktur. Yalnız başlangıç noktası sıfırda değil eksi birde olduğu için ilk örtüşme orada gerçekleşir ve sonucu eksi birden itibaren göstermek gerekir.

**Soru:** Hangisini ters çevirdiğimizin önemi yok değil mi?

**Cevap:** Yok, istediğinizi yapabilirsiniz. Kısa olanı çevirmek daha kolaydır, ama çevirirken hangi noktanın nereye gittiğine, yani sınırlara dikkat etmelisiniz.

Hazır fonksiyonlar açısından da hoca MATLAB'deki `conv` fonksiyonunu gösterdi: İki dizi ($u$ ve $v$) alır ve konvolüsyon sonucunu verir. Kendi yazılan algoritmayla bu fonksiyonun aynı değerleri vermesi beklenir. İki boyutlu sürümü de vardır.

## Dersin Toparlaması

Bu derste bir LTI sistemin birim dürtü cevabı $h(t)$ biliniyorsa, herhangi bir girişe karşı çıkışın konvolüsyonla bulunabileceğini gördük. Yol, dürtü ayrıştırmasından, genişletilmiş doğrusallıktan ve zamanla değişmezlikten geçti ve bizi $y(t) = \int x(\tau)\,h(t-\tau)\,d\tau$ integraline, ayrık zamanda da $y[n] = \sum x[k]\,h[n-k]$ toplamına getirdi. İşlem hep aynıdır: $\tau$ düzlemine geç, kısa olanı ters çevir, kenarları bul, kaydır, örtüşen bölgelerde çarp ve topla ya da integre et. Dikdörtgen örneği yamuk bir çıkış verdi ($6t$, $6$, $18-6t$). Ayrık örnek $\{6, 12, 15, 15, 15, 9, 3\}$ dizisini verdi. Görüntü işleme ve CNN uygulamaları ile dönüşüm düzleminde konvolüsyonun çarpmaya dönüşmesi de konunun neden bu kadar temel olduğunu gösterdi.

İkinci yarıda sistem modellemenin amacını konuştuk. Mühendislikteki birçok model diferansiyel denkleme varır ve amaç $y$ ile $x$ arasında türevsiz bir ilişki kurmaktır. Klasik sıfır giriş çözümü adımlarını örneklerle gördük. Ancak bu derste bu denklemler klasik yolla değil, dönüşümlerle çözülecektir. Hoca sonraki adımları da söyledi: Sürekli zaman konvolüsyonundan birkaç analitik örnek daha çözülecek. Ardından genel olarak dönüşümlerin mantığı anlatılacak ve Fourier serilerine, sonra dönüşümlere geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
