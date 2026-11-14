# Ders 26 Genişletilmiş Notu: Disk, Pul ve Kabuk Yöntemleriyle Dönel Cisimlerin Hacmi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Disk Yönteminin Tekrarı
- 2. Pul Yöntemi
- 3. Örnek 1: $x=y^2$ ve $x-y=2$ Arasındaki Bölge
- 4. Örnek 2: $y=x^2$, $x=1$, $x=2$, $y=0$ ile Sınırlı Bölge
- 5. Örnek 3: $y=e^x$, $y=\ln 3$ ve $x=0$ ile Sınırlı Bölge
- 6. Kabuk Yöntemi
- 7. Örnek 4: $y=\sin x$, $0\le x\le 2\pi$
- 8. Örnek 5: $y=\sin x$, $0\le x\le\pi$, Dikey Doğrular Etrafında Dönme
- 9. Örnek 6: $x=y-y^2$ ile $y$ Ekseni Arasındaki Bölge
- 10. Örnek Sorular
- 11. Dersin Toparlaması

## 1. Disk Yönteminin Tekrarı

Hoca derse, bir önceki derste anlatılan disk yönteminin (disk method) arkasındaki mantığı hatırlatarak başladı. Ders İngilizce anlatıldı, önemli yerler Türkçe tekrar edildi. Hoca tahtaya çizerek anlattı; altyazıda yalnız sözlü kısım vardır. Formüller sözlü anlatımdan kuruldu.

### 1.1 $x$ ekseni etrafında dönme

Bir $y=f(x)$ grafiği düşünelim. Grafiğin altına, $x$ eksenine dik duran, kalınlığı $dx$ olan ince bir dikdörtgen çubuk yerleştirelim. Kalınlık $dx$ yeterince küçük olduğu için çubuğun tepesindeki eğrilikten gelen hata ihmal edilir; çubuk bir dikdörtgen kabul edilir. Çubuğun yüksekliği $f(x)$'tir.

Bu dikdörtgen bölge $x$ ekseni etrafında döndürülünce bir disk oluşur:

- Diskin yarıçapı: $r=f(x)$.
- Diskin kalınlığı (silindirin yüksekliği): $h=dx$.
- Diskin hacmi: $dV=\pi r^2 h=\pi\,[f(x)]^2\,dx$.

Bu yalnız tek bir diskin hacmidir. Bölge bu çubukla $x=a$'dan $x=b$'ye taranır ve eşitliğin iki tarafı integrallenir:

$$V=\pi\int_a^b [f(x)]^2\,dx$$

> **Hocanın vurgusu:** Bölgeyi tarayan çubuk dönme eksenine (rotation axis) **dik** olmalıdır. Aksi durumda disk elde edilemez.

### 1.2 $y$ ekseni etrafında dönme

Bölge $y$ ekseni etrafında döndürülecekse, bölgeyi yatay kesitlerle (horizontal cross sections) taramak daha uygundur. Bu durumda çubuğun kalınlığı $dy$ olur. Çubuğun uzunluğu, eğrinin $x=F(y)$ biçimindeki denklemiyle verilir. Çubuk $y$ ekseni etrafında döndürülünce yarıçapı $F(y)$, kalınlığı $dy$ olan bir disk oluşur:

$$dV=\pi\,[F(y)]^2\,dy,\qquad V=\pi\int_c^d [F(y)]^2\,dy$$

Hoca burada da aynı şartı tekrarladı: Çubuk dönme eksenine dik olmalıdır, bu çok önemli bir karakteristik özelliktir. Aksi hâlde yöntem uygulanamaz.

## 2. Pul Yöntemi

Hoca disk yöntemini, iki grafik arasında kalan bölgeye genelleştirdi. Bölge üstte $y=f(x)$, altta $y=g(x)$ grafikleri arasında, $x=a$ ile $x=b$ arasında olsun. Bölgeye yine dikey bir çubuk yerleştirilir, kalınlığı $dx$'tir.

<!-- BELİRSİZ: 00:09:20-00:10:20 arasında altyazı anlamsız Türkçe tekrarlara giriyor ("Yüce Yüceyik, bu sayede R1'e"); bu kısımda r1 ve r2'nin tahtada nasıl gösterildiği altyazıda anlaşılmıyor. Aşağıdaki tanımlar hocanın hemen sonraki anlatımından kuruldu. -->

Çubuk $x$ ekseni etrafında döndürülünce ortası boş bir disk, yani bir **pul** (washer) oluşur. Hoca: "Bir pul elde edeceğim, yeterince ince olduğundan." Pulun hacmi, iç içe geçmiş iki silindirin hacimleri farkıdır:

- Dış yarıçap: $r_1$ (dış silindirin yarıçapı).
- İç yarıçap: $r_2$ (oyuk kısmın yarıçapı).
- Kalınlık: $h$.

$$dV=\pi r_1^2 h-\pi r_2^2 h=\pi\,(r_1^2-r_2^2)\,h$$

Çubuğun kalınlığı $dx$ olduğu için **bütün bilgiler $x$ cinsinden yazılmalıdır**. Burada $h=dx$, $r_1=f(x)$ ve $r_2=g(x)$'tir. İki taraf integrallenince:

$$V=\pi\int_a^b \left([f(x)]^2-[g(x)]^2\right)dx$$

Bu $V$, $y=f(x)$ ile $y=g(x)$ arasındaki ve $x=a$'dan $x=b$'ye uzanan bölgenin $x$ ekseni etrafında döndürülmesiyle oluşan cismin hacmidir. Bu yönteme pul yöntemi (washer method) denir. Pulların hacimleri birleştirilerek, "kaynaştırılarak" bütün cismin hacmi bulunur. Hoca, pul yönteminin aslında disk yönteminin genelleştirilmiş hâli olduğunu söyledi.

> **Hocanın vurgusu:** Pul yönteminde de aynı karakteristik özellik geçerlidir: Bölgeyi tarayan çubuk dönme eksenine **dik** olmalıdır. Aksi durumda pul elde edilemez.

**Soru:** Doğrudan $r_1-r_2$ deyip yapsak olmaz mı?
**Cevap:** Sınavda doğrudan $[f(x)]^2-[g(x)]^2$ yazabilirsiniz. Ama şuna dikkat edin: Birçok öğrenci $(r_1-r_2)^2$ yazıyor. Bu yanlıştır. Doğrusu $r_1^2-r_2^2$'dir. Ezbere giderseniz bu hatayı yaparsınız; mantık genel olmalıdır.

> **Hocanın vurgusu:** Pul yönteminde $(r_1-r_2)^2$ değil, $r_1^2-r_2^2$ yazılır. "Unfortunately, most of students made this mistake."

## 3. Örnek 1: $x=y^2$ ve $x-y=2$ Arasındaki Bölge

### 3.1 Sorunun düzeltilmesi

Hoca soruyu bir kaynaktan doğrudan aldığını söyledi. Soru: $R$ bölgesi $x=y^2$ parabolü ve bir doğruyla sınırlıdır. (a) $R$'nin alanını veren integrali bulun. (b) $R$'nin $y$ ekseni etrafında döndürülmesiyle oluşan cismin hacmini veren integrali bulun.

<!-- BELİRSİZ: Doğrunun ilk yazılan denklemi altyazıda net değil (00:15:14 "y-x is equal to", 00:19:16 "4", 00:20:33 "y minus x is equal to 2"). -->

Şekli çizerken hoca, ilk yazılan doğrunun ($y-x=2$ biçiminde) parabolle kesişmediğini fark etti: Bu doğru $x=0$ için $y=2$'den, $y=0$ için $x=-2$'den geçer ve parabolle kesişmez. "Soruda yanlışlık var, soruyu yanlış yazmışlar" diyerek soruyu düzeltti. Doğruyu eksen kesenleri $(2,0)$ ve $(0,-2)$ olacak biçimde istedi:

$$\frac{x}{2}+\frac{y}{-2}=1\quad\Longrightarrow\quad x-y=2$$

Ayrıca alan şıkkını "$y$'ye göre" (with respect to $y$) istedi: "$x$'e göre zor olur, sınavda o kadar zor gelmez."

### 3.2 Kesişim noktaları

$y$'ye göre çalışmak, bölgeyi yatay kesitlerle taramak demektir. Önce kesişim noktaları bulunur. $x-y=2$ doğrusundan $x=2+y$ yazılır ve $x=y^2$ ile ortak çözülür:

$$y^2=2+y\;\Longrightarrow\; y^2-y-2=0\;\Longrightarrow\;(y-2)(y+1)=0$$

$$y=-1,\qquad y=2$$

### 3.3 (a) Alan

Yatay tarama sırasında çubuğun sağ uç noktası her zaman $x=2+y$ doğrusu üzerinde, sol uç noktası her zaman $x=y^2$ parabolü üzerindedir. Hoca alanı önce "$y=-1$'den $y=0$ seviyesine" diye yazmaya başladı, sonra iki ucun bütün aralıkta aynı eğrilerde kaldığını belirterek integrali ayırmaya gerek olmadığını söyledi. Sağ uç noktanın cebirsel değerinden sol uç noktanınki çıkarılınca çubuğun uzunluğu bulunur:

$$A=\int_{-1}^{2}\left[(2+y)-y^2\right]dy$$

Hoca hesabı ödev bıraktı. Hesaplanınca (derste hesaplanmadı):

$$A=\left[2y+\frac{y^2}{2}-\frac{y^3}{3}\right]_{-1}^{2}=\frac{10}{3}-\left(-\frac{7}{6}\right)=\frac{9}{2}$$

### 3.4 (b) $y$ ekseni etrafında hacim

Yatay çubuk $y$ ekseni etrafında döndürülür. Çubuk dönme eksenine diktir, ama çubuk ile eksen arasında boşluk vardır; bu yüzden pul oluşur.

- Dış yarıçap: sağ uç noktanın eksene uzaklığı, $r_1=2+y$.
- İç yarıçap: sol uç noktanın eksene uzaklığı, $r_2=y^2$.
- Kalınlık: $dy$.

Bir pulun hacmi $dV=\pi\,(r_1^2-r_2^2)\,dy$'dir. Bütün pullar en alt seviye $y=-1$'den $y=2$'ye kadar integrallenir:

$$V=\pi\int_{-1}^{2}\left[(2+y)^2-(y^2)^2\right]dy$$

Hoca şunu vurguladı: Çubuğun kalınlığı $dy$ olduğu için bütün bilgiler $y$ cinsinden yazılır. $r_1$ ve $r_2$ belirlendikten sonra tek bir pulun hacmi yazılır, sonra pullar integrallenir.

Hesaplanınca (derste hesaplanmadı): $V=\dfrac{72\pi}{5}$. Bu sonuç python (sympy) ile hem pul hem kabuk yöntemiyle doğrulandı.

> **Ders sonrası not:** Hoca dış yarıçapın karesini sözlü olarak "two plus y square" diye okudu (00:28:40). Doğrusu $(2+y)^2$'dir; $2+y^2$ değildir.

## 4. Örnek 2: $y=x^2$, $x=1$, $x=2$, $y=0$ ile Sınırlı Bölge

**Soru:** $R$ bölgesi $y=x^2$ eğrisi, $x=1$ doğrusu, $x=2$ doğrusu ve $y=0$ doğrusuyla sınırlıdır.

- (a) $R$'nin $y=0$ doğrusu etrafında döndürülmesiyle oluşan cismin hacmini veren integrali yazın.
- (b) $R$'nin $y=-1$ doğrusu etrafında döndürülmesiyle oluşan cismin hacmini veren integrali yazın.

Hoca: "Basit sorular, ama B şıkkı biraz daha düşünme gerektiriyor."

### 4.1 (a) $x$ ekseni etrafında: disk yöntemi

Hoca önce "$y$ ekseni etrafında döndürürüz" dedi, hemen "$x$ ekseni etrafında, pardon" diye düzeltti. Bölgeyi taramak için en iyi çubuk dikey kesittir (vertical cross section). Dikey çubuk $x$ ekseni etrafında dönünce disk oluşur:

- Yarıçap: $r=x^2$.
- Kalınlık: $dx$.
- $dV=\pi\,(x^2)^2\,dx$.

$$V=\pi\int_1^2 x^4\,dx=\pi\left[\frac{x^5}{5}\right]_1^2=\pi\left(\frac{32}{5}-\frac{1}{5}\right)=\frac{31\pi}{5}$$

Hoca bu şıkkı sondan bir önceki adıma ($\pi(32/5-1/5)$) kadar götürdü. Sonuç $31\pi/5$, python ile doğrulandı.

### 4.2 (b) $y=-1$ doğrusu etrafında: pul yöntemi

Dönme ekseni artık $y=-1$ doğrusudur. Hoca dikey çubuğun **uzantısını** düşündü: Çubuk $y=-1$ doğrusuna kadar uzatılırsa, uzantı dönme eksenine diktir. Bu yüzden yine disk ya da pul yöntemi uygulanabilir. Çubuk ile eksen arasında boşluk ($x$ ekseninden $y=-1$'e kadar olan şerit) olduğu için pul oluşur.

- Dış yarıçap $r_1$: çubuğun üst ucunun $y=-1$ doğrusuna uzaklığı. Çubuğun yüksekliği $x^2$, buna eksenle $x$ ekseni arasındaki $1$ birim eklenir: $r_1=x^2+1$. Hoca: "Bu uzaklık pozitif olmalı."
- İç yarıçap $r_2$: $x$ ekseninin $y=-1$ doğrusuna uzaklığı, $r_2=1$.
- Kalınlık: $dx$.

$$dV=\pi r_1^2 h-\pi r_2^2 h,\qquad V=\pi\int_1^2\left[(x^2+1)^2-1^2\right]dx$$

Hesaplanınca (derste hesaplanmadı): $V=\dfrac{163\pi}{15}$. Python ile doğrulandı.

> **Hocanın vurgusu:** "İşin mantığını anladığınız an, farklı tipte bir soru geldiğinde hemen modelleyebiliyorsunuz, probleminizi çözebiliyorsunuz."

## 5. Örnek 3: $y=e^x$, $y=\ln 3$ ve $x=0$ ile Sınırlı Bölge

**Soru:** $R$ bölgesi $y=e^x$ eğrisi, $y=\ln 3$ doğrusu ve $x=0$ doğrusuyla sınırlıdır.

- (a) $R$'yi $x$ ekseni etrafında döndürün. Oluşan cismin hacmini veren integrali bulun.
- (b) $R$'yi $y$ ekseni etrafında döndürün. Oluşan cismin hacmini veren integrali bulun.
- (c) şıkkı "haftaya" bırakıldı; altyazıda metni yok.

<!-- BELİRSİZ: Bölgenin tanımı 00:40:06'da altyazıda okunmuyor ("Bounded by y'x"). Sınırlar 00:46:30, 00:47:04 ve 00:49:24-00:49:30'daki anlatımdan kuruldu: y = ln 3, y = e^x, x = 0. -->

Hoca: "Sadece integrali bulun. Hesaplamaları daha sonra siz yaparsınız. Just find integration model."

### 5.1 Kesişim noktası

Hoca kesişimi önce zihinden hesaplamaya çalıştı ve yanılınca durdu: "Direkt zihnimden yapmaya çalışıyorum, olmuyor." $y=e^x$ ile $y=\ln 3$ ortak çözülür:

$$e^x=\ln 3\;\Longrightarrow\;x=\ln(\ln 3)$$

> **Hocanın vurgusu:** "Zihnimizden yaparken hata yapabiliyoruz. Zihin yanıltıcı olabiliyor. Adım adım işlem yapmak daha mantıklı."

<!-- BELİRSİZ: 00:46:50-00:46:58 arasında hoca "orası e üzeri 3, 3 olacak arkadaşlar ... Neyse böyle kalsın" diyor. Sorunun aslında y = 3 doğrusuyla mı kurgulandığı, yoksa yalnız hesap sürçmesi mi olduğu altyazıdan anlaşılmıyor. Hoca soruyu y = ln 3 ile sürdürdü. -->

Bir öğrenci kesişimde $x$ yerine neden $3$ yazılamadığını sordu. Hoca cevap olarak iki denklemi ortak çözdürdü: $y$ görülen yere $\ln 3$ yazılır, $e^x=\ln 3$ olur; iki tarafa $\ln$ uygulanınca $x=\ln(\ln 3)$ bulunur.

### 5.2 (a) $x$ ekseni etrafında: pul yöntemi

Dikey çubuk yerleştirilir ve dönme eksenine (x eksenine) kadar uzantısı düşünülür. Bölge $y=e^x$'in üstünde, $y=\ln 3$'ün altında kaldığı için oyuk vardır; pul oluşur.

- Dış yarıçap: $r_1=\ln 3$.
- İç yarıçap: $r_2=e^x$.
- Kalınlık: $dx$; tarama $x=0$'dan $x=\ln(\ln 3)$'e.

$$V=\pi\int_0^{\ln(\ln 3)}\left[(\ln 3)^2-e^{2x}\right]dx$$

### 5.3 (b) $y$ ekseni etrafında: disk yöntemi

Bölgeyi taramak için en iyi çubuk yatay çubuktur. Hoca: "Burada boş kısım yok." Yatay çubuk $y$ ekseninden başlayıp $y=e^x$ eğrisine kadar uzanır; dönünce pul değil disk oluşur. Çubuğun kalınlığı $dy$ olduğundan bütün bilgiler $y$ cinsinden yazılmalıdır: $y=e^x$ denklemi $x=\ln y$ biçimine getirilir.

- Yarıçap: $r=\ln y$.
- Kalınlık: $dy$.
- $y$, $e^0=1$ seviyesinden $\ln 3$ seviyesine kadar değişir.

$$V=\pi\int_1^{\ln 3}(\ln y)^2\,dy$$

Hoca bu integralin kısmi integrasyonla (integration by parts) ya da indirgeme formülüyle hesaplanabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Kısmi integrasyon iki kez uygulanırsa $\int(\ln y)^2\,dy=y(\ln y)^2-2y\ln y+2y+C$ bulunur. Bu ilkel fonksiyon türetilerek kontrol edilebilir: türevi $(\ln y)^2+2\ln y-2\ln y-2+2=(\ln y)^2$ olur.

> **Ders sonrası not:** $\ln 3\approx1{,}0986$ olduğu için $\ln(\ln 3)\approx0{,}094$'tür; bölge çok küçüktür. Python ile hesaplanınca (a) şıkkı $V\approx0{,}0315$, (b) şıkkı $V\approx0{,}00093$ birim küp çıkar. Her iki sonuç kabuk yöntemiyle de aynı bulundu, yani kurulan integral modelleri tutarlıdır.

Bir öğrenci (a) şıkkını tekrar göstermesini istedi; hoca tahtayı geri getirdi. Ardından ders aradan önce bitti.

## 6. Kabuk Yöntemi

Aradan sonra hoca kabuk yöntemine (shell method) geçti.

### 6.1 Silindirik kabuğun oluşması

Bir koordinat sistemi çizilir ve $y=f(x)$ grafiğinin altına kalınlığı $dx$ olan dikey bir çubuk yerleştirilir. Çubuk ile $y$ ekseni arasındaki uzaklık $x$'tir. Bu dikdörtgen bölge $y$ ekseni etrafında döndürülünce bir **silindirik kabuk** (cylindrical shell) oluşur. Kabuğun ölçüleri:

- Yarıçap (radius of shell): $x$.
- Yükseklik (height of shell): $f(x)$.
- Kalınlık (thickness of shell): $dx$.

### 6.2 Kabuğun hacmi

Kabuğun hacmini bulmak için kabuk dikey bir doğru boyunca kesilir ve açılır (cut and expand). Yaklaşık olarak bir dikdörtgenler prizması elde edilir. Hoca bunu "aslında bir A4 kâğıdı" diye niteledi. Prizmanın kenarları:

- Açılan çemberin çevresi: yaklaşık $2\pi x$.
- Yükseklik: $f(x)$.
- Kalınlık: $dx$.

Bütün kenar uzunlukları çarpılınca tek bir kabuğun hacmi bulunur:

$$dV=2\pi\,x\,f(x)\,dx$$

Çubuğun kalınlığı $dx$ olduğu için integral değişkeni $x$'tir. Bölge $x=a$'dan $x=b$'ye taranır ve iki taraf integrallenir:

$$V=2\pi\int_a^b x\,f(x)\,dx$$

Bu $V$, $[a,b]$ aralığının üstünde ve $f(x)$ grafiğinin altında kalan bölgenin $y$ ekseni etrafında döndürülmesiyle oluşan cismin hacmidir.

<!-- BELİRSİZ: 01:11:35-01:12:04 arasında altyazı anlamsız Türkçe tekrarlara giriyor ("bu bölgeye görebilecek bir şekilde"); bu kısımda tahtada ne gösterildiği altyazıda anlaşılmıyor. -->

### 6.3 Yöntemin şartı: paralel çubuk

Hoca öğrencilere sordu: Bölgeyi tarayan mavi çubuk ile dönme ekseni arasındaki ilişki nedir? Cevap: **paraleldir**. Aksi durumda kabuk elde edilemez. Yöntem bu yüzden kabuk yöntemi diye adlandırılır.

> **Hocanın vurgusu:** "İsmi ezberlemeyin. İsmin arkasında yatan mantığa odaklanın. Kavramları ezberlerseniz kavram kargaşası çıkar. Mantığını öğrenirseniz kavramlar kolayca anlaşılır."

> **Ders sonrası not:** Hoca 01:13:27'de İngilizce "the bar scanning our region must be perpendicular to rotation axis in order to obtain shells" dedi. Bu bir dil sürçmesidir. Hemen öncesinde Türkçe ve 01:17:30'da İngilizce doğrusunu söyledi: Kabuk elde etmek için çubuk dönme eksenine **paralel** olmalıdır.

### 6.4 A4 kâğıdı benzetmesi

Bir öğrenci anlatımın tekrarını isteyince hoca şu benzetmeyi yaptı:

- Elinize tek bir A4 kâğıdı alın. Normalde bu kâğıdın hacmi yok gibidir.
- Kâğıdı kıvırıp uçlarını birleştirirseniz bir boru olur. Bu bir ağaç kabuğu gibidir.
- Kalınlığı $dx$, yüksekliği $f(x)$ olan yeterince ince bir çubuğu, $y$ ekseninden $x$ uzaklıkta ve eksene paralel tutup döndürürseniz yüksekliği $f(x)$, yarıçapı $x$, kalınlığı $dx$ olan bir boru, yani bir ağaç kabuğu elde edersiniz.
- Bu boruyu tekrar açarsanız kâğıdı bir dikdörtgenler prizması gibi düşünebilirsiniz: bir kenarı çemberin çevresi $2\pi x$, diğer kenarı $f(x)$, kalınlığı $dx$. Hacmi $dV=2\pi\,x\,f(x)\,dx$'tir.
- Çubuğu $a$'dan $b$'ye hareket ettirdikçe iç içe geçmiş bir sürü silindirik kabuk oluşur. İç içe geçmiş kabuklar üst üste gelince ağacı meydana getirir. Bu kabuklar integralle "kaynaştırılınca" cismin hacmi bulunur.

### 6.5 Hangi yöntem seçilmeli?

Hoca iki yöntemin şartlarını yan yana koydu:

| Yöntem | Çubuk ile dönme ekseni | Elde edilen parça |
|---|---|---|
| Disk | Dik | Disk |
| Pul | Dik | Pul (ortası oyuk disk) |
| Kabuk | Paralel | Silindirik kabuk |

Hangi yöntemin kullanılacağı tercihe bağlıdır ve sorudan soruya değişir. Bazen disk, bazen pul, bazen kabuk yöntemi avantajlıdır. Pozisyonlara dikkat edilirse hata yapılmaz; ezberlenmeye çalışılırsa hata yapılır.

> **Ders sonrası not:** Hoca 01:18:16'da "kabuk yöntemi, pul yöntemi zaten kabuğun, diskin genelleştirilmiş hali" dedi. Bu bir sürçmedir. Dersin başında (00:12:48) söylediği gibi, pul yöntemi disk yönteminin genelleştirilmiş hâlidir; kabuk yöntemi ayrı bir yöntemdir.

## 7. Örnek 4: $y=\sin x$, $0\le x\le 2\pi$

**Soru:** $R$ bölgesi $y=\sin x$ grafiği ile $x$ ekseni arasında, $0\le x\le 2\pi$ aralığında kalan bölgedir.

- (a) $R$ $x$ ekseni etrafında döndürülürse oluşan cismin hacmi nedir?
- (b) $R$ $y$ ekseni etrafında döndürülürse oluşan cismin hacmi nedir?

Hoca: "Hangi yöntemin en iyi olduğunu belirlemek sizin beceriniz olmalı."

### 7.1 (a) $x$ ekseni etrafında: disk yöntemi

Bu durumda en iyi yöntem disk yöntemidir. Dikey çubuğun $x$ ekseni etrafında dönmesi bir disk verir. Yarıçap $\sin x$, kalınlık $dx$'tir:

$$V=\pi\int_0^{2\pi}\sin^2x\,dx=\pi\int_0^{2\pi}\frac{1-\cos 2x}{2}\,dx$$

Hoca hesabı ödev bıraktı. Hesaplanınca (derste hesaplanmadı): $V=\pi\cdot\dfrac{1}{2}\cdot 2\pi=\pi^2$. Python ile doğrulandı.

> **Ders sonrası not:** Hoca önce "$2\pi$ ... $\sin$, $0$'dan $\pi$'ye" diye başladı, sonra "sorry, this is $\pi$" diyerek $\pi\sin^2 x\,dx$ biçimine düzeltti ve sınırları $0$'dan $2\pi$'ye yazdı. Bölge $[0,2\pi]$ olduğu için doğru sınırlar $0$ ve $2\pi$'dir.

### 7.2 (b) $y$ ekseni etrafında: kabuk yöntemi

Bu durumda kabuk yöntemi daha iyidir. Disk yöntemi denenirse çok daha karmaşık integral problemleri çıkar. Dikey çubuk $y$ eksenine paraleldir, kabuk oluşur.

Formüldeki $2\pi$ çemberin çevresinden gelir. Yarıçap $x$, yükseklik $\sin x$, kalınlık $dx$'tir. Fakat hoca burada sık yapılan bir hataya dikkat çekti: $\pi<x<2\pi$ aralığında $\sin x$ negatiftir. Kabuğun yarıçapı, yüksekliği ve kalınlığı pozitif olmalıdır. Bu yüzden genel formül mutlak değerlerle yazılır:

$$V=2\pi\int |\text{yarıçap}|\cdot|\text{yükseklik}|\;d(\text{değişken})$$

Bu bölgede $x$ her zaman pozitiftir. $\sin x$ ise $[0,\pi]$'de pozitif, $[\pi,2\pi]$'de negatiftir. İntegral ikiye ayrılır ve ikinci parçada $\sin x$ eksiyle çarpılır:

$$V=2\pi\left[\int_0^{\pi}x\sin x\,dx+\int_{\pi}^{2\pi}x\,(-\sin x)\,dx\right]$$

Hesaplanınca (derste hesaplanmadı): $\int_0^{\pi}x\sin x\,dx=\pi$ ve $\int_{\pi}^{2\pi}x(-\sin x)\,dx=3\pi$ olduğundan $V=2\pi(\pi+3\pi)=8\pi^2$. Python ile doğrulandı. Mutlak değer unutulup $2\pi\int_0^{2\pi}x\sin x\,dx$ yazılsaydı sonuç $-4\pi^2$ çıkardı; negatif hacim, hatanın işaretidir.

> **Hocanın vurgusu:** "Some students make this mistake, unfortunately." Kabuğun yarıçapı pozitif, yüksekliği pozitif, kalınlığı pozitif olmalıdır. Bu yüzden $x$'e ve $f(x)$'e mutlak değer uygulanır; gerekirse integral parçalara ayrılır.

**Soru:** Formüldeki $2\pi$ nereden geliyor? (01:28:04)
**Cevap:** Çemberin çevre uzunluğundan. Kabuk kesilip açılınca o kenarın uzunluğu $2\pi r$ olur.

## 8. Örnek 5: $y=\sin x$, $0\le x\le\pi$, Dikey Doğrular Etrafında Dönme

**Soru:** $R$ bölgesi $y=\sin x$ grafiği ile $x$ ekseni arasında, $0\le x\le\pi$ aralığında kalan bölgedir. Şekilde $x=-\pi/2$ ve $x=3\pi/2$ doğruları da çizilidir.

- (a) $R$ $x=-\pi/2$ doğrusu etrafında döndürülürse oluşan cismin hacmi nedir?
- (b) $R$ $x=3\pi/2$ doğrusu etrafında döndürülürse oluşan cismin hacmi nedir?

Hoca: "İlk sorular çok önemlidir. Basit sorularda düşünerek öğrenmeniz, keşfetmeniz daha iyi öğrenmenize neden olur."

### 8.1 (a) $x=-\pi/2$ etrafında: kabuk yöntemi

Yine kabuk yöntemi daha iyidir: Bölgeyi tarayan dikey çubuk, dönme eksenine (dikey doğru $x=-\pi/2$) paraleldir. Çubuk döndürülünce kabuk oluşur.

Yarıçap, çubuk ile dönme ekseni arasındaki uzaklıktır ve pozitif olmalıdır. İki nokta arasındaki uzaklık formülüyle bulunur:

- Çubuğun üst uç noktası: $(x,\sin x)$.
- Dönme ekseni üzerindeki karşı nokta: $(-\pi/2,\sin x)$.
- $y$ koordinatları aynı olduğu için $(y_2-y_1)^2=0$ olur. Uzaklık $\sqrt{(x_2-x_1)^2}=|x_2-x_1|$'dir.

$$r=\left|x-\left(-\frac{\pi}{2}\right)\right|=x+\frac{\pi}{2}$$

Bölgede $x\ge0$ olduğu için mutlak değer kalkar. Kabuğun yüksekliği $\sin x$'tir; $[0,\pi]$'de pozitif olduğu için mutlak değere gerek yoktur. Kalınlık $dx$'tir ve bölge $x=0$'dan $x=\pi$'ye taranır:

$$V=2\pi\int_0^{\pi}\left(x+\frac{\pi}{2}\right)\sin x\,dx=2\pi\left[\int_0^{\pi}x\sin x\,dx+\frac{\pi}{2}\int_0^{\pi}\sin x\,dx\right]$$

Birinci integral kısmi integrasyonla hesaplanır, ikincisi çok kolaydır. Hoca hesabı ödev bıraktı: "Zaman kaybetmek istemiyorum." Hesaplanınca (derste hesaplanmadı): $\int_0^{\pi}x\sin x\,dx=\pi$, $\int_0^{\pi}\sin x\,dx=2$; $V=2\pi(\pi+\pi)=4\pi^2$. Python ile doğrulandı.

> **Hocanın vurgusu:** Sınavlarda bu tarz sorularda genellikle integral modeli istenir. İntegralin hesaplanması çok nadir sorulur.

> **Ders sonrası not:** Hoca mutlak değerin kalkmasını "x is always positive here" diye gerekçelendirdi. Asıl gerekçe $x+\pi/2>0$ olmasıdır; bu, bölgede $x\ge0$ olmasından çıkar.

### 8.2 Neden yatay çubuk kullanılmıyor?

Bir öğrenci yarıçapın bulunuşunu ve yöntem seçimini tekrar sordu. Hoca adım adım açıkladı ve sonra öğrencilere şu soruyu sordu: Bölgeyi tarayan çubuk dönme eksenine dik olursa ne elde ederiz?

**Soru:** Çubuk dönme eksenine dik (ya da uzantısı dik) olursa kabuk mu, disk/pul mu elde ederiz?
**Cevap:** Disk ya da iç içe geçmiş disklerin oyulmasıyla oluşan pul elde ederiz. Ama bu işimize yaramaz. Çubuğun kalınlığı $dy$ olur. O zaman $y=\sin x$ yerine $x=\arcsin y$ yazmak gerekir. Üstelik $\arcsin y$ orada her yerde uygun biçimde tanımlı olmaz ve iş "çorba olur". $y=\sin x$ biçimi, işlem açısından $x=\arcsin y$ biçiminden daha düzgündür. Bu yüzden bölge dikey taranır.

> **Ek bilgi (derste anlatılmadı):** $\arcsin$ fonksiyonu yalnız $[-\pi/2,\pi/2]$ aralığındaki açıları verir. $[0,\pi]$'deki $\sin x$ grafiğinin sağ yarısı ($\pi/2<x\le\pi$) için $x=\pi-\arcsin y$ yazmak gerekir. Yani yatay çubuğun iki ucu iki farklı ifadeyle verilir; bu da integral modelini karmaşıklaştırır.

### 8.3 (b) $x=3\pi/2$ etrafında: kabuk yöntemi

Hoca bu şıkkı önce öğrencilere bıraktı: "Cevabı bulmayın, sadece integrali bulun. Hata yapmaktan korkmayın; derste yapılan hatalar gayet öğreticidir."

Dikey çubuk $x=3\pi/2$ doğrusuna paraleldir; kabuk oluşur. Dönme ekseni bölgenin sağında kaldığı için yarıçap:

$$r=\frac{3\pi}{2}-x$$

Bu ifade bölgede ($0\le x\le\pi$) pozitiftir. Yükseklik $\sin x$ (pozitif), kalınlık $dx$'tir. Hoca: "$2\pi$'yi koymayı unutmayın; çemberin çevresinden geliyor."

$$V=2\pi\int_0^{\pi}\left(\frac{3\pi}{2}-x\right)\sin x\,dx$$

Hoca hesabı ödev bıraktı. Hesaplanınca (derste hesaplanmadı): $V=2\pi\left(\dfrac{3\pi}{2}\cdot2-\pi\right)=4\pi^2$. Python ile doğrulandı.

> **Ek bilgi (derste anlatılmadı):** (a) ve (b) şıklarında aynı sonucun çıkması tesadüf değildir. $\sin x$ grafiği $x=\pi/2$ doğrusuna göre simetriktir. $x=-\pi/2$ ve $x=3\pi/2$ doğruları da bu simetri doğrusuna eşit uzaklıktadır ($\pi$ birim). Bu yüzden iki dönel cisim birbirinin aynası olur.

## 9. Örnek 6: $x=y-y^2$ ile $y$ Ekseni Arasındaki Bölge

**Soru:** $R$ bölgesi $x=y-y^2$ eğrisi ile $y$ ekseni arasında kalan bölgedir. Eğri $y$ eksenini $y=0$ ve $y=1$'de keser.

- (a) $R$ $x$ ekseni etrafında döndürülürse oluşan cismin hacmi nedir?
- (b) $R$ $y=-1$ doğrusu etrafında döndürülürse oluşan cismin hacmi nedir?

<!-- BELİRSİZ: (b) şıkkının sorulduğu yer (01:47:43-01:47:54) altyazıda okunmuyor; dönme ekseni 01:49:26'daki çözümden y = -1 olarak alındı. -->

### 9.1 (a) $x$ ekseni etrafında: kabuk yöntemi

Hoca "hemen yapalım, bitirelim" diyerek çözdü. En iyi pozisyon yatay çubuktur. Yatay çubuk $x$ eksenine paraleldir, bu yüzden kabuk oluşur. Çubuğun kalınlığı $dy$'dir.

- Çubuğun uç noktası: $(x,y)$, burada $x=y-y^2$.
- Kabuğun yarıçapı: çubuğun $x$ eksenine uzaklığı, $y$. Bu bölgede $y$ pozitiftir.
- Kabuğun yüksekliği: çubuğun uzunluğu, $x=y-y^2$. Bu bölgede pozitiftir.
- Kalınlık: $dy$; tarama $y=0$'dan $y=1$'e.

$$V=2\pi\int_0^1 y\,(y-y^2)\,dy$$

Hesaplanınca (derste hesaplanmadı): $V=2\pi\left(\dfrac13-\dfrac14\right)=\dfrac{\pi}{6}$. Python ile doğrulandı.

### 9.2 (b) $y=-1$ doğrusu etrafında: kabuk yöntemi

Yatay çubuk $y=-1$ doğrusuna da paraleldir. Değişen yalnız yarıçaptır: Çubuğun $y=-1$ doğrusuna uzaklığı $y+1$'dir.

- Yarıçap: $y+1$.
- Yükseklik: $y-y^2$.
- Kalınlık: $dy$.

$$V=2\pi\int_0^1 (y+1)(y-y^2)\,dy$$

Hesaplanınca (derste hesaplanmadı): $(y+1)(y-y^2)=y-y^3$ olduğundan $V=2\pi\left(\dfrac12-\dfrac14\right)=\dfrac{\pi}{2}$. Python ile doğrulandı.

### 9.3 Neden kabuk?

**Soru:** Bu soruda neden kabuk yöntemi kullanıldı?
**Cevap:** Disk ya da pul elde etmeye çalışın: Dönme eksenine dik, yani dikey bir çubuk koyun. O zaman çubuğun kalınlığı $dx$ olur ve $y$'yi $x$ cinsinden yazmanız gerekir. $x=y-y^2$ denklemi $y$ için çözülünce iki farklı $y$ değeri gelir, biri artılı biri eksili. Durum değişir, iş "çorba olur". Yaparsınız ama işi karmaşık hâle getirmiş olursunuz. Burada kabuk yöntemi daha mantıklıdır.

> **Ek bilgi (derste anlatılmadı):** $x=y-y^2$ denklemi $y^2-y+x=0$ biçiminde yazılıp ikinci derece formülüyle çözülürse $y=\dfrac{1\pm\sqrt{1-4x}}{2}$ bulunur. Dikey çubuğun üst ucu artılı, alt ucu eksili kökle verilir. Bu durumda pul yönteminde iki kökün kareleri farkını integrallemek gerekir.

## 10. Örnek Sorular

Bu derste kare yoktur; sorular hocanın derste sözlü olarak sorduğu ve çözdüğü sorulardır. Çözümler yukarıdaki bölümlerde adım adım verilmiştir; burada soru ve integral modeli toplu verilir.

**Soru 1** (derste sözlü, 00:14:57 ve düzeltme 00:22:39): $R$ bölgesi $x=y^2$ ve $x-y=2$ ile sınırlı. (a) $R$'nin alanını veren integrali $y$'ye göre yazın. (b) $R$'nin $y$ ekseni etrafında döndürülmesiyle oluşan cismin hacmini veren integrali yazın.

> **Çözüm (derste verildi, Bölüm 3):** (a) $A=\int_{-1}^{2}\left[(2+y)-y^2\right]dy=\dfrac92$. (b) $V=\pi\int_{-1}^{2}\left[(2+y)^2-y^4\right]dy=\dfrac{72\pi}{5}$. Sayısal sonuçlar derste hesaplanmadı; python ile bulundu.

**Soru 2** (derste sözlü, 00:30:16): $R$ bölgesi $y=x^2$, $x=1$, $x=2$, $y=0$ ile sınırlı. (a) $R$'nin $y=0$ etrafında, (b) $y=-1$ etrafında döndürülmesiyle oluşan cismin hacmini veren integrali yazın.

> **Çözüm (derste verildi, Bölüm 4):** (a) $V=\pi\int_1^2 x^4\,dx=\dfrac{31\pi}{5}$. (b) $V=\pi\int_1^2\left[(x^2+1)^2-1\right]dx=\dfrac{163\pi}{15}$ (sayısal sonuç python ile).

**Soru 3** (derste sözlü, 00:39:53): $R$ bölgesi $y=e^x$, $y=\ln 3$, $x=0$ ile sınırlı. (a) $x$ ekseni, (b) $y$ ekseni etrafında dönmeyle oluşan cismin hacmini veren integrali bulun. <!-- BELİRSİZ: bölge tanımı altyazıda kısmen okunuyor; c şıkkının metni yok. -->

> **Çözüm (derste verildi, Bölüm 5):** (a) $V=\pi\int_0^{\ln(\ln 3)}\left[(\ln 3)^2-e^{2x}\right]dx$. (b) $V=\pi\int_1^{\ln 3}(\ln y)^2\,dy$.

**Soru 4** (derste sözlü, 01:19:14 ve 01:22:47): $R$ bölgesi $y=\sin x$ ile $x$ ekseni arasında, $0\le x\le2\pi$. (a) $x$ ekseni, (b) $y$ ekseni etrafında dönmeyle oluşan cismin hacmi nedir? Hangi yöntem en uygundur?

> **Çözüm (derste verildi, Bölüm 7):** (a) Disk: $V=\pi\int_0^{2\pi}\sin^2x\,dx=\pi^2$. (b) Kabuk: $V=2\pi\left[\int_0^{\pi}x\sin x\,dx-\int_{\pi}^{2\pi}x\sin x\,dx\right]=8\pi^2$ (sayısal sonuçlar python ile).

**Soru 5** (derste sözlü, 01:31:10 ve 01:41:10): $R$ bölgesi $y=\sin x$ ile $x$ ekseni arasında, $0\le x\le\pi$. (a) $x=-\pi/2$, (b) $x=3\pi/2$ doğrusu etrafında dönmeyle oluşan cismin hacmini veren integrali bulun.

> **Çözüm (derste verildi, Bölüm 8):** (a) $V=2\pi\int_0^{\pi}\left(x+\frac{\pi}{2}\right)\sin x\,dx=4\pi^2$. (b) $V=2\pi\int_0^{\pi}\left(\frac{3\pi}{2}-x\right)\sin x\,dx=4\pi^2$ (sayısal sonuçlar python ile).

**Soru 6** (derste sözlü, 01:46:47): $R$ bölgesi $x=y-y^2$ ile $y$ ekseni arasında. (a) $x$ ekseni, (b) $y=-1$ doğrusu etrafında dönmeyle oluşan cismin hacmi nedir?

> **Çözüm (derste verildi, Bölüm 9):** (a) $V=2\pi\int_0^1 y(y-y^2)\,dy=\dfrac{\pi}{6}$. (b) $V=2\pi\int_0^1 (y+1)(y-y^2)\,dy=\dfrac{\pi}{2}$ (sayısal sonuçlar python ile).

**Soru 7** (derste sözlü, 01:39:29): Bölgeyi tarayan çubuk dönme eksenine dik (ya da uzantısı dik) olursa kabuk mu, disk ya da pul mu elde ederiz?

> **Çözüm (derste verildi, Bölüm 8.2):** Disk ya da pul elde edilir. Kabuk için çubuk eksene paralel olmalıdır.

## 11. Dersin Toparlaması

Bu derste dönel cisimlerin hacmi için üç yöntem bir arada görüldü. Disk ve pul yönteminde bölgeyi tarayan çubuk dönme eksenine diktir; çubuk dönünce bir disk ya da ortası oyuk bir pul oluşur ve hacim $\pi\int r^2$ ya da $\pi\int(r_1^2-r_2^2)$ ile bulunur. Kabuk yönteminde çubuk dönme eksenine paraleldir; çubuk dönünce silindirik bir kabuk oluşur ve hacim $2\pi\int(\text{yarıçap})(\text{yükseklik})\,d(\text{değişken})$ ile bulunur. Her yöntemde çubuğun kalınlığı ($dx$ ya da $dy$) integral değişkenini belirler; bütün bilgiler o değişken cinsinden yazılır. Yarıçap, yükseklik ve kalınlık pozitif olmalıdır; gerekirse mutlak değer kullanılır ve integral parçalara ayrılır. Dönme ekseni bir koordinat ekseni değil de $y=-1$ ya da $x=-\pi/2$ gibi bir doğruysa, yarıçap çubuk ile eksen arasındaki uzaklıktır ve iki nokta arası uzaklık formülüyle bulunur.

Hocanın dersin bütününe yaydığı mesaj, yöntem seçiminin bir beceri olduğudur: Aynı bölge için bir yöntem basit bir integral verirken öteki $\arcsin y$ ya da iki köklü ifadeler gibi karmaşık integrallere götürebilir. Hoca ezber yerine çubuk ile dönme ekseni arasındaki ilişkiye odaklanmayı önerdi. Örnek 3'ün (c) şıkkı bir sonraki derse bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
