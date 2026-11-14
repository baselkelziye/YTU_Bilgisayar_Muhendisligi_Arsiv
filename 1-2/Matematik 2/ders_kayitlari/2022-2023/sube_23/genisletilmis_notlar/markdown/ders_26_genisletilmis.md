# Ders 26 Genişletilmiş Notu: Final Hazırlığı: Zincir Kuralı, Teğet Düzlem, Lineerleştirme, Yönlü Türev ve Ekstremumlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı: Çok Değişkenli Fonksiyonlardan Final Soruları
- 2. Zincir Kuralı ile Kısmi Türev
- 3. Teğet Düzlem ve Normal Doğru
- 4. Lineerleştirme ve Diferansiyelle Yaklaşık Değer
- 5. Tam Diferansiyel ile Hacim Değişimi
- 6. Yönlü Türev
- 7. Yerel Ekstremumlar ve Eyer Noktaları
- 8. İki Yüzey Arasındaki Kesişim Açısı

## 1. Dersin Amacı: Çok Değişkenli Fonksiyonlardan Final Soruları

Hoca derse, bir önceki derste serilerle başladıklarını ve konular arasında "çaprazlama" gittiklerini hatırlatarak başladı. Bu derste final öncesi önemli bir konuyu aradan çıkarmak istedi: çok değişkenli fonksiyonlar (functions of several variables). Ekranda çok değişkenli fonksiyonlarla ilgili çalışma sorularını ve cevaplarını içeren bir dosya paylaştı ve soruları tek tek tahtada çözdü.

> **Hocanın vurgusu:** Bu konudan finalde mutlaka soru geliyor, en az bir soru. Yerel maksimum ve minimumla ilgili soru da mutlaka gelecek.

Sorular çoktan seçmeli biçimdeydi. Hoca her soruda önce yöntemi hatırlattı, sonra değerleri yerine koyup şıkkı buldu. Ders boyunca öğrencilere takıldıkları yeri rahatça sormalarını söyledi:

> **Hocanın vurgusu:** "Burası bir atölye, bilim atölyesi. Burada kimsenin kimseden bir üstünlüğü yok, ben de dahil." Anlamadığınızı sormaktan çekinmeyin; sorduğunuzda diğer arkadaşlarınız da tekrar etmiş olur.

## 2. Zincir Kuralı ile Kısmi Türev

Bu bölümdeki iki soru, araya ara değişkenler giren bileşke fonksiyonlarda kısmi türevin (partial derivative) zincir kuralıyla (chain rule) nasıl alındığını sınıyor. Hoca bu soruları "çok orijinal, finalde gelebilecek sorular" diye tanıttı.

**Zincir kuralı (iki ara değişken için)**

- $f=f(u,v)$ ve $u=u(x,y,z)$, $v=v(x,y,z)$ ise:
  - $\dfrac{\partial f}{\partial x}=\dfrac{\partial f}{\partial u}\dfrac{\partial u}{\partial x}+\dfrac{\partial f}{\partial v}\dfrac{\partial v}{\partial x}$
- Üç ara değişken varsa ($u,v,w$) toplama bir terim daha eklenir. $y$ ve $z$ türevleri de aynı biçimdedir.

### 2.1 Örnek 1: $f(x-y,\;y-z,\;z-x)$ için $f_x+f_y$

Soru: $f$, üç bileşenli bir ifadeye bağlı bir fonksiyon: $f(x-y,\;y-z,\;z-x)$. $\dfrac{\partial f}{\partial x}+\dfrac{\partial f}{\partial y}$ toplamı nedir? Şıklarda $2f$, $f_u+f_v+f_w$, $0$ gibi seçenekler vardı.

Hoca bileşenlere ad verdi: birinci bileşene $u$, ikinciye $v$, üçüncüye $w$ (hoca "omega" dedi):

$$u=x-y,\qquad v=y-z,\qquad w=z-x.$$

Böylece $f$ fonksiyonu $u,v,w$'ye; $u$ ise $x$ ve $y$'ye, $v$ ise $y$ ve $z$'ye, $w$ ise $z$ ve $x$'e bağlıdır. $f$'nin $u,v,w$'ye göre türevlerini bilmiyoruz, ama $u,v,w$'nin $x$ ve $y$'ye göre türevlerini biliyoruz.

$x$'e göre kısmi türev:

$$f_x=f_u\,u_x+f_v\,v_x+f_w\,w_x=f_u\cdot1+f_v\cdot0+f_w\cdot(-1)=f_u-f_w.$$

Burada $v=y-z$ içinde $x$ olmadığı için $v_x=0$ oldu.

$y$'ye göre kısmi türev:

$$f_y=f_u\,u_y+f_v\,v_y+f_w\,w_y=f_u\cdot(-1)+f_v\cdot1+f_w\cdot0=-f_u+f_v.$$

İki ifade taraf tarafa toplanınca $f_u$'lar birbirini götürür:

$$f_x+f_y=f_v-f_w.$$

Hoca bunun D şıkkı olduğunu söyledi. sympy ile genel $f$ için yapılan kontrol de $f_x+f_y=f_v-f_w$ verdi.

### 2.2 Örnek 2: $\nabla g(0,2,1)$

Soru: $f(u,v)$ fonksiyonu $f_u(4,2)=4$ ve $f_v(4,2)=2$ eşitliklerini sağlasın. $g(x,y,z)=f\left(y^2+zx,\;2y-2z^2+3x\right)$ olmak üzere $\nabla g(0,2,1)$ nedir?

<!-- BELİRSİZ: Altyazıda fonksiyonun değeri "2 noktasındaki değeri demiş 2" diye bozuk okunuyor; kısa notta f(4,2)=2023 yazıyor. Bu değer gradyan hesabında kullanılmıyor. Bileşenler altyazıda "Y kere ZX. 2Y Z kare artı 3X" diye geçiyor; y^2+zx ve 2y-2z^2+3x biçimi kısa nottan alındı ve hocanın sonuçlarıyla tutarlı. -->

Hoca yine bileşenlere ad verdi: $u=y^2+zx$, $v=2y-2z^2+3x$. $g$ fonksiyonu $f$'ye, $f$ ise $u$ ve $v$'ye, $u$ ve $v$ de $x,y,z$'ye bağlıdır. İstenen gradyan (gradient):

$$\nabla g=\left\langle g_x,\;g_y,\;g_z\right\rangle.$$

Önce $(0,2,1)$ noktasında $u$ ve $v$'nin değerine bakılır (ara adım eklendi): $u=4+0=4$, $v=4-2+0=2$. Yani $f$'nin türevleri tam olarak verilen $(4,2)$ noktasında alınır.

Zincir kuralı her değişken için:

| Türev | Zincir kuralı | $(0,2,1)$'deki değer |
|---|---|---|
| $g_x$ | $f_u\cdot z+f_v\cdot 3$ | $4\cdot1+2\cdot3=10$ |
| $g_y$ | $f_u\cdot 2y+f_v\cdot 2$ | $4\cdot4+2\cdot2=20$ |
| $g_z$ | $f_u\cdot x+f_v\cdot(-4z)$ | $4\cdot0+2\cdot(-4)=-8$ |

Sonuç:

$$\nabla g(0,2,1)=\langle10,\;20,\;-8\rangle.$$

Hoca bunun A şıkkı olduğunu söyledi. Burada sorulan, zincir kuralıyla bağlantılı kısmi türevleri alabilmektir.

> **Ders sonrası not:** Hoca üçüncü bileşeni sözlü olarak "8" diye okudu. sympy kontrolüne göre doğrusu $g_z(0,2,1)=-8$'dir.

## 3. Teğet Düzlem ve Normal Doğru

Hoca bu bölümde $z=f(x,y)$ biçiminde verilen bir yüzeyin teğet düzlemini (tangent plane) ve normal doğrusunu (normal line) bulmayı üç soruyla çalıştı.

> **Hocanın vurgusu:** Teğet düzlem ve normal doğru tek tek de, ikisi birlikte de sorulabilir. İkisini de bilmemiz lazım.

**Yöntem**

- Önce fonksiyon kapalı biçime getirilir: $z$ karşı tarafa geçirilir ve $F(x,y,z)=f(x,y)-z=0$ yazılır.
- $\nabla F=\langle F_x,F_y,F_z\rangle$ yüzeye diktir, yani normal vektöre paraleldir, teğet düzleme diktir.
- Noktanın üçüncü koordinatı $z_0=f(x_0,y_0)$ fonksiyondan hesaplanır.
- Teğet düzlem: $F_x(P)(x-x_0)+F_y(P)(y-y_0)+F_z(P)(z-z_0)=0$.
- Normal doğru: $\dfrac{x-x_0}{F_x}=\dfrac{y-y_0}{F_y}=\dfrac{z-z_0}{F_z}=t$, ya da parametrik olarak $x=x_0+F_x t$, $y=y_0+F_y t$, $z=z_0+F_z t$.

> **Ek bilgi (derste anlatılmadı):** $\nabla F$'nin yüzeye dik olmasının nedeni şudur: yüzey $F=0$ seviye yüzeyidir. Yüzey üzerindeki her eğri boyunca $F$ sabit kaldığı için $\frac{d}{dt}F(\vec r(t))=\nabla F\cdot\vec r\,'(t)=0$ olur. Yani gradyan, yüzeye teğet olan her vektöre diktir.

### 3.1 Örnek 3: $\ln$ içeren yüzeyin $(1,1)$ noktasındaki teğet düzlemi ve normal doğrusu

Soru: $z=\ln(\ldots)$ biçiminde verilen yüzeyin $(1,1)$ noktasındaki teğet düzlemi ve normal doğrusu hangisidir?

<!-- BELİRSİZ: Fonksiyon altyazıda "Z'iştir [öğrenci] bir artı X kare yukarı" diye geçiyor; maskelenen kelime büyük olasılıkla "ln". Hoca sonra "L'en neydi? X kare artı Y kare artı 1" diyor. Türevi anlatırken "2x bölü 2 kök" dediği için içeride karekök olabilir. Fonksiyonun tam biçimi altyazıdan çıkmıyor. -->

Hoca fonksiyonu kapalı biçime getirdi ($F=\ldots-z$) ve gradyanı hesapladı. $x$'e göre türevi alırken "$\ln$'in türevi: içinin türevi bölü kendisi" kuralını kullandı ve içinin türevini "$2x$ bölü $2$ kök" diye yazdı. $(1,1)$ noktasında bulduğu değerler:

$$F_x(1,1)=\frac13,\qquad F_y(1,1)=\frac13,\qquad F_z=-1.$$

Hoca anlatım sırasında bir bileşeni yanlış harfle yazdığını fark edip düzeltti ("şurası $y$'ye göre olması lazım, şurası $z$'ye göre türevi, eksi bir").

Sonra noktanın $z_0$ değerini buldu. $x=1$, $y=1$ koyunca içerisi $1+1+1=3$ olur; hoca $z_0=\ln3$ aldı. Teğet düzlem:

$$\frac13(x-1)+\frac13(y-1)-(z-z_0)=0.$$

Normal doğru:

$$\frac{x-1}{1/3}=\frac{y-1}{1/3}=\frac{z-z_0}{-1}.$$

> **Ders sonrası not:** sympy kontrolüne göre $z=\ln(1+x^2+y^2)$ olsaydı $F_x(1,1)=F_y(1,1)=\frac23$ çıkardı. Hocanın bulduğu $\frac13$ değerleri büyük olasılıkla $z=\ln\sqrt{1+x^2+y^2}$ fonksiyonuna aittir. Bu durumda doğru nokta değeri $z_0=\ln\sqrt3=\frac12\ln3$ olur, hocanın söylediği $\ln3$ değil.

### 3.2 Örnek 4: $z=\tan(x^2-xy)$ yüzeyinin $(0,-1)$ noktasındaki teğet düzlemi

Hoca "aynı düzeyde sorular çözüyoruz ki iyice anlaşılsın" diyerek benzer bir soruya geçti.

Kapalı biçim: $\tan(x^2-xy)$ yerinde kalır, $z$ karşı tarafa eksi olarak geçer:

$$F(x,y,z)=\tan(x^2-xy)-z.$$

Önce nokta: $x=0$, $y=-1$ konunca $x^2-xy=0$ olur. $\tan0=\dfrac{\sin0}{\cos0}=0$, yani $z_0=0$. Nokta $(0,-1,0)$.

Gradyan (ara adımlar eklendi):

- $F_x=\sec^2(x^2-xy)\,(2x-y)$, noktada $\sec^2 0\cdot(0+1)=1$.
- $F_y=\sec^2(x^2-xy)\,(-x)$, noktada $0$.
- $F_z=-1$.

Teğet düzlem:

$$1\cdot(x-0)+0\cdot(y+1)-1\cdot(z-0)=0\;\Longrightarrow\;x-z=0\;\Longrightarrow\;x=z.$$

Hoca cevabın A şıkkı olduğunu söyledi. Şıklarda $x=z$ ya da $x-z=0$ biçimini görmek yeterli.

### 3.3 Örnek 5: $z=\sin(x+y^2)$ yüzeyinin $(\pi,0)$ noktasındaki teğet düzlemi ve normal doğrusu

Soru normal doğruyu soruyordu, hoca teğet düzlemi de yazdı.

Kapalı biçim: $F(x,y,z)=\sin(x+y^2)-z$.

Gradyan:

- $F_x=\cos(x+y^2)\cdot1$. Hoca: "İçinin türevi $x$'e göre 1, çarpı kosinüs." Noktada $\cos\pi=-1$.
- $F_y=2y\cos(x+y^2)$, noktada $y=0$ olduğu için $0$.
- $F_z=-1$.

Yani $\nabla F(\pi,0,0)=\langle-1,\;0,\;-1\rangle$.

Bu arada hocanın internet bağlantısı kısa bir süre koptu. Bağlantı gelince hoca asıl önemli noktanın $z_0$'ı bulmak olduğunu vurguladı:

> **Hocanın vurgusu:** Teğet düzlem denklemini biliyorum, ama $x_0,y_0,z_0$ noktası ne oldu? Soru yalnız $x_0$ ve $y_0$'ı veriyor. $z_0$'ı fonksiyonda yerine koyarak bulmalıyız.

$z_0=\sin(\pi+0)=\sin\pi=0$. Nokta $(\pi,0,0)$.

Teğet düzlem:

$$-1\cdot(x-\pi)+0\cdot(y-0)-1\cdot(z-0)=0\;\Longrightarrow\;x+z=\pi.$$

Normal doğru (parametrik):

$$x=\pi-t,\qquad y=0,\qquad z=-t.$$

> **Hocanın vurgusu:** Yapılacak iş çok basit, ama işlem hatası yapmamalıyız. "Finalde kaç alacağız? 100."

Bu sorudan sonra yaklaşık 13 dakikalık bir mola verildi.

## 4. Lineerleştirme ve Diferansiyelle Yaklaşık Değer

Moladan sonra hoca yaklaşık değer sorularına geçti. Bu sorular iki yolla sorulabilir: ya doğrudan yaklaşık değer istenir, ya da "lineer denklem (lineerleştirme) aşağıdakilerden hangisidir?" diye sorulur.

**Lineerleştirme (linearization)**

- $(x_0,y_0)$ noktasında $f$'nin lineerleştirmesi:
  - $L(x,y)=f(x_0,y_0)+f_x(x_0,y_0)(x-x_0)+f_y(x_0,y_0)(y-y_0)$
- Tek değişkenli hâli $L(x)=f(x_0)+f'(x_0)(x-x_0)$ idi.
- $(x_0,y_0)$, istenen noktaya en yakın ve değeri kolay hesaplanan noktadır.

**Diferansiyel yöntemi**

- $f(a+\Delta x,\;b+\Delta y)\approx f(a,b)+f_x(a,b)\,\Delta x+f_y(a,b)\,\Delta y$.
- Hoca: "Başka hiçbir şey yok, her şey aynı." Lineerleştirmedeki $x-x_0$ yerine $\Delta x$, $y-y_0$ yerine $\Delta y$ yazılır.

### 4.1 Örnek 6: $f(x,y)=\sqrt{2x^2+e^{2y}}$ için $f(2{,}2;\,-0{,}2)$

Soru: $f(x,y)=\sqrt{2x^2+e^{2y}}$ fonksiyonunun $x=2{,}2$, $y=-0{,}2$ noktasındaki yaklaşık değeri nedir?

Nokta seçimi: $2{,}2$'ye en yakın kolay değer $2$, $-0{,}2$'ye en yakın kolay değer $0$. Yani $(x_0,y_0)=(2,0)$.

Fonksiyonun değeri: $f(2,0)=\sqrt{8+e^0}=\sqrt9=3$.

Kısmi türevler. Kök içinde olduğu için "içinin türevi bölü iki çarpı kök" kuralı kullanılır:

$$f_x=\frac{4x}{2\sqrt{2x^2+e^{2y}}},\qquad f_x(2,0)=\frac{8}{6}=\frac43,$$

$$f_y=\frac{2e^{2y}}{2\sqrt{2x^2+e^{2y}}},\qquad f_y(2,0)=\frac{2}{6}=\frac13.$$

Lineer denklem:

$$L(x,y)=3+\frac43(x-2)+\frac13(y-0).$$

$x=2{,}2$ ve $y=-0{,}2$ konunca:

$$L(2{,}2;\,-0{,}2)=3+\frac43(0{,}2)+\frac13(-0{,}2)=3+0{,}2=3{,}2.$$

Hoca bu sorunun "lineer denklem hangisidir" diye de sorulabileceğini, bu durumda yalnız $L(x,y)$ ifadesinin istendiğini hatırlattı.

### 4.2 Örnek 7: $\sqrt{(2{,}06)^2+5(0{,}97)^4}$

Soru: Bu sayının yaklaşık değerini lineerleştirme ya da diferansiyel ile bulunuz.

İlk adım bu sayıyı bir fonksiyonun değeri olarak yazmaktır. $2{,}06$ yerine $x$, $0{,}97$ yerine $y$ denirse:

$$f(x,y)=\sqrt{x^2+5y^4}.$$

Nokta seçimi: $2{,}06$, $2$'ye yakın; $0{,}97$, $1$'e yakın. Yani $(a,b)=(2,1)$ ve

$$\Delta x=2{,}06-2=0{,}06,\qquad \Delta y=0{,}97-1=-0{,}03.$$

Hoca $\Delta y$'nin işaretine dikkat çekti: $0{,}97$, $1$'den küçük olduğu için $\Delta y$ negatiftir; $1+(-0{,}03)=0{,}97$.

Değer ve türevler:

- $f(2,1)=\sqrt{4+5}=3$.
- $f_x=\dfrac{2x}{2\sqrt{x^2+5y^4}}=\dfrac{x}{\sqrt{x^2+5y^4}}$, $f_x(2,1)=\dfrac23$.
- $f_y=\dfrac{20y^3}{2\sqrt{x^2+5y^4}}$, $f_y(2,1)=\dfrac{20}{6}=\dfrac{10}{3}$.

Diferansiyel yöntemi:

$$f(2{,}06;\,0{,}97)\approx3+\frac23(0{,}06)+\frac{10}{3}(-0{,}03)=3+0{,}04-0{,}1=2{,}94.$$

Hoca soruyu sonra boş tahtada lineerleştirme biçimiyle bir kez daha çözdü:

$$L(x,y)=3+\frac23(x-2)+\frac{10}{3}(y-1),$$

ve $x=2{,}06$, $y=0{,}97$ koyarak aynı sonucu buldu. İki yöntem aynı işi yapar.

> **Ders sonrası not:** İkinci çözümde hoca $y-1$ farkını sözlü olarak "eksi 0,3" diye okudu. Doğrusu $0{,}97-1=-0{,}03$'tür; sonuç $2{,}94$ değişmez.

> **Ek bilgi (derste anlatılmadı):** sympy ile hesaplanan gerçek değerler: $\sqrt{2(2{,}2)^2+e^{-0{,}4}}\approx3{,}2172$ ve $\sqrt{(2{,}06)^2+5(0{,}97)^4}\approx2{,}9445$. Lineer yaklaşımlar ($3{,}2$ ve $2{,}94$) bu değerlere yakındır. Fark, $\Delta x$ ve $\Delta y$'nin karelerinden gelen ikinci mertebe terimlerden kaynaklanır.

## 5. Tam Diferansiyel ile Hacim Değişimi

### 5.1 Örnek 8: Dikdörtgenler prizmasının hacim değişimi

Hoca bunu geçmiş yıllarda sınavlarda benzeri çıkmış, "çok orijinal" bir soru olarak tanıttı.

Soru: Dikdörtgenler prizması şeklindeki bir cismin kenarları 2 cm, 3 cm ve 4 cm'dir. Cismin her boyutunda 0,02 cm artış yapıldığında hacminde meydana gelen değişim nedir?

<!-- BELİRSİZ: Soru metni altyazıda "her iki boyutunda" diye geçiyor; çözümde üç kenarın da artırıldığı kullanılıyor. -->

Hoca prizmayı gözümüzde canlandırmamızı istedi: kenarlar $x$, $y$ ve yükseklik $z$. Hacim:

$$V=xyz.$$

Tam diferansiyel (total differential):

$$dV=V_x\,dx+V_y\,dy+V_z\,dz.$$

Hoca bunun genel yapısını da anlattı: iki değişken olsaydı iki terimde dururduk, üç değişken var diye üç terim yazdık; $n$ değişken olsaydı terimler devam ederdi. Diferansiyel, fonksiyonun "ne kadar arttığını" gösterir.

Kısmi türevler. $x$'e göre türev alınırken $y$ ve $z$ katsayı gibi düşünülür:

- $V_x=yz=3\cdot4=12$,
- $V_y=xz=2\cdot4=8$,
- $V_z=xy=2\cdot3=6$.

Artışlar $dx=dy=dz=0{,}02$. Yerine konunca:

$$dV=12(0{,}02)+8(0{,}02)+6(0{,}02)=26\cdot0{,}02=0{,}52\ \text{cm}^3.$$

**Soru:** Şıklarda $0{,}52$ yok. **Cevap:** Olmayabilir; $\frac{52}{100}$ varsa aynı şeydir.

Hoca sonucu yorumladı:

- Kenarlar 0,02 cm artırılınca hacim $\frac{52}{100}$ cm³ artar.
- Kenarlar 0,02 cm azaltılsaydı $dx=dy=dz=-0{,}02$ olur, hacim $\frac{52}{100}$ cm³ azalırdı.
- Soru "son durumdaki hacim nedir" deseydi ilk hacme artış eklenirdi: $V=2\cdot3\cdot4=24$, son hacim $24+0{,}52=24{,}52$ cm³.
- Birim hacim olduğu için cm³'tür; alan olsaydı cm² derdik.

> **Ders sonrası not:** Hoca artış miktarını bir yerde "0,002" diye söyledi. Soruda ve hesapta kullanılan değer $0{,}02$'dir.

> **Ek bilgi (derste anlatılmadı):** Gerçek hacim değişimi $2{,}02\cdot3{,}02\cdot4{,}02-24\approx0{,}5236$ cm³'tür (sympy). Diferansiyel $0{,}52$ bunun birinci mertebe yaklaşımıdır; aradaki küçük fark $dx\,dy$ gibi çarpım terimlerinden gelir.

## 6. Yönlü Türev

**Yönlü türev (directional derivative)**

- $f$'nin $\vec u$ yönündeki türevi: $D_{\vec u}f=\nabla f\cdot\vec u$.
- $\vec u$ birim vektör olmalıdır. Değilse vektör kendi boyuna bölünür: $\vec u=\dfrac{\vec v}{|\vec v|}$.
- $D_{\vec u}f=|\nabla f|\,|\vec u|\cos\theta=|\nabla f|\cos\theta$. Bu yüzden:
  - En büyük değer $|\nabla f|$ ($\cos\theta=1$),
  - En küçük değer $-|\nabla f|$ ($\cos\theta=-1$).

### 6.1 Örnek 9: Yönlü türev bilgisiyle yaklaşık değer

Soru: $f(x,y)$ fonksiyonu bilinmiyor. $f(1,2)=5$ ve $f$'nin $(1,2)$ noktasındaki $\vec i+\vec j$ yönündeki türevi $3\sqrt2$'dir. Buna göre $f(1{,}1;\,2{,}1)$ sayısının yaklaşık değeri nedir?

Hoca önce lineerleştirmeyi kurdu. $1{,}1$'e en yakın $1$, $2{,}1$'e en yakın $2$; yani $(a,b)=(1,2)$:

$$f(1{,}1;\,2{,}1)\approx f(1,2)+f_x(1,2)\,(0{,}1)+f_y(1,2)\,(0{,}1)=5+0{,}1\left(f_x+f_y\right).$$

Fonksiyonu bilmediğimiz için $f_x$ ve $f_y$'yi tek tek bulamayız. "Buradan sonra iş başlıyor": yönlü türev bilgisi kullanılır.

$\vec v=\vec i+\vec j$ vektörünün boyu $\sqrt{1+1}=\sqrt2\neq1$. Birim vektör yapılır:

$$\vec u=\frac{1}{\sqrt2}\langle1,1\rangle.$$

Yönlü türev:

$$D_{\vec u}f=\nabla f\cdot\vec u=\frac{f_x+f_y}{\sqrt2}=3\sqrt2\;\Longrightarrow\;f_x+f_y=6.$$

Yerine konunca:

$$f(1{,}1;\,2{,}1)\approx5+0{,}1\cdot6=5{,}6.$$

Hoca bu soruyu "kalbur üstü", elementer olmayan bir soru olarak niteledi: fonksiyonun kendisi bilinmeden sonuca ulaşılıyor.

### 6.2 Örnek 10: Yönlü türevin en büyük ve en küçük değeri

Soru: $f(x,y,z)=\dfrac{x}{y}-yz$ fonksiyonunun $P(4,1,1)$ noktasındaki yönlü türevlerinin en büyük değeri $A$, en küçük değeri $B$ ise $A$ ve $B$ nedir?

<!-- BELİRSİZ: Fonksiyon altyazıda "x bölü y, x'i y'e z" ve "x bölü y-z" diye geçiyor; x/y - yz biçimi kısa nottan alındı ve hocanın sonucu (kök 27) ile tutarlı. -->

Gradyan:

$$\nabla f=\left\langle\frac1y,\;-\frac{x}{y^2}-z,\;-y\right\rangle,\qquad \nabla f(4,1,1)=\langle1,\;-5,\;-1\rangle.$$

Boyu:

$$|\nabla f|=\sqrt{1+25+1}=\sqrt{27}=3\sqrt3.$$

Sonuç $A=\sqrt{27}=3\sqrt3$, $B=-\sqrt{27}=-3\sqrt3$. Şıklarda $\sqrt{27}$ ya da $3\sqrt3$ biçiminde görülebilir.

> **Hocanın vurgusu:** En büyük ve en küçük değer tam zıt işaretli olmalı. Birini $\sqrt{27}$, öbürünü başka bir sayı bulursanız işlem hatası yapmışsınızdır.

## 7. Yerel Ekstremumlar ve Eyer Noktaları

> **Hocanın vurgusu:** Yerel minimum ve yerel maksimumlarla ilgili soru mutlaka gelecek.

**İkinci türev testi**

- Kritik noktalar $f_x=0$ ve $f_y=0$ denklemlerinin ortak çözümüdür.
- Her kritik noktada $A=f_{xx}$, $B=f_{xy}$, $C=f_{yy}$ hesaplanır.
  - $B^2-AC<0$ ve $A<0$: yerel maksimum.
  - $B^2-AC<0$ ve $A>0$: yerel minimum.
  - $B^2-AC>0$: eyer noktası (saddle point).
  - $B^2-AC=0$: test karar vermez.
- Birden fazla kritik nokta varsa bir tablo kurulur.

### 7.1 Örnek 11: Tek kritik nokta, yerel maksimum

Soru: $f(x,y)=xy-x^2-y^2-2x-2y+4$ için aşağıdakilerden hangisi doğrudur? Şıklar: bir tane yerel minimum vardır; bir tane yerel maksimum vardır; iki tane yerel maksimum vardır; bir tane eyer noktası vardır.

<!-- BELİRSİZ: Fonksiyon altyazıda okunmuyor ("Fonksiyonumuz şu fx yi işitir"); kısa nottan alındı. -->

Kritik nokta (ara adımlar eklendi):

$$f_x=y-2x-2=0,\qquad f_y=x-2y-2=0.$$

İlk denklemden $y=2x+2$; ikinciye konunca $x-4x-4-2=0$, $x=-2$, $y=-2$. Tek kritik nokta $(-2,-2)$.

İkinci türevler: $A=f_{xx}=-2$, $B=f_{xy}=1$, $C=f_{yy}=-2$.

$$B^2-AC=1-4=-3<0,\qquad A=-2<0\;\Longrightarrow\;\text{yerel maksimum}.$$

Cevap: bir tane yerel maksimum vardır (C şıkkı).

> **Hocanın vurgusu:** "İki tane yerel maksimum vardır" şıkkına dikkat. Tek bir nokta bulduk; buna yanlışlıkla düşmeyelim.

> **Ders sonrası not:** Hoca kritik noktayı sözlü olarak "eksi 2, artı 2" ve "2, 2" diye okudu. Denklemlerin çözümü (sympy ile de) $(-2,-2)$'dir. Sonuç (tek yerel maksimum) değişmez.

### 7.2 Örnek 12: İki kritik nokta, tablo ile sınıflandırma

Hoca başka bir fonksiyonda $f_x$ ve $f_y$'yi sıfıra eşitledi, iki kritik nokta buldu: $x=0$'a karşılık $y=0$, $x=1$'e karşılık $y=2$. İkinci türevler $A=48x$, $B=-12$, $C=6y$. "Daha önce yapmıştık" dediği tabloyu kurdu:

| Nokta | $A$ | $B$ | $C$ | $B^2-AC$ | Sonuç |
|---|---|---|---|---|---|
| $(0,0)$ | $0$ | $-12$ | $0$ | $144>0$ | eyer noktası |
| $(1,2)$ | $48$ | $-12$ | $12$ | $144-576=-432<0$, $A>0$ | yerel minimum |

<!-- BELİRSİZ: Fonksiyonun kendisi altyazıda geçmiyor; A, B, C ve kritik noktalar kısa nottan alındı. -->

> **Ek bilgi (derste anlatılmadı):** Verilen $A=48x$, $B=-12$, $C=6y$ ve kritik noktalar $(0,0)$, $(1,2)$, büyük olasılıkla $f(x,y)=8x^3+y^3-12xy$ (artı bir sabit) fonksiyonuna aittir. sympy ile bu fonksiyonun kritik noktaları tam olarak $(0,0)$ ve $(1,2)$ çıkar; sınıflandırma tablodakiyle aynıdır.

### 7.3 Örnek 13: $f(x,y)=4+x^3+y^3-3xy$

Soru: Fonksiyonun yerel maksimum sayısı $a$, yerel minimum sayısı $b$, eyer noktası sayısı $c$ ise aşağıdakilerden hangisi doğrudur?

<!-- BELİRSİZ: Altyazıda "4 artı x küp artı y küp eksi x'ye" geçiyor; -3xy katsayısı kısa nottan alındı ve hocanın bulduğu kritik noktalarla tutarlı. -->

Kritik noktalar (ara adımlar eklendi):

$$f_x=3x^2-3y=0\Rightarrow y=x^2,\qquad f_y=3y^2-3x=0\Rightarrow x=y^2.$$

Buradan $x=x^4$, yani $x(x^3-1)=0$; $x=0$ ya da $x=1$. Kritik noktalar $(0,0)$ ve $(1,1)$.

İkinci türevler: $A=6x$, $B=-3$, $C=6y$.

- $(0,0)$: $A=0$, $C=0$, $B^2-AC=9>0$, eyer noktası.
- $(1,1)$: $A=6$, $C=6$, $B^2-AC=9-36=-27<0$ ve $A>0$, yerel minimum.

Sonuç: $a=0$ (yerel maksimum yok), $b=1$, $c=1$.

<!-- BELİRSİZ: Hoca sonunda "yerlerine koyduğum zaman, topladığım zaman" diyor; şıkların a, b, c'nin toplamı ya da başka bir birleşimi üzerinden mi kurulduğu altyazıdan çıkmıyor. -->

### 7.4 Örnek 14: $f(x,y)=x+y\sin x$ için kritik nokta sayısı

Soru: $f(x,y)=x+y\sin x$ fonksiyonunun $0\le x\le\pi$ aralığında kaç kritik noktası vardır?

Hoca bu soruda yalnız sonucu ve uyarıyı söyledi: "Sen üç tane buldun, iki taneymiş. O zaman yanlışa gidiyoruz."

> **Hocanın vurgusu:** Kritik nokta sayısı bile önemli. Bu tip soruların hiçbirini bırakmadan çözmek lazım.

> **Çözüm (derste verilmedi):** $f_y=\sin x=0$ ise $[0,\pi]$'de $x=0$ ya da $x=\pi$. $f_x=1+y\cos x=0$ denklemine konunca $x=0$ için $y=-1$, $x=\pi$ için $y=1$ çıkar. Kritik noktalar $(0,-1)$ ve $(\pi,1)$; toplam 2 tane (sympy ile doğrulandı).

## 8. İki Yüzey Arasındaki Kesişim Açısı

### 8.1 Örnek 15: Kesişim açısı

Hoca bu soruyu son sorudan önce gelen, "görmenizde fayda var" dediği bir soru olarak gösterdi.

Soru: $x^2+y^2+z^2=4y+2z+5$ yüzeyi ile $3x^2+2y^2-2z=3$ yüzeyi $P(1,2,4)$ noktasında kesişiyor. Kesişim açısı nedir?

<!-- BELİRSİZ: Yüzey denklemleri altyazıda geçmiyor; kısa nottan alındı. P noktası her iki yüzeyi de sağlıyor (sympy). -->

> **Hocanın vurgusu:** İki yüzeyin kesişim açısı, gradyanları arasındaki açıdır. Bu çok önemli.

Yöntem: İki yüzey de kapalı biçime getirilir, gradyanlar alınır, noktada değerlendirilir ve iki vektör arasındaki açı formülü kullanılır:

$$\cos\theta=\frac{\nabla F\cdot\nabla G}{|\nabla F|\,|\nabla G|}.$$

Kapalı biçimler ve gradyanlar (ara adımlar eklendi):

- $F=x^2+y^2+z^2-4y-2z-5$, $\nabla F=\langle2x,\;2y-4,\;2z-2\rangle$, $\nabla F(P)=\langle2,\;0,\;6\rangle$.
- $G=3x^2+2y^2-2z-3$, $\nabla G=\langle6x,\;4y,\;-2\rangle$, $\nabla G(P)=\langle6,\;8,\;-2\rangle$.

İç çarpım: $\nabla F\cdot\nabla G=12+0-12=0$. Buradan $\cos\theta=0$ ve

$$\theta=\frac{\pi}{2}.$$

Yüzeyler birbirini dik keser.

## Örnek Sorular

Bu derste kare yok. Sorular hocanın ekranda paylaştığı çalışma sorularından sesli okuduğu ve çözdüğü sorulardır. Çözümler yukarıdaki bölümlerde adım adım verildi.

- **Soru 1** (derste sözlü, 00:03:35): $f(x-y,\;y-z,\;z-x)$ için $\dfrac{\partial f}{\partial x}+\dfrac{\partial f}{\partial y}$ nedir?
  - Çözüm: $f_v-f_w$ ($u=x-y$, $v=y-z$, $w=z-x$).
- **Soru 2** (derste sözlü, 00:08:43): $f_u(4,2)=4$, $f_v(4,2)=2$ ve $g(x,y,z)=f\left(y^2+zx,\;2y-2z^2+3x\right)$ ise $\nabla g(0,2,1)$ nedir? <!-- BELİRSİZ: bileşenlerin biçimi kısa nottan. -->
  - Çözüm: $\langle10,\;20,\;-8\rangle$.
- **Soru 3** (derste sözlü, 00:13:35): $z=\ln(\ldots)$ yüzeyinin $(1,1)$ noktasındaki teğet düzlemi ve normal doğrusu hangisidir? <!-- BELİRSİZ: fonksiyonun tam biçimi altyazıda okunmuyor. -->
  - Çözüm (hocanın değerleriyle): $\frac13(x-1)+\frac13(y-1)-(z-z_0)=0$; normal doğru $\frac{x-1}{1/3}=\frac{y-1}{1/3}=\frac{z-z_0}{-1}$.
- **Soru 4** (derste sözlü, 00:19:55): $z=\tan(x^2-xy)$ yüzeyinin $(0,-1)$ noktasındaki teğet düzlemi nedir?
  - Çözüm: $x-z=0$.
- **Soru 5** (derste sözlü, 00:23:44): $z=\sin(x+y^2)$ yüzeyinin $(\pi,0)$ noktasındaki normal doğrusu nedir?
  - Çözüm: $x=\pi-t$, $y=0$, $z=-t$; teğet düzlem $x+z=\pi$.
- **Soru 6** (derste sözlü, 00:46:05): $f(x,y)=\sqrt{2x^2+e^{2y}}$ için $f(2{,}2;\,-0{,}2)$'nin yaklaşık değeri nedir?
  - Çözüm: $L(x,y)=3+\frac43(x-2)+\frac13y$, yaklaşık değer $3{,}2$.
- **Soru 7** (derste sözlü, 00:50:35): $\sqrt{(2{,}06)^2+5(0{,}97)^4}$ sayısının yaklaşık değerini lineerleştirme ya da diferansiyel ile bulunuz.
  - Çözüm: $2{,}94$.
- **Soru 8** (derste sözlü, 00:59:54): Kenarları 2 cm, 3 cm ve 4 cm olan dikdörtgenler prizmasının her kenarı 0,02 cm artırılırsa hacimde meydana gelen değişim nedir?
  - Çözüm: $dV=0{,}52=\frac{52}{100}$ cm³ artış.
- **Soru 9** (derste sözlü, 01:04:30): $f(1,2)=5$ ve $f$'nin $(1,2)$'de $\vec i+\vec j$ yönündeki türevi $3\sqrt2$ ise $f(1{,}1;\,2{,}1)$'in yaklaşık değeri nedir?
  - Çözüm: $f_x+f_y=6$, yaklaşık değer $5{,}6$.
- **Soru 10** (derste sözlü, 01:09:05): $f(x,y,z)=\frac xy-yz$ fonksiyonunun $P(4,1,1)$'deki yönlü türevlerinin en büyük değeri $A$, en küçük değeri $B$ ise $A$ ve $B$ nedir?
  - Çözüm: $A=\sqrt{27}=3\sqrt3$, $B=-3\sqrt3$.
- **Soru 11** (derste sözlü, 01:11:25): $f(x,y)=xy-x^2-y^2-2x-2y+4$ için hangisi doğrudur (yerel minimum, yerel maksimum, eyer noktası sayısı)? <!-- BELİRSİZ: fonksiyon kısa nottan. -->
  - Çözüm: $(-2,-2)$'de bir tane yerel maksimum vardır.
- **Soru 12** (derste sözlü, 01:12:55): Kritik noktaları $(0,0)$ ve $(1,2)$, ikinci türevleri $A=48x$, $B=-12$, $C=6y$ olan fonksiyonun maksimum, minimum ve eyer noktaları için hangisi doğrudur? <!-- BELİRSİZ: fonksiyonun kendisi altyazıda yok. -->
  - Çözüm: $(0,0)$ eyer noktası, $(1,2)$ yerel minimum.
- **Soru 13** (derste sözlü, 01:13:53): $f(x,y)=4+x^3+y^3-3xy$ fonksiyonunun yerel maksimum sayısı $a$, yerel minimum sayısı $b$, eyer noktası sayısı $c$ ise hangisi doğrudur?
  - Çözüm: $a=0$, $b=1$, $c=1$.
- **Soru 14** (derste sözlü, 01:14:46): $f(x,y)=x+y\sin x$ fonksiyonunun $0\le x\le\pi$ aralığında kaç kritik noktası vardır?
  - Çözüm: 2 tane, $(0,-1)$ ve $(\pi,1)$.
- **Soru 15** (derste sözlü, 01:15:15): $x^2+y^2+z^2=4y+2z+5$ ve $3x^2+2y^2-2z=3$ yüzeylerinin $P(1,2,4)$'teki kesişim açısı nedir? <!-- BELİRSİZ: yüzey denklemleri kısa nottan. -->
  - Çözüm: $\nabla F\cdot\nabla G=0$, $\theta=\frac\pi2$.

## Dersin Toparlaması

Bu ders, çok değişkenli fonksiyonlar konusunun finale yönelik bir tekrarıydı. Önce zincir kuralıyla ara değişkenler üzerinden kısmi türev ve gradyan hesaplandı. Ardından kapalı biçimde yazılan bir yüzeyin gradyanının normal vektör olduğu kullanılarak teğet düzlem ve normal doğru bulundu; burada en sık yapılan hatanın $z_0$'ı fonksiyondan hesaplamayı unutmak olduğu vurgulandı. Lineerleştirme ve diferansiyel yönteminin aslında aynı formül olduğu ($x-x_0=\Delta x$) gösterildi, tam diferansiyel ile prizmanın hacim değişimi hesaplandı. Yönlü türevde birim vektör şartı, yönlü türev bilgisiyle bilinmeyen bir fonksiyonun yaklaşık değeri ve yönlü türevin en büyük ($|\nabla f|$) ve en küçük ($-|\nabla f|$) değerleri çalışıldı.

Son kısımda ikinci türev testiyle yerel maksimum, yerel minimum ve eyer noktaları sınıflandırıldı; hoca kritik nokta sayısında yapılacak bir hatanın doğrudan yanlış şıkka götürdüğünü özellikle belirtti. Ders, iki yüzeyin kesişim açısının gradyanlar arasındaki açı olduğu bir soruyla bitti. Hoca gelecek hafta diğer konulardan da final soruları çözüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
