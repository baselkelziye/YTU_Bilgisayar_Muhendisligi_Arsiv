# Ders 8 Çalışma Özeti

## Genel Konular

- Bu ders 28 Ekim 2020'de, Cumhuriyet Bayramı arifesi nedeniyle yaklaşık 1 saat yapıldı.
- Yeni konuya geçilmedi. Hoca, diğer grup çok geride kalmasın diye genel uygulama (soru çözümü) yaptı.
- Sorular, bir başka hocanın geçmiş yıllardan derlediği "2. Uygulama" dosyasından alındı.
- Çözülen soru tipleri:
  - $\dfrac{\sin t}{t}$ limitine dönüştürerek limit hesabı.
  - Parçalı fonksiyonda süreklilik için bilinmeyen sabitler.
  - Sonsuzda limit: kök içeren ifadeler ve eşlenik yöntemi (conjugate method).
  - Mutlak değerli fonksiyonda türevlenebilme.
  - Bir doğruya dik teğet doğrusu.
  - $x\sin(1/x)$ fonksiyonunun $0$'da türevlenebilirliği.
  - Yatay teğet doğruları.
  - Kapalı formda teğet ve normal doğrusu.
  - Kapalı formda ikinci türev.

## Hocanın Özellikle Vurguladığı Kısımlar

- Soruyu dikkatle okuyun. Hoca bir soruda kendisi de ilk okumada hata yaptığını söylüyor.
- Kök farkı içeren sonsuz limitlerde önce eşlenik yöntemini uygulayın. L'Hôpital kuralı burada işi zorlaştırır.
- Bütün formülleri ezberlemeye çalışmayın. Temel yöntemleri bilin, diğerleri onların üzerine kurulur. Ezberi en az düzeyde tutun.
- Her fonksiyonun grafiğini çizemezsiniz. Sorunun yapısına odaklanın ve genel yöntemle çözün.
- Yatay teğet doğrusunu yatay asimptotla karıştırmayın.
- Normal doğrusu uygulamada çok önemli. İleride hız ve ivme vektörlerinde, çok değişkenli fonksiyonlarda teğet düzlem ve gradyanda (gradient) kullanılacak.
  - Makine öğrenmesindeki gradyan inişi (gradient descent) algoritması bu fikre dayanır.
- Kapalı formda ikinci türevi bulurken bildiğiniz kısa formül birinci türev için işe yarar. İkinci türevde zorlanırsınız; derste anlatılan yöntemi kullanın.
- Gelecek hafta: ters trigonometrik fonksiyonlar ve türevleri.

## Kısa Tekrar Notları

- $\displaystyle\lim_{t \to 0} \frac{\sin t}{t} = 1$.
- $\sin\left(\dfrac{\pi}{2} - \theta\right) = \cos\theta$, $\cos\left(\dfrac{\pi}{2} - \theta\right) = \sin\theta$.
- Eşlenik yöntemi: $(A - B) \cdot \dfrac{A + B}{A + B} = \dfrac{A^2 - B^2}{A + B}$.
- Sürekli ama türevlenemez örnekleri: $|x^2 - 1|$ ($x = \pm 1$), $x\sin(1/x)$ ($x = 0$).
- Dik iki doğrunun eğimleri çarpımı $-1$'dir: $m_1 \cdot m_2 = -1$.
- Teğet: $y - y_0 = m_T(x - x_0)$. Normal: $y - y_0 = -\dfrac{1}{m_T}(x - x_0)$.
- Yatay teğet: $f'(x) = 0$ olan noktalar.

## Detaylı Açıklamalar

### Örnek 1: $\displaystyle\lim_{x \to 1^-} (1 - x)\tan\left(\frac{\pi}{2}x\right)$

- L'Hôpital kullanmadan, bilinen limite benzeterek çözülür.
- Değişken değiştirme: $u = 1 - x$. $x \to 1$ iken $u \to 0$.
- $\tan\left(\dfrac{\pi}{2}x\right) = \dfrac{\sin\left(\frac{\pi}{2} - \frac{\pi}{2}u\right)}{\cos\left(\frac{\pi}{2} - \frac{\pi}{2}u\right)} = \dfrac{\cos\frac{\pi}{2}u}{\sin\frac{\pi}{2}u}$.
- Limit: $\displaystyle\lim_{u \to 0} \frac{u \cos\frac{\pi}{2}u}{\sin\frac{\pi}{2}u} = \lim_{u \to 0} \frac{\frac{\pi}{2}u}{\sin\frac{\pi}{2}u} \cdot \frac{2}{\pi} \cdot \cos\frac{\pi}{2}u = 1 \cdot \frac{2}{\pi} \cdot 1 = \frac{2}{\pi}$.
- Bir öğrenci $\dfrac{2}{\pi}$'nin nereden geldiğini soruyor.
  - Hoca: $t = \dfrac{\pi}{2}u$ yapısını elde etmek için $\dfrac{\pi}{2}$ ile çarpıp böldük. Bölünen kısım $\dfrac{2}{\pi}$ olarak dışarıda kalıyor.

### Örnek 2: Sürekli olmama ve süreklilik koşulu

- Soru: Hangi $a$ ve $b$ değerleri için $f$, $x = 0$'da süreksiz, $x = 1$'de süreklidir?
- Yöntem:
  - $x = 0$'da süreksizlik için sağdan ve soldan limitler farklı olmalı (ya da limit fonksiyon değerine eşit olmamalı).
  - $x = 1$'de süreklilik için sağdan limit = soldan limit = $f(1)$ olmalı.
- Fonksiyonun kuralı ve çözümün sözlü kısmı altyazıda anlaşılmıyor (döngü). Ekranda sonuç kısmında "$b \ne 0$" ve "$x = 1$'de sürekli olur" notları görülüyor.

### Örnek 3: Ekrandaki uygulama dosyasında çözümü görünen iki soru

- $\displaystyle\lim_{x \to \infty} \frac{2\sqrt{x} + \sqrt[3]{x} + \sqrt[5]{x}}{\sqrt{3x - 2} + \sqrt[3]{2x - 3}}$ ($\frac{\infty}{\infty}$ belirsizliği)
  - Pay ve paydada $\sqrt{x}$ ortak çarpan parantezine alınır.
  - Kalan terimler $0$'a gider. Sonuç: $\dfrac{2}{\sqrt{3}}$.
- Parçalı fonksiyon:
  - $f(x) = \dfrac{x - 1}{1 - \sqrt{2 - x}}$ ($x < 1$), $f(1) = 2a$, $f(x) = \dfrac{\sin(x-1)}{b(2x - 2)}$ ($x > 1$).
  - $x = 1$'de sürekliyse $a$ ve $b$ nedir?
  - Soldan: eşlenikle çarpılır, $\dfrac{(x-1)(1 + \sqrt{2-x})}{x - 1} = 1 + \sqrt{2 - x} \to 2$.
  - Sağdan: $\dfrac{\sin(x-1)}{2b(x-1)} \to \dfrac{1}{2b}$.
  - $2a = 2 \Rightarrow a = 1$. $\dfrac{1}{2b} = 2 \Rightarrow b = \dfrac{1}{4}$.
- Bu iki sorunun sözlü anlatımı altyazıda anlaşılmıyor. Çözüm ekrandaki dosyadan ve yeniden hesapla verildi.

### Örnek 4: $\displaystyle\lim_{x \to \infty} \left(\sqrt{x + \sqrt{x}} - \sqrt{x}\right)$

- $\infty - \infty$ belirsizliği. Eşlenikle çarpıp bölünür:
  - $\dfrac{(x + \sqrt{x}) - x}{\sqrt{x + \sqrt{x}} + \sqrt{x}} = \dfrac{\sqrt{x}}{\sqrt{x}\left(\sqrt{1 + \frac{1}{\sqrt{x}}} + 1\right)}$.
- $x \to \infty$ iken $\dfrac{1}{\sqrt{x}} \to 0$. Sonuç: $\dfrac{1}{2}$.
- Hoca: Bu tür sorularda eşlenik yöntemi zorunlu gibidir. L'Hôpital doğrudan uygulanamaz. Eşlenikten sonra uygulanabilir ama daha zordur.
- Bir öğrenci $x \to -\infty$ durumunu soruyor.
  - Hoca: Önce tanım kümesine bakın. $\sqrt{x}$ olduğu için $x \ge 0$ olmalı. Bu yüzden $x \to -\infty$ anlamsızdır.

### Örnek 5: $f(x) = |x^2 - 1|$ türevlenebilir mi?

- $x^2 - 1 \ge 0$ (yani $x \le -1$ ya da $x \ge 1$) için $f(x) = x^2 - 1$.
- $-1 < x < 1$ için $f(x) = 1 - x^2$.
- Grafik: $y = x^2 - 1$ parabolünün $x$ ekseninin altındaki kısmı yukarı katlanır. $x = \pm 1$'de kırılma olur.
- $x = 1$'de:
  - Sağdan türev: $\displaystyle\lim_{x \to 1^+} \frac{x^2 - 1 - 0}{x - 1} = 2$.
  - Soldan türev: $\displaystyle\lim_{x \to 1^-} \frac{1 - x^2 - 0}{x - 1} = -2$.
  - Farklı oldukları için $f'(1)$ yok. $x = -1$ için de benzer.
- Sonuç: $f$ her yerde süreklidir, $\mathbb{R} \setminus \{-1, 1\}$'de türevlenebilirdir.
- Katlama sürekliliği korur, ama tek bir teğet çizilmesini engeller.
- Ekrandaki sorunun bir şıkkı (bir aralıkta türevlenebilirlik) daha karmaşık bir fikir gerektirdiği için hoca onu atladı.

### Örnek 6: Bir doğruya dik teğet doğrusu

- Soru: $y = x^2 - 2x$ eğrisinin, $x + 2y = 1$ doğrusuna dik olan teğetinin denklemi.
- Verilen doğru: $y = -\dfrac{1}{2}x + \dfrac{1}{2}$. Eğimi $-\dfrac{1}{2}$.
- Dik doğrunun eğimi: $m = 2$ (çünkü $m \cdot (-\frac{1}{2}) = -1$).
- Teğetin eğimi türev değeridir: $f'(x_0) = 2x_0 - 2 = 2 \Rightarrow x_0 = 2$.
- $y_0 = 4 - 4 = 0$.
- Teğet: $y - 0 = 2(x - 2)$, yani $y = 2x - 4$.
- Bir öğrenci grafiği çizerek çözüp çözemeyeceğini soruyor.
  - Hoca: Her fonksiyonun grafiğini çizemezsin. Karmaşık bir fonksiyon verilirse çizemezsin. Genel yönteme odaklan.

### Örnek 7: $f(x) = x\sin\left(\dfrac{1}{x}\right)$ ($x \ne 0$), $f(0) = 0$

- Süreklilik: $\displaystyle\lim_{x \to 0} x\sin\frac{1}{x} = 0 = f(0)$ ($\sin$ sınırlı, $x \to 0$). Sürekli.
- Türev: Parçalı fonksiyon olduğu için tanım zorunlu.
  - $f'(0) = \displaystyle\lim_{h \to 0} \frac{h\sin(1/h) - 0}{h} = \lim_{h \to 0} \sin\frac{1}{h}$.
  - Bu limit yoktur. $f$, $x = 0$'da türevlenemez.

### Örnek 8: Yatay teğetler

- Soru: $y = x^3 - 3x$ grafiğinin hangi $x$ değerlerinde teğeti yataydır?
- $f'(x) = 3x^2 - 3 = 0 \Rightarrow x = 1$ ya da $x = -1$.
- Bu noktalarda teğet yataydır. Bunlar yatay asimptot değildir.

### Örnek 9: Kapalı formda teğet ve normal doğrusu

- Soru: $\cos(3x + y) + \sin(x + 3y) = -1$ eğrisinin $A\left(0, \dfrac{\pi}{2}\right)$ noktasındaki teğet ve normal doğruları.
- Nokta eğri üzerinde: $\cos\frac{\pi}{2} + \sin\frac{3\pi}{2} = 0 - 1 = -1$.
- İki tarafın $x$'e göre türevi:
  - $-\sin(3x + y)(3 + y') + \cos(x + 3y)(1 + 3y') = 0$.
- $A$'da: $\sin\frac{\pi}{2} = 1$, $\cos\frac{3\pi}{2} = 0$.
  - $-(3 + m_T) = 0 \Rightarrow m_T = -3$.
- Teğet: $y - \dfrac{\pi}{2} = -3(x - 0)$.
- Normal: $m_N = \dfrac{1}{3}$, $y - \dfrac{\pi}{2} = \dfrac{1}{3}(x - 0)$.
- Bir öğrenci $m_T$'nin nereden geldiğini soruyor. Hoca: $y'$, birinci türevdir. $A$ noktasını yerine koyunca $y'$ teğetin eğimi olur.
- Bir öğrenci neden normal doğrusunu da bulduğumuzu soruyor. Hoca: Soru normal doğrusunu da istiyor. Normal ve teğet aynı noktadan geçer, yalnız eğimleri farklıdır.

### Örnek 10: Kapalı formda ikinci türev

- Soru: $y^3 - x^3 = xy$ ise $y''$'yü $x$ ve $y$ cinsinden yazın.
- Birinci türev: $3y^2 y' - 3x^2 - y - x y' = 0 \Rightarrow y' = \dfrac{3x^2 + y}{3y^2 - x}$.
- İkinci türev (bölüm kuralı, $y$'nin $x$'e bağlı olduğunu unutmadan):
  - $y'' = \dfrac{(6x + y')(3y^2 - x) - (3x^2 + y)(6y\,y' - 1)}{(3y^2 - x)^2}$.
  - Sonra $y' = \dfrac{3x^2 + y}{3y^2 - x}$ yerine yazılır.
- Diğer yol: $3y^2 y' - 3x^2 - y - x y' = 0$ denkleminin iki tarafını yeniden türevleyip $y''$'yü yalnız bırakmak. Aynı sonuca gelir.
- Bir öğrenci "$x$ ve $y$ cinsinden" ifadesinin özel bir anlamı olup olmadığını soruyor.
  - Hoca: Hayır. Denklem kapalı formda verildiği için sonuç zaten $x$ ve $y$ cinsinden çıkar.

### Ders sonrası notlar

- Hoca soruların kaynağını "... Hoca'nın geçmiş yıllardan derlediği sorular" diye söylüyor. Ad altyazıda net anlaşılmıyor. Ekrandaki dosya başlığında "2. Uygulama" yazıyor.
- Örnek 2'nin fonksiyonu ve çözümü altyazıda anlaşılmıyor. Ekranda yalnız sonuç notları görüldü.
- Bir öğrenci bir soruyu $\ln$ ile çözmeyi öneriyor. Hoca: Bu, $\ln$ ile çözülecek bir soru değil, işi zorlaştırırsın. $\ln$ ile çözülecek soruları ayrıca getireceğim.
- Bazı bölümlerin sözlü anlatımı (ör. 00:12:40–00:13:10, 00:16:15–00:16:45, 00:59:04) altyazıda döngüye girmiş. Bu kısımlar altyazıda anlaşılmıyor.
- Hoca derste yoklama ya da sınav tarihi duyurmadı. Sınav öncesi genel alıştırmalar yapılacağını tekrarladı.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
