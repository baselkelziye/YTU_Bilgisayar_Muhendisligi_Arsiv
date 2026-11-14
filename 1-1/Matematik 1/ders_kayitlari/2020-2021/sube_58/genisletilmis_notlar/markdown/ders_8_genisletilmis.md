# Ders 8 Genişletilmiş Notu: Genel Uygulama: Limit, Süreklilik, Teğet ve Normal Doğruları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Kaynağı
- 2. Örnek 1: $\sin t / t$ Limitine Dönüştürme
- 3. Örnek 2: Bir Noktada Süreksiz, Başka Noktada Sürekli Fonksiyon
- 4. Kısa Notta Ekrandan Aktarılan İki Soru
- 5. Örnek 3: Sonsuzda Limit ve Eşlenik Yöntemi
- 6. Formül Ezberi Üzerine
- 7. Örnek 4: Mutlak Değerli Fonksiyonun Türevlenebilmesi
- 8. Örnek 5: Bir Doğruya Dik Teğet Doğrusu
- 9. Örnek 6: $x\sin(1/x)$ Fonksiyonunun $0$'da Türevi
- 10. Örnek 7: Yatay Teğet Doğruları
- 11. Örnek 8: Kapalı Formda Teğet ve Normal Doğrusu
- 12. Normal Doğrusu Neden Önemli?
- 13. Örnek 9: Kapalı Formda İkinci Türev
- 14. Örnek Sorular

## 1. Dersin Amacı ve Kaynağı

Bu derste yeni bir konuya geçilmedi. Hoca, öbür grubun çok geride kalmaması için konularda ilerlemek yerine genel bir uygulama (soru çözümü) yaptı. Sorular, hocanın sözüne göre bir başka hocanın geçmiş yıllardan derlediği sorulardan alındı. Hoca soruları ekrandaki uygulama dosyasından okudu, çözümleri tablete yazdı. Bu yüzden altyazıda soruların metni çoğu yerde yalnız sözlü okumadan çıkıyor.

Ders yaklaşık bir saat sürdü. Hoca dersin sonunda kısa tutmasının asıl nedeninin yine öbür grupla arada büyük bir fark oluşmasını istememesi olduğunu söyledi.

<!-- BELİRSİZ: Soruların alındığı dosyayı derleyen hocanın adı altyazıda "Kınar Hoca" diye geçiyor (00:03:13); adın doğru yazımı doğrulanamadı. -->

## 2. Örnek 1: $\sin t / t$ Limitine Dönüştürme

**Soru (00:03:28):**

$$\lim_{x \to 1^-} (1 - x)\tan\left(\frac{\pi}{2}x\right)$$

<!-- BELİRSİZ: Hoca soruyu "1 minus x times pi over 2x" diye okuyor; "tan" sözcüğü altyazıda yok. Sonraki çözümde sin/cos oranı kullanıldığı için fonksiyonun $\tan$ olduğu anlaşılıyor (kısa notla da uyumlu). -->

Hoca bu tür soruların L'Hôpital kuralı kullanılmadan çözülebileceğini söyledi. Fikir, soruyu iyi bilinen bir formüle benzetmektir:

$$\lim_{t \to 0} \frac{\sin t}{t} = 1.$$

**Çözüm:**

- **Değişken değiştirme:** $u = 1 - x$ olsun. Böylece $x = 1 - u$ olur. $x \to 1^-$ iken $u \to 0^+$.
- **Fark formülleri:** Hoca iki formülü hatırlattı:
  - $\sin(a - b) = \sin a\cos b - \cos a \sin b$,
  - $\cos(a - b) = \cos a\cos b + \sin a \sin b$.
- Bunlarla $\dfrac{\pi}{2}x = \dfrac{\pi}{2} - \dfrac{\pi}{2}u$ yazılır ve (ara adım eklendi)
  $$\tan\left(\frac{\pi}{2}x\right) = \frac{\sin\left(\frac{\pi}{2} - \frac{\pi}{2}u\right)}{\cos\left(\frac{\pi}{2} - \frac{\pi}{2}u\right)} = \frac{\cos\frac{\pi}{2}u}{\sin\frac{\pi}{2}u}.$$
- Yeni problem $u$ cinsinden:
  $$\lim_{u \to 0} \frac{u\cos\frac{\pi}{2}u}{\sin\frac{\pi}{2}u}.$$
- $u \to 0$ iken $\cos\frac{\pi}{2}u \to \cos 0 = 1$.
- Kalan kısmı $\dfrac{t}{\sin t}$ yapısına getirmek için $t = \dfrac{\pi}{2}u$ almak gerekir. Hoca bunun için ifadeyi $\dfrac{\pi}{2}$ ile çarpıp böldü. "Hiçbir şey değişmedi" dedi:
  $$\lim_{u \to 0} \frac{\frac{\pi}{2}u}{\sin\frac{\pi}{2}u} \cdot \frac{2}{\pi} \cdot \cos\frac{\pi}{2}u = 1 \cdot \frac{2}{\pi} \cdot 1 = \frac{2}{\pi}.$$

**Sonuç:** $\dfrac{2}{\pi}$. (sympy ile doğrulandı.)

**Soru:** $\dfrac{2}{\pi}$ nereden geldi? **Cevap:** Hoca yeni bir sayfa açıp aynı ifadeyi farklı renkle yeniden yazdı. $\dfrac{\pi}{2}u$ yapısını elde etmek için paya $\dfrac{\pi}{2}$ eklendi. İfade değişmesin diye dışarıda $\dfrac{2}{\pi}$ ile çarpıldı. $\dfrac{\pi}{2}$ ile $\dfrac{2}{\pi}$ sadeleşince $1$ kalır. Kırmızı kutu içindeki $\dfrac{t}{\sin t}$ kısmı $1$'e gider, geriye $\dfrac{2}{\pi}$ kalır.

## 3. Örnek 2: Bir Noktada Süreksiz, Başka Noktada Sürekli Fonksiyon

**Soru (00:07:48):** Hangi $a$ ve $b$ değerleri için $f$ fonksiyonu $x_0 = 0$ noktasında süreksiz (discontinuous), $x_1 = 1$ noktasında süreklidir (continuous)?

Hoca önce soruyu yanlış okuduğunu fark etti ve Türkçe metne bakarak düzeltti. Öğrencilere uyarısı şuydu:

> **Hocanın vurgusu:** Önce soruyu dikkatle okuyun. Yoksa benim gibi hata yapabilirsiniz.

Soruda iki koşul vardır: $x = 0$'da süreksizlik ve $x = 1$'de süreklilik.

<!-- BELİRSİZ: Parçalı fonksiyonun kuralları ekrandaki dosyada; altyazıda okunmuyor. Çözümün sözlü kısmı 00:12:40–00:13:10 ve 00:16:15–00:16:45 arasında döngüye girmiş, bu kısım altyazıda anlaşılmıyor. Kısa nota göre ekranda sonuç kısmında "$b \ne 0$" ve "$x = 1$'de sürekli olur" notları görülüyor. -->

**Birinci koşul: $x = 0$'da süreksizlik.** Hoca, $a$ ve $b$'nin bu koşulu doğru yapacak şekilde seçilmesi gerektiğini söyledi. $x \to 0^+$ için fonksiyonun sağdaki kuralı, $x \to 0^-$ için soldaki kuralı kullanılır. Bu iki değer birbirinden farklı olmalıdır. Böylece limit yoktur ve $f$, $0$'da süreksiz olur.

**İkinci koşul: $x = 1$'de süreklilik.** Hoca süreklilik tanımını hatırlattı: Sağdan limit ile soldan limit eşit olmalı ve bu limit değeri $f(1)$'e eşit olmalıdır:

$$\lim_{x \to 1^+} f(x) = \lim_{x \to 1^-} f(x) = f(1).$$

Sağdan limit için sağdaki kural, soldan limit için soldaki kural kullanılır. Hesabın kendisi altyazıda anlaşılmıyor.

**Soru:** Bir öğrenci soruyu $\ln$ ile çözmeyi önerdi. **Cevap:** Hoca, $\ln$ ile de çözülebileceğini ama işi zorlaştıracağını söyledi. Bu soru $\ln$ ile çözülecek bir soru değil. $\ln$ ile çözülecek soruları ayrıca getireceğini ekledi.

> **Ders sonrası not:** Hoca 00:09:22'de koşulları sayarken ikinci koşulu "continuity at the point $x_0$" diye söyledi; doğrusu "$x_1 = 1$ noktasında süreklilik"tir. Hemen öncesinde ve sonrasında doğru söylüyor.

## 4. Kısa Notta Ekrandan Aktarılan İki Soru

Bu iki sorunun sözlü anlatımı altyazıda anlaşılmıyor (00:12:40–00:17:15 arası döngü). Soru metinleri ve çözümleri aynı dersin kısa notunda ekrandaki uygulama dosyasından aktarılmıştır. Burada o metin esas alındı ve sonuçlar sympy ile yeniden hesaplandı.

<!-- BELİRSİZ: Aşağıdaki iki sorunun metni altyazıdan doğrulanamadı; kısa nottaki ekran okumasına dayanıyor. Derste bu soruların hangi sırayla ve ne kadar çözüldüğü belli değil. -->

### 4.1 Kökler İçeren $\infty/\infty$ Limiti

$$\lim_{x \to \infty} \frac{2\sqrt{x} + \sqrt[3]{x} + \sqrt[5]{x}}{\sqrt{3x - 2} + \sqrt[3]{2x - 3}}$$

- Bu bir $\dfrac{\infty}{\infty}$ belirsizliğidir.
- Pay ve paydada en hızlı büyüyen terim $\sqrt{x}$'tir. Pay ve payda $\sqrt{x}$ parantezine alınır:
  $$\frac{\sqrt{x}\left(2 + x^{-1/6} + x^{-3/10}\right)}{\sqrt{x}\left(\sqrt{3 - \frac{2}{x}} + \frac{\sqrt[3]{2x-3}}{\sqrt{x}}\right)}.$$
  (ara adım eklendi)
- $x \to \infty$ iken parantez içindeki kalan terimler $0$'a gider.
- Sonuç: $\dfrac{2}{\sqrt{3}} = \dfrac{2\sqrt{3}}{3}$. (sympy ile doğrulandı.)

### 4.2 Parçalı Fonksiyonda $x = 1$'de Süreklilik

$$f(x) = \begin{cases} \dfrac{x - 1}{1 - \sqrt{2 - x}}, & x < 1 \\[2mm] 2a, & x = 1 \\[2mm] \dfrac{\sin(x - 1)}{b(2x - 2)}, & x > 1 \end{cases}$$

$f$, $x = 1$'de sürekli ise $a$ ve $b$ nedir?

- **Soldan limit:** Payda eşleniği $1 + \sqrt{2 - x}$ ile çarpılıp bölünür. Payda $1 - (2 - x) = x - 1$ olur:
  $$\frac{(x-1)\left(1 + \sqrt{2-x}\right)}{x - 1} = 1 + \sqrt{2 - x} \to 2.$$
- **Sağdan limit:** $2x - 2 = 2(x - 1)$ olduğundan
  $$\frac{\sin(x-1)}{2b(x-1)} \to \frac{1}{2b}.$$
- **Süreklilik:** $2a = 2 \Rightarrow a = 1$. $\dfrac{1}{2b} = 2 \Rightarrow b = \dfrac{1}{4}$.

İki tek taraflı limit sympy ile doğrulandı ($2$ ve $\dfrac{1}{2b}$).

## 5. Örnek 3: Sonsuzda Limit ve Eşlenik Yöntemi

**Soru:**

$$\lim_{x \to \infty} \left(\sqrt{x + \sqrt{x}} - \sqrt{x}\right)$$

<!-- BELİRSİZ: Soru metni altyazıda okunmuyor; ifade kısa nottan ve hocanın 00:19:15–00:20:33 arasındaki anlatımından (eşlenik, $\sqrt{x}$ ortak çarpanı, $x + \sqrt{x}$ kök içi) kuruldu. -->

Hoca bu tip sorularda eşlenik yönteminin (conjugate method) uygulanması gerektiğini söyledi:

> **Hocanın vurgusu:** Böyle sorularda L'Hôpital'i zaten doğrudan uygulayamazsınız. İşinizi kolaylaştırmak için eşlenikle çarpıp bölme yöntemini uygulamak zorunludur. L'Hôpital uygulamak isteseniz bile önce eşlenik yöntemini uygulayın.

Hoca öğrencilerin kendilerinin çözmesini istedi. Birkaç öğrenci sonucu $\dfrac{1}{2}$ buldu.

**Çözüm:**

- $A = \sqrt{x + \sqrt{x}}$, $B = \sqrt{x}$ olsun. İfade $A - B$ biçimindedir ve $\infty - \infty$ belirsizliği vardır.
- $A + B$ ile çarpılıp bölünür: $(A - B)\dfrac{A + B}{A + B} = \dfrac{A^2 - B^2}{A + B}$.
- $A^2 - B^2 = (x + \sqrt{x}) - x = \sqrt{x}$. Böylece
  $$\frac{\sqrt{x}}{\sqrt{x + \sqrt{x}} + \sqrt{x}}.$$
- Paydada $\sqrt{x}$ ortak çarpan parantezine alınır ve sadeleşir:
  $$\frac{\sqrt{x}}{\sqrt{x}\left(\sqrt{1 + \frac{1}{\sqrt{x}}} + 1\right)} = \frac{1}{\sqrt{1 + \frac{1}{\sqrt{x}}} + 1}.$$
- $x \to \infty$ iken $\dfrac{1}{\sqrt{x}} \to 0$. Sonuç: $\dfrac{1}{1 + 1} = \dfrac{1}{2}$. (sympy ile doğrulandı.)

Hoca, eşlenikle çarptıktan sonraki adımdan itibaren L'Hôpital'in uygulanabileceğini, ama bu yöntemle karşılaştırınca daha zor olduğunu söyledi.

**Soru:** $x \to -\infty$ için de aynı şekilde $\infty - \infty$ belirsizliği olur mu? **Cevap:** Hoca önce fonksiyonun tanım kümesine bakmak gerektiğini söyledi. Karekök içindeki ifadeler negatif olamaz. $x + \sqrt{x}$ ve $\sqrt{x}$ var; $\sqrt{x}$'in tanımlı olması için $x \ge 0$ olmalıdır. Bu yüzden $x \to -\infty$ yazılamaz, anlamsızdır.

## 6. Formül Ezberi Üzerine

Öğrencinin sorusunun devamında hoca, bir formül ve onun genel temel yönteme dayandığı hakkında konuştu (bu kısmın bir bölümü altyazıda anlaşılmıyor, 00:21:00–00:21:58). Ardından genel bir uyarı yaptı:

> **Hocanın vurgusu:** Bütün formülleri ezberlemeye uğraşırsanız olmaz. Size 50 tane formül sunabilirim, ama temel yöntemleri bilin yeter. Diğerleri bunların üzerine kuruluyor. Amacımız formül ezberletmek değil, temel olanları öğretmek. L'Hôpital'i ve mantığını da öğreteceğiz. Formül ezberini olabildiğince en az düzeyde tutmaya çalışıyoruz.

Hoca bunu eşlenik yöntemiyle örnekledi: Eşlenikle çarpıp bölmemizin nedeni belirsizlikten kurtulmaktır. Özdeş ifadeler elde ederiz. Yaptığımız işin bir anlamı vardır ve hangi amaçla yaptığımızı biliriz.

## 7. Örnek 4: Mutlak Değerli Fonksiyonun Türevlenebilmesi

Ekrandaki sorunun bir şıkkı, bir fonksiyonun belli bir aralıkta türevlenebilir olup olmadığını soruyordu. Hoca bunun daha karmaşık bir fikir gerektirdiğini, öğrencilerin böyle sorularla karşılaşmayacağını söyleyip bu şıkkı atladı. Bu şıkta $x^2 + x$ ifadesinin her yerde türevlenebilir olduğunu belirtti.

<!-- BELİRSİZ: Atlanan şıkkın tam fonksiyonu ve aralığı altyazıda okunmuyor. -->

**Soru (00:24:08):** $f(x) = |x^2 - 1|$ fonksiyonu $x = 1$ noktasında türevlenebilir mi?

Hoca bu konuyu daha önce anlattığını söyledi ve yeni bir sayfada çözdü.

**Fonksiyonu parçalı yazmak:**

- $x^2 - 1 \ge 0$ iken $f(x) = x^2 - 1$. Bu eşitsizliğin çözümü $x \le -1$ ya da $x \ge 1$'dir.
- $x^2 - 1 < 0$ iken $f(x) = 1 - x^2$. Bu eşitsizliğin çözümü $-1 < x < 1$'dir. Hoca burada eşitlik olmadığına dikkat çekti.

**Grafik:** Önce $y = x^2 - 1$ parabolü çizilir. Mutlak değer uygulamak, eğrinin $x$ ekseninin altında kalan kısımlarını yukarı katlamak (simetriğini almak) demektir. Ortaya çıkan grafikte $x = -1$ ve $x = 1$'de bir kırılma noktası olduğu açıkça görülür.

**Sonuç:** $f$ her yerde süreklidir. Ama $f$, yalnız $\mathbb{R} \setminus \{-1, 1\}$ kümesinde türevlenebilirdir.

**$x = 1$'de türevin kontrolü** ($f(1) = 0$):

- Sağdan: $x \to 1^+$ iken $x^2 - 1$ kuralı kullanılır:
  $$\lim_{x \to 1^+} \frac{(x^2 - 1) - 0}{x - 1} = \lim_{x \to 1^+} (x + 1) = 2.$$
- Soldan: $x \to 1^-$ iken $1 - x^2$ kuralı kullanılır:
  $$\lim_{x \to 1^-} \frac{(1 - x^2) - 0}{x - 1} = \lim_{x \to 1^-} -(x + 1) = -2.$$
- Sonuçlar farklı olduğu için $f'(1)$ yoktur.

Hoca benzer şekilde $f$'nin $x = -1$'de de türevlenemediğinin gösterilebileceğini söyledi: $(-1, 0)$ noktasından geçen sonsuz çok doğru vardır. (sympy ile $x = -1$'de soldan türev $-2$, sağdan türev $2$ bulundu.)

> **Hocanın vurgusu:** Orada bir kırılma var, çünkü $x$ ekseninin altında kalan kısmı bükerek yukarıya simetrisini aldınız. Bükme sırasında süreklilik korunuyor. Ama türevlenebilme, yani tek bir teğet çizilebilmesi, orada mümkün olmuyor. Teğetin eğimi de sonlu bir değer olmalıdır.

Hoca bunların basit sorular olduğunu, daha önce anlattığını söyleyip geçti.

## 8. Örnek 5: Bir Doğruya Dik Teğet Doğrusu

**Soru (00:29:30):** $y = x^2 - 2x$ eğrisinin, $x + 2y = 1$ doğrusuna dik (perpendicular) olan teğet doğrusunun denklemi nedir?

**Soru:** Bu tür sorular verilen fonksiyonun grafiğini çizerek çözülemez mi? **Cevap:** Hoca her fonksiyonun grafiğini çizemeyeceğimizi söyledi: "Sana öyle bir fonksiyon yazarım ki karman çorman olur, grafiğini nasıl çizeceksin?" Fonksiyonun yapısını değiştirince soru çok yabancı görünebilir. Grafiği çizip cevabı görebileceğiniz sorular olabilir, ama bu her zaman mümkün değildir.

> **Hocanın vurgusu:** Sorunun yapısına odaklanın, en genel yöntemle çözmeye çalışın.

**Çözüm:** Hoca kaba bir grafik çizdi ve bunun yalnız fikri göstermek için olduğunu, grafiği çizmenin gerekmediğini söyledi. Aranan, eğriye teğet ve verilen doğruya dik bir doğrudur.

- Verilen doğru: $x + 2y = 1 \Rightarrow y = -\dfrac{1}{2}x + \dfrac{1}{2}$. Eğimi $-\dfrac{1}{2}$.
- Aranan doğru buna dik olduğu için eğimi $2$'dir. Denklemi $y = 2x + n$ biçimindedir; $n$ bulunacaktır.
- Teğetin eğimi, fonksiyonun uygun bir $x_0$ noktasındaki türev değeridir:
  $$f'(x_0) = 2x_0 - 2 = 2 \Rightarrow x_0 = 2.$$
- $y_0 = x_0^2 - 2x_0 = 4 - 4 = 0$.
- Teğet doğrusu denklemi $y - y_0 = m(x - x_0)$:
  $$y - 0 = 2(x - 2) \Rightarrow y = 2x - 4.$$

(sympy ile doğrulandı: $x_0 = 2$, $y_0 = 0$.)

**Soru:** $y = 2x + n$'deki $2$ nereden geldi? **Cevap:** İki doğru birbirine dikse eğimlerinin çarpımı $-1$'dir. Hoca bunu yazdı: $d_1 \perp d_2$ ise

$$m_1 \cdot m_2 = -1.$$

Burada $m \cdot \left(-\dfrac{1}{2}\right) = -1 \Rightarrow m = 2$.

## 9. Örnek 6: $x\sin(1/x)$ Fonksiyonunun $0$'da Türevi

**Soru (00:37:10):** Aşağıdaki fonksiyonun $x = 0$ noktasında türevlenebilirliğini inceleyin:

$$f(x) = \begin{cases} x\sin\dfrac{1}{x}, & x \ne 0 \\[2mm] 0, & x = 0 \end{cases}$$

<!-- BELİRSİZ: Fonksiyonun parçalı yazımı altyazıda tam okunmuyor; hoca "x times sin 1 over x" ve "f of 0" diyor. $f(0) = 0$ kısa nottan alındı. -->

Hoca bu soruyu daha önce gördüklerini söyledi. Böyle durumlarda türevin tanımını kullanmak zorunludur.

$$f'(0) = \lim_{x \to 0} \frac{f(x) - f(0)}{x - 0}.$$

Soldan da sağdan da aynı kural ($x\sin\frac{1}{x}$) kullanılır:

$$\lim_{x \to 0} \frac{x\sin\frac{1}{x} - 0}{x} = \lim_{x \to 0} \sin\frac{1}{x}.$$

Bu limit yoktur. Bu yüzden fonksiyon $x = 0$'da türevlenemez.

> **Ek bilgi (derste anlatılmadı):** $x \to 0$ iken $\frac{1}{x}$ sonsuza gider ve $\sin\frac{1}{x}$ $-1$ ile $1$ arasında durmadan salınır; bu yüzden limit yoktur. Buna karşın $\left|x\sin\frac{1}{x}\right| \le |x|$ olduğundan $\lim_{x \to 0} x\sin\frac{1}{x} = 0 = f(0)$ olur ve fonksiyon $0$'da süreklidir. Yani bu fonksiyon da sürekli ama türevlenemeyen bir örnektir.

sympy de $\lim_{x \to 0} x\sin\frac{1}{x} = 0$ ve $\sin\frac{1}{h}$ için yalnız $[-1, 1]$ aralığını (limit yok) verdi.

## 10. Örnek 7: Yatay Teğet Doğruları

**Soru (00:38:24):** $y = x^3 - 3x$ grafiğinin teğet doğruları hangi $x$ değerlerinde yataydır (horizontal)?

> **Hocanın vurgusu:** Teğet doğrular yatay olacak. Yatay asimptotla karıştırmayın.

**Çözüm:** Hoca grafiği bilmediğimizi varsayıp kaba bir eğri çizdi. Birden fazla nokta olabilir: $x_1$, $x_2$, $x_3$ gibi. Yatay teğetin eğimi $0$'dır. O yüzden türev fonksiyonunun kökleri aranır:

- $f(x) = x^3 - 3x \Rightarrow f'(x) = 3x^2 - 3$.
- $3x^2 - 3 = 0 \Rightarrow x_1 = 1$, $x_2 = -1$.

Bu koşulu sağlayan iki farklı değer vardır. Bu noktalarda grafiğin yatay teğet doğruları vardır, yatay asimptotları değil. (sympy ile doğrulandı.)

## 11. Örnek 8: Kapalı Formda Teğet ve Normal Doğrusu

**Soru (00:41:32):** Kapalı (implicit) formda verilen

$$\cos(3x + y) + \sin(x + 3y) = -1$$

eğrisinin $A\left(0, \dfrac{\pi}{2}\right)$ noktasındaki teğet (tangent) ve normal doğrularının denklemlerini bulun.

Hoca, böyle kapalı denklemlerin düzlemde bir eğri gösterdiğini hatırlattı. $A$ noktasının apsisi $0$, ordinatı $\dfrac{\pi}{2}$'dir.

**Teğetin eğimi:** Birinci türevin $A$ noktasındaki değeri teğet doğrusunun eğimini ($m_T$) verir. Bunun için eşitliğin iki tarafının $x$'e göre türevi alınır ($y$, $x$'e bağlıdır):

$$-\sin(3x + y)\,(3 + y') + \cos(x + 3y)\,(1 + 3y') = 0.$$

Sağ taraf sabit olduğu için türevi $0$'dır. Şimdi $A$ noktası yerine konur ($x = 0$, $y = \dfrac{\pi}{2}$, $y' = m_T$):

- $\sin\left(0 + \dfrac{\pi}{2}\right) = 1$,
- $\cos\left(0 + \dfrac{3\pi}{2}\right) = 0$.

Böylece $-(3 + m_T) = 0$, yani $-3 - m_T = 0$ ve

$$m_T = -3.$$

**Teğet doğrusu:**

$$y - \frac{\pi}{2} = -3(x - 0).$$

**Normal doğrusu:** Normal doğrusu teğete diktir. Eğimi $m_N = -\dfrac{1}{m_T} = \dfrac{1}{3}$. Hoca önce "eksi $\frac{1}{3}$" deyip hemen "artı $\frac{1}{3}$" diye düzeltti:

$$y - \frac{\pi}{2} = \frac{1}{3}(x - 0).$$

(sympy ile doğrulandı: $A$ eğri üzerindedir, çünkü $\cos\frac{\pi}{2} + \sin\frac{3\pi}{2} = 0 - 1 = -1$; ve $A$'da $y' = -3$.)

**Soru:** "$3 + y'$" yerine $m_T$ mi yazıldı, o kısım anlaşılmadı. **Cevap:** Birinci mertebeden türev fonksiyonunda $A$ noktası yerine konur: $x$ gördüğünüz yere $0$, $y$ gördüğünüz yere $\dfrac{\pi}{2}$. Bu, teğet doğrusunun eğimini verir. Oradaki $y'$, birinci türevdir; onun yerine $m_T$ gelir. Öğrenci $y'$'yi $y$ olarak gördüğünü söyledi.

## 12. Normal Doğrusu Neden Önemli?

**Soru:** Neden normal doğrusunun denklemine de ihtiyacımız var? Soru yalnız teğet doğrusunu soruyor gibiydi. **Cevap:** Hoca, sorunun normal doğrusunu da istediğini söyledi. Sonra normal doğrusunun neden önemli olduğunu anlattı.

Hoca bir grafik çizdi: Teğet doğrusu ve normal doğrusu aynı noktadan geçer. Aralarındaki tek fark eğimleridir. Teğetin eğimi $m_T$ ise normalin eğimi

$$m_N = -\frac{1}{m_T}$$

olur, çünkü birbirlerine diktirler (ortogonal).

> **Hocanın vurgusu:** Uygulama açısından normal ve teğet doğrusu çok önemlidir. İleride hız vektörü ve ivme vektörünü göreceksiniz ve bu fikirleri kullanacaksınız. Şimdi normal doğrusunun denklemini nasıl bulacağınıza odaklanın.

Hoca ileriye dönük bir örnek de verdi. İki değişkenli bir fonksiyon $z = f(x, y)$ bir yüzey gösterir. Yüzeyin bir noktasına teğet doğru değil, teğet düzlem (tangent plane) yerleştirilir. Bu, bu dönemin değil gelecek dönemin konusudur. Teğet düzleme dik olan bir normal vektör ve normal doğrusu vardır. Bu normal vektör gradyandır (gradient), $\nabla f$.

Hocaya göre bu fikir makine öğrenmesinde çok önemlidir. Bilgisayar bilimlerinde optimal çözümler elde etmek için kullanılan gradyan inişi (gradient descent) algoritması gradyana dayanır. Bugün gördüğümüz normal doğrusu, gradyanın en temel hâlidir.

> **Hocanın vurgusu:** Bunları ileride kullanacaksınız. İşin mantığını kavrayanlar "hocamız bize bunlardan daha önce bahsetmişti" diyecek. Kavramazsanız ezber yapıp geçersiniz.

> **Ek bilgi (derste anlatılmadı):** Gradyan, bir fonksiyonun en hızlı arttığı yönü gösteren vektördür. Gradyan inişi, bir fonksiyonun minimumunu bulmak için her adımda gradyanın tersi yönünde küçük bir adım atar. Bu konu ilerideki çok değişkenli kalkülüs ve makine öğrenmesi derslerinde ayrıntılı işlenir.

Ardından bir öğrenci normal doğrusu için ek örnek istedi. Hoca, az önce çözülen örneğin zaten normal doğrusu örneği olduğunu söyledi ve ekranda yeniden gösterdi.

## 13. Örnek 9: Kapalı Formda İkinci Türev

**Soru (00:53:20):** $y^3 - x^3 = xy$ olmak üzere $y$'nin ikinci mertebeden türevini ($y''$) $x$ ve $y$ cinsinden yazın.

Hoca bunun dersin son sorusu olduğunu söyledi.

> **Hocanın vurgusu:** Kolay gibi görünüyor ama biraz dikkat ve işlem istiyor. Birinci mertebeden türevi bulurken sıklıkla kullandığınız formülü kullanabilirsiniz. Ama ikinci mertebeden türevi bulurken sıkıntı yaşarsınız. O yüzden anlattığımız diğer yöntemi kullanmak avantaj sağlar.

**Birinci türev:** Eşitliğin iki tarafının $x$'e göre türevi alınır. $y^3$'ün $y$'ye göre türevi $3y^2$, çarpı $y$'nin $x$'e göre türevi $y'$. $xy$ için çarpım kuralı kullanılır:

$$3y^2 y' - 3x^2 = y + x y'.$$

Buradan $y'$ yalnız bırakılır (ara adım eklendi):

$$y'(3y^2 - x) = 3x^2 + y \Rightarrow y' = \frac{3x^2 + y}{3y^2 - x}.$$

**İkinci türev (1. yol, bölüm kuralı):** $y'$ ifadesinin $x$'e göre yeniden türevi alınır. Hoca, $y$'nin $x$'e bağlı olduğunu hesaba katmak gerektiğini vurguladı. Bölüm kuralı: payın türevi çarpı payda, eksi pay çarpı paydanın türevi, bölü paydanın karesi:

$$y'' = \frac{(6x + y')(3y^2 - x) - (3x^2 + y)(6y\,y' - 1)}{(3y^2 - x)^2}.$$

Son olarak bu ifadede $y'$ yerine $\dfrac{3x^2 + y}{3y^2 - x}$ yazılır. Hoca sonucu bu noktada bıraktı.

**Soru:** Soruda "$x$ ve $y$ cinsinden" denmesinin özel bir anlamı var mı? **Cevap:** Hayır. Denklem kapalı formda verildiği için sonuç doğal olarak $x$ ve $y$ cinsinden çıkar. Söylenmese de böyle olurdu.

**İkinci türev (2. yol):** **Soru:** Bölme yapmadan, $3y^2 y' - 3x^2 = y + xy'$ eşitliğinin türevini bir kez daha alıp $y''$'yü yalnız bıraksak aynı sonuç gelir mi? **Cevap:** Evet, o da olur, aynı sonuca gelir. Hoca bu yolu da tahtada gösterdi:

- İki tarafın $x$'e göre türevi alınır; $y''$ içeren terimler bir tarafta toplanır.
- $y''$ ortak çarpan parantezine alınır. Katsayısı $3y^2 - x$ olur.
- Sonra $y'$ yerine $x$ ve $y$ cinsinden ifadesi yazılır.

<!-- BELİRSİZ: 2. yolun tahtadaki ara satırları altyazıda döngüye girmiş (00:59:04); yalnız $y''$'nün ortak paranteze alındığı ve katsayısının $3y^2 - x$ olduğu anlaşılıyor. -->

Bir öğrenci sorudaki karenin nereden geleceğini sordu. Hoca, $y'$ yerine yazılınca paydada $3y^2 - x$ gibi kareli bir ifadenin zaten geleceğini, düzenlenince aynı ifadenin çıkacağını söyledi.

> **Ders sonrası not:** Hoca sonucu sadeleştirmeden bıraktı. sympy ile $y'$ yerine yazılıp sadeleştirilince
> $$y'' = \frac{2xy\,(3x - 3y + 1)(9x^2 + 9xy + 9y^2 - 3x + 3y + 1)}{(x - 3y^2)^3}$$
> elde edilir. Pay, $a = 3x$, $b = -3y$, $c = 1$ için $a^3 + b^3 + c^3 - 3abc = (a + b + c)(a^2 + b^2 + c^2 - ab - bc - ca)$ özdeşliğinden $27(x^3 - y^3 + xy) + 1$'e eşittir. Eğri denklemine göre $x^3 - y^3 + xy = 0$ olduğundan bu çarpım $1$'dir. Böylece sonuç $y'' = -\dfrac{2xy}{(3y^2 - x)^3}$ biçimine iner.

Dersin sonunda hoca, sınav öncesinde genel alıştırmalar yapılacağını, öğrencilerin endişelenmemesi gerektiğini söyledi.

## Örnek Sorular

Bu derste kare ya da video yoktur. Aşağıdaki sorular derste hocanın sözlü okuduğu ve çözdüğü sorulardır. Ayrıntılı çözümler yukarıdaki bölümlerdedir.

- **Soru 1** (derste sözlü, 00:03:28): $\displaystyle\lim_{x \to 1^-} (1 - x)\tan\left(\frac{\pi}{2}x\right)$ limitini L'Hôpital kullanmadan bulun.
  - Çözüm: $u = 1 - x$ ile $\dfrac{u\cos\frac{\pi}{2}u}{\sin\frac{\pi}{2}u}$ elde edilir. Sonuç $\dfrac{2}{\pi}$.
- **Soru 2** (derste sözlü, 00:07:48): Hangi $a$ ve $b$ değerleri için $f$, $x = 0$'da süreksiz, $x = 1$'de süreklidir?
  - <!-- BELİRSİZ: Fonksiyonun kuralları ve sonuç altyazıda okunmuyor. -->
  - Çözüm yöntemi: $0$'da sağdan ve soldan limitler farklı olmalı. $1$'de sağdan limit = soldan limit = $f(1)$ olmalı.
- **Soru 3** (derste sözlü, 00:17:24–00:18:26): $\displaystyle\lim_{x \to \infty} \left(\sqrt{x + \sqrt{x}} - \sqrt{x}\right)$.
  - <!-- BELİRSİZ: Soru metni sözlü okunmuyor; anlatımdan ve kısa nottan kuruldu. -->
  - Çözüm: Eşlenikle çarpıp bölünür. Sonuç $\dfrac{1}{2}$.
- **Soru 4** (derste sözlü, 00:24:08): $f(x) = |x^2 - 1|$ fonksiyonu $x = 1$'de türevlenebilir mi?
  - Çözüm: Sağdan türev $2$, soldan türev $-2$. Türevlenemez. $f$, $\mathbb{R} \setminus \{-1, 1\}$'de türevlenebilir.
- **Soru 5** (derste sözlü, 00:31:16): $x + 2y = 1$ doğrusuna dik olan ve $y = x^2 - 2x$ eğrisine teğet olan doğrunun denklemi nedir?
  - Çözüm: $m = 2$, $x_0 = 2$, $y_0 = 0$. Teğet $y = 2x - 4$.
- **Soru 6** (derste sözlü, 00:37:10): $f(x) = x\sin\frac{1}{x}$ ($x \ne 0$), $f(0) = 0$ fonksiyonunun $x = 0$'da türevlenebilirliğini inceleyin.
  - Çözüm: Tanımdan $\lim_{x \to 0}\sin\frac{1}{x}$ elde edilir; bu limit yoktur. Türevlenemez.
- **Soru 7** (derste sözlü, 00:38:45): $y = x^3 - 3x$ grafiğinin teğetleri hangi $x$ değerlerinde yataydır?
  - Çözüm: $3x^2 - 3 = 0 \Rightarrow x = \pm 1$.
- **Soru 8** (derste sözlü, 00:41:32): $\cos(3x + y) + \sin(x + 3y) = -1$ eğrisinin $A\left(0, \frac{\pi}{2}\right)$ noktasındaki teğet ve normal doğrularını bulun.
  - Çözüm: $m_T = -3$. Teğet $y - \frac{\pi}{2} = -3x$. Normal $y - \frac{\pi}{2} = \frac{1}{3}x$.
- **Soru 9** (derste sözlü, 00:53:54): $y^3 - x^3 = xy$ olmak üzere $y''$'yü $x$ ve $y$ cinsinden yazın.
  - Çözüm: $y' = \dfrac{3x^2 + y}{3y^2 - x}$. Bölüm kuralıyla türev alınıp $y'$ yerine yazılır. Sadeleşmiş hâli $y'' = -\dfrac{2xy}{(3y^2 - x)^3}$ (sympy ile kesinleştirildi; hoca sadeleşmiş hâli vermedi).

## Dersin Toparlaması

Bu ders, şimdiye kadar görülen limit, süreklilik ve türev konularının bir genel uygulamasıydı. Limit tarafında iki temel araç öne çıktı: bilinen $\lim_{t \to 0}\frac{\sin t}{t} = 1$ limitine değişken değiştirerek benzetmek ve kök farkı içeren $\infty - \infty$ belirsizliklerinde eşlenik yöntemi. Süreklilik tarafında parçalı fonksiyonlarda sağdan limit, soldan limit ve fonksiyon değerinin karşılaştırılması kullanıldı. Türev tarafında $|x^2 - 1|$ ve $x\sin\frac{1}{x}$ gibi sürekli ama bazı noktalarda türevlenemeyen fonksiyonlar türevin tanımıyla incelendi.

Teğet doğrusu sorularında dik doğruların eğimleri çarpımının $-1$ olması, yatay teğet için $f'(x) = 0$ koşulu ve kapalı türev ile teğet ve normal doğrusu bulma çalışıldı. Hoca normal doğrusunun ileride hız ve ivme vektörleri, teğet düzlem, gradyan ve gradyan inişi gibi konuların temeli olduğunu vurguladı. Son olarak kapalı formda ikinci türevin iki yolla nasıl bulunacağı gösterildi. Hoca gelecek hafta ters trigonometrik fonksiyonları ve türevlerini işleyeceklerini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
