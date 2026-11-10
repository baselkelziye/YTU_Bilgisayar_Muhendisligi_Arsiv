# Ders 26 Çalışma Özeti

## Genel Konular

- Ders tarihi: 30 Aralık 2020 Çarşamba.
- Disk yönteminin (disk method) tekrarı: $x$ ekseni ve $y$ ekseni etrafında dönme.
- Pul yöntemi (washer method): iki grafik arasındaki bölgenin döndürülmesi.
- Kabuk yöntemi (shell method, cylindrical shells): silindirik kabuğun hacminin çıkarılışı.
- Hangi yöntemin seçileceği: tarayan çubuk (scanning bar) ile dönme ekseni (rotation axis) arasındaki ilişki.
- Dönme ekseni koordinat ekseni olmayan sorular ($y=-1$, $x=-\pi/2$, $x=3\pi/2$ doğruları).
- Çok sayıda örnek: integral modelinin (integration model) kurulması.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Vize notları:** Vize notlarının listesi hocaya ulaştı. Notlar aynı akşam sisteme yüklenecek.
- **Disk ve pul yönteminin şartı:** Bölgeyi tarayan çubuk dönme eksenine **dik** olmalı. Aksi durumda disk ya da pul elde edilmez.
- **Kabuk yönteminin şartı:** Bölgeyi tarayan çubuk dönme eksenine **paralel** olmalı. Aksi durumda kabuk elde edilmez.
- **Çubuğun kalınlığı:** Kalınlık $dx$ ise bütün bilgiler $x$ cinsinden, $dy$ ise $y$ cinsinden yazılır.
- **Sık yapılan hata:** Pul yönteminde $(r_1-r_2)^2$ yazmak yanlıştır. Doğrusu $r_1^2-r_2^2$'dir. Ezbere giden öğrenci bu hatayı yapar.
- **Yarıçap, yükseklik ve kalınlık pozitif olmalı:** Gerekirse mutlak değer kullanılır, integral parçalara ayrılır.
- **Yöntem seçimi:** Hangi yöntemin daha uygun olduğunu bulmak sizin becerinizdir. Bazen disk, bazen kabuk yöntemi işlemi çok kolaylaştırır.
- **Sınav:** Bu tarz sorularda genellikle yalnız integral modeli istenir. İntegralin hesaplanması nadiren sorulur.
- **Ezber yerine mantık:** "İsmi ezberlemeyin, ismin arkasındaki mantığa odaklanın."

## Kısa Tekrar Notları

- **Disk yöntemi ($x$ ekseni etrafında, dikey çubuk):**
  - $dV=\pi\,[f(x)]^2\,dx$, $V=\pi\displaystyle\int_a^b [f(x)]^2\,dx$.
- **Disk yöntemi ($y$ ekseni etrafında, yatay çubuk):**
  - $x=F(y)$ ise $V=\pi\displaystyle\int_c^d [F(y)]^2\,dy$.
- **Pul yöntemi:**
  - $dV=\pi\,(r_1^2-r_2^2)\,h$. Burada $r_1$ dış yarıçap, $r_2$ iç yarıçap, $h$ çubuğun kalınlığı.
  - $x$ ekseni etrafında: $V=\pi\displaystyle\int_a^b \left([f(x)]^2-[g(x)]^2\right)dx$.
  - Pul yöntemi, disk yönteminin genelleştirilmiş hâlidir: iki silindirin hacimleri farkı.
- **Kabuk yöntemi ($y$ ekseni etrafında, dikey çubuk):**
  - $dV=2\pi\cdot(\text{yarıçap})\cdot(\text{yükseklik})\cdot(\text{kalınlık})=2\pi\,x\,f(x)\,dx$.
  - $V=2\pi\displaystyle\int_a^b x\,f(x)\,dx$.
  - Genel hâl: $V=2\pi\displaystyle\int |\text{yarıçap}|\cdot|\text{yükseklik}|\,d(\text{değişken})$.
- **Dönme ekseni bir doğruysa:** Yarıçap, çubuk ile dönme ekseni arasındaki uzaklıktır. İki nokta arası uzaklık formülüyle bulunur.

| Yöntem | Çubuk ile dönme ekseni | Elde edilen parça |
|---|---|---|
| Disk | Dik | Disk |
| Pul | Dik | Pul (ortası oyuk disk) |
| Kabuk | Paralel | Silindirik kabuk |

## Detaylı Açıklamalar

### Disk yönteminin tekrarı

- $y=f(x)$ grafiğinin altında, kalınlığı $dx$ olan dikey bir çubuk düşünün.
- $dx$ yeterince küçük olduğu için çubuk dikdörtgen kabul edilir, hata ihmal edilir.
- Çubuk $x$ ekseni etrafında döndürülünce yarıçapı $f(x)$, kalınlığı $dx$ olan bir disk oluşur.
- Diskin hacmi: $dV=\pi r^2 h=\pi [f(x)]^2\,dx$.
- Bölge bu çubukla taranır ve iki taraf integrallenir: $V=\pi\displaystyle\int_a^b [f(x)]^2\,dx$.
- $y$ ekseni etrafında dönmede bölgeyi yatay çubukla taramak gerekir. Çubuğun uzunluğu $x=F(y)$, kalınlığı $dy$ olur.

### Pul yöntemi

- Bölge $y=f(x)$ (üstte) ile $y=g(x)$ (altta) arasında, $x=a$ ile $x=b$ arasında olsun.
- Dikey çubuk $x$ ekseni etrafında döndürülünce ortası oyuk bir disk, yani pul (washer) oluşur.
- Pulun hacmi: dış silindirin hacmi eksi iç silindirin hacmi.
  - $dV=\pi r_1^2 h-\pi r_2^2 h=\pi\,(r_1^2-r_2^2)\,dx$.
  - $r_1=f(x)$, $r_2=g(x)$.
- Bütün pullar birleştirilir (integrallenir):

$$V=\pi\int_a^b \left([f(x)]^2-[g(x)]^2\right)dx$$

- Bir öğrenci "doğrudan $r_1-r_2$ deyip yapsak olmaz mı?" diye sordu. Hoca: Sınavda doğrudan $f^2-g^2$ yazabilirsiniz. Ama $(r_1-r_2)^2$ yazmak yanlıştır.

### Örnek 1: $x=y^2$ ve $x-y=2$ arasındaki bölge

- **Soru:** $R$ bölgesi $x=y^2$ ve $x-y=2$ ile sınırlı.
  - a) Alanı veren integrali $y$'ye göre yazın.
  - b) $R$ bölgesi $y$ ekseni etrafında döndürülünce oluşan cismin hacmini veren integrali yazın.
- **Not:** Hoca soruyu önce yanlış yazdı. Doğru ile parabol kesişmiyordu. Sonra doğruyu $x-y=2$ olarak düzeltti ve alanı $y$'ye göre istedi.
- **Kesişim noktaları:** $x=2+y$ ile $x=y^2$ ortak çözülür.
  - $y^2-y-2=0\Rightarrow (y-2)(y+1)=0\Rightarrow y=-1,\ y=2$.
- **a) Alan (yatay çubuk):**
  - Sağ uç nokta her zaman $x=2+y$ doğrusu üzerinde, sol uç nokta her zaman $x=y^2$ parabolü üzerinde.
  - Bu yüzden integrali parçalamaya gerek yok.

$$A=\int_{-1}^{2}\left[(2+y)-y^2\right]dy=\frac{9}{2}$$

- **b) $y$ ekseni etrafında hacim (pul yöntemi, yatay çubuk):**
  - Dış yarıçap $r_1=2+y$, iç yarıçap $r_2=y^2$, kalınlık $dy$.

$$V=\pi\int_{-1}^{2}\left[(2+y)^2-(y^2)^2\right]dy=\frac{72\pi}{5}$$

- Hoca hesaplamayı ödev bıraktı. Sonuçlar bu özette eklendi.

### Örnek 2: $y=x^2$, $x=1$, $x=2$, $y=0$

- **Soru:** $R$ bölgesi $y=x^2$, $x=1$, $x=2$ ve $y=0$ doğrularıyla sınırlı.
  - a) $R$, $y=0$ doğrusu ($x$ ekseni) etrafında döndürülünce oluşan hacmin integrali.
  - b) $R$, $y=-1$ doğrusu etrafında döndürülünce oluşan hacmin integrali.
- **a) Disk yöntemi (dikey çubuk):**
  - Yarıçap $x^2$, kalınlık $dx$.

$$V=\pi\int_1^2 (x^2)^2\,dx=\pi\int_1^2 x^4\,dx=\pi\left(\frac{32}{5}-\frac{1}{5}\right)=\frac{31\pi}{5}$$

- **b) Pul yöntemi ($y=-1$ etrafında):**
  - Çubuğu dönme eksenine kadar uzatın. Uzantısı dönme eksenine diktir.
  - Dış yarıçap: çubuğun üst ucunun $y=-1$ doğrusuna uzaklığı, $r_1=x^2+1$.
  - İç yarıçap: $x$ ekseninin $y=-1$ doğrusuna uzaklığı, $r_2=1$.

$$V=\pi\int_1^2\left[(x^2+1)^2-1^2\right]dx=\frac{163\pi}{15}$$

- Hoca: "İşin mantığını anladığınız an, farklı tipte bir soru geldiğinde hemen modelleyebilirsiniz."

### Örnek 3: $y=e^x$, $y=\ln 3$ ve $x=0$

- **Soru (büyük olasılıkla (ekrandan)):** $R$ bölgesi $y=e^x$, $y=\ln 3$ doğrusu ve $x=0$ doğrusuyla sınırlı.
  - a) $R$, $x$ ekseni etrafında döndürülünce hacmin integrali.
  - b) $R$, $y$ ekseni etrafında döndürülünce hacmin integrali.
  - c) şıkkı haftaya bırakıldı.
- **Kesişim:** $e^x=\ln 3\Rightarrow x=\ln(\ln 3)$.
  - Hoca önce kesişimi zihinden hesaplamaya çalıştı, olmayınca adım adım çözdü (altyazıda bu kısım net değil): "Zihnimizden yaparken hata yapabiliyoruz. Adım adım işlem yapmak daha mantıklı."
- **a) Pul yöntemi (dikey çubuk):**
  - Dış yarıçap $r_1=\ln 3$, iç yarıçap $r_2=e^x$.

$$V=\pi\int_0^{\ln(\ln 3)}\left[(\ln 3)^2-e^{2x}\right]dx$$

- **b) Disk yöntemi (yatay çubuk):**
  - Kalınlık $dy$ olduğu için $y=e^x$ yerine $x=\ln y$ yazılır.
  - Bölgede boş kısım yok, bu yüzden pul değil disk oluşur. Yarıçap $\ln y$.
  - $y$, $1$'den ($e^0$) $\ln 3$'e kadar değişir.

$$V=\pi\int_1^{\ln 3}(\ln y)^2\,dy$$

- Bu integral kısmi integrasyonla (integration by parts) ya da indirgeme formülüyle hesaplanır.

### Kabuk yöntemi

- $y=f(x)$ grafiğinin altında, $y$ eksenine $x$ uzaklıkta, kalınlığı $dx$ olan dikey bir çubuk düşünün.
- Çubuk $y$ ekseni etrafında döndürülünce silindirik bir kabuk (cylindrical shell) oluşur.
  - Kabuğun yarıçapı $x$.
  - Kabuğun yüksekliği $f(x)$.
  - Kabuğun kalınlığı $dx$.
- **Hacmin bulunuşu:** Kabuk dikey bir doğru boyunca kesilip açılır. Yaklaşık bir dikdörtgenler prizması elde edilir.
  - Bir kenarı çemberin çevresi: $2\pi x$.
  - Bir kenarı yükseklik: $f(x)$.
  - Kalınlığı: $dx$.
  - $dV=2\pi\,x\,f(x)\,dx$.
- İntegrallenince:

$$V=2\pi\int_a^b x\,f(x)\,dx$$

- **Hocanın benzetmesi (A4 kâğıdı):**
  - Bir A4 kâğıdının hacmi yok gibidir.
  - Kâğıdı kıvırıp boru yaparsanız bir ağaç kabuğu elde edersiniz.
  - Kalınlığı $dx$, yarıçapı $x$, yüksekliği $f(x)$.
  - Kâğıdı tekrar açınca uzunluğu çemberin çevresi olan $2\pi x$ olur.
  - İç içe geçmiş kabuklar üst üste gelince ağacı oluşturur. Bunları integralle birleştirince cismin hacmi bulunur.

### Örnek 4: $y=\sin x$, $[0,2\pi]$

- **Soru:** $R$ bölgesi $y=\sin x$ grafiği ile $x$ ekseni arasında, $0\le x\le 2\pi$.
- **a) $x$ ekseni etrafında (disk yöntemi en uygunu):**

$$V=\pi\int_0^{2\pi}\sin^2 x\,dx=\pi\int_0^{2\pi}\frac{1-\cos 2x}{2}\,dx=\pi^2$$

- Hoca sonucu ödev bıraktı.
- **b) $y$ ekseni etrafında (kabuk yöntemi en uygunu):**
  - Disk yöntemi burada çok karmaşık integraller verir.
  - **Dikkat:** $\pi<x<2\pi$ aralığında $\sin x$ negatiftir. Yükseklik pozitif olmalı, bu yüzden integral ikiye ayrılır.

$$V=2\pi\left[\int_0^{\pi}x\sin x\,dx+\int_{\pi}^{2\pi}x\,(-\sin x)\,dx\right]=2\pi(\pi+3\pi)=8\pi^2$$

- Hoca: "Bazı öğrenciler bu hatayı yapıyor. Yarıçap, yükseklik ve kalınlık pozitif olmalı."

### Örnek 5: $y=\sin x$, $[0,\pi]$, dikey doğrular etrafında

- **Soru:** $R$ bölgesi $y=\sin x$ ile $x$ ekseni arasında, $0\le x\le\pi$.
- **a) $x=-\pi/2$ doğrusu etrafında (kabuk yöntemi):**
  - Dikey çubuk dönme eksenine paraleldir, kabuk oluşur.
  - Yarıçap: $(x,\sin x)$ ile $(-\pi/2,\sin x)$ noktaları arası uzaklık.
  - $y$ koordinatları aynı, yarıçap $\left|x-(-\pi/2)\right|=x+\pi/2$. Bölgede $x\ge0$ olduğu için bu ifade pozitiftir.
  - Yükseklik $\sin x$, bu aralıkta pozitiftir.

$$V=2\pi\int_0^{\pi}\left(x+\frac{\pi}{2}\right)\sin x\,dx=2\pi\int_0^{\pi}x\sin x\,dx+\pi^2\int_0^{\pi}\sin x\,dx=4\pi^2$$

- Birinci integral kısmi integrasyonla hesaplanır.
- **Neden yatay çubuk değil?** Bir öğrencinin sorusu üzerine hoca açıkladı:
  - Yatay çubuk kullanılırsa pul elde edilir, kalınlık $dy$ olur.
  - O zaman $x=\arcsin y$ yazmak gerekir. Bu her yerde uygun değildir ve işi karmaşıklaştırır.
  - $y=\sin x$ biçimi $x=\arcsin y$ biçiminden işlem açısından daha düzgündür.
- **b) $x=3\pi/2$ doğrusu etrafında (kabuk yöntemi):**
  - Yarıçap: $3\pi/2-x$ (bölgede pozitif).

$$V=2\pi\int_0^{\pi}\left(\frac{3\pi}{2}-x\right)\sin x\,dx=4\pi^2$$

- Hoca: "Cevabı bulmayın, sadece integrali bulun." Hesap ödev olarak bırakıldı.

### Örnek 6: $x=y-y^2$ ve $y$ ekseni arasındaki bölge

- **Soru:** $R$ bölgesi $x=y-y^2$ eğrisi ile $y$ ekseni arasında, $0\le y\le1$.
- **a) $x$ ekseni etrafında (kabuk yöntemi, yatay çubuk):**
  - Yatay çubuk $x$ eksenine paraleldir. Kalınlık $dy$.
  - Yarıçap $y$, yükseklik $y-y^2$ (bölgede ikisi de pozitif).

$$V=2\pi\int_0^1 y\,(y-y^2)\,dy=\frac{\pi}{6}$$

- **b) $y=-1$ doğrusu etrafında:**
  - Yarıçap $y+1$, yükseklik $y-y^2$.

$$V=2\pi\int_0^1 (y+1)(y-y^2)\,dy=\frac{\pi}{2}$$

- **Neden kabuk?** Bir öğrenci sordu. Dikey çubuk kullanılırsa $y$'yi $x$ cinsinden yazmak gerekir. $x=y-y^2$ çözülünce iki farklı $y$ değeri gelir (artılı ve eksili). Bu işi karmaşıklaştırır. Burada kabuk yöntemi daha mantıklıdır.

### Ders sonrası notlar

- **Kabuk yönteminin şartı:** Hoca 01:13:27 civarında İngilizce "the bar must be perpendicular to rotation axis in order to obtain shells" diyor. Bu bir dil sürçmesi. Hemen önce ve 01:17:30'da doğrusunu söylüyor: kabuk için çubuk dönme eksenine **paralel** olmalı.
- **Örnek 2a:** Hoca önce "$y$ ekseni etrafında" dedi, hemen "$x$ ekseni etrafında" diye düzeltti.
- **Örnek 1:** Hoca alanı önce "$-1$'den $0$'a" diye başladı. Sağ ve sol uç noktalar bütün aralıkta aynı eğrilerde olduğu için integral $-1$'den $2$'ye tek parçadır. Hoca da öyle yazdı.
- **Örnek 1b:** Hoca dış yarıçapı sözlü olarak "two plus y square" diye söylüyor. Tahtada doğrusu yazılı: $(2+y)^2$.
- **Örnek 3:** Hoca kesişimde önce zihinden bir şey söyledi (altyazıda "orası e üzeri 3 olacak" gibi geçiyor; hesap sürçmesi mi, sorunun başka kurgusu mu olduğu net değil), sonra $x=\ln(\ln 3)$ ile devam etti. Soru büyük olasılıkla (ekrandan) $y=\ln 3$ doğrusuyla yazılı kaldı.
- **Örnek 5a:** Hoca "x is always positive here" diyor. Mutlak değerin kalkmasının asıl nedeni $x+\pi/2>0$ olmasıdır.
- **Hesaplanan sonuçlar:** Hoca integralleri ödev bıraktı. Özetteki sayısal sonuçlar ($9/2$, $72\pi/5$, $31\pi/5$, $163\pi/15$, $\pi^2$, $8\pi^2$, $4\pi^2$, $\pi/6$, $\pi/2$) bu özette hesaplandı.
- **Altyazı:** Pul yönteminin anlatıldığı yerde (yaklaşık 00:09:20-00:10:20) ve kabuk yöntemi sonrasında (yaklaşık 01:11:40-01:12:10) altyazı anlamsız Türkçe tekrarlara giriyor. Bu kısımlar altyazıda anlaşılmıyor; formüller hocanın sonraki anlatımından ve tahtadan kuruldu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
