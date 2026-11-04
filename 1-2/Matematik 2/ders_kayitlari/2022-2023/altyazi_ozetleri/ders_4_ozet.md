# Ders 4 Çalışma Özeti

**Tarih:** 7 Mart 2023 (Salı)

## Genel Konular

- Kuvvet serilerinin (power series) tekrarı: merkez, yakınsaklık yarıçapı (radius of convergence) ve yakınsaklık aralığı (interval of convergence).
- Mutlak yakınsaklık (absolute convergence) ve şartlı yakınsaklık (conditional convergence).
- Geometrik seriden yeni seri açılımları üretme: değişken değiştirme, terim terim türev ve integral.
- Bir fonksiyonu $x-c$'nin kuvvetlerine göre seriye açma.
- Geçmiş yıl sınav soruları: seri karakteri (yakınsak / ıraksak / mutlak / şartlı), kuvvet serisinin yakınsaklık aralığı ve uç noktalar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınav sorularının önemli bir kısmı seriler konusundan gelir.
- Seride ilk bakılacak şey genel terimin limitidir. $\lim a_n \neq 0$ ise seri ıraksaktır. Hoca bunu "10 puanlık soruda tek cümlelik cevap" diye vurguladı.
- Kuvvet serisinde oran testiyle bulunan aralık açık aralıktır. Uç noktalar ayrıca seriye konup tek tek incelenir.
- $\dfrac{1}{1-x}=\sum_{n=0}^{\infty}x^n$ ($|x|<1$) açılımı çok kullanılır. Yakınsaklık aralığı en az açılımın kendisi kadar önemlidir.
- Faktöriyel gören oran testini, $n$'inci kuvvet gören kök testini düşünmeli.
- Test sınavında şıklar uç noktanın dahil olup olmamasıyla ayrışır. Uç noktaları dikkatle inceleyin.
- "Burası bir bilim atölyesi." Anlaşılmayan yeri çekinmeden sorun.

## Kısa Tekrar Notları

- **Kuvvet serisi:** $\sum_{n=0}^{\infty} a_n (x-c)^n$. $x=c$'de seri $a_0$'a yakınsar.
- **Üç durum:** seri ya yalnız $x=c$'de, ya her $x\in\mathbb{R}$ için, ya da $|x-c|<R$ için yakınsar (dışında ıraksar).
- **Oran testi:** $L=\lim \left|\dfrac{a_{n+1}}{a_n}\right|$. $L<1$ yakınsak, $L>1$ ıraksak, $L=1$ test sonuç vermez.
- **Mutlak yakınsak:** $\sum |a_n|$ yakınsak.
- **Şartlı yakınsak:** $\sum a_n$ yakınsak ama $\sum |a_n|$ ıraksak.
- **Leibniz (alterne seri) testi:** $b_n$ monoton azalan ve $\lim b_n=0$ ise $\sum (-1)^n b_n$ yakınsaktır.
- **$p$-serisi:** $\sum \dfrac{1}{n^p}$, $p>1$ ise yakınsak, $p\le 1$ ise ıraksak.
- **Limit formülü:** $\lim a_n=0$, $\lim b_n=\infty$ ve $\lim a_n b_n=\lambda$ ise $\lim (1+a_n)^{b_n}=e^{\lambda}$.
- **Terim terim türev / integral:** yakınsaklık yarıçapı değişmez; uç noktalar yeniden incelenir.

## Detaylı Açıklamalar

### Kuvvet serisi ve yakınsaklık aralığı

**Tanım (kuvvet serisi)**
- $\sum_{n=0}^{\infty} a_n (x-c)^n = a_0 + a_1(x-c) + a_2(x-c)^2+\cdots$ serisine $x=c$ civarında (merkezli) kuvvet serisi denir.
- $a_n$'ler katsayılardır. Terimler $x$'in fonksiyonu olduğundan seri de $x$'in bir fonksiyonunu temsil eder.

**Teorem (yakınsaklık için üç durum)**
- Seri yalnız $x=c$'de yakınsaktır, ya da
- seri her $x\in\mathbb{R}$ için yakınsaktır, ya da
- öyle bir $R>0$ vardır ki $|x-c|<R$ için yakınsak, $|x-c|>R$ için ıraksaktır. $x=c\pm R$ uçları ayrıca incelenir.

**Yöntem**
- Genel terime $u_n$ denir ve $\lim \left|\dfrac{u_{n+1}}{u_n}\right|<1$ koşulu çözülür. Bu, açık aralığı verir.
- Uç noktalar seriye konur. Çıkan sayı serisi bilinen testlerle incelenir.

**Örnek 1 (önceki dersten).**
- $\sum \dfrac{x^n}{n!}$ için oran limiti her $x$ için $0$'dır. Seri her $x\in\mathbb{R}$ için mutlak yakınsaktır.
- $\sum n!\,x^n$ için oran limiti $x\neq0$ iken $\infty$'dur. Seri yalnız merkezde ($x=0$) yakınsaktır.
- $\sum n!\,(x-1)^n$ olsaydı seri yalnız $x=1$'de yakınsak olurdu.

### Geometrik seriden açılımlar

**Temel açılım:** $\dfrac{1}{1-x}=\sum_{n=0}^{\infty} x^n$, $|x|<1$.
- Kısmi toplam $S_n=\dfrac{1-x^{n+1}}{1-x}$. $|x|<1$ ise $x^{n+1}\to0$ ve $S_n\to\dfrac{1}{1-x}$.
- Bir öğrenci toplamın neden $n=0$'dan başladığını sordu. Hoca: $n=0$ terimi $x^0=1$'dir, ilk terim $1$ olduğu için toplam $0$'dan başlar.

**Örnek 2.** $\dfrac{1}{1+x}=\sum_{n=0}^{\infty}(-1)^n x^n$, $|x|<1$ ($x$ yerine $-x$ yazıldı).

**Örnek 3.** $\dfrac{1}{1+3x}=\sum_{n=0}^{\infty}(-1)^n 3^n x^n$.
- Koşul $|3x|<1$, yani $-\tfrac13<x<\tfrac13$.

**Örnek 4.** $\sum_{n=0}^{\infty}4^n x^{2n}=\sum (4x^2)^n=\dfrac{1}{1-4x^2}$.
- Koşul $4x^2<1$, yani $-\tfrac12<x<\tfrac12$.

**Örnek 5 (terim terim türev).** $\dfrac{1}{(1-x)^2}$.
- $\dfrac{1}{1-x}=\sum x^n$ eşitliğinin iki tarafının türevi alınır.
- $\dfrac{1}{(1-x)^2}=\sum_{n=1}^{\infty} n x^{n-1}$, $-1<x<1$. Uçlarda genel terim sıfıra gitmez, uçlar dahil değildir.

**Örnek 6 (terim terim integral).** $\ln(1-x)$.
- $\dfrac{1}{1-x}=\sum x^n$ integre edilir: $-\ln(1-x)=\sum_{n=0}^{\infty}\dfrac{x^{n+1}}{n+1}$.

**Örnek 7.** $\sum_{n=1}^{\infty} n x^{n-1}=\dfrac{1}{(1-x)^2}$ kullanılarak $\sum n^2 x^n$ toplamı.
1. İki taraf $x$ ile çarpılır: $\sum n x^n=\dfrac{x}{(1-x)^2}$.
2. Türev alınır: $\sum n^2 x^{n-1}=\dfrac{1+x}{(1-x)^3}$.
3. Tekrar $x$ ile çarpılır: $\sum_{n=1}^{\infty} n^2 x^n=\dfrac{x(1+x)}{(1-x)^3}$, $|x|<1$.
- Soru ardından $x=\tfrac12$ koyarak bir sayı serisinin toplamını istiyor: $\sum \dfrac{n^2}{2^n}=\dfrac{\tfrac12\cdot\tfrac32}{(1/2)^3}=6$.

### $x-c$'nin kuvvetlerine göre açılım

**Örnek 8.** $\dfrac{1}{2+x}$'i $x$'in kuvvetlerine göre açınız.
- $\dfrac{1}{2+x}=\dfrac12\cdot\dfrac{1}{1+x/2}=\dfrac12\sum_{n=0}^{\infty}(-1)^n\left(\dfrac{x}{2}\right)^n$.
- Koşul $|x/2|<1$, yani $-2<x<2$.

**Örnek 9 (sınav sorusu).** $\dfrac{1}{2+x}$'i $x-1$'in kuvvetlerine göre açınız, yakınsaklık aralığını bulunuz.
1. $t=x-1$ denir, $x=t+1$ ve $2+x=3+t$ olur.
2. $\dfrac{1}{3+t}=\dfrac13\cdot\dfrac{1}{1+t/3}=\sum_{n=0}^{\infty}\dfrac{(-1)^n t^n}{3^{n+1}}=\sum_{n=0}^{\infty}\dfrac{(-1)^n (x-1)^n}{3^{n+1}}$.
3. Koşul $|t|<3$, yani $-3<x-1<3$, yani $-2<x<4$. Ders sonrası notlara bakınız.

### Mutlak ve şartlı yakınsaklık örnekleri

**Örnek 10.** $\sum_{n=1}^{\infty}\dfrac{x^n}{\sqrt{n^2+3}}$.
- Oran testi: $|x|<1$, yani $-1<x<1$.
- $x=1$: $\sum\dfrac{1}{\sqrt{n^2+3}}$. Limit testiyle $\sum\dfrac1n$ (harmonik seri) ile aynı karakterde, ıraksak.
- $x=-1$: $\sum\dfrac{(-1)^n}{\sqrt{n^2+3}}$. Leibniz testiyle yakınsak. Mutlak değeri ıraksak olduğundan şartlı yakınsak.
- Sonuç: $(-1,1)$'de mutlak yakınsak, $x=-1$'de şartlı yakınsak, aralık $[-1,1)$.

**Örnek 11 (uygulama sorusu, kareden).** $\sum_{n=2}^{\infty}(-1)^{n-1}\dfrac{n}{(n-1)\ln n}$ serisinin karakteri.
- Mutlak değer: $\dfrac{n}{(n-1)\ln n}>\dfrac{n}{(n-1)n}=\dfrac{1}{n-1}>\dfrac1n$ ($n\ge2$ için $\ln n<n$). Mukayese testiyle ıraksak, yani mutlak yakınsak değil.
- Seri alterne seridir. $b_n=\dfrac{n}{(n-1)\ln n}$ monoton azalan ve $\lim b_n=0$. Leibniz testiyle yakınsak.
- Sonuç: şartlı yakınsak.

**Örnek 12.** $a_1$ ve $a_{n+1}$ bağıntısıyla verilen bir serinin karakteri.
- Oran testi uygulanır. Limit $1$'den küçük çıktığı için seri yakınsaktır.
- Bağıntının kendisi altyazıda anlaşılmıyor.

**Örnek 13 (kök testi).** $n$'inci kuvvet içeren bir seri.
- Kök alınınca $\left(1-\dfrac1n\right)^{n}$ tipinde bir ifade kalıyor. Yukarıdaki limit formülüyle sonuç $e^{-1}<1$ çıkıyor, seri yakınsak.
- Serinin tam ifadesi altyazıda anlaşılmıyor.

**Örnek 14 (2012 sınavı).** Genel terimi $\dfrac{1+n}{2+n}$ olan seri.
- $\lim \dfrac{1+n}{2+n}=1\neq0$. Genel terim testiyle ıraksak.
- Aynı sınavda $\cos(n\pi)=(-1)^n$ içeren bir seri de var. Seri alterne seriye dönüşüyor: kendisi yakınsak, mutlak değeri ıraksak, yani şartlı yakınsak.

**Örnek 15.** $\sum (-1)^n\dfrac{2n-1}{\sqrt{n}\,(n+1)}$ için hangisi doğrudur?
- $\lim b_n=0$, çünkü payın derecesi $1$, paydanınki $\tfrac32$. $b_n$ monoton azalan. Leibniz testiyle yakınsak.
- Oran testi $L=1$ verir, sonuç vermez.
- Limit testinde $\dfrac{1}{\sqrt n}$ ile karşılaştırılır: limit $2$, $\sum\dfrac{1}{\sqrt n}$ ıraksak. Mutlak değer serisi ıraksak.
- Sonuç: yakınsak ama mutlak yakınsak değil, yani şartlı yakınsak.

**Örnek 16.** $\sum\dfrac{(x-1)^n}{\sqrt[4]{n^3+1}}$ serisi hangi $x$ için mutlak / şartlı yakınsaktır?
- Oran testi: $|x-1|<1$, yani $0<x<2$. Burada mutlak yakınsak.
- $x=2$: $\sum\dfrac{1}{\sqrt[4]{n^3+1}}$. $\dfrac{1}{n^{3/4}}$ ile limit testi, $p=\tfrac34<1$, ıraksak.
- $x=0$: alterne seri, Leibniz testiyle yakınsak. Mutlak değeri ıraksak, yani şartlı yakınsak.
- Yakınsaklık aralığı $[0,2)$.
- Serinin ifadesi altyazıda bozuk geçiyor. Hocanın verdiği sonuçlarla ($p=3/4$, $0$ dahil, $2$ hariç) bu ifade uyumlu.

**Örnek 17.** $\sum\dfrac{1+n!}{(n+1)!}$ serisinin karakteri.
- $\dfrac{1+n!}{(n+1)!}>\dfrac{n!}{(n+1)!}=\dfrac{1}{n+1}$.
- $\sum\dfrac{1}{n+1}$ ıraksak olduğundan mukayese testiyle seri ıraksak.

**Örnek 18.** $\sum\dfrac{x^{2n}}{n!}$ serisinin yakınsaklık aralığı.
- Oran limiti her $x$ için $0$. Aralık $(-\infty,\infty)$, yarıçap $R=\infty$.

**Örnek 19.** Oran testiyle açık aralık $-\tfrac73<x<1$ bulunan bir kuvvet serisi.
- $x=1$'de alterne seri çıkıyor, şartlı yakınsak. Diğer uçta seri ıraksak.
- Aralık $\left(-\tfrac73,1\right]$. Serinin ifadesi altyazıda anlaşılmıyor.

**Örnek 20.** Oran testiyle aralık $-2<x<2$.
- Uçlarda genel terimin limiti sıfırdan farklı, iki uçta da ıraksak.

**Örnek 21.** $\sqrt{n+1}-\sqrt n$ içeren bir kuvvet serisi.
- İfade eşleniği ile çarpılarak sadeleştiriliyor. Aralık uçları $2$ ve $4$.
- Hoca iki uçta da serinin ıraksak olduğunu, aralığın açık olduğunu söylüyor. Serinin tam ifadesi altyazıda anlaşılmıyor.

### Ders sonrası notlar

- **Örnek 9:** Hoca sonunda aralığı "2 ile 4 arası" diye söylüyor. Doğrusu $-3<x-1<3$, yani $-2<x<4$.
- **Örnek 7:** Altyazıda sonuç "x kare bölü (1−x) karesi" gibi geçiyor. Doğru sonuç $\sum n^2x^n=\dfrac{x(1+x)}{(1-x)^3}$.
- **Örnek 3:** $\dfrac{1}{1+3x}$ açılımındaki "kesin olur" ifadesi altyazı bozulmasıdır. Açılım $(-1)^n3^nx^n$'dir.
- **Örnek 10:** Hoca $x=-1$'deki seriye bir yerde "harmonik seri" diyor, sonra "alterne seri" diye düzeltiyor. Doğrusu alterne seridir.
- Ders başında ve 01:25 civarında yoklama yapılıyor.

## Duyurular

- Bir sonraki hafta Taylor ve Maclaurin serileri ile uygulamaları işlenecek.
- Ardından kutupsal koordinatlar ve çok değişkenli fonksiyonlara geçilecek: tanım kümeleri, çizimler, limit, süreklilik, türev.
- Hoca, eksiği olanların tek değişkenli konuları tekrar etmesini istedi.

---

İsterseniz bu özeti NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
