# Ders 16 Genişletilmiş Notu: Ekstremum Değerler, İkinci Türev Testi, İki Değişkenli Taylor Açılımı ve Kısıtlı Kısmi Türevler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Derse Giriş
- 2. Tek Değişkenli Fonksiyonlarda Ekstremum (Hatırlatma)
- 3. Çok Değişkenli Fonksiyonlarda Ekstremum
- 4. İkinci Türev Testi
- 5. İkinci Türev Testiyle Çözülen Sorular
- 6. Taylor Açılımı
- 7. Kısıtlı Değişkenlerle Kısmi Türev
- 8. Zincir Kuralı ve Kapalı Fonksiyon Soruları
- Örnek Sorular
- Dersin Toparlaması

## 1. Derse Giriş

Ders online olarak (Zoom) yapıldı. Hoca ekran paylaşımı ve sanal tahta kullandı. Başta bir önceki dersle ilgili soru olup olmadığını sordu. Soru gelmeyince bu derste yeni konuya geçilmeyeceğini, önceki konuların örneklerle pekiştirileceğini söyledi.

Hoca konuyu şöyle bağladı: Çok değişkenli fonksiyonların türevlerini gördük. Tek değişkenli fonksiyonlarda olduğu gibi burada da ekstremum değerleri (extreme values), yani uç değerleri, maksimum ve minimum değerleri bulmak istiyoruz. Bir malın maliyeti, kârı, satışı, maksimum kazanç, minimum maliyet gibi problemler hep türev alıp sıfıra eşitlemekle çözülür.

Not: Hoca tahtaya ve slayta yazarak anlattı. Altyazıda yalnız sözlü kısım vardır. Bu dersin kareleri yoktur. Formüller sözlü anlatımdan kuruldu. Sözlü anlatımda tam geçmeyen fonksiyonlar kısa nottan alındı ve metinde ayrıca belirtildi.

## 2. Tek Değişkenli Fonksiyonlarda Ekstremum (Hatırlatma)

Hoca tahtada $y=f(x)$ fonksiyonu için maksimum ve minimum bulmanın üç yolunu hatırlattı. Her yolda önce türev alınır ve sıfıra eşitlenir: $f'(x)=0$. Buradan çıkan $x_1,x_2$ (tahtada $a,b$) değerlerine **kritik nokta** (critical point) denir.

- **1. yol (tanım):** Kritik noktadaki değer, tanım kümesindeki diğer değerlerle karşılaştırılır. Her $x$ için $f(a)\ge f(x)$ ise $x=a$'da maksimum vardır. Her $x$ için $f(a)\le f(x)$ ise minimum vardır.
- **2. yol (işaret tablosu):** Tabloda $x$ değerleri ve türevin işareti yazılır. Türev pozitif olan aralıkta fonksiyon artar, negatif olan aralıkta azalır. Hocanın tahtadaki örneğinde türev $a$'da artıdan eksiye, $b$'de eksiden artıya geçiyor. Fonksiyon önce artıp sonra azaldığı için $a$'da maksimum, önce azalıp sonra arttığı için $b$'de minimum vardır.
- **3. yol (ikinci türev):** Kritik nokta ikinci türevde yerine konur. $f''(a)>0$ ise $a$'da minimum, $f''(b)<0$ ise $b$'de maksimum vardır.

## 3. Çok Değişkenli Fonksiyonlarda Ekstremum

### 3.1 Kritik noktayı bulmak

$z=f(x,y)$ fonksiyonunda aynı mantık kullanılır. İki kısmi türev ayrı ayrı sıfıra eşitlenir:

$$f_x(x,y)=0,\qquad f_y(x,y)=0.$$

Bu sistemin çözümü $(a,b)$ kritik noktasını verir. Hoca, bu noktada üç durum olabileceğini söyledi: maksimum olabilir, minimum olabilir ya da hiçbiri olmayabilir.

### 3.2 Yerel ekstremum tanımı

**Tanım (yerel maksimum ve yerel minimum):**
- $(a,b)$ noktasının civarındaki her $(x,y)$ için $f(x,y)\le f(a,b)$ ise $f$, $(a,b)$'de **yerel maksimuma** (local maximum) sahiptir.
- $(a,b)$ civarındaki her $(x,y)$ için $f(x,y)\ge f(a,b)$ ise $f$, $(a,b)$'de **yerel minimuma** (local minimum) sahiptir.
- $f$, $(a,b)$'de yerel maksimuma ya da yerel minimuma sahipse bu noktada bir **ekstremuma** sahiptir. İkisine de sahip değilse orada ekstremum (uç nokta) yoktur.

Hoca bunu üç boyutlu grafikle anlattı. Yüzey $(a,b)$ noktasından her yöne yukarı çıkıyorsa, $(a,b)$'deki değer çevredeki değerlerden küçüktür ve orada minimum vardır. Yüzey $(a,b)$'den her yöne aşağı iniyorsa, orada maksimum vardır. "Yerel" sözcüğünü "bölgesel" diye açıkladı: karşılaştırma yalnız noktanın yakın çevresinde yapılır.

### 3.3 Kritik nokta teoremi

**Teorem (kritik nokta):** $(a,b)$, $f$'nin tanım kümesinde bir nokta olsun. Aşağıdakilerden biri sağlanıyorsa $(a,b)$ bir kritik noktadır:
- $f_x(a,b)=0$ ve $f_y(a,b)=0$.
- $f_x(a,b)$ ya da $f_y(a,b)$ mevcut değil.

Hoca bunu yerel ekstremum için gerekli şart olarak verdi ve tek değişkenli durumdan bilindiği için ayrıca tekrar etmedi.

### 3.4 Eyer noktası

**Tanım (eyer noktası):** $(a,b)$ kritik nokta olsun. $f$, $(a,b)$'de ne yerel maksimuma ne de yerel minimuma sahipse bu noktaya **eyer noktası** (saddle point) denir. Hoca diğer adının "semer noktası" olduğunu söyledi.

Hoca, test sınavında "aşağıdakilerden hangisi doğrudur" biçiminde, türevi sıfır olan ama maksimum ya da minimum olmayan bir noktanın eyer noktası olduğunun sorulabileceğini söyledi. Altyazıda bu terim "eğer noktası", "E'ye noktası" ve "Eya noktası" diye geçiyor; doğrusu "eyer noktası"dır.

### 3.5 Farkın işaretiyle sınıflandırma

Hoca kritik noktayı sınıflandırmanın bir yolu olarak şu farka baktı. $(a,b)$ kritik nokta olsun. $x$'i $h$ kadar, $y$'yi $k$ kadar değiştirelim:

$$\Delta=f(a+h,b+k)-f(a,b).$$

- Yeterince küçük her $h,k$ için $\Delta\ge 0$ ise $(a,b)$'de yerel minimum vardır.
- Yeterince küçük her $h,k$ için $\Delta\le 0$ ise $(a,b)$'de yerel maksimum vardır.
- $\Delta$'nın işareti belli değilse, yani bazı $(h,k)$ için pozitif, bazıları için negatif oluyorsa, $(a,b)$ eyer noktasıdır.

Hoca bu tipte bir sorunun beş altı yıl önce sınavda geldiğini söyledi.

> **Ders sonrası not:** Hoca bu tanımı okurken "$h$ ve $k$ pozitif olmak üzere" dedi. Doğrusu: $h$ ve $k$ sıfıra yakın, **her işaretten** değerlerdir. Yalnız pozitif $h,k$ alınırsa noktanın sadece bir çeyreği incelenmiş olur. Aşağıdaki Örnek 3'te $h^2-k^2$'nin işaretinin belirsiz olması da bu yüzdendir.

### 3.6 Örnekler

**Örnek 1 (sınav sorusu):** $f(x,y)=x^2+y^2$ fonksiyonunun kritik noktalarını bulup sınıflandırın.

- Kısmi türevler: $f_x=2x$, $f_y=2y$.
- $2x=0$ ve $2y=0$ ancak $x=0$, $y=0$ ile mümkündür. Kritik nokta $(0,0)$.
- Fark: $f(0+h,0+k)-f(0,0)=h^2+k^2-0=h^2+k^2$.
- Kareler toplamı her zaman sıfırdan büyük ya da eşittir: $h^2+k^2\ge 0$.
- Sonuç: $(0,0)$ yerel minimum noktasıdır.

Hoca, fark ters işaretli çıksaydı maksimum diyeceğimizi ekledi.

**Örnek 2:** Hoca bir sonraki sorunun da yerel minimum çıktığını söyledi.
<!-- BELİRSİZ: Fonksiyon altyazıda okunmuyor. Kısa notta $f(x,y)=(x+y)^2+y^4$ olarak geçiyor; çözüm buna göre yazıldı. -->

- $f_x=2(x+y)=0$, $f_y=2(x+y)+4y^3=0$.
- İkinciden birinci çıkarılırsa $4y^3=0$, yani $y=0$. Buradan $x=0$. Kritik nokta $(0,0)$.
- Fark: $f(h,k)-f(0,0)=(h+k)^2+k^4\ge 0$.
- Sonuç: $(0,0)$ yerel minimumdur.

> **Ek bilgi (derste anlatılmadı):** Bu fonksiyonda $(0,0)$'da $A=f_{xx}=2$, $B=f_{xy}=2$, $C=f_{yy}=2$ olur ve $B^2-AC=4-4=0$ çıkar. Yani aşağıdaki ikinci türev testi bu noktada sonuç vermez. Böyle durumlarda farkın işaretine bakma yöntemi işe yarar. Hocanın "bütün yöntemleri bilin" uyarısı bu tip sorular içindir.

**Örnek 3:** Kritik noktası $(0,0)$ olan bir fonksiyonda fark $h^2-k^2$ çıkıyor.
<!-- BELİRSİZ: Fonksiyon altyazıda okunmuyor; fark $h^2-k^2$ olduğuna göre büyük olasılıkla $f(x,y)=x^2-y^2$. -->

- $f_x=0$ ve $f_y=0$'dan kritik nokta $(0,0)$ bulundu.
- Fark: $f(h,k)-f(0,0)=h^2-k^2$.
- Bu ifade için "sıfırdan büyük" ya da "sıfırdan küçük" denemez. Örneğin $k=0$ alınırsa $h^2>0$, $h=0$ alınırsa $-k^2<0$ olur.
- Sonuç: $(0,0)$ eyer noktasıdır. Hoca, şıklı soruda bunun doğru cevap olacağını söyledi.

> **Hocanın vurgusu:** Yöntem ve teknik bilmek çok önemli. "İkinci türev testini bilmeye gerek yok" diye düşünmeyin. Yöntemlerin kullanıldığı yerler farklıdır, bazen kesişir. Hoca bunu araba ve motosikletle benzetti: Arabanın giremediği yere motosiklet girer, motosikletin yapamadığını araba yapar. Bu testler bir ihtiyaçtan doğmuştur. Bol alıştırma çözün, soru kaçırmayın.

## 4. İkinci Türev Testi

Hoca ikinci türev testini (second derivative test) önce tahtada kısaca, sonra slayttan anlattı.

**Teorem (ikinci türev testi):** $f$'nin birinci ve ikinci mertebe kısmi türevleri $(a,b)$ civarında sürekli olsun ve $(a,b)$ kritik nokta olsun, yani $f_x(a,b)=f_y(a,b)=0$. Şu kısaltmalar kullanılır:

$$A=f_{xx}(a,b),\qquad B=f_{xy}(a,b),\qquad C=f_{yy}(a,b).$$

- $B^2-AC<0$ ve $A>0$ ise $f$, $(a,b)$'de yerel minimuma sahiptir.
- $B^2-AC<0$ ve $A<0$ ise $f$, $(a,b)$'de yerel maksimuma sahiptir.
- $B^2-AC>0$ ise $(a,b)$ eyer noktasıdır.
- $B^2-AC=0$ ise test sonuç vermez. Hoca bunu "başka kapıya" diye anlattı: başka bir yönteme, örneğin farkın işaretine bakmaya geçilir.

Burada $f_{xx}$, $x$'e göre iki kez kısmi türev; $f_{xy}$, önce $x$'e sonra $y$'ye göre kısmi türev; $f_{yy}$, $y$'ye göre iki kez kısmi türevdir.

Uygulamada bir tablo kurulur: Satırlarda kritik noktalar, sütunlarda $A$, $B$, $C$, $B^2-AC$ ve sonuç yer alır. Önce $B^2-AC$'nin işaretine, o negatifse $A$'nın işaretine bakılır.

> **Ders sonrası not:** Hoca testi ilk kez tahtada anlatırken harfleri karıştırdı. $C=f_{xy}$ deyip "$C^2-A\cdot B$ sıfırdan büyükse ve $A>0$ ise minimum" dedi. Slayttan anlatırken önce "$B^2-4AC$" deyip "4 yok, pardon $B^2-AC$" diye düzeltti ve doğru koşulu ($B^2-AC<0$) verdi. Doğrusu yukarıdaki kutudadır: $B=f_{xy}$, $A=f_{xx}$, $C=f_{yy}$ ve ekstremum için $B^2-AC<0$ gerekir.

> **Ek bilgi (derste anlatılmadı):** Birçok kitapta aynı test $D=f_{xx}f_{yy}-f_{xy}^2=AC-B^2$ ile yazılır. O gösterimde $D>0$ ekstremum, $D<0$ eyer noktası demektir. İşaretler tam ters görünür ama iki yazım aynı testtir.

## 5. İkinci Türev Testiyle Çözülen Sorular

### 5.1 Örnek 4

**Soru:** $f(x,y)=2x^3-6xy+3y^2$ fonksiyonunun kritik noktalarını bulup sınıflandırın.
<!-- BELİRSİZ: Fonksiyon altyazıda tam okunmuyor. Hoca "$2x^3$'ün türevi $6x^2$" ve "$6y$" diyor; kısa nottaki $f_x=6x^2-6y$, $f_y=-6x+6y$ bununla uyumlu. -->

**Çözüm:**

- $f_x=6x^2-6y=0$ (1), $f_y=-6x+6y=0$ (2).
- (2)'den $x=y$.
- Bunu (1)'e koyunca $6x^2-6x=0$, yani $6x(x-1)=0$. Buradan $x=0$ ya da $x=1$.
- $x=0$ iken $y=0$; $x=1$ iken $y=1$. Kritik noktalar $(0,0)$ ve $(1,1)$.
- İkinci türevler: $A=f_{xx}=12x$, $B=f_{xy}=-6$, $C=f_{yy}=6$.

| Nokta | $A$ | $B$ | $C$ | $B^2-AC$ | Sonuç |
|---|---|---|---|---|---|
| $(0,0)$ | $0$ | $-6$ | $6$ | $36>0$ | Eyer noktası |
| $(1,1)$ | $12$ | $-6$ | $6$ | $36-72=-36<0$ | $A=12>0$, yerel minimum |

Hoca, şıklarda "$(1,1)$'de yerel minimum vardır" ve "$(0,0)$ eyer noktasıdır" ifadelerinin ikisinin de doğru olduğunu söyledi. Soru "hangisi yanlıştır" diye de sorulabilir.

### 5.2 Örnek 5

**Soru:** $f(x,y)=x^3-3x^2+3xy^2-3y^2$ fonksiyonunun kritik noktalarını bulup sınıflandırın.
<!-- BELİRSİZ: Fonksiyon altyazıda okunmuyor; kısa nottan alındı. Altyazıdaki çözüm adımları ($y(x-1)=0$, $x=1$ için $y^2=1$, $y=0$ için $x=0$ ya da $x=2$, $B^2-AC=-36$) bu fonksiyonla tutarlı. -->

Hoca türev alırken şunu hatırlattı: $x$'e göre türev alınırken $y$ sabit gibi, $y$'ye göre alınırken $x$ sabit gibi düşünülür.

**Çözüm:**

- $f_x=3x^2-6x+3y^2=0$ (1).
- $f_y=6xy-6y=6y(x-1)=0$ (2).
- (2)'de iki çarpanın çarpımı sıfırdır. Ya $y=0$ ya da $x=1$.
- $x=1$ ise (1)'den $3-6+3y^2=0$, yani $y^2=1$, $y=\pm1$. Noktalar $(1,1)$ ve $(1,-1)$.
- $y=0$ ise (1)'den $3x^2-6x=0$, yani $x=0$ ya da $x=2$. Noktalar $(0,0)$ ve $(2,0)$.
- Dört kritik nokta vardır. Hoca bunu "güzel bir soru, tam sınav sorusu" diye niteledi.
- İkinci türevler: $A=f_{xx}=6x-6$, $B=f_{xy}=6y$, $C=f_{yy}=6x-6$.

| Nokta | $A$ | $B$ | $C$ | $B^2-AC$ | Sonuç |
|---|---|---|---|---|---|
| $(0,0)$ | $-6$ | $0$ | $-6$ | $-36<0$ | $A<0$, yerel maksimum |
| $(1,1)$ | $0$ | $6$ | $0$ | $36>0$ | Eyer noktası |
| $(1,-1)$ | $0$ | $-6$ | $0$ | $36>0$ | Eyer noktası |
| $(2,0)$ | $6$ | $0$ | $6$ | $-36<0$ | $A>0$, yerel minimum |

Sonuç: $(0,0)$'da yerel maksimum, $(2,0)$'da yerel minimum vardır. $(1,1)$ ve $(1,-1)$ eyer noktalarıdır.

Hoca, $B^2-AC=0$ çıksaydı testin cevap vermeyeceğini ve diğer yönteme (farkın işaretine) geçileceğini tekrar hatırlattı.

## 6. Taylor Açılımı

### 6.1 Tek değişkenli hatırlatma

$f$, $x_0$ civarında her mertebeden türevlenebilir olsun. Taylor açılımı (Taylor expansion):

$$f(x)=f(x_0)+f'(x_0)(x-x_0)+\frac{f''(x_0)}{2!}(x-x_0)^2+\cdots=\sum_{k=0}^{\infty}\frac{f^{(k)}(x_0)}{k!}(x-x_0)^k.$$

- Toplam sonsuza kadar değil $n$'e kadar alınırsa **Taylor polinomu** elde edilir.
- $x_0=0$ özel durumunda açılıma **Maclaurin açılımı** denir. Formülde $x_0$ yerine $0$ yazılır.

Hoca, fonksiyonu seriyle yaklaşık olarak yazmanın çok önemli olduğunu söyledi. Bu yaklaşım özellikle mekatronik mühendisliğinde, uygulamalı bilimlerde ve uçak sanayisinde çok kullanılır. Tek değişkenli açılımın ilk dönemden bilindiğini, burada yalnız hatırlatma yapıldığını belirtti.

### 6.2 İki değişkenli Taylor açılımı

$f(x,y)$, $(a,b)$ noktası civarında yeterince türevlenebilir olsun. İkinci mertebe terimlere kadar açılım:

$$f(x,y)\approx f(a,b)+f_x(a,b)(x-a)+f_y(a,b)(y-b)+\frac{1}{2!}\Big[f_{xx}(a,b)(x-a)^2+2f_{xy}(a,b)(x-a)(y-b)+f_{yy}(a,b)(y-b)^2\Big].$$

Hoca formülü yazarken bir an karıştırdı ($(x-x_0)$'ın karesini erken yazdı), ekranı durdurup düzeltti. Doğru biçim yukarıdadır.

> **Hocanın vurgusu:** Sınavda sorulabilecek en fazla kısım ikinci mertebe terimlere kadardır. Formül $\frac{1}{3!}$'li üçüncü mertebe terimlerle devam eder ama o kısım sorulmaz.

> **Ek bilgi (derste anlatılmadı):** Köşeli parantezdeki ifade, tek değişkendeki $f''(x_0)(x-x_0)^2$ teriminin iki değişkenli karşılığıdır. Kritik noktada birinci mertebe terimler sıfır olduğundan, fonksiyonun davranışını bu ikinci mertebe kısım belirler. İkinci türev testindeki $A$, $B$, $C$ sayıları da tam bu parantezdeki katsayılardır.

### 6.3 Örnek 6

Hoca bunun "çok orijinal" ve sınavda çıkmış bir soru olduğunu söyledi.

**Soru:** $f(x,y)=e^x\sin y$ fonksiyonunun $(0,\pi/2)$ noktasında ikinci mertebe türevlerin bulunduğu terime kadar Taylor açılımı hangisidir?
<!-- BELİRSİZ: Fonksiyon altyazıda sözlü geçmiyor; kısa nottan alındı. Hocanın sonucu "$1+x+x^2/2-\dots$" bununla tutarlı. -->

**Çözüm:** $(a,b)=(0,\pi/2)$. Gereken türevler ve değerleri:

| Türev | İfade | $(0,\pi/2)$'deki değer |
|---|---|---|
| $f$ | $e^x\sin y$ | $1$ |
| $f_x$ | $e^x\sin y$ | $1$ |
| $f_y$ | $e^x\cos y$ | $0$ |
| $f_{xx}$ | $e^x\sin y$ | $1$ |
| $f_{xy}$ | $e^x\cos y$ | $0$ |
| $f_{yy}$ | $-e^x\sin y$ | $-1$ |

Formüle yerleştirince (ara adım eklendi):

$$f(x,y)\approx 1+1\cdot x+0\cdot\left(y-\tfrac{\pi}{2}\right)+\frac{1}{2}\Big[1\cdot x^2+2\cdot0\cdot x\left(y-\tfrac{\pi}{2}\right)-1\cdot\left(y-\tfrac{\pi}{2}\right)^2\Big],$$

$$f(x,y)\approx 1+x+\frac{x^2}{2}-\frac{1}{2}\left(y-\frac{\pi}{2}\right)^2.$$

Hoca test sınavı için bir ipucu verdi: Şıklarda baştaki terimlerden biri farklıysa, ilk birkaç terimi bulmak bile doğru şıkkı seçmeye yetebilir. Yine de açılımı tam yapmakta fayda var; şıklar birbirine çok benziyorsa sona kadar bakmak gerekir.

## 7. Kısıtlı Değişkenlerle Kısmi Türev

### 7.1 Bağımlı ve bağımsız değişken

Bu konu önceki derste anlatılmıştı. Hoca şöyle hatırlattı: $w$, $x,y,z$'ye bağlı olsun; $z$ de bir denklemle $x$ ve $y$'ye bağlı olsun. Bu durumda değişkenlerin hepsi bağımsız değildir. Türev alırken önce hangilerinin bağımsız, hangilerinin bağımlı olduğu belirlenmelidir.

**Gösterim:** $\left(\dfrac{\partial w}{\partial x}\right)_y$ ifadesinde türevin alındığı değişken ($x$) ile alt indisteki değişken ($y$) bağımsız değişkenlerdir. Geri kalan değişkenlerin hepsi bağımlıdır.

Hoca slayttaki genel örnekleri şöyle okudu:

- $\left(\dfrac{\partial w}{\partial x}\right)_y$: bağımsız $x,y$; bağımlı $w$ ve $z$.
- Alt indiste $y$ ve $t$ olan bir türevde ($x$'e göre): bağımsız $x,y,t$; bağımlı yalnız $w$.
- $x,y,z,w$ arasında bir $F(x,y,z,w)=0$ bağıntısı varken $z$ ve $w$'nin bağımsız olduğu bir türevde: bağımlı değişkenler $x$ ve $y$'dir.
<!-- BELİRSİZ: Bu genel örneklerin tam ifadeleri (hangi türevin istendiği) altyazıda net değil. -->

### 7.2 Çözüm yöntemi

- Bağımlı bir değişken (örneğin $z$) türevde sabit sayılmaz. Zincir kuralıyla türetilir: $\dfrac{\partial}{\partial x}(z^2)=2z\dfrac{\partial z}{\partial x}$.
- Kısıt denklemi $F(x,y,z)=0$ biçiminde, kapalı fonksiyon (implicit function) olarak yazılır.
- Kapalı fonksiyonun türevi: $\dfrac{\partial z}{\partial x}=-\dfrac{F_x}{F_z}$, $\dfrac{\partial z}{\partial y}=-\dfrac{F_y}{F_z}$.
- $F_x$, $F_z$ hesaplanırken $F$'in diğer değişkenleri sabit gibi düşünülür. Hoca bunu "pratik yöntem" diye andı: Bu formülle çalışırken artık bağımlı-bağımsız ayrımı yapılmaz. Açık yazarak türev alınırsa bağımlı değişken zincir kuralıyla türetilir.

### 7.3 Örnek 7

**Soru (sınav sorusu):** $w=x^2+y^2+z^2$ ve $z^3-xy+yz+y^3=1$ olsun. $(x,y,z)=(2,-1,1)$ noktasında $\left(\dfrac{\partial w}{\partial x}\right)_y$ hangisidir?
<!-- BELİRSİZ: $w$ ifadesi ve nokta altyazıda sözlü geçmiyor; kısa nottan alındı. Kısıt denklemi altyazıda ($z^3$, $-xy$, $+yz$, $+y^3$, $-1=0$) okunuyor. -->

**Çözüm:**

- Bağımsız: $x,y$. Bağımlı: $w$ ve $z$.
- $w$'nin $x$'e göre türevi: $\dfrac{\partial w}{\partial x}=2x+2z\dfrac{\partial z}{\partial x}$. Burada $z$ bağımlı olduğu ve $x$'e bağlı olduğu için $2z$ ile $\dfrac{\partial z}{\partial x}$ çarpılır. $y^2$'nin türevi sıfırdır.
- Kısıt kapalı fonksiyon olarak: $F(x,y,z)=z^3-xy+yz+y^3-1=0$.
- $F_x=-y$, $F_z=3z^2+y$.
- $\dfrac{\partial z}{\partial x}=-\dfrac{F_x}{F_z}=\dfrac{y}{3z^2+y}$.
- Yerine koyunca: $\dfrac{\partial w}{\partial x}=2x+\dfrac{2zy}{3z^2+y}$.
- $(2,-1,1)$'de: $2\cdot2+\dfrac{2\cdot1\cdot(-1)}{3\cdot1-1}=4-1=3$.

Sonuç: $\left(\dfrac{\partial w}{\partial x}\right)_y=3$. Hoca bunun test sorusuna çok uygun olduğunu söyledi.

### 7.4 Örnek 8

**Soru:** $w=x^2+y-z+\sin t$ ve $t=x+y$ olsun. $\left(\dfrac{\partial w}{\partial x}\right)_{y,z}$ hangisidir?
<!-- BELİRSİZ: $w$ ifadesi altyazıda tam geçmiyor; kısa nottan alındı. Altyazıda $t$ harfi "Trabzon" diye yazılmış. -->

**Çözüm:**

- $w$, $x,y,z,t$'ye bağlı; $t$ ise $x,y$'ye bağlı.
- Bağımsız: $x,y,z$. Bağımlı: $w$ ve $t$.
- $x^2$'nin türevi $2x$; $y$ ve $z$ bağımsız olduğu için türevleri $0$.
- $t$ bağımlı olduğu için $\sin t$'nin türevi zincir kuralıyla: $\cos t\cdot\dfrac{\partial t}{\partial x}$.
- $t=x+y$ olduğundan $\dfrac{\partial t}{\partial x}=1$.
- $\dfrac{\partial w}{\partial x}=2x+\cos t=2x+\cos(x+y)$.

Hoca son adımda $t$ yerine $x+y$ yazmak gerektiğini vurguladı, çünkü soru sonucu bağımsız değişkenler cinsinden istiyor. Şıklarda $2x+\cos(x+y)$ olan şık doğru cevaptır.

### 7.5 Örnek 9

**Soru:** $w=x^2+y^2+z^2$ ve $y\sin z+z\sin x=0$ olsun. $(0,1,\pi)$ noktasında $\left(\dfrac{\partial w}{\partial y}\right)_x$ hangisidir?
<!-- BELİRSİZ: Soru altyazıda sözlü okunmuyor; kısa nottan alındı. Hocanın türevleri ($F_y=\sin z$, $F_z=y\cos z+\sin x$) ve sonucu (2) bununla tutarlı. -->

Slaytta aynı soru için iki türev isteniyordu. Hoca hangisinin yapılacağını öğrencilere sordu ve birincisini çözdü.

**Çözüm:**

- Bağımsız: $x,y$. Bağımlı: $w$ ve $z$.
- $\dfrac{\partial w}{\partial y}=2y+2z\dfrac{\partial z}{\partial y}$. $x^2$'nin $y$'ye göre türevi sıfırdır.
- $F(x,y,z)=y\sin z+z\sin x$ alınır.
- $F_y=\sin z$ ($z$ sabit gibi).
- $F_z=y\cos z+\sin x$ ($y\sin z$'nin türevi $y\cos z$; $z\sin x$'in türevi $\sin x$).
- $\dfrac{\partial z}{\partial y}=-\dfrac{F_y}{F_z}=-\dfrac{\sin z}{y\cos z+\sin x}$. Hoca eksi işaretinin unutulmaması gerektiğini söyledi.
- $(0,1,\pi)$'de $\sin\pi=0$ olduğundan $\dfrac{\partial z}{\partial y}=0$.
- Sonuç: $\dfrac{\partial w}{\partial y}=2\cdot1+0=2$.

> **Hocanın vurgusu:** Hesaplamalarda dikkatli olun. Şıklarda 2, 3, 4 gibi birbirine yakın sayılar verilir. Küçük bir hesap hatası sizi doğru cevaba gidecekken yanlış cevaba götürür.

> **Ders sonrası not:** Slayttaki ikinci türev, $\left(\dfrac{\partial w}{\partial y}\right)_z$, derste çözülmedi. Bu durumda $y,z$ bağımsız, $w$ ve $x$ bağımlıdır: $\dfrac{\partial w}{\partial y}=2y+2x\dfrac{\partial x}{\partial y}$ ve $\dfrac{\partial x}{\partial y}=-\dfrac{F_y}{F_x}=-\dfrac{\sin z}{z\cos x}$. $(0,1,\pi)$'de $\sin\pi=0$ olduğundan bu türev de sıfırdır ve sonuç yine $2$ çıkar (sympy ile doğrulandı).

## 8. Zincir Kuralı ve Kapalı Fonksiyon Soruları

### 8.1 Örnek 10: Kutupsal dönüşüm

**Soru:** $f$, birinci mertebe kısmi türevleri mevcut iki değişkenli bir fonksiyon ve $z=f(x,y)$ olsun. $x=r\cos\theta$, $y=r\sin\theta$ dönüşümü yapılırsa
$$y\frac{\partial z}{\partial x}-x\frac{\partial z}{\partial y}=0$$
denklemi hangi şekli alır?
<!-- BELİRSİZ: Denklemin tam biçimi altyazıda sözlü geçmiyor; kısa nottan alındı. Hocanın çözüm adımları ve "$\partial z/\partial\theta$ sıfır" sonucu bununla tutarlı. -->

Hoca bunun bir zincir kuralı (chain rule) sorusu olduğunu söyledi. Bağımlılık zinciri şöyledir: $z$, $x$ ve $y$'ye bağlıdır; $x$ ve $y$ de $r$ ve $\theta$'ya bağlıdır. $z$'nin $\theta$'ya bağlılığı iki yoldan gelir: $x$ üzerinden ve $y$ üzerinden.

**Çözüm:**

- Zincir kuralı: $\dfrac{\partial z}{\partial\theta}=\dfrac{\partial z}{\partial x}\dfrac{\partial x}{\partial\theta}+\dfrac{\partial z}{\partial y}\dfrac{\partial y}{\partial\theta}$.
- $\dfrac{\partial z}{\partial x}$ ve $\dfrac{\partial z}{\partial y}$ bilinmiyor, ama $x$ ve $y$'nin $\theta$'ya göre türevleri biliniyor. $r$ sabit gibi alınır:
  - $\dfrac{\partial x}{\partial\theta}=-r\sin\theta=-y$.
  - $\dfrac{\partial y}{\partial\theta}=r\cos\theta=x$.
- Yerine konunca: $\dfrac{\partial z}{\partial\theta}=-y\dfrac{\partial z}{\partial x}+x\dfrac{\partial z}{\partial y}=-\left(y\dfrac{\partial z}{\partial x}-x\dfrac{\partial z}{\partial y}\right)$ (ara adım eklendi).
- Parantez içi verilen denklemde sıfırdır.
- Sonuç: denklem $\dfrac{\partial z}{\partial\theta}=0$ biçimini alır.

Hoca testte bu sorunun "$\partial z/\partial\theta$ neye eşittir" diye sorulabileceğini söyledi. Notta bir ikinci yol da vardı. Hoca onun daha karışık olduğunu, anlattığı birinci yolun çok daha basit olduğunu ve akılda bunun kalması gerektiğini söyleyerek ikinci yolu vermedi.

### 8.2 Örnek 11: $\varphi$ ile kapalı tanımlanan fonksiyon

Hoca bunun da sınavda çıkmış sorulardan biri olduğunu söyledi ve "bu son dakikalar çok kıymetli" diyerek dikkat istedi.

**Soru:** $z=z(x,y)$ sabit olmayan bir fonksiyon olsun ve

$$\varphi\!\left(2x-z^2,\;y-\frac{z^3}{3}\right)=0$$

denklemiyle kapalı olarak tanımlansın. Buna göre

$$\frac{\partial z}{\partial x}+z\frac{\partial z}{\partial y}$$

ifadesi hangisidir?

**Hocanın yöntemi:** $\varphi$'nin ikinci bileşeni birincisinin bir fonksiyonu olarak yazılır. Bir $g$ türevlenebilir fonksiyonu için:

$$y-\frac{z^3}{3}=g(2x-z^2).$$

Her şey bir tarafa geçirilerek $F$ fonksiyonu tanımlanır:

$$F(x,y,z)=g(2x-z^2)-y+\frac{z^3}{3}=0.$$

Hoca bunun "işin en önemli noktası" olduğunu söyledi: kapalı ve karışık verilen fonksiyon böylece açık bir $F$'ye dönüşür ve istenen her türev rahatça bulunur.

**Çözüm:** $g'$ ile $g'(2x-z^2)$ kastedilir.

- $F_x$: İç fonksiyonun $x$'e göre türevi $2$'dir. $F_x=2g'$. Diğer terimlerde $x$ yoktur.
- $F_y$: $g$'nin içinde $y$ yoktur. $F_y=-1$.
- $F_z$: İç fonksiyonun $z$'ye göre türevi $-2z$'dir. $\dfrac{z^3}{3}$'ün türevi $z^2$'dir. $F_z=-2z\,g'+z^2$.
- $\dfrac{\partial z}{\partial x}=-\dfrac{F_x}{F_z}=-\dfrac{2g'}{z^2-2zg'}$.
- $\dfrac{\partial z}{\partial y}=-\dfrac{F_y}{F_z}=\dfrac{1}{z^2-2zg'}$.
- İstenen ifade (ara adım eklendi):

$$\frac{\partial z}{\partial x}+z\frac{\partial z}{\partial y}=\frac{-2g'+z}{z^2-2zg'}=\frac{z-2g'}{z(z-2g')}=\frac{1}{z}.$$

Sonuç: $\dfrac{1}{z}$. Şıklarda $1/z$ olan şık doğrudur.

Hoca bu soru için başka bir yolun da olduğunu, ama önce bu birinci yöntemi iyice hazmetmek gerektiğini, ikinci yolun ancak o zaman kolay anlaşılacağını söyledi. İkinci yolu bu derste anlatmadı.

> **Ek bilgi (derste anlatılmadı):** Hocanın adımı, $\varphi(u,v)=0$ bağıntısından $v$'nin $u$'nun bir fonksiyonu olarak çözülebildiği varsayımına dayanır (örneğin $\varphi_v\ne0$ iken). Sonucun $g$'den bağımsız çıkması önemlidir: hangi $\varphi$ alınırsa alınsın cevap $1/z$ olur. Bu tip sorularda cevabın keyfi fonksiyonu içermemesi, doğru yolda olunduğunun bir işaretidir.

## Örnek Sorular

Bu derste kare yoktur. Aşağıdaki sorular derste hocanın slayttan okuyup sözlü olarak sorduğu ve çözdüğü sorulardır. Çözümler yukarıdaki bölümlerdedir; burada kısaca tekrar edilir.

**Soru 1** (derste sözlü, 00:17:31): $f(x,y)=x^2+y^2$ fonksiyonunun kritik noktalarını bulup sınıflandırın ya da aşağıdakilerden hangisinin doğru olduğunu bulun.

> **Çözüm:** $f_x=2x=0$, $f_y=2y=0$ ise kritik nokta $(0,0)$. $f(h,k)-f(0,0)=h^2+k^2\ge0$. $(0,0)$ yerel minimumdur.

**Soru 2** (derste sözlü, 00:19:02): Kritik noktası $(0,0)$ olan ve $f(h,k)-f(0,0)=h^2-k^2$ veren bir fonksiyonda $(0,0)$ ne tür bir noktadır?
<!-- BELİRSİZ: Fonksiyon altyazıda okunmuyor. -->

> **Çözüm:** $h^2-k^2$'nin işareti belirli değildir. $(0,0)$ eyer noktasıdır.

**Soru 3** (derste sözlü, 00:22:48): $B^2-AC=0$ olursa ikinci türev testi ne söyler?

> **Çözüm:** Test sonuç vermez. Başka bir yönteme (örneğin $f(a+h,b+k)-f(a,b)$ farkının işaretine) geçilir.

**Soru 4** (derste sözlü, 00:23:25): $f(x,y)=2x^3-6xy+3y^2$ fonksiyonunun kritik noktalarını bulup sınıflandırın.

> **Çözüm:** Kritik noktalar $(0,0)$ ve $(1,1)$. $(0,0)$'da $B^2-AC=36>0$, eyer noktası. $(1,1)$'de $B^2-AC=-36<0$ ve $A=12>0$, yerel minimum.

**Soru 5** (derste sözlü, 00:26:39): $f(x,y)=x^3-3x^2+3xy^2-3y^2$ fonksiyonunun kritik noktalarını bulup sınıflandırın.

> **Çözüm:** $(0,0)$ yerel maksimum, $(2,0)$ yerel minimum, $(1,1)$ ve $(1,-1)$ eyer noktası.

**Soru 6** (derste sözlü, 00:55:36): $f(x,y)=e^x\sin y$ fonksiyonunun $(0,\pi/2)$ noktasında ikinci mertebe türevlerin bulunduğu terime kadar Taylor açılımı hangisidir?

> **Çözüm:** $f(x,y)\approx 1+x+\dfrac{x^2}{2}-\dfrac{1}{2}\left(y-\dfrac{\pi}{2}\right)^2$.

**Soru 7** (derste sözlü, 01:00:23): $w=x^2+y^2+z^2$, $z^3-xy+yz+y^3=1$ ise $(2,-1,1)$ noktasında $\left(\dfrac{\partial w}{\partial x}\right)_y$ nedir?

> **Çözüm:** $\dfrac{\partial w}{\partial x}=2x+2z\dfrac{y}{3z^2+y}$; noktada $4-1=3$.

**Soru 8** (derste sözlü, 01:03:42): $w=x^2+y-z+\sin t$, $t=x+y$ ise $\left(\dfrac{\partial w}{\partial x}\right)_{y,z}$ nedir?

> **Çözüm:** $2x+\cos(x+y)$.

**Soru 9** (derste sözlü, 01:05:51): $w=x^2+y^2+z^2$, $y\sin z+z\sin x=0$ ise $(0,1,\pi)$ noktasında $\left(\dfrac{\partial w}{\partial y}\right)_x$ nedir? Aynı noktada $\left(\dfrac{\partial w}{\partial y}\right)_z$ nedir?

> **Çözüm:** $\left(\dfrac{\partial w}{\partial y}\right)_x=2$ (derste çözüldü).

> **Çözüm (derste verilmedi):** $\left(\dfrac{\partial w}{\partial y}\right)_z=2y+2x\cdot\left(-\dfrac{\sin z}{z\cos x}\right)$; $(0,1,\pi)$'de $2$ (sympy ile doğrulandı).

**Soru 10** (derste sözlü, 01:10:06): $z=f(x,y)$, $x=r\cos\theta$, $y=r\sin\theta$ ise $y\dfrac{\partial z}{\partial x}-x\dfrac{\partial z}{\partial y}=0$ denklemi hangi şekli alır?

> **Çözüm:** $\dfrac{\partial z}{\partial\theta}=0$.

**Soru 11** (derste sözlü, 01:12:13): $z=z(x,y)$ sabit olmayan bir fonksiyon ve $\varphi\!\left(2x-z^2,\,y-\dfrac{z^3}{3}\right)=0$ ise $\dfrac{\partial z}{\partial x}+z\dfrac{\partial z}{\partial y}$ nedir?

> **Çözüm:** $\dfrac{1}{z}$.

## Dersin Toparlaması

Bu derste yeni konuya geçilmedi; çok değişkenli fonksiyonların türevleriyle ilgili konular sınav tipi sorularla pekiştirildi. Önce tek değişkenli fonksiyonlarda ekstremum bulmanın üç yolu (tanım, işaret tablosu, ikinci türev) hatırlatıldı. Sonra iki değişkenli fonksiyonlarda kritik nokta, yerel maksimum, yerel minimum ve eyer noktası tanımlandı. Kritik noktalar iki yolla sınıflandırıldı: $f(a+h,b+k)-f(a,b)$ farkının işaretine bakarak ve $A=f_{xx}$, $B=f_{xy}$, $C=f_{yy}$ ile kurulan ikinci türev testiyle. $B^2-AC=0$ olduğunda testin sonuç vermediği, bu yüzden bütün yöntemlerin bilinmesi gerektiği vurgulandı.

Ardından tek değişkenli Taylor ve Maclaurin açılımı hatırlatıldı ve iki değişkenli Taylor açılımı ikinci mertebe terimlere kadar yazıldı; $e^x\sin y$ örneğiyle uygulandı. Son kısımda kısıtlı değişkenlerle kısmi türev ($(\partial w/\partial x)_y$ gösterimi, bağımlı ve bağımsız değişken ayrımı, $-F_x/F_z$ formülü), kutupsal dönüşümle zincir kuralı ve $\varphi$ ile kapalı tanımlanan fonksiyon soruları çözüldü. Hoca dersi "bayramdan sonra görüşmek üzere" diyerek bitirdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
