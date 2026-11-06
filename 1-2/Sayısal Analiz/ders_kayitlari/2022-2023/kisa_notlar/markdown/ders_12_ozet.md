# Ders 12 Çalışma Özeti

## Genel Konular

- Bu derste yeni konu işlenmedi. Kayıt proje gösterimlerinden oluşur. Aşağıda gösterimlerde çalıştırılan örnekler ve hocanın kod yorumları vardır.
- Gösterimlerde çalıştırılan örnekler (hocanın kontrol ettiği girdiler)
  - Newton-Raphson: $x^2 - 4x - 5$. $x_0 = 0$ ile kök $-1$, $x_0 = 6$ ile kök $5$ bulundu. Başka bir gösterimde $x^3 + x^2 - 9x - 9$ için kök $-1$ bulundu.
  - Matris tersi (büyük olasılıkla Ders 4'teki Gauss-Jordan yolu; ad altyazıda geçmiyor): $\begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 2 & 9 \end{bmatrix}$.
  - Simpson: $\int_1^3 (x^2 + 2x)\,dx$, $n = 6$, sonuç 16.666.
  - Gauss eliminasyon: $2x_1 + 5x_2 = 16$, $3x_1 + x_2 = 11$. Sonuç $x_1 = 3$, $x_2 = 2$.
  - Gregory-Newton: $x$: 0…6, $f$: −4, −2, 14, 62, 160, 326, 578. $x = 4.5$ için 233.375.
  - Regula falsi: $x^2 - 4x - 5$, aralık $[-1, 5]$, kök $-1$. Ders sonrası not: iki uç da köktür ($f(-1) = f(5) = 0$), $f(a) f(b) < 0$ sağlanmaz ve formülde payda sıfır olur. Yöntemi sınamak için kökü içine alan bir aralık (ör. $[0, 6]$) seçilmelidir.
- Hocanın kod hakkındaki yorumları
  - Newton-Raphson bir başlangıç değeriyle çalışır. Alt ve üst sınır istemek gereksiz.
  - Durma koşulu ardışık iki kökün mutlak farkının $\varepsilon$'dan küçük olmasıdır. Hoca iterasyon sayısı isteyen koda "10 bin iterasyon derim, belki 100'de sağlanır, boşuna döner" diye itiraz etti (00:05:22-00:05:39). Ders sonrası not: $\varepsilon$ kontrolü de varsa boşuna dönüş olmaz, üst sınır ıraksamaya karşı güvenlik sağlar. Asıl ölçüt yine bu farktır.
  - Gregory-Newton'da $x$ değerleri eşit aralıklı değilse $h$'yi sabit kabul etmek yanlıştır ("Sen hepsini eşit gibi mi düşündün?", 00:22:08). "Değişken dönüşümü" terimini bir öğrenci söyledi (00:21:55); Ders 10'daki yöntem budur.
  - Hoca birkaç gösterimde polinom girişinde neyin sorulduğunu (derece mi, terim sayısı mı, katsayı sırası mı) anlamakta zorlandı. Ders sonrası öneri: programınız girdi biçimini açıkça belirtsin.

## Hocanın Özellikle Vurguladığı Kısımlar

- Newton-Raphson'da başlangıç değeri, durma koşulunda ardışık köklerin farkı kullanılır.

## Kısa Tekrar Notları

- Newton-Raphson: başlangıç değeri yeter, durma için $|x_{k+1} - x_k| \le \varepsilon$.
- Gregory-Newton'da eşit olmayan aralıklarda $h$ sabit kabul edilemez.
- Regula falsi için $f(a) f(b) < 0$ gerekir. İki uç da kökse formülde payda sıfır olur.

## Detaylı Açıklamalar

### Ders sonrası notlar

- **Gösterim örneklerinin kontrolü:** Örnekler ders sonrasında Python ile yeniden hesaplandı. $x^2 - 4x - 5 = (x - 5)(x + 1)$, kökler 5 ve −1. $x^3 + x^2 - 9x - 9 = (x + 1)(x - 3)(x + 3)$, kökler −1, 3, −3. $\int_1^3 (x^2 + 2x)\,dx = \left[\frac{x^3}{3} + x^2\right]_1^3 = 16.667$. Ders 8'deki Gregory-Newton polinomu $3x^3 - 2x^2 + x - 4$, $x = 4.5$ için 233.375 verir.
- **Gösterimdeki matrisin tersi:** $\begin{bmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 2 & 9 \end{bmatrix}^{-1} = \begin{bmatrix} -0.9167 & 0.3333 & 0.0833 \\ -0.1667 & 0.3333 & -0.1667 \\ 0.75 & -0.3333 & 0.0833 \end{bmatrix}$. Kendi kodunuzu sınamak için kullanabilirsiniz.
- **Kendi kodunuzu sınamak için:** Hocanın yaptığı gibi kökleri bilinen polinomlar seçin (ör. $(x - a)(x - b)$ çarpımı) ve farklı başlangıç değerleriyle farklı köklerin bulunduğunu kontrol edin. Ders 5'te söylendiği gibi kök içermeyen bir aralık ve çok dar bir aralık da deneyin.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
