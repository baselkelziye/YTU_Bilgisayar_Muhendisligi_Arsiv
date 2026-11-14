# Ders 9 Genişletilmiş Notu: Merkezi Limit Teoremi, Süreklilik Düzeltmesi ve İstatistiğe Giriş: Örneklem Ortalaması, Medyan ve Kantiller

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Merkezi Limit Teoremi
- 2. Örnek: Sabit Diskte Yer Yeter mi?
- 3. Özel Durum: Toplanan Değişkenler Zaten Normalse
- 4. Disk Örneğinin Türkçe Tekrarı
- 5. Toplam Olarak Yazılabilen Dağılımlar
- 6. Süreklilik Düzeltmesi
- 7. İstatistiğe Giriş: Popülasyon, Parametre, Örnekleme
- 8. Tahmin, Şapkalı Gösterim ve İstatistik
- 9. Hata Kaynakları
- 10. Basit Rastgele Örnekleme
- 11. Örneklemi Rastgele Değişken Listesi Olarak Görmek ve CPU Verisi
- 12. Örneklem Ortalaması
- 13. İyi Bir Tahmin Edicinin Özellikleri
- 14. Medyan
- 15. Kantiller

## 1. Merkezi Limit Teoremi

Sürekli dağılımlarda kalınan yerden devam edildi ve sıra merkezi limit teoremine (central limit theorem, CLT) geldi. Bu teorem rastgele değişkenlerin toplamlarıyla ilgilidir.

### 1.1 Toplam ve i.i.d. Varsayımı

Elimizde $X_1, X_2, \dots, X_n$ rastgele değişkenleri olsun ve bunları toplayalım. Her biri rastgele değişken olduğu için toplamları da başka bir rastgele değişkendir. Bu değişkene, $n$ tane değişkenin toplamından geldiğini hatırlatmak için $S_n$ diyelim:

$$S_n = X_1 + X_2 + \dots + X_n$$

Ayrıca bu değişkenlerin bağımsız ve özdeş dağılmış (independent and identically distributed, i.i.d.) olduğunu varsayıyoruz. Bu varsayımın iki parçası vardır:

- **Bağımsız:** $X_1$'in aldığı değer, $X_2$'nin aldığı değeri değiştirmez, etkilemez.
- **Özdeş dağılmış:** Hepsi aynı dağılımdan gelir. Beklenen değerleri aynıdır: $E[X_i] = \mu_i$. Varyansları aynıdır: $\mathrm{Var}(X_i) = \sigma_i^2$. Grafikleri de aynıdır.

Burada $\mu_i$ ve $\sigma_i^2$, tek bir değişkenin ortalaması ve varyansıdır. Hepsi için aynı olduğundan altındaki $i$ belirli bir değişkeni değil, "herhangi biri" anlamını taşır.

### 1.2 Teoremin İfadesi

CLT şunu söyler: $n$ sonsuza giderken, yani toplama katılan değişken sayısı arttıkça, $S_n$'nin olasılık dağılımı normal dağılıma gider. Bu normal dağılımın parametreleri şöyledir:

$$S_n \approx N\left(n\mu_i,\; n\sigma_i^2\right)$$

Ortalama için sezgi basittir: $n$ tane değişken topluyoruz, ortalamaları da toplanır, dolayısıyla toplamın ortalaması tek bir değişkenin ortalamasının $n$ katıdır. Varyans da aynı biçimde tek bir değişkenin varyansının $n$ katıdır. İkinci parametrenin üzerindeki kareye dikkat edin: burada yazılan standart sapma değil, varyanstır.

### 1.3 Pratikte $n \ge 30$ Kuralı

Sonsuza hiçbir zaman gidemeyiz. Bu yüzden pratikte kural şudur:

> **Hocanın vurgusu:** Teorem $n \to \infty$ için geçerlidir, ama pratikte $n \ge 30$ ise merkezi limit teoremini kullanabiliriz.

## 2. Örnek: Sabit Diskte Yer Yeter mi?

### 2.1 Problem

Bir sabit diskte 330 MB boş yer var. Bu diske birbirinden bağımsız 300 resim indirmek istiyoruz. Resimlerin boyutunun tam dağılımını bilmiyoruz, ama ortalamasını ve standart sapmasını biliyoruz: ortalama boyut 1 MB, standart sapma 0.5 MB. Bazı resimler 1 MB'den büyük, bazıları küçük olabilir. Varyans $0.5^2 = 0.25$ MB²'dir.

Soru şu: Boş yer yeterli olur mu, yani yerin yetme olasılığı nedir?

### 2.2 Modelleme

Önce toplam indirme miktarını düşünelim. $X_i$, $i$. resmin boyutunu modelleyen rastgele değişken olsun. Resmi henüz indirmediğimiz için boyutunu bilmiyoruz; bu yüzden rastgele değişken olarak yazıyoruz. Toplam indirme miktarı:

$$S_{300} = X_1 + X_2 + \dots + X_{300}$$

Toplam boyut 330 MB'den küçük ya da ona eşitse disk yeter, değilse sorun var. Dolayısıyla aranan olasılık $P(S_{300} \le 330)$'dur.

### 2.3 Çözüm

Bu, merkezi limit teoreminin doğrudan bir uygulamasıdır.

**Verilen:** $n = 300$, $\mu_i = 1$ MB, $\sigma_i^2 = 0.25$ MB².

**Adım 1: Teoremi kullanabilir miyiz?** $n = 300 \ge 30$ olduğu için evet. Dağılımı bilinmese bile teorem için ortalama ve varyans yeterlidir.

**Adım 2: Toplamın dağılımı.** $S_{300}$ yaklaşık olarak normal dağılır.

- Ortalama: $n\mu_i = 300 \cdot 1 = 300$
- Varyans: $n\sigma_i^2 = 300 \cdot 0.25 = 75$

$$S_{300} \approx N(300,\; 75)$$

**Adım 3: Standartlaştırma.** Kalan iş, normal dağılımı standartlaştırmaktır. $Z$ standart normal dağılım olsun. Değerden ortalamayı çıkarıp standart sapmaya, yani varyansın kareköküne böleriz:

$$z = \frac{330 - 300}{\sqrt{75}} = \frac{30}{8.66} = 3.46$$

**Adım 4: Kümülatif değer.** $P(S_{300} \le 330)$, kümülatif dağılım fonksiyonunun tanımından $S_{300}$'ün 330'daki kümülatif değeridir. Standartlaştırınca bu, standart normalin $3.46$'daki kümülatif değerine dönüşür. Bu değer tablolardan, örneğin Baron'un kitabındaki tablodan bulunur:

$$P(S_{300} \le 330) = \Phi\left(\frac{330 - 300}{\sqrt{75}}\right) = \Phi(3.46) \approx 0.9997$$

Yani 330 MB'lik boş yer neredeyse kesin olarak yeter. Python ile hesaplandı: $\Phi(30/\sqrt{75}) = \Phi(3.4641) = 0.99973$. Hocanın sonucu doğrudur.

## 3. Özel Durum: Toplanan Değişkenler Zaten Normalse

CLT için $n$'nin büyük olması gerekir, ama özel bir durum vardır. $X_1, X_2, \dots, X_n$ değişkenlerinin kendileri zaten normal ise toplamları her zaman normaldir. Bu durumda terim sayısıyla ilgilenmeyiz. $n < 30$ olsa bile toplamın normal olduğunu söyleyebiliriz.

## 4. Disk Örneğinin Türkçe Tekrarı

Bu noktada bir öğrencinin sorusu üzerine hoca disk örneğini Türkçe olarak baştan anlattı.

**Soru:** 330 MB'lik bir yere birer MB'lik 300 resmi yerleştirme olasılığını mı bulduk?

**Cevap:** Resimler elimizde değil ve her birinin tam 1 MB olduğunu bilmiyoruz. Rastgele resimler indireceğiz. Bildiğimiz, daha önceki bir çalışmadan gelen şu bilgidir: İnternetteki resimlerin ortalama büyüklüğü 1 MB, varyansı $0.25$'tir. Resimlerin her biri aslında bir rastgele değişkendir, çünkü bu işi henüz yapmadık.

Hoca ardından çözümün mantığını yineledi. Elimizde $n$ tane rastgele değişkenin toplamı varsa ve $n$ sayısı pratikte 30'un üzerindeyse, normal dağılımı kullanabiliriz; teorem aslında "$n$ sonsuza giderken" der. Normal dağılımı belirleyen şey ortalaması ile varyansıdır. Varyans yerine standart sapma da verilebilir, fark etmez, çünkü varyans standart sapmanın karesidir.

Toplamın ortalaması, 1 MB ortalamalı 300 nesneyi topladığımız için $300 \cdot 1 = 300$'dür. Varyansı $300 \cdot 0.25$'tir. Bu parametreler bulunduktan sonra normal dağılım için sorulan değer standartlaştırılır: değerden ortalama çıkarılır, sonuç standart sapmaya bölünür, standart normal dağılımda karşılık gelen değer bulunur. Normalin kümülatif değerinin hesabı karmaşık olduğu için son adımda Baron'un tablosuna bakılır.

> **Hocanın vurgusu:** Paydada varyans değil, onun karekökü olan standart sapma kullanılır: $\sqrt{75}$.

<!-- BELİRSİZ: 00:27:38-00:34:31 aralığındaki Türkçe anlatım altyazıda büyük ölçüde bozuk çevrilmiş. Yalnız anlaşılan kısımlar ve 00:16-00:25 aralığındaki İngilizce anlatımla tutarlı olanlar aktarıldı. 00:28:36'daki "1, 5, 30, 0.2" gibi sayılar okunamadı, alınmadı. -->

## 5. Toplam Olarak Yazılabilen Dağılımlar

Bildiğimiz dağılımların bazıları başka dağılımların toplamıdır:

- **Binom dağılımı:** Bernoulli dağılımlarının toplamıdır. Kesiklidir.
- **Gama dağılımı:** Üstel dağılımların toplamıdır. Süreklidir.
- **Negatif binom dağılımı:** Geometrik dağılımların toplamıdır. Kesiklidir.

Bu, toplamdaki eleman sayısı 30'dan büyükse bu dağılımlar için CLT'yi kullanabileceğimiz anlamına gelir. Binom yerine, gama yerine, negatif binom yerine gerektiğinde normal dağılım kullanılabilir. Özellikle gamanın denklemi çok karmaşıktır, binomun denkleminde de çok büyük faktöriyeller vardır. Bu yüzden bazen normal dağılımdan yararlanılır.

> **Hocanın vurgusu:** "Hesaplarız" demek yerine "yaklaşık hesaplarız" demeliyiz. Tam eşitlik sonsuzda gerçekleşir, bizim ise toplayacak sonsuz sayıda şeyimiz yoktur. CLT ile yapılan hesap bir yaklaşıklıktır (approximation).

## 6. Süreklilik Düzeltmesi

Listedeki dağılımların bazıları kesikli, bazıları süreklidir. Kesikli bir dağılımı sürekli bir dağılımla yaklaşık hesaplamaya çalışınca bir sorunla karşılaşırız. Bu sorunun çözümüne süreklilik düzeltmesi (continuity correction) denir.

### 6.1 Sorun: Tek Noktanın Olasılığı

Binom dağılımını normal dağılımla yaklaşık hesaplamak istediğimizi düşünelim. Binom kesiklidir ve bir olasılık kütle fonksiyonu (probability mass function, PMF) vardır. Bu yüzden "5'in olasılığı" diyebiliriz; değeri burada önemli değil, diyelim ki $1/6$.

Normal dağılımda ise elimizde olasılık yoğunluk fonksiyonu (PDF) vardır ve sürekli bir eğri görürüz. Sürekli dağılımda tek bir noktanın olasılığı sıfırdır. Dolayısıyla tek tek noktaların olasılığından söz edemeyiz. Sorun hemen buradadır: Kesikli dağılımda $1/6$ olan olasılık, sürekli yaklaşımda sıfır çıkar.

> **Ders sonrası not:** Hoca 5'in olasılığı için önce "1.5 ya da 1.6" dedi. Olasılık 1'den büyük olamaz; hoca hemen sonra aynı örnekte "1 over 6" dediği için burada $1/6$ yazıldı. Hoca PDF'i "probability distribution function" diye açtı; yaygın açılımı büyük olasılıkla "probability density function"dır.

### 6.2 Fikir: Noktayı Bir Birimlik Aralık Yapmak

Süreklilik düzeltmesi yalnızca bir fikirdir: 5'ten söz ediyorsak, neden 4.5 ile 5.5 arasındaki bir birimlik bölgeden söz etmeyelim? Grafikte öncekinden yarım, sonrakinden yarım birim alınca genişlik 1 olur. Böylece olasılığı sıfır olan 5 yerine, 4.5 ile 5.5 arasının olasılığını hesaplarız. Yine bir yaklaşıklık elde ederiz, ama en azından elimizde bir şey olur.

Yaklaşık sürekli değişkene, $X$ ile karışmaması için $Y$ dersek:

$$P(X = 5) \approx P(4.5 < Y < 5.5)$$

### 6.3 Eşitsizliklerde Dikkat

Özellikle $P(X < 10)$ gibi ifadelerde dikkatli olmak gerekir. $X$ negatif binom olsun, yani kesikli olsun, ve onu normal dağılımla yaklaşık hesaplayalım. Yaklaşımdan sonra doğrudan "normal değişkenin 10'dan küçük olma olasılığı"nı hesaplamak yanlış olur.

Değerleri eksende düşünelim: bir tarafta 9, bir tarafta 10 var. Yaklaşımda 10 artık bir nokta değil, 9.5'ten 10.5'e kadar olan bir bölgedir. Biz 10'dan küçük olmayı istiyoruz ve 10'un bölgesi 9.5'te başlıyor. Öyleyse:

$$P(X < 10) \approx P(Y < 9.5)$$

### 6.4 Ne Zaman Yapılır, Ne Zaman Yapılmaz?

Düzeltme yalnızca kesikli bir dağılımı sürekli bir dağılımla yaklaşık hesaplarken gerekir. Sürekli bir dağılımı başka bir sürekli dağılımla yaklaşık hesaplarken gerekmez.

- **Binom ya da negatif binom, normal ile:** Kesikliden sürekliye geçiş var, düzeltme yapılır.
- **Gama, normal ile:** İkisi de sürekli, düzeltme yapılmaz.

> **Hocanın vurgusu:** Bu ayrıma dikkat edin. Gamayı normal ile yaklaşık hesaplarken süreklilik düzeltmesi yapılmaz.

Böylece Baron'un kitabının 4. bölümü, yani sürekli dağılımlar bitti. Bununla olasılık kısmı da tamamlanmış oldu. Sıradaki konu istatistiktir.

## 7. İstatistiğe Giriş: Popülasyon, Parametre, Örnekleme

Baron'un kitabında istatistik konuları 8. bölümle başlar. İstatistiğin ne olduğunu söylemeden önce bazı terimleri tanımlamamız gerekiyor.

### 7.1 Popülasyon ve Parametre

**Popülasyon (population)**, ilgilendiğimiz bütün birimlerdir. Türkiye'deki insanların ağırlıklarıyla ilgileniyorsak, her bir kişinin ağırlığı popülasyonumuzu oluşturur.

Popülasyonların olasılık dağılımları, bu dağılımların da parametreleri vardır. Örneğin Türkiye'deki insanların ağırlıklarının normal dağıldığını varsayalım. Normal dağılımın iki parametresi vardır: $\mu$ ve standart sapma $\sigma$. Bu dağılımı bulmak istiyorsak $\mu$ ve $\sigma$'yı bulmamız yeter; ikisini bulursak bütün dağılımı elde ederiz.

### 7.2 Neden Bütün Popülasyonu Ölçemiyoruz?

Parametrelerin gerçek değerini bulmak için Türkiye'deki her bir kişinin ağırlığını bilmek gerekir. Hoca nüfusu sınıfa sordu ve yaklaşık 83 milyon olarak aldı. $\mu$'yü bulmak için 83 milyon ağırlığı toplayıp 83 milyona bölmemiz gerekir. Sorun şudur: Herkesin ağırlığını almak son derece pahalıdır. Bu yüzden gerçek parametreleri pratikte bulamayız.

### 7.3 Örnekleme

Bunun yerine, Türkiye'den rastgele, diyelim ki 1000 kişi seçer ve ağırlıklarını ölçeriz. Bu kişileri seçmeye **örnekleme (sampling)** denir: popülasyondan 1000 ağırlık örneklemiş oluruz. Örnekleme aslında bir veri toplama işidir. Topladığımız verinin gerçek popülasyonu temsil etmesini umarız. Toplanan veriden, yani **örneklemden (sample)**, $\mu$'nün ne olduğunu tahmin edebiliriz.

<!-- BELİRSİZ: 01:07:49'da altyazıda bir kez "10,000 people" geçiyor. Hemen önceki ve sonraki cümlelerde 1000 olduğu için 1000 yazıldı. -->

## 8. Tahmin, Şapkalı Gösterim ve İstatistik

### 8.1 Tahmin Gerçek Parametre Değildir

Bin ağırlıktan hesapladığımız şey $\mu$ değildir, $\mu$ için bir tahmindir (estimate). Mutlaka bir hata olacaktır; bulduğumuz şey tam değer olmayacaktır. Bu yüzden ona $\mu$ yerine başka bir ad veririz: Bu derste **örneklem ortalaması (sample mean)** diyeceğiz. Bu ad, örneklemden elde edilen ortalama olmasından gelir.

Genel olarak, bir $\theta$ parametresinin tahminini $\hat{\theta}$ ile gösteririz; üzerinde bir şapka vardır. $\lambda$'yı tahmin etmek istiyorsak tahmini $\hat{\lambda}$'dır. Ama çok önemli bazı parametreler için özel adlar ve işaretler kullanılır. $\mu$'nün tahminini $\hat{\mu}$ diye yazmayız; o, örneklem ortalamasıyla tahmin edilir.

Bu tahminlere **istatistik (statistics)** denir. Hoca "estimate"in Türkçesini sınıfa sordu ve "tahmin" cevabını aldı: Tahminlerimize istatistik diyoruz.

**Soru:** Sample mean'deki "mean" de ortalama demek değil mi?

**Cevap:** Evet, ortalama demektir. Hepsini toplayıp eleman sayısına böleceksiniz.

### 8.2 Türkçe Tekrar: Gama Örneği

Hoca bu kısmı Türkçe olarak yineledi ve bu kez normal yerine gama dağılımını örnek aldı. İnsanların kilolarının gama dağılımıyla dağıldığını varsayalım. Gamanın iki parametresi vardır: $\alpha$ ve $\lambda$. Popülasyonun gerçek $\alpha$ ve $\lambda$'sını bulma şansımız yoktur, çünkü 83 milyon kişi gerekir. Bin kişi seçer ve $\alpha$ ile $\lambda$'yı o bin değerden tahmin ederiz. $\alpha$'nın tahminine "alfa şapka" ($\hat{\alpha}$), $\lambda$'nın tahminine "lambda şapka" ($\hat{\lambda}$) deriz.

> **Hocanın vurgusu:** Tahminlerle popülasyondaki gerçek parametreyi karıştırmak istemiyoruz. Çünkü popülasyon değerini hiçbir zaman tam bulamayacağız, her zaman bir hata olacak. Şapka, bu ikisini ayırt etmek içindir.

Tahminler genelde şapkalı yazılır, ama birkaç şeye özel ad verilmiştir. Beklenen değer $\mu$'nün tahmini için $\bar{X}$ ("X bar", örneklem ortalaması) kullanılır. $X$'in varyansının tahmini küçük $s$'nin karesiyle, yani $s^2$ ile gösterilir ve buna örneklem varyansı (sample variance) denir. Bu birkaç özel ad dışında, şapkalı bir şey gördüğünüzde tahmin anlamına gelir.

<!-- BELİRSİZ: 01:13:57-01:17:18 ve 01:18:43-01:20:03 aralığındaki Türkçe anlatım altyazıda bozuk ve uzun döngülü. Gama örneğinin girişi ile gamada beklenen değerin normalden farkına dair kısım (01:18:33-01:19:16) tam okunamadı. -->

## 9. Hata Kaynakları

Tahminlerde mutlaka hata olacağını söylemiştik. Bu hata, toplanan örneklem ile bütün popülasyon arasındaki farktan (discrepancy) kaynaklanır ve tahminlerimizde kendini gösterir. İki kaynağı vardır:

- **Örnekleme hatası (sampling error):** Örnek sayısından gelir. Daha çok örnek alırsanız hata azalır. Mümkünse daha çok örnek alın. $n$ sonsuza giderse bu hata sıfıra gider. İdeal olarak bütün popülasyonu kullanabilirseniz örnekleme hatası sıfır olur. Ama genelde bütün popülasyona bakacak para ya da zaman yoktur, bu yüzden sıfır olmaz.
- **Örnekleme dışı hata (non-sampling error):** Yanlış teknikten gelir. Örnekleme için yanlış bir yöntem kullanırsanız tahminleriniz bir şekilde değişir.

Örnekleme dışı hatayı yok etmek için doğru yöntemi, yani basit rastgele örneklemeyi kullanırız.

## 10. Basit Rastgele Örnekleme

### 10.1 Tanım ve Şartlar

**Basit rastgele örnekleme (simple random sampling)**, birimlerin bütün popülasyondan, birbirinden bağımsız ve hepsi eşit olasılıkla seçildiği bir örnekleme tasarımıdır. Üç şartı vardır:

- **Bütün popülasyondan seçim:** Birimler, yani gözlemler, popülasyonun tamamından alınır.
- **Bağımsızlık:** Burada kastedilen birimlerin seçiminin bağımsız olmasıdır. Ağırlığımı almak için benim seçilmem, aynı apartmandaki birinin seçilme olasılığını etkilemez. Ben seçildiysem yanımdaki kişi, benim seçilmemden bağımsız olarak seçilebilir de seçilmeyebilir de.
- **Eşit olasılık:** Bütün birimlerin seçilme olasılığı aynıdır.

### 10.2 Yanlış Örnekleme: Yalnız İstanbul

Türkiye'deki ağırlıkların beklenen değeriyle ilgilendiğimizi düşünelim. Yalnızca İstanbul'daki insanları seçip tartarsak bu uygun olur mu? Hayır, çünkü her yerden, yani bütün popülasyondan, 83 milyon kişinin hepsinden seçmeliyim.

Ayrıca her birim eşit olasılıkla seçilmelidir. İlk seçimde her kişinin seçilme şansı $1/83\,000\,000$ olmalıdır. Sonraki seçimlerde bu olasılık değişir, ama sonuçta herkesin seçilme olasılığı tam olarak aynı olmalıdır.

### 10.3 Örnek: Banka Hesapları

Bir bankanın toplam $N$ hesabı olsun; hoca sayı olarak 3 milyonu söyledi. Banka bu hesaplardan 1000 tanesini örneklemek istiyor. Yöntem şöyledir:

1. $X_1 \sim U(0, N)$ dağılımından rastgele bir sayı üretilir. Bu bir gerçel sayıdır.
2. Tavanı alınır: Hesap numarası $\lceil X_1 \rceil$ olur. Bu, örnekleme giren ilk hesaptır.
3. Seçilen hesap bir daha seçilmemeli, kalan hesapların da seçilme olasılığı eşit olmalıdır. Bu yüzden ikinci sayı $X_2 \sim U(0, N-1)$ dağılımından üretilir.
4. Yeni hesap numarası $\lceil X_2 \rceil$ olur.
5. 1000 hesap seçilene kadar aynı biçimde devam edilir (ara adım eklendi).

> **Ek bilgi (derste anlatılmadı):** Burada seçilen hesap bir daha seçilmediği için seçimler kesin anlamda tam bağımsız değildir; büyük olasılıkla hocanın "bağımsız" derken kastettiği, bir kişinin seçilmesinin başka bir kişiyi kayırmaması ya da dışlamamasıdır. Ayrıca ikinci adımda $\lceil X_2 \rceil$ değeri büyük olasılıkla doğrudan hesap numarası değil, kalan hesapların listesindeki sıradır; aksi hâlde seçilmiş hesap yine çıkabilir.

## 11. Örneklemi Rastgele Değişken Listesi Olarak Görmek ve CPU Verisi

İyi bir örneklemimiz varsa artık istatistikleri hesaplamaya başlayabiliriz. Basit betimleyici istatistiklere (descriptive statistics) geçiyoruz, ama bunun için önce bir örneklem gerekiyor.

Bir örneklemi, rastgele değişkenlerden oluşan bir tuple olarak gösteririz:

$$S = (X_1, X_2, \dots, X_n)$$

Hoca tuple'ı Python'daki kullanımıyla, liste benzeri ve elemanları değişmeyen bir yapı olarak hatırlattı.

<!-- BELİRSİZ: 01:36:10-01:36:18 aralığında altyazı "double list", "the difference between elements are not changing", "Python" diye geçiyor. Tuple açıklaması bu parçalardan kuruldu; ekrandaki yazı altyazıda okunmuyor. Ayrıca 01:35:02'de altyazıda "non-random variables" geçiyor; hemen sonraki Türkçe açıklama "rastgele değişken listesi" dediği için rastgele değişken olarak yazıldı. -->

Neden değer listesi değil de rastgele değişken listesi diyoruz? Çünkü değerleri toplamadan önce onları bilmiyoruz. Dolayısıyla her birine bir rastgele değişken gözüyle bakacağız ve istatistikleri de bu rastgele değişkenler üzerinden düşüneceğiz. Bu gösterim, toplanmadan önceki örneklemdir.

Örneklem toplandıktan sonra elimizde veri olur. Hoca örnek olarak Baron'un kitabındaki CPU verisini kullandı. Bu veri yine bir tuple olarak düşünülebilir, ama artık rastgele değişkenler yerine gerçek değerler içerir. $n = 30$'dur, yani örneklemde 30 gözlem vardır.

<!-- BELİRSİZ: 01:37:21-01:38:05'te CPU verisinin ham sırası altyazıda yalnız ilk 9 değer için okunuyor (70, 36, 43, 69, 82, 48, 34, 62, 35); kalanı ekrandan yazıldı. Ham sıra bu yüzden verilmedi. Verinin sıralı hâli Bölüm 15.4'tedir. -->

## 12. Örneklem Ortalaması

### 12.1 Tanım

Örneklem ortalaması (sample mean) aritmetik ortalamadır. Bütün değişkenler toplanır ve değişken sayısı $n$'e bölünür:

$$\bar{X} = \frac{1}{n}\sum_{i=1}^{n} X_i = \frac{X_1 + X_2 + \dots + X_n}{n}$$

Örneklem ortalaması, popülasyon ortalamasını, yani beklenen değeri ($\mu$) tahmin eder.

### 12.2 Beklenen Değeri

Örneklem ortalamasının kendisinin de beklenen değerinden söz edebiliriz, çünkü o da bir rastgele değişkendir. Hesabına bakın: $X_1, X_2, \dots, X_n$ birer rastgele değişkendir, toplamları da rastgele değişkendir, $n$'e bölünmesi de öyle.

Tanımdan başlayalım:

$$E[\bar{X}] = E\left[\frac{X_1 + X_2 + \dots + X_n}{n}\right]$$

Toplamın beklenen değeri, tek tek beklenen değerlerin toplamıdır. Sabit olan $n$'i de dışarı alabiliriz:

$$E[\bar{X}] = \frac{1}{n}E[X_1] + \frac{1}{n}E[X_2] + \dots + \frac{1}{n}E[X_n]$$

Şimdi kritik soru: $E[X_1]$ nedir? Bir gözlemin, daha seçilmeden önceki beklenen değeri, popülasyonun beklenen değeridir. Bu yüzden her terime alt indissiz $E[X]$ ya da $\mu$ yazabiliriz:

$$E[\bar{X}] = \frac{1}{n}E[X] + \frac{1}{n}E[X] + \dots + \frac{1}{n}E[X]$$

Toplamda $n$ tane terim olduğundan $n$'ler sadeleşir:

$$E[\bar{X}] = E[X] = \mu$$

> **Hocanın vurgusu:** Bu önemlidir. Örneklem ortalamasının beklenen değeri, popülasyonun beklenen değeridir.

### 12.3 Varyansı

Varyans için de tanımdan başlanır: $\mathrm{Var}(\bar{X}) = \mathrm{Var}\left(\frac{X_1 + \dots + X_n}{n}\right)$. Hoca hesabı alıştırma olarak bıraktı ve sonucu verdi:

$$\mathrm{Var}(\bar{X}) = \frac{\mathrm{Var}(X)}{n} = \frac{\sigma_X^2}{n}$$

Burada $\sigma_X^2$, popülasyon varyansıdır. Standart sapma varyansın karekökü olduğundan:

$$\mathrm{Std}(\bar{X}) = \frac{\sigma_X}{\sqrt{n}}$$

> **Ders sonrası not:** Hoca varyansın "popülasyondaki birim sayısına" bölündüğünü söyledi. Doğrusu, popülasyon varyansı örneklemdeki birim sayısı $n$'e bölünür; formüldeki $n$ örneklem büyüklüğüdür.

> **Ek bilgi (derste anlatılmadı):** Alıştırmanın adımları büyük olasılıkla şöyledir. Sabit çarpan varyanstan karesiyle çıkar: $\mathrm{Var}(\bar{X}) = \frac{1}{n^2}\mathrm{Var}(X_1 + \dots + X_n)$. Değişkenler bağımsız olduğu için toplamın varyansı varyansların toplamıdır, yani $n\sigma_X^2$. Sonuç $\frac{n\sigma_X^2}{n^2} = \frac{\sigma_X^2}{n}$ olur.

### 12.4 Dağılımı

Birim sayısı $n$ büyükse örneklem ortalaması normal dağılır. Bunu doğrudan merkezi limit teoreminden çıkarabilirsiniz. $n$ büyük değilse $t$ dağılımı (t distribution) kullanılır.

> **Ders sonrası not:** Hoca "$n$ küçükse örneklem ortalaması $t$ dağılır" dedi. Kesin ifade büyük olasılıkla şudur: Popülasyon normal ve $\sigma$ bilinmiyorsa, $\sigma$ yerine örneklem standart sapması $s$ konularak standartlaştırılan $\frac{\bar{X} - \mu}{s/\sqrt{n}}$ değeri $t$ dağılır.

## 13. İyi Bir Tahmin Edicinin Özellikleri

Tahmin ediciler (estimators) söz konusu olduğunda üç kavram önemlidir: yanlılık (bias), tutarlılık (consistency) ve asimptotik normallik (asymptotic normality).

<!-- BELİRSİZ: Altyazıda "bias" sözcüğü "Bayes", "Bs" gibi, $\hat{\theta}$ ise "teta het", "Tether head" gibi bozuk geçiyor. Bağlamdan ve "unbiased" kullanımından "bias" olduğu anlaşılıyor; Bayes teoremiyle ilgisi yoktur. -->

### 13.1 Yanlılık ve Yansızlık

$\theta$ parametresini $\hat{\theta}$ ile tahmin edelim. Tahmin edicinin yanlılığı, tahmin ile popülasyon parametresi arasındaki farkın beklenen değeridir, yani hatanın beklenen değeridir:

$$\mathrm{Bias}(\hat{\theta}) = E[\hat{\theta} - \theta]$$

Yanlılık sıfırsa $\hat{\theta}$'ya **yansız tahmin edici (unbiased estimator)** denir. İyi tahmin ediciler yansızdır.

Hoca bunu bir çizimle anlattı. Birden çok örneklem oluşturabileceğimiz için birden çok tahmin üretebiliriz. Eksende tahmin edilecek $\theta$ işaretli olsun:

- **Yanlı tahmin edici:** Tahminler hep yanlış yerdedir, hedefin tam üzerinde toplanmaz.
- **Yansız tahmin edici:** Tahminler $\theta$'nın çevresinde toplanır. Beklenen değerleri $\theta$ ile çakışır.

Peki örneklem ortalaması yanlı mı, yansız mı? Örneklem ortalaması yansızdır, bu iyi bir şeydir. Hoca gösterimini alıştırma olarak bıraktı. Bölüm 12.2'deki sonuç bunu doğrudan verir (ara adım eklendi): $E[\bar{X}] = \mu$ olduğundan $\mathrm{Bias}(\bar{X}) = E[\bar{X} - \mu] = \mu - \mu = 0$.

> **Hocanın vurgusu:** Yansız olmak bir tahmin edici için önemlidir.

### 13.2 Tutarlılık

Bir $\hat{\theta}$ tahmin edicisi şu koşulu sağlıyorsa tutarlıdır (consistent): Tahmin ile popülasyon parametresi arasındaki farkın $\varepsilon$'dan büyük olma olasılığı, birim sayısı $n$ sonsuza giderken sıfıra gider.

$$P\left(|\hat{\theta} - \theta| > \varepsilon\right) \to 0 \quad (n \to \infty)$$

Başka bir deyişle, hatanın bir eşiğin üzerinde olma olasılığı sıfıra gitmelidir. Örneklem ortalaması tutarlıdır. Hoca bunun gösterimini de alıştırma olarak bıraktı.

> **Ek bilgi (derste anlatılmadı):** Büyük olasılıkla en kısa yol Chebyshev eşitsizliğidir. $E[\bar{X}] = \mu$ ve $\mathrm{Var}(\bar{X}) = \sigma^2/n$ olduğundan $P(|\bar{X} - \mu| > \varepsilon) \le \frac{\sigma^2}{n\varepsilon^2}$ yazılır. Sağ taraf $n \to \infty$ iken sıfıra gider.

### 13.3 Asimptotik Normallik

Bir tahmin edici, $n$ sonsuza giderken kendi dağılımı normal dağılıma gidiyorsa asimptotik normaldir (asymptotically normal). Birim sayısı arttıkça tahmin edicinin dağılımı normale yaklaşmalıdır. "Asimptotik olarak" burada basitçe "örnek sayısı çok olduğunda" demektir.

Örneklem ortalamasının asimptotik normal olduğunu zaten söylemiştik: $n$ büyükse dağılımı normaldir. Bu, merkezi limit teoreminden gelir. Örneklem ortalamasının içinde bir toplam vardır ve $n$ büyükse bu toplamın dağılımı normale gider.

## 14. Medyan

### 14.1 Merkezi Ölçen Başka Bir Tahmin Edici

Medyan (median), popülasyonun merkezini ölçen başka bir değerdir ve aykırı değerlere (outliers) karşı dayanıklıdır (robust). Popülasyon medyanını derste daha önce görmemiştik, bugün öğreniyoruz. Hoca bunun aslında olasılık kısmında, ortalama ve varyansın yanında işlenmesi gerektiğini söyledi. Gösterim şöyledir:

- $M$: popülasyon medyanı
- $\hat{M}$: popülasyon medyanının tahmini, yani örneklem medyanı (sample median)

### 14.2 Popülasyon Medyanının Tanımı

Popülasyon medyanı $M$ şu iki koşulla tanımlanır:

$$P(X > M) \le 0.5 \qquad \text{ve} \qquad P(X < M) \le 0.5$$

Bu iki eşitsizlik birleştirilip kümülatif dağılımla yazılabilir: $F(M) = 0.5$. Hesap yaparken sürekli ve kesikli durumları ayrı düşünmek gerekir.

### 14.3 Sürekli Dağılımda Medyan

Sürekli dağılımda doğrudan $F(M) = 0.5$ denklemi çözülür.

**Örnek:** $F(x) = 1 - e^{-\lambda x}$, $x > 0$ dağılımının medyanını bulalım.

$$1 - e^{-\lambda M} = 0.5$$

$$e^{-\lambda M} = 0.5 \quad \text{(ara adım eklendi)}$$

$$M = \frac{\ln 2}{\lambda}$$

> **Ders sonrası not:** Hoca bu ifadeyi okurken "$f$ of $x$" dedi. Hesapta kümülatif değerle kullanıldığından bu, yoğunluk fonksiyonu değil, kümülatif dağılım fonksiyonudur (CDF); bu yüzden büyük $F$ ile yazıldı. Python ile hesaplandı: Farklı $\lambda$ değerleri için $F(\ln 2/\lambda) = 0.5$ çıkıyor.

### 14.4 Kesikli Dağılımda Medyan

Kesikli dağılımda biraz daha karmaşıktır. Yine $F(M) = 0.5$ denklemini çözeriz, ama CDF basamaklı olduğu için iki durum ortaya çıkar: Denklemin çok kökü vardır ya da hiç kökü yoktur.

**Durum A: Çok kök.** CDF grafiğini düşünün. Eksende 1, 2, 3 var. Fonksiyon 1'e kadar bir değerde, 1'den 2'ye kadar başka bir değerde, 2'den 3'e kadar yine başka bir değerde. 0.5 değeri bu yatay basamaklardan birinin tam üzerine denk gelsin, örneğin 1 ile 2 arasındaki basamağa. O aralıktaki bütün değerler denklemin köküdür, yani $[1, 2)$ aralığındaki her değer medyandır. 1 medyandır, 1.2 medyandır, 1.5 medyandır, çünkü hepsinin kümülatif değeri 0.5'tir.

> **Ders sonrası not:** Hoca aralığı $[1, 2)$ olarak verdi. Fakat $F$, 2'de zıplıyorsa, hocanın verdiği iki eşitsizliği 2 de sağlar: $P(X < 2) = 0.5$ ve $P(X > 2) < 0.5$. Dolayısıyla tanıma göre aralık $[1, 2]$'dir. $F(M) = 0.5$ denkleminin kökleri ise $[1, 2)$'dir; fark, denklem ile eşitsizliklerin ayrışmasından gelir.

**Durum B: Kök yok.** Aynı grafikte bu kez 0.5 değeri yatay basamakların hiçbirine denk gelmesin. Yani kümülatif değeri 0.5 olan hiçbir $x$ yoktur; CDF 0.5'in üzerinden atlar. Bu durumda kümülatif değeri 0.5'e eşit ya da ondan büyük olan en küçük $x$ medyandır. Hocanın çiziminde CDF, $x = 1$ noktasında 0.5'in üstüne çıkıyordu. Bu yüzden orada medyan 1'dir.

### 14.5 Örneklem Medyanı

Örneklem medyanı basittir: Değerler sıralanır ve ortadaki değer alınır. Örneklem olduğu için şapkalı yazılır: $\hat{M}$.

- **Tek sayıda eleman:** $(2, 2, 3)$ zaten sıralıdır. Ortadaki değer $\hat{M} = 2$'dir.
- **Çift sayıda eleman:** $(2, 2, 3, 3)$ için tek bir orta eleman yoktur; ortadaki iki eleman da ortadadır. Baron'a göre $[2, 3]$ aralığındaki her sayı medyandır. Burada yine birden fazla medyan vardır.

## 15. Kantiller

Medyan aslında kantil (quantile) dediğimiz şeyin özel bir hâlidir. Kantiller, medyanın genelleştirilmiş biçimidir.

### 15.1 Popülasyon Kantili

Bir popülasyonun $p$-kantili $q_p$, şu koşulları sağlayan sayıdır:

$$P(X < q_p) \le p \qquad \text{ve} \qquad P(X > q_p) \le 1 - p$$

> **Ders sonrası not:** Hoca ilk koşulu sözlü olarak "$P(X < q_p)$, $p$'dir" diye okudu. Medyan tanımıyla ve ikinci koşulla uyumlu genel biçim eşitsizliktir; eşitlik aşağıda görüldüğü gibi sürekli dağılımlarda geçerlidir.

Bu tanım kümülatif olasılıkla çok yakından ilişkilidir. Sürekli dağılımlarda ilk ifade doğrudan kümülatif değerdir:

$$F(q_p) = p$$

Dolayısıyla kantili, kümülatif dağılım fonksiyonunun tersi gibi düşünebilirsiniz:

$$q_p = F^{-1}(p)$$

İki grafikle düşünmek yardımcı olur:

- **Yoğunluk grafiğinde:** $q_p$, kendisinden önceki alanın $p$ olduğu noktadır.
- **CDF grafiğinde:** Fonksiyon 0'dan 1'e doğru gider. $q_p$, kümülatif değeri $p$ olan noktadır.

### 15.2 Örneklem Kantili

Elimizde dağılım değil de bir örneklem varsa örneklem kantillerini bulmamız gerekir. Örneklem $p$-kantili $\hat{q}_p$, örneklemin en fazla $100p$ yüzdesini aşan ve örneklemin en fazla $100(1-p)$ yüzdesi tarafından aşılan değerdir.

Bunu sıralı örneklem üzerinde düşünelim. $\hat{q}_p$ sıralı dizide bir yerde olsun. Ondan küçük birimlerin sayısı en fazla yüzde $100p$, ondan büyük birimlerin sayısı en fazla yüzde $100(1-p)$ olmalıdır.

### 15.3 Basit Hesap Yöntemi

Bu tanımla hesap yapmak biraz kafa karıştırıcıdır. Bu yüzden basit bir yöntem kullanılır:

1. Örneklem $S$ sıralanır. Yöntemi kullanmadan önce sıralamak şarttır.
2. $\hat{q}_p$, sıralı örneklemde $p(n+1)$ indisli birimdir.
3. $p(n+1)$ tamsayı değilse sayı yuvarlanır ya da öncesindeki ve sonrasındaki iki noktanın ortalaması alınır.

Dolayısıyla bu dersteki formül şöyledir:

$$\hat{q}_p = S_{\mathrm{round}(p(n+1))}$$

> **Hocanın vurgusu:** Yuvarlama keyfîdir, yalnızca bir uzlaşımdır (convention). Tavan da alınabilir, yani sonraki eleman seçilebilirdi. Bu derste "round" kullanılacak.

<!-- BELİRSİZ: 02:53:10-02:53:17'de altyazıda uzlaşım "median" diye geçiyor; 02:53:24'te hoca "I will use round here" dediği için "round" yazıldı. -->

### 15.4 Örnek: CPU Verisi

CPU verisinde 0.25-kantil, 0.75-kantil ve medyanı bulalım. Medyan, 0.50-kantilden başka bir şey değildir. Sıralı veri, $n = 30$:

| Sıra | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| Değer | 9 | 15 | 19 | 22 | 24 | 25 | 30 | 34 | 35 | 35 |

| Sıra | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 |
|---|---|---|---|---|---|---|---|---|---|---|
| Değer | 36 | 36 | 37 | 38 | 42 | 43 | 46 | 48 | 54 | 55 |

| Sıra | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 |
|---|---|---|---|---|---|---|---|---|---|---|
| Değer | 56 | 56 | 59 | 62 | 69 | 70 | 82 | 82 | 89 | 139 |

<!-- BELİRSİZ: Altyazıda sıralı liste 55'e kadar okunuyor (02:48:03-02:49:08); son 10 değer kısa nottan alındı. Eleman sayısı 30'dur ve hocanın verdiği 59 sonucuyla uyumludur. 02:51:53-02:52:06'da bir uyarı üzerine hoca "this should be six" diyerek ekranda bir şeyi düzeltti; neyi düzelttiği altyazıda okunmuyor. -->

**0.25-kantil:**

- İndis: $p(n+1) = 0.25 \cdot (30 + 1) = 7.75$
- Tamsayı değil, yuvarlanır: $\mathrm{round}(7.75) = 8$
- Sıralı veride 8. değer: $\hat{q}_{0.25} = S_8 = 34$

> **Ders sonrası not:** Hoca yuvarlamanın keyfî olduğunu anlatırken 7.75'in "yedinci ile altıncı arasında" olduğunu ve "34 ile 35 arasındaki her değerin 0.25-kantil olduğunu" söyledi. 7.75 aslında 7. değer (30) ile 8. değer (34) arasındadır. Python ile hesaplandı: Bölüm 15.2'deki tanımı yalnız 34 sağlar. 34'ten küçük 7 değer ($\le 7.5$), büyük 22 değer ($\le 22.5$) vardır. 34 ile 35 arasındaki bir sayı ya da 35 için küçük değer sayısı 8 olur ve 7.5'i aşar.

**0.75-kantil:**

- İndis: $0.75 \cdot 31 = 23.25$
- Yuvarlanır: $\mathrm{round}(23.25) = 23$
- Sıralı veride 23. değer: $\hat{q}_{0.75} = S_{23} = 59$

Hocanın verdiği sonuç 59'dur. Python ile hesaplandı: Tanımı da yalnız 59 sağlar.

**Medyan (0.50-kantil):**

- İndis: $0.5 \cdot 31 = 15.5$
- Yuvarlanır: $\mathrm{round}(15.5) = 16$
- Sıralı veride 16. değer: $\hat{M} = S_{16} = 43$

> **Ders sonrası not:** Hoca medyanın $S_{16}$ olduğunu doğru söyledi, ama değer olarak "48" dedi. Python ile hesaplandı: $S_{16} = 43$'tür; 48 ise 18. değerdir. Bölüm 15.3'teki iki komşunun ortalaması seçeneği $(42 + 43)/2 = 42.5$ verir. Baron'un $(2, 2, 3, 3)$ örneğindeki gibi, tanımı $[42, 43]$ aralığındaki her sayı sağlar. 48 tanımı sağlamaz: ondan küçük 17 değer vardır ve 15'i aşar.

Hoca 0.75-kantil ile medyanı evde alıştırma olarak yapmayı önerdi.

<!-- BELİRSİZ: 02:53:52'de altyazıda "0.58 quantiles" geçiyor; bağlamdan 0.50-kantil olduğu anlaşılıyor. -->

## Dersin Toparlaması

Dersin ilk kısmında olasılığın son parçasını bitirdik. Merkezi limit teoremi, i.i.d. değişkenlerin toplamının $n$ büyüdükçe $N(n\mu, n\sigma^2)$'ye gittiğini söyler ve pratikte $n \ge 30$ için kullanılır. Bunu disk örneğinde uyguladık ve 300 resmin 330 MB'ye sığma olasılığını $0.9997$ bulduk. Binom, gama ve negatif binom da toplam olarak yazılabildiği için normal ile yaklaşık hesaplanabilir. Yaklaşılan dağılım kesikliyse süreklilik düzeltmesi yapılır, gamada yapılmaz.

İkinci kısımda istatistiğe girdik. Popülasyonun gerçek parametrelerini bulamadığımız için örneklem alıp bu parametreleri tahmin ediyoruz ve tahminlere istatistik diyoruz. Örnekleme hatası örnek sayısıyla azalır, örnekleme dışı hata ise basit rastgele örneklemeyle önlenir. Örneklem ortalamasının $E[\bar{X}] = \mu$, $\mathrm{Var}(\bar{X}) = \sigma^2/n$ olduğunu ve yansız, tutarlı, asimptotik normal bir tahmin edici olduğunu gördük. Ardından medyanı ve onun genelleştirilmiş hâli olan kantilleri popülasyon ve örneklem için tanımladık, CPU verisinde hesapladık. Hoca örneklem varyansını ileride ele alacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
