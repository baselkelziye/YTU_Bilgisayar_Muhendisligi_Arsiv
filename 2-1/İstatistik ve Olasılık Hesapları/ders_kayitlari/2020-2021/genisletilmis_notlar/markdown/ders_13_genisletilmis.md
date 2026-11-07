# Ders 13 Genişletilmiş Notu: Standart Hatanın Tahmini ve Güven Aralıkları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Parametre Tahmini
- 2. Standart Hatanın Tahmini
- 3. Güven Aralıkları
- 4. Normal Dağılan Tahmin Edici İçin Güven Aralığı
- 5. Örnek: Popülasyon Ortalaması İçin Güven Aralığı
- 6. İstatistiğin Önemi ve Kitap Önerisi

## 1. Önceki Dersin Tekrarı: Parametre Tahmini

Hoca derse, önceki derste gördüğümüz parametre tahminini Türkçe olarak özetleyerek başladı. Yeni konulara ise İngilizce devam etti.

### 1.1 Parametre Nedir, Neden Tahmin Edilir?

Elinizde bir veri, yani bir örneklem (sample) olduğunu düşünün. Bu verinin histogramını çizdiğinizde üstel (exponential) dağılıma benzediğini görüyorsunuz. Bu durumda "bu veri üstel dağılımdan geliyor" diyebilirsiniz, ama hangi üstel dağılımdan? Çünkü $\lambda$ değiştikçe farklı üstel dağılımlar elde ederiz.

$\lambda$'yı bulursak verinin hangi üstel dağılımdan geldiğini de bulmuş oluruz. Bu sayede buna benzeyen yeni veriler üretebilir veya başka işler yapabiliriz. Buradaki $\lambda$'ya parametre, onu bulma işine de parametre tahmini (parameter estimation) denir. İki yöntem görmüştük: momentler yöntemi (method of moments) ve en çok olabilirlik yöntemi (method of maximum likelihood).

### 1.2 Momentler

Momentler yönteminden önce momenti tanımlamıştık. $X^k$'nın beklenen değeri $k$ numaralı momenttir. Buna $k$ numaralı popülasyon momenti de denir. Aynı büyüklüğün veriden hesaplanan karşılığı ise $k$ numaralı örneklem momentidir (sample moment):

$$\mu_k = E[X^k], \qquad m_k = \frac{1}{n}\sum_{i=1}^{n} x_i^k$$

Hocanın dikkat çektiği fark şudur: Popülasyon momenti size bir denklem verir, çünkü içinde parametreler vardır. Örneklem momenti ise, veri noktalarını yerine yazdığınızda, bir sayı verir.

Bir de merkezi momentler (central moments) vardır. Bunlarda doğrudan $X^k$'ya bakılmaz, önce merkez yani ortalama çıkarılır. Böylece dağılımın ortalaması sıfıra çekilmiş olur. Örneklem tarafında $x_i$'lerden popülasyon ortalaması değil, örneklem ortalaması çıkarılır; farkın $k$. kuvveti alınıp toplanır ve $n$'e bölünür:

$$\mu'_k = E\big[(X-\mu)^k\big], \qquad m'_k = \frac{1}{n}\sum_{i=1}^{n} (x_i-\bar{x})^k$$

> **Ders sonrası not:** Hoca $E[(X-\mu)^k]$ için altyazıda "$k$ numaralı population moment" dedi; doğrusu $k$ numaralı popülasyon **merkezi** momentidir.

Bu momentlerden ikisini zaten tanıyoruz: Birinci popülasyon momenti ortalamadır (mean), ikinci merkezi moment ise varyanstır (variance). Gördüğümüz dağılımların çoğunda ortalamayı ve varyansı hesaplamıştık. Dolayısıyla elimizde hazır iki denklem vardır.

### 1.3 Momentler Yöntemi

Yöntem şöyle çalışır:

1. Popülasyon momentleri ile örneklem momentleri eşitlenir: popülasyon momenti = örneklem momenti.
2. Bu eşitliklerden istenildiği kadar yazılabilir, çünkü sonsuz sayıda moment vardır. Kaç denklem lazımsa o kadar eşitlik alınır.
3. Eşitlikler bilinmeyenler için çözülür.

**Örnek (gama dağılımı).** Çok basit bir örneklemin gama (gamma) dağılımından geldiği varsayılmıştı. Hangi gama dağılımından geldiğini bulmak için dağılımın iki parametresi olan $\alpha$ ve $\lambda$'yı bulmamız gerekir. Gama dağılımının karmaşık bir denklemi vardır, ama burada ona ihtiyaç duymayız. En kolayı $\mu_1 = m_1$ eşitliğini kullanmaktır, çünkü $\mu_1$ zaten beklenen değerdir. İkinci denklem için ikinci merkezi moment yani varyans kullanılır:

$$E[X] = \frac{\alpha}{\lambda}, \qquad \mathrm{Var}(X) = \frac{\alpha}{\lambda^2}$$

Örneklem momentleri doğrudan hesaplanır. Birinci örneklem momenti $4$, ikinci örneklem merkezi momenti $8/3$ çıkmıştı. İki bilinmeyen olduğu için iki denklem kullanılır:

$$\frac{\alpha}{\lambda} = 4, \qquad \frac{\alpha}{\lambda^2} = \frac{8}{3}$$

<!-- BELİRSİZ: Örneklemin kendisi slaytta kalmış, altyazıda geçmiyor. Yalnız 4 ve 8/3 değerleri söyleniyor. -->

Bu sayıların çözümü altyazıda söylenmiyor, adımlar şöyledir (ara adım eklendi). Birinci denklemi ikinciye bölersek $\lambda$ kalır, sonra $\alpha$ birinci denklemden gelir:

$$\hat{\lambda} = \frac{4}{8/3} = \frac{3}{2}, \qquad \hat{\alpha} = 4\,\hat{\lambda} = 6$$

Kontrol: $6/(3/2) = 4$ ve $6/(3/2)^2 = 8/3$. Bu değerler python ile hesaplandı.

Hoca ardından sonucu genel bir formül olarak gösterdi. Bu ifadede örneklem ortalaması, örneklem varyansı, $n$ ve $n-1$ yer alıyordu. Yani elinizde herhangi bir veri varsa bu değerleri yerine koyarak gama dağılımının $\lambda$ parametresini bulabilirsiniz. $\lambda$ bulunduktan sonra $\alpha$'yı bulmak zor değildir, denklemlerden biri yeterlidir.

Formül altyazıda okunmuyor, ama söylenen terimlerle şöyle kurulur (ara adım eklendi). İkinci örneklem merkezi momenti $m'_2 = \frac{n-1}{n}s^2$ olduğu için:

$$\hat{\lambda} = \frac{\bar{x}}{m'_2} = \frac{n\,\bar{x}}{(n-1)\,s^2}, \qquad \hat{\alpha} = \hat{\lambda}\,\bar{x}$$

<!-- BELİRSİZ: Slayttaki formülün tam yazımı altyazıda yok; 00:12:37-00:14:10 arası bozuk. Yukarıdaki biçim, sayılan terimlerden kuruldu. -->

### 1.4 En Çok Olabilirlik Yöntemi

Bu yöntemin mantığı, olabilirliği (likelihood) maksimize eden parametreleri bulmaktır. Olabilirlik, elimizdeki verinin olasılığıdır. Diyelim ki örneklem olarak $3, 5, 6$ var. O zaman $P(X_1 = 3, X_2 = 5, X_3 = 6)$ olasılığını düşünürüz ve bu olasılığı maksimize eden parametreleri ararız.

Maksimum bulmayı matematik derslerinden biliyorsunuz: Analitik olarak türev alıp sıfıra eşitlenir. Analitik olarak çözemiyorsanız iteratif yöntemler uygulanabilir. Bu durumda problem ayrı bir optimizasyon problemine dönüşür ve gradient descent gibi yöntemler kullanmanız gerekebilir. Optimizasyon başlı başına büyük bir ders ve konudur. Biz burada analitik çözümün olduğunu varsayacağız.

**Bağımsızlık.** Bulduğumuz örnekler birbirinden bağımsızsa, yani birinin $3$ gelmesi diğerinin $5$ gelme şansını değiştirmiyorsa, ortak olasılık tek tek olasılıkların çarpımına dönüşür. Bu çarpım büyük pi ($\prod$) simgesiyle yazılır:

$$L(\theta) = \prod_{i=1}^{n} P(x_i;\theta)$$

<!-- BELİRSİZ: 00:18:04-00:19:22 arası bozuk (uzun döngü). Hoca kesikli ve sürekli durumu ayırıyor; sürekli durumun yazımı altyazıda okunmuyor. Çarpım gösterimi "big P" ifadesinden ve bağımsızlık anlatımından kuruldu. -->

**Logaritma alma hilesi.** Bu çarpım doğrudan maksimize edilmez, çünkü karmaşık bir ifadedir ve çok fazla çarpım terimi olduğu için analitik türev almak zordur. Bunun yerine logaritması alınır. Toplam terimlerinin türevi ayrı ayrı alınabildiği için daha basit türevlerle karşılaşırız. Türevi sıfıra eşitleyerek elde edilen çözümler, logaritma almadan elde edilecek çözümlerle aynıdır. Yani olabilirliğin maksimum olduğu yerleri bulmak için log-olabilirliğin (log-likelihood) maksimum olduğu yerleri buluruz.

> **Ek bilgi (derste anlatılmadı):** Hocanın 00:20:35'teki bozuk cümlesinde büyük olasılıkla çözümlerin neden aynı çıktığı anlatılıyor: Logaritma kesin artan bir fonksiyon olduğundan, $L$ ile $\ln L$ aynı noktada en büyük değerini alır. Sürekli dağılımlarda çarpım büyük olasılıkla olasılıklarla değil, olasılık yoğunluk fonksiyonu değerleriyle yazılır.

> **Hocanın vurgusu:** Optimizasyonda maksimumların yanında sınır noktalarını (boundary points) da göz önünde bulundurmamız gerekir.

Türevin sıfır olduğu noktalar her zaman maksimum değildir. Bazen minimum, bazen de dönüm noktası (inflection point) olabilir. Ayrıca aranan maksimum, aralığın ucunda da çıkabilir.

<!-- BELİRSİZ: 00:21:14-00:22:17 arası bozuk çevrilmiş. Sınır noktası ve dönüm noktası anlatımı yalnızca parçalardan anlaşılıyor. -->

**Örnek (Poisson dağılımı).** Çok basit bir veri verilmişti: $6, 4, 2$ gibi. Veri Poisson dağılımından geliyor ve $\lambda$ parametresini tahmin etmeye çalışıyoruz. Tahmin olduğu için de $\lambda$'nın üstüne şapka koyuyoruz. Poisson'un denklemi şudur:

$$P(x) = \frac{e^{-\lambda}\lambda^{x}}{x!}$$

> **Ders sonrası not:** Altyazıda paydanın "lambda bölü x faktöriyel" diye okunduğu yer var; doğrusu payda yalnız $x!$'dir. Dersin devamında (00:28:58) hoca denklemi de bu biçimde söylüyor.

Yapılacak iş, olabilirliğin logaritmasını alıp maksimize eden $\hat{\lambda}$'yı bulmaktır. Hoca çözümü derste bitirmedi, "artık çok zor değil" diyerek alıştırma olarak bıraktı. Sonucun örneklem ortalaması çıkacağını ise hemen sonra (00:30:01) söyledi. Adımlar şöyledir (ara adım eklendi):

$$\ln L(\lambda) = \sum_{i=1}^{n}\big(-\lambda + x_i\ln\lambda - \ln x_i!\big)$$

$$\frac{d}{d\lambda}\ln L = -n + \frac{1}{\lambda}\sum_{i=1}^{n}x_i = 0 \quad\Longrightarrow\quad \hat{\lambda} = \frac{1}{n}\sum_{i=1}^{n}x_i = \bar{x}$$

Verilen $6, 4, 2$ için sonuç $\hat{\lambda} = (6+4+2)/3 = 4$ olur. Bu değer python ile hesaplandı; $\ln L$ sayısal olarak taranınca da maksimum $\lambda = 4$ civarında çıktı.

<!-- BELİRSİZ: Altyazıda veri "6, 4, 2, like this" diye geçiyor. Slayttaki veri bu üç sayıdan uzun olabilir. Yukarıdaki sayısal sonuç yalnız bu üç sayı içindir. -->

## 2. Standart Hatanın Tahmini

### 2.1 Tahminimiz Ne Kadar İyi?

Diyelim ki bir tahmin bulduk, örneğin $\hat{\theta}$. Akla gelen ilk soru şudur: Bu tahmin ne kadar iyi? İyi bir tahmin ediciden (estimator) beklediğimiz özellikleri hoca şöyle sıraladı:

- Yansız (unbiased) olmalı.
- Tutarlı (consistent) olmalı.
- Asimptotik normal (asymptotically normal) olmalı.
- Standart hatası (standard error) düşük olmalı.

Standart hata, tahmin edicinin standart sapmasından başka bir şey değildir. Yani düşük standart hata istemek, tahmin edicimizin standart sapmasının düşük olmasını istemek demektir.

> **Ders sonrası not:** Altyazıda bir yerde "no standard error" geçiyor. Hemen ardından "low standard error" dendiği için doğrusu "düşük standart hata"dır. Büyük olasılıkla bu bir ses tanıma hatasıdır.

Peki bu standart hatalar nasıl hesaplanır? Artık elimizde veri var ve standart sapmanın tahmini örneklem standart sapmasıdır. Dolayısıyla tahmin edicinin standart sapmasını da veriden tahmin edebiliriz.

### 2.2 Örnek: Poisson Dağılımında $\hat{\lambda}$'nın Standart Hatası

Poisson dağılımında çalıştığımızı varsayalım. Olasılık kütle fonksiyonu (probability mass function) şöyledir:

$$P(x) = \frac{e^{-\lambda}\lambda^{x}}{x!}, \qquad x = 0, 1, 2, \ldots$$

Bu dağılımda hem beklenen değer hem varyans $\lambda$'dır: $E[X] = \lambda$ ve $\mathrm{Var}(X) = \lambda$.

> **Ders sonrası not:** Altyazıda "expected value of lambda" ve "variance of lambda" geçiyor; doğrusu $X$'in beklenen değeri ve varyansıdır.

Momentler yöntemi veya en çok olabilirlikle $\lambda$ için bir tahmin bulduğumuzu düşünelim. Bir önceki bölümde yarım kalan örneğin sonucu, $\lambda$'nın tahmininin örneklem ortalaması olduğudur:

$$\hat{\lambda} = \bar{X}$$

Bu tahmin edici ne kadar iyi? Bunun için standart hatasını bulmamız gerekir. Örneklem ortalamasını konuşurken bunun için zaten bir ifade bulmuştuk:

$$\mathrm{SE}(\bar{X}) = \sigma(\bar{X}) = \frac{\sigma}{\sqrt{n}}$$

Burada $n$ örneklemdeki birim sayısı, $\sigma$ ise popülasyon standart sapmasıdır. İfadenin hâlâ sorunlu bir yanı vardır: $n$'i biliyoruz, ama $\sigma$'yı bilebilir de bilmeyebiliriz de. Buradan farklı yollarla devam edilebilir.

**$\sigma$ biliniyorsa.** Bir şekilde biliyorsak doğrudan kullanırız.

**$\sigma$ bilinmiyorsa, genel yol.** $\sigma$'yı da veriden tahmin ederiz. Yerine, veriden hesaplayabildiğimiz örneklem standart sapması $s$ konur. Böylece bütün ifade veriden hesaplanabilir hale gelir:

$$\widehat{\mathrm{SE}}(\bar{X}) = \frac{s}{\sqrt{n}}$$

> **Ders sonrası not:** Hoca bu ifadeyi 00:35:25'te "$s$ bölü $n$" diye söyledi; doğrusu $s/\sqrt{n}$'dir. Hocanın kendisinin 00:32:36'da verdiği $\sigma/\sqrt{n}$ ifadesi de bunu gösteriyor.

**$\sigma$ bilinmiyorsa, Poisson'a özel yol.** Poisson dağılımında varyansın $\lambda$ olduğu bilgisini kullanabiliriz. Standart sapma varyansın karekökü olduğu için $\sigma$ yerine $\sqrt{\lambda}$ yazılır, paydadaki $\sqrt{n}$ aynen kalır. Hâlâ işimiz bitmedi, çünkü $\lambda$'yı da tahmin ediyoruz. Ama elimizde onun tahmini var: örneklem ortalaması. Onu yerine koyunca şunu buluruz:

$$\widehat{\mathrm{SE}}(\bar{X}) = \frac{\sqrt{\bar{X}}}{\sqrt{n}}$$

Böylece örneklem ortalamasının standart sapması için iki farklı tahminimiz olur. Tahminlerde böyle farklı yolların olması olağan bir durumdur. Hoca hangisinin daha iyi olduğundan emin olmadığını söyledi. Bildiği şey, en az iki farklı tahmin olduğuydu:

- $s/\sqrt{n}$ daha geneldir.
- $\sqrt{\bar{X}}/\sqrt{n}$ Poisson dağılımına özeldir, çünkü varyansın $\lambda$'ya eşit olduğu bilgisini kullanır.

Hangisinin seçileceği, bu tür bir problemde ne bildiğinize ve hangi dağılımla çalıştığınıza bağlıdır.

### 2.3 Bootstrap

Standart hatayı bulmanın başka bir yolu da bootstrap (bootstrapping) yöntemidir. Bugün dönemin son dersi olduğu için bu yönteme bakılmadı. İlgilenenler kitaptaki ilgili bölüme bakabilir.

<!-- BELİRSİZ: Bootstrap bölümü altyazıda "chapter 10.33" diye geçiyor. Büyük olasılıkla 10.3.3 kastediliyor; kitabın içindekilerinden kontrol edin. -->

Bu noktayla parametre tahmini bitmiş oldu. Sıradaki konu güven aralıklarıdır.

## 3. Güven Aralıkları

### 3.1 Nokta Tahmininin Sınırı

Tahminimizin iyiliğini şimdiye kadar standart hatayla, yani tahmin edicinin standart sapmasıyla konuşmaya çalıştık. Güvenimizi ifade etmenin başka bir yolu da güven aralığı (confidence interval) kurmaktır.

Aralık kurabilirsek olasılıklardan söz edebiliriz. Çünkü sürekli bir dağılımda tek bir noktanın olasılığı nedir? Sıfırdır. Bu yüzden tek bir noktayla çalışırken güvenimizi olasılıkla ifade edemeyiz. En çok olabilirlik tahmin edicisi ve momentler tahmin edicisi bu türdendir. Bunlara nokta tahmin edicileri (point estimators) denir, çünkü bize yalnızca bir nokta, tek bir sayı verirler.

Oysa bir $a$ sayısı ve bir $b$ sayısı yazıp "parametrenin $a$ ile $b$ arasında olma olasılığı şudur" diyebilirsek, bu olasılık sıfırdan farklı olur, çünkü artık sıfırdan farklı bir alanımız vardır. Örneğin $[a, b]$ için "%55 olasılıklı aralık" diyebiliriz. Böylece güvenimizi olasılıklarla sayısal olarak ifade etmiş oluruz.

### 3.2 Önce Olasılık, Sonra Aralık

Amacımız $a$ ve $b$'yi bulmaktır, ama sıra şöyledir: Önce istediğimiz olasılığı belirleriz, sonra bu olasılığı veren $a$ ve $b$'yi ararız.

- $\theta$'nın %99 olasılıkla bir aralıkta olduğundan emin olmak istiyorsak $a$ ve $b$ iki yana doğru açılır, alan büyür.
- %65 gibi bir olasılık yeterliyse aralık çok daha küçük olabilir.

Kitap bu olasılığı $1-\alpha$ ile gösterir. Hoca bunun biraz garip göründüğünü, "neden doğrudan $\alpha$ demiyoruz?" diye düşünebileceğinizi söyledi. Kitabın ilerleyen bölümlerinde burada $\alpha$ kullanılması daha açık bir anlatım sağlar. Bu yüzden burada işler biraz karmaşık görünür.

### 3.3 Tanım

Şöyle tanımlanır: Eğer

$$P(a \le \theta \le b) = 1-\alpha$$

ise $[a, b]$ aralığına $\theta$ için $(1-\alpha)\times 100\%$'lük güven aralığı denir.

Tanımı okuyunca biraz kafa karıştırıcı gelebilir, bu yüzden hoca bir örnek yazdı. Diyelim ki

$$P(1.2 \le \theta \le 1.6) = 0.95$$

Burada $1-\alpha = 0.95$, yani $\alpha = 0.05$'tir. $0.95$'i yüzle çarpıp yüzde olarak yazarsak $[1.2,\ 1.6]$ aralığı $\theta$ için %95'lik bir güven aralığıdır.

$1-\alpha$ değerine güven düzeyi (confidence level) veya kapsama düzeyi (coverage level) denir. Bu aralığa ne kadar güvendiğimizi bu değer belirler. Güvenimizi %95, %50, %99 gibi bir olasılıkla söyleyebildiğimiz için bu, nokta tahmininden daha iyidir.

> **Ek bilgi (derste anlatılmadı):** Dersteki tanımda $\theta$ rastgele bir büyüklük gibi yazılıyor. Klasik yorumda büyük olasılıkla şöyle düşünülür: $\theta$ sabit bir sayıdır, rastgele olan veriye bağlı $a$ ve $b$ uçlarıdır. O zaman "%95" ifadesi, bu yöntemle kurulan aralıkların yaklaşık %95'inin $\theta$'yı içermesi demektir.

### 3.4 İyi Aralık Nasıl Olmalı?

Soru şudur: İstenen bir olasılık için, örneğin %95 güven aralığı için, iyi bir aralık nasıl bulunur?

Önce şuna dikkat edin: Aslında sonsuz sayıda farklı aralık vardır. $\theta$ için bir dağılım çizdiğinizi düşünün. Bir bölgeyi seçip "bu alanın olasılığı $0.85$" diyebilirsiniz. Başka bir yerdeki bir bölgenin alanı da $0.85$ olabilir. Yani aynı grafikte alanı $0.85$ olan farklı bölgeler bulunabilir.

İstediğimiz şey, aralığın mümkün olduğunca küçük olmasıdır. Çünkü bir tahmin bulmaya çalışıyoruz ve aralık ne kadar küçükse tahminimiz o kadar kesindir. Olasılık genellikle ortalama etrafında yüksek olduğu için aralığımız da büyük olasılıkla ortalamanın çevresinde olacaktır.

## 4. Normal Dağılan Tahmin Edici İçin Güven Aralığı

### 4.1 Varsayımlar

Tahmin edicimizin normal dağıldığını, daha doğrusu asimptotik normal olduğunu varsayıyoruz. İyi bir tahmin edicinin asimptotik normal olması gerektiğini daha önce konuşmuştuk. Ayrıca tahmin edicinin yansız olduğunu da varsayıyoruz:

$$E[\hat{\theta}] = \theta$$

> **Ders sonrası not:** Hoca yansızlığı önce "beklenen değeri popülasyon ortalamasıdır" diye ifade etti; doğrusu popülasyon parametresi $\theta$'dır. Hoca 01:13:53'te bunu "population parameter itself" diye doğru söylüyor.

### 4.2 Standartlaştırma

Dağılım normal olduğu için standartlaştırırsak standart normal dağılım elde ederiz. Standartlaştırmak için beklenen değeri çıkarır, standart sapmaya böleriz. Beklenen değer yansızlıktan dolayı $\theta$ olduğundan:

$$Z = \frac{\hat{\theta} - \theta}{\sigma(\hat{\theta})}$$

> **Ders sonrası not:** Hoca önce "varyansına böl" dedi, hemen ardından "standart sapma" diye kendisi düzeltti. Doğrusu standart sapmaya bölmektir.

$Z$ standart normal dağılır: ortalaması $0$, standart sapması ve varyansı $1$'dir. Olasılık yoğunluk fonksiyonunu çizersek ortalaması sıfırda olan bilindik çan eğrisini görürüz.

### 4.3 Aranan Bölge

Bu dağılımda alanı $1-\alpha$ olan bir bölge arıyoruz. Bu tür bölgelerden çok sayıda vardır. En iyisi ortalama etrafında toplanmış olandır. Normal dağılım simetrik olduğu için bu bölge de simetrik olur, yani ortalamanın sağındaki ve solundaki uzunluklar eşittir. Ortalamanın iki yanındaki parçaların her birinin alanı $(1-\alpha)$'nın yarısıdır.

Kuyruklara ne kalır? Ortada $1-\alpha$ varsa kuyruklara $1-(1-\alpha) = \alpha$ kalır. İki kuyruk olduğu için bu alan ikiye bölünür:

- Sol kuyruğun olasılığı $\alpha/2$'dir.
- Sağ kuyruğun olasılığı $\alpha/2$'dir.

### 4.4 Sınırlar: Kantiller

Sol sınır, kümülatif dağılım değeri $\alpha/2$ olan noktadır, yani $\alpha/2$'nci kantildir (quantile): $q_{\alpha/2}$. Bu değerler herhangi bir olasılık kitabında bulunabilir. Sağ sınırın kümülatif değeri ise $\alpha/2 + (1-\alpha) = 1-\alpha/2$'dir. Ama simetriden dolayı sağ sınır için $q_{1-\alpha/2}$ yerine $-q_{\alpha/2}$ kullanacağız.

**Örnek ($\alpha = 0.05$).** Sol sınır $q_{0.025}$, sağ sınır ise $0.025 + 0.95 = 0.975$ olduğu için $q_{0.975}$'tir. Olasılık kitaplarına bakarsanız bu değerin $-q_{0.025}$ ile aynı olduğunu görürsünüz. Python ile hesaplandı: $q_{0.025} = -1.9600$, $q_{0.975} = 1.9600$. Böylece iki ayrı kantil düşünmek yerine tek bir $q_{\alpha/2}$ ile çalışmak kolaylaşır.

> **Ders sonrası not:** Altyazıda "0.025 plus 0.59" ve "Q 0.09075" geçiyor; doğrusu $0.025 + 0.95 = 0.975$ ve $q_{0.975}$'tir (python ile hesaplandı). Bu yazımlar büyük olasılıkla ses tanıma hatasıdır.

### 4.5 Formülün Çıkarılması

Olasılığı artık yazabiliriz:

$$P\big(q_{\alpha/2} \le Z \le -q_{\alpha/2}\big) = 1-\alpha$$

$Z$'yi standartlaştırmayla elde etmiştik. Şimdi bunu geri alacağız. Olasılık değişmez, ama amacımız $q$'lar yerine standartlaştırılmamış $a$ ve $b$ yazmaktır. $Z$ yerine açık halini yazalım:

$$P\left(q_{\alpha/2} \le \frac{\hat{\theta}-\theta}{\sigma(\hat{\theta})} \le -q_{\alpha/2}\right) = 1-\alpha$$

Burada yalnız bırakmak istediğimiz $\hat{\theta}$ değil, $\theta$'dır. Standartlaştırırken $\theta$'yı çıkarıp $\sigma$'ya bölmüştük. Tersini yapmak için önce standart sapmayla çarparız, sonra $\hat{\theta}$ ile işlem yaparız. Adımlar (ara adım eklendi):

1. $\sigma(\hat{\theta})$ ile çarpılır: $q_{\alpha/2}\,\sigma(\hat{\theta}) \le \hat{\theta}-\theta \le -q_{\alpha/2}\,\sigma(\hat{\theta})$
2. $\hat{\theta}$ çıkarılır: $-\hat{\theta} + q_{\alpha/2}\,\sigma(\hat{\theta}) \le -\theta \le -\hat{\theta} - q_{\alpha/2}\,\sigma(\hat{\theta})$
3. $-1$ ile çarpılır, eşitsizliklerin yönü değişir. Sıralamayı küçükten büyüğe yazınca hocanın ulaştığı sonuç çıkar:

$$P\big(\hat{\theta} + q_{\alpha/2}\,\sigma(\hat{\theta}) \le \theta \le \hat{\theta} - q_{\alpha/2}\,\sigma(\hat{\theta})\big) = 1-\alpha$$

Burada $q_{\alpha/2}$ negatif olduğu için sol sınır $\hat{\theta}$'dan küçük, sağ sınır büyüktür.

### 4.6 $z$ Gösterimi

Hedefe neredeyse vardık. Yalnız kitap $q$ yerine standart normal kantiller için $z$ gösterimini kullanır:

$$z_{\alpha/2} = -q_{\alpha/2}$$

Daha genel olarak aşağıdaki eşitlikler geçerlidir ($\Phi$ standart normal kümülatif dağılım fonksiyonudur):

$$z_\alpha = -q_\alpha = q_{1-\alpha} = \Phi^{-1}(1-\alpha)$$

$z_\alpha$'nın anlamı şudur: Standart normal değişkenin $\alpha$ olasılıkla aştığı değerdir. Yani ortalaması $0$, standart sapması $1$ olan dağılımda bu değerin sağında kalan olasılık $\alpha$'dır.

Sık kullanılan değerleri hoca şöyle yazdı. Kitapta da bulunabilir. Yanında dört basamaklı python hesabı verilmiştir (`statistics.NormalDist().inv_cdf`):

| $\alpha$ | Hocanın değeri $z_\alpha$ | Python ile hesaplandı |
|---|---|---|
| $0.10$ | $1.282$ | $1.2816$ |
| $0.05$ | $1.645$ | $1.6449$ |
| $0.025$ | $1.960$ | $1.9600$ |
| $0.01$ | $2.326$ | $2.3263$ |
| $0.005$ | $2.576$ | $2.5758$ |

> **Ders sonrası not:** Altyazıda $z_{0.025}$ satırı üst üste tekrarlanıyor ve $z_{0.05}$ "1645", $z_{0.005}$ "to 5, 7, 6" diye geçiyor. Tablodaki eşleşme python ile hesaplanan değerlerle doğrulandı; hocanın değerleri doğrudur.

Hoca önceki eşitliği bu gösterimle yeniden yazdı. $q_{\alpha/2}$ yerine $-z_{\alpha/2}$ gelince sol sınırda eksi, sağ sınırda artı işareti görülür:

$$P\big(\hat{\theta} - z_{\alpha/2}\,\sigma(\hat{\theta}) \le \theta \le \hat{\theta} + z_{\alpha/2}\,\sigma(\hat{\theta})\big) = 1-\alpha$$

### 4.7 Sonuç

Aslında işimiz bitti, çünkü aradığımız $a$ ve $b$ karşımızda: Soldaki ifade $a$, sağdaki ifade $b$'dir. Yani:

$$[a, b] = \hat{\theta} \pm z_{\alpha/2}\,\sigma(\hat{\theta})$$

Bu aralık, $\theta$ için $(1-\alpha)\times 100\%$'lük güven aralığıdır.

- $\hat{\theta}$ aralığın merkezidir (center).
- $z_{\alpha/2}\,\sigma(\hat{\theta})$ paydır (margin).

### 4.8 Formül Ne Zaman Uygulanır?

> **Hocanın vurgusu:** Bu formülü uygulamak için dikkatli olmak gerekir. Temelde iki şarta dikkat edilir: $\hat{\theta}$, $\theta$'nın yansız tahmin edicisi olmalıdır ve normal dağılmalıdır; çok veri varsa asimptotik normal olması yeterlidir.

Bunların yanında standart hatayı bir şekilde bulabiliyor olmamız gerekir, çünkü formülün içinde vardır. $z_{\alpha/2}$ ise normal dağılım tablosundan bulunur. Bu koşullar sağlanıyorsa formül doğrudan uygulanır.

Sıradaki örnek popülasyon ortalaması üzerine olacak, ama bu yalnızca bir örnektir. Yöntem, yansız ve normal dağılan her tahmin edici için kullanılabilir.

## 5. Örnek: Popülasyon Ortalaması İçin Güven Aralığı

### 5.1 Tahmin Edicinin Seçilmesi

Popülasyon ortalaması $\mu$ için bir güven aralığı denklemi bulmak istiyoruz. Öncelikle yansız ve normal dağılan bir tahmin edici gerekir. Böyle bir tahmin ediciyi zaten biliyoruz: örneklem ortalaması $\bar{X}$.

- Yansızdır, çünkü beklenen değeri $\mu$'nün kendisidir: $E[\bar{X}] = \mu$.
- Asimptotik normaldir. Yani yeterince veri varsa $\bar{X}$ normal dağılır.

> **Ek bilgi (derste anlatılmadı):** $\bar{X}$'in asimptotik normal olması büyük olasılıkla daha önce gördüğünüz merkezi limit teoreminden gelir. Bu teorem, bağımsız gözlemlerin ortalamasının $n$ büyüdükçe normal dağılıma yaklaştığını söyler.

Yeterli veri olduğunu varsayarak formülde $\hat{\theta}$ yerine $\bar{X}$ yazalım:

$$[a, b] = \bar{X} \pm z_{\alpha/2}\,\sigma(\bar{X})$$

Formüldeki büyüklüklere tek tek bakalım. $\bar{X}$ veriden kolayca hesaplanır. $z_{\alpha/2}$ standart normal kümülatif dağılım tablolarından okunur. Peki $\sigma(\bar{X})$? Örneklem ortalamasının standart sapmasını zaten biliyoruz: $\sigma/\sqrt{n}$. Burada $\sqrt{n}$ veriden bilinir.

### 5.2 Üç Durum

**$\sigma$ biliniyorsa.** Geçmiş verilerden veya başka bir yoldan biliyorsak doğrudan kullanırız:

$$[a, b] = \bar{X} \pm z_{\alpha/2}\,\frac{\sigma}{\sqrt{n}}$$

> **Ders sonrası not:** Hoca burada "popülasyon ortalamasını geçmiş verilerden biliyorsak" dedi, sonra "sorry" diyerek düzeltmeye geçti; doğrusu popülasyon **standart sapması** $\sigma$'dır.

**$\sigma$ bilinmiyor, örneklem büyükse.** Yerine tahmin edicisini, yani örneklem standart sapması $s$'yi koyarız. Bunu yapabilmemizin nedeni, örneklem büyükken standart sapma tahmininin yeterince iyi olmasıdır:

$$[a, b] = \bar{X} \pm z_{\alpha/2}\,\frac{s}{\sqrt{n}}$$

**$\sigma$ bilinmiyor, örneklem küçükse.** Standart sapmayı doğru tahmin edecek kadar veri yok demektir. Bu durumda normal dağılımı kullanmayız, Student $t$ dağılımını (Student's t distribution) kullanmak zorundayız. Formülde $z$ yerine $t$ gelir:

$$[a, b] = \bar{X} \pm t_{\alpha/2}\,\frac{s}{\sqrt{n}}$$

Burada $t_{\alpha/2}$, $n-1$ serbestlik dereceli (degrees of freedom) $t$ dağılımının kritik değeridir (critical value).

### 5.3 Student $t$ Dağılımı Hakkında

$t$ dağılımının ayrıntısı derste işlenmedi. Hocanın söyledikleri şunlardır: Normal dağılıma benzer, yine simetrik bir dağılımdır ve yeterince veri olmadığında normal dağılımın yerine kullanılabilir. Değerlerini tablodan okuyabilir, ayrıntısını kitaplardan araştırabilirsiniz.

> **Ek bilgi (derste anlatılmadı):** $t$ dağılımının kritik değerleri serbestlik derecesi büyüdükçe azalarak $z$ değerlerine yaklaşır. Bu davranış, %95 güven düzeyine karşılık gelen $t_{0.025}$ için python ile sayısal integralle kontrol edildi. Örneklem büyükken $z$ formülünün kullanılabilmesiyle bu davranış uyumludur.

Bu bölüm, dönemin son konusudur. Hoca, Baron'un kitabında en son işlenen yerin "9.22" olduğunu söyledi.

<!-- BELİRSİZ: Altyazıda "9.22" geçiyor. Büyük olasılıkla 9.2.2 numaralı alt bölüm kastediliyor; kitabın içindekilerinden kontrol edin. -->

## 6. İstatistiğin Önemi ve Kitap Önerisi

> **Hocanın vurgusu:** İstatistik çok önemlidir, özellikle veri bilimi (data science) için.

Hoca ayrıca başka bir kaynak önerdi. Kitap olarak Baron'un yanında Ross'un olasılık kitabını, *Introduction to Probability Models*'ı "güzel bir kitap" diye andı. Bu konuda çok sayıda başka kitap da olduğunu, başka kitaplar da bulunabileceğini ekledi.

<!-- BELİRSİZ: 02:12:44-02:16:29 arası bozuk çevrilmiş (Türkçe konuşma İngilizce modda). Baron'un kitabıyla ilgili karşılaştırma ve veri bilimi cümlelerinin tamamı okunmuyor. Yukarıda yalnız anlaşılan kısımlar var. -->

## Dersin Toparlaması

Bu derste parametre tahmininin ardından gelen soruya cevap arandı: Bulduğumuz tahmin ne kadar iyi? İlk cevap standart hataydı. Bir tahmin edicinin standart sapması olan bu büyüklük, $\bar{X}$ için $\sigma/\sqrt{n}$'dir. $\sigma$ bilinmediğinde veriden tahmin edilir. Poisson örneğinde bunun iki farklı yolu görüldü: genel $s/\sqrt{n}$ ve dağılıma özel $\sqrt{\bar{X}}/\sqrt{n}$.

İkinci cevap güven aralığıydı. Nokta tahmini tek bir sayı verdiği için ona olasılık atanamaz. Aralık kurunca güvenimizi $1-\alpha$ olasılığıyla söyleyebiliriz. Yansız ve normal dağılan bir $\hat{\theta}$ için standartlaştırma, simetri ve kantil adımlarıyla $\hat{\theta} \pm z_{\alpha/2}\,\sigma(\hat{\theta})$ formülüne ulaştık. Bunu popülasyon ortalamasına uyguladık. $\sigma$ bilinmeyen küçük örneklemlerde ise $z$ yerine $n-1$ serbestlik dereceli $t$ dağılımının kritik değeri kullanılır. Bu konu dönemin son konusuydu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
