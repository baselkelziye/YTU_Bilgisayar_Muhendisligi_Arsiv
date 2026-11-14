# Ders 20 Çalışma Özeti

## Genel Konular

- Kısmi integrasyon (integration by parts) soruları.
- $u$ seçimi için LAPTE sıralaması.
- Tablo yöntemi (tabular method) ve döngüsel (periyodik) durumlar.
- Önce değişken dönüşümü, sonra kısmi integrasyon gerektiren sorular.
- Ters trigonometrik fonksiyonların integralleri: $\arcsin x$, $\arctan x$, $\arctan\sqrt{x}$.
- Trigonometrik fonksiyonların integralleri (integration of trigonometric functions):
  - Toplam formülleri (addition formulas) ve kuvvet indirgeme (power reduction).
  - $\sin^n x$ ve $\cos^n x$: çift ve tek kuvvetler.
  - Çarpımı toplama çevirme (product-to-sum) formülleri.
  - $\tan^2 x$ ve $\tan^3 x$.

## Hocanın Özellikle Vurguladığı Kısımlar

- $u$ seçimi için sıralama: **L** (logaritmik), **A** (ters trigonometrik), **P** (polinom), **T** (trigonometrik), **E** (üstel). Sırada önce gelen fonksiyon $u$ seçilir, kalan kısım $dv$ olur.
- Tablo yöntemi ayrı bir yöntem değildir. Kısmi integrasyonun basitleştirilmiş hâlidir. "Klişeye uyalım" diye hoca da buna tablo yöntemi diyor.
- Döngüsel durumda (örneğin $e^x \sin x$) tabloda başladığınız fonksiyonu tekrar yakaladığınızda durursunuz. Katsayının ne olduğu (ör. $\tfrac{1}{2}$ veya $-\tfrac{1}{2}$) önemli değildir. İlla eksi işaretli gelmesi gerekmez.
- Bu yöntemle $e^{3t}\cos 2t$ gibi bir integrali en fazla 1 dakikada bulabilmelisiniz.
- İntegrand fonksiyonda "gözü tırmalayan" bir ifade (ör. $\sqrt{x}$) varsa önce değişken dönüşümüyle onu yok edin.
- Fonksiyonların toplamının integrali, çarpımının integralinden kolaydır. Trigonometrik çarpımları toplam formülleriyle toplama çevirin. Bunu görmek "sizin yeteneğinize kalmış".
- Trigonometride yalnız toplam formülünü ve Pisagor özdeşliğini bilmek yeterli. Bütün formülleri ezberlemek mantıklı değil.
- Tek kuvvetli terim varsa onu parçalayın, Pisagor özdeşliğini kullanın, sonra uygun değişken dönüşümü yapın.
- Şu ana kadar anlatılan her şey ikinci vizeye dahil. Yeni konu final konusu olursa hoca söyleyecek.
- Gelecek hafta indirgeme formülleri (reduction formulas) anlatılacak. İkinci vizeye dahil son konu bu. Sonra genel alıştırmalar çözülecek.
- Hoca gelecek hafta yerel ekstremum için ikinci türev testiyle ilgili soru çözeceğini tekrar söylüyor.
- Hoca, konuların neler olduğunu tek tek soranlara dersi baştan sona dinlemelerini söylüyor. Konuları bir önceki derste açıklamıştı.

## Kısa Tekrar Notları

- $\displaystyle\int u\,dv = uv - \int v\,du$.
- $\displaystyle\int x^2\cos x\,dx = x^2\sin x + 2x\cos x - 2\sin x + C$.
- $\displaystyle\int \cos\sqrt{x}\,dx = 2\sqrt{x}\sin\sqrt{x} + 2\cos\sqrt{x} + C$.
- $\displaystyle\int \ln^3 x\,dx = x\left(\ln^3 x - 3\ln^2 x + 6\ln x - 6\right) + C$.
- $\displaystyle\int e^x\sin x\,dx = \frac{e^x(\sin x - \cos x)}{2} + C$.
- $\displaystyle\int e^{3t}\cos 2t\,dt = \frac{e^{3t}(3\cos 2t + 2\sin 2t)}{13} + C$.
- $\displaystyle\int \arcsin x\,dx = x\arcsin x + \sqrt{1-x^2} + C$.
- $\displaystyle\int \arctan x\,dx = x\arctan x - \frac{1}{2}\ln(1+x^2) + C$.
- $\displaystyle\int \arctan\sqrt{x}\,dx = x\arctan\sqrt{x} - \sqrt{x} + \arctan\sqrt{x} + C$.
- Kuvvet indirgeme: $\cos^2 a = \dfrac{1+\cos 2a}{2}$, $\sin^2 a = \dfrac{1-\cos 2a}{2}$.
- Çarpımı toplama çevirme:
  - $\sin A\cos B = \dfrac{\sin(A+B) + \sin(A-B)}{2}$
  - $\sin A\sin B = \dfrac{\cos(A-B) - \cos(A+B)}{2}$
  - $\cos A\cos B = \dfrac{\cos(A-B) + \cos(A+B)}{2}$
- $\displaystyle\int \tan^2 x\,dx = \tan x - x + C$.
- $\displaystyle\int \tan^3 x\,dx = \frac{\tan^2 x}{2} + \ln|\cos x| + C$.

## Detaylı Açıklamalar

### Örnek 1: $\displaystyle\int x^2\cos x\,dx$

- Polinom ($P$) trigonometrikten ($T$) önce gelir: $u = x^2$, $dv = \cos x\,dx$.
- $du = 2x\,dx$, $v = \sin x$.
- $\displaystyle\int x^2\cos x\,dx = x^2\sin x - 2\int x\sin x\,dx$.
- İkinci integral için tekrar: $u = x$, $dv = \sin x\,dx$, $du = dx$, $v = -\cos x$.
  - $\displaystyle\int x\sin x\,dx = -x\cos x + \int\cos x\,dx = -x\cos x + \sin x$.
- Sonuç: $x^2\sin x + 2x\cos x - 2\sin x + C$.
- **Tablo ile:**
  - Türev sütunu: $x^2 \to 2x \to 2 \to 0$.
  - İntegral sütunu: $\cos x \to \sin x \to -\cos x \to -\sin x$.
  - İşaretler: $+, -, +$.
  - Aynı sonuç çıkar. Kontrol için integral sütununu aşağıdan yukarı türevlersiniz.
- Bir öğrenci ikinci satırdan sonrasını anlamadığını söylüyor. Hoca: İki kez kısmi integrasyon uygulandı. Parantez içindeki kısım ikinci uygulamadır.

### Örnek 2: $\displaystyle\int \cos\sqrt{x}\,dx$

- Önce $\sqrt{x}$'i yok etmek için değişken dönüşümü: $t = \sqrt{x}$, $x = t^2$, $dx = 2t\,dt$.
- $\displaystyle\int 2t\cos t\,dt$ olur. Polinom ile trigonometrik çarpımı.
- Tablo:
  - Türev sütunu: $2t \to 2 \to 0$.
  - İntegral sütunu: $\cos t \to \sin t \to -\cos t$.
- $2t\sin t + 2\cos t + C$.
- Eski değişkene dönülür: $2\sqrt{x}\sin\sqrt{x} + 2\cos\sqrt{x} + C$.
- Hoca bu tarz bir sorunun sınavda gelebileceğini söylüyor.

### Örnek 3: $\displaystyle\int \ln^3 x\,dx$

- **1. yol (ödev):** $u = \ln^3 x$, $dv = dx$. Kısmi integrasyonu en az üç kez uygulamak gerekir. Hoca bu yüzden bu yolu tercih etmiyor.
- **2. yol:** Önce değişken dönüşümü: $x = e^t$, $dx = e^t\,dt$, $\ln x = t$.
- $\displaystyle\int t^3 e^t\,dt$. Polinom ile üstel çarpımı, tablo uygulanır:
  - Türev sütunu: $t^3 \to 3t^2 \to 6t \to 6 \to 0$.
  - İntegral sütunu: hep $e^t$.
- $e^t\left(t^3 - 3t^2 + 6t - 6\right) + C$.
- $e^t = x$, $t = \ln x$ yazılır: $x\left(\ln^3 x - 3\ln^2 x + 6\ln x - 6\right) + C$.

### Örnek 4: $\displaystyle\int e^x\sin x\,dx$ (döngüsel durum)

- Trigonometrik ($T$) üstelden ($E$) önce gelir: $u = \sin x$, $dv = e^x\,dx$.
- $I = e^x\sin x - \displaystyle\int e^x\cos x\,dx$.
- Tekrar: $u = \cos x$, $dv = e^x\,dx$, $du = -\sin x\,dx$, $v = e^x$.
- $I = e^x\sin x - \left(e^x\cos x + \displaystyle\int e^x\sin x\,dx\right) = e^x\sin x - e^x\cos x - I$.
- $\sin x$'in türevleri periyodiktir. Bu yüzden başladığımız integral ($I$) sağ tarafta tekrar çıkar.
- $2I = e^x(\sin x - \cos x)$, yani $I = \dfrac{e^x(\sin x - \cos x)}{2} + C$.
- **Tablo ile:**
  - Türev sütununa $\sin x$ veya $e^x$ yazılabilir; fark etmez. Hoca $\sin x$ yazıyor: $\sin x \to \cos x \to -\sin x$.
  - İntegral sütunu: $e^x \to e^x \to e^x$.
  - $-\sin x$'i yakalayınca durulur. Son satırın çarpımı $-I$'yı verir.
  - $I = e^x\sin x - e^x\cos x - I$. Aynı sonuç, daha kısa yoldan.
- Bir öğrenci: "Diğer tablolarda en altta sıfır vardı, o yüzden sola atınca bir şey değişmiyordu." Hoca onaylıyor.

### Örnek 5 (alıştırma): $\displaystyle\int e^{3t}\cos 2t\,dt$

- Türev sütunu: $\cos 2t \to -2\sin 2t \to -4\cos 2t$.
- İntegral sütunu: $e^{3t} \to \dfrac{1}{3}e^{3t} \to \dfrac{1}{9}e^{3t}$.
- $-4\cos 2t$'yi yakalayınca durulur. Son satır: $-\dfrac{4}{9}I$.
- $I = \dfrac{1}{3}e^{3t}\cos 2t + \dfrac{2}{9}e^{3t}\sin 2t - \dfrac{4}{9}I$.
- $\dfrac{13}{9}I = e^{3t}\left(\dfrac{1}{3}\cos 2t + \dfrac{2}{9}\sin 2t\right)$.
- Sonuç: $I = \dfrac{e^{3t}(3\cos 2t + 2\sin 2t)}{13} + C$.
- Hoca önce integral sütununda $e^{3t}$'nin integralini yanlış yazıyor ($\tfrac{1}{3}$ katsayısını unutuyor), sonra düzeltiyor. "Ben uyuyorsam siz uyumayın" diyor.

### Örnek 6: $\displaystyle\int \arcsin x\,dx$

- Amaç: türevi $\arcsin x$ olan bir fonksiyon bulmak. Türevini değil, ters türevini arıyoruz.
- Normal değişken dönüşümü işe yaramaz. $1\cdot\arcsin x$ olarak düşünülür; $1$ bir polinomdur.
- $A$ (ters trigonometrik) $P$'den önce gelir: $u = \arcsin x$, $dv = dx$.
- $du = \dfrac{dx}{\sqrt{1-x^2}}$, $v = x$.
- $I = x\arcsin x - \displaystyle\int \frac{x\,dx}{\sqrt{1-x^2}}$.
- Değişken dönüşümü: $a = 1 - x^2$, $da = -2x\,dx$, yani $x\,dx = -\dfrac{1}{2}da$.
- $\displaystyle\int \frac{x\,dx}{\sqrt{1-x^2}} = -\frac{1}{2}\int a^{-1/2}\,da = -\sqrt{a}$.
- Sonuç: $x\arcsin x + \sqrt{1-x^2} + C$.

### Örnek 7: $\displaystyle\int \arctan x\,dx$

- $u = \arctan x$, $dv = dx$. $du = \dfrac{dx}{1+x^2}$, $v = x$.
- $I = x\arctan x - \displaystyle\int \frac{x\,dx}{1+x^2}$.
- $a = 1 + x^2$, $da = 2x\,dx$: $\displaystyle\int \frac{x\,dx}{1+x^2} = \frac{1}{2}\ln(1+x^2)$.
- Sonuç: $x\arctan x - \dfrac{1}{2}\ln(1+x^2) + C$.
- Kontrol: $\ln(1+x^2)$'nin türevi $\dfrac{2x}{1+x^2}$'dir.
- Bir öğrenci sınavda kısmi integrasyonla çözülmesinin söylenip söylenmeyeceğini soruyor. Hoca: Bunu sizin görmeniz lazım. Burada normal değişken dönüşümü yapılacak bir durum yok.

### Örnek 8: $\displaystyle\int \arctan\sqrt{x}\,dx$

- İntegrandda $\sqrt{x}$ olduğu için hem değişken dönüşümü hem kısmi integrasyon gerekir. Hoca önce üç yöntem gerekebileceğini söylüyor, sonra iki yöntemin yettiğini görüyor.
- $u = \arctan\sqrt{x}$, $dv = dx$.
  - $du = \dfrac{1}{1+x}\cdot\dfrac{1}{2\sqrt{x}}\,dx$, $v = x$.
- $I = x\arctan\sqrt{x} - \dfrac{1}{2}\displaystyle\int \frac{\sqrt{x}}{1+x}\,dx$.
  - Bir öğrenci paydada $2 + 2x$ olması gerektiğini hatırlatıyor. Hoca $\tfrac{1}{2}$'yi dışarı alıyor.
- $x = t^2$ ($t > 0$), $dx = 2t\,dt$:
  - $\dfrac{1}{2}\displaystyle\int \frac{t}{1+t^2}\,2t\,dt = \int \frac{t^2}{1+t^2}\,dt = \int\left(1 - \frac{1}{1+t^2}\right)dt = t - \arctan t$.
- Sonuç: $x\arctan\sqrt{x} - \sqrt{x} + \arctan\sqrt{x} + C$.
- Hoca bu sorunun test sınavının ruhuna biraz aykırı olduğunu, böyle bir sorunun gelmediğini söylüyor.

### Trigonometrik özdeşlikler

- $\sin(a \pm b) = \sin a\cos b \pm \cos a\sin b$. ($\cos$ çift, $\sin$ tek fonksiyondur.)
- $\cos(a \pm b) = \cos a\cos b \mp \sin a\sin b$.
- $b = a$ alınırsa: $\cos 2a = \cos^2 a - \sin^2 a$.
- $\sin^2 a = 1 - \cos^2 a$ yazılırsa: $\cos^2 a = \dfrac{1+\cos 2a}{2}$.
- Benzer şekilde: $\sin^2 a = \dfrac{1-\cos 2a}{2}$.
- Sol tarafta kuvvet 2, sağ tarafta $\cos 2a$'nın kuvveti 1. Kuvvet indirgenmiş olur.

### Örnek 9: $\displaystyle\int \cos^2 x\,dx$ ve $\displaystyle\int \sin^2 x\,dx$

- $\displaystyle\int \cos^2 x\,dx = \frac{1}{2}\int(1 + \cos 2x)\,dx = \frac{1}{2}\left(x + \frac{1}{2}\sin 2x\right) + C$.
- $\displaystyle\int \sin^2 x\,dx = \frac{1}{2}\left(x - \frac{1}{2}\sin 2x\right) + C$.

### Örnek 10: $\displaystyle\int \sin^3 x\,dx$ (tek kuvvet)

- Tek kuvvetli terim parçalanır: $\sin^3 x = \sin^2 x\,\sin x = (1 - \cos^2 x)\sin x$.
- $u = \cos x$, $du = -\sin x\,dx$.
- $\displaystyle -\int (1 - u^2)\,du = -u + \frac{u^3}{3} + C$.
- Sonuç: $-\cos x + \dfrac{\cos^3 x}{3} + C$.

### Örnek 11: $\displaystyle\int \sin^4 x\,dx$ (çift kuvvet)

- $\sin^4 x = \left(\dfrac{1-\cos 2x}{2}\right)^2 = \dfrac{1}{4}\left(1 - 2\cos 2x + \cos^2 2x\right)$.
- $\cos^2 2x$'in kuvveti yine çift, tekrar indirgenir: $\cos^2 2x = \dfrac{1+\cos 4x}{2}$.
- $\dfrac{1}{4}\left[x - \sin 2x + \dfrac{1}{2}\left(x + \dfrac{1}{4}\sin 4x\right)\right] + C$.
- Sadeleşmiş hâli: $\dfrac{3x}{8} - \dfrac{\sin 2x}{4} + \dfrac{\sin 4x}{32} + C$.
- Hoca sınavda bu kadar uzun bir sorunun gelmeyeceğini söylüyor.

### Örnek 12 (ödev): $\displaystyle\int \sin^5 x\,dx$

- $\sin^5 x = \sin^4 x\,\sin x = (1 - \cos^2 x)^2\sin x$ (büyük olasılıkla ekrandan; altyazıdan doğrulanmıyor).
- $u = \cos x$ ile polinom integraline döner.
- Sonuç: $-\cos x + \dfrac{2}{3}\cos^3 x - \dfrac{1}{5}\cos^5 x + C$.

### Örnek 13: $\displaystyle\int \sin^5 x\cos x\,dx$

- $u = \sin x$, $du = \cos x\,dx$ (büyük olasılıkla ekrandan; altyazıdan doğrulanmıyor).
- $\displaystyle\int u^5\,du = \frac{u^6}{6} + C = \frac{\sin^6 x}{6} + C$. Hoca bunu ödev bırakıyor.

### Örnek 14 (alıştırma): $\displaystyle\int \sin^5 x\cos^2 x\,dx$

- Tek kuvvetli terim ($\sin^5 x$) parçalanır: $\sin^4 x\cos^2 x\sin x = (1 - \cos^2 x)^2\cos^2 x\sin x$.
- $u = \cos x$, $\sin x\,dx = -du$.
- $\displaystyle -\int (1 - u^2)^2 u^2\,du$. Açılınca polinom integrali olur (ödev).
- Sonuç: $-\dfrac{\cos^3 x}{3} + \dfrac{2\cos^5 x}{5} - \dfrac{\cos^7 x}{7} + C$.

### Örnek 15: $\displaystyle\int \sin 2x\cos 3x\,dx$

- Bir öğrenci toplam formülünün kullanılacağını söylüyor.
- $\sin(A+B) + \sin(A-B) = 2\sin A\cos B$, yani $\sin A\cos B = \dfrac{\sin(A+B) + \sin(A-B)}{2}$.
- $A = 2x$, $B = 3x$: $\dfrac{1}{2}\displaystyle\int\left(\sin 5x + \sin(-x)\right)dx = \frac{1}{2}\int(\sin 5x - \sin x)\,dx$.
- $\sin$ tek fonksiyon: $\sin(-x) = -\sin x$.
- Sonuç: $\dfrac{1}{2}\left(-\dfrac{\cos 5x}{5} + \cos x\right) + C$.

### Örnek 16: $\displaystyle\int \sin 2x\sin 4x\,dx$

- $\cos(A-B) - \cos(A+B) = 2\sin A\sin B$, yani $\sin A\sin B = \dfrac{\cos(A-B) - \cos(A+B)}{2}$.
- $A = 2x$, $B = 4x$: $\dfrac{1}{2}\displaystyle\int\left(\cos(-2x) - \cos 6x\right)dx$.
- $\cos$ çift fonksiyon: $\cos(-2x) = \cos 2x$.
- Sonuç: $\dfrac{1}{2}\left(\dfrac{1}{2}\sin 2x - \dfrac{1}{6}\sin 6x\right) + C = \dfrac{\sin 2x}{4} - \dfrac{\sin 6x}{12} + C$.
- Farklı kombinasyonlar da gelebilir. Uygun toplam formülünü seçmek yeterli.

### Örnek 17: $\displaystyle\int \tan^2 x\,dx$

- $(\tan x)' = 1 + \tan^2 x$.
- İntegrandda $1$ yok; $1$ eklenip çıkarılır: $\displaystyle\int\left(1 + \tan^2 x - 1\right)dx$.
- Sonuç: $\tan x - x + C$.

### Örnek 18: $\displaystyle\int \tan^3 x\,dx$

- $\tan^3 x = \tan x\left(1 + \tan^2 x\right) - \tan x$.
- İlk kısım: $a = \tan x$, $da = (1 + \tan^2 x)\,dx$, yani $\displaystyle\int a\,da = \frac{a^2}{2}$.
- İkinci kısım: $\tan x = \dfrac{\sin x}{\cos x}$. $b = \cos x$, $db = -\sin x\,dx$, yani $\displaystyle\int\tan x\,dx = -\ln|\cos x|$.
- Sonuç: $\dfrac{\tan^2 x}{2} + \ln|\cos x| + C$.
- $\tan^4 x$, $\tan^5 x$ gibi kuvvetler için gelecek hafta indirgeme formülleri anlatılacak. Hoca öğrencilerden bu formülleri araştırmalarını istiyor.

### Ders sonrası notlar

- **Örnek 5'te ara adım:** Hoca "$-\tfrac{4}{9}I$'yı sola atınca $\tfrac{4}{9}I$ oluyor" diyor. Sol tarafta zaten $I$ olduğu için doğrusu $I + \tfrac{4}{9}I = \tfrac{13}{9}I$'dır. Hoca hemen ardından $\tfrac{13}{9}I$ yazıyor; sonuç doğru.
- **Örnek 16'da katsayı:** Altyazıda son satır "$\tfrac{1}{2}\sin 2x - \tfrac{1}{6}\sin 6x$" diye geçiyor. Dışarıdaki $\tfrac{1}{2}$ çarpanı unutulmamalı: $\dfrac{\sin 2x}{4} - \dfrac{\sin 6x}{12} + C$.
- **Örnek 8'in son satırı** altyazıda anlaşılmıyor. Doğru sonuç: $x\arctan\sqrt{x} - \sqrt{x} + \arctan\sqrt{x} + C$. Türev alarak kontrol edilebilir.
- **Örnek 1'de** hoca tablo yöntemini anlatırken önce "$\cos x$'in integrali $-\sin x$" diyor, hemen "$\sin x$" diye düzeltiyor.
- **LAPTE sıralaması** yaygın LIATE kuralıyla aynıdır (L: logaritma, I/A: ters trigonometrik, A/P: cebirsel/polinom, T: trigonometrik, E: üstel). Örnek 4'te trigonometrik fonksiyonu $u$ seçmek bu kurala uygundur. Döngüsel durumda $u = e^x$ seçmek de aynı sonucu verir.
- 00:04:54, 01:19:41 ve 01:21:19 civarında altyazı döngüye giriyor. Bu kısımların akışı sonraki cümlelerden kuruldu.
- 00:57:14 ile 01:12:02 arası ara verilmiş.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
