# Ders 14 Çalışma Özeti

## Genel Konular

- 1. vize öncesi son ders. Geçen yılın (büyük olasılıkla 2020 yaz okulu) MAT1071 vize sınavı, A grubu soruları çözülüyor. Sorular Türkçe, hoca İngilizce açıklıyor.
- Türev grafiğinden artanlık ve azalanlık (increasing / decreasing).
- Hiperbolik fonksiyonlar (hyperbolic functions).
- Tablo verisiyle ters fonksiyonun türevi, teğet doğru ve doğrusal yaklaşım (linear approximation).
- Kapalı türevle bilinmeyen sabiti bulma.
- Limitler: $0^0$ ve $\infty/\infty$ belirsizlikleri, sandviç teoremi (sandwich theorem), L'Hôpital kuralı.
- Kaldırılabilir süreksizlik (removable discontinuity).
- Türevin tanımı ve logaritmik türev.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Sınav düzeni:**
  - Sınav test. 4 yanlış 1 doğruyu götürür, yani 1 yanlış 0,25 doğru götürür.
  - Muhtemelen 20 soru.
  - Sınavda önceki sorulara geri dönülebilecek.
- **Soruların zorluğu:**
  - Hocaya göre geri dönüş olduğu için sorular biraz daha zor olabilir. Soruları dersi vermeyen bir komisyon hazırlıyor.
  - Hocanın tahmini: geçen yılın sınavından "bir iki tık" zor; yaklaşık 15 orta, 5 kolay soru. Derste çözülen sorular bunlardan zordur.
- **Konu sınırı:**
  - Ekstremum değerler, konkavlık (concavity), ortalama değer teoremi (mean value theorem) ve integral bu vizenin değil, finalin konusu.
  - Hoca bazı öğrencilerin integral sorusu gönderdiğini, derste integral anlatılmadığını hatırlattı.
- **Bu vizede ağırlık:** limit, türev, ters fonksiyonun türevi, türevin tanımı ve logaritmik türev. Bu sınavdan daha çok limit sorusu beklenebilir.
- **Çalışma önerisi:**
  - Ders notları ve videolar yeterli. Başka kaynaklara dağılmayın.
  - Çok soru çözmek değil, her sorunun arkasındaki mantığı anlamak önemli.
  - Hoca "Derste çözdüğümüz soruları bakmadan çözebiliyorsanız başarılı olursunuz" diyor.

## Kısa Tekrar Notları

- $f'>0$ olan aralıkta $f$ artan, $f'<0$ olan aralıkta azalandır.
- $\sinh x=\dfrac{e^x-e^{-x}}{2}$, $\cosh x=\dfrac{e^x+e^{-x}}{2}$, $\tanh x=\dfrac{\sinh x}{\cosh x}$.
- $(f^{-1})'(y_0)=\dfrac{1}{f'(x_0)}$, burada $f(x_0)=y_0$.
- Teğet doğru: $y-y_0=f'(x_0)(x-x_0)$.
- Doğrusal yaklaşım: $f(x)\approx f(a)+f'(a)(x-a)$, $a$ değeri $x$'e yakın seçilir.
- $\sin(\infty)$ biçimi görürseniz sandviç teoremini düşünün. Sinüsün argümanı sonsuza gitmiyorsa sandviç gerekmez.
- $\displaystyle\lim_{u\to0}\frac{\sin u}{u}=\lim_{u\to0}\frac{u}{\sin u}=1$. Her zaman L'Hôpital gerekmez.
- $0<a<1$ ise $a^{+\infty}\to0$ ve $a^{-\infty}\to\infty$. Bunlar belirsizlik değildir.
- Kaldırılabilir süreksizlik: sağ ve sol limit aynı ve sonlu, ama fonksiyon değeri farklı ya da tanımsız.

## Detaylı Açıklamalar

### Soru 1-3: Türev Grafiğinden Artanlık

- $f'$ fonksiyonunun grafiği veriliyor. "Hangisi söylenemez?" diye soruluyor.
- $f'>0$ olan aralıkta $f$ artan (ör. $(-2,1)$ aralığı), $f'<0$ olan aralıkta $f$ azalandır (ör. $(1,\infty)$).
- Hoca D ve E şıklarının (ekstremum) final konusu olduğunu söyleyip onlara bakmadı.
- Grafiğin kendisi altyazıda yok. Şıkların tamamı bu yüzden özete alınmadı.

### Soru 4: Hiperbolik İfade

$$\frac{1+\tanh x}{1-\tanh x}$$

- $\tanh x=\dfrac{e^x-e^{-x}}{e^x+e^{-x}}$ yazılır.
- Pay: $\dfrac{2e^x}{e^x+e^{-x}}$. Payda: $\dfrac{2e^{-x}}{e^x+e^{-x}}$.
- Oran: $\dfrac{e^x}{e^{-x}}=e^{2x}$. **Cevap: C.** (şık harfi altyazıda geçmiyor; büyük olasılıkla (ekrandan))

### Soru 5-7: Tablo Verisi

Üç soruda da aynı tablo kullanılıyor:

| $x$ | 1 | 2 | 3 |
|---|---|---|---|
| $f(x)$ | 6 | 4 | 1 |
| $f'(x)$ | -3 | 8 | -5 |

- **Soru 5: $(f^{-1})'(6)$.** $f(1)=6$ olduğundan $x_0=1$. Sonuç: $\dfrac{1}{f'(1)}=-\dfrac13$. **Cevap: C.**
- **Soru 6: $x=2$'deki teğet doğru.**
  - $x_0=2$, $y_0=4$, $f'(2)=8$. ($f(2)=4$ altyazıda geçmiyor; büyük olasılıkla (ekrandan).)
  - $y-4=8(x-2)$, yani $y=8x-12$. **Cevap: C.**
- **Soru 7: $f(3.1)$'in yaklaşık değeri.**
  - $a=3$ seçilir.
  - $f(3.1)\approx f(3)+f'(3)(0.1)=1+(-5)(0.1)=0.5$. **Cevap: A.**

### Soru 8: Kapalı Türevle Sabit Bulma

$x^2-c\sin(xy)=x+\tan y$ eğrisinin $(1,0)$ noktasındaki teğeti $y=-x+1$ ise $c$ kaçtır?

- Teğetin eğimi $y'(1)=-1$.
- $x$'e göre türev:

$$2x-c\cos(xy)\,(y+xy')=1+(1+\tan^2y)\,y'$$

- $(1,0)$ ve $y'=-1$ konursa: $2-c\cdot1\cdot(-1)=1+(-1)$.
- Buradan $c=-2$. **Cevap: B.**
- Bir öğrenci $\cos(xy)$'nin iç türevini sordu. Hocanın açıklaması:
  - $y$'yi $f(x)$ gibi düşün.
  - $(xy)'=1\cdot y+x\cdot y'$ (çarpım kuralı).
  - Bu ifade zincir kuralıyla $-\sin$ teriminin yanına çarpan olarak gelir.

### Soru 9: $0^0$ Belirsizliği

$$\lim_{x\to0^+}\left(\sin x^2\right)^{1/\ln x}$$

- $A=(\sin x^2)^{1/\ln x}$, $\ln A=\dfrac{\ln(\sin x^2)}{\ln x}$. Bu $\dfrac{\infty}{\infty}$ biçimidir.
- L'Hôpital:

$$\lim\frac{\dfrac{2x\cos x^2}{\sin x^2}}{\dfrac1x}=\lim 2\cos x^2\cdot\frac{x^2}{\sin x^2}=2$$

- Sonuç: $e^2$. **Cevap: D.** (şık harfi altyazıda geçmiyor; büyük olasılıkla (ekrandan))
- Bir öğrenci $\ln(\sin x^2)$'nin neden sonsuza gittiğini sordu. Hocanın açıklaması: $x\to0^+$ iken $\sin x^2\to0^+$, $\ln$ ise 0'a yakın pozitif sayılarda $-\infty$'a gider.

### Soru 10: Sandviç Teoremi

$$\lim_{x\to\infty}\frac{x\sin(x!)}{x^2+1}$$

- $\sin(x!)$, $-1$ ile $1$ arasında salınır.
- $-\dfrac{x}{x^2+1}\le\dfrac{x\sin(x!)}{x^2+1}\le\dfrac{x}{x^2+1}$. İki sınır da 0'a gider.
- **Cevap: A** (limit 0). (şık harfi altyazıda geçmiyor; büyük olasılıkla (ekrandan))

### Soru 11: L'Hôpital ve Zincir Kuralı

$f'(3)=2$ ise $\displaystyle\lim_{h\to2}\frac{f(h+1)-f(5-h)}{h-2}$ nedir?

- $h=2$ konunca $\dfrac00$ çıkar.
- L'Hôpital: $\dfrac{f'(h+1)\cdot1-f'(5-h)\cdot(-1)}{1}\to f'(3)+f'(3)=4$.
- Hoca ardından $f'(0)$ cinsinden daha karmaşık bir soru uydurdu. Tahtada yer kalmadığı için çözümü bitirmedi. Hocaya göre bu kadar uzun işlem isteyen soru sınavda çıkmaz.

### Soru 12: Ortalama Değer Teoremi

- Final konusu olduğu için çözülmedi.

### Soru 13: Zincir ve Çarpım Kuralı

$g(1)=1$, $g'(1)=2$ ve $f(x)=x\arctan\big(g(x)^2\big)$ ise $f'(1)$ nedir?

$$f'(x)=\arctan\big(g(x)^2\big)+x\cdot\frac{2g(x)g'(x)}{1+g(x)^4}$$

- $f'(1)=\arctan 1+\dfrac{2\cdot1\cdot2}{2}=\dfrac\pi4+2$.

### Soru 14: Tanım Kümesi

- Üç durumun kesişimiyle çözülüyor. Hoca bunu ödev bıraktı, soru altyazıda net değil.

### Soru 15: Temel Limitle Sadeleştirme

$$\lim_{x\to0}\frac{(\sin x)^{100}}{x^{99}\sin 2x}$$

- $\sin 2x=2\sin x\cos x$ yazılır:

$$\left(\frac{\sin x}{x}\right)^{99}\cdot\frac{\sin x}{2\sin x\cos x}\to\frac12$$

- **Cevap: B.** (şık harfi altyazıda geçmiyor; büyük olasılıkla (ekrandan)) L'Hôpital gerekmez.

### Soru 16: Limitin Yokluğu

$f$ pozitif değerli ve $\displaystyle\lim_{x\to0}x f(x)=3$ ise $\displaystyle\lim_{x\to0}\frac{f(x)}{|x|}$ nedir?

- Pay ve payda $x$ ile çarpılır (özdeş ifade, limit değişmez):

$$\frac{f(x)}{|x|}=\frac{x f(x)}{x|x|}$$

- Pay 3'e gider.
- Payda sağdan $0^+$'ya, soldan $0^-$'ya gider. Sonuç bir taraftan $+\infty$, öbür taraftan $-\infty$.
- **Cevap: C** (limit yok).

### Soru 17: Hangisi Yanlış?

- **a)** $\displaystyle\lim_{x\to\infty}x\sin\frac1x=1$. Doğru: $t=\dfrac1x$ denirse $\dfrac{\sin t}{t}\to1$.
- **Sinüs salınımı:** Sinüsün argümanı $\pm\infty$'a giderse $\sin t$'nin limiti yoktur. Bu ifade doğrudur.
- **Üstel limit:** $e^{1/x}$, $x\to0^-$ iken $0^+$'ya gider. Doğru.
- **D şıkkı yanlış:** $\left(\frac12\right)^{1/x}$ ifadesi sağdan 0'a, soldan $\infty$'a gider. Sağ ve sol limit farklı olduğu için "limit 0" ifadesi yanlıştır. **Cevap: D.**
- **Sandviç sorusu:** Bir öğrenci a şıkkında sandviç teoremini sordu. Hocanın cevabı: Sandviç için sinüsün argümanı sonsuza gitmeli. Burada $\dfrac1x\to0$ olduğu için sandviç uygulanmaz.

### Soru 18: Kaldırılabilir Süreksizlik ($x=2$)

- $\ln$ içeren şık: $\ln(0^+)=-\infty$. Bu sonsuz süreksizliktir (infinite discontinuity).
- $\sin\dfrac{2}{2-x}$ şıkkı: argüman $\pm\infty$'a gider, sinüs salınır, limit yoktur.
- Tanjant içeren şık: $\pm\infty$ çıkar, yine sonsuz süreksizlik.
- **Rasyonel şık:** Çarpanlarına ayrılınca $(x-2)$ sadeleşir ve $\dfrac{x+3}{x+2}$ kalır. Sağ ve sol limit $\dfrac54$'te aynıdır. Kaldırılabilir süreksizlik budur.
- **"Sinüs salınıyor" ne demek (öğrenci sorusu):** $x$ ekseninde yürüdükçe grafik $-1$ ile $1$ arasında gidip gelir. Hiçbir yatay doğruya yaklaşmaz. Bu yüzden limit yoktur.

### Soru 19: Türevin Tanımı

$g(0)=0$, $g'(0)=0$, $g''(0)=16$. $f(x)=\dfrac{g(x)}{x}$ ($x\ne0$) ve $f(0)=0$ ise $f'(0)$ nedir?

- Türevin tanımı:

$$f'(0)=\lim_{x\to0}\frac{f(x)-f(0)}{x}=\lim_{x\to0}\frac{g(x)}{x^2}$$

- $\dfrac00$ olduğu için L'Hôpital uygulanır: $\dfrac{g'(x)}{2x}$. Yine $\dfrac00$.
- İkinci kez L'Hôpital: $\dfrac{g''(x)}{2}\to\dfrac{16}{2}=8$.
- Doğrudan türev almaya çalışmak zaman kaybettirir. Hoca bunu "çok güzel bir soru" diye niteledi.

### Soru 20: Logaritmik Türev

$y=\sqrt[3]{\dfrac{(x+1)(x^2+1)}{(x^3+1)(x^4+1)}}$ ise $y'(1)$ nedir?

- $\ln$ alınır:

$$\ln y=\frac13\Big[\ln(x+1)+\ln(x^2+1)-\ln(x^3+1)-\ln(x^4+1)\Big]$$

- Türev:

$$\frac{y'}{y}=\frac13\left[\frac{1}{x+1}+\frac{2x}{x^2+1}-\frac{3x^2}{x^3+1}-\frac{4x^3}{x^4+1}\right]$$

- $x=1$'de $y(1)=1$ olur.
- $y'(1)=\dfrac13\left[\dfrac12+1-\dfrac32-2\right]=-\dfrac23$. **Cevap: B.**

### Ders sonrası notlar

- **Soru 6:** Hoca önce tablodaki $x=1$ sütununu kullanıp $y=-3x$ buldu. Bir öğrenci sorunun $x=2$'yi sorduğunu hatırlattı. Doğru cevap $y=8x-12$'dir.
- **Soru 16'daki çelişki:** $f$ pozitifse ve $x<0$ ise $x f(x)<0$ olur. Bu durumda $\displaystyle\lim_{x\to0}x f(x)=3$ soldan sağlanamaz. Soruda bir tutarsızlık var. Hoca da "pozitif değerli olmasının faydasını görmedik" dedi. Sınav cevabı yine C'dir.
- **Soru 11'in uzantısı:** Hocanın uydurduğu soruda öğrenciler bir işaret hatasını düzeltti ($1-\dfrac{\sin a}{a}$'nın türevinde eksi işareti). Soru bitirilmedi.
- **Altyazıda anlaşılmayan yerler:** Bazı yerlerde altyazı döngüye giriyor ("bu bölümde...", "yi'ye altyazı..."). Bu kısımlar tahtadaki çözümden tamamlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
