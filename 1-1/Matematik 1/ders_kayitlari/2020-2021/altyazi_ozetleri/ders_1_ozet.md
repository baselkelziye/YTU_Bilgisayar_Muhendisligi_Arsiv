# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin tanıtımı: tek değişkenli fonksiyonlar teorisi (single variable functions). Çok değişkenli fonksiyonlar sonraki dönemde.
- Ana başlıklar: fonksiyon, limit, süreklilik (continuity), türev (derivative), integral ve uygulamaları.
- Ana kaynak: Thomas' Calculus. Zorunlu değil; başka kitaplar da kullanılabilir.
- Motivasyon örneği: "başarının matematiksel tanımı" ve türev.
- Fonksiyon tanımı, tanım kümesi (domain), değer kümesi (codomain), görüntü kümesi (range).
- Düşey doğru testi (vertical line test).
- Fonksiyonlarda cebirsel işlemler ve bileşke (composition).
- Simetri: çift fonksiyon (even function) ve tek fonksiyon (odd function).
- Temel fonksiyonlar: polinomlar, rasyonel fonksiyonlar, mutlak değer, trigonometrik fonksiyonlar.
- Birim çember üzerinden trigonometrik fonksiyonların grafikleri.
- Limit kavramı, tablodan limit, cebirsel işlemlerle limit, eşlenik yöntemi (conjugate method).
- Teğet doğrunun eğimini limitle ifade etme.
- Limit kuralları, çelişki yöntemi (proof by contradiction), tek taraflı limitler (one-sided limits).
- Sıkıştırma teoremi (Sandwich / Squeeze Theorem).

## Hocanın Özellikle Vurguladığı Kısımlar

- Formül ezberlemeyin. Her formülün arkasındaki mantığı (philosophy) anlamaya çalışın.
- Limit, süreklilik, türev ve integral boş kavramlar değil. Günlük hayatta ve mühendislik problemlerinde kullanılır.
- $f(a)$ ile $\lim_{x\to a} f(x)$ farklı şeylerdir. Fonksiyon bir noktada tanımsız olsa da o noktada limiti olabilir.
- $\frac{1}{0}=\infty$ gibi bir gösterim yanlıştır. $\frac{1}{0}$ tanımsızdır. Doğrusu limit kavramıyla konuşmaktır.
- Kuralları özdeş (identical) olan iki fonksiyon aynı fonksiyon olmayabilir. Tanım kümeleri farklı olabilir.
- Bileşke $f\circ g$ için $g$'nin görüntü kümesi ile $f$'nin tanım kümesinin kesişimi boş olmamalı.
- Çift/tek fonksiyondan söz etmek için tanım kümesi orijine göre simetrik olmalı.
- Sınavlar büyük olasılıkla çoktan seçmeli (test) olacak. L'Hôpital kuralı serbest olabilir, ama önce L'Hôpital'siz limit hesabı öğrenilmeli.
- Sıkıştırma teoremi ve çelişki yöntemi test sorularında da kullanılabilir. Bu tür soruları atlamayın.

## Kısa Tekrar Notları

- **Fonksiyon:** $D$ kümesindeki her $x$'e tek bir $f(x)$ değeri atayan kural.
  - Bir girdi iki farklı çıktıya gidemez.
  - İki farklı girdi aynı çıktıya gidebilir.
- **Bağımsız değişken:** $x$ (girdi). **Bağımlı değişken:** $y=f(x)$ (çıktı).
- **Grafik:** $\{(x,f(x)) : x\in D\}\subset \mathbb{R}^2$.
- **Düşey doğru testi:** Bir düşey doğru eğriyi iki noktada kesiyorsa eğri $y=f(x)$ biçiminde bir fonksiyonun grafiği değildir.
- **Tanım kümesi grafikten:** Grafiğin yatay eksene dik izdüşümü tanım kümesini verir.
- **Çift fonksiyon:** $f(-x)=f(x)$. Grafik $y$ eksenine göre simetrik. Örnek: $x^2$.
- **Tek fonksiyon:** $f(-x)=-f(x)$. Grafik orijine göre simetrik. Örnek: $x^3$.
- **Periyot:** $f(x+T)=f(x)$ eşitliğini sağlayan en küçük pozitif $T$.
  - $\sin$, $\cos$, $\sec$, $\csc$: periyot $2\pi$.
  - $\tan$, $\cot$: periyot $\pi$.
- **Limit (kaba tanım):** $x$, $a$'ya sağdan ve soldan yaklaşırken $f(x)$ tek ve sonlu bir $L$ değerine yaklaşıyorsa $\lim_{x\to a}f(x)=L$.
- **Limit var olması için:** sağ limit = sol limit.
- **Teğet eğimi:** $m=\lim_{x\to x_0}\frac{f(x)-f(x_0)}{x-x_0}=\lim_{h\to 0}\frac{f(x_0+h)-f(x_0)}{h}$.

## Detaylı Açıklamalar

### Motivasyon: Başarının Matematiksel Tanımı

- Hoca derse bir soruyla başlıyor: "Başarının matematiksel tanımı nedir?"
- Başarı sorumluluğa bağlıdır. Sorumluluğun temel değişkeni zamandır.
- Sorumluluk fonksiyonu: $R=f(t)$. Belli bir zamana kadar yerine getirilen sorumluluk miktarı olarak düşünülebilir.
- **Ortalama başarı:** ortalama hız gibi tanımlanır.

$$\text{ortalama başarı}=\frac{R(t)-R(t_0)}{t-t_0}$$

- **Anlık başarı:** $t\to t_0$ iken bu oranın limiti. Yani sorumluluk fonksiyonunun türevi.
- Türev negatifse birim zamanda düşen sorumluluklar yerine getirilmiyor demektir.
- Bu tanım için limit, süreklilik ve türev kavramları gerekir.

### Fonksiyon, Tanım Kümesi ve Görüntü Kümesi

- $f: D\subset\mathbb{R}\to\mathbb{R}$, $x\mapsto f(x)$.
- **Codomain (değer kümesi):** burada $\mathbb{R}$.
- **Range (görüntü kümesi):** $\{f(x): x\in D\}$. Değer kümesinin alt kümesidir.
- **Örnek 1:** $y=x^2+1$.
  - Tanım kümesi: $\mathbb{R}$ (polinom her yerde tanımlı).
  - Görüntü kümesi: $[1,\infty)$.
- **Örnek 2:** $z=f(t)=\sqrt{4-t^2}$ (üst yarım çember).
  - Gerçel sayılarda tanımlı olması için $4-t^2\ge 0$.
  - $t^2\le 4 \Rightarrow |t|\le 2 \Rightarrow -2\le t\le 2$.
  - Tanım kümesi: $[-2,2]$ (uç noktalar dahil).
  - Görüntü kümesi: $[0,2]$.
- **Örnek 3:** $w=f(u)=\frac{1}{u-1}$ (döndürülmüş hiperbol).
  - Tanım kümesi: $\mathbb{R}\setminus\{1\}$.
  - $u\to 1^+$ iken $\frac{1}{0^+}$ biçimi: değer $+\infty$'a gider.
  - $u\to 1^-$ iken $\frac{1}{0^-}$ biçimi: değer $-\infty$'a gider.
  - $\frac{1}{0^+}$ "sıfıra çok yakın pozitif bir sayıya bölüm" demektir. Bu, $\frac{1}{0}$ yazmaktan daha doğrudur, ama asıl doğrusu limit gösterimidir.

### Düşey Doğru Testi ve Çember Örneği

- $x^2+y^2=1$ çemberi tek başına $y=f(x)$ biçiminde bir fonksiyon değildir. Düşey doğru onu iki noktada keser.
- $y$ çözülürse iki fonksiyon çıkar:
  - $y_+=\sqrt{1-x^2}$: üst yarım çember.
  - $y_-=-\sqrt{1-x^2}$: alt yarım çember.
- $x$ çözülürse:
  - $x_+=\sqrt{1-y^2}$: sağ yarım çember.
  - $x_-=-\sqrt{1-y^2}$: sol yarım çember.
- Bir eğri $y=f(x)$ olmasa da $x=g(y)$ biçiminde bir fonksiyon olabilir. O zaman $y$ bağımsız, $x$ bağımlı değişkendir.
- Eğrinin yerel parçaları fonksiyon grafiği olabilir.

### Cebirsel İşlemler ve Bileşke

- $f+g$, $f-g$, $fg$, $f/g$ tanımlanabilir. Tanım kümeleri farklı olabilir.
  - $f/g$ için $g(x)\neq 0$ olmalı.
- **Bileşke:** $(f\circ g)(x)=f(g(x))$. Önce $g$, sonra $f$ uygulanır.
  - Koşul: $\text{Range}(g)\cap D(f)\neq\emptyset$. Yoksa bileşke tanımlanamaz.
- **Örnek 4:** $f(x)=3x^2-x$, $g(x)=\frac{1}{x}$.
  - $D(f)=\mathbb{R}$, $D(g)=\mathbb{R}\setminus\{0\}$.
  - $f(5p+1)$: $x$ yerine $5p+1$ yazılır.
- **Örnek 5 (tablodan bileşke):** $g(5)=1$, sonra $f(1)=6$. Yani $(f\circ g)(5)=6$.

### Simetri: Çift ve Tek Fonksiyonlar

- **Ön koşul:** $D(f)$ orijine göre simetrik olmalı.
- **Çift fonksiyon:** her $x\in D(f)$ için $f(-x)=f(x)$.
  - Grafik $y$ eksenine göre simetrik.
  - $x^{2n}$ biçimindeki tek terimliler çifttir.
- **Tek fonksiyon:** her $x\in D(f)$ için $f(-x)=-f(x)$.
  - Grafik orijine göre simetrik.
  - $x^{2n+1}$ biçimindeki tek terimliler tektir.
- $x=f(y)$ biçimindeki bir fonksiyonun grafiği $x$ eksenine göre simetrikse o da çift fonksiyondur. Burada $y$ bağımsız değişkendir.
- Bazı fonksiyonlar ne tek ne çifttir.

### Temel Fonksiyonlar

- **Polinom:** $p(x)=a_nx^n+\dots+a_1x+a_0$, $a_n\neq 0$, derece $n$. Tanım kümesi $\mathbb{R}$.
- **Rasyonel fonksiyon:** iki polinomun oranı. Tanım kümesi: paydayı sıfır yapan noktalar hariç $\mathbb{R}$.
- **Özdeş kural, farklı fonksiyon:**
  - $\frac{x^2-5x+6}{x-2}=\frac{(x-2)(x-3)}{x-2}$ ifadesi $x-3$'e özdeştir.
  - Ama $\frac{x^2-5x+6}{x-2}$ $x=2$'de tanımsız, $x-3$ ise her yerde tanımlı.
  - Kuralları özdeş, fonksiyonlar aynı değil.
- **Mutlak değer:**

$$|f(x)|=\begin{cases} f(x), & f(x)\ge 0\\ -f(x), & f(x)<0\end{cases}$$

### Trigonometrik Fonksiyonlar (Birim Çember ile)

- Yatay eksen kosinüs ekseni, düşey eksen sinüs eksenidir.
- $(1,0)$ noktasından geçen düşey teğet doğru tanjant eksenidir. "Tanjant" adı bu teğet doğrudan gelir.
- $(0,1)$ noktasından geçen yatay teğet doğru kotanjant eksenidir.
- Orijin etrafında dönen bir çubuk ve $\theta$ açısı düşünülür:
  - Çubuğun uç noktasının kosinüs eksenine dik izdüşümü: $\cos\theta$.
  - Sinüs eksenine dik izdüşümü: $\sin\theta$.
  - Çubuğun uzantısının tanjant eksenini kestiği nokta: $\tan\theta$.
  - Kotanjant eksenini kestiği nokta: $\cot\theta$.
- Benzer üçgenlerden:
  - $\tan\theta=\frac{\sin\theta}{\cos\theta}$, $\cos\theta\neq 0$.
  - $\cot\theta=\frac{\cos\theta}{\sin\theta}$, $\sin\theta\neq 0$.
  - $\csc\theta=\frac{1}{\sin\theta}$, $\sec\theta=\frac{1}{\cos\theta}$.
- Pisagor özdeşliği: $\sin^2\theta+\cos^2\theta=1$.
- **Toplam formülleri** (ödev: nasıl elde edildiğini inceleyin):
  - $\sin(a+b)=\sin a\cos b+\cos a\sin b$.
  - $\cos(a+b)=\cos a\cos b-\sin a\sin b$.
  - $\cos$ çift, $\sin$ tek olduğu için $b$ yerine $-b$ yazınca:
    - $\sin(a-b)=\sin a\cos b-\cos a\sin b$.
    - $\cos(a-b)=\cos a\cos b+\sin a\sin b$.
  - Yalnız iki ana formülü bilmek yeter, gerisi çıkarılır.
- **Yarım açı / çift açı:**
  - $\sin 2\theta=2\sin\theta\cos\theta$.
  - $\cos 2\theta=\cos^2\theta-\sin^2\theta$.
  - $\cos^2\theta=\frac{1+\cos 2\theta}{2}$, $\sin^2\theta=\frac{1-\cos 2\theta}{2}$.
  - Bu özdeşlikler integralde çok önemlidir. Kuvvet 2'den 1'e iner.

### Trigonometrik Grafikler

- **$\sin$:** $\theta=0$'da 0, $\pi/4$'te $\frac{\sqrt2}{2}$, $\pi/2$'de 1, $\pi$'de 0, $3\pi/2$'de $-1$. Periyodik dalga.
  - Tanım kümesi $\mathbb{R}$, görüntü kümesi $[-1,1]$.
- **$\csc=\frac{1}{\sin}$:** $\sin$'in sıfır olduğu yerlerde ($k\pi$) tanımsız. Bu noktalarda düşey asimptot var.
  - $\pi$'ye soldan yaklaşırken $\frac{1}{0^+}\to+\infty$.
- **$\cos$:** $\cos 0=1$, $\cos\frac{\pi}{2}=0$, $\cos\pi=-1$.
- **$\sec=\frac{1}{\cos}$:** $\frac{\pi}{2}$ ve $\frac{3\pi}{2}$'de tanımsız.
  - $\lim_{x\to\pi/2^-}\frac{1}{\cos x}=+\infty$.
  - $\sec\pi=-1$.
- **$\tan$:** $\theta\to\frac{\pi}{2}^-$ iken çubuğun uzantısı pozitif tanjant eksenini giderek yukarıda keser: $+\infty$. Düşey asimptotlar var. Periyot $\pi$.
  - İşaretler $\frac{\sin\theta}{\cos\theta}$ üzerinden de belirlenebilir.
- **$\cot$:** tanjant grafiği "havada döndürülerek" elde edilir.
- $\sin$ grafiği bilinirse $\csc$, $\cos$ grafiği bilinirse $\sec$ grafiği hemen çıkarılır.

### Limit Kavramı

- Bir grafik üzerinde üç durum:
  - **$x=1$:** $f(1)=2$ ve $\lim_{x\to1}f(x)=2$. Değer ile limit aynı.
  - **$x=2$:** $f(2)=5$ ama $\lim_{x\to2}f(x)=3$. Değer ile limit farklı.
  - **$x=3$:** $f(3)$ tanımsız ama $\lim_{x\to3}f(x)=4$. Limit var.
- Yani "x'ler 3'e yaklaşırken $f(x)$ nereye yaklaşır?" sorusunun tek ve sonlu bir cevabı varsa limit vardır.

### Tablodan ve Cebirsel İşlemlerle Limit

- **Örnek 6:** $\lim_{x\to1}\frac{\sqrt x-1}{x-1}$.
  - Tabloda $x=0{,}9;\ 0{,}99;\ 0{,}999$ ve sağdan değerler alınınca sonuç $0{,}5$'e yaklaşır.
  - $x=1$ doğrudan yazılırsa $\frac00$ belirsizliği çıkar.
  - Sadeleştirme: $x-1=(\sqrt x-1)(\sqrt x+1)$.

$$\lim_{x\to1}\frac{\sqrt x-1}{(\sqrt x-1)(\sqrt x+1)}=\lim_{x\to1}\frac{1}{\sqrt x+1}=\frac12$$

  - Fonksiyon $x=1$'de tanımsız, ama limiti $\frac12$.
  - Bilgisayarda bir döngüyle $x$'i 1'e yeterince yakın seçerek de yaklaşık değer bulunabilir.
- **Örnek 7 (eşlenik yöntemi, L'Hôpital kullanmadan):** $\lim_{x\to5}\frac{4-\sqrt{3x+1}}{x^2-7x+10}$.
  - $x=5$ yazınca $\frac00$.
  - Pay ve payda eşlenik $4+\sqrt{3x+1}$ ile çarpılır.

$$\lim_{x\to5}\frac{16-(3x+1)}{(x^2-7x+10)(4+\sqrt{3x+1})}=\lim_{x\to5}\frac{-3(x-5)}{(x-2)(x-5)(4+\sqrt{3x+1})}$$

$$=\frac{-3}{3\cdot 8}=-\frac18$$

  - Eşlenikle çarpınca kural değişir ama ifade öncekine özdeştir.

### Teğet Doğrunun Eğimi

- **Örnek 8:** $(-3,-9)$ noktasında grafiğe teğet doğrunun eğimi $m$'yi limit olarak yazın (hesaplamayın).

$$m=\lim_{x\to-3}\frac{f(x)-f(-3)}{x-(-3)}$$

- Genel olarak $\frac{\Delta f}{\Delta x}=\frac{f(x)-f(x_0)}{x-x_0}$, $[x_0,x]$ aralığında ortalama değişim hızıdır.
- $x\to x_0$ iken teğet doğrunun eğimi elde edilir.
- $h=x-x_0$ yazılırsa denk limit: $\lim_{h\to0}\frac{f(x_0+h)-f(x_0)}{h}$.

### Limit Kuralları

- $\lim_{x\to a}f(x)=L$ ve $\lim_{x\to a}g(x)=M$ var olsun. Sonra:
  - Toplam/fark: $\lim(f\pm g)=L\pm M$.
  - Sabitle çarpım: $\lim cf=cL$.
  - Çarpım: $\lim fg=LM$.
  - Bölüm: $\lim\frac fg=\frac LM$, $M\neq0$.
  - Kuvvet: $\lim f^n=L^n$, $n$ pozitif tam sayı.
  - Kök: $\lim\sqrt[n]{f}=\sqrt[n]{L}$; çift $n$ için $f\ge 0$ varsayılır.
- Bu dağıtma işlemleri ancak her terimin limiti varsa yapılabilir.

### Çelişki Yöntemi Örneği

- **Örnek 9:** $\lim_{x\to c}f(x)\neq0$ ve $\lim_{x\to c}g(x)=0$ ise $\lim_{x\to c}\frac{f(x)}{g(x)}$ yoktur. Gösterin.
  - Hipotez $p$, amaç $q$: $p\Rightarrow q$.
  - Amacın değilini kabul edin: limit var olsun ve $L$ olsun.
  - Çarpım kuralıyla:

$$\lim_{x\to c}f(x)=\lim_{x\to c}\frac{f(x)}{g(x)}\cdot g(x)=L\cdot 0=0$$

  - Bu, $\lim f(x)\neq0$ hipoteziyle çelişir.
  - Kabul yanlıştır. Kabulün değili doğrudur: limit yoktur.
- Mantık: bir önermenin değilinin değili kendisidir.

### Tek Taraflı Limitler

- $\lim_{x\to a^+}f(x)=L_1$ (sağ limit), $\lim_{x\to a^-}f(x)=L_2$ (sol limit).
- Parçalı fonksiyonlarda bunlar farklı olabilir.
- Limit var $\iff$ $L_1=L_2$.
- **Örnek 10:** Grafikte $x\to2^+$ iken $g(x)\to1$, $x\to2^-$ iken $g(x)\to4$. Farklı olduğu için $x=2$'de limit yok.
- **Örnek 11:** $x\to100^+$ için kök içeren bir ifade. Eşlenikle çarpılıp sadeleşince $\sqrt x+10$ kalıyor. Sonrası öğrenciye bırakılıyor. Tam ifade altyazıda net değil.

### Sıkıştırma (Sandwich) Teoremi

- **Teorem:** $a$ civarındaki $x$ değerleri için $f(x)\le g(x)\le h(x)$ olsun.
  - $\lim_{x\to a}f(x)=\lim_{x\to a}h(x)=L$ ise $\lim_{x\to a}g(x)=L$.
  - $a$ sonlu olmak zorunda değil; $\pm\infty$ olabilir.
- **Örnek 12:** $\lim_{x\to\infty}\frac{\sin x}{x}$.
  - $-1\le\sin x\le1$. $x>0$ için $x$'e bölünür: $-\frac1x\le\frac{\sin x}{x}\le\frac1x$.
  - İki sınır da 0'a gider. Sonuç 0.
  - Sınırlı ifade bölü sınırsız ifade sıfıra gider.
- **Örnek 13:** $\lim_{x\to0}\sin x=0$.
  - $-|x|\le\sin x\le|x|$.
  - $x\to0$ iken iki sınır da 0. Sonuç 0.
- **Örnek 14:** $\lim_{x\to0}\cos x=1$.
  - $0\le1-\cos x\le|x|$.
  - İki sınır da 0'a gider. Yani $\lim(1-\cos x)=0$.
  - Limit farka dağıtılırsa $1-\lim\cos x=0$, yani $\lim_{x\to0}\cos x=1$.

### Ders sonrası notlar

- **Görüntü kümesi sürçmesi:** Hoca $f(t)=\sqrt{4-t^2}$ için görüntü kümesini sözlü olarak "sıfırdan üçe" diyor. Doğrusu $[0,2]$. En büyük değer $t=0$'da $\sqrt4=2$.
- **$f(2)$ düzeltmesi:** Hoca önce $f(2)$'nin tanımsız olduğunu söylüyor, sonra kendisi düzeltiyor: grafikte $f(2)=5$ tanımlı, ama limit 3.
- **Not dağılımı:** Altyazıda "vize %30, final 30-70%" diye karışık geçiyor. Büyük olasılıkla vize %30, final %70.
- **Sınav tarihleri:** henüz belli değil.
- **Bütünleme (make-up exam):** final notuyla geçemeyenler için.
- Ders kaydı Zoom'da otomatik alınıyor. Hoca kaydın paylaşılmasına itiraz etmiyor.
- Dersin sonunda "yarın soru çözeceğiz" duyurusu var.
- Hoca ders dosyalarının Avesis sayfasında olduğunu ve şifreyle açıldığını söylüyor.

---

İsterseniz bu özeti NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
