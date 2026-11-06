# Ders 6 Çalışma Özeti

**Tarih:** 14 Mart 2023 (Salı)

## Genel Konular

- Seriler konusunun kapanışı: geçmiş yıl ara sınav, final ve bütünleme sorularının çözümü.
- Dizi limiti: $\lim\dfrac{\sin(1/x)}{1/x}$ tipi limitler.
- Teleskopik seri, geometrik seri ve seri toplamı.
- Kuvvet serisinin yakınsaklık aralığı, uç noktalar, mutlak ve şartlı yakınsaklık.
- Genel terim testi, oran testi, $p$-serisiyle limit testi.
- Maclaurin serisi ile integral ve limit soruları.
- Sonraki konuya giriş: kutupsal koordinatlardan kartezyen koordinatlara geçiş.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu hafta seriler bitiyor. Gelecek hafta parametrik denklemlere geçilecek. Ardından çok değişkenli fonksiyonlar, tanım kümeleri, limit, süreklilik, türev ve çok katlı integral gelecek.
- Birinci vize sorularının yarıdan fazlası serilerden gelecek. Kuvvet serisinin mutlak / şartlı yakınsaklığını soran en az bir soru kesin gelir.
- Sınav test şeklinde, yaklaşık 20 soru. Bir soruya en fazla 3-5 dakika düşüyor. Kendinizi 3 dakikaya göre ayarlayın.
- Test sınavında "işlem hatası yaptım" deme lüksü yok: soru ya doğrudur ya yanlış.
- Şıklar çoğu zaman uç noktanın dahil olup olmamasıyla ayrışır.
- Sonuç değil süreç odaklı çalışın. Sorular sürecin bir adımını da sorabilir ("hangi adım doğrudur" gibi).
- Geçmiş sınavlar bölümün sayfasında bulunur.

## Kısa Tekrar Notları

- $\lim_{x\to0}\dfrac{\sin x}{x}=1$, $\lim_{x\to\infty}\dfrac{\sin x}{x}=0$, $\lim_{x\to\infty}\dfrac{\sin(1/x)}{1/x}=1$.
- **Genel terim testi:** $\lim a_n\neq0$ ise $\sum a_n$ ıraksaktır.
- **Geometrik seri:** $\sum_{n=0}^{\infty}ar^n=\dfrac{a}{1-r}$, $|r|<1$.
- **$\sum n!\,(x-c)^n$:** yalnız $x=c$'de yakınsak. **$\sum\dfrac{(x-c)^n}{n!}$:** her $x$ için yakınsak.
- **$\sum_{n=1}^{\infty}n\left(\tfrac12\right)^n=2$**, çünkü $\sum nx^n=\dfrac{x}{(1-x)^2}$.
- $\int_0^xe^{-t^2}dt=\sum_{n=0}^{\infty}\dfrac{(-1)^nx^{2n+1}}{(2n+1)\,n!}$.
- **Kutupsal-kartezyen:** $x=r\cos\theta$, $y=r\sin\theta$, $x^2+y^2=r^2$.

## Detaylı Açıklamalar

### Dizi limiti

**Örnek 1 (sınav sorusu, 12 puan, kareden).** $\left\{\dfrac{n^{5/2}}{2n^2+1}\sin\dfrac{1}{\sqrt n}\right\}_{n\ge1}$ dizisinin limitini bulunuz.
1. $n\to\infty$ için $\infty\cdot0$ belirsizliği var.
2. $n^{5/2}=n^2\sqrt n$ yazılır. $\sqrt n$, sinüsün altına $\dfrac{1}{1/\sqrt n}$ olarak taşınır.
3. $\lim\left(\dfrac{n^2}{2n^2+1}\cdot\dfrac{\sin(1/\sqrt n)}{1/\sqrt n}\right)$ elde edilir.
4. İlk çarpan $\tfrac12$'ye, ikinci çarpan $1$'e gider. Limit $\tfrac12$.

### Seri toplamları

**Örnek 2 (teleskopik seri).** Genel terim iki terimin farkı şeklinde yazılır.
- Kısmi toplamda ara terimler birbirini götürür.
- $S_n\to1$. Serinin toplamı $1$.

**Örnek 3.** $\sum_{n=0}^{\infty}\dfrac{(x+3)^n}{4^{n+1}}$ kuvvet serisinin yakınsaklık aralığı ve temsil ettiği fonksiyon.
1. $\tfrac14$ dışarı alınır: $\dfrac14\sum\left(\dfrac{x+3}{4}\right)^n$. Geometrik seri, ortak çarpan $r=\dfrac{x+3}{4}$.
2. Toplam: $\dfrac14\cdot\dfrac{1}{1-\frac{x+3}{4}}=\dfrac{1}{1-x}$.
3. Koşul $\left|\dfrac{x+3}{4}\right|<1$, yani $-7<x<1$.
- Test sorusunda her aşama ayrı bir şık olabilir: fonksiyon $\dfrac{1}{1-x}$, aralık $(-7,1)$, koşul $\left|\dfrac{x+3}{4}\right|<1$.

**Örnek 4 (2020 bütünleme sorusu, 15 puan, kareden).** $\{a_n\}_{n=1}^{\infty}=\left\{\tfrac34,\tfrac58,\tfrac7{16},\tfrac9{32},\dots\right\}$ dizisi veriliyor. $\sum a_n$ toplamını hesaplayınız.
1. Örüntü: paylar $2n+1$, paydalar $2^{n+1}$. $a_n=\dfrac{2n+1}{2^{n+1}}$.
2. Parçalanır: $\sum\dfrac{2n+1}{2^{n+1}}=\underbrace{\sum_{n=1}^{\infty}\dfrac{n}{2^n}}_{A}+\underbrace{\sum_{n=1}^{\infty}\dfrac{1}{2^{n+1}}}_{B}$.
3. $B$: geometrik seri, $a=\tfrac14$, $r=\tfrac12$. $B=\dfrac{1/4}{1-1/2}=\tfrac12$.
4. $A$: $\sum x^n=\dfrac{1}{1-x}$ türevlenip $x$ ile çarpılır: $\sum nx^n=\dfrac{x}{(1-x)^2}$. $x=\tfrac12$ için $A=2$.
5. Toplam $\tfrac52$.
- Hoca: genel terimi bulmak sorunun yarısını çözmek demektir.

**Örnek 5.** $\sum_{n=1}^{\infty}\left(\dfrac{2}{3^n}+\dfrac{(-1)^n}{5^n}\right)$ tipinde bir toplam.
- İki geometrik seriye ayrılır. Her birinde $|r|<1$ kontrol edilir ve $\dfrac{a}{1-r}$ uygulanır.
- İfade altyazıdan böyle anlaşılıyor: $2\cdot\dfrac{1/3}{1-1/3}+\dfrac{-1/5}{1+1/5}=1-\dfrac16=\dfrac56$.

### Karakter ve yakınsaklık aralığı

**Örnek 6.** $\sum_{n=0}^{\infty}n!\,(x-1)^n$ serisini yakınsak yapan $x$ değerleri.
- Oran testi: $\lim(n+1)\,|x-1|$. $x\neq1$ ise limit $\infty$.
- Seri yalnız $x=1$'de yakınsaktır.
- $n!$ paydada olsaydı ($\sum\dfrac{(x-1)^n}{n!}$) limit her $x$ için $0$ olurdu ve seri her $x\in\mathbb{R}$ için yakınsak olurdu.

**Örnek 7.** $\sum_{n=2}^{\infty}n\ln\left(1-\dfrac1n\right)$ serisinin karakteri.
1. Önce genel terimin limitine bakılır.
2. Logaritmanın özelliğiyle $n\ln\left(1-\tfrac1n\right)=\ln\left(1-\tfrac1n\right)^n$.
3. Limit ile $\ln$ yer değiştirir: $\ln\left(\lim\left(1-\tfrac1n\right)^n\right)=\ln e^{-1}=-1$.
4. $-1\neq0$, genel terim testiyle seri ıraksaktır.

**Örnek 8.** İlk terimi ve $a_{n+1}$'i $a_n$ cinsinden veren bir bağıntıyla tanımlanan seri.
- Oran testi doğrudan uygulanır, seri yakınsak çıkıyor.
- Bağıntının kendisi altyazıda anlaşılmıyor.

**Örnek 9 (2019 Bahar ara sınavı, Soru 1, kareden).** $\sum_{n=1}^{\infty}\dfrac{(x-4)^n}{2^n\sqrt[5]{n^3+7}}$ serisinin hangi $x\in\mathbb{R}$ değerleri için mutlak yakınsak, şartlı yakınsak ve ıraksak olduğunu araştırınız.
1. Oran testi: $\lim\dfrac{\sqrt[5]{n^3+7}}{\sqrt[5]{(n+1)^3+7}}\cdot\dfrac{|x-4|}{2}=\dfrac{|x-4|}{2}<1$, yani $2<x<6$.
2. $x=6$: $\sum\dfrac{1}{\sqrt[5]{n^3+7}}$. $\sum\dfrac{1}{n^{3/5}}$ ile limit testi, $p=\tfrac35<1$, ıraksak. $6$ dahil değil.
3. $x=2$: $\sum\dfrac{(-1)^n}{\sqrt[5]{n^3+7}}$. Leibniz testiyle yakınsak. Mutlak değeri ıraksak, yani şartlı yakınsak.
4. Sonuç: $(2,6)$'da mutlak yakınsak, $x=2$'de şartlı yakınsak, aralığın dışında ve $x=6$'da ıraksak. Yakınsaklık aralığı $[2,6)$.

**Örnek 10.** $n$'inci kök ve $2020$ sayısı içeren bir seri (klasik sınav sorusu).
- Genel terimin limiti sıfırdan farklı çıkıyor, seri ıraksak.
- Hoca, komisyonun yazdığı uzun çözüm yerine genel terim testinin yeteceğini söylüyor. Serinin tam ifadesi altyazıda anlaşılmıyor.

### Maclaurin serisi soruları

**Örnek 11.** $\int_0^xe^{-t^2}dt$'nin Maclaurin serisinin genel terimi.
1. $e^x=1+x+\dfrac{x^2}{2!}+\cdots=\sum\dfrac{x^n}{n!}$. Bu açılımda $(-1)^n$ yoktur. Unutulursa Taylor formülünden yeniden çıkarılır.
2. $x$ yerine $-t^2$ yazılır: $e^{-t^2}=\sum\dfrac{(-1)^nt^{2n}}{n!}$.
3. Terim terim integral: $\sum_{n=0}^{\infty}\dfrac{(-1)^nx^{2n+1}}{(2n+1)\,n!}$.

**Örnek 12.** $\lim_{x\to0}\dfrac{x-\sin x}{x^3}$.
- $0/0$ belirsizliği var. Test sorusunda yöntem serbesttir.
- Seri açılımıyla da, üç kez L'Hôpital kuralıyla da sonuç $\dfrac16$.

### Kutupsal koordinattan kartezyene

**Örnek 13.** $r=2\sin\theta$ eğrisini çiziniz.
1. $x=r\cos\theta$, $y=r\sin\theta$, $x^2+y^2=r^2$.
2. İki taraf $r$ ile çarpılır: $r^2=2r\sin\theta$, yani $x^2+y^2=2y$.
3. Düzenlenir: $x^2+(y-1)^2=1$.
4. Eğri merkezi $(0,1)$, yarıçapı $1$ olan çemberdir.

### Ders sonrası notlar

- **Örnek 7:** Hoca önce limiti "−1, sıfırdan farklı" deyip seriye bir an "yakınsak" diyor, sonra ıraksak diye düzeltiyor. Doğrusu ıraksaktır. Limitin değeri $e^{-1}$ değil, $\ln e^{-1}=-1$'dir. Hoca bir yerde $e^{-1}$ diyor; iki değer de sıfırdan farklı olduğu için sonuç değişmez.
- **Örnek 9:** Hoca önce $\tfrac35$'i 1'den büyük sanıp $x=6$'yı dahil ediyor, sonra $\tfrac35<1$ olduğunu görüp düzeltiyor. Doğrusu $6$ dahil değildir.
- **Örnek 4:** Altyazıda dördüncü terim "9 bölü 22" diye geçiyor. Doğrusu $\tfrac{9}{32}$ (kareden doğrulandı).
- **Örnek 3:** Altyazıda aralık bir yerde bozuk geçiyor ("x yeri ile artı 1"). Doğrusu $-7<x<1$.
- 00:54-00:58 arasında hocanın mikrofonu kapalı kalıyor. Bu arada anlatılan integral adımları altyazıda yok.
- Molada (00:37 civarı) yoklama yapılıyor.

## Duyurular

- Seriler bu hafta bitti. Gelecek hafta parametrik denklemler ve kutupsal koordinatlar işlenecek.
- Pandemi öncesi dönemlere ait çıkmış test soruları bölüm sayfasında var.
- Sınav öncesinde yine genel soru çözümü yapılacak.

---

İsterseniz bu özeti Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
