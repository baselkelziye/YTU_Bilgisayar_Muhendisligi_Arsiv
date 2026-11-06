# Ders 25 Çalışma Özeti

## Genel Konular

- Ders 22 Mayıs 2023 Pazartesi günü yapıldı. Konular bitti, final hazırlığı için çıkmış ve çıkabilecek sorular çözülüyor.
- Kutupsal koordinatlar (polar coordinates):
  - Kutupsal denklemi kartezyen denkleme çevirme.
  - Kutupsal noktayı kartezyen koordinata çevirme.
  - Bölgeyi tanıyan eşitsizlikler.
  - İki eğri arasında kalan alanı veren integrali yazma (çember, kardiyoid (cardioid), doğru).
- Seriler (series) tekrarı:
  - Geometrik seri, $p$-serisi.
  - Rasyonel genel terimli serilerde derece farkı kuralı.
  - Alterne seri (alternating series), mutlak ve şartlı yakınsaklık.
  - Limit karşılaştırma, mukayese, integral, oran ve kök testleri.
- Kuvvet serileri (power series):
  - Yakınsaklık aralığı ve uç noktalar.
  - Geometrik kuvvet serisinin toplam fonksiyonu.
  - Bilinen serilerden türev ve çarpma ile yeni seri elde etme.
  - $\ln(1-x)$ açılımı ile integral hesabı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Alan sorularında genellikle "integrali hesaplayınız" değil, "alanı veren integral hangisidir" diye soruluyor. Sınırları ve hangi eğrinin dışta olduğunu doğru yazmak yeterli.
- Önce iki eğriyi kesiştir, kesim açısını bul. Sonra bölgeyi simetriyle ikiye böl: yarısını hesapla, 2 ile çarp.
- Alan formülündeki $\frac12$ çarpanını unutmayın: $A=\frac12\int r^2\,d\theta$.
- Şıklar arasındaki fark bazen yalnız bir uç noktanın dahil olup olmamasıdır ("küçük" ile "küçük eşit"). Çizgili sınır dahil değil demektir.
- Rasyonel genel terimli serilerde pratik kural (limit karşılaştırmaya dayanır):
  - Paydanın derecesi paydan 2 veya daha fazla büyükse seri yakınsak.
  - Fark 1 veya daha az ise (dereceler eşit dahil) seri ıraksak.
- Genel terimin limiti sıfırdan farklıysa seri hemen ıraksaktır.
- "Bol bol çözün. Doğru ile yanlış arasında ufak bir nüans var, onu görmek için çözmek lazım."

## Kısa Tekrar Notları

- Dönüşüm: $x=r\cos\theta$, $y=r\sin\theta$, $r^2=x^2+y^2$.
- $r=2a\cos\theta$: merkezi $(a,0)$, yarıçapı $a$ olan çember. $r=2a\sin\theta$: merkezi $(0,a)$ olan çember.
- $r=1\pm\cos\theta$, $r=1\pm\sin\theta$: kardiyoid.
- $r=a\sec\theta \iff x=a$ (dikey doğru).
- Geometrik seri $\sum ar^n$: $|r|<1$ ise yakınsak, toplam $\frac{a}{1-r}$ (a: ilk terim).
- $p$-serisi $\sum\frac1{n^p}$: $p>1$ yakınsak, $p\le1$ ıraksak.
- $\sum(-1)^n\frac1{n^p}$: $p>1$ mutlak yakınsak, $0<p\le1$ şartlı yakınsak.
- $\cos n\pi=(-1)^n$.
- $\lim_{n\to\infty}\left(1+\frac{k}{n}\right)^n=e^k$.
- $\frac1{1-x}=\sum_{n=0}^\infty x^n$, $|x|<1$.
- $\ln(1+x)=x-\frac{x^2}{2}+\frac{x^3}{3}-\cdots$, $-1<x\le1$.

## Detaylı Açıklamalar

### Kutupsal Denklem ve Noktalar

**Örnek 1 (kutupsal denklem).** $r=\dfrac{4}{2\cos\theta-\sin\theta}$ neyi belirtir?

- Paydayı karşıya at: $2r\cos\theta-r\sin\theta=4$.
- $r\cos\theta=x$, $r\sin\theta=y$ yaz: $2x-y=4$.
- Bu bir doğrudur. Cevap: "doğru belirtir".
- Karşılaştırma için:
  - Çember: $x^2+y^2=a^2$.
  - Kardiyoid: $r=a(1\pm\cos\theta)$.
  - Parabol: $y=ax^2+\dots$

**Örnek 2 (noktanın kartezyen koordinatı).** $(r,\theta)=\left(-3,\frac{5\pi}{6}\right)$.

- $\frac{5\pi}{6}=150^\circ$. $\cos150^\circ=-\frac{\sqrt3}{2}$, $\sin150^\circ=\frac12$.
- $x=r\cos\theta=-3\cdot\left(-\frac{\sqrt3}{2}\right)=\frac{3\sqrt3}{2}$.
- $y=r\sin\theta=-3\cdot\frac12=-\frac32$.
- Nokta: $\left(\frac{3\sqrt3}{2},-\frac32\right)$. Şıklarda $+\frac32$ çeldiricisi var.

**Örnek 3 (bölge eşitsizliği).** Şıklar $-\frac\pi3\le\theta\le-\frac\pi6$, $-3\le r<2$ gibi aralıklarla verilmiş.

- İki şık yalnız $r=2$ sınırının dahil olup olmamasıyla ayrılıyor.
- Şekilde $r=2$ sınırı kesikli çizilmişse 2 dahil değildir. Doğru şık $r<2$ olandır.
- Hoca bu soruda birçok öğrencinin şıkları hızlı okuyup yanlış cevap verdiğini söyledi.

### İki Eğri Arasında Kalan Alan

**Genel yöntem:**
- Eğrileri eşitle, kesim açılarını bul.
- Bölgeyi çiz. Hangi açı aralığında hangi eğrinin dışta olduğuna bak.
- Alan $=\frac12\int_\alpha^\beta\left(r_{dış}^2-r_{iç}^2\right)d\theta$. Gerekirse aralığı parçala.
- Simetri varsa yarısını hesapla, 2 ile çarp.

**Örnek 4.** $r=2\cos\theta$ içinde, $r=\sqrt2$ dışında kalan alan.

- Kesişim: $2\cos\theta=\sqrt2 \Rightarrow \theta=\frac\pi4$.
- $x$ eksenine göre simetrik. Üst yarıyı al:

$$\frac A2=\frac12\int_0^{\pi/4}\left[(2\cos\theta)^2-(\sqrt2)^2\right]d\theta$$

- Alanı veren integral: $A=\int_0^{\pi/4}\left(4\cos^2\theta-2\right)d\theta$.
- Değeri: $4\cos^2\theta-2=2\cos2\theta$, $A=\left[\sin2\theta\right]_0^{\pi/4}=1$.

**Örnek 5.** $r=2\cos\theta$ dışında, $r=\sqrt2$ içinde kalan alan.

- Üst yarıda $\theta\in\left[\frac\pi4,\pi\right]$ boyunca çemberin tamamı alınır. Sonra $\left[\frac\pi4,\frac\pi2\right]$ aralığındaki $2\cos\theta$ parçası çıkarılır.

$$A=\int_{\pi/4}^{\pi}2\,d\theta-\int_{\pi/4}^{\pi/2}4\cos^2\theta\,d\theta$$

- Değeri: $\frac{3\pi}{2}-\left(\frac\pi2-1\right)=\pi+1$.

**Örnek 6.** $r=3\cos\theta$ içinde, $r=1+\cos\theta$ (kardiyoid) dışında kalan alan.

- Kardiyoid çizimi:

  | $\theta$ | $0$ | $\pi/2$ | $\pi$ | $3\pi/2$ |
  |---|---|---|---|---|
  | $r=1+\cos\theta$ | 2 | 1 | 0 | 1 |

- Kesişim: $3\cos\theta=1+\cos\theta \Rightarrow \cos\theta=\frac12 \Rightarrow \theta=\frac\pi3$.

$$A=\int_0^{\pi/3}\left[9\cos^2\theta-(1+\cos\theta)^2\right]d\theta$$

- İki kare farkı olarak da yazılabilir: $(3\cos\theta-1-\cos\theta)(3\cos\theta+1+\cos\theta)$. Şıklarda bu düzenlenmiş hâl de çıkabilir.
- Değeri: $\pi$.

**Örnek 7.** $r=3\cos\theta$ dışında, $r=1+\cos\theta$ içinde kalan alan.

$$A=\int_{\pi/3}^{\pi}(1+\cos\theta)^2d\theta-\int_{\pi/3}^{\pi/2}9\cos^2\theta\,d\theta$$

- İlk integral kardiyoidin üst yarısındaki ilgili parçayı verir. İkincisi oraya taşan çember parçasını çıkarır.
- Değeri: $\frac\pi4$.

**Örnek 8.** $r=1-\sin\theta$ içinde, $r=\sin\theta$ dışında kalan alan.

- Kardiyoid $r=1-\sin\theta$: $\theta=0$'da $r=1$, $\theta=\frac\pi2$'de $r=0$, $\theta=\pi$'de $r=1$, $\theta=-\frac\pi2$'de $r=2$.
- $r=\sin\theta$: merkezi $\left(0,\frac12\right)$ olan çember.
- Kesişim: $\sin\theta=\frac12 \Rightarrow \theta=\frac\pi6$ (ve $\frac{5\pi}{6}$).
- Bölge $y$ eksenine göre simetrik. Sağ yarıyı al:

$$A=\int_{-\pi/2}^{\pi/6}(1-\sin\theta)^2d\theta-\int_0^{\pi/6}\sin^2\theta\,d\theta$$

- Değeri: $\frac{11\pi}{12}+\sqrt3$.

**Örnek 9.** Bir kardiyoidin dışında, $r=3\sin\theta$ çemberinin içinde kalan alan.

- Kesim açısı $\frac\pi6$ olarak verildi.

$$A=\int_{\pi/6}^{\pi/2}\left[9\sin^2\theta-(1+\sin\theta)^2\right]d\theta$$

- Değeri: $\pi$.
- Kardiyoidin denklemi altyazıda net değil. Kesim açısının $\frac\pi6$ çıkması $r=1+\sin\theta$ ile uyumlu.

**Örnek 10 (ortak alan).** $r=1-\sin\theta$ ile $r=\sin\theta$ eğrilerinin ortak alanı.

- $\left[0,\frac\pi6\right]$ aralığında çember içte, $\left[\frac\pi6,\frac\pi2\right]$ aralığında kardiyoid içte kalır.

$$A=2\cdot\frac12\left[\int_0^{\pi/6}\sin^2\theta\,d\theta+\int_{\pi/6}^{\pi/2}(1-\sin\theta)^2d\theta\right]$$

- Değeri: $\frac{7\pi}{12}-\sqrt3$.

**Örnek 11 ($r=1$ ve $r=1-\cos\theta$).**

- Kardiyoid $r=1-\cos\theta$: $\theta=0$'da 0, $\frac\pi2$'de 1, $\pi$'de 2. Kesim açısı $\frac\pi2$.
- Ortak alan:

$$A=\int_0^{\pi/2}(1-\cos\theta)^2d\theta+\int_{\pi/2}^{\pi}1\,d\theta=\frac{5\pi}{4}-2$$

- $r=1$ içinde, kardiyoid dışında: $\int_0^{\pi/2}\left[1-(1-\cos\theta)^2\right]d\theta=2-\frac\pi4$.
- $r=1$ dışında, kardiyoid içinde: $\int_{\pi/2}^{\pi}\left[(1-\cos\theta)^2-1\right]d\theta=2+\frac\pi4$.

**Örnek 12 (sınavda çıkmış).** $r=4$, $\theta=\frac\pi2$ ve $r=2\sec\theta$ arasında kalan alan.

- $r=4$: merkezil çember. $\theta=\frac\pi2$: $y$ ekseni. $r=2\sec\theta \iff r\cos\theta=2 \iff x=2$.
- Kesişim: $2\sec\theta=4 \Rightarrow \cos\theta=\frac12 \Rightarrow \theta=\frac\pi3$.
- Hocanın kurduğu integral:

$$\frac A2=\frac12\left[\int_0^{\pi/3}(2\sec\theta)^2d\theta+\int_{\pi/3}^{\pi/2}4^2\,d\theta\right]$$

- Yarım bölgenin alanı: $\frac12\left(4\sqrt3+\frac{8\pi}{3}\right)=2\sqrt3+\frac{4\pi}{3}$. Bu, birinci bölgede $0\le x\le2$ ve çemberin içi olan bölgedir.

**Örnek 13.** $r=2\sin\theta$ dışında, $r=\sqrt2$ içinde kalan alan.

- Kesişim: $2\sin\theta=\sqrt2 \Rightarrow \theta=\frac\pi4$.

$$A=\int_{-\pi/2}^{\pi/4}2\,d\theta-\int_0^{\pi/4}4\sin^2\theta\,d\theta=\pi+1$$

### Seri Soruları

**Pratik kural (rasyonel genel terim).** $a_n=\frac{P(n)}{Q(n)}$ olsun.

- $\deg Q-\deg P\ge2$ ise yakınsak. Örnek: $\frac{\sqrt{n^2+3n+1}}{n^4+\dots}$ için fark 3, yakınsak.
- $\deg Q-\deg P\le1$ ise ıraksak. Örnekler: $\frac{n+1}{n+9}$, $\frac{n^3}{n^4+\dots}$.
- Gerekçe limit karşılaştırma testidir. $\lim\frac{a_n}{b_n}=L$, $0<L<\infty$ ise $\sum a_n$ ile $\sum b_n$ aynı karakterdedir. $b_n$ olarak uygun bir $\frac1{n^p}$ seçilir.

**Örnek 14.** $\sum\pi^{-n}\cos n\pi$.

- $\cos n\pi=(-1)^n$. Genel terim $\left(-\frac1\pi\right)^n$: oranı $-\frac1\pi$ olan geometrik seri, $\left|\frac1\pi\right|<1$ olduğu için yakınsak.
- Hoca cevabı $\frac{\pi}{1+\pi}$ (A şıkkı) olarak verdi. Bu değer seri $n=0$'dan başlıyorsa doğrudur. $n=1$'den başlıyorsa toplam $-\frac{1}{1+\pi}$ olur.

**Örnek 15 (kaç tanesi yakınsak?).**

- $\sum\frac1{n^{3/2}}$: yakınsak.
- $\sum\left(\frac23\right)^n$: yakınsak.
- $\sum\frac1{\sqrt n}$: ıraksak.
- $\sum\frac{2^n}{n^2}$: ıraksak, genel terim sonsuza gider.
- Payda derecesi 5 olan rasyonel terim: yakınsak.
- Harmonik seri: ıraksak.
- Cevap: 3 tane yakınsak.

**Örnek 16.** $\sum\frac{5\cdot4^n+7^n\cos n\pi}{7^n\cdot4^{n+1}}$ (tahta görüntüsünden).

- Ayır: $\sum\frac{5}{4\cdot7^n}+\sum\frac{(-1)^n}{4^{n+1}}$.
- Birinci seri: $\frac54\cdot\frac{1/7}{1-1/7}=\frac{5}{24}$.
- İkinci seri: ilk terim $-\frac1{16}$, oran $-\frac14$. Toplam $\frac{-1/16}{1+1/4}=-\frac1{20}$.
- Sonuç: $\frac5{24}-\frac1{20}=\frac{19}{120}$.

**Örnek 17.** $\sum\frac1{(\ln2)^n}$: oran $\frac1{\ln2}>1$, çünkü $\ln2<1$. Seri ıraksak.

**Örnek 18.** $\sum\frac{2n+1}{3+4n}$ ile aynı karakterde olan seri.

- Limit $\frac12\neq0$, seri ıraksak.
- Şıklardan yalnız $\sum\left(\frac52\right)^n$ ıraksak. Cevap C.

**Örnek 19 (ıraksak olanları say).** $\frac{\pi^n}{e^{n-1}}$ ($\frac\pi e>1$), derece farkı 1 olan rasyonel terimler ve harmonik seri ıraksak. Toplam 4 tane.

**Örnek 20 (integral testi).** $\sum\frac{1}{n\left(1+(\ln n)^2\right)}$.

- $f(x)=\frac{1}{x(1+\ln^2x)}$ pozitif ve azalan. $u=\ln x$ dönüşümü ile $\int\frac{du}{1+u^2}=\arctan u$ olur.
- İntegral $\frac\pi2$'ye yakınsar. Seri yakınsak.

**Örnek 21 (mukayese).** $\sum\frac1{n+2^n}$.

- $\frac1{n+2^n}<\frac1{2^n}$ ve $\sum\frac1{2^n}$ yakınsak. Seri yakınsak.
- $\frac1n$ ile karşılaştırma işe yaramaz: büyük seri ıraksaksa küçük hakkında bir şey söylenemez.

**Örnek 22.** $\sum\frac{2+\sin n^2}{1+n^2}$: pay en fazla 3. $\frac3{n^2}$ ile mukayese edilir, seri yakınsak.

**Örnek 23 (alterne seri).** $\sum(-1)^n\frac{n+1}{n+4}$.

- Terimler $\frac25$, $\frac36$, ... diye artıyor, limit 1.
- Leibniz testinin şartları ($a_n$ azalan ve $a_n\to0$) sağlanmıyor. Genel terim sıfıra gitmediği için seri ıraksak.

**Örnek 24 (kök testi).** $\sum\frac{n}{e^n}$: $\sqrt[n]{a_n}=\frac{\sqrt[n]{n}}{e}\to\frac1e<1$. Mutlak yakınsak.

**Örnek 25.** $\sum(-1)^n\frac{\cos n}{n^3}$ türü seri.

- $\left|\frac{\cos n}{n^3}\right|\le\frac1{n^3}$ ve $p=3>1$.
- Mutlak değerler serisi yakınsak, seri mutlak yakınsak.

### Kuvvet Serileri

**Örnek 26.** Oran testinde $\lim\left|\frac{a_{n+1}}{a_n}\right|=\lim\frac{\sqrt{x}}{n+3}=0$ çıkıyor. Limit $x$'ten bağımsız olarak $0<1$ olduğundan seri her $x$ için yakınsar. Yakınsaklık aralığı $(-\infty,\infty)$.

**Örnek 27 (doğru/yanlış).** Oran testinden $0<x<2$ aralığında mutlak yakınsaklık bulundu. Uçlar ayrıca denendi.

- Hoca iki uçta da şartlı yakınsaklık buldu.
- Doğru ifadeler: yakınsaklık aralığı $0$-$2$; $x=4$ için seri ıraksak; $(0,2)$'de mutlak yakınsak.
- Yanlış ifade: "$x=0$'da mutlak yakınsak".
- Serinin kendisi altyazıda geçmiyor.

**Örnek 28.** Faktöriyelli bir kuvvet serisinde oran testi limiti sonsuz çıkıyor. Seri yalnız merkezde ($x=2$) yakınsar.

**Örnek 29.** $\sum_{n=0}^\infty\frac{(x+1)^{n+1}}{2^{n+2}}$ serisinin yakınsaklık aralığı ve toplam fonksiyonu (tahta görüntüsünden).

- Açık yaz: $\frac{x+1}{2^2}+\frac{(x+1)^2}{2^3}+\cdots$. Geometrik kuvvet serisi.
- İlk terim $a=\frac{x+1}{4}$, oran $r=\frac{x+1}{2}$.
- $|r|<1 \iff |x+1|<2 \iff -3<x<1$.
- Toplam: $\frac{a}{1-r}=\frac{(x+1)/4}{(1-x)/2}=\frac{x+1}{2-2x}$.
- Cevap C. Uçlarda terimler sıfıra gitmez, uçlar dahil değil.

**Örnek 30.** $f(x)=\frac{x}{1+x^2}$ kuvvet serisi.

- $\frac1{1-u}=\sum u^n$'de $u=-x^2$ yaz: $\frac1{1+x^2}=\sum(-1)^nx^{2n}$.
- $x$ ile çarp: $\frac{x}{1+x^2}=\sum_{n=0}^\infty(-1)^nx^{2n+1}$, $|x|<1$.

**Örnek 31.** $\frac{x^2}{(1-x^2)^2}$ kuvvet serisi.

- $\frac1{1-x^2}=\sum x^{2n}$. Türev al: $\frac{2x}{(1-x^2)^2}=\sum2nx^{2n-1}$.
- $\frac x2$ ile çarp: $\frac{x^2}{(1-x^2)^2}=\sum_{n=1}^\infty nx^{2n}$, $|x|<1$.

**Örnek 32.** $\sum\frac{n+2}{3^{n+1}}$ toplamı.

- $\frac13$ yerine $x$ koyup kuvvet serisi gibi düşünülür: $\sum nx^n=\frac{x}{(1-x)^2}$ ve $\sum x^n=\frac1{1-x}$ kullanılır.
- Toplama indisinin başlangıcı altyazıda net değil. $n=0$'dan başlıyorsa toplam $\frac54$.

**Örnek 33.** $\int_0^{1/2}\frac{\ln(1-x)}{x}dx$.

- $\ln(1+x)=x-\frac{x^2}{2}+\frac{x^3}{3}-\cdots$ açılımında $x$ yerine $-x$ yaz: $\ln(1-x)=-x-\frac{x^2}{2}-\frac{x^3}{3}-\cdots$.
- $x$'e böl: $\frac{\ln(1-x)}{x}=-1-\frac x2-\frac{x^2}{3}-\cdots$.
- Terim terim integral al:

$$\int_0^{1/2}\frac{\ln(1-x)}{x}dx=-\left(\frac12+\frac{1}{2^2\cdot4}+\frac{1}{3^2\cdot8}+\cdots\right)=-\sum_{n=1}^\infty\frac{1}{n^2\,2^n}$$

- Sayısal değeri yaklaşık $-0{,}582$.

### Ders sonrası notlar

- Örnek 2: hoca $y$ koordinatını anlatırken işareti karıştırdı. Doğrusu $y=-\frac32$. Şıklardaki $+\frac32$ çeldiricidir.
- Örnek 14: hocanın verdiği $\frac\pi{1+\pi}$ yalnız $n=0$'dan başlayan seri için doğrudur. $n=1$'den başlıyorsa sonuç $-\frac1{1+\pi}$ olur.
- Örnek 16: altyazıda sonuç "9 bölü 120" gibi geçiyor. Tahtadaki ve hesaplanan doğru sonuç $\frac{19}{120}$.
- Örnek 23: hoca önce "şartlı" dedi, sonra limiti 1 bulup ıraksak dedi. Doğru sonuç ıraksaktır.
- Alan sorularında derste yalnız integraller kuruldu. Bu özetteki sayısal değerleri ben hesapladım.
- 00:32-00:45 ve 01:14-01:24 arasında mola var.

İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
