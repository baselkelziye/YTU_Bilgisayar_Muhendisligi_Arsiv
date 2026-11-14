# Ders 3 Çalışma Özeti

## Genel Konular

- $\lim_{\theta\to0}\frac{\sin\theta}{\theta}=1$ formülünün birim çember ve sıkıştırma teoremiyle kanıtı.
- Bu formülün genel hâli: $u(x)\to0$ ise $\frac{\sin u(x)}{u(x)}\to1$ ve $\frac{\tan u(x)}{u(x)}\to1$.
- L'Hôpital kullanmadan trigonometrik limitler: eşlenik yöntemi, değişken değiştirme, toplam formülleri.
- Parçalı fonksiyonda süreklilik incelemesi.
- Ara değer teoremi (Intermediate Value Theorem) ve kök varlığı.
- Süreksizlik türleri: kaldırılabilir (removable), sıçrama (jump), sonsuz (infinite) süreksizlik.
- Geçmiş yıl sınav soruları ve alıştırmalar.

## Hocanın Özellikle Vurguladığı Kısımlar

- İki formülü karıştırmayın:
  - $\lim_{x\to0}\frac{\sin x}{x}=1$ ($\frac00$ belirsizliği var).
  - $\lim_{x\to\infty}\frac{\sin x}{x}=0$ (sıkıştırma teoremi; $\sin x$ sınırlı, $x$ sınırsız).
- Amaç sonuca ulaşmak değil, yöntemi öğrenmek. L'Hôpital her zaman işe yaramaz. Bazı sorularda L'Hôpital uygulandıkça yeniden belirsizlik çıkar.
- İki limit aynı belirsizlik türündeyse (ör. $\frac00$), değişken değiştirme veya düzenlemeyle bilinen formüle benzetin.
- $\frac{\sin u}{u}$ kuralını kullanmak için $x\to a$ iken $u\to0$ olmalı. Bu koşulu mutlaka kontrol edin.
- $1-\cos(\dots)$ görürseniz ve belirsizlik $\frac00$ ise eşleniği $1+\cos(\dots)$ ile çarpıp bölün.
- Kök (karekök) görürseniz eşlenik yöntemini düşünün.
- Sıkıştırma teoremi için $\cos(\pm\infty)$ veya $\sin(\pm\infty)$ gibi salınan bir ifade gerekir.
- Ara değer teoremi için fonksiyon kapalı aralıkta sürekli olmalı.
- Açılar radyan cinsindendir. Dairesel dilimin alanı $\frac12r^2\theta$ (radyan).
- Test sınavında "Hangi ifadeler doğrudur?" tipinde ara değer teoremi soruları gelebilir.

## Kısa Tekrar Notları

- **Temel formül:** $\lim_{\theta\to0}\frac{\sin\theta}{\theta}=1$.
- **Genel hâl:** $\lim_{x\to a}u(x)=0$ ise

$$\lim_{x\to a}\frac{\sin u(x)}{u(x)}=\lim_{u\to0}\frac{\sin u}{u}=1,\qquad \lim_{x\to a}\frac{\tan u(x)}{u(x)}=1$$

- **Sonuçlar:** $\lim_{x\to0}\frac{\tan x}{x}=1$, $\lim_{x\to0}\frac{\sin ax}{bx}=\frac ab$ ($a,b\ne0$).
- **$\lim_{x\to0}\frac{1-\cos x}{x}=0$.**
- **Ara değer teoremi:** $f$, $[a,b]$'de sürekli ve $L$, $f(a)$ ile $f(b)$ arasında ise $f(c)=L$ olan en az bir $c\in[a,b]$ vardır.
- **Kök için:** $f(a)$ ve $f(b)$ zıt işaretliyse $f$'nin $(a,b)$'de en az bir kökü vardır.
- **Kaldırılabilir süreksizlik:** limit var ama $f(a)$'ya eşit değil (veya $f(a)$ tanımsız). Yeni bir fonksiyon tanımlanarak giderilir.
- **Sıçrama süreksizliği:** sol ve sağ limit sonlu ama farklı.
- **Sonsuz süreksizlik:** tek taraflı limitlerden en az biri $\pm\infty$.

## Detaylı Açıklamalar

### $\lim_{\theta\to0}\frac{\sin\theta}{\theta}=1$ Kanıtı (L'Hôpital'siz)

- Birim çember çizilir. $O$ merkez, $A=(1,0)$, $P$ çember üzerinde, $T$ çubuğun uzantısının tanjant eksenini kestiği nokta.
- **Durum 1:** $\theta\to0^+$ ($0<\theta<\frac\pi2$).
  - $\triangle OAP$ alanı: taban 1, yükseklik $\sin\theta$. Alan $\frac{\sin\theta}{2}$.
  - $OAP$ dairesel diliminin alanı: $\frac12r^2\theta=\frac\theta2$ ($r=1$, radyan).
    - Derece cinsinden olsaydı: $\frac{\alpha}{360^\circ}\pi r^2$.
  - $\triangle OAT$ alanı: yükseklik $\tan\theta$. Alan $\frac{\tan\theta}{2}$.
  - Alanlar sıralanır:

$$\frac{\sin\theta}{2}<\frac{\theta}{2}<\frac{\tan\theta}{2}$$

  - Ödev: Bu eşitsizliği düzenleyip (hoca her tarafı $\theta$'ya bölmeyi önerdi) sıkıştırma teoremini uygulayın. $\lim_{\theta\to0^+}\frac{\sin\theta}{\theta}=1$ çıkar.
- **Durum 2:** $\theta\to0^-$ ($-\frac\pi2<\theta<0$). Benzer şekilde $\lim_{\theta\to0^-}\frac{\sin\theta}{\theta}=1$.
- İki tek taraflı limit eşit. Sonuç: $\lim_{\theta\to0}\frac{\sin\theta}{\theta}=1$.
- **Öğrenci sorusu:** Neden $\lim\sin x$ ve $\lim x$ ayrı ayrı alınıp sıkıştırma teoremi doğrudan uygulanamıyor?
  - Çünkü ikisi de 0'a gider ve $\frac00$ belirsizliği çıkar. Bölüm kuralı payda limiti 0 olunca kullanılamaz.

### Örnek 1: $\lim_{x\to0}\frac{1-\cos x}{x}$

- $\frac00$ belirsizliği. Eşlenik $1+\cos x$ ile çarpılıp bölünür:

$$\lim_{x\to0}\frac{1-\cos^2x}{x(1+\cos x)}=\lim_{x\to0}\frac{\sin x}{x}\cdot\sin x\cdot\frac{1}{1+\cos x}=1\cdot0\cdot\frac12=0$$

- Çarpım kuralını kullanmadan önce her çarpanın limitinin var olduğu kontrol edilir.

### Örnek 2: Değişken Değiştirme

- $\lim_{x\to1}\frac{\cos\frac{\pi x}{2}}{x-1}$. $x=1$'de $\frac00$.
- $t=x-1$ dönüşümü: $x\to1$ iken $t\to0$, $x=t+1$.

$$\cos\left(\frac{\pi t}{2}+\frac\pi2\right)=\cos\frac{\pi t}{2}\cos\frac\pi2-\sin\frac{\pi t}{2}\sin\frac\pi2=-\sin\frac{\pi t}{2}$$

- $u=\frac{\pi t}{2}$ yazılır. $t\to0$ iken $u\to0$. Pay ve payda $\frac\pi2$ ile düzenlenir:

$$\lim_{t\to0}\frac{-\sin\frac{\pi t}{2}}{t}=-\frac\pi2\lim_{u\to0}\frac{\sin u}{u}=-\frac\pi2$$

### Örnek 3: $\lim_{x\to1}\frac{\sin(x^2-1)}{x-1}$

- $u=x^2-1$. $x\to1$ iken $u\to0$. Koşul sağlanıyor.
- $u$'yu paydada oluşturmak için $x+1$ ile çarpılıp bölünür:

$$\lim_{x\to1}\frac{\sin(x^2-1)}{x^2-1}\cdot(x+1)=1\cdot2=2$$

### Örnek 4: $\lim_{x\to0}\frac{\sin(\sin x)}{x}$

- $u=\sin x$. $x\to0$ iken $u\to0$.
- $\sin x$ ile çarpılıp bölünür:

$$\lim_{x\to0}\frac{\sin(\sin x)}{\sin x}\cdot\frac{\sin x}{x}=1\cdot1=1$$

### Örnek 5: $\tan$ ile

- $\lim_{x\to0}\frac{\tan x}{x}=\lim_{x\to0}\frac{\sin x}{x}\cdot\frac{1}{\cos x}=1$.
- **Örnek 6:** $\lim_{x\to\infty}\frac{x\tan\frac{\sin x}{x}}{\sin x}$.
  - Yeniden yazılır: $\frac{\tan\frac{\sin x}{x}}{\frac{\sin x}{x}}$.
  - $u=\frac{\sin x}{x}$. $x\to\infty$ iken sıkıştırma teoremiyle $u\to0$.
  - $\lim_{u\to0}\frac{\tan u}{u}=1$.
  - L'Hôpital ile çok daha uzun sürer.

### Örnek 7: Parçalı Fonksiyonda Süreklilik

$$f(x)=\begin{cases}\dfrac{\sin\left(\sqrt{x^3+1}-3\right)}{x-2}, & x<2\\[2mm] x+1, & x\ge2\end{cases}$$

- $x=2$'de sürekli mi?
- $f(2)=3$.
- Sol limit: $u=\sqrt{x^3+1}-3$. $x\to2$ iken $u\to0$.

$$\lim_{x\to2^-}\frac{\sin u}{u}\cdot\frac{\sqrt{x^3+1}-3}{x-2}$$

- İkinci çarpan için eşlenik:

$$\frac{x^3+1-9}{(x-2)(\sqrt{x^3+1}+3)}=\frac{(x-2)(x^2+2x+4)}{(x-2)(\sqrt{x^3+1}+3)}\to\frac{12}{6}=2$$

- Sol limit 2, $f(2)=3$. Fonksiyon $x=2$'de sürekli değil.

### Ara Değer Teoremi

- **Koşul 1:** $f$, $[a,b]$ kapalı aralığında sürekli (uçlarda tek taraflı süreklilik).
- **Koşul 2:** $L$, $f(a)$ ile $f(b)$ arasında.
- **Sonuç:** $f(c)=L$ olan en az bir $c$ vardır. $y=L$ yatay doğrusu süreklilik sayesinde grafiği keser.
- Fonksiyon sürekli değilse teorem kullanılamaz.
- **Örnek 8:** $x^3+x+1=0$ denkleminin $[-2,1]$'de çözümü var mı?
  - $f(-2)=-8-2+1=-9<0$, $f(1)=3>0$.
  - $f$ polinom, her yerde sürekli.
  - $0$, $-9$ ile $3$ arasında. En az bir $c\in(-2,1)$ için $f(c)=0$.
  - $-2$ yerine $-1$ de seçilebilir: $f(-1)=-1<0$.
- **Örnek 9 (ödev):** $2x^3+x-2=0$, $(-1,1)$: $f(-1)=-5$, $f(1)=1$. Kök var.
- **Örnek 10 (ödev):** $\sqrt{x^4+25x^3+10}=5$, $(0,1)$: $f(x)=\sqrt{x^4+25x^3+10}-5$ fonksiyonu kurulur.
- $x+e^x=0$ gibi örnekler üstel fonksiyon işlendikten sonra yapılacak.

### Ara Değer Teoremi: Test Tipi Sorular

- **Örnek 11:** "$x^2-10=x\sin x$ denkleminin gerçel çözümü vardır" ifadesi doğru mu?
  - $f(x)=x^2-10-x\sin x$. Her yerde sürekli.
  - $f(0)=-10<0$, $f(10)=90-10\sin10>0$.
  - Ara değer teoremine göre doğru.
- **Örnek 12:** $f(x)=1-\frac{x^2}{4}-\cos x$.
  - $f$ çift fonksiyondur: $f(-x)=f(x)$.
  - $f(0)=0$. Yani $r_1=0$ bir kök.
  - $f\left(\frac\pi2\right)=1-\frac{\pi^2}{16}>0$, $f(\pi)=2-\frac{\pi^2}{4}<0$. $\left(\frac\pi2,\pi\right)$'de bir kök $r_2$ var.
  - Çift olduğu için $-r_2$ de kök.
  - En az 3 kök vardır.

### Süreksizlik Türleri

- **Kaldırılabilir süreksizlik:** $\lim_{x\to a}f(x)=L$ var ama $L\ne f(a)$.
  - Yeni fonksiyon tanımlanır: $x\ne a$ için $f(x)$, $x=a$ için $L$.
  - Bu yeni fonksiyon süreklidir. Süreksizlik "kaldırılmış" olur.
- **Sıçrama süreksizliği:** sol limit $L_1$, sağ limit $L_2$, ikisi de sonlu ve farklı.
  - Aradaki sonlu mesafe "sıçranabilir". Adı buradan gelir.
- **Sonsuz süreksizlik:** sağdan veya soldan limit $\pm\infty$.

### Diğer Alıştırmalar

- **Örnek 13:** $\lim_{x\to\pi}\frac{\cos^2x+3\cos x+2}{\cos x+1}$ benzeri bir ifade.
  - Pay çarpanlara ayrılır: $(\cos x+1)(\cos x+2)$.
  - Sadeleşince $\cos x+2\to-1+2=1$.
- **Örnek 14:** Bir parçalı fonksiyonun $x=-1$'de sürekli olması için $a$: $x^2+3x+2$ çarpanlarına ayrılır, $a=1$ bulunur. Hoca bunu basit soru diye hızlı geçiyor.
- **Örnek 15:**

$$\lim_{x\to0}\frac{\sqrt{1+\sin^2x^2}-\cos^3x^2}{x^3\tan x}=2$$

  - Payın içine $-1+1$ eklenir. İki parça ayrı incelenir.
  - $\frac{x}{\tan x}\to1$.
  - Birinci parça eşlenikle: $\frac{\sin^2x^2}{x^4}\cdot\frac{1}{\sqrt{1+\sin^2x^2}+1}\to1\cdot\frac12=\frac12$.
  - İkinci parça $a^3-b^3=(a-b)(a^2+ab+b^2)$ ile ($a=1$, $b=\cos x^2$):

$$\lim_{x\to0}\frac{1-\cos^3x^2}{x^4}=\lim_{x\to0}\frac{2\sin^2\frac{x^2}{2}}{x^4}\left(1+\cos x^2+\cos^2x^2\right)=\frac12\cdot1^2\cdot3=\frac32$$

  - Burada $1-\cos\theta=2\sin^2\frac\theta2$ ve $u=\frac{x^2}{2}\to0$ kullanılır.
  - Toplam: $\left(\frac12+\frac32\right)\cdot1=2$.
- **Örnek 16:** $\lim_{x\to\infty}\left(\sqrt{x^2+1}-\sqrt{x^2-1}\right)$.
  - $\infty-\infty$ belirsizliği. Eşlenikle:

$$\lim_{x\to\infty}\frac{2}{\sqrt{x^2+1}+\sqrt{x^2-1}}=0$$

- **Örnek 17:** $\lim_{x\to0}\frac{\sin ax}{bx}=\frac ab$ ($a,b\ne0$). $a$ ile çarpılıp bölünür, $u=ax$.
- **Örnek 18:** $\lim_{x\to0}\frac{\sin(1-\cos x)}{\sin x}$.
  - $u=1-\cos x\to0$. $\frac{\sin u}{u}\to1$.
  - Kalan $\frac{1-\cos x}{\sin x}=\frac{1-\cos x}{x}\cdot\frac{x}{\sin x}\to0\cdot1=0$.
  - Sonuç 0.
- **Örnek 19:** $\lim_{x\to0^+}\frac{1-\cos\sqrt x}{x}$.
  - Eşlenikle: $\frac{\sin^2\sqrt x}{(\sqrt x)^2}\cdot\frac{1}{1+\cos\sqrt x}\to1\cdot\frac12=\frac12$.
- **Örnek 20:** $\lim_{x\to0}x^2\cos\frac1x$ benzeri bir ifade.
  - $x\to0$ iken $\frac1x\to\infty$. $\cos\frac1x$ salınır, belirsizlik yok.
  - $-x^2\le x^2\cos\frac1x\le x^2$. Sıkıştırma teoremiyle 0.
- **Örnek 21:** $\lim_{x\to-1}\frac{1+x}{1+x\sqrt{2+x}}$.
  - $\frac00$. Eşlenik $1-x\sqrt{2+x}$ ile çarpılır.
  - Payda: $1-x^2(2+x)=1-2x^2-x^3$.
  - Polinom bölmesiyle: $1-2x^2-x^3=(x+1)(-x^2-x+1)$.
  - Sadeleşince $x=-1$ yazılır. Sonuç 2.

### Geçmiş Yıl Sınav Soruları

- Hoca başka bir hocanın herkese açık paylaştığı uygulama dosyasından geçmiş yıl sorularını çözüyor. Dosyalar hocanın Avesis sayfasında da var.
- **Örnek 22:** $x\to\infty$ iken $\infty\cdot0$ belirsizliği veren, $1-\cos\frac2x$ içeren bir limit.
  - $1-\cos$ olduğu için eşlenik: $1-\cos^2\frac2x=\sin^2\frac2x$.
  - $u=\frac2x$. $x\to\infty$ iken $u\to0$. $\frac{\sin u}{u}$ oluşturmak için 4 ile çarpılıp bölünür.
- **Örnek 23:** $x\to\frac\pi2$ iken $\frac00$ belirsizliği olan bir limit.
  - $u=x-\frac\pi2$ dönüşümü ve toplam formülü $\cos(a+b)$.
  - $v=\frac u2$ oluşturmak için 2 ile çarpılıp bölünür.
  - Sonuç $-\frac12$.
- **Örnek 24:** $\lim_{x\to0}\frac{\tan x-\sin x}{x^3}$.
  - $\tan x=\frac{\sin x}{\cos x}$ yazılır, payda eşitlenir.
  - $\frac{\sin x}{x}\cdot\frac{1-\cos x}{x^2}\cdot\frac{1}{\cos x}$ biçimine gelir.
  - $1-\cos x$ eşlenikle $\sin^2x$ yapılır.
  - Sonuç $\frac12$.
- **Örnek 25:**

$$\lim_{x\to0}\frac{\sqrt{2+\sin x}-\sqrt{1+\cos x}}{\tan x}=\frac{1}{2\sqrt2}$$

  - Pay eşlenikle çarpılıp bölünür: pay $1+\sin x-\cos x$ olur.
  - $\tan x=\frac{\sin x}{\cos x}$ yazılır.
  - Gruplama: $\frac{1-\cos x}{\sin x}$ ve $\frac{\sin x}{\sin x}$ parçalarına dağıtılır.
  - $\frac{1-\cos x}{x}\cdot\frac{x}{\sin x}\to0$. İlk parça 0 olur.
  - Kalan: $\frac{\cos x}{\sqrt{2+\sin x}+\sqrt{1+\cos x}}\to\frac{1}{\sqrt2+\sqrt2}=\frac{1}{2\sqrt2}$.

### Ders sonrası notlar

- **Örnek 8'deki $f(-1)$ ifadesi:** Hoca "cevap $-1$, doğrudan kök bu" diyor. Doğrusu: $f(-1)=-1$ bir kök değil, fonksiyonun $-1$'deki değeridir. Negatif olduğu için $[-1,1]$ aralığı da ara değer teoremi için kullanılabilir.
- **Örnek 7:** Hoca yalnız sol limiti hesaplıyor. Sağ limit $\lim_{x\to2^+}(x+1)=3$. Sol limit 2, sağ limit 3 olduğu için $x=2$'de limit yoktur. Bu bir sıçrama süreksizliğidir.
- **Örnek 6:** $\sin x=0$ olduğu noktalarda ifade tanımsızdır. Limit, $\sin x\ne0$ olan $x$ değerleri üzerinden düşünülmelidir.
- **Örnek 1'deki öğrenci sorusu:** Bölüm kuralı payda limiti sıfırken kullanılamaz. Bu yüzden önce düzenleme gerekir.
- Altyazıda bazı yerlerde uzun tekrar döngüsü var (ör. 00:19:20-00:19:47 arası kelime kelime bölünmüş, 01:53:09). Bu yerlerdeki çözüm adımları altyazıda anlaşılmıyor.
- Hoca derste rastgele yoklama alıyor. Ders notları ve geçmiş yıl soruları Avesis sayfasında.
- Sonraki ders: "See you tomorrow".

---

İsterseniz bu özeti Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
