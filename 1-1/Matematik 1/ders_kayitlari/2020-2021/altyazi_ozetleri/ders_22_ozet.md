# Ders 22 Çalışma Özeti

> Tarih: 16 Aralık 2020 (Çarşamba). Ders İngilizce anlatıldı, arada Türkçe açıklamalar var. Bu ders 2. vizeye hazırlık için soru çözümü dersidir. Hocanın tablet kalemi bozuk olduğu için hoca fareyle yazmaya çalıştı; bazı çözümler ekranda tam yazılamadı.

## Genel Konular

- Kalkülüsün temel teoremi 1. kısım (Fundamental Theorem of Calculus, Part 1) ile belirli integralle tanımlı fonksiyonların türevi.
- Belirli integralle tanımlı fonksiyon içeren limit (L'Hôpital ile).
- Logaritmik türev ile ikinci mertebe türev hesabı.
- Riemann toplamı (Riemann sum) ile alan hesabı.
- Ortalama değer (average value) ile ortalama değişim oranı (average rate of change) farkı.
- Grafik çizimi: $y = \dfrac{x}{x^2-1}$.
- Geçen yılın mazeret sınavından test soruları: zincir kuralı, parçalı fonksiyonun sürekliliği, yerel uç değer, türevler için ortalama değer teoremi, türev grafiğinden yorum.
- Geçen yılın 1. vizesinde çözülmeyen (2. vize konusu olan) içbükeylik sorusu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Çözülen sorular Pınar Albayrak Hoca'nın hazırladığı uygulama notlarından (uygulama 5). Bu notları Pınar Hoca'nın AVS sayfasından indirebilirsiniz. Hoca uygulama 5 dosyasını Zoom sohbetinden de paylaştı.
- Üç yıldızla işaretlenen soru tipleri test sınavında çıkabilir.
- 2. vize ağırlıkla 1. vizeden sonraki konulardan gelir.
- Kısmi integrasyon (by parts), tablo yöntemi (tabular method) ve indirgeme formülü (reduction formula) **final** konusudur, 2. vize konusu değildir. Hoca bu tip bir sorunun gelme olasılığını yaklaşık %5 olarak gördü.
- Önemli olan çözümün mantığını anlamak. Ders videolarını izlediyseniz bu soruları çözersiniz.
- "Ders derste öğrenilir": önünüzde kâğıt kalem olsun, soruyu kendiniz çözün.
- Bükülme noktası (inflection point), içbükeylik (concavity) ve türev grafiğinin yorumu üzerine sorular 2. vizede çıkabilir.
- Hoca haftaya da soru çözeceğini, 12. haftanın konusunu bitirirse biraz da konu işleyeceğini söyledi.

## Kısa Tekrar Notları

- **Temel teorem (genelleştirilmiş hâli):**
  $$\frac{d}{dx}\int_{a(x)}^{b(x)} f(t)\,dt = f(b(x))\,b'(x) - f(a(x))\,a'(x)$$
- Alt ve üst sınır aynıysa belirli integral sıfırdır: $\int_a^a f(t)\,dt = 0$.
- $f'(x)$ üstel-üstel biçimdeyse (ör. $(2x)^x$) ikinci türev için önce iki tarafın $\ln$'i alınır.
- **Ortalama değer:** $f_{\text{ort}} = \dfrac{1}{b-a}\displaystyle\int_a^b f(x)\,dx$.
- **İntegraller için ortalama değer teoremi:** $f(c) = f_{\text{ort}}$ olacak şekilde bir $c \in [a,b]$ vardır.
- **Ortalama değişim oranı** başka bir kavramdır: $\dfrac{f(b)-f(a)}{b-a}$. İkisini karıştırmayın.
- **Türevler için ortalama değer teoremi (geometrik yorum):** Kirişe paralel teğetin değme noktası $f'(c) = \dfrac{f(b)-f(a)}{b-a}$ eşitliğinden bulunur.
- Türev grafiğinden okuma:
  - $f' > 0$ olan aralıkta $f$ artan, $f' < 0$ olan aralıkta $f$ azalan.
  - $f'$ artan ise $f'' > 0$, yani $f$ yukarı içbükey (concave up).
  - $f'$ azalan ise $f'' < 0$, yani $f$ aşağı içbükey (concave down).
  - $f''$ bir noktada işaret değiştiriyorsa o nokta bükülme noktasıdır.
- Tanım kümesinde olmayan nokta kritik nokta ya da bükülme noktası olamaz.

## Detaylı Açıklamalar

### Örnek 1: Belirli integral içeren limit

$$L = \lim_{x\to 0} \frac{\displaystyle\int_0^x \frac{\sin^2 t}{\cos t}\,dt}{\tan x}$$

- $x \to 0$ iken pay $\int_0^0 = 0$'a, payda $\tan 0 = 0$'a gider. $\frac{0}{0}$ belirsizliği var, L'Hôpital uygulanır.
- Payın türevi temel teoremden: $\dfrac{\sin^2 x}{\cos x}$. Paydanın türevi: $\sec^2 x$.
- $$L = \lim_{x\to 0} \frac{\sin^2 x}{\cos x}\cdot\cos^2 x = \lim_{x\to 0} \sin^2 x \cos x = 0$$

### Örnek 2: $\int_0^{\cos x} f(t)\,dt = \arctan x$ ise $f\!\left(\tfrac{1}{\sqrt 2}\right) = ?$ ($x \in (0, \tfrac{\pi}{2})$)

- İki tarafın türevi alınır: $-\sin x \cdot f(\cos x) - 0 = \dfrac{1}{1+x^2}$.
- Buradan $f(\cos x) = \dfrac{-1}{\sin x\,(1+x^2)}$.
- $\cos x = \tfrac{1}{\sqrt 2}$ için uygun değer $x = \tfrac{\pi}{4}$:
  $$f\!\left(\tfrac{1}{\sqrt2}\right) = \frac{-1}{\tfrac{1}{\sqrt2}\left(1+\tfrac{\pi^2}{16}\right)} = \frac{-16\sqrt2}{\pi^2+16}$$

### Örnek 3: $x \ge 1$ için $f(x) = \int_1^x (2t)^t\,dt$ ise $f''(1) = ?$

- Temel teoremden: $f'(x) = (2x)^x$.
- İki tarafın $\ln$'i: $\ln f'(x) = x \ln(2x)$.
- Türev (zincir ve çarpım kuralı): $\dfrac{f''(x)}{f'(x)} = \ln(2x) + x\cdot\dfrac{2}{2x} = \ln(2x) + 1$.
- $f''(x) = (2x)^x\,[\ln(2x) + 1]$, dolayısıyla $f''(1) = 2(\ln 2 + 1)$.

### Örnek 4: $f(x) = \cos x - \displaystyle\int_0^{\sin x} \frac{dt}{t^3+8}$ ise $f(\pi)$ ve $f'(\pi)$

- $f(\pi) = \cos\pi - \int_0^0 (\dots) = -1 - 0 = -1$.
- $f'(x) = -\sin x - \cos x \cdot \dfrac{1}{\sin^3 x + 8}$.
- $f'(\pi) = -0 - (-1)\cdot\dfrac{1}{0+8} = \dfrac{1}{8}$.

### Örnek 5: İkinci türevin 0'daki değeri (2016 sınavı)

- Altyazıdan anlaşılan: $f'(x) = (x^2+9)^{\sin x}$ biçiminde (integrant fonksiyonu temel teoremle yerine konunca).
- $\ln f'(x) = \sin x \cdot \ln(x^2+9)$.
- Türev: $\dfrac{f''(x)}{f'(x)} = \cos x \ln(x^2+9) + \sin x \cdot \dfrac{2x}{x^2+9}$.
- $x = 0$ yazılır. $f'(0) = 9^0 = 1$ olduğundan $f''(0) = \ln 9 = 2\ln 3$.
- Hoca önce "$\ln 2 \cdot \ln 3$" dedi, sonra doğru cevabı $2\ln 3$ (ya da $\ln 9$) olarak verdi.

### Örnek 6: Riemann toplamı ile alan

- $f(x) = x^3$ fonksiyonunun $[0,1]$ üzerindeki grafiği altındaki alan.
- $[0,1]$ aralığı $n$ eşit parçaya bölünür: $\Delta x = \dfrac{1-0}{n} = \dfrac1n$, $x_i = \dfrac{i}{n}$.
- Toplam: $\displaystyle\sum_{i=1}^{n} f(x_i)\,\Delta x = \sum_{i=1}^{n} \frac{i^3}{n^3}\cdot\frac1n$.
- $\sum i^3 = \left(\dfrac{n(n+1)}{2}\right)^2$ formülü kullanılır.
- $n \to \infty$ limiti hatasız gerçek alanı verir: $\dfrac14$.
- Bir öğrenci, alt Riemann toplamında indisin $i = 0$'dan $n-1$'e gitmesi gerektiğini sordu. Hoca notlardaki indisin yanlış yazıldığını kabul etti. Limitte alt ve üst toplam aynı sonuca gider.

### Örnek 7: Ortalama değer

- Altyazıda fonksiyon "$2x + 1$" ve "$f'(x) = 2x+1$" diye karışık geçiyor; aralık altyazıda anlaşılmıyor.
- Formül: $f_{\text{ort}} = \dfrac{1}{b-a}\int_a^b f(x)\,dx$.
- Bir öğrencinin sorusu üzerine hoca farkı açıkladı: soru ortalama değeri istiyorsa formül yeterli. "İntegraller için ortalama değer teoremi" soruluyorsa $f(c) = f_{\text{ort}}$ eşitliğini sağlayan $c$ bulunur.

### Örnek 8: $y = \dfrac{x}{x^2-1}$ grafiğini çiziniz

1. **Tanım kümesi:** $\mathbb{R} \setminus \{-1, 1\}$.
2. **Düşey asimptotlar:** $x = 1$ ve $x = -1$.
3. **Yatay asimptot:** $x \to \pm\infty$ iken $y \to 0$, yani $y = 0$. Yatay asimptot olduğu için eğik asimptot yok.
4. **Birinci türev:**
   $$y' = \frac{(x^2-1) - x\cdot 2x}{(x^2-1)^2} = -\frac{1+x^2}{(x^2-1)^2}$$
   - $y' = 0$ olan nokta yok. $x = \pm1$'de türev tanımsız ama bu noktalar tanım kümesinde değil.
   - Kritik nokta yok, yerel uç değer yok. Fonksiyon her yerde azalan.
5. **İkinci türev:**
   $$y'' = \frac{2x(x^2+3)}{(x^2-1)^3} = \frac{2x^3+6x}{(x^2-1)^3}$$
   - $x = \pm1$ tanım kümesinde olmadığı için bükülme noktası olamaz.
   - $x = 0$'da $y''$ işaret değiştirir, $(0,0)$ bükülme noktasıdır.
6. **İşaret tablosu:**

   | Aralık | $y'$ | $y''$ | Grafik |
   |---|---|---|---|
   | $(-\infty, -1)$ | $-$ | $-$ | azalan, aşağı içbükey |
   | $(-1, 0)$ | $-$ | $+$ | azalan, yukarı içbükey |
   | $(0, 1)$ | $-$ | $-$ | azalan, aşağı içbükey |
   | $(1, \infty)$ | $-$ | $+$ | azalan, yukarı içbükey |

7. **Asimptot yorumu:** $x \to -1^-$ iken $f \to -\infty$, bu yüzden $-1$'in solunda grafik aşağı içbükey olmalı. $x \to -1^+$ iken $f \to +\infty$, sağında yukarı içbükey olmalı. Aynı mantık $x = 1$ için de geçerli.

- Aradan sonra hoca bir başka grafiği yorumladı: yatay asimptotu $y = 1$ olan bir grafikte, bükülme noktasının bir yanında grafik yukarı içbükey ($f''>0$), diğer yanında aşağı içbükey ($f''<0$). Aksi hâlde o doğru yatay asimptot olamaz.

### Mazeret sınavı soruları (geçen yıl)

**Soru 1 (Cevap A):** $h(0) = 1$, $h'(0) = -1$, $f'(1) = -1$ ve $k(x) = f(h(\ln x))$ ise $k'(1) = ?$

- Zincir kuralı: $k'(x) = f'(h(\ln x))\cdot h'(\ln x)\cdot \dfrac1x$.
- $x = 1$: $\ln 1 = 0$, $h(0) = 1$.
- $k'(1) = f'(1)\cdot h'(0)\cdot 1 = (-1)(-1) = 1$.

**Soru 2 (Cevap B):** $f(x) = \begin{cases} \dfrac{2\arcsin x}{\pi}, & x \le 1 \\[2mm] \dfrac{\ln x + 1}{\arccos x - 1}, & x > 1 \end{cases}$ için hangi ifade doğru?

- Soldan limit: $\dfrac{2\cdot\frac{\pi}{2}}{\pi} = 1$.
- Sağdan limit: Hoca $\dfrac{\ln 1 + 1}{0 - 1} = -1$ hesapladı.
- Sağ ve sol limit farklı, $f$ 1 noktasında sürekli değil.
- Mutlak değerli bir fonksiyonun türevi ve $\ln$ içinde $\frac00$ belirsizliği olan bir limit (cevap D) de kısaca konuşuldu; hoca kalemsiz yazamadığı için bu kısımlar ekranda ve altyazıda net değil.

**Soru: $f(x) = \ln(1-x^2)$**

- $f'(x) = \dfrac{-2x}{1-x^2}$. İşaret tablosuyla $x = 0$'da yerel maksimum incelenir.
- Hoca bu tip sorunun 2. vizede çıkabileceğini söyledi.

**Soru: $x \neq 2$ olmak üzere bir fonksiyonun uç değerleri**

- Önce birinci türev alınıp yerel uç noktalar bulunur, sonra bu noktalarda $f$ değeri hesaplanır. Hoca cevabın A olduğunu söyledi, işlemi öğrencilere bıraktı.

**Soru 19 (anahtar: Cevap D):** $y = x^2 - 8x$ eğrisinde, apsisleri $x = 1$ ve $x = 10$ olan noktaları birleştiren kirişe paralel teğetin değme noktası?

- Türevler için ortalama değer teoreminin geometrik yorumu: $f'(c) = \dfrac{f(10) - f(1)}{10 - 1}$.
- Şıklar: A) $(7,-7)$, B) $(4,-16)$, C) $(3,-15)$, D) $(5,-15)$, E) $(6,-12)$.
- Hoca anahtardaki gibi $c = 5$, $f(c) = -15$ dedi. Bir öğrenci $c = \tfrac{11}{2}$ bulduğunu söyledi. Hoca bunun sınavın taslak hâli olduğunu, hatalı olabileceğini belirtti. Doğrusu için "Ders sonrası notlar"a bakın.

**Soru: $g'$ grafiğinden yanlış ifadeyi bulma (Cevap E)**

- $(-\infty, -3)$'te $g' > 0$, yani $g$ artan: doğru.
- $(2, 5)$'te $g' < 0$, yani $g$ azalan.
- $x = 5$'in solunda $g' < 0$, sağında $g' > 0$: $g$'nin $x = 5$'te yerel minimumu var (birinci türev testi).
- $(0, 2)$'de $g'$ artan, yani $g'' > 0$. $(2, 4)$'te $g'$ azalan, yani $g'' < 0$. $g''$ $x = 2$'de işaret değiştirir, $x = 2$ bükülme noktasıdır.
- "$x = 2$ bükülme noktası değildir" ifadesi yanlış: cevap E.

### Geçen yılın 1. vizesinden 2. vize konusu olan soru

- Tüm reel sayılarda tanımlı bir $f$'nin türev grafiği veriliyor, yanlış ifade soruluyor. Hoca cevabın D olduğunu söyledi ve öğrencilerden doğrulamalarını istedi.
- Şıklar içbükeylik, azalanlık ve $x = 1$'de yerel uç değer üzerine.
- Hocanın açıklaması: $(-1, 1)$ aralığında $f'$ azalan ama pozitif (türev grafiği $x$ ekseninin üstünde). Bu yüzden $f$ bu aralıkta artan. "$f$ azalandır" diyen şık yanlış.
- Bu kısmın bir bölümü altyazıda anlaşılmıyor.

### Ders sonrası notlar

- **Soru 19'un anahtarı hatalı:** $f(1) = -7$, $f(10) = 20$, kiriş eğimi $\dfrac{27}{9} = 3$. $f'(c) = 2c - 8 = 3$ ise $c = \tfrac{11}{2}$, $f(\tfrac{11}{2}) = -\tfrac{55}{4}$. Bu nokta şıklarda yok; öğrencinin bulduğu $c = \tfrac{11}{2}$ doğru. Anahtardaki D şıkkı $(5,-15)$ ancak ikinci nokta $x = 9$ olsaydı doğru olurdu: $f(9) = 9$, eğim $\tfrac{16}{8} = 2$, $c = 5$, $f(5) = -15$. Sorunun metninde muhtemelen yazım hatası var.
- **Soru 2'de sağdan limit:** Hoca $\arccos 1 = 0$ kullanarak payda $-1$ buldu. Ancak $\arccos x$ yalnız $[-1,1]$'de tanımlı; $x > 1$ için $\arccos x$ reel sayı değildir. Ekrandaki yazım ($\arccos x - 1$) büyük olasılıkla $\arccos(x-1)$ ya da benzeri bir ifadedir. Bu durumda sağdan limit $\dfrac{1}{\pi/2} = \dfrac{2}{\pi}$ olur. Her iki okumada da sağ ve sol limit farklıdır, yani $f$ 1'de sürekli değildir; sonuç değişmez.
- **Örnek 5:** Hocanın ilk söylediği "$\ln2\cdot\ln3$" yanlış. Doğru cevap $2\ln 3 = \ln 9$.
- **Riemann toplamı:** Alt toplamda sol uç noktalar ($i = 0, \dots, n-1$), üst toplamda sağ uç noktalar ($i = 1, \dots, n$) alınır. Artan $x^3$ için $i = 1..n$ toplamı üst toplamdır. Limitte ikisi de $\tfrac14$ verir.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
