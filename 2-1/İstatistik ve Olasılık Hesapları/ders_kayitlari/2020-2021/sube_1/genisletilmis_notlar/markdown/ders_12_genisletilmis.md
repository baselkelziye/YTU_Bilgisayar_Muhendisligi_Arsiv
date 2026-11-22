# Ders 12 Genişletilmiş Notu: Yüzdelikler, Dörttebirlikler, Güven Aralıklarına Giriş, Momentler ve En Çok Olabilirlik Yöntemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yüzdelikler (percentiles)
- 2. Dörttebirlikler ve dörttebirlik açıklığı
- 3. Örnek: CPU sürelerinin dörttebirlikleri
- 4. Güven aralıkları
- 5. Popülasyon ortalaması için güven aralığı ve Z-prosedürü
- 6. İstatistiksel çıkarım: parametre değerlerini veriden bulmak
- 7. Momentler yöntemi
- 8. En çok olabilirlik yöntemi
- 9. İki yöntemin karşılaştırması
- Örnek Sorular

## 1. Yüzdelikler (percentiles)

Ders, önceki derslerde olduğu gibi iPad üzerinde "BLM2011 Lecture Notes (2020 Fall)" başlıklı el yazısı not defteriyle yürütüldü; anlatım çoğunlukla İngilizce, yer yer Türkçe açıklamalarla yapıldı. Bir önceki derste $p$-kantil (p-quantile) tanımlanmıştı: $x_p$, $X$'in $p$-kantilidir ve $F_X(x_p) = p$ sağlanır (ekrandan, 00:20:00). Bu derse oradan devam edildi ve önce yüzdelikler, ardından dörttebirlikler (quartiles) ele alındı.

Yüzdelik için hoca bazen $\gamma$, bazen $\alpha$ harfini kullandı; hangi harf seçilirse seçilsin bu 0 ile 100 arasında bir sayıdır ve bir yüzdeyi gösterir. "5-yüzdelik", "10-yüzdelik", "99-yüzdelik" gibi ifadeler kullanılır. Yüzdelik ile kantil arasındaki ilişki şudur: $\gamma$-yüzdelik, $\gamma/100$-kantildir. Örneğin:

- 5-yüzdelik, 0,05-kantildir.
- 99-yüzdelik, 0,99-kantildir.
- 1-yüzdelik, 0,01-kantildir.

Ekranda tanım şöyle yazıldı (ekrandan, 00:25:00): $\gamma_p$, $X$ popülasyonunun $\gamma$-yüzdeliğini göstersin. Bu durumda $\gamma_p$, $\gamma/100$-kantile karşılık gelir. Hoca bunu yazarken bir yazım hatası yaptığını fark edip düzeltti ve kantil tanımına geri döndü: önceki derste $p = F_X(x_p)$ yazılmıştı; aynı tanım yüzdeliğe uygulanınca

$$F_X(\gamma_p) = \frac{\gamma}{100}$$

olur. Yani yüzdelik de CDF'nin tersiyle bulunur.

<!-- BELİRSİZ: Hocanın yüzdelik formülünü düzeltip yeniden yazdığı ekran (00:24-00:26) karelerde tam okunmuyor; yukarıdaki biçim altyazıdaki "p is equal to F x p" anlatımından ve kantil tanımından kuruldu. -->

## 2. Dörttebirlikler ve dörttebirlik açıklığı

### 2.1 Tanım

Bazı yüzdeliklerin özel adları vardır:

- 25-yüzdelik **birinci dörttebirlik** (first quartile) diye anılır ve $Q_1$ ile gösterilir.
- 50-yüzdelik **ikinci dörttebirlik**tir ($Q_2$). Bu aynı zamanda **medyandır**: $M = Q_2$.
- 75-yüzdelik **üçüncü dörttebirlik**tir ($Q_3$).

### 2.2 PDF üzerinde yorum

Hoca sağa çarpık bir olasılık yoğunluk fonksiyonu $f_X(x)$ çizdi ve altındaki alanı $Q_1$, $Q_2$, $Q_3$ noktalarıyla dört bölgeye ayırdı (ekrandan, 00:35:00 ve 00:40:00). Bölgeler $A_1$, $A_2$, $A_3$, $A_4$ diye adlandırıldı. PDF'in altındaki toplam alan 1 olmak zorundadır:

$$\int_{-\infty}^{+\infty} f_X(x)\,dx = 1, \qquad A_1 + A_2 + A_3 + A_4 = 1.$$

Dörttebirliklerin tanımı gereği dört alan birbirine eşittir:

$$A_1 = A_2 = A_3 = A_4 = \frac{1}{4} = 0{,}25.$$

Ekrandaki ifadeyle: "Dörttebirlikler PDF'i dört eşit alana böler." Bu, integrallerle şöyle yazılır (ekrandan, 00:40:00):

$$\int_{-\infty}^{Q_1} f_X(x)\,dx = 0{,}25, \qquad \int_{-\infty}^{Q_2} f_X(x)\,dx = 0{,}5, \qquad \int_{Q_1}^{Q_2} f_X(x)\,dx = 0{,}25,$$

$$\int_{-\infty}^{Q_3} f_X(x)\,dx = 0{,}75, \qquad \int_{Q_1}^{Q_3} f_X(x)\,dx = 0{,}5, \qquad \int_{Q_2}^{Q_3} f_X(x)\,dx = 0{,}25.$$

Hoca alt sınırı $-\infty$ aldı; rastgele değişken yalnız pozitif değer alıyorsa integral 0'dan başlar, ama genel durum için $-\infty$ yazıldı.

### 2.3 Dörttebirlikleri ters CDF ile bulmak

$\int_{-\infty}^{Q_1} f_X(x)\,dx$, CDF'nin $Q_1$'deki değeridir. Bu yüzden:

$$F_X(Q_1) = 0{,}25 \;\Rightarrow\; Q_1 = F_X^{-1}(0{,}25),$$

$$F_X(Q_2) = 0{,}5 \;\Rightarrow\; Q_2 = F_X^{-1}(0{,}5),$$

$$F_X(Q_3) = 0{,}75 \;\Rightarrow\; Q_3 = F_X^{-1}(0{,}75).$$

Burada $F_X(x) = \Pr(X \le x)$, $X$ popülasyonunun CDF'idir. Dörttebirlikler veri kümesini dört eşit parçaya böler; yüzdelikler de aynı mantıkla PDF'i 100 eşit alana böler. Hoca bunları "birbiriyle ilişkili" kavramlar olarak sundu: dörttebirlikler yalnızca belirli yüzdeliklerdir.

### 2.4 Dörttebirlik açıklığı (IQR)

Dörttebirlik açıklığı (interquartile range)

$$IQR = Q_3 - Q_1$$

diye tanımlanır. Verinin değişkenliğini (variability) ölçer: ortadaki %50'lik kısmın ne kadar yayıldığını gösterir.

## 3. Örnek: CPU sürelerinin dörttebirlikleri

Hoca kitaptaki gibi bir örnek yaptı: bir bilgisayarda ölçülen CPU sürelerinin birinci ve üçüncü dörttebirliklerini hesaplamak. Pratikte bir şirkette patronunuz bir verinin medyanını ya da dörttebirliklerini istediğinde ilk iş veriyi sıralamaktır; bunun için quicksort gibi bir sıralama algoritması kullanılır.

**Veri.** Hoca önce sırasız veriyi yazdı (ekrandan, 00:45:00), sonra sıralı hâlini verdi (ekrandan, 00:50:00). Sıralı 30 gözlem:

```text
 9  15  19  22  24  25  30  34  35  35
36  36  37  38  42  43  46  48  54  55
56  56  59  62  69  70  82  82  89 139
```

Her satırda 10 sayı olduğu için sıra numaraları kolay sayılır.

> **Ders sonrası not:** Ekrandaki sırasız listede 27 sayı yazılı; sıralı listede bulunan 34, 46 ve iki 82'den biri sırasız listede yok. Hesaplar sıralı 30 gözlemle yapıldığı için sonuçlar etkilenmez (python ile karşılaştırıldı).

**Birinci dörttebirlik.** $p = 0{,}25$ için verinin %25'i (ekrandan, 00:50:00)

$$np = 30 \times 0{,}25 = 7{,}5$$

gözleme karşılık gelir; verinin %75'i ise $n(1-p) = 30 \times 0{,}75 = 22{,}5$ gözlemdir. Hoca kestirimi sıralı veride $\mathrm{round}(np)$. gözlem olarak aldı:

$$\hat{Q}_1 = X_{\mathrm{round}(np)} = X_{\mathrm{round}(7{,}5)} = X_8 = 34.$$

Sayarken: 9, 15, 19, 22, 24, 25, 30, 34; sekizinci gözlem 34'tür.

**Üçüncü dörttebirlik.** (ekrandan, 00:55:00)

$$\hat{Q}_3 = X_{\mathrm{round}(n \times 0{,}75)} = X_{\mathrm{round}(22{,}5)} = X_{23} = 59.$$

İlk iki satır 20 gözlemdir; üçüncü satırın üçüncü sayısı 23. gözlemdir: 59.

**İkinci dörttebirlik (medyan).** (ekrandan, 00:55:00)

$$\hat{Q}_2 = X_{\mathrm{round}(n \times 0{,}5)} = X_{\mathrm{round}(15)} = X_{15} = 42.$$

Hoca altyazıda bir an "$n \times 0{,}4$" dedi; ekranda $n \times 0{,}5$ yazılıdır.

> **Ders sonrası not:** Hoca medyanı $X_{15} = 42$ olarak buldu. Gözlem sayısı çift olduğunda medyan genellikle iki ortadaki gözlemin ortalamasıyla hesaplanır: $(X_{15} + X_{16})/2 = (42 + 43)/2 = 42{,}5$. Ders kitabının bu örnekte büyük olasılıkla 42,5 verdiği düşünülür. $Q_1$ ve $Q_3$ için hocanın kuralı ($X_8 = 34$, $X_{23} = 59$) bu veride büyük olasılıkla kitaptaki tanımla aynı sonucu verir. Bütün değerler python ile kontrol edildi.

## 4. Güven aralıkları

Aradan sonra güven aralıklarına (confidence intervals) geçildi (ekrandan, 01:10:00).

### 4.1 Tanım

Bir popülasyonun bir $\theta$ parametresi olsun. Hoca daha önceki derslerdeki örnekleri hatırlattı: rastgele değişkenlerin dağılımı parametrelere bağlıdır; örneğin normal dağılımın parametreleri ortalama $\mu$ ve varyans $\sigma^2$'dir. Amaç, bilinmeyen $\theta$ için bir aralık kestirmek ve $\theta$'nın bu aralıkta bulunma olasılığını bilmektir.

**Tanım:** $[a, b]$ aralığı, $\theta$ parametresini $1 - \alpha$ olasılıkla içeriyorsa, $\theta$ için $(1-\alpha)100\%$ güven aralığıdır:

$$\Pr(a \le \theta \le b) = 1 - \alpha.$$

### 4.2 Sayısal örnek

$\alpha = 0{,}2$ alınırsa (ekrandan, 01:15:00):

$$(1 - 0{,}2) \times 100\% = 0{,}8 \times 100\% = 80\%, \qquad \Pr(a \le \theta \le b) = 0{,}8.$$

Yorum: $\theta$ parametresinin değeri %80 olasılıkla $[a, b]$ aralığındadır.

### 4.3 Güven düzeyi

$(1-\alpha)100\%$ ifadesine güven aralığının yüzdesi, $1 - \alpha$'ya ise **güven düzeyi** (confidence level) denir. Literatürde yaygın kullanılan güven düzeyleri %90, %95 ve %99'dur; bunlara karşılık gelen $\alpha$ değerleri sırasıyla 0,1, 0,05 ve 0,01'dir (ekrandan, 01:20:00).

## 5. Popülasyon ortalaması için güven aralığı ve Z-prosedürü

### 5.1 Ne zaman uygun?

Popülasyon ortalaması $\mu$ için güven aralıkları büyük örneklem boyutlarında (en az 30 gözlem) uygundur (ekrandan, 01:20:00). Daha küçük örneklemlerde ise veri yaklaşık normal dağılıyor kabul edilebiliyorsa kullanılabilir. Ortalama Gauss yaklaşımıyla kestirilir.

$\bar{X} = \frac{1}{n}\sum_{i=1}^{n} X_i$ için normal dağılım varsayımı geçerliyse $\bar{X}$ normal dağılır. Bu durumda $\mu$ parametresinin verilen aralıkta bulunma olasılığını bulmak için **Z-prosedürü** kullanılabilir (ekrandan, 01:25:00).

### 5.2 Z-prosedürünün kurulumu

$Z$, ortalaması 0 ve varyansı 1 olan standart normal dağılımlı bir rastgele değişkendir: $E[Z] = 0$, $\mathrm{Var}(Z) = 1$. Z-prosedüründe varsayımlar şunlardır:

- Popülasyonun standart sapması $\sigma$ (dolayısıyla varyansı $\sigma^2 = \mathrm{Var}(X)$) bilinir.
- Ortalama $\mu$ bilinmez; hangi değeri aldığı hakkında fikrimiz yoktur.

Gösterimler (ekrandan, 01:30:00):

- $n$: örneklem boyutu. Örneklem (veri) $S = (X_1, X_2, \dots, X_n)$, $|S| = n$.
- $\bar{X} = \frac{1}{n}\sum_{i=1}^{n} X_i$: örneklem ortalaması (veriden kestirilen değer).
- $\sigma$: $X$ popülasyonunun standart sapması; $\sigma^2$ popülasyonun varyansı.
- $\mu$: gerçek (exact) ortalama; bilinmez.

Kestirimin $z$-skoru (z-score) standart normal dağılır ve şöyle tanımlanır (ekrandan, 01:35:00):

$$Z = \frac{\bar{X} - \mu_{\bar{X}}}{\sigma_{\bar{X}}} = \frac{\bar{X} - \mu}{\sqrt{\sigma^2/n}} = \frac{(\bar{X} - \mu)\sqrt{n}}{\sigma}.$$

Burada $\mu_{\bar{X}}$ örneklem ortalamasının beklenen değeri, $\sigma_{\bar{X}}$ örneklem ortalamasının standart sapmasıdır.

### 5.3 Örneklem ortalamasının ortalaması ve standart sapması

Hoca bu iki değeri (önceki derste görülmüş olsa da) yeniden türetti ve adımları 1, 2, 3, 4 diye numaraladı:

1. $E[\bar{X}] = \frac{1}{n}\sum_{i=1}^{n} E[X_i] = \frac{1}{n}\cdot n\mu = \mu$. Örneklem ortalamasının ortalaması, $X$ popülasyonunun ortalamasına eşittir.
2. $\mathrm{Var}(\bar{X}) = \frac{1}{n^2}\sum_{i=1}^{n}\mathrm{Var}(X_i) = \frac{1}{n^2}\cdot n\sigma^2$ (ara adım: $X_i$'ler bağımsız alındı).
3. $\mathrm{Var}(\bar{X}) = \sigma^2_{\bar{X}} = \dfrac{\sigma^2}{n}$.
4. $\sigma_{\bar{X}} = \sqrt{\sigma^2_{\bar{X}}} = \sqrt{\dfrac{\sigma^2}{n}} = \dfrac{\sigma}{\sqrt{n}}$ (ekrandan, 01:40:00).

Son kutudaki sonuç: örneklem ortalaması $\bar{X}$'in standart sapması $\sigma/\sqrt{n}$'dir; burada $\sigma$ popülasyonun standart sapmasıdır.

### 5.4 Kritik değer ve tek taraflı Z-aralıkları

Kritik değer $z_\alpha$, normal dağılım tablosundan

$$\Pr(Z > z_\alpha) = \alpha$$

olacak biçimde okunur. İki tür Z-aralığı vardır: tek taraflı (one-sided) ve iki taraflı (two-sided). Tek taraflı iki aralık şöyledir (ekrandan, 01:45:00):

$$\left(-\infty,\; \bar{X} + \frac{\sigma}{\sqrt{n}}\, z_\alpha\right] \qquad \text{ve} \qquad \left[\bar{X} - \frac{\sigma}{\sqrt{n}}\, z_\alpha,\; \infty\right).$$

Hoca bir şekil çizmeye başladı ve $\bar{X}$'in kendisinin de bir rastgele değişken olduğunu, tam olarak $\mu$'ye eşit olmadığını, yani hata yapılabileceğini belirtti; ancak bu ayrıntıya şimdilik girmemeye karar verdi. "İki taraflı Z-aralıkları" başlığı ekrana yazıldı, ama içeriği bu derste anlatılmadı.

> **Ek bilgi (derste anlatılmadı):** İki taraflı $(1-\alpha)100\%$ Z-aralığı genellikle $\bar{X} \pm z_{\alpha/2}\,\sigma/\sqrt{n}$ biçiminde yazılır; sağ kuyruktan $\alpha/2$, sol kuyruktan $\alpha/2$ alan dışarıda bırakılır. Hoca bunun ve T-prosedürünün sonraki derste işleneceğini söyledi.

İkinci aradan sonra hoca, güven aralıklarına sıradan biraz önce geçtiğini, bir karışıklık olduğunu ama sorun olmadığını, konunun sonraki derste ayrıntılandırılacağını söyledi ve parametre kestirimine (Chapter 8, Statistical Inference) döndü.

## 6. İstatistiksel çıkarım: parametre değerlerini veriden bulmak

Hoca bu kısmı hızlı geçmek için önce Türkçe anlattı ve ilk derslerdeki histogram örneklerini hatırlattı.

- Bir histogram gama dağılımına benziyorsa, gama PDF'inin parametrelerinin değerleri ne olmalıdır? <!-- BELİRSİZ: Hoca gama PDF'inin parametrelerini altyazıda "m ve omega" gibi duyulan adlarla andı; ilgili ekran karelerde yok. -->
- Bir histogram Gauss'a benziyorsa PDF

$$f(x) = \frac{1}{\sqrt{2\pi\sigma^2}}\, \exp\!\left(-\frac{(x-\mu)^2}{2\sigma^2}\right)$$

olur. İki parametre vardır: ortalama $\mu$ ve varyans $\sigma^2$. Bu histogramın ait olduğu veriden $\mu$ ve $\sigma^2$'nin değerleri nasıl bulunur?

- Bir histogram üstel dağılıma benziyorsa PDF (ekrandan, 02:30:00)

$$f_X(x) = \frac{1}{\lambda}\exp\!\left(-\frac{x}{\lambda}\right), \qquad 0 < x < \infty$$

olur. Tek parametre vardır: $\lambda$. Bu histogramın ait olduğu veri için $\lambda$ nedir?

Genel soru şudur: verilen verinin ait olduğu PDF'in parametrelerinin değerleri veriden nasıl çıkarılır (infer edilir)? Bunun için iki yöntem vardır:

1. Momentler yöntemi (method of moments).
2. En çok olabilirlik yöntemi (method of maximum likelihood).

## 7. Momentler yöntemi

### 7.1 Kuramsal momentler

$X$ bir popülasyon (rastgele değişken) olsun. $X$'in $k$. momenti (ekrandan, 02:10:00)

$$E[X^k]$$

ile verilir. $E[X]$ birinci momenttir (ortalama), $E[X^2]$ ikinci moment, $E[X^3]$ üçüncü moment, $E[X^4]$ dördüncü momenttir ve böyle devam eder. Bunlar kuramsal olarak PDF'ten bulunur:

$$E[X^k] = \int_{-\infty}^{+\infty} x^k f_X(x)\,dx.$$

Hoca bu integrali ilk yazışında $x^k$ çarpanını unuttu, öğrencilere "doğru mu?" diye sordu ve beklenen değer tanımını uygulayarak düzeltti.

### 7.2 Örneklem momentleri

Örneklem momentleri veriden şöyle hesaplanır:

$$m_1 = \frac{1}{n}\sum_{i=1}^{n} X_i, \qquad m_2 = \frac{1}{n}\sum_{i=1}^{n} X_i^2, \qquad m_3 = \frac{1}{n}\sum_{i=1}^{n} X_i^3, \qquad \dots, \qquad m_k = \frac{1}{n}\sum_{i=1}^{n} X_i^k.$$

$m_1$ örneklem ortalamasıdır. Sonuç olarak $m_k$, $X$ popülasyonunun $k$. gerçek momentinin kestirimidir: $m_k$ veriden, $E[X^k]$ PDF'ten elde edilir.

> **Hocanın vurgusu:** Örneklem momentinin gerçek momentin kestirimi olması "çok önemli"dir; yöntem bu eşleştirmeye dayanır.

> **Ders sonrası not:** Hoca $m_2$ ve $m_3$'ü anlatırken "second/third sample mean" dedi; doğrusu ikinci/üçüncü örneklem momentidir (sample moment).

### 7.3 Merkezi momentler

Merkezi momentler de benzer biçimde kestirilir. $k \ge 2$ için $k$. merkezi moment (ekrandan, 02:20:00)

$$\mu'_k = E\big[(X - E[X])^k\big]$$

diye tanımlanır. Buna karşılık gelen $k$. örneklem merkezi momenti

$$m'_k = \frac{1}{n}\sum_{i=1}^{n} (X_i - \bar{X})^k$$

olur. Burada $\bar{X}$ örneklem ortalamasıdır, yani $\bar{X} = m_1$.

### 7.4 Yöntemin kendisi

PDF'in parametreleri, şu eşitlikler kurulup çözülerek bulunur (ekrandan, 02:25:00):

$$m_1 = E[X], \qquad m_2 = E[X^2], \qquad m_3 = E[X^3], \qquad \dots, \qquad m_k = E[X^k].$$

Sol taraftakiler örneklem momentleridir ve veriden elde edilir; sağ taraftakiler $X$'in momentleridir ve PDF'ten elde edilir. İkisi eşit olmalıdır. Bu $k$ denklem çözülerek, histogramdan elde edilen empirik PDF'e uyan (fit eden) PDF'in parametre değerleri bulunur. Hoca bunu Türkçe şöyle özetledi: size bir veri verilir, o verinin histogramından empirik PDF'i bulursunuz; o empirik PDF'in benzediği PDF'in empirik PDF'e uyması için ilgili parametrelerin değerlerini de bulmuş olursunuz.

**Üstel dağılım için:** tek parametre ($\lambda$) olduğundan $\lambda$, yalnızca

$$m_1 = E[X]$$

çözülerek bulunur (ekrandan, 02:30:00).

**Denklem sayısı kuralı:** (ekrandan, 02:30:00)

$$(\text{momentler yöntemindeki denklem sayısı}) = (\text{PDF'teki parametre sayısı}).$$

> **Hocanın vurgusu:** Bu "çok çok önemli bir sonuç"tur. Bilinmeyen sayısı kadar denklem kurulur.

**Soru:** Bulmamız gereken iki parametre varsa, iki denklem mi kurulur; birinci örneklem momenti birinci momente mi eşitlenir? **Cevap:** Evet. Örneğin normal dağılımda $m_1 = E[X]$ ve $m_2 = E[X^2]$ olmak üzere iki denklem ve iki bilinmeyen ($\mu$, $\sigma^2$) vardır; bunlar birlikte çözülür.

Hoca üç parametreli bir PDF için de yöntemi Türkçe özetledi: birinci, ikinci ve üçüncü örneklem momentleri hesaplanır; sırasıyla birinci, ikinci ve üçüncü gerçek momentlere eşitlenir; üç bilinmeyenli üç denklem çözülerek parametreler bulunur.

> **Ders sonrası not:** Hoca İngilizce anlatırken bir an "üç parametre varsa beş denklem gerekir" dedi; hemen ardından Türkçe olarak "beş bilinmeyen varsa beş denklem lazım" diye düzeltti. Kural her zaman parametre (bilinmeyen) sayısı kadar denklemdir.

## 8. En çok olabilirlik yöntemi

### 8.1 Fikir

Bir örneklem (veri) verilir: $S = (X_1, X_2, \dots, X_n)$ (ekrandan, 02:35:00). Ekrandaki ifadeyle: parametreleri bulmak için örneklemin "entropisi" kullanılabilir; parametreler, bu entropiyi en küçük yapan değerlere sahiptir. Hoca bunu formülle şöyle yazdı ($L$ tane parametre $\theta_1, \dots, \theta_L$ için):

$$(\hat\theta_1, \dots, \hat\theta_L) = \arg\min_{\theta_1,\dots,\theta_L} \left(-\log \prod_{i=1}^{n} f_X(X_i)\right) = \arg\max_{\theta_1,\dots,\theta_L} \log \prod_{i=1}^{n} f_X(X_i).$$

Çarpımın logaritması toplama dönüşür:

$$\log \prod_{i=1}^{n} f_X(X_i) = \sum_{i=1}^{n} \log f_X(X_i).$$

Hoca $f_X(X_i)$ değerine olasılık (probability) yerine "possibility" (olabilirlik) demenin daha doğru olacağını söyledi: olabilirlik, PDF'in $X_i$ noktasındaki değeridir.

> **Ek bilgi (derste anlatılmadı):** Standart terimle $\prod_{i=1}^{n} f_X(X_i;\theta)$ ifadesine olabilirlik fonksiyonu (likelihood), $-\sum \log f_X(X_i;\theta)$ ifadesine negatif log-olabilirlik denir. Hocanın "entropi" diye andığı nicelik büyük olasılıkla bu negatif log-olabilirliktir; onu en küçük yapmak log-olabilirliği en büyük yapmakla aynıdır.

Bu ifade parametrelerin ($\theta_1, \theta_2, \dots, \theta_L$) bir fonksiyonu olur ve parametreler bu fonksiyonu en büyük yapmalıdır (ekrandan, 02:40:00).

**Soru (hocadan):** Bir $g(\sigma)$ fonksiyonunu en büyük yapan $\sigma$ değeri nasıl bulunur? **Cevap (bir öğrenci):** Türev alınarak. Hoca tamamladı: $\sigma$'ya göre türev alınır, sıfıra eşitlenir ve çözülür; böylece fonksiyonu en büyük yapan $\sigma$ bulunur.

### 8.2 Örnek: üstel dağılımın parametresi

Veri, $f_X(x) = \lambda e^{-\lambda x}$, $x > 0$ PDF'ine ait olsun. $\lambda$'nın değerini veri cinsinden bulun. Aranan şey, örnekleri alıp $\lambda$'yı veren bir fonksiyondur.

**Kurulum** (ekrandan, 02:45:00):

$$\hat\lambda = \arg\max_{\lambda} \log\left(\prod_{i=1}^{n} f_X(X_i)\right), \qquad L(\lambda) = \prod_{i=1}^{n} \lambda e^{-\lambda X_i} = \lambda^n e^{-\lambda\sum_{i=1}^{n} X_i}.$$

**Türev.** Hoca $L(\lambda)$'nın türevini doğrudan (logaritma almadan) aldı ve sıfıra eşitledi (ekrandan, 02:50:00):

$$\frac{dL}{d\lambda} = n\lambda^{n-1} e^{-\lambda\sum X_i} + \lambda^n\left(-\sum_{i=1}^{n} X_i\right) e^{-\lambda\sum X_i} = 0.$$

Yazarken bir üs eksiğini ($n-1$) fark edip düzeltti. Buradan

$$n\lambda^{n-1} e^{-\lambda\sum X_i} = \lambda^n \left(\sum_{i=1}^{n} X_i\right) e^{-\lambda\sum X_i}.$$

Üstel çarpanlar iki tarafta aynıdır ve sadeleşir; $\lambda^n / \lambda^{n-1} = \lambda$ olduğundan

$$n = \lambda \sum_{i=1}^{n} X_i.$$

**Sonuç:**

$$\hat\lambda = \frac{n}{\sum_{i=1}^{n} X_i}.$$

Bu, $f_X(x) = \lambda e^{-\lambda x}$, $x > 0$ PDF'inin $\lambda$ parametresi için kestiricidir; $X_i$'ler veriden gelen örneklerdir. Rastgele üretilmiş bir örneklemde log-olabilirliğin sayısal olarak en büyük olduğu nokta bu formülle aynı çıktı (python ile kontrol edildi).

> **Ek bilgi (derste anlatılmadı):** Aynı sonuç logaritma alınarak daha kısa yoldan bulunur: $\log L(\lambda) = n\log\lambda - \lambda\sum X_i$, türevi $n/\lambda - \sum X_i = 0$, yani $\hat\lambda = n/\sum X_i = 1/\bar{X}$. Logaritma artan bir fonksiyon olduğu için $L$ ile $\log L$ aynı noktada en büyük olur.

> **Ders sonrası not:** Momentler yöntemi anlatılırken üstel PDF $\frac{1}{\lambda}e^{-x/\lambda}$ (burada $\lambda$ ortalamadır), en çok olabilirlik örneğinde ise $\lambda e^{-\lambda x}$ (burada $\lambda$ orandır) biçiminde yazıldı. İki gösterimdeki $\lambda$ farklı anlamdadır.

### 8.3 Birden çok parametre

**Soru:** En çok olabilirlik yönteminde birden fazla parametre varsa ne yapılır? **Cevap:** Her parametreye göre ayrı ayrı türev alınır ve sıfıra eşitlenir. İki parametre varsa birinci parametreye göre türev sıfıra, ikinci parametreye göre türev sıfıra eşitlenir; elde iki bilinmeyenli iki denklem olur ve birlikte çözülür. Üç parametre varsa üç türev, üç denklem ve üç bilinmeyen olur.

## 9. İki yöntemin karşılaştırması

**Soru:** İki yöntemin birbirine göre avantajı ve dezavantajı nedir; sonuçta ikisi de parametreyi bulmaya çalışıyor. **Cevap:** Momentler yöntemi biraz daha hatalıdır ama basittir, sonuç çok kolay bulunur. En çok olabilirlik yöntemi daha doğru, hatası daha küçük bir kestirim verir, çünkü olabilirliği en büyük yapar. Ancak türev alınıp sıfıra eşitlenince ortaya çıkan denklemleri çözmek zordur. Momentleri hesaplamak kolay, olabilirlikten çıkan denklemleri çözmek zor olduğundan genelde momentler yöntemi kullanılır; en çok olabilirlik de gayet iyi bir çözümdür.

> **Hocanın vurgusu:** Momentler yöntemi ve en çok olabilirlik yöntemi dersin en önemli konularındandır; her biriyle ilgili çok sayıda örnek çalışılmalıdır.

## Örnek Sorular

**Soru 1 (ekrandan, 00:45:00, 00:50:00 ve 00:55:00):** Bir bilgisayarda ölçülen 30 CPU süresi sıralanınca şu veri elde ediliyor: 9, 15, 19, 22, 24, 25, 30, 34, 35, 35, 36, 36, 37, 38, 42, 43, 46, 48, 54, 55, 56, 56, 59, 62, 69, 70, 82, 82, 89, 139. Birinci ve üçüncü dörttebirlikleri (ve medyanı) kestirin.

> **Çözüm (derste verildi):** $n = 30$. $np = 30 \times 0{,}25 = 7{,}5$, $n \times 0{,}75 = 22{,}5$. $\hat{Q}_1 = X_{\mathrm{round}(7{,}5)} = X_8 = 34$; $\hat{Q}_3 = X_{\mathrm{round}(22{,}5)} = X_{23} = 59$; $\hat{Q}_2 = X_{\mathrm{round}(15)} = X_{15} = 42$. (Ders sonrası not: çift $n$ için yaygın medyan tanımıyla $(42+43)/2 = 42{,}5$.)

**Soru 2 (ekrandan, 01:15:00):** $\alpha = 0{,}2$ ise güven aralığının yüzdesi nedir ve $\Pr(a \le \theta \le b)$ kaçtır?

> **Çözüm (derste verildi):** $(1 - 0{,}2) \times 100\% = 80\%$; $\Pr(a \le \theta \le b) = 0{,}8$. Parametrenin değeri %80 olasılıkla $[a, b]$ aralığındadır.

**Soru 3 (ekrandan, 02:30:00):** Histogramı $f_X(x) = \frac{1}{\lambda}\exp(-x/\lambda)$, $0 < x < \infty$ üstel dağılımına benzeyen bir veri için $\lambda$ nedir? (Momentler yöntemiyle.)

> **Çözüm (derste verilmedi):** Hoca yalnızca "$m_1 = E[X]$ çözülerek bulunur" dedi. Bu PDF için $E[X] = \int_0^\infty x\,\frac{1}{\lambda}e^{-x/\lambda}\,dx = \lambda$ olduğundan $m_1 = \bar{X} = \lambda$, yani $\hat\lambda = \bar{X} = \frac{1}{n}\sum_{i=1}^{n} X_i$.

**Soru 4 (ekrandan, 02:40:00):** Bir $g(\sigma)$ fonksiyonunu en büyük yapan $\sigma$ değeri nasıl bulunur?

> **Çözüm (derste verildi):** $g$'nin $\sigma$'ya göre türevi alınır, sıfıra eşitlenir ve $\sigma$ için çözülür.

**Soru 5 (ekrandan, 02:45:00 ve 02:50:00):** Veri $f_X(x) = \lambda e^{-\lambda x}$, $x > 0$ PDF'ine aittir. En çok olabilirlik yöntemiyle $\lambda$'yı veri cinsinden bulun.

> **Çözüm (derste verildi):** $L(\lambda) = \prod_{i=1}^{n}\lambda e^{-\lambda X_i} = \lambda^n e^{-\lambda\sum X_i}$. Türev sıfıra eşitlenir: $n\lambda^{n-1}e^{-\lambda\sum X_i} - \lambda^n\left(\sum X_i\right)e^{-\lambda\sum X_i} = 0 \Rightarrow n = \lambda\sum X_i \Rightarrow \hat\lambda = \dfrac{n}{\sum_{i=1}^{n} X_i}$.

## Dersin Toparlaması

Bu derste önce betimsel istatistiğin konum ölçüleri tamamlandı: yüzdelik, kantilin yüzdeyle ifadesi olarak tanımlandı; dörttebirlikler PDF'in altını dört eşit alana bölen noktalar olarak gösterildi, ters CDF ile bulundu ve 30 CPU süresinden oluşan bir örnekte sıralı veriyle kestirildi. Dörttebirlik açıklığı $Q_3 - Q_1$ değişkenlik ölçüsü olarak tanıtıldı. Ardından güven aralığı kavramına ve güven düzeyine giriş yapıldı; $\sigma$'nın bilindiği durumda popülasyon ortalaması için Z-prosedürü kuruldu, $\sigma_{\bar{X}} = \sigma/\sqrt{n}$ yeniden türetildi ve iki tek taraflı Z-aralığı yazıldı.

Dersin son bölümünde istatistiksel çıkarımın temel sorusuna dönüldü: histogramı bilinen bir PDF'e benzeyen verinin parametreleri nasıl bulunur? Momentler yönteminde örneklem momentleri gerçek momentlere eşitlenir ve parametre sayısı kadar denklem çözülür; en çok olabilirlik yönteminde log-olabilirlik her parametreye göre türevi sıfıra eşitlenerek en büyük yapılır. Üstel dağılım için $\hat\lambda = n/\sum X_i$ elde edildi. Sonraki derste iki taraflı aralıklar, Z-prosedürü ve T-prosedürü (T-skorları) ile güven aralıklarının ayrıntılandırılacağı söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
