# Ders 18 Genişletilmiş Notu: Yerine Koyma Yöntemi, Sonlu Toplamlar ve Riemann Toplamıyla Belirli İntegral

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Derse Giriş
- 2. Yerine Koyma Yönteminin Tekrarı
- 3. Yerine Koyma Örnekleri
- 4. Toplam Sembolü ve Sonlu Toplamlar
- 5. Sonlu Toplamlarla Alan Tahmini
- 6. Genel Bölüntü ve Üst Riemann Toplamı
- 7. Notasyonun Felsefesi: Çubuklarla Alan
- 8. Riemann Toplamı ve Belirli İntegralin Tanımı
- 9. Örnek: $[0,1]$ Üzerinde $f(x)=x^2$
- 10. Örnek: $[1,2]$ Üzerinde $f(x)=x^3$
- 11. Kapanış: Riemann Toplamının Yeri
- Örnek Sorular

## 1. Derse Giriş

Ders İngilizce anlatıldı, arada Türkçe açıklamalar yapıldı. Hoca tablete yazarak anlattı. Altyazıda yalnız sözlü kısım olduğu için formüller ve çözüm adımları hocanın sözlü anlatımından kuruldu.

Dersin ilk bölümünde bir önceki derste başlanan yerine koyma yöntemi (substitution method) tekrar edildi ve üç örnek çözüldü. Ardından belirli integrale (definite integration) geçildi. Hoca önce toplam sembolünü (sigma notation) ve sonlu toplamların (finite sums) özelliklerini anlattı. Sonra bir bölgenin alanını sonlu toplamlarla tahmin etme fikrinden üst ve alt Riemann toplamlarına (upper / lower Riemann sum), oradan da belirli integralin tanımına ulaştı. Ders iki tam örnekle bitti: $[0,1]$ üzerinde $x^2$ ve $[1,2]$ üzerinde $x^3$.

## 2. Yerine Koyma Yönteminin Tekrarı

Hoca yöntemin genel fikrini bileşke fonksiyonun (composite function) integrali üzerinden hatırlattı. İntegrand $f(u(x))\,u'(x)$ biçimindeyse integrasyon değişkeni $x$'tir. İç fonksiyona $u$ denir ve diferansiyel bağıntı yazılır:

$$u=u(x) \implies du=u'(x)\,dx.$$

Hocanın ifadesiyle diferansiyel almak türev almaya karşılık gelir. Bu dönüşüm yerine konunca integral, yeni değişken $u$ cinsinden daha basit bir integrale dönüşür:

$$\int f(u(x))\,u'(x)\,dx=\int f(u)\,du.$$

Sağ tarafta integrasyon değişkeni artık $u$'dur ve $f(u)$, yeni değişken cinsinden integrand fonksiyondur. Hoca bunun yöntemin arkasındaki felsefe olduğunu ve yöntemin diğer adının değişken değiştirme (change of variable) olduğunu söyledi.

<!-- BELİRSİZ: 00:03:19-00:03:49 arasında altyazı kopuk ("u'x'ı dx'"); diferansiyel bağıntının hangi biçimde yazıldığı tam okunmuyor. Yukarıdaki biçim sonraki cümlelerden kuruldu. -->

## 3. Yerine Koyma Örnekleri

### 3.1 Örnek 1: $\displaystyle\int \frac{dx}{1+4x^2}$

Hoca önce bilinen temel formülü hatırlattı:

$$\int \frac{du}{1+u^2}=\arctan u + C.$$

Bu "popüler" formüle göre integrandın hangi kısmının $u$ olması gerektiğini sordu. $4x^2=(2x)^2$ olduğundan uygun dönüşüm $u=2x$'tir.

- Dönüşüm: $u=2x$.
- Diferansiyel bağıntı: $du=2\,dx$, yani $dx=\dfrac{1}{2}\,du$.
- Yerine koyma:

$$\int \frac{dx}{1+4x^2}=\int \frac{\frac{1}{2}\,du}{1+u^2}=\frac{1}{2}\int\frac{du}{1+u^2}.$$

- Türevi $\dfrac{1}{1+u^2}$ olan fonksiyon $\arctan u$'dur: $\dfrac{1}{2}\arctan u + C$.
- Kontrol: $\dfrac{1}{2}\arctan u$'nun $u$'ya göre türevi $\dfrac{1}{2}\cdot\dfrac{1}{1+u^2}$'dir.
- Eski değişkene dönüş ($u=2x$):

$$\int \frac{dx}{1+4x^2}=\frac{1}{2}\arctan(2x)+C.$$

Hoca ardından durumu genelleştirdi: $\displaystyle\int\frac{dx}{1+a\,x^2}$ için sonucun $\dfrac{1}{\sqrt{a}}\arctan(\ldots)$ biçiminde olduğunu yazmaya başladı.

<!-- BELİRSİZ: 00:08:15-00:08:45 arasında genellemenin geri kalanı altyazıda yok. -->

> **Ders sonrası not:** Genellemenin tamamı altyazıda yarım kalıyor. Doğru formül ($a>0$ için) $\displaystyle\int\frac{dx}{1+a\,x^2}=\frac{1}{\sqrt{a}}\arctan(\sqrt{a}\,x)+C$'dir. Türev alınarak doğrulandı. $a=4$ için Örnek 1'in sonucu çıkar.

### 3.2 Örnek 2: $\displaystyle\int \frac{\ln x}{x\,(1+\ln^2 x)}\,dx$

Hoca yine integrandın hangi kısmının $u$ olması gerektiğini sordu. Bir öğrenci $1+\ln^2 x$'e $u$ denebileceğini söyledi. Hoca iki durumu bir dikey çizgiyle ayırarak karşılaştırdı:

- **Birinci durum:** $u=\ln x$, $du=\dfrac{1}{x}\,dx$.
- **İkinci durum:** $u=\ln^2 x$.

Birinci durumda problem $u$ cinsinden kolayca dönüşmüyor. Hocanın sözleriyle, dönüştürebilirsiniz ama ilkinden daha karmaşık bir ifade elde edersiniz. Bu yüzden hoca bunu tercih etmedi ve ikinci durumla devam etti.

- Dönüşüm: $u=\ln^2 x$.
- İki tarafın diferansiyeli: $du=2\ln x\cdot\dfrac{1}{x}\,dx$.
- Aranan ifade: $\dfrac{\ln x}{x}\,dx=\dfrac{1}{2}\,du$.
- Yerine koyma:

$$\int \frac{\ln x}{x\,(1+\ln^2 x)}\,dx=\int\frac{\frac{1}{2}\,du}{1+u}=\frac{1}{2}\ln|1+u|+C.$$

- Kontrol: $\dfrac{1}{2}\ln(1+u)$'nun $u$'ya göre türevi $\dfrac{1}{2}\cdot\dfrac{1}{1+u}$'dur.
- Eski değişkene dönüş ($u=\ln^2 x$):

$$\int \frac{\ln x}{x\,(1+\ln^2 x)}\,dx=\frac{1}{2}\ln\left(1+\ln^2 x\right)+C.$$

$1+\ln^2 x>0$ olduğu için mutlak değere gerek kalmaz (ara adım eklendi). Öğrencinin önerdiği $u=1+\ln^2 x$ seçimi de aynı diferansiyeli verir ($du=\frac{2\ln x}{x}dx$) ve doğrudan $\frac{1}{2}\ln|u|+C$ ile aynı sonuca ulaşır (ara adım eklendi).

### 3.3 Örnek 3: $\displaystyle\int \frac{dx}{x\,(1+4\ln^2 x)}$

Hoca türevi $\dfrac{1}{x(1+4\ln^2 x)}$ olan uygun bir fonksiyon aradıklarını söyledi. Bir öğrenci "arctan" diye cevap verdi.

- İlk dönüşüm: $u=\ln x$. İki tarafın diferansiyeli: $du=\dfrac{dx}{x}$.
- İntegralde $\dfrac{dx}{x}$ zaten var. Problem şuna dönüşür:

$$\int\frac{du}{1+4u^2}.$$

Burada Örnek 1'in formülü doğrudan kullanılabilir. Hoca formülü unuttuğumuzu varsaydı: "Genelde bu formülü kolayca unutabilirsiniz. Formül ezberlemenize gerek yok."

- İkinci dönüşüm: $a=2u$, $da=2\,du$, yani $du=\dfrac{1}{2}\,da$.
- Yerine koyma:

$$\int\frac{du}{1+4u^2}=\frac{1}{2}\int\frac{da}{1+a^2}=\frac{1}{2}\arctan a + C.$$

- Geri dönüş: $a=2u$, $u=\ln x$:

$$\int \frac{dx}{x\,(1+4\ln^2 x)}=\frac{1}{2}\arctan(2\ln x)+C.$$

Hoca bir an "arctangent u" dedi, sonra düzeltip doğru değişkenin $a$ olduğunu söyledi.

> **Hocanın vurgusu:** Formülleri ezberlemenize gerek yok. Uygun bir değişken değiştirmeyle her seferinde temel formüle indirebilirsiniz.

### 3.4 Yöntemin Müfredattaki Yeri

Hoca, yerine koyma yönteminin normalde bu haftanın konusu olmadığını, 11. ya da 12. haftanın konusu olduğunu söyledi. Yöntem temel ve önemli olduğu için, sonraki konular zor gelmesin diye önce bunu anlattı. Daha karmaşık integral teknikleri sonra gelecek.

## 4. Toplam Sembolü ve Sonlu Toplamlar

### 4.1 Toplam Sembolü

Hoca belirli integrale hazırlık olarak toplam sembolünü (sigma notation) anlattı. Bu sembol sonlu ya da sonsuz sayıda terimin toplamını göstermek için kullanılır. Elimizde $a_1, a_2, \dots$ gibi sıralı terimler olsun. Bunların toplamı

$$\sum_{k=1}^{n} a_k = a_1+a_2+\dots+a_n$$

diye yazılır. $k=1$ için $a_1$, $k=2$ için $a_2$, $k=3$ için $a_3$ gelir ve son terim $k=n$ için $a_n$'dir.

**Tanım (toplam sembolünün parçaları):**

- $k$: toplam değişkeni (summation variable). Kesikli (discrete) bir değişkendir. $1,2,3,\dots$ gibi yalnız tam sayı değerleri alır.
- $a_k$: toplamın genel terimi (general term).
- $n$: son terimin indisi.

Hoca bu notasyonun, özellikle toplam değişkeni $k$'nın çok önemli olduğunu vurguladı.

**Örnek:**

$$\sum_{k=1}^{n}\frac{1}{k}=1+\frac{1}{2}+\frac{1}{3}+\dots+\frac{1}{n}.$$

Bu bir sonlu toplamdır (finite sum), yani sonlu sayıda terimin toplamıdır.

### 4.2 Sonlu Toplamların Özellikleri

**Özellik 1 (toplama ve çıkarmaya dağılma):**

$$\sum_{k=1}^{n}(a_k\pm b_k)=\sum_{k=1}^{n}a_k\pm\sum_{k=1}^{n}b_k.$$

**Özellik 2 (sabit çarpan):**

$$\sum_{k=1}^{n}c\,a_k=c\sum_{k=1}^{n}a_k.$$

Gerçekte sol taraf $c\,a_1+c\,a_2+\dots+c\,a_n$'dir. Ortak çarpan $c$ dışarı alınır. Burada $c$, toplam değişkenine göre sabittir (constant with respect to the summation variable). İleride $n$ gibi ifadeler de $k$'ya göre sabit olduğu için toplamın dışına alınacak.

**Soru:** Yazdığınız "w.r.t." ne demek? **Cevap:** "With respect to" kısaltmasıdır, yani "-e göre".

### 4.3 Önemli Toplam Formülleri

Hoca bu formüllerin sonlu toplamları hesaplamak için çok önemli olduğunu söyledi. İspatlarının kolay olduğunu, birinciyi herkesin bildiğini belirtti.

$$\sum_{k=1}^{n}k=1+2+\dots+n=\frac{n(n+1)}{2}$$

$$\sum_{k=1}^{n}k^2=1^2+2^2+\dots+n^2=\frac{n(n+1)(2n+1)}{6}$$

$$\sum_{k=1}^{n}k^3=1^3+2^3+\dots+n^3=\left(\frac{n(n+1)}{2}\right)^2$$

$$\sum_{k=1}^{n}c=n\,c$$

Son formül derste $[1,2]$ örneğinde "$n$ tane $c$'nin toplamı" olarak kullanıldı. Hoca ezberinin kuvvetli olmadığını, formülleri ispatlaması gerektiğini, ama böyle hatırladığını söyledi. Formüller sympy ile doğrulandı.

> **Ders sonrası not:** 00:23:48'de hoca kareler toplamını önce $n(n+1)(n+2)$ diye yazdı, sonra "burası $2n+1$ olacak" diye düzeltti. Doğrusu $\frac{n(n+1)(2n+1)}{6}$'dır. 00:25:05'te küpler toplamı için "küp" dedi, sonra "kare" diye düzeltti. Doğrusu $\left(\frac{n(n+1)}{2}\right)^2$'dir.

> **Ek bilgi (derste anlatılmadı):** $\sum k$ formülünün klasik ispatı, toplamı bir de ters sırada yazıp iki satırı alt alta toplamaktır. Her sütun $n+1$ eder ve $n$ sütun vardır. Böylece toplamın iki katı $n(n+1)$ olur. Kareler ve küpler toplamı ise genellikle tümevarımla (induction) ispatlanır.

## 5. Sonlu Toplamlarla Alan Tahmini

### 5.1 Çiftçi Benzetmesi

Hoca konuya bir tarihsel benzetmeyle girdi. Bir zamanlar çiftçilerin çoğu tarlalarının alanını sonlu toplamlarla tahmin ederdi. Bu yöntem, matematik bilmeyen çiftçilerce de bilinirdi. Çiftçinin yalnız dikdörtgenin alanını bilmesi yeterliydi. Daha sonra matematikçiler ve fizikçiler bu yöntemi matematiksel olarak ifade ettiler ve adı belirli integral oldu.

> **Hocanın vurgusu:** Bu aslında bilinen bir şey. Sadece matematiksel olarak ifade edilmesi belirli integrali doğurmuş. Belirli integralin mantığı budur.

### 5.2 Fikir

$y=f(x)$ grafiğinin altında ve $[a,b]$ aralığının üstünde kalan bir bölge olsun. Bu bölgenin alanını nasıl tahmin ederiz? Bir öğrencinin cevabıyla: parçalara bölerek. Hoca bunu şöyle ifade etti: bölge yeterince küçük dikdörtgensel bölgelere ayrılır (partition). Ancak hesaplayabilmek için bu alt bölgelerin sayısı sonlu olmalıdır, yoksa hesaplayamayız.

Dikdörtgenlerin grafikten taşan ya da eksik kalan kısımları hatadır (error). Her dikdörtgenin alanı hesaplanıp toplanınca yaklaşık bir alan bulunur. Gerçek alan (actual area), dikdörtgen alanlarının toplamına yaklaşık eşittir.

### 5.3 Örnek: $y=x^2$, $[0,1]$, iki ve üç parça

Hoca $y=x^2$ grafiğinin $[0,1]$ üzerindeki kısmını çizdi. $A$ gerçek alan olsun.

**İki parça:** Aralık $\frac{1}{2}$ noktasından ikiye bölündü. Her dikdörtgenin tabanı $\frac{1}{2}$'dir. Birinci dikdörtgenin yüksekliği $f\left(\frac{1}{2}\right)$'dir.

$$A\approx\frac{1}{2}\,f\left(\frac{1}{2}\right)+\frac{1}{2}\,f(1).$$

<!-- BELİRSİZ: 00:33:51'de ikinci terim "one over two times f of five" diye geçiyor. Üç parçalı örnekle tutarlı olarak f(1) alındı. -->

**Üç parça:** Daha hassas bir tahmin için alt bölge sayısı artırılır. $[0,1]$ aralığı $\frac{1}{3}$ ve $\frac{2}{3}$ noktalarıyla üç alt aralığa bölünür. Her dikdörtgenin taban uzunluğu $\frac{1}{3}$'tür. Yükseklikler $f\left(\frac{1}{3}\right)$, $f\left(\frac{2}{3}\right)$ ve son dikdörtgen için $f(1)$'dir.

$$A\approx\frac{1}{3}\,f\left(\frac{1}{3}\right)+\frac{1}{3}\,f\left(\frac{2}{3}\right)+\frac{1}{3}\,f(1).$$

Hoca, bu durumda hata miktarının azaldığını gösterdi. Parça sayısı arttıkça daha hassas sonuç elde edilir.

> **Ders sonrası not:** Hoca bu tahminlerin sayısal değerini hesaplamadı. $f(x)=x^2$ için iki parçalı tahmin $\frac{1}{2}\cdot\frac{1}{4}+\frac{1}{2}\cdot 1=\frac{5}{8}$, üç parçalı tahmin $\frac{1}{3}\left(\frac{1}{9}+\frac{4}{9}+1\right)=\frac{14}{27}$'dir. İkisi de ileride bulunacak gerçek değer $\frac{1}{3}$'ten büyüktür ve parça sayısı artınca ona yaklaşır. Hesap python ile doğrulandı. Bu tahminler sağ uç noktaları kullanır, yani üst toplamdır; kısa nottaki "orta noktalarla" ifadesi bu anlamda yanıltıcıdır.

### 5.4 Limite Geçiş

Hoca bu gözlemin çok önemli olduğunu söyledi: "Parça sayısını artırdıkça daha hassas sonuç elde ederiz" önermesi, limit kavramını kullanabileceğimizi gösterir. Parça sayısını istediğimiz kadar artırabiliriz.

## 6. Genel Bölüntü ve Üst Riemann Toplamı

### 6.1 Ön Koşul: Süreklilik

Genel durumda bir $[a,b]$ aralığı ve bir $y=f(x)$ fonksiyonu verilsin.

> **Hocanın vurgusu:** Süreklilik çok önemlidir. $f$ sürekli değilse bu integralden söz edemezsiniz. $f$'nin sürekli olması ön koşuldur (precondition).

<!-- BELİRSİZ: 00:38:01'de altyazı döngüye giriyor ("Yükümetli" tekrarı), 00:38:31-00:38:45 arası Türkçe kısım da kopuk. Bu kısım altyazıda anlaşılmıyor; aşağıdaki bölüntü sonraki cümlelerden kuruldu. -->

### 6.2 Eşit Bölüntü

$[a,b]$ aralığında $n+1$ nokta alınır:

$$a=x_0<x_1<x_2<\dots<x_n=b.$$

Bu noktalar aralığı $n$ alt aralığa (subinterval) böler. Her alt aralığın aynı uzunlukta olduğu varsayılır. Bu uzunluk $\Delta x$ ise $n$ tane $\Delta x$'in toplamı ana aralığın uzunluğunu verir:

$$\underbrace{\Delta x+\Delta x+\dots+\Delta x}_{n\text{ tane}}=n\,\Delta x=b-a \implies \Delta x=\frac{b-a}{n}.$$

Burada $n$, alt aralıkların (alt dikdörtgensel bölgelerin) sayısıdır.

Sonra her $x_k$ noktası $a$, $b$ ve $\Delta x$ cinsinden yazılır:

$$x_0=a,\quad x_1=a+\Delta x,\quad x_2=a+2\Delta x,\quad\dots,\quad x_k=a+k\,\Delta x,\qquad \Delta x=\frac{b-a}{n}.$$

Hoca bunun çok önemli olduğunu, ama ezberlemeye gerek olmadığını, kolayca elde edilebileceğini söyledi.

### 6.3 Üst Riemann Toplamı

Hoca, her dikdörtgendeki hatanın daima $y=f(x)$ grafiğinin **üstünde** kaldığı dikdörtgenleri ele aldı. Çizimdeki artan grafik için birinci dikdörtgenin yüksekliği $f(x_1)$, ikincisinin $f(x_2)$, sonuncusunun $f(x_n)$'dir. Gerçek alan şu toplama yaklaşır:

$$A\approx f(x_1)\,\Delta x+f(x_2)\,\Delta x+\dots+f(x_n)\,\Delta x=\sum_{k=1}^{n}f(x_k)\,\Delta x.$$

Bu sonlu toplama **üst Riemann toplamı** (upper Riemann sum) denir. "Üst" adı, her hatanın daima grafiğin üstünde olmasından gelir. Hoca bunu Türkçe de açıkladı: bölgeyi dikdörtgenlere parçaladığınızda her durumda meydana gelen hata grafiğin üstündeyse, o sonlu toplama üst Riemann toplamı adı verilir. Alt Riemann toplamı da benzer şekilde tanımlanır. Hoca bu toplamı $A_n$ ile gösterdi: $A\approx A_n$.

<!-- BELİRSİZ: 00:45:20-00:45:55 arasında hocanın üst ve alt toplam için hangi sembolü seçtiği altyazıdan okunmuyor. Bu notta üst toplam için $U_n$, alt toplam için $L_n$ kullanıldı. -->

> **Ders sonrası not:** Üst toplamın $f(x_k)$ (sağ uç) ile, alt toplamın $f(x_{k-1})$ (sol uç) ile kurulması, derste çizilen **artan** fonksiyonlar için geçerlidir. Azalan bir fonksiyonda roller yer değiştirir. Genel tanımda üst toplam her alt aralıktaki en büyük değerle, alt toplam en küçük değerle kurulur.

### 6.4 Gerçek Alan Bir Limittir

Alt aralık sayısı artırılırsa yaklaşıklık bağıntısından gerçek alan elde edilir:

$$A=\lim_{n\to\infty}A_n.$$

Bu, "parça sayısı arttıkça sonuç daha hassas olur" önermesinin sonucudur. Ancak limit kavramı $f$'nin sürekli olması koşuluyla kullanılabilir. Hoca, $f$ sürekli olduğunda bu limitin var olduğunun ispatlanabileceğini söyledi.

**Soru:** Limit kısmında toplam sembolü nerede? **Cevap:** $A_n$ toplam sembolünü içerir. Bu yüzden limit ifadesinde ayrıca toplam sembolü yazmaya gerek yok.

## 7. Notasyonun Felsefesi: Çubuklarla Alan

### 7.1 Neden Yeni Bir Notasyon?

Hoca $\displaystyle\lim_{n\to\infty}\sum_{k=1}^{n}f(x_k)\,\Delta x$ notasyonunun bu mantığı göstermek için "pek iyi olmadığını" söyledi ve yeni notasyonun arkasındaki felsefeyi anlattı.

- $\Delta x=\dfrac{b-a}{n}$ her alt aralığın uzunluğudur. $n\to\infty$ iken $\Delta x$, $dx$'e dönüşür.
- $x_k=a+k\,\dfrac{b-a}{n}$'dir. $n\to\infty$ iken $x_k$, $a$ ile $b$ arasındaki herhangi bir $x$'e dönüşür: $a\le x\le b$.
- Böylece $f(x_k)$, $f(x)$ olur. $a$ ve $b$ de $x$ için alt ve üst sınırdır.

Bu yüzden şu notasyon tercih edilir:

$$\lim_{n\to\infty}\sum_{k=1}^{n}f(x_k)\,\Delta x=\int_a^b f(x)\,dx.$$

Hoca bu notasyonun daha iyi olduğunu söyledi.

<!-- BELİRSİZ: 00:50:36-00:51:16 arasındaki Türkçe kısım kopuk, 00:51:33'te altyazı döngüye giriyor ("bu seferin bölgesi" tekrarı). Bu kısım altyazıda anlaşılmıyor. -->

### 7.2 Bir Doğru Parçasının Alanı Var mı?

Hoca bir doğru parçasına bakıp şu soruyu sordu: Bu doğru parçasının bir alanı var mı? Öğrencilerden "evet" ve "göreceli" cevapları geldi. Hoca kesin bir cevabın olmadığını, bunun yalnız bir varsayım olduğunu söyledi. Noktanın da kesin bir tanımı yoktur. Doğru parçası sonsuz sayıda noktanın bir araya gelmesidir.

Yine de $x$ noktasındaki doğru parçasının bir alanı olduğunu varsayalım. Bu parçanın yüksekliği $f(x)$'tir. Parça yeterince incedir. Üzerine yakınlaştırılırsa (zoom) kalınlığı $\Delta x$ olan, yani çok küçük bir $dx$ kalınlığında bir şerit görülür. Bu tek parçanın alanına $dA$ denir:

$$dA=f(x)\,dx.$$

Burada $f(x)>0$ varsayılır. $dA$, yüksekliği $f(x)$ ve kalınlığı $dx$ olan tek bir doğru parçasının (çubuğun) alanıdır.

### 7.3 Parçalardan Bütüne

Bu yalnız bir parçadır. Başka bir doğru parçası da alınabilir. Sonsuz sayıda doğru parçası vardır ve sürekli olarak yan yana çizilebilirler. Bu doğru parçaları "integre edilirse", yani bir araya toplanırsa bölge elde edilir:

$$\lim_{n\to\infty}\sum_{k=1}^{n}f(x_k)\,\Delta x=\int_a^b f(x)\,dx=\int_a^b dA=A.$$

Yani bu limit, yüksekliği $f(x)$ ve kalınlığı $dx$ olan doğru parçalarının $a$'dan $b$'ye integralinden başka bir şey değildir.

Hoca bunu belirsiz integralle (indefinite integration) ilişkilendirdi. Sınırları bir kenara bırakırsak, türevi 1 olan fonksiyonu arıyoruz: $\int dA=A$. Bu, ters türevle (antiderivative) aynı mantıktır. $dA$ tek bir parçadır, $A$ sonsuz sayıda küçük parçanın toplamıdır. Önceki dersteki $\int du=u$ felsefesiyle aynıdır: $du$ tek bir parçadır, bütün parçalar toplanınca $u$ elde edilir. Hoca belirli ve belirsiz integral arasındaki bu ilişkiden ileride bahsedeceklerini söyledi.

Bu noktada derse yaklaşık on dakikalık bir ara verildi (00:58:44 ile 01:10:26 arası kayıtta konuşma yok).

## 8. Riemann Toplamı ve Belirli İntegralin Tanımı

Aradan sonra hoca tanımı yazdı.

**Tanım (Riemann toplamı):**

- $[a,b]$ üzerinde sürekli $f$ ve $\Delta x=\dfrac{b-a}{n}$, $x_k=a+k\,\Delta x$ için

$$\sum_{k=1}^{n}f(x_k)\,\Delta x$$

sonlu toplamına **Riemann toplamı** (Riemann sum) denir.

- Sonlu bir toplamdır ve $n$'ye bağlıdır.
- Hoca toplamın $k=0$'dan $n-1$'e de yazılabileceğini, yani iki durum olduğunu belirtti (üst ve alt toplam).

**Tanım (belirli integral):**

$$\int_a^b f(x)\,dx=\lim_{n\to\infty}\sum_{k=1}^{n}f(x_k)\,\Delta x.$$

- Riemann toplamının limiti belirli integrali verir.
- Bu limit yüzünden belirli integral bir **sonsuz toplamdır** (infinite sum).
- $n$'den bağımsız, sabit bir değerdir.

**Soru:** Sonlu toplamdan söz ediyorduk; sonlu toplamdan söz ederken $n$'i nasıl sonsuza götürebiliriz? **Cevap:** Riemann toplamı sonludur. Limit alındıktan sonra elde edilen şey sonsuz toplamdır. Riemann toplamının limitini alırsanız belirli integrali elde edersiniz.

> **Hocanın vurgusu:** $\sum_{k=1}^{n} f(x_k)\,\Delta x$ toplamı Riemann toplamıdır, sonlu bir toplamdır ve $n$'ye bağlıdır. $n$'i sonsuza götürdüğünüzde $n$'den bağımsız bir limit değeri, sabit bir değer bulursunuz. Bu belirli integraldir. Sonsuz tane dikdörtgenin toplamı olduğu için o da aslında sonsuz toplamdır.

> **Ek bilgi (derste anlatılmadı):** Genel tanımda alt aralıkların eşit olması ve yüksekliğin uç noktadan alınması şart değildir. Her alt aralıktan keyfi bir $c_k$ noktası seçilerek $\sum f(c_k)\,\Delta x_k$ toplamı kurulur. En geniş alt aralığın uzunluğu sıfıra giderken bu toplamların limiti seçimden bağımsız olarak varsa $f$ integrallenebilir denir. Sürekli fonksiyonlar kapalı aralıkta her zaman integrallenebilirdir.

## 9. Örnek: $[0,1]$ Üzerinde $f(x)=x^2$

Hoca örneği üç şık halinde verdi. $f(x)=x^2$ olsun.

- a) $f$'nin $[0,1]$ üzerindeki üst Riemann toplamını hesaplayın.
- b) $f$'nin $[0,1]$ üzerindeki alt Riemann toplamını hesaplayın.
- c) $f$'nin $[0,1]$ üzerindeki belirli integralini hesaplayın.

### 9.1 a) Üst Riemann Toplamı

$y=x^2$ grafiği $[0,1]$ üzerinde çizildi. Üst toplam için hataların daima grafiğin üstünde kaldığı dikdörtgenler alınır. Bölüntü noktaları $x_0, x_1, \dots, x_n$'dir.

- Verilen: $a=0$, $b=1$, $\Delta x=\dfrac{1-0}{n}=\dfrac{1}{n}$.
- Dikdörtgenler: birincinin alanı $f(x_1)\,\dfrac{1}{n}$, ikincinin $f(x_2)\,\dfrac{1}{n}$, sonuncunun $f(x_n)\,\dfrac{1}{n}$.
- Toplam sembolüyle:

$$U_n=\sum_{k=1}^{n}f(x_k)\,\Delta x=\sum_{k=1}^{n}f(x_k)\,\frac{1}{n}.$$

- Noktalar: $x_k=0+k\cdot\dfrac{1}{n}=\dfrac{k}{n}$. $f(x_k)=x_k^2$ olduğundan:

$$U_n=\sum_{k=1}^{n}\left(\frac{k}{n}\right)^2\frac{1}{n}.$$

Hoca burada sordu: Bu toplamda hangisi toplam değişkenidir? Cevap: $k$. $n$, toplam değişkenine göre sabittir. Bu yüzden $\dfrac{1}{n^3}$ dışarı alınır:

$$U_n=\frac{1}{n^3}\sum_{k=1}^{n}k^2=\frac{1}{n^3}\left(1^2+2^2+\dots+n^2\right)=\frac{1}{n^3}\cdot\frac{n(n+1)(2n+1)}{6}.$$

Hoca formülü hatırlarken bir an tereddüt etti ("$2n+1$ bölü 6 idi galiba"). Öğrenciler formülün doğru olduğunu teyit etti. Sadeleştirilirse (ara adım eklendi):

$$U_n=\frac{(n+1)(2n+1)}{6n^2}.$$

Görüldüğü gibi üst Riemann toplamı $n$'ye, yani alt aralık (parça) sayısına bağlıdır. Hoca bunu böyle bırakabileceğinizi ya da düzenleyebileceğinizi söyledi.

### 9.2 b) Alt Riemann Toplamı

Grafik yeniden çizildi. Bu kez hataların grafiğin **altında** kaldığı dikdörtgenler alınır.

- Son dikdörtgenin yüksekliği $f(x_{n-1})$'dir. Hoca bunu son dikdörtgen üzerinde ayrıca gösterdi: hatanın daima grafiğin altında kalması için son dikdörtgenin yüksekliği $f(x_{n-1})$, tabanı $\dfrac{1}{n}$ olmalıdır.
- Dikdörtgenler: $f(x_0)\,\dfrac{1}{n}$, $f(x_1)\,\dfrac{1}{n}$, …, $f(x_{n-1})\,\dfrac{1}{n}$.
- Toplam sembolüyle:

$$L_n=\sum_{k=0}^{n-1}f(x_k)\,\Delta x,\qquad \Delta x=\frac{1-0}{n}=\frac{1}{n},\quad x_k=\frac{k}{n}.$$

- Yerine koyma:

$$L_n=\sum_{k=0}^{n-1}\left(\frac{k}{n}\right)^2\frac{1}{n}=\frac{1}{n^3}\sum_{k=0}^{n-1}k^2=\frac{1}{n^3}\left(0^2+1^2+2^2+\dots+(n-1)^2\right).$$

$0^2$ terimini yazmaya gerek yoktur. Son terim $(n-1)^2$ olduğundan kareler toplamı formülünde $n$ yerine $n-1$ yazılır. Hoca bunu Türkçe adım adım yaptı: $n$ gördüğümüz yere $n-1$ yazarsak $n+1$ yerine $n$ gelir; $2n+1$ yerine $2(n-1)+1=2n-1$ gelir. Böylece:

$$L_n=\frac{1}{n^3}\cdot\frac{(n-1)\,n\,(2n-1)}{6}=\frac{(n-1)(2n-1)}{6n^2}\ \text{(sadeleştirme eklendi)}.$$

### 9.3 c) Belirli İntegral

Hoca önce gerçek alanın iki toplam arasında kaldığını belirtti:

$$L_n\le A\le U_n.$$

Gerçek alan alt Riemann toplamından büyük veya eşit, üst Riemann toplamından küçük veya eşittir. Sonra sordu: Burada hangi teorem kullanılmalı? Cevap: sıkıştırma teoremi (sandwich theorem). $L_n$ ve $U_n$ aynı $L$ değerine giderse, aradaki $A$ da $L$'ye gitmek zorundadır. Bu limit belirli integralin kendisidir:

$$\int_0^1 x^2\,dx=\lim_{n\to\infty}L_n=\lim_{n\to\infty}U_n.$$

Hoca limiti alt toplam üzerinden hesapladı. Payın en yüksek dereceli terimi $2n^3$, paydanınki $6n^3$'tür; diğer terimler limitte önemsizdir:

$$\lim_{n\to\infty}\frac{(n-1)\,n\,(2n-1)}{6n^3}=\lim_{n\to\infty}\frac{2n^3+\dots}{6n^3}=\frac{2}{6}=\frac{1}{3}.$$

Üst toplamın limiti de aynıdır:

$$\lim_{n\to\infty}\frac{n(n+1)(2n+1)}{6n^3}=\lim_{n\to\infty}\frac{2n^3+\dots}{6n^3}=\frac{1}{3}.$$

Sonuç:

$$\int_0^1 x^2\,dx=\frac{1}{3}.$$

Sonuçlar sympy ile doğrulandı.

**Yorum:** Hocanın Türkçe ifadesiyle: yükseklikleri $x^2$, kalınlıkları $dx$ olan yeterince ince çubukları yan yana dizerseniz meydana gelen bölgenin alanı $\dfrac{1}{3}$'tür. Buna $0$'dan $1$'e $x^2\,dx$'in belirli integrali denir.

> **Hocanın vurgusu:** İntegral her zaman alan vermez. Burada alanı vermesinin sebebi, fonksiyonun verilen aralık üzerinde pozitif olmasıdır.

<!-- BELİRSİZ: 01:33:58'de altyazı döngüye giriyor ("bu şekilde" tekrarı). Hemen ardından gelen Türkçe cümleden yorum kurulabildi. -->

> **Ek bilgi (derste anlatılmadı):** Sıkıştırma teoremi (sandwich / squeeze theorem) şunu söyler: her $n$ için $a_n\le c_n\le b_n$ ve $\lim a_n=\lim b_n=L$ ise $\lim c_n=L$'dir. Burada $A$ sabit olduğu için teorem, $A$'nın tam olarak bu ortak limite eşit olduğunu verir.

### 9.4 Soru: Alt ve Üst Toplamın Limitleri Neden Aynı?

**Soru:** Sıkıştırma teoreminde alt ve üst toplamın limitinin $L$ olduğunu söyledik. İkisinin de $L$'ye eşit olduğunu nereden biliyoruz?

**Cevap:** Hoca bunun ispat gerektirdiğini söyledi ve sezgisini anlattı. Alt dikdörtgenlere "alt" denmesinin sebebi her hatanın grafiğin altında olmasıdır. Bölüntü sayısı artırıldıkça her dikdörtgenin hatası küçülür. Fonksiyon sürekli olduğu için hataların toplamı sıfıra gider. Hoca üst ve alt hataların toplamını yazdı. Bu fark, yani $U_n-L_n$, $n\to\infty$ iken sıfıra gider. Yazarken bir işareti düzeltti ("bu çıkarma olmalı").

<!-- BELİRSİZ: 01:36:13-01:38:49 arasında altyazı büyük ölçüde boş/kopuk. Hocanın tahtaya yazdığı hata ifadesinin tam biçimi okunmuyor. -->

> **Ders sonrası not:** Bu örnekte fark açıkça hesaplanabilir: $U_n-L_n=\frac{1}{n^3}\cdot n^2=\frac{1}{n}$ (sympy ile doğrulandı). Gerçekten de $n\to\infty$ iken sıfıra gider. Artan bir fonksiyon için genelde $U_n-L_n=\left(f(b)-f(a)\right)\Delta x$'tir.

Hoca bölümü Türkçe özetledi: Riemann toplamı deyince akla sonlu toplam gelmelidir. Alt ya da üst olsun, Riemann toplamı $n$'ye bağlıdır. Parçalanma sayısı sonsuza götürülürse gerçek alan, gerçek integral hatasız hesaplanır; hata sıfıra gider. Bu, yükseklikleri $f(x)$ ve kalınlıkları $dx$ olan sonsuz sayıda yeterince ince çubuğun alanlarının toplamıdır ($f(x)$ pozitifse).

## 10. Örnek: $[1,2]$ Üzerinde $f(x)=x^3$

Hoca bir örnek daha yaptı: $f(x)=x^3$ fonksiyonunun $[1,2]$ aralığı üzerindeki üst Riemann toplamını hesaplayın. Hoca bunun sonunda belirli integrali de buldu.

### 10.1 Üst Toplamın Kurulması

Bölüntü noktaları $x_0=1, x_1, x_2,\dots,x_n=2$'dir. Üst toplam için her durumda hatalar grafiğin üstündedir. Birinci dikdörtgenin yüksekliği $f(x_1)$, sonuncununki $f(x_n)$'dir:

$$A\approx f(x_1)\,\Delta x+\dots+f(x_n)\,\Delta x=\sum_{k=1}^{n}f(x_k)\,\Delta x.$$

- Alt aralık uzunluğu: $\Delta x=\dfrac{2-1}{n}=\dfrac{1}{n}$.
- Noktalar: $x_k=1+k\cdot\dfrac{1}{n}=\dfrac{n+k}{n}$.
- $f(x_k)=x_k^3$ olduğundan:

$$U_n=\sum_{k=1}^{n}\left(\frac{k+n}{n}\right)^3\frac{1}{n}.$$

$k$ toplam değişkenidir. $\dfrac{1}{n^4}$ dışarı alınır:

$$U_n=\frac{1}{n^4}\sum_{k=1}^{n}(k+n)^3.$$

### 10.2 Açılım ve Toplamın Dağıtılması

Küp açılır:

$$(k+n)^3=k^3+3k^2n+3kn^2+n^3.$$

Toplam sembolü dağıtılır. $3n$ ve $3n^2$, $k$'ya göre sabittir, dışarı alınır. Son terimde $n^3$, $k$'ya göre sabit olduğundan $n$ tane $n^3$ toplanır ($\sum c=n\,c$):

$$U_n=\frac{1}{n^4}\left[\sum_{k=1}^{n}k^3+3n\sum_{k=1}^{n}k^2+3n^2\sum_{k=1}^{n}k+n^3\sum_{k=1}^{n}1\right].$$

Her toplam $n$ cinsinden yazılır:

$$U_n=\frac{1}{n^4}\left[\left(\frac{n(n+1)}{2}\right)^2+3n\cdot\frac{n(n+1)(2n+1)}{6}+3n^2\cdot\frac{n(n+1)}{2}+n\cdot n^3\right].$$

Hoca ilk toplam için önce kareler formülünü yazdı, "hata yaptık" diyerek küpler formülüyle düzeltti.

### 10.3 Limit ve Sonuç

Hoca, limit alınacağı için tüm terimleri açmadığını, yalnız $n^4$'lü terimleri izlediğini söyledi. Her parçanın en yüksek dereceli terimi:

- $\left(\dfrac{n(n+1)}{2}\right)^2=\dfrac{n^4+\dots}{4}$,
- $3n\cdot\dfrac{n(n+1)(2n+1)}{6}=\dfrac{6n^4+\dots}{6}$,
- $3n^2\cdot\dfrac{n(n+1)}{2}=\dfrac{3n^4+\dots}{2}$,
- $n\cdot n^3=n^4$.

Paydalar 12'de eşitlenir. Hocanın genişletmesiyle pay $3n^4+12n^4+18n^4+12n^4+\dots=45n^4+\dots$ olur:

$$U_n=\frac{45n^4+\dots}{12\,n^4}.$$

$n\to\infty$ iken:

$$\int_1^2 x^3\,dx=\lim_{n\to\infty}U_n=\frac{45}{12}=\frac{15}{4}.$$

Sonuç $n$'ye bağlı değildir, sabittir. Sympy ile kapalı biçim $U_n=\frac{(3n+1)(5n+3)}{4n^2}$ bulundu; limiti $\frac{15}{4}$'tür.

> **Ders sonrası not:** 01:48-01:51 arasında hoca payda eşitlerken bir süre karıştırdı ("33, 55 mi geldi?"), sonra kendisi 45'e ulaştı ve 3'e bölerek $\frac{15}{4}$'ü buldu. Sonuç doğrudur. Yeni bir yöntemle kontrol: ters türevle $\left[\frac{x^4}{4}\right]_1^2=\frac{16-1}{4}=\frac{15}{4}$ (ara adım eklendi; bu yöntem derste henüz anlatılmadı).

Hoca sonucu şöyle yorumladı: Riemann toplamı $n$'ye bağlı sonlu bir toplamdır, yalnız alan için bir tahmindir, hatalı bir toplamdır. Belirli integral ise gerçek alandır; burada hata sıfırdır. Parça sayısı sonsuza götürüldüğünde hatasız gerçek cevap bulunur: $\frac{15}{4}$.

## 11. Kapanış: Riemann Toplamının Yeri

**Soru:** Bunu integralin nereden geldiğini göstermek için mi anlattınız, yoksa doğrudan integral mi hesaplayacağız? **Cevap:** Hoca, anlattığı her şeyin önemli olduğunu söyledi. Buradaki mantığı anlamazsanız soruları çözemezsiniz.

> **Hocanın vurgusu:** Doğrudan Riemann toplamı hesaplamanız istenebilir. Ayrıca öyle limitler vardır ki başka yolla hesaplayamazsınız, yalnız Riemann toplamıyla hesaplarsınız.

**Soru:** Sonsuz toplama limit uyguladığımız için belirli integrali elde ediyoruz, değil mi? **Cevap:** Evet. Bölüntü sayısını artırarak hatası sıfır olan bir tahmin elde ettik. Bu, belirli integralin arkasındaki felsefedir.

Hoca bu yaklaşımın hesap için pek pratik olmadığını, yalnız belirli integralin temeli olduğunu söyledi. Gelecek hafta bu işlemleri kolaylaştıran popüler teoremler öğrenilecek.

> **Ek bilgi (derste anlatılmadı):** Hocanın sözünü ettiği teoremlerin başında büyük olasılıkla analizin temel teoremi (fundamental theorem of calculus) gelir. Bu teorem, sürekli $f$ için $F'=f$ ise $\int_a^b f(x)\,dx=F(b)-F(a)$ olduğunu söyler. Böylece belirli integral, Riemann toplamının limitiyle uğraşmadan ters türevle hesaplanır. Bölüm 7.3'teki $\int dA=A$ ilişkisi bu teoremin sezgisidir.

## Örnek Sorular

Bu derste video karesi kullanılmadı. Aşağıdaki sorular derste hocanın sözlü sorduğu ya da öğrencilerin sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:05:56): $\displaystyle\int\frac{dx}{1+4x^2}$ integralinde integrandın hangi kısmı $u$ olmalıdır?

> **Çözüm (derste verildi):** $\int\frac{du}{1+u^2}=\arctan u+C$ formülüne uymak için $u=2x$ seçilir. $dx=\frac{1}{2}du$ ile sonuç $\frac{1}{2}\arctan(2x)+C$ olur (Bölüm 3.1).

**Soru 2** (derste sözlü, 00:09:01): $\displaystyle\int\frac{\ln x}{x\,(1+\ln^2 x)}\,dx$ integralinde hangi kısım $u$ olmalıdır?

> **Çözüm (derste verildi):** $u=\ln x$ seçilirse ifade sadeleşmez. $u=\ln^2 x$ (ya da bir öğrencinin önerdiği $u=1+\ln^2 x$) seçilir. $\frac{\ln x}{x}dx=\frac{1}{2}du$ ile sonuç $\frac{1}{2}\ln(1+\ln^2 x)+C$ olur (Bölüm 3.2).

**Soru 3** (derste sözlü, 00:13:07): Türevi $\dfrac{1}{x\,(1+4\ln^2 x)}$ olan fonksiyon nedir?

> **Çözüm (derste verildi):** $u=\ln x$, sonra $a=2u$ dönüşümleriyle $\frac{1}{2}\arctan(2\ln x)+C$ bulunur (Bölüm 3.3).

**Soru 4** (derste sözlü, 00:28:48): $y=f(x)$ grafiğinin altında ve $[a,b]$ aralığının üstünde kalan bölgenin alanını nasıl tahmin ederiz?

> **Çözüm (derste verildi):** Bölge sonlu sayıda yeterince küçük dikdörtgene bölünür, dikdörtgenlerin alanları toplanır. Parça sayısı arttıkça tahmin gerçek alana yaklaşır (Bölüm 5.2).

**Soru 5** (derste sözlü, 00:51:48): Bir doğru parçasının alanı var mıdır?

> **Çözüm (derste verildi):** Kesin bir cevap yoktur, bu bir varsayımdır. Yüksekliği $f(x)$, kalınlığı $dx$ olan doğru parçasının alanı $dA=f(x)\,dx$ diye varsayılır; sonsuz sayıda parça toplanınca $A=\int_a^b f(x)\,dx$ elde edilir (Bölüm 7.2-7.3).

**Soru 6** (derste sözlü, 01:19:56): $\displaystyle\sum_{k=1}^{n}\left(\frac{k}{n}\right)^2\frac{1}{n}$ toplamında toplam değişkeni hangisidir?

> **Çözüm (derste verildi):** $k$'dır. $n$, toplam değişkenine göre sabittir; bu yüzden $\frac{1}{n^3}$ toplamın dışına alınabilir (Bölüm 9.1).

**Soru 7** (derste sözlü, 01:30:19): $L_n\le A\le U_n$ ve $L_n, U_n\to L$ iken $A$'yı bulmak için hangi teorem kullanılır?

> **Çözüm (derste verildi):** Sıkıştırma teoremi. Buna göre $A=\int_0^1 x^2\,dx=\frac{1}{3}$ (Bölüm 9.3).

**Soru 8** (derste sözlü, 01:35:00): Alt ve üst Riemann toplamlarının limitlerinin aynı olduğunu nereden biliyoruz?

> **Çözüm (derste verildi):** $f$ sürekli olduğu için parça sayısı arttıkça her dikdörtgenin hatası küçülür ve $U_n-L_n$ sıfıra gider. $[0,1]$ üzerinde $x^2$ için $U_n-L_n=\frac{1}{n}$'dir (Bölüm 9.4).

**Soru 9** (derste sözlü, 01:40:56): $f(x)=x^3$ fonksiyonunun $[1,2]$ üzerindeki üst Riemann toplamını hesaplayın.

> **Çözüm (derste verildi):** $\Delta x=\frac{1}{n}$, $x_k=\frac{n+k}{n}$, $U_n=\frac{1}{n^4}\sum_{k=1}^{n}(k+n)^3=\frac{(3n+1)(5n+3)}{4n^2}$. Limiti $\int_1^2 x^3\,dx=\frac{15}{4}$'tür (Bölüm 10).

## Dersin Toparlaması

Bu derste önce yerine koyma yöntemi pekiştirildi. Temel fikir, integranddaki iç fonksiyona $u$ deyip $du=u'(x)\,dx$ bağıntısıyla integrali daha basit bir integrale indirmektir. $\arctan$ veren integraller üzerinde hoca formül ezberlemek yerine uygun değişken değiştirmenin yeterli olduğunu gösterdi. Ardından toplam sembolü, toplam değişkeni kavramı, sonlu toplamların özellikleri ve $\sum k$, $\sum k^2$, $\sum k^3$, $\sum c$ formülleri verildi.

Dersin ana konusu belirli integralin doğuşuydu. Bir bölgenin alanı, çiftçilerin de bildiği gibi, dikdörtgenlere bölünerek tahmin edilir. $[a,b]$ aralığı $\Delta x=\frac{b-a}{n}$ uzunluğunda $n$ parçaya bölünür, $x_k=a+k\,\Delta x$ alınır. Hataların grafiğin üstünde ya da altında kalmasına göre üst ve alt Riemann toplamı kurulur. Bunlar $n$'ye bağlı, hatalı sonlu toplamlardır. $f$ sürekliyse $n\to\infty$ limiti vardır ve sıkıştırma teoremiyle iki toplam aynı sabite gider: bu belirli integraldir, yani hatası sıfır olan sonsuz toplamdır. $\int_0^1 x^2\,dx=\frac{1}{3}$ ve $\int_1^2 x^3\,dx=\frac{15}{4}$ bu yolla hesaplandı. Hoca gelecek hafta bu hesapları kolaylaştıran teoremlerin anlatılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
