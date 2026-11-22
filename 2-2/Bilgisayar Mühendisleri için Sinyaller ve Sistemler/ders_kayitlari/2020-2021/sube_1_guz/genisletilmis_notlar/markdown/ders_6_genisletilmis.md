# Ders 6 Genişletilmiş Notu: Sürekli Zamanda Konvolüsyon İntegrali

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Diferansiyel ve Fark Denklemleriyle Tanımlanan Sistemler
- 2. Konvolüsyona Giriş ve İmpuls Cevabı
- 3. Girişin Dikdörtgen Darbelerle Yaklaşıklanması
- 4. Birim Darbe Cevabından İmpuls Cevabına
- 5. Konvolüsyon İntegrali
- 6. Grafik Konvolüsyon Örnekleri
- 7. Konvolüsyon İntegralinin Özellikleri
- 8. Birim Üçgen Fonksiyonu
- 9. Sistem Bağlantıları ve Kararlılık
- 10. Konvolüsyon ve Evrişimli Sinir Ağları
- Örnek Sorular

## 1. Önceki Dersin Tekrarı: Diferansiyel ve Fark Denklemleriyle Tanımlanan Sistemler

Ders, önceki derste kalınan sistem özellikleri slaytının son kısmının tekrarıyla başladı. Bu derste iki tür işaret incelenir: sürekli (continuous) ve ayrık (discrete) işaretler. Sürekli işaret $x(t)$ analog işarettir, değişkeni zaman $t$'dir. Ayrık işaretin değişkeni $n$ tam sayı indisidir ($0,1,2,3,\dots$). Derste her konu önce sürekli zamanda, sonra ayrık zamanda ele alınır ve konular birbirinin üzerine kurulur.

Sistem, bir $x(t)$ girişini işleyip $y(t)$ çıkışına dönüştüren bir $T[\cdot]$ dönüşümüdür. Ayrık zamanda $x[n]$ örnekleri $y[n]$ örneklerine dönüşür.

### 1.1 Belleğe ihtiyaç duyan sistemler

Çıkış, şu anki giriş dışında geçmiş girişlere ve geçmiş çıkışlara da bağlı olabilir. Hoca ekrana şu örneği yazdı (ekrandan, 00:15:00):

$$y[n]=y[n-2]+y^2[n-1]+\frac{x[n-1]}{2}+x[n]$$

Burada şu anki çıkış $y[n]$; şu anki giriş $x[n]$, bir önceki girişin yarısı, bir önceki çıkışın karesi ve iki önceki çıkışın toplamıdır. Böyle bir sistem geçmiş örnekleri tutmak için belleğe ihtiyaç duyar.

### 1.2 Doğrusal sabit katsayılı diferansiyel denklemler

Sürekli zamanda birçok sistem doğrusal sabit katsayılı adi diferansiyel denklemle (linear constant coefficient ordinary differential equation, LCCODE) tanımlanır (ekrandan, 00:15:00):

$$a_n y^{(n)}(t)+\dots+a_1y'(t)+a_0y(t)=b_m x^{(m)}(t)+\dots+b_1x'(t)+b_0x(t)$$

Denklemin çözümü için başlangıç koşulları verilmelidir:

$$y^{(n-1)}(0),\ \dots,\ y'(0),\ y(0)$$

Bu koşullar verilen $x(t)$ için $y(t)$'yi tek olarak belirler. $n$ sistemin derecesi (order), $b_0,\dots,b_m,a_0,\dots,a_n$ sistemin katsayılarıdır. Denklem doğrusal olduğu için her terimin önünde sabit bir çarpan bulunabilir; önemli olan değişkenlerdir. Sürekli sistemlerde geçmişe ait bilgi türevlerle ifade edilir. Hoca bu kısmın ayrıntısına çok girilmeyeceğini söyledi.

Hoca iki özel durum gösterdi:

- $a_0=1$, $b_0=A$ ve diğer katsayılar sıfırsa denklem $y(t)=A\,x(t)$ olur. Sistem girişi yalnız bir genlik değeriyle çarpar.
- $a_0=0$, $a_1=1$, $b_0=1$ ise denklem $y'(t)=x(t)$ olur. $y(t)$'yi elde etmek için girişin integrali alınmalıdır; bu yüzden böyle bir sisteme integratör denir.

### 1.3 Fark denklemleri

Ayrık zamanda genel fark denklemi şu biçimdedir (ekrandan, 00:20:00):

$$a_0y[n]+a_1y[n-1]+\dots=b_0x[n]+b_1x[n-1]+\dots$$

Burada $x[n]$ giriş, $y[n]$ çıkıştır. Ayrık sistemlerde ölçekleme ve gecikme blokları yaygındır.

Hocanın örneği:

$$y[n]+3y[n-1]=2x[n]\quad\Longrightarrow\quad y[n]=2x[n]-3y[n-1]$$

Şu anki çıkışı bulmak için şu anki giriş 2 ile ölçeklenir, bellekte tutulan bir önceki çıkış 3 ile çarpılıp çıkarılır. $y[0]$'ı bulmak için $n=0$ konur ve $y[-1]$ gerekir; $y[-1]$ için de $y[-2]$ gerekir. Bu zincir bir yerde durmalıdır, bu yüzden bir başlangıç değeri verilmelidir. "Başlangıç koşulları" ile kastedilen budur.

## 2. Konvolüsyona Giriş ve İmpuls Cevabı

Bu dersin konusu konvolüsyondur. Konu yine iki başlık altında işlenecek: önce sürekli zamanda (bu ders), sonra ayrık zamanda. Hoca bu hafta için önceki slaytlardan farklı, konuyu daha iyi anlattığını düşündüğü bir slayt setine geçti (ekrandan, 00:25:00). Hoca konunun matematiksel kısmına çok derin girmeyeceğini, ama nereden geldiğinin bilinmesi için açıklayacağını söyledi.

### 2.1 İşareti impulsların toplamı olarak görmek

Sürekli bir işaret, teorik olarak sonsuz dar impulsların toplamı gibi düşünülebilir. Bu impulslar ayrık değildir, aralarında boşluk yoktur. Gerçek işaret, genliği 1 olan impulsun ölçeklenmiş (scaled) ve ötelenmiş (shifted) kopyalarının toplamıdır; örneğin $\delta(t-5)$ ya da $\delta(t-2{,}01)$ gibi (ekrandan, 00:25:00).

### 2.2 İmpuls cevabı

Sistemin birim impulsa verdiği cevap $h(t)$ ile gösterilir ve impuls cevabı (impulse response) ya da dürtü yanıtı diye adlandırılır. Hoca derste "impuls cevabı" terimini kullanacaklarını söyledi. $h(t)$ biliniyorsa sistemin nasıl karakterize olduğu da bilinir ve impulslardan oluşan herhangi bir girişin çıkışı bulunabilir.

İmpuls, $t=0$ anında bir birimlik bir atım gibi düşünülebilir. Çok dar bir aralıkta oluşur ve sistemi uyarır (excitation); bu yüzden "dürtü" diye de çevrilir. Böyle bir işaret gerçekte üretilemez, sanal bir işarettir; yalnız $t=0$ anında olup biten bir şeyi matematiksel olarak modellemek için kullanılır. İmpuls $t=0$'da uygulandığından, bundan önce sistem hiçbir çıkış vermez. Bunun nedeni sistemin nedensel olmasıdır: nedensel sistem bir uyaran olmadan çıkış üretmez.

Hoca slayttaki daha ayrıntılı matematiksel kısımları atladı ve doğrudan konvolüsyon integralinin geliştirildiği slayta geçti.

## 3. Girişin Dikdörtgen Darbelerle Yaklaşıklanması

### 3.1 Tam ve yaklaşık uyaran

Sürekli zamanlı bir LTI sisteme keyfi bir $x(t)$ girişi uygulandığında $y(t)$ aranır; sistemi $h(t)$ karakterize eder. İmpuls gerçekte oluşturulamadığı için uyaranın bir yaklaşığı kullanılır. Slayta göre girişe verilen cevap, uyaranı $T_p$ genişliğinde bitişik dikdörtgen darbelerin dizisiyle yaklaşıklayarak yaklaşık olarak bulunabilir (ekrandan, 00:30:00).

Sistemin girişine gelen gerçek işarete tam uyaran (exact excitation), dikdörtgen darbelerle kurulan basamaklı işarete yaklaşık uyaran (approximate excitation) denir. İşaret bir anda örneklenir, değeri bir sonraki ana kadar tutulur, sonra bir sonraki değer alınır ve o da tutulur. Her basamağın genişliği $T_p$'dir; $T_p$ darbe periyodu (pulse period) diye okunabilir. Sonsuz sayıda impuls yerine önce bunun daha geniş bir hali kullanılır, çünkü ileride matematiksel olarak genellenecektir.

### 3.2 Dikdörtgen fonksiyonu ile darbeler

Temel darbe, genliği 1 olan ve $-T_p/2$ ile $+T_p/2$ arasında tanımlı dikdörtgendir: $\mathrm{rect}(t/T_p)$ (ekrandan, 00:35:00). $t/T_p$ yazımı, fonksiyonun $T_p$ genişliğinde bir dikdörtgen olduğunu söyler: $t=\pm T_p/2$ konunca argüman $\pm1/2$ olur, yani birim dikdörtgenin sınırlarına denk gelir.

Hoca ekranda ortadaki darbeyi kırmızıyla, yanındakini yeşille çizdi (ekrandan, 00:40:00). Ortadaki darbenin genliği işaretin sıfırdaki değeridir:

$$x(0)\,\mathrm{rect}\left(\frac{t}{T_p}\right)$$

Sağdaki darbe $T_p$ kadar kaymıştır ve genliği $x(T_p)$'dir:

$$x(T_p)\,\mathrm{rect}\left(\frac{t-T_p}{T_p}\right)$$

Bir sonraki $2T_p$, sonraki $3T_p$ kadar kayar; sola doğru da $-T_p$, $-2T_p$ kadar kayan darbeler vardır. Hepsinin toplamı yaklaşık işareti verir (ekrandan, 00:45:00):

$$x(t)\cong\dots+x(-T_p)\,\mathrm{rect}\left(\frac{t+T_p}{T_p}\right)+x(0)\,\mathrm{rect}\left(\frac{t}{T_p}\right)+x(T_p)\,\mathrm{rect}\left(\frac{t-T_p}{T_p}\right)+\dots$$

Kapalı formda:

$$x(t)\cong\sum_{n=-\infty}^{\infty}x(nT_p)\,\mathrm{rect}\left(\frac{t-nT_p}{T_p}\right)$$

$n=0$ konunca kırmızı darbe, $n=1$ konunca yanındaki darbe elde edilir. Hoca bu genel gösterimin amacının, ileride üzerinde matematiksel işlemler yapabilmek olduğunu vurguladı. Bu yapıya darbe treni (pulse train) denir.

### 3.3 Birim alanlı darbeler

Darbeler birim alana sahip olacak hale getirilir. $T_p$ genişliğindeki bir dikdörtgenin alanının 1 olması için yüksekliği $1/T_p$ olmalıdır, çünkü yükseklik çarpı genişlik alanı verir. Bunun için ifade $T_p/T_p$ ile çarpılır; bir $T_p$ öne, $1/T_p$ darbenin yanına yazılır (ekrandan, 00:45:00):

$$x(t)\cong\sum_{n=-\infty}^{\infty}T_p\,x(nT_p)\,\underbrace{\frac{1}{T_p}\mathrm{rect}\left(\frac{t-nT_p}{T_p}\right)}_{\text{ötelenmiş birim alanlı darbe}}$$

Böylece toplamın içindeki her darbenin altındaki alan 1 olur. Birim alanlı dikdörtgen darbelere sistemin ne cevap verdiği bilinirse, sistemin bütün girişe cevabı bulunabilir.

## 4. Birim Darbe Cevabından İmpuls Cevabına

### 4.1 Birim darbe cevabı

Ötelenmemiş, birim alanlı ve $T_p$ genişliğindeki darbeye verilen cevaba birim darbe cevabı (unit pulse response) denir ve $h_p(t)$ ile gösterilir (ekrandan, 00:50:00). Hoca bunun bir ara form olduğunu söyledi. Sistem doğrusal olduğu için toplam uyarana cevap, yaklaşık olarak ötelenmiş ve ölçeklenmiş birim darbe cevaplarının toplamıdır:

$$y(t)\cong\sum_{n=-\infty}^{\infty}T_p\,x(nT_p)\,h_p(t-nT_p)$$

Burada $T_p\,x(nT_p)$ terimleri girişin farklı zamanlardaki değerlerinden gelir ve ölçek katsayısı gibi davranır. Asıl önemli olan sistemin dikdörtgen darbelere verdiği cevaptır; katsayılar bunların başına çarpan olarak gelir.

### 4.2 $T_p\to0$ limiti

$T_p$ sıfıra yaklaşırken birim darbeler birim impulslara dönüşür, birim darbe cevabı $h_p(t)$ birim impuls cevabı $h(t)$'ye dönüşür ve uyaran ile cevap kesinleşir (ekrandan, 00:50:00). Amaç, altındaki alan 1 olan ve genişliği neredeyse $\varepsilon$ olan impulsu, gerçekte üretilebilen bir kare dalgadan yola çıkarak canlandırmaktır.

### 4.3 RC devresiyle somutlaştırma

Hoca konuyu somutlaştırmak için sistemi bir RC devresi gibi düşündü. Girişe bir birim darbe uygulandığında, darbe süresince kapasitörde bir gerilim birikir. Giriş kesilince kapasitör üzerindeki gerilim yavaş yavaş azalır. Darbeye verilen cevap budur. Hoca, kitabın devre teorisine gönderme yaptığını, ama derste bununla çok ilgilenmeyeceklerini de belirtti. $T_p$ daraltıldıkça darbe cevabı birim impuls cevabını daha iyi temsil eder.

### 4.4 Slayttaki sayısal gösterim

Slaytta düzgün bir $x(t)$ dalga biçimi ve onun dikdörtgen darbelerle yaklaşığı gösterildi; işaret $-1$ ile 3 arasında, genliği $-0{,}1$ ile $0{,}2$ arasında değişir (ekrandan, 00:55:00). Sistemin her ötelenmiş darbeye ayrı cevabı vardır: sıfır genlikli darbeye sıfır cevap, ilk darbeye RC benzeri bir cevap, sonrakilere genliği düşen, ötelenen, hatta ters dönen cevaplar. Sistem toplamsal, homojen ve ötelemeyle değişmez olduğu için (LTI), bu ayrı cevapların toplamı $y(t)$'yi oluşturur.

Ardından $T_p$ küçültülerek karşılaştırma yapıldı. $T_p=0{,}1$ s iken yaklaşık çıkış gerçek çıkışa yakındır ama aralarındaki fark görülebilir (ekrandan, 01:20:00). $T_p=0{,}05$ s'ye inince birim darbe cevabı impuls cevabına daha çok yaklaşır ve yaklaşık çıkış daha pürüzsüz hale gelip kesin çıkışa yaklaşır.

Hocanın özeti şöyledir: dikdörtgen bir fonksiyon tanımlandı ve bu gerçekleştirilebilir işaret giderek daraltıldı. Sonunda impuls denen, yalnız $t=0$ anında var olan, $0^-$ ve $0^+$ anlarında olmayan, $\varepsilon$ genişliğinde ve altındaki alanı 1 olan sanal bir fonksiyona ulaşıldı.

## 5. Konvolüsyon İntegrali

### 5.1 İmpulsların integrali olarak işaret

Bir işaret impulsların toplamı olarak ifade edilebilir. Aralarında hiç mesafe olmadığı için bu toplam ayrık bir toplam (sigma) değil, zamanın çok küçük birimlerinin toplamı olan bir integraldir (ekrandan, 01:30:00 ve 01:35:00):

$$x(t)=\int_{-\infty}^{\infty}x(\tau)\,\delta(t-\tau)\,d\tau$$

Slayta göre bu ifade doğrudan impulsun örnekleme özelliğinden gelir. Her $\tau$ için $x(\tau)$ genliği, $\tau$ kadar ötelenmiş impulsla çarpılır. Hoca, slayttaki $-\infty$ ile $\infty$ sınırlarının genel olduğunu, işaret $a$ ile $b$ arasında tanımlıysa integralin de bu aralıkta değer alacağını belirtti.

### 5.2 Konvolüsyon integralinin elde edilmesi

$h(t)$ sistemin impuls cevabıysa ve sistem LTI ise, $x(\tau)\delta(t-\tau)$ girişinin cevabı $x(\tau)h(t-\tau)$ olmalıdır. Toplamsallık kullanılınca (ekrandan, 01:35:00):

$$y(t)=\int_{-\infty}^{\infty}x(\tau)\,h(t-\tau)\,d\tau$$

Bu işleme konvolüsyon integrali denir ve $y(t)=x(t)*h(t)$ diye yazılır. Hoca bunu "sözün özü" diye niteledi: bir kutuya $x(t)$ uygulanıyorsa, $x(t)$ aslında impulsların toplamıdır, sistemin bu impulslara cevabı $h(t)$'dir ve $y(t)$ bu integralle bulunur.

> **Hocanın vurgusu:** Çıkışı bulmak için girişi ve sistemin impuls cevabını bilmek yeterlidir; yapılması gereken işlem konvolüsyondur.

### 5.3 Hesabın mantığı

İntegralde ana değişken $\tau$'dur ve $t$ anındaki çıkış aranır. Birinci fonksiyon $x(\tau)$ olduğu gibi durur. İkinci fonksiyon önce ters çevrilir: $h(\tau)$'dan $h(-\tau)$ elde edilir. Değişkeni eksiyle çarpmak fonksiyonu düşey eksene göre aynalamaktır. Sonra $t$ kadar kaydırılarak $h(t-\tau)$ elde edilir. $t$ değiştikçe ters çevrilmiş fonksiyon eksen üzerinde kayar. Her konumda iki fonksiyon çarpılır ve çarpımın altındaki alan integralle bulunur. Bu alanlar $y(t)$'nin değerleridir.

Örneğin yalnız $y(5)$ istenirse $h(5-\tau)$ kullanılır:

$$y(5)=\int_{-\infty}^{\infty}x(\tau)\,h(5-\tau)\,d\tau$$

$5$, ters çevrilmiş fonksiyonun merkezinin 0'dan 5'e kaydırılması demektir. Bütün çıkışı bulmak için bu hesap her $t$ değeri için yapılır.

## 6. Grafik Konvolüsyon Örnekleri

### 6.1 Üçgen impuls cevabı ve dikdörtgen giriş

Slayttaki ilk örnekte impuls cevabı ve giriş şöyledir (ekrandan, 01:40:00):

- $h(t)$: $t=0$'da 2 değerini alıp $t=1$'de 0'a doğrusal inen üçgen. Altındaki alan $2\cdot1/2=1$.
- $x(t)$: $-1$ ile $1$ arasında genliği 2 olan dikdörtgen. Altındaki alan $2\cdot2=4$.

Önce $h(\tau)$ ters çevrilir; $h(-\tau)$, $-1$ ile 0 arasında, tepesi 0'da olan bir üçgendir. Sonra $h(t-\tau)$ olarak $t$ boyunca kaydırılır.

$t=5$ için ters çevrilmiş üçgen $4$ ile $5$ arasındadır, dikdörtgen ise $-1$ ile $1$ arasındadır. Üst üste binen bir bölge olmadığı için $y(5)=0$'dır.

$t=0$ için ters üçgen $-1$ ile 0 arasındadır ve tamamen dikdörtgenin içindedir. Çarpım fonksiyonu $\tau=0$'da $2\cdot2=4$, $\tau=-0{,}5$'te $1\cdot2=2$, $\tau=-1$'de 0 değerini alır. Çarpımın altındaki alan $y(0)=2$'dir; slayt bunu "$y(0)=2$, çarpımın altındaki alan" diye verir (ekrandan, 01:45:00).

Bir öğrenci "daha basit bir şekilde anlatabilir misiniz?" diye sorunca hoca adımları baştan tekrarladı:

- $x(\tau)$ sabit kalır.
- $h(t-\tau)$, $\tau$'ya göre çizilir; yani ters çevrilmiş üçgen oluşturulur.
- Üçgen $-\infty$'dan başlayarak sağa kaydırılır.
- İlk temas üçgenin sağ ucu dikdörtgenin sol ucuna değdiğinde, yani $t=-1$'de olur (bu anda üçgenin sol ucu $-2$'dedir). Burada alan henüz 0'dır.
- Üçgen dikdörtgenin içine girdikçe alan önce hızlı, sonra yavaş artar.
- Üçgen tamamen içerideyken ($0\le t\le1$) alan sabit kalır ve $2\cdot(2\cdot1/2)=2$ olur.
- Üçgen dikdörtgenden çıkarken alan önce hızlı, sonra yavaş azalır ve $t=2$'de sıfıra iner.

Sonuç grafiği $t=-1$'de 0'dan başlar, $t=0$'da 2'ye ulaşır, 1'e kadar 2'de kalır ve 2'de sıfır olur (ekrandan, 01:50:00). Bunun grafik anlamı şudur: ikinci fonksiyon ters döner, $t$ değerlerini kapsayacak şekilde adım adım kayar ve her adımda altta kalan alan hesaplanır.

Derste yalnız grafik ve birkaç nokta verildi. Parçalı ifade şöyledir (ara adım eklendi; python ile doğrulandı):

$$y(t)=\begin{cases}2(1-t^2), & -1\le t\le 0\\ 2, & 0\le t\le 1\\ 2(2-t)^2, & 1\le t\le 2\\ 0, & \text{diğer}\end{cases}$$

Örneğin $y(-0{,}5)=1{,}5$ ve $y(1{,}5)=0{,}5$'tir.

### 6.2 İki dikdörtgenin konvolüsyonu

İkinci örnekte $h(t)$ yerine ikinci bir fonksiyon kullanıldı ve $x_1(t)*x_2(t)$ istendi (ekrandan, 01:55:00):

- $x_1(t)$: $-0{,}5$ ile $0{,}5$ arasında genliği 3 olan dikdörtgen.
- $x_2(t)$: $0$ ile $2$ arasında genliği 2 olan dikdörtgen.

Hoca, iki fonksiyondan herhangi birinin sabit tutulup diğerinin ters çevrilebileceğini, çünkü konvolüsyonun değişme özelliği olduğunu söyledi. $x_2$ ters çevrilince $x_2(-\tau)$, $-2$ ile 0 arasında kalır. Sonra $x_2(t-\tau)$ sağa kaydırılır.

- $t=-0{,}5$'te ters dikdörtgenin sağ ucu $x_1$'in sol ucuna değer ($-0{,}5$), sol ucu $-2{,}5$'tedir. Alan 0'dır.
- $t=0$'da ters dikdörtgen $-2$ ile 0 arasındadır; $x_1$ ile çakışma $-0{,}5$ ile 0 arasıdır. Çakışan bölgede çarpımın yüksekliği $3\cdot2=6$, genişliği $0{,}5$'tir; alan 3'tür (ekrandan, 02:00:00).
- $t=0{,}5$'te $x_1$ tamamen ters dikdörtgenin içine girer. Alan $6\cdot1=6$ olur.
- $0{,}5\le t\le1{,}5$ boyunca $x_1$ içeride kalır, kesişim alanı değişmez ve sonuç 6'da sabit kalır.
- $t=1{,}5$'ten sonra $x_1$ dışarı çıkmaya başlar; alan doğrusal azalır ve $t=2{,}5$'te sıfıra iner.

Sonuç bir yamuktur (ekrandan, 02:00:00):

$$x_1(t)*x_2(t)=\begin{cases}6(t+0{,}5), & -0{,}5\le t\le 0{,}5\\ 6, & 0{,}5\le t\le 1{,}5\\ 6(2{,}5-t), & 1{,}5\le t\le 2{,}5\\ 0, & \text{diğer}\end{cases}$$

Hoca bunu "çarp-topla" diye özetledi: her kaydırmada iki fonksiyonun değerleri çarpılır ve çarpımın altındaki alan toplanır. Yalnız uç geçiş noktaları bulunsa bile sonucun biçimi çizilebilir. $x_2$ bir sistemin impuls cevabı olsaydı sonuç $y(t)$ diye adlandırılırdı.

> **Ders sonrası not:** Hoca anlatım sırasında 6 değerinin "0 ile $-0{,}5$ arasında" alındığını söyledi. Ekrandaki sonuç grafiğine ve hesaba göre $t=0$'da değer 3'tür; 6 değeri $0{,}5\le t\le1{,}5$ aralığında alınır (python ile doğrulandı). Hoca $t=0$ için ekrana 3'ü de işaretledi.

### 6.3 İki üçgenin konvolüsyonu

Üçüncü örnekte iki üçgen tanımlandı (ekrandan, 02:05:00):

- $x_1(t)$: $-3$ ile $1$ arasında, tepesi $t=-1$'de 3 olan üçgen.
- $x_2(t)$: $-1$ ile $1$ arasında, tepesi $t=0$'da 1,5 olan üçgen.

<!-- BELİRSİZ: Hoca altyazıda x_1'in "-1 ile -3 arasında" tanımlı olduğunu söylüyor ve ekranda -3 ile -1'i işaretliyor; ekrandaki eksen ölçeğine göre üçgenin tabanı -3 ile 1, tepesi -1'dedir. Not ekran grafiğine göre yazıldı. -->

Önce ikinci fonksiyon ters çevrilir. $x_2$ simetrik olduğu için tersi de aynıdır. Sonra $x_2(t-\tau)$, $x_1(\tau)$'nun üzerinden adım adım geçirilir. Slaytta $t=-3,-2,-1,0,1$ için iki fonksiyon ve çarpımları gösterilir (ekrandan, 02:15:00). Küçük üçgen önce büyük üçgenin sol kenarına girer ve çarpımın alanı yavaşça artar. $t=-1$'de iki tepe üst üste gelir; çarpım fonksiyonunun tepesi $3\cdot1{,}5=4{,}5$ olur. Sonra küçük üçgen sağa doğru çıkar ve alan azalır.

Hoca, sonucun önce artan, sonra azalan bir biçimde olduğunu ve iki fonksiyon birbirinin üzerinden geçerken altta kalan alanın değişiminin sistem çıktısını verdiğini söyledi. Ayrıca burada $t$'nin yalnız birkaç örneği ($-3,-2,-1,0,1$) alındığını, gerçekte $t$'nin bütün değerleri için hesap yapılması gerektiğini vurguladı.

Python ile hesaplanan konvolüsyon değerleri şunlardır: $y(-4)=0$, $y(-3)=0{,}375$, $y(-2)=2{,}25$, $y(-1)=3{,}75$ (en büyük değer), $y(0)=2{,}25$, $y(1)=0{,}375$, $y(2)=0$. Sonuç $t=-1$'e göre simetriktir ve $[-4,2]$ aralığında sıfırdan farklıdır.

> **Ders sonrası not:** Hoca bu örnekte 4,5 ve 2,25 değerlerini söyledi ve "maksimumuna 6'da ulaştı" dedi. 4,5 ($3\cdot1{,}5$) ve 2,25 ($1{,}5\cdot1{,}5$) belirli kaydırmalarda çarpım fonksiyonunun tepe değerleridir; konvolüsyonun değeri çarpımın altındaki alandır. Konvolüsyonun en büyük değeri $t=-1$'de 3,75'tir (python ile hesaplandı). 6, ikinci örneğin en büyük değeridir.

> **Ek bilgi (derste anlatılmadı):** Sonlu süreli iki fonksiyonun konvolüsyonu, başlangıçları toplamında başlar ve bitişleri toplamında biter. Bu örnekte $-3+(-1)=-4$ ve $1+1=2$ olur. İkinci örnekte de $-0{,}5+0=-0{,}5$ ve $0{,}5+2=2{,}5$ bulunur.

### 6.4 Konvolüsyon ve sistem çıkışı

Bir öğrenci, $h(t)$ yerine $x_2(t)$ yazılınca işlemin değişip değişmediğini sordu.

**Soru:** Örnekte $h$ yerine $x_2$ dedik; işlem aynı mı, yoksa farklı bir şey mi oldu?

**Cevap:** İşlem aynıdır. $x(t)$ ile $h(t)$ yerine iki farklı fonksiyon konduğunda da konvolüsyon alınmış olur. İkinci fonksiyon sistemin impuls cevabıysa sonuç sistemin çıkışıdır; değilse yalnız iki fonksiyonun konvolüsyonudur.

Hoca bunu daha sonra tekrar vurguladı: herhangi iki fonksiyonun konvolüsyonu alınabilir, ama sonuç ancak ikinci fonksiyon kutunun impuls cevabıysa sistem çıkışı $y(t)$ olur.

## 7. Konvolüsyon İntegralinin Özellikleri

Slayttaki özellikler şunlardır (ekrandan, 02:20:00). Buradaki $y(t)$ çıkış fonksiyonu değil, herhangi bir fonksiyondur.

- Değişme (commutativity): $x(t)*y(t)=y(t)*x(t)$. İki fonksiyondan hangisinin sabit tutulup hangisinin kaydırıldığı sonucu değiştirmez.
- Birleşme (associativity): $[x(t)*y(t)]*z(t)=x(t)*[y(t)*z(t)]$. Üç fonksiyonun konvolüsyonunda ikisi önce alınıp sonra üçüncüyle konvolüsyona sokulabilir.
- Dağılma (distributivity): $[x(t)+y(t)]*z(t)=x(t)*z(t)+y(t)*z(t)$. Toplanan iki fonksiyonun $z(t)$ ile konvolüsyonu, ayrı ayrı konvolüsyonların toplamıdır.

Slayttaki diğer özellikler:

$$x(t)*A\delta(t-t_0)=A\,x(t-t_0)$$

Hoca bunu şöyle açıkladı: ikinci fonksiyon $t_0$ kadar kaydırılmış, genliği $A$ olan tek bir impulsa eşitse, konvolüsyon yalnız o noktadan katkı alır ve sonuç $A\,x(t-t_0)$ olur.

$$g(t)=g_0(t)*\delta(t)\ \Rightarrow\ g(t-t_0)=g_0(t-t_0)*\delta(t)=g_0(t)*\delta(t-t_0)$$

$$y(t)=x(t)*h(t)\ \Rightarrow\ y'(t)=x'(t)*h(t)=x(t)*h'(t),\qquad y(at)=|a|\,x(at)*h(at)$$

Hoca son iki özelliğin çok önemli olmadığını, değişme, birleşme ve dağılma özelliklerinin önemli olduğunu söyledi.

## 8. Birim Üçgen Fonksiyonu

Birim üçgen fonksiyonu şöyle tanımlanır (ekrandan, 02:25:00):

$$\mathrm{tri}(t)=\begin{cases}1-|t|, & |t|<1\\ 0, & |t|\ge1\end{cases}$$

$-1$ ile 1 arasında tanımlıdır, tepesi $t=0$'da 1'dir ve altındaki alan 1'dir. Slayta göre birim üçgen, birim dikdörtgenin kendisiyle konvolüsyonudur:

$$\mathrm{tri}(t)=\mathrm{rect}(t)*\mathrm{rect}(t)$$

Birim dikdörtgen $-0{,}5$ ile $0{,}5$ arasında 1 değerini alır ve altındaki alan 1'dir. Hoca konvolüsyonu grafikle gösterdi: iki dikdörtgen $t=-1$'de karşılaşır, ikincisi birincinin içine girdikçe alan doğrusal artar, tam örtüştüklerinde $1\cdot1=1$ ile en büyük değere ulaşır, sonra çıkmaya başlar ve alan azalır. Sonuç üçgendir.

**Soru:** Burada dikdörtgenlerden biri $x(t)$, diğeri $h(t)$ olarak mı alınıyor?

**Cevap:** Evet. Ama hoca şuna dikkat çekti: konvolüsyon için ikinci fonksiyonun mutlaka impuls cevabı olması gerekmez; ilgisiz iki fonksiyonun da konvolüsyonu alınabilir. İkinci fonksiyon kutunun impuls cevabıysa sonuç sistem çıkışı olur.

## 9. Sistem Bağlantıları ve Kararlılık

### 9.1 Seri ve paralel bağlantı

Bir giriş arka arkaya iki kutudan geçiyorsa (biri $h_1(t)$, diğeri $h_2(t)$), sistemi tek kutu gibi düşünmek için iki impuls cevabı konvolüsyona sokulur:

$$h_3(t)=h_1(t)*h_2(t)$$

Sistemler paralel bağlıysa ve çıkışları toplanıyorsa eşdeğer impuls cevabı toplamdır:

$$h_3(t)=h_1(t)+h_2(t)$$

> **Hocanın vurgusu:** Seri bağlı sistemlerde impuls cevapları konvolüsyona sokulur, paralel bağlı sistemlerde toplanır.

### 9.2 Kararlılık şartı

Sistemin kararlı (stabil) olması için impuls cevabının mutlak değerinin $-\infty$'dan $\infty$'a integrali sonlu olmalıdır:

$$\int_{-\infty}^{\infty}|h(t)|\,dt<\infty$$

Bu, $h(t)$'nin altındaki alanın, negatif kısımlar da pozitife çevrilerek, sonlu bir değere varması demektir. Hoca iki örnek verdi. Sonsuza kadar süren ve sönmeyen bir fonksiyonun her noktasındaki değerler toplandığında sonucun sonlu olacağının garantisi yoktur; böyle sistemler kararlı değildir. Buna karşılık $e^{-t}u(t)$, sıfırdan başlar ve sonsuzda sıfıra gider; altındaki alan sonlu bir sayıya yakınsar.

Hoca slaytların bundan sonraki kısımlarının daha çok sayısal işaret işlemenin (DSP) konusu olduğunu söyleyip onları anlatmadı. Ayrık zamanda konvolüsyonun bir sonraki konu olduğunu belirtti.

## 10. Konvolüsyon ve Evrişimli Sinir Ağları

Ders sonunda bir öğrenci, konvolüsyon operatörünün evrişimli sinir ağı (CNN) mimarisindeki kullanımıyla bir ilişkisi olup olmadığını sordu.

**Soru:** Konvolüsyon operatörünün CNN mimarisinde kullanılmasıyla bir ilişkisi var mı, yoksa yalnız isim benzerliği mi?

**Cevap:** Altyapısı budur. Ayrık zamanda $x[n]$ girip $y[n]$ çıkan bir sistemde $h[n]$ bir filtre görevi görüyorsa, bu filtrenin katsayılarıyla yapılan işlem CNN'deki filtrelere karşılık gelir. Bu filtrelerle giriş işareti ya da görüntünün farklı parçaları (patch) konvolüsyona sokulur ve öznitelikler çıkarılır. Filtrelerin bazıları kenar çıkarır, bazıları geçiş noktalarını ya da gradyanları bulur. Yani derste CNN mimarisinin temeli anlatılmaktadır.

Öğrencinin "bu daha çok ayrık olarak incelediğimiz kısma denk gelecek galiba" yorumuna hoca, analog halin anlaşılmasının biraz daha zor olduğunu, bilgisayar mühendisleri için ayrık hali anlamanın çok daha net olacağını söyleyerek katıldı.

> **Ek bilgi (derste anlatılmadı):** CNN kütüphanelerindeki "konvolüsyon" katmanları çoğunlukla filtreyi ters çevirmeden kayan çarpım-toplam yapar; matematikte buna çapraz korelasyon denir. Filtre katsayıları eğitimle öğrenildiği için ters çevirmenin yapılıp yapılmaması pratikte sonucu değiştirmez.

## Örnek Sorular

### Soru 1 (ekrandan, 01:40:00)

İmpuls cevabı $h(t)$, $t=0$'da 2 değerinden $t=1$'de 0'a doğrusal inen üçgen; giriş $x(t)$, $-1\le t\le1$ aralığında genliği 2 olan dikdörtgendir. $y(t)=x(t)*h(t)$'yi bulun.

> **Çözüm:** Derste grafikle çözüldü (ekrandan, 01:45:00 ve 01:50:00). $h$ ters çevrilip kaydırılır. $t<-1$ ve $t>2$ için çakışma yoktur, $y=0$. $t=0$'da ters üçgen tamamen dikdörtgenin içindedir ve $y(0)=2\cdot1=2$ olur. $0\le t\le1$ boyunca değer 2'de sabittir. Parçalı ifade (ara adım eklendi, python ile doğrulandı): $-1\le t\le0$ için $y=2(1-t^2)$; $0\le t\le1$ için $y=2$; $1\le t\le2$ için $y=2(2-t)^2$. Ayrıca $y(5)=0$'dır.

### Soru 2 (ekrandan, 01:55:00)

$x_1(t)$, $-0{,}5\le t\le0{,}5$ aralığında genliği 3 olan dikdörtgen; $x_2(t)$, $0\le t\le2$ aralığında genliği 2 olan dikdörtgendir. $x_1(t)*x_2(t)$'yi bulun.

> **Çözüm:** Derste grafikle çözüldü (ekrandan, 02:00:00). $x_2$ ters çevrilip kaydırılır. Sonuç bir yamuktur: $-0{,}5\le t\le0{,}5$ için $6(t+0{,}5)$, $0{,}5\le t\le1{,}5$ için 6, $1{,}5\le t\le2{,}5$ için $6(2{,}5-t)$, diğer yerlerde 0. $t=0$'da değer 3'tür (python ile doğrulandı).

### Soru 3 (ekrandan, 02:05:00)

$x_1(t)$, $-3\le t\le1$ aralığında tepesi $t=-1$'de 3 olan üçgen; $x_2(t)$, $-1\le t\le1$ aralığında tepesi $t=0$'da 1,5 olan üçgendir. $x_1(t)*x_2(t)$'yi bulun.

> **Çözüm:** Derste $t=-3,-2,-1,0,1$ kaydırmaları için grafikle gösterildi (ekrandan, 02:15:00), sayısal değerler tam verilmedi. Python ile hesaplanan değerler: $y(-3)=0{,}375$, $y(-2)=2{,}25$, $y(-1)=3{,}75$, $y(0)=2{,}25$, $y(1)=0{,}375$; sonuç $[-4,2]$ aralığında, $t=-1$'e göre simetrik ve en büyük değeri 3,75'tir.

### Soru 4 (ekrandan, 02:25:00)

Birim üçgen fonksiyonunun birim dikdörtgenin kendisiyle konvolüsyonu olduğunu gösterin: $\mathrm{tri}(t)=\mathrm{rect}(t)*\mathrm{rect}(t)$.

> **Çözüm:** Derste grafikle gösterildi. Dikdörtgenler $t=-1$'de karşılaşır. $-1\le t\le0$ için çakışma genişliği $t+1$ olduğundan sonuç $1+t$'dir. $t=0$'da tam örtüşürler ve değer $1\cdot1=1$ olur. $0\le t\le1$ için çakışma genişliği $1-t$'dir. Sonuç $1-|t|$ ($|t|<1$), yani $\mathrm{tri}(t)$'dir (python ile doğrulandı).

### Soru 5 (derste sözlü, 02:28:05)

İmpuls cevabı $h(t)=e^{-t}u(t)$ olan sistem kararlı mıdır?

> **Çözüm:** Hoca bu fonksiyonun sıfırdan başladığını ve sonsuzda sıfıra gittiğini, altındaki alanın sonlu bir sayıya yakınsadığını söyledi; sistem kararlıdır. Hesap (derste verilmedi): $\int_{0}^{\infty}e^{-t}\,dt=1<\infty$.

## Dersin Toparlaması

Bu derste önce diferansiyel ve fark denklemleriyle tanımlanan sistemler hatırlatıldı, ardından sürekli zamanlı LTI sistemlerin temel aracı olan konvolüsyon integrali adım adım kuruldu. Giriş işareti önce $T_p$ genişliğinde birim alanlı dikdörtgen darbelerle yaklaşıklandı. Sistem doğrusal ve zamanla değişmez olduğu için çıkış, ötelenmiş ve ölçeklenmiş birim darbe cevaplarının toplamı olarak yazıldı. $T_p\to0$ limitinde darbe cevabı impuls cevabına, toplam da $y(t)=\int x(\tau)h(t-\tau)d\tau$ integraline dönüştü. Hesap yolu olarak "ters çevir, kaydır, çarp, alanı bul" adımları üç grafik örnekle uygulandı. Ardından değişme, birleşme ve dağılma özellikleri, impulsla konvolüsyon, birim üçgenin iki birim dikdörtgenin konvolüsyonu olması, seri ve paralel bağlantı kuralları ve $\int|h(t)|dt<\infty$ kararlılık şartı verildi.

Hoca bir sonraki derste aynı konunun ayrık zamandaki karşılığını, yani ayrık konvolüsyonu bol örnekle işleyeceğini söyledi. Ayrık halde bütün değerler tek tek hesaplandığı için konunun daha kolay anlaşılacağını ve CNN'deki filtrelerin temelinin de bu olduğunu belirtti. Kaynak olarak bu dersin slaytlarının alındığı M. J. Roberts'ın "Signals and Systems" kitabını (Türkçe çevirisi de var) öncelikli olarak önerdi; Schaum serisinin "Signals and Systems" kitabını <!-- BELİRSİZ: altyazıda "Xiaomi serisi", yazar "Huey Kusu" geçiyor; büyük olasılıkla Schaum serisi, H. P. Hsu --> ve daha çok ayrık zamana odaklanan "DSP First" kitabını da andı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
