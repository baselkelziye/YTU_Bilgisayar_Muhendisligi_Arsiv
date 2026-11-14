# Ders 3 Genişletilmiş Notu: Alterne Seriler, Mutlak ve Şartlı Yakınsaklık, Kuvvet Serileri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Geçen Haftanın Testlerinin Tekrarı
- 2. Gabriel Borusu Paradoksu
- 3. Alterne Seriler ve Leibniz Testi
- 4. Mutlak ve Şartlı Yakınsaklık
- 5. Seri Testlerinin Özeti
- 6. Kuvvet Serileri: Tanım, Merkez, Yarıçap ve Aralık
- 7. Kuvvet Serilerinin Yakınsaklık Aralığı Örnekleri
- 8. Kuvvet Serileriyle İşlemler
- 9. Temel Açılım: $\frac{1}{1-x}$ ve Türetilen Seriler
- 10. Terim Terim Türev ve İntegral
- 11. Örnek Sorular

## 1. Geçen Haftanın Testlerinin Tekrarı

Ders, Zoom üzerinden online yapıldı. Hoca derse seriler konusuna devam edileceğini söyleyerek başladı. Yeni konuya geçmeden önce geçen haftanın testlerini yaklaşık beş dakikada özetledi. Hocanın genel mesajı şuydu: Bir serinin karakterini (yakınsak mı, ıraksak mı) bulmak için tek bir yöntem her zaman işe yaramaz. Uçaktan paraşütle atlarken yedek paraşüt taşınır. Biri açılmazsa diğeri açılır. Seri testleri de böyledir: bir test sonuç vermezse başka bir teste geçilir. Bu yüzden hepsini kavramak gerekir. Hocaya göre anlamak da yetmez, bol bol soru çözmek gerekir.

### 1.1 İntegral testi

**İntegral testi (integral test)**

- $\sum a_n$ serisinde $a_n=f(n)$ olsun.
- $f$, $[1,\infty)$ aralığında pozitif, sürekli ve monoton azalan olsun.
- O zaman $\sum_{n=1}^{\infty} a_n$ serisi ile $\int_1^{\infty} f(x)\,dx$ integrali aynı karakterdedir.

Yani serinin yakınsak olup olmadığını bulmak yerine integralin sonucuna bakılır. İntegral yakınsaksa seri de yakınsaktır. Hoca burada önemli bir uyarı yaptı: İntegralin bir değere gitmesi, serinin toplamının da aynı değere gittiği anlamına gelmez. Test yalnızca karakteri söyler, toplamı vermez.

Hoca örnek olarak $\sum \frac{1}{n}$ serisini hatırlattı. Tahtada $y=\frac{1}{x}$ grafiğini çizdi. Bu seri, $\int_1^\infty \frac{dx}{x}$ ile aynı karakterdedir. Bu integral birinci dönem Matematik 1'de görülmüştü:

$$\int_1^\infty \frac{dx}{x}=\lim_{b\to\infty}\big[\ln x\big]_1^b=\lim_{b\to\infty}\ln b=\infty .$$

İntegral ıraksak olduğundan $\sum\frac1n$ de ıraksaktır.

### 1.2 Karşılaştırma (mukayese) testi

**Karşılaştırma testi (comparison test)**

- $\sum a_n$ ve $\sum b_n$ negatif olmayan terimli iki seri olsun.
- Her $n$ için $0\le a_n\le b_n$ olsun.
- $\sum b_n$ (büyük olan) yakınsak ise $\sum a_n$ (küçük olan) da yakınsaktır.
- $\sum a_n$ (küçük olan) ıraksak ise $\sum b_n$ (büyük olan) da ıraksaktır.

Hoca öğrencilere şunu sordu: Küçük olan $\sum a_n$ yakınsak ise büyük olan için bir şey söylenebilir mi? Cevap: Hayır. $\sum b_n$ yakınsak da olabilir, ıraksak da. Aynı şekilde büyük olan ıraksaksa küçük olan için bir şey söylenemez.

Hoca örnek olarak $\sum \frac{1}{n^2+1}$ serisini yazdı ve hangi seriyle karşılaştırılacağını sordu. Bir öğrenci $\sum\frac1{n^2}$ ile karşılaştırılmasını önerdi. $\frac{1}{n^2+1}\le\frac1{n^2}$ ve $\sum\frac1{n^2}$ yakınsak olduğundan $\sum\frac1{n^2+1}$ de yakınsaktır. Hoca buradan şu genel yöntemi çıkardı: Bilinmeyen bir seri, karakteri bilinen bir seriyle karşılaştırılır.

### 1.3 Limit karşılaştırma testi

**Limit karşılaştırma testi (limit comparison test)**

- $\sum a_n$ ve $\sum b_n$ pozitif terimli iki seri olsun. $\sum a_n$'nin karakteri bilinmiyor, $\sum b_n$'ninki biliniyor.
- $L=\lim_{n\to\infty}\dfrac{a_n}{b_n}$ hesaplanır.
- $0<L<\infty$ ise iki seri aynı karakterdedir.
- $L=0$ ve $\sum b_n$ yakınsak ise $\sum a_n$ yakınsaktır.
- $L=\infty$ ve $\sum b_n$ ıraksak ise $\sum a_n$ ıraksaktır.

Hoca aynı $\sum\frac{1}{n^2+1}$ örneğini bu testle de çözdü. Paydada baskın terim $n^2$ olduğundan $b_n=\frac1{n^2}$ seçilir:

$$L=\lim_{n\to\infty}\frac{1/(n^2+1)}{1/n^2}=\lim_{n\to\infty}\frac{n^2}{n^2+1}=1 .$$

$L=1$ sıfırdan ve sonsuzdan farklıdır. $\sum\frac1{n^2}$ yakınsak olduğundan $\sum\frac1{n^2+1}$ de yakınsaktır.

Hoca $L=0$ ve $L=\infty$ durumlarını sezgiyle de açıkladı. $\frac{a_n}{b_n}\to0$ ise $a_n$, $b_n$'den çok daha hızlı küçülür. Bu yüzden $b_n$'nin serisi yakınsaksa $a_n$'ninki de yakınsar. $\frac{a_n}{b_n}\to\infty$ ise $a_n$ daha büyüktür. $b_n$'nin serisi ıraksaksa $a_n$'ninki de ıraksar.

<!-- BELİRSİZ: 00:14:22-00:14:55 arasında altyazıda "beğen ıraksak ise aende ıraksak ise" ifadesi döngü halinde tekrar ediyor. Hocanın L=0 durumu için tam olarak ne söylediği okunmuyor. -->

> **Ders sonrası not:** Hoca $L=0$ durumunu anlatırken bir yerde "$\sum b_n$ ıraksak ise $\sum a_n$ ıraksak" gibi bir ifade kullandı. $L=0$ iken bu çıkarım yapılamaz. Doğrusu: $L=0$ ise yalnız "$\sum b_n$ yakınsak $\Rightarrow\sum a_n$ yakınsak" çıkarımı geçerlidir. "Iraksak $\Rightarrow$ ıraksak" çıkarımı $L=\infty$ durumuna aittir.

### 1.4 Oran testi

**Oran testi (ratio test)**

- $\sum a_n$ pozitif terimli bir seri olsun.
- $L=\lim_{n\to\infty}\dfrac{a_{n+1}}{a_n}$ hesaplanır.
- $L<1$ ise seri yakınsak, $L>1$ ise ıraksaktır.
- $L=1$ ise test sonuç vermez, "başka kapıya" gidilir.

Hoca bu testin nerede kullanıldığını özellikle vurguladı: Genel terimde kuvvetler ve faktöriyeller varsa oran testi kullanılır.

### 1.5 Kök testi

**Kök testi (root test)**

- $\sum a_n$ negatif olmayan terimli bir seri olsun.
- $L=\lim_{n\to\infty}\sqrt[n]{a_n}$ hesaplanır.
- $L<1$ ise yakınsak, $L>1$ ise ıraksak, $L=1$ ise test sonuç vermez.

Genel terimin tamamı $n$-inci kuvvette ise kök testi işi kolaylaştırır.

**Örnek 1:** $\displaystyle\sum_{n=2}^\infty \frac{1}{(\ln n)^n}$

- Genel terimde $n$-inci kuvvet var. Hocanın ifadesiyle "işimi bozuyor". Kökü alınır.
- $\sqrt[n]{a_n}=\sqrt[n]{\dfrac{1}{(\ln n)^n}}=\dfrac{1}{\ln n}$.
- $n\to\infty$ iken $\ln n\to\infty$, yani $\dfrac1{\ln n}\to0$.
- $L=0<1$ olduğundan seri yakınsaktır.

<!-- BELİRSİZ: Altyazıda kuvvet bir yerde "K'ıncı kuvvet", bir yerde "n" diye geçiyor. Örnekteki üs tahtada okunamıyor; çözüm n-inci kuvvete göre kuruldu. -->

## 2. Gabriel Borusu Paradoksu

Tekrarın ortasında hoca "sabah sabah uyanmanız için" bir paradoks sorusu sordu. Birinci dönemde görülmüş olabileceğini söyledi.

$y=\frac1x$ eğrisi ile $x$ ekseni arasında, $x\ge1$ için kalan bölge düşünülür.

**Soru 1: Bu bölgenin alanı var mıdır?**

$$A=\int_1^\infty\frac{dx}{x}=\lim_{b\to\infty}\ln b=\infty .$$

İntegral ıraksaktır. Bölgenin alanı sonlu değildir.

**Soru 2: Bu bölge $x$ ekseni etrafında döndürülürse oluşan cismin hacmi var mıdır?**

Disk yöntemiyle hacim $V=\pi\int_1^\infty \big(f(x)\big)^2\,dx$'tir:

$$V=\pi\int_1^\infty\frac{dx}{x^2}=\pi\left[-\frac1x\right]_1^\infty=\pi\big(0-(-1)\big)=\pi .$$

Paradoks şudur: Bölgenin alanı sonsuzdur, ama onu döndürerek elde edilen cismin hacmi sonludur.

> **Ders sonrası not:** Hoca hacmi hesaplarken başa $\pi$ koydu, ama sonucu "bir birim küp" diye söyledi. Doğrusu $V=\pi$ birim küptür. $1$, integralin $\pi$ çarpanı olmadan değeridir.

> **Ek bilgi (derste anlatılmadı):** Bu cisim literatürde büyük olasılıkla "Gabriel'in borusu" ya da "Torricelli'nin trompeti" adıyla bilinir. Yüzey alanı da büyük olasılıkla sonsuzdur. Bu yüzden "boyası sonlu miktarda boyayla doldurulabilir ama yüzeyi boyanamaz" diye anlatılır.

## 3. Alterne Seriler ve Leibniz Testi

### 3.1 Tanım

Hoca alterne seriyi (alternating series) öğrencilere sordu. Bir öğrenci "$a_1-a_2+a_3-\dots$ diye devam eden seriler" diye cevap verdi. Ardışık terimleri zıt işaretli olan seriye alterne seri denir. Genel biçimi:

$$\sum_{n=1}^\infty(-1)^{n}a_n \quad\text{ya da}\quad \sum_{n=1}^\infty(-1)^{n+1}a_n,\qquad a_n>0 .$$

Bir terim eksi, bir terim artı gelir.

### 3.2 Leibniz teoremi

Bu tür serilerin yakınsaklığı için Leibniz bir teorem vermiştir. Testte $(-1)^n$ çarpanı dışarıda bırakılır, yalnızca $a_n$'ye bakılır.

**Leibniz testi (alterne seri testi)**

- $\sum(-1)^n a_n$ verilsin. Şu üç koşula bakılır:
  - $a_n>0$ (pozitif; $(-1)^n$ zaten dışarıda).
  - Her $n$ için $a_{n+1}\le a_n$, yani $a_n$ monoton azalan. Bir önceki terim bir sonrakinden büyükse dizi azalıyordur.
  - $\lim_{n\to\infty}a_n=0$.
- Üçü de sağlanırsa $\sum(-1)^n a_n$ yakınsaktır.

> **Hocanın vurgusu:** Bunu unutmayın. Sınavlarda bununla ilgili soru geliyor.

**Örnek 2:** $\displaystyle\sum_{n=1}^\infty\frac{(-1)^{n-1}}{n^2}$

<!-- BELİRSİZ: Hoca seriyi 00:22:49'da "eksi bir üzeri n eksi bir" diye okudu, paydası tahtada. Sonuçta "toplam en karatörs, yakınsaktır" deniyor; payda n^2 olarak alındı. -->

Hoca öğrencilere bir dakika düşünme süresi verdi, sonra tahtada çözdü.

- Seri alternedir. $a_n=\dfrac{1}{n^2}$.
- Koşul 1: $a_n=\dfrac1{n^2}>0$.
- Koşul 2: $n$ arttıkça $\dfrac1{n^2}$ azalır, yani $a_{n+1}\le a_n$.
- Koşul 3: $\lim\limits_{n\to\infty}\dfrac1{n^2}=0$.
- Üç koşul sağlandığından seri yakınsaktır.

### 3.3 Harmonik seri ve alterne harmonik seri

**Örnek 3:** $\displaystyle\sum_{n=1}^\infty\frac1n$ yakınsak mıdır?

Bir öğrenci "ıraksaktır" diye cevap verdi. Hoca nedenini hatırlattı: Bu harmonik seridir. İntegral testiyle $\int_1^\infty\frac{dx}{x}$ ile aynı karakterdedir ve ıraksaktır. $p$-testiyle de görülür: $\sum\frac1{n^p}$ serisinde $p\le1$ ise ıraksak, $p>1$ ise yakınsaktır. Burada $p=1$'dir.

**Örnek 4:** $\displaystyle\sum_{n=1}^\infty\frac{(-1)^n}{n}$ yakınsak mıdır?

Hoca rengi maviye çevirip çözdü.

- Seri alternedir. $a_n=\dfrac1n$.
- $\lim\limits_{n\to\infty}\dfrac1n=0$.
- Monotonluk: Doğal sayılar için her zaman $n<n+1$'dir. Terslerini alınca eşitsizlik döner: $\dfrac1{n+1}<\dfrac1n$, yani $a_{n+1}<a_n$.
- Koşullar sağlandığından seri Leibniz testinden yakınsaktır.

Hoca sonucu şöyle bağladı: $\sum\frac1n$ ıraksaktır, ama işaretleri sırayla değiştirilmiş hali $\sum\frac{(-1)^n}n$ yakınsaktır.

## 4. Mutlak ve Şartlı Yakınsaklık

Hoca bu konunun sınavlarda gelen soru tiplerinden biri olduğunu söyledi.

**Tanım**

- $\sum|a_n|$ yakınsak ise $\sum a_n$ serisine **mutlak yakınsak** (absolutely convergent) denir.
- $\sum a_n$ yakınsak, ama $\sum|a_n|$ ıraksak ise $\sum a_n$ serisine **şartlı yakınsak** (conditionally convergent) denir.

> **Ek bilgi (derste anlatılmadı):** Büyük olasılıkla ders kitabında da geçen bir teoreme göre mutlak yakınsak her seri yakınsaktır. Yani $\sum|a_n|$ yakınsaksa $\sum a_n$'nin ayrıca yakınsak olduğunu göstermeye gerek yoktur. Derste hoca her örnekte iki adımı da (serinin kendisi ve mutlak değeri) ayrı ayrı kontrol etti.

**Örnek 5:** Şartlı yakınsak bir seriye örnek veriniz.

Hoca bu soruyu öğrencilere sordu. Cevabı geçen örnekten verdi: $\sum\frac{(-1)^n}{n}$.

- Serinin kendisi Leibniz testinden yakınsaktır (Örnek 4).
- Mutlak değeri alınınca $(-1)^n$ gider: $\sum\left|\frac{(-1)^n}{n}\right|=\sum\frac1n$. Bu harmonik seridir, ıraksaktır.
- Kendisi yakınsak, mutlak değeri ıraksak olduğundan seri şartlı yakınsaktır.

**Örnek 6:** $\displaystyle\sum_{n=1}^\infty\frac{(-1)^n}{n^2}$ mutlak mı, şartlı mı yakınsaktır?

- Seri alternedir. $a_n=\dfrac1{n^2}$.
- $\lim a_n=0$ ve $a_{n+1}\le a_n$. Seri yakınsaktır.
- Mutlak değer: $\sum\left|\frac{(-1)^n}{n^2}\right|=\sum\frac1{n^2}$. $p=2>1$ olduğundan $p$-testinden yakınsaktır.
- Hem kendisi hem mutlak değeri yakınsak. Seri mutlak yakınsaktır.

**Örnek 7:** $\displaystyle\sum_{n=1}^\infty\frac{(-1)^{n+1}}{n}$ (alterne harmonik seri)

Hoca bu örneği nottan okudu. Mutlak değeri alınınca harmonik seri çıkar, bu ıraksaktır. Yani seri mutlak yakınsak değildir. Leibniz testinden yakınsak olduğundan şartlı yakınsaktır.

### 4.1 Sınav sorusu: $\sum\frac{n\cos(n\pi)}{2^n}$

**Örnek 8:** $\displaystyle\sum_{n=1}^\infty\frac{n\cos(n\pi)}{2^n}$ serisinin yakınsaklığını inceleyiniz.

Hoca bu soruyu "alın size sınav sorusu" diyerek verdi. Öğrencilerden kağıt kalemle yerlerinde çözmelerini istedi. Böyle bir soruyla sınavda ilk kez karşılaşan öğrencinin "bunu görmemiştik" diyebileceğini, ama çok soru çözenin bunu yapma olasılığının artacağını söyledi.

> **Hocanın vurgusu:** Zor iş, zamanında yapılmayan kolay işlerin toplamıdır. Her gün, her hafta düzenli çalışırsanız başarı kaçınılmazdır. Biriktirirseniz en sevdiğiniz iş bile içinden çıkılmaz hale gelebilir.

Çözüm:

- Önce $\cos(n\pi)$'ye bakılır.
  - $n=1$: $\cos\pi=-1$.
  - $n=2$: $\cos2\pi=1$.
  - Genel olarak $\cos(n\pi)=(-1)^n$.
- Seri $\displaystyle\sum(-1)^n\frac{n}{2^n}$ biçiminde alterne seridir.
- Mutlak değer serisi $\sum\dfrac{n}{2^n}$'dir. Paydada kuvvet olduğundan oran testi kullanılır:

$$\lim_{n\to\infty}\frac{a_{n+1}}{a_n}=\lim_{n\to\infty}\frac{(n+1)/2^{n+1}}{n/2^n}=\lim_{n\to\infty}\frac{n+1}{2n}=\frac12<1 .$$

- Mutlak değer serisi yakınsaktır. Bu yüzden seri mutlak yakınsaktır.

Hoca "tek başına soru bile gelebilir" diyerek $\sum\frac{n}{2^n}$'nin oran testiyle yakınsaklığının ayrı bir soru olarak da sorulabileceğini söyledi.

<!-- BELİRSİZ: 00:39:48'de hoca "şurada n artı 1 olacak... eksi 1 artı ... için bu şekilde olması lazım" diyor. Tahtadaki ifadede bir düzeltme yapıldığı anlaşılıyor (üs n mi n+1 mi), ama hangi terime ait olduğu altyazıdan okunmuyor. Sonuç işaret düzeninden etkilenmez. -->

Moladan sonra (yaklaşık 13 dakikalık ara) hoca bir örneği daha hatırlattı.

**Örnek 9:** $\displaystyle\sum_{n=2}^\infty\frac{(-1)^n}{\ln n}$

- Seri alternedir. $a_n=\dfrac1{\ln n}$ azalır ve $0$'a gider. Leibniz testinden yakınsaktır.
- Mutlak değer serisi $\sum\dfrac1{\ln n}$ ıraksaktır.
- Mutlak yakınsak değildir, ama kendisi yakınsaktır. Seri şartlı yakınsaktır.

Hoca $\sum\frac1{\ln n}$'nin neden ıraksak olduğunu altyazıda ayrıca açıklamadı. Kısa gerekçe (ara adım eklendi): $n\ge2$ için $\ln n<n$, yani $\dfrac1{\ln n}>\dfrac1n$. Harmonik seri ıraksak olduğundan karşılaştırma testiyle $\sum\frac1{\ln n}$ de ıraksaktır.

Hoca, çözümü anlamayan olursa tahtada tekrar çözebileceğini söyledi. Ardından terimlerin yeniden düzenlenmesi (sıralanması) konusunu "okuyup geçiyoruz" diyerek atladı.

> **Ek bilgi (derste anlatılmadı):** Terimlerin yeniden düzenlenmesi konusunun ana sonucu büyük olasılıkla şudur: Mutlak yakınsak bir serinin terimlerinin sırası değiştirilirse toplam değişmez. Şartlı yakınsak bir serinin terimleri ise uygun sırayla dizilerek istenen herhangi bir toplama (Riemann yeniden düzenleme teoremi) yakınsatılabilir.

## 5. Seri Testlerinin Özeti

Hoca bu özeti "hayat kurtaran bir simit gibi" önemli bilgiler diye tanıttı. Bir seri verildiğinde sırayla şunlara bakılır:

1. **$n$-inci terim testi:** Önce $\lim_{n\to\infty}a_n$'ye bakılır. Limit sıfırdan farklıysa seri doğrudan ıraksaktır. Bu, yapılacak ilk iştir.
   - Örnek 10: $\sum\dfrac{n}{n+1}$. $\lim\dfrac{n}{n+1}=1\ne0$, seri ıraksaktır.
2. **Geometrik seri:** $\sum ar^{n}$ için ortak çarpan $|r|<1$ ise yakınsak, $|r|\ge1$ ise ıraksaktır.
3. **$p$-serisi:** $\sum\frac1{n^p}$ için $p>1$ ise yakınsak, $p\le1$ ise ıraksaktır. Bu, integral testiyle $\int_1^\infty\frac{dx}{x^p}$'den gösterilmişti.
4. **Pozitif terimli seriler:** integral testi, oran testi, kök testi, karşılaştırma testi, limit karşılaştırma testi. Karşılaştırma ve limit karşılaştırmada karakteri bilinen geometrik seri ya da $p$-serisi seçilir.
5. **Alterne seriler:** Leibniz testi. Sonra mutlak değer serisine bakılarak mutlak ya da şartlı yakınsaklık belirlenir.

## 6. Kuvvet Serileri: Tanım, Merkez, Yarıçap ve Aralık

### 6.1 Tanım

**Kuvvet serisi (power series)**

- $\displaystyle\sum_{n=0}^\infty a_n(x-c)^n=a_0+a_1(x-c)+a_2(x-c)^2+\dots$ biçimindeki seriye $c$ merkezli kuvvet serisi denir.
- $a_n$ sabitleri serinin katsayılarıdır.

Kuvvet serisinin her terimi $x$'in fonksiyonudur. Bu yüzden seri bazı $x$ değerleri için yakınsar, bazıları için ıraksar. Amaç, serinin hangi $x$ değerleri için yakınsak, hangileri için ıraksak olduğunu bulmaktır. Hoca bunu "matematiğin güzelliği" diye anlattı: Seri $x$'e bağlı olarak bir fonksiyon tanımlar.

$x=c$ noktası **yakınsaklık merkezidir**. $x$ yerine $c$ konursa $x-c=0$ olur. $x$'li terimlerin hepsi sıfırlanır, geriye $a_0$ kalır. Yani her kuvvet serisi $x=c$'de $a_0$'a yakınsar.

### 6.2 Yakınsaklık teoremi

**Teorem:** $\sum a_n(x-c)^n$ kuvvet serisi için aşağıdakilerden biri sağlanır.

1. Seri yalnızca $x=c$ noktasında yakınsaktır.
2. Seri her $x\in\mathbb{R}$ için yakınsaktır. Yakınsaklık $x$'e bağlı değildir.
3. Bir $R>0$ sayısı vardır: $|x-c|<R$ olan her $x$ için seri yakınsak, $|x-c|>R$ olan her $x$ için ıraksaktır. $x=c-R$ ve $x=c+R$ uç noktalarında seri yakınsak da olabilir, ıraksak da.

Buradaki $R$ sayısına **yakınsaklık yarıçapı** (radius of convergence) denir. Birinci durumda $R=0$, ikinci durumda $R=\infty$ kabul edilir.

> **Hocanın vurgusu:** "Sınav sorusu bunlar." Yakınsaklık yarıçapı ve yakınsaklık aralığı sorulur.

Merkezi $c$, yarıçapı $R$ olan bir kuvvet serisinin **yakınsaklık aralığı** (interval of convergence) şu dört biçimden biridir:

- $(c-R,\;c+R)$: iki uç da hariç,
- $[c-R,\;c+R)$: sol uç dahil,
- $(c-R,\;c+R]$: sağ uç dahil,
- $[c-R,\;c+R]$: iki uç da dahil.

### 6.3 Yakınsaklık aralığını bulma yöntemi

1. Oran testi uygulanır: $\lim_{n\to\infty}\left|\dfrac{u_{n+1}}{u_n}\right|<1$ koşulundan serinin **mutlak yakınsadığı açık aralık** bulunur. Bu aralık genelde $|x-c|<R$ biçimindedir.
2. Uç noktalar $x=c-R$ ve $x=c+R$ ayrı ayrı seride yerine konur. Elde edilen sayı serilerinin karakteri bilinen testlerle incelenir. Yakınsaksa uç aralığa dahil edilir, değilse edilmez.
3. Yakınsaklık aralığının dışında kalan noktalarda seri ıraksaktır.

### 6.4 Soru-cevap: Neden "$<1$" diyoruz?

Örnek 14'ün çözümünden sonra bir öğrenci şunu sordu:

**Soru:** $\dfrac{a_{n+1}}{a_n}$ oranını kurup neden "$1$'den küçük olsun" diyoruz? Burada $R$'nin $1$ olduğunu nereden anlıyorsunuz?

**Cevap:** Hoca soruyu "çok güzel bir soru" diye karşıladı. $1$, yarıçap değildir. $1$, oran testinin kendi eşiğidir. Oran testi şunu söyler: $\lim\frac{u_{n+1}}{u_n}=L$ ise $L<1$'de seri yakınsak, $L>1$'de ıraksak, $L=1$'de test sonuç vermez. Bu, ispatlanmış bir teoremdir ve biz onu kullanırız. Kuvvet serisinde terimlerin içinde $x$ de vardır. Bu yüzden terimin tamamına $u_n$ (ya da $a_n$) deriz ve oranı hesaplarız. Oran artık $x$'e bağlı çıkar. "$<1$" koşulu, hangi $x$ değerleri için serinin yakınsak olduğunu verir. Yarıçap bu eşitsizlikten okunur.

<!-- BELİRSİZ: Hoca cevabı verirken internet bağlantısı yaklaşık 01:37-01:40 arasında kesildi. Bu sırada söylenenler kayıtta yok. -->

## 7. Kuvvet Serilerinin Yakınsaklık Aralığı Örnekleri

**Örnek 11:** $\displaystyle\sum_{n=0}^\infty\frac{x^n}{n!}$ hangi $x$ değerleri için yakınsaktır?

Hoca soruyu şıklı bir sınav sorusu olarak okudu: A şıkkı "tüm $x$ için", diğer şıklar çeşitli aralıklar.

- Kuvvet ve faktöriyel var, oran testi kullanılır. $n$ yerine $n+1$ yazılır:

$$\left|\frac{x^{n+1}/(n+1)!}{x^n/n!}\right|=\frac{|x|}{n+1}\xrightarrow[n\to\infty]{}0 .$$

- $x$ sabit bir sayıdır. Sayı bölü sonsuz sıfıra gider.
- $0<1$ olduğundan seri her $x$ için yakınsaktır. Sonuç $x$'e bağlı değil. $R=\infty$.

Hoca burada, sonuç $x$'e bağlı çıksaydı ne yapılacağını da gösterdi. Örneğin oran testi $|x-1|<2$ koşulunu verseydi:

$$-2<x-1<2\;\Longrightarrow\;-1<x<3 .$$

Seri bu açık aralıkta yakınsak olurdu. Sonra $x=-1$ ve $x=3$ ayrı ayrı seride yerine konup uçların dahil olup olmadığına bakılırdı.

**Örnek 12:** $\displaystyle\sum_{n=0}^\infty n!\,x^n$ hangi $x$ değerleri için yakınsaktır?

Hoca soruyu öğrencilere söyletti ve tahtaya yazdı. Önce bunun bir kuvvet serisi olduğunu belirtti: $x^n$ kuvvetleri ve $n!$ katsayıları var.

- Oran testi:

$$\left|\frac{(n+1)!\,x^{n+1}}{n!\,x^n}\right|=(n+1)\,|x| .$$

- $(n+1)!/n!=n+1$ kalır. $x^{n+1}/x^n=x$ kalır.
- $x\ne0$ ise $(n+1)|x|\to\infty$. Hiçbir $x\ne0$ için $1$'den küçük olmaz.
- $x=0$ konursa bütün terimler (ilki hariç) sıfırdır. Seri yalnızca merkezde, $x=0$'da yakınsaktır. $R=0$.

**Örnek 13:** $\displaystyle\sum_{n=1}^\infty\frac{x^n}{n}$ serisinin mutlak ya da şartlı yakınsak olduğu $x$ değerleri

Hoca bunu "çok güzel bir soru" diye tanıttı.

- Oran testi: $\left|\dfrac{x^{n+1}/(n+1)}{x^n/n}\right|=\dfrac{n}{n+1}|x|\to|x|$.
- $|x|<1$, yani $-1<x<1$ için seri mutlak yakınsaktır.
- $x=-1$: Seri $\sum\dfrac{(-1)^n}{n}$ olur. Bu alterne harmonik seridir. Leibniz testinden yakınsak, mutlak değeri ıraksak. Şartlı yakınsaktır.
- $x=1$: Seri $\sum\dfrac1n$ olur. Harmonik seridir, ıraksaktır.
- Yakınsaklık aralığı: $[-1,1)$. $-1$ dahil, $+1$ hariç.

Hoca şıkları tek tek değerlendirdi:

- "$(-1,1)$ aralığında seri mutlak yakınsaktır": doğru.
- "$x=-1$'de seri şartlı yakınsaktır": doğru.
- "$x=-1$'de mutlak yakınsaktır": yanlış.
- "$x=1$'de seri ıraksaktır": doğru.
- "Yakınsaklık aralığı $[-1,1)$'dir": doğru.

Sınavda soru bazen "aşağıdakilerden hangisi yanlıştır" diye kurulur. Dört doğru verilir, beşincisinde bir yanlış olur. Örneğin "$x=1$'de seri mutlak yakınsaktır" şıkkı yanlıştır.

Hoca bir de şuna dikkat çekti: Bu sorunun şıklarında $[-1,1)$ yoktu. Doğru cevap, "seri hangi $x$ değerleri için ıraksaktır" biçiminde tersten sorulmuştu. Yani cevap yakınsaklık aralığının tümleyeni olan küme, $(-\infty,-1)\cup[1,\infty)$ oluyordu.

<!-- BELİRSİZ: Şıktaki aralığın tam yazımı altyazıda yalnızca "eksi bir, artı bir ... ıraksaktır" diye geçiyor. Tümleyen küme sonuçtan kuruldu. -->

> **Hocanın vurgusu:** Şıklar tersten kurulabilir. Sorunun ne kadar olaya hakim olduğunuzu ölçtüğünü unutmayın. Balık vermiyoruz, balık tutmayı öğretiyoruz.

> **Ders sonrası not:** Hoca $x=-1$ için çıkan seriyi bir yerde "eksi bir üzeri $n$ bölü $n$ faktöriyel" diye okudu. Seri $\sum\frac{(-1)^n}{n}$'dir, faktöriyel yoktur. Ayrıca $x=1$ için şıkları okurken bir an "mutlak yakınsaktır, doğru" dedi. Doğrusu: $x=1$'de seri harmonik seridir ve ıraksaktır. Hoca kısa süre sonra bunu düzeltti ve bu şıkkın yanlış olduğunu söyledi.

**Örnek 14:** $\displaystyle\sum_{n=1}^\infty\frac{x^n}{\sqrt{n^2+3}}$ serisinin mutlak ya da şartlı yakınsak olduğu $x$ değerleri ve yakınsaklık aralığı

- Oran testi:

$$\left|\frac{x^{n+1}/\sqrt{(n+1)^2+3}}{x^n/\sqrt{n^2+3}}\right|=|x|\sqrt{\frac{n^2+3}{(n+1)^2+3}}\to|x| .$$

- Hocanın ifadesiyle "$n^2$'ler gidiyor, $1$ kalıyor, geriye $x$ kalıyor". $|x|<1$ için mutlak yakınsak.
- $x=1$: Seri $\sum\dfrac{1}{\sqrt{n^2+3}}$ olur.
  - Kökün içinden $n^2$ dışarı çıkarılınca terim $\frac1n$ gibi davranır.
  - Limit karşılaştırma: $\lim\dfrac{1/\sqrt{n^2+3}}{1/n}=\lim\dfrac{n}{\sqrt{n^2+3}}=1$. $L$ sıfırdan ve sonsuzdan farklı.
  - $\sum\frac1n$ ıraksak olduğundan bu seri de ıraksaktır.
- $x=-1$: Seri $\sum\dfrac{(-1)^n}{\sqrt{n^2+3}}$ olur.
  - Alterne seridir. Terimler monoton azalır ve $0$'a gider. Leibniz testinden yakınsaktır.
  - Mutlak değeri $x=1$'deki seridir, ıraksaktır. Şartlı yakınsaktır.
- Yakınsaklık aralığı: $[-1,1)$.

> **Ders sonrası not:** Hoca $x=-1$ uç noktasındaki seriyi okurken paydayı "$n^2+1$" dedi. Serinin terimi $\frac{(-1)^n}{\sqrt{n^2+3}}$'tür. Sonuç (yakınsak, şartlı) değişmez.

**Örnek 15 (çıkmış sınav sorusu):** $\displaystyle\sum_{n=1}^\infty\frac{(2x+5)^n}{(n^2+1)\,3^n}$ serisinin merkezini, mutlak yakınsaklık yarıçapını ve yakınsaklık aralığını bulunuz. Seri hangi $x$ değerleri için mutlak yakınsak, hangileri için şartlı yakınsaktır?

Hoca öğrencilere iki dakika süre verdi. Sonra soruyu öğrencilere söyletip tahtada çözdü. Bu sırada ses ve ekran paylaşımı birkaç kez kesildi.

- Oran testi:

$$\left|\frac{u_{n+1}}{u_n}\right|=\frac{|2x+5|^{n+1}}{\big((n+1)^2+1\big)3^{n+1}}\cdot\frac{(n^2+1)\,3^n}{|2x+5|^n}=\frac{|2x+5|}{3}\cdot\frac{n^2+1}{(n+1)^2+1}\xrightarrow[n\to\infty]{}\frac{|2x+5|}{3} .$$

- Koşul: $\dfrac{|2x+5|}{3}<1$, yani $|2x+5|<3$.
  - $-3<2x+5<3$
  - $-8<2x<-2$
  - $-4<x<-1$.
- Bu, mutlak yakınsaklığın açık aralığıdır.
- Merkez ve yarıçap (ara adım eklendi): $|2x+5|<3\iff\left|x+\tfrac52\right|<\tfrac32$. Merkez $c=-\tfrac52$, yarıçap $R=\tfrac32$.
- Uç nokta $x=-1$: $2(-1)+5=3$. Seri $\displaystyle\sum\frac{3^n}{(n^2+1)3^n}=\sum\frac1{n^2+1}$ olur. Limit karşılaştırmasıyla $\frac1{n^2}$ ile aynı karakterdedir, yakınsaktır. $-1$ dahil.
- Uç nokta $x=-4$: $2(-4)+5=-3$. Seri $\displaystyle\sum\frac{(-3)^n}{(n^2+1)3^n}=\sum\frac{(-1)^n}{n^2+1}$ olur. Mutlak değeri $\sum\frac1{n^2+1}$, yakınsaktır. Seri mutlak yakınsaktır. $-4$ dahil.
- Yakınsaklık aralığı: $[-4,-1]$. Seri bu aralığın her noktasında mutlak yakınsaktır. Şartlı yakınsak olduğu nokta yoktur.

Hoca bu sorunun geçmiş yıllarda da sınavda çıktığını söyledi.

## 8. Kuvvet Serileriyle İşlemler

İkinci moladan sonra hoca kuvvet serileriyle işlemlere geçti.

**Kuvvet serileriyle işlemler**

- İki kuvvet serisi, yakınsaklık aralıklarının kesişiminde, sabit terimli seriler gibi terim terim toplanıp çıkarılabilir:

$$\sum a_nx^n\pm\sum b_nx^n=\sum(a_n\pm b_n)x^n .$$

- **Çarpım teoremi:** $\sum a_nx^n$ ve $\sum b_nx^n$ aynı aralıkta (örneğin $|x|<R$) yakınsak ise çarpımları da orada yakınsaktır:

$$\left(\sum_{n=0}^\infty a_nx^n\right)\left(\sum_{n=0}^\infty b_nx^n\right)=\sum_{n=0}^\infty c_nx^n,\qquad c_n=a_0b_n+a_1b_{n-1}+\dots+a_nb_0=\sum_{k=0}^n a_kb_{n-k} .$$

- $c_n$'nin genel ifadesini bulmak çoğu zaman zordur. Genelde ilk birkaç terim hesaplanır.
- **Sabitle çarpma:** $\sum a_n(x-c)^n$ serisi $|x-c|<R$'de yakınsaksa, her terimi bir $\alpha$ sabitiyle çarpılarak elde edilen seri de aynı aralıkta yakınsaktır. Aralık katsayıdan bağımsızdır.

> **Ek bilgi (derste anlatılmadı):** $c_n=\sum_{k=0}^n a_kb_{n-k}$ formülüne büyük olasılıkla iki serinin **Cauchy çarpımı** adı verilir. Polinom çarpımındaki "aynı dereceli terimleri topla" kuralının sonsuz terimli halidir.

**Örnek 16:** $\sum x^n$ serisinin başka bir kuvvet serisiyle çarpımı

Hoca $\sum x^n$'i açık yazdı: $n=0$ için $1$, $n=1$ için $x$, $n=2$ için $x^2$, yani $1+x+x^2+\dots$. İkinci seriyi de açtı. Sonra terim terim çarptı: birinci ile birinci, birinci ile ikinci, ikinci ile birinci gibi. Bütün terimleri çarpmanın çok uzun olduğunu, ama ilk üç-dört terimi bu şekilde bulabildiğimizi gösterdi.

<!-- BELİRSİZ: İkinci serinin ifadesi ve çarpımın ilk terimleri altyazıdan okunmuyor. Hoca "1 koyduk, bir eksi bir artı koyduk... n yerine 0 koyarsanız x çıktı" diyor; ikinci seri büyük olasılıkla x ile başlayan, işaretleri değişen bir seri. -->

Hoca burada bir kuvvet serisinin yakınsadığı aralıkta bir $f(x)$ fonksiyonu tanımladığını söyledi. Bunun önemli bir sonucu var: İntegrali bilinen yollarla alınamayan fonksiyonlar, seriler yardımıyla işlenebilir.

## 9. Temel Açılım: $\frac{1}{1-x}$ ve Türetilen Seriler

> **Hocanın vurgusu:** Notta bu açılımın yanına dört yıldız konmuş. En çok kullandığımız açılımlardan biri budur. Sınavda gelebilir. Bunu çok iyi bilmemiz lazım.

$$\frac{1}{1-x}=\sum_{n=0}^\infty x^n=1+x+x^2+x^3+\dots,\qquad |x|<1 .$$

Hoca bunun nereden geldiğini sordu. Cevap: $\sum x^n$ bir geometrik seridir. İlk terimi $1$, ortak çarpanı $x$'tir. Geometrik serinin toplamı $\frac{\text{ilk terim}}{1-\text{ortak çarpan}}$ olduğundan, $|x|<1$ için toplam $\frac{1}{1-x}$'tir. Bu seri hem geometrik seri hem kuvvet serisidir.

### 9.1 $\frac{1}{1+x}$

Hoca sordu: Buna bakarak $\frac{1}{1+x}$'in açılımı nedir? Bir öğrenci "$x$ yerine $-x$" diye cevap verdi.

$$\frac{1}{1+x}=\frac{1}{1-(-x)}=\sum_{n=0}^\infty(-x)^n=\sum_{n=0}^\infty(-1)^nx^n,\qquad |x|<1 .$$

### 9.2 $\frac{1}{1+x^2}$

Hoca yeşil kalemle ekledi: Paydada $x$ yerine $x^2$ olsaydı, üste $2$ gelirdi. $x$ yerine $-x^2$ yazılır:

$$\frac{1}{1+x^2}=\sum_{n=0}^\infty(-x^2)^n=\sum_{n=0}^\infty(-1)^nx^{2n},\qquad |x|<1 .$$

### 9.3 Toplam fonksiyonunu bulmak

**Örnek 17:** $\displaystyle\sum_{n=0}^\infty 4^nx^{2n}$ serisinin yakınsaklık aralığını ve bu aralıkta yakınsadığı fonksiyonu bulunuz.

<!-- BELİRSİZ: Altyazıda seri "4 üzeri n, 2 üzeri 2 n" diye geçiyor; çözümün devamı (4x^2) seriyi 4^n x^{2n} olarak doğruluyor. -->

- Temel açılım biliniyor: $\sum x^n=\frac1{1-x}$, $|x|<1$. Bu seriyi ona benzetmeye çalışırız.
- $4^nx^{2n}=(4x^2)^n$. Yani $x$ yerine $4x^2$ gelmiş.
- Hoca öğrencilere "$x$ yerine $4x$ desek olur mu?" diye sordu. Olmaz, çünkü $x$ karedir. Doğrusu $4x^2$'dir.
- Toplam fonksiyonu:

$$f(x)=\frac{1}{1-4x^2} .$$

- Aralık: $x$ yerine gelen ifade için $|4x^2|<1$ olmalı.
  - $4x^2<1$
  - $x^2<\frac14$
  - $-\frac12<x<\frac12$.
- Sonuç: Seri $\left(-\frac12,\frac12\right)$ aralığında $\dfrac{1}{1-4x^2}$ fonksiyonuna yakınsar.

> **Ders sonrası not:** Hoca sonucu söylerken "bu ıraksak olan serimiz bu fonksiyona bu aralıkta yakınsıyor" dedi. Seri $\left(-\frac12,\frac12\right)$ aralığında yakınsaktır, ıraksak değildir. Bu aralığın dışında ise ıraksaktır.

## 10. Terim Terim Türev ve İntegral

### 10.1 Kurallar

$f(x)=\displaystyle\sum_{n=0}^\infty a_n(x-c)^n$ serisi $|x-c|<R$'de yakınsak olsun.

**Terim terim türev ve integral**

- Türev, serinin terim terim türevidir. $a_n$ sabit kalır, $n$ başa geçer:

$$f'(x)=\sum_{n=1}^\infty n\,a_n(x-c)^{n-1},\qquad f''(x)=\sum_{n=2}^\infty n(n-1)\,a_n(x-c)^{n-2} .$$

- İntegral de terim terim alınır ($x$'e göre):

$$\int f(x)\,dx=\sum_{n=0}^\infty a_n\frac{(x-c)^{n+1}}{n+1}+C .$$

- Elde edilen seriler $c-R<x<c+R$ aralığında yakınsar.

Hoca bunun uygulamada çok işe yaradığını söyledi. "Aralık değişmiyor" diye de ekledi.

> **Ders sonrası not:** Terim terim türev ve integralde **yarıçap** değişmez, ama **uç noktalardaki** davranış değişebilir. Bu dersteki serilerden: $\sum\frac{x^n}{n}$'nin aralığı $[-1,1)$'dir (Örnek 13). Terim terim türevi $\sum x^{n-1}$'in aralığı ise $(-1,1)$'dir; $x=-1$ ucu kaybolur. Bu yüzden türev ya da integralden sonra uçlar yeniden kontrol edilmelidir.

### 10.2 Örnekler

**Örnek 18:** $\dfrac{1}{(1-x)^2}$ fonksiyonunun kuvvet serisi temsili ve geçerli olduğu aralık

Hoca bu soruyu şıklı bir soru olarak okudu: "Aşağıdaki fonksiyonların kuvvet serisi temsillerini ve geçerli olduğu aralıkları bulunuz."

- $\frac{1}{(1-x)^2}$ için hazır bir açılım bilmiyoruz. Bildiğimiz yönteme dönüştürmeye çalışırız.
- Bildiğimiz: $\dfrac1{1-x}=\sum_{n=0}^\infty x^n$.
- Paydada kare çıkması için iki tarafın türevi alınır:

$$\frac{d}{dx}\left(\frac1{1-x}\right)=\frac{1}{(1-x)^2},\qquad \frac{d}{dx}\sum_{n=0}^\infty x^n=\sum_{n=1}^\infty nx^{n-1} .$$

- Toplam $n=0$'dan değil $n=1$'den başlar, çünkü $n=0$ terimi ($1$) sabittir ve türevi sıfırdır.
- Sonuç:

$$\frac{1}{(1-x)^2}=\sum_{n=1}^\infty nx^{n-1}=1+2x+3x^2+\dots,\qquad |x|<1 .$$

**Örnek 19:** $\dfrac{1}{(1-x)^3}$

- Paydada küp var. Örnek 18'deki eşitliğin bir kez daha türevi alınır:

$$\frac{2}{(1-x)^3}=\sum_{n=2}^\infty n(n-1)x^{n-2} .$$

- Sol tarafta $1$ olması için iki taraf $2$'ye bölünür:

$$\frac{1}{(1-x)^3}=\sum_{n=2}^\infty\frac{n(n-1)}{2}x^{n-2}=1+3x+6x^2+10x^3+\dots,\qquad |x|<1 .$$

**Örnek 20:** $\ln(1+x)$

- Bilinen: $\dfrac1{1+x}=\sum_{n=0}^\infty(-1)^nx^n$, $-1<x<1$.
- $\ln(1+x)$'i bulmak için iki tarafın $x$'e göre integrali alınır:

$$\ln(1+x)=\int_0^x\frac{dt}{1+t}=\sum_{n=0}^\infty(-1)^n\frac{x^{n+1}}{n+1}=x-\frac{x^2}{2}+\frac{x^3}{3}-\dots,\qquad |x|<1 .$$

<!-- BELİRSİZ: 02:27:58'de "ln(1+x)" ifadesi altyazıda maskelenmiş görünüyor ("[öğrenci] 1 artı x"); bağlamdan ln(1+x) olduğu anlaşılıyor. İntegral sabitinin nasıl belirlendiği altyazıda geçmiyor; x=0'da iki taraf da 0 olduğundan C=0'dır (ara adım eklendi). -->

**Örnek 21:** $\arctan x$

- Bilinen: $\dfrac1{1+x^2}=\sum_{n=0}^\infty(-1)^nx^{2n}$, $|x|<1$.
- İki tarafın integrali alınır:

$$\arctan x=\sum_{n=0}^\infty(-1)^n\frac{x^{2n+1}}{2n+1}=x-\frac{x^3}{3}+\frac{x^5}{5}-\dots,\qquad |x|<1 .$$

- Hoca kontrolü türevle yaptı: Serinin terim terim türevi alınır.
  - $x$'in türevi $1$'dir.
  - $\frac{x^3}{3}$'te $3$ başa geçer, sadeleşir: $x^2$.
  - $\frac{x^5}{5}$'te $5$ başa geçer, sadeleşir: $x^4$.
  - Sonuç $1-x^2+x^4-\dots=\dfrac1{1+x^2}$ olur. Bu da $\arctan x$'in türevidir.

Hoca ardından benzer, daha önce sınavda sorulmuş "orijinal" soruların ve çözümlerinin notta bulunduğunu söyledi. Öğrencilerden çözümlere bakmadan önce kendileri uğraşmalarını istedi. Son olarak bir alıştırma verdi (bkz. Örnek Sorular, Soru 14) ve kuvvet serileriyle ilgili soruların bir sonraki derste çözüleceğini söyledi.

### 10.3 Kaynak sorusu

**Soru:** Derse yardımcı olacak, fazladan örnek soru içeren bir kaynak kitap önerebilir misiniz?

**Cevap:** Kalkülüs kitaplarının hepsi faydalıdır. Konu anlatımlarında ve çözümlü örneklerinde onlarca, yüzlerce soru vardır. Tek bir kitapla sınırlanmamalı, en yakın kütüphaneden temin edilebilir. İnternette PDF'ler de bulunabilir, ama bir kitap edinmek anlamak açısından daha iyidir. Dersin kendi kitabı var, ama onda soru az. Kitaba yalnızca konu için bakılabilir. Konuyu kavramak ve kısa zamanda doğruya gitmek için bol bol soru çözmek gerekir. Hoca ilerleyen derslerde not paylaşacağını da söyledi.

## 11. Örnek Sorular

Bu derste video karesi yoktur. Aşağıdaki sorular, derste hocanın sözlü sorduğu ya da tahtada çözdüğü sorulardır.

**Soru 1** (derste sözlü, 00:06:06): $y=\frac1x$ eğrisi altında $x\ge1$ için kalan bölgenin alanı var mıdır? Bu bölge $x$ ekseni etrafında döndürülürse oluşan cismin hacmi var mıdır?

> **Çözüm:** Alan $\int_1^\infty\frac{dx}{x}=\infty$, sonlu değil. Hacim $\pi\int_1^\infty\frac{dx}{x^2}=\pi$ birim küp (bkz. Bölüm 2).

**Soru 2** (derste sözlü, 00:11:26): $\sum\frac{1}{n^2+1}$ serisi yakınsak mıdır? Hangi seriyle karşılaştırılır?

> **Çözüm:** $\sum\frac1{n^2}$ ile. $\frac1{n^2+1}\le\frac1{n^2}$ ve limit oranı $1$. Seri yakınsaktır (bkz. Bölüm 1.2-1.3).

**Soru 3** (derste sözlü, 00:22:49): $\sum\frac{(-1)^{n-1}}{n^2}$ serisi yakınsak mıdır? <!-- BELİRSİZ: payda tahtada; n^2 olarak alındı. -->

> **Çözüm:** Leibniz testinin üç koşulu sağlanır. Seri yakınsaktır (Örnek 2).

**Soru 4** (derste sözlü, 00:25:32 ve 00:27:16): $\sum\frac1n$ yakınsak mıdır? $\sum\frac{(-1)^n}{n}$ yakınsak mıdır?

> **Çözüm:** $\sum\frac1n$ harmonik seri, ıraksak. $\sum\frac{(-1)^n}{n}$ Leibniz testinden yakınsak (Örnek 3-4).

**Soru 5** (derste sözlü, 00:32:27): Şartlı yakınsak bir seriye örnek veriniz.

> **Çözüm:** $\sum\frac{(-1)^n}{n}$. Kendisi yakınsak, mutlak değeri $\sum\frac1n$ ıraksak (Örnek 5).

**Soru 6** (derste sözlü, 00:34:49): $\sum\frac{(-1)^n}{n^2}$ mutlak mı, şartlı mı yakınsaktır?

> **Çözüm:** Mutlak yakınsaktır; $\sum\frac1{n^2}$ yakınsak ($p=2$) (Örnek 6).

**Soru 7** (derste sözlü, sınav sorusu, 00:38:30): $\sum\frac{n\cos(n\pi)}{2^n}$ serisinin yakınsaklığını inceleyiniz.

> **Çözüm:** $\cos(n\pi)=(-1)^n$. Mutlak değer serisi $\sum\frac{n}{2^n}$, oran testiyle $L=\frac12<1$. Seri mutlak yakınsaktır (Örnek 8).

**Soru 8** (derste sözlü, şıklı soru, 01:07:35): $\sum\frac{x^n}{n!}$ hangi $x$ değerleri için yakınsaktır?

> **Çözüm:** Oran $\frac{|x|}{n+1}\to0$. Her $x$ için yakınsak, $R=\infty$ (Örnek 11).

**Soru 9** (derste sözlü, 01:10:27): $\sum n!\,x^n$ hangi $x$ değerleri için yakınsaktır?

> **Çözüm:** Oran $(n+1)|x|\to\infty$ ($x\ne0$). Yalnızca $x=0$'da yakınsak, $R=0$ (Örnek 12).

**Soru 10** (derste sözlü, şıklı soru, 01:14:20): $\sum\frac{x^n}{n}$ serisinin mutlak ya da şartlı yakınsak olduğu $x$ değerleri hangileridir?

> **Çözüm:** $(-1,1)$'de mutlak yakınsak, $x=-1$'de şartlı yakınsak, $x=1$'de ıraksak. Aralık $[-1,1)$. Iraksak olduğu küme $(-\infty,-1)\cup[1,\infty)$ (Örnek 13).

**Soru 11** (derste sözlü, 01:18:30): $\sum\frac{x^n}{\sqrt{n^2+3}}$ serisinin mutlak, şartlı yakınsak olduğu $x$ değerleri ve yakınsaklık aralığı nedir?

> **Çözüm:** $(-1,1)$'de mutlak, $x=-1$'de şartlı yakınsak, $x=1$'de ıraksak. Aralık $[-1,1)$ (Örnek 14).

**Soru 12** (derste sözlü, çıkmış sınav sorusu, 01:22:03): $\sum_{n=1}^\infty\frac{(2x+5)^n}{(n^2+1)3^n}$ serisinin merkezi, yarıçapı ve yakınsaklık aralığı nedir?

> **Çözüm:** Merkez $-\frac52$, yarıçap $\frac32$, aralık $[-4,-1]$; her noktada mutlak yakınsak (Örnek 15).

**Soru 13** (derste sözlü, 02:13:55 ve 02:15:33): $\frac{1}{1+x}$'in açılımı nedir? $\sum 4^nx^{2n}$ serisinin yakınsaklık aralığı ve toplam fonksiyonu nedir?

> **Çözüm:** $\frac1{1+x}=\sum(-1)^nx^n$, $|x|<1$. $\sum4^nx^{2n}=\frac{1}{1-4x^2}$, $-\frac12<x<\frac12$ (Bölüm 9, Örnek 17).

**Soru 14** (derste sözlü, alıştırma, 02:30:37): $f(x)=\dfrac{1}{2+x}$ fonksiyonunu $(x-1)$'in kuvvetlerine göre yazınız.

> **Çözüm (derste verilmedi):**
>
> - Paydayı $(x-1)$ cinsinden yazalım: $2+x=3+(x-1)$.
> - $\dfrac{1}{2+x}=\dfrac{1}{3+(x-1)}=\dfrac13\cdot\dfrac{1}{1+\frac{x-1}{3}}$.
> - $\dfrac1{1+u}=\sum(-1)^nu^n$ ($|u|<1$) açılımında $u=\dfrac{x-1}{3}$ yazılır:
>
> $$\frac{1}{2+x}=\sum_{n=0}^\infty\frac{(-1)^n(x-1)^n}{3^{n+1}}=\frac13-\frac{x-1}{9}+\frac{(x-1)^2}{27}-\dots$$
>
> - Koşul: $\left|\dfrac{x-1}{3}\right|<1$, yani $|x-1|<3$, yani $-2<x<4$. Merkez $1$, yarıçap $3$.
> - Uçlar: $x=-2$'de terimler $\frac13$, $x=4$'te $\pm\frac13$ olur; genel terim sıfıra gitmez, iki uç da ıraksaktır. Aralık $(-2,4)$.

## Dersin Toparlaması

Ders, geçen haftanın pozitif terimli seri testlerinin (integral, karşılaştırma, limit karşılaştırma, oran ve kök) kısa bir tekrarıyla başladı. Arada Gabriel borusu paradoksu hatırlatıldı: $\frac1x$ altındaki sonsuz alanlı bölge döndürülünce hacmi $\pi$ olan bir cisim verir. Ardından işaretleri değişen serilere geçildi. Leibniz testinin üç koşulu (pozitif, monoton azalan, limiti sıfır) ile alterne serilerin yakınsaklığı incelendi. Mutlak ve şartlı yakınsaklık, $\sum\frac{(-1)^n}{n}$ (şartlı) ve $\sum\frac{(-1)^n}{n^2}$ (mutlak) karşıtlığıyla anlatıldı. Bütün testler beş adımlık bir özetle bağlandı: önce $n$-inci terim testi, sonra geometrik ve $p$-serileri, pozitif terimli testler ve alterne seriler.

Dersin ikinci yarısı kuvvet serilerine ayrıldı. Bir kuvvet serisinin yalnız merkezde, her yerde ya da $|x-c|<R$ aralığında yakınsadığı görüldü. Aralık oran testiyle bulunur, uç noktalar ayrıca denenir. Sınav sorularında şıkların tersten (ıraksak olduğu küme, yanlış olan şık) kurulabileceği vurgulandı. Son olarak kuvvet serileriyle toplama, çarpma ve sabitle çarpma; dört yıldızlı $\frac1{1-x}=\sum x^n$ açılımı ve ondan yerine koyma, terim terim türev ve integral ile türetilen $\frac1{1+x}$, $\frac1{1+x^2}$, $\frac1{(1-x)^2}$, $\frac1{(1-x)^3}$, $\ln(1+x)$ ve $\arctan x$ serileri işlendi. Hoca bir sonraki derste kuvvet serileriyle ilgili soru çözüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
