# Ders 14 Genişletilmiş Notu: Yönlü Türev, Gradyan ve Vektör Uygulamaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Derse Giriş
- 2. Yönlü Türevin Tanımı
- 3. Gradyan Vektörü ve Yönlü Türevin Pratik Formülü
- 4. Yönlü Türev Bir Değişim Hızıdır
- 5. Gradyanın Anlamı: En Hızlı Artış, En Hızlı Azalış, Sıfır Değişim
- 6. Gradyan İçin Cebirsel Kurallar ve Üç Değişken
- 7. Yönlü Türev ve Gradyan Soruları
- 8. Doğru, Düzlem ve İzdüşüm Uygulamaları
- 9. Çıkmış Sınav Sorularından Seçmeler
- Örnek Sorular
- Dersin Toparlaması

## 1. Derse Giriş

Ders online olarak, hocanın ekran paylaşımı ve sanal tahta üzerinden yürüdü. Hoca önce bir önceki derste anlatılanlarla ilgili soru olup olmadığını sordu. Bir öğrenci, Bologna sayfasındaki konu listesinin güncel olup olmadığını ve vizeye hangi konuların gireceğini sordu. Hoca, matematik için sayfanın güncel olduğunu bildiğini, bir değişiklik olursa hemen bildirileceğini söyledi.

Bu dersin konusu yönlü türevdir (directional derivative). Hoca konuyu şöyle bağladı: Çok değişkenli bir fonksiyonda $x$'e göre ve $y$'ye göre kısmi türevler vardır. Bunlar yalnızca eksen yönlerindeki türevlerdir. Bir de herhangi bir yöndeki türev vardır. Buna yönlü türev denir.

Not: Hoca tahtaya ve slayta yazarak anlattı. Altyazıda yalnız sözlü kısım vardır. Bu dersin kareleri yoktur. Formüller sözlü anlatımdan kuruldu. Sözlü anlatımda geçmeyen fonksiyon ve noktalar kısa nottan alındı. Kısa nota göre bu bilgiler ekrandan doğrulanmıştır. Bu yerler metinde ayrıca belirtildi.

## 2. Yönlü Türevin Tanımı

### 2.1 Birim vektör

Yönlü türev her zaman bir **birim vektör** (unit vector) yönünde alınır. Hoca birim vektörü şöyle tanımladı: $\vec u=u_1\vec i+u_2\vec j$ vektörünün birim olması, boyunun 1 olması demektir:

$$|\vec u|=\sqrt{u_1^2+u_2^2}=1.$$

### 2.2 Tanım

Hoca $P_0(x_0,y_0)$ noktasından $\vec u$ yönünde geçen doğruyu parametrik olarak yazdı:

$$x=x_0+su_1,\qquad y=y_0+su_2.$$

Artık yalnız $x$'te ya da yalnız $y$'de bir artış yoktur. İki değişken de aynı anda $s$ ile orantılı artar. Fonksiyondaki artış $s$'ye bölünür ve $s\to0$ iken limit alınır.

**Tanım (yönlü türev):**

- $\vec u=u_1\vec i+u_2\vec j$ birim vektör olsun.
- $f(x,y)$ fonksiyonunun $P_0(x_0,y_0)$ noktasında $\vec u$ yönündeki türevi, limit varsa,
  $$D_{\vec u}f(P_0)=\lim_{s\to0}\frac{f(x_0+su_1,\;y_0+su_2)-f(x_0,y_0)}{s}$$
  ile tanımlanır.
- Bu limit varsa $f$'nin $P_0$'da $\vec u$ yönünde yönlü türevi vardır.

Hoca kısmi türevlerin de birer yönlü türev olduğunu vurguladı:

- $f_x$, $f$'nin $\vec i$ yönündeki ($x$ ekseni yönündeki) türevidir.
- $f_y$, $f$'nin $\vec j$ yönündeki türevidir.
- Üç değişkende $f_z$, $f$'nin $\vec k$ yönündeki türevidir.

### 2.3 Örnek 1: Tanımla yönlü türev

**Soru.** $f(x,y)=x^2+xy$ fonksiyonunun $P_0(1,2)$ noktasında $\vec u=\left(\tfrac1{\sqrt2},\tfrac1{\sqrt2}\right)$ yönündeki türevini tanımla hesaplayınız.

<!-- BELİRSİZ: Fonksiyon altyazıda "x'in karesi artı y çarpı x" diye geçiyor; P0 noktası açıkça söylenmiyor. x yerine 1 + s/√2, y yerine 2 + s/√2 yazıldığı ve f(P0) = 3 çıkarıldığı için P0 = (1,2) olarak alındı. -->

**Çözüm.**

- Önce vektörün birim olup olmadığına bakılır: $|\vec u|=\sqrt{\tfrac12+\tfrac12}=1$. Birim vektördür.
- $x=1+\tfrac{s}{\sqrt2}$, $y=2+\tfrac{s}{\sqrt2}$ yazılır. $f(1,2)=1+2=3$.
- Fonksiyona yerleştirelim (ara adım eklendi):
  $$f\!\left(1+\tfrac{s}{\sqrt2},\,2+\tfrac{s}{\sqrt2}\right)=\left(1+\tfrac{s}{\sqrt2}\right)^2+\left(1+\tfrac{s}{\sqrt2}\right)\left(2+\tfrac{s}{\sqrt2}\right)=3+\tfrac{5s}{\sqrt2}+s^2.$$
- Fark bölümü: $\dfrac{3+\frac{5s}{\sqrt2}+s^2-3}{s}=\dfrac5{\sqrt2}+s$.
- $s\to0$ iken limit:
  $$D_{\vec u}f(1,2)=\frac5{\sqrt2}.$$

### 2.4 Birim olmayan vektör

Hoca, vektör birim verilmezse ne yapılacağını gösterdi. Örneğin yön $\vec v=\vec i+\vec j$ olarak verilsin. Boyu $|\vec v|=\sqrt{1^2+1^2}=\sqrt2\neq1$ olduğundan birim değildir. Her vektör kendi boyuna (normuna) bölünerek birim vektöre dönüştürülür:

$$\vec u=\frac{\vec v}{|\vec v|}=\frac1{\sqrt2}\vec i+\frac1{\sqrt2}\vec j.$$

> **Hocanın vurgusu:** Yönlü türev almadan önce vektörün birim olup olmadığına mutlaka bakın. "Burası çok çok önemli." Birim değilse önce boyuna bölün.

## 3. Gradyan Vektörü ve Yönlü Türevin Pratik Formülü

### 3.1 Gradyan

Hoca bir önceki derste bahsettiği gradyan vektörünü (gradient vector) hatırlattı. $f(x,y)$ için gradyan $\operatorname{grad}f$ ya da $\nabla f$ ("nabla $f$") ile gösterilir:

$$\nabla f=f_x\,\vec i+f_y\,\vec j.$$

Üç değişken olursa buna $f_z\,\vec k$ eklenir.

### 3.2 Teorem

**Teorem (gradyanla yönlü türev):**

- $f(x,y)$, $P_0$'ı içeren bir bölgede türevlenebilir olsun.
- O zaman $f$'nin $P_0$'da $\vec u$ birim vektörü yönündeki türevi
  $$D_{\vec u}f(P_0)=\nabla f(P_0)\cdot\vec u$$
  olur. Yani gradyan ile birim vektörün iç çarpımıdır.

Hoca bunun pratikte en çok kullanılan formül olduğunu söyledi. Tanımdaki limit yerine genellikle bu formül kullanılır.

> **Ek bilgi (derste anlatılmadı):** Örnek 1 bu formülle de kontrol edilebilir. $\nabla f=(2x+y,\;x)$ olduğundan $\nabla f(1,2)=(4,1)$ olur. $(4,1)\cdot\left(\tfrac1{\sqrt2},\tfrac1{\sqrt2}\right)=\tfrac5{\sqrt2}$ çıkar. Bu, tanımla bulunan sonuçla aynıdır.

### 3.3 Örnek 2: Tahtada çözülen soru

Hoca slayttaki bir örneği okumaya başladı, sonra boş tahtayı açıp bir soruyu adım adım çözdü. Tahtada çözdüğü fonksiyon slayttakinden farklıdır (bkz. Örnek 3).

**Soru.** $f(x,y)=xy+x^2$ fonksiyonunun $(1,2)$ noktasında $\vec v=3\vec i-4\vec j$ yönündeki türevini bulunuz.

**Çözüm.**

- Formül: $D_{\vec u}f(P_0)=\nabla f(P_0)\cdot\vec u$.
- Kısmi türevler: $f_x=y+2x$, $f_y=x$. Yani $\nabla f=(y+2x)\,\vec i+x\,\vec j$.
- $(1,2)$ noktasında: $f_x=2+2=4$, $f_y=1$. Yani $\nabla f(1,2)=4\vec i+\vec j=(4,1)$.
- Vektör birim mi? $|\vec v|=\sqrt{3^2+(-4)^2}=5$. Birim değildir.
- Birim vektör: $\vec u=\dfrac{\vec v}{|\vec v|}=\left(\tfrac35,-\tfrac45\right)$.
- İç çarpım: birinci bileşen birinciyle, ikinci bileşen ikinciyle çarpılıp toplanır:
  $$D_{\vec u}f(1,2)=4\cdot\frac35+1\cdot\left(-\frac45\right)=\frac{12}5-\frac45=\frac85.$$

Hoca özetle şunu söyledi: Vektör birim değilse birim hale getirip öyle çözüyoruz.

### 3.4 Örnek 3: Slayttaki soru

Ekrandaki ilk örnekte fonksiyon $f(x,y)=xe^y+\cos(xy)$ idi. Hoca aradan sonra "üstteki soru" diye bu soruya döndü ve sonucu slayttan okudu: gradyan bulunmuş, noktada değeri hesaplanmış, birim vektörle iç çarpımı alınmış ve sonuç $-1$ çıkmış.

<!-- BELİRSİZ: Altyazıda fonksiyon "x çarpı e üzeri y, kosinüs x y" biçiminde parçalı geçiyor; nokta ve yön söylenmiyor. Nokta (2,0) ve yön 3i - 4j kısa nottan alındı (kısa nota göre ekrandan doğrulanmış). -->

**Soru.** $f(x,y)=xe^y+\cos(xy)$ fonksiyonunun $(2,0)$ noktasında $\vec v=3\vec i-4\vec j$ yönündeki türevini bulunuz.

**Çözüm.**

- $\vec u=\tfrac35\vec i-\tfrac45\vec j$.
- $f_x=e^y-y\sin(xy)$, $f_y=xe^y-x\sin(xy)$.
- $\nabla f(2,0)=(1-0)\,\vec i+(2-0)\,\vec j=\vec i+2\vec j$.
- $D_{\vec u}f(2,0)=1\cdot\tfrac35+2\cdot\left(-\tfrac45\right)=\tfrac35-\tfrac85=-1$.

## 4. Yönlü Türev Bir Değişim Hızıdır

Hoca bunları "önemli notlar" olarak verdi. $D_{\vec u}f(P_0)$ değerine şu adlar da verilir:

- $f$'nin $P_0$'da $\vec u$ yönündeki **yönlü türevi**,
- $\vec u$ yönündeki **artış hızı** (değer pozitifse),
- $\vec u$ yönündeki **azalış hızı** (değer negatifse),
- genel olarak $\vec u$ yönündeki **değişim oranı**.

Yani yönlü türev, fonksiyonun o yönde ne kadar hızlı arttığını ya da azaldığını söyler.

## 5. Gradyanın Anlamı: En Hızlı Artış, En Hızlı Azalış, Sıfır Değişim

### 5.1 Açıyla yazılış

İki vektörün iç çarpımı, boyların çarpımı ile aradaki açının kosinüsünün çarpımıdır. $\theta$, $\nabla f$ ile $\vec u$ arasındaki açı olsun. $|\vec u|=1$ olduğundan

$$D_{\vec u}f=\nabla f\cdot\vec u=|\nabla f|\,|\vec u|\cos\theta=|\nabla f|\cos\theta.$$

Değişim yalnız $\cos\theta$'nın alacağı değere göre değişir. Hoca buradan üç sonuç çıkardı.

**Özellikler (gradyanın anlamı):**

- **En hızlı artış:** $\theta=0$ iken $\cos\theta=1$ olur. $\vec u$ ile $\nabla f$ aynı yöndedir. $f$, $P$'deki gradyan vektörünün yönünde en hızlı artar. Bu yöndeki türev $|\nabla f|$'dir. Yön: $\vec u=\dfrac{\nabla f}{|\nabla f|}$.
- **En hızlı azalış:** $\theta=\pi$ (180 derece) iken $\cos\theta=-1$ olur. $f$, $-\nabla f$ yönünde en hızlı azalır. Bu yöndeki türev $-|\nabla f|$'dir.
- **Sıfır değişim:** $\theta=\pi/2$ (90 derece) iken $\cos\theta=0$ olur. $\nabla f\neq\vec0$ ise gradyana dik olan her $\vec u$ yönü, $f$'nin sıfır değişim yönüdür.

> **Hocanın vurgusu:** Bu bilgiler "çok önemli, çok kıymetli". Şıklı bir soru olarak da sorulabilir.

### 5.2 Örnek 4: En çok artan, en çok azalan, sıfır değişim yönü

**Soru.** $f(x,y)=\dfrac{x^2}2+\dfrac{y^2}2$ fonksiyonu için $(1,1)$ noktasında aşağıdaki yönleri bulunuz: (a) $f$'nin en çok arttığı yön, (b) en çok azaldığı yön, (c) değişimin sıfır olduğu yön.

**Çözüm.**

- $f_x=\tfrac{2x}2=x$, $f_y=y$. Hoca "ikiler sadeleşir, $x$ kalır" dedi.
- $\nabla f(1,1)=\vec i+\vec j$, $|\nabla f|=\sqrt2$.
- (a) En çok artış $\nabla f$ yönündedir: $\vec u=\dfrac{\vec i+\vec j}{\sqrt2}=\left(\tfrac1{\sqrt2},\tfrac1{\sqrt2}\right)$. Bu yöndeki türev $\sqrt2$'dir (ara adım eklendi).
- (b) En çok azalış bunun tersidir: $\vec u=\left(-\tfrac1{\sqrt2},-\tfrac1{\sqrt2}\right)$, türev $-\sqrt2$ (ara adım eklendi).
- (c) Sıfır değişim için $\nabla f\cdot\vec u=0$ olmalıdır. Gradyana dik birim vektörler: $\vec u=\pm\left(\tfrac1{\sqrt2},-\tfrac1{\sqrt2}\right)$.

<!-- BELİRSİZ: Bu örneğin (a)-(c) sonuçlarını hoca slayttan okudu; altyazıda yalnız yöntem geçiyor. Sonuçlar kısa notla ve hesapla doğrulandı. -->

## 6. Gradyan İçin Cebirsel Kurallar ve Üç Değişken

### 6.1 Cebirsel kurallar

Hoca aradan hemen önce gradyan için cebirsel kuralları verdi ve bunları tek değişkenli türev kurallarına benzetti.

**Kurallar ($f$, $g$ türevlenebilir, $k$ sabit):**

- Toplam ve fark: $\nabla(f\pm g)=\nabla f\pm\nabla g$. İki fonksiyonun toplamının ya da farkının gradyanı, gradyanlarının toplamı ya da farkıdır.
- Sabitle çarpım: $\nabla(kf)=k\,\nabla f$.
- Çarpım: $\nabla(fg)=f\,\nabla g+g\,\nabla f$. Birincinin gradyanı çarpı ikinci, artı ikincinin gradyanı çarpı birinci.
- Bölüm: $\nabla\!\left(\dfrac fg\right)=\dfrac{g\,\nabla f-f\,\nabla g}{g^2}$. Payın gradyanı çarpı payda, eksi paydanın gradyanı çarpı pay, bölü paydanın karesi.

### 6.2 Üç değişkenli fonksiyonlar

$f(x,y,z)$ ve $\vec u=u_1\vec i+u_2\vec j+u_3\vec k$ birim vektörü için:

$$\nabla f=f_x\,\vec i+f_y\,\vec j+f_z\,\vec k,\qquad D_{\vec u}f=\nabla f\cdot\vec u=f_xu_1+f_yu_2+f_zu_3.$$

### 6.3 Örnek 5: Üç değişkenli yönlü türev ve en hızlı değişim

Hoca bunu "çok güzel soru, orijinal soru" diye tanıttı.

<!-- BELİRSİZ: Fonksiyon altyazıda "x küp, x y kare, z" biçiminde parçalı geçiyor; işaretler kısa nottan alındı. f_x = 3x² − y² ve sonuçlar (4/7, 3) altyazıyla uyumlu. -->

**Soru.** $f(x,y,z)=x^3-xy^2-z$ fonksiyonunun $P_0(1,1,0)$ noktasında $\vec v=2\vec i-3\vec j+6\vec k$ yönündeki türevini bulunuz. $f$, $P_0$'da en hızlı hangi yönde değişir? Bu yöndeki değişim oranı nedir?

**Çözüm.**

- Vektör birim mi? $|\vec v|=\sqrt{2^2+3^2+6^2}=\sqrt{49}=7$. Birim değildir.
- Birim vektör: $\vec u=\dfrac{\vec v}{7}=\tfrac27\vec i-\tfrac37\vec j+\tfrac67\vec k$.
- Kısmi türevler: $f_x=3x^2-y^2$, $f_y=-2xy$, $f_z=-1$.
- $\nabla f(1,1,0)=2\vec i-2\vec j-\vec k$.
- Yönlü türev:
  $$D_{\vec u}f(P_0)=2\cdot\frac27+(-2)\cdot\left(-\frac37\right)+(-1)\cdot\frac67=\frac47+\frac67-\frac67=\frac47.$$
- $f$ en hızlı $\nabla f=2\vec i-2\vec j-\vec k$ yönünde artar. Hız: $|\nabla f|=\sqrt{4+4+1}=3$.
- $f$ en hızlı $-\nabla f$ yönünde azalır. Bu yöndeki değişim oranı $-3$'tür.

## 7. Yönlü Türev ve Gradyan Soruları

### 7.1 Örnek 6: En büyük, en küçük ve sıfır yönlü türev

**Soru.** $f(x,y)=x^2-xy+y^2-y$ fonksiyonu için $(1,-1)$ noktasında $D_{\vec u}f$'nin en büyük ve en küçük değerlerini, bu değerlerin alındığı $\vec u$ yönlerini ve $D_{\vec u}f=0$ olan yönleri bulunuz.

<!-- BELİRSİZ: Fonksiyon altyazıda okunmuyor; yalnız kısmi türevler (2x − y ve −x + 2y − 1) söyleniyor. Fonksiyon kısa nottan alındı ve bu türevlerle uyumlu. -->

**Çözüm.**

- İki değişken olduğu için gradyanın iki bileşeni vardır:
  $$\nabla f=(2x-y)\,\vec i+(-x+2y-1)\,\vec j.$$
- $x=1$, $y=-1$ konursa: $\nabla f(1,-1)=3\vec i-4\vec j$.
- $|\nabla f|=\sqrt{3^2+(-4)^2}=5$.
- En büyük değer: $D_{\vec u}f=5$, yön $\vec u=\dfrac{\nabla f}{|\nabla f|}=\left(\tfrac35,-\tfrac45\right)$.
- En küçük değer: $D_{\vec u}f=-5$, yön $\vec u=\left(-\tfrac35,\tfrac45\right)$.
- Sıfır değişim: $\vec u=a\vec i+b\vec j$ olsun. Birim olduğu için $a^2+b^2=1$. Ayrıca
  $$\nabla f\cdot\vec u=3a-4b=0\ \Rightarrow\ a=\tfrac43b.$$
- Birim koşuluna yerleştirince (ara adım eklendi): $\tfrac{16}9b^2+b^2=1\Rightarrow b^2=\tfrac9{25}\Rightarrow b=\pm\tfrac35$, $a=\pm\tfrac45$.
- İki yön vardır: $\vec u_1=\tfrac45\vec i+\tfrac35\vec j$ ve $\vec u_2=-\vec u_1=-\tfrac45\vec i-\tfrac35\vec j$.

> **Ders sonrası not:** Bu kısımda altyazı "a eksi 4 bölü 3, artı 4 bölü 3" gibi bozuk geçiyor. Doğru sonuç $\vec u=\pm\left(\tfrac45,\tfrac35\right)$'tir (sympy ile doğrulandı).

Hoca sonra anlamayan olursa soruyu tahtada yeniden çözebileceğini söyledi. Bir öğrenci anlaşıldığını söyledi.

### 7.2 Birim olmayan yön vektörüyle başka bir soru

Hoca ekranda "yine gelebilecek" bir soru daha gösterdi: bir fonksiyonun bir noktadaki, $\vec u$ vektörü yönündeki türevi. Burada $\vec u$ birim değildi: boyu $\sqrt{4^2+3^2}=5$ çıktı. Bu yüzden birim vektör $\left(\tfrac45,\tfrac35\right)$ alındı. Sonra $D_{\vec u}f(P_0)=\nabla f(P_0)\cdot\vec u$ formülü uygulandı. Hoca sonucu ekranda gösterdi.

<!-- BELİRSİZ: Bu sorunun fonksiyonu, noktası ve sonucu altyazıda geçmiyor. Kısa notta da bu soru yok. -->

### 7.3 Örnek 7: Fonksiyon verilmeden yönlü türev

Hoca bunu "ters soru" olarak tanıttı. Fonksiyon verilmez. Bir fonksiyon vardır ama ne olduğunu bilmiyoruz. Yalnız verilen bilgilerle hareket ederiz. Hoca, bu sorunun önceki soruların "mezcedilmiş hali" olduğunu, konuyu anlayan birinin rahatça çözebileceğini söyledi.

**Soru.** $f$ fonksiyonunun $P_0$ noktasında $\vec i+\vec j$ yönündeki türevi $2\sqrt2$, $-2\vec j$ yönündeki türevi $-3$'tür. $f$'nin $P_0$'da $-\vec i-2\vec j$ yönündeki türevi nedir?

**Çözüm.**

- Gradyanı bilinmeyenlerle yazalım: $\nabla f(P_0)=a\,\vec i+b\,\vec j$.
- $\vec i+\vec j$ yönü: boyu $\sqrt{1^2+1^2}=\sqrt2$. Birim vektör $\left(\tfrac1{\sqrt2},\tfrac1{\sqrt2}\right)$.
  $$\frac{a+b}{\sqrt2}=2\sqrt2\ \Rightarrow\ a+b=4.$$
- $-2\vec j$ yönü: birim vektör $-\vec j$.
  $$-b=-3\ \Rightarrow\ b=3,\qquad a=1.$$
- İstenen yön $-\vec i-2\vec j$: boyu $\sqrt5$, birim vektör $\left(-\tfrac1{\sqrt5},-\tfrac2{\sqrt5}\right)$.
- Sonuç (ara adım eklendi):
  $$D_{\vec u}f(P_0)=1\cdot\left(-\frac1{\sqrt5}\right)+3\cdot\left(-\frac2{\sqrt5}\right)=-\frac7{\sqrt5}.$$

Hoca, $a=1$, $b=3$ bulunduktan sonra üçüncü istenenin aynı şekilde yapıldığını söyledi. Son sayıyı sözlü okumadı; sonuç sympy ile kontrol edildi. Hoca soruyu öğrencilerle birlikte yeniden çözmeyi önerdi, ama mikrofonu açan olmadı.

### 7.4 Örnek 8: En hızlı artış ve azalış yönleri

<!-- BELİRSİZ: Fonksiyon ve nokta altyazıda geçmiyor; yalnız sonuç "2j" söyleniyor. f ve P0 kısa nottan alındı (kısa nota göre ekrandan doğrulanmış). -->

**Soru.** $f(x,y)=x^2y+e^{xy}\sin y$ fonksiyonunun $P_0(1,0)$ noktasında en hızlı arttığı ve en hızlı azaldığı yönleri bulunuz.

**Çözüm.**

- $f_x=2xy+ye^{xy}\sin y$, $f_y=x^2+xe^{xy}\sin y+e^{xy}\cos y$.
- $\nabla f(1,0)=0\,\vec i+(1+0+1)\,\vec j=2\vec j$.
- En hızlı artış, gradyan yönündeki birim vektördür: $\vec u=\dfrac{2\vec j}{2}=\vec j$.
- En hızlı azalış ters yöndedir: $\vec u=-\vec j$.

### 7.5 Üç değişkenli bir hız sorusu

Hoca üç değişkenli başka bir fonksiyon için de aynı yöntemi kullandı: $\nabla f$ bulundu, $\vec u$ birim vektörüyle iç çarpımı alındı. Bu çarpım, $f$'nin $P$ noktasında $\vec u$ yönündeki türevidir. Sonuç $3$ çıktı.

<!-- BELİRSİZ: Bu sorunun fonksiyonu, noktası ve yönü altyazıda geçmiyor. -->

## 8. Doğru, Düzlem ve İzdüşüm Uygulamaları

### 8.1 Örnek 9: İki doğrunun belirlediği düzlem

<!-- BELİRSİZ: Doğru denklemleri altyazıda parçalı geçiyor ("eksi bir t, ... iki ... t"); tam denklemler kısa nottan alındı (kısa nota göre ekrandan doğrulanmış). Yön vektörleri (1,1,−1), (−4,2,−2) ve normal (0,6,6) altyazıyla uyumlu. -->

**Soru.** $L_1:\ x=-1+t,\ y=2+t,\ z=1-t$ ve $L_2:\ x=1-4s,\ y=1+2s,\ z=2-2s$ doğrularının belirlediği düzlemi bulunuz.

**Çözüm.**

- Yön vektörleri, parametrenin katsayılarıdır: $\vec v_1=(1,1,-1)$, $\vec v_2=(-4,2,-2)$.
- Bu iki vektör düzlemin üzerindedir. Düzlemin normali ikisine de diktir.
- İki vektöre dik vektör, vektörel çarpımdır. Hoca $\vec i,\vec j,\vec k$ ile determinantı yazdı:
  $$\vec n=\vec v_1\times\vec v_2=\begin{vmatrix}\vec i&\vec j&\vec k\\1&1&-1\\-4&2&-2\end{vmatrix}=0\,\vec i+6\,\vec j+6\,\vec k.$$
- Düzlem üzerinde bir nokta: $L_1$'de $t=0$ alınırsa $P_0(-1,2,1)$.
- Hoca düzlem denkleminin nasıl kurulduğunu hatırlattı: Düzlemde değişken bir $P(x,y,z)$ noktası alınır. $\overrightarrow{P_0P}=(x-x_0,\,y-y_0,\,z-z_0)$ düzlemde olduğu için normale diktir. İç çarpımları sıfırdır:
  $$\vec n\cdot\overrightarrow{P_0P}=0\ \Rightarrow\ 0(x-x_0)+6(y-y_0)+6(z-z_0)=0.$$
- Noktayı koyunca (ara adım eklendi): $6(y-2)+6(z-1)=0\Rightarrow 6y+6z=18\Rightarrow y+z=3$.

> **Ders sonrası not:** İki doğru $(-1,2,1)$ noktasında kesişir ($L_1$'de $t=0$, $L_2$'de $s=\tfrac12$). Bu yüzden tek bir düzlem belirlerler. Bu nokta $L_2$ için de sağlanır: $1-4\cdot\tfrac12=-1$, $1+2\cdot\tfrac12=2$, $2-2\cdot\tfrac12=1$.

### 8.2 Örnek 10: Noktanın doğruya uzaklığı

<!-- BELİRSİZ: Altyazıda P noktası ve doğru tam okunmuyor; yalnız "t = 1 için 4, −2", "12'den 2 çıkarsan 10" ve yön katsayıları 4, −2, 2 geçiyor. P(0,0,12) ve doğru denklemi kısa nottan alındı. -->

**Soru.** $P(0,0,12)$ noktasının $L:\ x=4t,\ y=-2t,\ z=2t$ doğrusuna uzaklığını bulunuz.

**Çözüm.**

- Doğru üzerinde bir nokta: $t=1$ için $Q(4,-2,2)$.
- $\overrightarrow{QP}=P-Q=(0-4,\,0+2,\,12-2)=(-4,2,10)$. Hoca "12'den 2 çıkarsan 10 kalır" dedi.
- Doğrunun yön vektörü, $t$'nin katsayıları: $\vec v=(4,-2,2)$.
- $\theta$, $\overrightarrow{QP}$ ile $\vec v$ arasındaki açı olsun. Uzaklık $d=|\overrightarrow{QP}|\sin\theta$ olur. Vektörel çarpımın boyu $|\overrightarrow{QP}|\,|\vec v|\sin\theta$ olduğundan
  $$d=\frac{|\overrightarrow{QP}\times\vec v|}{|\vec v|}.$$
- Vektörel çarpım (ara adım eklendi): $\overrightarrow{QP}\times\vec v=(24,48,0)$, boyu $\sqrt{576+2304}=24\sqrt5$.
- $|\vec v|=\sqrt{16+4+4}=\sqrt{24}$.
- $d=\dfrac{24\sqrt5}{\sqrt{24}}=\sqrt{120}=2\sqrt{30}$.

> **Ek bilgi (derste anlatılmadı):** Bu doğru $t=0$'da orijinden geçer. Bu yüzden $Q=(0,0,0)$ alınsa da aynı uzaklık bulunur. Uzaklık, doğru üzerinde hangi nokta seçilirse seçilsin değişmez.

### 8.3 Örnek 11: Noktanın düzleme uzaklığı

**Soru.** Bir $S$ noktasının $x+2y+2z=13$ düzlemine uzaklığını bulunuz.

<!-- BELİRSİZ: S noktasının koordinatları ve sonuç altyazıda geçmiyor. -->

**Çözüm yolu (derste anlatıldığı kadar).**

- Düzlemde bir nokta: $y=z=0$ alınırsa $x=13$. Yani $(13,0,0)$ düzlemdedir.
- Düzlemin normali, $x$, $y$, $z$'nin katsayılarıdır: $ax+by+cz=d$ düzleminde $\vec n=(a,b,c)$. Burada $\vec n=(1,2,2)$.
- Bir noktası ve normali belli olan düzlem için uzaklık, bu noktadan $S$'ye giden vektör ile normal kullanılarak bulunur. Hoca hesabı ekrandan gösterdi.

> **Ek bilgi (derste anlatılmadı):** Bu yöntemin formülü genellikle şöyle yazılır: düzlemdeki bir $P$ noktası için $d=\dfrac{|\overrightarrow{PS}\cdot\vec n|}{|\vec n|}$. Yani uzaklık, $\overrightarrow{PS}$ vektörünün normal üzerine izdüşümünün boyudur.

### 8.4 İzdüşüm

Hoca bir vektörün başka bir vektör üzerine izdüşümünü (projection) hatırlattı. $\vec u$'nun $\vec v$ üzerine izdüşümü:

$$\operatorname{proj}_{\vec v}\vec u=\frac{\vec u\cdot\vec v}{|\vec v|^2}\,\vec v.$$

Ekrandaki soruda vektörler bu formüle yerleştirildi: iç çarpım alındı, $\vec v$'nin boyu bulundu ve sonuç yazıldı. Hoca bu tür işlemsel sorulardan sınavda soru gelebileceğini söyledi.

<!-- BELİRSİZ: İzdüşüm sorusunun vektörleri ve sonucu altyazıda geçmiyor. -->

## 9. Çıkmış Sınav Sorularından Seçmeler

Dersin son bölümünde hoca ekranda geçmiş sınav sorularını gösterdi.

### 9.1 Örnek 12: Sınav sorusu, en hızlı değişim yönleri

<!-- BELİRSİZ: Fonksiyon altyazıda "x bölü y, eksi y z" diye geçiyor ve gradyan "1/y, −x/y² − z, −y" diye okunuyor. P noktası söylenmiyor; P(4,1,1) kısa nottan alındı (kısa nota göre ekrandan doğrulanmış). -->

**Soru.** $y\neq0$ olmak üzere $f(x,y,z)=\dfrac xy-yz$ fonksiyonu veriliyor. $f$, $P(4,1,1)$ noktasında en hızlı olarak hangi yönlerde değişir? Bu yönlerdeki değişim hızları nedir?

**Çözüm.**

- Gradyan: $\nabla f=f_x\,\vec i+f_y\,\vec j+f_z\,\vec k=\dfrac1y\,\vec i+\left(-\dfrac x{y^2}-z\right)\vec j-y\,\vec k$.
- $P(4,1,1)$'de: $\nabla f(P)=\vec i-5\vec j-\vec k$.
- Uzunluk: $|\nabla f(P)|=\sqrt{1+25+1}=\sqrt{27}=3\sqrt3\approx5{,}196$.
- $f$ en hızlı $\nabla f=\vec i-5\vec j-\vec k$ yönünde artar. Hız $3\sqrt3$.
- $f$ en hızlı $-\nabla f$ yönünde azalır. Hız $-3\sqrt3$.

> **Ders sonrası not:** Hoca gradyanın uzunluğunu sözlü olarak önce "3,43", sonra "artı 3,3 ya da eksi 3,3" diye okudu. Doğrusu $|\nabla f(P)|=\sqrt{27}=3\sqrt3\approx5{,}196$'dır (sympy ile doğrulandı). Bu sayılar büyük olasılıkla ekrandaki $3\sqrt3$ ifadesinin sözlü okunuşundan kaynaklanıyor.

Hoca burada öğrencilere soru sormaktan çekinmemelerini söyledi. Ona göre ders bir "bilim atölyesi"dir. Okunan şey soruya dönüştürülmedikçe hafızaya yerleşmez.

### 9.2 Örnek 13: Kısmi türevin tanımla hesabı

**Soru.** Parçalı tanımlı bir $f(x,y)$ fonksiyonunun $(0,0)$ noktasındaki kısmi türevleri isteniyor.

<!-- BELİRSİZ: Fonksiyonun kendisi altyazıda geçmiyor. -->

**Çözüm yolu.**

- Kısmi türevin tanımı kullanılır:
  $$f_x(0,0)=\lim_{h\to0}\frac{f(h,0)-f(0,0)}h,\qquad f_y(0,0)=\lim_{h\to0}\frac{f(0,h)-f(0,0)}h.$$
- $x$'e göre limit $0$ çıktı: $f_x(0,0)=0$.
- $y$'ye göre limitte $h\to0$ iken $\tfrac10$ biçimi çıktı. Bu tanımsızdır. Yani $f_y(0,0)$ yoktur.
- Doğru şık buna göre işaretlendi.

Hoca bunun ardından "yine 16 final sorusu" dedi.

<!-- BELİRSİZ: "16 final sorusu" ifadesinin bu kısmi türev sorusunu mu, sıradaki kuvvet serisi sorusunu mu kastettiği altyazıdan anlaşılmıyor. -->

### 9.3 Örnek 14: Kuvvet serisinin yakınsaklık yarıçapı

<!-- BELİRSİZ: Serinin genel terimi altyazıda söylenmiyor; kısa nottan alındı (kısa nota göre ekrandan doğrulanmış). Sonuç b = ±1/3 altyazıyla uyumlu. -->

**Soru.** $\displaystyle\sum_{n=2}^{\infty}\frac{b^nx^n}{\ln n}$ kuvvet serisinin yakınsaklık yarıçapının $3$ olması için $b$ sabiti hangi değerleri almalıdır?

**Çözüm.**

- Genel terim: $a_n=\dfrac{b^nx^n}{\ln n}$.
- Oran testi kullanılır (ara adım eklendi):
  $$\lim_{n\to\infty}\left|\frac{a_{n+1}}{a_n}\right|=\lim_{n\to\infty}\frac{\ln n}{\ln(n+1)}\,|b|\,|x|=|b|\,|x|.$$
- Yakınsaklık için bu limit 1'den küçük olmalıdır: $|b|\,|x|<1\Rightarrow|x|<\dfrac1{|b|}$.
- Yarıçap $\dfrac1{|b|}=3$ olmalıdır. Yani $|b|=\tfrac13$, $b=\pm\tfrac13$.

### 9.4 Parametrik eğrinin yay uzunluğu

Ekranda bir parametrik eğri ve $-1\le t\le1$ aralığı verilmişti. Eğrinin bu aralıktaki parçasının yay uzunluğu isteniyordu. Hoca formülü hatırlattı: türevler alınır, karelerinin toplamının karekökü integre edilir:

$$L=\int_{-1}^{1}\sqrt{x'(t)^2+y'(t)^2}\,dt.$$

<!-- BELİRSİZ: Eğrinin denklemi ve sonuç altyazıda geçmiyor. -->

> **Hocanın vurgusu:** Şıklarda doğru cevabı hızlı bulmak için her konudan 10, 20, 30 soru çözmek gerekir. Bu sorular hem internette hem ders materyalinde vardır.

### 9.5 Çok değişkenli fonksiyonlarda limit

> **Hocanın vurgusu:** Çok değişkenli fonksiyonlarda limit sorusu sınavda "mutlaka" geliyor.

Yöntem şöyledir:

- Önce eksenler boyunca yaklaşılır: $x$ ekseni ($y=0$) ve $y$ ekseni ($x=0$).
- Sonra $y=mx$ doğruları boyunca yaklaşılır. Hoca bunu "en önemli yol" olarak andı.
- Sonuç $m$'ye bağlı çıkıyorsa limit yoktur.
- Hoca, $m$'ye bağlı olmayan bir sonuç çıkarsa limitin var olduğunu söyledi.

> **Ders sonrası not:** Hoca "$m$'ye bağlı değilse limit vardır" dedi; doğrusu, bu durumda limit yalnız var olabilir. Farklı yollarda aynı sonucun çıkması limitin varlığını kanıtlamaz, çünkü denenmeyen bir yolda (örneğin $y=mx^2$) farklı sonuç çıkabilir. Varlık büyük olasılıkla tanımla ya da sıkıştırma ile gösterilmelidir.

### 9.6 Zincir kuralı

Son soru zincir kuralı ile ilgiliydi. Hoca bu konuyu bir önceki derste gösterdiğini söyledi ve soruyu çözmeden geçti.

## Örnek Sorular

Bu derste kare yoktur. Sorular yalnız derste sözlü sorulan ya da hocanın sesli okuduğu sorulardan alınmıştır.

**Soru 1** (derste sözlü, 00:14:38). Hoca tahtadaki örnekte öğrencilere sordu: $f(x,y)=xy+x^2$ için $f_x$ nedir? $(1,2)$ noktasında $\vec v=3\vec i-4\vec j$ yönündeki türev nedir?

- Çözüm (derste verildi): $f_x=y+2x$, $f_y=x$, $\nabla f(1,2)=(4,1)$. $\vec u=\left(\tfrac35,-\tfrac45\right)$. $D_{\vec u}f=\tfrac{12}5-\tfrac45=\tfrac85$. Ayrıntı Örnek 2'dedir.

**Soru 2** (derste sözlü, 00:29:34). $f(x,y,z)=x^3-xy^2-z$ fonksiyonunun $(1,1,0)$ noktasında $\vec v=2\vec i-3\vec j+6\vec k$ yönündeki türevi nedir? $f$, bu noktada en hızlı hangi yönde değişir, değişim oranı nedir?

<!-- BELİRSİZ: Fonksiyonun işaretleri altyazıda tam okunmuyor; kısa nottan alındı. -->

- Çözüm (derste verildi): $\vec u=\left(\tfrac27,-\tfrac37,\tfrac67\right)$, $\nabla f=(2,-2,-1)$, $D_{\vec u}f=\tfrac47$. En hızlı artış $\nabla f$ yönünde, hız $3$. En hızlı azalış $-\nabla f$ yönünde, hız $-3$. Ayrıntı Örnek 5'tedir.

**Soru 3** (derste sözlü, 00:54:56). Bir fonksiyon için $D_{\vec u}f$'nin en büyük ve en küçük değerlerini, bunların alındığı $\vec u$ yönlerini ve $D_{\vec u}f=0$ olan yönleri bulunuz. Nokta $(1,-1)$'dir.

<!-- BELİRSİZ: Fonksiyon altyazıda okunmuyor; kısa nottaki f = x² − xy + y² − y, söylenen kısmi türevlerle uyumlu. -->

- Çözüm (derste verildi): $\nabla f(1,-1)=(3,-4)$. En büyük değer $5$, yön $\left(\tfrac35,-\tfrac45\right)$. En küçük değer $-5$, yön $\left(-\tfrac35,\tfrac45\right)$. Sıfır değişim yönleri $\pm\left(\tfrac45,\tfrac35\right)$. Ayrıntı Örnek 6'dadır.

**Soru 4** (derste sözlü, 01:08:20 ve 01:10:34). $f$'nin $P_0$'da $\vec i+\vec j$ yönündeki türevi $2\sqrt2$, $-2\vec j$ yönündeki türevi $-3$ ise $-\vec i-2\vec j$ yönündeki türevi nedir? Hoca soruyu ikinci kez okuyup "Yapalım mı gençler?" diye sordu; cevap veren olmadı.

- Çözüm (derste kısmen verildi): $\nabla f(P_0)=(a,b)$ alınırsa $a+b=4$, $b=3$, $a=1$ çıkar. Son adım (sympy ile kesinleşti): $D_{\vec u}f=\dfrac{-1-6}{\sqrt5}=-\dfrac7{\sqrt5}$. Ayrıntı Örnek 7'dedir.

**Soru 5** (derste sözlü, 01:15:52). $y\neq0$ olmak üzere $f(x,y,z)=\dfrac xy-yz$. $f$, $P$ noktasında en hızlı hangi yönlerde değişir ve bu yönlerdeki değişim hızları nedir?

<!-- BELİRSİZ: P noktası altyazıda söylenmiyor; kısa nottaki P(4,1,1) alındı. -->

- Çözüm (derste verildi, sayı düzeltildi): $\nabla f(P)=\vec i-5\vec j-\vec k$. En hızlı artış bu yönde, hız $3\sqrt3$. En hızlı azalış $-\nabla f$ yönünde, hız $-3\sqrt3$. Hocanın sözlü okuduğu "3,43" ve "3,3" değerleri yanlıştır. Ayrıntı Örnek 12'dedir.

**Soru 6** (derste sözlü, 01:18:48). $\displaystyle\sum_{n=2}^{\infty}\frac{b^nx^n}{\ln n}$ kuvvet serisinin yakınsaklık yarıçapının $3$ olması için $b$ hangi değerleri alır?

<!-- BELİRSİZ: Serinin genel terimi altyazıda söylenmiyor; kısa nottan alındı. -->

- Çözüm (derste verildi): Oran testiyle $|b|\,|x|<1$, yarıçap $\tfrac1{|b|}=3$, yani $b=\pm\tfrac13$. Ayrıntı Örnek 14'tedir.

## Dersin Toparlaması

Bu derste çok değişkenli fonksiyonlarda kısmi türevin genellemesi olan yönlü türev işlendi. Yönlü türev önce limit tanımıyla verildi. Sonra pratikte kullanılan $D_{\vec u}f=\nabla f\cdot\vec u$ formülüne geçildi. Her iki yolda da ilk iş, yön vektörünün birim olup olmadığını kontrol etmek ve gerekirse boyuna bölmektir. $D_{\vec u}f=|\nabla f|\cos\theta$ yazılışından gradyanın anlamı çıktı: $f$ en hızlı $\nabla f$ yönünde artar, $-\nabla f$ yönünde azalır, gradyana dik yönlerde değişmez. En büyük ve en küçük değişim hızları $\pm|\nabla f|$'dir. Gradyan için toplam, çarpım ve bölüm kuralları tek değişkenli türev kurallarına benzer biçimde verildi.

İkinci yarıda bu fikirler sınav tipi sorularla pekiştirildi: en hızlı değişim yönleri, fonksiyon verilmeden gradyanın bilinmeyenlerle bulunması, iki doğrunun belirlediği düzlem, noktanın doğruya ve düzleme uzaklığı, izdüşüm. Son olarak geçmiş sınavlardan kuvvet serisinin yakınsaklık yarıçapı, kısmi türevin tanımla hesabı, yay uzunluğu ve çok değişkenli limit soruları gözden geçirildi. Hoca zincir kuralı sorusunu çözmeden geçti; bu konuyu bir önceki derste gösterdiğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
