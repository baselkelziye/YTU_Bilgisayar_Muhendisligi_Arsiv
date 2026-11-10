# Ders 25 Genişletilmiş Notu: Tanjant Dönüşümü, İntegralle Alan Hesabı ve Disk Yöntemi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çerçevesi
- 2. Son Trigonometrik Dönüşüm: $x = a\tan t$
- 3. Diskriminantı Negatif İkinci Derece İfadeler
- 4. İntegralin Uygulamaları: Alan Hesabı ve Tarama Çubuğu
- 5. Alan Hesabı Örnekleri
- 6. Dönel Cisimlerin Hacmi: Disk Yöntemi
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Çerçevesi

Bu ders 2. vizeden sonraki ilk derstir. Ders İngilizce anlatıldı, arada Türkçe açıklamalar yapıldı. Hoca tablete (whiteboard) yazarak anlattı. Altyazıda yalnız sözlü kısım olduğu için formüller hocanın sözlü anlatımından kuruldu.

Hoca derse, iki farklı şubeye ders verdiği için hangi konuda kaldıklarını karıştırdığını söyleyerek başladı. Rasyonel fonksiyonların integrallerini, payın derecesi paydanınkinden büyükken polinom bölmesiyle basit kesirlere ayırmayı ve trigonometrik dönüşümleri görmüşlerdi. İlk iki trigonometrik dönüşüm, $x = a\sin t$ ve $x = a\sec t$, işlenmişti. Geriye son dönüşüm olan $x = a\tan t$ kalmıştı.

Hoca, final haftasından önce konuları bitirmek gerektiğini, bu yüzden biraz hızlanacaklarını söyledi. Plan, bu hafta ve gelecek hafta konuları bitirip sonra sınava yönelik genel soru çözmekti.

## 2. Son Trigonometrik Dönüşüm: $x = a\tan t$

### 2.1 Dönüşümün Fikri

Hoca, dönüşümün nereden geldiğini $\arctan$ fonksiyonunun türeviyle açıkladı. $\arctan x$'in türevi $\dfrac{1}{1+x^2}$'dir. Bu ifadede $1 + x^2$, yani $a = 1$ için $x^2 + a^2$ biçimi vardır. Tanjant ile $x^2 + a^2$ arasında bir ilişki olduğu buradan görülür.

Bu yüzden integralde $x^2 + a^2$ biçiminde bir ifade görürseniz $x = a\tan t$ dönüşümü yapmak işinizi kolaylaştırır. Hoca Türkçe olarak şunu vurguladı: $x^2 + a^2$ hele bir kare kökün içindeyse, bu dönüşüm kesinlikle avantaj sağlar ve problemi trigonometrik bir integrale çevirir.

Dönüşümün adımları:

- $x = a\tan t$ ise her iki tarafın diferansiyeli alınır: $dx = a\sec^2 t\,dt$.
- $x^2 + a^2 = a^2\tan^2 t + a^2 = a^2(\tan^2 t + 1) = a^2\sec^2 t$.
- Kök içindeyse: $\sqrt{x^2 + a^2} = a\,|\sec t|$.
- Hoca $a > 0$ olduğunu ve $\sec t > 0$ olan bir aralıkta çalışıldığını varsaydı. Bu varsayımla $\sqrt{x^2+a^2} = a\sec t$ olur.

Böylece kısa notta da verilen dönüşüm tablosu tamamlanmış oldu:

| İfade | Dönüşüm | Sadeleşme |
|---|---|---|
| $\sqrt{a^2 - x^2}$ | $x = a\sin t$ | $a\cos t$ |
| $\sqrt{x^2 - a^2}$ | $x = a\sec t$ | $a\tan t$ |
| $\sqrt{x^2 + a^2}$ | $x = a\tan t$ | $a\sec t$ |

### 2.2 Örnek 1: $\displaystyle\int\frac{dx}{x^2+a^2}$

Hoca bu integrali iki yolla hesapladı.

**Birinci yöntem:** Paydada $a^2$ ortak paranteze alınır. Böylece $\dfrac{1}{a^2}\displaystyle\int\frac{dx}{1+(x/a)^2}$ elde edilir. $u = \dfrac{x}{a}$ dönüşümüyle sonuç bulunur:

$$\int\frac{dx}{x^2+a^2} = \frac1a\arctan\frac xa + C$$

**İkinci yöntem:** $x = a\tan t$ dönüşümü yapılır.

1. $dx = a\sec^2 t\,dt$.
2. $x^2 + a^2 = a^2\sec^2 t$. Burada kök yoktur.
3. İntegral: $$\int\frac{a\sec^2 t\,dt}{a^2\sec^2 t} = \frac1a\int dt = \frac1a t + C$$
4. $x = a\tan t$ eşitliğinden $t = \arctan\dfrac xa$. Sonuç birinci yöntemle aynıdır: $\dfrac1a\arctan\dfrac xa + C$.

### 2.3 Örnek 2: $\displaystyle\int\frac{dx}{\sqrt{x^2+a^2}}$

Hoca bunu "ikinci önemli problem" olarak verdi.

1. $x = a\tan t$, $dx = a\sec^2 t\,dt$, $\sqrt{x^2+a^2} = a\sec t$.
2. $$\int\frac{a\sec^2 t\,dt}{a\sec t} = \int\sec t\,dt$$
3. $\sec t$'nin integralini hatırlamıyorsanız şu yol izlenir: Pay ve payda $\sec t + \tan t$ ile çarpılır. $$\int\sec t\,dt = \int\frac{\sec t(\sec t + \tan t)}{\sec t + \tan t}\,dt$$ $u = \sec t + \tan t$ denirse pay tam $du$ olur (ara adım eklendi: $du = (\sec t\tan t + \sec^2 t)\,dt$). Sonuç $\ln|u| + C = \ln|\sec t + \tan t| + C$.
4. Sonucu $x$ cinsinden yazmak için bir dik üçgen çizilir. $\tan t = \dfrac xa$ olduğundan karşı kenar $x$, komşu kenar $a$, hipotenüs $\sqrt{x^2+a^2}$ olur.
5. Üçgenden $\cos t = \dfrac{a}{\sqrt{x^2+a^2}}$, dolayısıyla $\sec t = \dfrac{\sqrt{x^2+a^2}}{a}$ ve $\tan t = \dfrac xa$.
6. Sonuç: $$\int\frac{dx}{\sqrt{x^2+a^2}} = \ln\left|\frac{\sqrt{x^2+a^2}}{a} + \frac xa\right| + C$$

<!-- BELİRSİZ: 00:09:53-00:10:21 arasında altyazı kesik ("ve bu", "2 t"); dönüşümün integrale yerleştirilmesi sözlü olarak duyulmuyor, adımlar 00:10:21 sonrasından ve bağlamdan kuruldu. -->

Hoca bunların basit örnekler olduğunu, ama çok şey anlattıklarını ve sınavda bu tarz örneklerle karşılaşılabileceğini söyledi.

### 2.4 Örnek 3: $\displaystyle\int\frac{dx}{x\sqrt{x^2+a^2}}$

Hoca bu soruyu öğrencilere görev olarak verdi ve "basitten zora doğru" örnekler yazacağını söyledi.

<!-- BELİRSİZ: 00:13:00'da soru metni "dx over x times square root of" diye kesiliyor; kök içindeki ifadenin $x^2+a^2$ olduğu, hocanın sonraki çözüm adımlarından ($a\tan t\cdot a\sec t$ paydası) çıkarıldı. -->

1. $x = a\tan t$, $dx = a\sec^2 t\,dt$, $\sqrt{x^2+a^2} = a\sec t$.
2. $$\int\frac{a\sec^2 t\,dt}{a\tan t\cdot a\sec t} = \frac1a\int\frac{\sec t}{\tan t}\,dt$$
3. $\dfrac{\sec t}{\tan t} = \dfrac{1}{\cos t}\cdot\dfrac{\cos t}{\sin t} = \dfrac{1}{\sin t} = \csc t$.
4. Böylece integral $\dfrac1a\displaystyle\int\csc t\,dt$ olur.

Hoca önce $\dfrac1a$ katsayısını unuttu. Bir öğrenci "bir $a$ var" diye uyardı, hoca bunu düzeltti.

5. $\csc t$'nin integrali, $\sec t$'ye benzer şekilde, pay ve payda $\csc t + \cot t$ ile çarpılarak bulunur. $u = \csc t + \cot t$ denir.

Hoca buradan sonrasını, yani sonucun üçgen yardımıyla $x$ cinsinden yazılmasını ödev olarak bıraktı. Sonucun tamamı "Örnek Sorular" bölümündedir.

> **Ders sonrası not:** Hoca $\csc t$ integralinin işaretini yazmadı. $u = \csc t + \cot t$ için $du = -(\csc t\cot t + \csc^2 t)\,dt = -\csc t\,(\csc t + \cot t)\,dt$ olduğundan $\displaystyle\int\csc t\,dt = -\ln|\csc t + \cot t| + C$ çıkar. Yani Örnek 3'ün $t$ cinsinden sonucu $-\dfrac1a\ln|\csc t + \cot t| + C$'dir.

## 3. Diskriminantı Negatif İkinci Derece İfadeler

### 3.1 Örnek 4: $\displaystyle\int\frac{dx}{\sqrt{4x^2+9}}$

Hoca önce şu soruyu sordu: Bu problemi trigonometrik bir integrale çevirmek için en iyi dönüşüm hangisidir? İpucu ikinci derece ifadenin diskriminantıydı. $4x^2 + 9$ ifadesinde $b$ yoktur. Diskriminant $b^2 - 4ac$ negatiftir.

<!-- BELİRSİZ: 00:20:51-00:21:00'da hoca diskriminantı "minus 9 negatif" gibi söylüyor; tam ifade duyulmuyor. $4x^2+9$ için $b^2-4ac = -144$'tür, işaret negatif olduğu için sonuç değişmez. -->

1. $4x^2 + 9 = (2x)^2 + 3^2$ biçiminde yazılır.
2. Bu yüzden $2x = 3\tan t$, yani $x = \dfrac32\tan t$ dönüşümü yapılır.
3. $dx = \dfrac32\sec^2 t\,dt$.
4. $(2x)^2 = 9\tan^2 t$ olduğundan kök: $\sqrt{9\tan^2 t + 9} = 3\sqrt{\tan^2 t + 1} = 3\sec t$.
5. $$\int\frac{\frac32\sec^2 t\,dt}{3\sec t} = \frac12\int\sec t\,dt = \frac12\ln|\sec t + \tan t| + C$$
6. Üçgen: $\tan t = \dfrac{2x}{3}$. Karşı kenar $2x$, komşu kenar $3$, hipotenüs $\sqrt{9 + 4x^2}$.

Sonucu $x$ cinsinden yazmak yine ödev olarak bırakıldı. Tamamı "Örnek Sorular" bölümündedir.

### 3.2 Örnek 5: $\displaystyle\int\frac{dx}{\sqrt{x^2+4x+8}}$

Hoca burada genel bir kural verdi: Böyle bir ifade gördüğünüzde önce ikinci derece ifadenin diskriminantını bulun. Diskriminant negatifse $u = a\tan t$ tarzında bir dönüşüm yapacaksınız demektir. Bunun için ikinci derece ifadeyi $u^2 + a^2$ biçimine benzetecek şekilde düzenlemelisiniz.

1. Diskriminant: $4^2 - 4\cdot 1\cdot 8 = 16 - 32 < 0$.
2. Tam kareye tamamlama: $(x+2)^2 = x^2 + 4x + 4$. İfadede sabit terim 8 olduğu için $x^2 + 4x + 8 = (x+2)^2 + 2^2$.
3. $u = x + 2$, $a = 2$. Dönüşüm: $x + 2 = 2\tan t$, $dx = 2\sec^2 t\,dt$.
4. $\sqrt{(x+2)^2 + 4} = \sqrt{4\tan^2 t + 4} = 2\sec t$.
5. $$\int\frac{2\sec^2 t\,dt}{2\sec t} = \int\sec t\,dt = \ln|\sec t + \tan t| + C$$
6. Üçgen: $\tan t = \dfrac{x+2}{2}$. Karşı kenar $x + 2$, komşu kenar $2$, hipotenüs $\sqrt{x^2+4x+8}$. Her terim bu üçgenle $x$ cinsinden yazılır.

Hoca bunların temel sorular olduğunu, işin mantığını öğrenmek için çözüldüğünü söyledi. Gelecek hafta daha karmaşık örnekler çözeceklerini ekledi.

### 3.3 Ertelenen Soru

Hoca ardından, ayrı bir konu sayılabilecek ama uzun anlatmayacağı, "çok nadir gelen bir soru tipi" olarak tanıttığı bir soruyu yazdı ve yanına üç yıldız koydu. Sonra bu soruyu şimdi çözmenin zor olacağını söyleyip gelecek haftaya bıraktı.

<!-- BELİRSİZ: 00:30:48-00:31:47 arasında yazılan üç yıldızlı sorunun metni altyazıda geçmiyor. -->

## 4. İntegralin Uygulamaları: Alan Hesabı ve Tarama Çubuğu

Hoca yeni konuya geçti: integralin uygulamaları (application of integration). İlk uygulama alan hesabıdır (computing areas). Hoca önce temel durumları anlattı, sonra genel durumu verdi.

### 4.1 Durum 1: Bir Eğrinin Altındaki Bölge (Dikey Tarama)

$y = f(x)$, $[a,b]$ aralığında sürekli ve pozitif olsun. Bölge, $[a,b]$ aralığının üstünde ve $y = f(x)$'in grafiğinin altındadır.

Hoca bölgenin içine bir doğru parçası çizdi ve bu parçaya "yakınlaştırdı". Yakından bakınca doğru parçasının bir kalınlığı olduğu görülür. Bu kalınlık $dx$'tir. Çubuğun yüksekliği ise $f(x)$'tir.

<!-- BELİRSİZ: 00:34:44-00:36:08 arasında altyazı döngüye girmiş ("bu bölümde" tekrarı ve anlamsız satırlar); bu kısımdaki anlatım altyazıda anlaşılmıyor. Akış 00:36:08 sonrasındaki özetten kuruldu. -->

Bu çubuk bir tarama çubuğudur (scanning bar). Çubuk dikeydir ve alt uç noktası $[a,b]$ aralığı üzerinde dolaşır. Tarama sırasında çubuğun uzunluğu, alt ucun $[a,b]$ üzerindeki konumuna göre değişir.

Hoca bu mantığı Türkçe olarak tekrar anlattı ve çok önemli olduğunu söyledi:

- Bu bölgeyi en güzel şekilde dikey bir çubukla tararız. Çubuk $[a,b]$ aralığına diktir ve alt ucu $[a,b]$ üzerinde dolaşır.
- Çubuğun kalınlığı $dx$'tir.
- Dikey taramada en alt sınır $x = a$, en üst sınır $x = b$'dir.
- Çubuğun yüksekliği $f(x)$'tir. Her seferinde yükseklik ile kalınlığı çarpıp toplarsak integral, yani bölgenin alanı elde edilir.

$$A = \int_a^b f(x)\,dx$$

> **Hocanın vurgusu:** Bu tarama mantığını çok sık kullanacağız. Çok değişkenli fonksiyonlarda da bu mantık kullanılıyor.

### 4.2 Durum 2: $x = g(y)$ ile Sınırlı Bölge (Yatay Tarama)

İkinci durumda bölge $x = 0$ (yani $y$ ekseni) ile $x = g(y)$ eğrisi arasındadır. Hoca öğrencilere sordu: Bu bölgeyi taramak için hangi tür çubuk uygundur, dikey mi, yatay mı? Öğrenciler "yatay" (horizontal) diye cevap verdi.

Yatay bir çubuk konursa:

- Sağ uç nokta daima $x = g(y)$ üzerindedir. Bu noktaya $x_2$ denir.
- Sol uç nokta daima $x = 0$ üzerindedir. Bu noktaya $x_1$ denir.
- İki ucun $y$ koordinatı aynıdır: $(x_1, y)$ ve $(x_2, y)$.

Çubuğun uzunluğu uzaklık formülüyle bulunur:

$$\sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$$

$y_1 = y_2 = y$ olduğundan ikinci terim sıfırdır. Uzunluk $|x_2 - x_1|$ olur.

<!-- BELİRSİZ: 00:40:41'de altyazı bozuluyor; hoca 00:41:21'de beyaz tahtanın yanlışlıkla silindiğini söyleyip çizimi yeniden yapıyor. -->

Hoca çizimi yeniden yaptıktan sonra en önemli noktayı vurguladı: Yatay çubuğun kalınlığı $dy$'dir. Bu, bütün bilgilerin $y$ cinsinden yazılması gerektiği anlamına gelir. Çünkü integral değişkeni (hocanın Türkçe deyişiyle "kaynaştırma değişkeni") $y$'dir.

- Çubuğun alanı: $dA = (\text{uzunluk})\times(\text{kalınlık}) = (x_2 - x_1)\,dy$.
- $x_2 = g(y)$, $x_1 = 0$. Yani $dA = (g(y) - 0)\,dy$.
- Alt sınır $y = c$, üst sınır $y = d$ ise her iki tarafın integrali alınır:

$$A = \int_c^d g(y)\,dy$$

Hoca, formülün arkasındaki mantığın bu olduğunu, formülü tarama mantığıyla özdeşleştirerek akılda tutabileceğimizi söyledi.

### 4.3 Durum 3: İki Eğri Arasındaki Bölge (Kesişim Yok)

Bölge $y = f(x)$ ile $y = g(x)$ arasında olsun ve eğriler $[a,b]$ içinde kesişmesin. Grafiğe göre üst uç nokta daima $f(x)$ üzerinde, alt uç nokta daima $g(x)$ üzerindedir. Bu, $f(x) \ge g(x)$ demektir.

- Çubuğun kalınlığı $dx$. Dolayısıyla integral değişkeni $x$'tir ve her bilgi $x$ cinsinden yazılır.
- Çubuğun yüksekliği uzaklık formülüyle: $|f(x) - g(x)| = f(x) - g(x)$.
- Tarama $x = a$'dan $x = b$'ye yapılır.

$$A = \int_a^b \big[f(x) - g(x)\big]\,dx$$

<!-- BELİRSİZ: 00:46:00 ve 00:46:56 civarında altyazı bozuk ("Yif'in yi'in", "Yeni Yeni"). -->

### 4.4 Durum 4: İki Eğri Arasındaki Bölge (Yatay Tarama)

Hoca bir sonrakini "benzer mantıkla yapabilirsiniz" diyerek hızlıca anlattı. Bölge $x = g(y)$ (sağda) ile $x = h(y)$ (solda) arasındadır.

- Yatay taramada sol uç daima $h(y)$, sağ uç daima $g(y)$ üzerindedir. Bu yüzden $g(y) \ge h(y)$.
- Çubuğun kalınlığı $dy$, integral değişkeni $y$.
- Çubuğun uzunluğu $|g(y) - h(y)| = g(y) - h(y)$.

$$A = \int_c^d \big[g(y) - h(y)\big]\,dy$$

### 4.5 Genel Durum: Eğriler Kesişiyorsa

Son olarak hoca en genel hâli verdi. $y = f(x)$ ve $y = g(x)$ eğrileri $[a,b]$ içinde $c_1$ ve $c_2$ noktalarında kesişsin. Bu bölgeyi taramanın en iyi yolu dikey taramadır. Ama tarama sırasında üst ve alt uç noktalar değişir.

Çubuğun uzunluğu her durumda uzaklık formülüyle verilir: $|f(x) - g(x)|$. Bu yüzden genel formül:

$$A = \int_a^b |f(x) - g(x)|\,dx$$

Mutlak değeri kaldırmak için integral kesişim noktalarında parçalara bölünür. Hocanın çizdiği şekle göre:

- $[a, c_1]$'de üst uç $f(x)$, alt uç $g(x)$ üzerinde: $f - g \ge 0$.
- $[c_1, c_2]$'de üst uç $g(x)$, alt uç $f(x)$ üzerinde: $g - f \ge 0$.
- $[c_2, b]$'de yine üst uç $f(x)$, alt uç $g(x)$ üzerinde.

$$A = \int_a^{c_1}\big[f(x) - g(x)\big]dx + \int_{c_1}^{c_2}\big[g(x) - f(x)\big]dx + \int_{c_2}^{b}\big[f(x) - g(x)\big]dx$$

> **Hocanın vurgusu:** Çubuğa odaklanın. Çubuğun uç noktaları tarama sırasında daima kimin üzerinde kalıyor, ona ve çubuğun kalınlığına bakın. Böylece integrali inşa etmiş olursunuz.

Bu bölümden sonra 15 dakikalık ara verildi.

## 5. Alan Hesabı Örnekleri

Aradan sonra hoca, bütün durumlardan bahsettiklerini ve artık mantığı anladıklarını söyledi.

> **Hocanın vurgusu:** Test sınavlarında genellikle integralin sonucu değil, "şu bölgenin alanını veren integrali ifade edin" diye sorulur. Bu yüzden integral modelini kurabilmek önemlidir.

### 5.1 Örnek 6: $y = \sqrt x$, $y = 0$ ve $x = 4$ ile Sınırlı Bölge

**Soru:** $R$ bölgesi $y = \sqrt x$, $y = 0$ doğrusu ve $x = 4$ doğrusuyla sınırlıdır.

- (a) $R$'nin alanını veren integrali dikey kesitlerle (vertical cross-sections) ifade edin.
- (b) $R$'nin alanını veren integrali yatay kesitlerle (horizontal cross-sections) ifade edin.
- (c) $R$'nin alanını hesaplayın.

**Çizim:** $y^2 = x$ eğrisinin iki kolu vardır: üst kol $y = \sqrt x$, alt kol $y = -\sqrt x$. $y = \sqrt x$ üst koldur. Bölge, bu kol, $x$ ekseni ve $x = 4$ doğrusu arasında kalan kısımdır.

**(a) Dikey tarama:**

- Çubuğun kalınlığı $dx$. Bütün bilgiler $x$ cinsinden yazılır.
- Üst uç daima $y = \sqrt x$, alt uç daima $y = 0$ üzerinde. Yükseklik $\sqrt x - 0$.
- Tarama $x = 0$'dan $x = 4$'e.

$$A = \int_0^4 \sqrt x\,dx$$

**(b) Yatay tarama:**

- Çubuğun kalınlığı $dy$.
- $x = 4$ yerine yazılırsa $y = 2$. Yatay taramanın en büyük değeri $y = 2$, en küçük değeri $y = 0$.
- Sağ uç daima $x = 4$, sol uç daima $x = y^2$ üzerinde.

$$A = \int_0^2 (4 - y^2)\,dy$$

**(c) Hesap:** Hoca, iki modelin de aynı sonucu vereceğini söyledi ve (b)'yi kullandı.

$$A = \left[4y - \frac{y^3}{3}\right]_0^2 = 8 - \frac83 - 0 = \frac{24 - 8}{3} = \frac{16}{3}$$

(a) modeliyle de aynı sonuç çıkar: $\displaystyle\int_0^4\sqrt x\,dx = \left[\frac23 x^{3/2}\right]_0^4 = \frac23\cdot 8 = \frac{16}{3}$ (ara adım eklendi).

**Soru:** Bir öğrenci (b) şıkkının tekrar anlatılmasını istedi.

**Cevap:** Hoca bölgeyi yeniden çizdi ve yatay çubuğa odaklandı. Çubuğun bir kenarı $y$ eksenine paraleldir, bu yüzden kalınlık $dy$'dir. Çubuğun alanı $dA = (\text{uzunluk})\cdot dy$. Sağ uç $(x_2, y)$, sol uç $(x_1, y)$ olduğundan uzunluk uzaklık formülüyle $|x_2 - x_1| = x_2 - x_1$ olur; bu fark daima pozitiftir. İntegral değişkeni $y$ olduğundan $x_2 = 4$ (çünkü sağ uç $x = 4$ doğrusu üzerinde) ve $x_1 = y^2$ yazılır. Bölgeyi taramaya en alttan başlarsak en küçük yatay seviye $y = 0$, en büyük seviye ise $x = 4$ yerine yazılınca $y = 2$'dir. Sonuç: $\displaystyle\int_0^2 (4 - y^2)\,dy$.

### 5.2 Örnek 7: $y = -x^2 + 2x$ ve $y = 0$ ile Sınırlı Bölge

Hoca bunun kolay bir soru olduğunu söyledi.

1. Önce kökler bulunur: $-x^2 + 2x = 0 \Rightarrow x = 0$ ya da $x = 2$.
2. $x^2$'nin katsayısı negatif olduğu için parabol aşağı açılır.
3. Bölge parabol ile $y = 0$ arasındadır. En uygun tarama dikey taramadır.
4. Çubuğun kalınlığı $dx$. Üst uç $y_2 = -x^2 + 2x$, alt uç $y_1 = 0$. Yükseklik $y_2 - y_1 = -x^2 + 2x$.
5. Tarama $x = 0$'dan (dikey taramanın en küçük değeri) $x = 2$'ye (en büyük değeri).

$$A = \int_0^2 (-x^2 + 2x)\,dx = \left[-\frac{x^3}{3} + x^2\right]_0^2 = -\frac83 + 4 - 0 = \frac43$$

Hoca sınırları yerine koyup "cevap bu" dedi ama sayıyı söylemedi. Sonuç $\dfrac43$'tür (ara adım eklendi).

### 5.3 Örnek 8: $y = x^2$ ve $y = x + 2$ ile Sınırlı Bölge

Hoca herkesin bu soruyu çözmesini istedi. Bölgeyi uygun bir çubukla taramayı, tarama sırasında uç noktaların daima kimin üzerinde olduğunu belirlemeyi, sonra çubuğun alanı $dA$'yı integre etmeyi hatırlattı.

> **Hocanın vurgusu:** Bu tarama çubuğu mantığını öğrenmeniz lazım. Seneye çok değişkenli fonksiyonların integrallerini göreceksiniz, o zaman da bu mantığı kullanacaksınız.

**Çizim:** $y = x^2$ yukarı açılan bir paraboldür. $y = x + 2$ doğrusu $x = 0$'da $y = 2$, $y = 0$'da $x = -2$ noktasından geçer.

1. Kesişim noktaları: $x^2 = x + 2 \Rightarrow x^2 - x - 2 = 0 \Rightarrow (x - 2)(x + 1) = 0$. Yani $x = -1$ ya da $x = 2$.
2. En uygun çubuk dikey çubuktur. Dikey tarama sırasında üst uç daima $y = x + 2$, alt uç daima $y = x^2$ üzerindedir. Hoca bunun "çok güzel bir durum" olduğunu söyledi, çünkü integrali bölmeye gerek yoktur.
3. Çubuğun kalınlığı $dx$, yüksekliği $(x + 2) - x^2$.
4. Tarama $x = -1$'den $x = 2$'ye.

$$A = \int_{-1}^{2}(x + 2 - x^2)\,dx = \left[\frac{x^2}{2} + 2x - \frac{x^3}{3}\right]_{-1}^{2}$$

5. Hoca İkinci Temel Teorem ile sınırları yerine koydu: $x = 2$ için $2 + 4 - \dfrac83 = \dfrac{10}{3}$.
6. $x = -1$ için: $\dfrac12 - 2 + \dfrac13 = -\dfrac76$ (ara adım eklendi).
7. $$A = \frac{10}{3} - \left(-\frac76\right) = \frac{20}{6} + \frac{7}{6} = \frac{27}{6} = \frac92$$

> **Ders sonrası not:** Hoca derste sonucu net söyleyemedi. Önce "$\frac{10}{3}$ mü geliyor?" dedi; bu yalnız üst sınırdaki değerdir. Bir öğrenci "$\frac{13}{2}$" dedi, hoca da "$\frac{13}{2}$ ya da 6 olabilir" dedi. Üçü de yanlıştır. Alt sınırdaki değer ($-\frac76$) çıkarılınca doğru alan $\dfrac92$ olur.

### 5.4 Örnek 9: $y = x^2$, $y = x + 2$ ve $y = 0$ ile Sınırlı Bölge

Hoca "aynı eğriler, ama farklı bir soru" diyerek bu soruyu verdi.

**Soru:** $R$ bölgesi $y = x^2$, $y = x + 2$ ve $y = 0$ doğrusuyla sınırlıdır. $R$'nin alanını

- (a) dikey kesitlerle,
- (b) yatay kesitlerle

veren integrali yazın.

Hoca, iki yöntemden birini kullanmanın daha avantajlı olduğunu, önce hangisinin en iyi yöntem olduğunu belirlemek gerektiğini söyledi.

**Bölgenin belirlenmesi:** Üç sınır eğrisi vardır: $y = 0$ doğrusu, $y = x + 2$ doğrusu ve $y = x^2$ parabolü. Bölge $x$ ekseninin üstünde, doğrunun sağında ve parabolün sol kolunun solunda kalır. Doğru $x$ eksenini $x = -2$'de keser. Doğru ile parabol $x = -1$'de kesişir. Parabol $x$ eksenine $x = 0$'da değer.

**(a) Dikey tarama:**

- $x = -2$'den $x = -1$'e kadar üst uç daima $y = x + 2$, alt uç daima $y = 0$ üzerindedir.
- $x = -1$'den $x = 0$'a kadar üst uç daima $y = x^2$, alt uç daima $y = 0$ üzerindedir.
- Üst uç değiştiği için integral ikiye bölünür:

$$A = \int_{-2}^{-1}(x + 2 - 0)\,dx + \int_{-1}^{0}(x^2 - 0)\,dx$$

Hoca birinci parçanın bir üçgenin alanı olduğunu fark edeceğimizi, ama sınavlarda bunun integral olarak istendiğini hatırlattı.

Hoca (a)'nın sayısal değerini hesaplamadı. Sonuç: $\displaystyle\int_{-2}^{-1}(x+2)\,dx = \frac12$ ve $\displaystyle\int_{-1}^{0}x^2\,dx = \frac13$; toplam $\dfrac56$ (ara adım eklendi).

**(b) Yatay tarama:**

- Çubuğun kalınlığı $dy$. Tarama $y = 0$'dan, doğru ile parabolün kesiştiği $y = 1$ seviyesine kadardır.
- Sağ uç daima parabolün sol kolu üzerindedir. Bu kol $y$ cinsinden $x_2 = -\sqrt y$ diye yazılır.
- Sol uç daima doğru üzerindedir. $y = x + 2$ eşitliğinden $x_1 = y - 2$.
- Çubuğun uzunluğu: $x_2 - x_1 = -\sqrt y - (y - 2)$.

$$A = \int_0^1 \big[-\sqrt y - (y - 2)\big]\,dy = \left[-\frac{y^{3/2}}{3/2} - \frac{y^2}{2} + 2y\right]_0^1 = -\frac23 - \frac12 + 2 - 0 = \frac56$$

Hoca son değeri $-\dfrac23 - \dfrac12 + 2$ diye bıraktı; bu $\dfrac56$'dır. İki yöntem aynı sonucu verir.

> **Hocanın vurgusu:** Sonuç negatif geliyorsa bir yerde hata yapıyorsunuz demektir. Hangisinin kolay olduğu duruma göre değişir; bazen (a), bazen (b).

**Soru:** Bir öğrenci (b) şıkkını anlamadığını söyledi.

<!-- BELİRSİZ: 01:49:18'de öğrencinin sorusu bozuk aktarılıyor ("integral içinde nasıl ... almaya karar"); sorunun tam metni anlaşılmıyor. -->

**Cevap:** Hoca (b) şıkkını Türkçe olarak baştan, adım adım anlattı:

- Dikdörtgenin alanını ve düzlemde iki nokta arasındaki uzaklık formülünü biliyorsunuz. Gerisi grafik çizimi ve bunların uygulanmasıdır.
- Yatay çubuğu koyduk. Çubuğun iki ucunun $y$ değerleri aynıdır. Çubuk aşağıdan yukarıya hareket eder.
- Çubuğun kalınlığı $dx$ değil, $dy$'dir. Yani integral değişkeni $y$'dir. Bu, bütün bilgileri $y$ cinsinden yazacağımız anlamına gelir.
- Çubuğun uzunluğu $|x_2 - x_1|$'dir. Sağdakinden soldakini çıkarırsak pozitif bir değer elde ederiz, bu yüzden uzunluk $x_2 - x_1$ olur.
- $y = x^2$ eğrisinin iki kolu vardır: $x = \sqrt y$ ve $x = -\sqrt y$. Bu bölgede sağ uç sol kol üzerindedir, yani $x_2 = -\sqrt y$.
- $y = x + 2$'den $x$ yalnız bırakılırsa $x_1 = y - 2$.
- Uzunluk: $-\sqrt y - (y - 2)$. Parantez açmayı unutmayın.
- Yatay seviye en az $y = 0$, en çok $y = 1$. Sonuç: $\displaystyle\int_0^1(-\sqrt y - y + 2)\,dy$.

Hoca, her soruda aynı mantığı kullandığını, başka bir mantık olmadığını söyledi: Çubuğun kalınlığını belirleyin, çubuğun alanını kurun, bütün bilgileri kalınlık değişkeni cinsinden yazın, sonra integre edin. Gerisi grafik çizimine ve işlem yeteneğine bağlıdır. Hoca bunu gözünüzde büyütülecek bir mesele olmadığını, olayı elinden geldiğince basitleştirmeye çalıştığını ekledi.

### 5.5 Örnek 10: $y = 0$, $x = e$ ve $x = e^y$ ile Sınırlı Bölge

**Soru:** $R$ bölgesi $y = 0$ doğrusu, $x = e$ doğrusu ve $x = e^y$ eğrisiyle çevrilidir.

- (a) $R$'nin alanını veren integral modelini dikey kesitlerle yazın.
- (b) $R$'nin alanını veren integral modelini yatay kesitlerle yazın.

Hoca önemli olanın integral modelini kurabilmek olduğunu, sonucun sonradan hesaplanabileceğini söyledi. Bölge doğru çizilirse modellerin hemen elde edileceğini ekledi. Öğrencilerden biri sorunun zor olduğunu söyleyince hoca, $x = e^y$'nin tersinin grafiğinin daha önce anlatıldığını hatırlattı. Bir öğrenci de "sınırlar 1 ile $e$ olmalı, galiba $\ln x$ geliyor" diye doğru sonuca ulaştı.

**İki denk ifade:** $x = e^y$ fonksiyonu terslenebilirdir. Her iki tarafa doğal logaritma uygulanırsa $\ln x = y$ elde edilir. Hoca bunu "ancak ve ancak" (denklik) sembolüyle açıkladı: $x = e^y$, $\ln x = y$'yi doğurur; $\ln x = y$ da $x = e^y$'yi doğurur. İki ifade birbirini doğuruyorsa matematikte bunlara denk ifadeler denir.

$$x = e^y \iff y = \ln x$$

> **Hocanın vurgusu:** Bu eğriyi $y = \ln x$ ya da $x = e^y$ ile temsil edebiliriz. Çubuğun konumuna göre bunlardan birini kullanmak avantaj sağlar.

**Çizim:** Bölge $y = \ln x$ eğrisinin altında, $x$ ekseninin üstünde ve $x = e$ doğrusunun solundadır. Eğri $x$ eksenini $x = 1$'de keser. $x = e$'de $y = 1$'dir.

**(a) Dikey tarama:**

- Çubuğun kalınlığı $dx$. Bütün bilgiler $x$ cinsinden yazılır.
- Üst uç daima eğri üzerindedir: $y_2 = \ln x$. Alt uç daima $y_1 = 0$ üzerindedir.
- Yükseklik uzaklık formülüyle $|y_2 - y_1| = \ln x - 0$.
- Tarama $x = 1$'den $x = e$'ye.

$$A = \int_1^e \ln x\,dx$$

Hoca, integral modelini kurduktan sonra bir kontrol yapılabileceğini gösterdi: Sınırlar $x$, uzunluk $x$ cinsinden ve kalınlık $dx$; yani her bilgi $x$ cinsinden yazılmış. Burada yalnız dikdörtgenin alanını (taban uzunluğu çarpı yükseklik) uyguladığını söyledi.

**(b) Yatay tarama:**

- Çubuğun bir kenarı $y$ eksenine paraleldir, kalınlık $dy$. Bütün bilgiler $y$ cinsinden yazılır.
- Sağ uç daima $x_2 = e$ üzerindedir.
- Sol uç daima eğri üzerindedir; $y$ cinsinden $x_1 = e^y$.
- Uzunluk $x_2 - x_1 = e - e^y$.
- $x = e$ yerine yazılırsa $y = 1$. Tarama $y = 0$ yatay seviyesinden $y = 1$ seviyesine kadardır.

$$A = \int_0^1 (e - e^y)\,dy = \big[ey - e^y\big]_0^1 = (e - e) - (0 - 1) = 1$$

Bölgenin alanı 1 birim karedir. Hocaya göre bu alanı hesaplamak için (b) daha kolaydır.

(a) modeliyle de aynı sonuç çıkar: kısmi integrasyonla $\displaystyle\int_1^e\ln x\,dx = \big[x\ln x - x\big]_1^e = 0 - (-1) = 1$ (ara adım eklendi).

Bu örnekten sonra 5 dakikalık ara verildi.

## 6. Dönel Cisimlerin Hacmi: Disk Yöntemi

### 6.1 Bir Dikdörtgeni Döndürmek

Aradan sonra hoca dönel cisimlerin hacimlerini hesaplamaya geçti (evaluating volumes of revolution). "Revolution" kelimesinin burada "dönel cisim" anlamına geldiğini söyledi.

Hoca bir soruyla başladı. Kalınlığı $dx$, yüksekliği $y = f(x)$ olan dikdörtgen bir bölge alalım. Bu bölgeyi $x$ ekseni etrafında 360 derece döndürürsek ne elde ederiz? Öğrenciler "disk, silindir" diye cevap verdi.

Elde edilen disk ince bir silindirdir:

- Diskin yarıçapı: $r = f(x)$.
- Diskin yüksekliği (kalınlığı): $h = dx$.
- Silindirin hacmi $\pi r^2 h$ olduğundan diskin hacmi:

$$dV = \pi\,[f(x)]^2\,dx$$

Hoca normalde bir diskin hacminden söz edilmediğini, eskiden kullanılan müzik disklerini örnek vererek bu diskin aslında ince bir silindir olduğunu anlattı.

### 6.2 Disk Yöntemi Formülü

Şimdi $y = f(x)$'in altında ve $[a,b]$ aralığının üstündeki bölgeyi bu dikdörtgen çubuklarla taradığımızı düşünelim. Bölge $x$ ekseni etrafında döndürülürse bir dönel cisim elde edilir. Cisim, yeterince küçük disk parçalarından oluşur. Her parçanın hacmi $dV$'dir. Bütün parçalar integre edilirse cismin hacmi bulunur:

$$V = \int_a^b \pi\,[f(x)]^2\,dx$$

Bu, $y = f(x)$'in altında ve $[a,b]$'nin üstünde kalan bölgenin $x$ ekseni etrafında döndürülmesiyle oluşan cismin hacmidir. Bu formüle **disk yöntemi** (disk method) denir.

> **Hocanın vurgusu:** Disk yöntemini uygulayabilmek için bölgeyi tarayan çubuk döndürme eksenine **dik** olmalıdır. Aksi hâlde disk elde edilmez. Hikayenin başına dikkat edin: $dx$ kalınlıklı, $f(x)$ yükseklikli dikdörtgeni döndürünce disk elde ettik; orada çubuk döndürme eksenine dikti.

**Ön koşul (disk yöntemi):**

- Bölge, döndürme eksenine dik çubuklarla taranır.
- Çubuğun döndürme eksenine uzaklığı diskin yarıçapıdır.
- Çubuğun kalınlığı diskin yüksekliğidir ve integral değişkenini belirler.

### 6.3 Örnek 11: $y = e^x$, $x = -\ln 2$, $x = \ln 2$ ve $y = 0$ ile Sınırlı Bölge

**Soru:** $R$ bölgesi $y = e^x$, $x = -\ln 2$, $x = \ln 2$ ve $y = 0$ doğrusuyla sınırlıdır.

- (a) $R$'nin alanını hesaplayın.
- (b) $R$'nin $x$ ekseni etrafında döndürülmesiyle elde edilen cismin hacmini hesaplayın.

Hoca bunun dersin son sorusu olduğunu söyledi. Bir öğrenci üçüncü sınırın da $\ln 2$ olup olmadığını sordu, hoca doğruladı. Hoca önce $y = 0$'ı söylemeyi unuttu, sonra ekledi; bu olmadan bölge sınırlı olmazdı. Böylece dört sınır eğrisi oldu.

Hoca burada bir terim notu da verdi: Her doğru bir eğridir, ama her eğri doğru değildir. Matematikçiler sınırlara "eğri" (curve) der.

**(a) Alan (dikey tarama):**

- En uygun çubuk dikey çubuktur.
- Çubuğun yüksekliği $e^x - 0$, kalınlığı $dx$.
- Tarama $x = -\ln 2$'den $x = \ln 2$'ye.

$$A = \int_{-\ln 2}^{\ln 2} e^x\,dx = e^{\ln 2} - e^{-\ln 2} = 2 - \frac12 = \frac32$$

**Soru:** Bir öğrenci sonucun 4 olması gerekmediğini sordu.

**Cevap:** Hoca, "2 eksi eksi" gibi bir işaret hatasına dikkat çekti ve $e^{-\ln 2}$'nin ne demek olduğunu hatırlattı: $e^{-\ln 2} = e^{\ln\frac12} = \dfrac12$. Logaritmanın özelliklerine dikkat etmek gerekir.

**(b) Hacim (disk yöntemi):**

Hoca formül ezberlemeye gerek olmadığını, silindirin hacmini herkesin bildiğini söyledi. Öğrenciler bunu ilkokul 4. sınıfta öğrendiklerini söyledi. Hoca, bu soruyu aslında 4. sınıf bilgisiyle çözdüğünü, yalnız soyut düşünme yeteneğinin gerektiğini ekledi: Bir 4. sınıf öğrencisine "bu dikdörtgeni $x$ ekseni etrafında tam döndürürsem ne elde ederim?" diye sorsanız silindir diyecektir.

1. Dikey çubuk $x$ eksenine diktir, bu yüzden disk yöntemi uygulanabilir.
2. Diskin kalınlığı (yüksekliği) $h = dx$.
3. Diskin yarıçapı $r = e^x$.
4. Diskin hacmi: $dV = \pi r^2 h = \pi e^{2x}\,dx$.
5. Diskler $x = -\ln 2$ seviyesinden $x = \ln 2$ seviyesine kadar integre edilir:

$$V = \int_{-\ln 2}^{\ln 2}\pi e^{2x}\,dx = \frac{\pi}{2}\big[e^{2x}\big]_{-\ln 2}^{\ln 2} = \frac{\pi}{2}\left(e^{2\ln 2} - e^{-2\ln 2}\right)$$

6. $e^{2\ln 2} = e^{\ln 4} = 4$ ve $e^{-2\ln 2} = \dfrac14$.
7. $$V = \frac{\pi}{2}\left(4 - \frac14\right) = \frac{\pi}{2}\cdot\frac{15}{4} = \frac{15\pi}{8}$$

Hoca sonucu $\dfrac{\pi}{2}\left(e^{2\ln 2} - e^{-2\ln 2}\right)$ biçiminde bıraktı ve işlem hatası olmadığını kontrol etti. Sayısal değer $\dfrac{15\pi}{8}$'dir.

<!-- BELİRSİZ: 02:39:03'te bir öğrencinin "must be one" diye bir şeyin 1 olması gerektiğini söylediği anlaşılıyor; hangi ifadeyi kastettiği altyazıda net değil. Hoca hata olmadığını söyledi. -->

## Örnek Sorular

Bu derste video karesi kullanılmadı. Aşağıdaki sorular hocanın derste çözdüğü ya da sözlü olarak sorduğu sorulardır.

**1. (derste sözlü, 00:12:56)** $\displaystyle\int\frac{dx}{x\sqrt{x^2+a^2}}$ integralini hesaplayın. <!-- BELİRSİZ: kök içindeki ifade çözüm adımlarından çıkarıldı. -->

- Derste $x = a\tan t$ ile $\dfrac1a\displaystyle\int\csc t\,dt$'ye kadar gelindi; $x$ cinsinden sonuç ödev bırakıldı.

> **Çözüm (derste verilmedi):** $\displaystyle\int\csc t\,dt = -\ln|\csc t + \cot t| + C$. Üçgende $\tan t = \frac xa$, hipotenüs $\sqrt{x^2+a^2}$ olduğundan $\csc t = \frac{\sqrt{x^2+a^2}}{x}$, $\cot t = \frac ax$. Sonuç: $$\int\frac{dx}{x\sqrt{x^2+a^2}} = -\frac1a\ln\left|\frac{\sqrt{x^2+a^2} + a}{x}\right| + C$$ Bu sonucun türevi sympy ile kontrol edildi ve integrand elde edildi.

**2. (derste sözlü, 00:14:04)** $x^2 + a^2$ içeren, özellikle $\sqrt{x^2+a^2}$ içeren bir integralde hangi dönüşümü yaparız?

- Cevap (derste verildi): $x = a\tan t$. Bu dönüşüm problemi trigonometrik bir integrale çevirir.

**3. (derste sözlü, 00:20:22)** $\displaystyle\int\frac{dx}{\sqrt{4x^2+9}}$ için en iyi trigonometrik dönüşüm hangisidir? İntegrali hesaplayın.

- Derste verilen çözüm: $2x = 3\tan t$; sonuç $\dfrac12\ln|\sec t + \tan t| + C$. $x$ cinsinden yazmak ödev.

> **Çözüm (derste verilmedi):** Üçgende $\tan t = \frac{2x}{3}$, hipotenüs $\sqrt{4x^2+9}$; $\sec t = \frac{\sqrt{4x^2+9}}{3}$. $$\int\frac{dx}{\sqrt{4x^2+9}} = \frac12\ln\left|\frac{\sqrt{4x^2+9} + 2x}{3}\right| + C$$ Türev sympy ile kontrol edildi.

**4. (derste sözlü, 00:24:24)** $\displaystyle\int\frac{dx}{\sqrt{x^2+4x+8}}$ integralini hesaplayın.

- Derste verilen çözüm: $(x+2)^2 + 2^2$, $x + 2 = 2\tan t$; sonuç $\ln|\sec t + \tan t| + C$.

> **Çözüm (derste verilmedi):** $\sec t = \frac{\sqrt{x^2+4x+8}}{2}$, $\tan t = \frac{x+2}{2}$. $$\int\frac{dx}{\sqrt{x^2+4x+8}} = \ln\left|\frac{\sqrt{x^2+4x+8} + x + 2}{2}\right| + C$$ Türev sympy ile kontrol edildi.

**5. (derste sözlü, 00:38:44)** $x = 0$ ile $x = g(y)$ arasındaki bölgeyi taramak için dikey çubuk mu, yatay çubuk mu uygundur?

- Cevap (derste verildi): Yatay çubuk. Sağ uç $x = g(y)$, sol uç $x = 0$ üzerindedir; kalınlık $dy$.

**6. (derste sözlü, 01:17:08)** $y = \sqrt x$, $y = 0$, $x = 4$ ile sınırlı bölgenin alanını veren integrali dikey ve yatay kesitlerle yazın; alanı hesaplayın.

- Cevap (derste verildi): $\displaystyle\int_0^4\sqrt x\,dx = \int_0^2(4 - y^2)\,dy = \frac{16}{3}$.

**7. (derste sözlü, 01:28:35)** $y = -x^2 + 2x$ ve $y = 0$ ile sınırlı bölgenin alanını bulun.

- Cevap (derste verildi, sayı eklendi): $\displaystyle\int_0^2(-x^2+2x)\,dx = \frac43$.

**8. (derste sözlü, 01:31:57)** $y = x^2$ ve $y = x + 2$ ile sınırlı bölgenin alanı nedir?

- Derste model $\displaystyle\int_{-1}^{2}(x + 2 - x^2)\,dx$ olarak kuruldu, sonuç yanlış söylendi.

> **Çözüm (derste verilmedi):** $\left[\frac{x^2}{2} + 2x - \frac{x^3}{3}\right]_{-1}^{2} = \frac{10}{3} - \left(-\frac76\right) = \frac92$. sympy ile doğrulandı.

**9. (derste sözlü, 01:38:59)** $y = x^2$, $y = x + 2$ ve $y = 0$ ile sınırlı bölgenin alanını (a) dikey, (b) yatay kesitlerle veren integrali yazın.

- Cevap (derste verildi): (a) $\displaystyle\int_{-2}^{-1}(x+2)\,dx + \int_{-1}^{0}x^2\,dx$; (b) $\displaystyle\int_0^1\big[-\sqrt y - (y - 2)\big]\,dy$. İkisi de $\dfrac56$.

**10. (derste sözlü, 01:54:45)** $y = 0$, $x = e$ ve $x = e^y$ ile çevrili bölgenin alanını veren integral modelini (a) dikey, (b) yatay kesitlerle yazın.

- Cevap (derste verildi): (a) $\displaystyle\int_1^e\ln x\,dx$; (b) $\displaystyle\int_0^1(e - e^y)\,dy = 1$.

**11. (derste sözlü, 02:19:02)** Kalınlığı $dx$, yüksekliği $f(x)$ olan dikdörtgen bölgeyi $x$ ekseni etrafında 360 derece döndürürsek ne elde ederiz?

- Cevap (derste verildi): Bir disk (ince silindir). Hacmi $\pi[f(x)]^2\,dx$.

**12. (derste sözlü, 02:27:46)** $y = e^x$, $x = -\ln 2$, $x = \ln 2$, $y = 0$ ile sınırlı $R$ bölgesinin (a) alanını, (b) $x$ ekseni etrafında döndürülmesiyle oluşan cismin hacmini hesaplayın.

- Cevap (derste verildi): (a) $\dfrac32$; (b) $\dfrac{\pi}{2}\left(e^{2\ln 2} - e^{-2\ln 2}\right) = \dfrac{15\pi}{8}$.

## Dersin Toparlaması

Bu derste önce trigonometrik dönüşümlerin sonuncusu olan $x = a\tan t$ işlendi. Dönüşüm, $\tan^2 t + 1 = \sec^2 t$ özdeşliği sayesinde $x^2 + a^2$ ifadesini $a^2\sec^2 t$'ye çevirir. Diskriminantı negatif ikinci derece ifadeler tam kareye tamamlanarak $u^2 + a^2$ biçimine getirilir ve aynı dönüşüm $u = a\tan t$ olarak uygulanır. Sonuçlar dik üçgen yardımıyla $x$ cinsinden yazılır.

Dersin ikinci yarısında integralin uygulamalarına geçildi. Bütün alan formüllerinin arkasında tek bir mantık vardır: Bölgeyi uygun bir tarama çubuğuyla tarayın, çubuğun kalınlığı ($dx$ ya da $dy$) integral değişkenini belirler, çubuğun uzunluğu uzaklık formülüyle (üst eksi alt ya da sağ eksi sol) bulunur, çubuğun alanı en düşük seviyeden en yüksek seviyeye integre edilir. Aynı mantık disk yöntemine de taşındı: Döndürme eksenine dik bir çubuk döndürülünce ince bir silindir oluşur, hacmi $\pi r^2 h$'den gelir ve $V = \displaystyle\int_a^b\pi[f(x)]^2\,dx$ elde edilir. Hoca bu tarama mantığının ileride çok değişkenli integrallerde de kullanılacağını söyledi. Bir sonraki derste kabuk yöntemi (shell method), yay uzunluğu ve yüzey alanı anlatılacak, vakit kalırsa genelleştirilmiş (improper) integrallere giriş yapılacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
