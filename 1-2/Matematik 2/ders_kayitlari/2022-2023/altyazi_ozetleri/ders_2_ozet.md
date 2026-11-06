# Ders 2 Çalışma Özeti

## Genel Konular

- Seri toplamı soruları: teleskopik seri, logaritmalı seri, iki geometrik serinin farkı.
- Verilen terimlerden genel terimi bulma.
- Yakınsaklık testlerine giriş:
  - İntegral testi (integral test)
  - $p$-serisi testi
  - Karşılaştırma (mukayese) testi (comparison test)
  - $n$-inci terim (genel terim) testi
  - Limit karşılaştırma testi (limit comparison test)
  - Oran testi, D'Alembert (ratio test)
  - Kök testi (root test)

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir seri görünce **ilk iş genel terimin limitine bakmak**. $\lim a_n\ne0$ ise seri ıraksaktır, başka teste gerek yok.
- $\lim a_n = 0$ olması yakınsaklık için yetmez. Harmonik seri $\sum\frac1n$'de genel terim $0$'a gider ama seri ıraksaktır.
- İntegral testi yalnız yakınsak/ıraksak bilgisini verir. Serinin toplamı integralin değerine eşit değildir.
- Karşılaştırma testinde eşitsizliğin yönü önemli. Büyük seri yakınsaksa küçük seri yakınsaktır. Küçük seri ıraksaksa büyük seri ıraksaktır. Ters yönler bir şey söylemez.
- Testler bir "paraşüt" gibidir: biri cevap vermezse diğeri denenir. Bazı sorular yalnız tek bir testle çözülür. Bu yüzden hepsini bilmek gerekir.
- Oran testi özellikle faktöriyel ve kuvvet içeren sorularda, kök testi $n$-inci kuvvet içeren sorularda kullanılır.
- Sınav soruları bölümdeki hocaların oluşturduğu komisyonlarca hazırlanıyor.

## Kısa Tekrar Notları

- **$n$-inci terim testi:** $\sum a_n$ yakınsak ise $\lim a_n=0$. Buna denk olarak $\lim a_n\ne0$ ise seri ıraksak.
- **İntegral testi:** $f$, $[N,\infty)$ aralığında pozitif, sürekli ve azalan ve $a_n=f(n)$ ise $\sum_{n=N}^\infty a_n$ ile $\int_N^\infty f(x)\,dx$ aynı karakterdedir.
- **$p$-serisi:** $\sum\frac1{n^p}$, $p>1$ ise yakınsak, $p\le1$ ise ıraksak.
- **Karşılaştırma testi:** $0\le a_n\le b_n$ ise:
  - $\sum b_n$ yakınsak ise $\sum a_n$ yakınsak.
  - $\sum a_n$ ıraksak ise $\sum b_n$ ıraksak.
- **Limit karşılaştırma testi:** $a_n,b_n>0$ ve $L=\lim\frac{a_n}{b_n}$ olsun.
  - $0<L<\infty$ ise iki seri aynı karakterdedir.
  - $L=0$ ve $\sum b_n$ yakınsak ise $\sum a_n$ yakınsaktır.
  - $L=\infty$ ve $\sum b_n$ ıraksak ise $\sum a_n$ ıraksaktır.
- **Oran testi:** $L=\lim\frac{a_{n+1}}{a_n}$.
  - $L<1$ ise yakınsak.
  - $L>1$ ise ıraksak.
  - $L=1$ ise test sonuç vermez.
- **Kök testi:** $L=\lim\sqrt[n]{a_n}$. Karar oran testiyle aynı: $L<1$ yakınsak, $L>1$ ıraksak, $L=1$ sonuç yok.
- Karşılaştırmada genellikle seçilen seriler: geometrik seri, harmonik seri, $p$-serisi.

## Detaylı Açıklamalar

### Seri toplamı soruları

**Örnek 1 (teleskopik seri):** $\sum_{n=1}^\infty\dfrac{4}{n^2+4n+3}$

- Payda çarpanlarına ayrılır: $n^2+4n+3=(n+1)(n+3)$.
- Basit kesirlere ayırma: $\dfrac{4}{(n+1)(n+3)} = \dfrac{A}{n+1}+\dfrac{B}{n+3}$. Sonuç $A=2$, $B=-2$.
- Seri $2\sum\left(\dfrac1{n+1}-\dfrac1{n+3}\right)$ olur.
- Açılınca terimler ikişer adım arayla birbirini götürür:
  - $\left(\frac12-\frac14\right)+\left(\frac13-\frac15\right)+\left(\frac14-\frac16\right)+\dots$
  - Baştan $\frac12$ ve $\frac13$, sondan $-\frac1{n+2}$ ve $-\frac1{n+3}$ kalır.
- $S_n = 2\left(\dfrac12+\dfrac13-\dfrac1{n+2}-\dfrac1{n+3}\right)$.
- $n\to\infty$ için kesirli terimler $0$'a gider. Toplam $2\cdot\dfrac56=\dfrac53$.

**Örnek 2 (logaritmalı seri):** $\sum_{n=2}^\infty \ln\dfrac{n-1}{n}$

- $n=1$ için $\ln0$ tanımsız olduğundan seri $n=2$'den başlar.
- Toplamların logaritması çarpımın logaritmasıdır:
  - $S_n=\ln\left(\dfrac12\cdot\dfrac23\cdot\dfrac34\cdots\dfrac{n-1}{n}\right)$
  - Çarpım sadeleşir: $S_n=\ln\dfrac1n$.
- $n\to\infty$ için $\dfrac1n\to0^+$ ve $\ln\dfrac1n\to-\infty$.
- Seri ıraksaktır. Şıklardaki sayısal cevaplar elenir.

**Örnek 3 (iki geometrik seri):** $\sum_{n=1}^\infty\dfrac{3^{n-1}-1}{6^{n-1}}$

- Seri iki parçaya ayrılır: $\sum\left(\dfrac12\right)^{n-1}-\sum\left(\dfrac16\right)^{n-1}$.
- Birinci seri: $a=1$, $r=\frac12$. Toplamı $\dfrac{1}{1-\frac12}=2$.
- İkinci seri: $a=1$, $r=\frac16$. Toplamı $\dfrac{1}{1-\frac16}=\dfrac65$.
- Toplam: $2-\dfrac65=\dfrac45$.

**Örnek 4 (genel terimi bulma):** $\dfrac19, \dfrac2{12}, \dfrac4{15}, \dfrac8{18}, \dots$

- Paylar $1, 2, 4, 8$, yani $2^{n-1}$.
- Paydalar $9, 12, 15, 18$, yani $3(n+2)$.
- $a_n=\dfrac{2^{n-1}}{3(n+2)}$.
- Kontrol: $n=1$ için $\frac19$, $n=2$ için $\frac2{12}$.

### İntegral testi

**Teorem**

- $f$ fonksiyonu $[N,\infty)$ aralığında pozitif, sürekli ve azalan olsun ve $a_n=f(n)$ olsun.
- Bu durumda $\sum_{n=N}^\infty a_n$ ile $\int_N^\infty f(x)\,dx$ ya ikisi birden yakınsak ya da ikisi birden ıraksaktır.
- Bir öğrenci "toplam integralin değerine mi eşit" diye sordu. Hayır, test yalnız karakteri verir.
- Azalanlık görülemezse türeve bakılır: $f'(x)<0$ ise $f$ azalandır.

**Örnek 5 ($p$-serisinin kanıtı):** $\sum_{n=1}^\infty\dfrac1{n^p}$

- $f(x)=\dfrac1{x^p}$, $p>0$ için $[1,\infty)$ aralığında pozitif, sürekli ve azalan.
- İntegral, $p\ne1$ için: $\int_1^\infty x^{-p}\,dx=\left[\dfrac{x^{1-p}}{1-p}\right]_1^\infty$.
- $p>1$ ise $x^{1-p}\to0$ olur. İntegral $\dfrac1{p-1}$'e eşittir, yani yakınsak.
- $p<1$ ise $x^{1-p}\to\infty$ olur. İntegral ıraksak.
- Sonuç: $p>1$ ise seri yakınsak, $p\le1$ ise ıraksak.
- Örnekler:
  - $\sum\frac1{\sqrt n}$: $p=\frac12$, ıraksak.
  - $\sum\frac1{n^{3/2}}$: $p=\frac32$, yakınsak.

**Örnek 6:** $\sum\dfrac1{n^2+1}$

- $f(x)=\dfrac1{x^2+1}$ pozitif, sürekli ve azalan.
- $\int_1^\infty\dfrac{dx}{x^2+1}=\dfrac\pi2-\dfrac\pi4=\dfrac\pi4$, yani integral yakınsak.
- Seri yakınsaktır. İntegralin sayısal değeri hocanın hesabında söylenmedi.

### Karşılaştırma (mukayese) testi

**Teorem:** $a_n,b_n\ge0$ ve her $n$ için $a_n\le b_n$ olsun.

- $\sum b_n$ yakınsak ise $\sum a_n$ yakınsaktır.
- $\sum a_n$ yakınsak ise $\sum b_n$ hakkında bir şey söylenemez.
- $\sum a_n$ ıraksak ise $\sum b_n$ ıraksaktır.

**Örnek 7:** $\sum\dfrac1{n-1}$ ($n\ge2$)

- Derste öğrenciler "terimler sıfıra gidiyor, yakınsak" dedi. Bu yanlış.
- $\dfrac1{n-1}>\dfrac1n$ olduğundan seri harmonik seriden büyüktür.
- Harmonik seri ($p=1$) ıraksak olduğu için bu seri de ıraksaktır.

**Örnek 8:** $\sum\dfrac1{n^2-2}$ ($n\ge2$)

- $\sum\frac1{n^2}$ yakınsaktır ($p=2>1$).
- Bir öğrenci $\dfrac1{n^2-2}>\dfrac1{n^2}$ olduğunu fark etti. Bu yönle karşılaştırma bir şey söylemez.
- Düzeltme: başa bir katsayı konur. $n\ge2$ için $\dfrac1{n^2-2}\le\dfrac2{n^2}$.
- $\sum\frac2{n^2}$ yakınsak olduğundan seri yakınsaktır.

**Örnek 9:** Terimleri $\dfrac3{n^2}+\dfrac1{n^3}$ ile üstten sınırlanan bir seri

- $\dfrac3{n^2}+\dfrac1{n^3}\le\dfrac4{n^2}$.
- $\sum\frac4{n^2}$ yakınsak olduğundan seri yakınsaktır.
- Serinin tam ifadesi altyazıda anlaşılmıyor.

**Örnek 10 (sınav sorusu):** $\sum_{n=2}^\infty\dfrac1{\ln n}$

- Önce genel terime bakılır: $\dfrac1{\ln n}\to0$. Test sonuç vermez, başka teste geçilir.
- Her $n\ge2$ için $\ln n<n$, yani $\dfrac1{\ln n}>\dfrac1n$.
- Harmonik seri ıraksak olduğundan seri ıraksaktır.

### $n$-inci terim testi

**Teorem**

- $\sum a_n$ yakınsak ise $\lim a_n=0$.
- Tersi doğru değildir.
- Buna denk olarak $\lim a_n\ne0$ ise seri ıraksaktır.

**Örnek 11 (sınav sorusu):** $\sum\dfrac{n+2}{n+5}$

- Hoca, öğrencilerin bu soruda uğraşıp bulamadığını anlatıyor.
- $\lim\dfrac{n+2}{n+5}=1\ne0$. Seri ıraksaktır.

**Örnek 12:** $\sum\left(1-\dfrac1n\right)^n$

- Kök testi uygulanırsa $\sqrt[n]{a_n}=1-\dfrac1n\to1$ çıkar. Test sonuç vermez.
- Genel terime bakılır: $\left(1-\dfrac1n\right)^n\to e^{-1}=\dfrac1e\ne0$.
- Seri ıraksaktır.

### Limit karşılaştırma testi

**Teorem:** $a_n,b_n>0$ ve $L=\lim\dfrac{a_n}{b_n}$.

- $0<L<\infty$ ise iki seri aynı karakterdedir.
- $L=0$ ve $\sum b_n$ yakınsak ise $\sum a_n$ yakınsaktır.
- $L=\infty$ ve $\sum b_n$ ıraksak ise $\sum a_n$ ıraksaktır.

**Örnekler**

- **Örnek 13:** $\sum\dfrac1{n+1}$, $b_n=\frac1n$ ile karşılaştırılır. $L=1$, seri ıraksak. Payda $n^2+1$ gibi olsaydı $\frac1{n^2}$ ile karşılaştırılır ve seri yakınsak olurdu.
- **Örnek 14:** $\sum\dfrac1{1+\sqrt n}$, $b_n=\frac1{\sqrt n}$ ile karşılaştırılır. $L=1$. $\sum\frac1{\sqrt n}$ ıraksak ($p=\frac12$) olduğundan seri ıraksaktır.
- **Örnek 15:** $\sum\sin\dfrac1{n^3}$
  - $n\to\infty$ için $\frac1{n^3}\to0$ ve $\sin0=0$, genel terim testi sonuç vermez.
  - $b_n=\frac1{n^3}$ alınır. $\dfrac{\sin(1/n^3)}{1/n^3}\to1$.
  - $\sum\frac1{n^3}$ yakınsak olduğundan seri yakınsaktır.
- **Örnek 16:** $\sum\sin\dfrac1n$
  - $b_n=\frac1n$ alınır, $L=1$.
  - Harmonik seri ıraksak olduğundan seri ıraksaktır.
  - Örnek 15'ten tek farkı küp. Küp kalkınca sonuç değişiyor.
- **Örnek 17:** Payın derecesi 1, paydanın derecesi 2 olan rasyonel bir seri.
  - Dereceler farkı 1 olduğu için $\frac1n$ ile karşılaştırılır, $L$ sonlu ve sıfırdan farklı çıkar.
  - Seri ıraksaktır.
- **Örnek 18:** $\sum\dfrac{n}{n^5+2}$
  - Dereceler farkı $5-1=4$. $b_n=\dfrac1{n^4}$ alınır.
  - $\lim\dfrac{n/(n^5+2)}{1/n^4}=\lim\dfrac{n^5}{n^5+2}=1$.
  - $\sum\frac1{n^4}$ yakınsak ($p=4>1$). Seri yakınsaktır.

### Oran testi

**Teorem:** $L=\lim\dfrac{a_{n+1}}{a_n}$.

- $L<1$ ise yakınsak.
- $L>1$ ise ıraksak.
- $L=1$ ise test sonuç vermez, başka teste geçilir.

**Örnekler**

- **Örnek 19:** $\sum\dfrac{99^n}{n!}$
  - $\dfrac{a_{n+1}}{a_n}=\dfrac{99^{n+1}}{(n+1)!}\cdot\dfrac{n!}{99^n}=\dfrac{99}{n+1}\to0$.
  - $0<1$, seri yakınsak.
- **Örnek 20:** $\sum\dfrac{2^n}{n}$
  - $\dfrac{a_{n+1}}{a_n}=\dfrac{2^{n+1}}{n+1}\cdot\dfrac n{2^n}=\dfrac{2n}{n+1}\to2$.
  - $2>1$, seri ıraksak.
- **Örnek 21 (öğrencilere bırakıldı):** $\sum\dfrac{n^n}{n!}$
  - $\dfrac{a_{n+1}}{a_n}=\dfrac{(n+1)^{n+1}}{(n+1)!}\cdot\dfrac{n!}{n^n}=\left(1+\dfrac1n\right)^n\to e$.
  - $e>1$, seri ıraksak.

### Kök testi

**Teorem:** $a_n\ge0$ ve $L=\lim\sqrt[n]{a_n}$.

- $L<1$ ise yakınsak.
- $L>1$ ise ıraksak.
- $L=1$ ise test sonuç vermez.

**Örnekler**

- **Örnek 22:** $\sum\dfrac1{(\ln k)^k}$
  - $\sqrt[k]{a_k}=\dfrac1{\ln k}\to0$.
  - $0<1$, seri yakınsak.
- **Örnek 23:** $\sum\dfrac{2^{n+1}}{n^n}$
  - $\sqrt[n]{a_n}=\dfrac{2^{(n+1)/n}}{n}$. Pay $2$'ye, payda sonsuza gider. Limit $0$.
  - Seri yakınsak.
- **Örnek 24:** $\sum\dfrac{2^n+5}{3^n}$ kök testiyle çözülebilir. Hoca sonucu söylemedi. Sonuç "Ders sonrası notlar" kısmında.
- Hoca ayrıca "$200^n$ bölü $n^2$" gibi okunan bir soruyu alıştırma olarak bıraktı. İfade altyazıda net değil.

### Duyurular

- Bu hafta soru çözülerek çalışılmalı. Sorular gelecek hafta pazartesi ve salı derslerinde sorulabilir.
- Gelecek hafta: kuvvet serileri, Taylor ve Maclaurin serileri, serilerin uygulamaları. Sonraki hafta çok değişkenli fonksiyonlara geçilecek.

### Ders sonrası notlar

- **Örnek 2'deki karışıklık:** Bir öğrenci $\ln\frac{n-1}{n}$ toplamını $\left(1-\frac1n\right)^n\to e^{-1}$ limitiyle karıştırıp cevabı $1$ sandı. Hoca bu limiti "eksi bir" diye söyledi; doğrusu $e^{-1}$. Seri toplamında ise kısmi toplam $\ln\frac1n\to-\infty$ olur, seri ıraksaktır.
- **Örnek 3'ün sonucu:** Hoca iki parçanın toplamlarını ($2$ ve $\frac65$) buldu ama farkı söylemedi. Sonuç $\dfrac45$.
- **$p=1$ durumu:** Hoca $p=1$ için integral formülünde paydanın $0$ olmasını "tanımsız, dolayısıyla ıraksak" diye açıkladı. Doğru gerekçe şudur: $p=1$ için ayrı hesap yapılır. $\int_1^\infty\frac{dx}x=\lim_{b\to\infty}\ln b=\infty$, yani integral ıraksaktır.
- **Örnek 7'deki katsayı:** Hoca karşılaştırmada araya "$\frac12$" katsayısı koyduğunu söylüyor. Bu seride katsayıya gerek yok, çünkü $\frac1{n-1}>\frac1n$ zaten doğrudur.
- **Örnek 20:** Hoca sonucu "küçük olduğu için ıraksak" diye söyledi. Doğrusu: oran $2$'ye gider, $2>1$ olduğu için ıraksak.
- **Örnek 24:** $\sum\dfrac{2^n+5}{3^n}=\sum\left(\dfrac23\right)^n+5\sum\left(\dfrac13\right)^n$. İkisi de $|r|<1$ olan geometrik seri, seri yakınsaktır.
  - $n=1$'den başlarsa toplam $\dfrac{2/3}{1/3}+5\cdot\dfrac{1/3}{2/3}=2+\dfrac52=\dfrac92$.
  - Kök testiyle $\sqrt[n]{a_n}\to\dfrac23<1$.
- **Testlerin adları:** Hoca "Abel kök testi" gibi duyulan bir ad kullanıyor. Kök testi Cauchy kök testi olarak bilinir. Oran testi D'Alembert oran testidir.

Gemini Notebook notu: İsterseniz bu özeti ve ders kaydını Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
