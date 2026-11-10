# Ders 5 Çalışma Özeti

**Tarih:** 13 Mart 2023 (Pazartesi)

## Genel Konular

- Taylor serisi (Taylor series) ve Maclaurin serisi (Maclaurin series).
- Taylor polinomu (Taylor polynomial) ve yaklaşık değer hesabı.
- Sık kullanılan Maclaurin açılımları: $e^x$, $\sin x$, $\cos x$, $\ln(1+x)$, $\arctan x$, $\dfrac{1}{1\pm x}$, binom serisi.
- Açılımlardan yeni açılım üretme: değişken değiştirme, türev, integral, bölme.
- Serilerin uygulamaları: kapalı biçimde alınamayan integraller, $0/0$ belirsizliğindeki limitler.
- Sınav tipi seri soruları: limit testi, teleskopik seri, oran testi, kök testi, kuvvet serisinin aralığı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Taylor serisi, fonksiyona türevleri yardımıyla yaklaşmaktır. Mühendislik uygulamalarında çok kullanılır.
- Maclaurin serisi, Taylor serisinin $a=0$ özel durumudur. "Maclaurin" denince açılım noktası $0$ alınır.
- Temel açılımları ezberlemeyin, anlayın: her birini Taylor formülünden kendiniz türetin.
- Açılım kadar yakınsaklık aralığı da önemlidir. Aralık sınavda ayrıca sorulur.
- Paydada $x^2$ varsa integral için payda türevi ($2x$) gerekir. Gerekirse iki taraf $2x$ ile çarpılır.
- Faktöriyel görünce oran testi aklınıza gelsin.
- Soru sormak öğrenmenin parçasıdır. Hoca yoklama yaptığını ve yoklamaların kayda geçeceğini söyledi.

## Kısa Tekrar Notları

- **Taylor serisi ($x=a$ civarında):** $f(x)=\sum_{n=0}^{\infty}\dfrac{f^{(n)}(a)}{n!}(x-a)^n$. Fonksiyon $a$'nın bir komşuluğunda her mertebeden türevlenebilir olmalı.
- **Maclaurin serisi:** $a=0$ alınır, $f(x)=\sum_{n=0}^{\infty}\dfrac{f^{(n)}(0)}{n!}x^n$.
- **$n$'inci mertebe Taylor polinomu:** toplam $n$'e kadar alınır. $P_n(x)=\sum_{k=0}^{n}\dfrac{f^{(k)}(a)}{k!}(x-a)^k$, $f(x)\approx P_n(x)$.
- **Temel açılımlar:**
  - $e^x=\sum_{n=0}^{\infty}\dfrac{x^n}{n!}$, her $x$ için.
  - $\sin x=\sum_{n=0}^{\infty}\dfrac{(-1)^n x^{2n+1}}{(2n+1)!}$, her $x$ için.
  - $\cos x=\sum_{n=0}^{\infty}\dfrac{(-1)^n x^{2n}}{(2n)!}$, her $x$ için.
  - $\dfrac{1}{1-x}=\sum x^n$, $\dfrac{1}{1+x}=\sum(-1)^nx^n$, $|x|<1$.
  - $\ln(1+x)=\sum_{n=1}^{\infty}\dfrac{(-1)^{n+1}x^n}{n}$, $-1<x\le1$.
  - $\arctan x=\sum_{n=0}^{\infty}\dfrac{(-1)^n x^{2n+1}}{2n+1}$, $-1\le x\le1$.
  - Binom: $(1+x)^r=1+rx+\dfrac{r(r-1)}{2!}x^2+\cdots$, $|x|<1$.

## Detaylı Açıklamalar

### Taylor ve Maclaurin serisi

**Fikir.** Yakınsaklık aralığında bir kuvvet serisinin toplamı, her mertebeden türevi olan sürekli bir fonksiyondur. Tersi sorulur: her mertebeden türevi olan bir $f$ kuvvet serisiyle yazılabilir mi, yazılırsa katsayılar ne olur?
- $f(x)=\sum a_n(x-a)^n$ yazılıp terim terim türev alınır ve $x=a$ konur.
- $f(a)=a_0$, $f'(a)=a_1$, $f''(a)=2!\,a_2$, genel olarak $a_n=\dfrac{f^{(n)}(a)}{n!}$ bulunur.
- $f^{(n)}$ kuvvet değil, $n$'inci türevdir.

**Tanım (Taylor serisi)**
- $f$, $a$'yı içeren bir aralıkta her mertebeden türevlenebilir olsun.
- $f(a)+\dfrac{f'(a)}{1!}(x-a)+\dfrac{f''(a)}{2!}(x-a)^2+\cdots$ serisine $f$'nin $x=a$'daki Taylor serisi denir.

**Örnek 1.** $e^x$'in $x=0$'daki Taylor (Maclaurin) serisi.
- $f^{(n)}(x)=e^x$, $f^{(n)}(0)=1$ (her $n$ için).
- $e^x=1+x+\dfrac{x^2}{2!}+\dfrac{x^3}{3!}+\cdots=\sum_{n=0}^{\infty}\dfrac{x^n}{n!}$.
- Hoca toplamı önce $n=1$'den yazıyor, sonra ilk terim $1$ olduğu için $n=0$'dan başlaması gerektiğini söyleyip düzeltiyor.

**Örnek 2.** $\cos x$'in Maclaurin serisi.
- Türevler sırayla $\cos x,\ -\sin x,\ -\cos x,\ \sin x,\dots$ şeklinde döner.
- $x=0$'da çift mertebeli türevler $(-1)^n$, tek mertebeli türevler $0$ olur.
- $\cos x=1-\dfrac{x^2}{2!}+\dfrac{x^4}{4!}-\cdots=\sum_{n=0}^{\infty}\dfrac{(-1)^n x^{2n}}{(2n)!}$.
- Benzer yolla $\sin x=x-\dfrac{x^3}{3!}+\dfrac{x^5}{5!}-\cdots$.
- Polinom sonlu terimde kesilirse "$\approx$" yazılır. Terim sayısı arttıkça polinom $\cos x$'e yaklaşır.

**Örnek 3.** $f(x)=\dfrac1x$'in $a=2$'deki Taylor serisi ve yakınsaklık aralığı.
- $f(2)=\tfrac12$, $f'(x)=-\dfrac{1}{x^2}$, $f'(2)=-\tfrac14$, böyle devam eder.
- Seri geometriktir: $\dfrac1x=\sum_{n=0}^{\infty}\dfrac{(-1)^n(x-2)^n}{2^{n+1}}$.
- Koşul $\left|\dfrac{x-2}{2}\right|<1$, yani $0<x<4$.

### Taylor polinomuyla yaklaşık değer

**Örnek 4.** $\sqrt[3]{1{,}2}$'nin ikinci mertebe Taylor polinomuyla yaklaşık değeri.
1. $f(x)=\sqrt[3]{x}$ seçilir. $1{,}2$'ye en yakın, küp kökü tam çıkan sayı $a=1$'dir.
2. $f(1)=1$, $f'(x)=\dfrac{1}{3}x^{-2/3}$, $f'(1)=\tfrac13$.
3. $f''(x)=-\dfrac{2}{9}x^{-5/3}$, $f''(1)=-\tfrac29$.
4. $P_2(x)=1+\dfrac{x-1}{3}-\dfrac{(x-1)^2}{9}$.
5. $x=1{,}2$: $\sqrt[3]{1{,}2}\approx1+\dfrac{0{,}2}{3}-\dfrac{0{,}04}{9}\approx1{,}0622$.
- Sayı $7{,}9$ olsaydı $a=8$ seçilirdi, çünkü $\sqrt[3]{8}=2$ tam çıkar.

### Açılımlardan yeni açılım üretme

**Örnek 5.** $\ln(1+x)$.
- $f(0)=0$, $f'(x)=\dfrac{1}{1+x}$.
- $\ln(1+x)=x-\dfrac{x^2}{2}+\dfrac{x^3}{3}-\cdots$, $-1<x\le1$.
- Aynı sonuç $\dfrac{1}{1+x}=\sum(-1)^nx^n$ açılımı terim terim integre edilerek de bulunur.

**Örnek 6.** $\arctan x$.
- $\dfrac{1}{1+x^2}=\sum_{n=0}^{\infty}(-1)^nx^{2n}$ ($x$ yerine $x^2$ yazıldı).
- İki taraf integre edilir: $\arctan x=\sum_{n=0}^{\infty}\dfrac{(-1)^nx^{2n+1}}{2n+1}$, $-1\le x\le1$.

**Örnek 7.** $e^{-x^2/3}$'ün Maclaurin serisi.
- $e^x$ açılımında $x$ yerine $-\dfrac{x^2}{3}$ yazılır.
- $e^{-x^2/3}=\sum_{n=0}^{\infty}\dfrac{(-1)^nx^{2n}}{3^n\,n!}$, her $x$ için geçerli.

**Örnek 8.** $\sin^2x$.
- $\sin^2x=\dfrac{1-\cos2x}{2}$ yazılır, $\cos2x$ açılımı kullanılır.
- $\sin^2x=\sum_{n=1}^{\infty}\dfrac{(-1)^{n+1}2^{2n-1}x^{2n}}{(2n)!}=x^2-\dfrac{x^4}{3}+\cdots$.

**Örnek 9.** $\tan x$'in Maclaurin serisinin ilk üç terimi.
- $\tan x=\dfrac{\sin x}{\cos x}$ yazılır, iki seri polinom bölmesi gibi bölünür.
- $\tan x=x+\dfrac{x^3}{3}+\dfrac{2x^5}{15}+\cdots$.

**Örnek 10.** $\ln x$'i $x-3$'ün kuvvetlerine göre açınız.
- $f(3)=\ln3$, $f'(3)=\tfrac13$, $f''(3)=-\tfrac19$.
- $\ln x=\ln3+\dfrac{x-3}{3}-\dfrac{(x-3)^2}{2\cdot9}+\cdots=\ln3+\sum_{n=1}^{\infty}\dfrac{(-1)^{n+1}(x-3)^n}{n\,3^n}$.
- Aynı sonuç $\dfrac1x=\dfrac{1}{3+(x-3)}$ açılımı integre edilerek de bulunur. Aralık $0<x\le6$.

### Uygulamalar: integral ve limit

**Örnek 11.** $\int_0^x e^{-t^2}\,dt$.
- Bu integralin reel sayılarda kapalı bir ilkeli yoktur. Gama/beta fonksiyonları ya da seri açılımı kullanılır.
- $e^{-t^2}=\sum\dfrac{(-1)^nt^{2n}}{n!}$, terim terim integral: $\int_0^xe^{-t^2}dt=\sum_{n=0}^{\infty}\dfrac{(-1)^nx^{2n+1}}{(2n+1)\,n!}$.

**Örnek 12.** $\int_0^1\cos(x^2)\,dx$.
- $\cos(x^2)=\sum_{n=0}^{\infty}\dfrac{(-1)^nx^{4n}}{(2n)!}$.
- $\int_0^1\cos(x^2)dx=\sum_{n=0}^{\infty}\dfrac{(-1)^n}{(4n+1)(2n)!}=1-\dfrac{1}{5\cdot2!}+\dfrac{1}{9\cdot4!}-\cdots$.

**Örnek 13.** $\lim_{x\to0}\dfrac{x-\sin x}{x^3}$.
- $x-\sin x=\dfrac{x^3}{3!}-\dfrac{x^5}{5!}+\cdots$. Sadeleştirilince limit $\dfrac{1}{3!}=\dfrac16$.

**Örnek 14 (ifade büyük olasılıkla (ekrandan)).** $\lim_{x\to0}\dfrac{(e^{2x}-1)\ln(1+x^3)}{(1-\cos3x)^2}$.
- $e^{2x}-1=2x+\dfrac{(2x)^2}{2!}+\cdots$
- $\ln(1+x^3)=x^3-\dfrac{x^6}{2}+\cdots$
- $1-\cos3x=\dfrac{9x^2}{2}-\dfrac{3^4x^4}{4!}+\cdots$
- Pay $\approx2x^4$, payda $\approx\dfrac{81x^4}{4}$. Limit $\dfrac{8}{81}$.

**Binom serisi.** $(1+x)^r=1+rx+\dfrac{r(r-1)}{2!}x^2+\dfrac{r(r-1)(r-2)}{3!}x^3+\cdots$, $|x|<1$.

### Sınav tipi soru çözümü (ders sonu)

**Örnek 15.** $\sum\sqrt{\dfrac{4n^2-1}{n^3+1}}$ serisinin karakteri.
- Genel terimin limiti $0$, test karar vermez.
- $\dfrac{1}{\sqrt n}$ ile limit testi: limit $\sqrt4=2$, sıfır ve sonsuzdan farklı.
- $\sum\dfrac{1}{n^{1/2}}$, $p=\tfrac12\le1$, ıraksak. Seri ıraksak.

**Örnek 16 (teleskopik seri).** $\sum_{n=1}^{\infty}\dfrac{4}{(4n-2)(4n+2)}$.
- Kısmi kesirler: $\dfrac{4}{(4n-2)(4n+2)}=\dfrac{1}{4n-2}-\dfrac{1}{4n+2}$.
- $S_n=\dfrac12-\dfrac{1}{4n+2}\to\dfrac12$. Toplam $\dfrac12$.

**Örnek 17.** $\sum\dfrac{n!}{n^{n+1}}$ serisinin karakteri.
- Oran testi: $\dfrac{a_{n+1}}{a_n}=\left(\dfrac{n}{n+1}\right)^{n+1}\to\dfrac1e<1$. Seri yakınsak.

**Örnek 18.** $\ln(1+x^2)$'nin seri açılımı ve $\ln2$.
1. $\dfrac{1}{1+x^2}=\sum(-1)^nx^{2n}$, $|x|<1$.
2. $\ln(1+x^2)$'nin türevi $\dfrac{2x}{1+x^2}$ olduğundan iki taraf $2x$ ile çarpılır: $\dfrac{2x}{1+x^2}=\sum(-1)^n2x^{2n+1}$.
3. İntegre edilir: $\ln(1+x^2)=\sum_{n=0}^{\infty}\dfrac{(-1)^nx^{2n+2}}{n+1}$.
4. $x=1$ konur: $\ln2=\sum_{n=0}^{\infty}\dfrac{(-1)^n}{n+1}=1-\dfrac12+\dfrac13-\cdots$.
- Benzer olarak $-\ln(1-x)=\sum_{n=0}^{\infty}\dfrac{x^{n+1}}{n+1}$.

**Örnek 19.** $\dfrac{1}{3+2x}$'in seri açılımı.
- $\dfrac{1}{3+2x}=\dfrac13\cdot\dfrac{1}{1+\frac{2x}{3}}=\dfrac13\sum_{n=0}^{\infty}(-1)^n\left(\dfrac{2x}{3}\right)^n$.
- Koşul $\left|\dfrac{2x}{3}\right|<1$, yani $-\tfrac32<x<\tfrac32$.

**Örnek 20.** $\dfrac{1}{(2+x)^2}$'nin seri açılımı.
- $\dfrac{1}{2+x}=\sum_{n=0}^{\infty}\dfrac{(-1)^nx^n}{2^{n+1}}$ açılımının türevi alınır.
- $-\dfrac{1}{(2+x)^2}=\sum_{n=1}^{\infty}\dfrac{(-1)^nn\,x^{n-1}}{2^{n+1}}$.
- Buradan $\dfrac{1}{(2+x)^2}=\sum_{n=0}^{\infty}\dfrac{(-1)^n(n+1)x^n}{2^{n+2}}$, $|x|<2$.

**Örnek 21 (kök testi).** Genel terimi $n$'inci kuvvet olan, içinde $\sin(e^{-n})$ bulunan bir seri.
- Kök alınınca $n\sin(e^{-n})$ kalıyor.
- $\dfrac{\sin(e^{-n})}{e^{-n}}\to1$ olduğundan limit $\lim\dfrac{n}{e^n}=0<1$. Seri yakınsak.
- Serinin tam ifadesi altyazıda anlaşılmıyor.

**Örnek 22.** $\sum_{n=0}^{\infty}\dfrac{(2x+5)^n}{(n^2+1)\,3^n}$ serisinin yakınsaklık aralığı, merkezi ve yarıçapı.
1. Oran testi: $\left|\dfrac{2x+5}{3}\right|<1$, yani $-3<2x+5<3$, yani $-4<x<-1$.
2. $x=-4$: $\sum\dfrac{(-1)^n}{n^2+1}$, yakınsak.
3. $x=-1$: $\sum\dfrac{1}{n^2+1}$. $\dfrac1{n^2}$ ile limit testi, $p=2>1$, yakınsak.
4. Aralık $[-4,-1]$; merkez $-\tfrac52$, yarıçap $\tfrac32$ (aralıktan okunur).

### Ders sonrası notlar

- **Örnek 12:** Hoca sonucu "1 artı 1/(5·2!), 1/(9·3!)" diye okuyor. Doğrusu işaretler değişir ve faktöriyeller çift sayılardır: $1-\dfrac{1}{5\cdot2!}+\dfrac{1}{9\cdot4!}-\cdots$.
- **Örnek 4:** Altyazıda $f''(1)$ değeri ve sonuç anlaşılmıyor. Hesap yukarıda tamamlandı. Gerçek değer yaklaşık $1{,}0627$'dir.
- **Örnek 22:** Hoca $x=-4$'teki seriyi alterne seri olduğu için yakınsak buluyor. Bu seri aslında mutlak yakınsaktır, çünkü $\sum\dfrac{1}{n^2+1}$ yakınsar.
- **Örnek 18:** Hoca integrali yazarken $2n+1$, $2n+2$ ve faktöriyel konusunda bir süre karışıklık yaşıyor. Doğru sonuç yukarıdakidir, faktöriyel yoktur.
- **Örnek 6:** Hoca $\arctan x$ için önce faktöriyelli bir payda yazıyor, sonra faktöriyel olmadığını söyleyip düzeltiyor.
- Ders içinde iki kez yoklama yapılıyor.

## Duyurular

- Bir öğrenci ders notlarının nerede paylaşıldığını sordu. Hoca notların AVESİS sayfasında olması gerektiğini, kontrol edeceğini söyledi.
- Ertesi gün (14 Mart) yine soru çözümü yapılacak.

---

İsterseniz bu özeti Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
