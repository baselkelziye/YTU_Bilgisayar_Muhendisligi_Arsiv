# Ders 24 Çalışma Özeti

Tarih: 16 Mayıs 2023 (Salı). İntegral konusu bir önceki derste bitti. Bu derste parametrik denklemler (parametric equations) tekrar edildi ve final için soru çözüldü. Ekranda hocanın "Matematik 2 ders notu hafta 5" PDF'i kullanıldı.

## Genel Konular

- Parametrik eğri: başlangıç ve bitiş noktası, parametreyi yok ederek kartezyen denkleme geçiş.
- Aynı eğriyi temsil eden farklı parametrizasyonlar.
- Düzlem ile silindirin arakesitini parametrize etme.
- Bir noktadan geçen, eğimi bilinen doğrunun parametrik denklemi.
- Parametrik eğride birinci ve ikinci türev, teğet ve normal doğru.
- Parametrik eğride alan: elips, astroid, $y=x^3$ altındaki alan.
- Parametrik ve kutupsal eğride yay uzunluğu: çember, astroid.

## Hocanın Özellikle Vurguladığı Kısımlar

- Grafik çizimi integral sorularında "olmazsa olmaz". Bölgeleri doğru çizmek doğru sonuca giden en önemli adımlardan biri.
- Parametrik eğride ikinci türev sınavda gelmişti. Öğrencilerin yaklaşık %80'i birinci türevi alıyor ama ikinci türevde zorlanıyor.
- İkinci türevde inceliği: $\dfrac{dy}{dx}$, $t$'ye bağlı bir ifadedir. Doğrudan $x$'e göre türevi alınamaz. Önce $t$'ye göre türev alınır, sonra $\dfrac{dx}{dt}$'ye bölünür.
- Parametrik alan, yay uzunluğu ve iki eğri arası alan finalde gelebilecek soru tipleri.

## Kısa Tekrar Notları

- $x=f(t)$, $y=g(t)$, $a\le t\le b$: başlangıç noktası $(f(a),g(a))$, bitiş noktası $(f(b),g(b))$.
- Birinci türev: $\dfrac{dy}{dx}=\dfrac{dy/dt}{dx/dt}$.
- İkinci türev: $\dfrac{d^2y}{dx^2}=\dfrac{\dfrac{d}{dt}\left(\dfrac{dy}{dx}\right)}{dx/dt}$.
- Teğet: $y-y_0=m(x-x_0)$. Normal: $y-y_0=-\dfrac1m(x-x_0)$.
- Alan: $A=\displaystyle\int y\,dx=\int_{t_1}^{t_2}g(t)\,f'(t)\,dt$. Simetrik eğride bir parçanın alanı bulunup çarpılır.
- Yay uzunluğu:
  - Kartezyen: $L=\displaystyle\int_a^b\sqrt{1+\left(f'(x)\right)^2}\,dx$.
  - Parametrik: $L=\displaystyle\int_{t_1}^{t_2}\sqrt{\left(\frac{dx}{dt}\right)^2+\left(\frac{dy}{dt}\right)^2}\,dt$.
  - Kutupsal: $L=\displaystyle\int_\alpha^\beta\sqrt{r^2+\left(\frac{dr}{d\theta}\right)^2}\,d\theta$.

## Detaylı Açıklamalar

### Örnek 1: Parametreyi yok etme

- $x=t^2$, $y=t+1$: $t=y-1 \Rightarrow x=(y-1)^2$. Yatay eksene açılan parabol.
- $x=\cos t$, $y=\sin t$, $0\le t\le2\pi$: $x^2+y^2=1$, birim çember.
- $x=\sin t$, $y=\cos t$, $-\tfrac\pi2\le t\le\tfrac\pi2$: yine $x^2+y^2=1$. Bu aralıkta $y\ge0$, üst yarım çember. $t=-\tfrac\pi2$'de $(-1,0)$, $t=\tfrac\pi2$'de $(1,0)$.
- Hoca: farklı parametrizasyonlar aynı eğriyi temsil edebilir. Uç noktalara değer koyarak eğrinin nereden başlayıp nerede bittiği görülür.

### Örnek 2: Düzlem ile silindirin arakesiti

- Düzlem $x+2y+4z=4$, silindir $x^2+4y^2=4$ (eliptik silindir).
- $\dfrac{x^2}{4}+y^2=1 \Rightarrow x=2\cos t$, $y=\sin t$, $0\le t\le2\pi$.
- Düzlemden: $z=1-\dfrac14(x+2y)=1-\dfrac14(2\cos t+2\sin t)=1-\dfrac{\cos t+\sin t}{2}$.
- Arakesit eğrisi: $\vec r(t)=\left\langle 2\cos t,\ \sin t,\ 1-\dfrac{\cos t+\sin t}{2}\right\rangle$.

### Örnek 3: Doğrunun parametrik denklemi

- $(a,b)$ noktasından geçen, eğimi $m$ olan doğru: $y-b=m(x-a)$.
- $x-a=t$ denirse: $x=a+t$, $y=b+mt$.

### Örnek 4: Kartezyen denkleme geçiş

- $x=t+\dfrac1t$, $y=t-\dfrac1t$, $t>0$.
- $x+y=2t$, $x-y=\dfrac2t$. Çarpınca: $x^2-y^2=4$.
- $t>0$ olduğu için $x\ge2$: hiperbolün sağ kolu.

### Örnek 5: Teğet ve normal doğru

- $x=\sec t$, $y=\tan t$ eğrisi. $(\sqrt2,1)$ noktasında eğim, teğet ve normal isteniyor.
- $\sec t=\sqrt2 \Rightarrow \cos t=\tfrac{\sqrt2}{2} \Rightarrow t=\tfrac\pi4$. $\tan t=1$ ile de aynı $t$ çıkıyor.
- $\dfrac{dy}{dt}=\sec^2t$, $\dfrac{dx}{dt}=\sec t\tan t$.
- $\dfrac{dy}{dx}=\dfrac{\sec^2t}{\sec t\tan t}=\dfrac{\sec t}{\tan t}=\dfrac{1}{\sin t}$. $t=\tfrac\pi4$'te $m=\sqrt2$.
- Teğet: $y-1=\sqrt2(x-\sqrt2) \Rightarrow y=\sqrt2\,x-1$.
- Normal: $y-1=-\dfrac{1}{\sqrt2}(x-\sqrt2) \Rightarrow y=-\dfrac{x}{\sqrt2}+2$.

### Örnek 6: İkinci türev

- $x=t-t^2$, $y=t-t^3$.
- $\dfrac{dy}{dx}=\dfrac{1-3t^2}{1-2t}$.
- $\dfrac{d}{dt}\left(\dfrac{1-3t^2}{1-2t}\right)=\dfrac{-6t(1-2t)+2(1-3t^2)}{(1-2t)^2}=\dfrac{6t^2-6t+2}{(1-2t)^2}$.
- $\dfrac{d^2y}{dx^2}=\dfrac{6t^2-6t+2}{(1-2t)^3}$.
- Tahtadaki varyasyon: $x=t-t^2$, $y=t^3$.
  - $\dfrac{dy}{dx}=\dfrac{3t^2}{1-2t}$.
  - $\dfrac{d}{dt}\left(\dfrac{3t^2}{1-2t}\right)=\dfrac{6t(1-2t)+6t^2}{(1-2t)^2}=\dfrac{6t-6t^2}{(1-2t)^2}$.
  - $\dfrac{d^2y}{dx^2}=\dfrac{6t-6t^2}{(1-2t)^3}$.
- Belirli bir $t$ değeri verilirse yerine konur.
- Hoca: ivme vektörü de ikinci türev demektir.

### Örnek 7: Elipsin alanı

- $x=a\cos t$, $y=b\sin t$, $0\le t\le2\pi$, yani $\dfrac{x^2}{a^2}+\dfrac{y^2}{b^2}=1$.
- Birinci bölgedeki alan bulunup 4 ile çarpılır. $x:0\to a$ iken $t:\tfrac\pi2\to0$.
- $dx=-a\sin t\,dt$.
- $A=4\displaystyle\int_{\pi/2}^{0}b\sin t\,(-a\sin t)\,dt=4ab\int_0^{\pi/2}\sin^2t\,dt$.
- $\sin^2t=\dfrac{1-\cos2t}{2}$ ile: $A=4ab\cdot\dfrac\pi4=\pi ab$.

### Örnek 8: Astroidin alanı

- $x=\cos^3t$, $y=\sin^3t$, $0\le t\le2\pi$ (astroid).
- $dx=-3\cos^2t\sin t\,dt$.
- $A=4\displaystyle\int_0^1y\,dx=12\int_0^{\pi/2}\sin^4t\cos^2t\,dt$.
- Yarım açı formülleriyle: $A=\dfrac{3\pi}{8}$ birim kare.

### Örnek 9: Çemberin uzunluğu ve alanı

- $x=r\cos t$, $y=r\sin t$, $0\le t\le2\pi$.
- $L=\displaystyle\int_0^{2\pi}\sqrt{r^2\sin^2t+r^2\cos^2t}\,dt=2\pi r$.
- Alan: $A=4\displaystyle\int_0^{\pi/2}r^2\sin^2t\,dt=\pi r^2$.

### Örnek 10: $y=x^3$ altındaki alan (parametrik)

- $x=t^2$, $y=t^6$ ($y=x^3$). $0\le x\le1$ için $0\le t\le1$.
- $dx=2t\,dt$.
- $A=\displaystyle\int_0^1t^6\cdot2t\,dt=\frac14$.

### Örnek 11: Astroidin uzunluğu

- $\dfrac{dx}{dt}=-3\cos^2t\sin t$, $\dfrac{dy}{dt}=3\sin^2t\cos t$.
- Kareler toplamı: $9\cos^2t\sin^2t$.
- $S=4\displaystyle\int_0^{\pi/2}3\sin t\cos t\,dt=12\int_0^{\pi/2}\frac{\sin2t}{2}\,dt=-3(\cos\pi-1)=6$.

### Ders sonrası notlar

- Örnek 1'de hoca $x=\sin t$, $y=\cos t$ için "birim çember" diyor. $-\tfrac\pi2\le t\le\tfrac\pi2$ aralığında yalnız üst yarım çember çizilir.
- Örnek 5'te hoca normal doğruyu "$x-2\sqrt2$" gibi söylüyor. Doğrusu $x-\sqrt2$: $y-1=-\tfrac{1}{\sqrt2}(x-\sqrt2)$.
- Örnek 8'de hoca $dx$'i "$3\cos^2t\sin t$" diye işaretsiz okuyor. Türev $-3\cos^2t\sin t$'dir. Eksi işaret, sınırların ters çevrilmesiyle ($\tfrac\pi2\to0$ yerine $0\to\tfrac\pi2$) götürülür.
- Örnek 11'in sonucunu hoca sesli okumadı. Ekrandaki çözüme göre sonuç 6.
- 00:07:54-00:09:40 arasında hocanın internet bağlantısı koptu. Bu aralık altyazıda yok.
- 00:26:11'de öğrenciler ekranda farklı sayfa göründüğünü haber verdi; ikinci türev sorusu sonradan boş tahtada yeniden çözüldü.
- 00:29:47-00:50:39 arası mola.
- Ders "haftaya" diye bitiyor. Sonraki ders 22 Mayıs Pazartesi.

İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
