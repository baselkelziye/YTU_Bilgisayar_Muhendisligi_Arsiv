# Ders 2 Genişletilmiş Notu: Seri Toplamları ve Yakınsaklık Testleri: İntegral, Karşılaştırma, Oran ve Kök Testleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri ve Planı
- 2. Seri Toplamı Soruları
- 3. Verilen Terimlerden Genel Terimi Bulma
- 4. Yakınsaklık Testlerine Giriş
- 5. İntegral Testi ve $p$-Serisi
- 6. Karşılaştırma (Mukayese) Testi
- 7. Genel Terim ($n$-inci Terim) Testi
- 8. Karşılaştırma Testine Dönüş: İki Örnek Daha
- 9. Limit Karşılaştırma Testi
- 10. Oran Testi
- 11. Kök Testi
- 12. Genel Terim Testine Son Bir Örnek
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Yeri ve Planı

Ders, Zoom üzerinden yapıldı. Hoca tablete ve ekranda paylaştığı soru sayfalarına yazarak anlattı. Altyazıda yalnız sözlü anlatım var. Bu yüzden formüller ve çözüm adımları hocanın söylediklerinden kuruldu.

Bir önceki derste diziler (sequences) ve seriler (series) başlamıştı. Geometrik serinin toplamı ve $p$-serisi için bir özellik verilmişti. Bu derste hoca önce önceki dersten kalan seri toplamı sorularını çözdü. Sonra serilerin yakınsak (convergent) mı ıraksak (divergent) mı olduğunu anlamaya yarayan testlere geçti.

Hoca başta "integral testinden önce mukayese testi olması lazım" dedi. Ama derste sıra şöyle oldu: önce integral testi, sonra karşılaştırma testi, genel terim testi, limit karşılaştırma testi, oran testi ve kök testi.

## 2. Seri Toplamı Soruları

Bir seride bizden toplam istendiğinde önce serinin yakınsak mı ıraksak mı olduğuna bakılır. Seri yakınsaksa bir sayı çıkar. Iraksaksa "toplam bulunmaz" denir.

Yöntem şudur: Serinin ilk $n$ teriminin toplamı olan kısmi toplam $S_n$ yazılır. Bu kısmi toplamlar dizisinin $n\to\infty$ için limiti alınır. Bu limit varsa ve sonluysa, serinin toplamı bu limittir:

$$\sum_{n=1}^{\infty} a_n = \lim_{n\to\infty} S_n .$$

### 2.1 Teleskopik Seri

Hocanın ekranda paylaştığı sorulardan ilki şuydu:

$$\sum_{n=1}^{\infty} \frac{4}{n^2+4n+3}.$$

Hoca bu serinin "bildiğimiz tarzda olmadığını", önce düzenlenmesi gerektiğini söyledi. Payda çarpanlarına ayrılır:

$$n^2+4n+3=(n+1)(n+3).$$

Sonra basit kesirlere ayırma yapılır:

$$\frac{4}{(n+1)(n+3)}=\frac{A}{n+1}+\frac{B}{n+3}.$$

Paydalar eşitlenince $4=A(n+3)+B(n+1)$ olur (ara adım eklendi). Buradan $A=2$ ve $B=-2$ bulunur. Hoca da $A=2$, $B=-2$ sonucunu verdi. Böylece seri iki serinin farkı biçiminde yazılır:

$$\sum_{n=1}^{\infty} \frac{4}{n^2+4n+3}=2\sum_{n=1}^{\infty}\left(\frac{1}{n+1}-\frac{1}{n+3}\right).$$

Hoca bu tür serilere teleskopik seri (telescoping series) dendiğini söyledi. Kısmi toplam terim terim açılır:

$$S_n=2\left[\left(\frac12-\frac14\right)+\left(\frac13-\frac15\right)+\left(\frac14-\frac16\right)+\dots+\left(\frac{1}{n+1}-\frac{1}{n+3}\right)\right].$$

Terimler ikişer adım arayla birbirini götürür. Baştan $\frac12$ ve $\frac13$ kalır. Sondan $-\frac{1}{n+2}$ ve $-\frac{1}{n+3}$ kalır:

$$S_n=2\left(\frac12+\frac13-\frac{1}{n+2}-\frac{1}{n+3}\right).$$

$n\to\infty$ için "sayı bölü sonsuz" biçimindeki iki terim $0$'a gider. Geriye $2\cdot\frac56=\frac53$ kalır:

$$\sum_{n=1}^{\infty} \frac{4}{n^2+4n+3}=\lim_{n\to\infty}S_n=\frac53.$$

Hoca "Metot bu" diyerek kısmi toplamlar dizisinin limitinin serinin toplamı olduğunu bir kez daha vurguladı.

### 2.2 Logaritmalı Seri

Hoca ikinci soruyu boş bir sayfada çözdü:

$$\sum_{n=2}^{\infty} \ln\frac{n-1}{n}.$$

Seri $n=2$'den başlar. Çünkü $n=1$ için $\ln 0$ tanımsızdır. Bunu derste bir öğrenci de söyledi.

**Soru:** Bir öğrenci cevabın $1$ olup olmadığını sordu. Gerekçesi şuydu: $\frac{n-1}{n}=1-\frac1n$ yazılırsa, limitte öğrenilen $\left(1-\frac1n\right)^n$ ifadesinden $e$'nin bir kuvveti gelir. **Cevap:** Hoca bu limitin değerini sordu, sonra seriyi kısmi toplamla çözdü. Bu sorudaki ifade bir kuvvet değil, logaritmaların toplamıdır.

<!-- BELİRSİZ: 00:12:18-00:12:27 arasında "Eksi bir eşitir" ve "burası artı olsaydı ... artı bir" sözlerinin kime ait olduğu ve tam ne dendiği altyazıda net değil. -->

Kısmi toplam tek tek yazılır:

$$S_n=\ln\frac12+\ln\frac23+\ln\frac34+\dots+\ln\frac{n-1}{n}.$$

Logaritmanın özelliğinden toplamların logaritması çarpımın logaritmasıdır:

$$S_n=\ln\left(\frac12\cdot\frac23\cdot\frac34\cdots\frac{n-1}{n}\right).$$

Çarpımda terimler birbirini götürür ve geriye $\frac1n$ kalır:

$$S_n=\ln\frac1n.$$

Limit alınırken derste kısa bir tartışma oldu. Bir öğrenci $\frac1n\to0$ olduğu için cevabın sıfır olduğunu düşündü. Başka bir öğrenci "eksi sonsuz olmaz mı?" diye sordu. Hoca doğru cevabı verdi: $\frac1n$ sıfıra gider, ama $\ln\frac1n$ eksi sonsuza gider:

$$\lim_{n\to\infty}S_n=\lim_{n\to\infty}\ln\frac1n=-\infty.$$

Kısmi toplamlar dizisi sonlu bir sayıya gitmediği için seri ıraksaktır. Hoca şıklardaki sayısal cevapların hepsinin bu yüzden elendiğini söyledi.

> **Ders sonrası not:** Derste $\left(1-\frac1n\right)^n$ limitinin değeri "eksi bir" diye söylendi. Doğrusu $\lim_{n\to\infty}\left(1-\frac1n\right)^n=e^{-1}=\frac1e$ olur. Hoca dersin sonunda aynı limiti doğru olarak $e^{-1}$ diye verdi (bkz. Bölüm 12).

### 2.3 İki Geometrik Serinin Farkı

Hoca bu soruyu "ÖYS sorusu gibi" diye tanıttı:

$$\sum_{n=1}^{\infty} \frac{3^{n-1}-1}{6^{n-1}}.$$

Kesir iki parçaya ayrılır. $\frac{a-b}{c}=\frac ac-\frac bc$ kuralı kullanılır:

$$\sum_{n=1}^{\infty}\left(\frac{1}{2}\right)^{n-1}-\sum_{n=1}^{\infty}\left(\frac{1}{6}\right)^{n-1}.$$

İki parça da geometrik seridir. Bir önceki derste geometrik serinin toplamı $\frac{a}{1-r}$ olarak verilmişti. Burada $a$ ilk terim, $r$ ortak çarpandır ve $|r|<1$ olmalıdır.

- **Birinci seri:** $n=1$ için $\left(\frac12\right)^0=1$, yani $a=1$. Ortak çarpan $r=\frac12$. Toplam $\dfrac{1}{1-\frac12}=2$.
- **İkinci seri:** $n=1$ için yine $a=1$. Terimler $1,\frac16,\frac1{36},\dots$ diye gider, yani $r=\frac16$. $r<1$ olduğu için yakınsaktır. Toplam $\dfrac{1}{1-\frac16}=\dfrac65$.

Serinin toplamı iki toplamın farkıdır:

$$2-\frac65=\frac45.$$

> **Ders sonrası not:** Hoca iki parçanın toplamlarını ($2$ ve $\frac65$) buldu, ama altyazıda farkı söylenmiyor. Sonuç $\frac45$'tir. Bu değer python (sympy) ile de doğrulandı.

## 3. Verilen Terimlerden Genel Terimi Bulma

Hoca bir sonraki soru tipini "dizisinin genel terimi aşağıdakilerden hangisidir?" diye tanıttı. Burada önemli olan örüntü (pattern) bulmaktır. Hoca örüntüyü "çok kıymetli bir şey" diye niteledi. Kısa nottaki terimler şunlardır:

$$\frac19,\ \frac2{12},\ \frac4{15},\ \frac8{18},\ \dots$$

Paylar $1,2,4,8$ diye gider. Bunlar ikinin kuvvetleridir: $2^0,2^1,2^2,2^3$. Paydalar $9,12,15,18$ diye gider. Bunlar $3\cdot3,\ 3\cdot4,\ 3\cdot5,\ 3\cdot6$ biçimindedir, yani hepsinde $3$ çarpanı sabittir.

Hoca önce payı $2^n$ diye yazdı, sonra üs ile paydadaki çarpanı ilk terime uyacak şekilde deneme yanılma ile düzeltti. Doğal sayılar $1$'den başladığı için $n=1$ ilk terimi vermelidir. Sonuç şudur:

$$a_n=\frac{2^{n-1}}{3(n+2)}.$$

Kontrol: $n=1$ için $\frac{1}{9}$, $n=2$ için $\frac{2}{12}$, $n=3$ için $\frac{4}{15}$, $n=4$ için $\frac{8}{18}$ çıkar. Hoca bu kontrolü "bir veriyorum, veriyor; iki veriyorum, veriyor" diye yaptı.

<!-- BELİRSİZ: 00:19:06-00:19:51 arasında hocanın denediği ara ifadeler ("en artı iki", "3 çarpı en eksi 1") altyazıda karışık. Sonuçtaki genel terim kısa nottaki gibi alındı. -->

## 4. Yakınsaklık Testlerine Giriş

Hoca serilerin yakınsaklığını belirlemek için bir takım yöntemler olduğunu söyledi ve bunları saydı: integral testi, mukayese (karşılaştırma) kriteri, D'Alembert oran testi ve kök testi. Bu testler, bir serinin yakınsak mı ıraksak mı olduğunu belirlemekte "ışık tutar". Seri yakınsaksa toplamı aranır. Iraksaksa ıraksak olduğu tespit edilir.

> **Ek bilgi (derste anlatılmadı):** Altyazıda kök testi için "abi kök testi" gibi duyulan bir ad geçiyor. Kök testi kaynaklarda büyük olasılıkla "Cauchy kök testi" adıyla geçer. Oran testi ise "D'Alembert oran testi" olarak bilinir.

## 5. İntegral Testi ve $p$-Serisi

### 5.1 Teorem

Hoca integral testini (integral test) şöyle tanıttı: Pozitif terimli bir seri, benzer davranan bir has olmayan integral (improper integral) ile karşılaştırılarak incelenebilir.

**Teorem (İntegral testi)**

- $N$ pozitif bir tam sayı olsun.
- $f$ fonksiyonu $[N,\infty)$ aralığında **pozitif**, **sürekli** ve **azalan** olsun.
- $a_n=f(n)$ olsun.
- Bu durumda $\displaystyle\sum_{n=N}^{\infty}a_n$ serisi ile $\displaystyle\int_N^{\infty}f(x)\,dx$ integrali ya ikisi birden yakınsak ya da ikisi birden ıraksaktır.

Hoca üç koşulu tek tek vurguladı: pozitif, sürekli, azalan. Bu üç koşul sağlanırsa serinin karakteri ile integralin karakteri aynıdır. İntegral yakınsaksa seri yakınsaktır. İntegral ıraksaksa seri ıraksaktır.

> **Hocanın vurgusu:** Bu test yalnız yakınsaklık ve ıraksaklık bilgisini verir. İntegral bir sayıya eşitse, serinin toplamı da o sayıya eşittir diyemeyiz.

Fonksiyonun azalan olduğu her zaman gözle görülmeyebilir. Hoca bu durumda türeve bakılmasını söyledi: $f'(x)<0$ ise $f$ azalandır.

### 5.2 Harmonik Seri

Hoca ilk örnek olarak harmonik serinin (harmonic series) ıraksak olduğunun bu testle gösterilebileceğini söyledi:

$$\sum_{n=1}^{\infty}\frac1n.$$

Genel terim $\frac1n$ olduğu için fonksiyon $f(x)=\frac1x$ seçilir. $n$ arttıkça $\frac1n$ azalır. Doğal sayılar için pozitiftir. İntegral testi uygulanabilir ve seri ıraksaktır. Hoca bu sonucu bir sonraki genel örneğin özel hâli olarak gösterdi.

### 5.3 $p$-Serisinin Yakınsaklığı

Hoca "bir taşta iki kuş" diyerek genel bir seri aldı:

$$\sum_{n=1}^{\infty}\frac{1}{n^p}.$$

Soru, bu serinin hangi $p$ değerleri için yakınsak, hangileri için ıraksak olduğudur.

Fonksiyon $f(x)=\frac{1}{x^p}$ alınır. Hoca öğrencilere sordu: $[1,\infty)$ aralığında azalan mı, pozitif mi, sürekli mi? Öğrenciler üçüne de "evet" dedi. O zaman serinin karakteri ile şu integralin karakteri aynıdır:

$$\int_1^{\infty}\frac{dx}{x^p}.$$

Hoca bu seçimin nedenini şöyle açıkladı: Serinin toplamını göstermek kolay değildir, ama integrali hesaplamak kolaydır.

$p\ne1$ için integral alınır:

$$\int_1^{\infty}x^{-p}\,dx=\left[\frac{x^{1-p}}{1-p}\right]_1^{\infty}.$$

Önce üst sınır, sonra alt sınır yerine konur. Sonuç $p$'ye göre değişir:

- **$p>1$:** $1-p<0$ olduğu için $x^{1-p}=\frac{1}{x^{p-1}}$ olur ve $x\to\infty$ için $0$'a gider. Geriye alt sınırdan gelen terim kalır. İntegral $\frac{1}{p-1}$'e eşittir, yani yakınsaktır.
- **$p<1$:** $1-p>0$ olduğu için $x^{1-p}\to\infty$ olur. İntegral ıraksaktır.

Hoca $p=2$ için hesabı öğrencilerle birlikte yaptı. Üst sınır sonsuz konunca terim $0$ olur. Alt sınır $1$ konunca $1$ kalır. Yani $\int_1^\infty\frac{dx}{x^2}=1$ olur ve integral yakınsaktır.

**Soru:** Bir öğrenci $p=1$ alınabilir mi diye sordu. **Cevap:** Hoca, formülde paydada $1-p$ olduğunu, $p=1$ için bunun $0$ olacağını ve ifadenin tanımsız kalacağını söyledi. Bu yüzden $p=1$ durumunu ıraksak olarak aldı.

> **Ders sonrası not:** $p=1$ için doğru gerekçe, ayrı bir hesap yapmaktır. Formülün tanımsız olması tek başına ıraksaklık kanıtı değildir. $p=1$ için $\displaystyle\int_1^{\infty}\frac{dx}{x}=\lim_{b\to\infty}\ln b=\infty$ olur. İntegral ıraksaktır, dolayısıyla harmonik seri de ıraksaktır. Sonuç hocanınkiyle aynıdır.

**Soru:** Bir öğrenci, testle yalnız yakınsak olduğunu mu öğrendiğimizi, yoksa "sıfıra yakınsak" gibi bir değer de söyleyip söyleyemeyeceğimizi sordu. **Cevap:** Hayır. Test yalnız yakınsak olduğunu gösterir, değeri vermez.

Bu hesaptan şu sonuç çıkar:

**Sonuç ($p$-serisi testi)**

- $\displaystyle\sum_{n=1}^{\infty}\frac{1}{n^p}$ serisi $p>1$ ise yakınsaktır.
- $p\le1$ ise ıraksaktır.

Hoca hemen iki uygulama verdi:

- $\displaystyle\sum\frac{1}{\sqrt n}$: Burada $p=\frac12$'dir. $\frac12<1$ olduğu için seri ıraksaktır. Öğrenciler bunu doğru cevapladı.
- Paydada $\sqrt{n^3}$ olsaydı, yani $\displaystyle\sum\frac{1}{n^{3/2}}$: $p=\frac32>1$ olduğu için seri yakınsaktır.

Hoca bu tür bilgilerin şıklarda sorulabileceğini, konuya ne kadar hâkim olunduğunu ölçtüğünü söyledi.

## 6. Karşılaştırma (Mukayese) Testi

### 6.1 Teorem

Hoca bu testi "mukayese kriteri, yani karşılaştırma testi (comparison test)" diye adlandırdı. Fikir, bilinmeyen bir seriyi bildiğimiz bir seriyle karşılaştırmaktır.

**Teorem (Karşılaştırma testi)**

- $\sum a_n$ ve $\sum b_n$ terimleri negatif olmayan iki seri olsun.
- Her $n$ için $a_n\le b_n$ olsun.
- $\sum b_n$ yakınsak ise $\sum a_n$ yakınsaktır.
- $\sum a_n$ yakınsak ise $\sum b_n$ için bir şey söylenemez.
- $\sum a_n$ ıraksak ise $\sum b_n$ ıraksaktır.

Hoca bunu "üst taraftaki yakınsaksa alt taraftaki yakınsaktır; alt taraftaki ıraksaksa üst taraftaki ıraksaktır" diye özetledi. Öğrenciler ters yönler için doğru olarak "bir şey söyleyemeyiz" dedi.

Karşılaştırma için genellikle seçilen seriler şunlardır:

- geometrik seri,
- harmonik seri,
- $p$-serisi.

### 6.2 Örnek: $\sum\frac{1}{n-1}$

Hoca öğrencilerden bir örnek üretmelerini istedi, sonra kendisi şu seriyi yazdı:

$$\sum_{n=2}^{\infty}\frac{1}{n-1}.$$

Bazı öğrenciler "terimler sıfıra yaklaşıyor, yakınsak" dedi. Hoca bunun yanlış olduğunu söyledi. Genel terimin sıfıra gitmesi yakınsaklık için yetmez (bkz. Bölüm 7).

Doğru yol karşılaştırmadır. $n-1<n$ olduğu için

$$\frac{1}{n-1}>\frac1n$$

olur. Yani incelenen seri harmonik seriden büyüktür. Harmonik seride $p=1$'dir ve seri ıraksaktır. Küçük seri ıraksak olduğu için büyük seri de ıraksaktır:

$$\sum_{n=2}^{\infty}\frac{1}{n-1}\ \text{ıraksaktır.}$$

Derste hoca önce $\frac{1}{n-1}\le\frac{1}{n}$ yazılıp yazılamayacağını sordu. Bir öğrenci "yazamayız" dedi, hoca da onayladı. Hoca ayrıca karşılaştırmada araya $\frac12$ gibi bir katsayı koyduğunu söyledi.

**Soru:** Bir öğrenci açıklamanın tekrarlanmasını istedi. **Cevap:** Hoca, bilinmeyen seriyi bildiğimiz $\sum\frac1n$ ile karşılaştırmak gerektiğini, eşitsizliğin yönünün önemli olduğunu ve katsayı ile eşitsizliğin istenen yöne getirildiğini anlattı.

**Soru:** Bir öğrenci, araya konan $\frac12$ katsayısının belli bir oranı olup olmadığını sordu. **Cevap:** Katsayının değeri önemli değildir. $\frac12$, $5$ ya da $10$ konabilir. Seri ıraksaksa katsayı sonucu değiştirmez. Hoca bunu "manipülasyon", yani göstermek için yapılan bir düzenleme diye adlandırdı.

> **Ders sonrası not:** Bu seride katsayıya gerek yoktur, çünkü $\frac{1}{n-1}>\frac1n$ eşitsizliği zaten doğrudur. Katsayı, sonraki örnekteki gibi eşitsizliğin ters çıktığı durumlarda gerekir.

> **Ek bilgi (derste anlatılmadı):** $\sum_{n=2}^{\infty}\frac{1}{n-1}$ serisinde $m=n-1$ yazılırsa seri $\sum_{m=1}^{\infty}\frac1m$ olur. Yani bu seri, büyük olasılıkla bir kaydırma ile harmonik serinin kendisidir. Bu yüzden ıraksak olması doğrudan görülebilir.

### 6.3 Örnek: $\sum\frac{1}{n^2-2}$

Hoca yeni bir örnek yazdı. Önce payda $n^2+2$ diye başladı, sonra "eksi iki diyeyim" diyerek değiştirdi:

$$\sum_{n=2}^{\infty}\frac{1}{n^2-2}.$$

Bildiğimiz seri $\sum\frac{1}{n^2}$'dir. Burada $p=2>1$ olduğu için seri (integral testinden, yani $p$-serisi testinden) yakınsaktır. Bu yakınsak seriyle karşılaştırma yapılmak istenir. Yakınsak bir seriden yararlanmak için incelenen serinin ondan **küçük** olduğu gösterilmelidir.

**Soru:** Bir öğrenci şunu fark etti: Paydada sayı küçüldükçe kesir büyür. Bu yüzden $\frac{1}{n^2-2}>\frac{1}{n^2}$ olur. **Cevap:** Hoca öğrenciyi tebrik etti ve doğru olduğunu söyledi. Payda $n^2+2$ olsaydı eşitsizlik istenen yönde olurdu. Burada ise başa bir katsayı koymak gerekir.

Katsayı ile düzeltme şöyledir. $n\ge2$ için $n^2\le 2(n^2-2)$ olduğundan (ara adım eklendi)

$$\frac{1}{n^2-2}\le\frac{2}{n^2}$$

olur. $\sum\frac{2}{n^2}=2\sum\frac{1}{n^2}$ yakınsaktır. Küçük seri olan $\sum\frac{1}{n^2-2}$ de karşılaştırma testine göre yakınsaktır.

<!-- BELİRSİZ: Hocanın bu örnekte başa koyduğu katsayının değeri altyazıda net değil ("1 bölü 2 getireceğim" deniyor). Katsayı 2 alınırsa eşitsizlik her n ≥ 2 için doğrudur; bu python ile denetlendi. -->

## 7. Genel Terim ($n$-inci Terim) Testi

Hoca öğrencilerin az önceki sorularından aklına gelen iki teoremi yazdı.

**Teorem 1**

- $\sum a_n$ yakınsak ise $\lim_{n\to\infty}a_n=0$ olur.
- Bu teoremin tersi her zaman doğru değildir. Genel terimin limiti sıfır olduğu hâlde seri yakınsak olmayabilir.

**Teorem 2 (Genel terim testi)**

- $\lim_{n\to\infty}a_n\ne0$ ise $\sum a_n$ ıraksaktır.

### 7.1 Örnek: $\sum\frac{n+2}{n+5}$

Hoca bu sorunun bir sınavda sorulduğunu, öğrencilerin uğraştığını ama bulamadığını anlattı:

$$\sum\frac{n+2}{n+5}.$$

Genel terimin limiti alınır:

$$\lim_{n\to\infty}\frac{n+2}{n+5}=1.$$

$1\ne0$ olduğu için seri ıraksaktır.

> **Hocanın vurgusu:** Bir seri görünce ilk iş genel terimin limitine bakmaktır. Bu limit sıfırdan farklıysa seri ıraksaktır. Başka hiçbir yönteme girmeye gerek yoktur.

Ama limitin sıfır olması yakınsaklık anlamına gelmez. O zaman testler uygulanır. Hoca harmonik seriyi örnek verdi: $\lim\frac1n=0$'dır, ama $\sum\frac1n$ ıraksaktır.

Bu noktada derse ara verildi.

## 8. Karşılaştırma Testine Dönüş: İki Örnek Daha

Aradan sonra hoca, integral testinin bir örneğini daha gösterdi: $\sum\frac{1}{n^2+1}$. Burada $f(x)=\frac{1}{x^2+1}$ alınır. Fonksiyon bu aralıkta sürekli, pozitif ve azalandır. Hoca azalanlığın gözle görüldüğünü, görülmezse türeve bakılacağını tekrar söyledi. Bu seri integral testiyle incelenebilir.

> **Ders sonrası not:** Altyazıda bu integralin değeri söylenmiyor. $\int_1^{\infty}\frac{dx}{x^2+1}=\arctan x\Big|_1^{\infty}=\frac\pi2-\frac\pi4=\frac\pi4$ olur. İntegral yakınsak olduğu için seri yakınsaktır. Bu değer serinin toplamı değildir (seri toplamı yaklaşık $1{,}077$'dir). Değerler python (sympy) ile doğrulandı.

Hoca sonra karşılaştırma testini kısaca tekrar etti ve iki örnek daha çözdü.

### 8.1 Örnek: Üstten $\frac{4}{n^2}$ ile Sınırlanan Seri

Hoca ekrandaki bir seriyi önce düzenledi, sonra parça parça karşılaştırdı. Altyazıdaki adımlar şunlardır:

- Bir parça, paydası bir fazla olduğu için $\frac{3}{n^2}$'den küçüktür.
- Diğer parça, payda $n^3+1$ olduğu için $\frac{1}{n^3}$'ten küçüktür.
- Toplam: $\frac{3}{n^2}+\frac{1}{n^3}\le\frac{3}{n^2}+\frac{1}{n^2}=\frac{4}{n^2}$.

$\sum\frac{4}{n^2}$ yakınsaktır, çünkü $p=2>1$'dir. Karşılaştırma testi gereği incelenen seri de yakınsaktır.

<!-- BELİRSİZ: Serinin tam ifadesi altyazıda okunmuyor ("üçen bölü, üçen en kare artı bir", "en küp artı bir"). Yalnız karşılaştırma adımları ve 4/n² üst sınırı net. -->

### 8.2 Örnek: $\sum\frac{1}{\ln n}$ (Sınav Sorusu)

Hoca bunun bir sınav sorusu olduğunu ve "hiç aklınıza gelmeyecek" bir soru olduğunu söyledi:

$$\sum_{n=2}^{\infty}\frac{1}{\ln n}.$$

İlk iş genel terime bakmaktır. $n\to\infty$ için $\ln n\to\infty$ ve $\frac{1}{\ln n}\to0$ olur. Limit sıfır olduğu için genel terim testi sonuç vermez. Başka teste geçilir.

Karşılaştırma yapılır. Hoca, çok soru çözerek şu eşitsizliğin akla geleceğini söyledi: Her $n\ge2$ için

$$\ln n<n.$$

Ters çevrilince eşitsizlik yön değiştirir:

$$\frac{1}{\ln n}>\frac1n.$$

Harmonik seri ıraksak olduğu için, ondan büyük olan $\sum\frac{1}{\ln n}$ de ıraksaktır.

## 9. Limit Karşılaştırma Testi

### 9.1 Teorem

Hoca bu testi bir paraşüt benzetmesiyle tanıttı: Havadan düşüyorsunuz, A paraşütünü açtınız, açılmadı. B'yi açıyorsunuz. Testler de böyledir. Bazen biri yeter, bazen diğeri gerekir. Bu yüzden bütün teknikleri öğrenmek gerekir.

**Teorem (Limit karşılaştırma testi)**

- $\sum a_n$ ve $\sum b_n$ pozitif terimli iki seri olsun.
- $L=\displaystyle\lim_{n\to\infty}\frac{a_n}{b_n}$ olsun.
- $0<L<\infty$ ise iki seri aynı karakterdedir.
- $L=0$ ve $\sum b_n$ yakınsak ise $\sum a_n$ yakınsaktır.
- $L=\infty$ ve $\sum b_n$ ıraksak ise $\sum a_n$ ıraksaktır.

Hoca işin özünü şöyle anlattı: İncelenmesi istenen $\sum a_n$'dir. Ona benzeyen ve karakterini bildiğimiz bir $b_n$ bulunur. Oranın limiti alınır. Sıfırdan ve sonsuzdan farklı bir $L$ çıkarsa, $a_n$'nin karakteri $b_n$'ninkiyle aynıdır.

### 9.2 Örnek: $\sum\frac{1}{n+1}$

$b_n=\frac1n$ seçilir:

$$\lim_{n\to\infty}\frac{1/(n+1)}{1/n}=\lim_{n\to\infty}\frac{n}{n+1}=1.$$

$L=1$ sıfırdan ve sonsuzdan farklıdır. $\sum\frac1n$ ıraksak olduğu için $\sum\frac{1}{n+1}$ de ıraksaktır.

Hoca, payda $n^2$ türünden olsaydı $\frac{1}{n^2}$ ile karşılaştırılacağını ve serinin yakınsak çıkacağını söyledi. Hocaya göre bu yol, mukayese testinden daha kolaydır.

<!-- BELİRSİZ: 01:09:03 civarında hocanın "en kare olsaydı" dediği serinin tam paydası altyazıda net değil. -->

### 9.3 Örnek: $\sum\frac{1}{1+\sqrt n}$

Seriye en çok benzeyen seri $b_n=\frac{1}{\sqrt n}$'dir:

$$\lim_{n\to\infty}\frac{1/(1+\sqrt n)}{1/\sqrt n}=\lim_{n\to\infty}\frac{\sqrt n}{1+\sqrt n}=1.$$

İki seri aynı karakterdedir. $\sum\frac{1}{\sqrt n}$'de $p=\frac12<1$ olduğu için seri ıraksaktır. Dolayısıyla $\sum\frac{1}{1+\sqrt n}$ de limit karşılaştırma testine göre ıraksaktır.

### 9.4 Örnek: $\sum\sin\frac{1}{n^3}$

Hoca bu sorunun bölümdeki hocaların hazırladığı "orijinal" sorulardan olduğunu söyledi:

$$\sum\sin\frac{1}{n^3}.$$

Hoca, bu testin dışındaki testlerin burada "kolay kolay cevap vermeyeceğini" söyledi. $n\to\infty$ için $\frac{1}{n^3}\to0$ ve $\sin0=0$ olur. Genel terim testi sonuç vermez.

$b_n=\frac{1}{n^3}$ ile karşılaştırılır:

$$\lim_{n\to\infty}\frac{\sin(1/n^3)}{1/n^3}=1.$$

İki seri aynı karakterdedir. $\sum\frac{1}{n^3}$ yakınsaktır ($p=3>1$). Dolayısıyla $\sum\sin\frac{1}{n^3}$ de yakınsaktır.

### 9.5 Örnek: $\sum\sin\frac1n$

Hoca sordu: Küp olmasaydı ne olurdu?

**Soru:** Bir öğrenci, dizilerde $\frac{\cos x}{x}$ türü bir limitin sıfır çıktığını hatırlattı ve küp olmasaydı limitin sıfıra gideceğini, bu yüzden iki serinin aynı karakterde olmayacağını önerdi. **Cevap:** Hoca "güzel" dedi ve başka fikir sordu. Sonra kendisi çözdü.

$$\sum\sin\frac1n.$$

Önce genel terime bakılır: $\sin\frac1n\to\sin0=0$. Genel terim testi sonuç vermez. $b_n=\frac1n$ ile karşılaştırılır:

$$\lim_{n\to\infty}\frac{\sin(1/n)}{1/n}=1.$$

Limit sıfırdan ve sonsuzdan farklıdır. İki seri aynı karakterdedir. $\sum\frac1n$ ıraksak olduğu için $\sum\sin\frac1n$ ıraksaktır.

> **Ders sonrası not:** Öğrencinin önerisindeki limit doğru değildir. Burada oran $\frac{\sin(1/n)}{1/n}$'dir ve $t=\frac1n\to0$ için $\frac{\sin t}{t}\to1$ olur. Sıfıra giden limit $x\to\infty$ için $\frac{\sin x}{x}$ ya da $\frac{\cos x}{x}$ limitidir, bu durumla karıştırılmamalıdır. Hoca da hesapta limiti $1$ buldu.

Hoca iki örneği karşılaştırdı: Sinüsün içinde küp varken seri yakınsak, küp kalkınca ıraksak oldu. Hoca bu inceliklerin anlaşılmasını istedi. Anlaşılmayan yer olursa başka bir soru çözebileceklerini söyledi.

### 9.6 Örnek: Rasyonel Seri, Dereceler Farkı 1

Hoca ekrandaki bir soruda payın derecesinin $1$, paydanın derecesinin $2$ olduğunu söyledi. Böyle bir seri $\frac1n$ ile karşılaştırılır. Çünkü dereceler farkı $1$'dir ve oranın limiti sonlu, sıfırdan farklı bir değer çıkar. $\sum\frac1n$ ıraksak olduğu için seri ıraksaktır.

<!-- BELİRSİZ: 01:15:44'teki serinin tam ifadesi altyazıda yok; yalnız pay ve paydanın dereceleri söyleniyor. -->

### 9.7 Örnek: $\sum\frac{n}{n^5+2}$

Payın derecesi $1$, paydanın derecesi $5$'tir. Aradaki fark $4$'tür. Bu yüzden $b_n=\frac{1}{n^4}$ seçilir:

$$\lim_{n\to\infty}\frac{n/(n^5+2)}{1/n^4}=\lim_{n\to\infty}\frac{n^5}{n^5+2}=1.$$

Hoca limitin "tesadüfen" $1$ çıktığını söyledi. $\sum\frac{1}{n^4}$'te $p=4>1$ olduğu için seri yakınsaktır. Dolayısıyla $\sum\frac{n}{n^5+2}$ de yakınsaktır.

Hoca bir sonraki ekrandaki sorunun da sınav sorusu olduğunu söyledi. Bu sorunun çözümü altyazıda yok.

<!-- BELİRSİZ: 01:17:23-01:18:27 arasında altyazı kesik; bu sınav sorusunun ifadesi ve çözümü alınamadı. -->

## 10. Oran Testi

### 10.1 Teorem

Hoca oran testinin (ratio test) bir önceki derste de söylendiğini hatırlattı.

**Teorem (Oran testi, D'Alembert)**

- $L=\displaystyle\lim_{n\to\infty}\frac{a_{n+1}}{a_n}$ olsun.
- $L<1$ ise seri yakınsaktır.
- $L>1$ ise seri ıraksaktır.
- $L=1$ ise test cevap vermez. Başka bir teste ("başka bir kapıya") yönelinir.

> **Hocanın vurgusu:** Bu test özellikle faktöriyel ve kuvvet içeren sorularda kıymetlidir. Diğer testlerle de çözülebilen sorular olabilir.

### 10.2 Örnek: $\sum\frac{99^n}{n!}$

$a_n$'de $n$ yerine $n+1$ yazılır ve $a_n$'ye bölünür:

$$\frac{a_{n+1}}{a_n}=\frac{99^{n+1}}{(n+1)!}\cdot\frac{n!}{99^n}=\frac{99}{n+1}.$$

$n\to\infty$ için bu oran $0$'a gider. $0<1$ olduğu için seri oran testine göre yakınsaktır.

### 10.3 Örnek: $\sum\frac{2^n}{n}$

$$\frac{a_{n+1}}{a_n}=\frac{2^{n+1}}{n+1}\cdot\frac{n}{2^n}=\frac{2n}{n+1}\to2.$$

$2>1$ olduğu için seri ıraksaktır.

> **Ders sonrası not:** Altyazıda hocanın sonucu "küçük olduğu için ıraksak" diye söylediği duyuluyor. Doğrusu: oran $2$'ye gider ve $2>1$ olduğu için seri ıraksaktır. Python (sympy) ile oranın limiti $2$ bulundu.

### 10.4 Örnek: $\sum\frac{n^n}{n!}$

Hoca bu soruyu herkesin kendi yapmasını istedi, sonra sonucu söyledi.

$$\frac{a_{n+1}}{a_n}=\frac{(n+1)^{n+1}}{(n+1)!}\cdot\frac{n!}{n^n}=\frac{(n+1)^{n}}{n^n}=\left(1+\frac1n\right)^n\to e \quad \text{(ara adım eklendi)}.$$

Hoca da sonucu "$e$ çıkıyor" diye verdi. $e>1$ olduğu için seri oran testine göre ıraksaktır.

## 11. Kök Testi

### 11.1 Teorem

**Teorem (Kök testi)**

- $\sum a_n$ terimleri negatif olmayan bir seri olsun.
- $L=\displaystyle\lim_{n\to\infty}\sqrt[n]{a_n}$ olsun.
- $L<1$ ise seri yakınsaktır.
- $L>1$ ise seri ıraksaktır.
- $L=1$ ise test sonuç vermez.

Hoca bu testin genelde $n$-inci kuvvet içeren serilerde kullanıldığını söyledi.

### 11.2 Örnek: $\sum\frac{1}{(\ln k)^k}$

Genel terim $k$-inci kuvvettir. $k$-inci kök alınınca kuvvetten kurtulunur:

$$\sqrt[k]{a_k}=\frac{1}{\ln k}\to0.$$

$0<1$ olduğu için seri kök testine göre yakınsaktır.

### 11.3 Örnek: $\sum\frac{2^{n+1}}{n^n}$

$n$-inci kök alınır:

$$\sqrt[n]{a_n}=\frac{2^{(n+1)/n}}{n}.$$

$n\to\infty$ için $\frac{n+1}{n}\to1$ olduğundan pay $2$'ye gider. Payda sonsuza gider. Limit $0$'dır. $0<1$ olduğu için seri kök testine göre yakınsaktır.

### 11.4 Örnek: $\sum\frac{2^n+5}{3^n}$

Hoca bu serinin de kuvvetler içerdiği için kök testiyle yapılabileceğini söyledi ve "yaptık, çıktı" dedi. Sonucu altyazıda söylenmiyor.

> **Ders sonrası not:** Altyazıda bu örneğin sonucu yok. Kök testinde $\sqrt[n]{\frac{2^n+5}{3^n}}\to\frac23<1$ olur, yani seri yakınsaktır. Seri $\sum\left(\frac23\right)^n+5\sum\left(\frac13\right)^n$ biçiminde iki geometrik seriye de ayrılabilir. $n=1$'den başlarsa toplam $2+\frac52=\frac92$'dir. Serinin başlangıç indisi altyazıda net olmadığı için toplam büyük olasılıkla bu değerdir. Değerler python (sympy) ile doğrulandı.

**Soru (hocanın kendi sorduğu):** Bu soru yalnız bu yöntemle mi çözülür? **Cevap:** Hayır. Bazı sorular iki yöntemle de çözülebilir. Ama bazı sorular yalnız bir yöntemle çözülür, o yöntemi bilmek gerekir. Bu yüzden bütün teknikleri öğrenmek şarttır.

Hoca son olarak ekrandaki bir soruyu ("$200$'ler en bölü en kare" diye duyuluyor) alıştırma olarak bıraktı. İşlem yapa yapa işlem hatalarının azalacağını ve işlemlerin kavranacağını söyledi.

<!-- BELİRSİZ: 01:24:03'teki alıştırmanın ifadesi altyazıda "200'ler en bölü en kare" diye geçiyor; büyük olasılıkla 200^n / n^2. Çözümü Örnek Sorular bölümünde bu varsayımla verildi. -->

## 12. Genel Terim Testine Son Bir Örnek

Hoca dersin sonunda genel terim testine döndü. Genel terim sıfırdan farklıysa seri kesinlikle ıraksaktır. Sıfırsa iki durum olabilir ve başka testlere bakılır.

Ekrandaki soru şuydu:

$$\sum\left(1-\frac1n\right)^n.$$

Seride $n$-inci kuvvet olduğu için kök testi akla gelir. Ama kök testi burada cevap vermez:

$$\sqrt[n]{a_n}=1-\frac1n\to1.$$

$L=1$ olduğu için test sonuç vermez ve "başka bir kapıya" gidilir. Hoca genel terimin limitine doğrudan baktı:

$$\lim_{n\to\infty}\left(1-\frac1n\right)^n=e^{-1}=\frac1e.$$

$\frac1e\ne0$ olduğu için seri ıraksaktır.

## Örnek Sorular

Bu derste video karesi yoktur. Aşağıdaki sorular, derste çözülen ya da sözlü olarak sorulan sorulardır. Saat damgaları altyazıdan alınmıştır.

**Soru 1** (derste sözlü, 00:05:17): $\displaystyle\sum_{n=1}^{\infty}\frac{4}{n^2+4n+3}$ serisinin toplamını bulunuz.

- Çözüm (derste verildi): $\frac{4}{(n+1)(n+3)}=\frac{2}{n+1}-\frac{2}{n+3}$. Teleskopik kısmi toplam $S_n=2\left(\frac12+\frac13-\frac{1}{n+2}-\frac{1}{n+3}\right)\to\frac53$. Toplam $\frac53$.

**Soru 2** (derste sözlü, 00:11:02): $\displaystyle\sum_{n=2}^{\infty}\ln\frac{n-1}{n}$ serisinin toplamını bulunuz.

- Çözüm (derste verildi): $S_n=\ln\frac1n\to-\infty$. Seri ıraksaktır, toplam yoktur.

**Soru 3** (derste sözlü, 00:16:38): $\displaystyle\sum_{n=1}^{\infty}\frac{3^{n-1}-1}{6^{n-1}}$ serisinin toplamını bulunuz.

- Çözüm (derste kısmen verildi): $\sum\left(\frac12\right)^{n-1}-\sum\left(\frac16\right)^{n-1}=2-\frac65=\frac45$.

**Soru 4** (derste sözlü, 00:18:18): $\frac19,\frac2{12},\frac4{15},\frac8{18},\dots$ dizisinin genel terimi nedir?

- Çözüm (derste verildi): $a_n=\dfrac{2^{n-1}}{3(n+2)}$.

**Soru 5** (derste sözlü, 00:29:02): $\displaystyle\sum_{n=1}^{\infty}\frac{1}{n^p}$ serisinin yakınsaklığını inceleyiniz.

- Çözüm (derste verildi): İntegral testiyle $p>1$ için yakınsak, $p\le1$ için ıraksak.

**Soru 6** (derste sözlü, 00:34:45): $\sum\frac{1}{\sqrt n}$ yakınsak mıdır?

- Çözüm (derste verildi): $p=\frac12<1$, ıraksak.

**Soru 7** (derste sözlü, 00:39:46): $\displaystyle\sum_{n=2}^{\infty}\frac{1}{n-1}$ serisi yakınsak mıdır?

- Çözüm (derste verildi): $\frac{1}{n-1}>\frac1n$ ve harmonik seri ıraksak olduğundan seri ıraksaktır.

**Soru 8** (derste sözlü, 00:43:29): $\displaystyle\sum_{n=2}^{\infty}\frac{1}{n^2-2}$ serisinin karakterini belirleyiniz.

- Çözüm (derste verildi): $\frac{1}{n^2-2}\le\frac{2}{n^2}$ ve $\sum\frac{2}{n^2}$ yakınsak olduğundan seri yakınsaktır.

**Soru 9** (derste sözlü, 00:48:23, geçmiş sınav sorusu): $\sum\frac{n+2}{n+5}$ serisi yakınsak mıdır?

- Çözüm (derste verildi): $\lim\frac{n+2}{n+5}=1\ne0$, seri ıraksaktır.

**Soru 10** (derste sözlü, 01:04:43, geçmiş sınav sorusu): $\displaystyle\sum_{n=2}^{\infty}\frac{1}{\ln n}$ serisinin karakterini inceleyiniz.

- Çözüm (derste verildi): $\ln n<n$ olduğundan $\frac{1}{\ln n}>\frac1n$. Seri ıraksaktır.

**Soru 11** (derste sözlü, 01:09:29): $\sum\frac{1}{1+\sqrt n}$ serisinin karakteri nedir?

- Çözüm (derste verildi): $b_n=\frac1{\sqrt n}$ ile $L=1$. Seri ıraksaktır.

**Soru 12** (derste sözlü, 01:10:33): $\sum\sin\frac{1}{n^3}$ serisinin karakterini belirleyiniz.

- Çözüm (derste verildi): $b_n=\frac1{n^3}$ ile $L=1$. Seri yakınsaktır.

**Soru 13** (derste sözlü, 01:11:24): Küp olmasaydı, yani $\sum\sin\frac1n$ serisi nasıl olurdu?

- Çözüm (derste verildi): $b_n=\frac1n$ ile $L=1$. Seri ıraksaktır.

**Soru 14** (derste sözlü, 01:16:26): $\sum\frac{n}{n^5+2}$ serisinin karakteri nedir?

- Çözüm (derste verildi): $b_n=\frac1{n^4}$ ile $L=1$. Seri yakınsaktır.

**Soru 15** (derste sözlü, 01:18:52): $\sum\frac{99^n}{n!}$ serisinin karakteri nedir?

- Çözüm (derste verildi): Oran $\frac{99}{n+1}\to0<1$. Seri yakınsaktır.

**Soru 16** (derste sözlü, 01:19:53): $\sum\frac{2^n}{n}$ serisinin karakteri nedir?

- Çözüm (derste verildi): Oran $\frac{2n}{n+1}\to2>1$. Seri ıraksaktır.

**Soru 17** (derste sözlü, 01:20:26): $\displaystyle\sum_{n=1}^{\infty}\frac{n^n}{n!}$ serisinin karakterini bulunuz.

- Çözüm (derste verildi): Oran $\left(1+\frac1n\right)^n\to e>1$. Seri ıraksaktır.

**Soru 18** (derste sözlü, 01:21:44): $\sum\frac{1}{(\ln k)^k}$ serisinin karakteri nedir?

- Çözüm (derste verildi): $\sqrt[k]{a_k}=\frac1{\ln k}\to0<1$. Seri yakınsaktır.

**Soru 19** (derste sözlü, 01:22:23): $\sum\frac{2^{n+1}}{n^n}$ serisinin karakteri nedir?

- Çözüm (derste verildi): $\sqrt[n]{a_n}=\frac{2^{(n+1)/n}}{n}\to0<1$. Seri yakınsaktır.

**Soru 20** (derste sözlü, 01:23:22): $\sum\frac{2^n+5}{3^n}$ serisinin karakteri nedir?

> **Çözüm (derste verilmedi):** $\sqrt[n]{\frac{2^n+5}{3^n}}\to\frac23<1$. Seri kök testine göre yakınsaktır. $n=1$'den başlarsa toplamı $\frac92$'dir (sympy ile doğrulandı).

**Soru 21** (derste sözlü, 01:24:03, alıştırma): "$200$'ler en bölü en kare" serisinin karakterini inceleyiniz.

<!-- BELİRSİZ: Serinin ifadesi altyazıdan tam çıkmıyor; büyük olasılıkla 200^n / n^2. -->

> **Çözüm (derste verilmedi):** İfade $\sum\frac{200^n}{n^2}$ ise oran testi uygulanır: $\frac{a_{n+1}}{a_n}=200\left(\frac{n}{n+1}\right)^2\to200>1$. Seri ıraksaktır. Genel terim de sonsuza gittiği için genel terim testi de aynı sonucu verir. Limit sympy ile doğrulandı.

**Soru 22** (derste sözlü, 01:25:08): $\sum\left(1-\frac1n\right)^n$ serisinin karakteri nedir?

- Çözüm (derste verildi): Kök testi $L=1$ verir, sonuç yoktur. Genel terim $e^{-1}\ne0$'a gider. Seri ıraksaktır.

## Dersin Toparlaması

Bu derste önce seri toplamı soruları çözüldü. Teleskopik seride basit kesirlere ayırma ile terimlerin birbirini götürdüğü görüldü. Logaritmalı seride çarpım sadeleşti ve kısmi toplam eksi sonsuza gitti. Geometrik serilerin farkında $\frac{a}{1-r}$ formülü kullanıldı. Ayrıca verilen terimlerden genel terimi bulmanın örüntü yakalamaya dayandığı gösterildi.

Dersin büyük kısmı yakınsaklık testlerine ayrıldı. İntegral testiyle $p$-serisinin $p>1$ için yakınsak, $p\le1$ için ıraksak olduğu gösterildi. Karşılaştırma testinde eşitsizliğin yönünün ve gerekirse katsayı ile düzenlemenin önemi vurgulandı. Genel terim testi, her seride ilk bakılması gereken test olarak öne çıktı. Limit karşılaştırma testi, rasyonel ve sinüslü serilerde dereceler farkına göre bir $b_n$ seçmeye dayandı. Oran testi faktöriyel ve kuvvetlerde, kök testi $n$-inci kuvvetlerde kullanıldı. Hoca testleri birbirinin yedeği olan paraşütlere benzetti ve hepsinin öğrenilmesini istedi. Gelecek hafta kuvvet serileri, Taylor ve Maclaurin serileri ve serilerin uygulamaları işlenecek. Ondan sonraki hafta çok değişkenli fonksiyonlara geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
