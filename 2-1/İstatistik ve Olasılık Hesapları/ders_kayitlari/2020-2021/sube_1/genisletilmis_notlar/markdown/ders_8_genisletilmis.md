# Ders 8 Genişletilmiş Notu: Üstel, Gama ve Normal Dağılımlar, Merkezi Limit Teoremi ve İstatistiğe Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Olasılığın sınav analizinde kullanılması
- 2. Üstel dağılım
- 3. Gama fonksiyonu
- 4. Gama dağılımı
- 5. Normal (Gauss) dağılım
- 6. Teori ve teorem
- 7. Merkezi limit teoremi
- 8. İstatistiğe giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Olasılığın sınav analizinde kullanılması

Ders, olasılık ve istatistiğin gerçek hayatta nerede kullanılabileceğini gösteren bir soruyla açıldı. Hoca soruyu kendisinin ürettiğini söyledi ve iPad'e şöyle yazdı (ekrandan, 00:10:00 ve 00:15:00):

> Below is given a good example of possible usage of probability theory and statistics for evaluating the multiple choice exams. It is strongly recommended to solve the following question: Assume that there are 20 multiple-choice questions in a midterm exam. Each question has 5 options. The number of students taking this midterm exam is 100. What is the probability of the event that two students solved at least 5 questions incorrectly by choosing the same option? If this probability is very very small, what is your comment on the occurrence of that event?

Yani olay, iki öğrencinin en az beş soruda aynı şıkkı seçerek yanlış yapmasıdır. Bu olayın olasılığı çok küçük çıkıyorsa ve olay yine de gerçekleşmişse, bunun rastlantıyla açıklanması güçleşir. Sorunun çözümü bu bölümde verilmedi; ara sırasında bir öğrencinin sorusu üzerine kısa bir tartışma yapıldı (bkz. Örnek Sorular).

Hoca bu tür bir analizin hangi veriye dayanacağını da gösterdi. Her öğrenci ve her soru için şu sütunları olan bir tablo düşünülebilir (ekrandan, 00:15:00):

| ID | Name | Surname | Time for seeing | Time for answering | Selection | T/F |
|---|---|---|---|---|---|---|
| 2001... | A | B | 11:00 | 11:03 | A | T |
| 219... | C | D | 10:50 | 10:55 | ... | ... |

Tablodaki kimlik ve adlar hocanın uydurduğu örnek değerlerdir. Soruyu görme ve cevaplama zamanları, seçilen şık ve cevabın doğru olup olmadığı bilinirse, olasılık hesaplarıyla olağan dışı benzerlikler yakalanabilir. Hoca bu problemin olasılık ve istatistik teorisi ile derin öğrenme birlikte kullanılarak otomatikleştirilebileceğini, bunun güncel bir proje konusu olabileceğini söyledi.

## 2. Üstel dağılım

### 2.1 Tanım ve PDF

$X$ üstel (exponential) dağılımlı bir rastgele değişken olsun ve $X \sim \mathrm{Exp}(\lambda)$ diye gösterilsin. Parametre $\lambda$, üstel dağılımın ortalamasının tersidir. PDF şöyledir (ekrandan, 00:25:00):

$$
f_X(x) = \begin{cases} \lambda e^{-\lambda x}, & x \ge 0 \\ 0, & x < 0 \end{cases}
$$

PDF negatif değerlerde ($x \in \mathbb{R}^-$) sıfır olduğu için $X \sim \mathrm{Exp}(\lambda)$ negatif olmayan (non-negative) bir dağılımdır.

Grafikte $x = 0$ noktasında PDF'in değeri $\lambda$'dır; $x$ arttıkça eğri sıfıra doğru iner, negatif tarafta ise değer sıfırdır. Hoca eğrinin altındaki toplam alanı sordu ve hesapladı (ekrandan, 00:30:00):

$$
\int_{-\infty}^{\infty} f_X(x)\,dx = \int_0^\infty \lambda e^{-\lambda x}\,dx = \lambda \int_0^\infty e^{-\lambda x}\,dx = \lambda \cdot \frac{1}{\lambda} = 1 .
$$

### 2.2 Üstel dağılım neden kullanılır?

Hoca öğrencilere "Bilimde ve mühendislikte üstel dağılımı neden kullanırız?" diye sordu. Bir öğrencinin yorumu üzerine şu uyarıyı yaptı: dağılımı bir sinyal ya da zamanla azalan bir fonksiyon gibi düşünmemek gerekir. Rastgele değişken herhangi bir değeri alabilir; azalan şey, PDF'te ya da histogramda görülen olasılıktır. $x$ büyüdükçe o değerin civarında olma olasılığı azalır.

Ekrana yazılan cevap şudur: üstel dağılım arıza (failure) ya da bekleme sürelerini modellemek için kullanılır; "bir şey olana kadar ne kadar süre geçer?" biçiminde bir soru içeren deneyleri tanımlar (ekrandan, 00:30:00 ve 00:35:00).

Hoca şu örnekleri verdi:

- **Sınav sorusu:** Çoktan seçmeli bir soruyu gördükten sonra bir şık seçene kadar geçen toplam süre üstel dağılımlıdır (ekrandan, 00:35:00). Sınavda soruyu görmek ile cevaplamak arasındaki süre bu dağılımla modellenebilir.
- **Banka:** Bir bankaya art arda gelen iki müşterinin geliş zamanları arasındaki süre üstel dağılımlıdır (ekrandan, 00:35:00).
- **Twitter:** Aynı kişiye ya da gruba art arda atılan iki tweet arasındaki süre üstel dağılımlıdır. Ekranda bu örneğin devamında, bu bilgiden o kişinin ya da grubun terörist olma olasılığının ne olduğu sorusu yazılıydı (ekrandan, 00:40:00). <!-- BELİRSİZ: Twitter örneğinin tam metni karede kısmen görünüyor, altyazıda da bozuk. -->
- **Yazılım:** Bir programcı Java'da kod yazıyor. Art arda iki programlama hatası (bug) arasındaki satır sayısı üstel dağılımlıdır (ekrandan, 00:40:00). Hoca, bu bilgiden CVS ya da Git kullanılmasa bile hatanın sahibinin bulunabileceğini söyledi.

Hoca örneklerin ortak anahtar kelimesinin **art arda (consecutive)** olduğunu vurguladı.

> **Hocanın vurgusu:** Art arda iki şey arasındaki süre ya da mesafe söz konusuysa üstel dağılımı düşünün. Başlangıç ve bitiş zamanı arasındaki toplam süre de aynı mantıkla ele alınır.

**Soru:** Soruların zorluğu değiştikçe bu dağılım bozulmaz mı?
**Cevap:** Hoca bu soruya doğrudan bir cevap vermedi; cevaplama süresinin olasılık teorisiyle analiz edilerek olağan dışı davranışların yakalanabileceğini söylemekle yetindi.

> **Ek bilgi (derste anlatılmadı):** Sorular farklı zorlukta olduğunda her sorunun cevaplama süresi farklı $\lambda$ değerli bir üstel dağılımla modellenebilir. Tek bir $\lambda$ varsaymak büyük olasılıkla bir basitleştirmedir.

### 2.3 CDF, ortalama ve varyans

CDF, PDF'in $-\infty$'dan $x$'e integralidir. PDF yalnız $0$ ile $\infty$ arasında tanımlı olduğu için alt sınır $0$ alınır:

$$
F_X(x) = \Pr(X \le x) = \int_0^x \lambda e^{-\lambda t}\,dt = \begin{cases} 1 - e^{-\lambda x}, & x \ge 0 \\ 0, & x < 0 \end{cases}
$$

Beklenen değer için PDF tanıma konur (ekrandan, 00:45:00):

$$
E[X] = \int_0^\infty x\,\lambda e^{-\lambda x}\,dx = \lambda \int_0^\infty x e^{-\lambda x}\,dx = \lambda \cdot \frac{1}{\lambda^2} = \frac{1}{\lambda}.
$$

Varyans, ikinci momentten birinci momentin karesi çıkarılarak bulunur:

$$
\mathrm{Var}(X) = E[X^2] - E[X]^2 = \int_0^\infty x^2 \lambda e^{-\lambda x}\,dx - \frac{1}{\lambda^2} = \frac{1}{\lambda^2}.
$$

Hoca integralin çözümünü öğrencilere bıraktı; sonuçlar python ile sayısal integralle doğrulandı.

### 2.4 Geometrik dağılımla ilişkisi

Kesikli rastgele değişkenler için verilen geometrik dağılımın sürekli zamandaki karşılığı (continuous time analog) üstel dağılımdır. Hoca, geometrik dağılımda başarı olasılığı belli bir kısıt altında sıfıra götürülünce üstel dağılımın elde edildiğini söyledi.

### 2.5 Belleksizlik özelliği

Üstel dağılım belleksizdir (memoryless) (ekrandan, 00:50:00):

$$
\Pr(X > r) = \Pr(X > r + s \mid X > s).
$$

Yani $X$'in $s$'den büyük olduğunu bilmek, $s$'nin üstüne $r$ kadar daha geçme olasılığını değiştirmez. Hoca ispatı koşullu olasılıkla yaptı. $X > r+s$ ise $X > s$ de sağlanır, bu yüzden kesişim $X > r+s$ olayıdır:

$$
\Pr(X > r+s \mid X > s) = \frac{\Pr(X > r+s)}{\Pr(X > s)} = \frac{1 - \Pr(X \le r+s)}{1 - \Pr(X \le s)} = \frac{1 - F_X(r+s)}{1 - F_X(s)} .
$$

CDF yerine konursa

$$
\frac{e^{-\lambda(r+s)}}{e^{-\lambda s}} = e^{-\lambda r} = 1 - \Pr(X \le r) = \Pr(X > r)
$$

bulunur. Sonuç $s$'ye bağlı değildir; geçmişteki bekleme süresinin bilgisi hesaba girmez. Bu yüzden dağılıma belleksiz denir.

### 2.6 Nadir olaylar ve paralel evrenler örneği

Nadir olaylar (rare events) arasındaki süre ya da uzaydaki mesafe üstel dağılımlıdır. Hoca sezgi için varsayımsal örnekler verdi: uzayda hayat barındıran gezegenler arasındaki mesafe ya da çok sayıda paralel evren varsa art arda iki evren arasındaki mesafe.

Bir öğrenciye bu mesafenin neden üstel olduğu soruldu. Öğrenci "consecutive" kelimesinin anlamını bilmediğini söyleyince hoca açıkladı: art arda, ardışık, arka arkaya gelen demektir. Ardından örneği kurdu: dünyamızın bulunduğu evren ile herhangi bir evren arasındaki mesafe $D$ olsun. Mesafe negatif olamaz, çok küçük de çok büyük de olabilir; $D$ üstel dağılımlı alınır:

$$
f_D(x) = \lambda e^{-\lambda x}\ (x \ge 0), \qquad \lambda = \frac{1}{E[D]} .
$$

$\lambda$, daha önce bulunan $E[X] = 1/\lambda$ ilişkisinden ortalamanın tersi olarak elde edilir. Hoca ortalamayı araştırmalara dayandırarak $E[D] \approx 10^{10}$ diye yazdı (ekrandan, 01:05:00). Örneğin amacı, ortalaması bilinen bir büyüklük için PDF'in tamamen belirlenebildiğini göstermektir.

> **Ders sonrası not:** Paralel evrenler örneği varsayımsal bir sezgi örneğidir. $10^{10}$ değerinin birimi ve kaynağı derste belirtilmedi; altyazıda bu sayı bozuk çıkmış, değer kareden alındı.

### 2.7 Evde çalışılacak dağılım: EGK

Hoca "Extended Generalized K" (EGK) dağılımını öğrencilerin kendi başlarına çalışmasını istedi ("This distribution is given for you to study at home", ekrandan, 01:10:00). Dersin ilerleyen kısmında bu dağılımın optik kablosuz kanalların performansını modellemekte kullanıldığını anlattı. Örnek olarak Li-Fi'yi verdi: Wi-Fi'deki radyo dalgaları yerine lambadan gelen ışıkla internete bağlanma; telefonun üzerindeki bir algılayıcı ışıktan gelen bilgiyi alır. Bir öğrencinin "karanlıkta nasıl bağlanacağız?" sorusuna, gözün görmediği dalga boylarında da yayın yapılabileceği cevabını verdi.

<!-- BELİRSİZ: EGK dağılımının ekranda yazılan tanımı ve PDF'i karelerde görünmüyor; altyazıda da okunmuyor. -->

## 3. Gama fonksiyonu

Gama dağılımının PDF'inde geçen $\Gamma(m)$ sorulduğunda bir öğrenci bunun faktöriyelle ilgili olduğunu söyledi. Hoca doğruladı: $\Gamma$, faktöriyelin gerçel sayılara genişletilmiş tanımıdır. Tamsayı faktöriyeli $n! = n(n-1)(n-2)\cdots 2\cdot 1$, örneğin $3! = 3\cdot2\cdot1 = 6$'dır. Peki $0.78!$ nedir? Bunun cevabı $0.78! = \Gamma(1.78)$'dir (ekrandan, 01:25:00).

Gama fonksiyonu integral olarak tanımlanır:

$$
\Gamma(m) = \int_0^\infty x^{m-1} e^{-x}\,dx .
$$

Hoca, örneğin $1000!$'i doğrudan hesaplamanın zor olduğunu, ama integral biçiminin işi kolaylaştırdığını söyledi. Ekrana şu özellikleri yazdı (ekrandan, 01:30:00):

- $\Gamma(1) = 1$
- $\Gamma(0.5) = \sqrt{\pi}$
- $\Gamma(k+1) = k\,\Gamma(k)$
- $\Gamma(n) = (n-1)!$, $n \in \mathbb{N}^+$

Python ile kontrol: $\Gamma(0.5) = 1.7725 = \sqrt\pi$, $\Gamma(4) = 6 = 3!$, $\Gamma(1.78) \approx 0.9262$.

İstatistiksel analizlerde gama fonksiyonu sınırlar bulurken ve momentleri hesaplarken çok sık kullanılır. Hoca öğrencilerin isteği üzerine şu sonucu da not ettirdi: rastgele değişkenlerin momentleri (birinci, ikinci, üçüncü, dördüncü moment...) genellikle gama fonksiyonları cinsinden, onların çarpımı ya da toplamı olarak ifade edilebilir. Bu sonuçla ilişkili aracın adını Mellin dönüşümü olarak verdi.

> **Ek bilgi (derste anlatılmadı):** Bir $X \ge 0$ değişkeninin Mellin dönüşümü $E[X^{s-1}]$ biçimindedir; yani momentleri doğrudan verir. Gama ve benzeri dağılımlarda bu beklenen değerler gama fonksiyonlarının oranı olarak çıkar.

## 4. Gama dağılımı

### 4.1 Tanım ve PDF

Hoca, olasılık ve istatistiği iyi kullanmak için bu dağılımları çok iyi bilmenin şart olduğunu tekrar hatırlattı. Ardından gama dağılımını tanımladı. Kitaptaki gösterimden farklı bir gösterim kullandığını, PDF'in aynı olduğunu belirtti (ekrandan, 01:40:00):

$X \sim \mathrm{Gamma}(m, \Omega)$, burada $m \ge \frac12$ ve $\Omega > 0$; $m$ biçim (shape) parametresi, $\Omega$ ise $X$'in ortalamasıdır.

$$
f_X(x) = \begin{cases} \dfrac{1}{\Gamma(m)} \left(\dfrac{m}{\Omega}\right)^m x^{m-1} \exp\!\left(-\dfrac{m}{\Omega}x\right), & x \ge 0 \\ 0, & x < 0 \end{cases}
$$

PDF yalnız pozitif $x$ için tanımlı olduğundan gama dağılımı da negatif olmayan bir dağılımdır.

> **Ek bilgi (derste anlatılmadı):** Kitapta gama dağılımı büyük olasılıkla biçim $\alpha$ ve oran $\lambda$ parametreleriyle yazılır. Derste kullanılan $(m,\Omega)$ gösterimi, biçim $\alpha = m$ ve oran $\lambda = m/\Omega$ alınarak aynı PDF'e dönüşür. Genel gama dağılımında biçim parametresi $m > 0$ olabilir; $m \ge 1/2$ kısıtı bu gösterimin iletişim kanalı modellerinde kullanılan biçimine özgüdür.

### 4.2 PDF'in biçimi

Hoca farklı $m$ değerleri için PDF'i çizdi (ekrandan, 01:25:00 ve 01:30:00):

- $m = 1$: PDF'te $m = 1$ konunca $f_X(x) = \frac{1}{\Omega} e^{-x/\Omega}$ olur; yani gama dağılımı üstel dağılıma dönüşür. Eğri $x = 0$'da $1/\Omega$ değerinden başlayıp azalır.
- $m = 2$ ve $m = 3$: eğri sıfırdan başlar, bir tepe yapar ve azalır; $m$ büyüdükçe tepe sivrileşir.
- $m = 10$: tepe daha da dar ve yüksektir.
- $m \to \infty$: PDF Dirac delta fonksiyonuna dönüşür.

Hoca Dirac fonksiyonunu daha önce görüp görmediklerini sordu; bir öğrenci önceki derslerde gördüklerini söyledi. Dirac fonksiyonu tek bir noktada sonsuza gider ve altındaki alan 1'dir; olasılıkta da PDF'in altındaki alan 1 olduğundan, $m$ sonsuz olunca dağılım bu biçimi alır.

### 4.3 Ortalama ve varyans

Beklenen değer, PDF tanıma konarak kuruldu (ekrandan, 01:35:00):

$$
E[X] = \int_0^\infty x \frac{1}{\Gamma(m)} \left(\frac{m}{\Omega}\right)^m x^{m-1} e^{-\frac{m}{\Omega}x}\,dx = \frac{1}{\Gamma(m)} \left(\frac{m}{\Omega}\right)^m \int_0^\infty x^m e^{-\frac{m}{\Omega}x}\,dx .
$$

Hoca bu integrali gama fonksiyonu yardımıyla çözdü. Doğru sonuç şöyledir (ara adım eklendi):

$$
\int_0^\infty x^m e^{-\frac{m}{\Omega}x}\,dx = \Gamma(m+1)\left(\frac{\Omega}{m}\right)^{m+1}
\quad\Rightarrow\quad
E[X] = \frac{\Gamma(m+1)}{\Gamma(m)} \cdot \frac{\Omega}{m} = m \cdot \frac{\Omega}{m} = \Omega .
$$

Varyans için $\mathrm{Var}(X) = E[(X - E[X])^2]$ tanımı açılarak $E[X^2] - E[X]^2$ elde edilir. İkinci moment, aynı integralde $x$ yerine $x^2$ konarak aynı yolla bulunur. Sonuç:

$$
\mathrm{Var}(X) = \frac{\Omega^2}{m}.
$$

> **Ders sonrası not:** Hoca ekranda integrali $\frac{\Gamma(m)\,\Omega^{m-1}}{m^m}$, ortalamayı $E[X] = 1/\Omega$ diye yazdı ve varyans hesabında $1/\Omega^2$ çıkardı. Doğrusu integralin $\Gamma(m+1)(\Omega/m)^{m+1}$, ortalamanın $E[X] = \Omega$ olmasıdır; varyansta çıkarılan terim de $\Omega^2$'dir. Bu, hocanın kendi tanımıyla ("$\Omega$ is the average of $X$") uyumludur. Hocanın verdiği varyans sonucu $\Omega^2/m$ doğrudur. $m = 3$, $\Omega = 2$ için python ile sayısal integral: alan $1$, ortalama $2$, varyans $4/3$.

### 4.4 Varyansın sıfıra gitmesi ne demek?

$\lim_{m\to\infty} \mathrm{Var}(X) = 0$ olur. Hoca bunun ne anlama geldiğini sordu. Bir öğrenci dağılımın tek bir noktada sonsuza giden delta biçimine dönüşmesi gerektiğini söyledi. Hoca doğruladı: $m$ sonsuz olunca $X$ hep $\Omega$ değerini alır, saçılma yoktur; $X$ değeri $\Omega$ olan bir sabite dönüşür. Sabit bir büyüklüğün varyansı sıfırdır.

Hoca bunu bir ölçüm örneğiyle açtı. Hava basıncını ölçen bir mühendis düşünelim. Her ölçümde hep aynı değer çıkıyorsa varyans sıfırdır; değerler birbirine çok yakınsa varyans küçüktür, standart sapma azdır. Ölçümler 700, 750, 400 milibar gibi çok farklı değerler arasında gidip geliyorsa varyans büyüktür. Böyle bir barometre için belirsizlik ve hata oranı fazladır, yani cihaz hatalı çalışıyor denir. Varyans bir bakıma hatayı ifade eder.

> **Hocanın vurgusu:** Gama dağılımındaki biçim parametresi $m$, ölçümlerin doğruluğunu gösteren bir parametre gibi düşünülebilir. Yönteminizin doğruluğunu artırdıkça gözlemlerinizin varyansı sıfıra yaklaşır.

### 4.5 Üstel dağılımların toplamı gama dağılımlıdır

Hoca şu durumu yazdı: bir işlem $k$ adımda yapılıyor ve her adım üstel dağılımlı bir süre alıyor. Bu durumda toplam süre gama dağılımlıdır (ekrandan, 01:45:00):

$$
G = \sum_{i=1}^{k} E_i, \qquad E_i \sim \mathrm{Exp}\!\left(\frac{k}{\Omega}\right),\ i = 1, 2, \dots, k \quad\Rightarrow\quad G \sim \mathrm{Gamma}\!\left(k, \frac{\Omega}{k}\right).
$$

Yani üstel dağılımların toplamı gama dağılımlıdır.

> **Ders sonrası not:** Her $E_i$'nin ortalaması $\Omega/k$ olduğundan $G$'nin ortalaması $\Omega$, varyansı $k(\Omega/k)^2 = \Omega^2/k$'dır. Derste kullanılan $\mathrm{Gamma}(m,\Omega)$ gösteriminde ikinci parametre ortalama olduğu için bu sonuç $G \sim \mathrm{Gamma}(k, \Omega)$ diye yazılmalıdır. Ekrandaki $\Omega/k$, biçim-ölçek (shape-scale) gösterimindeki ölçek parametresine karşılık gelir. $k = 3$, $\Omega = 2$ için $10^6$ örnekli benzetim: ortalama $\approx 2.000$, varyans $\approx 1.334 \approx 4/3$.

Üstel dağılım art arda iki olay arasındaki süre için kullanılıyordu. Art arda birden fazla olayın toplam süresi düşünüldüğünde gama dağılımı kullanılır. Hocanın örnekleri:

- Bir öğrencinin art arda üç soruyu cevaplaması için geçen toplam süre gama dağılımlıdır.
- Art arda $n$ müşterinin bankaya gelmesi için geçen toplam süre gama dağılımlıdır.
- Art arda $n$ paralel evreni ziyaret etmek için kat edilen yol gama dağılımlıdır.
- Bir elektronun metal içinde hareket ederken art arda $n$ elektronla çarpışması için geçen süre gama dağılımlıdır.

## 5. Normal (Gauss) dağılım

### 5.1 Tanım ve PDF

$X$ normal (Gauss) dağılımlı olsun: $X \sim N(\mu, \sigma^2)$. Burada $\mu \in \mathbb{R}$, $X$'in ortalamasıdır ($\mu = E[X]$); $\sigma > 0$, $X$'in standart sapmasıdır: $\sigma = \sqrt{\mathrm{Var}(X)}$, yani $\sigma^2 = \mathrm{Var}(X)$ (ekrandan, 01:50:00).

$$
f_X(x) = \frac{1}{\sqrt{2\pi\sigma^2}} \exp\!\left(-\frac{(x-\mu)^2}{2\sigma^2}\right), \qquad -\infty < x < \infty .
$$

### 5.2 Grafik ve alanlar

PDF çan biçimindedir ve ortası $\mu$'dür. Hoca grafikte $\mu - \sigma$ ve $\mu + \sigma$ noktalarını işaretledi (ekrandan, 01:55:00). PDF'in altındaki toplam alan 1 olduğundan, simetri gereği $\mu$'nün sağında kalan alan $1/2$'dir. Hoca $\mu - \sigma$'nın solunda kalan alanı sordu; bir öğrenci $0.16$ diye cevap verdi, hoca doğruladı. Ekranda ayrıca $\mu - \sigma$ ile $\mu$ arasındaki alan $\approx 0.34$ diye yazılıydı.

Kontrol: $\Phi(-1) \approx 0.1587$, $\Phi(0) - \Phi(-1) \approx 0.3413$.

Ortalama ve varyans bilinirse PDF tamamen bilinmiş olur. Hoca bunu pratik bir öneriye bağladı: elinizdeki bir rastgele değişkenin histogramı bu çan biçimindeyse onu Gauss dağılımlı kabul edebilir, ortalamasını ve varyansını hesaplayıp PDF'ini yazabilir ve kullanabilirsiniz.

**Soru:** Normal dağılımın parametresi olarak varyans yerine standart sapmayı vermemiz gerekmiyor muydu?
**Cevap:** Standart sapma varyansın kareköküdür ve tanımda bu açıkça yazıldı. Gösterimde $\sigma^2$ (varyans) kullanılır; deviation sapma demektir, standart sapmanın karesi varyanstır.

### 5.3 Standart normal dağılım

Standart normal dağılım $Y \sim N(0,1)$ ile gösterilir. Ortalama $0$, varyans $1$ konunca PDF şu olur (ekrandan, 01:55:00):

$$
f_Y(y) = \frac{1}{\sqrt{2\pi}} \exp\!\left(-\frac{y^2}{2}\right), \qquad -\infty < y < \infty .
$$

Standart normalin dağılım fonksiyonu

$$
\Phi(x) = \Pr(Y \le x) = \frac{1}{\sqrt{2\pi}} \int_{-\infty}^{x} e^{-u^2/2}\,du
$$

ile verilir. Bu integralin kapalı biçimli bir ifadesi kolay bulunamaz; değerleri sayısal tablolarda verilir.

> **Ders sonrası not:** Altyazıda bu fonksiyon için "quantile function" ve "Q function" adları geçiyor; ekranda ise $\Phi$ yazılı (ekrandan, 02:05:00). $\Phi$ standart normalin dağılım fonksiyonudur (CDF). Quantile fonksiyonu büyük olasılıkla onun tersi olan $\Phi^{-1}$'dir; mühendislikte $Q(x)$ ise genelde $1 - \Phi(x)$ için kullanılır. Hoca altyazıdaki $\frac{1}{\cdot}$ katsayısını sözlü olarak eksik söylemiş olabilir; doğru katsayı $\frac{1}{\sqrt{2\pi}}$'dir.

### 5.4 Standartlaştırma

$X \sim N(\mu, \sigma^2)$ için yeni bir değişken tanımlanır: $Z = \dfrac{X - \mu}{\sigma}$. Hoca $Z$'nin ortalamasını, varyansını ve dağılımını sordu ve hesapladı (ekrandan, 02:00:00):

$$
E[Z] = E\!\left[\frac{X - \mu}{\sigma}\right] = E\!\left[\frac{X}{\sigma}\right] - E\!\left[\frac{\mu}{\sigma}\right] = \frac{1}{\sigma}E[X] - \frac{\mu}{\sigma} = \frac{\mu}{\sigma} - \frac{\mu}{\sigma} = 0 .
$$

$\mu$ sabit olduğu için varyansı değiştirmez:

$$
\mathrm{Var}(Z) = \mathrm{Var}\!\left(\frac{X - \mu}{\sigma}\right) = \mathrm{Var}\!\left(\frac{X}{\sigma}\right) = \frac{1}{\sigma^2}\mathrm{Var}(X) = \frac{1}{\sigma^2}\cdot\sigma^2 = 1 .
$$

Dolayısıyla $Z \sim N(0, 1)$'dir. Bu işleme standart normalleştirme (standardization) denir.

### 5.5 Gauss olasılıklarının hesabı

$Z = \frac{X - \mu}{\sigma}$ ifadesinden $X = \sigma Z + \mu$ yazılır (ekrandan, 02:05:00):

$$
\Pr(X < b) = \Pr(\sigma Z + \mu < b) = \Pr(\sigma Z < b - \mu) = \Pr\!\left(Z < \frac{b-\mu}{\sigma}\right) = \Phi\!\left(\frac{b-\mu}{\sigma}\right).
$$

Son adımda $\sigma$ pozitif olduğu için iki taraf $\sigma$'ya bölünür; eşitsizliğin yönü ve olasılık değişmez. Önce $\Phi$'nin argümanı hesaplanır, değer tablodan okunur.

Benzer şekilde, Gauss sürekli bir dağılım olduğu için uç noktaların dahil olup olmaması olasılığı değiştirmez:

$$
\Pr(a < X \le b) = \Pr(a < X < b) = \Pr(X < b) - \Pr(X < a) = \Phi\!\left(\frac{b-\mu}{\sigma}\right) - \Phi\!\left(\frac{a-\mu}{\sigma}\right).
$$

## 6. Teori ve teorem

Merkezi limit teoremine geçmeden önce hoca teori ile teorem arasındaki farkı sordu. Bir öğrenci teoremin kanıtlanmış bir önerme olduğunu söyledi; hoca bunu kabul etti. Teori ise bir teoremler kümesidir ("Theory is the set of theorems"). Örnek olarak olasılık teorisi $\{T_1, T_2, \dots, T_n\}$ ve istatistik teorisi $\{T_1, T_2, \dots, T_m\}$ gösterildi.

Merkezi limit teoremi de olasılık teorisinin teoremlerinden biridir. Hoca bu derse kadar görülen teoremleri saydı: Markov eşitsizliği, Chernoff sınırı, toplam olasılık teoremi, bölüntü (partition) teoremi ve Bayes teoremi. Merkezi limit teoremi bunlara eklenen yenisidir.

> **Ek bilgi (derste anlatılmadı):** Doğa bilimlerinde "teori" kelimesi genellikle matematikteki anlamıyla değil, gözlemlerle defalarca sınanmış açıklayıcı bir çerçeve anlamında kullanılır. Derste verilen "teoremler kümesi" tanımı matematiksel teoriler için geçerlidir.

## 7. Merkezi limit teoremi

### 7.1 Kurulum

$X_1, X_2, \dots, X_n$ birbirinden bağımsız rastgele değişkenler olsun. Hepsinin beklenen değeri (ortalaması) aynı, $\mu = E[X_i]$, ve hepsinin standart sapması aynı, $\sigma = \sqrt{\mathrm{Var}(X_i)}$, $i = 1, 2, \dots, n$. Toplamları

$$
S_n = X_1 + X_2 + \dots + X_n
$$

ve standartlaştırılmış toplam (standardized sum)

$$
Z_n = \frac{S_n - E[S_n]}{\sqrt{\mathrm{Var}(S_n)}}
$$

olsun. Hoca bunun normal dağılımda yapılan standartlaştırmanın aynısı olduğunu hatırlattı. Teorem, değişken sayısı $n \to \infty$ giderken her $z \in \mathbb{R}$ için $\Pr(Z_n < z)$'nin standart normalin $\Phi(z)$ değerine yaklaştığını söyler. <!-- BELİRSİZ: Teoremin limit ifadesinin ekrandaki tam yazımı karelerde görünmüyor; burada altyazıdaki anlatıma göre verildi. -->

### 7.2 Toplamın ortalaması ve varyansı

Beklenen değerin doğrusallığından (ekrandan, 02:30:00):

$$
E[S_n] = E[X_1 + \dots + X_n] = E[X_1] + \dots + E[X_n] = \mu + \mu + \dots + \mu = n\mu .
$$

$X_1, \dots, X_n$ bağımsız varsayıldığı için varyanslar toplanır:

$$
\mathrm{Var}(S_n) = \mathrm{Var}(X_1) + \dots + \mathrm{Var}(X_n) = n\sigma^2, \qquad \sqrt{\mathrm{Var}(S_n)} = \sqrt{n}\,\sigma .
$$

### 7.3 Sonuç

$n \to \infty$ iken $S_n$'nin PDF'i ortalaması $n\mu$, varyansı $n\sigma^2$ olan normal PDF'e yaklaşır:

$$
f_{S_n}(s) \approx \frac{1}{\sqrt{2\pi n\sigma^2}} \exp\!\left(-\frac{(s - n\mu)^2}{2n\sigma^2}\right).
$$

$S_n$, $Z_n$ cinsinden $S_n = \sqrt{\mathrm{Var}(S_n)}\,Z_n + E[S_n] = \sqrt{n}\,\sigma Z_n + n\mu$ diye yazılır; burada $Z_n \sim N(0,1)$'dir. Normal dağılımdaki adımların aynısıyla (ekrandan, 02:35:00):

$$
\Pr(S_n < s) = \Pr\!\left(Z_n < \frac{s - n\mu}{\sqrt{n}\,\sigma}\right) = \Phi\!\left(\frac{s - n\mu}{\sqrt{n}\,\sigma}\right).
$$

Pratikte merkezi limit teoremi (CLT) $n$ yeterince büyükse, genellikle $n \ge 30$ için kullanılır (ekrandan, 02:40:00). Hoca bazen 5 ya da 10 gibi daha küçük değerlerin de kullanıldığını söyledi. Değişken sayısı çok büyükse doğrudan normal dağılım kullanılabilir.

### 7.4 Toplamların tam dağılımları

Hoca şu noktaları "çok önemli" diye işaretledi (ekrandan, 02:40:00):

- Bağımsız ve özdeş dağılımlı üstel değişkenlerin toplamının tam (exact) dağılımı gama dağılımıdır.
- Bağımsız ama özdeş olmayan üstel değişkenlerin toplamı Gauss dağılımıyla yaklaşıklanabilir.
- Negatif binom dağılımı, bağımsız geometrik rastgele değişkenlerin toplamının tam dağılımıdır.
- Binom dağılımı, Bernoulli değişkenlerinin toplamının tam dağılımıdır.

> **Hocanın vurgusu:** Bunlar çok önemli noktalar. Tam dağılım biliniyorsa onu kullanın; bilinmiyorsa ve değişken sayısı yeterince büyükse CLT ile Gauss yaklaşımı yapılır.

## 8. İstatistiğe giriş

### 8.1 İstatistik nedir?

Hoca, kitabın 8. bölümüne (Introduction to Statistics) geçerek istatistiğe başladıklarını söyledi ve "İstatistik nedir?" diye sordu. Öğrencilerden gelen cevaplar: veriden çıkarım yapmak için kullanılan matematiksel yöntemler; düzenli sayı verileri; veriyi bilgiye çevirme bilimi; karmaşık bilgiden anlamlı bilgi üretme. Hoca hepsini kabul etti ve istatistiğin anlamlı bilgi üretmek için kullanıldığını vurguladı. Sınav örneğine döndü: bir olayın olasılığı çok küçükse ve olay yine de oluyorsa orada bir aykırılık (outlier), bir düzensizlik vardır; istatistik bunun fark edilmesini sağlar.

Ekrana yazılan tanım: istatistik bilimlerin evrensel dilidir (statistics is the universal language of sciences). Bilgisayar bilimi, elektronik, matematik, kimya, fizik, biyoloji ve yapay zekâ bu dili kullanır. Hoca bu dili bilmeden bilim üretilemeyeceğini söyledi.

İkinci tanım: istatistik, verilerin toplanması (collecting), sınıflandırılması (classifying), sunulması (presenting) ve yorumlanması (interpreting) bilimidir.

### 8.2 Betimsel ve çıkarımsal istatistik

- **Betimsel istatistik (descriptive statistics):** Verinin nasıl toplanacağını, nasıl sunulacağını ve sayısal verinin nasıl betimleneceğini kapsar.
- **Çıkarımsal istatistik (inferential statistics):** Betimsel tekniklerden elde edilen değerleri yorumlar ve bunları karar vermek ve tahmin (estimation) yapmak için kullanır (ekrandan, 02:55:00).

### 8.3 Temel terimler

Ekrana yazılan temel terimler (ekrandan, 02:55:00 ve 03:00:00):

- **Popülasyon (population):** Özellikleri incelenecek bireyler, nesneler ya da ölçümler kümesi.
- **Örneklem (sample):** Popülasyonun bir alt kümesi.
- **Değişken (variable):** Bir popülasyonun ya da örneklemin her bir elemanıyla ilgili, ilgilenilen bir özellik.
- **Veri (data):** Değişken için popülasyonun ya da örneklemin her elemanından toplanan değerler kümesi.
- **Deney (experiment):** Sonuçları bir veri kümesi veren planlı bir etkinlik.
- **Parametre (parameter):** Tüm popülasyonun sayısal bir özelliği; genellikle Yunan harfleriyle gösterilir.
- **İstatistik (statistic):** Bir örneklemin sayısal bir özelliği; genellikle Latin harfleriyle gösterilir. Hoca bunun "istatistik teorisi" değil, tek bir sayısal büyüklük anlamındaki "statistic" olduğunu belirtti.

Hoca bu kavramları kümeler ve olasılık teorisiyle eşleştirdi:

| Kümeler teorisi | Olasılık teorisi | İstatistik |
|---|---|---|
| Evrensel küme | Örnek uzay | Popülasyon |
| Alt küme | Olay | Örneklem |

İstatistikte artık gerçek hayattan ölçümler yapılır; bu ölçümler örneklemi oluşturur. Değişken için verdiği örnek: bir sınıftaki öğrencilerin boyları incelenirse boy bir değişkendir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00 ve 00:15:00): 20 soruluk bir ara sınavda her soru 5 seçeneklidir ve sınava 100 öğrenci girmiştir. İki öğrencinin en az 5 soruyu aynı seçeneği işaretleyerek yanlış yapma olasılığı nedir? Bu olasılık çok çok küçükse olayın gerçekleşmesi hakkında yorumunuz nedir?

Derste yalnız kısa bir tartışma yapıldı. Bir öğrenci olasılığın %100'e çok yakın çıktığını söyledi. Hoca iki öğrencinin şık seçimlerinin ortak uzayının $5 \times 5 = 25$ elemanlı olduğunu, 100 öğrenciden 2'sinin $\binom{100}{2} = 4950$ biçimde seçilebileceğini ve 20 sorudan 5, 6, ..., 20'sinin seçimlerinin toplanacağını söyledi. Öğrenci tek bir soruda aynı şıkla yanlış yapma olasılığını $4/25 = 0.16$ bulduğunu belirtti. Ek soru üzerine hoca bütün şıkların eşit olasılıklı alınmasını söyledi: doğru cevabın herhangi bir şıkta olma olasılığı $1/5$'tir. Ayrıca Naive Bayes sınıflandırmasıyla öğrencilerin hata örüntülerine göre sınıflandırılabileceğini ekledi.

> **Çözüm (derste verilmedi):** Varsayım: her öğrenci her soruda 5 şıktan birini bağımsız ve eşit olasılıkla seçer (derste söylenen eşit olasılık varsayımı). Belirli iki öğrencinin bir soruda aynı yanlış şıkkı seçmesi için 4 yanlış şıktan birinde buluşmaları gerekir: $p = 4 \cdot \frac15 \cdot \frac15 = \frac{4}{25} = 0.16$. 20 soru bağımsız kabul edilirse bu iki öğrencinin aynı yanlış şıkla buluştuğu soru sayısı $X \sim \mathrm{Binomial}(20, 0.16)$ olur ve
> $$\Pr(X \ge 5) = \sum_{i=5}^{20} \binom{20}{i} (0.16)^i (0.84)^{20-i} \approx 0.206 .$$
> 100 öğrencideki $\binom{100}{2} = 4950$ çiftten en az birinde bu olayın görülme olasılığı ise (çiftler bağımsızmış gibi yaklaşık) $1 - (1 - 0.206)^{4950} \approx 1$'dir; beklenen çift sayısı $\approx 1019$'dur. Yani tamamen rastgele işaretleme modelinde olay hiç de küçük olasılıklı değildir; öğrencinin %100'e yakın sonucu bu modelle uyumludur. Olasılığın küçük çıkması için öğrencilerin çoğu soruyu bildiği, yalnız birkaç soruda tahmin yaptığı daha gerçekçi bir model gerekir. Böyle bir modelde olasılık çok küçük çıkıp olay yine de gözlenirse, bunun rastlantıyla açıklanması güçtür ve olay bir aykırılık olarak incelenmelidir. Sayılar python ile hesaplandı.

**Soru 2** (derste sözlü, 00:26:01): Üstel dağılımın PDF'inin altındaki toplam alan nedir?

$\int_0^\infty \lambda e^{-\lambda x}\,dx = \lambda \cdot \frac{1}{\lambda} = 1$.

**Soru 3** (derste sözlü, 00:27:24): Bilimde ve mühendislikte üstel dağılımı neden kullanırız?

Arıza ve bekleme sürelerini, yani "bir şey olana kadar ne kadar süre geçer?" sorusunu içeren deneyleri modellemek için. Anahtar kelime art arda (consecutive) iki olaydır.

**Soru 4** (derste sözlü, 00:54:38): Çok sayıda paralel evren varsa aralarındaki mesafenin üstel dağılımlı olduğunu neden söyleyebiliriz?

Art arda iki nadir olay (burada iki evren) arasındaki mesafe söz konusudur; nadir olaylar arasındaki süre ya da mesafe üstel dağılımla modellenir. $\lambda$, ortalama mesafenin tersidir (bkz. 2.6).

**Soru 5** (derste sözlü, 01:23:54): Gama dağılımının PDF'inde geçen $\Gamma(m)$ nedir? $0.78!$ nasıl hesaplanır?

$\Gamma(m) = \int_0^\infty x^{m-1}e^{-x}dx$ faktöriyelin gerçel sayılara genişletilmesidir; $0.78! = \Gamma(1.78) \approx 0.9262$ (değer python ile hesaplandı).

**Soru 6** (derste sözlü, 01:36:06): $m \to \infty$ iken gama dağılımının varyansı sıfıra gidiyor. Varyansın sıfır olması ne demektir?

$X$ hep aynı değeri ($\Omega$) alır, saçılma yoktur; $X$ bir sabite dönüşür. Hep aynı sonucu veren bir ölçümün varyansı sıfırdır.

**Soru 7** (ekrandan, 01:55:00): $N(\mu, \sigma^2)$ dağılımında $\mu - \sigma$'nın solunda kalan alan yaklaşık kaçtır?

Derste bir öğrenci $0.16$ dedi, hoca doğruladı. $\Phi(-1) \approx 0.1587$; ayrıca $\mu-\sigma$ ile $\mu$ arası $\approx 0.34$.

**Soru 8** (derste sözlü, 01:58:22): $X \sim N(\mu,\sigma^2)$ ve $Z = (X-\mu)/\sigma$ ise $Z$'nin ortalaması, varyansı ve dağılımı nedir?

$E[Z] = 0$, $\mathrm{Var}(Z) = 1$, $Z \sim N(0,1)$ (bkz. 5.4).

**Soru 9** (derste sözlü, 02:19:17): Teori nedir, teorem nedir?

Teorem ispatlanmış önermedir; teori teoremler kümesidir.

**Soru 10** (derste sözlü, 02:42:17): İstatistik nedir?

İstatistik bilimlerin evrensel dilidir; verilerin toplanması, sınıflandırılması, sunulması ve yorumlanması bilimidir.

## Dersin Toparlaması

Bu derste sürekli dağılımların üç temel üyesi işlendi. Üstel dağılım art arda iki olay arasındaki süreyi ya da mesafeyi modeller; ortalaması $1/\lambda$, varyansı $1/\lambda^2$'dir ve belleksizdir. Gama dağılımı, faktöriyelin genellemesi olan gama fonksiyonu üzerine kurulur; $m = 1$ için üstel dağılıma indirgenir, $m \to \infty$ için tek noktaya yığılır ve bağımsız özdeş üstellerin toplamının tam dağılımıdır. Normal dağılım ortalaması ve varyansıyla tamamen belirlenir; standartlaştırma ile her Gauss olasılığı standart normalin $\Phi$ fonksiyonuna ve tablolarına indirgenir.

Merkezi limit teoremi bu iki fikri birleştirir: bağımsız, aynı ortalama ve varyanslı çok sayıda değişkenin toplamı, $n \ge 30$ gibi yeterince büyük $n$ için yaklaşık $N(n\mu, n\sigma^2)$ dağılımlıdır. Tam dağılımı bilinen toplamlar (gama, negatif binom, binom) ayrıca not edildi. Dersin sonunda kitabın 8. bölümüyle istatistiğe geçildi ve popülasyon, örneklem, değişken, veri, deney, parametre ve istatistik kavramları tanımlandı. Bir sonraki derste istatistik konusuna devam edileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
