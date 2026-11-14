# Ders 10 Genişletilmiş Notu: Fazörlere Giriş: Karmaşık Sayılar, Sinüzoidal İşaretler, RMS, Faz Farkı ve Fazör Dönüşümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Geçen Haftanın Özeti: RLC Devrelerinin Zaman Domeninde Çözümü
- 2. Neden Fazör Uzayına Geçiyoruz?
- 3. Fazör Uzayında Bir Devrenin Görünümü ve Empedans
- 4. Frekansın Etkisi: Deneysel Gözlem ve Çözüm Akışı
- 5. Karmaşık Sayılar: Tanım ve Gösterimler
- 6. Euler Formülü ve Kuvvet Serisi
- 7. Üç Gösterim, Eksenler Üzerindeki Sayılar ve Eşlenik
- 8. Kartezyen Formda Dört İşlem
- 9. Polar Formda Çarpma ve Bölme
- 10. Fazör Uzayında Ohm Kanunu
- 11. Fazör Uzayında Güç ve Polar Formda Eşlenik
- 12. Sinüzoidal İşaretin Parametreleri
- 13. Genlik, Tepeden Tepeye Değer, Ortalama Değer ve RMS
- 14. Faz Farkı: Önde ve Geride Olan İşaret
- 15. Özel Sayıların Fazör Gösterimi
- 16. Zaman Domeninden Fazöre, Fazörden Zaman Domenine
- 17. Özel Fonksiyonlara Kısa Bir Bakış
- 18. Sinüzoidal Kaynaklı RL Devresi ve Geçici Hâlin Sönmesi
- 19. R, L ve C'nin Fazör Uzayındaki Tanım Bağıntıları
- 20. Laboratuvar Oturumundan Akademik Notlar

## 1. Geçen Haftanın Özeti: RLC Devrelerinin Zaman Domeninde Çözümü

Hoca derse geçen haftanın özetiyle başladı. İkinci dereceden RLC devrelerinin zaman domeninde dört durumu incelenmişti:

- Kaynaksız seri RLC devresi. Kaynaksız derken, ilk koşul oluşturulduktan sonraki durumdan söz ediyoruz.
- Kaynaksız paralel RLC devresi.
- DC kaynaklı seri RLC devresi.
- DC kaynaklı paralel RLC devresi.

Kaynaksız devrelerde yalnız homojen çözüm vardı. Denklem ikinci dereceden olduğu için homojen çözüm iki çözüm içeriyordu ve aradığımız genel çözüm bunların lineer toplamıydı. Kaynaklı devrelerde genel çözüm, homojen çözüm artı zorlanmış çözümdü. Yani üç terimli bir sonuç elde ediyorduk: homojen çözümden iki, zorlanmış çözümden bir terim.

Bu iki parçayı şöyle ayırıyorduk. Diferansiyel denklem "lineer ifade eşittir sabit" biçimindeydi. Sağ tarafı sıfır alıp homojen çözümü buluyorduk. Sonra sağ tarafı kaynak değerine eşitleyip kaynağın tipinde bir fonksiyon öneriyorduk. Kaynak sabit olduğu için öneri de sabit bir değerdi. Böylece zorlanmış çözüm elde ediliyordu.

Homojen çözümden gelen davranışa doğal çözüm deniyordu. Bu davranış pratikte yaklaşık $5\tau$ boyunca geçerliydi. $5\tau$ sonra üstel geçici rejimler bitiyor, devre kaynağın belirlediği sürekli davranışa dönüyordu. $t \to \infty$ durumunda DC şartlarda kapasite açık devre, endüktans kısa devre gibi davranıyordu. Bu eşdeğer elemanları yerine koyup devreyi çözerek ilgilendiğimiz değerlere bakıyorduk. Hoca geçici hâli şöyle tarif etti: Endüktans ve kapasite elemanlarının etkileşiminin bittiği, ilk durumların etkisinin kaybolduğu, kaynak etkisinin diğerlerini bastırdığı duruma sürekli hâl diyoruz. DC kaynak bağlı bir devrede sürekli hâl analizi, DC analize karşılık geliyordu.

## 2. Neden Fazör Uzayına Geçiyoruz?

### 2.1 Sinüzoidal Kaynakta Geriye Ne Kalıyor?

Geçen haftaki RLC devrelerinde kaynak DC idi. DC kaynak yerine sinüzoidal kaynak kullansaydık çözümde homojen kısımdan iki üstel terim, zorlanmış kısımdan da bir sinüzoidal terim gelirdi. Üstel terimler zamanla azalıp kaybolur. Belirli bir noktadan sonra devrede yalnız sinüzoidal kaynağın etkisi kalır. Bu yüzden analizi, sinüzoidal fonksiyonların farklı bir gösterimi olan fazörler üzerinden yapmak devre çözümlemeyi basitleştirir.

### 2.2 Bir Boyut Ekleyip Diferansiyel Denklemden Kurtulmak

Zaman domeninde yalnız $t$ ile ilgileniyoruz, yani bir boyutlu bir uzayda çalışıyoruz. Fazör uzayı ise iki boyutlu, düzlemsel bir yapıdır. Daha yüksek bir uzaya geçip fazladan bir değişken eklemiş oluyoruz. Karşılığında şu avantajı elde ediyoruz: Zaman domeninde diferansiyel denklem olarak yazılmış bir denklem, fazör uzayında **lineer denkleme** dönüşür. Türev ve integral gibi karmaşık işlemler ortadan kalkar.

Hoca iki denklem tipini yan yana koydu. Lineer denklemler $ax + by$ biçimindedir. Diferansiyel denklemler ise $a f'' + b f' = \text{sabit}$ biçimindedir.

> **Hocanın vurgusu:** Fazör uzayını kullanmanın en büyük amacı ve faydası, diferansiyel denklemlerin lineer denklemlere dönüşmesidir.

### 2.3 Sinüzoidal Kaynak Yaygın Bir Durum, Değilse de Çare Var

Sinüzoidal kaynak kullanmak geçerli bir varsayımdır. Şehir şebeke gerilimi sinüzoidaldir. Kullanılan çeşitli modülasyon teknikleri de sinüzoidal işaretler kullanır. Bulunduğumuz ortamda pek çok sinüzoidal kaynak vardır.

Kaynak sinüzoidal olmasa bile yöntem işe yarar. Hoca, konu kapsamında olmadığını söyleyerek Fourier dönüşümüne kısaca değindi: Herhangi bir işaret, sonsuz sayıda sinüzoidal işaretin toplamı olarak yazılabilir. Sonsuz tane sinüzoidal toplamak pratikte mümkün değildir, ama $n$ adet ya da 3-5 adet sinüzoidalin toplamıyla örneğin bir kare dalga yaklaşık olarak elde edilebilir. Sonra süperpozisyondan yararlanılır: Her sinüzoidal bileşen tek tek devreye alınır, sürekli sinüzoidal hâl analizi yapılır ve sonuçların lineer toplamı alınır. Böylece kare dalganın davranışı kabaca modellenir.

> **Ek bilgi (derste anlatılmadı):** Hoca burada "Fourier dönüşümü" dedi. Periyodik bir işareti ayrık frekanslı sinüzoidallerin toplamı olarak yazan araç büyük olasılıkla Fourier serisidir. Kısa notta da "Fourier serisi" ifadesi kullanılır. Fourier dönüşümü ise periyodik olmayan işaretlerde büyük olasılıkla toplam yerine integral biçimini alır.

### 2.4 Fazör Analizi Yalnız Sürekli Hâlle İlgilenir

> **Hocanın vurgusu:** Çok önemli bir nokta: Fazör analizi yalnız sürekli hâl çözümüyle ilgilenir. Devredeki geçici (transient) kısım için çözüm vermez.

Pratikte bu, devre kurulup enerji verildikten sonra yaklaşık $5\tau$ geçtikten sonraki duruma bakmak demektir. Teoride ise devrenin aynı kaynaklarla yeterince uzun süre sürülmüş olduğu duruma karşılık gelir.

Sinüzoidal kaynak bağlandıktan bir süre sonra devrede ölçülen bütün değerler kaynak frekansında dalgalanır. Bir direncin gerilimi, bir endüktansın gerilimi ya da akımı, bir koldaki akım, hepsi kaynak frekansında salınır. Hoca bu durumu şöyle yorumladı: Bu özel durumda, real kısmı olmayan, yalnız imajiner olan bir karmaşık sayıyla çalışıyormuşuz gibi düşünebiliriz.

Geçici hâl ile sürekli hâli birlikte çözen yöntem Laplace analizidir. Hoca, zaman nedeniyle Laplace'ın büyük ihtimalle bu dersin kapsamına yetişmeyeceğini söyledi. Laplace analizinde kullanılan karmaşık sayının hem real hem imajiner kısmı vardır. Bu da hem geçici hem sürekli hâl analizini sağlar.

> **Ek bilgi (derste anlatılmadı):** Hocanın sözünü ettiği karmaşık sayı büyük olasılıkla Laplace değişkeni $s = \sigma + j\omega$'dır. Real kısım $\sigma$ üstel sönümü, imajiner kısım $\omega$ salınımı taşır. Fazör analizi bu durumda $\sigma = 0$, yani $s = j\omega$ özel durumuna karşılık gelir.

## 3. Fazör Uzayında Bir Devrenin Görünümü ve Empedans

Dersin konusu AC devre analizinde fazör kullanımıdır. Bu hafta matematik altyapısı kurulacak, önümüzdeki hafta devre çözümünde nasıl kullanıldığına bakılacak. Sinüzoidal kaynaklı bir RLC devresinin $5\tau$ sonraki davranışına sürekli hâl davranışı denir. Devre uzun süredir çalışıyorsa asıl ilgilenmemiz gereken kısım budur. Kaynak sinüzoidalse ve devre uzun zamandır çalışıyorsa, önceki haftalarda gördüğümüz geçici analiz bu senaryoda pek önemli olmaz.

Hoca slayttaki bir devre üzerinden görünümü anlattı. Kaynak zaman domeninde $120\cos(1000t)$ olsun. Geçici hâller bittikten sonra, devre ne kadar karmaşık olursa olsun, pasif elemanlardan oluşan devredeki bütün ölçülebilir değerler kaynak frekansında olacaktır. Kaynak frekansını baştan biliyoruz. O hâlde frekansı ayırır, devreye hiç katmayız. Devreyi yalnız genlikler üzerinden ve diferansiyel denklemlerin lineer karşılıklarıyla çözeriz. Düğüm analizi, çevre (mesh) analizi, süperpozisyon, Thevenin ve Norton teoremleri burada da geçerlidir. Fark, kullanılan değerlerin birer karmaşık sayı olmasıdır.

Slayttaki devrede şu değerler görülüyordu:

- Kapasite elemanının yanında $-j30$ yazıyor. Hoca bunu önce "$-j30$ farad" diye okudu, sonra burada farad olarak adlandırılmadığını, yalnız benzetme için böyle söylediğini belirtti.
- Direncin değeri $30$ olarak gösterilmiş. Karmaşık sayılar real sayıları kapsadığı için bu da imajiner kısmı olmayan bir karmaşık sayıdır.
- Bir başka elemanın yalnız empedans değeri verilmiş. Bu değerin hem real hem imajiner kısmı var.
- Kaynak farklı bir gösterimle yazılmış. Bu gösterim aslında $a + jb$ biçiminde bir karmaşık sayıya denk geliyor.

<!-- BELİRSİZ: Slayttaki devrenin eleman listesi ve kaynağın fazör değeri altyazıda tam okunmuyor. Yalnız -j30, 30 ve 120 cos(1000t) söyleniyor. -->

### 3.1 Empedans

> **Hocanın vurgusu:** Bu çok önemli bir nokta: Fazör uzayında bütün elemanların akıma karşı gösterdikleri dirence **empedans** denir. Fazör uzayındaki gerilim bölü fazör uzayındaki akım, empedans olarak tanımlanır.

Her eleman için empedans hesaplandıktan sonra bütün değerler karmaşık sayı olur. Düğüm ya da çevre analiziyle örneğin $I_2$ akımının karmaşık değeri bulunur. Karmaşık sayının fiziksel dünyada bir karşılığı yoktur. Bu yüzden sonucun real kısmını alıp fiziksel dünyaya döneriz ve kaynak frekansında bir sinüzoidal işaret elde ederiz. Devre çözülürken yalnız lineer denklemler kullanılmış olur. Örneğin kapasitenin tanımı $i = C\,dv/dt$ idi. Bu bağıntı fazör uzayında lineer bir denkleme dönüşür.

## 4. Frekansın Etkisi: Deneysel Gözlem ve Çözüm Akışı

### 4.1 Aynı Frekans, Farklı Genlik ve Faz

Yalnız dirençlerden oluşan bir devrede kaynak frekansı ne kadar değişirse değişsin eleman genlikleri değişmez. RLC devresinde ise elemanların akıma gösterdiği direnç, kaynak frekansıyla değişir. Yani empedans değerleri frekansa bağlıdır. Hoca bunu slaytlardaki deneysel sonuçlarla gösterdi. Kaynak $\sin(2\pi f t)$ gerilimidir ve turuncu dalga ile gösterilmiştir. Endüktans üzerindeki gerilim mavi dalgadır.

- **$f = 5$ kHz:** Çıkış gerilimi girişe göre oldukça küçük, adeta bastırılmış. Hoca bunun, yetişirse ileride göreceğimiz bir filtre yapısına karşılık geldiğini söyledi. Tepelerin arasını saydığımızda giriş ve çıkışın frekansı aynı çıkıyor. Yalnız genlikler farklı.
- **$f = 50$ kHz:** Çıkış genliği arttı, giriş işaretine yaklaştı.

Her iki şekilde çıkışın tepe yaptığı nokta ile girişin tepe yaptığı nokta arasında bir fark vardır. Aynı yöndeki sıfır geçişlerine bakıldığında da bir zaman farkı görülür. Bu fark faz farkı olarak adlandırılır. Her iki grafikte de bir bölme (division) 20 mikrosaniye olmasına rağmen, 50 kHz'te faz farkı küçülmüştür.

<!-- BELİRSİZ: Osiloskop ekranlarındaki devre değerleri altyazıda yok. Hocanın 5 kare saydığı aralığın tepeden tepeye hangi iki noktayı kapsadığı da net değil. -->

### 4.2 Fazörün Anlamı ve 10 kHz Örneği

Hocaya göre fazör, açı ve genlikten oluşan bir ikilidir. Slayttaki kaynağın genliği 1, faz açısı 0'dır. Dolayısıyla kaynağın karşılığı "1 ve 0" ikilisidir. Direncin fazör karşılığı kendisinin aynısıdır. Kapasite ve endüktans elemanlarının diferansiyel denklemleri ise lineer denklemlere dönüşür. Bunun ayrıntısına hoca burada girmedi.

Çözüm sonunda $f = 10$ kHz için çıkış $0.25$ genlikli ve $40^\circ$ açılıdır. Bu bir karmaşık sayıdır ve $a + jb$ biçiminde de yazılabilir. Hoca burada $i$ yerine $j$ kullanacağımızı hatırlattı. Fiziksel karşılığına şöyle geçilir: Genlik doğrudan dışarı çıkar. Örnekte kaynak sinüs olarak alındığı için sonuç da sinüs fonksiyonu olarak yazılır. Frekans giriş frekansının aynısıdır. Açı da faz olarak eklenir:

$$v_{\text{çıkış}}(t) = 0.25\sin(2\pi \cdot 10\text{k}\cdot t + 40^\circ)$$

<!-- BELİRSİZ: Bu örnekteki devre değerleri altyazıda yok, bu yüzden 0.25 ve 40 derece sonucu bağımsız olarak hesaplanamadı. -->

### 4.3 İzlenecek Yol

Hocanın "dar bir pencereden" özetlediği akış şudur:

1. Zaman domenindeki bütün eşitlikleri ve verilenleri fazör uzayına geçir.
2. Fazör uzayında karmaşık sayılarla işlem yaparak devreyi çöz.
3. İlgilenilen değerin fazör karşılığını hesapla.
4. Bu değerden zaman domenine dön.

Zaman domenine dönerken unutulmaması gereken nokta şudur: Sürekli sinüzoidal hâlde bütün değerlerin frekansı kaynak frekansıyla aynıdır. Çıkış işareti bundan yararlanılarak yazılır.

## 5. Karmaşık Sayılar: Tanım ve Gösterimler

### 5.1 Sayı Kümeleri

Doğal sayıların üzerinde tam sayılar, onların üzerinde $Q$ ile gösterilen rasyonel sayılar, onların üzerinde real sayılar, en üstte de karmaşık sayılar yer alır. Hoca önemli bir fark vurguladı: Doğal, tam, rasyonel ve real sayılar tek boyutlu bir doğru üzerindeki noktalardır, bu yüzden aralarında büyüklük-küçüklük tanımlanabilir. Karmaşık sayılar iki boyutlu uzayda olduğu için büyüklük-küçüklük tanımlanamaz.

### 5.2 Kartezyen Gösterim

Karmaşık sayı temelde sıralı bir ikilidir. Bir $z$ sayısı $x$ ve $y$ değerleriyle belirlenir. Geometrik olarak yatay eksen real eksen, dikey eksen imajiner eksendir:

$$z = x + jy$$

Daha önce sanal birim için $i$ kullanmıştık. Devre teorisi notasyonunda $j$ kullanılır, çünkü $i$'nin $i(t)$ biçiminde değişken akımı göstermesi ihtimali yüksektir.

### 5.3 Polar Gösterim

Aynı sayı polar biçimde $r$ ve $\phi$ ikilisiyle gösterilebilir. Polar format, fazöre karşılık gelen gösterimdir.

- $r$: Sayının orijine olan uzaklığı.
- $\phi$: Real eksenden saat yönünün tersine ölçülen açı.

Kartezyenden polara geçiş şöyledir:

$$r = \sqrt{x^2 + y^2}, \qquad \phi = \tan^{-1}\frac{y}{x}$$

Polar gösterim, "açı işareti" ile toparlanarak $z = r\angle\phi$ biçiminde yazılır. İlk değer orijinden sayıya olan uzaklık, açı sembolünün içindeki değer de real eksenle orijin-sayı doğrultusu arasındaki açıdır.

### 5.4 Polardan Kartezyene

Hoca sınıfa, $r$ ve $\phi$ verildiğinde $x$ ile $y$'nin nasıl bulunacağını sordu. Cevap bir dik üçgenden gelir. $r$ hipotenüs, $x$ komşu kenar, $y$ karşı kenardır. $x/r = \cos\phi$ ve $y/r = \sin\phi$ olduğundan:

$$x = r\cos\phi, \qquad y = r\sin\phi$$

$$z = x + jy = r\cos\phi + j\,r\sin\phi$$

## 6. Euler Formülü ve Kuvvet Serisi

Üçüncü gösterim üstel (eksponansiyel) formdur. Çıkış noktası Euler formülüdür:

$$e^{j\theta} = \cos\theta + j\sin\theta$$

Slaytlarda ayrıntısı olmadığı için hoca bunu tahtada gösterdi. Formül, $e^x$'in Taylor açılımına dayanır. Önce bir fonksiyonun kuvvet serisine (power series) nasıl açıldığı hatırlatıldı.

### 6.1 Kuvvet Serisi Katsayıları

Bir $f(x)$ fonksiyonunu şöyle yazıp yazamayacağımıza bakıyoruz. Sağ tarafa $g(x)$ diyelim:

$$f(x) = g(x) = a_0 + a_1 x + a_2 x^2 + \dots + a_n x^n + \dots$$

İki tarafın eşit olabilmesi için $f$ ve bütün türevleri, her $x$ değerinde $g$ ve türevlerine eşit olmalıdır. Hoca $x = 0$ koymanın "sihirli" olduğunu söyledi, çünkü $x$'in kuvvetlerini içeren terimler kaybolur.

- $f(0) = g(0) = a_0$.
- Türev alınır: $g'(x) = a_1 + 2a_2 x + 3a_3 x^2 + \dots$. Burada $a_0$ gider. $x = 0$ koyunca $f'(0) = a_1$ kalır.
- Bir türev daha alınır: $g''(x) = 2\cdot 1\cdot a_2 + 3\cdot 2\cdot a_3 x + 4\cdot 3\cdot a_4 x^2 + \dots$. $x = 0$ koyunca $f''(0) = 2\cdot 1\cdot a_2$ kalır.
- Genelleştirilirse $f^{(n)}(0) = a_n\, n!$, yani $a_n = \dfrac{f^{(n)}(0)}{n!}$.

> **Ders sonrası not:** Hoca birinci türevi yazarken "$2a_1 x + 3a_2 x^2$" dedi; doğrusu $2a_2 x + 3a_3 x^2$. Sonuç $f'(0) = a_1$ değişmez.

Böylece Taylor açılımı elde edilir:

$$f(x) = f(0) + \frac{f'(0)}{1!}x + \frac{f''(0)}{2!}x^2 + \dots = \sum_{n=0}^{\infty}\frac{f^{(n)}(0)}{n!}x^n$$

### 6.2 $e^x$ Açılımından Euler Formülüne

$e^x$'in bütün türevleri yine $e^x$'tir. $x = 0$ konunca her türev 1 olur. Bu yüzden:

$$e^x = 1 + x + \frac{x^2}{2!} + \frac{x^3}{3!} + \dots$$

$x$ yerine $j\theta$ konur ve $j^2 = -1$ kullanılır. $(j\theta)^2 = j^2\theta^2 = -\theta^2$ olur, terimlerin işareti dönüşümlü olarak değişir. Çift kuvvetli terimlerde ($j^2, j^4, j^6$) $j$ kaybolur. Tek kuvvetli terimlerde ($j^1, j^3, j^5$) $j$ kalır ve $j$ parantezine alınabilir. Hoca açılımı burada bıraktı, kosinüs ve sinüs serilerini yazmadı, bu adımı isteyenin kendisinin yapabileceğini söyledi. Adım şöyledir (ara adım eklendi):

$$e^{j\theta} = \underbrace{\left(1 - \frac{\theta^2}{2!} + \frac{\theta^4}{4!} - \dots\right)}_{\cos\theta} + j\underbrace{\left(\theta - \frac{\theta^3}{3!} + \frac{\theta^5}{5!} - \dots\right)}_{\sin\theta}$$

Birinci grup $\cos\theta$'nın, $j$ parantezindeki ikinci grup $\sin\theta$'nın kuvvet serisidir. Python ile hesaplandı: Serinin toplamı, denenen $\theta$ değerlerinde $\cos\theta + j\sin\theta$ ile örtüştü.

## 7. Üç Gösterim, Eksenler Üzerindeki Sayılar ve Eşlenik

### 7.1 Üç Gösterim Bir Arada

Polardan kartezyene geçiş $r(\cos\phi + j\sin\phi)$ idi. Euler formülüyle bu ifade $re^{j\phi}$ olur. Böylece aynı sayının üç gösterimi elde edilir:

$$z = x + jy = r\angle\phi = re^{j\phi}$$

Hoca polar ve üstel gösterimi kabaca eşdeğer saydı, yani temelde iki farklı gösterim vardır. İkisinin varlık sebebi işlem kolaylığıdır.

> **Hocanın vurgusu:** Toplama ve çıkarmada kartezyen gösterimi, çarpma ve bölmede polar ve üstel formu kullanmak mantıklı ve pratiktir.

### 7.2 Eksenler Üzerindeki Sayılar

Sayı yatay eksendeyse $\operatorname{Im}(z) = 0$ olur ve $z = a$ gibi real bir sabittir. Sayı dikey eksendeyse $\operatorname{Re}(z) = 0$ olur ve $z = jb$ biçimindedir. Yatay eksen real sayı doğrusudur. İmajiner eksen eklenince düzlemsel olarak daha büyük bir küme elde edilir.

### 7.3 Karmaşık Eşlenik

Sık karşılaşıldığı için özel bir gösterimi vardır. $z$'nin eşleniği $z^*$ ile gösterilir ve sayının **yatay eksene göre simetriğidir**. Real kısım değişmez, imajiner kısım işaret değiştirir:

$$z = x + jy \quad\Rightarrow\quad z^* = x - jy$$

Hoca iki özel durum sordu:

- $\operatorname{Im}(z) = 0$ ise $z^* = z$. Sayı yatay eksende olduğu için simetriği kendisidir.
- $\operatorname{Re}(z) = 0$ ise $z = jb$, $z^* = -jb$, yani $z^* = -z$.

## 8. Kartezyen Formda Dört İşlem

$X = a + jb$ ve $Y = c + jd$ olsun.

### 8.1 Toplama ve Çıkarma

Sayıları sıralı ikililer gibi düşünürsek aynı sıradaki terimler toplanır ya da çıkarılır:

$$X + Y = (a + c) + j(b + d), \qquad X - Y = (a - c) + j(b - d)$$

Grafik olarak bu, vektörel toplamadır. Bir vektör diğerinin bitiş noktasına kaydırılır, başlangıçtan son bitiş noktasına çizilen vektör toplamı verir. Vektörler de aslında sıralı $n$'lilerdir, bu yüzden hesap aynıdır. Çıkarmada karmaşık sayının eksisini almak, yönünü değiştirmekle eşdeğerdir. Yönü değiştirip toplayınca çıkarma yapılmış olur.

### 8.2 Çarpma

Çarpma, çarpmanın toplama üzerine dağılmasıyla yapılır. Dikkat edilecek nokta $j^2 = -1$ olmasıdır:

$$(a + jb)(c + jd) = ac + jad + jbc + j^2 bd = (ac - bd) + j(ad + bc)$$

Dört çarpma yapıp düzenlemek gerektiği için bu biraz zahmetli bir iştir.

> **Ders sonrası not:** Hoca bu çarpımın iki vektörün vektörel çarpımına denk geldiğini, genliğinin de vektörlerin oluşturduğu alana eşit olduğunu söyledi; doğrusu farklıdır. Karmaşık çarpımın genliği $|X||Y|$, açısı iki açının toplamıdır (bkz. Bölüm 9). Paralelkenar alanını veren vektörel çarpım ise $ad - bc$ değeridir ve $\operatorname{Im}(X^* Y)$'ye eşittir. Python ile hesaplandı: Rastgele sayılarla $|XY| = |X||Y|$ ve $\operatorname{Im}(X^*Y) = ad - bc$ eşitlikleri doğrulandı.

### 8.3 Bölme

Paydayı karmaşık olmaktan kurtarmak için pay ve payda $c - jd$ ile, yani paydanın eşleniğiyle çarpılır. Hoca sınıfa bunun nedenini sordu.

**Soru:** $z$ ile $z^*$ çarpılırsa ne olur? **Cevap:** Real bir sayı çıkar. Bir öğrencinin "$a^2$" yorumuna hoca, biraz daha fazlası olduğunu söyledi:

$$(a + jb)(a - jb) = a^2 - jab + jab - j^2 b^2 = a^2 + b^2$$

> **Ders sonrası not:** Hoca bu işlemde "$j^2$ dediğimiz terim 1" dedi; doğrusu $j^2 = -1$. Sonuç doğrudur, çünkü $-j^2 b^2 = +b^2$ olur.

$a^2 + b^2$, karmaşık sayının uzunluğunun karesidir: $zz^* = |z|^2 = r^2$. Bu yüzden payda eşlenikle çarpılınca geriye real bir sayı kalır ve bölme işleminden kurtuluruz. Bölme için:

$$\frac{a + jb}{c + jd} = \frac{(a + jb)(c - jd)}{c^2 + d^2} = \frac{ac + bd}{c^2 + d^2} + j\,\frac{bc - ad}{c^2 + d^2}$$

Python ile hesaplandı: Çarpma ve bölme formülleri rastgele sayılarla doğrulandı. Görüldüğü gibi bu da karmaşık ve uğraştırıcı bir süreçtir. Polar ve üstel formda çok daha pratiktir.

## 9. Polar Formda Çarpma ve Bölme

Fazör gösterimi $V\angle\phi$ ve $I\angle\theta$ olan iki sayıyı üstel formda yazalım: $Ve^{j\phi}$ ve $Ie^{j\theta}$.

**Çarpma:**

$$Ve^{j\phi}\cdot Ie^{j\theta} = VI\,e^{j(\phi + \theta)} \quad\Rightarrow\quad (V\angle\phi)(I\angle\theta) = VI\angle(\phi + \theta)$$

Genlikler çarpılır, açılar toplanır.

**Bölme:**

$$\frac{Ve^{j\phi}}{Ie^{j\theta}} = \frac{V}{I}\,e^{j(\phi - \theta)} \quad\Rightarrow\quad \frac{V\angle\phi}{I\angle\theta} = \frac{V}{I}\angle(\phi - \theta)$$

Genlikler bölünür, açılar çıkarılır. $e^{j\theta}$ pay kısmına çıkınca $e^{-j\theta}$ olduğu için açı çıkarılır. Kuralın ispatı üstel formdaki bu işlemdir.

### 9.1 Çarpım ve Bölümün Fiziksel Anlamı

Hoca bu iki işlemin fiziksel anlamını sordu. $V$ bir elemanın fazör gerilimi, $I$ de o elemandan geçen fazör akım olsun.

- **Bölüm:** Zaman domeninde gerilim bölü akım dirençti. Fazör uzayında da $V/I$, elemanın fazör uzayındaki direncini verir. Terimler karışmasın diye buna empedans denir.
- **Çarpım:** Hoca önce akım ile gerilimin çarpımının yaklaşık olarak gücü verdiğini söyledi. Fazör uzayındaki kesin tanım Bölüm 11'de, akımın eşleniğiyle verilir.

### 9.2 Uzunluk Üzerine Notlar

$|z|$ her zaman real bir değerdir. Hoca önce "real ve pozitif" dedi, sonra sıfır sayısı için uzunluğun sıfır olabileceğini belirterek "real" demenin daha anlamlı olduğunu söyledi. Uzunluğun karesi, sayının eşleniğiyle çarpımından bulunur. Aynı sonuç grafik yoldan da çıkar: $a = |z|\cos\theta$ ve $b = |z|\sin\theta$ olduğundan $a^2 + b^2 = |z|^2(\cos^2\theta + \sin^2\theta) = |z|^2$ olur.

## 10. Fazör Uzayında Ohm Kanunu

### 10.1 Hatırlatma: Tanım Bağıntıları Sabit Katsayıya Dönüşür

Zaman domeninde verilen bir devrede her kaynak fazör uzayına geçirilir. Direncin değeri fazör uzayında aynı kalır. Endüktans ve kapasitenin zaman domenindeki bağıntıları şöyleydi:

$$i_C(t) = C\frac{dv_C}{dt}, \qquad v_L(t) = L\frac{di_L}{dt}$$

Hoca, nasıl yapıldığını sonraya bırakarak bunların fazör uzayında şu biçimi alacağını söyledi:

$$I_C = A\,V_C, \qquad V_L = B\,I_L$$

Buna göre $V_C/I_C = 1/A$ ve $V_L/I_L = B$ birer sabittir. Hoca önce $V_C/I_C = A$ yazdı, sonra bunu $1/A$ olarak düzeltti. Bu sabitler birer karmaşık sayıdır ve elemanın empedans değeri olarak yazılır. Sonuç olarak fazör uzayında kaynakların yanında yazan karmaşık sayı kaynağın değeridir. Direnç, endüktans ve kapasitenin yanında yazan değer ise o elemanın empedansıdır. Üç eleman için de gerilim bölü akım sabit bir değerdir.

### 10.2 Örnek: Tek Endüktanslı Devre

Bir kaynağa doğrudan bağlı tek bir endüktans var. Değerler $-3\sqrt{3} + j3$ ve $1 + j\sqrt{3}$'tür. Hoca önce birinciyi kaynak gerilimi, ikinciyi endüktansın empedansı $Z_L$ olarak okudu ve akımı istedi. Empedans $Z$ ile gösterilir ve fazör uzayında akıma gösterilen dirençtir, zaman domenindeki dirençle eşdeğer düşünülebilir. Bölme yapılacağı için iki sayı polar forma çevrilir.

**Birinci sayı, $-3\sqrt{3} + j3$:**

- Uzunluk: $r_1 = \sqrt{3^2 + (3\sqrt{3})^2} = \sqrt{9 + 27} = 6$.
- Açı: $\tan^{-1}\left(\dfrac{3}{-3\sqrt{3}}\right)$. Oran büyüklük olarak $1/\sqrt{3}$'tür. $y$ pozitif, $x$ negatif olduğu için sayı ikinci bölgededir. Tanjantı $1/\sqrt{3}$ olan açı $30^\circ$'dir, dolayısıyla $\phi_1 = 150^\circ$.
- Sonuç: $6\angle 150^\circ$.

**İkinci sayı, $1 + j\sqrt{3}$:**

- Uzunluk: $r_2 = \sqrt{1 + 3} = 2$.
- Açı: Birinci bölgede, karşı kenar $\sqrt{3}$, komşu kenar 1. $\phi_2 = 60^\circ$.
- Sonuç: $2\angle 60^\circ$.

**Bölüm:**

$$\frac{6\angle 150^\circ}{2\angle 60^\circ} = 3\angle 90^\circ$$

Python ile hesaplandı: $6\angle 150^\circ$, $2\angle 60^\circ$ ve bölüm olarak $3\angle 90^\circ$ çıktı. Hoca sonucu "akım" olarak yorumlayıp 90 derecelik döndürmeyi açıkladı: Kaynak $\sin(2\pi f t)$ olsaydı akım $\sin(2\pi f t + 90^\circ)$ gibi olurdu, yani giriş gerilimi ile akım arasında 90 derecelik faz farkı olurdu.

### 10.3 Notasyon Kuralı

**Soru:** Büyük $I_L$ ile küçük $i_L$ arasındaki fark nedir? **Cevap:** Zamanla değişen bütün işaretler küçük harfle gösterilir. Küçük $i_L$, örneğin $A\sin(2\pi f t + \phi)$ gibi bir zaman domeni değişkenidir. Büyük $I_L$, $V_s$, $Z_L$ ise fazör karşılıklarıdır.

> **Hocanın vurgusu:** Hep bu şekilde anlaşalım ve siz de bu şekilde uygulayın: Zaman domenindeki değişkenler küçük harfle, fazör uzayındaki değişkenler büyük harfle yazılır.

### 10.4 Gerilimi Akıma Neden Bölüyoruz?

**Soru:** $V_L$'yi $I_L$'ye neden böldük? **Cevap:** Endüktans için zaman domeninde $v_L(t) = L\,di_L(t)/dt$ biliyoruz. Bu denklem fazör uzayına geçirilince $V_L = A\,I_L$ biçimini alır. $A$'nın içinde $L$ ve türevden gelen bir sabit vardır. Bu sabitin ne olduğunu hoca o noktada söylemedi. Böylece diferansiyel tanım bağıntısı, fazör uzayında direnç denklemi gibi lineer bir denkleme dönüşür. Endüktans ve kapasitenin yanında yazan değer, elemanın gerilim bölü akım değeridir.

**Soru:** Slayttaki $A$ ile $I$ eşit mi? **Cevap:** Bu soru üzerine hoca slaydı yeniden okudu ve soruyu farklı okuduğunu fark etti. Slaytta verilen $-3\sqrt{3} + j3$ kaynak gerilimi, $1 + j\sqrt{3}$ ise endüktans kolundaki **akımdır**. Sorulan da $A$ değeri, yani gerilim bölü akımdır. Yapılan bölme işlemi aynı kalır, ama sonuç akım değil empedanstır.

> **Ders sonrası not:** Hoca bölümü önce akım saydı ve kaynak gerilimi ile akım arasında 90 derece fark olduğunu söyledi; doğrusu $3\angle 90^\circ$ empedanstır: $Z_L = V_L/I_L = 3\angle 90^\circ$. 90 derecelik fark, gerilim ($150^\circ$) ile akım ($60^\circ$) arasındadır: $150^\circ - 60^\circ = 90^\circ$. Hocanın ilk yorumu doğru olsaydı bile fark $150^\circ - 90^\circ = 60^\circ$ olurdu. Python ile hesaplandı. Kısa nota göre gerilimin birimi mV, akımın birimi mA'dır. Bu durumda sonuç $3\angle 90^\circ\ \Omega = j3\ \Omega$ olur.

<!-- BELİRSİZ: Örnekteki mV ve mA birimleri altyazıda söylenmiyor, kısa nottan alındı. Slaydın tam soru metni altyazıda okunmuyor. -->

## 11. Fazör Uzayında Güç ve Polar Formda Eşlenik

### 11.1 Güç Tanımı

Bir elemanın fazör uzayındaki gerilim düşümü ve akımı biliniyorsa, elemanın çektiği güç gerilim ile **akımın eşleniğinin** çarpımıdır:

$$S = V\cdot I^*$$

> **Ders sonrası not:** Hoca Bölüm 9'da gücü "$V$ çarpı $I$" olarak andı; doğrusu burada verdiği $V\cdot I^*$ tanımıdır.

Değerler kartezyen formda verilmişse, çarpma yapacağımız için önce fazör gösterimine çevirmekte fayda vardır: uzunluk ve açı bulunur, sonra eşleniği üzerinden işlem yapılır.

### 11.2 Eşleniğin Polar Gösterimi

Hoca sınıfa, $z = r\angle\phi$ ise $z^*$'ın nasıl yazılacağını sordu. $z = a + jb$ için $z^* = a - jb$'dir. Uzunluk değişmez: $\sqrt{a^2 + (-b)^2} = r$. Açı için $\tan^{-1}(-b/a)$ yazılır, yani açının işareti değişir:

$$z = r\angle\phi \quad\Rightarrow\quad z^* = r\angle{-\phi}$$

Slayttaki güç örneğinde de akımın iki bileşeni pozitif olduğu için arktanjantın pozitif çıkması beklenir, ama eşleniğin fazör gösteriminde açı negatif çıkmıştır.

<!-- BELİRSİZ: Slayttaki güç örneğinin sayıları altyazıda okunmuyor. -->

> **Ders sonrası not:** Kısa notta Bölüm 10.2'deki değerlerle şu kontrol yapılır: $S = V_L I_L^* = (6\angle 150^\circ)(2\angle{-60^\circ}) = 12\angle 90^\circ = j12$. Python ile hesaplandı. Birimler kısa nottaki gibi mV ve mA ise sonuç $\mu$VA cinsindendir.

> **Ek bilgi (derste anlatılmadı):** Yukarıdaki sonucun real kısmı sıfırdır. Bu, ideal endüktansın ortalamada güç harcamadığını gösterir. Python ile hesaplandı: Aralarında $90^\circ$ bulunan iki sinüzoidalin çarpımının bir periyottaki ortalaması sıfır çıktı. İmajiner kısma büyük olasılıkla reaktif güç adı verilir.

### 11.3 Soru-Cevap: Hangisi Fazör Gösterimi?

**Soru:** Fazör gösterimi dediğimiz, $e$ üzeri ya da polar biçimde gösterdiğimiz kısım mı? **Cevap:** Hoca üçünü ayırarak yazdı:

- $z = a + jb$: Kartezyen gösterim.
- $z = r\angle\phi$: Fazör gösterim, aynı zamanda polar gösterim olarak da geçer.
- $z = re^{j\phi}$: Üstel gösterim.

Üçü de birbirine eşittir. Geçişler $r = \sqrt{a^2 + b^2}$, $\phi = \tan^{-1}(b/a)$, $a = r\cos\phi$ ve $b = r\sin\phi$ bağıntılarıyla yapılır.

## 12. Sinüzoidal İşaretin Parametreleri

Aranın ardından hoca sinüzoidal işaretin özelliklerine geçti. Sinüzoidal işaret üç özellikle belirlenir. Hoca, frekans sabit tutulduğunda iki serbestlik derecesi kaldığını da belirtti.

$$v(t) = V_m\sin(\omega t + \phi)$$

- **Genlik ($V_m$):** Sinüs $-1$ ile $+1$ arasında dalgalanır. Sabit katsayıyla çarpılınca işaret $-V_m$ ile $V_m$ arasında dalgalanır. Genlik artınca tepe noktalarının salınım aralığı artar.
- **Açısal frekans ($\omega$) ya da frekans ($f$):** $\omega = 2\pi f$. Hangisi kullanılırsa kullanılsın ikinci parametredir. Frekans arttıkça işaretin birim zamandaki sıfır geçişleri artar, yani işaret sıkışır.
- **Faz ($\phi$):** Faz sıfırsa $t = 0$'da $v = 0$ olur. Sinüsün sıfır geçişleri $\pi$'nin tam katlarında olur. Faz sıfırdan farklıysa işaret olduğu gibi sağa ya da sola kayar, sıfır geçişleri $\pi$'nin katlarından ayrılır.

### 12.1 Periyot, Frekans ve Birimler

Periyot $T$, işaretin kendini tekrar etmeye başlama süresidir. Bulmak için işaretin negatiften pozitife geçtiği bir nokta seçilir, aynı biçimde negatiften pozitife geçtiği sonraki nokta aranır. Aradaki süre minimum periyottur. Frekans periyodun tersidir:

$$f = \frac{1}{T}$$

> **Ders sonrası not:** Hoca frekansın "bir periyot boyunca işaretin kaç kere kendini tekrar ettiğini" ifade ettiğini söyledi; doğrusu frekans, birim zamanda (saniyede) işaretin kaç kez tekrar ettiğidir. Bu, hocanın verdiği $f = 1/T$ bağıntısı ve Hz $=$ 1/s birimiyle tutarlıdır.

Birimler şöyledir:

- Periyot saniye cinsindendir, frekans saniye üzeri eksi birdir. Bu birim hertz'dir: Hz $=$ 1/s.
- Açısal frekans radyan bölü saniyedir. $\omega t$ çarpımında radyan/saniye çarpı saniye kalır ve parantez içinde bir açı değeri elde edilir. Bu açının sinüsü hesaplanabilir.
- Faz açısı $\phi$'nin birimi de radyandır.

### 12.2 Radyan ve Derece

Bir tam tur $2\pi$ radyandır ve aynı zamanda 360 derecedir. Dönüşümler bu eşitlikten oran-orantıyla yapılır: $2\pi$ radyan 360 derece ise, $x$ derece kaç radyandır ya da $y$ radyan kaç derecedir, diye sorulur.

## 13. Genlik, Tepeden Tepeye Değer, Ortalama Değer ve RMS

Bir işaretin ne kadar güçlü olduğunu tanımlamak için hoca üç ölçü saydı: genlik, tepeden tepeye değer ve RMS.

### 13.1 Anlık Değer ve Genlik

Anlık değer (instantaneous value), zamana bağlı değişkenin bir $t_0$ anındaki değeridir, yani fonksiyonun o andaki değeridir. Genlik ise $V_m$'dir, yani sinüs teriminin neyle çarpıldığıdır.

### 13.2 Tepeden Tepeye Değer

İşaretin tepeden tepeye kat ettiği mesafe peak-to-peak genliktir:

$$V_{pp} = V_m - (-V_m) = 2V_m$$

Daha genel olarak, üst tepe noktası eksi alt tepe noktasıdır. Bunun önemi şudur: Bazen AC kaynağın üzerine bir DC kaynak biner ve işaretin ortalaması sıfırdan farklı olur. Küçük sinyal AC analizinde ortalamanın anlamı yoktur, yalnız işaretin ne kadarlık bir aralıkta salındığıyla ilgileniriz. Bu durumda tepeden tepeye genlik işe yarar.

### 13.3 Ortalama Değer ve DC Ofset

Sinüzoidal ya da üçgen, kare dalga gibi diğer periyodik işaretlerin periyotları aynı olsa bile etki güçleri farklıdır. Etkiyi ölçmek için hoca sınıfa önce işaretin bir periyottaki ortalamasını sordu:

$$\frac{1}{T}\int_0^T f(t)\,dt$$

**Soru:** Bu integralin değeri nedir? **Cevap:** Sıfırdır. Sinüs işaretinde pozitif alternansın alanı negatif alternansın alanına eşittir, toplayınca sıfır çıkar. Bu yüzden ortalama, işaretin etkinliği açısından bir şey söylemez. Oysa hem pozitif hem negatif alternansın devrede etkisi vardır.

> **Ders sonrası not:** Hoca soruyu genel olarak "periyodik işaret" için sordu ve ortalamanın sıfır olduğunu söyledi; doğrusu bu, hocanın hemen ardından belirttiği gibi saf sinüzoidal için, yani sıfır ortalamalı işaretler için geçerlidir. DC ofsetli işaretin ortalaması aşağıdaki gibi sıfırdan farklıdır.

Üzerine DC bindirilmiş bir işaret ele alalım:

$$v(t) = A + B\sin(\omega t + \phi)$$

İntegralin toplama üzerine dağılmasından:

$$\frac{1}{T}\int_0^T v\,dt = \frac{1}{T}\int_0^T A\,dt + \frac{1}{T}\int_0^T B\sin(\omega t + \phi)\,dt = \frac{A\,T}{T} + 0 = A$$

$A$ terimi işaretin DC ofsetidir. Çizimde işaret $A$ kadar yukarı kayar ve $A$ civarında salınır.

### 13.4 RMS Değer

Alanları toplamak için işaretin karesi alınır, bir periyot boyunca integrali alınır, periyoda bölünür ve kök alınır:

$$V_{\text{rms}} = \sqrt{\frac{1}{T}\int_0^T v^2(t)\,dt}$$

Adı root mean square, kısaca RMS'tir. Hoca aynı değeri bazen işaretin "etkinliği" olarak andı. Hocaya göre kare dalganın sıfır geçiş noktalarında bile tam etkisi vardır, sinüzoidal dalganın etkinliği o kadar değildir. Frekansları eşit olsa bile aradaki farkı bu ölçü ortaya koyar.

Kare alınmasının sebebi, pozitif ve negatif kısımların birbirini götürmesini önlemektir. Hoca mutlak değer gibi başka ölçülerin de olabileceğini söyledi. Kök alınmasının sebebi birimi geri getirmektir: Gerilimin karesi V$^2$, integrali V$^2$s, periyoda bölününce yine V$^2$, kökü V olur. Böylece karşılaştırılabilir bir değer elde edilir.

> **Ek bilgi (derste anlatılmadı):** "Etkin" adı büyük olasılıkla güç eşdeğerliğinden gelir. Bir $R$ direncinde, $V_{\text{rms}}$ değerindeki DC gerilim ile sinüzoidal işaretin ortalama gücü aynıdır. Python ile hesaplandı: $v^2/R$ ortalaması ile $V_{\text{rms}}^2/R$ örtüştü.

### 13.5 Sinüzoidal İşaretin RMS Değeri

$v(t) = V_p\sin\omega t$ olsun.

$$V_{\text{rms}}^2 = \frac{1}{T}\int_0^T V_p^2\sin^2\omega t\,dt$$

Hoca $\sin^2$ için özdeşliği sınıfa sordu.

**Soru:** $\sin^2\omega t$ nasıl yazılır? **Cevap:** Bir öğrenci $\dfrac{1 - \cos 2\omega t}{2}$ dedi. Hoca önce "$1 - \cos^2\omega t$" diye düşünmüştü, doğru özdeşlik öğrencinin söylediğidir.

Özdeşliği $\cos 2a$'dan elde ederiz:

- $\cos 2a = \cos a\cos a - \sin a\sin a = \cos^2 a - \sin^2 a$.
- $\cos^2 a + \sin^2 a = 1$ olduğundan $\cos^2 a$ yerine $1 - \sin^2 a$ yazılır.
- $\cos 2a = 1 - 2\sin^2 a$, yani $\sin^2 a = \dfrac{1 - \cos 2a}{2}$.

Yerine koyalım:

$$V_{\text{rms}}^2 = \frac{V_p^2}{T}\int_0^T\left(\frac{1}{2} - \frac{\cos 2\omega t}{2}\right)dt$$

Kosinüslü terimin integrali için: $\sin 2\omega t$'nin türevi $2\omega\cos 2\omega t$'dir. Bu yüzden integral $\dfrac{\sin 2\omega t}{2\omega}$ olur ve baştaki $1/2$ ile birlikte $\dfrac{1}{4\omega}$ katsayısı gelir. $0$ ile $T$ arasında $\cos 2\omega t$ iki tam periyot yapar, altında kalan net alan sıfırdır. Geriye:

$$\int_0^T\frac{1}{2}\,dt = \frac{T}{2}$$

kalır. O hâlde:

$$V_{\text{rms}}^2 = \frac{1}{T}\,V_p^2\,\frac{T}{2} = \frac{V_p^2}{2} \quad\Rightarrow\quad V_{\text{rms}} = \frac{V_p}{\sqrt{2}}$$

Sinüzoidal bir işaretin RMS değeri, genliğinin $\sqrt{2}$'de biridir.

> **Ders sonrası not:** Hoca $\cos 2\omega t$ için "periyodu artık $2\omega T$" dedi; doğrusu frekans iki katına çıktığı için periyot $T/2$ olur. Aynı anlatımda "$T$ süresinde iki kez tekrar eder" sözü doğrudur.

### 13.6 Şebeke Frekansı

Hoca şehir şebeke geriliminin frekansını hatırlattı.

> **Ders sonrası not:** Hoca "Türkiye ve Avrupa'da 50 Hz, Avrupa'da 60 Hz" dedi; doğrusu büyük olasılıkla Türkiye ve Avrupa'da 50 Hz, ABD ve Kuzey Amerika'da 60 Hz'dir. Kısa notta da düzeltme böyledir.

## 14. Faz Farkı: Önde ve Geride Olan İşaret

### 14.1 Tanım ve Grafik Yorum

Faz açısı, işaretin frekansını ve genliğini bozmadan zaman ekseninde kaydırılmasına karşılık gelir. Aynı frekanslı iki işaret için fazları $\phi_1$ ve $\phi_2$ ise $\phi_1 - \phi_2$ faz farkını verir.

Hoca slaytta üç işaret gösterdi. Mavi işaret sıfır noktasından geçer. Genliği 5, periyodu 500'dür:

$$v_1(t) = 5\sin\left(\frac{2\pi}{500}t\right)$$

Hoca önce "frekansı 500" dedi, hemen "periyodu 500" olarak düzeltti. $t = 500$ konunca açı $2\pi$ olur, yani işaret bir periyodu tamamlar. Yeşil ve kırmızı işaretler aynı genlik ve frekansta, yalnız farklı fazlardadır.

Görsel yol şudur: **Aynı yöndeki sıfır geçişini kim önce yapıyorsa o öndedir.**

- Kırmızı (3) işaret negatiften pozitife geçişi önce yapar. Mavi ve yeşilin önündedir.
- Yeşil (2) işaret mavi ve kırmızıya göre geriden gelir.

Önden gidene **leading**, geriden gelene **lagging** denir.

### 14.2 Sayısal Karşılaştırma

Slaytta fazlar $\phi_1 = 0$, $\phi_2 = -28.8^\circ$ ve $\phi_3 = 14.4^\circ$ olarak verilmiştir. Açısal frekans $\omega = 2\pi/T = 2\pi/500$'dür.

- $\phi_1 - \phi_2 = 0 - (-28.8^\circ) = 28.8^\circ > 0$: İşaret 1, işaret 2'nin önündedir.
- $\phi_1 - \phi_3 = 0 - 14.4^\circ = -14.4^\circ < 0$: İşaret 3, işaret 1'in önündedir.

Slaytta bir de zaman farkları vardı, ama hoca bunları grafikten net göremediğini söyledi. Zaman farkı faz farkından bulunabilir (ara adım eklendi): $\dfrac{28.8}{360}\cdot 500 = 40$ ve $\dfrac{14.4}{360}\cdot 500 = 20$ birim. Python ile hesaplandı.

<!-- BELİRSİZ: Slayttaki zaman farkı değerleri altyazıda okunmuyor. 40 ve 20 birim hesapla ve kısa nottan alındı. -->

### 14.3 Karşılaştırmadan Önce Üç Kural

> **Hocanın vurgusu:** Sinüzoidalleri karşılaştırmadan önce şu üç koşul sağlanmalıdır.

1. Genlikler pozitif olmalı.
2. Fonksiyonlar aynı tipte olmalı: Hepsi sinüs ya da hepsi kosinüs.
3. Faz açısının büyüklüğü $180^\circ$'den küçük olmalı. Değilse trigonometrik dönüşümlerle uygun açıya getirilmeli.

Üçüncü kuralın gerekçesi grafik karşılaştırmadır. Faz $180^\circ$'yi aşarsa bir işaret, diğerinin bir sonraki periyodundaki hâline yaklaşmış olur ve kim önde sorusunu geometrik olarak yorumlamak zorlaşır.

> **Ders sonrası not:** Hoca burada "sıfırla 180 arasına indirmemiz lazım" dedi; doğrusu, dersin ilerisinde kendisinin de söylediği gibi aralık $-180^\circ$ ile $+180^\circ$ arasıdır.

Negatif genlik için hoca $-5\sin\alpha$ örneğini verdi ve $\sin$'in işaret değiştirmesi için içerideki açının negatif alınabileceğini söyledi: $-5\sin\alpha = 5\sin(-\alpha)$.

> **Ders sonrası not:** Hocanın yazdığı eşitlik matematiksel olarak doğrudur, ama $\alpha = \omega t + \phi$ ise $\omega t$'nin önüne eksi gelir ve faz doğrudan okunamaz. Karşılaştırmada kullanışlı biçim, dersin kosinüs örneğindeki gibi $180^\circ$ kaydırmaktır: $-5\sin\alpha = 5\sin(\alpha - 180^\circ)$. Python ile hesaplandı: Bu iki yazım da $-5\sin\alpha$ ile örtüştü.

Açıları kaydırmak için kullanılan özdeşlikleri hoca dik üçgen ve birim çemberden hatırlattı:

- $\cos\alpha = \sin(90^\circ - \alpha)$. Aynı şekilde $\sin\alpha = \cos(90^\circ - \alpha)$.
- $\cos\alpha = \cos(-\alpha)$.
- $\cos(180^\circ - \alpha) = -\cos\alpha$.

İkinci ve üçüncü özdeşlikten $-\cos\alpha = \cos(180^\circ - \alpha) = \cos(\alpha - 180^\circ)$ elde edilir.

<!-- BELİRSİZ: Hocanın 180 artı beta biçimindeki açıyı küçültme anlatımı altyazıda bozuk olduğu için nota alınmadı. -->

### 14.4 Örnek

$$v_1(t) = 6\sin(20t + 40^\circ), \qquad v_2(t) = -4\cos(20t + 20^\circ)$$

Frekanslar eşit olduğu için faz farkı anlamlıdır.

**Kosinüs cinsinden:**

- $v_1$: Sinüsü kosinüse çevirmek için $90^\circ$ çıkarılır. $6\cos(20t + 40^\circ - 90^\circ) = 6\cos(20t - 50^\circ)$.
- $v_2$: Negatif genlik giderilir. $-\cos\alpha = \cos(\alpha - 180^\circ)$ ile $4\cos(20t + 20^\circ - 180^\circ) = 4\cos(20t - 160^\circ)$.
- Koşullar sağlandı: Genlikler pozitif, tipler aynı, fazlar $180^\circ$'den küçük.
- Fark: $-50^\circ - (-160^\circ) = 110^\circ > 0$. $v_1$, $v_2$'nin $110^\circ$ önündedir.

**Sinüs cinsinden:**

- $v_1$ olduğu gibi kalır: $6\sin(20t + 40^\circ)$.
- $v_2$: İşaret değiştirilir, sonra $4\cos(20t - 160^\circ) = 4\sin(20t - 160^\circ + 90^\circ) = 4\sin(20t - 70^\circ)$.
- Fark: $40^\circ - (-70^\circ) = 110^\circ$. Yine $v_1$ öndedir.

Python ile hesaplandı: Bütün yazımlar özgün ifadelerle örtüştü ve fark iki yoldan da $110^\circ$ çıktı.

## 15. Özel Sayıların Fazör Gösterimi

Hoca üç gösterimi ve geçiş bağıntılarını tahtada referans olarak bıraktı, çünkü konunun geri kalanı bunların üzerine kuruludur. Derste asıl kullanılacak gösterim fazör gösterimidir, ama kartezyen ve üstel karşılıkları da bilinmelidir. Örneğin fazör gösterimiyle verilmiş iki gerilim kaynağı seri bağlıysa toplama gerekir, bu durumda fazörler kartezyene çevrilip kolayca toplanır.

> **Hocanın vurgusu:** Bu dönüşümleri yapan programlanabilir hesap makineleri ve web kaynakları kullanılabilir, kısa sınav ve finalde de bunlardan yararlanılabilir. Ama nasıl çalıştıklarını önceden pratik edin. Fazör ve kartezyen gösterim arasında hızlı geçiş yapabilmek önemlidir.

### 15.1 Pozitif Real Sayı

$A > 0$ için sayı pozitif real eksendedir. İmajiner kısmı sıfırdır: $z = A + j0 = A$. Orijinden sayıya çizilen doğru real eksen üzerindedir, açı sıfırdır:

$$z = A\angle 0^\circ$$

### 15.2 Negatif Real Sayı

$B > 0$ için $z = -B + j0 = -B$ olsun. Pozitif real eksenden sayıya kadar olan açı $180^\circ$'dir. Hoca önce "$-B\angle 180^\circ$" yazdı.

**Soru:** $-B$ yazarsak açıya sıfır yazmamız gerekmez mi? **Cevap:** Hoca üstel formdan kontrol etti. $re^{j\theta} = r(\cos\theta + j\sin\theta)$ yazılır. $\sin 180^\circ = 0$ ve $\cos 180^\circ = -1$ olduğundan sonucun $-B$ olması için $r = B$ olmalıdır. Öğrenci haklıdır. Doğru yazım:

$$-B = B\angle 180^\circ = B\angle{-180^\circ}$$

Açı ters yönde ölçülürse $-180^\circ$ olur, iki yazım da aynı sayıdır.

**Soru:** $-B$'yi $-B\angle 0^\circ$ olarak da yazabilir miyiz? **Cevap:** $\cos 0^\circ = 1$, $\sin 0^\circ = 0$ olduğu için değer olarak $-B$ çıkar, yazılabilir. Hoca $-1 = 1\angle 180^\circ$ olduğunu kullanarak bir kontrol de yaptı: $(B\angle 180^\circ)(1\angle 180^\circ) = B\angle 360^\circ = B$, yani $-B$'yi $-1$ ile çarpınca $B$ çıkar.

> **Ders sonrası not:** Hoca $-B\angle 0^\circ$ yazımını kabul etti. Değer olarak doğrudur, ama hocanın kendi kuralına göre uzunluk negatif olmamalıdır, faz karşılaştırmasında da genlik pozitif istenir. Bu yüzden kullanılacak yazım $B\angle\pm 180^\circ$'dir. Python ile hesaplandı: $(B\angle 180^\circ)(1\angle 180^\circ)$ çarpımı $B$ verdi.

### 15.3 Saf İmajiner Sayılar

Hoca önce $i$ diye başlayıp akımla karışmaması için $j$ olarak düzeltti:

- $j = 1\angle 90^\circ$
- $-j = 1\angle{-90^\circ}$
- $jA = A\angle 90^\circ$
- $-jA = A\angle{-90^\circ}$, ya da az önceki gibi $-A\angle 90^\circ$

## 16. Zaman Domeninden Fazöre, Fazörden Zaman Domenine

### 16.1 Fazörden Sinüzoidale

Elimizde genliği $V_m$, açısı $\phi$ olan bir fazör olsun: $V = V_m\angle\phi$. Euler formülüyle:

$$V_m\angle\phi = V_m e^{j\phi} = V_m\cos\phi + jV_m\sin\phi$$

Sinüzoidal kaynaklı devrede geçici rejimler bittikten sonra bütün akım ve gerilimler aynı frekansta dalgalanır. Frekansı baştan bildiğimiz için, açısal frekans $\omega$ da hesaba katılınca fazörün real kısmı alınır:

$$\operatorname{Re}\left\{V_m e^{j(\omega t + \phi)}\right\} = V_m\cos(\omega t + \phi)$$

Dolayısıyla $V_m\cos(\omega t + \phi)$ işaretinin fazör karşılığı $V_m\angle\phi$'dir.

### 16.2 Kosinüs Kabulü

İki alternatif vardır. Kaynak kosinüs biçimindeyse sonucun real kısmı, sinüs biçimindeyse imajiner kısmı alınır. Burada önemli olan bir kabul belirleyip hep ona uymaktır.

> **Hocanın vurgusu:** Kendi aramızda anlaşalım: Bütün kaynakları kosinüse çevirip fazörün hep real kısmını alacağız. Kısa sınav ve finalde cevapları bu şekilde bekliyorum.

### 16.3 İki Yönde Geçiş

**Fazörden zaman domenine:**

- Fazörün genliği, sinüzoidal işaretin genliğidir.
- Real kısım alındığı için fonksiyon kosinüstür.
- Frekans, baştan not edilen kaynak frekansıdır. Çözüm boyunca sonucu değiştirmeyen, keyfi bir değişken gibi kenarda durur.
- Fazörün açısı, işaretin fazıdır.

**Zaman domeninden fazöre:**

- İşaret, faz karşılaştırmasındaki kurallara göre düzenlenir: Genlik pozitif, fonksiyon kosinüs, faz $-180^\circ$ ile $+180^\circ$ arasında.
- Genlik ve açı alınıp fazör yazılır.
- Frekans not edilir: $\omega = 2\pi f$, yani $f = \omega/2\pi$. Hesaplar bitip zaman domenine dönerken yerine konur.

$$V_m\cos(\omega t + \phi) \;\leftrightarrow\; V_m\angle\phi$$

**Sinüsten başlanırsa:** Birim çember ve dik üçgenden $\sin\alpha = -\sin(-\alpha)$ ve $\sin\alpha = \cos(90^\circ - \alpha)$ yazılır. $\alpha = \omega t + \phi$ koyarsak $\cos(90^\circ - \omega t - \phi)$ olur. $\cos\alpha = \cos(-\alpha)$ ile düzenlenince:

$$V_m\sin(\omega t + \phi) = V_m\cos(\omega t + \phi - 90^\circ) \;\to\; V_m\angle(\phi - 90^\circ)$$

Aynı işlemler akım için de geçerlidir.

### 16.4 Örnekler

**Örnek 1:** $3\sin(100t + 20^\circ)$ V.

- Kosinüse çevirmek için $90^\circ$ çıkarılır: $3\cos(100t + 20^\circ - 90^\circ) = 3\cos(100t - 70^\circ)$.
- Genlik aynen kalır. Fazör: $3\angle{-70^\circ}$ V.

**Örnek 2:** $7\sin(350t - 100^\circ)$ A.

- Kosinüse çevirmek için $90^\circ$ çıkarılır: $7\cos(350t - 190^\circ)$.
- $-190^\circ$ aralığın dışındadır. Hoca birim çemberden iki dönüşüm kullandı:
  - $\cos\alpha = -\cos(180^\circ + \alpha)$ ile içeriye $180^\circ$ eklenir, başına eksi konur: $-7\cos(350t - 10^\circ)$.
  - Başta kalan eksi, yine $180^\circ$ kaydırmayla içeri alınır: $-\cos\beta = \cos(\beta + 180^\circ)$. Sonuç $7\cos(350t + 170^\circ)$.
- Genlik pozitif, faz aralıkta. Fazör: $7\angle 170^\circ$ A.
- Frekans not edilir: $\omega = 350$ rad/s. Zaman domenine dönerken $2\pi f$ yerine bu değer konur.

Python ile hesaplandı: İki örnekte de ara ve son yazımlar özgün işaretle örtüştü.

<!-- BELİRSİZ: İki örneğin başlangıç ifadeleri ve birimleri altyazıda tam söylenmiyor, kısa nottan alındı. Altyazıda yalnız 90 derece çıkarma, -70, 7 genliği, -190 ve 170 geçiyor. -->

**Örnek 3 (kartezyenden polara):** $5 + j3$.

- $r = \sqrt{5^2 + 3^2} = \sqrt{25 + 9} = \sqrt{34} \approx 5.83$.
- $\phi = \tan^{-1}(3/5) \approx 31^\circ$.
- Sonuç: $5.83\angle 31^\circ$. Python ile hesaplandı: $5.831\angle 30.96^\circ$.

Hoca bu tablonun diğer satırlarını işlemedi.

> **Ders sonrası not:** Kısa nota göre slayttaki bu tablonun iki satırı hatalıdır, $\tan^{-1}$ sonucunda bölge düzeltmesi yapılmamıştır. Python ile hesaplandı: $-30 + j100 = 104.4\angle 106.7^\circ$ (slaytta $104\angle{-73.3^\circ}$), $-0.4 - j0.25 = 0.472\angle{-148.0^\circ}$ (slaytta $0.472\angle 32.0^\circ$). $75 - j150 = 167.7\angle{-63.4^\circ}$ satırı doğrudur. Bölüm 10.2'deki gibi önce sayının bölgesine bakılmalıdır.

<!-- BELİRSİZ: Slayttaki tablo değerleri altyazıda okunmuyor, kısa nottan alındı. -->

## 17. Özel Fonksiyonlara Kısa Bir Bakış

Hoca, daha önce görülen bazı özel fonksiyonlara kısaca değindi ve üzerinde durmadan geçti. Örneğin slayttaki kare dalga, üç birim basamak fonksiyonunun toplamıyla oluşturuluyordu. Rampa fonksiyonunun tanım bağıntısı ve testere dişi biçimindeki fonksiyonlar için neler yapılacağı ile bunların birbiriyle ilişkisi hatırlatıldı. Hoca bunlara daha sonra dönmek istediğini söyledi.

<!-- BELİRSİZ: Slayttaki kare dalganın biçimi ve üç basamak fonksiyonunun değerleri altyazıda yok. -->

## 18. Sinüzoidal Kaynaklı RL Devresi ve Geçici Hâlin Sönmesi

### 18.1 Diferansiyel Denklem

Geçen haftaki geçici analizin sinüzoidal kaynaktaki karşılığına bakalım. Seri RL devresinde kaynak $V_0\cos\omega t$ olsun. Denklem her tarafı $L$'ye bölünmüş biçimde şöyledir:

$$\frac{di}{dt} + \frac{R}{L}i = \frac{V_0}{L}\cos\omega t$$

Devre RL olduğu için homojen çözüm tek bir üstel terimdir: $Ae^{\alpha t}$. Bu denklemde $\alpha = -R/L$'dir (ara adım eklendi).

### 18.2 Zorlanmış Çözüm Önerisi

Hoca sınıfa, zorlanmış çözüm için en genel öneriyi sordu. Önceki haftalarda kaynak DC olduğu için en genel öneri tek bir sabitti. Şimdi sağ taraf sinüzoidal olduğu için öneri, bir sinüzoidali belirleyen bütün keyfilikleri içermelidir. Bir sinüzoidali üç parametre belirler: genlik, frekans ve faz. Deneysel sonuçlardan biliyoruz ki sürekli hâldeki frekans kaynak frekansıyla aynıdır. Bu yüzden frekans keyfi değildir, geriye iki keyfilik kalır:

$$i_{\text{zorlanmış}}(t) = I_0\cos(\omega t + \theta)$$

Hoca bunu önce $A\cos(\omega t + \phi)$ biçiminde yazdı, slaytta aynı şey $I_0$ ve $\theta$ ile gösterilmiştir.

### 18.3 Katsayıların Bulunması

Öneri denkleme konur (ara adımlar eklendi):

$$-I_0\omega\sin(\omega t + \theta) + \frac{R}{L}I_0\cos(\omega t + \theta) = \frac{V_0}{L}\cos\omega t$$

Toplam açı açılımları yazılır, $\sin\omega t$ ve $\cos\omega t$ katsayıları iki tarafta eşitlenir.

- $\sin\omega t$ katsayısı sıfır olmalıdır: $-\omega\cos\theta - \dfrac{R}{L}\sin\theta = 0$, buradan $\tan\theta = -\dfrac{\omega L}{R}$.
- $\cos\omega t$ katsayısı: $I_0\left(\dfrac{R}{L}\cos\theta - \omega\sin\theta\right) = \dfrac{V_0}{L}$. Burada $\cos\theta = \dfrac{R}{\sqrt{R^2 + \omega^2 L^2}}$ ve $\sin\theta = \dfrac{-\omega L}{\sqrt{R^2 + \omega^2 L^2}}$ konur.

Sonuç:

$$i(t) = \frac{V_0}{\sqrt{R^2 + \omega^2 L^2}}\cos\left(\omega t - \tan^{-1}\frac{\omega L}{R}\right)$$

Kaynakla aynı frekansta, genliği ölçeklenmiş ve fazı kaymış bir işarettir.

> **Ders sonrası not:** Hoca genliği "$V_0$ bölü $R^2 + \omega^2L^2$", fazı "$VL$ bölü $R$'nin tanjant eksi biri" diye okudu; doğrusu yukarıdaki gibi paydada karekök, fazda $-\tan^{-1}(\omega L/R)$'dir. Python ile hesaplandı: Bu çözüm rastgele $R$, $L$, $V_0$, $\omega$ değerlerinde denklemi sağladı. Kısa nottaki sayısal çözüm karşılaştırması ($R = 10\ \Omega$, $L = 50$ mH, $V_0 = 5$ V, $f = 50$ Hz) da yinelendi ve geçici hâl söndükten sonra formülle örtüştü.

### 18.4 Simülasyon Grafikleri

Hoca bu çözümü, homojen kısmın etkisini göstermek için yaptığını söyledi. Slaytlarda simülasyon ortamında kurulan devrelerin giriş ve çıkış grafikleri vardı.

- **RL devresi, $i_L$ çıkışı:** Homojen çözümden gelen $Ae^{\alpha t}$ terimi bir süre etkili olur, sonra kaybolur. Pratikte yaklaşık $5\tau$ sonra ihmal edilebilir. Geriye baskın olarak sinüzoidal kaynağın etkisi kalır.
- **RC devresi, kapasite gerilimi:** Geçici hâl yaklaşık $5\tau$ etkili olur, sonra kaybolur.
- **Paralel RLC devresi, kapasite gerilimi:** Geçici hâl süresi bittikten sonra üstel terimlerin etkisi kaybolur ve yalnız kaynağın baskın sürdüğü durum kalır.

Zaman domeninde çözüm yaparken bunun tamamıyla ilgilenmiştik, ama özel durumlara bakmıştık: Kaynak bir $t_0$ anında devreden çıkıyor ya da devreye giriyor, $t \to \infty$ iken bir DC değere asimptotik olarak yaklaşıyorduk. Sinüzoidal zorlayıcı kaynakta ise belirli bir süre sonra kaynakla aynı frekansta salınım görülür. Fazör yöntemi bu kısmı hesaplar.

## 19. R, L ve C'nin Fazör Uzayındaki Tanım Bağıntıları

Dersin sonunda süre yetmediği için hoca bu konuya kısaca değindi. Ayrıntılar önümüzdeki hafta anlatılacak.

| Eleman | Zaman domeni | Fazör uzayı |
|---|---|---|
| Direnç | $v = Ri$ (doğru orantı) | $V = RI$ |
| Endüktans | $v = L\,di/dt$ | $V = j\omega L\,I$ |
| Kapasite | $i = C\,dv/dt$ | $I = j\omega C\,V$ |

Bölüm 10.1'deki bilinmeyen sabitlerin karşılığı artık görülüyor: $B = j\omega L$ ve $A = j\omega C$. Gerilim ve akım arasındaki ilişki sabit orantılı hâle gelmiştir.

## 20. Laboratuvar Oturumundan Akademik Notlar

Dersin ardından yapılan laboratuvar oturumunun büyük bölümü idari konulardır ve buraya alınmadı. Asistanın anlattığı akademik kısımlar şunlardır.

**Endüktif reaktans:** Asistan $X_L = 2\pi f L$ formülünü verdi. $f$ frekans, $L$ endüktanstır. Hesap bu çarpımdan ibarettir. Asistan, $R$'nin yatay, $X_L$'nin yukarı doğru, $X_C$'nin aşağı doğru birer vektör olarak gösterildiğini de söyledi. Öğrenciler bunun derste henüz anlatılmadığını belirtti.

**Proteus'ta AC kaynak:** Bileşen seçme bölümünde "source" aratılır ve sinüzoidal kaynak (altyazıda "V-Syn") seçilir. Kaynağın ayarlarında DC değeri sıfır yapılır, genlik ve frekans girilir. Asistanın gösterdiği örnek değerler 5 V ve 100 Hz'dir. Gerilim ölçümünde AC voltmetre kullanılır.

<!-- BELİRSİZ: Ekran paylaşımındaki Proteus menü adları altyazıda tam okunmuyor. "V-Syn" bileşen adının yazımı doğrulanamadı. -->

Laboratuvar sorusu oturum sırasında AC kaynaktan DC kaynağa çevrildi. Bu yüzden Proteus anlatımı o oturumun çözümünde gerekli kalmadı.

## Dersin Toparlaması

Bu derste kaynak sinüzoidal olduğunda neden fazör uzayına geçtiğimizi ve bunun için gereken matematiği gördük. Sinüzoidal kaynaklı bir devrede geçici hâl yaklaşık $5\tau$ içinde söner ve bütün büyüklükler kaynak frekansında salınır. Frekans ayrılınca geriye genlik ve faz kalır. Bu ikisi bir karmaşık sayıyla gösterilir ve diferansiyel denklemler lineer denklemlere dönüşür. Karmaşık sayının kartezyen, polar ve üstel gösterimlerini, toplama ve çıkarmanın kartezyende, çarpma ve bölmenin polarda kolay olduğunu, empedansın $Z = V/I$, gücün $S = V I^*$ olduğunu öğrendik. Sinüzoidal işaretin genliğini, frekansını, fazını, tepeden tepeye değerini, ortalamasını ve RMS değerini tanımladık. Faz karşılaştırmasının üç koşulunu ve "kosinüse çevir, real kısmı al" kabulünü yerleştirdik.

RL devresinin zaman domeni çözümü, fazör yönteminin neyi hesapladığını gösterdi: Üstel terim söndükten sonraki, kaynakla aynı frekanstaki çözümü. Ders, R, L ve C'nin fazör bağıntılarının kısaca verilmesiyle bitti. $V = j\omega L\,I$ ve $I = j\omega C\,V$ bağıntılarının nasıl çıktığı ve eksik kalan kısımlar önümüzdeki hafta tamamlanacak, sonra bu araçlar devre çözümünde kullanılacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
