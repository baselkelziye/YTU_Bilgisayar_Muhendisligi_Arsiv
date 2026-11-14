# Ders 25 Genişletilmiş Notu: Final Hazırlığı: Kutupsal Alan İntegralleri, Seri Testleri ve Kuvvet Serileri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı: Çıkmış ve Çıkabilecek Sorular
- 2. Kutupsal Denklem, Kutupsal Nokta ve Bölge Eşitsizlikleri
- 3. İki Eğri Arasında Kalan Alanı Veren İntegral
- 4. Serilerde Hatırlatmalar ve Pratik Kurallar
- 5. Seri Soruları
- 6. Kuvvet Serileri
- 7. Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Planı: Çıkmış ve Çıkabilecek Sorular

Hoca derse, konuların bittiğini ve artık final hazırlığı için soru çözüleceğini söyleyerek başladı. Plan şuydu: seriler (gerekirse tekrar), kutupsal koordinatlar, vektörler, çok değişkenli fonksiyonlar, limit, süreklilik ve türev. Bu derste çözülen sorular "çıkmış ve çıkabilecek sorular" olarak sunuldu. Hoca soruları ekranda hazır hâlde gösterdi, üzerine kalemle çizerek ve renklendirerek anlattı. Altyazıda yalnız sözlü kısım olduğu için şıkların tam metni çoğu yerde okunmuyor.

Ders üç bölümden oluştu: önce kutupsal koordinatlar ve alan integralleri, sonra seri testleri, en sonda kuvvet serileri. Arada iki mola verildi (yaklaşık 00:32-00:45 ve 01:14-01:24).

## 2. Kutupsal Denklem, Kutupsal Nokta ve Bölge Eşitsizlikleri

### 2.1 Temel dönüşümler

Kutupsal koordinatlarla (polar coordinates) kartezyen koordinatlar arasındaki bağıntılar hatırlatıldı:

$$x=r\cos\theta,\qquad y=r\sin\theta,\qquad r^2=x^2+y^2.$$

Son eşitlik, ilk ikisinin karesini alıp toplayınca elde edilir.

### 2.2 Örnek 1: Kutupsal denklem neyi belirtir?

Soru: $r=\dfrac{4}{2\cos\theta-\sin\theta}$ kutupsal denklemi için hangisi doğrudur? Şıklar: A) doğru belirtir, B) çember belirtir, C) kardiyoid (cardioid) belirtir, D) parabol belirtir.

Çözüm adımları:

- Payda karşıya çarpım olarak geçirilir: $2r\cos\theta-r\sin\theta=4$.
- $r\cos\theta$ yerine $x$, $r\sin\theta$ yerine $y$ yazılır: $2x-y=4$.
- Bu birinci dereceden bir denklemdir, yani bir doğru denklemidir. Cevap A.

Hoca diğer şıkların hangi denklem tipine karşılık geldiğini de söyledi:

- Çember: $x^2+y^2=a^2$ biçiminde olurdu.
- Kardiyoid: $r=a(1\pm\sin\theta)$ ya da $r=a(1\pm\cos\theta)$ biçiminde olurdu.
- Parabol: $y=ax^2+\dots$ biçiminde olurdu.

### 2.3 Kutupsal bölge şıkları

Hoca ardından, şıklarda kutupsal bölgelerin eşitsizliklerle verildiği bir soruya geçti. Şıklardan birinde $\frac\pi4\le\theta\le\frac{3\pi}4$, $0\le r\le1$ gibi bir bölge, bir başkasında $1\le r\le2$ aralığı geçiyor. Hoca bir şık için "yanlış, fazlalık vermiş" dedi.

<!-- BELİRSİZ: 00:04:51-00:06:18 arası şıkların tam metni altyazıda okunmuyor ("teta 2pi bölü 3, r eksi b'den büyük, sonsuza gidiyor" gibi bozuk ifadeler var). Hangi şıkkın doğru olduğu anlaşılmıyor. -->

### 2.4 Örnek 2: Kutupsal noktanın kartezyen koordinatı

Soru: $(r,\theta)=\left(-3,\frac{5\pi}{6}\right)$ noktasının kartezyen koordinatı nedir?

- Birinci bileşen $r$, ikinci bileşen $\theta$'dır. $r=-3$, $\theta=\frac{5\pi}6$.
- $\frac\pi6=30^\circ$ olduğundan $\frac{5\pi}6=150^\circ$. Bu açı ikinci bölgededir ve referans açısı $30^\circ$'dir.
- İkinci bölgede kosinüs negatiftir: $\cos150^\circ=-\cos30^\circ=-\frac{\sqrt3}2$.
- İkinci bölgede sinüs pozitiftir: $\sin150^\circ=\sin30^\circ=\frac12$.
- $x=r\cos\theta=(-3)\left(-\frac{\sqrt3}2\right)=\frac{3\sqrt3}2$.
- $y=r\sin\theta=(-3)\cdot\frac12=-\frac32$.
- Nokta: $\left(\frac{3\sqrt3}2,-\frac32\right)$.

Hoca şıklarda $y=+\frac32$ veren bir çeldirici olduğunu gösterdi.

> **Hocanın vurgusu:** Doğru ile yanlış arasında ufak bir nüans var. Bunu fark etmek için çözmek lazım, bol bol çözmek.

> **Ders sonrası not:** Altyazıda $y$ hesaplanırken ifade karışıyor ("X'i 3 bölge 2" gibi). Doğru sonuç $y=-\frac32$'dir; $+\frac32$ olan şık çeldiricidir. Sonuç sympy ile doğrulandı.

### 2.5 Örnek 3: Bölge eşitsizliğinde sınırın dahil olup olmaması

Kutupsal bölüm bitmeden (01:01:13) hoca bir sınav sorusuna daha döndü. Hocaya göre birçok öğrenci bu soruya çok yaklaşmış ama bir hata yapmış. Şıklarda $-\frac\pi3\le\theta\le-\frac\pi6$ (yani $-60^\circ$ ile $-30^\circ$ arası) ve $r$ için $-3$ ile $2$ arası bir aralık var. A şıkkı ile bir başka şık arasındaki tek fark, $r=2$ sınırının dahil olup olmamasıdır.

**Soru:** A şıkkı ile diğer şık arasındaki fark nedir? **Cevap (bir öğrenci):** Küçük eşittir olmadığı için çizgiler alınmayacak. Hoca cevabı onayladı: şekilde $r=2$ sınırı kesikli çizilmiş, yani 2 dahil değil. Doğru şık $r<2$ olandır. Şıkları hızlı okuyup "balıklama atlayan" doğru cevabı kaçırır.

<!-- BELİRSİZ: Şıklardaki $r$ alt sınırının tam biçimi ($-3\le r$ mi, başka bir şey mi) altyazıda net değil. -->

## 3. İki Eğri Arasında Kalan Alanı Veren İntegral

### 3.1 Genel yöntem

**Kutupsal alan formülü**

- $\theta=\alpha$ ile $\theta=\beta$ arasında $r=f(\theta)$ eğrisinin süpürdüğü alan: $A=\dfrac12\displaystyle\int_\alpha^\beta r^2\,d\theta$.
- İki eğri arasında kalan alan: $A=\dfrac12\displaystyle\int_\alpha^\beta\left(r_{\text{dış}}^2-r_{\text{iç}}^2\right)d\theta$.

Hoca bu bölümdeki bütün sorularda aynı sırayı izledi:

- Eğrileri tanı ve çiz (çember, kardiyoid, doğru).
- Eğrileri birbirine eşitle, kesim açısını bul.
- Bölge simetrikse yarısını hesapla: $\frac A2=\frac12\int\dots$ yaz. Sonra 2'yi karşıya geçir; $\frac12$ ile 2 sadeleşir.
- Gerekirse "fazla alanı al, fazlalığı çıkar" yöntemiyle iki integral yaz.

> **Hocanın vurgusu:** Bu sorularda genellikle "integrali hesaplayınız" denmiyor, "alanı veren integral aşağıdakilerden hangisidir" deniyor. Sınırları ve hangi eğrinin dışta olduğunu doğru yazmak yeterli. Formüldeki $\frac12$'yi unutmayın. Herkes sınırları bilmeli.

Derste integrallerin değeri hesaplanmadı. Aşağıdaki sayısal değerler ders sonrasında sympy ile hesaplandı ve "doğrulama" diye ayrıca belirtildi.

### 3.2 Örnek 4: $r=2\cos\theta$ içinde, $r=\sqrt2$ dışında

Ekranda $r=2\cos\theta$ mavi, $r=\sqrt2$ (yarıçapı $\sqrt2$ olan merkezil çember) kırmızı çizilmişti. İstenen alan, mavi çemberin içinde, kırmızı çemberin dışında kalan, $x$ ekseninin altında ve üstünde iki parçadan oluşan bölgedir.

- Kesişim: $2\cos\theta=\sqrt2\Rightarrow\cos\theta=\frac{\sqrt2}2\Rightarrow\theta=\frac\pi4$.
- Bölge $x$ eksenine göre simetrik. Üst yarıda $0\le\theta\le\frac\pi4$ aralığında dıştaki eğri $2\cos\theta$, içteki $\sqrt2$'dir.
- Hoca önce mavinin içindeki toplam alanı ($(2\cos\theta)^2$), sonra kırmızının içindeki kısmı ($(\sqrt2)^2$) yazdı ve çıkardı:

$$\frac A2=\frac12\int_0^{\pi/4}\left[(2\cos\theta)^2-(\sqrt2)^2\right]d\theta=\frac12\int_0^{\pi/4}\left(4\cos^2\theta-2\right)d\theta.$$

- 2 karşıya geçince: $A=\displaystyle\int_0^{\pi/4}\left(4\cos^2\theta-2\right)d\theta$.

Doğrulama: $4\cos^2\theta-2=2\cos2\theta$ olduğundan $A=\left[\sin2\theta\right]_0^{\pi/4}=1$.

### 3.3 Örnek 5: $r=2\cos\theta$ dışında, $r=\sqrt2$ içinde

Bu kez mavinin dışı, kırmızının içi isteniyor. Hoca üst yarıyı şöyle kurdu:

- $\frac\pi4$'ten $\pi$'ye kadar $r=\sqrt2$ çemberinin süpürdüğü alanı al. Bu, mavi çemberin bir parçasını da içerir.
- Mavi parçayı çıkar: $\frac\pi4$'ten $\frac\pi2$'ye kadar $r=2\cos\theta$ ile süpürülen alan.

$$\frac A2=\frac12\int_{\pi/4}^{\pi}(\sqrt2)^2\,d\theta-\frac12\int_{\pi/4}^{\pi/2}(2\cos\theta)^2\,d\theta.$$

- 2 karşıya geçince: $A=\displaystyle\int_{\pi/4}^{\pi}2\,d\theta-\int_{\pi/4}^{\pi/2}4\cos^2\theta\,d\theta$.

Hoca bunun "çok güzel bir soru" olduğunu söyledi. Doğrulama: $\frac{3\pi}2-\left(\frac\pi2-1\right)=\pi+1$.

### 3.4 Kardiyoid çizimi

Bir sonraki soruda $r=1+\cos\theta$ kardiyoidi geçtiği için hoca önce onu tablo yaparak çizdi. Çizerken bir noktayı yanlış koydu, silip düzeltti.

| $\theta$ | $0$ | $\pi/2$ | $\pi$ | $3\pi/2$ |
|---|---|---|---|---|
| $\cos\theta$ | $1$ | $0$ | $-1$ | $0$ |
| $r=1+\cos\theta$ | $2$ | $1$ | $0$ | $1$ |

Kardiyoid $x$ eksenini sağda $r=2$'de keser, $y$ eksenini $r=1$'de keser, $\theta=\pi$'de orijinden geçer. Hoca $r=3\cos\theta$'nın $x$ ekseni üzerinde merkezli bir çember olduğunu, $r=3\sin\theta$ olsaydı çemberin $y$ ekseni üzerinde olacağını da söyledi.

> **Ek bilgi (derste anlatılmadı):** Genel olarak $r=2a\cos\theta$ merkezi $(a,0)$, yarıçapı $|a|$ olan çemberdir; $r=2a\sin\theta$ merkezi $(0,a)$ olan çemberdir. Bu, $r^2=2ar\cos\theta$ yazıp $x^2+y^2=2ax$ elde ederek görülür.

### 3.5 Örnek 6: $r=3\cos\theta$ içinde, $r=1+\cos\theta$ dışında

- Kesişim: $3\cos\theta=1+\cos\theta\Rightarrow\cos\theta=\frac12\Rightarrow\theta=\frac\pi3$ ($60^\circ$).
- Bölge $x$ eksenine göre simetrik. Üst yarıda $0\le\theta\le\frac\pi3$ aralığında çember dışta, kardiyoid içtedir.
- Hoca önce "siyah ve turuncu" toplam alanı ($3\cos\theta$ çemberi), sonra turuncu alanı (kardiyoid) yazdı:

$$\frac A2=\frac12\int_0^{\pi/3}(3\cos\theta)^2\,d\theta-\frac12\int_0^{\pi/3}(1+\cos\theta)^2\,d\theta.$$

- Sınırlar aynı olduğu için tek integralde birleşir:

$$A=\int_0^{\pi/3}\left[9\cos^2\theta-(1+\cos\theta)^2\right]d\theta.$$

Hoca şıklarda integrandın iki kare farkı olarak düzenlenmiş hâlinin de çıkabileceğini söyledi: $(3\cos\theta-1-\cos\theta)(3\cos\theta+1+\cos\theta)=(2\cos\theta-1)(4\cos\theta+1)$ (ara adım eklendi).

Doğrulama: $A=\pi$.

### 3.6 Örnek 7: $r=3\cos\theta$ dışında, $r=1+\cos\theta$ içinde

Hoca bunun bir sınav sorusu olduğunu, önceki sorunun "tam tersi" olduğunu söyledi.

- Kesim açısı yine $\frac\pi3$.
- Üst yarıda $\frac\pi3$'ten $\pi$'ye kadar kardiyoidin süpürdüğü alan alınır. Bu alan, $\frac\pi3$ ile $\frac\pi2$ arasında çemberin bir parçasını (mavi alan) da içerir.
- Mavi alan çıkarılır: $\frac\pi3$'ten $\frac\pi2$'ye kadar $(3\cos\theta)^2$.

$$\frac A2=\frac12\int_{\pi/3}^{\pi}(1+\cos\theta)^2\,d\theta-\frac12\int_{\pi/3}^{\pi/2}9\cos^2\theta\,d\theta.$$

- 2 karşıya geçer, $\frac12$ ile sadeleşir:

$$A=\int_{\pi/3}^{\pi}(1+\cos\theta)^2\,d\theta-\int_{\pi/3}^{\pi/2}9\cos^2\theta\,d\theta.$$

Doğrulama: $A=\frac\pi4$.

> **Hocanın vurgusu:** Ne kadar çok soru çözerseniz sınavda karşılaştığınızda yapma olasılığınız o kadar artar.

### 3.7 Örnek 8: $r=1-\sin\theta$ içinde, $r=\sin\theta$ dışında

Hoca önce $r=1-\sin\theta$ kardiyoidini çizdi:

| $\theta$ | $0$ | $\pi/2$ | $\pi$ | $-\pi/2$ |
|---|---|---|---|---|
| $r=1-\sin\theta$ | $1$ | $0$ | $1$ | $2$ |

Kardiyoid $y$ ekseninin altına doğru açılır, $\theta=\frac\pi2$'de orijinden geçer. $r=\sin\theta$ ise $y$ ekseninin üst tarafında, orijinden geçen küçük bir çemberdir.

- Kesişim: $1-\sin\theta=\sin\theta\Rightarrow\sin\theta=\frac12\Rightarrow\theta=\frac\pi6$ (sol tarafta $\frac{5\pi}6$).
- Bölge $y$ eksenine göre simetrik. Hoca sağ yarıyı hesaplayıp 2 ile çarptı.
- Sağ yarıda kardiyoid $-\frac\pi2$'den $\frac\pi6$'ya kadar taranır. Bunun içindeki çember parçası ("mor kısım", $0$ ile $\frac\pi6$ arası) çıkarılır.

$$\frac A2=\frac12\int_{-\pi/2}^{\pi/6}(1-\sin\theta)^2\,d\theta-\frac12\int_0^{\pi/6}\sin^2\theta\,d\theta.$$

$$A=\int_{-\pi/2}^{\pi/6}(1-\sin\theta)^2\,d\theta-\int_0^{\pi/6}\sin^2\theta\,d\theta.$$

> **Hocanın vurgusu:** Soru "çözünüz" demiyor, "veren integral hangisidir" diyor. Sadece integrali bulmanız isteniyor.

Doğrulama: $A=\frac{11\pi}{12}+\sqrt3$.

### 3.8 Örnek 9: $r=1-\sin\theta$ dışında, $r=\sin\theta$ içinde

Bu, önceki sorunun tersidir. Altyazıda eğriler "1-3 seta" ve "3 seta" diye geçiyor; hocanın iki kare farkı açıklaması ($\sin\theta$ ile $1-\sin\theta$) bunların $r=1-\sin\theta$ ve $r=\sin\theta$ olduğunu gösteriyor.

- Kesim açısı $\frac\pi6$.
- Sağ yarıda $\frac\pi6\le\theta\le\frac\pi2$ aralığında çember dışta, kardiyoid içtedir.

$$\frac A2=\frac12\int_{\pi/6}^{\pi/2}\sin^2\theta\,d\theta-\frac12\int_{\pi/6}^{\pi/2}(1-\sin\theta)^2\,d\theta.$$

- Sınırlar aynı, birleşir: $A=\displaystyle\int_{\pi/6}^{\pi/2}\left[\sin^2\theta-(1-\sin\theta)^2\right]d\theta$.
- Hoca şıklarda düzenlenmiş hâlin çıkabileceğini gösterdi. İki kare farkı:

$$\sin^2\theta-(1-\sin\theta)^2=\big(\sin\theta-(1-\sin\theta)\big)\big(\sin\theta+(1-\sin\theta)\big)=(2\sin\theta-1)\cdot1.$$

- Yani $A=\displaystyle\int_{\pi/6}^{\pi/2}(2\sin\theta-1)\,d\theta$.

Doğrulama: $A=\sqrt3-\frac\pi3$.

> **Hocanın vurgusu:** Sınırlara dikkat edin, sınırlar önemli. Şıklarda integralin kendisi değil, düzenlenmiş hâli de olabilir.

### 3.9 Örnek 10: $r=1-\sin\theta$ ve $r=\sin\theta$ eğrilerinin ortak alanı

Moladan sonra hoca aynı iki eğrinin ortak alanını sordu. Ortak bölge, hem mor çemberin hem sarı kardiyoidin içinde kalan kısımdır.

- $0\le\theta\le\frac\pi6$: çember ($\sin\theta$) içte kalır, ortak bölgenin sınırı çemberdir (mor kısım).
- $\frac\pi6\le\theta\le\frac\pi2$: kardiyoid ($1-\sin\theta$) içte kalır (sarı kısım).
- Sağ yarıyı alıp iki katını alırız:

$$\frac A2=\frac12\int_0^{\pi/6}\sin^2\theta\,d\theta+\frac12\int_{\pi/6}^{\pi/2}(1-\sin\theta)^2\,d\theta.$$

Doğrulama: $A=\frac{7\pi}{12}-\sqrt3$.

### 3.10 Örnek 11: $r=1$ ve $r=1-\cos\theta$

$r=1$ yarıçapı 1 olan merkezil çemberdir. Kardiyoid $r=1-\cos\theta$: $\theta=0$'da $r=0$, $\theta=\frac\pi2$'de $r=1$, $\theta=\pi$'de $r=2$. Kesim açısı $\frac\pi2$'dir. Bölgeler $x$ eksenine göre simetrik olduğu için hep üst yarı hesaplanıp 2 ile çarpıldı. Hoca aynı şekil üzerinde üç soru sordu.

**(a) Ortak alan.** $0\le\theta\le\frac\pi2$ arasında kardiyoid içtedir (kırmızı), $\frac\pi2\le\theta\le\pi$ arasında çember içtedir (mavi):

$$A=\int_0^{\pi/2}(1-\cos\theta)^2\,d\theta+\int_{\pi/2}^{\pi}1^2\,d\theta.$$

Doğrulama: $\frac{5\pi}4-2$.

**(b) $r=1$ içinde, kardiyoid dışında.** Yalnız mavi kısım isteniyor. Önce $0$'dan $\frac\pi2$'ye çeyrek çember alınır (mavi + kırmızı), sonra kardiyoid kısmı (kırmızı) çıkarılır:

$$A=\int_0^{\pi/2}\left[1-(1-\cos\theta)^2\right]d\theta.$$

Doğrulama: $2-\frac\pi4$.

**(c) $r=1$ dışında, kardiyoid içinde.** $\frac\pi2$'den $\pi$'ye kardiyoid alınır, aynı aralıktaki çember parçası çıkarılır:

$$A=\int_{\pi/2}^{\pi}\left[(1-\cos\theta)^2-1\right]d\theta.$$

Doğrulama: $2+\frac\pi4$.

> **Hocanın vurgusu:** Bu tip sorulardan soru kaçmaması gerekiyor. Yapa yapa anlamış ve kavramış olursunuz.

### 3.11 Örnek 12: $r=4$, $\theta=\frac\pi2$ ve $r=2\sec\theta$ arasında kalan alan (sınavda çıkmış)

Hoca bunun sınavda çıkmış bir soru olduğunu, "şekli çiziniz" ya da "bölge hangisidir" diye de sorulabileceğini söyledi.

- $r=4$: yarıçapı 4 olan merkezil çember (mavi).
- $\theta=\frac\pi2$: $y$ ekseni doğrusu.
- $r=2\sec\theta=\frac{2}{\cos\theta}\Rightarrow r\cos\theta=2\Rightarrow x=2$ doğrusu.
- Kesişim: $2\sec\theta=4\Rightarrow\cos\theta=\frac12\Rightarrow\theta=\frac\pi3$.
- Üst parçada $0\le\theta\le\frac\pi3$ arasında sınır $x=2$ doğrusudur (turuncu), $\frac\pi3\le\theta\le\frac\pi2$ arasında sınır çemberdir (mavi).

$$\frac A2=\frac12\int_0^{\pi/3}(2\sec\theta)^2\,d\theta+\frac12\int_{\pi/3}^{\pi/2}4^2\,d\theta.$$

- 2 karşıya geçer: $A=\displaystyle\int_0^{\pi/3}4\sec^2\theta\,d\theta+\int_{\pi/3}^{\pi/2}16\,d\theta$.

Doğrulama: Üst parçanın alanı $\frac A2=2\sqrt3+\frac{4\pi}3$. Bu, $0\le x\le2$ şeridinin çemberin üst yarısındaki kısmıdır; kartezyen olarak $\int_0^2\sqrt{16-x^2}\,dx$ ile aynı sonucu verir.

### 3.12 Örnek 13: $r=2\sin\theta$ dışında, $r=\sqrt2$ içinde

Hoca önce aynı eğrilerin ortak alanı sorusunu gösterdi ("mavi ve pembenin iki katı"), ama "yeterince çözdük" diyerek onun integralini yazmadı. Sonra dış-iç sorusunu çözdü.

- $r=2\sin\theta$: $y$ ekseni üzerinde merkezli çember (mor/kırmızı). $r=\sqrt2$: merkezil çember (mavi).
- Kesişim: $2\sin\theta=\sqrt2\Rightarrow\theta=\frac\pi4$.
- Bölge $y$ eksenine göre simetrik. Sağ yarıda $-\frac\pi2$'den $\frac\pi4$'e kadar $\sqrt2$ çemberi alınır (mavi + pembe), sonra $0$'dan $\frac\pi4$'e $2\sin\theta$ ile taranan pembe kısım çıkarılır:

$$\frac A2=\frac12\int_{-\pi/2}^{\pi/4}(\sqrt2)^2\,d\theta-\frac12\int_0^{\pi/4}(2\sin\theta)^2\,d\theta.$$

$$A=\int_{-\pi/2}^{\pi/4}2\,d\theta-\int_0^{\pi/4}4\sin^2\theta\,d\theta.$$

Doğrulama: $A=\pi+1$.

Hoca bu bölümün sonunda tamamlayıcı açıların trigonometrik değerlerini (bir açının sinüsünün tümleyeninin kosinüsüne, tanjantının tümleyeninin kotanjantına eşit olması) tekrar amacıyla ekranda gösterdi.

## 4. Serilerde Hatırlatmalar ve Pratik Kurallar

### 4.1 Geometrik seri ve $p$-serisi

**Geometrik seri**

- $\sum ar^{n-1}$ biçimindedir; $r$ ortak çarpandır.
- $|r|<1$ ise yakınsak (convergent), toplamı $\dfrac{a}{1-r}$ ($a$: ilk terim).
- $|r|\ge1$ ise ıraksak (divergent).

**$p$-serisi**

- $\sum\dfrac1{n^p}$: $p>1$ ise yakınsak, $p\le1$ ise ıraksak.

Hoca daha genel bir biçimin de aynı kurala uyduğunu söyledi ($a$ herhangi bir sayı).

<!-- BELİRSİZ: 01:04:51'deki genel biçim altyazıda "en üzeri P artı A" diye geçiyor; $\frac1{n^p+a}$ mı $\frac1{(n+a)^p}$ mi olduğu anlaşılmıyor. -->

### 4.2 Rasyonel genel terimli seriler için pratik kural

Hoca, testleri bilerek ama uygulamadan, yalnız $n$'in kuvvetlerini içeren kesirli genel terimli serilerin karakterini hızlıca belirlemek için bir kural verdi. Genel terim $a_n=\frac{P(n)}{Q(n)}$ olsun.

- Paydanın derecesi paydan **2 veya daha fazla** büyükse seri yakınsaktır.
- Paydanın derecesi paydan **1** büyükse seri ıraksaktır.
- Dereceler **eşitse** seri ıraksaktır (genel terimin limiti sıfırdan farklıdır).
- Payın derecesi büyükse genel terim sonsuza gider, seri ıraksaktır.

Kuralın gerekçesi limit karşılaştırma testidir (limit comparison test):

**Limit karşılaştırma testi**

- $a_n,b_n>0$ ve $\lim\limits_{n\to\infty}\dfrac{a_n}{b_n}=L$ olsun.
- $0<L<\infty$ ise $\sum a_n$ ile $\sum b_n$ aynı karakterdedir.
- $b_n$ olarak karakterini bildiğimiz uygun bir $\frac1{n^p}$ seçilir.

**Genel terim testi**

- $\lim\limits_{n\to\infty}a_n\neq0$ ise $\sum a_n$ ıraksaktır.

Hoca kuralı örneklerle gösterdi:

- Pay ve paydası ikinci dereceden bir terim: limit sıfırdan farklı bir sayı (altyazıda "bir bölü üç" gibi geçiyor), seri ıraksak.
- $\sum\frac{n+1}{n+9}$: pay ve payda birinci dereceden, limit 1, seri ıraksak.
- Payında $\sqrt{n^2+3n+1}$, paydası dördüncü dereceden olan terim: kök dışına $n$ çıkar, pay birinci dereceden olur. Fark 3'tür. $b_n=\frac1{n^3}$ ile limit karşılaştırma yapılır, limit sıfırdan ve sonsuzdan farklı bir sayıdır. $p=3>1$ olduğu için seri yakınsaktır. Paydada $n^3$ yerine $n^2$ olsaydı da sonuç aynıydı; $n$ olursa değişir.
- Payı $n^3$, paydası dördüncü dereceden olan terim: $\frac1n$ ile karşılaştırılır, harmonik seri ıraksak olduğundan seri ıraksaktır.

> **Hocanın vurgusu:** Genel terimin limiti sıfırdan farklıysa seri hemen ıraksaktır. Bu, sorularda takıldığınızda "olmazsa olmaz" bir kontroldür.

> **Ders sonrası not:** 01:05:45'te hoca kuralı önce "payın derecesi paydanınkinden küçükse seri yakınsak" diye söyledi. Bu eksiktir; doğru kural, hocanın ardından verdiği gibi derece farkının en az 2 olmasıdır. Fark 1 ise seri ıraksaktır.

### 4.3 Alterne seriler

Ardışık terimleri zıt işaretli olan serilere alterne seri (alternating series) denir. Hoca şu kuralı verdi:

**$\sum(-1)^n\frac1{n^p}$ serisi**

- $p>1$ ise mutlak yakınsaktır (absolutely convergent).
- $0<p\le1$ ise şartlı yakınsaktır (conditionally convergent).

Örnekler:

- $\sum(-1)^n\frac1{\sqrt n}$: $p=\frac12$, $0$ ile $1$ arasında, şartlı yakınsak.
- $\sum(-1)^n\frac1{n^2}$: $p=2>1$, mutlak yakınsak.
- $\sum(-1)^n\frac1n$: $p=1$, şartlı yakınsak.

> **Ek bilgi (derste anlatılmadı):** $\sum|a_n|$ yakınsaksa seri mutlak yakınsaktır. $\sum a_n$ yakınsak ama $\sum|a_n|$ ıraksaksa seri şartlı yakınsaktır. $p\le1$ durumunda $\sum\frac1{n^p}$ ıraksak, ama alterne seri testi (Leibniz) $\sum(-1)^n\frac1{n^p}$'nin yakınsadığını gösterir; şartlı yakınsaklık buradan gelir.

## 5. Seri Soruları

### 5.1 Örnek 14: $\sum\pi^{-n}\cos n\pi$ serisinin toplamı

- $\cos n\pi$ terimleri $-1,+1,-1,\dots$ diye gider: $\cos n\pi=(-1)^n$.
- $\pi^{-n}=\frac1{\pi^n}$; negatif üs paydaya geçer.
- Genel terim: $\dfrac{(-1)^n}{\pi^n}=\left(-\dfrac1\pi\right)^n$.
- Bu, ortak çarpanı $r=-\frac1\pi$ olan geometrik seridir. $\pi\approx3{,}14$ olduğundan $|r|<1$, seri yakınsaktır.
- Toplam $\frac{a}{1-r}$ formülüyle bulunur. Hoca sonucu $\dfrac{\pi}{1+\pi}$ (A şıkkı) olarak verdi.

> **Ders sonrası not:** $\frac{\pi}{1+\pi}=\frac{1}{1-(-1/\pi)}$ değeri, seri $n=0$'dan başlıyorsa (ilk terim 1) doğrudur. Seri $n=1$'den başlıyorsa ilk terim $-\frac1\pi$ olur ve toplam $\frac{-1/\pi}{1+1/\pi}=-\frac1{1+\pi}$ çıkar. Toplamanın başlangıç indisi altyazıda geçmiyor. İki değer de sympy ile doğrulandı.

### 5.2 Dizi limiti ve $e$'ye giden ifadeler

Hoca bir $a_n$ dizisi için hangi ifadenin doğru olduğunu sordu. Dizinin limiti bir sayı ($e^{-1}$) çıktığı için dizi yakınsaktır. Bu tip limitlerde ifade, bilinen şu limite benzetilerek dönüştürülür:

$$\lim_{n\to\infty}\left(1+\frac1n\right)^n=e,\qquad\lim_{n\to\infty}\left(1+\frac2n\right)^n=e^2.$$

<!-- BELİRSİZ: Dizinin kendisi altyazıda geçmiyor. 01:27:22'de "şurada 3 olsaydı e üzeri 6" deniyor; $\left(1+\frac3n\right)^n$ için limit $e^3$'tür, ekrandaki ifadede ek bir üs olabilir. -->

Hoca ardından teleskopik serileri (telescoping series) hatırlattı: genel terim iki ifadenin farkı olarak yazılır, kısmi toplamlarda terimler birbirini götürür.

### 5.3 Örnek 15: Kaç tanesi yakınsak?

Hoca az önce verdiği pratik kuralları kullandı:

- $\sum\frac1{n^{3/2}}$: $p=\frac32>1$, yakınsak.
- $\sum\left(\frac23\right)^n$: ortak çarpanı $\frac23<1$ olan geometrik seri, yakınsak.
- $\sum\frac1{\sqrt n}$: $p=\frac12$, ıraksak.
- $\sum\frac{2^n}{n^2}$: genel terim sonsuza gider, ıraksak.
- Paydasında $n^5$ olan rasyonel terim: $\frac1{n^5}$ ile limit karşılaştırma, yakınsak.
- Harmonik seri ile karşılaştırılan terim: ıraksak.
- Cevap: 3 tane yakınsak (B şıkkı).

### 5.4 Örnek 16: Verilen seriyle aynı karakterde olanlar

Referans seri $\sum\frac1{n^{2/3}}$ gibi geçiyor: $p=\frac23<1$, $p$-testinden ıraksak. Şıklardaki seriler:

- $\frac1{n^{1/2}}$ biçimli seri: ıraksak (aynı karakter).
- $\frac{4}{2^n}$ biçimli seri: geometrik, yakınsak.
- $2^n$ içeren seri: genel terim sonsuza gider, ıraksak.
- Bir seri karşılaştırma ile yakınsak çıkıyor.
- Hoca sonunda "yakınsak ile ıraksağın toplamı ıraksaktır" kuralını da kullandı ve cevabı "3 tanesi ıraksak, aynı karakterde" diyerek C olarak verdi.

<!-- BELİRSİZ: 01:30:44-01:32:58 arası şıkların tam ifadeleri altyazıda okunmuyor ("Ankara'ya mukaised" gibi bozuk yerler var). -->

### 5.5 Örnek 17: $\sum\dfrac{2+\sin n^2}{1+n^2}$

- Sinüs $[-1,1]$ aralığındadır, pay en fazla 3 olur.
- Seri $\frac1{n^2}$ (ya da $\frac3{n^2}$) ile karşılaştırılır. $\sum\frac1{n^2}$ yakınsak ($p=2$), dolayısıyla verilen seri de yakınsaktır.

<!-- BELİRSİZ: Paydaki ifadenin $\sin(n^2)$ mi $\sin^2 n$ mi olduğu altyazıdan ayırt edilemiyor; ikisi de sınırlı olduğu için sonuç değişmez. -->

### 5.6 Örnek 18: $\sum\dfrac{5\cdot4^n+7^n\cos n\pi}{7^n\cdot4^{n+1}}$

- $\cos n\pi=(-1)^n$ yazılır.
- Seri iki geometrik seriye ayrılır:

$$\frac{5\cdot4^n}{7^n\cdot4^{n+1}}+\frac{7^n(-1)^n}{7^n\cdot4^{n+1}}=\frac{5}{4}\cdot\frac1{7^n}+\frac{(-1)^n}{4^{n+1}}.$$

- Her birinin ilk terimi ve ortak çarpanı bellidir, $\frac{a}{1-r}$ formülü uygulanır (ara adım eklendi, $n=1$'den başladığı varsayılarak):
  - $\sum_{n\ge1}\frac54\cdot\frac1{7^n}=\frac54\cdot\frac{1/7}{1-1/7}=\frac54\cdot\frac16=\frac5{24}$.
  - $\sum_{n\ge1}\frac{(-1)^n}{4^{n+1}}$: ilk terim $-\frac1{16}$, oran $-\frac14$; toplam $\frac{-1/16}{1+1/4}=-\frac1{20}$.
  - Sonuç: $\frac5{24}-\frac1{20}=\frac{25-6}{120}=\frac{19}{120}$.

> **Hocanın vurgusu:** Finalde gelecek sorular için işlem hızı, işlem doğruluğu ve işlem pratikliği gerekiyor.

> **Ders sonrası not:** Altyazıda sonuç "9 bölü 120" diye geçiyor. Seri $n=1$'den başlıyorsa doğru sonuç $\frac{19}{120}$'dir (büyük olasılıkla altyazı "19"u eksik yazmıştır). $n=0$'dan başlıyorsa toplam $\frac{199}{120}$ olur. İki değer de sympy ile doğrulandı.

### 5.7 Örnek 19: $\sum\dfrac1{(\ln2)^n}$

- Ortak çarpanı $r=\frac1{\ln2}$ olan geometrik seri.
- $\ln2<1$ olduğundan $r>1$ ($\approx1{,}44$). Seri ıraksaktır.

### 5.8 Örnek 20: $\sum\dfrac{2n+1}{3+4n}$ ile aynı karakterde olan seri

- Pay ve payda birinci dereceden; limit $\frac24=\frac12\neq0$. Seri ıraksaktır.
- Şıklar: $n^3$ içeren bir seri yakınsak, bir başkası yakınsak, $\sum\left(\frac52\right)^n$ ıraksak ($\frac52=2{,}5>1$), sonuncusu yakınsak.
- Tek ıraksak şık $\sum\left(\frac52\right)^n$'dir. Cevap C.

### 5.9 Örnek 21: Kaç tanesi ıraksak?

- Kök içinden $n$ dışarı çıkınca pay ve payda aynı dereceden olan seri: ıraksak.
- $\sum\dfrac{\pi^n}{e^{n-1}}=e\sum\left(\dfrac\pi e\right)^n$: $\pi\approx3{,}14$, $e\approx2{,}71$, oran $\frac\pi e>1$, ıraksak.
- Düzenleme yapınca genel terimin limiti $e^k$ gibi sıfırdan farklı bir sayı çıkan seri: ıraksak.
- Bir seri daha ıraksak.
- Harmonik seri: ıraksak.
- Cevap: 4 tane ıraksak.

<!-- BELİRSİZ: 01:36:35-01:38:37 arası üçüncü ve dördüncü serilerin ifadeleri altyazıda okunmuyor. -->

> **Hocanın vurgusu:** Sorusu olan söylesin, tahtada tekrar çözerim; bundan hiç kaçınmam. Amacım anlaşılmayan şeylerin anlaşılır hâle gelmesi.

Hoca ardından, "$\sum a_n$ yakınsak iken $\sum\frac1{a_n}$ ıraksak" gibi ifadeleri genel terimlerle eşleştiren bir soruyu (daha önce sınavda gelmiş ve derste çözülmüş) gösterip geçti. 01:40:16'da $\ln n$ içeren bir serinin karakteri de soruldu.

<!-- BELİRSİZ: 01:40:16'daki seri altyazıda "birbirli elen en" diye geçiyor; tam ifade okunmuyor. -->

### 5.10 Örnek 22: İntegral testi, $\sum\dfrac1{n\left(1+(\ln n)^2\right)}$

Hoca bu serinin karakterinin diğer testlerle bulunmasının zor olduğunu, integral testiyle (integral test) yapılabileceğini söyledi.

**İntegral testi**

- $f$ pozitif, sürekli ve azalan, $a_n=f(n)$ olsun.
- $\int_1^\infty f(x)\,dx$ ile $\sum a_n$ aynı karakterdedir.

Çözüm:

- $f(x)=\dfrac1{x\left(1+\ln^2x\right)}$ pozitif ve azalan.
- $u=\ln x$, $du=\frac{dx}x$ dönüşümü: $\displaystyle\int\frac{du}{1+u^2}=\arctan u$.
- $x=1$'de $u=0$, $x\to\infty$'da $u\to\infty$ (ara adım eklendi): $\displaystyle\int_0^\infty\frac{du}{1+u^2}=\frac\pi2$.
- İntegral yakınsak, dolayısıyla seri yakınsaktır.

Doğrulama: sympy $\int_0^\infty\frac{du}{1+u^2}=\frac\pi2$.

### 5.11 Örnek 23: $\frac1{3^n}$ ve $\frac1{\sqrt[3]n}$ içeren seri

Ekranda iki serinin birlikte bulunduğu bir ifade vardı:

- $\sum\frac1{3^n}$: geometrik seri, yakınsak.
- $\sum\frac1{\sqrt[3]n}$: $p=\frac13<1$, $p$-serisi, ıraksak.

<!-- BELİRSİZ: 01:42:05'te iki serinin toplam mı başka bir biçimde mi verildiği ve sorunun tam ne istediği altyazıda net değil. Toplam olarak verildiyse yakınsak + ıraksak = ıraksak olur. -->

### 5.12 Örnek 24: Karşılaştırma testi, $\sum\dfrac1{n+2^n}$

- İlk akla gelen $\frac1n$ ile karşılaştırmak işe yaramaz: $\frac1{n+2^n}<\frac1n$ ama $\sum\frac1n$ ıraksaktır. Büyük seri ıraksaksa küçük seri hakkında bir şey söylenemez.
- Doğru karşılaştırma: $\frac1{n+2^n}<\frac1{2^n}$ ve $\sum\frac1{2^n}$ yakınsak geometrik seridir. Dolayısıyla seri yakınsaktır.

> **Hocanın vurgusu:** Çok ince bir nokta, orijinal bir soru. Bu karşılaştırma aklınıza geldiği anda iş biter.

> **Ek bilgi (derste anlatılmadı):** Karşılaştırma testi (comparison test): $0\le a_n\le b_n$ ise, $\sum b_n$ yakınsaksa $\sum a_n$ de yakınsaktır; $\sum a_n$ ıraksaksa $\sum b_n$ de ıraksaktır. Ters yönler bir sonuç vermez.

### 5.13 Oran ve kök testleri

Hoca hangi testin ne zaman kullanılacağını özetledi:

**Oran testi (ratio test)**

- Faktöriyelli terimlerde kullanılır.
- $L=\lim\left|\dfrac{a_{n+1}}{a_n}\right|$.
- $L<1$ ise yakınsak, $L>1$ ise ıraksak, $L=1$ ise test sonuç vermez; başka teste geçilir.

**Kök testi (root test)**

- $n$'inci kuvvetlerin olduğu terimlerde kullanılır.
- $L=\lim\sqrt[n]{|a_n|}$; karar oran testindeki gibidir.

### 5.14 Örnek 25: Karışık karakter soruları

Hoca daha önce çözülmüş soruları hızla gözden geçirdi:

- Payı $n^2$, paydasında $n^5$ olan terim: fark 3, yakınsak.
- $\sum\frac{5^n}{2^n}=\sum\left(\frac52\right)^n$: oran 1'den büyük, ıraksak geometrik seri.
- $\sum(-1)^n\frac1{n^{3/2}}$: $p=\frac32>1$, mutlak yakınsak. $p\le1$ olsaydı şartlı yakınsak olurdu.
- Payın derecesi 3, paydanın derecesi 2 olan terim: ıraksak.
- $\sum(-1)^n\left(\frac25\right)^n$ biçimli alterne seri: $\frac25<1$; mutlak değeri alınınca da yakınsak geometrik seri kalır. Mutlak yakınsak.

### 5.15 Örnek 26: Mutlak değerli karşılaştırma

Hoca alterne bir seride kosinüsün $[-1,1]$ aralığında olmasını kullandı. Paydaki ifade en fazla 2 değerini alır, paydada $n^3$ vardır:

- Mutlak değerler serisi $\frac2{n^3}$ ile karşılaştırılır. $p=3>1$, yakınsak.
- Mutlak değerler serisi yakınsak olduğu için seri mutlak yakınsaktır.

<!-- BELİRSİZ: 01:48:30'daki serinin payı altyazıda net değil ("kosinüs ... en fazla alacağı değer biridir, toplarsak iki"); $1+\cos(\cdot)$ biçiminde bir pay olabilir. -->

Hoca, $2n\ln n$ içeren bir seride integral testinin ıraksaklık verdiğini de kısaca gösterdi.

<!-- BELİRSİZ: 01:49:54'teki seri altyazıda "iki en elene" diye geçiyor; $\sum\frac1{n\ln n}$ türünden bir seri olabilir. -->

### 5.16 Örnek 27: $\sum(-1)^n\dfrac{n+1}{n+4}$

**Alterne seri testi (Leibniz)**

- $\sum(-1)^na_n$ için $a_n$ monoton azalan ve $\lim a_n=0$ ise seri yakınsaktır.

Çözüm:

- $a_n=\frac{n+1}{n+4}$: $n=1$'de $\frac25=0{,}4$, $n=2$'de $\frac36=0{,}5$. Terimler azalmıyor, artıyor.
- $\lim a_n=1\neq0$. Leibniz testinin şartları sağlanmıyor.
- Genel terim sıfıra gitmediği için seri ıraksaktır.

> **Ders sonrası not:** Hoca 01:50:15'te önce "şartlı" dedi, ardından terimlerin arttığını ve limitin 1 olduğunu görüp "ıraksaktır" dedi. Doğru sonuç ıraksaktır; $(-1)^n\frac{n+1}{n+4}$ sıfıra gitmez.

### 5.17 Örnek 28: Kök testi, $\sum\dfrac n{e^n}$

- $\sqrt[n]{a_n}=\dfrac{\sqrt[n]n}{e}$.
- $\sqrt[n]n\to1$ olduğundan limit $\frac1e<1$.
- Seri yakınsak; terimler pozitif olduğu için mutlak yakınsak.

Doğrulama: sympy limit $=e^{-1}$.

## 6. Kuvvet Serileri

Hoca dersi bitirmek üzereyken sonraki planı söyledi: kuvvet serileri, ardından çok değişkenli fonksiyonlar, limit, türevler ve kısmi türev soruları. Öğrencilere "devam edelim mi" diye sordu ve "3-5 soru çözüp kapatalım" diyerek kuvvet serilerine (power series) geçti.

**Kuvvet serisinde yakınsaklık aralığı**

- Oran testi uygulanır: $\lim\left|\dfrac{a_{n+1}}{a_n}\right|<1$ olan $x$ değerleri mutlak yakınsaklık aralığını verir.
- Uç noktalar ayrıca seride yerine konup incelenir.

### 6.1 Örnek 29: Her $x$ için yakınsayan seri

- Oran testinde düzenleme sonrası $\lim\limits_{n\to\infty}\dfrac{\sqrt x}{n+3}$ gibi bir ifade çıktı.
- $n\to\infty$ iken bu limit $x$'ten bağımsız olarak $0$'dır ve $0<1$.
- Seri her $x\in\mathbb R$ için yakınsaktır. Yakınsaklık aralığı $(-\infty,\infty)$, yakınsaklık yarıçapı sonsuz.

<!-- BELİRSİZ: Serinin kendisi altyazıda yok; limitteki pay "kök x" diye geçiyor, $|x|$ olabilir. -->

### 6.2 Örnek 30: Doğru/yanlış ifadeler

Bir kuvvet serisi için şu ifadeler verilmişti:

- I. Yakınsaklık aralığı $0$ ile $2$ arasındadır.
- II. $x=0$'da seri mutlak yakınsaktır.
- III. $x=4$ için seri ıraksaktır.
- IV. $(0,2)$ aralığında seri mutlak yakınsaktır.

Çözüm: oran testinden $0<x<2$'de mutlak yakınsaklık bulundu. Uç noktalar ($x=2$ ve $x=0$) yerine konunca hoca iki uçta da şartlı yakınsaklık olduğunu söyledi. Sonuç: I doğru, II yanlış, III doğru, IV doğru.

> **Ders sonrası not:** 01:57:26-01:57:51 arasında hoca uç noktalar için önce "ıraksaktır, 2 dahil değil", hemen ardından "2'de şartlı yakınsaklık vardır" dedi. Vardığı sonuç uçlarda şartlı yakınsaklıktır. Serinin kendisi altyazıda geçmediği için bu sonuç doğrulanamadı.

### 6.3 Örnek 31: Yalnız merkezde yakınsayan seri

- Faktöriyelli bir kuvvet serisinde oran testi uygulanınca limit $n\to\infty$ iken sonsuz çıktı.
- Limit 1'den büyük olduğu için seri merkez dışındaki her noktada ıraksaktır.
- Seri yalnız kuvvetin sıfır olduğu noktada, yani $x=2$'de yakınsar.

> **Hocanın vurgusu:** Burası çok kıymetli; sadece $x=2$ noktasında yakınsaktır.

### 6.4 Örnek 32: Yakınsaklık aralığı ve toplam fonksiyonu

Hoca bunun "çok orijinal bir soru" olduğunu söyledi: yalnız aralığı değil, serinin yakınsadığı fonksiyonu da bulmak isteniyor. Yöntem: seriyi terim terim açık yazmak. Açık yazınca ilk terim ve ortak çarpan görülür, seri geometrik seri gibi toplanır.

Kısa nottaki (tahta karesinden alınmış) ifadeye göre seri $\sum_{n=0}^\infty\dfrac{(x+1)^{n+1}}{2^{n+2}}$'dir:

- Açık yazım: $\dfrac{x+1}{2^2}+\dfrac{(x+1)^2}{2^3}+\dfrac{(x+1)^3}{2^4}+\cdots$
- İlk terim $a=\frac{x+1}4$, ortak çarpan $r=\frac{x+1}2$.
- $|r|<1\iff|x+1|<2\iff-3<x<1$.
- Toplam: $\dfrac{a}{1-r}=\dfrac{(x+1)/4}{1-(x+1)/2}=\dfrac{(x+1)/4}{(1-x)/2}=\dfrac{x+1}{2(1-x)}$.

<!-- BELİRSİZ: Serinin ifadesi altyazıda geçmiyor; yukarıdaki ifade kısa nottan alındı. Toplam fonksiyonu sympy ile doğrulandı. -->

> **Hocanın vurgusu:** Seri ne kadar karışık görünse de açık açık yazarsanız görme şansınız artar.

Hoca 02:01:56'da benzer bir soruyu (yakınsaklık aralığı ve yakınsadığı fonksiyon) daha gösterdi ama ayrıntısını anlatmadı.

### 6.5 Örnek 33: $f(x)=\dfrac{x}{1+x^2}$ fonksiyonunun kuvvet serisi

Bilinen seri:

$$\frac1{1-x}=\sum_{n=0}^\infty x^n,\qquad|x|<1.$$

- $x$ yerine $-x^2$ yazılır: $\dfrac1{1+x^2}=\displaystyle\sum_{n=0}^\infty(-1)^nx^{2n}$.
- Her taraf $x$ ile çarpılır: $\dfrac{x}{1+x^2}=\displaystyle\sum_{n=0}^\infty(-1)^nx^{2n+1}$.
- Aralık aynı kalır: $|x^2|<1\iff|x|<1$.

Doğrulama: sympy açılımı $x-x^3+x^5-x^7+\cdots$.

### 6.6 Örnek 34: $\dfrac{x^2}{(1-x^2)^2}$ fonksiyonunun kuvvet serisi

Hoca paydada kare olduğunu görünce bir kez türev almanın yeteceğini söyledi; küp olsaydı bir kez daha türev alınacaktı.

- $\dfrac1{1-x}=\sum x^n$ eşitliğinin iki tarafının türevi alınır, sağ taraf terim terim türevlenir: $\dfrac1{(1-x)^2}=\displaystyle\sum_{n=1}^\infty nx^{n-1}$.
- $x$ yerine $x^2$ yazılır (ara adım eklendi): $\dfrac1{(1-x^2)^2}=\displaystyle\sum_{n=1}^\infty nx^{2n-2}$.
- Eksik olan $x^2$ çarpanı için her taraf $x^2$ ile çarpılır:

$$\frac{x^2}{(1-x^2)^2}=\sum_{n=1}^\infty nx^{2n},\qquad-1<x<1.$$

Doğrulama: sympy açılımı $x^2+2x^4+3x^6+4x^8+\cdots$.

> **Ders sonrası not:** 02:05:08'de hoca sonucu okurken "$x$ bölü $(1-x^2)^2$" dedi. Sorudaki fonksiyon $\frac{x^2}{(1-x^2)^2}$'dir ve seri $\sum nx^{2n}$ bu fonksiyona aittir.

### 6.7 Örnek 35: $\sum\dfrac{n+2}{3^{n+1}}$ toplamı

- $\frac13$ yerine $x$ konup seri bir kuvvet serisi gibi düşünülür, bilinen serilerden düzenlenir.
- Hoca bunun tek yol olmadığını, ama sınavda bu şekilde düşünmenin pratik olduğunu söyledi.

> **Hocanın vurgusu:** Çöze çöze bu meleke kazanılır. Serileri bir bulmaca, bir oyun gibi görürseniz çok rahat ulaşırsınız.

> **Ek bilgi (derste anlatılmadı):** $\sum_{n\ge0}x^n=\frac1{1-x}$ ve türevinden $\sum_{n\ge0}nx^n=\frac x{(1-x)^2}$ ($|x|<1$). Bunlarla $\sum_{n\ge0}\frac{n+2}{3^{n+1}}=\frac13\left(\frac{x}{(1-x)^2}+\frac2{1-x}\right)_{x=1/3}=\frac54$ bulunur. Seri $n=1$'den başlıyorsa toplam $\frac7{12}$ olur; iki değer sympy ile doğrulandı.

<!-- BELİRSİZ: Toplamanın başlangıç indisi altyazıda geçmiyor. -->

### 6.8 Örnek 36: $\displaystyle\int_0^{1/2}\frac{\ln(1-x)}{x}\,dx$

- Bilinen açılım: $\ln(1+x)=x-\dfrac{x^2}2+\dfrac{x^3}3-\cdots$
- $x$ yerine $-x$ yazılır: $\ln(1-x)=-x-\dfrac{x^2}2-\dfrac{x^3}3-\cdots$
- $x$'e bölünür: $\dfrac{\ln(1-x)}x=-1-\dfrac x2-\dfrac{x^2}3-\cdots$
- Terim terim integral alınır; $x=0$'da değer sıfır olduğu için yalnız üst sınır $\frac12$ yerine konur:

$$\int_0^{1/2}\frac{\ln(1-x)}x\,dx=\left[-x-\frac{x^2}{4}-\frac{x^3}{9}-\cdots\right]_0^{1/2}=-\left(\frac12+\frac1{4\cdot4}+\frac1{9\cdot8}+\cdots\right)=-\sum_{n=1}^\infty\frac1{n^2\,2^n}.$$

Hoca şıklarda sonucun bu toplam biçiminde verildiğini, yöntemi bilince şıkları karşılaştırmanın yeteceğini söyledi.

Doğrulama: sayısal değer yaklaşık $-0{,}5822$ (sympy, integral ve seri aynı).

Hoca sıradaki sorunun Taylor ve Maclaurin açılımları ile yaklaşık hesaplamalarla ilgili olduğunu söyleyip dersi orada bıraktı.

## 7. Örnek Sorular

Bu bölümdeki sorular derste ekranda gösterilen ve çözülen sorulardır. Video ve kare olmadığı için metinler altyazıdaki sözlü anlatımdan kuruldu; çözümler yukarıdaki numaralı örneklerdedir.

- **Soru 1** (derste sözlü, 00:02:13): $r=\frac4{2\cos\theta-\sin\theta}$ kutupsal denklemi ne belirtir? Doğru / çember / kardiyoid / parabol. Cevap: doğru ($2x-y=4$). Bkz. Örnek 1.
- **Soru 2** (derste sözlü, 00:06:21): $(r,\theta)=\left(-3,\frac{5\pi}6\right)$ noktasının kartezyen koordinatı nedir? Cevap: $\left(\frac{3\sqrt3}2,-\frac32\right)$. Bkz. Örnek 2.
- **Soru 3** (derste sözlü, 00:09:00): $r=2\cos\theta$ içinde, $r=\sqrt2$ dışında kalan alanı veren integral hangisidir? Cevap: $\int_0^{\pi/4}(4\cos^2\theta-2)\,d\theta$. Bkz. Örnek 4.
- **Soru 4** (derste sözlü, 00:13:21): $r=2\cos\theta$ dışında, $r=\sqrt2$ içinde kalan alanı veren integral hangisidir? Bkz. Örnek 5.
- **Soru 5** (derste sözlü, 00:16:25): $r=3\cos\theta$ içinde, $r=1+\cos\theta$ dışında kalan alanı veren integral hangisidir? Bkz. Örnek 6.
- **Soru 6** (derste sözlü, sınav sorusu, 00:22:13): $r=3\cos\theta$ dışında, $r=1+\cos\theta$ içinde kalan alanı veren integral hangisidir? Bkz. Örnek 7.
- **Soru 7** (derste sözlü, 00:24:18): $r=1-\sin\theta$ içinde, $r=\sin\theta$ dışında kalan alanı veren integral hangisidir? Bkz. Örnek 8.
- **Soru 8** (derste sözlü, 00:29:49): $r=1-\sin\theta$ dışında, $r=\sin\theta$ içinde kalan bölgenin alanını veren integral hangisidir? Bkz. Örnek 9.
- **Soru 9** (derste sözlü, 00:46:01): $r=1-\sin\theta$ ve $r=\sin\theta$ eğrilerinin ortak alanını veren integral hangisidir? Bkz. Örnek 10.
- **Soru 10** (derste sözlü, 00:48:56, 00:50:58, 00:52:22): $r=1$ ve $r=1-\cos\theta$ için (a) ortak alanı, (b) $r=1$ içinde kardiyoid dışında, (c) $r=1$ dışında kardiyoid içinde kalan alanı veren integraller hangileridir? Bkz. Örnek 11.
- **Soru 11** (derste sözlü, sınavda çıkmış, 00:53:44): $r=4$, $\theta=\frac\pi2$ ve $r=2\sec\theta$ arasında kalan alanı veren integral hangisidir? Bkz. Örnek 12.
- **Soru 12** (derste sözlü, 00:57:49): $r=2\sin\theta$ ve $r=\sqrt2$ eğrilerinin ortak alanını veren integral hangisidir?

> **Çözüm (derste verilmedi):** Kesim açısı $\frac\pi4$. Sağ yarıda $0\le\theta\le\frac\pi4$ arasında $2\sin\theta$, $\frac\pi4\le\theta\le\frac\pi2$ arasında $\sqrt2$ içtedir. $A=\int_0^{\pi/4}4\sin^2\theta\,d\theta+\int_{\pi/4}^{\pi/2}2\,d\theta=\pi-1$ (sympy ile doğrulandı).

- **Soru 13** (derste sözlü, 00:58:16): $r=2\sin\theta$ dışında, $r=\sqrt2$ içinde kalan alanı veren integral hangisidir? Bkz. Örnek 13.
- **Soru 14** (derste sözlü, sınav sorusu, 01:01:13): $-\frac\pi3\le\theta\le-\frac\pi6$ açı aralığında, $r=2$ sınırı kesikli çizilmiş bir bölgeyi veren eşitsizlikler hangisidir? Cevap: $r<2$ olan şık. Bkz. Örnek 3. <!-- BELİRSİZ: $r$ alt sınırı altyazıda net değil. -->
- **Soru 15** (derste sözlü, 01:24:36): $\sum\pi^{-n}\cos n\pi$ serisinin toplamı nedir? Bkz. Örnek 14.
- **Soru 16** (derste sözlü, 01:28:18): $\sum\frac1{n^{3/2}}$, $\sum\left(\frac23\right)^n$, $\sum\frac1{\sqrt n}$, $\sum\frac{2^n}{n^2}$, paydası $n^5$ dereceli bir rasyonel seri ve harmonik seri ile karşılaştırılan bir seriden kaç tanesi yakınsaktır? Cevap: 3. Bkz. Örnek 15.
- **Soru 17** (derste sözlü, 01:33:06): $\sum\frac{2+\sin n^2}{1+n^2}$ serisinin karakterini belirleyiniz. Cevap: yakınsak. Bkz. Örnek 17.
- **Soru 18** (derste sözlü, 01:33:47): $\sum\frac{5\cdot4^n+7^n\cos n\pi}{7^n\cdot4^{n+1}}$ serisinin toplamı nedir? Bkz. Örnek 18.
- **Soru 19** (derste sözlü, 01:34:45): $\sum\frac1{(\ln2)^n}$ serisinin karakteri nedir? Cevap: ıraksak. Bkz. Örnek 19.
- **Soru 20** (derste sözlü, 01:35:08): $\sum\frac{2n+1}{3+4n}$ serisiyle aynı karakterde olan seri hangisidir? Cevap: $\sum\left(\frac52\right)^n$. Bkz. Örnek 20.
- **Soru 21** (derste sözlü, 01:41:12): $\sum\frac1{n(1+\ln^2n)}$ serisinin karakterini bulunuz. Cevap: yakınsak (integral testi). Bkz. Örnek 22.
- **Soru 22** (derste sözlü, 01:42:48): $\sum\frac1{n+2^n}$ serisinin karakteri nedir? Cevap: yakınsak. Bkz. Örnek 24.
- **Soru 23** (derste sözlü, 01:50:15): $\sum(-1)^n\frac{n+1}{n+4}$ ve $\sum\frac n{e^n}$ serilerinin karakterlerini belirleyiniz. Cevap: birincisi ıraksak, ikincisi mutlak yakınsak. Bkz. Örnek 27 ve 28.
- **Soru 24** (derste sözlü, 01:56:37): Bir kuvvet serisi için "yakınsaklık aralığı $0$-$2$", "$x=0$'da mutlak yakınsak", "$x=4$ için ıraksak", "$(0,2)$'de mutlak yakınsak" ifadelerinden hangileri doğrudur? Cevap: II dışındakiler. Bkz. Örnek 30. <!-- BELİRSİZ: Serinin kendisi altyazıda yok. -->
- **Soru 25** (derste sözlü, 02:02:34): $f(x)=\frac x{1+x^2}$ fonksiyonunun kuvvet serisi temsili ve yakınsaklık aralığı nedir? Cevap: $\sum(-1)^nx^{2n+1}$, $|x|<1$. Bkz. Örnek 33.
- **Soru 26** (derste sözlü, 02:03:57): $\frac{x^2}{(1-x^2)^2}$ fonksiyonunun kuvvet serisi temsili ve yakınsaklık aralığı nedir? Cevap: $\sum_{n\ge1}nx^{2n}$, $|x|<1$. Bkz. Örnek 34.
- **Soru 27** (derste sözlü, 02:05:36): $\sum\frac{n+2}{3^{n+1}}$ serisinin toplamı nedir? Bkz. Örnek 35.
- **Soru 28** (derste sözlü, 02:06:27): $\int_0^{1/2}\frac{\ln(1-x)}x\,dx$ integralinin seri karşılığı nedir? Cevap: $-\sum\frac1{n^2 2^n}\approx-0{,}582$. Bkz. Örnek 36.

## Dersin Toparlaması

Bu ders final hazırlığı için bir soru çözüm dersiydi. Kutupsal bölümde ana fikir, iki eğri arasındaki alanı veren integrali doğru kurmaktı: eğrileri tanıyıp çizmek, kesim açısını bulmak, simetriyi kullanıp yarım bölgeyi hesaplamak ve gerektiğinde "fazlayı al, fazlalığı çıkar" mantığıyla iki integral yazmak. Hoca, sorularda çoğunlukla integralin değerinin değil kendisinin istendiğini, şıkların bazen yalnız sınır ya da düzenleme farkıyla ayrıldığını tekrar tekrar vurguladı.

Seriler bölümünde geometrik seri, $p$-serisi, rasyonel terimler için derece farkı kuralı, alterne serilerde mutlak ve şartlı yakınsaklık, karşılaştırma, limit karşılaştırma, integral, oran ve kök testleri soru üzerinden tekrar edildi. Kuvvet serilerinde oran testiyle yakınsaklık aralığı bulma, geometrik kuvvet serisinin toplam fonksiyonunu bulma ve $\frac1{1-x}$ ile $\ln(1+x)$ açılımlarından yerine koyma, türev ve çarpma yoluyla yeni seriler elde etme gösterildi. Hoca bir sonraki derste Taylor ve Maclaurin açılımları ve yaklaşık hesaplama sorularıyla, ardından çok değişkenli fonksiyonlar, limit ve kısmi türev sorularıyla devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
