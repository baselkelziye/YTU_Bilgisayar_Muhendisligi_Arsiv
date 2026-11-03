# Ders 25 Çalışma Özeti

> Tarih: 29 Aralık 2020 (Salı). Ders İngilizce anlatıldı, arada Türkçe açıklamalar var. 2. vizeden sonraki ilk ders. Final konuları işlendi: $x = a\tan t$ trigonometrik dönüşümü, integralle alan hesabı (tarama çubuğu mantığı) ve dönel cisimlerin hacmi için disk yöntemi.

## Genel Konular

- Son trigonometrik dönüşüm: $\sqrt{x^2+a^2}$ ve $x^2+a^2$ için $x = a\tan t$.
- Diskriminantı negatif ikinci derece ifade içeren integraller: tam kareye tamamlayıp $u = a\tan t$.
- İntegralin uygulamaları:
  - Düzlemsel bölgenin alanı: dikey çubuklarla (vertical cross-sections) ve yatay çubuklarla (horizontal cross-sections) tarama.
  - Dönel cisimlerin hacmi (volumes of revolution): disk yöntemi (disk method).
- Bir "nadir gelen soru tipi" (üç yıldızlı) gösterildi ama çözümü sonraki haftaya bırakıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- 2. vize yapılmış. Hoca bazı soruların çok kolay, bazılarının zor olduğunu söyledi.
- **Final:** Final haftası 11 Ocak'ta başlıyor gibi görünüyor. 15. hafta sınav haftası olacağı için konuları hızlı bitirmek gerekiyor.
- **Mazeretler:** Sınav sırasında elektrik kesintisi gibi sorun yaşayanlar hocaya e-posta atmak yerine doğrudan bölüme dilekçe yazmalı. Hoca sisteme müdahale edemiyor. Hoca e-postasına günde bir kez bakıyor.
- **Tarama çubuğu mantığı:** Bütün alan ve hacim formüllerinin arkasındaki mantık aynı:
  1. Bölgeyi uygun bir çubukla (dikey ya da yatay) tara.
  2. Çubuğun kalınlığı ($dx$ ya da $dy$) integral değişkenini belirler. Bütün bilgiler bu değişken cinsinden yazılır.
  3. Çubuğun uzunluğunu uzaklık formülüyle bul: üst uç − alt uç (dikey) ya da sağ uç − sol uç (yatay).
  4. Çubuğun alanını ($dA$) ya da hacmini ($dV$) yaz, sonra en düşük seviyeden en yüksek seviyeye integral al.
- Bu tarama mantığı ileride çok değişkenli fonksiyonların integrallerinde de kullanılacak.
- Test sınavlarında genellikle sonucun kendisi değil, "bu bölgenin alanını veren integral hangisidir?" sorulur.
- Bazen dikey, bazen yatay tarama daha kolaydır; önce hangisinin uygun olduğunu belirleyin.
- Formül ezberlemeye gerek yok. Disk yöntemi silindirin hacmi ($\pi r^2 h$) bilgisiyle kurulur.
- **Disk yöntemi şartı:** Bölgeyi tarayan çubuk döndürme eksenine **dik** olmalı. Aksi hâlde disk elde edilmez.
- Bir sonraki ders: kabuk yöntemi (shell method), yay uzunluğu, yüzey alanı; vakit kalırsa genelleştirilmiş (improper) integrallere giriş. Sonra soru çözümü.

## Kısa Tekrar Notları

- **Dönüşüm tablosu (tam hâli):**

  | İfade | Dönüşüm | Sadeleşme |
  |---|---|---|
  | $\sqrt{a^2 - x^2}$ | $x = a\sin t$ | $a\cos t$ |
  | $\sqrt{x^2 - a^2}$ | $x = a\sec t$ | $a\tan t$ |
  | $\sqrt{x^2 + a^2}$ | $x = a\tan t$ | $a\sec t$ |

- $x = a\tan t \Rightarrow dx = a\sec^2 t\,dt$, $\tan^2 t + 1 = \sec^2 t$.
- $\displaystyle\int\sec t\,dt = \ln|\sec t + \tan t| + C$, $\displaystyle\int\csc t\,dt = -\ln|\csc t + \cot t| + C$.
- Diskriminant $b^2 - 4ac < 0$ ise ifadeyi $u^2 + a^2$ biçimine getirin, sonra $u = a\tan t$.
- **Alan (dikey tarama):** $A = \displaystyle\int_a^b \big[\text{üst} - \text{alt}\big]\,dx$.
- **Alan (yatay tarama):** $A = \displaystyle\int_c^d \big[\text{sağ} - \text{sol}\big]\,dy$.
- **Genel durum:** $A = \displaystyle\int_a^b |f(x) - g(x)|\,dx$. Eğriler kesişiyorsa integral kesişim noktalarında parçalara bölünür; her parçada üstteki eğriden alttaki çıkarılır.
- **Disk yöntemi ($x$ ekseni etrafında):** $V = \displaystyle\int_a^b \pi\,[f(x)]^2\,dx$.
- $e^{-\ln 2} = \dfrac12$, $e^{2\ln 2} = 4$.

## Detaylı Açıklamalar

### $x = a\tan t$ dönüşümü

- $\arctan$'ın türevindeki $1 + x^2$ ifadesinden yola çıkılır. $x^2 + a^2$ görürseniz (özellikle kök içindeyse) $x = a\tan t$ dönüşümü işi kolaylaştırır.
- $\sqrt{a^2\tan^2 t + a^2} = a|\sec t| = a\sec t$ ($a > 0$ ve $\sec t > 0$ olan aralıkta).

**Örnek 1:** $\displaystyle\int\frac{dx}{x^2+a^2}$
- Birinci yöntem: $a^2$ parantezine al, $u = \frac xa$.
- İkinci yöntem: $x = a\tan t$, $dx = a\sec^2 t\,dt$, $x^2 + a^2 = a^2\sec^2 t$:
  $$\int\frac{a\sec^2 t\,dt}{a^2\sec^2 t} = \frac1a t + C = \frac1a\arctan\frac xa + C$$

**Örnek 2:** $\displaystyle\int\frac{dx}{\sqrt{x^2+a^2}}$
1. $x = a\tan t$: $\displaystyle\int\frac{a\sec^2 t\,dt}{a\sec t} = \int\sec t\,dt = \ln|\sec t + \tan t| + C$.
2. $\sec t$ integrali hatırlanmıyorsa: pay ve payda $\sec t + \tan t$ ile çarpılır, $u = \sec t + \tan t$ yapılır.
3. Dik üçgen: $\tan t = \frac xa$, karşı $x$, komşu $a$, hipotenüs $\sqrt{x^2+a^2}$. $\sec t = \frac{\sqrt{x^2+a^2}}{a}$.
4. $$\int\frac{dx}{\sqrt{x^2+a^2}} = \ln\left|\frac{\sqrt{x^2+a^2}}{a} + \frac xa\right| + C$$

**Örnek 3:** $\displaystyle\int\frac{dx}{x\sqrt{x^2+a^2}}$
- $x = a\tan t$: $\displaystyle\int\frac{a\sec^2 t\,dt}{a\tan t\cdot a\sec t} = \frac1a\int\frac{\sec t}{\tan t}\,dt = \frac1a\int\csc t\,dt$.
- Hoca önce $\frac1a$ katsayısını unuttu; bir öğrenci uyardı.
- $\csc t$ integrali: pay ve payda $\csc t + \cot t$ ile çarpılır. Sonuç $-\frac1a\ln|\csc t + \cot t| + C$.
- $x$ cinsinden yazmak (üçgenle) ödev.

**Örnek 4:** $\displaystyle\int\frac{dx}{\sqrt{4x^2+9}}$
1. $4x^2 + 9 = (2x)^2 + 3^2$ (diskriminant negatif). $2x = 3\tan t$, $x = \frac32\tan t$, $dx = \frac32\sec^2 t\,dt$.
2. $\sqrt{9\tan^2 t + 9} = 3\sec t$.
3. $$\int\frac{\frac32\sec^2 t\,dt}{3\sec t} = \frac12\int\sec t\,dt = \frac12\ln|\sec t + \tan t| + C$$
4. Üçgen: $\tan t = \frac{2x}{3}$, hipotenüs $\sqrt{9 + 4x^2}$. $x$ cinsinden yazmak ödev.

**Örnek 5:** $\displaystyle\int\frac{dx}{\sqrt{x^2+4x+8}}$
1. Diskriminant $16 - 32 < 0$. Tam kare: $x^2 + 4x + 8 = (x+2)^2 + 2^2$.
2. $x + 2 = 2\tan t$, $dx = 2\sec^2 t\,dt$, kök $= 2\sec t$.
3. $$\int\frac{2\sec^2 t\,dt}{2\sec t} = \int\sec t\,dt = \ln|\sec t + \tan t| + C$$
4. Üçgen: $\tan t = \frac{x+2}{2}$, hipotenüs $\sqrt{x^2+4x+8}$.

### Alan hesabı: temel durumlar

**Durum 1:** $f$, $[a,b]$'de sürekli ve pozitif. Bölge: $[a,b]$ aralığının üstü, $y = f(x)$'in altı.
- Dikey çubuk: kalınlık $dx$, yükseklik $f(x)$.
- $$A = \int_a^b f(x)\,dx$$

**Durum 2:** Bölge $x = 0$ ile $x = g(y)$ arasında, $y = c$'den $y = d$'ye.
- Yatay çubuk: kalınlık $dy$. Sağ uç $(g(y), y)$, sol uç $(0, y)$. Uzunluk: $x_2 - x_1 = g(y)$.
- $$A = \int_c^d g(y)\,dy$$

**Durum 3:** Bölge $y = f(x)$ (üstte) ile $y = g(x)$ (altta) arasında, kesişim yok.
- $$A = \int_a^b \big[f(x) - g(x)\big]\,dx$$

**Durum 4:** Bölge $x = g(y)$ (sağda) ile $x = h(y)$ (solda) arasında.
- $$A = \int_c^d \big[g(y) - h(y)\big]\,dy$$

**Genel durum:** $f$ ve $g$ eğrileri $c_1$ ve $c_2$'de kesişiyor.
$$A = \int_a^b |f(x) - g(x)|\,dx = \int_a^{c_1}(f - g)\,dx + \int_{c_1}^{c_2}(g - f)\,dx + \int_{c_2}^{b}(f - g)\,dx$$
- Her aralıkta tarama çubuğunun üst ucu hangi eğrideyse ondan alttaki çıkarılır.

### Örnek 6: $y = \sqrt x$, $y = 0$ ve $x = 4$ ile sınırlı bölge

- (a) **Dikey tarama:** üst uç $\sqrt x$, alt uç $0$, $x$: $0 \to 4$.
  $$A = \int_0^4 \sqrt x\,dx$$
- (b) **Yatay tarama:** $x = 4$ için $y = 2$. Sağ uç $x = 4$, sol uç $x = y^2$, $y$: $0 \to 2$.
  $$A = \int_0^2 (4 - y^2)\,dy$$
- (c) $$A = \left[4y - \frac{y^3}{3}\right]_0^2 = 8 - \frac83 = \frac{16}{3}$$
- İki model de aynı sonucu verir.

### Örnek 7: $y = -x^2 + 2x$ ve $y = 0$ ile sınırlı bölge

- Kökler $x = 0$ ve $x = 2$. $x^2$ katsayısı negatif, parabol aşağı açılıyor.
- Dikey tarama:
  $$A = \int_0^2 (-x^2 + 2x)\,dx = \left[-\frac{x^3}{3} + x^2\right]_0^2 = -\frac83 + 4 = \frac43$$

### Örnek 8: $y = x^2$ ve $y = x + 2$ ile sınırlı bölge

- Kesişim: $x^2 = x + 2 \Rightarrow x = -1$ ya da $x = 2$.
- Dikey tarama: üst uç daima $y = x + 2$, alt uç daima $y = x^2$.
  $$A = \int_{-1}^{2}(x + 2 - x^2)\,dx = \left[\frac{x^2}{2} + 2x - \frac{x^3}{3}\right]_{-1}^{2}$$
- Hoca sonucu derste net söyleyemedi ("$\frac{10}{3}$", "$\frac{13}{2}$ ya da 6"). Doğru değer için "Ders sonrası notlar"a bakın.

### Örnek 9: $y = x^2$, $y = x + 2$ ve $y = 0$ ile sınırlı bölge

- Üç sınır eğrisi. Bölge $x = -2$ ile $x = 0$ arasında, $x$ ekseninin üstünde.
- (a) **Dikey tarama:** Üst uç $[-2, -1]$'de $y = x + 2$, $[-1, 0]$'da $y = x^2$. Bu yüzden integral ikiye bölünür:
  $$A = \int_{-2}^{-1}(x + 2)\,dx + \int_{-1}^{0} x^2\,dx$$
  - Hoca birinci parçanın bir üçgen alanı olduğunu, ama sınavda integral olarak isteneceğini hatırlattı.
- (b) **Yatay tarama:** $y$: $0 \to 1$. Sağ uç $x = -\sqrt y$ (parabolün sol kolu), sol uç $x = y - 2$.
  $$A = \int_0^1 \big[-\sqrt y - (y - 2)\big]\,dy = \left[-\frac{2}{3}y^{3/2} - \frac{y^2}{2} + 2y\right]_0^1 = -\frac23 - \frac12 + 2 = \frac56$$
- Sonuç negatif çıkarsa bir yerde hata yapmışsınız demektir.
- Hoca bir öğrencinin sorusu üzerine (b) şıkkını Türkçe olarak adım adım tekrar anlattı: $y = x^2$'nin iki kolu var, $x = \sqrt y$ ve $x = -\sqrt y$; bu bölgede sol kol kullanılır. Parantez açmayı unutmayın.

### Örnek 10: $y = 0$, $x = e$ ve $x = e^y$ ile sınırlı bölge

- $x = e^y \iff y = \ln x$. Aynı eğri iki denk biçimde yazılabilir; çubuğun konumuna göre uygun olanı seçilir.
- (a) **Dikey tarama:** üst uç $y = \ln x$, alt uç $y = 0$, $x$: $1 \to e$.
  $$A = \int_1^e \ln x\,dx$$
- (b) **Yatay tarama:** sağ uç $x = e$, sol uç $x = e^y$, $y$: $0 \to 1$.
  $$A = \int_0^1 (e - e^y)\,dy = \big[ey - e^y\big]_0^1 = (e - e) - (0 - 1) = 1$$
- Alan 1 birim kare. Hocaya göre (b) daha kolay.
- Bir öğrenci sınırların 1 ile $e$ olduğunu ve $\ln x$ geldiğini doğru buldu.

### Dönel cisimlerin hacmi: disk yöntemi

- Kalınlığı $dx$, yüksekliği $f(x)$ olan dikdörtgen çubuğu $x$ ekseni etrafında $360°$ döndürürsek bir disk (ince silindir) elde ederiz.
- Diskin yarıçapı $r = f(x)$, yüksekliği $h = dx$.
- Hacmi: $dV = \pi r^2 h = \pi[f(x)]^2\,dx$.
- $y = f(x)$'in altında ve $[a,b]$'nin üstündeki bölge $x$ ekseni etrafında döndürülürse:
  $$V = \int_a^b \pi\,[f(x)]^2\,dx$$
- Bu formüle **disk yöntemi** denir.
- **Şart:** Bölgeyi tarayan çubuk döndürme eksenine dik olmalı.

### Örnek 11: $y = e^x$, $x = -\ln 2$, $x = \ln 2$ ve $y = 0$ ile sınırlı bölge

- Dört sınır eğrisi var. Hoca önce $y = 0$'ı söylemeyi unuttu, sonra ekledi.
- (a) **Alan (dikey tarama):**
  $$A = \int_{-\ln 2}^{\ln 2} e^x\,dx = e^{\ln 2} - e^{-\ln 2} = 2 - \frac12 = \frac32$$
  - Bir öğrenci "4 olmalı" dedi. Hoca $e^{-\ln 2} = e^{\ln\frac12} = \frac12$ olduğunu hatırlattı.
- (b) **Hacim ($x$ ekseni etrafında, disk yöntemi):** Dikey çubuk $x$ eksenine dik. Yarıçap $r = e^x$.
  $$V = \int_{-\ln 2}^{\ln 2}\pi e^{2x}\,dx = \frac{\pi}{2}\big[e^{2x}\big]_{-\ln 2}^{\ln 2} = \frac{\pi}{2}\left(4 - \frac14\right) = \frac{15\pi}{8}$$

### Ders sonrası notlar

- **Örnek 8'in doğru sonucu:**
  $$\left[\frac{x^2}{2} + 2x - \frac{x^3}{3}\right]_{-1}^{2} = \left(2 + 4 - \frac83\right) - \left(\frac12 - 2 + \frac13\right) = \frac{10}{3} + \frac76 = \frac92$$
  Hocanın söylediği $\frac{10}{3}$ yalnız üst sınırdaki değer. Öğrencinin söylediği $\frac{13}{2}$ ve 6 da yanlış. Doğru alan $\frac92$.
- **Örnek 9 (a):** $\int_{-2}^{-1}(x+2)\,dx = \frac12$ ve $\int_{-1}^{0}x^2\,dx = \frac13$; toplam $\frac56$. Yatay taramayla bulunan sonuçla aynı.
- **Örnek 11 (b):** Hoca sonucu $\frac{\pi}{2}\left(e^{2\ln2} - e^{-2\ln2}\right)$ biçiminde bıraktı. Sayısal değeri $\frac{15\pi}{8}$.
- **Örnek 3:** $\int\csc t\,dt = -\ln|\csc t + \cot t| + C$ (ya da $\ln|\csc t - \cot t| + C$). Hoca işaretini yazmadı.
- Altyazının bazı kısımları döngüye girmiş ya da bozuk (ör. 00:34:44, 00:35:14-00:35:44, 00:40:41 civarı). Bu kısımlar altyazıda anlaşılmıyor; içerik bağlamdan kuruldu.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
