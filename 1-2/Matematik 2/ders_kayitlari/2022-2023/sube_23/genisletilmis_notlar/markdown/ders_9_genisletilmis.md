# Ders 9 Genişletilmiş Notu: Uzayda Doğru ve Düzlem, Vektör Değerli Fonksiyonlar ve Çok Değişkenli Fonksiyonlara Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Vektörler Tekrarı
- 2. Üç Nokta, Açı ve İz Düşüm Örneği
- 3. Uzayda Doğru ve Doğru Parçası
- 4. Bir Noktanın Uzaydaki Bir Doğruya Uzaklığı
- 5. Uzayda Düzlem
- 6. Düzlemlerin ve Doğruların Birbirine Göre Konumu
- 7. Vektör Değerli Fonksiyonlar
- 8. Çıkmış Sınav Soruları: Doğru ve Düzlem
- 9. Çok Değişkenli Fonksiyonlara Giriş
- 10. Tanım Bölgesi Örnekleri
- 11. Temel Yüzeyler
- Örnek Sorular
- Dersin Toparlaması

## 1. Vektörler Tekrarı

Hoca derse, bir önceki derste görülen vektör konularını kısaca hatırlatarak başladı. Amaç, uzayda doğru ve düzlem konusuna geçmeden önce gereken araçları tazelemekti. Hoca bu tekrarın ardından aynı gün çok değişkenli fonksiyonlara giriş yapılacağını söyledi.

### 1.1 Skaler Çarpım

İki vektörün skaler çarpımı (dot product), vektörlerin boyları ile aralarındaki açının kosinüsünün çarpımıdır:

$$\vec u\cdot\vec v=|\vec u|\,|\vec v|\cos\theta.$$

İki vektör birbirine dikse aradaki açı $90^\circ$'dir ve $\cos 90^\circ=0$ olduğundan skaler çarpım sıfır olur. Tersi de doğrudur: skaler çarpım sıfırsa vektörler diktir. Hoca skaler çarpımın değişme özelliğini, toplama üzerine dağılma özelliğini ve bir sayıyla çarpım özelliğini de hatırlattı. Bunların notlarda zaten bulunduğunu söyledi.

### 1.2 Dik İz Düşüm

$\vec u$ vektörünün $\vec v$ vektörü üzerine dik iz düşümü (projection), şekildeki dik üçgenden anlaşılır. $\vec u$'nun boyu ile $\cos\theta$'nın çarpımı, iz düşümün boyunu verir. Yön ise $\vec v$'nin birim vektörüdür:

$$\operatorname{proj}_{\vec v}\vec u=\left(|\vec u|\cos\theta\right)\frac{\vec v}{|\vec v|}=\frac{\vec u\cdot\vec v}{|\vec v|^2}\,\vec v.$$

Hoca bunun geçen derste ayrıntılı gösterildiğini söyleyip tekrar etmedi.

### 1.3 Vektörel Çarpım

$\vec u$ ve $\vec v$ aynı düzlemde iki vektör olsun. Bunların vektörel çarpımı (cross product), bu iki vektörün bulunduğu düzleme dik bir vektör verir. Hoca bu vektöre $\vec\omega$ dedi. Hesap determinantla yapılır:

$$\vec\omega=\vec u\times\vec v=\begin{vmatrix}\vec i&\vec j&\vec k\\u_1&u_2&u_3\\v_1&v_2&v_3\end{vmatrix}=a\vec i+b\vec j+c\vec k=\langle a,b,c\rangle.$$

Vektörel çarpımın boyu $|\vec u\times\vec v|=|\vec u||\vec v|\sin\theta$'dır. Hoca, skaler çarpımda kosinüs, vektörel çarpımda sinüs geldiğini vurguladı. Bu boy, $\vec u$ ve $\vec v$'nin oluşturduğu paralelkenarın alanıdır. Vektörel çarpımın özellikleri ve karma çarpım (determinant formülü) da geçen derste verilmişti.

## 2. Üç Nokta, Açı ve İz Düşüm Örneği

Hoca, sınavlarda sık gelen bir soru tipini anlattı. Üç nokta $P$, $Q$, $R$ verilir. Bu noktalardan vektörler kurulur ve şunlar sorulabilir: vektörün uzunluğu, birim vektörü, iki vektör arasındaki açı, iz düşüm, üçgenin alanı ya da $PQR$ düzlemine dik bir vektör.

Vektörler noktaların farkıyla bulunur. Örneğin $R$'den $P$ çıkarılırsa $\overrightarrow{PR}$, $Q$'dan $P$ çıkarılırsa $\overrightarrow{PQ}$ elde edilir. Hoca, bunlar nokta olduğu için konum vektörü gösterimi yazmaya gerek olmadığını belirtti.

İki vektör arasındaki açı skaler çarpımla bulunur:

$$\overrightarrow{PQ}\cdot\overrightarrow{PR}=|\overrightarrow{PQ}|\,|\overrightarrow{PR}|\cos\theta.$$

**Örnek 1 (açı, birim vektör, iz düşüm, dik vektör):** Hoca tahtada önce $\overrightarrow{PQ}$ ve $\overrightarrow{PR}$ adlarını kullandı. Slayttaki çözümde ise açı $\overrightarrow{PQ}$ ile $\overrightarrow{QR}$ arasında alınmıştı. Bileşenler şöyledir:

$$\overrightarrow{PQ}=\langle-2,-2,1\rangle,\qquad \overrightarrow{QR}=\langle 6,-1,-1\rangle.$$

<!-- BELİRSİZ: P, Q, R noktalarının koordinatları altyazıda okunmuyor; yalnız vektör bileşenleri geçiyor. -->

- **Uzunluklar:** $|\overrightarrow{PQ}|=\sqrt{(-2)^2+(-2)^2+1^2}=\sqrt9=3$. $|\overrightarrow{QR}|=\sqrt{36+1+1}=\sqrt{38}$.
- **Birim vektör:** $\overrightarrow{PQ}$'nun boyu 3'tür, 1'den farklıdır, yani birim vektör değildir. Bir vektör kendi normuna bölünürse birim vektör elde edilir:
  $$\vec u=\frac{\overrightarrow{PQ}}{|\overrightarrow{PQ}|}=\left\langle-\frac23,-\frac23,\frac13\right\rangle.$$
  Kontrol: $\sqrt{\frac49+\frac49+\frac19}=1$. Hoca bunu öğrencilerin kendilerinin yapmasını istedi.
- **Skaler çarpım:** birinci ile birinci, ikinci ile ikinci, üçüncü ile üçüncü bileşen çarpılıp toplanır: $(-2)(6)+(-2)(-1)+(1)(-1)=-12+2-1=-11$.
- **Açı:**
  $$\cos\theta=\frac{-11}{3\sqrt{38}},\qquad \theta=\arccos\left(\frac{-11}{3\sqrt{38}}\right)\approx126{,}5^\circ.$$
  (Derece değeri ara adım olarak eklendi.)
- **İz düşüm:** $\overrightarrow{PQ}$'nun $\overrightarrow{QR}$ üzerine dik iz düşümü:
  $$\operatorname{proj}_{\overrightarrow{QR}}\overrightarrow{PQ}=\frac{-11}{38}\langle6,-1,-1\rangle=-\frac{66}{38}\vec i+\frac{11}{38}\vec j+\frac{11}{38}\vec k.$$
  Hoca, şıklarda bu ifadenin bu şekilde ya da sadeleşmiş halde ($-\frac{66}{38}=-\frac{33}{19}$) verilebileceğini söyledi.
- **İki vektöre dik vektör:** $\overrightarrow{PQ}\times\overrightarrow{QR}$ determinantla bulunur. Hoca sonucu sesli söylemedi. Hesaplanınca (ara adım eklendi):
  $$\overrightarrow{PQ}\times\overrightarrow{QR}=\begin{vmatrix}\vec i&\vec j&\vec k\\-2&-2&1\\6&-1&-1\end{vmatrix}=\langle3,4,14\rangle.$$

Hoca, soru "aşağıdakilerden hangisi yanlıştır" diye sorulursa şıkların tek tek kontrol edilmesi gerektiğini söyledi.

> **Ders sonrası not:** Hoca tahtada önce $|\overrightarrow{PQ}|$'yu "$\sqrt5$" diye yazdı ve skaler çarpımı $-9$ buldu ($\cos\theta=\frac{-9}{\sqrt5\sqrt{38}}$). Doğrusu $|\overrightarrow{PQ}|=\sqrt{4+4+1}=3$ ve skaler çarpım $-12+2-1=-11$'dir. Hoca hemen ardından slayttaki doğru değerleri ($3$ ve $-11$) gösterdi.

## 3. Uzayda Doğru ve Doğru Parçası

Hoca, doğrular ve düzlemlerden sınavda mutlaka bir soru geldiğini söyledi.

> **Hocanın vurgusu:** Doğrular ve düzlemlerden mutlaka bir soru geliyor. Bunlara dikkat etmek lazım, bu konudan kaçınmamak lazım.

### 3.1 Vektör Denklemi

$P_0(x_0,y_0,z_0)$ doğru üzerinde sabit bir nokta, $P(x,y,z)$ doğru üzerinde herhangi bir nokta olsun. Konum vektörleri $\vec r=x\vec i+y\vec j+z\vec k$ ve $\vec r_0=x_0\vec i+y_0\vec j+z_0\vec k$'dır. Doğruya paralel vektör $\vec v=\langle a,b,c\rangle$ olsun.

$\vec r-\vec r_0$ vektörü doğru üzerindedir ve $\vec v$'ye paraleldir. Bu yüzden $\vec v$'nin bir katıdır:

$$\vec r-\vec r_0=t\,\vec v,\qquad t\in\mathbb R.$$

Bu, $P_0$'dan geçen ve $\vec v$'ye paralel doğrunun **vektör denklemidir**.

### 3.2 Parametrik ve Simetrik Denklem

Vektör denklemi bileşenlerle yazılırsa $\langle x,y,z\rangle-\langle x_0,y_0,z_0\rangle=t\langle a,b,c\rangle$ olur. Her bileşen ayrı yazılınca **standart parametrik denklem** elde edilir:

$$x=x_0+at,\qquad y=y_0+bt,\qquad z=z_0+ct,\qquad -\infty<t<\infty.$$

Her denklemden $t$ çekilirse simetrik denklem çıkar:

$$\frac{x-x_0}{a}=\frac{y-y_0}{b}=\frac{z-z_0}{c}=t.$$

$\vec v$'ye doğrunun **yön vektörü** denir. $t$ bir parametredir ve $-\infty$ ile $+\infty$ arasında değer alır. İki doğru paralelse yön vektörleri de paraleldir.

**Doğru denklemi için gerekenler (kutu):**

- Doğru üzerinde bir nokta.
- Doğruya paralel bir vektör (yön vektörü).
- İkisi de gereklidir. Biri eksikse doğru yazılamaz.

**Örnek 2:** $(-2,0,4)$ noktasından geçen ve $\vec v=\langle2,4,-2\rangle$ vektörüne paralel doğrunun parametrik denklemi.

- Verilen: $P_0=(-2,0,4)$, $\vec v=\langle2,4,-2\rangle$.
- $\langle x,y,z\rangle-\langle-2,0,4\rangle=t\langle2,4,-2\rangle$.
- Sonuç: $x=-2+2t$, $y=4t$, $z=4-2t$.

**Örnek 3 (iki noktadan geçen doğru):** $P(-3,2,-3)$ ve $Q(1,-1,4)$ noktalarından geçen doğrunun parametrik denklemi.

İki nokta verildiğinde, yön vektörü bu iki noktayı birleştiren vektördür. Nokta olarak ikisinden biri alınabilir. Hoca $P$'yi aldı.

- $\overrightarrow{PQ}=Q-P=\langle1-(-3),\,-1-2,\,4-(-3)\rangle=\langle4,-3,7\rangle$.
- $\langle x,y,z\rangle-\langle-3,2,-3\rangle=t\langle4,-3,7\rangle$.
- Sonuç: $x=-3+4t$, $y=2-3t$, $z=-3+7t$.

> **Hocanın vurgusu:** Taraf değiştirirken işaretlere dikkat edin. Eksiyi karşıya artı olarak geçirmeyi unutursanız yanlış şıkka gidersiniz. Ne kadar çok soru çözer, ne kadar çok uğraşırsanız hata yapma olasılığı o kadar azalır.

### 3.3 Doğru Parçasını Parametrize Etmek

İki noktayı birleştiren doğru parçası da aynı denklemle yazılır, yalnız $t$'nin aralığı sınırlanır. Örnek 3'teki $P$ ve $Q$ için:

$$x=-3+4t,\qquad y=2-3t,\qquad z=-3+7t,\qquad 0\le t\le1.$$

$t=0$ iken $P$'de, $t=1$ iken $Q$'dayız. Altyazıda $t$ aralığı sesli söylenmiyor, ancak doğru parçası için $0\le t\le1$ alındığı yazılı denklemden anlaşılıyor. <!-- BELİRSİZ: t aralığı altyazıda sesli okunmuyor. -->

## 4. Bir Noktanın Uzaydaki Bir Doğruya Uzaklığı

Bir $S$ noktasının, $P$'den geçen ve $\vec v$'ye paralel doğruya uzaklığı isteniyor. Bu, $S$'den doğruya inilen dikmenin boyudur. Hoca buna önce $h$, sonra $d$ dedi.

$\overrightarrow{PS}$ ile $\vec v$ bir paralelkenar oluşturur. Bu paralelkenarın alanı $|\overrightarrow{PS}\times\vec v|$'dir. Alan, taban ($|\vec v|$) çarpı yüksekliktir. Yükseklik de aranan uzaklıktır. Buradan:

$$d=\frac{|\overrightarrow{PS}\times\vec v|}{|\vec v|}.$$

**Örnek 4:** Doğru $P(1,3,0)$ noktasından geçiyor ve yön vektörü $\vec v=\langle1,-1,2\rangle$. Derste $\overrightarrow{PS}=\langle0,-2,5\rangle$ olarak yazıldı.

Hoca $P$ ve $\vec v$'nin parametrik denklemden nasıl okunduğunu gösterdi: sabit terimler $P_0$'ı, $t$'nin katsayıları $\vec v$'nin bileşenlerini verir.

<!-- BELİRSİZ: S noktası ve doğrunun yazılı denklemi altyazıda okunmuyor. PS = <0,-2,5> ve P(1,3,0) ise S = (1,1,5) olur. -->

- $\overrightarrow{PS}\times\vec v=\begin{vmatrix}\vec i&\vec j&\vec k\\0&-2&5\\1&-1&2\end{vmatrix}=\langle1,5,2\rangle$ (ara adım eklendi).
- $|\overrightarrow{PS}\times\vec v|=\sqrt{1+25+4}=\sqrt{30}$, $|\vec v|=\sqrt{1+1+4}=\sqrt6$.
- $d=\dfrac{\sqrt{30}}{\sqrt6}=\sqrt5$.

Hoca sonucu sesli söylemedi. Yukarıdaki hesap derste kurulan formülle yapılmıştır.

## 5. Uzayda Düzlem

### 5.1 Düzlem Denklemi Nedir?

Hoca öğrencilere $ax+by+c=0$ ile $ax+by+cz+d=0$ denklemlerinden hangisinin düzlem denklemi olduğunu sordu. Cevabı kendisi verdi: $ax+by+c=0$ bir doğru denklemidir, $ax+by+cz+d=0$ ise bir düzlem denklemidir.

> **Ders sonrası not:** $ax+by+c=0$, $xy$-düzleminde (iki boyutta) bir doğrudur. Hoca büyük olasılıkla bunu kastetti. Üç boyutlu uzayda ise $ax+by+c=0$ denklemi, $z$ eksenine paralel bir düzlemdir. Uzayda bir doğru tek bir doğrusal denklemle değil, parametrik denklemle ya da iki düzlemin kesişimiyle verilir.

### 5.2 Bir Nokta ve Normal ile Düzlem

Düzlem üzerinde bir nokta $P_0(x_0,y_0,z_0)$ ve düzleme dik bir vektör $\vec n=\langle a,b,c\rangle$ biliniyorsa düzlem yazılabilir. $\vec n$'ye düzlemin **normal vektörü** denir.

$P(x,y,z)$ düzlem üzerinde gezen herhangi bir nokta olsun. $\overrightarrow{P_0P}$ düzlemin içindedir, bu yüzden $\vec n$'ye diktir. Dik iki vektörün skaler çarpımı sıfırdır:

$$\overrightarrow{P_0P}\cdot\vec n=0\;\Longrightarrow\;\langle x-x_0,\,y-y_0,\,z-z_0\rangle\cdot\langle a,b,c\rangle=0,$$

$$a(x-x_0)+b(y-y_0)+c(z-z_0)=0.$$

Açılırsa $ax+by+cz+d=0$ biçimi çıkar. Burada $d$, sabit sayıların toplamıdır.

**Düzlem denklemi için gerekenler (kutu):**

- Düzlem üzerinde bir nokta.
- Düzleme dik bir vektör (normal).

Derste bir örnekte normal $\vec n=\langle5,2,-1\rangle$ alındı ve bilinen noktanın koordinatları $x-x_0$, $y-y_0$, $z-z_0$ içine yerleştirildi.

<!-- BELİRSİZ: Bu örnekteki noktanın koordinatları altyazıda okunmuyor ("x eksi 3" diye geçiyor). Son denklem sesli söylenmedi. -->

### 5.3 Bir Doğruya Dik Düzlem

Bir noktadan geçen ve bir $L$ doğrusuna dik düzlem isteniyorsa, doğrunun yön vektörü düzlemin normali olur. Çünkü doğru düzleme dikse, yön vektörü de düzleme diktir.

Derste bu tipte bir örnekte nokta $(2,1,3)$ olarak okundu. Yön vektörü doğrunun parametrik denkleminde $t$'nin katsayılarından alındı. Bir bileşende $t$ olmadığı için o bileşen $0$ oldu.

<!-- BELİRSİZ: Bu örnekteki doğrunun denklemi ve yön vektörünün tam bileşenleri altyazıda anlaşılmıyor ("katsayısı eksi 6", "6, 2" gibi parçalar geçiyor). Sonuç sesli okunmadı. -->

### 5.4 Üç Noktadan Geçen Düzlem

Üç nokta $A$, $B$, $C$ verilirse:

- Önce $\overrightarrow{AB}$ ve $\overrightarrow{AC}$ vektörleri yazılır.
- Bunların vektörel çarpımı $\overrightarrow{AB}\times\overrightarrow{AC}$, düzleme dik bir vektördür, yani normaldir.
- Noktalardan biri (örneğin $A$) ve bu normal ile 5.2'deki formül uygulanır: $\overrightarrow{AP}\cdot\vec n=0$.

Derste çözülen örnekte normal $\langle3,2,6\rangle$ bulundu.

<!-- BELİRSİZ: Bu örnekteki üç noktanın koordinatları ve son düzlem denklemi altyazıda okunmuyor. -->

Hoca bu noktada ilk arayı verdi.

## 6. Düzlemlerin ve Doğruların Birbirine Göre Konumu

Aradan sonra hoca, düzlemlerle ilgili bütün soruların normaller üzerinden çözüldüğünü anlattı.

### 6.1 İki Düzlem

$D_1$ düzleminin normali $\vec n_1$, $D_2$ düzleminin normali $\vec n_2$ olsun.

**Düzlem–düzlem ilişkileri (kutu):**

- $\vec n_1\parallel\vec n_2$ ise düzlemler paraleldir. Tersi de doğrudur: düzlemler paralelse normaller de paraleldir.
- $\vec n_1\perp\vec n_2$, yani $\vec n_1\cdot\vec n_2=0$ ise düzlemler diktir.
- İki düzlem arasındaki açı, normalleri arasındaki açıdır: $\cos\theta=\dfrac{\vec n_1\cdot\vec n_2}{|\vec n_1||\vec n_2|}$.

> **Hocanın vurgusu:** Düzlemlerle ilgili soruda düzlemin kendisiyle işimiz yok. Hemen düzlemin normalini çıkarıyoruz. Paralellik, diklik, açı ve kesişim hep normallerden bulunur.

### 6.2 Doğru ile Düzlem

Düzlemin normali $\vec n$, doğrunun yön vektörü $\vec v$ olsun.

**Doğru–düzlem ilişkileri (kutu):**

- $\vec v\parallel\vec n$ ise doğru düzleme diktir.
- $\vec v\perp\vec n$, yani $\vec v\cdot\vec n=0$ ise doğru düzleme paraleldir.

**Örnek 5:** Bir düzlem ve parametrik bir doğru verilmiş. Doğrunun düzleme paralel olup olmadığı soruluyor.

- Düzlemin normali, $x$, $y$, $z$'nin katsayılarından okunur: $\vec n=\langle1,-2,5\rangle$.
- Doğru: $x=2-t$, $y=-1+2t$, $z=\ldots+t$. Yön vektörü $t$'nin katsayılarıdır: $\vec v=\langle-1,2,1\rangle$.
- $\vec n\cdot\vec v=(1)(-1)+(-2)(2)+(5)(1)=-1-4+5=0$.
- Normal yön vektörüne diktir. Bu yüzden doğru düzleme **paraleldir**.

<!-- BELİRSİZ: Düzlemin sabit terimi ve doğrunun z bileşenindeki sabit altyazıda okunmuyor. -->

### 6.3 Kesişimler

- İki doğru kesişirse bir **nokta** oluşur.
- Bir doğru bir düzlemi keserse yine bir **nokta** oluşur.
- İki düzlem kesişirse aralarında bir **doğru** oluşur. Buna ara kesit doğrusu denir.

### 6.4 Ara Kesit Doğrusu

İki düzlemin ara kesit doğrusu, iki düzlemin içindedir. Bu yüzden iki normale de diktir. İki vektöre birden dik vektör vektörel çarpımla bulunduğu için ara kesit doğrusunun yön vektörü:

$$\vec v=\vec n_1\times\vec n_2.$$

Doğruyu yazmak için bir de nokta gerekir. Bunun için değişkenlerden birine kolay bir değer (çoğu zaman $0$) verilir. Kalan iki bilinmeyen, iki düzlem denkleminden çözülür.

**Örnek 6:** Birinci düzlemin normali $\vec n_1=\langle3,-2,1\rangle$. İkinci düzlem slaytta verildi. İki düzlemin ara kesit doğrusunun parametrik denklemi soruluyor.

- $\vec v=\vec n_1\times\vec n_2=\langle-5,-8,-1\rangle$ bulundu.
- Değişkenlerden birine değer verilip iki denklem çözüldü. Doğru üzerinde $(1,2,3)$ noktası bulundu.
- Sonuç: $x=1-5t$, $y=2-8t$, $z=3-t$.
- Kontrol: $\vec n_1\cdot\vec v=-15+16-1=0$. Yön vektörü birinci normale gerçekten diktir (kontrol eklendi).

<!-- BELİRSİZ: İkinci düzlemin denklemi altyazıda okunmuyor; bu yüzden vektörel çarpım tam doğrulanamadı. -->

**Örnek 7:** Benzer bir soruda düzlemler altyazıda "$x-y\ldots3$" ve "$x+y+z\ldots$" diye geçiyor. Hoca $z=0$ alarak doğru üzerinde bir nokta buldu. $x$ bileşeni $\frac32$ çıktı ve yön vektörünün $x$ bileşeni $-1$ oldu: $x=\frac32-t$. $y$ ve $z$ bileşenleri aynı şekilde yazıldı.

<!-- BELİRSİZ: Düzlem denklemleri tam okunmuyor. Düzlemler x − y = 3 ve x + y + z = 0 ise n1 × n2 = <−1,−1,2> ve z = 0 için x = 3/2, y = −3/2 çıkar; bu, altyazıdaki "3 bölü 2" ve "eksi bir çarpı t" ile büyük olasılıkla uyumlu. -->

Hoca, $x$'e değer verilmezse çözümün bir parametreye bağlı kalacağını, bu yüzden değişkenlerden birine değer verildiğini söyledi.

### 6.5 Bir Noktanın Düzleme Uzaklığı

Hoca, bir noktanın düzleme uzaklığının daha önce yapıldığını hatırlattı. Bu uzaklık, $\overrightarrow{PS}$ ile normalin skaler çarpımından, yani vektörlerin uzunlukları ve aralarındaki açının kosinüsü arasındaki bağıntıdan çekilerek bulunuyordu.

> **Ek bilgi (derste anlatılmadı):** Bu bağıntıdan çıkan formül şudur: $P$ düzlem üzerinde bir nokta, $\vec n$ normal ise $S$ noktasının düzleme uzaklığı $d=\dfrac{|\overrightarrow{PS}\cdot\vec n|}{|\vec n|}$'dir. Bu, $\overrightarrow{PS}$'nin normal üzerine iz düşümünün boyudur.

## 7. Vektör Değerli Fonksiyonlar

### 7.1 Tanım

Vektör değerli fonksiyon (vector-valued function), bir $t$ parametresini alıp üç boyutlu uzaya götürür:

$$\vec r:D\subseteq\mathbb R\to\mathbb R^3,\qquad \vec r(t)=f(t)\,\vec i+g(t)\,\vec j+h(t)\,\vec k.$$

Tanım kümesi $D$, gerçel sayıların bir alt kümesidir. Fonksiyon her $t\in D$'ye bir vektör atar. $t$ arttıkça vektörün ucu uzayda bir yol boyunca hareket eder. Bu yol üç boyutlu uzayda bir eğridir.

### 7.2 Türev

Vektör değerli fonksiyonun türevi bileşen bileşen alınır:

$$\vec r\,'(t)=\frac{d\vec r}{dt}=f'(t)\,\vec i+g'(t)\,\vec j+h'(t)\,\vec k.$$

Hoca, üç bileşenin de türevli olması gerektiğini vurguladı. Birinin türevi yoksa $\vec r$'nin de türevi yoktur.

**Düzgün eğri (kutu):**

- $\vec r\,'(t)$ sürekli ise ve
- hiçbir $t$ için $\vec 0$ olmuyorsa (yani $f'$, $g'$, $h'$ aynı anda sıfır olmuyorsa),
- $\vec r$'nin çizdiği eğri **düzgündür** (smooth).

### 7.3 Hız, Sürat, İvme ve Birim Teğet Vektör

$\vec r(t)$, uzayda düzgün bir eğri boyunca hareket eden bir parçacığın konum vektörü olsun.

**Hareket büyüklükleri (kutu):**

- **Hız vektörü:** $\vec v(t)=\vec r\,'(t)=\dfrac{d\vec r}{dt}$.
- **Sürat:** hız vektörünün boyu, $|\vec v(t)|$. $\vec r\,'(t)=a\vec i+b\vec j+c\vec k$ ise $|\vec v|=\sqrt{a^2+b^2+c^2}$.
- **İvme:** hızın zamana göre türevi, $\vec a(t)=\vec v\,'(t)=\vec r\,''(t)$.
- **Birim teğet vektör:** hız vektörünün boyuna oranı, $\vec T=\dfrac{\vec v}{|\vec v|}=\dfrac{\vec r\,'(t)}{|\vec r\,'(t)|}$. $t$ anındaki hareketin yönünü gösterir.

> **Hocanın vurgusu:** Birim teğet vektör sınavlarda çıkan bir soru tipidir.

**Örnek 8 (çıkmış soru, birim teğet vektör):** $\vec r(t)=3\cos t\,\vec i+3\sin t\,\vec j+t^2\,\vec k$ için birim teğet vektörü bulunuz.

- Türev: $(3\cos t)'=-3\sin t$, $(3\sin t)'=3\cos t$, $(t^2)'=2t$. Yani $\vec r\,'(t)=-3\sin t\,\vec i+3\cos t\,\vec j+2t\,\vec k$.
- Boy: $|\vec r\,'(t)|=\sqrt{9\sin^2t+9\cos^2t+4t^2}=\sqrt{9(\sin^2t+\cos^2t)+4t^2}=\sqrt{9+4t^2}$.
- Sonuç:
  $$\vec T=\frac{-3\sin t\,\vec i+3\cos t\,\vec j+2t\,\vec k}{\sqrt{9+4t^2}}.$$

Örneğin ardından hoca, öğrencileri soru sormaya teşvik etti. Sorularla pekişmeyen bilginin kullanıma hazır olmadığını söyledi.

### 7.4 Limit ve Süreklilik

Vektör değerli fonksiyonun limiti de bileşen bileşen alınır:

$$\lim_{t\to t_0}\vec r(t)=\left(\lim_{t\to t_0}f(t)\right)\vec i+\left(\lim_{t\to t_0}g(t)\right)\vec j+\left(\lim_{t\to t_0}h(t)\right)\vec k.$$

**Limit ve süreklilik (kutu):**

- Bileşenlerden birinin limiti yoksa $\vec r$'nin limiti de yoktur.
- $\vec r$, bileşenlerinin hepsi $t_0$'da sürekliyse $t_0$'da süreklidir.
- Bir bileşen (örneğin $h$) sürekli değilse $\vec r$ de sürekli değildir.
- Vektör değerli fonksiyonun limiti de bir vektördür.

Derste $t\to\pi/4$ için bir örnek yapıldı. $t=\pi/4$ değeri bileşenlere tek tek konarak limit bulundu.

<!-- BELİRSİZ: t → π/4 örneğindeki fonksiyon ve sonuç altyazıda okunmuyor. -->

**Örnek 9 (sürat ve ivme):** Konum vektörü verilen bir cismin $t=1$ anındaki sürati ve ivmesi isteniyor.

- Konum vektörünün türevi alınıp $t=1$ konur: hız bulunur.
- Hızın bir daha türevi alınıp $t=1$ konur: ivme bulunur.
- Sürat, hız vektörünün boyudur. Hesapta $\sin^2 1+\cos^2 1=1$ kullanıldı ve sürat $5$ bulundu.

<!-- BELİRSİZ: Konum vektörünün ifadesi ve ivmenin sonucu altyazıda okunmuyor; bu yüzden sürat = 5 sonucu doğrulanamadı. -->

### 7.5 Türev Kuralları

$\vec u$ ve $\vec v$ türevli vektör fonksiyonları, $\lambda$ bir sabit olsun.

**Türev kuralları (kutu):**

- Toplam: $(\vec u+\vec v)'=\vec u\,'+\vec v\,'$.
- Sabitle çarpım: $(\lambda\vec u)'=\lambda\vec u\,'$.
- Skaler çarpım: $(\vec u\cdot\vec v)'=\vec u\,'\cdot\vec v+\vec u\cdot\vec v\,'$.
- Vektörel çarpım: $(\vec u\times\vec v)'=\vec u\,'\times\vec v+\vec u\times\vec v\,'$.

Hoca, çarpım kurallarının iki fonksiyonun çarpımının türevi gibi düşünülebileceğini söyledi: skaler çarpımda skaler çarpım, vektörel çarpımda vektörel çarpım kullanılır.

### 7.6 Yay Uzunluğu

$\vec r(t)=x(t)\vec i+y(t)\vec j+z(t)\vec k$ eğrisinin $a\le t\le b$ aralığındaki yay uzunluğu:

$$s=\int_a^b\sqrt{\left(\frac{dx}{dt}\right)^2+\left(\frac{dy}{dt}\right)^2+\left(\frac{dz}{dt}\right)^2}\;dt=\int_a^b|\vec r\,'(t)|\,dt.$$

Hoca bunun için "çok güzel bir örnek" dediği bir soru çözdü. Türev alındı, kök içine yazıldı, $0$'dan $\pi$'ye integral alındı ve sonuç şıklarda bir sayı çarpı $\pi$ olarak görüldü.

<!-- BELİRSİZ: Yay uzunluğu örneğindeki fonksiyon ve sonuç altyazıda okunmuyor ("kök ... pi" gibi geçiyor). -->

## 8. Çıkmış Sınav Soruları: Doğru ve Düzlem

Hoca, önceki yılların sınavlarından (büyük olasılıkla 2017–2018 dönemi, pandemiden önce) doğru ve düzlem sorularını ekranda gösterip çözdü. Soruların farklı gruplarda sorulduğunu ve mantığın hep aynı olduğunu söyledi.

**Örnek 10 (doğruyu içeren düzlem):** Bir $A$ noktasından geçen ve $x=1+2t$, $y=2-3t$, $z=3-t$ doğrusunu içeren düzlemin denklemi.

<!-- BELİRSİZ: A noktasının koordinatları altyazıda okunmuyor. -->

- Düzlem doğruyu içerdiği için doğrunun her noktası düzlemdedir. Doğrudan iki nokta alınır.
- $t=0$ için $B(1,2,3)$.
- $t=1$ için $C(1+2,\;2-3,\;3-1)=C(3,-1,2)$.
- $\overrightarrow{AB}$ ve $\overrightarrow{AC}$ yazılır. Normal $\vec n=\overrightarrow{AB}\times\overrightarrow{AC}$'dir.
- Düzlem: $\overrightarrow{AP}\cdot\vec n=0$.

> **Ders sonrası not:** Altyazıda $t=1$ için nokta "$(3,2,1)$" diye geçiyor. Doğrusu $C(3,-1,2)$'dir.

**Örnek 11 (ara kesit doğrusuna paralel düzlem):** $A(1,0,-1)$ ve $B(2,1,0)$ noktalarından geçen ve $3x-y=4$, $x+y+z=5$ düzlemlerinin ara kesit doğrusuna paralel olan düzlemin denklemi.

- Normaller: $3x-y=4$'te $z$ yok, katsayısı $0$: $\vec n_1=\langle3,-1,0\rangle$. İkinci düzlem: $\vec n_2=\langle1,1,1\rangle$.
- Ara kesit doğrusunun yönü: $\vec v=\vec n_1\times\vec n_2=\begin{vmatrix}\vec i&\vec j&\vec k\\3&-1&0\\1&1&1\end{vmatrix}=\langle-1,-3,4\rangle$.
- $\overrightarrow{AB}=B-A=\langle1,1,1\rangle$.
- Aranan düzlem hem $\vec v$'ye paralel hem de $\overrightarrow{AB}$'yi içeriyor. Bu yüzden normali bu iki vektöre diktir: $\vec n=\vec v\times\overrightarrow{AB}=\begin{vmatrix}\vec i&\vec j&\vec k\\-1&-3&4\\1&1&1\end{vmatrix}=\langle-7,5,2\rangle$ (ara adım eklendi).
- $A$ noktasıyla: $-7(x-1)+5(y-0)+2(z+1)=0$, yani $7x-5y-2z-9=0$ (ara adım eklendi).
- Kontrol: $B$ için $14-5-0-9=0$. Sağlanıyor.

Derste normal $\vec v\times\overrightarrow{AB}$ olarak kuruldu, son denklem sesli okunmadı. Hoca bunun birçok yöntemden biri olduğunu söyledi.

**Örnek 12 (düzleme dik doğru):** $P(-1,0,1)$ noktasından geçen ve normali $\langle2,-1,7\rangle$ olan düzleme dik doğrunun parametrik denklemi.

- Doğru düzleme dik olduğundan yön vektörü düzlemin normalidir: $\vec v=\langle2,-1,7\rangle$.
- Hoca önce aynı nokta ve normalle düzlem denklemini yazdı: $2(x+1)-1(y-0)+7(z-1)=0$.
- Ama soru doğrunun parametrik denklemini istiyor. Doğru üzerindeki her $M$ noktası için $\overrightarrow{PM}$, normale paraleldir: $\overrightarrow{PM}=\lambda\vec n$. Bileşenler eşitlenir.
- Sonuç: $x=-1+2t$, $y=-t$, $z=1+7t$.

**Soru:** (Hoca $x-1$ yazınca) $x+1$ olmayacak mı hocam?
**Cevap:** Evet, doğru. Eksi eksi bir artı olur. Yani $2(x+1)$.

Hoca, aynı sorunun birçok açıdan sorulabileceğini, önemli olanın mantığı anlamak olduğunu söyledi. Ekranda vektör değerli fonksiyonların yay uzunluğu ve çok değişkenli fonksiyonlarla ilgili başka çıkmış soruları da gösterdi ve bunları paylaşacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** Çıkmış sorulardan biri "eğrinin $t$'nin artış yönündeki yay uzunluğu fonksiyonunu" istiyordu. Yay uzunluğu fonksiyonu, sabit bir $t_0$ başlangıcından ölçülen $s(t)=\displaystyle\int_{t_0}^{t}|\vec r\,'(\tau)|\,d\tau$ fonksiyonudur. Yani 7.6'daki integralin üst sınırı değişken bırakılır.

## 9. Çok Değişkenli Fonksiyonlara Giriş

İkinci aradan sonra hoca yeni konuya geçti. Tek değişkenli fonksiyonların analizi bitmişti, şimdi çok değişkenli fonksiyonlara geçiliyordu.

### 9.1 Tek Değişkenden Çok Değişkene

$y=f(x)$ tek değişkenli bir fonksiyondur. $x$ bağımsız değişkendir, ona değer verilir. $y$ ise fonksiyona bağlı olarak değer alan bağımlı değişkendir. $f(x,y)=0$ biçimindeki kapalı yazım da aynı şekilde düşünülür.

$z=f(x,y)$ ise iki değişkenli bir fonksiyondur. İki bağımsız değişken ($x$ ve $y$) vardır, $z$ bağımlı değişkendir. Genel olarak

$$w=f(x_1,x_2,\ldots,x_n)$$

$n$ değişkenli bir fonksiyondur.

Hoca, doğadaki olayların çok değişkenli olduğunu anlattı. Sıcaklık, iklim, hava şartları ve yer gibi birçok etken olaya bir değişken olarak girer. Hocanın örneği hazır betondu: çimento miktarı, kireç miktarı, su miktarı ve benzer birçok parametre işin içine girer. Bu yüzden asıl uygulamalar çok değişkenli fonksiyonlar üzerinde yapılır. Hoca bunu keşfetmenin ve analiz etmenin çok heyecan verici olduğunu söyledi.

### 9.2 Tanım

**İki değişkenli fonksiyon (kutu):**

- $D\subseteq\mathbb R^2$ boştan farklı bir küme olsun.
- $D$'deki her $(x,y)$ ikilisine tek bir $z=f(x,y)$ gerçel sayısını karşılık getiren $f$ kuralına iki değişkenli fonksiyon denir.
- $D$'ye **tanım kümesi** denir.
- $f$'nin aldığı değerlerin kümesi **değer kümesidir** ve $\mathbb R$'nin alt kümesidir.

Hoca öğrencilere fonksiyonun götürdüğü yerin $\mathbb R$ mi, $\mathbb R^3$ mü olduğunu sordu. Cevap $\mathbb R$'dir. Hoca, bu fonksiyonların vektör değerli olmadığına dikkat çekti.

Üç değişkenli fonksiyonlar da benzer şekilde $w=f(x,y,z)$ olarak tanımlanır.

## 10. Tanım Bölgesi Örnekleri

> **Hocanın vurgusu:** Çok değişkenli fonksiyonun tanım bölgesinden mutlaka soru geliyor. Vizede de, finalde de geliyor. Buna dikkat edin.

**Örnek 13:** $z=\dfrac{1}{\sqrt{1-x^2-y^2}}$ fonksiyonunun tanım kümesi.

- Kök tanımlı olmak için içi $\ge0$ olmalı.
- Kök paydada olduğu için sıfır da olamaz. Bu yüzden içi kesin pozitif olmalı: $1-x^2-y^2>0$.
- Hoca, normal bir kökte eşitlik de olabileceğini, burada paydada olduğu için eşitliğin olmadığını vurguladı.
- Sonuç: $x^2+y^2<1$. Merkezi orijin, yarıçapı $1$ olan **açık daire** (sınır çember dahil değil).

Hoca ardından değer kümesini sordu (Örnek Sorular bölümüne bakın). Kendi cevabı şuydu: pay $1$, yani pozitif. Payda pozitif bir kök. O halde $z$ hep pozitiftir, sıfır olamaz, negatif de olamaz.

> **Ders sonrası not:** Hoca değer kümesine "pozitif sayılar" dedi. Daha kesin cevap $[1,\infty)$'dur. Tanım kümesinde $0\le x^2+y^2<1$ olduğundan $0<1-x^2-y^2\le1$'dir. Payda en fazla $1$ olur, bu yüzden $z\ge1$'dir. Orijinde $z=1$, sınıra yaklaşırken $z\to\infty$.

Hoca soru sorarken öğrencilere şunu söyledi:

> **Hocanın vurgusu:** Çekinmeyin, yanlış da olsa cevap verin. Yanlış cevap bile cevap vermemekten daha iyidir.

**Örnek 14:** $z=\sqrt{x^2+y^2-1}+\ln(4-x^2-y^2)$ fonksiyonunun tanım bölgesi.

- Kök için: $x^2+y^2-1\ge0$, yani $x^2+y^2\ge1$.
- Logaritma için: $4-x^2-y^2>0$, yani $x^2+y^2<4$.
- İki koşulun kesişimi: $1\le x^2+y^2<4$.
- Bu, merkezi orijin olan, yarıçapı $1$ ve $2$ olan iki çember arasındaki halkadır.
- İçteki çember ($x^2+y^2=1$) dahildir. Dıştaki çember ($x^2+y^2=4$) dahil değildir ve kesikli çizilir.

**Örnek 15:** Kök içinde iki çarpanın çarpımı bulunan bir fonksiyonun tanım bölgesi.

- Kökün içi sıfırdan büyük olmalı. Çarpanlarına ayrılınca, çarpımın pozitif olması için ya iki çarpan da pozitif ya da ikisi de negatif olmalıdır.
- Hocanın anlattığı durumda bir koşul $3x>y$ çıktı: $y=3x$ doğrusu çizilir ve doğrunun **altı** alınır.
- Diğer koşul $y>-3x$ çıktı: $y=-3x$ doğrusunun **üstü** alınır.
- Tanım bölgesi bu bölgelerin kesişimidir. Hoca bölgeyi şekil üzerinde gösterdi.

<!-- BELİRSİZ: Fonksiyonun tam ifadesi ve "ikisi de negatif" durumunun derste nasıl ele alındığı altyazıda anlaşılmıyor. -->

**Örnek 16:** Logaritma ve $y-x$ içeren bir fonksiyonun tanım bölgesi.

Hoca bu örneği tanım bölgesine sık soru geldiğini tekrar vurgulayarak anlattı.

- Logaritmanın tanımlı olması için içi pozitif olmalı: $y-x>0$.
- İfadenin pozitif olması için iki parçanın da pozitif ya da ikisinin de negatif olması gerekiyor.
- Hoca bir soru sordu: Hangi sayıların logaritması negatiftir? Cevap: $0$ ile $1$ arasındaki sayıların.
- **$x>0$ durumu:** Logaritma da pozitif olmalı, yani $y-x>1$. Bu, $y>x+1$ demektir: $y=x+1$ doğrusunun üstü, $x>0$ tarafı.
- **$x<0$ durumu:** Logaritma da negatif olmalı, yani $0<y-x<1$. Bu, $x<y<x+1$ demektir: $y=x$ ile $y=x+1$ doğruları arasındaki şerit, $x<0$ tarafı.
- Eşitlik olmadığı için sınırlar dahil değildir.

Hoca, slayttaki grafikte bir hata olduğunu söyledi ve grafiği kendisi yeniden çizdi: önce $y=x+1$, sonra $y=x$ doğrusu çizildi. $x>0$ iken $y=x+1$'in üstü, $x<0$ iken iki doğrunun arası tarandı.

<!-- BELİRSİZ: Fonksiyonun tam ifadesi altyazıda okunmuyor (logaritma "[öğrenci]" diye maskelenmiş; "y−1 sıfıra eşit değil" gibi bir koşul da geçiyor). -->

## 11. Temel Yüzeyler

Yaklaşık 02:03 ile 02:05 arasında hocanın mikrofonu kapalı kaldı. Bir öğrenci bunu söyleyince hoca, temel yüzeyleri kısaca yeniden anlattı.

**Temel yüzeyler (kutu):**

- **Küre:** $x^2+y^2+z^2=R^2$. Merkezi $(0,0,0)$, yarıçapı $R$ olan küredir. Merkez $(a,b,c)$ ise $(x-a)^2+(y-b)^2+(z-c)^2=R^2$ yazılır. $z$ terimi olmasaydı bu, düzlemde merkezi $(a,b)$ olan bir çember olurdu.
- **Elipsoid:** $\dfrac{x^2}{a^2}+\dfrac{y^2}{b^2}+\dfrac{z^2}{c^2}=1$. $x$ eksenini $a$'da, $y$ eksenini $b$'de keser. İki boyutta bu bir elipstir, yumurta gibidir. $z$ eklenince küre benzeri bir yüzey olur, ama basık bir küre gibidir.
- **Paraboloid:** $z=x^2+y^2$. Tepe noktası orijindedir. $y=0$ alınınca $z=x^2$, $x=0$ alınınca $z=y^2$ parabolü çıkar. Bunlar birleşince yukarı açık bir tas oluşur.
- **Aşağı açık paraboloid:** $z=a-x^2-y^2$. $y$ yok sayılınca $z=a-x^2$: $a$'dan başlayıp kolları aşağı inen parabol. $x=0$ alınınca $z=a-y^2$. Birleşince tepesi $z=a$'da olan, kolları aşağı inen bir tas olur.
- **Silindir:** $x^2+y^2=R^2$. Düzlemde yarıçapı $R$ olan çemberdir. Üç boyutta $z$ serbest kaldığı için $z$ ekseni boyunca uzanan bir silindir olur.

<!-- BELİRSİZ: Mikrofon kapalıyken (yaklaşık 02:03–02:05) anlatılanlar altyazıda yok; hoca yalnız temel yüzeyleri tekrar etti. -->

> **Ek bilgi (derste anlatılmadı):** Silindir denkleminde bir değişkenin (burada $z$'nin) hiç görünmemesi, o değişkenin her değeri alabileceği anlamına gelir. Bu yüzden düzlemdeki çember, o eksen boyunca kaydırılarak bir yüzey oluşturur. Aynı mantık, 5.1'de üç boyutta $ax+by+c=0$'ın neden bir düzlem olduğunu da açıklar.

Hoca, seviye eğrileri (level curves) ve kontur eğrilerinin bir sonraki derste verileceğini söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:09:07): $\overrightarrow{PQ}=\langle-2,-2,1\rangle$ ve $\overrightarrow{QR}=\langle6,-1,-1\rangle$ vektörleri arasındaki $\theta$ açısı nasıl bulunur?

> **Çözüm (derste verildi):** Skaler çarpım alınır: $\overrightarrow{PQ}\cdot\overrightarrow{QR}=-11$. Boylar $3$ ve $\sqrt{38}$. $\cos\theta=\dfrac{-11}{3\sqrt{38}}$, yani $\theta=\arccos\left(\dfrac{-11}{3\sqrt{38}}\right)\approx126{,}5^\circ$. Ayrıntı Örnek 1'de.

**Soru 2** (derste sözlü, 01:19:32, çıkmış soru): $\vec r(t)=3\cos t\,\vec i+3\sin t\,\vec j+t^2\,\vec k$ için birim teğet vektörü bulunuz.

> **Çözüm (derste verildi):** $\vec r\,'(t)=-3\sin t\,\vec i+3\cos t\,\vec j+2t\,\vec k$, $|\vec r\,'(t)|=\sqrt{9+4t^2}$. $\vec T=\dfrac{-3\sin t\,\vec i+3\cos t\,\vec j+2t\,\vec k}{\sqrt{9+4t^2}}$.

**Soru 3** (derste sözlü, 01:28:33, çıkmış soru): $A$ noktasından geçen ve $x=1+2t$, $y=2-3t$, $z=3-t$ doğrusunu içeren düzlemin denklemi aşağıdakilerden hangisidir? <!-- BELİRSİZ: A noktasının koordinatları ve şıklar altyazıda okunmuyor. -->

> **Çözüm (derste verildi, yöntem):** Doğrudan $B(1,2,3)$ ($t=0$) ve $C(3,-1,2)$ ($t=1$) alınır. Normal $\overrightarrow{AB}\times\overrightarrow{AC}$; düzlem $\overrightarrow{AP}\cdot\vec n=0$. $A$ okunmadığı için son denklem yazılamıyor.

**Soru 4** (derste sözlü, 01:30:54, çıkmış soru): $A(1,0,-1)$ ve $B(2,1,0)$ noktalarından geçen ve $3x-y=4$, $x+y+z=5$ düzlemlerinin ara kesit doğrusuna paralel olan düzlemin denklemini bulunuz.

> **Çözüm (derste yöntem verildi, son denklem okunmadı; sympy ile kesinleştirildi):** $\vec v=\langle3,-1,0\rangle\times\langle1,1,1\rangle=\langle-1,-3,4\rangle$, $\overrightarrow{AB}=\langle1,1,1\rangle$, $\vec n=\vec v\times\overrightarrow{AB}=\langle-7,5,2\rangle$. Düzlem: $7x-5y-2z-9=0$.

**Soru 5** (derste sözlü, 01:34:25, çıkmış soru): $P(-1,0,1)$ noktasından geçen ve normali $\langle2,-1,7\rangle$ olan düzleme dik doğrunun parametrik denklemini yazınız.

> **Çözüm (derste verildi):** Yön vektörü normaldir. $x=-1+2t$, $y=-t$, $z=1+7t$.

**Soru 6** (derste sözlü, 01:33:47, çıkmış soru): Verilen eğrinin $t$'nin artış yönündeki yay uzunluğu fonksiyonunu bulunuz. <!-- BELİRSİZ: Eğrinin ifadesi altyazıda okunmuyor; derste çözülmedi, yalnız ekranda gösterildi. -->

**Soru 7** (derste sözlü, 01:54:58): $z=\dfrac{1}{\sqrt{1-x^2-y^2}}$ fonksiyonunun değer kümesi nedir?

> **Çözüm (derste verildi, düzeltilerek):** Hoca "pozitif sayılar" dedi. Kesin cevap: $0<1-x^2-y^2\le1$ olduğundan $z\ge1$, değer kümesi $[1,\infty)$.

**Soru 8** (derste sözlü, 02:00:11): Hangi sayıların logaritması negatiftir?

> **Çözüm (derste verildi):** $0$ ile $1$ arasındaki sayıların. Yani $0<u<1$ ise $\ln u<0$.

## Dersin Toparlaması

Bu derste önce vektörlerin temel araçları (skaler çarpım, iz düşüm, vektörel çarpım, birim vektör) bir örnek üzerinde tekrar edildi. Ardından uzayda doğrunun vektör, parametrik ve simetrik denklemleri kuruldu. Bir doğru için bir nokta ve bir yön vektörü, bir düzlem için bir nokta ve bir normal vektör gerektiği vurgulandı. Noktanın doğruya uzaklığı paralelkenar alanından, üç noktadan geçen düzlemin normali vektörel çarpımdan bulundu. Düzlemler ve doğrular arasındaki paralellik, diklik, açı ve ara kesit doğrusu hep normaller üzerinden incelendi. Çıkmış sınav sorularıyla bu yöntemler pekiştirildi.

İkinci bölümde vektör değerli fonksiyonların türevi, hız, sürat, ivme, birim teğet vektör, limit, süreklilik, türev kuralları ve yay uzunluğu görüldü. Son bölümde çok değişkenli fonksiyonlara giriş yapıldı: tanım ve değer kümeleri örneklerle bulundu, temel yüzeyler (küre, elipsoid, paraboloid, silindir) tanıtıldı. Hoca bir sonraki derste seviye eğrileri, ardından çok değişkenli fonksiyonlarda limit ve süreklilik, sonra kısmi türev ve çok katlı integrallerle devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
