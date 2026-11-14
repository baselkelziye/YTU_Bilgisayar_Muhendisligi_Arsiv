# Ders 4 Genişletilmiş Notu: Kuvvet Serileri: Yakınsaklık Aralığı, Mutlak ve Şartlı Yakınsaklık Uygulamaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Kuvvet Serisi Tekrarı
- 3. Mutlak ve Şartlı Yakınsaklık
- 4. Geometrik Seriden Yeni Açılımlar
- 5. Terim Terim Türev ve İntegral
- 6. Bir Fonksiyonu $x-c$'nin Kuvvetlerine Göre Açmak
- 7. Uygulamalar: Sayı Serilerinin Karakteri
- 8. Uygulamalar: Kuvvet Serilerinin Yakınsaklık Aralığı
- 9. Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Planı

Hoca derse, seriler konusuna devam edileceğini söyleyerek başladı. Bu derste yeni bir konuya geçilmedi. Önceki derste anlatılan kuvvet serileri (power series) kısaca tekrar edildi, ardından konuyu pekiştiren ve geçmiş sınavlarda çıkmış sorular çözüldü.

> **Hocanın vurgusu:** Sınavda çıkacak soruların önemli bir kısmı seriler konusundan geliyor.

Ders iki bölümden oluştu. İlk bölümde tekrar ve geometrik seriden açılım örnekleri yapıldı. Moladan sonraki ikinci bölüm "uygulamalar" başlığı altında, ekrandan gösterilen hazır sorular üzerinden ilerledi. Hoca bu bölümde soruları tek tek tahtada yazmadı; çözümü hazır olan soruları ekranda gösterip sözlü olarak üzerinden geçti. Bu yüzden bazı soruların tam ifadesi altyazıdan okunamıyor. Bu yerler aşağıda ayrıca işaretlendi.

## 2. Kuvvet Serisi Tekrarı

### 2.1 Tanım

**Tanım (kuvvet serisi)**

- $a_n$ katsayılar olmak üzere
$$\sum_{n=0}^{\infty} a_n (x-c)^n = a_0 + a_1(x-c) + a_2(x-c)^2 + \cdots$$
serisine $x=c$ noktasında (ya da $x=c$ civarında) kuvvet serisi denir.
- $n=0$ konunca ilk terim $a_0$, $n=1$ konunca $a_1(x-c)$, $n=2$ konunca $a_2(x-c)^2$ elde edilir ve böyle devam eder.

Serinin terimleri $x$'in fonksiyonu olduğu için serinin kendisi de $x$'e bağlı bir fonksiyon tanımlar. Hoca önce en basit noktaya baktı: $x=c$ konunca $(x-c)$ içeren bütün terimler sıfır olur ve geriye yalnız $a_0$ kalır. Yani seri merkezde her zaman $a_0$'a yakınsar. Yakınsaklık bölgesi de $c$ merkezli, $c-R$ ile $c+R$ arasında bir aralık olarak ortaya çıkar.

### 2.2 Yakınsaklık İçin Üç Durum

**Teorem (kuvvet serisinin yakınsaklığı)**

Bir kuvvet serisi için aşağıdakilerden biri ve yalnız biri sağlanır:

- Seri yalnız $x=c$'de yakınsaktır.
- Seri her $x\in\mathbb{R}$ için yakınsaktır. Yani yakınsaklık $x$'ten bağımsızdır.
- Öyle bir $R>0$ vardır ki seri $|x-c|<R$ sağlayan her $x$ için yakınsak, $|x-c|>R$ için ıraksaktır.

Üçüncü durumda $R$'ye yakınsaklık yarıçapı (radius of convergence) denir. Hoca bunu "$c$ merkezli, $R$ yarıçaplı yuvar içinde yakınsak, dışında ıraksak" diye ifade etti.

### 2.3 Yakınsaklık Aralığı Nasıl Bulunur?

> **Hocanın vurgusu:** Yakınsaklık aralığı (interval of convergence) önemlidir. Sorularda sık sık "bu serinin yakınsaklık aralığını bulunuz" diye gelir.

Yöntem önceki dersteki gibidir:

1. Serinin genel terimine $u_n$ denir (hoca bazen $a_n$ diyor).
2. Oran testi (ratio test) uygulanır: $L=\lim_{n\to\infty}\left|\dfrac{u_{n+1}}{u_n}\right|$.
3. $L<1$ koşulu çözülür. Bu, serinin mutlak yakınsak olduğu açık aralığı verir.
4. Aralığın uç noktaları ayrı ayrı seriye konur. Çıkan sayı serisi bilinen testlerle incelenir ve uç noktanın aralığa dahil olup olmadığına karar verilir.

Oran testinde $L<1$ ise seri yakınsak, $L>1$ ise ıraksaktır. $L=1$ ise test sonuç vermez ve başka bir teste geçilir.

### 2.4 Önceki Dersten İki Örnek

**Örnek 1.** $\displaystyle\sum_{n=0}^{\infty}\frac{x^n}{n!}$ serisi hangi $x$'ler için yakınsaktır?

- Oran: $\left|\dfrac{u_{n+1}}{u_n}\right|=\dfrac{|x|}{n+1}$.
- $n\to\infty$ iken payda sonsuza gider. $x$ yerine $1$, $5$, $10$ ya da $50$ konsa da limit $0$ olur.
- $0<1$ olduğundan seri her $x\in\mathbb{R}$ için mutlak yakınsaktır.

**Örnek 2.** $\displaystyle\sum_{n=0}^{\infty} n!\,x^n$ serisi hangi $x$'ler için yakınsaktır?

- Oran: $\left|\dfrac{u_{n+1}}{u_n}\right|=(n+1)|x|$. $x\neq 0$ ise bu oran sonsuza gider.
- Seri yalnız merkezde, yani $x=0$'da yakınsaktır.

Hoca burada bir soru sordu: Seri $\sum n!\,(x-1)^n$ olsaydı ne değişirdi? Cevap: aynı hesap yapılır, ama bu kez merkez $x=1$'dir. Seri yalnız $x=1$'de yakınsak, onun dışında ıraksak olur.

## 3. Mutlak ve Şartlı Yakınsaklık

Hoca önceki derste verilen tanımları hatırlattı.

**Tanım (mutlak ve şartlı yakınsaklık)**

- $\sum a_n$ yakınsak ve $\sum |a_n|$ de yakınsak ise seriye **mutlak yakınsak** (absolutely convergent) denir.
- $\sum a_n$ yakınsak ama $\sum |a_n|$ ıraksak ise seriye **şartlı yakınsak** (conditionally convergent) denir.

**Örnek 3.** $\displaystyle\sum_{n=1}^{\infty}\frac{x^n}{\sqrt{n^2+3}}$ serisinin mutlak ve şartlı yakınsak olduğu $x$ değerlerini bulunuz.

*Açık aralık.* Genel terim $u_n=\dfrac{x^n}{\sqrt{n^2+3}}$ alınır.
$$\left|\frac{u_{n+1}}{u_n}\right|=|x|\,\frac{\sqrt{n^2+3}}{\sqrt{(n+1)^2+3}}\ \xrightarrow{\,n\to\infty\,}\ |x|.$$
Kök içindeki ifadelerin oranının limiti $1$'dir, geriye $|x|$ kalır. $|x|<1$ koşulundan seri $-1<x<1$ aralığında mutlak yakınsaktır.

*Uç nokta $x=1$.* Seri $\displaystyle\sum\frac{1}{\sqrt{n^2+3}}$ olur. Kök dışına $n$ olarak çıkar, yani terim $\dfrac1n$ gibi davranır. Limit testi (limit comparison test) uygulanır:
$$\lim_{n\to\infty}\frac{1/\sqrt{n^2+3}}{1/n}=1.$$
Limit $0$ ve $\infty$'dan farklı olduğundan iki serinin karakteri aynıdır. $\sum\dfrac1n$ harmonik seri ıraksak olduğu için bu seri de ıraksaktır. $x=1$ aralığa dahil değildir.

*Uç nokta $x=-1$.* Seri $\displaystyle\sum\frac{(-1)^n}{\sqrt{n^2+3}}$ olur. Bu bir alterne seridir (alternating series). Leibniz testi uygulanır: $b_n=\dfrac{1}{\sqrt{n^2+3}}$ monoton azalandır ve limiti sıfırdır. O halde seri yakınsaktır. Mutlak değeri alındığında yine $\sum\dfrac{1}{\sqrt{n^2+3}}$ çıkar ve bu ıraksaktır. Yani $x=-1$'de seri şartlı yakınsaktır.

*Sonuç.* Seri $(-1,1)$ aralığında mutlak yakınsak, $x=-1$'de şartlı yakınsak, $x=1$'de ıraksaktır. Yakınsaklık aralığı $[-1,1)$'dir.

> **Ders sonrası not:** Hoca $x=-1$'de çıkan seriye önce "harmonik seri" dedi, hemen ardından "alterne seri" diye düzeltti. Doğrusu alterne seridir.

Hoca aynı yöntemle çözülmüş bir benzer soruyu da ekranda kısaca gösterdi (00:15:53). Bu sorunun ifadesi altyazıda geçmiyor.

<!-- BELİRSİZ: 00:15:53'te gösterilen ikinci mutlak/şartlı yakınsaklık sorusunun serisi altyazıda okunmuyor. -->

Hoca ayrıca serilerde işlemlere, özellikle iki serinin çarpımına değindi. Önceki derste iki seri açılarak çarpılmıştı. Bu konudan da soru geldiğini söyledi, ama bu derste yeni örnek çözmedi.

## 4. Geometrik Seriden Yeni Açılımlar

### 4.1 Temel Açılım

**Teorem (geometrik seri açılımı)**

- $|x|<1$ için
$$\frac{1}{1-x}=\sum_{n=0}^{\infty}x^n=1+x+x^2+\cdots$$
- Ortak çarpan $x$, ilk terim $1$ olan bir geometrik seridir.

Hoca bu eşitliğin nereden geldiğini kısmi toplamlarla hatırlattı. $n$'inci kısmi toplam
$$S_n=1+x+\cdots+x^n=\frac{1-x^{n+1}}{1-x}$$
olur. $n\to\infty$ iken limit alınır. Sorunlu kısım $x^{n+1}$'dir. $|x|<1$ ise $x^{n+1}\to0$ olur ve
$$\lim_{n\to\infty}S_n=\frac{1}{1-x}$$
bulunur. Yani bu serinin fonksiyonu $\dfrac{1}{1-x}$'tir, ama yalnız $|x|<1$ için.

> **Hocanın vurgusu:** Bu açılım çok önemlidir. Birçok soru bunu kullanarak çözülür. Bir serinin fonksiyonu, ya da bir fonksiyonun serisi, yakınsaklık aralığı bulunarak yazılır.

**Soru:** Toplam neden $n=0$'dan başlıyor, $n=1$'den başlaması gerekmiyor mu? **Cevap:** $n=0$ konunca $x^0=1$ olur. Serinin ilk terimi $1$ olduğu için toplam $0$'dan başlar. $n=0$ için $1$, $n=1$ için $x$, $n=2$ için $x^2$ gelir. Hoca soruyu güzel bulduğunu söyleyip öğrenciyi tebrik etti.

### 4.2 $x$ Yerine Başka İfade Yazmak

Temel açılımda $x$ yerine başka bir ifade yazılarak yeni açılımlar elde edilir. Yakınsaklık koşulu da aynı değişiklikle bulunur: $|x|<1$ yerine "yeni ifadenin mutlak değeri $1$'den küçük" yazılır.

**Örnek 4.** $\dfrac{1}{1+x}$'in seri açılımı.

- $\dfrac{1}{1+x}=\dfrac{1}{1-(-x)}$ yazılır. $x$ yerine $-x$ gelmiştir.
- $$\frac{1}{1+x}=\sum_{n=0}^{\infty}(-x)^n=\sum_{n=0}^{\infty}(-1)^n x^n.$$
- Koşul $|-x|<1$, yani yine $|x|<1$. Aralık aynıdır.

**Örnek 5.** $\dfrac{1}{1+3x}$'in seri açılımı ve yakınsaklık aralığı.

- $x$ yerine $-3x$ gelmiştir:
$$\frac{1}{1+3x}=\sum_{n=0}^{\infty}(-3x)^n=\sum_{n=0}^{\infty}(-1)^n 3^n x^n.$$
- Koşul $|3x|<1$. Düzenlenirse $-\dfrac13<x<\dfrac13$ bulunur.

**Örnek 6.** $\displaystyle\sum_{n=0}^{\infty}4^n x^{2n}$ serisinin yakınsaklık aralığını ve bu aralıktaki toplam fonksiyonunu bulunuz.

- Seri $\sum (4x^2)^n$ biçiminde yazılır. Hoca burada bir parantez olması gerektiğini özellikle belirtti. Temel açılımda $x$ yerine $4x^2$ gelmiştir.
- Toplam fonksiyonu: $\dfrac{1}{1-4x^2}$.
- Koşul $4x^2<1$. Her taraf $4$'e bölünür, karekök alınır: $|x|<\dfrac12$.
- Yakınsaklık aralığı $-\dfrac12<x<\dfrac12$. Hoca bunu "güzel bir soru" diye niteledi.

## 5. Terim Terim Türev ve İntegral

Temel açılımdan yeni açılımlar elde etmenin ikinci yolu, eşitliğin iki tarafının türevini ya da integralini almaktır.

**Örnek 7 (terim terim türev).** $\dfrac{1}{(1-x)^2}$'nin seri açılımı ve yakınsaklık aralığı.

Hoca önce şu soruyu sordu: $\dfrac{1}{1-x}$ ile $\dfrac{1}{(1-x)^2}$ arasında nasıl bir ilişki var? Cevap: $\dfrac{1}{1-x}$'in türevi $\dfrac{1}{(1-x)^2}$'dir. O halde
$$\frac{1}{1-x}=\sum_{n=0}^{\infty}x^n$$
eşitliğinin iki tarafının türevi alınır:
$$\frac{1}{(1-x)^2}=\sum_{n=1}^{\infty}n\,x^{n-1}.$$
$n=0$ terimi türevde sıfır olduğu için toplam $n=1$'den başlatılır. Yakınsaklık aralığı $-1<x<1$'dir. Hoca uçların dahil olmadığını söyledi.

Uçların dahil olmadığı kolayca görülür (ara adım eklendi): $x=1$ konunca $\sum n$, $x=-1$ konunca $\sum (-1)^{n-1}n$ çıkar. İkisinde de genel terim sıfıra gitmez, seriler ıraksaktır.

> **Ek bilgi (derste anlatılmadı):** Bir kuvvet serisi terim terim türetilir ya da integre edilirse yakınsaklık yarıçapı değişmez. Ancak uç noktalardaki davranış değişebilir. Bu yüzden türev ya da integral sonrası uç noktalar yeniden incelenmelidir.

**Örnek 8 (terim terim integral).** $\ln(1-x)$'in seri açılımı.

Hoca bu soruyu bir öğrenciye yöneltti: "$\ln(1-x)$'in seri açılımı sorulsaydı ne yapmam lazımdı?" Bu kez iki tarafın integrali alınır. $\int\dfrac{dx}{1-x}=-\ln(1-x)$ olduğundan
$$-\ln(1-x)=\sum_{n=0}^{\infty}\frac{x^{n+1}}{n+1}=x+\frac{x^2}{2}+\frac{x^3}{3}+\cdots$$
bulunur. Hoca daha sonra ekrandaki çözümlü soruların arasında bu açılımın da bulunduğunu gösterdi.

**Örnek 9.** $\displaystyle\sum_{n=1}^{\infty} n\,x^{n-1}=\frac{1}{(1-x)^2}$ eşitliğini kullanarak $\displaystyle\sum_{n=1}^{\infty} n^2x^n$ serisinin toplamını bulunuz. Bu sonucu kullanarak bir sayı serisinin toplamını bulunuz.

Hoca, elimizdeki seride $n$ ve $x^{n-1}$, istenen seride ise $n^2$ ve $x^n$ olduğuna dikkat çekti. Aradaki farkı kapatmak için "manipülasyon" yapmak gerekir.

1. İşimizi bozan $x^{n-1}$'deki $-1$'dir. İki taraf $x$ ile çarpılır:
$$\sum_{n=1}^{\infty} n\,x^{n}=\frac{x}{(1-x)^2}.$$
2. $n^2$ elde etmek için iki tarafın türevi alınır:
$$\sum_{n=1}^{\infty} n^2x^{n-1}=\frac{d}{dx}\left[\frac{x}{(1-x)^2}\right]=\frac{1+x}{(1-x)^3}.$$
3. Yine $x^{n-1}$ kaldı. İki taraf tekrar $x$ ile çarpılır:
$$\sum_{n=1}^{\infty} n^2x^{n}=\frac{x(1+x)}{(1-x)^3},\qquad |x|<1.$$

Sorunun ikinci kısmında $x$ yerine $\dfrac12$ yazılır. Hoca bunun "görme hadisesi" olduğunu, ne kadar çok soru çözülürse sınavda bunu görme olasılığının o kadar artacağını söyledi. Altyazıda sayı serisi açıkça okunmuyor. $x=\tfrac12$ konunca çıkan seri $\sum\dfrac{n^2}{2^n}$'dir (ara adım eklendi):
$$\sum_{n=1}^{\infty}\frac{n^2}{2^n}=\frac{\tfrac12\cdot\tfrac32}{\left(\tfrac12\right)^3}=6.$$

<!-- BELİRSİZ: Sorunun ikinci kısmındaki sayı serisinin tam ifadesi altyazıda okunmuyor; yalnız x yerine 1/2 yazıldığı söyleniyor. -->

> **Ders sonrası not:** Hoca 3. adımı sözlü anlatırken sonucu "$x^2$ bölü $(1-x)$'in karesi" gibi söyledi. Doğru sonuç $\dfrac{x(1+x)}{(1-x)^3}$'tür (sympy ile doğrulandı). Ekrandaki çözümlü sürümde adımlar doğru sırayla gösterildi.

## 6. Bir Fonksiyonu $x-c$'nin Kuvvetlerine Göre Açmak

**Örnek 10.** $\dfrac{1}{2+x}$'i $x$'in kuvvetlerine göre seriye açınız.

Bu, aslında bir sonraki sorudan farklı bir sorudur, ama hoca ikisini karşılaştırmak için önce bunu çözdü. Bilinen açılım $\dfrac{1}{1+x}=\sum (-1)^n x^n$'dir. $2+x$'i bu biçime benzetmek için $2$ dışarı alınır:
$$\frac{1}{2+x}=\frac12\cdot\frac{1}{1+\frac{x}{2}}=\frac12\sum_{n=0}^{\infty}(-1)^n\left(\frac{x}{2}\right)^n.$$
Koşul $\left|\dfrac{x}{2}\right|<1$, yani $-2<x<2$.

**Örnek 11 (sınav sorusu).** $f(x)=\dfrac{1}{2+x}$ fonksiyonunun $x-1$'in kuvvetlerine göre seri temsilini ve yakınsaklık aralığını bulunuz.

Hoca bunun geçmiş bir sınavdan derlenmiş bir soru olduğunu söyledi. $x-1$'in kuvvetlerine göre açmak, $x$'in kuvvetlerine göre açmaktan farklıdır.

1. $t=x-1$ denir. Buradan $x=t+1$ olur.
2. Fonksiyonda yerine yazılır: $2+x=3+t$, yani $\dfrac{1}{2+x}=\dfrac{1}{3+t}$.
3. $3$ dışarı alınır ve Örnek 10'daki gibi açılır:
$$\frac{1}{3+t}=\frac13\cdot\frac{1}{1+\frac{t}{3}}=\frac13\sum_{n=0}^{\infty}(-1)^n\left(\frac{t}{3}\right)^n=\sum_{n=0}^{\infty}\frac{(-1)^n t^n}{3^{n+1}}.$$
4. Koşul $\left|\dfrac{t}{3}\right|<1$, yani $-3<t<3$.
5. $t$ yerine $x-1$ yazılır:
$$\frac{1}{2+x}=\sum_{n=0}^{\infty}\frac{(-1)^n (x-1)^n}{3^{n+1}},\qquad -3<x-1<3\iff -2<x<4.$$

> **Ders sonrası not:** Hoca son adımda aralığı "2 ile 4 arasında" diye söyledi. Doğrusu $-3<x-1<3$ eşitsizliğinin her tarafına $1$ eklenerek bulunan $-2<x<4$'tür (sympy ile doğrulandı). Hoca tekrar özetlerken "eksi bulmuş olduk" dedi; büyük olasılıkla burada sol ucun $-2$ olduğunu düzeltti.

> **Ek bilgi (derste anlatılmadı):** Bir fonksiyonun $x-c$'nin kuvvetlerine göre açılımı, $c$ merkezli bir kuvvet serisidir. Yakınsaklık aralığı da $c$'ye göre simetriktir. Burada merkez $1$, yarıçap $3$'tür ve bu, $x=-2$'deki tekilliğe (paydanın sıfırlandığı noktaya) olan uzaklıktır.

## 7. Uygulamalar: Sayı Serilerinin Karakteri

Moladan sonra hoca "Uygulamalar 1, Uygulamalar 2" başlıklı hazır soru sayfalarını ekranda paylaştı. Bunların daha önce sınavlarda ve kitaplarda sorulmuş sorular olduğunu söyledi. Sorulan şey serinin "karakteri"dir: seri yakınsak mı, ıraksak mı, mutlak yakınsak mı, şartlı yakınsak mı?

### 7.1 İlk Bakılacak Şey: Genel Terim

> **Hocanın vurgusu:** Bir seride ilk bakılacak şey genel terimin limitidir. $\lim a_n\neq0$ ise seri ıraksaktır. Bu, on puanlık bir soruda tek cümlelik cevap olabilir.

Limit sıfır çıkarsa seri yakınsak olabilir de olmayabilir de. Bu durumda başka testlere geçilir.

### 7.2 Örnekler

**Örnek 12.** $\displaystyle\sum_{n=2}^{\infty}(-1)^{n-1}\frac{n}{(n-1)\ln n}$ serisinin karakterini belirleyiniz.

*Genel terim.* Önce mutlak değer alınır, $(-1)^{n-1}$ gider. Genel terimin limitine bakılır:
$$\lim_{n\to\infty}\frac{n}{n-1}\cdot\lim_{n\to\infty}\frac{1}{\ln n}=1\cdot 0=0.$$
$\ln n\to\infty$ olduğundan $\dfrac{1}{\ln n}\to0$. Limit sıfır, test sonuç vermez.

*Mutlak yakınsaklık.* Mukayese testi (comparison test) kullanılır. $n\ge2$ için $n>\ln n$'dir. Bu yüzden
$$\frac{n}{(n-1)\ln n}>\frac{n}{(n-1)\,n}=\frac{1}{n-1}.$$
$\sum\dfrac{1}{n-1}$ harmonik seridir ve ıraksaktır. Alttaki seri ıraksak olduğundan üstteki de ıraksaktır. Yani seri mutlak yakınsak değildir.

*Kendisi.* Seri alterne seridir. $b_n=\dfrac{n}{(n-1)\ln n}$ monoton azalandır ve limiti sıfırdır. Leibniz testine göre seri yakınsaktır.

*Sonuç.* Kendisi yakınsak, mutlak değer serisi ıraksak. Seri **şartlı yakınsaktır**. "Aşağıdakilerden hangisi doğrudur?" diye sorulursa cevap hemen buradan bulunur.

**Örnek 13.** $a_1$ ve $a_{n+1}$ bağıntısıyla tanımlanan bir serinin yakınsaklığını inceleyiniz.

Oran testi uygulanır. Çıkan limit $1$'den küçük olduğu için seri yakınsaktır. Hoca burada oran testinin kuralını tekrarladı: $1$'den büyük olsaydı ıraksak olurdu, $1$ çıksaydı test cevap vermezdi ve limit testi gibi başka bir teste geçilirdi.

<!-- BELİRSİZ: Örnek 13'teki a_1 değeri ve a_{n+1} bağıntısı altyazıda okunmuyor. -->

**Örnek 14 (kök testi).** $n$'inci kuvvet içeren bir serinin karakteri.

Seride kuvvet olduğu için kök testi (root test) uygulanır. $n$'inci kök alınınca $\left(1-\dfrac1n\right)^{n}$ tipinde bir ifade kalıyor. Hoca bu limitin birinci dönemden bilindiğini söyleyip şu formülü hatırlattı.

**Teorem (limit formülü)**

- $\lim a_n=0$ ve $\lim b_n=\infty$ olsun.
- $\lim a_nb_n=\lambda$ ise
$$\lim_{n\to\infty}(1+a_n)^{b_n}=e^{\lambda}.$$

Burada $a_n=-\dfrac1n\to0$, $b_n=n\to\infty$ ve $a_nb_n=-1$'dir. O halde limit $e^{-1}=\dfrac1e$'dir. $\dfrac1e<1$ olduğundan seri yakınsaktır (sympy ile doğrulandı: $\lim(1-1/n)^n=e^{-1}$).

<!-- BELİRSİZ: Örnek 14'teki serinin tam ifadesi altyazıda okunmuyor; yalnız kökten sonra (1 - 1/n)^n tipinde ifade kaldığı anlaşılıyor. -->

Hoca hemen ardından kök testiyle çözülen benzer bir soru daha gösterdi (01:11:03). Bu sorunun ifadesi altyazıda "n bölü n küp artı ..." diye yarım geçiyor.

<!-- BELİRSİZ: 01:11:03'teki ikinci kök testi sorusunun serisi altyazıda okunmuyor. -->

**Örnek 15 (2012 Matematik 2 sınavı).** Serinin yakınsak olup olmadığını belirleyiniz.

*Birinci kısım.* Genel terim $\dfrac{1+n}{2+n}$'dir. Pay ve paydada $n$'in kuvveti $1$'dir, limit katsayılar oranıdır:
$$\lim_{n\to\infty}\frac{1+n}{2+n}=1\neq0.$$
Genel terimin limiti sıfırdan farklı olduğu için seri ıraksaktır. Hoca bunun "bir cümle" ile cevaplanan on puanlık bir soru olduğunu vurguladı.

*İkinci kısım.* Serinin yakınsak, mutlak yakınsak, şartlı yakınsak ya da ıraksak olduğu belirlenir. Hoca bunun test sınavında şıklı olarak da sorulabileceğini söyledi. Seride $\cos(n\pi)$ vardır. Bu ifade $n$'ye göre $-1$, $+1$, $-1$, ... diye işaret değiştirir, yani $\cos(n\pi)=(-1)^n$'dir. Yerine konunca seri alterne seriye dönüşür. Kendisi yakınsaktır, mutlak değeri ıraksaktır. Seri şartlı yakınsaktır, mutlak yakınsak değildir.

<!-- BELİRSİZ: 2012 sınavındaki ikinci serinin cos(nπ) dışındaki kısmı altyazıda okunmuyor. -->

**Örnek 16.** $\displaystyle\sum_{n=1}^{\infty}(-1)^n\frac{2n-1}{\sqrt{n}\,(n+1)}$ serisi için aşağıdakilerden hangisi doğrudur? (A) Seri yakınsaktır. (B) Seri ıraksaktır. (C) Seri şartlı yakınsaktır. (D) Seri mutlak yakınsaktır.

Hoca seriyi yazarken paydada $n+1$ mi $n-1$ mi olduğunu bir an karıştırdı, sonra "fark etmez" dedi ve mutlak değer serisini $\sum\dfrac{2n-1}{\sqrt n\,(n+1)}$ diye yazdı.

*Kendisi yakınsak mı?* Seri $-,+$ diye gittiği için alterne seridir. $b_n=\dfrac{2n-1}{\sqrt n\,(n+1)}$ için Leibniz testinin iki koşuluna bakılır:

- Limit: payın derecesi $1$, paydanınki $\tfrac12+1=\tfrac32$'dir. Payın derecesi paydanınkinden küçük olduğu için $b_n\to0$.
- Monotonluk: $n$ arttıkça $b_n$ azalır.

İki koşul da sağlandığı için seri yakınsaktır. (A) doğru, (B) yanlıştır.

*Mutlak yakınsak mı?* Mutlak değer serisi $\displaystyle\sum\frac{2n-1}{\sqrt n\,(n+1)}$'dir. Hoca önce oran testini denedi:
$$\lim_{n\to\infty}\frac{b_{n+1}}{b_n}=\lim_{n\to\infty}\frac{2n+1}{2n-1}\cdot\frac{\sqrt n}{\sqrt{n+1}}\cdot\frac{n+1}{n+2}=1.$$
Limit $1$ çıktığı için oran testi cevap vermez, "başka kapıya" gidilir. Limit testi uygulanır. Payda $n^1$, paydada $n^{3/2}$ olduğundan seri $\dfrac{1}{\sqrt n}$ ile karşılaştırılır:
$$\lim_{n\to\infty}\frac{\dfrac{2n-1}{\sqrt n\,(n+1)}}{\dfrac{1}{\sqrt n}}=\lim_{n\to\infty}\frac{2n-1}{n+1}=2.$$
Limit $0$ ve $\infty$'dan farklıdır. $\sum\dfrac{1}{\sqrt n}$, $p=\tfrac12\le1$ olan bir $p$-serisi olduğu için ıraksaktır. Mutlak değer serisi de ıraksaktır.

*Sonuç.* Seri yakınsak ama mutlak yakınsak değil, yani şartlı yakınsaktır. (A) ve (C) doğru, (B) ve (D) yanlıştır.

> **Ders sonrası not:** $b_n$ için azalma $n\ge3$'ten itibaren geçerlidir: $b_1=0{,}5$, $b_2\approx0{,}707$, $b_3\approx0{,}722$, $b_4=0{,}7$ (sympy ile doğrulandı). Leibniz testi için azalmanın bir yerden sonra sağlanması yeterli olduğundan sonuç değişmez.

> **Ek bilgi (derste anlatılmadı):** $p$-serisi $\sum\dfrac{1}{n^p}$, $p>1$ ise yakınsak, $p\le1$ ise ıraksaktır. Limit testinde karşılaştırma serisi olarak çoğunlukla bir $p$-serisi seçilir. $p$, genel terimde paydanın derecesinden payın derecesi çıkarılarak bulunur.

**Örnek 17.** $\displaystyle\sum\frac{1+n!}{(n+1)!}$ serisinin karakterini bulunuz.

Faktöriyel görülünce oran testi ya da mukayese testi akla gelir. Hoca burada "manipülasyona dikkat edin, bildiklerimizle mukayese edecek şekilde getiriyoruz" dedi. Paydaki $1$ kaldırılırsa terim küçülür:
$$\frac{1+n!}{(n+1)!}>\frac{n!}{(n+1)!}=\frac{1}{n+1}.$$
$\sum\dfrac{1}{n+1}$, $\sum\dfrac1n$ ile aynı karakterdedir ve ıraksaktır. Alttaki seri ıraksak olduğundan mukayese testine göre verilen seri de ıraksaktır.

## 8. Uygulamalar: Kuvvet Serilerinin Yakınsaklık Aralığı

Bu bölümdeki sorularda hep aynı metot izlendi: oran testiyle açık aralık bulunur, uç noktalar seriye konup incelenir.

**Örnek 18.** Bir kuvvet serisinin yakınsaklık aralığını bulunuz ve aralığın uç noktalarında serinin yakınsaklığını inceleyiniz (01:20:48).

Oran testiyle açık aralık $1<x<3$ bulundu. Uç noktalar seriye konunca hem $x=1$'de hem $x=3$'te seri ıraksak çıktı. Aralık $(1,3)$'tür.

<!-- BELİRSİZ: Örnek 18'deki serinin ifadesi altyazıda okunmuyor. -->

**Örnek 19.** $\displaystyle\sum_{n=1}^{\infty}\frac{(x-1)^n}{\sqrt[4]{n^3+1}}$ serisi hangi $x$ değerleri için mutlak yakınsak, hangileri için şartlı yakınsaktır? Yakınsaklık aralığını bulunuz.

Serinin ifadesi altyazıda "x eksi bir üzeri n bölü dördüncü dereceden kök n küp artı bir" biçiminde bozuk geçiyor. Hocanın verdiği sonuçlar ($p=\tfrac34$, $0$ dahil, $2$ hariç) bu ifadeyle uyumludur.

*Açık aralık.* Oran testi:
$$\left|\frac{u_{n+1}}{u_n}\right|=|x-1|\,\sqrt[4]{\frac{n^3+1}{(n+1)^3+1}}\ \xrightarrow{\,n\to\infty\,}\ |x-1|<1.$$
Buradan $0<x<2$ bulunur. Bu aralıkta seri mutlak yakınsaktır.

*Uç nokta $x=2$.* $x-1=1$ olur ve seri $\displaystyle\sum\frac{1}{\sqrt[4]{n^3+1}}$'e dönüşür. Bu terim $\dfrac{1}{n^{3/4}}$ gibi davranır. Limit testi:
$$\lim_{n\to\infty}\frac{1/\sqrt[4]{n^3+1}}{1/n^{3/4}}=1.$$
$\sum\dfrac{1}{n^{3/4}}$ için $p=\tfrac34<1$, yani ıraksaktır. Aynı karakterde olduklarından seri $x=2$'de ıraksaktır.

*Uç nokta $x=0$.* $x-1=-1$ olur ve seri $\displaystyle\sum\frac{(-1)^n}{\sqrt[4]{n^3+1}}$'e dönüşür. Bu alterne seride $b_n=\dfrac{1}{\sqrt[4]{n^3+1}}>0$ monoton azalandır ve limiti sıfırdır. Leibniz testine göre seri yakınsaktır. Mutlak değeri $x=2$'deki seridir ve ıraksaktır. O halde $x=0$'da seri şartlı yakınsaktır.

*Sonuç.* $(0,2)$'de mutlak yakınsak, $x=0$'da şartlı yakınsak, $x=2$'de ıraksak. Yakınsaklık aralığı $[0,2)$'dir; alt uç dahil, üst uç hariçtir.

**Örnek 20.** Bir serinin yakınsaklık aralığı aşağıdakilerden hangisidir?

Hoca bu sorunun genel terimini "$x$ üzeri $2n$ bölü $n$ faktöriyel" gibi okudu ve öğrencilere soruları kapatıp önce kendilerinin çözmesini önerdi. Oran testinde $n\to\infty$ iken oran sıfıra gider. Bu her $x$ için doğrudur, çünkü $x$ sabit kalırken payda faktöriyel olarak büyür. Yakınsaklık aralığı $(-\infty,\infty)=\mathbb{R}$, yakınsaklık yarıçapı $R=\infty$'dur. Hoca iki yazımın da doğru olduğunu söyledi.

Genel terim $\dfrac{x^{2n}}{n!}$ alınırsa oran $\dfrac{x^2}{n+1}\to0$ olur (sympy ile doğrulandı).

<!-- BELİRSİZ: Örnek 20'nin genel terimi x^{2n}/n! mi yoksa x^n/(2n)! mi, altyazıdan kesin değil; iki durumda da R = ∞ çıkar. -->

**Örnek 21.** Bir serinin yakınsaklık aralığını ve mutlak, şartlı yakınsak olduğu $x$ değerlerini bulunuz.

Oran testinde $n$'li kısmın limiti $1$'e gidiyor ve geriye $x$'li bir ifade kalıyor. Hoca $x=1$ konunca "üç kere bir, üç, iki daha, beş, beş bölü beş" dediği için oran testinden çıkan koşul büyük olasılıkla $\left|\dfrac{3x+2}{5}\right|<1$ biçimindedir. Bu koşul $-5<3x+2<5$, yani $-\dfrac73<x<1$ verir (sympy ile doğrulandı). Bu, hocanın bulduğu aralıkla uyumludur.

- Açık aralıkta seri mutlak yakınsaktır.
- $x=1$'de $(-1)^n$ çarpanlı bir seri kalıyor. Bu alterne seri şartlı yakınsaktır.
- $x=-\dfrac73$'te çıkan seri ıraksaktır.
- Yakınsaklık aralığı $\left(-\dfrac73,1\right]$'dir.

Hoca test sorularında şıkların tam bu noktada, yani uçların dahil olup olmamasında ayrıştığını söyledi.

> **Hocanın vurgusu:** Test sınavında şıklar uç noktanın dahil olup olmamasıyla birbirinden ayrılır. Uç noktaları dikkatle inceleyin.

> **Ders sonrası not:** Hoca sonunda aralığı bir yerde "eksi yedi bölü iki ile bir" diye söyledi. Doğrusu, kendisinin de önce bulduğu gibi $-\dfrac73$'tür.

<!-- BELİRSİZ: Örnek 21'deki serinin tam ifadesi altyazıda okunmuyor. -->

Hoca ardından bol işlem yapmanın önemini vurguladı: farklı tipte çok soru çözülmezse sınavda takılıp kalınır.

**Örnek 22.** Bir serinin yakınsaklık aralığını bulunuz, aralığın uç noktalarındaki seriyi inceleyiniz (01:31:34).

Hoca bu soruda yöntemi tekrar etti: yakınsaklık aralığı bulunur, uç noktalar yerine konur. Ayrıntıya girmedi.

<!-- BELİRSİZ: Örnek 22'nin serisi ve sonucu altyazıda geçmiyor. -->

**Örnek 23.** Bir serinin mutlak ya da şartlı yakınsak olduğu $x$ değerlerini bulunuz (01:32:10).

- Oran testi: $-2<x<2$. Bu aralıkta seri mutlak yakınsaktır.
- $x=2$: genel terimin limiti sıfırdan farklı çıkıyor. Terim testine göre seri ıraksaktır.
- $x=-2$: seri alterne seri oluyor, ama genel terimin mutlak değeri yine $1$'e gidiyor, sıfıra gitmiyor. Genel terim testine göre bu seri de ıraksaktır.
- Aralık $(-2,2)$'dir; iki uç da dahil değildir.

<!-- BELİRSİZ: Örnek 23'teki serinin ifadesi altyazıda okunmuyor. -->

**Örnek 24.** Katsayısında $\sqrt{n+1}-\sqrt n$ bulunan bir kuvvet serisi hangi $x$ değerleri için mutlak ya da şartlı yakınsaktır? (01:33:14)

Hoca $\sqrt{n+1}-\sqrt n$ ifadesinin eşleniğiyle çarpılarak sadeleştirildiğini hatırlattı. Bu, birinci dönemde limitlerde yapılan işlemin aynısıdır:
$$\sqrt{n+1}-\sqrt n=\frac{1}{\sqrt{n+1}+\sqrt n}.$$
Düzenleme sonunda yakınsaklık aralığı bulundu ve uç noktalar $x=2$ ile $x=4$ çıktı. Hoca, $x=4$'te serinin bilinen ıraksak bir seriye dönüştüğünü, diğer uçta da ıraksak olduğunu söyledi. Sonuçta seri yalnız açık aralıkta yakınsaktır.

<!-- BELİRSİZ: Örnek 24'teki serinin tam ifadesi altyazıda okunmuyor; x=2 ucunda neden ıraksak olduğu da anlatılmıyor. -->

> **Ders sonrası not:** Serinin tam ifadesi altyazıda olmadığı için hocanın sonucu doğrulanamadı. Seri $\sum(\sqrt{n+1}-\sqrt n)(x-3)^n$ biçiminde olsaydı, $x=2$'de çıkan $\sum(-1)^n(\sqrt{n+1}-\sqrt n)$ alterne serisi Leibniz testine göre yakınsak olurdu. Hocanın "iki uçta da ıraksak" sonucu ancak seri farklı bir biçimdeyse (örneğin terim $\dfrac{(x-3)^n}{\sqrt{n+1}-\sqrt n}$ ise) doğrudur. Ekrandaki ifadeye bakılmalıdır.

## 9. Örnek Sorular

Bu derste kare ve video yok. Aşağıdaki sorular hocanın derste sözlü sorduğu ya da bir öğrencinin sorduğu sorulardır. Ekranda çözülen sorular yukarıda numaralı örnekler olarak verildi.

**Soru 1** (derste sözlü, 00:09:03). $\sum n!\,x^n$ yerine $\sum n!\,(x-1)^n$ serisi verilseydi ne değişirdi?

> **Çözüm (derste verildi):** Oran $(n+1)|x-1|$ olur ve $x\neq1$ için sonsuza gider. Seri yalnız merkezde, $x=1$'de yakınsak, onun dışında ıraksaktır.

**Soru 2** (derste sözlü, 00:19:12). $\dfrac{1}{1-x}=\sum x^n$ biliniyorsa $\dfrac{1}{1+x}$'in açılımı ve aralığı nedir?

> **Çözüm (derste verildi):** $x$ yerine $-x$ yazılır: $\dfrac{1}{1+x}=\sum_{n=0}^{\infty}(-1)^n x^n$, $|x|<1$. Aralık değişmez.

**Soru 3** (derste sözlü, 00:20:07). $\dfrac{1}{1+3x}$'in açılımı ve yakınsaklık aralığı nedir?

> **Çözüm (derste verildi):** $\dfrac{1}{1+3x}=\sum_{n=0}^{\infty}(-1)^n3^nx^n$. Koşul $|3x|<1$, yani $-\dfrac13<x<\dfrac13$.

**Soru 4** (derste sözlü, bir öğrenci, 00:21:47). Geometrik seri toplamı neden $n=0$'dan başlatılıyor, $n=1$'den başlaması gerekmez mi?

> **Çözüm (derste verildi):** $n=0$ terimi $x^0=1$'dir. Açılımın ilk terimi $1$ olduğu için toplam $0$'dan başlar: $1+x+x^2+\cdots$.

**Soru 5** (derste sözlü, 00:26:47). $\dfrac{1}{1-x}$ ile $\dfrac{1}{(1-x)^2}$ arasında nasıl bir ilişki var? Bunu kullanarak $\dfrac{1}{(1-x)^2}$'yi seriye açınız.

> **Çözüm (derste verildi):** İkincisi birincinin türevidir. Terim terim türev alınarak $\dfrac{1}{(1-x)^2}=\sum_{n=1}^{\infty}n\,x^{n-1}$, $-1<x<1$ bulunur.

**Soru 6** (derste sözlü, 00:28:07). $\ln(1-x)$'in seri açılımı sorulsaydı ne yapmak gerekirdi?

> **Çözüm (derste verildi):** $\dfrac{1}{1-x}=\sum x^n$ eşitliğinin iki tarafının integrali alınır: $-\ln(1-x)=\sum_{n=0}^{\infty}\dfrac{x^{n+1}}{n+1}$.

## Dersin Toparlaması

Bu derste yeni bir konu anlatılmadı; kuvvet serileri ve seri testleri soru çözümüyle pekiştirildi. Bir kuvvet serisinin yakınsaklık aralığı oran testiyle bulunur ve bu aralık her zaman açık aralıktır. Uç noktalar ayrıca seriye konup incelenir. Uçlarda çıkan sayı serileri için genel terim testi, mukayese ve limit testleri ($p$-serisiyle karşılaştırma) ve alterne seriler için Leibniz testi kullanılır. Bir seri kendisi yakınsak ama mutlak değer serisi ıraksaksa şartlı yakınsaktır. Geometrik seri açılımı $\dfrac{1}{1-x}=\sum x^n$ ($|x|<1$), değişken değiştirme, terim terim türev ve integral ile yeni açılımlar üretmenin temelidir. $x-c$'nin kuvvetlerine göre açılımda önce $t=x-c$ dönüşümü yapılır, sonuç aralığı $x$'e geri çevrilir.

Hoca gelecek hafta Taylor ve Maclaurin serileri ile uygulamalarının işleneceğini, ardından kutupsal koordinatlara ve çok değişkenli fonksiyonlara (tanım kümeleri, çizimler, limit, süreklilik, türev) geçileceğini söyledi. Tek değişkenli konularda eksiği olanların bu konuları gözden geçirmesini istedi. Dersin sınıfta bir "bilim atölyesi" olduğunu, kimsenin kimseden "epsilon kadar" farkı olmadığını söyleyerek anlaşılmayan yerlerin çekinmeden sorulmasını istedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
