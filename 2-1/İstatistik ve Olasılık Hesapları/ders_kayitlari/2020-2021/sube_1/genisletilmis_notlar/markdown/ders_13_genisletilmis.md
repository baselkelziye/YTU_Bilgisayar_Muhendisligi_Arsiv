# Ders 13 Genişletilmiş Notu: Momentler Yöntemi, En Çok Olabilirlik Örnekleri ve Güven Aralıkları (Z Prosedürü)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: performans karşılaştırması ve olasılık-istatistiğin yeri
- 2. Momentler yöntemi
- 3. Kesikli bir dağılımda momentler yöntemi
- 4. Sürekli bir dağılımda momentler yöntemi ve en çok olabilirlik
- 5. Poisson dağılımı için en çok olabilirlik: banka örneği
- 6. Veriye uygun dağılımı seçmek
- 7. Z prosedürü tekrarı
- 8. Güven aralıkları
- 9. Ders kitabından örnek: %95 güven aralığı
- Örnek Sorular

## 1. Giriş: performans karşılaştırması ve olasılık-istatistiğin yeri

Bu kayıt dönemin son dersidir. Ders iPad üzerinde "BLM2011 Lecture Notes (2020 Fall)" başlıklı el yazısı not defteriyle, çoğunlukla İngilizce, yer yer Türkçe açıklamalarla yürütüldü. Ders kitabı olarak Baron'un *Probability and Statistics for Computer Scientists* kitabı ekranda açıldı.

Hoca dersi bir soruyla açtı. Bir öğrenci, bu dersteki yöntemlerin yeni geliştirilen bir sistemin değerlendirme (evaluation) aşamasında kullanılabileceğini söyledi. Hoca bunun üzerine şunu sordu:

**Soru:** Elinizde iki sistem var. Performanslarını karşılaştırmak için PDF mi kullanırsınız, CDF mi? **Cevap:** Önce tanımlar hatırlandı. CDF (cumulative distribution function) olasılıkların birikimli toplamıdır, yani bir aralıkta olma olasılığını verir. Bu yüzden iki sistemi karşılaştırmak için CDF kullanılır. CDF'i en hızlı 1'e giden sistemin performansı daha iyidir.

Hoca ardından, bilgisayar mühendisliği öğrencilerinin genelde teoriden uzak durduğunu ve bu yüzden makine öğrenmesi, yapay zeka gibi konularda zorlandığını söyledi. Matematik derslerinin yanında dört derse özellikle önem verilmesini önerdi: olasılık ve istatistik, hesaplama kuramı, işaret (sinyal) işleme, algoritmalar ve makine öğrenmesi. Ona göre bu derste öğrenilen olasılık-istatistik "denizde bir damla"dır; olasılık ve istatistik evrendeki olayları açıklamak için kullanılan bir dildir. Bu konular iyi bilinirse makine öğrenmesi, veri madenciliği, büyük veri ve yapay zekanın ileri konuları rahatça anlaşılır.

## 2. Momentler yöntemi

Hoca derse momentler yöntemiyle (method of moments, MoM) devam etti ve tanımı yeniden yazdı (ekrandan, 00:35:00):

> Momentler yöntemi, örneklem momentlerinin karşılık gelen popülasyon momentlerinin iyi tahminleri olduğu varsayımına dayanır.

Popülasyon momentleri birinci, ikinci, üçüncü, ..., $k$. momenttir:

$$\mu_1 = E[X],\quad \mu_2 = E[X^2],\quad \dots,\quad \mu_k = E[X^k].$$

Örneklem momentleri ise $N$ örneklemden hesaplanır:

$$m_1 = \frac{1}{N}\sum_{n=1}^{N} X_n,\quad m_2 = \frac{1}{N}\sum_{n=1}^{N} X_n^2,\quad \dots,\quad m_k = \frac{1}{N}\sum_{n=1}^{N} X_n^k.$$

Burada $X_1, X_2, \dots, X_N$, PDF'i bilinen biçimde olan ama parametreleri bilinmeyen bir popülasyondan alınmış örneklemlerdir. Her örneklem momenti, karşılık gelen popülasyon momentinin iyi bir tahmini kabul edilir. Bu ifadeler birbirine eşitlenir ve popülasyonun parametreleri bulunur.

## 3. Kesikli bir dağılımda momentler yöntemi

### 3.1 Problem

Hoca örneği tahtaya şöyle yazdı (ekrandan, 00:40:00 ve 00:45:00): Bir sistemin kesikli girdisi $X$ için istatistiksel bir model geliştirmeye çalışıyoruz. $X$ kesikli bir rastgele değişkendir ve olasılık kütle fonksiyonu (PMF) şöyledir:

| $x_k$ | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| $P(X=x_k)$ | $\frac{2\theta}{3}$ | $\frac{\theta}{3}$ | $\frac{2(1-\theta)}{3}$ | $\frac{1-\theta}{3}$ |

Burada $0\le\theta\le1$ kestirilecek parametredir. Bu dağılımdan 10 bağımsız gözlem (örneklem) alınmıştır:

$$S = (3, 0, 2, 1, 3, 2, 1, 0, 2, 1).$$

İstenen: $\theta$'yı momentler yöntemiyle, dağılım örnekleme uyacak biçimde kestirmek.

Hoca sezgiyi şöyle anlattı: $X$'i ölçüyorsunuz, 3 çıkıyor; tekrar ölçüyorsunuz, 0 çıkıyor; sonra 2, 1, 3, 2, 1, 0, 2, 1. Bu girdiler bu PMF'e sahipse $\theta$'nın değeri ne olmalıdır?

### 3.2 Çözüm

PMF'te tek bilinmeyen parametre vardır: $\theta$. Bir bilinmeyen için bir denklem yeter. Bu yüzden yalnız birinci örneklem momenti ile birinci popülasyon momenti eşitlenir:

$$\frac{1}{N}\sum_{n=1}^{N} X_n = E[X].$$

**Örneklem ortalaması.** $N=10$. Hoca toplamı tahtada $16$ yazdı ve örneklem ortalamasını $16/10$ buldu (ekrandan, 00:50:00). Bir öğrenci toplamın 15 olduğunu söyledi. Hoca da sayıp 15 buldu, sonra değerlerden birini 1 yaparak toplamı 16'da bıraktı. <!-- BELİRSİZ: hangi gözlemin değiştirildiği karelerden okunmuyor; tahtadaki liste değişmeden kaldı. -->

**Popülasyon ortalaması.** Tanıma göre $E[X]=\sum_{x_k} x_k\,P(X=x_k)$:

$$E[X] = 0\cdot\frac{2\theta}{3} + 1\cdot\frac{\theta}{3} + 2\cdot\frac{2(1-\theta)}{3} + 3\cdot\frac{1-\theta}{3} = \frac{\theta}{3} + \frac{4(1-\theta)}{3} + \frac{3(1-\theta)}{3} = \frac{7-6\theta}{3}.$$

**Eşitleme.** Örneklem ortalaması popülasyon ortalamasının iyi bir kestiricisi kabul edildiği için ikisi eşit olmalıdır (ekrandan, 00:55:00):

$$\frac{16}{10} = \frac{7-6\theta}{3} \quad\Rightarrow\quad 48 = 70 - 60\theta.$$

Hoca buradan $\theta = 2/3$ yazdı ve PMF'i $\theta=2/3$ ile şöyle doldurdu: $P(X=0)=4/9$, $P(X=1)=2/9$, $P(X=2)=2/9$, $P(X=3)=1/9$.

> **Ders sonrası not:** $48 = 70 - 60\theta$ denkleminden $60\theta = 22$, yani $\theta = 11/30 \approx 0.367$ çıkar; hoca "20 bölü 30" diyerek $2/3$ buldu. Sağlama: $\theta = 2/3$ için $E[X] = (7-4)/3 = 1$ olur, örneklem ortalaması $1.6$ değildir. Doğru değerle PMF $11/45,\ 11/90,\ 19/45,\ 19/90$ olur. Ayrıca listedeki gerçek toplam 15 alınırsa $1.5 = \frac{7-6\theta}{3}$ ve $\theta = 5/12 \approx 0.417$ çıkar; PMF $5/18,\ 5/36,\ 7/18,\ 7/36$ olur. Her iki değer de $0\le\theta\le1$ koşulunu sağlar (python ile doğrulandı).

### 3.3 Yöntemin gerçek hayatta kullanımı

Hoca yöntemi Türkçe olarak şöyle özetledi. Gerçek hayatta önce verinin dağılımına bakılır ve hangi dağılıma benzediğine karar verilir. Bu dağılımın kaç parametresi olduğu bulunur; örneğin üç. Verinin birinci, ikinci ve üçüncü örneklem momentleri hesaplanır ve birinci, ikinci, üçüncü popülasyon momentlerine eşitlenir. Üç bilinmeyenli üç denklem çözülünce seçilen PDF'in bütün parametreleri bulunmuş olur.

## 4. Sürekli bir dağılımda momentler yöntemi ve en çok olabilirlik

### 4.1 Problem

Hoca ikinci örneği yazdı (ekrandan, 01:00:00): PDF

$$f_X(x) = \begin{cases} c\,(1+\theta x), & -1\le x\le 1 \\ 0, & \text{aksi halde} \end{cases}$$

olarak verilmiştir.

- a) $f_X(x)$'in bir PDF olması için $c$ sabitinin değerini bulun.
- b) $\theta$'nın kestiricisini bulun.

### 4.2 Sabitin bulunması

Bilinmeyenler $c$ ve $\theta$'dır, ama $c$ normalleştirme koşulundan bulunur. PDF'in integrali 1 olmalıdır:

$$\int_{-\infty}^{+\infty} f_X(x)\,dx = \int_{-1}^{1} c(1+\theta x)\,dx = \left[cx + c\theta\frac{x^2}{2}\right]_{-1}^{1} = 1.$$

Sınırlar yerine konunca $\left(c + \frac{c\theta}{2}\right) - \left(-c + \frac{c\theta}{2}\right) = 2c = 1$, yani $c = \tfrac12$. PDF:

$$f_X(x) = \tfrac12(1+\theta x),\quad -1\le x\le 1.$$

> **Ek bilgi (derste anlatılmadı):** $f_X(x)$'in bütün aralıkta negatif olmaması için $|\theta|\le1$ olmalıdır; aksi halde aralığın bir ucunda $1+\theta x<0$ olur.

### 4.3 Momentler yöntemiyle kestirici

Tek bilinmeyen $\theta$ olduğu için birinci moment yeter. Popülasyon ortalaması:

$$E[X] = \int_{-1}^{1} x\cdot\tfrac12(1+\theta x)\,dx = \int_{-1}^{1}\left(\frac{x}{2} + \frac{\theta}{2}x^2\right)dx = \left[\frac{x^2}{4} + \frac{\theta x^3}{6}\right]_{-1}^{1} = \frac{\theta}{3}.$$

Bu, örneklem ortalamasına eşitlenir: $\frac{\theta}{3} = \frac{1}{N}\sum_{i=1}^{N} X_i$. Hoca kestiriciyi tahtada şöyle yazdı (ekrandan, 01:05:00):

$$\hat\theta = \frac{1}{3N}\sum_{i=1}^{N} X_i.$$

Sonra kestiricinin yanlı (biased) mı yansız (unbiased) mı olduğuna baktı: $E[\hat\theta] - \theta$ hesaplanır; sabit beklenen değerin dışına alınır ve geriye örneklem ortalamasının beklenen değeri kalır. $\bar X$ her zaman yansız bir kestirici olduğu için hoca yanlılığın sıfır olduğu sonucuna vardı.

> **Ders sonrası not:** $\frac{\theta}{3} = \bar X$ eşitliğinden $\hat\theta = 3\bar X = \frac{3}{N}\sum X_i$ çıkar; tahtadaki $\frac{1}{3N}\sum X_i$ yanlıştır. Doğru kestirici yansızdır: $E[\hat\theta] = 3E[\bar X] = 3\cdot\frac{\theta}{3} = \theta$. Tahtadaki biçim kullanılsaydı $E[\hat\theta] = \theta/9$ olurdu ve kestirici yanlı çıkardı.

### 4.4 En çok olabilirlik kestiricisi (iki örneklem)

Bir öğrenci aynı PDF için en çok olabilirlik (maximum likelihood, ML) kestiricisini sordu. Hoca problemi şöyle yazdı (ekrandan, 01:10:00): İki örneklemimiz olsun, $S = (X_1, X_2)$. $\theta$ için en çok olabilirlik kestiricisini bulun.

**Olabilirlik.** İki örneklemin olasılıkları çarpılır:

$$L(\theta) = \prod_{n=1}^{2} f_X(X_n) = \tfrac12(1+\theta X_1)\cdot\tfrac12(1+\theta X_2).$$

**Logaritma.** Logaritma çarpımları toplama çevirir:

$$\log L(\theta) = \log\tfrac14 + \log(1+\theta X_1) + \log(1+\theta X_2).$$

**Türev.** $\theta$'ya göre türev alınır. Sabit terimin türevi sıfırdır. $\log u$'nun türevi $\frac{u'}{u}$ olduğu için:

$$\frac{\partial}{\partial\theta}\log L = \frac{X_1}{1+\theta X_1} + \frac{X_2}{1+\theta X_2} = 0.$$

Maksimum noktasında türev sıfırdır. Kestirici bu denklemin çözümüdür (ekrandan, 01:15:00). Paydalar eşitlenir:

$$\frac{X_1(1+\theta X_2) + X_2(1+\theta X_1)}{(1+\theta X_1)(1+\theta X_2)} = 0 \;\Rightarrow\; X_1 + \theta X_1X_2 + X_2 + \theta X_1X_2 = 0.$$

$\theta$ parantezine iki terim gelir: $\theta\cdot 2X_1X_2 = -(X_1+X_2)$. Sonuç (ekrandan, 01:50:00):

$$\hat\theta = -\frac{X_1+X_2}{2X_1X_2}.$$

Hoca $N$ örneklem olsaydı aynı yolun izleneceğini, ama denklemin zorlaşacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** $N$ örneklemde denklem $\sum_{n=1}^{N}\frac{X_n}{1+\theta X_n}=0$ olur ve genelde kapalı biçimde çözülmez; sayısal yöntemle çözülür. Bulunan değer $|\theta|\le1$ aralığının dışına düşerse kestirici aralığın en yakın ucuna çekilir.

### 4.5 Logaritmanın tabanı

**Soru:** Türev alırken logaritmanın tabanı 10 değil midir, $\ln$ yazmak gerekmez mi? **Cevap:** Hoca matematikte $\log$ yazıldığında e tabanının kastedildiğini söyledi ve tahtaya şunu yazdı (ekrandan, 01:50:00):

$$\log(x) = \log_e(x), \qquad \log_{10}(x) = \frac{\log(x)}{\log(10)}.$$

Hoca 10 tabanını $\log$ diye, e tabanını $\ln$ diye yazma alışkanlığının makale okurken kafa karıştırdığını söyledi.

### 4.6 Neden maksimum?

Hoca, "aptalca soru" diye bir şey olmadığını, her sorunun bir anlamı olduğunu vurguladıktan sonra bir öğrencinin sorusunu aldı.

**Soru:** Türevi sıfıra eşitleyip $\theta$'yı bulduk. Bu noktanın popülasyonu en iyi kestirdiğinden nasıl emin oluyoruz, neden minimumu değil de maksimumu arıyoruz? **Cevap:** Hoca olabilirliği maksimum yapmanın entropiyi minimum yaptığını söyledi. Entropi bilinmeyenin miktarıdır; entropinin minimum olması belirsizliğin azalması demektir. Öyle bir $\theta$ değeri bulunur ki veriye en iyi uyar.

> **Ders sonrası not:** Hoca log-olabilirliğe derste "entropi" ya da "negatif entropi" dedi. Daha doğru ifade şudur: ortalama log-olabilirliği maksimum yapmak, verinin deneysel dağılımı ile model dağılımı arasındaki çapraz entropiyi (eşdeğer olarak KL ıraksamasını) minimum yapmaktır. Türevin sıfır olduğu noktanın gerçekten maksimum olduğu ikinci türevle ya da fonksiyonun biçimiyle kontrol edilir.

## 5. Poisson dağılımı için en çok olabilirlik: banka örneği

### 5.1 Model

Aradan sonra hoca Poisson dağılımıyla bir örnek yaptı. Poisson dağılımı kesiklidir ve $0, 1, 2, \dots$ sonsuza kadar giden değerleri alır. PMF:

$$P(X = k) = \frac{\lambda^k}{k!}e^{-\lambda},\quad k = 0, 1, 2, \dots$$

Uygulama olarak bir banka düşünüldü (ekrandan, 01:35:00). Bankaya insanlar geliyor ve belirli zaman aralıklarında gelen müşteri sayısı ölçülüyor. Ölçümler:

| Aralık | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|
| Müşteri sayısı | 0 | 5 | 1 | 0 | 6 |

Bunlar, belirtilen zaman aralığında bankaya gelen müşterilerin sayılarıdır. Bu veri Poisson dağılımlı kabul edilirse $\lambda$ ne olur? $\lambda$ bilinirse bankaya gelen müşteri sayısı gerçekçi biçimde modellenmiş olur.

### 5.2 Kestiricinin türetilmesi

$k_1, k_2, \dots, k_N$ örneklemlerinden $\lambda$ kestirilecek. Olabilirlik:

$$L(\lambda) = \prod_{n=1}^{N} P(X = k_n) = \frac{\lambda^{k_1}}{k_1!}e^{-\lambda}\cdot\frac{\lambda^{k_2}}{k_2!}e^{-\lambda}\cdots\frac{\lambda^{k_N}}{k_N!}e^{-\lambda} = \frac{\lambda^{k_1+k_2+\dots+k_N}}{k_1!\,k_2!\cdots k_N!}e^{-N\lambda}.$$

Doğrudan bu ifadenin değil, logaritmasının türevi alınır (ekrandan, 01:40:00):

$$\log L(\lambda) = \left(\sum_{n=1}^{N} k_n\right)\log\lambda - \log(k_1!\,k_2!\cdots k_N!) - N\lambda.$$

$\lambda$'ya göre türev alınıp sıfıra eşitlenir:

$$\frac{\partial}{\partial\lambda}\log L = \frac{1}{\lambda}\sum_{n=1}^{N} k_n - N = 0 \;\Rightarrow\; \hat\lambda = \frac{1}{N}\sum_{n=1}^{N} k_n.$$

### 5.3 Sayısal sonuç

Beş ölçüm için:

$$\hat\lambda = \frac{1}{5}(0 + 5 + 1 + 0 + 6) = \frac{12}{5} = 2.4.$$

Bu $\lambda$ ile rastgele sayı üretilirse bankaya gelen müşterilerin simülasyonu yapılmış olur.

## 6. Veriye uygun dağılımı seçmek

**Soru:** Veri setimiz bu dağılımlardan birine uymak zorunda mı, uymazsa ne yapıyoruz? Örneğin iki tepe noktalı bir veri setimiz olabilir. **Cevap:** Hoca önce verinin histogramına bakıldığını hatırlattı. Önceki derslerin not sayfaları ekranda gösterildi (ekrandan, 01:45:00): histogram üstel dağılıma benziyorsa $f_X(x) = \frac{1}{\lambda}\exp\left(-\frac{x}{\lambda}\right)$, $0<x<\infty$ seçilir ve "bu histogramın ait olduğu veri için $\lambda$ nedir?" sorusu sorulur. Histogram gama dağılımına benziyorsa

$$f_X(x) = \frac{1}{\Gamma(m)}\left(\frac{m}{\Omega}\right)^m x^{m-1}\exp\left(-\frac{m}{\Omega}x\right)$$

seçilir ve $m$ ile $\Omega$ veriden kestirilir. Gauss'a benziyorsa bilinmeyenler $\mu$ ve $\sigma$'dır.

Hoca bir veri bir dağılıma uymuyorsa başka birine uyacağını, her veri setine uygun bir dağılımın her zaman bulunduğunu söyledi. Bunu göstermek için ekranda beş parametreli genel bir dağılım ailesi gösterdi. Rayleigh, Maxwell, yarı normal, üstel, Weibull, Nakagami-m ve gama dağılımları bu ailenin özel halleridir. Böyle çok parametreli bir dağılım hemen her veriye uyar. Ama parametre sayısı büyüdükçe teorik hesaplar ağırlaşır: momentler yöntemiyle beş parametre için beş denklem gerekir, en çok olabilirlik daha da zordur. Bu yüzden parametre sayısını küçük tutmak önemlidir.

Sonuç olarak süreç şudur: veri toplanır, histograma bakılır, benzediği dağılım seçilir (gama, üstel, Gauss gibi). Seçilen dağılımın parametreleri (Gauss için $\mu$ ve $\sigma^2$, üstel için $\lambda$, gama için $m$ ve $\Omega$) veriden kestiriciler ile bulunur. Kestirici formülleri de bu derste gösterilen yollarla (momentler yöntemi, en çok olabilirlik) elde edilir. Böylece elde teorik bir ifade olur: PDF ve parametreleri bilinince moment, varyans ve olasılıklar hesaplanabilir, makine öğrenmesi algoritmalarında kullanılabilir.

> **Ek bilgi (derste anlatılmadı):** İki tepeli (bimodal) veriler için sık kullanılan bir yol, iki dağılımın ağırlıklı toplamı olan karışım (mixture) modelleridir; örneğin iki Gauss bileşenli karışım.

## 7. Z prosedürü tekrarı

Hoca bir önceki derste başlanan Z prosedürünü Türkçe olarak hızlıca tekrar etti.

### 7.1 Kurulum

$Z$ ortalaması 0, varyansı 1 olan normal (Gauss) bir rastgele değişkendir: $E[Z]=0$, $\mathrm{Var}(Z)=1$. Buna standart normal dağılım denir.

Bir $X$ popülasyonu verilsin. Popülasyonun standart sapması $\sigma$ (dolayısıyla varyansı $\sigma^2 = \mathrm{Var}(X)$) bilinsin, ama ortalamasının ne olduğu hakkında hiçbir fikrimiz olmasın (ekrandan, 01:55:00). Ortalama veriden bulunacaktır. Veri $S = (X_1, X_2, \dots, X_n)$, örneklem büyüklüğü $|S| = n$. Örneklem ortalaması

$$\bar X = \frac{1}{n}\sum_{i=1}^{n} X_i$$

kestirilen değerdir; $\sigma$ ise popülasyonun gerçek (bilinen) standart sapmasıdır.

### 7.2 $\bar X$ bir rastgele değişkendir

Popülasyonun gerçek ortalaması $\mu$ zamanla değişmez. Ama kestirilen $\bar X$ değişir. Hoca bunu boy ortalamasıyla anlattı. Bir ülkedeki erkeklerin boy ortalaması gerçekten bir sabit sayıdır: bütün insanların boyları toplanıp nüfusa bölünürse bu sayı bulunur. Ama farklı şehirlerden bin kişilik örneklemler alınınca her seferinde farklı bir $\bar X$ çıkar. Yani $\bar X$ bir rastgele değişkendir. Hoca tahtaya kırmızıyla şunu yazdı (ekrandan, 02:00:00):

$$\lim_{n\to\infty}\bar X = \mu.$$

**Soru:** $\bar X$'in histogramı neden Gauss'a gider? **Cevap (bir öğrenci):** Merkezi limit teoreminden. Hoca bunu onayladı: rastgele sayıların toplamı merkezi limit teoremine göre yaklaşık Gauss dağılımlıdır, dolayısıyla ortalama da yaklaşık Gauss'tur.

### 7.3 Z-skoru

Gerçek ortalama $\mu$'nün kestiriminin Z-skoru (yani örneklem ortalamasının Z-skoru) standart normal dağılıma uyar (ekrandan, 02:00:00):

$$Z = \frac{\bar X - \mu_{\bar X}}{\sigma_{\bar X}} = \frac{\bar X - \mu}{\sqrt{\sigma^2/n}} = \frac{(\bar X - \mu)\sqrt n}{\sigma}, \qquad f_Z(z) = \frac{1}{\sqrt{2\pi}}\exp\left(-\frac{z^2}{2}\right),\ -\infty<z<\infty.$$

Burada $\mu_{\bar X}$ örneklem ortalamasının beklenen değeri, $\sigma_{\bar X}$ örneklem ortalamasının standart sapmasıdır. CDF ise önceki derslerde görülen Q fonksiyonu cinsinden yazılır.

Örneklem ortalamasının beklenen değeri $\mu$'dür, dolayısıyla $\bar X$ yansız bir kestiricidir. Varyansı:

$$\mathrm{Var}(\bar X) = \frac{\sigma^2}{n}.$$

> **Hocanın vurgusu:** Örneklem ortalamasının varyansı $\sigma^2/n$'dir; $\sigma^2$ popülasyonun varyansı, $n$ örneklem sayısıdır. Bu, bir bakıma yapılan hatanın varyansıdır.

### 7.4 Z aralıkları

Kritik nokta $z_\alpha>0$, standart normal tablosundan $P(Z > z_\alpha) = \alpha$ olacak biçimde okunur (ekrandan, 02:05:00). İki tek taraflı Z aralığı vardır:

$$\left(-\infty,\ \bar X + \frac{\sigma}{\sqrt n}z_\alpha\right), \qquad \left(\bar X - \frac{\sigma}{\sqrt n}z_\alpha,\ \infty\right).$$

İki taraflı Z aralığı:

$$\left(\bar X - \frac{\sigma}{\sqrt n}z_{\alpha/2},\ \bar X + \frac{\sigma}{\sqrt n}z_{\alpha/2}\right).$$

Hoca bunu $\bar X$'in histogramı üzerinde anlattı. $\bar X$ rastgele olduğu için hesaplanan aralık bazen $\mu$'nün solunda, bazen sağında kalır. Tek taraflı aralıkta soru, kestirilen ifadenin yüzde kaç olasılıkla $\mu$'nün bir tarafında kaldığıdır. İki taraflı aralıkta ise kestirimin bu iki sınır arasında olma olasılığına bakılır. Böylece kestiricinin performansı ölçülür ve kestiriciler karşılaştırılır. Bu olasılıklar CDF ile kolayca bulunur.

## 8. Güven aralıkları

### 8.1 Tanım

Hoca tanımı ders kitabından aynen yazdı (ekrandan, 02:20:00): Bir $[a, b]$ aralığı, $\theta$ parametresini $1-\alpha$ olasılıkla içeriyorsa, yani

$$P(a \le \theta \le b) = 1 - \alpha$$

ise, $\theta$ için bir $(1-\alpha)100\%$ güven aralığıdır (confidence interval). Kapsama olasılığı (coverage probability) $1-\alpha$'ya güven düzeyi (confidence level) de denir.

Hoca anlamını şöyle açıkladı. $\theta$'yı kestirdik; $\theta$'nın $a$ ile $b$ arasında olma olasılığı $1-\alpha$'dır. Bu sayı kestirimin ne kadar güvenilir olduğunu söyler; 1'e ne kadar yakınsa o kadar güvenilirdir. $\alpha = 0$ ise $1-\alpha = 1$ olur ve $\theta$ kesinlikle $a$ ile $b$ arasındadır. $\alpha = 0.1$ ise $1-\alpha = 0.9$ olur; kestirim %90 olasılıkla doğrudur.

Kitaptaki "parametre $\theta$ için güven aralıkları ve kapsama" şekli üzerinden: aynı parametre her kestirildiğinde farklı bir aralık çıkar, çünkü kestirici rastgele değişir. Kestiricinin varyansı küçüktür; bütün aralıkların ortalaması alınırsa kestiricinin aralığı bulunmuş olur.

> **Ders sonrası not:** Hoca burada aralıkların ortalamasından söz etti. Kitaptaki şeklin anlamı büyük olasılıkla şudur: deney çok kez tekrarlanırsa, oluşturulan aralıkların yaklaşık $(1-\alpha)$ oranı gerçek $\theta$'yı kapsar. Tek bir aralık için olasılık, parametrenin değil, aralığın rastgeleliğinden gelir.

### 8.2 Genel yapım yöntemi

Kitabın 9.2.1 bölümü ekranda gösterildi (ekrandan, 02:25:00): Bir veri örneklemi ve istenen bir güven düzeyi $(1-\alpha)$ verildiğinde, kapsama koşulunu $P\{a\le\theta\le b\} = 1-\alpha$ sağlayan $[a, b]$ nasıl kurulur? Önce $\theta$ kestirilir. Normal dağılımlı yansız bir $\hat\theta$ kestiricisi olduğu varsayılır. Standartlaştırılınca standart normal bir değişken elde edilir:

$$Z = \frac{\hat\theta - E(\hat\theta)}{\sigma(\hat\theta)} = \frac{\hat\theta - \theta}{\sigma(\hat\theta)}.$$

Burada $\hat\theta$ yansız olduğu için $E(\hat\theta) = \theta$'dır. $\sigma(\hat\theta)$ ise kestiricinin standart hatasıdır (standard error).

Hoca yine boy örneğini kullandı: farklı semtlerden bin kişilik gruplar seçilip boy ortalamasına bakılırsa her grup için farklı bir değer çıkar; $\hat\theta$ bir rastgele değişken gibi davranır. Paydaki fark ortalaması sıfır olan bir rastgele değişkendir, paydadaki ise kestirilen değerin standart sapmasıdır.

### 8.3 $z_{\alpha/2}$'nin bulunması

Standart normal PDF üzerinde iki nokta işaretlendi: $-z_{\alpha/2}$ ve $z_{\alpha/2}$ (ekrandan, 02:50:00). Ortadaki alan $1-\alpha$, iki kuyruğun her biri $\alpha/2$'dir. Toplam alan 1 olduğu için:

$$F_Z(z_{\alpha/2}) = \frac{\alpha}{2} + (1-\alpha) = 1 - \frac{\alpha}{2}, \qquad F_Z(-z_{\alpha/2}) = \frac{\alpha}{2}.$$

CDF biliniyorsa tersi alınarak (ekrandan, 02:35:00):

$$z_{\alpha/2} = F_Z^{-1}\left(1 - \frac{\alpha}{2}\right).$$

### 8.4 Aralığın türetilmesi

$P(-z_{\alpha/2} < Z < z_{\alpha/2}) = 1-\alpha$ ifadesinde $Z = \frac{\bar X - \mu}{\sigma/\sqrt n}$ yazılır (ekrandan, 02:35:00):

$$P\left(-z_{\alpha/2} < \frac{\bar X - \mu}{\sigma/\sqrt n} < z_{\alpha/2}\right) = P\left(-\frac{\sigma}{\sqrt n}z_{\alpha/2} < \bar X - \mu < \frac{\sigma}{\sqrt n}z_{\alpha/2}\right) = 1-\alpha.$$

$\mu$ eşitsizliğin iki yanına atılınca hoca şunu yazdı (ekrandan, 02:40:00):

$$P(a < \bar X < b) = 1-\alpha, \qquad (a, b) = \left(\mu - \frac{\sigma}{\sqrt n}z_{\alpha/2},\ \mu + \frac{\sigma}{\sqrt n}z_{\alpha/2}\right).$$

Bu aralığa güven aralığı, yönteme de Z prosedürü (Z-procedure) dedi. Hoca adın, yöntemin $Z$ kullanılarak kurulmasından geldiğini söyledi. Yorum şöyledir: ölçüm yapılır, $\bar X$ aralığın içinde çıkar; tekrar ölçülür, yine içinde çıkar; bazen dışında çıkabilir. Hesaplanan $\bar X$ $1-\alpha$ olasılıkla bu aralığın içindedir.

> **Ders sonrası not:** Tahtadaki aralık $\bar X$'in $\mu$ etrafında düştüğü aralıktır. $\mu$ bilinmediği için güven aralığı olarak kullanılan biçim, aynı eşitsizliğin $\mu$ için çözülmüş halidir: $\left(\bar X - \frac{\sigma}{\sqrt n}z_{\alpha/2},\ \bar X + \frac{\sigma}{\sqrt n}z_{\alpha/2}\right)$. Bu biçim hem hocanın bir önceki not sayfasında (ekrandan, 02:05:00) hem de kitap örneğinde (bölüm 9) kullanılır.

**Soru:** $\alpha$ nasıl belirleniyor? **Cevap:** $\alpha$'yı kullanıcı belirler. $\alpha = 0.1$ denirse değerin %90 olasılıkla bu aralıkta olduğu söylenir. $\alpha$ küçüldükçe aralık genişler.

**Soru:** Elimizdeki örneklemlerin yarısı $1-\alpha$ ile gösterilen alanın içine, yarısı dışına düşerse bu ne demektir? **Cevap:** O aralık için olasılık 0.5 demektir, yani $1-\alpha = 0.5$; buna karşılık gelen $z_\alpha$ değeri bulunabilir.

## 9. Ders kitabından örnek: %95 güven aralığı

### 9.1 Problem

Hoca örneği kitaptan yazdı (ekrandan, 02:45:00 ve 03:00:00): Ölçümlerden oluşan şu örnekleme dayanarak popülasyon ortalaması için %95 güven aralığı kurun:

$$2.5,\ 7.4,\ 8.0,\ 4.5,\ 7.4,\ 9.2.$$

Ölçüm hataları normal dağılımlıdır ve ölçüm cihazı $\sigma = 2.2$ standart sapmayı garanti etmektedir.

Hoca burada ondalık ayırıcıya değindi. Aynı sayılar virgülle yazılırsa ("2,5, 7,4, 8,0, 4,5, 7,4, 9,2") liste tek bir sayı ya da tam sayılar dizisi gibi okunur. Ona göre matematikte ondalık ayırıcı olarak nokta kullanılmalıdır, çünkü gösterim karışıklığa yol açar.

### 9.2 Çözüm

- Örneklem büyüklüğü $n = 6$.
- Örneklem ortalaması $\bar X = \frac{1}{6}(2.5+7.4+8.0+4.5+7.4+9.2) = \frac{39}{6} = 6.5$.
- Güven düzeyi $1-\alpha = 0.95$, dolayısıyla $\alpha = 0.05$ ve $\alpha/2 = 0.025$.
- Aranan kantiller $q_{0.025} = -z_{0.025}$ ve $q_{0.975} = z_{0.025}$.
- Ters CDF kapalı biçimde olmayabilir; o zaman birçok girdi değeri için çıktıyı gösteren tablo kullanılır (ekrandan, 02:55:00). Tablodan $z_{0.025} = 1.96$.
- Aralık:

$$\bar X \pm z_{\alpha/2}\frac{\sigma}{\sqrt n} = 6.50 \pm (1.960)\frac{2.2}{\sqrt6} = 6.50 \pm 1.76 \quad\text{ya da}\quad [4.74,\ 8.26].$$

Python ile kontrol: $z_{0.025} = 1.95996$, yarı genişlik $1.7603$, aralık $[4.740,\ 8.260]$. Kitap sayfasında, örneklem küçük ve verinin dağılımı normal değilse bu yöntemin uygulanamadığı da belirtiliyordu (ekrandan, 03:00:00).

Hoca kitaptaki standart normal tablosunu da gösterdi: $z = 0$ iken CDF değeri $0.5$'tir, $z$ arttıkça olasılık artar, $z \approx 3.9$ civarında yaklaşık 1 olur. İlgili olasılıklar tablodan okunur.

### 9.3 Güven düzeyi ve aralık genişliği

Hoca önce %90 aralığının daha geniş olacağını söyledi, sonra öğrencileri sınamak için böyle dediğini belirterek soruyu açtı:

**Soru:** Aralığı büyütürsem o aralıkta olma olasılığı artar mı, azalır mı? **Cevap:** Artar. Aralık küçültülürse olasılık azalır. Dolayısıyla %90 aralığı %95 aralığından daha dardır.

> **Ders sonrası not:** Aynı veriyle %90 güven aralığı $z_{0.05} \approx 1.645$ ile $6.5 \pm 1.48$, yani yaklaşık $[5.02,\ 7.98]$ olur; %95 aralığı $[4.74,\ 8.26]$'dan dardır (python ile hesaplandı).

Hoca sezgiyi bir tahmin örneğiyle bağladı: kimliği belli olmayan bir sosyal medya yorumunun kimin tarafından yazıldığı sorulsa, kesin bir cevap yerine "%80 şu kişi, %90 bu kişi" gibi olasılıkla cevap verilir. Güven aralığı da böyledir: $\bar X$ bizim tahminimizdir ve bu tahmin %95 olasılıkla belirli bir aralıktadır. Aralık çok geniş tutulursa olasılık %100 olur, ama önemli olan aralığın verdiği güvendir. Örneğin 4 birimlik bir fark sizin için kabul edilebilirse ve algoritma sonucu %95 olasılıkla $4.74$ ile $8.26$ arasında üretiyorsa, bu sonuca %95 güvenebilirsiniz.

> **Ders sonrası not:** Hoca bu kısımda bir yerde aralığı "4.74 ile 8.74" diye söyledi; doğrusu $[4.74,\ 8.26]$'dır.

## Örnek Sorular

### Soru 1 (ekrandan, 00:45:00)

Kesikli $X$'in PMF'i $P(X=0)=\frac{2\theta}{3}$, $P(X=1)=\frac{\theta}{3}$, $P(X=2)=\frac{2(1-\theta)}{3}$, $P(X=3)=\frac{1-\theta}{3}$, $0\le\theta\le1$. Bu dağılımdan alınan 10 bağımsız gözlem $S=(3,0,2,1,3,2,1,0,2,1)$. $\theta$'yı momentler yöntemiyle kestirin.

> **Çözüm (derste verildi, düzeltilmiş):** $E[X]=\frac{7-6\theta}{3}$. Gözlemlerin toplamı 15, $\bar X = 1.5$. $1.5 = \frac{7-6\theta}{3}$ ise $\hat\theta = 5/12 \approx 0.417$. Derste toplam 16 alınıp $48 = 70-60\theta$ yazıldı; bu denklemin çözümü $11/30$'dur. Tahtada yazılan $2/3$ ise aritmetik hatadır (bkz. bölüm 3.2).

### Soru 2 (ekrandan, 01:00:00)

$f_X(x) = c(1+\theta x)$, $-1\le x\le1$, aksi halde 0. a) $c$'yi bulun. b) $\theta$'nın kestiricisini bulun.

> **Çözüm (derste verildi, düzeltilmiş):** a) $\int_{-1}^{1}c(1+\theta x)\,dx = 2c = 1$, $c = \tfrac12$. b) $E[X] = \theta/3$; momentler yöntemiyle $\hat\theta = 3\bar X = \frac{3}{N}\sum X_i$. Bu kestirici yansızdır: $E[\hat\theta]=\theta$.

### Soru 3 (ekrandan, 01:10:00)

Aynı PDF'ten iki örneklem $S=(X_1, X_2)$ alınmıştır. $\theta$ için en çok olabilirlik kestiricisini bulun.

> **Çözüm (derste verildi):** $\log L = \log\tfrac14 + \log(1+\theta X_1) + \log(1+\theta X_2)$; türev sıfıra eşitlenince $X_1 + X_2 + 2\theta X_1X_2 = 0$, $\hat\theta = -\frac{X_1+X_2}{2X_1X_2}$.

### Soru 4 (ekrandan, 01:35:00)

Bankaya beş zaman aralığında gelen müşteri sayıları $0, 5, 1, 0, 6$'dır. Veri Poisson($\lambda$) dağılımlı kabul edilirse $\lambda$'nın en çok olabilirlik kestirimi nedir?

> **Çözüm (derste verildi):** $\hat\lambda = \frac1N\sum k_n = \frac{12}{5} = 2.4$.

### Soru 5 (derste sözlü, 00:09:51)

İki sistemin performansını karşılaştırmak için PDF mi, CDF mi kullanılır?

> **Çözüm (derste verildi):** CDF. CDF bir aralıkta olma olasılığını verir; CDF'i daha hızlı 1'e giden sistemin performansı daha iyidir.

### Soru 6 (ekrandan, 02:45:00)

Ölçümler $2.5, 7.4, 8.0, 4.5, 7.4, 9.2$; ölçüm hataları normal dağılımlı ve $\sigma = 2.2$. Popülasyon ortalaması için %95 güven aralığı kurun.

> **Çözüm (derste verildi):** $n=6$, $\bar X = 6.5$, $z_{0.025} = 1.96$, $6.5 \pm 1.96\cdot\frac{2.2}{\sqrt6} = 6.5 \pm 1.76$, yani $[4.74,\ 8.26]$.

### Soru 7 (derste sözlü, 03:01:26)

Güven aralığı büyütülürse aralıkta olma olasılığı artar mı, azalır mı? %90 aralığı %95 aralığından geniş mi, dar mı olur?

> **Çözüm (derste verildi):** Aralık büyüdükçe olasılık artar. Bu yüzden %90 aralığı daha dardır; yukarıdaki veriyle yaklaşık $[5.02,\ 7.98]$ (sayısal değer derste verilmedi, python ile hesaplandı).

## Dersin Toparlaması

Bu son derste parametre kestiriminin iki temel yolu örneklerle pekiştirildi. Momentler yönteminde örneklem momentleri popülasyon momentlerine eşitlenir ve parametre sayısı kadar denklem çözülür. Kesikli dört değerli bir PMF'te ve $\tfrac12(1+\theta x)$ biçimli sürekli bir PDF'te tek parametre için birinci moment yetti. En çok olabilirlik yönteminde olabilirlik fonksiyonunun logaritması alınıp türevi sıfıra eşitlendi. Aynı sürekli PDF için iki örneklemli kestirici bulundu, Poisson dağılımında ise kestiricinin örneklem ortalaması olduğu gösterildi ve banka müşteri örneğinde $\hat\lambda = 2.4$ hesaplandı. Pratikte önce histogramla dağılım ailesi seçilir, sonra parametreler bu yöntemlerle veriden kestirilir.

Dersin ikinci yarısında Z prosedürü tekrar edildi ve güven aralığı kavramı kitaptaki tanımıyla verildi. Varyansı bilinen bir popülasyonda $\bar X$ yansız ve yaklaşık normal olduğu için $\bar X \pm z_{\alpha/2}\sigma/\sqrt n$ aralığı $(1-\alpha)100\%$ güven aralığıdır. Kitap örneğinde altı ölçümden $[4.74,\ 8.26]$ aralığı bulundu. Güven düzeyi ile aralık genişliği arasındaki denge vurgulandı. Hoca olasılığın istatistiğin, istatistiğin makine öğrenmesi ve bilgi teorisinin, bunların da yapay zekanın temeli olduğunu söyleyerek dersi bitirdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
