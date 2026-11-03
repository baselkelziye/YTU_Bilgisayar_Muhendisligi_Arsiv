# Ders 28 Çalışma Özeti

## Genel Konular

- Ders tarihi: 6 Ocak 2021 Çarşamba. Dönemin son dersi, final öncesi soru çözümü.
- Çözülen sorular "2020 Yaz - Final Mazeret MAT1071" sınavından. Hoca: Mazeret sınavlarında sorular biraz daha zor gelir.
- Konular:
  - Hacim (kabuk ve pul yöntemi), dönme ekseni parametreli soru.
  - Sınırsız bölgenin döndürülmesi (has olmayan integralle hacim).
  - Riemann toplamından belirli integrale geçiş.
  - Zincir kuralı, lineerleştirme ve temel teorem.
  - Parametreli has olmayan integral.
  - Yay uzunluğu, trigonometrik dönüşüm, ekstremum.
  - Yeni konu: $\tan(x/2)=t$ dönüşümü (Weierstrass dönüşümü).
- Finalde hangi konulardan kaç soru gelebileceğine dair hocanın tahmini.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Baştan sona sorumlusunuz:** Finalde en baştaki konulardan da soru gelebilir.
- **Temel eğrileri çizebilmek önemli:** Logaritmik, üstel, parabolik ve trigonometrik eğrileri çalışın.
- **Yarıçap pozitif olmalı:** $y$ negatif olan bölgede de kabuk yarıçapı $b-y$ çıkar. Böylece integrali ikiye bölmeye gerek kalmaz.
- **Derse katılım:** "Başarı, birim zamanda yapılan sorumlulukların, fedakârlıkların miktarıdır. Kolay yolu tercih etmeyin."
- **Has olmayan integral:** Has olmayan integrallerle ilgili en az iki soru bekleniyor. Biri yorum tipi (öncüllü) soru olacak; hoca bunun ihtimaline %98 diyor.
- **Zincir kuralı sorusu:** Benzer bir sorunun gelme ihtimali "en az %75".
- **Weierstrass dönüşümü:** Gelme ihtimali düşük (%10-20). Ama test sınavında seçici soru olarak sorulabilir.
- **Çalışma sırası:** Önce aşağıdaki tahmin listesindeki konulara çalışın. Sonra geçmiş yılların diğer soru tiplerine bakın.
- **Dosya:** Hoca derste çözülen soru dosyasını Zoom sohbetinden paylaştı. Öğrencilerin dosyayı birbirleriyle paylaşabileceğini söyledi.

## Kısa Tekrar Notları

- **Kabuk yöntemi, $x=-b$ etrafında:** yarıçap $b+x$ ($x\ge0$, $b>0$).
- **Yatay çubuk, $y=b$ etrafında:** yarıçap $b-y$. $y$ negatif de olsa bu ifade doğrudur.
- **Riemann toplamı:** $\Delta x=\dfrac{b-a}{n}$, $x_k=a+k\,\Delta x$.

$$\lim_{n\to\infty}\sum_{k=1}^{n}f(x_k)\,\Delta x=\int_a^b f(x)\,dx$$

- **Weierstrass dönüşümü:** $t=\tan\dfrac{x}{2}$ ise:
  - $\sin x=\dfrac{2t}{1+t^2}$
  - $\cos x=\dfrac{1-t^2}{1+t^2}$
  - $dx=\dfrac{2\,dt}{1+t^2}$
  - Bu dönüşüm, $\sin x$ ve $\cos x$ içeren rasyonel ifadeleri rasyonel fonksiyon integraline çevirir.
- **Hocanın final tahmini (en kötü ihtimalle):**

| Konu | Beklenen soru sayısı |
|---|---|
| Alan | En az 1 |
| Hacim | 2-3 |
| Yay uzunluğu | En az 1 |
| Yüzey alanı | 1 |
| Rasyonel fonksiyonların integrali | 1 |
| Trigonometrik dönüşüm | En az 1 |
| Has olmayan integral | 1 kesin, 2. için %50-60 |
| Temel teorem (fundamental theorem) | 1 (%95 üstü) |
| Ortalama değer teoremleri (türev ve integral) | %80 üstü |
| L'Hôpital ve temel teorem birlikte | 1 |

- Hocaya göre en az 10 soru 2. vizeden sonraki konulardan gelecek. Bu sayı 12-13'e çıkabilir.
- Soruların yaklaşık %70'i integrallerle ilgili olacak.
- Bir öğrenci indirgeme formüllerini (reduction formulas) sordu. Hoca: "Vizede gelmediyse gelme ihtimali var."

## Detaylı Açıklamalar

### Soru 3: Dönme ekseni bilinmeyen hacim sorusu

- **Soru:** $R$ bölgesi $y=2-x^2$, $y=x$ ve $x=0$ ile sınırlı. $R$, $x=-b$ ($b>0$) doğrusu etrafında döndürülünce hacim $\dfrac{11\pi}{2}$. $b$ kaçtır?
- **Kesişim:** $2-x^2=x\Rightarrow x=1$ (bölgede). Bölge $0\le x\le1$.
- **Kabuk yöntemi:** Dikey çubuk dönme eksenine paraleldir.
  - Yarıçap $b+x$, yükseklik $(2-x^2)-x$, kalınlık $dx$.

$$\frac{11\pi}{2}=2\pi\int_0^1(b+x)(2-x-x^2)\,dx$$

- $\displaystyle\int_0^1(2-x-x^2)\,dx=\frac{7}{6}$, $\displaystyle\int_0^1 x(2-x-x^2)\,dx=\frac{5}{12}$.
- $2\pi\left(\dfrac{7b}{6}+\dfrac{5}{12}\right)=\dfrac{11\pi}{2}\Rightarrow b=2$.
- Hoca hesabı ödev bıraktı ve cevabın $2$ olduğunu söyledi.

### Sınırsız bölge: $y=\ln x$, $x=0$, $y=b$

- **Soru:** Bölge $y=b$ doğrusunun altında, $y=\ln x$ ile $x=0$ ($y$ ekseni) arasında. $y=b$ doğrusu etrafında döndürülünce hacmi veren integral hangisidir?
- Bölge aşağı doğru sınırsız. Bu yüzden integral has olmayan bir integral olacak.
- **Kabuk yöntemi (yatay çubuk):**
  - Sağ uç hep $y=\ln x$, yani $x=e^y$ üzerinde. Sol uç hep $x=0$ üzerinde. Tek integral yeter.
  - Yarıçap: $b-y$. Bölgenin $y>0$ kısmında da, $y<0$ kısmında da aynı ifade çıkar. $y<0$ iken uzaklık $b+(-y)=b-y$ olur.
  - Yükseklik: $e^y-0=e^y$. Kalınlık $dy$.

$$V=2\pi\int_{-\infty}^{b}(b-y)\,e^{y}\,dy$$

- Bu integral hesaplanırsa $V=2\pi e^{b}$ çıkar (kısmi integrasyon ve limit).
- Doğru şık B.

### Soru 9: Lineerleştirme ve temel teorem (tahtadan)

- **Soru:** $h(x)=1+x+(x-2)\displaystyle\int_{-2}^{x}\left[(\sin t)^{2019}(\cos t)^{2020}-1\right]dt$ fonksiyonunun $x=2$'deki lineerleştirmesi hangisidir?
- $h(2)=3$.
- Temel teorem 1. kısım ve çarpım kuralıyla: $h'(x)=1+\displaystyle\int_{-2}^{x}g(t)\,dt+(x-2)\,g(x)$.
- $h'(2)=1+\displaystyle\int_{-2}^{2}\left[(\sin t)^{2019}(\cos t)^{2020}-1\right]dt$.
  - $(\sin t)^{2019}(\cos t)^{2020}$ tek fonksiyondur, simetrik aralıkta integrali $0$.
  - $\displaystyle\int_{-2}^{2}(-1)\,dt=-4$.
- $h'(2)=-3$, $L(x)=3-3(x-2)=-3x+9$. Cevap A.
- Hoca bu tür sorular için "Temel teorem 1 ve 2'yi çalışın" dedi.

### Soru 10: $y=x^2$ ve $y=3x$ arasındaki bölge, $x=-5$ etrafında

- **Soru:** Kabuk yöntemiyle hacmi veren integral hangisidir?
- Bölgede $x$ ve $y$ pozitif. Kesişim $x=0$ ve $x=3$.
- Yarıçap $x+5$, yükseklik $3x-x^2$ (üst uç eksi alt uç), kalınlık $dx$.

$$V=2\pi\int_0^3(x+5)(3x-x^2)\,dx$$

- Cevap E.

### Soru 11: Riemann toplamı

- **Soru:** $\displaystyle\lim_{n\to\infty}\sum_{k=1}^{n}\frac{n}{n^2+k^2}$ kaçtır?
- $n^2$ ortak paranteze alınır:

$$\sum_{k=1}^{n}\frac{n}{n^2+k^2}=\sum_{k=1}^{n}\frac{1}{1+\left(\frac{k}{n}\right)^2}\cdot\frac{1}{n}$$

- $\Delta x=\dfrac1n=\dfrac{1-0}{n}$ seçilir. O zaman $a=0$, $b=1$, $x_k=\dfrac kn$, $f(x)=\dfrac{1}{1+x^2}$.

$$\lim_{n\to\infty}\sum_{k=1}^{n}f(x_k)\Delta x=\int_0^1\frac{dx}{1+x^2}=\frac{\pi}{4}$$

- **Bir öğrencinin sorusu: "Neden $0$'dan $1$'e?"**
  - Sigma'da değişken $k$'dır; $n$'ye bağlı her şey sabittir.
  - $\dfrac1n$ ifadesi $\dfrac{b-a}{n}$ olarak okunur.
  - $a=1$, $b=2$ de seçilebilir ama o zaman fonksiyonu kurmak zorlaşır. $a=0$, $b=1$ seçimi $x_k$'yi en kolay verir.

### Zincir kuralı sorusu (tahtadan)

- **Soru:** $f$ türevlenebilir, $f(1)=-3$, $f'(1)=4$. $y=f\!\left(xy^2+f(x^2)\right)+5$ ise $\left.\dfrac{dy}{dx}\right|_{(1,2)}$ kaçtır?
- İki tarafın türevi alınır. $y$'nin $x$'e bağlı olduğu unutulmaz:

$$y'=f'\!\left(xy^2+f(x^2)\right)\cdot\left(y^2+2xy\,y'+f'(x^2)\cdot2x\right)$$

- $(1,2)$ noktasında iç ifade: $1\cdot4+f(1)=4-3=1$.
- $y'=4\left(4+4y'+4\cdot2\right)=48+16y'\Rightarrow y'=-\dfrac{16}{5}$.
- Cevap B. Hoca hesabı öğrencilere bıraktı.

### Soru 15: Parametreli has olmayan integral (tahtadan)

- **Soru:** $t>0$ için $\displaystyle\int_0^t\frac{dx}{(2-x)^2}$ hakkında hangi ifadeler doğrudur?
  - I. $t<2$ için yakınsar.
  - II. $t>2$ için $+\infty$'a ıraksar.
  - III. $t>2$ için $-\infty$'a ıraksar.
  - IV. $t=2$ için yakınsar.
- **I:** $t<2$ ise $[0,t]$ aralığında integrandı tanımsız yapan nokta yok. Olağan integraldir, yakınsar. Doğru.
- **II:** $t>2$ ise $x=2$ iç süreksizlik noktasıdır. İntegral iki limite ayrılır:

$$\lim_{t_1\to2^-}\int_0^{t_1}\frac{dx}{(2-x)^2}+\lim_{t_2\to2^+}\int_{t_2}^{t}\frac{dx}{(2-x)^2}$$

  - Belirsiz integral: $\displaystyle\int\frac{dx}{(2-x)^2}=\frac{1}{2-x}+C$.
  - Integrand pozitif, limitler $+\infty$ verir. II doğru, III yanlış.
- **IV:** $t=2$'de de süreksizlik var, integral ıraksar. Yanlış.
- Cevap C (yalnız I ve II).

### Soru 17: Yay uzunluğu (tahtadan)

- **Soru:** $y=\dfrac12x^2-\dfrac14\ln x$, $1\le x\le2$ eğrisinin uzunluğu nedir?
- $f'(x)=x-\dfrac{1}{4x}$.
- $1+[f'(x)]^2=1+x^2-\dfrac12+\dfrac{1}{16x^2}=x^2+\dfrac12+\dfrac{1}{16x^2}=\left(x+\dfrac{1}{4x}\right)^2$.
- Tam kare olduğunu görmek sorunun anahtarı.

$$L=\int_1^2\left(x+\frac{1}{4x}\right)dx=\left[\frac{x^2}{2}+\frac14\ln x\right]_1^2=\frac32+\frac14\ln2$$

- Cevap A.

### Soru 18: Trigonometrik dönüşüm

- **Soru:** $\displaystyle\int\frac{x^2}{\sqrt{4+x^2}}\,dx$ integraline uygun trigonometrik dönüşüm uygulanınca hangi integral elde edilir?
- $a^2+x^2$ biçimi $\arctan$'ın türeviyle ilişkilidir. Uygun dönüşüm $x=2\tan\theta$.
  - Bir öğrenci $\sec$ dönüşümünü önerdi. Hoca: $\sec$ dönüşümü $x^2-a^2$ biçimi içindir.
- $dx=2\sec^2\theta\,d\theta$, $\sqrt{4+4\tan^2\theta}=2\sec\theta$.

$$\int\frac{4\tan^2\theta\cdot2\sec^2\theta}{2\sec\theta}\,d\theta=\int4\tan^2\theta\sec\theta\,d\theta$$

- Cevap A.

### Hacim: $y=2x-x^2$ ve $x$ ekseni arasındaki bölge

- Parabolün kökleri $x=0$ ve $x=2$.
- **$y$ ekseni etrafında (kabuk):**

$$V=2\pi\int_0^2x\,(2x-x^2)\,dx=\frac{8\pi}{3}$$

  - Cevap C.
- **Hocanın ek varyasyonları:**
  - $x=-2$ etrafında: $V=2\pi\displaystyle\int_0^2(x+2)(2x-x^2)\,dx$.
  - $x=3$ etrafında: $V=2\pi\displaystyle\int_0^2(3-x)(2x-x^2)\,dx$.
  - $y=-2$ etrafında döndürülseydi pul yöntemi uygun olurdu, çünkü dikey çubuk dönme eksenine dik olur.

### Ekstremum: parçacığın en büyük hızı

- **Soru:** Bir parçacığın hız fonksiyonu $v(t)$ verilmiş. $[0,2]$ aralığında en büyük hız nedir?
- Hoca türevi $v'(t)=\dfrac{(t-1)^2}{t^2+1}$ biçiminde buldu. Bu ifade hiçbir yerde negatif değil.
- $v$ artan bir fonksiyon. En büyük hız aralığın sağ ucunda: $v(2)=2-\ln5$.
- Altyazıya göre fonksiyon büyük olasılıkla $v(t)=t-\ln(t^2+1)$. Sorunun tam metni altyazıda net değil.

### Yeni dönüşüm: $\tan\dfrac{x}{2}=t$

- Olağan yöntemlerle basit bir integrale dönüşmeyen, $\sin x$ ve $\cos x$ içeren kesirler için kullanılır.
- **Formüllerin çıkarılışı:** Dik üçgende açı $x/2$, karşı kenar $t$, komşu kenar $1$, hipotenüs $\sqrt{t^2+1}$.
  - $\sin x=2\sin\dfrac x2\cos\dfrac x2=2\cdot\dfrac{t}{\sqrt{t^2+1}}\cdot\dfrac{1}{\sqrt{t^2+1}}=\dfrac{2t}{1+t^2}$.
  - $\cos x=\cos^2\dfrac x2-\sin^2\dfrac x2=\dfrac{1-t^2}{1+t^2}$.
  - $\tan\dfrac x2=t$ türevlenir: $\left(1+\tan^2\dfrac x2\right)\cdot\dfrac12\,dx=dt\Rightarrow dx=\dfrac{2\,dt}{1+t^2}$.
- Hoca: "Çok aşina olmadığımız bir problemi, çok iyi bilinen bir probleme, rasyonel fonksiyonların integraline dönüştürüyoruz. Yaptığımız her şey zaten bu."

### Örnek A: $\displaystyle\int\frac{dx}{2+\sin x+\cos x}$

- Dönüşüm uygulanınca payda: $\dfrac{2(1+t^2)+2t+1-t^2}{1+t^2}=\dfrac{t^2+2t+3}{1+t^2}$.

$$\int\frac{2\,dt}{t^2+2t+3}=\int\frac{2\,dt}{(t+1)^2+2}=\sqrt2\arctan\frac{t+1}{\sqrt2}+C$$

- Eski değişkene dönüş:

$$\int\frac{dx}{2+\sin x+\cos x}=\sqrt2\arctan\left(\frac{1+\tan\frac x2}{\sqrt2}\right)+C$$

### Örnek B: $\displaystyle\int\frac{dx}{5+3\cos x}$

- Payda: $\dfrac{5(1+t^2)+3(1-t^2)}{1+t^2}=\dfrac{2t^2+8}{1+t^2}$.

$$\int\frac{2\,dt}{2t^2+8}=\int\frac{dt}{t^2+4}=\frac12\arctan\frac t2+C=\frac12\arctan\left(\frac{\tan\frac x2}{2}\right)+C$$

- Hoca önce $2$'ye bölmeyi unuttu, sonra düzeltti: "Yoksa $x/2$ gelir, yanlış olur."

### Ders sonrası notlar

- **Soru 3:** Hoca "Bazen burada değişiklikler olabiliyor, hata olabilir, dikkat edin" dedi. Hesap yapıldığında cevap gerçekten $b=2$ çıkıyor.
- **Soru 8 (L'Hôpital):** Hoca soruyu "daha önce çözdük" diyerek geçti. Soru metni bu özete alınmadı.
- **Soru 10 olasılığı:** Hoca önce "finalde gelme ihtimali %80" dedi. Bir öğrenci bu tipin 2. vizede geldiğini söyleyince tahminini %40-50'ye indirdi.
- **Örnek A:** Altyazıda sonuç "$\frac{2}{\sqrt2}\arctan\left(\frac{1}{\sqrt2}\tan\frac x2\right)$" gibi geçiyor. Bu ifadede $+1$ eksik. Doğrusu yukarıdaki gibi $\dfrac{1+\tan\frac x2}{\sqrt2}$'dir ($\frac{2}{\sqrt2}=\sqrt2$).
- **Hız sorusu:** Hoca türevi "her zaman pozitif" diyor. Doğrusu "negatif değil": $t=1$'de türev $0$ olur. Fonksiyon yine de artandır.
- **Soru 15, IV:** Hoca "$t=2$ yazınca yakınsak olmaz" diyor. Gerekçe: $\displaystyle\lim_{t_1\to2^-}\frac{1}{2-t_1}=+\infty$.
- **Hesaplanan sonuçlar:** $b=2$, $2\pi e^b$, $-\frac{16}{5}$, $\frac{8\pi}{3}$ ve Örnek A'nın sonucu bu özette hesaplandı ya da doğrulandı.
- **Altyazı:** Yaklaşık 00:14:35'te ("ikinci olarak" döngüsü) ve 01:44:36-01:44:55 arasında altyazı anlaşılmıyor. Soru metinleri ekrandaki PDF'ten alındı.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
