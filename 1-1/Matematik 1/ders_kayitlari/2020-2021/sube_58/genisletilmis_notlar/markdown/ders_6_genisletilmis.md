# Ders 6 Genişletilmiş Notu: Zincir Kuralı Alıştırmaları, Yüksek Mertebeden Türevler ve Kapalı Türev

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı ve Çalışma Yöntemi
- 2. Zincir Kuralı Alıştırmaları
- 3. Tablo ile Zincir Kuralı
- 4. Sınav Sorusu Nasıl Zorlaştırılır?
- 5. Yüksek Mertebeden Türevler
- 6. Zincir Kuralı ve Teğet Doğrusu
- 7. Kapalı Türev: Açık ve Kapalı Form
- 8. Birim Çember Örneği
- 9. Kapalı Türev Alma Yöntemi ve $dx/dy$
- 10. Kapalı Formda Verilen Eğrilere Teğet
- 11. Kitaptan Alıştırmalar: Rasyonel Üslü Kapalı Türev
- Örnek Sorular

## 1. Dersin Planı ve Çalışma Yöntemi

Hoca derse, sınavdan önce bütün konuları bitirmeyi hedeflediğini söyleyerek başladı. Konular bittikten sonra sınava yönelik genel alıştırmalar yapılacak, geçen yılların test soruları çözülecek. Bu yüzden derslerin biraz hızlı gittiği düşünülebilir. Hocaya göre bu hız öğrencinin avantajına olacak.

Hoca birkaç kez aynı noktayı vurguladı: Önemli olan işin mantığını anlamaktır. Çok soru çözmek marifet değildir.

> **Hocanın vurgusu:** Her formülün arkasındaki felsefeyi anlamak çok önemlidir (it is very important to understand philosophy behind each formula). Hocaya göre çok sayıda soru çözmenize gerek yok. Derste çözülen soruların mantığını kavrarsanız sınavda zorlanmazsınız.

Hoca ayrıca online ders sırasında önünüzde kâğıt ve kalem bulunmasını istedi. Ders içinde ara ara alıştırma verip öğrencilerden çözmelerini bekliyor.

## 2. Zincir Kuralı Alıştırmaları

Bir önceki derste zincir kuralı (chain rule) kavramı anlatılmıştı. Hoca bu derse önce özel bir durumla başladı, ardından kısa alıştırmalar çözdü.

### 2.1 Karekök İçin Genel Kural

$y = \sqrt{u}$ ve $u = u(x)$ olsun. $y$, $u$'ya; $u$ da $x$'e bağlıdır. Zincir kuralına göre önce $y$'nin $u$'ya göre türevi alınır, sonra $u$'nun $x$'e göre türeviyle çarpılır:

$$\frac{dy}{dx} = \frac{dy}{du} \cdot \frac{du}{dx}, \qquad \big(\sqrt{u}\big)' = \frac{1}{2\sqrt{u}} \cdot u'.$$

Hoca bunu "genel kural" olarak verdi.

### 2.2 Örnek 1: $y = \sqrt{\sin^2 x + x^2}$

Burada $u = \sin^2 x + x^2$'dir. Kök içindeki ifadenin (radikalin argümanının) da türevi alınmalıdır:

$$y' = \frac{1}{2\sqrt{\sin^2 x + x^2}} \cdot \big(\sin^2 x + x^2\big)'.$$

$\sin^2 x$'in türevi için zincir kuralı bir kez daha uygulanır. Bu kez $u = \sin x$ ve $(u^2)' = 2u \cdot u'$ olduğundan $(\sin^2 x)' = 2\sin x \cos x$ olur. $x^2$'nin türevi $2x$'tir. Sonuç:

$$y' = \frac{2\sin x \cos x + 2x}{2\sqrt{\sin^2 x + x^2}}.$$

### 2.3 Örnek 2: $y = (3x + 7)^{10}$

$u = 3x + 7$ alınır. $y = u^{10}$ olduğundan:

$$y' = 10u^9 \cdot u' = 10(3x+7)^9 \cdot 3 = 30(3x+7)^9.$$

### 2.4 Örnek 3: $y = \cos(x^5)$

$u = x^5$ ve $y = \cos u$. $y$'nin $u$'ya göre türevi $-\sin u$, $u$'nun $x$'e göre türevi $5x^4$'tür:

$$y' = -\sin(x^5) \cdot 5x^4.$$

Hoca bu noktada listedeki üstel fonksiyonlu soruların sonraki haftaların konusu olduğunu söyledi.

### 2.5 Örnek 4: $y = \tan(5x^2)$

$u = 5x^2$ ve $y = \tan u$. $(\tan u)' = \sec^2 u \cdot u'$ olduğundan:

$$y' = \sec^2(5x^2) \cdot 10x.$$

### 2.6 Örnek 5: $y = \sin^5 x$

$u = \sin x$ ve $y = u^5$:

$$y' = 5\sin^4 x \cdot \cos x.$$

<!-- BELİRSİZ: 00:09:36–00:09:58 arasında altyazı döngüye girmiş; "7x-1" geçen bir ifade duyuluyor. Bu aralıkta ayrı bir örnek çözülmüş olabilir, ama altyazıdan anlaşılmıyor. -->

Hoca, herkesin zincir kuralı fikrini anladığını düşündüğünü söyledi.

## 3. Tablo ile Zincir Kuralı

Hoca ardından test sınavının ruhuna uygun bir soru gösterdi ve öğrencilerden çözmelerini istedi. Test sınavında çıkma olasılığı yüksek soruların üstüne üç yıldız (\*\*\*) koyduğunu, bunu öğrencilerin motivasyonunu artırmak için yaptığını söyledi. Listedeki 18. sorunun ise sonraki haftaların konusu olduğunu belirtti.

> **Hocanın vurgusu:** Bu tarz sorular test sınavının ruhuna uygun sorulardır. Üç yıldızlı soruların sınavda çıkma olasılığı yüksektir.

<!-- BELİRSİZ: Üç yıldızın hangi soruya konduğu altyazıdan tam anlaşılmıyor; akışa göre büyük olasılıkla aşağıdaki tablo sorusudur. -->

### 3.1 Örnek 6: Tablodan Türev Hesabı

$h(x) = f(g(x))$ ve $p(x) = g(f(x))$ veriliyor. Tablodaki değerler kullanılarak türevler hesaplanacak.

| $x$ | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|
| $f(x)$ | 0 | 3 | 5 | 1 | 0 |
| $f'(x)$ | 5 | 2 | −5 | −8 | −10 |
| $g(x)$ | 4 | 5 | 1 | 3 | 2 |
| $g'(x)$ | 2 | 10 | 20 | 15 | 20 |

<!-- BELİRSİZ: Tablo değerleri altyazıda okunmuyor; kısa nottaki ekrandan alınmış tablo kullanıldı. Altyazı yalnız $g'(3) = 20$ değerini doğruluyor. -->

$h$'de $f$, $g$'ye; $g$ de $x$'e bağlıdır. Zincir kuralına göre önce $f$'nin $g$'ye göre türevi ($df/dg$) alınır, sonra $dg/dx$ ile çarpılır:

$$h'(x) = f'(g(x)) \cdot g'(x).$$

**a) $h'(3)$:** $x = 3$ yazılır. Tablodan $g(3) = 1$ ve $g'(3) = 20$ okunur:

$$h'(3) = f'(g(3)) \cdot g'(3) = f'(1) \cdot 20 = 5 \cdot 20 = 100.$$

$p$ için bileşkenin sırasına dikkat etmek gerekir. $p$, $g$ ile $f$'nin bileşkesidir, ama sıra terstir:

$$p'(x) = g'(f(x)) \cdot f'(x).$$

Hoca diğer şıkları basit olduğu için tek tek çözmedi, öğrencilere ödev olarak bıraktı.

## 4. Sınav Sorusu Nasıl Zorlaştırılır?

Hoca, "hocanın psikolojisini anlamanız için" soru hazırlayanların ne yaptığını gösterdi. Soru hazırlayan hocalar kitapta beğendikleri bir soruyu alıp modifiye eder. Sınavda göreceğiniz sorular, kitaptaki soruların değiştirilmiş hâlleri olabilir.

Hoca bunu canlı olarak gösterdi. Bir fonksiyon şöyle verilsin:

$$f(x) = \tan\big(g(x)\big) \cdot h(x),$$

ve $g$, $h$ için bir tablo verilsin. $f'(x)$'i bulmak için hem çarpım kuralı (product rule) hem zincir kuralı gerekir. Birinci çarpanın türevi çarpı ikinci çarpan, artı birinci çarpan çarpı ikinci çarpanın türevi yazılır. $\tan$'ın türevi için hoca $1 + \tan^2$ biçimini kullandı:

$$f'(x) = \big(1 + \tan^2 g(x)\big) \cdot g'(x) \cdot h(x) + \tan\big(g(x)\big) \cdot h'(x).$$

Bu sorunun amacı, zincir kuralını bilip bilmediğinizi ölçmektir. Tablodan bir noktadaki değerler okunup yerine konur.

> **Hocanın vurgusu:** Bu tarz sorularla sınavlarda karşılaşabilirsiniz. Hoca uyarmış olsun; ona göre çalışın.

> **Ek bilgi (derste anlatılmadı):** $(\tan u)' = \sec^2 u \cdot u'$ ve $(\tan u)' = (1 + \tan^2 u) \cdot u'$ aynı sonuçtur. Çünkü $1 + \tan^2 u = \sec^2 u$ özdeşliği vardır. Bu özdeşlik $\sin^2 u + \cos^2 u = 1$ eşitliğinin iki tarafı $\cos^2 u$'ya bölünerek elde edilir.

## 5. Yüksek Mertebeden Türevler

Hoca ardından yüksek mertebeden türevlere (higher order derivatives) geçti. Önce gösterimleri verdi: İkinci türev $y''$ ya da $\dfrac{d^2y}{dx^2}$ ile, $n$. türev $y^{(n)}$ ya da $\dfrac{d^ny}{dx^n}$ ile gösterilir.

İkinci mertebe türevin anlamı şudur: Birinci mertebe türevin türevidir.

$$\frac{d^2y}{dx^2} = \frac{d}{dx}\left(\frac{dy}{dx}\right).$$

### 5.1 Örnek 7: $y = x\cos(x^2)$

**Birinci türev.** Çarpım kuralı uygulanır. $x$'in türevi $1$'dir. $\cos(x^2)$'nin türevi için zincir kuralı gerekir: $(\cos u)' = -\sin u \cdot u'$ ve $u = x^2$, $u' = 2x$.

$$y' = 1 \cdot \cos(x^2) + x \cdot \big(-\sin(x^2) \cdot 2x\big) = \cos(x^2) - 2x^2\sin(x^2).$$

**Soru:** (Bir öğrenci) Çarpım kuralında artı olmuyor muydu? Eksi nereden geldi?
**Cevap:** Çarpım formülünde artı vardır. Bu eksi, $\cos u$'nun türevinden ($-\sin u \cdot u'$) geliyor.

**İkinci türev.** Şimdi birinci türevin türevi alınır. İlk terim $\cos(x^2)$'nin türevi $-\sin(x^2) \cdot 2x$'tir. İkinci terim $2x^2\sin(x^2)$ için yine çarpım kuralı gerekir: Birinci çarpanın türevi $4x$ çarpı $\sin(x^2)$, artı $2x^2$ çarpı $\sin(x^2)$'nin türevi, yani $\cos(x^2) \cdot 2x$.

$$y'' = -2x\sin(x^2) - \Big(4x\sin(x^2) + 2x^2\cos(x^2) \cdot 2x\Big).$$

Sadeleştirilirse (ara adım eklendi):

$$y'' = -6x\sin(x^2) - 4x^3\cos(x^2).$$

> **Hocanın vurgusu:** Sonucu sadeleştirmek zorunda değilsiniz. Sınavda genellikle belirli bir $x$ değerinde ifadenin değeri sorulur. O değeri bu ifadeye yerine koymanız yeterlidir.

Hoca listedeki üstel fonksiyonlu soruların yine sonraki haftaların konusu olduğunu söyledi. Diğer sorular ödev olarak bırakıldı.

## 6. Zincir Kuralı ve Teğet Doğrusu

Hoca, test sınavında genelde teğet doğrusu sorularının sorulduğunu söyledi ve bu yapıda "çok güzel" bulduğu bir kitap sorusunu gösterdi.

> **Hocanın vurgusu:** Teğet doğrusu soruları test sınavında sıkça sorulur. Bu sorular genelde modifiye edilerek karşınıza çıkar. Sorunun genel yapısına odaklanın.

### 6.1 Örnek 8: $g(x) = f(x^2)$ ve Teğet Doğrusu

$f$ türevlenebilir bir fonksiyondur ve grafiği $(1, 4)$ noktasından geçer. $f$'nin grafiğine $(1, 4)$ noktasında teğet olan doğru $y = 3x + 1$'dir. $g(x) = f(x^2)$ olarak veriliyor.

Hoca önce soruyu anlamaya çalıştı. Grafiğin $(1,4)$'ten geçmesi $f(1) = 4$ demektir. Teğet doğrusunun eğimi $3$'tür. Türevin geometrik yorumuna göre bu eğim, $f$'nin $x = 1$'deki türev değeridir. Yani elimizdeki bilgiler:

$$f(1) = 4, \qquad f'(1) = 3.$$

**a) $g(1)$:** $g(1) = f(1^2) = f(1) = 4$.

**b) $g'(x)$:** Zincir kuralıyla, önce $f$'nin $x^2$'ye göre türevi, sonra $x^2$'nin $x$'e göre türevi:

$$g'(x) = f'(x^2) \cdot 2x.$$

**c) $g'(1)$:** $g'(1) = f'(1) \cdot 2 \cdot 1 = 3 \cdot 2 = 6$.

**Soru:** (Bir öğrenci) $y = 3x + 1$ dediniz. Bu $f(x)$ değil mi? O zaman $f(x) = 3x^2 + 1$ mi olacak?
**Cevap:** Hayır. $y = 3x + 1$ teğet doğrusunun denklemidir. $y = f(x)$'in kuralını bilmiyoruz. Bildiğimiz şey teğet doğrusudur. Türevin geometrik yorumundan dolayı teğetin eğiminin, türev fonksiyonunun $1$'deki değeri olduğunu biliyoruz.

**d) $g$'nin grafiğine $x = 1$'de teğet olan doğru:** Bir öğrencinin isteği üzerine hoca bu şıkkı da çözdü. Önce soruyu bir şekille anlattı: $y = g(x)$'in grafiğini bilmiyoruz, ama $g(x) = f(x^2)$ olduğunu biliyoruz. $x = 1$'deki teğet doğrusunun $y = mx + n$ biçimindeki denklemi isteniyor.

Teğet doğrusunun geçtiği nokta $(1, g(1)) = (1, 4)$'tür. Eğim (c) şıkkında bulundu: $g'(1) = 6$. Doğru denklemi:

$$y - g(1) = g'(1)(x - 1) \;\Rightarrow\; y - 4 = 6(x - 1) \;\Rightarrow\; y = 6x - 6 + 4 = 6x - 2.$$

Hocaya göre bu kolay bir sorudur. Zor hâli, fonksiyonların yapısının değiştirilmesiyle elde edilir: İşin içine tanjant, sekant ya da ileride görülecek üstel fonksiyonlar katılır.

### 6.2 Örnek 9: $g(x) = f(\sin x)$

Hoca bir alıştırma daha verdi ve öğrencilerin cevaplarını bekledikten sonra çözdü. $f$ ilgili aralıkta türevlenebilir, $f'(0) = 3$ ve $f'(1) = 5$ veriliyor. $g(x) = f(\sin x)$, yani $f$ ile $\sin$'in bileşkesi.

Zincir kuralıyla önce $g'$ bulunur: $f$'nin $\sin x$'e göre türevi çarpı $\sin x$'in $x$'e göre türevi.

$$g'(x) = f'(\sin x) \cdot \cos x.$$

- $g'(0) = f'(\sin 0) \cdot \cos 0 = f'(0) \cdot 1 = 3$.
- $g'(\pi/2) = f'(\sin \tfrac{\pi}{2}) \cdot \cos \tfrac{\pi}{2} = f'(1) \cdot 0 = 0$. Birim çemberden $\sin(\pi/2) = 1$ ve $\cos(\pi/2) = 0$.
- $g'(\pi) = f'(\sin \pi) \cdot \cos \pi = f'(0) \cdot (-1) = 3 \cdot (-1) = -3$.

## 7. Kapalı Türev: Açık ve Kapalı Form

Hoca bu kısımda kapalı türev (implicit differentiation) konusuna geçti. Kendi ifadesiyle "kapalı fonksiyonun türevi" yerine "kapalı formda verilen bir fonksiyonun türevi" demek daha doğru bir kavramdır.

### 7.1 Açık Form

Şimdiye kadar açık formdaki (explicit form) fonksiyonların türevini öğrendik.

**Tanım (açık form):**

- Bağımlı değişken, yalnız bağımsız değişken cinsinden yazılabiliyorsa fonksiyon açık formdadır.
- $y = f(x)$: $y$ bağımlı, $x$ bağımsız değişkendir. Bağımlı değişkenin bağımsız değişkene göre türevinden, yani $\dfrac{dy}{dx}$'ten söz ederiz.
- $x = g(y)$: Bu da açık formdur. Burada $x$, $y$ cinsinden yazılmıştır. Bu durumda $\dfrac{dx}{dy}$'den söz ederiz.

Hoca ikinci durumu da bir grafikle gösterdi. $x = g(y)$ eğrisine çizilen teğetin eğimiyle ilgili değer burada $\dfrac{dx}{dy}$'dir.

### 7.2 Kapalı Form

**Tanım (kapalı form):**

- $x$ ve $y$'yi birlikte içeren cebirsel bir denkleme kapalı form (implicit form) denir.
- Böyle durumlarda bazen $y$'yi $x$ cinsinden ya da $x$'i $y$ cinsinden yazamayabiliriz.

Kapalı formdaki bir eğrinin tamamı, $y = f(x)$ ya da $x = g(y)$ biçiminde herhangi bir fonksiyonun grafiğine karşılık gelmeyebilir. Ama eğrinin bazı yerel parçaları (local parts) vardır ve bu parçalar için açık bir form elde edilebilir. Size $\dfrac{dy}{dx}$ hesaplamanız soruluyorsa, bu, eğrinin böyle bir yerel parçası üzerinde çalıştığınız anlamına gelir. O yerel parça üzerinde eğrinin teğetini hesaplarsınız.

## 8. Birim Çember Örneği

### 8.1 Örnek 10: $x^2 + y^2 = 1$

Bu denklem açık form değil, kapalı formdur. Düzlemde birim çemberi gösterir.

**Üst yarı çember.** $\dfrac{dy}{dx}$ istendiğinde bir yerel parça seçilir; örneğin üst yarı çember. Bu durumda $y$'yi $x$ cinsinden yazabiliriz (ama bu her zaman mümkün değildir):

$$y = +\sqrt{1 - x^2}.$$

Böylece kapalı formdan bir açık form elde ettik. Artık $y$ bağımlı, $x$ bağımsız değişkendir ve doğrudan türev alınabilir:

$$\frac{dy}{dx} = \frac{1}{2\sqrt{1 - x^2}} \cdot (1 - x^2)' = \frac{-2x}{2\sqrt{1 - x^2}} = -\frac{x}{\sqrt{1 - x^2}}.$$

> **Hocanın vurgusu:** Bu $\dfrac{dy}{dx} = -\dfrac{x}{\sqrt{1-x^2}}$ fonksiyonu, üst yarı çembere çizilen teğet doğrularının eğimini hesaplamak için kullanılan bir araçtır.

Alt yarı çember için de benzer şekilde $\dfrac{dy}{dx}$ yazılabilir.

**Sol yarı çember.** Hoca şöyle bir soru sordu: Sağ ve sol yarı çemberdeki teğetlerin eğimini hesaplayan bir araç geliştirmek istersek ne yaparız? Sol yarı çemberde $x$'i $y$ cinsinden yazarız:

$$x = -\sqrt{1 - y^2}.$$

Bu kez $x$ bağımlı, $y$ bağımsız değişkendir, yani $x = g(y)$. Bağımlı değişkenin bağımsız değişkene göre türevi $\dfrac{dx}{dy}$'dir:

$$\frac{dx}{dy} = -\frac{1}{2\sqrt{1 - y^2}} \cdot (-2y) = \frac{y}{\sqrt{1 - y^2}}.$$

Bu fonksiyon da sol yarı çemberdeki teğet doğrularının eğimiyle ilgili bir araçtır.

## 9. Kapalı Türev Alma Yöntemi ve $dx/dy$

### 9.1 İkinci Yöntem: Açık Forma Geçmeden Türev

Birim çember basit bir örnekti, çünkü $y$'yi $x$ cinsinden yazabildik. Ama öyle denklemler vardır ki bunu yapamayız. O zaman ne yapacağız?

Hoca ikinci yöntemi yine $x^2 + y^2 = 1$ üzerinde gösterdi. $\dfrac{dy}{dx}$ isteniyorsa, $y$'nin $x$'e bağlı bir fonksiyon olduğunu, yani $y = f(x)$ olduğunu kabul ederiz. Bu $f$'yi bilmemiz ya da bulmamız gerekmez. Denklemde $y$ yerine $f(x)$ yazılır ve eşitliğin iki tarafının bağımsız değişken $x$'e göre türevi alınır:

- $x^2$'nin $x$'e göre türevi $2x$'tir.
- $f(x)^2$'nin türevi zincir kuralıyla bulunur: $f^2$'nin $f$'ye göre türevi $2f$, çarpı $f$'nin $x$'e göre türevi $f'(x)$.
- Sağ taraftaki $1$ sabittir, türevi $0$'dır.

$$2x + 2f(x) \cdot f'(x) = 0.$$

Aynı şey $y$ gösterimiyle de yazılabilir. $y^2$, $y$'ye bağlıdır; $y$ de $x$'e bağlıdır. Hoca bunu bir ağaç diyagramıyla (tree diagram) gösterdi:

```
y^2  ->  y  ->  x
```

Zincir kuralına göre $y^2$'nin $x$'e göre türevi için önce $y^2$'nin $y$'ye göre türevi ($2y$) alınır, sonra $y$'nin $x$'e göre türeviyle ($y'$) çarpılır:

$$2x + 2y \cdot y' = 0 \;\Rightarrow\; y' = -\frac{x}{y}.$$

$y = f(x)$ gösterimini kullanmanız gerekmez. Ağaç diyagramını göz önüne alarak aynı sonuca ulaşırsınız. Yaklaşım aynıdır, yalnız gösterimler farklıdır.

<!-- BELİRSİZ: 00:53:46–00:54:14 arasında altyazı döngüye girmiş; bu kısımda hoca yöntemi adım adım özetliyor olabilir, ama altyazıdan anlaşılmıyor. -->

### 9.2 Örnek 11: $x^2 + \sin(xy) = y^2$

Aradan sonra hoca kafasından yazdığı bir örnekle devam etti. $\dfrac{dy}{dx}$ isteniyor. Bu, $y$'nin bağımlı, $x$'in bağımsız değişken olduğu anlamına gelir. $y^2$, $y$'ye; $y$ de $x$'e bağlıdır.

Eşitliğin iki tarafının $x$'e göre türevi alınır:

- $x^2$'nin türevi $2x$.
- $\sin(xy)$ için $u = xy$ alınır: $(\sin u)' = \cos u \cdot u'$. $u = xy$'nin türevi çarpım kuralıyla bulunur ve $y$'nin $x$'e bağlı olduğu unutulmaz: $(xy)' = 1 \cdot y + x \cdot y'$.
- $y^2$'nin türevi ağaç diyagramına göre $2y \cdot y'$.

$$2x + \cos(xy)\,(y + x y') = 2y \, y'. \qquad (\star)$$

Hoca burada $y'$'yü ortak parantezine alarak düzenlemeye başladı, ama düzenlemeyi yarıda bıraktı. Hocaya göre sonucu bu hâliyle bırakmak yeterlidir. Sorularda görüleceği gibi düzenleme yapmaya gerek yoktur.

**$dx/dy$ istenirse.** Bu kez $x$'i bağımlı, $y$'yi bağımsız değişken kabul ederiz: $x = g(y)$. $g$'nin ne olduğunu bilmemiz gerekmez. Bu durumda $x^2$, $x$'e; $x$ de $y$'ye bağlıdır. Eşitliğin iki tarafının $y$'ye göre türevi alınır ve $x' = \dfrac{dx}{dy}$ yazılır:

$$2x \, x' + \cos(xy)\,(x' y + x) = 2y. \qquad (\star\star)$$

<!-- BELİRSİZ: 01:13:33–01:14:03 arasında altyazı döngüye girmiş; $(\star\star)$ denkleminin son hâli derste anlatılan adımlardan kuruldu. -->

**Ödev ve sonuç.** Hoca, $(\star)$'dan $\dfrac{dy}{dx}$'i, $(\star\star)$'dan $\dfrac{dx}{dy}$'yi bulup çarpmayı ödev olarak verdi. Çarpımın $1$ çıktığı görülecek:

$$\frac{dy}{dx} \cdot \frac{dx}{dy} = 1.$$

Bunun anlamı şudur: $\dfrac{dy}{dx}$ elinizdeyse ayrıca $\dfrac{dx}{dy}$ hesaplamanız gerekmez:

$$\frac{dy}{dx} = \frac{1}{\,dx/dy\,}.$$

Bunun için payda sıfırdan farklı olmalıdır. Aksi hâlde bu yazılamaz.

## 10. Kapalı Formda Verilen Eğrilere Teğet

### 10.1 Örnek 12: $x^2 + xy + y^2 = 3y$, $(1,1)$ Noktasında Teğet

Hoca test sınavında görülebilecek yapıda bir soru yazdı: Kapalı formda verilen $x^2 + xy + y^2 = 3y$ eğrisine $(1, 1)$ noktasında teğet olan doğrunun denklemini bulun. Önce öğrencilere süre verdi.

Çözüme bir şekille başladı. Eğrinin grafiğini bilmiyoruz, ama bir eğri düşünüp üzerinde bir teğet çizebiliriz. Amaç bu teğetin $y = mx + n$ denklemini bulmaktır. Burada $m$, $y$'nin $(1,1)$ noktasındaki türev değeridir. $y$ bağımlı, $x$ bağımsız değişkendir. Bu yüzden eşitliğin iki tarafının $x$'e göre türevi alınır, $y$'nin $x$'e bağlı olduğu göz önüne alınır:

$$2x + (1 \cdot y + x y') + 2y \, y' = 3y'.$$

$(1,1)$ noktasında $y' = m$ yazılır:

$$2 + 1 + m + 2m = 3m \;\Rightarrow\; 3 + 3m = 3m.$$

<!-- BELİRSİZ: 01:20:32–01:21:48 arasında altyazı döngüye girmiş. Hoca bir ara "eğim 0 ise yatay doğru" diyor; sonra bir öğrenci tahtada sağ tarafın türevinde $3y^2$ gibi bir hata olduğunu söylüyor ve hoca türevi $3y'$ olarak düzeltiyor. İlk hesabın tam içeriği altyazıdan anlaşılmıyor. -->

Düzeltmeden sonra $3m$'ler birbirini götürür ve $3 = 0$ çelişkisi (contradiction) elde edilir. İki öğrenci de kendi çözümlerinde aynı sonuca ulaştıklarını, "soru hatalı galiba" diye düşündüklerini söyledi. Hoca sorunun hatalı olmadığını, bu sonucun yorumlanabileceğini söyledi. Hocanın yorumu şöyleydi: Bu noktada teğet doğrusu yoktur. Eğride bir kırılma noktası (broken point) vardır, eğri o noktada türevlenemez, noktadan sonsuz tane doğru geçer. Hoca, grafiği çizmeden bile bu sonuçtan eğrinin kırıldığını anlayabileceğimizi, bunun ileride bir projede ya da model geliştirirken işe yarayabileceğini söyledi. Soruyu kafasından yazdığını, sınavda böyle gelmeyeceğini de ekledi.

> **Ders sonrası not:** Hoca $3 = 0$ çelişkisini "bu noktada kırılma var, teğet yok" diye yorumladı; doğrusu farklıdır. $x^2 + xy + y^2 = 3y$ bir elipstir ($x^2 + xy + y^2$ kısmı için $B^2 - 4AC = 1 - 4 = -3 < 0$). Elips düzgün bir eğridir, kırılma noktası yoktur. Çelişki yalnızca $(1,1)$'de $\dfrac{dy}{dx}$'in tanımsız olduğunu gösterir. $\dfrac{dx}{dy}$ hesaplanırsa: $2x\,x' + x'y + x + 2y = 3$, $(1,1)$'de $3x' + 3 = 3$, yani $x' = 0$. Demek ki $(1,1)$'de teğet **dikey**dir: $x = 1$. Genel olarak kapalı türevde $y'$'nin katsayısı sıfır çıkıyorsa, ya dikey teğet vardır ya da nokta tekil (singular) bir noktadır; hangisi olduğu ayrıca incelenmelidir. (sympy ile doğrulandı.)

**Soru:** (Bir öğrenci) Bu tür fonksiyonlar için bir formül var; yukarıda $x$'e göre, aşağıda $y$'ye göre türev alınan, başında eksi olan bir formül. Onu kullanabilir miyiz?
**Cevap:** O formülü ben size öğretmedim, şimdi kullanmayın. O ikinci dönemin konusu. Ben size derste formüllerin nasıl çıkarıldığını gösteriyorum. Formülden giderseniz işin ruhunu kavrayamazsınız. Burada türevin mantığını bildiğimiz için çıkan sonucu yorumlayabildik. Mantığı bilmeseydik "soru yanlış" deyip geçerdik.

> **Hocanın vurgusu:** Henüz öğretilmeyen formülleri ezberleyip kullanmayın. Önce işin mantığını kavrayın.

> **Ek bilgi (derste anlatılmadı):** Öğrencinin sözünü ettiği formül, $F(x,y) = 0$ biçimindeki bir eğri için $\dfrac{dy}{dx} = -\dfrac{F_x}{F_y}$ formülüdür. Burada $F_x$ ve $F_y$, $F$'nin $x$'e ve $y$'ye göre kısmi türevleridir (partial derivatives). Kısmi türevler büyük olasılıkla Matematik 2 dersinde işlenir. Bu formülde de $F_y = 0$ olduğu noktalarda $\dfrac{dy}{dx}$ tanımsız kalır; Örnek 12'deki durum budur.

### 10.2 Örnek 13: $x^2 + xy + y^2 = 3y^3$, $(1,1)$ Noktasında Teğet

Hoca daha iyi anlaşılması için soruyu değiştirdi: Sağ taraftaki $3y$ yerine $3y^3$ yazdı. $(1,1)$ noktası yine eğrinin üzerindedir: $1 + 1 + 1 = 3 \cdot 1^3$. Hoca soruya parantez içinde "(if any)" (varsa) eklenmesini önerdi. Teğet doğrusu olmak zorunda değildir. Grafikte $(1,1)$'de bir kırılma noktası varsa cevap "teğet doğrusu yoktur" olmalıdır.

$(1,1)$'deki $\dfrac{dy}{dx}$ değeri teğet doğrusunun eğimidir. İki tarafın $x$'e göre türevi:

$$2x + y + x y' + 2y \, y' = 9y^2 \, y'.$$

$(1,1)$'de $y' = m$:

$$2 + 1 + m + 2m = 9m \;\Rightarrow\; 3 = 6m \;\Rightarrow\; m = \frac{1}{2}.$$

Hoca hesap sırasında bir an "9 eksi..." diye duraksadı, sonra $6m = 3$ olduğunu söyledi. Nokta-eğim formülüyle teğet:

$$\frac{y - y_0}{x - x_0} = m \;\Rightarrow\; y - 1 = \frac{1}{2}(x - 1).$$

Hoca bu sonucun grafikte o noktada kırılma olmadığını gösterdiğini söyledi. Ardından gösterimi bir kez daha hatırlattı: Burada $y'$ ile $m$ aynı şeydir. $y'$, $\dfrac{dy}{dx}$ demektir ve geometrik yoruma göre $(x_0, y_0)$ noktasındaki teğet doğrusunun eğimi, türevin $x_0$'daki değeridir.

### 10.3 Örnek 14: $x^2 + \sin(xy) = x + y - 1$, $P(0,1)$ Noktasında Teğet (Varsa)

Hoca soruyu "biraz daha karmaşık hâle getirdi" ve öğrencilerden çözmelerini istedi. Teğet yoksa "türevlenemez, orada bir kırılma var" demeleri gerektiğini hatırlattı. Öğrencilere formülü kullanmadıklarını da sordu.

<!-- BELİRSİZ: Eğrinin denklemi altyazıda okunmuyor; kısa nottaki ekrandan alınmış denklem kullanıldı. Altyazı "1 plus x y'", $(0,1)$ noktası ve $m = 0$ sonucunu doğruluyor. 01:35:16–01:35:46 arası altyazı döngüye girmiş. -->

Önce nokta eğri üzerinde mi kontrol edilir: $0 + \sin 0 = 0 + 1 - 1$, yani $0 = 0$. Eğrinin $(0,1)$'de türevlenebilir olduğu varsayılır. İki tarafın $x$'e göre türevi:

$$2x + \cos(xy)\,(y + x y') = 1 + y'.$$

$(0,1)$'de $y' = m$:

$$0 + \cos 0 \cdot (1 + 0 \cdot m) = 1 + m \;\Rightarrow\; 1 = 1 + m \;\Rightarrow\; m = 0.$$

Teğet:

$$y - 1 = 0 \cdot (x - 0) \;\Rightarrow\; y = 1.$$

Bu yatay bir doğrudur. Hoca bunu bir şekille gösterdi: Eğri $(0,1)$ noktasında $y = 1$ yatay doğrusuna teğettir.

Hoca, haftaya bu konuyla ilgili birkaç örnek daha yapıp yeni konuya geçeceklerini söyledi. Konuların 4.–5. hafta civarında bitmesini istiyor.

## 11. Kitaptan Alıştırmalar: Rasyonel Üslü Kapalı Türev

Hoca son olarak kitaptan birkaç alıştırma paylaştı ve öğrencilerden 47. soruyu çözmelerini istedi.

### 11.1 Kitaptaki İfadenin Düzeltilmesi

Hoca kitaptaki "determine the slope of the following curves" (aşağıdaki eğrilerin eğimini bulun) ifadesinin yanlış olduğunu söyledi ve düzeltti: "Determine the slope of tangent line of the following curves at the given point" (aşağıdaki eğrilere verilen noktada teğet olan doğrunun eğimini bulun).

> **Hocanın vurgusu:** Eğrinin eğimi olmaz. Eğriye teğet olan doğrunun eğimi olur. Bu konuda kafanız karışmasın.

### 11.2 Örnek 15: $x y^{1/3} + y = 10$, $(1,8)$ Noktası (Kitap, 47. Soru)

Nokta eğri üzerindedir: $1 \cdot 8^{1/3} + 8 = 2 + 8 = 10$. İki tarafın $x$'e göre türevi alınır. İlk terim için çarpım kuralı, $y^{1/3}$ için zincir kuralı kullanılır:

$$1 \cdot y^{1/3} + x \cdot \frac{1}{3} y^{-2/3} \, y' + y' = 0.$$

Sağ taraftaki $10$'un türevi $0$'dır. $(1, 8)$'de $y' = m$ yazılır. $8^{1/3} = 2$ ve $8^{-2/3} = \dfrac{1}{4}$ olduğundan:

$$2 + \frac{1}{3} \cdot \frac{1}{4} \, m + m = 0 \;\Rightarrow\; 2 + \frac{m}{12} + m = 0 \;\Rightarrow\; \frac{13m}{12} = -2 \;\Rightarrow\; m = -\frac{24}{13}.$$

**Soru:** (Bir öğrenci) Neden sağ tarafı $0$'a eşitledik? $10$'a eşitlememiz gerekmiyor mu?
**Cevap:** Eşitliğin her iki tarafının türevini alıyoruz. $10$ sabittir ve sabitin türevi $0$'dır.

> **Hocanın vurgusu:** Kapalı türevde eşitliğin iki tarafının türevini aldığınızı unutmayın. Sabitin türevi $0$'dır. Burada hata yapmayın.

### 11.3 Örnek 16: $(x + y)^{2/3} = y$, $(4,4)$ Noktası (Kitap, 48. Soru)

Süre bittiği için hoca bu soruda yalnız türevin kabaca nasıl alındığını gösterdi, gerisini ödev bıraktı. $u = x + y$ alınır. $(u^n)' = n u^{n-1} u'$ kuralı uygulanır. $y$, $x$'e bağlı olduğu için $u' = 1 + y'$ olur. Sağ tarafın türevi $y'$'dür:

$$\frac{2}{3}(x + y)^{\frac{2}{3} - 1}(1 + y') = y'.$$

Sayısal sonuç için "Örnek Sorular" bölümüne bakın.

## Örnek Sorular

Aşağıdaki sorular, hocanın derste öğrencilere çözmeleri için verdiği ya da ödev bıraktığı sorulardır.

**Soru 1** (derste sözlü, 00:10:35 ve 00:12:26) — \*\*\* işaretli soru (büyük olasılıkla). $h(x) = f(g(x))$, $p(x) = g(f(x))$ ve Bölüm 3'teki tablo veriliyor. $h'(3)$'ü bulun.

> **Çözüm (derste verildi):** $h'(3) = f'(g(3)) \cdot g'(3) = f'(1) \cdot 20 = 100$. Diğer şıklar ödev bırakıldı; $p'(x) = g'(f(x)) \cdot f'(x)$ kullanılır.

**Soru 2** (derste sözlü, 00:23:26) — $f$ türevlenebilir, grafiği $(1,4)$'ten geçiyor ve bu noktadaki teğeti $y = 3x + 1$. $g(x) = f(x^2)$ ise a) $g(1)$, b) $g'(x)$, c) $g'(1)$, d) $g$'nin grafiğine $x = 1$'de teğet olan doğruyu bulun.

> **Çözüm (derste verildi):** a) $4$, b) $f'(x^2) \cdot 2x$, c) $6$, d) $y = 6x - 2$.

**Soru 3** (derste sözlü, 00:36:04) — $f'(0) = 3$, $f'(1) = 5$ ve $g(x) = f(\sin x)$. $g'(0)$, $g'(\pi/2)$ ve $g'(\pi)$'yi bulun.

> **Çözüm (derste verildi):** $g'(x) = f'(\sin x)\cos x$; $g'(0) = 3$, $g'(\pi/2) = 0$, $g'(\pi) = -3$.

**Soru 4** (derste sözlü, 01:14:03, ödev) — $x^2 + \sin(xy) = y^2$ için $(\star)$'dan $\dfrac{dy}{dx}$'i, $(\star\star)$'dan $\dfrac{dx}{dy}$'yi bulun ve çarpımlarının $1$ olduğunu gösterin.

> **Çözüm (derste verilmedi):** $(\star)$'dan $y'\big(2y - x\cos(xy)\big) = 2x + y\cos(xy)$, yani $\dfrac{dy}{dx} = \dfrac{2x + y\cos(xy)}{2y - x\cos(xy)}$. $(\star\star)$'dan $x'\big(2x + y\cos(xy)\big) = 2y - x\cos(xy)$, yani $\dfrac{dx}{dy} = \dfrac{2y - x\cos(xy)}{2x + y\cos(xy)}$. Çarpım $1$'dir (paydalar sıfırdan farklıysa). sympy ile doğrulandı.

**Soru 5** (derste sözlü, 01:16:11) — $x^2 + xy + y^2 = 3y$ eğrisine $(1,1)$ noktasında teğet olan doğrunun denklemini (varsa) bulun.

> **Çözüm (derste verildi, ders sonrası düzeltildi):** Kapalı türev $3 = 0$ çelişkisini verir; $\dfrac{dy}{dx}$ bu noktada tanımsızdır. $\dfrac{dx}{dy} = 0$ olduğundan teğet dikeydir: $x = 1$. Hocanın "kırılma var, teğet yok" yorumu için Bölüm 10.1'deki ders sonrası nota bakın.

**Soru 6** (derste sözlü, 01:27:28) — $x^2 + xy + y^2 = 3y^3$ eğrisine $(1,1)$ noktasında teğet olan doğruyu (varsa) bulun.

> **Çözüm (derste verildi):** $m = \dfrac{1}{2}$, teğet $y - 1 = \dfrac{1}{2}(x - 1)$.

**Soru 7** (derste sözlü, 01:33:17) — $x^2 + \sin(xy) = x + y - 1$ eğrisine $(0,1)$ noktasında teğet olan doğruyu (varsa) bulun.

> **Çözüm (derste verildi):** $m = 0$, teğet $y = 1$ (yatay doğru).

**Soru 8** (derste sözlü, 01:40:00; kitap 47) — $x y^{1/3} + y = 10$ eğrisine $(1,8)$ noktasında teğet olan doğrunun eğimini bulun.

> **Çözüm (derste verildi):** $m = -\dfrac{24}{13}$.

**Soru 9** (derste sözlü, 01:45:28; kitap 48, ödev) — $(x + y)^{2/3} = y$ eğrisine $(4,4)$ noktasında teğet olan doğrunun eğimini bulun.

> **Çözüm (derste verilmedi):** Türev $\dfrac{2}{3}(x+y)^{-1/3}(1 + y') = y'$. $(4,4)$'te $(x+y)^{-1/3} = 8^{-1/3} = \dfrac{1}{2}$, böylece $\dfrac{1}{3}(1 + m) = m \Rightarrow 1 + m = 3m \Rightarrow m = \dfrac{1}{2}$. Nokta eğri üzerindedir: $8^{2/3} = 4$. sympy ile doğrulandı.

## Dersin Toparlaması

Ders, zincir kuralının farklı biçimlerde kullanımıyla başladı: köklü, kuvvetli ve trigonometrik bileşkeler, tablodan türev hesabı ve teğet doğrusu soruları. Hoca bu soruların sınavda nasıl modifiye edilebileceğini, örneğin çarpım kuralıyla birleştirilip tanjant, sekant ya da üstel fonksiyon eklenerek zorlaştırılabileceğini gösterdi. Ardından yüksek mertebeden türevlerin, birinci türevin tekrar tekrar türevi olduğunu bir örnekle işledi.

Dersin ikinci yarısı kapalı türeve ayrıldı. Açık form ($y = f(x)$ ya da $x = g(y)$) ile kapalı form ($x$ ve $y$'nin birlikte bulunduğu denklem) ayırt edildi. Kapalı formda $\dfrac{dy}{dx}$ sormanın, eğrinin yerel bir parçası üzerinde çalışmak anlamına geldiği birim çember örneğiyle gösterildi. Yöntem şudur: $y$'nin $x$'e bağlı olduğu kabul edilir, eşitliğin iki tarafının $x$'e göre türevi alınır ve $y$ içeren terimlerde zincir kuralı uygulanır. $\dfrac{dy}{dx}$ ile $\dfrac{dx}{dy}$'nin çarpımının $1$ olduğu görüldü. Hoca, haftaya kapalı türevle ilgili birkaç örnek daha çözüp yeni konuya geçeceklerini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
