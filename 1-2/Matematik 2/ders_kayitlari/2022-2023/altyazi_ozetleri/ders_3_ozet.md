# Ders 3 Çalışma Özeti

## Genel Konular

- Geçen haftanın testlerinin kısa tekrarı: integral, karşılaştırma, limit karşılaştırma, oran ve kök testleri.
- Gabriel borusu paradoksu: alanı sonsuz, hacmi sonlu bölge.
- Alterne seriler (alternating series) ve Leibniz testi.
- Mutlak yakınsaklık (absolute convergence) ve şartlı yakınsaklık (conditional convergence).
- Seri testlerinin özeti: hangi durumda hangi test kullanılır.
- Kuvvet serileri (power series): yakınsaklık merkezi, yakınsaklık yarıçapı ve yakınsaklık aralığı.
- Kuvvet serileriyle işlemler: toplama, çarpma, sabitle çarpma.
- $\dfrac1{1-x}$ açılımı ve ondan türetilen seriler.
- Terim terim türev ve integral alma.

## Hocanın Özellikle Vurguladığı Kısımlar

- $\dfrac{1}{1-x}=\sum_{n=0}^\infty x^n$ ($|x|<1$) açılımı "dört yıldızlı". En çok kullanılan açılım bu.
- Kuvvet serisinde önce oran testiyle açık aralık bulunur. **Uç noktalar ayrıca denenir.** Uçlarda seri yakınsak da olabilir, ıraksak da.
- Sınavda şıklar bazen "yanlış olanı bulun" ya da tümleyen aralığı ("ıraksak olduğu aralık") soracak şekilde ters kurulur. Olaya hakim olmak gerekir.
- Bilinen bir seriden türev ya da integralle yeni seriler elde edilir. Bu yolla integrali alınamayan fonksiyonlar da seriyle işlenebilir.
- Zor iş, zamanında yapılmayan kolay işlerin toplamıdır. Her hafta düzenli soru çözülmeli.
- Kaynak: herhangi bir kalkülüs kitabı. Dersin kitabında soru az olduğu için bol soru içeren kaynaklardan da çalışılmalı. Hoca ilerde not paylaşacak.

## Kısa Tekrar Notları

- **Leibniz (alterne seri) testi:** $\sum(-1)^n b_n$ için üç koşul:
  - $b_n>0$
  - $b_{n+1}\le b_n$ (monoton azalan)
  - $\lim b_n=0$
  - Üçü sağlanırsa seri yakınsaktır.
- **Mutlak yakınsak:** $\sum|a_n|$ yakınsak.
- **Şartlı yakınsak:** $\sum a_n$ yakınsak ama $\sum|a_n|$ ıraksak.
- Örnekler:
  - $\sum\dfrac{(-1)^n}{n}$ şartlı yakınsaktır.
  - $\sum\dfrac{(-1)^n}{n^2}$ mutlak yakınsaktır.
- **Kuvvet serisi:** $\sum_{n=0}^\infty a_n(x-c)^n$. Merkez $c$, yarıçap $R$.
  - $|x-c|<R$ ise mutlak yakınsak.
  - $|x-c|>R$ ise ıraksak.
  - $x=c\pm R$ uç noktaları ayrıca denenir.
- Üç olasılık:
  - Seri yalnız $x=c$'de yakınsar ($R=0$).
  - Seri her $x$ için yakınsar ($R=\infty$).
  - Seri $|x-c|<R$ için yakınsar.
- **Temel açılımlar** ($|x|<1$):
  - $\dfrac1{1-x}=\sum x^n$
  - $\dfrac1{1+x}=\sum(-1)^nx^n$
  - $\dfrac1{1+x^2}=\sum(-1)^nx^{2n}$
  - $\dfrac1{(1-x)^2}=\sum_{n\ge1} nx^{n-1}$
  - $\ln(1+x)=\sum(-1)^n\dfrac{x^{n+1}}{n+1}$
  - $\arctan x=\sum(-1)^n\dfrac{x^{2n+1}}{2n+1}$
- Terim terim türev ve integral alınınca yakınsaklık yarıçapı değişmez.

## Detaylı Açıklamalar

### Geçen dersin kısa tekrarı

- **İntegral testi:** $a_n=f(n)$, $f$ pozitif, sürekli ve azalan ise $\sum a_n$ ile $\int_1^\infty f(x)\,dx$ aynı karakterdedir. Toplam integralin değerine eşit değildir.
- **Karşılaştırma testi:**
  - $0\le a_n\le b_n$ ve $\sum b_n$ yakınsak ise $\sum a_n$ yakınsak.
  - $\sum a_n$ ıraksak ise $\sum b_n$ ıraksak.
- **Örnek 1:** $\sum\dfrac{1}{n^2+1}$, $\sum\frac1{n^2}$ ile karşılaştırılır, yakınsak. Limit karşılaştırmasıyla da $\lim\dfrac{1/(n^2+1)}{1/n^2}=1$ çıkar, yine yakınsak.
- **Oran testi** kuvvet ve faktöriyel içeren terimlerde kullanılır. $L<1$ yakınsak, $L>1$ ıraksak, $L=1$ sonuç yok.
- **Örnek 2 (kök testi):** $\sum\dfrac1{(\ln n)^n}$
  - $\sqrt[n]{a_n}=\dfrac1{\ln n}\to0<1$.
  - Seri yakınsaktır.

### Gabriel borusu paradoksu

- $y=\dfrac1x$ eğrisi altında, $x\ge1$ için kalan bölgeye bakılır.
- **Alan:** $\int_1^\infty\dfrac{dx}x=\lim_{b\to\infty}\ln b=\infty$. Bölgenin alanı yoktur, sonsuzdur.
- **Hacim:** Bölge $x$ ekseni etrafında döndürülür. Disk yöntemi: $V=\pi\int_1^\infty\dfrac{dx}{x^2}=\pi\left[-\dfrac1x\right]_1^\infty=\pi$.
- Paradoks: alanı sonsuz olan bölgenin döndürülmesiyle oluşan cismin hacmi sonludur.

### Alterne seriler ve Leibniz testi

- Ardışık terimleri zıt işaretli seriye alterne seri denir: $a_1-a_2+a_3-\dots$

**Leibniz teoremi:** $b_n>0$, $b_{n+1}\le b_n$ ve $\lim b_n=0$ ise $\sum(-1)^nb_n$ yakınsaktır.

**Örnek 3:** $\sum\dfrac{(-1)^{n-1}}{n^2}$

- $b_n=\dfrac1{n^2}>0$.
- $b_n$ azalandır.
- $\lim b_n=0$.
- Üç koşul sağlanır, seri yakınsaktır.
- Serinin ifadesi altyazıda tam net değil.

**Örnek 4:** $\sum\dfrac1n$ ve $\sum\dfrac{(-1)^n}{n}$

- $\sum\frac1n$ harmonik seridir, ıraksaktır.
- $\sum\dfrac{(-1)^n}n$ alterne seridir:
  - $b_n=\frac1n\to0$.
  - $n<n+1$ olduğundan $\dfrac1{n+1}<\dfrac1n$, yani $b_n$ azalan.
  - Leibniz testinden yakınsaktır.
- Sonuç: harmonik seri ıraksak, ama işaretleri değiştirilmiş hali yakınsak.

### Mutlak ve şartlı yakınsaklık

- $\sum|a_n|$ yakınsak ise seri mutlak yakınsaktır.
- $\sum a_n$ yakınsak, $\sum|a_n|$ ıraksak ise seri şartlı yakınsaktır.

**Örnekler**

- **Örnek 5:** $\sum\dfrac{(-1)^n}{n}$
  - Leibniz testinden yakınsak.
  - Mutlak değeri $\sum\frac1n$, ıraksak.
  - Seri şartlı yakınsaktır.
- **Örnek 6:** $\sum\dfrac{(-1)^n}{n^2}$
  - Leibniz testinden yakınsak.
  - Mutlak değeri $\sum\frac1{n^2}$ ($p=2>1$), yakınsak.
  - Seri mutlak yakınsaktır.
- **Örnek 7 (alterne harmonik seri):** $\sum\dfrac{(-1)^{n+1}}{n}$. Mutlak değeri harmonik seri olduğundan şartlı yakınsaktır.
- **Örnek 8 (sınav sorusu):** $\sum\dfrac{n\cos(n\pi)}{2^n}$
  - $\cos(n\pi)=(-1)^n$ olduğu fark edilir. $n=1$ için $-1$, $n=2$ için $1$.
  - Seri $\sum(-1)^n\dfrac{n}{2^n}$ biçiminde alterne seridir.
  - Mutlak değer serisine oran testi uygulanır: $\dfrac{(n+1)/2^{n+1}}{n/2^n}=\dfrac{n+1}{2n}\to\dfrac12<1$.
  - Mutlak değer serisi yakınsak, seri mutlak yakınsaktır.
- **Örnek 9:** $\sum\dfrac{(-1)^n}{\ln n}$
  - Leibniz testinden yakınsak.
  - $\dfrac1{\ln n}>\dfrac1n$ olduğundan mutlak değer serisi ıraksak.
  - Seri şartlı yakınsaktır.

### Seri testlerinin özeti

1. **$n$-inci terim testi:** Önce $\lim a_n$'ye bakılır. $\ne0$ ise seri ıraksaktır.
   - Örnek: $\sum\frac{n}{n+1}$'de $\lim\frac{n}{n+1}=1\ne0$, seri ıraksak.
2. **Geometrik seri:** $|r|<1$ ise yakınsak, $|r|\ge1$ ise ıraksak.
3. **$p$-serisi:** $p>1$ yakınsak, $p\le1$ ıraksak.
4. **Pozitif terimli seriler:** integral, oran, kök, karşılaştırma ve limit karşılaştırma testleri. Karşılaştırmada genellikle geometrik seri ya da $p$-serisi seçilir.
5. **Alterne seriler:** Leibniz testi. Ardından mutlak ya da şartlı yakınsaklık incelenir.

- Terimlerin yeniden düzenlenmesi konusu okunup geçildi.

### Kuvvet serileri

**Tanım**

- $\sum_{n=0}^\infty a_n(x-c)^n = a_0+a_1(x-c)+a_2(x-c)^2+\dots$ serisine $c$ merkezli kuvvet serisi denir.
- $a_n$ sabitleri serinin katsayılarıdır.
- Terimler $x$'e bağlı olduğundan seri bazı $x$ değerleri için yakınsar, bazıları için ıraksar.
- $x=c$ yakınsaklık merkezidir. Bu noktada bütün $x$'li terimler sıfır olur, seri $a_0$'a yakınsar.

**Teorem:** Bir kuvvet serisi için aşağıdakilerden biri doğrudur.

1. Seri yalnız $x=c$'de yakınsar.
2. Seri her $x\in\mathbb{R}$ için yakınsar.
3. Bir $R>0$ sayısı vardır: $|x-c|<R$ için seri yakınsak, $|x-c|>R$ için ıraksaktır. $x=c\pm R$ uç noktalarında yakınsak da olabilir, ıraksak da.

- $R$'ye yakınsaklık yarıçapı denir.
- Yakınsaklık aralığı şu dört biçimden biri olur: $(c-R,c+R)$, $[c-R,c+R)$, $(c-R,c+R]$, $[c-R,c+R]$.

**Yöntem**

1. Oran testi uygulanır: $\lim\left|\dfrac{u_{n+1}}{u_n}\right|<1$ koşulundan mutlak yakınsaklığın açık aralığı bulunur.
2. Uç noktalar ayrı ayrı seride yerine konur ve o serilerin karakteri incelenir.
3. Aralık dışındaki noktalarda seri ıraksaktır.

- Bir öğrenci "neden $1$'den küçük olsun diyoruz" diye sordu. Cevap: oran testinin koşulu bu. Kuvvet serisinde oran $x$'e bağlı çıkar. $<1$ koşulu hangi $x$'ler için yakınsadığını verir.

**Örnek 10:** $\sum\dfrac{x^n}{n!}$

- $\left|\dfrac{x^{n+1}/(n+1)!}{x^n/n!}\right|=\dfrac{|x|}{n+1}\to0<1$.
- Sonuç $x$'e bağlı değil. Seri her $x$ için yakınsaktır ($R=\infty$).
- Oran $|x-1|<2$ gibi bir koşul verseydi, $-1<x<3$ olur ve sonra uçlara bakılırdı.

**Örnek 11:** $\sum n!\,x^n$

- $\left|\dfrac{(n+1)!\,x^{n+1}}{n!\,x^n}\right|=(n+1)|x|$.
- $x\ne0$ ise bu oran $\infty$'a gider.
- Seri yalnız $x=0$'da (merkezde) yakınsar ($R=0$).

**Örnek 12:** $\sum\dfrac{x^n}{n}$

- Oran: $\dfrac{n}{n+1}|x|\to|x|$. $|x|<1$ için mutlak yakınsak.
- $x=-1$: $\sum\dfrac{(-1)^n}{n}$ alterne harmonik seri, şartlı yakınsak.
- $x=1$: $\sum\frac1n$ harmonik seri, ıraksak.
- Yakınsaklık aralığı $[-1,1)$.
- Sınavdaki şıklarda "yakınsaklık aralığı" yerine "ıraksak olduğu küme" sorulmuş olabilir. Cevap $(-\infty,-1)\cup[1,\infty)$ biçiminde gelir.

**Örnek 13:** $\sum\dfrac{x^n}{\sqrt{n^2+3}}$

- Oran $|x|$'e gider, yani $|x|<1$ için mutlak yakınsak.
- $x=1$: $\sum\dfrac1{\sqrt{n^2+3}}$.
  - Limit karşılaştırması $\frac1n$ ile yapılır, $L=1$.
  - Harmonik seri ıraksak, bu seri de ıraksak.
- $x=-1$: $\sum\dfrac{(-1)^n}{\sqrt{n^2+3}}$.
  - Terimler azalıyor ve $0$'a gidiyor. Leibniz testinden yakınsak.
  - Mutlak değeri ıraksak olduğundan şartlı yakınsak.
- Yakınsaklık aralığı $[-1,1)$.

**Örnek 14 (çıkmış sınav sorusu):** $\sum_{n=1}^\infty\dfrac{(2x+5)^n}{(n^2+1)\,3^n}$

- Oran testi: $\dfrac{|2x+5|}{3}\cdot\dfrac{n^2+1}{(n+1)^2+1}\to\dfrac{|2x+5|}3<1$.
  - $|2x+5|<3$, yani $-8<2x<-2$.
  - Açık aralık $-4<x<-1$.
  - Merkez $-\frac52$, yarıçap $\frac32$.
- $x=-1$: $2x+5=3$, seri $\sum\dfrac1{n^2+1}$ olur. $\frac1{n^2}$ ile karşılaştırılır, yakınsak.
- $x=-4$: $2x+5=-3$, seri $\sum\dfrac{(-1)^n}{n^2+1}$ olur. Mutlak değeri yakınsak, seri mutlak yakınsak.
- Yakınsaklık aralığı $[-4,-1]$.

### Kuvvet serileriyle işlemler

- İki kuvvet serisinin ortak yakınsaklık aralığında:
  - Seriler terim terim toplanıp çıkarılabilir.
  - Seriler çarpılabilir.
  - Seri bir sabitle çarpılabilir. Sabitle çarpım aralığı değiştirmez.
- **Çarpma:** $\left(\sum a_nx^n\right)\left(\sum b_nx^n\right)=\sum c_nx^n$, burada $c_n=a_0b_n+a_1b_{n-1}+\dots+a_nb_0$.
- Genel terimi bulmak çoğu zaman zordur. Genellikle ilk birkaç terim hesaplanır.

**Örnek 15:** $\sum x^n=1+x+x^2+\dots$ ile başka bir serinin çarpımı. Hoca ilk 3-4 terimi terim terim çarparak buldu. İkinci serinin ifadesi altyazıda net değil.

### Temel açılım: $\dfrac1{1-x}$

- $\sum_{n=0}^\infty x^n$ ilk terimi $1$, ortak çarpanı $x$ olan geometrik seridir.
- $|x|<1$ için toplamı $\dfrac1{1-x}$'tir.
- $x$ yerine $-x$ yazılırsa: $\dfrac1{1+x}=\sum(-1)^nx^n$, $|x|<1$.
- $x$ yerine $-x^2$ yazılırsa: $\dfrac1{1+x^2}=\sum(-1)^nx^{2n}$, $|x|<1$.

**Örnek 16:** $\sum_{n=0}^\infty 4^nx^{2n}$ serisinin yakınsaklık aralığı ve toplam fonksiyonu

- $4^nx^{2n}=(4x^2)^n$. Yani $\sum x^n$ açılımında $x$ yerine $4x^2$ gelmiş.
- Toplam fonksiyonu: $f(x)=\dfrac1{1-4x^2}$.
- Koşul: $|4x^2|<1$, yani $x^2<\frac14$, yani $-\frac12<x<\frac12$.
- Bu aralıkta seri $\dfrac1{1-4x^2}$ fonksiyonuna yakınsar.

### Terim terim türev ve integral

$f(x)=\sum a_n(x-c)^n$, $|x-c|<R$ olsun.

- **Türev:**
  - $f'(x)=\sum n\,a_n(x-c)^{n-1}$
  - $f''(x)=\sum n(n-1)a_n(x-c)^{n-2}$
- **İntegral:** $\int f(x)\,dx=\sum a_n\dfrac{(x-c)^{n+1}}{n+1}+C$.
- Elde edilen seriler aynı yarıçapla $c-R<x<c+R$ aralığında yakınsar.

**Örnek 17:** $\dfrac1{(1-x)^2}$

- $\dfrac1{1-x}=\sum x^n$ iki tarafın türevi alınır.
- $\dfrac1{(1-x)^2}=\sum_{n=1}^\infty nx^{n-1}$, $|x|<1$.

**Örnek 18:** $\dfrac1{(1-x)^3}$

- Bir kez daha türev alınır: $\dfrac{2}{(1-x)^3}=\sum_{n=2}^\infty n(n-1)x^{n-2}$.
- İki taraf $2$'ye bölünür: $\dfrac1{(1-x)^3}=\sum_{n=2}^\infty\dfrac{n(n-1)}2x^{n-2}$, $|x|<1$.

**Örnek 19:** $\ln(1+x)$

- $\dfrac1{1+x}=\sum(-1)^nx^n$ iki tarafın integrali alınır.
- $\ln(1+x)=\sum_{n=0}^\infty(-1)^n\dfrac{x^{n+1}}{n+1}$, $|x|<1$.

**Örnek 20:** $\arctan x$

- $\dfrac1{1+x^2}=\sum(-1)^nx^{2n}$ integrali alınır.
- $\arctan x=\sum_{n=0}^\infty(-1)^n\dfrac{x^{2n+1}}{2n+1}$.
- Kontrol: Serinin türevi alınırsa $x$'in türevi $1$, $\frac{x^3}3$'ün türevi $x^2$, $\frac{x^5}5$'in türevi $x^4$ olur. Yani $1-x^2+x^4-\dots$ geri gelir.

### Alıştırma ve duyurular

- **Alıştırma:** $f(x)=\dfrac1{2+x}$ fonksiyonunu $(x-1)$'in kuvvetlerine göre yazınız. Çözüm "Ders sonrası notlar" kısmında.
- Yarınki derste kuvvet serileriyle ilgili sorular çözülecek.
- Çıkmış sorulardan ve internetteki kaynaklardan çalışın. Çözümlere bakmadan önce kendiniz uğraşın.

### Ders sonrası notlar

- **Gabriel borusunun hacmi:** Hoca sonucu "bir birim küp" diye söyledi, $\pi$ çarpanını atladı. Doğrusu $V=\pi\int_1^\infty\frac{dx}{x^2}=\pi$ birim küp.
- **Limit karşılaştırmasında $L=0$ durumu:** Hoca bu durumu anlatırken "$\sum b_n$ ıraksak ise $\sum a_n$ ıraksak" gibi söyledi. $L=0$'da bu çıkarım yapılamaz. Doğrusu:
  - $L=0$ ve $\sum b_n$ yakınsak ise $\sum a_n$ yakınsak.
  - $L=\infty$ ve $\sum b_n$ ıraksak ise $\sum a_n$ ıraksak.
- **Örnek 12'deki karışıklık:** Hoca $x=-1$ için seriyi bir yerde "$(-1)^n$ bölü $n$ faktöriyel" diye okudu. Seri $\sum\frac{(-1)^n}{n}$ olur. Ayrıca $x=1$ için bir an "mutlak yakınsak, doğru" deyip sonra ıraksak dedi. Doğrusu: $x=1$'de seri harmonik seridir ve ıraksaktır.
- **Uç noktalar:** Hoca "terim terim türev ve integralde aralık değişmez" dedi. Yarıçap değişmez, ama uç noktalardaki davranış değişebilir.
  - Örnek: $\sum\frac{x^n}{n}$'nin aralığı $[-1,1)$.
  - Türevi $\sum x^{n-1}$'in aralığı $(-1,1)$. $x=-1$ ucu kaybolur.
- **Alıştırmanın çözümü:**
  - $\dfrac1{2+x}=\dfrac1{3+(x-1)}=\dfrac13\cdot\dfrac1{1+\frac{x-1}3}$.
  - $\dfrac1{1+u}=\sum(-1)^nu^n$ açılımında $u=\frac{x-1}3$ yazılır.
  - Sonuç: $\dfrac1{2+x}=\sum_{n=0}^\infty\dfrac{(-1)^n(x-1)^n}{3^{n+1}}$.
  - Koşul: $\left|\frac{x-1}3\right|<1$, yani $-2<x<4$.

Gemini Notebook notu: İsterseniz bu özeti ve ders kaydını Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
