# Ders 9 Genişletilmiş Notu: Fourier Dönüşümü Çiftleri ve Özellikleri, Diferansiyel Denklem Çözümü ve Modülasyon

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Neden Fourier Dönüşümü: Diferansiyel Denklemlere Dönüş
- 2. Temel Fourier Dönüşüm Çiftleri
- 3. Özelliklere İlk Bakış
- 4. Diferansiyel Denklemin Fourier Dönüşümüyle Çözümü
- 5. Periyodik İşaretin Fourier Dönüşümü
- 6. Özellikler: Slaytlar Üzerinden Daha Ayrıntılı
- 7. Uygulama: Sesin Modüle Edilip Taşınması
- 8. Fourier Dönüşümünde Neler Hayati?
- 9. Fourier Dönüşümü Her Zaman Var Mı?
- 10. Ayrık Konvolüsyonda Sıfır Noktası İçin Kısa Yol

## 1. Neden Fourier Dönüşümü: Diferansiyel Denklemlere Dönüş

Hoca derse, birkaç ders önce konuşulan diferansiyel denklemleri hatırlatarak başladı. Sistemleri genellikle diferansiyel denklemlerle ifade ediyoruz: Bir sistemin davranışını göstermek için $y$'nin ikinci türevi, artı iki kere $y$'nin türevi gibi ifadeler yazıyorduk. Bu derste Fourier dönüşümünü, işte bu denklemleri daha kolay çözmek için kullanacağız.

### 1.1 Bir İşaretin Dönüşümü: $Y(\omega)$

Hoca konuya bir soruyla girdi.

**Soru:** Elimizde $y(t)$ diye bir işaret var. Buna Fourier dönüşümü uygularsak ne elde ederiz?

**Cevap:** $Y(\omega)$ elde ederiz. Yani $t$'ye bağlı herhangi bir işaret, $\omega$'ya bağlı bir ifadeye dönüşür. Elimizde $x(t)$ olsa, dönüşümü de $X(\omega)$ olur.

Fourier dönüşümünün integrali şudur:

$$X(\omega) = \int_{-\infty}^{\infty} x(t)\, e^{-j\omega t}\, dt$$

Kaynaklarda $X(f)$ yazımını da görebilirsiniz. Hiçbir şey fark etmez: $\omega = 2\pi f$ olduğunu biliyoruz. Bunu integralde yerine yazarsak sonuç $X(f)$ veya $X(\omega)$ şeklinde yazılabilir, ikisi de aynı kapıya çıkar.

### 1.2 Türevin Dönüşümü ve Uzun Yol

Hoca ikinci soruyu türevli işaret için sordu.

**Soru:** Elimizde $y'(t)$ var. Fourier dönüşümünü alırsak ne elde ederiz?

**Cevap:** $y(t)$'nin türevi de sonuçta bir işarettir. O hâlde o işaretin Fourier dönüşümü de vardır. Hoca bunu "$Y$ türev $\omega$" diye adlandırdı.

> **Ders sonrası not:** Hocanın burada söylediği "$Y'(\omega)$", $y'(t)$ işaretinin dönüşümü anlamındadır, $Y(\omega)$'nın $\omega$'ya göre türevi anlamında değildir. Bu ikisi farklı şeylerdir: $y'(t) \leftrightarrow j\omega\,Y(\omega)$ iken $\omega$'ya göre türev $t\,y(t)$ işaretiyle ilişkilidir (Bölüm 3.3).

Bir sonraki adımda hoca, bu dönüşümün algoritmik olarak nasıl bulunabileceğini sordu.

**Soru:** $X(\omega)$ elimizde var, türev işaretinin dönüşümü aranıyor. Algoritmik olarak ne yaparız?

**Cevap:** Ters dönüşüm yapıp türev alır, sonra tekrar dönüşüm yaparız.

Hoca cevabı adımlarıyla doğruladı:

- Ters dönüşümle $X(\omega)$'dan $x(t)$ elde edilir.
- $x(t)$'nin türevi alınır.
- Türevin Fourier dönüşümü alınır.

Bu yol mümkündür, ama uzundur. Fourier dönüşümünün özelliklerine geldiğimizde bu uzun yola gerek kalmayacak.

### 1.3 Dönüşümlerle Çözüm Fikri

Bu sayede diferansiyel denklemleri dönüşümler yoluyla çözmek çok daha kolay hâle gelir. Hoca bir karşılaştırma yaptı: Bir matematik bölümünün diferansiyel denklemler dersine veya bir diferansiyel denklem kitabına bakarsanız pek çok çeşit görürsünüz. Bizim özellikle elektronik ve bilgisayar sistemlerinde kullandığımız diferansiyel denklem türleri ise dönüşümler yoluyla çözülebilir. Dönüşümleri yaptıktan sonra işlem toplama, çıkarma, çarpma ve bölmeyle tamamlanır, başka bir şey yoktur.

Buradan şu sonuç çıkar: Fourier dönüşüm tablosu elimizdeyse, birçok şeyi integral hesaplamaya gerek kalmadan buluruz.

## 2. Temel Fourier Dönüşüm Çiftleri

Hoca tablodaki temel işaretlerden bazılarını, frekans düzleminde çizerek tekrar gösterdi. Bir işaretin Fourier dönüşümü karşılığına **Fourier dönüşüm çifti** deniyor. Tablodaki bir çift, ters dönüşümde de kullanılır: Elimizde bir taraf varsa diğer tarafı buluruz.

### 2.1 Birim Dürtü: $\delta(t) \leftrightarrow 1$

Dönüşümün integrali yazılır:

$$\int_{-\infty}^{\infty} \delta(t)\, e^{-j\omega t}\, dt$$

Sayı doğrusunda $-\infty$'dan itibaren gelirken $t = 0$ dışındaki bütün noktalarda çarpan sıfırdır, dolayısıyla integralin içi hep sıfır olur. Yalnızca $t$ sıfıra ulaştığında katkı gelir, sonrasında yine hep sıfırdır. Bu yüzden integrali çözmeye gerek yoktur: $e^{-j\omega t}$'nin $t = 0$'daki değerine bakmak yeterlidir.

$$\int_{-\infty}^{\infty} \delta(t)\, e^{-j\omega t}\, dt = e^{-j\omega \cdot 0} = e^{0} = 1$$

> **Ders sonrası not:** Hoca sonucu önce "$e^{-j\omega}$" diye yazdı, hemen ardından "$t = 0$ olunca doğrudan $e^0 = 1$" diye düzeltti. Doğrusu $1$'dir. Dar bir Gauss darbesiyle yaklaşık alınarak Python ile doğrulandı.

Hoca bu işareti iki eksende gösterdi. Zaman düzleminde işaret, $t = 0$'daki tek bir dürtüdür. Frekans düzleminde ise $-\infty$'dan $+\infty$'a kadar uzanan sabit bir spektrum bulunur. İşaretin fazı da yoktur: Frekans-faz analizi yapsaydık boş bir grafik, yani sıfır görürdük.

### 2.2 Üstel ve Birim Basamak

Hoca $e^{-at}u(t)$ işaretinin daha önce örnek olarak çözüldüğünü söyleyip tekrar etmedi. Bu çift, Bölüm 4 ve 9'da yeniden kullanılacak:

$$e^{-at}u(t) \leftrightarrow \frac{1}{a + j\omega}, \quad a > 0$$

### 2.3 Kosinüs ve Sinüs

Hoca kosinüs ve sinüsü çizmeden önce, hangi düzlemde olursak olalım dürtünün mantığının aynı olduğunu hatırlattı: Bir $\lambda$ değişkeni için $\delta(\lambda)$, $\lambda = 0$'da bir dürtüdür, başka her yerde sıfırdır.

<!-- BELİRSİZ: Altyazıda "L domaini" ve "Drak L" geçiyor. Bu, büyük olasılıkla slayttaki λ değişkenidir. -->

> **Ders sonrası not:** Hoca $\delta(\lambda)$ için "$\lambda$ sıfırken birdir" dedi. Sürekli zamanda $\delta$'nın tepe değeri $1$ değildir. Dürtünün **alanı** $1$'dir ve eleme yaparken integralin sonucu, çarpılan fonksiyonun o noktadaki değeri olur. Alanı $1$ olan Gauss darbesi daraldıkça tepesi büyür: Standart sapma $0{,}05$'te tepe yaklaşık $7{,}98$, $0{,}01$'de yaklaşık $39{,}9$'dur, alan ise $1$ kalır (Python ile doğrulandı).

Kosinüsün dönüşümü, $\omega$ ekseninde $-\omega_0$ ve $+\omega_0$ noktalarında iki dürtüdür:

$$\cos\omega_0 t \leftrightarrow \pi\left[\delta(\omega + \omega_0) + \delta(\omega - \omega_0)\right]$$

Hoca bunu, $\omega$'nın $\omega_0$ kadar öne alınması ve $\omega_0$ kadar geciktirilmesi olarak okudu. İki dürtünün de ağırlığı $\pi$'dir, yani grafikte $\pi$ yüksekliğinde bir tepe görürüz.

> **Ders sonrası not:** Hoca "tepe değeri $\omega_0$'ın değerine bağlıdır, $2\omega_0$ olsaydı $2\pi$ olurdu" dedi. Doğrusu, dürtü ağırlığı $\omega_0$'a bağlı değildir, her $\omega_0$ için $\pi$'dir. $2\pi$, frekansın değil **genliğin** iki katı olduğu $2\cos\omega_0 t$ işaretinde çıkar. Pencerelenmiş dönüşümün dürtü civarındaki integraliyle $\omega_0 = 1, 2, 5$ için ağırlık $\pi$, $2\cos 2t$ için $2\pi$ olarak hesaplandı (Python ile doğrulandı).

Sinüs için de $\pm\omega_0$'da iki dürtü vardır, fakat ağırlıklar saf sanaldır. Negatif frekanstaki dürtünün ağırlığı $+j\pi$'dir, pozitif frekanstaki ise aşağı doğru $-j\pi$'dir:

$$\sin\omega_0 t \leftrightarrow j\pi\left[\delta(\omega + \omega_0) - \delta(\omega - \omega_0)\right]$$

Bu ağırlıklar da Python ile doğrulandı.

### 2.4 Karmaşık Üstel: $e^{j\omega_0 t}$

Bu işareti çizmeye kalkarsak yalnız $\omega = \omega_0$ noktasında $2\pi$'lik bir tepe görürüz:

$$e^{j\omega_0 t} \leftrightarrow 2\pi\,\delta(\omega - \omega_0)$$

Hoca tablolar konusunda şunu söyledi: Bu tablolardaki çiftleri ezberlemek zorunda değilsiniz. Örneğin $\cos 5\pi t$'nin dönüşümünü uzun uzun integralle hesaplamanız ayrıca istenirse o zaman integrali yaparsınız. Ama genel olarak bu çiftler bilinir ve kullanılır.

### 2.5 Ötelenmiş Dürtü: $\delta(t - c)$

Hoca bunu önemli bir özelliğin habercisi olarak gösterdi ve integralden çıkardı: Dürtü $c$ kadar ötelendiğinde sonuç artık $1$ değil, $e^{-j\omega c}$ olur.

$$\int_{-\infty}^{\infty} \delta(t - c)\, e^{-j\omega t}\, dt$$

Bu integrali çözmeden önce hoca bir soru sordu.

**Soru:** Burada neden $\omega$ yerine sayısal bir değer yazmıyoruz, doğrudan değişken olarak bırakıyoruz? Fourier serilerinde öyle bir şey yapıyorduk. Fourier dönüşümü periyodik işaretlere mi, periyodik olmayanlara mı uygulanıyordu?

**Cevap:** Periyodik olmayan işaretlere. Periyodik bir işarette belli bir periyot (hocanın örneğiyle $3$, $5$, $7$ gibi) elimizdedir ve frekansı oradan çıkarırız. Periyodik olmayan bir işarette ise her tür frekans olabilir. Bu yüzden $\omega$ belli bir değer değil, değişkendir. Bu integral dönüşümünün gayesi de zaten $t$'yi alıp $\omega$'ya dönüştürmektir.

İntegrali çözelim. $-\infty$'dan gelirken bütün noktalarda sıfır gelir, yalnız $t = c$ noktasında katkı oluşur:

$$\int_{-\infty}^{\infty} \delta(t - c)\, e^{-j\omega t}\, dt = e^{-j\omega t}\Big|_{t = c} = e^{-j\omega c}$$

Hoca sonucun bir $\omega$ fonksiyonu olduğunu vurguladı: $\omega$'nın değerine bir şey yapmıyoruz, $c$ sabittir ve $e^{-j\omega c}$, $\omega$'ya göre değişir. $\omega = 0$'da $e^0 = 1$'den başlar.

> **Ders sonrası not:** Hoca önce "$c$ noktasında tek bir pik" dedi, sonra bu sonucu "azalıp giden bir frekans spektrumu" gibi çizdi. İkisi de doğru değildir. $\lvert e^{-j\omega c}\rvert = 1$'dir, yani genlik spektrumu her frekansta sabit $1$'dir. Değişen şey fazdır: Faz $-\omega c$ biçiminde doğrusal değişir. $c = 1{,}5$ için Python ile doğrulandı.

### 2.6 Faz Ötelemeli Kosinüs ve Sinüs

Kosinüse $\theta$ kadar faz ötelemesi yaparsak ekstra bir işlem gerekmez. $\cos\omega_0 t$'nin dönüşümünü biliyorsak, dürtüleri yalnızca $e^{\pm j\theta}$ ile çarparız, bir tarafta eksi, bir tarafta artı:

$$\cos(\omega_0 t + \theta) \leftrightarrow \pi\left[e^{-j\theta}\delta(\omega + \omega_0) + e^{j\theta}\delta(\omega - \omega_0)\right]$$

Hoca sinüs için de aynı durumun geçerli olduğunu söyledi.

> **Ders sonrası not:** Hoca sinüs için "iki tarafta da eksi olacak şekilde bir çarpma" dedi. Doğrusu, faz çarpanları kosinüstekiyle aynıdır, eksi işareti dürtü ağırlıklarından gelir: $\sin(\omega_0 t + \theta) \leftrightarrow j\pi\left[e^{-j\theta}\delta(\omega + \omega_0) - e^{j\theta}\delta(\omega - \omega_0)\right]$. Her iki çift de $\omega_0 = 2$, $\theta = 0{,}7$ için Python ile doğrulandı.

<!-- BELİRSİZ: Tablonun sinüs satırının tam yazımı altyazıda okunmuyor. Hocanın "iki tarafta da eksi" sözü slayttaki başka bir gösterime dayanıyor olabilir. -->

Hoca tablodaki "pt" diye andığı satırın çok önemli olmadığını söyleyip geçti.

<!-- BELİRSİZ: "pt" satırı altyazıda açıklanmıyor. Bu, büyük olasılıkla dikdörtgen darbe çiftidir. -->

## 3. Özelliklere İlk Bakış

Hoca tablonun özellikler kısmını önce hızlıca dolaştı. Slaytlarla daha ayrıntılı geçiş Bölüm 6'dadır.

### 3.1 Doğrusallık

İki parçalı bir fonksiyonumuz varsa, örneğin $3x(t) + 5x^2(t)$, doğrusallık özelliğinden dolayı parçaların Fourier dönüşümlerini ayrı ayrı alıp hesaplayabiliriz.

<!-- BELİRSİZ: Altyazıda "3 XT artı 5 X kare" geçiyor. Slayttaki ifade x_2 gibi ikinci bir işaret de olabilir. -->

### 3.2 Zamanda Öteleme ve Ölçekleme

> **Hocanın vurgusu:** Zamanda öteleme "çok çok önemli" bir özelliktir.

Herhangi bir $x(t)$ fonksiyonumuz var. Bu, tablodakilerden biri olabilir, kendi yazdığımız başka bir fonksiyon da olabilir. $x(t)$'yi zaman düzleminde $c$ birim ötelediğimizde oluşan yeni işaretin dönüşümünü sıfırdan hesaplamamıza gerek yoktur. $X(\omega)$'yı $e^{-j\omega c}$ ile çarpmak yeter:

$$x(t - c) \leftrightarrow e^{-j\omega c} X(\omega)$$

Ölçeklemede de benzer bir kısa yol vardır. $a$ sıfırdan farklı olmak üzere, bulduğumuz dönüşümü $1/\lvert a\rvert$ ile çarparız ve bütün $\omega$'ları $\omega/a$ ile değiştiririz:

$$x(at) \leftrightarrow \frac{1}{\lvert a\rvert} X\!\left(\frac{\omega}{a}\right), \quad a \neq 0$$

> **Ders sonrası not:** Hoca burada önce "$1/a$" dedi, ikinci geçişte mutlak değerli hâlini söyledi. Doğrusu $1/\lvert a\rvert$'dır. $a = -2$ için Python ile doğrulandı.

Zamanda ters çevirmede $x(-t) \leftrightarrow X(-\omega)$ olur. Hoca, bunun eşlenikle ilgili bir biçiminin de slaytta bulunduğunu söyledi.

<!-- BELİRSİZ: Slayttaki eşlenik ifadesi altyazıda net okunmuyor. Bu, büyük olasılıkla x(t) gerçelken geçerli olan X(-ω) = X*(ω) eşitliğidir. -->

> **Ders sonrası not:** $x(t)$ gerçel bir işaretse $X(-\omega)$, $X(\omega)$'nın karmaşık eşleniğine eşittir. Simetrik olmayan gerçel bir işaret üzerinde Python ile doğrulandı.

### 3.3 $t^n$ ile Çarpma

Hoca bu özelliğin değerini bir örnekle anlattı. Elimizde $x(t) = \sin t$ olsun. Dönüşümde $\sin t$ ile $e^{-j\omega t}$'nin çarpımının integralini alırız. Bir de bunu $t^n$ ile çarparsak integral çok daha zorlaşır: Bir tarafta değişken dönüşümü, bir tarafta kısmi integrasyon gerekir. $\sin t$'yi üstellerle yazmak biraz kolaylaştırır, ama $t$ çarpanı kaldığı için yine zor bir integralle karşılaşırız.

Özellik bizi bundan kurtarır: İşaretin dönüşümünün $\omega$'ya göre $n$. dereceden türevini alıp $j^n$ ile çarparız.

$$t^n x(t) \leftrightarrow j^n \frac{d^n X(\omega)}{d\omega^n}$$

Hocanın örneği $t^4$ idi: $j^4 = 1$ olduğu için önüne artı bir çarpanı gelir ve yalnızca $\omega$'ya göre dördüncü mertebeden türev alınır:

$$t^4 x(t) \leftrightarrow (+1)\,\frac{d^4 X(\omega)}{d\omega^4}$$

$n = 1$ ve $n = 4$ durumları, sayısal türevle Python ile doğrulandı.

### 3.4 Karmaşık Üstelle Çarpma: Modülasyon

> **Hocanın vurgusu:** Zamanda öteleme ve karmaşık üstelle çarpma "çok önemli" özelliklerdir ve çok kullanılacaktır. Sinyal işlemeyle ilgili bir işte çalışacaksanız ya da ileride görüntü işleme, derin öğrenme gibi konuları görecekseniz bunlar çok daha fazla lazım olacak.

Bu özellik, zamanda ötelemenin tam tersidir. Zamanda ötelemede frekans düzleminde karmaşık üstelle çarpıyorduk. Zaman düzleminde karmaşık üstelle çarparsak da frekans ekseninde öteleme olur:

$$x(t)\, e^{j\omega_0 t} \leftrightarrow X(\omega - \omega_0)$$

$e^{j\omega_0 t}$ hem kosinüs hem sinüs içerir. Bir işareti kosinüsle çarpmak ise modülasyon demektir. Modülasyonun frekans eksenindeki karşılığı $\omega_0$ kadar ötelemedir. Yalnızca kosinüsle ya da yalnızca sinüsle çarpıyorsak bir kopya $\omega_0$ kadar ileri, bir kopya $\omega_0$ kadar geri ötelenir. Sinüste ayrıca $j/2$ çarpanı vardır. Bunlar formülün kendisinden gelir:

$$x(t)\cos\omega_0 t \leftrightarrow \frac{1}{2}\left[X(\omega + \omega_0) + X(\omega - \omega_0)\right]$$

$$x(t)\sin\omega_0 t \leftrightarrow \frac{j}{2}\left[X(\omega + \omega_0) - X(\omega - \omega_0)\right]$$

Bu üç çift, $\omega_0 = 2$ için Python ile doğrulandı.

### 3.5 Türev ve İntegral

> **Hocanın vurgusu:** Asıl lazım olan özellik türevdir.

Bir $x(t)$ işaretinin $n$. türevini almak istediğimizde, $X(\omega)$'nın önüne $(j\omega)^n$ çarpanını ekleriz:

$$\frac{d^n x(t)}{dt^n} \leftrightarrow (j\omega)^n X(\omega)$$

Hoca bunun başlangıç koşulları olmayan durum için olduğunu, başlangıç koşulu olan durumun biraz daha farklı olduğunu söyledi.

İntegral özelliğinde $X(\omega)$, $j\omega$'ya bölünür ve ekstra bir dürtü terimi gelir. Buradaki $\lambda$ yalnızca integral değişkenidir:

$$\int_{-\infty}^{t} x(\lambda)\, d\lambda \leftrightarrow \frac{X(\omega)}{j\omega} + \pi X(0)\,\delta(\omega)$$

Hoca bu özelliğin kendi alanlarında o kadar kullanılmadığını, türevin çok daha sık kullanıldığını ekledi.

> **Ders sonrası not:** Hoca dürtünün katsayısındaki terime "başlangıç koşulu $x(0)$" dedi. Doğrusu $X(0)$'dır, yani dönüşümün $\omega = 0$'daki değeri. Bu değer işaretin altındaki alana eşittir, işaretin $t = 0$'daki değeri ya da bir başlangıç koşulu değildir. $e^{-t^2}$ için dürtü ağırlığının $\pi X(0)$ olduğu Python ile doğrulandı.

### 3.6 Konvolüsyon ve Zamanda Çarpma

> **Hocanın vurgusu:** Konvolüsyon özelliği bir diğer önemli özelliktir.

Sürekli zamanda konvolüsyonun integral sınırları vardı, integrali parçalara bölüyorduk. Üstelik integrali almak zorsa bir de oradan zorluk çıkıyordu. Oysa $x(t)$ ile $h(t)$'nin dönüşümlerini biliyorsak ikisini çarparız, konvolüsyonun dönüşümünü elde ederiz. Bunun ters dönüşümünü alırsak konvolüsyon sonucunun zaman düzlemindeki karşılığını buluruz:

$$x(t) * h(t) \leftrightarrow X(\omega)\, H(\omega)$$

Zaman düzleminde işaretleri çarpıyorsak bu kez frekans düzleminde konvolüsyon yaparız:

$$x(t)\, y(t) \leftrightarrow \frac{1}{2\pi}\, X(\omega) * Y(\omega)$$

> **Ders sonrası not:** Altyazıda bu çarpan için "iki bölü pi'ye bölüp" deniyor. Doğrusu $2\pi$'ye bölmektir, yani çarpan $1/(2\pi)$'dir. İki Gauss tabanlı işaretle Python ile doğrulandı.

### 3.7 Parseval Teoremi

Hoca Parseval teoremini hatırlatırken, bunun frekans düzleminde de bir karşılığı olduğunu söyledi: Fourier dönüşümlerinin integrali alınıp $1/(2\pi)$ ile çarpılır.

> **Ders sonrası not:** Hoca teoremi "işaretin bileşenlerini toplayıp orijinal işareti oluşturuyordu" diye hatırlattı. Bu anlatım Parseval teoremini değil, Fourier sentezini tarif eder. Parseval teoremi iki düzlemdeki integralleri eşitler: $\int_{-\infty}^{\infty} x(t)\,y(t)\,dt = \frac{1}{2\pi}\int_{-\infty}^{\infty} X^*(\omega)\,Y(\omega)\,d\omega$ (gerçel $x$, $y$ için). $y = x$ alınırsa işaretin enerjisi iki düzlemde de aynı çıkar: $\int_{-\infty}^{\infty} x^2(t)\,dt = \frac{1}{2\pi}\int_{-\infty}^{\infty} \lvert X(\omega)\rvert^2\,d\omega$. Sayısal olarak iki taraf da $1{,}56664$ (enerji) ve $1{,}38262$ (iki işaret) çıktı (Python ile doğrulandı).

<!-- BELİRSİZ: Slayttaki Parseval eşitliğinin tam biçimi altyazıda okunmuyor. Hocanın "her birinin" sözü iki işaretli biçime işaret ediyor. -->

### 3.8 Dualite

$x(t)$ ile $X(\omega)$ birbirine dönüştürülebiliyorsa, $X(\omega)$'da $\omega$ yerine $t$ yazıp yeni bir zaman işareti elde edebiliriz. Bu $X(t)$ işaretinin dönüşümü:

$$X(t) \leftrightarrow 2\pi\, x(-\omega)$$

Yani yalnızca değişken dönüşümü yapılmış olur, sonuçta $2\pi$ çarpanı ve bir frekans terslemesi gelir. Bu eşitlik Python ile doğrulandı.

## 4. Diferansiyel Denklemin Fourier Dönüşümüyle Çözümü

Hoca "bu kadar anlattık, bir işe yarayacak bir şey konuşalım" diyerek özellikleri bir örnekte kullandı.

### 4.1 Problem

Çalışması şu diferansiyel denklemle verilen bir sistem var:

$$\frac{dy(t)}{dt} + 2y(t) = x(t) + \frac{dx(t)}{dt}$$

İstenen, türevlerden arındırılmış, giriş-çıkış ilişkisini gösteren ifadedir. Hoca önce "$y(t)$'yi bulun" dedi, sonra asıl bulacağımız şeyin $h(t)$ olduğunu belirtti.

> **Ders sonrası not:** Hoca $h(t)$'ye bu örnek boyunca "sistemin birim basamak cevabı (tepkisi)" dedi. Doğrusu $h(t)$ **birim dürtü cevabıdır**. Birim basamak cevabı $s(t) = \int_{-\infty}^{t} h(\tau)\,d\tau$'dur. Bu örnekte $s(t) = \tfrac{1}{2}\left(1 + e^{-2t}\right)u(t)$ olur (Python ile doğrulandı).

Burada $y(t)$ ile türevleri bilinmeyen şeylerdir. Hoca, daha önce diferansiyel denklemler için gösterilen yöntemlerin burada pek işe yaramayacağını söyledi. Dönüşümle ilerleyeceğiz.

### 4.2 Türev Özelliğiyle Cebirsel Denkleme Geçiş

$y(t)$'nin dönüşümünün $Y(\omega)$ olduğunu biliyoruz. Hoca sınıfa sordu.

**Soru:** O zaman $y'(t)$'nin Fourier dönüşümünü ne olarak yazarız?

**Cevap:** Sınıftan "$Y$ türev $\omega$" cevabı geldi. Hoca bunun işe yaramadığını söyledi, çünkü bize $Y(\omega)$ cinsinden karşılığı lazım. Türev özelliğine göre $Y(\omega)$'yı $(j\omega)^n$ ile çarparız. Burada birinci türev olduğu için $n = 1$'dir.

> **Hocanın vurgusu:** Problemi çözmek için türevli ifadelerden kurtulmamız gerekir. "$Y$ türev $\omega$" bu yüzden işimize yaramaz.

Denklemin iki tarafının dönüşümünü alalım:

$$j\omega\, Y(\omega) + 2\,Y(\omega) = X(\omega) + j\omega\, X(\omega)$$

Sol tarafı $Y(\omega)$, sağ tarafı $X(\omega)$ parantezine alırız:

$$Y(\omega)\,(2 + j\omega) = X(\omega)\,(1 + j\omega)$$

### 4.3 $H(\omega)$

İki tarafı $X(\omega)$'ya ve $(2 + j\omega)$'ya böleriz:

$$H(\omega) = \frac{Y(\omega)}{X(\omega)} = \frac{1 + j\omega}{2 + j\omega}$$

> **Ders sonrası not:** Hoca "$h(t)$, $y(t)$'nin $x(t)$'ye oranıdır" dedi. Bu oran zaman düzleminde geçerli değildir, yalnız frekans düzleminde $H(\omega) = Y(\omega)/X(\omega)$ yazılır. Zaman düzlemindeki ilişki konvolüsyondur: $y(t) = x(t) * h(t)$. Aynı şekilde $h(t)$, $y(t)$'nin kendisi değildir. $x(t) = e^{-t}u(t)$ girişi için $x * h$ sonucunun diferansiyel denklemi $t > 0$'da sağladığı Python ile doğrulandı.

Hoca bu $H(\omega)$'nın ters Fourier dönüşümünü alırsak $h(t)$'yi, yani sistemin çalışma mantığını bulacağımızı söyledi.

### 4.4 Basit Kesirlere Ayırma ve Ters Dönüşüm

Basit kesirlere ayırmayı daha sonra Laplace'ta ayrıntılı konuşacağız. Burada kısa bir yol var: Paydaki $1 + j\omega$, paydadaki $2 + j\omega$'dan $1$ çıkarılarak elde edilir:

$$H(\omega) = \frac{(2 + j\omega) - 1}{2 + j\omega} = 1 - \frac{1}{2 + j\omega}$$

İki ifadenin eşitliği Python ile doğrulandı. Ters dönüşümleri integralle almayacağız, tablolara bakacağız.

**Soru:** Neyin Fourier dönüşümü $1$'di?

**Cevap:** $\delta(t)$'nin. Hoca bunu az önce integralle de yazdığını hatırlattı.

Tablodan $e^{-bt}u(t) \leftrightarrow \dfrac{1}{b + j\omega}$ çiftini de kullanırız. Burada $b = 2$'dir:

$$\delta(t) \leftrightarrow 1, \qquad e^{-2t}u(t) \leftrightarrow \frac{1}{2 + j\omega}$$

Sonuç:

$$h(t) = \delta(t) - e^{-2t}u(t)$$

Böylece diferansiyel denklemi çözmüş olduk, sistemin giriş-çıkış ilişkisi bu ifadedir. Artık sisteme bir $x(t)$ girişi verdiğimizde elde edilecek sonucu bulabiliriz.

Hoca, sistemin $t = 100$ anındaki davranışını da yerine koyarak bulabileceğimizi söyledi. Adım adım:

- $\delta(100) = 0$'dır.
- $u(100) = 1$'dir, ikinci terim $e^{-200}$ olur.
- $h(100) = 0 - e^{-200} \approx -1{,}38 \times 10^{-87}$ (ara adım eklendi, Python ile hesaplandı).

## 5. Periyodik İşaretin Fourier Dönüşümü

Periyodik bir işareti zaten Fourier serisiyle analiz etmiştik:

$$x(t) = \sum_{k=-\infty}^{\infty} c_k\, e^{jk\omega_0 t}$$

Bu işaretin Fourier dönüşümünü almak için iki tarafa da dönüşüm uygularız. Dönüşüm toplam sembolünün içine atılabilir. İçeride kalan ifade $e^{jk\omega_0 t}$'nin dönüşümüdür ve bunu az önce konuştuk: $2\pi\,\delta(\omega - k\omega_0)$. Sonuç:

$$X(\omega) = 2\pi \sum_{k=-\infty}^{\infty} c_k\, \delta(\omega - k\omega_0)$$

Bu dürtüleri öğleden önceki derste de görmüştük. Şöyle okunur: Dürtüler temel frekansın katlarındadır, $k = 1$ için $1\cdot\omega_0$'da, $k = 2$ için $2\cdot\omega_0$'da bulunur. Bu dürtülerin değerleri, Fourier serisinden bildiğimiz $c_k$ katsayılarından gelir ve ayrıca $2\pi$ ile çarpılır. Yani aslında bir Fourier serisini Fourier dönüşümü ile de bulabiliriz, bu da bir yöntemdir.

Slaytta aynı işlem grafik olarak gösteriliyordu: $\omega_0$, $2\omega_0$, $3\omega_0$, $4\omega_0$ noktaları vardı. Bulduğumuz $c_k$'ları buraya yazarsak işaretin frekans spektrumunu çizmiş oluruz. Hoca fazla ilgili kısmın çok önemli olmadığını söyleyip geçti.

Ağırlıkların $2\pi c_k$ olduğu, $\omega_0 = 1$ olan bir kare dalgada $k = 1, 3, 5$ için Python ile doğrulandı.

## 6. Özellikler: Slaytlar Üzerinden Daha Ayrıntılı

Hoca bu kez özellikler slaytlarını sırayla açtı. Bu özellikler sayesinde, biraz önceki diferansiyel denklemde olduğu gibi birçok problem çok rahat çözülebiliyor.

### 6.1 Doğrusallık ve İspatı

$x(t) \leftrightarrow X(\omega)$ ve $y(t) \leftrightarrow Y(\omega)$ ise katsayılar ve toplama dönüşümü değiştirmez:

$$a\,x(t) + b\,y(t) \leftrightarrow a\,X(\omega) + b\,Y(\omega)$$

İspat için integrali yerine yazalım. Toplamın integrali iki integrale ayrılır, katsayılar dışarı çıkar:

$$\int_{-\infty}^{\infty} \left[a\,x(t) + b\,y(t)\right] e^{-j\omega t}\, dt = a\int_{-\infty}^{\infty} x(t)\, e^{-j\omega t}\, dt + b\int_{-\infty}^{\infty} y(t)\, e^{-j\omega t}\, dt = a\,X(\omega) + b\,Y(\omega)$$

### 6.2 Zamanda Öteleme

$c$ kadar kaydırma yaptığımızda $X(\omega)$'ya bir çarpan, hocanın deyişiyle bir gecikme eklenir. Bunu biraz önce dürtü üzerinde göstermiştik. $x(t)$ sinüs, kosinüs veya kendi tanımladığınız bir işaret de olsa aynı sonuç geçerlidir.

> **Ek bilgi (derste anlatılmadı):** Genel ispat değişken dönüşümüyle yapılır. $\tau = t - c$ denirse $\int x(t-c)\,e^{-j\omega t}\,dt = \int x(\tau)\,e^{-j\omega(\tau + c)}\,d\tau = e^{-j\omega c} X(\omega)$ olur. Sonuç, simetrik olmayan bir işaret ve $c = 1{,}5$ için Python ile doğrulandı.

### 6.3 Zamanda Ölçekleme

$\omega$ yerine $\omega/a$ yazıp $1/\lvert a\rvert$ ile çarparak sonucu bulabiliyoruz. Sıfırdan integral almak çok maliyetli bir iştir. Elimizde $x(t)$'den elde edilmiş $X(\omega)$ varsa, ölçeklenmiş işaretlerin dönüşümünü hesaplamak çok daha kolaydır.

Slaytta bir örnek işaretin ölçeklenmiş hâlleri ve dönüşümleri yan yana gösteriliyordu.

<!-- BELİRSİZ: Slayttaki grafikler altyazıda yalnız sözlü geçiyor. Hoca bir işaretin "A bölü 2" ve "2A" ile ölçeklenmiş hâllerinden söz ediyor. -->

Örneğin $x(2t)$ yaparsak işareti zamanda sıkıştırmış oluruz. $\omega/2$ yazmak ise bölmek demektir, yani frekans ekseninde işareti germiş oluruz. Tersini yaparsak, yani zamanda açarsak, bu kez frekans ekseninde sıkıştırırız. $a = 2$ için

$$x(2t) \leftrightarrow \frac{1}{2} X\!\left(\frac{\omega}{2}\right)$$

olur. Bu eşitlik Python ile doğrulandı.

### 6.4 Zamanda Ters Çevirme

$x(t)$ işaretini ters çevirirsek dönüşüm doğrudan $X(-\omega)$ olur. Hoca ispatın uzun olduğunu, integralde $t$ yerine $-t$ yazılarak geldiğini ve faz tarafında bazı farklılıklar çıktığını, ama burada faza çok girmeyeceğini söyledi. $\tau = -t$ dönüşümüyle (ara adım eklendi):

$$\int_{-\infty}^{\infty} x(-t)\, e^{-j\omega t}\, dt = \int_{-\infty}^{\infty} x(\tau)\, e^{-j(-\omega)\tau}\, d\tau = X(-\omega)$$

### 6.5 Modülasyon

Bir işareti başka bir işaretle modüle etmek, aslında onunla çarpmak demektir. $x(t)$'yi $e^{j\omega_0 t}$ ile çarpınca dönüşümde yalnızca frekans ekseninde belli bir kaydırma olur.

Hoca bu kaydırmaya MATLAB'den de örnek verdi: MATLAB'in FFT fonksiyonunda işaretin sıfır noktasına göre bir kayması vardır ve bu kaydırma geri alınabilir. Bunu daha sonra göreceğiz.

> **Ders sonrası not:** Bu kayma, FFT çıktısının dizilişinden kaynaklanır. NumPy'da $8$ noktalı örnekte FFT çıktısının frekans sırası $0, 1, 2, 3, -4, -3, -2, -1$'dir, yani sıfır frekansı ilk sıradadır. `fftshift` bu diziyi $-4, \ldots, 3$ sırasına getirip sıfırı ortaya alır (Python ile çalıştırıldı). MATLAB'in `fft` ve `fftshift` fonksiyonları da büyük olasılıkla aynı dizilişi kullanır.

Sinüzoidal modülasyon, hep yaptığımız örnektir. $e^{j\omega_0 t}$ ile çarpma biliniyor, kosinüs de bu üstellerle yazılabiliyor. Slaytta ispat şöyle yapılıyordu: Kosinüsün yerine (ara adım eklendi)

$$\cos\omega_0 t = \frac{e^{j\omega_0 t} + e^{-j\omega_0 t}}{2}$$

yazılır. Her terimin dönüşümü, biraz önceki özellikten ötelenmiş bir kopyadır: Biri aşağı, biri yukarı. Toplamı Bölüm 3.4'teki sonucu verir. Sinüsle çarpınca sonuç benzerdir, yalnız frekans eksenindeki kopyalardan biri, pozitif $\omega_0$ tarafındaki, aşağıya doğru bakar.

<!-- BELİRSİZ: Slayttaki modülasyon grafikleri altyazıda sözlü geçiyor. Hoca bunun örneklemede de kullanıldığını söyleyip geçti. -->

### 6.6 Konvolüsyon, Parseval ve Dualite

Konvolüsyon, zaman düzleminde yaptığımız işlemin frekans düzlemindeki hâlidir. Hoca bununla ilgili örneği daha sonra yapacağını söyledi. Parseval teoremini ve dualiteyi hoca bu geçişte atladı, çok fazla girmeye gerek olmadığını söyledi. Dualitenin, zaten konuşulan gecikme ve modülasyon özellikleriyle ilişkili olduğunu ekledi.

## 7. Uygulama: Sesin Modüle Edilip Taşınması

Herhangi bir sesi karşı tarafa aktarmak için, onu bir kanalda modüle etmemiz gerekir. Bir $x(t)$ işaretimiz var ve bunu bir kosinüs işaretiyle modüle ediyoruz. Hoca insan kulağının duyma aralığını "$10$ Hz - $10$ kHz miydi, $20$ Hz - $20$ kHz miydi, şu an hatırlamıyorum" diye andı.

> **Ders sonrası not:** İnsan kulağının duyma aralığı büyük olasılıkla yaklaşık $20$ Hz - $20$ kHz'dir.

Ses belli bir frekans aralığındadır. Kosinüsle çarpma sayesinde bu ses, kablonun veya antenin taşıyabileceği frekans aralığına çekilir. Çarpma sonucunda işaretin frekans karşılığı yatay eksende ötelenmiş olur.

> **Ders sonrası not:** Hoca bu çarpmaya bir yerde "ölçekleme" dedi. Bu, Bölüm 6.3'teki zamanda ölçekleme değildir. Burada olan, Bölüm 3.4'teki frekans ötelemesidir.

Hocanın örneklerinde $\omega_0$ değeri, kullanıma göre seçilir: AM radyoda "100 MHz", cep telefonlarında gigahertz bölgesi. Ses bu aralığa taşınmış olur.

> **Ders sonrası not:** Hocanın AM radyo için söylediği $100$ MHz büyük olasılıkla FM bandına aittir ($88$-$108$ MHz). AM yayınları büyük olasılıkla yaklaşık $0{,}5$-$1{,}7$ MHz aralığındadır.

Peki alıcı bunu nasıl geri alır? Telefonsa kendi çalışma aralığındadır. Gelen işaret, tekrar kosinüs işaretiyle demodüle edilir ve o aralıktan olması gereken noktaya, kulağımızın duyacağı aralığa geri çekilir. Bu sırada oluşan ekstra kopyalar atılır, bize lazım olan parça kalır. Hoca bunun ters dönüşümünü alarak duyulabilir $x(t)$ işaretini bulduğumuzu söyledi.

> **Ders sonrası not:** Hoca alıcının "ters Fourier dönüşümü alarak" sesi geri elde ettiğini söyledi. Fourier dönüşümü burada işlemi anlamak için kullanılan araçtır, geri kazanımı sağlayan şey yeniden çarpmadır. $\cos^2\omega_0 t = \tfrac{1}{2}\left(1 + \cos 2\omega_0 t\right)$ olduğundan $x(t)\cos^2\omega_0 t$ işaretinin dönüşümü $\tfrac{1}{2}X(\omega) + \tfrac{1}{4}\left[X(\omega - 2\omega_0) + X(\omega + 2\omega_0)\right]$'dir (Python ile doğrulandı). Hocanın "atılıyor" dediği kopyalar $\pm 2\omega_0$ civarındakilerdir. Kalan parça $\tfrac{1}{2}X(\omega)$'dır. Bu atma işlemi pratikte büyük olasılıkla alçak geçiren bir filtreyle yapılır.

<!-- BELİRSİZ: Slayttaki modülasyon ve demodülasyon spektrum grafikleri altyazıda yalnız sözlü geçiyor. -->

## 8. Fourier Dönüşümünde Neler Hayati?

Hoca, sonraki derste uygulamalara devam edeceğini söyleyerek bir tavsiye verdi.

> **Hocanın vurgusu:** Fourier dönüşümünü iyi öğrenin, üzerinde bayağı duracağız. Bu slaytta hayati olan, Fourier integralini bilmektir. Ters Fourier integralini o kadar çok kullanmıyoruz. Tablodaki bazı işaretler ile konvolüsyon ve diferansiyel denklem için kullanılan özellikler çok işimize yarayacak.

Hoca son olarak kosinüs işaretinin dönüşümünü yeniden gösterdi. Tek bir kosinüs işaretinde tek bir frekans bileşeni vardır, ama spektrumda biri pozitif, biri negatif tarafta olmak üzere iki dürtü görürüz. Daha önce MATLAB'de yazılan kodun da buna benzer sonuçlar gösterdiğini hatırlattı.

Bir önceki yıl kullanılan ikinci bir slayt setinde daha çok örnek bulunduğunu da söyledi.

<!-- BELİRSİZ: İkinci slayt setinde hocanın işaret ettiği örnek işaret altyazıda belirtilmiyor. -->

## 9. Fourier Dönüşümü Her Zaman Var Mı?

Hoca, öğleden önceki derste bir konuda söz verip söylemediği noktaya geri döndü. Örneğini iki adımda kurdu.

### 9.1 $e^{at}u(-t)$: Dönüşüm Vardır

Daha önce $e^{-at}u(t)$ için sonucun şu olduğunu bulmuştuk:

$$e^{-at}u(t) \leftrightarrow \frac{1}{a + j\omega}$$

Şimdi işareti biraz değiştirelim. $a > 0$ olmak üzere $x(t) = e^{at}u(-t)$ olsun:

$$X(\omega) = \int_{-\infty}^{\infty} e^{at}\, u(-t)\, e^{-j\omega t}\, dt$$

$u(-t)$ yalnızca $t \le 0$ için bir olduğundan integral $-\infty$'dan $0$'a kadar alınır. $t$ ortak parantezine alınırsa:

$$X(\omega) = \int_{-\infty}^{0} e^{(a - j\omega)t}\, dt = \left.\frac{e^{(a - j\omega)t}}{a - j\omega}\right|_{-\infty}^{0}$$

Sınırları yerine koyalım. $t = 0$ için $e^0 = 1$ olur ve $\dfrac{1}{a - j\omega}$ gelir. $t \to -\infty$ için terim sıfırdır. Sonuç:

$$e^{at}u(-t) \leftrightarrow \frac{1}{a - j\omega}, \quad a > 0$$

Bu çift $a = 1$ ve $a = 3$ için Python ile doğrulandı. Görüldüğü gibi bu örnekte integral alınabildi.

### 9.2 $e^{at}u(t)$: Dönüşüm Yoktur

Hoca örneği bir kez daha değiştirdi: Üstelde $e^{at}$, basamakta $u(t)$ olsun, yine $a > 0$. İkisi de pozitif. Bu kez $u(t)$'den dolayı integral $0$'dan $\infty$'a alınır:

$$X(\omega) = \int_{0}^{\infty} e^{at}\, e^{-j\omega t}\, dt = \int_{0}^{\infty} e^{(a - j\omega)t}\, dt = \left.\frac{e^{(a - j\omega)t}}{a - j\omega}\right|_{0}^{\infty}$$

> **Ders sonrası not:** Altyazıda bu üstel terim "$e$ üzeri eksi $(a - j\omega)t$" diye geçiyor. Doğrusu üstte eksi işareti olmayan $e^{(a - j\omega)t}$'dir.

$t$ yerine sonsuz koyarsak üst sınır sonsuz çıkar, $t = 0$ koyarsak bir çıkar. Yani "sonsuz eksi bir" sonsuzdur. Bu integral alınamaz: Yakınsamıyor, ıraksıyor. Hoca bunu fonksiyonun grafiğiyle de düşündürdü: $e^{at}$ artan bir fonksiyondur ve sonsuza kadar integre ettiğimizde altında kalan alan sonsuz çıkar.

Sayısal olarak $a = 1$, $\omega = 1$ için integralin üst sınırı $T$ alındığında mutlak değer şöyle büyür: $T = 5$'te yaklaşık $105$, $T = 10$'da yaklaşık $1{,}56 \times 10^{4}$, $T = 20$'de yaklaşık $3{,}43 \times 10^{8}$ (Python ile hesaplandı).

> **Hocanın vurgusu:** Her şeyin illa ki Fourier dönüşümü olacak diye bir şey yok. Bu tür bir işaret ıraksadığı için Fourier dönüşümü yoktur, ancak Laplace dönüşümü olur. Ona daha sonra geleceğiz.

> **Ek bilgi (derste anlatılmadı):** Laplace dönüşümü integralin içine ek bir $e^{-\sigma t}$ azaltıcı çarpanı katar. $e^{at}u(t)e^{-\sigma t}$ işaretinin Fourier dönüşümü, $\sigma > a$ olduğunda vardır ve $\dfrac{1}{\sigma - a + j\omega}$'ya eşittir. Bu sonuç $a = 1$, $\sigma = 3$ için Python ile doğrulandı.

## 10. Ayrık Konvolüsyonda Sıfır Noktası İçin Kısa Yol

Hoca, öğleden önceki derste gösterdiği kısa yolda bir şeyi söylemeyi unuttuğunu belirtip ekledi. Soru şudur: Konvolüsyon sonucunda hangi nokta $n = 0$'dır?

> **Hocanın vurgusu:** İki işaretin sıfır noktalarını çarptığınız adımda elde ettiğiniz sonuç, konvolüsyonun sıfır noktasıdır.

Örnek işaretler:

$$x[n] = \{1, \underline{2}, 1\}, \quad n = -1, 0, 1 \qquad\qquad h[n] = \{\underline{1}, 1\}, \quad n = 0, 1$$

Altı çizili değer $n = 0$ noktasıdır. $h$'yi ters çevirip $x$ üzerinde birer birer kaydırıyoruz:

| Adım | Örtüşen çarpımlar | Toplam | $y[n]$ |
|:---:|:---:|:---:|:---:|
| 1 | $x[-1]\,h[0] = 1 \cdot 1$ | $1$ | $y[-1] = 1$ |
| 2 | $x[0]\,h[0] + x[-1]\,h[1] = 2 \cdot 1 + 1 \cdot 1$ | $3$ | $y[0] = 3$ |
| 3 | $x[1]\,h[0] + x[0]\,h[1] = 1 \cdot 1 + 2 \cdot 1$ | $3$ | $y[1] = 3$ |
| 4 | $x[1]\,h[1] = 1 \cdot 1$ | $1$ | $y[2] = 1$ |

Hocanın anlatımıyla: İlk adımda çıkan $1$, $h$'nin sıfır noktasındaki $1$ ile $x[-1]$'in çarpımıdır. $x$'in sıfır noktası çarpılmadığı için burası sonucun sıfır noktası değildir. Bir kaydırınca $h$'nin sıfır noktası $x$'in sıfır noktasına ($2$) gelir, bu çarpım o adımda yapılır. Demek ki **bu adım $n = 0$'dır**. Adımın toplamı ise tablodaki gibi $3$'tür. Hoca bu değeri bir an "$2$" diye yazıp hemen $3$ olarak düzeltti.

Sonucun bir elemanı sıfır noktası olarak belirlendikten sonra, ayrık zamanda indisler birer birer arttığı için geri kalanı sağa ve sola doğru yazılır:

$$y[n] = \{1, \underline{3}, 3, 1\}, \quad n = -1, 0, 1, 2$$

Sonuç Python ile doğrulandı (`np.convolve([1,2,1],[1,1])` çıktısı $[1, 3, 3, 1]$).

Hoca sınırlardan da aynı sonuca gitmeyi gösterirken bir an duraksadı.

**Soru:** (Hoca, $h$'nin aralığını $-1$'den $0$'a diye okuduktan sonra sordu.) Yanlış mı yaptım?

**Cevap:** Bir öğrenci, hocanın yansımayı okuduğunu, $h$'nin aralığının $0$'dan $1$'e olduğunu söyledi. Hoca düzeltti.

Sınır kuralı şudur: Sonucun alt sınırı, alt sınırların toplamı, üst sınırı da üst sınırların toplamıdır.

- Alt sınır: $-1 + 0 = -1$.
- Üst sınır: $1 + 1 = 2$.

Hoca iki yolun da aynı sonucu verdiğini söyledi. Kendisine en kolay gelen yolun, hesapları yaptıktan sonra sınırları toplayıp indisleri birer birer yazmak olduğunu ekledi.

## Dersin Toparlaması

Bu derste, Fourier dönüşümünün neden işe yaradığı görüldü. Tablodaki çiftler ($\delta(t)$, $\delta(t - c)$, kosinüs, sinüs, karmaşık üstel) ve özellikler (doğrusallık, öteleme, ölçekleme, ters çevirme, $t^n$ ile çarpma, modülasyon, türev, integral, konvolüsyon, Parseval, dualite) sayesinde birçok sonuç integral hesaplamadan bulunur. Türev özelliği diferansiyel denklemi cebirsel denkleme çevirir. $\dfrac{dy}{dt} + 2y = x + \dfrac{dx}{dt}$ örneğinde bu yolla $H(\omega) = \dfrac{1 + j\omega}{2 + j\omega}$ ve $h(t) = \delta(t) - e^{-2t}u(t)$ bulundu. Periyodik işaretin dönüşümünün $2\pi c_k$ ağırlıklı dürtülerden oluştuğu, sesin kosinüsle çarpılarak kanal aralığına taşındığı görüldü.

Her işaretin Fourier dönüşümü yoktur: $e^{at}u(t)$, $a > 0$ için integral ıraksar, bu tür işaretlerde Laplace dönüşümüne ihtiyaç duyulur ve Laplace'a daha sonra gelinecektir. Hoca sonraki derste Fourier dönüşümünün uygulamalarına ve konvolüsyon örneklerine devam edeceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
