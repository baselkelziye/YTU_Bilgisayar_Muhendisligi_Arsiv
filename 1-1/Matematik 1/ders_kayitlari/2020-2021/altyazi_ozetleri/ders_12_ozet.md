# Ders 12 Çalışma Özeti

> Tarih: 11 Kasım 2020 (Çarşamba). Ders İngilizce anlatıldı, arada Türkçe açıklamalar var. Bu ders 1. vizeye hazırlık için genel alıştırma (soru çözümü) dersidir.

## Genel Konular

- 1. vize tarihi ve sınav sistemi.
- Çalışma önerileri.
- Genel alıştırmalar:
  - $1^\infty$, $0^0$, $0\cdot\infty$, $\infty - \infty$, $\dfrac{\infty}{\infty}$ belirsizlikli limitler.
  - Tanım kümesi bulma (arccos, ln, iç içe ln, kök).
  - arcsin içeren fonksiyonun artan/azalan olduğu aralıklar.
  - Ters fonksiyonun bir noktadaki türevi.
  - Kapalı (implicit) fonksiyonda teğet ve normal doğru.
  - Doğrusallaştırma (linearization) ile yaklaşık değer.

## Hocanın Özellikle Vurguladığı Kısımlar

- **1. vize:** 21 Kasım 2020 Cumartesi, saat 15.00 (58. grup). Sınav öğrenci modülü / Yıldız uygulamaları üzerinden online yapılacak. Tarih sistemde sınavdan önce güncellenecek.
- Her sorunun arkasındaki "felsefeyi" anlarsanız çok soru çözmenize gerek yok.
- Önce tanım ve kavramları öğrenin. Tanımlardaki ince nüansları kaçırırsanız ne kadar soru çözseniz anlamı yok.
- Çözülen soruları çözüme bakmadan tekrar çözmeye çalışın. Video izlerken önünüze kâğıt kalem alın.
- Hoca, yaz döneminin test sınavını derste birlikte çözeceklerini söyledi.
- Artan/azalan sorularında **önce tanım kümesini bulun.** Tanım kümesi dışında artan/azalan demek anlamsızdır. Test şıkları bu hatayı yakalamak için hazırlanabilir.
- Ezbere giderseniz basit yerlerde yanlış şıkkı işaretlersiniz. Test sınavında kısmi puan yoktur.
- Bazen değişken değiştirmek ($t = \frac{1}{x}$) L'Hôpital işlemini kolaylaştırır.
- L'Hôpital'ın mantığı: limit, anlık değişim oranlarının oranıdır. Polinomlarda derece karşılaştırması sonucu doğrudan gösterir.
- Hocanın tavsiyesi: Limit, türev, L'Hôpital, ters fonksiyon, artan/azalan gibi genel kuralları bir kâğıda özetleyin ve soru çözerken yanınızda bulundurun.

## Kısa Tekrar Notları

- $u(x) \to 0$ ise $\displaystyle\lim (1 + a u)^{1/u} = e^a$.
- arccos ve arcsin argümanı $[-1, 1]$; ln argümanı $> 0$; çift dereceli kök içi $\ge 0$; tek dereceli kök her reel sayıda tanımlı.
- İç içe ln: dıştan içe doğru her argüman pozitif olmalı.
- $(f^{-1})'(y_0) = \dfrac{1}{f'(x_0)}$, $f(x_0) = y_0$. $f^{-1}$'i bulmaya gerek yok.
- Teğet doğru: $y - y_0 = m_t (x - x_0)$, $m_t = f'(x_0)$. Normal doğru: $m_n = -\dfrac{1}{m_t}$ ($m_t \neq 0$).
- Doğrusallaştırma: $f(x) \approx f(a) + f'(a)(x - a)$.
- $\sqrt{x^2} = |x|$.

## Detaylı Açıklamalar

### Sınav bilgisi ve öğrenci soruları

- Sınav 21 Kasım Cumartesi saat 15.00'te (hoca 58. grup için kontrol etti).
- Sınav, derse girilen sistemdeki öğrenci modülünden yapılacak (online.yildiz.edu.tr).
- Bir öğrenci yalnızca ders notlarındaki soruları çözmenin yeterli olup olmadığını sordu. Hoca: Evet, ama her sorunun arkasındaki felsefeyi anlamaya odaklanın.
- Bir öğrenci tabletteki notların yüklenmesini istedi. Hoca: Bunlar AVS'deki ders notlarının özeti; asıl notlardan çalışmak daha iyi.

### Alıştırma 1: $\displaystyle\lim_{x\to 1}\big(1 + \sin(x - 1)\big)^{1/(x-1)}$

- Belirsizlik: $x \to 1$ iken taban $\to 1$, üs $\to \pm\infty$. Yani $1^\infty$.
- **Benzetme yöntemi:**
  - $u = \sin(x - 1) \to 0$.
  - $\left[(1 + u)^{1/u}\right]^{\frac{\sin(x-1)}{x-1}}$.
  - Köşeli parantez $e$'ye, üs $\dfrac{\sin(x-1)}{x-1} \to 1$'e gider.
  - Cevap: $e^1 = e$.
- **Genel yöntem:**
  - $A = \big(1 + \sin(x-1)\big)^{1/(x-1)}$, $\ln A = \dfrac{\ln\big(1 + \sin(x-1)\big)}{x - 1}$.
  - $x \to 1$: $\dfrac{0}{0}$. L'Hôpital: $\dfrac{\cos(x-1)/(1 + \sin(x-1))}{1} \to 1$.
  - $\displaystyle\lim A = e^1 = e$.

### Alıştırma 2: Tanım kümesi

- **Soru:** $f(x) = \arccos\left(\dfrac{x-5}{2}\right) + \ln(6 - x) + \sin\sqrt[3]{x-2}$ fonksiyonunun tanım kümesi.
- **Çözüm:**
  - arccos: $-1 \le \dfrac{x - 5}{2} \le 1 \Rightarrow -2 \le x - 5 \le 2 \Rightarrow 3 \le x \le 7$.
  - ln: $6 - x > 0 \Rightarrow x < 6$.
  - Küp kök: $x - 2$ her reel sayı olabilir.
  - Kesişim: $D(f) = [3, 6)$.
- Bir öğrenci $6 - x \neq 1$ olması gerekip gerekmediğini sordu. Cevap: Hayır. ln'in argümanı yalnızca pozitif olmalıdır; 1 olabilir ($\ln 1 = 0$).

### Alıştırma 3: İç içe logaritma

- **Soru:** $f(x) = \ln\big(\ln(\ln x)\big) + \sqrt{9 - x^2}$ fonksiyonunun tanım kümesi.
- **Çözüm:**
  - Birinci terim üç ln'in bileşkesidir. Dıştan içe gidilir.
  - En dıştaki ln için: $\ln(\ln x) > 0$.
  - Üstel fonksiyon uygulanınca: $\ln x > e^0 = 1$. Tekrar uygulanınca: $x > e$.
  - (Bu şart, içteki $\ln x > 0$ ve $x > 0$ şartlarını da kapsar.)
  - Kök: $9 - x^2 \ge 0 \Rightarrow -3 \le x \le 3$.
  - Kesişim: $D(f) = (e, 3]$. $e$ dahil değil, 3 dahil.
- Hoca: Herkes doğru cevabı ($e$ ile 3 arası) bulmuş.

### Alıştırma 4: Artan/azalan aralıklar

- **Soru:** $f(x) = \arcsin\sqrt{1 - x^2}$ fonksiyonunun artan ve azalan olduğu aralıklar.
- **Önce tanım kümesi:**
  - Kök: $1 - x^2 \ge 0 \Rightarrow -1 \le x \le 1$.
  - arcsin: $-1 \le \sqrt{1-x^2} \le 1$. Kare alınca $0 \le 1 - x^2 \le 1 \Rightarrow x^2 \ge 0$; her zaman doğru.
  - $D(f) = [-1, 1]$.
- **Türev:**
  - $u = \sqrt{1 - x^2}$, $u' = \dfrac{-2x}{2\sqrt{1-x^2}} = \dfrac{-x}{\sqrt{1-x^2}}$.
  - $f'(x) = \dfrac{u'}{\sqrt{1 - u^2}} = \dfrac{-x/\sqrt{1-x^2}}{\sqrt{x^2}} = \dfrac{-x}{|x|\sqrt{1 - x^2}}$.
- **İşaret:**
  - $0 < x < 1$: $f' < 0$. $f$ azalan.
  - $-1 < x < 0$: $f' > 0$. $f$ artan.
- **Cevap:** $f$, $(-1, 0)$ aralığında artan, $(0, 1)$ aralığında azalan. $[-1, 1]$ dışında fonksiyon tanımlı değil.
- Hoca: Tanım kümesini bulmadan yapan öğrenciler yanlış bulmuş. Test şıklarında $(-\infty, -1)$ veya $(1, \infty)$ gibi seçenekler olabilir.
- Bir öğrenci mutlak değerin nereden geldiğini sordu. Hoca: Kök içinde $x^2$ kaldı; $\sqrt{x^2} = |x|$, daima pozitif.
- Bir öğrenci türevin işaretinin neden önemli olduğunu sordu. Hoca: Bu soru maksimum-minimum sorusu değil; yalnızca artan/azalan aralık sorusu. Türevin işareti bunu verir.
- Hoca, tanım kümesi adımında $1 - x^2$'nin karesini alırken bir yazım hatası yaptı; bir öğrenci uyardı, düzeltildi.

### Alıştırma 5 (test tipi): Ters fonksiyonun türevi

- **Soru:** $f: \mathbb{R} \to \mathbb{R}$, $f(x) = x\sqrt{8 + x^2}$. $(f^{-1})'(3) = ?$
- $f^{-1}$'i hesaplamaya gerek yok.
- **Formül:** $f^{-1}\big(f(x)\big) = x$. Zincir kuralı: $(f^{-1})'\big(f(x)\big)\cdot f'(x) = 1$. Yani $(f^{-1})'\big(f(x_0)\big) = \dfrac{1}{f'(x_0)}$.
- **Çözüm:**
  - $f(x_0) = x_0\sqrt{8 + x_0^2} = 3 \Rightarrow x_0 = 1$ (tek çözüm).
  - $f'(x) = \sqrt{8 + x^2} + x\cdot\dfrac{2x}{2\sqrt{8 + x^2}} = \sqrt{8 + x^2} + \dfrac{x^2}{\sqrt{8 + x^2}}$.
  - $f'(1) = 3 + \dfrac{1}{3} = \dfrac{10}{3}$.
  - $(f^{-1})'(3) = \dfrac{1}{10/3} = \dfrac{3}{10}$.
- Hoca: Cevap $\dfrac{3}{10}$, $\dfrac{10}{3}$ değil. Ezberle gidenler burada hata yapıyor.
- Derse düzenli katılıp anlattıklarını öğrenenler için stres yapılacak bir durum yok.

### Alıştırma 6: $\infty - \infty$

- **Soru:** $\displaystyle\lim_{x\to 0^+}\left(\frac{1}{x} - \frac{1}{\sqrt{x}}\right)$.
- Belirsizlik: $\infty - \infty$. L'Hôpital doğrudan uygulanamaz.
- **L'Hôpital ile:**
  - Payda eşitlenir: $\dfrac{\sqrt{x} - x}{x\sqrt{x}}$ → $\dfrac{0}{0}$.
  - L'Hôpital: $\dfrac{\frac{1}{2\sqrt{x}} - 1}{\sqrt{x} + x\cdot\frac{1}{2\sqrt{x}}} = \dfrac{\frac{1 - 2\sqrt{x}}{2\sqrt{x}}}{\frac{3\sqrt{x}}{2}} = \dfrac{1 - 2\sqrt{x}}{3x}$.
  - $x \to 0^+$: $\dfrac{1}{0^+} \to +\infty$.
- **Eşlenik yöntemiyle (L'Hôpital'sız):**
  - $\dfrac{1}{x} - \dfrac{1}{\sqrt{x}} = \dfrac{1 - \sqrt{x}}{x}$ → pay 1'e, payda $0^+$'a gider.
  - Bir öğrenci eşlenikle de çözülebileceğini sordu; hoca bu yolun belki daha kolay olduğunu söyledi.
- **Cevap:** $+\infty$.
- Bu sırada hoca rastgele yoklama aldı.

### Alıştırma 7: $0\cdot\infty$ ve değişken değiştirme

- **Soru:** $\displaystyle\lim_{x\to\infty} x^2\left(1 - \cos\frac{1}{x}\right)$.
- Belirsizlik: $\infty \cdot 0$.
- Düzenleme: $\dfrac{1 - \cos\frac{1}{x}}{1/x^2}$.
- Değişken değiştirme: $t = \dfrac{1}{x}$, $x \to \infty$ iken $t \to 0^+$.
- $\displaystyle\lim_{t\to 0^+}\frac{1 - \cos t}{t^2}$ → $\dfrac{0}{0}$. L'Hôpital: $\dfrac{\sin t}{2t} \to \dfrac{1}{2}$.
- **Cevap:** $\dfrac{1}{2}$.

### Alıştırma 8: $0^0$

- **Soru:** $\displaystyle\lim_{x\to 0^+} x^{\frac{1}{\ln(e^x - 1)}}$.
- Belirsizlik: Taban $\to 0^+$. $e^x - 1 \to 0^+$, $\ln \to -\infty$, üs $\to 0$. Yani $0^0$.
- **Genel yöntem:**
  - $A = x^{1/\ln(e^x-1)}$, $\ln A = \dfrac{\ln x}{\ln(e^x - 1)}$.
  - $x \to 0^+$: $\dfrac{-\infty}{-\infty}$.
  - L'Hôpital: $\dfrac{1/x}{e^x/(e^x - 1)} = \dfrac{e^x - 1}{x}\cdot\dfrac{1}{e^x}$.
  - Limiti parçala: $\dfrac{1}{e^x} \to 1$. $\dfrac{e^x - 1}{x}$ → $\dfrac{0}{0}$, L'Hôpital: $e^x \to 1$.
  - $\displaystyle\lim \ln A = 1 \Rightarrow \lim A = e$.
- **Cevap:** $e$. Cevap 1 değil; ln'den geri dönmek için üstel fonksiyon uygulanır.

### Alıştırma 9: Kapalı fonksiyonda teğet ve normal doğru

- **Soru:** $x^y = 2y$ eğrisinin $P(2, 1)$ noktasındaki teğet ve normal doğrularının denklemleri (varsa).
- **Çözüm:**
  - Olağan bir fonksiyon değil. İki tarafa ln uygulanır: $y\ln x = \ln(2y)$.
  - $x$'e göre türev: $y'\ln x + y\cdot\dfrac{1}{x} = \dfrac{2y'}{2y} = \dfrac{y'}{y}$.
  - $P(2,1)$: $m\ln 2 + \dfrac{1}{2} = m$.
  - $m(\ln 2 - 1) = -\dfrac{1}{2} \Rightarrow m_t = -\dfrac{1}{2(\ln 2 - 1)} = \dfrac{1}{2(1 - \ln 2)}$.
- **Teğet doğru:** $y - 1 = \dfrac{1}{2(1 - \ln 2)}(x - 2)$.
- **Normal doğru:** $m_n = -\dfrac{1}{m_t} = 2(\ln 2 - 1)$. $y - 1 = 2(\ln 2 - 1)(x - 2)$.
- Hoca önce $x$ ile $y$'yi karıştırıp $\frac{y}{x}$ terimine 2 yazdı; bir öğrenci $\frac{1}{2}$ olması gerektiğini söyledi, hoca düzeltti.
- Hoca: Sayılar biraz çirkin çıktı; testte daha düzgün gelir.
- Bir öğrenci doğru denklemini sordu. Hoca açıkladı:
  - Noktası $P(x_0, y_0)$ ve eğimi bilinen doğru: $\dfrac{y - y_0}{x - x_0} = m$.
  - Teğet eğimi $f'(x_0)$. Teğet: $y - y_0 = f'(x_0)(x - x_0)$.
  - Normal doğru teğete diktir, eğimler çarpımı $-1$: $m_n = -\dfrac{1}{m_t}$, $m_t \neq 0$.

### Alıştırma 10: Doğrusallaştırma ile yaklaşık değer

- **Soru:** $g$ türevlenebilir, $g(1) = 4$, $g'(1) = 4$. $f(x) = \dfrac{g(x^2)}{1 + x^2}$. $f(1{,}25) \approx ?$
- Hoca: Teğet/normal doğru soruları bu şekilde de sorulabilir; fonksiyon açıkça verilmez, $g$ ve şartlar verilir.
- **Türev (bölüm kuralı):**
  - $f'(x) = \dfrac{g'(x^2)\cdot 2x\cdot(1 + x^2) - g(x^2)\cdot 2x}{(1 + x^2)^2}$.
- **$a = 1$ seçilir** (1,25'e yakın ve değerler biliniyor):
  - $f'(1) = \dfrac{4\cdot 2\cdot 2 - 4\cdot 2}{4} = \dfrac{16 - 8}{4} = 2$.
  - $f(1) = \dfrac{g(1)}{2} = \dfrac{4}{2} = 2$.
- **Doğrusallaştırma:**
  - $\Delta f \approx f'(1)\,\Delta x$, $\Delta f = f(x) - f(1)$, $\Delta x = x - 1$.
  - $f(x) \approx f(1) + f'(1)(x - 1) = 2 + 2(x - 1)$.
  - $f(1{,}25) \approx 2 + 2\cdot 0{,}25 = 2{,}5 = \dfrac{5}{2}$.
- Hoca: Bu tür sorular sınavda (test veya final) gelebilir; hocalar sormayı seviyor.

### Alıştırma 11: $\dfrac{\infty}{\infty}$

- **Soru:** $\displaystyle\lim_{x\to\infty}\frac{e^{\arctan x} - x}{\ln(1 + x^2) + x}$.
- Belirsizlik: $\arctan x \to \dfrac{\pi}{2}$, yani $e^{\arctan x}$ sabite gider. Pay $\to -\infty$, payda $\to +\infty$.
- **Hatırlatma:** $(e^u)' = e^u u'$, $(\arctan u)' = \dfrac{u'}{1 + u^2}$, $(\ln u)' = \dfrac{u'}{u}$.
- **L'Hôpital:**
  - $\displaystyle\lim_{x\to\infty}\frac{e^{\arctan x}\cdot\frac{1}{1+x^2} - 1}{\frac{2x}{1+x^2} + 1}$.
  - $e^{\arctan x}$ sabite, $\dfrac{1}{1+x^2} \to 0$. $\dfrac{2x}{1 + x^2} \to 0$.
  - $= \dfrac{0 - 1}{0 + 1} = -1$.
- Hoca önce gereksiz bir sadeleştirmeye girdi, sonra sildi: düzenlemeye gerek yok.
- **Cevap:** $-1$.
- Bir öğrenci $\dfrac{2x}{1+x^2}$'nin neden 0'a gittiğini sordu. Hoca:
  - Payın derecesi 1, paydanınki 2. Payda daha hızlı artar, sonuç 0.
  - Payın derecesi büyük olsaydı ($\frac{1 + x^2}{2x}$) sonuç $\infty$ olurdu.
  - L'Hôpital de aynı şeyi söyler: anlık değişim oranlarının oranı.

### Ders sonu

- Haftaya yine genel soru çözümü yapılacak.
- "Başarılar, görüşmek üzere."

### Ders sonrası notlar

- **Alıştırma 2:** Hoca altyazıda bir an "$x$ smaller than 6" ile "$x \ge 3$" ifadelerini kesiştirirken $x \le 7$ şartını söylemiyor; tahtada $3 \le x \le 7$ yazılı. Sonuç $[3, 6)$ değişmez.
- **Alıştırma 7:** Altyazıda "as x goes to 0" deniyor. Soru $x \to \infty$ içindir; $x^2 \to \infty$, $\cos\frac{1}{x} \to 1$.
- **Alıştırma 9:** Altyazıda teğet eğimi "$-1$ times 2 times $\ln 2$" gibi bozuk geçiyor. Doğru eğim $m_t = -\dfrac{1}{2(\ln 2 - 1)}$.
- **Alıştırma 10:** Altyazıda "$g$ of 1, $g'$ of 1 is equal to 4" geçiyor; hesaplarda $g(1) = 4$ ve $g'(1) = 4$ kullanılıyor.
- **Alıştırma 11:** Altyazıda paydaki terim "$\ln$ 1 plus ekstrem" diye bozuk geçiyor. Doğru soru tahtadaki gibi $\ln(1 + x^2) + x$'tir.
- Altyazıda bir döngü var (00:14:08). Bu kısım altyazıda anlaşılmıyor; içerik tahtadan tamamlandı.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
