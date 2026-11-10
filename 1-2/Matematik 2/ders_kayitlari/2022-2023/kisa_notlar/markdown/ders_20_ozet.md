# Ders 20 Çalışma Özeti

## Genel Konular

- Bu ders 2 Mayıs 2023 Salı günü yapıldı. 1. vize sonrası ilk kayıtlı derstir.
- Dersin ilk yarısında 1. vizenin A grubu soruları (MAT2 vize-sorular GrA) üzerinden geçildi.
- İkinci yarıda yeni konuya geçildi: iki katlı (çift katlı) integraller (double integrals).
- Fubini teoremi (Fubini's theorem), dikdörtgen ve eğrilerle sınırlı bölgeler üzerinde integral işlendi.
- İntegrasyon bölgesini çizme ve integrasyon sırasını değiştirme (change of order of integration) gösterildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Çok katlı integrallerden finalde en az 3-5 soru gelebilir. Final integral ağırlıklıdır. Kısmi türev ve maksimum-minimum konularından da soru gelecek.
- "İntegrasyon bölgesini çiziniz, integrasyon sırasını değiştiriniz, değerini hesaplayınız" tipi sorudan mutlaka soru gelir. Hoca bunu "İstanbul'dan Sivas'a giderken Ankara'dan geçmek" gibi zorunlu bir geçiş noktası olarak anlattı.
- $\iint_D 1\,dA$ alanı verir. İntegrand 1'den farklı bir fonksiyon ise hacmi verir.
- Çok katlı integral kütle, ağırlık merkezi, hacim ve yüzey alanı hesaplarında kullanılır.
- Tek katlı integral bilgisi eksik olan tekrar etmelidir. Çift katlı integral sonunda tek katlı integrale indirgenerek çözülür.
- Vize soruları elementer ama çeldiricili. Basit sorularda daha dikkatli olmak gerekir.
- Kendi başına soru çözmek verimi "%50'den %99'a" çıkarır.

## Kısa Tekrar Notları

- **Dikdörtgen bölgede Fubini:** $R=[a,b]\times[c,d]$ ise $\displaystyle\iint_R f\,dA=\int_a^b\!\int_c^d f(x,y)\,dy\,dx=\int_c^d\!\int_a^b f(x,y)\,dx\,dy$.
- **Eğriler arası bölge:** $D=\{a\le x\le b,\;g_1(x)\le y\le g_2(x)\}$ ise $\displaystyle\iint_D f\,dA=\int_a^b\!\int_{g_1(x)}^{g_2(x)} f(x,y)\,dy\,dx$.
- İçteki integral alınırken diğer değişken sabit gibi düşünülür.
- **Alan:** $\iint_D 1\,dA$. **Hacim:** $\iint_D f(x,y)\,dA$ ($f\ge0$).
- **Sıra değiştirme adımları:** bölgeyi çiz, kesim noktalarını bul, dış değişkenin sabit sınırlarını yaz, iç değişkeni eğriler cinsinden yaz.
- Bölge dönüşümü için Jacobian kullanılır. Hoca bunu sonraki haftaya bıraktı.

## Detaylı Açıklamalar

### 1. Vize Soruları (A Grubu)

**Soru 1:** $a_n$ dizisinin limiti $a$ ise $a_{n+1}$'in limiti de $a$'dır. Bunu kullanarak özyinelemeli dizinin limiti bulunur. Altyazıda dizinin formülü net değil.

**Soru 2:** $a_n=n-\sqrt{n^2-1}$ dizisi için hangisi doğrudur?
- $\infty-\infty$ belirsizliği var. Eşleniğiyle çarpılır: $a_n=\dfrac{1}{n+\sqrt{n^2-1}}$.
- $n\to\infty$ iken $a_n\to0$. Dizi pozitif ve azalandır.
- Doğru şık: büyük olasılıkla A) Azalandır.

**Soru 3:** $\displaystyle\sum_{n=2}^{\infty}\frac{(-1)^n+2^n+3^n}{4^n}$ serisinin toplamı nedir?
- Seri üç geometrik seriye ayrılır.
- $\displaystyle\sum_{n=2}^{\infty}\left(-\tfrac14\right)^n=\frac{1}{16}\cdot\frac{1}{1+\frac14}=\frac{1}{20}$.
- $\displaystyle\sum_{n=2}^{\infty}\left(\tfrac12\right)^n=\frac14\cdot\frac{1}{1-\frac12}=\frac12$.
- $\displaystyle\sum_{n=2}^{\infty}\left(\tfrac34\right)^n=\frac{9}{16}\cdot\frac{1}{1-\frac34}=\frac94$.
- Toplam: $\dfrac{1}{20}+\dfrac{10}{20}+\dfrac{45}{20}=\dfrac{14}{5}$. Hoca şıkkı söylemedi; şık harfi büyük olasılıkla (ekrandan) A.

**Soru 4:** $\displaystyle\lim_{x\to0}\frac{(e^x-x-1)^2}{x^2-\ln(1+x^2)}$ (ifade büyük olasılıkla (ekrandan)). Hoca bu soruyu açmadı. Çözümü "Ders sonrası notlar" kısmındadır.

**Soru 5 (eşleştirme):**
- "$\sum a_n$ ıraksak iken $\sum 1/a_n$ ıraksaktır" gibi ifadelerle genel terimler eşleştirildi.
- $1/n^5$ gibi bir terim için $\sum 1/a_n$ yakınsak olmaz, ıraksak olur. Bu yüzden o eşleşme elendi.
- $a_n\to\infty$ olan bir terimde $\sum a_n$ ıraksak, $\sum 1/a_n$ yakınsak olabilir.
- Hoca doğru şıkkın A olduğunu söyledi. Terimlerin tam hâli altyazıda net değil.

**Soru 6 (serilerin karakteri):**
- Payın derecesi paydanınkinden büyükse genel terim sıfıra gitmez. Seri ıraksaktır.
- $1/n^{4/3}$ gibi $p>1$ olan seri yakınsaktır.
- Şıklar bu iki gözlemle elendi.

**Soru 7 (hangi test kullanılır):** $\displaystyle\sum_{n=2}^{\infty}\frac{1}{n(\ln n)^5}$ için integral testi (integral test) uygundur.
- $u=\ln x$, $du=dx/x$ dönüşümü yapılır.
- $\displaystyle\int_2^\infty\frac{dx}{x(\ln x)^5}=\left[-\frac{1}{4(\ln x)^4}\right]_2^\infty=\frac{1}{4(\ln2)^4}$.
- İntegral sonlu olduğu için seri yakınsaktır. Doğru şık: C.

**Kuvvet serisi sorusu:** Yakınsaklık aralığı oran testiyle bulunur: $\lim\left|\dfrac{a_{n+1}}{a_n}\right|<1$. Uç noktalar ayrı ayrı denenir. Yakınsak olan uç aralığa dahil edilir.

**Kutupsal alan sorusu:** Çemberin içinde, kardiyoidin dışında kalan bölgenin alanını veren integral soruldu. Hoca "çözüm bile istememişler, doğrudan integrali sormuşlar" dedi.

**Soru 12:** 
$$f(x,y)=\begin{cases}\dfrac{5xy^2}{x^2+y^4}, & (x,y)\ne(0,0)\\[4pt] 0, & (x,y)=(0,0)\end{cases}$$
I. Bütün $\mathbb{R}^2$'de tanımlıdır. II. $(0,0)$'da limiti 0'dır. III. $(0,0)$'da süreklidir. Hangileri doğrudur?
- $y=mx^2$ boyunca limit 0 çıkıyor. Bu yeterli değil.
- $x=my^2$ boyunca: $\displaystyle\lim_{y\to0}\frac{5my^2\cdot y^2}{m^2y^4+y^4}=\frac{5m}{1+m^2}$.
- Sonuç $m$'ye bağlı. Limit yoktur, fonksiyon süreksizdir.
- Yalnız I doğrudur. Şık harfi büyük olasılıkla (ekrandan) B; altyazıda net değil.

**Parametrik sorusu:** Parametrik verilen eğrinin $(0,0)$'daki ikinci türevi soruldu. Hoca benzerinin derste çözüldüğünü söyledi.

### İki Katlı İntegraller

**Dikdörtgen bölge:** $x$, $a$'dan $b$'ye; $y$, $c$'den $d$'ye değişiyor.
$$\int_a^b\!\int_c^d 1\,dy\,dx=\int_a^b (d-c)\,dx=(d-c)(b-a)$$
Bu, dikdörtgenin alanıdır.

**Tek katlı ve çift katlı integralle alan:** $y=d$ doğrusunun altında, $x=a$ ile $x=b$ arasındaki alan:
- Tek katlı: $\int_a^b d\,dx=d(b-a)$.
- Çift katlı: $\int_a^b\int_0^d dy\,dx=\int_a^b d\,dx=d(b-a)$.
- İki yol aynı sonucu verir.

**İkinci Fubini teoremi (eğriler arası bölge):** Üstteki eğri $y=\varphi_1(x)$, alttaki $y=\varphi_2(x)$ ise:
$$\iint_D f\,dA=\int_a^b\!\int_{\varphi_2(x)}^{\varphi_1(x)} f(x,y)\,dy\,dx$$
"Üstteki eğriden alttakini, sağdaki doğrudan soldakini çıkarıyoruz."

**Hacim örneği:** $\displaystyle\int_1^2\!\int_3^4 x^2y\,dx\,dy$.
- İçte $x$'e göre: $\left[\dfrac{x^3}{3}\right]_3^4 y=\dfrac{64-27}{3}y=\dfrac{37}{3}y$.
- Dışta $y$'ye göre: $\dfrac{37}{3}\left[\dfrac{y^2}{2}\right]_1^2=\dfrac{37}{3}\cdot\dfrac32=\dfrac{37}{2}$.
- Sonuç bir hacimdir (birim küp).

### Problemler: Eşitlikleri Gösteriniz

**Örnek 1:** $\displaystyle\int_0^1\!\int_2^4 x^2y\,dy\,dx=2$.
- İçte $y$'ye göre: $x^2\left[\dfrac{y^2}{2}\right]_2^4=x^2(8-2)=6x^2$.
- Dışta: $\int_0^1 6x^2\,dx=2x^3\Big|_0^1=2$.

**Örnek 2:** $\displaystyle\int_0^1\!\int_0^1 \frac{x^2}{1+y^2}\,dy\,dx=\frac{\pi}{12}$.
- İçte: $x^2\arctan y\Big|_0^1=x^2\cdot\dfrac{\pi}{4}$.
- Dışta: $\dfrac{\pi}{4}\cdot\dfrac{x^3}{3}\Big|_0^1=\dfrac{\pi}{12}$.

**Örnek 3:** $\displaystyle\int_0^\pi\!\int_0^{\sin x} y\,dy\,dx=\frac{\pi}{4}$.
- İçte: $\left[\dfrac{y^2}{2}\right]_0^{\sin x}=\dfrac{\sin^2x}{2}$.
- Dışta: $\displaystyle\int_0^\pi\frac{1-\cos2x}{4}\,dx=\frac{\pi}{4}$.

**Örnek 4 (bölge üzerinde integral):** $f(x,y)=x+y$, $D=\{0\le x\le1,\;0\le y\le x\}$.
$$\iint_D (x+y)\,dA=\int_0^1\!\int_0^x (x+y)\,dy\,dx$$
- İçte $y$'ye göre: $xy+\dfrac{y^2}{2}$, sınırlar konur. Sonra $x$'e göre integral alınır.
- Hoca yalnız yöntemi anlattı, sonucu hesaplamadı ($\tfrac12$ çıkar).

### İntegrasyon Sırasını Değiştirme

**Örnek 5:** $\displaystyle\int_0^1\!\int_0^x dy\,dx$.
- Bölge: $0\le x\le1$, $0\le y\le x$. Yani $y=0$, $y=x$ ve $x=1$ arasındaki üçgen.
- Kesim noktası $(1,1)$. Dışta $y$: $0$'dan $1$'e. İçte $x$: $x=y$ doğrusundan $x=1$'e.
- Yeni hâli: $\displaystyle\int_0^1\!\int_y^1 dx\,dy$.
- İki hâl de aynı sonucu verir: $\int_0^1 x\,dx=\tfrac12$ ve $\int_0^1(1-y)\,dy=\tfrac12$ birim kare.

**Örnek 6 (elips bölgesi):** Sınırları $y=\pm\sqrt{4-2x^2}$ ve $0\le x\le\sqrt2$ olan integral.
- $y^2=4-2x^2$ ise $\dfrac{x^2}{2}+\dfrac{y^2}{4}=1$. Bu bir elipstir. $x$ eksenini $\sqrt2$'de, $y$ eksenini $\pm2$'de keser.
- Bölge elipsin sağ yarısıdır.
- Sıra değişince: dışta $y$, $-2$'den $2$'ye. İçte $x$, $0$'dan $\sqrt{\dfrac{4-y^2}{2}}$'ye.

**Örnek 7 (sıra değiştirmek neden gerekli):** $e^{y^2}$'nin $y$'ye göre ilkeli elementer fonksiyonlarla yazılamaz. Bu yüzden bu integral doğrudan alınamaz, sıra değiştirilir.
- Doğru kurulmuş hâli "Ders sonrası notlar" kısmındadır.

**Son örnek:** $\displaystyle\int_{-1}^0\!\int_{-y}^1 e^{x^2}\,dx\,dy$. Aynı sebeple sıra değiştirilir. Hoca çözümü vermedi.

### Ders sonrası notlar

- **Vize Soru 4'ün çözümü:**
  - $e^x-x-1\approx\dfrac{x^2}{2}$ olduğundan pay $\approx\dfrac{x^4}{4}$.
  - $\ln(1+x^2)\approx x^2-\dfrac{x^4}{2}$ olduğundan payda $\approx\dfrac{x^4}{2}$.
  - Limit $\dfrac{1/4}{1/2}=\dfrac12$. Şık harfi büyük olasılıkla (ekrandan) B.
- **Örnek 7 düzeltmesi:** Hoca tahtaya $\int_0^1\!\int_0^x e^{y^2}\,dy\,dx$ yazdı. Bu bölgede sıra değişince $\int_0^1\!\int_y^1 e^{y^2}\,dx\,dy=\int_0^1(1-y)e^{y^2}\,dy$ çıkar. Bu da elementer olarak alınamaz. Hocanın "türevi burada var, $u$ dönüşümü yaparız" dediği çözüm, sınırları $x\le y\le1$ olan standart örnekte işler:
  - $\displaystyle\int_0^1\!\int_x^1 e^{y^2}\,dy\,dx=\int_0^1\!\int_0^y e^{y^2}\,dx\,dy=\int_0^1 y\,e^{y^2}\,dy=\frac{e-1}{2}$.
- Hacim örneğindeki sayısal sonuç ($\tfrac{37}{2}$) derste okunmadı, hesaplanarak eklendi.
- Ders başında "x'den 2x'e kadar" sınırlı bir sıra değiştirme sorusundan söz edildi. Hoca tahtada daha basit olan $0\le y\le x$ bölgesini çözdü.
- **Aradaki haftalar:** Dersin başında 1. vizenin soruları çözülüyor. Bir öğrenci notların ne zaman açıklanacağını soruyor, hoca "muhtemelen bu hafta" diyor. Yani 1. vize 18 Nisan (ders 16) ile 2 Mayıs arasında yapılmış. Arşivde 24 Nisan kaydı boş, 18 ve 19 numaralı kayıtlar yok; bu arada tatil günleri var. Vizenin kesin tarihi altyazıda geçmiyor.
- Kalan konular için hoca "üç ya da dört haftamız var, integral iki haftada biter, sonra genel soru çözeriz" dedi. Jacobian sonraki haftaya kaldı.

İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
