# Ders 24 Çalışma Özeti

> Tarih: 23 Aralık 2020 (Çarşamba). Ders İngilizce anlatıldı, arada Türkçe açıklamalar var. Bu derste final konuları işlendi: rasyonel fonksiyonların integrali (devam) ve trigonometrik dönüşümler (trigonometric substitutions). Hoca bu derste tablet kalemiyle Microsoft Whiteboard üzerinde yazdı.

## Genel Konular

- Dersin başında hocanın "ön taslak sınav dosyaları" dediği sorulardan $\ln|x^2-1|$ sorusunun kısa tekrarı (bu grupla dün çözüldüğü fark edildi).
- Parçalı tanımlı fonksiyonun belirli integrali.
- Payın derecesi paydanınkinden büyük ya da eşit olan rasyonel fonksiyonlar: polinom bölmesi.
- Üstel ifadeleri $u = e^t$ ile rasyonel fonksiyona çevirme.
- Paydası reel kökü olmayan ikinci derece polinom: tam kareye tamamlama ve "payda türevini oluşturma" yöntemleri.
- $\sin t = u$ dönüşümüyle trigonometrik integrali rasyonel fonksiyona çevirme.
- Trigonometrik dönüşümler:
  - $\sqrt{a^2 - x^2}$ için $x = a\sin t$.
  - $\sqrt{x^2 - a^2}$ için $x = a\sec t$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Rasyonel fonksiyonların integrali ve trigonometrik dönüşümler **final** konusu.
- Parçalı tanımlı fonksiyonların belirli integrali finalde gelebilir; hoca bu tipe üç yıldız verdi. Çıkan değerler "absürt" görünebilir; gidişata odaklanın.
- "Ders derste öğrenilir." Hoca derse gelmeyen ve videoyu izlemeyen öğrencileri uyardı.
- Taslak sınav dosyalarını AVS'de paylaşmayacak, çünkü bunlar düzeltilmemiş ön taslaklar; videoları izleyin.
- Katlı reel kök için $\dfrac{Bu + C}{(u-1)^2}$ yazmak hatadır. Reel kök varsa her katmana yalnız sabit yazılır: $\dfrac{A}{u-1} + \dfrac{B}{(u-1)^2}$.
- $\sqrt{a^2 - x^2}$ görürseniz $x = a\sin t$ dönüşümü işi kolaylaştırır. Bu tip sorular AYT'deki trigonometri sorularına benzer (ör. "$x = \frac{\sqrt3}{2}\sin t$ ise $\sin 2t$'nin $x$ cinsinden yazılışı").
- Sonuç her zaman ilk değişken ($x$) cinsinden yazılmalı. Bunun için dik üçgen çizilir.
- **2. vize için son öneriler:**
  - Ağırlığı 1. vizeden sonra işlenen konulara verin. 1. vizeden sonra 4-5 hafta işlendi; her haftadan 3-4 soru gelecekmiş gibi çalışın.
  - 1. vize konularını küçümsemeyin; 2. vize konularıyla birleştirilip sorulabilir.
  - Temel teorem önemli; asimptotlar da var.

## Kısa Tekrar Notları

- **Payın derecesi ≥ paydanın derecesi:** Önce polinom bölmesi yapılır. Kalanın derecesi paydanınkinden küçük olunca durulur.
  - $\dfrac{x^2}{x^2+1} = 1 - \dfrac{1}{x^2+1}$
  - $\dfrac{x^3}{x^2+1} = x - \dfrac{x}{x^2+1}$
  - $\dfrac{x^3+x^2}{x^2+x+1} = x - \dfrac{x}{x^2+x+1}$
- **Tam kareye tamamlama:** $x^2 + x + 1 = \left(x + \tfrac12\right)^2 + \tfrac34$.
- $\displaystyle\int\frac{du}{u^2+a^2} = \frac1a\arctan\frac ua + C$.
- $\displaystyle\int\frac{du}{\sqrt{a^2-u^2}} = \arcsin\frac ua + C$.
- $\dfrac{d}{du}\operatorname{arcsec} u = \dfrac{1}{|u|\sqrt{u^2-1}}$.
- $\displaystyle\int\sec t\,dt = \ln|\sec t + \tan t| + C$ (pay ve payda $\sec t + \tan t$ ile çarpılarak bulunur).
- $\cos^2 t = \dfrac{1+\cos 2t}{2}$, $\sin^2 t = \dfrac{1-\cos 2t}{2}$, $\sin 2t = 2\sin t\cos t$.
- **Trigonometrik dönüşüm tablosu:**

  | İfade | Dönüşüm | Sadeleşme |
  |---|---|---|
  | $\sqrt{a^2 - x^2}$ | $x = a\sin t$ | $a\cos t$ |
  | $\sqrt{x^2 - a^2}$ | $x = a\sec t$ | $a\tan t$ |

  - Mutlak değer gerçekte $|a\cos t|$, $|a\tan t|$'dir. Hoca $a>0$ ve $\cos t$, $\tan t$'nin pozitif olduğu bir aralıkta çalışıldığını varsaydı.

## Detaylı Açıklamalar

### Örnek 1: Parçalı fonksiyonun belirli integrali

$$f(x) = \begin{cases} \dfrac{x}{x^2+1}, & -\pi < x < \dfrac{\pi}{2} \\[2mm] \dfrac{1}{x(x^2+1)}, & \dfrac{\pi}{2} \le x < \pi \end{cases} \qquad \int_{-\pi}^{\pi} f(x)\,dx = ?$$

- İntegral iki parçaya ayrılır: $I = I_1 + I_2$.
- $$I_1 = \int_{-\pi}^{\pi/2}\frac{x\,dx}{x^2+1} = \frac12\ln(x^2+1)\Big|_{-\pi}^{\pi/2} = \frac12\left[\ln\left(\frac{\pi^2}{4}+1\right) - \ln(\pi^2+1)\right]$$
- $I_2$ için basit kesirler: $\dfrac{1}{x(x^2+1)} = \dfrac Ax + \dfrac{Bx+C}{x^2+1}$.
  - $A = 1$ (kısa yol), $B = -1$, $C = 0$ (ders 23'teki örnekle aynı).
  - $$I_2 = \left[\ln|x| - \frac12\ln(x^2+1)\right]_{\pi/2}^{\pi}$$
- Sonuç $I_1 + I_2$. Hoca sorunun aklından yazıldığını, değerlerin garip görünmesinin sorun olmadığını söyledi.

### Örnek 2: $\displaystyle\int\frac{x^2}{x^2+1}\,dx$ ve $\displaystyle\int\frac{x^3}{x^2+1}\,dx$

- $x^2 = 1\cdot(x^2+1) - 1$, yani $\dfrac{x^2}{x^2+1} = 1 - \dfrac{1}{x^2+1}$. İntegral: $x - \arctan x + C$.
- $x^3 = x(x^2+1) - x$, yani $\dfrac{x^3}{x^2+1} = x - \dfrac{x}{x^2+1}$.
  $$\int\frac{x^3}{x^2+1}\,dx = \frac{x^2}{2} - \frac12\ln(x^2+1) + C$$

### Örnek 3: $\displaystyle\int\frac{dt}{e^{2t}+2e^t+1}$

- Rasyonel fonksiyon değil. Pay ve payda $e^t$ ile çarpılır:
  $$\int\frac{e^t\,dt}{e^t(e^{2t}+2e^t+1)}$$
- $u = e^t$, $du = e^t\,dt$:
  $$\int\frac{du}{u(u^2+2u+1)} = \int\frac{du}{u(u+1)^2}$$
- Basit kesirler: $\dfrac{1}{u(u+1)^2} = \dfrac Au + \dfrac B{u+1} + \dfrac C{(u+1)^2}$.
- $A$, $B$, $C$'nin bulunması ödev olarak bırakıldı. Sonra $I = A\ln|u| + B\ln|u+1| - \dfrac{C}{u+1} + c$ ve $u = e^t$ yazılır.
- Sınavda "bu integrali çözmek için aşağıdaki adımlardan hangileri doğrudur?" tipi soru gelebilir.

### Örnek 4: $u = e^t$ ile $\displaystyle\int\frac{u^2\,du}{u^2-2u+1}$

- Altyazıdan anlaşılan: üstel ifadeli bir integral $u = e^t$ dönüşümüyle $\int\frac{u^2}{u^2-2u+1}\,du$ biçimine getiriliyor. Asıl integrant ekranda net görünmedi.
- Hoca polinom bölmesinin ya da değişken dönüşümünün kullanılabileceğini söyledi.
- Polinom bölmesi: $\dfrac{u^2}{u^2-2u+1} = 1 + \dfrac{2u-1}{u^2-2u+1}$. Yani $I = u + J$, $J = \displaystyle\int\frac{(2u-1)\,du}{(u-1)^2}$.
- **Birinci yöntem:** Basit kesirler, $\dfrac{2u-1}{(u-1)^2} = \dfrac{A}{u-1} + \dfrac{B}{(u-1)^2}$. Katsayılar ödev.
- **İkinci yöntem (özel durum):** Payda paydanın türevini oluştur. $2u - 1 = (2u - 2) + 1$:
  $$J = \int\frac{(2u-2)\,du}{u^2-2u+1} + \int\frac{du}{(u-1)^2} = \ln(u^2-2u+1) - \frac{1}{u-1} + C$$
  - Birinci integralde $t = u^2-2u+1$, $dt = (2u-2)\,du$ dönüşümü yapıldı.
- Sonunda $u = e^t$ yazılmayı unutmayın.

### Örnek 5: $\displaystyle\int\frac{x\,dx}{x^2+x+1}$

- Diskriminant $b^2 - 4ac = 1 - 4 < 0$: reel kök yok.

**Birinci yöntem: tam kareye tamamlama**
- $x^2+x+1 = \left(x+\frac12\right)^2 + \frac34$. $u = x + \frac12$, $x = u - \frac12$:
  $$\int\frac{u\,du}{u^2+\frac34} - \frac12\int\frac{du}{u^2+\left(\frac{\sqrt3}{2}\right)^2}$$
- Birinci integral $t = u^2 + \frac34$ ile $\dfrac12\ln\left(u^2+\frac34\right)$. İçerisi hep pozitif, mutlak değere gerek yok.
- İkinci integral: $\dfrac12\cdot\dfrac{1}{\sqrt3/2}\arctan\dfrac{u}{\sqrt3/2}$.

**İkinci yöntem: paydada paydanın türevini oluştur**
- $(x^2+x+1)' = 2x+1$. Pay $x = \frac12\big[(2x+1) - 1\big]$:
  $$\frac12\int\frac{(2x+1)\,dx}{x^2+x+1} - \frac12\int\frac{dx}{\left(x+\frac12\right)^2+\frac34}$$
- Sonuç:
  $$\int\frac{x\,dx}{x^2+x+1} = \frac12\left[\ln|x^2+x+1| - \frac{2}{\sqrt3}\arctan\frac{x+\frac12}{\sqrt3/2}\right] + C = \frac12\ln(x^2+x+1) - \frac{1}{\sqrt3}\arctan\frac{2x+1}{\sqrt3} + C$$
- Hoca önce payda $x^2+2x+1$ varmış gibi düşünüp ikinci integrali $\frac{1}{x+1}$ biçiminde yazdı. Aradan sonra bu hatayı düzeltti ve doğru sonucu (arctan'lı) verdi.

### Örnek 6: $\displaystyle\int\frac{\cos^3 t\,dt}{\sin^3 t - \sin^2 t - 6\sin t}$

- $u = \sin t$, $du = \cos t\,dt$. $\cos^3 t\,dt = \cos^2 t\cdot\cos t\,dt = (1 - u^2)\,du$:
  $$\int\frac{(1-u^2)\,du}{u^3 - u^2 - 6u} = \int\frac{(1-u^2)\,du}{u(u-3)(u+2)}$$
- Üç katsız reel kök: kısa yol kullanılır.
  - $A$ ($u=0$): $\dfrac{1}{(-3)(2)} = -\dfrac16$.
  - $B$ ($u=3$): $\dfrac{1-9}{3\cdot5} = -\dfrac{8}{15}$.
  - $C$ ($u=-2$): $\dfrac{1-4}{(-2)(-5)} = -\dfrac{3}{10}$.
- $$I = -\frac16\ln|\sin t| - \frac{8}{15}\ln|\sin t - 3| - \frac{3}{10}\ln|\sin t + 2| + C$$
- Hoca bu kadar işlemli bir sorunun test sınavında sorulmayabileceğini söyledi.

### Örnek 7: $\displaystyle\int\frac{x^3+x^2}{x^2+x+1}\,dx$

- Polinom bölmesi: $x^3 + x^2 = x(x^2+x+1) - x$. Yani $\dfrac{x^3+x^2}{x^2+x+1} = x - \dfrac{x}{x^2+x+1}$.
- $$I = \frac{x^2}{2} - J, \qquad J = \int\frac{x\,dx}{x^2+x+1}$$
- $J$ Örnek 5'teki gibi hesaplanır.

### Trigonometrik dönüşümler

**Giriş:** $\displaystyle\int\frac{du}{\sqrt{4-u^2}}$
- 4 parantezine alınır: $\sqrt{4\left(1 - \left(\frac u2\right)^2\right)}$. $t = \frac u2$, $du = 2\,dt$:
  $$\int\frac{2\,dt}{2\sqrt{1-t^2}} = \arcsin t + C = \arcsin\frac u2 + C$$
- Genelleme: $\displaystyle\int\frac{du}{\sqrt{a^2-u^2}} = \arcsin\frac ua + C$.
- İkinci yöntem: $u = a\sin t$, $du = a\cos t\,dt$, $\sqrt{a^2 - a^2\sin^2 t} = a\cos t$. İntegral $\int dt = t + C$ olur.

**Örnek 8:** $\displaystyle\int\sqrt{1-x^2}\,dx$
1. $x = \sin t$, $dx = \cos t\,dt$, $\sqrt{1-x^2} = \cos t$.
2. $$\int\cos^2 t\,dt = \frac12\int(1+\cos 2t)\,dt = \frac12\left(t + \frac12\sin 2t\right) + C$$
3. Dik üçgen: karşı kenar $x$, hipotenüs 1, komşu kenar $\sqrt{1-x^2}$. $\sin 2t = 2\sin t\cos t = 2x\sqrt{1-x^2}$, $t = \arcsin x$.
4. $$\int\sqrt{1-x^2}\,dx = \frac12\left(\arcsin x + x\sqrt{1-x^2}\right) + C$$

**Ödev:** $\displaystyle\int x^2\sqrt{1-x^2}\,dx$
- $x = \sin t$ ile $\int\sin^2 t\cos^2 t\,dt = \frac14\int\sin^2 2t\,dt$ olur. $\sin^2 2t = \frac{1-\cos 4t}{2}$ kullanılır.

**Örnek 9:** $\displaystyle\int\sqrt{3-4x^2}\,dx$
1. $x = \dfrac{\sqrt3}{2}\sin t$, $dx = \dfrac{\sqrt3}{2}\cos t\,dt$.
2. $\sqrt{3 - 3\sin^2 t} = \sqrt3\cos t$.
3. $$\int\sqrt3\cos t\cdot\frac{\sqrt3}{2}\cos t\,dt = \frac32\int\cos^2 t\,dt = \frac34\left(t + \frac12\sin 2t\right) + C$$
4. $x$ cinsinden yazmak için dik üçgen kurulması ödev olarak bırakıldı ($\sin t = \frac{2x}{\sqrt3}$).

**Örnek 10:** $\displaystyle\int\frac{dx}{\sqrt{x^2-1}}$ (Dikkat: bu $\arcsin x$ değildir.)
1. $\operatorname{arcsec}$ türevindeki $\sqrt{u^2-1}$ ifadesinden yola çıkılır: $\sqrt{x^2 - a^2}$ için $x = a\sec t$.
2. $x = \sec t$, $dx = \sec t\tan t\,dt$, $\sqrt{\sec^2 t - 1} = \tan t$.
3. $$\int\frac{\sec t\tan t\,dt}{\tan t} = \int\sec t\,dt = \ln|\sec t + \tan t| + C$$
4. Dik üçgen: $\cos t = \frac1x$, komşu 1, hipotenüs $x$, karşı $\sqrt{x^2-1}$. $\sec t = x$, $\tan t = \sqrt{x^2-1}$.
5. $$\int\frac{dx}{\sqrt{x^2-1}} = \ln\left|x + \sqrt{x^2-1}\right| + C$$

**Ödev:** $\displaystyle\int\frac{x\,dx}{\sqrt{4x^2-9}}$
- 9 parantezine alınıp $x = \dfrac32\sec t$ dönüşümü yapılır; kök ifadesi $\tan t$'nin katına dönüşür.

### Ders sonrası notlar

- **Örnek 6'daki katsayılar:** Altyazıda $A$ için "$-\frac13$" ve $C$ için "$\frac32$" geçiyor. Doğru hesap ve kontrol: $A = -\frac16$, $B = -\frac{8}{15}$, $C = -\frac{3}{10}$. Doğrulama: $u^2$ katsayısı $A + B + C = -\frac{5+16+9}{30} = -1$, paydaki $-u^2$ ile tutarlı.
- **Örnek 5:** Hoca ilk çözümde $x^2+x+1$'i $(x+1)^2$ gibi düşündü. Aradan sonra kendisi düzeltti; doğru sonuçta $\arctan$ terimi var.
- **Örnek 3'ün ödev cevabı:** $\dfrac{1}{u(u+1)^2}$ için $A = 1$, $C = -1$, $B = -1$. Kontrol: $1 = A(u+1)^2 + Bu(u+1) + Cu$; $u=0 \Rightarrow A=1$, $u=-1 \Rightarrow C=-1$, $u^2$ katsayısı $A + B = 0 \Rightarrow B = -1$.
- Altyazının bazı kısımları döngüye girmiş ya da bozuk (ör. 00:25:10-00:26:39, 00:34:53, 00:49:13 civarı). Bu kısımlar altyazıda anlaşılmıyor; içerik tahta görüntüsü ve bağlamla tamamlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
