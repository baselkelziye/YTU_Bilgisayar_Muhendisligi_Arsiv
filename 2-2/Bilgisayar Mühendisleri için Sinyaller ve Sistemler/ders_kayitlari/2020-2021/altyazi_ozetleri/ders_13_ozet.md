# Ders 13 Çalışma Özeti

## Genel Konular

- Dersin tarihi 1 Eylül 2021 Çarşamba. Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:03'te başlar.
  - Hoca çözümleri PowerPoint'te kalemle yazarak anlattı. Slaytlar İngilizce.
- Laplace dönüşümünün devamı
  - Sol taraflı (left-sided), sağ taraflı (right-sided) ve iki taraflı (bilateral) sinyaller.
  - Aynı $X(s)$ ifadesine iki farklı sinyalin karşılık gelmesi ve yakınsama bölgesinin (ROC) önemi.
  - ROC kuralları: sağ taraflı sinyalde ROC en büyük kutbun sağında, sol taraflı sinyalde en küçük kutbun solundadır.
  - Kutup (pole) ve sıfır (zero) kavramları, sıfır-kutup diyagramı (pole-zero plot).
- Laplace dönüşümünün özellikleri
  - Zaman kayması, s-düzleminde kayma, konvolüsyon, türev, integral.
  - Başlangıç değer teoremi (initial value theorem) ve son değer teoremi (final value theorem).
  - Zaman ölçekleme, $t^n$ ile çarpma, sinüzoidal ile çarpma.
- Laplace dönüşümüyle diferansiyel denklem çözümü
  - Tek taraflı (unilateral) dönüşümde türev kuralı ve başlangıç koşulları.
  - Birinci dereceden RC devresi örneği: sıfır giriş cevabı (zero-input response) ve sıfır durum cevabı (zero-state response).
  - İkinci dereceden sistem örneği.
- Kısmi kesirlere ayırma (partial fraction expansion)
  - Farklı reel kökler, katlı kökler, karmaşık kökler.
  - Rezidüler (residues).
- Kararlılık ve nedensellik: sağ yarı düzlemde kutup, ROC'un $j\omega$ eksenini içermesi.
- ROC örnekleri: sağ taraflı, iki taraflı ve Laplace dönüşümü olmayan sinyaller.
- Final bilgisi ve sonraki ders (z-dönüşümü).

## Hocanın Özellikle Vurguladığı Kısımlar

- Laplace dönüşümünde ters dönüşüm için yalnız $X(s)$ yetmez. ROC da bilinmelidir.
  - $e^{-at}u(t)$ ve $-e^{-at}u(-t)$'nin ikisinin de dönüşümü $\frac{1}{s+a}$'dır. Farkı ROC belirler.
- ROC kuralı:
  - Sinyal sağ taraflıysa ROC en büyük kutbun sağındadır.
  - Sinyal sol taraflıysa ROC en küçük kutbun solundadır.
- Fourier dönüşümünün var olması için ROC $j\omega$ eksenini içermelidir.
- Gerçek hayattaki sistemlerde tek taraflı Laplace dönüşümü kullanılır.
  - Türev alırken $t = 0$ anındaki başlangıç değerleri çıkarılır.
  - Türev formüllerini ezberlemeye gerek yok. Mantık: her türevde $s$ ile çarp, o türevin başlangıç değerini çıkar.
- Diferansiyel denklemi Laplace dönüşümüyle cebirsel denkleme çevirmek çözümü kolaylaştırır.
- Hoca genellikle en fazla ikinci dereceden payda soracağını söyledi.
  - "Matematik bilginizi burada test etmiyoruz. Sinyal bilgisini ve bu özelliği kullanmak yeterli."
- Kısmi kesirlerde katsayıları bulmak için uzun denklem sistemi kurmaya gerek yoktur.
  - Paydayı sıfırlayan değeri $s$ yerine koymak yeterlidir.
- Final: 5-6 soru olacak, Laplace dönüşümünden soru gelecek.

## Kısa Tekrar Notları

- $e^{-at}u(t) \leftrightarrow \frac{1}{s+a}$, ROC: $\mathrm{Re}(s) > -a$ (sağ taraflı).
- $-e^{-at}u(-t) \leftrightarrow \frac{1}{s+a}$, ROC: $\mathrm{Re}(s) < -a$ (sol taraflı).
- Kutup: paydayı sıfır yapan $s$ değeri. Diyagramda × ile gösterilir.
- Sıfır: payı sıfır yapan $s$ değeri. Diyagramda ○ ile gösterilir.
- Özellikler:
  - Zaman kayması: $x(t - t_0) \leftrightarrow e^{-s t_0} X(s)$.
  - s-düzleminde kayma: $e^{s_0 t} x(t) \leftrightarrow X(s - s_0)$.
  - Konvolüsyon: $x_1(t) * x_2(t) \leftrightarrow X_1(s) X_2(s)$.
  - Türev (iki taraflı): $\frac{dx}{dt} \leftrightarrow s X(s)$.
  - İntegral: $\int_{-\infty}^{t} x(\tau)\, d\tau \leftrightarrow \frac{1}{s} X(s)$.
  - Zaman ölçekleme ($a > 0$): $x(at) \leftrightarrow \frac{1}{a} X\!\left(\frac{s}{a}\right)$.
  - Başlangıç değer teoremi: $x(0^+) = \lim_{s \to \infty} s X(s)$.
  - Son değer teoremi: $x(\infty) = \lim_{s \to 0} s X(s)$.
- Tek taraflı türev kuralları:
  - $y' \leftrightarrow sY(s) - y(0)$
  - $y'' \leftrightarrow s^2 Y(s) - s\, y(0) - y'(0)$
  - $y''' \leftrightarrow s^3 Y(s) - s^2 y(0) - s\, y'(0) - y''(0)$
- Transfer fonksiyonu: $H(s) = \frac{Y(s)}{X(s)}$ (başlangıç koşulları sıfırken). $Y(s) = X(s) H(s)$.
- Nedensel bir sistemin sağ yarı düzlemde kutbu varsa sistem kararsızdır.
- ROC $j\omega$ eksenini içeriyorsa sistem BIBO kararlıdır.
- Kısmi kesirler:
  - Farklı kökler: $\frac{F(s)}{(s-a)(s-b)} = \frac{A}{s-a} + \frac{B}{s-b}$.
  - Katlı kök: $\frac{F(s)}{(s-a)^2} = \frac{A}{s-a} + \frac{B}{(s-a)^2}$.
  - İkinci dereceden çarpan: $\frac{F(s)}{(s-a)(s^2+b)} = \frac{A}{s-a} + \frac{Bs + C}{s^2+b}$.

## Detaylı Açıklamalar

### Aynı dönüşüm, farklı sinyal

- Birinci sinyal: $x(t) = -e^{-at}u(-t)$.
  - $u(-t)$ yüzünden integral $-\infty$'dan $0$'a alınır.
  - $X(s) = -\int_{-\infty}^{0} e^{-(s+a)t}\, dt = \frac{1}{s+a}$.
  - İntegralin yakınsaması için $\mathrm{Re}(s+a) < 0$ olmalıdır. ROC: $\sigma < -a$.
- İkinci sinyal: $x(t) = e^{-at}u(t)$.
  - İntegral $0$'dan $\infty$'a alınır.
  - $X(s) = \frac{1}{s+a}$.
  - Yakınsama için $\mathrm{Re}(s+a) > 0$ olmalıdır. ROC: $\sigma > -a$.
- İki sinyalin dönüşümü aynıdır. Ters dönüşümde hangisinin kastedildiğini ROC söyler.
- Sınırların farklı olması şartın yönünü değiştirir.
  - Üst sınır $+\infty$ ise üs negatif olmalıdır.
  - Alt sınır $-\infty$ ise üs pozitif olmalıdır.
- Hangisinde Fourier dönüşümü vardır?
  - $a > 0$ için ikinci durumda ROC $j\omega$ eksenini içerir. Fourier ve Laplace dönüşümü eşittir.

### Sinyal türleri ve ROC kuralı

- Sol taraflı sinyal: yalnız $t < 0$ için tanımlı. Örnek: $e^{-at}u(-t)$.
- Sağ taraflı sinyal: yalnız $t > 0$ için tanımlı. Örnek: $e^{-at}u(t)$.
- İki taraflı sinyal: $t$'nin bütün değerleri için tanımlı. Örnek: $e^{at}$ (basamak çarpanı olmadan).
  - Hoca matematikçilerin bu en genel hâlle uğraştığını, elektronik ve bilgisayar tarafında genellikle tek taraflı sinyallerle çalışıldığını söyledi.
- Kural:
  - Sol taraflı sinyalde ROC en küçük kutbun solundadır.
  - Sağ taraflı sinyalde ROC en büyük kutbun sağındadır.
- Örnek: $X(s) = \frac{1}{(s-a)(s-b)(s-c)}$ üç kutupludur. Sinyal sağ taraflıysa ROC en sağdaki kutbun sağındadır.

### İki kutuplu örnek

- $x(t) = 3e^{-2t}u(t) - 2e^{-t}u(t)$.
- Doğrusallıktan:
  - $3e^{-2t}u(t) \to \frac{3}{s+2}$, ROC: $\sigma > -2$.
  - $-2e^{-t}u(t) \to \frac{-2}{s+1}$, ROC: $\sigma > -1$.
- Payda eşitlenir:
  - $X(s) = \frac{3(s+1) - 2(s+2)}{(s+1)(s+2)} = \frac{s - 1}{(s+1)(s+2)}$.
- Kutuplar: $s = -1$ ve $s = -2$. Sıfır: $s = 1$.
- Sinyal sağ taraflıdır. ROC en büyük kutbun ($-1$) sağındadır: $\sigma > -1$.
- ROC $j\omega$ eksenini içerir. Bu yüzden sinyalin Fourier dönüşümü vardır.

### Laplace dönüşümünün özellikleri

- Zaman kayması: $x(t - t_0) \leftrightarrow e^{-s t_0} X(s)$.
  - Dönüşümü sıfırdan yeniden hesaplamaya gerek yoktur.
- s-düzleminde kayma: $X(s - s_0) \leftrightarrow e^{s_0 t} x(t)$.
- Konvolüsyon: $x_1(t) * x_2(t) \leftrightarrow X_1(s)\, X_2(s)$.
- Türev: Fourier dönüşümünde $j\omega$ ile çarpılıyordu. Laplace dönüşümünde $s$ ile çarpılır.
- İntegral: $\frac{1}{s}$ ile çarpılır.
  - Türev ile integral birbirinin tersidir: biri $s$ ile çarpar, öbürü $s$'ye böler.
- Başlangıç değer teoremi:
  - Sistemi açtıktan hemen sonraki değeri verir.
  - $x(0^+) = \lim_{s \to \infty} s X(s)$.
  - Zaman düzlemindeki sıfır anı, s-düzlemindeki sonsuza karşılık gelir.
- Son değer teoremi:
  - Sistemin $t \to \infty$'daki davranışını verir.
  - $x(\infty) = \lim_{s \to 0} s X(s)$.
- Zaman ölçekleme: $x(at) \leftrightarrow \frac{1}{a} X\!\left(\frac{s}{a}\right)$, $a > 0$.
- $t^n$ ile çarpma: $(-1)^n \frac{d^n X(s)}{ds^n}$.
  - Yüksek $n$ için ek maliyet getirir; her derece için bir türev alınır.
- Hoca dersin geri kalanında en çok türev, başlangıç ve son değer özelliklerinin kullanılacağını söyledi.

### Sistem çıkışının bulunması

- $h(t)$ veya $H(s)$, sistemin nasıl davrandığını söyler.
- Çıkış: $Y(s) = X(s)\, H(s)$.
  - Zaman düzleminde konvolüsyon olan işlem s-düzleminde çarpmadır.
- $Y(s)$'nin ters Laplace dönüşümü alınınca sistemin çıkışı $y(t)$ bulunur.

### Birinci dereceden RC devresi

- Devre denklemi: $\frac{dy}{dt} + \frac{1}{RC}\, y(t) = \frac{1}{RC}\, x(t)$.
- Genel hâl: $y' + a\, y = b\, x$. Burada $a = b = \frac{1}{RC}$.
- Sinyal sağ taraflıdır, tek taraflı dönüşüm kullanılır:
  - $s Y(s) - y(0^-) + a Y(s) = b X(s)$.
  - $Y(s)(s + a) = b X(s) + y(0^-)$.
  - $Y(s) = \frac{y(0^-)}{s + a} + \frac{b X(s)}{s + a}$.
- Birinci terim başlangıç koşuluna (devredeki ilk gerilime) bağlıdır. İkinci terim girişe bağlıdır.
- Giriş $x(t) = u(t)$ (1 V'luk sabit gerilim) ise $X(s) = \frac{1}{s}$.
  - Örnek: 5 V verilirse $X(s) = \frac{5}{s}$ olur.
- Sıfır giriş cevabı (zero-input response):
  - $\frac{y(0^-)}{s + 1/RC} \to y(0^-)\, e^{-t/RC}\, u(t)$.
  - Başlangıç değerinden başlar ve sönümlenerek sıfıra gider.
- Sıfır durum cevabı (zero-state response):
  - $\frac{1/RC}{s(s + 1/RC)} = \frac{1}{s} - \frac{1}{s + 1/RC}$.
  - Ters dönüşüm: $\left(1 - e^{-t/RC}\right) u(t)$.
  - Sıfırdan başlar ve 1'e yükselir.
- Toplam cevap iki parçanın toplamıdır.
  - Örnek: $y(0^-) = 5$ ise $y(t) = 5e^{-t/RC} + 1 - e^{-t/RC} = 1 + 4e^{-t/RC}$, $t \ge 0$.
  - Çıkış 5'ten başlar, azalır ve 1'de oturur (sıfıra kadar inmez).

### Tek taraflı dönüşümde yüksek dereceli türevler

- İki taraflı dönüşümde $y'' \leftrightarrow s^2 Y(s)$'dir.
- Tek taraflı dönüşümde her türev adımında başlangıç değeri çıkarılır:
  - $y' \leftrightarrow sY(s) - y(0)$.
  - $y'' \leftrightarrow s\left[sY(s) - y(0)\right] - y'(0) = s^2 Y(s) - s\, y(0) - y'(0)$.
  - $y''' \leftrightarrow s^3 Y(s) - s^2 y(0) - s\, y'(0) - y''(0)$.
- Soruda $y(0)$, $y'(0)$ gibi değerler sayı olarak verilir. Bunlar doğrudan yerine yazılır.
- İkinci dereceden sistemler, iki enerji depolayan eleman içeren devrelerde görülür.
  - Genel denklem: $y'' + a_1 y' + a_0 y = b_1 x' + b_0 x$.
  - Giriş nedenselse ($t < 0$ için $x(t) = 0$) $x(0^-) = 0$'dır. Bu terim yazılmaz.
- $Y(s)$ iki parçaya ayrılır:
  - Başlangıç koşullarından gelen parça (sıfır giriş cevabı).
  - Girişten gelen parça (sıfır durum cevabı).
- Başlangıç koşulları sıfırsa $\frac{Y(s)}{X(s)}$ transfer fonksiyonudur.
- Cevabın bir kısmı zamanla yok olur: geçici cevap (transient response). Bir kısmı kalır: kalıcı cevap (steady-state response).

### Kısmi kesirlere ayırma

- Ters Laplace integrali zordur. Bu yüzden $X(s)$ basit kesirlere ayrılır ve tablo kullanılır.
- Farklı reel kökler:
  - $\frac{F(s)}{(s-a)(s-b)(s-c)} = \frac{A}{s-a} + \frac{B}{s-b} + \frac{C}{s-c}$.
  - $F(s) = A(s-b)(s-c) + B(s-a)(s-c) + C(s-a)(s-b)$.
  - $s = a$ yazılınca $A$, $s = b$ yazılınca $B$, $s = c$ yazılınca $C$ bulunur.
  - Örnek: $\frac{A}{s-5} \to A e^{5t} u(t)$.
- Katlı kök:
  - Örnek payda: $s^2 - 2s + 1 = (s-1)^2$.
  - $\frac{F(s)}{(s-a)^2} = \frac{A}{s-a} + \frac{B}{(s-a)^2}$.
  - $F(s) = A(s-a) + B$. Önce $s = a$ yazılır ve $B$ bulunur. Sonra başka bir $s$ değeriyle $A$ bulunur.
- Karmaşık kökler:
  - Payda tam kareye tamamlanır.
  - Örnek: $\frac{2s - 3}{s^2 - 2s + 5} = \frac{2s-3}{(s-1)^2 + 4}$.
  - Paydaki ifade $(s-1)$ cinsinden yazılır. Sonuç kosinüs ve sinüs terimlerine $e^{t}$ çarpanıyla karşılık gelir.
- Örnek: $\frac{3s - 1}{s^2 + 3s + 2}$.
  - Payda: $(s+1)(s+2)$.
  - $\frac{3s-1}{(s+1)(s+2)} = \frac{A}{s+2} + \frac{B}{s+1}$.
  - $s = -1$: $B = -4$. $s = -2$: $A = 7$.
  - Sonuç: $7e^{-2t}u(t) - 4e^{-t}u(t)$.
  - $A$ ve $B$'ye rezidü (residue) denir.
  - Hoca katsayıları denklem sistemiyle ($A + B = 3$, $A + 2B = -1$) bulmanın uzun yol olduğunu söyledi.

### Kutuplar ve sıfırlar

- Sıfır: payı sıfır yapan değer. Kutup: paydayı sıfır yapan değer.
- Kutupta sistemin değeri sonsuza gider.
- Kutuplar ve sıfırlar bilinirse $H(s)$ bir sabit çarpan (kazanç) dışında bilinir.
- Slayttaki örnek:
  - $H(s) = \frac{2s^2 + 12s + 20}{s^3 + 6s^2 + 10s + 8} = \frac{2(s+3-j)(s+3+j)}{(s+4)(s+1-j)(s+1+j)}$.
  - Kutuplar: $-4$, $-1 + j$, $-1 - j$.
  - Sıfırlar: $-3 + j$, $-3 - j$.
  - Katsayılar reel olduğu için karmaşık kökler eşlenik çiftler hâlinde gelir.
- MATLAB'de pay ve payda katsayıları verilince sıfır-kutup diyagramı çizilebilir.
- $s = j\omega$ yazılınca transfer fonksiyonundan frekans cevabı $H(\omega)$ elde edilir.
  - Bunun için sistemin Fourier dönüşümü var olmalıdır.
- Kutup $j\omega$ eksenine yaklaştıkça frekans cevabında daha keskin ve yüksek tepeler oluşur. Uzaklaştıkça etkisi azalır.

### Kararlılık ve nedensellik

- Nedensellik: $t < 0$ için $h(t) = 0$. Yani $h(t)$ sağ taraflıdır ($u(t)$ içerir).
- Nedensel bir sistemin sağ yarı düzlemde kutbu varsa sistem kararsızdır.
- ROC $j\omega$ eksenini içeriyorsa sistem BIBO (sınırlı giriş-sınırlı çıkış) kararlıdır.
- ROC iki kutup arasında da olabilir. Bu durumda sinyal ne sağ taraflı ne sol taraflıdır.

### İkinci dereceden diferansiyel denklem örneği

- Denklem: $y'' + 3y' + 2y = x(t)$, $x(t) = u(t)$, $y(0) = 1$, $y'(0) = 2$.
- Laplace dönüşümü:
  - $s^2 Y(s) - s - 2 + 3\left[sY(s) - 1\right] + 2Y(s) = \frac{1}{s}$.
  - $Y(s)(s^2 + 3s + 2) = \frac{1}{s} + s + 5$.
  - $Y(s) = \frac{s^2 + 5s + 1}{s(s+1)(s+2)}$.
- Kısmi kesirler:
  - $Y(s) = \frac{1/2}{s} + \frac{3}{s+1} - \frac{5/2}{s+2}$.
- Sonuç: $y(t) = \left(\frac{1}{2} + 3e^{-t} - \frac{5}{2}e^{-2t}\right) u(t)$.
  - Kontrol: $y(0) = \frac{1}{2} + 3 - \frac{5}{2} = 1$. $y'(0) = -3 + 5 = 2$.
- Hoca derste vakit kalmadığı için son adımı ayrıntılı çözmedi. Yukarıdaki sonuç özet için hesaplandı.
- Adımlar: denklemin dönüşümünü al, başlangıç koşullarını yaz, $Y(s)$'yi yalnız bırak, basit kesirlere ayır, ters dönüşüm al.

### ROC örnekleri

- Örnek 1: $x(t) = e^{-2t}u(t) + e^{-3t}u(t)$.
  - $X(s) = \frac{1}{s+2} + \frac{1}{s+3} = \frac{2s + 5}{(s+2)(s+3)}$.
  - Kutuplar: $-2$ ve $-3$. Sıfır: $-\frac{5}{2}$.
  - Sağ taraflı sinyal. ROC: $\sigma > -2$.
- Örnek 2: $x(t) = e^{-3t}u(t) + e^{2t}u(-t)$.
  - $e^{-3t}u(t) \to \frac{1}{s+3}$, $\sigma > -3$.
  - $e^{2t}u(-t) \to -\frac{1}{s-2}$, $\sigma < 2$.
  - $X(s) = \frac{1}{s+3} - \frac{1}{s-2} = \frac{-5}{(s+3)(s-2)}$.
  - Kutuplar: $-3$ ve $2$. Sıfır yok.
  - Sinyal iki taraflıdır. ROC: $-3 < \sigma < 2$ (iki kutup arasındaki şerit).
- Örnek 3: $x(t) = e^{2t}u(t) + e^{-3t}u(-t)$.
  - $e^{2t}u(t) \to \frac{1}{s-2}$, $\sigma > 2$.
  - $e^{-3t}u(-t) \to -\frac{1}{s+3}$, $\sigma < -3$.
  - İki ROC kesişmez. Bu sinyalin Laplace dönüşümü yoktur.
- Örnek 4 (ters dönüşüm): $X(s) = \frac{2s + 4}{s^2 + 4s + 3}$.
  - Payda: $(s+1)(s+3)$.
  - $A(s+3) + B(s+1) = 2s + 4$. $s = -1$: $A = 1$. $s = -3$: $B = 1$.
  - $X(s) = \frac{1}{s+1} + \frac{1}{s+3}$.
  - Soruda ROC verilmelidir. Hoca ROC'u $-3 < \sigma < -1$ olarak aldı.
  - $\frac{1}{s+1}$ için $\sigma < -1$: sol taraflı terim, $-e^{-t}u(-t)$.
  - $\frac{1}{s+3}$ için $\sigma > -3$: sağ taraflı terim, $e^{-3t}u(t)$.
  - Sonuç: $x(t) = -e^{-t}u(-t) + e^{-3t}u(t)$.

### İkinci dereceden çarpanlı kısmi kesir örneği

- $X(s) = \frac{2s + 1}{(s-2)(s^2+9)} = \frac{A}{s-2} + \frac{Bs + C}{s^2 + 9}$.
- İkinci dereceden çarpanın payı birinci dereceden yazılır ($Bs + C$).
  - Çarpan üçüncü dereceden olsaydı pay $Bs^2 + Cs + D$ olurdu.
- Burada $s$ yerine değer koymak tek başına yetmez. İfade açılır:
  - $2s + 1 = s^2(A + B) + s(C - 2B) + (9A - 2C)$.
  - $A + B = 0$, $C - 2B = 2$, $9A - 2C = 1$.
- Çözüm: $A = \frac{5}{13}$, $B = -\frac{5}{13}$, $C = \frac{16}{13}$.
- Ters dönüşüm (sağ taraflı kabul edilerek):
  - $x(t) = \left[\frac{5}{13}e^{2t} - \frac{5}{13}\cos(3t) + \frac{16}{39}\sin(3t)\right] u(t)$.
  - $\frac{C}{s^2+9} = \frac{C}{3} \cdot \frac{3}{s^2+9} \to \frac{C}{3}\sin(3t)$.

### Duyurular

- Final: 5-6 soru. Laplace dönüşümünden soru gelecek.
- Cumartesi dersinde z-dönüşümü (Laplace dönüşümünün ayrık zamandaki karşılığı) anlatılacak ve 3-5 örnek çözülecek.
- Notlar: USİS kapanıyor, yeni sistem OBS (obs.yildiz.edu.tr). Hoca henüz not giremediğini söyledi.
- Ödev 2 hakkında bir öğrencinin sorusu: genliği sıfır olan harmonikler çizdirilirse yanlış dalga elde edilir. Katsayıları sıfırdan farklı olan bileşenler kullanılmalıdır.

### Ders sonrası notlar

- **Kısmi kesir örneğinin katsayıları:** Hoca $\frac{2s+1}{(s-2)(s^2+9)}$ örneğinde $A = \frac{6}{13}$, $B = -\frac{6}{13}$, $C = \frac{14}{13}$ buldu. Bu değerler yanlış.
  - Hocanın yazdığı denklemler doğrudur: $A + B = 0$, $C - 2B = 2$, $9A - 2C = 1$.
  - Bu denklemlerin çözümü $A = \frac{5}{13}$, $B = -\frac{5}{13}$, $C = \frac{16}{13}$'tür.
  - Kısa kontrol: $s = 2$ yazılırsa $2(2) + 1 = A(4 + 9)$, yani $A = \frac{5}{13}$.
  - Doğru sonuç: $\frac{5}{13}e^{2t} - \frac{5}{13}\cos(3t) + \frac{16}{39}\sin(3t)$.
  - Sonuç Python ile sayısal Laplace integrali alınarak doğrulandı.
- **RC devresinin ROC'u:** Hoca "sigma değeri bir bölü RC'den büyük" dedi. Doğrusu: $\frac{1}{s + 1/RC}$ için ROC $\sigma > -\frac{1}{RC}$'dir.
- **Konvolüsyon özelliği:** Hoca $X_1(s)$ ile $X_2(s)$ arasındaki işlemi "vektörel çarpım" diye andı. Bu sıradan (skaler) çarpmadır: $X_1(s)\, X_2(s)$. ROC en az iki ROC'un kesişimini içerir.
- **Sinüzoidal ile çarpma:** Hoca "sinüsle çarpmak S düzleminde $j\omega$ kadar öteleme demektir" dedi. Tam ifade:
  - $x(t)\cos(\omega_0 t) \leftrightarrow \frac{1}{2}\left[X(s - j\omega_0) + X(s + j\omega_0)\right]$.
  - $x(t)\sin(\omega_0 t) \leftrightarrow \frac{1}{2j}\left[X(s - j\omega_0) - X(s + j\omega_0)\right]$.
  - Yani iki yöne yarım genlikli iki öteleme vardır.
- **$\frac{3s-1}{(s+1)(s+2)}$ örneği:** Hoca sonucu önce "$7e^{-t}$" diye söyledi, sonra slaytta $7e^{-2t}$ olarak düzeltti. Doğrusu $7e^{-2t}u(t) - 4e^{-t}u(t)$'dir.
- **Sıfır-kutup örneğinin katsayıları:** Hoca MATLAB örneğini anlatırken payda katsayılarını "1, 6, 18" diye söyledi. Slayttaki payda $s^3 + 6s^2 + 10s + 8$'dir, yani katsayılar $1, 6, 10, 8$'dir. Pay katsayıları $2, 12, 20$'dir. Kökler Python ile doğrulandı.
- **İkinci dereceden örneğin sonucu:** Hoca son adımı sözlü ve karışık söyledi ("1/2 ... 4 ... 3"). Doğru sonuç $y(t) = \frac{1}{2} + 3e^{-t} - \frac{5}{2}e^{-2t}$'dir ($t \ge 0$). Sonuç denklemi ve iki başlangıç koşulunu sağlıyor; Python ile kontrol edildi.
- **Karmaşık kök örneği:** Hoca $\frac{2s-3}{(s-1)^2+4}$ için $\frac{As + B}{\cdots} + \frac{C}{\cdots}$ biçiminde üç bilinmeyenli bir yazım gösterdi. Bu gereksiz uzun. Kısa yol:
  - $2s - 3 = 2(s-1) - 1$.
  - $\frac{2(s-1)}{(s-1)^2+4} - \frac{1}{2} \cdot \frac{2}{(s-1)^2+4}$.
  - Sonuç: $e^{t}\left[2\cos(2t) - \frac{1}{2}\sin(2t)\right] u(t)$. Python ile doğrulandı.
- **Son değer teoremi:** Teorem yalnız $sX(s)$'nin bütün kutupları sol yarı düzlemdeyse geçerlidir. Örneğin $x(t) = e^{t}u(t)$ için $\lim_{s\to 0} s \cdot \frac{1}{s-1} = 0$ çıkar ama sinyal sonsuza gider.
- **Kutup için "sonsuza gitmek":** Kutupta $|H(s)|$ sonsuza gider. Bu, sistemin zaman cevabının sonsuza gittiği anlamına gelmez. Zaman cevabının davranışını kutbun s-düzlemindeki yeri belirler.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
