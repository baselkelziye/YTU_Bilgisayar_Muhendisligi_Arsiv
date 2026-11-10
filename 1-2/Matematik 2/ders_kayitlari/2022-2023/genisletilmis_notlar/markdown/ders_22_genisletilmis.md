# Ders 22 Genişletilmiş Notu: Final Soruları: Değişken Dönüşümü, Karışık Kısmi Türev, Kritik Noktalar ve Seri Toplamı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı: Geçmiş Yıl Final Soruları
- 2. İki Katlı İntegralde Değişken Dönüşümü (Örnek 1)
- 3. Parçalı Fonksiyonda Karışık Kısmi Türev (Örnek 2)
- 4. Karışık Kısmi Türevlerin Eşitliği ve Süreklilik
- 5. Kritik Noktalar ve İkinci Türev Testi (Örnek 3)
- 6. Kapalı Fonksiyon, Zincir Kuralı ve Teğet Düzlem (Örnek 4)
- 7. Kare Bölgede Değişken Dönüşümü (Örnek 5)
- 8. Kutupsal Koordinatlarla Hacim (Örnek 6)
- 9. Seri Toplamı: Terim Terim Türev (Örnek 7)
- 10. Serinin Karakteri: Limit Karşılaştırma Testi (Örnek 8)
- 11. Gradyan, En Hızlı Artış Yönü ve Teğet Düzlem (Örnek 9)
- 12. Lineerleştirme ile Yönlü Türev (Örnek 10)
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Planı: Geçmiş Yıl Final Soruları

Hoca derse bir önceki günün konusunu hatırlatarak başladı. Dün iki katlı integralde değişken dönüşümünün temel fikri anlatılmıştı. Bugün bu fikri ve dönemin diğer konularını, üniversitede 2020 yılında final sınavında çıkmış sorular üzerinden pekiştirmek istedi. Soruları ekranda paylaştı ve tablet üzerinde kırmızı kalemle çözdü. Bu yüzden altyazıda yalnız sözlü anlatım var. Formüllerin bir kısmı aşağıda sözlü anlatımdan ve kısa notta ekrandan okunan değerlerden kurulmuştur.

Hoca, 2020'deki sınavın klasik (yazılı) olduğunu, her adımın ayrı puanlandığını söyledi. Bu dönemki sınav test olacağı için soruların daha kısa ("light") hale getirileceğini, ama aynı mantığın sorulacağını belirtti. Örneğin bir dönüşüm sorusunda integralin sonucuna kadar gitmek yerine yalnız "dönüştürülmüş hali hangisidir" diye sorulabilir. Bu yüzden ara adımların her birini bilmek gerekir.

## 2. İki Katlı İntegralde Değişken Dönüşümü (Örnek 1)

### 2.1 Soru ve ilk gözlem

**Örnek 1 (2020 final, Soru 1).** Aşağıdaki integrali hesaplayınız:

$$I=\int_0^1\int_{2y}^{5-3y}\frac{x-2y}{(x+3y)^2}\cos(x+3y)\,dx\,dy$$

Burada $y$ sıfırdan bire kadar, $x$ ise $2y$'den $5-3y$'ye kadar değişiyor. Hoca önce integrandın "çok karmakarışık" göründüğünü vurguladı. Normal yolla bu integrali almak zor. Akla gelen ilk fikir bölgeyi çizip integrasyon sırasını değiştirmektir. Ama hoca bunun burada işe yaramayacağını söyledi: sıra $dy\,dx$ yapılsa da integrand yine aynı karışık ifadedir. Bu yüzden bir dönüşüm, yani pratik bir çözüm gerekir.

### 2.2 Bölgenin çizilmesi

Dönüşümden önce integrasyon bölgesi $D$ çizilir. Hoca bu adımın "çok kıymetli" olduğunu söyledi.

- $0\le y\le 1$.
- Sol sınır: $x=2y$ doğrusu.
- Sağ sınır: $x=5-3y$ doğrusu.
- Alt sınır: $y=0$ ekseni.

İki doğru $y=1$'de, $(2,1)$ noktasında kesişir (ara adım eklendi). Yani $D$, köşeleri $(0,0)$, $(5,0)$ ve $(2,1)$ olan bir üçgendir.

### 2.3 Dönüşümün seçimi

Hocaya göre integrand, hangi dönüşümün yapılacağını "ipucu olarak veriyor". Sınır doğruları $x=2y$ ve $x=5-3y$ şöyle yazılabilir:

- $x-2y=0$,
- $x+3y=5$.

İntegrandın içinde de tam olarak $x-2y$ ve $x+3y$ ifadeleri geçiyor. O halde:

$$u=x-2y,\qquad v=x+3y$$

> **Hocanın vurgusu:** İntegrandın içindeki ifadeler size sinyali veriyor. $x+3y$ hem sınırda hem integrandın içinde var; buna $v$ diyoruz.

### 2.4 Yeni bölge

Sınırlar tek tek $u$, $v$ cinsinden yazılır:

- $x=2y \Rightarrow u=0$.
- $x=5-3y \Rightarrow v=5$.
- $y=0 \Rightarrow u=x$ ve $v=x$, yani $u=v$.

Böylece yeni bölge $D'$:

$$0\le v\le 5,\qquad 0\le u\le v$$

Hoca bunu "$v$ sıfırdan 5'e, $u$ sıfırdan $v$'ye" diye özetledi.

> **Ders sonrası not:** Hoca 00:12:35 civarında "$x$ sıfırdan bire değişiyordu" dedi. Sıfırdan bire değişen $y$'dir. Ayrıca 00:06:49 civarında "$x$ eksi $3y$ sıfırdır" dedi; doğrusu $x-2y=0$, yani $u=0$.

### 2.5 Jacobian

Değişken dönüşümünde $dx\,dy$ yerine $|J|\,du\,dv$ yazılır. Burada

$$J=\frac{\partial(x,y)}{\partial(u,v)}=\begin{vmatrix}x_u & x_v\\ y_u & y_v\end{vmatrix}$$

Bunu doğrudan hesaplamak için $x$ ve $y$'yi $u$, $v$ cinsinden çözmek gerekir. Hoca bunun zahmetli olduğunu, onun yerine ters yönden gitmenin kolay olduğunu söyledi: $u$'nun $x$'e göre türevi 1, $y$'ye göre türevi $-2$, "çok kolay". Bu yüzden "takla attırıyoruz":

$$\frac{\partial(x,y)}{\partial(u,v)}=\frac{1}{\dfrac{\partial(u,v)}{\partial(x,y)}},\qquad \frac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}u_x & u_y\\ v_x & v_y\end{vmatrix}=\begin{vmatrix}1&-2\\1&3\end{vmatrix}=3+2=5$$

Dolayısıyla $J=\dfrac15$ ve $dx\,dy=\dfrac15\,du\,dv$.

> **Ek bilgi (derste anlatılmadı):** Ters çevirme kuralı, iki dönüşümün Jacobian matrislerinin birbirinin tersi olmasından gelir. Bileşke dönüşüm birim dönüşüm olduğundan determinantların çarpımı 1'dir. Bu kural, Jacobian sıfırdan farklı olduğu sürece geçerlidir.

### 2.6 Hesap

Yerine koyunca, $x-2y$ yerine $u$, $x+3y$ yerine $v$ gelir:

$$I=\frac15\int_0^5\int_0^v\frac{u}{v^2}\cos v\,du\,dv$$

İç integralde $v$ sabittir (ara adım eklendi):

$$\int_0^v\frac{u}{v^2}\cos v\,du=\frac{\cos v}{v^2}\cdot\frac{v^2}{2}=\frac{\cos v}{2}$$

Dış integral:

$$I=\frac15\int_0^5\frac{\cos v}{2}\,dv=\frac1{10}\Big[\sin v\Big]_0^5=\frac{\sin 5}{10}$$

Hoca sonucu "1 bölü 10 çarpı sin 5" diye okudu. Karmakarışık görünen integral basit bir sonuca dönüştü. Hoca bunun matematiğin temel amacı olduğunu, yani problemi çözülebilir hale getirmek olduğunu söyledi. Sayısal olarak $I\approx-0{,}0959$'dur. Bu değer, asıl integral sayısal olarak hesaplanarak da doğrulandı.

Hoca integralin geometrik anlamını da hatırlattı: bu, $D$ bölgesi üzerinde integrand fonksiyonunun grafiği altındaki "hacim"dir. Fonksiyon ilginç ve karışık olduğu için bu hacmi doğrudan hesaplamak mümkün görünmez. Dönüşüm bunu mümkün kılar.

## 3. Parçalı Fonksiyonda Karışık Kısmi Türev (Örnek 2)

### 3.1 Soru

**Örnek 2 (2020 final, Soru 2).** İki değişkenli, parçalı tanımlı bir fonksiyon veriliyor:

$$F(x,y)=\begin{cases}\dfrac{4y(2x^3-xy^2)}{4x^2+3y^2}, & (x,y)\ne(0,0)\\[4pt] 0, & (x,y)=(0,0)\end{cases}$$

İstenen: önce $x$'e, sonra $y$'ye göre alınan karışık kısmi türevin orijindeki değeri, $F_{xy}(0,0)$.

<!-- BELİRSİZ: Fonksiyonun formülü altyazıda okunmuyor; kısa notta ekrandan okunan haliyle verildi. Hesaplanan ara değerler (F(h,0)=0, F_xy(0,0)=-4/3) altyazıyla uyumlu. -->

Hoca aynı fonksiyon için başka soruların da gelebileceğini söyledi: limiti var mı, sürekli mi, kısmi türevi nedir, karışık türevi nedir. Bunların birinin, ikisinin ya da hepsinin sorulabileceğini belirtti.

### 3.2 Birinci adım: $F_x(0,0)$

Orijinde fonksiyon ayrı tanımlandığı için türev formülle değil tanımla alınır. $x$'e göre türev istendiği için artış $x$'e verilir:

$$F_x(0,0)=\lim_{h\to0}\frac{F(h,0)-F(0,0)}{h}$$

$F(h,0)$: $x$ yerine $h$, $y$ yerine 0 konur. Paydaki $4y$ çarpanı sıfır olur, payda $4h^2$ olur. Yani $F(h,0)=\dfrac{0}{4h^2}=0$. $F(0,0)=0$ zaten verilmiş. Böylece limit almadan önce bile ifade $\dfrac{0}{h}=0$ olur:

$$F_x(0,0)=0$$

### 3.3 İkinci adım: $F_x$'in orijin dışındaki ifadesi

$(x,y)\ne(0,0)$ için $F_x$, $y$ sabit tutularak bölüm kuralıyla bulunur. Hoca bu türevi ekranda hazır gösterdi. Sonra bu ifadede $x=0$ konur (ara adım eklendi):

$$F_x(0,y)=-\frac{4y}{3}\qquad (y\ne0)$$

Hoca burada bir noktaya dikkat çekti: $F_x(0,h)$ hesaplanırken $(0,0)$ değil, $(0,h)$ konur. Orijindeki değer zaten bir önceki adımda tanımla bulunmuştu.

### 3.4 Üçüncü adım: $F_{xy}(0,0)$

Bu kez artış $y$'ye verilir. Hoca artışa $h$ ya da $k$ denebileceğini, fark etmediğini söyledi:

$$F_{xy}(0,0)=\lim_{h\to0}\frac{F_x(0,h)-F_x(0,0)}{h}=\lim_{h\to0}\frac{-\tfrac{4h}{3}-0}{h}=-\frac43$$

Kısa notta bu adım $F_x(0,h)=\dfrac{-12h^5}{9h^4}$ biçiminde yazılmıştır. Sadeleşince yine $-\dfrac{4h}{3}$ olur. Sonuç sympy ile doğrulandı.

Hoca, bu tip soruları çözerken en önemli şeyin dikkat olduğunu, bunun için de bol soru çözmek gerektiğini söyledi.

## 4. Karışık Kısmi Türevlerin Eşitliği ve Süreklilik

Örnek 2'den sonra hoca bir soruyu hatırlattı: önce $x$'e sonra $y$'ye göre alınan karışık türev, önce $y$'ye sonra $x$'e göre alınana eşit midir?

**Teorem (karışık türevlerin eşitliği).**

- $f_{xy}=f_{yx}$ eşitliği her zaman doğru değildir.
- Kısmi türevler (hoca "$f$'in $x$'e göre ve $y$'ye göre kısmi türevleri" dedi) sürekli ise eşitlik sağlanır.
- Aksi halde eşit olmayabilir.

> **Ek bilgi (derste anlatılmadı):** Bu sonuç Clairaut (Schwarz) teoremi olarak bilinir. Kesin koşul, bir noktanın komşuluğunda $f_{xy}$ ve $f_{yx}$'in var olup o noktada sürekli olmasıdır. Örnek 2'deki fonksiyon için ters sırada türev alınırsa $F_y(x,0)=2x$ ve $F_{yx}(0,0)=2$ çıkar. Bu, $F_{xy}(0,0)=-\tfrac43$'ten farklıdır; yani orada bu koşul sağlanmıyor.

Hoca ardından tek ve çok değişkenli fonksiyonlar arasındaki bir farkı vurguladı. Tek değişkenli bir fonksiyon bir noktada sürekli değilse orada türevi yoktur. Bu yüzden süreksiz bir noktada türeve bakılmaz. Çok değişkenli fonksiyonlarda durum değişir: kısmi türevler var olduğu halde fonksiyon süreksiz olabilir.

> **Hocanın vurgusu:** Çok değişkenli fonksiyonda kısmi türev var ama fonksiyon sürekli değil; bu mümkün. Buna dikkat edelim.

## 5. Kritik Noktalar ve İkinci Türev Testi (Örnek 3)

### 5.1 Neden kritik noktalar?

Hoca kritik noktaların maksimum ve minimum bulmaya yaradığını hatırlattı. Günlük hayatta bunlar çok önemlidir: minimum maliyet, maksimum kazanç, maksimum verim, az zamanda çok iş. Mühendislikte de veriler (örneğin binlerce hastanın verisi) parametrelere bağlanıp bir fonksiyona dönüştürülür. Sonra bu fonksiyon analiz edilir. Hoca regresyon ve korelasyon analizlerini örnek verdi: 50 örnekle yapılan bir çalışmadan, 500 ya da 5000 örnek yapılmış gibi sonuç çıkarmak mümkün olur. Bu, "hareket alanını genişleten" önemli bir tekniktir.

### 5.2 Soru

**Örnek 3 (2020 final, Soru 3).** Aşağıdaki fonksiyonun tüm kritik noktalarını bulup sınıflandırınız:

$$f(x,y)=x^4-4xy-7x^2+4x+4y^2-8y+5$$

<!-- BELİRSİZ: Fonksiyonun tam hali altyazıda okunmuyor; kısa nottaki ekran okumasından alındı. Altyazıdaki f_x, f_y terimleri ve bulunan noktalarla uyumlu. -->

### 5.3 Kısmi türevler ve kritik noktalar

$x$'e göre türev alırken $y$ sabit gibi düşünülür:

$$f_x=4x^3-4y-14x+4=0$$

$y$'ye göre türev alırken $x$ sabit gibi düşünülür. $x^4$'ün türevi 0 olur, $-4xy$'nin türevi $-4x$ olur:

$$f_y=-4x+8y-8=0$$

İkinci denklemden $8y=4x+8$, yani $y=\dfrac{x}{2}+1$ (eşdeğer olarak $x=2y-2$). Bunu birinci denklemde yerine koyalım (ara adım eklendi):

$$4x^3-4\Big(\frac{x}{2}+1\Big)-14x+4=4x^3-16x=4x(x^2-4)=0$$

Buradan $x=0$, $x=2$, $x=-2$ çıkar. Karşılık gelen $y$ değerleri $1$, $2$, $0$'dır. Hoca üç kritik noktayı şöyle adlandırdı:

- $P(0,1)$,
- $Q(2,2)$,
- $R(-2,0)$.

### 5.4 İkinci türev testi

Hoca testi şöyle hatırlattı:

**İkinci türev testi.**

- $A=f_{xx}$, $B=f_{xy}$, $C=f_{yy}$ kritik noktada hesaplanır.
- $\Delta=B^2-AC$.
- $\Delta>0$ ise nokta eyer noktasıdır (saddle point); maksimum ya da minimum yoktur.
- $\Delta<0$ ve $A>0$ ise yerel minimumdur.
- $\Delta<0$ ve $A<0$ ise yerel maksimumdur.
- $\Delta=0$ ise test karar vermez.

Bu fonksiyon için:

$$A=f_{xx}=12x^2-14,\qquad B=f_{xy}=-4,\qquad C=f_{yy}=8$$

| Nokta | $A$ | $B$ | $C$ | $\Delta=B^2-AC$ | Sonuç |
|---|---|---|---|---|---|
| $P(0,1)$ | $-14$ | $-4$ | $8$ | $16+112=128>0$ | Eyer noktası |
| $Q(2,2)$ | $34$ | $-4$ | $8$ | $16-272=-256<0$ | Yerel minimum |
| $R(-2,0)$ | $34$ | $-4$ | $8$ | $16-272=-256<0$ | Yerel minimum |

Altyazıda $Q$ için $\Delta=-256$ ve $A>0$ olduğu, dolayısıyla "Q noktasında minimum var" dendiği açıkça geçiyor. $R$ için de $A=34$, $B=-4$ bulunup "delta sıfırdan küçük, $a$ sıfırdan büyükse minimum" deniyor. Tablonun tamamı sympy ile doğrulandı. Fonksiyonun $Q$ ve $R$'deki değeri ikisinde de $-15$, $P$'deki değeri $1$'dir.

<!-- BELİRSİZ: 00:27:05-00:27:31 arası altyazı bozuk ("Küçük o sayıda ne vardı? Maksimum noktasıdır ... çift katlı, ıraksın"). Hocanın burada A<0 durumunu (maksimum) hatırlattığı düşünülüyor. -->

Hoca son olarak ikinci türev testinin maksimum ve minimum noktalarını "elemek için" kullanıldığını söyledi.

## 6. Kapalı Fonksiyon, Zincir Kuralı ve Teğet Düzlem (Örnek 4)

Hoca bir sonraki 2020 final sorusunu ekranda okudu. Soru kısmi türev, zincir kuralı ve kapalı fonksiyon üzerine kuruluydu.

**Örnek 4 (2020 final).** Bir $F(u,v)$ fonksiyonunun belirli bir noktadaki değeri ve kısmi türevleri veriliyor. Bu koşulları sağlayan $F$ için

$$G(x,y,z)=F\big(3yz+x^2,\;2x+2y^2-z^2\big)$$

tanımlanıyor.

- a) $G(x,y,z)=$ sabit yüzeyinin $(0,1,2)$ noktasındaki teğet düzlemini bulunuz.
- b) Verilen bir $\vec r(t)$ eğrisinin, a şıkkında bulunan düzleme paralel olduğu noktadaki teğet doğrusunu bulunuz.

<!-- BELİRSİZ: F'nin verilen değeri ve kısmi türevleri, yüzeyin sabiti ("2020 yüzeyinin" diye geçiyor) ve r(t) eğrisinin bileşenleri ("T kare artı 1, 2T artı T, 4 teksi T kare") altyazıda tam okunmuyor. -->

Soru okunduktan sonra ara verildi. Aradan sonra bu soruya dönülmedi. Hoca ara vermeden önce şunları söyledi: soru kapsamlı ve orijinal bir klasik sınav sorusudur. Testte daha basit gelir; örneğin üç değişkenli değil iki değişkenli hali, değerleri daha kısa olan bir hali sorulur.

> **Hocanın vurgusu:** Çok değişkenli fonksiyonlarda kapalı fonksiyonlar ve zincir kuralı çok önemli.

> **Ek bilgi (derste anlatılmadı):** Bu tür bir sorunun çözüm yolu büyük olasılıkla şudur: $u=3yz+x^2$, $v=2x+2y^2-z^2$ alınır ve zincir kuralıyla $G_x=F_u u_x+F_v v_x$ (benzer şekilde $G_y$, $G_z$) yazılır. $(0,1,2)$'de $u=6$, $v=-2$ olur. Bu noktadaki $\nabla G$, yüzeyin normalidir ve teğet düzlem $\nabla G\cdot(x-0,\,y-1,\,z-2)=0$ ile yazılır. Altyazıdaki "6'ya eksi iki noktası" ifadesi bu $(u,v)=(6,-2)$ noktasıyla uyumludur.

## 7. Kare Bölgede Değişken Dönüşümü (Örnek 5)

### 7.1 Soru

Aradan sonra hoca değişken dönüşümüne bir örnekle daha devam etti.

**Örnek 5.** Köşeleri $(0,0)$, $\left(-\tfrac\pi2,\tfrac\pi2\right)$, $(-\pi,0)$ ve $\left(-\tfrac\pi2,-\tfrac\pi2\right)$ olan kare bölge $D$ olmak üzere

$$\iint_D (x+y)^2\sin(y-x)\,dA$$

integralini hesaplayınız.

### 7.2 Sınır doğruları

Hoca önce dört kenarın denklemini iki noktadan geçen doğru denklemiyle buldu ($L_1$, $L_2$, $L_3$, $L_4$):

- $y=-x$, yani $x+y=0$,
- $y=-x-\pi$, yani $x+y=-\pi$,
- $y=x$, yani $y-x=0$,
- $y=x+\pi$, yani $y-x=\pi$.

<!-- BELİRSİZ: Altyazıda doğru denklemleri karışık okunuyor ("Y'şitir x, y'şitir eksi pi..."); yukarıdaki dört denklem köşe noktalarından hesaplanarak yazıldı. -->

Böylece $y-x$ ifadesi $0$'dan $\pi$'ye, $x+y$ ifadesi $-\pi$'den $0$'a değişir. Hoca bu noktada en kritik sorunun "hangisine $u$, hangisine $v$ diyeceğim" olduğunu söyledi. Cevap yine integrandın içinde: $(x+y)^2$ ve $\sin(y-x)$. Bu ifadeler "kendiliğinden geliyor":

$$u=x+y,\qquad v=y-x$$

> **Ders sonrası not:** Hoca 00:46:34 civarında "$x-y$'ye $u$ diyorsun" dedi. Doğrusu $u=x+y$'dir; hemen öncesinde ve sonrasında da $x+y$ kullanılıyor.

### 7.3 Yeni bölge

Dönüşümle kare, $uv$-düzleminde bir dikdörtgene dönüşür:

$$-\pi\le u\le 0,\qquad 0\le v\le\pi$$

Hoca bunu "$v$ sıfırdan $\pi$'ye, $u$ sıfırdan eksi $\pi$'ye" diye okudu. Köşelerin görüntüleri $(0,0)$, $(0,\pi)$, $(-\pi,\pi)$, $(-\pi,0)$'dır (ara adım eklendi). Bu bölgede integral, sınırları sabit olduğu için rahatça alınır.

### 7.4 Jacobian

Hoca yine ters yoldan gitti:

$$\frac{\partial(x,y)}{\partial(u,v)}=\frac{1}{\begin{vmatrix}u_x&u_y\\v_x&v_y\end{vmatrix}}=\frac{1}{\begin{vmatrix}1&1\\-1&1\end{vmatrix}}=\frac{1}{1+1}=\frac12$$

> **Ders sonrası not:** Hoca determinantı yazarken $v=y-x$ için "$v$'nin $x$'e göre türevi 1" dedi. Doğrusu $v_x=-1$'dir. Tüm girdiler 1 olsaydı determinant 0 olurdu. Doğru determinant $1\cdot1-1\cdot(-1)=2$'dir; hocanın vardığı Jacobian $\tfrac12$ doğrudur.

### 7.5 Dönüştürülmüş integral ve sonuç

$$\iint_D (x+y)^2\sin(y-x)\,dA=\frac12\int_0^\pi\int_{-\pi}^0 u^2\sin v\,du\,dv$$

Hoca integrali bu hale getirip "çok basit hale geliyor" dedi, sonucu derste hesaplamadı. İntegral ayrılabilir olduğu için (ara adım eklendi):

$$\int_{-\pi}^0u^2\,du=\frac{\pi^3}{3},\qquad \int_0^\pi\sin v\,dv=2$$

$$\Rightarrow\ \frac12\cdot\frac{\pi^3}{3}\cdot2=\frac{\pi^3}{3}$$

Sonuç sympy ile doğrulandı.

## 8. Kutupsal Koordinatlarla Hacim (Örnek 6)

### 8.1 Soru

**Örnek 6.** $y^2+(z-1)^2=1$ silindiri ile $x=2$ ve $x+z=5$ düzlemlerinin oluşturduğu kapalı cismin hacmini veren iki katlı kutupsal integral aşağıdakilerden hangisidir?

Hoca $y^2+(z-1)^2=1$'in "çembersel bir yüzey" olduğunu söyledi. $yz$-düzleminde merkezi $(y,z)=(0,1)$, yarıçapı 1 olan çember, $x$ ekseni boyunca uzanan bir silindir oluşturur.

### 8.2 Kurulum

Cisim $x$ yönünde iki düzlem arasında kalır: altta $x=2$, üstte $x=5-z$. Hacim, üstteki yüzeyden alttakini çıkarıp $D$ taban bölgesi üzerinde integral almakla bulunur:

$$V=\iint_D\big[(5-z)-2\big]\,dA=\iint_D(3-z)\,dA$$

Taban bölgesi $D$, $yz$-düzlemindeki $y^2+(z-1)^2\le1$ dairesidir.

### 8.3 Kutupsal koordinatlar

Hoca $z=r\cos\theta$, $y=r\sin\theta$ aldı. Çember denklemi açılırsa $y^2+z^2=2z$ olur, yani $r^2=2r\cos\theta$, $r=2\cos\theta$ (ara adım eklendi). Daire $-\tfrac\pi2\le\theta\le\tfrac\pi2$ aralığında taranır. Kutupsal dönüşümde $dA=r\,dr\,d\theta$ olur; hoca "$r$ geliyor" diye bunu hatırlattı:

$$V=\int_{-\pi/2}^{\pi/2}\int_0^{2\cos\theta}(3-r\cos\theta)\,r\,dr\,d\theta$$

Hoca, testte sorunun bu kadar uzun olmayacağını, şıklarda yalnız bu integralin ya da yalnız integrasyon bölgesinin sorulabileceğini söyledi. Asıl istenen, şekli çizip mantığı kurmaktır.

Sonuç derste hesaplanmadı. Hesaplanırsa $V=2\pi$ çıkar (sympy ile doğrulandı).

## 9. Seri Toplamı: Terim Terim Türev (Örnek 7)

### 9.1 Soru ve genel terim

**Örnek 7 (final sorusu).**

$$\frac34+\frac58+\frac7{16}+\frac9{32}+\cdots$$

serisinin toplamını hesaplayınız.

Önce genel terim $a_n$ bulunmalıdır. Hoca payları ve paydaları ayrı ayrı inceledi:

- Paylar: $3,5,7,9,\dots$ İkişer artıyor. O halde pay $2n+1$.
- Paydalar: $4,8,16,32,\dots$ İkinin kuvvetleri: $2^2,2^3,\dots$ O halde payda $2^{n+1}$.

$$a_n=\frac{2n+1}{2^{n+1}},\qquad n\ge1$$

<!-- BELİRSİZ: 00:58:46-00:59:44 arasında hocanın sesi kesildi (bir öğrenci "sesiniz bir anda gitti" dedi). Seriyi ayırma adımının bu kısmı altyazıda yok; aşağıdaki ayrım hocanın sonraki "A ve B kısımları" anlatımından kuruldu. -->

### 9.2 İki seriye ayırma

Hoca seriyi iki parçaya ("A ve B kısımları") ayırdı:

$$\sum_{n=1}^\infty\frac{2n+1}{2^{n+1}}=\sum_{n=1}^\infty\frac{n}{2^n}+\sum_{n=1}^\infty\frac{1}{2^{n+1}}$$

İkinci kısım geometrik seridir. İlk terimi $\tfrac14$, ortak çarpanı $\tfrac12$'dir:

$$\sum_{n=1}^\infty\frac{1}{2^{n+1}}=\frac{1/4}{1-1/2}=\frac12$$

### 9.3 Terim terim türev

Birinci kısım için hoca bilinen geometrik seriden başladı:

$$\sum_{n=0}^\infty x^n=\frac{1}{1-x},\qquad |x|<1$$

Her iki tarafın türevi alınır; sol tarafta terim terim türev alınır:

$$\sum_{n=1}^\infty n\,x^{n-1}=\frac{1}{(1-x)^2}$$

İki taraf $x$ ile çarpılır (ara adım eklendi):

$$\sum_{n=1}^\infty n\,x^{n}=\frac{x}{(1-x)^2}$$

$x=\tfrac12$ konunca:

$$\sum_{n=1}^\infty\frac{n}{2^n}=\frac{1/2}{1/4}=2$$

### 9.4 Sonuç

$$\sum_{n=1}^\infty\frac{2n+1}{2^{n+1}}=2+\frac12=\frac52$$

Hoca sonucu "5 bölü 2" olarak verdi. Sonuç sympy ile doğrulandı. Hoca bu yöntemin, yani terim terim türev alma ve terim terim integre etme ile toplam bulmanın, seri sorularında normal yol olduğunu söyledi. Benzer bir sorunun önceki yıllarda da çıktığını ekledi.

## 10. Serinin Karakteri: Limit Karşılaştırma Testi (Örnek 8)

**Örnek 8 (final sorusu).** Verilen bir serinin karakterini (yakınsak mı ıraksak mı) belirleyiniz.

<!-- BELİRSİZ: Serinin genel terimi altyazıda okunmuyor ("En önce mertebeden 2020-1 serisinin karakterini..." diye geçiyor). Limit değeri de 01:03:00'da "[öğrenci] 2020" diye maskelenmiş görünüyor. -->

Hoca seriyi ıraksak olduğu bilinen harmonik seriyle ($\sum\tfrac1n$) karşılaştırdı. Limit karşılaştırma testi uygulandı: iki serinin genel terimlerinin oranının limiti alındı. Limit sıfırdan ve sonsuzdan farklı çıktı. Bu durumda iki seri aynı karakterdedir. Harmonik seri ıraksak olduğundan verilen seri de ıraksaktır.

**Limit karşılaştırma testi.**

- $a_n,b_n>0$ ve $\lim\limits_{n\to\infty}\dfrac{a_n}{b_n}=L$ olsun.
- $0<L<\infty$ ise $\sum a_n$ ve $\sum b_n$ aynı karakterdedir: ikisi birlikte yakınsar ya da birlikte ıraksar.

Hoca bu sorunun ilk bakışta akla gelmesinin kolay olmadığını söyledi. Seriyi uygun biçimde yazıp $n$ ile düzenlemeyi ve hangi seriyle karşılaştırılacağını görmeyi gerektiriyor. Bunu görebilmek için bol uygulama yapmak gerekir.

Hoca ayrıca karşılaştırılan ifadenin paydasında $n$ yerine $n^2$ ya da $n^3$ olsaydı, karşılaştırmanın $\sum\tfrac1{n^2}$ ya da $\sum\tfrac1{n^3}$ ile yapılacağını ve serinin yakınsak olacağını söyledi.

## 11. Gradyan, En Hızlı Artış Yönü ve Teğet Düzlem (Örnek 9)

### 11.1 Soru

**Örnek 9 (2020 bütünleme).** $f$ ve $g$, bir $P$ noktasında aşağıdaki koşulları sağlayan türevlenebilir iki fonksiyondur:

- $f(P)=2$, $g(P)=5$,
- $g_x(P)=-1$,
- $f$'nin $P$'deki en hızlı artışı $\vec u$ yönünde gerçekleşiyor ve bu yöndeki türevin değeri 6,
- $f+2g=12$ yüzeyinin $P$ noktasındaki teğet düzleminin denklemi veriliyor.

Buna göre $g_y(P)$'yi hesaplayınız.

<!-- BELİRSİZ: u yönü (<1,-8,4>) ve teğet düzlemin normali (<4,2,3>) altyazıda okunmuyor; kısa notta ekrandan okunan değerler kullanıldı. Hocanın sözlü okuduğu ∇f(P)=<2/3,-16/3,8/3> ve k=2/3 bu değerlerle uyumlu. -->

### 11.2 Gradyanın bulunması

En hızlı artış gradyan yönündedir. Bu yüzden $\nabla f(P)$, $\vec u=\langle1,-8,4\rangle$'e paraleldir:

$$\nabla f(P)=k\langle1,-8,4\rangle,\qquad k>0$$

En hızlı artış yönündeki türev, gradyanın boyudur:

$$|\nabla f(P)|=k\sqrt{1+64+16}=9k=6\ \Rightarrow\ k=\frac23$$

$$\nabla f(P)=\Big\langle\frac23,\,-\frac{16}3,\,\frac83\Big\rangle$$

Hoca bu değerleri sözlü olarak okudu ("2 bölü 3, eksi 16 bölü 3, 8 bölü 3").

### 11.3 Teğet düzlemden $g_y(P)$

$H=f+2g-12$ alınırsa yüzey $H=0$ olur. $P$ bu yüzey üzerindedir, çünkü $f(P)+2g(P)=2+10=12$ (ara adım eklendi). Yüzeyin $P$'deki normali $\nabla H(P)=\nabla f(P)+2\nabla g(P)$'dir ve teğet düzlemin normali $\langle4,2,3\rangle$'e paralel olmalıdır:

$$\nabla f(P)+2\nabla g(P)=c\langle4,2,3\rangle$$

$x$ bileşeninden $c$ bulunur:

$$\frac23+2(-1)=4c\ \Rightarrow\ -\frac43=4c\ \Rightarrow\ c=-\frac13$$

$y$ bileşeninden istenen değer bulunur:

$$-\frac{16}{3}+2g_y(P)=2c=-\frac23\ \Rightarrow\ 2g_y(P)=\frac{14}{3}\ \Rightarrow\ g_y(P)=\frac73$$

Hoca son adımları ekranda gösterip hızlı geçti ("yerlere yerleştirip sonuca ulaşmış oluyoruz"). Yukarıdaki hesap sympy ile doğrulandı.

## 12. Lineerleştirme ile Yönlü Türev (Örnek 10)

### 12.1 Lineerleştirme formülü

Ders bitmek üzereyken hoca bir lineerleştirme (linearization) sorusu daha gösterdi. Bunun kısmi türevin bir uygulaması olduğunu, tek değişkenli fonksiyonlarda görülenin bir başka versiyonu olduğunu söyledi.

**Lineerleştirme.**

- Tek değişkenli: $L(x)=f(a)+f'(a)(x-a)$.
- İki değişkenli: $L(x,y)=f(a,b)+f_x(a,b)(x-a)+f_y(a,b)(y-b)$.
- $(a,b)$'ye yakın noktalarda $f(x,y)\approx L(x,y)$.

### 12.2 Soru

**Örnek 10 (2020 bütünleme, Soru 6).** $f(1,3)=-2$ ve $f(1{,}02;\,2{,}99)=-1{,}98$ koşullarını sağlayan bir $f$ fonksiyonu için, $P(1,3)$ noktasında $\vec v=-4\vec i+2\vec j$ yönündeki türevin değerini yaklaşık olarak hesaplayınız.

<!-- BELİRSİZ: f(1,3), f(1.02; 2.99) ve v vektörü altyazıda sözlü okunmuyor; kısa notta ekrandan okunan değerler kullanıldı. Altyazıdaki Δx=0,02 ve Δy=-0,01 bu değerlerle uyumlu. -->

### 12.3 Çözüm

$(a,b)=(1,3)$ alınır. Hoca $\Delta x=0{,}02$, $\Delta y=-0{,}01$ olduğunu söyledi ("3'e tamamlamak için"). Lineerleştirme:

$$-1{,}98\approx-2+f_x(1,3)\cdot0{,}02+f_y(1,3)\cdot(-0{,}01)$$

$$0{,}02\approx0{,}02f_x-0{,}01f_y\ \Rightarrow\ 2f_x-f_y\approx2$$

Yönlü türev için birim vektör gerekir: $|\vec v|=\sqrt{16+4}=\sqrt{20}=2\sqrt5$.

$$D_{\vec u}f(P)=\nabla f\cdot\frac{\vec v}{|\vec v|}=\frac{-4f_x+2f_y}{2\sqrt5}=-\frac{2f_x-f_y}{\sqrt5}\approx-\frac{2}{\sqrt5}\approx-0{,}894$$

Hoca bu son adımları ekranda gösterdi, sesli okumadı. Sonuç yukarıdaki gibi hesaplanarak eklendi. Hoca soruyu "güzel bir soru" olarak niteledi.

> **Ek bilgi (derste anlatılmadı):** Bu soruda $f_x$ ve $f_y$ ayrı ayrı bulunamaz; yalnız $2f_x-f_y$ birleşimi bilinir. Soru, istenen yönün $\langle-4,2\rangle=-2\langle2,-1\rangle$ olması sayesinde tam bu birleşime bağlıdır. Yani artış vektörü $\langle0{,}02;\,-0{,}01\rangle$ ile istenen yön aynı doğru üzerindedir.

## Örnek Sorular

Bu derste kare ya da video yoktu. Aşağıdaki sorular hocanın ekranda gösterip sözlü okuduğu ve derste çözdüğü sorulardır.

**Soru 1** (derste sözlü, 00:03:27). $\displaystyle\int_0^1\int_{2y}^{5-3y}\frac{x-2y}{(x+3y)^2}\cos(x+3y)\,dx\,dy$ integralini hesaplayınız.

> **Çözüm (derste verildi):** $u=x-2y$, $v=x+3y$; bölge $0\le u\le v$, $0\le v\le5$; $J=\tfrac15$. Sonuç $\dfrac{\sin5}{10}$. Ayrıntı Bölüm 2'de.

**Soru 2** (derste sözlü, 00:13:11). $F(x,y)=\dfrac{4y(2x^3-xy^2)}{4x^2+3y^2}$, $(x,y)\ne(0,0)$; $F(0,0)=0$ için $F_{xy}(0,0)$ nedir?

> **Çözüm (derste verildi):** $F_x(0,0)=0$, $F_x(0,h)=-\tfrac{4h}{3}$, $F_{xy}(0,0)=-\tfrac43$. Ayrıntı Bölüm 3'te.

<!-- BELİRSİZ: Soru 2'deki fonksiyonun formülü kısa nottaki ekran okumasından. -->

**Soru 3** (derste sözlü, 00:18:52). $f(x,y)=x^4-4xy-7x^2+4x+4y^2-8y+5$ fonksiyonunun tüm kritik noktalarını bulup sınıflandırınız.

> **Çözüm (derste verildi):** $P(0,1)$ eyer noktası, $Q(2,2)$ ve $R(-2,0)$ yerel minimum. Ayrıntı Bölüm 5'te.

**Soru 4** (derste sözlü, 00:28:45). $G(x,y,z)=F(3yz+x^2,\;2x+2y^2-z^2)$ için $G=$ sabit yüzeyinin $(0,1,2)$ noktasındaki teğet düzlemini bulunuz; verilen $\vec r(t)$ eğrisinin bu düzleme paralel olduğu noktadaki teğet doğrusunu bulunuz.

> **Çözüm (derste verilmedi):** $F$'nin verilen değerleri ve $\vec r(t)$ altyazıda okunmadığı için çözüm kesinleştirilemedi. Yol Bölüm 6'daki ek bilgi bloğunda.

<!-- BELİRSİZ: Soru 4'ün sayısal verileri altyazıda eksik. -->

**Soru 5** (derste sözlü, 00:42:10). Köşeleri $(0,0)$, $(-\tfrac\pi2,\tfrac\pi2)$, $(-\pi,0)$, $(-\tfrac\pi2,-\tfrac\pi2)$ olan kare bölge $D$ üzerinde $\iint_D(x+y)^2\sin(y-x)\,dA$ integralini hesaplayınız.

> **Çözüm (derste verildi, son hesap yapılmadı):** $u=x+y$, $v=y-x$, $J=\tfrac12$; $\tfrac12\int_0^\pi\int_{-\pi}^0u^2\sin v\,du\,dv=\dfrac{\pi^3}{3}$ (son değer sympy ile hesaplandı). Ayrıntı Bölüm 7'de.

**Soru 6** (derste sözlü, 00:54:04). $y^2+(z-1)^2=1$ silindiri ile $x=2$ ve $x+z=5$ düzlemlerinin oluşturduğu kapalı cismin hacmini veren iki katlı kutupsal integral hangisidir?

> **Çözüm (derste verildi, son hesap yapılmadı):** $V=\int_{-\pi/2}^{\pi/2}\int_0^{2\cos\theta}(3-r\cos\theta)\,r\,dr\,d\theta=2\pi$ (son değer sympy ile hesaplandı). Ayrıntı Bölüm 8'de.

**Soru 7** (derste sözlü, 00:57:41). $\dfrac34+\dfrac58+\dfrac7{16}+\dfrac9{32}+\cdots$ serisinin toplamını hesaplayınız.

> **Çözüm (derste verildi):** $a_n=\dfrac{2n+1}{2^{n+1}}$; $\sum\tfrac{n}{2^n}=2$, $\sum\tfrac1{2^{n+1}}=\tfrac12$; toplam $\tfrac52$. Ayrıntı Bölüm 9'da.

**Soru 8** (derste sözlü, 01:02:26). Verilen serinin karakterini belirleyiniz.

<!-- BELİRSİZ: Serinin genel terimi altyazıda okunmuyor. -->

> **Çözüm (derste verildi):** Harmonik seriyle limit karşılaştırma testi; limit sıfırdan ve sonsuzdan farklı, seri ıraksak. Ayrıntı Bölüm 10'da.

**Soru 9** (derste sözlü, 01:04:43). $f(P)=2$, $g(P)=5$, $g_x(P)=-1$; $f$'nin $P$'deki en hızlı artışı $\vec u=\langle1,-8,4\rangle$ yönünde ve bu yöndeki türev 6; $f+2g=12$ yüzeyinin $P$'deki teğet düzleminin normali $\langle4,2,3\rangle$'e paralel. $g_y(P)$ nedir?

> **Çözüm (derste verildi):** $\nabla f(P)=\langle\tfrac23,-\tfrac{16}3,\tfrac83\rangle$, $c=-\tfrac13$, $g_y(P)=\tfrac73$. Ayrıntı Bölüm 11'de.

**Soru 10** (derste sözlü, 01:08:14). $f(1,3)=-2$, $f(1{,}02;\,2{,}99)=-1{,}98$ ise $f$'nin $P(1,3)$'teki $\vec v=-4\vec i+2\vec j$ yönündeki türevinin yaklaşık değeri nedir?

> **Çözüm (derste verildi, son adım sesli okunmadı):** $2f_x-f_y\approx2$; $D_{\vec u}f\approx-\dfrac{2}{\sqrt5}\approx-0{,}894$. Ayrıntı Bölüm 12'de.

## Dersin Toparlaması

Bu ders, dönem boyunca görülen çok değişkenli analiz konularını geçmiş yıl final ve bütünleme soruları üzerinden bir araya getirdi. İki katlı integralde değişken dönüşümünün adımları iki örnekle pekişti: önce bölge çizilir, sonra integrandın ve sınırların içindeki ifadelerden $u$ ve $v$ seçilir, sınırlar yeni değişkenlerle yazılır, Jacobian ise çoğu zaman ters yoldan $\dfrac{1}{\partial(u,v)/\partial(x,y)}$ olarak bulunur. Kutupsal koordinatlarla hacim kurulumu da aynı mantığın bir başka uygulaması olarak görüldü.

Kısmi türev tarafında parçalı bir fonksiyonun karışık kısmi türevi tanımla hesaplandı. Karışık türevlerin yalnız süreklilik koşulu altında eşit olduğu, çok değişkenli fonksiyonlarda kısmi türevlerin var olup fonksiyonun süreksiz olabileceği vurgulandı. Kritik noktalar ikinci türev testiyle sınıflandırıldı; gradyanın en hızlı artış yönü olduğu ve teğet düzlem normalinin gradyandan geldiği bir soruda kullanıldı; lineerleştirme ile yönlü türev yaklaşık hesaplandı. Seriler tarafında genel terimi bulup terim terim türev alarak toplam hesaplandı ve limit karşılaştırma testiyle bir serinin karakteri belirlendi. Hoca, integral konusunun kalan kısmının önümüzdeki hafta tamamlanacağını, sonraki hafta da genel tekrara geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
