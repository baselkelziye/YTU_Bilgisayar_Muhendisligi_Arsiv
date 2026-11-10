# Ders 7 Genişletilmiş Notu: Kutupsal Koordinatlar: Eğri Çizimi, Kardiyoid, Alan ve Yay Uzunluğu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kutupsal Koordinat Sistemi
- 2. Kartezyen ve Kutupsal Koordinatlar Arasındaki Dönüşüm
- 3. Eşitsizliklerle Verilen Bölgeler
- 4. Kutupsal Eğrilerde Simetri
- 5. Kutupsal Koordinatlarda Eğri Çizimi
- 6. Kardiyoidin Pratik Çizimi
- 7. Kardiyoid Olmayan Bir Eğri: $r=2-4\sin\theta$
- 8. Temel Kutupsal Eğriler
- 9. Kutupsal Koordinatlarda Alan
- 10. İki Eğri Arasındaki Alan: Çıkmış Sorular
- 11. Kutupsal Koordinatlarda Yay Uzunluğu
- 12. Hocanın Kendi Sorusu: Çemberin Dışında, Kardiyoidin İçinde
- 13. Örnek Sorular
- 14. Ders Sonrası Notlar

## 1. Kutupsal Koordinat Sistemi

Hoca derse serilerin bittiğini, sıradaki konunun kutupsal koordinatlar (polar coordinates) olduğunu söyleyerek başladı. Düzlemde şimdiye kadar $x$ ve $y$ dik koordinatlarını, yani Kartezyen koordinatları kullandık. Şimdi aynı düzlemi başka bir koordinat sistemiyle tarif edeceğiz.

Kutupsal koordinat sistemini kurmak için düzlemde bir nokta ve bu noktadan çıkan bir ışın seçilir. Bu noktaya **kutup** (pole), ışına ise **kutup ekseni** (polar axis) denir. Hoca tahtada kutbu $O$ ile gösterdi ve kutup eksenini sağa doğru, $x$ ekseninin pozitif yönü gibi çizdi.

Düzlemdeki bir $P$ noktası $(r,\theta)$ sıralı ikilisiyle gösterilir:

- $r$: kutuptan $P$'ye olan **yönlü uzaklık**.
- $\theta$: kutup ekseninden $OP$ doğrusuna olan **yönlü açı**.

Açının yönü önemlidir. Pozitif $\theta$ saatin tersi yönünde, yani yukarı doğru ölçülür. Negatif $\theta$ ise saat yönünde, yani aşağı doğru ölçülür.

Başka bir deyişle $(r,\theta)$ noktası, kutup ekseniyle $\theta$ açısı yapan doğru üzerinde, kutuptan $r$ birim uzaklıkta bulunan noktadır.

### 1.1 Bir noktanın sonsuz sayıda gösterimi

Kartezyen koordinatlardan önemli bir farkı şudur: Bir noktayı temsil eden sonsuz sayıda kutupsal koordinat çifti vardır.

- $r=0$ ise $\theta$ ne olursa olsun nokta kutuptur. Hoca bunu "yarıçap sıfır; o zaman $\theta$ isterse 360 derece olsun, yine aynı yer" diye açıkladı.
- Açıya $2\pi$'nin katları eklenince aynı noktaya gelinir: $(r,\theta)$ ile $(r,\theta+2k\pi)$ aynı noktadır.
- $r<0$ ise nokta, $\theta$ ışınının **tam ters yönündedir**. Bu yüzden $(-r,\theta)$ ile $(r,\theta+\pi)$ aynı noktayı gösterir. Benzer biçimde $(r,\theta)$ ile $(-r,\pi+\theta)$ da aynı noktadır.

### 1.2 Nokta yerleştirme örnekleri

**Örnek 1:** $(3,\pi/4)$ noktası.

Önce açı çizilir: kutup ekseninden saatin tersi yönünde $\pi/4$ kadar dönülür. Sonra bu ışın üzerinde kutuptan 3 birim gidilir. Nokta birinci bölgededir.

**Örnek 2:** $(2,-\pi/6)$ noktası.

Önce açı yapılır. Açı negatif olduğu için saat yönünde, yani aşağı doğru dönülür. $-\pi/6$, $-30°$ demektir. Bu ışın üzerinde 2 birim gidilir. Nokta dördüncü bölgededir.

**Örnek 3:** $(-3,\pi/3)$ noktası.

Önce $\pi/3$ ışını çizilir. $r=+3$ olsaydı nokta bu ışın üzerinde 3 birim ileride olurdu. $r=-3$ olduğu için nokta bu ışının tam ters yönünde, kutuptan 3 birim uzaktadır. Bu, açısı $\pi+\pi/3$ olan ışın üzerindeki noktadır.

Hoca burada öğrencilere sordu: $r=3$ alınırsa açı ne olmalı? Cevap $\pi+\dfrac{\pi}{3}=\dfrac{4\pi}{3}$'tür. Yani

$$(-3,\tfrac{\pi}{3})=(3,\tfrac{4\pi}{3}).$$

İkisinin Kartezyen karşılığı da $\left(-\tfrac32,-\tfrac{3\sqrt3}{2}\right)$'dir; nokta üçüncü bölgededir.

## 2. Kartezyen ve Kutupsal Koordinatlar Arasındaki Dönüşüm

Hoca bu kısmın önemli olduğunu söyledi. Tahtada $x$ ve $y$ eksenlerini çizdi ve bir $P(x,y)$ noktası aldı. Kutupsalda bu nokta $(r,\theta)$ ile gösterilir: $r$, $OP$ doğru parçasının uzunluğu; $\theta$, $OP$'nin $x$ ekseniyle yaptığı açıdır.

$P$'den $x$ eksenine dik inilince bir dik üçgen oluşur. Bu üçgende $\theta$ açısına komşu dik kenar $x$, karşı dik kenar $y$, hipotenüs $r$'dir. Hoca bunları öğrencilere sordu ve öğrenciler cevapladı:

$$\cos\theta=\frac{x}{r},\qquad \sin\theta=\frac{y}{r}.$$

Buradan $x$ ve $y$ çekilir:

$$x=r\cos\theta,\qquad y=r\sin\theta.$$

İki eşitliğin kareleri alınıp taraf tarafa toplanırsa

$$x^2+y^2=r^2\cos^2\theta+r^2\sin^2\theta=r^2(\cos^2\theta+\sin^2\theta)=r^2$$

bulunur. Açıyı bulmak için de iki eşitlik oranlanır:

$$\tan\theta=\frac{y}{x}.$$

**Tanım kutusu: Dönüşüm formülleri**

- $x=r\cos\theta$
- $y=r\sin\theta$
- $x^2+y^2=r^2$
- $\tan\theta=\dfrac{y}{x}$

### 2.1 Örnek 4: Orijin merkezli çember

$x^2+y^2=a^2$, merkezi orijin, yarıçapı $a$ olan çemberdir. Kutupsala geçmek için $x$ yerine $r\cos\theta$, $y$ yerine $r\sin\theta$ yazılır. Kareler toplamı $r^2$ olduğundan

$$r^2=a^2\quad\Rightarrow\quad r=a$$

elde edilir. Kutupsalda "yarıçapı $a$ olan çember" denklemi bu kadar basittir.

### 2.2 Örnek 5: $r^2=a^2\cos 2\theta$ eğrisinin Kartezyen denklemi

Hoca bunun sınavlarda karşılaşılabilecek bir soru tipi olduğunu söyledi. Verilen kutupsal denklemin Kartezyen denklemi isteniyor.

İlk adım $\cos 2\theta$'yı tek açılı hale getirmektir. Hoca üç yazılışı hatırlattı:

$$\cos 2\theta=\cos^2\theta-\sin^2\theta=1-2\sin^2\theta=2\cos^2\theta-1.$$

Burada ilki kullanılır. $\cos\theta=\dfrac{x}{r}$ ve $\sin\theta=\dfrac{y}{r}$ yazılırsa

$$r^2=a^2\left(\frac{x^2}{r^2}-\frac{y^2}{r^2}\right)=a^2\,\frac{x^2-y^2}{r^2}.$$

$r^2$ karşı tarafa geçer:

$$r^4=a^2(x^2-y^2).$$

$r^4=(r^2)^2=(x^2+y^2)^2$ olduğundan sonuç

$$(x^2+y^2)^2=a^2(x^2-y^2)$$

olur. (sympy ile doğrulandı.)

> **Ek bilgi (derste anlatılmadı):** $(x^2+y^2)^2=a^2(x^2-y^2)$ eğrisine Bernoulli lemniskatı (lemniscate) denir. Sonsuzluk işaretine ($\infty$) benzer ve kutuptan geçer. $\cos2\theta<0$ olan açılarda $r^2$ negatif olacağından eğrinin o açılarda noktası yoktur.

### 2.3 Örnek 6: $(x-a)^2+y^2=a^2$ çemberinin kutupsal denklemi

Bu çemberin merkezi $(a,0)$, yarıçapı $a$'dır. Kutuptan (orijinden) geçer. Hoca çemberi önce Kartezyen düzlemde çizdi.

Parantez açılır:

$$x^2-2ax+a^2+y^2=a^2\quad\Rightarrow\quad x^2+y^2-2ax=0.$$

$x^2+y^2=r^2$ ve $x=r\cos\theta$ yazılır:

$$r^2-2ar\cos\theta=0\quad\Rightarrow\quad r=2a\cos\theta.$$

Hoca bundan şu sonucu çıkardı: Bize "$r=2a\cos\theta$ eğrisini çiziniz" denirse, onu Kartezyene çevirip bu çember olarak çizeriz. Kutupsal denklemi doğrudan çizmek zordur; dönüştürmek işi kolaylaştırır.

Bu kısımda hocanın sorduğu $r=2\sin\theta$ sorusu, "Örnek Sorular" bölümünde ayrıca çözüldü.

## 3. Eşitsizliklerle Verilen Bölgeler

Hoca, kutupsal koordinatlarda eşitsizliklerle verilen nokta kümelerinin grafiklerini çizdi.

### 3.1 $1\le r\le 2$, $0\le\theta\le\pi/2$

$r=1$, yarıçapı 1 olan çember; $r=2$, yarıçapı 2 olan çemberdir. $1\le r\le2$ bu iki çember arasındaki halkadır. $0\le\theta\le\pi/2$ ise açının $x$ ekseninden $y$ eksenine kadar gittiğini söyler. Sonuç: birinci bölgedeki halka parçası.

Hoca bir de şunu ekledi: $\theta$ yalnız $0$ ile $\pi$ arasında olsaydı halkanın üst yarısı alınırdı.

### 3.2 $-3\le r\le 2$, $\theta=\pi/4$

Açı sabit olduğu için bölge, $\pi/4$ doğrusu üzerindeki bir doğru parçasıdır. Pozitif $r$ değerleri $\pi/4$ ışını üzerinde kutuptan 2 birime kadar gider. Negatif $r$ değerleri ters yönde, yani $5\pi/4$ yönünde 3 birime kadar uzanır.

### 3.3 $\dfrac{2\pi}{3}\le\theta\le\dfrac{5\pi}{6}$, $r$ sınırsız

$r$ üzerinde bir koşul yok. Hoca "$r$ yok, sınırsız" dedi. $2\pi/3$ yani $120°$ ışını ile $5\pi/6$ yani $150°$ ışını arasında kalan, sonsuza uzanan kama biçimli bölge alınır.

Hoca ardından koşulları değiştirip, açının $-\pi$ ile başlayan bir aralıkta ve $r$'nin $-1$ ile $+1$ arasında olduğu bir durumu sordu. <!-- BELİRSİZ: 00:21:35-00:22:09 arası; açı aralığının üst sınırı ve çizilen bölge altyazıdan okunmuyor. -->

### 3.4 $1\le r<2$, $0\le\theta\le\pi/4$

Burada $r=1$ dahil, $r=2$ hariçtir. Hoca, dahil olmayan sınırı (yarıçapı 2 olan çember yayını) kesik çizgiyle (nokta nokta) çizdi. Bölge, $1$ ve $2$ çemberleri arasında, $0$ ile $\pi/4$ açıları arasında kalan halka parçasıdır. <!-- BELİRSİZ: 00:22:25; açı aralığı altyazıda "sıfırla pi 1'e 4 arasında" diye geçiyor, $0\le\theta\le\pi/4$ olarak okundu. -->

Yalnız $r=1$ denseydi, bölge değil sadece $r=1$ çemberinin bu açılar arasındaki yayı alınırdı.

Hoca ardından "2 ile 3 arasında" diye başlayan bir örnek daha verdi. <!-- BELİRSİZ: 00:23:10; bu örneğin koşulları altyazıda anlaşılmıyor. -->

## 4. Kutupsal Eğrilerde Simetri

Arada verilen moladan sonra hoca simetri özelliklerine geçti. $r=f(\theta)$ eğrisi için:

**Simetri kuralları**

- **Kutup eksenine göre simetri** ($x$ ekseni): $\theta$ yerine $-\theta$ yazılınca denklem değişmiyorsa, yani $f(-\theta)=f(\theta)$ ise, eğri kutup eksenine göre simetriktir. Hoca bunu tahtada gösterdi: $(r,\theta)$ noktası kutup ekseninin üstündeyse, $(r,-\theta)$ noktası aynı uzunlukta ama aşağıda kalır; ikisi kutup eksenine göre birbirinin yansımasıdır.
- **$\theta=\pi/2$ doğrusuna göre simetri** ($y$ ekseni): $(r,\theta)$ yerine $(-r,-\theta)$ yazılınca denklem değişmiyorsa eğri $\theta=\pi/2$ doğrusuna göre simetriktir.
- Aynı simetri $\theta$ yerine $\pi-\theta$ yazarak da kontrol edilir: $f(\pi-\theta)=f(\theta)$ ise eğri $\theta=\pi/2$ doğrusuna göre simetriktir.

Hoca $(-r,\theta)$ noktasının tahtada nasıl bulunduğunu mavi kalemle tekrar gösterdi: $r$ negatif olunca nokta $\theta$ ışınının yönünde değil, tam ters yönünde alınır.

> **Hocanın vurgusu:** Bu kurallar ezber değildir. Şekli çizerken kendi kendinize çıkarabileceğiniz kurallardır. Önemli olan grafiği doğru çizebilmektir. Bu kurallardan zaman zaman faydalanırsınız.

### 4.1 Eğim

Hoca, $r=f(\theta)$ eğrisinin $(r,\theta)$ noktasındaki eğiminin $\dfrac{dy}{dx}$ türevinin o noktadaki değeri olduğunu, $x$ ve $y$ yerine kutupsal karşılıkları yazılarak bulunduğunu söyledi. Formül slaytta gösterildi, altyazıda sözlü okunmadı.

> **Ek bilgi (derste anlatılmadı):** $x=r\cos\theta$, $y=r\sin\theta$ ve $r=f(\theta)$ olduğundan, $\theta$'ya göre türev alıp oranlayınca eğim $\dfrac{dy}{dx}=\dfrac{r'\sin\theta+r\cos\theta}{r'\cos\theta-r\sin\theta}$ olur ($r'=dr/d\theta$). Payda sıfır, pay sıfırdan farklıysa teğet düşeydir.

## 5. Kutupsal Koordinatlarda Eğri Çizimi

Hoca, Matematik 1'de Kartezyen koordinatlarda eğri çizimini gördüğümüzü hatırlattı. Kutupsal koordinatlarda da benzer bir yol izlenir.

**$r=f(\theta)$ grafiği çizilirken adımlar**

- Eğri periyodikse periyot bulunur. Çizim bir periyot içinde yapılır.
- Simetri durumu incelenip çizim aralığı belirlenir (kutup eksenine göre mi, $\theta=\pi/2$'ye göre mi).
- $r=f(\theta)$'nın değişimi türev yardımıyla incelenir. Türev pozitifse $r$ artar, negatifse azalır.
- Bazı $\theta$ değerleri için $r$ bulunur.
- $\theta$, $r$ ve $r'$ değerlerini içeren tablo yapılır ve eğri çizilir.

### 5.1 Örnek 7: $r=a(1+\cos\theta)$, $a>0$

Hoca bu eğri için sınavda şunların sorulabileceğini söyledi: grafiği hangisidir, alanı nedir, yay uzunluğu nedir.

**Periyot.** Hoca öğrencilere periyodun neden $2\pi$ olduğunu sordu. Cevap: denklemde yalnız $\cos\theta$ var; $\cos\theta$'nın periyodu $2\pi$'dir. Yani eğri $0$ ile $2\pi$ arasında çizilir; aynı şekil $2\pi$'den $4\pi$'ye, $0$'dan $-2\pi$'ye tekrar eder.

Hoca periyot üzerine iki soru daha sordu:

- $\cos\theta$ yerine $\cos3\theta$ olsaydı periyot ne olurdu? Öğrenciler doğru cevap verdi: $\dfrac{2\pi}{3}$.
- $\tan\theta$ olsaydı periyot ne olurdu? $\pi$.

**Simetri.** $\theta$ yerine $-\theta$ yazılınca $\cos(-\theta)=\cos\theta$ olduğundan denklem değişmez. Eğri kutup eksenine göre simetriktir. Bu yüzden yalnız üst yarı çizilir; inceleme aralığı $[0,\pi]$'dir. Hoca diğer simetri testlerinin sağlanmadığını belirtti.

**Türev.** $r'=-a\sin\theta$. $[0,\pi]$'de $\sin\theta\ge0$ olduğundan $r'\le0$; yani $r$ bu aralıkta azalır.

**Tablo.** $\theta=0$'da $\cos0=1$, $r=2a$. $\theta=\pi/2$'de $r=a$. $\theta=\pi$'de $\cos\pi=-1$, $r=0$.

| $\theta$ | $0$ | $\pi/2$ | $\pi$ |
|---|---|---|---|
| $r'$ | $0$ | $-a$ | $0$ |
| $r$ | $2a$ | $a$ | $0$ |

**Çizim.** $\theta=0$'da kutup ekseni üzerinde $2a$ uzaklıktan başlanır. Açı $90°$ olunca $r=a$, açı $180°$ olunca $r=0$ olur ve eğri kutba varır. Bu üst yarıdır. Kutup eksenine göre yansıtılınca alt yarı da elde edilir. Ortaya bir kalp şekli çıkar. Hoca adını "kardiyolojiden, kalpten geliyor" diye açıkladı: **kardiyoid** (cardioid).

## 6. Kardiyoidin Pratik Çizimi

Hoca, sınav test biçiminde olduğu için uzun eğri çizim adımlarına gerek kalmadan kardiyoidi hızlıca çizmenin pratik yolunu gösterdi: yalnız birkaç açıda ($0$, $\pi/2$, $\pi$, $3\pi/2$) $r$ değerini bulmak.

> **Hocanın vurgusu:** Bu pratik yol test sınavında çok işe yarar. Üç dört açı verip hemen çizersiniz.

**Kardiyoid biçimleri:** $r=a(1+\cos\theta)$, $r=a(1-\cos\theta)$, $r=a(1+\sin\theta)$, $r=a(1-\sin\theta)$. Parantez içindeki sabit 1, trigonometrik terimin katsayısı da 1 olmalıdır; dışarıdaki $a$ çarpanı önemli değildir.

### 6.1 Örnek 8: $r=2(1+\sin\theta)$

Hoca basit olsun diye bu kardiyoidi seçti ve değerleri öğrencilerle birlikte hesapladı.

- $\theta=0$: $\sin0=0$, $r=2(1+0)=2$.
- $\theta=\pi/2$: $\sin90°=1$, $r=2(1+1)=4$.
- $\theta=\pi$: $\sin\pi=0$, $r=2$.
- $\theta=3\pi/2$: $\sin270°=-1$, $r=2(1-1)=0$.

| $\theta$ | $0$ | $\pi/2$ | $\pi$ | $3\pi/2$ |
|---|---|---|---|---|
| $r$ | $2$ | $4$ | $2$ | $0$ |

Hoca $\theta=\pi$ değerini hesaplarken bir an karıştırdı, sonra düzeltip $r(\pi)=2$ olduğunu söyledi.

**Çizim.** Kutup ekseni üzerinde 2'den başlanır. $90°$'de $y$ ekseni üzerinde 4'e çıkılır. $180°$'de negatif $x$ ekseni üzerinde 2'ye inilir. $270°$'de $r=0$ olduğundan eğri kutba gelir. Kalbin uzun kısmı ($r=4$) yukarıda, sivri ucu kutuptadır.

### 6.2 Örnek 9: $r=a(1-\cos\theta)$

Hoca bunu mavi kalemle doğrudan çizdi.

- $\theta=0$: $\cos0=1$, $1-1=0$, $r=0$.
- $\theta=\pi/2$: $\cos90°=0$, $r=a$.
- $\theta=\pi$: $\cos\pi=-1$; önündeki eksiyle artı olur, $1+1=2$, $r=2a$.
- $\theta=3\pi/2$: $\cos270°=0$, $r=a$.

| $\theta$ | $0$ | $\pi/2$ | $\pi$ | $3\pi/2$ |
|---|---|---|---|---|
| $r$ | $0$ | $a$ | $2a$ | $a$ |

Kalbin uzun kısmı ($2a$) negatif $x$ ekseni yönündedir; sivri ucu kutuptadır. Hoca bunu "$x$ ekseninin negatif yönünde olan kardiyoid" diye özetledi.

Hoca ayrıca sınavda şu tür şıklı soruların da gelebileceğini söyledi: "Aşağıdakilerden hangisi doğrudur? Türevi şuna eşittir; kutup eksenine göre simetriktir..." gibi. Yani yöntemin bilinip bilinmediği de sorulabilir.

**Soru:** Kutupsal koordinatlarda eksenlere ne ad veriyoruz? Örneğin $x$ ekseni $r$ mi oluyor, $y$ ekseni $\theta$'ya mı dönüşüyor?
**Cevap:** Hoca, eksenlerin $r$ ve $\theta$ olmadığını, bir $P$ noktasının $(r,\theta)$ ile belirlendiğini açıkladı: $\theta$, $OP$'nin kutup ekseniyle yaptığı açı; $r$ ise $OP$'nin uzunluğudur. Tabloda yalnız uç açılar ($0$, $\pi/2$, ...) verildi; arada, örneğin $\pi/4$'te, ara bir $r$ değeri gelir.

## 7. Kardiyoid Olmayan Bir Eğri: $r=2-4\sin\theta$

Hoca, her $a\pm b\sin\theta$ biçimindeki eğrinin kardiyoid olmadığını vurguladı. $r=2-4\sin\theta$ kardiyoid değildir, çünkü sabit terim (2) ile $\sin\theta$'nın katsayısı (4) eşit değildir. Böyle bir eğri gelince normal eğri çizim yöntemiyle (tablo, simetri, türev) çizmek gerekir.

Hoca yine birkaç açı verdi:

- $\theta=0$: $\sin0=0$, $r=2$.
- $\theta=\pi/2$: $\sin90°=1$, $r=2-4=-2$. $r$ negatif olduğu için nokta $90°$ ışınında değil, ters yönde, aşağıda $(0,-2)$'dedir.
- $\theta=\pi$: $\sin\pi=0$, $r=2$.
- $\theta=3\pi/2$: $\sin270°=-1$, $r=2+4=6$. Nokta yine aşağıda, $(0,-6)$'dadır.

| $\theta$ | $0$ | $\pi/2$ | $\pi$ | $3\pi/2$ |
|---|---|---|---|---|
| $r$ | $2$ | $-2$ | $2$ | $6$ |

Hoca eğrinin biçiminin "garip" olduğunu, bunların tablo ile yaklaşık çizildiğini söyledi ve şeklin slayttaki "Şekil A"da görüldüğünü belirtti.

> **Ek bilgi (derste anlatılmadı):** $r=a+b\sin\theta$ ya da $r=a+b\cos\theta$ biçimindeki eğrilere limaçon denir. $|a|=|b|$ ise kardiyoid, $|a|<|b|$ ise iç döngülü limaçon, $|a|>|b|$ ise iç döngüsüz limaçon elde edilir. $r=2-4\sin\theta$ iç döngülü bir limaçondur; iç döngü, $r$'nin negatif olduğu açılarda oluşur.

## 8. Temel Kutupsal Eğriler

Hoca, sık karşılaşılan temel şekilleri bir kez daha topladı ve bunların önemli olduğunu söyledi.

**Temel eğriler**

- $r=a$: merkezi kutup, yarıçapı $a$ olan çember.
- $\theta=\alpha$: kutup ekseniyle $\alpha$ açısı yapan, kutuptan geçen doğru.
- $r=2a\cos\theta$: kutuptan geçen, merkezi $(a,0)$, yarıçapı $a$ olan çember. Her iki taraf $r$ ile çarpılıp $r\cos\theta$ yerine $x$ yazılarak bulunur (bkz. Örnek 6).
- $r=2a\sin\theta$: kutuptan geçen, merkezi $(0,a)$, yarıçapı $a$ olan çember. Bu kez $r\sin\theta$ yerine $y$ yazılır.
- $r=a(1\pm\cos\theta)$, $r=a(1\pm\sin\theta)$: kardiyoidler. Uzun kısım "kalbin uzun kuyruğu"dur, öbür taraflar kısa kısımlardır.
- $r=a\sin n\theta$, $r=a\cos n\theta$: gül eğrileri (rose curves). Hoca bunların pratik çizimlerinin ders notlarında olduğunu söyledi.

Hoca $r=2a\cos\theta$ ve $r=2a\sin\theta$ çemberlerinin yarıçapını söylerken bir hata yaptı; düzeltmesi "Ders Sonrası Notlar" bölümündedir.

Hoca ayrıca $r=a\cos\theta+b\sin\theta$ biçiminde bir eğriden de söz etti. <!-- BELİRSİZ: 01:13:05; altyazıda "reçap koordinatı tta, reçap sinüs tta b ... x a dolusu, y b dolusu" geçiyor; eğrinin tam denklemi ve hocanın söylediği sonuç okunmuyor. -->

## 9. Kutupsal Koordinatlarda Alan

İkinci moladan önce hoca bu konunun çok önemli olduğunu, ertesi gün vektörlere geçileceğini söyledi.

**Soru:** Eğrinin denkleminde $\sin$ ve $\cos$ yerine $\tan\theta$ gibi bir şey gelirse ne yapacağız?
**Cevap:** O zaman genel eğri çizim maddeleri uygulanır: kutup eksenine göre, $\theta=\pi/2$'ye göre ya da kutba göre simetriye bakılır, türev alınır, daha fazla ara nokta konup ona göre çizilir. Hoca bu tür eğrilerin az ihtimalle geldiğini söyledi.

> **Hocanın vurgusu:** Alan sorularında önce eğri çizilmelidir. Eğri çizmeden alan bulunamaz. Genelde iki eğri arasında kalan alan soruluyor.

**Tanım kutusu: Kutupsal alan formülü**

- $r=f(\theta)$ eğrisi ile $\theta=\alpha$ ve $\theta=\beta$ doğrularının sınırladığı bölgenin alanı:

$$A=\frac12\int_\alpha^\beta r^2\,d\theta.$$

- Bölge simetrikse yarısı hesaplanıp 2 ile çarpılır.

Hoca bunu bir kardiyoid üzerinde anlattı: kardiyoid çizilir, üzerinde $\theta=\alpha$ ve $\theta=\beta$ ışınları işaretlenir. İstenen, kardiyoidin tamamının değil, bu iki ışın arasındaki parçasının alanıdır. Tamamı isteniyorsa, örneğin kutup eksenine göre simetrik bir kardiyoidde, $0$'dan $\pi$'ye kadar alınıp 2 ile çarpılır.

### 9.1 Örnek 10: $r=2(1+\sin\theta)$ kardiyoidinin alanı

Hoca soruyu boş bir sayfada çözdü ve kardiyoidi rastgele seçtiğini söyledi.

**Çizim.** Önce şekil çizilir:

- $\theta=0$: $r=2$.
- $\theta=\pi/2$: $r=4$.
- $\theta=\pi$: $r=2$.
- $\theta=-\pi/2$ (ya da $3\pi/2$): $\sin=-1$, $r=0$.

Kalbin uzun kısmı yukarıdadır.

**Simetri.** Eğri $y$ eksenine ($\theta=\pi/2$ doğrusuna) göre simetriktir. Sağ yarı, $\theta=-\pi/2$'den $\theta=\pi/2$'ye kadar taranır.

**Kurulum.** Sağ yarının alanı

$$\frac{A}{2}=\frac12\int_{-\pi/2}^{\pi/2}\left[2(1+\sin\theta)\right]^2d\theta.$$

Paydadaki 2 karşı tarafa geçince tam alan bulunur:

$$A=\int_{-\pi/2}^{\pi/2}4(1+\sin\theta)^2\,d\theta.$$

Hoca buradan sonrası için "normal kareyi alıp integre edeceğim: birincinin karesi, birinci ile ikincinin çarpımının iki katı..." dedi. Sonucu derste söylemedi. Hesap şöyle tamamlanır (ara adım eklendi):

$$A=4\int_{-\pi/2}^{\pi/2}\left(1+2\sin\theta+\sin^2\theta\right)d\theta.$$

- $\displaystyle\int_{-\pi/2}^{\pi/2}1\,d\theta=\pi$.
- $\displaystyle\int_{-\pi/2}^{\pi/2}2\sin\theta\,d\theta=0$ ($\sin$ tek fonksiyon).
- $\displaystyle\int_{-\pi/2}^{\pi/2}\sin^2\theta\,d\theta=\int_{-\pi/2}^{\pi/2}\frac{1-\cos2\theta}{2}\,d\theta=\frac{\pi}{2}$.

$$A=4\left(\pi+0+\frac{\pi}{2}\right)=6\pi.$$

(sympy ile doğrulandı.)

### 9.2 Örnek 11: $r=1+\cos\theta$ kardiyoidinin alanı (slayt)

Hoca slayttaki çözümü gösterdi: eğri kutup eksenine göre simetrik olduğu için $0$'dan $\pi$'ye kadar alınıp 2 ile çarpılır.

$$A=2\cdot\frac12\int_0^{\pi}(1+\cos\theta)^2\,d\theta.$$

Sonuç slaytta yazılıydı, altyazıda okunmadı. Hesap (ara adım eklendi):

$$A=\int_0^\pi\left(1+2\cos\theta+\cos^2\theta\right)d\theta=\pi+0+\frac{\pi}{2}=\frac{3\pi}{2}.$$

(sympy ile doğrulandı.)

> **Ek bilgi (derste anlatılmadı):** İki örnek birlikte genel bir sonuç verir: $r=a(1\pm\cos\theta)$ ya da $r=a(1\pm\sin\theta)$ kardiyoidinin alanı $\dfrac{3\pi a^2}{2}$'dir. $a=1$ için $\tfrac{3\pi}{2}$, $a=2$ için $6\pi$ bulunur.

## 10. İki Eğri Arasındaki Alan: Çıkmış Sorular

Hoca bu bölümde sınavlarda çıkmış soruları çözdü.

### 10.1 Örnek 12: $r=4\cos\theta$ ve $r=4\sin\theta$ eğrilerinin ortak alanı

**Çizim.** Önce iki eğri çizilir. Örnek 6'ya göre:

- $r=4\cos\theta$: merkezi $(2,0)$, yarıçapı 2 olan, kutba ve $y$ eksenine "yaslanmış" çember.
- $r=4\sin\theta$: merkezi $(0,2)$, yarıçapı 2 olan, üst tarafta duran çember. Hoca bunu yeşil kalemle çizdi.

İki çember kutupta ve birinci bölgede bir noktada kesişir. İstenen, iki çemberin ortak (mercek biçimli) bölgesinin alanıdır.

**Kesişme noktası.** İki denklem eşitlenir:

$$4\cos\theta=4\sin\theta\ \Rightarrow\ \tan\theta=1\ \Rightarrow\ \theta=\frac{\pi}{4}.$$

**Bölgeyi bölmek.** Hoca bölgeyi $\theta=\pi/4$ ışınıyla ikiye ayırdı:

- $0\le\theta\le\pi/4$ arasında, kutuptan çıkan ışın önce $r=4\sin\theta$ çemberinden çıkar. Bu parçanın sınırı $r=4\sin\theta$'dır.
- $\pi/4\le\theta\le\pi/2$ arasında sınır $r=4\cos\theta$'dır.

Bu iki parçanın toplamı ortak alanı verir:

$$A=\frac12\int_0^{\pi/4}(4\sin\theta)^2\,d\theta+\frac12\int_{\pi/4}^{\pi/2}(4\cos\theta)^2\,d\theta.$$

> **Hocanın vurgusu:** Formülde $r$'nin karesi alınır. Kareyi unutmayın.

Sonuç derste söylenmedi. Hesap (ara adım eklendi):

- $\dfrac12\displaystyle\int_0^{\pi/4}16\sin^2\theta\,d\theta=8\int_0^{\pi/4}\frac{1-\cos2\theta}{2}\,d\theta=4\left[\theta-\frac{\sin2\theta}{2}\right]_0^{\pi/4}=4\left(\frac{\pi}{4}-\frac12\right)=\pi-2.$
- Simetriden ikinci parça da $\pi-2$'dir.

$$A=2(\pi-2)=2\pi-4.$$

(sympy ile doğrulandı.)

**Soru:** Kesişme noktalarının bulunmasını bir daha anlatır mısınız?
**Cevap:** $r=4\cos\theta$ ile $r=4\sin\theta$ eşitlenir. 4'ler sadeleşir, $\cos\theta=\sin\theta$ kalır. İki taraf $\cos\theta$'ya bölünürse $\tan\theta=1$, buradan açı $45°$ bulunur. Hoca bunun Matematik 1'deki fonksiyon çizimlerine benzediğini söyledi: orada da iki eğri eşitlenip kesişme noktası bulunuyordu; burada eşitleyip açıyı buluyoruz. Ardından hoca silip, neden $0$'dan $\pi/4$'e kadar $4\sin\theta$, $\pi/4$'ten $\pi/2$'ye kadar $4\cos\theta$ alındığını renkli kalemlerle tahtada tekrar gösterdi.

### 10.2 Örnek 13: $r=1$ çemberinin dışında, $r=1+\cos\theta$ kardiyoidinin içinde kalan alan

**Çizim.** $r=1$, yarıçapı 1 olan çemberdir. $r=1+\cos\theta$, uzun kısmı sağda olan kardiyoiddir. İstenen bölge, çemberin dışında ama kardiyoidin içinde kalan, sağ taraftaki bölgedir.

**Kesişme.** $1=1+\cos\theta\Rightarrow\cos\theta=0$. Hoca öğrencilere $\cos$'un sıfır olduğu açıları sordu: $\theta=\pi/2$ ve $\theta=3\pi/2$ (yani $-\pi/2$).

**Kurulum.** Bölge kutup eksenine göre simetriktir. Üstteki parça ($0\le\theta\le\pi/2$) bulunup 2 ile çarpılır. Üstteki parçanın alanı, kardiyoidin bu aralıktaki alanından çemberin bu aralıktaki alanının çıkarılmasıyla bulunur:

$$A=2\cdot\frac12\int_0^{\pi/2}\left[(1+\cos\theta)^2-1^2\right]d\theta.$$

Burada bir öğrenci yay uzunluğu formülüyle karıştırınca hoca durdu ve hatırlattı: "Bu yay uzunluğu değil. Alan nedir? $\tfrac12\int r^2\,d\theta$."

Sonuç slaytta yazılıydı, altyazıda okunmadı. Hesap (ara adım eklendi):

$$A=\int_0^{\pi/2}\left(2\cos\theta+\cos^2\theta\right)d\theta=2\left[\sin\theta\right]_0^{\pi/2}+\frac{\pi}{4}=2+\frac{\pi}{4}.$$

(sympy ile doğrulandı.)

### 10.3 Gül eğrisi alanı (slayt)

Slaytta bir de $r=\sin3\theta$ eğrisinin sınırladığı bölgenin alanını isteyen bir soru vardı. Hoca bu tip eğrilerin "gül" şekli olduğunu, $\sin3\theta$, $\cos3\theta$ gibi eğrilerin pratik çizimlerinin notlarda bulunduğunu söyledi. Çözüm altyazıda anlaşılmıyor. <!-- BELİRSİZ: 01:57:51-01:58:35; sorunun tam metni ("4 denkli bir esna bölgenin alanı") ve çözüm altyazıdan okunmuyor. -->

## 11. Kutupsal Koordinatlarda Yay Uzunluğu

**Tanım kutusu: Yay uzunluğu formülleri**

- Kutupsal: $r=f(\theta)$ eğrisinin $\theta=\alpha$'dan $\theta=\beta$'ya kadarki yay uzunluğu

$$L=\int_\alpha^\beta\sqrt{r^2+\left(\frac{dr}{d\theta}\right)^2}\,d\theta.$$

- Kartezyen: $y=f(x)$ için $L=\displaystyle\int_a^b\sqrt{1+\left(f'(x)\right)^2}\,dx$.
- Parametrik: $x=x(t)$, $y=y(t)$ için $L=\displaystyle\int_{t_1}^{t_2}\sqrt{\left(\frac{dx}{dt}\right)^2+\left(\frac{dy}{dt}\right)^2}\,dt$.

Hoca yay uzunluğunu $S$ ya da $L$ ile göstermenin fark etmediğini söyledi.

### 11.1 Örnek 14: $r=1+\cos\theta$ kardiyoidinin uzunluğu

**Simetri.** Eğri çizilmişti; kutup eksenine göre simetriktir. $0$'dan $\pi$'ye kadar hesaplanıp 2 ile çarpılırsa tüm uzunluk bulunur.

**Türev.** $r'=-\sin\theta$.

**Kök içi.** (ara adım eklendi)

$$r^2+r'^2=(1+\cos\theta)^2+\sin^2\theta=1+2\cos\theta+\cos^2\theta+\sin^2\theta=2+2\cos\theta.$$

Yarım açı formülüyle $2+2\cos\theta=4\cos^2\dfrac{\theta}{2}$ olur. $0\le\theta\le\pi$ için $\cos\dfrac{\theta}{2}\ge0$ olduğundan

$$\sqrt{r^2+r'^2}=2\cos\frac{\theta}{2}.$$

<!-- BELİRSİZ: 01:51:09-01:51:33; altyazıda hoca kök içinin sonucunu "2 çarpı kosünüs teta" diye söylüyor, hemen ardından "Teta belki" geçiyor; "teta bölü iki" denmiş olabilir. -->

**Neden yarı alınır?** Hoca: "$0$'dan $2\pi$'ye yazarsak mutlak değer yazmamız lazım." Çünkü $\pi<\theta<2\pi$ için $\cos\dfrac{\theta}{2}<0$ olur ve $\sqrt{4\cos^2(\theta/2)}=2\left|\cos\dfrac{\theta}{2}\right|$ yazmak gerekir. Üst yarıyı alıp 2 ile çarpmak bu dertten kurtarır; çünkü alttaki eğri üsttekinin aynısıdır.

$$L=2\int_0^\pi2\cos\frac{\theta}{2}\,d\theta=2\left[4\sin\frac{\theta}{2}\right]_0^\pi=8.$$

Sonuç derste söylenmedi; hesap eklendi ve sympy ile doğrulandı.

### 11.2 Örnek 15: $r=\cos\theta$ çemberinin uzunluğu

Hoca slayttaki iki sorudan ($r=\cos\theta$ ve bir kardiyoid) hangisini çözeceğini sordu ve önce çemberi çözdü. <!-- BELİRSİZ: 01:51:59; altyazıda "kosür 3 teta" ve "1- kosür 3 teta" geçiyor; çözülen sorular $r=\cos\theta$ ve $r=1-\cos\theta$ olarak okundu. -->

Çember sağ yarı düzlemde olduğu için $\theta$, $-\pi/2$'den $\pi/2$'ye kadar alınır.

- $r'=-\sin\theta$.
- $r^2+r'^2=\cos^2\theta+\sin^2\theta=1$.

$$L=\int_{-\pi/2}^{\pi/2}1\,d\theta=\pi.$$

Hoca: "Bu çemberin yay uzunluğu $\pi$'ymiş." Gerçekten $r=\cos\theta$, çapı 1 olan çemberdir; çevresi $\pi\cdot1=\pi$'dir. (sympy ile doğrulandı.)

### 11.3 Örnek 16: $r=1-\cos\theta$ kardiyoidinin uzunluğu

Aynı yöntem uygulanır: $r'=\sin\theta$, $r^2+r'^2=2-2\cos\theta=4\sin^2\dfrac{\theta}{2}$ (ara adım eklendi). Hoca yine uyardı: $0$'dan $2\pi$'ye alınırsa bir kısım pozitif, bir kısım negatif çıkar ve mutlak değer gerekir. Sadece üst kısmı yapıp iki katını almak işi kolaylaştırır.

$$L=2\int_0^\pi2\sin\frac{\theta}{2}\,d\theta=8.$$

Sonuç derste sözlü verilmedi; hesap eklendi ve sympy ile doğrulandı.

### 11.4 Örnek 17: $r=1+\sin\theta$ kardiyoidinin uzunluğu

$r'=\cos\theta$, $r^2+r'^2=2+2\sin\theta$. Hoca bu kez simetri eksenini $y$ ekseni olarak aldı: $-\pi/2$'den $\pi/2$'ye kadar hesaplanırsa kardiyoidin sağ yarısının uzunluğu bulunur, 2 ile çarpılınca tamamı elde edilir.

$$L=2\int_{-\pi/2}^{\pi/2}\sqrt{2+2\sin\theta}\,d\theta=8.$$

Sonuç derste sözlü verilmedi; sayısal integral ile sympy'de 8 bulundu.

## 12. Hocanın Kendi Sorusu: Çemberin Dışında, Kardiyoidin İçinde

Dersin sonunda hoca öğrencilere "Soruyu siz söyleyin" diyerek bir soru kurdu.

**Soru:** $r=2$ çemberinin dışında ve $r=2(1+\cos\theta)$ kardiyoidinin içinde kalan bölgenin (a) yay uzunluğu ve (b) alanı nedir?

**Çizim.** $r=2$, yarıçapı 2 olan çemberdir. Kardiyoid için:

- $\theta=0$: $\cos0=1$, $r=2\cdot2=4$.
- $\theta=\pi/2$: $\cos=0$, $r=2$.
- $\theta=\pi$: $\cos\pi=-1$, $r=0$.
- $\theta=-\pi/2$: $r=2$.

| $\theta$ | $0$ | $\pi/2$ | $\pi$ | $3\pi/2$ |
|---|---|---|---|---|
| $r$ | $4$ | $2$ | $0$ | $2$ |

İstenen bölge, çember ile kardiyoid arasında, sağ tarafta kalan bölgedir.

**Kesişme.** $2=2+2\cos\theta\Rightarrow2\cos\theta=0\Rightarrow\cos\theta=0$. Buradan $\theta=\pi/2$ ve $\theta=-\pi/2$ (ya da $3\pi/2$, aynı yer).

**Alan.** Hoca: "Üsttekinin alanını hesaplarsam, 2 ile çarpacağım için $\tfrac12$ gidiyor."

$$A=2\cdot\frac12\int_0^{\pi/2}\left[\left(2(1+\cos\theta)\right)^2-2^2\right]d\theta=\int_0^{\pi/2}\left[4(1+\cos\theta)^2-4\right]d\theta.$$

Hoca integrali kurdu, hesabı yapmadı. Tamamlanışı (ara adım eklendi):

$$A=4\int_0^{\pi/2}\left(2\cos\theta+\cos^2\theta\right)d\theta=4\left(2+\frac{\pi}{4}\right)=8+\pi.$$

(sympy ile doğrulandı.) Bu, Örnek 13'teki bölgenin 2 kat büyütülmüş halidir; alan $2^2=4$ katına çıkar.

**Yay uzunluğu.** Hoca formülü $L=\displaystyle\int_\alpha^\beta\sqrt{r^2+r'^2}\,d\theta$ olarak yazdı ve "$0$'dan $\pi/2$'ye kadar, yine üsttekini alacağız, yerine koyup işlem yapacağız" dedi. Hesap derste yapılmadı. Kardiyoid tarafındaki sınır yayı için (ara adım eklendi):

- $r=2+2\cos\theta$, $r'=-2\sin\theta$.
- $r^2+r'^2=8+8\cos\theta=16\cos^2\dfrac{\theta}{2}$.

$$L_{\text{kardiyoid}}=2\int_0^{\pi/2}4\cos\frac{\theta}{2}\,d\theta=2\left[8\sin\frac{\theta}{2}\right]_0^{\pi/2}=2\cdot4\sqrt2=8\sqrt2.$$

(sympy ile doğrulandı.)

> **Ders sonrası not:** Hoca hangi yayın uzunluğunu kastettiğini açık söylemedi; büyük olasılıkla kardiyoidin bölgeyi sınırlayan yayı ($8\sqrt2$) kastedildi. Bölgenin tüm çevresi isteniyorsa, $r=2$ çemberinin $-\pi/2\le\theta\le\pi/2$ arasındaki yayı ($2\pi$) da eklenir ve çevre $8\sqrt2+2\pi$ olur.

Hoca dersi burada bitirdi ve sonraki derste vektörlere geçileceğini söyledi.

## 13. Örnek Sorular

Bu derste video karesi yoktur; aşağıdaki sorular derste sözlü sorulan ya da hocanın sesli okuduğu sorulardır.

**Soru 1** (derste sözlü, 00:09:15): $(-3,\pi/3)$ noktası, $r=3$ alınarak hangi açıyla gösterilir?

Çözüm (derste verildi): $r$'nin işareti değişince açıya $\pi$ eklenir: $\pi+\dfrac{\pi}{3}=\dfrac{4\pi}{3}$. Yani $(-3,\pi/3)=(3,4\pi/3)$.

**Soru 2** (derste sözlü, 00:25:49): $r=2\sin\theta$ eğrisinin grafiği aşağıdakilerden hangisidir? (Hoca tahtaya beş şık çizdi; şıkların şekilleri altyazıda yok.)

Çözüm (derste verildi): Denklemde $r\sin\theta$ olsaydı yerine $y$ yazılırdı. Bunu sağlamak için iki taraf $r$ ile çarpılır:

$$r^2=2r\sin\theta\ \Rightarrow\ x^2+y^2=2y.$$

Tam kareye tamamlamak için iki tarafa 1 eklenir ($x^2+y^2-2y+1=1$):

$$x^2+(y-1)^2=1.$$

Merkezi $(0,1)$, yarıçapı 1 olan çemberdir. Bir öğrenci doğru şıkkı (E) söyledi. Hoca: "Bildikten sonra bu kadar basit."

**Soru 3** (derste sözlü, 00:51:11): $r=a(1+\cos\theta)$ eğrisinin periyodunun $2\pi$ olduğunu nasıl anlarız? $\cos3\theta$ olsaydı periyot ne olurdu?

Çözüm (derste verildi): Denklemde yalnız $\cos\theta$ vardır ve periyodu $2\pi$'dir. $\cos3\theta$'nın periyodu $\dfrac{2\pi}{3}$'tür; $\tan\theta$'nın periyodu $\pi$'dir.

**Soru 4** (ekranda gösterilen çıkmış soru, hoca sesli okudu, 01:41:40): $r=4\cos\theta$ ve $r=4\sin\theta$ eğrilerinin sınırladığı ortak alanı bulunuz.

Çözüm: Örnek 12'de. Derste integral kuruldu; sonuç $2\pi-4$.

**Soru 5** (ekranda gösterilen çıkmış soru, hoca sesli okudu, 02:01:52): $r=1$ çemberinin dışında ve $r=1+\cos\theta$ kardiyoidinin içinde kalan bölgenin alanını bulunuz.

Çözüm: Örnek 13'te. Sonuç $2+\dfrac{\pi}{4}$.

**Soru 6** (ekranda gösterilen çıkmış soru, hoca kısmen okudu, 02:00:51): Parametrik olarak verilen bir eğrinin $-1\le t\le1$ aralığındaki uzunluğunu bulunuz.

Derste verilen yol: Parametrik yay uzunluğu formülü $L=\displaystyle\int_{-1}^{1}\sqrt{\left(\dfrac{dx}{dt}\right)^2+\left(\dfrac{dy}{dt}\right)^2}\,dt$ kurulur, türevler yerine konup düzenlenir. <!-- BELİRSİZ: 02:00:51-02:01:28; eğrinin denklemi altyazıda "x eşittir t küp, y eşittir ... t kare" gibi geçiyor; tam denklem ve sonuç okunmuyor. -->

**Soru 7** (ekranda gösterilen çıkmış soru, 01:58:14): $r=\sin3\theta$ eğrisinin sınırladığı bölgenin alanını hesaplayınız.

<!-- BELİRSİZ: 01:57:51-01:58:14; sorunun tam metni altyazıda okunmuyor; "$r=\sin3\theta$ gül eğrisinin sınırladığı alan" olarak okundu. -->

> **Çözüm (derste verilmedi):** $r=\sin3\theta$ üç yapraklı bir güldür ve $0\le\theta\le\pi$ aralığında bir kez çizilir. Alan $A=\dfrac12\displaystyle\int_0^{\pi}\sin^2 3\theta\,d\theta=\dfrac{\pi}{4}$ olur (sympy ile doğrulandı). Soru metni kesin okunamadığı için bu çözüm, sorunun büyük olasılıkla bütün gülün alanını istediği varsayımına dayanır.

**Soru 8** (hocanın kurduğu soru, 02:06:13): $r=2$ çemberinin dışında, $r=2(1+\cos\theta)$ kardiyoidinin içinde kalan bölgenin yay uzunluğu ve alanı.

Çözüm: Bölüm 12'de. Alan $8+\pi$; kardiyoid yayı $8\sqrt2$.

## 14. Ders Sonrası Notlar

> **Ders sonrası not:** Hoca $r=2a\cos\theta$ için "merkezi $(a,0)$, yarıçapı $a/2$ olan çember" dedi (01:10:44). Doğrusu: $r=2a\cos\theta$ çemberinin merkezi $(a,0)$, yarıçapı $a$'dır (Örnek 6'da kendisi de böyle türetti). Merkezi $(a/2,0)$ ve yarıçapı $a/2$ olan çember $r=a\cos\theta$'dır.

> **Ders sonrası not:** Aynı şekilde $r=2a\sin\theta$ için yarıçap $a/2$ denmesi (01:11:18) hatalıdır. Doğrusu: merkezi $(0,a)$, yarıçapı $a$ olan çember.

> **Ders sonrası not:** Hoca $r=2-4\sin\theta$ için "$(0,0)$'ı kesmiyor" dedi (01:09:18). Doğrusu: $\sin\theta=\tfrac12$ iken, yani $\theta=\pi/6$ ve $\theta=5\pi/6$'da $r=0$ olur. Bu iç döngülü limaçon kutuptan iki kez geçer (sympy ile doğrulandı).

> **Ders sonrası not:** Hoca "$1+\sin\theta$ değil de $2+\sin\theta$ olsa yine kardiyoid ama içinde başka şekiller çıkıyor" dedi (00:57:14); ayrıca kardiyoid koşulunu anlatırken açının $2\theta$, $3\theta$ olmasının fark etmediğini söyledi (01:06:24). Doğrusu: $r=2+\sin\theta$ kardiyoid değildir; iç döngüsü olmayan bir limaçondur. $r=a(1+\cos2\theta)$ gibi eğriler de kardiyoid değildir; kardiyoid için açı $\theta$ olmalı ve sabit ile katsayı eşit olmalıdır.

> **Ders sonrası not:** $r=2(1+\sin\theta)$ tablosunda hoca $\theta=\pi$ değerini bir an "0" ve "eksi 1" diye karıştırdı (00:58:15), sonra düzeltti. Doğru değerler: $r(\pi)=2$, $r(3\pi/2)=0$.

> **Ders sonrası not:** $r=1+\cos\theta$ yay uzunluğunda kök içi $2+2\cos\theta$'dır; karekökü $0\le\theta\le\pi$ için $2\cos\dfrac{\theta}{2}$'dir, $2\cos\theta$ değildir. Toplam uzunluk 8'dir.

- Bu derste hocanın gösterdiği bazı integral sonuçları yalnız slaytta yazılıydı, altyazıda okunmadı. Yukarıdaki sayısal sonuçlar ($6\pi$, $\tfrac{3\pi}{2}$, $2\pi-4$, $2+\tfrac{\pi}{4}$, $8+\pi$, $8$, $\pi$, $8\sqrt2$) ders sonrası hesaplandı ve sympy ile doğrulandı.

## Dersin Toparlaması

Bu derste Kartezyen koordinatlardan kutupsal koordinatlara geçildi. Bir noktanın kutuptan yönlü uzaklık $r$ ve kutup ekseninden yönlü açı $\theta$ ile gösterildiği, aynı noktanın sonsuz sayıda gösterimi olduğu ve negatif $r$'nin ters yönü belirttiği görüldü. $x=r\cos\theta$, $y=r\sin\theta$, $x^2+y^2=r^2$ dönüşümleriyle çember, lemniskat ve kutuptan geçen çemberler iki sistem arasında çevrildi. Eşitsizliklerle verilen bölgeler, simetri kuralları ve eğri çizim adımları anlatıldı. Kardiyoidin birkaç açıyla hızlıca çizilmesi gösterildi ve kardiyoid olmayan $r=2-4\sin\theta$ ile karşılaştırıldı.

Dersin ikinci yarısında kutupsal alan formülü $A=\tfrac12\int r^2\,d\theta$ ve yay uzunluğu formülü $L=\int\sqrt{r^2+r'^2}\,d\theta$ verildi. Kardiyoid alanları, iki çemberin ortak alanı ve çemberin dışında kardiyoidin içinde kalan bölgeler çıkmış sorular üzerinden çözüldü. Her soruda önce eğrinin çizilmesi, kesişme açılarının bulunması ve simetriyle yarı aralıkta çalışılması vurgulandı. Hoca sonraki derste vektörlere geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
